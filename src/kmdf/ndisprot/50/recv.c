/*++

Copyright (c) Microsoft Corporation

Module Name:

    recv.c

Abstract:

    NDIS protocol entry points and utility routines to handle receiving
    data.

Environment:

    Kernel mode only.

--*/

#include "precomp.h"

#define __FILENUMBER 'VCER'



VOID
NdisProtEvtIoRead(
    IN WDFQUEUE         Queue,
    IN WDFREQUEST       Request,
    IN size_t           Length
    )
/*++

Routine Description:

    This event is called when the framework receives IRP_MJ_READ requests.
    We will just read the file.

Arguments:

    Queue -  Handle to the framework queue object that is associated with the
            I/O request.
    Request - Handle to a framework request object.

    Length  - number of bytes to be read.

Return Value:

  None.

--*/
{
    NTSTATUS                 NtStatus;
    PNDISPROT_OPEN_CONTEXT   pOpenContext;
    WDFFILEOBJECT            fileObject;

    UNREFERENCED_PARAMETER(Queue);
    UNREFERENCED_PARAMETER(Length);

    fileObject = WdfRequestGetFileObject(Request);

    pOpenContext = GetFileObjectContext(fileObject)->OpenContext;

    do
    {
        //
        // Validate!
        //
        if (pOpenContext == NULL)
        {
            DEBUGP(DL_FATAL, ("Read: NULL FsContext on FileObject %p\n", fileObject));
            NtStatus = STATUS_INVALID_HANDLE;
            break;
        }

        NPROT_STRUCT_ASSERT(pOpenContext, oc);

        NPROT_ACQUIRE_LOCK(&pOpenContext->Lock);

        if (!NPROT_TEST_FLAGS(pOpenContext->Flags, NPROTO_BIND_FLAGS, NPROTO_BIND_ACTIVE))
        {
            NPROT_RELEASE_LOCK(&pOpenContext->Lock);
            NtStatus = STATUS_INVALID_HANDLE;
            break;
        }

        NPROT_RELEASE_LOCK(&pOpenContext->Lock);

        //
        // Forward this request to the pending read Request queue. We don't have to
        // worry about cancelation of requests pending in the queue because
        // framework takes care of that.
        //
        NtStatus = WdfRequestForwardToIoQueue(Request,
                                    pOpenContext->ReadQueue);

    }
    while (FALSE);

    if (!NT_SUCCESS(NtStatus))
    {
        WdfRequestCompleteWithInformation(Request, NtStatus, 0);
    }

    return;
}

VOID
ndisprotEvtNotifyReadQueue(
    IN WDFQUEUE            Queue,
    IN WDFCONTEXT          Context
    )
/*++

Routine Description:

    This event will be called every time the number of requests in the
    queue changes from 0 to 1.

Arguments:

    Queue - Read queue
    pOpenContext - pointer to open context

Return Value:

    None

--*/
{
    PNDISPROT_OPEN_CONTEXT   pOpenContext = (PNDISPROT_OPEN_CONTEXT)Context;

    UNREFERENCED_PARAMETER(Queue);

    ndisprotServiceReads(pOpenContext);
}


VOID
ndisprotServiceReads(
    IN PNDISPROT_OPEN_CONTEXT  pOpenContext
    )
/*++

Routine Description:

    Utility routine to copy received data into user buffers and
    complete READ Requests.

Arguments:

    pOpenContext - pointer to open context

Return Value:

    None

--*/
{
    WDFREQUEST          request;
    PNDIS_PACKET        pRcvPacket;
    PLIST_ENTRY         pRcvPacketEntry;
    PUCHAR              pSrc, pDst;
    ULONG               BytesRemaining; // at pDst
    PNDIS_BUFFER        pNdisBuffer;
    ULONG               BytesAvailable;
    PMDL                mdl;
    NTSTATUS            ntStatus = STATUS_UNSUCCESSFUL;
    ULONG               bytesCopied = 0;

    DEBUGP(DL_VERY_LOUD, ("ServiceReads: open %p/%x\n",
            pOpenContext, pOpenContext->Flags));

    NPROT_REF_OPEN(pOpenContext);  // temp ref - service reads

    NPROT_ACQUIRE_LOCK(&pOpenContext->Lock);

    request = NULL;

    while (NPROT_IS_LIST_EMPTY(&pOpenContext->RecvPktQueue) == FALSE)
    {
        //
        //  Get the first pended Read Request
        //
        ntStatus = WdfIoQueueRetrieveNextRequest(
                         pOpenContext->ReadQueue,
                         &request
                         );
        if(!NT_SUCCESS(ntStatus)){
            ASSERTMSG("WdfIoQueueRetrieveNextRequest failed",  ntStatus == STATUS_NO_MORE_ENTRIES);
            break;
        }

        ntStatus = WdfRequestRetrieveOutputWdmMdl(request, &mdl);
        if (!NT_SUCCESS(ntStatus))
        {
            DEBUGP(DL_FATAL, ("Read: WdfRequestRetrieveOutputWdmMdl %x\n", ntStatus));
            break;
        }

        pDst = MmGetSystemAddressForMdlSafe(mdl, NormalPagePriority);
        if (pDst == NULL)
        {
            DEBUGP(DL_FATAL, ("Read: MmGetSystemAddr failed for Request %p, MDL %p\n",
                    request, pDst));
            ntStatus = STATUS_INSUFFICIENT_RESOURCES;
            break;
        }

        BytesRemaining = MmGetMdlByteCount(mdl);

        //
        //  Get the first queued receive packet
        //
        pRcvPacketEntry = pOpenContext->RecvPktQueue.Flink;
        NPROT_REMOVE_ENTRY_LIST(pRcvPacketEntry);

        pOpenContext->RecvPktCount --;

        NPROT_DEREF_OPEN(pOpenContext);  // Service: dequeue rcv packet

        pRcvPacket = NPROT_LIST_ENTRY_TO_RCV_PKT(pRcvPacketEntry);

        //
        //  Copy as much data as possible from the receive packet to
        //  the Request MDL.
        //

        pNdisBuffer = pRcvPacket->Private.Head;

        //
        // Copy the data in the received packet into the buffer provided by the client.
        // If the length of the receive packet is greater than length of the given buffer,
        // we just copy as many bytes as we can. Once the buffer is full, we just discard
        // the rest of the data, and complete the Request sucessfully even we only did a partial copy.
        //
        while (BytesRemaining && (pNdisBuffer != NULL))
        {

            NdisQueryBufferSafe(pNdisBuffer, &pSrc, &BytesAvailable, NormalPagePriority);

            if (pSrc == NULL)
            {
                DEBUGP(DL_FATAL,
                    ("ServiceReads: Open %p, QueryBuffer failed for buffer %p\n",
                            pOpenContext, pNdisBuffer));
                break;
            }

            if (BytesAvailable)
            {
                ULONG       BytesToCopy = MIN(BytesAvailable, BytesRemaining);

                NPROT_COPY_MEM(pDst, pSrc, BytesToCopy);
                BytesRemaining -= BytesToCopy;
                pDst += BytesToCopy;
            }

            NdisGetNextBuffer(pNdisBuffer, &pNdisBuffer);
        }

        //
        //  Complete the Request.
        //
        bytesCopied = MmGetMdlByteCount(mdl) - BytesRemaining;
        ntStatus = STATUS_SUCCESS;

        //
        //  Free up the receive packet - back to the miniport if it
        //  belongs to it, else reclaim it (local copy).
        //
        if (NdisGetPoolFromPacket(pRcvPacket) != pOpenContext->RecvPacketPool)
        {
            NdisReturnPackets(&pRcvPacket, 1);
        }
        else
        {
            ndisprotFreeReceivePacket(pOpenContext, pRcvPacket);
        }

        DEBUGP(DL_INFO, ("ServiceReads: Open %p, Request %p completed with %d bytes\n",
                                                pOpenContext, request, bytesCopied));

        NPROT_RELEASE_LOCK(&pOpenContext->Lock);

        WdfRequestCompleteWithInformation(request, ntStatus, bytesCopied);

        NPROT_ACQUIRE_LOCK(&pOpenContext->Lock);

        request = NULL;

    }

    NPROT_RELEASE_LOCK(&pOpenContext->Lock);

    if(request) {
        WdfRequestComplete(request, ntStatus);
    }

    NPROT_DEREF_OPEN(pOpenContext);    // temp ref - service reads
}




NDIS_STATUS
NdisProtReceive(
    IN NDIS_HANDLE                  ProtocolBindingContext,
    IN NDIS_HANDLE                  MacReceiveContext,
    IN PVOID                        pHeaderBuffer,
    IN UINT                         HeaderBufferSize,
    IN PVOID                        pLookaheadBuffer,
    IN UINT                         LookaheadBufferSize,
    IN UINT                         PacketSize
    )
/*++

Routine Description:

    Our protocol receive handler called by NDIS, typically if we have
    a miniport below that doesn't indicate packets.

    We make a local packet/buffer copy of this data, queue it up, and
    kick off the read service routine.

Arguments:

    ProtocolBindingContext - pointer to open context
    MacReceiveContext - for use in NdisTransferData
    pHeaderBuffer - pointer to data header
    HeaderBufferSize - size of the above
    pLookaheadBuffer - pointer to buffer containing lookahead data
    LookaheadBufferSize - size of the above
    PacketSize - size of the entire packet, minus header size.

Return Value:

    NDIS_STATUS_NOT_ACCEPTED - if this packet is uninteresting
    NDIS_STATUS_SUCCESS - if we processed this successfully

--*/
{
    PNDISPROT_OPEN_CONTEXT   pOpenContext;
    NDIS_STATUS             Status;
    PNDIS_PACKET            pRcvPacket;
    PUCHAR                  pRcvData;
    UINT                    BytesTransferred;
    PNDIS_BUFFER            pOriginalNdisBuffer, pPartialNdisBuffer;
    ULONG                   safeRecvPacketSize;

    pOpenContext = (PNDISPROT_OPEN_CONTEXT)ProtocolBindingContext;
    NPROT_STRUCT_ASSERT(pOpenContext, oc);
    pRcvPacket = NULL;
    pRcvData = NULL;
    Status = NDIS_STATUS_SUCCESS;
    do
    {
        if (HeaderBufferSize != sizeof(NDISPROT_ETH_HEADER))
        {
            Status = NDIS_STATUS_NOT_ACCEPTED;
            break;
        }
        Status =   RtlULongAdd (PacketSize,
                                HeaderBufferSize,
                                &safeRecvPacketSize);

        if (!NT_SUCCESS(Status)) {
            break;
        }
        //
        //  Allocate resources for queueing this up.
        //
        pRcvPacket = ndisprotAllocateReceivePacket(
                        pOpenContext,
                        safeRecvPacketSize,
                        &pRcvData
                        );

        if (pRcvPacket == NULL)
        {
            Status = NDIS_STATUS_NOT_ACCEPTED;
            break;
        }

        NdisMoveMappedMemory(pRcvData, pHeaderBuffer, HeaderBufferSize);

        //
        //  Check if the entire packet is within the lookahead.
        //
        if (PacketSize == LookaheadBufferSize)
        {
            NdisCopyLookaheadData(pRcvData+HeaderBufferSize,
                                  pLookaheadBuffer,
                                  LookaheadBufferSize,
                                  pOpenContext->MacOptions);
            //
            //  Queue this up for receive processing, and
            //  try to complete some read Requests.
            //
            ndisprotQueueReceivePacket(pOpenContext, pRcvPacket);
        }
        else
        {
            //
            //  Allocate an NDIS buffer to map the receive area
            //  at an offset "HeaderBufferSize" from the current
            //  start. This is so that NdisTransferData can copy
            //  in at the right point in the destination buffer.
            //

            NdisAllocateBuffer(
                &Status,
                &pPartialNdisBuffer,
                pOpenContext->RecvBufferPool,
                pRcvData + HeaderBufferSize,
                PacketSize);

            if (Status == NDIS_STATUS_SUCCESS)
            {
                //
                //  Unlink and save away the original NDIS Buffer
                //  that maps the full receive buffer.
                //
                NdisUnchainBufferAtFront(pRcvPacket, &pOriginalNdisBuffer);
                NPROT_RCV_PKT_TO_ORIGINAL_BUFFER(pRcvPacket) = pOriginalNdisBuffer;

                //
                //  Link in the partial buffer for NdisTransferData to
                //  operate on.
                //
                NdisChainBufferAtBack(pRcvPacket, pPartialNdisBuffer);

                DEBUGP(DL_LOUD, ("Receive: setting up for TransferData:"
                        " Pkt %p, OriginalBuf %p, PartialBuf %p\n",
                        pRcvPacket, pOriginalNdisBuffer, pPartialNdisBuffer));

                NdisTransferData(
                    &Status,
                    pOpenContext->BindingHandle,
                    MacReceiveContext,
                    0,  // ByteOffset
                    PacketSize,
                    pRcvPacket,
                    &BytesTransferred);
            }
            else
            {
                //
                //  Failure handled below in TransferDataComplete.
                //
                BytesTransferred = 0;
            }

            if (Status != NDIS_STATUS_PENDING)
            {
                NdisProtTransferDataComplete(
                    (NDIS_HANDLE)pOpenContext,
                    pRcvPacket,
                    Status,
                    BytesTransferred);
            }
        }

    }
    while (FALSE);


    DEBUGP(DL_LOUD, ("Receive: Open %p, Pkt %p, Size %d\n",
            pOpenContext, pRcvPacket, PacketSize));

    return Status;
}



VOID
NdisProtTransferDataComplete(
    IN NDIS_HANDLE                  ProtocolBindingContext,
    IN PNDIS_PACKET                 pNdisPacket,
    IN NDIS_STATUS                  TransferStatus,
    IN UINT                         BytesTransferred
    )
/*++

Routine Description:

    NDIS entry point called to signal completion of a call to
    NdisTransferData that had pended.

Arguments:

    ProtocolBindingContext - pointer to open context
    pNdisPacket - our receive packet into which data is transferred
    TransferStatus - status of the transfer
    BytesTransferred - bytes copied into the packet.

Return Value:

    None

--*/
{
    PNDISPROT_OPEN_CONTEXT   pOpenContext;
    PNDIS_BUFFER            pOriginalBuffer, pPartialBuffer;

    UNREFERENCED_PARAMETER(BytesTransferred);

    pOpenContext = (PNDISPROT_OPEN_CONTEXT)ProtocolBindingContext;
    NPROT_STRUCT_ASSERT(pOpenContext, oc);

    //
    //  Check if an NDIS_BUFFER was created to map part of the receive buffer;
    //  if so, free it and link back the original NDIS_BUFFER that maps
    //  the full receive buffer to the packet.
    //
    pOriginalBuffer = NPROT_RCV_PKT_TO_ORIGINAL_BUFFER(pNdisPacket);
    if (pOriginalBuffer != NULL)
    {
        //
        //  We had stashed off the NDIS_BUFFER for the full receive
        //  buffer in the packet reserved area. Unlink the partial
        //  buffer and link in the full buffer.
        //
        NdisUnchainBufferAtFront(pNdisPacket, &pPartialBuffer);
        NdisChainBufferAtBack(pNdisPacket, pOriginalBuffer);

        DEBUGP(DL_LOUD, ("TransferComp: Pkt %p, OrigBuf %p, PartialBuf %p\n",
                pNdisPacket, pOriginalBuffer, pPartialBuffer));

        //
        //  Free up the partial buffer.
        //
        NdisFreeBuffer(pPartialBuffer);
    }

    if (TransferStatus == NDIS_STATUS_SUCCESS)
    {
        //
        //  Queue this up for receive processing, and
        //  try to complete some read Requests.
        //
        ndisprotQueueReceivePacket(pOpenContext, pNdisPacket);
    }
    else
    {
        ndisprotFreeReceivePacket(pOpenContext, pNdisPacket);
    }
}


VOID
NdisProtReceiveComplete(
    IN NDIS_HANDLE                  ProtocolBindingContext
    )
/*++

Routine Description:

    Protocol entry point called by NDIS when the miniport
    has finished indicating up a batch of receives.

    We ignore this.

Arguments:

    ProtocolBindingContext - pointer to open context

Return Value:

    None

--*/
{
    PNDISPROT_OPEN_CONTEXT   pOpenContext;

    pOpenContext = (PNDISPROT_OPEN_CONTEXT)ProtocolBindingContext;
    NPROT_STRUCT_ASSERT(pOpenContext, oc);

    return;
}


INT
NdisProtReceivePacket(
    IN NDIS_HANDLE                  ProtocolBindingContext,
    IN PNDIS_PACKET                 pNdisPacket
    )
/*++

Routine Description:

    Protocol entry point called by NDIS if the driver below
    uses NDIS 4 style receive packet indications.

    If the miniport allows us to hold on to this packet, we
    use it as is, otherwise we make a copy.

Arguments:

    ProtocolBindingContext - pointer to open context
    pNdisPacket - the packet being indicated up.

Return Value:

    None

--*/
{
    PNDISPROT_OPEN_CONTEXT   pOpenContext;
    PNDIS_BUFFER            pNdisBuffer;
    UINT                    BufferLength;
    PNDISPROT_ETH_HEADER     pEthHeader;
    PNDIS_PACKET            pCopyPacket;
    PUCHAR                  pCopyBuf;
    UINT                    TotalPacketLength;
    UINT                    BytesCopied;
    INT                     RefCount = 0;
    NDIS_STATUS             Status;

    pOpenContext = (PNDISPROT_OPEN_CONTEXT)ProtocolBindingContext;
    NPROT_STRUCT_ASSERT(pOpenContext, oc);

#ifdef NDIS51
    NdisGetFirstBufferFromPacketSafe(
        pNdisPacket,
        &pNdisBuffer,
        &pEthHeader,
        &BufferLength,
        &TotalPacketLength,
        NormalPagePriority);

    if (pEthHeader == NULL)
    {
        //
        //  The system is low on resources. Set up to handle failure
        //  below.
        //
        BufferLength = 0;
    }
#else
    NdisGetFirstBufferFromPacket(
        pNdisPacket,
        &pNdisBuffer,
        &pEthHeader,
        &BufferLength,
        &TotalPacketLength);
#endif

    do
    {
        if (BufferLength < sizeof(NDISPROT_ETH_HEADER))
        {
            DEBUGP(DL_WARN,
                ("ReceivePacket: Open %p, runt pkt %p, first buffer length %d\n",
                    pOpenContext, pNdisPacket, BufferLength));

            Status = NDIS_STATUS_NOT_ACCEPTED;
            break;
        }

        DEBUGP(DL_LOUD, ("ReceivePacket: Open %p, interesting pkt %p\n",
                    pOpenContext, pNdisPacket));

        //
        //  If the miniport is out of resources, we can't queue
        //  this packet - make a copy if this is so.
        //
        if ((NDIS_GET_PACKET_STATUS(pNdisPacket) == NDIS_STATUS_RESOURCES))
        {
            pCopyPacket = ndisprotAllocateReceivePacket(
                            pOpenContext,
                            TotalPacketLength,
                            &pCopyBuf
                            );

            if (pCopyPacket == NULL)
            {
                DEBUGP(DL_FATAL, ("ReceivePacket: Open %p, failed to"
                    " alloc copy, %d bytes\n", pOpenContext, TotalPacketLength));
                break;
            }

            NdisCopyFromPacketToPacket(
                pCopyPacket,
                0,
                TotalPacketLength,
                pNdisPacket,
                0,
                &BytesCopied);

            NPROT_ASSERT(BytesCopied == TotalPacketLength);

            pNdisPacket = pCopyPacket;
        }
        else
        {
            //
            //  We can queue the original packet - return
            //  a packet reference count indicating that
            //  we will call NdisReturnPackets when we are
            //  done with this packet.
            //
            RefCount = 1;
        }

        //
        //  Queue this up and service any pending Read Requests.
        //
        ndisprotQueueReceivePacket(pOpenContext, pNdisPacket);

    }
    while (FALSE);

    return (RefCount);
}


VOID
ndisprotQueueReceivePacket(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext,
    IN PNDIS_PACKET                 pRcvPacket
    )
/*++

Routine Description:

    Queue up a received packet on the open context structure.
    If the queue size goes beyond a water mark, discard a packet
    at the head of the queue.

    Finally, run the queue service routine.

Arguments:

    pOpenContext - pointer to open context
    pRcvPacket - the received packet

Return Value:

    None

--*/
{
    PLIST_ENTRY     pEnt;
    PLIST_ENTRY     pDiscardEnt;
    PNDIS_PACKET    pDiscardPkt;

    do
    {
        pEnt = NPROT_RCV_PKT_TO_LIST_ENTRY(pRcvPacket);

        NPROT_REF_OPEN(pOpenContext);    // queued rcv packet

        NPROT_ACQUIRE_LOCK(&pOpenContext->Lock);

        //
        //  Check if the binding is in the proper state to receive
        //  this packet.
        //
        if (NPROT_TEST_FLAGS(pOpenContext->Flags, NPROTO_BIND_FLAGS, NPROTO_BIND_ACTIVE) &&
            (pOpenContext->PowerState == NetDeviceStateD0))
        {
            NPROT_INSERT_TAIL_LIST(&pOpenContext->RecvPktQueue, pEnt);
            pOpenContext->RecvPktCount++;

            DEBUGP(DL_VERY_LOUD, ("QueueReceivePacket: open %p,"
                    " queued pkt %p, queue size %d\n",
                    pOpenContext, pRcvPacket, pOpenContext->RecvPktCount));
        }
        else
        {
            //
            //  Received this packet when the binding is going away.
            //  Drop this.
            //
            NPROT_RELEASE_LOCK(&pOpenContext->Lock);

            ndisprotFreeReceivePacket(pOpenContext, pRcvPacket);

            NPROT_DEREF_OPEN(pOpenContext);  // dropped rcv packet - bad state
            break;
        }

        //
        //  Trim the queue if it has grown too big.
        //
        if (pOpenContext->RecvPktCount > MAX_RECV_QUEUE_SIZE)
        {
            //
            //  Remove the head of the queue.
            //
            pDiscardEnt = pOpenContext->RecvPktQueue.Flink;
            NPROT_REMOVE_ENTRY_LIST(pDiscardEnt);

            pOpenContext->RecvPktCount --;

            NPROT_RELEASE_LOCK(&pOpenContext->Lock);

            pDiscardPkt = NPROT_LIST_ENTRY_TO_RCV_PKT(pDiscardEnt);

            ndisprotFreeReceivePacket(pOpenContext, pDiscardPkt);

            NPROT_DEREF_OPEN(pOpenContext);  // dropped rcv packet - queue too long

            DEBUGP(DL_INFO, ("QueueReceivePacket: open %p queue"
                    " too long, discarded pkt %p\n",
                    pOpenContext, pDiscardPkt));
        }
        else
        {
            NPROT_RELEASE_LOCK(&pOpenContext->Lock);
        }

        //
        //  Run the receive queue service routine now.
        //
        ndisprotServiceReads(pOpenContext);
    }
    while (FALSE);
}


PNDIS_PACKET
ndisprotAllocateReceivePacket(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext,
    IN UINT                         DataLength,
    OUT PUCHAR *                    ppDataBuffer
    )
/*++

Routine Description:

    Allocate resources to copy and queue a received packet.

Arguments:

    pOpenContext - pointer to open context for received packet
    DataLength - total length in bytes of the packet
    ppDataBuffer - place to return pointer to allocated buffer

Return Value:

    Pointer to NDIS packet if successful, else NULL.

--*/
{
    PNDIS_PACKET            pNdisPacket;
    PNDIS_BUFFER            pNdisBuffer;
    PUCHAR                  pDataBuffer;
    NDIS_STATUS             Status;

    pNdisPacket = NULL;
    pNdisBuffer = NULL;
    pDataBuffer = NULL;

    do
    {
        NPROT_ALLOC_MEM(pDataBuffer, DataLength);

        if (pDataBuffer == NULL)
        {
            DEBUGP(DL_FATAL, ("AllocRcvPkt: open %p, failed to alloc"
                " data buffer %d bytes\n", pOpenContext, DataLength));
            break;
        }

        //
        //  Make this an NDIS buffer.
        //
        NdisAllocateBuffer(
            &Status,
            &pNdisBuffer,
            pOpenContext->RecvBufferPool,
            pDataBuffer,
            DataLength);

        if (Status != NDIS_STATUS_SUCCESS)
        {
            DEBUGP(DL_FATAL, ("AllocateRcvPkt: open %p, failed to alloc"
                " NDIS buffer, %d bytes\n", pOpenContext, DataLength));
            break;
        }

        NdisAllocatePacket(&Status, &pNdisPacket, pOpenContext->RecvPacketPool);

        if (Status != NDIS_STATUS_SUCCESS)
        {
            DEBUGP(DL_FATAL, ("AllocateRcvPkt: open %p, failed to alloc"
                " NDIS packet, %d bytes\n", pOpenContext, DataLength));
            break;
        }

        NDIS_SET_PACKET_STATUS(pNdisPacket, 0);
        NPROT_RCV_PKT_TO_ORIGINAL_BUFFER(pNdisPacket) = NULL;

        NdisChainBufferAtFront(pNdisPacket, pNdisBuffer);

        *ppDataBuffer = pDataBuffer;


    }
    while (FALSE);

    if (pNdisPacket == NULL)
    {
        //
        //  Clean up
        //
        if (pNdisBuffer != NULL)
        {
            NdisFreeBuffer(pNdisBuffer);
        }

        if (pDataBuffer != NULL)
        {
            NPROT_FREE_MEM(pDataBuffer);
        }
    }

    return (pNdisPacket);
}



VOID
ndisprotFreeReceivePacket(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext,
    IN PNDIS_PACKET                 pNdisPacket
    )
/*++

Routine Description:

    Free up all resources associated with a received packet. If this
    is a local copy, free the packet to our receive pool, else return
    this to the miniport.

Arguments:

    pOpenContext - pointer to open context
    pNdisPacket - pointer to packet to be freed.

Return Value:

    None

--*/
{
    PNDIS_BUFFER        pNdisBuffer;
    UINT                TotalLength;
    UINT                BufferLength;
    PUCHAR              pCopyData;

    if (NdisGetPoolFromPacket(pNdisPacket) == pOpenContext->RecvPacketPool)
    {
        //
        //  This is a local copy.
        //
#ifdef NDIS51
        NdisGetFirstBufferFromPacketSafe(
            pNdisPacket,
            &pNdisBuffer,
            (PVOID *)&pCopyData,
            &BufferLength,
            &TotalLength,
            NormalPagePriority);
#else
        NdisGetFirstBufferFromPacket(
            pNdisPacket,
            &pNdisBuffer,
            (PVOID *)&pCopyData,
            &BufferLength,
            &TotalLength);
#endif

        NPROT_ASSERT(BufferLength == TotalLength);

        NPROT_ASSERT(pNdisBuffer != NULL);

        NPROT_ASSERT(pCopyData != NULL); // we would have allocated non-paged pool

        NdisFreePacket(pNdisPacket);

        NdisFreeBuffer(pNdisBuffer);

        NPROT_FREE_MEM(pCopyData);
    }
    else
    {
        NdisReturnPackets(&pNdisPacket, 1);
    }
}


VOID
ndisprotFlushReceiveQueue(
    IN PNDISPROT_OPEN_CONTEXT            pOpenContext
    )
/*++

Routine Description:

    Free any receive packets queued up on the specified open

Arguments:

    pOpenContext - pointer to open context

Return Value:

    None

--*/
{
    PLIST_ENTRY         pRcvPacketEntry;
    PNDIS_PACKET        pRcvPacket;

    NPROT_REF_OPEN(pOpenContext);  // temp ref - flushRcvQueue

    NPROT_ACQUIRE_LOCK(&pOpenContext->Lock);

    while (!NPROT_IS_LIST_EMPTY(&pOpenContext->RecvPktQueue))
    {
        //
        //  Get the first queued receive packet
        //
        pRcvPacketEntry = pOpenContext->RecvPktQueue.Flink;
        NPROT_REMOVE_ENTRY_LIST(pRcvPacketEntry);

        pOpenContext->RecvPktCount --;

        NPROT_RELEASE_LOCK(&pOpenContext->Lock);

        pRcvPacket = NPROT_LIST_ENTRY_TO_RCV_PKT(pRcvPacketEntry);

        DEBUGP(DL_LOUD, ("FlushReceiveQueue: open %p, pkt %p\n",
            pOpenContext, pRcvPacket));

        ndisprotFreeReceivePacket(pOpenContext, pRcvPacket);

        NPROT_DEREF_OPEN(pOpenContext);    // took out pended Read

        NPROT_ACQUIRE_LOCK(&pOpenContext->Lock);
    }

    NPROT_RELEASE_LOCK(&pOpenContext->Lock);

    NPROT_DEREF_OPEN(pOpenContext);    // temp ref - flushRcvQueue
}



/*++

Copyright (c) Microsoft Corporation

Module Name:

    send.c

Abstract:

    NDIS protocol entry points and utility routines to handle sending
    data.

Environment:

    Kernel mode only.

--*/

#include "precomp.h"

#define __FILENUMBER 'DNES'




VOID
NdisProtEvtIoWrite(
    IN WDFQUEUE         Queue,
    IN WDFREQUEST       Request,
    IN size_t           Length
    )
/*++

Routine Description:

    Dispatch routine to handle Request_MJ_WRITE.

Arguments:

    Queue - Default queue handle
    Request - Handle to the read/write request
    Lenght - Length of the data buffer associated with the request.
                 The default property of the queue is to not dispatch
                 zero lenght read & write requests to the driver and
                 complete is with status success. So we will never get
                 a zero length request.

Return Value:

    VOID

--*/
{
    ULONG                   DataLength;
    NTSTATUS                NtStatus;
    NDIS_STATUS             Status;
    PNDISPROT_OPEN_CONTEXT  pOpenContext;
    PNDIS_PACKET            pNdisPacket;
    PNDIS_BUFFER            pNdisBuffer;
    NDISPROT_ETH_HEADER UNALIGNED *pEthHeader;
    PMDL                    mdl = NULL;
    WDFFILEOBJECT           fileObject;
    PREQUEST_CONTEXT        reqContext;
    WDF_OBJECT_ATTRIBUTES   attributes;

#ifdef NDIS51
    PVOID                   CancelId;
#endif

    UNREFERENCED_PARAMETER(Queue);


    fileObject = WdfRequestGetFileObject(Request);
    pOpenContext = GetFileObjectContext(fileObject)->OpenContext;
    pNdisPacket = NULL;

    do
    {
        //
        // Create a context to track the length of transfer and NDIS packet
        // associated with this request.
        //
        WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, REQUEST_CONTEXT);

        NtStatus = WdfObjectAllocateContext(Request, &attributes, &reqContext);
        if(!NT_SUCCESS(NtStatus)){
            DEBUGP(DL_WARN, ("Write: WdfObjectAllocateContext failed\n", NtStatus));
            NtStatus = STATUS_INVALID_HANDLE;
            break;

        }

        reqContext->Length = (ULONG) Length;

        if (pOpenContext == NULL)
        {
            DEBUGP(DL_WARN, ("Write: FileObject %p not yet associated with a device\n",  fileObject));
            NtStatus = STATUS_INVALID_HANDLE;
            break;
        }

        NPROT_STRUCT_ASSERT(pOpenContext, oc);

        NtStatus = WdfRequestRetrieveInputWdmMdl(Request, &mdl);
        if (!NT_SUCCESS(NtStatus))
        {
            DEBUGP(DL_FATAL, ("Write: WdfRequestRetrieveInputWdmMdl failed %x\n", NtStatus));
            break;
        }

        //
        // Try to get a virtual address for the MDL.
        //
        pEthHeader = MmGetSystemAddressForMdlSafe(mdl, NormalPagePriority);

        if (pEthHeader == NULL)
        {
            DEBUGP(DL_FATAL, ("Write: MmGetSystemAddr failed for"
                    " Request %p, MDL %p\n",
                    Request, mdl));
            NtStatus = STATUS_INSUFFICIENT_RESOURCES;
            break;
        }

        //
        // Sanity-check the length.
        //
        DataLength = MmGetMdlByteCount(mdl);
        if (DataLength < sizeof(NDISPROT_ETH_HEADER))
        {
            DEBUGP(DL_WARN, ("Write: too small to be a valid packet (%d bytes)\n",
                DataLength));
            NtStatus = STATUS_BUFFER_TOO_SMALL;
            break;
        }

        if (DataLength > (pOpenContext->MaxFrameSize + sizeof(NDISPROT_ETH_HEADER)))
        {
            DEBUGP(DL_WARN, ("Write: Open %p: data length (%d)"
                    " larger than max frame size (%d)\n",
                    pOpenContext, DataLength, pOpenContext->MaxFrameSize));

            NtStatus = STATUS_INVALID_BUFFER_SIZE;
            break;
        }

        //
        // To prevent applications from sending packets with spoofed
        // mac address, we will do the following check to make sure the source
        // address in the packet is same as the current MAC address of the NIC.
        //
        if ((WdfRequestGetRequestorMode(Request) == UserMode) &&
            !NPROT_MEM_CMP(pEthHeader->SrcAddr, pOpenContext->CurrentAddress, NPROT_MAC_ADDR_LEN))
        {
            DEBUGP(DL_WARN, ("Write: Failing with invalid Source address"));
            NtStatus = STATUS_INVALID_PARAMETER;
            break;
        }

        NPROT_ACQUIRE_LOCK(&pOpenContext->Lock);

        if (!NPROT_TEST_FLAGS(pOpenContext->Flags, NPROTO_BIND_FLAGS, NPROTO_BIND_ACTIVE))
        {
            NPROT_RELEASE_LOCK(&pOpenContext->Lock);

            DEBUGP(DL_FATAL, ("Write: Open %p is not bound"
            " or in low power state\n", pOpenContext));

            NtStatus = STATUS_INVALID_HANDLE;
            break;
        }

        //
        //  Allocate a send packet.
        //
        NPROT_ASSERT(pOpenContext->SendPacketPool != NULL);
        NdisAllocatePacket(
            &Status,
            &pNdisPacket,
            pOpenContext->SendPacketPool);

        if (Status != NDIS_STATUS_SUCCESS)
        {
            NPROT_RELEASE_LOCK(&pOpenContext->Lock);

            DEBUGP(DL_FATAL, ("Write: open %p, failed to alloc send pkt\n",
                    pOpenContext));
            NtStatus = STATUS_INSUFFICIENT_RESOURCES;
            break;
        }

        pNdisBuffer = mdl;


        NPROT_REF_OPEN(pOpenContext);  // pended send

        //
        //  Initialize the packet ref count. This packet will be freed
        //  when this count goes to zero.
        //
        NPROT_SEND_PKT_RSVD(pNdisPacket)->RefCount = 1;

        NPROT_RELEASE_LOCK(&pOpenContext->Lock);

        //
        //  Set a back pointer from the packet to the Request.
        //
        NPROT_Request_FROM_SEND_PKT(pNdisPacket) = Request;

        NtStatus = STATUS_PENDING;

        pNdisBuffer->Next = NULL;
        NdisChainBufferAtFront(pNdisPacket, pNdisBuffer);

#ifdef NDIS51

        //
        //  NDIS 5.1 supports cancelling sends. We set up a cancel ID on
        //  each send packet (which maps to a Write Request), and save the
        //  packet pointer in the Request. If the Request gets cancelled, we use
        //  NdisCancelSendPackets() to cancel the packet.
        //

        CancelId = NPROT_GET_NEXT_CANCEL_ID();
        NDIS_SET_PACKET_CANCEL_ID(pNdisPacket, CancelId);
        reqContext->NdisPacket = (PVOID)pNdisPacket;
        //
        // Take one more reference for the Cancel routine.
        //
        NPROT_REF_SEND_PKT(pNdisPacket);

        WdfRequestMarkCancelable(Request, NdisProtCancelWrite);

#endif // NDIS51
        NdisInterlockedIncrement((PLONG)&pOpenContext->PendedSendCount);

        NdisSendPackets(pOpenContext->BindingHandle, &pNdisPacket, 1);

    }
    while (FALSE);

    if (NtStatus != STATUS_PENDING)
    {
        WdfRequestComplete(Request, NtStatus);
    }

    return;
}


VOID
NdisProtSendComplete(
    IN NDIS_HANDLE                  ProtocolBindingContext,
    IN PNDIS_PACKET                 pNdisPacket,
    IN NDIS_STATUS                  Status
    )
/*++

Routine Description:

    NDIS entry point called to signify completion of a packet send.
    We pick up and complete the Write Request corresponding to this packet.

    NDIS 5.1:

Arguments:

    ProtocolBindingContext - pointer to open context
    pNdisPacket - packet that completed send
    Status - status of send

Return Value:

    None

--*/
{
    WDFREQUEST              request = NULL;
    PNDISPROT_OPEN_CONTEXT  pOpenContext;
    PREQUEST_CONTEXT        reqContext;
#ifdef NDIS51
    NTSTATUS NtStatus;
#endif

    pOpenContext = (PNDISPROT_OPEN_CONTEXT)ProtocolBindingContext;
    NPROT_STRUCT_ASSERT(pOpenContext, oc);

    request = NPROT_Request_FROM_SEND_PKT(pNdisPacket);
    reqContext = GetRequestContext(request);

#ifdef NDIS51
    //
    // Clear the cancelable state.
    //
    NtStatus = WdfRequestUnmarkCancelable(request);
    if(!NT_SUCCESS(NtStatus)) {
        //
        // Request is already canceled. The cancel-routine will drop the extra
        // reference.
        //
    } else {
            //
            // Remove the extra reference we took for the cancel routine.
            //
            NPROT_DEREF_SEND_PKT(pNdisPacket);
    }
#endif

    //
    //  We are done with the NDIS_PACKET:
    //
    NPROT_DEREF_SEND_PKT(pNdisPacket);

    //
    //  Complete the Write request the right status.
    //
    DEBUGP(DL_INFO, ("SendComplete: packet %p/Request %p/Length %d "
                    "completed with status %x\n",
                    pNdisPacket, request, reqContext->Length, Status));

    if (Status == NDIS_STATUS_SUCCESS)
    {
        WdfRequestCompleteWithInformation(request, STATUS_SUCCESS, reqContext->Length);
     }
    else
    {
        WdfRequestCompleteWithInformation(request, STATUS_UNSUCCESSFUL, 0);
    }

    NdisInterlockedDecrement((PLONG)&pOpenContext->PendedSendCount);
    NPROT_DEREF_OPEN(pOpenContext); // send complete - dequeued send Request
}

#ifdef NDIS51

VOID
NdisProtCancelWrite(
    IN WDFREQUEST Request
    )
/*++

Routine Description:

    Cancel a pending write Request. This routine attempt to cancel the NDIS send.
    The request will be always completed in the SendComplete routine.

Arguments:

    pDeviceObject - pointer to our device object
    pIrp - Request to be cancelled

Return Value:

    None

--*/
{
    PNDISPROT_OPEN_CONTEXT      pOpenContext;
    PNDIS_PACKET                pNdisPacket = NULL;
    PREQUEST_CONTEXT            reqContext;

    pOpenContext = (PNDISPROT_OPEN_CONTEXT)
        GetFileObjectContext(WdfRequestGetFileObject(Request))->OpenContext;
    reqContext = GetRequestContext(Request);
    pNdisPacket = reqContext->NdisPacket;

    NPROT_STRUCT_ASSERT(pOpenContext, oc);

    //
    //  Request NDIS to cancel this send. The result of this call is that
    //  our SendComplete handler will be called (if not already called).
    //
    DEBUGP(DL_INFO, ("CancelWrite: cancelling pkt %p on Open %p\n",
                                pNdisPacket, pOpenContext));

    NdisCancelSendPackets(
                        pOpenContext->BindingHandle,
                        NDIS_GET_PACKET_CANCEL_ID(pNdisPacket)
                        );

    //
    //  It is now safe to remove the reference we had placed on the packet
    //  before marking the request cancelable.
    //
    NPROT_DEREF_SEND_PKT(pNdisPacket);
 }

#endif // NDIS51






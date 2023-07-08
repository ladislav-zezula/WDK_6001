/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

Module Name:

    Send.C

Abstract:

    This module contains miniport functions for handling Send
    packets and other helper routines called by the miniport function.

--*/

#include "ndiswdm.h"


VOID
MPSendNetBufferLists(
    IN  NDIS_HANDLE         MiniportAdapterContext,
    IN  PNET_BUFFER_LIST    NetBufferList,
    IN  NDIS_PORT_NUMBER    PortNumber,
    IN  ULONG               SendFlags
    )
/*++

Routine Description:

    Called by NDIS to send network packet. MiniportSendNetBufferLists takes
    as a parameter a pointer to a linked list of NET_BUFFER_LIST structures,
    each of which contains a linked list of NET_BUFFER structures.
    The MiniportSendNetBufferLists function does not have a return value.

    A miniport driver must therefore always complete a send operation
    by calling NdisMSendNetBufferListComplete.

    NDIS 6.0 miniport drivers specify the completion status in the
    NET_BUFFER_LIST structure by calling the
    NET_BUFFER_LIST_STATUS(NetBufferList) macro.

    The completion status applies to all the NET_BUFFER structures associated
    with the NET_BUFFER_LIST structure. Therefore, a miniport driver should
    set the completion status to NDIS_STATUS_SUCCESS only if the data in
    all the NET_BUFFER structures associated with the NET_BUFFER_LIST
    structure was transmitted successfully.

    Runs at IRQL <= DISPATCH_LEVEL

Arguments:

    MiniportAdapterContext    Pointer to our adapter context
    PacketArray               Set of packets to send
    NumberOfPackets           Length of above array

Return Value:

    None

--*/
{
    PMP_ADAPTER       Adapter;
    NDIS_STATUS       Status = NDIS_STATUS_FAILURE;
    UINT                NetBufferCount = 0;
    PNET_BUFFER         NetBuffer;
    PNET_BUFFER_LIST    CurrNetBufferList;
    PNET_BUFFER_LIST    NextNetBufferList;
    KIRQL               OldIrql = 0;
    BOOLEAN             DispatchLevel;

    DEBUGP(MP_INFO, ("---> MPSendNetBufferLists 0x%p\n", NetBufferList));

    UNREFERENCED_PARAMETER(PortNumber);

    Adapter = (PMP_ADAPTER)MiniportAdapterContext;
    DispatchLevel = NDIS_TEST_SEND_AT_DISPATCH_LEVEL(SendFlags) ? TRUE: FALSE;

   do
    {
        //
        // If the adapter is in Pausing or paused state, just fail the send.
        //
        if (Adapter->AdapterState != NicRunning)
        {
            ASSERTMSG("Adapter is not in a running state ", FALSE);
            Status =  NDIS_STATUS_PAUSED;
            break;
        }

        MP_ACQUIRE_SPIN_LOCK(&Adapter->SendLock, DispatchLevel);
        OldIrql = Adapter->SendLock.OldIrql;

        //
        // Adapter is ready, send this net buffer list, in this case,
        // we always return pending
        //
        for (CurrNetBufferList = NetBufferList;
                CurrNetBufferList != NULL;
                CurrNetBufferList = NextNetBufferList)
        {

            Adapter->nPacketsArrived++;

            NextNetBufferList = NET_BUFFER_LIST_NEXT_NBL(CurrNetBufferList);
            //
            // Get how many net buffers inside the net buffer list
            //
            NetBufferCount = 0;
            for (NetBuffer = NET_BUFFER_LIST_FIRST_NB(CurrNetBufferList);
                    NetBuffer != NULL;
                    NetBuffer = NET_BUFFER_NEXT_NB(NetBuffer))
            {

                NetBufferCount++;
                DEBUGP(MP_INFO, ("  %d: NetBuffer 0x%p\n", NetBufferCount, NetBuffer));
            }

            ASSERT(NetBufferCount > 0);

            //
            // Save the reference count in the MiniportReserved[1] field of
            // the NetBufferList.
            //
            MP_GET_NET_BUFFER_LIST_REF_COUNT(CurrNetBufferList) = NetBufferCount;

            //
            // Is the adapter busy sending another NetBufferList?
            //
            if (Adapter->SendingNetBufferList != NULL ||
                 MP_TEST_FLAG(Adapter, fMP_POST_WRITES) == FALSE)
            {
                //
                // Adapter is busy sending another netbuffer list. Just
                // queue this one.
                //
                MP_GET_NET_BUFFER_LIST_NEXT_SEND(CurrNetBufferList) =
                                    NET_BUFFER_LIST_FIRST_NB(CurrNetBufferList);
                NET_BUFFER_LIST_STATUS(CurrNetBufferList) = NDIS_STATUS_SUCCESS;

                InsertTailList(&Adapter->SendWaitList,
                            (PLIST_ENTRY)MP_GET_NET_BUFFER_LIST_LINK(CurrNetBufferList));

                Adapter->nWaitSend++;
            }
            else
            {
                ASSERT(Adapter->SendingNetBufferList == NULL);
                ASSERT(Adapter->PendingNetBuffer == NULL);
                Adapter->SendingNetBufferList = CurrNetBufferList;
                NET_BUFFER_LIST_STATUS(CurrNetBufferList) = NDIS_STATUS_SUCCESS;
                NICSendNetBufferList(Adapter,
                                CurrNetBufferList,
                                NET_BUFFER_LIST_FIRST_NB(CurrNetBufferList));
            }

            Status = NDIS_STATUS_PENDING;

        }

        Adapter->SendLock.OldIrql = OldIrql;
        MP_RELEASE_SPIN_LOCK(&Adapter->SendLock, DispatchLevel);
    }WHILE (FALSE);

    if (Status != NDIS_STATUS_PENDING)
    {
        ULONG SendCompleteFlags = 0;

        //
        // Walk the chain of NetBufferList to set the failure status.
        //
        for (CurrNetBufferList = NetBufferList;
                 CurrNetBufferList != NULL;
                 CurrNetBufferList = NextNetBufferList)
        {
            NextNetBufferList = NET_BUFFER_LIST_NEXT_NBL(CurrNetBufferList);
            NET_BUFFER_LIST_STATUS(CurrNetBufferList) = Status;
        }

        if (NDIS_TEST_SEND_AT_DISPATCH_LEVEL(SendFlags))
        {
            NDIS_SET_SEND_COMPLETE_FLAG(SendCompleteFlags, NDIS_SEND_COMPLETE_FLAGS_DISPATCH_LEVEL);
        }

        DEBUGP(MP_TRACE, ("Completing NBL 0x%p\n", NetBufferList));

        NdisMSendNetBufferListsComplete(
            Adapter->AdapterHandle,
            NetBufferList,
            SendCompleteFlags);
    }

    DEBUGP(MP_TRACE, ("<--- MPSendNetBufferLists\n"));

    return;
}


NDIS_STATUS
NICSendNetBufferList(
    IN  PMP_ADAPTER         Adapter,
    IN  PNET_BUFFER_LIST    NetBufferList,
    IN  PNET_BUFFER         NetBufferToSend
    )
/*++
Routine Description:

    Do the work to send a packet
    Assumption: Send spinlock has been acquired

Arguments:

    Adapter             Pointer to our adapter
    NetBufferList       Pointer to the NetBufferList is going to send.

Return Value:

    NDIS_STATUS_SUCCESS
    NDIS_STATUS_PENDING         Put into the send wait queue
    NDIS_STATUS_HARD_ERRORS

    NOTE: SendLock is held, called at DISPATCH level
--*/
{
    NDIS_STATUS     Status = NDIS_STATUS_PENDING;
    NDIS_STATUS     SendStatus;
    PTCB            pTCB = NULL;
    NTSTATUS        ntStatus;
    BOOLEAN         atDispatchLevel = TRUE, result;

    DEBUGP(MP_TRACE, ("--> NICSendNetBufferList, NetBufferList 0x%p\n",
                            NetBufferList));
    SendStatus = NDIS_STATUS_SUCCESS;

    for (;
            NetBufferToSend != NULL;
            NetBufferToSend = NET_BUFFER_NEXT_NB(NetBufferToSend))
    {
        //
        // Get a free TCB block
        //
        if (IsListEmpty(&Adapter->SendFreeList)) {
            DEBUGP (MP_TRACE, ( "TCB not available\n" ));
            ASSERT(Adapter->PendingNetBuffer == NULL);
            Adapter->PendingNetBuffer = NetBufferToSend;
            SendStatus = NDIS_STATUS_SUCCESS;
            break;

        }

        pTCB = (PTCB) RemoveHeadList(&Adapter->SendFreeList);

        Adapter->nBusySend++;
        ASSERT(Adapter->nBusySend <= NIC_MAX_BUSY_SENDS);

        MP_RELEASE_SPIN_LOCK(&Adapter->SendLock, atDispatchLevel);

        //
        // 1) If the target support chained MDLs and if the packet
        // size is more than minimum required size (so that we
        // have pad with zero), just build a new MDL chain such that
        // the first MDL in the chain contains the start of the packet.
        // 2) Even if the target doesn't support MDL chains, and the
        // entire packet is in one MDL, we will avoid copy and just
        // build a partial MDL.
        //
        if ((Adapter->IsTargetSupportChainedMdls &&
                NET_BUFFER_DATA_LENGTH(NetBufferToSend) >= ETH_MIN_PACKET_SIZE)
                || NetBufferToSend->MdlChain->Next == NULL) {

            result = NICCopyNetBufferMdlToMdl(Adapter, pTCB, NetBufferList, NetBufferToSend);

        } else {
            //
            // The target doesn't support chained MDLs and the packet could be
            // spanning more than one MDL. Best thing is to copy the content
            // of the packet to a TCB block buffer.
            //
            result = NICCopyNetBuffer(Adapter, pTCB, NetBufferList, NetBufferToSend);
        }

        if (result)
        {
            NdisInterlockedInsertTailList(
                        &Adapter->SendBusyList,
                        &pTCB->List,
                        &Adapter->SendLock);

            Adapter->nWritesPosted++;

            //
            // Post a asynchronouse write request.
            //
            ntStatus = NICPostWriteRequest(Adapter, pTCB);

            if ( !NT_SUCCESS ( ntStatus ) ) {
                DEBUGP (MP_ERROR, ( "NICPostWriteRequest failed %x\n", ntStatus ));
                Status = NDIS_STATUS_FAILURE;
                MP_ACQUIRE_SPIN_LOCK(&Adapter->SendLock, atDispatchLevel);
                break;
            }

            NT_STATUS_TO_NDIS_STATUS(ntStatus, &Status);

        }else {

            DEBUGP(MP_ERROR, ("NICCopyPacket returned error\n"));
            Status = NDIS_STATUS_FAILURE;

            NICFreeSendTCB(Adapter, pTCB);

            MP_ACQUIRE_SPIN_LOCK(&Adapter->SendLock, atDispatchLevel);

            break;
        }

        MP_ACQUIRE_SPIN_LOCK(&Adapter->SendLock, atDispatchLevel);

    }

    if (NDIS_STATUS_SUCCESS != SendStatus)
    {
        //
        // We should fail the entire NET_BUFFER_LIST because the system
        // cannot map the NET_BUFFER
        //
        NET_BUFFER_LIST_STATUS(NetBufferList) = NDIS_STATUS_RESOURCES;

        for (; NetBufferToSend != NULL;
               NetBufferToSend = NET_BUFFER_NEXT_NB(NetBufferToSend))
        {
            MP_GET_NET_BUFFER_LIST_REF_COUNT(NetBufferList)--;
        }
        //
        // Following function completes the buffer list only
        // if all the outstanding send operations to the target
        // device completes.
        //
        NICCompleteSendNetBufferLists(Adapter, NetBufferList);
    }

    DEBUGP(MP_TRACE, ("<-- NICSendNetBufferList\n"));
    return Status;

}

NTSTATUS
NICPostWriteRequest(
    PMP_ADAPTER Adapter,
    PTCB    pTCB
    )
/*++

Routine Description:

    This routine posts a write Request to the target device to send
    the network packet out to the device.

Arguments:

    Adapter    - pointer to the MP_ADAPTER structure
    PTCB    -  Pointer to the TCB block that contains the Request and data.


Return Value:

    NT status code

--*/
{
    PIRP            irp = NULL;
    PIO_STACK_LOCATION  nextStack;
    NTSTATUS    status = STATUS_SUCCESS;

    DEBUGP(MP_TRACE, ("--> NICPostWriteRequest sending NetBufferList 0x%p "
                      "NetBuffer 0x%p\n", pTCB->NetBufferList, pTCB->NetBuffer));

    status = WdfIoTargetFormatRequestForWrite(
                                    Adapter->IoTarget,
                                    pTCB->Request,
                                    NULL, //OutputBuffer
                                    NULL, // OutputBufferOffsets
                                    NULL); // StartingOffset

    if (!NT_SUCCESS(status)) {
        return status;
    }

    irp = WdfRequestWdmGetIrp(pTCB->Request);
    //
    // Obtain a pointer to the stack location of the first driver that will be
    // invoked.  This is where the function codes and the parameters are set.
    //
    nextStack = IoGetNextIrpStackLocation( irp );

    if (pTCB->WhichMdl == DATA_MDL) {
        irp->MdlAddress = pTCB->DataMdl;
    } else if (pTCB->WhichMdl == PARTIAL_MDL) {
        irp->MdlAddress = pTCB->PartialMdl;
    } else {
        ASSERTMSG("Unknown MDL type ", FALSE);
    }
    nextStack->Parameters.Write.Length = pTCB->ulSize;

    WdfRequestSetCompletionRoutine(pTCB->Request,
                   NICWriteRequestCompletion,
                   pTCB);

    //
    // We are making an asynchronous request, so we don't really care
    // about the return status of IoCallDriver.
    //
    if (WdfRequestSend(pTCB->Request, Adapter->IoTarget, WDF_NO_SEND_OPTIONS) == FALSE) {
        status = WdfRequestGetStatus(pTCB->Request);
    }

    DEBUGP(MP_TRACE, ("<-- NICPostWriteRequest\n"));

    return status;
}

VOID
NICWriteRequestCompletion(
    IN WDFREQUEST                  Request,
    IN WDFIOTARGET                 Target,
    PWDF_REQUEST_COMPLETION_PARAMS CompletionParams,
    IN WDFCONTEXT                  Context
    )
/*++

Routine Description:

    Completion routine for the write request. This routine
    indicates to NDIS that send operation is complete and
    free the TCB if nobody has already done so. This routine
    also handles the case where another thread has canceled the
    write request.

Arguments:

    DeviceObject    -  not used. Should be NULL
    Request    -   Pointer to our Request
    Context - pointer to our adapter context structure

Return Value:

    STATUS_MORE_PROCESSING_REQUIRED - because this is an asynchronouse Request
    and we want to reuse it.

--*/
{
    PTCB              pTCB = (PTCB)Context;
    PMP_ADAPTER       Adapter = pTCB->Adapter;
    PLIST_ENTRY       pEntry = NULL;
    PNET_BUFFER_LIST  NetBufferList = NULL;
    PNET_BUFFER       NetBufferToSend = NULL;
    NTSTATUS          status;
    ULONG             bytesWritten;

    UNREFERENCED_PARAMETER(Target);
    UNREFERENCED_PARAMETER(Request);

    DEBUGP(MP_TRACE, ("--> NICWriteRequestCompletion\n"));

    status = CompletionParams->IoStatus.Status;

    if (NT_SUCCESS(status)) {
        bytesWritten = (ULONG)CompletionParams->IoStatus.Information;
        DEBUGP (MP_INFO, ("Wrote %d bytes\n", bytesWritten));
        Adapter->GoodTransmits++;
        Adapter->nBytesWritten += bytesWritten;

    } else {

        DEBUGP (MP_ERROR, ("Write request failed %x\n", status));
        Adapter->nWritesCompletedWithError++;
        //
        // Clear the flag to prevent any more writes from being
        // posted to the target device.
        //
        //MP_CLEAR_FLAG(Adapter, fMP_POST_WRITES);

    }

    pTCB->Ref--;

    if (NT_SUCCESS(status))
    {

        NetBufferList = pTCB->NetBufferList;

        MP_SEND_STATS(Adapter, pTCB->NetBuffer);

        //
        // For performance, let us free the TCB block before completing send.
        //
        NICFreeSendTCB(Adapter, pTCB);

        MP_GET_NET_BUFFER_LIST_REF_COUNT(NetBufferList)--;

        NdisAcquireSpinLock(&Adapter->SendLock);

        if (Adapter->PendingNetBuffer != NULL) {

            NetBufferToSend = Adapter->PendingNetBuffer;
            Adapter->PendingNetBuffer = NULL;
            //
            // There is still pending list of NetBuffers to send for the
            // current SendingNetBufferList.
            //
            ASSERT(Adapter->SendingNetBufferList != NULL);
            (VOID) NICSendNetBufferList(Adapter, NetBufferList, NetBufferToSend);

        } else {
            NICCompleteSendNetBufferLists(Adapter, NetBufferList);
        }

        if (Adapter->SendingNetBufferList == NULL &&
            IsListEmpty(&Adapter->SendWaitList) == FALSE)
        {
            pEntry = (PLIST_ENTRY)RemoveHeadList(&Adapter->SendWaitList);

            Adapter->nWaitSend--;

            ASSERT(Adapter->nWaitSend >= 0);

            NetBufferList = MP_GET_NET_BUFFER_LIST_FROM_LIST_ENTRY(pEntry);

            Adapter->SendingNetBufferList = NetBufferList;

            NetBufferToSend = MP_GET_NET_BUFFER_LIST_NEXT_SEND(NetBufferList);
            MP_GET_NET_BUFFER_LIST_NEXT_SEND(NetBufferList) = NULL;
            NetBufferList->FirstNetBuffer = NetBufferToSend;

            //
            // TODO: This can cause recursion if the target driver completes
            // write requests synchronously. Use workitem to avoid recursion.
            //

            (VOID) NICSendNetBufferList(Adapter, NetBufferList, NetBufferToSend);
        }


        NdisReleaseSpinLock(&Adapter->SendLock);

    }

    DEBUGP(MP_TRACE, ("<-- NICWriteRequestCompletion\n"));

    return;
}


VOID
NICFreeSendTCB(
    IN PMP_ADAPTER Adapter,
    IN PTCB pTCB)
/*++

Routine Description:

    Adapter    - pointer to the adapter structure
    pTCB      - pointer to TCB block

Arguments:

    This routine reinitializes the TCB block and puts it back
    into the SendFreeList for reuse.


Return Value:

    VOID

--*/
{
    WDF_REQUEST_REUSE_PARAMS    params;
    PIRP                        irp = NULL;
    PIO_STACK_LOCATION          nextStack;
    NTSTATUS status;

    DEBUGP(MP_TRACE, ("--> NICFreeSendTCB %p\n", pTCB));

    pTCB->NetBufferList= NULL;
    pTCB->NetBuffer = NULL;

    if (pTCB->WhichMdl == DATA_MDL) {
        pTCB->DataMdl->Next = NULL;
        //
        // Re adjust the length to the originl size
        //
        NdisAdjustMdlLength(pTCB->DataMdl, NIC_BUFFER_SIZE);
    } else {
        MmPrepareMdlForReuse(pTCB->PartialMdl);
        pTCB->PartialMdl->Next = NULL;
    }

    pTCB->WhichMdl = INVALID_MDL;
    pTCB->ulSize = 0;

    ASSERT(pTCB->Request);
    ASSERT(!pTCB->Ref);

    WDF_REQUEST_REUSE_PARAMS_INIT(&params,
                            WDF_REQUEST_REUSE_NO_FLAGS,
                            STATUS_SUCCESS);

    status = WdfRequestReuse(pTCB->Request, &params);
    if (!NT_SUCCESS(status)){
        DEBUGP(MP_ERROR, ("WdfRequestReuse failed 0x%x\n", status));
        ASSERT(FALSE);
        return;
    }

    //
    // Set the MDL field to NULL so that we don't end up freeing the
    // MDL when we delete the Request object.
    //
    irp = WdfRequestWdmGetIrp(pTCB->Request);
    nextStack = IoGetNextIrpStackLocation( irp );
    irp->MdlAddress = NULL;

    //
    // Insert the TCB back in the send free list
    //
    NdisAcquireSpinLock(&Adapter->SendLock);

    RemoveEntryList(&pTCB->List);

    InsertTailList(&Adapter->SendFreeList, &pTCB->List);

    Adapter->nBusySend--;
    ASSERT(Adapter->nBusySend >= 0);

    NdisReleaseSpinLock(&Adapter->SendLock);


    DEBUGP(MP_TRACE, ("<-- NICFreeSendTCB\n"));

}


VOID
NICFreeQueuedSendNetBufferLists(
    IN  PMP_ADAPTER  Adapter
    )
/*++
Routine Description:

    Free and complete the pended sends on SendWaitList
    Assumption: spinlock has been acquired

Arguments:

    Adapter     Pointer to our adapter

Return Value:

     None
NOTE: Run at DPC

--*/
{
    PLIST_ENTRY         pEntry;
    PNET_BUFFER_LIST    NetBufferList;
    PNET_BUFFER_LIST    NetBufferListToComplete = NULL;
    PNET_BUFFER_LIST    PendingNetBufferList = NULL;
    NDIS_STATUS         Status = NDIS_STATUS_FAILURE;
    PNET_BUFFER         NetBuffer;
    BOOLEAN             atDispatchLevel = TRUE;

    DEBUGP(MP_TRACE, ("--> NICFreeQueuedSendNetBufferLists\n"));

    while (!IsListEmpty(&Adapter->SendWaitList))
    {
        pEntry = RemoveHeadList(&Adapter->SendWaitList);
        ASSERT(pEntry);

        Adapter->nWaitSend--;

        NetBufferList = MP_GET_NET_BUFFER_LIST_FROM_LIST_ENTRY(pEntry);

        NET_BUFFER_LIST_STATUS(NetBufferList) = Status;
        //
        // The sendLock is held
        //
        NetBuffer = MP_GET_NET_BUFFER_LIST_NEXT_SEND(NetBufferList);
        MP_GET_NET_BUFFER_LIST_NEXT_SEND(NetBufferList) = NULL;
        NetBufferList->FirstNetBuffer = NetBuffer;

        for (; NetBuffer != NULL; NetBuffer = NET_BUFFER_NEXT_NB(NetBuffer))
        {
            MP_GET_NET_BUFFER_LIST_REF_COUNT(NetBufferList)--;
        }
        //
        // If Ref count goes to 0, then complete it.
        // Otherwise, Send interrupt DPC would complete it later
        //
        if (MP_GET_NET_BUFFER_LIST_REF_COUNT(NetBufferList) == 0)
        {
            if (NetBufferListToComplete == NULL)
            {
                NetBufferListToComplete = NetBufferList;
            }
            else
            {
                NET_BUFFER_LIST_NEXT_NBL(PendingNetBufferList) = NetBufferList;
            }
            NET_BUFFER_LIST_NEXT_NBL(NetBufferList) = NULL;
            PendingNetBufferList = NetBufferList;

        }
    }

    if (NetBufferListToComplete != NULL)
    {
        MP_RELEASE_SPIN_LOCK(&Adapter->SendLock, atDispatchLevel);
        NdisMSendNetBufferListsComplete(
               Adapter->AdapterHandle,
               NetBufferListToComplete,
               NDIS_SEND_COMPLETE_FLAGS_DISPATCH_LEVEL);

        MP_ACQUIRE_SPIN_LOCK(&Adapter->SendLock, atDispatchLevel);
    }

    DEBUGP(MP_TRACE, ("<-- NICFreeQueuedSendNetBufferLists\n"));

}

BOOLEAN
NICCopyNetBuffer(
    PMP_ADAPTER Adapter,
    PTCB pTCB,
    IN PNET_BUFFER_LIST NetBufferList,
    IN  PNET_BUFFER     NetBuffer
   )
/*++
Routine Description:

   Copy data in a packet to the specified location

Arguments:


Return Value:

    TRUE if the data is copied to TCB buffer

--*/
{
    PUCHAR         pDest;
    ULONG          bytesCopied = 0;
    ULONG          offset;
    PMDL           firstMdl;
    ULONG          dataLength;
    BOOLEAN        bRet;
    NTSTATUS       status = STATUS_SUCCESS;

    DEBUGP(MP_TRACE, ("--> NICCopyNetBuffer\n"));

    pTCB->Adapter = Adapter;
    pTCB->NetBuffer = NetBuffer;
    pTCB->NetBufferList = NetBufferList;

    pTCB->Ref = 1;
    NdisInitializeListHead(&pTCB->List);

    dataLength = NET_BUFFER_DATA_LENGTH(NetBuffer);
    firstMdl = NET_BUFFER_FIRST_MDL(NetBuffer);
    offset = NET_BUFFER_DATA_OFFSET(NetBuffer);

    ASSERT(dataLength <= NIC_BUFFER_SIZE);

    status = NICCopyMdlToBuffer(firstMdl,
                            (SIZE_T)offset,
                            pTCB->Data,
                            (SIZE_T)dataLength,
                            (SIZE_T*)&bytesCopied);
    if (!NT_SUCCESS(status))
    {
        bRet = FALSE;
        goto End;
    }

    //
    // If the data size is less than ETH_MIN_PACKET_SIZE then
    // zero out the trailing buffer for security.
    //
    if ((bytesCopied != 0) && (bytesCopied < ETH_MIN_PACKET_SIZE))
    {
        pDest = &pTCB->Data[0] + bytesCopied;
        NdisZeroMemory(pDest, ETH_MIN_PACKET_SIZE - bytesCopied);
    }

    NdisAdjustMdlLength(pTCB->DataMdl, bytesCopied);
    pTCB->ulSize = bytesCopied;
    pTCB->WhichMdl = DATA_MDL;
    Adapter->nBytesArrived += pTCB->ulSize;

    bRet = TRUE;

End:

    DEBUGP(MP_TRACE, ("<-- NICCopyNetBuffer\n"));
    return bRet;
}

BOOLEAN
NICCopyNetBufferMdlToMdl(
    PMP_ADAPTER Adapter,
    PTCB pTCB,
    IN PNET_BUFFER_LIST NetBufferList,
    IN  PNET_BUFFER     NetBuffer
   )
/*++
Routine Description:

   Called if the target device supports chained MDLs, if the packet
   size is less than the required minimum ethernet packet size, or if
   the entire packet is in one MDL.

   Find the first MDL that contains the data and build a partial
   MDL to represent the buffer taking into account the Data-Offset
   value. Chain rest of the MDLs to the partial MDL.

Arguments:


Return Value:

    TRUE if the data is copied to TCB buffer

--*/
{
    PUCHAR         pDest;
    ULONG          offset;
    PMDL           firstMdl;
    ULONG          dataLength, mdlByteCount, length;
    BOOLEAN        bRet;

    DEBUGP(MP_TRACE, ("--> NICCopyNetBuffer\n"));

    //
    // Validation.
    //
    pTCB->Adapter = Adapter;
    pTCB->NetBuffer = NetBuffer;
    pTCB->NetBufferList = NetBufferList;

    pTCB->Ref = 1;
    NdisInitializeListHead(&pTCB->List);

    dataLength = NET_BUFFER_DATA_LENGTH(NetBuffer);
    firstMdl = NET_BUFFER_FIRST_MDL(NetBuffer);
    offset = NET_BUFFER_DATA_OFFSET(NetBuffer);

    ASSERT(dataLength <= NIC_BUFFER_SIZE);

    mdlByteCount = 0;

    //
    // Skip the required offset bytes in the MDL chain.
    //
    while (firstMdl && offset >= (mdlByteCount = MmGetMdlByteCount(firstMdl))) {
        offset -= mdlByteCount;
        firstMdl = firstMdl->Next;
    }

    //
    // Skip zero length MDLs.
    //
    for (; firstMdl; firstMdl = firstMdl->Next) {

        mdlByteCount = MmGetMdlByteCount(firstMdl);
        if (mdlByteCount != 0) {
            break;
        }
    }

    mdlByteCount -= offset; // Remaining size of data
    length = min(dataLength, mdlByteCount); // Adjust if the remaining size is
                                            // more than total DataLength

    pDest = MmGetSystemAddressForMdlSafe(firstMdl, LowPagePriority);
    if (pDest == NULL) {
        bRet = FALSE;
        goto End;
    }

    //
    // With that we will build a new MDL to corresponding to the first mdl
    // with the right bytecount and offset.
    //
    IoBuildPartialMdl(firstMdl, pTCB->PartialMdl, pDest+offset, length);

    //
    // Chain rest of the MDLs if there is more data past the first mdl.
    //
    if (dataLength > MmGetMdlByteCount(pTCB->PartialMdl)) {
        pTCB->PartialMdl->Next = firstMdl->Next;
    } else {
        pTCB->PartialMdl->Next = NULL;
    }

    pTCB->ulSize = dataLength;
    pTCB->WhichMdl = PARTIAL_MDL;
    Adapter->nBytesArrived += pTCB->ulSize;

    //
    // Make sure the data doesn't span multiple MDLs if the target
    // doesn't support
    //
    if (Adapter->IsTargetSupportChainedMdls == FALSE) {
        ASSERT(pTCB->PartialMdl->Next == NULL);
    }

    bRet = TRUE;

End:

    DEBUGP(MP_TRACE, ("<-- NICCopyNetBuffer\n"));
    return bRet;
}

VOID
NICCompleteSendNetBufferLists(
    PMP_ADAPTER Adapter,
    IN  PNET_BUFFER_LIST     NetBufferList
    )
{

    if (MP_GET_NET_BUFFER_LIST_REF_COUNT(NetBufferList) == 0)
    {

        DEBUGP(MP_INFO, ("Completing NBL 0x%p with Status 0x%x\n",
                            NetBufferList,
                            NET_BUFFER_LIST_STATUS(NetBufferList)));

        ASSERT(Adapter->SendingNetBufferList == NetBufferList);

        Adapter->SendingNetBufferList = NULL;
        Adapter->PendingNetBuffer = NULL;

        NdisReleaseSpinLock(&Adapter->SendLock);

        NET_BUFFER_LIST_NEXT_NBL(NetBufferList) = NULL;

        NdisMSendNetBufferListsComplete(
            Adapter->AdapterHandle,
            NetBufferList,
            0);

        NdisAcquireSpinLock(&Adapter->SendLock);
    }

}



NTSTATUS
NICCopyMdlToBuffer(
    IN PMDL Mdl,
    IN SIZE_T MdlOffset,
    __out_bcount_part(BytesToCopy, *BytesCopied) IN PVOID Buffer,
    IN SIZE_T BytesToCopy,
    OUT SIZE_T* BytesCopied
    )
{
    SIZE_T MdlByteCount, Remain, CopySize;

    //
    // This routine copies data from an MDL chain to a flat buffer
    // A maximum of BytesToCopy bytes will be copied.
    // The actual number of bytes copied is returned in BytesCopied.
    //

    *BytesCopied = 0;

    //
    // Skip the required offset bytes in the MDL chain.
    //

    while (Mdl && MdlOffset >= (MdlByteCount = MmGetMdlByteCount(Mdl))) {
        MdlOffset -= MdlByteCount;
        Mdl = Mdl->Next;
    }

    //
    // While there is remaining data to be copied, and we have MDLs to walk...
    //

    for (Remain = BytesToCopy; Mdl && (Remain > 0); Mdl = Mdl->Next) {

        PUCHAR SysVa;

        //
        // Skip zero length MDLs.
        //

        MdlByteCount = MmGetMdlByteCount(Mdl);
        if (MdlByteCount == 0) {
            continue;
        }

        //
        // Compute the amount to transfer this time.
        //

        ASSERT(MdlOffset < MdlByteCount);
        MdlByteCount -= MdlOffset;
        CopySize = min(Remain, MdlByteCount);

        //
        // Perform the transfer, either directly or using our reserved PTE.
        //

        SysVa = MmGetSystemAddressForMdlSafe(Mdl, LowPagePriority);
        if (SysVa == NULL) {
            return STATUS_INSUFFICIENT_RESOURCES;
        } else {
            RtlCopyMemory(Buffer, SysVa + MdlOffset, CopySize);
        }

        MdlOffset = 0;
        (PUCHAR)Buffer += CopySize;
        Remain -= CopySize;
    }

    *BytesCopied = BytesToCopy - Remain;
    ASSERT(*BytesCopied <= BytesToCopy);

    return STATUS_SUCCESS;
}

VOID
MPCancelSendNetBufferLists(
    IN  NDIS_HANDLE     MiniportAdapterContext,
    IN  PVOID           CancelId
    )
/*++

Routine Description:

    MiniportCancelNetBufferLists handler - This function walks through all
    of the queued send NetBufferLists and cancels all the NetBufferLists that
    have the correct CancelId

Arguments:

    MiniportAdapterContext      Pointer to our adapter
    CancelId                    All the Net Buffer Lists with this Id should be cancelled

Return Value:

    None

--*/
{
    PMP_ADAPTER         Adapter = (PMP_ADAPTER)MiniportAdapterContext;
    PNET_BUFFER_LIST    NetBufferList;
    PNET_BUFFER_LIST    CancelHeadNetBufferList = NULL;
    PNET_BUFFER_LIST    CancelTailNetBufferList = NULL;
    PVOID               NetBufferListId;
    PLIST_ENTRY         thisEntry, nextEntry, listHead;
    PNET_BUFFER         NetBuffer;


    DEBUGP(MP_TRACE, ("---> MPCancelSendNetBufferLists\n"));

    NdisAcquireSpinLock(&Adapter->SendLock);

    //
    // Walk through the send wait list and complete the sends with matching Id
    //
    listHead = &Adapter->SendWaitList;

    for(thisEntry = listHead->Flink, nextEntry = thisEntry->Flink;
        thisEntry != listHead;
        thisEntry = nextEntry, nextEntry = thisEntry->Flink)
    {
        NetBufferList = MP_GET_NET_BUFFER_LIST_FROM_LIST_ENTRY(thisEntry);

        NetBufferListId = NDIS_GET_NET_BUFFER_LIST_CANCEL_ID(NetBufferList);

        if ((NetBufferListId == CancelId)
                && (NetBufferList != Adapter->SendingNetBufferList))
        {
            RemoveEntryList(thisEntry);

            NET_BUFFER_LIST_STATUS(NetBufferList) = NDIS_STATUS_REQUEST_ABORTED;

            Adapter->nWaitSend--;

            NetBuffer = MP_GET_NET_BUFFER_LIST_NEXT_SEND(NetBufferList);
            MP_GET_NET_BUFFER_LIST_NEXT_SEND(NetBufferList) = NULL;
            NetBufferList->FirstNetBuffer = NetBuffer;

            //
            // Queue this NetBufferList for cancellation
            //
            if (CancelHeadNetBufferList == NULL)
            {
                CancelHeadNetBufferList = NetBufferList;
                CancelTailNetBufferList = NetBufferList;
            }
            else
            {
                NET_BUFFER_LIST_NEXT_NBL(CancelTailNetBufferList) = NetBufferList;
                CancelTailNetBufferList = NetBufferList;
            }

        }

    }


    NdisReleaseSpinLock(&Adapter->SendLock);

    //
    // Get the packets from SendCancelQueue and complete them if any
    //
    if (CancelHeadNetBufferList != NULL)
    {
        NET_BUFFER_LIST_NEXT_NBL(CancelTailNetBufferList) = NULL;

        NdisMSendNetBufferListsComplete(
               Adapter->AdapterHandle,
               CancelHeadNetBufferList,
               0);
    }

    DEBUGP(MP_TRACE, ("<--- MPCancelSendNetBufferLists\n"));
    return;

}





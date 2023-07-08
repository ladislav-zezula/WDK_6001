/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

Module Name:

    RECV.C

Abstract:

    This module contains miniport functions for posting read requests
    to the underly minport driver and indicating the completed request
    buffers to NDIS.

--*/


#include "ndiswdm.h"

VOID
NICIndicateReceivedPacket(
    IN PRCB             pRCB,
    IN ULONG            BytesToIndicate
    )
/*++

Routine Description:

    This function is called by the NICReadRequestCompletion when a read
    request posted to the underlying stack completes.

    An NDIS 6.0 miniport driver calls NdisMIndicateNetBufferLists
    to indicate a linked list of NET_BUFFER_LIST structures.

    Miniport drivers can indicate a linked list of NET_BUFFER_LIST
    structures to NDIS instead of NDIS_PACKET structures.
    NDIS forwards the NET_BUFFER_LIST structures to the appropriate bound
    protocol drivers.

    If the miniport driver specifies NDIS_RECEIVE_FLAGS_RESOURCES
    in its ReceiveFlags parameter, it can reclaim ownership of the
    NET_BUFFER_LIST structures as soon as NdisMIndicateNetBufferLists
    returns. Otherwise, NDIS returns ownership of the NET_BUFFER_LIST
    structure by calling the miniport driver's MiniportReturnNetBufferLists
    function. MiniportReturnNetBufferLists can be called at
    IRQL <= DISPATCH_LEVEL. The IRQL level is specified in the
    ReturnFlags parameter.

Arguments:

    pRCB - pointer to the RCB block
    BytesToIndicate - number of bytes to indicate

Return value:

    VOID
--*/
{
    PETH_HEADER     pEthHeader = NULL;
    PMP_ADAPTER     Adapter = pRCB->Adapter;
    PNET_BUFFER     NetBuffer;
    ULONG           BytesAvailable;

    if (Adapter->AdapterState != NicRunning) {
        DEBUGP(MP_INFO,
            ("Adapter is pausing so don't indicate the request to NDIS\n"));
        return;
    }
    NetBuffer = NET_BUFFER_LIST_FIRST_NB(pRCB->NetBufferList);

    //
    // During the call NdisAllocateNetBufferAndNetBufferList to
    // allocate the NET_BUFFER_LIST, NDIS already
    // initializes DataOffset, CurrentMdl and CurrentMdlOffset.
    // We just need to update DataLength
    // in the NET_BUFFER to reflect the received frame size.
    //
    NET_BUFFER_DATA_LENGTH(NetBuffer) = BytesToIndicate;

    NdisAdjustMdlLength(pRCB->Mdl, BytesToIndicate);

    MP_SET_RCB_IN_NBL(pRCB->NetBufferList, pRCB);

    //
    // Update the statistics
    //
    MP_RECEIVE_STATS(Adapter, NetBuffer);

    NdisQueryMdl(pRCB->Mdl, (PVOID)&pEthHeader, &BytesAvailable, NormalPagePriority);

    if (pEthHeader &&
        Adapter->PacketFilter &&
        NICIsPacketAcceptable(Adapter, pEthHeader->DstAddr)){

        DEBUGP(MP_LOUD, ("Src Address = %02x-%02x-%02x-%02x-%02x-%02x  ",
            pEthHeader->SrcAddr[0],
            pEthHeader->SrcAddr[1],
            pEthHeader->SrcAddr[2],
            pEthHeader->SrcAddr[3],
            pEthHeader->SrcAddr[4],
            pEthHeader->SrcAddr[5]));

        DEBUGP(MP_LOUD, ("  Dest Address = %02x-%02x-%02x-%02x-%02x-%02x\n",
            pEthHeader->DstAddr[0],
            pEthHeader->DstAddr[1],
            pEthHeader->DstAddr[2],
            pEthHeader->DstAddr[3],
            pEthHeader->DstAddr[4],
            pEthHeader->DstAddr[5]));

        DEBUGP(MP_INFO, ("Indicating NetBufferList = %p, Packet Length = %d\n",
                            pRCB->NetBufferList, BytesToIndicate));

        NdisInterlockedIncrement(&pRCB->Ref);

        NdisInterlockedIncrement(&Adapter->nIndicatedNetBufferList);

        NdisMIndicateReceiveNetBufferLists(Adapter->AdapterHandle,
                        pRCB->NetBufferList,
                        NDIS_DEFAULT_PORT_NUMBER,
                        1,
                        NDIS_RECEIVE_FLAGS_SINGLE_ETHER_TYPE );

    }else {
        DEBUGP(MP_INFO,
            ("Invalid packet or filter is not set packet = %p,Packet Length = %d\n",
            pRCB->NetBufferList, BytesToIndicate));
    }

}


VOID
MPReturnNetBufferLists(
    IN  NDIS_HANDLE         MiniportAdapterContext,
    IN  PNET_BUFFER_LIST    NetBufferLists,
    IN  ULONG               ReturnFlags
    )
/*++

Routine Description:

    MiniportReturnNetBufferLists handler
    NDIS calls this handler to return the ownership of one or more
    NetBufferLists and their embedded NetBuffers to the miniport driver.

Arguments:

    MiniportAdapterContext  Pointer to our adapter
    NetBufferLists          A linked list of NetBufferLists that miniport driver
                            allocated for one or more previous receive
                            indications. The list can include NetBuferLists
                            from different previous calls to
                            NdisMIndicateNetBufferLists.
    ReturnFlags             Flags specifying if the caller is at DISPATCH level

Return Value:

    None


--*/
{
    PRCB         pRCB = NULL;
    PMP_ADAPTER  Adapter;
    BOOLEAN      atDispatchLevel;

    UNREFERENCED_PARAMETER(MiniportAdapterContext);

    DEBUGP(MP_TRACE, ("---> MPReturnNetBufferLists\n"));

    atDispatchLevel = (BOOLEAN)NDIS_TEST_RETURN_AT_DISPATCH_LEVEL(ReturnFlags);

    pRCB = MP_GET_RCB_FROM_NBL(NetBufferLists);

    ASSERT(NET_BUFFER_LIST_NEXT_NBL(NetBufferLists) == NULL);

    Adapter = pRCB->Adapter;

    ASSERT(Adapter);

    NdisInterlockedDecrement(&Adapter->nIndicatedNetBufferList);

    if (NdisInterlockedDecrement(&pRCB->Ref) == 0)
    {
        NICFreeRCB(pRCB, atDispatchLevel);
    }

    DEBUGP(MP_TRACE, ("<--- MPReturnNetBufferLists\n"));
}

VOID
NICPostReadsWorkItemCallBack(
    WDFWORKITEM  WorkItem
    )
/*++

Routine Description:

   Workitem to post all the free read requests to the target
   driver. This workitme is scheduled from the MiniportInitialize
   worker routine during start and also from the NICFreeRCB whenever
   the outstanding read requests to the target driver goes below
   the NIC_SEND_LOW_WATERMARK.

Arguments:

    WorkItem - Pointer to workitem

    Dummy - Unused

Return Value:

    None.

--*/
{
    PMP_ADAPTER     Adapter;
    NTSTATUS        ntStatus;
    PRCB            pRCB=NULL;

    DEBUGP(MP_TRACE, ("--->NICPostReadsWorkItemCallBack\n"));

    Adapter = GetWdfDeviceInfo(WdfWorkItemGetParentObject(WorkItem))->Adapter;

    NdisAcquireSpinLock(&Adapter->RecvLock);

    while (MP_IS_READY(Adapter) && !IsListEmpty(&Adapter->RecvFreeList))
    {
        pRCB = (PRCB) RemoveHeadList(&Adapter->RecvFreeList);

        ASSERT(pRCB);// cannot be NULL

        //
        // Insert the RCB in the recv busy queue
        //
        NdisInterlockedIncrement(&Adapter->nBusyRecv);
        ASSERT(Adapter->nBusyRecv <= NIC_MAX_BUSY_RECVS);

        InsertTailList(&Adapter->RecvBusyList, &pRCB->List);

        NdisReleaseSpinLock(&Adapter->RecvLock);

        Adapter->nReadsPosted++;

        ntStatus = NICPostReadRequest(Adapter, pRCB);

        NdisAcquireSpinLock(&Adapter->RecvLock);

        if (!NT_SUCCESS ( ntStatus ) ) {
            ASSERT(FALSE);
            DEBUGP (MP_ERROR, ( "NICPostReadRequest failed %x\n", ntStatus ));
            break;
        }

    }

    NdisReleaseSpinLock(&Adapter->RecvLock);

    //
    // Clear the flag to let the WorkItem structure be reused for
    // scheduling another one.
    //
    InterlockedExchange(&Adapter->IsReadWorkItemQueued, FALSE);

    DEBUGP(MP_TRACE, ("<---NICPostReadsWorkItemCallBack\n"));
}

NTSTATUS
NICPostReadRequest(
    PMP_ADAPTER Adapter,
    PRCB    pRCB
    )
/*++

Routine Description:

    This routine sends a read Request to the target device to get
    the incoming network packet from the device.

Arguments:

    Adapter    - pointer to the MP_ADAPTER structure
    pRCB    -  Pointer to the RCB block that contains the Request.


Return Value:

    NT status code

--*/
{
    NTSTATUS        status = STATUS_SUCCESS;
    PIRP            irp = NULL;
    PIO_STACK_LOCATION  nextStack;

    DEBUGP(MP_LOUD, ("--> NICPostReadRequest\n"));

    status = WdfIoTargetFormatRequestForRead(
                    Adapter->IoTarget,
                    pRCB->Request,
                    NULL, // InputBuffer
                    NULL, // InputBufferOffsets
                    NULL); // StartingOffset
    if (!NT_SUCCESS(status)) {
        return status;
    }

    irp = WdfRequestWdmGetIrp(pRCB->Request);
    //
    // Obtain a pointer to the stack location of the first driver that will be
    // invoked.  This is where the function codes and the parameters are set.
    //
    nextStack = IoGetNextIrpStackLocation( irp );
    irp->MdlAddress = pRCB->Mdl;
    nextStack->Parameters.Read.Length = NIC_BUFFER_SIZE;

    ASSERT(pRCB->Ref == 0);
    pRCB->Ref = 1;

    WdfRequestSetCompletionRoutine(pRCB->Request,
                               NICReadRequestCompletion,
                               pRCB);

    //
    // We are making an asynchronous request, so we don't really care
    // about the return status of IoCallDriver.
    //
    if (WdfRequestSend(pRCB->Request, Adapter->IoTarget, WDF_NO_SEND_OPTIONS) == FALSE) {
        ASSERT(FALSE);
        status = WdfRequestGetStatus(pRCB->Request);
    }

    DEBUGP(MP_LOUD, ("<-- NICPostReadRequest\n"));

    return status;
}

VOID
NICReadRequestCompletion(
    IN WDFREQUEST                  Request,
    IN WDFIOTARGET                 Target,
    PWDF_REQUEST_COMPLETION_PARAMS CompletionParams,
    IN WDFCONTEXT                  Context
    )
/*++

Routine Description:

    Completion routine for the read request. This routine
    indicates the received packet from the WDM driver to
    NDIS. This routine also handles the case where another
    thread has canceled the read request.

Arguments:

    DeviceObject    -  not used. Should be NULL
    Request    -   Pointer to our read Request
    Context - pointer to our adapter context structure

Return Value:


--*/
{
    PRCB         pRCB = (PRCB)Context;
    PMP_ADAPTER  Adapter = pRCB->Adapter;
    ULONG        bytesRead = 0;
    BOOLEAN      bIndicateReceive = FALSE;
    NTSTATUS     status;

    UNREFERENCED_PARAMETER(Target);
    UNREFERENCED_PARAMETER(Request);

    DEBUGP(MP_TRACE, ("--> NICReadRequestCompletion\n"));

    status = CompletionParams->IoStatus.Status;


    if (!NT_SUCCESS(status)) {

        if (status != STATUS_CANCELLED) {
            DEBUGP (MP_ERROR, ("Read request failed %x\n", status));
        }
        Adapter->nReadsCompletedWithError++;
        //
        // Clear the flag to prevent any more reads from being
        // posted to the target device.
        //
        MP_CLEAR_FLAG(Adapter, fMP_POST_READS);

    } else {

        Adapter->GoodReceives++;
        bytesRead = (ULONG)CompletionParams->IoStatus.Information;
        DEBUGP (MP_VERY_LOUD, ("Read %d bytes\n", bytesRead));
        Adapter->nBytesRead += bytesRead;
        bIndicateReceive = TRUE;
    }

    if (bIndicateReceive) {
        NICIndicateReceivedPacket(pRCB, bytesRead);
    }

    if (NdisInterlockedDecrement(&pRCB->Ref) == 0)
    {
        NICFreeRCB(pRCB, FALSE);
    }

    return;
}

VOID
NICFreeRCB(
    IN PRCB pRCB,
    IN BOOLEAN AtDispatchLevel
    )
/*++

Routine Description:

    pRCB      - pointer to RCB block

Arguments:

    This routine reinitializes the RCB block and puts it back
    into the RecvFreeList for reuse.


Return Value:

    VOID

--*/
{
    PMP_ADAPTER                 Adapter = pRCB->Adapter;
    WDF_REQUEST_REUSE_PARAMS    params;
    PIRP                        irp;
    PIO_STACK_LOCATION          nextStack;
    NTSTATUS                    status;
    BOOLEAN                     completePause = FALSE;

    DEBUGP(MP_TRACE, ("--> NICFreeRCB %p\n", pRCB));

    ASSERT(pRCB->Mdl->Next == NULL);
    ASSERT(pRCB->Request != NULL);
    ASSERT(pRCB->Ref == 0);
    ASSERT(pRCB->Adapter != NULL);

    WDF_REQUEST_REUSE_PARAMS_INIT(&params, WDF_REQUEST_REUSE_NO_FLAGS, STATUS_SUCCESS);

    status = WdfRequestReuse(pRCB->Request, &params);
    if (!NT_SUCCESS(status)){
        DEBUGP(MP_ERROR, ("WdfRequestReuse failed 0x%x\n", status));
        ASSERT(FALSE);
        return;
    }

    //
    // Set the MDL field to NULL so that we don't end up free the
    // MDL in our call to Free Request.
    //
    irp = WdfRequestWdmGetIrp(pRCB->Request);
    nextStack = IoGetNextIrpStackLocation( irp );
    irp->MdlAddress = NULL;

    //
    // Re adjust the length to the originl size
    //
    NdisAdjustMdlLength(pRCB->Mdl, NIC_BUFFER_SIZE);

    //
    // Insert the RCB back in the Recv free list
    //
    MP_ACQUIRE_SPIN_LOCK(&Adapter->RecvLock, AtDispatchLevel);

    RemoveEntryList(&pRCB->List);

    InsertTailList(&Adapter->RecvFreeList, &pRCB->List);

    NdisInterlockedDecrement(&Adapter->nBusyRecv);
    ASSERT(Adapter->nBusyRecv >= 0);

    if (Adapter->nIndicatedNetBufferList == 0 &&
        (Adapter->AdapterState == NicPausing))
    {
        //
        // If all the NetBufferLists are returned and miniport is pausing,
        // complete the pause
        //
        Adapter->AdapterState = NicPaused;
        completePause = TRUE;
    }

    MP_RELEASE_SPIN_LOCK(&Adapter->RecvLock, AtDispatchLevel);

    if (completePause) {
        DEBUGP(MP_TRACE, ("Completed Pause\n"));
        NdisMPauseComplete(Adapter->AdapterHandle);
    }

    //
    // For performance, instead of scheduling a workitem at the end of
    // every read completion, we will do it only when the number of
    // outstanding Requests goes below NIC_SEND_LOW_WATERMARK.
    // We shouldn't queue a workitem if it's already scheduled and waiting in
    // the system workitem queue to be fired.
    //
    if ((!NIC_SEND_LOW_WATERMARK || Adapter->nBusyRecv <= NIC_SEND_LOW_WATERMARK)
            && MP_TEST_FLAG(Adapter, fMP_POST_READS) &&
#pragma warning(disable:4127)
            (InterlockedExchange(&Adapter->IsReadWorkItemQueued, TRUE) == FALSE) )
#pragma warning(default:4127)
    {
        Adapter->nReadWorkItemScheduled++;
        WdfWorkItemEnqueue(Adapter->ReadWorkItem);
    }

    DEBUGP(MP_TRACE, ("<-- NICFreeRCB %d\n", Adapter->nBusyRecv));
}


BOOLEAN
NICIsPacketAcceptable(
    IN PMP_ADAPTER Adapter,
    IN PUCHAR   pDstMac
    )
/*++

Routine Description:

    Check if the destination address of a received packet
    matches the receive criteria of our adapter.

Arguments:

    Adapter    - pointer to the adapter structure
    pDstMac - Destination MAC address to compare


Return Value:

    True or False

--*/
{
    UINT            AddrCompareResult;
    ULONG           PacketFilter;
    BOOLEAN         bPacketMatch;
    BOOLEAN         bIsMulticast, bIsBroadcast;

    PacketFilter = Adapter->PacketFilter;

    bIsMulticast = ETH_IS_MULTICAST(pDstMac);
    bIsBroadcast = ETH_IS_BROADCAST(pDstMac);

    //
    // Handle the directed packet case first.
    //
    if (!bIsMulticast)
    {
        //
        // If the Adapter is not in promisc. mode, check if
        // the destination MAC address matches the local
        // address.
        //
        if ((PacketFilter & NDIS_PACKET_TYPE_PROMISCUOUS) == 0)
        {
            ETH_COMPARE_NETWORK_ADDRESSES_EQ(Adapter->CurrentAddress,
                                             pDstMac,
                                             &AddrCompareResult);

            bPacketMatch = (BOOLEAN)
                ((AddrCompareResult == 0) &&
                 ((PacketFilter & NDIS_PACKET_TYPE_DIRECTED) != 0));
        }
        else
        {
            bPacketMatch = TRUE;
        }
     }
     else
     {
        //
        // Multicast or broadcast packet.
        //

        //
        // Indicate if the filter is set to promisc mode ...
        //
        if ((PacketFilter & NDIS_PACKET_TYPE_PROMISCUOUS)
                ||

            //
            // or if this is a broadcast packet and the filter
            // is set to receive all broadcast packets...
            //
            (bIsBroadcast &&
             (PacketFilter & NDIS_PACKET_TYPE_BROADCAST))
                ||

            //
            // or if this is a multicast packet, and the filter is
            // either set to receive all multicast packets, or
            // set to receive specific multicast packets. In the
            // latter case, indicate receive only if the destn
            // MAC address is present in the list of multicast
            // addresses set on the Adapter.
            //
            (!bIsBroadcast &&
             ((PacketFilter & NDIS_PACKET_TYPE_ALL_MULTICAST) ||
              ((PacketFilter & NDIS_PACKET_TYPE_MULTICAST) &&
               NICIsMulticastMatch(Adapter, pDstMac))))
           )
        {
            bPacketMatch = TRUE;
        }
        else
        {
            //
            // No protocols above are interested in this
            // multicast/broadcast packet.
            //
            bPacketMatch = FALSE;
        }
    }

    return (bPacketMatch);
}

BOOLEAN
NICIsMulticastMatch(
    IN PMP_ADAPTER  Adapter,
    IN PUCHAR       pDstMac
    )
/*++

Routine Description:

    Check if the given multicast destination MAC address matches
    any of the multicast address entries set on the Adapter.

    NOTE: the caller is assumed to hold a READ/WRITE lock
    to the parent ADAPT structure. This is so that the multicast
    list on the Adapter is invariant for the duration of this call.

Arguments:

    Adapter  - Adapter to look in
    pDstMac - Destination MAC address to compare

Return Value:

    TRUE iff the address matches an entry in the Adapter

--*/
{
    ULONG           i;
    UINT            AddrCompareResult;

    for (i = 0; i < Adapter->ulMCListSize; i++)
    {
        ETH_COMPARE_NETWORK_ADDRESSES_EQ(Adapter->MCList[i],
                                         pDstMac,
                                         &AddrCompareResult);

        if (AddrCompareResult == 0)
        {
            break;
        }
    }

    return (BOOLEAN) (i != Adapter->ulMCListSize);
}


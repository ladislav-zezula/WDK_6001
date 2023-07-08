/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    mp_evnts.c

Abstract:
    Hooking functions for modifying MP Layer functionality
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created
    01-15-2006    Renamed Mp_Events.c to mp_evnts.c
    
Notes:

--*/

///////////////////////////////////////////////////////////////////
//
// This file contains all interfaces that vendor needs
// to add to the miniport. This file among all others is
// least likely to change from one revision of the sample
// to the next. By localising all MP portion changes to
// this file, vendor can add code, value adds and handle
// hardware specific issues with little or no changes to
// other Mp portion files. Syncing with the next revision
// of the driver (to get bug fixes and/or new features will,
// hopefully, be a much easier process.
//
//////////////////////////////////////////////////////////////////


#include "Precomp.h"

#include "Mp_Evnts.h"
#if DOT11_TRACE_ENABLED
#include "Mp_Evnts.tmh"
#endif



/*
 * Allocate any resources required by CustomInterfaces.
 * All initializations go here as well.
 * 
 * \param pAdapter  The adapter context for this miniport
 * \return NDIS_STATUS_SUCCESS if all goes well, else the
 * appropriate failure
 * \sa MpEventTerminate
 */ 
NDIS_STATUS
MpEventInitialize(
    IN  PADAPTER    pAdapter
    )
{
    UNREFERENCED_PARAMETER(pAdapter);    
    return NDIS_STATUS_SUCCESS;
}


/*
 * Free all resources allocated by CustomInterfaces
 * 
 * \param pAdapter  The adapter context for this miniport
 * \sa MpEventInitialize
 */
VOID
MpEventTerminate(
    IN  PADAPTER    pAdapter
    )
{
    UNREFERENCED_PARAMETER(pAdapter);
}


/**
 * Handle and private OIDs or intercept other RequestQuery in this function.
 * This way, OID handling changes are localised to this file.
 * 
 * \return The appropriate NDIS_STATUS error code.
 * \sa Please refer to MiniportRequest function in the DDK for
 * full description of this function and its handling.
 */
NDIS_STATUS
MpEventQueryInformation(
    IN    PADAPTER                  pAdapter,
    IN    NDIS_OID                  Oid,
    IN    PVOID                     InformationBuffer,
    IN    ULONG                     InformationBufferLength,
    OUT   PULONG                    BytesWritten,
    OUT   PULONG                    BytesNeeded
    )
{
    NDIS_STATUS                 ndisStatus = NDIS_STATUS_SUCCESS;
    ULONG                       uInfo = 0, uInfoLen = 0;
    PVOID                       pInfo = (PVOID)&uInfo;
    
    UNREFERENCED_PARAMETER(pAdapter);
    UNREFERENCED_PARAMETER(InformationBuffer);
    UNREFERENCED_PARAMETER(InformationBufferLength);
    UNREFERENCED_PARAMETER(BytesWritten);
    UNREFERENCED_PARAMETER(BytesNeeded);

    switch(Oid)
    {
        default:
            ndisStatus = NDIS_STATUS_INVALID_OID;
            break;
    }

    if (ndisStatus == NDIS_STATUS_SUCCESS)
    {
        if (uInfoLen <= InformationBufferLength)
        {
            if(uInfoLen)
            {
                // Copy result into InformationBuffer
                *BytesWritten = uInfoLen;
                NdisMoveMemory(InformationBuffer, pInfo, uInfoLen);
            }
            else 
            {
                //
                // the result is either zero length of has been copied
                // by the OID specific handler
                //
                // Dont overwrite the BytesWritten and BytesNeeded
                // as they are also appropriately set
                //
            }
        }
        else
        {
            //
            // The buffer length is not sufficient
            //
            *BytesNeeded = uInfoLen;
            ndisStatus = NDIS_STATUS_INVALID_LENGTH;
        }
    }

    return ndisStatus;
}


/**
 * Handle and private OIDs or intercept other RequestSet in this function.
 * This way, OID handling changes are localised to this file.
 * 
 * \return The appropriate NDIS_STATUS error code.
 * \sa Please refer to MiniportRequest function in the DDK for
 * full description of this function and its handling.
 */
NDIS_STATUS
MpEventSetInformation(
    IN    PADAPTER                  pAdapter,
    IN    NDIS_OID                  Oid,
    IN    PVOID                     InformationBuffer,
    IN    ULONG                     InformationBufferLength,
    OUT   PULONG                    BytesRead,
    OUT   PULONG                    BytesNeeded
    )
{
    NDIS_STATUS         ndisStatus = NDIS_STATUS_SUCCESS;

    UNREFERENCED_PARAMETER(pAdapter);
    UNREFERENCED_PARAMETER(InformationBuffer);
    UNREFERENCED_PARAMETER(InformationBufferLength);
    UNREFERENCED_PARAMETER(BytesRead);
    UNREFERENCED_PARAMETER(BytesNeeded);

    switch(Oid)
    {
        default:
            ndisStatus = NDIS_STATUS_INVALID_OID;
            break;
    }
    
    return ndisStatus;
}


/**
 * Handle and private OIDs or intercept other RequestMethods in this function.
 * This way, OID handling changes are localised to this file.
 * 
 * \return The appropriate NDIS_STATUS error code.
 * \sa Please refer to MiniportRequest function in the DDK for
 * full description of this function and its handling.
 */
NDIS_STATUS
MpEventQuerySetInformation(
    IN    PADAPTER                  pAdapter,
    IN    NDIS_OID                  Oid,
    IN    PVOID                     InformationBuffer,
    IN    ULONG                     InputBufferLength,
    IN    ULONG                     OutputBufferLength,
    IN    ULONG                     MethodId,
    OUT   PULONG                    BytesWritten,
    OUT   PULONG                    BytesRead,
    OUT   PULONG                    BytesNeeded
    )
{
    NDIS_STATUS         ndisStatus = NDIS_STATUS_SUCCESS;

    UNREFERENCED_PARAMETER(pAdapter);
    UNREFERENCED_PARAMETER(InformationBuffer);
    UNREFERENCED_PARAMETER(InputBufferLength);
    UNREFERENCED_PARAMETER(OutputBufferLength);
    UNREFERENCED_PARAMETER(MethodId);
    UNREFERENCED_PARAMETER(BytesWritten);
    UNREFERENCED_PARAMETER(BytesRead);
    UNREFERENCED_PARAMETER(BytesNeeded);

    switch(Oid)
    {
        default:
            ndisStatus = NDIS_STATUS_INVALID_OID;
            break;
    }

    return ndisStatus;    
}


/**
 * This function is called every time MiniportCheckForHang is
 * called. Return TRUE if the miniport needs to be reset.
 * 
 * \param pAdapter  The adapter context for this miniport
 * \return TRUE if miniport should be reset. Else false
 * \sa MpEventMiniportReset
 */
BOOLEAN
MpEventCheckForHang(
    IN  PADAPTER    pAdapter
    )
{
    UNREFERENCED_PARAMETER(pAdapter);
    
    //
    // Sometimes, due to timing windows, packets can get stuck in the send
    // queue since hardware thinks the queue is empty when it is not. Just
    // request a HwPoll to handle such issues.
    //
    if (pAdapter->PendingSends > 0)
    {
        Hw11CheckForSends(pAdapter->pNic);
    }
    
    return FALSE;
}


/**
 * When a Dot11 Reset is issued (OID_DOT11_RESET_REQUEST), before the reset
 * of miniport and hardware begins, this function is called. If there is
 * any state that requires to be reset, should be done here. Please note that
 * MpEventMiniportReset will -also- be called so only Dot11 Reset specific work
 * be placed here. All reinitializations that always take place during a reset
 * can be placed in MpEventMiniportReset.
 * 
 * \param pAdapter      The miniport Adapter context
 * \param ResetType     The type of reset this miniport is undergoing.
 * \sa MpEventMiniportReset, OID_DOT11_RESET_REQUEST
 */
VOID
MpEventDot11Reset(
    IN  PADAPTER            pAdapter,
    IN  DOT11_RESET_TYPE    ResetType
    )
{
    UNREFERENCED_PARAMETER(pAdapter);
    UNREFERENCED_PARAMETER(ResetType);
}


/**
 * This function is called when miniport is being reset.
 * Interrupts are disabled on the device and send/receive
 * units have been stopped.
 * 
 * \param pAdapter  The adapter context for this miniport 
 * \sa MpEventCheckForHang, MpEventDot11Reset
 */
VOID
MpEventMiniportReset(
    IN  PADAPTER    pAdapter
    )
{
    UNREFERENCED_PARAMETER(pAdapter);
}


/**
 * This function is called when a packet to be sent is submitted to
 * the miniport driver. This function can perform a number of operations
 * on the packet being sent. Please be careful about major operations
 * like subsuming packets etc. as they may affect the operation of the
 * rest of the miniport driver.
 * 
 * \param pAdapter                  The Adapter context for this miniport
 * \param NetBufferList             The BetBufferList submitted to the driver
 * \param pDot11SendContext         The send context for this packet
 * \param SendContextSize           Size of send context Info
 * \return NDIS_STATUS_SUCCESS if this packet has been subsumed by this function.
 * Responsibility for sending and send completing this packet is on this function.
 * NDIS_STATUS_NOT_RECOGNIZED be returned if this packet is to process normally.
 * Any other status will be treated as failure and packet failed back to the OS.
 * \sa MPSendNetBufferLists, MpEventPacketReceived
 */
NDIS_STATUS
MpEventSendNetBufferList(
    IN  PADAPTER                        pAdapter,
    IN  PNET_BUFFER_LIST                NetBufferList,
    IN  ULONG                           SendFlags,
    IN  PDOT11_EXTSTA_SEND_CONTEXT      pDot11SendContext,
    IN  BOOLEAN                         DispatchLevel
    )
{
    UNREFERENCED_PARAMETER(pAdapter);
    UNREFERENCED_PARAMETER(SendFlags);
    UNREFERENCED_PARAMETER(NetBufferList);
    UNREFERENCED_PARAMETER(pDot11SendContext);
    UNREFERENCED_PARAMETER(DispatchLevel);

    // Currently for extensible model, we dont do anything
    return NDIS_STATUS_NOT_RECOGNIZED;
}


BOOL
MpEventShouldBufferPacket(
    IN  PADAPTER                        pAdapter,
    IN  PDOT11_EXTSTA_SEND_CONTEXT      pDot11SendContext
    )
{
    BOOL    bufferPacket = FALSE;

    UNREFERENCED_PARAMETER(pAdapter);
    UNREFERENCED_PARAMETER(pDot11SendContext);
    
    // add this packet to PS broadcast queue if
    // 1. DOT11_FLAGS_PS_ON is set (by soft ap) in send context.
    // 2. DOT11_FLAGS_PS_ON is clear but PS broadcast queue is not empty.
    //    This is to prevent packets recieved out of order on receive side. A STA
    //    in PS mode can choose to send out a NULL packet with power save off when
    //    it wakes up to receive broadcast data from AP. This causes problem because 
    //    AP will not set DOT11_FLAGS_PS_ON for subsequent outgoing packets and 
    //    these packets will be sent immediately instead of queued up, and STA 
    //    receives packets out of order as a result.

    return bufferPacket;
}
    
/*
 * This function is called to notify when a send complete has occured and
 * is about to relayed to NDIS. Please note that this function is only called
 * for Tx MSDU that were actually handed to the hardware. Packets failed because
 * of issues that prevented us from ever handing the packet to the hardware
 * may not be provided to this API.
 *
 * \param   pAdapter        Adapter context
 * \param   pTxd            The Tx MSDU completing
 * \param   ndisStatus      Completion status for this packet
 */
VOID
MpEventSendComplete(
    IN  PADAPTER        pAdapter,
    IN  PMP_TX_MSDU     pTxd,
    IN  NDIS_STATUS     ndisStatus,
    IN  BOOLEAN         DispatchLevel
    )
{
    UNREFERENCED_PARAMETER(pAdapter);
    UNREFERENCED_PARAMETER(pTxd);
    UNREFERENCED_PARAMETER(ndisStatus);
    UNREFERENCED_PARAMETER(DispatchLevel);    
}


/**
 * This function is invoked when the miniport receives a 
 * packet from the underlying hardware. This packet has been
 * checked for correct CRC, but not filtered compeletly. 
 * The default takes no action.
 * 
 * \param pAdapter      The adapter context for this miniport
 * \param pMpFragment   The MP_RX_FRAGMENT for this MPDU
 * \param pNicFragment  The NIC_RX_FRAGMENT for this MPDU
 * \param pFragmentHdr  Buffer pointing to the header of this MPDU
 * \param uFragmentSize The size of this fragment in bytes
 * \return return NDIS_STATUS_SUCCESS if the packet has been
 * processed successfully. Any failure code will cause this
 * fragment to be dropped.
 * \sa MpEventSendPacket
 */
NDIS_STATUS
MpEventPacketReceived(
    IN  PADAPTER                        pAdapter,
    IN  PMP_RX_FRAGMENT                 pMpFragment,
    IN  PNIC_RX_FRAGMENT                pNicFragment,
    IN  PDOT11_MAC_HEADER               pFragmentHdr,
    IN  USHORT                          uFragmentSize
    )
{
    UNREFERENCED_PARAMETER(pAdapter);
    UNREFERENCED_PARAMETER(pMpFragment);
    UNREFERENCED_PARAMETER(pNicFragment);
    UNREFERENCED_PARAMETER(pFragmentHdr);
    UNREFERENCED_PARAMETER(uFragmentSize);
    
    return NDIS_STATUS_SUCCESS;
}

VOID
MpEventHandleInterrupt(
    IN  PADAPTER        pAdapter
    )
{    
    UNREFERENCED_PARAMETER(pAdapter);
}


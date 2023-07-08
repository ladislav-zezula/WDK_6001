/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    Mp_Evnts.h

Abstract:
    Prototypes for MP layer hooking functions
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created
    01-15-2006    Renamed mp_events.h to mp_evnts.h

Notes:

--*/
#ifndef _MP_CUSTOM_INTERFACES_H_

#define _MP_CUSTOM_INTERFACES_H_


#define OID_RTL_SAMPLE_OID       0xDEEF1201
#define OID_RTL_SAMPLE2_OID      0xDEEF1202


/*
 * Any OIDs that are private to this this miniport should be added to the
 * macro below. At compile time this macro will aggregate these OIDs into
 * the supported OID list and automatically report them to the OS.
 *
 * If there is at least one OID in the list, please remember to include the
 * comma after the last OID. You will see compiler errors otherwise
 */
#define MP_PRIVATE_OID_LIST         \
    OID_RTL_SAMPLE_OID,               \
    OID_RTL_SAMPLE2_OID,


NDIS_STATUS
MpEventInitialize(
    IN  PADAPTER    pAdapter
    );


VOID
MpEventTerminate(
    IN  PADAPTER    pAdapter
    );


NDIS_STATUS
MpEventQueryInformation(
    IN    PADAPTER                  pAdapter,
    IN    NDIS_OID                  Oid,
    IN    PVOID                     InformationBuffer,
    IN    ULONG                     InformationBufferLength,
    OUT   PULONG                    BytesWritten,
    OUT   PULONG                    BytesNeeded
    );


NDIS_STATUS
MpEventSetInformation(
    IN    PADAPTER                  pAdapter,
    IN    NDIS_OID                  Oid,
    IN    PVOID                     InformationBuffer,
    IN    ULONG                     InformationBufferLength,
    OUT   PULONG                    BytesRead,
    OUT   PULONG                    BytesNeeded
    );

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
    );

BOOLEAN
MpEventCheckForHang(
    IN  PADAPTER    pAdapter
    );


VOID
MpEventDot11Reset(
    IN  PADAPTER            pAdapter,
    IN  DOT11_RESET_TYPE    ResetType
    );


VOID
MpEventMiniportReset(
    IN  PADAPTER    pAdapter
    );


NDIS_STATUS
MpEventSendNetBufferList(
    IN  PADAPTER                        pAdapter,
    IN  PNET_BUFFER_LIST                NetBufferList,
    IN  ULONG                           SendFlags,
    IN  PDOT11_EXTSTA_SEND_CONTEXT      pDot11SendContext,
    IN  BOOLEAN                         DispatchLevel
    );

BOOL
MpEventShouldBufferPacket(
    IN  PADAPTER                        pAdapter,
    IN  PDOT11_EXTSTA_SEND_CONTEXT      pDot11SendContext
    );

VOID
MpEventSendComplete(
    IN  PADAPTER        pAdapter,
    IN  PMP_TX_MSDU     pTxd,
    IN  NDIS_STATUS     ndisStatus,
    IN  BOOLEAN         DispatchLevel
    );


NDIS_STATUS
MpEventPacketReceived(
    IN  PADAPTER                        pAdapter,
    IN  PMP_RX_FRAGMENT                 pMpFragment,
    IN  PNIC_RX_FRAGMENT                pNicFragment,
    IN  PDOT11_MAC_HEADER               pFragmentHdr,
    IN  USHORT                          uFragmentSize
    );

VOID
MpEventHandleInterrupt(
    IN  PADAPTER        pAdapter
    );

#endif  // _MP_CUSTOM_INTERFACES_H_


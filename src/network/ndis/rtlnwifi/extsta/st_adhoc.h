/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    st_adhoc.h

Abstract:
    STA layer adhoc functions
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created
    01-15-2006    Renamed sta_adhoc.h to st_adhoc.h

Notes:

--*/
#ifndef _STATION_ADHOC_H
#define _STATION_ADHOC_H

#define STA11_ADHOC_JOIN_TIMEOUT                2000            /* 2 seconds */
#define STA_ADHOC_MIN_UNREACHABLE_THRESHOLD     5000            /* 5 seconds */
#define STA_ADHOC_MAX_UNREACHABLE_THRESHOLD     30000           /* 30 seconds */
#define STA_DEAUTH_WAITING_THRESHOLD            3               /* 3 ticks, or 6 seconds */
#define STA_PROBE_REQUEST_LIMIT                 2               /* 2 probe requests */

/**
 * Information Element to be put in beacon for FHSS phy
 */
typedef struct STA_FHSS_IE {
    USHORT dot11DwellTime;
    UCHAR dot11HopSet;
    UCHAR dot11HopPattern;
    UCHAR dot11HopIndex;
} STA_FHSS_IE, *PSTA_FHSS_IE;

/**
 * Initializes the AdHoc station info
 * 
 * \param pStation  station pointer
 */
NDIS_STATUS
StaInitializeAdHocStaInfo(
    IN  PSTATION        pStation
    );

/**
 * Free the AdHoc station info
 * 
 * \param pStation  station pointer
 */
VOID
StaFreeAdHocStaInfo(
    IN  PSTATION        pStation
    );

NDIS_STATUS 
StaSaveAdHocStaInfo(
    IN  PSTATION        pStation,
    IN  PNIC_RX_FRAGMENT    pNicFragment,
    IN  PDOT11_BEACON_FRAME pDot11BeaconFrame,
    IN  ULONG           InfoElemBlobSize
    );

NDIS_STATUS
StaResetAdHocStaInfo(
    IN  PSTATION       pStation,
    IN  BOOLEAN        flushStaList
    );

void
StaClearStaListAssocState(
    IN  PSTATION    pStation,
    IN  BOOLEAN     SendDeauth
    );

NTSTATUS
StaConnectAdHoc(
    IN  PVOID           Context,
    IN  NDIS_HANDLE     NdisIoWorkItemHandle
    );

void 
StaAdHocReceiveDirectData(
    IN  PSTATION                    pStation,
    IN  PDOT11_DATA_SHORT_HEADER    pDataHdr
    );

void 
StaAdHocIndicateAssociation(
    IN  PSTATION pStation,
    IN  PSTA_ADHOC_STA_ENTRY StaEntry
    );

NDIS_STATUS
StaFlushAdHocStaList(
    IN  PSTATION         pStation
    );

VOID
StaAdHocWatchdogTimerRoutine(
    IN  PVOID pvSystemSpecific1,
    IN  PSTATION pStation,
    IN  PVOID pvSystemSpecific2,
    IN  PVOID pvSystemSpecific3
    );

VOID
StaAdhocProcessMgmtPacket(
    IN  PSTATION                        pStation,
    IN  PDOT11_MGMT_HEADER              MgmtPacket,
    IN  ULONG                           PacketLength
    );

VOID
StaResumeAdHoc(
    IN  PSTATION                        pStation
    );

#endif


/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    st_send.c

Abstract:
    STA layer send processing functions
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created
    01-15-2006    Renamed sta_send.c to st_send.c

Notes:

--*/
#include "precomp.h"
#include "st_scan.h"

#if DOT11_TRACE_ENABLED
#include "st_send.tmh"
#endif

BOOLEAN
Sta11CanTransmit(
    IN  PSTATION        pStation
    )
{
    //
    // If we are in the middle of a scan, this send must be queued
    //
    if (STA_TEST_SCAN_FLAG(pStation, (STA_COMPLETE_PERIODIC_SCAN | STA_COMPLETE_EXTERNAL_SCAN)))
        return FALSE;

    return TRUE;
}

NDIS_STATUS
Sta11SendNetBufferList(
    IN  PSTATION        pStation,
    IN  PNET_BUFFER_LIST    pNetBufferList,
    IN  ULONG           SendFlags,
    IN  PDOT11_EXTSTA_SEND_CONTEXT  pSendContext
    )
{
    UNREFERENCED_PARAMETER(pStation);
    UNREFERENCED_PARAMETER(pNetBufferList);
    UNREFERENCED_PARAMETER(SendFlags);
    UNREFERENCED_PARAMETER(pSendContext);
    
    return NDIS_STATUS_NOT_RECOGNIZED;
}

VOID
Sta11ProcessSend(
    IN  PSTATION        pStation,
    IN  PMP_TX_MSDU     pMpTxd
    )
{
    UNREFERENCED_PARAMETER(pStation);
    UNREFERENCED_PARAMETER(pMpTxd);
}

VOID 
Sta11ProcessSendComplete(
    IN  PSTATION        pStation,
    IN  PMP_TX_MSDU     pMpTxd,
    IN  NDIS_STATUS     ndisStatus
    )
{
    UNREFERENCED_PARAMETER(pStation);
    UNREFERENCED_PARAMETER(pMpTxd);
    UNREFERENCED_PARAMETER(ndisStatus);
}


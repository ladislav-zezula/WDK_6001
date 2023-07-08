/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    Sta_Recv.h

Abstract:
    STA layer receive processing functions
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created

Notes:

--*/
#ifndef _STATION_RECEIVE_H_
#define _STATION_RECEIVE_H_

#include <packon.h>
typedef struct {
    UCHAR sh_dsap;
    UCHAR sh_ssap;
    UCHAR sh_ctl;
    UCHAR sh_protid[3];
    unsigned short  sh_etype;
} IEEE_8022_LLC_SNAP, *PIEEE_8022_LLC_SNAP;
#include <packoff.h>

/**
 * 
 * 
 * \param pStation
 * \param pMpFragment
 * \param pNicFragment
 * \param pFragmentHdr
 * \param FragmentSize
 * \return 
 * \sa 
 */
NDIS_STATUS
StaReceiveMgmtPacket(
    IN  PSTATION                        pStation,
    IN  PMP_RX_FRAGMENT                 pMpFragment,
    IN  PNIC_RX_FRAGMENT                pNicFragment,
    IN  PDOT11_MAC_HEADER               pFragmentHdr,
    IN  USHORT                          FragmentSize
    );

/**
 * 
 * 
 * \param pStation
 * \param pNicFragment
 * \param TotalLength
 * \return 
 * \sa 
 */
VOID 
StaReceiveBeacon(
    IN  PSTATION                        pStation,
    IN  PNIC_RX_FRAGMENT                pNicFragment,
    IN  ULONG                           TotalLength
    );

/**
 * 
 * 
 * \param pStation
 * \param pNicFragment
 * \param TotalLength
 * \sa 
 */
VOID 
StaReceiveAuthentication(
    IN  PSTATION                        pStation,
    IN  PNIC_RX_FRAGMENT                pNicFragment,
    IN  ULONG                           TotalLength
    );

/**
 * 
 * 
 * \param pStation
 * \param pNicFragment
 * \param TotalLength
 * \sa 
 */
VOID 
StaReceiveDeauthentication(
    IN  PSTATION                        pStation,
    IN  PNIC_RX_FRAGMENT                pNicFragment,
    IN  ULONG                           TotalLength
    );

/**
 * 
 * 
 * \param pStation
 * \param pNicFragment
 * \param TotalLength
 * \return 
 * \sa 
 */
VOID 
StaReceiveAssociationResponse(
    IN  PSTATION                        pStation,
    IN  PNIC_RX_FRAGMENT                pNicFragment,
    IN  ULONG                           TotalLength
    );


/**
 * 
 * 
 * \param pStation
 * \param pNicFragment
 * \param TotalLength
 * \return 
 * \sa 
 */
VOID 
StaReceiveDisassociation(
    IN  PSTATION                        pStation,
    IN  PNIC_RX_FRAGMENT                pNicFragment,
    IN  ULONG                           TotalLength
    );

#endif // _STATION_RECEIVE_H_


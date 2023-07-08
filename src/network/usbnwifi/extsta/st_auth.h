/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    Sta_auth.h

Abstract:
    STA layer authentication frame processing functions
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created

Notes:

--*/
#ifndef _STATION_AUTHENTICATION_H_
#define _STATION_AUTHENTICATION_H_

/**
 * Starts exchanging authentication packets with the access point. 
 * 
 * \param pStation          STATION structure
 * \param pAPEntry          APEntry to authenticate with
 * \param AuthenticateTimeout  Max time to wait for authentication completion,
 *                             expressed in 100 nanoseconds
 * \return NDIS_STATUS  If the function fails, it must complete association process
 *                      before returning.
 * \sa StaAuthenticateComplete
 */
NDIS_STATUS
StaAuthenticate(
    IN  PSTATION        pStation,
    IN  PSTA_BSS_ENTRY  pAPEntry,
    IN  ULONG           AuthenticateTimeout
    );

/**
 * Called to complete an authentication attempt. This is generally called on receiving
 * authentication response (depending on authentication type) or on timeout
 * 
 * \param pStation          STATION structure
 * \param Status            Status code for the authentication attempt. If the
 *                          status is zero, the authentication is considered a 
 *                          success and association step initiated
 * \param ErrorSource       Source of error in case Status was non successful
 * \sa 
 */
VOID
StaAuthenticateComplete(
    IN  PSTATION        pStation,
    IN  ULONG           Status
    );

/**
 * Timeout call back in case of timeout waiting for authentication response. This 
 * can also be called from the reset routine to expedite association process 
 * completion. This means it may be called at IRQL_PASSIVE or IRQL_DISPATCH
 *
 * \param param             STATION structure
 */
 VOID
StaAuthenticateTimeoutCallback(
    IN WDFTIMER WdfTimer
    );

/**
 * Sends a deauthentication packet to an access point. The caller is responsible
 * for determining if the packet must be sent or not, changing states and
 * indicating status
 * 
 * \param pStation          STATION structure
 * \param pAPEntry          APEntry to deauthenticate with
 * \param AssociateTimeout  Reason to use in the deauthenticate request
 * \return NDIS_STATUS  NDIS_STATUS from the send attempt
 */
NDIS_STATUS
StaSendDeauthentication(
    IN  PSTATION        pStation,
    IN  PSTA_BSS_ENTRY  pAPEntry,
    IN  USHORT          ReasonCode
    );


/**
 * Starts exchanging 802.11 authentication packets with the access point
 * 
 * \param pStation          STATION structure
 * \param pAPEntry          APEntry to authenticate with
 * \param AuthenticateTimeout  Max time to wait for authentication completion,
 *                             expressed in 100 nanoseconds
 * \return NDIS_STATUS  If the function fails, it must complete association process
 *                      before returning.
 * \sa StaAuthenticateComplete
 */
NDIS_STATUS
StaStart80211Authentication(
    IN  PSTATION        pStation,
    IN  PSTA_BSS_ENTRY  pAPEntry,
    IN  ULONG           AuthenticateTimeout
    );

/**
 * Timeout call back in case of timeout waiting for authentication response. This 
 * can also be called from the reset routine to expedite association process 
 * completion. This means it may be called at IRQL_PASSIVE or IRQL_DISPATCH
 *
 * \param param             STATION structure
 */
VOID
StaCancel80211Authentication(
    IN  PSTATION                        pStation
    );

/**
 * Invoked on receiving an authentication packet from an access point. This
 * function is used for 802.11 authentication
 * 
 * \param pStation          STATION structure
 * \param pPacketBuffer     Authentication packet contents
 * \param PacketLength      Length of authentication packet
 */
VOID
StaProcess80211AuthPacket(
    IN  PSTATION                        pStation,
    IN  PUCHAR                          pPacketBuffer,
    IN  ULONG                           PacketLength
    );

/**
 * Allocates and populate the first 802.11 authentication request packet. 
 * 
 * \param pStation              STATION structure
 * \param pAPEntry              The APEntry this authentication request packet is for
 * \param ppAuthPacket          Returns pointer to authentication request packet
 * \param pAuthPacketLength     Authentication request packet length
 * \return NDIS_STATUS
 * \sa StaFree80211AuthReqPacket
 */
NDIS_STATUS
StaCreate80211AuthReqPacket(
    IN  PSTATION        pStation,
    IN  PSTA_BSS_ENTRY  pAPEntry,
    OUT PUCHAR*         ppAuthPacket,
    OUT PUSHORT         pAuthPacketLength
    );

/**
 * Populate the shared key authentication challenge response packet
 * 
 * \param pStation              STATION structure
 * \param pAPEntry              The APEntry this authentication request packet is for
 * \param pPacketBuffer         Pre-allocated buffer for the auth packet with challenge
 *                              text already in place
 * \sa StaCreate80211AuthReqPacket and StaFree80211AuthReqPacket
 */
void
StaFillSharedKeyAuthChallengResPacket(
    IN  PSTATION        pStation,
    IN  PSTA_BSS_ENTRY  pAPEntry,
    IN  PUCHAR          pPacketBuffer
    );

/**
 * Frees a previously allocate 802.11 authentication request packet
 * 
 * \param pStation              STATION structure
 * \param pAPEntry              The APEntry this authentication request packet was for
 * \param pAuthPacket           Pointer to authentication request packet
 * \param AuthPacketLength      Authentication request packet length
 * \sa StaCreate80211AuthReqPacket
 */

VOID
StaFree80211AuthReqPacket(
    IN  PSTATION        pStation,
    IN  PSTA_BSS_ENTRY  pAPEntry,
    OUT PUCHAR          pAuthPacket,
    OUT USHORT          AuthPacketLength
    );


#endif // _STATION_AUTHENTICATION_H_


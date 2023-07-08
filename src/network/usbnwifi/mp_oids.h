/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    Mp_Oids.h

Abstract:
    OID processing code
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created

Notes:

--*/
#ifndef _MP_OIDS_H_

#define _MP_OIDS_H_

VOID
MpQuerySupportedOidsList(
    IN OUT PNDIS_OID *SupportedOidList,
    IN OUT PULONG    SupportedOidListLength
    );

NDIS_STATUS
MpQuerySupportedPHYTypes(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpResetRequest(
    IN  PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN  ULONG InputBufferLength,
    IN  ULONG OutputBufferLength,
    OUT PULONG BytesRead,
    OUT PULONG BytesWritten,
    OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetMulticastList(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryMPDUMaxLength(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryOperationModeCapability(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryCurrentOperationMode(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryATIMWindow(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryIndicateTXStatus(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryNicPowerState(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryOptionalCapability(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryCurrentOptionalCapability(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryCFPollable(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryPowerMgmtMode(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryOperationalRateSet(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryBeaconPeriod(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryRTSThreshold(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryShortRetryLimit(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryLongRetryLimit(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryFragmentationThreshold(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryMaxTXMSDULifeTime(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryMaxReceiveLifeTime(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryCurrentRegDomain(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryTempType(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryCurrentTXAntenna(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryDiversitySupport(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryCurrentRXAntenna(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQuerySupportedPowerLevels(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpPnPQueryPower(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength
    );

NDIS_STATUS
MpQueryCurrentTXPowerLevel(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryCurrentChannel(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryCCAModeSupported(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryCurrentCCA(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryEDThreshold(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryRegDomainsSupportValue(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQuerySupportedTXAntenna(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQuerySupportedRXAntenna(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryDiversitySelectionRX(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQuerySupportedDataRatesValue(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetATIMWindow(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetIndicateTXStatus(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetNicPowerState(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryStationId(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryPnPCapabilities(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetPower(
    IN  PADAPTER        pAdapter,
    IN  PVOID           InformationBuffer,
    IN  ULONG           InformationBufferLength,
    IN  PULONG          pulBytesNeeded,
    IN  PULONG          pulBytesRead
    );

NDIS_STATUS
MpAddWakeUpPattern(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpRemoveWakeUpPattern(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetOperationalRateSet(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetBeaconPeriod(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetRTSThreshold(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetFragmentationThreshold(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetCurrentRegDomain(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );
    
NDIS_STATUS
MpSetCurrentChannel(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetCurrentOperationMode(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpScanRequest(
    PADAPTER pAdapter,
    IN PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    OUT PULONG BytesRead,
    OUT PULONG BytesNeeded
    );



NDIS_STATUS
MpSetPacketFilter(
    IN PADAPTER pAdapter,
    IN ULONG PacketFilter
    );

NDIS_STATUS
MpEnumerateBSSList(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InputBufferLength,
    IN ULONG OutputBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryDesiredSSIDList(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryExcludedMACAddressList(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryDesiredBSSIDList(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryDesiredBSSType(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryDot11Statistics(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryEnabledAuthenticationAlgorithm(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQuerySupportedUnicastAlgorithmPair(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQuerySupportedMulticastAlgorithmPair(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryEnabledUnicastCipherAlgorithm(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryEnabledMulticastCipherAlgorithm(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpEnumerateAssociationInformation(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryHardwarePHYState(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryDesiredPHYList(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryCurrentPHYID(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryMediaSteamingOption(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryUnreachableDetectionThreshold(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryActivePHYList(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );
    
NDIS_STATUS
MpQueryDot11TableSize(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpQueryDataRateMappingTable(
    IN PADAPTER pAdapter,
    __inout_bcount(InformationBufferLength)IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpFlushBSSList(
    IN PADAPTER pAdapter
    );

NDIS_STATUS
MpSetPowerMgmtMode(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetDesiredSSIDList(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetExcludedMACAddressList(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetDesiredBSSIDList(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetDesiredBSSType(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpConnectRequest(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );


NDIS_STATUS
MpDisconnectRequest(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetEnabledAuthenticationAlgorithm(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetDesiredPHYList(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );

NDIS_STATUS
MpSetCurrentPHYID(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );
    
NDIS_STATUS
MpSetMediaStreamingOption(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );
    
NDIS_STATUS
MpSetUnreachableDetectionThreshold(
    IN PADAPTER pAdapter,
    IN OUT PVOID InformationBuffer,
    IN ULONG InformationBufferLength,
    IN OUT PULONG BytesRead,
    IN OUT PULONG BytesNeeded
    );


NDIS_STATUS
MpQueryInformation(
    IN    NDIS_HANDLE               MiniportAdapterContext,
    IN    NDIS_OID                  Oid,
    IN    PVOID                     InformationBuffer,
    IN    ULONG                     InformationBufferLength,
    OUT   PULONG                    BytesWritten,
    OUT   PULONG                    BytesNeeded
    );


NDIS_STATUS
MpSetInformation(
    IN    NDIS_HANDLE               MiniportAdapterContext,
    IN    NDIS_OID                  Oid,
    IN    PVOID                     InformationBuffer,
    IN    ULONG                     InformationBufferLength,
    OUT   PULONG                    BytesRead,
    OUT   PULONG                    BytesNeeded
    );

NDIS_STATUS
MpQuerySetInformation(
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

#endif  // _MP_OIDS_H_


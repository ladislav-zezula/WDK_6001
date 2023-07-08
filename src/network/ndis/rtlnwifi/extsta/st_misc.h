/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    st_misc.h

Abstract:
    STA layer utility functions
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created
    01-15-2006    Renamed sta_misc.h to st_misc.h

Notes:

--*/
#ifndef _STATION_MISC_H
#define _STATION_MISC_H

#define STA_INVALID_PHY_ID          0x80000000U

#define RSNA_OUI_PREFIX             0xac0f00
#define WPA_OUI_PREFIX              0xf25000

#define RSNA_CIPHER_WEP40           0x01000000
#define RSNA_CIPHER_TKIP            0x02000000
#define RSNA_CIPHER_CCMP            0x04000000
#define RSNA_CIPHER_WEP104          0x05000000

#define RSNA_AKM_RSNA               0x01000000
#define RSNA_AKM_RSNA_PSK           0x02000000

#define RSNA_CAPABILITY_PRE_AUTH    0x01
#define RSNA_CAPABILITY_NO_PAIRWISE 0x02

//
// This structure is used for extracting RSN IE in beacon or probe response frame.
// Both RSN (WPA2) and WPA share the same structure. However, for WPA, PMKIDCount
// is also 0 and PKMID NULL.
// 
typedef struct _RSN_IE_INFO
{
    ULONG   OUIPrefix;
    USHORT  Version;
    USHORT  GroupCipherCount;
    USHORT  PairwiseCipherCount;
    USHORT  AKMSuiteCount;
    USHORT  Capability;
    USHORT  PMKIDCount;
    PUCHAR  GroupCipher;
    PUCHAR  PairwiseCipher;
    PUCHAR  AKMSuite;
    PUCHAR  PMKID;
} RSN_IE_INFO, *PRSN_IE_INFO;

NDIS_STATUS
StaGetRateSetFromInfoEle(
    IN  PUCHAR InfoElemBlobPtr,
    IN  ULONG InfoElemBlobSize,
    IN  BOOLEAN basicRateOnly,
    OUT PDOT11_RATE_SET rateSet
    );

NDIS_STATUS
StaFilterUnsupportedRates(
    IN PSTA_BSS_ENTRY pAPEntry, 
    IN PDOT11_RATE_SET rateSet
    );

VOID
StaGenerateRandomBSSID(
    IN  DOT11_MAC_ADDRESS MACAddr,
    OUT DOT11_MAC_ADDRESS BSSID
    );

ULONG
StaGetPhyIdByType(
    IN PNIC pNic,
    IN DOT11_PHY_TYPE PhyType
    );

DOT11_PHY_TYPE
StaGetPhyTypeById(
    IN PNIC pNic,
    IN ULONG PhyId
    );

NDIS_STATUS
StaParseRNSIE(
    IN PUCHAR RSNIEData,
    IN ULONG OUIPrefix,
    IN UCHAR RSNIELength,
    OUT PRSN_IE_INFO RSNIEInfo
    );

DOT11_CIPHER_ALGORITHM
StaGetGroupCipherFromRSNIEInfo(
    IN PRSN_IE_INFO RSNIEInfo
    );

DOT11_CIPHER_ALGORITHM
StaGetPairwiseCipherFromRSNIEInfo(
    IN PRSN_IE_INFO RSNIEInfo,
    IN USHORT index
    );

DOT11_AUTH_ALGORITHM
StaGetAKMSuiteFromRSNIEInfo(
    IN PRSN_IE_INFO RSNIEInfo,
    IN USHORT index
    );

NDIS_STATUS
StaAttachInfraRSNIE(
    IN PSTATION pStation, 
    IN PSTA_BSS_ENTRY pAPEntry, 
    IN OUT PUCHAR *ppCurrentIE,
    IN OUT PUSHORT pIESize
    );

NDIS_STATUS
StaAttachAdHocRSNIE(
    IN PSTATION pStation, 
    IN OUT PUCHAR *ppCurrentIE,
    IN OUT PUSHORT pIESize
    );

BOOLEAN
StaMatchRSNInfo(
    IN PSTATION        pStation,
    IN PRSN_IE_INFO    RSNIEInfo
    );

#endif // _STATION_MAIN_H


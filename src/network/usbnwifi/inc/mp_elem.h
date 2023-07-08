/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    Mp_Element.h

Abstract:
    Prototypes of information element processing functions
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created

Notes:

--*/
#ifndef _NATIVE_WIFI_UTIL_H_

#define _NATIVE_WIFI_UTIL_H_

#define WPA_IE_TAG      0x01f25000

//
// Dot11ValidateInfoBlob and Dot11ValidatePacketInfoBlob
//  Validate the information blob. Dot11ValidateInfoBlob works
//  on a contiguous buffer while Dot11ValidatePacketInfoBlob
//  works on a MDL chain.
//
NDIS_STATUS
Dot11ValidateInfoBlob(
    IN PUCHAR pucInfoBlob,
    IN ULONG uOffsetOfInfoEleBlob
    );

NDIS_STATUS
Dot11GetInfoBlobSize(
    IN  PUCHAR                  pPacketBuffer,
    IN  ULONG                   PacketLength,
    IN  ULONG                   OffsetOfInfoElemBlob,
    OUT PULONG                  pInfoElemBlobSize
    );

NDIS_STATUS
Dot11ValidatePacketInfoBlob(
    IN PNDIS_BUFFER pMdlHead,
    IN ULONG uOffsetOfInfoEleBlob
    );

//
// Dot11GetInfoEle and Dot11GetInfoEleFromPacket
//      Look up a particular information element in the
//      information blob.
//
// Dot11GetInfoEle works on a contiguous buffer while
// Dot11GetInfoEleFromPacket works on a MDL chain
//
NDIS_STATUS
Dot11GetInfoEle(
    IN PUCHAR pucInfoBlob,
    IN ULONG uSizeOfBlob,
    IN UCHAR ucInfoId,
    OUT PUCHAR pucLength,
    IN OUT PVOID * ppvInfoEle
    );

NDIS_STATUS
Dot11GetInfoEleFromPacket(
    IN PNDIS_BUFFER pMdlHead,
    IN ULONG uOffsetOfInfoEleBlob,
    IN UCHAR ucInfoId,
    IN UCHAR ucMaxLength,
    OUT PUCHAR pucLength,
    IN OUT PVOID * ppvInfoEle
    );

NDIS_STATUS
Dot11CopySSIDFromPacket(
    IN PNDIS_BUFFER pMdlHead,
    IN ULONG uOffsetOfInfoEleBlob,
    IN PDOT11_SSID pDot11SSID
    );

NDIS_STATUS
Dot11GetChannelForDSPhy(
    IN PUCHAR pucInfoBlob,
    IN ULONG uSizeOfBlob,
    IN PUCHAR pucChannel
    );

NDIS_STATUS
Dot11CopySSIDFromMemoryBlob(
    IN PUCHAR pucInfoBlob,
    IN ULONG uSizeOfBlob,
    IN PDOT11_SSID pDot11SSID
    );

NDIS_STATUS
Dot11AttachElement(
    IN OUT PUCHAR *ppucBlob,
    IN OUT USHORT *pusBlobSize,
    IN UCHAR ucElementId,
    IN UCHAR ucElementLength,
    IN PUCHAR pucElementInfo
    );

NDIS_STATUS
Dot11CopyInfoEle(
    IN PUCHAR pucInfoBlob,
    IN ULONG uSizeOfBlob,
    IN UCHAR ucInfoId,
    OUT PUCHAR pucLength,
    IN ULONG uBufSize,
    IN OUT PVOID pvInfoEle
    );

NDIS_STATUS
Dot11GetWPAIE(
    IN PUCHAR pucInfoBlob,
    IN ULONG uSizeOfBlob,
    OUT PUCHAR pucLength,
    IN OUT PVOID * ppvInfoEle
    );

#endif  // _NATIVE_WIFI_UTIL_H_


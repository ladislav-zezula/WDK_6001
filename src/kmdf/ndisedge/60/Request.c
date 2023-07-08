/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

Module Name:

        Request.c

Abstract:

    This module contains Miniport function and helper routines for handling
    Set & Query Information requests.

--*/


#include "ndiswdm.h"

NDIS_OID NICSupportedOids[] =
{
        OID_GEN_SUPPORTED_LIST,
        OID_GEN_HARDWARE_STATUS,
        OID_GEN_MEDIA_SUPPORTED,
        OID_GEN_MEDIA_IN_USE,
        OID_GEN_MAXIMUM_LOOKAHEAD,
        OID_GEN_MAXIMUM_FRAME_SIZE,
        OID_GEN_LINK_SPEED,
        OID_GEN_TRANSMIT_BUFFER_SPACE,
        OID_GEN_RECEIVE_BUFFER_SPACE,
        OID_GEN_TRANSMIT_BLOCK_SIZE,
        OID_GEN_RECEIVE_BLOCK_SIZE,
        OID_GEN_VENDOR_ID,
        OID_GEN_VENDOR_DESCRIPTION,
        OID_GEN_VENDOR_DRIVER_VERSION,
        OID_GEN_CURRENT_PACKET_FILTER,
        OID_GEN_CURRENT_LOOKAHEAD,
        OID_GEN_DRIVER_VERSION,
        OID_GEN_MAXIMUM_TOTAL_SIZE,
        OID_GEN_MAC_OPTIONS,
        OID_GEN_MEDIA_CONNECT_STATUS,
        OID_GEN_MAXIMUM_SEND_PACKETS,
        OID_GEN_XMIT_OK,
        OID_GEN_RCV_OK,
        OID_GEN_XMIT_ERROR,
        OID_GEN_RCV_ERROR,
        OID_GEN_RCV_NO_BUFFER,
        OID_GEN_RCV_CRC_ERROR,
        OID_GEN_TRANSMIT_QUEUE_LENGTH,
        OID_GEN_PHYSICAL_MEDIUM,
        OID_802_3_PERMANENT_ADDRESS,
        OID_802_3_CURRENT_ADDRESS,
        OID_802_3_MULTICAST_LIST,
        OID_802_3_MAXIMUM_LIST_SIZE,
        OID_802_3_RCV_ERROR_ALIGNMENT,
        OID_802_3_XMIT_ONE_COLLISION,
        OID_802_3_XMIT_MORE_COLLISIONS,
        OID_802_3_XMIT_DEFERRED,
        OID_802_3_XMIT_MAX_COLLISIONS,
        OID_802_3_RCV_OVERRUN,
        OID_802_3_XMIT_UNDERRUN,
        OID_802_3_XMIT_HEARTBEAT_FAILURE,
        OID_802_3_XMIT_TIMES_CRS_LOST,
        OID_802_3_XMIT_LATE_COLLISIONS
#ifndef INTERFACE_WITH_NDISPROT
        ,
        OID_PNP_CAPABILITIES,
        OID_PNP_SET_POWER,
        OID_PNP_QUERY_POWER,
        OID_PNP_ADD_WAKE_UP_PATTERN,
        OID_PNP_REMOVE_WAKE_UP_PATTERN,
        OID_PNP_ENABLE_WAKE_UP
#endif
};

#pragma NDIS_PAGEABLE_FUNCTION(NICSendOidRequest)

NDIS_STATUS
MPOidRequest(
    IN  NDIS_HANDLE        MiniportAdapterContext,
    IN  PNDIS_OID_REQUEST  NdisRequest
    )
/*++
Routine Description:

    NDIS calls a miniport driver's MiniportOidRequest function to send an OID
    request to the driver. These OID requests are serialized so the
    MiniportOidRequest function is not called until the pending OID request
    has completed. MiniportOidRequest can be called at either IRQL
    PASSIVE_LEVEL or IRQL DISPATCH_LEVEL.

    If the MiniportOidRequest function returns NDIS_STATUS_PENDING,
    the miniport driver must subsequently call the NdisMOidRequestComplete
    function to complete the request. NdisMOidRequestComplete can be called
    at either IRQL DISPATCH_LEVEL or IRQL PASSIVE_LEVEL.

Arguments:

    MiniportAdapterContext  Pointer to the adapter structure
    NdisRequest             Pointer to NDIS_OID_REQUEST

Return Value:

    NDIS_STATUS_SUCCESS
    NDIS_STATUS_NOT_SUPPORTED
    NDIS_STATUS_BUFFER_TOO_SHORT

--*/
{
    PMP_ADAPTER             Adapter = (PMP_ADAPTER)MiniportAdapterContext;
    NDIS_STATUS             Status = NDIS_STATUS_SUCCESS;
    NDIS_REQUEST_TYPE       RequestType;

    DEBUGP(MP_TRACE, ("---> MPOidRequest\n"));

    //
    // Should abort the request if reset is in process
    //
    NdisAcquireSpinLock(&Adapter->Lock);

    //
    // If there is a request pending then assert.
    //

    ASSERT(Adapter->PendingOidNdisRequest == NULL);

    if (MP_TEST_FLAG(Adapter,
        (fMP_RESET_IN_PROGRESS | fMP_HALT_IN_PROGRESS)))
    {
        NdisReleaseSpinLock(&Adapter->Lock);
        Status =  NDIS_STATUS_REQUEST_ABORTED;
        goto End;
    }

    NdisReleaseSpinLock(&Adapter->Lock);

    RequestType = NdisRequest->RequestType;

    switch (RequestType)
    {
        case NdisRequestMethod:
            break;

        case NdisRequestSetInformation:
            Status = NICSetInformation(Adapter, NdisRequest);
            break;

        case NdisRequestQueryInformation:
        case NdisRequestQueryStatistics:
            Status = NICQueryInformation(Adapter, NdisRequest);
            break;

        default:
            //
            // Later the entry point may by used by all the requests
            //
            Status = NDIS_STATUS_NOT_SUPPORTED;
            break;
    }

End:
    DEBUGP(MP_TRACE, ("<---- MPOidRequest\n"));
    return Status;

}


NDIS_STATUS
NICQueryInformation(
    IN  NDIS_HANDLE         MiniportAdapterContext,
    IN  PNDIS_OID_REQUEST   NdisRequest
    )
/*++
Routine Description:

    MiniportQueryInformation handler

Arguments:

    MiniportAdapterContext  Pointer to the adapter structure
    NdisRequest             Pointer to the query request

Return Value:

    NDIS_STATUS_SUCCESS
    NDIS_STATUS_NOT_SUPPORTED
    NDIS_STATUS_BUFFER_TOO_SHORT

--*/
{
    NDIS_OID                Oid;
    PVOID                   InformationBuffer;
    ULONG                   InformationBufferLength;
    PUINT                   BytesWritten;
    PUINT                   BytesNeeded;
    NDIS_STATUS             Status = NDIS_STATUS_SUCCESS;
    PMP_ADAPTER             Adapter;
    NDIS_HARDWARE_STATUS    HardwareStatus = NdisHardwareStatusReady;
    NDIS_MEDIUM             Medium = NIC_MEDIA_TYPE;
    UCHAR                   VendorDesc[] = NIC_VENDOR_DESC;
    ULONG                   ulInfo = 0;
    USHORT                  usInfo = 0;
    ULONG64                 ulInfo64 = 0;
    PVOID                   pInfo = (PVOID) &ulInfo;
    ULONG                   ulInfoLen = sizeof(ulInfo);
    BOOLEAN                 bForwardRequest = TRUE;
    NDIS_PNP_CAPABILITIES   PMCaps;
    NDIS_PHYSICAL_MEDIUM    PhysMedium = NdisPhysicalMediumUnspecified;

    Oid = NdisRequest->DATA.QUERY_INFORMATION.Oid;
    InformationBuffer = NdisRequest->DATA.QUERY_INFORMATION.InformationBuffer;
    InformationBufferLength = NdisRequest->DATA.QUERY_INFORMATION.InformationBufferLength;

    //
    // Initialize the result
    //
    BytesWritten = &NdisRequest->DATA.QUERY_INFORMATION.BytesWritten;
    BytesNeeded = &NdisRequest->DATA.QUERY_INFORMATION.BytesNeeded;

    *BytesWritten = 0;
    *BytesNeeded = 0;

    DEBUGP(MP_VERY_LOUD, ("---> MPQueryInformation %s\n", DbgGetOidName(Oid)));

    Adapter = (PMP_ADAPTER) MiniportAdapterContext;

    switch (Oid)
    {
        case OID_GEN_SUPPORTED_LIST:
            //
            // The OID_GEN_SUPPORTED_LIST OID specifies an array of OIDs
            // for objects that the underlying driver or its NIC supports.
            // Objects include general, media-specific, and implementation-
            // specific objects. NDIS forwards a subset of the returned
            // list to protocols that make this query. That is, NDIS filters
            // any supported statistics OIDs out of the list because
            // protocols never make statistics queries.
            //
            pInfo = (PVOID) NICSupportedOids;
            ulInfoLen = sizeof(NICSupportedOids);
            bForwardRequest = FALSE;
            break;

        case OID_GEN_HARDWARE_STATUS:
            //
            // Specify the current hardware status of the underlying NIC as
            // one of the following NDIS_HARDWARE_STATUS-type values.
            //
            pInfo = (PVOID) &HardwareStatus;
            ulInfoLen = sizeof(NDIS_HARDWARE_STATUS);
            bForwardRequest = FALSE;
            break;

        case OID_GEN_MEDIA_SUPPORTED:
            //
            // Specify the media types that the NIC can support but not
            // necessarily the media types that the NIC currently uses.
            // fallthrough:
        case OID_GEN_MEDIA_IN_USE:
            //
            // Specifiy a complete list of the media types that the NIC
            // currently uses.
            //
            pInfo = (PVOID) &Medium;
            ulInfoLen = sizeof(NDIS_MEDIUM);
            bForwardRequest = FALSE;
            break;


    case OID_GEN_PHYSICAL_MEDIUM:
            pInfo = (PVOID) &PhysMedium;
            ulInfoLen = sizeof(NDIS_PHYSICAL_MEDIUM);
            break;

        case OID_GEN_CURRENT_LOOKAHEAD:
        case OID_GEN_MAXIMUM_LOOKAHEAD:
            //
            // If the miniport driver indicates received data by calling
            // NdisXxxIndicateReceive, it should respond to OID_GEN_MAXIMUM_LOOKAHEAD
            // with the maximum number of bytes the NIC can provide as
            // lookahead data. If that value is different from the size of the
            // lookahead buffer supported by bound protocols, NDIS will call
            // MiniportSetInformation to set the size of the lookahead buffer
            // provided by the miniport driver to the minimum of the miniport
            // driver and protocol(s) values. If the driver always indicates
            // up full packets with NdisMIndicateReceivePacket, it should
            // set this value to the maximum total packet size, which
            // excludes the header.
            // Upper-layer drivers examine lookahead data to determine whether
            // a packet that is associated with the lookahead data is intended
            // for one or more of their clients. If the underlying driver
            // supports multipacket receive indications, bound protocols are
            // given full net packets on every indication. Consequently,
            // this value is identical to that returned for
            // OID_GEN_RECEIVE_BLOCK_SIZE.
            //
            if (Adapter->ulLookAhead == 0)
            {
                Adapter->ulLookAhead = NIC_MAX_LOOKAHEAD;
            }
            ulInfo = Adapter->ulLookAhead;
            bForwardRequest = FALSE;
            break;

        case OID_GEN_MAXIMUM_FRAME_SIZE:
            //
            // Specifiy the maximum network packet size, in bytes, that the
            // NIC supports excluding the header. A NIC driver that emulates
            // another medium type for binding to a transport must ensure that
            // the maximum frame size for a protocol-supplied net packet does
            // not exceed the size limitations for the true network medium.
            //
            ulInfo = ETH_MAX_PACKET_SIZE - ETH_HEADER_SIZE;
            bForwardRequest = FALSE;
            break;

        case OID_GEN_MAXIMUM_TOTAL_SIZE:
            //
            // Specify the maximum total packet length, in bytes, the NIC
            // supports including the header. A protocol driver might use
            // this returned length as a gauge to determine the maximum
            // size packet that a NIC driver could forward to the
            // protocol driver. The miniport driver must never indicate
            // up to the bound protocol driver packets received over the
            // network that are longer than the packet size specified by
            // OID_GEN_MAXIMUM_TOTAL_SIZE.
            //
        case OID_GEN_TRANSMIT_BLOCK_SIZE:
            //
            // The OID_GEN_TRANSMIT_BLOCK_SIZE OID specifies the minimum
            // number of bytes that a single net packet occupies in the
            // transmit buffer space of the NIC. For example, a NIC that
            // has a transmit space divided into 256-byte pieces would have
            // a transmit block size of 256 bytes. To calculate the total
            // transmit buffer space on such a NIC, its driver multiplies
            // the number of transmit buffers on the NIC by its transmit
            // block size. In our case, the transmit block size is
            // identical to its maximum packet size.

        case OID_GEN_RECEIVE_BLOCK_SIZE:
            //
            // The OID_GEN_RECEIVE_BLOCK_SIZE OID specifies the amount of
            // storage, in bytes, that a single packet occupies in the receive
            // buffer space of the NIC.
            //
            ulInfo = (ULONG) ETH_MAX_PACKET_SIZE;
            bForwardRequest = FALSE;
            break;

        case OID_GEN_MAC_OPTIONS:
            //
            // Specify a bitmask that defines optional properties of the NIC.
            // This miniport indicates receive with NdisMIndicateReceivePacket
            // function. It has no MiniportTransferData function. Such a driver
            // should set this NDIS_MAC_OPTION_TRANSFERS_NOT_PEND flag.
            //
            // NDIS_MAC_OPTION_NO_LOOPBACK tells NDIS that NIC has no internal
            // loopback support so NDIS will manage loopbacks on behalf of
            // this driver.
            //
            // NDIS_MAC_OPTION_COPY_LOOKAHEAD_DATA tells the protocol that
            // our receive buffer is not on a device-specific card. If
            // NDIS_MAC_OPTION_COPY_LOOKAHEAD_DATA is not set, multi-buffer
            // indications are copied to a single flat buffer.
            //
            ulInfo = NDIS_MAC_OPTION_COPY_LOOKAHEAD_DATA |
                NDIS_MAC_OPTION_TRANSFERS_NOT_PEND |
                NDIS_MAC_OPTION_NO_LOOPBACK;
            bForwardRequest = FALSE;
            break;

        case OID_GEN_LINK_SPEED:
            //
            // Specify the maximum speed of the NIC in kbps.
            //
            ulInfo = Adapter->ulLinkSpeed;
            break;

        case OID_GEN_TRANSMIT_BUFFER_SPACE:
            //
            // Specify the amount of memory, in bytes, on the NIC that
            // is available for buffering transmit data. A protocol can
            // use this OID as a guide for sizing the amount of transmit
            // data per send.
            //
            ulInfo = ETH_MAX_PACKET_SIZE * NIC_MAX_BUSY_SENDS;
            bForwardRequest = FALSE;
            break;

        case OID_GEN_RECEIVE_BUFFER_SPACE:
            //
            // Specify the amount of memory on the NIC that is available
            // for buffering receive data. A protocol driver can use this
            // OID as a guide for advertising its receive window after it
            // establishes sessions with remote nodes.
            //
            ulInfo = ETH_MAX_PACKET_SIZE * NIC_MAX_BUSY_RECVS;
            bForwardRequest = FALSE;
            break;

        case OID_GEN_VENDOR_ID:
            //
            // Specify a three-byte IEEE-registered vendor code, followed
            // by a single byte that the vendor assigns to identify a
            // particular NIC. The IEEE code uniquely identifies the vendor
            // and is the same as the three bytes appearing at the beginning
            // of the NIC hardware address. Vendors without an IEEE-registered
            // code should use the value 0xFFFFFF.
            //
            ulInfo = NIC_VENDOR_ID;
            bForwardRequest = FALSE;
            break;

        case OID_GEN_VENDOR_DESCRIPTION:
            //
            // Specify a zero-terminated string describing the NIC vendor.
            //
            pInfo = VendorDesc;
            ulInfoLen = sizeof(VendorDesc);
            bForwardRequest = FALSE;
            break;

        case OID_GEN_VENDOR_DRIVER_VERSION:
            //
            // Specify the vendor-assigned version number of the NIC driver.
            // The low-order half of the return value specifies the minor
            // version; the high-order half specifies the major version.
            //
            ulInfo = NIC_VENDOR_DRIVER_VERSION;
            bForwardRequest = FALSE;
            break;

        case OID_GEN_DRIVER_VERSION:
            //
            // Specify the NDIS version in use by the NIC driver. The high
            // byte is the major version number; the low byte is the minor
            // version number.
            //
            usInfo = (USHORT) (MP_NDIS_MAJOR_VERSION<<8) + MP_NDIS_MINOR_VERSION;
            pInfo = (PVOID) &usInfo;
            ulInfoLen = sizeof(USHORT);
            bForwardRequest = FALSE;
            break;

        case OID_GEN_MAXIMUM_SEND_PACKETS:
            //
            // If a miniport driver registers a MiniportSendPackets function,
            // MiniportQueryInformation will be called with the
            // OID_GEN_MAXIMUM_SEND_PACKETS request. The miniport driver must
            // respond with the maximum number of packets it is prepared to
            // handle on a single send request. The miniport driver should
            // pick a maximum that minimizes the number of packets that it
            // has to queue internally because it has no resources
            // (its device is full). A miniport driver for a bus-master DMA
            // NIC should attempt to pick a value that keeps its NIC filled
            // under anticipated loads.
            //
            ulInfo = NIC_MAX_SEND_PKTS;
            bForwardRequest = FALSE;
            break;

        case OID_GEN_MEDIA_CONNECT_STATUS:
            //
            // Return the connection status of the NIC on the network as one
            // of the following system-defined values: NdisMediaStateConnected
            // or NdisMediaStateDisconnected.
            //
            ulInfo = NICGetMediaConnectStatus(Adapter);
            bForwardRequest = FALSE;
            break;

        case OID_GEN_CURRENT_PACKET_FILTER:
            //
            // Specifiy the types of net packets such as directed, broadcast
            // multicast, for which a protocol receives indications from a
            // NIC driver. After NIC is initialized, a protocol driver
            // can send a set OID_GEN_CURRENT_PACKET_FILTER to a non-zero value,
            // thereby enabling the miniport driver to indicate receive packets
            // to that protocol.
            //
            ulInfo = Adapter->PacketFilter;
            bForwardRequest = FALSE;
            break;

        case OID_PNP_CAPABILITIES:
            //
            // Return the wake-up capabilities of its NIC. If you return
            // NDIS_STATUS_NOT_SUPPORTED, NDIS considers the miniport driver
            // to be not Power management aware and doesn't send any power
            // or wake-up related queries such as
            // OID_PNP_SET_POWER, OID_PNP_QUERY_POWER,
            // OID_PNP_ADD_WAKE_UP_PATTERN, OID_PNP_REMOVE_WAKE_UP_PATTERN,
            // OID_PNP_ENABLE_WAKE_UP. Here, we are expecting the driver below
            // us to do the right thing.
            //
            RtlZeroMemory (&PMCaps, sizeof(NDIS_PNP_CAPABILITIES));
            ulInfoLen = sizeof (NDIS_PNP_CAPABILITIES);
            pInfo = (PVOID) &PMCaps;
            Status = NDIS_STATUS_SUCCESS;
            break;

        case OID_PNP_QUERY_POWER:
            Status = NDIS_STATUS_SUCCESS;
            break;

            //
            // Following 4 OIDs are for querying Ethernet Operational
            // Characteristics.
            //
        case OID_802_3_PERMANENT_ADDRESS:
            //
            // Return the MAC address of the NIC burnt in the hardware.
            //
            pInfo = Adapter->PermanentAddress;
            ulInfoLen = ETH_LENGTH_OF_ADDRESS;
            break;

        case OID_802_3_CURRENT_ADDRESS:
            //
            // Return the MAC address the NIC is currently programmed to
            // use. Note that this address could be different from the
            // permananent address as the user can override using
            // registry. Read NdisReadNetworkAddress doc for more info.
            //
            pInfo = Adapter->CurrentAddress;
            ulInfoLen = ETH_LENGTH_OF_ADDRESS;
            break;

        case OID_802_3_MAXIMUM_LIST_SIZE:
            //
            // The maximum number of multicast addresses the NIC driver
            // can manage. This list is global for all protocols bound
            // to (or above) the NIC. Consequently, a protocol can receive
            // NDIS_STATUS_MULTICAST_FULL from the NIC driver when
            // attempting to set the multicast address list, even if
            // the number of elements in the given list is less than
            // the number originally returned for this query.
            //
            ulInfo = NIC_MAX_MCAST_LIST;
            bForwardRequest = TRUE;
            break;

            //
            // Following list  consists of both general and Ethernet
            // specific statistical OIDs.
            //

        case OID_GEN_XMIT_OK:
            ulInfo64 = Adapter->GoodTransmits;
            pInfo = &ulInfo64;
            if (InformationBufferLength >= sizeof(ULONG64) ||
                InformationBufferLength == 0)
            {
                ulInfoLen = sizeof(ULONG64);
            }
            else
            {
                ulInfoLen = sizeof(ULONG);
            }
            // We should always report that 8 bytes are required to keep ndistest happy
            *BytesNeeded =  sizeof(ULONG64);
            break;

        case OID_GEN_RCV_OK:
            ulInfo64 = Adapter->GoodReceives;
            pInfo = &ulInfo64;
            if (InformationBufferLength >= sizeof(ULONG64) ||
                InformationBufferLength == 0)
            {
                ulInfoLen = sizeof(ULONG64);
            }
            else
            {
                ulInfoLen = sizeof(ULONG);
            }
            // We should always report that 8 bytes are required to keep ndistest happy
            *BytesNeeded =  sizeof(ULONG64);
            break;

        case OID_GEN_XMIT_ERROR:
            ulInfo = Adapter->TxAbortExcessCollisions +
                Adapter->TxDmaUnderrun +
                Adapter->TxLostCRS +
                Adapter->TxLateCollisions+
                Adapter->TransmitFailuresOther;
            break;

        case OID_GEN_RCV_ERROR:
            ulInfo = Adapter->RcvCrcErrors +
                Adapter->RcvAlignmentErrors +
                Adapter->RcvResourceErrors +
                Adapter->RcvDmaOverrunErrors +
                Adapter->RcvRuntErrors;
            break;

        case OID_GEN_RCV_NO_BUFFER:
            ulInfo = Adapter->RcvResourceErrors;
            break;

        case OID_GEN_RCV_CRC_ERROR:
            ulInfo = Adapter->RcvCrcErrors;
            break;

        case OID_GEN_TRANSMIT_QUEUE_LENGTH:
            ulInfo = NIC_MAX_BUSY_SENDS;
            break;

        case OID_802_3_RCV_ERROR_ALIGNMENT:
            ulInfo = Adapter->RcvAlignmentErrors;
            break;

        case OID_802_3_XMIT_ONE_COLLISION:
            ulInfo = Adapter->OneRetry;
            break;

        case OID_802_3_XMIT_MORE_COLLISIONS:
            ulInfo = Adapter->MoreThanOneRetry;
            break;

        case OID_802_3_XMIT_DEFERRED:
            ulInfo = Adapter->TxOKButDeferred;
            break;

        case OID_802_3_XMIT_MAX_COLLISIONS:
            ulInfo = Adapter->TxAbortExcessCollisions;
            break;

        case OID_802_3_RCV_OVERRUN:
            ulInfo = Adapter->RcvDmaOverrunErrors;
            break;

        case OID_802_3_XMIT_UNDERRUN:
            ulInfo = Adapter->TxDmaUnderrun;
            break;

        case OID_802_3_XMIT_HEARTBEAT_FAILURE:
            ulInfo = Adapter->TxLostCRS;
            break;

        case OID_802_3_XMIT_TIMES_CRS_LOST:
            ulInfo = Adapter->TxLostCRS;
            break;

        case OID_802_3_XMIT_LATE_COLLISIONS:
            ulInfo = Adapter->TxLateCollisions;
            break;

        default:
            Status = NDIS_STATUS_NOT_SUPPORTED;
            break;
    }


    if (Status == NDIS_STATUS_SUCCESS)
    {
        if (ulInfoLen <= InformationBufferLength)
        {
            // Copy result into InformationBuffer
            *BytesWritten = ulInfoLen;
            if (ulInfoLen)
            {
                NdisMoveMemory(InformationBuffer, pInfo, ulInfoLen);
            }
        }
        else
        {
            // too short
            *BytesNeeded = ulInfoLen;
            Status = NDIS_STATUS_BUFFER_TOO_SHORT;
        }
    }

    if (Status == NDIS_STATUS_SUCCESS && bForwardRequest &&
            MP_IS_READY(Adapter) && InformationBufferLength){

        Status = NICForwardRequest(Adapter,  NdisRequest);
        ASSERT(Status == NDIS_STATUS_SUCCESS);
        Status = NDIS_STATUS_PENDING;

    }

    DEBUGP(MP_VERY_LOUD, ("<--- NICQueryInformation Status = 0x%08x\n",
                                                Status));

    return(Status);
}

NDIS_STATUS
NICSetInformation(
    IN NDIS_HANDLE           MiniportAdapterContext,
    IN PNDIS_OID_REQUEST     NdisRequest
    )
/*++
Routine Description:

    This is the handler for an OID set operation.
    The only operations that really change the configuration of the adapter are
    set PACKET_FILTER, and SET_MULTICAST.

Arguments:

    MiniportAdapterContext  Pointer to the adapter structure
    NdisRequest             Pointer to the request needed to process

Return Value:

    NDIS_STATUS_SUCCESS
    NDIS_STATUS_INVALID_LENGTH
    NDIS_STATUS_INVALID_OID
    NDIS_STATUS_NOT_SUPPORTED
    NDIS_STATUS_NOT_ACCEPTED

--*/
{
    NDIS_OID                    Oid;
    PVOID                       InformationBuffer;
    ULONG                       InformationBufferLength;
    PUINT                       BytesRead;
    PUINT                       BytesNeeded;
    NDIS_STATUS             Status = NDIS_STATUS_SUCCESS;
    PMP_ADAPTER             Adapter = (PMP_ADAPTER) MiniportAdapterContext;
    PNDIS_PM_PACKET_PATTERN pPmPattern = NULL;
    BOOLEAN                 bForwardRequest = FALSE;

    Oid = NdisRequest->DATA.SET_INFORMATION.Oid;
    InformationBuffer = NdisRequest->DATA.SET_INFORMATION.InformationBuffer;
    InformationBufferLength = NdisRequest->DATA.SET_INFORMATION.InformationBufferLength;

    BytesRead = &NdisRequest->DATA.SET_INFORMATION.BytesRead;
    BytesNeeded = &NdisRequest->DATA.SET_INFORMATION.BytesNeeded;

    *BytesRead = 0;
    *BytesNeeded = 0;

    DEBUGP(MP_VERY_LOUD, ("---> NICSetInformation %s\n", DbgGetOidName(Oid)));

    switch (Oid)
    {
        case OID_802_3_MULTICAST_LIST:
            //
            // Set the multicast address list on the NIC for packet reception.
            // The NIC driver can set a limit on the number of multicast
            // addresses bound protocol drivers can enable simultaneously.
            // NDIS returns NDIS_STATUS_MULTICAST_FULL if a protocol driver
            // exceeds this limit or if it specifies an invalid multicast
            // address.
            //
            Status = NICSetMulticastList(
                            Adapter,
                            InformationBuffer,
                            InformationBufferLength,
                            (PULONG)BytesRead,
                            (PULONG)BytesNeeded);
            if (!Adapter->Promiscuous) {
                bForwardRequest = TRUE;
            }
            break;

        case OID_GEN_CURRENT_PACKET_FILTER:
            //
            // Program the hardware to indicate the packets
            // of certain filter types.
            //
            if (InformationBufferLength != sizeof(ULONG))
            {
                *BytesNeeded = sizeof(ULONG);
                Status = NDIS_STATUS_INVALID_LENGTH;
                break;
            }

            *BytesRead = InformationBufferLength;

            Status = NICSetPacketFilter(
                            Adapter,
                            *((PULONG)InformationBuffer));

            if (!Adapter->Promiscuous) {
                bForwardRequest = TRUE;
            }
            break;

        case OID_GEN_CURRENT_LOOKAHEAD:
            //
            // A protocol driver can set a suggested value for the number
            // of bytes to be used in its binding; however, the underlying
            // NIC driver is never required to limit its indications to
            // the value set.
            //
            if (InformationBufferLength != sizeof(ULONG)){
                *BytesNeeded = sizeof(ULONG);
                Status = NDIS_STATUS_INVALID_LENGTH;
                break;
            }

            Adapter->ulLookAhead = *(PULONG)InformationBuffer;

            *BytesRead = sizeof(ULONG);
            Status = NDIS_STATUS_SUCCESS;
            bForwardRequest = FALSE;

            break;

        case OID_PNP_SET_POWER:
            //
            // This OID notifies a miniport driver that its NIC will be
            // transitioning to the device power state specified in the
            // InformationBuffer. The miniport driver must always return
            // NDIS_STATUS_SUCCESS to an OID_PNP_SET_POWER request. An
            // OID_PNP_SET_POWER request may or may not be preceded by an
            // OID_PNP_QUERY_POWER request.
            //
            if (InformationBufferLength != sizeof(NDIS_DEVICE_POWER_STATE ))
            {
                Status = NDIS_STATUS_INVALID_LENGTH;
                break;
            }
            *BytesRead = sizeof(NDIS_DEVICE_POWER_STATE);
            Status = NDIS_STATUS_SUCCESS;
            bForwardRequest = TRUE;
            break;

        case OID_PNP_ADD_WAKE_UP_PATTERN:
            //
            // This OID is sent by a protocol driver to a miniport driver to
            // specify a wake-up pattern. The wake-up pattern, along with its mask,
            // is described by an NDIS_PM_PACKET_PATTERN structure.
            //
            pPmPattern = (PNDIS_PM_PACKET_PATTERN) InformationBuffer;
            if (InformationBufferLength < sizeof(NDIS_PM_PACKET_PATTERN))
            {
                Status = NDIS_STATUS_BUFFER_TOO_SHORT;

                *BytesNeeded = sizeof(NDIS_PM_PACKET_PATTERN);
                break;
            }
            if (InformationBufferLength < pPmPattern->PatternOffset + pPmPattern->PatternSize)
            {
                Status = NDIS_STATUS_BUFFER_TOO_SHORT;

                *BytesNeeded = pPmPattern->PatternOffset + pPmPattern->PatternSize;
                break;
            }
            *BytesRead = pPmPattern->PatternOffset + pPmPattern->PatternSize;
            Status = NDIS_STATUS_SUCCESS;
            bForwardRequest = TRUE;
            break;

        case OID_PNP_REMOVE_WAKE_UP_PATTERN:
            //
            // This OID requests the miniport driver to delete a wake-up pattern
            // that it previously received in an OID_PNP_ADD_WAKE_UP_PATTERN request.
            // The wake-up pattern, along with its mask, is described by an
            // NDIS_PM_PACKET_PATTERN structure.
            //
            pPmPattern = (PNDIS_PM_PACKET_PATTERN) InformationBuffer;
            if (InformationBufferLength < sizeof(NDIS_PM_PACKET_PATTERN))
            {
                Status = NDIS_STATUS_BUFFER_TOO_SHORT;

                *BytesNeeded = sizeof(NDIS_PM_PACKET_PATTERN);
                break;
            }
            if (InformationBufferLength < pPmPattern->PatternOffset + pPmPattern->PatternSize)
            {
                Status = NDIS_STATUS_BUFFER_TOO_SHORT;

                *BytesNeeded = pPmPattern->PatternOffset + pPmPattern->PatternSize;
                break;
            }
            *BytesRead = pPmPattern->PatternOffset + pPmPattern->PatternSize;
            Status = NDIS_STATUS_SUCCESS;
            bForwardRequest = TRUE;

            break;

        case OID_PNP_ENABLE_WAKE_UP:
            //
            // This OID specifies which wake-up capabilities a miniport
            // driver should enable in its NIC. Before the miniport
            // transitions to a low-power state (that is, before NDIS
            // sends the miniport driver an OID_PNP_SET_POWER request),
            // NDIS sends the miniport an OID_PNP_ENABLE_WAKE_UP request to
            // enable the appropriate wake-up capabilities.
            //
            DEBUGP(MP_INFO, ("--> OID_PNP_ENABLE_WAKE_UP\n"));
            if (InformationBufferLength != sizeof(ULONG))
            {
                *BytesNeeded = sizeof(ULONG);
                Status = NDIS_STATUS_INVALID_LENGTH;
                break;
            }
            *BytesRead = sizeof(ULONG);
            Status = NDIS_STATUS_SUCCESS;
            bForwardRequest = TRUE;
            break;

        default:
            Status = NDIS_STATUS_INVALID_OID;
            break;

    }

    if (Status == NDIS_STATUS_SUCCESS && bForwardRequest &&
        MP_IS_READY(Adapter) && InformationBufferLength){

        Status = NICForwardRequest(Adapter, NdisRequest);
        ASSERT(Status == NDIS_STATUS_SUCCESS);
        Status = NDIS_STATUS_PENDING;
    }

    DEBUGP(MP_VERY_LOUD, ("<-- NICSetInformation Status = 0x%08x\n", Status));

    return(Status);
}

ULONG
NICGetMediaConnectStatus(
    PMP_ADAPTER Adapter
    )
/*++
Routine Description:
    This routine will query the hardware and return
    the media status.

Arguments:
    IN PMP_ADAPTER Adapter - pointer to adapter block

Return Value:
    NdisMediaStateDisconnected or
    NdisMediaStateConnected

--*/
{
    if (MP_TEST_FLAG(Adapter, fMP_DISCONNECTED))
    {
        return(NdisMediaStateDisconnected);
    }
    else
    {
        return(NdisMediaStateConnected);
    }
}

NDIS_STATUS
NICSetPacketFilter(
    IN PMP_ADAPTER Adapter,
    IN ULONG PacketFilter)
/*++
Routine Description:
    This routine will set up the adapter so that it accepts packets
    that match the specified packet filter.  The only filter bits
    that can truly be toggled are for broadcast and promiscuous

Arguments:
    IN PMP_ADAPTER Adapter - pointer to adapter block
    IN ULONG PacketFilter - the new packet filter

Return Value:
    NDIS_STATUS_SUCCESS
    NDIS_STATUS_NOT_SUPPORTED

--*/

{
    NDIS_STATUS      Status = NDIS_STATUS_SUCCESS;

    DEBUGP(MP_TRACE, ("--> NICSetPacketFilter\n"));

    // any bits not supported?
    if (PacketFilter & ~NIC_SUPPORTED_FILTERS)
    {
        return(NDIS_STATUS_NOT_SUPPORTED);
    }

    // any filtering changes?
    if (PacketFilter != Adapter->PacketFilter)
    {
        //
        // Change the filtering modes on hardware
        // TODO


        // Save the new packet filter value
        Adapter->PacketFilter = PacketFilter;
    }

    DEBUGP(MP_TRACE, ("<-- NICSetPacketFilter\n"));

    return(Status);
}


NDIS_STATUS
NICSetMulticastList(
    IN PMP_ADAPTER              Adapter,
    IN PVOID                    InformationBuffer,
    IN ULONG                    InformationBufferLength,
    OUT PULONG                  pBytesRead,
    OUT PULONG                  pBytesNeeded
    )
/*++
Routine Description:
    This routine will set up the adapter for a specified multicast
    address list.

Arguments:
    IN PMP_ADAPTER Adapter - Pointer to adapter block
    InformationBuffer       - Buffer for information
    InformationBufferLength   Size of this buffer
    pBytesRead                Specifies how much info is read
    BytesNeeded               In case the buffer is smaller than

Return Value:

    NDIS_STATUS

--*/
{
    NDIS_STATUS            Status = NDIS_STATUS_SUCCESS;
    ULONG                  index;

    UNREFERENCED_PARAMETER(index);

    DEBUGP(MP_TRACE, ("--> NICSetMulticastList\n"));

    //
    // Initialize.
    //
    *pBytesNeeded = 0;
    *pBytesRead = InformationBufferLength;

    do
    {
        if (InformationBufferLength % ETH_LENGTH_OF_ADDRESS)
        {
            Status = NDIS_STATUS_INVALID_LENGTH;
            break;
        }

        if (InformationBufferLength > (NIC_MAX_MCAST_LIST * ETH_LENGTH_OF_ADDRESS))
        {
            Status = NDIS_STATUS_MULTICAST_FULL;
            *pBytesNeeded = NIC_MAX_MCAST_LIST * ETH_LENGTH_OF_ADDRESS;
            break;
        }

        //
        // Protect the list update with a lock if it can be updated by
        // another thread simultaneously.
        //

        NdisZeroMemory(Adapter->MCList,
                       NIC_MAX_MCAST_LIST * ETH_LENGTH_OF_ADDRESS);

        NdisMoveMemory(Adapter->MCList,
                       InformationBuffer,
                       InformationBufferLength);

        Adapter->ulMCListSize =    InformationBufferLength / ETH_LENGTH_OF_ADDRESS;

#if DBG
        // display the multicast list
        for(index = 0; index < Adapter->ulMCListSize; index++)
        {
            DEBUGP(MP_VERY_LOUD, ("MC(%d) = %02x-%02x-%02x-%02x-%02x-%02x\n",
                index,
                Adapter->MCList[index][0],
                Adapter->MCList[index][1],
                Adapter->MCList[index][2],
                Adapter->MCList[index][3],
                Adapter->MCList[index][4],
                Adapter->MCList[index][5]));
        }
#endif

    } WHILE (FALSE);

    //
    // Program the hardware to add suport for these muticast addresses
    //

    DEBUGP(MP_TRACE, ("<-- NICSetMulticastList\n"));

    return(Status);

}

NDIS_STATUS
NICForwardRequest(
    IN PMP_ADAPTER                  Adapter,
    IN  PNDIS_OID_REQUEST           NdisRequest
    )
/*++

Routine Description:

    Utility routine that forwards an NDIS request made on a Adapter to the
    lower binding. Since at most a single request can be pended on a Adapter,
    we use the pre-allocated request structure embedded in the Adapter struct.

Arguments:


Return Value:

    NDIS_STATUS_SUCCESS if the request is sent down.

--*/
{
    PWORKITEM_CONTEXT   wdmNdisRequest;

    DEBUGP(MP_TRACE, ("--> NICForwardRequest\n"));

    wdmNdisRequest = GetWorkItemContext(Adapter->WorkItemForNdisRequest);

    wdmNdisRequest->Adapter = Adapter;
    wdmNdisRequest->Oid = NdisRequest->DATA.QUERY_INFORMATION.Oid;;
    wdmNdisRequest->RequestType = NdisRequest->RequestType;

    if (wdmNdisRequest->RequestType == NdisRequestQueryInformation ||
        wdmNdisRequest->RequestType == NdisRequestQueryStatistics ) {

        wdmNdisRequest->BytesReadOrWritten = (PULONG)&NdisRequest->DATA.QUERY_INFORMATION.BytesWritten;
        wdmNdisRequest->InformationBuffer = NdisRequest->DATA.QUERY_INFORMATION.InformationBuffer;
        wdmNdisRequest->InformationBufferLength = NdisRequest->DATA.QUERY_INFORMATION.InformationBufferLength;
        wdmNdisRequest->BytesNeeded = (PULONG)&NdisRequest->DATA.QUERY_INFORMATION.BytesNeeded;

    } else if (wdmNdisRequest->RequestType == NdisRequestSetInformation) {
        wdmNdisRequest->BytesReadOrWritten = (PULONG)&NdisRequest->DATA.SET_INFORMATION.BytesRead;
        wdmNdisRequest->InformationBuffer = NdisRequest->DATA.SET_INFORMATION.InformationBuffer;
        wdmNdisRequest->InformationBufferLength = NdisRequest->DATA.SET_INFORMATION.InformationBufferLength;
        wdmNdisRequest->BytesNeeded = (PULONG)&NdisRequest->DATA.SET_INFORMATION.BytesNeeded;
    } else {
        ASSERTMSG("Unknown RequestType ", FALSE);
        return NDIS_STATUS_NOT_SUPPORTED;
    }

    //
    // Save the request in the adapter context. This will
    // be cleared when the lower driver completes the ioctl request.
    //

    NdisAcquireSpinLock(&Adapter->Lock);

    ASSERT(Adapter->PendingOidNdisRequest == NULL);
    Adapter->PendingOidNdisRequest = NdisRequest;

    NdisReleaseSpinLock(&Adapter->Lock);

    WdfWorkItemEnqueue(Adapter->WorkItemForNdisRequest);

    DEBUGP(MP_TRACE, ("<-- NICForwardRequest\n"));

    return (NDIS_STATUS_SUCCESS);
}

VOID
NICRequestWorkItemCallback(
    WDFWORKITEM WorkItem
    )
{

    PMP_ADAPTER Adapter;
    PWORKITEM_CONTEXT wdmNdisRequest;
    NDIS_STATUS Status;
    BOOLEAN isResetPending = FALSE;
    PNDIS_OID_REQUEST pendingRequest;

    DEBUGP(MP_TRACE, ("--> NICRequestWorkItemCallback\n"));

    wdmNdisRequest = GetWorkItemContext(WorkItem);

    Adapter = wdmNdisRequest->Adapter;

    Status = NICSendOidRequest(Adapter,
                    wdmNdisRequest->RequestType,
                    wdmNdisRequest->Oid,
                    wdmNdisRequest->InformationBuffer,
                    wdmNdisRequest->InformationBufferLength,
                    wdmNdisRequest->BytesReadOrWritten,
                    wdmNdisRequest->BytesNeeded
                    );

    //
    // Make sure the multicast list reported by the physical doesn't exceed our
    // hardcoded limit of NIC_MAX_MCAST_LIST.
    //
    if (wdmNdisRequest->Oid == OID_802_3_MAXIMUM_LIST_SIZE){
        if (*(PLONG)wdmNdisRequest->InformationBuffer > NIC_MAX_MCAST_LIST) {
            *(PLONG)wdmNdisRequest->InformationBuffer = NIC_MAX_MCAST_LIST;
        }
    }

    //
    // Check to see if there is any pending reset. If so we should complet it
    // after completing the request.
    //
    NdisAcquireSpinLock(&Adapter->Lock);

    pendingRequest = Adapter->PendingOidNdisRequest;
    Adapter->PendingOidNdisRequest = NULL;

    if (Adapter->ResetPending){
        MP_CLEAR_FLAG(Adapter, fMP_RESET_IN_PROGRESS);
        Adapter->ResetPending = FALSE;
        isResetPending = TRUE;
    }

    NdisReleaseSpinLock(&Adapter->Lock);

    //
    // Inform NDIS to complete the pending request and reset.
    //
    NdisMOidRequestComplete(Adapter->AdapterHandle, pendingRequest, Status);

    //
    // NDIS will not send another OID request as long as a reset is pending.
    // So we don't have to worry about another requests sneeking in before
    // we complete the reset.
    //
    if (isResetPending){
        DEBUGP(MP_LOUD, ("Called NdisMResetComplete\n"));
        NdisMResetComplete(Adapter->AdapterHandle, NDIS_STATUS_SUCCESS, FALSE);
    }

    DEBUGP(MP_TRACE, ("<-- NICRequestWorkItemCallback: %x\n", Status));

    return;
}





NDIS_STATUS
NICSendOidRequest(
    IN PMP_ADAPTER                  Adapter,
    IN NDIS_REQUEST_TYPE            RequestType,
    IN NDIS_OID                     Oid,
    IN PVOID                        InformationBuffer,
    IN ULONG                        InformationBufferLength,
    OUT PULONG                      BytesReadOrWritten,
    OUT PULONG                      BytesNeeded
    )
/*++

Routine Description:

    Utility routine that forwards an NDIS request made on a Adapter to the
    target driver.

Arguments:


Return Value:


--*/
{
    NDIS_STATUS         Status;
    PNDISPROT_QUERY_OID pQueryOid = NULL;
    PNDISPROT_SET_OID   pSetOid = NULL;
    PVOID               buffer;
    NTSTATUS            ntStatus;
    ULONG               length, bytes=0;
    PREQUEST_CONTEXT    reqContext = NULL;

    DEBUGP(MP_TRACE, ("--> NICSendOidRequest\n"));


    PAGED_CODE();

    //
    // Calculate the size of the area to allocate
    //
    switch (RequestType) {

    case  NdisRequestQueryInformation :
    case  NdisRequestQueryStatistics  :
        length = sizeof(NDISPROT_QUERY_OID)  - sizeof(ULONG);
        ntStatus = RtlULongAdd(length, InformationBufferLength, &length);
        if (!NT_SUCCESS(ntStatus)) {
            return ntStatus;
        }
        break;

    case  NdisRequestSetInformation :
        length = sizeof(NDISPROT_SET_OID)  - sizeof(ULONG);
        ntStatus = RtlULongAdd(length, InformationBufferLength, &length);
        if (!NT_SUCCESS(ntStatus)) {
            return ntStatus;
        }

        break;

    default:
        DEBUGP(MP_ERROR, ("NICSendOidRequest Invalid RequestType 0x%X 0x%x\n",
                            RequestType, Oid));
        return NDIS_STATUS_NOT_SUPPORTED;
    }

    //
    // Allocate memory for adapter context
    //
    Status = NdisAllocateMemoryWithTag(&buffer, length, NIC_TAG);
    if (Status != NDIS_STATUS_SUCCESS)
    {
        DEBUGP(MP_ERROR, ("NICSendOidRequest failed to allocate memory\n"));
        Status = STATUS_INVALID_PARAMETER;
        goto End;
    }

    *BytesNeeded = 0;

    switch (RequestType)
    {
        case NdisRequestQueryInformation:
        case NdisRequestQueryStatistics:


            pQueryOid = (PNDISPROT_QUERY_OID) buffer;
            pQueryOid->Oid = Oid;

            ntStatus = NICSendOidRequestToTargetAsync(
                            Adapter->IoTarget,
                            Adapter->PendingOidWdfRequest,
                            Adapter->FileObject,
                            IOCTL_NDISPROT_QUERY_OID_VALUE,
                            pQueryOid,
                            length,
                            pQueryOid,
                            length,
                            &bytes
                            );
            if (!NT_SUCCESS(ntStatus)) {

                DEBUGP(MP_ERROR, ("NICMakeSynchronousIoctl failed %x\n",
                                    ntStatus));
                *BytesNeeded = bytes;

            } else {
                reqContext = GetRequestContext(Adapter->PendingOidWdfRequest);
                //
                // Reason for sending an asynchronouse request and doing a
                // ourself instead of just sending a synchronous request is
                // to allow cancellation of sent request when NDIS calls
                // MPCancelOidRequest.
                //
                NdisWaitEvent(&reqContext->Event, 0);
                NdisResetEvent(&reqContext->Event);

                *BytesReadOrWritten = bytes - FIELD_OFFSET(NDISPROT_QUERY_OID, Data);
                ASSERT(*BytesReadOrWritten <= InformationBufferLength);
                RtlCopyMemory(InformationBuffer, pQueryOid->Data,
                                        *BytesReadOrWritten);
            }

            NT_STATUS_TO_NDIS_STATUS(ntStatus, &Status);
            break;

        case NdisRequestSetInformation:

            pSetOid = (PNDISPROT_SET_OID) buffer;
            pSetOid->Oid = Oid;

            RtlCopyMemory(pSetOid->Data, InformationBuffer,
                                    InformationBufferLength);

            ntStatus = NICSendOidRequestToTargetAsync(
                            Adapter->IoTarget,
                            Adapter->PendingOidWdfRequest,
                            Adapter->FileObject,
                            IOCTL_NDISPROT_SET_OID_VALUE,
                            pSetOid,
                            length,
                            NULL,
                            0,
                            &bytes
                            );
            if (!NT_SUCCESS(ntStatus)) {

                DEBUGP(MP_ERROR, ("NICMakeSynchronousIoctl failed %x\n", ntStatus));
                *BytesNeeded = bytes;
            }else {
                //
                // Unfortunately, the NDISPROT driver returns 0 as the number of
                // bytes read. So let us just use the InformationBufferLength.
                //
                reqContext = GetRequestContext(Adapter->PendingOidWdfRequest);
                NdisWaitEvent(&reqContext->Event, 0);
                NdisResetEvent(&reqContext->Event);

                *BytesReadOrWritten = InformationBufferLength;
            }

            NT_STATUS_TO_NDIS_STATUS(ntStatus, &Status);
            break;

        default:
            ASSERT(FALSE);
            break;
    }

End:
    if (buffer){
        NdisFreeMemory(buffer, length, 0);
    }

    DEBUGP(MP_TRACE, ("<-- NICSendOidRequest %x\n", Status));

    return (Status);
}

NTSTATUS
NICSendOidRequestToTargetAsync(
    IN WDFIOTARGET          IoTarget,
    IN WDFREQUEST           Request,
    IN PFILE_OBJECT         FileObject,
    IN ULONG                IoctlControlCode,
    IN OUT PVOID            InputBuffer,
    IN ULONG                InputBufferLength,
    IN OUT PVOID            OutputBuffer,
    IN ULONG                OutputBufferLength,
    OUT PULONG              BytesReadOrWritten
    )
/*++

Routine Description:

    This routine sends a asynchronous ioctl request. It also assumes
    that InputBuffer and OutputBuffer pointers are non paged kernelmode
    bufferr addresses.

    This routine can be called at IRQL <= DISPATCH_LEVEL.

Arguments:

    TopOfDeviceStack    - Pointer to the target deviceobject

    IoctlControlCode    - Value of the IOCTL request

    InputBuffer        - Buffer to be sent to the TopOfDeviceStack

    InputBufferLength  - Size of buffer to be sent to the TopOfDeviceStack

    OutputBuffer       - Buffer for received data from the TopOfDeviceStack

    OutputBufferLength - Size of receive buffer from the TopOfDeviceStack

    BytesReadOrWritten - Number of bytes read or written

Return Value:

    NT status code

--*/
{
    NTSTATUS                status;
    PREQUEST_CONTEXT        reqContext;
    WDF_REQUEST_REUSE_PARAMS    params;
    WDFMEMORY               inputMem, outputMem;

    UNREFERENCED_PARAMETER(FileObject);

    //
    // Since we are reusing the same request, we need to do the
    // following.
    //
    WDF_REQUEST_REUSE_PARAMS_INIT(&params,
                            WDF_REQUEST_REUSE_NO_FLAGS,
                            STATUS_SUCCESS);

    status = WdfRequestReuse(Request, &params);
    if (!NT_SUCCESS(status)){
        DEBUGP(MP_ERROR, ("WdfRequestReuse failed 0x%x\n", status));
        return status;
    }


    reqContext = GetRequestContext(Request);

    //
    // Assign the new buffer in the preallocated memory objects
    //
    inputMem = outputMem = NULL;

    if (InputBuffer != NULL) {
        status = WdfMemoryAssignBuffer(reqContext->InputMemory,
                                    InputBuffer,
                                    InputBufferLength);
       if (!NT_SUCCESS(status)) {
            return status;
        }

        inputMem = reqContext->InputMemory;
    }

    if (OutputBuffer != NULL) {
        status = WdfMemoryAssignBuffer(reqContext->OutputMemory,
                                    OutputBuffer,
                                    OutputBufferLength);
       if (!NT_SUCCESS(status)) {
            return status;
        }
        outputMem = reqContext->OutputMemory;
    }

    status = WdfIoTargetFormatRequestForIoctl(
                                IoTarget,
                                Request,
                                IoctlControlCode,
                                inputMem,
                                NULL, // offsets
                                outputMem,
                                NULL); // OutputBufferOffset
   if (!NT_SUCCESS(status)) {
        DEBUGP(MP_ERROR, ("WdfIoTargetFormatRequestForIoctl failed 0x%x\n", status));
        return status;
    }

    WdfRequestSetCompletionRoutine(Request,
                               NICSendOidRequestToTargetAsyncCompletionRoutine,
                               BytesReadOrWritten);

    if (WdfRequestSend(Request, IoTarget, WDF_NO_SEND_OPTIONS) == FALSE) {
        DEBUGP(MP_ERROR, ("WdfRequestSend for sending OID failed 0x%x\n", status));
        status = WdfRequestGetStatus(Request);
    }

    return status;
}


VOID
NICSendOidRequestToTargetAsyncCompletionRoutine(
    IN WDFREQUEST                  Request,
    IN WDFIOTARGET                 Target,
    PWDF_REQUEST_COMPLETION_PARAMS CompletionParams,
    IN WDFCONTEXT                  Context
    )
/*++

Routine Description:

    Get the number of bytes transfered and signal the event to
    let the workitem that sent this request to continue.

Arguments:

    Adapter     Pointer to our adapter

Return Value:

    NT status code

--*/
{
    NTSTATUS status;
    PREQUEST_CONTEXT        reqContext;

    UNREFERENCED_PARAMETER(Target);

    reqContext = GetRequestContext(Request);

    DEBUGP(MP_TRACE, ("--> NICSendOidRequestToTargetAsyncCompletionRoutine\n"));

    status = CompletionParams->IoStatus.Status;

    if (!NT_SUCCESS(status)) {
        DEBUGP (MP_ERROR, ("NICSendOidRequestToTarget failed %x, %d \n",
                status,
                CompletionParams->IoStatus.Information));
    }

    *((PULONG)Context) = (ULONG)CompletionParams->IoStatus.Information;

    NdisSetEvent(&reqContext->Event);

}

VOID
MPCancelOidRequest(
    IN  NDIS_HANDLE            MiniportAdapterContext,
    IN  PVOID                  RequestId
    )
/*++
Routine Description:

    An NDIS 6.0 miniport driver must provide a MiniportCancelOidRequest
    function if it pends any OID request. MiniportCancelOidRequest
    is called when NDIS or an overlying driver calls NdisCancelOidRequest
    or NdisFCancelOidRequest. If the miniport driver finds the OID
    request to be cancelled in its queue, it should complete the OID request
    by calling NdisMOidRequestComplete with NDIS_STATUS_REQUEST_ABORTED.

Arguments:

    MiniportAdapterContext  Pointer to the adapter structure
    RequestId               Specify the request to be cancelled.

Return Value:

--*/
{
    PMP_ADAPTER         Adapter = (PMP_ADAPTER) MiniportAdapterContext;

    DEBUGP(MP_TRACE, ("---> MPCancelOidRequest\n"));

    NdisAcquireSpinLock(&Adapter->Lock);

    if (Adapter->PendingOidNdisRequest != NULL
            && Adapter->PendingOidNdisRequest->RequestId == RequestId)
    {
        //
        // Cancel the PendingOidWdfRequest. It's safe to call
        // WdfRequestCancelSentRequest even if it's not already sent.
        //
        DEBUGP(MP_INFO, ("  Calling WdfRequestCancelSentRequest\n"));
        WdfRequestCancelSentRequest(Adapter->PendingOidWdfRequest);
    }

    NdisReleaseSpinLock(&Adapter->Lock);

    DEBUGP(MP_TRACE, ("<--- MPCancelOidRequest\n"));

}

NDIS_STATUS
NICSetAttributes(
    PMP_ADAPTER Adapter
    )
/*++
Routine Description:

    An NDIS 6.0 miniport driver must call NdisMSetMiniportAttributes
    at least twice. The first call is to register itself with NDIS.
    The second call is to register the miniport driver's general
    attributes with NDIS.

    NdisMSetMiniportAttributes takes a parameter of type
    NDIS_MINIPORT_ADAPTER_ATTRIBUTES, which is a union of several miniport
    adapter attributes. Miniport drivers must first call
    NdisMSetMiniportAttributes and pass in an
    NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES structure
    that contains the pointer to its own context area, attribute flags,
    check-for-hang time, and interface type.

    All NDIS 6.0 miniport drivers are deserialized by default.

Arguments:


Return Value:

--*/
{
    NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES   RegistrationAttributes;
    NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES        GeneralAttributes;
    NDIS_PNP_CAPABILITIES          PowerManagementCapabilities;
    NTSTATUS Status;
    ULONG               unUsed;

    NdisZeroMemory(&RegistrationAttributes,
                    sizeof(NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES));
    //
    // setting registration attributes
    //
    RegistrationAttributes.Header.Type =
                NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES;
    RegistrationAttributes.Header.Revision =
                NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES_REVISION_1;
    RegistrationAttributes.Header.Size =
                sizeof(NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES);

    RegistrationAttributes.MiniportAdapterContext = (NDIS_HANDLE)Adapter;
    RegistrationAttributes.AttributeFlags =
                            NDIS_MINIPORT_ATTRIBUTES_HARDWARE_DEVICE;

    RegistrationAttributes.CheckForHangTimeInSeconds = 2;
    RegistrationAttributes.InterfaceType = NdisInterfacePci;

    Status = NdisMSetMiniportAttributes(Adapter->AdapterHandle,
                    (PNDIS_MINIPORT_ADAPTER_ATTRIBUTES)&RegistrationAttributes);

    if (Status != NDIS_STATUS_SUCCESS)
    {
        DEBUGP(MP_ERROR, ("NdisMSetMiniportAttributes failed %x\n", Status));
        return Status;
    }

    //
    // set up generic attributes
    //
    NdisZeroMemory(&GeneralAttributes,
                    sizeof(NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES));

    GeneralAttributes.Header.Type =
                        NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES;
    GeneralAttributes.Header.Revision =
                        NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES_REVISION_1;
    GeneralAttributes.Header.Size =
                        sizeof(NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES);

    GeneralAttributes.MediaType = NIC_MEDIA_TYPE;

    GeneralAttributes.MtuSize = ETH_MAX_PACKET_SIZE - ETH_HEADER_SIZE;
    GeneralAttributes.MaxXmitLinkSpeed = NIC_LINK_SPEED;
    GeneralAttributes.MaxRcvLinkSpeed = NIC_LINK_SPEED;
    GeneralAttributes.XmitLinkSpeed = NDIS_LINK_SPEED_UNKNOWN;
    GeneralAttributes.RcvLinkSpeed = NDIS_LINK_SPEED_UNKNOWN;
    GeneralAttributes.MediaConnectState = MediaConnectStateConnected;
    GeneralAttributes.MediaDuplexState = MediaDuplexStateUnknown;
    GeneralAttributes.LookaheadSize = ETH_MAX_PACKET_SIZE - ETH_HEADER_SIZE;

    Status = NICSendOidRequest(Adapter,
                        NdisRequestQueryInformation,
                        OID_PNP_CAPABILITIES,
                        &PowerManagementCapabilities,
                        sizeof(NDIS_PNP_CAPABILITIES),
                        &unUsed,
                        &unUsed
                        );
    if (NT_SUCCESS(Status)) {
        GeneralAttributes.PowerManagementCapabilities = &PowerManagementCapabilities;
    } else {
        GeneralAttributes.PowerManagementCapabilities = NULL;
    }

    //
    // do not fail the call because of failure to get PM caps
    //
    Status = NDIS_STATUS_SUCCESS;

    GeneralAttributes.MacOptions = NDIS_MAC_OPTION_COPY_LOOKAHEAD_DATA |
                                   NDIS_MAC_OPTION_TRANSFERS_NOT_PEND |
                                   NDIS_MAC_OPTION_NO_LOOPBACK;

    GeneralAttributes.SupportedPacketFilters = NIC_SUPPORTED_FILTERS;

    GeneralAttributes.MaxMulticastListSize = NIC_MAX_MCAST_LIST;
    GeneralAttributes.MacAddressLength = ETH_LENGTH_OF_ADDRESS;
    NdisMoveMemory(GeneralAttributes.PermanentMacAddress,
                   Adapter->PermanentAddress,
                   ETH_LENGTH_OF_ADDRESS);

    NdisMoveMemory(GeneralAttributes.CurrentMacAddress,
                   Adapter->CurrentAddress,
                   ETH_LENGTH_OF_ADDRESS);


    GeneralAttributes.PhysicalMediumType = NdisPhysicalMediumUnspecified;
    GeneralAttributes.RecvScaleCapabilities = NULL;
    GeneralAttributes.AccessType = NET_IF_ACCESS_BROADCAST; // NET_IF_ACCESS_BROADCAST for a typical ethernet adapter
    GeneralAttributes.DirectionType = NET_IF_DIRECTION_SENDRECEIVE; // NET_IF_DIRECTION_SENDRECEIVE for a typical ethernet adapter
    GeneralAttributes.ConnectionType = NET_IF_CONNECTION_DEDICATED;  // NET_IF_CONNECTION_DEDICATED for a typical ethernet adapter
    GeneralAttributes.IfType = IF_TYPE_ETHERNET_CSMACD; // IF_TYPE_ETHERNET_CSMACD for a typical ethernet adapter (regardless of speed)
    GeneralAttributes.IfConnectorPresent = TRUE; // RFC 2665 TRUE if physical adapter

    GeneralAttributes.SupportedStatistics =
                                NDIS_STATISTICS_XMIT_OK_SUPPORTED |
                                NDIS_STATISTICS_RCV_OK_SUPPORTED |
                                NDIS_STATISTICS_XMIT_ERROR_SUPPORTED |
                                NDIS_STATISTICS_RCV_ERROR_SUPPORTED |
                                NDIS_STATISTICS_RCV_CRC_ERROR_SUPPORTED |
                                NDIS_STATISTICS_RCV_NO_BUFFER_SUPPORTED |
                                NDIS_STATISTICS_TRANSMIT_QUEUE_LENGTH_SUPPORTED;

    GeneralAttributes.SupportedOidList = NICSupportedOids;
    GeneralAttributes.SupportedOidListLength = sizeof(NICSupportedOids);

    Status = NdisMSetMiniportAttributes(Adapter->AdapterHandle,
                        (PNDIS_MINIPORT_ADAPTER_ATTRIBUTES)&GeneralAttributes);

    if (Status != NDIS_STATUS_SUCCESS)
    {
        DEBUGP(MP_ERROR, ("NdisMSetMiniportAttributes failed %x\n", Status));
        return Status;
    }

    return Status;

}

#define OID_TCP4_OFFLOAD_STATS                  0xFC010207
#define OID_TCP6_OFFLOAD_STATS                  0xFC010208
#define OID_IP4_OFFLOAD_STATS                   0xFC010209
#define OID_IP6_OFFLOAD_STATS                   0xFC01020A

PCHAR
DbgGetOidName(ULONG oid)
{
    PCHAR oidName;
    static char tempBuf[50];

    switch (oid){

        #undef MAKECASE
        #define MAKECASE(oidx) case oidx: oidName = #oidx; break;

        MAKECASE(OID_GEN_SUPPORTED_LIST)
        MAKECASE(OID_GEN_HARDWARE_STATUS)
        MAKECASE(OID_GEN_MEDIA_SUPPORTED)
        MAKECASE(OID_GEN_MEDIA_IN_USE)
        MAKECASE(OID_GEN_MAXIMUM_LOOKAHEAD)
        MAKECASE(OID_GEN_MAXIMUM_FRAME_SIZE)
        MAKECASE(OID_GEN_LINK_SPEED)
        MAKECASE(OID_GEN_TRANSMIT_BUFFER_SPACE)
        MAKECASE(OID_GEN_RECEIVE_BUFFER_SPACE)
        MAKECASE(OID_GEN_TRANSMIT_BLOCK_SIZE)
        MAKECASE(OID_GEN_RECEIVE_BLOCK_SIZE)
        MAKECASE(OID_GEN_VENDOR_ID)
        MAKECASE(OID_GEN_VENDOR_DESCRIPTION)
        MAKECASE(OID_GEN_CURRENT_PACKET_FILTER)
        MAKECASE(OID_GEN_CURRENT_LOOKAHEAD)
        MAKECASE(OID_GEN_DRIVER_VERSION)
        MAKECASE(OID_GEN_MAXIMUM_TOTAL_SIZE)
        MAKECASE(OID_GEN_PROTOCOL_OPTIONS)
        MAKECASE(OID_GEN_MAC_OPTIONS)
        MAKECASE(OID_GEN_MEDIA_CONNECT_STATUS)
        MAKECASE(OID_GEN_MAXIMUM_SEND_PACKETS)
        MAKECASE(OID_GEN_VENDOR_DRIVER_VERSION)
        MAKECASE(OID_GEN_SUPPORTED_GUIDS)
        MAKECASE(OID_GEN_NETWORK_LAYER_ADDRESSES)
        MAKECASE(OID_GEN_TRANSPORT_HEADER_OFFSET)
        MAKECASE(OID_GEN_MEDIA_CAPABILITIES)
        MAKECASE(OID_GEN_PHYSICAL_MEDIUM)
        MAKECASE(OID_GEN_XMIT_OK)
        MAKECASE(OID_GEN_RCV_OK)
        MAKECASE(OID_GEN_XMIT_ERROR)
        MAKECASE(OID_GEN_RCV_ERROR)
        MAKECASE(OID_GEN_RCV_NO_BUFFER)
        MAKECASE(OID_GEN_DIRECTED_BYTES_XMIT)
        MAKECASE(OID_GEN_DIRECTED_FRAMES_XMIT)
        MAKECASE(OID_GEN_MULTICAST_BYTES_XMIT)
        MAKECASE(OID_GEN_MULTICAST_FRAMES_XMIT)
        MAKECASE(OID_GEN_BROADCAST_BYTES_XMIT)
        MAKECASE(OID_GEN_BROADCAST_FRAMES_XMIT)
        MAKECASE(OID_GEN_DIRECTED_BYTES_RCV)
        MAKECASE(OID_GEN_DIRECTED_FRAMES_RCV)
        MAKECASE(OID_GEN_MULTICAST_BYTES_RCV)
        MAKECASE(OID_GEN_MULTICAST_FRAMES_RCV)
        MAKECASE(OID_GEN_BROADCAST_BYTES_RCV)
        MAKECASE(OID_GEN_BROADCAST_FRAMES_RCV)
        MAKECASE(OID_GEN_RCV_CRC_ERROR)
        MAKECASE(OID_GEN_TRANSMIT_QUEUE_LENGTH)
        MAKECASE(OID_GEN_GET_TIME_CAPS)
        MAKECASE(OID_GEN_GET_NETCARD_TIME)
        MAKECASE(OID_GEN_NETCARD_LOAD)
        MAKECASE(OID_GEN_DEVICE_PROFILE)
        MAKECASE(OID_GEN_INIT_TIME_MS)
        MAKECASE(OID_GEN_RESET_COUNTS)
        MAKECASE(OID_GEN_MEDIA_SENSE_COUNTS)
        MAKECASE(OID_PNP_CAPABILITIES)
        MAKECASE(OID_PNP_SET_POWER)
        MAKECASE(OID_PNP_QUERY_POWER)
        MAKECASE(OID_PNP_ADD_WAKE_UP_PATTERN)
        MAKECASE(OID_PNP_REMOVE_WAKE_UP_PATTERN)
        MAKECASE(OID_PNP_ENABLE_WAKE_UP)
        MAKECASE(OID_802_3_PERMANENT_ADDRESS)
        MAKECASE(OID_802_3_CURRENT_ADDRESS)
        MAKECASE(OID_802_3_MULTICAST_LIST)
        MAKECASE(OID_802_3_MAXIMUM_LIST_SIZE)
        MAKECASE(OID_802_3_MAC_OPTIONS)
        MAKECASE(OID_802_3_RCV_ERROR_ALIGNMENT)
        MAKECASE(OID_802_3_XMIT_ONE_COLLISION)
        MAKECASE(OID_802_3_XMIT_MORE_COLLISIONS)
        MAKECASE(OID_802_3_XMIT_DEFERRED)
        MAKECASE(OID_802_3_XMIT_MAX_COLLISIONS)
        MAKECASE(OID_802_3_RCV_OVERRUN)
        MAKECASE(OID_802_3_XMIT_UNDERRUN)
        MAKECASE(OID_802_3_XMIT_HEARTBEAT_FAILURE)
        MAKECASE(OID_802_3_XMIT_TIMES_CRS_LOST)
        MAKECASE(OID_802_3_XMIT_LATE_COLLISIONS)
        MAKECASE(OID_GEN_MACHINE_NAME)
        MAKECASE(OID_GEN_STATISTICS)
        MAKECASE(OID_IP4_OFFLOAD_STATS)
        MAKECASE(OID_IP6_OFFLOAD_STATS)
        MAKECASE(OID_TCP4_OFFLOAD_STATS)
        MAKECASE(OID_TCP6_OFFLOAD_STATS)
        default:
            RtlStringCchPrintfA(tempBuf, sizeof(tempBuf), "<** UNKNOWN OID **> 0x%x", oid);
            oidName = tempBuf;
            break;
    }

    return oidName;
}




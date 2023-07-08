/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

Module Name:

   ndiswdm.H

Abstract:
    This module contains structure definitons and function prototypes.

--*/


#ifndef _NDISWDM_H
#define _NDISWDM_H

#pragma warning(disable:4201)  // nameless struct/union warning
#pragma warning(disable:4214)  // bit field types other than int warning

#define WIN9X_COMPAT_SPINLOCK

#include <ndis.h>

//#pragma warning(default:4201)
//#pragma warning(default:4214)

#include <wdf.h>
#include <WdfMiniport.h>

#include "nuiouser.h"
//
// To use strsafe function on 9x, ME, and Win2K Oses, we
// have to define NTSTRSAFE_LIB before including this header file and explicitly
// link to ntstrsafe.lib. If your driver is just target for XP and above, there is
// no need to define NTSTRSAFE_LIB and link to the lib.
//
#define NTSTRSAFE_LIB
#include <ntstrsafe.h>
#include <ntintsafe.h>

#pragma warning(disable:4127) // conditional expression
#pragma warning(disable: 4213)// nonstandard extension used : cast on l-value

#define MP_NDIS_MAJOR_VERSION       6
#define MP_NDIS_MINOR_VERSION       0

#define NIC_MAJOR_DRIVER_VERSION        0x02
#define NIC_MINOR_DRIVER_VERISON        0x00

//-----------------------------------------------------------------------------
// 4127 -- Conditional Expression is Constant warning
//-----------------------------------------------------------------------------
#define WHILE(constant) \
__pragma(warning(disable: 4127)) while(constant); __pragma(warning(default: 4127))


#define NIC_TAG                             ((ULONG)'MDWN')

// media type, we use ethernet, change if necessary
#define NIC_MEDIA_TYPE                    NdisMedium802_3

// we use Internal, change to Pci, Isa, etc. properly
#define NIC_INTERFACE_TYPE                NdisInterfaceInternal

//
// Update the driver version number every time you release a new driver
// The high byte is the major version. The low byte is the minor version.
// Also make sure that VER_FILEVERSION specified in the .RC file also
// matches with the driver version because NDISTESTER checks for that.
//
#define NIC_VENDOR_DRIVER_VERSION    ((NIC_MAJOR_DRIVER_VERSION << 16) | NIC_MINOR_DRIVER_VERISON)


// change to your company name instead of using Microsoft
#define NIC_VENDOR_DESC                 "Microsoft"

// Highest byte is the NIC byte plus three vendor bytes, they are normally
// obtained from the NIC
#define NIC_VENDOR_ID                    0x00FFFFFF

#define PROTOCOL_INTERFACE_NAME L"\\??\\NdisProt"

typedef UCHAR   NIC_MAC_ADDRESS[6];

#define     ETH_HEADER_SIZE             14
#define     ETH_MAX_DATA_SIZE           1500
#define     ETH_MAX_PACKET_SIZE         ETH_HEADER_SIZE + ETH_MAX_DATA_SIZE
#define     ETH_MIN_PACKET_SIZE         60


#define ETH_IS_LOCALLY_ADMINISTERED(Address) \
                (BOOLEAN)(((PUCHAR)(Address))[0] & ((UCHAR)0x02))

#define NIC_MAX_MCAST_LIST              32
#define NIC_MAX_BUSY_SENDS              64
#define NIC_MAX_SEND_PKTS               5
#define NIC_MAX_BUSY_RECVS              64
#define NIC_MAX_LOOKAHEAD               ETH_MAX_DATA_SIZE
#define NIC_BUFFER_SIZE                 ETH_MAX_PACKET_SIZE
#define NIC_LINK_SPEED                  500000    // in 100 bps
#define NIC_SEND_LOW_WATERMARK         NIC_MAX_BUSY_SENDS/4
#define NIC_ADAPTER_NAME_SIZE          128

//
// Buffer size passed in NdisMQueryAdapterResources
// We should only need three adapter resources (IO, interrupt and memory),
// Some devices get extra resources, so have room for 10 resources
//
#define NIC_RESOURCE_BUF_SIZE           (sizeof(NDIS_RESOURCE_LIST) + \
                                        (10*sizeof(CM_PARTIAL_RESOURCE_DESCRIPTOR)))

#define NIC_SUPPORTED_FILTERS ( \
                NDIS_PACKET_TYPE_DIRECTED   | \
                NDIS_PACKET_TYPE_MULTICAST  | \
                NDIS_PACKET_TYPE_BROADCAST  | \
                NDIS_PACKET_TYPE_PROMISCUOUS | \
                NDIS_PACKET_TYPE_ALL_MULTICAST)

#define fMP_RESET_IN_PROGRESS               0x00000001
#define fMP_DISCONNECTED                    0x00000002
#define fMP_HALT_IN_PROGRESS                0x00000004
#define fMP_SURPRISE_REMOVED                0x00000008
#define fMP_RECV_LOOKASIDE                  0x00000010
#define fMP_INIT_IN_PROGRESS                0x00000020
#define fMP_SEND_SIDE_RESOURCE_ALLOCATED    0x00000040
#define fMP_RECV_SIDE_RESOURCE_ALLOCATED    0x00000080
#define fMP_POST_READS                      0x00000100
#define fMP_POST_WRITES                     0x00000200

//
// Message verbosity: lower values indicate higher urgency
//
#define MP_VERY_LOUD    5
#define MP_LOUD    4
#define MP_TRACE   3
#define MP_INFO    2
#define MP_WARNING 1
#define MP_ERROR   0

extern INT MPDebugLevel;

#if DBG
#define DEBUGP(Level, Fmt) \
{ \
    if (Level <= MPDebugLevel) \
    { \
        DbgPrint("NDISWDM.SYS:"); \
        DbgPrint Fmt; \
    } \
}
#else
#define DEBUGP(Level, Fmt)
#endif


#ifndef min
#define    min(_a, _b)      (((_a) < (_b)) ? (_a) : (_b))
#endif

#ifndef max
#define    max(_a, _b)      (((_a) > (_b)) ? (_a) : (_b))
#endif

//--------------------------------------
// Utility macros
//--------------------------------------

#define MP_SET_FLAG(_M, _F)      ((_M)->Flags |= (_F))
#define MP_CLEAR_FLAG(_M, _F)    ((_M)->Flags &= ~(_F))
#define MP_TEST_FLAG(_M, _F)     ((((_M)->Flags & (_F)) != 0)?TRUE:FALSE)
#define MP_TEST_FLAGS(_M, _F)    ((((_M)->Flags & (_F)) == (_F))?TRUE:FALSE)

#define MP_IS_READY(_M)  (((_M)->Flags & \
         (fMP_DISCONNECTED | fMP_RESET_IN_PROGRESS | fMP_HALT_IN_PROGRESS | fMP_INIT_IN_PROGRESS | fMP_SURPRISE_REMOVED)) == 0)

#define MP_INC_REF(_A)  NdisInterlockedIncrement(&(_A)->RefCount)

#define MP_DEC_REF(_A) {\
                            NdisInterlockedDecrement(&(_A)->RefCount);\
                            ASSERT(_A->RefCount >= 0);\
                            if((_A)->RefCount == 0){\
                                NdisSetEvent(&(_A)->HaltEvent);\
                            }\
                        }


#define MP_GET_REF(_A)    ((_A)->RefCount)

//
// Take advantage of dispatch level
//
FORCEINLINE
VOID
MP_ACQUIRE_SPIN_LOCK(
    IN PNDIS_SPIN_LOCK Lock,
    IN BOOLEAN DispatchLevel
    )
{
    if (DispatchLevel)
    {
        NdisDprAcquireSpinLock(Lock);
    }
    else
    {
        NdisAcquireSpinLock(Lock);
    }
}

FORCEINLINE
VOID
MP_RELEASE_SPIN_LOCK(
    IN PNDIS_SPIN_LOCK Lock,
    IN BOOLEAN DispatchLevel
    )
{
    if (DispatchLevel)
    {
        NdisDprReleaseSpinLock(Lock);
    }
    else
    {
        NdisReleaseSpinLock(Lock);
    }
}


//
// Define 4 macros to get some fields in NetBufferList for miniport's own use
//
#define MP_GET_NET_BUFFER_LIST_LINK(_NetBufferList)       (&(NET_BUFFER_LIST_NEXT_NBL(_NetBufferList)))
#define MP_GET_NET_BUFFER_LIST_NEXT_SEND(_NetBufferList)  ((_NetBufferList)->MiniportReserved[0])
#define MP_GET_NET_BUFFER_LIST_REF_COUNT(_NetBufferList)  ((ULONG)(ULONG_PTR)((_NetBufferList)->MiniportReserved[1]))

#define MP_GET_NET_BUFFER_PREV(_NetBuffer)      ((_NetBuffer)->MiniportReserved[0])
#define MP_GET_NET_BUFFER_LIST_FROM_LIST_ENTRY(_pEntry)  \
    (CONTAINING_RECORD((_pEntry), NET_BUFFER_LIST, Next))


#define MP_INIT_NDIS_STATUS_INDICATION(_pStatusIndication, _M, _St, _Buf, _BufSize)        \
    {                                                                                      \
        NdisZeroMemory(_pStatusIndication, sizeof(NDIS_STATUS_INDICATION));                \
        (_pStatusIndication)->Header.Type = NDIS_OBJECT_TYPE_STATUS_INDICATION;            \
        (_pStatusIndication)->Header.Revision = NDIS_STATUS_INDICATION_REVISION_1;         \
        (_pStatusIndication)->Header.Size = sizeof(NDIS_STATUS_INDICATION);                \
        (_pStatusIndication)->SourceHandle = _M;                                           \
        (_pStatusIndication)->StatusCode = _St;                                            \
        (_pStatusIndication)->StatusBuffer = _Buf;                                         \
        (_pStatusIndication)->StatusBufferSize = _BufSize;                                 \
    }

#include <pshpack1.h>

typedef struct _ETH_HEADER
{
    UCHAR       DstAddr[ETH_LENGTH_OF_ADDRESS];
    UCHAR       SrcAddr[ETH_LENGTH_OF_ADDRESS];
    USHORT      EthType;
} ETH_HEADER, *PETH_HEADER;

#include <poppack.h>

typedef enum _WHICH_MDL
{
    INVALID_MDL = 0,
    DATA_MDL,
    PARTIAL_MDL
} WHICH_MDL;

// TCB (Transmit Control Block)
typedef struct _TCB
{
    LIST_ENTRY              List; // This must be the first entry
    LONG                    Ref;
    PVOID                   Adapter;
    WDFREQUEST              Request;
    PMDL                    DataMdl; // Mdl representing the Data[] buffer below
    PMDL                    PartialMdl; // Mdl used in the request
    WHICH_MDL               WhichMdl; // WhichMdl to use for transfer
    PNET_BUFFER             NetBuffer;
    PNET_BUFFER_LIST        NetBufferList;
    ULONG                   ulSize;
    UCHAR                   Data[NIC_BUFFER_SIZE];
} TCB, *PTCB;

// RCB (Receive Control Block)
typedef struct _RCB
{
    LIST_ENTRY              List; // This must be the first entry
    LONG                    Ref;
    PVOID                   Adapter;
    WDFREQUEST              Request;
    PMDL                    Mdl;
    PNET_BUFFER             NetBuffer;
    PNET_BUFFER_LIST        NetBufferList;
    ULONG                   ulSize;
    UCHAR                   Data[NIC_BUFFER_SIZE];
} RCB, *PRCB;

#define MP_SET_RCB_IN_NBL(_NBL,_RCB)  (*((PRCB*)&NET_BUFFER_LIST_MINIPORT_RESERVED(_NBL)) = _RCB)
#define MP_GET_RCB_FROM_NBL(_NBL)      (*((PRCB*)&NET_BUFFER_LIST_MINIPORT_RESERVED(_NBL)))

typedef enum _NIC_STATE
{
    NicPaused,
    NicPausing,
    NicRunning
} NIC_STATE;

extern NDIS_OID NICSupportedOids[];

typedef struct _MP_ADAPTER
{
    LONG                    RefCount;
    NDIS_SPIN_LOCK          Lock;
    NDIS_EVENT              InitEvent;
    NDIS_EVENT              HaltEvent;
    NIC_STATE               AdapterState;
    //
    // Keep track of various device objects.
    //
    PDEVICE_OBJECT          Pdo;
    PDEVICE_OBJECT          Fdo;
    PDEVICE_OBJECT          NextDeviceObject;
    WDFDEVICE               WdfDevice;
    NDIS_HANDLE             AdapterHandle;
    WCHAR                   AdapterName[NIC_ADAPTER_NAME_SIZE];
    WCHAR                   AdapterDesc[NIC_ADAPTER_NAME_SIZE];

    union {
        ULONG                   Flags;
        //
        // Each field in this struct correspond to ascending #define fMP_XXX
        // values. Don't touch these fields directly. It's there for
        // debugging purposes.
        //
        struct {
            ULONG ResetInProgess : 1;
            ULONG Disconnected : 1;
            ULONG HaltInProgress : 1;
            ULONG SurpriseRemoved: 1;
            ULONG RecvLookAside : 1;
            ULONG InitInProgess : 1;
            ULONG SendResourcesAllocated : 1;
            ULONG RecvResourcesAllocated : 1;
            ULONG PostReads : 1;
            ULONG PostWrites : 1;
            ULONG Unused : 23;
        } FlagsByName;
    };

    UCHAR                   PermanentAddress[ETH_LENGTH_OF_ADDRESS];
    UCHAR                   CurrentAddress[ETH_LENGTH_OF_ADDRESS];
    WDFWORKITEM             WorkItemForNdisRequest;
    BOOLEAN                 Promiscuous;
    PNDIS_OID_REQUEST       PendingOidNdisRequest;
    WDFREQUEST              PendingOidWdfRequest; // Request used to send oid to the target
    BOOLEAN                 ResetPending;
    BOOLEAN                 IsTargetSupportChainedMdls;
    //
    // Variables to track resources for the send operation
    //
    LIST_ENTRY              SendFreeList; // Available for Send
    LIST_ENTRY              SendWaitList; // Waiting to be sent
    LIST_ENTRY              SendBusyList; // Already sent to the target
    PUCHAR                  TCBMem;
    LONG                    nBusySend;    // Number of requests Sent
    LONG                    nWaitSend;    // Number of request waiting to be sent
    NDIS_SPIN_LOCK          SendLock;     // Locks that protects all the Send List
    PNET_BUFFER_LIST        SendingNetBufferList; // Current being sent
    PNET_BUFFER             PendingNetBuffer; // Next net buffer to be sent from above list

    //
    // Variables to track resources for the Receive operation
    //
    LIST_ENTRY              RecvFreeList; // Available for receiving data from the nic
    LIST_ENTRY              RecvBusyList; // List of requests current posted to recv data
    NDIS_SPIN_LOCK          RecvLock; // Lock to protect the above two list
    LONG                    nBusyRecv; // Number of requests currently in use -
    NDIS_HANDLE             RecvNetBufferListPool;
    NDIS_HANDLE             RecvNetBufferPool;
    PUCHAR                  RCBMem;
    WDFWORKITEM             ReadWorkItem;
    WDFWORKITEM             ExecutiveCallbackWorkItem;
    LONG                    IsReadWorkItemQueued;
    LONG                    nIndicatedNetBufferList; // Number of NetBufferList indicated above

    //
    // Packet Filter and look ahead size.
    //
    ULONG                   PacketFilter;
    ULONG                   ulLookAhead;
    ULONG                   ulLinkSpeed;

    // multicast list
    ULONG                   ulMCListSize;
    UCHAR                   MCList[NIC_MAX_MCAST_LIST][ETH_LENGTH_OF_ADDRESS];

    // Packet counts
    ULONG64                 GoodTransmits;
    ULONG64                 GoodReceives;
    ULONG                   NumTxSinceLastAdjust;
    ULONG64                 InUcastPkts;
    ULONG64                 InUcastOctets;
    ULONG64                 InMulticastPkts;
    ULONG64                 InMulticastOctets;
    ULONG64                 InBroadcastPkts;
    ULONG64                 InBroadcastOctets;
    ULONG64                 OutUCastPkts;
    ULONG64                 OutUCastOctets;
    ULONG64                 OutMulticastPkts;
    ULONG64                 OutMulticastOctets;
    ULONG64                 OutBroadcastPkts;
    ULONG64                 OutBroadcastOctets;

    // Count of transmit errors
    ULONG                   TxAbortExcessCollisions;
    ULONG                   TxLateCollisions;
    ULONG                   TxDmaUnderrun;
    ULONG                   TxLostCRS;
    ULONG                   TxOKButDeferred;
    ULONG                   OneRetry;
    ULONG                   MoreThanOneRetry;
    ULONG                   TotalRetries;
    ULONG                   TransmitFailuresOther;

    // Count of receive errors
    ULONG                   RcvCrcErrors;
    ULONG                   RcvAlignmentErrors;
    ULONG                   RcvResourceErrors;
    ULONG                   RcvDmaOverrunErrors;
    ULONG                   RcvCdtFrames;
    ULONG                   RcvRuntErrors;

    //
    // Talking to NDISPROT protocol
    //
    HANDLE                  FileHandle;
    PFILE_OBJECT            FileObject;
    WDFIOTARGET             IoTarget;
    UCHAR                   PhyNicMacAddress[ETH_LENGTH_OF_ADDRESS];
    PCALLBACK_OBJECT        CallbackObject;
    PVOID                   CallbackRegisterationHandle;
    WDFREQUEST              StatusIndicationRequest;
    NDISPROT_INDICATE_STATUS NdisProtIndicateStatus;
    WDFMEMORY               WdfStatusIndicationBuffer;
    //
    // Statistic for debugging & validation purposes
    //
    ULONG                   nReadsPosted;
    ULONG                   nReadsCompletedWithError;
    ULONG                   nBytesRead;
    ULONG                   nPacketsArrived;
    ULONG                   nWritesPosted;
    ULONG                   nWritesCompletedWithError;
    ULONG                   nBytesArrived;
    ULONG                   nBytesWritten;
    ULONG                   nReadWorkItemScheduled;
} MP_ADAPTER, *PMP_ADAPTER;


typedef struct _WDF_DEVICE_INFO{

    PMP_ADAPTER Adapter;

} WDF_DEVICE_INFO, *PWDF_DEVICE_INFO;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(WDF_DEVICE_INFO, GetWdfDeviceInfo)

//
// This structure is used to send requests to the WDM
// driver at PASSIVE_LEVEL.
//
typedef struct _WORKITEM_CONTEXT
{
    PMP_ADAPTER         Adapter;
    NDIS_OID            Oid;
    NDIS_REQUEST_TYPE   RequestType;
    PVOID               InformationBuffer;
    ULONG               InformationBufferLength;
    PULONG              BytesReadOrWritten;
    PULONG              BytesNeeded;

} WORKITEM_CONTEXT, *PWORKITEM_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(WORKITEM_CONTEXT,
                                    GetWorkItemContext)

//
// This structure is used to send requests to the WDM
// driver at PASSIVE_LEVEL.
//
typedef struct _REQUEST_CONTEXT
{
    WDFMEMORY           InputMemory;
    WDFMEMORY           OutputMemory;
    NDIS_EVENT          Event;

} REQUEST_CONTEXT, *PREQUEST_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(REQUEST_CONTEXT,
                                    GetRequestContext)


#define NDIS_STATUS_TO_NT_STATUS(_NdisStatus, _pNtStatus)                           \
{                                                                                   \
    /*                                                                              \
     *  The following NDIS status codes map directly to NT status codes.            \
     */                                                                             \
    if (((NDIS_STATUS_SUCCESS == (_NdisStatus)) ||                                  \
        (NDIS_STATUS_PENDING == (_NdisStatus)) ||                                   \
        (NDIS_STATUS_BUFFER_OVERFLOW == (_NdisStatus)) ||                           \
        (NDIS_STATUS_FAILURE == (_NdisStatus)) ||                                   \
        (NDIS_STATUS_RESOURCES == (_NdisStatus)) ||                                 \
        (NDIS_STATUS_NOT_SUPPORTED == (_NdisStatus))))                              \
    {                                                                               \
        *(_pNtStatus) = (NTSTATUS)(_NdisStatus);                                    \
    }                                                                               \
    else if (NDIS_STATUS_BUFFER_TOO_SHORT == (_NdisStatus))                         \
    {                                                                               \
        /*                                                                          \
         *  The above NDIS status codes require a little special casing.            \
         */                                                                         \
        *(_pNtStatus) = STATUS_BUFFER_TOO_SMALL;                                    \
    }                                                                               \
    else if (NDIS_STATUS_INVALID_LENGTH == (_NdisStatus))                           \
    {                                                                               \
        *(_pNtStatus) = STATUS_INVALID_BUFFER_SIZE;                                 \
    }                                                                               \
    else if (NDIS_STATUS_INVALID_DATA == (_NdisStatus))                             \
    {                                                                               \
        *(_pNtStatus) = STATUS_INVALID_PARAMETER;                                   \
    }                                                                               \
    else if (NDIS_STATUS_ADAPTER_NOT_FOUND == (_NdisStatus))                        \
    {                                                                               \
        *(_pNtStatus) = STATUS_NO_MORE_ENTRIES;                                     \
    }                                                                               \
    else if (NDIS_STATUS_ADAPTER_NOT_READY == (_NdisStatus))                        \
    {                                                                               \
        *(_pNtStatus) = STATUS_DEVICE_NOT_READY;                                    \
    }                                                                               \
    else                                                                            \
    {                                                                               \
        *(_pNtStatus) = STATUS_UNSUCCESSFUL;                                        \
    }                                                                               \
}

#define NT_STATUS_TO_NDIS_STATUS(_NtStatus, _pNdisStatus)                           \
{                                                                                   \
    /*                                                                              \
     *  The following NDIS status codes map directly to NT status codes.            \
     */                                                                             \
    if (((STATUS_SUCCESS == (_NtStatus)) ||                                  \
        (STATUS_PENDING == (_NtStatus)) ||                                   \
        (STATUS_BUFFER_OVERFLOW == (_NtStatus)) ||                           \
        (STATUS_UNSUCCESSFUL == (_NtStatus)) ||                                   \
        (STATUS_INSUFFICIENT_RESOURCES == (_NtStatus)) ||                                 \
        (STATUS_NOT_SUPPORTED == (_NtStatus))))                              \
    {                                                                               \
        *(_pNdisStatus) = (NDIS_STATUS)(_NtStatus);                                    \
    }                                                                               \
    else if (STATUS_BUFFER_TOO_SMALL == (_NtStatus))                         \
    {                                                                               \
        /*                                                                          \
         *  The above NDIS status codes require a little special casing.            \
         */                                                                         \
        *(_pNdisStatus) = NDIS_STATUS_BUFFER_TOO_SHORT;                            \
    }                                                                               \
    else if (STATUS_INVALID_BUFFER_SIZE == (_NtStatus))                           \
    {                                                                               \
        *(_pNdisStatus) = NDIS_STATUS_INVALID_LENGTH;                                 \
    }                                                                               \
    else if (STATUS_INVALID_PARAMETER == (_NtStatus))                             \
    {                                                                               \
        *(_pNdisStatus) = NDIS_STATUS_INVALID_DATA;                                   \
    }                                                                               \
    else if (STATUS_NO_MORE_ENTRIES == (_NtStatus))                        \
    {                                                                               \
        *(_pNdisStatus) = NDIS_STATUS_ADAPTER_NOT_FOUND;                                     \
    }                                                                               \
    else if (STATUS_DEVICE_NOT_READY == (_NtStatus))                        \
    {                                                                               \
        *(_pNdisStatus) = NDIS_STATUS_ADAPTER_NOT_READY;                                    \
    }                                                                               \
    else                                                                            \
    {                                                                               \
        *(_pNdisStatus) = NDIS_STATUS_FAILURE;                                        \
    }                                                                               \
}



FORCEINLINE
MP_SEND_STATS(
    IN PMP_ADAPTER  Adapter,
    IN PNET_BUFFER  NetBuffer
    )
/*++
Routine Description:
    This function updates the send statistics on the Adapter.
    This is called only after a NetBuffer has been sent out.

    These should be maintained in hardware to increase performance.
    They are demonstrated here as all NDIS 6.0 miniports are required
    to support these statistics.

Arguments:

    Adapter     Pointer to our adapter
    NetBuffer   Pointer the the sent NetBuffer
Return Value:
    None

--*/
{
    PUCHAR  EthHeader;
    ULONG   Length;
    PMDL    Mdl = NET_BUFFER_CURRENT_MDL(NetBuffer);

    NdisQueryMdl(Mdl, &EthHeader, &Length, NormalPagePriority);
    if (EthHeader != NULL)
    {
        EthHeader += NET_BUFFER_CURRENT_MDL_OFFSET(NetBuffer);
        if (ETH_IS_BROADCAST(EthHeader))
        {
            Adapter->OutBroadcastPkts++;
            Adapter->OutBroadcastOctets +=NET_BUFFER_DATA_LENGTH(NetBuffer);
        }
        else if (ETH_IS_MULTICAST(EthHeader))
        {
            Adapter->OutMulticastPkts++;
            Adapter->OutMulticastOctets +=NET_BUFFER_DATA_LENGTH(NetBuffer);
        }
        else
        {
            Adapter->OutUCastPkts++;
            Adapter->OutUCastOctets += NET_BUFFER_DATA_LENGTH(NetBuffer);
        }
    }

}

FORCEINLINE
MP_RECEIVE_STATS(
    IN PMP_ADAPTER  Adapter,
    IN PNET_BUFFER  NetBuffer
    )
/*++
Routine Description:
    This function updates the receive statistics on the Adapter.
    This is incremented before the NetBufferList is indicated to NDIS.

    These should be maintained in hardware to increase performance.
    They are demonstrated here as all NDIS 6.0 miniports are required
    to support these statistics.

Arguments:

    Adapter     Pointer to our adapter
    NetBuffer   Pointer the the sent NetBuffer
Return Value:
    None

--*/
{
    PUCHAR  EthHeader;
    ULONG   Length;
    PMDL    Mdl = NET_BUFFER_CURRENT_MDL(NetBuffer);
    ULONG   NbLength = NET_BUFFER_DATA_LENGTH(NetBuffer);

    NdisQueryMdl(Mdl, &EthHeader, &Length, NormalPagePriority);
    EthHeader += NET_BUFFER_CURRENT_MDL_OFFSET(NetBuffer);
    if (ETH_IS_BROADCAST(EthHeader))
    {
        Adapter->InBroadcastPkts++;
        Adapter->InBroadcastOctets +=NbLength;
    }
    else if (ETH_IS_MULTICAST(EthHeader))
    {
        Adapter->InMulticastPkts++;
        Adapter->InMulticastOctets +=NbLength;
    }
    else
    {
        Adapter->InUcastPkts++;
        Adapter->InUcastOctets += NbLength;
    }

}

//--------------------------------------
// Miniport routines
//--------------------------------------

DRIVER_INITIALIZE DriverEntry;

NDIS_STATUS
MPInitialize(
    IN  NDIS_HANDLE                        MiniportAdapterHandle,
    IN  NDIS_HANDLE                        MiniportDriverContext,
    IN  PNDIS_MINIPORT_INIT_PARAMETERS     MiniportInitParameters
    );

NDIS_STATUS
MPSetOptions(
    IN NDIS_HANDLE  NdisMiniportDriverHandle,
    IN NDIS_HANDLE  MiniportDriverContext
    );

VOID
MPSendNetBufferLists(
    IN  NDIS_HANDLE         MiniportAdapterContext,
    IN  PNET_BUFFER_LIST    NetBufferList,
    IN  NDIS_PORT_NUMBER    PortNumber,
    IN  ULONG               SendFlags
    );

VOID
MPReturnNetBufferLists(
    IN  NDIS_HANDLE         MiniportAdapterContext,
    IN  PNET_BUFFER_LIST    NetBufferLists,
    IN  ULONG               ReturnFlags
    );

BOOLEAN
MPCheckForHang(
    IN NDIS_HANDLE MiniportAdapterContext
    );

NDIS_STATUS
MPReset(
    IN  NDIS_HANDLE     MiniportAdapterContext,
    OUT PBOOLEAN        AddressingReset
    );

NDIS_STATUS
MPPause(
    IN  NDIS_HANDLE                         MiniportAdapterContext,
    IN  PNDIS_MINIPORT_PAUSE_PARAMETERS     MiniportPauseParameters
    );

NDIS_STATUS
MPRestart(
    IN  NDIS_HANDLE                         MiniportAdapterContext,
    IN  PNDIS_MINIPORT_RESTART_PARAMETERS   MiniportRestartParameters
    );

VOID
MPPnPEventNotify(
    IN  NDIS_HANDLE             MiniportAdapterContext,
    IN  PNET_DEVICE_PNP_EVENT   NetDevicePnPEvent
    );


NDIS_STATUS
NICSetAttributes(
    PMP_ADAPTER Adapter
    );

VOID
MPUnload(
    IN  PDRIVER_OBJECT  DriverObject
    );

VOID
MPCancelOidRequest(
    IN  NDIS_HANDLE            MiniportAdapterContext,
    IN  PVOID                  RequestId
    );

NDIS_STATUS
MPOidRequest(
    IN  NDIS_HANDLE        MiniportAdapterContext,
    IN  PNDIS_OID_REQUEST  NdisRequest
    );

NDIS_STATUS
NICQueryInformation(
    IN  NDIS_HANDLE         MiniportAdapterContext,
    IN  PNDIS_OID_REQUEST   NdisRequest
    );


NDIS_STATUS
NICSendNetBufferList(
    IN  PMP_ADAPTER         Adapter,
    IN  PNET_BUFFER_LIST    NetBufferList,
    IN  PNET_BUFFER         NetBuffer
    );

BOOLEAN
NICCopyNetBuffer(
    PMP_ADAPTER Adapter,
    PTCB pTCB,
    IN PNET_BUFFER_LIST NetBufferList,
    IN  PNET_BUFFER     NetBuffer
   );

BOOLEAN
NICCopyNetBufferMdlToMdl(
    PMP_ADAPTER Adapter,
    PTCB pTCB,
    IN PNET_BUFFER_LIST NetBufferList,
    IN  PNET_BUFFER     NetBuffer
   );

NTSTATUS
NICCopyMdlToBuffer(
    IN PMDL Mdl,
    IN SIZE_T MdlOffset,
    __out_bcount_part(BytesToCopy, *BytesCopied) IN PVOID Buffer,
    IN SIZE_T BytesToCopy,
    OUT SIZE_T* BytesCopied
    );

VOID
NICCompleteSendNetBufferLists(
    PMP_ADAPTER Adapter,
    IN  PNET_BUFFER_LIST     NetBufferList
    );


NDIS_STATUS
NICSetInformation(
    IN NDIS_HANDLE           MiniportAdapterContext,
    IN PNDIS_OID_REQUEST     NdisRequest
    );

VOID
MPShutdown(
    IN NDIS_HANDLE MiniportAdapterContext,
    IN  NDIS_SHUTDOWN_ACTION    ShutdownAction
    );

VOID
NICFreeSendTCB(
    IN PMP_ADAPTER Adapter,
    IN PTCB pTCB);


NDIS_STATUS
NICInitializeAdapter(
    IN PMP_ADAPTER Adapter
);

NDIS_STATUS
NICAllocAdapter(
    PMP_ADAPTER *Adapter
    );

VOID
NICFreeAdapter(
    PMP_ADAPTER Adapter
    );

NDIS_STATUS
NICAllocSendResources(
    PMP_ADAPTER Adapter);

NDIS_STATUS
NICAllocRecvResources(
    PMP_ADAPTER Adapter);

VOID
NICFreeSendResources(
    PMP_ADAPTER Adapter);

VOID
NICFreeRecvResources(
    PMP_ADAPTER Adapter);


NDIS_STATUS
NICReadRegParameters(
    PMP_ADAPTER Adapter
    );

NDIS_STATUS
NICGetStatsCounters(
    PMP_ADAPTER Adapter,
    NDIS_OID Oid,
    PULONG pCounter);

NDIS_STATUS
NICSetPacketFilter(
    IN PMP_ADAPTER Adapter,
    IN ULONG PacketFilter);

NDIS_STATUS
NICSetMulticastList(
    IN PMP_ADAPTER              Adapter,
    IN PVOID                    InformationBuffer,
    IN ULONG                    InformationBufferLength,
    OUT PULONG                  pBytesRead,
    OUT PULONG                  pBytesNeeded
    );

ULONG
NICGetMediaConnectStatus(
    PMP_ADAPTER Adapter);

VOID
MPCancelSendNetBufferLists(
    IN  NDIS_HANDLE     MiniportAdapterContext,
    IN  PVOID           CancelId
    );

PCHAR
DbgGetOidName (
    ULONG oid
    );


VOID
NICInitWorkItemCallback(
    WDFWORKITEM WorkItem
    );

NTSTATUS
NICInitAdapterWorker(
    PMP_ADAPTER Adapter
    ) ;

VOID
NICPostReadsWorkItemCallBack(
    WDFWORKITEM WorkItem
    );

NTSTATUS
NICMakeSynchronousIoctl(
    IN WDFIOTARGET          IoTarget,
    IN PFILE_OBJECT         FileObject,
    IN ULONG                IoctlControlCode,
    IN OUT PVOID            InputBuffer,
    IN ULONG                InputBufferLength,
    IN OUT PVOID            OutputBuffer,
    IN ULONG                OutputBufferLength,
    OUT PULONG              BytesReadOrWritten
    );

VOID
NICMakeSynchronousIoCtlCompletion(
    IN WDFREQUEST                  Request,
    IN WDFIOTARGET                 Target,
    PWDF_REQUEST_COMPLETION_PARAMS CompletionParams,
    IN WDFCONTEXT                  Context
    );

NTSTATUS
NICPostWriteRequest(
    PMP_ADAPTER Adapter,
    PTCB    pTCB
    );

VOID
NICWriteRequestCompletion(
    IN WDFREQUEST                  Request,
    IN WDFIOTARGET                 Target,
    PWDF_REQUEST_COMPLETION_PARAMS CompletionParams,
    IN WDFCONTEXT                  Context
    );

NTSTATUS
NICPostReadRequest(
    PMP_ADAPTER Adapter,
    PRCB    pRCB
    );

VOID
NICReadRequestCompletion(
    IN WDFREQUEST                  Request,
    IN WDFIOTARGET                 Target,
    PWDF_REQUEST_COMPLETION_PARAMS CompletionParams,
    IN WDFCONTEXT                  Context
    );

VOID
NICFreeRCB(
    IN PRCB pRCB,
    IN BOOLEAN AtDispatchLevel
    );


NDIS_STATUS
NICSendOidRequest(
    IN PMP_ADAPTER                  Adapter,
    IN NDIS_REQUEST_TYPE            RequestType,
    IN NDIS_OID                     Oid,
    IN PVOID                        InformationBuffer,
    IN ULONG                        InformationBufferLength,
    OUT PULONG                      BytesReadOrWritten,
    OUT PULONG                      BytesNeeded
    );

NDIS_STATUS
NICForwardRequest(
    IN PMP_ADAPTER                  Adapter,
    IN  PNDIS_OID_REQUEST           NdisRequest
    );

VOID
NICRequestWorkItemCallback(
    WDFWORKITEM WorkItem
    );

BOOLEAN
NICIsPacketAcceptable(
    IN PMP_ADAPTER Adapter,
    IN PUCHAR   pDstMac
    );

BOOLEAN
NICIsMulticastMatch(
    IN PMP_ADAPTER                  Adapter,
    IN PUCHAR                       pDstMac
    );

VOID
MPHalt(
    IN  NDIS_HANDLE             MiniportAdapterContext,
    IN  NDIS_HALT_ACTION        HaltAction
    );

VOID
NICFreeQueuedSendNetBufferLists(
    IN  PMP_ADAPTER  Adapter
    );

VOID
MPIndicateLinkState(
    IN  PMP_ADAPTER     Adapter
    );

#ifdef INTERFACE_WITH_NDISPROT

VOID
NICUnregisterExCallback(
    IN PMP_ADAPTER Adapter
    );

BOOLEAN
NICRegisterExCallback(
    PMP_ADAPTER Adapter
    );

VOID
NICExCallback(
    PVOID   CallBackContext,
    PVOID   Source,
    PVOID   AreYouThere
    );

NTSTATUS
NICOpenNdisProtocolInterface(
    PMP_ADAPTER Adapter
    );

#else

#define NICUnregisterExCallback(Adapter)
#define NICRegisterExCallback(Adapter) TRUE
#define NICExCallback()

#endif


NTSTATUS
NICPostAsynchronousStatusIndicationRequest(
    IN PMP_ADAPTER Adapter
    );

VOID
NICStatusIndicationRequestCompletionRoutine(
    IN WDFREQUEST                  Request,
    IN WDFIOTARGET                 Target,
    PWDF_REQUEST_COMPLETION_PARAMS CompletionParams,
    IN WDFCONTEXT                  Context
    );

NDIS_STATUS
NICAllocOidResources(
    PMP_ADAPTER Adapter
    );

VOID
NICSendOidRequestToTargetAsyncCompletionRoutine(
    IN WDFREQUEST                  Request,
    IN WDFIOTARGET                 Target,
    PWDF_REQUEST_COMPLETION_PARAMS CompletionParams,
    IN WDFCONTEXT                  Context
    );

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
    );



#endif    // NDISWDM_H




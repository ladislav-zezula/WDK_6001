/*++

Copyright (c) 2000  Microsoft Corporation

Module Name:

    ndisprot.h

Abstract:

    Data structures, defines and function prototypes for NDISPROT.

Environment:

    Kernel mode only.

--*/

#ifndef __NDISPROT__H
#define __NDISPROT__H


#define NT_DEVICE_NAME          L"\\Device\\NdisProt"
#define DOS_DEVICE_NAME         L"\\DosDevices\\NdisProt"

//
//  Abstract types
//
typedef NDIS_EVENT              NPROT_EVENT;


#define NPROT_MAC_ADDR_LEN            6

//-----------------------------------------------------------------------------
// 4127 -- Conditional Expression is Constant warning
//-----------------------------------------------------------------------------
#define WHILE(constant) \
__pragma(warning(disable: 4127)) while(constant); __pragma(warning(default: 4127))


//
//  The Open Context represents an open of our device object.
//  We allocate this on processing a BindAdapter from NDIS,
//  and free it when all references (see below) to it are gone.
//
//  Binding/unbinding to an NDIS device:
//
//  On processing a BindAdapter call from NDIS, we set up a binding
//  to the specified NDIS device (miniport). This binding is
//  torn down when NDIS asks us to Unbind by calling
//  our UnbindAdapter handler.
//
//  Receiving data:
//
//  While an NDIS binding exists, read Requests are queued on this
//  structure, to be processed when packets are received.
//  If data arrives in the absense of a pended read Request, we
//  queue it, to the extent of one packet, i.e. we save the
//  contents of the latest packet received. We fail read Requests
//  received when no NDIS binding exists (or is in the process
//  of being torn down).
//
//  Sending data:
//
//  Write Requests are used to send data. Each write Request maps to
//  a single NDIS packet. Packet send-completion is mapped to
//  write Request completion. We use NDIS 5.1 CancelSend to support
//  write Request cancellation. Write Requests that arrive when we don't
//  have an active NDIS binding are failed.
//
//  Reference count:
//
//  The following are long-lived references:
//  OPEN_DEVICE ioctl (goes away on processing a Close Request)
//  Pended read Requests
//  Queued received packets
//  Uncompleted write Requests (outstanding sends)
//  Existence of NDIS binding
//
typedef struct _NDISPROT_OPEN_CONTEXT
{
    LIST_ENTRY              Link;           // Link into global list
    ULONG                   Flags;          // State information
    ULONG                   RefCount;
    NPROT_LOCK               Lock;

    WDFFILEOBJECT            pFileObject;    // Set on OPEN_DEVICE

    NDIS_HANDLE             BindingHandle;
    NDIS_HANDLE             SendPacketPool;
    NDIS_HANDLE             SendBufferPool;
    NDIS_HANDLE             RecvPacketPool;
    NDIS_HANDLE             RecvBufferPool;
    ULONG                   MacOptions;
    ULONG                   MaxFrameSize;

    ULONG                   PendedSendCount;

    WDFQUEUE                ReadQueue;
    LIST_ENTRY              RecvPktQueue;   // queued rcv packets
    ULONG                   RecvPktCount;

    NET_DEVICE_POWER_STATE  PowerState;
    NDIS_EVENT              PoweredUpEvent; // signalled iff PowerState is D0
    NDIS_STRING             DeviceName;     // used in NdisOpenAdapter
    NDIS_STRING                DeviceDescr;    // friendly name

    NDIS_STATUS             BindStatus;     // for Open/CloseAdapter
    NPROT_EVENT              BindEvent;      // for Open/CloseAdapter

    ULONG                   oc_sig;         // Signature for sanity

    UCHAR                   CurrentAddress[NPROT_MAC_ADDR_LEN];
    WDFQUEUE             StatusIndicationQueue;

} NDISPROT_OPEN_CONTEXT, *PNDISPROT_OPEN_CONTEXT;

typedef struct _FILEO_BJECT_CONTEXT {

    PNDISPROT_OPEN_CONTEXT OpenContext;

} FILE_OBJECT_CONTEXT, *PFILE_OBJECT_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(FILE_OBJECT_CONTEXT, GetFileObjectContext)

typedef struct _REQUEST_CONTEXT {

    PNDIS_PACKET NdisPacket;
    ULONG Length;

} REQUEST_CONTEXT, *PREQUEST_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(REQUEST_CONTEXT, GetRequestContext)

#define oc_signature        'OiuN'

//
//  Definitions for Flags above.
//
#define NPROTO_BIND_IDLE             0x00000000
#define NPROTO_BIND_OPENING          0x00000001
#define NPROTO_BIND_FAILED           0x00000002
#define NPROTO_BIND_ACTIVE           0x00000004
#define NPROTO_BIND_CLOSING          0x00000008
#define NPROTO_BIND_FLAGS            0x0000000F  // State of the binding

#define NPROTO_OPEN_IDLE             0x00000000
#define NPROTO_OPEN_ACTIVE           0x00000010
#define NPROTO_OPEN_FLAGS            0x000000F0  // State of the I/O open

#define NPROTO_RESET_IN_PROGRESS     0x00000100
#define NPROTO_NOT_RESETTING         0x00000000
#define NPROTO_RESET_FLAGS           0x00000100

#define NPROTO_MEDIA_CONNECTED       0x00000000
#define NPROTO_MEDIA_DISCONNECTED    0x00000200
#define NPROTO_MEDIA_FLAGS           0x00000200

#define NPROTO_READ_SERVICING        0x00100000  // Is the read service
                                                // routine running?
#define NPROTO_READ_FLAGS            0x00100000

#define NPROTO_UNBIND_RECEIVED       0x10000000  // Seen NDIS Unbind?
#define NPROTO_UNBIND_FLAGS          0x10000000


//
//  Globals:
//
typedef struct _NDISPROT_GLOBALS
{
    WDFDEVICE          ControlDevice;
    NDIS_HANDLE             NdisProtocolHandle;
    UCHAR                   PartialCancelId;    // for cancelling sends
    ULONG                   LocalCancelId;
    LIST_ENTRY              OpenList;           // of OPEN_CONTEXT structures
    NPROT_LOCK               GlobalLock;         // to protect the above
    NPROT_EVENT              BindsComplete;      // have we seen NetEventBindsComplete?

} NDISPROT_GLOBALS, *PNDISPROT_GLOBALS;



//
//  NDIS Request context structure
//
typedef struct _NDISPROT_REQUEST
{
    NDIS_REQUEST            Request;
    NPROT_EVENT              ReqEvent;
    ULONG                   Status;

} NDISPROT_REQUEST, *PNDISPROT_REQUEST;


#define NPROTO_PACKET_FILTER  (NDIS_PACKET_TYPE_DIRECTED|    \
                              NDIS_PACKET_TYPE_MULTICAST|   \
                              NDIS_PACKET_TYPE_BROADCAST)

//
//  Send packet pool bounds
//
#define MIN_SEND_PACKET_POOL_SIZE    20
#define MAX_SEND_PACKET_POOL_SIZE    400

//
//  ProtocolReserved in sent packets. We save a pointer to the Request
//  that generated the send.
//
//  The RefCount is used to determine when to free the packet back
//  to its pool. It is used to synchronize between a thread completing
//  a send and a thread attempting to cancel a send.
//
typedef struct _NPROT_SEND_PACKET_RSVD
{
    WDFREQUEST         Request;
    ULONG                   RefCount;

} NPROT_SEND_PACKET_RSVD, *PNPROT_SEND_PACKET_RSVD;

//
//  Receive packet pool bounds
//
#define MIN_RECV_PACKET_POOL_SIZE    4
#define MAX_RECV_PACKET_POOL_SIZE    20

//
//  Max receive packets we allow to be queued up
//
#define MAX_RECV_QUEUE_SIZE          4

//
//  ProtocolReserved in received packets: we link these
//  packets up in a queue waiting for Read Requests.
//
typedef struct _NPROT_RECV_PACKET_RSVD
{
    LIST_ENTRY              Link;
    PNDIS_BUFFER            pOriginalBuffer;    // used if we had to partial-map

} NPROT_RECV_PACKET_RSVD, *PNPROT_RECV_PACKET_RSVD;



#include <pshpack1.h>

typedef struct _NDISPROT_ETH_HEADER
{
    UCHAR       DstAddr[NPROT_MAC_ADDR_LEN];
    UCHAR       SrcAddr[NPROT_MAC_ADDR_LEN];
    USHORT      EthType;

} NDISPROT_ETH_HEADER;

typedef struct _NDISPROT_ETH_HEADER UNALIGNED * PNDISPROT_ETH_HEADER;

#include <poppack.h>


extern NDISPROT_GLOBALS      Globals;


#define NPROT_ALLOC_TAG      'oiuN'


#ifndef NDIS51
#define NdisGetPoolFromPacket(_Pkt) (_Pkt->Private.Pool)
#endif

//
//  Prototypes.
//
DRIVER_INITIALIZE DriverEntry;

VOID
NdisProtEvtDriverUnload(
    IN WDFDRIVER Driver
    );

VOID
NdisProtEvtDeviceFileCreate(
    IN WDFDEVICE            Device,
    IN WDFREQUEST Request,
    IN WDFFILEOBJECT        FileObject
    );

VOID
NdisProtEvtFileClose(
    IN WDFFILEOBJECT    FileObject
    );

VOID
NdisProtEvtFileCleanup(
    IN WDFFILEOBJECT    FileObject
    );

VOID
NdisProtEvtIoDeviceControl(
    IN WDFQUEUE     Queue,
    IN WDFREQUEST Request,
    IN size_t      OutputBufferLength,
    IN size_t      InputBufferLength,
    IN ULONG      IoControlCode
    );

NTSTATUS
ndisprotOpenDevice(
    IN PUCHAR                   pDeviceName,
    IN ULONG                    DeviceNameLength,
    IN WDFFILEOBJECT             pFileObject,
    OUT PNDISPROT_OPEN_CONTEXT * ppOpenContext
    );

VOID
ndisprotRefOpen(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext
    );

VOID
ndisprotDerefOpen(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext
    );

#if DBG
VOID
ndisprotDbgRefOpen(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext,
    IN ULONG                        FileNumber,
    IN ULONG                        LineNumber
    );

VOID
ndisprotDbgDerefOpen(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext,
    IN ULONG                        FileNumber,
    IN ULONG                        LineNumber
    );
#endif // DBG

VOID
NdisProtBindAdapter(
    OUT PNDIS_STATUS                pStatus,
    IN NDIS_HANDLE                  BindContext,
    IN PNDIS_STRING                 DeviceName,
    IN PVOID                        SystemSpecific1,
    IN PVOID                        SystemSpecific2
    );

VOID
NdisProtOpenAdapterComplete(
    IN NDIS_HANDLE                  ProtocolBindingContext,
    IN NDIS_STATUS                  Status,
    IN NDIS_STATUS                  OpenErrorCode
    );

VOID
NdisProtUnbindAdapter(
    OUT PNDIS_STATUS                pStatus,
    IN NDIS_HANDLE                  ProtocolBindingContext,
    IN NDIS_HANDLE                  UnbindContext
    );

VOID
NdisProtCloseAdapterComplete(
    IN NDIS_HANDLE                  ProtocolBindingContext,
    IN NDIS_STATUS                  Status
    );


NDIS_STATUS
NdisProtPnPEventHandler(
    IN NDIS_HANDLE                  ProtocolBindingContext,
    IN PNET_PNP_EVENT               pNetPnPEvent
    );

VOID
NdisProtProtocolUnloadHandler(
    VOID
    );

NDIS_STATUS
ndisprotCreateBinding(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext,
    IN PUCHAR                       pBindingInfo,
    IN ULONG                        BindingInfoLength
    );

VOID
ndisprotShutdownBinding(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext
    );

VOID
ndisprotFreeBindResources(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext
    );

VOID
ndisprotWaitForPendingIO(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext,
    IN BOOLEAN                      DoCancelReads
    );

VOID
ndisprotDoProtocolUnload(
    VOID
    );

NDIS_STATUS
ndisprotDoRequest(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext,
    IN NDIS_REQUEST_TYPE            RequestType,
    IN NDIS_OID                     Oid,
    IN PVOID                        InformationBuffer,
    IN ULONG                        InformationBufferLength,
    OUT PULONG                      pBytesProcessed
    );

NDIS_STATUS
ndisprotValidateOpenAndDoRequest(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext,
    IN NDIS_REQUEST_TYPE            RequestType,
    IN NDIS_OID                     Oid,
    IN PVOID                        InformationBuffer,
    IN ULONG                        InformationBufferLength,
    OUT PULONG                      pBytesProcessed,
    IN BOOLEAN                      bWaitForPowerOn
    );

VOID
NdisProtResetComplete(
    IN NDIS_HANDLE                  ProtocolBindingContext,
    IN NDIS_STATUS                  Status
    );

VOID
NdisProtRequestComplete(
    IN NDIS_HANDLE                  ProtocolBindingContext,
    IN PNDIS_REQUEST                pNdisRequest,
    IN NDIS_STATUS                  Status
    );

VOID
NdisProtStatus(
    IN NDIS_HANDLE                  ProtocolBindingContext,
    IN NDIS_STATUS                  GeneralStatus,
    IN PVOID                        StatusBuffer,
    IN UINT                         StatusBufferSize
    );

VOID
NdisProtStatusComplete(
    IN NDIS_HANDLE                  ProtocolBindingContext
    );

NDIS_STATUS
ndisprotQueryBinding(
    IN PUCHAR                       pBuffer,
    IN ULONG                        InputLength,
    IN ULONG                        OutputLength,
    OUT PULONG                      pBytesReturned
    );

PNDISPROT_OPEN_CONTEXT
ndisprotLookupDevice(
    __in_bcount(BindingInfoLength) IN PUCHAR    pBindingInfo,
    IN ULONG                                    BindingInfoLength
    );

NDIS_STATUS
ndisprotQueryOidValue(
    IN  PNDISPROT_OPEN_CONTEXT       pOpenContext,
    OUT PVOID                       pDataBuffer,
    IN  ULONG                       BufferLength,
    OUT PULONG                      pBytesWritten
    );

NDIS_STATUS
ndisprotSetOidValue(
    IN  PNDISPROT_OPEN_CONTEXT       pOpenContext,
    OUT PVOID                       pDataBuffer,
    IN  ULONG                       BufferLength
    );


VOID
NdisProtEvtIoRead(
    IN WDFQUEUE         Queue,
    IN WDFREQUEST       Request,
    IN size_t            Length
    );

VOID
ndisprotEvtNotifyReadQueue(
    IN WDFQUEUE            Queue,
    IN WDFCONTEXT          Context
    );

VOID
ndisprotServiceReads(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext
    );

NDIS_STATUS
NdisProtReceive(
    IN NDIS_HANDLE                  ProtocolBindingContext,
    IN NDIS_HANDLE                  MacReceiveContext,
    IN PVOID                        pHeaderBuffer,
    IN UINT                         HeaderBufferSize,
    IN PVOID                        pLookaheadBuffer,
    IN UINT                         LookaheadBufferSize,
    IN UINT                         PacketSize
    );

VOID
NdisProtTransferDataComplete(
    IN NDIS_HANDLE                  ProtocolBindingContext,
    IN PNDIS_PACKET                 pNdisPacket,
    IN NDIS_STATUS                  TransferStatus,
    IN UINT                         BytesTransferred
    );

VOID
NdisProtReceiveComplete(
    IN NDIS_HANDLE                  ProtocolBindingContext
    );

INT
NdisProtReceivePacket(
    IN NDIS_HANDLE                  ProtocolBindingContext,
    IN PNDIS_PACKET                 pNdisPacket
    );

VOID
ndisprotShutdownBinding(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext
    );

VOID
ndisprotQueueReceivePacket(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext,
    IN PNDIS_PACKET                 pRcvPacket
    );

PNDIS_PACKET
ndisprotAllocateReceivePacket(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext,
    IN UINT                         DataLength,
    OUT PUCHAR *                    ppDataBuffer
    );

VOID
ndisprotFreeReceivePacket(
    IN PNDISPROT_OPEN_CONTEXT        pOpenContext,
    IN PNDIS_PACKET                 pNdisPacket
    );

VOID
ndisprotFlushReceiveQueue(
    IN PNDISPROT_OPEN_CONTEXT            pOpenContext
    );

VOID
NdisProtEvtIoWrite(
    IN WDFQUEUE         Queue,
    IN WDFREQUEST       Request,
    IN size_t            Length
    );

VOID
NdisProtCancelWrite(
    IN WDFREQUEST Request
    );

VOID
NdisProtSendComplete(
    IN NDIS_HANDLE                  ProtocolBindingContext,
    IN PNDIS_PACKET                 pNdisPacket,
    IN NDIS_STATUS                  Status
    );



VOID
ndisServiceIndicateStatusIrp(
    IN PNDISPROT_OPEN_CONTEXT   OpenContext,
    IN NDIS_STATUS              GeneralStatus,
    IN PVOID                    StatusBuffer,
    IN UINT                     StatusBufferSize
    );

NTSTATUS
NdisProtCreateControlDevice(
    IN WDFDRIVER Driver,
    IN PWDFDEVICE_INIT DeviceInit
    );

#ifdef EX_CALLBACK

BOOLEAN
ndisprotRegisterExCallBack();

VOID
ndisprotUnregisterExCallBack();

VOID
ndisprotCallback(
    PVOID   CallBackContext,
    PVOID   Source,
    PVOID   NotifyPresenceCallback
    );

#else

#define ndisprotRegisterExCallBack() TRUE
#define ndisprotUnregisterExCallBack()

#endif

#endif // __NDISPROT__H



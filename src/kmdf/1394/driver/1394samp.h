/*++

Copyright (c) 1998-99 Microsoft Corporation

Module Name:

    1394vdev.h

Abstract:

--*/

//
// 80 msecs in units of 100nsecs
//
#define ISOCH_DETACH_TIMEOUT_VALUE  (ULONG)(-100 * 100 * 100 * 100)

//
// IEEE 1212 Directory definition
//
typedef struct _DIRECTORY_INFO {
    union {
        USHORT          DI_CRC;
        USHORT          DI_Saved_Length;
    } u;
    USHORT              DI_Length;
} DIRECTORY_INFO, *PDIRECTORY_INFO;

//
// IEEE 1212 Offset entry definition
//
#pragma warning(disable:4214)  // bit field types other than int warning

typedef struct _OFFSET_ENTRY {
    ULONG               OE_Offset:24;
    ULONG               OE_Key:8;
} OFFSET_ENTRY, *POFFSET_ENTRY;

#pragma warning(default:4214)

//
// Structure to identify myself as a virtual test device across the bus
//
#define MAX_LEN_HOST_NAME 32


typedef struct _DEVICE_EXTENSION {

    PDEVICE_OBJECT          PortDeviceObject;
    PDEVICE_OBJECT          PhysicalDeviceObject;
    PDEVICE_OBJECT          StackDeviceObject;

    WDFDEVICE               WdfDevice;
    WDFIOTARGET             StackIoTarget;
    WDFIOTARGET             PortDeviceIoTarget;

    WDFQUEUE                IoctlQueue;

    WDFQUEUE                BusResetRequestsQueue;

    WDFSPINLOCK             CromSpinLock;
    WDFSPINLOCK             AsyncSpinLock;
    WDFSPINLOCK             IsochSpinLock;
    WDFSPINLOCK             IsochResourceSpinLock;

    ULONG                   GenerationCount;

    LIST_ENTRY              CromData;
    LIST_ENTRY              AsyncAddressData;
    LIST_ENTRY              IsochDetachData;
    LIST_ENTRY              IsochResourceData;

} DEVICE_EXTENSION, *PDEVICE_EXTENSION;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DEVICE_EXTENSION, GetDeviceContext)


//
// This is used to keep track of dynamic crom calls.
//
typedef struct _CROM_DATA {
    LIST_ENTRY      CromList;
    HANDLE          hCromData;
    PVOID           Buffer;
    PMDL            pMdl;
} CROM_DATA, *PCROM_DATA;

//
// This is used to store data for each async address range.
//
typedef struct _ASYNC_ADDRESS_DATA {
    LIST_ENTRY              AsyncAddressList;
    PDEVICE_EXTENSION       DeviceExtension;
    PVOID                   Buffer;
    ULONG                   nLength;
    ULONG                   nAddressesReturned;
    PADDRESS_RANGE          AddressRange;
    HANDLE                  hAddressRange;
    PMDL                    pMdl;
} ASYNC_ADDRESS_DATA, *PASYNC_ADDRESS_DATA;

#define ISOCH_DETACH_TAG    0xaabbbbaa

//
// This is used to store data needed when calling IsochDetachBuffers.
// We need to store this data seperately for each call to IsochAttachBuffers.
//
typedef struct _ISOCH_DETACH_DATA {
    LIST_ENTRY              IsochDetachList;
    PDEVICE_EXTENSION       DeviceExtension;
    PISOCH_DESCRIPTOR       IsochDescriptor;
    WDFREQUEST              Request;
    PIRP                    newIrp;
    PIRB                    DetachIrb;
    PIRB                    AttachIrb;
    NTSTATUS                AttachStatus;
    KTIMER                  Timer;
    KDPC                    TimerDpc;
    HANDLE                  hResource;
    ULONG                   numIsochDescriptors;
    ULONG                   outputBufferLength;
    ULONG                   bDetach;
} ISOCH_DETACH_DATA, *PISOCH_DETACH_DATA;

//
// This is used to store allocated isoch resources.
// We use this information in case of a surprise removal.
//
typedef struct _ISOCH_RESOURCE_DATA {
    LIST_ENTRY      IsochResourceList;
    HANDLE          hResource;
} ISOCH_RESOURCE_DATA, *PISOCH_RESOURCE_DATA;

//
// 1394api.c
//
NTSTATUS
t1394_GetLocalHostInformation(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN ULONG      nLevel,
    IN OUT PULONG UserStatus,
    IN OUT PVOID  Information
    );

NTSTATUS
t1394_Get1394AddressFromDeviceObject(
    IN WDFDEVICE      DeviceObject,
    IN WDFREQUEST     Irp,
    IN ULONG          fulFlags,
    OUT PNODE_ADDRESS pNodeAddress
    );

NTSTATUS
t1394_Control(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp
    );

NTSTATUS
t1394_GetMaxSpeedBetweenDevices(
    IN WDFDEVICE      DeviceObject,
    IN WDFREQUEST     Irp,
    IN ULONG          fulFlags,
    IN ULONG          ulNumberOfDestinations,
    IN PDEVICE_OBJECT hDestinationDeviceObjects[64],
    OUT PULONG        fulSpeed
    );

NTSTATUS
t1394_SetDeviceXmitProperties(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN ULONG      fulSpeed,
    IN ULONG      fulPriority
    );

NTSTATUS
t1394_GetConfigurationInformation(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp
    );

NTSTATUS
t1394_BusReset(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN ULONG      fulFlags
    );

NTSTATUS
t1394_GetGenerationCount(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN OUT PULONG GenerationCount
    );

NTSTATUS
t1394_SendPhyConfigurationPacket(
    IN WDFDEVICE DeviceObject,
    IN WDFREQUEST Irp,
    IN PHY_CONFIGURATION_PACKET PhyConfigurationPacket
    );

NTSTATUS
t1394_BusResetNotification(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN ULONG      fulFlags
    );

NTSTATUS
t1394_SetLocalHostProperties(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN ULONG      nLevel,
    IN PVOID      Information
    );

void
t1394_BusResetRoutine(
    IN PVOID    Context
    );

//
// asyncapi.c
//
NTSTATUS
t1394_AllocateAddressRange(
    IN WDFDEVICE           DeviceObject,
    IN WDFREQUEST          Irp,
    IN ULONG               fulAllocateFlags,
    IN ULONG               fulFlags,
    IN ULONG               nLength,
    IN ULONG               MaxSegmentSize,
    IN ULONG               fulAccessType,
    IN ULONG               fulNotificationOptions,
    IN OUT PADDRESS_OFFSET Required1394Offset,
    OUT PHANDLE            phAddressRange,
    IN OUT PULONG          Data
    );

NTSTATUS
t1394_FreeAddressRange(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN HANDLE     hAddressRange
    );

NTSTATUS
t1394_SetAddressData(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN HANDLE     hAddressRange,
    IN ULONG      nLength,
    IN ULONG      ulOffset,
    IN PVOID      Data
    );

NTSTATUS
t1394_GetAddressData(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN HANDLE     hAddressRange,
    IN ULONG      nLength,
    IN ULONG      ulOffset,
    __out_bcount(nLength) PVOID Data
    );

NTSTATUS
t1394_AsyncRead(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN ULONG      bRawMode,
    IN ULONG      bGetGeneration,
    IN IO_ADDRESS DestinationAddress,
    IN ULONG      nNumberOfBytesToRead,
    IN ULONG      nBlockSize,
    IN ULONG      fulFlags,
    IN ULONG      ulGeneration,
    IN OUT PULONG Data
    );

NTSTATUS
t1394_AsyncWrite(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN ULONG      bRawMode,
    IN ULONG      bGetGeneration,
    IN IO_ADDRESS DestinationAddress,
    IN ULONG      nNumberOfBytesToWrite,
    IN ULONG      nBlockSize,
    IN ULONG      fulFlags,
    IN ULONG      ulGeneration,
    IN OUT PULONG Data
    );

NTSTATUS
t1394_AsyncLock(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN ULONG      bRawMode,
    IN ULONG      bGetGeneration,
    IN IO_ADDRESS DestinationAddress,
    IN ULONG      nNumberOfArgBytes,
    IN ULONG      nNumberOfDataBytes,
    IN ULONG      fulTransactionType,
    IN ULONG      fulFlags,
    IN ULONG      Arguments[2],
    IN ULONG      DataValues[2],
    IN ULONG      ulGeneration,
    IN OUT PVOID  Buffer
    );

NTSTATUS
t1394_AsyncStream(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN ULONG      nNumberOfBytesToStream,
    IN ULONG      fulFlags,
    IN ULONG      ulTag,
    IN ULONG      nChannel,
    IN ULONG      ulSynch,
    IN UCHAR      nSpeed,
    IN OUT PULONG Data
    );

//
// isochapi.c
//
NTSTATUS
t1394_IsochAllocateBandwidth(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN ULONG      nMaxBytesPerFrameRequested,
    IN ULONG      fulSpeed,
    OUT PHANDLE   phBandwidth,
    OUT PULONG    pBytesPerFrameAvailable,
    OUT PULONG    pSpeedSelected
    );

NTSTATUS
t1394_IsochAllocateChannel(
    IN WDFDEVICE        DeviceObject,
    IN WDFREQUEST       Irp,
    IN ULONG            nRequestedChannel,
    OUT PULONG          pChannel,
    OUT PLARGE_INTEGER  pChannelsAvailable
    );

NTSTATUS
t1394_IsochAllocateResources(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN ULONG      fulSpeed,
    IN ULONG      fulFlags,
    IN ULONG      nChannel,
    IN ULONG      nMaxBytesPerFrame,
    IN ULONG      nNumberOfBuffers,
    IN ULONG      nMaxBufferSize,
    IN ULONG      nQuadletsToStrip,
    OUT PHANDLE   phResource
    );

NTSTATUS
t1394_IsochAttachBuffers(
    IN WDFDEVICE                    DeviceObject,
    IN WDFREQUEST                   Irp,
    IN ULONG                        outputBufferLength,
    IN HANDLE                       hResource,
    IN ULONG                        nNumberOfDescriptors,
    OUT PISOCH_DESCRIPTOR           pIsochDescriptor,
    IN OUT PRING3_ISOCH_DESCRIPTOR  R3_IsochDescriptor
    );

NTSTATUS
t1394_IsochDetachBuffers(
    IN WDFDEVICE         DeviceObject,
    IN WDFREQUEST        Irp,
    IN HANDLE            hResource,
    IN ULONG             nNumberOfDescriptors,
    IN PISOCH_DESCRIPTOR IsochDescriptor
    );

NTSTATUS
t1394_IsochFreeBandwidth(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN HANDLE     hBandwidth
    );

NTSTATUS
t1394_IsochFreeChannel(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN ULONG      nChannel
    );

NTSTATUS
t1394_IsochFreeResources(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN HANDLE     hResource
    );

NTSTATUS
t1394_IsochListen(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN HANDLE     hResource,
    IN ULONG      fulFlags,
    IN CYCLE_TIME StartTime
    );

NTSTATUS
t1394_IsochQueryCurrentCycleTime(
    IN WDFDEVICE    DeviceObject,
    IN WDFREQUEST   Irp,
    OUT PCYCLE_TIME pCurrentCycleTime
    );

NTSTATUS
t1394_IsochQueryResources(
    IN WDFDEVICE        DeviceObject,
    IN WDFREQUEST       Irp,
    IN ULONG            fulSpeed,
    OUT PULONG          pBytesPerFrameAvailable,
    OUT PLARGE_INTEGER  pChannelsAvailable
    );

NTSTATUS
t1394_IsochSetChannelBandwidth(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN HANDLE     hBandwidth,
    IN ULONG      nMaxBytesPerFrame
    );

NTSTATUS
t1394_IsochModifyStreamProperties(
    IN WDFDEVICE      DeviceObject,
    IN WDFREQUEST     Irp,
    IN HANDLE         hResource,
    IN ULARGE_INTEGER ChannelMask,
    IN ULONG          fulSpeed
    );

NTSTATUS
t1394_IsochStop(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN HANDLE     hResource,
    IN ULONG      fulFlags
    );

NTSTATUS
t1394_IsochTalk(
    IN WDFDEVICE  DeviceObject,
    IN WDFREQUEST Irp,
    IN HANDLE     hResource,
    IN ULONG      fulFlags,
    CYCLE_TIME    StartTime
    );

void
t1394_IsochCallback(
    IN PDEVICE_EXTENSION    DeviceExtension,
    IN PISOCH_DETACH_DATA   IsochDetachData
    );

void
t1394_IsochTimeout(
    IN PKDPC                Dpc,
    IN PISOCH_DETACH_DATA   IsochDetachData,
    IN PVOID                SystemArgument1,
    IN PVOID                SystemArgument2
    );

void
t1394_IsochCleanup(
    IN PISOCH_DETACH_DATA   IsochDetachData
    );

NTSTATUS
t1394_IsochDetachCompletionRoutine(
    IN PDEVICE_OBJECT       DeviceObject,
    IN PIRP                 Irp,
    IN PISOCH_DETACH_DATA   IsochDetachData
    );

NTSTATUS
t1394_IsochAttachCompletionRoutine(
    IN PDEVICE_OBJECT       DeviceObject,
    IN PIRP                 Irp,
    IN PISOCH_DETACH_DATA   IsochDetachData
    );

//
// util.c
//
NTSTATUS
t1394_SubmitIrpSynch(
    IN WDFIOTARGET IoTarget,
    IN WDFREQUEST  Irp,
    IN PIRB        Irb
    );


BOOLEAN
t1394_IsOnList(
    PLIST_ENTRY Entry,
    PLIST_ENTRY List
    );

VOID
t1394_UpdateGenerationCount (
    IN  WDFDEVICE Device
    );


//
// 1394vdev.c
//
DRIVER_INITIALIZE DriverEntry;


//
// ioctl.c
//
EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL t1394_EvtIoDeviceControl;

//
// pnp.c
//
EVT_WDF_DRIVER_DEVICE_ADD t1394_EvtDeviceAdd;
EVT_WDF_DEVICE_PREPARE_HARDWARE t1394_EvtPrepareHardware;
EVT_WDF_DEVICE_RELEASE_HARDWARE t1394_EvtReleaseHardware;
EVT_WDF_DEVICE_D0_ENTRY t1394_EvtDeviceD0Entry;
EVT_WDF_DEVICE_D0_EXIT t1394_EvtDeviceD0Exit;
EVT_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP t1394_EvtDeviceSelfManagedIoCleanup;

PCHAR
DbgDevicePowerString(
    IN WDF_POWER_DEVICE_STATE Type
    );



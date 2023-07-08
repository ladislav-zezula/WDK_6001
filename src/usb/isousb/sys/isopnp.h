/*++

Copyright (c) 2004  Microsoft Corporation

Module Name:

    isopnp.h

Abstract:

Environment:

    Kernel mode

Notes:

    Copyright (c) 2004 Microsoft Corporation.
    All Rights Reserved.

--*/

#ifndef _ISOUSB_PNP_H
#define _ISOUSB_PNP_H

#define REMOTE_WAKEUP_MASK 0x20

IO_COMPLETION_ROUTINE IsoUsb_SyncCompletionRoutine;
IO_WORKITEM_ROUTINE IdleRequestWorkerRoutine;
DRIVER_DISPATCH IsoUsb_DispatchPnP;
DRIVER_DISPATCH IsoUsb_DispatchClean;

NTSTATUS
HandleStartDevice(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP           Irp
    );

NTSTATUS
CanStopDevice(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP           Irp
    );

NTSTATUS
HandleQueryStopDevice(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP           Irp
    );

NTSTATUS
HandleCancelStopDevice(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP           Irp
    );

NTSTATUS
HandleStopDevice(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP           Irp
    );

NTSTATUS
CanRemoveDevice(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP           Irp
    );

NTSTATUS
HandleQueryRemoveDevice(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP           Irp
    );

NTSTATUS
HandleCancelRemoveDevice(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP           Irp
    );

NTSTATUS
HandleSurpriseRemoval(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP           Irp
    );

NTSTATUS
HandleRemoveDevice(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP           Irp
    );

NTSTATUS
HandleQueryCapabilities(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP           Irp
    );

NTSTATUS
IsoUsb_SyncPassDownIrp (
    IN PDEVICE_OBJECT   DeviceObject,
    IN PIRP             Irp
    );

NTSTATUS
IsoUsb_SyncSendUsbRequest (
    IN PDEVICE_OBJECT   DeviceObject,
    IN PURB             Urb
    );

NTSTATUS
IsoUsb_GetDescriptor (
    IN PDEVICE_OBJECT   DeviceObject,
    IN UCHAR            Recipient,
    IN UCHAR            DescriptorType,
    IN UCHAR            Index,
    IN USHORT           LanguageId,
    IN ULONG            RetryCount,
    IN ULONG            DescriptorLength,
    OUT PUCHAR         *Descriptor
    );

NTSTATUS
IsoUsb_GetDescriptors (
    IN PDEVICE_OBJECT   DeviceObject
    );

PUSBD_INTERFACE_LIST_ENTRY
IsoUsb_BuildInterfaceList (
    PUSB_CONFIGURATION_DESCRIPTOR   ConfigurationDescriptor
    );

NTSTATUS
IsoUsb_SelectConfiguration (
    IN PDEVICE_OBJECT   DeviceObject
    );

NTSTATUS
IsoUsb_SelectAlternateInterface (
    IN PDEVICE_OBJECT   DeviceObject,
    IN UCHAR            InterfaceNumber,
    IN UCHAR            AlternateSetting
    );

NTSTATUS
IsoUsb_UnConfigure (
    IN PDEVICE_OBJECT   DeviceObject
    );

NTSTATUS
IsoUsb_AbortResetPipe (
    IN PDEVICE_OBJECT       DeviceObject,
    IN USBD_PIPE_HANDLE     PipeHandle,
    IN BOOLEAN              ResetPipe
    );

NTSTATUS
IsoUsb_AbortPipes(
    IN PDEVICE_OBJECT DeviceObject
    );

VOID
DpcRoutine(
    IN PKDPC Dpc,
    IN PVOID DeferredContext,
    IN PVOID SystemArgument1,
    IN PVOID SystemArgument2
    );

VOID
ProcessQueuedRequests(
    IN OUT PDEVICE_EXTENSION DeviceExtension
    );

VOID
GetBusInterfaceVersion(
    IN PDEVICE_OBJECT DeviceObject
    );

NTSTATUS
IsoUsb_GetRegistryDword(
    IN     PWCHAR RegPath,
    IN     PWCHAR ValueName,
    IN OUT PULONG Value
    );

NTSTATUS
ReleaseMemory(
    IN PDEVICE_OBJECT DeviceObject
    );

LONG
IsoUsb_IoIncrement(
    IN OUT PDEVICE_EXTENSION DeviceExtension
    );

LONG
IsoUsb_IoDecrement(
    IN OUT PDEVICE_EXTENSION DeviceExtension
    );

BOOLEAN
CanDeviceSuspend(
    IN PDEVICE_EXTENSION DeviceExtension
    );


#if DBG

PCHAR
PnPMinorFunctionString (
    IN UCHAR MinorFunction
    );

VOID
DumpDeviceDesc (
    PUSB_DEVICE_DESCRIPTOR   DeviceDesc
);

VOID
DumpConfigDesc (
    PUSB_CONFIGURATION_DESCRIPTOR   ConfigDesc
);

VOID
DumpConfigurationDescriptor (
    PUSB_CONFIGURATION_DESCRIPTOR   ConfigDesc
);

VOID
DumpInterfaceDescriptor (
    PUSB_INTERFACE_DESCRIPTOR   InterfaceDesc
);

VOID
DumpEndpointDescriptor (
    PUSB_ENDPOINT_DESCRIPTOR    EndpointDesc
);

VOID
DumpInterfaceInformation (
    PUSBD_INTERFACE_INFORMATION InterfaceInfo
);

PCHAR
UsbdPipeTypeString (
    USBD_PIPE_TYPE  PipeType
);

#endif


#endif



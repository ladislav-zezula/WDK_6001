/*++
Copyright (c) 1990-2000    Microsoft Corporation All Rights Reserved

Module Name:

    power.h

Abstract:

    This module contains the declarations used by power.c

Environment:

    user and kernel

--*/

#ifndef __POWER_H
#define __POWER_H

#define MAGIC_NUMBER -1

typedef enum {

    IRP_NEEDS_FORWARDING = 1,
    IRP_ALREADY_FORWARDED

} IRP_DIRECTION;

typedef struct _POWER_COMPLETION_CONTEXT {

    PDEVICE_OBJECT  DeviceObject;
    PIRP            SIrp;
} POWER_COMPLETION_CONTEXT, *PPOWER_COMPLETION_CONTEXT;


DRIVER_DISPATCH PciDrvDispatchPowerDefault;

DRIVER_DISPATCH PciDrvDispatchQueryPowerState;

DRIVER_DISPATCH PciDrvDispatchSetPowerState;

DRIVER_DISPATCH PciDrvDispatchSystemPowerIrp;

DRIVER_DISPATCH PciDrvDispatchDeviceQueryPower;

DRIVER_DISPATCH PciDrvDispatchDeviceSetPower;

IO_COMPLETION_ROUTINE PciDrvCompletionSystemPowerUp;

IO_COMPLETION_ROUTINE PciDrvCompletionDevicePowerUp;

VOID
PciDrvCallbackHandleDeviceQueryPower(
    __in PDEVICE_OBJECT       DeviceObject,
    __in PVOID                Context
    );

VOID
PciDrvCallbackHandleDeviceSetPower(
    __in PDEVICE_OBJECT      DeviceObject,
    __in PWORKER_ITEM_CONTEXT Context
    );

VOID
PciDrvQueueCorrespondingDeviceIrp(
    __in PIRP SIrp,
    __in PDEVICE_OBJECT DeviceObject
    );

VOID
PciDrvCompletionOnFinalizedDeviceIrp(
    __in  PDEVICE_OBJECT              DeviceObject,
    __in  UCHAR                       MinorFunction,
    __in  POWER_STATE                 PowerState,
    __in  PVOID   PowerContext,
    __in  PIO_STATUS_BLOCK            IoStatus
    );

NTSTATUS
PciDrvFinalizeDevicePowerIrp(
    __in  PDEVICE_OBJECT      DeviceObject,
    __in  PIRP                Irp,
    __in  IRP_DIRECTION       Direction,
    __in  NTSTATUS            Result
    );

NTSTATUS
PciDrvPowerBeginQueuingIrps(
    __in  PDEVICE_OBJECT      DeviceObject,
    __in  ULONG               IrpIoCharges,
    __in  BOOLEAN             Query
    );

NTSTATUS
PciDrvGetPowerPoliciesDeviceState(
    __in  PIRP                SIrp,
    __in  PDEVICE_OBJECT      DeviceObject,
    __out DEVICE_POWER_STATE *DevicePowerState
    );

NTSTATUS
PciDrvCanSuspendDevice(
    __in PDEVICE_OBJECT   DeviceObject
    );

PCHAR
DbgPowerMinorFunctionString(
    __in UCHAR MinorFunction
    );

PCHAR
DbgSystemPowerString(
    __in SYSTEM_POWER_STATE Type
    );

PCHAR
DbgDevicePowerString(
    __in DEVICE_POWER_STATE Type
    );


#endif



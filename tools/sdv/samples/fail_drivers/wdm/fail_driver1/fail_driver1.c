/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    fail_driver1.c

Abstract:

    This is a sample driver that contains intentionally placed
    code defects in order to illustrate how Static Driver Verifier
    works. This driver is not functional and not intended as a 
    sample for real driver development projects.

Environment:

    Kernel mode

--*/

#include "fail_driver1.h"

#define _DRIVER_NAME_ "fail_driver1"

#ifdef ALLOC_PRAGMA
#pragma alloc_text (INIT, DriverEntry)
#pragma alloc_text (PAGE, DriverAddDevice)
#pragma alloc_text (PAGE, DispatchCreate)
#pragma alloc_text (PAGE, DispatchRead)
#pragma alloc_text (PAGE, DispatchPower)
#pragma alloc_text (PAGE, DispatchSystemControl)
#pragma alloc_text (PAGE, DispatchPnp)
#pragma alloc_text (PAGE, DriverUnload)
#endif

NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT  DriverObject,
    IN PUNICODE_STRING RegistryPath
    )
{

    UNREFERENCED_PARAMETER(RegistryPath);
    DriverObject->MajorFunction[IRP_MJ_CREATE]         = DispatchCreate;
    DriverObject->MajorFunction[IRP_MJ_READ]           = DispatchRead;
    DriverObject->MajorFunction[IRP_MJ_POWER]          = DispatchPower;
    DriverObject->MajorFunction[IRP_MJ_SYSTEM_CONTROL] = DispatchSystemControl;
    DriverObject->MajorFunction[IRP_MJ_PNP]            = DispatchPnp;
    DriverObject->DriverExtension->AddDevice           = DriverAddDevice;
    DriverObject->DriverUnload                         = DriverUnload;

    return STATUS_SUCCESS;
}

NTSTATUS
DriverAddDevice(
    IN PDRIVER_OBJECT DriverObject,
    IN PDEVICE_OBJECT PhysicalDeviceObject
    )
{
    UNREFERENCED_PARAMETER(DriverObject);
    UNREFERENCED_PARAMETER(PhysicalDeviceObject);
    return STATUS_SUCCESS;
}

NTSTATUS
DispatchCreate (
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    )
{   
    /*
      This defect is injected for the "NullExFreePool" rule.
    */
    PVOID *badPointer = NULL;

    UNREFERENCED_PARAMETER(DeviceObject);
    UNREFERENCED_PARAMETER(Irp);
    
    ExFreePool(badPointer);
	
    return STATUS_SUCCESS;
}

NTSTATUS
DispatchRead (
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    )
{  
    /*
       This defect is injected for the "SpinLock" rule.
    */
    KSPIN_LOCK  queueLock;
    KIRQL oldIrql;

    UNREFERENCED_PARAMETER(DeviceObject);
    UNREFERENCED_PARAMETER(Irp);
     
    KeAcquireSpinLock(&queueLock, &oldIrql);
	
    return STATUS_SUCCESS;
}

NTSTATUS
DispatchPower (
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    )
{
    UNREFERENCED_PARAMETER(DeviceObject);
    UNREFERENCED_PARAMETER(Irp);  

    return STATUS_SUCCESS;
}

NTSTATUS
DispatchSystemControl (
    IN  PDEVICE_OBJECT  DeviceObject,
    IN  PIRP            Irp
    )
{   
    /*
       This defect is injected for the "CancelSpinLock" rule.
    */
    KIRQL oldIrql;

    UNREFERENCED_PARAMETER(DeviceObject);
    UNREFERENCED_PARAMETER(Irp);
    
    IoAcquireCancelSpinLock(&oldIrql);
	
    return STATUS_SUCCESS;
}

NTSTATUS
DispatchPnp (
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    )
{   
    /*
       This defect is injected for "LowerDriverReturn" rule.
    */
    NTSTATUS status = IoCallDriver(DeviceObject,Irp);

    status = STATUS_SUCCESS;

    return status;
}

VOID
DriverUnload(
    IN PDRIVER_OBJECT DriverObject
    )
{
    UNREFERENCED_PARAMETER(DriverObject);
     
    return;
}

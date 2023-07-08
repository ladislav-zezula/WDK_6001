/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    Driver.c

Abstract:

    This is a sample driver that contains intentionally placed
    code defects in order to illustrate how PREfast for Drivers (PFD)
    works. This driver is not functional and not intended as a 
    sample for real driver development projects. 

Environment:

    Kernel mode

--*/

#include "Driver.h"

#define _DRIVER_NAME_ "Driver"

#ifdef __cplusplus
extern " C "
#endif
ULONG _fltused=1;

#ifdef ALLOC_PRAGMA
#pragma alloc_text (INIT, DriverEntry)
#pragma alloc_text (PAGE, DriverAddDevice)
#pragma alloc_text (PAGE, DispatchPnp)
#pragma alloc_text (PAGE, DispatchPower)
#pragma alloc_text (PAGE, DispatchSystemControl)
#pragma alloc_text (PAGE, DriverUnload)
#endif

// A function to cause PFD to register warning 28195
void * malloc(size_t s) { return NULL; }

NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT  DriverObject,
    IN PUNICODE_STRING RegistryPath
    )
{
    DriverObject->MajorFunction[IRP_MJ_PNP]            = DispatchPnp;
    DriverObject->MajorFunction[IRP_MJ_POWER]          = DispatchPower;
    DriverObject->MajorFunction[IRP_MJ_SYSTEM_CONTROL] = DispatchSystemControl;
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
    //
    // A floating point operation that causes PFD to register Warning-28110
    //
    
    double a, b, c;

    a = 2.85;
    b = 7.87;
    c = (b/a);

    return STATUS_SUCCESS;
}

NTSTATUS
DispatchPnp (
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP           Irp
    )
{  
    //
    // A memory leaking operation that causes PFD to register Warning-6014 and Warning-28193.
    //
    
    char *buffer = malloc(10); 
    

    return STATUS_SUCCESS;
}

NTSTATUS
DispatchPower (
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP           Irp
    )
{
    return STATUS_SUCCESS;
}

NTSTATUS
DispatchSystemControl (
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP           Irp
    )
{   
    return STATUS_SUCCESS;
}

VOID
DriverUnload(
    IN PDRIVER_OBJECT DriverObject
    )
{
    return;
}
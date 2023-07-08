/*++

Copyright (c) 1998 Microsoft Corporation

Module Name:

    1394vdev.c

Abstract:

--*/

#include "pch.h"

#if DBG

unsigned char t1394DebugLevel = TL_WARNING;

#endif

NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT   DriverObject,
    IN PUNICODE_STRING  RegistryPath
    )
/*++

Routine Description:

    Installable driver initialization entry point.
    This entry point is called directly by the I/O system.

Arguments:

    DriverObject - pointer to the driver object

    RegistryPath - pointer to a unicode string representing the path,
                   to driver-specific key in the registry.

Return Value:

    STATUS_SUCCESS if successful,
    STATUS_UNSUCCESSFUL otherwise.

--*/
{
    NTSTATUS    ntStatus = STATUS_SUCCESS;
    WDF_DRIVER_CONFIG      config;

    ENTER("DriverEntry");

    TRACE(TL_TRACE, ("1394VDev Sample - Driver Framework Edition \n"));
    TRACE(TL_TRACE, ("Built %s %s\n", __DATE__, __TIME__));

    //
    // Initialize the Driver Config structure..
    //
    WDF_DRIVER_CONFIG_INIT(
        &config,
        t1394_EvtDeviceAdd
    );

    //
    // Create a WDFDRIVER object.
    //
    ntStatus = WdfDriverCreate(
                 DriverObject,
                 RegistryPath,
                 WDF_NO_OBJECT_ATTRIBUTES,
                 &config,
                 WDF_NO_HANDLE
             );

    if (!NT_SUCCESS(ntStatus)) {
        TRACE(TL_ERROR, ("WdfDriverCreate failed with status %x\n", ntStatus));
    }

    EXIT("DriverEntry", ntStatus);
    return(ntStatus);
} // DriverEntry


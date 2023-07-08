/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    fail_driver7.h

Environment:

    Kernel mode

--*/

#include <NTDDK.h>  
#include <wdf.h>

#include "fail_library7.h"

DRIVER_INITIALIZE DriverEntry;

EVT_WDF_DRIVER_DEVICE_ADD EvtDriverDeviceAdd;

EVT_WDF_IO_QUEUE_IO_READ EvtIoRead;

EVT_WDF_IO_QUEUE_IO_WRITE EvtIoWrite;

EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL EvtIoDeviceControl;

EVT_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL EvtIoInternalDeviceControl;
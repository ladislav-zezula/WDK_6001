/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    fail_driver3.h

Environment:

    Kernel mode

--*/

#include <NTDDK.h>  
#include <wdf.h>

#include "fail_library3.h"

DRIVER_INITIALIZE DriverEntry; 

EVT_WDF_DRIVER_DEVICE_ADD EvtDriverDeviceAdd;

EVT_WDF_IO_QUEUE_IO_READ EvtIoRead;

EVT_WDF_IO_QUEUE_IO_WRITE EvtIoWrite;

EVT_WDF_IO_QUEUE_IO_STOP EvtIoStop;

EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL EvtIoDeviceControl;

EVT_WDF_DRIVER_UNLOAD EvtDriverUnload;

EVT_WDF_TIMER EvtTimerFunc;

EVT_WDF_REQUEST_CANCEL EvtRequestCancel;

EVT_WDF_DEVICE_D0_ENTRY DeviceD0Entry;

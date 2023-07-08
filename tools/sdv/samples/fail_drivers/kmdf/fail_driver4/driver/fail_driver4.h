/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    fail_driver4.h

Environment:

    Kernel mode

--*/

#include <NTDDK.h>  
#include <wdf.h>

#include "fail_library4.h"

DRIVER_INITIALIZE DriverEntry; 

EVT_WDF_IO_QUEUE_IO_READ EvtIoRead;

EVT_WDF_IO_QUEUE_IO_WRITE EvtIoWrite;

EVT_WDF_REQUEST_CANCEL EvtRequestCancel;

EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL EvtIoDeviceControl;

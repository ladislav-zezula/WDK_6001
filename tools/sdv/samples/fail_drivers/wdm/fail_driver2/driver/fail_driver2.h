/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    fail_driver2.h

Environment:

    Kernel mode

--*/

#include <wdm.h>
#include "fail_library2.h"

DRIVER_INITIALIZE DriverEntry;

DRIVER_ADD_DEVICE DriverAddDevice;

__drv_dispatchType(IRP_MJ_CREATE)
DRIVER_DISPATCH DispatchCreate;

__drv_dispatchType(IRP_MJ_READ)
DRIVER_DISPATCH DispatchRead;

__drv_dispatchType(IRP_MJ_WRITE)
DRIVER_DISPATCH DispatchWrite;

__drv_dispatchType(IRP_MJ_POWER)
DRIVER_DISPATCH DispatchPower;

__drv_dispatchType(IRP_MJ_SYSTEM_CONTROL)
DRIVER_DISPATCH DispatchSystemControl;

DRIVER_UNLOAD DriverUnload;

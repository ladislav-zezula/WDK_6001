/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    fail_driver1.h

Environment:

    Kernel mode

--*/

#include <wdm.h>

DRIVER_INITIALIZE DriverEntry;

DRIVER_ADD_DEVICE DriverAddDevice;

__drv_dispatchType(IRP_MJ_CREATE)
DRIVER_DISPATCH DispatchCreate;

__drv_dispatchType(IRP_MJ_READ)
DRIVER_DISPATCH DispatchRead;

__drv_dispatchType(IRP_MJ_POWER)
DRIVER_DISPATCH DispatchPower;

__drv_dispatchType(IRP_MJ_SYSTEM_CONTROL)
DRIVER_DISPATCH DispatchSystemControl;

__drv_dispatchType(IRP_MJ_PNP)
DRIVER_DISPATCH DispatchPnp;

DRIVER_UNLOAD DriverUnload;

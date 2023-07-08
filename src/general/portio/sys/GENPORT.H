/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

Module Name:

    genport.h

Abstract:

    Include file for Generic Port I/O Example Driver

Environment:

    Kernel mode

--*/

#if     !defined(__GENPORT_H__)
#define __GENPORT_H__

#include <ntddk.h>
#include <wdmsec.h>

#include "gpioctl.h"        // Get IOCTL interface definitions
#include <dontuse.h>

// NT device name
#define GPD_DEVICE_NAME L"\\Device\\Gpd0"

// File system device name.   When you execute a CreateFile call to open the
// device, use "\\.\GpdDev", or, given C's conversion of \\ to \, use
// "\\\\.\\GpdDev"

#define DOS_DEVICE_NAME L"\\DosDevices\\GpdDev"

#define PORTIO_TAG 'TROP'

//
// These are the states FDO transition to upon
// receiving a specific PnP Irp. Refer to the PnP Device States
// diagram in DDK documentation for better understanding.
//

typedef enum _DEVICE_PNP_STATE {

    NotStarted = 0,         // Not started yet
    Started,                // Device has received the START_DEVICE IRP
    StopPending,            // Device has received the QUERY_STOP IRP
    Stopped,                // Device has received the STOP_DEVICE IRP
    RemovePending,          // Device has received the QUERY_REMOVE IRP
    SurpriseRemovePending,  // Device has received the SURPRISE_REMOVE IRP
    Deleted                 // Device has received the REMOVE_DEVICE IRP

} DEVICE_PNP_STATE;

#define INITIALIZE_PNP_STATE(_Data_)    \
        (_Data_)->DevicePnPState =  NotStarted;\
        (_Data_)->PreviousPnPState = NotStarted;

#define SET_NEW_PNP_STATE(_Data_, _state_) \
        (_Data_)->PreviousPnPState =  (_Data_)->DevicePnPState;\
        (_Data_)->DevicePnPState = (_state_);

#define RESTORE_PREVIOUS_PNP_STATE(_Data_)   \
        (_Data_)->DevicePnPState =   (_Data_)->PreviousPnPState;\

// driver local data structure specific to each device object
typedef struct _LOCAL_DEVICE_INFO {
    PVOID               PortBase;       // base port address
    ULONG               PortCount;      // Count of I/O addresses used.
    ULONG               PortMemoryType; // HalTranslateBusAddress MemoryType
    PDEVICE_OBJECT      DeviceObject;   // The Gpd device object.
    PDEVICE_OBJECT      NextLowerDriver;     // The top of the stack
    DEVICE_PNP_STATE    DevicePnPState;   // Track the state of the device
    DEVICE_PNP_STATE    PreviousPnPState; // Remembers the previous pnp state
    BOOLEAN             PortWasMapped;  // If TRUE, we have to unmap on unload
    IO_REMOVE_LOCK      RemoveLock;
} LOCAL_DEVICE_INFO, *PLOCAL_DEVICE_INFO;


#if DBG
#define DebugPrint(_x_) \
               DbgPrint ("PortIo:"); \
               DbgPrint _x_;

#else
#define DebugPrint(_x_)
 #endif


/********************* function prototypes ***********************************/
//


DRIVER_INITIALIZE DriverEntry;

DRIVER_ADD_DEVICE GpdAddDevice;

__drv_dispatchType(IRP_MJ_CREATE)
__drv_dispatchType(IRP_MJ_CLOSE)
__drv_dispatchType(IRP_MJ_DEVICE_CONTROL)
DRIVER_DISPATCH GpdDispatch;

__drv_dispatchType(IRP_MJ_PNP)
DRIVER_DISPATCH GpdDispatchPnp;

DRIVER_DISPATCH GpdStartDevice;

__drv_dispatchType(IRP_MJ_POWER)
DRIVER_DISPATCH GpdDispatchPower;

__drv_dispatchType(IRP_MJ_SYSTEM_CONTROL)
DRIVER_DISPATCH GpdDispatchSystemControl;

DRIVER_UNLOAD GpdUnload;

NTSTATUS
GpdCompletionRoutine(
    __in PDEVICE_OBJECT   DeviceObject,
    __in PIRP             Irp,
    __in PVOID            Context
    );

NTSTATUS
GpdIoctlReadPort(
    __in  PLOCAL_DEVICE_INFO pLDI,
    __in  PIRP pIrp,
    __in  PIO_STACK_LOCATION IrpStack,
    __in  ULONG IoctlCode
    );

NTSTATUS
GpdIoctlWritePort(
    __in  PLOCAL_DEVICE_INFO pLDI,
    __in  PIRP pIrp,
    __in  PIO_STACK_LOCATION IrpStack,
    __in  ULONG IoctlCode
    );

PCHAR
PnPMinorFunctionString (
    UCHAR MinorFunction
);

#endif



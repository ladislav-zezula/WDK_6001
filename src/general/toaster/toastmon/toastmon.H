/*++

Copyright (c) 1990-2000 Microsoft Corporation, All Rights Reserved

Module Name:

    toastmon.h

Abstract:


Environment:

    Kernel mode

Revision History:

--*/
#include <ntddk.h>
#include <dontuse.h>

#if     !defined(__TOASTMON_H__)
#define __TOASTMON_H__

#define DRIVER_TAG 'NOMT'

#define INITIALIZE_PNP_STATE(_Data_)    \
        (_Data_)->DevicePnPState =  NotStarted;\
        (_Data_)->PreviousPnPState = NotStarted;

#define SET_NEW_PNP_STATE(_Data_, _state_) \
        (_Data_)->PreviousPnPState =  (_Data_)->DevicePnPState;\
        (_Data_)->DevicePnPState = (_state_);

#define RESTORE_PREVIOUS_PNP_STATE(_Data_)   \
        (_Data_)->DevicePnPState =   (_Data_)->PreviousPnPState;\
//
// These are the states a PDO or FDO transition upon
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
    Deleted,                // Device has received the REMOVE_DEVICE IRP
    UnKnown                 // Unknown state

} DEVICE_PNP_STATE;


typedef struct _DEVICE_EXTENSION {
    PDEVICE_OBJECT      DeviceObject; // The ToastMon device object.
    PDEVICE_OBJECT      TopOfStack;   // The top of the stack
    DEVICE_PNP_STATE     DevicePnPState; // Track PnP state
    DEVICE_PNP_STATE     PreviousPnPState;
    IO_REMOVE_LOCK      RemoveLock;   //
    PVOID                NotificationHandle; // Interface notification handle
    LIST_ENTRY            DeviceListHead; // List to queue the target device info
    FAST_MUTEX          ListMutex;    // Synchronize access to DeviceList
    PVOID		WMIDeviceArrivalNotificationObject;
} DEVICE_EXTENSION, *PDEVICE_EXTENSION;


typedef struct _DEVICE_INFO {
    PDEVICE_EXTENSION    DeviceExtension; // Our FDO device extension
    PDEVICE_OBJECT      TargetDeviceObject; // Toplevel deviceobject of the target device
    PDEVICE_OBJECT      Pdo;          // It's PDO
    PFILE_OBJECT        FileObject;
    PVOID                NotificationHandle; //Device change notification handle
    LIST_ENTRY            ListEntry; // Entry to chain to the listhead
    UNICODE_STRING        SymbolicLink;
} DEVICE_INFO, *PDEVICE_INFO;


#if DBG
#define DebugPrint(_x_) \
               DbgPrint ("ToastMon:"); \
               DbgPrint _x_;

#define TRAP() DbgBreakPoint()

#else
#define DebugPrint(_x_)
#define TRAP()
#endif


/********************* function prototypes ***********************************/
//

DRIVER_INITIALIZE DriverEntry;

DRIVER_ADD_DEVICE ToastMon_AddDevice;

__drv_dispatchType(IRP_MJ_CREATE)
__drv_dispatchType(IRP_MJ_CLOSE)
__drv_dispatchType(IRP_MJ_DEVICE_CONTROL)
DRIVER_DISPATCH ToastMon_Dispatch;

__drv_dispatchType(IRP_MJ_PNP)
DRIVER_DISPATCH ToastMon_DispatchPnp;

__drv_dispatchType(IRP_MJ_POWER)
DRIVER_DISPATCH ToastMon_DispatchPower;

DRIVER_DISPATCH ToastMon_StartDevice;

__drv_dispatchType(IRP_MJ_SYSTEM_CONTROL)
DRIVER_DISPATCH ToastMon_DispatchSystemControl;

DRIVER_UNLOAD ToastMon_Unload;

NTSTATUS
ToastMon_CompletionRoutine(
    __in PDEVICE_OBJECT   DeviceObject,
    __in PIRP             Irp,
    __in PVOID            Context
    );

NTSTATUS
ToastMon_PnpNotifyDeviceChange(
    __in  PTARGET_DEVICE_REMOVAL_NOTIFICATION    NotificationStruct,
    __in  PVOID                                  Context
    );


NTSTATUS
ToastMon_PnpNotifyInterfaceChange(
    __in  PDEVICE_INTERFACE_CHANGE_NOTIFICATION NotificationStruct,
    __in  PVOID                        Context
    );

NTSTATUS
ToastMon_GetTargetDevicePdo(
    __in PDEVICE_OBJECT DeviceObject,
    __out PDEVICE_OBJECT* PhysicalDeviceObject
    );

NTSTATUS
ToastMon_OpenTargetDevice(
    __in PDEVICE_INFO        List
    );

VOID
ToastMon_CloseTargetDevice(
    __in PDEVICE_INFO        List
    );

PCHAR
PnPMinorFunctionString (
    __in UCHAR MinorFunction
);

NTSTATUS
RegisterForWMINotification(
    __in PDEVICE_EXTENSION DeviceExt
    );

VOID
UnregisterForWMINotification(
    __in PDEVICE_EXTENSION DeviceExt
);

VOID
WmiNotificationCallback(
    __in PVOID Wnode,
    __in PVOID Context
    );

#endif


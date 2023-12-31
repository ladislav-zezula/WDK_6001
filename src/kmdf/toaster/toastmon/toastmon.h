/*++

Copyright (c) 1990-2000 Microsoft Corporation, All Rights Reserved

Module Name:

    toastmon.h

Abstract:

Environment:

    Kernel mode

--*/

#if     !defined(__TOASTMON_H__)
#define __TOASTMON_H__

#include <ntddk.h> //wdm.h>
#include <wdf.h>    // Driver Framework.

#define DRIVER_TAG                  'NOMT'
#define READ_BUF_SIZE           100
#define WRITE_BUF_SIZE          120

#define PERIODIC_TIMER_INTERVAL  1000 //ms

typedef enum _WORKITEM_STATE {
    WORKITEM_STATE_FREE =0,
    WORKITEM_STATE_BUSY = 1
} WORKITEM_STATE;


typedef struct _DEVICE_EXTENSION {
    WDFDEVICE           WdfDevice;
    WDFIOTARGET         ToasterTarget;
    PVOID               NotificationHandle; // Interface notification handle
    WDFCOLLECTION       TargetDeviceCollection;
    WDFWAITLOCK         TargetDeviceCollectionLock;
    PVOID               WMIDeviceArrivalNotificationObject;
} DEVICE_EXTENSION, *PDEVICE_EXTENSION;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DEVICE_EXTENSION, GetDeviceExtension)


typedef struct  _TARGET_DEVICE_INFO {
    PDEVICE_EXTENSION    DeviceExtension; // Our FDO device extension
    LIST_ENTRY           ListEntry; // Entry to chain to the listhead
    WDFREQUEST          ReadRequest;
    WDFREQUEST          WriteRequest;
    WDFTIMER            TimerForPostingRequests;
    WDFWORKITEM       WorkItemForPostingRequests;
    WORKITEM_STATE     WorkItemState;
} TARGET_DEVICE_INFO, *PTARGET_DEVICE_INFO;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(TARGET_DEVICE_INFO, GetTargetDeviceInfo)

typedef struct _TIMER_CONTEXT {

   WDFIOTARGET IoTarget;

} TIMER_CONTEXT, *PTIMER_CONTEXT ;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(TIMER_CONTEXT, GetTimerContext)

typedef struct _WORKITEM_CONTEXT {

   WDFIOTARGET IoTarget;

} WORKITEM_CONTEXT, *PWORKITEM_CONTEXT ;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(WORKITEM_CONTEXT, GetWorkItemContext)


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

EVT_WDF_DRIVER_DEVICE_ADD ToastMon_EvtDeviceAdd;

EVT_WDF_DEVICE_CONTEXT_CLEANUP ToastMon_EvtDeviceContextCleanup;

EVT_WDF_IO_TARGET_QUERY_REMOVE ToastMon_EvtIoTargetQueryRemove;
EVT_WDF_IO_TARGET_REMOVE_CANCELED ToastMon_EvtIoTargetRemoveCanceled;
EVT_WDF_IO_TARGET_REMOVE_COMPLETE ToastMon_EvtIoTargetRemoveComplete;

EVT_WDF_WORKITEM Toastmon_EvtWorkItemPostRequests;
EVT_WDF_TIMER Toastmon_EvtTimerPostRequests;

EVT_WDF_REQUEST_COMPLETION_ROUTINE Toastmon_ReadRequestCompletionRoutine;
EVT_WDF_REQUEST_COMPLETION_ROUTINE Toastmon_WriteRequestCompletionRoutine;

NTSTATUS
ToastMon_PnpNotifyInterfaceChange(
    IN  PDEVICE_INTERFACE_CHANGE_NOTIFICATION NotificationStruct,
    IN  PVOID                        Context
    );

NTSTATUS
Toastmon_OpenDevice(
    WDFDEVICE Device,
    PUNICODE_STRING SymbolicLink,
    WDFIOTARGET *Target
    );

NTSTATUS
ToastMon_PostReadRequests(
    IN WDFIOTARGET IoTarget
    );

NTSTATUS
ToastMon_PostWriteRequests(
    IN WDFIOTARGET IoTarget
    );

NTSTATUS
RegisterForWMINotification(
    PDEVICE_EXTENSION DeviceExt
    );

VOID
UnregisterForWMINotification(
    PDEVICE_EXTENSION DeviceExt
    );

VOID
WmiNotificationCallback(
    IN PVOID Wnode,
    IN PVOID Context
    );

#endif


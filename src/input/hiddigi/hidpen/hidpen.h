/*++
    Copyright (c) Microsoft Corporation

    Module Name:
        hidpen.h

    Abstract:
        Contains definitions of all constants and data types for the
        serial pen hid driver.

    Environment:
        Kernel mode

--*/

#ifndef _HIDPEN_H
#define _HIDPEN_H

//
// Constants
//
#define HPEN_POOL_TAG                   'nepH'

//
// Pen Tablet Report IDs
//
#define REPORTID_PEN                    1
#define REPORTID_MOUSE                  2

// dwfHPen flag values
#define HPENF_DEVICE_STARTED            0x00000001
#define HPENF_DIGITIZER_STANDBY         0x00000002

#define ULONG_MAX                       0xffffffffUL
//
// Macros
//
#define GET_MINIDRIVER_DEVICE_EXTENSION(DO) \
    ((PDEVICE_EXTENSION)(((PHID_DEVICE_EXTENSION)(DO)->DeviceExtension)->MiniDeviceExtension))

#define GET_NEXT_DEVICE_OBJECT(DO) \
    (((PHID_DEVICE_EXTENSION)(DO)->DeviceExtension)->NextDeviceObject)

#define GET_PDO(DO) \
    (((PHID_DEVICE_EXTENSION)(DO)->DeviceExtension)->PhysicalDeviceObject)

//
// Type Definitions
//
typedef struct _DEVICE_EXTENSION
{
    ULONG                 dwfHPen;      //flags
    PDEVICE_OBJECT        DevObj;       //fdo
    PDEVICE_OBJECT        pdo;          //pdo of the pen device
    PDEVICE_OBJECT        LowerDevObj;  //points to the serial device object
    IO_REMOVE_LOCK        RemoveLock;   //to protect IRP_MN_REMOVE_DEVICE
    KSPIN_LOCK            SpinLock;     //to protect the resync buffer
    DEVICE_POWER_STATE    PowerState;   //power state of the digitizer
    OEM_DATA              OemData;      //OEM specific data  
 } DEVICE_EXTENSION, *PDEVICE_EXTENSION;

typedef struct _WORKITEM_DATA
{
   POWER_STATE    NewPowerState;
   PIRP		  Irp;
   PIO_WORKITEM   workItem;
}WORKITEM_DATA, *PWORKITEM_DATA;


//
// Function prototypes
//

// hidpen.c
NTSTATUS EXTERNAL
DriverEntry(
    IN PDRIVER_OBJECT  DrvObj,
    IN PUNICODE_STRING RegPath
    );

DRIVER_DISPATCH HpenCreateClose;

NTSTATUS EXTERNAL
HpenCreateClose(
    IN PDEVICE_OBJECT DevObj,
    IN PIRP Irp
    );

DRIVER_DISPATCH HpenSystemControl;

NTSTATUS EXTERNAL
HpenSystemControl(
    IN PDEVICE_OBJECT DevObj,
    IN PIRP Irp
    );

DRIVER_ADD_DEVICE HpenAddDevice;

NTSTATUS EXTERNAL
HpenAddDevice(
    IN PDRIVER_OBJECT DrvObj,
    IN PDEVICE_OBJECT DevObj
    );

DRIVER_UNLOAD HpenUnload;

VOID EXTERNAL
HpenUnload(
    IN PDRIVER_OBJECT DrvObj
    );

NTSTATUS INTERNAL
RegQueryValue(
    IN  HANDLE  hkey,
    IN  LPCWSTR pszValueName,
    IN  ULONG   dwType,
    OUT PUCHAR  lpbData,
    IN  ULONG   dwcbData,
    OUT PULONG  pdwcbLen OPTIONAL
    );

NTSTATUS INTERNAL
RegSetValue(
    IN HANDLE  hkey,
    IN LPCWSTR pszValueName,
    IN ULONG   dwType,
    IN PUCHAR  lpbData,
    IN ULONG   dwcbData
    );

DRIVER_DISPATCH HpenPnp;
// pnp.c
NTSTATUS EXTERNAL
HpenPnp(
    IN PDEVICE_OBJECT DevObj,
    IN PIRP Irp
    );

DRIVER_DISPATCH HpenPower;

NTSTATUS EXTERNAL
HpenPower(
    IN PDEVICE_OBJECT DevObj,
    IN PIRP Irp
    );

NTSTATUS INTERNAL
SendSyncIrp(
    IN PDEVICE_OBJECT DevObj,
    IN PIRP           Irp,
    IN BOOLEAN        fCopyToNext
    );

IO_COMPLETION_ROUTINE IrpCompletion;

NTSTATUS INTERNAL
IrpCompletion(
    IN PDEVICE_OBJECT DevObj,
    IN PIRP           Irp,
    IN PVOID          Event
    );

IO_COMPLETION_ROUTINE DevicePowerIrpCompletion;

NTSTATUS INTERNAL
DevicePowerIrpCompletion(
    IN PDEVICE_OBJECT DevObj,
    IN PIRP           Irp,
    IN PVOID          Context
    );

DRIVER_DISPATCH HpenInternalIoctl;
// ioctl.c
NTSTATUS EXTERNAL
HpenInternalIoctl(
    IN PDEVICE_OBJECT DevObj,
    IN PIRP Irp
    );

NTSTATUS INTERNAL
GetDeviceDescriptor(
    IN PDEVICE_EXTENSION DevExt,
    IN PIRP              Irp
    );

NTSTATUS INTERNAL
GetReportDescriptor(
    IN PDEVICE_EXTENSION DevExt,
    IN PIRP              Irp
    );

NTSTATUS INTERNAL
ReadReport(
    IN PDEVICE_EXTENSION DevExt,
    IN PIRP              Irp,
    OUT BOOLEAN          *fSentDown
    );

NTSTATUS INTERNAL
GetString(
    IN PDEVICE_EXTENSION DevExt,
    IN PIRP              Irp
    );

NTSTATUS INTERNAL
GetAttributes(
    IN PDEVICE_EXTENSION DevExt,
    IN PIRP              Irp
    );

// OEM specific functions
NTSTATUS EXTERNAL
OemAddDevice(
    IN PDEVICE_EXTENSION DevExt
    );

NTSTATUS INTERNAL
OemStartDevice(
    IN PDEVICE_EXTENSION DevExt,
    IN PIRP              Irp
    );

NTSTATUS INTERNAL
OemStopDevice(
    IN PDEVICE_EXTENSION DevExt,
    IN PIRP              Irp
    );

NTSTATUS INTERNAL
OemInitDevice(
    IN PDEVICE_EXTENSION DevExt
    );

NTSTATUS INTERNAL
OemWakeupDevice(
    IN PDEVICE_EXTENSION DevExt
    );

NTSTATUS INTERNAL
OemStandbyDevice(
    IN PDEVICE_EXTENSION DevExt
    );

NTSTATUS INTERNAL
OemInitSerialPort(
    IN PDEVICE_EXTENSION DevExt
    );

NTSTATUS INTERNAL
OemReadReport(
    IN PDEVICE_EXTENSION DevExt,
    IN PIRP              Irp,
    OUT BOOLEAN          *fSentDown
    );

BOOLEAN INTERNAL
OemIsResyncDataValid(
    IN PDEVICE_EXTENSION DevExt
    );

NTSTATUS INTERNAL
OemNormalizeInputData(
    IN     PDEVICE_EXTENSION DevExt,
    IN OUT POEM_INPUT_REPORT InData
    );

IO_WORKITEM_ROUTINE WakeDeviceWorkItem;

VOID
  WakeDeviceWorkItem (
    IN PDEVICE_OBJECT  DevObj,
    IN PVOID  Context 
    );

NTSTATUS INTERNAL
SetDeviceReportDescriptor(
     IN PDEVICE_EXTENSION DevExt
     );

#endif  //ifndef _HIDPEN_H


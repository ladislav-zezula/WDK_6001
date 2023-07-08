/*++
    Copyright (c) 2006 Microsoft Corporation

    Module Name:
        VSerial.h

    Abstract:
        Contains definitions of all constants and data types for the
        serial pen hid driver.

    Environment:
        Kernel mode
--*/

#ifndef VSERIAL_H
#define VSERIAL_H

#include <ntddk.h>
#include <wdf.h>

#define HPEN_HARDWARE_IDS    L"ACPI\\MSVS010\0\0"
#define HPEN_HARDWARE_IDS_LENGTH sizeof (HPEN_HARDWARE_IDS)

typedef struct tagDEVICE_EXTENSION {
    KEVENT                           TerminateWorkerThread;
    ULONG                            WriteCount;
    ULONG                            ReadCount;
    PKTHREAD                         Thread;
    WDFKEY							 SimDevKey;
    CHAR                             DeviceData[500];
    ULONG                            ByteCount;
    HANDLE                           hDataFile;
    BOOLEAN                          IsDataFileActive;
    ULONG_PTR                        CurrentPos;
    ULONG_PTR                        LastPos;
    KSPIN_LOCK                       BufferLock;
    WDFQUEUE                         ReadQueue;
} SERIAL_DEVICE_EXTENSION, *PSERIAL_DEVICE_EXTENSION;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(SERIAL_DEVICE_EXTENSION, GetDeviceContext)

#define VSERIAL_TAG 'RLSV'

#define MAX_FILE_PATH               255
#define DEFAULT_FILE        L"\\??\\C:\\TempDir\\SimPenData.log"
#define CUSTOM_FILE_NAME    L"FileName"
#define SIMULATED_DEVICE_KEY_NAME L"\\Registry\\Machine\\Software\\Microsoft\\SimDevice"

#define READ_RESPONSE	    L"ReadResponse"
#define WRITE_RESPONSE	    L"WriteResponse"
#define CONTROL_RESPONSE    L"ControlResponse"
#define PNP_QUERY_RESPONSE  L"PnpQueryResponse"
#define CLOSE_RESPONSE      L"CloseResponse"
#define CREATE_RESPONSE     L"CreateResponse"
#define CLEANUP_RESPONSE    L"CleanupResponse"

#define IO_TIMEOUT          -40000000

///////////////////////////////////////////////////////////////////////////////
// Global functions

DRIVER_INITIALIZE DriverEntry;

//thread function
VOID ReadIrpThreadCompletionRoutine(PVOID pContext);
// I/O request handlers
VOID
ReadIrpCompletionRoutine(
    IN PVOID pContext
    );
NTSTATUS
QueryDesiredReadWriteResponse(
    IN UCHAR IrpMajorFunc,
    IN PSERIAL_DEVICE_EXTENSION DevExt
);

NTSTATUS
QueryDesiredControlResponse(
    IN ULONG_PTR controlCode,
    IN PSERIAL_DEVICE_EXTENSION DevExt
);

NTSTATUS
ReadDeviceBuffer(
    __out_bcount_full(readLength) CHAR* dataBuffer,
    IN size_t readLength,
    IN PSERIAL_DEVICE_EXTENSION    DevExt
    );

NTSTATUS
FillDeviceBuffer(
    IN PSERIAL_DEVICE_EXTENSION    DevExt
    );
NTSTATUS
OpenDeviceDataFile(
    IN PSERIAL_DEVICE_EXTENSION    DevExt
    );

NTSTATUS
DeleteDeviceDataFile(
    IN PSERIAL_DEVICE_EXTENSION    DevExt
    );

NTSTATUS
VSerialAddDevice(
    IN WDFDRIVER        Driver,
    IN PWDFDEVICE_INIT  DeviceInit
    );

NTSTATUS
VSerialEvtDeviceSelfManagedIoInit(
    IN WDFDEVICE  Device
    );

VOID
VSerialDeviceContextCleanup(
    IN WDFDEVICE  Device
    );

VOID
VSerialEvtIoWrite(
    IN WDFQUEUE         Queue,
    IN WDFREQUEST       Request,
    IN size_t           Length
    );

VOID
VSerialEvtIoRead(
    IN WDFQUEUE         Queue,
    IN WDFREQUEST       Request,
    IN size_t           Length
    );

NTSTATUS
VSerialWdmFileCreate(
    IN WDFDEVICE Device,
    IN PIRP Irp
    );

NTSTATUS
VSerialWdmFileCleanup(
    IN WDFDEVICE Device,
    IN PIRP Irp
    );

NTSTATUS
VSerialWdmFileClose(
    IN WDFDEVICE Device,
    IN PIRP Irp
    );

VOID
VSerialEvtIoDeviceControl(
    IN WDFQUEUE   Queue,
    IN WDFREQUEST Request,
    IN size_t     OutputBufferLength,
    IN size_t     InputBufferLength,
    IN ULONG      IoControlCode
    );

NTSTATUS
VSerialPnpIrpPreprocessCallback (
    IN WDFDEVICE Device,
    IN PIRP Irp
    );

NTSTATUS
RegQueryValue(
    IN  WDFKEY  hkey,
    IN  LPCWSTR pszValueName,
    IN  ULONG   dwType,
    OUT PVOID   lpbData,
    IN  ULONG   dwcbData,
    OUT PULONG  pdwcbLen OPTIONAL
    );
NTSTATUS
RegSetValue(
    IN WDFKEY  hkey,
    IN LPCWSTR pszValueName,
    IN ULONG   dwType,
    IN PUCHAR  lpbData,
    IN ULONG   dwcbData
    );

NTSTATUS
RegOpenDeviceKey(
	IN PSERIAL_DEVICE_EXTENSION DevExt
	);

#endif // VSERIAL_H



/*++
    Copyright (c) Microsoft Corporation

    Module Name:
        serial.h

    Abstract:
        Contains definitions of all Serial Port related functions.

    Environment:
        Kernel mode

--*/

#ifndef _SERIAL_H
#define _SERIAL_H

//
// Constants
//

// Serial Port FIFO Control Register bits for Receiver Trigger Level
#define SERIAL_IOC_FCR_RCVR_TRIGGER_01_BYTE     0
#define SERIAL_IOC_FCR_RCVR_TRIGGER_04_BYTES    SERIAL_IOC_FCR_RCVR_TRIGGER_LSB
#define SERIAL_IOC_FCR_RCVR_TRIGGER_08_BYTES    SERIAL_IOC_FCR_RCVR_TRIGGER_MSB
#define SERIAL_IOC_FCR_RCVR_TRIGGER_14_BYTES    (SERIAL_IOC_FCR_RCVR_TRIGGER_LSB |\
                                                 SERIAL_IOC_FCR_RCVR_TRIGGER_MSB)



typedef enum {

   IRPLOCK_CANCELABLE,
   IRPLOCK_CANCEL_STARTED,
   IRPLOCK_CANCEL_COMPLETE,
   IRPLOCK_COMPLETED

} IRPLOCK, *PIRPLOCK;


//
// Function prototypes
//

NTSTATUS INTERNAL
SerialSyncSendIoctl(
    IN ULONG          IoctlCode,
    IN PDEVICE_OBJECT DevObj,
    IN PVOID          InBuffer OPTIONAL,
    IN ULONG          InBufferLen,
    OUT PVOID         OutBuffer OPTIONAL,
    IN ULONG          OutBufferLen,
    IN BOOLEAN        fInternal,
    OUT PIO_STATUS_BLOCK Iosb
    );

NTSTATUS INTERNAL
SerialAsyncReadWriteData(
    IN BOOLEAN                fRead,
    IN PDEVICE_EXTENSION      DevExt,
    IN PIRP                   Irp,
    IN PUCHAR                 Buffer,
    IN ULONG                  BuffLen,
    IN PIO_COMPLETION_ROUTINE CompletionRoutine,
    IN PVOID                  Context
    );

NTSTATUS INTERNAL
SerialAsyncReadWritePort(
    IN BOOLEAN           fRead,
    IN PDEVICE_EXTENSION DevExt,
    IN PUCHAR            Buffer,
    IN ULONG             BuffLen
    );


IO_COMPLETION_ROUTINE AsyncReadWriteCompletion;

NTSTATUS INTERNAL
AsyncReadWriteCompletion(
    IN PDEVICE_OBJECT    DevObj,
    IN PIRP              Irp,
    IN PVOID             Context
    );

NTSTATUS INTERNAL
SerialSyncReadWritePort(
    IN BOOLEAN           fRead,
    IN PDEVICE_EXTENSION DevExt,
    IN PUCHAR            Buffer,
    IN ULONG             BuffLen,
    IN PIRPLOCK           Lock,
    IN PLARGE_INTEGER    Timeout OPTIONAL,
    OUT PULONG           BytesAccessed OPTIONAL
    );

NTSTATUS
SyncReadWriteCompletion(
    IN PDEVICE_OBJECT   DevObj,
    IN PIRP             Irp,
    IN PVOID            Context
    );

#endif  //ifndef _SERIAL_H


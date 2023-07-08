/*++

Copyright (c) Microsoft Corporation

Module Name :

    serialp.h

Abstract:

    Prototypes and macros that are used throughout the driver.

--*/

//-----------------------------------------------------------------------------
// 4127 -- Conditional Expression is Constant warning
//-----------------------------------------------------------------------------
#define WHILE(constant) \
__pragma(warning(disable: 4127)) while(constant); __pragma(warning(default: 4127))

typedef
VOID
(*PSERIAL_START_ROUTINE) (
    IN PSERIAL_DEVICE_EXTENSION
    );

typedef
VOID
(*PSERIAL_GET_NEXT_ROUTINE) (
    IN WDFREQUEST *CurrentOpRequest,
    IN WDFQUEUE QueueToProcess,
    OUT WDFREQUEST *NewRequest,
    IN BOOLEAN CompleteCurrent,
    PSERIAL_DEVICE_EXTENSION Extension
    );

DRIVER_INITIALIZE DriverEntry;

EVT_WDF_DRIVER_DEVICE_ADD SerialEvtDeviceAdd;
EVT_WDF_OBJECT_CONTEXT_CLEANUP SerialEvtDriverContextCleanup;

EVT_WDF_DEVICE_CONTEXT_CLEANUP SerialEvtDeviceContextCleanup;
EVT_WDF_DEVICE_D0_ENTRY SerialEvtDeviceD0Entry;
EVT_WDF_DEVICE_D0_EXIT SerialEvtDeviceD0Exit;
EVT_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED SerialEvtDeviceD0EntryPostInterruptsEnabled;
EVT_WDF_DEVICE_D0_EXIT_PRE_INTERRUPTS_DISABLED SerialEvtDeviceD0ExitPreInterruptsDisabled;
EVT_WDF_DEVICE_PREPARE_HARDWARE SerialEvtPrepareHardware;
EVT_WDF_DEVICE_RELEASE_HARDWARE SerialEvtReleaseHardware;

EVT_WDF_DEVICE_FILE_CREATE SerialEvtDeviceFileCreate;
EVT_WDF_FILE_CLOSE SerialEvtFileClose;

EVT_WDF_IO_QUEUE_IO_READ SerialEvtIoRead;
EVT_WDF_IO_QUEUE_IO_WRITE SerialEvtIoWrite;
EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL SerialEvtIoDeviceControl;
EVT_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL SerialEvtIoInternalDeviceControl;
EVT_WDF_IO_QUEUE_IO_CANCELED_ON_QUEUE SerialEvtCanceledOnQueue;
EVT_WDF_IO_QUEUE_IO_STOP SerialEvtIoStop;
EVT_WDF_IO_QUEUE_IO_RESUME SerialEvtIoResume;

EVT_WDF_INTERRUPT_ENABLE SerialEvtInterruptEnable;
EVT_WDF_INTERRUPT_DISABLE SerialEvtInterruptDisable;

EVT_WDF_DPC SerialCompleteRead;
EVT_WDF_DPC SerialCompleteWrite;
EVT_WDF_DPC SerialCommError;
EVT_WDF_DPC SerialCompleteImmediate;
EVT_WDF_DPC SerialCompleteXoff;
EVT_WDF_DPC SerialCompleteWait;
EVT_WDF_DPC SerialStartTimerLowerRTS;

EVT_WDF_TIMER SerialReadTimeout;
EVT_WDF_TIMER SerialIntervalReadTimeout;
EVT_WDF_TIMER SerialWriteTimeout;
EVT_WDF_TIMER SerialTimeoutImmediate;
EVT_WDF_TIMER SerialTimeoutXoff;
EVT_WDF_TIMER SerialInvokePerhapsLowerRTS;

VOID
SerialStartRead(
    IN PSERIAL_DEVICE_EXTENSION Extension
    );

VOID
SerialStartWrite(
    IN PSERIAL_DEVICE_EXTENSION Extension
    );

VOID
SerialStartMask(
    IN PSERIAL_DEVICE_EXTENSION Extension
    );

VOID
SerialStartImmediate(
    IN PSERIAL_DEVICE_EXTENSION Extension
    );

VOID
SerialStartPurge(
    IN PSERIAL_DEVICE_EXTENSION Extension
    );

VOID
SerialGetNextWrite(
    IN WDFREQUEST *CurrentOpRequest,
    IN WDFQUEUE QueueToProcess,
    IN WDFREQUEST *NewRequest,
    IN BOOLEAN CompleteCurrent,
    IN PSERIAL_DEVICE_EXTENSION Extension
    );

BOOLEAN
SerialProcessEmptyTransmit(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

NTSTATUS
SerialWdmDeviceFileCreate (
    IN WDFDEVICE Device,
    IN PIRP Irp
    );

NTSTATUS
SerialDeviceFileCreateWorker (
    IN WDFDEVICE Device
    );


NTSTATUS
SerialWdmFileClose (
    IN WDFDEVICE Device,
    IN PIRP Irp
    );

VOID
SerialFileCloseWorker(
    IN WDFDEVICE Device
    );

BOOLEAN
SerialMarkOpen(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );


BOOLEAN
SerialSetDTR(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialClrDTR(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialSetRTS(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialClrRTS(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialSetChars(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialSetBaud(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialSetLineControl(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialSetupNewHandFlow(
    IN PSERIAL_DEVICE_EXTENSION Extension,
    IN PSERIAL_HANDFLOW NewHandFlow
    );

BOOLEAN
SerialSetHandFlow(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialTurnOnBreak(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialTurnOffBreak(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialPretendXoff(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialPretendXon(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

VOID
SerialHandleReducedIntBuffer(
    IN PSERIAL_DEVICE_EXTENSION Extension
    );

VOID
SerialProdXonXoff(
    IN PSERIAL_DEVICE_EXTENSION Extension,
    IN BOOLEAN SendXon
    );

VOID
SerialCancelWait(
    IN WDFREQUEST Request
    );

BOOLEAN
SerialPurgeInterruptBuff(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

VOID
SerialPurgeRequests(
    IN WDFQUEUE QueueToClean,
    IN WDFREQUEST *CurrentOpRequest
    );

VOID
SerialFlushRequests(
    IN WDFQUEUE QueueToClean,
    IN WDFREQUEST *CurrentOpRequest
    );

VOID
SerialGetNextRequest(
    IN WDFREQUEST *CurrentOpRequest,
    IN WDFQUEUE QueueToProcess,
    OUT WDFREQUEST *NextIrp,
    IN BOOLEAN CompleteCurrent,
    IN PSERIAL_DEVICE_EXTENSION extension
    );


VOID
SerialTryToCompleteCurrent(
    IN PSERIAL_DEVICE_EXTENSION Extension,
    IN PFN_WDF_INTERRUPT_SYNCHRONIZE  SynchRoutine OPTIONAL,
    IN NTSTATUS StatusToUse,
    IN WDFREQUEST *CurrentOpRequest,
    IN WDFQUEUE QueueToProcess,
    IN WDFTIMER IntervalTimer,
    IN WDFTIMER TotalTimer,
    IN PSERIAL_START_ROUTINE Starter,
    IN PSERIAL_GET_NEXT_ROUTINE GetNextIrp,
    IN LONG RefType
    );

VOID
SerialStartOrQueue(
    IN PSERIAL_DEVICE_EXTENSION Extension,
    IN WDFREQUEST Request,
    IN WDFQUEUE QueueToExamine,
    IN WDFREQUEST *CurrentOpRequest,
    IN PSERIAL_START_ROUTINE Starter
    );

NTSTATUS
SerialCompleteIfError(
    PSERIAL_DEVICE_EXTENSION extension,
    WDFREQUEST Request
    );

ULONG
SerialHandleModemUpdate(
    IN PSERIAL_DEVICE_EXTENSION Extension,
    IN BOOLEAN DoingTX
    );

BOOLEAN
SerialISR(
    IN WDFINTERRUPT Interrupt,
    IN ULONG        MessageID
    );

NTSTATUS
SerialGetDivisorFromBaud(
    IN ULONG ClockRate,
    IN LONG DesiredBaud,
    OUT PSHORT AppropriateDivisor
    );

BOOLEAN
SerialReset(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialPerhapsLowerRTS(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

VOID
SerialCleanupDevice(
    IN PSERIAL_DEVICE_EXTENSION Extension
    );

UCHAR
SerialProcessLSR(
    IN PSERIAL_DEVICE_EXTENSION Extension
    );

LARGE_INTEGER
SerialGetCharTime(
    IN PSERIAL_DEVICE_EXTENSION Extension
    );


BOOLEAN
SerialMarkClose(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );


VOID
SerialPutChar(
    IN PSERIAL_DEVICE_EXTENSION Extension,
    IN UCHAR CharToPut
    );

BOOLEAN
SerialGetStats(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialClearStats(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );


NTSTATUS
SerialGetConfigDefaults(
    IN PSERIAL_FIRMWARE_DATA DriverDefaultsPtr,
    IN WDFDRIVER          Driver
    );

VOID
SerialGetProperties(
    IN PSERIAL_DEVICE_EXTENSION Extension,
    IN PSERIAL_COMMPROP Properties
    );

VOID
SerialLogError(
    __in                             PDRIVER_OBJECT DriverObject,
    __in_opt                         PDEVICE_OBJECT DeviceObject,
    __in                             PHYSICAL_ADDRESS P1,
    __in                             PHYSICAL_ADDRESS P2,
    __in                             ULONG SequenceNumber,
    __in                             UCHAR MajorFunctionCode,
    __in                             UCHAR RetryCount,
    __in                             ULONG UniqueErrorValue,
    __in                             NTSTATUS FinalStatus,
    __in                             NTSTATUS SpecificIOStatus,
    __in                             ULONG LengthOfInsert1,
    __in_bcount_opt(LengthOfInsert1) PWCHAR Insert1,
    __in                             ULONG LengthOfInsert2,
    __in_bcount_opt(LengthOfInsert2) PWCHAR Insert2
    );

NTSTATUS
SerialMapHWResources(
    IN WDFDEVICE Device,
    IN WDFCMRESLIST PResList,
    IN WDFCMRESLIST PTrResList,
    OUT PCONFIG_DATA PConfig
    );

VOID
SerialUnmapHWResources(
    IN PSERIAL_DEVICE_EXTENSION PDevExt
    );

BOOLEAN
SerialGetRegistryKeyValue (
    IN  WDFDEVICE  WdfDevice,
    __in  PWCHAR   Name,
    OUT PULONG     Value
    );


BOOLEAN
SerialPutRegistryKeyValue (
    IN WDFDEVICE  WdfDevice,
    __in PWCHAR   Name,
    IN ULONG      Value
    );

NTSTATUS
SerialInitController(
    IN PSERIAL_DEVICE_EXTENSION pDevExt,
    IN PCONFIG_DATA PConfigData
    );

BOOLEAN
SerialCIsrSw(
    IN WDFINTERRUPT Interrupt,
    IN ULONG        MessageID
    );

NTSTATUS
SerialDoExternalNaming(
    IN PSERIAL_DEVICE_EXTENSION PDevExt
    );

PVOID
SerialGetMappedAddress(
    PHYSICAL_ADDRESS IoAddress,
    ULONG NumberOfBytes,
    ULONG AddressSpace,
    PBOOLEAN MappedAddress
    );

BOOLEAN
SerialDoesPortExist(
    IN PSERIAL_DEVICE_EXTENSION Extension,
    PUNICODE_STRING InsertString,
    IN ULONG ForceFifo,
    IN ULONG LogFifo
    );

SERIAL_MEM_COMPARES
SerialMemCompare(
    IN PHYSICAL_ADDRESS A,
    IN ULONG SpanOfA,
    IN PHYSICAL_ADDRESS B,
    IN ULONG SpanOfB
    );

VOID
SerialUndoExternalNaming(
    IN PSERIAL_DEVICE_EXTENSION Extension
    );

VOID
SerialReleaseResources(
    IN PSERIAL_DEVICE_EXTENSION PDevExt
    );

VOID
SerialPurgePendingRequests(
    PSERIAL_DEVICE_EXTENSION pDevExt
    );

VOID
SerialDisableUART(
    IN PVOID Context
    );

VOID
SerialDrainUART(
    IN PSERIAL_DEVICE_EXTENSION PDevExt,
    IN PLARGE_INTEGER PDrainTime
    );

VOID
SerialSaveDeviceState(
    IN PSERIAL_DEVICE_EXTENSION PDevExt
    );

NTSTATUS
SerialSetPowerPolicy(
    IN PSERIAL_DEVICE_EXTENSION DeviceExtension
    );

UINT32
SerialReportMaxBaudRate(
    ULONG Bauds
    );

BOOLEAN
SerialSetMCRContents(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialGetMCRContents(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialSetFCRContents(
    IN WDFINTERRUPT  Interrupt,
    IN PVOID Context
    );

BOOLEAN
SerialInsertQueueDpc(
    IN WDFDPC Dpc
    );

BOOLEAN
SerialSetTimer(
    IN WDFTIMER Timer,
    IN LARGE_INTEGER DueTime
    );

BOOLEAN
SerialCancelTimer(
    IN WDFTIMER Timer,
    IN PSERIAL_DEVICE_EXTENSION PDevExt
    );

VOID
SerialUnlockPages(
    IN WDFDPC PDpc,
    IN PVOID PDeferredContext,
    IN PVOID PSysContext1,
    IN PVOID PSysContext2)
    ;

VOID
SerialMarkHardwareBroken(
    IN PSERIAL_DEVICE_EXTENSION PDevExt
    );

VOID
SerialDisableInterfacesResources(
    IN PSERIAL_DEVICE_EXTENSION PDevExt,
    IN BOOLEAN DisableUART
    );

VOID
SerialSetDeviceFlags(
    IN  PSERIAL_DEVICE_EXTENSION PDevExt,
    OUT PULONG PFlags,
    IN  ULONG Value,
    IN  BOOLEAN Set
    );


VOID
SetDeviceIsOpened(
    IN PSERIAL_DEVICE_EXTENSION PDevExt,
    IN BOOLEAN DeviceIsOpened,
    IN BOOLEAN Reopen
    );

BOOLEAN
IsQueueEmpty(
    IN WDFQUEUE Queue
    );

NTSTATUS
SerialCreateTimersAndDpcs(
    IN PSERIAL_DEVICE_EXTENSION PDevExt
    );

VOID
SerialDrainTimersAndDpcs(
    IN PSERIAL_DEVICE_EXTENSION PDevExt
    );

VOID
SerialSetCancelRoutine(
    IN WDFREQUEST Request,
    IN PFN_WDF_REQUEST_CANCEL CancelRoutine
    );

NTSTATUS
SerialClearCancelRoutine(
    IN WDFREQUEST Request,
    IN BOOLEAN ClearReference
    );

NTSTATUS
SerialWmiRegistration(
    WDFDEVICE      Device
    );

NTSTATUS
SerialReadSymName(
    IN                           WDFDEVICE Device,
    __out_bcount(*SizeOfRegName) PWCHAR RegName,
    __inout                      PUSHORT SizeOfRegName
    );

VOID
SerialCompleteRequest(
    IN WDFREQUEST    Request,
    IN NTSTATUS      Status,
    IN ULONG_PTR     Info
    );

BOOLEAN
SerialGetFdoRegistryKeyValue(
    IN PWDFDEVICE_INIT  DeviceInit,
    __in PWCHAR         Name,
    OUT PULONG          Value
    );

NTSTATUS
SerialQueryInformationFile(
    IN WDFDEVICE Device,
    IN PIRP Irp
    );

NTSTATUS
SerialSetInformationFile(
    IN WDFDEVICE Device,
    IN PIRP Irp
    );

NTSTATUS
SerialFlush(
    IN WDFDEVICE Device,
    IN PIRP Irp
    );

typedef struct _SERIAL_UPDATE_CHAR {
    PSERIAL_DEVICE_EXTENSION Extension;
    ULONG CharsCopied;
    BOOLEAN Completed;
    } SERIAL_UPDATE_CHAR,*PSERIAL_UPDATE_CHAR;

//
// The following simple structure is used to send a pointer
// the device extension and an ioctl specific pointer
// to data.
//
typedef struct _SERIAL_IOCTL_SYNC {
    PSERIAL_DEVICE_EXTENSION Extension;
    PVOID Data;
    } SERIAL_IOCTL_SYNC,*PSERIAL_IOCTL_SYNC;


//
// The following three macros are used to initialize, set
// and clear references in IRPs that are used by
// this driver.  The reference is stored in the fourth
// argument of the request, which is never used by any operation
// accepted by this driver.
//

#define SERIAL_REF_ISR         (0x00000001)
#define SERIAL_REF_CANCEL      (0x00000002)
#define SERIAL_REF_TOTAL_TIMER (0x00000004)
#define SERIAL_REF_INT_TIMER   (0x00000008)
#define SERIAL_REF_XOFF_REF    (0x00000010)


#define SERIAL_INIT_REFERENCE(ReqContext) { \
    (ReqContext)->RefCount = NULL; \
    }

#define SERIAL_SET_REFERENCE(ReqContext, RefType) \
   do { \
       LONG _refType = (RefType); \
       PULONG_PTR _arg4 = (PVOID)&(ReqContext)->RefCount; \
       ASSERT(!(*_arg4 & _refType)); \
       *_arg4 |= _refType; \
   } WHILE (0)

#define SERIAL_CLEAR_REFERENCE(ReqContext, RefType) \
   do { \
       LONG _refType = (RefType); \
       PULONG_PTR _arg4 = (PVOID)&(ReqContext)->RefCount; \
       ASSERT(*_arg4 & _refType); \
       *_arg4 &= ~_refType; \
   } WHILE (0)

#define SERIAL_REFERENCE_COUNT(ReqContext) \
    ((ULONG_PTR)(((ReqContext)->RefCount)))

#define SERIAL_TEST_REFERENCE(ReqContext, RefType) ((ULONG_PTR)ReqContext ->RefCount & RefType)


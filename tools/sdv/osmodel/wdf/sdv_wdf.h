/*  
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

#ifndef _SDV_WDF_H_
#define _SDV_WDF_H_


#define WdfObjectGetTypedContextWorker sdv_WdfObjectGetTypedContextWorker
PVOID
sdv_WdfObjectGetTypedContextWorker(
      IN WDFOBJECT Handle,
      IN PCWDF_OBJECT_CONTEXT_TYPE_INFO TypeInfo
   );

#define WDF_DRIVER_CONFIG_INIT sdv_WDF_DRIVER_CONFIG_INIT
VOID
sdv_WDF_DRIVER_CONFIG_INIT(
    OUT PWDF_DRIVER_CONFIG Config,
    IN PFN_WDF_DRIVER_DEVICE_ADD EvtDriverDeviceAdd
    );

#define WdfDriverCreate sdv_WdfDriverCreate
WDFAPI
NTSTATUS
sdv_WdfDriverCreate(
    IN           PDRIVER_OBJECT          DriverObject,
    IN           PUNICODE_STRING         RegistryPath,
    IN OPTIONAL  PWDF_OBJECT_ATTRIBUTES  DriverAttributes,
    IN           PWDF_DRIVER_CONFIG      DriverConfig,
    OUT OPTIONAL WDFDRIVER*              Driver
    );

#define WdfDriverOpenParametersRegistryKey sdv_WdfDriverOpenParametersRegistryKey
NTSTATUS
sdv_WdfDriverOpenParametersRegistryKey(
    IN WDFDRIVER Driver,
    IN ACCESS_MASK DesiredAccess,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    OUT WDFKEY* Key
    );

#define WdfDriverWdmGetDriverObject sdv_WdfDriverWdmGetDriverObject
PDRIVER_OBJECT
sdv_WdfDriverWdmGetDriverObject(
    IN WDFDRIVER Driver
    );
#define WdfDeviceCreate sdv_WdfDeviceCreate
WDFAPI
NTSTATUS
sdv_WdfDeviceCreate(
    IN OUT PWDFDEVICE_INIT* DeviceInit,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES DeviceAttributes,
    OUT WDFDEVICE* Device
    );
#define WdfDeviceCreateSymbolicLink sdv_WdfDeviceCreateSymbolicLink
WDFAPI NTSTATUS
sdv_WdfDeviceCreateSymbolicLink(
    IN WDFDEVICE  Device,
    IN PCUNICODE_STRING  SymbolicLinkName
    );

#define WdfDeviceCreateDeviceInterface sdv_WdfDeviceCreateDeviceInterface
WDFAPI
NTSTATUS
sdv_WdfDeviceCreateDeviceInterface(
    IN WDFDEVICE Device,
    IN CONST GUID* InterfaceClassGUID,
    IN OPTIONAL PUNICODE_STRING ReferenceString
    );
#define WdfDeviceGetDriver sdv_WdfDeviceGetDriver
WDFAPI WDFDRIVER
sdv_WdfDeviceGetDriver(
   IN WDFDEVICE  Device
   );
#define WdfDeviceGetDefaultQueue sdv_WdfDeviceGetDefaultQueue
WDFQUEUE
sdv_WdfDeviceGetDefaultQueue(
    IN WDFDEVICE Device
    );
#define WdfDeviceOpenRegistryKey sdv_WdfDeviceOpenRegistryKey
NTSTATUS
sdv_WdfDeviceOpenRegistryKey(
    IN WDFDEVICE Device,
    IN ULONG DeviceInstanceKeyType,
    IN ACCESS_MASK DesiredAccess,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    OUT WDFKEY* Key
    );
#define WDF_IO_QUEUE_CONFIG_INIT sdv_WDF_IO_QUEUE_CONFIG_INIT
VOID
sdv_WDF_IO_QUEUE_CONFIG_INIT(
    IN PWDF_IO_QUEUE_CONFIG      Config,
    IN WDF_IO_QUEUE_DISPATCH_TYPE DispatchType
    );
#define WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE sdv_WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE
VOID
sdv_WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE(
    OUT PWDF_IO_QUEUE_CONFIG      Config,
    IN WDF_IO_QUEUE_DISPATCH_TYPE DispatchType
    );
#define WdfIoQueueCreate sdv_WdfIoQueueCreate
WDFAPI
NTSTATUS
sdv_WdfIoQueueCreate(
    IN WDFDEVICE Device,
    IN PWDF_IO_QUEUE_CONFIG Config,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES QueueAttributes,
    OUT WDFQUEUE* Queue
    );
#define WdfIoQueueGetDevice sdv_WdfIoQueueGetDevice
WDFDEVICE
sdv_WdfIoQueueGetDevice(
    IN WDFQUEUE Queue
    );
#define WDF_TIMER_CONFIG_INIT_PERIODIC sdv_WDF_TIMER_CONFIG_INIT_PERIODIC
VOID
sdv_WDF_TIMER_CONFIG_INIT_PERIODIC(
    IN PWDF_TIMER_CONFIG Config,
    IN PFN_WDF_TIMER     EvtTimerFunc,
    IN ULONG             Period
    );
#define WdfTimerCreate sdv_WdfTimerCreate
WDFAPI
NTSTATUS
sdv_WdfTimerCreate(
    IN  PWDF_TIMER_CONFIG            Config,
    IN  PWDF_OBJECT_ATTRIBUTES Attributes,
    OUT WDFTIMER*              Timer
    );
#define WdfTimerStart sdv_WdfTimerStart
BOOLEAN
sdv_WdfTimerStart(
    IN WDFTIMER Timer,
    IN LONGLONG DueTime
    );
#define WdfTimerStop sdv_WdfTimerStop
BOOLEAN
sdv_WdfTimerStop(
    IN WDFTIMER Timer,
    IN BOOLEAN Wait
    );
#define WdfTimerGetParentObject sdv_WdfTimerGetParentObject
WDFOBJECT
FORCEINLINE
sdv_WdfTimerGetParentObject(
    IN WDFTIMER Timer
    );
#define WDF_WORKITEM_CONFIG_INIT sdv_WDF_WORKITEM_CONFIG_INIT
VOID
sdv_WDF_WORKITEM_CONFIG_INIT(
    OUT PWDF_WORKITEM_CONFIG Config,
    IN PFN_WDF_WORKITEM     EvtWorkItemFunc
    );

#define WdfWorkItemCreate sdv_WdfWorkItemCreate
NTSTATUS
sdv_WdfWorkItemCreate(
    IN PWDF_WORKITEM_CONFIG Config,
	IN OPTIONAL PWDF_OBJECT_ATTRIBUTES Attributes,
    OUT WDFWORKITEM* WorkItem
    );
#define WdfWorkItemEnqueue sdv_WdfWorkItemEnqueue
VOID
sdv_WdfWorkItemEnqueue(
    IN WDFWORKITEM WorkItem
    );
#define WDF_DPC_CONFIG_INIT sdv_WDF_DPC_CONFIG_INIT
VOID
sdv_WDF_DPC_CONFIG_INIT(
    IN PWDF_DPC_CONFIG Config,
    IN PFN_WDF_DPC     EvtDpcFunc
    );
#define WdfDpcCreate sdv_WdfDpcCreate
NTSTATUS
sdv_WdfDpcCreate(
    IN PWDF_DPC_CONFIG Config,
    IN PWDF_OBJECT_ATTRIBUTES Attributes,
    OUT WDFDPC* Dpc);
#define WdfDpcEnqueue sdv_WdfDpcEnqueue
BOOLEAN
sdv_WdfDpcEnqueue(
    IN WDFDPC Dpc
    );
#define WdfDpcCancel sdv_WdfDpcCancel
BOOLEAN
sdv_WdfDpcCancel(
    IN WDFDPC Dpc,
    IN BOOLEAN Wait
    );
#define WdfCommonBufferGetLength sdv_WdfCommonBufferGetLength
size_t 
sdv_WdfCommonBufferGetLength(
    IN WDFCOMMONBUFFER CommonBuffer
    );

#define WdfCommonBufferGetAlignedLogicalAddress sdv_WdfCommonBufferGetAlignedLogicalAddress
PHYSICAL_ADDRESS
sdv_WdfCommonBufferGetAlignedLogicalAddress(
    IN WDFCOMMONBUFFER CommonBuffer
    );

#define WdfCommonBufferGetAlignedVirtualAddress sdv_WdfCommonBufferGetAlignedVirtualAddress
PVOID
sdv_WdfCommonBufferGetAlignedVirtualAddress(
    IN WDFCOMMONBUFFER CommonBuffer
    );

#define WdfCommonBufferCreate sdv_WdfCommonBufferCreate
NTSTATUS
sdv_WdfCommonBufferCreate(
    IN WDFDMAENABLER DmaEnabler,
    IN size_t Length,
	IN OPTIONAL PWDF_OBJECT_ATTRIBUTES Attributes,
    OUT WDFCOMMONBUFFER* CommonBufferHandle
    );

#define WdfRequestSetCompletionRoutine sdv_WdfRequestSetCompletionRoutine
VOID
sdv_WdfRequestSetCompletionRoutine(
    WDFREQUEST Request,
    PFN_WDF_REQUEST_COMPLETION_ROUTINE CompletionRoutine,
    WDFCONTEXT CompletionContext
    );

#define WdfRequestCreate sdv_WdfRequestCreate
NTSTATUS 
sdv_WdfRequestCreate(
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES RequestAttributes,
    IN OPTIONAL WDFIOTARGET IoTarget,
    OUT WDFREQUEST* Request
    );

#define WdfRequestGetFileObject sdv_WdfRequestGetFileObject
WDFFILEOBJECT
sdv_WdfRequestGetFileObject(
    IN WDFREQUEST Request
    );
#define WdfRequestRetrieveOutputBuffer sdv_WdfRequestRetrieveOutputBuffer
NTSTATUS
sdv_WdfRequestRetrieveOutputBuffer(
	IN WDFREQUEST Request,
	IN size_t  MinimumRequiredSize,
	OUT PVOID* Buffer,
	OUT size_t* Length
	);

#define WdfRequestRetrieveInputBuffer sdv_WdfRequestRetrieveInputBuffer
NTSTATUS
sdv_WdfRequestRetrieveInputBuffer(
    IN WDFREQUEST Request,
    IN size_t  MinimumRequiredSize,
    OUT PVOID* Buffer,
    OUT size_t* Length
    );

#define WdfRequestRetrieveUnsafeUserInputBuffer sdv_WdfRequestRetrieveUnsafeUserInputBuffer
NTSTATUS
sdv_WdfRequestRetrieveUnsafeUserInputBuffer(
    IN WDFREQUEST Request,
    IN size_t MinimumRequiredLength,
    OUT PVOID* InputBuffer,
    OUT OPTIONAL size_t* Length
    );

#define WdfRequestRetrieveUnsafeUserOutputBuffer sdv_WdfRequestRetrieveUnsafeUserOutputBuffer
NTSTATUS
sdv_WdfRequestRetrieveUnsafeUserOutputBuffer(
    IN WDFREQUEST Request,
    IN size_t MinimumRequiredLength,
    OUT PVOID* OutputBuffer,
    OUT OPTIONAL size_t* Length
    );

#define WdfRequestRetrieveOutputMemory sdv_WdfRequestRetrieveOutputMemory
NTSTATUS
sdv_WdfRequestRetrieveOutputMemory(
	IN WDFREQUEST Request,
	OUT WDFMEMORY* Memory
	);

#define WdfRequestRetrieveInputMemory sdv_WdfRequestRetrieveInputMemory
NTSTATUS
sdv_WdfRequestRetrieveInputMemory(
	IN WDFREQUEST Request,
	OUT WDFMEMORY* Memory
	);

#define WdfRequestRetrieveOutputWdmMdl sdv_WdfRequestRetrieveOutputWdmMdl
NTSTATUS
sdv_WdfRequestRetrieveOutputWdmMdl(
	IN WDFREQUEST Request,
	OUT PMDL* Mdl
	);

#define WdfRequestRetrieveInputWdmMdl sdv_WdfRequestRetrieveInputWdmMdl
NTSTATUS
sdv_WdfRequestRetrieveInputWdmMdl(
	IN WDFREQUEST Request,
	OUT PMDL* Mdl
	);

#define WdfMemoryGetBuffer sdv_WdfMemoryGetBuffer
PVOID
sdv_WdfMemoryGetBuffer(
    IN WDFMEMORY Memory,
    OUT OPTIONAL size_t* BufferSize
    );

#define WDF_MEMORY_DESCRIPTOR_INIT_HANDLE sdv_WDF_MEMORY_DESCRIPTOR_INIT_HANDLE
VOID
sdv_WDF_MEMORY_DESCRIPTOR_INIT_HANDLE(
    OUT PWDF_MEMORY_DESCRIPTOR Descriptor,
    IN WDFMEMORY Memory,
    IN OPTIONAL PWDFMEMORY_OFFSET Offsets
    );

#define WDF_MEMORY_DESCRIPTOR_INIT_BUFFER sdv_WDF_MEMORY_DESCRIPTOR_INIT_BUFFER
VOID
sdv_WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(
    OUT PWDF_MEMORY_DESCRIPTOR Descriptor,
    IN PVOID Buffer,
    IN ULONG BufferLength
    );

#define WdfMemoryCreate sdv_WdfMemoryCreate
NTSTATUS
sdv_WdfMemoryCreate(
    PWDF_OBJECT_ATTRIBUTES Attributes,
    IN POOL_TYPE PoolType,
    IN OPTIONAL ULONG PoolTag,
    IN size_t BufferSize,
    OUT WDFMEMORY* Memory,
    OUT OPTIONAL PVOID* Buffer
    );

#define WdfMemoryCreatePreallocated sdv_WdfMemoryCreatePreallocated
NTSTATUS
sdv_WdfMemoryCreatePreallocated(
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES Attributes,
    IN PVOID Buffer,
    IN size_t BufferSize,
    OUT WDFMEMORY* Memory
    );

#define WdfMemoryAssignBuffer sdv_WdfMemoryAssignBuffer
NTSTATUS
sdv_WdfMemoryAssignBuffer(
    IN WDFMEMORY Memory,
    IN PVOID Buffer,
    IN size_t BufferSize
    );

#define WdfMemoryCopyFromBuffer sdv_WdfMemoryCopyFromBuffer
NTSTATUS
sdv_WdfMemoryCopyFromBuffer(
    IN WDFMEMORY DestinationMemory,
    IN size_t DestinationOffset,
    IN PVOID Buffer,
    IN size_t NumBytesToCopyFrom
    );

#define WdfMemoryCopyToBuffer sdv_WdfMemoryCopyToBuffer
NTSTATUS
sdv_WdfMemoryCopyToBuffer(
    IN WDFMEMORY SourceMemory,
    IN size_t SourceOffset,
    IN OUT PVOID Buffer,
    IN size_t NumBytesToCopyTo
    );

#define WDF_MEMORY_DESCRIPTOR_INIT_MDL sdv_WDF_MEMORY_DESCRIPTOR_INIT_MDL
VOID
sdv_WDF_MEMORY_DESCRIPTOR_INIT_MDL(
    OUT PWDF_MEMORY_DESCRIPTOR Descriptor,
    IN PMDL Mdl,
    IN ULONG BufferLength
    );

#define WdfDmaTransactionInitialize sdv_WdfDmaTransactionInitialize
NTSTATUS
sdv_WdfDmaTransactionInitialize(
    IN WDFDMATRANSACTION DmaTransaction,
    IN PFN_WDF_PROGRAM_DMA EvtProgramDmaFunction,
    IN WDF_DMA_DIRECTION DmaDirection,
    IN PMDL Mdl,
    IN PVOID VirtualAddress,
    IN size_t  Length
    );

#define WdfDmaTransactionCreate sdv_WdfDmaTransactionCreate
NTSTATUS
sdv_WdfDmaTransactionCreate(
    IN WDFDMAENABLER DmaEnabler,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES Attributes,
    OUT WDFDMATRANSACTION* DmaTransaction
    );

#define WdfDmaTransactionGetDevice sdv_WdfDmaTransactionGetDevice
WDFDEVICE
sdv_WdfDmaTransactionGetDevice(
    IN WDFDMATRANSACTION DmaTransaction
    );

#define WdfDmaTransactionGetCurrentDmaTransferLength sdv_WdfDmaTransactionGetCurrentDmaTransferLength
size_t
sdv_WdfDmaTransactionGetCurrentDmaTransferLength(
    IN WDFDMATRANSACTION DmaTransaction
    );

#define WdfDmaTransactionGetRequest sdv_WdfDmaTransactionGetRequest
WDFREQUEST
sdv_WdfDmaTransactionGetRequest(
    IN WDFDMATRANSACTION DmaTransaction
    );

#define WdfDmaTransactionSetMaximumLength sdv_WdfDmaTransactionSetMaximumLength
VOID
sdv_WdfDmaTransactionSetMaximumLength(
    __in
    WDFDMATRANSACTION DmaTransaction,
    IN size_t MaximumLength
    );

#define WdfDmaTransactionGetBytesTransferred sdv_WdfDmaTransactionGetBytesTransferred
size_t
sdv_WdfDmaTransactionGetBytesTransferred(
    IN WDFDMATRANSACTION DmaTransaction
    );

#define WdfDmaTransactionDmaCompletedFinal sdv_WdfDmaTransactionDmaCompletedFinal
BOOLEAN
sdv_WdfDmaTransactionDmaCompletedFinal(
    IN WDFDMATRANSACTION DmaTransaction,
    IN size_t FinalTransferredLength,
    OUT NTSTATUS* Status
    );

#define WdfDmaTransactionDmaCompletedWithLength sdv_WdfDmaTransactionDmaCompletedWithLength
BOOLEAN
sdv_WdfDmaTransactionDmaCompletedWithLength(
    IN WDFDMATRANSACTION DmaTransaction,
    IN size_t TransferredLength,
    OUT NTSTATUS* Status
    );

#define WdfDmaTransactionDmaCompleted sdv_WdfDmaTransactionDmaCompleted
BOOLEAN
sdv_WdfDmaTransactionDmaCompleted(
    IN WDFDMATRANSACTION DmaTransaction,
    OUT NTSTATUS* Status
    );

#define WdfDmaTransactionRelease sdv_WdfDmaTransactionRelease
NTSTATUS
sdv_WdfDmaTransactionRelease(
    IN WDFDMATRANSACTION DmaTransaction
    );

#define WdfDmaTransactionExecute sdv_WdfDmaTransactionExecute
NTSTATUS
sdv_WdfDmaTransactionExecute(
    IN WDFDMATRANSACTION DmaTransaction,
    IN OPTIONAL PVOID Context
    );

#define WdfDmaTransactionInitializeUsingRequest sdv_WdfDmaTransactionInitializeUsingRequest
NTSTATUS
sdv_WdfDmaTransactionInitializeUsingRequest(
    IN WDFDMATRANSACTION DmaTransaction,
    IN WDFREQUEST Request,
    IN PFN_WDF_PROGRAM_DMA EvtProgramDmaFunction,
    IN WDF_DMA_DIRECTION DmaDirection
    );
#define WdfDmaEnablerSetMaximumScatterGatherElements sdv_WdfDmaEnablerSetMaximumScatterGatherElements
VOID
sdv_WdfDmaEnablerSetMaximumScatterGatherElements(
    IN WDFDMAENABLER DmaEnabler,
    IN size_t MaximumFragments
    );

#define WdfDmaEnablerGetMaximumScatterGatherElements sdv_WdfDmaEnablerGetMaximumScatterGatherElements
size_t
sdv_WdfDmaEnablerGetMaximumScatterGatherElements(
    IN WDFDMAENABLER DmaEnabler
    );

#define WdfDmaEnablerGetMaximumLength sdv_WdfDmaEnablerGetMaximumLength
size_t
sdv_WdfDmaEnablerGetMaximumLength(
    IN WDFDMAENABLER DmaEnabler
    );

#define WdfDmaEnablerCreate sdv_WdfDmaEnablerCreate
NTSTATUS
sdv_WdfDmaEnablerCreate(
    IN WDFDEVICE Device,
    IN PWDF_DMA_ENABLER_CONFIG Config,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES Attributes,
    OUT WDFDMAENABLER* DmaEnablerHandle
    );

#define WDF_DMA_ENABLER_CONFIG_INIT sdv_WDF_DMA_ENABLER_CONFIG_INIT
VOID
sdv_WDF_DMA_ENABLER_CONFIG_INIT(
    IN  PWDF_DMA_ENABLER_CONFIG  Config,
    IN  WDF_DMA_PROFILE          Profile,
    IN  size_t                   MaximumLength
    );
#define WdfRegistryAssignULong sdv_WdfRegistryAssignULong
NTSTATUS
sdv_WdfRegistryAssignULong(
    IN WDFKEY Key,
    IN PCUNICODE_STRING ValueName,
    IN ULONG Value
    );

#define WdfRegistryAssignString sdv_WdfRegistryAssignString
NTSTATUS
sdv_WdfRegistryAssignString(
    IN WDFKEY Key,
    IN PCUNICODE_STRING ValueName,
    IN WDFSTRING String
    );

#define WdfRegistryAssignMultiString sdv_WdfRegistryAssignMultiString
NTSTATUS
sdv_WdfRegistryAssignMultiString(
    IN WDFKEY Key,
    IN PCUNICODE_STRING ValueName,
    IN WDFCOLLECTION StringsCollection
    );

#define WdfRegistryAssignMemory sdv_WdfRegistryAssignMemory
NTSTATUS
sdv_WdfRegistryAssignMemory(
    IN WDFKEY Key,
    IN PCUNICODE_STRING ValueName,
    IN ULONG ValueType,
    IN WDFMEMORY Memory,
    IN OPTIONAL PWDFMEMORY_OFFSET MemoryOffsets
    );

#define WdfRegistryAssignValue sdv_WdfRegistryAssignValue
NTSTATUS
sdv_WdfRegistryAssignValue(
    IN WDFKEY Key,
    IN PCUNICODE_STRING ValueName,
    IN ULONG ValueType,
    IN ULONG ValueLength,
    IN PVOID Value
    );

#define WdfRegistryQueryULong sdv_WdfRegistryQueryULong
NTSTATUS
sdv_WdfRegistryQueryULong(
    IN WDFKEY Key,
    IN PCUNICODE_STRING ValueName,
    OUT PULONG Value
    );

#define WdfRegistryQueryString sdv_WdfRegistryQueryString
NTSTATUS
sdv_WdfRegistryQueryString(
    IN WDFKEY Key,
    IN PCUNICODE_STRING ValueName,
    IN PCUNICODE_STRING Value
    );

#define WdfRegistryClose sdv_WdfRegistryClose
VOID
sdv_WdfRegistryClose(
    IN WDFKEY Key
    );
#define WDF_OBJECT_ATTRIBUTES_INIT sdv_WDF_OBJECT_ATTRIBUTES_INIT
VOID
sdv_WDF_OBJECT_ATTRIBUTES_INIT(
    IN PWDF_OBJECT_ATTRIBUTES Attributes
    );

#ifdef WdfObjectReference
#undef WdfObjectReference
#endif
#define WdfObjectReference sdv_WdfObjectReference
VOID
sdv_WdfObjectReference(
    IN WDFOBJECT Handle);


#ifdef WdfObjectDereference
#undef WdfObjectDereference
#endif
#define WdfObjectDereference sdv_WdfObjectDereference
VOID
sdv_WdfObjectDereference(
    IN WDFOBJECT Handle);


#define WdfRequestComplete sdv_WdfRequestComplete
WDFAPI
VOID
sdv_WdfRequestComplete(
    IN  WDFREQUEST Request,
    IN  NTSTATUS  RequestStatus
   );

#define WdfRequestCompleteWithInformation sdv_WdfRequestCompleteWithInformation
WDFAPI
VOID
sdv_WdfRequestCompleteWithInformation(
    IN  WDFREQUEST Request,
    IN  NTSTATUS  RequestStatus,
	IN ULONG_PTR Information
   );

#define WdfRequestCompleteWithPriorityBoost sdv_WdfRequestCompleteWithPriorityBoost
VOID
sdv_WdfRequestCompleteWithPriorityBoost(
    IN WDFREQUEST Request,
    IN NTSTATUS Status,
    IN CCHAR PriorityBoost
    );

#define WDF_REQUEST_PARAMETERS_INIT sdv_WDF_REQUEST_PARAMETERS_INIT
VOID
sdv_WDF_REQUEST_PARAMETERS_INIT(
    OUT PWDF_REQUEST_PARAMETERS Parameters
    );

#define WdfRequestGetParameters sdv_WdfRequestGetParameters
VOID
sdv_WdfRequestGetParameters(
    IN WDFREQUEST Request,
    OUT PWDF_REQUEST_PARAMETERS Parameters
    );

#define WdfRequestMarkCancelable sdv_WdfRequestMarkCancelable
VOID
sdv_WdfRequestMarkCancelable(
    IN WDFREQUEST Request,
    IN PFN_WDF_REQUEST_CANCEL EvtRequestCancel
    );

#define WdfRequestUnmarkCancelable sdv_WdfRequestUnmarkCancelable
NTSTATUS
sdv_WdfRequestUnmarkCancelable(
    IN WDFREQUEST Request
    );

#define WdfRequestIsCanceled sdv_WdfRequestIsCanceled
BOOLEAN
sdv_WdfRequestIsCanceled(
    IN WDFREQUEST Request
    );

#define WdfRequestSend sdv_WdfRequestSend
WDFAPI
BOOLEAN
sdv_WdfRequestSend(
    IN WDFREQUEST Request,
    IN WDFIOTARGET Target,
    IN OPTIONAL PWDF_REQUEST_SEND_OPTIONS RequestOptions
    );
#define WdfRequestGetStatus sdv_WdfRequestGetStatus
NTSTATUS
sdv_WdfRequestGetStatus(
    IN WDFREQUEST Request
    );
#define WdfRequestGetIoQueue sdv_WdfRequestGetIoQueue
WDFQUEUE
sdv_WdfRequestGetIoQueue(
    IN WDFREQUEST Request
    );
#define WdfIoTargetSendReadSynchronously  sdv_WdfIoTargetSendReadSynchronously 
WDFAPI
NTSTATUS
sdv_WdfIoTargetSendReadSynchronously (
    IN WDFIOTARGET IoTarget,
    IN OPTIONAL WDFREQUEST Request,
    IN OPTIONAL PWDF_MEMORY_DESCRIPTOR OutputBuffer,
    IN OPTIONAL PLONGLONG  DeviceOffset,
    IN OPTIONAL PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    OUT OPTIONAL PULONG_PTR BytesRead
    );
#define WdfIoTargetSendWriteSynchronously  sdv_WdfIoTargetSendWriteSynchronously 
WDFAPI
NTSTATUS
sdv_WdfIoTargetSendWriteSynchronously (
    IN WDFIOTARGET IoTarget,
    IN OPTIONAL WDFREQUEST Request,
    IN OPTIONAL PWDF_MEMORY_DESCRIPTOR InputBuffer,
    IN OPTIONAL PLONGLONG DeviceOffset,
    IN OPTIONAL PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    OUT OPTIONAL PULONG_PTR BytesWritten
    );
#define WdfIoTargetSendIoctlSynchronously  sdv_WdfIoTargetSendIoctlSynchronously 
WDFAPI
NTSTATUS
sdv_WdfIoTargetSendIoctlSynchronously (
    IN WDFIOTARGET IoTarget,
    IN OPTIONAL WDFREQUEST Request,
    IN ULONG IoctlCode,
    IN OPTIONAL PWDF_MEMORY_DESCRIPTOR InputBuffer,
    IN OPTIONAL PWDF_MEMORY_DESCRIPTOR OutputBuffer,
    IN OPTIONAL PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    OUT OPTIONAL PULONG_PTR BytesReturned
    );
#define WdfIoTargetSendInternalIoctlSynchronously  sdv_WdfIoTargetSendInternalIoctlSynchronously 
WDFAPI
NTSTATUS
sdv_WdfIoTargetSendInternalIoctlSynchronously (
    IN WDFIOTARGET IoTarget,
    IN OPTIONAL WDFREQUEST Request,
    IN ULONG IoctlCode,
    IN OPTIONAL PWDF_MEMORY_DESCRIPTOR InputBuffer,
    IN OPTIONAL PWDF_MEMORY_DESCRIPTOR OutputBuffer,
    IN OPTIONAL PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    OUT OPTIONAL PULONG_PTR BytesReturned
    );
#define WdfIoTargetSendInternalIoctlOthersSynchronously  sdv_WdfIoTargetSendInternalIoctlOthersSynchronously 
WDFAPI
NTSTATUS
sdv_WdfIoTargetSendInternalIoctlOthersSynchronously (
    IN WDFIOTARGET IoTarget,
    IN OPTIONAL WDFREQUEST Request,
    IN ULONG IoctlCode,
    IN OPTIONAL PVOID OtherArg1,
    IN OPTIONAL PVOID OtherArg2,
    IN OPTIONAL PVOID OtherArg4,
    IN OPTIONAL PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    OUT PULONG_PTR BytesReturned
    );
#define WdfIoTargetStop sdv_WdfIoTargetStop
VOID
sdv_WdfIoTargetStop(
    IN WDFIOTARGET IoTarget,
    IN WDF_IO_TARGET_SENT_IO_ACTION  Action
    );
#define WdfDeviceEnqueueRequest sdv_WdfDeviceEnqueueRequest
WDFAPI
NTSTATUS
sdv_WdfDeviceEnqueueRequest(
    IN WDFDEVICE Device,
    IN WDFREQUEST Request
    );
#define WdfRequestForwardToIoQueue sdv_WdfRequestForwardToIoQueue
NTSTATUS
sdv_WdfRequestForwardToIoQueue(
    IN WDFREQUEST Request,
    IN WDFQUEUE DestinationQueue
    );
#define WdfRequestStopAcknowledge sdv_WdfRequestStopAcknowledge
VOID
sdv_WdfRequestStopAcknowledge(
    IN WDFREQUEST Request,
    BOOLEAN Requeue
    );
#define WdfIoQueueRetrieveNextRequest sdv_WdfIoQueueRetrieveNextRequest
NTSTATUS
sdv_WdfIoQueueRetrieveNextRequest(
    IN WDFQUEUE Queue,
    OUT WDFREQUEST* OutRequest
    );
#define WdfIoQueueRetrieveRequestByFileObject sdv_WdfIoQueueRetrieveRequestByFileObject
NTSTATUS
sdv_WdfIoQueueRetrieveRequestByFileObject(
    IN WDFQUEUE Queue,
    IN WDFFILEOBJECT FileObject,
    OUT WDFREQUEST* OutRequest
    );
#define WdfIoQueueFindRequest sdv_WdfIoQueueFindRequest
NTSTATUS
sdv_WdfIoQueueFindRequest(
    IN WDFQUEUE Queue,
    IN WDFREQUEST FoundRequest,
    IN WDFFILEOBJECT FileObject,
    OUT PWDF_REQUEST_PARAMETERS Parameters,
    OUT WDFREQUEST* OutRequest
    );
#define WdfIoQueueRetrieveFoundRequest sdv_WdfIoQueueRetrieveFoundRequest
NTSTATUS
sdv_WdfIoQueueRetrieveFoundRequest(
    IN WDFQUEUE Queue,
    IN WDFREQUEST FoundRequest,
    OUT WDFREQUEST* OutRequest
    );
#define WdfIoQueueDrainSynchronously sdv_WdfIoQueueDrainSynchronously
VOID
FORCEINLINE
sdv_WdfIoQueueDrainSynchronously(
    IN WDFQUEUE Queue
    );
#define WdfIoQueueDrain sdv_WdfIoQueueDrain
VOID
FORCEINLINE
sdv_WdfIoQueueDrain(
    IN WDFQUEUE Queue,
    IN PFN_WDF_IO_QUEUE_STATE DrainComplete,
    IN WDFCONTEXT Context
    );
#define WdfIoQueuePurge sdv_WdfIoQueuePurge
VOID
sdv_WdfIoQueuePurge(
    WDFQUEUE Queue,
    PFN_WDF_IO_QUEUE_STATE PurgeComplete,
    WDFCONTEXT Context
    );
#define WdfIoQueueReadyNotify sdv_WdfIoQueueReadyNotify
NTSTATUS
sdv_WdfIoQueueReadyNotify(
    IN WDFQUEUE Queue,
    IN OPTIONAL PFN_WDF_IO_QUEUE_STATE QueueReady,
    IN OPTIONAL WDFCONTEXT Context
    );
#define WdfIoQueueStart sdv_WdfIoQueueStart
VOID
sdv_WdfIoQueueStart(
    IN WDFQUEUE Queue
    );
#define WdfIoQueueStop sdv_WdfIoQueueStop
VOID
sdv_WdfIoQueueStop(
    IN WDFQUEUE Queue,
    IN OPTIONAL PFN_WDF_IO_QUEUE_STATE StopComplete,
    IN OPTIONAL WDFCONTEXT Context
    );
#define WdfIoQueueStopSynchronously sdv_WdfIoQueueStopSynchronously
VOID
sdv_WdfIoQueueStopSynchronously(
    IN WDFQUEUE Queue
    );
#define WdfIoQueueGetState sdv_WdfIoQueueGetState
WDF_IO_QUEUE_STATE
sdv_WdfIoQueueGetState(
    IN WDFQUEUE Queue,
    OUT OPTIONAL PULONG QueueRequests,
    OUT OPTIONAL PULONG DriverRequests
    );
#ifdef WDF_IO_QUEUE_IDLE
#undef WDF_IO_QUEUE_IDLE
#endif
#define WDF_IO_QUEUE_IDLE sdv_WDF_IO_QUEUE_IDLE
BOOLEAN
sdv_WDF_IO_QUEUE_IDLE(
  IN WDF_IO_QUEUE_STATE Status);

#ifdef WdfIoQueueNoRequests
#undef WdfIoQueueNoRequests
#endif
#define WdfIoQueueNoRequests sdv_WdfIoQueueNoRequests

#ifdef WdfIoQueueDriverNoRequests
#undef WdfIoQueueDriverNoRequests
#endif
#define WdfIoQueueDriverNoRequests sdv_WdfIoQueueDriverNoRequests

#define WDF_PNPPOWER_EVENT_CALLBACKS_INIT sdv_WDF_PNPPOWER_EVENT_CALLBACKS_INIT
VOID
sdv_WDF_PNPPOWER_EVENT_CALLBACKS_INIT(
    OUT PWDF_PNPPOWER_EVENT_CALLBACKS Callbacks
    );
#define WdfDeviceInitSetPnpPowerEventCallbacks sdv_WdfDeviceInitSetPnpPowerEventCallbacks
VOID
sdv_WdfDeviceInitSetPnpPowerEventCallbacks(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PWDF_PNPPOWER_EVENT_CALLBACKS PnpPowerEventCallbacks
    );

#define WdfDeviceInitSetRequestAttributes sdv_WdfDeviceInitSetRequestAttributes
VOID
sdv_WdfDeviceInitSetRequestAttributes(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PWDF_OBJECT_ATTRIBUTES RequestAttributes
    );
#define WdfDeviceInitAssignWdmIrpPreprocessCallback sdv_WdfDeviceInitAssignWdmIrpPreprocessCallback
NTSTATUS
sdv_WdfDeviceInitAssignWdmIrpPreprocessCallback(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PFN_WDFDEVICE_WDM_IRP_PREPROCESS EvtDevicePreprocessWdmIrp,
    UCHAR MajorFunction,
    IN OPTIONAL PUCHAR MinorFunctions,
    ULONG NumMinorFunctions
    );
#define WdfDeviceInitSetIoInCallerContextCallback sdv_WdfDeviceInitSetIoInCallerContextCallback
VOID
sdv_WdfDeviceInitSetIoInCallerContextCallback(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PFN_WDF_IO_IN_CALLER_CONTEXT EvtIoInCallerContext
    );
#define WdfFileObjectGetFileName sdv_WdfFileObjectGetFileName
PUNICODE_STRING
sdv_WdfFileObjectGetFileName(
    IN WDFFILEOBJECT FileObject
    );
#define WdfDeviceInitSetExclusive sdv_WdfDeviceInitSetExclusive
WDFAPI VOID
sdv_WdfDeviceInitSetExclusive(
    IN PWDFDEVICE_INIT  DeviceInit,
    IN BOOLEAN  IsExclusive
    );
#define WdfDeviceInitAssignName sdv_WdfDeviceInitAssignName
NTSTATUS
sdv_WdfDeviceInitAssignName(
	IN PWDFDEVICE_INIT  DeviceInit,
    IN PCUNICODE_STRING  DeviceName
    );
#define WdfDeviceInitFree sdv_WdfDeviceInitFree
WDFAPI 
VOID
sdv_WdfDeviceInitFree(
    IN PWDFDEVICE_INIT  DeviceInit
    );
#define WdfDeviceInitSetPowerPolicyOwnership sdv_WdfDeviceInitSetPowerPolicyOwnership
WDFAPI VOID
sdv_WdfDeviceInitSetPowerPolicyOwnership(
    IN PWDFDEVICE_INIT  DeviceInit,
    IN BOOLEAN  IsPowerPolicyOwner
    );
#define WdfDeviceInitSetPnpPowerEventCallbacks sdv_WdfDeviceInitSetPnpPowerEventCallbacks
VOID
sdv_WdfDeviceInitSetPnpPowerEventCallbacks(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PWDF_PNPPOWER_EVENT_CALLBACKS PnpPowerEventCallbacks
    );

#define WdfDeviceInitSetFileObjectConfig sdv_WdfDeviceInitSetFileObjectConfig
VOID
sdv_WdfDeviceInitSetFileObjectConfig(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PWDF_FILEOBJECT_CONFIG  FileObjectConfig,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES FileObjectAttributes
    );
#define WdfDeviceInitSetPowerPolicyEventCallbacks sdv_WdfDeviceInitSetPowerPolicyEventCallbacks
VOID
sdv_WdfDeviceInitSetPowerPolicyEventCallbacks(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PWDF_POWER_POLICY_EVENT_CALLBACKS PowerPolicyEventCallbacks
    );
#define WdfDeviceInitRegisterPnpStateChangeCallback sdv_WdfDeviceInitRegisterPnpStateChangeCallback
NTSTATUS
sdv_WdfDeviceInitRegisterPnpStateChangeCallback(
    PWDFDEVICE_INIT DeviceInit,
    WDF_DEVICE_PNP_STATE PnpState,
    PFN_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION  EvtDevicePnpStateChange,
    ULONG CallbackTypes
    );
#define WdfDeviceInitRegisterPowerStateChangeCallback sdv_WdfDeviceInitRegisterPowerStateChangeCallback
NTSTATUS
sdv_WdfDeviceInitRegisterPowerStateChangeCallback(
    PWDFDEVICE_INIT DeviceInit,
    WDF_DEVICE_POWER_STATE PowerState,
    PFN_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION  EvtDevicePowerStateChange,
    ULONG CallbackTypes
    );
#define WdfDeviceInitRegisterPowerPolicyStateChangeCallback sdv_WdfDeviceInitRegisterPowerPolicyStateChangeCallback
NTSTATUS
sdv_WdfDeviceInitRegisterPowerPolicyStateChangeCallback(
    PWDFDEVICE_INIT DeviceInit,
    WDF_DEVICE_POWER_POLICY_STATE PowerPolicyState,
    PFN_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION  EvtDevicePowerPolicyStateChange,
    ULONG CallbackTypes
    );
#define WdfDeviceInitSetIoType sdv_WdfDeviceInitSetIoType
VOID
sdv_WdfDeviceInitSetIoType(
    IN PWDFDEVICE_INIT DeviceInit,
    IN WDF_DEVICE_IO_TYPE IoType
    );
#define WdfDeviceInitSetPowerNotPageable sdv_WdfDeviceInitSetPowerNotPageable
VOID
sdv_WdfDeviceInitSetPowerNotPageable(
    IN PWDFDEVICE_INIT DeviceInit
    );
#define WdfDeviceInitSetPowerPageable sdv_WdfDeviceInitSetPowerPageable
VOID
sdv_WdfDeviceInitSetPowerPageable(
    IN PWDFDEVICE_INIT DeviceInit
    );
#define WdfDeviceInitSetPowerInrush sdv_WdfDeviceInitSetPowerInrush
VOID
sdv_WdfDeviceInitSetPowerInrush(
    IN PWDFDEVICE_INIT DeviceInit
    );
#define WdfDeviceInitSetDeviceType sdv_WdfDeviceInitSetDeviceType
VOID
sdv_WdfDeviceInitSetDeviceType(
    IN PWDFDEVICE_INIT DeviceInit,
    IN DEVICE_TYPE DeviceType
    );
#define WdfDeviceInitAssignSDDLString sdv_WdfDeviceInitAssignSDDLString
NTSTATUS
sdv_WdfDeviceInitAssignSDDLString(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PCUNICODE_STRING SDDLString
    );
#define WdfDeviceInitSetDeviceClass sdv_WdfDeviceInitSetDeviceClass
VOID
sdv_WdfDeviceInitSetDeviceClass(
    IN PWDFDEVICE_INIT DeviceInit,
    IN CONST GUID* DeviceClassGuid
    );
#define WdfDeviceInitSetCharacteristics sdv_WdfDeviceInitSetCharacteristics
VOID
sdv_WdfDeviceInitSetCharacteristics(
    IN PWDFDEVICE_INIT DeviceInit,
    IN ULONG DeviceCharacteristics,
    IN BOOLEAN OrInValues
    );

#define WdfFdoInitSetFilter sdv_WdfFdoInitSetFilter
VOID
sdv_WdfFdoInitSetFilter(
    IN PWDFDEVICE_INIT  DeviceInit
	);
#define WdfFdoInitOpenRegistryKey sdv_WdfFdoInitOpenRegistryKey
NTSTATUS
sdv_WdfFdoInitOpenRegistryKey(
    IN PWDFDEVICE_INIT DeviceInit,
    IN ULONG DeviceInstanceKeyType,
    IN ACCESS_MASK DesiredAccess,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    OUT WDFKEY* Key
    );
#define WdfFdoInitQueryProperty sdv_WdfFdoInitQueryProperty
NTSTATUS
sdv_WdfFdoInitQueryProperty(
    IN PWDFDEVICE_INIT DeviceInit,
    IN DEVICE_REGISTRY_PROPERTY DeviceProperty,
    IN ULONG BufferLength,
    OUT PVOID PropertyBuffer,
    OUT PULONG ResultLength
    );
#define WdfFdoInitAllocAndQueryProperty sdv_WdfFdoInitAllocAndQueryProperty
NTSTATUS
sdv_WdfFdoInitAllocAndQueryProperty(
    IN PWDFDEVICE_INIT DeviceInit,
    IN DEVICE_REGISTRY_PROPERTY DeviceProperty,
    IN POOL_TYPE PoolType,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    OUT WDFMEMORY* PropertyMemory
    );
#define WdfFdoInitWdmGetPhysicalDevice sdv_WdfFdoInitWdmGetPhysicalDevice
PDEVICE_OBJECT
sdv_WdfFdoInitWdmGetPhysicalDevice(
    IN PWDFDEVICE_INIT  DeviceInit
	);
#define WdfFdoInitSetEventCallbacks sdv_WdfFdoInitSetEventCallbacks
VOID
sdv_WdfFdoInitSetEventCallbacks(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PWDF_FDO_EVENT_CALLBACKS FdoEventCallbacks
    );
#define WdfFdoInitSetDefaultChildListConfig sdv_WdfFdoInitSetDefaultChildListConfig
VOID
sdv_WdfFdoInitSetDefaultChildListConfig(
    IN OUT  PWDFDEVICE_INIT DeviceInit,
    IN PWDF_CHILD_LIST_CONFIG Config,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES DefaultChildListAttributes
    );
#define WdfPdoInitSetEventCallbacks sdv_WdfPdoInitSetEventCallbacks
VOID
sdv_WdfPdoInitSetEventCallbacks(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PWDF_PDO_EVENT_CALLBACKS DispatchTable
    );
#define WdfPdoInitAssignDeviceID sdv_WdfPdoInitAssignDeviceID 
NTSTATUS
sdv_WdfPdoInitAssignDeviceID(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PCUNICODE_STRING DeviceID
    );
#define WdfPdoInitAssignInstanceID sdv_WdfPdoInitAssignInstanceID
NTSTATUS
sdv_WdfPdoInitAssignInstanceID(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PCUNICODE_STRING InstanceID
    );
#define WdfPdoInitAddHardwareID sdv_WdfPdoInitAddHardwareID
NTSTATUS
sdv_WdfPdoInitAddHardwareID(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PCUNICODE_STRING HardwareID
    );
#define WdfPdoInitAddCompatibleID sdv_WdfPdoInitAddCompatibleID
NTSTATUS
sdv_WdfPdoInitAddCompatibleID(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PCUNICODE_STRING CompatibleID
    );
#define WdfPdoInitAddDeviceText sdv_WdfPdoInitAddDeviceText
NTSTATUS
sdv_WdfPdoInitAddDeviceText(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PCUNICODE_STRING DeviceDescription,
    IN PCUNICODE_STRING DeviceLocation,
    IN LCID LocaleId
    );
#define WdfPdoInitSetDefaultLocale sdv_WdfPdoInitSetDefaultLocale
VOID
sdv_WdfPdoInitSetDefaultLocale(
    IN PWDFDEVICE_INIT DeviceInit,
    IN LCID LocaleId
    );
#define WdfPdoInitAssignRawDevice sdv_WdfPdoInitAssignRawDevice
NTSTATUS
sdv_WdfPdoInitAssignRawDevice(
    IN PWDFDEVICE_INIT DeviceInit,
    IN CONST GUID* DeviceClassGuid
    );
#define WdfControlDeviceInitAllocate sdv_WdfControlDeviceInitAllocate
WDFAPI PWDFDEVICE_INIT
sdv_WdfControlDeviceInitAllocate(
    IN WDFDRIVER  Driver,
    IN CONST UNICODE_STRING*  SDDLString
    );
#define WdfControlDeviceInitSetShutdownNotification sdv_WdfControlDeviceInitSetShutdownNotification
VOID
sdv_WdfControlDeviceInitSetShutdownNotification(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PFN_WDF_DEVICE_SHUTDOWN_NOTIFICATION Notification,
    IN UCHAR Flags
    );
#define WdfPdoInitAllocate sdv_WdfPdoInitAllocate
PWDFDEVICE_INIT
sdv_WdfPdoInitAllocate(
    IN WDFDEVICE ParentDevice
    );
#define WdfControlFinishInitializing sdv_WdfControlFinishInitializing
VOID
sdv_WdfControlFinishInitializing(
    WDFDEVICE Device
    );
#define WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT sdv_WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT
VOID
sdv_WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT(
    PWDF_DEVICE_POWER_POLICY_IDLE_SETTINGS Settings,
    WDF_POWER_POLICY_S0_IDLE_CAPABILITIES IdleCaps
    );
#define WdfDeviceAssignS0IdleSettings sdv_WdfDeviceAssignS0IdleSettings
NTSTATUS
sdv_WdfDeviceAssignS0IdleSettings(
    WDFDEVICE Device,
    PWDF_DEVICE_POWER_POLICY_IDLE_SETTINGS Settings
    );
#define WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS_INIT sdv_WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS_INIT
VOID
sdv_WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS_INIT(
    PWDF_DEVICE_POWER_POLICY_WAKE_SETTINGS Settings
    );
#define WdfDeviceAssignSxWakeSettings sdv_WdfDeviceAssignSxWakeSettings
NTSTATUS
sdv_WdfDeviceAssignSxWakeSettings(
    WDFDEVICE Device,
    PWDF_DEVICE_POWER_POLICY_WAKE_SETTINGS Settings
    );
#define WDF_POWER_POLICY_EVENT_CALLBACKS_INIT sdv_WDF_POWER_POLICY_EVENT_CALLBACKS_INIT
VOID
sdv_WDF_POWER_POLICY_EVENT_CALLBACKS_INIT(
    PWDF_POWER_POLICY_EVENT_CALLBACKS Callbacks
    );
#define WdfCollectionCreate sdv_WdfCollectionCreate
NTSTATUS
sdv_WdfCollectionCreate(
	IN OPTIONAL PWDF_OBJECT_ATTRIBUTES CollectionAttributes,
    OUT WDFCOLLECTION *Collection
	);
#define WdfCollectionGetFirstItem sdv_WdfCollectionGetFirstItem
WDFOBJECT
sdv_WdfCollectionGetFirstItem(
    WDFCOLLECTION Collection
    );
#define WdfCollectionGetItem sdv_WdfCollectionGetItem
WDFOBJECT 
sdv_WdfCollectionGetItem(
    IN WDFCOLLECTION Collection,
    IN ULONG Index
    );
#define WdfCollectionAdd sdv_WdfCollectionAdd
WDFAPI NTSTATUS
sdv_WdfCollectionAdd(
    IN WDFCOLLECTION Collection,
    IN WDFOBJECT Object
    );
#define WdfCollectionRemoveItem sdv_WdfCollectionRemoveItem
VOID
sdv_WdfCollectionRemoveItem(
    IN WDFCOLLECTION Collection,
    IN WDFOBJECT Item
    );
#define WdfCollectionGetCount sdv_WdfCollectionGetCount
WDFAPI ULONG
sdv_WdfCollectionGetCount(
    IN WDFCOLLECTION Collection
    );
#define WdfObjectDelete sdv_WdfObjectDelete
VOID 
sdv_WdfObjectDelete(
    IN WDFOBJECT Object
    );
#define WdfFdoQueryForInterface sdv_WdfFdoQueryForInterface
NTSTATUS 
sdv_WdfFdoQueryForInterface(
    IN WDFDEVICE Device,
    IN LPCGUID InterfaceType,
    IN OUT PINTERFACE Interface,
    IN USHORT Size,
    IN USHORT Version,
    IN OUT PVOID InterfaceSpecificData
    );
#define WDF_DEVICE_STATE_INIT sdv_WDF_DEVICE_STATE_INIT
VOID
sdv_WDF_DEVICE_STATE_INIT(
    OUT PWDF_DEVICE_STATE PnpDeviceState
    );
#define WdfDeviceSetDeviceState sdv_WdfDeviceSetDeviceState
VOID
sdv_WdfDeviceSetDeviceState(
    IN WDFDEVICE Device,
    IN PWDF_DEVICE_STATE DeviceState
    );
#define WdfDeviceAssignMofResourceName sdv_WdfDeviceAssignMofResourceName
NTSTATUS 
sdv_WdfDeviceAssignMofResourceName(
    IN WDFDEVICE Device,
    IN PCUNICODE_STRING MofResourceName
    );
#define WPP_INIT_TRACING sdv_WPP_INIT_TRACING
VOID
sdv_WPP_INIT_TRACING(
	 IN PDRIVER_OBJECT DriverObject,
     IN PUNICODE_STRING RegistryPath
           );
#define WDF_INTERRUPT_CONFIG_INIT sdv_WDF_INTERRUPT_CONFIG_INIT
VOID
sdv_WDF_INTERRUPT_CONFIG_INIT(
    OUT PWDF_INTERRUPT_CONFIG Configuration,
    IN  PFN_WDF_INTERRUPT_ISR EvtInterruptIsr,
    IN  PFN_WDF_INTERRUPT_DPC EvtInterruptDpc
    );

#define WdfInterruptCreate sdv_WdfInterruptCreate
NTSTATUS
sdv_WdfInterruptCreate(
    IN WDFDEVICE Device,
    IN PWDF_INTERRUPT_CONFIG Configuration,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES Attributes,
    OUT WDFINTERRUPT* Interrupt
    );

#define WdfInterruptSynchronize sdv_WdfInterruptSynchronize
BOOLEAN
sdv_WdfInterruptSynchronize(
    IN WDFINTERRUPT Interrupt,
    IN PFN_WDF_INTERRUPT_SYNCHRONIZE Callback,
    IN WDFCONTEXT Context
    );
#define WdfSpinLockCreate sdv_WdfSpinLockCreate
NTSTATUS
sdv_WdfSpinLockCreate(
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES SpinLockAttributes,
    OUT WDFSPINLOCK* SpinLock
    );
#define WdfSpinLockAcquire sdv_WdfSpinLockAcquire
VOID
sdv_WdfSpinLockAcquire(
    IN WDFSPINLOCK SpinLock
    );
#define WdfSpinLockRelease sdv_WdfSpinLockRelease
VOID
sdv_WdfSpinLockRelease(
    IN WDFSPINLOCK SpinLock
    );
#define WdfObjectAcquireLock sdv_WdfObjectAcquireLock
VOID
sdv_WdfObjectAcquireLock(
    IN WDFOBJECT Object
    );
#define WdfObjectReleaseLock sdv_WdfObjectReleaseLock
VOID
sdv_WdfObjectReleaseLock(
    IN WDFOBJECT Object
    );
#define WdfStringGetUnicodeString sdv_WdfStringGetUnicodeString
VOID
sdv_WdfStringGetUnicodeString(
    IN WDFSTRING String,
    PUNICODE_STRING UnicodeString
    );
#define	WdfDeviceGetDevicePowerState	sdv_WdfDeviceGetDevicePowerState
WDF_DEVICE_POWER_STATE
sdv_WdfDeviceGetDevicePowerState(
    __in WDFDEVICE Device
    );
#define	WdfDeviceGetDevicePowerPolicyState	sdv_WdfDeviceGetDevicePowerPolicyState
WDF_DEVICE_POWER_POLICY_STATE
sdv_WdfDeviceGetDevicePowerPolicyState(
    __in WDFDEVICE Device
    );
#define	WdfDeviceSetPowerCapabilities	sdv_WdfDeviceSetPowerCapabilities
VOID
sdv_WdfDeviceSetPowerCapabilities(
    __in WDFDEVICE Device,
    __in PWDF_DEVICE_POWER_CAPABILITIES PowerCapabilities
    );
#define	WdfWdmDeviceGetWdfDeviceHandle	sdv_WdfWdmDeviceGetWdfDeviceHandle
WDFDEVICE
sdv_WdfWdmDeviceGetWdfDeviceHandle(
	IN PDEVICE_OBJECT DeviceObject
    );

#define	WdfDeviceWdmGetDeviceObject	sdv_WdfDeviceWdmGetDeviceObject
PDEVICE_OBJECT
sdv_WdfDeviceWdmGetDeviceObject(
   __in WDFDEVICE Device
    );

#define	WdfDeviceWdmGetPhysicalDevice	sdv_WdfDeviceWdmGetPhysicalDevice
PDEVICE_OBJECT
sdv_WdfDeviceWdmGetPhysicalDevice(
    __in WDFDEVICE Device
    );

#define	__sdv_save_request sdv_save_request
void sdv_save_request(void *r);
#define	__sdv_retrieve_request sdv_retrieve_request
void sdv_retrieve_request(void *r);
#define	WdfDeviceWdmGetAttachedDevice sdv_WdfDeviceWdmGetAttachedDevice
PDEVICE_OBJECT sdv_WdfDeviceWdmGetAttachedDevice(
    IN WDFDEVICE  Device);
#define	WdfDeviceWdmDispatchPreprocessedIrp sdv_WdfDeviceWdmDispatchPreprocessedIrp
NTSTATUS  sdv_WdfDeviceWdmDispatchPreprocessedIrp(
    WDFDEVICE  Device,
    PIRP  Irp    );
#endif

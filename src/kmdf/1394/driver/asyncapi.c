/*++

Copyright (c) 1998  Microsoft Corporation

Module Name:

    async.c

Abstract:

--*/

#include "pch.h"


NTSTATUS
t1394_AllocateAddressRange(
    IN WDFDEVICE            Device,
    IN WDFREQUEST           Request,
    IN ULONG                fulAllocateFlags,
    IN ULONG                fulFlags,
    IN ULONG                nLength,
    IN ULONG                MaxSegmentSize,
    IN ULONG                fulAccessType,
    IN ULONG                fulNotificationOptions,
    IN OUT PADDRESS_OFFSET  Required1394Offset,
    OUT PHANDLE             phAddressRange,
    IN OUT PULONG           Data
    )
{
    NTSTATUS                ntStatus          = STATUS_SUCCESS;
    PDEVICE_EXTENSION       deviceExtension   = GetDeviceContext(Device);
    PIRB                    pIrb              = NULL;
    PASYNC_ADDRESS_DATA     pAsyncAddressData = NULL;
    ULONG                   nPages;

    UNREFERENCED_PARAMETER(fulAllocateFlags);

    ENTER("t1394_AllocateAddressRange");

    TRACE(TL_TRACE, ("fulAllocateFlags = 0x%x\n", fulAllocateFlags));
    TRACE(TL_TRACE, ("fulFlags = 0x%x\n", fulFlags));
    TRACE(TL_TRACE, ("nLength = 0x%x\n", nLength));
    TRACE(TL_TRACE, ("MaxSegmentSize = 0x%x\n", MaxSegmentSize));
    TRACE(TL_TRACE, ("fulAccessType = 0x%x\n", fulAccessType));
    TRACE(TL_TRACE, ("fulNotificationOptions = 0x%x\n", fulNotificationOptions));
    TRACE(TL_TRACE, ("Required1394Offset->Off_High = 0x%x\n", Required1394Offset->Off_High));
    TRACE(TL_TRACE, ("Required1394Offset->Off_Low = 0x%x\n", Required1394Offset->Off_Low));
    TRACE(TL_TRACE, ("Data = 0x%x\n", Data));

    if (nLength == 0) {

        TRACE(TL_ERROR, ("Invalid nLength!\n"));
        ntStatus = STATUS_INVALID_PARAMETER;
        goto Exit_AllocateAddressRange;
    }

    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_AllocateAddressRange;
    } // if

    pAsyncAddressData = ExAllocatePoolWithTag(NonPagedPool,
                                              sizeof(ASYNC_ADDRESS_DATA),
                                              POOLTAG_1394);

    if (!pAsyncAddressData) {

        TRACE(TL_ERROR, ("Failed to allocate pAsyncAddressData!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_AllocateAddressRange;
    }

    pAsyncAddressData->Buffer = ExAllocatePoolWithTag(NonPagedPool, nLength, POOLTAG_1394);

    TRACE(TL_TRACE, ("pAsyncAddressData->Buffer = 0x%x\n", pAsyncAddressData->Buffer));

    if (!pAsyncAddressData->Buffer) {

        TRACE(TL_ERROR, ("Failed to allocate Buffer!\n"));
        ExFreePoolWithTag(pAsyncAddressData, POOLTAG_1394);

        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_AllocateAddressRange;
    }

    // we need to know how big our address range buffer will be, depends on maxSegmentSize
    if ((0 == MaxSegmentSize) || (PAGE_SIZE == MaxSegmentSize))
    {
        nPages = ADDRESS_AND_SIZE_TO_SPAN_PAGES(Data, nLength);
    }
    else
    {
        // check to see if MaxSegmentSize divides nLength evenly or not
        nPages = (nLength % MaxSegmentSize) ? nLength / MaxSegmentSize + 1 : nLength / MaxSegmentSize;
    }

    TRACE(TL_TRACE, ("nPages = 0x%x\n", nPages));

    pAsyncAddressData->AddressRange = ExAllocatePoolWithTag(NonPagedPool,
                                                            sizeof(ADDRESS_RANGE)*nPages,
                                                            POOLTAG_1394);

    if (!pAsyncAddressData->AddressRange) {

        TRACE(TL_ERROR, ("Failed to allocate AddressRange!\n"));
        if (pAsyncAddressData->Buffer)
            ExFreePoolWithTag(pAsyncAddressData->Buffer, POOLTAG_1394);

        ExFreePoolWithTag(pAsyncAddressData, POOLTAG_1394);

        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_AllocateAddressRange;
    }

    pAsyncAddressData->pMdl = IoAllocateMdl (pAsyncAddressData->Buffer,
                                             nLength,
                                             FALSE,
                                             FALSE,
                                             NULL);

    if (!pAsyncAddressData->pMdl) {

        TRACE(TL_ERROR, ("Failed to create pMdl!\n"));
        if (pAsyncAddressData->AddressRange)
            ExFreePoolWithTag(pAsyncAddressData->AddressRange, POOLTAG_1394);

        if (pAsyncAddressData->Buffer)
            ExFreePoolWithTag(pAsyncAddressData->Buffer, POOLTAG_1394);

        ExFreePoolWithTag(pAsyncAddressData, POOLTAG_1394);

        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_AllocateAddressRange;
    }

    MmBuildMdlForNonPagedPool(pAsyncAddressData->pMdl);

    TRACE(TL_TRACE, ("pMdl = 0x%x\n", pAsyncAddressData->pMdl));

    // copy over the contents of data to our driver buffer
    RtlCopyMemory(pAsyncAddressData->Buffer, Data, nLength);
    pAsyncAddressData->nLength = nLength;

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ALLOCATE_ADDRESS_RANGE;
    pIrb->Flags = 0;
    pIrb->u.AllocateAddressRange.Mdl = pAsyncAddressData->pMdl;
    pIrb->u.AllocateAddressRange.fulFlags = fulFlags;
    pIrb->u.AllocateAddressRange.nLength = nLength;
    pIrb->u.AllocateAddressRange.MaxSegmentSize = MaxSegmentSize;
    pIrb->u.AllocateAddressRange.fulAccessType = fulAccessType;
    pIrb->u.AllocateAddressRange.fulNotificationOptions = fulNotificationOptions;


    pIrb->u.AllocateAddressRange.Callback = NULL;
    pIrb->u.AllocateAddressRange.Context = NULL;

    pIrb->u.AllocateAddressRange.Required1394Offset = *Required1394Offset;
    pIrb->u.AllocateAddressRange.FifoSListHead = NULL;
    pIrb->u.AllocateAddressRange.FifoSpinLock = NULL;
    pIrb->u.AllocateAddressRange.AddressesReturned = 0;
    pIrb->u.AllocateAddressRange.p1394AddressRange = pAsyncAddressData->AddressRange;
    pIrb->u.AllocateAddressRange.DeviceExtension = deviceExtension;


    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (NT_SUCCESS(ntStatus)) {

        ULONG   i;

        // save off info into our struct...
        pAsyncAddressData->DeviceExtension = deviceExtension;
        pAsyncAddressData->nAddressesReturned = pIrb->u.AllocateAddressRange.AddressesReturned;
//        pAsyncAddressData->AddressRange = pIrb->u.AllocateAddressRange.p1394AddressRange;
        pAsyncAddressData->hAddressRange = pIrb->u.AllocateAddressRange.hAddressRange;

        // add our struct to the list...

        WdfSpinLockAcquire(deviceExtension->AsyncSpinLock);
        InsertHeadList(&deviceExtension->AsyncAddressData, &pAsyncAddressData->AsyncAddressList);

        WdfSpinLockRelease(deviceExtension->AsyncSpinLock);

        *phAddressRange = pIrb->u.AllocateAddressRange.hAddressRange;

        TRACE(TL_TRACE, ("AddressesReturned = 0x%x\n", pIrb->u.AllocateAddressRange.AddressesReturned));
        TRACE(TL_TRACE, ("hAddressRange = 0x%x\n", *phAddressRange));

        for (i=0; i < pIrb->u.AllocateAddressRange.AddressesReturned; i++) {

            TRACE(TL_TRACE, ("Off_High = 0x%x\n", pAsyncAddressData->AddressRange[0].AR_Off_High));
            TRACE(TL_TRACE, ("Off_Low = 0x%x\n", pAsyncAddressData->AddressRange[0].AR_Off_Low));
        }

        Required1394Offset->Off_High = pIrb->u.AllocateAddressRange.p1394AddressRange[0].AR_Off_High;
        Required1394Offset->Off_Low = pIrb->u.AllocateAddressRange.p1394AddressRange[0].AR_Off_Low;
    }
    else {
        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
        // need to free a few things...
        if (pAsyncAddressData->pMdl)
            IoFreeMdl(pAsyncAddressData->pMdl);

        if (pAsyncAddressData->Buffer)
            ExFreePoolWithTag(pAsyncAddressData->Buffer, POOLTAG_1394);

        if (pAsyncAddressData->AddressRange)
            ExFreePoolWithTag(pAsyncAddressData->AddressRange, POOLTAG_1394);

        ExFreePoolWithTag(pAsyncAddressData, POOLTAG_1394);
    }

Exit_AllocateAddressRange:

    if (pIrb)
        ExFreePoolWithTag(pIrb, POOLTAG_1394);

    EXIT("t1394_AllocateAddressRange", ntStatus);
    return(ntStatus);
} // t1394_AllocateAddressRange

NTSTATUS
t1394_FreeAddressRange(
    IN WDFDEVICE   Device,
    IN WDFREQUEST  Request,
    IN HANDLE      hAddressRange
    )
{
    NTSTATUS                ntStatus          = STATUS_SUCCESS;
    PDEVICE_EXTENSION       deviceExtension   = GetDeviceContext(Device);
    PIRB                    pIrb              = NULL;
    PASYNC_ADDRESS_DATA     AsyncAddressData  = NULL;
    PLIST_ENTRY             listHead;
    PLIST_ENTRY             thisEntry;

    UNREFERENCED_PARAMETER(Request);

    ENTER("t1394_FreeAddressRange");

    TRACE(TL_TRACE, ("hAddressRange = 0x%x\n", hAddressRange));


    // have to find our struct...

    WdfSpinLockAcquire(deviceExtension->AsyncSpinLock);

    listHead = &deviceExtension->AsyncAddressData;

    for(thisEntry = listHead->Flink;
                    thisEntry != listHead;
                    AsyncAddressData = NULL, thisEntry = thisEntry->Flink)
    {
        AsyncAddressData = CONTAINING_RECORD(thisEntry, ASYNC_ADDRESS_DATA,
                                                                            AsyncAddressList);

        if (AsyncAddressData->hAddressRange == hAddressRange) {

            RemoveEntryList(&AsyncAddressData->AsyncAddressList);
            break;
        }
    }


    WdfSpinLockRelease(deviceExtension->AsyncSpinLock);

    // never found an entry...
    if (!AsyncAddressData) {

        ntStatus = STATUS_INVALID_PARAMETER;
        goto Exit_FreeAddressRange;
    }

    // got it, lets free it...

    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        // we need to add this back into our list since we were
        // unable to free it...

        WdfSpinLockAcquire(deviceExtension->AsyncSpinLock);
        InsertHeadList(&deviceExtension->AsyncAddressData, &AsyncAddressData->AsyncAddressList);

        WdfSpinLockRelease(deviceExtension->AsyncSpinLock);

        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_FreeAddressRange;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_FREE_ADDRESS_RANGE;
    pIrb->Flags = 0;
    pIrb->u.FreeAddressRange.nAddressesToFree = AsyncAddressData->nAddressesReturned;
    pIrb->u.FreeAddressRange.p1394AddressRange = AsyncAddressData->AddressRange;
    pIrb->u.FreeAddressRange.pAddressRange = &AsyncAddressData->hAddressRange;
    pIrb->u.FreeAddressRange.DeviceExtension = (PVOID)deviceExtension;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    // need to free up everything associated with this allocate...
    if (AsyncAddressData->pMdl) {
        IoFreeMdl(AsyncAddressData->pMdl);
    }
    if (AsyncAddressData->Buffer) {
        ExFreePoolWithTag(AsyncAddressData->Buffer, POOLTAG_1394);
    }

    if (AsyncAddressData->AddressRange) {
        ExFreePoolWithTag(AsyncAddressData->AddressRange, POOLTAG_1394);
    }

    ExFreePoolWithTag(AsyncAddressData, POOLTAG_1394);


Exit_FreeAddressRange:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_FreeAddressRange", ntStatus);
    return(ntStatus);
} // t1394_FreeAddressRange

NTSTATUS
t1394_GetAddressData(
    IN  WDFDEVICE      Device,
    IN WDFREQUEST      Request,
    IN  HANDLE         hAddressRange,
    IN  ULONG          nLength,
    IN  ULONG          ulOffset,
    __out_bcount(nLength) PVOID          Data
    )
{
    NTSTATUS                ntStatus         = STATUS_SUCCESS;
    PDEVICE_EXTENSION       deviceExtension  = GetDeviceContext(Device);
    PASYNC_ADDRESS_DATA     AsyncAddressData = NULL;
    PLIST_ENTRY             listHead;
    PLIST_ENTRY             thisEntry;

    UNREFERENCED_PARAMETER(Request);

    ENTER("t1394_GetAddressData");

    TRACE(TL_TRACE, ("hAddressRange = 0x%x\n", hAddressRange));
    TRACE(TL_TRACE, ("nLength = 0x%x\n", nLength));
    TRACE(TL_TRACE, ("ulOffset = 0x%x\n", ulOffset));

    // have to find our struct...

    WdfSpinLockAcquire(deviceExtension->AsyncSpinLock);

    listHead = &deviceExtension->AsyncAddressData;

    for(thisEntry = listHead->Flink;
                    thisEntry != listHead;
                    AsyncAddressData = NULL, thisEntry = thisEntry->Flink)
    {
        AsyncAddressData = CONTAINING_RECORD(thisEntry, ASYNC_ADDRESS_DATA,
                                                                            AsyncAddressList);

        if (AsyncAddressData->hAddressRange == hAddressRange) {

            PCHAR   pBuffer;

            // found it, let's copy over the contents to our buffer
            pBuffer = (PCHAR)((ULONG_PTR)AsyncAddressData->Buffer + ulOffset);

            TRACE(TL_TRACE, ("pBuffer = 0x%x\n", pBuffer));
            TRACE(TL_TRACE, ("Data = 0x%x\n", Data));
            if(pBuffer && Data) {
                RtlCopyMemory(Data, pBuffer, nLength);
            }
            break;
        }
    }


    WdfSpinLockRelease(deviceExtension->AsyncSpinLock);

    // never found an entry...
    if (!AsyncAddressData) {

        ntStatus = STATUS_INVALID_PARAMETER;
    }

    EXIT("t1394_GetAddressData", ntStatus);
    return(ntStatus);
} // t1394_GetAddressData

NTSTATUS
t1394_SetAddressData(
    IN WDFDEVICE       Device,
    IN WDFREQUEST      Request,
    IN HANDLE          hAddressRange,
    IN ULONG           nLength,
    IN ULONG           ulOffset,
    IN PVOID           Data
    )
{
    NTSTATUS             ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION    deviceExtension = GetDeviceContext(Device);
    PASYNC_ADDRESS_DATA  AsyncAddressData = NULL;
    PLIST_ENTRY          listHead;
    PLIST_ENTRY          thisEntry;

    UNREFERENCED_PARAMETER(Request);

    ENTER("t1394_SetAddressData");

    TRACE(TL_TRACE, ("hAddressRange = 0x%x\n", hAddressRange));
    TRACE(TL_TRACE, ("nLength = 0x%x\n", nLength));
    TRACE(TL_TRACE, ("ulOffset = 0x%x\n", ulOffset));

    // have to find our struct...

    WdfSpinLockAcquire(deviceExtension->AsyncSpinLock);

    listHead = &deviceExtension->AsyncAddressData;

    for(thisEntry = listHead->Flink;
                    thisEntry != listHead;
                    AsyncAddressData = NULL, thisEntry = thisEntry->Flink)
    {
        AsyncAddressData = CONTAINING_RECORD(thisEntry, ASYNC_ADDRESS_DATA,
                                                                            AsyncAddressList);

        if (AsyncAddressData->hAddressRange == hAddressRange) {
            PULONG  pBuffer;

            // found it, let's copy over the contents from data...
            pBuffer = (PULONG)((ULONG_PTR)AsyncAddressData->Buffer + ulOffset);

            TRACE(TL_TRACE, ("pBuffer = 0x%x\n", pBuffer));
            TRACE(TL_TRACE, ("Data = 0x%x\n", Data));
            if(pBuffer && Data) {
                RtlCopyMemory(pBuffer, Data, nLength);
            }
            break;
        }
    }



    WdfSpinLockRelease(deviceExtension->AsyncSpinLock);

    // never found an entry...
    if (!AsyncAddressData) {

        ntStatus = STATUS_INVALID_PARAMETER;
    }

    EXIT("t1394_SetAddressData", ntStatus);
    return(ntStatus);
} // t1394_SetAddressData

NTSTATUS
t1394_AsyncRead(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN ULONG            bRawMode,
    IN ULONG            bGetGeneration,
    IN IO_ADDRESS       DestinationAddress,
    IN ULONG            nNumberOfBytesToRead,
    IN ULONG            nBlockSize,
    IN ULONG            fulFlags,
    IN ULONG            ulGeneration,
    IN OUT PULONG       Data
    )
{
    NTSTATUS            ntStatus            = STATUS_SUCCESS;
    PDEVICE_EXTENSION       deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb                = NULL;
    PMDL                pMdl                = NULL;
    WDFIOTARGET      ioTarget    = NULL;

    ENTER("t1394_AsyncRead");

    TRACE(TL_TRACE, ("bRawMode = %d\n", bRawMode));
    TRACE(TL_TRACE, ("bGetGeneration = %d\n", bGetGeneration));
    TRACE(TL_TRACE, ("DestinationAddress.IA_Destination_ID.NA_Bus_Number = 0x%x\n", DestinationAddress.IA_Destination_ID.NA_Bus_Number));
    TRACE(TL_TRACE, ("DestinationAddress.IA_Destination_ID.NA_Node_Number = 0x%x\n", DestinationAddress.IA_Destination_ID.NA_Node_Number));
    TRACE(TL_TRACE, ("DestinationAddress.IA_Destination_Offset.Off_High = 0x%x\n", DestinationAddress.IA_Destination_Offset.Off_High));
    TRACE(TL_TRACE, ("DestinationAddress.IA_Destination_Offset.Off_Low = 0x%x\n", DestinationAddress.IA_Destination_Offset.Off_Low));
    TRACE(TL_TRACE, ("nNumberOfBytesToRead = 0x%x\n", nNumberOfBytesToRead));
    TRACE(TL_TRACE, ("nBlockSize = 0x%x\n", nBlockSize));
    TRACE(TL_TRACE, ("fulFlags = 0x%x\n", fulFlags));
    TRACE(TL_TRACE, ("ulGeneration = 0x%x\n", ulGeneration));
    TRACE(TL_TRACE, ("Data = 0x%x\n", Data));


    if (nNumberOfBytesToRead == 0) {

        TRACE(TL_ERROR, ("Invalid nNumberOfBytesToRead size!\n"));
        ntStatus = STATUS_INVALID_PARAMETER;
        goto Exit_AsyncRead;
    }

    //
    // get the location of the next device object in the stack
    //
    if (bRawMode) {
        ioTarget = deviceExtension->PortDeviceIoTarget;
    }
    else {
        ioTarget = deviceExtension->StackIoTarget;
    }

    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_AsyncRead;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ASYNC_READ;
    pIrb->Flags = 0;
    pIrb->u.AsyncRead.DestinationAddress = DestinationAddress;
    pIrb->u.AsyncRead.nNumberOfBytesToRead = nNumberOfBytesToRead;
    pIrb->u.AsyncRead.nBlockSize = nBlockSize;
    pIrb->u.AsyncRead.fulFlags = fulFlags;

    if (bGetGeneration) {

        pIrb->u.AsyncRead.ulGeneration = deviceExtension->GenerationCount;
        TRACE(TL_TRACE, ("Retrieved Generation Count = 0x%x\n", pIrb->u.AsyncRead.ulGeneration));
    }
    else {

        pIrb->u.AsyncRead.ulGeneration = ulGeneration;
    }

    pMdl = IoAllocateMdl (Data,
                          nNumberOfBytesToRead,
                          FALSE,
                          FALSE,
                          NULL);
    if(pMdl == NULL) {
        TRACE(TL_ERROR, ("Failed to allocate mdl!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_AsyncRead;
    }
    MmBuildMdlForNonPagedPool(pMdl);

    pIrb->u.AsyncRead.Mdl = pMdl;

    ntStatus = t1394_SubmitIrpSynch(ioTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));

        if (ntStatus != STATUS_INVALID_GENERATION) {
        }
    }
    else {

    }



Exit_AsyncRead:

    if (pMdl)
    {
        IoFreeMdl(pMdl);
    }

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_AsyncRead", ntStatus);
    return(ntStatus);
} // t1394_AsyncRead

NTSTATUS
t1394_AsyncWrite(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN ULONG            bRawMode,
    IN ULONG            bGetGeneration,
    IN IO_ADDRESS       DestinationAddress,
    IN ULONG            nNumberOfBytesToWrite,
    IN ULONG            nBlockSize,
    IN ULONG            fulFlags,
    IN ULONG            ulGeneration,
    IN OUT PULONG       Data
    )
{
    NTSTATUS            ntStatus            = STATUS_SUCCESS;
    PDEVICE_EXTENSION       deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb                = NULL;
    PMDL                pMdl                = NULL;
    WDFIOTARGET ioTarget    = NULL;

    ENTER("t1394_AsyncWrite");

    TRACE(TL_TRACE, ("bRawMode = %d\n", bRawMode));
    TRACE(TL_TRACE, ("bGetGeneration = %d\n", bGetGeneration));
    TRACE(TL_TRACE, ("DestinationAddress.IA_Destination_ID.NA_Bus_Number = 0x%x\n", DestinationAddress.IA_Destination_ID.NA_Bus_Number));
    TRACE(TL_TRACE, ("DestinationAddress.IA_Destination_ID.NA_Node_Number = 0x%x\n", DestinationAddress.IA_Destination_ID.NA_Node_Number));
    TRACE(TL_TRACE, ("DestinationAddress.IA_Destination_Offset.Off_High = 0x%x\n", DestinationAddress.IA_Destination_Offset.Off_High));
    TRACE(TL_TRACE, ("DestinationAddress.IA_Destination_Offset.Off_Low = 0x%x\n", DestinationAddress.IA_Destination_Offset.Off_Low));
    TRACE(TL_TRACE, ("nNumberOfBytesToWrite = 0x%x\n", nNumberOfBytesToWrite));
    TRACE(TL_TRACE, ("nBlockSize = 0x%x\n", nBlockSize));
    TRACE(TL_TRACE, ("fulFlags = 0x%x\n", fulFlags));
    TRACE(TL_TRACE, ("ulGeneration = 0x%x\n", ulGeneration));
    TRACE(TL_TRACE, ("Data = 0x%x\n", Data));

    if (nNumberOfBytesToWrite == 0) {

        TRACE(TL_ERROR, ("Invalid nNumberOfBytesToWrite size!\n"));
        ntStatus = STATUS_INVALID_PARAMETER;
        goto Exit_AsyncWrite;
    }

    //
    // get the location of the next device object in the stack
    //
    if (bRawMode) {
        ioTarget = deviceExtension->PortDeviceIoTarget;
    }
    else {
        ioTarget = deviceExtension->StackIoTarget;
    }


    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_AsyncWrite;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ASYNC_WRITE;
    pIrb->Flags = 0;
    pIrb->u.AsyncWrite.DestinationAddress = DestinationAddress;
    pIrb->u.AsyncWrite.nNumberOfBytesToWrite = nNumberOfBytesToWrite;
    pIrb->u.AsyncWrite.nBlockSize = nBlockSize;
    pIrb->u.AsyncWrite.fulFlags = fulFlags;

    if (bGetGeneration) {

        pIrb->u.AsyncRead.ulGeneration = deviceExtension->GenerationCount;
        TRACE(TL_TRACE, ("Retrieved Generation Count = 0x%x\n", pIrb->u.AsyncRead.ulGeneration));
    }
    else {
        pIrb->u.AsyncRead.ulGeneration = ulGeneration;
    }

    pMdl = IoAllocateMdl (Data,
                          nNumberOfBytesToWrite,
                          FALSE,
                          FALSE,
                          NULL);
    if(pMdl == NULL) {
        TRACE(TL_ERROR, ("Failed to allocate mdl!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_AsyncWrite;
    }

    MmBuildMdlForNonPagedPool(pMdl);

    pIrb->u.AsyncWrite.Mdl = pMdl;

    ntStatus = t1394_SubmitIrpSynch(ioTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));

        if (ntStatus != STATUS_INVALID_GENERATION) {
        }
    }
    else {

    }


Exit_AsyncWrite:

    if (pMdl)
    {
        IoFreeMdl(pMdl);
    }

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_AsyncWrite", ntStatus);
    return(ntStatus);
} // t1394_AsyncWrite

NTSTATUS
t1394_AsyncLock(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN ULONG            bRawMode,
    IN ULONG            bGetGeneration,
    IN IO_ADDRESS       DestinationAddress,
    IN ULONG            nNumberOfArgBytes,
    IN ULONG            nNumberOfDataBytes,
    IN ULONG            fulTransactionType,
    IN ULONG            fulFlags,
    IN ULONG            Arguments[2],
    IN ULONG            DataValues[2],
    IN ULONG            ulGeneration,
    IN OUT PVOID        Buffer
    )
{
    NTSTATUS            ntStatus            = STATUS_SUCCESS;
    PDEVICE_EXTENSION       deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb                = NULL;
    WDFIOTARGET ioTarget    = NULL;

    ENTER("t1394_AsyncLock");

    TRACE(TL_TRACE, ("bRawMode = %d\n", bRawMode));
    TRACE(TL_TRACE, ("bGetGeneration = %d\n", bGetGeneration));
    TRACE(TL_TRACE, ("DestinationAddress.IA_Destination_ID.NA_Bus_Number = 0x%x\n", DestinationAddress.IA_Destination_ID.NA_Bus_Number));
    TRACE(TL_TRACE, ("DestinationAddress.IA_Destination_ID.NA_Node_Number = 0x%x\n", DestinationAddress.IA_Destination_ID.NA_Node_Number));
    TRACE(TL_TRACE, ("DestinationAddress.IA_Destination_Offset.Off_High = 0x%x\n", DestinationAddress.IA_Destination_Offset.Off_High));
    TRACE(TL_TRACE, ("DestinationAddress.IA_Destination_Offset.Off_Low = 0x%x\n", DestinationAddress.IA_Destination_Offset.Off_Low));
    TRACE(TL_TRACE, ("nNumberOfArgBytes = 0x%x\n", nNumberOfArgBytes));
    TRACE(TL_TRACE, ("nNumberOfDataBytes = 0x%x\n", nNumberOfDataBytes));
    TRACE(TL_TRACE, ("fulTransactionType = 0x%x\n", fulTransactionType));
    TRACE(TL_TRACE, ("fulFlags = 0x%x\n", fulFlags));
    TRACE(TL_TRACE, ("Arguments[0] = 0x%x\n", Arguments[0]));
    TRACE(TL_TRACE, ("Arguments[1] = 0x%x\n", Arguments[1]));
    TRACE(TL_TRACE, ("DataValues[0] = 0x%x\n", DataValues[0]));
    TRACE(TL_TRACE, ("DataValues[1] = 0x%x\n", DataValues[1]));
    TRACE(TL_TRACE, ("ulGeneration = 0x%x\n", ulGeneration));
    TRACE(TL_TRACE, ("Buffer = 0x%x\n", Buffer));

    //
    // get the location of the next device object in the stack
    //
    if (bRawMode) {
        ioTarget = deviceExtension->PortDeviceIoTarget;
    }
    else {
        ioTarget = deviceExtension->StackIoTarget;
    }

    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_AsyncLock;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ASYNC_LOCK;
    pIrb->Flags = 0;
    pIrb->u.AsyncLock.DestinationAddress = DestinationAddress;
    pIrb->u.AsyncLock.nNumberOfArgBytes = nNumberOfArgBytes;
    pIrb->u.AsyncLock.nNumberOfDataBytes = nNumberOfDataBytes;
    pIrb->u.AsyncLock.fulTransactionType = fulTransactionType;
    pIrb->u.AsyncLock.fulFlags = fulFlags;
    pIrb->u.AsyncLock.Arguments[0] = Arguments[0];
    pIrb->u.AsyncLock.Arguments[1] = Arguments[1];
    pIrb->u.AsyncLock.DataValues[0] = DataValues[0];
    pIrb->u.AsyncLock.DataValues[1] = DataValues[1];
    pIrb->u.AsyncLock.pBuffer = Buffer;

    if (bGetGeneration) {

        pIrb->u.AsyncLock.ulGeneration = deviceExtension->GenerationCount;
        TRACE(TL_TRACE, ("Retrieved Generation Count = 0x%x\n", pIrb->u.AsyncLock.ulGeneration));
    }
    else {
        pIrb->u.AsyncLock.ulGeneration = ulGeneration;
    }

    ntStatus = t1394_SubmitIrpSynch(ioTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));

        if (ntStatus != STATUS_INVALID_GENERATION) {
        }
    }


Exit_AsyncLock:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_AsyncLock", ntStatus);
    return(ntStatus);
} // t1394_AsyncLock

NTSTATUS
t1394_AsyncStream(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN ULONG            nNumberOfBytesToStream,
    IN ULONG            fulFlags,
    IN ULONG            ulTag,
    IN ULONG            nChannel,
    IN ULONG            ulSynch,
    IN UCHAR            nSpeed,
    IN OUT PULONG       Data
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION       deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;
    PMDL                pMdl            = NULL;

    ENTER("t1394_AsyncStream");

    TRACE(TL_TRACE, ("nNumberOfBytesToStream = 0x%x\n", nNumberOfBytesToStream));
    TRACE(TL_TRACE, ("fulFlags = 0x%x\n", fulFlags));
    TRACE(TL_TRACE, ("ulTag = 0x%x\n", ulTag));
    TRACE(TL_TRACE, ("nChannel = 0x%x\n", nChannel));
    TRACE(TL_TRACE, ("ulSynch = 0x%x\n", ulSynch));
    TRACE(TL_TRACE, ("nSpeed = 0x%x\n", nSpeed));

    if (nNumberOfBytesToStream == 0) {

        TRACE(TL_ERROR, ("Invalid nNumberOfBytesToStream size!\n"));
        ntStatus = STATUS_INVALID_PARAMETER;
        goto Exit_AsyncStream;
    }

    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_AsyncStream;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ASYNC_STREAM;
    pIrb->Flags = 0;
    pIrb->u.AsyncStream.nNumberOfBytesToStream = nNumberOfBytesToStream;
    pIrb->u.AsyncStream.fulFlags = fulFlags;
    pIrb->u.AsyncStream.ulTag = ulTag;
    pIrb->u.AsyncStream.nChannel = nChannel;
    pIrb->u.AsyncStream.ulSynch = ulSynch;
    pIrb->u.AsyncStream.nSpeed = nSpeed;

    pMdl = IoAllocateMdl (Data,
                          nNumberOfBytesToStream,
                          FALSE,
                          FALSE,
                          NULL);

    if (!pMdl) {

        TRACE(TL_ERROR, ("Failed to allocate pMdl!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_AsyncStream;
    }

    MmBuildMdlForNonPagedPool(pMdl);

    pIrb->u.AsyncStream.Mdl = pMdl;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_AsyncStream:

    if (pMdl)
    {
        IoFreeMdl(pMdl);
    }

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_AsyncStream", ntStatus);
    return(ntStatus);
} // t1394_AsyncStream




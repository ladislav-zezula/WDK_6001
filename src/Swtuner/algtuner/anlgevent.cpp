//==========================================================================;
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
//  PURPOSE.
//
//  Copyright (c) Microsoft Corporation.  All Rights Reserved.
//
//==========================================================================;
/**************************************************************************
    File    : anlgevent.cpp 
    Abstract: Contains devent handling mechanisms and worker/system thread implemntations.
**************************************************************************/

//#include "anlgevent.h"

#include "common.h"
PEventHandlerData EventHandler;

VOID TunerScanWorkItem(IN PDEVICE_OBJECT DeviceObject,IN PVOID Context);
VOID ScanThread(IN PVOID Context);
VOID StopPollingThread();
void TimerDpcInterrupt(IN PKDPC Dpc, IN PEventHandlerData EventBlock,IN PVOID SystemArg1,IN PVOID SystemArg2);

PCWSTR REGISTRYPATH = L"\\Registry\\Machine\\System\\AnlgSWTuner\\Device Parameters\\";
PCWSTR MpegFileName= L"\\??\\C:\\mpeg\\rio.mpg";

DWORD DetermineIfFineTuning(IN DWORD dwFreq)
{
    return FALSE;
}

DWORD 
GetDefaultStreamLocation(OUT PUNICODE_STRING FileName)
{
    // 1) Convert dword frequency to string.
    // 2) find matching key in registry
    // 3) read StreamLocation value from registry.
    // 4) pass key back to caller.
    
    NTSTATUS Status = STATUS_SUCCESS;

    UNICODE_STRING DefaultStreamKeyName;
    RtlInitUnicodeString(&DefaultStreamKeyName,REGISTRYPATH);

    UNICODE_STRING StreamLocation;
    RtlZeroMemory(&StreamLocation, sizeof(StreamLocation));
    
    Status = PptRegGetSz(RTL_REGISTRY_ABSOLUTE, 
                        DefaultStreamKeyName.Buffer,
                        L"DefaultStreamLocation", 
                        &StreamLocation);
    if (!NT_SUCCESS(Status))
    {
//        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
        // There was an error, use the default filename.
        RtlInitUnicodeString(&StreamLocation, MpegFileName);        
        Status = STATUS_SUCCESS;
    }
//    DbgPrint("Stream Location %S\n", StreamLocation.Buffer);

    if(StreamLocation.Length)
      RtlInitUnicodeString(FileName, StreamLocation.Buffer);
    else
      RtlInitUnicodeString(FileName, MpegFileName);
    return Status;
}

DWORD 
GetStreamLocationFromFrequency(IN CEncoderDevice* EncDevice, IN DWORD dwFreq, OUT PUNICODE_STRING FileName)
{
    // 1) Convert dword frequency to string.
    // 2) find matching key in registry
    // 3) read StreamLocation value from registry.
    // 4) pass key back to caller.
    
    NTSTATUS Status = STATUS_SUCCESS;
    UNICODE_STRING KeyName;
    KeyName.Buffer = (LPWSTR)ExAllocatePoolWithTag(NonPagedPool,
                                              MAX_PATH+1, 
                                              MS_SAMPLE_ANALOG_POOL_TAG
                                              );
    KeyName.Length = MAX_PATH;
    KeyName.MaximumLength = MAX_PATH;

    UNICODE_STRING StubName;
    RtlInitUnicodeString(&StubName,REGISTRYPATH);

    RtlCopyUnicodeString(&KeyName,&StubName);

    UNICODE_STRING Freq;
    Freq.Buffer = (LPWSTR)ExAllocatePoolWithTag(NonPagedPool,
                                              MAX_PATH+1, 
                                              MS_SAMPLE_ANALOG_POOL_TAG
                                              );
    Freq.Length = MAX_PATH;
    Freq.MaximumLength = MAX_PATH;
    
    RtlZeroMemory(Freq.Buffer,  MAX_PATH+1);
    RtlIntegerToUnicodeString(dwFreq, 10, &Freq);

//    DbgPrint("Converted Frequency value %S\n", Freq.Buffer);

    RtlAppendUnicodeStringToString(&KeyName, &Freq);

//    DbgPrint("KeyName %S\n", KeyName.Buffer);


//    UNICODE_STRING StreamLocation;
    RtlZeroMemory(&(EncDevice->StreamLocation), sizeof(EncDevice->StreamLocation));
    
    Status = PptRegGetSz(RTL_REGISTRY_ABSOLUTE, 
                        KeyName.Buffer,
                        L"StreamLocation", 
                        &(EncDevice->StreamLocation));
    if (!NT_SUCCESS(Status))
    {
//        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
        DetermineIfFineTuning(dwFreq);
        return Status;
    }
//    DbgPrint("Stream Location %S\n", EncDevice->StreamLocation.Buffer);
    RtlInitUnicodeString(FileName, EncDevice->StreamLocation.Buffer);
    return Status;
}

void TimerDpcInterrupt(IN PKDPC Dpc, IN PEventHandlerData EventBlock,IN PVOID SystemArg1,IN PVOID SystemArg2)
{
    NTSTATUS Status;;
    if (!EventBlock->bStopScan) {
//      CEncoderDevice* EncDevice = EventBlock->pDevice;
        //
        // Reschedule the timer for the next interrupt time.
        //
        if(EventBlock->CurrentFrequency <= EventBlock->ScanData.EndFrequency)
        {
/*          Status = GetStreamLocationFromFrequency(EncDevice, EventBlock->CurrentFrequency, &EncDevice->FileName);
            if(Status == STATUS_SUCCESS)        
            {*/
                KeSetEvent(&(EventBlock->InitEvent), 0,FALSE);
//          }
/*          else
            {
                KeAcquireSpinLockAtDpcLevel(&(EventHandler->LockAccess));
                EventBlock->CurrentFrequency +=  EncDevice->ScanSensingRange;
                KeReleaseSpinLockFromDpcLevel(&(EventHandler->LockAccess));
                LARGE_INTEGER NextTime;
                NextTime.QuadPart = EventBlock->IdleTimeout.QuadPart;
                KeSetTimerEx(&(EventBlock->timer), NextTime, NULL, &(EventBlock->DPCObject));
            }*/
        }
        else
        {
            KeAcquireSpinLockAtDpcLevel(&(EventHandler->LockAccess));
            EventBlock->bStopScan = TRUE;
            EventBlock->CurrentFrequency = EventBlock->ScanData.EndFrequency;
            KeReleaseSpinLockFromDpcLevel(&(EventHandler->LockAccess));
            KeSetEvent(&(EventBlock->ThreadEvent), 0,FALSE);            
        }
        
    } else {
        //
        // If someone is waiting on the hardware to stop, raise the stop
        // event and clear the flag.
        //
        KeAcquireSpinLockAtDpcLevel(&(EventHandler->LockAccess));
        EventBlock->CurrentFrequency = EventBlock->ScanData.EndFrequency;
        KeReleaseSpinLockFromDpcLevel(&(EventHandler->LockAccess));
        KeSetEvent(&(EventBlock->ThreadEvent), 0,FALSE);
    }
}

NTSTATUS InitializeEventing(CEncoderDevice* pEncDevice)
{
    //  First, allocate buffers
    NTSTATUS ntStatus = STATUS_SUCCESS;
    if(!EventHandler)
    {
        EventHandler = (PEventHandlerData)ExAllocatePoolWithTag(NonPagedPool,
            sizeof(EventHandlerData), MS_SAMPLE_ANALOG_POOL_TAG);
            if (!EventHandler) {
                ntStatus = STATUS_UNSUCCESSFUL;
                return ntStatus;
            }
            pEncDevice->EventData = reinterpret_cast<PVOID>(EventHandler);
            KeInitializeEvent(&(EventHandler->InitEvent),
                        SynchronizationEvent,
                        FALSE);

            KeInitializeEvent(&(EventHandler->TuneEvent),
                        SynchronizationEvent,
                        FALSE);

            KeInitializeEvent(&(EventHandler->ThreadEvent),
                        SynchronizationEvent,
                        FALSE);
            KeInitializeSpinLock(&(EventHandler->LockAccess));
            KeInitializeDpc (&(EventHandler->DPCObject), reinterpret_cast <PKDEFERRED_ROUTINE>(TimerDpcInterrupt), EventHandler);
            KeInitializeTimerEx(&(EventHandler->timer), SynchronizationTimer);
    }
    KeClearEvent(&(EventHandler->InitEvent));
    KeClearEvent(&(EventHandler->TuneEvent));
    KeClearEvent(&(EventHandler->ThreadEvent));
    return ntStatus;
}

NTSTATUS 
AnlgTunerScanAddEvent(
    PIRP pIrp,
    PKSEVENTDATA EventData,
    PKSEVENT_ENTRY pEventEntry
)
{
    KIRQL OldIrql;
    NTSTATUS ntStatus = STATUS_SUCCESS, Status = STATUS_SUCCESS;
    PKSEVENT_TUNER_INITIATE_SCAN_S ScanRequest = reinterpret_cast<PKSEVENT_TUNER_INITIATE_SCAN_S>(EventData);
    PEventHandlerData EventBlock;

    ASSERT(pIrp);
    PKSFILTER pFilter = KsGetFilterFromIrp(pIrp);
    PKSDEVICE pDevice = KsFilterGetDevice(pFilter);

    CEncoderDevice* pEncDevice = reinterpret_cast<CEncoderDevice *>(pDevice->Context);
    if(ScanRequest -> StartFrequency == ScanRequest -> EndFrequency )
    {
        if(pEncDevice->ScanInitialization)
        {
            ntStatus = STATUS_UNSUCCESSFUL;
            goto error;
        }
        // go ahead and tune to the frequency;
        ntStatus = InitializeEventing(pEncDevice);
        if (!NT_SUCCESS(ntStatus))
              goto error;
        EventBlock = EventHandler;

        ntStatus = GetStreamLocationFromFrequency(pEncDevice, ScanRequest -> StartFrequency, &pEncDevice->FileName);
        if(ntStatus != STATUS_SUCCESS)                // Found the frequency in the registry...so Just tune to it.
        {
            ULONG dwFreq = ( ScanRequest -> StartFrequency / (1000 * 1000) ); // fine tune algorithm ..
            dwFreq *= 1000000;

            ntStatus = GetStreamLocationFromFrequency(pEncDevice, dwFreq, &pEncDevice->FileName);
            if(ntStatus != STATUS_SUCCESS)
            {
                pEncDevice->LockedFrequency = 0;
                EventBlock->CurrentFrequency = ScanRequest -> StartFrequency;
                EventBlock->StatusCode = Tuner_LockType_None;
                KsGenerateEvent(pEventEntry);
                ntStatus = STATUS_SUCCESS;
                goto error;
            }
        }
        KeClearEvent(&(EventBlock->TuneEvent));
        EventBlock->IdleTimeout.QuadPart = pEncDevice->SettlingTime / 2;
        EventBlock->IdleTimeout.QuadPart = EventBlock->IdleTimeout.QuadPart * 1000 * 10; // in 100 nanasecond units

        KeWaitForSingleObject(&(EventBlock->TuneEvent),
                                             Executive,
                                             KernelMode,
                                             FALSE,
                                             &(EventBlock->IdleTimeout));     // in 100 nano second units
         
        pEncDevice->LockedFrequency = EventBlock->CurrentFrequency = ScanRequest -> StartFrequency;
        pEncDevice->SetFrequency(pEncDevice->LockedFrequency);

        EventBlock->StatusCode = Tuner_LockType_Locked;
        KsGenerateEvent(pEventEntry);
        ntStatus = STATUS_SUCCESS;
        goto error;

    }
    else
    {
        if (pEncDevice->pScanEvent)
        {
                // only one scan operation allowed on a tuner at a time
                if(EventHandler->ScanData.EventData.EventHandle.Event != ScanRequest->EventData.EventHandle.Event)
                {
                    ntStatus = STATUS_UNSUCCESSFUL;
                    goto error;
                }
                else
                {
                    if(pEncDevice->ScanInitialization)
                    {
                        KeAcquireSpinLock(&pEncDevice->EventHandlerSpinLock, &OldIrql);

                        pEncDevice->pScanEvent = pEventEntry;
                        EventHandler->EventEntry = pEventEntry; // Need to remove one of the references here.
                        memcpy(&(EventHandler->ScanData),ScanRequest, sizeof(KSEVENT_TUNER_INITIATE_SCAN_S));
                        EventHandler->CurrentFrequency = ScanRequest->StartFrequency;
                        EventHandler->StatusCode = Tuner_LockType_None;
                        KeReleaseSpinLock(&pEncDevice->EventHandlerSpinLock, OldIrql);

                        KeSetTimerEx (&(EventHandler->timer), EventHandler->IdleTimeout, NULL, &(EventHandler->DPCObject));
                        ntStatus = STATUS_SUCCESS;
                        goto error;
                    }
                }
        }
        else
        {
                KeAcquireSpinLock(&pEncDevice->EventHandlerSpinLock, &OldIrql);
                pEncDevice->pScanEvent = pEventEntry;
                KeReleaseSpinLock(&pEncDevice->EventHandlerSpinLock, OldIrql);
        }
        if (!NT_SUCCESS(ntStatus)) goto error;
        {
                        // use a separate thread to do the actual scan.
                PEventHandlerData EventBlock;
                NTSTATUS     WaitStatus;

                ntStatus = InitializeEventing(pEncDevice);
                if (!NT_SUCCESS(ntStatus))
                    goto error;

                EventBlock = EventHandler;

                KeAcquireSpinLock(&(EventBlock->LockAccess), &OldIrql);
                memcpy(&(EventBlock->ScanData),ScanRequest, sizeof(KSEVENT_TUNER_INITIATE_SCAN_S));
                EventHandler->CurrentFrequency = ScanRequest->StartFrequency;
                if(EventBlock->ScanData.EndFrequency < EventBlock->ScanData.StartFrequency)
                {
                    ULONG temp;
                    temp = EventBlock->ScanData.EndFrequency;
                    EventBlock->ScanData.EndFrequency= EventBlock->ScanData.StartFrequency;
                    EventBlock->ScanData.StartFrequency = temp;
                }
                pEncDevice->FreqRange = ScanRequest->EndFrequency - ScanRequest->StartFrequency;
                EventBlock->EventEntry = pEventEntry;
                EventBlock->IdleTimeout.QuadPart = pEncDevice->SettlingTime;
                EventBlock->IdleTimeout.QuadPart = EventBlock->IdleTimeout.QuadPart * (pEncDevice->FreqRange/pEncDevice->ScanSensingRange) * 1000 * 10; // in 100 nanasecond units
                EventBlock->bStopScan = FALSE;
                EventBlock->pDevice = pEncDevice;
                EventBlock->StatusCode = Tuner_LockType_None;
                pEncDevice->LockedFrequency = 0;
                KeReleaseSpinLock(&(EventBlock->LockAccess), OldIrql);

                // worker thread item for reads
                EventBlock->ThreadItem=IoAllocateWorkItem(pDevice->PhysicalDeviceObject);

                IoQueueWorkItem(EventBlock->ThreadItem,
                    TunerScanWorkItem,
                    CriticalWorkQueue,
                    EventBlock);

                pEncDevice->ScanInitialization = TRUE;

                WaitStatus = KeWaitForSingleObject(&(EventBlock->InitEvent),
                    Executive,
                    KernelMode,
                    FALSE,
                    NULL);

                if (!NT_SUCCESS(WaitStatus)) {
                    ntStatus = STATUS_UNSUCCESSFUL;
                    goto error;
                }
                KeClearEvent(&(EventBlock->InitEvent));
        }
    }
    // remove handler wont be called for this particular pEventEntry
    // till KsDefaultAddEventHandler returns. So pEventEntry is "safe"
    ntStatus = KsDefaultAddEventHandler(pIrp, reinterpret_cast<PKSEVENTDATA>(ScanRequest), pEventEntry);

error:
    pIrp->IoStatus.Status = ntStatus;
    return ntStatus;
}

VOID 
AnlgTunerScanRemoveEvent(
  PFILE_OBJECT  FileObject,
  struct _KSEVENT_ENTRY*  EventEntry
)
{
    KIRQL OldIrql;
    CEncoderFilter *pFilter;
    CEncoderDevice* pEncDevice = NULL;

    PKSFILTER Filter = KsGetFilterFromFileObject(FileObject);
    ASSERT(Filter);
    if (!Filter) return;
    ASSERT(EventEntry);

    PKSDEVICE pDevice = KsFilterGetDevice(Filter);
    pEncDevice = reinterpret_cast<CEncoderDevice *>(pDevice->Context);

    KeAcquireSpinLock(&pEncDevice->EventHandlerSpinLock, &OldIrql);

    if(pEncDevice->ScanInitialization)
        RemoveEntryList(&EventEntry->ListEntry);
    if (pEncDevice->pScanEvent) 
    {
        pEncDevice->pScanEvent = NULL;
        IoFreeWorkItem(EventHandler->ThreadItem); // Release Work Item
        EventHandler->EventEntry = NULL;
        ExFreePool(EventHandler);
        pEncDevice->EventData = EventHandler = NULL;
        pEncDevice->ScanInitialization = FALSE;
    }
    KeReleaseSpinLock(&pEncDevice->EventHandlerSpinLock, OldIrql);
    return;

}

VOID TunerScanWorkItem(IN PDEVICE_OBJECT DeviceObject,IN PVOID Context)
{
    DbgPrint( "TunerScanWorkItem\n");

   OBJECT_ATTRIBUTES FileObject;
   UNICODE_STRING    FileName; 
   NTSTATUS          Status;
   BOOL              FirstPass=TRUE;
   KIRQL             SpinIrql;
   HANDLE           handle;
   NTSTATUS          WaitStatus;

   PEventHandlerData EventBlock= static_cast<PEventHandlerData>( Context);

   OBJECT_ATTRIBUTES oa;
   InitializeObjectAttributes(&oa, NULL, OBJ_KERNEL_HANDLE, NULL, NULL);

   Status = PsCreateSystemThread(&handle, THREAD_ALL_ACCESS, &oa, NULL, NULL,
                                 ScanThread, EventBlock);

   Status = ObReferenceObjectByHandle(handle, THREAD_ALL_ACCESS, NULL,
        KernelMode, (PVOID*) &EventBlock->thread, NULL);

   Status = KeSetEvent(&(EventBlock->InitEvent), 0,FALSE);
   ZwClose(handle);
   do
   {
        WaitStatus = KeWaitForSingleObject(&(EventBlock->TuneEvent),
            Executive,
            KernelMode,
            FALSE,
            NULL);
        if (!NT_SUCCESS(WaitStatus)) {
            Status = STATUS_UNSUCCESSFUL;
            break;
        }
        if(EventBlock->bStopScan)
        {
            KsGenerateEvent(EventBlock->EventEntry);
            StopPollingThread();
            break;
        }
        CEncoderDevice* EncDevice = EventBlock->pDevice;
        if(EventBlock->StatusCode == Tuner_LockType_None)
        {
            EncDevice->LockedFrequency = 0;
        }
        if(EventBlock->StatusCode == Tuner_LockType_Locked)
        {
            EncDevice->LockedFrequency = EventBlock->CurrentFrequency;
        }
        KeClearEvent(&(EventBlock->TuneEvent));
        DbgPrint( "TunerScanWorkItem : Firing an event from driver to the app\n");
        KsGenerateEvent(EventBlock->EventEntry);
   }while(1);
}

VOID
ScanThread(
    IN PVOID Context
    )
{
    PEventHandlerData EventBlock = static_cast<PEventHandlerData>( Context);
    LARGE_INTEGER   Timeout;
    PIRP            CurrentIrp;
    NTSTATUS        WaitStatus, Status;
    PVOID           eventArray[2];
    KIRQL           OldIrql;
    CEncoderDevice* EncDevice = EventBlock->pDevice;

    eventArray[0] = &(EventBlock->InitEvent);
    eventArray[1] = &(EventBlock->ThreadEvent);

    Timeout.QuadPart = EventBlock->IdleTimeout.QuadPart;
    KeSetTimerEx (&(EventBlock->timer), Timeout,NULL, &(EventBlock->DPCObject));
    do
    {
        WaitStatus = KeWaitForMultipleObjects( 2, 
                                               eventArray,
                                               WaitAny,
                                               Executive,
                                               KernelMode,
                                               FALSE, 
                                               NULL,
                                               NULL);
        if(WaitStatus == STATUS_TIMEOUT )
        {
            KeAcquireSpinLock(&(EventBlock->LockAccess), &OldIrql);
            EventBlock->StatusCode = Tuner_LockType_None;
            KeReleaseSpinLock(&(EventBlock->LockAccess), OldIrql);
            Status = KeSetEvent(&(EventBlock->TuneEvent), 0,FALSE);
            continue;
        }
        else if(WaitStatus == STATUS_WAIT_0 )
        {
            Status = GetStreamLocationFromFrequency(EncDevice, EventBlock->CurrentFrequency, &EncDevice->FileName);
            KeClearEvent((PKEVENT)eventArray[0]);
            if(Status == STATUS_SUCCESS)        
            {
                KeAcquireSpinLock(&(EventBlock->LockAccess), &OldIrql);
                EventBlock->StatusCode = Tuner_LockType_Locked;
                KeReleaseSpinLock(&(EventBlock->LockAccess), OldIrql);
                Status = KeSetEvent(&(EventBlock->TuneEvent), 0,FALSE);  
            }
            else
            {
                KeAcquireSpinLock(&(EventBlock->LockAccess), &OldIrql);
                EventBlock->CurrentFrequency +=  EncDevice->ScanSensingRange;
                KeReleaseSpinLock(&(EventBlock->LockAccess), OldIrql);
                LARGE_INTEGER NextTime;
                NextTime.QuadPart = EventBlock->IdleTimeout.QuadPart;
                KeSetTimerEx(&(EventBlock->timer), NextTime, NULL, &(EventBlock->DPCObject));
            }
            continue;
        }
        else if(WaitStatus == STATUS_WAIT_1)
        {
            KeAcquireSpinLock(&(EventBlock->LockAccess), &OldIrql);
            EventBlock->StatusCode = Tuner_LockType_None;
            KeReleaseSpinLock(&(EventBlock->LockAccess), OldIrql);
            KeClearEvent((PKEVENT)eventArray[1]);
            Status = KeSetEvent(&(EventBlock->TuneEvent), 0,FALSE);  
            PsTerminateSystemThread(STATUS_SUCCESS);
        }
    }while(1);
}

VOID StopPollingThread()
{                           
  KIRQL OldIrql;
  if(EventHandler)      // need to check..it is possible and seen that this gets called even after the cleanup is done and RemoveEvent has been called.
  {
    if(EventHandler->thread)
    {
       KeSetEvent(&EventHandler->ThreadEvent, 0, FALSE);
       KeWaitForSingleObject(EventHandler->thread, Executive, KernelMode, FALSE, NULL);
       ObDereferenceObject(EventHandler->thread);
       EventHandler->thread = NULL;
    }
  }
}

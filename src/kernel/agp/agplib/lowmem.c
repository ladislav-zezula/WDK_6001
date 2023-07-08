/*++

Copyright (c) 2004  Microsoft Corporation

Module Name:

    lowmem.c

Abstract:

    Utility code to help debug low memory corruption issue encounter
    during R200 LDDM driver development.


--*/
#include "agplib.h"

#define AGPLOWMEM_BUFFER_SIZE       0x4000
#define AGPLOWMEM_BARRIER           0x100000

#define AGPLOWMEM_PATTERN           0x3BADCAFE

static BOOLEAN gLowMemTestingEnabled = FALSE;
static PVOID gLowMemBuffer = NULL;
static PVOID gNextCheckedPages = NULL;
static HANDLE gAgpLowMemThreadHandle = NULL;
static PKTHREAD gAgpLowMemWorkerThread = NULL;
static KEVENT gAgpLowMemTerminateEvent;

VOID
AgpLowMemWorker(
    IN PVOID Unused
    );

VOID
AgpLowMemInit(
    )
{
    ULONG i;
    PULONG Tmp;
    PHYSICAL_ADDRESS MaximumAddress;
    OBJECT_ATTRIBUTES ObjectAttributes;
    KEVENT InitializationDoneEvent;
    NTSTATUS Status;

    //
    // Try to allocate 16KB of memory below 4MB.
    //

    MaximumAddress.QuadPart = AGPLOWMEM_BARRIER;
    gLowMemBuffer = MmAllocateContiguousMemory(AGPLOWMEM_BUFFER_SIZE, 
                                               MaximumAddress);

    if (NULL == gLowMemBuffer) 
    {
        return;
    }

    //
    // Fill the memory with our pattern.
    //

    Tmp = gLowMemBuffer;
    for (i=0; i<AGPLOWMEM_BUFFER_SIZE/sizeof(ULONG); i++) 
    {
        Tmp[i] = AGPLOWMEM_PATTERN;
    }

    //
    // Initialize an event use to terminate the worker thread.
    //

    KeInitializeEvent(&gAgpLowMemTerminateEvent,
                      SynchronizationEvent,
                      FALSE);

    //
    // Initialize an event use by the worker thread to signal it's completed
    // it's initialization.
    //

    KeInitializeEvent(&InitializationDoneEvent,
                      SynchronizationEvent,
                      FALSE);

    //
    // Create Worker thread.
    //

    InitializeObjectAttributes(&ObjectAttributes, NULL, OBJ_KERNEL_HANDLE, NULL, NULL);

    //
    // Start a worker thread to check the low memory.
    //

    Status = PsCreateSystemThread(
                  &gAgpLowMemThreadHandle,
                  THREAD_ALL_ACCESS,
                  &ObjectAttributes,
                  NULL,
                  NULL,
                  AgpLowMemWorker,
                  (PVOID)&InitializationDoneEvent);
    if (!NT_SUCCESS(Status))
    {
        MmFreeContiguousMemory(gLowMemBuffer);
        gLowMemBuffer = NULL;
        return;
    }

    //
    // Wait for the worker thread to complete it's initialization.
    //

    KeWaitForSingleObject(&InitializationDoneEvent,
                          Executive,
                          KernelMode,
                          FALSE,
                          NULL);

    //
    // Reference the worker thread so the object doesn't go away
    // when the thread terminates.
    //

    ObReferenceObject(gAgpLowMemWorkerThread);

    //
    // We're ready to start testing for corruption.
    //

    gLowMemTestingEnabled = TRUE;
    gNextCheckedPages = gLowMemBuffer;
}   // AgpLowMemInit()

VOID
AgpLowMemTerminate(
    )
{
    //
    // If we haven't successfully initialized we have nothing to cleanup,
    // return immediately.
    //

    if (FALSE == gLowMemTestingEnabled) 
    {
        return;
    }

    //
    // Disable testing.
    //

    gLowMemTestingEnabled = FALSE;

    //
    // Signal to the worker thread that it should terminate.
    //

    KeSetEvent(&gAgpLowMemTerminateEvent, 0, FALSE);

    //
    // Wait on the worker thread to terminate.
    //

    KeWaitForSingleObject(gAgpLowMemWorkerThread,
                          Executive,
                          KernelMode,
                          FALSE,
                          NULL);

    //
    // Dereference the thread object so it can go away.
    //

    ObDereferenceObject(gAgpLowMemWorkerThread);

    //
    // Free our buffer.
    //

    MmFreeContiguousMemory(gLowMemBuffer);
    gLowMemBuffer = NULL;
}   // AgpLowMemWorker()

BOOLEAN
AgpLowMemCheckForCorruption(
    )
{
    ULONG i;
    PULONG Tmp;

    if (FALSE == gLowMemTestingEnabled) 
    {
        return FALSE;
    }

    Tmp = gLowMemBuffer;
    for (i=0; i<AGPLOWMEM_BUFFER_SIZE/sizeof(ULONG); i++)
    {
        if (Tmp[i] != AGPLOWMEM_PATTERN) 
        {
            DbgPrint("Agp low memory check detected corruption at offset %d.\n", i);
            return TRUE;
        }
    }

    return FALSE;
}   // AgpLogCheckForCorruption()

BOOLEAN
AgpLowMemCheckForCorruptionIncremental(
    )
{
    ULONG i;
    PULONG Tmp;

    if (FALSE == gLowMemTestingEnabled) 
    {
        return FALSE;
    }

    Tmp = gNextCheckedPages;
    for (i=0; i<PAGE_SIZE; i++) 
    {
        if (*Tmp != AGPLOWMEM_PATTERN) 
        {
            ASSERT((PVOID)&Tmp[i] < gLowMemBuffer);
            return TRUE;
        }
        
        Tmp++;
    }

    gNextCheckedPages = Tmp;
    if ((char*)gNextCheckedPages >= ((char*)gLowMemBuffer + AGPLOWMEM_BUFFER_SIZE)) 
    {
        gNextCheckedPages = gLowMemBuffer;
    }

    return FALSE;
}   // AgpLowMemCheckForCorruptionIncremental()

VOID
AgpLowMemWorker(
    IN PVOID Param
    )
{
    BOOLEAN CorruptionDetected;
    LARGE_INTEGER Timeout;
    PKEVENT InitializationDoneEvent = (PKEVENT)Param;

    Timeout.QuadPart = -20000000;

    //
    // Save our thread handle in a global variable.
    //

    gAgpLowMemWorkerThread = KeGetCurrentThread();

    //
    // Signal to the caller that we're done initializing.
    //

    KeSetEvent(InitializationDoneEvent, 0, FALSE);

    while (1) 
    {
        NTSTATUS Status;
            
        Status = KeWaitForSingleObject(&gAgpLowMemTerminateEvent,
                                       Executive,
                                       KernelMode,
                                       FALSE,
                                       &Timeout);

        switch (Status) 
        {
            case STATUS_TIMEOUT:
                CorruptionDetected = AgpLowMemCheckForCorruption();
                if (CorruptionDetected) 
                {
                    DbgPrint("");
                    DbgBreakPoint();
                }
                break;

            case STATUS_SUCCESS:
                
                //
                // Done.
                //

                return;

            default:
                break;
        }
    }
}   // AgpLowMemWorker()


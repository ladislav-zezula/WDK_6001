/*++

Copyright (c) 2005  Microsoft Corporation

Module Name:

    GuardRegion.c

Abstract:

    Code to impliment the AGP guard region that will check for AGP writes through
    unmapped gart pages


--*/

#include "agplib.h"

#ifdef ALLOC_PRAGMA
#pragma alloc_text(PAGE, AgpGuardRegionInit)
#pragma alloc_text(PAGE, AgpGuardRegionFree)
#endif

typedef struct
{
    struct
    {
        ULONG GuardRegionPageIdx : 28;
        ULONG Operation : 4;        
    };
    ULONG RegionSizeInPages;
    ULONG RegionPageOffsetFromGartBase;    
} GUARD_REGION_HISTORY, *PGUARD_REGION_HISTORY;

typedef struct
{
    ULONG   Idx;
    ULONG   WrapCount;
}WRAPPING_INDEX, *PWRAPPING_INDEX; 

#if AGP_GUARD_RANGE_UNMAP_HISTORY_SIZE
GUARD_REGION_HISTORY    g_GuardHistory[AGP_GUARD_RANGE_UNMAP_HISTORY_SIZE] = {0};
WRAPPING_INDEX          g_GuardHistoryIdx = {0};        // Index of next guard hostory slot to use
WRAPPING_INDEX          g_LastGuardRegionCheck = {0};   // Index into history buffer of the last time we check for corruption
PCHAR                   g_GartOpNames[] = {NULL, "Create", "Reserve", "Release", "UnMap", "Map"};
#endif

#if AGP_GUARD_RANGE_SIZE_IN_PAGES > 1 || AGP_GUARD_RANGE_UNMAP_HISTORY_SIZE
ULONG                   g_GuardPageIdx = 0;             // Page index into guard region to use next
#endif 

BOOLEAN
AgpGuardRegionInit(
   IN PTARGET_EXTENSION Extension)
{
    PHYSICAL_ADDRESS    HighAddr = { 0xFFFFFFFF, 0 };
    PHYSICAL_ADDRESS    LowAddr = { 0x100000, 0 };
    PHYSICAL_ADDRESS    BoundaryAddr = { 0, 0 };
    ULONG               Idx;
    PULONG              FillAddr;
        
    PAGED_CODE();

    //
    // Allocated guard page, make it write combined to speed up the fill that will occur during boot
    //
    Extension->AgpGuardPageVirtual = MmAllocateContiguousMemorySpecifyCache(PAGE_SIZE * AGP_GUARD_RANGE_SIZE_IN_PAGES,    
                                               LowAddr,
                                               HighAddr,
                                               BoundaryAddr,
                                               MmWriteCombined);
    if (Extension->AgpGuardPageVirtual == NULL)
    {
        AGPLOG(AGP_CRITICAL, ("AgpGuardRegionInit: Failed to allocated Gart guard page\n"));
        return FALSE;
    }
    Extension->AgpGuardPagePhys = MmGetPhysicalAddress(Extension->AgpGuardPageVirtual);

    //
    // Fill guard page with pattern
    //
    FillAddr = (ULONG*)Extension->AgpGuardPageVirtual;
    for (Idx = 0; Idx < ((PAGE_SIZE * AGP_GUARD_RANGE_SIZE_IN_PAGES) / sizeof(ULONG)); Idx++) 
    {
        *FillAddr++ = AGP_VERIFIER_SIGNATURE;
    }

    //
    // Flush WC buffer on CPU
    //
    Idx = *(volatile ULONG *)Extension->AgpGuardPageVirtual;

    return TRUE;
}


void
AgpGuardRegionFree(
   IN PTARGET_EXTENSION Extension)
{
    PAGED_CODE();

    if (Extension->AgpGuardPageVirtual != NULL)
    {
        MmFreeContiguousMemorySpecifyCache(Extension->AgpGuardPageVirtual, PAGE_SIZE * AGP_GUARD_RANGE_SIZE_IN_PAGES, MmWriteCombined);
        Extension->AgpGuardPageVirtual = NULL;
    }

    return;
}

NTSTATUS
AgpGuardRegionCheck(
    IN PTARGET_EXTENSION Extension,
    IN ULONG Flags,
    IN ULONG ULongsToCheck)
{
    ULONG   Index;
    ULONG   CheckInc;
    PULONG  AgpVerifierPageOffset;
    NTSTATUS Status = STATUS_SUCCESS;
    static ULONG StartIdxOffset = 0;

    AgpVerifierPageOffset = (PULONG)Extension->AgpGuardPageVirtual;

    if (Flags & AGP_GUARD_PAGE_CHECK_USE_SAME_OFFSET)
    {
        if (++StartIdxOffset == AGP_GUARD_RANGE_SIZE_IN_PAGES)
        {
            StartIdxOffset = 0;
        }
    }

    if (ULongsToCheck == 0)
    {
        StartIdxOffset = 0;    
        CheckInc = 1;
    }
    else if (Flags & AGP_GUARD_PAGE_CHECK_FIRST_ULONG)
    {
        StartIdxOffset = 0;    
        CheckInc = PAGE_SIZE / sizeof(ULONG);
    }
    else
    {
        CheckInc = (((AGP_GUARD_RANGE_SIZE_IN_PAGES * PAGE_SIZE) / sizeof(ULONG))) / ULongsToCheck;
    }

    AgpVerifierPageOffset += StartIdxOffset;

    //
    // Bugcheck if there's any corruption in our verifier page
    //
    while (AgpVerifierPageOffset < (PULONG)Extension->AgpGuardPageVirtual + (AGP_GUARD_RANGE_SIZE_IN_PAGES * PAGE_SIZE) / sizeof(ULONG))
    {       
        if (*AgpVerifierPageOffset != AGP_VERIFIER_SIGNATURE) 
        {            
            AGPLOG(AGP_CRITICAL, ("AgpVerify: Gart corruption "
                                  "detected at %p\n",
                                  AgpVerifierPageOffset));

            Status = STATUS_BUFFER_OVERFLOW;

            if (!(Flags & AGP_GUARD_PAGE_CHECK_DO_NOT_BUGCHECK))
            {        
#if DBG
                ASSERT(0);
#elif (WINVER > 0x501)
                KeBugCheckEx(AGP_INVALID_ACCESS,
                             (ULONG_PTR)(AgpVerifierPageOffset),
                             0,
                             0,
                             0);
#endif
            }
        }
        AgpVerifierPageOffset+=CheckInc;        
    }

#if AGP_GUARD_RANGE_UNMAP_HISTORY_SIZE
    //
    // Remeber when in history buffer we last checked for corruption and did not find any
    //
    g_LastGuardRegionCheck = g_GuardHistoryIdx;
#endif

    return Status;
}

#if (AGP_GUARD_RANGE_SIZE_IN_PAGES > 1) || AGP_GUARD_RANGE_UNMAP_HISTORY_SIZE
PHYSICAL_ADDRESS
AgpLibGuardRegionGetGuardPageAddr(
    IN PVOID AgpExtension,
    IN ULONG StartPageoffset,
    IN ULONG NumPages,
    IN GUARD_REGION_OPERATION Op
    )
{
    PTARGET_EXTENSION   Extension;
    PHYSICAL_ADDRESS    GuardPageAddr;
    
    GET_TARGET_EXTENSION(Extension, AgpExtension);

#if AGP_GUARD_RANGE_UNMAP_HISTORY_SIZE
    //
    // First store the info in the hostory buffer
    //
    g_GuardHistory[g_GuardHistoryIdx.Idx].Operation = Op;
    g_GuardHistory[g_GuardHistoryIdx.Idx].GuardRegionPageIdx = g_GuardPageIdx;
    g_GuardHistory[g_GuardHistoryIdx.Idx].RegionPageOffsetFromGartBase = StartPageoffset;
    g_GuardHistory[g_GuardHistoryIdx.Idx].RegionSizeInPages = NumPages;

    //
    // Move history and page index to next free slot
    //
    g_GuardHistoryIdx.Idx++;
    if (g_GuardHistoryIdx.Idx >= AGP_GUARD_RANGE_UNMAP_HISTORY_SIZE)
    {
        g_GuardHistoryIdx.Idx = 0;
        g_GuardHistoryIdx.WrapCount++;
    }    
#endif    

    //
    // We just want to record the mapping operations and not return the addr of the next guard page
    //
    if (Op == GART_OP_MAP)
    {        
        GuardPageAddr.QuadPart = 0L;
        return GuardPageAddr;
    }

#if AGP_GUARD_RANGE_SIZE_IN_PAGES > 1
    //
    // Calc the guard page addr for the caller to map
    //
    GuardPageAddr.QuadPart = Extension->AgpGuardPagePhys.QuadPart + (g_GuardPageIdx * PAGE_SIZE);

    g_GuardPageIdx++;
    if (g_GuardPageIdx >= AGP_GUARD_RANGE_SIZE_IN_PAGES)
    {
        g_GuardPageIdx = 0;
    }
#else
    GuardPageAddr.QuadPart = Extension->AgpGuardPagePhys.QuadPart;            
#endif    

    return GuardPageAddr;
}

#endif


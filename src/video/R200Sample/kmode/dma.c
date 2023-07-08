/*****************************************************************************\
* 
*  Module Name    DMA.C
*  Project        Longhorn
*  Device         R200
*
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
\*****************************************************************************/


#include "ntddk.h"
#include "rage.h"
#include "dma.h"
#include "dderror.h"

#include <ntintsafe.h>

VOID
vAsicFlushPciGartCache (
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

//
// Allow swapping.
//
#if defined (ALLOC_PRAGMA)
#pragma alloc_text(PAGE_COM, GetPageSize)
#pragma alloc_text(PAGE_COM, InitializeSgtInfo)
#pragma alloc_text(PAGE_COM, AllocateContiguousMemory)
#pragma alloc_text(PAGE_COM, FreeContiguousMemory)
#pragma alloc_text(PAGE_COM, AllocatePool)
#pragma alloc_text(PAGE_COM, DoesSgtHaveRoom)
#pragma alloc_text(PAGE_COM, MapToSgt)
#pragma alloc_text(PAGE_COM, UnmapFromSgt)

#pragma alloc_text(PAGE_COM, FreePool)
#pragma alloc_text(PAGE_COM, GetPhysicalAddress)
#pragma alloc_text(PAGE_COM, ShareDmaMem)
#pragma alloc_text(PAGE_COM, UnshareDmaMem)
#pragma alloc_text(PAGE_COM, AddPhysicalAddress)
#endif  // ALLOC_PRAGMA

const DWORD COMMON_ALLOC_ADJUSTMENT = ((sizeof(COMMON_ALLOC) + POOL_ALIGNMENT - 1) & ~(POOL_ALIGNMENT - 1));

extern NTSTATUS
ZwQueryInformationProcess (
    IN HANDLE           ProcessHandle,
    IN PROCESSINFOCLASS ProcessInformationClass,
    OUT PVOID           ProcessInformation,
    IN ULONG            ProcessInformationLength,
    OUT PULONG          ReturnLength OPTIONAL
);

HANDLE
ATIGetProcessID_ZwMethod(HANDLE  hProcess)
{
    HANDLE                      hProcessID = (HANDLE)0;
    PROCESS_BASIC_INFORMATION   sProcessInfo;
    PROCESSINFOCLASS            enumProcessInfo = ProcessBasicInformation;
    DWORD                       dwBytesReturned;
    NTSTATUS                    status;

    status = ZwQueryInformationProcess(
                                hProcess,
                                enumProcessInfo,
                                &sProcessInfo,
                                sizeof (PROCESS_BASIC_INFORMATION),
                                &dwBytesReturned);

    ASSERT(status==STATUS_SUCCESS);

    if (status == STATUS_SUCCESS)
    {
        hProcessID = (HANDLE)sProcessInfo.UniqueProcessId;
    }
    return hProcessID;
}

ULONG
GetPageSize(    
    VOID
    )
// RETURN VALUE:
//  ULONG size of operating systems memory pages
//
{
    PAGED_CODE();

    return(PAGE_SIZE);
}   // GetPageSize()


VOID
InitializeSgtInfo(
    __in  PHW_DEVICE_EXTENSION pHwDeviceExtension
    )
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//
// RETURN VALUE:
//  Base virtual address of the allocated range, otherwise NULL.
//
{
    PSGT_INFO   pSGTinfo;
    DWORD       dwMaxSizePCIGARTmemoryBytes;

    PAGED_CODE();

    ASSERT(NULL != pHwDeviceExtension);

    dwMaxSizePCIGARTmemoryBytes = 64 * ONE_MEG;

    pSGTinfo = &pHwDeviceExtension->pCommonBlock->sgtInfo;
    pSGTinfo->sgtPhysicalAddress.LowPart    = 0;
    pSGTinfo->sgtPhysicalAddress.HighPart   = 0;
    pSGTinfo->pvSgtBaseAddress              = NULL;
    pSGTinfo->ulTotalEntriesUsedByMHP       = 0;
    pSGTinfo->ulTotalEntriesInSGT           = 0;
    pSGTinfo->ulTotalSGTentriesUseableByMHP = 0;
    pSGTinfo->ulSGTsizeBytes                = 0;
    pSGTinfo->ulPhysicalAddressRangeSize    = dwMaxSizePCIGARTmemoryBytes;
    pSGTinfo->bAGPLargeApertureEnabled      = FALSE;
    pSGTinfo->bPCIGARTDMAEnabled            = FALSE;
    pSGTinfo->ulPCIGARTDMABase              = 0;
    pSGTinfo->ulPCIGARTDMASize              = 0;

}   // InitializeSgtInfo()

PVOID
AllocateContiguousMemory(
    PHW_DEVICE_EXTENSION    pHwDeviceExtension,
    ULONG                   ulPoolSize,
    PHYSICAL_ADDRESS        *pPhysAddr
    )
//
// DESCRIPTION:
//  Provides a virtual address to a contiguous chunk of memory.
//
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//  ulPoolSize          Amount of memory to allocate.
//
// RETURN VALUE:
//  Pointer to contiguous memory or NULL if there is not enough free pool space.
//
{
    PHYSICAL_ADDRESS    paPhysAddress;
    PVOID               pvLinearAddress;

    PCOMMON_ALLOC       pcaNode;

    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);


//    ulPoolSize += COMMON_ALLOC_ADJUSTMENT;

    if (!NT_SUCCESS(RtlULongAdd(ulPoolSize, COMMON_ALLOC_ADJUSTMENT, &ulPoolSize)))
    {
         ASSERT(0);
         return NULL;
    }

    pvLinearAddress = AllocateCommonBuffer(pHwDeviceExtension, ulPoolSize, &paPhysAddress, TRUE);
    ASSERT( ((DWORD_PTR)pvLinearAddress & (POOL_ALIGNMENT - 1)) == 0);
    if (NULL != pvLinearAddress)
    {
        pcaNode = (PCOMMON_ALLOC) pvLinearAddress;
        pcaNode->paPhysicalAddress = paPhysAddress;
        pcaNode->pvLinearAddress = pvLinearAddress;
        pcaNode->ulBlockSize = ulPoolSize;

        paPhysAddress.LowPart += COMMON_ALLOC_ADJUSTMENT;
        (UCHAR *)pvLinearAddress += COMMON_ALLOC_ADJUSTMENT;
    }

    if (pPhysAddr != NULL)
    {
        *pPhysAddr = paPhysAddress;
    }
    return pvLinearAddress;

}   // AllocateContiguousMemory()

VOID
FreeContiguousMemory(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID pVirtualAddress
    )
//
// DESCRIPTION;
//  Deallocates a block of contiguous memory.
//
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//
// RETURN VALUE:
//  NONE
//  
{
    PCOMMON_ALLOC   pcaNode;

    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);

    if (NULL == pVirtualAddress)
        return;

    pcaNode = (PCOMMON_ALLOC)((DWORD_PTR)pVirtualAddress - COMMON_ALLOC_ADJUSTMENT);
    
    FreeCommonBuffer(pHwDeviceExtension,
                     pcaNode->ulBlockSize,
                     pcaNode->paPhysicalAddress,
                     pcaNode->pvLinearAddress,
                     TRUE);
}   // FreeContiguousMemory()

PVOID
AllocatePool(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulPoolSize
    )
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//  ulPoolSize          Amount of memory to allocate.
//
// RETURN VALUE:
//  Pointer to allocated pool memory or NULL if there is not enough free pool space.
//
{
#if defined(FOUR_GB_FIX)
    PHYSICAL_ADDRESS paPhysAddress;
    PVOID pvLinearAddress;
    PCOMMON_ALLOC pcaNode;

    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);

    ulPoolSize += sizeof(COMMON_ALLOC);
    pvLinearAddress = AllocateCommonBuffer(pHwDeviceExtension, ulPoolSize, &paPhysAddress, TRUE);

    if (NULL != pvLinearAddress)
    {
        pcaNode = (PCOMMON_ALLOC) pvLinearAddress;
        pcaNode->paPhysicalAddress = paPhysAddress;
        pcaNode->pvLinearAddress = pvLinearAddress;
        pcaNode->ulBlockSize = ulPoolSize;

        pvLinearAddress = (PVOID) (pcaNode+1);
    }
    return pvLinearAddress;
#else
    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);

    return VpAllocatePool( pHwDeviceExtension, (ULONG)VP_NONPAGEDPOOL, ulPoolSize, 'RAGE');

#endif
}   // AllocatePool()

BOOL DoesSgtHaveRoom (PHW_DEVICE_EXTENSION  pHwDeviceExtension,
                      DWORD                 dwPoolSizeInBytes,
                      DWORD                 dwEntryOffset)

{
    BOOL       bSgtHasRoom = FALSE;
    DWORD      dwNumEntriesAvailable,
               dwNumEntriesRequired;
    PSGT_INFO  pSGTinfo;               

    PAGED_CODE();
    ASSERT ((dwPoolSizeInBytes % SGT_PAGE_SIZE) == 0);

    pSGTinfo              = &pHwDeviceExtension->pCommonBlock->sgtInfo;

    if(pSGTinfo->pvSgtBaseAddress != NULL)
    {
        dwNumEntriesRequired  = dwPoolSizeInBytes / SGT_PAGE_SIZE;
        
        {
            PULONG            pulSGT;                 
            ULONG             ulIncrement;           

            if((dwEntryOffset + dwNumEntriesRequired) <= pSGTinfo->ulTotalSGTentriesUseableByMHP)
            {
                pulSGT = (PULONG )pSGTinfo->pvSgtBaseAddress + dwEntryOffset;
                bSgtHasRoom = TRUE;

                for (ulIncrement = 0; ulIncrement < dwNumEntriesRequired; ulIncrement++)
                {
                    if(*pulSGT != 0)
                    {
                        bSgtHasRoom = FALSE;
                        break;
                    }
                    pulSGT++;
                } // loop through all the pages in this allocation
            }

        }
    }

    return bSgtHasRoom;

}

BOOL
MapToSgt(
    __in  PHW_DEVICE_EXTENSION  pHwDeviceExtension,
    __in  PMEMHEAP_POOL         pMHPpool,
    __in  DWORD                 dwEntryOffset
    )
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//  pVirtualAddress     Virtual address from which the MDL is to be created.
//  ulPoolSize          Amount of memory allocated to the virtual address.
//
// RETURN VALUE:
//  NONE.
//
{
    BOOL       bMapSuccessful;
    PSGT_INFO  pSGTinfo;               
    ULONG      ulPoolSize;
    ULONG      ulIncrement;            

    PAGED_CODE();
    ASSERT (NULL != pHwDeviceExtension);

    ulPoolSize = pMHPpool->dwMHP_TotalBytes;
    ASSERT ((ulPoolSize % SGT_PAGE_SIZE) == 0);

    bMapSuccessful = FALSE; // assume failure
    pSGTinfo       = &(pHwDeviceExtension->pCommonBlock->sgtInfo);
    if (DoesSgtHaveRoom (pHwDeviceExtension, ulPoolSize, dwEntryOffset))
    {
        PHYSICAL_ADDRESS  sgtPhysicalAddress;     
        PULONG            pulSGT;                 
        PVOID             pVirtualAddress;

        pulSGT = (PULONG )pSGTinfo->pvSgtBaseAddress + dwEntryOffset;

        bMapSuccessful  = TRUE;
        pVirtualAddress = pMHPpool->pvMHP_CPU_BaseAddr;
        for (ulIncrement = 0; bMapSuccessful && (ulIncrement < ulPoolSize); ulIncrement += SGT_PAGE_SIZE)
        {
            sgtPhysicalAddress = MmGetPhysicalAddress((PVOID)((PUCHAR)pVirtualAddress + ulIncrement));

            if (sgtPhysicalAddress.HighPart == 0)
            {
                *pulSGT++ = sgtPhysicalAddress.LowPart;
            }
            else
            {
                bMapSuccessful = FALSE;
            } // end check for a valid physical address
        } // loop through all the pages in this allocation
    } // end check for their being room...
    
    if (bMapSuccessful)
    {
        vAsicFlushPciGartCache (pHwDeviceExtension);

        ulIncrement = ulPoolSize / SGT_PAGE_SIZE;
        if (dwEntryOffset + ulIncrement > pSGTinfo->ulTotalEntriesUsedByMHP)
        {
            pSGTinfo->ulTotalEntriesUsedByMHP = dwEntryOffset + ulIncrement;
        }
    }

    return bMapSuccessful;
}


VOID
UnmapFromSgt(
    __in  PHW_DEVICE_EXTENSION  pHwDeviceExtension,
    __in  PMEMHEAP_POOL         pMHPpool
    )
// PARAMETERS
//  pHwDeviceExtension  Points to per-adapter device extension.
//  ulRemovePool        Free the actual pool (if TRUE).
//
// RETURN VALUE
//  NONE
//
{

    DWORD      dwNumEntries;
    PSGT_INFO  pSGTinfo;       // Pointer to the SGT information table.
    DWORD_PTR  dwEntryOffset;
    PULONG     pulSGT;                 // pointer inside the scatter gather table...
    ULONG      ulIncrement;            // Used to increment the value of the buffer address.

    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);
    ASSERT(NULL != pHwDeviceExtension->pCommonBlock);

    pSGTinfo     = &pHwDeviceExtension->pCommonBlock->sgtInfo;

    dwEntryOffset = (pMHPpool->dwMHP_ASIC_BaseAddr - pHwDeviceExtension->gartMemoryControllerAddress.LowPart) / SGT_PAGE_SIZE;
    dwNumEntries = pMHPpool->dwMHP_TotalBytes / SGT_PAGE_SIZE;

    ASSERT (dwEntryOffset + dwNumEntries <= pSGTinfo->ulTotalEntriesUsedByMHP);
    ASSERT (pSGTinfo->ulTotalEntriesUsedByMHP <= pSGTinfo->ulTotalSGTentriesUseableByMHP);


    if (dwEntryOffset + dwNumEntries == pSGTinfo->ulTotalEntriesUsedByMHP)
    {
        pSGTinfo->ulTotalEntriesUsedByMHP -= dwNumEntries;
    }

    if((dwEntryOffset + dwNumEntries) <= pSGTinfo->ulTotalSGTentriesUseableByMHP)
    {
        pulSGT = (PULONG )pSGTinfo->pvSgtBaseAddress + dwEntryOffset;

        for (ulIncrement = 0; ulIncrement < dwNumEntries; ulIncrement ++)
        {
            *pulSGT++ = 0;
        } // loop through all the pages in this allocation
    }

}   // UnmapFromSgt()

VOID
FreePool(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID VirtualAddress
    )
//
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//
// RETURN VALUE:
//  NONE
//  
{
#if defined(FOUR_GB_FIX)
    PCOMMON_ALLOC   pcaNode;

    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);

    //
    // Free most recently allocated pool of memory.
    //
    pcaNode = (PCOMMON_ALLOC) VirtualAddress;

    if (NULL == pcaNode)
        return;

    pcaNode--;
    
    FreeCommonBuffer(pHwDeviceExtension,
                     pcaNode->ulBlockSize,
                     pcaNode->paPhysicalAddress,
                     pcaNode->pvLinearAddress,
                     TRUE);

#else
    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);

    //
    // Free most recently allocated pool of memory.
    //
    VpFreePool( pHwDeviceExtension, VirtualAddress ); 

#endif
}   // FreePool()

PHYSICAL_ADDRESS
GetPhysicalAddress(
	PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID pVirtualAddress
    )
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//  pVirtualAddress     Points to the virtual address of a chunk of memory.
//
// RETURN VALUE:
//  None.
//  
{
    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);

    return MmGetPhysicalAddress(pVirtualAddress);
}   // GetPhysicalAddress()

PVOID
ShareDmaMem(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID pVirtualAddress,
    ULONG ulSize
    )
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//  VirtualAddress      Address of the beginning of the buffer to be mapped.
//  ulSize              Size of the buffer to be mapped.
//
// RETURN VALUE:
//  Pointer to mapped buffer.
//
{
    PMDL  pMDL;                   // Pointer to the memory descriptor list.
    PVOID pMappedVirtualAddress;  // Pointer to the user memory.

    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);

        
    pMDL = IoAllocateMdl(pVirtualAddress, ulSize, FALSE, FALSE, NULL);

    if (NULL == pMDL)
        return NULL;   
        
    MmBuildMdlForNonPagedPool(pMDL);

    __try
    {   
       pMappedVirtualAddress = MmMapLockedPagesSpecifyCache(pMDL,
                                                            UserMode,
                                                            MmCached,
                                                            NULL,
                                                            FALSE,
                                                            HighPagePriority); 
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
      //
      // Release memory allocated for MDL.
      //
      IoFreeMdl(pMDL);
      return NULL;
    }

    //
    // Release memory allocated for MDL.
    //
        
    IoFreeMdl(pMDL);

    return pMappedVirtualAddress;
}   // ShareDmaMem()

VOID
UnshareDmaMem(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID pVirtualAddress,
    ULONG ulSize
    )
//
// DESCRIPTION:
//  Unmaps memory from user space.
//
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//  VirtualAddress      Address of the beginning of the buffer to be mapped.
//  ulSize              Size of the buffer to be mapped.
//
// RETURN VALUE:
//  Pointer to mapped buffer.
//
{
    PMDL pMDL;                   // Pointer to the memory descriptor list.

    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);
       
    if(!MmIsAddressValid(pVirtualAddress))
    {
        return;
    }
        
    pMDL = IoAllocateMdl(pVirtualAddress, ulSize, FALSE, FALSE, NULL);

	if (NULL == pMDL)
	{
		ASSERT(NULL != pMDL);
		return;
	}
    
    MmBuildMdlForNonPagedPool(pMDL);
    
    MmUnmapLockedPages(pVirtualAddress, pMDL);

    //
    // Release memory allocated for MDL.
    //
    IoFreeMdl(pMDL);

}   // UnshareDmaMem()

ULONG
ReadPciConfig(
    PVOID pHwDeviceExt,
    ULONG ulAddress,
    PVOID pValue,
    ULONG ulSize
    )
//
// DESCRIPTION:
//  Reads value of a specific size to the PCI config space
//
// PARAMETERS:
//  
//  ulAddress specifies the byte offset in the PCI_COMMON_CONFIG structure for 
//  which the requested information should be returned.
//
//  pValue points to a caller-supplied buffer for configuration information 
//
//  ulSize specifies the maximum number of bytes to return in the buffer. 
//
// RETURN VALUE:
//  Number of bytes read
//
{

    if ((ulSize <= 0) || (ulSize > sizeof(PCI_COMMON_CONFIG)))
        return(0);

    ASSERT(NULL != pHwDeviceExt);

    if (!pHwDeviceExt)
    {
        return 0;
    }
    else
    {
        PHW_DEVICE_EXTENSION pHwDevExt = (PHW_DEVICE_EXTENSION)pHwDeviceExt;
        HANDLE DeviceHandle = pHwDevExt->ddiCallback.DeviceHandle;
        ULONG ulSizeRet = 0;
        NTSTATUS status = pHwDevExt->ddiCallback.DxgkCbReadDeviceSpace( DeviceHandle,
                                                                        PCI_WHICHSPACE_CONFIG,
                                                                        pValue,
                                                                        ulAddress,
                                                                        ulSize,
                                                                        &ulSizeRet);

        return (status == STATUS_SUCCESS)?ulSizeRet:0;
    }
} // ReadPciConfig


ULONG
WritePciConfig(
    PVOID pHwDeviceExt,
    ULONG ulAddress,
    PVOID pValue,
    ULONG ulSize
    )
//
// DESCRIPTION:
//  Writes value of a specific size to the PCI config space
//
// PARAMETERS:
//  
//
// RETURN VALUE:
//  Number of bytes written
//
{
    if ((ulSize <= 0) || (ulSize > sizeof(PCI_COMMON_CONFIG)))
        return(0);

    ASSERT(NULL != pHwDeviceExt);

    if (!pHwDeviceExt)
    {
        return 0;
    }
    else
    {
        PHW_DEVICE_EXTENSION pHwDevExt = (PHW_DEVICE_EXTENSION)pHwDeviceExt;
        HANDLE DeviceHandle = pHwDevExt->ddiCallback.DeviceHandle;
        ULONG ulSizeRet = 0;
        NTSTATUS status = pHwDevExt->ddiCallback.DxgkCbWriteDeviceSpace( DeviceHandle,
                                                                        PCI_WHICHSPACE_CONFIG,
                                                                        pValue,
                                                                        ulAddress,
                                                                        ulSize,
                                                                        &ulSizeRet);
        return (status == STATUS_SUCCESS)?ulSizeRet:0;
    }
} // WritePciConfig
/******************************Public*Routine******************************\
* AddPhyscialAddress()
*
* This routine is used in add physical addresses (or 64 bit values).
* Result = Addr1 + Addr2
*
\**************************************************************************/
void AddPhysicalAddress(PHYSICAL_ADDRESS *pAddr1, 
                        PHYSICAL_ADDRESS *pAddr2,
                        PHYSICAL_ADDRESS *pResult)
{
    PAGED_CODE();

    pResult->HighPart = pAddr1->HighPart + pAddr2->HighPart;
    pResult->LowPart = pAddr1->LowPart + pAddr2->LowPart;

    //Any carry? Yes, if less then either one of the originals...
    if (pResult->LowPart < pAddr1->LowPart)
    {
        ++pResult->HighPart;
    }    
}

// *** begin PM4_INTERRUPT code ***

/******************************Public*Routine******************************\
* AtiSetKernelEvent()
*
* pvEvent : This is a pointer to the 'opaque' _ENG_EVENT object.
*
\**************************************************************************/
VOID
AtiSetKernelEvent(
    PHW_DEVICE_EXTENSION    pHwDeviceExtension,
    PVOID                   pvEvent,
    DWORD                   dwPriorityBoost
    )
{
    PKEVENT pkEvent;
    pkEvent = (PKEVENT)pvEvent;

    KeSetEvent(*((PVOID*)pkEvent), dwPriorityBoost, FALSE);
}

BOOL
AtiValidateKernelEventPriorityBoost(
    DWORD                   dwPriorityBoost
    )
{
    return (dwPriorityBoost < IO_SOUND_INCREMENT) ? TRUE : FALSE;
}

DWORD
AtiGetDefaultKernelEventPriorityBoost(
    VOID
    )
{
    return IO_VIDEO_INCREMENT;
}

// *** end PM4_INTERRUPT code ***

#ifdef CMMQSMP

//#define APIENTRY    __stdcall

typedef void           *LPVOID;
typedef void           *HSEMAPHORE;

NTSTATUS
R200DeviceIoControl(
    HANDLE hDevice,
    DWORD dwIoControlCode,
    LPVOID lpInBuffer,
    DWORD nInBufferSize,
    LPVOID lpOutBuffer,
    DWORD nOutBufferSize,
    LPDWORD lpBytesReturned
    );

DWORD APIENTRY
EngDeviceIoControl(
    HANDLE hDevice,
    DWORD dwIoControlCode,
    LPVOID lpInBuffer,
    DWORD nInBufferSize,
    LPVOID lpOutBuffer,
    DWORD nOutBufferSize,
    LPDWORD lpBytesReturned
    )

{
    DWORD retStatus;
    NTSTATUS Status = R200DeviceIoControl(hDevice,
                                          dwIoControlCode,
                                          lpInBuffer,
                                          nInBufferSize,
                                          lpOutBuffer,
                                          nOutBufferSize,
                                          lpBytesReturned);

    //
    // Do the inverse translation to what the video port does
    // so that we can have the original win32 status codes.
    //
    // Maybe, somehow, we can completely eliminate this double
    // translation - but I don't care for now.  It's just a bit
    // longer on the very odd failiure case
    //

    switch (Status) {

    case STATUS_SUCCESS:
        retStatus = NO_ERROR;
        break;

    case STATUS_NOT_IMPLEMENTED:
        retStatus = ERROR_INVALID_FUNCTION;
        break;

    case STATUS_INSUFFICIENT_RESOURCES:
        retStatus = ERROR_NOT_ENOUGH_MEMORY;
        break;

    case STATUS_INVALID_PARAMETER:
        retStatus = ERROR_INVALID_PARAMETER;
        break;

    case STATUS_BUFFER_TOO_SMALL:
        retStatus = ERROR_INSUFFICIENT_BUFFER;
        break;

    case STATUS_BUFFER_OVERFLOW:
        retStatus = ERROR_MORE_DATA;
        break;

    case STATUS_PENDING:
        retStatus = ERROR_IO_PENDING;
        break;
    case STATUS_DEVICE_DOES_NOT_EXIST:
        retStatus = ERROR_DEV_NOT_EXIST;
        break;

    default:
        retStatus = Status;
        break;

    }

    return retStatus;
}


HSEMAPHORE APIENTRY EngCreateSemaphore(
    VOID
    )
{
    PERESOURCE  pRes;

#pragma prefast( disable: 8103 )
    pRes = (PERESOURCE)ExAllocatePoolWithTag(PagedPool,
                                             sizeof(ERESOURCE),
                                             'r2sm');
    if (! pRes)
    {
        return NULL;
    }

    if (NT_SUCCESS(ExInitializeResourceLite(pRes)))
    {
        return (pRes);
    }
    else
    {
        ExFreePool(pRes);
        return NULL;
    }
#pragma prefast( enable: 8103 )
}

VOID APIENTRY EngAcquireSemaphore(
    __in  HSEMAPHORE hsem
    )
{
#pragma prefast( disable: 8103 )
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite((PERESOURCE)hsem, TRUE);
#pragma prefast( enable: 8103 )
}

VOID APIENTRY EngReleaseSemaphore(
    __in  HSEMAPHORE hsem
    )
{
#pragma prefast( disable: 8107 )
    ExReleaseResourceLite((PERESOURCE)hsem);
    KeLeaveCriticalRegion();
#pragma prefast( enable: 8107 )
}

VOID APIENTRY EngDeleteSemaphore(
    HSEMAPHORE hsem
    )
{
    ExDeleteResourceLite((PERESOURCE)hsem);
    ExFreePool(hsem);
}

#endif



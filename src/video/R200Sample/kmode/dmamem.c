/*****************************************************************************\
* 
*  Module Name    DMAMEM.C
*  Project        Longhorn
*  Device         R200
*
*  Description    Contains routines required to allocate/free memory that is accessible via DMA.
*                 
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
\*****************************************************************************/

#include "common.h"
#include "rage.h"
#include "dma.h"

extern VP_DEVICE_DESCRIPTION ex_vpDeviceDescription;

//
// Allow swapping.
//

#if defined (ALLOC_PRAGMA)
#pragma alloc_text(PAGE_COM, AllocateCommonBuffer)
#pragma alloc_text(PAGE_COM, FreeCommonBuffer)
#endif  // ALLOC_PRAGMA

PVOID
AllocateCommonBuffer(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulBufferLength,
    PHYSICAL_ADDRESS *pPhysicalAddress,
    BOOLEAN bCacheable                        
    )
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//
// RETURN VALUE:
//  Base virtual address of the allocated range, otherwise NULL.
//
{
    ULONG ulActualLength;
    PVOID pvAddress = NULL;

    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);
    ASSERT(NULL != pHwDeviceExtension->pDmaAdapterGUI);

	if (NULL != pHwDeviceExtension->pDmaAdapterGUI)
    {
        ulActualLength = ulBufferLength;

        pvAddress = DlAllocateCommonBuffer(pHwDeviceExtension->DeviceHandle, 
                                                  pHwDeviceExtension->pDmaAdapterGUI,
                                                  ulBufferLength,
                                                  pPhysicalAddress,
                                                  bCacheable,
                                                  NULL
            );
        if (NULL != pvAddress && (ulActualLength < ulBufferLength))
        {
            DlReleaseCommonBuffer(pHwDeviceExtension,
                                         pHwDeviceExtension->pDmaAdapterGUI,
                                         ulActualLength,
                                         *pPhysicalAddress,
                                         pvAddress,
                                         bCacheable);
            pvAddress = NULL;
        }
    }
    return pvAddress;
}   // AllocateCommonBuffer()

VOID
FreeCommonBuffer(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulBufferLength,
    PHYSICAL_ADDRESS PhysicalAddress,
    PVOID VirtualAddress,
    BOOLEAN bCacheable                        
    )
//
// DESCRIPTION:
//  Frees the memory used for the scatter gather table.
//
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//
// RETURN VALUE:
//  NONE
//
{
    PAGED_CODE();
    ASSERT(NULL != pHwDeviceExtension);

    DlReleaseCommonBuffer(pHwDeviceExtension, 
                                 pHwDeviceExtension->pDmaAdapterGUI,
                                 ulBufferLength,
                                 PhysicalAddress,
                                 VirtualAddress,
                                 bCacheable);
}   // FreeCommonBuffer()

PVOID
VpAllocatePool(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG  PoolType,
    SIZE_T NumberOfBytes,
    ULONG  Tag
    )
{
    ASSERT( PoolType == VP_NONPAGEDPOOL );

    return DlAllocatePool( pHwDeviceExtension, VpNonPagedPool, NumberOfBytes, Tag );
}   // VpAllocatePool()

VOID
VpFreePool(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID VirtualAddress
    )
{
    DlFreePool( pHwDeviceExtension, VirtualAddress );
}   // VpFreePool()



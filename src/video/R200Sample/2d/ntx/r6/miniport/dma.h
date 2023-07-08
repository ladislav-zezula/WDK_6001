

/*****************************************************************************\
* 
*  Module Name    DMA.H
*  Project        Longhorn
*  Device         R200
*
*  Description    header definitions for functions in DMA.C, 
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
\*****************************************************************************/


#ifndef _DMA_H_
#define _DMA_H_

#include <DriverSpecs.h>

__kernel_driver

//
// Prototypes for functions supplied by DMA.C.
//

ULONG
GetPageSize(
    VOID
    );

VOID
InitializeSgtInfo(
    __in PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

PVOID
AllocateCommonBuffer(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulBufferLength,
    PHYSICAL_ADDRESS *pPhysicalAddress,
    BOOLEAN bCacheable                        
    );

VOID
FreeCommonBuffer(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulBufferLength,
    PHYSICAL_ADDRESS PhysicalAddress,
    PVOID VirtualAddress,
    BOOLEAN bCacheable                        
    );

PVOID
AllocateContiguousMemory(
    PHW_DEVICE_EXTENSION    pHwDeviceExtension,
    ULONG                   ulPoolSize,
    PHYSICAL_ADDRESS        *pPhysAddr
    );

VOID
FreeContiguousMemory(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID pVirtualAddress
    );

PVOID
AllocatePool(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulPoolSize
    );

BOOL
DoesSgtHaveRoom(
    PHW_DEVICE_EXTENSION  pHwDeviceExtension,
    DWORD                 dwPoolSizeInBytes,
    DWORD                 dwEntryOffset
    );

BOOL
MapToSgt(
    __in PHW_DEVICE_EXTENSION  pHwDeviceExtension,
    __in PMEMHEAP_POOL         pMHPpool,
    __in DWORD                 dwEntryOffset
    );

VOID
UnmapFromSgt(
    __in PHW_DEVICE_EXTENSION  pHwDeviceExtension,
    __in PMEMHEAP_POOL         pMHPpool
    );

VOID
FreePool(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID VirtualAddress
    );

PHYSICAL_ADDRESS
GetPhysicalAddress(
	PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID pVirtualAddress
    );

PVOID
ShareDmaMem(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID pVirtualAddress,
    ULONG ulSize
    );

VOID
UnshareDmaMem(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID pVirtualAddress,
    ULONG ulSize
    );
    
ULONG
ReadPciConfig(
    PVOID pHwDeviceExt,
    ULONG ulAddress,
    PVOID pValue,
    ULONG ulSize
    );

ULONG
WritePciConfig(
    PVOID pHwDeviceExt,
    ULONG ulAddress,
    PVOID pValue,
    ULONG ulSize
    );

PVOID
VpAllocatePool(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG  PoolType,
    SIZE_T NumberOfBytes,
    ULONG  Tag
);

VOID
VpFreePool(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID pVirtualAddress
);

#define VP_NONPAGEDPOOL 0

void AddPhysicalAddress(PHYSICAL_ADDRESS *pAddr1, 
                        PHYSICAL_ADDRESS *pAddr2,
                        PHYSICAL_ADDRESS *pResult);

#define ONE_KILOBYTE           (1024)
#define ONE_MEGABYTE           (1024*1024)
#define MAX_SYSTEM_MEM_LOWER_BLOCK  ((ULONGLONG)2*ONE_KILOBYTE*ONE_MEGABYTE)

VOID
AtiSetKernelEvent(
    PHW_DEVICE_EXTENSION    pHwDeviceExtension,
    PVOID                   pvEvent,
    DWORD                   dwPriorityBoost
    );

BOOL
AtiValidateKernelEventPriorityBoost(
    DWORD                   dwPriorityBoost
    );

DWORD
AtiGetDefaultKernelEventPriorityBoost(
    VOID
    );

#endif  // _DMA_H_


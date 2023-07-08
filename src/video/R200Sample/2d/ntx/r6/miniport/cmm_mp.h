

/**************************************************************************\
* 
*  Module Name    cmm_mp.h
*  Project        Longhorn
*  Device         R200
*
*  Description    header file for shared memory heap manager....
*
*  (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*
*  LOG OF CHANGES
*
\**************************************************************************/

#ifndef _CMM_MP_H
#define _CMM_MP_H

// Error codes returned by MHP_ReserveFBMemory
#define MHP_STATUS_SUCCESS              0
#define MHP_STATUS_NO_MEMORY            1
#define MHP_STATUS_MEMORY_OVERLAP       2
#define MHP_STATUS_INVALID_LOCATION     3
#define MHP_STATUS_INVALID_SIZE         4
#define MHP_STATUS_INVALID_RANGE        5
#define MHP_STATUS_RESERVATION_EXISTS   6

//////////////////////////////////////////////////////////////////
// Exported functions from cmm_mp.c
//////////////////////////////////////////////////////////////////
DWORD MHP_DisablePoolMemory (
    PHW_DEVICE_EXTENSION  pHwDeviceExtension,
    DWORD                 dwPoolType
    );

DWORD MHP_GetTotalPoolSizeBoot (
    PMEMHEAP_COMBINED_POOL  pMHPcombined,
    DWORD                   dwMemoryType
    );

DWORD MHP_GetTotalPoolSize (
    PMEMHEAP_COMBINED_POOL  pMHPcombined,
    DWORD                   dwMemoryType
    );

VOID MHP_SetFrameBufferValues (
    PMEMHEAP_COMBINED_POOL  pMHPcombined,
    ULONG                   ulVRamSizeAvailable,
    ULONG                   ulVRamSizeInvisible,
    PHYSICAL_ADDRESS        lfbPhysicalAddress,
    PVOID                   pvLfbBaseAddress,
    PHW_DEVICE_EXTENSION    pHwDeviceExtension
    );

VOID MHP_RememberState(
    PMEMHEAP_COMBINED_POOL  pMHPcombined,
    ULONG           ulPowerState
    );

VOID MHP_SetAgpValues (
    PMEMHEAP_COMBINED_POOL  pMHPcombined,
    ULONG                   ulUSWC,
    ULONG                   ulAGPregionSizeBytes,
    PHYSICAL_ADDRESS        lfbPhysicalAddress,
    PVOID                   pVirtualAddress
    );

VOID MHP_ClearAgpAperture(
    PMEMHEAP_COMBINED_POOL  pMHPcombined
    );

VOID MHP_FreeResources (
    PMEMHEAP_COMBINED_POOL  pMHPcombined,
    PHW_DEVICE_EXTENSION    pHwDeviceExtension
    );

BOOL MHP_GetMorePCIGARTspace (PHW_DEVICE_EXTENSION    pHwDeviceExtension,
                              PMEMHEAP_COMBINED_POOL  pMHPcombined,
                              PMEMHEAP_POOL           pMHPpool,
                              DWORD                   dwSpaceRequiredInBytes,
                              DWORD                   dwGartControllerAddress);

BOOL MHP_ReleasePCIGARTspace (PHW_DEVICE_EXTENSION    pHwDeviceExtension,
                              PMEMHEAP_COMBINED_POOL  pMHPcombined,
                              PMEMHEAP_POOL           pMHPpool);

VOID MHP_GetResources(
    PMEMHEAP_COMBINED_POOL  pMHPcombined,
    PHW_DEVICE_EXTENSION    pHwDeviceExtension
    );

VOID MHP_Clear(
    PMEMHEAP_COMBINED_POOL  pMHPcombined
    );

DWORD MHP_ReserveFBMemory(
    PHW_DEVICE_EXTENSION    pHwDeviceExtension,
    DWORD                   dwReserveOffset,
    DWORD                   dwReserveSize
    );

DWORD MHP_GetRegistrySetting (PHW_DEVICE_EXTENSION  pHwDeviceExtension,
                              DWORD                 dwWhichSetting);

BOOL MHP_ReadAllRegistrySettings (PHW_DEVICE_EXTENSION  pHwDeviceExtension);

#endif //_CMM_MP_H


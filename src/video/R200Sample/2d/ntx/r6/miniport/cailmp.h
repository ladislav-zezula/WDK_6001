

/*****************************************************************************\
* 
*  Module Name    CAILMP.H
*  Project        Longhorn
*  Device         R200
*
*  Description    Miniport header for Common ASIC Initialization Library.
*
*  Coppyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
\*****************************************************************************/

#ifndef CAILMP_H
#define CAILMP_H
// Function prototypes

CAILRESULT  CailGetRegistrykeyCallback(
    __in     PHW_CAIL_EXTENSION      hCAIL,
    __in     PWSTR                   pwszName,
    __in     ULONG                   ulDefaultvalue,
    __inout  PULONG                  pulResult
);

CAILRESULT  CailSetRegistrykeyCallback(
    __in     PHW_CAIL_EXTENSION  hCAIL,
    __in     PWSTR               pwszName,
    __in     ULONG               ulKeyvalue
);

CAILRESULT InitCail(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PHW_CAIL_EXTENSION hCAIL
);

DWORD QuerySystemInfo_Cail(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PHW_CAIL_EXTENSION hCAIL
);

void FixChipsetBugs_Cail(
    PHW_DEVICE_EXTENSION    pHwDeviceExtension,
    PHW_CAIL_EXTENSION      hCAIL
);

DWORD QueryASICInfo_Cail(
    PHW_DEVICE_EXTENSION    pHwDeviceExtension,
    PHW_CAIL_EXTENSION      hCAIL
);

CAILRESULT CailNtInitialize(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PHW_CAIL_EXTENSION hCAIL
);

CAILRESULT CailPostNoBiosUpdateHde(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PHW_CAIL_EXTENSION hCAIL
);


CAILRESULT CailReadPciCfgCallback(
    PVOID hDevice,  //  Hardware Device Extension
    ULONG ulSlot,   //  Is not used anymore
    ULONG ulAddress,
    PVOID pvDest,
    ULONG ulSize,
    PULONG pulRetSizeBytes
);

CAILRESULT CailWritePciCfgCallback(
    PVOID hDevice,  //  Hardware Device Extension
    ULONG ulSlot,   //  Is not used anymore
    ULONG ulAddress,
    PVOID pvSrc,
    ULONG ulSize,
    PULONG pulRetSizeBytes
);

CAILRESULT CailGetPciBusDataCallback(
    PVOID hDevice, 
    PVOID pvDest,
    ULONG ulAddress,
    ULONG ulSize,
    PULONG pulRetSizeBytes
    );

CAILRESULT CailSetPciBusDataCallback(
    PVOID hDevice,
    PVOID pvDest,
    ULONG ulAddress,
    ULONG ulSize,
    PULONG pulRetSizeBytes
    );

ULONG GetCailPowerState(
    DWORD PowerState
    );

CAILRESULT CailSyncExecutionCallback(
    PVOID               pHwDevice,
    CAIL_VSYNC_PRIORITY priority,
    PVOID               pSyncRoutine,
    PVOID               pContext
    );

CAILRESULT CailAllocateMemoryCallback(
    PHW_CAIL_EXTENSION  hCAIL,
    ULONG               ulMemSize,
    VOID**              ResultPtr
    );

CAILRESULT CailReleaseMemoryCallback(
    PHW_CAIL_EXTENSION  hCAIL,
    VOID*               pPoolPtr
    );

VOID   MHP_ReserveFBMemory_CAIL(    
    PHW_DEVICE_EXTENSION    pHwDeviceExtension,
    PHW_CAIL_EXTENSION      hCAIL
);

CAILRESULT  CailGetRegistryDWORDArrayCallback(
    __in     PHW_CAIL_EXTENSION      hCAIL,
    __in     PWSTR                   pwszName,
    __inout  PDWORD                  lpdwArray,
    __in     DWORD                   dwSize
);

#endif // CAILMP_H


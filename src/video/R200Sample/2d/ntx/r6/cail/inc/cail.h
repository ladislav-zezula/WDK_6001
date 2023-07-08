

/****************************************************************************\
* 
*  Module Name    cail.h
*  Project        Common ASIC Initialization Library
*  Device         Radeon (9x/NT5+)
*
*  Description    Header file for Common ASIC Initialization Library
*  
*
*  Copyright (c) 2001 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
\****************************************************************************/

#ifndef _CAIL_H
#define _CAIL_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_X86_)
#pragma pack(1)
#endif

#define CAIL_VERSION_MAJOR                   0x00010000
#define CAIL_VERSION_MINOR                   0x00000012

#define CAIL_HEADER_VERSION (CAIL_VERSION_MAJOR | CAIL_VERSION_MINOR)

// Adapter state flags
#define CAIL_ADAPTERSTATE_VGAENABLED                  0x00000001L
#define CAIL_ADAPTERSTATE_ASIC_RESET                  0x00000002L

// Adapter data constants
#define CAIL_ADAPTERDATA_MAX_BIOS_SCRATCH_REGS        10
#define CAIL_ADAPTERDATA_MAX_GUI_SCRATCH_REGS         10

// flag from CAIL for 2d to use
#define CAIL_DISABLE_DUALVIEW                           1
#define CAIL_DISABLE_AGP_WRITE                          2
#define CAIL_DISABLE_AGP_FASTWRITES                     3
#define CAIL_DISABLE_DMA                                5
#define CAIL_EXTEND_POWER_CONNECTED                     6

// Memory type
#define CAIL_MEMTYPE_AGP       0x00000000L
#define CAIL_MEMTYPE_FB        0x00000001L
#define CAIL_MEMTYPE_ROM       0x00000002L
#define CAIL_MEMTYPE_ATIGART   0x00000003L
#define CAIL_MEMTYPE_PCIGART   0x00000004L

#define CAIL_MAX_MEMTYPE       0x00000005L

#define R200_TAG               '002R'

//flags used by CAILReserveMCAddressRange call
#define CAIL_RESERVEMC_USE_MCBASEADDR         0x00000001L
#define CAIL_RESERVEMC_USE_MCBASEADDR_ONLY    0x00000002L


// flag from 2D to inform CAIL
#define CAIL_2D_ADAPTER_VGAENABLED                     0x00000001L
#define CAIL_2D_IKOS_PLATFORM                          0x00000002L

/****************************************************************************\
* Return Codes
\****************************************************************************/

// CAILRESULT
typedef enum _CAILRESULT
{
    CAIL_OK                                 = 0,
    CAIL_ERROR_GENERIC                      = 1,
    CAIL_ERROR_INVALIDPARAMS                = 2,
    CAIL_ERROR_UNINITIALIZED                = 3,
    CAIL_ERROR_REINITIALIZE                 = 4,
    CAIL_ERROR_CATASTROPHIC                 = 5,
    CAIL_ERROR_NOACK                        = 100, //I2C stuff
    CAIL_ERROR_TIMEOUT                      = 101,
    CAIL_ERROR_UNSUPPORTADDRESS             = 102,
    CAIL_ERROR_INVALIDI2C                   = 103,
    CAIL_ERROR_INVALIDASICSUPPORT           = 104, 
    CAIL_ERROR_BIOSTABLENOTFOUND            = 110,
    CAIL_ERROR_BIOSEXECPARSER               = 111,
    CAIL_ERROR_MCRANGE_ALREADY_MAPPED       = 120,
    CAIL_ERROR_MCRANGE_CONFLICT             = 121,
    CAIL_ERROR_MCRANGE_NOT_MAPPED           = 122
} CAILRESULT;


#define CAIL_POWERSTATE_D0                0x00000001
#define CAIL_POWERSTATE_D1                0x00000002
#define CAIL_POWERSTATE_D2                0x00000004
#define CAIL_POWERSTATE_D3                0x00000008
#define CAIL_POWERSTATE_HIBERNATE         0x00000010


#define INVALID_VALUE            0xFFFFFFFF
/****************************************************************************\
* Types
\****************************************************************************/

#ifndef _WIN64
#ifndef ULONG_PTR
typedef unsigned long ULONG_PTR;
#endif // ULONG_PTR
#endif // _WIN64

/****************************************************************************\
* Types
\****************************************************************************/

// CAIL_FUNCPTR
#ifndef FGL_LINUX
typedef CAILRESULT (*CAIL_FUNCPTR)();
#else
// gnu c wants function parameters for function type defines.
// this type is referenced nowhere i can see it. exclude it for now.
#endif

// CAIL_DRV_CALLBACK
#ifndef FGL_LINUX
typedef CAILRESULT (*CAIL_DRV_CALLBACK)();
#else
// gnu c wants function parameters for function type defines.
// -> define an exact match for any pfnDrv* function
typedef CAILRESULT (*CAIL_DRV_CB_READPCICONFIG)(
    IN PVOID hDevice,
    IN ULONG ulSlot,
    IN ULONG ulAddress,
    IN OUT PVOID pValue,
    IN ULONG ulSize,
    IN ULONG* ulRet);
typedef CAILRESULT (*CAIL_DRV_CB_WRITEPCICONFIG)(
    IN PVOID hDevice,
    IN ULONG ulPciBusNumber,
    IN ULONG ulSlot,
    IN PVOID pValue,
    IN ULONG ulSize,
    IN ULONG* ulRet);
typedef CAILRESULT (*CAIL_DRV_CB_GETPCIBUSDATA)(
    IN PVOID hDevice,
    IN OUT PVOID pPciCfgData,
    IN ULONG ulOffset,
    IN ULONG ulSize,
    IN ULONG* ulRet);
typedef CAILRESULT (*CAIL_DRV_CB_SETPCIBUSDATA)(
    IN PVOID hDevice,
    IN PVOID pvPciCfgData,
    IN ULONG ulOffset,
    IN ULONG ulSize,
    IN ULONG* ulRet);
typedef CAILRESULT (*CAIL_DRV_CB_READROMIMAGE)(
    IN PVOID hCAIL,
    IN PVOID pvDestination,
    IN ULONG ulRomOffset,
    IN ULONG ulLength);
typedef CAILRESULT (*CAIL_DRV_CB_DELAYINMICROSECONDS)(
    IN ULONG ulTimeInMicroSeconds);
#endif

/****************************************************************************\
* Structure Definitions
\****************************************************************************/

// CAIL_DRV_CALLBACKS
typedef struct _CAIL_DRV_CALLBACKS
{
#ifndef FGL_LINUX
    CAIL_DRV_CALLBACK pfnDrvReadPciConfig;
    CAIL_DRV_CALLBACK pfnDrvWritePciConfig;
    CAIL_DRV_CALLBACK pfnDrvGetPciBusData;
    CAIL_DRV_CALLBACK pfnDrvSetPciBusData;
    CAIL_DRV_CALLBACK pfnDrvReadRomImage;
    CAIL_DRV_CALLBACK pfnDrvDelayInMicroseconds;
    CAIL_DRV_CALLBACK pfnDrvGetRegistrykey;     // read Registry key from system
    CAIL_DRV_CALLBACK pfnDrvSetRegistrykey;     // write registry key from system
    CAIL_DRV_CALLBACK pfnDrvGetRegistryDWORDArray;   // read a DWORD Array registry key from system
    CAIL_DRV_CALLBACK pfnDrvSyncExecution;      // Soft reset generation
    CAIL_DRV_CALLBACK pfnDrvAllocateMemory;   // Allocate memory - used by command decoder
    CAIL_DRV_CALLBACK pfnDrvReleaseMemory;    // Release memory - used by command decoder
#else
    CAIL_DRV_CB_READPCICONFIG       pfnDrvReadPciConfig;
    CAIL_DRV_CB_WRITEPCICONFIG      pfnDrvWritePciConfig;
    CAIL_DRV_CB_GETPCIBUSDATA       pfnDrvGetPciBusData;
    CAIL_DRV_CB_SETPCIBUSDATA       pfnDrvSetPciBusData;
    CAIL_DRV_CB_READROMIMAGE        pfnDrvReadRomImage;
    CAIL_DRV_CB_DELAYINMICROSECONDS pfnDrvDelayInMicroseconds;
#endif
} CAIL_DRV_CALLBACKS;

#define CAIL_INIT_HDEVICE                       0X00000001L
#define CAIL_INIT_ASICFAMILYID                  0X00000002L
#define CAIL_INIT_ASICID                        0X00000004L
#define CAIL_INIT_ASICREVID                     0X00000008L
#define CAIL_INIT_ROMHEADOFFSET                 0X00000010L
#define CAIL_INIT_ROMBASEADDR                   0X00000020L
#define CAIL_INIT_MMRBASE                       0X00000040L
#define CAIL_INIT_BRDGEMMRBASE                  0X00000080L
#define CAIL_INIT_DRVREADPCICFG                 0X00000100L
#define CAIL_INIT_DRVWRITEPCICFG                0X00000200L
#define CAIL_INIT_DRVGETPCIBUSDATA              0X00000400L
#define CAIL_INIT_DRVSETPCIBUSDATA              0X00000800L
#define CAIL_INIT_DRVREADROMIMAGE               0X00001000L
#define CAIL_INIT_DRVDELAYMICOSECONDS           0X00002000L
#define CAIL_INIT_DRVGETREGISTRYKEY             0X00004000L
#define CAIL_INIT_DRVSETREGISTRYKEY             0X00008000L
#define CAIL_INIT_FLAGSFROM2D                   0X00010000L
#define CAIL_INIT_ALL                           0X0001FFFFL

typedef struct _CAIL_INIT
{
    ULONG   ulSize;
    ULONG   ulInitFlags;            // Init flag, indicate which field is valid 
    PVOID   hDevice;                // == HCAIL->hDevice, in NTx, PHW_DEVICE_EXTENSION, in 9x, PVXDINFO
    ULONG   ulAsicFamilyID;         // Family ID  == ATIAdapterInfo.ulAsicFamily
    ULONG   ulAsicID;               // ASIC ID    == ATIAdapterInfo.ulAsicID
    ULONG   ulAsicRevisionID;       // == ATIAdapterInfo.ulAsicRevisionID
    PVOID   pvRomBaseAddr;          // == ATIAdapterInfo.pvRomBaseAddr Mapped logical base address of ATI ROM
    PVOID   pvMmr;                  // == ATIAdapterInfo.pvMmr Linear base addr of memmapped registers
    PVOID   pvBridgeBase;           // == ATIAdapterInfo.pvCailBridgeBase
    
    CAIL_DRV_CALLBACK pfnDrvReadPciConfig;      // read from northbridge and southbridge
    CAIL_DRV_CALLBACK pfnDrvWritePciConfig;     // write to northbridge and southbridge
    CAIL_DRV_CALLBACK pfnDrvGetPciBusData;      // read from ASIC ATI adapter
    CAIL_DRV_CALLBACK pfnDrvSetPciBusData;      // write to ASIC ATI adapter
    CAIL_DRV_CALLBACK pfnDrvReadRomImage;       // read Rom image from ATI adapter BIOS
    CAIL_DRV_CALLBACK pfnDrvDelayInMicroseconds;// Delay for a certain microseconds
    CAIL_DRV_CALLBACK pfnDrvGetRegistrykey;     // read Registry key from system
    CAIL_DRV_CALLBACK pfnDrvSetRegistrykey;     // write registry key from system
    CAIL_DRV_CALLBACK pfnDrvGetRegistryDWORDArray;   // read a DWORD Array registry key from system
    CAIL_DRV_CALLBACK pfnDrvSyncExecution;      // Soft reset generation
    CAIL_DRV_CALLBACK pfnDrvAllocateMemory;     // ALlocate Memory - Used in command decoder
    CAIL_DRV_CALLBACK pfnDrvReleaseMemory;      // Release Memory - Used in command decoder

    ULONG   ulFlagsFrom2D;                      // == hCAIL.ulAdapterStateFlags
    ULONG   ulPadding[2];                       // May need to be changed
} CAIL_INIT, *PCAIL_INIT;

// This is a temp structure, need to modify
#define CAIL_ADDITION_ASIC_ID                     1
#define CAIL_ADDITION_ASIC_SUBSYSTEM_ID           2
#define CAIL_ADDITION_ASIC_INTERNAL_REV_ID        3
#define CAIL_ADDITION_ASIC_ACTUAL_REV_ID          4
#define CAIL_ADDITION_FB_VRAM_PHYS_ADDR           5
#define CAIL_ADDITION_FB_VRAM_LINEAR_ADDR         6
#define CAIL_ADDITION_FB_VRAM_SIZE                7
#define CAIL_ADDITION_FB_APERTURE_SIZE            8
#define CAIL_ADDITION_FB_VRAM_VISIBLE_SIZE        9
#define CAIL_ADDITION_FB_VRAM_INVISIBLE_SIZE      10

#define CAIL_ADDITION_FB_VRAM_TYPE                11
#define CAIL_ADDITION_FB_VRAM_BIT_WIDTH           12
#define CAIL_ADDITION_FB_VRAM_SIZE_OVERWRITE      13
#define CAIL_ADDITION_AGP_SPEED                   14
#define CAIL_ADDITION_AGP_SPEED_OVERWRITE         15
#define CAIL_ADDITION_ROM_LENGTH                  16
#define CAIL_ADDITION_ROM_HEADEROFFSET            17
#define CAIL_ADDITION_ROM_IMAGE_ADDRESS           18
#define CAIL_ADDITION_ROM_BASE_ADDRESS            19

#define CAIL_ADDITION_ADAPTER_X_CLOCK             20
#define CAIL_ADDITION_ADAPTER_M_CLOCK             21
#define CAIL_ADDITION_ADAPTER_REF_CLOCK           22
#define CAIL_ADDITION_ADAPTER_MAX_X_CLOCK         23
#define CAIL_ADDITION_ADAPTER_MAX_M_CLOCK         24
#define CAIL_ADDITION_BIOS_RESERVE_BLOCK          25
#define CAIL_ADDITION_ADAPTER_CAP_PRT             26
#define CAIL_ADDITION_MMR_BASE_ADDRESS            27
#define CAIL_ADDITION_BRIDGE_BASE_ADDRESS         28

#define CAIL_ADDITION_CAILEXTEND_SIZE             30
#define CAIL_ADDITION_2D_DEVICE_HANDLE            31
#define CAIL_ADDITION_REGULATOR_HANDLE            32

typedef struct _CAIL_SYSTEMINFO
{
    ULONG   ulSize;
    ULONG   ulNorthBridgeSlotNumber; // Northbridge slot number BnDnFn
    ULONG   ulSouthBridgeSlotNumber; // Southbridge slot number BnDnFn
    ULONG   ulNorthBridgeID;         // Northbirdge device ID
    ULONG   ulSouthBridgeID;         // Southbridge device ID
    ULONG   ulDisableFlag;           // Flags indicate system problem
    ULONG   ulPadding[2];            // May need to be changed
} CAIL_SYSTEMINFO, *PCAIL_SYSTEMINFO;


typedef struct _CAIL_CONTROL_REG_INFO
{
    ULONG   ulDisableFlags1;         // Bit vector for disabling features, initialize read from registry key
    ULONG   ulEnableFlags1;          // Bit vector for enable features, initialize read from registry key
    ULONG   ulMemInitLatencyTimer;   // R200/R300 bringup value for MEM_INIT_LATENCY_TIMER
    ULONG   ulForceAgpSpeed;         // Forece AGP speed
    ULONG   ulAiBVersion;            // Flags indicate AIB system
    ULONG   ulSdrDcLineSize;         // SDR DcLine Size to set
    ULONG   ulAgpMaxIdleClk;         // Flags indicate system problem
    ULONG   ulMclkFreqCtrl;          // Overwrite MCLK frequency to set
    ULONG   ulXclkFreqCtrl;          // Overwrite XCLK frequency to set
    ULONG   ulMemChannels;
    ULONG   ulPadding[6];            // May need to be changed
} CAIL_CONTROL_REG_INFO, *PCAIL_CONTROL_REG_INFO;

typedef struct _CAIL_CONTROL_DEBUG_LEVEL
{
    ULONG   ulCAILDebugError;       // Control the output debug message level DEBUG_ERROR
    ULONG   ulCAILDebugNormal;      // Control the output debug message level DEBUG_NORMAL
    ULONG   ulCAILDebugDetail;      // Control the output debug message level DEBUG_DETAIL
    ULONG   ulCAILDebugAll;         // Control the output debug message level DEBUG_RIDICULOUS
} CAIL_CONTROL_DEBUG_LEVEL, *PCAIL_CONTROL_DEBUG_LEVEL;

// This is a temp structure, need to modify
typedef struct _CAIL_ADAPTER_INFO
{
    ULONG   ulSize;
    ULONG   ulSubsysID;             // Subsystem ID
    ULONG   ulVidMemType;           // Type of the video memory
    ULONG   ulXclkFreq;             // XCLK frequency
    ULONG   ulMclkFreq;             // MCLK frequency
    ULONG   ulRefFreq;              // Reference frequency
    ULONG   ulXclkMaxFreq;          // Maximum XCLK frequency
    ULONG   ulMclkMaxFreq;          // Maximum MCLK frequency
    ULONG   ulDacType;              // DAC type
    PVOID   pvAdapterCapsPtr;       // Pointer to DDI_ASIC_INIT_INFO

    ULONG   ulDDICapsSize;             // Fields that MUST exactly match DDI_CAPS in asiccaps.h
    ULONG   ulDDICapsFamilyID;         // |
    ULONG   ulDDICapsAsicID;           // |
    ULONG   ulDDICapsRevNo;            // |
    ULONG   ulDDICapsEmltRevNo;        // |
    ULONG   ulDDICaps[8];

    ULONG   ulPadding[1];           // May need to be changed
}CAIL_ADAPTER_INFO,*PCAIL_ADAPTER_INFO;

typedef struct _CAIL_PCI_CONFIG_SPACE {
    USHORT  VendorID;                   // (ro)
    USHORT  DeviceID;                   // (ro)
    USHORT  Command;                    // Device control
    USHORT  Status;
    UCHAR   RevisionID;                 // (ro)
    UCHAR   ProgIf;                     // (ro)
    UCHAR   SubClass;                   // (ro)
    UCHAR   BaseClass;                  // (ro)
    UCHAR   CacheLineSize;              // (ro+)
    UCHAR   LatencyTimer;               // (ro+)
    UCHAR   HeaderType;                 // (ro)
    UCHAR   BIST;                       // Built in self test

} CAIL_PCI_CONFIG_SPACE, *PCAIL_PCI_CONFIG_SPACE;

typedef struct CAIL_MC_RANGE_BLOCK {
    ULONG                       ulMemType;
    ULONG                       ulMemMCBaseAddr;
    ULONG                       ulMemSize;
    ULONG                       ulAlignment;
} CAIL_MC_RANGE_BLOCK, *PCAIL_MC_RANGE_BLOCK;

typedef struct _CAIL_ADAPTER_CONFIG_INFO
{
    ULONG   ulAsicID;               // ASIC ID
    ULONG   ulSubsysID;             // Subsystem ID
    ULONG   ulAsicFamily;           // Family ID
    ULONG   ulAsicInternalRevision; // Internal revision
    ULONG   ulAsicExternalRevision; // External revision
    ULONG   ulAsicActualRevision;   // "Actual" revision
    ULONG   ulVidMemPhysAddr;       // Physical address of video memory base
    PVOID   pvVidMemLinearAddr;     // Linear address of video memory base
    ULONG   ulVidMemSize;           // Video memory size in bytes
    ULONG   ulVidMemSizeVisible;    // Video memory size accessable by CPU
    ULONG   ulVidMemSizeInvisible;  // Video memory size accessable by ASIC but not CPU
    ULONG   ulVidMemType;           // Type of the video memory
    ULONG   ulVRamBitWidth;
    ULONG   ulVidMemSizeOverride;   // If we want to override the size found
    ULONG   ulLinearApertureSize;
    ULONG   ulAgpSpeed;             // AGP speed (1X/2X/4X/8X)
    ULONG   ulAgpSpeedOverride;     // Override AGP speed in case of a chipset bug
    ULONG   ulRomLength;            // Size of ATI ROM in bytes
    ULONG   ulRomHeaderOffset;      // Offset to ROM header
    ULONG   ulXclkFreq;             // XCLK frequency
    ULONG   ulMclkFreq;             // MCLK frequency
    ULONG   ulRefFreq;              // Reference frequency
    ULONG   ulXclkMaxFreq;          // Maximum XCLK frequency
    ULONG   ulMclkMaxFreq;          // Maximum MCLK frequency
    ULONG   ulDacType;              // DAC type
    PVOID   volatile pvRomBaseAddr; // Mapped logical base address of ATI ROM
    PVOID   volatile pvMmr;         // Linear base addr of memmapped registers
    PVOID   pvCailBridgeBase;
    PVOID   pvAdapterCapsPtr;
    ULONG   ulCailDDICaps[8];
    ULONG   ulBiosReservBlock;
    PVOID   pvVBiosRomImage;
    CAIL_MC_RANGE_BLOCK  sMCRangeBlock[CAIL_MAX_MEMTYPE];
}CAIL_ADAPTER_CONFIG_INFO,*PCAIL_ADAPTER_CONFIG_INFO;

/********************************************************************************************************
  The following structure should move into cail.h
*********************************************************************************************************/
typedef struct _CAIL_PCICFGDATA
{
   USHORT  VendorID;                       //offset 0
   USHORT  DeviceID;                       //offset 2
   USHORT  Command;                        //offset 4
   USHORT  Status;                         //offset 6
   UCHAR   RevisionID;                     //offset 8
   UCHAR   RegProgINF;                     //offset 9
   UCHAR   PCISubClass;                    //offset a
   UCHAR   byte_r_PCI_BASE_CODE;           //offset b
   UCHAR   byte_rw_PCI_CACHE_LINE;         //offset c
   UCHAR   byte_rw_PCI_LATENCY;            //offset d
   UCHAR   byte_r_PCI_HEADER;              //offset e
   UCHAR   byte_r_PCI_BIST;                //offset f
   ULONG   dword_rw_PCI_MEM_BASE;          //offset 10
   ULONG   dword_rw_PCI_IO_BASE;           //offset 14
   ULONG   dword_rw_PCI_REG_BASE;          //offset 18

   ULONG   PCI_RESERVED1[4];               //offset 1c - 2b

   ULONG   dword_r_PCI_ADAPTER_ID;         //offset 2c
   ULONG   dword_rw_PCI_BIOS_ROM;          //offset 30
   ULONG   dword_r_PCI_CAPBILITIES_PTR;    //offset 34

   ULONG   PCI_RESERVED2;                  //offset 38 - 3b

   UCHAR   byte_rw_PCI_INTERRUPT_LINE;     //offset 3c
   UCHAR   byte_rw_PCI_INTERRUPT_PIN;      //offset 3d
   UCHAR   byte_r_PCI_MIN_GRANT;           //offset 3e
   UCHAR   byte_r_PCI_MAX_LATENCY;         //offset 3f

   ULONG   PCI_RESERVED3[3];               //offset 40 - 4b

   ULONG   dword_w_PCI_ADAPTER_ID_W;       //offset 4c

   ULONG   PCI_RESERVED5[49];              //offset 50 - ff

} CAIL_PCICFGDATA, *PCAIL_PCICFGDATA;

typedef CAIL_PCICFGDATA CAIL_PCI_COMMON_CONFIG;

// flags for  dwPM_SavedFlags@_PM_WORKAROUND
#define PM_SAVED_MC_CHPIOCNTL_REGS                  0x00000001L
#define PM_SAVED_CORE_CLOCK_REGS                    0x00000002L
#define PM_SAVED_DISPLAY_CLOCK_REGS                 0x00000004L
#define PM_SAVED_PLL_PWRMT_CNTL_REGS                0x00000008L
#define PM_SAVED_CLK_PWRMT_CNTL_REGS                0x00000010L
#define PM_SAVED_CLOCK_PIN_REGS                     0x00000020L
#define PM_SAVED_MCLK_MISC_REGS                     0x00000040L
#define PM_SAVED_DISP_MISC_CNTL_REGS                0x00000080L
#define PM_SAVED_DISP_PWR_MAN_REGS                  0x00000100L
#define PM_SAVED_POWER_STATE_D1_PREPPED             0x00000200L
#define PM_SAVED_POWER_STATE_DX_PREPPED             0x00000400L
#define PM_SAVED_AGP_REGS                           0x00000800L
#define PM_SAVED_BIOS_SCRATCH_REGISTER              0x00001000L
#define PM_SAVED_MOBILEAGPPLLCNTL                   0x00002000L
#define PM_PROGRAMMED_CLKPINCNTL                    0x00004000L
#define PM_SAVED_PROGRAMMED_CRTCOFFSETCNTL          0x00008000L
#define PM_PROGRAMMED_BUSCNTL1                      0x00010000L
#define PM_NORTHBRDIGE_PCISPACE_SAVED               0x00020000L
#define PM_SAVED_MISCREGS                           0x00040000L
#define PM_SAVED_PWRMGMT_REGISTERS                  0x00080000L
#define PM_SAVED_GUI_SCRATCH_REGISTER               0x00100000L
#define PM_SAVED_TMDS_TRANSMITTER_CNTL              0x00200000L

typedef struct _CAIL_PM_WORKAROUND
{
    CAIL_PCICFGDATA     NorthBridgeCfgData;
    ULONG Saved_BIOS_ScratchRegs[CAIL_ADAPTERDATA_MAX_BIOS_SCRATCH_REGS];   // BIOS scratch register
    ULONG Saved_GUI_ScratchRegs[CAIL_ADAPTERDATA_MAX_GUI_SCRATCH_REGS];     // GUI scratch register 
    ULONG Saved_DISP_MISC_CNTL;
    ULONG Saved_SCLK_CNTL;
    ULONG Saved_MCLK_CNTL;
    ULONG Saved_VCLK_ECP_CNTL;
    ULONG Saved_PIXCLKS_CNTL;
    ULONG Saved_PLL_PWRMGT_CNTL;
    ULONG Saved_CLK_PWRMGT_CNTL;
    ULONG Saved_CLK_PIN_CNTL;
    ULONG Saved_MCLK_MISC;
    ULONG Saved_DISP_PWR_MAN;
    ULONG Saved_LVDS_GEN_CNTL;
    ULONG Saved_LVDS_PLL_CNTL;
    ULONG Saved_LVDS_SS_GEN_CNTL;
    ULONG Saved_SCLK_MORE_CNTL;
    ULONG Saved_MC_CHP_IO_CNTL_A1;
    ULONG Saved_MC_CHP_IO_CNTL_B1;
    ULONG Saved_MC_CHP_IO_CNTL_C1;
    ULONG Saved_MC_CHP_IO_CNTL_D1;
    ULONG Saved_SS_TST_CNTL;
    ULONG Saved_OV0_BASE_ADDR;
    ULONG Saved_Agp_Base;
    ULONG Saved_Agp_Cntl;
    ULONG Saved_U1_PWRMAN_MISC;
    ULONG Saved_BUS_CNTL1;
    ULONG Saved_CRTC_OFFSET_CNTL;
    ULONG Saved_TMDS_TRANSMITTER_CNTL;
    ULONG dwPM_SavedFlags;

} CAIL_PM_WORKAROUND, *PCAIL_PM_WORKAROUND;

// HW_CAIL_EXTENSION
typedef struct _HW_CAIL_EXTENSION
{

    ULONG   ulSize;
    PVOID   strCailVersion;
    PVOID   hDevice;                    //  in NTx, PHW_DEVICE_EXTENSION, in 9x, PVXDINFO

   
    CAIL_DRV_CALLBACKS  cailDrvCallbacks;       // Callbacks for display driver services

    CAIL_PCI_CONFIG_SPACE   NorthBridgeInfo;         // Northbridge information
    ULONG                   ulNorthBridgeSlotNumber; // Northbridge slot number BnDnFn

    CAIL_PCI_CONFIG_SPACE   SouthBridgeInfo;         // Southbridge information
    ULONG                   ulSouthBridgeSlotNumber; // Southbridge slot number BnDnFn

    CAIL_ADAPTER_CONFIG_INFO ATIAdapterInfo;         // Adapter information

    CAIL_CONTROL_REG_INFO   AdapterControlData;

    CAIL_PM_WORKAROUND      Saved_Registers;
                                    // System info
    ULONG   ulSystemFlags1;         // General system flags
    ULONG   ulSystemType;           // Identifier, eg, 440BX
                                    // ACPI Status
    ULONG   ulCurrentPowerState;
    ULONG   ulPreviousPowerState;
    ULONG   ulAdapterStateFlags;    // Flags for various attributes
    ULONG   ulFlagFromCailFor2D[4];     // Disable Flag from Cail driver for 2D to use

    CAIL_CONTROL_DEBUG_LEVEL    DebugLevelCNTL;     // control the output message level
    ULONG   ulPadding[3];           // May need to be changed to keep 64 bits
} HW_CAIL_EXTENSION, *PHW_CAIL_EXTENSION;


//I2C Extension
typedef struct _CAIL_I2C
{
    ULONG                   ulSize;
    ULONG					ulLine;      // Select the I2C line
    ULONG					ulAddress;   // The address to send the data onto the bus
    ULONG					ulOffset;    // The offset from the base address
    ULONG					ulAction;    // The Read Write option
    ULONG					ulSpeed;     // Select the I2C bus speed
    PUCHAR					pDataBuffer; // Pointer to the start of the data buffer
    ULONG					ulBufSize;   // Size of the buffer
} CAIL_I2C, *PCAIL_I2C;

// For Query BIOS Reserve Frame buffer block
typedef struct CAIL_BIOS_RESERVE_BLOCK {
    ULONG                       dwIndex;
    ULONG                       dwOffset;
    ULONG                       dwSize;
} CAIL_BIOS_RESERVE_BLOCK, *PCAIL_BIOS_RESERVE_BLOCK;

typedef struct _CAIL_PARSER_TABLE_CONTEXT
{
    ULONG   ulSize;
    ULONG   dwTableIndex;           // indicate index of Command table
    PVOID   pvParaPtr;              // Parameter space pointer
    ULONG   ulParserResult;         // Save the result from Parser
} CAIL_PARSER_TABLE_CONTEXT, *PCAIL_PARSER_TABLE_CONTEXT;

// Sychronization Priority
typedef enum CAIL_VSYNC_PRIORITY {
    CAIL_LOW_PRIORITY,
    CAIL_MEDIUM_PRIORITY,
    CAIL_HIGH_PRIORITY
} CAIL_VSYNC_PRIORITY;

#define CAIL_ASIC_SHUTDOWN_TURN_OFF_LCD     0x00000001L


#define CAIL_OCADATA_DMA_SNAP    256
#define CAIL_OCADATA_CSQ_SNAP    16

typedef struct _CAIL_BUGCHECK_DATA {

    //
    // Hardware readouts.
    //  TODO: Investigate, if there is a safe way to get to this data even in the case of a messed up bus interface.
    //      Store more registers of interest.
    //      Make this data ASIC specific.
    //

    ULONG   ulRBBM_STATUS;                          // preserves the busy status of the different components

    ULONG   ulCP_RB_RPTR;                           // helps figuring out wraparound problems
    ULONG   ulCP_RB_WPTR;                           // 

    ULONG   ulCP_IB_BUFSZ;
    ULONG   ulCP_CSQ_STAT;

    ULONG   ulaCSQBuffEntries[CAIL_OCADATA_CSQ_SNAP]; //

    ULONG   ulaCmdBuffEntries[CAIL_OCADATA_DMA_SNAP]; // some historic cmd data that can be analyzed
} CAIL_BUGCHECK_DATA , *PCAIL_BUGCHECK_DATA;


/****************************************************************************\
* Function prototypes - Entry points
\****************************************************************************/

ULONG CAILGetExtensionSize(void);

// CAILInitialize
CAILRESULT  
CAILInitialize(
    IN  PHW_CAIL_EXTENSION       hCAIL,
    IN  PCAIL_INIT               lpCail_init);

// CAILResetAndInitializeGUI
CAILRESULT
CAILResetAndInitializeGUI(
    PHW_CAIL_EXTENSION       hCAIL
);

// CAILNoBiosInitializeAdapter
CAILRESULT
CAILNoBiosInitializeAdapter(
    PHW_CAIL_EXTENSION hCAIL,
    PVOID pvMmr,
    PHYSICAL_ADDRESS *plfbPhysicalAddress
);
// CAILQuerySystemInfo
CAILRESULT
CAILQueryASICInfo(
    PHW_CAIL_EXTENSION          hCAIL,
    PCAIL_ADAPTER_INFO          pAdapterInfo
);

CAILRESULT
CAILQuerySystemInfo(
    PHW_CAIL_EXTENSION      hCAIL,
    PCAIL_SYSTEMINFO        SystemChipInfo
);

// CAILFixChipsetBugs
CAILRESULT
CAILFixChipsetBugs(
    PHW_CAIL_EXTENSION       hCAIL
);

void Cail_Powerdown(PHW_CAIL_EXTENSION  hCAIL,
                    ULONG               ulPowerState);

void Cail_Powerup(PHW_CAIL_EXTENSION  hCAIL);


CAILRESULT CAIL_ASICSetup(PHW_CAIL_EXTENSION  hCAIL);

CAILRESULT CAIL_QueryBIOSReserveFB(
           PHW_CAIL_EXTENSION       hCAIL,
           PCAIL_BIOS_RESERVE_BLOCK pvBIOSReserve);


CAILRESULT CAILReserveMCAddressRange(
    IN      PHW_CAIL_EXTENSION      hCAIL,
    IN      PCAIL_MC_RANGE_BLOCK    pMCBlock,
    IN      ULONG                   ulFlags);

CAILRESULT CAILQueryMCAddressRange(
    IN      PHW_CAIL_EXTENSION      hCAIL,
    IN      PCAIL_MC_RANGE_BLOCK    pMCBlock,
    IN      ULONG                   ulMemType);

CAILRESULT  CAIL_InitAdditionInfo(
    IN      PHW_CAIL_EXTENSION      hCAIL, 
    IN      ULONG                   ulFlag,
    IN      ULONG_PTR               ulInfo);

ULONG_PTR   CAIL_QueryAdditionInfo(
    IN      PHW_CAIL_EXTENSION      hCAIL, 
    IN      ULONG                   ulFlag);

BOOL CAIL_GetGuiStatus(PHW_CAIL_EXTENSION    hCAIL);

VOID CAIL_AsicShutDown(
     PHW_CAIL_EXTENSION         hCAIL,  
     ULONG                      ulShutDownOption);

VOID CAIL_ReadHardwareStatus(
           PHW_CAIL_EXTENSION       hCAIL, 
           PCAIL_BUGCHECK_DATA      pBugcheckdata);
/******************************, ULONG ulPowerState)**********************************************/


/****************************************************************************\
* Macros definitions
\****************************************************************************/

#define CailSetCaps(addr,c)       ( addr[(c/32)] |=  ((DWORD)(1) << (c & 0x1F)) )
#define CailUnSetCaps(addr,c)     ( addr[(c/32)] &=  ((DWORD)(-1) - ((DWORD)(1) << (c & 0x1F))) )
#define CailCapsEnabled(addr,c)   ( addr[(c/32)] &   ((DWORD)(1) << (c & 0x1F)) )

/****************************************************************************/

#if defined(_X86_)
#pragma pack()
#endif

#ifdef __cplusplus
}
#endif

#endif // _CAIL_H


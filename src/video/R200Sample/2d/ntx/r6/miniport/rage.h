

/*****************************************************************************\
* 
*  Module Name    RAGE.H
*  Project        Longhorn
*  Device         R200
*
*  Description    Contains defines, macros, and definition of the
*                 HW_DEVICE_EXTENSION which is integral to the miniport.
*
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
\*****************************************************************************/

#ifndef _RAGE_H_
#define _RAGE_H_

#ifndef _DISPMPRT_H_
#include <dispmprt.h>
#endif

#include "MultiEngine.h"

// Forward-declare PEVENT according to a new makefile flag.
// Note: PEVENT is defined differently in winddi.h (included by CMM and Display Driver)
// and video.h (included by the Miniport) because of its 'opaqueness'.
#ifndef _NTDDVDEO_
#ifndef _WINDDI_
typedef struct _VIDEO_PORT_EVENT *PEVENT;
#endif
#endif

//
// Define typedefs to be used throughout the miniport.
//
#ifdef BOOL
    #undef BOOL
#endif

#ifdef DWORD
    #undef DWORD
#endif

#ifdef PDWORD
    #undef PDWORD
#endif

#ifndef _WINDEF_
typedef unsigned long   BOOL;
typedef unsigned long   DWORD;
typedef unsigned long  *PDWORD;
#endif

#include "ragent.h"
#include "atiid.h"

//////////////////////////////////////////////////////////////////
// Common memory heap definitions....
//////////////////////////////////////////////////////////////////
// Signature to validate a given pMHP (combined pools) structure is
// valid!  Note, this is just a random bit pattern....
#define MHP_COMBINED_POOLS_SIGNATURE        0x03700730

// flags for the MEMHEAP structures below...

// TODO:  this will have to get re-organized at some point based on
//        the frequency of allocations done from each memory type.
//
// Constants used as indices into the mhpIndividualPools array
#define MHP_POOL_TYPE_AGP                    0
#define MHP_POOL_TYPE_FRAME_BUFFER           1
#define MHP_POOL_TYPE_FRAME_BUFFER_INVISIBLE 2
#define MHP_POOL_TYPE_ATI_AGP                3
#define MHP_POOL_TYPE_PCI_GART               4
#define MHP_POOL_TYPE_ATI_PCI                MHP_POOL_TYPE_PCI_GART
#define MHP_POOL_TYPE_NON_PAGEABLE           5
#define MHP_POOL_TYPE_PAGEABLE               6
#define MHP_POOL_TYPE_NUM_TYPES              7
#define MHP_POOL_TYPE_MASK              ((1 << MHP_POOL_TYPE_NUM_TYPES) - 1)
// Note: See HeapStr in cmm.c

// Used in the dwMHP_MemProperties field of each pool structure.
#define MHP_MEM_PROPERTIES_USWC         0x00000001
#define MHP_MEM_PROPERTIES_UC           0x00000002

/** Base address starting value for invisible frame buffer heap.
  * This address must be non-NULL as it would indicate "not found" in 
  * a lot of the code.
  */
#define MHP_BASE_ADDRESS_INVISIBLE      0x00000001

// Flag values used in the MEMHEAP_COMBINED_POOL dwMiniportFlags field.
// Power Mgt signals...
#define MHP_POWER_RESTORE_QS            0x00000001
#define MHP_POWER_RECOVER_SURFACES      0x00000002

// This defines the size of the scratch nonpageable memory allocated by the
// miniport once for use by the display driver use.  
// In particular, this memory will be used for ASIC writebacks 
// (RPTR & TimeStamps). [RA]
// Just 1 page for now, since only used for ASICBLOCK definitions.
#define MHP_NUM_SCRATCH_NONPAGEABLE_PAGES   2

#define MHP_CAP_HPROCESS_GETINFO        0x00000004

// Miniport sets this to indicate it supports PCI GART entries
// to be reusable.
#define MHP_CAP_POWERDOWN_CALLBACK      0x00000010

typedef struct _MEMHEAP_COMBINED_POOL   MEMHEAP_COMBINED_POOL;

typedef void (*PFN_MHP_ASIC_POWERDOWN) (MEMHEAP_COMBINED_POOL *pMHP);


// A MEMHEAP Pool constitutes a logical set of memory.
typedef struct _MEMHEAP_POOL
{
    // The host CPUs idea of the physical address for this pool.  This can not
    // use the "PHYSICAL_ADDRESS" type since that is only defined for miniport
    // compilations.  However, this is exactly the same structure, so it works.
    // Set by the miniport.
    LARGE_INTEGER  physMHP_HostBaseAddr;

    // Pointer to buffer.  Set by the miniport.
    PVOID          pvMHP_CPU_BaseAddr;

    // The total number of bytes accessible from this pool.  Set by the miniport.
    DWORD          dwMHP_TotalBytes;

    // Memory controller base address for this pool.  Set by the miniport.
    DWORD          dwMHP_ASIC_BaseAddr;

    // Pointer to the next pool of the same memory type.  Note for the time being
    // we are keeping this here so the miniport can still determine the total
    // size of the allocated pools...  When / if this is resolved, this field
    // should move back into the private-info field of the pool structure, so 
    // do not access this directly...
    struct _MEMHEAP_POOL   *pMHP_nextPool;

    // Flags that specify the characteristics of the memory associated with
    // this pool.  Set by the miniport...
    DWORD          dwMHP_MemProperties;

} MEMHEAP_POOL, *PMEMHEAP_POOL;

//////////////////////////////////////////////////////////////////
//    Note, this structure stores all the required information for
// CMM functionality.
//    A MEMHEAP_COMBINED_POOL contains information on all the
// memory available in the system.  Whoever allocates this structure
// should ensure that the base address of the structure resides on
// a CPU cache line boundary, as the individual pools array is optimized
// to start on a cache-line boundary as well.

// Forward declare private structures
struct _BIOS_RESERVE_ENTRY;

typedef struct _MEMHEAP_COMBINED_POOL 
{
    /** See the MHP_POOL_TYPE_* constants for the allowable indices into
        the mhpIndividualPool[] array.*/
    MEMHEAP_POOL                mhpIndividualPool[MHP_POOL_TYPE_NUM_TYPES];

    /** Frame buffer memory to reserve for BIOS. Set by the miniport.*/
    struct _BIOS_RESERVE_ENTRY  *pBIOSReserve;

    /** Rate of the AGP bus (1x, 2x, 4x, 8x)*/
    DWORD                  dwAgpRate;

    /** Flags that communicate information from the miniport. Set by the miniport.*/
    DWORD                  dwMiniportFlags;

    /** The size, in pages, of miniport-committed AGP memory.*/
    DWORD                  dwPreCommittedAGPsize;

    PFN_MHP_ASIC_POWERDOWN pfnMHP_power_down_callback;

    DWORD                  dwMHP_signature;

#ifdef LHVIDMM
    //
    // Part of the frame buffer and AGP aperture are reserved 
    // by the miniport for the new Longhorn memory manager
    //
    DWORD                  dwVidMmPoolSizes[MHP_POOL_TYPE_NUM_TYPES];
#endif

} MEMHEAP_COMBINED_POOL, *PMEMHEAP_COMBINED_POOL;



#include "asiccaps.h" 

typedef VOID (* PFN_RESET_HW) (PVOID pHwDeviceExtension);
typedef LONG (* PFN_INT10) (PVOID pHwDeviceExtension,PVOID pBiosArgument);
typedef VOID (* PFN_SET_VIDEO_MUX) (PVOID pHwDeviceExtension, ULONG ulIndex);
typedef BOOLEAN (* PFN_SET_FP_INT) (PVOID pHwDeviceExtension, ULONG ulIndex);
typedef VOID (* PFN_TURN_OFF_CURSOR) (PVOID pHwDeviceExtension);
typedef VOID (* PFN_IS_HOTPLUGABLE) (PVOID pvMmr);
typedef BOOL (* PFN_APERTURE_MAPPING) (PVOID pvMmr);
typedef VOID (* PFN_PROGRAM_SCK_PRESCALE1)  (PVOID pvMmr, DWORD sck_prescale);
typedef VOID (* PFN_SET_INT_CLEAR) (PVOID pvMmr);
typedef BOOL (* PFN_PM4INT_ACK) (PVOID pHwDeviceExtension);
typedef BOOL (* PFN_PM4INT_ENABLE) (PVOID pHwDeviceExtension, DWORD IRQSource);
typedef BOOL (* PFN_PM4INT_DISABLE) (PVOID pHwDeviceExtension, DWORD IRQSource);

#ifndef _DAL_H

#define MAX_NUMBER_CONTROLLERS       2
#define MAX_NUMBER_DISPLAYS          7
#define DAL_GCO_MEMSEG_MIN_INDEX                       0
#define DAL_GCO_MEMSEG_MAX_INDEX                       (DAL_GCO_MEMSEG_MIN_INDEX+MAX_NUMBER_CONTROLLERS-1)
#define DAL_GDO_MEMSEG_MIN_INDEX                       (DAL_GCO_MEMSEG_MAX_INDEX+1)
#define DAL_GDO_MEMSEG_MAX_INDEX                       (DAL_GDO_MEMSEG_MIN_INDEX+MAX_NUMBER_DISPLAYS-1)
#define DAL_MAX_MEMSEG_ALLOCATION                      (DAL_GDO_MEMSEG_MAX_INDEX+1)

typedef struct _DALMEMSEG
{
  ULONG  ulSize;
  VOID *lpMem;
} DALMEMSEG, FAR *LPDALMEMSEG;

typedef struct _SDALMEM
{
  ULONG     ulSize;
  ULONG     ulNumEntries;
  DALMEMSEG aMemSeg[DAL_MAX_MEMSEG_ALLOCATION];
} SDALMEM, FAR *LPDALMEM;

#endif

#define SGT_PAGE_SIZE            0x1000 
#define INTERNAL_REV_UNKNOWN    0xFF


    #ifndef _DWORD_DEFINED
        #define _DWORD_DEFINED
        typedef ULONG DWORD;
    #endif  // !defined _DWORD_DEFINED

    #include "dxmini.h"
    // #include "ntstatus.h"
    #include "videoagp.h"

    #define NTSTATUS    LONG

    #ifndef NT_SUCCESS
        #define NT_SUCCESS(ntStatus) ((NTSTATUS)(ntStatus) >= 0)
    #endif  // !defined NT_SUCCESS

    #ifndef IsEqualGUID
        #define IsEqualGUID(guid1, guid2) (RtlCompareMemory((guid1), (guid2)) == sizeof (GUID)))
    #endif // !defined IsEqualGUID

//
// Define DAC types -- they match values used by ATI Video BIOS.
//
#define DAC_ATI_INTERNAL            0x00000000

//
// Define miscellaneous values.
//
#define ONE_K                       0x00000400UL        // 1KB
#define HALF_MEG                    0x00080000UL        // 512KB
#define ONE_MEG                     0x00100000UL        // 1MB
#define NOT_INIT_FEATURE_FLAGS      0x00000000          // Invalid value
#define NOT_INIT_MEMTYPE            0xFFFFFFFF          // Invalid value
#define NOT_INIT_DAC_TYPE           0xFFFFFFFF          // Invalid value
#define NOT_INIT_DISABLE_FLAGS      0xFFFFFFFF          // Invalid value
#define MAX_PATHNAME                256                 // Max number of char for the driver specific registry path
#define FORCED_AGP_ALIGNMENT        0xFFC00000          // AGP alignment must be 4MB
#define POOL_ALIGNMENT              0x100               // minimum alignment of contiguous memory allocations for pools
#define MAX_MESSAGECODES            8                   // Size of the message code queue
#define MESSAGECODE_POOLSIZE        256                 // Size of the message code memeory pool in bytes
#define MAX_AGP_SIZE                0x4000000           // 64M. 

#include "devenum.h"

#ifdef CMMQSMP

typedef unsigned char BYTE;
typedef unsigned char *LPBYTE;
typedef unsigned long *LPDWORD;

#ifndef _WINDEF_
typedef void *HWND;
typedef void *HDEV;
typedef struct _RECTL       /* rcl */
{
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECTL, *PRECTL, *LPRECTL;
#endif


#include "ring.h"

#ifndef _NTDDVDEO_
typedef struct _VIDEO_MODE_INFORMATION {
    ULONG Length;
    ULONG ModeIndex;
    ULONG VisScreenWidth;
    ULONG VisScreenHeight;
    ULONG ScreenStride;
    ULONG NumberOfPlanes;
    ULONG BitsPerPlane;
    ULONG Frequency;
    ULONG XMillimeter;
    ULONG YMillimeter;
    ULONG NumberRedBits;
    ULONG NumberGreenBits;
    ULONG NumberBlueBits;
    ULONG RedMask;
    ULONG GreenMask;
    ULONG BlueMask;
    ULONG AttributeFlags;
    ULONG VideoMemoryBitmapWidth;
    ULONG VideoMemoryBitmapHeight;
    ULONG DriverSpecificAttributeFlags;
} VIDEO_MODE_INFORMATION, *PVIDEO_MODE_INFORMATION;
#endif

#endif

#define IS_VGA_ENABLED(p) \
    (ASSERT(NULL != (p)), (p)->bVgaEnabled)

#define IS_ROM_READABLE(p) \
    (ASSERT(NULL != (p)), (NULL == (p)->pvRomBaseAddress) ? FALSE : TRUE)

#define IS_DMA_DISABLED(p) \
    (ASSERT(NULL != (p)), ASSERT(NOT_INIT_DISABLE_FLAGS != (p)->ulDisableFlags), \
    ((p)->ulDisableFlags & PDEV_DISABLE_DMA) ? TRUE : FALSE)

#define IS_VIDEOUSWC_DISABLED(p) \
    (ASSERT(NULL != (p)), ASSERT(NOT_INIT_DISABLE_FLAGS != (p)->ulDisable2Flags), \
    ((p)->ulDisable2Flags & PDEV_DISABLE2_VIDEOUSWC) ? TRUE : FALSE)

#define IS_USWCAGP_DISABLED(p) \
    (ASSERT(NULL != (p)), ASSERT(NOT_INIT_DISABLE_FLAGS != (p)->ulDisable4Flags), \
    ((p)->ulDisable4Flags & PDEV_DISABLE4_USWCAGP) ? TRUE : FALSE)

#define IS_MMLIB_DISABLED(p) \
    (ASSERT(NULL != (p)), ASSERT(NOT_INIT_DISABLE_FLAGS != (p)->ulDisable4Flags), \
    ((p)->ulDisable4Flags & PDEV_DISABLE4_MMLIB) ? TRUE : FALSE)

#define IS_MULTIMONENUM_DISABLED(p) \
    (ASSERT(NULL != (p)), ASSERT(NOT_INIT_DISABLE_FLAGS != (p)->ulDisable3Flags), \
    ((p)->ulDisable3Flags & PDEV_DISABLE3_MULTIMONENUM) ? TRUE : FALSE)

#define IS_DAL_VALIDATECHILD_DISABLED(p) \
    (ASSERT(NULL != (p)), ASSERT(NOT_INIT_DISABLE_FLAGS != (p)->ulDisable4Flags), \
    ((p)->ulDisable4Flags & PDEV_DISABLE4_DALVALIDATECHILD) ? TRUE : FALSE)

#define IS_ENUM_INACTIVE_DISPLAYS_DISABLED(p) \
    (ASSERT(NULL != (p)), ASSERT(NOT_INIT_DISABLE_FLAGS != (p)->ulDisable3Flags), \
    ((p)->ulDisable3Flags & PDEV_DISABLE3_ENUMALLCHILDS) ? TRUE : FALSE)

#define IS_PM4TSINTERRUPT_DISABLED(p) \
    (ASSERT(NULL != (p)), ASSERT(NOT_INIT_DISABLE_FLAGS != (p)->ulDisable4Flags), \
    ((p)->ulDisable4Flags & PDEV_DISABLE4_PM4TSINTERRUPT) ? TRUE : FALSE)

#define IS_ONEMONITOR_ENUMERATED(p) \
    (ASSERT(NULL != (p)), (p)->bOneMonEnumerated)

#define SET_ONEMONITOR_ENUMERATED(p) \
    {\
        if (NULL != p) \
            p->bOneMonEnumerated = TRUE; \
    }

#define RESET_ONEMONITOR_ENUMERATED(p) \
    {\
        if (NULL != p) \
            p->bOneMonEnumerated = FALSE; \
    }

#define IS_SUPPORTED_MULTIFUNCTION_DEVICE(PciCommonConfig) \
   ( (\
        PciCommonConfig.HeaderType & PCI_MULTIFUNCTION && \
        (\
            (PciCommonConfig.DeviceID == DEVICE_ID_RADEON200_QL) || \
            (PciCommonConfig.DeviceID == DEVICE_ID_RADEON200_QM) || \
            (PciCommonConfig.DeviceID == DEVICE_ID_IRIS_IF)      || \
            (PciCommonConfig.DeviceID == DEVICE_ID_ARGUS_5960)   || \
            (PciCommonConfig.DeviceID == DEVICE_ID_ARGUS_5961)   || \
            (PciCommonConfig.DeviceID == DEVICE_ID_ARGUS_5962)   || \
            (PciCommonConfig.DeviceID == DEVICE_ID_ARGUS_5964)   || \
            (PciCommonConfig.DeviceID == DEVICE_ID_IRIS_IG)      || \
            (PciCommonConfig.DeviceID == DEVICE_ID_IRIS_LG) \
        )\
     )\
      ? TRUE : FALSE \
   )

#define IS_DESKTOP_EXTENDED(p) \
    ( \
        ((ASSERT(NULL != (p)))), \
        ( \
            (NULL == ((p)->pvHwOtherDevExt)) ? FALSE : \
            (((p)->ulMultiCrtcFlags & HW_MCRTC_VIEW_ENABLED) && \
            (((PHW_DEVICE_EXTENSION)(p)->pvHwOtherDevExt)->ulMultiCrtcFlags & HW_MCRTC_VIEW_ENABLED)) \
        ) \
    )
    
#define GET_AGP_ENABLED_HDE(pCurrentHde) \
    ( \
       ((ASSERT(NULL != (pCurrentHde)))), \
       ( pCurrentHde->ulFeatureFlags & FEATURE_AGPENABLE ? pCurrentHde : pCurrentHde->pvHwOtherDevExt )\
    )

#define PCI_PAGES_RESERVED_FOR_DMA              4097

#define NUM_OF_GPIO_PINS                        3
#define NUM_OF_PINS_IN_BYTES                    1
#define MAXDDTRANSFERJOBS                       11

//
// Used to store away parameters for freeing memory allocated by AllocateCommonBuffer
//

typedef struct _COMMON_ALLOC
{
    PHYSICAL_ADDRESS    paPhysicalAddress;
    PVOID               pvLinearAddress;
    ULONG               ulBlockSize;
}   COMMON_ALLOC, *PCOMMON_ALLOC;

typedef struct _PM_STATEINFO
{
    ULONG Saved_SCLK_CNTL;
    ULONG Saved_MCLK_CNTL;
    ULONG Saved_VCLK_ECP_CNTL;
    ULONG Saved_PIXCLKS_CNTL;
    ULONG Saved_SCLK_MORE_CNTL;
    ULONG Saved_MCLK_MISC;
    ULONG Saved_SS_TST_CNTL;
    ULONG Saved_MC_CHP_IO_CNTL_A1;
    ULONG Saved_MC_CHP_IO_CNTL_B1;
    ULONG Saved_MC_CHP_IO_CNTL_C1;
    ULONG Saved_MC_CHP_IO_CNTL_D1;
    BOOL bSavedMcChpIoCntl;
    BOOL bSavedCoreClocks;
    BOOL bSavedDisplayClocks;
    BOOL bPwrStateDXPrepped;
    BOOL bPwrStateD1Prepped;
    BOOL bPMRegsInitialized;
} PM_STATEINFO, *PPM_STATEINFO;

typedef struct _HPD_DATA
{
    ULONG   ulInterruptBitmap;
    DWORD_PTR   dwIRQEnableId;
    BOOL    bPanelConnectivityState;
    PVOID   pvInterruptEvent;
} HPD_DATA, *PHPD_DATA;

typedef struct _LVDS_REGS
{
    ULONG LVDS_GEN_CNTL;
    ULONG LVDS_PLL_CNTL;
    ULONG LVDS_SS_GEN_CNTL;
} LVDS_REGS, *PLVDS_REGS;

typedef struct _MESSAGECODE
{
  ULONG MessageCode;
  ULONG BufferSize;
} MESSAGECODE;

typedef struct _R2AllocationInfo *PR2AllocationInfo;

typedef struct _TILED_SURFACE_INFO
{
    BOOL                bEnabled;
    PR2AllocationInfo   pSurfData;
}TILED_SURFACE_INFO, *PTILED_SURFACE_INFO;

typedef struct _DESIRED_CHILD_STATUS
{
    BOOL                bActive;
    ULONG               ulSourceId;
    ULONG               ulTargetId;
} DESIRED_CHILD_STATUS, *PDESIRED_CHILD_STATUS;


//
// Define HW_DEVICE_EXTENSION -- device dependant, per adapter information.
//
typedef struct _HW_DEVICE_EXTENSION
{
    ULONG ulChipFamily;                           // Chip family ID
    USHORT usDeviceId;                            // Device ID (PCI space and CONFIG_CHIP_ID)
    UCHAR ucRevision;                             // Device Revision (PCI space and CONFIG_CHIP_ID)
    UCHAR ucAtiExternalRev;                       // ATI's External (or Major) Revision
    ULONG ulAtiInternalRev;                       // ATI's Internal Revision
    USHORT usSubVendorId;                         // PCI Sub-vendor Id
    USHORT usSubSystemId;                         // PCI Sub-system Id
    PCI_SLOT_NUMBER PciSlotNumber;                // Slot number for this adapter
    BOOL bVgaEnabled;                             // TRUE if adapter is VGA enabled
    UCHAR ucAgpRate;                              // AGP level the adapter is running at
    UCHAR ucAgpRevision;                          // AGP Revesion. AGP 2.0 versus AGP 3.0 interface support. 

    PHYSICAL_ADDRESS lfbPhysicalAddress;          // Base physical address of LFB aperture
    PHYSICAL_ADDRESS ioPhysicalAddress;           // Base physical address of I/O aperture
    PHYSICAL_ADDRESS mmPhysicalAddress;           // Base physical address of MM aperture
    PHYSICAL_ADDRESS vgaPhysicalAddress;          // Base physical address of VGA aperture
    PHYSICAL_ADDRESS romPhysicalAddress;          // Base physical address of ATI ROM
    PHYSICAL_ADDRESS agpPhysicalAddress;          // Base physical address of AGP aperture
    PHYSICAL_ADDRESS lfbMemoryControllerAddress;  // Physical address (in terms of the memory controller) of the LFB
    PHYSICAL_ADDRESS gartMemoryControllerAddress; // Physical address (in terms of the memory controller) of the GART
    PHYSICAL_ADDRESS agpMemoryControllerAddress;  // Physical address (in terms of the memory controller) of AGP

    PVOID pvLfbBaseAddress;                       // Mapped logical base address of LFB aperture
    PVOID pvIoBaseAddress;                        // Mapped logical base address of I/O aperture
    PVOID pvMmr;                                  // Mapped logical base address of MM aperture
    PVOID pvVgaBaseAddress;                       // Mapped logical base address of VGA aperture
    PVOID pvVgaIo1BaseAddress;                    // Mapped logical base address of 1st VGA I/O aperture
    PVOID pvVgaIo2BaseAddress;                    // Mapped logical base address of 2nd VGA I/O aperture
    PVOID pvRomBaseAddress;                       // Mapped logical base address of ATI ROM
    PVOID pvBroadcastDispChangeEvent;             // Event to notify polling app of display change event
    PVOID pvBridgeBaseAddress;                    // Mapped logical base address of Bridget registers

    ULONG ulLfbLength;                            // Length in bytes of LFB aperture
    ULONG ulLfbInvisibleLength;                   // Length in bytes of Invisible FB aperture
    ULONG ulIoLength;                             // Length in bytes of I/O aperture
    ULONG ulMmLength;                             // Length in bytes of MM aperture
    ULONG ulVgaLength;                            // Length in bytes of VGA aperture
    ULONG ulRomLength;                            // Length in bytes of ATI ROM
    ULONG ulFBMappedSize;                         // Length in bytes of Video Memory Mapped.

    ULONG ulRomHeaderOffset;                      // Offset of ATI ROM header from beginning of ROM image

    USHORT usXclkFreq;                            // XCLK freq (internal if SDR 2:1 mem)(Hz/10000)
    USHORT usMclkFreq;                            // MCLK (engine) freq
    ULONG usMclkMaxFreq;                          // MCLK reference freq (Hz/10000)
    ULONG usXclkMaxFreq;                          // XCLK reference freq (Hz/10000)
    USHORT usRefFreq;                             // PLL reference freq (Hz/10000)

    ULONG ulPageSize;                             // size of the operating systems memory pages
    ULONG ulVRamSizeInstalled;                    // Size in bytes of installed video memory
    ULONG ulVRamSizeAvailable;                    // Size in bytes of available video memory
    ULONG ulVRamType;                             // Type of installed video memory
    ULONG ulVRamBitWidth;                         // One of {32, 64, 128}

    MEMHEAP_COMBINED_POOL   *pMHP_info;           // General information for CMM support

#ifdef CMMQSMP
    PVOID                   pQs;
    VIDEO_MODE_INFORMATION  curModeInfo[2];
    ULONG                   ulFlipFlags[2];
    ULONG                   curPrimaryOffset[2];
#endif

    ULONG                   ulCursorFlags[2];     // Cursor flag for each CRTC

    PHYSICAL_ADDRESS        agpApertureBase;
    LARGE_INTEGER           agpApertureSize;

    //
    // BUGBUG: Fix the header so that d3dukmdt.h can be included
    //
    VOID (*pVidSchINTCB)();                       // Scheduler INT callback
    VOID (*pVidSchDPCCB)();                       // Scheduler DPC callback

    ULONG ulRequiredDmaQueueEntry;                // number of queue entry

    DXGKRNL_INTERFACE ddiCallback;                // Kernel runtime callbacks

    ULONG ulDacType;                              // Type of DAC

    PVOID pvhDal;                                 // Dal Device Handle

    PVOID hCAIL;                                  // Pointer to CAIL instance

    PVOID pvMMLib;                                // MMLib Device Handle
    PVOID pvMMLibMemoryBlock1;
    PVOID pvMMLibMemoryBlock2;
    ULONG ulMMLibMemoryBlock1Size;
    ULONG ulMMLibMemoryBlock2Size;

    ULONG ulMMLibReservedApertureSize;            // Size of AGP memory MMLIB allocates 

    PVOID pDDL;                                   // DAL's pointer to HwDeviceExtension

    ULONG ulDisableFlags;                         // Set according to the registry DB
    ULONG ulDisable2Flags;                        // Set according to the registry DB
    ULONG ulDisable3Flags;                        // Set according to the registry DB
    ULONG ulDisable4Flags;                        // Set according to the registry DB
    ULONG ulMMLibDisableFlags;                    // Set according to the registry DB
    CONTROL_DATA ControlData;                     // Set according to the registry DB (>1 bit)

    ULONG ulFeatureFlags;                         // Adapter specific feature flags
    ULONG ulHardwareChange;                       // Used to flag adapter/monitor changes
    ULONG ulAsicBugs;                             // Hardware bit flags for SW bug fixes
    ULONG ulNumberOfLookupModes;                  // Total number of modes determined to be available

    USHORT usNbVendorId;                          // Northbridge Vendor ID
    USHORT usNbDeviceId;                          // Northbridge Device ID
    USHORT ucNbSlotNumber;                        // Northbridge slot number
    USHORT usSbVendorId;                          // Southbridge Vendor ID
    USHORT usSbDeviceId;                          // Southbridge Device ID
    USHORT ucSbSlotNumber;                        //. Southbridge slot number

    ULONG ulNBCaps;                               // capabilities of northbridge

    WCHAR wcDriverRegistryPath[MAX_PATHNAME];     // Driver specific registry path string in unicode

#ifdef _WIN64
    DWORD dwBytesLostOffFront;                    // the size we lopped off the front
#endif

    PHYSICAL_ADDRESS pAgpPhysicalAddress;         // physical AGP address
    PVOID pAgpVirtualAddress;                     // virtual AGP address

    PVOID pvMessageCodeEvent;                     // Event to notify polling app that we want to be heard
    MESSAGECODE MessageCodes[MAX_MESSAGECODES];   // Q of MessageCodes to return on CWDDE GetLastMessageCode
    UCHAR ucMessagePool[MESSAGECODE_POOLSIZE];    // Memory pool for buffers associated with each message
    ULONG ulMessagePoolTop;                       // Index of top of the message pool
    UCHAR ucMessageQRead;                         // Read index
    UCHAR ucMessageQLen;                          // Queue length

    ULONG ulPciCapIdPtr;
    ULONG ulPciCapLength;

    ULONG ulaDisplayTypeVector[MAX_NUMBER_DISPLAYS]; // Stores DAL display vector bits where entry 0=CRT,1=TV,2=LCD,3=DFP, 4=CV
    ULONG ulAcpiDisplays;                         // Displays enumerated by the ACPI
    ULONG ulDPMSState;                            // Used to determine the DPMS states of display devices (each bit represent display)
    ULONG ulStoreDisplayIndex;                    // Store DisplayIndex for ACPI resume use
    ULONG ulAdapterPowerState;                    // Current power state of the video adapter

    PVOID pMMLibQueryInterface;
    PVOID pMMLibISR;
    PVOID pMMLibChildEnumeration;
    PVOID pMMLibEventNotificationCallback;
    PVOID pMMLibIoctlHandler;
    
    MMLIB_MEM_LOCATION                        MMLibMemLocation;

    ULONG       ulSwInterruptBitmap;              //bitmap for SW interrupt

    HPD_DATA aHPDData[MAX_NUMBER_DISPLAYS];
    ULONG    ulHPDEntries;
    PEVENT  eventHPD;
    KDPC    dpcOnMonitorHPD;

    BOOL    bModeDriverHandled;                   // TRUE if we handle current mode
    ULONG   ulEnabledDisplays;                    // Displays we want to use
    ULONG   ulNumberDisplays;                     // Number of displays supported by the adapter
    ULONG   ulConnectedDisplays;                  // Displays physically connected to the adapter
    ULONG   ulActiveDisplays;                     // See AtiGetVideoChildDescriptor: Bit vector of active displays
    ULONG   ulDisplaysOnSecondary;                // Active display on secondary controller
    BOOL    bDisplaySwitchAllowed;                // TRUE if a device switch is allowed
    BOOL    bOneMonEnumerated;                    // If multimonitor enumeration is disabled, only one monitor is allowed to be enumerated            

    ULONG ulDALSize;
    ULONG ulHDALSize;
    SDALMEM aAdditionalMemSeg;                    // Additional Memory Segment

    DWORD dwStatus;

    PM_STATEINFO PgltPM;

    PVOID pDmaAdapterGUI;                           // opaque DMA object from the videoport 
    PVOID pDmaAdapterFB;                            // opaque DMA object from the videoport 

    ULONG       ulMultiCrtcFlags;       // Stores MultiCRTC specific flags 
    PVOID       pvHwOtherDevExt;        // links the primary device extension to the secondary ones.
    BOOL        bFailExtendingDesktop;  //A flag that tells driver to fail setmode for secondary pdev.

    PVOID       pvCMMregistryEntries;
    ULONG       ulDriverID; //Used by DAL to determine which driver is calling.  
    ULONG       ulNumControllers;
    PCOMMON_BLOCK pCommonBlock;                       // Mapped logical base address of COMMON_BLOCK structure.

    DWORD       dwIRQSource;

    ULONG       ulAtiMemoryPoolID;  //Pool Tag.

    PFN_RESET_HW               pfn_vAsicResetHw;
    PFN_INT10                  pfn_vpAsicInt10;
    PFN_APERTURE_MAPPING       pfn_bAsicAreHdpAperturesSameMapping;
    PFN_PROGRAM_SCK_PRESCALE1  pfn_vAsicProgramSckPrescale1;
    PFN_SET_INT_CLEAR          pfn_vAsicSwInterruptClear;
    PFN_SET_VIDEO_MUX          pfn_vAsicSetVideoMuxCntlGeyserville;
    PFN_SET_FP_INT             pfn_vAsicSetFpIntConnectivityState;
    PFN_TURN_OFF_CURSOR        pfn_vAsicTurnOffHwCursor;
    PFN_PM4INT_ACK             pfn_bAsicPM4InterruptAck;
    PFN_PM4INT_ENABLE          pfn_bAsicPM4InterruptEnable;
    PFN_PM4INT_DISABLE         pfn_bAsicPM4InterruptDisable;
    PFN_IS_HOTPLUGABLE         pfn_vAsicSetNextIntIsHotPlug;
    DWORD                      dwCailCaps[NUM_CAPS_DWORDS];   // save CAIL caps

    ULONG       ulFBSegID;                      //Segment ID of FB mem
    ULONG       ulAGPSegID;                     //Segment ID of AGP mem
    ULONG       ulDXVASegID;                    //Segment ID of DXVA mem
    
    BOOLEAN                    bDXVASegment;        // A special memory segment exists for DXVA render targets
    PHYSICAL_ADDRESS           lDXVASegmentAddress;

    PVOID       pPrivateBuffers;

    PVOID       DeviceHandle;
    ULONG64     SystemAgpApertureSize;
    PHYSICAL_ADDRESS SystemAgpApertureBase;
    ULONG       PrevPreemptFenceIDArray[MULTI_ENGINE_COUNT];
    ULONG       PrevSubmitFenceIDArray[MULTI_ENGINE_COUNT];

    union
    {
        struct 
        {                
            TILED_SURFACE_INFO  sPrimTiledSurf[2];      //These two tiled surface apertures are reserved for primary surfaces
            TILED_SURFACE_INFO  sGenTiledSurf[6];          //These tiled surface apetures are for generat use
        };
        TILED_SURFACE_INFO  sTiledSurf[8];
    };

    DWORD   dwFBSegOffset;                              //Offset from FB base of the FB seg
    DWORD   dwLastPrimSurfFBOffset;                     //Used in R200SetCurRLEntry() to patch invalid handle resources to prim so we can spot corruption

    ULONG ChildCount;                                   // Total number of children enumerated.
    PVOID AcpiChildren;                                 // Used to keep track of all our ACPI enumerated children.

    BOOLEAN InterruptsEnabled;                          // Global flag that masks off interrupts on power-down.

    DWORD   dwVideoEngineContextCo;                     // Used to change how we handle Preempt DDI


} HW_DEVICE_EXTENSION, *PHW_DEVICE_EXTENSION;



#define SEGID_INVALID           0xffffffff  // Indicates invalid segment ID

//HW_DEVICE_EXTENSION.ulCursorFlags definitions
#define USE_MONOCURSOR          0x00000001  // flags if HW mono cursor is enabled
#define USE_COLORCURSOR         0x00000002  // flags if HW color cursor is enabled
#define USE_ALPHACURSOR         0x00000004  // flags if HW Alpha cursor is enabled
#define CURSOR_VISIBLE          0x00000008  // Indicates that the cursor is visible

typedef struct _ATI_SHARE_HDE {
    PHW_DEVICE_EXTENSION     pHwDevExt;
} ATI_SHARE_HDE;

#define MAX_HDES                12
#define ATI_FUNCTION_PRIMARY    0
#define ATI_FUNCTION_SECONDARY  1

#define HWDEVICEEXTENSIONFROMHDDL(h) (PHW_DEVICE_EXTENSION)(*(PVOID*)h)

typedef struct _CMM_PCI_GART_IOCTL_STRUCT {
    DWORD       dwAllocSize;
    DWORD       dwGartControllerAddress;
} CMM_PCI_GART_IOCTL_STRUCT, *PCMM_PCI_GART_IOCTL_STRUCT;

#define INVALID_ADDRESS         0

#define R200_MEMORY_TAG         '002R'

#if (_WIN32_WINNT == 0x500)

#define VIDEO_CHILD_ACTIVE      1    // Defined by DDK only in WinXP and higher
#endif


//
// Registry setting for ring manager
//


#ifdef __cplusplus
extern "C" {
#endif

typedef enum _CMMQS_REGISTRY_KEYENUMERATORS                    
{
        //! this is ID and index to define size of AGP pool
        CMMQS_REGISTRY_INITIAL_POOL_AGP,        // Used by miniport
        //! this is ID and index to define size of PCI_GART pool
        CMMQS_REGISTRY_INITIAL_POOL_PCI_GART,   // Used by miniport
        //! this is ID to define how many pages of memory will be committed simultaneously      <br><br>  
        CMMQS_REGISTRY_COMMIT_MULTIPLIER_AGP,   // Used by miniport
        //! this is ID and index to disable all QS features (relative to QS_DISABLE_ALL)
        CMMQS_REGISTRY_DISABLE_QS_ALL,
        //! this is ID and index to disable all local list (relative to QS_DISABLE_LISTSLOCAL flag)
        CMMQS_REGISTRY_DISABLE_QS_LISTS_LOCAL,                                   
        //! this is ID and index to disable all non local list (relative to QS_DISABLE_LISTSNONLOCAL flag)
        CMMQS_REGISTRY_DISABLE_QS_LISTS_NONLOCAL,
        //! this is ID and index to disable QS entirely (relative to QS_DISABLE_ENTIRELY flag)
        CMMQS_REGISTRY_DISABLE_QS_ENTIRELY,
        //! this is ID and index to disable rptr register writeback capability
        //! (relative to QS_DISABLE_RPTRWRITEBACK flag)                                
        CMMQS_REGISTRY_WRITEBACK_DISABLE_RPTR,
        //! this is ID and index to disable timestamp writeback
        //! (relative to QS_DISABLE_TIMESTAMPWRITEBACK flag)                 
        CMMQS_REGISTRY_WRITEBACK_DISABLE_TS,
        //! this is ID and index to disable bitblt using scratch register 4
        //! (relative to QS_DISABLE_BITBLT_THROTTLE_WRITEBACK flag)
        CMMQS_REGISTRY_WRITEBACK_DISABLE_SCRATCH4,
        //! this is ID and index to disable writeback using scratch register 5
        //! (relative to QS_DISABLE_PIXEL_CACHE_PURGE_WRITEBACK flag)
        CMMQS_REGISTRY_WRITEBACK_DISABLE_SCRATCH5,
        //! this is ID and index to disable writeback using scratch register 6
        //! (relative to QS_DISABLE_3D_SCRATCH_0_WRITEBACK flag)
        CMMQS_REGISTRY_WRITEBACK_DISABLE_SCRATCH6,
        //! this is ID and index to disable writeback using scratch register 7
        //! (relative to QS_DISABLE_3D_SCRATCH_1_WRITEBACK flag)
        CMMQS_REGISTRY_WRITEBACK_DISABLE_SCRATCH7,
        //! This is ID to define registry value which is number of clocks 
        //! that a write to WPTR will be delayed before taking effect                           <br><br>
        CMMQS_REGISTRY_WPTR_DELAY_CLOCKS,
        //! This is ID to define registry value, 
        //! which is max fetch size                        <br><br>
        CMMQS_REGISTRY_MAX_FETCH_READ_REQUEST,
        //! Determines how often CP will write back the read pointer.
        //! See the description of the CP_RB_CNTL register for details.
        CMMQS_REGISTRY_CP_RB_BLKSZ,

        CMMQS_REGISTRY_SENTINAL_VALUE

} CMMQS_REGISTRY_KEYENUMERATORS;

typedef enum _CMMQS_REGISTRY_KEY_TYPES
{
        CMMQS_REGISTRY_KEY_IS_DWORD             = 1,    //!< identifies that type of saved data is DWORD
        CMMQS_REGISTRY_KEY_IS_STRING            = 2,    //!< identifies that type of saved data is STRING
        CMMQS_REGISTRY_MAX_STRING_LENGTH        = 80    //!< identifies max allowed string length
        
} CMMQS_REGISTRY_KEY_TYPES;

typedef struct {
    PWSTR  pchKeyName;
    DWORD  dwDefaultValue;
    DWORD  dwKeyEnum;
    DWORD  dwExpectedType;
} CMMQS_REG_INPUT_TYPE, *PCMMQS_REG_INPUT_TYPE;

typedef struct { 
    CHAR   chString[CMMQS_REGISTRY_MAX_STRING_LENGTH]; //!< string value read from registry
    BOOL   bRegistryEntryPresent;                      //!< TRUE if the rest of this data is valid
    DWORD  dwReadValue;                                //!< DWORD value read from registry
    DWORD  dwValueType;                                //!< one of CMMQS_REGISTRY_KEY_TYPES values
} CMMQS_REG_OUTPUT_TYPE, *PCMMQS_REG_OUTPUT_TYPE;

typedef struct _CMMQS_REGISTRY_INTERNAL {
    DWORD   dwQSdisableFlags;                              //!< initial flags read from registry. See CMMQS_REGISTRY_KEYENUMERATORS      
    DWORD   dwQSdisable2Flags;                             //!< initial flags read from registry. See CMMQS_REGISTRY_KEYENUMERATORS
    DWORD   dwPageSizeMultiplier;                          //!< how many pages of memory will be committed simultaneously?

    DWORD   dwWptrDelayClocks;          //!< Number of clocks that a write to WPTR will be delayed before taking effect.
    DWORD   dwCPMaxFetchReadRequest;    //!< Max fetch size

    DWORD   dwCpRbBlksz;                //!< Used to override the default setting of CP_RB_CNTL.RB_BLKSZ

} CMMQS_REGISTRY_INTERNAL, *PCMMQS_REGISTRY_INTERNAL;


#ifdef INCLUDE_REGISTRY_TABLE

    CMMQS_REG_INPUT_TYPE  cmmqsRegistryInfo[] = {
        //   Registry Value Name            //    Default value    // one of CMMQS_REGISTRY_KEYENUMERATORS  // one of CMMQS_REGISTRY_KEY_TYPES
        L"AgpSize",                         0,          CMMQS_REGISTRY_INITIAL_POOL_AGP,            CMMQS_REGISTRY_KEY_IS_DWORD,
        L"MHPinitialPCIGartPoolSize",       0,          CMMQS_REGISTRY_INITIAL_POOL_PCI_GART,       CMMQS_REGISTRY_KEY_IS_DWORD,
        L"MHPcommitMultiplier",             256,        CMMQS_REGISTRY_COMMIT_MULTIPLIER_AGP,       CMMQS_REGISTRY_KEY_IS_DWORD,
        L"DisableQSAll",                    0,          CMMQS_REGISTRY_DISABLE_QS_ALL,              CMMQS_REGISTRY_KEY_IS_DWORD,
        L"DisableQSListsLocal",             0,          CMMQS_REGISTRY_DISABLE_QS_LISTS_LOCAL,      CMMQS_REGISTRY_KEY_IS_DWORD,
        L"DisableQSListsNonlocal",          0,          CMMQS_REGISTRY_DISABLE_QS_LISTS_NONLOCAL,   CMMQS_REGISTRY_KEY_IS_DWORD,
        L"DisableQSEntirely",               0,          CMMQS_REGISTRY_DISABLE_QS_ENTIRELY,         CMMQS_REGISTRY_KEY_IS_DWORD,
        L"DisableRptrWriteBack",            0,          CMMQS_REGISTRY_WRITEBACK_DISABLE_RPTR,      CMMQS_REGISTRY_KEY_IS_DWORD,
        L"DisableTimeStampWriteBack",       0,          CMMQS_REGISTRY_WRITEBACK_DISABLE_TS,        CMMQS_REGISTRY_KEY_IS_DWORD,
        L"DisableBitBltThrottleWriteBack",  0,          CMMQS_REGISTRY_WRITEBACK_DISABLE_SCRATCH4,  CMMQS_REGISTRY_KEY_IS_DWORD,
        L"DisablePixelCachePurgeWriteBack", 0,          CMMQS_REGISTRY_WRITEBACK_DISABLE_SCRATCH5,  CMMQS_REGISTRY_KEY_IS_DWORD,
        L"Disable3DScratch0WriteBack",      0,          CMMQS_REGISTRY_WRITEBACK_DISABLE_SCRATCH6,  CMMQS_REGISTRY_KEY_IS_DWORD,
        L"Disable3DScratch1WriteBack",      0,          CMMQS_REGISTRY_WRITEBACK_DISABLE_SCRATCH7,  CMMQS_REGISTRY_KEY_IS_DWORD,
        L"WmWptrDelayClocks",               0,          CMMQS_REGISTRY_WPTR_DELAY_CLOCKS,           CMMQS_REGISTRY_KEY_IS_DWORD,
        L"CPMaxFetchReadRequest",           2,          CMMQS_REGISTRY_MAX_FETCH_READ_REQUEST,      CMMQS_REGISTRY_KEY_IS_DWORD,
        L"CpRbBlksz",                       0,          CMMQS_REGISTRY_CP_RB_BLKSZ,                 CMMQS_REGISTRY_KEY_IS_DWORD,
        // The last entry in cmmqsRegistryInfo[] must have dwKeyEnum = CMMQS_REGISTRY_SENTINAL_VALUE
        L"",                                0,          CMMQS_REGISTRY_SENTINAL_VALUE,              CMMQS_REGISTRY_KEY_IS_DWORD,
    };
#endif  // INCLUDE_REGISTRY_TABLE

#ifdef __cplusplus
}
#endif

#endif  // _RAGE_H_


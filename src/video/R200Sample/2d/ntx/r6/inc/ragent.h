

/*****************************************************************************\
* 
*  Module Name    ragent.h
*  Project        Longhorn
*  Device         R200
*
*  Description    header file for Miniport
*  
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
\*****************************************************************************/

#ifndef _RAGENT_H_
#define _RAGENT_H_

#undef FAR
#define FAR

//
// Include some structure used by DAL.
//
#include "dalbase.h"
#include "atios.h"

#define ATI_MINIPORT_STR    "R200.SYS:"

// computes the number of elements within an array

#define NUM(x) ( sizeof(x) / sizeof((x)[0]) )

//
// Define physicial device disable flags, used in DisableFlags field of
// PDEV and HW_DEVICE_EXTENSION. Based on boolean values stored in the
// registry.
//

#define PDEV_DISABLE_DMA                        0x00040000

#define PDEV_DISABLE2_VIDEOUSWC                 0x00000400
#define PDEV_DISABLE2_TV                        0x00400000
#define PDEV_DISABLE2_DFP                       0x00800000
#define PDEV_DISABLE2_LCD                       0x01000000
#define PDEV_DISABLE2_CRT                       0x02000000

#define PDEV_DISABLE3_HOTPLUGDFP                0x00000010
#define PDEV_DISABLE3_MULTIMONENUM              0x00000020
#define PDEV_DISABLE3_ENUMALLCHILDS             0x00000040

#define PDEV_DISABLE4_USWCAGP                   0x00000010
#define PDEV_DISABLE4_MMLIB                     0x00002000
#define PDEV_DISABLE4_DALVALIDATECHILD          0x00004000
#define PDEV_DISABLE4_PM4TSINTERRUPT            0x01000000

//
// Define controls used in ControlData field of HW_DEVICE_EXTENSION.
// Based on DWORD values stored in the registry.
//
#define CONTROL_AGP_LEVEL_1X                    1
#define CONTROL_AGP_LEVEL_2X                    2
#define CONTROL_AGP_LEVEL_4X                    4
#define CONTROL_AGP_LEVEL_8X                    8

//
// Maximum number of pending flip allowed to 
// queue into the ring buffer at any given time
//
#define WM_MAX_FLIP_PENDING_ALLOWED_DEFAULT     2

//
// Default allocation size of DMACopy buffer
//
#define WM_DMA_COPY_BUFFER_SIZE                 512 * ONE_K
#define WM_DMA_COPY_BUFFER_SIZE_MIN             256 * ONE_K

//
// QS DirectDraw submit watermark level.
//
#define WM_SUBMIT_CB_LEVEL_DEFAULT             (ONE_K) 


//
// Default DynamicMode enable in driver
#define WM_DYNAMIC_MODE_DEFAULT                 1

//
// Define feature flags, used in dwFeatureFlags field of HW_DEVICE_EXTENSION.
//
#define FEATURE_MMLIB                           0x00000100
#define FEATURE_DUALVIEW                        0x00020000
#define FEATURE_AGPENABLE                       0x00040000
#define FEATURE_PM4_TS_INTERRUPT                0x00800000

//
// Flags for MultiCRTC functionality (DUALVIEW)
//

#define HW_MCRTC_PRIMARY            0x00000001          // Marks primary
#define HW_MCRTC_VIEW_ENABLED       0x00000002          // DALEnableDriverInstance has
                                                        //  returned successfully on
                                                        //  the current HDE
#define HW_MCRTC_DISABLE_VIEW       0x00000004          // Dualview secondary on this hardware device extension
                                                        //  must be disabled in the DAL

                                                        //  
#define HW_MCRTC_DEFINED    0x80000000                  // ulMultiCrtcFlags is initialized

#define DUALVIEW_DEFAULT_DESKTOP     1                  // These values are prescribed by the DAL. We use

#define ASICBUG_CUR_MODE_NOT_LOCKABLE           0x00000002

/******************************Public*Definition***************************\
* Cursor Management
\**************************************************************************/

#define MAX_CACHEABLE_CURSORS   8

#define CURSOR_MAX_X 64
#define CURSOR_MAX_Y 64 

#define CUR_CLR_WHITE 0xFFFFFFFF
#define CUR_CLR_BLACK 0x00000000

typedef struct _CS
{
    // hotspot location for X and Y
    DWORD dxHot;
    DWORD dyHot;

    // width and height of the cursor
    DWORD dcx;
    DWORD dcy;

    // pOffset is the value for hardware register CUR_OFFSET
    UCHAR* pHWOffset;

    // iUniq specifies the current state of the specified cursor. 
    // Every time the cursor changes this value is incremented.
    // This enables drivers to cache source surfaces. [FB]
    ULONG iUniq;
  
    VOID *psoMask;

    // pointer to the cursor's ring 0 address
    VOID *pRing0Address;

    DWORD ulDriverID;

} CS;

#ifndef PHYSICAL_ADDRESS
typedef LARGE_INTEGER PHYSICAL_ADDRESS, *PPHYSICAL_ADDRESS;
#endif
//
// Structure used to hold information about the scatter gather table.
//
typedef struct SGT_INFO
{
    PHYSICAL_ADDRESS    sgtPhysicalAddress;             // Base physical address of SGT
    PVOID               pvSgtBaseAddress;               // Mapped logical base address of SGT
    ULONG               ulTotalEntriesUsedByMHP;        // Total entries in SGT used by pools registered with MHP
    ULONG               ulTotalEntriesInSGT;            // Total number of entries in the SGT
    ULONG               ulTotalSGTentriesUseableByMHP;  // max number of SGT entries useable by the MHP
    ULONG               ulSGTsizeBytes;
    ULONG               ulPhysicalAddressRangeSize;
    BOOL                bAGPLargeApertureEnabled;       // can we use a large aperture for page locking
    BOOL                bPCIGARTDMAEnabled;             // can we use some (half) of PCI for page locking
    ULONG               ulPCIGARTDMABase;               // start of PCI which is reserved for page locking
    ULONG               ulPCIGARTDMASize;               // size of PCI which is reserved for page locking
} SGT_INFO, *PSGT_INFO;

//
// Common Block information structure.
// This structure contains controller information for each pHwDeviceExtension which will be shared with the DRV.
//
typedef struct
{
    DWORD dControllersForDriver1;                   // Controllers owned by primary HwDeviceExtension
    DWORD dControllersForDriver2;                   // Controllers owned by secondary HwDeviceExtension if one exists.
    // Cursor is a structure containing information about the cursor,
    // two identical structures are used to allow the driver to update
    // one cursor preserving the current cursor until the hardware is
    // updated to point to the new cursor.
    
    CS Cursor[MAX_CACHEABLE_CURSORS];
    // dCursor index selects the active cursor from 'Cursor' structure
    DWORD dCursorIndex;
    
    DWORD  dwFlags;
    SGT_INFO sgtInfo;

} COMMON_BLOCK, *PCOMMON_BLOCK;

//
// COMMON_BLOCK.dControllersForDriverX field capabilities
//

#define NOCONTROLLER_ON      0x00000000
#define CONTROLLER1_ON       0x00000001
#define CONTROLLER2_ON       0x00000002

//
//  CommonBlock flags
//                               
#define CB_ENUMERATE                   0x00000001  // Trigger DlEnumerateChildren call to O/S
#define CB_DISABLE_VIEW                0x00000002  // Multi-function secondary must be disabled in the DAL
#define CB_DESKTOP_EXTENDED            0x00000004  // Extended desktop is enabled (DualView/Multi-function)   
#define CB_INVCURSOR_ENABLED           0x00000008  // Identifies primary invisible cursor is active
#define CB_INVCURSOR2_ENABLED          0x00000010  // Identifies secondary invisiblec ursor is active
#define CB_RESUME_FROM_SLEEP	       0x00000020  // Identifies the adapter is returning from sleep state
#define CB_SUPPRESS_ENUMERATION        0x00000040  // Ignore next change of controller state

typedef struct
{
    DWORD dwAgpLevel;                       // Determines if AGP is disabled, 1x or 2x.
} CONTROL_DATA, *PCONTROL_DATA;

//
// Structure used to represent information about a particular buffer
// (including its size and address).
//
typedef struct _BUFFER_INFO
{
    DWORD dwLength;
    PVOID pvBuffer;
    DWORD dwPM4Alignment;                   // alignment for PM4 submissions
} BUFFER_INFO, *PBUFFER_INFO;

//
// Defined structure for reading registry values
//
typedef struct _REGISTRY_VALUE 
{
    PUCHAR  pValueName; // ASCII single byte character system string
    PVOID   pValueData;
    ULONG   ulValueLength;

} REGISTRY_VALUE, *PREGISTRY_VALUE;

// Defined structure for allocating MMLIB memory
typedef struct _MMLIB_MEM_LOCATION
{
    BOOL    bMMLibInitialized;  // One-time setting

    // AGP memory
    ULONG   ulRequiredMMLibAGPMemSize;  // It's the required mem size by mmlib
    ULONG   ulMMLibAGPMemSize;          // If AGPREAD test fails, this is 0. otherwise, it's equal to ulRequiredMMLibAGPMemSize
    PVOID   pMMLibAGPMemAddr;
    BOOL    bMMLibAGPMemInitialized;

    // system memory
    ULONG   ulRequiredMMLibSysMemSize; 
    ULONG   ulMMLibSysMemSize;
    PVOID   pMMLibSysMemAddr;
    BOOL    bMMLibSysMemInitialized;

    // video memory
    ULONG   ulRequiredMMLibVidMemSize; 
    ULONG   ulMMLibVidMemSize;
    PVOID   pMMLibVidMemAddr;
    BOOL    bMMLibVidMemInitialized;

} MMLIB_MEM_LOCATION, *PMMLIB_MEM_LOCATION;
#endif  // _RAGENT_H_


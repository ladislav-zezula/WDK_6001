

/*****************************************************************************\
* 
*  Module Name    VPE.H
*  Project        Longhorn
*  Device         R200
*
*  Description    Contains the functions to support latest video port
*                 extensions.
*
*  Copyright (c) 2004I Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
\*****************************************************************************/

#ifndef _VPE_H_
#define _VPE_H_

//
// Prototypes for functions supplied by VPE.C.
//

BOOLEAN
AtiInterrupt(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VP_STATUS
AtiQueryInterface(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PQUERY_INTERFACE pQueryInterface
    );

ULONG
AtiGetIrqInfo(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID pvInput,
    PDDGETIRQINFO pDDGetIrqInfo
    );

ULONG
AtiEnableIrq(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PDDENABLEIRQINFO pDDEnableIrqInfo,
    PVOID lpOutput
    );
#endif  // _VPE_H_




/*****************************************************************************\
* 
*  Module Name    HOTPLUG.H
*  Project        Longhorn
*  Device         R200
*
*  Description    Header file for hotplug.
*
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
\*****************************************************************************/

#ifndef _HOTPLUG_H_
#define _HOTPLUG_H_

//
// Prototypes for functions supplied by HOTPLUG.C.
//

VOID
InitializeDisplayDeviceInterrupt(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

BOOLEAN
RegisterDFPHotPlugInterrupt(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    HANDLE hEventHandle,
    ULONG ulInterruptBitmap);

VOID
IRQCallback(
    DWORD_PTR ulClientContext,
    struct tag_IRQCallbackInfo*);


DWORD_PTR
RegisterDisplayDeviceIRQCallback(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulInterruptBitmap
    );

VOID
AtiObReferenceObjectByHandle(
    PVOID pvHandle,
    PVOID pvEvent
    );

VOID
AtiSetEvent(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID pvEvent
    );

VOID
AtiClearEvent(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID pvEvent
    );

#endif // _HOTPLUG_H_




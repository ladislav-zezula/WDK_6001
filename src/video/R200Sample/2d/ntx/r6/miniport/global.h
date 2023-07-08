

/****************************************************************************\
*
*  Module Name    global.h
*  Project        Longhorn
*  Device         R200
*
*
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
*
\****************************************************************************/

#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include "combios.h"

//
// Define SUPPORTED_REVISION -- supported devices revision information.
//
typedef struct _SUPPORTED_REVISION
{
    ULONG ulChipFamily;
    USHORT usDeviceId;
    UCHAR ucRevision;
    PWSTR pwszDescription;
} SUPPORTED_REVISION, *PSUPPORTED_REVISION;

//
// Define REVISION_ID -- determines the exact revision of the chip.
//
typedef struct _REVISION_ID
{
    ULONG ulChipFamily;
    ULONG ulInternalRev;
    ULONG ulExternalRev;
    ULONG ulActualRev;
} REVISION_ID, FAR *LPREVISION_ID;

//
// Define REGISTRY_INFO -- stores information retrieved from the registry.
//
typedef struct _REGISTRY_INFO
{
    PWSTR pwszName;         // Name of the registry entry.
    ULONG ulData;           // Bits occupied by this entry.
    ULONG ulDefaultData;    // Default value for the registry entry if not available.
} REGISTRY_INFO, *PREGISTRY_INFO;


#define BRIDGE_TABLE_COUNT 1


extern DXGK_AGP_INTERFACE gAgpServices;         // AGP services struct for Longhorn
extern DXGK_TIMED_OPERATION_INTERFACE gTimedOpServices;
extern VP_DEVICE_DESCRIPTION ex_vpDeviceDescription;


extern ULONG              ex_ulNumCardsFound;
extern BOOL               gbSecondaryFunctionFound;
extern BOOL               gbOtherExtensionFound;

extern ULONGLONG gSystemMemorySize;

extern const GUID GUID_I2C_INTERFACE;
extern const GUID GUID_GPIO_INTERFACE;

extern SUPPORTED_REVISION ex_aSupportedRevisions[];
extern REVISION_ID        ex_aRevisionIds[];
extern REGISTRY_INFO      ex_aRegistryDisableFlags[];
extern REGISTRY_INFO      ex_aRegistryDisable2Flags[];
extern REGISTRY_INFO      ex_aRegistryDisable3Flags[];
extern REGISTRY_INFO      ex_aRegistryDisable4Flags[];
extern REGISTRY_INFO      ex_aRegistryControlData[];
extern USHORT             BridgeDeviceTable[];

extern REGISTRY_INFO      ex_aRegistryMMLibDisableFlags[];

#endif  // _GLOBAL_H_


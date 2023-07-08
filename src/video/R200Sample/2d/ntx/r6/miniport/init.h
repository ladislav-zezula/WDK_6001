

/*****************************************************************************\
* 
*  Module Name    INIT.H
*  Project        Longhorn
*  Device         R200
*
*  Description    Corresponding header file for INIT.C.
*
*  Copyright (c) 1998-1999 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
\*****************************************************************************/

#ifndef _INIT_H_
#define _INIT_H_

//
// Define valuse used in ATI Video BIOS identification.
//
#define BIOS_PN_PREFIX                  "BIOS P/N "                 // ATI BIOS P/N prefix
#define BIOS_RAGE128_PREFIX             "ATI Technologies Inc. "    // ATI BIOS prefix for pre-production BIOS
#define BIOS_STRING_LENGTH              43                          // Max length of ATI BIOS P/N string
#define ADAPTER_STRING_LENGTH           45                          // Max length of Adapter ID
//
// Define flags used in hardware change detection.
//
#define HC_ADAPTER                      0x00000001
#define HC_MONITOR                      0x00000002
#define HC_MONITOR_UNKNOWN              0x00008000

//
// Define values used by ADAPTER_INFO structure.
//
#define ADAPTER_CHIP_TYPE_SIZE          128
#define ADAPTER_DAC_TYPE_SIZE           128
#define ADAPTER_ADAPTER_STRING_SIZE     128
#define ADAPTER_BIOS_STRING_SIZE        128

//
// Define ADAPTER_INFO -- stores adapter data used by Display Properties Applet.
//
typedef struct _ADAPTER_INFO
{
    UCHAR ucaChipType[ADAPTER_CHIP_TYPE_SIZE];
    UCHAR ucaDacType[ADAPTER_DAC_TYPE_SIZE];
    UCHAR ucaAdapterString[ADAPTER_ADAPTER_STRING_SIZE];
    UCHAR ucaBiosString[ADAPTER_BIOS_STRING_SIZE];
    ULONG ulMemorySize;
} ADAPTER_INFO, *PADAPTER_INFO;

#endif  // _INIT_H_


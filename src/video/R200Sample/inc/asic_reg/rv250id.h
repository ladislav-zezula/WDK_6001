

/*****************************************************************************\
* 
*  Module Name    rv250id.h
*  Project        Iris Windows
*  Device         Iris
*
*  Description    Identifier file for Iris driver
*  
*
*  (c) 1999 - 2001 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*  
*
\*****************************************************************************/

#ifndef _RV250ID_H
#define _RV250ID_H
 
enum
{
    IRIS_A11     = 1,
    IRIS_A12     = 2,
    IRIS_A13     = 3,
    IRIS_WS_A11  = 0x80,
    IRIS_WS_A12  = 0x81,
    IRIS_UNKNOWN = 0xFF
};

//
// Define Chip ID's for the Iris.
//
#define DEVICE_ID_IRIS_ID        0x4964  // Workstation, CHG_ID=00
#define DEVICE_ID_IRIS_IE        0x4965  // Workstation, CHG_ID=01
#define DEVICE_ID_IRIS_IF        0x4966  // Regular, CHG_ID=00
#define DEVICE_ID_IRIS_IG        0x4967  // Regular, CHG_ID=01

#define DEVICE_ID_IRIS_IL        0x496C  // Workstation, CHG_ID=00
#define DEVICE_ID_IRIS_IM        0x496D  // Workstation, CHG_ID=01
#define DEVICE_ID_IRIS_IN        0x496E  // Regular, CHG_ID=00
#define DEVICE_ID_IRIS_IO        0x496F  // Regular, CHG_ID=01

#define DEVICE_ID_IRIS_LD        0x4C64  // WS Mobile, CHG_ID=10
#define DEVICE_ID_IRIS_LE        0x4C65  // WS Mobile, CHG_ID=11
#define DEVICE_ID_IRIS_LF        0x4C66  // Mobile, CHG_ID=10
#define DEVICE_ID_IRIS_LG        0x4C67  // Mobile, CHG_ID=11

#define DEVICE_ID_IRIS_LL        0x4C6C  // WS Mobile, CHG_ID=10
#define DEVICE_ID_IRIS_LM        0x4C6D  // WS Mobile, CHG_ID=11
#define DEVICE_ID_IRIS_LN        0x4C6E  // Mobile, CHG_ID=10
#define DEVICE_ID_IRIS_LO        0x4C6F  // Mobile, CHG_ID=11

//
// Define ATI's internal revision numbers.
//
#define INTERNAL_REV_IRIS_A11    0x00  // The first Iris ASIC spin
#define INTERNAL_REV_IRIS_A12    0x00   
#define INTERNAL_REV_IRIS_A13    0x00
#define INTERNAL_REV_IRIS_WS_A11 0x00  // The first Iris ASIC spin for WS
#define INTERNAL_REV_IRIS_WS_A12 0x00  

//
// Define ATI's external revision numbers.
//
#define EXTERNAL_REV_IRIS        0x00
#define EXTERNAL_REV_IRIS_A11    0x00
#define EXTERNAL_REV_IRIS_A12    0x01   
#define EXTERNAL_REV_IRIS_A13    0x02
#define EXTERNAL_REV_IRIS_WS_A11 0x80  
#define EXTERNAL_REV_IRIS_WS_A12 0x81  

//
// Define packaging options for RV250
//
#define CONFIG_XSTRAP__PKGTYPE_LE                      0x0C
#define CONFIG_XSTRAP__PKGTYPE_STD                     0x0E


#endif  // _RV250ID_H


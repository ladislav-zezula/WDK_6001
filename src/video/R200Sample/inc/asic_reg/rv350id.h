

/*****************************************************************************\
* 
*  Module Name    rv350id.h
*  Project        Shivah Windows
*  Device         Shivah
*
*  Description    Identifier file for Iris driver
*  
*
*  (c) 1999 - 2001 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
*  1.0    20/08/2002 [respiritu] - initial revision
*
\*****************************************************************************/

#ifndef _RV350ID_H
#define _RV350ID_H
 
enum
{
    SHIVAH_A11     = 1,
    SHIVAH_A12     = 2,
    SHIVAH_UNKNOWN = 0xFF
};

//
// Define Chip ID's for the Shivah.
//
#define DEVICE_ID_SHIVAH_AP        0x4150  // "Fcn 1, Desktop, CHG_ID=00, WSEN=0"
#define DEVICE_ID_SHIVAH_AQ        0x4151  // "Fcn 1, Desktop, CHG_ID=01, WSEN=0"
#define DEVICE_ID_SHIVAH_AR        0x4152  // "Fcn 1, Desktop, CHG_ID=10, WSEN=0"
#define DEVICE_ID_SHIVAH_AS        0x4153  // "Fcn 1, Desktop, CHG_ID=11, WSEN=0" 

#define DEVICE_ID_SHIVAH_AT        0x4170  // "Fcn 2, Desktop, CHG_ID=00, WSEN=0 "
#define DEVICE_ID_SHIVAH_AU        0x4171  // "Fcn 2, Desktop, CHG_ID=01, WSEN=0 "
#define DEVICE_ID_SHIVAH_AV        0x4172  // "Fcn 2, Desktop, CHG_ID=10, WSEN=0 "
#define DEVICE_ID_SHIVAH_AW        0x4173  // "Fcn 2, Desktop, CHG_ID=11, WSEN=0 "

#define DEVICE_ID_SHIVAH_NP        0x4E50  // "Fcn 1, Mobile, CHG_ID=00, WSEN=0"
#define DEVICE_ID_SHIVAH_NQ        0x4E51  // "Fcn 1, Mobile, CHG_ID=01, WSEN=0" 
#define DEVICE_ID_SHIVAH_NR        0x4E52  // "Fcn 1, Mobile, CHG_ID=10, WSEN=0" 
#define DEVICE_ID_SHIVAH_NS        0x4E53  // "Fcn 1, Mobile, CHG_ID=11, WSEN=0"
#define DEVICE_ID_SHIVAH_NX        0x4E54  // "M10 Mobile/Workstation, WSDEGRADE = 0"
#define DEVICE_ID_SHIVAH_NY        0x4E56  // "M10 Mobile/Workstation, WSDEGRADE = 0"

#define DEVICE_ID_SHIVAH_NT        0x4E70  // "Fcn 2, Mobile, CHG_ID=00, WSEN=0 "
#define DEVICE_ID_SHIVAH_NU        0x4E71  // "Fcn 2, Mobile, CHG_ID=01, WSEN=0 "
#define DEVICE_ID_SHIVAH_NV        0x4E72  // "Fcn 2, Mobile, CHG_ID=10, WSEN=0 "
#define DEVICE_ID_SHIVAH_NW        0x4E73  // "Fcn 2, Mobile, CHG_ID=11, WSEN=0 "

//
// Define ATI's internal revision numbers.
//
#define INTERNAL_REV_SHIVAH_A11    0x00  // The first Iris ASIC spin
#define INTERNAL_REV_SHIVAH_A12    0x01   

//
// Define ATI's external revision numbers.
//
#define EXTERNAL_REV_SHIVAH        0x00
#define EXTERNAL_REV_SHIVAH_A12    0x01   

#endif  // _RV350ID_H




/*****************************************************************************\
* 
*  Module Name    caboid.h
*  Project        CABO WindowsNT
*  Device         CABO
*
*  Description    Identifier file for CABO driver
*  
*
*  (c) 2002 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
*  1.0    01/10/00 [jcheng] - initial revision
*
\*****************************************************************************/

#ifndef _CABOID_H
#define _CABOID_H

enum
{
    U1_A11     = 1,
    U1_A21     = 2,
    U1_UNKNOWN = 0xFF
};

enum
{
    RS200_A11     = 1,
    RS200_UNKNOWN = 0xFF
};

enum
{
    RS250_A11     = 1,
    RS250_UNKNOWN = 0xFF
};

//
// Define Chip ID's for CABO,RS200,RS250
//
#define DEVICE_ID_A3_A6           0x4136  // A3 Internal graphics core (M6).
#define DEVICE_ID_RS200           0x4137  // A4  Internal graphics core (M6).
#define DEVICE_ID_RS250           0x4237  // RS250 Internal graphics core(M6).

#define DEVICE_ID_U1_C1           0x4331  // U1 Internal PCI-PCI Bridge.
#define DEVICE_ID_U1_C6           0x4336  // U1 Internal graphics core (M6).
#define DEVICE_ID_RS200M          0x4337  // U2 Internal graphics core (M6).
#define DEVICE_ID_RS250M          0x4437  // RS250M Internal graphics core(M6).


//
// Define ATI's internal revision numbers.
//
#define INTERNAL_REV_U1_A11    0x00  // The first U1 ASIC.
#define INTERNAL_REV_U1_A21    0x01  // The second version of U1/A3 ASIC
#define INTERNAL_REV_RS200_A11 0x00  // The first RS200 ASIC.
#define INTERNAL_REV_RS250_A11 0x00  // The first RS250 ASIC

//
// Define ATI's external revision numbers.
//
#define EXTERNAL_REV_U1       0x00
#define EXTERNAL_REV_RS200    0x00
#define EXTERNAL_REV_RS250    0x00

#endif  // _CABOID_H


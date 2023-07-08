

/*****************************************************************************\
* 
*  Module Name    rs300id.h
*  Project        RS300 WindowsNT
*  Device         RS300
*
*  Description    Identifier file for RS300 driver
*  
*
*  (c) 2002 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
*  1.0    02/11/20 [szhao] - initial revision
*
\*****************************************************************************/

#ifndef _RS300ID_H
#define _RS300ID_H

enum
{
    RS300_A11     = 1,
    RS300_UNKNOWN = 0xFF
};

//
// Define Chip ID's for RS300
//
#define DEVICE_ID_RS300           0x5834  // RS300 Internal graphics core (M9).
#define DEVICE_ID_RS300VE         0x5836  // RS300VE Internal graphics core (M9).
#define DEVICE_ID_RS300M          0x5835  // RS300M Internal graphics core (M9).
#define DEVICE_ID_RS300ML         0x5837  // RS300ML Internal graphics core (M9).

//
// Define ATI's internal revision numbers.
//
#define INTERNAL_REV_RS300_A11 0x00  // The first RS300 ASIC.

//
// Define ATI's external revision numbers.
//
#define EXTERNAL_REV_RS300    0x00

#endif  // _RS300ID_H


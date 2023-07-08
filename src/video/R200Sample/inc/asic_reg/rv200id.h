

/*****************************************************************************\
* 
*  Module Name    rv200id.h
*  Project        Morpheus Windows
*  Device         Morpheus
*
*  Description    Identifier file for Morpheus driver
*  
*
*  (c) 1999 - 2001 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
*  1.0    20/02/2001 [JJiang] - initial revision
*
\*****************************************************************************/

#ifndef _RV200ID_H
#define _RV200ID_H
 
enum
{
    MORPHEUS_A11     = 1,
    MORPHEUS_A12     = 2,
    MORPHEUS_UNKNOWN = 0xFF
};

//
// Define Chip ID's for the Morpheus
//
#define DEVICE_ID_MORPHEUS_QW        0x5157  // RV200 default
#define DEVICE_ID_MORPHEUS_QX        0x5158  // RV200 reduced functionality

#define DEVICE_ID_MORPHEUS_LW        0x4C57  // P7/D7 default
#define DEVICE_ID_MORPHEUS_LX        0x4C58  // P7/D7 reduced functionality

//
// Define ATI's internal revision numbers.
//
#define INTERNAL_REV_MORPHEUS_A11  0x00  // The first Morpheus ASIC.
#define INTERNAL_REV_MORPHEUS_A12  0x01  // First ASIC fixes.

//
// Define ATI's external revision numbers.
//
#define EXTERNAL_REV_MORPHEUS     0x00
#endif  // _RV200ID_H


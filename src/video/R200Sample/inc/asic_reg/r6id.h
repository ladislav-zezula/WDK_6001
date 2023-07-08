

/*****************************************************************************\
* 
*  Module Name    r6id.h
*  Project        Rage6 WindowsNT
*  Device         Rage
*
*  Description    Identifier file for Rage driver
*  
*
*  (c) 1999 - 2000 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
*  1.0    10/13/99 [MF] - initial revision
*
\*****************************************************************************/

#ifndef _R6ID_H
#define _R6ID_H
 
enum
{
    RAGE6_A11     = 1,
    RAGE6_A12     = 2,
    RAGE6_A12N1   = 3,
    RAGE6_A13     = 4,
    RAGE6_A21     = 5,
    RAGE6_A22     = 6,
    RAGE6_UNKNOWN = 0xFF
};

enum
{
    R6LITE_A11     = 1,
    R6LITE_A12     = 2,
    R6LITE_UNKNOWN = 0xFF
};

enum
{
    M6_A11     = 1,
    M6_A12     = 2,
    M6_A21     = 3,
    M6_UNKNOWN = 0xFF
};


//
// Define Chip IDs for the Rage6.
//
#define DEVICE_ID_RAGE6_QD        0x5144  // Rage6 ???
#define DEVICE_ID_RAGE6_QE        0x5145  // Rage6 ???
#define DEVICE_ID_RAGE6_QF        0x5146  // Rage6 ???
#define DEVICE_ID_RAGE6_QG        0x5147  // Rage6 ???


//
// Define Chip ID's for the Rage6Lite
//
#define DEVICE_ID_R6LITE_QY       0x5159  // R6Lite default
#define DEVICE_ID_R6LITE_QZ       0x515A  // R6Lite reduced functionality


//
// Define Chip ID's for the M6
//
#define DEVICE_ID_M6_LY           0x4C59  // M6 default
#define DEVICE_ID_M6_LZ           0x4C5A  // M6 reduced functionality


//
// Define ATI's internal revision numbers.
//
#define INTERNAL_REV_RAGE6_A11    0x00  // The first Rage6 ASIC.
#define INTERNAL_REV_RAGE6_A12    0x01  // First ASIC fixes.
#define INTERNAL_REV_RAGE6_A12N1  0x02  // Officially known as A12n1 but really A13.
#define INTERNAL_REV_RAGE6_A13    0x03  // The official A13
#define INTERNAL_REV_RAGE6_A21    0x00  // The official A21
#define INTERNAL_REV_RAGE6_A22    0x01  // The official A22

//
// Define ATI's external revision numbers.
//
#define EXTERNAL_REV_RAGE6        0x00
#define EXTERNAL_REV_RAGE6_A1     0x00
#define EXTERNAL_REV_RAGE6_A2     0x01
#define EXTERNAL_REV_UNKNOWN      0xFF


//
// Define ATI's internal revision numbers.
//
#define INTERNAL_REV_R6LITE_A11    0x00  // The first R6LITE ASIC.
#define INTERNAL_REV_R6LITE_A12    0x01  // First ASIC fixes.

//
// Define ATI's external revision numbers.
//
#define EXTERNAL_REV_R6LITE       0x00

//
// Define ATI's internal revision numbers.
//
#define INTERNAL_REV_M6_A11    0x00  // The first M6 ASIC.
#define INTERNAL_REV_M6_A12    0x01  // First ASIC fixes.
#define INTERNAL_REV_M6_A21    0x03  // Second ASIC fixes.

//
// Define ATI's external revision numbers.
//
#define EXTERNAL_REV_M6       0x00

#endif  // _R6ID_H


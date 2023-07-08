

/*****************************************************************************\
* 
*  Module Name    r300id.h
*  Project        Khan Windows
*  Device         Khan
*
*  Description    Identifier file for khan driver
*  
*
*  (c) 1999 - 2001 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
\*****************************************************************************/

#ifndef _R300ID_H
#define _R300ID_H
 
enum
{
    KHAN_A11     = 1,
    KHAN_A12     = 2,
    KHAN_A13     = 3,
    KHAN_UNKNOWN = 0xFF
};

//
// Define Chip ID's for the Khan
//
#define DEVICE_ID_R300_AD        0x4144  // CHG_ID(00), FUNC_LEVEL(11), Desktop, Commercial, 1 pipe only
#define DEVICE_ID_R300_AE        0x4145  // CHG_ID(01), FUNC_LEVEL(11), Desktop, Commercial, 1 pipe only
#define DEVICE_ID_R300_AF        0x4146  // CHG_ID(10), FUNC_LEVEL(11), Desktop, Commercial, 1 pipe only
#define DEVICE_ID_R300_AG        0x4147  // CHG_ID(11), FUNC_LEVEL(11), Desktop, Workstation, 1 pipe only

#define DEVICE_ID_R300_ND        0x4E44  // CHG_ID(00), FUNC_LEVEL(11), Desktop, Commercial
#define DEVICE_ID_R300_NE        0x4E45  // CHG_ID(01), FUNC_LEVEL(11), Desktop, Commercial
#define DEVICE_ID_R300_NF        0x4E46  // CHG_ID(10), FUNC_LEVEL(11), Desktop, Commercial
#define DEVICE_ID_R300_NG        0x4E47  // CHG_ID(11), FUNC_LEVEL(11), Desktop, Workstation

#define DEVICE_ID_RL300_AL       0x414C  // CHG_ID(00), FUNC_LEVEL(01), Desktop, Commercial
#define DEVICE_ID_RL300_AM       0x414D  // CHG_ID(01), FUNC_LEVEL(01), Desktop, Commercial
#define DEVICE_ID_RL300_AN       0x414E  // CHG_ID(10), FUNC_LEVEL(01), Desktop, Commercial
#define DEVICE_ID_RL300_AO       0x414F  // CHG_ID(11), FUNC_LEVEL(01), Desktop, Workstation

// R350 device ids: 
#define DEVICE_ID_R350_AH        0x4148  // CHG_ID(00), FUNC_LEVEL(10), Desktop, Commercial
#define DEVICE_ID_R350_AI        0x4149  // CHG_ID(01), FUNC_LEVEL(10), Desktop, Commercial
#define DEVICE_ID_R350_AJ        0x414A  // CHG_ID(10), FUNC_LEVEL(10), Desktop, Commercial
#define DEVICE_ID_R350_AK        0x414B  // CHG_ID(11), FUNC_LEVEL(10), Desktop, Workstation

#define DEVICE_ID_R350_NH        0x4E48  // CHG_ID(00), FUNC_LEVEL(11), Desktop, Commercial
#define DEVICE_ID_R350_NI        0x4E49  // CHG_ID(01), FUNC_LEVEL(11), Desktop, Commercial
#define DEVICE_ID_R350_NJ        0x4E4A  // CHG_ID(10), FUNC_LEVEL(11), Desktop, Commercial
#define DEVICE_ID_R350_NK        0x4E4B  // CHG_ID(11), FUNC_LEVEL(11), Desktop, Workstation

//
// Define ATI's internal revision numbers.
//
#define INTERNAL_REV_KHAN_A11  0x00  // The first Khan ASIC.
#define INTERNAL_REV_KHAN_A12  0x01  // A12 revision.
#define INTERNAL_REV_KHAN_A13  0x02  // A13 revision.

//
// Define ATI's external revision numbers.
//
#define EXTERNAL_REV_KHAN     0x00

#endif  // _R300ID_H


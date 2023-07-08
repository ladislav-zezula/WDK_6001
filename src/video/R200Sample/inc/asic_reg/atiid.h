

/*****************************************************************************\
* 
*  Module Name    atiid.h
*  Project        R128/M3/R6 WindowsNT
*  Device         R128/M3/R6
*
*  Description    Common Family ID file for R128/M3/R6 driver
*  
*
*  Copyright (c) 1999-2000 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
\*****************************************************************************/

#ifndef _ATIID_H
#define _ATIID_H


//
// Define Asic Family IDs for different asic family.
//

#define FAMILY_UNKNOWN                  0
#define FAMILY_RADEON200                8

#define FAMILY_RS200                   23
#define DEVICE_ID_RS200M               0x4337  // U2 Internal graphics core (M6).
#define EXTERNAL_REV_RS200             0x00


#define FAMILY_RS300                   25  // including Device ID: RS300,RS300VE,RS300M,RS300ML

//
// Define Vendor ID.
//

#define FAMILY_IRIS                     47
#define FAMILY_RV250                    FAMILY_IRIS
#define FAMILY_M9                       48

#define FAMILY_ARGUS                    49
#define FAMILY_RV280                    FAMILY_ARGUS

#define FAMILY_M9PLUS                   51

#define ATI_VENDOR_ID                   0x1002


#endif  // _ATIID_H


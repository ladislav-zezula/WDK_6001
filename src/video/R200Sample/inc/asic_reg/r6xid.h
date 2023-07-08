

/*****************************************************************************\
*
*  Module Name    r6xid.h
*  Project        Radeon200
*  Device         Rage
*
*  Description    Identifier file for Rage driver
*
*
*  (c) 2000 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
\*****************************************************************************/

#ifndef _R6XID_H
#define _R6XID_H

enum
{
    RADEON200_A11     = 1,
    RADEON200_A12     = 2,
    RADEON200_A13     = 3,
    RADEON200_UNKNOWN = 0xFF
};

//
// Define Chip IDs for the Radeon200.
// naming convention: small case h,i,j... replaced with P,Q,R,...since vxd is not case sensitive 
#define DEVICE_ID_RADEON200_QH        0x5148  //"Function 1, workstation. Straps CHG_ID(00), WSDEGRADE(0), Bonding WSEN(1)."
#define DEVICE_ID_RADEON200_QI        0x5149  //"Function 1, workstation. Straps CHG_ID(01), WSDEGRADE(0), Bonding WSEN(1)."
#define DEVICE_ID_RADEON200_QJ        0x514A  //"Function 1, workstation. Straps CHG_ID(10), WSDEGRADE(0), Bonding WSEN(1)."
#define DEVICE_ID_RADEON200_QK        0x514B  //"Function 1, workstation. Straps CHG_ID(11), WSDEGRADE(0), Bonding WSEN(1)."
#define DEVICE_ID_RADEON200_QL        0x514C  // RADEON200 Single ASIC boards
#define DEVICE_ID_RADEON200_QM        0x514D  // RADEON200 Multi-ASIC boards, Primary
#define DEVICE_ID_RADEON200_QN        0x514E  // RADEON200 Multi-ASIC boards, Secondary
#define DEVICE_ID_RADEON200_QO        0x514F  // Class = 0xFF, no AGP ability claimed
#define DEVICE_ID_RADEON200_QP        0x5168  //"Function 2, workstation. Straps CHG_ID(00), WSDEGRADE(0), Bonding WSEN(1)."
#define DEVICE_ID_RADEON200_QQ        0x5169  //"Function 2, workstation. Straps CHG_ID(01), WSDEGRADE(0), Bonding WSEN(1)."
#define DEVICE_ID_RADEON200_QR        0x516A  //"Function 2, workstation. Straps CHG_ID(10), WSDEGRADE(0), Bonding WSEN(1)."
#define DEVICE_ID_RADEON200_QS        0x516B  //"Function 2, workstation. Straps CHG_ID(11), WSDEGRADE(0), Bonding WSEN(1)."
#define DEVICE_ID_RADEON200_QT        0x516C  //"Function 2, regular. Straps CHG_ID(00), WSDEGRADE(X), Bonding WSEN(0)."
#define DEVICE_ID_RADEON200_QU        0x516D  //"Function 2, regular. Straps CHG_ID(01), WSDEGRADE(X), Bonding WSEN(0)."
#define DEVICE_ID_RADEON200_QV        0x516E  //"Function 2, regular. Straps CHG_ID(10), WSDEGRADE(X), Bonding WSEN(0)."
#define DEVICE_ID_RADEON200_QW        0x516F  //"Function 2, regular. Straps CHG_ID(11), WSDEGRADE(X), Bonding WSEN(0)."
#define DEVICE_ID_RADEON200_BB        0x4242  // RADEON200 with Bridget in PCI-PCI bridge mode 
#define DEVICE_ID_RADEON200_BC        0x4243  // RADEON200 with Bridget in PCI-PCI bridge mode 

//
// Define ATI's internal revision numbers.
//
#define INTERNAL_REV_RADEON200_A11     0x00   // The first Rage6 ASIC.
#define INTERNAL_REV_RADEON200_A12     0x01   // 
#define INTERNAL_REV_RADEON200_A13     0x02   // 

//
// Define ATI's Bridget internal revision numbers.
//
#define INTERNAL_REV_RADEON200_BB     0x00

//
// Define ATI's external revision numbers.
//
#define EXTERNAL_REV_RADEON200         0x00
#define EXTERNAL_REV_RADEON200_WS      0x80

#endif  // _R6XID_H


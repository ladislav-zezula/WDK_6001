

/****************************************************************************\
*
*  Module Name    find.h
*  Project        Longhorn
*  Device         R200
*
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
*
\****************************************************************************/

#ifndef _FIND_H_
#define _FIND_H_

//
// Values used in ATI adapter identification.
//
#define PC_ROM_ID                   0xAA55          // Found at start of any PC ROM block
#define ATI_PCI_VENDOR_ID           0x1002          // PCI Vendor ID of ATI Technologies Inc.
#define ATI_SIGNATURE               "761295520"     // ATI product signature string

//
// Values used in claiming and mapping of the VGA aperture.
//
#define VGA_ADDRESS_LOW             0x000A0000      // VGA aperture physical address low part
#define VGA_ADDRESS_HIGH            0x00000000      // VGA aperture physical address high part
#define VGA_LENGTH                  0x00020000      // VGA aperture length (128K)

//
// Values used in claiming and mapping of the 1st VGA I/O aperture.
//
#define VGA_IO1_ADDRESS_LOW         0x000003B0      // 1st VGA I/O aperture physical address low part
#define VGA_IO1_ADDRESS_HIGH        0x00000000      // 1st VGA I/O aperture physical address high part
#define VGA_IO1_LENGTH              0x0000000C      // 1st VGA I/O aperture length

//
// Values used in claiming and mapping of the 2nd VGA I/O aperture.
//
#define VGA_IO2_ADDRESS_LOW         0x000003C0      // 2nd VGA I/O aperture physical address low part
#define VGA_IO2_ADDRESS_HIGH        0x00000000      // 2nd VGA I/O aperture physical address high part
#define VGA_IO2_LENGTH              0x00000020      // 2nd VGA I/O aperture length

//
// Values used in claiming and mapping of the ATI Video ROM (may not be available).
//

#define ROM_ADDRESS_LOW             0x000C0000      // Video ROM physical address low part
#define ROM_ADDRESS_HIGH            0x00000000      // Video ROM physical address high part
#define ROM_LENGTH                  0x00000100      // Video ROM initial length
#define ROM_HEADER_POINTER          0x00000048      // Offset in ROM of pointer to ATI ROM header location
#define OFFSET_ROM_HEADER_SIZE               6      // Offset in ROM to the size of the ROM header

#endif  // _FIND_H_


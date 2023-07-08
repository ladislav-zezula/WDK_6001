

/****************************************************************************\
* 
*  Module Name    RAGEIO.H
*  Project        Longhorn
*  Device         R200
*
*  Description    Contains defines and macros related to I/O involved
*                 in the miniport.
*  
*
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
\****************************************************************************/

#ifndef _RAGEIO_H_
#define _RAGEIO_H_


#if (defined (ALPHA) || defined (_ALPHA_))

    #define IN_MM_DENSE             0x04                // DEC Alpha dense memory
    #define IN_MM_SPARSE            0x00                // DEC Alpha sparse memory space
    #define IN_IO_SPACE             0x01                // DEC Alpha sparse I/O space

#else   // defined (ALPHA)

    #define IN_MM_DENSE             0x00                // i386 memory space
    #define IN_MM_SPARSE            0x00                // i386 memory space
    #define IN_IO_SPACE             0x01                // i386 I/O space

#endif  // defined (ALPHA)

//
// Define ATI registers accessable through I/O aperture.
//
#define ATI_IO_REGISTERS            256
#define ATI_IO_FIRST                0x00
#define ATI_IO_LAST                 0xFF

//
// Define 2nd VGA I/O block register selectors as byte offsets from the 2nd VGA I/O register aperture base (0x03C0).
//
#define VGA_IO2_SEQUENCER_INDEX     0x00000004          // 0x03C4
#define VGA_IO2_SEQUENCER_DATA      0x00000005          // 0x03C5
#define VGA_IO2_DAC_MASK            0x00000006          // 0x03C6
#define VGA_IO2_DAC_WRITE_INDEX     0x00000008          // 0x03C8
#define VGA_IO2_DAC_DATA            0x00000009          // 0x03C9
#define VGA_IO2_GRAPHICS_INDEX      0x0000000E          // 0x03CE
#define VGA_IO2_GRAPHICS_DATA       0x0000000F          // 0x03CF

//
// Define macros for accessing ATI registers. This way we can easily switch between different ATI I/O functions.
//

#define ATI_INPD(p, r)              ReadMmRegisterUlong((p), (r))
#define ATI_OUTPD(p, r, v)          WriteMmRegisterUlong((p), (r), (v))

#endif  // _RAGEIO_H_


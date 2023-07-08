

/****************************************************************************\
* 
*  Module Name    DDL.H
*  Project        Longhorn
*  Device         R200
*
*  Description    Header file for the Device Dependant Layer.
*  
*
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
\****************************************************************************/

#ifndef _DDL_H_
#define _DDL_H_

#define VGA_IO2_SEQUENCER_INDEX     0x00000004          // 0x03C4
#define VGA_IO2_SEQUENCER_DATA      0x00000005          // 0x03C5
#define VGA_IO2_DAC_MASK            0x00000006          // 0x03C6
#define VGA_IO2_DAC_WRITE_INDEX     0x00000008          // 0x03C8
#define VGA_IO2_DAC_DATA            0x00000009          // 0x03C9
#define VGA_IO2_GRAPHICS_INDEX      0x0000000E          // 0x03CE
#define VGA_IO2_GRAPHICS_DATA       0x0000000F          // 0x03CF

#define DDL_ADAPTERID               "0000"

//
// Stores buffer data for generic data type registry reads.
//
typedef struct _DDLBUFFER_INFO
{
    PVOID  pvBuffer;                                // Points to actual buffer where data will be written
    PULONG pulLength;                               // Max number of bytes to read from registry
} DDLBUFFER_INFO, *PDDLBUFFER_INFO;

#endif  // _DDL_H_


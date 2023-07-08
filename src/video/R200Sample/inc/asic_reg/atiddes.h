

/****************************************************************************\
* 
*  Module Name    atiddes.h
*  Project        Rage DirectDraw HAL and DirectDraw Client Apps
*  Device         Rage (Win95/98 & WinNT4/W2K)
*
*  Description    Header file for the ATI_FOURCC_DDES interface
*  
*
*  (c) 1999/2000 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
*  Refer to 
*    ATI_FOURCC_DDES Interface Specification, Revision 1.00, February 14,
*    2000 for usage
*
*  LOG OF CHANGES
*
*  1.10   01/15/2001 [ZW] - added HiZ fields to ATIDDESSURFDESC.
*  1.00   02/14/2000 [TK] - updated to 1.00 of spec
*  0.50   01/05/2000 [TK] - initial draft revision
*
*
\****************************************************************************/
#ifndef _ATI_FOURCC_DDES_H
#define _ATI_FOURCC_DDES_H

#ifdef __cplusplus
extern "C" {
#endif

// Revision Information
#define ATI_DDES_REVISION_MAJOR 0x00000001
#define ATI_DDES_REVISION_MINOR 0x00000001  

#define ATI_DDES_REVISION (ATI_DDES_REVISION_MAJOR << 16 | ATI_DDES_REVISION_MINOR)

//
//************************************TypeDefs*********************************
//

// ATIDDESSURFDESC - the structure used to pass data back to client
typedef struct _ATIDDESSURFDESC
{
  DWORD dwSize;          // Size of the structure returned
  DWORD dwOffset;        // Surface address or offset from base address as appropriate for ASIC
  DWORD dwTileFlags;     // Surface tile flags
  BOOL  bAGP;            // Boolean denoting whether surface is in AGP or not
  DWORD dwSurfaceFlags;  // Various surface flags
  DWORD dwZMaskOffset;   // Offset into ZMask memory (Rage 6 and later only)
  DWORD dwZMaskSize;     // Size of allocation in blocks. (Rage 6 and later only)
  DWORD dwRevision;      // DDES spec revision number
  DWORD dwHiZOffset;     // Offset into HiZ memory ( R200 and later )
  DWORD dwHiZSize;       // Size of allocation in blocks. ( R200 and later )
  DWORD dwPadding[6];    // Padding to 16*4 bytes for alignment and extra room
} ATIDDESSURFDESC, *PATIDDESSURFDESC, *LPATIDDESSURFDESC;

// ATIDIRECTDRAWSURFDESC - the legacy structure used to pass data back to client
typedef struct _ATIDIRECTDRAWSURFDESC
{
  DWORD dwSize;          // Size of the structure returned
  DWORD dwOffset;        // Surface address or offset from base address as appropriate for ASIC
  DWORD dwTileFlags;     // Surface tile flags
  BOOL  bAGP;            // Boolean denoting whether surface is in AGP or not
} ATIDIRECTDRAWSURFDESC, *PATIDIRECTDRAWSURFDESC, *LPATIDIRECTDRAWSURFDESC;

//
//************************************Macros*********************************
//

// if the FOURCC_DDES #define isn't already defined, define it
#ifndef FOURCC_DDES
#ifndef MAKE_FOURCC
#define MAKE_FOURCC(ch0, ch1, ch2, ch3)\
		   ((DWORD)(BYTE)(ch0)|((DWORD)(BYTE)(ch1)<<8)|\
		   ((DWORD)(BYTE)(ch2)<<16)|((DWORD)(BYTE)(ch3)<<24))
#endif
#define ATI_FOURCC_DDES MAKE_FOURCC('D', 'D', 'E', 'S')
#define FOURCC_DDES ATI_FOURCC_DDES
#endif // #ifndef FOURCC_DDES

//
//************************************Defines*********************************
//


// Surface Creation and BLT Defines
#define ATI_DDES_BITCOUNT           16
#define ATI_DDES_WIDTH              32
#define ATI_DDES_HEIGHT             32
#define ATI_DDES_RECT_TOP_LEFT       0
#define ATI_DDES_RECT_BOTTOM_RIGHT   1 


// Tile Flags
#define ATI_DDES_NOT_TILED     0x00000000
#define ATI_DDES_MACRO_TILED   0x00000001
#define ATI_DDES_MICRO_TILED   0x00000002
#define ATI_DDES_TILED         (ATI_DDES_MACRO_TILED)

// Surface Flags
#define ATI_DDES_ZMASK_VALID   0x000000001
#define ATI_DDES_HIZ_VALID     0x000000002


#ifdef __cplusplus
}
#endif

#endif // _ATI_FOURCC_DDES_H


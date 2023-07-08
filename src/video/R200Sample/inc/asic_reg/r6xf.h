

/*****************************************************************************\
* 
*  Module Name    r6xf.h
*  Project        Rage6x WindowsNT
*  Device         Rage
*
*  Description    header file for Rage driver
*  
*
*  (c) 1998-2000 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
\*****************************************************************************/

//[TODO] This file needs to be moved back to ASIC_INC directory!!!![RA]

#ifndef _R6XF_H
#define _R6XF_H
 

//////////////////////////////////////////////////////////////////////////////
// These fields are specific to ONLY Chaplin (and are not compatible with other
// RADEON products...
//////////////////////////////////////////////////////////////////////////////


// These defines are ignored by Rage6x, and need to be here for
// binary compatible Rage6/Rage6x solution.
#define   SE_VTX_FMT__VTX_PKCOLOR_PRESENT   0x00000008L
#define   SE_VTX_FMT__VTX_ST0_PRESENT       0x00000080L
#define   SE_VF_CNTL__VTX_FMT_MODE          0x00000100L

#define RB3D_BLENDCNTL__R200_COMB_FCN__ADD_CLAMP            ( 0 << RB3D_BLENDCNTL__R200_COMB_FCN__SHIFT)
#define RB3D_BLENDCNTL__R200_COMB_FCN__ADD_NOCLAMP          ( 1 << RB3D_BLENDCNTL__R200_COMB_FCN__SHIFT)
#define RB3D_BLENDCNTL__R200_COMB_FCN__SUB_CLAMP            ( 2 << RB3D_BLENDCNTL__R200_COMB_FCN__SHIFT)
#define RB3D_BLENDCNTL__R200_COMB_FCN__SUB_NOCLAMP          ( 3 << RB3D_BLENDCNTL__R200_COMB_FCN__SHIFT)

#define RB3D_BLENDCNTL__SRCBLEND__D3D_ZERO                  ( 1 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__D3D_ONE                   ( 2 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__D3D_SRCCOLOR              ( 3 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__D3D_INVSRCCOLOR           ( 4 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__D3D_SRCALPHA              ( 5 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__D3D_INVSRCALPHA           ( 6 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__D3D_DESTALPHA             ( 7 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__D3D_INVDESTALPHA          ( 8 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__D3D_DESTCOLOR             ( 9 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__D3D_INVDESTCOLOR          (10 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__D3D_SRCALPHASAT           (11 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__D3D_BOTHSRCALPHA          (12 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__D3D_BOTHINVSRCALPHA       (13 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__GL_ZERO                   (32 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__GL_ONE                    (33 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__GL_SRC_COLOR              (34 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__GL_ONE_MINUS_SRC_COLOR    (35 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__GL_DST_COLOR              (36 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__GL_ONE_MINUS_DST_COLOR    (37 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__GL_SRC_ALPHA              (38 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__GL_ONE_MINUS_SRC_ALPHA    (39 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__GL_DST_ALPHA              (40 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)
#define RB3D_BLENDCNTL__SRCBLEND__GL_ONE_MINUS_DST_ALPHA    (41 << RB3D_BLENDCNTL__SRCBLEND__SHIFT)

#define RB3D_BLENDCNTL__DESTBLEND__D3D_ZERO                 ( 1 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__D3D_ONE                  ( 2 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__D3D_SRCCOLOR             ( 3 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__D3D_INVSRCCOLOR          ( 4 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__D3D_SRCALPHA             ( 5 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__D3D_INVSRCALPHA          ( 6 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__D3D_DESTALPHA            ( 7 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__D3D_INVDESTALPHA         ( 8 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__D3D_DESTCOLOR            ( 9 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__D3D_INVDESTCOLOR         (10 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__D3D_SRCALPHASAT          (11 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__D3D_BOTHSRCALPHA         (12 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__D3D_BOTHINVSRCALPHA      (13 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__GL_ZERO                  (32 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__GL_ONE                   (33 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__GL_SRC_COLOR             (34 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__GL_ONE_MINUS_SRC_COLOR   (35 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__GL_DST_COLOR             (36 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__GL_ONE_MINUS_DST_COLOR   (37 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__GL_SRC_ALPHA             (38 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__GL_ONE_MINUS_SRC_ALPHA   (39 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__GL_DST_ALPHA             (40 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)
#define RB3D_BLENDCNTL__DESTBLEND__GL_ONE_MINUS_DST_ALPHA   (41 << RB3D_BLENDCNTL__DESTBLEND__SHIFT)

#define RB3D_CNTL__COLORFORMAT_ARGB1555             (0x00000003 << RB3D_CNTL__COLORFORMAT__SHIFT)
#define RB3D_CNTL__COLORFORMAT_RGB565               (0x00000004 << RB3D_CNTL__COLORFORMAT__SHIFT)
#define RB3D_CNTL__COLORFORMAT_ARGB8888             (0x00000006 << RB3D_CNTL__COLORFORMAT__SHIFT)
#define RB3D_CNTL__COLORFORMAT_RGB332               (0x00000007 << RB3D_CNTL__COLORFORMAT__SHIFT)
#define RB3D_CNTL__COLORFORMAT_Y8                   (0x00000008 << RB3D_CNTL__COLORFORMAT__SHIFT)
#define RB3D_CNTL__COLORFORMAT_RGB8                 (0x00000009 << RB3D_CNTL__COLORFORMAT__SHIFT)
#define RB3D_CNTL__COLORFORMAT_VYUY422_8888         (0x0000000B << RB3D_CNTL__COLORFORMAT__SHIFT)
#define RB3D_CNTL__COLORFORMAT_YVYU422_8888         (0x0000000C << RB3D_CNTL__COLORFORMAT__SHIFT)
#define RB3D_CNTL__COLORFORMAT_AYUV444_8888         (0x0000000E << RB3D_CNTL__COLORFORMAT__SHIFT)
#define RB3D_CNTL__COLORFORMAT_ARGB4444             (0x0000000F << RB3D_CNTL__COLORFORMAT__SHIFT)

#define TXFORMAT_DATATYPE__8BPP_GREYSCALE_I         0x00000000
#define TXFORMAT_DATATYPE__16BPP_GREYSCALE_AI       0x00000001
#define TXFORMAT_DATATYPE__8BPP_RGB332              0x00000002
#define TXFORMAT_DATATYPE__16BPP_ARGB1555           0x00000003
#define TXFORMAT_DATATYPE__16BPP_RGB565             0x00000004
#define TXFORMAT_DATATYPE__16BPP_ARGB4444           0x00000005
#define TXFORMAT_DATATYPE__32BPP_ARGB8888           0x00000006
#define TXFORMAT_DATATYPE__32BPP_RGBA8888           0x00000007
#define TXFORMAT_DATATYPE__8BPP_Y8                  0x00000008
#define TXFORMAT_DATATYPE__AYUV444_8888             0x00000009
#define TXFORMAT_DATATYPE__VYUY422_8888             0x0000000A
#define TXFORMAT_DATATYPE__YVYU422_8888             0x0000000B
#define TXFORMAT_DATATYPE__CCC_NO_TO_1_ALPHA        0x0000000C
#define TXFORMAT_DATATYPE__CCC_EXP_ALPHA            0x0000000E
#define TXFORMAT_DATATYPE__CCC_CMP_ALPHA            0x0000000F
#define TXFORMAT_DATATYPE__16BPP_SHADOW             0x00000010
#define TXFORMAT_DATATYPE__32BPP_SHADOW             0x00000011
#define TXFORMAT_DATATYPE__8U8V_BUMP_MAP	    0x00000014
#define TXFORMAT_DATATYPE__5U5V6L_BUMP_MAP	    0x00000015	
#define TXFORMAT_DATATYPE__8U8V8L_BUMP_MAP	    0x00000016	

#endif /* end _R6XF_H */

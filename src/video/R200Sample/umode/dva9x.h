/**************************************************************************************\
*                                                                                      *
* Module Name:     DVA9X.H                                                             *
* Project:         ATI DirectX-VA Driver for R200                                      *
* Description:     registers needed for ati dva driver                                 *
*                                                                                      *
* Copyringt (c) 2000 ATI Technologies Inc.                                             *
*                                                                                      *
* All rights reserved.                                                                 *
* The year included in the forgoing notice is the year of creation of work.            *
*                                                                                      *
* Log of Changes                                                                       *
* --------------                                                                       *
* Version    Date        Author        Description                                     *
* 1.0     04/14/2000    Henry Law      Initial revision                                *
*                                                                                      *
\**************************************************************************************/


#ifndef __DVA9X_H
#define __DVA9X_H

#define IDCT_PKT_HDR            0xc0003100
#define PITCH_SH                3

#define MC_PITCHx1              0
#define MC_PITCHx2              0x40000000
#define MC_PITCHx4              0x80000000

#define MC_SRC_Y_SHIFT          16
#define MC_DST_X_SHIFT          16

#define MC_CNTL_WH_16x16        0xC0000000 //110...
#define MC_CNTL_WH_16x8         0xA0000000 //101...
#define MC_CNTL_WH_8x8          0x20000000 //001...
#define MC_CNTL_WH_8x4          0x00000000 //000...
#define MC_SRCINDEX2_SHIFT      26

#define PM4F_EOF_BLOCK          0
#define PM4F_RUN_AND_LEVEL      1
#define PM4F_V_PLANE            3
#define PM4F_2D_2VECTOR         5
#define PM4F_1D_2VECTOR         6
#define PM4F_INTRA_MBLOCK       7


#define IDCT_ALT_SCAN           16
#define IDCT_LUMA_012           0
#define IDCT_LUMA_024           1
#define IDCT_LUMA_081           2
#define IDCT_CHROMA_012         0
#define IDCT_CHROMA_024         4

#define PT_FIELD_BASED          0x1
#define PT_FRAME_BASED          0x2
#define PT_16x8_MC              0x2
#define PT_DUAL_PRIME           0x3

#endif


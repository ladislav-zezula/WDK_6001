

//    
//  $Workfile: ipt.h $
//  $Revision: 4 $
//
//  Description:
//

//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

 
//  @IPT.H
//  Author: Jianing Dai, Driver Research Team
//  Date: Feb. 18, 1998
//
//  Revision Record:
//  
//  Added new packet PM4_PACKET3_CNTL_TRANS_BITBLT on Apr. 16, 1998
//  Added new packet PM4_PACKET3_PLY_NEXTSCAN   on Apr. 20, 1998
//  Added new packet PM4_PACKET3_WAIT_FOR_IDLE  on May 20, 1998

//  This file contains the definition of IT_OPCODEs of PM4 packets and the
//  external defintion of the aPM4_Microcode array.

#ifndef _IPT_H_
#define _IPT_H_

#ifdef __cplusplus
extern "C" {
#endif  //  __cplusplus

#define PM4_MICROCODE_SIZE  256                 // Size of PM4 microcode in QWORD

//  Empty headers of type-0,1,2 packets

#define PM4_PACKET0_NOP     0x00000000          // Empty header of type-0 packtes
#define PM4_PACKET1_NOP     0x40000000          // Empty header of type-1 packtes
#define PM4_PACKET2_NOP     0x80000000          // Empty header of type-2 packtes (reserved)

//  IT_OPCODEs for type-3 packets without the DP_GUI_MASTER_CNTL block.
#define PM4_PACKET3_NOP                 0xC0001000      // Do nothing.
#define PM4_PACKET3_PAINT               0xC0001100      // Paint with brush using a solid colour.
#define PM4_PACKET3_BITBLT              0xC0001200      // Bitblt and source copy.
#define PM4_PACKET3_SMALLTEXT           0xC0001300      // Draw small glyphs on the screen.
#define PM4_PACKET3_HOSTDATA_BLT        0xC0001400      // Draw large glyphs or bitmap through
                                                        // hostdata register writes.
#define PM4_PACKET3_POLYLINE            0xC0001500      // Draw a polyline.
#define PM4_PACKET3_SCALING             0xC0001600      // Scaling operation for ROP3 and pattern.
#define PM4_PACKET3_TRANS_SCALING       0xC0001700      // Transparent scaling.

#define PM4_PACKET3_PLY_NEXTSCAN        0xC0001D00      // Draw polyscanlines using current setup. 
#define PM4_PACKET3_PAINT_MULTI         0xC0001A00      // Paint multiple Rect. y_x and height_width with brush 
                                                        // without the setup body..
#define PM4_PACKET3_BITBLT_MULTI        0xC0001B00      // Multiple BITBLTs without the setup body.

#define PM4_PACKET3_SETDSTSCISSORS      0xC0001E00      // Set the DST scissors.
#define PM4_PACKET3_INIT_24BPP          0xC0001F00      // Turn on 24bpp
#define PM4_PACKET3_LOAD_PALETTE        0xC0002C00      // Load palette

#define PM4_PACKET3_LDDM_HANDLE(ResType) (PM4_PACKET3_NOP | ResType | ((sizeof(D3DKMT_HANDLE)/sizeof(DWORD)-1) << 16))

//  IT_OPCODEs for type-3 packets with the DP_GUI_MASTER_CNTL block.
#define PM4_PACKET3_CNTL_PAINT          0xC0009100      // Paint Rect. y_x and bottom_right with brush using a solid colour.
#define PM4_PACKET3_CNTL_BITBLT         0xC0009200      // Bitblt and source copy.
#define PM4_PACKET3_CNTL_SMALLTEXT      0xC0009300      // Draw small glyphs on the screen.
#define PM4_PACKET3_CNTL_HOSTDATA_BLT   0xC0009400      // Draw large glyphs or bitmap through
                                                        // hostdata register writes.
#define PM4_PACKET3_CNTL_POLYLINE       0xC0009500      // Draw a polyline. 
#define PM4_PACKET3_CNTL_SCALING        0xC0009600      // Scaling operation for ROP3 and pattern.
#define PM4_PACKET3_CNTL_TRANS_SCALING  0xC0009700      // Transparent scaling.
#define PM4_PACKET3_CNTL_POLYSCANLINES  0xC0009800      // Draw polyscanlines or scanlines.
#define PM4_PACKET3_CNTL_NEXT_CHAR      0xC0009900      // Draw large glyphs or bitmap through
                                                        // hostdata register writes without fore- and
                                                        // back-ground colour writes.
#define PM4_PACKET3_CNTL_PAINT_MULTI    0xC0009A00      // Paint multiple Rect. y_x and height_width with brush  .
#define PM4_PACKET3_CNTL_BITBLT_MULTI   0xC0009B00      // Multiple Bitblits .
#define PM4_PACKET3_CNTL_TRANS_BITBLT   0xC0009C00      // 3D Transparent BitBlt.

//  IT_OPCODEs for 3D packets
#define PM4_PACKET3_3D_SAVE_CONTEXT         0xC0002000      // General purpose context saving.
#define PM4_PACKET3_3D_PLAY_CONTEXT         0xC0002100      // Play back the context saved previously.
#define PM4_PACKET3_3D_RNDR_GEN_INDX_PRIM   0xC0002300      // Draw objetcs through the Vertex Walker.
#define PM4_PACKET3_3D_RNDR_GEN_PRIM        0xC0002500      // Draw points, lines,strips, fans, and
#define PM4_PACKET3_LOAD_MICROCODE          0xC0002400      // Load Microcode of PM4
                                                            // independent triangles.
#define PM4_PACKET3_WAIT_FOR_IDLE           0xC0002600      // Waite for the engine to be idle. 
#define PM4_PACKET3_MPEG_IDCT_MACROBLOCK    0xC0003000      // MPEG Inverse Discrete Cosine Transformation

// New 3D packets for Rage5.
#define PM4_PACKET3_3D_DRAW_VBUF        0xC0002800      // Draw primitive using vertex buffer
#define PM4_PACKET3_3D_DRAW_IMMD        0xC0002900      // Draw primitives using immediate vertices in the packet
#define PM4_PACKET3_3D_DRAW_INDX        0xC0002A00      // Draw primitives using vertex buffer and indcies in this packet.
#define PM4_PACKET3_3D_LOAD_VBPNTR      0xC0002F00      // Load pointers to vertex buffers
#define PM4_PACKET3_3D_CLEAR_ZMASK      0xC0003200      // Clear portion of ZMask memory

#define PM4_PACKET3_VB_BASE_ADDR        0xC0001900      // Set VB base addr
#define PM4_PACKET3_VB_OFFSET           0xC0001800      // Set VB stream offsets

#define PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV 0xC0003100      // 

// Chaplin packets
#define PM4_PACKET3_INDX_BUFFER         0xC0003300      // Load indices using Indirect Buffer # 2
#define PM4_PACKET3_3D_DRAW_VBUF_2      0xC0003400      // Same as 3D_DRAW_VBUF but without SE_VTX_FMT
#define PM4_PACKET3_3D_DRAW_IMMD_2      0xC0003500      // Same as 3D_DRAW_IMMD but without SE_VTX_FMT
#define PM4_PACKET3_3D_DRAW_INDX_2      0xC0003600      // Same as 3D_DRAW_INDX but without SE_VTX_FMT
#define PM4_PACKET3_3D_CLEAR_HIZ        0xC0003700      // Clear portion of the Hierarchal Z RAM

extern  unsigned long aPM4_Microcode[PM4_MICROCODE_SIZE][2];    // PM4 microcode

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // _IPT_H_


//
// $Archive: /3D/D3D/d3drage5/Rage5Direct3D/inc/common/ipt.h $
// $Author: Merwin $
// $Revision: 4 $
// $Date: 6/17/99 2:52p $
// $Modtime: 6/17/99 9:44a $
// $History: ipt.h $
// 
// *****************  Version 4  *****************
// User: Merwin       Date: 6/17/99    Time: 2:52p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// fixed blits using 8bpp palettized source
// 
// *****************  Version 3  *****************
// User: Cjiang       Date: 5/24/99    Time: 1:45p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// Added 5 new 3D packets for Rage5 such as clearZMask and DrawVBuf.
// 
// *****************  Version 2  *****************
// User: Jweyman      Date: 2/16/99    Time: 5:17p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// added header/footer
//


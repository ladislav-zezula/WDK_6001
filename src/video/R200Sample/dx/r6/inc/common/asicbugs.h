

//    
//  $Workfile: asicbugs.h$
//
//  Description:
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _ASICBUGS_H
#define _ASICBUGS_H
 

#define ASICBUG_3D1_ERROR_DIFUSSION_DITHER         0x00000001L
#define ASICBUG_3D1_32BPP_WRITE_MASK               0x00000002L
#define ASICBUG_3D1_STENCIL_UNDERFLOW              0x00000004L
#define ASICBUG_3D1_STENCIL_WRAP                   0x00000008L

#define ASICBUG_3D1_ANISO_16_1                     0x00000010L
#define ASICBUG_3D1_ANISO_STEP                     0x00000020L
#define ASICBUG_3D1_MIPMAP_TEXTURE_MISS            0x00000040L
#define ASICBUG_3D1_MAX_ANISIO                     0x00000080L

#define ASICBUG_3D1_BUMPMAPPING                    0x00000100L
#define ASICBUG_3D1_THREETEXTUREBUG                0x00000200L
#define ASICBUG_3D1_BADVERTEXCULL                  0x00000400L
#define ASICBUG_3D1_BUMPWAVES                      0x00000800L

#define ASICBUG_3D1_ZCOMPRESSION                   0x00001000L
#define ASICBUG_3D1_HIERARCHICALZ                  0x00002000L
#define ASICBUG_3D1_NULLPRIMITIVE                  0x00004000L
#define ASICBUG_3D1_ZMASKL0BUG                     0x00008000L

#define ASICBUG_3D1_T2T0HANG                       0x00010000L
#define ASICBUG_3D1_ANISOHANG                      0x00020000L
#define ASICBUG_3D1_DEGEN_TEXCOORDS_SAMPLE         0x00040000L
#define ASICBUG_3D1_RESERVED20                     0x00080000L

#define ASICBUG_3D1_RESERVED21                     0x00100000L
#define ASICBUG_3D1_RESERVED22                     0x00200000L
#define ASICBUG_3D1_RESERVED23                     0x00400000L
#define ASICBUG_3D1_RESERVED24                     0x00800000L

#define ASICBUG_3D1_RESERVED25                     0x01000000L
#define ASICBUG_3D1_RESERVED26                     0x02000000L
#define ASICBUG_3D1_RESERVED27                     0x04000000L
#define ASICBUG_3D1_RESERVED28                     0x08000000L

#define ASICBUG_3D1_RESERVED29                     0x10000000L
#define ASICBUG_3D1_RESERVED30                     0x20000000L
#define ASICBUG_3D1_RESERVED31                     0x40000000L
#define ASICBUG_3D1_RESERVED32                     0x80000000L


#define ASICBUG_3D2_YUVBlit                        0x00000001L		   
#define ASICBUG_3D2_CYLINDRICALWRAPHANG            0x00000002L		   

#define ASICBUG_3D2_Redirect8BPPARGBL              0x00000004L

#define ASICBUG_3D2_HWFogValueClamplingBug         0x00000008L

#define ASICBUG_3D2_TxZeroBug                      0x00000010L          
#define ASICBUG_3D2_HWMultipassHang                0x00000020L          
#define ASICBUG_3D2_HWDataDropBug                  0x00000040L          
#define ASICBUG_3D2_HWPerformanceIssue             0x00000080L          

#define ASICBUG_3D2_YUVTexture                     0x00000100L          
#define ASICBUG_3D2_DP4X8ConstantPrecision         0x00000200L          
#define ASICBUG_3D2_RESERVED11                     0x00000400L
#define ASICBUG_3D2_RESERVED12                     0x00000800L

#define ASICBUG_3D2_RESERVED13                     0x00001000L
#define ASICBUG_3D2_RESERVED14                     0x00002000L
#define ASICBUG_3D2_RESERVED15                     0x00004000L
#define ASICBUG_3D2_RESERVED16                     0x00008000L

#define ASICBUG_3D2_RESERVED17                     0x00010000L
#define ASICBUG_3D2_RESERVED18                     0x00020000L
#define ASICBUG_3D2_RESERVED19                     0x00040000L
#define ASICBUG_3D2_RESERVED20                     0x00080000L

#define ASICBUG_3D2_RESERVED21                     0x00100000L
#define ASICBUG_3D2_RESERVED22                     0x00200000L
#define ASICBUG_3D2_RESERVED23                     0x00400000L
#define ASICBUG_3D2_RESERVED24                     0x00800000L

#define ASICBUG_3D2_RESERVED25                     0x01000000L
#define ASICBUG_3D2_RESERVED26                     0x02000000L
#define ASICBUG_3D2_RESERVED27                     0x04000000L
#define ASICBUG_3D2_RESERVED28                     0x08000000L

#define ASICBUG_3D2_RESERVED29                     0x10000000L
#define ASICBUG_3D2_RESERVED30                     0x20000000L
#define ASICBUG_3D2_RESERVED31                     0x40000000L
#define ASICBUG_3D2_RESERVED32                     0x80000000L


#endif // _ASICBUGS_H


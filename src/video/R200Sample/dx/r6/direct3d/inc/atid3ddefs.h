

//
//  $Workfile: atidefs.h $
//
//  Description:
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef ATIDEFS_H
#define ATIDEFS_H

#include "features.h"
#include "ativbinfo.h"

////////////////////////////////////////////////////////////////////////////////
// General Defines file. This file will be included at the VERY TOP of most   //
// files, so no dependants please!                                            //
////////////////////////////////////////////////////////////////////////////////

#define CB_MAX_SIZE_DWORDS          ((64*1024)/sizeof(DWORD))
#define CB_MIN_SIZE_DWORDS          ((8*1024)/sizeof(DWORD))


// for type 3 packets
#define SIZE_OF_PRIM_HEADER         3                   // number of DWORDS for a 3D render packet header
#define SIZE_OF_IB_USING_TYPE_3     6                   // number of DWORDS for the 3D index buffer packets
#define SIZE_OF_IB_USING_GUI_DMA    10                  // number of DWORDS for IBs if using GUI DMA
#define MAX_PACKET_SIZE_DWORDS      0x4000              // max number of DWORDS allowed in the body of a type3 packet.
#define MAX_HWIB_PRIMS              21847               // Used solely for the hardware index buffer rendering

// The maximum number of DWORDS per vertex is calculated thusly:
//   4 - Position
//   3 - Normal
//   4 - vertex blend weights
//   1 - Diffuse Color
//   1 - Specular Color
//  12 - 3 Texture coordinate sets * 4 coords per set
//   4 - Position 2
//   3 - Normal 2

#define MAX_VERTEX_SIZE_DWORDS      32                  // max number of DWORDS per vertex
#define MAX_VERTEX_SIZE_BYTES       (MAX_VERTEX_SIZE_DWORDS << 2)
#define MAX_VERTS_PER_PRIM           3

#define MAX_FFTCLSTATE_SIZE          821                // Max number of dwords for TCL states.
#define MAX_PVSSTATE_SIZE            2 * (ATI_R200_PVS_CODE_SIZE_SEG + ATI_R200_PVS_STATE_SIZE_SEG) + 24
#define MAX_VAPSTATE_SIZE            MAX(MAX_FFTCLSTATE_SIZE, MAX_PVSSTATE_SIZE)

#define VBSYSMEMPOOL_INITSIZE       (128*1024)      //128K
#define ContextPerBlock   256
#define LISTGROWSIZE      1024
#define MAX_NUM_CB_ID     2048
#define MAX_PRIM_COUNT   65535
#define MAX_NUM_VERTEX   65535

////////////////////////////////////////////////////////////////////////////////
// Render state related defines.                                              //
////////////////////////////////////////////////////////////////////////////////
#if(DIRECT3D_VERSION == 0x0900)

#define ATI_D3D_NORMALDEGREE            D3DRS_NORMALDEGREE
#define ATI_D3D_POSITIONDEGREE          D3DRS_POSITIONDEGREE

#define ATI_ENUM_D3DDEGREE_LINEAR       D3DDEGREE_LINEAR
#define ATI_ENUM_D3DDEGREE_QUADRATIC    D3DDEGREE_QUADRATIC
#define ATI_ENUM_D3DDEGREE_CUBIC        D3DDEGREE_CUBIC
#define ATI_ENUM_D3DDEGREE_QUINTIC      D3DDEGREE_QUINTIC

#define R200CYLWRAP_MIN_COUNT           0x20
#define R200CYLWRAP_2_FLUSH             0x10
#define R200CYLWRAP_6_FLUSH             0x04
#define R200CYLWRAP_2_TEX               0x00000002
#define R200CYLWRAP_6_TEX               0x00000008

#define ATI_D3DBLEND_BLENDFACTOR        43 // GL_CONSTANT_COLOR
#define ATI_D3DBLEND_INVBLENDFACTOR     44 // GL_ONE_MINUS_CONSTANT_COLOR

#endif  // (DIRECT3D_VERSION == 0x0900)

#if(DIRECT3D_VERSION == 0x0810)

#define ATI_D3D_NORMALDEGREE            D3DRS_NORMALORDER
#define ATI_D3D_POSITIONDEGREE          D3DRS_POSITIONORDER

#define ATI_ENUM_D3DDEGREE_LINEAR       D3DORDER_LINEAR
#define ATI_ENUM_D3DDEGREE_QUADRATIC    D3DORDER_QUADRATIC
#define ATI_ENUM_D3DDEGREE_CUBIC        D3DORDER_CUBIC
#define ATI_ENUM_D3DDEGREE_QUINTIC      D3DORDER_QUINTIC

#endif  // (DIRECT3D_VERSION == 0x0810)

#if   (DIRECT3D_VERSION >= 0x0900)
#define MAX_RENDER_STATES  (D3DRS_BLENDOPALPHA + 1)
#elif (DIRECT3D_VERSION == 0x0810)
#define MAX_RENDER_STATES  (ATI_D3D_NORMALDEGREE + 1)
#else//(DIRECT3D_VERSION < 0x0810)
#define MAX_RENDER_STATES  (D3DRS_BLENDOP + 1)
#endif

#if   (DIRECT3D_VERSION >= 0x0900)
#define MAX_DP2S           (D3DDP2OP_SURFACEBLT + 1)
#elif (DIRECT3D_VERSION >= 0x0800)
#define MAX_DP2S           (D3DDP2OP_ADDDIRTYBOX + 1) //D3DDP2OP_RESERVE3 only defined in DX9!!
#else//(DIRECT3D_VERSION < 0x0800)
#define MAX_DP2S           (D3DDP2OP_SETCLIPPLANE + 1)
#endif

#define MAX_PRIM_TYPE 7 //6 prim types starting from 1.

#if   (DIRECT3D_VERSION >= 0x0900)
#define MAX_TSS (D3DTSS_CONSTANT + 1)
#else
#define MAX_TSS (D3DTSS_RESULTARG + 1)
#endif //(DIRECT3D_VERSION >= 0x0900)

#define MAX_TA 6
#define MAX_TOP 26

#define MAX_STATE       D3DSTATE_OVERRIDE_BIAS
#define DWORD_BITS      32
#define DWORD_SHIFT     5

#define ZBIAS_CONST_FACTOR 18000.0f
#define WBIAS_CONST_FACTOR 12000.0f

////////////////////////////////////////////////////////////////////////////////
// Macros:                                                                    //
////////////////////////////////////////////////////////////////////////////////
#define MIN(a, b)    ( ((a) < (b)) ? (a) : (b) )
#define MAX(a, b)    ( ((a) > (b)) ? (a) : (b) )
#define  MemFlags  (GMEM_FIXED | GMEM_ZEROINIT)

#define make1_Tex_Size_Pitch(dwTex_Pitch, dwTex_Height, dwTex_Size)  \
         ( dwTex_Pitch  <<TEX_SIZE_PITCH__TEX_PITCH_SHIFT |\
           dwTex_Height <<TEX_SIZE_PITCH__TEX_HEIGHT_SHIFT |\
           dwTex_Size   <<TEX_SIZE_PITCH__TEX_SIZE_SHIFT )

#define make2_Tex_Size_Pitch(dwTex_Size_Pitch, dwTex_Min_Size)  \
         ( dwTex_Size_Pitch | dwTex_Min_Size << TEX_SIZE_PITCH__TEX_MIN_SIZE_SHIFT )

////////////////////////////////////////////////////////////////////////////////
// Texture related constants.                                                 //
////////////////////////////////////////////////////////////////////////////////
// ** DX6 **

// Chaplin (R200) Defines

#define ATI_RAD2_NUM_TEX_UNITS   6
#define ATI_RAD2_NUM_BLEND_INST  8
#define ATI_RAD2_NUM_ADDR_INST   8
#define ATI_RAD2_NUM_PS_CONSTS   8


#define ATI_MAX_NUM_TEX_UNITS   6      // MAX( R100, R200 )
#define ATI_MAX_NUM_TEX_BLENDERS    8


#define MAX_TEXSTAGE            8

#define MAX_MIPMAP_LEVEL        11
#define ATiMinTextureWH         1
#define ATiMaxTextureWH         2048
#define MAX_ANISOTROPY          16L
#define ATI_GUARD_BAND          2048

// Stipple table size
#define STIPPLE_PATTERN_SIZE    32
// Fog table size
#define FOGTABLE_SIZE           256

#define ATIMINVOLUMETEXTURE_WH  1
#define ATIMAXVOLUMETEXTURE_WH  256
#define ATIMAXVOLUMETEXTURE_EX  256

#define ATI_MAX_POINTSPRITE_SIZE 256

#if(DIRECT3D_VERSION >= 0x0900)
// Primitive-level AntiAliasing (in the PP_CNTL register)
#define ATI_AA_NONE             0
#define ATI_AA_LINE             1
#define ATI_AA_TRI              2
#define ATI_AA_LINE_TRI         3
#endif//(DIRECT3D_VERSION >= 0x0900)

////////////////////////////////////////////////////////////////////////////////
// MAX_SURF_PER_TRI:                                                          //
//     The max number of surfaces we will have for each primitive: back buffer//
//     , z buffer and the texture surfaces.                                     //
// FirstContext:                                                              //
//     It's illegal to return a contecxt handle of 0.                         //
////////////////////////////////////////////////////////////////////////////////
#define MAX_SURF_PER_TRI        (2 + ATI_MAX_NUM_TEX_UNITS)
#define FirstContext            1


////////////////////////////////////////////////////////////////////////////////
// TCL-related constants                                                      //
////////////////////////////////////////////////////////////////////////////////
#define ATI_NUM_LIGHTS          8
#define ATI_NUM_CLIP_PLANES     6
#define ATI_NUM_BLEND_MATRICES  4
#define ATI_NUM_TEX_MATRICES    6

//
// ATI_MAX_NUM_MATRICES
// There are only 16 in Rage 6. Rage 6 driver never accesses more than 16.
#define ATI_MAX_NUM_MATRICES    22


// Vertex Shader Defines
#define ATI_VS_CONST_SIZE       192
#define ATI_VS_CODE_SIZE        128

////////////////////////////////////////////////////////////////////////////////
// Render state dirty flags.                                                  //
////////////////////////////////////////////////////////////////////////////////
#define PPMISC_DIRTY            0x00000001
#define ALPHA_BLEND_DIRTY       0x00000002
#define DEPTH_SURFACE_DIRTY     0x00000004
#define PPCNTL_DIRTY            0x00000008
#define RB3D_CNTL_DIRTY         0x00000010
#define RENDER_SURFACE_DIRTY    0x00000020
#define SE_CNTL_DIRTY           0x00000040
#define SE_COORD_FMT_DIRTY      0x00000080 // CHAPLIN_TODO: Chaplin uses this as a dirty bit for SE_VTE_CNTL
#define TEXTURES_DIRTY          0x00000100
#define DEPTH_CACHE_DIRTY       0x00000200
#define DEPTH_HIZ_DIRTY         0x00000400
#define PSHADER_DIRTY           0x00000800     // Chaplin (R200)
#define STIPPLE_DIRTY           0x00001000
#define SCISSOR_DIRTY           0x00002000
//#define RESERVED_DIRTY        0x00004000
#define VERTEX_SHADER_DIRTY     0x00008000
#define CHROMA_DIRTY            0x00010000
#define BORDER_DIRTY            0x00020000
#define FOGTABLE_DIRTY          0x00040000
#define COLOR_CMP_DIRTY         0x00080000
#define STENCILREFMASK_DIRTY    0x00100000
#define MISC_BLOCK2_DIRTY       0x00200000
#define SETUP_DIRTY             0x00400000
#define FOGCOLOR_DIRTY          0x00800000
#define LINEPATTERN_DIRTY       0x01000000
#define HOS_DIRTY               0x02000000
#define VBPNTR_DIRTY            0x04000000
#define TFACTOR_DIRTY           0x08000000
#define VTX_PROC_MODE_DIRTY     0x10000000
#define SE_VTX_FMT_DIRTY        0x20000000
#define RE_JITTERTBL_DIRTY      0x40000000

//////////////////////////////////////////
// Texture Dirty Bits
#define TEX_T0_DIRTY            0x00000001
#define TEX_T1_DIRTY            0x00000002
#define TEX_T2_DIRTY            0x00000004
#define TEX_T3_DIRTY            0x00000008
#define TEX_T4_DIRTY            0x00000010
#define TEX_T5_DIRTY            0x00000020
#define TEX_CUBICMAP_DIRTY      0x00000040
#define TEX_BUMPMAP_DIRTY       0x00000080

#define ATI_CNTX_DIRTY_ALL      0xFFFFFFFF

#define NUM_MISC_BLOCK1         3
#define NUM_Z_OFF_PITCH         5
#define NUM_Z_OFF_PITCH_1_PIGLET 3
#define NUM_Z_OFF_PITCH_2_PIGLET 2
#define NUM_Z_OFF_PITCH_RV200   3

#define NUM_COLOR_OFF_PITCH     3
#define NUM_TEX_BLOCK           6
#define NUM_TEX_SIZE_PITCH      2
#define NUM_TEX3_BLOCK          3
#define NUM_STIPPLE_BLOCK       4
#define NUM_SCISSOR_BLOCK       6
#define NUM_CUBIC_FACE_BLOCK    3
#define NUM_CUBIC_OFFSET_BLOCK  5
#define NUM_CHROMA_BLOCK        2
#define NUM_BORDER_BLOCK        3
//#define NUM_FOGTABLE_BLOCK      2
#define NUM_COLOR_CMP_BLOCK     4
#define NUM_MISC_BLOCK2         2
#define NUM_SETUP_BLOCK         10
#define NUM_BUMPMAP_BLOCK       2

#define NUM_PIXSHADER_BLOCK      32
#define NUM_ADRSHADER_BLOCK      32
#define NUM_BUMPMAP_MATRIX_BLOCK 3
#define NUM_PP_TX_BLOCK          3
#define NUM_PP_TX_BLOCK2         5
#define NUM_TFACTOR_BLOCK        5
#define NUM_JITTERTBL_BLOCK      2

//
// These defines are used with the dwRecalcTexStages field in the context
// to form a dirty bit scheme. This dirty bit scheme allows us to process
// as little texture stage/pixel shader information as possible between
// each draw operation.
//
#define ATI_RECALC_NONE           0
#define ATI_RECALC_TEXUNITS       ( 1 << 0 )
#define ATI_RECALC_COLORBLENDERS  ( 1 << 1 )
#define ATI_RECALC_ALPHABLENDERS  ( 1 << 2 )
#define ATI_RECALC_PIXELSHADER    ( 1 << 3 )
#define ATI_RECALC_TEXSTATE       ( 1 << 4 )
#define ATI_RECALC_ALL            ( ATI_RECALC_TEXUNITS       | \
                                    ATI_RECALC_COLORBLENDERS  | \
                                    ATI_RECALC_ALPHABLENDERS  | \
                                    ATI_RECALC_PIXELSHADER    | \
                                    ATI_RECALC_TEXSTATE )

// This enum is used by registry key DitherAlpha for controlling dither
// operations during alpha blending to prevent "dither build up".
// These values are chosen to be set directly to the SCALE_DITHER hw bitfield.
typedef enum _EDITHERMODE
{
    E_DITHER_DIFFUSION = 0,
    E_DITHER_SPATIAL   = 1
} EDITHERMODE;

typedef enum _E_TX_ROUTING_MODE
{
    E_TX_ROUTING_HAL = 0,                   // HAL responsible for TX Coord Routing
    E_TX_ROUTING_TCL = 1,                   // TCL responsible for TX Coord Routing
    E_E_TX_ROUTING_FORCE_DWORD = 0xffffffff
} ETXROUTING_MODE;

typedef enum _EVTXPROCMODE
{
    E_VTXPROCMODE_SW          = 0,           // Software vertex processing
    E_VTXPROCMODE_HW_FF       = 1,           // Hardware vertex processing, fixed function TCL
    E_VTXPROCMODE_HW_PVS      = 2,           // Hardware vertex processing, programmable vertex shader
    E_VTXPROCMODE_FORCE_DWORD = 0xffffffff
} EVTXPROCMODE, *LPEVTXPROCMODE;


#define R5_BYTES_TO_ZOFFSET_UNITS(o) ((o) >> 4)
#define R5_BYTES_TO_OFFSET_UNITS(o) ((o) >> 4)

#define R200_BYTES_TO_ZOFFSET_UNITS(o) ((o) >> 12)

////////////////////////////////////////////////////////////////////////////////
// QSSubmitList: dwFlags                                                      //
////////////////////////////////////////////////////////////////////////////////
//#define D3D_TIMESTAMP_FLAGS   (QS_FLAG_TIMESTAMP_RETIRED | QS_FLAG_TIMESTAMP_CONSUMED)
#define D3D_TIMESTAMP_FLAGS   (QS_FLAG_TIMESTAMP_RETIRED)

typedef void (*VOIDFUNC)();

////////////////////////////////////////////////////////////////////////////////
// dwVBMemLoader settings                                                     //
////////////////////////////////////////////////////////////////////////////////
#define VB_MEM_LOADER_ALL                0xffffffff
#define VB_MEM_LOADER_STATIC_VERTEX      0x00000001
#define VB_MEM_LOADER_DYNAMIC_VERTEX     0x00000002
#define VB_MEM_LOADER_XYZ_DX7            0x00000004 // DX7 untransformed
#define VB_MEM_LOADER_XYZRHW_DX7         0x00000008 // DX7 transformed
#define VB_MEM_LOADER_STATIC_INDEX       0x00000010
#define VB_MEM_LOADER_DYNAMIC_INDEX      0x00000020
#define VB_MEM_LOADER_INTERNAL           0x00000040

////////////////////////////////////////////////////////////////////////////////
// dwHwIb settings                                                            //
////////////////////////////////////////////////////////////////////////////////
#define HW_IB_ALL                        0x00000007
#define HW_IB_STATIC                     0x00000001
#define HW_IB_DYNAMIC                    0x00000002
#define HW_IB_STATIC_SYSTEM_COPY         0x00000004
#define HW_IB_RESERVED                   0x00000008


//////////////////////////////////////////////////////////////////////////////////
//  DX8 - Specific Stuff                                                        //
//////////////////////////////////////////////////////////////////////////////////
// these three really should be included in DX8 DDK, but they're not
// included yet, so define them here.

#define D3DCOLORWRITEENABLED_RED        0x000000001
#define D3DCOLORWRITEENABLED_GREEN      0x000000002
#define D3DCOLORWRITEENABLED_BLUE       0x000000004
#define D3DCOLORWRITEENABLED_ALPHA      0x000000008

//////////////////////////////////////////////////////////////////////////////////
//  Defines to detect DX runtime version                                        //
//////////////////////////////////////////////////////////////////////////////////
// Refer to the original definition in ddrawi.h - DD_RUNTIME_VERSION
#define ATI_DXRUNTIME_VERSION_DX9   0x00000902l
#define ATI_DXRUNTIME_VERSION_DX81  0x00000802l
#define ATI_DXRUNTIME_VERSION_DX8   0x00000800l

//////////////////////////////////////////////////////////////////////////////////
//  Inline Functions Common to R100 and R200                                    //
//////////////////////////////////////////////////////////////////////////////////

/****************************************************************************
* DWORD CalcNumTexCoordSets(DWORD dwFVFType)
*
* Args:
*       dwFVFType - The FVF from which to extract the number of Texture
*                   Coordinate Sets.
*
* Returns:
*       A DWORD containing the number of texture coordinante sets contained
*       in the provided FVF.
*
* Description:
*       Apply the appropriate DX "mask" and "shift" to extract the number of
*       Texture Coordinate Sets from the provided FVF.
*****************************************************************************/
__inline DWORD CalcNumTexCoordSets(DWORD dwFVFType)
{
    return (dwFVFType & D3DFVF_TEXCOUNT_MASK) >> D3DFVF_TEXCOUNT_SHIFT;
}

#endif // ATIDEFS_H



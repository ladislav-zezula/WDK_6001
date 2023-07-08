

//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _ATI3DCAPS_H
#define _ATI3DCAPS_H

#include "atidxinc.h"

DWORD __stdcall ContextCreate32(LPD3DHAL_CONTEXTCREATEDATA pccd);
DWORD __stdcall ContextDestroy32(LPD3DHAL_CONTEXTDESTROYDATA pcdd);
 
/****************************************************
**                                                 **
**       Direct3D  Caps                            **
**                                                 **
*****************************************************/

#ifdef NULLDRV
#define MaxVertexCount    2048
#else
#define MaxVertexCount       0
#endif

#define RAGE6A_BUMPMAP_FIXED 0

/***************************************************************************/
/*                        CAPS MACROS                                      */
/***************************************************************************/


//-----------------------------------------------------------------------------
// miscCaps - LINE
#if (DIRECT3D_VERSION >= 0x0900)
#define ATID3DPMISC_LINECAPS                                                  \
    D3DPMISCCAPS_MASKPLANES                 |                                 \
    D3DPMISCCAPS_MASKZ                      |                                 \
    D3DPMISCCAPS_COLORWRITEENABLE           |           /* added for DX8 */   \
    D3DPMISCCAPS_TSSARGTEMP                 |           /* added for DX8 */   \
    0/*D3DPMISCCAPS_LINEPATTERNREP */       |                                 \
    0/*D3DPMISCCAPS_INDEPENDENTWRITEMASKS*/ |           /* added for DX9 */   \
    0/*D3DPMISCCAPS_PERSTAGECONSTANT*/      |           /* added for DX9 */   \
    0/*D3DPMISCCAPS_FOGANDSPECULARALPHA*/               /* added for DX9 */

#else  // (DIRECT3D_VERSION < 0x0900)
#define ATID3DPMISC_LINECAPS                                                  \
    D3DPMISCCAPS_MASKPLANES                 |                                 \
    D3DPMISCCAPS_MASKZ                      |                                 \
    D3DPMISCCAPS_COLORWRITEENABLE           |           /* added for DX8 */   \
    D3DPMISCCAPS_TSSARGTEMP                 |           /* added for DX8 */   \
    D3DPMISCCAPS_LINEPATTERNREP
#endif // (DIRECT3D_VERSION)

// miscCaps - TRI
#define ATID3DPMISC_TRICAPS                                                   \
    D3DPMISCCAPS_CULLCCW                    |                                 \
    D3DPMISCCAPS_CULLCW                     |                                 \
    D3DPMISCCAPS_CULLNONE                   |                                 \
    ATID3DPMISC_LINECAPS

//-----------------------------------------------------------------------------
// rasterCaps - LINE
#if (DIRECT3D_VERSION >= 0x0900)
#define ATID3DPRASTER_LINECAPS                                                \
    D3DPRASTERCAPS_DITHER                     |                               \
    D3DPRASTERCAPS_ROP2                       |                               \
    D3DPRASTERCAPS_XOR                        |                               \
    D3DPRASTERCAPS_PAT                        |                               \
    D3DPRASTERCAPS_ZTEST                      |                               \
    D3DPRASTERCAPS_SUBPIXEL                   |                               \
    D3DPRASTERCAPS_STIPPLE                    |                               \
    D3DPRASTERCAPS_FOGVERTEX                  |                               \
    D3DPRASTERCAPS_ANTIALIASSORTDEPENDENT     |                               \
    D3DPRASTERCAPS_ANTIALIASSORTINDEPENDENT   |                               \
    D3DPRASTERCAPS_ANTIALIASEDGES             |                               \
    D3DPRASTERCAPS_MIPMAPLODBIAS              |                               \
    D3DPRASTERCAPS_ZBIAS                      |                               \
    D3DPRASTERCAPS_ANISOTROPY                 |                               \
    D3DPRASTERCAPS_WBUFFER                    |                               \
    0/*D3DPRASTERCAPS_ZFOG*/                  |                               \
    0/*D3DPRASTERCAPS_COLORPERSPECTIVE*/      |                               \
    0/*D3DPRASTERCAPS_STRETCHBLTMULTISAMPLE*/ |         /* added for DX9 */   \
    D3DPRASTERCAPS_SCISSORTEST                |         /* added for DX9 */   \
    D3DPRASTERCAPS_SLOPESCALEDEPTHBIAS        |         /* added for DX9 */   \
    D3DPRASTERCAPS_DEPTHBIAS                            /* added for DX9 */

#else  // (DIRECT3D_VERSION < 0x0900)
#define ATID3DPRASTER_LINECAPS                                                \
    D3DPRASTERCAPS_DITHER                     |                               \
    D3DPRASTERCAPS_ROP2                       |                               \
    D3DPRASTERCAPS_XOR                        |                               \
    D3DPRASTERCAPS_PAT                        |                               \
    D3DPRASTERCAPS_ZTEST                      |                               \
    D3DPRASTERCAPS_SUBPIXEL                   |                               \
    D3DPRASTERCAPS_STIPPLE                    |                               \
    D3DPRASTERCAPS_FOGVERTEX                  |                               \
    D3DPRASTERCAPS_ANTIALIASSORTDEPENDENT     |                               \
    D3DPRASTERCAPS_ANTIALIASSORTINDEPENDENT   |                               \
    D3DPRASTERCAPS_ANTIALIASEDGES             |                               \
    D3DPRASTERCAPS_MIPMAPLODBIAS              |                               \
    D3DPRASTERCAPS_ZBIAS                      |                               \
    D3DPRASTERCAPS_ANISOTROPY                 |                               \
    D3DPRASTERCAPS_WBUFFER                    |                               \
    0/*D3DPRASTERCAPS_ZFOG*/
#endif // (DIRECT3D_VERSION)

// rasterCaps - TRI (same as LINE)
#define ATID3DPRASTER_TRICAPS                                                 \
        ATID3DPRASTER_LINECAPS

//-----------------------------------------------------------------------------
// zCmpCaps - LINE
#define ATID3DPZCMP_LINECAPS                                                  \
    D3DPCMPCAPS_NEVER             |                                           \
    D3DPCMPCAPS_LESS              |                                           \
    D3DPCMPCAPS_EQUAL             |                                           \
    D3DPCMPCAPS_LESSEQUAL         |                                           \
    D3DPCMPCAPS_GREATER           |                                           \
    D3DPCMPCAPS_NOTEQUAL          |                                           \
    D3DPCMPCAPS_GREATEREQUAL      |                                           \
    D3DPCMPCAPS_ALWAYS

// zCmpCaps - TRI (same as LINE)
#define ATID3DPZCMP_TRICAPS                                                   \
        ATID3DPZCMP_LINECAPS

//-----------------------------------------------------------------------------
// srcBlendCaps - LINE
#define ATID3DPSRCBLEND_LINECAPS                                              \
    D3DPBLENDCAPS_ZERO            |                                           \
    D3DPBLENDCAPS_ONE             |                                           \
    D3DPBLENDCAPS_SRCCOLOR        |                                           \
    D3DPBLENDCAPS_INVSRCCOLOR     |                                           \
    D3DPBLENDCAPS_SRCALPHA        |                                           \
    D3DPBLENDCAPS_INVSRCALPHA     |                                           \
    D3DPBLENDCAPS_DESTALPHA       |                                           \
    D3DPBLENDCAPS_INVDESTALPHA    |                                           \
    D3DPBLENDCAPS_DESTCOLOR       |                                           \
    D3DPBLENDCAPS_INVDESTCOLOR    |                                           \
    D3DPBLENDCAPS_SRCALPHASAT     |                                           \
    D3DPBLENDCAPS_BOTHSRCALPHA    |                                           \
    D3DPBLENDCAPS_BOTHINVSRCALPHA

// srcBlendCaps - TRI (same as LINE)
#define ATID3DPSRCBLEND_TRICAPS                                               \
        ATID3DPSRCBLEND_LINECAPS

//-----------------------------------------------------------------------------
// dstBlendCaps - LINE
#define ATID3DPDSTBLEND_LINECAPS                                              \
    D3DPBLENDCAPS_ZERO            |                                           \
    D3DPBLENDCAPS_ONE             |                                           \
    D3DPBLENDCAPS_SRCCOLOR        |                                           \
    D3DPBLENDCAPS_INVSRCCOLOR     |                                           \
    D3DPBLENDCAPS_SRCALPHA        |                                           \
    D3DPBLENDCAPS_INVSRCALPHA     |                                           \
    D3DPBLENDCAPS_DESTALPHA       |                                           \
    D3DPBLENDCAPS_INVDESTALPHA    |                                           \
    D3DPBLENDCAPS_DESTCOLOR       |                                           \
    D3DPBLENDCAPS_INVDESTCOLOR    |                                           \
    D3DPBLENDCAPS_BOTHSRCALPHA    |                                           \
    D3DPBLENDCAPS_BOTHINVSRCALPHA

// dstBlendCaps - TRI (same as LINE)
#define ATID3DPDSTBLEND_TRICAPS                                               \
        ATID3DPDSTBLEND_LINECAPS

//-----------------------------------------------------------------------------
// alphaCmpCaps - LINE
#define ATID3DPALPHACMP_LINECAPS                                              \
    D3DPCMPCAPS_NEVER             |                                           \
    D3DPCMPCAPS_LESS              |                                           \
    D3DPCMPCAPS_EQUAL             |                                           \
    D3DPCMPCAPS_LESSEQUAL         |                                           \
    D3DPCMPCAPS_GREATER           |                                           \
    D3DPCMPCAPS_NOTEQUAL          |                                           \
    D3DPCMPCAPS_GREATEREQUAL      |                                           \
    D3DPCMPCAPS_ALWAYS

// alphaCmpCaps - TRI (same as LINE)
#define ATID3DPALPHACMP_TRICAPS                                               \
        ATID3DPALPHACMP_LINECAPS

//-----------------------------------------------------------------------------
// shadeCaps - LINE
#define ATID3DPSHADE_LINECAPS                                                 \
    D3DPSHADECAPS_ALPHAFLATBLEND    |                                         \
    D3DPSHADECAPS_ALPHAGOURAUDBLEND |                                         \
    D3DPSHADECAPS_COLORFLATRGB      |                                         \
    D3DPSHADECAPS_COLORGOURAUDRGB   |                                         \
    D3DPSHADECAPS_SPECULARFLATRGB   |                                         \
    D3DPSHADECAPS_SPECULARGOURAUDRGB|                                         \
    D3DPSHADECAPS_FOGFLAT           |                                         \
    D3DPSHADECAPS_FOGGOURAUD

// shadeCaps - TRI (same as LINE)
#define ATID3DPSHADE_TRICAPS                                                  \
        ATID3DPSHADE_LINECAPS

//-----------------------------------------------------------------------------
// textureCaps - LINE

// Cubic Mipmaps are temporarily disabled for R200 due to HW problem
// being investigated.  This cap can however be control by a
// registry setting, bExportMipMapCubeMaps.
//   D3DPTEXTURECAPS_MIPCUBEMAP      |                                        

#if (DIRECT3D_VERSION >= 0x0900)
#define ATID3DPTEXTURE_LINECAPS                                               \
    D3DPTEXTURECAPS_ALPHA                    |                                \
    D3DPTEXTURECAPS_PERSPECTIVE              |                                \
    D3DPTEXTURECAPS_TRANSPARENCY             |                                \
    D3DPTEXTURECAPS_POW2                     |                                \
    D3DPTEXTURECAPS_BORDER                   |                                \
    D3DPTEXTURECAPS_PROJECTED                |                                \
    D3DPTEXTURECAPS_MIPMAP                   |                                \
    0/*D3DPTEXTURECAPS_MIPCUBEMAP*/          |          /* R200 HW problem */ \
    D3DPTEXTURECAPS_CUBEMAP_POW2             |                                \
    D3DPTEXTURECAPS_CUBEMAP                  |                                \
    D3DPTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE |                                \
    0/*D3DPTEXTURECAPS_SRGBTEXTURES*/        |          /* added for DX9 */   \
    0/*D3DPTEXTURECAPS_NOPROJECTEDBUMPENV*/             /* added for DX9 */

#else  // (DIRECT3D_VERSION < 0x0900)
#define ATID3DPTEXTURE_LINECAPS                                               \
    D3DPTEXTURECAPS_ALPHA            |                                        \
    D3DPTEXTURECAPS_PERSPECTIVE      |                                        \
    D3DPTEXTURECAPS_TRANSPARENCY     |                                        \
    D3DPTEXTURECAPS_POW2             |                                        \
    D3DPTEXTURECAPS_BORDER           |                                        \
    D3DPTEXTURECAPS_PROJECTED        |                                        \
    D3DPTEXTURECAPS_MIPMAP           |                                        \
    0/*D3DPTEXTURECAPS_MIPCUBEMAP*/  |                  /* R200 HW problem */ \
    D3DPTEXTURECAPS_CUBEMAP_POW2     |                                        \
    D3DPTEXTURECAPS_CUBEMAP          |                                        \
    D3DPTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE

#endif // (DIRECT3D_VERSION)


// textureCaps - TRI (same as LINE)
#define ATID3DPTEXTURE_TRICAPS                                                \
        ATID3DPTEXTURE_LINECAPS

//-----------------------------------------------------------------------------
// textureFilterCaps - LINE
#define ATID3DPTFILTER_LINECAPS                                               \
    D3DPTFILTERCAPS_LINEAR           |                                        \
    D3DPTFILTERCAPS_LINEARMIPNEAREST |                                        \
    D3DPTFILTERCAPS_LINEARMIPLINEAR  |                                        \
    D3DPTFILTERCAPS_MIPLINEAR        |                                        \
    D3DPTFILTERCAPS_MIPNEAREST       |                                        \
    D3DPTFILTERCAPS_NEAREST          |                                        \
    D3DPTFILTERCAPS_MINFPOINT        |                                        \
    D3DPTFILTERCAPS_MINFLINEAR       |                                        \
    D3DPTFILTERCAPS_MINFANISOTROPIC  |                                        \
    D3DPTFILTERCAPS_MAGFPOINT        |                                        \
    D3DPTFILTERCAPS_MAGFLINEAR       |                                        \
    D3DPTFILTERCAPS_MIPFPOINT        |                                        \
    D3DPTFILTERCAPS_MIPFLINEAR

// textureFilterCaps - TRI (same as LINE)
#define ATID3DPTFILTER_TRICAPS                                                \
        ATID3DPTFILTER_LINECAPS

//-----------------------------------------------------------------------------
// textureBlendCaps - LINE
#define ATID3DPTBLEND_LINECAPS                                                \
    D3DPTBLENDCAPS_DECAL             |                                        \
    D3DPTBLENDCAPS_COPY              |                                        \
    D3DPTBLENDCAPS_ADD               |                                        \
    D3DPTBLENDCAPS_DECALALPHA        |                                        \
    D3DPTBLENDCAPS_MODULATE          |                                        \
    D3DPTBLENDCAPS_MODULATEALPHA

// textureBlendCaps - TRI (same as LINE)
#define ATID3DPTBLEND_TRICAPS                                                 \
        ATID3DPTBLEND_LINECAPS

//-----------------------------------------------------------------------------
// textureAddressCaps - LINE
#define ATID3DPTADDRESS_LINECAPS                                              \
    D3DPTADDRESSCAPS_WRAP            |                                        \
    D3DPTADDRESSCAPS_MIRROR          |                                        \
    D3DPTADDRESSCAPS_CLAMP           |                                        \
    D3DPTADDRESSCAPS_BORDER          |                                        \
    D3DPTADDRESSCAPS_INDEPENDENTUV

// textureAddressCaps - TRI (same as LINE)
#define ATID3DPTADDRESS_TRICAPS                                               \
        ATID3DPTADDRESS_LINECAPS


/***************************************************************************/
/*                        DX9 CAPS                                         */
/***************************************************************************/


//Line Caps
#define lineCaps {                \
    /* dwSize */                  \
    sizeof(D3DPRIMCAPS),          \
	ATID3DPMISC_LINECAPS,         \
    ATID3DPRASTER_LINECAPS,       \
    ATID3DPZCMP_LINECAPS,         \
    ATID3DPSRCBLEND_LINECAPS,     \
    ATID3DPDSTBLEND_LINECAPS,     \
    ATID3DPALPHACMP_LINECAPS,     \
    ATID3DPSHADE_LINECAPS,        \
    ATID3DPTEXTURE_LINECAPS,      \
    ATID3DPTFILTER_LINECAPS,      \
    ATID3DPTBLEND_LINECAPS,       \
    ATID3DPTADDRESS_LINECAPS,     \
    /* stippleWidth */            \
    32,                           \
    /* stippleHeight */           \
    32                            \
}                                              


//Triangle Caps
#define triCaps {                 \
    /* dwSize */                  \
    sizeof(D3DPRIMCAPS),          \
	ATID3DPMISC_TRICAPS,          \
    ATID3DPRASTER_TRICAPS,        \
    ATID3DPZCMP_TRICAPS,          \
    ATID3DPSRCBLEND_TRICAPS,      \
    ATID3DPDSTBLEND_TRICAPS,      \
    ATID3DPALPHACMP_TRICAPS,      \
    ATID3DPSHADE_TRICAPS,         \
    ATID3DPTEXTURE_TRICAPS,       \
    ATID3DPTFILTER_TRICAPS,       \
    ATID3DPTBLEND_TRICAPS,        \
    ATID3DPTADDRESS_TRICAPS,      \
    /* stippleWidth */            \
    32,                           \
    /* stippleHeight */           \
    32                            \
} 


/****************************************************
**                                                 **
**       Alpha and ZCompare Capabilities           **
**                                                 **
*****************************************************/

//The following caps are used by D3D


// Texture operation caps
#define ATID3DTEXOPCAPS                      \
  ( D3DTEXOPCAPS_BUMPENVMAPLUMINANCE       | \
    D3DTEXOPCAPS_PREMODULATE               | \
    D3DTEXOPCAPS_DISABLE                   | \
    D3DTEXOPCAPS_SELECTARG1                | \
    D3DTEXOPCAPS_SELECTARG2                | \
    D3DTEXOPCAPS_MODULATE                  | \
    D3DTEXOPCAPS_MODULATE2X                | \
    D3DTEXOPCAPS_MODULATE4X                | \
    D3DTEXOPCAPS_ADD                       | \
    D3DTEXOPCAPS_ADDSIGNED                 | \
    D3DTEXOPCAPS_ADDSIGNED2X               | \
    D3DTEXOPCAPS_SUBTRACT                  | \
    D3DTEXOPCAPS_BLENDDIFFUSEALPHA         | \
    D3DTEXOPCAPS_BLENDTEXTUREALPHA         | \
    D3DTEXOPCAPS_BLENDFACTORALPHA          | \
    D3DTEXOPCAPS_BLENDTEXTUREALPHAPM       | \
    D3DTEXOPCAPS_BLENDCURRENTALPHA         | \
    D3DTEXOPCAPS_MODULATEALPHA_ADDCOLOR    | \
    D3DTEXOPCAPS_MODULATECOLOR_ADDALPHA    | \
    D3DTEXOPCAPS_MODULATEINVALPHA_ADDCOLOR | \
    D3DTEXOPCAPS_MODULATEINVCOLOR_ADDALPHA | \
    D3DTEXOPCAPS_BUMPENVMAP                | \
    D3DTEXOPCAPS_MULTIPLYADD               | \
    D3DTEXOPCAPS_LERP                      | \
    D3DTEXOPCAPS_ADDSMOOTH                 | \
    D3DTEXOPCAPS_DOTPRODUCT3 )

//-----------------------------------------------------------------------------
//stencil caps
#if (DIRECT3D_VERSION >= 0x0900)
#define ATID3DSTENCILCAPS              \
  ( 0/*D3DSTENCILCAPS_TWOSIDED*/     | \
    D3DSTENCILCAPS_KEEP              | \
    D3DSTENCILCAPS_ZERO              | \
    D3DSTENCILCAPS_REPLACE           | \
    D3DSTENCILCAPS_INCRSAT           | \
    D3DSTENCILCAPS_DECRSAT           | \
    D3DSTENCILCAPS_INVERT            | \
    D3DSTENCILCAPS_INCR              | \
    D3DSTENCILCAPS_DECR )

#else  // (DIRECT3D_VERSION < 0x0900)
#define ATID3DSTENCILCAPS              \
  ( D3DSTENCILCAPS_KEEP              | \
    D3DSTENCILCAPS_ZERO              | \
    D3DSTENCILCAPS_REPLACE           | \
    D3DSTENCILCAPS_INCRSAT           | \
    D3DSTENCILCAPS_DECRSAT           | \
    D3DSTENCILCAPS_INVERT            | \
    D3DSTENCILCAPS_INCR              | \
    D3DSTENCILCAPS_DECR )
#endif // (DIRECT3D_VERSION)


//-----------------------------------------------------------------------------
#ifdef NULLDRV

static D3DHAL_CALLBACKS myD3DHALCallbacks = {
    sizeof(D3DHAL_CALLBACKS),

    // Device context
    nullContextCreate32,            // Required.
    nullContextDestroy32,           // Required.
    0L,          

    // Scene capture
    0L,            
    
    // Execution
    0L, //Execute32, // Execute,           // Optional.  Don't implement if just rasterization.
    0L, //ExecuteClipped32, // ExecuteClipped,
    0L, //RenderState32,              // Required if no Execute
    0L,          // Required if no Execute
    0L,                         // Reserved, must be zero
    
    // Textures
    0L,            // If any of these calls are supported,
    0L,           // they must all be.
    0L,              // ditto - but can always fail.
    0L,           // ditto - but can always fail.

    // Transform - must be supported if lighting is supported.
    0L, //MatrixCreate32, //MatrixCreate,       // If any of these calls are supported,
    0L, //MatrixDestroy32, //MatrixDestroy,      // they must all be.
    0L, //MatrixSetData32, //MatrixSetData,      // ditto
    0L, //MatrixGetData32, //MatrixGetData,      // ditto
    0L, //SetViewPortData32, //SetViewportData,    // ditto
    
    // Lighting
    0L, //LightSet32, //LightSet            // If any of these calls are supported,
    0L, //MaterialCreate32, //myMaterialCreate,   // they must all be.
    0L, //MaterialDestroy32, //myMaterialDestroy,  // ditto
    0L, //MaterialSetData32, //myMaterialSetData,  // ditto
    0L, //MaterialGetData32, //myMaterialGetData,  // ditto

    // Pipeline state
    0L,                 // Required if implementing Execute.
};

#define nullPrimCaps {                                          \
    sizeof(D3DPRIMCAPS), 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0, 0  \
}

#else //IFDEF NULLDRV
/*****************************************************************************
 * Direct3D HAL Table. Should be filled in to indicate which HAL calls we    *
 * support. NO EMULATION HERE.                                               *
 * Calls take the form of:                                                   *
 *     retcode = HalCall(HalCallData* lpData);                               *
 *****************************************************************************/
static D3DHAL_CALLBACKS myD3DHALCallbacks = {
    sizeof(D3DHAL_CALLBACKS),

    // Device context
    ContextCreate32,            // Required.
    ContextDestroy32,           // Required.
    0L,                         // ContextDestroyAll.
    0L,                         // SceneCapture.
    
    // Execution
    0L, //Execute32, // Execute,           // Optional.  Don't implement if just rasterization.
    0L, //ExecuteClipped32, // ExecuteClipped,
    0L,                         // RenderState32
    0L,                         // RenderPrimitive32
    0L,                         // Reserved, must be zero
    
    // Textures
    0L,                         // TextureCreate32.
    0L,                         // TextureDestroy32.
    0L,                         // TextureSwap32.
    0L,                         // TextureGetSurf32.

    // Transform - must be supported if lighting is supported.
    0L, //MatrixCreate32, //MatrixCreate,       // If any of these calls are supported,
    0L, //MatrixDestroy32, //MatrixDestroy,      // they must all be.
    0L, //MatrixSetData32, //MatrixSetData,      // ditto
    0L, //MatrixGetData32, //MatrixGetData,      // ditto
    0L, //SetViewPortData32, //SetViewportData,    // ditto
    
    // Lighting
    0L, //LightSet32, //LightSet            // If any of these calls are supported,
    0L, //MaterialCreate32, //myMaterialCreate,   // they must all be.
    0L, //MaterialDestroy32, //myMaterialDestroy,  // ditto
    0L, //MaterialSetData32, //myMaterialSetData,  // ditto
    0L, //MaterialGetData32, //myMaterialGetData,  // ditto

    // Pipeline state
    0L                          // GetState32
};

#ifdef WIN2K 
static DD_D3DBUFCALLBACKS myD3DBufCallbacks = {
    sizeof(DD_D3DBUFCALLBACKS),                      /* dwSize  */
    BORG_EXEBUFFER_CAPS,                             /* dwFlags */
    CanCreateExecuteBuffer32,                        /* CanCreateD3DBuffer */
    CreateExecuteBuffer32,                           /* CreateD3DBuffer */ 
    DestroyExecuteBuffer32,                          /* DestroyD3DBuffer */
    LockExecuteBuffer32,                             /* LockD3DBuffer */
    UnlockExecuteBuffer32                            /* UnlockD3DBuffer */
};
#endif

#endif //IFDEF NULLDRV

static D3DDEVICEDESC_V1 myCaps = {
    sizeof(D3DDEVICEDESC_V1),                         /* dwSize */
    D3DDD_COLORMODEL                 |                /* dwFlags */
    D3DDD_DEVCAPS                    |
    D3DDD_LINECAPS                   |
    D3DDD_TRICAPS                    |
    D3DDD_DEVICERENDERBITDEPTH       |
    D3DDD_DEVICEZBUFFERBITDEPTH,
    D3DCOLOR_RGB,                                     /* dcmColorModel */
    D3DDEVCAPS_EXECUTESYSTEMMEMORY   |                /* devCaps */
    D3DDEVCAPS_EXECUTEVIDEOMEMORY    |
    D3DDEVCAPS_TEXTUREVIDEOMEMORY    |
    D3DDEVCAPS_TEXTURENONLOCALVIDMEM |
    D3DDEVCAPS_FLOATTLVERTEX         |
    D3DDEVCAPS_TLVERTEXSYSTEMMEMORY  |
    D3DDEVCAPS_TLVERTEXVIDEOMEMORY   |
    D3DDEVCAPS_CANRENDERAFTERFLIP    |
    D3DDEVCAPS_DRAWPRIMITIVES2       |
    D3DDEVCAPS_DRAWPRIMTLVERTEX,      
    { sizeof(D3DTRANSFORMCAPS), 0 },                  /* dtcTransformCaps */
    FALSE,                                            /* bClipping */
    { sizeof(D3DLIGHTINGCAPS), 0,0,0 },               /* dlcLightingCaps */
    lineCaps,                                         /* lineCaps */
    triCaps,                                          /* triCaps */
    DDBD_16 | DDBD_32,                                /* DeviceRenderBitDepth */
    DDBD_16 | DDBD_24,                                /* DeviceZBuffBitDepth */
    0,                                                /* dwMaxBufferSize */
    MaxVertexCount                                    /* dwMaxVertexCount */
};

#endif // _ATI3DCAPS_H

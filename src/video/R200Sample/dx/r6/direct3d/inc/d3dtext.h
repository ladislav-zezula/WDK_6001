

//    
//  $Workfile: d3dtext.h $
//
//  Description:
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef  _D3DTEXTURE_H
#define  _D3DTEXTURE_H

#include "atid3ddefs.h"
#include "atidxhsl.h"
#include "ddmacros.h"

#define D3DTOP_LEGACY_ALPHAOVR 0xFFFFFFFF
#define MAX_MIP_COUNT          12

#define TEX_MICRO_TILE_MASK 0x8
#define TEX_MACRO_TILE_MASK 0x4
#define TEX_TILE_MASK 0xC

/****************************************************************************/
//** Valid values for the dwSurfFlags field of the ATISURFINFO structure.
///****************************************************************************/

//Indicates whether or not a DDRAW surface has a TimeStamp
//associated with or not
#define     SURF_HAS_TSTAMP         0x00000001

//Indicates surface needs to be synchronized. It's currently used for 
//texture surfaces which is also a render target, sychronization is added
//before the texture is being used in 3d rendering if it has been used as
//render target earlier.
#define     SURF_NEEDS_SYNC         0x00000002

//Indicates that the Surface Context data has been reloaded in LoadSurfaceCntx
//Therefore when the Tx is bound to a stage make sure to reprogam the Tx units
//for this Tx.
#define     SURF_CNTX_RELOADED      0x00000004

//Indicate whether this texture is compressed by the driver.
#define     SURF_DRIVER_COMPRESSED  0x00000008

#define     SURF_CANT_BE_COMPRESSED 0x00000010

#define     SURF_COMP_WITH_REJECTION    0x00000020

#define     SURF_COMP_DIRTY         0x00000040 

//For MultisampleQualityLevel
#if (DIRECT3D_VERSION >= 0x0900)
#define     D3DMAX_SUPPORTED_MULTISAMPLES  6

//the QualityLevel reported to runtime
#define		MULITISAMPLE_QUALITYLEVEL_ONE   1
#define		MULITISAMPLE_QUALITYLEVEL_TWO   2

/* Multi-Sample quality level types */
typedef enum _D3DMULTISAMPLE_QUALITYLEVEL
{
    D3DMULTISAMPLE_QUALITYLEVEL_ZERO    =  0,
    D3DMULTISAMPLE_QUALITYLEVEL_ONE     =  1,

} D3DMULTISAMPLE_QUALITYLEVEL;

typedef  struct _MSAMPLEQLEVEL_MAPPING
{
    DWORD    dwNumSamples;
    BOOL     bQualityMode;
} MSAMPLEQLEVEL_MAPPING;
#endif //#if (DIRECT3D_VERSION >= 0x0900)

typedef struct 
{
    BOOL           bTextureHasAlpha;
    BOOL           bNonPowerOfTwo;
    BOOL           bYUVTexture;
    DWORD          Tex_Pixel_Format;//Texture's PixelFormat.

    DWORD          dwTexLog2Width;  //log2 of tex pitch
    DWORD          dwTexLog2Height; //log2 of tex height
    DWORD          dwTexWidth;      //tex width in pixels
    DWORD          dwTexHeight;     //tex height in pixels
    
    DWORD          dwTexLog2Size;   // Max of the above two.
    DWORD          dwTexPitch;      // Tex pitch for non-power of 2 texture.

    DWORD          dwMipCount;
    LPDWORD 	   lpTexOffset;	   // pointer to the texture offset of the base map.

    BOOL           IsCubicMap;
    LPDWORD 	   lpCubeOffset[6];

#ifdef UMD
    D3DKMT_HANDLE  hCubeAllocation[6];
#endif

    // pMipOffsets[] stores pointers to tex surf offsets calculated by ddhal
    // at surface creation time, they are the exact format that PP_TXOFFSET_n
    // register takes, which include tiling info.
    FLATPTR*       pMipOffsets[MAX_MIP_COUNT];

    // dwMipSurfOffsets[] is an offset of mip level i from the basemap, when i=0, offset is 0.
    ULONG_PTR	   dwMipSurfOffsets[MAX_MIP_COUNT];

    ULONG_PTR	   dwTileInfo[MAX_MIP_COUNT];

}ATITEXTURESTRUCT,  *LPATITEXTURESTRUCT;


typedef struct _ATISURFCNTX
{
    // This must be the first member of this structure
    // Surfaces and VB share the surface list. This
    // DWORD allows us to tell if any given pointer
    // in that list points to a surface or a VB.
    ATIHANDLETYPE  handleType;

    //Time Stamp Info
    DWORD      dwSurfFlags;        // Holds SURF_HAS_TSTAMP flag

    // dwSurfPendingCB_ID means that this surface is used by a CB with ID = dwSurfPendingCB_ID.
    // and this CB is either not submitted or it is submitted but we don't know
    // if its time is elasped. Each surface can at most in one un-submitted CB!
    // Also, note that when we eventually want to test a surface's timestamp
    // it is possible that the timestamp has actually been overwritten.  We use
    // surfPendingWrapStamp to detect that case.
    DWORD      dwSurfPendingCB_ID;     
    DWORD      surfPendingWrapStamp;

    // Context index to find context pointer in lpD3DDevice.
    DWORD      dwhContextID;            


    //Surface Local Ponter data
    DWORD dwWidth;
    DWORD dwHeight;
    DWORD dwFlags;
    long lPitch;
    long lSlicePitch;

    // Caps
    DDSCAPS ddsCaps;
    DDSCAPSEX ddsCapsEx;

    // Pixel Format
    DDPIXELFORMAT ddpfSurface;
    
    DDCOLORKEY ddckCKSrcBlt;

    union
    {
#ifdef UMD
        D3DKMT_HANDLE  hAllocation; // Allocation handle
#endif
        // Video memory pointer (virtual)
        FLATPTR fpVidMem;
    };

    // Surface handle
    DWORD dwSurfaceHandle;

    //Direct Draw ATISURFINFO data
    DWORD dwSurfPixFrmt;
    DWORD dwSurfPitchIn8Pixels;
    DWORD dwBytesPerPixel;
    DWORD dwTexelFormat;
    DWORD dwColorFormat;

    DDHSLATISURFHANDLE hATISurfInfoHandle;
    DDHSLD3DSURFHANDLE hHSLSurfInfoHandle;
    LPDWORD pdwSurfByteOffset;

    //Direct 3D Texture Context data
    BOOL  bSurfaceIsValid;     //if true, indicates surface is in vidmem,
                               //otherwise, surface is in system memory.
    DWORD dwSize;              //size of structure

    // All the info about the texture i.e. width height etc. based on
    // the texture format supplied by the app.
    ATITEXTURESTRUCT NativeTextureInfo; 

    // Texture info based on the texture format selected by the driver.
    // When certain registry controls are enabled, driver may choose to compress 
    // certain textures to achieve higher hw performance. This structure is then 
    // updated accordingly so that hw can be programmed to treat those textures 
    // in compressed formats. This feature is disabled by default, in which case,
    // ActiveTextureInfo is the same as NativeTextureInfo.
    ATITEXTURESTRUCT ActiveTextureInfo;

    // This structure is used in R100 code path only. It is used to save the 
    // ActiveTextureInfo about the base texture for situations where MAXMIPLEVEL 
    // is set, and all the values must be modified, and possibly reset back to  
    // the base values in the future.
    ATITEXTURESTRUCT ActiveBaseTextureInfo; 

    // SurfHandle for each mip level, dwMipSurfHandle[0] = dwSurfaceHandle.
    DWORD dwMipSurfHandle[MAX_MIP_COUNT]; 

    // ATISurfInfoHandle for each mip level.
    DDHSLATISURFHANDLE hMipATISurfInfoHandle[MAX_MIP_COUNT];

    DWORD dwFCCDepthOffset;  
    DWORD dwFCCHeight;      

    DWORD dwDepthClearValue;

    // Used to know when surface is unlocked so we can place any valid resource handles back into cmd buf
    DWORD dwLockCount;     

    // Bit field used to record which resource slots this surface is currently in, we need this info as on lock
    // we will NULL and then restore them when we unlock
    ULONGLONG liLockResSlotMaskLow;     //Bit field for resource slots 0-63
    ULONGLONG liLockResSlotMaskHigh;    //Bit field for resource slots 64-127

#if (DIRECT3D_VERSION >= 0x0900)
    //DX9 multi-head. Indicate this master head surf cntx has slave heads
    BOOL  bHasSlaveHead;   
    //DX9 multisample quality level. The structure is for mapping between DX9 multisample
    //quality level and DX8 multisample.
    MSAMPLEQLEVEL_MAPPING   MSampleQLevelMapping[ 2 * D3DMAX_SUPPORTED_MULTISAMPLES ]; 
#endif // (DIRECT3D_VERSION >= 0x0900)

}ATISURFCNTX, *LPATISURFCNTX;


typedef struct _ATI_SURF_HANDLE
{
    // The size of lpATITexCntxList
    DWORD    dwNumATITexCntxAllocated;       

    // array to hold handles. It is dynamically allocated in 
    // SetTextureSlot in misc2CBdx7.c 
    LPATISURFCNTX   *lpATITexCntxList;
    
    // owning ddraw pointer as a key
    LPVOID  lpDDLcl;                  
    
    // Back reference to CNTX when CNTX is destroyed.
    
    LPVOID  pCtx;

} ATISURFHANDLE, *LPATISURFHANDLE;

/*********************************************
  Inline Access Functions for Surface Context
 *********************************************/

_inline DWORD GetSurfCntxWidth( LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? lpSurfCntx->dwWidth : 0;
}

_inline DWORD GetSurfCntxHeight( LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? lpSurfCntx->dwHeight : 0;
}

_inline DWORD GetSurfCntxFlags( LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? lpSurfCntx->dwFlags : 0;
} 

_inline LONG GetSurfCntxPitch( LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? lpSurfCntx->lPitch : 0;
}

_inline LONG GetSurfCntxSlicePitch( LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? lpSurfCntx->lSlicePitch : 0;
}

_inline FLATPTR GetSurfCntxVidMem( LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? lpSurfCntx->fpVidMem : 0;
}

_inline DWORD GetSurfCntxCaps( LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? lpSurfCntx->ddsCaps.dwCaps : 0;
}

_inline DWORD GetSurfCntxCaps2( LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? lpSurfCntx->ddsCapsEx.dwCaps2 : 0;
}

_inline DWORD GetSurfCntxMipMapCount( LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? lpSurfCntx->ActiveTextureInfo.dwMipCount : 0;
}

_inline DWORD GetSurfCntxCKSrcLowColorKey( LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? lpSurfCntx->ddckCKSrcBlt.dwColorSpaceLowValue : 0;
}

_inline DDHSLATISURFHANDLE GetSurfCntxATISurfInfoHandle( LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? lpSurfCntx->hATISurfInfoHandle : 0;
}

_inline DDHSLD3DSURFHANDLE GetSurfCntxHSLSurfInfoHandle( LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? lpSurfCntx->hHSLSurfInfoHandle : 0;
}

_inline struct HSLSurfInfo* GetSurfCntxHSLSurfInfo( LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? (struct HSLSurfInfo*)lpSurfCntx->hHSLSurfInfoHandle : NULL;
}

__inline LPDDPIXELFORMAT GetSurfCntxlpDDPF(LPATISURFCNTX lpSurfCntx)
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? &lpSurfCntx->ddpfSurface : NULL;
}

__inline DWORD GetSurfCntxBPP( LPATISURFCNTX lpSurfCntx)
{
    if (!lpSurfCntx)
    {
        HSLASSERT(lpSurfCntx);
        return 0;
    }

    if( lpSurfCntx->ddpfSurface.dwFlags & DDPF_FOURCC ) 
    {
        if( (lpSurfCntx->ddpfSurface.dwFourCC & 0x00FFFFFF ) == 'TXD' )
        {
            return 8;
        }
        // The new DX8 surface formats are handled as FOURCC surfaces
        // even though they are not FOURCC surfaces.
        else if ( (lpSurfCntx->ddpfSurface.dwFourCC == D3DFMT_V16U16) ||
                  (lpSurfCntx->ddpfSurface.dwFourCC == D3DFMT_Q8W8V8U8) ||
#if (DIRECT3D_VERSION >= 0x0900)
                  (lpSurfCntx->ddpfSurface.dwFourCC == D3DFMT_A8B8G8R8) ||
                  (lpSurfCntx->ddpfSurface.dwFourCC == D3DFMT_X8B8G8R8) ||
                  (lpSurfCntx->ddpfSurface.dwFourCC == D3DFMT_A2R10G10B10) ||
#endif //(DIRECT3D_VERSION)
                  (lpSurfCntx->ddpfSurface.dwFourCC == D3DFMT_W11V11U10) ||
                  (lpSurfCntx->ddpfSurface.dwFourCC == D3DFMT_A2W10V10U10) ||
                  (lpSurfCntx->ddpfSurface.dwFourCC == D3DFMT_A2B10G10R10) )
        {
            return 32;
        }
        else 
        {
            return 16;
        }
    }

    return lpSurfCntx->ddpfSurface.dwRGBBitCount;
}

__inline DWORD GetMinHeight(LPATISURFCNTX lpSurfCntx)
{
    DWORD dwMinHeight = 1;

    if (lpSurfCntx->ddsCaps.dwCaps & DDSCAPS_VIDEOMEMORY)
    {
        DWORD dwMinMipLevel = (lpSurfCntx->ActiveTextureInfo.dwMipCount > 1) ? lpSurfCntx->ActiveTextureInfo.dwMipCount - 1 : 0;

        if (lpSurfCntx->ActiveTextureInfo.dwTileInfo[dwMinMipLevel] & TEX_MICRO_TILE_MASK)
        {
            dwMinHeight = 2;
        }
        else
        {
            dwMinHeight = 1;
        }
    }
    return dwMinHeight;
}

// Get Minimum Pitch size.
__inline DWORD GetMinPitch(LPATISURFCNTX lpSurfCntx)
{
    DWORD dwMinMipLevel;
    DWORD dwMinPitch = 0;

    HSLASSERT(lpSurfCntx->ddsCaps.dwCaps & DDSCAPS_VIDEOMEMORY);

    if (! lpSurfCntx->ActiveTextureInfo.dwMipCount)
    {
        return 0;
    }

    dwMinMipLevel = lpSurfCntx->ActiveTextureInfo.dwMipCount - 1;
    HSLASSERT(dwMinMipLevel < MAX_MIP_COUNT);

    if (lpSurfCntx->ActiveTextureInfo.dwTileInfo[dwMinMipLevel] & TEX_MICRO_TILE_MASK)
    {
        dwMinPitch = ATI_MINMICROTILEPITCH;
    }
    else
    {
        dwMinPitch = ATI_MINPITCH;
    }

    return dwMinPitch;
}

// Get the size of a specific mip level in the mip chain given the base map
// size and minimum size.
__inline DWORD GetMipSize(DWORD dwBaseSize, DWORD dwMipLevel, DWORD dwMinSize)
{
    DWORD dwMipSize = dwBaseSize >> dwMipLevel;
    if (dwMipSize < dwMinSize)
    {
        dwMipSize = dwMinSize;
    }
    return dwMipSize;
}

_inline DWORD GetSurfCntxPFFlags(LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? GetSurfCntxlpDDPF(lpSurfCntx)->dwFlags : 0;
}


_inline DWORD GetSurfCntxFourCC( LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
    return (lpSurfCntx) ? GetSurfCntxlpDDPF(lpSurfCntx)->dwFourCC : 0;
}

_inline DWORD GetSurfCntxMSType( LPATISURFCNTX lpSurfCntx )
{
    HSLASSERT(lpSurfCntx);
#if (DIRECT3D_VERSION >= 0x0900)
    return lpSurfCntx->ddsCapsEx.dwCaps3 & DDSCAPS3_MULTISAMPLE_MASK;
#else
    return lpSurfCntx->ddsCapsEx.dwCaps3;
#endif //DIRECT3D_VERSION >= 0x0900

}

//For MultisampleQualityLevel
#if (DIRECT3D_VERSION >= 0x0900)
_inline DWORD GetSurfCntxMSQuality( LPATISURFCNTX lpSurfCntx )
{
	DWORD dwCaps3 = 0;
	HSLASSERT(lpSurfCntx);
	dwCaps3 = lpSurfCntx->ddsCapsEx.dwCaps3;
	return ( dwCaps3 & DDSCAPS3_MULTISAMPLE_QUALITY_MASK ) >> DDSCAPS3_MULTISAMPLE_QUALITY_SHIFT;
}
#endif
//end of MultisampleQualityLevel

/*
 * SurfCntxHasTStampFlag:
 * This macro is used to determine if the identified surface requires
 * a TIMESTAMP check.
 */
_inline BOOL SurfCntxHasTStampFlag( LPATISURFCNTX lpSurfCntx )
{
   if ( lpSurfCntx == NULL ) return FALSE;

   return lpSurfCntx->dwSurfFlags & SURF_HAS_TSTAMP;
}

/*
 * ClearSurfCntxTStampFlag:
 * This macro reset's the SURF_HAS_TSTAMP member of the 
 * dwSurfFlags DWORD of the supplied Surface Context.
 */
_inline VOID ClearSurfCntxTStampFlag( LPATISURFCNTX lpSurfCntx )
{
    lpSurfCntx->dwSurfFlags &= (~(SURF_HAS_TSTAMP));
}

extern LPVOID GetSurfaceCntx(LPDDRAWI_DIRECTDRAW_LCL lpDDLcl, 
                             DWORD dwSurfaceHandle,
                             ATIHANDLETYPE handleType);



#endif	 //_D3DTEXTURE_H





//    
//  $Workfile: atisurf.h $
//
//  Description:
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2002, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

 
#ifndef _ATISURF_H_

#define _ATISURF_H_


#include "atidxinc.h"
#include "ddmacros.h"
#include "rage.h"
#include "tplates.h"
#include "atisurfp.h"
#include "atidefs.h"
#include "qs.h"
#include "atidxobj.h"
#include "align.h"
#include "fourcc.h"
#include "atidxhsl.h"
#include "pm4.h"


#include "macros.h"

typedef enum _E_FLUSHFREE {
    FLUSH_ONLY     = 1,
    FREE_ONLY      = 2,
    FLUSH_AND_FREE = 3
} E_FLUSHFREE;

void DDFlushFreeDstCache( LPCMDBUFF lpCB, E_FLUSHFREE eFF, 
                          DWORD dwNumSurfsToStamp );

void DDFlushFreeZCache( LPCMDBUFF lpCB, E_FLUSHFREE eFF );

// This is used in cases where we do not have a surface local pointer.
// NOTE: This function should be moved out of this file into a more appropriate file.
__inline DWORD GetDDSurfacePitch2(LPDDHSLSURFACEDESC lpSurfDesc)
{
   if((lpSurfDesc->dwCaps & DDSCAPS_SYSTEMMEMORY))
   {
       if(lpSurfDesc->lpddPixelFormat->dwFlags & DDPF_FOURCC && 
         (lpSurfDesc->lpddPixelFormat->dwFourCC & 0x00FFFFFF) == 'TXD')
       {
            if(lpSurfDesc->lpddPixelFormat->dwFourCC == FOURCC_DXT1)
                return ((lpSurfDesc->dwWidth + 3) >> 2) << 3;
            return ((lpSurfDesc->dwWidth + 3) >> 2) << 4;
       }
   }
       
   return lpSurfDesc->lPitch;
}

/*
 * SetSurfInfoPtr:
 * This macro set's surface GBL dwReserved1 field to pint to 
 * either a ATISURFINFO ptr or a ATIVTXLIST ptr
 */
__inline void SetSurfInfoPtr(LPDDRAWI_DDRAWSURFACE_LCL lpDDSurf, LPVOID lpInfo)
{
  lpDDSurf->lpGbl->dwReserved1 = (ULONG_PTR) lpInfo;
}


/*
 * GetLCLCB:
 * This macro returns the CMDBUFF for this surface ptr
 */
_inline LPCMDBUFF GetLCLCB(LPDDRAWI_DDRAWSURFACE_LCL lpLCLSurf)
{
    LPATISURFINFO lpSurfInfo = GetATISurfInfoPtr(lpLCLSurf);
    HSLASSERT( GetATISurfInfoPtr(lpLCLSurf) != 0 );
    return (lpSurfInfo->lpCmdBuff);
}


/*
 * GetATISurfInfoCB:
 * This macro returns the CMDBUFF for this surface info ptr
 */
_inline LPCMDBUFF GetATISurfInfoCB( LPATISURFINFO lpSurfInfo )
{
    HSLASSERT( lpSurfInfo != 0 );
    return (lpSurfInfo->lpCmdBuff);
}

/*
 * ClearSurfTStampFlag:
 * This macro reset's the SURF_HAS_TSTAMP member of the 
 * dwSurfFlags DWORD of the supplied ATISurfInfo struct.
 */
__inline void ClearSurfTStampFlag(LPATISURFINFO lpATISurfInfo)
{
    HSLASSERT( lpATISurfInfo != 0 );
    lpATISurfInfo->dwSurfFlags &= (~(SURF_HAS_TSTAMP));
}


/*
 * SetSurfCRTCSyncFlag:
 * This macro sets the HSL_SURF_NEEDS_CRTC_SYNC member of the 
 * supplied ATISurfInfo struct.
 */
__inline void SetSurfCRTCSyncFlag(LPATISURFINFO lpATISurfInfo)
{
    HSLASSERT( lpATISurfInfo != 0 );
    lpATISurfInfo->dwSurfFlags |= HSL_SURF_NEEDS_CRTC_SYNC;
    lpATISurfInfo->dwSurfFlags &= (~(SURF_HAS_TSTAMP));
}

/*
 * ClearSurfCRTCSyncFlag:
 * This macro reset's the HSL_SURF_NEEDS_CRTC_SYNC member of the 
 * the supplied ATISurfInfo struct.
 */
__inline void ClearSurfCRTCSyncFlag(LPATISURFINFO lpATISurfInfo)
{
    HSLASSERT( lpATISurfInfo != 0 );
    lpATISurfInfo->dwSurfFlags &= ~HSL_SURF_NEEDS_CRTC_SYNC;
}


/*
 * SetSurfTStampFlag:
 * This macro set the SURF_HAS_TSTAMP member of the 
 * dwSurfFlags DWORD of the supplied ATISurfInfo struct.
 */
__inline void SetSurfTStampFlag(LPATISURFINFO lpATISurfInfo)
{
    HSLASSERT( lpATISurfInfo != 0 );
    lpATISurfInfo->dwSurfFlags |= SURF_HAS_TSTAMP;
}

/*
 * SetSurfFlipTStampFlag:
 * This macro set the SURF_HAS_TSTAMP member of the 
 * dwSurfFlags DWORD of the supplied ATISurfInfo struct.
 */
__inline void SetSurfFlipTStampFlag(LPATISURFINFO lpATISurfInfo)
{
    HSLASSERT( lpATISurfInfo != 0 );
    lpATISurfInfo->dwSurfFlags |=SURF_HAS_FLIP_TSTAMP;
    ClearSurfCRTCSyncFlag(lpATISurfInfo);
}

/*
 * SurfHasCRTCSyncFlag:
 * This macro is used to determine if the identified surface requires
 * CRTC synchronization.
 */
__inline BOOL SurfHasCRTCSyncFlag( LPATISURFINFO lpATISurfInfo )
{
    HSLASSERT( lpATISurfInfo != 0 );
    return ( lpATISurfInfo == NULL ? FALSE : (lpATISurfInfo->dwSurfFlags & HSL_SURF_NEEDS_CRTC_SYNC));
}


/*
 * SurfHasTStampFlag:
 * This macro is used to determine if the identified surface requires
 * a TIMESTAMP check.
 */
 __inline BOOL SurfHasTStampFlag( LPATISURFINFO lpSurfInfo )
{
    HSLASSERT( lpSurfInfo != 0 );
    return ( lpSurfInfo == NULL ? FALSE : lpSurfInfo->dwSurfFlags & SURF_HAS_TSTAMP);
}


/*
 * SurfHasFlipTStampFlag:
 * This macro is used to determine if the identified surface requires
 * a TIMESTAMP check.
 */
 __inline BOOL SurfHasFlipTStampFlag (LPATISURFINFO lpSurfInfo)
{
    HSLASSERT( lpSurfInfo != 0 );
    return ( lpSurfInfo == NULL ? FALSE : lpSurfInfo->dwSurfFlags & SURF_HAS_FLIP_TSTAMP);
}

/*
 * ClearSurfFlipTStampFlag:
 * This macro is used to clear(remove) the surface's flip timestamp flag 
 */
 __inline void ClearSurfFlipTStampFlag (LPATISURFINFO lpSurfInfo)
{
    HSLASSERT( lpSurfInfo != 0 );
    lpSurfInfo->dwSurfFlags &= (~(SURF_HAS_FLIP_TSTAMP));
}

/*
 * SetPrimarySurfFlag:
 * This macro is used to designate a surface as the primary surface
 */
 __inline void SetPrimarySurfFlag(LPATISURFINFO lpSurfInfo)
{
    HSLASSERT(lpSurfInfo != 0);
    lpSurfInfo->dwSurfFlags |= SURF_IS_PRIMARY;
}

/*
 * IsPrimarySurf:
 * This macro is used to determine if the surface is the 
 * primary surface.
 */
 __inline BOOL IsPrimarySurf(LPATISURFINFO lpSurfInfo)
{
    HSLASSERT(lpSurfInfo != 0);
    return ( lpSurfInfo == NULL ? FALSE : lpSurfInfo->dwSurfFlags & SURF_IS_PRIMARY);
}

/*
 * ClrPrimarySurfFlag:
 * This macro is used to clear(remove) the SURF_IS_PRIMARY flag 
 */
 __inline void ClrPrimarySurfFlag(LPATISURFINFO lpSurfInfo)
{
    HSLASSERT(lpSurfInfo != 0);
    lpSurfInfo->dwSurfFlags &= (~(SURF_IS_PRIMARY));
}

/*
 * SetTStamp:
 * This macro sets up the timestamp index which is stored in LOW 32bits of 
 * the timestamp field in ATISURFINFO.
 */
__inline void SetTStamp(LPATISURFINFO lpATISurfInfo, DWORD dwTime)
{
    HSLASSERT( lpATISurfInfo != 0 );
    lpATISurfInfo->dwTSIndex = dwTime;
}

/*
 * SetWrapStamp:
 * This macro sets the wrap Stamp.
 */
__inline void SetWrapStamp(LPATISURFINFO lpATISurfInfo, DWORD dwCount)
{
    HSLASSERT( lpATISurfInfo != 0 );
    lpATISurfInfo->dwTSWrapStamp = dwCount;
}

/*
 * SetFlipTStamp:
 * This macro sets up the timestamp index for flippable surface which is stored in
 * the HIGH 32bits of the timestamp field in ATISURFINFO.
 */
__inline void SetFlipTStamp(LPATISURFINFO lpATISurfInfo, DWORD dwTime)
{
    HSLASSERT(lpATISurfInfo != 0 );
    lpATISurfInfo->dwTSFlipIndex = dwTime;
}

/*
 * SetFlipWrapStamp:
 * This macro sets the flip wrap count.
 */
__inline void SetFlipWrapStamp(LPATISURFINFO lpATISurfInfo, DWORD dwCount)
{
    HSLASSERT( lpATISurfInfo != 0 );
    lpATISurfInfo->dwTSFlipWrapStamp = dwCount;
}

/*
 * GetTilePtchSel:
 * This macro returns the TiledPtchSel value for  a tiled surface.
 * NOTE:This value can be written directly into one
 * of the SURFACEx_INFO structures.
 */
__inline DWORD GetTilePtchSel(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return GetATISurfInfoPtr(lpSLCL)->dwTiledPtchSel;
}

/*
 * SetTilePtchSel:
 * This macro sets the TiledPtchSel value for a tiled surface.
 */
__inline void SetTilePtchSel(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD dwPtchSelVal)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwTiledPtchSel = dwPtchSelVal;
}

// Set index (into CBStampArray) instead of time stamp
// in each surface.  Then each surface will have the timestamp
// of the CB when it is submitted
__inline  void TimeStampSurfaces (DWORD dwNumOfSurfaces, LPATIDXOBJECT lpATIDXObj)
{
    DWORD i;   

    //Update the time stamp index in each surface 
    for (i=0;i < dwNumOfSurfaces; i++)
    {
        // for each surface, we record the actual TimeStamp, and also the WrapStamp.
        // The WrapStamp is needed to determine if lpATIDXObj->dwCBStampArray[] entry
        // gets overwritten, before we check it.

        SetTStamp(lpATIDXObj->TimeStampArray[i], lpATIDXObj->dwCBStampIndex);
        SetWrapStamp( lpATIDXObj->TimeStampArray[i], lpATIDXObj->dwCurrentWrapStamp );

        // When GetFlipStatus is called, blt cannot
        // be busy. So we have to set flip time here. 
        if ( SurfHasCRTCSyncFlag(lpATIDXObj->TimeStampArray[i]) )
        {
            SetFlipTStamp(lpATIDXObj->TimeStampArray[i], lpATIDXObj->dwCBStampIndex);
            SetFlipWrapStamp( lpATIDXObj->TimeStampArray[i], lpATIDXObj->dwCurrentWrapStamp );
            SetSurfFlipTStampFlag(lpATIDXObj->TimeStampArray[i]);
        }

        SetSurfTStampFlag(lpATIDXObj->TimeStampArray[i]); 
    } 
}

/*
 * GetATIBPP:
 * This macro returns the pixel format of the given 
 * DDRAW surface in the RAGE128 specific format
 * NOTE: This value is setup at createsurface time.
 */
__inline DWORD GetATIBPP(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return GetATISurfInfoPtr(lpSLCL)->dwSurfPixFrmt;
}


/*
 * GetATIBPP:
 * This macro returns the pixel format of the given 
 * DDRAW surface in the RAGE128 specific format
 * NOTE: This value is setup at createsurface time.
 */
__inline DWORD GetATIBPP2( LPATISURFINFO lpATISurfInfo )
{
    HSLASSERT( lpATISurfInfo != 0 );
    return lpATISurfInfo->dwSurfPixFrmt;
}

__inline DWORD GetATIBPP3( LPDDHSLSURFACEDESC lpATISurfDesc )
{
    HSLASSERT( lpATISurfDesc != 0 );
    return lpATISurfDesc->dwBPP;
}

/*
 * GetATITexBPP:
 * This macro returns the pixel format of the given 
 * DDRAW texture surface in the RAGE128 specific format
 * NOTE: This value is setup at createsurface time.
 */
__inline DWORD GetATITexBPP(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );

  return ( GetATISurfInfoPtr(lpSLCL)->dwTexelFormat );
}

/*
 * GetATISurfInfofpVidMem:
 * This macro is used to retrieve the surface's fpVidMem pointer.
 * NOTE: This field is only valid if the HAL was responsible for
 * allocating the surface's memory.
 */
__inline FLATPTR GetATISurfInfofpVidMem(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return GetATISurfInfoPtr(lpSLCL)->fpVidMem;
}

/*
 * GetATISurfVidMemHeap:
 * This macro is used to retrieve the memory heap that the surface was allocated
 * from.
 */
__inline DWORD GetATISurfVidMemHeap(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return GetATISurfInfoPtr(lpSLCL)->dwHeap;
}

/*
 * SetATISurfInfofpVidMem:
 * This macro is used to store the surface's fpVidMem pointer inside 
 * it's ATISURFINFO structure, as well as indicate the field as valid.
 */
__inline void  SetATISurfInfofpVidMem(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, FLATPTR fpVidMem, DWORD dwHeap)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );

    //Store the vidmem pointer
    GetATISurfInfoPtr(lpSLCL)->fpVidMem = fpVidMem;
 
    //Store the heap number that the memory was allocated from
    GetATISurfInfoPtr(lpSLCL)->dwHeap = dwHeap;
}

__inline LPVOID GetATISurfRing3Addr(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return GetATISurfInfoPtr(lpSLCL)->lpRing3Addr;
}

__inline void SetATISurfRing3Addr(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, LPVOID lpAddr)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->lpRing3Addr = lpAddr;
}

__inline ULONG_PTR GetATISurfInfoSurfHandle(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return (ULONG_PTR)(GetATISurfInfoPtr(lpSLCL)->hSurface); 
}

__inline void SetATISurfInfoSurfHandle(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, ULONG_PTR hSurface)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->hSurface = hSurface;
}

//This macro calculates the frame buffer address in ATI memory space
__inline FLATPTR CreateByteOffset(LPATIDXOBJECT lpATIDXObj, FLATPTR fpVidMem)
{
    return fpVidMem - GetATIFrameBuffStart(lpATIDXObj) + lpATIDXObj->dwATI_FB_Start;
} 

/*
 * GetFrameBuffOffset: This macro is used to retrieve
 * the BYTE offset of any given surface from the base of
 * the videomemory
*/
__inline FLATPTR GetFrameBuffOffset(LPATIDXOBJECT lpATIDXObj, LPDDRAWI_DDRAWSURFACE_LCL lpDDSurf_LCL)
{
    return (GetDDSurffpVidMem(lpDDSurf_LCL) - GetATIFrameBuffStart(lpATIDXObj));
            
}

/*
 * GetATISurfOffset:
 * This macro is used to retrieve the surface's dwSurfOffset pointer.
 * This value is in terms that are applicable to the surface type (i.e.
 * if it's a TEXTUTE, it will be BYTE offset etc.)
 * NOTE: This field is only valid if the HAL was responsible for the memory
 * allocation
 */
__inline DWORD_PTR GetATISurfOffset(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return GetATISurfInfoPtr(lpSLCL)->dwSurfOffset;
}


/*
 * GetATISurfOffset:
 * This macro is used to retrieve the surface's dwSurfOffset pointer.
 * This value is in terms that are applicable to the surface type (i.e.
 * if it's a TEXTUTE, it will be BYTE offset etc.)
 * NOTE: This field is only valid if the HAL was responsible for the memory
 * allocation
 */
__inline DWORD_PTR GetATISurfOffset2( LPATISURFINFO lpATISurfInfo )
{
    HSLASSERT( lpATISurfInfo != 0 );
    return lpATISurfInfo->dwSurfOffset;
}

__inline DWORD_PTR GetATISurfOffset3( LPDDHSLSURFACEDESC lpATISurfDesc )
{
    HSLASSERT( lpATISurfDesc != 0 );
    return lpATISurfDesc->dwMCOffset;
}

#ifdef UMD
__inline D3DKMT_HANDLE GetATISurfAllocHandle( LPATISURFINFO lpATISurfInfo )
{
    HSLASSERT( lpATISurfInfo != 0 );
    return lpATISurfInfo->hAllocation;
}
#else
__inline HANDLE GetATISurfAllocHandle( LPATISURFINFO lpATISurfInfo )
{
    return NULL;
}
#endif

/*
 * SetATISurfOffset:
 * This macro is used to set the surface's dwSurfOffset pointer.
 * This value is in terms that applicable to the surface type (i.e.
 * if it's a TEXTUTE, it will be BYTE offset etc.)
 * NOTE: This field is only valid if the HAL was responsible for
 * allocating the surface's memory and it's a texture.
 */
__inline void SetATISurfOffset(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD_PTR dwOffset)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwSurfOffset = dwOffset;
}

/*
 * GetATISurfPitch:
 * This macro is used to retrieve the surface's pitch in terms that are applicable
 * to the surface type(i.e. if it's a TEXTURE, it will be a LOG2 pitch etc.)
 * NOTE: This field is only valid if the HAL was responsible for the memory
 * allocation
 */
__inline DWORD GetATISurfPitch(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return GetATISurfInfoPtr(lpSLCL)->dwSurfPitch;
}

/*
 * GetATISurfPitch2:
 * This macro is used to retrieve the surface's pitch in terms that are applicable
 * to the surface type(i.e. if it's a TEXTURE, it will be a LOG2 pitch etc.)
 * NOTE: This field is only valid if the HAL was responsible for the memory
 * allocation
 */
__inline DWORD GetATISurfPitch2( LPATISURFINFO lpATISurfInfo )
{
    HSLASSERT( lpATISurfInfo != 0 );
    return lpATISurfInfo->dwSurfPitch;
}


__inline DWORD GetATISurfPitch3( LPDDHSLSURFACEDESC lpATISurfDesc )
{
    HSLASSERT( lpATISurfDesc != 0 );
    return lpATISurfDesc->lPitch;
}

/*
 * SetATISurfPitch:
 * This macro is used to set the surface's pitch in terms that are applicable
 * to the surface type(i.e. if it's a TEXTURE, it will be a LOG2 pitch etc.)
 * NOTE: This field is only valid if the HAL was responsible for the memory
 * allocation
 */
__inline void SetATISurfPitch(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD dwPitch)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwSurfPitch = dwPitch;
}


/*
 * GetATITexMCOffset:
 * This macro is used to retrieve the MC offset for texture surface.
 */
__inline DWORD_PTR GetATITexMCOffset(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return GetATISurfInfoPtr(lpSLCL)->dwTexMCOffset;
}

/*
 * SetATITexMCOffset:
 * This macro is used to set the MC offset for texture surface.
 */
__inline void SetATITexMCOffset(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD_PTR dwTexMCOffset)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwTexMCOffset = dwTexMCOffset;
}

/*
 * IsSurfTiled:
 * This macro returns TRUE if the indicated surface is tiled
 */
__inline DWORD IsSurfTiled(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return (GetATISurfInfoPtr(lpSLCL)->dwSurfFlags & HSL_SURF_IS_TILED);
}

/*
 * IsSurfTiled2:
 * This macro returns TRUE if the indicated surface is tiled
 */
__inline DWORD IsSurfTiled2( LPATISURFINFO lpATISurfInfo )
{
    if ( !lpATISurfInfo )
    {
        HSLASSERT( lpATISurfInfo != 0 );
        return 0;
    }
    return (lpATISurfInfo->dwSurfFlags & HSL_SURF_IS_TILED);
}

__inline DWORD IsSurfTiled3( LPDDHSLSURFACEDESC lpATISurfDesc )
{
    if ( !lpATISurfDesc )
    {
        HSLASSERT( lpATISurfDesc != 0 );
        return 0;
    }
    return (lpATISurfDesc->dwFlags & HSL_SURF_IS_TILED);
}

/*
 * IsSurfMicroTiled:
 * This macro returns TRUE if the indicated surface is microtiled
 */
__inline DWORD IsSurfMicroTiled(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return (GetATISurfInfoPtr(lpSLCL)->dwSurfFlags & HSL_SURF_IS_MICROTILED);
}

/*
 * IsSurfMicroTiled2:
 * This macro returns TRUE if the indicated surface is microtiled
 */
__inline DWORD IsSurfMicroTiled2( LPATISURFINFO lpATISurfInfo )
{
    if ( !lpATISurfInfo )
    {
        HSLASSERT( lpATISurfInfo != 0 );
        return 0;
    }
    return (lpATISurfInfo->dwSurfFlags & HSL_SURF_IS_MICROTILED);
}

__inline DWORD IsSurfMicroTiled3( LPDDHSLSURFACEDESC lpATISurfDesc )
{
    if ( !lpATISurfDesc )
    {
        HSLASSERT( lpATISurfDesc != 0 );
        return 0;
    }
    return (lpATISurfDesc->dwFlags & HSL_SURF_IS_MICROTILED);
}

/*
 * IsSurfPalettized:
 * This macro returns TRUE if the indicated surface is palettized
 */
__inline DWORD IsSurfPalettized(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return ( GetATISurfInfoPtr(lpSLCL)->dwSurfFlags & SURF_IS_PALETTIZED);
}


/*
 * IsSurfPalettized2:
 * This macro returns TRUE if the indicated surface is palettized
 */
__inline DWORD IsSurfPalettized2( LPATISURFINFO lpSurfInfo )
{
    HSLASSERT( lpSurfInfo != 0 );
    return ( lpSurfInfo->dwSurfFlags & SURF_IS_PALETTIZED);
}

__inline DWORD IsSurfPalettized3( LPDDHSLSURFACEDESC lpSurfDesc )
{
    HSLASSERT( lpSurfDesc != 0 );
    HSLASSERT( lpSurfDesc->lpddPixelFormat != 0);

    return (lpSurfDesc->lpddPixelFormat->dwFlags & DDPF_PALETTEINDEXED8);
}

/*
 * GetATIColorPitch:
 * This macro is used to retrieve the surface's color pitch.
 */
__inline DWORD GetATIColorPitch(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return GetATISurfInfoPtr(lpSLCL)->dwColorPitch;
}

/*
 * GetATIColorPitch:
 * This macro is used to retrieve the surface's color pitch.
 */
__inline DWORD GetATIColorPitch2( LPATISURFINFO lpSurfInfo )
{
    HSLASSERT( lpSurfInfo != 0 );
    return lpSurfInfo->dwColorPitch;
}

/*
 * SetATIColorPitch:
 * This macro is used to set the surface's color pitch.
 */
__inline void SetATIColorPitch(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD dwColorPitch)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwColorPitch = dwColorPitch;
}

/*
 * GetATIColorFormat:
 * This macro is used to retrieve the surface's color format for RB3D_CNTL.
 */
__inline DWORD GetATIColorFormat(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return GetATISurfInfoPtr(lpSLCL)->dwColorFormat;
}

/*
 * GetATIColorFormat2:
 * This macro is used to retrieve the surface's color format for RB3D_CNTL.
 */
__inline DWORD GetATIColorFormat2( LPATISURFINFO lpSurfInfo )
{
    HSLASSERT( lpSurfInfo != 0 );
    return lpSurfInfo->dwColorFormat;
}

/*
 * GetATITexelFormat:
 * This macro is used to retrieve the surface's texel format for PP_TXFORMAT_n.
 */
__inline DWORD GetATITexelFormat(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return GetATISurfInfoPtr(lpSLCL)->dwTexelFormat;
}

/*
 * GetATITexelFormat2:
 * This macro is used to retrieve the surface's texel format for PP_TXFORMAT_n.
 */
__inline DWORD GetATITexelFormat2( LPATISURFINFO lpATISurfInfo )
{
    HSLASSERT( lpATISurfInfo != 0 );
    return lpATISurfInfo->dwTexelFormat;
}

/*
 * GetATIPixelFormat:
 * This macro is used to retrieve the surface's pixel format.
 */
__inline DWORD GetATIPixelFormat(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
  return GetATITexelFormat(lpSLCL);
}

/*
 * GetATIPixelFormat2:
 * This macro is used to retrieve the surface's pixel format.
 */
__inline DWORD GetATIPixelFormat2( LPATISURFINFO lpATISurfInfo )
{
  return GetATITexelFormat2(lpATISurfInfo);
}

__inline DWORD GetATIPixelFormat3( LPDDHSLSURFACEDESC lpATISurfDesc )
{
  HSLASSERT( lpATISurfDesc != 0 );
  HSLASSERT( lpATISurfDesc->lpddPixelFormat != 0 );
  return (GetATiSurfTexelFormat(lpATISurfDesc->lpddPixelFormat));
}

/*
 * ClearSurfTiledFlag:
 * This macro is used to clear the HSL_SURF_IS_TILED 
 * member of the ATISURFINFO structure.
 */
__inline void ClearSurfTiledFlag(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwSurfFlags &= ~HSL_SURF_IS_TILED;
}

/*
 * MakeAtiPitch:
 * This macro is used to calculate the pitch for the PITCH_OFFSET from the byte pitch
*/

_inline DWORD MakeAtiPitch(DWORD dwBytePitch, DWORD dwBytesPerPixel)  
{
  return (dwBytePitch >> 6);
}

/*
 * MakeAtiOffset:
 * This macro is used to calculate the offset for the PITCH_OFFSET from the full offset
*/

_inline DWORD MakeAtiOffset(DWORD_PTR  dwFullOffset)  
{
  return (DWORD) (dwFullOffset >> 10);
}

/*
 * MakeAtiColorPitch:
 * This macro is used to calculate the pitch for the RB3D_COLORPITCH from the byte pitch
*/

_inline DWORD MakeAtiColorPitch(DWORD dwBytePitch, DWORD dwBytesPerPixel)  
{
  return (dwBytePitch / dwBytesPerPixel);
}

/*
 * MakeOffPitch:
 * This macro is used to create a surfaces offset/pitch combination to be used by the hardware.
 * dwOffset is in units of 1024 bytes for Rage 5 and 32 bytes for Rage 128
 * dwAtiPitch is in returned by MakeAtiPitch
*/

_inline DWORD MakeAtiOffPitch(DWORD dwAtiOffset, DWORD dwAtiPitch, DWORD dwAtiTile)
{
  return ((dwAtiPitch << DST_PITCH_OFFSET__DST_PITCH__SHIFT) & DST_PITCH_OFFSET__DST_PITCH_MASK) | 
         ((dwAtiOffset << DST_PITCH_OFFSET__DST_OFFSET__SHIFT) & DST_PITCH_OFFSET__DST_OFFSET_MASK) |
         ((dwAtiTile << DST_PITCH_OFFSET__DST_TILE__SHIFT) & DST_PITCH_OFFSET__DST_TILE_MASK);
}

/*
 * MakeTempOffPitch:
 * This macro is used to create a temporary surface's offset/pitch
*/
__inline DWORD MakeTempOffPitch(DWORD_PTR dwOffset, DWORD dwBytePitch, DWORD dwAtiTile)  
{
    return MakeAtiOffPitch(MakeAtiOffset(dwOffset), MakeAtiPitch(dwBytePitch, 0), dwAtiTile);
}

/*
 * MakeATISurfOffPitch:
 * This macro is used to create a surface's offset/pitch
 * combination to be used by the Rage 5 or R128 hardware.
*/
_inline DWORD MakeATISurfOffPitch(LPDDRAWI_DDRAWSURFACE_LCL lpDDSurf_LCL)  
{
  return MakeAtiOffPitch(MakeAtiOffset(GetATISurfOffset(lpDDSurf_LCL)), 
                                       GetATISurfPitch(lpDDSurf_LCL), 
                                       (IsSurfTiled(lpDDSurf_LCL) ? 1 : 0) | 
                                       (IsSurfMicroTiled(lpDDSurf_LCL) ? 2 : 0));
}
/*
 * MakeATISurfOffPitchZB:
 * This macro is used to create a z-buffer surface's offset/pitch
 * combination to be used by the Rage 5 or R128 hardware.
*/
_inline DWORD MakeATISurfOffPitchZB(LPDDRAWI_DDRAWSURFACE_LCL lpDDSurf_LCL)  
{
  return MakeAtiOffPitch(MakeAtiOffset(GetATISurfOffset(lpDDSurf_LCL)), 
                                       GetATISurfPitch(lpDDSurf_LCL), 0);
}

/*
 * MakeATISurfOffPitch2:
 * This macro is used to create a surface's offset/pitch
 * combination to be used by the Rage 5 or R128 hardware.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
_inline DWORD MakeATISurfOffPitch2( LPATISURFINFO lpATISurfInfo )  
{
  return MakeAtiOffPitch( MakeAtiOffset(GetATISurfOffset2(lpATISurfInfo) ),
                          GetATISurfPitch2(lpATISurfInfo),
                          ( IsSurfTiled2(lpATISurfInfo) ? 1 : 0 ) | 
                          ( IsSurfMicroTiled2(lpATISurfInfo) ? 2 : 0 ) );
}

/*
 * MakeATISurfOffPitch3:
 * This macro is used to create a surface's offset/pitch
 * combination to be used by the Rage 5 or R128 hardware.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
_inline DWORD MakeATISurfOffPitch3( LPDDHSLSURFACEDESC lpATISurfDesc )  
{
  return MakeAtiOffPitch( MakeAtiOffset(GetATISurfOffset3(lpATISurfDesc) ),
                          GetATISurfPitch3(lpATISurfDesc),
                          ( IsSurfTiled3(lpATISurfDesc) ? 1 : 0 ) | 
                          ( IsSurfMicroTiled3(lpATISurfDesc) ? 2 : 0 ) );
}

/*
 * MakeATISurfOffPitchZB2:
 * This macro is used to create a z-buffer surface's offset/pitch
 * combination to be used by the Rage 5 or R128 hardware.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
_inline DWORD MakeATISurfOffPitchZB2( LPATISURFINFO lpATISurfInfo )  
{
  return MakeAtiOffPitch( MakeAtiOffset(GetATISurfOffset2(lpATISurfInfo) ),
                          GetATISurfPitch2(lpATISurfInfo), 0);
}

/*
 * GetATIColorOffset:
 * This macro is used to retrieve the surface's color offset for RB3D_COLOROFFSET.
 */
__inline DWORD_PTR GetATIColorOffset(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
  return GetATISurfOffset(lpSLCL);
}

/*
 * GetATIColorOffset2:
 * This macro is used to retrieve the surface's color offset for RB3D_COLOROFFSET.
 */
__inline DWORD_PTR GetATIColorOffset2( LPATISURFINFO lpSurfInfo )
{
  return GetATISurfOffset2(lpSurfInfo);
}


/*
 * GetATITexelOffset:
 * This macro is used to retrieve a surface's texel offset for PP_TXOFFSET_n.
 */
__inline DWORD_PTR GetATITexelOffset(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
  return GetATISurfOffset(lpSLCL);
}

/*
 * GetATITexelOffset2:
 * This macro is used to retrieve a surface's texel offset for PP_TXOFFSET_n.
 */
__inline DWORD_PTR GetATITexelOffset2( LPATISURFINFO lpSurfInfo )
{
  return GetATISurfOffset2(lpSurfInfo);
}

/*
 * GetATITexelPitch:
 * This macro is used to retrieve the surface's texel pitch for PP_TXPITCH_n.
 */
__inline DWORD GetATITexelPitch(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
  return GetDDSurfacePitch(lpSLCL);
}

/*
 * GetATITexelPitch2:
 * This macro is used to retrieve the surface's texel pitch for PP_TXPITCH_n.
 */
__inline DWORD GetATITexelPitch2( LPDDHSLSURFACEDESC lpSurfDesc )
{
  return GetDDSurfacePitch2(lpSurfDesc);
}

/*************************YUV Surface functions****************************/
/*
 * GetYOffset:-
 * This function returns the offset (in OCTWORDS) of the Y-Plane of a 
 * YUV planar surface.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
__inline FLATPTR GetYOffset2( LPATIDXOBJECT lpATIDXObj, LPDDHSLSURFACEDESC lpSurfDesc )
{
    return CreateByteOffset( lpATIDXObj, lpSurfDesc->fpVidMem ); 
}

/*
 * GetYColorOffset2:-
 * This function returns the offset (in OCTWORDS) of the Y-Plane of a 
 * YUV planar surface.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
__inline FLATPTR GetYColorOffset2( LPATIDXOBJECT lpATIDXObj, LPDDHSLSURFACEDESC lpSurfDesc )
{
    return GetYOffset2( lpATIDXObj, lpSurfDesc );
}

/*
 * GetYTexelOffset2:
 * This macro is used to retrieve a Y plane's texel offset for PP_TXOFFSET_n.
 * NOTE: This is used in cases where we do not have a surface local pointer.
 */
__inline FLATPTR GetYTexelOffset2( LPATIDXOBJECT lpATIDXObj, LPDDHSLSURFACEDESC lpSurfDesc )
{
    return GetYOffset2( lpATIDXObj, lpSurfDesc );
}

/*
 * GetVOffset2:-
 * This function returns the offset of the V-Plane (OCTWORDS) of a 
 * YUV planar surface.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
__inline FLATPTR GetVOffset2( LPATIDXOBJECT lpATIDXObj, LPDDHSLSURFACEDESC lpSurfDesc )
{
    return ( GetYOffset2( lpATIDXObj, lpSurfDesc ) + (lpSurfDesc->dwHeight * lpSurfDesc->lPitch) );
}

/*
 * GetVColorOffset2:-
 * This function returns the offset of the V-Plane (OCTWORDS) of a 
 * YUV planar surface.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
__inline FLATPTR GetVColorOffset2( LPATIDXOBJECT lpATIDXObj, LPDDHSLSURFACEDESC lpSurfDesc )
{
    return GetVOffset2( lpATIDXObj, lpSurfDesc );
}

/*
 * GetVTexelOffset2:
 * This macro is used to retrieve a V plane's texel offset for PP_TXOFFSET_n.
 * NOTE: This is used in cases where we do not have a surface local pointer.
 */
__inline FLATPTR GetVTexelOffset2( LPATIDXOBJECT lpATIDXObj, LPDDHSLSURFACEDESC lpSurfDesc )
{
    return GetVOffset2( lpATIDXObj, lpSurfDesc );
}

/*
 * GetUOffset:-
 * This function returns the offset of the U-Plane (in OCTWORDS) of a 
 * YUV planar surface. With this macro we have to distinguish 
 * between YV12 and YUV/IF09 surface's.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
__inline FLATPTR GetUOffset2( LPATIDXOBJECT lpATIDXObj, LPDDHSLSURFACEDESC lpSurfDesc )
{
    if ( lpSurfDesc->lpddPixelFormat->dwFourCC == FOURCC_YV12)
    {
        return GetVOffset2( lpATIDXObj, lpSurfDesc ) + 
            (( lpSurfDesc->dwHeight * lpSurfDesc->lPitch ) >> 2); 
    }
    else
    {
        return GetVOffset2( lpATIDXObj, lpSurfDesc ) + 
            (( lpSurfDesc->dwHeight * lpSurfDesc->lPitch ) >> 4); 
    }
}

/*
 * GetUColorOffset2:-
 * This function returns the offset of the U-Plane (in OCTWORDS) of a 
 * YUV planar surface. With this macro we have to distinguish 
 * between YV12 and YUV/IF09 surface's.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
__inline FLATPTR GetUColorOffset2( LPATIDXOBJECT lpATIDXObj, LPDDHSLSURFACEDESC lpSurfDesc )
{
    return GetUOffset2( lpATIDXObj, lpSurfDesc );
}

/*
 * GetUTexelOffset2:
 * This macro is used to retrieve a U plane's texel offset for PP_TXOFFSET_n.
 * NOTE: This is used in cases where we do not have a surface local pointer.
 */
__inline FLATPTR GetUTexelOffset2( LPATIDXOBJECT lpATIDXObj, LPDDHSLSURFACEDESC lpSurfDesc )
{  
    return GetUOffset2( lpATIDXObj, lpSurfDesc );
}

/*
 * GetYPitch2:-
 * This function returns the pitch (in OCTWORDS) of the Y-Plane of a 
 * YUV planar surface.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
__inline DWORD GetYPitch2( LPDDHSLSURFACEDESC lpSurfDesc )
{
    return GetDDSurfacePitch2( lpSurfDesc ); 
}

/*
 * GetYColorPitch2:-
 * This function returns the color pitch of the Y-Plane of a 
 * YUV planar surface.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
__inline DWORD GetYColorPitch2( LPDDHSLSURFACEDESC lpSurfDesc )
{
    return GetYPitch2( lpSurfDesc ); 
}

/*
 * GetYTexelPitch:-
 * This function returns the texel pitch (in OCTWORDS) of the Y-Plane of a 
 * YUV planar surface.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
__inline DWORD GetYTexelPitch2( LPDDHSLSURFACEDESC lpSurfDesc )
{
    return GetYPitch2( lpSurfDesc );
}

/*
 * GetUVPitch2:-
 * This function returns the pitch (in OCTWORDS) of the UV-Planes of a 
 * YUV planar surface. With this macro we have to distinguish 
 * between YV12 and YUV/IF09 surface's.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
__inline DWORD GetUVPitch2( LPDDHSLSURFACEDESC lpSurfDesc )
{
    if( lpSurfDesc->lpddPixelFormat->dwFourCC == FOURCC_YV12 )
    {
        return GetYPitch2(lpSurfDesc) >> 1; 
    }
    
    else
    {
        return GetYPitch2(lpSurfDesc) >> 2; 
    }
}

/*
 * GetUVColorPitch2:-
 * This function returns the color pitch of the UV-Planes of a 
 * YUV planar surface. With this macro we have to distinguish 
 * between YV12 and YUV/IF09 surface's.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
__inline DWORD GetUVColorPitch2( LPDDHSLSURFACEDESC lpSurfDesc )
{
    return GetUVPitch2(lpSurfDesc);
}

/*
 * GetUVTexelPitch:-
 * This function returns the texel pitch of the UV-Planes of a 
 * YUV planar surface. With this macro we have to distinguish 
 * between YV12 and YUV/IF09 surface's.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
__inline DWORD GetUVTexelPitch2( LPDDHSLSURFACEDESC lpSurfDesc )
{
    return GetUVPitch2( lpSurfDesc );
}

/*
 * GetUVWidth2:-
 * This function returns the width (in OCTWORDS) of the UV-Planes of a 
 * YUV planar surface. With this macro we have to distinguish 
 * between YV12 and YUV/IF09 surface's.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
__inline DWORD GetUVWidth2( LPDDHSLSURFACEDESC lpSurfDesc )
{
    if( lpSurfDesc->lpddPixelFormat->dwFourCC == FOURCC_YV12 )
    {
        return lpSurfDesc->dwWidth >> 1; 
    }

    else
    {
        return lpSurfDesc->dwWidth >> 2; 
    }
}

/*
 * GetUVHeight:-
 * This function returns the height (in OCTWORDS) of the UV-Planes of a 
 * YUV planar surface. With this macro we have to distinguish 
 * between YV12 and YUV/IF09 surface's.
 * NOTE: This is used in cases where we do not have a surface local pointer.
*/
__inline DWORD GetUVHeight2( LPDDHSLSURFACEDESC lpSurfDesc )
{
    if( lpSurfDesc->lpddPixelFormat->dwFourCC == FOURCC_YV12)
    {
        return lpSurfDesc->dwHeight >> 1; 
    }
 
    else
    {
        return lpSurfDesc->dwHeight >> 2; 
    }
}

/*************************End YUV Surface functions****************************/

/*
 * SetTexLOG2Pitch:
 * This macro is used to set the surface's dwTexLOG2Pitch member.
 * NOTE: This field is only valid if the HAL was responsible for
 * allocating the surface's memory and it's a texture.
 */
__inline void SetTexLOG2Pitch(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD dwLog2Pitch)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwTexLOG2Pitch = dwLog2Pitch;
}

/*
 * GetTexLOG2Pitch:
 * This macro returns the LOG2 pitch of a texture surface.
 * NOTE: This field is only valid if the HAL was responsible for
 * allocating the surface's memory and it's a texture.
 */
__inline DWORD GetTexLOG2Pitch(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return ( GetATISurfInfoPtr(lpSLCL)->dwTexLOG2Pitch);

}

/*
 * SetTexLOG2Width:
 * This macro is used to set the surface's dwTexLOG2Width member.
 * NOTE: This field is only valid if the HAL was responsible for
 * allocating the surface's memory and it's a texture.
 */
__inline void SetTexLOG2Width(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD dwLog2Width)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwTexLOG2Width = dwLog2Width;
}

/*
 * GetTexLOG2Width:
 * This macro returns the LOG2 width of a texture surface.
 * NOTE: This field is only valid if the HAL was responsible for
 * allocating the surface's memory and it's a texture.
 */
__inline DWORD GetTexLOG2Width(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return ( GetATISurfInfoPtr(lpSLCL)->dwTexLOG2Width);
}

/*
 * SetTexLOG2Height:
 * This macro is used to set the surface's dwTexLOG2Height member.
 * NOTE: This field is only valid if the HAL was responsible for
 * allocating the surface's memory and it's a texture.
 */
__inline void SetTexLOG2Height(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD dwLog2Height)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwTexLOG2Height = dwLog2Height;
}

/*
 * GetTexLOG2Height:
 * This macro returns the LOG2 height of a texture surface.
 * NOTE: This field is only valid if the HAL was responsible for
 * allocating the surface's memory and it's a texture.
 */
__inline DWORD GetTexLOG2Height(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return ( GetATISurfInfoPtr(lpSLCL)->dwTexLOG2Height);
}

/*
 * SetTexLOG2Size:
 * This macro is used to set the surface's dwTexLOG2Size member. If the texture
 * is not square, this will be the LOG2 size of the largest dimension.
 * NOTE: This field is only valid if the HAL was responsible for
 * allocating the surface's memory and it's a texture.
 */
__inline void SetTexLOG2Size(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD dwLog2Size)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwTexLOG2Size = dwLog2Size;
}

/*
 * GetTexLOG2Size:
 * This macro returns the LOG2 size of a texture surface. If the texture
 * is not square, this will be the LOG2 size of the largest dimension.
 * NOTE: This field is only valid if the HAL was responsible for
 * allocating the surface's memory and it's a texture.
 */
__inline DWORD GetTexLOG2Size(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return ( GetATISurfInfoPtr(lpSLCL)->dwTexLOG2Size);
}

/*
 * SetSurfIsYUVPLANAR:
 * This macro is used to set the surface's SURF_IS_YUVPLANAR member of
 * the ATISURFINFO structure.
 * NOTE: This field is only valid for OVERLAYS!!!
 */
__inline void SetSurfIsYUVPlaner(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwSurfFlags |=SURF_IS_YUVPLANAR;
}

/*
 * IsSurfYUVPlanar:
 * This macro returns TRUE if the indicated surface is a YUV(planar)
 * OVERLAY.
 */
__inline DWORD IsSurfYUVPlanar(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return ( GetATISurfInfoPtr(lpSLCL)->dwSurfFlags & SURF_IS_YUVPLANAR);
}

/*
 * IsSurfYUVPlanar2:
 * This macro returns TRUE if the indicated surface is a YUV(planar)
 * OVERLAY.
 */
__inline DWORD IsSurfYUVPlanar2( LPATISURFINFO lpSurfInfo )
{
    HSLASSERT( lpSurfInfo != 0 );
    return ( lpSurfInfo->dwSurfFlags & SURF_IS_YUVPLANAR);
}

__inline DWORD IsSurfYUVPlanar3( LPDDHSLSURFACEDESC lpSurfDesc )
{
    HSLASSERT( lpSurfDesc != 0 );
    HSLASSERT( lpSurfDesc->lpddPixelFormat != 0);

    if (! (lpSurfDesc->lpddPixelFormat->dwFlags & DDPF_FOURCC))
    {
        return (FALSE);
    }

    switch (lpSurfDesc->lpddPixelFormat->dwFourCC)
    {
        case FOURCC_YV12:
        case FOURCC_IYUV:
        case FOURCC_IMC4:
        case FOURCC_YVU9:
        case FOURCC_IF09:
            return (TRUE);

        default:
            return (FALSE);
    }
}

/*
 * SetSurfIsYUV:
 * This macro is used to set the surface's SURF_IS_YUV member of
 * the ATISURFINFO structure.
 */
__inline void SetSurfIsYUV(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwSurfFlags |= SURF_IS_YUV;
}

/*
 * IsSurfYUV:
 * This macro returns TRUE if the indicated surface is YUV
 */
__inline DWORD IsSurfYUV(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return (GetATISurfInfoPtr(lpSLCL)->dwSurfFlags & SURF_IS_YUV);
}

/*
 * IsSurfYUV2:
 * This macro returns TRUE if the indicated surface is YUV
 */
__inline DWORD IsSurfYUV2( LPATISURFINFO lpSurfInfo )
{
    HSLASSERT( lpSurfInfo != 0 );
    return (lpSurfInfo->dwSurfFlags & SURF_IS_YUV);
}

__inline DWORD IsSurfYUV3( LPDDHSLSURFACEDESC lpSurfDesc )
{
    HSLASSERT( lpSurfDesc != 0 );
    HSLASSERT( lpSurfDesc->lpddPixelFormat != 0 );

    if (! (lpSurfDesc->lpddPixelFormat->dwFlags & DDPF_FOURCC))
    {
        return (FALSE);
    }

    switch (lpSurfDesc->lpddPixelFormat->dwFourCC)
    {
        case FOURCC_YUY2:
        case FOURCC_UYVY:
        case FOURCC_YV12:
        case FOURCC_IYUV:
        case FOURCC_IMC4:
        case FOURCC_YVU9:
        case FOURCC_IF09:
        case FOURCC_AYUV:
            return (TRUE);
        default:
            return (FALSE);
    }
}

/*
 * SetSurfIsPowerOfTwo:
 * This macro is used to set the surface's SURF_IS_POWER_OF_TWO member of
 * the ATISURFINFO structure.
 */
__inline void SetSurfIsPowerOfTwo(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwSurfFlags |= SURF_IS_POWER_OF_TWO;
}

/*
 * IsSurfPowerOfTwo:
 * This macro returns TRUE if the indicated surface has a power of 2 size
 */
__inline DWORD IsSurfPowerOfTwo(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return ( GetATISurfInfoPtr(lpSLCL)->dwSurfFlags & SURF_IS_POWER_OF_TWO);
}

/*
 * SetSurfIsTiled:
 * This macro is used to set the HSL_SURF_IS_TILED member of
 * the ATISURFINFO structure.
 */
__inline void SetSurfIsTiled(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwSurfFlags |= HSL_SURF_IS_TILED;
}

/*
 * UnSetSurfIsTiled:
 * This macro is used to clear the HSL_SURF_IS_TILED member of
 * the ATISURFINFO structure.
 */
__inline void UnSetSurfIsTiled(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwSurfFlags &= ~HSL_SURF_IS_TILED;
}

/*
 * SetSurfIsMicroTiled:
 * This macro is used to set the HSL_SURF_IS_MICROTILED member of
 * the ATISURFINFO structure.
 */
__inline void SetSurfIsMicroTiled(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwSurfFlags |= HSL_SURF_IS_MICROTILED;
}

/*
 * UnSetSurfIsMicroTiled:
 * This macro is used clear the HSL_SURF_IS_MICROTILED member of
 * the ATISURFINFO structure.
 */
__inline void UnSetSurfIsMicroTiled(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwSurfFlags &= ~HSL_SURF_IS_MICROTILED;
}

/*
 * SetSurfIsFSBackBuffer:
 * This macro is used set the SURF_IS_FSBACKBUFFER flag in dwSurfFlags 
 * field of the ATISURFINFO structure.
 */
__inline void SetSurfIsFSBackBuffer(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwSurfFlags |= SURF_IS_FSBACKBUFFER;
}

/*
 * IsSurfFSBackBuffer:
 * This macro returns true if the SURF_IS_FSBACKBUFFER flag is set.
 */
__inline DWORD IsSurfFSBackBuffer(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return ( GetATISurfInfoPtr(lpSLCL)->dwSurfFlags & SURF_IS_FSBACKBUFFER);
}

/*
 * SetSurfIsDynamic:
 * This macro is used set the SURF_IS_DYNAMIC flag in dwSurfFlags 
 * field of the ATISURFINFO structure.
 */
__inline void SetSurfIsDynamic(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwSurfFlags |= SURF_IS_DYNAMIC;
}

/*
 * GetSurfaceBytesPerPixel:
 * This macro is used to return the surface's dwBytesPerPixel
 * member of the ATISURFINFO structure.
 */
__inline DWORD GetSurfaceBytesPerPixel(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return GetATISurfInfoPtr(lpSLCL)->dwBytesPerPixel;
}


/*
 * GetSurfaceBytesPerPixel2:
 * This macro is used to return the surface's dwBytesPerPixel
 * member of the ATISURFINFO structure.
 */
__inline DWORD GetSurfaceBytesPerPixel2( LPATISURFINFO lpSurfInfo )
{
    HSLASSERT( lpSurfInfo != 0 );
    return lpSurfInfo->dwBytesPerPixel;
}

/*
 * SetSurfFCCOffset:
 * This macro is used set the FCC offset field of the ATISurfInfo structure.
 * This offset is used as the depth offset in Fast Color Clears.
 * For more information on Fast Color Clears goto FastColorClear() in clear.c.
 */
VOID __inline SetSurfFCCOffset( LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD dwFCCDepthOffset )
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwFCCDepthOffset = dwFCCDepthOffset;
}

/*
 * SetSurfFCCOffset:
 * This macro is used set the FCC height field of the ATISurfInfo structure.
 * This height is used as the quad height in Fast Color Clears.
 * For more information on Fast Color Clears goto FastColorClear() in clear.c.
 */
VOID __inline SetSurfFCCHeight( LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD dwFCCHeight )
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    GetATISurfInfoPtr(lpSLCL)->dwFCCHeight = dwFCCHeight;
}

/*
 * GetSurfFCCOffset:
 * This macro is used get the FCC offset field of the ATISurfInfo structure.
 * For more information on Fast Color Clears goto FastColorClear() in clear.c.
 */
DWORD __inline GetSurfFCCOffset( LPDDRAWI_DDRAWSURFACE_LCL lpSLCL )
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return GetATISurfInfoPtr(lpSLCL)->dwFCCDepthOffset;
}

/*
 * GetSurfFCCHeight:
 * This macro is used get the FCC height field of the ATISurfInfo structure.
 * For more information on Fast Color Clears goto FastColorClear() in clear.c.
 */
DWORD __inline GetSurfFCCHeight( LPDDRAWI_DDRAWSURFACE_LCL lpSLCL )
{
    HSLASSERT( GetATISurfInfoPtr(lpSLCL) != 0 );
    return GetATISurfInfoPtr(lpSLCL)->dwFCCHeight;
}


/*
 * SetupFCCInfo:
 * This macro is used to setup the FCC information in the ATISurfInfo structure.
 * For more information on Fast Color Clears goto FastColorClear() in clear.c.
 */
_inline DWORD SetupFCCInfo( DWORD dwPitch, DWORD dwPitchAlign,
                            DWORD dwHeight, DWORD dwHeightAlign,
                            LPDWORD lpdwFCCDepthOffset, 
                            LPDWORD lpdwFCCHeight)
{
    DWORD dwFCCDepthOffset;
    DWORD dwFCCHeight;

    DWORD dwMiddleOffsetHeight;

    DWORD dwExtraHeight = 0;
    
    // Calculuate aligned pitch and height.
    DWORD dwAlignedPitch = ( dwPitch + (dwPitchAlign-1) ) & ~(dwPitchAlign-1);
    DWORD dwAlignedHeight = ( dwHeight + (dwHeightAlign-1) ) & ~(dwHeightAlign-1);

    DWORD dwBufferSize = ( dwAlignedPitch * dwAlignedHeight );

    DWORD dwMiddleOffset = dwBufferSize >> 1;

    // Make sure depth offset is aligned to nearest 4k.
    dwFCCDepthOffset = ( dwMiddleOffset + 4095 ) & ~4095;

    if( dwFCCDepthOffset >= dwBufferSize  )
    {
        dwFCCDepthOffset = 0;
        dwFCCHeight = 0;
    }
    else
    {
        dwMiddleOffsetHeight = dwMiddleOffset / dwAlignedPitch;
        dwFCCHeight = ( ( dwFCCDepthOffset / dwAlignedPitch ) + 15 ) & ~15;

        dwExtraHeight = dwFCCHeight - dwMiddleOffsetHeight;
        dwExtraHeight = ( dwExtraHeight + 15 ) & ~15;

        dwFCCHeight += dwExtraHeight;
    }

    *lpdwFCCDepthOffset = dwFCCDepthOffset;
    *lpdwFCCHeight = dwFCCHeight;
    
    dwExtraHeight = dwExtraHeight << 1;

    return dwExtraHeight;
}

/**************** PIGLET INLINE MACROS BEGIN ****************************/
/*
 * GetCRTCSyncEntries:
 * This macro returns the number of PM4 entries for flip sync according to the number
 * of CRTCs. 
 */
_inline DWORD GetCRTCSyncEntries(LPATIDXOBJECT lpATIDXObj)
{
  switch ( GetConnectedCRTC(lpATIDXObj) )
  {
    case 1:  return ( 2);
    case 2:  return ( 6);
    case 3:  return ( 8);
    default: return ( 2);
  }
}

/*
 * GetCRTCWriteEntries
 */
_inline DWORD GetCRTCWriteEntries(LPATIDXOBJECT lpATIDXObj)
{
  return  (((GetConnectedCRTC(lpATIDXObj) & 3) == 3)? 4 : 2);
}

/*
 * WaitUntilFlip:
 * This macro inserts the appropriate commands into command
 * stream to instruct the hardware to stall the GUI engine
 * until next refresh(vertical blank) in dual-CRTC configuration
 * Parameters:-
 * DWORD* lpCommandStream, this is were we should insert the commands
 *
*/
__inline void WaitUntilFlip(LPATIDXOBJECT lpATIDXObj, DWORD* lpCommandStream)
{
  DWORD i = 0;

  if ( GetConnectedCRTC(lpATIDXObj) & 1 )
  {
    lpCommandStream[i++] = RegWriteWAIT_UNTIL;
    lpCommandStream[i++] = WAIT_UNTIL__WAIT_CRTC_PFLIP;
  }
  if ( GetConnectedCRTC(lpATIDXObj) & 2 )
  {
    lpCommandStream[i++] = RegWriteWAIT_UNTIL;
    lpCommandStream[i++] = WAIT_UNTIL__ENG_DISPLAY_SELECT;
    lpCommandStream[i++] = RegWriteWAIT_UNTIL;
    lpCommandStream[i++] = WAIT_UNTIL__WAIT_CRTC_PFLIP | WAIT_UNTIL__ENG_DISPLAY_SELECT;
    lpCommandStream[i++] = RegWriteWAIT_UNTIL;
    lpCommandStream[i++] = 0;
  }
}
/**************** PIGLET INLINE MACROS END ****************************/

/*
 * SyncSurface:
 * This macro inserts the appropriate commands(register writes)
 * into the command stream to instruct the hardware to stall the 
 * GUI engine until next refresh(vertical blank).
 * Parameters:-
 * DWORD* lpCommandStream, this is were we should insert the commands
 * LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, this is DirectDraw surface that 
 * requires the CRTC syncronization.
 * 
*/
__inline void SyncSurface(DWORD* lpCommandStream,
                          LPATISURFINFO lpATISurfInfo,
                          LPATIDXOBJECT lpATIDXObj)
{
    WaitUntilFlip(lpATIDXObj, lpCommandStream);

    /*
     * When we submit a opertaion that requires a surface to be timestamped,
     * the TimeStampSurfaces function will walk the TimeStampArray until all the surface's
     * associated with the current operation have been "TIMESTAMP'ED".
    */

    if (lpATISurfInfo)
    {
        lpATIDXObj->TimeStampArray[0] = lpATISurfInfo;
    }
    /*
     * Note when we obtain a timestamp (inside SubmitPM4Entries)
     * for the surface, we will reset the CRTCSyncFlag!.
     * For a description of the SubmitPM4Entries macro,
     * check description inside inline.h
    */
}


/*
Use this macro to program scissors
*/
__inline DWORD MakeSCHghtWdth(LPDDRAWI_DDRAWSURFACE_LCL lpDDSurf_LCL)
{
 return (   ((GetDDSurfHeight(lpDDSurf_LCL)- 1) << 16) |
             (GetDDSurfWidth(lpDDSurf_LCL) - 1)        ); 
}

/*
 * CreateSurfaceBytesPerPixel:
 * This macro returns the bytes per pixel of any given DDRAW surface
 * NOTE: CI4 surface have to handled with care! 
*/
__inline DWORD CreateSurfaceBytesPerPixel(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    DWORD dwBitsPP;
    LPDDPIXELFORMAT lpDDPF;

    //Get Surface has pixel format
    lpDDPF = &lpSLCL->lpGbl->ddpfSurface;

    if(lpDDPF->dwFlags & DDPF_FOURCC)
    {
        switch(lpDDPF->dwFourCC)
        {
        case FOURCC_YUY2:
        case FOURCC_UYVY:
            dwBitsPP = 16;
            break;
        case FOURCC_AYUV:
            dwBitsPP = 32;
            break;

        // The new DX8 surface formats are handled as FOURCC surfaces
        // even though they are not FOURCC surfaces.
        case D3DFMT_V16U16:
        case D3DFMT_Q8W8V8U8:
#if (DIRECT3D_VERSION >= 0x0900)
        case D3DFMT_A8B8G8R8:
        case D3DFMT_X8B8G8R8:
#endif //(DIRECT3D_VERSION)
        case D3DFMT_W11V11U10:
        case D3DFMT_A2W10V10U10:
        case D3DFMT_A2B10G10R10:
            dwBitsPP = 32;
            break;
            
        case FOURCC_DXT1:
        case FOURCC_DXT2:
        case FOURCC_DXT3:
        case FOURCC_DXT4:
        case FOURCC_DXT5:
            dwBitsPP = 8;
            break;

        case FOURCC_YV12:
        case FOURCC_YVU9:
        case FOURCC_IF09:
        case FOURCC_IMC4:
        case FOURCC_VBID:
        default:
            dwBitsPP = 8;
            break;
        }
    }
    
    else
    {
        dwBitsPP = GetDDSurfaceBPP(lpSLCL);
        // When creating a 24bit ZBUFFER that contains no stencil buffer, we
        // must allocate it as if it was 32bit. 
        if((GetDDSurfddsCaps(lpSLCL) & DDSCAPS_ZBUFFER) && (dwBitsPP == 24))
        {
            dwBitsPP = 32;
        }
    }

    return dwBitsPP >> 3;
}

/*
 * CreateAlignedPitch:
 * THis macro returns a pitch that is aligned to a (Alignment) boundary. 
*/
__inline DWORD CreateByteAlignedPitch(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD Alignment)
{
     return (DWORD) (ByteAlign((DWORD_PTR) (GetDDSurfWidth(lpSLCL)*GetSurfaceBytesPerPixel(lpSLCL)), (DWORD_PTR)Alignment));
}

//SHAREDD_TO_DO: Don't need those macros after ddraw for win2k is merged?
//These functions are for code commonality between NT4/5 and Win9x sharing
//r6blt.h [RAB]
/****************************************************************************/

__inline LPATISURFINFO GetATIInfoPtr(LPDDHSLSURFACEDESC lpSurfDesc)
{
    return (LPATISURFINFO)(lpSurfDesc->hATISurfInfoHandle);
}

__inline DWORD GetSurfWidth( LPDDHSLSURFACEDESC lpSurfDesc )
{
    return lpSurfDesc->dwWidth;
}

__inline DWORD GetSurfHeight( LPDDHSLSURFACEDESC lpSurfDesc )
{
    return lpSurfDesc->dwHeight;
}

__inline LONG GetSurfPitch( LPDDHSLSURFACEDESC lpSurfDesc )
{
    return lpSurfDesc->lPitch;
}

__inline DWORD GetSurfCaps( LPDDHSLSURFACEDESC lpSurfDesc )
{
    return lpSurfDesc->dwCaps;
}

__inline FLATPTR GetSurfVidMem( LPDDHSLSURFACEDESC lpSurfDesc )
{
    return lpSurfDesc->fpVidMem;
}

_inline LPDDPIXELFORMAT GetSurfDDPFormat( LPDDHSLSURFACEDESC lpSurfDesc )
{
    return lpSurfDesc->lpddPixelFormat;
}

/*****************************************************************************/

extern void ReInitilizePFVars(LPATIDXOBJECT lpATIDXObj);
#endif




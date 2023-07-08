

//    
//  $Workfile: ddmacros.h $
//  $Revision: 7 $
//
//  Description:
//
//  Last modification: 
//     $Author: Xwu $ 
//     $Date: 7/20/99 12:40p $
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2002, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _DDMACROS_H_
#define _DDMACROS_H_
 
/***************************************************************************
** The following are macros defined for use by DirectDraw HAL and the     **
** 3D HAL.                                                                **
***************************************************************************/ 

#include "atidxinc.h"
#include "fourcc.h"
#include "atidispdd.h"
#include "atidxobj.h"


#define     ATI_MINPITCH                32  //Minimum surf pitch for micro-tiled textures.
#define     ATI_MINMICROTILEPITCH       16  //Minimum surf pitch for non-micro-tiled textures.

#ifdef WIN2K

#include "mmsystem.h"

#define GetGdidDeviceInfo(lpData) pDISP4DDGetDXObj(lpData->dhpdev)

_inline LPATIDXOBJECT D3dGetATIDeviceInfoObject(LPDDRAWI_DIRECTDRAW_GBL lpDDGbl) 
{
    return pDISP4DDGetDXObj(lpDDGbl->dhpdev); 
}

//TO_DO : Caller must access the Display drivers pDev to obtain the PF of the primary.
#define GetDDSurfacePFFlags(lpDDSurfaceLCL) \
              ((LPDDRAWI_DDRAWSURFACE_LCL)lpDDSurfaceLCL)->lpGbl->ddpfSurface.dwFlags
              
//TO_DO : Caller must access the Display drivers pDev to obtain the PF of the primary.
#define GetDDSurfacelpDDPF(lpDDSurfaceLCL) \
              (&(((LPDDRAWI_DDRAWSURFACE_LCL)lpDDSurfaceLCL)->lpGbl->ddpfSurface))
              
__inline LPATIDXOBJECT GetDXObjDDGBL(LPDDRAWI_DIRECTDRAW_GBL lpDDGbl)
{
    return (LPATIDXOBJECT)pDISP4DDGetDXObj(lpDDGbl->dhpdev);
}

__inline LPATIDXOBJECT GetDXObjDDLCL(LPDDRAWI_DDRAWSURFACE_LCL lpDDSurf_LCL)
{
    //TODO: Each Surface will have a DXObj Ptr stored in the ATISURF info.
    return NULL;
}


__inline LPATIDXOBJECT GetDXObjDDHALGDID(LPDDHAL_GETDRIVERINFODATA lpGDID)
{
    return (LPATIDXOBJECT)pDISP4DDGetDXObj(lpGDID->dhpdev);
}

#endif

/***************************************************************************/

__inline DWORD GetDDSurfaceBPP(LPDDRAWI_DDRAWSURFACE_LCL lpDDSurfaceLCL)
{
        if(lpDDSurfaceLCL->lpGbl->ddpfSurface.dwFlags & DDPF_FOURCC) 
        {
            if((lpDDSurfaceLCL->lpGbl->ddpfSurface.dwFourCC & 0x00FFFFFF ) == 'TXD')
            {
                return 8;
            }
            
            else if ( (lpDDSurfaceLCL->lpGbl->ddpfSurface.dwFourCC == FOURCC_YUY2) ||
                      (lpDDSurfaceLCL->lpGbl->ddpfSurface.dwFourCC == FOURCC_UYVY) )
            {  
                return 16;
            }
            // The new DX8 surface formats are handled as FOURCC surfaces
            // even though they are not FOURCC surfaces.
            else if ( (lpDDSurfaceLCL->lpGbl->ddpfSurface.dwFourCC == D3DFMT_V16U16) ||
                      (lpDDSurfaceLCL->lpGbl->ddpfSurface.dwFourCC == D3DFMT_Q8W8V8U8) ||
#if (DIRECT3D_VERSION >= 0x0900)
                      (lpDDSurfaceLCL->lpGbl->ddpfSurface.dwFourCC == D3DFMT_A8B8G8R8) ||
                      (lpDDSurfaceLCL->lpGbl->ddpfSurface.dwFourCC == D3DFMT_X8B8G8R8) ||
                      (lpDDSurfaceLCL->lpGbl->ddpfSurface.dwFourCC == D3DFMT_A2R10G10B10) ||
#endif //(DIRECT3D_VERSION)
                      (lpDDSurfaceLCL->lpGbl->ddpfSurface.dwFourCC == D3DFMT_W11V11U10) ||
                      (lpDDSurfaceLCL->lpGbl->ddpfSurface.dwFourCC == D3DFMT_A2W10V10U10) ||
                      (lpDDSurfaceLCL->lpGbl->ddpfSurface.dwFourCC == D3DFMT_A2B10G10R10) )
            {
                return 32;
            }
        }
        
        return lpDDSurfaceLCL->lpGbl->ddpfSurface.dwRGBBitCount;
}

// DirectDraw Part.

// Get the flags of spec'd DD Surf
#define GetDDSurfdwFlags(lpDDSurfLCL)\
    (((LPDDRAWI_DDRAWSURFACE_LCL)lpDDSurfLCL)->dwFlags)

// get the surface caps of spec'd DD Surf
#define GetDDSurfddsCaps(lpDDSurfLCL)\
    (((LPDDRAWI_DDRAWSURFACE_LCL) lpDDSurfLCL)->ddsCaps.dwCaps)
    
// get the surface caps2 of spec'd DD Surf
#define GetDDSurfddsCaps2(lpDDSurfDesc)\
    (((LPDDSURFACEDESC2) lpDDSurfDesc)->ddsCaps.dwCaps2)

// get the surface capsEx of the spec'd DD Surf
#define GetDDSurfddsCapsEx(lpDDSurfLCL)\
    (((LPDDRAWI_DDRAWSURFACE_LCL) lpDDSurfLCL)->lpSurfMore->ddsCapsEx)

// Get the wHeight of spec'd DD Surf.
#define GetDDSurfHeight(lpDDSurfLCL)\
    (((LPDDRAWI_DDRAWSURFACE_LCL)lpDDSurfLCL)->lpGbl->wHeight)

// Get the wWidth of spec'd DD Surf.
#define GetDDSurfWidth(lpDDSurfLCL)\
    (((LPDDRAWI_DDRAWSURFACE_LCL)lpDDSurfLCL)->lpGbl->wWidth)

// Get the volume depth of spec'd DD Surf.
#define GetDDSurfVolDepth(lpDDSurfLCL)\
    (LOWORD(((LPDDRAWI_DDRAWSURFACE_LCL)lpDDSurfLCL)->lpSurfMore->ddsCapsEx.dwVolumeDepth))

// Get the fpVidMem of spec'd DD Surf.
#define GetDDSurffpVidMem(lpDDSurfLCL)\
    (((LPDDRAWI_DDRAWSURFACE_LCL)lpDDSurfLCL)->lpGbl->fpVidMem)

//Get surface that "attached" itself to this one
#define GetDDSurfAttachedSurfLCL2(lpDDSurfLCL)  \
    (((LPDDRAWI_DDRAWSURFACE_LCL)lpDDSurfLCL)->lpAttachListFrom->lpAttached)

// Get next attached list
#define GetD3DAttachListNextList(lpNextList) \
    (((LPATTACHLIST)lpNextList)->lpLink)

//Get Source colourkey from the BltData structure
#define GetDDSurfSRCColourKey(lpBltData)\
     (((LPDDHAL_BLTDATA)lpBltData)->bltFX.ddckSrcColorkey.dwColorSpaceLowValue) 

//Get Destination colourkey from the BltData structure
#define GetDDSurfDESTColourKey(lpBltData)\
     (((LPDDHAL_BLTDATA)lpBltData)->bltFX.ddckDestColorkey.dwColorSpaceLowValue) 

//return the Zbuffer Bit Depth
#define GetDDSurfZBitDepth(lpDDSurfLCL) \
        (((LPDDRAWI_DDRAWSURFACE_LCL)lpDDSurfLCL)->lpGbl->ddpfSurface.dwZBufferBitDepth)

//return the Stencil Bit Depth
#define GetDDSurfStencilBitDepth(lpDDSurfLCL) \
       ( ((LPDDRAWI_DDRAWSURFACE_LCL)lpDDSurfLCL)->lpGbl->ddpfSurface.dwStencilBitDepth)

//returns the ZBuffer bit mask        
#define GetDDSurfZBitMask(lpDDSurfLCL) \
        ( ((LPDDRAWI_DDRAWSURFACE_LCL)lpDDSurfLCL)->lpGbl->ddpfSurface.dwRGBZBitMask)

// Get mipmap count
#define GetDDSurfMipMapCount(lpDDSurfLCL)\
    (((LPDDRAWI_DDRAWSURFACE_LCL)lpDDSurfLCL)->lpSurfMore->dwMipMapCount)

// Get Attached surfaces which is LPDDRAWI_DDRAWSURFACE_LCL
#define GetDDSurfAttachedSurfLCL(lpDDSurfLCL) \
     (((LPDDRAWI_DDRAWSURFACE_LCL)lpDDSurfLCL)->lpAttachList->lpAttached)

// Get the fourCC code of the spec'd DD Surf.
_inline DWORD GetFourCCCode(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
  return (lpSLCL->lpGbl->ddpfSurface.dwFourCC);
}

// Determine if the surface is a FOURCC_DXTn compressed texture
BOOL __inline IsDxtTexture(LPDDPIXELFORMAT lpddPixelFormat)
{
    return (lpddPixelFormat != NULL && 
           (lpddPixelFormat->dwFlags & DDPF_FOURCC) && 
           ((lpddPixelFormat->dwFourCC & 0x00FFFFFF) == 'TXD'));
}

//Functions to compute block width, height and linear size of DXTn textures.

__inline DWORD CalcDXTByteWidth(DWORD dwWidth, DWORD dwFourCC)
{
    if( dwFourCC == FOURCC_DXT1 )
        return ( ( ( dwWidth + 3 ) >> 2 ) << 3 );
    return ( ( ( dwWidth + 3 ) >> 2 ) << 4 );
}

__inline DWORD CalcDXTBlockHeight(DWORD dwHeight)
{
   return ( ( dwHeight + 3 ) >> 2 );
}

__inline DWORD CalcDXTLinearSize(DWORD dwWidth, DWORD dwHeight, DWORD dwFourCC)
{
    if( dwFourCC == FOURCC_DXT1 )
        return ( ( dwWidth + 3 ) >> 2 ) * ( ( dwHeight + 3 ) >> 2 ) * 8;
    return ( ( dwWidth + 3 ) >> 2 ) * ( ( dwHeight + 3 ) >> 2 ) * 16;
}

__inline DWORD GetDXTBlockSize(DWORD dwFourCC)
{
    if(dwFourCC == FOURCC_DXT1)    
        return 8;
    return 16;
}

//Function to compute block pitch of DXTn textures.
__inline DWORD CalcDXTBlockPitch( DWORD dwWidth, DWORD dwFourCC, BOOL MicroTiled )
{
    if( !MicroTiled )
        return ( CalcDXTByteWidth(dwWidth, dwFourCC) + (ATI_MINPITCH - 1) ) 
               & ~(ATI_MINPITCH - 1);
    return ( CalcDXTByteWidth(dwWidth, dwFourCC) + (ATI_MINMICROTILEPITCH - 1) ) 
           & ~( ATI_MINMICROTILEPITCH - 1 );
}

// Determine if the surface is a bumpmap texture
BOOL __inline IsBumpMapTexture(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    return (GetDDSurfacePFFlags(lpSLCL) & DDPF_BUMPDUDV);
}

// Determine if the surface is a volume texture
BOOL __inline IsVolumeTexture(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    DDSCAPSEX sCapsEx = GetDDSurfddsCapsEx(lpSLCL);
    return(sCapsEx.dwCaps2 & DDSCAPS2_VOLUME);
}

#if (DIRECT3D_VERSION >= 0x0900)

// Determine if the surface is a lightweightmipmap  texture
BOOL __inline IsLightWeightMipMap(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    DDSCAPSEX sCapsEx = GetDDSurfddsCapsEx(lpSLCL);
    return(sCapsEx.dwCaps3 & DDSCAPS3_LIGHTWEIGHTMIPMAP);
}

// Determine if the surface is a auto gen mipmap  texture
BOOL __inline IsAutoGenMipMap(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    DDSCAPSEX sCapsEx = GetDDSurfddsCapsEx(lpSLCL);
    return(sCapsEx.dwCaps3 & DDSCAPS3_AUTOGENMIPMAP);
}

#endif //(DIRECT3D_VERSION >= 0x0900)

__inline DWORD GetDDSurfMSType(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    return lpSLCL->lpSurfMore->ddsCapsEx.dwCaps3;
}

BOOL __inline IsZBSurface(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    return ((GetDDSurfddsCaps(lpSLCL) & DDSCAPS_ZBUFFER));
}

BOOL __inline IsDVDSurface(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    if((GetDDSurfacePFFlags(lpSLCL) & DDPF_FOURCC))
    {
        switch(GetFourCCCode(lpSLCL))
        {
            case FOURCC_MCR4:
            case FOURCC_MCAM:
            case FOURCC_MC12:
            case FOURCC_M2AM:
            case FOURCC_M2IA:
                return TRUE;
            
            default:            
                return FALSE;                                   
        }
    }

    return FALSE;
}

// Get the pitch of the spec'd DD Surf.
__inline DWORD GetDDSurfacePitch(LPDDRAWI_DDRAWSURFACE_LCL lpDDSurfLCL)
{
   return lpDDSurfLCL->lpGbl->lPitch;
}

// Get the slice pitch of the spec'd DD Surf.
__inline DWORD GetDDSurfaceSlicePitch( LPDDRAWI_DDRAWSURFACE_LCL lpDDSurfLCL)
{


    if (IsVolumeTexture(lpDDSurfLCL))
    {
        if (lpDDSurfLCL->lpGbl->lSlicePitch != 0)
        {
            return lpDDSurfLCL->lpGbl->lSlicePitch;
        }
        return GetDDSurfHeight(lpDDSurfLCL) * GetDDSurfacePitch(lpDDSurfLCL);
    }



    return 0; // for non-volume texture.
}

/*
 * SetSurfacePitch stores a pitch value into the surface gbl->lpitch
 * field
 */
VOID __inline SetSurfacePitch(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD lPitch)
{
 lpSLCL->lpGbl->lPitch=lPitch;
}



/*
 * SetSurfaceSlicePitch stores a slice pitch value into the surface gbl->lSlicePitch
 * field, for non volume texture, it's always 0
 */
VOID __inline SetSurfaceSlicePitch(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD dwSlicePitch)
{
  lpSLCL->lpGbl->lSlicePitch = dwSlicePitch;
}


/*
 * SetSurfaceVidMem stores a video memory ptr into the surface gbl->fpVidMem
 * field
 */
VOID __inline  SetSLCLfpVidMem (LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, FLATPTR fpVidMem)
{
  lpSLCL->lpGbl->fpVidMem=fpVidMem;
}

/*
 * SetSLCLLocalVidMem set's the surface (DDSCAPS_LOCALVIDMEM) flag
 */
VOID __inline SetSLCLLocalVidMemFlag (LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{

  lpSLCL->ddsCaps.dwCaps &= (~DDSCAPS_NONLOCALVIDMEM);
  lpSLCL->ddsCaps.dwCaps |= DDSCAPS_LOCALVIDMEM;
  
}

/*
 * SetSLCLNonLocalVidMem set's the surface (DDSCAPS_LOCALVIDMEM) flag
 */
VOID __inline SetSLCLNonLocalVidMemFlag (LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{

  lpSLCL->ddsCaps.dwCaps &= (~DDSCAPS_LOCALVIDMEM);
  lpSLCL->ddsCaps.dwCaps |= DDSCAPS_NONLOCALVIDMEM;
  
}

_inline LPVOID GetHSLSurfInfoHandle( LPDDRAWI_DDRAWSURFACE_LCL lpSLCL )
{
    return ( lpSLCL ) ? (LPVOID)lpSLCL->dwReserved1 : NULL;
}

_inline LPVOID GetATISurfInfoHandle( LPDDRAWI_DDRAWSURFACE_LCL lpSLCL )
{
    return ( lpSLCL ) ? (LPVOID)lpSLCL->lpGbl->dwReserved1 : NULL;
}



////////////////////////////////////////////////////////
// used by overlay only begin
////////////////////////////////////////////////////////
/*
 * GetVideoPortInfo:
 * This macro returns the ptr of the strucuture that describes the VIDEOPORT 
 * that is attached to the surface.
 */
__inline LPDDRAWI_DDVIDEOPORT_LCL GetVideoPortInfo(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
 return (lpSLCL->lpSurfMore->lpVideoPort);
}
/*
 * GetVideoPortId:
 * This macro returns the VideoPort ID (shifted left by 8, because that's what bits it
 * occupies inside the mmOV0_AUTO_FLIP_CNTRL reg) that is currently attached
 * to the surface identified by lpSLCL 
*/
__inline DWORD GetVideoPortID(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
  return (DWORD) ((((LPDDRAWI_DDVIDEOPORT_LCL) GetVideoPortInfo(lpSLCL))->ddvpDesc.dwVideoPortID) << 8 );
}



// Get the surface pixel format
#define GetDDSurfddpfSurface(lpDDSurfLCL)\
    (((LPDDRAWI_DDRAWSURFACE_LCL) lpDDSurfLCL)->lpGbl->ddpfSurface)

// Get Attached surfaces which is LPDDRAWI_DDRAWSURFACE_LCL
#define GetDDSurfAttachedSurfLCL(lpDDSurfLCL) \
     (((LPDDRAWI_DDRAWSURFACE_LCL)lpDDSurfLCL)->lpAttachList->lpAttached)

//Determine how many surfaces are attached to the identified surface
#define GetDDSurfBackBufferCount(lpDDSurfLCL)\
            (((LPDDRAWI_DDRAWSURFACE_LCL)lpDDSurfLCL)->dwBackBufferCount)

////////////////////////////////////////////////////////
// used by overlay only end
////////////////////////////////////////////////////////
#endif /* _DDMACROS_H_ */


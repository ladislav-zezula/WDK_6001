#ifndef _ATISURFINFO_H
#define _ATISURFINFO_H


#include <DriverSpecs.h>

__user_code                                                     


// external includes 

#include "fourcc.h"
#include "atidxinc.h"
#include "radeon.h"
#include "ddmacros.h"
#include "qs.h"
#include "atidxhsl.h"


#ifdef WIN2K
#include "mmsystem.h"
#endif

//private D3D includes

#include "d3ddevice.h"

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


/*
 * HSLSurfInfo contains just the direct draw local associated with this
 * D3D surface structure.
 *
 * !! NOTE: This structure no longer matches LPATIVERTEXBUFFER and therefore
 *          no longer shares any macros with it.
 *
*/
typedef     struct     HSLSurfInfo
{
    DWORD      dwSize;
    
    DWORD      dwWhichBlock;            // Which block is this surface resides.
    LPDDRAWI_DIRECTDRAW_LCL lpDDLcl;    //Ptr to DDrawLcl object. It's set in CreateSurfaceEx32.

}HSLSURFINFO, *LPHSLSURFINFO;

/****************************************************************************/
//** Valid values for the dwFlags field of the HSLSURFINFO structure.
///****************************************************************************/

// The following flags are only used in the case of vertex buffers
#define     IS_BUFFER_CHAIN_HEAD  0x00000001
#define     IS_BUFFER_CHAIN_TAIL  0x00000002
#define     HAS_ATTACHED_BUFFER   0x00000004

/*
 * GetHSLSurfInfoPtr:
 * This macro returns the LPATISURFINFO ptr (if there is one). 
 */
_inline LPHSLSURFINFO GetHSLSurfInfoPtr(LPDDRAWI_DDRAWSURFACE_LCL lpDDSurf)
{
    return( (LPHSLSURFINFO)(lpDDSurf->dwReserved1) );
}

VOID __inline SetHSLSurfInfoPtr(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, LPHSLSURFINFO pD3DSurfInfo)
{
    lpSLCL->dwReserved1 = (DWORD_PTR)pD3DSurfInfo;
}

/*
 * MakeHSLSurfOffPitch:
 * This macro is used to create a surfaces offset/pitch
 * combination to be used by the Rage 5 or R128 hardware.
*/
_inline DWORD MakeHSLSurfOffPitch(LPATISURFCNTX lpATISurfContext)  
{
    ULONG_PTR dwOffset = *lpATISurfContext->pdwSurfByteOffset >> 10;


    DWORD dwBytePitch = (lpATISurfContext->dwSurfPitchIn8Pixels << 3) * 
                        lpATISurfContext->dwBytesPerPixel;

    DWORD dwPitch = dwBytePitch >> 6;
    DWORD dwSurfOffPitch;

    LPDWORD pdwDsSurfFlags = 
              pDdHslQueryATISurfInfo3( GetSurfCntxATISurfInfoHandle(lpATISurfContext),
                                      E_SURF_FLAGS );

    BOOL    bMacroTiled = (*pdwDsSurfFlags) & HSL_SURF_IS_TILED;
    BOOL    bMicroTiled = (*pdwDsSurfFlags) & HSL_SURF_IS_MICROTILED;
    DWORD   dwTile = (bMacroTiled ? 1:0) | (bMicroTiled ? 2:0);

    dwSurfOffPitch = (DWORD)(
        ((dwPitch << DST_PITCH_OFFSET__DST_PITCH__SHIFT) & DST_PITCH_OFFSET__DST_PITCH_MASK) |         
        ((dwOffset << DST_PITCH_OFFSET__DST_OFFSET__SHIFT) & DST_PITCH_OFFSET__DST_OFFSET_MASK) | 
        ((dwTile << DST_PITCH_OFFSET__DST_TILE__SHIFT) & DST_PITCH_OFFSET__DST_TILE_MASK)
        );
    
    return dwSurfOffPitch;
}


_inline DWORD MakeHSLAASurfOffPitch(LPATISURFCNTX lpATISurfContext, 
                                    LPANTIALIASINFO lpAAInfo)
{
    DWORD dwOffset = (DWORD) lpAAInfo->dwRTSurfOffset >> 10;
    DWORD dwPitch = lpAAInfo->dwBytePitch >> 6;
    DWORD dwSurfOffPitch;

    LPDWORD pdwDsSurfFlags = 
              pDdHslQueryATISurfInfo3( GetSurfCntxATISurfInfoHandle(lpATISurfContext),
                                      E_SURF_FLAGS );

    BOOL    bMacroTiled = (*pdwDsSurfFlags) & HSL_SURF_IS_TILED;
    BOOL    bMicroTiled = (*pdwDsSurfFlags) & HSL_SURF_IS_MICROTILED;
    DWORD   dwTile = (bMacroTiled ? 1:0) | (bMicroTiled ? 2:0);

    dwSurfOffPitch = (DWORD)
        ((dwPitch << DST_PITCH_OFFSET__DST_PITCH__SHIFT) & DST_PITCH_OFFSET__DST_PITCH_MASK) |         
        ((dwOffset << DST_PITCH_OFFSET__DST_OFFSET__SHIFT) & DST_PITCH_OFFSET__DST_OFFSET_MASK) | 
        ((dwTile << DST_PITCH_OFFSET__DST_TILE__SHIFT) & DST_PITCH_OFFSET__DST_TILE_MASK);
    
    return (dwSurfOffPitch);
}

_inline DWORD MakeHSLAAZBSurfOffPitch(LPATISURFCNTX lpATISurfContext, 
                                    LPANTIALIASINFO lpAAInfo)
{
    DWORD dwOffset = (DWORD) lpAAInfo->dwZBSurfOffset >> 10;
    DWORD dwPitch = lpAAInfo->dwZBytePitch >> 6;
    DWORD dwSurfOffPitch;

    dwSurfOffPitch = (DWORD)
        ((dwPitch << DST_PITCH_OFFSET__DST_PITCH__SHIFT) & DST_PITCH_OFFSET__DST_PITCH_MASK) |         
        ((dwOffset << DST_PITCH_OFFSET__DST_OFFSET__SHIFT) & DST_PITCH_OFFSET__DST_OFFSET_MASK);
    
    return (dwSurfOffPitch);
}



__inline DWORD ConvertBPPtoR6HW_New(LPATISURFCNTX lpSurfContext)
{
    LPDDPIXELFORMAT lpDDpf= GetSurfCntxlpDDPF(lpSurfContext);

    switch (lpDDpf->dwRGBBitCount)
    {
        case 8:
            return 0x07;  // RGB332. No pseudocolor

        case 16:
            if (lpDDpf->dwFlags & DDPF_ALPHAPIXELS) 
            {
                if (lpDDpf->dwRBitMask == 0x7c00)
                {
                    return 0x03;      // 1555
                }
                else
                {
                    return 0xf;      // 4444
                }
            }
            else
            {
                if (lpDDpf->dwGBitMask == 0x3e0)
                    return 0x03;      // 555
                else
                    return 0x4;       // 565
            }

        case 24:
            return 0x06; // no 24 bit color support

        case 32:
            return 0x06;

        default:
            return 0x07;
    }
}


__inline DWORD ConvertBPPtoR6HW(LPDDRAWI_DDRAWSURFACE_LCL lpDDSurf_LCL)
{

 LPDDPIXELFORMAT lpDDpf= GetDDSurfacelpDDPF(lpDDSurf_LCL);

 switch (lpDDpf->dwRGBBitCount)
        {
         case 8:
               return 0x07;  // RGB332. No pseudocolor 
         case 16:
               if (lpDDpf->dwFlags & DDPF_ALPHAPIXELS) 
               {
                 if (lpDDpf->dwRBitMask == 0x7c00)
						 return 0x03;      // 1555
				      else
					     return 0xf;      // 4444
               }
               else
                 return 0x4;              // 565
         case 24:
               return 0x06; // no 24 bit color support
         case 32:
               return 0x06;
         default:
               return 0x07;
        }
}

// This macro converts the Pixel Width of the surface to the
// HW format used by the DP_GUI_MASTER_CNTL register.

__inline DWORD GetATiSurfPixWidth(LPDDPIXELFORMAT lpDDPF)
{
    if (lpDDPF->dwFlags & DDPF_FOURCC)
    {
        switch (lpDDPF->dwFourCC)
        {
            case FOURCC_DXT1:
            case FOURCC_DXT2:
            case FOURCC_DXT3:
            case FOURCC_DXT4:
            case FOURCC_DXT5: 
                return DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__8BPP_CLUT;

            case FOURCC_YUY2:
            case FOURCC_UYVY:
                return DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__16BPP_1555;

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
                return DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__32BPP_8888;
#if (DIRECT3D_VERSION >= 0x0900)
            case D3DFMT_A2R10G10B10:
                return DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__32BPP_2101010;
#endif //(DIRECT3D_VERSION)
        }
    }
    
    switch (lpDDPF->dwRGBBitCount)
    {
        case 8:
            return DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__8BPP_CLUT;   

        case 16:
            if (lpDDPF->dwRBitMask == 0xF800)
                return DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__16BPP_565;
            else
                return DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__16BPP_1555;
    
        case 32:
            return DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__32BPP_8888;
    
        default: return 0;   
    }
}


__inline DWORD GetATiSurfTexelFormat(LPDDPIXELFORMAT lpDDPF)
{
    if (lpDDPF->dwFlags & DDPF_BUMPDUDV)    //It's a bump map
    {
        //Rage 6 supports 8U8V, 5U5V6L, and 8U8V8L bump formats

        switch (lpDDPF->dwBumpBitCount)
        {
        case 16:

            if (lpDDPF->dwBumpDuBitMask == 0xff)
              return (PP_TXFORMAT_0__TXFORMAT__8U8V_BUMP_MAP);
            else if (lpDDPF->dwBumpDuBitMask == 0x1f)
              return(PP_TXFORMAT_0__TXFORMAT__5U5V6L_BUMP_MAP);
            else
              return(0);

        case 24:
        case 32:
            if (lpDDPF->dwBumpDuBitMask == 0xff)
              return (PP_TXFORMAT_0__TXFORMAT__8U8V8L_BUMP_MAP);
            else
              return(0);

        default:
            return(0);
        }
    }
    else if ( lpDDPF->dwFlags & DDPF_LUMINANCE )
    {
        if ( lpDDPF->dwLuminanceBitMask == 0xff )
        {
            if ( lpDDPF->dwFlags & DDPF_ALPHAPIXELS )
            {
                return PP_TXFORMAT_0__TXFORMAT__16BPP_AL;
            }
            else
            {
                return PP_TXFORMAT_0__TXFORMAT__8BPP_L;
            }
        }
        return 0;
    }
	else if (lpDDPF->dwFlags & DDPF_ALPHA)
	{
		if (lpDDPF->dwRGBBitCount == 8)
		{
			return PP_TXFORMAT_0__TXFORMAT__8BPP_L;
		}
		return 0;
	}
    else if( lpDDPF->dwFlags & DDPF_FOURCC ) 
    {
        switch( lpDDPF->dwFourCC )
        {
            case FOURCC_DXT1:
                return PP_TXFORMAT_0__TXFORMAT__CCC_DXT1;
            case FOURCC_DXT2:
                return PP_TXFORMAT_0__TXFORMAT__CCC_DXT2;
            case FOURCC_DXT3:
                return PP_TXFORMAT_0__TXFORMAT__CCC_DXT3;
            case FOURCC_DXT4:
                return PP_TXFORMAT_0__TXFORMAT__CCC_DXT4;
            case FOURCC_DXT5:
                return PP_TXFORMAT_0__TXFORMAT__CCC_DXT5;
            case FOURCC_YUY2:
                return PP_TXFORMAT_0__TXFORMAT__YUV_422_VYUY;  //VYUY
            case FOURCC_UYVY:
                return PP_TXFORMAT_0__TXFORMAT__YUV_422_YVYU;  //YVYU
            // The new DX8 surface formats are handled as FOURCC surfaces
            // even though they are not FOURCC surfaces.
            case D3DFMT_V16U16:
                return PP_TXFORMAT_0__TXFORMAT__V16U16_SIGNED;
            case D3DFMT_Q8W8V8U8:
                return PP_TXFORMAT_0__TXFORMAT__Q8W8V8U8_SIGNED;
#if (DIRECT3D_VERSION >= 0x0900)
            case D3DFMT_A8B8G8R8:
                return PP_TXFORMAT_0__TXFORMAT__A8B8G8R8;
            case D3DFMT_X8B8G8R8:
                return PP_TXFORMAT_0__TXFORMAT__X8B8G8R8;
#endif //(DIRECT3D_VERSION)
            case D3DFMT_W11V11U10:
                return PP_TXFORMAT_0__TXFORMAT__W11V11U10_SIGNED;
            case D3DFMT_A2W10V10U10:
                return PP_TXFORMAT_0__TXFORMAT__A2W10V10U10_SIGNED;
            case D3DFMT_A2B10G10R10:
                return PP_TXFORMAT_0__TXFORMAT__A2B10G10R10;
            default:    return 0;
        }
    }    
    
    else
    {
        //Must be RGB
        switch (lpDDPF->dwRGBBitCount)
        {
        case 8:
            if (lpDDPF->dwFlags & DDPF_PALETTEINDEXED8)
               return 0;
            else if(lpDDPF->dwRBitMask == 0xE0)
               return PP_TXFORMAT_0__TXFORMAT__8BPP_RGB;    //RGB332   
            else
               return 0;

        case 16:
            if (lpDDPF->dwRBitMask == 0xF800)
               return PP_TXFORMAT_0__TXFORMAT__16BPP_RGB;    //RGB565
            else if ((lpDDPF->dwRBitMask == 0x7C00)/*&&(lpDDPF->dwRGBAlphaBitMask==0x8000)*/)   
               return PP_TXFORMAT_0__TXFORMAT__16BPP_ARGB_1555;    //aRGB1555
            else if (lpDDPF->dwRBitMask == 0xF00)
               return PP_TXFORMAT_0__TXFORMAT__16BPP_ARGB_4444;    //aRGB4444    
            else 
               return 0;

        case 32:
            if(lpDDPF->dwRBitMask == 0xFF0000)
                return PP_TXFORMAT_0__TXFORMAT__32BPP_ARGB;       //aRGB8888
            else if(lpDDPF->dwRBitMask == 0xFF000000)
                return PP_TXFORMAT_0__TXFORMAT__32BPP_RGBA;       //RGBa8888
            else 
                return 0;

            default:
                return 0;   
        }
    }
}

__inline DWORD GetATiSurfColorFormat(LPDDPIXELFORMAT lpDDPF)
{
    //Must be RGB
    
    if (lpDDPF->dwFlags & DDPF_FOURCC)
    {
        switch (lpDDPF->dwFourCC)
        {
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
                return RB3D_CNTL__COLORFORMAT__ARGB8888;

            case FOURCC_YUY2:
                return RB3D_CNTL__COLORFORMAT__YUV422_VYUY; 

            case FOURCC_UYVY:
                return RB3D_CNTL__COLORFORMAT__YUV422_YVYU; 

            case FOURCC_DXT1:
            case FOURCC_DXT2:
            case FOURCC_DXT3:
            case FOURCC_DXT4:
            case FOURCC_DXT5:
                return RB3D_CNTL__COLORFORMAT__RGB332;
        }
    }

    switch (lpDDPF->dwRGBBitCount)
    {
         case 8:
            if (lpDDPF->dwFlags & DDPF_PALETTEINDEXED8)
               return 0;
            else
               return RB3D_CNTL__COLORFORMAT__RGB332;
    
         case 16:
            if (lpDDPF->dwRBitMask == 0xF800)
               return RB3D_CNTL__COLORFORMAT__RGB565;
            else if (lpDDPF->dwRBitMask == 0x0F00)
               return RB3D_CNTL__COLORFORMAT__ARGB4444;
            else
               return RB3D_CNTL__COLORFORMAT__ARGB1555;
    
         case 32:
           return RB3D_CNTL__COLORFORMAT__ARGB8888;
    
        default:
           return 0;
    }
}

__inline DWORD CalLog2( DWORD dwValue)
{
	DWORD dwLogValue=0;

	while (dwValue>1)
	{
        dwLogValue++;
		dwValue>>=1;
	}
	return dwLogValue;
}

typedef enum _E_FLUSHFREE {
    FLUSH_ONLY     = 1,
    FREE_ONLY      = 2,
    FLUSH_AND_FREE = 3
} E_FLUSHFREE;

void FlushFreeZCache( LPATID3DCNTX  pContext, E_FLUSHFREE eFlags );
void FlushFreeDstCache( LPATID3DCNTX  pContext, E_FLUSHFREE eFlags );

#endif // _ATISURFINFO_H


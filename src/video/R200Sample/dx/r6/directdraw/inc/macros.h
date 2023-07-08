

//    
//  $Workfile: macros.h $
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

 
/*******************************************************************
 *
 * DESCRIPTION:
 * macros.h is a include file that includes all the standard DDRAW/D3D
 * macros as well as some ATi psecific macros.
 *
 * (c) 1998 ATI Technologies Inc.  (unpublished)
 *
 * All rights reserved.
 * The year included in the foregoing notice is the year of creation of the work.
 *
 
 *******************************************************************/


#ifndef _MACROS_H

#define _MACROS_H

#include "atidxinc.h"

#include "fourcc.h"
#include "rage.h"
#include "cwddeci.h" //HDWRINFo and DXINFO  structures
#include "atidxobj.h" //Contains the data used for multi-monitor
#include "atiddes.h"
#include "ddmacros.h"

#include "features.h"
//#include "r5enm.h"

#define HghtMask    0x0000FFFF   
#define WdthMask    0xFFFF0000

#define MIN(a, b)    ( ((a) < (b)) ? (a) : (b) )


/*
 * Convert palette entry from 24 BPP to 15/16/32 BPP
 */

DWORD __inline ConvertPaletteEntry(LPPALETTEENTRY lpPaletteEntry, DWORD dwDstPixWidth)
{
    switch(dwDstPixWidth)
    {
    case DP_15BPP: return (((DWORD)lpPaletteEntry->peRed << 7) & 0x7C00) |
                          (((DWORD)lpPaletteEntry->peGreen << 2) & 0x03E0) |
                          (((DWORD)lpPaletteEntry->peBlue >> 3));

    case DP_16BPP: return (((DWORD)lpPaletteEntry->peRed << 8) & 0xF800) |
                          (((DWORD)lpPaletteEntry->peGreen << 3) & 0x07E0) |
                          (((DWORD)lpPaletteEntry->peBlue >> 3));

    //case DP_32BPP:
    default:       return ((DWORD)lpPaletteEntry->peRed << 16) |
                          ((DWORD)lpPaletteEntry->peGreen << 8) |
                          ((DWORD)lpPaletteEntry->peBlue);
    }
}


/*
 * Convert color from 15 BPP to 24 BPP
 */
DWORD __inline  ConvertColor_15to24(DWORD dwColor)
{
	 DWORD dwTemp;
	 DWORD dwR;
	 DWORD dwG;
	 DWORD dwB;

     dwR = (dwColor&0x7C00) >> 7;
	 dwG = (dwColor&0x03E0) >> 2;
	 dwB = (dwColor&0x1F)   << 3;
	 dwTemp = (dwR << 16) |	(dwG << 8) | dwB ;
	 return dwTemp;
}

/*
 * Convert color from 16 BPP to 24 BPP
 */
DWORD __inline  ConvertColor_16to24(DWORD dwColor)
{
	 DWORD dwTemp;
	 DWORD dwR;
	 DWORD dwG;
	 DWORD dwB;

     dwR = (dwColor&0xF800) >> 8;
	 dwG = (dwColor&0x07E0) >> 3;
	 dwB = (dwColor&0x1F)   << 3;
	 dwTemp = (dwR << 16) |	(dwG << 8) | dwB ;
	 return dwTemp;
}


__inline DWORD MakeSCBottomRight(RECTL rBltRect)
{
 return ( (((rBltRect.bottom)  - (rBltRect.top)) << 16) |
       ((rBltRect.right)  - (rBltRect.left)) ); 
}

/*
 * MakeSCExtents:
 * This macro takes a LPRECT and a BLT extents
 * and add's them together.
 * NOTE: This basically used by BLT32 to ensure
 * we handle YUV12 BLT's (we have to extend
 * the width and height).
*/
__inline DWORD MakeSCExtents( LPRECTL lpRect, DWORD dwBltHghtWdth)
{
  return ( ((lpRect->left) + ((dwBltHghtWdth) >> 16))  |
           (((lpRect->top) + (dwBltHghtWdth) & 0xffff) << 16)  );            
}

/*
 * MakeSCExtents24:
 * This macro takes a LPRECT and a BLT extents
 * and add's them together.
 * NOTE: This basically used by BLT32 to ensure
 * we handle YUV12 BLT's (we have to extend
 * the width and height).
*/
__inline DWORD MakeSCExtents24( LPRECTL lpRect, DWORD dwBltHghtWdth)
{
  return ( (((lpRect->left) + ((dwBltHghtWdth) >> 16)) * 3)  |
           ((((lpRect->top) + (dwBltHghtWdth) & 0xffff) * 3) << 16)  );            
}

__inline DWORD MakeSCScissor(RECTL rBltRect)
{
 return (  (rBltRect.right)  | ((rBltRect.bottom) << 16) );
}

//This macro returns a LOG2 pitch that is pitch^2. 
//NOTE: For non square textures this the value provided
//can be either width or height (whichever is greater).
__inline DWORD MakeLOG2Pitch(DWORD dwValue)
{
 DWORD  dwLOG2Shift=0;

 while  (!(dwValue & 1))
 {
  dwLOG2Shift++;
  dwValue >>= 1;
 }
 return dwLOG2Shift;
 
}


// This macro converts the Pixel Width of the surface to the
// HW format used by the SCALE_3D_CNTL register.
__inline DWORD GetATiOvlyPixFormat(LPDDPIXELFORMAT lpDDPF)
{
    if (lpDDPF->dwFlags & DDPF_FOURCC)
    {
        switch (lpDDPF->dwFourCC)
        {
        case FOURCC_YUY2:
            return 0xB00; //UYVY

        case FOURCC_UYVY:
            return 0xC00;  //YUYV

        case FOURCC_YV12:
        case FOURCC_MCAM:
        case FOURCC_MC12:
        case FOURCC_MCR4:
        case FOURCC_M2AM:
		case FOURCC_IYUV:
		case FOURCC_IMC4:
            return 0xA00; //YUV12 MCAM

        case FOURCC_YVU9:
        case FOURCC_IF09:
            return 0x900; // YUV9

        //case FOURCC_VBID:
        default:
            return 0;
        }
    }
    else
    {
        //Must be RGB
        switch (lpDDPF->dwRGBBitCount)
        {
        case 16:
            if (lpDDPF->dwRBitMask == 0xF800)
                return 0x400;
            else if (lpDDPF->dwRBitMask == 0x0F00)   
                return 0xF00; //aRGB4444
            else
                return 0x300;  //aRGB1555    
        
         case 32:
            return 0x600;
        
        default:
            return 0;   
        }
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
            case FOURCC_YVU9:
            case FOURCC_YV12:
            case FOURCC_MCAM:
            case FOURCC_MC12:
            case FOURCC_MCR4:
            case FOURCC_M2AM:
            case FOURCC_DXT1:
            case FOURCC_DXT2:
            case FOURCC_DXT3:
            case FOURCC_DXT4:
            case FOURCC_DXT5: 
		    case FOURCC_IYUV: // this case should not happen
		    case FOURCC_IMC4: // this case should not happen
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

            default:
                return 0;
        }
    }
    else if (lpDDPF->dwFlags & DDPF_BUMPDUDV)    //It's a bump map
    {
        switch (lpDDPF->dwBumpBitCount)
        {
            case 16:
                return DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__16BPP_565;
        
            case 24:
            case 32:
                return DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__32BPP_8888;
        
            default:
                return 0;
        }
    }
    else if ( lpDDPF->dwFlags & DDPF_LUMINANCE )
    {
        if ( lpDDPF->dwLuminanceBitMask == 0xFF )
        {
            if ( lpDDPF->dwFlags & DDPF_ALPHAPIXELS )
            {
                return DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__16BPP_1555;
            }
            else
            {
                return DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__8BPP_CLUT;
            }
        }
        return 0;
    }
	else if (lpDDPF->dwFlags & DDPF_ALPHA)
	{
		if (lpDDPF->dwRGBBitCount == 8)
		{
			return DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__8BPP_CLUT;
		}
		return 0;
	}
    else
    {
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
        
            default:
                return 0;   
        }
    }
}


__inline DWORD GetATiSurfTexelFormat(LPDDPIXELFORMAT lpDDPF)
{
    if (lpDDPF->dwFlags & DDPF_FOURCC)
    {
	    switch (lpDDPF->dwFourCC)
	    {
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

	        case FOURCC_YUY2:
		        return PP_TXFORMAT_0__TXFORMAT__YUV_422_VYUY;  //VYUY

	        case FOURCC_UYVY:
		        return PP_TXFORMAT_0__TXFORMAT__YUV_422_YVYU;  //YVYU

	        case FOURCC_YV12:
                return 0xFFFFFFFE;

	        case FOURCC_YVU9:
                return 0xFFFFFFFD;

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

	        default:
		        return 0;
	    }
    }
    else if (lpDDPF->dwFlags & DDPF_BUMPDUDV)    //It's a bump map
    {
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


/******************************************************************************
* DWORD ConvertTexelFormatFor3DBlt( DWORD dwTexelFormat )
*
* Args:
*   dwTexelFormat   Texture Pixel Format
*
* Returns: None
*
* Description:
*   When performing a 3D blt from a Non-RGB surface to a RGB surface, MS
*   seems to expect that no conversion of data takes place.  The Radeon
*   hardware tries to convert the non-RGB to RGB which produces incorrect
*   results.  For example, A8L8 gets converted to RGB by replicating the
*   L8 to the R, G, and B channels and dropping the Alpha.
*
******************************************************************************/
__inline DWORD ConvertTexelFormatFor3DBlt( DWORD dwTexelFormat )
{
    switch(dwTexelFormat)
    {
    case PP_TXFORMAT_0__TXFORMAT__8BPP_L_A1:
    case PP_TXFORMAT_0__TXFORMAT__8BPP_L:
    case PP_TXFORMAT_0__TXFORMAT__8BPP_Y:
    case PP_TXFORMAT_0__TXFORMAT__CCC_DXT1:
    case PP_TXFORMAT_0__TXFORMAT__CCC_DXT2:
    case PP_TXFORMAT_0__TXFORMAT__CCC_DXT4:
        dwTexelFormat = PP_TXFORMAT_0__TXFORMAT__8BPP_RGB;
        break;

    case PP_TXFORMAT_0__TXFORMAT__16BPP_AL:
    case PP_TXFORMAT_0__TXFORMAT__8U8V_BUMP_MAP:
    case PP_TXFORMAT_0__TXFORMAT__16BPP_SHADOW_MAP:
    case PP_TXFORMAT_0__TXFORMAT__5U5V6L_BUMP_MAP:
        dwTexelFormat = PP_TXFORMAT_0__TXFORMAT__16BPP_RGB;
        break;

    case PP_TXFORMAT_0__TXFORMAT__Q8W8V8U8_SIGNED:
    case PP_TXFORMAT_0__TXFORMAT__W11V11U10_SIGNED:
    case PP_TXFORMAT_0__TXFORMAT__V16U16_SIGNED:
    case PP_TXFORMAT_0__TXFORMAT__A2W10V10U10_SIGNED:
    case PP_TXFORMAT_0__TXFORMAT__32BPP_RGBA:
    case PP_TXFORMAT_0__TXFORMAT__32BPP_SHADOW_MAP:
    case PP_TXFORMAT_0__TXFORMAT__8U8V8L_BUMP_MAP:
        dwTexelFormat = PP_TXFORMAT_0__TXFORMAT__32BPP_ARGB;
        break;

    default:
        break;
    }
    return dwTexelFormat;
}


__inline DWORD GetATiSurfColorFormat(LPDDPIXELFORMAT lpDDPF)
{
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
        
            default:
                return 0;
        }
    }
    else if (lpDDPF->dwFlags & DDPF_BUMPDUDV)    //It's a bump map
    {
        switch (lpDDPF->dwBumpBitCount)
        {
            case 16:
                return RB3D_CNTL__COLORFORMAT__RGB565;
        
            case 24:
            case 32:
                return RB3D_CNTL__COLORFORMAT__ARGB8888;
       
            default:
                return 0;
        }
    }
    else if ( lpDDPF->dwFlags & DDPF_LUMINANCE )
    {
        if ( lpDDPF->dwLuminanceBitMask == 0xff )
        {
            if ( lpDDPF->dwFlags & DDPF_ALPHAPIXELS )
            {
                return RB3D_CNTL__COLORFORMAT__RGB565;
            }
            else
            {
                return RB3D_CNTL__COLORFORMAT__RGB332;
            }
        }
        return 0;
    }
	else if (lpDDPF->dwFlags & DDPF_ALPHA)
	{
		if (lpDDPF->dwRGBBitCount == 8)
		{
			return RB3D_CNTL__COLORFORMAT__RGB332;
		}
		return 0;
	}
    else
    {
        // Must be RGB
        switch (lpDDPF->dwRGBBitCount)
        {
        case 8:
            if (lpDDPF->dwFlags & DDPF_PALETTEINDEXED8)
            {
                return 0;
            }
            else
            {
                return RB3D_CNTL__COLORFORMAT__RGB332;
            }
        
        case 16:
            if (lpDDPF->dwRBitMask == 0xF800)
            {
                return RB3D_CNTL__COLORFORMAT__RGB565;
            }
            else if ( (lpDDPF->dwRBitMask == 0x1F) && (lpDDPF->dwGBitMask == 0x3E0) && (lpDDPF->dwBBitMask == 0xFC00) )
            {
                // 5U5V6L
                return RB3D_CNTL__COLORFORMAT__RGB565;
            }
            else if (lpDDPF->dwRBitMask == 0x0F00)
            {
                return RB3D_CNTL__COLORFORMAT__ARGB4444;
            }
            else
            {
                return RB3D_CNTL__COLORFORMAT__ARGB1555;
            }
        
        case 32:
            return RB3D_CNTL__COLORFORMAT__ARGB8888;
        
        default:
            return 0;
        }
    }
}


// Get Pixel Width of the overlay surface
__inline BOOL GetBytesPerPixel(DWORD dwATIPixelFormat)
{
    DWORD BytesPerPixel = 1;  // Default value
    
	switch (dwATIPixelFormat) {
	case 3: case 4: case 11: case 12:	BytesPerPixel = 2; break;
	case 6:								BytesPerPixel = 4; break;
	case 9: case 10: case 13: case 14:	BytesPerPixel = 1; break;
	}
    return BytesPerPixel;
}    

//return TRUR if the pixel format is support for overlay
__inline BOOL CheckValidATIOverlayPixFormat(LPDDPIXELFORMAT lpDDPF)
{
  if (lpDDPF->dwFlags & DDPF_FOURCC)
  {
	switch (lpDDPF->dwFourCC)
	{
      case FOURCC_YUY2:
      case FOURCC_UYVY:
      case FOURCC_YV12:
      case FOURCC_MCAM:
      case FOURCC_MC12:
      case FOURCC_MCR4:
      case FOURCC_M2AM:
      case FOURCC_YVU9:
      case FOURCC_IF09:
      case FOURCC_IYUV:
      case FOURCC_IMC4:
		return TRUE;
	}
  }
  else
  {
    //Must be RGB
    switch (lpDDPF->dwRGBBitCount)
    {
      case 16:
      case 32:
      return TRUE;
    }
  }
  // Invalid overlay pixel format
  return FALSE;

}

__inline BOOL CheckValidATITexturePixFormat(LPDDPIXELFORMAT lpDDPF)
{
  if (lpDDPF->dwFlags & DDPF_FOURCC)
  {
	 switch (lpDDPF->dwFourCC)
	 {
	 case FOURCC_YUY2:
	 case FOURCC_UYVY:
     case FOURCC_DXT1:
     case FOURCC_DXT2:
     case FOURCC_DXT3:
     case FOURCC_DXT4:
     case FOURCC_DXT5:
     case D3DFMT_V16U16:
     case D3DFMT_Q8W8V8U8:
#if (DIRECT3D_VERSION >= 0x0900)
     case D3DFMT_A8B8G8R8:
     case D3DFMT_X8B8G8R8:
#endif //(DIRECT3D_VERSION)
     case D3DFMT_W11V11U10:
     case D3DFMT_A2W10V10U10:
     case D3DFMT_A2B10G10R10:
         return TRUE;
     default:
         return FALSE;
     }
  } 
  else if (lpDDPF->dwFlags & DDPF_PALETTEINDEXED8)
  {
     return FALSE;
  }
  else if (lpDDPF->dwFlags & DDPF_BUMPDUDV)    //It's a bump map
  {
    //Rage 6 supports 8U8V, 5U5V6L, and 8U8V8L bump formats

    switch (lpDDPF->dwBumpBitCount)
    {
      case 16:
      case 24:
      case 32:
            return TRUE;
      default:
            return FALSE;
    }
  }
  else if(lpDDPF->dwFlags & DDPF_LUMINANCE)
  {
    if(lpDDPF->dwLuminanceBitMask == 0xFF)
    {
        return TRUE;
    }
    return FALSE;      
  }
  else if(lpDDPF->dwFlags & DDPF_ALPHA)
  {
	  if(lpDDPF->dwRGBBitCount == 8)
	  {
		  return TRUE;
	  }
	  return FALSE;
  }
  else
  {
     //Must be RGB
        switch (lpDDPF->dwRGBBitCount)
        {
        case 8:
            if(lpDDPF->dwRBitMask == 0xE0)
               return TRUE;    //RGB332   
            else
               return 0;

        case 16:
            if (lpDDPF->dwRBitMask == 0xF800)
               return TRUE;    //RGB565
            else if ((lpDDPF->dwRBitMask == 0x7C00)/*&&(lpDDPF->dwRGBAlphaBitMask==0x8000)*/)   
               return TRUE;    //aRGB1555
            else if (lpDDPF->dwRBitMask == 0xF00)
               return TRUE;    //aRGB4444    
            else 
               return 0;

        case 32:
            if(lpDDPF->dwRBitMask == 0xFF0000)
                return TRUE;        //aRGB8888
            else if(lpDDPF->dwRBitMask == 0xFF000000)
                return TRUE;        //RGBa8888
            else 
                return 0;

        default:
            return 0;   
        }
    }
  // Invalid texture pixel format
  return FALSE;
}


/*
 * CheckValidOffScrnPixFrmt:
 * This macro is used inside CanCreateSurface32, it determines
 * if the requested surface has a valid(ATIO supported) pixel format
*/
BOOL __inline CheckValidOffScrnPixFrmt (LPATIDXOBJECT lpATIDXObj,
                                        LPDDPIXELFORMAT lpDDPF) 
//                                        LPDDPIXELFORMAT lpDDDstPF )
{
  BOOL      bRetVal;
  
  if (lpDDPF->dwFlags & DDPF_FOURCC)
  {
	switch (lpDDPF->dwFourCC)
	{
	case FOURCC_YUY2:
	case FOURCC_UYVY:
    case FOURCC_YV12:
    case FOURCC_YVU9:
    case FOURCC_IYUV:
	case FOURCC_IMC4:
    case FOURCC_M2IA:
    case FOURCC_VBID:
    case FOURCC_DXT1:
    case FOURCC_DXT2:
    case FOURCC_DXT3:
    case FOURCC_DXT4:
    case FOURCC_DXT5:
    case FOURCC_AYUV:
		bRetVal=TRUE;
        break;

#if (DIRECT3D_VERSION >= 0x0900)
    case D3DFMT_A2R10G10B10:
        bRetVal = TRUE;
        break;
#endif //(DIRECT3D_VERSION >= 0x0900)

    default:
		bRetVal=FALSE;
        break;
	}
  }
  else if (lpDDPF->dwFlags & DDPF_RGB)
  {
     switch (lpDDPF->dwRGBBitCount)
     {
     case 8:
     case 16:
     case 32:
	     bRetVal=TRUE;
         break;

     default:
         bRetVal=FALSE;           
         break;
     }        
  }
  else if (lpDDPF->dwFlags & DDPF_ZBUFFER)
  {
     switch (lpDDPF->dwRGBBitCount)
     {
     case 16:
     case 32:
	    bRetVal=TRUE;
        break;

     default:
        bRetVal=FALSE;           
        break;
     }
  }
  else
  {
     bRetVal=FALSE;
  }

  return bRetVal;   
}

__inline BOOL IsValidBltPixFrmt2D(LPDDPIXELFORMAT lpDDPF)
{
    if (lpDDPF->dwFlags & DDPF_PALETTEINDEXED8)
    {
        return TRUE;
    }
    else if (lpDDPF->dwFlags & DDPF_FOURCC)  // FourCC Source
    {
        switch (lpDDPF->dwFourCC)
	    {
        // FourCC Source
        }
    }
    else if (lpDDPF->dwFlags & DDPF_RGB)
    {
        switch (lpDDPF->dwRGBBitCount)
        {
        case 8:
        case 16:
        case 32:
            return TRUE;
        }        
    }

    return FALSE;
}


__inline BOOL IsValidBltPixFrmt3D(LPDDPIXELFORMAT lpDDSrcPF, 
                                  LPDDPIXELFORMAT lpDDDstPF)
{
    if (lpDDSrcPF->dwFlags & DDPF_FOURCC)  // FourCC Source
    {
        switch (lpDDSrcPF->dwFourCC)
	    {
	    case FOURCC_YUY2:
	    case FOURCC_UYVY:
        case FOURCC_DXT1:
        case FOURCC_DXT2:
        case FOURCC_DXT3:
        case FOURCC_DXT4:
        case FOURCC_DXT5:
#if (DIRECT3D_VERSION >= 0x0900)
        case D3DFMT_A8B8G8R8:
        case D3DFMT_X8B8G8R8:
        case D3DFMT_A2B10G10R10:
#endif// (DIRECT3D_VERSION >= 0x0900)
            if (lpDDDstPF->dwFlags & DDPF_FOURCC)  // FourCC dest
            {
                switch (lpDDDstPF->dwFourCC)
                {
                case FOURCC_YUY2:
                case FOURCC_UYVY:
                case FOURCC_DXT1:
                case FOURCC_DXT2:
                case FOURCC_DXT3:
                case FOURCC_DXT4:
                case FOURCC_DXT5:
#if (DIRECT3D_VERSION >= 0x0900)
                case D3DFMT_A8B8G8R8:
                case D3DFMT_X8B8G8R8:
                case D3DFMT_A2B10G10R10:
#endif// (DIRECT3D_VERSION >= 0x0900)
                   return TRUE;

                }
            }
            else if (lpDDDstPF->dwFlags & DDPF_RGB)  // RGB dest
            {
                switch (lpDDDstPF->dwRGBBitCount)
                {
                case 8:
                    if( lpDDDstPF->dwFlags & DDPF_PALETTEINDEXED8)
                    {
                        return FALSE;
                    }
                    else
                    {
                        return TRUE;
                    }
                case 16:
                case 32:
                    return TRUE;
                }
            }
            break;

        case FOURCC_YV12:
        case FOURCC_YVU9:
        case FOURCC_IF09:
            if (lpDDDstPF->dwFlags & DDPF_FOURCC)  // FourCC dest
            {
                switch (lpDDDstPF->dwFourCC)
                {
                case FOURCC_YV12:
                case FOURCC_YVU9:
                case FOURCC_YUY2:
                case FOURCC_UYVY:
                case FOURCC_IF09:
                    return TRUE;
                }
            }
            else if (lpDDDstPF->dwFlags & DDPF_RGB)  // RGB dest
            {
                switch (lpDDDstPF->dwRGBBitCount)
                {
                case 8:
                    if( lpDDDstPF->dwFlags & DDPF_PALETTEINDEXED8)
                    {
                        return FALSE;
                    }
                    else
                    {
                        return TRUE;
                    }
                case 16:
                case 32:
                    return TRUE;
                }
            }
            break;
        }
    }
    else if ( lpDDSrcPF->dwFlags & DDPF_LUMINANCE )
    {
        if ( lpDDSrcPF->dwLuminanceBitMask == 0xFF )
        {
            return TRUE;
        }
    }
	else if (lpDDSrcPF->dwFlags & DDPF_ALPHA)
	{
		if (lpDDSrcPF->dwRGBBitCount == 8)
		{
			return TRUE;
		}
	}
    else if (lpDDSrcPF->dwFlags & DDPF_RGB)  // RGB source
    {
        switch (lpDDSrcPF->dwRGBBitCount)
        {
        case 8:
        case 16:
        case 32:
            if (lpDDDstPF->dwFlags & DDPF_FOURCC)  // FourCC dest
            {
                switch (lpDDDstPF->dwFourCC)
                {
                case FOURCC_YUY2:
                case FOURCC_UYVY:
                    return TRUE;

                }
            }
            else if (lpDDDstPF->dwFlags & DDPF_RGB)  // RGB dest
            {
                switch (lpDDDstPF->dwRGBBitCount)
                {
                case 8:
                    if( lpDDDstPF->dwFlags & DDPF_PALETTEINDEXED8)
                    {
                        return FALSE;
                    }
                    else
                    {
                        return TRUE;
                    }
                case 16:
                case 32:
                    return TRUE;
                }
            }
            break;
        }
    }        
    else if (lpDDDstPF->dwFlags & DDPF_BUMPDUDV)    //It's a bump map
    {
        switch (lpDDDstPF->dwBumpBitCount)
        {
            case 16:
            case 24:
            case 32:
                return TRUE;     
            default:
                return FALSE;
        }
    }

    return FALSE;   
}

__inline DWORD MakeBltStartXY( RECTL rBltRect)
{
 return ( (rBltRect.top) | ((rBltRect.left) << 16) );
}

__inline DWORD MakeBltWdthHght(RECTL rBltRect)
{
 return ( (((rBltRect.right)  - (rBltRect.left)) << 16) |
       ((rBltRect.bottom)  - (rBltRect.top)) ); 
}
__inline DWORD MakeScaleBltHghtWdth(RECTL rBltRect)
{
 return ( ((rBltRect.right) - (rBltRect.left)) |
        (((rBltRect.bottom) - (rBltRect.top)) << 16) ); 
}

__inline DWORD GetScaleXInc (DWORD SrcWdthHght, DWORD DstWdthHght)
{
 return (((SrcWdthHght & WdthMask)) / ((DstWdthHght>>16)));
}

__inline DWORD GetScaleYInc (DWORD SrcWdthHght, DWORD DstWdthHght)
{
 return (((SrcWdthHght & HghtMask)<<16) / (DstWdthHght & HghtMask));
}


__inline BOOL ColourKeySrc(DWORD dwFlags)
{
 if (dwFlags & DDBLT_KEYSRCOVERRIDE)
    return TRUE;
 else
    return FALSE;
}

__inline BOOL ColourKeyDst(DWORD dwFlags)
{
 if (dwFlags & DDBLT_KEYDESTOVERRIDE)
    return TRUE;
 else
    return FALSE;
}

__inline BOOL ColourKeyRequired(DWORD dwFlags)
{
 if ( (ColourKeySrc(dwFlags)) || (ColourKeyDst(dwFlags)) )
      return TRUE;
 else
      return FALSE;
}

/*****************************************************************************/

#endif //_MACROS_H



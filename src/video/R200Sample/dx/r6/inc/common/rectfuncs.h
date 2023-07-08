

//    
//  $Workfile: rectfuncs.h $
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

#ifndef _RECTFUNCS_H
#define _RECTFUNCS_H

#include "atidxinc.h"

#define DXT1_BLOCKSIZE            8 
#define DXT2TO5_BLOCKSIZE         16

#ifndef ATI_GUARD_BAND
    #define ATI_GUARD_BAND 2048
#endif

__inline DWORD MakePaintStartTL( RECTL rPaintRect)
{
 return ( (rPaintRect.left) | ((rPaintRect.top) << 16) );
}

__inline DWORD MakePaintBR(RECTL rPaintRect)
{
 return (  (rPaintRect.right)  | ((rPaintRect.bottom) << 16) );
}


__inline DWORD MakePaintStartTL2( LPRECTL lpPaintRect)
{
 return ( (lpPaintRect->left) | ((lpPaintRect->top) << 16) );
}

__inline DWORD MakePaintBR2( LPRECTL lpPaintRect)
{
 return ( (lpPaintRect->right) | ((lpPaintRect->bottom) << 16) );
}

//
// These two macros calculate rectangles in the super sampling surface.
// Their coordinates are doubled.
//
__inline DWORD MakeAAPaintStartTL2( LPRECTL lpPaintRect, float xRatio, float yRatio )
{
 return ( ( DWORD )( xRatio * lpPaintRect->left ) ) | ( ( ( DWORD )( yRatio * lpPaintRect->top ) << 16 ) );
}

__inline DWORD MakeAAPaintBR2( LPRECTL lpPaintRect, float xRatio, float yRatio )
{
    DWORD dwRight, dwBottom;

    if( ( dwRight = ( DWORD )( xRatio * lpPaintRect->right ) ) >= ATI_GUARD_BAND )
        dwRight = ATI_GUARD_BAND - 1;
    if( ( dwBottom = ( DWORD )( yRatio * lpPaintRect->bottom ) ) >= ATI_GUARD_BAND )
        dwBottom = ATI_GUARD_BAND - 1;
    return ( dwRight | ( dwBottom << 16 ) );
}

/*
 * This macro determines if two rectangle intersect(overlap)
*/
__inline BOOL OverlappingRects(LPRECTL rSrc, LPRECTL rDest)
{
 if ( (rDest->top <= rSrc->bottom) && (rDest->left < rSrc->right) 
      && (rDest->right > rSrc->left) )
      return TRUE;
 else
      return FALSE; 
}


/*
 * IsRectEqualSize:
 * This macro is used to determine if two rectangles are the same size
*/
__inline BOOL IsRectEqualSize(LPRECTL lpRect1, LPRECTL lpRect2)
{
    if(((lpRect1->right - lpRect1->left) == (lpRect2->right - lpRect2->left)) &&
       ((lpRect1->bottom - lpRect1->top) == (lpRect2->bottom - lpRect2->top)))
    {
        return TRUE; 
    }
    else
    {
        return FALSE;
    }
}

__inline BOOL IsPartialSurfRect(LPDDRAWI_DDRAWSURFACE_LCL lpDDSLCL, LPRECTL lpRect)
{
    if(lpRect->top != 0 || lpRect->left != 0 ||
       lpRect->bottom < (LONG)lpDDSLCL->lpGbl->wHeight ||
       lpRect->right < (LONG)lpDDSLCL->lpGbl->wWidth) 
    {
        return TRUE;
    }

    return FALSE;
}

__inline void ScaleRectToAASize( LPRECTL lpRect, float xRatio, float yRatio, LONG GuardBand )
{
    lpRect->top = ( DWORD )( lpRect->top * yRatio );
    lpRect->left = ( DWORD )( lpRect->left * xRatio );
    if( ( lpRect->bottom = ( DWORD )( lpRect->bottom * yRatio ) ) >= GuardBand )
        lpRect->bottom = GuardBand; 
    if( ( lpRect->right = ( DWORD )( lpRect->right * xRatio ) ) >= GuardBand )
        lpRect->right = GuardBand;     
}

__inline void CopyRectangle( LPRECTL Dest, LPRECTL Source )
{
    Dest->left = Source->left;
    Dest->right = Source->right;
    Dest->top = Source->top;
    Dest->bottom = Source->bottom;
}

__inline void MipMapRect( LPRECTL Rect, DWORD dwMipScale )
{
    Rect->top >>= dwMipScale;
    Rect->left >>= dwMipScale;

    // When calculate right and bottom edges, make sure they will be rounded up
    // and they won't be the same as left and right edges.
    Rect->right = ( Rect->right + ((1<<dwMipScale)-1) ) >> dwMipScale;
    Rect->bottom = ( Rect->bottom + ((1<<dwMipScale)-1) ) >> dwMipScale;

    if (Rect->right == Rect->left)
    {
        Rect->right += 1;
    }

    if (Rect->bottom == Rect->top)
    {
        Rect->bottom += 1;
    }
}

__inline void CalcDXTBltPt( LPPOINT Pt, DWORD dwDXTFourCC )
{
    //work in block sizes
    if( dwDXTFourCC == FOURCC_DXT1 )
    {
        Pt->x = ( Pt->x >> 2 ) * DXT1_BLOCKSIZE;
    }

    else
    {
        Pt->x = ( Pt->x >> 2 ) * DXT2TO5_BLOCKSIZE;
    }
    
    Pt->y = ( Pt->y >> 2 );
}

__inline void CalcDXTBltRect( LPRECTL Rect, DWORD dwDXTFourCC )
{
    //work in block sizes
    Rect->left =  Rect->left >> 2;
    Rect->right = ( Rect->right + 3 ) >> 2;
    
    if( dwDXTFourCC == FOURCC_DXT1 )
    {
        Rect->left  *= DXT1_BLOCKSIZE;
        Rect->right *= DXT1_BLOCKSIZE;
    }
    
    else //DXT 2 - 5 
    {
        Rect->left  *= DXT2TO5_BLOCKSIZE;
        Rect->right *= DXT2TO5_BLOCKSIZE;
    }
    
    Rect->top    = Rect->top >> 2;
    Rect->bottom = ( Rect->bottom + 3 ) >> 2;
}

#endif // _RECTFUNCS_H


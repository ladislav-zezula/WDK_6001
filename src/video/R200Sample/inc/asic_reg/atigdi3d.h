

/*****************************************************************************
 *
 *
 *
 *  Trade secret of ATI Technologies, Inc.
 *  Copyright 2002, ATI Technologies, Inc., (unpublished)
 *
 *	 All rights reserved.
 *	 The year included in the foregoing notice is the year of creation of the work.
 *
 *
 ****************************************************************************
 */

#ifndef __GDI3D_H__
#define __GDI3D_H__
#define _GDI3DAPI

typedef struct _GDI3DSTRBLT
{
    DWORD       dwSize;

    DWORD       dwSrcOffset;
    BOOL        dwSrcMacroTile;
    DWORD       dwSrcMicroTile; 
    DWORD       dwSrcLeft;
    DWORD       dwSrcTop;
    DWORD       dwSrcRight;
    DWORD       dwSrcBottom;
    DWORD       dwSrcSurfWidth;
    DWORD       dwSrcSurfHeight;
    DWORD       dwSrcDataType;

    DWORD       dwDstOffset; 
    BOOL        dwDstMacroTile;
    DWORD       dwDstMicroTile; 
    DWORD       dwDstLeft;
    DWORD       dwDstTop;
    DWORD       dwDstRight;
    DWORD       dwDstBottom;
    DWORD       dwDstSurfWidth;
    DWORD       dwDstSurfHeight;
    DWORD       dwDstPixFmt;

    DWORD       dwNumClipRects;  // Number of clip rectangles
    RECTL       *prclClip;       // Array of clip rectangles

    DWORD       dwNumPrimitives; // Total number of primitives
    RECTL       *prclSrc;        // Src rectangle of primitives
    RECTL       *prclDst;        // Dst rectangle of primitives
} GDI3DSTRBLT, *PGDI3DSTRBLT;

typedef struct _GDI3DALPHABLT
{
    DWORD       dwSize;

    DWORD       dwSrcOffset; 
    BOOL        dwSrcMacroTile; 
    DWORD       dwSrcMicroTile;
    DWORD       dwSrcLeft; 
    DWORD       dwSrcTop;
    DWORD       dwSrcRight;
    DWORD       dwSrcBottom;
    DWORD       dwSrcSurfWidth;
    DWORD       dwSrcSurfHeight;
    DWORD       dwSrcDataType; 

    DWORD       dwDstOffset; 
    BOOL        dwDstMacroTile; 
    DWORD       dwDstMicroTile;
    DWORD       dwDstLeft; 
    DWORD       dwDstTop;
    DWORD       dwDstRight;
    DWORD       dwDstBottom;
    DWORD       dwDstSurfWidth;
    DWORD       dwDstSurfHeight;
    DWORD       dwDstPixFmt;

    BOOL        bSrcAlpha;       // Source alpha enable
    DWORD       dwSrcConstAlpha; // Source constant alpha value

    DWORD       dwNumClipRects;  // Number of clip rectangles
    RECTL       *prclClip;       // Array of clip rectangles

    DWORD       dwNumPrimitives; // Total number of primitives
    RECTL       *prclSrc;        // Src rectangle of primitives
    RECTL       *prclDst;        // Dst rectangle of primitives
} GDI3DALPHABLT, *PGDI3DALPHABLT;
    
typedef struct _GDI3DGRADFILL
{
    DWORD       dwSize;

    DWORD       dwDstOffset;
    BOOL        dwDstMacroTile;
    DWORD       dwDstMicroTile; 
    DWORD       dwDstSurfWidth; 
    DWORD       dwDstSurfHeight;
    DWORD       dwDstPixFmt;

    DWORD       dwFillMode;      // GRADIENT_FILL_XXX mode

    DWORD       dwNumClipRects;  // Number of clip rectangles
    RECTL       *prclClip;       // Array of clip rectangles

    DWORD       dwNumPrimitives; // Total number of primitives
    LPTRIVERTEX pVertex;         // Must be in upper-left and lower-left
                                 // order for rectangle
                                 // Rectangle: 2 * dwNumPrimitives vertices
                                 // Triangle : 3 * dwNumPrimitives vertices
} GDI3DGRADFILL, *PGDI3DGRADFILL; 

typedef struct _GDI3DAATEXTOUT
{
    DWORD       dwSize;

    DWORD       dwSrcOffset; 
    BOOL        dwSrcMacroTile; 
    DWORD       dwSrcMicroTile;
    DWORD       dwSrcLeft; 
    DWORD       dwSrcTop;
    DWORD       dwSrcRight;
    DWORD       dwSrcBottom;
    DWORD       dwSrcSurfWidth;
    DWORD       dwSrcSurfHeight;

    DWORD       dwDstOffset; 
    BOOL        dwDstMacroTile; 
    DWORD       dwDstMicroTile;
    DWORD       dwDstLeft; 
    DWORD       dwDstTop;
    DWORD       dwDstRight;
    DWORD       dwDstBottom;
    DWORD       dwDstSurfWidth;
    DWORD       dwDstSurfHeight;
    DWORD       dwDstPixFmt;

    DWORD       dwSrcConstColor; // Source constant color value

    DWORD       bDstConstColor;  // Has solid background color
    DWORD       dwDstConstColor; // Solid background color

    DWORD       dwNumClipRects;  // Number of clip rectangles
    RECTL       *prclClip;       // Array of clip rectangles

    DWORD       dwNumPrimitives; // Total number of primitives
    RECTL       *prclSrc;        // Src rectangle of primitives
    RECTL       *prclDst;        // Dst rectangle of primitives
} GDI3DAATEXTOUT, *PGDI3DAATEXTOUT;
    
typedef struct _GDI3DSOLIDFILL
{
    DWORD       dwSize;

    DWORD       dwDstOffset; 
    BOOL        dwDstMacroTile; 
    DWORD       dwDstMicroTile;
    DWORD       dwDstLeft; 
    DWORD       dwDstTop;
    DWORD       dwDstRight;
    DWORD       dwDstBottom;
    DWORD       dwDstSurfWidth;
    DWORD       dwDstSurfHeight;
    DWORD       dwDstPixFmt;

    DWORD       dwFillValue;     // Source constant alpha value

    DWORD       dwNumClipRects;  // Number of clip rectangles
    RECTL       *prclClip;       // Array of clip rectangles

    DWORD       dwNumPrimitives; // Total number of primitives
    RECTL       *prclDst;        // Dst rectangle of primitives
} GDI3DSOLIDFILL, *PGDI3DSOLIDFILL;
    
extern VOID APIENTRY vGDI3DStretchBlt(
    LPVOID      lpDxObj,
    GDI3DSTRBLT *pStrBlt);

extern VOID APIENTRY vGDI3DAlphaBlt(
    LPVOID          lpDxObj,
    GDI3DALPHABLT *pAlphaBlt);

extern VOID APIENTRY vGDI3DGradientFill(
    LPVOID        lpDxObj,
    GDI3DGRADFILL *pGradFill);

extern VOID APIENTRY vGDI3DAATextOut(
    LPVOID         lpDxObj,
    GDI3DAATEXTOUT *pAATextOut);

extern VOID APIENTRY vGDI3DSolidFill(
    LPVOID         lpDxObj,
    GDI3DSOLIDFILL *pSolidFill);

#endif // __GDI3D_H__



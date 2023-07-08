

//    
//  $Workfile: blt.h $
//  $Revision: 8 $
//
//  Description:
//
//  Last modification: 
//     $Author: Merwin $ 
//     $Date: 7/19/99 3:15p $
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef BLT_H
#define BLT_H

#include "atidxhsl.h"
#include "atidxobj.h"
#include "rectfuncs.h"

#define BLTFLAG_SRC_TILED            0x00000001
#define BLTFLAG_DST_TILED            0x00000002
#define BLTFLAG_SRC_MICROTILED       0x00000004
#define BLTFLAG_DST_MICROTILED       0x00000008
#define BLTFLAG_SRC_COLORKEY         0x00000010
#define BLTFLAG_DST_COLORKEY         0x00000020
#define BLTFLAG_YUV_TO_RGB           0x00000040
#define BLTFLAG_ARITHMETIC           0x00000080
#define BLTFLAG_SRC_ALPHA            0x00000100
#define BLTFLAG_FORCE_SRCALPHA_ONE   0x00000800
#define BLTFLAG_SRC_A8               0x00001000
#define BLTFLAG_BLOCKDISABLE         0x00002000

#define TILE_WIDTH                   256
#define TEMP_ALIGNMENT               0x1000   //4K

#ifdef WIN2K
#define ROP_FROM_GDIROP3(r) (r >> 16)
#endif

#ifdef UMD
#define SUBMIT_SMALL_PITCH_2D_SRCCPY_BLT_SIZE  (29 + 2*(1 + sizeof(D3DKMT_HANDLE)/sizeof(DWORD)))
#define SUBMIT_2D_TRANS_BLT_SIZE               (13 + 2 + 2*(1 + sizeof(D3DKMT_HANDLE)/sizeof(DWORD)))
#else
#define SUBMIT_SMALL_PITCH_2D_SRCCPY_BLT_SIZE  29
#define SUBMIT_2D_TRANS_BLT_SIZE               (13 + 2)
#endif

typedef struct _CMDBUFF * LPCMDBUFF;
typedef struct _ATID3DCNTX     *LPATID3DCNTX;

#ifdef LUT1USEHWCSC
/******************************************************************************
* BOOL bIsDownscaleBlt()
*
* Args:
*   rSrc  (r)  the source rectangle
*   rDest (r)  the destination rectangle
*
* Returns:
*   true the BLT is considered a Downscale BLT.  A downscale BLT is one where
*   the source BLT region is much larger than the destination.    
*
* Description:
*    A BLT is considered downscale only if the source is much larger than the
*    destination in either height or width.
*
*    For BLTs where the dest is much smaller than the source (more than a 1:2 
*    ratio) a single-pass blt on Rage6 suffers in quality.  This method is used
*    detmine is a multipass BLT is warranted.
******************************************************************************/

__inline BOOL bIsDownscaleBlt(LPATIDXOBJECT lpATIDXObj, RECTL rSrc, RECTL rDst)
{
    // the var 'threshold' defines what source:destination ratio is considered
    // a downscale blt.  For Rage6, this number should be greater than 2.0.
    // The default is 2.5, but can be overriden in via the Windows registry.
    register float threshold = lpATIDXObj->fMultiPassDownscaleBltThreshold;
    register DWORD dstH = rDst.bottom - rDst.top;   // destination height
    register DWORD srcH = rSrc.bottom - rSrc.top;   // source height
    register DWORD dstW = rDst.right - rDst.left;   // destination width
    register DWORD srcW = rSrc.right - rSrc.left;   // source width

    // check to see if width or height ratios exceed threshold

    if(dstH * threshold < srcH || dstW * threshold < srcW)
    {
        HSLDPF(E_DEBUG1, "Downscale BLT detected %d:%d x %d:%d", srcH,dstH,srcW,dstW );
        return TRUE;
    }

    return FALSE;
}
#endif // LUT1USEHWCSC

/******************************************************************************
* DWORD ColorMaskFromColorFormat()
*
* Args:
*   dwFormat    a valid Rage6 RB3D_CNTL_COLORFORMAT         
*
* Returns:
*   a bit mask for the format's RGB colorbits 
*
* Description:
*   converts from an enumerated ColorFormat into a bit mask
*   for the RGB colorbits.  This is used to set the chroma mask
*   in the 3D pixel pipe. 
*
******************************************************************************/

__inline DWORD ColorMaskFromColorFormat(DWORD dwFormat)
{
    register rval=0;

    switch (dwFormat & RB3D_CNTL__COLORFORMAT_MASK )
    {
    case RB3D_CNTL__COLORFORMAT__ARGB1555:          // 15 bit rgb mask
        rval = 0x7FFF;
        break;
    case RB3D_CNTL__COLORFORMAT__RGB565:            // 16 bit rgb mask
        rval = 0xFFFF;
        break;
    case RB3D_CNTL__COLORFORMAT__ARGB8888:          // 24 bit rgb mask
        rval = 0x00FFFFFF;
        break;
    case RB3D_CNTL__COLORFORMAT__RGB332:            // 8 bit rgb mask
    case RB3D_CNTL__COLORFORMAT__Y8:
    case RB3D_CNTL__COLORFORMAT__RGB8:
    case RB3D_CNTL__COLORFORMAT__YUV422_VYUY:
    case RB3D_CNTL__COLORFORMAT__YUV422_YVYU:
        rval = 0xFF;
        break;
    case RB3D_CNTL__COLORFORMAT__aYUV444:           // 12 bit rgb mask
    case RB3D_CNTL__COLORFORMAT__ARGB4444:
        rval = 0xFFF;
        break;
    default:
        HSLDPF(E_ERROR_MESSAGE, "ColorMaskFromColorFormat: unrecognized dwformat = %8x", dwFormat );
        rval = 0xFFFFFFFF;
        break;
    }
    return rval;
    
}

void SubmitDepthFillZBuffer(LPATIDXOBJECT               lpATIDXObj, 
                            LPDDRAWI_DDRAWSURFACE_LCL   lpSurface, 
                            LPRECTL                     lpRect, 
                            LPCMDBUFF                   lpCmdBuf, 
                            DWORD                       dwfColor);

void SubmitColorFillSurface(LPATIDXOBJECT               lpATIDXObj, 
                            LPDDRAWI_DDRAWSURFACE_LCL   lpSurface, 
                            LPRECTL                     lpRect, 
                            LPCMDBUFF                   lpCmdBuf, 
                            DWORD                       dwfColor);

LPDWORD SubmitSmallPitch2dSrcCpyBlt(D3DKMT_HANDLE   hSrcAllocation,
                                    DWORD_PTR       dwSrcOffset,
                                    DWORD           dwSrcBytePitch,
                                    DWORD           dwSrcLeft, 
                                    DWORD           dwSrcTop, 
                                    D3DKMT_HANDLE   hDstAllocation,
                                    DWORD_PTR       dwDstOffset, 
                                    DWORD           dwDstBytePitch, 
                                    DWORD           dwDstLeft, 
                                    DWORD           dwDstTop, 
                                    DWORD           dwWidth, 
                                    DWORD           dwHeight, 
                                    DWORD           dwFormat, 
                                    DWORD           dwBltFlags, 
                                    DWORD           dwSrcKeyColor, 
                                    DWORD           dwDstKeyColor,
                                    DWORD          *PM4Entries,
                                    LPATID3DCNTX    pCtxt);

LPDWORD Submit2dTransBlt(D3DKMT_HANDLE  hSrcAllocation,
                         DWORD          dwSrcOffPtch, 
                         DWORD          dwSrcLeft, 
                         DWORD          dwSrcTop, 
                         D3DKMT_HANDLE  hDstAllocation,
                         DWORD          dwDstOffPtch, 
                         DWORD          dwDstLeft, 
                         DWORD          dwDstTop, 
                         DWORD          dwWidth, 
                         DWORD          dwHeight,
                         DWORD          dwFormat,
                         DWORD          dwBltFlags, 
                         DWORD          dwSrcKeyColor, 
                         DWORD          dwDstKeyColor,
                         DWORD         *PM4Entries,
                         LPATID3DCNTX   pCtxt);

LPDWORD Submit3dScaleBlt(LPATIDXOBJECT  lpATIDXObj,
                         D3DKMT_HANDLE  hSrcAllocation,
                         DWORD_PTR      dwSrcOffset,
                         DWORD          dwSrcBytePitch,
                         DWORD          dwSrcWidth, 
                         DWORD          dwSrcHeight, 
                         DWORD          dwSrcFormat, 
                         DWORD          dwSrcLeft, 
                         DWORD          dwSrcTop, 
                         DWORD          dwSrcRight, 
                         DWORD          dwSrcBottom, 
                         D3DKMT_HANDLE  hDstAllocation,
                         DWORD_PTR      dwDstOffset, 
                         DWORD          dwDstPixelPitch, 
                         DWORD          dwDstWidth, 
                         DWORD          dwDstHeight, 
                         DWORD          dwDstFormat, 
                         DWORD          dwDstLeft, 
                         DWORD          dwDstTop, 
                         DWORD          dwDstRight, 
                         DWORD          dwDstBottom, 
                         DWORD          dwBltFlags, 
                         DWORD          dwSrcKeyColor, 
                         float          uOffset,
                         float          vOffset,
                         DWORD         *PM4Entries,
                         LPATID3DCNTX    pCtxt);

DWORD SrcCopyBlt(LPVOID             lpDevInfo, 
                 LPDDHSLSURFACEDESC lpSurfDescSrc, 
                 LPDDHSLSURFACEDESC lpSurfDescDst, 
                 LPDDHAL_BLTDATA    lpBltData, 
                 LPCMDBUFF          lpCBCurrent);

DWORD SrcCopyZBBlt(LPVOID           lpDevInfo, 
                 LPDDHSLSURFACEDESC lpSurfDescSrc, 
                 LPDDHSLSURFACEDESC lpSurfDescDst, 
                 LPDDHAL_BLTDATA    lpBltData, 
                 LPCMDBUFF          lpCBCurrent);

void vYUVSrcCopy(LPATIDXOBJECT      lpATIDXObj, 
                 LPDDHSLSURFACEDESC lpSurfDescSrc, 
                 LPDDHSLSURFACEDESC lpSurfDescDst, 
                 LPDDHAL_BLTDATA    lpBltData, 
                 LPCMDBUFF          lpCBCurrent,
                 DWORD              dwSrcOffPtch,
                 DWORD              dwDstOffPtch,
                 DWORD              dwTmpTiled,
                 DWORD              dwTmpTiledSrcFlag,
                 DWORD              dwTmpTiledDstFlag,
                 DWORD              dwTmpAlignment,
                 DWORD              dwBltFlags);

void vPal8DstCKSrcCopy(LPATIDXOBJECT        lpATIDXObj, 
                       LPDDHSLSURFACEDESC   lpSurfDescSrc, 
                       LPDDHSLSURFACEDESC   lpSurfDescDst, 
                       LPDDHAL_BLTDATA      lpBltData, 
                       LPCMDBUFF            lpCBCurrent,
                       DWORD                dwSrcOffPtch,
                       DWORD                dwDstOffPtch,
                       DWORD                dwTmpTiled,
                       DWORD                dwTmpTiledSrcFlag,
                       DWORD                dwTmpTiledDstFlag,
                       DWORD                dwTmpAlignment,
                       DWORD                dwBltFlags);

void v3DBltSrcCopy(LPATIDXOBJECT lpATIDXObj, 
                   LPDDHSLSURFACEDESC lpSurfDescSrc, 
                   LPDDHSLSURFACEDESC lpSurfDescDst, 
                   LPDDHAL_BLTDATA lpBltData, 
                   LPCMDBUFF lpCBCurrent,
                   DWORD dwSrcOffPtch,
                   DWORD dwDstOffPtch,
                   DWORD dwTmpTiled,
                   DWORD dwTmpTiledSrcFlag,
                   DWORD dwTmpTiledDstFlag,
                   DWORD dwTmpAlignment,
                   DWORD dwBltFlags);

void v2DBltSrcCopy(LPATIDXOBJECT lpATIDXObj, 
                   LPDDHSLSURFACEDESC lpSurfDescSrc, 
                   LPDDHSLSURFACEDESC lpSurfDescDst, 
                   LPDDHAL_BLTDATA lpBltData, 
                   LPCMDBUFF lpCBCurrent,
                   DWORD dwSrcOffPtch,
                   DWORD dwDstOffPtch,
                   DWORD dwBltFlags);

DWORD AllocTempSurface(LPDDRAWI_DIRECTDRAW_GBL lpDD, DWORD dwWidth, DWORD dwHeight, DWORD dwBytePitch, LPDWORD lpHandle);
void FreeTempSurface(LPDDRAWI_DIRECTDRAW_GBL lpDD, DWORD dwHandle);
void ZBBlt(LPDDHAL_BLTDATA lpBltData, LPATIDXOBJECT lpATIDXObj, LPCMDBUFF lpCmdBuf);
void CSBlt(LPDDHAL_BLTDATA lpBltData, LPATIDXOBJECT lpATIDXObj, LPCMDBUFF lpCmdBuf);
void HostBltSurface(LPVOID lpDev, LPDDHSLSURFACEDESC lpSurfaceDescSys, LPDDHSLSURFACEDESC lpSurfaceDescVid,
                    LPDDHAL_BLTDATA lpBltData, LPCMDBUFF lpCBCurrent);
void AddBltQueueEntry(LPATISURFINFO lpSrcInfo, LPCMDBUFF lpCB);
BOOL IsBltQueueFull(LPATISURFINFO lpDstInfo, LPCMDBUFF lpCB);

#define BSB_MAX_SAMPLES 6
//Undocumented R200 texture cache tie settings set in the TX_PITCH register.
#define R200_TXCACHE_USE_TXUNIT         0
#define R200_TXCACHE_USE_PIPE0_TXUNIT_0 (1 << 30)
#define R200_TXCACHE_USE_PIPE1_TXUNIT_1 (1 << 30)

typedef struct _BSB_SAMPLEBLEND_INFO
{
    float uOffset;            //u, v offset are added to the Scr rect of the 
    float vOffset;            //BLENDED_SCALEBLT_INFO structure.
    float BlendWeight;        //0 - 1 blending weight for the sample point
    BOOL LinearFilter;        //TRUE to apply linear filter, FALSE = point filter.
    UINT TxUnit;              //The texture unit assignement for this sample.
    DWORD TxCacheUnit;        //The texture unit cache assigment for this sample.
} BSB_SAMPLEBLEND_INFO;

typedef struct _BLENDED_SCALEBLT_INFO
{
    DWORD dwBltFlags;           //BLTFLAG_X flags
    DWORD dwNSamples;           //# of sample points to blend

    DWORD dwSrcWidth;           //Src pixel width
    DWORD dwSrcHeight;          //Src pixel height
    DWORD dwSrcPitch;           //Src byte pitch
    DWORD dwHWSrcTxFormat;      //HW PP_TXFORMAT
    DWORD_PTR dwHWSrcOffset;    //HW Src offset
    DWORD dwSrcColorKey;        
    RECT SrcRect;               //Specifies area on Scr to blt
        
    DWORD dwDstWidth;           //Dst pixel width
    DWORD dwDstHeight;          //Dst pixel height
    DWORD dwDstPixelPitch;      //Dst pixel pitch
    DWORD dwDstHWColorFormat;   //RB3D Cntl color format
    DWORD_PTR dwHWDstOffset;    //HW Dst offset
    RECT DstRect;               //Specifies area on Dst to blt to
         
    BSB_SAMPLEBLEND_INFO SampleBlend[BSB_MAX_SAMPLES];  //Specifies how to blt each sample point.

} BLENDED_SCALEBLT_INFO;


BOOL BlendedScaleBlt(LPATIDXOBJECT lpATIDXObj, 
                     LPATISURFINFO lpSurfInfoSrc, 
                     LPATISURFINFO lpSurfInfoDst, 
                     BLENDED_SCALEBLT_INFO *BlendInfo,
                     LPCMDBUFF lpCBCurrent);
UINT CalcBlendedScaleBltPkSize(LPATIDXOBJECT lpATIDXObj,DWORD dwNSamples, DWORD *lpBltVertexSize);
BOOL FmtBlendedScaleBltPk(LPATIDXOBJECT lpATIDXObj,BLENDED_SCALEBLT_INFO *BlendInfo, DWORD *PM4Entries);

void
vInitRectangleCoordinates(
    LPRECTL lpRotRectl,   // rotated dest coordinates
    LPRECTL lpOrgRectl,   // original dest coordinates
    DWORD dwSurfWidth,    // primary surf width
    DWORD dwSurfHeight,   // primary surf height
    DWORD dwAngle         // rotation angle
    );



DWORD VidToSysBlt(LPATIDXOBJECT lpATIDXObj,
                  LPDDHAL_BLTDATA lpBltData);

#endif /* BLT_H */


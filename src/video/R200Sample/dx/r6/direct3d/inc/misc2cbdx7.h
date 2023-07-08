

//    
//  $Workfile: misc2CBdx7.h $
//  $Revision: 1 $
//
//  Description: DX7 routines: CreateSurfaceEx 
//
//  Last modification: 
//     $Author: Cjiang $ 
//     $Date: 7/20/99 6:34p $
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//
#ifndef         MISC2CBDX7_H_
#define         MISC2CBDX7_H_


#include "atidxinc.h"
#include "d3dcntx.h"
#include <d3dumddi.h>

extern BOOL HostBltBuffer(
        LPATID3DCNTX      pContext,
        LPBYTE            lpSrcBuffer,
        DWORD             dwHwDstAddr,
        DWORD             dwSrcByteOffset,
        DWORD             dwSrcByteSize,
        DWORD             dwDstByteOffset,
        LPATIVERTEXBUFFER pVbDst);

extern LPATISURFHANDLE  GetSurfaceHandleList(LPDDRAWI_DIRECTDRAW_LCL lpDDLcl);
extern HRESULT ATITextureBlt(LPATID3DCNTX pContext, D3DHAL_DP2TEXBLT* lpdp2texblt, DWORD dwSrcBltDepth, DWORD dwDstBltDepth );
extern HRESULT  ATISetRenderTarget(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND lpCmd); //// (DIRECT3D_VERSION >= 0x0900)
extern HRESULT ATIVolumeTexBlt( LPATID3DCNTX pContext, D3DHAL_DP2VOLUMEBLT* lpDP2VolTexBlt );
extern HRESULT ATIBufferBlt(LPATID3DCNTX          pContext, 
                            LPD3DHAL_DP2BUFFERBLT pBlt,
                            LPATIVERTEXBUFFER     pVbSrc,
                            LPATIVERTEXBUFFER     pVbDst);
extern VOID    ClearContextsSharingDDLCL (LPDDRAWI_DIRECTDRAW_LCL lpDDLcl);

#if (DIRECT3D_VERSION >= 0x0900)
DWORD  ATIDP2Blt(VOID* Context, D3DDDIARG_BLT* pBltData);
DWORD  ATIDP2Colorfill(LPVOID	Context, LPD3DHAL_DP2COLORFILL	ColorFillData);
HRESULT ATIGenerateMipLevels(LPATID3DCNTX pCtxt, LPD3DHAL_DP2GENERATEMIPSUBLEVELS pGenMipLevels);
DWORD  ATIDP2SurfaceBlt(LPATID3DCNTX pCtxt, LPD3DHAL_DP2SURFACEBLT lpSurfBlt);

extern HRESULT AtiSetScissorRect(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *lppCmd);
#endif // (DIRECT3D_VERSION >= 0x0900)

#endif   // MISC2CBDX7_H_


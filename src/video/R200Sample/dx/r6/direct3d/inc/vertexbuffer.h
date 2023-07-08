

//
//  Workfile: VertexBuffer.h
//
//  Description:
//      Vertex Buffer declarations and definitions.
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 2000-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _VERTEXBUFFER_H_
#define _VERTEXBUFFER_H_


// external includes

#include "atidxinc.h"

///////////////////////////////////////////////////////////////////////////////
// Definitions

#define VB_USE_LAZY_FREE        1

#define VB_CONTEXT_UNKNOWN      0

#define VB_LAZY_FREE_INTVB          1
#define VB_LAZY_FREE_IVB_PURGE      5

#define VB_LAZY_FREE_MAX_BYTESIZE   0x800000
#define VB_LAZY_FREE_MAX_COUNT      500

#define IB_UNLOCK_SYSMEMCOPY_THRESHOLD  8

///////////////////////////////////////////////////////////////////////////////
// Vertex Buffer Flags

#define VB_IS_SYS_MEM            0x00000001
#define VB_IS_AGP_MEM            0x00000002
#define VB_IS_INTERNAL_BUFFER    0x00000004
#define VB_IS_EXPLICIT_BUFFER    0x00000008
#define VB_IS_INDEX_BUFFER       0x00000010
#define VB_IS_LOCKED             0x00000020
#define VB_HAS_SYSTEM_COPY       0x00000040
#define VB_IS_SYSTEM_COPY_VALID  0x00000080
#define VB_IS_LIGHTABLE          0x00000100
#define VB_IS_CULLABLE           0x00000200
#define VB_IS_CULL_READY         0x00000400
#define VB_IS_LOCKED_NOOVERWRITE 0x00000800
#define VB_IS_LOBAL_COPY_VALID   0x00001000
#define VB_IS_NPATCHABLE         0x00004000
#define VB_IS_RTPATCH            0x00008000
#define VB_IS_STATIC             0x00010000
#define VB_IS_DYNAMIC            0x00020000

// Flags for call to VB_PurgeLazyFreeList() parameter dwFlags
#define VB_PLFL_FLAG_NO_FREE_MEM 0x00000000
#define VB_PLFL_FLAG_FREE_MEM    0x00000001
#define VB_PLFL_FLAG_NO_STALL    0x00000002
#define VB_PLFL_FLAG_LAZY_FREE_MIN  0x00000004


#define ATI_DEFAULT_VBUFFSIZE   (64*1024)
#define ATI_MAX_VBUFFSIZE       (16*ATI_DEFAULT_VBUFFSIZE)  // 1MB

///////////////////////////////////////////////////////////////////////////////
// Vertex buffer creation flags

#define CREATE_VB_IN_AGP              0x00000001
#define CREATE_VB_IN_LOCAL            0x00000002
#define CREATE_VB_IN_QS               0x00000004
#define CREATE_VB_INVERT_ALLOC_ORDER  0x10000000

///////////////////////////////////////////////////////////////////////////////
//  External Vertex Buffer functions

extern HRESULT VB_Create(LPD3DDEVICE pD3DDev,
                         LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                         LPDDSURFACEDESC2 lpSurfDesc2,
                         LPDDRAWI_DIRECTDRAW_GBL pDdGbl,
                         DWORD dwRequestedSize,
                         LPATIVERTEXBUFFER *pVertexBuffer);

extern void VB_Destroy(LPD3DDEVICE pD3DDev, LPATIVERTEXBUFFER pVb);

extern void VB_Swap(LPATIVERTEXBUFFER pVb, LPD3DDEVICE pD3DDev);

extern void VB_Stall(LPATIVERTEXBUFFER pVb, LPD3DDEVICE pD3DDev);

extern BOOL VB_IsVbBusy(LPATIVERTEXBUFFER pVb, LPD3DDEVICE pD3DDev);

extern VOID VB_SetTStampInfo(LPATIVERTEXBUFFER pVb, LPD3DCMDBUFF lpCmdB);

extern LPATIVERTEXBUFFER VB_PutVerticesIntoIntVB(LPATID3DCNTX pCtxt,
                                                 LPD3DTLVERTEX lpVertices,
                                                 DWORD dwVertexBytes,
                                                 DWORD dwVertexNum,
                                                 DWORD dwVertexType);

extern BOOL VB_SetupIntVB_MultiStream(LPATID3DCNTX pCtxt, INT dwBaseVtxIndex,
                                      DWORD dwMinIndex, DWORD dwVertexNum);

extern BOOL VB_SetupIntVB_SingleStream(LPATID3DCNTX pCtxt, int nBaseVertexOffset,
                                       DWORD dwMinIndex, DWORD dwVertexNum);

extern void VB_DestroyIntVB(LPATID3DCNTX pCtxt, BOOL FreeMemory);

extern void NP_VB_DestroyIntVB(LPATID3DCNTX pCtxt, LPATIVERTEXBUFFER pVb);

extern void VB_PurgeLazyFreeList(LPD3DDEVICE pD3DDev, LPATID3DCNTX pCtxt, DWORD dwFlags);

extern void VB_CleanUpContextVbs(LPD3DDEVICE pD3DDev, LPATID3DCNTX pCtxt);

extern LPATIVERTEXBUFFER VB_GetVbFromHandle(struct _D3DDEVICE *pD3DDev,
                                            DWORD dwHandle);

extern BOOL VB_RestoreFromExclusiveMode(LPATID3DCNTX lpCtxt);

// Vertex Buffer routines used for Partial Lighting Load Balancing.
extern BOOL VB_CreateSystemCopy(LPVOID lpATIDXObj, LPATIVERTEXBUFFER pVb);

extern void VB_DestroySystemCopy(LPVOID lpATIDXObj, LPATIVERTEXBUFFER pVb);

extern BOOL VB_UpdateSystemCopy(LPATIVERTEXBUFFER pVb);

extern BOOL VB_HasSystemCopy(LPATIVERTEXBUFFER pVb);

extern BOOL VB_IsSystemCopyValid(LPATIVERTEXBUFFER pVb);

extern VOID VB_InvalidateSystemCopy(LPATIVERTEXBUFFER pVb);

extern void VB_PrepVbForLobal(LPATIVERTEXBUFFER pVb);

extern BOOL VB_IsVbCulled(LPATIDXOBJECT lpATIDXObj, LPATIVERTEXBUFFER pVb, LPATID3DCNTX pCtxt);

extern void VB_PreVbForIntVB(LPATID3DCNTX pContext, void *lpBuffer,
                             void *lpVertices, DWORD dwFVFSize,
                             DWORD dwVertexNum, DWORD dwFVFType);

extern HRESULT R200DestroyAllocationCB(LPVOID pD3DDev, D3DKMT_HANDLE hAllocation);


///////////////////////////////////////////////////////////////////////////////
// Get/Set vertex buffer functions

__inline void VB_UsedByContext(LPATID3DCNTX pContext, LPATIVERTEXBUFFER pVb)
{
    if (pVb)
    {
        pVb->dwhContextID = pContext->dwhContextID;
    }
}

__inline void VB_SetContextIntVB(LPATID3DCNTX pContext, LPATIVERTEXBUFFER pVb)
{
    // TODO: Stamping the context ID early may not be necessary.
    if (pVb)
    {
        pVb->dwhContextID = pContext->dwhContextID;
    }
    pContext->lpIntVtxBuff = pVb;
}

__inline LPATIVERTEXBUFFER VB_GetContextIntVB(LPATID3DCNTX pContext)
{
    return pContext->lpIntVtxBuff;
}

// TODO: The next 5 functions need to be commented
__inline VOID VB_SetVtxSurfInfoPtr(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD_PTR dwD3DSurfInfo)
{
    lpSLCL->dwReserved1 = dwD3DSurfInfo;
}

__inline VOID VB_SetVtxBuffVidMemPtr(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, LPATIVERTEXBUFFER pVb)
{
    // Fill in Ring3 address. According to Sameer Nene at MS, the fpVidMem is not used
    // except in dx7 vb_swap that occurs at DP2 time, in which case, Ring3 address must
    // be filled for app the access the swapped vb. [xwu 09/26/01].
    lpSLCL->lpGbl->fpVidMem = (FLATPTR)pVb->lpVtxListRing3;
}

__inline VOID VB_ClearVtxSurfInfoPtr(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    lpSLCL->dwReserved1 = 0;
}

__inline VOID VB_ClearVtxBuffVidMemPtr(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL)
{
    lpSLCL->lpGbl->fpVidMem = 0;
}

_inline LPATIVERTEXBUFFER VB_GetVbPtrFromSurf(LPDDRAWI_DDRAWSURFACE_LCL lpDDSurf)
{
    return((LPATIVERTEXBUFFER)(lpDDSurf->dwReserved1));
}

__inline void VB_SetVbDirectDrawLocal(LPATIVERTEXBUFFER pVb, LPDDRAWI_DIRECTDRAW_LCL lpDDLcl)
{
    pVb->lpDDLcl = lpDDLcl;
}

__inline void VB_SetSurfaceHandle(LPATIVERTEXBUFFER pVb, DWORD dwHandle)
{
    pVb->dwHandle = dwHandle;
}


__inline LPATIVERTEXBUFFER VB_CreateSystem(LPDDRAWI_DIRECTDRAW_LCL    lpDDLcl,
                                           LPDDRAWI_DDRAWSURFACE_LCL  lpDDSLcl)
{
    HRESULT                     hr = S_OK;
    LPATIVERTEXBUFFER           pVb;
    LPDDRAWI_DDRAWSURFACE_MORE  lpSurfMore  = lpDDSLcl->lpSurfMore;
    LPATIDXOBJECT               pDeviceInfo = D3dGetATIDeviceInfoObject(lpDDLcl->lpGbl);

    pVb = (LPATIVERTEXBUFFER)pvDL_Alloc(pDeviceInfo, GetVBHdrPtr(lpDDLcl->lpGbl));
    if (pVb)
    {
        HSLASSERT(pVb->dwHandle == 0);
        
        memset(pVb, 0, sizeof(ATIVERTEXBUFFER));

        #if 0
        hr = vDdHslVideoMemoryAlloc(pDeviceInfo,
                                    lpDDLcl->lpGbl,
                                    lpDDSLcl->lpGbl->dwLinearSize,
                                    &(pVb->sVtxListData),
                                    E_VIDMEM_HEAP_AGP,
                                    (PVOID)lpDDSLcl->lpGbl->fpVidMem);
        if (FAILED(hr))
        {
            vDL_Free(GetVBHdrPtr(lpDDLcl->lpGbl), pVb);
            return NULL;
        }
        #endif

        pVb->handleType  = ATI_VERTEXBUFFER;
        pVb->lpVtxList   = (LPVOID)GetDDSurffpVidMem(lpDDSLcl);
        pVb->dwBuffFlags = VB_IS_SYS_MEM;
        pVb->QS_ListSize = GetDDSurfWidth(lpDDSLcl);
        
        pVb->dwSysVBListSize = lpDDSLcl->lpGbl->dwLinearSize;

        if (lpSurfMore->ddsCapsEx.dwCaps2 & DDSCAPS2_INDEXBUFFER)
        {
            pVb->dwBuffFlags        |= VB_IS_INDEX_BUFFER;
            pVb->dwRequestedListSize = lpDDSLcl->lpGbl->dwLinearSize;
        }
    }
    
    return pVb;
}

__inline void VB_DestroySystem(LPDDRAWI_DIRECTDRAW_LCL lpDDLcl,
                               LPATIVERTEXBUFFER       pVb)
{
    #if 0
    R200DestroyAllocationCB((LPVOID)D3dGetATIDeviceInfoObject(lpDDLcl->lpGbl)->QSHDevice,
                            pVb->sVtxListData.hSurface);
    #endif

    vDL_Free(GetVBHdrPtr(lpDDLcl->lpGbl), pVb);
}

#endif // _VERTEXBUFFER_H_


/******************************Module*****************************************\
*
*                           *******************
*                           * D3D SAMPLE CODE *
*                           *******************
*
* Copyright (c) 2003 Microsoft Corporation.  All rights reserved.
\*****************************************************************************/

//
// Thunk for context.c
//

#include <DriverSpecs.h>

__user_driver

#include "atid3ddefs.h"
#include "d3dcntx.h"
#include "atidispdd.h"
#include "drivercalls.h"
#include "dxcalls.h"
#include "d3ddevice.h"

#include "ativbinfo.h"
#include "vertexbuffer.h"

#include "atisurfinfo.h"
#include "dxcaps.h"
#include "debug.h"
#include "writerendstate.h"

#include "contextthk.h"
#include "d3dddithk.h"


void __stdcall R200SetCtxHandleList(LPATID3DCNTX pContext, DD_DIRECTDRAW_LOCAL *pDDLcl)
{
    SetCtxHandleList(pContext, pDDLcl);
}

BOOL __stdcall R200SetCtxtRT(LPATID3DCNTX pContext, DD_DIRECTDRAW_LOCAL *pDDLcl, DD_SURFACE_LOCAL *pDDSLclRT)
{
    return SetCtxtRT(pContext, pDDLcl, pDDSLclRT);
}

LPATID3DCNTX
R200ContextCreate(
    DD_DIRECTDRAW_LOCAL        *pDDLcl,
    DD_SURFACE_LOCAL           *pDDSLclRT,
    DWORD                       dwInterfaceVer,
    DWORD                       dwDxAppVersion)
{
    D3DHAL_CONTEXTCREATEDATA    ctxCreateData;

    memset(&ctxCreateData, 0, sizeof(ctxCreateData));

    ctxCreateData.dwhContext = dwInterfaceVer;   // Version of DX interface
    ctxCreateData.lpDDLcl    = pDDLcl;
    ctxCreateData.lpDDSLcl   = pDDSLclRT;
    ctxCreateData.dwPID      = dwDxAppVersion;   // Overloaded to be the Dx App version
    ctxCreateData.ddrval     = DDERR_GENERIC;

    if ((ContextCreate32(&ctxCreateData) == DDHAL_DRIVER_HANDLED) &&
        (SUCCEEDED(ctxCreateData.ddrval)))
    {
        return (GetD3DContextFromHandle(ctxCreateData.dwhContext));
    }
    else
    {
        return (NULL);
    }
}

VOID R200DestroyDevice(
    LPATIDXOBJECT lpATIDXObj,
    LPD3DDEVICE pD3DDev
    )
{
    if (pD3DDev)
    {
        int i;

        //
        // Free the HSL surface info arrays. (See hsl.c)
        // NOTE: This is necessary since vD3dHslExit() frees only the
        //       pD3DDev->D3DHSLSurfList[0]
        //
        for (i = 0; i < ContextPerBlock; i++)
        {
            if (pD3DDev->D3DHSLSurfList[i].lpD3DHSLSurfInfo)
            {
                bDdHslSharedMemFreeEx(GetATIDeviceInfo(pD3DDev),
                                      pD3DDev->D3DHSLSurfList[i].lpD3DHSLSurfInfo);
                pD3DDev->D3DHSLSurfList[i].lpD3DHSLSurfInfo = NULL;
            }
        }

        //
        // Clean up D3D device
        //
        vD3dHslExit(pD3DDev);
    }

    if (lpATIDXObj)
    {
        bDdHslSharedMemFree(lpATIDXObj);
    }
}

DWORD
R200ContextDestroy(
    LPATID3DCNTX                pR2Context)
{
    D3DHAL_CONTEXTDESTROYDATA   ctxDestroyData;
    LPATIDXOBJECT               lpATIDXObj;
    LPD3DDEVICE                 pD3DDev;
    DD_DIRECTDRAW_LOCAL        *pDDLcl;
    DDHAL_DESTROYDDLOCALDATA    ddDestroyLocal;

    //
    // Save the DD and D3D device pointers for clean up
    //
    pD3DDev    = pR2Context->pD3DDevice;
    lpATIDXObj = GetATIDeviceInfo(pD3DDev);
    pDDLcl     = (DD_DIRECTDRAW_LOCAL *)pR2Context->lpDDLcl;

    //
    // Destroy the D3D context
    //
    ctxDestroyData.dwhContext = pR2Context->dwContextIndex;
    ctxDestroyData.ddrval     = DDERR_GENERIC;

    ContextDestroy32(&ctxDestroyData);

    //
    // Destroy the DD local (surface/VB list, etc)
    //
    ddDestroyLocal.dwFlags = 0;
    ddDestroyLocal.pDDLcl  = pDDLcl;
    ddDestroyLocal.ddRVal  = DDERR_GENERIC;
    DestroyDDLocal32(&ddDestroyLocal);

    //
    // Simply free the D3D and D3D device pointers
    //
    R200DestroyDevice(lpATIDXObj, pD3DDev);

    return (DD_OK);
}

//
// Helper function to return the size of D3D command buffer preamble in BYTES
//
DWORD
GetCmdBufPreambleSize(
    LPVOID          pvCtx)
{
    LPATID3DCNTX    pD3DCtx = (LPATID3DCNTX)pvCtx;

    return (pD3DCtx->CmdBuff.dwPreambleSize << 2);
}

//
// Thunk for bDD4DISPInitDD
//

BOOL
R200D3DDevInit(
    LPVOID              pDevInfo,
    HANDLE              hDriver,
    LPATIDXOBJECT      *ppDXObj,
    LPD3DDEVICE        *ppD3DDev,
    PR200AdapterInfo    pR200AdapterInfo)
{
    BOOL            bRet;
    DD_HALINFO      ddHalInfo;
    LPATIDXOBJECT   pDXObj  = NULL;
    LPD3DDEVICE     pD3DDev = NULL;

    //
    // Initialize the caps to something sane.  We can do a better job here when the
    // adapter info callback is implemented.
    //
    memset(&ddHalInfo, 0, sizeof(ddHalInfo));
    ddHalInfo.dwSize = sizeof(DDHALINFO);
    ddHalInfo.ddCaps.dwZBufferBitDepths = BORG_HDWR_ZBBD;
    ddHalInfo.ddCaps.dwCaps2 = BORG_DDCAPS2;
    ddHalInfo.ddCaps.dwCKeyCaps = BORG_CKCAPS;
    ddHalInfo.ddCaps.dwSVBCaps     = DDCAPS_BLT | DDCAPS_CANBLTSYSMEM;
    ddHalInfo.ddCaps.dwSVBCKeyCaps = 0;
    ddHalInfo.ddCaps.dwSVBFXCaps   = 0;
    ddHalInfo.ddCaps.dwSVBRops[6]  = 0x00001000;
    ddHalInfo.ddCaps.dwSVBCaps2 = DDCAPS2_NOPAGELOCKREQUIRED;
    ddHalInfo.ddCaps.ddsCaps.dwCaps = BORG_SURF;
    ddHalInfo.ddCaps.ddsCaps.dwCaps |= DDSCAPS_EXECUTEBUFFER;
    ddHalInfo.ddCaps.dwFXCaps = BORG_FXCAPS;
    ddHalInfo.ddCaps.dwCaps = BORG_HDWR_CAPS;

    bRet = bDD4DISPInitDD(
               pDevInfo,
               (CMM_HDEVICE)pDevInfo,
               hDriver,              
               &pDXObj,
               &ddHalInfo,
               pR200AdapterInfo,
               NULL,                // lpdwNumFourCC
               NULL);               // lpdwFourCC

    if (bRet)
    {
        *ppDXObj  = pDXObj;
        *ppD3DDev = pD3DDev = pDXObj->pD3DDevice;
    }
    else
    {
        *ppD3DDev = NULL;
        return (bRet);
    }

    QSInit2((QS_HDEVICE)pDevInfo, &pD3DDev->QS_APIFunc, QS_REVISION);

    pD3DDev->pQSParam    = &pD3DDev->QSParam;
    pD3DDev->pQSCaps     = &pD3DDev->QSCaps;
    pD3DDev->pQS_APIFunc = &pD3DDev->QS_APIFunc;

    pD3DDev->QSHClient   = 0;
    if (pD3DDev->pQS_APIFunc->QSRegisterClient2((QS_HDEVICE)pDevInfo,
                                                &pD3DDev->QSHClient) != QS_OK)
    {
        bDdHslSharedMemFree(pD3DDev);
        bDdHslSharedMemFree(pDXObj);
        *ppDXObj = NULL;
        *ppD3DDev = NULL;
        return (FALSE);
    }

    return (TRUE);
}

//
// Adpated from vertexbuffer.c
//

BOOL
R200CreateATIVtxBufInfo(
    LPATIDXOBJECT       pATIDXObj,
    DD_SURFACE_LOCAL   *pDDSLcl)
{
    LPATIVERTEXBUFFER   pVB;

    //
    // BUBUG for surfaces, both dwReserved1s are used
    //

    pVB = (LPATIVERTEXBUFFER)pDdHslSharedMemCallocEx(pATIDXObj,
                                                     sizeof(ATIVERTEXBUFFER));
    if (! pVB)
    {
        return (FALSE);
    }

    memcpy(pVB,
           (LPVOID)pDDSLcl->lpGbl->dwReserved1,
           sizeof(ATIVERTEXBUFFER));


    pVB->lpVtxList = pVB->lpVtxListRing3;

    //
    // Hook the pVB into surface structure
    //
    pDDSLcl->lpGbl->dwReserved1 = (ULONG_PTR)pVB;

    return (TRUE);
}

BOOL
R200CreateATISurfInfo(
    LPATIDXOBJECT       pATIDXObj,
    DWORD               dwNumSurfaces,
    DD_SURFACE_LOCAL   *pDDSLcl)
{
    DD_SURFACE_LOCAL   *pCurDDSLcl;
    UINT                i;
    LPATISURFINFO       pSurfInfo;

    //
    // Nothing need to be done for system memory resources
    //
    if (pDDSLcl->ddsCaps.dwCaps & DDSCAPS_SYSTEMMEMORY)
    {
        return (TRUE);
    }

    for (i = 0, pCurDDSLcl = pDDSLcl; i < dwNumSurfaces; i++, pCurDDSLcl++)
    {
        if (pCurDDSLcl->ddsCaps.dwCaps & DDSCAPS_EXECUTEBUFFER)
        {
            if (! R200CreateATIVtxBufInfo(pATIDXObj, pCurDDSLcl))
            {
                return (FALSE);
            }
            else
            {
                continue;
            }
        }

        //
        // BUBUG for surfaces, both dwReserved1s are used
        //

        pSurfInfo = (LPATISURFINFO)
                    pDdHslSharedMemCallocEx(pATIDXObj,
                                            sizeof(ATISURFINFO) +
                                                sizeof(HSLSURFINFO));
        if (! pSurfInfo)
        {
            return (FALSE);
        }

        memcpy(pSurfInfo,
               (LPVOID)pCurDDSLcl->lpGbl->dwReserved1,
               sizeof(ATISURFINFO));

        pCurDDSLcl->lpGbl->dwReserved1 = (ULONG_PTR)pSurfInfo;

        pCurDDSLcl->dwReserved1 = (ULONG_PTR)(pSurfInfo + 1);
    }

    return (TRUE);
}

HRESULT
R200HwFlush(
    LPATID3DCNTX                pContext,
    LPBYTE                      pDP2Command,
    DWORD                       dwDP2CmdSize,
    LPBYTE                      pUMVertices,
    BOOL                        bToKMD)
{
    D3DHAL_DRAWPRIMITIVES2DATA  dp2Data;
    DD_SURFACE_LOCAL            ddSLclCmd;
    DD_SURFACE_GLOBAL           ddSGblCmd;
    DD_SURFACE_MORE             ddSMoreCmd;

    //
    // Flush the internal DP2 stream if necessary
    //
    if (dwDP2CmdSize)
    {
        memset(&dp2Data,    0, sizeof(dp2Data));
        memset(&ddSLclCmd,  0, sizeof(ddSLclCmd));
        memset(&ddSGblCmd,  0, sizeof(ddSGblCmd));
        memset(&ddSMoreCmd, 0, sizeof(ddSMoreCmd));

        // Set up the DP2 command stream surface
        ddSLclCmd.lpGbl      = &ddSGblCmd;
        ddSLclCmd.lpSurfMore = &ddSMoreCmd;
        ddSGblCmd.fpVidMem   = (FLATPTR)pDP2Command;

        dp2Data.dwhContext      = pContext->dwContextIndex;
        dp2Data.lpDDCommands    = &ddSLclCmd;
        dp2Data.dwCommandLength = dwDP2CmdSize;

        //
        // Set up the user memory vertex pointer
        //
        if (pUMVertices)
        {
            dp2Data.lpVertices  = pUMVertices;
            dp2Data.dwFlags    |= D3DHALDP2_USERMEMVERTICES;
        }

        dp2Data.dwVertexType = D3DFVF_XYZ | D3DFVF_NORMAL;

        DrawPrimitives232(&dp2Data);
    }
    else
    {
        dp2Data.ddrval = DD_OK;
    }

    //
    // Flush the command left in the current command buffer if requested
    //

    if (bToKMD)
    {
        dp2Data.ddrval = FlushCmdBuff(&pContext->CmdBuff);
    }

    return (dp2Data.ddrval);
}


//
// Get the allocation handle for a surface
//
D3DKMT_HANDLE
R200GetSurfaceAllocHandle(
    LPATID3DCNTX        pD3DCtxt,
    DWORD               hSurface)
{
    LPATISURFCNTX       pD3DSurf;

    pD3DSurf = SurfaceHandleToCntx(hSurface, pD3DCtxt);

    //
    // This call is only valid for surface
    //
    if ((pD3DSurf) && (pD3DSurf->handleType == ATI_SURFACE))
    {
        return (pD3DSurf->hAllocation);
    }

    return (0);
}


//
// Check whether a vertex buffer is idle
//
BOOL
CheckVbuffTimeStampRetired(
    LPD3DDEVICE         pD3DDev,
    LPATIVERTEXBUFFER   pVb,
    DWORD               dwFlags)
{
    LPATIDXOBJECT       pATIDXObj = GetATIDeviceInfo(pD3DDev);
    LPATID3DCNTX        pCtxt;
    D3DCMDBUFF         *pCmdBuf;
    HRESULT             hr;
    LPVOID              lpVBData;
    D3DKMT_HANDLE       hAllocation;

    //
    // A VB is idle when it is not even bound to a context
    //
    if (! pVb->dwhContextID)
    {
        return (TRUE);
    }

    //
    // Get the context back
    //
    pCtxt = GetD3DContextPointer(pD3DDev, pVb->dwhContextID);
    if (! pCtxt)
    {
        return (TRUE);
    }

    //
    // NOTE: The DDI level driver code has flushed the its DP2 command batch,
    //       so it doesn't have to be worried here.
    //

    pCmdBuf = &pCtxt->CmdBuff;
    //
    // Check if the VB is used in the current HW command buffer
    //
    if (pVb->dwVbuffCBWrapStamp >=
            pD3DDev->TimeStampArray[pVb->dwVbuffPendingCB_ID].dwWrapStamp)
    {
        if (pVb->dwVbuffPendingCB_ID == pCmdBuf->dwPendingCB_ID)
        {
            if (pCmdBuf->dwCBLeftDW <
                (pCmdBuf->pQSParam->dwCmdBufSizeInDWORDs - pCmdBuf->dwPreambleSize))
            {
                return (FALSE);
            }
            else
            {
                //
                // HW command buffer contains only preamble
                //
                return (TRUE);
            }
        }
    }

    //
    // Call the KDM to probe if the VB is busy using DONOTWAIT lock flag
    //
    hAllocation = pVb->sVtxListData.hAllocation;
    hr = R200LockAllocationCB((LPVOID)pATIDXObj->QSHDevice,
                              &hAllocation,
                              DDLOCK_DONOTWAIT,
                              FALSE,
                              0,
                              &lpVBData);
    if (SUCCEEDED(hr))
    {
        //
        // The VB is not busy, update the VB pointer
        //
        pVb->lpVtxListRing3 = lpVBData;

        return (TRUE);
    }

    return (FALSE);
}

HRESULT APIENTRY
Flush(
    HANDLE              pDriverInstance);

__inline void
VB_Stall(
    LPATIVERTEXBUFFER   pVb,
    LPD3DDEVICE         pD3DDev)
{
    HRESULT             hr;

    if (! CheckVbuffTimeStampRetired(pD3DDev, pVb, QS_FLAG_PRIMARY))
    {
        Flush(pVb->lpDDLcl);    // The CD3DContext object
    }
}

HRESULT
R200DisableColorKey(
    LPATID3DCNTX    pD3DCtx,
    DWORD           dwExHandle)
{
    LPATISURFCNTX   pD3DSurf;

    //
    // No action needed if no texture is in use
    //
    if (! dwExHandle)
    {
        return (S_OK);
    }

    pD3DSurf = SurfaceHandleToCntx(dwExHandle, pD3DCtx);
    if (! pD3DSurf)
    {
        return (DDERR_INVALIDOBJECT);
    }

    pD3DSurf->dwFlags &= (~DDRAWISURF_HASCKEYSRCBLT);

    return (S_OK);
}


HRESULT
R200SetSurfColorKeyVal(
    LPATID3DCNTX    pD3DCtx,
    DWORD           dwExHandle,
    DWORD           dwColorKeyVal)
{
    LPATISURFCNTX   pD3DSurf;

    pD3DSurf = SurfaceHandleToCntx(dwExHandle, pD3DCtx);
    if (! pD3DSurf)
    {
        return (DDERR_INVALIDOBJECT);
    }

    pD3DSurf->dwFlags |= DDRAWISURF_HASCKEYSRCBLT;
    pD3DSurf->ddckCKSrcBlt.dwColorSpaceLowValue = dwColorKeyVal;

    return (S_OK);
}


void UpdateHandleInCmdBuf(LPATID3DCNTX pD3DCtxt, LPATISURFCNTX pD3DSurf)
{
    DWORD   dwResIdx;
    PDWORD  pdwPm4;

    for (dwResIdx = 0; dwResIdx < D3D_RES_ALL; dwResIdx++)
    {
        if (pD3DCtxt->resSurfArray[dwResIdx] == (PVOID)pD3DSurf)
        {
            // Handle has changed so put new handle in the stream
            if (dwResIdx != D3D_RES_INDEX_BUFFER)
            {
                // Surface or VB
                pdwPm4=GetPM4Entries((1 + sizeof(D3DKMT_HANDLE)/sizeof(DWORD)), &pD3DCtxt->CmdBuff);
            }
            else
            {
                // When we write IB into stream we also put GUI DMA SRC handle
                pdwPm4=GetPM4Entries(2 * (1 + sizeof(D3DKMT_HANDLE)/sizeof(DWORD)), &pD3DCtxt->CmdBuff);
            }

            // Now place handle back into command stream
            if (pD3DSurf->handleType == ATI_SURFACE)
            {
                if (dwResIdx >= D3D_RES_CUBEMAP_0_FACE_1 && dwResIdx <= D3D_RES_CUBEMAP_0_FACE_5 ||
                    dwResIdx >= D3D_RES_CUBEMAP_1_FACE_1 && dwResIdx <= D3D_RES_CUBEMAP_1_FACE_5 ||
                    dwResIdx >= D3D_RES_CUBEMAP_2_FACE_1 && dwResIdx <= D3D_RES_CUBEMAP_2_FACE_5 ||
                    dwResIdx >= D3D_RES_CUBEMAP_3_FACE_1 && dwResIdx <= D3D_RES_CUBEMAP_3_FACE_5 ||
                    dwResIdx >= D3D_RES_CUBEMAP_4_FACE_1 && dwResIdx <= D3D_RES_CUBEMAP_4_FACE_5 ||
                    dwResIdx >= D3D_RES_CUBEMAP_5_FACE_1 && dwResIdx <= D3D_RES_CUBEMAP_5_FACE_5)
                {
                    EmbedCubeMapFaceHandleIntoCmdBuf(pdwPm4, pD3DCtxt, (dwResIdx-D3D_RES_TEXTURE_0)/6, (dwResIdx-D3D_RES_TEXTURE_0)%6);
                }
                else
                {
                    EmbedSurfHandleIntoCmdBuf(pdwPm4, pD3DCtxt, dwResIdx);
                }
            }
            else
            {
                // IB or VB
                if (dwResIdx != D3D_RES_INDEX_BUFFER)
                {
                    EmbedVBHandleIntoCmdBuf(pdwPm4, pD3DCtxt, dwResIdx);
                }
                else
                {
                    EmbedIBHandleIntoCmdBuf(pdwPm4, pD3DCtxt);
                }
            }

            SubmitPM4EntriesToHw((1 + sizeof(D3DKMT_HANDLE)/sizeof(DWORD)), 0, &pD3DCtxt->CmdBuff);

            // We have now placed the valid handle in the command stream, the driver thinks that
            // the registers that use these handles have already been setup so we need
            // to ensure the register write appears in the command stream so it can be patched
            // correctly before used.
            // For simplicity we will just dirty all the 3D register setup, a performance optimization
            // would be to just to dirty the register this resource type uses.
            SetAllDirtyBits(pD3DCtxt);
            memset(&pD3DCtxt->sVxtPrevState, 0xff, sizeof(pD3DCtxt->sVxtPrevState));
        }
    }

    return;
}

HRESULT
R200LockResource(
    LPATID3DCNTX        pD3DCtxt,
    D3DDDIARG_LOCK*     pLockData)
{
    LPATIDXOBJECT       lpATIDXObj = GetATIDeviceInfo(pD3DCtxt->pD3DDevice);
    LPD3DDEVICE         lpD3DDev   = GetD3DDevice(pD3DCtxt);
    DWORD               dwExHandle = (DWORD)(DWORD_PTR)pLockData->hResource;
    LPATISURFCNTX       pD3DSurf;
    PR2UMSurfaceHandle  pR2UMSurfHandle;
    DWORD               dwSubResourceIndex;
    DDHSLSURFACEDESC    ddHslSurfDesc;
    UINT                LockCBFlags = 0;

    //
    // Retrieve the private surface structure
    //
    pD3DSurf = SurfaceHandleToCntx(dwExHandle, pD3DCtxt);
    if (! pD3DSurf)
    {
        return (DDERR_INVALIDOBJECT);
    }

    dwSubResourceIndex = pLockData->SubResourceIndex;

    HSLDPF(E_LDDM_LOCK, "Locking resource UM handle 0x%lx, Suf 0x%lx", dwExHandle, pD3DSurf);

    if (pLockData->Flags.Discard)
    {
        LockCBFlags |= DDLOCK_DISCARDCONTENTS;
    }

    //
    // Surface and vertex buffer are handled differently
    //
    if (pD3DSurf->handleType == ATI_SURFACE)
    {
        //
        // Special handling for locking a cubemap face
        //
        if (pD3DSurf->ddsCapsEx.dwCaps2 & DDSCAPS2_CUBEMAP)
        {
            DWORD   dwFaceExHandle;

            //
            // Pick the right cubemap face and level index within the face
            //
            dwSubResourceIndex = pLockData->SubResourceIndex %
                                     pD3DSurf->NativeTextureInfo.dwMipCount;

            dwFaceExHandle = dwExHandle +
                             (pLockData->SubResourceIndex /
                              pD3DSurf->NativeTextureInfo.dwMipCount);
            pD3DSurf = SurfaceHandleToCntx(dwFaceExHandle,
                                           pD3DCtxt);

            if (pD3DSurf == NULL)
            {
                return DDERR_INVALIDOBJECT;
            }
        }

        if ((pD3DSurf->ddsCaps.dwCaps & DDSCAPS_TEXTURE) &&
            (dwSubResourceIndex > pD3DSurf->NativeTextureInfo.dwMipCount))
        {
            //
            // A wrong mip level is specified.
            //
            return (DDERR_INVALIDPARAMS);
        }

        if ((pD3DSurf->ddsCaps.dwCaps & DDSCAPS_FLIP) &&
            (dwSubResourceIndex > 0))
        {
            //
            // Find the specified back buffer in a full-screen swap chain
            //
            pD3DSurf = SurfaceHandleToCntx(dwExHandle + dwSubResourceIndex,
                                           pD3DCtxt);
            if ((! pD3DSurf) || (! (pD3DSurf->ddsCaps.dwCaps & DDSCAPS_FLIP)))
            {
                return (DDERR_INVALIDPARAMS);
            }

            //
            // Set the sub level within the back buffer to 0
            //
            dwSubResourceIndex = 0;
        }

        LoadHSLSurfaceDesc(lpD3DDev,
                           pD3DSurf,
                           &ddHslSurfDesc,
                           dwSubResourceIndex,
                           0,                   // Blt depth
                           pD3DCtxt->dwDXInterfaceVersion);

        if ((! ddHslSurfDesc.fpVidMem) || (! ddHslSurfDesc.lPitch))
        {
            return (DDERR_INVALIDPARAMS);
        }

        if (pD3DSurf->ddsCaps.dwCaps & DDSCAPS_SYSTEMMEMORY)
        {

            pLockData->pSurfData = (PVOID)ddHslSurfDesc.fpVidMem;
            pLockData->Pitch     = ddHslSurfDesc.lPitch;
            pLockData->SlicePitch = ddHslSurfDesc.lSlicePitch;

            return (DD_OK);
        }
        else
        {
            LPATISURFINFO   pDDSurf, pDDSurfSubLevel;
            HRESULT         hr;
            BOOL            Tiled;
            D3DKMT_HANDLE   hAllocation;

            //
            // Get the KM allocation handle
            //
            pDDSurf         = (LPATISURFINFO)pD3DSurf->hATISurfInfoHandle;
            pR2UMSurfHandle = (R2UMSurfaceHandle *)pDDSurf->hSurface;

            pDDSurfSubLevel = (LPATISURFINFO)ddHslSurfDesc.hATISurfInfoHandle;
            if ((pLockData->SubResourceIndex) && (! pDDSurfSubLevel))
            {
                return (DDERR_INVALIDPARAMS);
            }

            //
            // Check if surface is macro or micro tiled
            //
            Tiled = (IsSurfTiled2(pDDSurf) || IsSurfMicroTiled2(pDDSurf));


            //
            // Call the KM to lock the allocation
            //
            hAllocation=pR2UMSurfHandle->hAllocation;
            hr = R200LockAllocationCB((LPVOID)lpATIDXObj->QSHDevice,
                                      &hAllocation,
                                      LockCBFlags,
                                      Tiled,
                                      dwSubResourceIndex,
                                      &pLockData->pSurfData);
            if (SUCCEEDED(hr))
            {
                DWORD   dwIdx;

                //
                // Adjust the surface pointer to the sublevel
                //
                if (! pDDSurfSubLevel || dwSubResourceIndex == 0)
                {
                    pLockData->Pitch = ddHslSurfDesc.lPitch;
                    pLockData->SlicePitch = ddHslSurfDesc.lSlicePitch;
                }
                else
                {
                    // MipMap sublevel
                    ((LPBYTE)(pLockData->pSurfData)) += pDDSurfSubLevel->dwSurfOffset;
                    pLockData->Pitch = pDDSurfSubLevel->dwColorPitch * pDDSurfSubLevel->dwBytesPerPixel;
                    pLockData->SlicePitch = 0;
                }

                if (pLockData->Flags.RangeValid)
                {
                    ((BYTE*)(pLockData->pSurfData)) +=
                        pLockData->Range.Offset * ddHslSurfDesc.dwBPP / 8;
                }
                else
                if (pLockData->Flags.AreaValid)
                {
                    // NOTE: Production driver should calculate displasment correctly for DXT and YUV formats
                    ((BYTE*)(pLockData->pSurfData)) +=
                        pLockData->Area.top * pLockData->Pitch
                        + pLockData->Area.left * ddHslSurfDesc.dwBPP / 8;
                }
                else
                if (pLockData->Flags.BoxValid)
                {
                    ((BYTE*)(pLockData->pSurfData)) +=
                        pLockData->Box.Front * pLockData->SlicePitch
                        + pLockData->Box.Top * pLockData->Pitch
                        + pLockData->Box.Left * ddHslSurfDesc.dwBPP / 8;
                }

                pD3DSurf->dwLockCount++;

                if ((LockCBFlags & DDLOCK_DISCARDCONTENTS) == 0)
                {
                    //
                    // So surface is locked, we need to ensure that this surface is not reference in a KM resource
                    // list passed to VidMm as it will fail if surface is under lock.
                    // So for each resource slot this surface is we will NULL the resource slot and record which
                    // resource slots it was in so we can replace them on unlock
                    //
                    // NOTE we do not do this for discard locks as surface will be renamed and used by the hw

                    for (dwIdx=0; dwIdx < D3D_RES_ALL; dwIdx++)
                    {
                        PDWORD  pdwPm4;
                        BOOL    bFlushed=FALSE;

                        //Is this surface in current resource slot
                        if (pD3DCtxt->resSurfArray[dwIdx] == (PVOID)pD3DSurf)
                        {
                            // We flushed at start of lock code, but the preable will have the resource handle in it
                            // so if we discard the preable and start again we will not reference the locked handle
                            // in the command buffer
                            GetNewCmdBuff(&pD3DCtxt->CmdBuff, TRUE, FALSE);

                            // Now set the bit in bit field to remeber that this surface was in the resource slot
                            if (dwIdx <= 63)
                            {
                                pD3DSurf->liLockResSlotMaskLow|= ((ULONGLONG)1) << dwIdx;
                            }
                            else
                            {
                                pD3DSurf->liLockResSlotMaskHigh|= ((ULONGLONG)1) << (dwIdx-64);
                            }
                        }
                    }
                }
                else
                {
                    // Discard lock so VidMm handle will change
                    if (LockCBFlags & DDLOCK_DISCARDCONTENTS)
                    {
                        // Store new VidMm handle
                        R200SetVidMmAllocationHandleForSurface(pD3DSurf, hAllocation);

                        // Update this surface handle in stream if it is currently in a res slot
                        UpdateHandleInCmdBuf(pD3DCtxt, pD3DSurf);
                    }
                }
            }
            return (hr);
        }
    }
    else if (pD3DSurf->handleType == ATI_VERTEXBUFFER)
    {
        LPATIVERTEXBUFFER   pVB = (ATIVERTEXBUFFER *)pD3DSurf;


        if (pVB->dwBuffFlags & VB_IS_SYS_MEM)
        {
            pLockData->pSurfData = (PVOID)pVB->lpVtxList;
            if (pLockData->Flags.RangeValid)
            {
                ((BYTE*)(pLockData->pSurfData)) += pLockData->Range.Offset;
            }

            return (DD_OK);
        }
        else
        {
            HRESULT         hr;
            D3DKMT_HANDLE   hAllocation;

            //
            // Translate the lock flags
            //

            if (pLockData->Flags.NoOverwrite)
            {
                LockCBFlags |= DDLOCK_DONOTWAIT;
            }

            pR2UMSurfHandle = (R2UMSurfaceHandle *)pVB->sVtxListData.hSurface;

            //
            // Call the KM to lock the allocation
            //
            hAllocation = pR2UMSurfHandle->hAllocation;
            hr = R200LockAllocationCB((LPVOID)lpATIDXObj->QSHDevice,
                                      &hAllocation,
                                      LockCBFlags,
                                      FALSE,
                                      0,
                                      &pLockData->pSurfData);
            if (SUCCEEDED(hr))
            {
                // If discard then VidMm handle will change
                if (LockCBFlags & DDLOCK_DISCARDCONTENTS)
                {
                    // Save new VidMm handle we got from lock
                    R200SetVidMmAllocationHandleForVB(pVB, hAllocation);

                    // Update this surface handle in stream if it is currently in a res slot
                    UpdateHandleInCmdBuf(pD3DCtxt, pD3DSurf);
                }

                pVB->lpVtxListRing3 = pLockData->pSurfData;;

                if (pLockData->Flags.RangeValid)
                {
                    ((BYTE*)(pLockData->pSurfData)) += pLockData->Range.Offset;
                }
            }

            return hr;
        }
    }
    else
    {
#ifdef DEBUG
        DebugBreak();
#endif
        return (DDERR_INVALIDOBJECT);
    }
}

DWORD
R200GetSubLevelExHandle(
    LPATID3DCNTX    pD3DCtxt,
    HANDLE          hResource,
    DWORD           dwSubLevel)
{
    LPATISURFCNTX   pD3DSurf;
    DWORD           dwNumFaces;

    //
    // Return NULL handle if the render target is set to NULL resource
    //
    if (! hResource)
    {
        return (0);
    }

    //
    // Get the D3D surface context for the resource
    //
    pD3DSurf = SurfaceHandleToCntx((DWORD)(DWORD_PTR)hResource, pD3DCtxt);
    if (! pD3DSurf)
    {
        return (0);
    }

    //
    // Render targets of flip chain are created with the same resource handle
    //
    if (pD3DSurf->ddsCaps.dwCaps & DDSCAPS_3DDEVICE)
    {
        return (((DWORD)(DWORD_PTR)hResource) + dwSubLevel);
    }

    //
    // Other Single level resource
    //
    if (! ((pD3DSurf->ddsCaps.dwCaps & DDSCAPS_MIPMAP) ||
           (pD3DSurf->ddsCapsEx.dwCaps2 & DDSCAPS2_CUBEMAP)))
    {
        HSLASSERT(! dwSubLevel);
        return ((DWORD)(DWORD_PTR)hResource);
    }

    //
    // One of levels of the cubemap faces is used as render target
    //
    if (pD3DSurf->ddsCapsEx.dwCaps2 & DDSCAPS2_CUBEMAP)
    {
        dwNumFaces = 6;
    }
    else
    {
        dwNumFaces = 1;
    }

    if (dwSubLevel < (dwNumFaces*pD3DSurf->NativeTextureInfo.dwMipCount))
    {
        return (((DWORD)(DWORD_PTR)hResource) + dwSubLevel);
    }

    return (0);
}

//
// NOTE: pD3DSurf could be a surface or vertex buffer
//
HRESULT
R200DestroyAllocation(
    LPATID3DCNTX            pD3DCtxt,
    LPATISURFCNTX           pD3DSurf)
{
    LPATIDXOBJECT           lpATIDXObj = GetATIDeviceInfo(pD3DCtxt->pD3DDevice);
    PR2UMSurfaceHandle      pR2UMSurfHandle = NULL;
    HRESULT                 hr = DD_OK;

    //
    // Clean up and free UMD surface
    // NOTE: The pD3DSurf itself is free when D3D context is freed.
    //
    //
    if (pD3DSurf->handleType == ATI_SURFACE)
    {
        //
        // Get the UMD video memory handle
        //
        pR2UMSurfHandle = GetUMSurfaceHandle(pD3DSurf);

        //
        // Call the KMD to free the resources
        //
        if (pR2UMSurfHandle)
        {
            hr = R200DestroyAllocationCB((LPVOID)lpATIDXObj->QSHDevice,
                                         pR2UMSurfHandle->hAllocation);

            //
            // Free the UM surface handle
            //
#ifdef PRIVATE_HEAP
            HeapFree(g_Heap, 0, pR2UMSurfHandle);
#else
            LocalFree(pR2UMSurfHandle);
#endif
        }

        if (pD3DSurf->ddsCaps.dwCaps & DDSCAPS_TEXTURE)
        {
            UINT i;

            for (i = 0; i < pD3DSurf->ActiveTextureInfo.dwMipCount; i++)
            {
                if (pD3DSurf->hMipATISurfInfoHandle[i])
                {
#ifdef PRIVATE_HEAP
                    HeapFree(g_Heap, 0, pD3DSurf->hMipATISurfInfoHandle[i]);
#else
                    LocalFree(pD3DSurf->hMipATISurfInfoHandle[i]);
#endif
                    pD3DSurf->hMipATISurfInfoHandle[i] = NULL;
                }
            }

            pD3DSurf->hATISurfInfoHandle = NULL;
        }
        else
        {
            //
            // For surface that is not texture (RT, ZBuf, Offscreen Plain, etc)
            //
            if (pD3DSurf->hATISurfInfoHandle)
            {
#ifdef PRIVATE_HEAP
                HeapFree(g_Heap, 0, pD3DSurf->hATISurfInfoHandle);
#else
                LocalFree(pD3DSurf->hATISurfInfoHandle);
#endif
                pD3DSurf->hATISurfInfoHandle = NULL;
            }
        }

        //
        // Free the HSL surface structure
        //
        if (pD3DSurf->hHSLSurfInfoHandle)
        {
            DeallocateD3DHSLSurfSlot(pD3DCtxt->pD3DDevice, pD3DSurf->hHSLSurfInfoHandle);
            pD3DSurf->hHSLSurfInfoHandle = NULL;
        }
    }
    else if (pD3DSurf->handleType == ATI_VERTEXBUFFER)
    {
        LPATIVERTEXBUFFER   pVB = (LPATIVERTEXBUFFER)pD3DSurf;

        //
        // Destroy the verter buffer
        //
        if (pVB->dwBuffFlags & VB_IS_SYS_MEM)
        {
            LPATISURFHANDLE         lpSurfHandleList = pD3DCtxt->pSurfHandle;
            LPDDRAWI_DIRECTDRAW_LCL lpDDLcl = lpSurfHandleList->lpDDLcl;

            //
            // Disassociate from the handle list
            //
            CSExDisassociateSurfCntx(lpDDLcl,
                                     lpSurfHandleList,
                                     pVB->dwHandle,
                                     (LPATISURFCNTX)pVB);

            VB_DestroySystem(lpDDLcl, pVB);
        }
        else
        {
            hr = dD3dHslDestroyVertexBuffs(pD3DCtxt->pD3DDevice, pVB);
        }
    }

    return (hr);
}

HRESULT
R200GetSurfaceOffsetInfo(
    LPATID3DCNTX    pD3DCtxt,
    HANDLE          hResource,
    D3DKMT_HANDLE  *pAllocation,
    DWORD          *pPitchY,
    DWORD          *pPitchUV,
    DWORD          *pWidth,
    DWORD          *pHeight,
    DWORD          *pOffsetU,
    DWORD          *pOffsetV)
{
    LPATISURFCNTX           pD3DSurf;

    pD3DSurf = SurfaceHandleToCntx((DWORD)(DWORD_PTR)hResource, (LPATID3DCNTX)pD3DCtxt);
    if (! pD3DSurf)
    {
        return (DDERR_INVALIDOBJECT);
    }

    *pAllocation = pD3DSurf->hAllocation;
    *pWidth      = pD3DSurf->dwWidth;
    *pHeight     = pD3DSurf->dwHeight;

    if (pD3DSurf->ddpfSurface.dwFourCC == FOURCC_YV12)
    {
        *pPitchY  = pD3DSurf->lPitch;
        *pPitchUV = pD3DSurf->lPitch / 2;
        *pOffsetV = pD3DSurf->lPitch * pD3DSurf->dwHeight;
        *pOffsetU = (*pOffsetV) + pD3DSurf->dwHeight* pD3DSurf->lPitch /4;
    }

    return S_OK;
}

#ifndef KM_SYSMEM_PRESENT
D3DKMT_HANDLE
R200GetAllocationHandle(
    LPATID3DCNTX        pCtx,
    DWORD               dwExHandle,
    LONG               *plPitch)
{
    LPATISURFCNTX       pD3DSurf;
    LPATISURFINFO       pDDSurf;
    R2UMSurfaceHandle  *pR2UMSurfHandle;

    pD3DSurf = SurfaceHandleToCntx(dwExHandle, pCtx);
    if ((! pD3DSurf) || (ATI_SURFACE != pD3DSurf->handleType))
    {
        return (0);
    }

    //
    // Get the KM allocation handle
    //
    pDDSurf = (LPATISURFINFO)pD3DSurf->hATISurfInfoHandle;
    if (! pDDSurf)
    {
        return (0);
    }
    pR2UMSurfHandle = (R2UMSurfaceHandle *)pDDSurf->hSurface;
    if (! pR2UMSurfHandle)
    {
        return (0);
    }

    //
    // Set the return value
    //
    *plPitch = pD3DSurf->lPitch;
    return (pR2UMSurfHandle->hAllocation);
}
#endif

BOOL R200SetVidMmAllocationHandleForSurface(LPATISURFCNTX pD3DSurf, D3DKMT_HANDLE hAllocation)
{
    R2UMSurfaceHandle  *pR2UMSurfHandle;
    LPATISURFINFO       pDDSurf;

    if ((! pD3DSurf) || (ATI_SURFACE != pD3DSurf->handleType))
    {
        return FALSE;
    }

    pDDSurf = (LPATISURFINFO)pD3DSurf->hATISurfInfoHandle;
    if (! pDDSurf)
    {
        return FALSE;
    }
    pR2UMSurfHandle = (R2UMSurfaceHandle *)pDDSurf->hSurface;
    if (! pR2UMSurfHandle)
    {
        return FALSE;
    }

    // Check all the different stored values of this allocation match
    if (pR2UMSurfHandle->hAllocation != pD3DSurf->hAllocation || pD3DSurf->hAllocation != pDDSurf->hAllocation)
    {
        DBG_BREAK;
    }

    if (pR2UMSurfHandle->hAllocation == hAllocation)
    {
        DBG_BREAK;
    }

    // Update handles
    pR2UMSurfHandle->hAllocation = hAllocation;
    pD3DSurf->hAllocation = hAllocation;
    pDDSurf->hAllocation = hAllocation;

    return TRUE;
}



BOOL R200SetVidMmAllocationHandleForVB(LPATIVERTEXBUFFER pVB, D3DKMT_HANDLE hAllocation)
{
    R2UMSurfaceHandle  *pR2UMSurfHandle;

    if (!pVB || pVB->handleType != ATI_VERTEXBUFFER)
    {
        DBG_BREAK;
        return FALSE;
    }

    pR2UMSurfHandle = (R2UMSurfaceHandle *)pVB->sVtxListData.hSurface;
    if (!pR2UMSurfHandle)
    {
        return FALSE;
    }

    // Check all the different stored values of this allocation match
    if (pR2UMSurfHandle->hAllocation != pVB->sVtxListData.hAllocation)
    {
        DBG_BREAK;
    }

    if (pR2UMSurfHandle->hAllocation == hAllocation)
    {
        DBG_BREAK;
    }

    // Update handles
    pR2UMSurfHandle->hAllocation = hAllocation;
    pVB->sVtxListData.hAllocation = hAllocation;

    return TRUE;
}


void R200GetNewCmdBuff(LPATID3DCNTX pD3DCtxt, BOOL bWrite3DContex, BOOL bVMST)
{
    GetNewCmdBuff(&pD3DCtxt->CmdBuff, bWrite3DContex, bVMST);
}

void R200RemoveResourceFromContext(LPATID3DCNTX pD3DCtxt, DWORD dwExHandle)
{
    LPATISURFCNTX   pD3DSurf;
    DWORD           dwIdx;

    pD3DSurf = SurfaceHandleToCntx(dwExHandle, pD3DCtxt);
    if (pD3DSurf == NULL)
    {
        return;
    }

    for (dwIdx=0; dwIdx < D3D_RES_ALL; dwIdx++)
    {
        //Is this surface in current resource slot
        if (pD3DCtxt->resSurfArray[dwIdx] == (PVOID)pD3DSurf)
        {
            pD3DCtxt->resSurfArray[dwIdx] = NULL;
        }
    }
}


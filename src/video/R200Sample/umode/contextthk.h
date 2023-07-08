/******************************Module*Header**********************************\
*
*                           *******************
*                           * D3D SAMPLE CODE *
*                           *******************
*

* Copyright (c) 2003 Microsoft Corporation.  All rights reserved.
\*****************************************************************************/

VOID
LoadHSLSurfaceDesc(
    LPD3DDEVICE         lpD3DDev,
    LPATISURFCNTX       lpSurfCntx,
    LPDDHSLSURFACEDESC  lpddHslSurfDesc,
    DWORD               dwMipLevel,
    DWORD               dwVolBltDepth,
    ULONG_PTR           dwDXInterfaceVersion);

HRESULT APIENTRY
Flush(
    HANDLE              pDriverInstance);

HRESULT 
R200LockAllocationCB(
    LPVOID          pD3DDev,
    D3DKMT_HANDLE*  phAllocation,
    DWORD           dwLockFlags,
    BOOL            Tiled,
    DWORD           dwLockPriData,
    PVOID          *ppAllocation);

BOOL R200SetVidMmAllocationHandleForSurface( 
    LPATISURFCNTX       pD3DSurf,
    D3DKMT_HANDLE       hAllocation);

BOOL R200SetVidMmAllocationHandleForVB(
    LPATIVERTEXBUFFER pVB, 
    D3DKMT_HANDLE hAllocation);

void UpdateHandleInCmdBuf(
    LPATID3DCNTX pD3DCtxt, 
    LPATISURFCNTX pD3DSurf);

HRESULT
R200LockResource(
    LPATID3DCNTX        pD3DCtxt,
    D3DDDIARG_LOCK*     pLockData);

HRESULT
R200CreateAllocationCB(
    LPVOID                      pD3DDev,
    R2DDICreateAllocationData  *pR2AllocData,
    D3DKMT_HANDLE              *phAllocation,
    PVOID                       pSysMem);

DWORD
R200GetSubLevelExHandle(
    LPATID3DCNTX    pD3DCtxt,
    HANDLE          hResource,
    DWORD           dwSubLevel);

HRESULT
R200DestroyAllocation(
    LPATID3DCNTX            pD3DCtxt,
    LPATISURFCNTX           pD3DSurf);


HRESULT
R200UnlockAllocationCB(
    LPVOID          pD3DDev,
    D3DKMT_HANDLE   hAllocation);

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
    DWORD          *pOffsetV);

#ifndef KM_SYSMEM_PRESENT
D3DKMT_HANDLE
R200GetAllocationHandle(
    LPATID3DCNTX        pCtx,
    DWORD               dwExHandle,
    LONG               *plPitch);
#endif

BOOL R200SetVidMmAllocationHandleForSurface(
    LPATISURFCNTX pD3DSurf, 
    D3DKMT_HANDLE hAllocation);

void R200GetNewCmdBuff(LPATID3DCNTX pD3DCtxt, BOOL bWrite3DContex, BOOL bVMST);

void R200RemoveResourceFromContext(LPATID3DCNTX pD3DCtxt, DWORD dwExHandle);



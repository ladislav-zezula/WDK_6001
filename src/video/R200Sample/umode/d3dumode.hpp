/******************************Module*Header**********************************\
*
*                           *******************
*                           * D3D SAMPLE CODE *
*                           *******************
*

* Copyright (c) 2003 Microsoft Corporation.  All rights reserved.
\*****************************************************************************/

#ifndef D3DUMODE_INCLUDED
#define D3DUMODE_INCLUDED

#include <DriverSpecs.h>

__user_driver

#define DIRECT3D_VERSION    0x0900

#include <windef.h>
#include <wingdi.h>
#include <guiddef.h>
#include <d3d9.h>
#include <d3dnthal.h>
#include <ddrawint.h>

#define DX8DDK_DX7HAL_DEFINES   1

#include <dx95type.h>

#include <d3d8caps.h>

#include <d3dumddi.h>
#include "r2d3dddi.h"
#include "MultiEngine.h"

//
// Prototypes for R200 driver functions
//

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ATIDXOBJECT    *LPATIDXOBJECT;
typedef struct _D3DDEVICE      *LPD3DDEVICE;
typedef struct _ATID3DCNTX     *LPATID3DCNTX;

BOOL _stdcall R200SetCtxtRT(LPATID3DCNTX pContext, DD_DIRECTDRAW_LOCAL *pDDLcl, DD_SURFACE_LOCAL *pDDSLclRT);
void __stdcall R200SetCtxHandleList(LPATID3DCNTX pContext, DD_DIRECTDRAW_LOCAL *pDDLcl);



LPATID3DCNTX
R200ContextCreate(
    DD_DIRECTDRAW_LOCAL    *pDDLcl,
    DD_SURFACE_LOCAL       *pDDSLclRT,
    DWORD                   dwInterfaceVer,
    DWORD                   dwDxAppVersion);

DWORD
R200ContextDestroy(
    LPATID3DCNTX);

VOID R200DestroyDevice(
    LPATIDXOBJECT lpATIDXObj,
    LPD3DDEVICE pD3DDev
    );

BOOL
R200D3DDevInit(
    LPVOID           pDevInfo,
    HANDLE           hDriverHandle,
    LPATIDXOBJECT   *ppDXObj,
    LPD3DDEVICE     *ppD3DDev,
    PR200AdapterInfo pR200AdapterInfo);

DWORD APIENTRY
CreateSurfaceEx32(
    PDD_CREATESURFACEEXDATA pCSEXData);

BOOL
R200CreateATISurfInfo(
    LPATIDXOBJECT       pDXObj,
    DWORD               dwNumSurfaces,
    DD_SURFACE_LOCAL   *pDDSLcl);

HRESULT
R200HwFlush(
    LPATID3DCNTX        pContext,
    LPBYTE              pDP2Command,
    DWORD               dwDP2CmdSize,
    LPBYTE              pUMVertices,
    BOOL                bToKMD);

D3DKMT_HANDLE
R200GetSurfaceAllocHandle(
    LPATID3DCNTX        pContext,
    DWORD               hSurface);

HRESULT
R2QSExtEscape(
    __in    HANDLE                  hDev,
    __in    INT                     nEscape,
    __in    INT                     nInSize,
    __in    LPCSTR                  pIn,
    __in    INT                     nOutSize,
    __inout_bcount(nOutSize) LPSTR  pOut);

DWORD __stdcall
CreateSurface32(
    PDD_CREATESURFACEDATA lpCSData);

HRESULT
D3DDDICreateResource(
    PDD_DIRECTDRAW_LOCAL        pDDLcl,
    PDD_DIRECTDRAW_GLOBAL       pDDGbl,
    D3DDDIARG_CREATERESOURCE*   pCR);

HRESULT
D3DDDIOpenResource(
    PDD_DIRECTDRAW_LOCAL            pDDLcl,
    PDD_DIRECTDRAW_GLOBAL           pDDGbl,
    D3DDDIARG_OPENRESOURCE*         pOpenResource,
    LPATID3DCNTX                    pD3DCtx,
    D3DDDI_RESOURCEFLAGS*           pResFlags,
    D3DDDI_VIDEO_PRESENT_SOURCE_ID* pVidPn);

HRESULT
D3DDDIDestroyResource(
    LPATID3DCNTX                pD3DCtxt,
    DWORD                       dwExHandle,
    DWORD                       dwAllocCnt);

HRESULT
D3DDDIUnlockResource(
    LPATID3DCNTX                pD3DCtxt,
    CONST D3DDDIARG_UNLOCK           *pUnlockData);

HRESULT
CreateSurfaceNotify(
    HANDLE                      pDriverInstance,
    D3DDDIARG_CREATERESOURCE*   pCRData,
    PDD_SURFACE_LOCAL           pDDSLcl);

DWORD
GetExHandles(
    PDD_DIRECTDRAW_LOCAL        pDDLcl,
    DWORD                       dwNumHandles);

HRESULT
R200CreateAllocationCB(
    LPVOID                      pD3DDev,
    R2DDICreateAllocationData  *pR2AllocData,
    D3DKMT_HANDLE              *phAllocation,
    PVOID                       pSysMem);

HRESULT
R200LockAllocationCB(
    LPVOID          pD3DDev,
    D3DKMT_HANDLE*  phAllocation,
    DWORD           dwLockFlags,
    BOOL            Tiled,
    DWORD           dwLockPriData,
    PVOID          *ppAllocation);

HRESULT
R200LockResource(
    LPATID3DCNTX    pD3DCtxt,
    D3DDDIARG_LOCK* pLockData);

HRESULT
R200UnlockResource(
    LPATID3DCNTX    pD3DCtxt,
    HANDLE          hResource);

DWORD
R200GetSubLevelExHandle(
    LPATID3DCNTX    pD3DCtxt,
    HANDLE          hResource,
    DWORD           dwSubLevel);

HRESULT
R200DestroyAllocationCB(
    LPVOID          pD3DDev,
    D3DKMT_HANDLE   hAllocation);

HRESULT
R200UnlockAllocationCB(
    LPVOID          pD3DDev,
    D3DKMT_HANDLE   hAllocation);

void 
R200GetNewCmdBuff(
    LPATID3DCNTX pD3DCtxt, 
    BOOL bWrite3DContex, 
    BOOL bVMST);

QS_PARAM* _stdcall R200UpdateQSParamsForDXVASubmit(LPATID3DCNTX pD3DCtx, DWORD dwSize);


HRESULT APIENTRY
Flush(
    HANDLE          pDriverInstance);

HRESULT
R200GetSurfaceOffsetInfo(
    LPATID3DCNTX    pR200Ctx,
    HANDLE          hResource,
    D3DKMT_HANDLE  *pAllocation,
    DWORD          *pPitchY,
    DWORD          *pPitchUV,
    DWORD          *pWidth,
    DWORD          *pHeight,
    DWORD          *pOffsetU,
    DWORD          *pOffsetV);

extern DWORD
GetCmdBufPreambleSize(
    LPVOID          pvCtx);

#ifndef KM_SYSMEM_PRESENT
D3DKMT_HANDLE
R200GetAllocationHandle(
    LPATID3DCNTX    pD3DCtx,
    DWORD           dwExHandle,
    LONG           *plPitch);
#endif

R200DisableColorKey(
    LPATID3DCNTX    pD3DCtx,
    DWORD           dwExHandle);

R200SetSurfColorKeyVal(
    LPATID3DCNTX    pD3DCtx,
    DWORD           dwExHandle,
    DWORD           dwColorKeyVal);

#ifdef __cplusplus
};
#endif

struct CResource
{
    BOOL                    m_bValid;
    ULONGLONG               m_qwBatch;
    BOOL                    m_bDynamicBuffer;
    LPVOID                  m_pVidmem;              //  pointer for locked allocation
    HANDLE                  m_hResRuntime;          //  runtime handle for resource

    D3DDDI_RESOURCEFLAGS    m_dwResCaps;            // Caps for the resource
    D3DDDI_POOL             m_d3dPool;              // SysMem/VidMem resource
    DWORD                   m_dwNumExHandles;       // # of ExHandles

#ifndef KM_SYSMEM_PRESENT
    HANDLE                  m_hShadowRT;
    D3DDDIFORMAT            m_d3dFormat;
    DWORD                   m_dwWidth;
    DWORD                   m_dwHeight;
    DWORD                   m_lPitch;
    LPBYTE                  m_pSysMem;
#endif


};

class CResourceTable
{
private:
    enum {GROWSIZE = 1024};
    CResource              *m_pRes;
    DWORD                   m_dwSize;

public:
    CResourceTable() : m_pRes(0), m_dwSize(0) {}
    ~CResourceTable()
    {
        if (m_pRes)
        {
            delete[] m_pRes;
        }
    }

    HRESULT Grow(DWORD dwSize);

    DWORD Size() const { return m_dwSize; }
    CResource& operator[](DWORD dwHandle) const { return m_pRes[dwHandle]; }

    DWORD GetResourceHandle(DWORD dwNumHandles)
//  returns first handle in continuous set of handles or 0 if the set is not found
    {
        if (FAILED(Grow(1)))
        {
            return (0);
        }

        int nCont = 0;
        for (UINT i = 1; i < m_dwSize; i++)  //  run thru handle table to find requested spot
        {
            if (m_pRes[i].m_bValid) // is in use ?
            {
                nCont = 0;  //  reset counter
            }
            else // an empty stop found
            {
                if(++nCont == dwNumHandles)         // increment counter and verify
                    return (i - dwNumHandles + 1);  // return first empty handle (index in the table)
            }
        }

        // an empty spot for requested range is not found, save a position unused handles start from
        int indexCont = m_dwSize-nCont;
        //
        // Grow the table for more room
        //
        if (SUCCEEDED(Grow(m_dwSize - nCont + dwNumHandles)))
        {
            return indexCont;  
        }
        else
        {
            return (0);
        }
    }
};

class CD3DContext;

class CD3DFence
{
private:
    CD3DContext*            m_pContext;

    HANDLE                  m_hResource;
    UINT                    m_NextFence;
    UINT*                   m_pCurrentFence; // memory location being updated by hardware during processing command buffers
    BOOL                    m_bWrapped;

public:
    CD3DFence(CD3DContext* pContext);
    ~CD3DFence();

    HRESULT Initialize(VOID);
    BOOL QueryFence(UINT Value);
    HRESULT GetNextFenceValue(UINT*);
    VOID SubmitFence(UINT Fence);       // submits fence to a command buffer to update current fence value
};

class CAdapter
{
private:
    HANDLE                      m_hAdapter;
    DWORD                       m_dwVersion;
    D3DDDI_ADAPTERCALLBACKS     m_Callbacks;
    VOID                       *m_pDevice;
    ULONG                       m_ulGartSupported;
    R200AdapterInfo             R200AdapterInfo;

public:
    CAdapter(
        HANDLE                          hAdapter,
        DWORD                           dwVersion,
        CONST D3DDDI_ADAPTERCALLBACKS  *pCallbacks);
    ~CAdapter();

    BOOL Initialize(VOID);

    HRESULT CreateDevice(D3DDDIARG_CREATEDEVICE *pDeviceData);
    HRESULT GetCaps(CONST D3DDDIARG_GETCAPS *);

    ULONG GetGartSupported() { return m_ulGartSupported; };
};

//
// Maximal number of indices in the internal index buffer
// Production driver should not hard code the indices
//
#define MAX_NUM_INDICES_INT_IB (512*1024)

typedef struct
{
    BOOL                    bEnabled;
    HANDLE                  hContext;
    BYTE                   *pHwCmdBuf;    
    D3DDDI_ALLOCATIONLIST  *pHwCmdBufAllocList;    
}CONTEXT_INFO, *PCONTEXT_INFO;

class CD3DContext : public DD_DIRECTDRAW_LOCAL, DD_DIRECTDRAW_GLOBAL
{
private:
    HANDLE                  m_hD3D;
    DWORD                   m_dwInterface;
    DWORD                   m_dwVersion;
    D3DDDI_DEVICECALLBACKS  m_d3dCallbacks;
    CAdapter               *m_pAdapter;
    ULONG                   m_ulGartSupported;

    //
    // Direct3D resources
    //
    CResourceTable          m_RTbl;
    DWORD                   m_Tex[8];
    DWORD                   m_IB;
    DWORD                   m_VB[16];
    DWORD                   m_RT;
    DWORD                   m_ZB;

    //
    // The handle and index for the curently set render target
    //
    HANDLE                  m_hRenderTarget;
    DWORD                   m_RenderTargetIndex;

    //
    // User mode vertices
    //
    LPBYTE                  m_pUMVertices;

    //
    // Stride for user memory vertices or the VB stream source 0
    //
    DWORD                   m_dwVertexStride;

    //
    // Info for system memory DMA buffer
    //
    BYTE                   *m_pDP2CmdBuf;
    DWORD                   m_dwDP2CmdBufSize;
    DWORD                   m_dwDP2CmdPos;
    ULONGLONG               m_qwBatch;

    BYTE                   *m_pHwCmdBuf;
    DWORD                   m_dwHwCmdBufSize;

    DWORD                   m_dwHwCmdBufAllocListSize;
    DWORD                   m_dwHwCmdPos;
    ULONGLONG               m_qwHWBatch;

    CONTEXT_INFO            m_sContexts[MULTI_ENGINE_COUNT];

    //
    // BUGBUG, temporarily ExtEscape is used to communicate with the KM driver.
    //
    HDC                     m_hDC;

    //
    // RT surface structures for delayed context creation
    //
    DD_SURFACE_LOCAL        m_ddSLclRT;
    DD_SURFACE_GLOBAL       m_ddSGblRT;
    DD_SURFACE_MORE         m_ddSMoreRT;

    LPATIDXOBJECT           m_pR200DXObj;
    LPD3DDEVICE             m_pR200D3DDev;
    LPATID3DCNTX            m_pR200Ctx;
    BOOL                    m_bFirstRTSet;

    //
    // Internal index buffer to handle DrawIndexedPrimitives2
    //
    DD_SURFACE_LOCAL        m_ddSLclIntIB;
    DD_SURFACE_GLOBAL       m_ddSGblIntIB;
    DD_SURFACE_MORE         m_ddSMoreIntIB;

    //
    // Pointer to the user memory indices
    //
    const void             *m_pUMIndices;

    //
    // Stride of user memory indices or index buffer
    //
    DWORD                   m_dwIndexSize;

    //
    // Runtime handle of the resource being created or destroyed
    //
    HANDLE                  m_hCurResRuntime;
    //
    // LDDM Caps1 for the resource being created
    //
    D3DDDI_RESOURCEFLAGS    m_dwCurResCaps;
    //
    // ID of the VidPN source for the swap chain being created
    //
    D3DDDI_VIDEO_PRESENT_SOURCE_ID   m_VidPnSourceId;

    //
    // Indicate if the resource has been freed (all of its allocations freed)
    //
    BOOL                    m_bCurResFreed;

    //
    // Fence mechanism
    //
    CD3DFence*              m_pFence;

    D3DDDIARG_CREATERESOURCE*   m_pCreateResourceData;      // Only valid in context of CreateResource DDI call
    D3DDDIARG_OPENRESOURCE*     m_pOpenResourceData;        // Only valid in context of OpenResource DDI call
    UINT                        m_CurResourceIdx;

    DWORD                       m_LastEngineSubmit;         // Stores the last engine that submitted a packet to KM
#ifdef USE_LOCK_TO_SYNC_ENGINES
    D3DKMT_HANDLE               m_HandleUsedInLastSubmit;
#else
    D3DKMT_HANDLE               m_hEngineSyncObject;
    DWORD                       m_VideoContextCount;
#endif    


public:
    CD3DContext(
        HANDLE                  hD3DInstance,
        DWORD                   dwInterface,
        DWORD                   dwVersion,
        CAdapter*               pAdapter,
        CONST D3DDDI_DEVICECALLBACKS *pD3DCallbacks);
    ~CD3DContext();


    BOOL
    Initialize(D3DDDIARG_CREATEDEVICE* pDeviceData, PR200AdapterInfo pR200AdapterInfo);

    HRESULT CreateSurfaceNotify(D3DDDIARG_CREATERESOURCE* pCRData, PDD_SURFACE_LOCAL pDDSLcl);
    HRESULT LockNotify(HANDLE hSurfaceHandle, DWORD dwLockFlags);
    HRESULT BltNotify(HANDLE hSrcHandle, HANDLE hDstHandle);
    HRESULT FlipNotify(HANDLE hCurrHandle, HANDLE hTargHandle);
    HRESULT Flush(BOOL bToKMD);

    HRESULT SetRenderState(CONST D3DDDIARG_RENDERSTATE* pRS);
    HRESULT UpdateWInfo(CONST D3DDDIARG_WINFO* pWInfo);
    HRESULT ValidateDevice(D3DDDIARG_VALIDATETEXTURESTAGESTATE* pValidateData);
    HRESULT SetTSS(CONST D3DDDIARG_TEXTURESTAGESTATE* pTSS);
    HRESULT SetTexture(UINT Stage, HANDLE hTexture);
    HRESULT CreatePixelShader(D3DDDIARG_CREATEPIXELSHADER* pCreateShader, CONST UINT* pShader);
    HRESULT SetPixelShader(CONST HANDLE hPixelShader);
    HRESULT DeletePixelShader(CONST HANDLE hPixelShader);
    HRESULT SetPixelShaderConst(CONST D3DDDIARG_SETPIXELSHADERCONST* pSetShaderConst, CONST VOID *pConsts);
    HRESULT SetStreamSourceUM(CONST D3DDDIARG_SETSTREAMSOURCEUM* pSetUMStream, CONST VOID *pData);
    HRESULT SetIndices(CONST D3DDDIARG_SETINDICES* pSetIndices);
    HRESULT SetIndicesUM(DWORD dwStride, CONST VOID *pData);
    HRESULT DrawPrimitive(CONST D3DDDIARG_DRAWPRIMITIVE* pDP, CONST UINT* pEdgeFlags);
    HRESULT DrawIndexedPrimitive(CONST D3DDDIARG_DRAWINDEXEDPRIMITIVE* pDIP);
    HRESULT DrawRectPatch(CONST D3DDDIARG_DRAWRECTPATCH* pDrawRectPatch, CONST D3DDDIRECTPATCH_INFO *pPatchInfo, CONST FLOAT *pSegs);
    HRESULT DrawTriPatch(CONST D3DDDIARG_DRAWTRIPATCH* pDrawTriPatch, CONST D3DDDITRIPATCH_INFO *pPatchInfo, CONST FLOAT *pSegs);
    HRESULT DrawPrimitive2(CONST D3DDDIARG_DRAWPRIMITIVE2* pDP2);
    HRESULT DrawIndexedPrimitive2(CONST D3DDDIARG_DRAWINDEXEDPRIMITIVE2* pDIP2, DWORD dwIndexSize, CONST VOID *pIndices, CONST UINT*);
    HRESULT VolBlt(CONST D3DDDIARG_VOLUMEBLT* pVolBlt);
    HRESULT BufBlt(CONST D3DDDIARG_BUFFERBLT* pBufBlt);
    HRESULT TexBlt(CONST D3DDDIARG_TEXBLT* pTexBlt);
    HRESULT StateSet(D3DDDIARG_STATESET* pStateSet);
    HRESULT SetPriority(CONST D3DDDIARG_SETPRIORITY* pSetPriority);
    HRESULT Clear(CONST D3DDDIARG_CLEAR* pClear, UINT ClrCount, CONST RECT* pClrRects);
    HRESULT UpdatePalette(CONST D3DDDIARG_UPDATEPALETTE* pUpdatePalette, CONST PALETTEENTRY *pEntries);
    HRESULT SetPalette(CONST D3DDDIARG_SETPALETTE* pSetPalette);
    HRESULT SetVertexShaderConst(CONST D3DDDIARG_SETVERTEXSHADERCONST* pSetShaderConst, CONST VOID *pConsts);
    HRESULT MultiplyTransform(CONST D3DDDIARG_MULTIPLYTRANSFORM* pTransform);
    HRESULT SetTransform(CONST D3DDDIARG_SETTRANSFORM* pTransform);
    HRESULT SetViewport(CONST D3DDDIARG_VIEWPORTINFO* pViewport);
    HRESULT SetZRange(CONST D3DDDIARG_ZRANGE* pZRange);
    HRESULT SetMaterial(CONST D3DDDIARG_SETMATERIAL* pMaterial);
    HRESULT SetLight(CONST D3DDDIARG_SETLIGHT* pSetLight, CONST D3DDDI_LIGHT *pLight);
    HRESULT CreateLight(CONST D3DDDIARG_CREATELIGHT* pCreateLight);
    HRESULT DestroyLight(CONST D3DDDIARG_DESTROYLIGHT* pDestroyLight);
    HRESULT SetClipPlane(CONST D3DDDIARG_SETCLIPPLANE* pSetClipPlane);
    HRESULT GetInfo(UINT dwDevInfoID, VOID* pDevInfoStruct, UINT dwSize);
    HRESULT Lock(D3DDDIARG_LOCK* pLockData);
    HRESULT Unlock(CONST D3DDDIARG_UNLOCK* pUnlockData);
    HRESULT OpenResource(D3DDDIARG_OPENRESOURCE* pOR);
    HRESULT CreateResource(D3DDDIARG_CREATERESOURCE* pCR);
    HRESULT DestroyResource(HANDLE hResource);

    // DX9 umode driver entry points
    HRESULT CreateVertexShaderDecl(D3DDDIARG_CREATEVERTEXSHADERDECL* lpDP2CreateVSDecl, CONST D3DDDIVERTEXELEMENT *pDeclElems);
    HRESULT DeleteVertexShaderDecl(CONST HANDLE hVSDecl);
    HRESULT SetVertexShaderDecl(CONST HANDLE hVSDecl);

    HRESULT CreateVertexShaderFunc(D3DDDIARG_CREATEVERTEXSHADERFUNC*, CONST UINT*);
    HRESULT DeleteVertexShaderFunc(CONST HANDLE hVSFunc);
    HRESULT SetVertexShaderFunc(CONST HANDLE hVSFunc);

    HRESULT SetVertexShaderConstI(CONST D3DDDIARG_SETVERTEXSHADERCONSTI*, CONST int*);
    HRESULT SetVertexShaderConstB(CONST D3DDDIARG_SETVERTEXSHADERCONSTB*, CONST BOOL*);

    HRESULT SetPixelShaderConstI(CONST D3DDDIARG_SETPIXELSHADERCONSTI*, CONST int*);
    HRESULT SetPixelShaderConstB(CONST D3DDDIARG_SETPIXELSHADERCONSTB*, CONST BOOL*);

    HRESULT SetStreamSource2(CONST D3DDDIARG_SETSTREAMSOURCE* pDP2SetStreamSrc2);
    HRESULT SetRenderTarget2(CONST D3DDDIARG_SETRENDERTARGET* pDP2SetRenderTarget2);
    HRESULT SetDepthStencil(CONST D3DDDIARG_SETDEPTHSTENCIL* pDP2SetDepthStencil);

    HRESULT SetScissorRect(CONST RECT *pRect);
    HRESULT GenerateMipSubLevels(CONST D3DDDIARG_GENERATEMIPSUBLEVELS*);

    HRESULT SetDisplayMode(CONST D3DDDIARG_SETDISPLAYMODE* pSetDisplayMode);
    
    HRESULT Present(CONST D3DDDIARG_PRESENT* pPresent);
    HRESULT Blt(CONST D3DDDIARG_BLT*);
    HRESULT ColorFill(CONST D3DDDIARG_COLORFILL*);
    HRESULT DepthFill(CONST D3DDDIARG_DEPTHFILL*);

    HRESULT CreateQuery(D3DDDIARG_CREATEQUERY*);
    HRESULT DeleteQuery(CONST HANDLE);
    HRESULT IssueQuery(CONST D3DDDIARG_ISSUEQUERY*);
    HRESULT GetQueryData(CONST D3DDDIARG_GETQUERYDATA*);


    HRESULT GetCaps(CONST D3DDDIARG_GETCAPS*);

    HRESULT CreateDecodeDevice(D3DDDIARG_CREATEDECODEDEVICE* pCreateData);
    HRESULT DestroyDecodeDevice(HANDLE hDXVA);
    HRESULT DecodeSetRenderTarget(CONST D3DDDIARG_SETDECODERENDERTARGET* pSetRT);
    HRESULT DecodeBeginFrame(HANDLE hDXVA);
    HRESULT DecodeEndFrame(HANDLE hDXVA);
    HRESULT DecodeExecute(CONST D3DDDIARG_DECODEEXECUTE* pExecute);
    HRESULT DecodeExtensionExecute(CONST D3DDDIARG_DECODEEXTENSIONEXECUTE* pExecute);
    DWORD   GetNumDXVAGuids(VOID);
    VOID    CopyDXVAGuids(VOID* pGuids);
    DWORD   GetNumDecodeOutputFormats(GUID* pGuid);
    VOID    CopyDecodeOutputFormats(GUID* pGuid, D3DDDIFORMAT* pList);
    DWORD   GetNumDecodeBufferInfo(DXVADDI_DECODEINPUT* pInput);
    VOID    CopyDecodeBufferInfo(DXVADDI_DECODEINPUT* pInput, DXVADDI_DECODEBUFFERINFO* pBufferInfo);
    DWORD   GetNumDecodeConfigs(DXVADDI_DECODEINPUT* pInput);
    VOID    CopyDecodeConfigs(DXVADDI_DECODEINPUT* pInput, DXVADDI_CONFIGPICTUREDECODE* pConfigList);
    DWORD   GetNumVideoProcessorDeviceGuids(DXVADDI_VIDEODESC* pVideoDesc);
    HRESULT GetVideoProcessorDeviceGuids(DXVADDI_VIDEODESC* pVideoDesc, GUID* pData);
    HRESULT GetVideoProcessingCaps(DXVADDI_VIDEOPROCESSORINPUT* pInput,
                                   DXVADDI_VIDEOPROCESSORCAPS* pOutput);
    HRESULT CreateVideoProcessDevice(D3DDDIARG_CREATEVIDEOPROCESSDEVICE* pCreateData);
    HRESULT DestroyVideoProcessDevice(HANDLE hVideoProcess);
    HRESULT VideoProcessSetRenderTarget(CONST D3DDDIARG_SETVIDEOPROCESSRENDERTARGET* pSetRT);
    HRESULT VideoProcessBeginFrame(CONST HANDLE hVideoProcess);
    HRESULT VideoProcessEndFrame(CONST HANDLE hVideoProcess);
    HRESULT VideoProcessBlt(CONST D3DDDIARG_VIDEOPROCESSBLT* pBlt);
    HRESULT GetProcAmpRange(DXVADDI_QUERYPROCAMPINPUT* pInput, DXVADDI_VALUERANGE* pOutput);

#ifdef USE_LOCK_TO_SYNC_ENGINES
    HRESULT SyncEnginesUsingLock(VOID);
#else
    HRESULT SyncEngines(DWORD dwEngineReleasingControl, DWORD dwEngineAcquiringControl);
#endif

    HRESULT
    ExtEscape(
        __in    INT                     nEscape,
        __in    INT                     nInSize,
        __in_bcount(nInSize)   LPCSTR   pIn,
        __in    INT                     nOutSize,
        __out_bcount(nOutSize) LPSTR    pOut);

    DWORD   GetExHandles(DWORD);

    HRESULT SetStreamSourceFreq(CONST D3DDDIARG_SETSTREAMSOURCEFREQ* pData);
    HRESULT SetConvolutionKernelMono(CONST D3DDDIARG_SETCONVOLUTIONKERNELMONO* pData);
    HRESULT ComposeRects(CONST D3DDDIARG_COMPOSERECTS* pData);

    HRESULT QueryResourceResidency(CONST D3DDDIARG_QUERYRESOURCERESIDENCY* pArgs);

    HRESULT
    CreateAllocationCB(
        R2DDICreateAllocationData  *pR2AllocData,
        D3DKMT_HANDLE              *phAllocation,
        PVOID                       pSysMem);

    HRESULT
    LockAllocationCB(
        D3DKMT_HANDLE*  phAllocation,
        DWORD           dwLockFlags,
        BOOL            Tiled,
        DWORD           dwLockPriData,
        PVOID          *ppAllocation);

    HRESULT
    DestroyAllocationCB(
        D3DKMT_HANDLE   hAllocation);

    HRESULT
    UnlockAllocationCB(
        D3DKMT_HANDLE   hAllocation);


    HRESULT
    InitializeIntIB();

    CResource*
    GetResourceFromHandle(
        HANDLE          hResource)
    {
        return &(m_RTbl[(DWORD)(DWORD_PTR)hResource]);
    }

    LPVOID GetDXVABuffer(DWORD *pSize);
  
    VOID SubmitDXVABuffer(DWORD Size);

    HRESULT CreateFence(VOID);

    HANDLE GetRenderTargetHandle(VOID)
    {
        return m_hRenderTarget;
    }

    UINT GetRenderTargetIndex(VOID)
    {
        return m_RenderTargetIndex;
    }

    LPVOID GetBufferPointer(D3DHAL_DP2OPERATION op, DWORD dwDataSize)
    {
        if (m_dwDP2CmdPos + sizeof(D3DHAL_DP2COMMAND) + dwDataSize > m_dwDP2CmdBufSize)
        {
            Flush(FALSE);
        }

        LPD3DHAL_DP2COMMAND lpDP2CurrCommand = (LPD3DHAL_DP2COMMAND)(m_pDP2CmdBuf + m_dwDP2CmdPos);
        lpDP2CurrCommand->bCommand = op;
        lpDP2CurrCommand->bReserved = 0;
        lpDP2CurrCommand->wStateCount = 1;
        m_dwDP2CmdPos += (sizeof(D3DHAL_DP2COMMAND) + dwDataSize);

        return lpDP2CurrCommand + 1;
    }

#ifndef KM_SYSMEM_PRESENT
    DWORD
    PrepareShadowRenderTarget(
        DWORD           dwSrcRT,
        DWORD           dwSubLevelIndex);
#endif


};

#endif


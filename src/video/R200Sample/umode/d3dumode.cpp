/*****************************************************************************\
*
*                           *******************
*                           * D3D SAMPLE CODE *
*                           *******************
*
* Copyright (c) 2003 Microsoft Corporation.  All rights reserved.
\*****************************************************************************/


#include <windows.h>
#include <crtdbg.h>

#define DIRECT3D_VERSION 0x0900
#include "d3dumode.hpp"
#include "qs.h"
#include "cwddeqc.h"
#include "debug.h"
#include "MultiEngine.h"


BOOL GenerateAllocationListFromCmdBuf(QS_PARAM *pQSParam, D3DDDI_ALLOCATIONLIST *psAllocationList, DWORD dwAllocationListSize, PDWORD pdwListEntriesUsed);


HRESULT APIENTRY SetRenderState(HANDLE pDriverInstance, CONST D3DDDIARG_RENDERSTATE* pRS)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetRenderState(pRS);
}

HRESULT APIENTRY UpdateWInfo(HANDLE pDriverInstance, CONST D3DDDIARG_WINFO* pWInfo)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->UpdateWInfo(pWInfo);
}

HRESULT APIENTRY ValidateDevice(HANDLE pDriverInstance, D3DDDIARG_VALIDATETEXTURESTAGESTATE* pValidateData)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->ValidateDevice(pValidateData);
}

HRESULT APIENTRY SetTSS(HANDLE pDriverInstance, CONST D3DDDIARG_TEXTURESTAGESTATE* pTSS)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetTSS(pTSS);
}

HRESULT APIENTRY SetTexture(HANDLE pDriverInstance, UINT Stage, HANDLE hTexture)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetTexture(Stage, hTexture);
}

HRESULT APIENTRY CreatePixelShader(HANDLE pDriverInstance, D3DDDIARG_CREATEPIXELSHADER* pDDICreatePixelShader, CONST UINT* pShader)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->CreatePixelShader(pDDICreatePixelShader, pShader);
}

HRESULT APIENTRY SetPixelShader(HANDLE pDriverInstance, CONST HANDLE hPixelShader)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetPixelShader(hPixelShader);
}

HRESULT APIENTRY DeletePixelShader(HANDLE pDriverInstance, CONST HANDLE hPixelShader)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DeletePixelShader(hPixelShader);
}

HRESULT APIENTRY SetPixelShaderConst(HANDLE pDriverInstance, CONST D3DDDIARG_SETPIXELSHADERCONST* pSetShaderConst, CONST FLOAT *pConsts)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetPixelShaderConst(pSetShaderConst, pConsts);
}

HRESULT APIENTRY SetStreamSourceUM(HANDLE pDriverInstance, CONST D3DDDIARG_SETSTREAMSOURCEUM* pSetUMStream, CONST VOID *pData)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetStreamSourceUM(pSetUMStream, pData);
}

HRESULT APIENTRY SetIndices(HANDLE pDriverInstance, CONST D3DDDIARG_SETINDICES* pSetIndices)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetIndices(pSetIndices);
}

HRESULT APIENTRY SetIndicesUM(HANDLE pDriverInstance, UINT dwStride, CONST VOID *pData)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetIndicesUM(dwStride, pData);
}

HRESULT APIENTRY DrawPrimitive(HANDLE pDriverInstance, CONST D3DDDIARG_DRAWPRIMITIVE* pDP, CONST UINT* pEdgeFlags)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DrawPrimitive(pDP, pEdgeFlags);
}

HRESULT APIENTRY DrawIndexedPrimitive(HANDLE pDriverInstance, CONST D3DDDIARG_DRAWINDEXEDPRIMITIVE* pDIP)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DrawIndexedPrimitive(pDIP);
}

HRESULT APIENTRY DrawRectPatch(HANDLE pDriverInstance, CONST D3DDDIARG_DRAWRECTPATCH* pDrawRectPatch, CONST D3DDDIRECTPATCH_INFO *pPatchInfo, CONST FLOAT *pSegs)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DrawRectPatch(pDrawRectPatch, pPatchInfo, pSegs);
}

HRESULT APIENTRY DrawTriPatch(HANDLE pDriverInstance, CONST D3DDDIARG_DRAWTRIPATCH* pDrawTriPatch, CONST D3DDDITRIPATCH_INFO *pPatchInfo, CONST FLOAT *pSegs)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DrawTriPatch(pDrawTriPatch, pPatchInfo, pSegs);
}

HRESULT APIENTRY DrawPrimitive2(HANDLE pDriverInstance, CONST D3DDDIARG_DRAWPRIMITIVE2* pDP2)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DrawPrimitive2(pDP2);
}

HRESULT APIENTRY DrawIndexedPrimitive2(HANDLE pDriverInstance, CONST D3DDDIARG_DRAWINDEXEDPRIMITIVE2* pDIP2, UINT dwIndexSize, CONST VOID *pIndices, CONST UINT* pdw)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DrawIndexedPrimitive2(pDIP2, dwIndexSize, pIndices, pdw);
}

HRESULT APIENTRY VolBlt(HANDLE pDriverInstance, CONST D3DDDIARG_VOLUMEBLT* pVolBlt)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->VolBlt(pVolBlt);
}

HRESULT APIENTRY BufBlt(HANDLE pDriverInstance, CONST D3DDDIARG_BUFFERBLT* pBufBlt)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->BufBlt(pBufBlt);
}

HRESULT APIENTRY TexBlt(HANDLE pDriverInstance, CONST D3DDDIARG_TEXBLT* pTexBlt)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->TexBlt(pTexBlt);
}

HRESULT APIENTRY StateSet(HANDLE pDriverInstance, D3DDDIARG_STATESET* pStateSet)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->StateSet(pStateSet);
}

HRESULT APIENTRY SetPriority(HANDLE pDriverInstance, CONST D3DDDIARG_SETPRIORITY* pSetPriority)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetPriority(pSetPriority);
}

HRESULT APIENTRY Clear(HANDLE pDriverInstance, CONST D3DDDIARG_CLEAR* pClear, UINT ClrCount, CONST RECT* pClrRects)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->Clear(pClear, ClrCount, pClrRects);
}

HRESULT APIENTRY UpdatePalette(HANDLE pDriverInstance, CONST D3DDDIARG_UPDATEPALETTE* pUpdatePalette, CONST PALETTEENTRY *pEntries)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->UpdatePalette(pUpdatePalette, pEntries);
}

HRESULT APIENTRY SetPalette(HANDLE pDriverInstance, CONST D3DDDIARG_SETPALETTE* pSetPalette)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetPalette(pSetPalette);
}

HRESULT APIENTRY SetVertexShaderConst(HANDLE pDriverInstance, CONST D3DDDIARG_SETVERTEXSHADERCONST* pSetShaderConst, CONST VOID *pConsts)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetVertexShaderConst(pSetShaderConst, pConsts);
}

HRESULT APIENTRY MultiplyTransform(HANDLE pDriverInstance, CONST D3DDDIARG_MULTIPLYTRANSFORM* pTransform)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->MultiplyTransform(pTransform);
}

HRESULT APIENTRY SetTransform(HANDLE pDriverInstance, CONST D3DDDIARG_SETTRANSFORM* pTransform)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetTransform(pTransform);
}

HRESULT APIENTRY SetViewport(HANDLE pDriverInstance, CONST D3DDDIARG_VIEWPORTINFO* pViewport)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetViewport(pViewport);
}

HRESULT APIENTRY SetZRange(HANDLE pDriverInstance, CONST D3DDDIARG_ZRANGE* pZRange)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetZRange(pZRange);
}

HRESULT APIENTRY SetMaterial(HANDLE pDriverInstance, CONST D3DDDIARG_SETMATERIAL* pMaterial)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetMaterial(pMaterial);
}

HRESULT APIENTRY SetLight(HANDLE pDriverInstance, CONST D3DDDIARG_SETLIGHT* pSetLight, CONST D3DDDI_LIGHT *pLight)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetLight(pSetLight, pLight);
}

HRESULT APIENTRY CreateLight(HANDLE pDriverInstance, CONST D3DDDIARG_CREATELIGHT* pCreateLight)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->CreateLight(pCreateLight);
}

HRESULT APIENTRY DestroyLight(HANDLE pDriverInstance, CONST D3DDDIARG_DESTROYLIGHT* pDestroyLight)
{
    return reinterpret_cast<CD3DContext *>(pDriverInstance)->DestroyLight(pDestroyLight);
}

HRESULT APIENTRY SetClipPlane(HANDLE pDriverInstance, CONST D3DDDIARG_SETCLIPPLANE* pSetClipPlane)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetClipPlane(pSetClipPlane);
}

HRESULT APIENTRY GetInfo(HANDLE pDriverInstance, UINT dwDevInfoID, VOID* pDevInfoStruct, UINT dwSize)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->GetInfo(dwDevInfoID, pDevInfoStruct, dwSize);
}

HRESULT APIENTRY Lock(HANDLE pDriverInstance, D3DDDIARG_LOCK* pLockData)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->Lock(pLockData);
}

HRESULT APIENTRY Unlock(HANDLE pDriverInstance, CONST D3DDDIARG_UNLOCK* pUnlockData)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->Unlock(pUnlockData);
}

HRESULT APIENTRY Flush(HANDLE pDriverInstance)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->Flush(TRUE);
}

//
// DX9 umode driver entry points
//

HRESULT APIENTRY CreateVertexShaderDecl(HANDLE pDriverInstance, D3DDDIARG_CREATEVERTEXSHADERDECL* pDDICreateVSDecl, CONST D3DDDIVERTEXELEMENT *pDeclElems)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->CreateVertexShaderDecl(pDDICreateVSDecl, pDeclElems);
}

HRESULT APIENTRY DeleteVertexShaderDecl(HANDLE pDriverInstance, CONST HANDLE hVSDecl)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DeleteVertexShaderDecl(hVSDecl);
}

HRESULT APIENTRY SetVertexShaderDecl(HANDLE pDriverInstance, CONST HANDLE hVSDecl)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetVertexShaderDecl(hVSDecl);
}

HRESULT APIENTRY CreateVertexShaderFunc(HANDLE pDriverInstance, D3DDDIARG_CREATEVERTEXSHADERFUNC* pDDICreateVSFunc, CONST UINT* pCode)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->CreateVertexShaderFunc(pDDICreateVSFunc, pCode);
}

HRESULT APIENTRY DeleteVertexShaderFunc(HANDLE pDriverInstance, CONST HANDLE hVSFunc)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DeleteVertexShaderFunc(hVSFunc);
}

HRESULT APIENTRY SetVertexShaderFunc(HANDLE pDriverInstance, CONST HANDLE hVSFunc)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetVertexShaderFunc(hVSFunc);
}

HRESULT APIENTRY SetVertexShaderConstI(HANDLE pDriverInstance, CONST D3DDDIARG_SETVERTEXSHADERCONSTI* pDP2SetVSConstI, CONST int *pConstI)
{
    return E_NOTIMPL;
}

HRESULT APIENTRY SetVertexShaderConstB(HANDLE pDriverInstance, CONST D3DDDIARG_SETVERTEXSHADERCONSTB* pDP2SetVSConstB, CONST BOOL *pConstB)
{
    return E_NOTIMPL;
}

HRESULT APIENTRY SetPixelShaderConstI(HANDLE pDriverInstance, CONST D3DDDIARG_SETPIXELSHADERCONSTI* pDP2SetPSConstI, CONST int *pConstI)
{
    return E_NOTIMPL;
}

HRESULT APIENTRY SetPixelShaderConstB(HANDLE pDriverInstance, CONST D3DDDIARG_SETPIXELSHADERCONSTB* pDP2SetPSConstB, CONST BOOL *pConstB)
{
    return E_NOTIMPL;
}

HRESULT APIENTRY SetStreamSource2(HANDLE pDriverInstance, CONST D3DDDIARG_SETSTREAMSOURCE* pDP2SetStreamSrc2)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetStreamSource2(pDP2SetStreamSrc2);
}

HRESULT APIENTRY SetRenderTarget2(HANDLE pDriverInstance, CONST D3DDDIARG_SETRENDERTARGET* pDP2SetRenderTarget2)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetRenderTarget2(pDP2SetRenderTarget2);
}

HRESULT APIENTRY SetDepthStencil(HANDLE pDriverInstance, CONST D3DDDIARG_SETDEPTHSTENCIL* pDP2SetDepthStencil)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetDepthStencil(pDP2SetDepthStencil);
}

HRESULT APIENTRY SetScissorRect(HANDLE pDriverInstance, CONST RECT* pRect)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetScissorRect(pRect);
}

HRESULT APIENTRY GenerateMipSubLevels(HANDLE pDriverInstance, CONST D3DDDIARG_GENERATEMIPSUBLEVELS* pDP2GenMipLevels)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->GenerateMipSubLevels(pDP2GenMipLevels);
}

// DX9 2D DDI
HRESULT APIENTRY Blt(HANDLE pDriverInstance, CONST D3DDDIARG_BLT* pDP2Blt)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->Blt(pDP2Blt);
}

HRESULT APIENTRY ColorFill(HANDLE pDriverInstance, CONST D3DDDIARG_COLORFILL* pColorFill)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->ColorFill(pColorFill);
}

HRESULT APIENTRY DepthFill(HANDLE pDriverInstance, CONST D3DDDIARG_DEPTHFILL* pDepthFill)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DepthFill(pDepthFill);
}

// DX9 Query DDI
HRESULT APIENTRY CreateQuery(HANDLE pDriverInstance, D3DDDIARG_CREATEQUERY* pDP2CreateQuery)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->CreateQuery(pDP2CreateQuery);
}

HRESULT APIENTRY DeleteQuery(HANDLE pDriverInstance, CONST HANDLE hQuery)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DeleteQuery(hQuery);
}

HRESULT APIENTRY IssueQuery(HANDLE pDriverInstance, CONST D3DDDIARG_ISSUEQUERY* pDP2IssueQuery)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->IssueQuery(pDP2IssueQuery);
}

HRESULT APIENTRY GetQueryData(HANDLE pDriverInstance, CONST D3DDDIARG_GETQUERYDATA* pGetQueryData)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->GetQueryData(pGetQueryData);
}

HRESULT APIENTRY CreateResource(HANDLE pDriverInstance, D3DDDIARG_CREATERESOURCE* pCR)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->CreateResource(pCR);
}

HRESULT APIENTRY OpenResource(HANDLE pDriverInstance, D3DDDIARG_OPENRESOURCE* pOR)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->OpenResource(pOR);
}

HRESULT APIENTRY DestroyResource(HANDLE pDriverInstance, HANDLE hResource)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DestroyResource(hResource);
}

HRESULT APIENTRY SetDisplayMode(HANDLE pDriverInstance, CONST D3DDDIARG_SETDISPLAYMODE* pSetDisplayMode)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetDisplayMode(pSetDisplayMode);
}

HRESULT APIENTRY Present(HANDLE pDriverInstance, CONST D3DDDIARG_PRESENT* pPresent)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->Present(pPresent);
}

HRESULT APIENTRY GetCaps(HANDLE hAdapter, CONST D3DDDIARG_GETCAPS* pGetCapsData)
{
    return reinterpret_cast<CAdapter*>(hAdapter)->GetCaps(pGetCapsData);
}

HRESULT APIENTRY CreateDecodeDevice(HANDLE pDriverInstance, D3DDDIARG_CREATEDECODEDEVICE* pCreateData)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->CreateDecodeDevice(pCreateData);
}

HRESULT APIENTRY DestroyDecodeDevice(HANDLE pDriverInstance, HANDLE hDXVA)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DestroyDecodeDevice(hDXVA);
}

HRESULT APIENTRY DecodeSetRenderTarget(HANDLE pDriverInstance, CONST D3DDDIARG_SETDECODERENDERTARGET* pSetRT)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DecodeSetRenderTarget(pSetRT);
}

HRESULT APIENTRY DecodeBeginFrame(HANDLE pDriverInstance, D3DDDIARG_DECODEBEGINFRAME* pFrame)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DecodeBeginFrame(pFrame->hDecode);
}

HRESULT APIENTRY DecodeEndFrame(HANDLE pDriverInstance, D3DDDIARG_DECODEENDFRAME* pFrame)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DecodeEndFrame(pFrame->hDecode);
}

HRESULT APIENTRY DecodeExecute(HANDLE pDriverInstance, CONST D3DDDIARG_DECODEEXECUTE* pExecute)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DecodeExecute(pExecute);
}

HRESULT APIENTRY DecodeExtensionExecute(HANDLE pDriverInstance, CONST D3DDDIARG_DECODEEXTENSIONEXECUTE* pExecute)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DecodeExtensionExecute(pExecute);
}

HRESULT APIENTRY CreateVideoProcessDevice(HANDLE pDriverInstance, D3DDDIARG_CREATEVIDEOPROCESSDEVICE* pCreateData)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->CreateVideoProcessDevice(pCreateData);
}

HRESULT APIENTRY DestroyVideoProcessDevice(HANDLE pDriverInstance, HANDLE hVideoProcess)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->DestroyVideoProcessDevice(hVideoProcess);
}

HRESULT APIENTRY VideoProcessSetRenderTarget(HANDLE pDriverInstance, CONST D3DDDIARG_SETVIDEOPROCESSRENDERTARGET* pSetRT)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->VideoProcessSetRenderTarget(pSetRT);
}

HRESULT APIENTRY VideoProcessBeginFrame(HANDLE pDriverInstance, CONST HANDLE hVideoProcess)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->VideoProcessBeginFrame(hVideoProcess);
}

HRESULT APIENTRY VideoProcessEndFrame(HANDLE pDriverInstance, D3DDDIARG_VIDEOPROCESSENDFRAME* pFrame)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->VideoProcessEndFrame(pFrame->hVideoProcess);
}

HRESULT APIENTRY VideoProcessBlt(HANDLE pDriverInstance, CONST D3DDDIARG_VIDEOPROCESSBLT* pBlt)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->VideoProcessBlt(pBlt);
}

HRESULT APIENTRY CreateDevice(HANDLE hAdapter, D3DDDIARG_CREATEDEVICE* pDeviceData)
{
    return reinterpret_cast<CAdapter*>(hAdapter)->CreateDevice(pDeviceData);
}

HRESULT APIENTRY SetStreamSourceFreq(HANDLE pDriverInstance, CONST D3DDDIARG_SETSTREAMSOURCEFREQ* pData)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetStreamSourceFreq(pData);
}

HRESULT APIENTRY SetConvolutionKernelMono(HANDLE pDriverInstance, CONST D3DDDIARG_SETCONVOLUTIONKERNELMONO* pData)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->SetConvolutionKernelMono(pData);
}

HRESULT APIENTRY ComposeRects(HANDLE pDriverInstance, CONST D3DDDIARG_COMPOSERECTS* pData)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->ComposeRects(pData);
}

HRESULT APIENTRY CreateExtensionDevice(HANDLE pDriverInstance, D3DDDIARG_CREATEEXTENSIONDEVICE* pCreateData)
{
    pCreateData->hExtension = (HANDLE) 0x27;
    return S_OK;
}

HRESULT APIENTRY DestroyExtensionDevice(HANDLE pDriverInstance, HANDLE hDXVA)
{
    return S_OK;
}

HRESULT APIENTRY ExtensionExecute(HANDLE pDriverInstance, CONST D3DDDIARG_EXTENSIONEXECUTE* pExecute)
{
    return S_OK;
}

HRESULT APIENTRY QueryResourceResidency(HANDLE pDriverInstance, CONST D3DDDIARG_QUERYRESOURCERESIDENCY* pArgs)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->QueryResourceResidency(pArgs);
}


HRESULT APIENTRY
CloseAdapter(
    HANDLE  hAdapter)
{
    CAdapter *pAdapter = reinterpret_cast<CAdapter*>(hAdapter);

    delete pAdapter;

    return (S_OK);
}

//
// DDI function exported to umode runtime
//
HRESULT APIENTRY
OpenAdapter(
    D3DDDIARG_OPENADAPTER* pAdapterData)
{
    CAdapter* pAdapter = new CAdapter(pAdapterData->hAdapter,
                                      pAdapterData->Version,
                                      pAdapterData->pAdapterCallbacks);
    if (! pAdapter)
    {
        return (E_FAIL);
    }
    if (! pAdapter->Initialize())
    {
        delete pAdapter;
        return (E_FAIL);
    }

    pAdapterData->hAdapter = (HANDLE) pAdapter;
    pAdapterData->DriverVersion = D3D_UMD_INTERFACE_VERSION;

    pAdapterData->pAdapterFuncs->pfnGetCaps      = GetCaps;
    pAdapterData->pAdapterFuncs->pfnCreateDevice = CreateDevice;
    pAdapterData->pAdapterFuncs->pfnCloseAdapter = CloseAdapter;

    return (S_OK);
}

HRESULT CResourceTable::Grow(DWORD dwNewIndex)
{
    //
    // dwNewIndex is the index the caller will use
    //
    if (m_dwSize <= dwNewIndex)
    {
        DWORD NewSize = (dwNewIndex / GROWSIZE + 1) * GROWSIZE;

        if ( NewSize <= m_dwSize )
        {
            NewSize = m_dwSize + 1;

            if ( NewSize < m_dwSize )  // integer overflow condition
            {
                return E_OUTOFMEMORY;
            }
        }

        CResource *pTemp = new CResource[NewSize];
        if (pTemp == 0)
        {
            return E_OUTOFMEMORY;
        }

        memset(pTemp, 0, NewSize * sizeof(CResource));

        if ( m_dwSize <= NewSize )
        {
            memcpy(pTemp, m_pRes, m_dwSize * sizeof(CResource));
        }

        delete[] m_pRes;

        m_pRes   = pTemp;
        m_dwSize = NewSize;
    }

    return (S_OK);
}


HRESULT APIENTRY
DestroyDevice(
    HANDLE  hDriverInstance)
{
    CD3DContext    *pD3DDev = reinterpret_cast<CD3DContext *>(hDriverInstance);


    delete pD3DDev;
    return (S_OK);
}

CAdapter::CAdapter(
    HANDLE                          hAdapter,
    DWORD                           dwVersion,
    CONST D3DDDI_ADAPTERCALLBACKS  *pCallbacks) :

    m_hAdapter(hAdapter),
    m_dwVersion(dwVersion),
    m_Callbacks(*pCallbacks),
    m_pDevice(NULL),
    m_ulGartSupported(0)
{
}

CAdapter::~CAdapter()
{
    CD3DContext    *pDevice = (CD3DContext *)m_pDevice;

    if (pDevice != NULL)
    {
        delete pDevice;
    }
}

BOOL
CAdapter::Initialize(VOID)
{
    D3DDDI_DEVICECALLBACKS  DeviceCallbacks;
    D3DDDIARG_CREATEDEVICE  DeviceData = {0};
    HRESULT hr;

    //
    // Query the KMD for R200 adapter info (GART segment support for now)
    //
    D3DDDICB_QUERYADAPTERINFO   ddiQueryAdapterInfo;

    memset(&R200AdapterInfo, 0, sizeof(R200AdapterInfo));

    ddiQueryAdapterInfo.pPrivateDriverData    = &R200AdapterInfo;
    ddiQueryAdapterInfo.PrivateDriverDataSize = sizeof(R200AdapterInfo);

    hr = m_Callbacks.pfnQueryAdapterInfoCb(m_hAdapter, &ddiQueryAdapterInfo);
    if (FAILED(hr))
    {
        return FALSE;
    }

    m_ulGartSupported = R200AdapterInfo.ulGartSupported;


    // We made a late decision to query the caps from a new adapter
    // object rather than from the device, but all of our code is
    // currently written to query it from a device.  Rather than re-write
    // all of this code a few days before our milestone, we are simply
    // creating a dummy device object that will only be used for
    // querying caps.

    DeviceData.hDevice = (HANDLE) 1;
    DeviceData.Interface = 9;
    DeviceData.pCallbacks = &DeviceCallbacks;

    memset(&DeviceCallbacks, 0, sizeof(DeviceCallbacks));
    CD3DContext *pCtxt = new CD3DContext(DeviceData.hDevice,
                                         DeviceData.Interface,
                                         m_dwVersion,
                                         this,
                                         &DeviceCallbacks);
    if (! pCtxt)
    {
        return FALSE;
    }
    if (! pCtxt->Initialize(&DeviceData, &R200AdapterInfo))
    {
        delete pCtxt;
        return FALSE;
    }

    m_pDevice = (VOID *)pCtxt;

    return (TRUE);
}

HRESULT
CAdapter::GetCaps(
    CONST D3DDDIARG_GETCAPS*  pGetCaps)
{
    CD3DContext* pDevice = (CD3DContext*) m_pDevice;
    return pDevice->GetCaps(pGetCaps);
}

HRESULT
CAdapter::CreateDevice(D3DDDIARG_CREATEDEVICE* pDeviceData)
{
    D3DDDI_DEVICEFUNCS  *pUserModeFuncs = pDeviceData->pDeviceFuncs;
    LPATID3DCNTX         pR2Context;

    CD3DContext *pCtxt = new CD3DContext(pDeviceData->hDevice,
                                         pDeviceData->Interface,
                                         m_dwVersion,
                                         this,
                                         pDeviceData->pCallbacks);
    if (! pCtxt)
    {
        return (E_FAIL);
    }

    if (! pCtxt->Initialize(pDeviceData, &R200AdapterInfo))
    {
        delete pCtxt;
        return (E_FAIL);
    }


    pDeviceData->hDevice = (HANDLE) pCtxt;

    pUserModeFuncs->pfnSetRenderState         = SetRenderState;
    pUserModeFuncs->pfnUpdateWInfo            = UpdateWInfo;
    pUserModeFuncs->pfnValidateDevice         = ValidateDevice;
    pUserModeFuncs->pfnSetTextureStageState   = SetTSS;
    pUserModeFuncs->pfnSetTexture             = SetTexture;
    pUserModeFuncs->pfnCreatePixelShader      = CreatePixelShader;
    pUserModeFuncs->pfnSetPixelShader         = SetPixelShader;
    pUserModeFuncs->pfnDeletePixelShader      = DeletePixelShader;
    pUserModeFuncs->pfnSetPixelShaderConst    = SetPixelShaderConst;
    pUserModeFuncs->pfnSetStreamSourceUm      = SetStreamSourceUM;
    pUserModeFuncs->pfnSetIndices             = SetIndices;
    pUserModeFuncs->pfnSetIndicesUm           = SetIndicesUM;
    pUserModeFuncs->pfnDrawPrimitive          = DrawPrimitive;
    pUserModeFuncs->pfnDrawIndexedPrimitive   = DrawIndexedPrimitive;
    pUserModeFuncs->pfnDrawRectPatch          = DrawRectPatch;
    pUserModeFuncs->pfnDrawTriPatch           = DrawTriPatch;
    pUserModeFuncs->pfnDrawPrimitive2         = DrawPrimitive2;
    pUserModeFuncs->pfnDrawIndexedPrimitive2  = DrawIndexedPrimitive2;
    pUserModeFuncs->pfnVolBlt                 = VolBlt;
    pUserModeFuncs->pfnBufBlt                 = BufBlt;
    pUserModeFuncs->pfnTexBlt                 = TexBlt;
    pUserModeFuncs->pfnStateSet               = StateSet;
    pUserModeFuncs->pfnSetPriority            = SetPriority;
    pUserModeFuncs->pfnClear                  = Clear;
    pUserModeFuncs->pfnUpdatePalette          = UpdatePalette;
    pUserModeFuncs->pfnSetPalette             = SetPalette;
    pUserModeFuncs->pfnSetVertexShaderConst   = SetVertexShaderConst;
    pUserModeFuncs->pfnMultiplyTransform      = MultiplyTransform;
    pUserModeFuncs->pfnSetTransform           = SetTransform;
    pUserModeFuncs->pfnSetViewport            = SetViewport;
    pUserModeFuncs->pfnSetZRange              = SetZRange;
    pUserModeFuncs->pfnSetMaterial            = SetMaterial;
    pUserModeFuncs->pfnSetLight               = SetLight;
    pUserModeFuncs->pfnCreateLight            = CreateLight;
    pUserModeFuncs->pfnDestroyLight           = DestroyLight;
    pUserModeFuncs->pfnSetClipPlane           = SetClipPlane;
    pUserModeFuncs->pfnGetInfo                = GetInfo;
    pUserModeFuncs->pfnLock                   = Lock;
    pUserModeFuncs->pfnUnlock                 = Unlock;
    pUserModeFuncs->pfnCreateResource         = CreateResource;
    pUserModeFuncs->pfnOpenResource           = OpenResource;
    pUserModeFuncs->pfnDestroyResource        = DestroyResource;
    pUserModeFuncs->pfnSetDisplayMode         = SetDisplayMode;
    pUserModeFuncs->pfnPresent                = Present;
    pUserModeFuncs->pfnFlush                  = Flush;

    // DX9 umode driver entry points
    pUserModeFuncs->pfnCreateVertexShaderDecl = CreateVertexShaderDecl;
    pUserModeFuncs->pfnDeleteVertexShaderDecl = DeleteVertexShaderDecl;
    pUserModeFuncs->pfnSetVertexShaderDecl    = SetVertexShaderDecl;

    pUserModeFuncs->pfnCreateVertexShaderFunc = CreateVertexShaderFunc;
    pUserModeFuncs->pfnDeleteVertexShaderFunc = DeleteVertexShaderFunc;
    pUserModeFuncs->pfnSetVertexShaderFunc    = SetVertexShaderFunc;

    pUserModeFuncs->pfnSetVertexShaderConstI  = SetVertexShaderConstI;
    pUserModeFuncs->pfnSetVertexShaderConstB  = SetVertexShaderConstB;

    pUserModeFuncs->pfnSetPixelShaderConstI   = SetPixelShaderConstI;
    pUserModeFuncs->pfnSetPixelShaderConstB   = SetPixelShaderConstB;

    pUserModeFuncs->pfnSetStreamSource        = SetStreamSource2;
    pUserModeFuncs->pfnSetRenderTarget        = SetRenderTarget2;
    pUserModeFuncs->pfnSetDepthStencil        = SetDepthStencil;

    pUserModeFuncs->pfnSetScissorRect         = SetScissorRect;
    pUserModeFuncs->pfnGenerateMipSubLevels   = GenerateMipSubLevels;

    pUserModeFuncs->pfnBlt                    = Blt;
    pUserModeFuncs->pfnColorFill              = ColorFill;   // ColorFill
    pUserModeFuncs->pfnDepthFill              = DepthFill;

    pUserModeFuncs->pfnCreateQuery            = CreateQuery;
    pUserModeFuncs->pfnDestroyQuery           = DeleteQuery;
    pUserModeFuncs->pfnIssueQuery             = IssueQuery;
    pUserModeFuncs->pfnGetQueryData           = GetQueryData;


    pUserModeFuncs->pfnSetStreamSourceFreq    = SetStreamSourceFreq;
    pUserModeFuncs->pfnSetConvolutionKernelMono = SetConvolutionKernelMono;
    pUserModeFuncs->pfnComposeRects           = ComposeRects;

    pUserModeFuncs->pfnCreateDecodeDevice     = CreateDecodeDevice;
    pUserModeFuncs->pfnDestroyDecodeDevice    = DestroyDecodeDevice;
    pUserModeFuncs->pfnSetDecodeRenderTarget  = DecodeSetRenderTarget;
    pUserModeFuncs->pfnDecodeBeginFrame       = DecodeBeginFrame;
    pUserModeFuncs->pfnDecodeEndFrame         = DecodeEndFrame;
    pUserModeFuncs->pfnDecodeExecute          = DecodeExecute;
    pUserModeFuncs->pfnDecodeExtensionExecute = DecodeExtensionExecute;

    pUserModeFuncs->pfnCreateVideoProcessDevice    = CreateVideoProcessDevice;
    pUserModeFuncs->pfnDestroyVideoProcessDevice   = DestroyVideoProcessDevice;
    pUserModeFuncs->pfnVideoProcessBeginFrame      = VideoProcessBeginFrame;
    pUserModeFuncs->pfnVideoProcessEndFrame        = VideoProcessEndFrame;
    pUserModeFuncs->pfnSetVideoProcessRenderTarget = VideoProcessSetRenderTarget;
    pUserModeFuncs->pfnVideoProcessBlt             = VideoProcessBlt;

    pUserModeFuncs->pfnCreateExtensionDevice  = CreateExtensionDevice;
    pUserModeFuncs->pfnDestroyExtensionDevice = DestroyExtensionDevice;
    pUserModeFuncs->pfnExtensionExecute       = ExtensionExecute;

    pUserModeFuncs->pfnDestroyDevice           = DestroyDevice;
    pUserModeFuncs->pfnQueryResourceResidency  = QueryResourceResidency;

    return (S_OK);
}

CD3DContext::CD3DContext(
    HANDLE                  hD3DInstance,
    DWORD                   dwInterface,
    DWORD                   dwVersion,
    CAdapter*               pAdapter,
    CONST D3DDDI_DEVICECALLBACKS *pD3DCallbacks) :

    m_hD3D(hD3DInstance),
    m_dwInterface(5),     // Always say DX9 because we have yet to test it with anything else
    m_dwVersion(dwVersion),
    m_d3dCallbacks(*pD3DCallbacks),
    m_pAdapter(pAdapter),
    m_ulGartSupported(0),

    m_pDP2CmdBuf(NULL),
    m_dwDP2CmdBufSize(0),
    m_dwDP2CmdPos(0),
    m_qwBatch(0),

    m_pHwCmdBuf(NULL),
    m_dwHwCmdBufSize(0),
    m_dwHwCmdBufAllocListSize(0),
    m_qwHWBatch(0),

    m_RT(0),
    m_ZB(0),

    m_pUMVertices(NULL),
    m_dwVertexStride(0),

    m_hDC(NULL),

    m_pR200Ctx(NULL),
    m_bFirstRTSet(FALSE),
    m_pR200D3DDev(NULL),
    m_pR200DXObj(NULL),

    m_pUMIndices(NULL),
    m_dwIndexSize(0),

    m_pOpenResourceData(NULL),
    m_pCreateResourceData(NULL),
    m_CurResourceIdx(0),

    m_LastEngineSubmit(0xffffffff),

#ifndef USE_LOCK_TO_SYNC_ENGINES
    m_hEngineSyncObject(0),
    m_VideoContextCount(0),
#endif   


    m_hCurResRuntime(NULL),

    m_VidPnSourceId(0), 
    m_bCurResFreed(FALSE),
    m_pFence(NULL)
{
    memset(m_Tex, 0, sizeof(DWORD)*8);
    memset(&m_IB, 0, sizeof(DWORD));
    memset(m_VB, 0, sizeof(DWORD)*16);

    memset(&m_ddSLclRT, 0, sizeof(m_ddSLclRT));
    memset(&m_ddSGblRT, 0, sizeof(m_ddSGblRT));
    memset(&m_ddSMoreRT, 0, sizeof(m_ddSMoreRT));

    memset(&m_ddSLclIntIB, 0, sizeof(m_ddSLclRT));
    memset(&m_ddSGblIntIB, 0, sizeof(m_ddSGblRT));
    memset(&m_ddSMoreIntIB, 0, sizeof(m_ddSMoreRT));
    memset(&m_sContexts, 0, sizeof(m_sContexts));


    m_dwCurResCaps.Value = 0;
}


BOOL
CD3DContext::Initialize(
    D3DDDIARG_CREATEDEVICE* pDeviceData,
    PR200AdapterInfo        pR200AdapterInfo)
{
    HRESULT hr;

    //
    // Create default GPU Context for this device.
    //

    D3DDDICB_CREATECONTEXT CreateContext;
    ZeroMemory(&CreateContext, sizeof(CreateContext));

    if (NULL != m_d3dCallbacks.pfnCreateContextCb)
    {
        CreateContext.NodeOrdinal = 0;
        CreateContext.EngineAffinity = 1;

        hr = m_d3dCallbacks.pfnCreateContextCb(m_hD3D, &CreateContext);
        if (FAILED(hr))
        {
            DBG_BREAK;
            return FALSE;
        }
    }

    //
    // Multi-engine is implemented in a inefficient way in order to made the implementation easier.
    // Rather than changing all the code to write directly into the correct CmdBuf, we will continue to 
    // write into m_pHwCmdBuf and then at render time we will copy that data to the correct CmdBuf.
    // A production driver should not do this as it very inefficient and will reduce performance.
    //
    if (CreateContext.CommandBufferSize != 0)
    {
        m_pHwCmdBuf = (PBYTE)VirtualAlloc(NULL, CreateContext.CommandBufferSize, MEM_COMMIT, PAGE_READWRITE);
        if (m_pHwCmdBuf == NULL)
        {
            return FALSE;
        }
    }

    //
    // Store 3D context buffer info
    //
    m_sContexts[MULTI_ENGINE_NODE_3D].hContext = CreateContext.hContext;
    m_sContexts[MULTI_ENGINE_NODE_3D].bEnabled = TRUE;    
    m_sContexts[MULTI_ENGINE_NODE_3D].pHwCmdBuf = (PBYTE)CreateContext.pCommandBuffer;
    m_sContexts[MULTI_ENGINE_NODE_3D].pHwCmdBufAllocList = CreateContext.pAllocationList;

    //
    // Store sizes of buffers create by dxgkrnl for the device/context
    // All R200 contexts have the same buffer size
    //    
    m_dwHwCmdBufSize = CreateContext.CommandBufferSize;      // Returned by KMD
    m_dwHwCmdBufAllocListSize = CreateContext.AllocationListSize;

    //
    // Set up the DD_DIRECTDRAW_LOCAL fields
    //
    lpGbl = this;

    //
    // Set up the DD_DIRECTDRAW_GLOBAL fields
    //
    dhpdev            = NULL;
    dwReserved1       = NULL;
    dwReserved2       = NULL;
    lpDDVideoPortCaps = NULL;

    //
    // Set up the internal DP2 command buffer
    //
    m_pDP2CmdBuf = (PBYTE)VirtualAlloc(NULL,
                                       16*1024,
                                       MEM_COMMIT,
                                       PAGE_READWRITE);
    if (! m_pDP2CmdBuf)
    {
        return (FALSE);
    }

    m_dwDP2CmdBufSize = 16*1024;
    m_dwDP2CmdPos     = 0;


    //
    //Production Driver should not use CreateDC to retrieve device specific information
    //It should retrieve such information from kernel mode driver
    //
    m_hDC = CreateDCA("DISPLAY", NULL, NULL, NULL);
    if (! m_hDC)
    {
        return (FALSE);
    }

    if (R200D3DDevInit(this, m_hDC, &m_pR200DXObj, &m_pR200D3DDev, pR200AdapterInfo))
    {

        dhpdev = m_pR200DXObj;
    }
    else
    {
        return (FALSE);
    }

    //
    // Get GART segments supported on the adapter
    //
    m_ulGartSupported = m_pAdapter->GetGartSupported();

    //Create Context
    if (CreateContext.pCommandBuffer != NULL)
    {
        m_pR200Ctx = R200ContextCreate(this, NULL, m_dwInterface, pDeviceData->Interface);
        if (m_pR200Ctx == NULL)
        {
            return FALSE;
        }
    }

    return (TRUE);
}

CD3DContext::~CD3DContext()
{
    if (m_pDP2CmdBuf)
    {
        //
        // NOTE: When MEM_RELEASE is used, dwSize must be zero and
        //       lpAddress must point to the base address returned
        //       by the VirtualAlloc.
        //
        VirtualFree(m_pDP2CmdBuf, 0, MEM_RELEASE);
    }

    if (m_pFence != NULL)
    {
        delete m_pFence;
        m_pFence = NULL;
    }

    //
    // Destroy the R200 D3D context)
    //
    if (m_pR200Ctx)
    {
        // First flush the current command buffer
        R200HwFlush(m_pR200Ctx, m_pDP2CmdBuf, m_dwDP2CmdPos, m_pUMVertices, TRUE);

        R200ContextDestroy(m_pR200Ctx);
    }
    else
    {
        R200DestroyDevice(m_pR200DXObj, m_pR200D3DDev);
    }

    //
    // Clean up the internal index buffer
    //
    if (m_ddSGblIntIB.fpVidMem)
    {
        VirtualFree((LPVOID)m_ddSGblIntIB.fpVidMem,
                    0,
                    MEM_RELEASE);
    }

    //
    // Clean up the HDC (completely remove it later)
    //
    if (m_hDC)
    {
        DeleteDC(m_hDC);
    }


    if (m_pHwCmdBuf)
    {
        VirtualFree(m_pHwCmdBuf, 0, MEM_RELEASE);        
    }

    // Call to Destroy default GPU context.
    if (m_d3dCallbacks.pfnDestroyContextCb)
    {
        D3DDDICB_DESTROYCONTEXT DestroyContext;
        DestroyContext.hContext = m_sContexts[MULTI_ENGINE_NODE_3D].hContext;
        m_d3dCallbacks.pfnDestroyContextCb(m_hD3D, &DestroyContext);
        m_sContexts[MULTI_ENGINE_NODE_3D].hContext = NULL;
    }
}



HRESULT
CreateSurfaceNotify(
    HANDLE                      pDriverInstance,
    D3DDDIARG_CREATERESOURCE*   pCRData,
    PDD_SURFACE_LOCAL           pDDSLcl)
{
    return reinterpret_cast<CD3DContext*>(pDriverInstance)->CreateSurfaceNotify(pCRData, pDDSLcl);
}

#define MAX_MIPLEVELS   72

HRESULT
CD3DContext::CreateSurfaceNotify(
    D3DDDIARG_CREATERESOURCE*   pSurface,
    PDD_SURFACE_LOCAL           pDDSLcl)
{
    UINT i;
    PDD_SURFACE_LOCAL           pCurDDSLcl;

    // Check if attch list is enough
    if (pSurface->SurfCount > MAX_MIPLEVELS)
    {
#ifdef DEBUG
        DebugBreak();
#endif
        return (E_INVALIDARG);
    }

    // if (! R200CreateATISurfInfo(m_pR200DXObj, pSurface->dwSCnt, pDDSLcl))
    // {
    //     return (DDERR_INVALIDPARAMS);
    // }


    DD_CREATESURFACEEXDATA      createSurfExData;
    HRESULT                     hr;

    for (i = 0, pCurDDSLcl = pDDSLcl;
         i < pSurface->SurfCount;
         i++, pCurDDSLcl++)
    {
        memset(&createSurfExData, 0, sizeof(DD_CREATESURFACEEXDATA));
        createSurfExData.lpDDLcl  = this;
        createSurfExData.lpDDSLcl = pCurDDSLcl;
        createSurfExData.ddRVal   = DDERR_GENERIC;

        if ((CreateSurfaceEx32(&createSurfExData)) != DDHAL_DRIVER_HANDLED)
        {
            hr = DDERR_INVALIDPARAMS;
        }
        else
        {
            hr = createSurfExData.ddRVal;
        }
        if (FAILED(hr))
        {
            return (hr);
        }

        if (! (pCurDDSLcl->ddsCaps.dwCaps & DDSCAPS_3DDEVICE))
        {
            break;
        }
    }
    if ((((pDDSLcl->ddsCaps.dwCaps & DDSCAPS_3DDEVICE) &&
          (pDDSLcl->ddsCaps.dwCaps & DDSCAPS_VIDEOMEMORY)) ||
         (pDDSLcl->ddsCaps.dwCaps & DDSCAPS_PRIMARYSURFACE)) &&
        (! m_ddSLclRT.lpGbl))
    {
        m_ddSLclRT  = *pDDSLcl;
        m_ddSGblRT  = *pDDSLcl->lpGbl;
        m_ddSMoreRT = *pDDSLcl->lpSurfMore;

        m_ddSLclRT.ddsCaps.dwCaps |= DDSCAPS_3DDEVICE;

        //
        // Fix up the surface global and more pointers
        //
        m_ddSLclRT.lpGbl      = &m_ddSGblRT;
        m_ddSLclRT.lpSurfMore = &m_ddSMoreRT;
    }

    // Ensure the contect handle list is setup
    R200SetCtxHandleList(m_pR200Ctx, this);

    if (m_bFirstRTSet == FALSE && (m_pHwCmdBuf) && (m_ddSLclRT.lpGbl))
    {
        // Rember that we have set the first RT
        m_bFirstRTSet = TRUE;

        // Complete context setup
        if (R200SetCtxtRT(m_pR200Ctx, this, &m_ddSLclRT) == FALSE)
        {
            return (DDERR_GENERIC);
        }
    }

    for (i = 0, pCurDDSLcl = pDDSLcl;
         i < pSurface->SurfCount;
         i++, pCurDDSLcl++)
    {
        DWORD dwHandle = pCurDDSLcl->lpSurfMore->dwSurfaceHandle;
        m_RTbl.Grow(dwHandle);

        if ((pSurface->Flags.VertexBuffer || pSurface->Flags.IndexBuffer)
            && pSurface->Flags.Dynamic)
        {
            m_RTbl[dwHandle].m_bDynamicBuffer = TRUE;
        }
        else
        {
            m_RTbl[dwHandle].m_bDynamicBuffer = FALSE;
        }

        m_RTbl[dwHandle].m_bValid         = TRUE;
        m_RTbl[dwHandle].m_hResRuntime    = pSurface->hResource;
        m_RTbl[dwHandle].m_dwResCaps      = pSurface->Flags;
        m_RTbl[dwHandle].m_d3dPool        = pSurface->Pool;
#ifndef KM_SYSMEM_PRESENT
        m_RTbl[dwHandle].m_d3dFormat      = pSurface->Format;
        m_RTbl[dwHandle].m_dwWidth        = pSurface->pSurfList[i].Width;
        m_RTbl[dwHandle].m_dwHeight       = pSurface->pSurfList[i].Height;
        m_RTbl[dwHandle].m_lPitch         = pSurface->pSurfList[i].SysMemPitch;
        m_RTbl[dwHandle].m_pSysMem        = (LPBYTE)pSurface->pSurfList[i].pSysMem;
#endif
        m_RTbl[dwHandle].m_dwNumExHandles = pSurface->SurfCount - i;
    }

    return (S_OK);
}

HRESULT CD3DContext::SetRenderState(CONST D3DDDIARG_RENDERSTATE* pRS)
{
    *((D3DDDIARG_RENDERSTATE*)GetBufferPointer(D3DDP2OP_RENDERSTATE, sizeof(D3DDDIARG_RENDERSTATE))) = *pRS;
    return (S_OK);
}

HRESULT CD3DContext::UpdateWInfo(CONST D3DDDIARG_WINFO* pWInfo)
{
    *((D3DDDIARG_WINFO*)GetBufferPointer(D3DDP2OP_WINFO, sizeof(D3DDDIARG_WINFO))) = *pWInfo;
    return (S_OK);
}

extern "C" HRESULT Rad2ValidateTextureStageState32(LPATID3DCNTX pContext, PUINT pNumPasses);

HRESULT CD3DContext::ValidateDevice(D3DDDIARG_VALIDATETEXTURESTAGESTATE* pValidateData)
{
    return Rad2ValidateTextureStageState32(m_pR200Ctx, &pValidateData->NumPasses);
}

HRESULT CD3DContext::SetTSS(CONST D3DDDIARG_TEXTURESTAGESTATE* pTSS)
{
    if (pTSS->State == D3DDDITSS_DISABLETEXTURECOLORKEY)
    {
        Flush(FALSE);

        return R200DisableColorKey(m_pR200Ctx, m_Tex[pTSS->Stage]);
    }
    else if (pTSS->State == D3DDDITSS_TEXTURECOLORKEYVAL)
    {
        Flush(FALSE);

        return R200SetSurfColorKeyVal(m_pR200Ctx, m_Tex[pTSS->Stage], pTSS->Value);
    }
    else
    {
        D3DHAL_DP2TEXTURESTAGESTATE*    pDP2TSS;
        pDP2TSS = (D3DHAL_DP2TEXTURESTAGESTATE*)GetBufferPointer(D3DDP2OP_TEXTURESTAGESTATE, sizeof(D3DHAL_DP2TEXTURESTAGESTATE));

        pDP2TSS->wStage  = (WORD)pTSS->Stage;
        pDP2TSS->TSState = (WORD)pTSS->State;
        pDP2TSS->dwValue = pTSS->Value;

        _ASSERT(pTSS->Type);

        return (S_OK);
    }
}

HRESULT CD3DContext::SetTexture(UINT Stage, HANDLE hTexture)
{
    LPD3DHAL_DP2TEXTURESTAGESTATE   pTSS;
    DWORD                           dwExHandle = (DWORD)(DWORD_PTR)hTexture;

    pTSS = (LPD3DHAL_DP2TEXTURESTAGESTATE)GetBufferPointer(D3DDP2OP_TEXTURESTAGESTATE, sizeof(D3DHAL_DP2TEXTURESTAGESTATE));

    pTSS->wStage  = (WORD)Stage;
    pTSS->TSState = 0;
    pTSS->dwValue = dwExHandle;

    _ASSERT(pTSS->dwValue < m_RTbl.Size());

    // Setting new texture handle for this texture stage
    m_Tex[pTSS->wStage] = pTSS->dwValue;
    m_RTbl[pTSS->dwValue].m_qwBatch = m_qwBatch;

    return (S_OK);
}

HRESULT CD3DContext::CreatePixelShader(D3DDDIARG_CREATEPIXELSHADER *pDDICreateShader, CONST UINT *pShader)
{
    HRESULT hr;

    Flush(FALSE);

    D3DHAL_DP2CREATEPIXELSHADER *pData = (D3DHAL_DP2CREATEPIXELSHADER *)GetBufferPointer(D3DDP2OP_CREATEPIXELSHADER, sizeof(D3DHAL_DP2CREATEPIXELSHADER) + pDDICreateShader->CodeSize);

    pData->dwCodeSize = pDDICreateShader->CodeSize;
    pData->dwHandle   = 0;

    memcpy(pData + 1, pShader, pDDICreateShader->CodeSize);

    hr = Flush(FALSE);

    pDDICreateShader->ShaderHandle = (HANDLE)(DWORD_PTR)pData->dwHandle;

    return (hr);
}

HRESULT CD3DContext::SetPixelShader(CONST HANDLE hPixelShader)
{
    ((D3DHAL_DP2PIXELSHADER *)GetBufferPointer(D3DDP2OP_SETPIXELSHADER, sizeof(D3DHAL_DP2PIXELSHADER)))->dwHandle = (DWORD)(DWORD_PTR)hPixelShader;
    return (S_OK);
}

HRESULT CD3DContext::DeletePixelShader(CONST HANDLE hPixelShader)
{
    ((D3DHAL_DP2PIXELSHADER *)GetBufferPointer(D3DDP2OP_DELETEPIXELSHADER, sizeof(D3DHAL_DP2PIXELSHADER)))->dwHandle = (DWORD)(DWORD_PTR)hPixelShader;
    return (S_OK);
}

HRESULT CD3DContext::SetPixelShaderConst(CONST D3DDDIARG_SETPIXELSHADERCONST* pSetShaderConst, CONST VOID *pConsts)
{
    D3DDDIARG_SETPIXELSHADERCONST* pData = (D3DDDIARG_SETPIXELSHADERCONST*)GetBufferPointer(D3DDP2OP_SETPIXELSHADERCONST, sizeof(D3DDDIARG_SETPIXELSHADERCONST) + (pSetShaderConst->Count << 4));
    *pData = *pSetShaderConst;
    memcpy(pData + 1, pConsts, pSetShaderConst->Count << 4);
    return (S_OK);
}

HRESULT CD3DContext::SetStreamSourceUM(CONST D3DDDIARG_SETSTREAMSOURCEUM* pSetUMStream, CONST VOID *pData)
{
    D3DHAL_DP2SETSTREAMSOURCEUM* pDP2UM = (LPD3DHAL_DP2SETSTREAMSOURCEUM)GetBufferPointer(D3DDP2OP_SETSTREAMSOURCEUM, sizeof(D3DHAL_DP2SETSTREAMSOURCEUM));


    pDP2UM->dwStream = pSetUMStream->Stream;
    pDP2UM->dwStride = pSetUMStream->Stride;

    //
    // Save the pointer for rendering, it is reset by R200HwFlush
    //
    m_pUMVertices = (LPBYTE)pData;

    m_dwVertexStride = pSetUMStream->Stream;

    return (S_OK);
}

HRESULT CD3DContext::SetIndices(CONST D3DDDIARG_SETINDICES* pSetIndices)
{
    LPD3DHAL_DP2SETINDICES  pSI;
    DWORD                   dwVBHandle;

    dwVBHandle = (DWORD)(DWORD_PTR)pSetIndices->hIndexBuffer;

    m_pUMIndices = NULL;

    _ASSERT(dwVBHandle < m_RTbl.Size());
    pSI = (D3DHAL_DP2SETINDICES *)GetBufferPointer(D3DDP2OP_SETINDICES, sizeof(D3DHAL_DP2SETINDICES));

    pSI->dwVBHandle = dwVBHandle;
    pSI->dwStride   = pSetIndices->Stride;

    if (dwVBHandle != 0)
    {
        m_RTbl[dwVBHandle].m_qwBatch = m_qwBatch;
    }

    m_IB = dwVBHandle;

    //
    // Record the stride for the index buffer
    //
    m_dwIndexSize = pSetIndices->Stride;

    return (S_OK);
}

HRESULT CD3DContext::SetIndicesUM(DWORD dwStride, CONST VOID *pData)
{
    m_pUMIndices  = pData;
    m_dwIndexSize = dwStride;

    return (S_OK);
}

HRESULT CD3DContext::DrawPrimitive(CONST D3DDDIARG_DRAWPRIMITIVE* pDP, CONST UINT* pEdgeFlags)
{


    // This sample driver is choosing to ignore the EdgeFlags, this will cause visual errors
    // and WHQL failures, the only reason the sample driver is doing this is to reduce the work
    // required to interface with the legacy DX8/9 driver code.
    // A production driver MUST abide by the EdgeFlags and perform the correct drawing operation
    *((D3DDDIARG_DRAWPRIMITIVE*)GetBufferPointer(D3DDP2OP_DRAWPRIMITIVE, sizeof(D3DDDIARG_DRAWPRIMITIVE))) = *pDP;

    //
    // Flush the command batch when vertex data is in user memory
    //
    if (m_pUMVertices)
    {
        Flush(FALSE);
    }

    return (S_OK);
}

HRESULT CD3DContext::DrawIndexedPrimitive(CONST D3DDDIARG_DRAWINDEXEDPRIMITIVE* pDIP)
{
    if (m_pUMIndices)
    {
        D3DDDIARG_DRAWINDEXEDPRIMITIVE2 dip2;

        dip2.PrimitiveType    = pDIP->PrimitiveType;
        dip2.BaseVertexOffset = pDIP->BaseVertexIndex*m_dwVertexStride;
        dip2.MinIndex         = pDIP->MinIndex;
        dip2.NumVertices      = pDIP->NumVertices;
        dip2.StartIndexOffset = pDIP->StartIndex*m_dwIndexSize;
        dip2.PrimitiveCount   = pDIP->PrimitiveCount;

        return (DrawIndexedPrimitive2(&dip2,
                                      m_dwIndexSize,
                                      m_pUMIndices,
                                      NULL));
    }

    *((D3DDDIARG_DRAWINDEXEDPRIMITIVE*)GetBufferPointer(D3DDP2OP_DRAWINDEXEDPRIMITIVE, sizeof(D3DDDIARG_DRAWINDEXEDPRIMITIVE))) = *pDIP;

    //
    // Flush the command batch when vertex data is in user memory
    //
    if (m_pUMVertices)
    {
        Flush(FALSE);
    }

    return (S_OK);
}

HRESULT CD3DContext::DrawRectPatch(CONST D3DDDIARG_DRAWRECTPATCH* pDrawRectPatch, CONST D3DDDIRECTPATCH_INFO *pPatchInfo, CONST FLOAT *pSegs)
{
    D3DHAL_DP2DRAWRECTPATCH* pData = (D3DHAL_DP2DRAWRECTPATCH*)GetBufferPointer(D3DDP2OP_DRAWRECTPATCH, sizeof(D3DHAL_DP2DRAWRECTPATCH) + (pPatchInfo != 0 ? sizeof(D3DRECTPATCH_INFO) : 0) + (pSegs != 0 ? sizeof(FLOAT) * 4 : 0));

    pData->Handle   = pDrawRectPatch->Handle;
    pData->Flags    = 0;

    DWORD offset;

    if (pSegs != 0)
    {
        offset = sizeof(FLOAT) * 4;
        memcpy(pData + 1, pSegs, offset);
        pData->Flags |= RTPATCHFLAG_HASSEGS;
    }
    else
    {
        offset = 0;
    }

    if (pPatchInfo != 0)
    {
        memcpy((BYTE*)(pData + 1) + offset, pPatchInfo, sizeof(D3DRECTPATCH_INFO));
        pData->Flags |= RTPATCHFLAG_HASINFO;
    }

    //
    // Flush the command batch when vertex data is in user memory
    //
    if (m_pUMVertices)
    {
        Flush(FALSE);
    }

    return (S_OK);
}

HRESULT CD3DContext::DrawTriPatch(CONST D3DDDIARG_DRAWTRIPATCH* pDrawTriPatch, CONST D3DDDITRIPATCH_INFO *pPatchInfo, CONST FLOAT *pSegs)
{
    D3DHAL_DP2DRAWTRIPATCH* pData = (D3DHAL_DP2DRAWTRIPATCH*)GetBufferPointer(D3DDP2OP_DRAWTRIPATCH, sizeof(D3DHAL_DP2DRAWTRIPATCH) + (pPatchInfo != 0 ? sizeof(D3DTRIPATCH_INFO) : 0) + (pSegs != 0 ? sizeof(FLOAT) * 3 : 0));

    pData->Handle   = pDrawTriPatch->Handle;
    pData->Flags    = 0;

    DWORD offset;

    if (pSegs != 0)
    {
        offset = sizeof(FLOAT) * 3;
        memcpy(pData + 1, pSegs, offset);
        pData->Flags |= RTPATCHFLAG_HASSEGS;
    }
    else
    {
        offset = 0;
    }

    if (pPatchInfo != 0)
    {
        memcpy((BYTE*)(pData + 1) + offset, pPatchInfo, sizeof(D3DTRIPATCH_INFO));
        pData->Flags |= RTPATCHFLAG_HASINFO;
    }

    //
    // Flush the command batch when vertex data is in user memory
    //
    if (m_pUMVertices)
    {
        Flush(FALSE);
    }

    return (S_OK);
}

HRESULT CD3DContext::DrawPrimitive2(CONST D3DDDIARG_DRAWPRIMITIVE2* pDP2)
{
    *((D3DDDIARG_DRAWPRIMITIVE2*)GetBufferPointer(D3DDP2OP_DRAWPRIMITIVE2, sizeof(D3DDDIARG_DRAWPRIMITIVE2))) = *pDP2;

    //
    // Flush the command batch when vertex data is in user memory
    //
    if (m_pUMVertices)
    {
        Flush(FALSE);
    }

    return (S_OK);
}

DWORD
GetNumVertices(
    D3DPRIMITIVETYPE    d3dPrimType,
    DWORD               dwPrimCount)
{
    DWORD   dwVerticesPerPrim[D3DPT_TRIANGLEFAN + 1] =
        {
            0,          // Not used
            1,          // D3DPT_POINTLIST
            2,          // D3DPT_LINELIST
            2,          // D3DPT_LINESTRIP
            3,          // D3DPT_TRIANGLELIST
            3,          // D3DPT_TRIANGLESTRIP
            3           // D3DPT_TRIANGLEFAN
        };
    DWORD   dwStridePerPrim[D3DPT_TRIANGLEFAN + 1] =
        {
            0,          // Not used
            1,          // D3DPT_POINTLIST
            2,          // D3DPT_LINELIST
            1,          // D3DPT_LINESTRIP
            3,          // D3DPT_TRIANGLELIST
            1,          // D3DPT_TRIANGLESTRIP
            1           // D3DPT_TRIANGLEFAN
        };

    if ((d3dPrimType < D3DPT_POINTLIST) || (d3dPrimType > D3DPT_TRIANGLEFAN))
    {
        return (0);
    }

    return (dwVerticesPerPrim[d3dPrimType] +
            dwStridePerPrim[d3dPrimType]*(dwPrimCount - 1));
}

HRESULT CD3DContext::DrawIndexedPrimitive2(CONST D3DDDIARG_DRAWINDEXEDPRIMITIVE2* pDIP2, DWORD dwIndexSize, CONST VOID *pIndices, CONST UINT* pdw)
{
    HRESULT hr;
    DWORD   dwNumIndices;

    hr = InitializeIntIB();
    if (FAILED(hr))
    {
        return (hr);
    }

    // Copy index into the internal index buffer
    dwNumIndices = GetNumVertices(pDIP2->PrimitiveType, pDIP2->PrimitiveCount);

    //
    //Production driver should not hard code the indices
    //It should be able to handle arbitrary sized index buffers
    //
    if ((! dwNumIndices) || (dwNumIndices > MAX_NUM_INDICES_INT_IB))
    {
        DBG_BREAK;
        return (DDERR_INVALIDPARAMS);
    }
    memcpy((LPVOID)m_ddSGblIntIB.fpVidMem,
           pIndices,
           dwIndexSize*dwNumIndices);

    // Set internal index buffer to current
    LPD3DHAL_DP2SETINDICES pDP2SI = (LPD3DHAL_DP2SETINDICES)GetBufferPointer(D3DDP2OP_SETINDICES, sizeof(D3DHAL_DP2SETINDICES));
    pDP2SI->dwVBHandle = m_ddSMoreIntIB.dwSurfaceHandle;
    pDP2SI->dwStride   = dwIndexSize;

    *((D3DDDIARG_DRAWINDEXEDPRIMITIVE2*)GetBufferPointer(D3DDP2OP_DRAWINDEXEDPRIMITIVE2, sizeof(D3DDDIARG_DRAWINDEXEDPRIMITIVE2))) = *pDIP2;

    // Set the index buffer to NULL
    pDP2SI = (LPD3DHAL_DP2SETINDICES)GetBufferPointer(D3DDP2OP_SETINDICES, sizeof(D3DHAL_DP2SETINDICES));
    pDP2SI->dwVBHandle = 0;
    pDP2SI->dwStride   = 0;

    Flush(FALSE);

    return (S_OK);
}

HRESULT CD3DContext::VolBlt(CONST D3DDDIARG_VOLUMEBLT* pVolBlt)
{
    DWORD                   dwDDSrcSurface  = (DWORD)(DWORD_PTR)pVolBlt->hSrcResource;
    DWORD                   dwDDDestSurface = (DWORD)(DWORD_PTR)pVolBlt->hDstResource;
    D3DHAL_DP2VOLUMEBLT    *pDP2VolBlt;

    _ASSERT(dwDDSrcSurface < m_RTbl.Size());
    _ASSERT(dwDDDestSurface < m_RTbl.Size());

    // DP2 token has a flags field, so we need to convert
    pDP2VolBlt = (D3DHAL_DP2VOLUMEBLT *)GetBufferPointer(D3DDP2OP_VOLUMEBLT, sizeof(D3DHAL_DP2VOLUMEBLT));
    pDP2VolBlt->dwDDDestSurface = dwDDDestSurface;
    pDP2VolBlt->dwDDSrcSurface  = dwDDSrcSurface;
    pDP2VolBlt->dwDestX         = pVolBlt->DstX;
    pDP2VolBlt->dwDestY         = pVolBlt->DstY;
    pDP2VolBlt->dwDestZ         = pVolBlt->DstZ;
    _ASSERT(sizeof(D3DBOX) == sizeof(D3DDDIBOX));
    memcpy(&pDP2VolBlt->srcBox, &pVolBlt->SrcBox, sizeof(D3DBOX));
    pDP2VolBlt->dwFlags         = 0;

    m_RTbl[dwDDSrcSurface].m_qwBatch = m_qwBatch;
    m_RTbl[dwDDDestSurface].m_qwBatch = m_qwBatch;

    return (S_OK);
}

HRESULT CD3DContext::BufBlt(CONST D3DDDIARG_BUFFERBLT* pBufBlt)
{
    DWORD                   dwDDSrcSurface  = (DWORD)(DWORD_PTR)pBufBlt->hSrcResource;
    DWORD                   dwDDDestSurface = (DWORD)(DWORD_PTR)pBufBlt->hDstResource;
    D3DHAL_DP2BUFFERBLT    *pDP2BufBlt;

    _ASSERT(dwDDSrcSurface < m_RTbl.Size());
    _ASSERT(dwDDDestSurface < m_RTbl.Size());

    // DP2 token has a flags field, so we need to convert
    pDP2BufBlt = (D3DHAL_DP2BUFFERBLT *)GetBufferPointer(D3DDP2OP_BUFFERBLT, sizeof(D3DHAL_DP2BUFFERBLT));
    pDP2BufBlt->dwDDDestSurface = dwDDDestSurface;
    pDP2BufBlt->dwDDSrcSurface  = dwDDSrcSurface;
    pDP2BufBlt->dwOffset        = pBufBlt->Offset;
    pDP2BufBlt->rSrc.Offset     = pBufBlt->SrcRange.Offset;
    pDP2BufBlt->rSrc.Size       = pBufBlt->SrcRange.Size;
    pDP2BufBlt->dwFlags         = 0;

    m_RTbl[dwDDSrcSurface].m_qwBatch  = m_qwBatch;
    m_RTbl[dwDDDestSurface].m_qwBatch = m_qwBatch;

    return (S_OK);
}

HRESULT CD3DContext::TexBlt(CONST D3DDDIARG_TEXBLT* pTexBlt)
{
    DWORD               dwDDSrcSurface = (DWORD)(DWORD_PTR)pTexBlt->hSrcResource;
    DWORD               dwDDDstSurface = (DWORD)(DWORD_PTR)pTexBlt->hDstResource;
    D3DHAL_DP2TEXBLT   *pDP2TexBlt;

    _ASSERT(dwDDSrcSurface < m_RTbl.Size());
    _ASSERT(dwDDDestSurface < m_RTbl.Size());

    CResource           &resDst = m_RTbl[dwDDDstSurface];

    pDP2TexBlt = (D3DHAL_DP2TEXBLT *)GetBufferPointer(D3DDP2OP_TEXBLT, sizeof(D3DHAL_DP2TEXBLT));

    resDst.m_qwBatch                 = m_qwBatch;
    m_RTbl[dwDDSrcSurface].m_qwBatch = m_qwBatch;

    //
    // For cubemap, resource to surface handle translation is necessary
    //
    if (resDst.m_dwResCaps.CubeMap)
    {
        DWORD   dwFaceOffset = pTexBlt->CubeMapFace*resDst.m_dwNumExHandles/6;

        dwDDDstSurface += dwFaceOffset;
        dwDDSrcSurface += dwFaceOffset;
    }

    pDP2TexBlt->dwDDDestSurface = dwDDDstSurface;
    pDP2TexBlt->dwDDSrcSurface  = dwDDSrcSurface;

    pDP2TexBlt->pDest   = pTexBlt->DstPoint;
    pDP2TexBlt->rSrc    = *((RECTL *)&pTexBlt->SrcRect);
    pDP2TexBlt->dwFlags = 0;

    return (S_OK);
}

HRESULT CD3DContext::StateSet(D3DDDIARG_STATESET* pStateSet)
{
    HRESULT hr = S_OK;
    D3DHAL_DP2STATESET *pData;

    if ((pStateSet->Operation == D3DHAL_STATESETBEGIN) ||
        (pStateSet->Operation == D3DHAL_STATESETCREATE))
    {
        Flush(FALSE);
    }

    pData = ((D3DHAL_DP2STATESET *)GetBufferPointer(D3DDP2OP_STATESET, sizeof(D3DHAL_DP2STATESET)));

    pData->dwOperation = pStateSet->Operation;
    pData->sbType      = pStateSet->StateBlockType;

    if ((pStateSet->Operation == D3DHAL_STATESETBEGIN) ||
        (pStateSet->Operation == D3DHAL_STATESETCREATE))
    {
        pData->dwParam = 0;

        hr = Flush(FALSE);

        //
        // Return the state set handle to the runtime
        //
        pStateSet->hStateSet = (HANDLE)(DWORD_PTR)pData->dwParam;
    }
    else
    {
        pData->dwParam = (DWORD)(DWORD_PTR)pStateSet->hStateSet;
    }

    return (hr);
}

HRESULT CD3DContext::SetPriority(CONST D3DDDIARG_SETPRIORITY* pSetPriority)
{
    DWORD                   dwSurfaceHandle = (DWORD)(DWORD_PTR)pSetPriority->hResource;
    CResource              &res = m_RTbl[dwSurfaceHandle];
    D3DDDICB_SETPRIORITY    setPri;
    UINT                    priority;

    _ASSERT(dwDDSurface < m_RTbl.Size());

    priority = pSetPriority->Priority;

    memset(&setPri, 0, sizeof(setPri));

    setPri.hResource   = res.m_hResRuntime;
    setPri.pPriorities = &priority;

    return (m_d3dCallbacks.pfnSetPriorityCb(m_hD3D, &setPri));
}


HRESULT CD3DContext::Clear(CONST D3DDDIARG_CLEAR* pClear, UINT ClrCount, CONST RECT* pClrRects)
{
    const DWORD C_CLEAR_CMD_SIZE = sizeof(D3DHAL_DP2COMMAND) + sizeof(D3DHAL_DP2CLEAR); // command size for one rect.

    DWORD cntRect = ClrCount;        // rect. to be sent

    while(true)
    {
        if ( m_dwDP2CmdBufSize >= m_dwDP2CmdPos + C_CLEAR_CMD_SIZE) // do we have space for command ?
        {
            DWORD nRectAvl = (m_dwDP2CmdBufSize - m_dwDP2CmdPos - C_CLEAR_CMD_SIZE)/sizeof(RECT) + 1; // one rect. is included in D3DHAL_DP2CLEAR
            DWORD cntRectToBeSentNow = (nRectAvl < cntRect)?nRectAvl:cntRect; //  how many rect. will we send?

            LPD3DHAL_DP2COMMAND lpDP2CurrCommand = (LPD3DHAL_DP2COMMAND)(m_pDP2CmdBuf + m_dwDP2CmdPos);
            lpDP2CurrCommand->bCommand = D3DDP2OP_CLEAR;
            lpDP2CurrCommand->bReserved = 0;
            lpDP2CurrCommand->wStateCount = (WORD)cntRectToBeSentNow;
            D3DHAL_DP2CLEAR* pData = (D3DHAL_DP2CLEAR*)(lpDP2CurrCommand + 1);
            pData->dvFillDepth = pClear->FillDepth;
            pData->dwFillColor = pClear->FillColor;
            pData->dwFillStencil = pClear->FillStencil;
            pData->dwFlags = pClear->Flags;
            if (cntRectToBeSentNow > 0)
            {
                memcpy(pData->Rects, pClrRects, cntRectToBeSentNow * sizeof(RECT));
            }
            m_dwDP2CmdPos += (C_CLEAR_CMD_SIZE + sizeof(RECT) * (cntRectToBeSentNow - 1));

            if (cntRectToBeSentNow < cntRect) // update counter and pntr properly
            {
                pClrRects += cntRectToBeSentNow;
                cntRect -= cntRectToBeSentNow;
                Flush(FALSE);   //  buffer is full, flush it
            }
            else
            {
                break;  //  all done
            }
        }
        else
        {
            Flush(FALSE); 
        }
    }
    return (S_OK);
}

HRESULT CD3DContext::UpdatePalette(CONST D3DDDIARG_UPDATEPALETTE* pUpdatePalette, CONST PALETTEENTRY *pEntries)
{
    D3DHAL_DP2UPDATEPALETTE* pDP2UpdatePalette = (D3DHAL_DP2UPDATEPALETTE*)GetBufferPointer(D3DDP2OP_UPDATEPALETTE, sizeof(D3DHAL_DP2UPDATEPALETTE) + pUpdatePalette->NumEntries * sizeof(PALETTEENTRY));
    pDP2UpdatePalette->dwPaletteHandle = pUpdatePalette->PaletteHandle;
    pDP2UpdatePalette->wStartIndex = (WORD)pUpdatePalette->StartIndex;
    pDP2UpdatePalette->wNumEntries = (WORD)pUpdatePalette->NumEntries;
    memcpy(pDP2UpdatePalette + 1, pEntries, pUpdatePalette->NumEntries * sizeof(PALETTEENTRY));
    return (S_OK);
}

HRESULT CD3DContext::SetPalette(CONST D3DDDIARG_SETPALETTE* pSetPalette)
{
    DWORD dwSurfaceHandle = (DWORD)(DWORD_PTR)pSetPalette->hResource;

    _ASSERT(dwSurfaceHandle < m_RTbl.Size());
    *((D3DDDIARG_SETPALETTE*)GetBufferPointer(D3DDP2OP_SETPALETTE, sizeof(D3DDDIARG_SETPALETTE))) = *pSetPalette;
    m_RTbl[dwSurfaceHandle].m_qwBatch = m_qwBatch;
    return (S_OK);
}

HRESULT CD3DContext::SetVertexShaderConst(CONST D3DDDIARG_SETVERTEXSHADERCONST* pSetShaderConst, CONST VOID *pConsts)
{
    D3DDDIARG_SETVERTEXSHADERCONST* pData = (D3DDDIARG_SETVERTEXSHADERCONST*)GetBufferPointer(D3DDP2OP_SETVERTEXSHADERCONST, sizeof(D3DDDIARG_SETVERTEXSHADERCONST) + (pSetShaderConst->Count << 4));
    *pData = *pSetShaderConst;
    memcpy(pData + 1, pConsts, pSetShaderConst->Count << 4);
    return (S_OK);
}

HRESULT CD3DContext::MultiplyTransform(CONST D3DDDIARG_MULTIPLYTRANSFORM* pTransform)
{
    *((D3DDDIARG_MULTIPLYTRANSFORM*)GetBufferPointer(D3DDP2OP_MULTIPLYTRANSFORM, sizeof(D3DDDIARG_MULTIPLYTRANSFORM))) = *pTransform;
    return (S_OK);
}

HRESULT CD3DContext::SetTransform(CONST D3DDDIARG_SETTRANSFORM* pTransform)
{
    *((D3DDDIARG_SETTRANSFORM*)GetBufferPointer(D3DDP2OP_SETTRANSFORM, sizeof(D3DDDIARG_SETTRANSFORM))) = *pTransform;
    return (S_OK);
}

HRESULT CD3DContext::SetViewport(CONST D3DDDIARG_VIEWPORTINFO* pViewport)
{
    *((D3DDDIARG_VIEWPORTINFO*)GetBufferPointer(D3DDP2OP_VIEWPORTINFO, sizeof(D3DDDIARG_VIEWPORTINFO))) = *pViewport;
    return (S_OK);
}

HRESULT CD3DContext::SetZRange(CONST D3DDDIARG_ZRANGE* pZRange)
{
    *((D3DDDIARG_ZRANGE*)GetBufferPointer(D3DDP2OP_ZRANGE, sizeof(D3DDDIARG_ZRANGE))) = *pZRange;
    return (S_OK);
}

HRESULT CD3DContext::SetMaterial(CONST D3DDDIARG_SETMATERIAL* pMaterial)
{
    *((D3DDDIARG_SETMATERIAL*)GetBufferPointer(D3DDP2OP_SETMATERIAL, sizeof(D3DDDIARG_SETMATERIAL))) = *pMaterial;
    return (S_OK);
}

HRESULT CD3DContext::SetLight(CONST D3DDDIARG_SETLIGHT* pSetLight, CONST D3DDDI_LIGHT *pLight)
{
    if (pSetLight->DataType == D3DHAL_SETLIGHT_DATA)
    {
        D3DDDIARG_SETLIGHT* pData = (D3DDDIARG_SETLIGHT*)GetBufferPointer(D3DDP2OP_SETLIGHT, sizeof(D3DDDIARG_SETLIGHT) + sizeof(D3DLIGHT9));
        *pData = *pSetLight;
        memcpy(pData + 1, pLight, sizeof(D3DLIGHT9));
    }
    else
    {
        *((D3DDDIARG_SETLIGHT*)GetBufferPointer(D3DDP2OP_SETLIGHT, sizeof(D3DDDIARG_SETLIGHT))) = *pSetLight;
    }
    return (S_OK);
}

HRESULT CD3DContext::CreateLight(CONST D3DDDIARG_CREATELIGHT* pCreateLight)
{
    *((D3DDDIARG_CREATELIGHT*)GetBufferPointer(D3DDP2OP_CREATELIGHT, sizeof(D3DDDIARG_CREATELIGHT))) = *pCreateLight;
    return (S_OK);
}

HRESULT CD3DContext::DestroyLight(CONST D3DDDIARG_DESTROYLIGHT* pDestroyLight)
{
    Flush(FALSE);

    //
    // R200 driver doesn't keep track of individual lights
    // All lights are stored in an array that grows dynamically, and memory is
    // reused when new light gets created, also R200 drivers allows only 1024
    // software lights. So it is not really necessary to do anything here.
    //
    return (S_OK);
}

HRESULT CD3DContext::SetClipPlane(CONST D3DDDIARG_SETCLIPPLANE* pSetClipPlane)
{
    *((D3DDDIARG_SETCLIPPLANE*)GetBufferPointer(D3DDP2OP_SETCLIPPLANE, sizeof(D3DDDIARG_SETCLIPPLANE))) = *pSetClipPlane;
    return (S_OK);
}

HRESULT CD3DContext::GetInfo(UINT dwDevInfoID, VOID* pDevInfoStruct, UINT dwSize)
{
    return (E_NOTIMPL);
}

HRESULT CD3DContext::Lock(D3DDDIARG_LOCK* pLockData)
{
    DWORD       dwSurfaceHandle    = (DWORD)(DWORD_PTR)pLockData->hResource;
    CResource  &res                = m_RTbl[dwSurfaceHandle];

#ifndef VBRENAMING
    pLockData->Flags.Discard = FALSE;
#endif

    //
    // Flush the command buffer only when necessary
    //
    if (!pLockData->Flags.NoOverwrite && !pLockData->Flags.Discard && (res.m_qwBatch >= m_qwBatch))
    {
        if (pLockData->Flags.NotifyOnly)
        {
            //
            // Locking a system memory resource, flush only the DP2 batch
            //
            _ASSERT(res.m_d3dPool == D3DDDIPOOL_SYSTEMMEM);
            Flush(FALSE);
        }
        else
        {
            //
            // Locking a video memory resource, flush both DP2 and HW batch
            //
        Flush(TRUE);
        }

    }

    //
    // Flush only the DP2 command batch;
    // The decision to flush the HW command batch is made by VB lock routine.
    //
    if (pLockData->Flags.Discard && !pLockData->Flags.NoOverwrite && (res.m_qwBatch >= m_qwBatch))
    {
        Flush(FALSE);
    }

    if (pLockData->Flags.NotifyOnly)
    {
        _ASSERT(res.m_d3dPool == D3DDDIPOOL_SYSTEMMEM);


        // There is nothing else to do other than above possible sync and flush
        return S_OK;
    }

    if (res.m_bDynamicBuffer)
    {
        if ((!pLockData->Flags.ReadOnly && !pLockData->Flags.NoOverwrite) ||
            (res.m_pVidmem == 0))
        {
            HRESULT hr;

            if (res.m_pVidmem != 0)
            {
                D3DDDIARG_UNLOCK unlockData;
                _ASSERT(res.m_hSurface != 0);

                unlockData.hResource = pLockData->hResource;
                unlockData.SubResourceIndex = pLockData->SubResourceIndex;
                hr = D3DDDIUnlockResource(m_pR200Ctx, &unlockData);
                if (FAILED(hr))
                {
                    return (hr);
                }
            }

            hr = R200LockResource(m_pR200Ctx, pLockData);
            if (FAILED(hr))
            {
                res.m_pVidmem = 0;
                return (hr);
            }

            res.m_pVidmem = pLockData->pSurfData;
        }
        else
        {
            pLockData->pSurfData = res.m_pVidmem;
        }

        return (S_OK);
    }
    else
    {
        return R200LockResource(m_pR200Ctx, pLockData);
    }
}

HRESULT CD3DContext::Unlock(CONST D3DDDIARG_UNLOCK* pUnlockData)
{
    DWORD       dwResource = (DWORD)(DWORD_PTR)pUnlockData->hResource;
    CResource  &res = m_RTbl[dwResource];

    //why check m_pR200Ctx, ie might create a context that we didn't
    //even have m_pR200Ctx created with. Without this check explorer will
    //by hiiting m_pR200Ctx == NULL, we could even ignore D3DDDIPOOL_SYSTEMMEM
    //altogether though.

    if ((!res.m_bDynamicBuffer) && m_pR200Ctx)
    {
        //
        // NOTE: Swap chain is treated as an atomic resource
        //
        if (pUnlockData->SubResourceIndex > res.m_dwNumExHandles)
        {
            return (DDERR_INVALIDPARAMS);
        }



        if (pUnlockData->Flags.NotifyOnly)
        {
            _ASSERT(res.m_d3dPool == D3DDDIPOOL_SYSTEMMEM);

            return S_OK;
        }

        HRESULT hr = (D3DDDIUnlockResource(m_pR200Ctx,
                                     pUnlockData));
        return hr;
    }
    else
    {
        return (S_OK);
    }
}

HRESULT
R200UnlockAllocationCB(
    LPVOID          pD3DDev,
    D3DKMT_HANDLE   hAllocation)
{
    CD3DContext    *pD3DCtxt;

    pD3DCtxt = reinterpret_cast<CD3DContext*>(pD3DDev);

    return (pD3DCtxt->UnlockAllocationCB(hAllocation));
}

HRESULT
CD3DContext::UnlockAllocationCB(
    D3DKMT_HANDLE   hAllocation)
{
    D3DDDICB_UNLOCK Unlock;

    Unlock.NumAllocations = 1;
    Unlock.phAllocations  = &hAllocation;

    return (m_d3dCallbacks.pfnUnlockCb(m_hD3D, &Unlock));
}


HRESULT CD3DContext::Flush(BOOL bToKMD)
{
    HRESULT hr = S_OK;

    hr = R200HwFlush(m_pR200Ctx, m_pDP2CmdBuf, m_dwDP2CmdPos, m_pUMVertices, bToKMD);

    //
    // Reset UM vertex pointer to NULL
    //
    m_pUMVertices = NULL;

    // m_d3dCallbacks.pfnDrawPrimitives2Cb(m_hD3D, m_dwXXXCmdPos, NULL, 0, 0);

    // Reset the location to write new commands
    m_dwDP2CmdPos = 0;

    if (! bToKMD)
    {
        return (hr);
    }

    // Increase the batch sequence number
    m_qwBatch++;

    // Rebatch
    m_RTbl[m_RT].m_qwBatch = m_qwBatch;
    m_RTbl[m_ZB].m_qwBatch = m_qwBatch;

    for (DWORD i = 0; i < 8; ++i)
    {
        if (m_Tex[i] != 0)
        {
            m_RTbl[m_Tex[i]].m_qwBatch = m_qwBatch;
        }
    }

    m_RTbl[m_IB].m_qwBatch = m_qwBatch;
    for (DWORD i = 0; i < 16; ++i)
    {
        if (m_VB[i] != 0)
        {
            m_RTbl[m_VB[i]].m_qwBatch = m_qwBatch;
        }
    }


    return (hr);
}

//
// DX9 DDI support functions
//
HRESULT CD3DContext::CreateVertexShaderDecl(D3DDDIARG_CREATEVERTEXSHADERDECL* pDDICreateVSDecl, CONST D3DDDIVERTEXELEMENT *pDeclElems)
{
    HRESULT hr;

    Flush(FALSE);

    D3DHAL_DP2CREATEVERTEXSHADERDECL *pData = (D3DHAL_DP2CREATEVERTEXSHADERDECL *)GetBufferPointer(D3DDP2OP_CREATEVERTEXSHADERDECL, sizeof(D3DHAL_DP2CREATEVERTEXSHADERDECL) + pDDICreateVSDecl->NumVertexElements*sizeof(D3DVERTEXELEMENT9));

    pData->dwNumVertexElements = pDDICreateVSDecl->NumVertexElements;
    pData->dwHandle = 0;

    LPBYTE p = (LPBYTE)(pData + 1);
    memcpy(p, pDeclElems, pDDICreateVSDecl->NumVertexElements*sizeof(D3DVERTEXELEMENT9));

    hr = Flush(FALSE);

    pDDICreateVSDecl->ShaderHandle = (HANDLE)(DWORD_PTR)pData->dwHandle;

    return (hr);
}

HRESULT CD3DContext::DeleteVertexShaderDecl(CONST HANDLE hVSDecl)
{
    ((D3DHAL_DP2VERTEXSHADER *)GetBufferPointer(D3DDP2OP_DELETEVERTEXSHADERDECL, sizeof(D3DHAL_DP2VERTEXSHADER)))->dwHandle = (DWORD)(DWORD_PTR)hVSDecl;
    return (S_OK);
}

HRESULT CD3DContext::SetVertexShaderDecl(CONST HANDLE hVSDecl)
{
    ((D3DHAL_DP2VERTEXSHADER *)GetBufferPointer(D3DDP2OP_SETVERTEXSHADERDECL, sizeof(D3DHAL_DP2VERTEXSHADER)))->dwHandle = (DWORD)(DWORD_PTR)hVSDecl;
    return (S_OK);
}

HRESULT CD3DContext::CreateVertexShaderFunc(D3DDDIARG_CREATEVERTEXSHADERFUNC* pDDICreateVSFunc, CONST UINT* pCode)
{
    HRESULT hr;

    Flush(FALSE);

    D3DHAL_DP2CREATEVERTEXSHADERFUNC *pData = (D3DHAL_DP2CREATEVERTEXSHADERFUNC *)GetBufferPointer(D3DDP2OP_CREATEVERTEXSHADERFUNC, sizeof(D3DHAL_DP2CREATEVERTEXSHADERFUNC) + pDDICreateVSFunc->Size);

    pData->dwSize   = pDDICreateVSFunc->Size;
    pData->dwHandle = 0;

    LPBYTE p = (LPBYTE)(pData + 1);
    memcpy(p, pCode, pDDICreateVSFunc->Size);

    hr = Flush(FALSE);

    pDDICreateVSFunc->ShaderHandle = (HANDLE)(DWORD_PTR)pData->dwHandle;

    return hr;
}

HRESULT CD3DContext::DeleteVertexShaderFunc(CONST HANDLE hVSFunc)
{
    ((D3DHAL_DP2VERTEXSHADER *)GetBufferPointer(D3DDP2OP_DELETEVERTEXSHADERFUNC, sizeof(D3DHAL_DP2VERTEXSHADER)))->dwHandle = (DWORD)(DWORD_PTR)hVSFunc;
    return (S_OK);
}

HRESULT CD3DContext::SetVertexShaderFunc(CONST HANDLE hVSFunc)
{
    ((D3DHAL_DP2VERTEXSHADER *)GetBufferPointer(D3DDP2OP_SETVERTEXSHADERFUNC, sizeof(D3DHAL_DP2VERTEXSHADER)))->dwHandle = (DWORD)(DWORD_PTR)hVSFunc;
    return (S_OK);
}

HRESULT CD3DContext::SetVertexShaderConstI(CONST D3DDDIARG_SETVERTEXSHADERCONSTI* pDP2SetVSConstI, CONST int *pConstI)
{
    D3DDDIARG_SETVERTEXSHADERCONSTI* pData = (D3DDDIARG_SETVERTEXSHADERCONSTI*)GetBufferPointer(D3DDP2OP_SETVERTEXSHADERCONSTI, sizeof(D3DDDIARG_SETVERTEXSHADERCONSTI) + pDP2SetVSConstI->Count*sizeof(int));
    *pData = *pDP2SetVSConstI;
    LPBYTE p = (LPBYTE)(pData + 1);
    memcpy(p, pConstI, pDP2SetVSConstI->Count*sizeof(int));

    return (S_OK);
}

HRESULT CD3DContext::SetVertexShaderConstB(CONST D3DDDIARG_SETVERTEXSHADERCONSTB* pDP2SetVSConstB, CONST BOOL *pConstB)
{
    D3DDDIARG_SETVERTEXSHADERCONSTB* pData = (D3DDDIARG_SETVERTEXSHADERCONSTB*)GetBufferPointer(D3DDP2OP_SETVERTEXSHADERCONSTB, sizeof(D3DDDIARG_SETVERTEXSHADERCONSTB) + pDP2SetVSConstB->Count*sizeof(BOOL));
    *pData = *pDP2SetVSConstB;
    LPBYTE p = (LPBYTE)(pData + 1);
    memcpy(p, pConstB, pDP2SetVSConstB->Count*sizeof(BOOL));

    return (S_OK);
}

HRESULT CD3DContext::SetPixelShaderConstI(CONST D3DDDIARG_SETPIXELSHADERCONSTI* pDP2SetPSConstI, CONST int *pConstI)
{
    D3DDDIARG_SETPIXELSHADERCONSTI* pData = (D3DDDIARG_SETPIXELSHADERCONSTI*)GetBufferPointer(D3DDP2OP_SETPIXELSHADERCONSTI, sizeof(D3DDDIARG_SETPIXELSHADERCONSTI) + pDP2SetPSConstI->Count*sizeof(int));
    *pData = *pDP2SetPSConstI;
    LPBYTE p = (LPBYTE)(pData + 1);
    memcpy(p, pConstI, pDP2SetPSConstI->Count*sizeof(int));

    return (S_OK);
}

HRESULT CD3DContext::SetPixelShaderConstB(CONST D3DDDIARG_SETPIXELSHADERCONSTB* pDP2SetPSConstB, CONST BOOL *pConstB)
{
    D3DDDIARG_SETPIXELSHADERCONSTB* pData = (D3DDDIARG_SETPIXELSHADERCONSTB*)GetBufferPointer(D3DDP2OP_SETPIXELSHADERCONSTB, sizeof(D3DDDIARG_SETPIXELSHADERCONSTB) + pDP2SetPSConstB->Count*sizeof(BOOL));
    *pData = *pDP2SetPSConstB;
    LPBYTE p = (LPBYTE)(pData + 1);
    memcpy(p, pConstB, pDP2SetPSConstB->Count*sizeof(BOOL));

    return (S_OK);
}

HRESULT CD3DContext::SetStreamSource2(CONST D3DDDIARG_SETSTREAMSOURCE* pSetStreamSrc)
{
    LPD3DHAL_DP2SETSTREAMSOURCE2    pSSS2;
    DWORD                           dwVBHandle;

    dwVBHandle = (DWORD)(DWORD_PTR)pSetStreamSrc->hVertexBuffer;

    _ASSERT(dwVBHandle < m_RTbl.Size());

    pSSS2 = (D3DHAL_DP2SETSTREAMSOURCE2 *)GetBufferPointer(D3DDP2OP_SETSTREAMSOURCE2, sizeof(D3DHAL_DP2SETSTREAMSOURCE2));

    pSSS2->dwStream   = pSetStreamSrc->Stream;
    pSSS2->dwVBHandle = dwVBHandle;
    pSSS2->dwOffset   = pSetStreamSrc->Offset;
    pSSS2->dwStride   = pSetStreamSrc->Stride;

    if (dwVBHandle != 0)
    {
        m_RTbl[dwVBHandle].m_qwBatch = m_qwBatch;
    }
    m_VB[pSetStreamSrc->Stream] = dwVBHandle;

    if (0 == pSetStreamSrc->Stream)
    {
        m_dwVertexStride = pSetStreamSrc->Stride;
    }

    return (S_OK);
}

HRESULT CD3DContext::SetRenderTarget2(CONST D3DDDIARG_SETRENDERTARGET* pDP2SetRenderTarget2)
{
    LPD3DHAL_DP2SETRENDERTARGET2    pSRT2;
    DWORD                           dwRenderTarget;

    pSRT2 = (LPD3DHAL_DP2SETRENDERTARGET2)GetBufferPointer(D3DDP2OP_SETRENDERTARGET2, sizeof(D3DHAL_DP2SETRENDERTARGET2));

    //
    // Get sub level EX handle for cubemap and mipmap RT
    //
    dwRenderTarget =
        R200GetSubLevelExHandle(m_pR200Ctx,
                                pDP2SetRenderTarget2->hRenderTarget,
                                pDP2SetRenderTarget2->SubResourceIndex);
    if ((pDP2SetRenderTarget2->hRenderTarget) && (! dwRenderTarget))
    {
        return (DDERR_INVALIDPARAMS);
    }

    //
    // Set the render target into the command batch
    //
    pSRT2->RTIndex       = pDP2SetRenderTarget2->RenderTargetIndex;
    pSRT2->hRenderTarget = dwRenderTarget;

    _ASSERT(dwRenderTarget < m_RTbl.Size());

    m_RT = dwRenderTarget;
    m_RTbl[dwRenderTarget].m_qwBatch = m_qwBatch;

    m_hRenderTarget = pDP2SetRenderTarget2->hRenderTarget;
    m_RenderTargetIndex = pDP2SetRenderTarget2->SubResourceIndex;

    return (S_OK);
}

HRESULT CD3DContext::SetDepthStencil(CONST D3DDDIARG_SETDEPTHSTENCIL* pDP2SetDepthStencil)
{
    DWORD dwZBuffer = (DWORD)(DWORD_PTR)pDP2SetDepthStencil->hZBuffer;

    _ASSERT(dwZBuffer < m_RTbl.Size());

    *((DWORD *)GetBufferPointer(D3DDP2OP_SETDEPTHSTENCIL, sizeof(D3DHAL_DP2SETDEPTHSTENCIL))) = dwZBuffer;

    m_ZB = dwZBuffer;
    m_RTbl[dwZBuffer].m_qwBatch = m_qwBatch;

    return (S_OK);
}

HRESULT CD3DContext::SetScissorRect(CONST RECT* pRect)
{
    *((LPD3DHAL_DP2SETSCISSORRECT)GetBufferPointer(D3DDP2OP_SETSCISSORRECT, sizeof(RECT))) = *pRect;
    return (S_OK);
}

HRESULT CD3DContext::GenerateMipSubLevels(CONST D3DDDIARG_GENERATEMIPSUBLEVELS* pDP2GenMipLevels)
{
    *((D3DDDIARG_GENERATEMIPSUBLEVELS*)GetBufferPointer(D3DDP2OP_GENERATEMIPSUBLEVELS, sizeof(D3DDDIARG_GENERATEMIPSUBLEVELS))) = *pDP2GenMipLevels;
    return (S_OK);
}

#ifndef KM_SYSMEM_PRESENT
DWORD
CD3DContext::PrepareShadowRenderTarget(
    DWORD       dwSrcRes,
    DWORD       dwSubLevelIndex)
{
    CResource  &res = m_RTbl[dwSrcRes];
    DWORD       dwSrcRT = dwSrcRes + dwSubLevelIndex;
    CResource  &rt = m_RTbl[dwSrcRT];
    HRESULT     hr;
    UINT        i;

    if (res.m_d3dPool != D3DDDIPOOL_SYSTEMMEM)
    {
        return (dwSrcRT);
    }

    //
    // Support at most 4 back buffers
    //
    if (res.m_dwNumExHandles > 4)
    {
        return (dwSrcRT);
    }

    //
    // For system memory RT, data has to be copied to a video memory shadow RT
    //
    if (! res.m_hShadowRT)
    {
        D3DDDIARG_CREATERESOURCE    crData;
        D3DDDI_SURFACEINFO          surfInfo[4];

        memset(&crData, 0, sizeof(D3DDDIARG_CREATERESOURCE));
        memset(&surfInfo[0], 0, sizeof(D3DDDI_SURFACEINFO)*4);

        //
        // Set up the info to creat the video memory shadow
        //
        for (i = 0; i < res.m_dwNumExHandles; i++)
        {
            surfInfo[i].Width  = res.m_dwWidth;
            surfInfo[i].Height = res.m_dwHeight;
            surfInfo[i].Depth  = 1;
        }

        crData.Flags     = res.m_dwResCaps;
        crData.Format    = res.m_d3dFormat;
        crData.Pool      = D3DDDIPOOL_LOCALVIDMEM;
        crData.pSurfList = surfInfo;
        crData.SurfCount = res.m_dwNumExHandles;
        crData.MipLevels = 1;

        hr = CreateResource(&crData);
        if (FAILED(hr))        {
            return (dwSrcRT);
        }

        res.m_hShadowRT = crData.hResource;
    }

    //
    // Lock and copy the data
    //
    LONG                lDstPitch;
    D3DKMT_HANDLE       hDstAllocation;
    unsigned __int64    u64ShadowRT = ((DWORD)(DWORD_PTR)res.m_hShadowRT) + dwSubLevelIndex;
    DWORD               dwShadowRT;
    LPBYTE              pDstPixel;


    if ( u64ShadowRT < MAXDWORD )
    {
        dwShadowRT = (DWORD)u64ShadowRT;
    }
    else
    {
        return dwSrcRT;
    }

    hDstAllocation = R200GetAllocationHandle(m_pR200Ctx,
                                             dwShadowRT,
                                             &lDstPitch);
    if (! hDstAllocation)
    {
        return (dwSrcRT);
    }

    // We are not setting the discard flags so we will not get a new handle from VidMm
    hr = LockAllocationCB(&hDstAllocation,
                          0,                // LockFlags
                          FALSE,
                          0,
                          (LPVOID *)&pDstPixel);
    if (FAILED(hr))
    {
        return (dwSrcRT);
    }

    LPBYTE  pSrcPixel = (LPBYTE)rt.m_pSysMem;
    for (i = 0; i < rt.m_dwHeight; i++)
    {
        //
        // Assumption: system memory surface has smaller pitch
        //
        memcpy(pDstPixel, pSrcPixel, rt.m_lPitch);

        pSrcPixel += rt.m_lPitch;
        pDstPixel += lDstPitch;
    }

    hr = UnlockAllocationCB(hDstAllocation);

    return (dwShadowRT);
}
#endif

HRESULT CD3DContext::SetDisplayMode(CONST D3DDDIARG_SETDISPLAYMODE* pSetDisplayMode)
{
    DWORD   dwSrcSurf = ((DWORD)(DWORD_PTR)pSetDisplayMode->hResource) + pSetDisplayMode->SubResourceIndex;
    HRESULT hr;

    _ASSERT(dwSrcSurf < m_RTbl.Size());
    //
    // At the moment, everything batched should has been flushed.
    //
    _ASSERT(m_dwDP2CmdPos == 0);

    //
    // Timestamp the src surface
    //
    m_RTbl[dwSrcSurf].m_qwBatch = m_qwBatch;

    //
    // Send the presentation request to the KMD
    //
    D3DDDICB_SETDISPLAYMODE SetDisplayModeCBData = {0};

    SetDisplayModeCBData.hPrimaryAllocation = R200GetSurfaceAllocHandle(m_pR200Ctx,
                                                  dwSrcSurf);

    hr = m_d3dCallbacks.pfnSetDisplayModeCb(m_hD3D, &SetDisplayModeCBData);

    return (hr);
}

HRESULT CD3DContext::Present(CONST D3DDDIARG_PRESENT* pPresent)
{
    DWORD   dwSrcSurf = ((DWORD)(DWORD_PTR)pPresent->hSrcResource) + pPresent->SrcSubResourceIndex;
    HRESULT hr=S_OK;

    _ASSERT(dwSrcSurf < m_RTbl.Size());
    //
    // At the moment, everything batched should has been flushed.
    //
    _ASSERT(m_dwDP2CmdPos == 0);

    // If it's a colorfill request, we don't have a source surface
    if (dwSrcSurf == NULL)
    {
        D3DDDICB_PRESENT    PresentCBData = {0};

        PresentCBData.hContext = m_sContexts[MULTI_ENGINE_NODE_3D].hContext;
        PresentCBData.hSrcAllocation = NULL;

        if (pPresent->hDstResource)
        {
            DWORD   dwDstSurf = ((DWORD)(DWORD_PTR)pPresent->hDstResource) + pPresent->DstSubResourceIndex;
            _ASSERT(dwDstSurf < m_RTbl.Size());
            m_RTbl[dwDstSurf].m_qwBatch = m_qwBatch;
            PresentCBData.hDstAllocation = R200GetSurfaceAllocHandle(m_pR200Ctx,
                                                                     dwDstSurf);
        }

        if (m_LastEngineSubmit == MULTI_ENGINE_NODE_VIDEO)
        {
            // We need to ensure 3D/Video packets are in sync, the last packet we sent when to 
            // the Video engine so we need to ensure that packet finishes before this new 
            // packet is run on the hardware
#ifdef USE_LOCK_TO_SYNC_ENGINES
            hr = SyncEnginesUsingLock();
#else
            hr = SyncEngines(MULTI_ENGINE_NODE_VIDEO, MULTI_ENGINE_NODE_3D);
#endif                

            if (FAILED(hr))
            {
                return hr;
            }
        }

        hr = m_d3dCallbacks.pfnPresentCb(m_hD3D, &PresentCBData);

        return hr;
    }

#ifndef KM_SYSMEM_PRESENT
    //
    // Use the video memory resource that KMD can present
    //
    dwSrcSurf = PrepareShadowRenderTarget((DWORD)(DWORD_PTR)pPresent->hSrcResource,
                                          pPresent->SrcSubResourceIndex);
#endif

    //
    // Timestamp the src surface
    //
    m_RTbl[dwSrcSurf].m_qwBatch = m_qwBatch;

    //
    // Send the presentation request to the KMD
    //
    D3DDDICB_PRESENT    PresentCBData = {0};

    PresentCBData.hContext = m_sContexts[MULTI_ENGINE_NODE_3D].hContext;
    PresentCBData.hSrcAllocation = R200GetSurfaceAllocHandle(m_pR200Ctx,
                                                  dwSrcSurf);
    if (pPresent->hDstResource)
    {
        DWORD   dwDstSurf = ((DWORD)(DWORD_PTR)pPresent->hDstResource) + pPresent->DstSubResourceIndex;
        _ASSERT(dwDstSurf < m_RTbl.Size());
        m_RTbl[dwDstSurf].m_qwBatch = m_qwBatch;
        PresentCBData.hDstAllocation = R200GetSurfaceAllocHandle(m_pR200Ctx,
                                                  dwDstSurf);
    }


    if (m_LastEngineSubmit == MULTI_ENGINE_NODE_VIDEO)
    {
        // We need to ensure 3D/Video packets are in sync, the last packet we sent when to 
        // the Video engine so we need to ensure that packet finishes before this new 
        // packet is run on the hardware
#ifdef USE_LOCK_TO_SYNC_ENGINES
        hr = SyncEnginesUsingLock();
#else
        hr = SyncEngines(MULTI_ENGINE_NODE_VIDEO, MULTI_ENGINE_NODE_3D);
#endif                

        if (FAILED(hr))
        {
            return hr;
        }
    }    

#ifdef USE_LOCK_TO_SYNC_ENGINES
    m_HandleUsedInLastSubmit = PresentCBData.hSrcAllocation;
#endif     

                 hr = m_d3dCallbacks.pfnPresentCb(m_hD3D, &PresentCBData);


    // Remeber 3D was the last engine we submit any work to
    m_LastEngineSubmit = MULTI_ENGINE_NODE_3D;    

    return (hr);
}

HRESULT CD3DContext::Blt(CONST D3DDDIARG_BLT* pBlt)
{
    DWORD           dwSource = (DWORD)(DWORD_PTR)pBlt->hSrcResource;
    DWORD           dwDest   = (DWORD)(DWORD_PTR)pBlt->hDstResource;
    D3DDDIARG_BLT*  pDP2Blt;

    _ASSERT(dwSource < m_RTbl.Size());
    _ASSERT(dwDest < m_RTbl.Size());

    pDP2Blt = (D3DDDIARG_BLT*)GetBufferPointer(D3DDP2OP_BLT, sizeof(D3DDDIARG_BLT));
    *pDP2Blt = *pBlt;

    m_RTbl[dwSource].m_qwBatch = m_qwBatch;
    m_RTbl[dwDest].m_qwBatch   = m_qwBatch;

    return (S_OK);
}

HRESULT CD3DContext::ColorFill(CONST D3DDDIARG_COLORFILL* pColorFill)
{
    DWORD                   dwSurface = (DWORD)(DWORD_PTR)pColorFill->hResource;
    D3DHAL_DP2COLORFILL    *pDP2Color;

    _ASSERT(dwSurface < m_RTbl.Size());

    if (pColorFill->SubResourceIndex < m_RTbl[dwSurface].m_dwNumExHandles)
    {
        dwSurface += pColorFill->SubResourceIndex;
    }

    pDP2Color = (D3DHAL_DP2COLORFILL *)GetBufferPointer(D3DDP2OP_COLORFILL, sizeof(D3DHAL_DP2COLORFILL));
    pDP2Color->dwSurface = dwSurface;
    pDP2Color->rRect     = *(RECTL *)&pColorFill->DstRect;
    pDP2Color->Color     = pColorFill->Color;

    m_RTbl[dwSurface].m_qwBatch = m_qwBatch;

    return (S_OK);
}

HRESULT CD3DContext::DepthFill(CONST D3DDDIARG_DEPTHFILL* pDepthFill)
{
    DWORD                   dwSurface = (DWORD)(DWORD_PTR)pDepthFill->hResource;
    D3DHAL_DP2COLORFILL    *pDP2Color;

    _ASSERT(dwSurface < m_RTbl.Size());

    if (pDepthFill->SubResourceIndex < m_RTbl[dwSurface].m_dwNumExHandles)
    {
        dwSurface += pDepthFill->SubResourceIndex;
    }

    pDP2Color = (D3DHAL_DP2COLORFILL *)GetBufferPointer(D3DDP2OP_COLORFILL, sizeof(D3DHAL_DP2COLORFILL));
    pDP2Color->dwSurface = dwSurface;
    pDP2Color->rRect     = *(RECTL *)&pDepthFill->DstRect;
    pDP2Color->Color     = pDepthFill->Depth;

    m_RTbl[dwSurface].m_qwBatch = m_qwBatch;

    return (S_OK);
}

HRESULT CD3DContext::CreateFence(VOID)
{
    HRESULT     hr = S_OK;

    // If we have not yet initialized our fence mechanism, do so now.
    if (m_pFence == NULL)
    {
        CD3DFence * pFence = new CD3DFence(this);
        if (pFence == NULL)
        {
            return E_OUTOFMEMORY;
        }

        hr = pFence->Initialize();
        if (FAILED(hr))
        {
            delete pFence;
            return E_FAIL;
        }
        else
        {
            m_pFence = pFence;
        }
    }

    return hr;
}

HRESULT CD3DContext::CreateQuery(D3DDDIARG_CREATEQUERY* pDP2CreateQuery)
{
    // If we have not yet initialized our fence mechanism, do so now.
    if (CreateFence() != S_OK)
    {
        return E_FAIL;
    }

    // It would probably be more efficient to implement this as a large table, and the
    // handle would contain the table index.
    UINT* pQuery = new UINT;

    pDP2CreateQuery->hQuery = (HANDLE) pQuery;
    if (pQuery == NULL)
    {
        return E_OUTOFMEMORY;
    }
    *pQuery = 0xDEADBEEF;  // Query created, but not yet issued

    return (S_OK);
}

HRESULT CD3DContext::DeleteQuery(CONST HANDLE hQuery)
{
    delete ((UINT*)hQuery);
    return S_OK;
}

HRESULT CD3DContext::IssueQuery(CONST D3DDDIARG_ISSUEQUERY* pIssueQuery)
{
    UINT* pQuery = (UINT*) pIssueQuery->hQuery;
    HRESULT hr = m_pFence->GetNextFenceValue(pQuery);
    if (hr==S_OK)
    {
       m_pFence->SubmitFence(*pQuery);
    }
    return hr;
}

HRESULT CD3DContext::GetQueryData(CONST D3DDDIARG_GETQUERYDATA* pGetQueryData)
{
    UINT* pQuery = (UINT*) pGetQueryData->hQuery;

    if (m_pFence->QueryFence(*pQuery))
    {
        *((BOOL*)(pGetQueryData->pData)) = TRUE;
        return S_OK;
    }
    return S_FALSE;
}


//
// R200ExtEscape is used to intercept QS calls
//

HRESULT R2QSExtEscape(
    __in    HANDLE                  hDev,
    __in    INT                     nEscape,
    __in    INT                     nInSize,
    __in    LPCSTR                  pIn,
    __in    INT                     nOutSize,
    __inout_bcount(nOutSize) LPSTR  pOut)
{
    return (reinterpret_cast<CD3DContext*>(hDev)->ExtEscape(nEscape, nInSize, pIn, nOutSize, pOut));
}

//
// Copied from ntx\r6\driver\qswrap.c
//
#define QS_XOR_MASK   0x7FFFFFFF
#define CONV_TO_QSRETURNCODE(RetVal) (DWORD) RetVal ^ QS_XOR_MASK

#ifdef USE_LOCK_TO_SYNC_ENGINES
HRESULT CD3DContext::SyncEnginesUsingLock(VOID)
{
    HRESULT hr;
    D3DDDICB_LOCK   lockCB;
    D3DDDICB_UNLOCK Unlock;

    memset(&lockCB, 0, sizeof(D3DDDICB_LOCK));
    lockCB.hAllocation = m_HandleUsedInLastSubmit;
    lockCB.PrivateDriverData = 0;                       
    hr = m_d3dCallbacks.pfnLockCb(m_hD3D, &lockCB);
    if (FAILED(hr))
    {
        DBG_BREAK;
        return hr;
    }

    Unlock.NumAllocations = 1;
    Unlock.phAllocations = &m_HandleUsedInLastSubmit;
    m_d3dCallbacks.pfnUnlockCb(m_hD3D, &Unlock);   
    return hr;
}   
#else
HRESULT CD3DContext::SyncEngines(DWORD dwEngineReleasingControl, DWORD dwEngineAcquiringControl)
{
    HRESULT hr;
    D3DDDICB_WAITFORSYNCHRONIZATIONOBJECT   sWaitObject;
    D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT    sSignalObject;

    _ASSERT(m_hEngineSyncObject != 0);

    sSignalObject.hContext = m_sContexts[dwEngineReleasingControl].hContext;
    sSignalObject.ObjectCount = 1;
    sSignalObject.ObjectHandleArray[0] = m_hEngineSyncObject;
    hr = m_d3dCallbacks.pfnSignalSynchronizationObjectCb(m_hD3D, &sSignalObject);
    if (FAILED(hr))
    {
        DBG_BREAK;
        return hr;
    }

    sWaitObject.hContext = m_sContexts[dwEngineAcquiringControl].hContext;
    sWaitObject.ObjectCount = 1;
    sWaitObject.ObjectHandleArray[0] = m_hEngineSyncObject;
    hr = m_d3dCallbacks.pfnWaitForSynchronizationObjectCb(m_hD3D, &sWaitObject);
    if (FAILED(hr))
    {
        DBG_BREAK;        
    }    

    return hr;
}   
#endif // USE_LOCK_TO_SYNC_ENGINES

HRESULT
CD3DContext::ExtEscape(
    __in    INT                     nEscape,
    __in    INT                     nInSize,
    __in_bcount(nInSize)   LPCSTR   pIn,
    __in    INT                     nOutSize,
    __out_bcount(nOutSize) LPSTR    pOut)
{   
    switch (nEscape)
    {
        case CWDDEQC_QSALLOCLIST:
        {
            QS_PARAM   *pQSParam = (QS_PARAM *)pIn;
            pQSParam->pList    = (PBYTE)m_pHwCmdBuf;
            pQSParam->dwCmdBufSizeInDWORDs = m_dwHwCmdBufSize/sizeof(DWORD);
            pQSParam->hOutList = 0xDEADBEEF;

            return D3D_OK;
            break;
        }
        case CWDDEQC_QSSUBMITLIST:
        {
            QS_PARAM           *pQSParam = (QS_PARAM *)pIn;
            D3DDDICB_RENDER     renderCBData = {0};
            DWORD               dwAllocationListUsed;
            HRESULT             hrRet = S_OK;
            
            pQSParam->lTimeStamp.QuadPart = m_qwHWBatch;
            m_qwHWBatch++;

            {       //  Regular command buffer

                // The R200 sample generates the allocation list after the cmd buffer is created and the
                // kernel mode generates the patch list, this is not optimal for performance as we are parsing
                // the cmd buffer more than is really necessary. It was implemented this way to ease
                // implementation.  In a production driver it would be more efficient to generate the
                // allocation/patch list while generating the cmd buffer.
                if (GenerateAllocationListFromCmdBuf(pQSParam, m_sContexts[MULTI_ENGINE_NODE_3D].pHwCmdBufAllocList, m_dwHwCmdBufAllocListSize, &dwAllocationListUsed) == FALSE)
                {
                    DBG_BREAK;
                    return E_FAIL;
                }
            }

            if (m_LastEngineSubmit == MULTI_ENGINE_NODE_VIDEO)
            {
                // We need to ensure 3D/Video packets are in sync, the last packet we sent when to 
                // the Video engine so we need to ensure that packet finishes before this new 
                // packet is run on the hardware
#ifdef USE_LOCK_TO_SYNC_ENGINES
                hrRet = SyncEnginesUsingLock();
#else
                hrRet = SyncEngines(MULTI_ENGINE_NODE_VIDEO, MULTI_ENGINE_NODE_3D);
#endif                
                if (FAILED(hrRet))
                {
                    return hrRet;
                }
            }

            renderCBData.CommandOffset = 0;
            renderCBData.CommandLength = pQSParam->dwListSize;
            renderCBData.NumAllocations = dwAllocationListUsed;
            renderCBData.hContext = m_sContexts[MULTI_ENGINE_NODE_3D].hContext;      // 3D engine


            //
            // Now copy CmdBuf data from internal buffer to the buffer created by dxgkrnl
            //
            memcpy(m_sContexts[MULTI_ENGINE_NODE_3D].pHwCmdBuf, m_pHwCmdBuf, renderCBData.CommandLength);

#ifdef USE_LOCK_TO_SYNC_ENGINES
            if (dwAllocationListUsed != 1)
            {
                m_HandleUsedInLastSubmit = m_sContexts[MULTI_ENGINE_NODE_3D].pHwCmdBufAllocList[1].hAllocation;
            }
#endif     

            hrRet = m_d3dCallbacks.pfnRenderCb(m_hD3D, &renderCBData);

            // Remeber 3D was the last engine we submit any work to
            m_LastEngineSubmit = MULTI_ENGINE_NODE_3D;


            return hrRet;
        }
        default:
            return (::ExtEscape(m_hDC, nEscape, nInSize, pIn, nOutSize, pOut));
            break;
    }

    return E_FAIL;
}


HRESULT CD3DContext::OpenResource(D3DDDIARG_OPENRESOURCE* pOR)
{
    HRESULT hr;

    // Save ptr to params for uses in CreateAllocationCB
    m_pOpenResourceData = pOR;
    m_CurResourceIdx = 0;


    hr = D3DDDIOpenResource(this,
                          this,
                          pOR,
                          m_pR200Ctx,
                          &m_dwCurResCaps,
                          &m_VidPnSourceId);


    // Signal we are not in OpenResource call anymore
    m_pOpenResourceData = NULL;
    m_CurResourceIdx = 0xffffffff;
    m_dwCurResCaps.Value = 0;

    return hr;
}

//
// DDI entry pointer to create surface, vertex buffer, etc
//
HRESULT
CD3DContext::CreateResource(
    D3DDDIARG_CREATERESOURCE   *pCR)
{
    HRESULT                     hr;

    if ((! m_ulGartSupported) &&
        (pCR->Flags.VertexBuffer || pCR->Flags.IndexBuffer) &&
        (pCR->Pool != D3DDDIPOOL_SYSTEMMEM))
    {
        return (DDERR_UNSUPPORTED); // production driver shouldn't return this error code
    }

    
    //  R200 sample code doesn't support shared vertex and index buffers
    if (pCR->Flags.SharedResource && (pCR->Flags.VertexBuffer || pCR->Flags.IndexBuffer))
    {
        return (D3DERR_NOTAVAILABLE);
    }

    //
    // NOTE: Current R200 code doesn't support MIPMAP CUBEMAP correctly.
    // Unless a reg key is set, the driver doesn't claim support for it.
    // When MIPMAP CUBEMAP is created, there are problems along the
    // CreateSurfaceEx32 code path that makes the CUBEMAP appear as a
    // single level one.
    //
    if ((pCR->Flags.CubeMap) && (pCR->SurfCount > 6))
    {
        //
        // DX8/9 doesn't try to create MIPMAP CUBEMAP without the
        // D3DPTEXTURECAPS_MIPCUBEMAP, but DX7 relies on CanCreateSurface
        // to make the decision. So it has to be failed here.
        //
        return (DDERR_INVALIDPARAMS);
    }

    //
    // NOTE: In R200 driver, allocations for VB renaming are pooled together,
    // the side effect of this design in LDDM is that allocation for VBs
    // can not be associated with the VB resource, it has to be associated
    // with the D3D device. Another consequence is that VB can't be shared
    // between multiple D3D devices (which is not a requirement).
    //

    //
    // Save the handle of the resource being created for CreateAllocationCB()
    //
    if (!(pCR->Flags.VertexBuffer || pCR->Flags.IndexBuffer))
    {
        m_hCurResRuntime = pCR->hResource;
    }

    //
    // Save the resource's LDDM caps1 for the allocation creation callback
    //
    m_dwCurResCaps = pCR->Flags;
    //
    // Save the VidPN source ID for the resource
    //
    m_VidPnSourceId= pCR->VidPnSourceId;

    //
    // Store ptr to CreateResource data so if this is a shred resource we can
    // save some of the data to make OpenResource earier
    //
    m_pCreateResourceData = pCR;
    m_CurResourceIdx = 0;

    hr = D3DDDICreateResource(this,
                              this,
                              pCR);

    m_pCreateResourceData = NULL;
    m_CurResourceIdx = 0xffffffff;

    //
    // Reset the handle of the resource being created
    //
    m_hCurResRuntime = NULL;
    m_bCurResFreed   = FALSE;
    m_dwCurResCaps.Value = 0;


    return (hr);
}

HRESULT
CD3DContext::DestroyResource(
    HANDLE  hResource)
{
    DWORD   dwExHandle = (DWORD)(DWORD_PTR)hResource;
    HRESULT hr=S_OK;
    DWORD   i;

    //
    // Validate the handle
    //
    if (m_RTbl.Size() < dwExHandle)
    {
        return (DDERR_INVALIDOBJECT);
    }

    CResource &res = m_RTbl[dwExHandle];
    //
    // Make sure the resource hasn't been destroyed
    //
    if (! res.m_bValid)
    {
        return (DDERR_INVALIDOBJECT);
    }

    if (m_pR200Ctx)
    {
        DWORD   dwAllocCnt = res.m_dwNumExHandles;

        //
        // There appears to be an issue we using the batch number to check if we need to flush
        // if we use the optimisation we still get stale handles in the preamble.
        // With the new allocation/patch beta 2 DDI chnages dxgkrnl performs the handle look up
        // and will fail the Render if it finds stale handles
        //
        // So for now just disable this optimization
        //
        Flush(TRUE);

        if (!(res.m_dwResCaps.VertexBuffer || res.m_dwResCaps.IndexBuffer))
        {
            m_hCurResRuntime = res.m_hResRuntime;
            m_bCurResFreed   = FALSE;
        }

        {
            //
            // Free the resource
            //
            hr = D3DDDIDestroyResource(m_pR200Ctx,
                                        dwExHandle,
                                        dwAllocCnt);
            _ASSERT(hr == DD_OK);
        }

        
        //
        // One resource may have multiple EX handles (swap chain, etc)
        //
        for (i = 0; i < dwAllocCnt; i++)
        {
            m_RTbl[dwExHandle + i].m_bValid  = FALSE;
            m_RTbl[dwExHandle + i].m_pVidmem = NULL;


        }

        //
        // Reset the current resource handle to NULL
        //
        m_hCurResRuntime = NULL;
        m_bCurResFreed   = FALSE;

#ifndef KM_SYSMEM_PRESENT
        if (res.m_hShadowRT)
        {
            HRESULT      hrTemp;
            CResource   &resShadow = m_RTbl[(DWORD)(DWORD_PTR)res.m_hShadowRT];
            {
                hrTemp = D3DDDIDestroyResource(m_pR200Ctx,
                                               (DWORD)(DWORD_PTR)res.m_hShadowRT,
                                               1);
                _ASSERT(hrTemp == DD_OK);
            }

            m_RTbl[((DWORD)(DWORD_PTR)res.m_hShadowRT)].m_bValid  = FALSE;
            m_RTbl[((DWORD)(DWORD_PTR)res.m_hShadowRT)].m_pVidmem = NULL;

            //
            // Clear out shadow RT
            //
            res.m_hShadowRT = NULL;
        }
#endif

        // We flushed at just before destroying the resource, but the preable could have the resource handle in it
        // so if we discard the preable and start again we will not reference the invalid handle
        // in the command buffer
        R200GetNewCmdBuff(m_pR200Ctx, TRUE, FALSE);

        return (hr);
    }
    else
    {
        memset(&res, 0, sizeof(CResource));
        return (S_OK);
    }
}

#define PM4_PACKET3_NOP 0xC0001000
#define GetType3OpCode(n) ((n & 0xFF00) >> 8)

LPVOID CD3DContext:: GetDXVABuffer(DWORD *pSize)
{
    UINT    PreambleSize;        
    PUMD_CMDBUF_INFO pPm4PacketInfo;

    Flush(TRUE);
    PreambleSize = GetCmdBufPreambleSize(m_pR200Ctx);

    *pSize = ((m_dwHwCmdBufSize - PreambleSize - sizeof(UMD_CMDBUF_INFO)) / sizeof(DWORD));

    pPm4PacketInfo = (PUMD_CMDBUF_INFO)(m_pHwCmdBuf + PreambleSize);
    memset(pPm4PacketInfo, 0, sizeof(UMD_CMDBUF_INFO));
    pPm4PacketInfo->dwInfoNopHeader = PM4_INFO_PACKET_HEADER;

    return m_pHwCmdBuf + PreambleSize + sizeof(UMD_CMDBUF_INFO);
}

VOID CD3DContext::SubmitDXVABuffer(
        DWORD Size)
    {
        D3DDDICB_RENDER     renderCBData = {0};
        DWORD               dwAllocationListUsed;
        HRESULT             hr;

        // The R200 sample generates the allocation list after the cmd buffer is created and the
        // kernel mode generates the patch list, this is not optimal for performance as we are parsing
        // the cmd buffer more than is really necessary. It was implemented this way to ease
        // implementation.  In a production driver it would be more efficient to generate the
        // allocation/patch list while generating the cmd buffer.      
        if (GenerateAllocationListFromCmdBuf(R200UpdateQSParamsForDXVASubmit(m_pR200Ctx, Size), m_sContexts[MULTI_ENGINE_NODE_VIDEO].pHwCmdBufAllocList, m_dwHwCmdBufAllocListSize, &dwAllocationListUsed) == FALSE)
        {
            DBG_BREAK;
            return;
        }

        if (m_LastEngineSubmit == MULTI_ENGINE_NODE_3D)
        {
            // We need to ensure 3D/Video packets are in sync, the last packet we sent when to 
            // the 3D engine so we need to ensure that packet finishes before this new 
            // packet is run on the hardware
#ifdef USE_LOCK_TO_SYNC_ENGINES
            hr = SyncEnginesUsingLock();
#else
            hr = SyncEngines(MULTI_ENGINE_NODE_3D, MULTI_ENGINE_NODE_VIDEO);
#endif              
            if (FAILED(hr))
            {
                return;
            }
        }        

        renderCBData.CommandOffset  = 0;
        renderCBData.CommandLength  = Size + sizeof(UMD_CMDBUF_INFO);
        renderCBData.NumAllocations = dwAllocationListUsed;
        renderCBData.hContext = m_sContexts[MULTI_ENGINE_NODE_VIDEO].hContext;

        //
        // Now copy CmdBuf data from internal buffer to the buffer created by dxgkrnl
        //
        memcpy(m_sContexts[MULTI_ENGINE_NODE_VIDEO].pHwCmdBuf, m_pHwCmdBuf + GetCmdBufPreambleSize(m_pR200Ctx), renderCBData.CommandLength);


#ifdef USE_LOCK_TO_SYNC_ENGINES
        if (dwAllocationListUsed != 1)
        {
            m_HandleUsedInLastSubmit = m_sContexts[MULTI_ENGINE_NODE_VIDEO].pHwCmdBufAllocList[1].hAllocation;
        }
#endif    

        m_d3dCallbacks.pfnRenderCb(m_hD3D, &renderCBData);

        // Remeber Video was the last engine we submit any work to
        m_LastEngineSubmit = MULTI_ENGINE_NODE_VIDEO;            
    }

DWORD
GetExHandles(
    PDD_DIRECTDRAW_LOCAL        pDDLcl,
    DWORD                       dwNumHandles)
{
    return (reinterpret_cast<CD3DContext*>(pDDLcl)->GetExHandles(dwNumHandles));
}

DWORD
CD3DContext::GetExHandles(
    DWORD                       dwNumHandles)
{
    return (m_RTbl.GetResourceHandle(dwNumHandles));
}

HRESULT
R200CreateAllocationCB(
    LPVOID                      pD3DDev,
    R2DDICreateAllocationData  *pR2AllocData,
    D3DKMT_HANDLE              *phAllocation,
    PVOID                       pSysMem)
{
    CD3DContext    *pD3DCtxt;

    pD3DCtxt = reinterpret_cast<CD3DContext*>(pD3DDev);

    return (pD3DCtxt->CreateAllocationCB(pR2AllocData,
                                         phAllocation,
                                         pSysMem));
}

BOOL CheckOpenData(R2DDICreateAllocationData* pR2AllocData, D3DDDIARG_OPENRESOURCE* pOpenResource, UINT OpenResIdx)
{
    R2DDICreateAllocationData   sFromDrvCreateCode=*pR2AllocData;
    R2DDICreateAllocationData   sFromOpenDDI;

    // Should we check the following condition or just assume that?
    if (sizeof(sFromOpenDDI) >= pOpenResource->pOpenAllocationInfo[OpenResIdx].PrivateDriverDataSize)
    {
        memcpy(&sFromOpenDDI, pOpenResource->pOpenAllocationInfo[OpenResIdx].pPrivateDriverData, pOpenResource->pOpenAllocationInfo[OpenResIdx].PrivateDriverDataSize);
    }
    else
    {
        _ASSERT(sizeof(sFromOpenDDI) >= pOpenResource->pOpenAllocationInfo[OpenResIdx].PrivateDriverDataSize);
        return FALSE;
    }

    // Zero elements we know will be different
    sFromOpenDDI.sAllocInfo.hslSurfDesc.dwSurfaceHandle = 0;
    sFromDrvCreateCode.sAllocInfo.hslSurfDesc.dwSurfaceHandle = 0;

    sFromOpenDDI.sAllocInfo.hslSurfDesc.lpddPixelFormat = 0;
    sFromDrvCreateCode.sAllocInfo.hslSurfDesc.lpddPixelFormat = 0;

    sFromOpenDDI.sAllocInfo.hslSurfDesc.hAllocation = 0;
    sFromDrvCreateCode.sAllocInfo.hslSurfDesc.hAllocation = 0;

    sFromOpenDDI.sAllocInfo.hslSurfDesc.hATISurfInfoHandle = 0;
    sFromDrvCreateCode.sAllocInfo.hslSurfDesc.hATISurfInfoHandle = 0;

    if ((sFromOpenDDI.sAllocInfo.dwCaps & DDSCAPS_PRIMARYSURFACE) != 0)
    {
        sFromOpenDDI.sAllocInfo.dwOffsetAlign = 0;
        sFromDrvCreateCode.sAllocInfo.dwOffsetAlign = 0;

        sFromOpenDDI.sAllocInfo.hslSurfDesc.dwGMCWidth = 0;
        sFromDrvCreateCode.sAllocInfo.hslSurfDesc.dwGMCWidth = 0;

        sFromOpenDDI.sAllocInfo.RefreshRate.Denominator = 0;
        sFromOpenDDI.sAllocInfo.RefreshRate.Numerator = 0;

        sFromDrvCreateCode.sAllocInfo.RefreshRate.Denominator = 0;
        sFromDrvCreateCode.sAllocInfo.RefreshRate.Numerator = 0;
    }


#ifdef WOW6432
    sFromOpenDDI.dwPad0 = 0;
    sFromDrvCreateCode.dwPad0 = 0;
    sFromOpenDDI.sAllocInfo.dwPad0 = 0;
    sFromDrvCreateCode.sAllocInfo.dwPad0 = 0;
    sFromOpenDDI.sAllocInfo.dwPad1 = 0;
    sFromDrvCreateCode.sAllocInfo.dwPad1 = 0;
    sFromOpenDDI.sAllocInfo.hslSurfDesc.dwPad0 = 0;
    sFromOpenDDI.sAllocInfo.hslSurfDesc.dwPad1 = 0;
    sFromOpenDDI.sAllocInfo.hslSurfDesc.dwPad2 = 0;
    sFromOpenDDI.sAllocInfo.hslSurfDesc.dwPad3 = 0;
    sFromOpenDDI.sAllocInfo.hslSurfDesc.dwPad4 = 0;
    sFromOpenDDI.sAllocInfo.hslSurfDesc.dwPad5 = 0;
    sFromDrvCreateCode.sAllocInfo.hslSurfDesc.dwPad0 = 0;
    sFromDrvCreateCode.sAllocInfo.hslSurfDesc.dwPad1 = 0;
    sFromDrvCreateCode.sAllocInfo.hslSurfDesc.dwPad2 = 0;
    sFromDrvCreateCode.sAllocInfo.hslSurfDesc.dwPad3 = 0;
    sFromDrvCreateCode.sAllocInfo.hslSurfDesc.dwPad4 = 0;
    sFromDrvCreateCode.sAllocInfo.hslSurfDesc.dwPad5 = 0;
    sFromOpenDDI.sAllocInfo.vidMemData.dwPad0 = 0;
    sFromOpenDDI.sAllocInfo.vidMemData.dwPad1 = 0;
    sFromOpenDDI.sAllocInfo.vidMemData.dwPad2 = 0;
    sFromOpenDDI.sAllocInfo.vidMemData.dwPad3 = 0;
    sFromDrvCreateCode.sAllocInfo.vidMemData.dwPad0 = 0;
    sFromDrvCreateCode.sAllocInfo.vidMemData.dwPad1 = 0;
    sFromDrvCreateCode.sAllocInfo.vidMemData.dwPad2 = 0;
    sFromDrvCreateCode.sAllocInfo.vidMemData.dwPad3 = 0;
#endif

    if (memcmp(&sFromDrvCreateCode, &sFromOpenDDI, sizeof(R2AllocationInfo)) != 0)
    {
        DBG_BREAK;
        return FALSE;
    }

    return TRUE;
}

HRESULT
CD3DContext::CreateAllocationCB(
    R2DDICreateAllocationData  *pR2AllocData,
    D3DKMT_HANDLE              *phAllocation,
    PVOID                       pSysMem)
{
    D3DDDICB_ALLOCATE           allocCB;
    D3DDDI_ALLOCATIONINFO       allocInfo;
    HRESULT                     hr;

    memset(&allocInfo,   0, sizeof(allocInfo));
    memset(&allocCB,     0, sizeof(allocCB));

    //
    // Note : this informtion doesn't matter much for the driver
    //
    allocInfo.pPrivateDriverData    = pR2AllocData;
    allocInfo.PrivateDriverDataSize = sizeof(R2DDICreateAllocationData);

    //
    // Decide if the allocation belongs to a shared resource
    //
    if (m_dwCurResCaps.SharedResource)
    {
        pR2AllocData->sAllocInfo.bShared = TRUE;

        if (m_pCreateResourceData != NULL)
        {
            // Store some of the CreateResource DDI data to make OpenResource easier
            pR2AllocData->CreateDataFormat = m_pCreateResourceData->Format;
            pR2AllocData->CreateDataPool = m_pCreateResourceData->Pool;
            pR2AllocData->CreateDataMultisampleType = m_pCreateResourceData->MultisampleType;
            pR2AllocData->CreateDataMultisampleQuality = m_pCreateResourceData->MultisampleQuality;
            pR2AllocData->CreateDataSurfCount = m_pCreateResourceData->SurfCount;
            pR2AllocData->CreateDataMipLevels = m_pCreateResourceData->MipLevels;
            pR2AllocData->CreateDataFvf = m_pCreateResourceData->Fvf;
            pR2AllocData->CreateDataVidPnSourceId = m_pCreateResourceData->VidPnSourceId;
            pR2AllocData->CreateDataFlags = m_pCreateResourceData->Flags;
            pR2AllocData->CreateDataSurfDepth = m_pCreateResourceData->pSurfList[m_CurResourceIdx].Depth;

            // Next surf
            m_CurResourceIdx++;
        }
    }
    else
    {
        pR2AllocData->sAllocInfo.bShared = FALSE;
    }

    //
    // Determine whether the allocation is CPU optimized or not
    //
    if (m_dwCurResCaps.CpuOptimized)
    {
        pR2AllocData->sAllocInfo.bCPUOptimized = TRUE;
    }
    else
    {
        pR2AllocData->sAllocInfo.bCPUOptimized = FALSE;
    }


    //
    // Decide if the allocation is a DXVA render target
    //
    if (m_dwCurResCaps.DecodeRenderTarget)
    {
        pR2AllocData->sAllocInfo.bDXVARenderTarget = TRUE;
    }
    else
    {
        pR2AllocData->sAllocInfo.bDXVARenderTarget = FALSE;
    }


    //
    // Set VidPN source ID for the primary and fullscreen back buffer
    //
    if (m_dwCurResCaps.Primary)
    {
        allocInfo.Flags.Primary = TRUE;
        allocInfo.VidPnSourceId = m_VidPnSourceId;

        pR2AllocData->sAllocInfo.VidPnSourceId = m_VidPnSourceId;

        if ((m_pCreateResourceData != NULL) && !m_pCreateResourceData->Flags.MatchGdiPrimary)
        {
            pR2AllocData->sAllocInfo.RefreshRate = m_pCreateResourceData->RefreshRate;
        }
    }

    // Is this a open rather than a create
    if (m_pOpenResourceData != NULL)
    {
        // Check we have created the dummy Create data correctly. 
        // This is just a verification code.
        if (CheckOpenData(pR2AllocData, m_pOpenResourceData, m_CurResourceIdx) == FALSE)
        {
            DBG_BREAK;
        }

        // Return the handle of the opened resource
        *phAllocation = m_pOpenResourceData->pOpenAllocationInfo[m_CurResourceIdx].hAllocation;

        // Copy correct create data
        memcpy(pR2AllocData, m_pOpenResourceData->pOpenAllocationInfo[m_CurResourceIdx].pPrivateDriverData, m_pOpenResourceData->pOpenAllocationInfo[m_CurResourceIdx].PrivateDriverDataSize);

        // Move to next allocation
        m_CurResourceIdx++;

        return S_OK;
    }

    // Check to see if it's in system mem
    if (pSysMem)
    {
        allocInfo.pSystemMem = pSysMem;
        pR2AllocData->sAllocInfo.bExistingSysMem = TRUE;
    }
    else
    {
        pR2AllocData->sAllocInfo.bExistingSysMem = FALSE;
    }

    //
    // Use the runtime handle of the resource being created
    // NOTE: This is critical for supporting the shared resource
    //
    allocCB.hResource       = m_hCurResRuntime;


    //  NOTE: Sample driver doesn't support shared multisurface resource (cube maps, etc.) properly.
    //  Production driver should create shared resource by specifing appropriate number of allocations and
    //  call pfnAllocateCb exectly once.
    
    allocCB.NumAllocations  = 1;
    allocCB.pAllocationInfo = &allocInfo;


    hr = m_d3dCallbacks.pfnAllocateCb(m_hD3D, &allocCB);


    if (FAILED(hr))
    {
        allocInfo.hAllocation = NULL;
    }
    else
    {
        *phAllocation = allocInfo.hAllocation;
    }

    return (hr);
}

HRESULT
R200LockAllocationCB(
    LPVOID          pD3DDev,
    D3DKMT_HANDLE*  phAllocation,
    DWORD           dwLockFlags,
    BOOL            Tiled,
    DWORD           dwLockPriData,
    PVOID          *ppAllocation)
{
    CD3DContext    *pD3DCtxt;

    pD3DCtxt = reinterpret_cast<CD3DContext*>(pD3DDev);

    return (pD3DCtxt->LockAllocationCB(phAllocation,
                                       dwLockFlags,
                                       Tiled,
                                       dwLockPriData,
                                       ppAllocation));
}

HRESULT
CD3DContext::LockAllocationCB(
    D3DKMT_HANDLE*  phAllocation,
    DWORD           dwLockFlags,
    BOOL            Tiled,
    DWORD           dwLockPriData,
    PVOID          *ppAllocation)
{
    D3DDDICB_LOCK   lockCB;
    HRESULT         hr;

    //
    // Zero out the return value
    //
    *ppAllocation = NULL;

    //
    // Call the KM to lock the allocation
    //
    memset(&lockCB, 0, sizeof(D3DDDICB_LOCK));
    lockCB.hAllocation = *phAllocation;
    lockCB.PrivateDriverData=dwLockPriData;
    if (Tiled)
    {
        lockCB.Flags.AcquireAperture = TRUE;


    }
    if (dwLockFlags & DDLOCK_DONOTWAIT)
    {
        lockCB.Flags.DonotWait = TRUE;
    }
    if (dwLockFlags & DDLOCK_DISCARDCONTENTS)
    {
        lockCB.Flags.Discard = TRUE;
    }

    hr = m_d3dCallbacks.pfnLockCb(m_hD3D, &lockCB);


    if (!SUCCEEDED(hr) && lockCB.Flags.Discard == TRUE)
    {
        // Surface renaming failed, could be out of memory for new surface instance.  Now flush
        // CmdBuf to retire all of the surface instances and try again
        Flush(TRUE);
        lockCB.Flags.NoExistingReference = TRUE;
        hr = m_d3dCallbacks.pfnLockCb(m_hD3D, &lockCB);
    }

    if (SUCCEEDED(hr))
    {
        *ppAllocation = lockCB.pData;
        *phAllocation = lockCB.hAllocation;
    }

    return (hr);
}

HRESULT
CD3DContext::InitializeIntIB()
{
    HRESULT                     hr;
    D3DDDI_SURFACEINFO          surfInfo;
    D3DDDIARG_CREATERESOURCE    crData;

    if (m_ddSMoreIntIB.dwSurfaceHandle)
    {
        return (S_OK);
    }

    //
    // Set up the DD surface structure for the internal index buffer
    //
    m_ddSLclIntIB.lpGbl      = &m_ddSGblIntIB;
    m_ddSLclIntIB.lpSurfMore = &m_ddSMoreIntIB;

    m_ddSLclIntIB.ddsCaps.dwCaps     = DDSCAPS_SYSTEMMEMORY |
                                       DDSCAPS_EXECUTEBUFFER;
    m_ddSMoreIntIB.ddsCapsEx.dwCaps2 = DDSCAPS2_RESERVED3;  // DDSCAPS2_INDEXBUFFER;

    //
    // Set up the internal ex handle
    //
    if (! (m_ddSMoreIntIB.dwSurfaceHandle = GetExHandles(1)))
    {
        return (DDERR_OUTOFMEMORY);
    }

    //
    // Internal index buffer can only handle at most 64KB vertices
    //
    m_ddSGblIntIB.dwLinearSize = MAX_NUM_INDICES_INT_IB*4;
    m_ddSGblIntIB.wWidth       = m_ddSGblIntIB.dwLinearSize;
    m_ddSGblIntIB.wHeight      = 1;

    m_ddSGblIntIB.fpVidMem = (FLATPTR)VirtualAlloc(NULL,
                                                   m_ddSGblIntIB.dwLinearSize,
                                                   MEM_COMMIT,
                                                   PAGE_READWRITE);
    if (! m_ddSGblIntIB.fpVidMem)
    {
        return (DDERR_OUTOFMEMORY);
    }

    //
    // Set up the create resource data
    //
    memset(&surfInfo, 0, sizeof(D3DDDI_SURFACEINFO));
    surfInfo.Width       = m_ddSGblIntIB.dwLinearSize;
    surfInfo.Height      = 1;
    surfInfo.Depth       = 1;
    surfInfo.pSysMem     = (CONST VOID *)m_ddSGblIntIB.fpVidMem;
    surfInfo.SysMemPitch = surfInfo.Width;

    memset(&crData, 0, sizeof(D3DDDIARG_CREATERESOURCE));
    crData.Flags.IndexBuffer = TRUE;
    crData.Format    = D3DDDIFMT_INDEX32;
    crData.SurfCount = 1;
    crData.pSurfList = &surfInfo;
    crData.hResource = (HANDLE)(DWORD_PTR)m_ddSMoreIntIB.dwSurfaceHandle;

    hr = CreateSurfaceNotify(&crData, &m_ddSLclIntIB);
    if (FAILED(hr))
    {
        VirtualFree((LPVOID)m_ddSGblIntIB.fpVidMem,
                    0,
                    MEM_RELEASE);
        memset(&m_ddSLclIntIB, 0, sizeof(m_ddSLclIntIB));
        memset(&m_ddSGblIntIB, 0, sizeof(m_ddSGblIntIB));
        memset(&m_ddSMoreIntIB, 0, sizeof(m_ddSMoreIntIB));
    }

    return (hr);
}

HRESULT
R200DestroyAllocationCB(
    LPVOID          pD3DDev,
    D3DKMT_HANDLE   hAllocation)
{
    CD3DContext    *pD3DCtxt;

    pD3DCtxt = reinterpret_cast<CD3DContext*>(pD3DDev);

    return (pD3DCtxt->DestroyAllocationCB(hAllocation));
}

HRESULT
CD3DContext::DestroyAllocationCB(
    D3DKMT_HANDLE       hAllocation)
{
    D3DDDICB_DEALLOCATE deAllocCB;
    HRESULT             hr;
    D3DKMT_HANDLE       hKMAllocHandle;

    //
    // Allocations have been freed with the resource atomically
    //
    if ((m_hCurResRuntime) && (m_bCurResFreed))
    {
        return (DD_OK);
    }

    memset(&deAllocCB, 0, sizeof(deAllocCB));

    deAllocCB.hResource = m_hCurResRuntime;
    if (! m_hCurResRuntime)
    {
        hKMAllocHandle = (D3DKMT_HANDLE)hAllocation;

        //
        // When allocation is not associated with a resource
        //
        deAllocCB.NumAllocations = 1;
        deAllocCB.HandleList     = &hKMAllocHandle;
    }


    hr = m_d3dCallbacks.pfnDeallocateCb(m_hD3D, &deAllocCB);
    if ((m_hCurResRuntime) && (SUCCEEDED(hr)))
    {
        m_bCurResFreed = TRUE;
    }


    return (hr);
}

extern "C" DWORD GetDX8PixelFormatCount( LPD3DDEVICE lpD3DDevice );
extern "C" LPDDPIXELFORMAT GetDX8PixelFormatFromList( LPD3DDEVICE lpD3DDevice, DWORD dwIndex );
extern "C" void CopyDx7CapsToDx9(LPD3DDEVICE lpD3DDev, D3DCAPS9 *pD3D9Caps);
extern "C" void FillNewDx9Caps(LPD3DDEVICE lpD3DDev, D3DCAPS9 *pD3DCaps9);
extern "C" void CopyDx7CapsToDx8(LPD3DDEVICE lpD3DDev, D3DCAPS8 *pD3D8Caps);
extern "C" void FillNewDx8Caps(LPD3DDEVICE lpD3DDev, D3DCAPS8 *pD3DCaps8);
extern "C" void GetNewDDrawCaps(LPD3DDEVICE lpD3DDev, DDRAW_CAPS *pDDCaps);
extern "C" void FillInExtendedCaps(LPD3DDEVICE lpD3DDev, D3DHAL_D3DEXTENDEDCAPS* pExtendedCaps);
extern "C" void FillInGlobalDriverData(LPD3DDEVICE lpD3DDev, D3DHAL_GLOBALDRIVERDATA* pGlobalDriverData);


HRESULT
CD3DContext::GetCaps(
    CONST D3DDDIARG_GETCAPS*  pGetCaps)
{
    HRESULT hr = DDERR_UNSUPPORTED;

    switch(pGetCaps->Type)
    {
    case D3DDDICAPS_DDRAW:
        GetNewDDrawCaps(m_pR200D3DDev, (DDRAW_CAPS *)pGetCaps->pData);
        hr = S_OK;
        break;

    case D3DDDICAPS_DDRAW_MODE_SPECIFIC:
        {
            DDRAW_MODE_SPECIFIC_CAPS   *pDDModeCaps = (DDRAW_MODE_SPECIFIC_CAPS *)pGetCaps->pData;

            memset(pDDModeCaps, 0, sizeof(DDRAW_MODE_SPECIFIC_CAPS));

            hr = S_OK;
        }
        break;

    case D3DDDICAPS_GETFORMATCOUNT:
        *((UINT *)pGetCaps->pData) = GetDX8PixelFormatCount(m_pR200D3DDev);
        hr = S_OK;
        break;

    case D3DDDICAPS_GETD3DQUERYCOUNT:
        *((UINT *)pGetCaps->pData) = 1;
        hr = S_OK;
        break;

    case D3DDDICAPS_GETD3DQUERYDATA:
        *((D3DDDIQUERYTYPE *)pGetCaps->pData) = D3DDDIQUERYTYPE_EVENT;
        hr = S_OK;
        break;

    case D3DDDICAPS_GETFORMATDATA:
        {
            UINT            NumTextures = GetDX8PixelFormatCount(m_pR200D3DDev);
            DDPIXELFORMAT   Temp;
            FORMATOP       *pFormat = (FORMATOP*) pGetCaps->pData;
            UINT            i;

            for (i = 0; i < NumTextures; i++)
            {
                memcpy(&Temp,
                       GetDX8PixelFormatFromList(m_pR200D3DDev, i),
                       sizeof(DDPIXELFORMAT) );

                pFormat[i].Format      = (D3DDDIFORMAT)Temp.dwFourCC;
                pFormat[i].Operations  = Temp.dwOperations;
                pFormat[i].FlipMsTypes = 0; 

                pFormat[i].BltMsTypes  = 0;
                pFormat[i].PrivateFormatBitCount = Temp.dwPrivateFormatBitCount;
            }
            hr = S_OK;
        }
        break;

    case D3DDDICAPS_GETD3D9CAPS:
        {
            D3DCAPS9   *pCaps9 = (D3DCAPS9 *)pGetCaps->pData;

            CopyDx7CapsToDx9(m_pR200D3DDev, pCaps9);
            FillNewDx9Caps(m_pR200D3DDev, pCaps9);

            // For some reason the current code returns some dumb caps, so filter those out

            pCaps9->Caps  &= ~DDCAPS_NOHARDWARE;
            pCaps9->Caps2 &= ~(DDCAPS2_CANMANAGETEXTURE | DDCAPS2_TEXMANINNONLOCALVIDMEM | DDCAPS2_CANMANAGERESOURCE);

#ifndef HWINDEXBUF
            //
            // NOTE:
            //   HW index buffer causes:
            //     (1) ProgessiveMesh to crash when it tries to access the
            //         HW index buffer's CPU mapping
            //   Otherwise it is working and can be turned on.
            //
            pCaps9->DevCaps &= (~(D3DDEVCAPS_HWINDEXBUFFER));
#endif

            //
            // Turn off get scan line before it is supported
            //
            pCaps9->Caps &= (~(D3DCAPS_READ_SCANLINE));

            //
            // Patches are not supported yet, see BUG 889409 and 896803
            //
            pCaps9->DevCaps &= (~(D3DDEVCAPS_QUINTICRTPATCHES));
            pCaps9->DevCaps &= (~(D3DDEVCAPS_RTPATCHES));
            pCaps9->DevCaps &= (~(D3DDEVCAPS_NPATCHES));

            hr = S_OK;
        }
        break;


    case D3DDDICAPS_GETD3D8CAPS:
        {
            D3DCAPS8   *pCaps8 = (D3DCAPS8 *)pGetCaps->pData;

            CopyDx7CapsToDx8(m_pR200D3DDev, pCaps8);
            FillNewDx8Caps(m_pR200D3DDev, pCaps8);

            // For some reason the current code returns some dumb caps, so filter those out

            pCaps8->Caps  &= ~DDCAPS_NOHARDWARE;
            pCaps8->Caps2 &= ~(DDCAPS2_CANMANAGETEXTURE|DDCAPS2_TEXMANINNONLOCALVIDMEM|DDCAPS2_CANMANAGERESOURCE);

#ifndef HWINDEXBUF
            //
            // Turn off index buffer support for DX8
            //
            pCaps8->DevCaps &= (~(D3DDEVCAPS_HWINDEXBUFFER));
#endif

            //
            // Turn off get scan line before it is supported
            //
            pCaps8->Caps &= (~(D3DCAPS_READ_SCANLINE));

            //
            // Patches are not supported yet, see BUG 889409 and 896803
            //
            pCaps8->DevCaps &= (~(D3DDEVCAPS_QUINTICRTPATCHES));
            pCaps8->DevCaps &= (~(D3DDEVCAPS_RTPATCHES));
            pCaps8->DevCaps &= (~(D3DDEVCAPS_NPATCHES));

            hr = S_OK;
        }
        break;

    case D3DDDICAPS_GETD3D7CAPS:
        {
            FillInExtendedCaps(m_pR200D3DDev, (D3DHAL_D3DEXTENDEDCAPS *)pGetCaps->pData);
            hr = S_OK;
        }
        break;

    case D3DDDICAPS_GETD3D3CAPS:
        {
            FillInGlobalDriverData(m_pR200D3DDev, (D3DHAL_GLOBALDRIVERDATA *)pGetCaps->pData);
            hr = S_OK;
        }
        break;

    case D3DDDICAPS_GETDECODEGUIDCOUNT:
        *((UINT*)pGetCaps->pData) = GetNumDXVAGuids();
        hr = S_OK;
        break;

    case D3DDDICAPS_GETDECODEGUIDS:
        CopyDXVAGuids(pGetCaps->pData);
        hr = S_OK;
        break;

    case D3DDDICAPS_GETDECODERTFORMATCOUNT:
        *((UINT*)pGetCaps->pData) = GetNumDecodeOutputFormats((GUID*)(pGetCaps->pInfo));
        hr = S_OK;
        break;

    case D3DDDICAPS_GETDECODERTFORMATS:
        CopyDecodeOutputFormats((GUID*)(pGetCaps->pInfo), (D3DDDIFORMAT*)(pGetCaps->pData));
        hr = S_OK;
        break;

    case D3DDDICAPS_GETDECODECOMPRESSEDBUFFERINFOCOUNT:
        *((UINT*)pGetCaps->pData) = GetNumDecodeBufferInfo((DXVADDI_DECODEINPUT*)(pGetCaps->pInfo));
        hr = S_OK;
        break;

    case D3DDDICAPS_GETDECODECOMPRESSEDBUFFERINFO:
        CopyDecodeBufferInfo((DXVADDI_DECODEINPUT*)(pGetCaps->pInfo), (DXVADDI_DECODEBUFFERINFO*)(pGetCaps->pData));
        hr = S_OK;
        break;

    case D3DDDICAPS_GETDECODECONFIGURATIONCOUNT:
        *((UINT*)pGetCaps->pData) = GetNumDecodeConfigs((DXVADDI_DECODEINPUT*)(pGetCaps->pInfo));
        hr = S_OK;
        break;

    case D3DDDICAPS_GETDECODECONFIGURATIONS:
        CopyDecodeConfigs((DXVADDI_DECODEINPUT*)(pGetCaps->pInfo), (DXVADDI_CONFIGPICTUREDECODE*)(pGetCaps->pData));
        hr = S_OK;
        break;

    case D3DDDICAPS_GETVIDEOPROCESSORDEVICEGUIDCOUNT:
        *((UINT*)pGetCaps->pData) = GetNumVideoProcessorDeviceGuids((DXVADDI_VIDEODESC*)(pGetCaps->pInfo));
        hr = S_OK;
        break;

    case D3DDDICAPS_GETVIDEOPROCESSORDEVICEGUIDS:
        hr = GetVideoProcessorDeviceGuids((DXVADDI_VIDEODESC*)(pGetCaps->pInfo), (GUID*)(pGetCaps->pData));
        break;

    case D3DDDICAPS_GETVIDEOPROCESSORCAPS:
        hr = GetVideoProcessingCaps((DXVADDI_VIDEOPROCESSORINPUT*) (pGetCaps->pInfo),
            (DXVADDI_VIDEOPROCESSORCAPS*)(pGetCaps->pData));
        break;

    case D3DDDICAPS_GETPROCAMPRANGE:
        hr = GetProcAmpRange((DXVADDI_QUERYPROCAMPINPUT*) (pGetCaps->pInfo),
            (DXVADDI_VALUERANGE*)(pGetCaps->pData));
        break;

    case D3DDDICAPS_GETGAMMARAMPCAPS:
        {
            DDIGAMMACAPS* pGammaCaps = (DDIGAMMACAPS*) pGetCaps->pData;
            pGammaCaps->GammaCaps = GAMMA_CAP_RGB256x3x16;
            hr = S_OK;
        }
        break;
    }

    return (hr);
}

HRESULT
CD3DContext::SetStreamSourceFreq(CONST D3DDDIARG_SETSTREAMSOURCEFREQ* pData)
{
    return S_OK;
}

HRESULT
CD3DContext::SetConvolutionKernelMono(CONST D3DDDIARG_SETCONVOLUTIONKERNELMONO* pData)
{
    return S_OK;
}

HRESULT
CD3DContext::ComposeRects(CONST D3DDDIARG_COMPOSERECTS* pData)
{
    return S_OK;
}

HRESULT
CD3DContext::QueryResourceResidency(CONST D3DDDIARG_QUERYRESOURCERESIDENCY* pQRR)
{
    D3DDDICB_QUERYRESIDENCY queryRes;
    D3DDDI_RESIDENCYSTATUS  resStatus = (D3DDDI_RESIDENCYSTATUS)0;
    HRESULT hr;
    BOOL    bPartInSharedMem = FALSE;

    for (UINT i = 0; i < pQRR->NumResources; i++)
    {
        memset(&queryRes, 0, sizeof(queryRes));

        queryRes.hResource = m_RTbl[(DWORD)(DWORD_PTR)pQRR->pHandleList[i]].m_hResRuntime;
        if (! queryRes.hResource)
        {
            return (DDERR_INVALIDPARAMS);
        }

        queryRes.pResidencyStatus = &resStatus;

        hr = m_d3dCallbacks.pfnQueryResidencyCb(m_hD3D, &queryRes);
        if (FAILED(hr))
        {
            return (hr);
        }

        switch (resStatus)
        {
        case D3DDDI_RESIDENCYSTATUS_NOTRESIDENT:
            return S_NOT_RESIDENT;
        case D3DDDI_RESIDENCYSTATUS_RESIDENTINSHAREDMEMORY:
            bPartInSharedMem = TRUE;
            break;
        case D3DDDI_RESIDENCYSTATUS_RESIDENTINGPUMEMORY:
            break;
        default:
            return DDERR_GENERIC;
        }
    }

    if (bPartInSharedMem)
    {
        return S_RESIDENT_IN_SHARED_MEMORY;
    }
    else
    {
        return  S_OK;
    }
}

CD3DFence::CD3DFence(CD3DContext* pContext) :
    m_hResource(NULL),
    m_NextFence(0),
    m_pCurrentFence(NULL),
    m_bWrapped(FALSE)
{
    m_pContext = pContext;
}

CD3DFence::~CD3DFence(VOID)
{
    if (m_hResource != NULL)
    {
        if (m_pCurrentFence != NULL)
        {
            D3DDDIARG_UNLOCK UnlockData;

            UnlockData.hResource = m_hResource;
            UnlockData.SubResourceIndex = 0;
            m_pContext->Unlock(&UnlockData);
        }
        m_pContext->DestroyResource(m_hResource);
    }
}

HRESULT
CD3DFence::Initialize(VOID)
{
    if (m_hResource == NULL)
    {
        D3DDDIARG_CREATERESOURCE    crData;
        D3DDDI_SURFACEINFO          surfInfo;
        HRESULT hr;

        memset(&crData, 0, sizeof(D3DDDIARG_CREATERESOURCE));
        memset(&surfInfo, 0, sizeof(D3DDDI_SURFACEINFO));

        surfInfo.Width  = 1;
        surfInfo.Height = 1;
        surfInfo.Depth  = 1;

        crData.Format    = D3DDDIFMT_A8R8G8B8;
        crData.Pool      = D3DDDIPOOL_NONLOCALVIDMEM;
        crData.pSurfList = &surfInfo;
        crData.SurfCount = 1;
        crData.MipLevels = 1;

        hr = m_pContext->CreateResource(&crData);
        if (FAILED(hr))
        {
            return E_FAIL;
        }

        m_hResource = crData.hResource;
        m_NextFence = 1;

        // Now lock the resource so we can read the fence
        D3DDDIARG_LOCK LockData;

        memset(&LockData, 0, sizeof(LockData));
        LockData.hResource = m_hResource;
        LockData.Flags.NoOverwrite = TRUE;
        hr = m_pContext->Lock(&LockData);
        if (FAILED(hr))
        {
            m_pContext->DestroyResource(m_hResource);
            m_hResource = NULL;
            return E_FAIL;
        }
        m_pCurrentFence = (UINT*) LockData.pSurfData;
        *m_pCurrentFence = 0;
    }

    return S_OK;
}

// We want a generic fence mechanism to handle D3D queries and possibly buffer renaming.
// It is a fairly straight forward mechanism where we issue a command to write a value to
// our fence memory, and then we can read the value of the fence memory to know whether the
// command has been executed or not.  By incrementing the value for each fence submition,
// we can tell when all previous submitions have been completed.
//
// This mechanism breaks down, however, when the UINT fence value reaches 4 gig, at which
// point it wraps back around to zero.  Our current fence value may be very high, while we are
// quering very low fence values, resulting in false positives.
//
// We attempt a very simply work around by assuming that 2 gig worth of queries will not be
// submitted without being queried.  With this assumption, a very large current fence value and
// a very low query value will result in the correct response as long as they are more than 2 gig
// apart.  If a submitions is queried after 2 gig worth of previous submitions, however, the query
// will result in a false negative.  I belive that this is a worthwhile trade-off since it
// simplifies our design.


#define MAX_FENCE_VALUE    ((UINT) -1)
#define HALF_FENCE_VALUE   (MAX_FENCE_VALUE / 2)

_inline UINT FenceValue(UINT Start, UINT Add)
{
    // We want to do our own wrap around handling rather than rely on
    // the compiler.
    if ((MAX_FENCE_VALUE - Start) < Add)
    {
        return (Add - ((MAX_FENCE_VALUE - Start) + 1));
    }
    return Start + Add;
}

BOOL
CD3DFence::QueryFence(UINT Value)
{
    UINT Current = *m_pCurrentFence;
    UINT LastFence = FenceValue(m_NextFence, HALF_FENCE_VALUE);

    if (!m_bWrapped)
    {
        if (Value <= Current)
        {
            return TRUE;
        }
    }
    else
    {
        if (Current >= LastFence)
        {
            if ((Value >= LastFence) &&
                (Value <= Current))
            {
                return TRUE;
            }
        }
        else
        {
            if ((Value >= LastFence) ||
                (Value <= Current))
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}

HRESULT
CD3DFence::GetNextFenceValue(UINT* fence)
{
    if ((m_NextFence == FenceValue(*m_pCurrentFence, HALF_FENCE_VALUE)) &&
        ((m_NextFence - *m_pCurrentFence) > HALF_FENCE_VALUE))
    {
        return E_OUTOFMEMORY;
    }
    else
    {
        UINT oldFence = m_NextFence; 
        m_NextFence = FenceValue(m_NextFence, 1);
        if (m_NextFence < oldFence)
        {
            m_bWrapped = TRUE;
        }
        *fence = oldFence;
        return S_OK;
    }
}

VOID
CD3DFence::SubmitFence(UINT Fence)
{
    D3DHAL_DP2COLORFILL    *pDP2Color;

    pDP2Color = (D3DHAL_DP2COLORFILL *)m_pContext->GetBufferPointer(D3DDP2OP_COLORFILL, sizeof(D3DHAL_DP2COLORFILL));
    pDP2Color->dwSurface    = (DWORD)(DWORD_PTR)m_hResource;
    pDP2Color->rRect.left   = 0;
    pDP2Color->rRect.right  = 1;
    pDP2Color->rRect.top    = 0;
    pDP2Color->rRect.bottom = 1;
    pDP2Color->Color        = Fence;
}

#ifdef PRIVATE_HEAP
extern "C"
{
HANDLE g_Heap = NULL;
};
#endif

//
// DllMain
//

extern "C"
{
void ReadDebugRegistrySettings(void);
}

BOOL WINAPI
DllMain(HINSTANCE hmod, DWORD dwReason, LPVOID lpvReserved)
{
    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:

#ifdef DEBUG
        ReadDebugRegistrySettings();
#endif

#ifdef PRIVATE_HEAP
        g_Heap = HeapCreate(0,
                            1024 * 16,
                            0);             // Heap is growable
        if (g_Heap)
        {
            return (TRUE);
        }
        else
        {
            return (FALSE);
        }
#endif
        break;

    case DLL_PROCESS_DETACH:
#ifdef PRIVATE_HEAP
        if (g_Heap)
        {
            HeapDestroy(g_Heap);
        }
#endif
        break;

    default:
        break;
    }

    return TRUE;
}

extern "C"
{
extern BOOL BreakOnAssert;
}

void ReadDebugRegistrySettings(void)
{
    int     result;
    HKEY    hKey;
    DWORD   valType;
    DWORD   dwUMDisableAssertsAndDbgBreaks;
    DWORD   dwUMBreakOnLoad=0;
    DWORD   dwSize;

    // Open registry key
    result = RegOpenKeyExA( HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Services\\R200", 0, KEY_QUERY_VALUE, &hKey );
    if ( result != ERROR_SUCCESS )
    {
        return;
    }

    // Do we want to break into the debugger as soon as we have been loaded
    dwSize=sizeof(DWORD);
    result = RegQueryValueExA( hKey, "UMBreakOnLoad", NULL, &valType,
                               (LPBYTE)&dwUMBreakOnLoad, (LPDWORD)&dwSize );
    if ( (result == ERROR_SUCCESS) && (valType == REG_DWORD) )
    {
        if (dwUMBreakOnLoad != 0)
        {
            DBG_BREAK;
        }
    }

    // Do we want to diable asserts and dbg breaks
    dwSize=sizeof(DWORD);
    result = RegQueryValueExA( hKey, "UMDisableAssertsAndDbgBreaks", NULL, &valType,
                               (LPBYTE)&dwUMDisableAssertsAndDbgBreaks, (LPDWORD)&dwSize );
    if ( (result == ERROR_SUCCESS) && (valType == REG_DWORD) )
    {
        if (dwUMDisableAssertsAndDbgBreaks == 1)
        {
            BreakOnAssert=FALSE;
        }
    }



    RegCloseKey(hKey);

    return;
}

DWORD AddHandleToAllocationList(D3DDDI_ALLOCATIONLIST *psAllocationList, DWORD dwAllocationListSize, PDWORD pdwdwCurAllocationListIdx, D3DKMT_HANDLE hHandle,UINT bWrite)
{
    DWORD                   dwIdx=0;
    D3DDDI_ALLOCATIONLIST   *psAllocationListEntry=psAllocationList;

    // First check if handle is already in table already
    while (dwIdx < *pdwdwCurAllocationListIdx)
    {
        if (psAllocationListEntry->hAllocation == hHandle)
        {
            return dwIdx;
        }
        dwIdx++;
        psAllocationListEntry++;
    }

    // New handle, is there room
    if (*pdwdwCurAllocationListIdx >= dwAllocationListSize)
    {
        // No room
        DBG_BREAK;
        return 0xffffffff;
    }

    // Add new entry

    dwIdx = *pdwdwCurAllocationListIdx;
    psAllocationList[dwIdx].hAllocation = hHandle;
    psAllocationList[dwIdx].WriteOperation = bWrite;
    psAllocationList[dwIdx].Reserved = 0;

    (*pdwdwCurAllocationListIdx)++;

    return dwIdx;
}


BOOL GenerateAllocationListFromCmdBuf(QS_PARAM *pQSParam, D3DDDI_ALLOCATIONLIST *psAllocationList, DWORD dwAllocationListSize, PDWORD pdwListEntriesUsed)
{
    DWORD   *pPM4Buf, *pPM4BufEnd, *pCurPM4Packet;
    DWORD   dwPM4PacketSize, dwPM4PacketHeader;
    DWORD   dwPM4RegCount;
    DWORD   dwOpCode;
    DWORD   dwCurAllocationListIdx=0;   //Idx of next slot to use

    pPM4Buf = (PDWORD)pQSParam->pList;
    pPM4BufEnd = (PDWORD)((PBYTE)pPM4Buf + pQSParam->dwListSize);
    pCurPM4Packet = pPM4Buf;

    // Set first entry to be a NULL handle so it can be used to unbind allocations from resource slots.
    psAllocationList->hAllocation = (D3DKMT_HANDLE)0;
    psAllocationList->Reserved = 0;
    psAllocationList->WriteOperation = 0;
    dwCurAllocationListIdx++;

    do
    {
        //
        // dwPM4PacketSize of -1 indicates wrongly formated PM4 packet
        //
        dwPM4PacketSize = -1;

        dwPM4PacketHeader = *pCurPM4Packet;
        switch (dwPM4PacketHeader >> 30)
        {
        case 0:
            dwPM4RegCount = ((dwPM4PacketHeader & 0x3FFF0000) >> 16) + 1;
            dwPM4PacketSize = 1 + dwPM4RegCount;
            break;

        case 1:
        case 2:
            dwPM4PacketSize = -1;
            break;

        case 3:
            //
            // Calculate the size of the type 3 packet
            //
            dwPM4PacketSize = ((dwPM4PacketHeader & 0x3FFF0000) >> 16) + 2;
            dwOpCode = (dwPM4PacketHeader & (0xFF00)) >> 8;

            if (dwOpCode == GetType3OpCode(PM4_PACKET3_NOP))
            {
                D3DResourceID   d3dResID = (D3DResourceID)(dwPM4PacketHeader & 0xFF);
                D3DKMT_HANDLE   hNew = *(D3DKMT_HANDLE *)(pCurPM4Packet + 1);
                DWORD           dwIdx;

                if (d3dResID < D3D_RES_ALL && hNew != 0)
                {
                    // for simplicity we will set the WriteOperation flag for all allocations
                    // this will cause performace issues so this should not be done in a production driver.
                    dwIdx = AddHandleToAllocationList(psAllocationList, dwAllocationListSize, &dwCurAllocationListIdx, hNew,(UINT)1);
                    if (dwIdx == 0xffffffff)
                    {
                        return FALSE;
                    }

                    // We overload the PM4 type 3 NOP packet count field with the Allocation list Idx, KM driver
                    // can place the correct count value into the packet header during Render as all the handle NOP
                    // packets are the same size
                    *pCurPM4Packet = (dwPM4PacketHeader & ~0x3FFF0000) + (dwIdx << 16);
                }
            }

            break;
        default:
            DBG_BREAK;
            return FALSE;
        }

        if (dwPM4PacketSize == -1)
        {
            DBG_BREAK;
            return FALSE;
        }

        //
        // Move on to the next PM4 packet
        //
        pCurPM4Packet += dwPM4PacketSize;

    }while (pCurPM4Packet < pPM4BufEnd);

    *pdwListEntriesUsed = dwCurAllocationListIdx;

    return TRUE;
}


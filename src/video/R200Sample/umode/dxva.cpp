/******************************Module*****************************************\
*
*                           *******************
*                           * D3D SAMPLE CODE *
*                           *******************
*

* Copyright (c) 2003 Microsoft Corporation.  All rights reserved.
\*****************************************************************************/

#include <crtdbg.h>
#include <limits.h>

#define DIRECT3D_VERSION 0x0900
#define INITGUID
#include "d3dumode.hpp"
#include "dxva.hpp"
#include "radeon.h"
#include "dva9x.h"
#include "dvaidct.h"
#include "ipt.h"
#include "MultiEngine.h"

#define R3xx_MaxMacroBlock  0x700

GUID SupportedDXVAGuids[] =
{
    DXVADDI_ModeMPEG2_IDCT
//    {0x1b81be0D,0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5}, //DXVA_ModeMPEG2_D
//    {0x1b81beD0,0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5}, //DXVA_NoEncrypt guid
};

#define NUM_DXVA_GUIDS              (sizeof(SupportedDXVAGuids)/sizeof(GUID))
#define NUM_SUPPORTED_CONFIGS       2

DWORD   GetNumDecodeConfigs(DXVADDI_DECODEINPUT* pInput);
VOID    CopyDecodeConfigs(DXVADDI_DECODEINPUT* pInput, DXVADDI_DECODEBUFFERINFO* pConfigList);


static DXVADDI_CONFIGPICTUREDECODE ModeConfig[NUM_SUPPORTED_CONFIGS] =
{
    {
       DXVADDI_NoEncrypt, DXVADDI_NoEncrypt, DXVADDI_NoEncrypt, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1
    },
    {
       DXVADDI_NoEncrypt, DXVADDI_NoEncrypt, DXVADDI_NoEncrypt, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //VLD
    }
};

DWORD R200_StartBufferArray[] =
{
    mmWAIT_UNTIL,           // 0 
    WAIT_UNTIL__WAIT_2D_IDLE | WAIT_UNTIL__WAIT_3D_IDLE | WAIT_UNTIL__WAIT_2D_IDLECLEAN | WAIT_UNTIL__WAIT_3D_IDLECLEAN,
    mmSE_CNTL,              // 2
    0x00000000,             // 3
    mmRE_CNTL,              // 4
    0x00000000,             // 5
    mmRE_PERF_CNTL,         // 6
    0x00000010,             // 7
    mmRE_WIDTH_HEIGHT,      // 8
    0x07ff07ff,             // 9
    mmRB3D_CNTL,            // 10
    0x00002001,             // 11
    mmRB3D_BLENDCNTL,       // 12
    0x01020000,             // 13
    mmRB3D_COLORPITCH,      // 14
    0xAAAAAAAA,             // 15 pDVDInfo->dwPitchY/2,
    mmPP_CNTL,              // 16
    0x80000000,             // 17
    mmPP_TEX_SIZE_0,        // 18
    0x07f007f0,             // 19
    mmPP_TEX_SIZE_1,        // 20
    0x07f007f0,             // 21
    mmPP_TXFILTER_0,        // 22
    0x00000003,             // 23
    mmPP_TXFORMAT_0,        // 24
    0x00000088,             // 25
    mmPP_TXPITCH_0,         // 26
    0xAAAAAAAA,             // 27 pDVDInfo->dwPitchY/2 - 32,
    mmPP_TXFILTER_1,        // 28
    0x00000003,             // 29
    mmPP_TXFORMAT_1,        // 30
    0x01000088,             // 31
    mmPP_TXPITCH_1,         // 32
    0xAAAAAAAA,             // 33 pDVDInfo->dwPitchY/2 - 32,
    mmSE_MC_BUF_BASE,       // 34
    0xAAAAAAAA,             // 35 pDVDInfo->dwMCFBLocation
    mmPP_TXOFFSET_0,        //36
    0x00000000,             //37
    mmPP_TXOFFSET_1,        //38
    0x00000000              //39
};

DWORD R200_EndBufferArray[] =
{
    mmRE_PERF_CNTL,
    0x00000000
};

#define END_BUFFER_PADDING  (77 + (sizeof(R200_EndBufferArray) / sizeof(DWORD)) + 1000)

#ifdef CAPTURE_DXVA_BUFFERS 
VOID CopyBufferContents(UINT Frame, DWORD* pBuffer, UINT BufferSize);
UINT gBuffCount = 0;
#endif

//
// GetNumDXVAGuids
//
// Returns the number of DXVA GUIDs supported by the user mode driver
//
DWORD
CD3DContext::GetNumDXVAGuids(
    VOID)
{
    return NUM_DXVA_GUIDS;    // Un-comment this to enable DXVA
}

//
// CopyDXVAGuids
//
// Retrieves the list of DXVA GUIDS supported by the user mode driver.
//
VOID
CD3DContext::CopyDXVAGuids(
    VOID* pGuids)
{
    memcpy(pGuids, SupportedDXVAGuids, sizeof(SupportedDXVAGuids));
}

DWORD
CD3DContext::GetNumDecodeOutputFormats(
    GUID* pGuid)
{
    _ASSERT(*pGuid == DXVADDI_ModeMPEG2_IDCT);
    return 1;
}

VOID
CD3DContext::CopyDecodeOutputFormats(
    GUID* pGuid, 
    D3DDDIFORMAT* pList)
{
    _ASSERT(*pGuid == DXVADDI_ModeMPEG2_IDCT);
    pList[0] = (D3DDDIFORMAT) MAKEFOURCC('Y','V','1','2');
}

DWORD
CD3DContext::GetNumDecodeBufferInfo(DXVADDI_DECODEINPUT* pInput)
{
    _ASSERT(*(pInput->pGuid) == DXVADDI_ModeMPEG2_IDCT);
    return 7;
}

VOID
CD3DContext::CopyDecodeBufferInfo(DXVADDI_DECODEINPUT* pInput, DXVADDI_DECODEBUFFERINFO* pBufferInfo)
{
    _ASSERT(*(pInput->pGuid) == DXVADDI_ModeMPEG2_IDCT);

    DXVADDI_VIDEODESC* pVideoDesc = &pInput->VideoDesc;

    UINT MaxNumOfMB = ((pVideoDesc->SampleWidth+15)/16) * ((pVideoDesc->SampleHeight+15)/16);
    if ((MaxNumOfMB > R3xx_MaxMacroBlock) || (MaxNumOfMB == 0))
    {
        MaxNumOfMB = R3xx_MaxMacroBlock;
    }

    UINT Size = sizeof(DXVA_PictureParameters);
    pBufferInfo[0].CompressedBufferType = D3DDDIFMT_PICTUREPARAMSDATA;
    pBufferInfo[0].CreationWidth = Size;
    pBufferInfo[0].CreationHeight = 1;
    pBufferInfo[0].CreationPool = D3DDDIPOOL_SYSTEMMEM;

    Size = sizeof(DXVA_MBctrl_P_OffHostIDCT_1) * MaxNumOfMB;
    pBufferInfo[1].CompressedBufferType = D3DDDIFMT_MACROBLOCKDATA;
    pBufferInfo[1].CreationWidth = 4096;
    pBufferInfo[1].CreationHeight = (Size + 4095) / 4096;
    pBufferInfo[1].CreationPool = D3DDDIPOOL_SYSTEMMEM;

    UINT MaxIndexCoef = MaxNumOfMB * ((8 * 8) * 6);
    Size = sizeof(DXVA_TCoef4Group) * MaxIndexCoef;
    pBufferInfo[2].CompressedBufferType = D3DDDIFMT_RESIDUALDIFFERENCEDATA;
    pBufferInfo[2].CreationWidth = 4096;
    pBufferInfo[2].CreationHeight = (Size + 4095) / 4096;
    pBufferInfo[2].CreationPool = D3DDDIPOOL_SYSTEMMEM;

    pBufferInfo[3].CompressedBufferType = D3DDDIFMT_DEBLOCKINGDATA;
    pBufferInfo[3].CreationWidth = 0;
    pBufferInfo[3].CreationHeight = 0;
    pBufferInfo[3].CreationPool = D3DDDIPOOL_SYSTEMMEM;

    Size = sizeof(DXVA_QmatrixData);
    pBufferInfo[4].CompressedBufferType = D3DDDIFMT_INVERSEQUANTIZATIONDATA;
    pBufferInfo[4].CreationWidth = 4;
    pBufferInfo[4].CreationHeight = (Size + 3) / 4;
    pBufferInfo[4].CreationPool = D3DDDIPOOL_SYSTEMMEM;

    Size = sizeof(DXVA_SliceInfo) * pVideoDesc->SampleHeight * 10;
    pBufferInfo[5].CompressedBufferType = D3DDDIFMT_SLICECONTROLDATA;
    pBufferInfo[5].CreationWidth = 4096;
    pBufferInfo[5].CreationHeight = (Size + 4095) / 4096;
    pBufferInfo[5].CreationPool = D3DDDIPOOL_SYSTEMMEM;

    Size = pVideoDesc->SampleHeight * pVideoDesc->SampleWidth * 3 /2;
    pBufferInfo[6].CompressedBufferType = D3DDDIFMT_BITSTREAMDATA;
    pBufferInfo[6].CreationWidth = 4096;
    pBufferInfo[6].CreationHeight = (Size + 4095) / 4096;
    pBufferInfo[6].CreationPool = D3DDDIPOOL_SYSTEMMEM;
}

DWORD
CD3DContext::GetNumDecodeConfigs(
    DXVADDI_DECODEINPUT* pInput)
{
    return 1;
}

VOID
CD3DContext::CopyDecodeConfigs(
    DXVADDI_DECODEINPUT* pInput, 
    DXVADDI_CONFIGPICTUREDECODE* pConfigList)
{
    pConfigList[0] = ModeConfig[0];
}

DWORD
CD3DContext::GetNumVideoProcessorDeviceGuids(
    DXVADDI_VIDEODESC* pVideoDesc)
{
    switch (pVideoDesc->SampleFormat.SampleFormat)
    {
    case DXVADDI_SampleProgressiveFrame:
    case DXVADDI_SampleFieldInterleavedEvenFirst:
    case DXVADDI_SampleFieldInterleavedOddFirst:
    case DXVADDI_SampleFieldSingleEven:
    case DXVADDI_SampleFieldSingleOdd:
        return 1;
        break;
    }

    return 0;
}

HRESULT
CD3DContext::GetVideoProcessorDeviceGuids(
    DXVADDI_VIDEODESC* pVideoDesc, GUID* pData)
{
    HRESULT hr = S_OK;

    switch (pVideoDesc->SampleFormat.SampleFormat)
    {
    case DXVADDI_SampleProgressiveFrame:
        *pData = DXVADDI_VideoProcProgressiveDevice;
        break;

    case DXVADDI_SampleFieldInterleavedEvenFirst:
    case DXVADDI_SampleFieldInterleavedOddFirst:
    case DXVADDI_SampleFieldSingleEven:
    case DXVADDI_SampleFieldSingleOdd:
        *pData = DXVADDI_VideoProcBobDevice;
        break;

    default:
        hr = E_INVALIDARG;
        break;
    }

    return hr;
}

HRESULT
CD3DContext::GetVideoProcessingCaps(
    DXVADDI_VIDEOPROCESSORINPUT* pInput, 
    DXVADDI_VIDEOPROCESSORCAPS* pOutput)
{
    _ASSERT(pInput->pVideoProcGuid != NULL);

    if (*pInput->pVideoProcGuid == DXVADDI_VideoProcBobDevice)
    {
        if (pInput->VideoDesc.Format != '21VY' &&
            pInput->VideoDesc.Format != '21VN' &&
            pInput->VideoDesc.Format != '2YUY' &&
            pInput->VideoDesc.Format != 'YVYU')
        {
            return DDERR_UNSUPPORTED;   // Unsupported format.
        }

        pOutput->DeinterlaceTechnology = DXVADDI_DEINTERLACETECH_BOBVERTICALSTRETCH;

        pOutput->ProcAmpControlCaps = 0;
    }
    else if (*pInput->pVideoProcGuid == DXVADDI_VideoProcProgressiveDevice)
    {
        pOutput->DeinterlaceTechnology = 0;

        pOutput->ProcAmpControlCaps = DXVADDI_PROCAMP_BRIGHTNESS |
                                      DXVADDI_PROCAMP_CONTRAST |
                                      DXVADDI_PROCAMP_HUE |
                                      DXVADDI_PROCAMP_SATURATION;
    }
    else
    {
        return E_INVALIDARG;    // Unsupported Video Processor Device.
    }

    pOutput->NumForwardRefSamples = 0;
    pOutput->NumBackwardRefSamples = 0;
    pOutput->OutputFormat = pInput->VideoDesc.Format;
    pOutput->InputPool = D3DDDIPOOL_LOCALVIDMEM;
    pOutput->NoiseFilterTechnology = 0;
    pOutput->DetailFilterTechnology = 0;

    pOutput->VideoProcessorOperations = DXVADDI_VIDEOPROCESS_YUV2RGB |
                                        DXVADDI_VIDEOPROCESS_STRETCHX |
                                        DXVADDI_VIDEOPROCESS_STRETCHY;

    return S_OK;
}

HRESULT
CD3DContext::GetProcAmpRange(
    DXVADDI_QUERYPROCAMPINPUT* pInput,
    DXVADDI_VALUERANGE* pOutput)
{
    switch (pInput->ProcAmpCap)
    {
    case DXVADDI_PROCAMP_BRIGHTNESS:
        pOutput->MinValue.Value         = -100; // -100.0
        pOutput->MinValue.Fraction      = 0;

        pOutput->MaxValue.Value         = 100;  // 100.0
        pOutput->MaxValue.Fraction      = 0;

        pOutput->DefaultValue.Value     = 0;    // 0.0
        pOutput->DefaultValue.Fraction  = 0;

        pOutput->StepSize.Value         = 0;    // 0.1
        pOutput->StepSize.Fraction      = static_cast<USHORT> (0.1 * USHRT_MAX);

        break;

    case DXVADDI_PROCAMP_CONTRAST:
        pOutput->MinValue.Value         = 0;    // 0.0
        pOutput->MinValue.Fraction      = 0;

        pOutput->MaxValue.Value         = 10;   // 10.0
        pOutput->MaxValue.Fraction      = 0;

        pOutput->DefaultValue.Value     = 1;    // 1.0
        pOutput->DefaultValue.Fraction  = 0;

        pOutput->StepSize.Value         = 0;    // 0.01
        pOutput->StepSize.Fraction      = static_cast<USHORT> (0.01 * USHRT_MAX);

        break;

    case DXVADDI_PROCAMP_HUE:
        pOutput->MinValue.Value         = -180; // -180.0
        pOutput->MinValue.Fraction      = 0;

        pOutput->MaxValue.Value         = 180;  // 180.0
        pOutput->MaxValue.Fraction      = 0;

        pOutput->DefaultValue.Value     = 0;    // 0.0
        pOutput->DefaultValue.Fraction  = 0;

        pOutput->StepSize.Value         = 0;    // 0.1
        pOutput->StepSize.Fraction      = static_cast<USHORT>(0.1 * USHRT_MAX);

        break;

    case DXVADDI_PROCAMP_SATURATION:
        pOutput->MinValue.Value         = 0;    // 0.0
        pOutput->MinValue.Fraction      = 0;

        pOutput->MaxValue.Value         = 10;   // 10.0
        pOutput->MaxValue.Fraction      = 0;

        pOutput->DefaultValue.Value     = 1;    // 1.0
        pOutput->DefaultValue.Fraction  = 0;

        pOutput->StepSize.Value         = 0;    // 0.01
        pOutput->StepSize.Fraction      = static_cast<USHORT>(0.01 * USHRT_MAX);

        break;

    default:
        return E_INVALIDARG;
    }
    return S_OK;
}

HRESULT
CD3DContext::CreateDecodeDevice(
    D3DDDIARG_CREATEDECODEDEVICE* pCreateData)
{
    CDXVA*                  pDxvaDevice;
    D3DDDICB_CREATECONTEXT  sCreateContext;
    HRESULT                 hr;

    pCreateData->hDecode = NULL;

    pDxvaDevice = new CDXVA(this,
                            pCreateData->pGuid,
                            pCreateData->VideoDesc.SampleWidth,
                            pCreateData->VideoDesc.SampleHeight,
                            pCreateData->VideoDesc.Format,
                            pCreateData->pConfig);

    if (pDxvaDevice == NULL)
    {
        return E_OUTOFMEMORY;
    }

    pDxvaDevice->m_pStartBuffer = new DWORD[sizeof(R200_StartBufferArray)/sizeof(DWORD)];
    pDxvaDevice->m_pEndBuffer = new DWORD[sizeof(R200_EndBufferArray)/sizeof(DWORD)];

    if ((pDxvaDevice->m_pStartBuffer != NULL) &&
        (pDxvaDevice->m_pEndBuffer != NULL))
    {
        memcpy(pDxvaDevice->m_pStartBuffer, R200_StartBufferArray, sizeof(R200_StartBufferArray));
        memcpy(pDxvaDevice->m_pEndBuffer, R200_EndBufferArray, sizeof(R200_EndBufferArray));
        pCreateData->hDecode = (HANDLE) pDxvaDevice;
    }
    else
    {
        delete [] pDxvaDevice->m_pStartBuffer;
        pDxvaDevice->m_pStartBuffer = NULL;

        delete [] pDxvaDevice->m_pEndBuffer;
        pDxvaDevice->m_pEndBuffer = NULL;

        delete pDxvaDevice;

        return E_OUTOFMEMORY;
    }

    //
    // Create Video context
    //
    sCreateContext.NodeOrdinal = MULTI_ENGINE_NODE_VIDEO;
#ifdef DONOT_USE_VIDEO_ENGINE
    sCreateContext.NodeOrdinal = MULTI_ENGINE_NODE_3D;
#endif    
    sCreateContext.EngineAffinity = 0;
    sCreateContext.pPrivateDriverData = NULL;
    sCreateContext.PrivateDriverDataSize = 0;
    hr = m_d3dCallbacks.pfnCreateContextCb(m_hD3D, &sCreateContext);
    if (FAILED(hr))
    {
        return hr;
    }
    
    //
    // Store context info
    //
    m_sContexts[MULTI_ENGINE_NODE_VIDEO].bEnabled = TRUE;    
    m_sContexts[MULTI_ENGINE_NODE_VIDEO].hContext = sCreateContext.hContext;
    m_sContexts[MULTI_ENGINE_NODE_VIDEO].pHwCmdBuf = (PBYTE)sCreateContext.pCommandBuffer;
    m_sContexts[MULTI_ENGINE_NODE_VIDEO].pHwCmdBufAllocList = (D3DDDI_ALLOCATIONLIST*)sCreateContext.pAllocationList;

#ifndef USE_LOCK_TO_SYNC_ENGINES
    //
    // Create the sync mutex used to sync packets between the 3D and video engines
    //
    D3DDDICB_CREATESYNCHRONIZATIONOBJECT    sCreateSyncObj;

    memset(&sCreateSyncObj, 0, sizeof(sCreateSyncObj));
    sCreateSyncObj.Info.Type = D3DDDI_SYNCHRONIZATION_MUTEX;
    sCreateSyncObj.Info.SynchronizationMutex.InitialState = TRUE;

    hr = m_d3dCallbacks.pfnCreateSynchronizationObjectCb(m_hD3D, &sCreateSyncObj);
    if (FAILED(hr))
    {
        D3DDDICB_DESTROYCONTEXT     sDestroyContext;

        sDestroyContext.hContext = m_sContexts[MULTI_ENGINE_NODE_VIDEO].hContext;
        m_d3dCallbacks.pfnDestroyContextCb(m_hD3D, &sDestroyContext);
        return hr;                   
    }
    m_hEngineSyncObject = sCreateSyncObj.hSyncObject;

    // Keep a count of the number of video GPU contexts
    m_VideoContextCount++;
#endif

    return S_OK;
}

HRESULT
CD3DContext::DestroyDecodeDevice(
    HANDLE hDXVA)
{
    D3DDDICB_DESTROYCONTEXT                 sDestroyContext;
    D3DDDICB_DESTROYSYNCHRONIZATIONOBJECT   sDestroySybcObject;
    HRESULT                                 hr = reinterpret_cast<CDXVA*>(hDXVA)->Destroy();

    delete hDXVA;

#ifndef USE_LOCK_TO_SYNC_ENGINES
    
    if (--m_VideoContextCount == 0)
    {
        _ASSERT(m_hEngineSyncObject != 0);
        sDestroySybcObject.hSyncObject = m_hEngineSyncObject;
        m_d3dCallbacks.pfnDestroySynchronizationObjectCb(m_hD3D, &sDestroySybcObject);
        m_hEngineSyncObject = 0;
    }
#endif    
        
    sDestroyContext.hContext = m_sContexts[MULTI_ENGINE_NODE_VIDEO].hContext;
    m_d3dCallbacks.pfnDestroyContextCb(m_hD3D, &sDestroyContext);

    m_sContexts[MULTI_ENGINE_NODE_VIDEO].hContext = 0;
    m_sContexts[MULTI_ENGINE_NODE_VIDEO].bEnabled = FALSE;

    // As we have just destroyed the Video context no sync with 3D required so
    // mark 3D as last engine to submit
    m_LastEngineSubmit = MULTI_ENGINE_NODE_3D;

    return hr;
}

HRESULT
CD3DContext::DecodeBeginFrame(
    CONST HANDLE hDXVA)
{
    return reinterpret_cast<CDXVA*>(hDXVA)->BeginFrame(m_pR200Ctx);
}

HRESULT
CD3DContext::DecodeEndFrame(
    CONST HANDLE hDXVA)
{
    return reinterpret_cast<CDXVA*>(hDXVA)->EndFrame();
}

HRESULT
CD3DContext::DecodeSetRenderTarget(
    CONST D3DDDIARG_SETDECODERENDERTARGET* pSetRT)
{
    return reinterpret_cast<CDXVA*>(pSetRT->hDecode)->DecodeSetRenderTarget(pSetRT, m_pR200Ctx);
}

HRESULT
CD3DContext::DecodeExecute(
    CONST D3DDDIARG_DECODEEXECUTE* pExecuteData)
{   
    return reinterpret_cast<CDXVA*>(pExecuteData->hDecode)->Execute(pExecuteData);
}

HRESULT
CD3DContext::DecodeExtensionExecute(
    CONST D3DDDIARG_DECODEEXTENSIONEXECUTE* pExecuteData)
{   
    return DDERR_UNSUPPORTED;
}

CDXVA::CDXVA(CD3DContext*                   pD3DContext,
             CONST GUID*                    pGuid,
             UINT                           Width,
             UINT                           Height,
             D3DDDIFORMAT                   Format,
             DXVADDI_CONFIGPICTUREDECODE*   pConfig) :

    m_pStartBuffer(NULL),
    m_pEndBuffer(NULL),
    m_Flags(0),
    m_SurfaceWidth(0),
    m_SurfaceHeight(0),
    m_SurfacePitchY(0),
    m_SurfacePitchUV(0),
    m_SurfaceOffsetU(0),
    m_SurfaceOffsetV(0),
    m_pMBControlBuffer(NULL), 
    m_pDCTBuffer(NULL),
    m_bPictureParameters(FALSE),
    m_MaxSurfaces(0),
    m_pCommandBuffer(NULL),
    m_MaxCommandBufferEntries(0),
    m_NumCommandBufferEntries(0),
    m_pNext(NULL),
    m_pPrevious(NULL),
    m_DestBufferAllocation(0)
{
    RtlZeroMemory(m_hOutputSurfaces, sizeof(m_hOutputSurfaces));
    RtlZeroMemory(m_SurfaceOffset, sizeof(CSurfaceOffset) * MAX_VIDEO_SURFACES);
    RtlZeroMemory(&m_MBControlHeader, sizeof(DXVADDI_DECODEBUFFERDESC));
    RtlZeroMemory(&m_DCTHeader, sizeof(DXVADDI_DECODEBUFFERDESC));
    RtlZeroMemory(&m_PictureParameters, sizeof(DXVA_PictureParameters));
    RtlZeroMemory(m_DestBuffer, sizeof(DWORD) * 6);
#ifdef QUERYSTATUS
    RtlZeroMemory(m_QueryInfo, sizeof(CQueryInfo) * MAX_VIDEO_SURFACES);
#endif

    m_pD3DContext  = pD3DContext;
    m_Guid         = *pGuid;
    m_OutputWidth  = Width;
    m_OutputHeight = Height;
    m_OutputFormat = Format;
    m_LockedConfigPictureDecode = *pConfig;
}

CDXVA::~CDXVA()
{
    delete[] m_pStartBuffer;
    delete[] m_pEndBuffer;
}

HRESULT CDXVA::Destroy(VOID)
{
    return S_OK;
}

HRESULT CDXVA::DecodeSetRenderTarget(
    CONST D3DDDIARG_SETDECODERENDERTARGET* pSetRT,
    LPATID3DCNTX pR200Ctx)
{
    HRESULT hr;

    if (pSetRT->SubResourceIndex >= MAX_VIDEO_SURFACES)
    {
        return E_INVALIDARG;
    }

    if (pSetRT->SubResourceIndex > m_MaxSurfaces)
    {
        m_MaxSurfaces = pSetRT->SubResourceIndex;
    }

    hr = R200GetSurfaceOffsetInfo(pR200Ctx,
                                  (HANDLE)(DWORD_PTR)(((UINT)(DWORD_PTR)pSetRT->hRenderTarget) + pSetRT->SubResourceIndex),
                                  &m_hOutputSurfaces[pSetRT->SubResourceIndex],
                                  &m_SurfaceOffset[pSetRT->SubResourceIndex].PitchY,
                                  &m_SurfaceOffset[pSetRT->SubResourceIndex].PitchUV,
                                  &m_SurfaceOffset[pSetRT->SubResourceIndex].Width,
                                  &m_SurfaceOffset[pSetRT->SubResourceIndex].Height,
                                  &m_SurfaceOffset[pSetRT->SubResourceIndex].OffsetU,
                                  &m_SurfaceOffset[pSetRT->SubResourceIndex].OffsetV);
    if (SUCCEEDED(hr))
    {
        m_SurfaceWidth = m_SurfaceOffset[pSetRT->SubResourceIndex].Width;
        m_SurfaceHeight = m_SurfaceOffset[pSetRT->SubResourceIndex].Height;
        m_SurfacePitchY = m_SurfaceOffset[pSetRT->SubResourceIndex].PitchY;
        m_SurfacePitchUV = m_SurfaceOffset[pSetRT->SubResourceIndex].PitchUV;
        m_SurfaceOffsetU = m_SurfaceOffset[pSetRT->SubResourceIndex].OffsetU;
        m_SurfaceOffsetV = m_SurfaceOffset[pSetRT->SubResourceIndex].OffsetV;

        //
        // Patch the startup buffer
        //
        m_pStartBuffer[15] = m_SurfacePitchY / 2;
        m_pStartBuffer[27] = m_SurfacePitchY / 2 - 32;
        m_pStartBuffer[33] = m_SurfacePitchY / 2 - 32;
    }

    return hr;
}

void CDXVA::EmbedDxvaSurface(D3DResourceID ResID, D3DKMT_HANDLE hAlloc)
{
    m_pCommandBuffer[m_NumCommandBufferEntries] = PM4_PACKET3_LDDM_HANDLE(ResID);
    *((D3DKMT_HANDLE *)(&m_pCommandBuffer[m_NumCommandBufferEntries+1])) = hAlloc;
    m_NumCommandBufferEntries+=(1 + sizeof(D3DKMT_HANDLE)/sizeof(DWORD));
    return;
}

HRESULT CDXVA::BeginFrame(
    LPATID3DCNTX pR200Ctx)
{
    m_bPictureParameters = FALSE;

    return S_OK;
}

HRESULT CDXVA::EndFrame(
    VOID)
{
    m_bPictureParameters = FALSE;

    return S_OK;
}

HRESULT CDXVA::Execute(
    CONST D3DDDIARG_DECODEEXECUTE* pExecuteData)
{
    UINT                    i;
    WORD                    PicIndex;
    D3DDDIARG_LOCK          Lock = {0};
    D3DDDIARG_UNLOCK        Unlock = {0};
    BOOL                    bMBControlBuffer = FALSE;
    BOOL                    bDCTBuffer = FALSE;

#ifndef _WIN64
    // some decoder has the mmx operations which may affect the floating point operation
    _asm{
        emms
    }
#endif

    for (i = 0; i < pExecuteData->NumCompBuffers; i++)
    {
        if (pExecuteData->pCompressedBuffers[i].CompressedBufferType == D3DDDIFMT_PICTUREPARAMSDATA)
        {
            break;
        }
    }

    if (i < pExecuteData->NumCompBuffers)
    {
        DXVADDI_DECODEBUFFERDESC* pPicParamsHeader = &pExecuteData->pCompressedBuffers[i];

        Lock.hResource = pPicParamsHeader->hBuffer;
        Lock.SubResourceIndex = 0;
        if (m_pD3DContext->Lock(&Lock) == S_OK)
        {
            m_PictureParameters = *(DXVA_PictureParameters*) Lock.pSurfData;
            m_bPictureParameters = TRUE;

            Unlock.hResource = pPicParamsHeader->hBuffer;
            Unlock.SubResourceIndex = 0;
            m_pD3DContext->Unlock(&Unlock);
        }
        else
        {
            return E_INVALIDARG;
        }
    }

    if (m_bPictureParameters)
    {
        PicIndex = m_PictureParameters.wDecodedPictureIndex;

        if (m_PictureParameters.bPicStructure == 0x2) // bottom field picture
        {
            m_DestBuffer[0] = m_SurfaceOffset[PicIndex].PitchY;
            m_DestBuffer[1] = m_SurfaceOffset[PicIndex].PitchY;
            m_DestBuffer[2] = m_SurfaceOffset[PicIndex].OffsetU + m_SurfaceOffset[PicIndex].PitchUV;
            m_DestBuffer[3] = m_SurfaceOffset[PicIndex].OffsetU + m_SurfaceOffset[PicIndex].PitchUV;
            m_DestBuffer[4] = m_SurfaceOffset[PicIndex].OffsetV + m_SurfaceOffset[PicIndex].PitchUV;
            m_DestBuffer[5] = m_SurfaceOffset[PicIndex].OffsetV + m_SurfaceOffset[PicIndex].PitchUV;
        }
        else
        {
            m_DestBuffer[0] = 0;
            m_DestBuffer[1] = m_SurfaceOffset[PicIndex].PitchY;
            m_DestBuffer[2] = m_SurfaceOffset[PicIndex].OffsetU;
            m_DestBuffer[3] = m_SurfaceOffset[PicIndex].OffsetU + m_SurfaceOffset[PicIndex].PitchUV;
            m_DestBuffer[4] = m_SurfaceOffset[PicIndex].OffsetV;
            m_DestBuffer[5] = m_SurfaceOffset[PicIndex].OffsetV + m_SurfaceOffset[PicIndex].PitchUV;
        }

        m_DestBufferAllocation = m_hOutputSurfaces[PicIndex];
    }

    for (i = 0; i < pExecuteData->NumCompBuffers; i++)
    {
        if (pExecuteData->pCompressedBuffers[i].CompressedBufferType == D3DDDIFMT_MACROBLOCKDATA)
        {
            break;
        }
    }

    if (i < pExecuteData->NumCompBuffers)
    {
        m_MBControlHeader = pExecuteData->pCompressedBuffers[i];
        Lock.hResource = m_MBControlHeader.hBuffer;
        Lock.SubResourceIndex = 0;
        if (m_pD3DContext->Lock(&Lock) == S_OK)
        {
            m_pMBControlBuffer = Lock.pSurfData;
            bMBControlBuffer = TRUE;

            Unlock.hResource = m_MBControlHeader.hBuffer;
            Unlock.SubResourceIndex = 0;
            m_pD3DContext->Unlock(&Unlock);
        }
        else
        {
            return E_INVALIDARG;
        }
    }

    for (i = 0; i < pExecuteData->NumCompBuffers; i++)
    {
        if (pExecuteData->pCompressedBuffers[i].CompressedBufferType == D3DDDIFMT_RESIDUALDIFFERENCEDATA)
        {
            break;
        }
    }

    if (i < pExecuteData->NumCompBuffers)
    {
        m_DCTHeader = pExecuteData->pCompressedBuffers[i];
        Lock.hResource = m_DCTHeader.hBuffer;
        Lock.SubResourceIndex = 0;
        if (m_pD3DContext->Lock(&Lock) == S_OK)
        {
            m_pDCTBuffer = Lock.pSurfData; 
            bDCTBuffer = TRUE;

            Unlock.hResource = m_DCTHeader.hBuffer;
            Unlock.SubResourceIndex = 0;
            m_pD3DContext->Unlock(&Unlock);
        }
        else
        {
            return E_INVALIDARG;
        }
    }

    if (!m_bPictureParameters || ValidatePictureParameters() != 0)
    {
        return E_INVALIDARG;
    }

    if (bMBControlBuffer && bDCTBuffer)
    {
        // The DXVA commands should not be mixed with the D3D commands.  The D3D 
        // commands live in the DP2 buffer as DP2 tokens and are then converted to
        // hw commands when Flush is called, but we want to generate the hw commands
        // directly into the hw buffer (bypassing the DP2 buffer).

        m_pCommandBuffer = (DWORD*) m_pD3DContext->GetDXVABuffer(&m_MaxCommandBufferEntries);

        ConstructIDCTBuffer();

#ifdef CAPTURE_DXVA_BUFFERS 
        CopyBufferContents(gBuffCount++, m_pCommandBuffer, m_NumCommandBufferEntries);
#endif

        m_pD3DContext->SubmitDXVABuffer(m_NumCommandBufferEntries * sizeof(DWORD));
    }

    return S_OK;
}

VOID CDXVA::InitCommandBuffer(CSurfaceOffset* pSurfOffset,
                              WORD wForwardRefIndex,
                              WORD wBackwardRefIndex,
                              WORD wDecodedRefIndex,
                              BYTE bPicStructure,
                              BYTE bSecondField,
                              BYTE bPicBackwardPrediction)
{
    memcpy(m_pCommandBuffer, m_pStartBuffer, sizeof(R200_StartBufferArray));
    m_NumCommandBufferEntries = sizeof(R200_StartBufferArray) / 4;

    if (wForwardRefIndex == 0xffff)
    {
        wForwardRefIndex = wDecodedRefIndex;
    }
    if (wBackwardRefIndex == 0xffff)
    {
        wBackwardRefIndex = wForwardRefIndex;
    }

    if (bSecondField && (bPicBackwardPrediction==0 ) )
    {
        if (bPicStructure == 0x2)
        {
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_Y0, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_PITCH_Y0, m_hOutputSurfaces[wForwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U0, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U0_PITCH_UV, m_hOutputSurfaces[wForwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V0, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V0_PITCH_UV, m_hOutputSurfaces[wForwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_Y1, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_PITCH_Y1, m_hOutputSurfaces[wBackwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U1, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U1_PITCH_UV, m_hOutputSurfaces[wBackwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V1, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V1_PITCH_UV, m_hOutputSurfaces[wBackwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_Y2, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_PITCH_Y2, m_hOutputSurfaces[wForwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U2, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U2_PITCH_UV, m_hOutputSurfaces[wForwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V2, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V2_PITCH_UV, m_hOutputSurfaces[wForwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_DEST_ALLOCATION, m_DestBufferAllocation);
                
            // bottom-field picture => top-field already decoded
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_0;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = 0;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_1;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].PitchY;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_2;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wDecodedRefIndex].OffsetU;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_3;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetU + pSurfOffset[wForwardRefIndex].PitchUV;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_4;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wDecodedRefIndex].OffsetV;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_5;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetV + pSurfOffset[wForwardRefIndex].PitchUV;
    
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_6;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = 0;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_7;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wBackwardRefIndex].PitchY;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_8;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wDecodedRefIndex].OffsetU;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_9;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wBackwardRefIndex].OffsetU + pSurfOffset[wBackwardRefIndex].PitchUV;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_10;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wDecodedRefIndex].OffsetV;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_11;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wBackwardRefIndex].OffsetV + pSurfOffset[wBackwardRefIndex].PitchUV;

            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_12;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = 0;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_13;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].PitchY;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_14;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wDecodedRefIndex].OffsetU;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_15;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetU + pSurfOffset[wForwardRefIndex].PitchUV;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_16;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wDecodedRefIndex].OffsetV;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_17;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetV + pSurfOffset[wForwardRefIndex].PitchUV;

            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmDST_PITCH;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = (pSurfOffset[wBackwardRefIndex].PitchY / 2) >> PITCH_SH;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmSE_MC_SRC1_CNTL;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = SE_MC_SRC1_CNTL__MC_IDCT_ENB;
            return;
        }
        else
        {
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_Y0, m_hOutputSurfaces[wForwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_PITCH_Y0, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U0, m_hOutputSurfaces[wForwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U0_PITCH_UV, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V0, m_hOutputSurfaces[wForwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V0_PITCH_UV, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_Y1, m_hOutputSurfaces[wBackwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_PITCH_Y1, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U1, m_hOutputSurfaces[wBackwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U1_PITCH_UV, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V1, m_hOutputSurfaces[wBackwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V1_PITCH_UV, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_Y2, m_hOutputSurfaces[wForwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_PITCH_Y2, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U2, m_hOutputSurfaces[wForwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U2_PITCH_UV, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V2, m_hOutputSurfaces[wForwardRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V2_PITCH_UV, m_hOutputSurfaces[wDecodedRefIndex]);
            EmbedDxvaSurface(D3D_RES_DXVA_DEST_ALLOCATION, m_DestBufferAllocation);

            // top-field picture => bottom-field already decoded
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_0;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = 0;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_1;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wDecodedRefIndex].PitchY;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_2;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetU;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_3;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wDecodedRefIndex].OffsetU + pSurfOffset[wDecodedRefIndex].PitchUV;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_4;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetV;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_5;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wDecodedRefIndex].OffsetV + pSurfOffset[wDecodedRefIndex].PitchUV;
    
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_6;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = 0;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_7;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wDecodedRefIndex].PitchY;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_8;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wBackwardRefIndex].OffsetU;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_9;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wDecodedRefIndex].OffsetU + pSurfOffset[wDecodedRefIndex].PitchUV;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_10;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wBackwardRefIndex].OffsetV;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_11;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wDecodedRefIndex].OffsetV + pSurfOffset[wDecodedRefIndex].PitchUV;

            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_12;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = 0;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_13;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wDecodedRefIndex].PitchY;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_14;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetU;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_15;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wDecodedRefIndex].OffsetU + pSurfOffset[wDecodedRefIndex].PitchUV;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_16;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetV;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_17;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wDecodedRefIndex].OffsetV + pSurfOffset[wDecodedRefIndex].PitchUV;

            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmDST_PITCH;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = (pSurfOffset[wBackwardRefIndex].PitchY / 2) >> PITCH_SH;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = mmSE_MC_SRC1_CNTL;
            m_pCommandBuffer[m_NumCommandBufferEntries++] = SE_MC_SRC1_CNTL__MC_IDCT_ENB;
            return;
        }
    }
    
    // The following entries need to be patched so create entries in the patch table
    EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_Y0, m_hOutputSurfaces[wForwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_PITCH_Y0, m_hOutputSurfaces[wForwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U0, m_hOutputSurfaces[wForwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U0_PITCH_UV, m_hOutputSurfaces[wForwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V0, m_hOutputSurfaces[wForwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V0_PITCH_UV, m_hOutputSurfaces[wForwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_Y1, m_hOutputSurfaces[wBackwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_PITCH_Y1, m_hOutputSurfaces[wBackwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U1, m_hOutputSurfaces[wBackwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U1_PITCH_UV, m_hOutputSurfaces[wBackwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V1, m_hOutputSurfaces[wBackwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V1_PITCH_UV, m_hOutputSurfaces[wBackwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_Y2, m_hOutputSurfaces[wForwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_PITCH_Y2, m_hOutputSurfaces[wForwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U2, m_hOutputSurfaces[wForwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_U2_PITCH_UV, m_hOutputSurfaces[wForwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V2, m_hOutputSurfaces[wForwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_OFFSET_V2_PITCH_UV, m_hOutputSurfaces[wForwardRefIndex]);
    EmbedDxvaSurface(D3D_RES_DXVA_DEST_ALLOCATION, m_DestBufferAllocation);

    // Now write the registers and their values, most of which will get patched later
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_0;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = 0;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_1;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].PitchY;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_2;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetU;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_3;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetU + pSurfOffset[wForwardRefIndex].PitchUV;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_4;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetV;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_5;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetV + pSurfOffset[wForwardRefIndex].PitchUV;
    
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_6;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = 0;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_7;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wBackwardRefIndex].PitchY;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_8;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wBackwardRefIndex].OffsetU;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_9;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wBackwardRefIndex].OffsetU + pSurfOffset[wBackwardRefIndex].PitchUV;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_10;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wBackwardRefIndex].OffsetV;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_11;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wBackwardRefIndex].OffsetV + pSurfOffset[wBackwardRefIndex].PitchUV;

    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_12;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = 0;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_13;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].PitchY;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_14;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetU;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_15;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetU + pSurfOffset[wForwardRefIndex].PitchUV;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_16;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetV;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmPP_SRC_OFFSET_17;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = pSurfOffset[wForwardRefIndex].OffsetV + pSurfOffset[wForwardRefIndex].PitchUV;

    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmDST_PITCH;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = (pSurfOffset[wBackwardRefIndex].PitchY / 2) >> PITCH_SH;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = mmSE_MC_SRC1_CNTL;
    m_pCommandBuffer[m_NumCommandBufferEntries++] = SE_MC_SRC1_CNTL__MC_IDCT_ENB;
}


VOID CDXVA::ConstructIDCTBuffer(VOID)
{
    LPDWORD pdwBufferCurrent;

    DWORD MBCounter;
    DWORD NumberOfMB;
    DXVA_MBctrl_I_OffHostIDCT_1 *pMBctrl_I;
    DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P;
    LPDXVA_TCoef4Group pTCoef;
    DWORD Size = 0;
    int SkippedMB = 0;

    // pBufferHeader = m_MBControlHeader
    NumberOfMB =  m_MBControlHeader.NumMBsInBuffer;

    if (m_PictureParameters.bPicIntra)
    {
        InitCommandBuffer(m_SurfaceOffset,
                          m_PictureParameters.wDecodedPictureIndex,
                          m_PictureParameters.wDecodedPictureIndex,
                          m_PictureParameters.wDecodedPictureIndex,
                          m_PictureParameters.bPicStructure,
                          m_PictureParameters.bSecondField,
                          m_PictureParameters.bPicBackwardPrediction);

        pMBctrl_I = (DXVA_MBctrl_I_OffHostIDCT_1 *) m_pMBControlBuffer;
        pTCoef = (LPDXVA_TCoef4Group) m_pDCTBuffer;
        MBCounter = 0; 

        while (MBCounter < NumberOfMB)  //; MBCounter++, pMBctrl_I++)
        {
            if ((readDXVA_MBdataLocation(pMBctrl_I) << 2) > m_DCTHeader.DataSize)
            {
                // invalid macroblock control data
                return;
            }

            Size = R128IDCT_ParseIntraMacroBlock(
                                           &m_pCommandBuffer[m_NumCommandBufferEntries],
                                           (DWORD*) &m_DestBuffer,
                                           &m_PictureParameters,
                                           (DXVA_MBctrl_P_OffHostIDCT_1 *)pMBctrl_I, 
                                           pTCoef,
                                           FALSE);

            m_NumCommandBufferEntries += Size;
            MBCounter++; 
            pMBctrl_I++;

            if (m_NumCommandBufferEntries > (m_MaxCommandBufferEntries - END_BUFFER_PADDING))
            {
                // Have to submit it now
                m_NumCommandBufferEntries += R128IDCT_WriteBufferEnd(&m_pCommandBuffer[m_NumCommandBufferEntries]);
                memcpy(&m_pCommandBuffer[m_NumCommandBufferEntries], m_pEndBuffer, sizeof(R200_EndBufferArray));
                m_NumCommandBufferEntries += sizeof(R200_EndBufferArray) / sizeof(DWORD);

#ifdef CAPTURE_DXVA_BUFFERS 
                CopyBufferContents(gBuffCount++, m_pCommandBuffer, m_NumCommandBufferEntries);
#endif

                if (m_NumCommandBufferEntries > m_MaxCommandBufferEntries)
                {
                    DebugBreak();
                }

                m_pD3DContext->SubmitDXVABuffer(m_NumCommandBufferEntries * sizeof(DWORD));

                m_NumCommandBufferEntries = 0;

                InitCommandBuffer(m_SurfaceOffset,
                                m_PictureParameters.wDecodedPictureIndex,
                                m_PictureParameters.wDecodedPictureIndex,
                                m_PictureParameters.wDecodedPictureIndex,
                                m_PictureParameters.bPicStructure,
                                m_PictureParameters.bSecondField,
                                m_PictureParameters.bPicBackwardPrediction);
            }
        }
    }
    else
    {
        InitCommandBuffer(m_SurfaceOffset,
                          m_PictureParameters.wForwardRefPictureIndex,
                          m_PictureParameters.wBackwardRefPictureIndex,
                          m_PictureParameters.wDecodedPictureIndex,
                          m_PictureParameters.bPicStructure,
                          m_PictureParameters.bSecondField,
                          m_PictureParameters.bPicBackwardPrediction);
    
        pMBctrl_P = (DXVA_MBctrl_P_OffHostIDCT_1 *)m_pMBControlBuffer;
        pTCoef = (LPDXVA_TCoef4Group) m_pDCTBuffer;
        MBCounter = 0;

        while (MBCounter < NumberOfMB) //; dwMBCounter++)
        {
            if ((readDXVA_MBdataLocation((DXVA_MBctrl_I_OffHostIDCT_1 *)pMBctrl_P) << 2) > m_DCTHeader.DataSize)
            {
                // invalid macroblock control data
                return;
            }

            if (readDXVA_IntraMacroblock(pMBctrl_P))
            {
                Size = R128IDCT_ParseIntraMacroBlock(
                                            &m_pCommandBuffer[m_NumCommandBufferEntries],
                                            (DWORD*) &m_DestBuffer,
                                            &m_PictureParameters,
                                            pMBctrl_P, 
                                            pTCoef,
                                            FALSE);
            }
            else
            {
                Size = R128IDCT_ParseNonIntraMacroBlock(
                                            &m_pCommandBuffer[m_NumCommandBufferEntries],
                                            (DWORD*) &m_DestBuffer,
                                            &m_PictureParameters,
                                            pMBctrl_P, 
                                            pTCoef);
                if (MBCounter == 0)
                {
                    SkippedMB = readDXVA_MBskipsFollowing(pMBctrl_P);
                }
            }

            m_NumCommandBufferEntries += Size;
            MBCounter++;

            if (SkippedMB)
            {
                pMBctrl_P->wMBaddress++;
                SkippedMB--;
            }
            else
            {
                pMBctrl_P++;
                SkippedMB = readDXVA_MBskipsFollowing(pMBctrl_P);
            }

            if (m_NumCommandBufferEntries > (m_MaxCommandBufferEntries - END_BUFFER_PADDING))
            {
                // Have to submit it now
                m_NumCommandBufferEntries += R128IDCT_WriteBufferEnd(&m_pCommandBuffer[m_NumCommandBufferEntries]);
                memcpy(&m_pCommandBuffer[m_NumCommandBufferEntries], m_pEndBuffer, sizeof(R200_EndBufferArray));
                m_NumCommandBufferEntries += sizeof(R200_EndBufferArray) / sizeof(DWORD);

#ifdef CAPTURE_DXVA_BUFFERS 
                CopyBufferContents(gBuffCount++, m_pCommandBuffer, m_NumCommandBufferEntries);
#endif

                if (m_NumCommandBufferEntries > m_MaxCommandBufferEntries)
                {
                    DebugBreak();
                }

                m_pD3DContext->SubmitDXVABuffer(m_NumCommandBufferEntries * sizeof(DWORD));

                m_NumCommandBufferEntries = 0;

                InitCommandBuffer(m_SurfaceOffset,
                                m_PictureParameters.wForwardRefPictureIndex,
                                m_PictureParameters.wBackwardRefPictureIndex,
                                m_PictureParameters.wDecodedPictureIndex,
                                m_PictureParameters.bPicStructure,
                                m_PictureParameters.bSecondField,
                                m_PictureParameters.bPicBackwardPrediction);
            }
        }
    }

    m_NumCommandBufferEntries += R128IDCT_WriteBufferEnd(&m_pCommandBuffer[m_NumCommandBufferEntries]);
    memcpy(&m_pCommandBuffer[m_NumCommandBufferEntries], m_pEndBuffer, sizeof(R200_EndBufferArray));
    m_NumCommandBufferEntries += sizeof(R200_EndBufferArray) / sizeof(DWORD);
} 

UINT CDXVA::ValidatePictureParameters()
{
    //this function returns 0 (no error) or error number(Parameter index from 0x01 to 0x24).

    //check wDecodedPictureIndex
    if (m_PictureParameters.wDecodedPictureIndex > m_MaxSurfaces)
    {
        return 0x01;
    }

    //check wPicWidthInMBminus1
    if (m_PictureParameters.wPicWidthInMBminus1 >= (m_SurfaceWidth+15)>>4)
    {
        return 0x05;
    }

    //check wPicHeightInMBminus1
    if (m_PictureParameters.wPicHeightInMBminus1 >= (m_SurfaceHeight+15)>>4)
    {
        return 0x06;
    }

    //bPicDeblocked
    if ((m_PictureParameters.bPicDeblocked & 0xFE) != 0)
    {
        return 0x1a;
    }
    else 
    {
        //wDeblockedPictureIndex
        if ((m_PictureParameters.bPicDeblocked == 1) &&
            (m_PictureParameters.wDeblockedPictureIndex > m_MaxSurfaces))
        {
            return 0x02;
        }
    }

    if (m_PictureParameters.bBPPminus1 != 7)
    {
        return 0x0b;
    }

    //bPicIntra
    if (m_PictureParameters.bPicIntra == 1)
    {
        //bPicSpatialResid8 = 1
        if ((m_LockedConfigPictureDecode.ConfigResidDiffHost == 1) &&
            (m_PictureParameters.bPicSpatialResid8 != 1))
        {
            return 0x17;
        }

        //bPicOverflowBlocks = 0
        if (m_PictureParameters.bPicOverflowBlocks != 0)
        {
            return 0x18;
        }
    }
    else if (m_PictureParameters.bPicIntra == 0)
    {
        if (m_PictureParameters.bSecondField == 0)
        {
            //wForwardRefPictureIndex != wDecodedPictureIndex
            if ((m_PictureParameters.wForwardRefPictureIndex > m_MaxSurfaces) ||
                (m_PictureParameters.wForwardRefPictureIndex == m_PictureParameters.wDecodedPictureIndex))
            {
                return 0x03;
            }

            //wBackwardRefPictureIndex != wDecodedPictureIndex
            if ((m_PictureParameters.bPicBackwardPrediction == 1) &&
                ((m_PictureParameters.wBackwardRefPictureIndex > m_MaxSurfaces) ||
                    (m_PictureParameters.wBackwardRefPictureIndex == m_PictureParameters.wDecodedPictureIndex)))
            {
                return 0x04;
            }
        }
    }
    else //bPicIntra
    {
        return 0x0e;
    }

    //bMacroblockWidthMinus1
    if (m_PictureParameters.bMacroblockWidthMinus1 != 15)
    {
        return 0x07;
    }

    //bMacroblockHeightMinus1
    if (m_PictureParameters.bMacroblockHeightMinus1 != 15)
    {
        return 0x08;
    }

    //bBlockWidthMinus1 == 7
    if (m_PictureParameters.bBlockWidthMinus1 != 7)
    {
        return 0x09;
    }

    //bBlockHeightMinus1 == 7
    if (m_PictureParameters.bBlockHeightMinus1 != 7)
    {
        return 0x0a;
    }

    //bChromaFormat
    if ((m_PictureParameters.bChromaFormat & 0xFC) != 0)
    {
        return 0x12;
    }
    else 
    {
        //bConfig4GroupedCoefs
        if (m_LockedConfigPictureDecode.Config4GroupedCoefs == 1)
        {
            //bChromaFormat == 01
            if (m_PictureParameters.bChromaFormat != 1)
            {
                return 0x12;
            }
        }
    }

    //bPicScanFixed
    if (m_PictureParameters.bPicScanFixed == 1)
    {
        if (m_LockedConfigPictureDecode.ConfigHostInverseScan == 0)//bPicScanMethod 
        {
            if ((m_PictureParameters.bPicScanMethod & 0xFE) != 0)
            {
                return 0x14;
            }
        }
        else if(m_LockedConfigPictureDecode.ConfigHostInverseScan == 1)//bPicScanMethod 
        {
            if (m_PictureParameters.bPicScanMethod != 0x03)
            {
                return 0x14;
            }
        }
    }
    else if (m_PictureParameters.bPicScanFixed == 0)
    {
        if ((m_LockedConfigPictureDecode.ConfigHostInverseScan == 1) || 
            (m_LockedConfigPictureDecode.ConfigResidDiffAccelerator == 0))//bPicScanFixed should be 1 
        {
            return 0x13;
        }
    }
    else 
    {
        return 0x13;
    }

    //bPicSpatialResid8
    if (m_PictureParameters.bPicSpatialResid8 == 1)
    {
        if ((m_LockedConfigPictureDecode.ConfigResidDiffHost == 0) ||
            (m_PictureParameters.bBPPminus1 > 7))
        {
            return 0x17;
        }
    }
    else if (m_PictureParameters.bPicSpatialResid8 == 0)
    {
        //bPicSpatialResid8 shall be 1
        if (m_LockedConfigPictureDecode.ConfigSpatialResid8 == 1)
        {
            return 0x17;
        }
    }
    else 
    {
        return 0x17;
    }

    //bPicOverflowBlocks 
    if ((m_PictureParameters.bPicOverflowBlocks & 0xFE) != 0)
    {
        return 0x18;
    }
    else if (m_PictureParameters.bPicOverflowBlocks == 1)
    {
        if ((m_LockedConfigPictureDecode.ConfigResidDiffHost == 0) ||
            (m_LockedConfigPictureDecode.ConfigSpatialResid8 == 0) ||
            (m_PictureParameters.bBPPminus1 > 7))
        {
            return 0x18;
        }
    }

    return 0;
}
 
#ifdef QUERYSTATUS
BOOL CDXVA::QueryStatus(HANDLE hResource)
{
    UINT i;

    for (i = 0; i < m_MaxSurfaces; i++)
    {
        if ((m_QueryInfo[i].hMBBuffer == hResource) ||
            (m_QueryInfo[i].hDCTBuffer == hResource) ||
            (m_QueryInfo[i].hOutput == hResource))
        {
            if (m_QueryInfo[i].Status != 0)
            {
                VOID*   pData;
                HRESULT hr;

                hr = m_pD3DContext->LockAllocationCB(m_hOutputSurfaces[i], 
                                                     DDLOCK_DONOTWAIT,
                                                     FALSE,
                                                     &pData);
                if (SUCCEEDED(hr))
                {
                    m_QueryInfo[i].Status = 0;

                    m_pD3DContext->UnlockAllocationCB(m_hOutputSurfaces[i]);
                }
                else
                {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}
#endif

#ifdef CAPTURE_DXVA_BUFFERS 
#include <stdio.h>

VOID CopyBufferContents(UINT Frame, DWORD* pBuffer, UINT BufferSize)
{
    char szName[100];
    FILE* hFile;
    UINT i;

    sprintf(szName, "c:\\Buffer%d.txt", Frame);      
    hFile = fopen(szName,"at");

    if (hFile != NULL)
    {
        for (i = 0; i < BufferSize; i++)
        {
            fprintf(hFile,"%08x\n", pBuffer[i]);
        }
        
        fclose(hFile);
    }
}
#endif

HRESULT
CD3DContext::CreateVideoProcessDevice(
    D3DDDIARG_CREATEVIDEOPROCESSDEVICE* pCreateData)
{
    pCreateData->hVideoProcess = (HANDLE) new CVIDPROCESS(this,
                                                 pCreateData->pVideoProcGuid,
                                                 pCreateData->VideoDesc.SampleWidth,
                                                 pCreateData->VideoDesc.SampleHeight,
                                                 pCreateData->VideoDesc.Format);
    if (pCreateData->hVideoProcess == NULL)
    {
        return E_OUTOFMEMORY;
    }

    return S_OK;
}

HRESULT
CD3DContext::DestroyVideoProcessDevice(
    HANDLE hVideoProcess)
{
    HRESULT hr = reinterpret_cast<CVIDPROCESS*>(hVideoProcess)->Destroy();

    delete hVideoProcess;

    return hr;
}

HRESULT
CD3DContext::VideoProcessBeginFrame(
    CONST HANDLE hVideoProcess)
{
    return reinterpret_cast<CVIDPROCESS*>(hVideoProcess)->BeginFrame(m_pR200Ctx);
}

HRESULT
CD3DContext::VideoProcessEndFrame(
    CONST HANDLE hVideoProcess)
{
    return reinterpret_cast<CVIDPROCESS*>(hVideoProcess)->EndFrame();
}

HRESULT
CD3DContext::VideoProcessSetRenderTarget(
    CONST D3DDDIARG_SETVIDEOPROCESSRENDERTARGET* pSetRT)
{
    return reinterpret_cast<CVIDPROCESS*>(pSetRT->hVideoProcess)->SetRenderTarget(pSetRT, m_pR200Ctx);
}

HRESULT
CD3DContext::VideoProcessBlt(
    CONST D3DDDIARG_VIDEOPROCESSBLT* pBlt)
{   
    return reinterpret_cast<CVIDPROCESS*>(pBlt->hVideoProcess)->Blt(pBlt);
}

CVIDPROCESS::CVIDPROCESS(CD3DContext*                   pD3DContext,
                         CONST GUID*                    pGuid,
                         UINT                           Width,
                         UINT                           Height,
                         D3DDDIFORMAT                   Format)
{
    _ASSERT(pGuid != NULL);

    m_pD3DContext  = pD3DContext;
    m_Guid         = *pGuid;
    m_OutputWidth  = Width;
    m_OutputHeight = Height;
    m_OutputFormat = Format;
}

CVIDPROCESS::~CVIDPROCESS()
{
}

HRESULT CVIDPROCESS::Destroy(VOID)
{
    return S_OK;
}

HRESULT CVIDPROCESS::SetRenderTarget(
    CONST D3DDDIARG_SETVIDEOPROCESSRENDERTARGET* pSetRT,
    LPATID3DCNTX pR200Ctx)
{
    m_RenderTargetResource = pSetRT->hRenderTarget;
    m_RenderTargetIndex = pSetRT->SubResourceIndex;
    return S_OK;
}

HRESULT CVIDPROCESS::BeginFrame(
    LPATID3DCNTX pR200Ctx)
{
    return S_OK;
}

HRESULT CVIDPROCESS::EndFrame(
    VOID)
{
    return S_OK;
}

HRESULT CVIDPROCESS::Blt(
    CONST D3DDDIARG_VIDEOPROCESSBLT* pBlt)
{
    D3DDDIARG_BLT Blt = {0};
    HRESULT hr;

    Blt.hSrcResource = pBlt->pSrcSurfaces->SrcResource;
    Blt.SrcSubResourceIndex = pBlt->pSrcSurfaces->SrcSubResourceIndex;

    Blt.SrcRect.left = pBlt->pSrcSurfaces->SrcRect.left;
    Blt.SrcRect.right = pBlt->pSrcSurfaces->SrcRect.right;
    Blt.SrcRect.top = pBlt->pSrcSurfaces->SrcRect.top;
    Blt.SrcRect.bottom = pBlt->pSrcSurfaces->SrcRect.bottom;

    Blt.DstRect.left = pBlt->TargetRect.left;
    Blt.DstRect.right = pBlt->TargetRect.right;
    Blt.DstRect.top = pBlt->TargetRect.top;
    Blt.DstRect.bottom = pBlt->TargetRect.bottom;

    Blt.hDstResource = m_RenderTargetResource;
    Blt.DstSubResourceIndex = m_RenderTargetIndex;
    Blt.ColorKey = 0;

    hr = m_pD3DContext->Blt(&Blt);

    return hr;
}


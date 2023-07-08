/******************************Module*Header**********************************\
*
*                           *******************
*                           * D3D SAMPLE CODE *
*                           *******************
*

* Copyright (c) 2003 Microsoft Corporation.  All rights reserved.
\*****************************************************************************/

#ifndef DXVA_INCLUDED
#define DXVA_INCLUDED

#include <dxva.h>
#include "d3dumode.hpp"

#define MAX_VIDEO_SURFACES          32

struct CSurfaceOffset
{
    DWORD       PitchY;
    DWORD       PitchUV;
    DWORD       Width;
    DWORD       Height;
    DWORD       OffsetU;
    DWORD       OffsetV;
};

class CDXVA
{
public:
    CDXVA(
        CD3DContext*                   pD3DContext,
        CONST GUID*                    pGuid,
        UINT                           Width,
        UINT                           Height,
        D3DDDIFORMAT                   Format,
        DXVADDI_CONFIGPICTUREDECODE*   pConfig);
    ~CDXVA();

    HRESULT Destroy(VOID);
    HRESULT DecodeSetRenderTarget(CONST D3DDDIARG_SETDECODERENDERTARGET* pSetRT, LPATID3DCNTX pR200Ctx);    
    HRESULT BeginFrame(LPATID3DCNTX pR200Ctx);
    HRESULT Execute(CONST D3DDDIARG_DECODEEXECUTE* pExecuteData);
    HRESULT EndFrame(VOID);
    void    EmbedDxvaSurface(D3DResourceID ResID, D3DKMT_HANDLE hAlloc);

    DWORD*                        m_pStartBuffer;
    DWORD*                        m_pEndBuffer;

private:
    CD3DContext*                  m_pD3DContext;
    GUID                          m_Guid;
    UINT                          m_OutputWidth;
    UINT                          m_OutputHeight;
    UINT                          m_Flags;
    D3DDDIFORMAT                  m_OutputFormat;
    DXVADDI_CONFIGPICTUREDECODE   m_LockedConfigPictureDecode;
    D3DKMT_HANDLE                 m_hOutputSurfaces[MAX_VIDEO_SURFACES];
    CSurfaceOffset                m_SurfaceOffset[MAX_VIDEO_SURFACES];
    UINT                          m_SurfaceWidth;
    UINT                          m_SurfaceHeight;
    UINT                          m_SurfacePitchY;
    UINT                          m_SurfacePitchUV;
    UINT                          m_SurfaceOffsetU;
    UINT                          m_SurfaceOffsetV;
    DWORD                         m_DestBuffer[6];
    D3DKMT_HANDLE                 m_DestBufferAllocation;
    DXVADDI_DECODEBUFFERDESC      m_MBControlHeader;
    DXVADDI_DECODEBUFFERDESC      m_DCTHeader;
    VOID*                         m_pMBControlBuffer; 
    VOID*                         m_pDCTBuffer;    
    DXVA_PictureParameters        m_PictureParameters;
    BOOL                          m_bPictureParameters;
    UINT                          m_MaxSurfaces;
    DWORD*                        m_pCommandBuffer;
    DWORD                         m_MaxCommandBufferEntries;
    DWORD                         m_NumCommandBufferEntries;

    CDXVA*                        m_pNext;
    CDXVA*                        m_pPrevious;

    UINT ValidatePictureParameters(void);
    VOID ConstructIDCTBuffer(void);
    VOID InitCommandBuffer(CSurfaceOffset* pSurfOffset,
                           WORD wForwardRefIndex,
                           WORD wBackwardRefIndex,
                           WORD wDecodedRefIndex,
                           BYTE bPicStructure,
                           BYTE bSecondField,
                           BYTE bPicBackwardPrediction);
};

#define DXVA_CONFIG_LOCKED      0x00000001
#define DXVA_MBCONTROL          0x00000002
#define DXVA_DCTDATA            0x00000004

class CVIDPROCESS
{
public:
    CVIDPROCESS(
        CD3DContext*                   pD3DContext,
        CONST GUID*                    pGuid,
        UINT                           Width,
        UINT                           Height,
        D3DDDIFORMAT                   Format);
    ~CVIDPROCESS();

    HRESULT Destroy(VOID);
    HRESULT SetRenderTarget(CONST D3DDDIARG_SETVIDEOPROCESSRENDERTARGET* pSetRT, LPATID3DCNTX pR200Ctx);
    HRESULT BeginFrame(LPATID3DCNTX pR200Ctx);
    HRESULT Blt(CONST D3DDDIARG_VIDEOPROCESSBLT* pExecuteData);
    HRESULT EndFrame(VOID);

private:
    CD3DContext*                  m_pD3DContext;
    GUID                          m_Guid;
    UINT                          m_OutputWidth;
    UINT                          m_OutputHeight;
    D3DDDIFORMAT                  m_OutputFormat;

    HANDLE                        m_RenderTargetResource;
    UINT                          m_RenderTargetIndex;
};

#endif


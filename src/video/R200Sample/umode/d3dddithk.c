/*****************************************************************************\
*
*                           *******************
*                           * D3D SAMPLE CODE *
*                           *******************
*
* Copyright (c) 2003 Microsoft Corporation.  All rights reserved.
\*****************************************************************************/

#include <DriverSpecs.h>

__user_driver

#include "atid3ddefs.h"
#include "atidispdd.h"
#include "atidxobj.h"
#include "d3dtext.h"
#include "d3ddevice.h"
#include "vertexbuffer.h"
#include "ativbinfo.h"
#include "misc2cbdx7.h"
#include "atisurf.h"

#include <d3dumddi.h>

#include "r2d3dddi.h"
#include "d3dddithk.h"
#include "writerendstate.h"
#include "debug.h"
#include "contextthk.h"

DWORD
GetExHandles(
    PDD_DIRECTDRAW_LOCAL        pDDLcl,
    DWORD                       dwNumHandles);

//
// Helper function to get the UM surface handle
//
PR2UMSurfaceHandle
GetUMSurfaceHandle(
    LPATISURFCNTX   pD3DSurf)
{
    //
    // Surface and vertex buffer are handled differently
    //
    if (pD3DSurf->handleType == ATI_SURFACE)
    {
        LPATISURFINFO   pSurfInfo = pD3DSurf->hATISurfInfoHandle;

        if (pSurfInfo)
        {
            return ((R2UMSurfaceHandle *)pSurfInfo->hSurface);
        }
    }
    else if (pD3DSurf->handleType == ATI_VERTEXBUFFER)
    {
        LPATIVERTEXBUFFER   pVB = (ATIVERTEXBUFFER *)pD3DSurf;

        return ((R2UMSurfaceHandle *)pVB->sVtxListData.hSurface);
    }

    return (NULL);
}

// typedef struct _ATIDXOBJECT    *LPATIDXOBJECT;
typedef struct _D3DDEVICE      *LPD3DDEVICE;
typedef struct _ATID3DCNTX     *LPATID3DCNTX;

DDHAL_DDCALLBACKS               DDCb     = {0};
DDHAL_DDSURFACECALLBACKS        DDSurfCb = {0};
DDHAL_D3DBUFCALLBACKS           D3DBufCb = {0};
DDHAL_DDMISCELLANEOUS2CALLBACKS Misc2Cb  = {0};
D3DHAL_CALLBACKS                D3DHALCb = {0};
D3DHAL_CALLBACKS3               D3DCb3   = {0};

DDHAL_DDCALLBACKS                  *pDDCb;
DDHAL_DDSURFACECALLBACKS           *pDDSurfCb;
DDHAL_D3DBUFCALLBACKS              *pD3DBufCb;
DDHAL_DDMISCELLANEOUS2CALLBACKS    *pMisc2Cb;
D3DHAL_CALLBACKS                   *pD3DHALCb;
D3DHAL_CALLBACKS3                  *pD3DCb3;

void
CPixel__ConvertToOldFormat(
    LPDDPIXELFORMAT pOldFormat,
    D3DFORMAT       NewFormat)
{
    // Zero out the format to avoid missing
    // cases where it isn't initialized right
    ZeroMemory(pOldFormat, sizeof(*pOldFormat));

    // Set Size
    pOldFormat->dwSize = sizeof(DDPIXELFORMAT);

    // Convert away
    if (HIWORD((DWORD)NewFormat))
    {
        pOldFormat->dwFlags = DDPF_FOURCC;
        pOldFormat->dwFourCC = (DWORD)NewFormat;
        return;
    }

    switch (NewFormat)
    {
    case D3DFMT_R8G8B8:
        pOldFormat->dwFlags           = DDPF_RGB;
        pOldFormat->dwRBitMask        = 0x00ff0000;
        pOldFormat->dwGBitMask        = 0x0000ff00;
        pOldFormat->dwBBitMask        = 0x000000ff;
        pOldFormat->dwRGBBitCount     = 24;
        break;

    case D3DFMT_A8R8G8B8:
        pOldFormat->dwFlags           = DDPF_RGB | DDPF_ALPHAPIXELS;
        pOldFormat->dwRGBAlphaBitMask = 0xFF000000;
        pOldFormat->dwRBitMask        = 0x00ff0000;
        pOldFormat->dwGBitMask        = 0x0000ff00;
        pOldFormat->dwBBitMask        = 0x000000ff;
        pOldFormat->dwRGBBitCount     = 32;
        break;

    case D3DFMT_X8R8G8B8:
        pOldFormat->dwFlags           = DDPF_RGB;
        pOldFormat->dwRBitMask        = 0x00ff0000;
        pOldFormat->dwGBitMask        = 0x0000ff00;
        pOldFormat->dwBBitMask        = 0x000000ff;
        pOldFormat->dwRGBBitCount     = 32;
        break;

    case D3DFMT_R5G6B5:
        pOldFormat->dwFlags           = DDPF_RGB;
        pOldFormat->dwRBitMask        = 0x0000f800;
        pOldFormat->dwGBitMask        = 0x000007e0;
        pOldFormat->dwBBitMask        = 0x0000001f;
        pOldFormat->dwRGBBitCount     = 16;
        break;

    case D3DFMT_X1R5G5B5:
        pOldFormat->dwFlags           = DDPF_RGB;
        pOldFormat->dwRBitMask        = 0x00007c00;
        pOldFormat->dwGBitMask        = 0x000003e0;
        pOldFormat->dwBBitMask        = 0x0000001f;
        pOldFormat->dwRGBBitCount     = 16;
        break;

    case D3DFMT_A1R5G5B5:
        pOldFormat->dwFlags           = DDPF_RGB | DDPF_ALPHAPIXELS;
        pOldFormat->dwRGBAlphaBitMask = 0x00008000;
        pOldFormat->dwRBitMask        = 0x00007c00;
        pOldFormat->dwGBitMask        = 0x000003e0;
        pOldFormat->dwBBitMask        = 0x0000001f;
        pOldFormat->dwRGBBitCount     = 16;
        break;

    case D3DFMT_A4R4G4B4:
        pOldFormat->dwFlags           = DDPF_RGB | DDPF_ALPHAPIXELS;
        pOldFormat->dwRGBAlphaBitMask = 0x0000f000;
        pOldFormat->dwRBitMask        = 0x00000f00;
        pOldFormat->dwGBitMask        = 0x000000f0;
        pOldFormat->dwBBitMask        = 0x0000000f;
        pOldFormat->dwRGBBitCount     = 16;
        break;

    case D3DFMT_X4R4G4B4:
        pOldFormat->dwFlags           = DDPF_RGB;
        pOldFormat->dwRBitMask        = 0x00000f00;
        pOldFormat->dwGBitMask        = 0x000000f0;
        pOldFormat->dwBBitMask        = 0x0000000f;
        pOldFormat->dwRGBBitCount     = 16;
        break;

    case D3DFMT_R3G3B2:
        pOldFormat->dwFlags           = DDPF_RGB;
        pOldFormat->dwRBitMask        = 0x000000e0;
        pOldFormat->dwGBitMask        = 0x0000001c;
        pOldFormat->dwBBitMask        = 0x00000003;
        pOldFormat->dwRGBBitCount     = 8;
        break;

    case D3DFMT_A8R3G3B2:
        pOldFormat->dwFlags           = DDPF_RGB | DDPF_ALPHAPIXELS;
        pOldFormat->dwRGBAlphaBitMask = 0x0000FF00;
        pOldFormat->dwRBitMask        = 0x000000e0;
        pOldFormat->dwGBitMask        = 0x0000001c;
        pOldFormat->dwBBitMask        = 0x00000003;
        pOldFormat->dwRGBBitCount     = 16;
        break;

    case D3DFMT_A8P8:
        pOldFormat->dwFlags            = DDPF_RGB         |
                                         DDPF_ALPHAPIXELS |
                                         DDPF_PALETTEINDEXED8;

        pOldFormat->dwRGBAlphaBitMask  = 0x0000FF00;
        pOldFormat->dwRGBBitCount      = 16;
        break;

    case D3DFMT_P8:
        pOldFormat->dwFlags            = DDPF_RGB         |
                                         DDPF_PALETTEINDEXED8;
        pOldFormat->dwRGBBitCount      = 8;
        break;

    case D3DFMT_L8:
        pOldFormat->dwFlags             = DDPF_LUMINANCE;
        pOldFormat->dwLuminanceBitMask  = 0x000000FF;
        pOldFormat->dwLuminanceBitCount = 8;
        break;

    case D3DFMT_A8L8:
        pOldFormat->dwFlags                 = DDPF_LUMINANCE |
                                              DDPF_ALPHAPIXELS;
        pOldFormat->dwLuminanceAlphaBitMask = 0x0000FF00;
        pOldFormat->dwLuminanceBitMask      = 0x000000FF;
        pOldFormat->dwLuminanceBitCount     = 16;
        break;

    case D3DFMT_A4L4:
        pOldFormat->dwFlags                 = DDPF_LUMINANCE |
                                              DDPF_ALPHAPIXELS;
        pOldFormat->dwLuminanceAlphaBitMask = 0x000000F0;
        pOldFormat->dwLuminanceBitMask      = 0x0000000F;
        pOldFormat->dwLuminanceBitCount     = 8;
        break;

    case D3DFMT_V8U8:
        pOldFormat->dwFlags                = DDPF_BUMPDUDV;
        pOldFormat->dwBumpDvBitMask        = 0x0000FF00;
        pOldFormat->dwBumpDuBitMask        = 0x000000FF;
        pOldFormat->dwBumpBitCount         = 16;
        break;

    case D3DFMT_L6V5U5:
        pOldFormat->dwFlags                = DDPF_BUMPDUDV |
                                             DDPF_BUMPLUMINANCE;
        pOldFormat->dwBumpLuminanceBitMask = 0x0000FC00;
        pOldFormat->dwBumpDvBitMask        = 0x000003E0;
        pOldFormat->dwBumpDuBitMask        = 0x0000001F;
        pOldFormat->dwBumpBitCount         = 16;
        break;

    case D3DFMT_X8L8V8U8:
        pOldFormat->dwFlags                = DDPF_BUMPDUDV |
                                             DDPF_BUMPLUMINANCE;
        pOldFormat->dwBumpLuminanceBitMask = 0x00FF0000;
        pOldFormat->dwBumpDvBitMask        = 0x0000FF00;
        pOldFormat->dwBumpDuBitMask        = 0x000000FF;
        pOldFormat->dwBumpBitCount         = 32;
        break;

    case D3DFMT_A8:
        pOldFormat->dwFlags                = DDPF_ALPHA;
        pOldFormat->dwAlphaBitDepth        = 8;
        break;

    case D3DFMT_D16:
    case D3DFMT_D16_LOCKABLE:
        pOldFormat->dwFlags                = DDPF_ZBUFFER;
        pOldFormat->dwZBufferBitDepth      = 16;
        pOldFormat->dwZBitMask             = 0xFFFF;
        pOldFormat->dwStencilBitDepth      = 0;
        pOldFormat->dwStencilBitMask       = 0;
        break;

    case D3DFMT_D32:
        pOldFormat->dwFlags                = DDPF_ZBUFFER;
        pOldFormat->dwZBufferBitDepth      = 32;
        pOldFormat->dwZBitMask             = 0xFFFFFFFF;
        pOldFormat->dwStencilBitDepth      = 0;
        pOldFormat->dwStencilBitMask       = 0;
        break;

    case D3DFMT_D15S1:
        pOldFormat->dwFlags                = DDPF_ZBUFFER |
                                             DDPF_STENCILBUFFER;
        pOldFormat->dwZBufferBitDepth      = 16;
        pOldFormat->dwZBitMask             = 0xFFFE;
        pOldFormat->dwStencilBitDepth      = 1;
        pOldFormat->dwStencilBitMask       = 0x0001;
        break;
    case D3DFMT_D24S8:
        pOldFormat->dwFlags                = DDPF_ZBUFFER |
                                             DDPF_STENCILBUFFER;
        pOldFormat->dwZBufferBitDepth      = 32;
        pOldFormat->dwZBitMask             = 0xFFFFFF00;
        pOldFormat->dwStencilBitDepth      = 8;
        pOldFormat->dwStencilBitMask       = 0xFF;
        break;
    case D3DFMT_S1D15:
        pOldFormat->dwFlags                = DDPF_ZBUFFER |
                                             DDPF_STENCILBUFFER;
        pOldFormat->dwZBufferBitDepth      = 16;
        pOldFormat->dwZBitMask             = 0x7FFF;
        pOldFormat->dwStencilBitDepth      = 1;
        pOldFormat->dwStencilBitMask       = 0x8000;
        break;
    case D3DFMT_S8D24:
        pOldFormat->dwFlags                = DDPF_ZBUFFER |
                                             DDPF_STENCILBUFFER;
        pOldFormat->dwZBufferBitDepth      = 32;
        pOldFormat->dwZBitMask             = 0x00FFFFFF;
        pOldFormat->dwStencilBitDepth      = 8;
        pOldFormat->dwStencilBitMask       = 0xFF000000;
        break;
    case D3DFMT_X8D24:
        pOldFormat->dwFlags                = DDPF_ZBUFFER;
        pOldFormat->dwZBufferBitDepth      = 32;
        pOldFormat->dwZBitMask             = 0x00FFFFFF;
        pOldFormat->dwStencilBitDepth      = 0;
        pOldFormat->dwStencilBitMask       = 0x00000000;
        break;
    case D3DFMT_D24X8:
        pOldFormat->dwFlags                = DDPF_ZBUFFER;
        pOldFormat->dwZBufferBitDepth      = 32;
        pOldFormat->dwZBitMask             = 0xFFFFFF00;
        pOldFormat->dwStencilBitDepth      = 0;
        pOldFormat->dwStencilBitMask       = 0x00000000;
        break;
    case D3DFMT_D24X4S4:
        pOldFormat->dwFlags                = DDPF_ZBUFFER |
                                             DDPF_STENCILBUFFER;
        pOldFormat->dwZBufferBitDepth      = 32;
        pOldFormat->dwZBitMask             = 0xFFFFFF00;
        pOldFormat->dwStencilBitDepth      = 4;
        pOldFormat->dwStencilBitMask       = 0x0000000F;
        break;
    case D3DFMT_X4S4D24:
        pOldFormat->dwFlags                = DDPF_ZBUFFER |
                                             DDPF_STENCILBUFFER;
        pOldFormat->dwZBufferBitDepth      = 32;
        pOldFormat->dwZBitMask             = 0x00FFFFFF;
        pOldFormat->dwStencilBitDepth      = 4;
        pOldFormat->dwStencilBitMask       = 0x0F000000;
        break;

    default:
        // All other formats are treated as a
        // FOURCC
        pOldFormat->dwFlags = DDPF_FOURCC;
        pOldFormat->dwFourCC = (DWORD)NewFormat;
        break;
    }

    return;
}

void
InitSurfaceStructures(
    D3DDDIARG_CREATERESOURCE*   pCreateSurface,
    DDHAL_CREATESURFACEDATA    *pOldCreateSurfaceData,
    DDSURFACEDESC2             *pSurfaceDesc)
{
    DWORD                       i;
    DD_SURFACE_LOCAL           *pDDSurfaceLocal;
    DD_SURFACE_GLOBAL          *pDDSurfaceGlobal;
    DD_SURFACE_MORE            *pDDSurfaceMore;

    for (i = 0; i < pCreateSurface->SurfCount; i++)
    {
        pDDSurfaceLocal  = pOldCreateSurfaceData->lplpSList[i];
        pDDSurfaceGlobal = pDDSurfaceLocal->lpGbl;
        pDDSurfaceMore   = pDDSurfaceLocal->lpSurfMore;

        pDDSurfaceLocal->dwFlags          = 0;
        pDDSurfaceLocal->ddsCaps.dwCaps   = 0;
        pDDSurfaceMore->ddsCapsEx.dwCaps2 = 0;
        pDDSurfaceMore->ddsCapsEx.dwCaps3 = 0;
        pDDSurfaceMore->ddsCapsEx.dwCaps4 = 0;

        // Make sure there's always a valid pixel format for the surface:
        if ((pCreateSurface->Format != D3DFMT_UNKNOWN) &&
            (pCreateSurface->Format != D3DFMT_VERTEXDATA) &&
            (pCreateSurface->Format != D3DFMT_INDEX16) &&
            (pCreateSurface->Format != D3DFMT_INDEX32) &&
            (pCreateSurface->Format != D3DDDIFMT_MACROBLOCKDATA) &&
            (pCreateSurface->Format != D3DDDIFMT_RESIDUALDIFFERENCEDATA) &&
            (pCreateSurface->Format != D3DDDIFMT_DEBLOCKINGDATA) &&
            (pCreateSurface->Format != D3DDDIFMT_INVERSEQUANTIZATIONDATA) &&
            (pCreateSurface->Format != D3DDDIFMT_SLICECONTROLDATA) &&
            (pCreateSurface->Format != D3DDDIFMT_BITSTREAMDATA))
        {
            pDDSurfaceLocal->dwFlags |= DDRAWISURF_HASPIXELFORMAT;
            // For non-textures, we want to promote X8R8G8B8 to A8R8G8B8 in some cases;
            // this allows things like RTs and Backbuffers to get created matching the
            // primary which is more consistent with typical DX7 usage.
            CPixel__ConvertToOldFormat(&pDDSurfaceGlobal->ddpfSurface, pCreateSurface->Format);
        }

        // Setup width/height first
        pDDSurfaceGlobal->wWidth  = pCreateSurface->pSurfList[i].Width;
        pDDSurfaceGlobal->wHeight = pCreateSurface->pSurfList[i].Height;

        // Setup pitch
        pDDSurfaceGlobal->lPitch  = pCreateSurface->pSurfList[i].SysMemPitch;

        // Setup multisample caps
        pDDSurfaceMore->ddsCapsEx.dwCaps3  = DDSCAPS3_MULTISAMPLE_MASK & (DWORD) pCreateSurface->MultisampleType;
        pDDSurfaceMore->ddsCapsEx.dwCaps3 |= DDSCAPS3_MULTISAMPLE_QUALITY_MASK & (pCreateSurface->MultisampleQuality << DDSCAPS3_MULTISAMPLE_QUALITY_SHIFT);

        // Surfaces come in three general flavors:
        //  - Primary flip chains
        //  - Z buffers
        //  - OffscreenPlain (RenderTargets or just sys-mem stuff)
        //
        // Textures are a different resource type

        // Note: Production LDDM drivers should treat all primary surfaces identically.
        // In particular, drivers should not rely on the runtime to create primary surfaces in a particular order.

        if (pCreateSurface->Flags.Primary)
        {
            // If we aren't creating a primary flip chain, then we
            // don't have to do much here.

            if (pCreateSurface->SurfCount == 1)
            {
                // See if this is primary surface or some other kind of primary surface.

                pDDSurfaceLocal->ddsCaps.dwCaps |= DDSCAPS_PRIMARYSURFACE;
            }
            else
            {
                if (i == 0)
                {
                    pDDSurfaceLocal->ddsCaps.dwCaps |= DDSCAPS_PRIMARYSURFACE;
                    pDDSurfaceLocal->ddsCaps.dwCaps |= (DDSCAPS_VISIBLE | DDSCAPS_FRONTBUFFER);
                }
                else
                {
                    // This is a back buffer
                    pDDSurfaceLocal->ddsCaps.dwCaps |= DDSCAPS_BACKBUFFER;
                }

                // All surfaces in the primary chain get these caps
                pDDSurfaceLocal->ddsCaps.dwCaps |= DDSCAPS_COMPLEX | DDSCAPS_FLIP | DDSCAPS_3DDEVICE;

            }
            if (D3DFMT_A2R10G10B10 == pCreateSurface->Format)
            {
                pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_ENABLEALPHACHANNEL;
            }
        }

        if (pCreateSurface->Flags.ZBuffer)
        {
            pDDSurfaceLocal->ddsCaps.dwCaps |= DDSCAPS_ZBUFFER;
        }
		

        if ((pCreateSurface->Flags.Texture) &&
            (D3DDDIPOOL_SYSTEMMEM == pCreateSurface->Pool))
        {
            //
            // Set up the special encoding for
            // system memory DXT texture's width and height
            //
            if ((pCreateSurface->Format == D3DDDIFMT_DXT1) ||
                (pCreateSurface->Format == D3DDDIFMT_DXT2) ||
                (pCreateSurface->Format == D3DDDIFMT_DXT3) ||
                (pCreateSurface->Format == D3DDDIFMT_DXT4) ||
                (pCreateSurface->Format == D3DDDIFMT_DXT5))
            {
                pDDSurfaceGlobal->wHeight /= 4;

                if (pCreateSurface->Format == D3DDDIFMT_DXT1)
                {
                    pDDSurfaceGlobal->wWidth *= 8;
                }
                else
                {
                    pDDSurfaceGlobal->wWidth *= 16;
                }
                pDDSurfaceGlobal->wWidth /= 4;
            }
        }

        if ((pCreateSurface->Flags.Texture) &&
            (! (pCreateSurface->Flags.CubeMap)))
        {
            pDDSurfaceLocal->ddsCaps.dwCaps |= DDSCAPS_TEXTURE;

            //mipmaps are only DDI-level mipmaps if they're more than one level
            if (pCreateSurface->SurfCount > 1)
            {
                pDDSurfaceLocal->ddsCaps.dwCaps |= DDSCAPS_MIPMAP;
            }

            if (pDDSurfaceLocal->ddsCaps.dwCaps & DDSCAPS_MIPMAP)
            {
                pDDSurfaceMore->dwMipMapCount = pCreateSurface->SurfCount - i;
            }

            if (i > 0)
            {
                // Mark non-top levels as being a sub-level
                pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_MIPMAPSUBLEVEL;
            }

            if (pCreateSurface->Flags.Dynamic)
            {
                pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_HINTDYNAMIC;
            }

            if ((pCreateSurface->Flags.AutogenMipmap) &&
                (pCreateSurface->Pool != D3DDDIPOOL_SYSTEMMEM))
            {
                pDDSurfaceMore->ddsCapsEx.dwCaps3 |= DDSCAPS3_AUTOGENMIPMAP;
            }
        }

        if (pCreateSurface->Flags.Volume)
        {
            pDDSurfaceLocal->ddsCaps.dwCaps |= DDSCAPS_TEXTURE | DDSCAPS_MIPMAP;
            pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_VOLUME;
            pDDSurfaceMore->ddsCapsEx.dwCaps4 =
                MAKELONG((WORD)(pCreateSurface->pSurfList[i].Depth),0);

            if (i > 0)
            {
                // Mark non-top levels as being a sub-level
                pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_MIPMAPSUBLEVEL;
            }

            if (pCreateSurface->Flags.Dynamic)
            {
                pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_HINTDYNAMIC;
            }

            if ((pCreateSurface->Flags.AutogenMipmap) &&
                (pCreateSurface->Pool != D3DDDIPOOL_SYSTEMMEM))
            {
                pDDSurfaceMore->ddsCapsEx.dwCaps3 |= DDSCAPS3_AUTOGENMIPMAP;
            }
        }
        if (pCreateSurface->Flags.CubeMap)
        {
            pDDSurfaceLocal->ddsCaps.dwCaps |= DDSCAPS_TEXTURE | DDSCAPS_COMPLEX;
            pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_CUBEMAP;

            //cubemaps are only DDI-level mipmaps if they're more than one level
            if (pCreateSurface->SurfCount>6)
                pDDSurfaceLocal->ddsCaps.dwCaps |= DDSCAPS_MIPMAP;

            // DX8 only supports creation of all faces
            {
                DWORD dwOrderedFaces[6] = {
                                           DDSCAPS2_CUBEMAP_POSITIVEX,
                                           DDSCAPS2_CUBEMAP_NEGATIVEX,
                                           DDSCAPS2_CUBEMAP_POSITIVEY,
                                           DDSCAPS2_CUBEMAP_NEGATIVEY,
                                           DDSCAPS2_CUBEMAP_POSITIVEZ,
                                           DDSCAPS2_CUBEMAP_NEGATIVEZ
                };

                int MipLevels;

                MipLevels = pCreateSurface->SurfCount / 6; //since all faces are always present in DX8

                if (MipLevels == 0)
                {
                    MipLevels = 1;
                }

                //the first n (where n is mip depth) faces are +x, etc.
                pDDSurfaceMore->ddsCapsEx.dwCaps2 |= dwOrderedFaces[i / MipLevels];

                //every MipLevels'th surface is a top-level face,
                if (i % MipLevels)
                {
                    // Mark non-top levels as being a sub-level
                    pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_MIPMAPSUBLEVEL;
                }

                if (pCreateSurface->Flags.Dynamic)
                {
                    pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_HINTDYNAMIC;
                }

                if ((pCreateSurface->Flags.AutogenMipmap) &&
                    (pCreateSurface->Pool != D3DDDIPOOL_SYSTEMMEM))
                {
                    pDDSurfaceMore->ddsCapsEx.dwCaps3 |= DDSCAPS3_AUTOGENMIPMAP;
                }
            }
        }

        if (pCreateSurface->Flags.VertexBuffer ||
            pCreateSurface->Flags.IndexBuffer)
        {
            HSLASSERT(pCreateSurface->pSurfList[0].Height == 1);
            pDDSurfaceGlobal->dwLinearSize = pCreateSurface->pSurfList[0].Width;
        }

        if (pCreateSurface->Flags.VertexBuffer)
        {
            pDDSurfaceLocal->ddsCaps.dwCaps   |= DDSCAPS_EXECUTEBUFFER;
            pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_RESERVED1;    //aka DDSCAPS2_VERTEXBUFFER;
            if (pCreateSurface->Flags.Dynamic)
            {
                pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_HINTDYNAMIC;
            }
            if (pCreateSurface->Flags.HintStatic)
            {
                pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_HINTSTATIC;
            }
            pDDSurfaceGlobal->dwLinearSize = pDDSurfaceGlobal->wWidth;
        }
        if (pCreateSurface->Flags.IndexBuffer)
        {
            pDDSurfaceLocal->ddsCaps.dwCaps   |= DDSCAPS_EXECUTEBUFFER;
            pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_RESERVED3;    //aka DDSCAPS2_INDEXBUFFER;
            if (pCreateSurface->Flags.Dynamic)
            {
                pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_HINTDYNAMIC;
            }
            if (pCreateSurface->Flags.HintStatic)
            {
                pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_HINTSTATIC;
            }
            pDDSurfaceGlobal->dwLinearSize  = pDDSurfaceGlobal->wWidth;
        }

        if (pCreateSurface->Flags.RenderTarget)
        {
            pDDSurfaceLocal->ddsCaps.dwCaps |= DDSCAPS_3DDEVICE;
        }
        if (pCreateSurface->Flags.WriteOnly)
        {
            pDDSurfaceLocal->ddsCaps.dwCaps |= DDSCAPS_WRITEONLY;
        }
        if (pCreateSurface->Flags.NotLockable)
        {
            pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_NOTUSERLOCKABLE;
        }
        else if (DDSCAPS_TEXTURE & pDDSurfaceLocal->ddsCaps.dwCaps)
        {
            //
            // NOTE: CreateTextureSurface uses DDSCAPS2_HINTDYNAMIC to decide
            //       if a surface should be tiled, mark any texture that can
            //       potentially be locked with this flag. (DX7 textures)
            //
            pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_HINTDYNAMIC;
        }

        if (pCreateSurface->Flags.DiscardRenderTarget)
        {
            if (!( pCreateSurface->Flags.ZBuffer
                || pCreateSurface->Flags.Texture
                || pCreateSurface->Flags.CubeMap
                || pCreateSurface->Flags.Volume
                || pCreateSurface->Flags.VertexBuffer
                || pCreateSurface->Flags.IndexBuffer)
               )
            {
                pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_DISCARDBACKBUFFER;
            }
        }
        if (pCreateSurface->Flags.Points)
        {
            pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_POINTS;
        }
        if (pCreateSurface->Flags.RtPatches)
        {
            pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_RTPATCHES;
        }
        if (pCreateSurface->Flags.NPatches)
        {
            pDDSurfaceMore->ddsCapsEx.dwCaps2 |= DDSCAPS2_NPATCHES;
        }

        switch (pCreateSurface->Pool)
        {
        case D3DDDIPOOL_LOCALVIDMEM:
            pDDSurfaceLocal->ddsCaps.dwCaps |= DDSCAPS_LOCALVIDMEM | DDSCAPS_VIDEOMEMORY;
            break;
        case D3DDDIPOOL_NONLOCALVIDMEM:
            pDDSurfaceLocal->ddsCaps.dwCaps |= DDSCAPS_NONLOCALVIDMEM | DDSCAPS_VIDEOMEMORY;
            break;
        case D3DDDIPOOL_SYSTEMMEM:
            pDDSurfaceLocal->ddsCaps.dwCaps   |= DDSCAPS_SYSTEMMEMORY;
            pDDSurfaceMore->ddsCapsEx.dwCaps3 &= ~DDSCAPS3_AUTOGENMIPMAP;
            pDDSurfaceGlobal->fpVidMem         = (FLATPTR)pCreateSurface->pSurfList[i].pSysMem;
            break;
        case D3DDDIPOOL_VIDEOMEMORY:
            pDDSurfaceLocal->ddsCaps.dwCaps |= DDSCAPS_VIDEOMEMORY;
            break;
        default:
            /* Unknown Pool?? */
            break;
        }
    }

    pDDSurfaceLocal  = pOldCreateSurfaceData->lplpSList[0];
    pDDSurfaceGlobal = pDDSurfaceLocal->lpGbl;
    pDDSurfaceMore   = pDDSurfaceLocal->lpSurfMore;

    pSurfaceDesc->ddsCaps.dwCaps  = pDDSurfaceLocal->ddsCaps.dwCaps;
    pSurfaceDesc->ddsCaps.dwCaps2 = pDDSurfaceMore->ddsCapsEx.dwCaps2;
    pSurfaceDesc->ddsCaps.dwCaps3 = pDDSurfaceMore->ddsCapsEx.dwCaps3;
    pSurfaceDesc->ddsCaps.dwCaps4 = pDDSurfaceMore->ddsCapsEx.dwCaps4;
    pSurfaceDesc->ddpfPixelFormat = pDDSurfaceGlobal->ddpfSurface;

    if (pCreateSurface->Flags.Texture || pCreateSurface->Flags.Volume)
    {
        pSurfaceDesc->dwMipMapCount = pCreateSurface->SurfCount;
        if (pSurfaceDesc->dwMipMapCount)
        {
            pSurfaceDesc->dwFlags |= DDSD_MIPMAPCOUNT;
        }
    }
    else if (pCreateSurface->Flags.CubeMap)
    {
        if (pCreateSurface->SurfCount > 6)
        {
            pSurfaceDesc->dwMipMapCount = pCreateSurface->SurfCount / 6;
            pSurfaceDesc->dwFlags |= DDSD_MIPMAPCOUNT;
        }
    }
    else if (pCreateSurface->SurfCount > 1)
    {
        pSurfaceDesc->dwBackBufferCount = pCreateSurface->SurfCount - 1;
        pSurfaceDesc->dwFlags |= DDSD_BACKBUFFERCOUNT;
    }
    pSurfaceDesc->dwHeight = pDDSurfaceGlobal->wHeight;
    pSurfaceDesc->dwWidth = pDDSurfaceGlobal->wWidth;
    pSurfaceDesc->dwFlags |= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
    if (pDDSurfaceLocal->dwFlags & DDRAWISURF_HASPIXELFORMAT)
    {
        pSurfaceDesc->dwFlags |= DDSD_PIXELFORMAT;
    }
    if (pCreateSurface->Flags.VertexBuffer)
    {
        pSurfaceDesc->dwFVF = pCreateSurface->Fvf;
        pSurfaceDesc->dwFlags |= DDSD_FVF;
    }
    if (pSurfaceDesc->ddsCaps.dwCaps & DDSCAPS_EXECUTEBUFFER)
    {
        pSurfaceDesc->dwLinearSize = pCreateSurface->pSurfList[0].SysMemPitch;
        pSurfaceDesc->dwFlags |= DDSD_LINEARSIZE;
    }
    if (pSurfaceDesc->ddsCaps.dwCaps2 & DDSCAPS2_VOLUME)
    {
        pSurfaceDesc->dwDepth = pCreateSurface->pSurfList[0].Depth;
        pSurfaceDesc->dwFlags |= DDSD_DEPTH;
    }

    if (pSurfaceDesc->ddsCaps.dwCaps & DDSCAPS_ZBUFFER)
    {
        // ATI Rage3 driver in Win2K still expects dwZbufferBitDepth
        // in the old place in DDSD, so put it there but probably not
        // set the bit in dwFlags as we don't advocate it.
        ((DDSURFACEDESC*)pSurfaceDesc)->dwZBufferBitDepth =
            pSurfaceDesc->ddpfPixelFormat.dwZBufferBitDepth;
    }
}

//
// 6 faces for maximal face of 2048x2048
//
#define MAX_MIPLEVEL   72

DWORD APIENTRY
CanCreateExecuteBuffer32(
    DD_CANCREATESURFACEDATA *);

DWORD APIENTRY
CanCreateSurface32(
    DD_CANCREATESURFACEDATA *);

DWORD APIENTRY
CreateExecuteBuffer32(
    DDHAL_CREATESURFACEDATA *);

DWORD APIENTRY
CreateSurface32(
    DDHAL_CREATESURFACEDATA *);

HRESULT
CreateSurfaceNotify(
    HANDLE                      pDriverInstance,
    D3DDDIARG_CREATERESOURCE*   pCRData,
    PDD_SURFACE_LOCAL           pDDSLcl);

//
// Surface linkage in mipmap cubmap is a little bit strange :
//     (1) All mip sublevel of POSITIVEX face and other top level faces
//         are linked to POSITIVEX
//     (2) Mip sublevel of other top level faces are linked to corresponding
//         top level faces
//
//  SelectAttachmentSurface() is adopted from ddgdi32.c
//
DWORD
SelectAttachmentSurface(
    BOOL    bCubeMap,
    DWORD   dwSurfaceIndex,
    DWORD   dwMipCount)
{
    if ((bCubeMap) && ((dwSurfaceIndex % dwMipCount) == 0))
    {
        return (0);
    }
    else
    {
        return (dwSurfaceIndex - 1);
    }
}

//
// Return value indicates if pDDAttachList is actually used
//
VOID
AttachSurfaces(
    PDD_SURFACE_LOCAL   pDDSLclTo,
    PDD_SURFACE_LOCAL   pDDSLclFrom,
    PDD_ATTACHLIST      pDDAttachList)
{
    if (pDDSLclFrom->lpAttachListFrom)
    {
        pDDSLclFrom->lpAttachListFrom->lpLink     = NULL;
        pDDSLclFrom->lpAttachListFrom->lpAttached = pDDSLclTo;
    }

    if ((pDDSLclTo) && (pDDSLclTo->lpAttachList))
    {
        if (! pDDSLclTo->lpAttachList->lpAttached)
        {
            pDDSLclTo->lpAttachList->lpLink     = NULL;
            pDDSLclTo->lpAttachList->lpAttached = pDDSLclFrom;
        }
        else
        {
            PDD_ATTACHLIST  pCurAttachment;

            //
            // This should only happen for CUBEMAP
            //
            // HSLASSERT(pDDSLclTo->lpSurfMore->ddsCapsEx.dwCaps2 & DDSCAPS2_CUBEMAP);
            // HSLASSERT(pDDSLclFrom->lpSurfMore->ddsCapsEx.dwCaps2 & DDSCAPS2_CUBEMAP);

            pCurAttachment = pDDSLclTo->lpAttachList;
            while (pCurAttachment->lpLink)
            {
                pCurAttachment = pCurAttachment->lpLink;
            }

            // Link the surface into the chain
            pCurAttachment->lpLink    = pDDAttachList;

            pDDAttachList->lpLink     = NULL;
            pDDAttachList->lpAttached = pDDSLclFrom;
        }
    }
}

__inline
struct HSLSurfInfo *
GetHSLSurfInfoPtr(
    PDD_SURFACE_LOCAL   pDDSLcl)
{
    return ((struct HSLSurfInfo *)pDDSLcl->dwReserved1);
}

HRESULT
D3DDDICreateResource(
    PDD_DIRECTDRAW_LOCAL        pDDLcl,
    PDD_DIRECTDRAW_GLOBAL       pDDGbl,
    D3DDDIARG_CREATERESOURCE*   pD3DCSData)
{
    DWORD                       ret, i;
    HRESULT                     RVal = E_FAIL;
    DDHAL_CANCREATESURFACEDATA  ccsd = {0};
    DDHAL_CREATESURFACEDATA     csd = {0};

    // description of surface being created
    LPDDSURFACEDESC2            pSurfDesc = {0};

    // list of pointers to surface objects
    DD_SURFACE_LOCAL           *lplpSList[MAX_MIPLEVEL] = {0};

    BOOL                        bCubeMap;
    DWORD                       dwMipCount;
    PDD_ATTACHLIST              pDDAttachList = NULL;     // For cubemap
    PDD_ATTACHLIST              pDDAttachListFrom = NULL;
    DWORD                       dwFreeAttachListIdx;
    PDD_ATTACHLIST              pDDAttachLink = NULL;
    PDD_SURFACE_LOCAL           pDDSLcl = NULL;
    PDD_SURFACE_GLOBAL          pDDSGbl = NULL;
    PDD_SURFACE_MORE            pDDSMore = NULL;
    PDD_SURFACE_LOCAL           pDDSLclAttachTo = NULL;
    PDD_SURFACE_LOCAL           pCurDDSLcl;
    DWORD                       dwExHandle;
    DWORD                       dwUMHandleStart = 0;

    //
    // Maximal dimension of surface is 2048x2048
    //
    if (pD3DCSData->SurfCount > MAX_MIPLEVEL)
    {
        DebugBreak();
        return (E_FAIL);
    }

#ifdef PRIVATE_HEAP
    pDDAttachList = (PDD_ATTACHLIST)HeapAlloc( g_Heap, HEAP_ZERO_MEMORY, sizeof(DD_ATTACHLIST) * (MAX_MIPLEVEL + 5) );
    pDDAttachListFrom = (PDD_ATTACHLIST)HeapAlloc( g_Heap, HEAP_ZERO_MEMORY, sizeof(DD_ATTACHLIST) * MAX_MIPLEVEL );
    pSurfDesc = (LPDDSURFACEDESC2)HeapAlloc( g_Heap, HEAP_ZERO_MEMORY, sizeof(DDSURFACEDESC2) );
    pDDSLcl = (PDD_SURFACE_LOCAL)HeapAlloc( g_Heap, HEAP_ZERO_MEMORY, sizeof(DD_SURFACE_LOCAL) * MAX_MIPLEVEL );
    pDDSGbl = (PDD_SURFACE_GLOBAL)HeapAlloc( g_Heap, HEAP_ZERO_MEMORY, sizeof(DD_SURFACE_GLOBAL) * MAX_MIPLEVEL );
    pDDSMore = (PDD_SURFACE_MORE)HeapAlloc( g_Heap, HEAP_ZERO_MEMORY, sizeof(DD_SURFACE_MORE) * MAX_MIPLEVEL );
#else
    pDDAttachList = (PDD_ATTACHLIST)LocalAlloc( LMEM_ZEROINIT, sizeof(DD_ATTACHLIST) * (MAX_MIPLEVEL + 5) );
    pDDAttachListFrom = (PDD_ATTACHLIST)LocalAlloc( LMEM_ZEROINIT, sizeof(DD_ATTACHLIST) * MAX_MIPLEVEL );
    pSurfDesc = (LPDDSURFACEDESC2)LocalAlloc( LMEM_ZEROINIT, sizeof(DDSURFACEDESC2) );
    pDDSLcl = (PDD_SURFACE_LOCAL)LocalAlloc( LMEM_ZEROINIT, sizeof(DD_SURFACE_LOCAL) * MAX_MIPLEVEL );
    pDDSGbl = (PDD_SURFACE_GLOBAL)LocalAlloc( LMEM_ZEROINIT, sizeof(DD_SURFACE_GLOBAL) * MAX_MIPLEVEL );
    pDDSMore = (PDD_SURFACE_MORE)LocalAlloc( LMEM_ZEROINIT, sizeof(DD_SURFACE_MORE) * MAX_MIPLEVEL );
#endif


    if ( pDDAttachList == NULL
        || pDDAttachListFrom == NULL
        || pSurfDesc == NULL
        || pDDSLcl == NULL
        || pDDSGbl == NULL
        || pDDSMore == NULL )
    {
        RVal = DDERR_OUTOFMEMORY;
        goto Exit;
    }

    if (pD3DCSData->Flags.CubeMap)
    {
        bCubeMap   = TRUE;
        dwMipCount = pD3DCSData->SurfCount / 6;
    }
    else
    {
        bCubeMap   = FALSE;
        dwMipCount = pD3DCSData->SurfCount;
    }

    pSurfDesc->dwSize = sizeof(DDSURFACEDESC2);

    //
    // Get SurfCount of consecutive Ex handles in CD3DContext m_RTbl.
    // Those indexes will become UMD surface handles !!!
    //
    if (! (dwExHandle = GetExHandles(pDDLcl, pD3DCSData->SurfCount)))
    {
        RVal = DDERR_OUTOFMEMORY;
        goto Exit;
    }

    dwUMHandleStart = dwExHandle;

    dwFreeAttachListIdx = MAX_MIPLEVEL;
    for (i = 0, pCurDDSLcl = pDDSLcl; i < pD3DCSData->SurfCount; i++, pCurDDSLcl++)
    {
        pCurDDSLcl->lpGbl      = (pDDSGbl + i);
        pCurDDSLcl->lpSurfMore = (pDDSMore + i);

        //
        // Initialize the EX handle
        //
        pCurDDSLcl->lpSurfMore->dwSurfaceHandle = dwExHandle++; // save UMD sufrace handle in ddraw structure

        //
        // Decide the upper level surface
        //
        if (i > 0)
        {
            pDDSLclAttachTo = pDDSLcl +
                              SelectAttachmentSurface(bCubeMap,
                                                      i,
                                                      dwMipCount);
        }
        else
        {
            pDDSLclAttachTo = NULL;
        }

        //
        // Allocate AttachList and AttachListFrom
        //
        if (pDDSLclAttachTo)
        {
            if (! (pDDSLclAttachTo->lpAttachList))
            {
                pDDSLclAttachTo->lpAttachList = pDDAttachList + i;
                pDDAttachLink = NULL;
            }
            else
            {
                pDDAttachLink = pDDAttachList + dwFreeAttachListIdx;
                dwFreeAttachListIdx++;
            }

            pCurDDSLcl->lpAttachListFrom = pDDAttachListFrom + i;
        }

        //
        // Link the surface together
        //
        AttachSurfaces(pDDSLclAttachTo,
                       pCurDDSLcl,
                       pDDAttachLink);

        lplpSList[i] = pCurDDSLcl;
    }

    csd.dwSCnt                   = pD3DCSData->SurfCount;
    csd.lplpSList                = lplpSList;
    InitSurfaceStructures(pD3DCSData, &csd, pSurfDesc);
	

    //
    // AI44 (used by Media Player can't be handled)
    //
    if ((pSurfDesc->ddpfPixelFormat.dwFlags & DDPF_FOURCC) &&
        (pSurfDesc->ddpfPixelFormat.dwFourCC == MAKE_FOURCC('A','I','4','4')))
    {
        return (DDERR_UNSUPPORTED);
    }

    csd.lpDD            = pDDGbl;
    csd.lpDDSurfaceDesc = (LPDDSURFACEDESC)pSurfDesc;
    csd.lplpSList       = lplpSList;

    ret = DDHAL_DRIVER_HANDLED;
    if (pSurfDesc->ddsCaps.dwCaps & DDSCAPS_VIDEOMEMORY)
    {
        if (pSurfDesc->ddsCaps.dwCaps & DDSCAPS_EXECUTEBUFFER)
        {
            ret = CreateExecuteBuffer32(&csd);
        }
        else
        {
            ret = CreateSurface32(&csd);    //  creates VidMM allocations and ATISurfaceInfo for each surface 
        }                                   //  stores KM handles for allocations created in an appropriate ATISurfaceInfo
    }

    if ((ret == DDHAL_DRIVER_HANDLED) && (SUCCEEDED(csd.ddRVal))) // for SysMem csd.ddRVal == 0
    {
        if (SUCCEEDED(CreateSurfaceNotify(pDDLcl, pD3DCSData, lplpSList[0])))
        {
            RVal = S_OK;
        }

        //
        // Clean up unused HSL surface structure for MIPMAP sublevels
        //
        for (i = 1; i < csd.dwSCnt; i++)
        {
            PDD_SURFACE_LOCAL   pSubDDSLcl = lplpSList[i];

            if ((pSubDDSLcl->ddsCaps.dwCaps & DDSCAPS_MIPMAP) &&
                (! (pSubDDSLcl->ddsCaps.dwCaps & DDSCAPS_3DDEVICE)))
            {
                struct HSLSurfInfo *pHSLSurfInfo = GetHSLSurfInfoPtr(pSubDDSLcl);

                if (pHSLSurfInfo)
                {
                    LPATIDXOBJECT   pATIDXObj = GetDXObjDDGBL(pDDGbl);

                    DeallocateD3DHSLSurfSlot(pATIDXObj->pD3DDevice,
                                             pHSLSurfInfo);
                }
            }
        }

        //
        // Return this surface's driver handle
        //
        if (csd.lplpSList[0] == NULL)
        {
            RVal = DDERR_OUTOFMEMORY;
            goto Exit;
        }
        else
        {
            pD3DCSData->hResource =
                (HANDLE)(DWORD_PTR)csd.lplpSList[0]->lpSurfMore->dwSurfaceHandle;

            HSLDPF(E_LDDM_CREATE_RES, "Creating resource caps 0x%lx, UM handle 0x%lx", pD3DCSData->Flags.Value, pD3DCSData->hResource);
        }
    }
    else
    if (FAILED(ret))
    {
        RVal = ret;
    }

Exit:

#ifdef PRIVATE_HEAP
    if ( pDDAttachList != NULL )
    {
        HeapFree(g_Heap, 0, pDDAttachList);
    }

    if ( pDDAttachListFrom != NULL )
    {
        HeapFree(g_Heap, 0, pDDAttachListFrom);
    }

    if ( pSurfDesc != NULL )
    {
        HeapFree(g_Heap, 0, pSurfDesc);
    }

    if ( pDDSLcl != NULL )
    {
        HeapFree(g_Heap, 0, pDDSLcl);
    }

    if ( pDDSGbl != NULL )
    {
        HeapFree(g_Heap, 0, pDDSGbl);
    }

    if ( pDDSMore != NULL )
    {
        HeapFree(g_Heap, 0, pDDSMore);
    }
#else
    if ( pDDAttachList != NULL )
    {
        LocalFree(pDDAttachList);
    }

    if ( pDDAttachListFrom != NULL )
    {
        LocalFree(pDDAttachListFrom);
    }

    if ( pSurfDesc != NULL )
    {
        LocalFree(pSurfDesc);
    }

    if ( pDDSLcl != NULL )
    {
        LocalFree(pDDSLcl);
    }

    if ( pDDSGbl != NULL )
    {
        LocalFree(pDDSGbl);
    }

    if ( pDDSMore != NULL )
    {
        LocalFree(pDDSMore);
    }
#endif

    return RVal;
}


//
// Thunk to call KM driver for creating allocation
//


HRESULT
AllocateVidMem(
    LPATIDXOBJECT               lpATIDXObj,
    LPDDRAWI_DIRECTDRAW_GBL     lpDD,
    DWORD                       dwHeap,
    DWORD                       dwCaps,
    DWORD                       dwFlags,
    DWORD                       dwBytesPerPixel,
    DWORD                       dwPitch,
    DWORD                       dwPitchAlign,
    DWORD                       dwHeight,
    DWORD                       dwHeightAlign,
    DWORD                       dwOffsetAlign,
    DWORD                       bDXVARenderTarget,
    DDHSLSURFACEDESC           *pHSLSurfDesc,
    DISP4DDVIDMEMDATA          *pVidMemData,
    PVOID                       pSysMem)
{
    R2DDICreateAllocationData   r2AllocData;
    D3DKMT_HANDLE               hAllocation;
    PR2UMSurfaceHandle          pR2UMSurfHandle;
    HRESULT                     hr;

    //
    // Clear out return value
    //
    memset(pVidMemData, 0, sizeof(DISP4DDVIDMEMDATA));

    //
    // Allocate memory for the handle wrapper
    //
    pR2UMSurfHandle =
        (PR2UMSurfaceHandle)
#ifdef PRIVATE_HEAP
        HeapAlloc(g_Heap, HEAP_ZERO_MEMORY, sizeof(R2UMSurfaceHandle));
#else
        LocalAlloc(LMEM_ZEROINIT, sizeof(R2UMSurfaceHandle));
#endif

    if (! pR2UMSurfHandle)
    {
        return E_FAIL;
    }

    //
    // Clear out allocation info
    //
    memset(&r2AllocData, 0, sizeof(R2DDICreateAllocationData));

    r2AllocData.sAllocInfo.dwHeap          = dwHeap;
    r2AllocData.sAllocInfo.dwCaps          = dwCaps;
    r2AllocData.sAllocInfo.dwFlags         = dwFlags;
    r2AllocData.sAllocInfo.dwBytesPerPixel = dwBytesPerPixel;
    r2AllocData.sAllocInfo.dwPitch         = dwPitch;
    r2AllocData.sAllocInfo.dwPitchAlign    = dwPitchAlign;
    r2AllocData.sAllocInfo.dwHeight        = dwHeight;
    r2AllocData.sAllocInfo.dwHeightAlign   = dwHeightAlign;
    r2AllocData.sAllocInfo.dwOffsetAlign   = dwOffsetAlign;
    if (pHSLSurfDesc)
    {
        r2AllocData.sAllocInfo.hslSurfDesc   = *pHSLSurfDesc;
        //
        // Make the pixel format pointer self contained
        //
        r2AllocData.sAllocInfo.ddPixelFormat = *pHSLSurfDesc->lpddPixelFormat;
        r2AllocData.sAllocInfo.hslSurfDesc.lpddPixelFormat = &r2AllocData.sAllocInfo.ddPixelFormat;
    }
    else
    {
        memset(&r2AllocData.sAllocInfo.hslSurfDesc, 0, sizeof(DDHSLSURFACEDESC));
    }
    r2AllocData.sAllocInfo.vidMemData      = *pVidMemData;

    hr = R200CreateAllocationCB((LPVOID)lpATIDXObj->QSHDevice,
                                &r2AllocData,
                                &hAllocation,
                                pSysMem);
    if (FAILED(hr))
    {
#ifdef PRIVATE_HEAP
        HeapFree(g_Heap, 0, pR2UMSurfHandle);
#else
        LocalFree(pR2UMSurfHandle);
#endif
        return hr;
    }

    *pVidMemData = r2AllocData.sAllocInfo.vidMemData;

    //
    // Always return 0 for the physical address
    //
    pVidMemData->dwMCOffset = 0;

    //
    // Setting lpVideoMemory to the allocation
    //
    pVidMemData->hAllocation = hAllocation;


    //
    // Wrap around the allocation handles
    //
    pR2UMSurfHandle->hAllocation  = hAllocation;
    pR2UMSurfHandle->hR2QSSurface = pVidMemData->hSurface;
    pR2UMSurfHandle->pSurfaceUM   = pVidMemData->lpRing3Addr;

    //
    // Return the wrapper to UM driver
    //
    pVidMemData->hSurface = (ULONG_PTR)pR2UMSurfHandle;

    return hr;
}

VOID
ReleaseVidMem(
    LPATIDXOBJECT           lpATIDXObj,
    LPDDRAWI_DIRECTDRAW_GBL lpDD,
    DWORD                   dwHeap,
    DISP4DDVIDMEMDATA      *pVidMemData)
{
    HRESULT                 hr;

    //
    // Free the video memory allocation
    //
    hr = R200DestroyAllocationCB((LPVOID)lpATIDXObj->QSHDevice,
                                 pVidMemData->hAllocation);
    HSLASSERT(DD_OK == hr);

    //
    // Free the memory allocated for the handle wrapper
    //
#ifdef PRIVATE_HEAP
        HeapFree(g_Heap, 0, (LPVOID)pVidMemData->hSurface);
#else
        LocalFree((LPVOID)pVidMemData->hSurface);
#endif
}



HRESULT
D3DDDIDestroyResource(
    LPATID3DCNTX            pD3DCtxt,
    DWORD                   dwExHandle,
    DWORD                   dwAllocCnt)
{
    LPATISURFCNTX           pD3DSurf;
    LPATIVERTEXBUFFER       pVB;
    HRESULT                 hr;
    DWORD                   i;

    //
    // Retrieve the private surface structure
    //
    pD3DSurf = SurfaceHandleToCntx(dwExHandle, pD3DCtxt);
    if (! pD3DSurf)
    {
        return (DDERR_INVALIDOBJECT);
    }

    HSLDPF(E_LDDM_CREATE_RES, "Destorying UM handle 0x%lx, SurfCtx 0x%lx, KM handle 0x%lx", dwExHandle, pD3DSurf, pD3DSurf->hAllocation);

    if (pD3DSurf->handleType == ATI_SURFACE)
    {
        if ((pD3DSurf->ddsCapsEx.dwCaps2 & DDSCAPS2_CUBEMAP) ||
            (pD3DSurf->ddsCaps.dwCaps    & DDSCAPS_FLIP))
        {
            //
            // Destroy the component allocations
            //
            hr = DD_OK;
            for (i = 0; i < dwAllocCnt; i++)
            {
                pD3DSurf = SurfaceHandleToCntx(dwExHandle + i, pD3DCtxt);
                if (pD3DSurf)
                {
                    if (R200DestroyAllocation(pD3DCtxt, pD3DSurf) != S_OK)
                    {
                        hr = DDERR_INVALIDOBJECT;
                    }
                }
                else
                {
                    hr = DDERR_INVALIDOBJECT;
                }
            }
        }
        else
        {
            //
            // Texture and other resources
            //
            hr = R200DestroyAllocation(pD3DCtxt, pD3DSurf);
        }
    }
    else if (pD3DSurf->handleType == ATI_VERTEXBUFFER)
    {
        //
        // Vertex/index buffer
        //
        pVB = (ATIVERTEXBUFFER *)pD3DSurf;

        hr = R200DestroyAllocation(pD3DCtxt, pD3DSurf);
    }
    else
    {
        return (DDERR_INVALIDOBJECT);
    }

    // Remove all surfaces from the context
    for (i = 0; i < dwAllocCnt; i++)
    {
        R200RemoveResourceFromContext(pD3DCtxt, dwExHandle+i);
    }

    return (hr);
}

HRESULT
D3DDDIUnlockResource(
    LPATID3DCNTX            pD3DCtxt,
    D3DDDIARG_UNLOCK       *pUnlockData)
{
    DWORD                   dwExHandle = (DWORD)(DWORD_PTR)pUnlockData->hResource;
    LPATIDXOBJECT           lpATIDXObj = GetATIDeviceInfo(pD3DCtxt->pD3DDevice);
    LPATISURFCNTX           pD3DSurf;
    PR2UMSurfaceHandle      pR2UMSurfHandle = NULL;
    HRESULT                 Ret=S_OK;

    //
    // Retrieve the private surface structure
    //
    pD3DSurf = SurfaceHandleToCntx(dwExHandle, pD3DCtxt);
    if (! pD3DSurf)
    {
        return (DDERR_INVALIDOBJECT);
    }

    HSLDPF(E_LDDM_LOCK, "Unlocking resource UM handle 0x%lx, Suf 0x%lx", dwExHandle, pD3DSurf);

    if (pD3DSurf->handleType == ATI_SURFACE)
    {
        //
        // Get the correct back buffer for full screen swap chain
        //
        if (pD3DSurf->ddsCaps.dwCaps & DDSCAPS_FLIP)
        {
            pD3DSurf = SurfaceHandleToCntx(dwExHandle + pUnlockData->SubResourceIndex,
                                           pD3DCtxt);
            if ((! pD3DSurf) || (! (pD3DSurf->ddsCaps.dwCaps & DDSCAPS_FLIP)))
            {
                return (DDERR_INVALIDOBJECT);
            }
        }

        //
        // Special handling for unlocking cubemap face
        //
        if (pD3DSurf->ddsCapsEx.dwCaps2 & DDSCAPS2_CUBEMAP)
        {
            DWORD   dwFaceExHandle;

            //
            // Pick the right cubemap face
            //

            dwFaceExHandle = dwExHandle +
                             (pUnlockData->SubResourceIndex /
                              pD3DSurf->NativeTextureInfo.dwMipCount);
            pD3DSurf = SurfaceHandleToCntx(dwFaceExHandle,
                                           pD3DCtxt);

            if (pD3DSurf == NULL)
            {
                return DDERR_INVALIDOBJECT;
            }
        }
    }
    else if (pD3DSurf->handleType == ATI_VERTEXBUFFER)
    {
    }
    else
    {
        return (DDERR_INVALIDOBJECT);
    }

    pR2UMSurfHandle = GetUMSurfaceHandle(pD3DSurf);
    if (pR2UMSurfHandle)
    {
        Ret=R200UnlockAllocationCB((LPVOID)lpATIDXObj->QSHDevice, pR2UMSurfHandle->hAllocation);


        if (Ret == S_OK && pD3DSurf->handleType == ATI_SURFACE)
        {
            // Check if surface has any outstanding locks
            pD3DSurf->dwLockCount--;
            if (pD3DSurf->dwLockCount == 0)
            {
                PULONGLONG  pliBitField=&pD3DSurf->liLockResSlotMaskLow;
                ULONGLONG   liBitMask=1;
                DWORD       dwResIdx=0;

                // Check if when this surface was locked the surface was in any resource slots
                while (pD3DSurf->liLockResSlotMaskLow != 0 || pD3DSurf->liLockResSlotMaskHigh != 0)
                {
                    PDWORD  pdwPm4;

                    // Check for wrapping to next 64 bit mask
                    if (dwResIdx == 64)
                    {
                        pliBitField++;
                        liBitMask=1;
                    }

                    // Was surface in resource slot when it was locked
                    if ( (*pliBitField & liBitMask) != 0)
                    {
                        // Has that resource slot got a new surface in it
                        if (pD3DCtxt->resSurfArray[dwResIdx] == (PVOID)pD3DSurf)
                        {
                            // Same surface so embed handle back in stream
                            pdwPm4=GetPM4Entries((1 + sizeof(D3DKMT_HANDLE)/sizeof(DWORD)), &pD3DCtxt->CmdBuff);

                            // Now place handle back into command stream
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
                            SubmitPM4EntriesToHw((1 + sizeof(D3DKMT_HANDLE)/sizeof(DWORD)), 0, &pD3DCtxt->CmdBuff);

                            // We have now placed the valid handle in the command stream, the driver thinks that
                            // the registers that use these handles have already been setup so we need
                            // to ensure the register write appears in the command stream so it can be patched
                            // correctly before used.
                            // For simplicity we will just dirty all the 3D register setup, a performance optimization
                            // would be to just to dirty the register this resource type uses.
                            SetAllDirtyBits(pD3DCtxt);
                        }

                        // Clear bit from bit field
                        *pliBitField &= ~liBitMask;
                    }

                    // Move to next bit
                    liBitMask = liBitMask << 1;
                    dwResIdx++;

                }
            }
        }
    }

    return Ret;
}


HRESULT
D3DDDIOpenResource(
    PDD_DIRECTDRAW_LOCAL            pDDLcl,
    PDD_DIRECTDRAW_GLOBAL           pDDGbl,
    D3DDDIARG_OPENRESOURCE*         pOpenResource,
    LPATID3DCNTX                    pD3DCtx,
    D3DDDI_RESOURCEFLAGS*           pResFlags,
    D3DDDI_VIDEO_PRESENT_SOURCE_ID* pVidPn)
{
    D3DDDIARG_CREATERESOURCE    sCRresData = {0};
    HRESULT                     RVal = E_FAIL;
    D3DDDI_SURFACEINFO*         psDummySurfList;
    R2DDICreateAllocationData*  pFirstPrivateDriverData;
    UINT                        Idx;
    R2DDICreateAllocationData*  pCurPrivateDriverData;

    // Now we have to construct a fake Create Resource data to feed to D3DDDICreateResource
    memset(&sCRresData, 0, sizeof(sCRresData));

    // Check size of PrivateDriver data is the correct size
    if (pOpenResource->pOpenAllocationInfo[0].PrivateDriverDataSize != sizeof(R2DDICreateAllocationData))
    {
        DBG_BREAK;
        return E_INVALIDARG;
    }
    pFirstPrivateDriverData=(R2DDICreateAllocationData*)pOpenResource->pOpenAllocationInfo[0].pPrivateDriverData;

    // Allocate mem for dummy create surf lists
    psDummySurfList = (D3DDDI_SURFACEINFO*)
#ifdef PRIVATE_HEAP
    HeapAlloc(g_Heap, HEAP_ZERO_MEMORY, sizeof(D3DDDI_SURFACEINFO) * pFirstPrivateDriverData->CreateDataSurfCount);
#else
    LocalAlloc(LMEM_ZEROINIT, sizeof(D3DDDI_SURFACEINFO) * pFirstPrivateDriverData->CreateDataSurfCount);
#endif
    if (psDummySurfList == NULL)
    {
        return E_OUTOFMEMORY;
    }

    // Setup dummy create data
    sCRresData.Format = pFirstPrivateDriverData->CreateDataFormat;
    sCRresData.Pool = pFirstPrivateDriverData->CreateDataPool;
    sCRresData.MultisampleType = pFirstPrivateDriverData->CreateDataMultisampleType;
    sCRresData.MultisampleQuality = pFirstPrivateDriverData->CreateDataMultisampleQuality;
    sCRresData.pSurfList = psDummySurfList;
    sCRresData.SurfCount = pFirstPrivateDriverData->CreateDataSurfCount;
    sCRresData.MipLevels = pFirstPrivateDriverData->CreateDataMipLevels;
    sCRresData.Fvf = pFirstPrivateDriverData->CreateDataFvf;
    sCRresData.VidPnSourceId = pFirstPrivateDriverData->CreateDataVidPnSourceId;
    sCRresData.Flags.Value = pFirstPrivateDriverData->CreateDataFlags.Value;
    sCRresData.hResource = pOpenResource->hResource;

#pragma prefast(disable:__WARNING_WRITE_OVERRUN, "PREfast for Drivers starts misinterpreting the length of psDummySurfList[Idx].Width")
    for (Idx=0; Idx < pOpenResource->NumAllocations; Idx++)
    {
        // Check PrivateDriver data is correct size
        if (pOpenResource->pOpenAllocationInfo[Idx].PrivateDriverDataSize != sizeof(R2DDICreateAllocationData))
        {
            DBG_BREAK;
            RVal = E_INVALIDARG;
            goto D3DDDIOpenResource_Cleanup;
        }
        pCurPrivateDriverData = (R2DDICreateAllocationData*)pOpenResource->pOpenAllocationInfo[Idx].pPrivateDriverData;
        psDummySurfList[Idx].Width= pCurPrivateDriverData->sAllocInfo.hslSurfDesc.dwWidth;
        psDummySurfList[Idx].Height = pCurPrivateDriverData->sAllocInfo.hslSurfDesc.dwHeight;
        psDummySurfList[Idx].Depth =  pCurPrivateDriverData->CreateDataSurfDepth;
        psDummySurfList[Idx].pSysMem = NULL;
        psDummySurfList[Idx].SysMemPitch = 0;
        psDummySurfList[Idx].SysMemSlicePitch = 0;
    }

    if (pOpenResource->NumAllocations != pFirstPrivateDriverData->CreateDataSurfCount)
    {
        HSLASSERT((pFirstPrivateDriverData->sAllocInfo.dwCaps & DDSCAPS_MIPMAP) != 0);

        for (Idx = 1; Idx < pFirstPrivateDriverData->CreateDataSurfCount; Idx++)
        {
            psDummySurfList[Idx].Width= MAX(psDummySurfList[Idx-1].Width/2, 1);
            psDummySurfList[Idx].Height = MAX(psDummySurfList[Idx-1].Height/2, 1);
            psDummySurfList[Idx].Depth =  MAX(psDummySurfList[Idx-1].Depth/2, 1);
            psDummySurfList[Idx].pSysMem = NULL;
            psDummySurfList[Idx].SysMemPitch = 0;
            psDummySurfList[Idx].SysMemSlicePitch = 0;
        }
    }
#pragma prefast(enable:386, "PREfast for Drivers is now OK")

    // Store res flags
    *pResFlags=sCRresData.Flags;
    *pVidPn=sCRresData.VidPnSourceId;

    RVal = D3DDDICreateResource(pDDLcl, pDDGbl, &sCRresData);
    if (FAILED(RVal))
    {
        DBG_BREAK;
    }

    // Now pass driver handle for resource back to runtime
    pOpenResource->hResource = sCRresData.hResource;

D3DDDIOpenResource_Cleanup:

#ifdef PRIVATE_HEAP
    HeapFree(g_Heap, 0, psDummySurfList);
#else
    LocalFree(psDummySurfList);
#endif

    return RVal;
}

DWORD GetCmdBufPreambleSize(LPVOID pvCtx);

QS_PARAM* _stdcall R200UpdateQSParamsForDXVASubmit(LPATID3DCNTX pD3DCtx, DWORD dwSize)
{
    pD3DCtx->lpCmdBuff->pQSParam->pList = (PVOID)((PBYTE)pD3DCtx->lpCmdBuff->pList + GetCmdBufPreambleSize(pD3DCtx));
    pD3DCtx->lpCmdBuff->pQSParam->dwListSize = dwSize;
    return pD3DCtx->lpCmdBuff->pQSParam;
}



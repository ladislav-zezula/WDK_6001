

//
//  $Workfile: surface.h $
//
//  Description:
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//

#ifndef _SURFACE_H_
#define _SURFACE_H_

// Rage6 Default Settings.
#define     PITCH_ALIGN                 64
#define     TILE_WIDTH                  256
#define     TILE_HEIGHT                 8
#define     TILE_SIZE                   (TILE_WIDTH*TILE_HEIGHT)
#define     SURFACE_ALIGN               (TILE_SIZE*2)

#define     TILE_SURFACE_ALIGN          (TILE_SIZE*2)
#define     MACRO_TILE                  4
#define     ATiSurfaceAlignment         PITCH_ALIGN
#define     YVU9PitchAlignment          (4*PITCH_ALIGN)
#define     YV12PitchAlignment          (2*PITCH_ALIGN)
#define     MAX_OVERLAY_WIDTH           3840*2

#define     LOCALVIDMEMHEAP             0
#define     INVALIDMEMHEAP              0x2
    
#define     MAX_SUPPORTED_MULTISAMPLES  6
#define     R200_FAMILY_ZPITCH_ALIGN  128     // Pitch defined in bytes for R200 family

// This offset is used to enable the high speed Z and DST surface reads.
// You have to align the DST and Z to a 8k starting address and then offset the Z by 4K
#define DSTAlignment     0x4000  //16K

#define ZPITCHAlignment 64       // z buffer pitch alignment in pixels.
#define ZHEIGHTAlignment 16      // z buffer height alignment in pixels.

#define SCRATCH_SURFACE_SIZE            0x40000
    
/*****************************************************************************/
//
// Video to System memory transfer constants
//
/*****************************************************************************/
#define STEPSIZE                        16
#define NUMOFSTEPS                      4
#define SCRATCH_MAX_WIDTH               2048

// Minimum width and height (in micro tile blocks) for macro tiling.
#define MIN_WIDTH_MACROTILING           8
#define MIN_HEIGHT_MACROTILING          8

// Minimum pitch (in bytes) for macro tiling.
#define MIN_PITCH_MACROTILING           256

#define PLANAR_SURFACE_ALIGN            SURFACE_ALIGN

#define ENTEREXCLUSIVEMODE  1    // Enter Exclusive Mode
#define EXITEXCLUSIVEMODE   0    // Exit Exclusive Mode

typedef DWORD (*ATICREATESURFACEFCN) (LPDDHAL_CREATESURFACEDATA lpCSData,
                                      LPDDRAWI_DIRECTDRAW_GBL lpDD,
                                      LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                                      DWORD dwHeap,
                                      DWORD dwCount);

// functions implemented in surface_texture.c
void CanCreateTextureSurface(LPDDHAL_CANCREATESURFACEDATA lpCCSData,
                             LPDDPIXELFORMAT lpDDPFPrimary);

DWORD CreateTextureSurface(LPDDHAL_CREATESURFACEDATA lpCSData,
                           LPDDRAWI_DIRECTDRAW_GBL lpDD,
                           LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                           DWORD dwHeap,
                           DWORD dwCount);

// functions implemented in surface_z.c
DWORD CreateZBufferSurface(LPDDHAL_CREATESURFACEDATA lpCSData,
                           LPDDRAWI_DIRECTDRAW_GBL lpDD,
                           LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                           DWORD dwHeap,
                           DWORD dwCount);

// functions implemented in surface_4cc.c
void CanCreateOverlaySurface(LPDDHAL_CANCREATESURFACEDATA lpCCSData,
                             LPDDPIXELFORMAT lpDDPFPrimary);

DWORD CreateFOURCCSurface(LPDDHAL_CREATESURFACEDATA lpCSData,
                          LPDDRAWI_DIRECTDRAW_GBL lpDD,
                          LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                          DWORD dwHeap,
                          DWORD dwCount);

// functions implemented in surface_misc.c
void CanCreate3DDevice(LPDDHAL_CANCREATESURFACEDATA lpCCSData,
                       LPDDPIXELFORMAT lpDDPFPrimary);

void CanCreateOffScreenPlainSurface(LPDDHAL_CANCREATESURFACEDATA lpCCSData,
                                    LPDDPIXELFORMAT lpDDPFPrimary);

DWORD CreateGenericSurface(LPDDHAL_CREATESURFACEDATA lpCSData,
                           LPDDRAWI_DIRECTDRAW_GBL lpDD,
                           LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                           DWORD dwHeap,
                           DWORD dwCount);

void DisableExclusiveMode(LPDDRAWI_DIRECTDRAW_GBL lpDD,
                         LPDDRAWI_DDRAWSURFACE_LCL lpSLCL);

// functions implemented in surface_alloc.c
DWORD ConvertPtchtoTiledPtch(DWORD dwBytePitch);
DWORD ConvertPtchtoZTiledPtch(DWORD dwBytePitch);

HRESULT AllocateVidMem(LPATIDXOBJECT lpATIDXObj,
                       LPDDRAWI_DIRECTDRAW_GBL lpDD,
                       DWORD dwHeap,
                       DWORD dwCaps,
                       DWORD dwFlags,
                       DWORD dwBytesPerPixel,
                       DWORD dwPitch,
                       DWORD dwPitchAlign,
                       DWORD dwHeight,
                       DWORD dwHeightAlign,
                       DWORD dwOffsetAlign,
                       DWORD bDXVARenderTarget,
                       DDHSLSURFACEDESC *pHSLSurfDesc,
                       DISP4DDVIDMEMDATA *pVidMemData,
                       PVOID pSysMem);

void ReleaseVidMem(LPATIDXOBJECT lpATIDXObj,
                   LPDDRAWI_DIRECTDRAW_GBL lpDD,
                   DWORD dwHeap,
                   DISP4DDVIDMEMDATA *pVidMemData);

BOOL ReallocateSystemScratchBuffer(LPATIDXOBJECT lpATIDXObj,
                                   VIDTOSYSSCRATCHINFO *poScratchInfo);

void FreeSystemScratchBuffer(LPATIDXOBJECT lpATIDXObj);
BOOL IsScratchBufferAllocated(LPATIDXOBJECT lpATIDXObj);

void UpdateATISurfInfo(LPATIDXOBJECT lpATIDXObj,
                       LPDDRAWI_DIRECTDRAW_GBL lpDD,
                       LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, 
                       DWORD dwHeap,
                       DWORD dwPitch,
                       DWORD dwPitchAlign,
                       DWORD dwOffsetAlign,
                       DWORD dwBytesPP,
                       DISP4DDVIDMEMDATA *pVidMemData);

void UpdateATITexSurfInfo(LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                          LPDDRAWI_DDRAWSURFACE_LCL lpSLCLBaseMap,
                          DWORD dwMipIndex);

BOOL AllocateSurface(LPATIDXOBJECT lpATIDXObj,
                     LPDDRAWI_DIRECTDRAW_GBL lpDD,
                     LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, 
                     DWORD dwHeap,
                     DWORD dwPitch,
                     DWORD dwPitchAlign,
                     DWORD dwHeight,
                     DWORD dwHeightAlign,
                     DWORD dwOffsetAlign);

void FreeSurface(LPATIDXOBJECT lpATIDXObj,
                 LPDDRAWI_DIRECTDRAW_GBL lpDD,
                 LPDDRAWI_DDRAWSURFACE_LCL lpSLCL);

BOOL SetSurfaceTilingAperture(LPATIDXOBJECT lpATIDXObj, LPDDRAWI_DDRAWSURFACE_LCL lpSLCL);
BOOL FreeSurfaceTilingAperture(LPATIDXOBJECT lpATIDXObj, LPDDRAWI_DDRAWSURFACE_LCL lpSLCL);

BOOL CreateOffscreenSurface(LPDDRAWI_DIRECTDRAW_GBL lpDD, LPDDRAWI_DDRAWSURFACE_LCL lpSLCL, DWORD dwHeap);

#endif //_SURFACE_H_


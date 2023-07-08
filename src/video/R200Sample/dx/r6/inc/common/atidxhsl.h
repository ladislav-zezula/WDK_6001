

/*****************************************************************************\
*
*  Module Name    atidxhsl.h
*  Project        Rage Win9x/W2K  HAL Support Layer
*  Device         Rage
*
*  Description   Declaration of interface between ATI D3D lib and DD HAL
*
*
*  Copyright (c) 2000-2001 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*
\*****************************************************************************/

#ifndef  _ATIDXHSL_H
#define  _ATIDXHSL_H

#include "atiddhsl.h"
#include <d3dumddi.h>

//***************************************************************************
//* HSL revisions ( Additions )                                       *
//***************************************************************************

#define D3DHSL_VERSION_MAJOR    0x00000003
#define D3DHSL_VERSION_MINOR    0x00000001

#define D3DHSL_VERSION  (((DWORD)D3DHSL_VERSION_MAJOR<<16) | D3DHSL_VERSION_MINOR)

//****************************************************************************
//* D3DHSL Return Codes                                                      *
//****************************************************************************
#define D3DHSL_OK                   0x00000000
#define D3DHSL_VERSIONMISMATCH      0x00000001
#define D3DHSL_OUTOFMEMORY          0x00000002
#define D3DHSL_GENERIC              0x00000003

//****************************************************************************
//* HSL HANDLES                                                              *
//****************************************************************************
typedef LPVOID DDHSLATISURFHANDLE;
typedef LPVOID DDHSLD3DSURFHANDLE;
typedef LPVOID DDHSLVERTEXSURFHANDLE;


#define DDHSLHZMEM_ZMASK 0
#define DDHSLHZMEM_HIZ   1

//**************************** DDHSL functions ********************************
//* The following is the public interface of the D3D library (as defined      *
//* in HSL spec. These are the only functions that D3D should be calling      *
//* from DirectDraw.                                                          *
//*****************************************************************************

// Reads the D3DDEVICE pointer from the DD-HAL corresponding
// to pDevInfo. Since the source variable for pDevInfo is typed
// differently in 9x vs Win2K, it is passed here as an LPVOID.
// This function should no longer be used to fetch the
// D3DDEVICE pointer from a ATIDXOBJECT directly.
extern struct _D3DDEVICE* APIENTRY pDdHslQueryD3DDevice(LPVOID pDevInfo);

// Surface flag masks, they are defined the same way as the CH_ flags in Win2K.
// When pDdHslQueryATISurfInfo() is called with E_SURF_FLAGS, those defines
// will be used to mask out certain field in the surface flag.
#define HSL_SURF_IS_TILED           0x02000000
#define HSL_SURF_IS_MICROTILED      0x40000000
#define HSL_SURF_NEEDS_CRTC_SYNC    0x00000004

// Additional surface flag masks.
#define HSL_SURF_IS_AA_BACKBUFFER   0x00000010  // Back buffer for AA.
#define HSL_SURF_IS_AA_Z            0x00000020  // Z buffer for AA.

typedef LPVOID DDHSLATISURFHANDLE;

extern LPDWORD APIENTRY
    pDdHslQueryATISurfInfo3( DDHSLATISURFHANDLE hATISurfInfoHandle, EDDHSLQUERY eFlag );

extern VOID APIENTRY
 vDdHslVideoMemoryAllocWithCaps( LPVOID  pDevInfo,
                               LPDDRAWI_DIRECTDRAW_GBL FAR lpGbl,
                               DWORD dwBytes,
                               DDHSLVIDMEMDATA  *pDdHslVidMemData,
                               EDDHSLVIDMEMHEAP eSpace,
                               DWORD dwSurfCaps
                               );

// Interface to allow D3D to wait on the DDraw Flip Queue
extern VOID APIENTRY vDdHslSyncSurface(LPVOID pDevInfo,
                                       LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                                       DDHSLATISURFHANDLE  hATISurf);

extern BOOL APIENTRY bDdHslIsSurfNeedCRTC_SYNC(LPVOID pDevInfo,
                                               DDHSLATISURFHANDLE  hATISurf);

// Determines if a queued flip has occurred or not.
extern BOOL APIENTRY bDdHslIsFlipFinished( LPVOID pDevInfo,
                                           LPDDRAWI_DDRAWSURFACE_LCL lpSLCLTarg,
                                           DWORD dwNumFlipsBackInTime );

extern VOID APIENTRY
vDdHslSyncSurface3( LPVOID pDevInfo, DDHSLATISURFHANDLE hATISurfInfoHandle );

// Surface Description used to pass surface information between
// D3D and DirectDraw through TexBlt.
//
// NOTE: For WOW64 on AM64, pads are put in to align data properly,
//       so that 32bit UMD and 64bit KMD can share the data struture.
//
typedef struct _DDHSLSURFACEDESC
{
    DWORD dwSurfaceHandle;  //The surface handle assigned by DirectX
    DWORD dwFlags;
    DWORD dwBPP;
    DWORD dwWidth;
    DWORD dwHeight;
    DWORD dwVolBltDepth;
    LONG lPitch;
    LONG lSlicePitch;
    DWORD dwCaps;
    DWORD dwGMCWidth;
    FLATPTR fpVidMem;
#ifdef WOW6432
    DWORD dwPad0;
#endif
    INT_PTR dwMCOffset;
#ifdef WOW6432
    DWORD dwPad1;
#endif
    LPDDPIXELFORMAT lpddPixelFormat;
#ifdef WOW6432
    DWORD dwPad2;
#endif
    DDHSLD3DSURFHANDLE hSurfInfoHandle;
#ifdef WOW6432
    DWORD dwPad3;
#endif
    DDHSLATISURFHANDLE hATISurfInfoHandle;
#ifdef WOW6432
    DWORD dwPad4;
#endif

#if defined(KMD) || defined(UMD)
    D3DKMT_HANDLE hAllocation;
#endif
#ifdef WOW6432
    DWORD dwPad5;
#endif
} DDHSLSURFACEDESC, *LPDDHSLSURFACEDESC;

// Used in vD3dHslNotifyDdEvent()
typedef enum
{
    E_DDHAL_VSYNCFLIPSUCCEED        = 1,
    E_DDHAL_NOVSYNCFLIPSUCCEED      = 2,
    E_DDHAL_PRESENTBLTSUCCEED       = 3,
    E_DDHAL_FLIPFAIL                = 4,
    E_DDHAL_CMDBUFFSUBMIT           = 5,
    E_DDHAL_EXCLUSIVEMODE_LEAVE     = 6,
    E_DDHAL_FLIP                    = 7,
    E_DDHAL_ZBUFFERMODIFIED         = 8,
    E_DDHAL_FULLZBDEPTHFILL         = 9,
    E_DDHAL_LOCK_ZBUFFER            = 10,
    E_DDHAL_CREATED3DRT             = 11,
    E_DDHAL_COLORFILL               = 12,
    E_DDHAL_OUTOFVIDMEMORY          = 13,
    E_DDHAL_FORCEDWORD              = 0x7FFFFFFF
} EDDHSLDDHALEVENT;

enum DDHSLANTIALIAS_SURFACETYPES
{
    AASURFACE_NOAA         = 0,
    AASURFACE_RENDERTARGET = 1,
    AASURFACE_ZBUFFER      = 2,
    AASURFACE_ACTIVE       = 4, //Indicates that AA is currently on for the surface.
    AASURFACE_POSSIBLEAA   = 8  //Indicates that the AA surface currenlty does not exist, but when
                                //AA is enabled this surface may be a one in which an AA buffer will be
                                //assiocated with.
};

typedef struct _DDHSLANTIALIAS_SURFINFO
{
    DWORD dwAASurfType;
    float xRatio;
    float yRatio;
    DWORD dwAAWidth;
    DWORD dwAAHeight;
    DWORD dwAABytePitch;
    DWORD_PTR dwAASurfOffset;
    FLATPTR fpAAAlignedVidMem;
    ULONG_PTR hSurface;

    union
    {
        DWORD dw1xWidth;
        DWORD dwAABytesPerPixel;
    };

    union
    {
        DWORD dw1xHeight;
        DWORD dwFCCDepthOffset;
    };

    union
    {
        DWORD dw1xBytePitch;
        DWORD dwFCCHeight;
    };

    union
    {
        DWORD dwReserved1;
        DWORD dwTilingFlags;
    };

    BOOL bOnlyCalcAllocSize;
    DWORD_PTR dw1xSurfOffset;
    ULONG_PTR h1xSurface;
    FLATPTR fp1xAlignedVidMem;

} DDHSLANTIALIAS_SURFINFO, *LPDDHSLANTIALIAS_SURFINFO;

// Utility function to populate a surface description given
// a surface.
extern void APIENTRY
vDdHslLoadSurfaceDesc3(LPDDRAWI_DDRAWSURFACE_LCL lpSurface,
                       LPDDHSLSURFACEDESC lpddHslSurfDesc);

// Causes DDraw to perform a texture BLT.
extern BOOL APIENTRY bDdHslExecuteTexBlt3(LPVOID pDevInfo,
                                          LPDDRAWI_DIRECTDRAW_GBL lpGbl,
                                          LPDDHSLSURFACEDESC lpDDHSLSurfDescSrc,
                                          LPDDHSLSURFACEDESC lpDDHSLSurfDescDst,
                                          LPRECTL lprSrc, LPRECTL lprDst,  LPPOINT lpDestPt);

extern BOOL APIENTRY bDdHslExecuteSurfaceBlt( LPVOID pDevInfo,
                                              LPDDRAWI_DIRECTDRAW_GBL lpGbl,
                                              LPDDHSLSURFACEDESC lpDDHSLSurfDescSrc,
                                              LPDDHSLSURFACEDESC lpDDHSLSurfDescDst,
                                              LPRECTL lprSrc, LPRECTL lprDst,  LPPOINT lpDestPt, DWORD BltFlag);

extern DWORD APIENTRY vDdHslAllocAASurface(LPVOID lpDXObj,
                                           LPDDRAWI_DIRECTDRAW_GBL lpDDGbl,
                                           LPDDHSLANTIALIAS_SURFINFO lpAASI,
                                           DDHSLVIDMEMDATA *lpDDHSLVidMem);

//**************************** D3DHSL functions, defines. *********************
//* The following is the public interface of the D3D library (as defined      *
//* in HSL spec. These are the only functions that DirectDraw should be       *
//* calling from D3D.                                                         *
//*****************************************************************************

// This function performs initialization of the D3D HAL including
// allocation and initialization of D3DDEVICE struct, setting CAPs
// and call backs through pDdHalInfo
extern DWORD APIENTRY
dD3dHslInit(LPVOID pDevInfo, LPDDHALINFO pDdHalInfo, DWORD dwVersion, struct _D3DDEVICE** ppD3DDev);

// Frees QS resources related to D3DDevice and frees D3DDevice structure.
extern VOID  APIENTRY vD3dHslExit(struct _D3DDEVICE *pD3DDev);

// This function enables the D3D HAL ready for use by the runtime.
// Performs additional initialization, including QS initialization.
extern BOOL  APIENTRY bD3dHslEnable(struct _D3DDEVICE *pD3DDev);

// Frees QS resources and video memory allocated for d3d contexts.
extern VOID  APIENTRY vD3dHslDisable(struct _D3DDEVICE *pD3DDev);

// This function allows the DDHAL to enquire of the D3DHAL if
// it has support for various extensions
extern DWORD APIENTRY dD3dHslGetDriverInfo(struct _D3DDEVICE * pD3DDev,
                                    LPDDHAL_GETDRIVERINFODATA lpDrvData);

// This function gives notice to D3DHAL that DDHAL is about
// to destroy a surface.
extern void APIENTRY vD3dHslDestroySurface( struct _D3DDEVICE *pD3DDev,
                                            LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                                            LPDDRAWI_DIRECTDRAW_GBL   pDDGbl );

#ifdef UMD
void DeallocateD3DHSLSurfSlot(struct _D3DDEVICE *pD3DDevice, struct HSLSurfInfo *lpSurfInfo);
#endif

// This function instructs the D3DHAL to flush any command buffers
// associated with this surface.
extern VOID  APIENTRY vD3dHslSurfaceFlush(struct _D3DDEVICE *pD3DDev,
                                   LPDDRAWI_DDRAWSURFACE_LCL lpSLCL);

extern HRESULT  APIENTRY vD3dHslSurfaceFlush3( struct _D3DDEVICE *pD3DDev,
                                            DDHSLD3DSURFHANDLE hSurfInfo,
                                            DWORD dwSurfaceHandle );

//This function is used to flush all pending command buffers in all D3D contexts.
extern HRESULT vD3DHSLFlushAllCmdBuffers(struct _D3DDEVICE *pD3DDev);

extern BOOL APIENTRY bD3dHslUpdateSurfColorKeyInfo( LPDDHAL_SETCOLORKEYDATA lpSCKData );

// This function give D3DHAL the opportunity to build its own
// HSLSURFINFO struct for a surface. This is needed since D3DHAL
// and DDHAL do not share pointers to surface structs any more.
extern BOOL  APIENTRY bD3dHslBuildSurfaceInfo(struct _D3DDEVICE *pD3DDev,
                                       LPDDRAWI_DDRAWSURFACE_LCL lpSLCL);

// This function is called to ensure that all drawing operations
// pending on this surface are complete prior to return.
// Called during the DDHAL Lock32 operation
extern BOOL  APIENTRY bD3dHslSurfaceLock(struct _D3DDEVICE *pD3DDev,
                                  LPDDRAWI_DDRAWSURFACE_LCL lpSLCL);

// This function is called to notify the D3DHAL of a DDHAL Unlock32
// operation to the surface. If super sample antialiasing is enabled,
// this may require a blt of data from pSurface to an AA surface.
extern BOOL  APIENTRY bD3dHslSurfaceUnlock(struct _D3DDEVICE *pD3DDev,
                                    LPDDRAWI_DDRAWSURFACE_LCL lpSLCL);

//This function checks if a Surface is in use by 3D.
extern BOOL APIENTRY bD3dHslCheck3DTSRetired( struct _D3DDEVICE *pD3DDev,
                          LPDDRAWI_DDRAWSURFACE_LCL pSurface );

extern BOOL APIENTRY bD3dHslCheck3DTSRetired3( struct _D3DDEVICE *pD3DDev,
                                               DDHSLD3DSURFHANDLE hSurfInfoHandle,
                                               DWORD dwSurfaceHandle);

//This function is called from DDraw Blt to impliment the DDBLT_DEPTHFILL
//Blt. It uses hardware rendering.
extern BOOL APIENTRY bD3dHslBltDepthFill( struct _D3DDEVICE *pD3DDev,
                                   LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                                   RECTL *lpRect, DWORD dwFillDepth,
                                   DWORD dwZBitDepth, BOOL bAAZBuffer);

// For vertex buffer communication between DD-HAL and D3D-HAL
extern DWORD APIENTRY dD3dHslCreateVertexBuffs (struct _D3DDEVICE *pD3DDev,
                                         LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                                         LPDDSURFACEDESC2 lpSurfDesc2,
                                         LPDDRAWI_DIRECTDRAW_GBL lpDDGbl);
extern DWORD APIENTRY dD3dHslDestroyVertexBuffs(struct _D3DDEVICE *pD3DDev,
                                         DDHSLVERTEXSURFHANDLE hVb);
extern DWORD APIENTRY dD3dHslLockVertexBuffs   (struct _D3DDEVICE *pD3DDev,
                                         LPDDHAL_LOCKDATA lpLockData,
                                         FLATPTR *fpVidMem,  BOOL *pbAGPBuffer);
extern DWORD APIENTRY dD3dHslUnlockVertexBuffs (struct _D3DDEVICE *pD3DDev,
                                         DDHSLVERTEXSURFHANDLE hVb);
extern DWORD APIENTRY dD3dHslCanCreateVtxBuff( struct _D3DDEVICE *pD3DDev,
                                        LPDDSURFACEDESC2 lpSurfDesc2 );


// Interface to DDraw to notify D3D of a DdHal event.
// Useful for performance and statistics gathering.
// Initially used for FlipFail and FlipSucceed events
// for performance and statistics gathering.
extern VOID APIENTRY vD3dHslNotifyDdEvent( struct _D3DDEVICE *pD3DDev,
                                    LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                                    EDDHSLDDHALEVENT eDdEvent,
                                    LPDWORD pEventInfo);

extern DWORD APIENTRY dD3dHslGetAntiAliasSurfaceInfo( struct _D3DDEVICE *pD3DDev,
                                                     LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                                                     LPDDHSLANTIALIAS_SURFINFO lpAASI );

extern BOOL APIENTRY bD3dHslSetUpAABlendScaleBltInfo( struct _D3DDEVICE *lpD3DDev,
                                                      LPDDRAWI_DDRAWSURFACE_LCL lpD3DRTSrcSLCL,
                                                      LPDDRAWI_DDRAWSURFACE_LCL lpDstSLCL,
                                                      struct _BLENDED_SCALEBLT_INFO *BlendInfo,
                                                      RECTL *SrcRect, RECTL *DstRect );

extern BOOL APIENTRY bD3dHslRTBltToAART( struct _D3DDEVICE *lpD3DDev,
                                         LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                                         LPRECTL lpRect );

// Interface to allow DDraw get R200 family bugs list
extern DWORD APIENTRY dD3DHslQuery3D2BugsList(LPVOID lpATIDXObj);

void APIENTRY bD3dHslRTBltFromAART( struct _D3DDEVICE *lpD3DDev,
                                    LPDDRAWI_DDRAWSURFACE_LCL lpSLCL );

#if (DIRECT3D_VERSION >= 0x0900)
extern BOOL APIENTRY bDdHslExecuteBlt( LPVOID AtiDxObj,
                                       LPVOID DDHslSurfDescSrc,
                                       LPVOID DDHslSurfDescDst,
                                       LPDDHAL_BLTDATA DDHalBltData );

extern BOOL APIENTRY bDdHslExecuteColorfill( LPVOID AtiDxObj,
                                             LPVOID DDHslSurfDesc,
                                             LPRECTL lpRect,
                                             DWORD Color );

extern BOOL APIENTRY bDdHslGenMipMapTexBlt(LPVOID pDevInfo,
                                           LPDDRAWI_DIRECTDRAW_GBL lpGbl,
                                           LPDDHSLSURFACEDESC lpDDHSLSurfDescSrc,
                                           LPDDHSLSURFACEDESC lpDDHSLSurfDescDst,
                                           LPRECTL lprSrc, LPRECTL lprDst, LPPOINT lpDestPt,
                                           DWORD dwBltFlags, BOOL bLWMipmap);

#endif //(DIRECT3D_VERSION >= 0x0900)

#endif   //_ATIDXHSL_H


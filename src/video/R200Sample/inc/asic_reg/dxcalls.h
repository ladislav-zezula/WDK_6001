// This file defines all D3D entry points required for the 2D driver
// This replaces the previous structure  where function pointers were 
// stored in globals in d3d_loader giving the ability to have 
// multiple different asics in one system and all being accelerated

// If additional functionality is required, it is recommended
// (although not necessary) that new functions be added to the end
// of the DXCALLS strucure.  

// ncooper [01/12/07]

//  Typedefs for all functions that the 2D driver will want to call


//
// GDI3D structures and functions
//
#include "atigdi3d.h"
#include "r2d3dddi.h"

#ifndef _GDI3DAPI
#define _GDI3DAPI

typedef struct _GDI3DSTRBLT
{
    DWORD       dwSize;

    DWORD       dwSrcOffset;
    BOOL        dwSrcMacroTile;
    DWORD       dwSrcMicroTile; 
    DWORD       dwSrcLeft;
    DWORD       dwSrcTop;
    DWORD       dwSrcRight;
    DWORD       dwSrcBottom;
    DWORD       dwSrcSurfWidth;
    DWORD       dwSrcSurfHeight;
    DWORD       dwSrcDataType;

    DWORD       dwDstOffset; 
    BOOL        dwDstMacroTile;
    DWORD       dwDstMicroTile; 
    DWORD       dwDstLeft;
    DWORD       dwDstTop;
    DWORD       dwDstRight;
    DWORD       dwDstBottom;
    DWORD       dwDstSurfWidth;
    DWORD       dwDstSurfHeight;
    DWORD       dwDstPixFmt;

    DWORD       dwNumClipRects;  // Number of clip rectangles
    RECTL       *prclClip;       // Array of clip rectangles
} GDI3DSTRBLT, *PGDI3DSTRBLT;

typedef struct _GDI3DALPHABLT
{
    DWORD       dwSize;

    DWORD       dwSrcOffset; 
    BOOL        dwSrcMacroTile; 
    DWORD       dwSrcMicroTile;
    DWORD       dwSrcLeft; 
    DWORD       dwSrcTop;
    DWORD       dwSrcRight;
    DWORD       dwSrcBottom;
    DWORD       dwSrcSurfWidth;
    DWORD       dwSrcSurfHeight;
    DWORD       dwSrcDataType; 

    DWORD       dwDstOffset; 
    BOOL        dwDstMacroTile; 
    DWORD       dwDstMicroTile;
    DWORD       dwDstLeft; 
    DWORD       dwDstTop;
    DWORD       dwDstRight;
    DWORD       dwDstBottom;
    DWORD       dwDstSurfWidth;
    DWORD       dwDstSurfHeight;
    DWORD       dwDstPixFmt;

    BOOL        bSrcAlpha;       // Source alpha enable
    DWORD       dwSrcConstAlpha; // Source constant alpha value

    DWORD       dwNumClipRects;  // Number of clip rectangles
    RECTL       *prclClip;       // Array of clip rectangles
} GDI3DALPHABLT, *PGDI3DALPHABLT;
    
typedef struct _GDI3DGRADFILL
{
    DWORD       dwSize;

    DWORD       dwDstOffset;
    BOOL        dwDstMacroTile;
    DWORD       dwDstMicroTile; 
    DWORD       dwDstSurfWidth; 
    DWORD       dwDstSurfHeight;
    DWORD       dwDstPixFmt;

    DWORD       dwFillMode;      // GRADIENT_FILL_XXX mode
    LPTRIVERTEX pVertex;         // Must be in upper-left and lower-left
                                 // order for rectangle

    DWORD       dwNumClipRects;  // Number of clip rectangles
    RECTL       *prclClip;       // Array of clip rectangles
} GDI3DGRADFILL, *PGDI3DGRADFILL; 

typedef struct _GDI3DAATEXTOUT
{
    DWORD       dwSize;

    DWORD       dwSrcOffset; 
    BOOL        dwSrcMacroTile; 
    DWORD       dwSrcMicroTile;
    DWORD       dwSrcLeft; 
    DWORD       dwSrcTop;
    DWORD       dwSrcRight;
    DWORD       dwSrcBottom;
    DWORD       dwSrcSurfWidth;
    DWORD       dwSrcSurfHeight;

    DWORD       dwDstOffset; 
    BOOL        dwDstMacroTile; 
    DWORD       dwDstMicroTile;
    DWORD       dwDstLeft; 
    DWORD       dwDstTop;
    DWORD       dwDstRight;
    DWORD       dwDstBottom;
    DWORD       dwDstSurfWidth;
    DWORD       dwDstSurfHeight;
    DWORD       dwDstPixFmt;

    DWORD       dwSrcConstColor; // Source constant color value

    DWORD       bDstConstColor;  // Has solid background color
    DWORD       dwDstConstColor; // Solid background color

    DWORD       dwNumClipRects;  // Number of clip rectangles
    RECTL       *prclClip;       // Array of clip rectangles
} GDI3DAATEXTOUT, *PGDI3DAATEXTOUT;
    
typedef struct _GDI3DSOLIDFILL
{
    DWORD       dwSize;

    DWORD       dwDstOffset;
    BOOL        dwDstMacroTile;
    DWORD       dwDstMicroTile;
    DWORD       dwDstLeft;
    DWORD       dwDstTop;
    DWORD       dwDstRight;
    DWORD       dwDstBottom;
    DWORD       dwDstSurfWidth;
    DWORD       dwDstSurfHeight;
    DWORD       dwDstPixFmt;

    DWORD       dwFillValue;     // Source constant alpha value

    DWORD       dwNumClipRects;  // Number of clip rectangles
    RECTL       *prclClip;       // Array of clip rectangles
} GDI3DSOLIDFILL, *PGDI3DSOLIDFILL;

extern VOID APIENTRY vGDI3DStretchBlt(
    LPVOID      lpDxObj,
    GDI3DSTRBLT *pStrBlt);

extern VOID APIENTRY vGDI3DAlphaBlt(
    LPVOID          lpDxObj,
    GDI3DALPHABLT *pAlphaBlt);

extern VOID APIENTRY vGDI3DGradientFill(
    LPVOID        lpDxObj,
    GDI3DGRADFILL *pGradFill);

extern VOID APIENTRY vGDI3DAATextOut(
    LPVOID         lpDxObj,
    GDI3DAATEXTOUT *pAATextOut);

extern VOID APIENTRY vGDI3DSolidFill(
    LPVOID         lpDxObj,
    GDI3DSOLIDFILL *pSolidFill);

#endif //_GDI3DAPI

//
// DD4DISP functions

#ifdef D3D_LOADER_API_VERSION
#ifndef __DXCALLS_H__
#define __DXCALLS_H__

typedef BOOL (APIENTRY *PBDD4DISPINITDD) (LPVOID pDevObj, 
                                    CMM_HDEVICE CMMDevHandle, 
                                    HANDLE hDriverHandle,
                                    LPVOID *ppDXObj,
                                    LPDDHALINFO lpDDHALInfo,
                                    PR200AdapterInfo pR200AdapterInfo,
                                    LPDWORD lpdwNumFourCC,
                                    LPDWORD lpdwFourCC);

typedef BOOL (APIENTRY *PBDD4DISPENABLEDD) (LPVOID lpDXObj);


typedef void (APIENTRY *PVDD4DISPSETDDCALLBACKS) (LPVOID lpDXObj,
                                            LPDDHAL_DDCALLBACKS lpDDCallbacks, 
                                            LPDDHAL_DDSURFACECALLBACKS lpDDSurfaceCallbacks);

typedef void (APIENTRY *PVDD4DISPDISABLEDD) (LPVOID lpDXObj);
typedef void (APIENTRY *PVDD4DISPEXITDD) (LPVOID lpDXObj);

typedef ULONG_PTR (APIENTRY *PPDD4DISPDERIVESURFACE) (LPVOID lpDXObj, 
                                             LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                                             CMM_HCLIENT *lpCMMClient);

typedef void (APIENTRY *PVDD4DISPHANDLEPANCALLBACK) (LPVOID lpDXObj, 
                                               RECTL* prctlScreen, 
                                               RECTL* prctlPanLock, 
                                               RECTL* prctlView);

typedef VOID (APIENTRY *PVD3DHSLSETDRIVERCALLS) (DRIVERCALLS* DriverCalls);

typedef BOOL (APIENTRY *PBD3DHSLSETDRIVERCALLSEX) (DWORD dwAPIVersionRequired, DRIVERCALLS_EX* DrvCallsEx);

//fv-26Nov01-new function pointer for NT 2D Driver to access vplib function, now linked into D3D_DLL
typedef DWORD (APIENTRY *LPVPEACCESSCALLBACK) (LPVOID  ppdev, ULONG ulInSize, LPVOID lpInData, ULONG ulOutSize, LPVOID lpOutData);

//DVD
typedef VOID (APIENTRY *PVDVDHSLUPDATEPDEV) (LPVOID lpDVDDevObj, 
                                               LPVOID ppdev, 
                                               LPVOID lpATIDXObject);

// BEGIN DX_UDA
typedef VOID (APIENTRY *PVDD4DISPRESETDXOBJ) (LPVOID lpDXObjOld,
                                              LPVOID lpDXObjNew);

typedef VOID (APIENTRY *PVGDI3DSTRETCHBLT) (LPVOID lpDXObj,
                                            GDI3DSTRBLT *pStrBlt);

typedef VOID (APIENTRY *PVGDI3DALPHABLT) (LPVOID lpDXObj,
                                          GDI3DALPHABLT *pAlphaBlt);

typedef VOID (APIENTRY *PVGDI3DGRADIENTFILL) (LPVOID lpDXObj,
                                              GDI3DGRADFILL *pGradFill);

typedef VOID (APIENTRY *PVGDI3DAATEXTOUT) (LPVOID lpDXObj,
                                           GDI3DAATEXTOUT *pAATextOut);

typedef VOID (APIENTRY *PVGDI3DSOLIDFILL) (LPVOID lpDXObj,
                                           GDI3DSOLIDFILL *pSolidFill);

#ifndef PDD4DISPDESCRIBESURFACE
#ifndef _PDD4DISPDESCRIBESURFACE
#define PDD4DISPDESCRIBESURFACE PVOID
#endif
#endif

typedef BOOL (APIENTRY *PBDD4DISPDESCRIBESURFACE) (LPVOID lpDXObj, 
                                         LPDDRAWI_DDRAWSURFACE_LCL lpLCL,
                                         PDD4DISPDESCRIBESURFACE   pDescSurf);
// END DX_UDA


typedef struct
{
    DWORD                           dwSize;         //size of structure in bytes
    LPVOID                          pDevObj;        //2D PDEV
    HANDLE                          hD3ddll;        //handle of D3Ddll for this pdev
    PBDD4DISPINITDD                 pfnbDD4DISPInitDD;            //00
    PBDD4DISPENABLEDD               pfnbDD4DISPEnableDD;          //01
    PVDD4DISPSETDDCALLBACKS         pfnvDD4DISPSetDDCallBacks;    //02
    PVDD4DISPDISABLEDD              pfnvDD4DISPDisableDD;         //03
    PVDD4DISPEXITDD                 pfnvDD4DISPExitDD;            //04
    PPDD4DISPDERIVESURFACE          pfnpDD4DISPDeriveSurface;     //05
    PVDD4DISPHANDLEPANCALLBACK      pfnvDD4DISPHandlePanCallback; //06

    LPDDHSLVIDEOMEMORYALLOC         pfnvDdHslVideoMemoryAlloc;    //07
    LPDDHSLVIDEOMEMORYFREE          pfnbDdHslVideoMemoryFree;     //08

    PPDDHSLQUERYDEVICEOBJECT        pfnpDdHslQueryDeviceObject;   //09
    PBDDHSLQUERYCIINFO              pfnbDdHslQueryCIInfo;         //10

    LPDDHSLQUERYREGISTRYVALUE       pfnbDdHslQueryRegistryValue;  //11
    LPDDHSLESCAPE                   pfndDdHslEscape;              //12
    PVDVDHSLUPDATEPDEV              pfnvDVDHSLUpdatePDEV;         //13
    LPVPEACCESSCALLBACK             pfndwVPEAccessCallback;       //14
    // BEGIN DX_UDA
    PVDD4DISPRESETDXOBJ             pfnvDD4DISPResetDxObj;        //15
    PVGDI3DSTRETCHBLT               pfnvGDI3DStretchBlt;          //16
    PVGDI3DALPHABLT                 pfnvGDI3DAlphaBlt;            //17
    PVGDI3DGRADIENTFILL             pfnvGDI3DGradientFill;        //18
    PVGDI3DAATEXTOUT                pfnvGDI3DAATextOut;           //19
    PVGDI3DSOLIDFILL                pfnvGDI3DSolidFill;           //20
    PBDD4DISPDESCRIBESURFACE        pfnbDD4DISPDescribeSurface;   //21
    // END DX_UDA

} DXCALLS,*PDXCALLS;

PDXCALLS pDXCallsFromDevObj(LPVOID lpDevObj);
#endif // __DXCALLS_H__

#endif // D3D_LOADER_API_VERSION





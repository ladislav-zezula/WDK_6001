#ifndef ATIDISPDD_H
#define ATIDISPDD_H

#include "qs.h"
#include "cmm.h"
#include <d3dumddi.h>

typedef struct _R200AdapterInfo R200AdapterInfo, *PR200AdapterInfo;

/**********************************************************************
    Exported/shared library functions, these functions are called 
    from the display driver.
***********************************************************************/

extern BOOL APIENTRY bDD4DISPInitDD(LPVOID pDevObj,
                                    CMM_HDEVICE CMMDevHandle, 
                                    HANDLE hDriverHandle,
                                    LPVOID *ppDXObj,
                                    LPDDHALINFO lpDDHALInfo,
                                    PR200AdapterInfo pR200AdapterInfo,
                                    LPDWORD lpdwNumFourCC,
                                    LPDWORD lpdwFourCC);

extern BOOL APIENTRY bDD4DISPEnableDD(LPVOID lpDXObj);

extern void APIENTRY vDD4DISPSetDDCallBacks(LPVOID lpDXObj,
                                            LPDDHAL_DDCALLBACKS lpDDCallbacks, 
                                            LPDDHAL_DDSURFACECALLBACKS lpDDSurfaceCallbacks);

extern void APIENTRY vDD4DISPDisableDD(LPVOID lpDXObj);
extern void APIENTRY vDD4DISPExitDD(LPVOID lpDXObj);


extern void APIENTRY vDD4DISPHandlePanCallback(LPVOID lpDXObj, 
                                               RECTL* prctlScreen, 
                                               RECTL* prctlPanLock, 
                                               RECTL* prctlView);

#ifdef WIN2K
extern CMM_HSURF APIENTRY pDD4DISPDeriveSurface(LPVOID lpDXObj, 
                                                LPDDRAWI_DDRAWSURFACE_LCL lpSLCL,
                                                CMM_HCLIENT *lpCMMClient);
#endif

//
// NOTE: For WOW64 on AM64, pads are put in to align data properly,
//       so that 32bit UMD and 64bit KMD can share the data struture.
//
typedef struct _DISP4DDVIDMEMDATA
{
    union
    {
#if defined(UMD) || defined(KMD)
        D3DKMT_HANDLE      hAllocation;
#endif
        LPVOID      lpVideoMemory;  // 32bit linear address in ring 0 space.
    };
#ifdef WOW6432
    DWORD       dwPad0;
#endif
    ULONG_PTR   hSurface;           // Cache handle of the allocated memory, null for win9x.
                                    // When CMM is used this is the CMM surface handle.
#ifdef WOW6432
    DWORD       dwPad1;
#endif
    DWORD_PTR   dwMCOffset;         // MC offset.
#ifdef WOW6432
    DWORD       dwPad2;
#endif
    LPVOID      lpRing3Addr;        // 32bit linear address in ring 3 space (for win2k agp memory).
                                    // When CMM is used this will be availible for both local and agp memory
#ifdef WOW6432
    DWORD       dwPad3;
#endif
} DISP4DDVIDMEMDATA;

#ifdef UMD
__inline D3DKMT_HANDLE GetVidMemAllocHandle(DISP4DDVIDMEMDATA *pVidMem)
{
    return (pVidMem->hAllocation);
}
#else
__inline HANDLE GetVidMemAllocHandle(DISP4DDVIDMEMDATA *pVidMem)
{
    return (NULL);
}
#endif

/**********************************************************************
    Win2k DDraw library support functions.
***********************************************************************/

extern LPVOID APIENTRY pDISP4DDGetDXObj(LPVOID pDevObj);

extern DWORD APIENTRY dDISP4DDEscape(LPVOID pDevInfo, DWORD dwEscape,
                                     DWORD dwInputSize, LPVOID pInput,
                                     DWORD dwOutputSize, LPVOID pOutput);

extern void APIENTRY vDISP4DDEnableExclusiveMode(LPVOID pDevObj);

extern void APIENTRY vDISP4DDDisableExclusiveMode(LPVOID pDevObj);

//The following functions are not used when CMM is active.

typedef struct _DISP4DD_MEMINFO
{
    DWORD dwTotal;
    DWORD dwFree;
} DISP4DD_MEMINFO, *LPDISP4DD_MEMINFO;

extern LPVOID APIENTRY pDISP4DDGetPrimarySurfaceStart(LPVOID pDevObj);

typedef enum _EDDHSLVIDMEMHEAP EDDHSLVIDMEMHEAP;

extern void APIENTRY vDISP4DDGetMemInfo(LPVOID pDevPtr, 
                                        EDDHSLVIDMEMHEAP eHeapType,
                                        LPDISP4DD_MEMINFO lpMemInfo);

extern void APIENTRY vDISP4DDAllocVidMem(LPVOID pDevObj, 
                                         EDDHSLVIDMEMHEAP eHeapType,
                                         DWORD dwCaps,
                                         DWORD dwFlags,
                                         DWORD dwAlignedPitch, 
                                         DWORD dwMemoryNeeded, 
                                         DWORD dwOffsetAlign,
                                         DISP4DDVIDMEMDATA *pVidMemData); 

extern void APIENTRY vDISP4DDFreeVidMem(LPVOID pDevObj, 
                                        EDDHSLVIDMEMHEAP eHeapType, 
                                        DISP4DDVIDMEMDATA *pVidMemData);


extern DWORD _stdcall dDISP4DDGetPdevFlags(LPVOID pDevObj);

extern LPVOID APIENTRY pDISP4DDAllocPageableMem(LPVOID pDevObj,
                                                DWORD  dwSizeInBytes);

extern BOOL APIENTRY bDISP4DDFreePageableMem(   LPVOID pDevObj, 
                                                LPVOID pMem);

extern VOID APIENTRY vDISP4DDDriverEntry(LPVOID pDevObj);
extern VOID APIENTRY vDISP4DDDriverExit(LPVOID pDevObj);


#endif //ATIDISPDD_H


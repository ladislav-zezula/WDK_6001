

//
//  $Workfile: atidxobj.h $
//
//  Description:
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//


#ifndef _ATIDXOBJ_H
#define _ATIDXOBJ_H

#include "atidxinc.h"
#include "atisurfp.h"
#include "atidispdd.h"
#include "cwddeci.h"
#include "qs.h"
#include "cwddedi.h"

#define MAX_ATI_CB               256      

#define MAX_FLIPS                20  

//This definition is for the PM4 semaphore!
#define     DDRAWHAL0   3
#define     D3DHAL0     2

#define MemCntlMask 0xFF00FF01
#define Rank1Bank4Row12Col256   0x2D002D01   //64M; 1 rank, 4 banks, 2**12 rows, 256 columns" in two channel, 128 bit configuration
#define Rank1Bank4Row12Col512   0x2E002E01   //128M; 1 rank, 4 banks, 2**12 rows, 512 columns in two channel, 128 bit configuration
#define Rank2Bank4Row12Col256   0xAD00AD01   //128M; 2 ranks, 4 banks, 2**12 rows, 256 columns" in two channel, 128 bit configuration

typedef struct _CVPDATA
{
    DWORD    ulFrameCount;
    DWORD    ulFlags;
    DWORD    dwStart;
    DWORD    dwEnd;
    BOOL     bIgnoreNextFlip;
    HWND     hwndCallback;
    PVOID    lpBuffer;
    LPDDRAWI_DDRAWSURFACE_LCL  lpSLCL;
} CVPDATA;

#define WM_CVP_GETFRAME     WM_USER

typedef struct _DDASICINFO
{
    DWORD    dwSize;
    DWORD    dwChipFamily;       //chip family (e.g. rage6, rage6x...)
    DWORD    dwChipID;           //vender and device id
    DWORD    dwChipRevision;     //chip revision (e.g. A11, A12)
} DDASICINFO;

typedef struct _ATIDDTIMESTAMP2
{
    QS_TIMESTAMP QsTstamp;
    DWORD    dwWrapStamp;       //chip family (e.g. rage6, rage6x...)
} ATIDDTIMESTAMP2;

typedef struct _VIDTOSYSSCRATCHINFO
{
    CMM_SURF_INFO oScratchInfo;
} VIDTOSYSSCRATCHINFO;

#ifndef _IA64_
#pragma pack (4)
#endif //_IA64_
typedef struct _ATIDXOBJECT
{
    DWORD       dwSize;

    LPVOID      lpDev;            //For WinNT - Display driver object

    struct _D3DDEVICE *pD3DDevice;

    CIASICID     sCiAsicId, *pCiAsicId;
    CIASICRANGES sCiAsicRanges, *pCiAsicRanges;
    CICHIPSETID  sCiChipSetId, *pCiChipSetId;

    // For FlipQueue
    DWORD          dwFlipQueueIndx;
    ATISURFINFO    ATISurfInfoFlipArray[MAX_FLIPS];
    DWORD          dwMaxFlipQueue;

    DWORD dwChipId;

    //These values hold the addresses of the frame buffer and AGP in ATI memory space
    ULONG_PTR          dwATI_FB_Start;
    ULONG_PTR          dwATI_AGP_Start;

    //Holds asic id and rev related info
    PR200AdapterInfo pR200AdapterInfo;

    BOOL           bStereoMode;

    DWORD          dwFeatures;

    // variable require for tiling/untiling
    DISP4DDVIDMEMDATA sMicroTileBuff;

    // Direct Draw's private CB
    struct _CMDBUFF*    lpDDrawCB;

    //USED FOR QT
    QS_FUNC2   QS_APIFunc, *pQS_APIFunc;
    QS_CAPS    QSCaps,     *pQSCaps;
    QS_PARAM   QSParam,    *pQSParam;
    QS_HCLIENT QSHClient;
    QS_HDEVICE QSHDevice;

    LPATISURFINFO TimeStampArray[8];
    ATIDDTIMESTAMP2                   CBStampArray[MAX_ATI_CB];
    DWORD                           dwCBStampIndex; //index into CBStampArray
    DWORD                           dwCurrentWrapStamp;

    // keep a copy of this register to avoid reading it every flip
    DWORD dwCrtcOffsetCntl;
    DWORD dwCrtc2OffsetCntl;

    DWORD dwCRTCSyncEntries;

    // CICALLBACKDATA_DCI contains variables for dual-CRTC & ratiometric expansion support
    CICALLBACKDATA_DCI sCIDCIData,  *lpCIDCIData;
    CICALLBACKDATA_DCI sCIDCIData2, *lpCIDCIData2;
    CVPDATA CVPData;

    LPATISURFINFO  lpSurfInfoArrays[MAX_ATISURFINFO_ARRAYS];

    DWORD                           dwMaxNumHeaps;

    DWORD                           dwAGP_HEAP;

    // Keep count of all the DirectDraw surfaces (except the Primary)
    DWORD                           dwTextureSurfaceCount;

    DWORD       dwOverlaySurfaceCount;

    VIDTOSYSSCRATCHINFO oSystemScratch;

#ifdef WIN2K
    HANDLE      hDriver;          //For WinNT - Handle used to refer to the driver by the Kernal
#endif

    // Start of the primary surface.
    DWORD_PTR                   dwPrimaryStart;

    DWORD                       dwWindowGammaMode; //gamma settings in windowed mode.

    // registry settings
    BOOL bIsStereoEnabled;
    BOOL bIsColorFillEnabled;
    BOOL bIsSysMemBltsEnabled;
    BOOL bIsLVBEnabled;
    BOOL bIsLocalTextureTilingEnabled;
    BOOL bIsNonLocalTextureTilingEnabled;
    BOOL bIsPrimaryTilingEnabled;
    BOOL bIsLocalTextureMicroTilingEnabled;
    BOOL bIsNonLocalTextureMicroTilingEnabled;
    BOOL bIsOffscreenPlainTilingEnabled;
    BOOL bIsBackBufferTilingEnabled;
    BOOL bIsFBTextureEnabled;
    BOOL bIsOGLZDecompressEnabled;
    BOOL dwIsVSyncEnabled;
    BOOL bIsTextureRatioWorkaround;
    BOOL bIsOGLBTilingEnabled;
    DWORD dwIsAGPTextureEnabled;
    DWORD dwQSWaitTimeStamp;
    DWORD dwPacketDump;
    BOOL bEliminateBackToPrimBlt;
    DWORD bIFH;
    DWORD bIFHTexLoad;        //IFH but texture updates are still being executed.
    BOOL bVBEnableImplicit;
    DWORD dwExtraQueuedFrames;
    BOOL  bEdit24ZPixelFormat;
    DWORD dwExportBumpMappedTex;
    BOOL  bExportSignedVolTex;   // expose signed volume formats (V16U16, Q8W8V8U8, W11V11U10)
    BOOL  bExportMipMapCubeMaps;
    BOOL bExportWBuffer;
    BOOL bEnableMemoryBanking;
    DWORD dwTilingOptions;
    BOOL bIsBlockRasterizationCanBeDisabled;

    DWORD dwIsGameGammaEnabled;
    DWORD dwBltQueueSyncEnabled;
    DWORD dwRegistryReserved5;
    DWORD dwRegistryReserved6;
    float fMultiPassDownscaleBltThreshold;

    char           DisplayName[32];        // display name

    char           szDriverRegistryID[4];  //Driver number, i.e 0000, 0001 or ????
    char           szCRTCRegistryID[4]; //CRTC number, i.e 00 or 01

    DWORD dwFlags0;
    //CMM Client structure for this ATIDXOBJECT.
    CMM_CLIENT_INFO CMMClientInfo;

    DWORD           dwVSYNCEnabled;

    DWORD dwSubmit3DScaleBltSize;
    DWORD dwSubmit3DYuvPlanarBltSize;

    // MS has requested ATI to disable D3D on PCI boards
    // running on WinXP. We are doing that via registry
    // in case if there is a reversal in that decision.
    BOOL bDisableD3D;
    // This field determines whether Overlay uses a pitch that meets the VMR requirement,
    // i.e. the pitch alignment of a Overlay surface is identical to that of a d3d surface.
    // The default value is 1.
    DWORD dwUseVmrPitch;

    // This parameter is for invalidating HDP read buffer. We read HOST_PATH_CNTL
    // at the init time. In lock function, we write it back which will invalidate
    // HDP read buffer. See more detailed comments in lock.c
    // This register is static after init for all chips (but a different static value
    // in each chip).
    DWORD dwHOST_PATH_CNTL;

    QS_SCRATCH_REGISTERS    sQS_ScrRegs, *pQS_ScrRegs;

#ifdef _IA64_
    BOOL bCheckMissedVerticalBlank;
#endif //_IA64_

#ifdef DEBUG
    struct reginfo *pRegListInfo;
#endif // DEBUG

    DWORD dwMemCntl;

    DWORD   dwDetectedFeatures;

    BOOL bIsBlockRasterizationDisabled;

} ATIDXOBJECT, *LPATIDXOBJECT;

#define Ctrl_DXHALCommand         0x73F3
#define DXHALGETDXINFO              1


// Note:  if the size of this structure changes, you *must* change the
//        idc_drvInitInfo field of the IDC structure as well!  See
//        devinfo.h in the 9x database.
typedef struct _DXINFO
{
 DWORD       dwSize;         //Size of structure
 DWORD       dwDXRuntimeVer; //DX runtime version number
 LPDDHALINFO lpDDHALInfo;    //ptr to DDHALINFO struct inside
                             //the display driver!
}DXINFO, FAR *LPDXINFO;

typedef struct _DX9XDRVINITINFO {
    char   szDeviceName[32];
    char   idc_szDriverRegistryID[4];
    char   idc_szCRTCRegistryID[4];
    DWORD  dwCMMhDevice;
} DX9XDRVINITINFO, *PDX9XDRVINITINFO;

typedef struct _DXHALCOMMAND
{
 DWORD      dwFunction;
 LPVOID     lpInputStruct;
}DXHALCOMMAND, FAR *LPDXHALCOMMAND;

#define     ATIDXOBJ_FLAGS0_EXTRAQUEUEDFRAMES_MASK  0x000000FFL

#ifndef QSWAIT_OPTIONSENUM
#define QSWAIT_OPTIONSENUM

    //Registry options for waiting for QServer after each QSSubmitList call
    enum QSWAIT_OPTIONS
    {
        QSWAIT_NONE,
        QSWAIT_CONSUMED,
        QSWAIT_RETIRED,
    };

#endif

#ifndef PACKETDUMP_OPTIONSENUM
#define PACKETDUMP_OPTIONSENUM

    //Registry options for peforming Packet Dumps
    enum PACKETDUMP_OPTIONS
    {
        PACKETDUMP_NONE=0,
        PACKETDUMP_APPEND=1,
        PACKETDUMP_OVERWRITE=2,
        PACKETDUMP_APPEND_NOANNOTATE=5,
        PACKETDUMP_OVERWRITE_NOANNOTATE=6
    };

#endif

#ifndef AGPSURFACE_OPTIONS
#define AGPSURFACE_OPTIONS

    enum AGPSURFACE_OPTIONS
    {
        AGPSURFACE_DISABLE,
        AGPSURFACE_ENABLE,
        AGPSURFACE_ENABLE_SYSBLTMEMCPY,
    };

#endif

#ifndef CHIPID_OPTIONS
#define CHIPID_OPTIONS

    enum CHIPID_OPTIONS
    {
        CHIPID_DEFAULT          =0,      // Get the chipid info from CI interface.
        CHIPID_FORCE_RADEON200A11   =1,      // Force to be R200 A11
        CHIPID_FORCE_RADEON200A12   =2,      // Force to be R200 A12
        CHIPID_FORCE_RADEON200A13   =3       // Force to be R200 A13
    };

#endif

#ifndef TILING_OPTIONS
#define TILING_OPTIONS

    enum TILING_OPTIONS
    {
        TILING_DST_MICROTILE   = 1,
        TILING_HDP_MICROTILE   = 2
    };

#define TILING_OPTIONS_DEFAULT   0

#endif

#ifndef _IA64_
#pragma pack ()
#endif //_IA64_

///////////////////////////////////////////////////////////////////////////////
// Function creates/releases a HDC under Win9x only                              //
// For Win2K the Driver handle is provided by the display driver and
// and stored in the ATIDXOBJECT
///////////////////////////////////////////////////////////////////////////////

__inline HANDLE GetDDrawDrvHandle(LPATIDXOBJECT lpATIDXObj)
{
#ifdef WIN2K
    return lpATIDXObj->hDriver;
#endif
}

__inline void ReleaseDDrawDrvHandle(HANDLE hDriver)
{
}

__inline void EnableMemoryBanking(LPATIDXOBJECT lpATIDXObj, BOOL Enable)
{
    lpATIDXObj->bEnableMemoryBanking = Enable;
}

__inline QS_HCLIENT GetQsHClient(LPATIDXOBJECT lpATIDXObj)
{
    return lpATIDXObj->QSHClient;
}

__inline QS_HDEVICE GetQsHDevice(LPATIDXOBJECT lpATIDXObj)
{
    return lpATIDXObj->QSHDevice;
}

__inline QS_FUNC2 * GetQsFunctions(LPATIDXOBJECT lpATIDXObj)
{
    return lpATIDXObj->pQS_APIFunc;
}

__inline QS_PARAM * GetQsParam(LPATIDXOBJECT lpATIDXObj)
{
    return lpATIDXObj->pQSParam;
}

__inline QS_CAPS * GetQsCaps(LPATIDXOBJECT lpATIDXObj)
{
    return lpATIDXObj->pQSCaps;
}

__inline DWORD_PTR GetATIFrameBuffStart(LPATIDXOBJECT  lpATIDXObj)
{
    return (DWORD_PTR)lpATIDXObj->sCiAsicRanges.pVram;
}

__inline DWORD GetATIFrameBuffSize(LPATIDXOBJECT lpATIDXObj)
{
    return (lpATIDXObj->sCiAsicId.ulVramInstalled);
}

__inline volatile DWORD *GetATIMemReg(LPATIDXOBJECT lpATIDXObj)
{
    return (volatile DWORD *)(lpATIDXObj->sCiAsicRanges.pMmr);
}

__inline DWORD_PTR GetPrimaryStart(LPATIDXOBJECT lpATIDXObj)
{
    return (lpATIDXObj->dwPrimaryStart);
}

__inline DWORD_PTR GetATIAGPBase(LPATIDXOBJECT  lpATIDXObj)
{
    return(lpATIDXObj->sCiAsicRanges.ulAgpBase);
}

__inline DWORD GetATIScreenWidth(LPATIDXOBJECT  lpATIDXObj)
{
    return(lpATIDXObj->sCIDCIData.ulModeWidth);
}

__inline DWORD GetATIScreenHeight(LPATIDXOBJECT  lpATIDXObj)
{
    return(lpATIDXObj->sCIDCIData.ulModeHeight);
}

__inline DWORD GetATIScreenBPP(LPATIDXOBJECT  lpATIDXObj)
{
    return(lpATIDXObj->sCIDCIData.ulModeBpp);
}

__inline DWORD GetATIScreenPitch(LPATIDXOBJECT  lpATIDXObj)
{
    return(lpATIDXObj->sCIDCIData.ulScreenPitch);
}


__inline void IncATIFlipQueueIndx(LPATIDXOBJECT  lpATIDXObj)
{
    lpATIDXObj->dwFlipQueueIndx++;
    if( lpATIDXObj->dwFlipQueueIndx > lpATIDXObj->dwMaxFlipQueue)
    {
        lpATIDXObj->dwFlipQueueIndx = 0;
    }
}

// dwMaxFlipQueue is initialized to extraQueuedFrames
__inline void  IncATIMaxFlipQueue(LPATIDXOBJECT  lpATIDXObj)
{
    lpATIDXObj->dwMaxFlipQueue++;

    // We can only hand MAX_FLIPS.
    if( lpATIDXObj->dwMaxFlipQueue >= MAX_FLIPS)
    {
        lpATIDXObj->dwMaxFlipQueue = MAX_FLIPS-1;
    }
}

__inline DWORD GetATIMaxFlipQueue(LPATIDXOBJECT  lpATIDXObj)
{
    return lpATIDXObj->dwMaxFlipQueue;
}

__inline LPATISURFINFO GetATIFlipArray(LPATIDXOBJECT  lpATIDXObj, DWORD dwIndex)
{
    return (&(lpATIDXObj->ATISurfInfoFlipArray[dwIndex]));
}

__inline void SetStereoMode(LPATIDXOBJECT  lpATIDXObj, BOOL bValue)
{
    lpATIDXObj->bStereoMode = bValue;
}

//CMM interface functions
__inline CMM_RETURNCODE __stdcall DDCMMRegisterClient(LPATIDXOBJECT           lpATIDXObj,
                                                      CMM_CLIENT_DESCRIPTOR   *pInput,
                                                      CMM_CLIENT_INFO         *pOutput)
{
    return lpATIDXObj->QS_APIFunc.QSCentralMemoryMgr2(lpATIDXObj->QSHDevice,
                                                      CMM_COMMAND_REGISTER_CLIENT,
                                                      sizeof(CMM_CLIENT_DESCRIPTOR),
                                                      pInput,
                                                      sizeof(CMM_CLIENT_INFO),
                                                      pOutput);
}

__inline CMM_RETURNCODE __stdcall DDCMMUnregisterClient(LPATIDXOBJECT           lpATIDXObj,
                                                        CMM_CLIENT_INFO         *pInput)
{
    return lpATIDXObj->QS_APIFunc.QSCentralMemoryMgr2(lpATIDXObj->QSHDevice,
                                                      CMM_COMMAND_UNREGISTER_CLIENT,
                                                      sizeof(CMM_CLIENT_INFO),
                                                      pInput,
                                                      0,
                                                      NULL);
}


__inline CMM_RETURNCODE __stdcall DDCMMAllocSurface(LPATIDXOBJECT           lpATIDXObj,
                                                    CMM_SURF_DESCRIPTOR     *pInput,
                                                    CMM_SURF_INFO           *pOutput)
{
    return lpATIDXObj->QS_APIFunc.QSCentralMemoryMgr2(lpATIDXObj->QSHDevice,
                                                      CMM_COMMAND_ALLOCATE_SURFACE,
                                                      sizeof(CMM_SURF_DESCRIPTOR),
                                                      pInput,
                                                      sizeof(CMM_SURF_INFO),
                                                      pOutput);
}

__inline CMM_RETURNCODE __stdcall DDCMMFreeSurface(LPATIDXOBJECT           lpATIDXObj,
                                                   CMM_FREESURF_INPUT      *pInput)
{
    return lpATIDXObj->QS_APIFunc.QSCentralMemoryMgr2(lpATIDXObj->QSHDevice,
                                                      CMM_COMMAND_FREE_SURFACE,
                                                      sizeof(CMM_FREESURF_INPUT),
                                                      pInput,
                                                      0,
                                                      NULL);
}

__inline CMM_RETURNCODE __stdcall DDCMMQuerySurfaceInfo(LPATIDXOBJECT           lpATIDXObj,
                                                        CMM_SURF_REQUEST        *pInput,
                                                        CMM_SURF_INFO           *pOutput)
{
    return lpATIDXObj->QS_APIFunc.QSCentralMemoryMgr2(lpATIDXObj->QSHDevice,
                                                      CMM_COMMAND_QUERY_SURFACE_INFO,
                                                      sizeof(CMM_SURF_REQUEST),
                                                      pInput,
                                                      sizeof(CMM_SURF_INFO),
                                                      pOutput);
}

__inline CMM_RETURNCODE __stdcall DDCMMAllocCache(LPATIDXOBJECT           lpATIDXObj,
                                                  CMM_SURF_REQUEST        *pInput,
                                                  CMM_SURF_INFO           *pOutput)
{
    return lpATIDXObj->QS_APIFunc.QSCentralMemoryMgr2(lpATIDXObj->QSHDevice,
                                                      CMM_COMMAND_ALLOC_CACHE,
                                                      sizeof(CMM_SURF_REQUEST),
                                                      pInput,
                                                      sizeof(CMM_SURF_INFO),
                                                      pOutput);
}

__inline CMM_RETURNCODE __stdcall DDCMMFreeCache(LPATIDXOBJECT           lpATIDXObj,
                                                 CMM_SURF_REQUEST        *pInput)
{
    return lpATIDXObj->QS_APIFunc.QSCentralMemoryMgr2(lpATIDXObj->QSHDevice,
                                                      CMM_COMMAND_FREE_CACHE,
                                                      sizeof(CMM_SURF_REQUEST),
                                                      pInput,
                                                      0,
                                                      NULL);

}

__inline CMM_RETURNCODE __stdcall DDCMMRecoverSurface(LPATIDXOBJECT           lpATIDXObj,
                                                      CMM_SURF_REQUEST        *pInput,
                                                      CMM_SURF_INFO           *pOutput)
{
    return lpATIDXObj->QS_APIFunc.QSCentralMemoryMgr2(lpATIDXObj->QSHDevice,
                                                      CMM_COMMAND_RECOVER_SURFACE,
                                                      sizeof(CMM_SURF_REQUEST),
                                                      pInput,
                                                      sizeof(CMM_SURF_INFO),
                                                      pOutput);
}

__inline CMM_RETURNCODE __stdcall DDCMMSetAperture(LPATIDXOBJECT           lpATIDXObj,
                                                   CMM_APERTURE_DESCRIPTOR *pInput)
{
    return lpATIDXObj->QS_APIFunc.QSCentralMemoryMgr2(lpATIDXObj->QSHDevice,
                                                      CMM_COMMAND_SET_APERTURE,
                                                      sizeof(CMM_APERTURE_DESCRIPTOR),
                                                      pInput,
                                                      0,
                                                      NULL);

}

__inline CMM_RETURNCODE __stdcall DDCMMFreeAperture(LPATIDXOBJECT           lpATIDXObj,
                                                    CMM_APERTURE_DESCRIPTOR *pInput)
{
    return lpATIDXObj->QS_APIFunc.QSCentralMemoryMgr2(lpATIDXObj->QSHDevice,
                                                      CMM_COMMAND_FREE_APERTURE,
                                                      sizeof(CMM_APERTURE_DESCRIPTOR),
                                                      pInput,
                                                      0,
                                                      NULL);

}

__inline CMM_RETURNCODE __stdcall DDCMMGetGeneralInfo(LPATIDXOBJECT           lpATIDXObj,
                                                      CMM_GENERAL_INFO        *pOutput)
{
    return lpATIDXObj->QS_APIFunc.QSCentralMemoryMgr2(lpATIDXObj->QSHDevice,
                                                      CMM_COMMAND_GET_GENERAL_INFO,
                                                      0,
                                                      NULL,
                                                      sizeof(CMM_GENERAL_INFO),
                                                      pOutput);
}

extern DWORD APIENTRY dDISP4DDEscape(LPVOID pDevInfo, DWORD dwEscape,
                                     DWORD dwInputSize, LPVOID pInput,
                                     DWORD dwOutputSize, LPVOID pOutput);

__inline PQS_SCRATCH_REGISTERS GetQSScratchRegs( LPATIDXOBJECT lpATIDXObj )
{
    QS_SCRATCH_REGISTER_PARAMETERS  sQSScrRegsParam, *pQSScrRegsParam = &sQSScrRegsParam;

    pQSScrRegsParam->hClient = lpATIDXObj->QSHClient;
    pQSScrRegsParam->dwReadSelector = QS_SCRATCH_QUERY_PRIMARY;
    pQSScrRegsParam->dwDmaStatus = QS_SCRATCH_LAST_READ_RETIRED;
    if( lpATIDXObj->pQS_APIFunc->QSGetScratchRegisters )
    {
        lpATIDXObj->pQS_APIFunc->QSGetScratchRegisters( lpATIDXObj->QSHDevice, pQSScrRegsParam );
    }

    return( pQSScrRegsParam->pRegisters );
}

#endif //ATIDXOBJ_H




//
//  Workfile: d3ddevice.h
//
//  Description: D3D Device Header
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _D3DDEVICE_H
#define _D3DDEVICE_H

#include "atidxinc.h"
#include "d3dcntx.h"
#include "Dlink.h"
#include "atiid.h"
#include "asicbugs.h"

#ifdef WIN2K
#define IsBadReadPtr(x,y) 0
#endif

typedef struct
{
    float       zbias_factor;
    float       zbias_constant;
} ZBiasValue;

typedef struct _D3DHSLSURF_LIST
{
    VOID             *lpD3DHSLSurfInfo;  // Points to D3D HSL surfInfo, D3D context, ...
    DWORD            dwNumUsedSlot;
} D3DHSLSURF_LIST, *LPD3DHSLSURF_LIST;

typedef struct _D3DASICINFO
{
    DWORD        dwSize;
    volatile     DWORD *lpMMR;       //memory mapped register base address
    LPVOID       lpFrameBuffStart;   //frame buffer base address
    ULONG_PTR    dwATI_FB_Base;      //memory control address for frame buffer base
    ULONG_PTR    dwATI_AGP_Base;     //memory control address for agp base
    DWORD        dwChipFamily;       //chip family (e.g. rage6, rage6x...)
    DWORD        dwChipID;           //vender and device id
    DWORD        dwChipRevision;     //chip revision (e.g. A11, A12)
    DWORD        dwVRAMSize;         //Total Videomemory on the board
} D3DASICINFO;

typedef struct _ATID3DTIMESTAMP2
{
    QS_TIMESTAMP QsTstamp;
    DWORD    dwWrapStamp;
} ATID3DTIMESTAMP2;

////////////////////////////////////////////////////////////////////////////////
// Registry range values                                                      //
////////////////////////////////////////////////////////////////////////////////
#define REGISTRY_VALUE_OFF      0
#define REGISTRY_VALUE_LOW      1
#define REGISTRY_VALUE_MED      2
#define REGISTRY_VALUE_HIGH     3

typedef struct _ATID3DREGISTRY {

    // Registry settings

    BOOL bIsTclEnabled;
    BOOL bIsPureDeviceEnabled;
    BOOL bIsWaitExtraCacheFlushEnabled;
    BOOL bIsVbDdHeapsEnabled;
    BOOL bIsLVBEnabled;
    BOOL bIsIntLVBEnabled;
    DWORD dwIntLvbLogFract;
    DWORD dwVBMemLoader;
    BOOL  bVbHwBufferBlt;

    // Index buffer-related variables
    DWORD dwHwIb;
    BOOL  HwIbMethod;
    DWORD dwHwIbMaxPrims;
    DWORD dwHwIbMinPrims;
    DWORD dwHwIbMinSize;

    BOOL bSubmitOnDraw;
    BOOL bExportWBuffer;
    DWORD dwDisableZCacheModeWC;
    DWORD dwZCacheModeDefault;  // non-registry, but move with registry
    BOOL bBadTexCoordCullDisable;
    DWORD dwIsAGPTextureEnabled;
    ANTIALIAS_REGISTRY_ENTRY AARegistry;
    DWORD dwAASamples;

    BOOL bGetRasterGuardbandEnable;
    DWORD dwGetTclGuardbandClipAcceptX;
    DWORD dwGetTclGuardbandClipAcceptY;
    DWORD dwGetTclGuardbandDiscardX;
    DWORD dwGetTclGuardbandDiscardY;
    DWORD dwIsTclBackfaceCullingEnabled;
    DWORD dwIsTclVertexBlendUseProjMtxEnabled;
    DWORD dwIsTclVertexBlend2OptimizeEnabled;
    DWORD dwGetTclCullingMethod;
    DWORD dwGetMaxAgpVb;
    DWORD dwGetMaxLocalVb;
    DWORD dwDefaultVBSize;
    DWORD dwQSWaitTimeStamp;
    DWORD dwPacketDump;

    // Used for RV250 debugging
    DWORD bReDebug7Reg;

    DWORD dwExportCompressedTex;
    DWORD dwNumExportedTexStages;
    DWORD bIFH;
    DWORD bIFHTexLoad;        //IFH but texture updates are still being executed.
    DWORD bT2T0HangWorkaround;
    DWORD dwExportBumpMappedTex;
    DWORD dwDitherAlpha;
    DWORD dwZFormats;
    BOOL  bNONPOW2ConditionalTextureCaps;
    BOOL  bEdit24ZPixelFormat;
    BOOL  bTableFogEnable;
    BOOL  bWFogEnable;
    BOOL  bZFogEnable;
    BOOL  bVertexFogEnable;
    BOOL  bDiscreteFogEnable;
    BOOL  bVolTxEnable;
    BOOL  bExportYUVTex;
    BOOL  bExportSignedVolTex;   // expose signed volume formats (V16U16, Q8W8V8U8, W11V11U10)
    BOOL  bExportMipMapCubeMaps; // expose mip map cube maps
    DWORD dwTexUnitOrd;          //Texture unit allocation order.
    DWORD adwTUAllocOrd[ATI_MAX_NUM_TEX_UNITS]; //non-registry, but it's set based on dwTUAllocOrd.

    DWORD dwForceAnisoSize;      // 0 ... 16.
    BOOL  bAnisoLinear;          // 0 or 1

    // Chaplin programmable vertex shader (PVS) settings
    DWORD dwVertexShaderVersion;  // Controls the vertex shader version that is exposed (unsigned 1.1)
    DWORD dwMaxVertexShaderConst; // Controls the max number of vertex shader constants
    DWORD dwGetMaxAgpPVS;
    DWORD dwGetMaxLocalPVS;
    BOOL  bPVSConstInVidMem;
    BOOL  bIsPVSRingEnabled;

    DWORD dwOptimizePVSCode;     

    DWORD dwPvsDebug;            
                                 
    DWORD dwChipId;

    // Whether or not vertex index validate routines will be enabled.
    // When disabled, validate always returns true.
    BOOL  bValidateVertexIndex;

    // This registry controls what version of the PixelShader is exposed
    DWORD dwPixelShaderVersion;

    // This registry control number of vertex streams we support
    DWORD dwMaxStreams;

    BOOL bEnablePlaneMaskWorkaround;

    // If this is set, we will export the RTPatch caps.
    DWORD dwEnableRTPatch;

    DWORD dwNPatchMode;

    BOOL  bReEnableZForA12;

    DWORD dwMaxMatrixBlend;

    DWORD dwTriListStall;
    DWORD dwSolidVbidxImCnt;
    DWORD dwTriListPacketMax;

    // For pixel center setting at 0.0 or 0.5
    DWORD dwPixelCenterAtPoint5;

    BOOL  bPointSpritesEnable;
    DWORD dwPointSpriteMinSizeClamp;

    // R200 settings
    BOOL  bR200OnePrimPerPassEnable;
    BOOL  bR200DuplicateIdxEcoDisable;
    BOOL  bR200MPLinePatternEnable;
    DWORD dwR200ReDebug7Default;       // non-registry, but move with registry
    BOOL  bR200TexCacheLRUWorkaroundEnable;
    DWORD dwR200TexCacheLRUDefault;    // non-registry, but move with registry
    BOOL  bR200ZMaskCacheWorkaroundEnable;
    DWORD dwR200ZMaskCacheDefault;     // non-registry, but move with registry
    BOOL  bClipDisable;
    BOOL  dwClipOptimizations;
    DWORD dwTriPerf;
    DWORD dwJTable1;
    DWORD dwJTable2;


    BOOL  bRemoveDegenTris;

    BOOL  bR200MissingSpecWorkaround;

    BOOL  bR200PtViewportBugFix;

    BOOL  bR200PtSprTexBugFix;

    BOOL  bR200PtPunySizeBugFix;

    BOOL  bR200IndexBufferRangeFix;

    BOOL  bR200OptimizeTexStages;

    BOOL bR200ZeroLengthLineWorkaround;

    BOOL bR200VTEBackpressureWorkAround;

    BOOL bR200T0HangWorkaround;

    // Enable/disable alpha blending blendops [MIN, MAX, SUBTRACT, REVSUBTRACT].
    BOOL bBlendOpEnable;

    // TCL Viewport Scale in Projection matrix
    BOOL  bTclVpScaleInProj;

    // R200 vertex cache prefetch quantity
    // 0 - 1 Octword  (16 bytes)
    // 1 - 2 Octwords (32 bytes)
    // 2 - 4 Octwords (64 bytes)
    DWORD dwVtxPrefetch;

    // This registry setting allows the A11 (and presumably A12) boards that showed
    // PVS corruption at low clock speeds to be clocked up significantly.  The 1 caveat
    // is that MAD operations now count as 2 instructions.  This should probably only be
    // used for performance tuning until A13 (it will be disabled by default).
    BOOL bVertexShaderOCWorkaround;

    // Maximum number of prims allowed in a command packet.  This reduces the stall when
    // an app tries to lock a HW VB.
    DWORD dwMaxPrimsInPacket;

    // Minimum number of vertices required to enable IntVB.
    DWORD dwMinVertsIntVB;

    // Point Sprite reuse with user clip planes enabled causes the VAP to hang.  This
    // registry setting forces reuse off via SE_VTX_NUM_ARRAYS:VTX_REUSE_DISABLE.  This
    // register does not exist on A11 or A12, so this value is disabled by default on those
    // revisions.
    BOOL bDisablePointSpriteReuseForUCP;

    DWORD dwMaxLazyFreeVB_ByteSize;  // global limit on lazy free list
    DWORD dwMaxLazyFreeVB_Count;     // global limit on lazy free list

    // Controls for Z Viewport Tweaks for HiZ Effectiveness
    BOOL  bForceVPortZ;
    float fForceVPortZScale;
    float fForceVPortZOffset;

    BOOL bRV250ConstsandTexcoordAlpha;

    // RV250 Wrapping is disabled for RV250
    BOOL bDisableCylindricalWrap;

    // R200 Cylindrical Wrapping state for R200
    DWORD dwR200CylindricalWrapState;

    DWORD dwCheckFeatures;

    // Enable DX9 extended modes (A2R10G10B10 display format).
    BOOL bR200ExtModesEnabled;

    // Enable DX9 LineAntiAlias cap
    BOOL bLineAntiAliasEnabled;


} ATID3DREGISTRY;

#define D3DDEV_NTEXADDR_STATES D3DTADDRESS_MIRRORONCE

// Define used for exported pixel formats array in D3DDevice structure.

#define ATI_TEXTURE_FORMATS  36

#define MAX_TEXTURES 6

extern LPATISURFHANDLE CurrSurfaceTable;

void
SSEmemcpy(
    __out_bcount(nCount)  void*  lpDest,
    __in    const void*  lpSource,
    __in    size_t  nCount
    );

void
MMXmemcpy(
    __out_bcount(nCount)  void*  lpDest,
    __in    const void*  lpSource,
    __in    size_t  nCount
    );

typedef
void
(*PMEMCPY)(
    __out_bcount(nCount)  void*  lpDest,
    __in    const void*  lpSource,
    __in    size_t  nCount
    );

#define STENCILOP_INRANGE(x)    ((x) <= D3DSTENCILOP_DECR)
#define FILTERLOP_INRANGE(x)    ((x) <= D3DTFG_ANISOTROPIC)
#define BLENDOP_INRANGE(x)      ((x) <= D3DBLENDOP_MAX)
typedef struct _D3DDEVICE
{
    D3DHAL_CALLBACKS          sD3DHalCallbacks;
    D3DHAL_GLOBALDRIVERDATA   sD3DGlobalDriverData;

    // For texStage setup.
    DWORD dwNumTextureUnits;
    DWORD TexDirty[MAX_TEXTURES];
    DWORD BlendCntl[MAX_TOP];
    DWORD ColorArg[4][MAX_TA];
    DWORD AlphaArg[4][MAX_TA];

    //Register values for the Result Arg.  Currently support on D3DTA_CURRENT
    //and D3DTA_TEMP.  Pixel shader may need a wider selection.
    DWORD ResultArg[MAX_TA];

    DWORD ColorBlendAlpha[4][5];
    DWORD AlphaBlendAlpha[4][5];
    DWORD MagFilter[6];
    DWORD MinMipFilter[3][3];
    DWORD MaxAnisotropy[17];
    DWORD TexAddress[D3DDEV_NTEXADDR_STATES];

    // For renderState setup.
    DWORD ConvertZCmpFunc[9];
    DWORD ConvertAlphaFunctoHW[9];
    DWORD ConvertShadeModeHW[4];
    DWORD ConvertFogModetoHW[4];
    DWORD ConvertStencilOpToHW[9];
    DWORD ConvertRopToHW[17];
    DWORD ConvertBlendOpToHW[6];

    // For texture coordinate setup in projected textures and cubemaps.
    DWORD FlexibleWFlag[3];

    ZBiasValue ZBiasTable[2][17];
    ANTIALIAS_SETTINGS AASettings[NUM_SUPPORTED_AAMODES];

#ifdef DEBUG
    char* Dp2OpString[MAX_DP2S];
    char* RpOpString[15];
    char* DpOpString[7];

    char *strBool[2];
    char *strTexAddr[5];
    char *strFillMode[4];
    char *strShadeMode[4];
    char *strTexMinMag[7];
    char *strSrcDstBlend[14];
    char *strTexBlend[9];
    char *strCullMode[4];
    char *strCmpFunc[9];
    char *strFogMode[4];
    char *strStencilOP[9];
    char *strColorOP[MAX_TOP + 1];  //+1 to account for [0] = "UNKNOWN"
    char *strColorARGS[MAX_TA];
    char *strTexStageStates[MAX_TSS];

    char* strStateName[MAX_RENDER_STATES];

#endif  // DEBUG

    /* Enough space to store 256 D3D Context Hndl's. */
    LPATID3DCNTX ATID3DCntxList[ContextPerBlock];

    // A pointer to memory to store D3D HSLSurfInfo struct. All three variables
    // are init to zero in InitD3DDevice. They are used in AllocateD3DHSLSurfSlot
    // and DeallocateD3DHSLSurfSlot.
    D3DHSLSURF_LIST           D3DHSLSurfList[ContextPerBlock];

    /* Counts #of allocated 3D contexts */
    DWORD dwTotalContexts;

    //pointer to vertex buffer unknown command processing function
    PFND3DPARSEUNKNOWNCOMMAND pD3DParseUnknownCommand;

    //USED FOR QT
    QS_FUNC2   QS_APIFunc, *pQS_APIFunc;
    QS_CAPS    QSCaps,     *pQSCaps;
    QS_PARAM   QSParam,    *pQSParam;
    QS_HCLIENT QSHClient;
    QS_HDEVICE QSHDevice;

    // Each CB created by GetNewCB is given an unique ID from 1 to MAX_NUM_CB_ID-1, no
    // matter which context created it. It is init to 0
    DWORD           dwLatestCB_ID;

    // When there's no memory, we will write all the qs entries to this
    // scratch area and skip qs submit. This avoids us having to check
    // the return value of GetPM4Entries.
    DWORD  aQsScratchArea[CB_MAX_SIZE_DWORDS];

    // This array is set in SubmitCmdBuff and init to 0 in initialize.c
    ATID3DTIMESTAMP2    TimeStampArray[MAX_NUM_CB_ID];
    DWORD               dwCurrentWrapStamp;

    volatile DWORD*  lpMMReg;

    LPVOID  lpDevInfo;        //ATIDXOBJECT

    DWORD dwVbAgpInUse;
    DWORD dwVbAgpAllocated;
    DWORD dwVbLocalInUse;
    DWORD dwVbLocalAllocated;
    // for Chaplin
    DWORD dwPVSAgpAllocated;
    DWORD dwPVSLocalAllocated;

    // DrawPrimitive jump tables
    PRENDTRI* pDrawTableSolid;
    PRENDTRI* pDrawTableWframe;
    PRENDTRI* pDrawTablePoint;

    // Jump tables to check the validity of vertex indices.
    PVALIDATETRI* pValidateVertexIndexTable;

    STATESETFUNCTIONTABLE* pStateSetFunctionTable;
    STATESETFUNCTIONTABLE* pStateRecFunctionTable;

    // Registry settings
    ATID3DREGISTRY AtiD3dRegistry;

    // New fields added for dx8.
    DDHALINFO                 sDDHalInfo;

    // Primitive type in SE_VF_CNTL.
    DWORD aPm4PrimType[MAX_PRIM_TYPE];

    // Number of vertices per primitive.
    DWORD aVertsPerPrim[MAX_PRIM_TYPE];

    // Stride per primitive.
    DWORD aStridePerPrim[MAX_PRIM_TYPE];

    // The number of vertices overlapped between the current primitive
    // and last primitive, this is used in draw routines when a set of
    // primitives is broken into several pm4 blocks, with this info, we
    // can properly set the start of the next pm4 block.
    DWORD aDeltaVerts[MAX_PRIM_TYPE];

    // Dx8 draw prim jump tables.
    PDX8RENDTRI* pDx8DrawPrimTable;
    PDX8RENDIDXTRI* pDx8DrawIdxPrimTable;

    // Dx8 pointsprite jump tables
    PDX8RENDPS*    pDx8DrawPSTable;
    PDX8RENDIDXPS* pDx8DrawIdxPSTable;

    DWORD dwSupportedFSAASamples;

    // Exported Pixel Formats Arrays used in init_pixformat.c
    //DX7Texture Formats
    DDSURFACEDESC lpDX7ExportedTextureFormats[ATI_TEXTURE_FORMATS];

    //DX8 Texture Formats
    DDSURFACEDESC lpDX8ExportedTextureFormats[ATI_TEXTURE_FORMATS];
    DWORD dwNumDX8TexFormats;

    DWORD  dwDXRunTimeVersion;

    // Asic Features
    DWORD dwFeatures;

    // Display Mode
    DWORD dwModeWidth;
    DWORD dwModeHeight;
    DWORD dwModeBpp;
    PMEMCPY pmemcpy;

    // Asic bugs originated in R200 Family asics.
    DWORD dw3D2AsicBugsList;

    DWORD dwLazyFreeVB_ByteSize;  // global limit on lazy free list
    DWORD dwLazyFreeVB_Count;     // global limit on lazy free list

    BOOL bIsExclusiveMode;   // TRUE if device is in fullscreen mode.

    DWORD dwNBID;                 //Northbridge info obtained from CWDDE-CI call
                                  //we just store the NB  (devid<<16) | venid
    QS_SCRATCH_REGISTERS    *pQS_ScrRegs;

} D3DDEVICE, *LPD3DDEVICE;

/***************************************************************/

typedef struct _ATI_SURFACE_LIST
{
    //256 surface lists
    ATISURFHANDLE SurfaceHandleList[ContextPerBlock];
    //Main Vertex buffer hdr
    DLinkList dlVb;
} ATISURFACELIST, *LPATISURFACELIST;

__inline LPATISURFACELIST GetATISurfaceListPtr( LPDDRAWI_DIRECTDRAW_LCL lpDDLcl )
{
    if( lpDDLcl == NULL )
        return NULL;
    return ( LPATISURFACELIST )( lpDDLcl->lpGbl->dwReserved1 );
}

__inline LPATISURFACELIST GetATISurfaceListPtrDDGbl( LPDDRAWI_DIRECTDRAW_GBL lpDDGbl )
{
    if( lpDDGbl == NULL )
        return NULL;
    return ( LPATISURFACELIST )( lpDDGbl->dwReserved1 );
}

__inline void SetATISurfaceListPtr( LPDDRAWI_DIRECTDRAW_LCL lpDDLcl, LPATISURFACELIST lpSurfaceList )
{
    if( lpDDLcl != NULL )
        lpDDLcl->lpGbl->dwReserved1 = ( DWORD_PTR )lpSurfaceList;
}

__inline DLinkList * GetVBHdrPtr( LPDDRAWI_DIRECTDRAW_GBL lpDDGbl )
{
    LPATISURFACELIST lpSL;

    if( lpDDGbl == NULL || lpDDGbl->dwReserved1 == 0 )
        return NULL;

    lpSL = ( LPATISURFACELIST )( lpDDGbl->dwReserved1 );
    return &lpSL->dlVb;
}

/****************************************************************/

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

#ifndef ZFORMAT_OPTIONS
#define ZFORMAT_OPTIONS

    // Several Z formats are supported in hardware.  The default exported formats
    // can be overridden by registry.  Note that Rage6 HW does not support
    // 24Z packed format, and has limited stencil features.  The 24Z_0S format
    // is actually implemented as a 24-bit Z with 8-bit stencil but the stencil
    // features are not exposed via stencil caps.

    enum ZFORMAT_OPTIONS
    {
        ZFORMAT_16Z_0S = 1,     // 16-bit Z buffer,  no stencil
        ZFORMAT_24Z_0S = 2,     // 24-bit Z buffer,  no stencil
        ZFORMAT_24Z_8S = 4,     // 24-bit Z buffer,  8-bit stencil
        ZFORMAT_32Z_0S = 8      // 32-bit Z buffer,  no stencil

    };
         // all valid z formats
#define ZFORMAT_ALL_VALID  (ZFORMAT_16Z_0S | ZFORMAT_24Z_0S | ZFORMAT_24Z_8S | ZFORMAT_32Z_0S)
        // all formats with stencil
#define ZFORMAT_ALL_STENCIL ZFORMAT_24Z_8S
        // default exposed formats
#define ZFORMAT_DEFAULTS   (ZFORMAT_16Z_0S | ZFORMAT_24Z_0S | ZFORMAT_24Z_8S)

        // max number of Z formats that can be exposed
#define ATI_MAX_Z_FORMATS   4

#endif

#define GetATIDeviceInfo(lpD3DDevice) (lpD3DDevice->lpDevInfo)

__inline DWORD GetNumTextureUnits(LPD3DDEVICE pD3DDevice)
{
    return (pD3DDevice->dwNumTextureUnits);
}
////////////////////////////////////////////////////////////////////////
// GetAsicFamily()
////////////////////////////////////////////////////////////////////////
__inline DWORD GetAsicFamily(LPATIDXOBJECT lpATIDXObj)
{
    return lpATIDXObj->pR200AdapterInfo->ulFamily;
}

////////////////////////////////////////////////////////////////////////
// SetAsicFamily()
////////////////////////////////////////////////////////////////////////
__inline VOID SetAsicFamily(LPATIDXOBJECT lpATIDXObj, DWORD dwFamily)
{
    lpATIDXObj->pR200AdapterInfo->ulFamily = dwFamily;
}


////////////////////////////////////////////////////////////////////////
// GetAsicRevision()
////////////////////////////////////////////////////////////////////////
__inline DWORD GetAsicRevision(LPATIDXOBJECT lpATIDXObj)
{
    return lpATIDXObj->pR200AdapterInfo->ulEmulatedRevision;
}

////////////////////////////////////////////////////////////////////////
// SetAsicRevision()
////////////////////////////////////////////////////////////////////////
__inline VOID SetAsicRevision(LPATIDXOBJECT lpATIDXObj, DWORD dwRevision)
{
    lpATIDXObj->pR200AdapterInfo->ulEmulatedRevision = dwRevision;
}


// General purpose macro for reading memory mapped registers within D3D
__inline DWORD ReadMMReg(LPD3DDEVICE lpD3DDev, DWORD dwRegOffset)
{
    return (lpD3DDev->lpMMReg[dwRegOffset]);
}

// General purpose macro for writing memory mapped registers within D3D
__inline void WriteMMReg(LPD3DDEVICE lpD3DDev, DWORD dwRegOffset, DWORD dwValue)
{

    lpD3DDev->lpMMReg[dwRegOffset] = dwValue;
}


#ifdef WIN2K
extern LPVOID pDdHslGetDisplayDevObj(LPVOID pDevInfo);

#define GetDCHandle(pD3DDev) (pDdHslGetDisplayDevObj(pD3DDev->lpDevInfo))
#define ReleaseDCHandle(hDC)

#endif

#endif


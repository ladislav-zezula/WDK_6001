
#ifndef _R2D3DDDIH_
#define _R2D3DDDIH_

#ifndef _D3DNTHAL_H_
//
// Forward definition for d3dumode.cpp when atidispdd.h is not included
//
typedef struct _DDHALINFO                  *LPDDHALINFO;
typedef struct _DDHAL_DDCALLBACKS          *LPDDHAL_DDCALLBACKS;
typedef struct _DDHAL_DDSURFACECALLBACKS   *LPDDHAL_DDSURFACECALLBACKS;
#endif

#if defined(DONT_USE_CMMQS)
#pragma message("###STOP including CMMQS headers in the header below (ATIDISPDD.H)!")
#endif
#include "atidispdd.h"

#include "atidxhsl.h"

#include <d3dumddi.h>

//
// R3D3DDDI.H contains the data struture shared between UM/KM driver
//
// NOTE: For WOW64 on AM64, pads are put in to align data properly,
//       so that 32bit UMD and 64bit KMD can share the data struture.
//

typedef struct _R2AllocationInfo
{
    DWORD               dwHeap;
    DWORD               dwCaps;
    DWORD               dwFlags;
    DWORD               dwBytesPerPixel;
    DWORD               dwPitch;
    DWORD               dwPitchAlign;
    DWORD               dwHeight;
    DWORD               dwHeightAlign;
    DWORD               dwOffsetAlign;
    BOOL                bShared;
    BOOL                bDXVARenderTarget;
#ifdef WOW6432
    DWORD               dwPad0;
#endif
    DDHSLSURFACEDESC    hslSurfDesc;
    DDPIXELFORMAT       ddPixelFormat;
    DISP4DDVIDMEMDATA   vidMemData;
    //
    // Only used by surfaces created in KM (Primary, Shadow buffer)
    //
    DWORD                           dwModeIndex;
    D3DDDI_VIDEO_PRESENT_SOURCE_ID  VidPnSourceId;
    D3DDDI_RATIONAL                 RefreshRate;        // in: RefreshRate that this primary surface is to be used with    

    DWORD               dwAllocSize;                //Alloc size in btyes
    BOOL                bCPUOptimized;
    BOOL                bExistingSysMem;            //Whether to set ExistingSysMem or not
#ifdef WOW6432
    DWORD               dwPad1;
#endif
} R2AllocationInfo, *PR2AllocationInfo;

typedef struct
{      
    R2AllocationInfo                sAllocInfo;    

    // These are stored when we create the allocations so we can use them in the OpenResource DDI
    D3DDDIFORMAT                    CreateDataFormat;
    D3DDDI_POOL                     CreateDataPool;
    D3DDDIMULTISAMPLE_TYPE          CreateDataMultisampleType;
    UINT                            CreateDataMultisampleQuality;
    UINT                            CreateDataSurfCount;          
    UINT                            CreateDataMipLevels; 
    UINT                            CreateDataFvf;                
    D3DDDI_VIDEO_PRESENT_SOURCE_ID  CreateDataVidPnSourceId;
    D3DDDI_RESOURCEFLAGS            CreateDataFlags;
    UINT                            CreateDataSurfDepth;   
    BOOL                            bStandardAllocation;
#ifdef WOW6432
    DWORD               dwPad0;
#endif    
}R2DDICreateAllocationData, *PR2DDICreateAllocationData;


//
// X64 64bit kernel mode driver and Wow64 32-bit user mode driver have to share the R2DDICreateAllocationData
// struct in the UMD OpenResource DDI.  We want to generate a compiler error when the structs are different 
// in size
//
#define WOW6432_R2DDICreateAllocationData_SIZE 0x118
#define X64_R2DDICreateAllocationData_SIZE 0x118

C_ASSERT(WOW6432_R2DDICreateAllocationData_SIZE == X64_R2DDICreateAllocationData_SIZE);

#if _X86_
#ifdef WOW6432
C_ASSERT(sizeof(R2DDICreateAllocationData) == WOW6432_R2DDICreateAllocationData_SIZE);
#endif
#else
C_ASSERT(sizeof(R2DDICreateAllocationData) == X64_R2DDICreateAllocationData_SIZE);
#endif


#if defined(KMD) || defined(UMD)

//
// NOP3 packet is used to specify
//     <1> A full resource table at the beginning of the each command buffer
//     <2> A new allocation handle is bound to a resource afterward
//
// TODO : Currently this is used to set VB pointer and load texture,
//        this will be used for all D3D resorces (RT/ZB/TXT)
//

#ifndef VS_MAX_NUM_STREAMS
#define VS_MAX_NUM_STREAMS      12
#endif

#ifndef ATI_MAX_NUM_TEX_UNITS
#define ATI_MAX_NUM_TEX_UNITS   6
#endif

typedef struct
{
    DWORD dwInfoNopHeader;
    DWORD dwThreadID;
    DWORD dwBreakIntoDebugger;
    DWORD dwPreambleSize;           // Size in bytes
}UMD_CMDBUF_INFO, *PUMD_CMDBUF_INFO;    

#define PM4_INFO_PACKET_HEADER          (PM4_PACKET3_NOP | D3D_RES_UMD_DEBUG_PACKET | ((sizeof(UMD_CMDBUF_INFO)/sizeof(DWORD)-2) << 16))

//
// Resource ID is to specify D3D allocation handle in command buffer
//
typedef enum _D3DResourceID
{
    D3D_RES_RENDER_TARGET,
    D3D_RES_ZBUFFER,

    D3D_RES_DST_2D,
    D3D_RES_SRC_2D,

    D3D_RES_GUI_DMA_DST,
    D3D_RES_GUI_DMA_SRC,

    D3D_RES_STREAM_0,
    D3D_RES_STREAM_1,
    D3D_RES_STREAM_2,
    D3D_RES_STREAM_3,
    D3D_RES_STREAM_4,
    D3D_RES_STREAM_5,
    D3D_RES_STREAM_6,
    D3D_RES_STREAM_7,
    D3D_RES_STREAM_8,
    D3D_RES_STREAM_9,
    D3D_RES_STREAM_10,
    D3D_RES_STREAM_11,

    D3D_RES_INDEX_BUFFER,

    //
    // NOTE: 1st face of the cubemap is the base texture resource
    //
    D3D_RES_TEXTURE_0,
    D3D_RES_CUBEMAP_0_FACE_1,
    D3D_RES_CUBEMAP_0_FACE_2,
    D3D_RES_CUBEMAP_0_FACE_3,
    D3D_RES_CUBEMAP_0_FACE_4,
    D3D_RES_CUBEMAP_0_FACE_5,
    D3D_RES_TEXTURE_1,
    D3D_RES_CUBEMAP_1_FACE_1,
    D3D_RES_CUBEMAP_1_FACE_2,
    D3D_RES_CUBEMAP_1_FACE_3,
    D3D_RES_CUBEMAP_1_FACE_4,
    D3D_RES_CUBEMAP_1_FACE_5,
    D3D_RES_TEXTURE_2,
    D3D_RES_CUBEMAP_2_FACE_1,
    D3D_RES_CUBEMAP_2_FACE_2,
    D3D_RES_CUBEMAP_2_FACE_3,
    D3D_RES_CUBEMAP_2_FACE_4,
    D3D_RES_CUBEMAP_2_FACE_5,
    D3D_RES_TEXTURE_3,
    D3D_RES_CUBEMAP_3_FACE_1,
    D3D_RES_CUBEMAP_3_FACE_2,
    D3D_RES_CUBEMAP_3_FACE_3,
    D3D_RES_CUBEMAP_3_FACE_4,
    D3D_RES_CUBEMAP_3_FACE_5,
    D3D_RES_TEXTURE_4,
    D3D_RES_CUBEMAP_4_FACE_1,
    D3D_RES_CUBEMAP_4_FACE_2,
    D3D_RES_CUBEMAP_4_FACE_3,
    D3D_RES_CUBEMAP_4_FACE_4,
    D3D_RES_CUBEMAP_4_FACE_5,
    D3D_RES_TEXTURE_5,
    D3D_RES_CUBEMAP_5_FACE_1,
    D3D_RES_CUBEMAP_5_FACE_2,
    D3D_RES_CUBEMAP_5_FACE_3,
    D3D_RES_CUBEMAP_5_FACE_4,
    D3D_RES_CUBEMAP_5_FACE_5,

    D3D_RES_DXVA_OFFSET_Y0,
    D3D_RES_DXVA_PITCH_Y0,
    D3D_RES_DXVA_OFFSET_U0,
    D3D_RES_DXVA_OFFSET_U0_PITCH_UV,
    D3D_RES_DXVA_OFFSET_V0,
    D3D_RES_DXVA_OFFSET_V0_PITCH_UV,
    D3D_RES_DXVA_OFFSET_Y1,
    D3D_RES_DXVA_PITCH_Y1,
    D3D_RES_DXVA_OFFSET_U1,
    D3D_RES_DXVA_OFFSET_U1_PITCH_UV,
    D3D_RES_DXVA_OFFSET_V1,
    D3D_RES_DXVA_OFFSET_V1_PITCH_UV,
    D3D_RES_DXVA_OFFSET_Y2,
    D3D_RES_DXVA_PITCH_Y2,
    D3D_RES_DXVA_OFFSET_U2,
    D3D_RES_DXVA_OFFSET_U2_PITCH_UV,
    D3D_RES_DXVA_OFFSET_V2,
    D3D_RES_DXVA_OFFSET_V2_PITCH_UV,
    D3D_RES_DXVA_DEST_ALLOCATION,

    D3D_RES_ALL,

    D3D_RES_UMD_DEBUG_PACKET
} D3DResourceID, *PD3DResourceID;

// NOTE : If you change the _R2FullResourceTable struct you must update _R2FullResourceSurfTable
typedef struct _R2FullResourceTable
{
    DWORD   dwRenderTargetIdx;
    DWORD   dwZBufferIdx;
    DWORD   dwDst2DIdx;
    DWORD   dwSrc2DIdx;
    DWORD   dwDstGUIDMAIdx;
    DWORD   dwSrcGUIDMAIdx;
    DWORD   dwStreamsIdx[VS_MAX_NUM_STREAMS];
    DWORD   dwIndexBufferIdx;
    DWORD   dwTexturesIdx[ATI_MAX_NUM_TEX_UNITS][6];
    DWORD   dwDXVAIdx[3][6];
    DWORD   dwDXVADestAllocationIdx;
} R2ResourceTable, *PR2ResourceTable;

// NOTE : If you change the _R2FullResourceSurfTable struct you must update _R2FullResourceTable
typedef struct _R2FullResourceSurfTable
{
    PVOID   pRenderTarget;
    PVOID   pZBuffer;
    PVOID   pDst2D;
    PVOID   pSrc2D;
    PVOID   pDstGUIDMA;
    PVOID   pSrcGUIDMA;
    PVOID   pStreams[VS_MAX_NUM_STREAMS];
    PVOID   pIndexBuffer;
    PVOID   pTextures[ATI_MAX_NUM_TEX_UNITS][6];
    PVOID   pDXVA[3][6];
    PVOID   pDXVADestAllocation;
} R2ResourceSurfTable, *PR2ResourceSurfTable;

//
// Type of GART supported by the adapter
//
#define R200_GART_AGP           1
#define R200_GART_PCI           2
#define R200_GART_PCI_EXPRESS   4

//
// Structure used for R200's private query adapter info call,
// shared between UMD and KMD
//
// NOTE: For WOW64 on AM64, if pointer has to be added, proper padding or
//       thunking is needed, so that 32bit UMD and 64bit KMD can communicate.
//
typedef struct _R200AdapterInfo
{
    ULONG   ulChipID;
    ULONG   ulFamily;
    ULONG   ulEmulatedRevision;
    ULONG   ulVramInstalled;
    ULONG   ulVramType;
    ULONG   ulVramBitWidth;
    USHORT  usXClock;
    USHORT  usMClock;
    ULONG   ulSubsystemID;

    ULONG   ulCaps1;
        
    ULONG   ulNBCaps;
    ULONG   ulSBCaps;
    USHORT  usNBVendorID;
    USHORT  usNBDeviceID;
    USHORT  usSBVendorID;
    USHORT  usSBDeviceID;
    ULONG   ulNBType;
    ULONG   ulSBType;

    ULONG   ulCiCpuCaps;

    ULONG   ulGartSupported;
} R200AdapterInfo, *PR200AdapterInfo;

#endif // defined(KMD) || defined(UMD)

#endif // _R2D3DDDIH_



#ifndef _R2KMDDIH_
#define _R2KMDDIH_  1

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#if 1
#include <ntddk.h>
#include <dispmprt.h>
#endif

#include <ntddk.h>

#include <windef.h>
#include <wingdi.h>

#include <winerror.h>
#include <winddi.h>
#include <d3dkmddi.h>

#include "rage.h"

#include <dx95type.h>
#include "r2d3dddi.h"

//
// Include header for R200 register
//
#define  RADEON_ASIC    0x200
#include "radeon.h"

//
// Include header for Type3 PM4 Opcode
//
#include "ipt.h"

//
// Include header for HSL surface tiling definition
//
#include "atidxhsl.h"

#define DMABUF_SIZE (64*ONE_K)

//
// Include header for BLT related definition
//
#define  _ATIDXOBJ_H    1
#define  _RECTFUNCS_H   1
typedef  PVOID          LPATIDXOBJECT;
typedef  PVOID          LPATISURFINFO;
typedef  PVOID          LPATIDXOBJECT;

#include "pm4.h"
#include "cmm_mp.h"

//
// Separated from blt.h
// 
#define BLTFLAG_SRC_COLORKEY         0x00000010
#define BLTFLAG_DST_COLORKEY         0x00000020

#define SUBMIT_SMALL_PITCH_2D_SRCCPY_BLT_SIZE  29
#define SUBMIT_2D_BLT_SIZE                      (SUBMIT_SMALL_PITCH_2D_SRCCPY_BLT_SIZE)

LPDWORD
Submit2dBlt2(
    DWORD  dwSrcOffPtch, 
    DWORD  dwSrcLeft, 
    DWORD  dwSrcTop, 
    DWORD  dwDstOffPtch, 
    DWORD  dwDstLeft, 
    DWORD  dwDstTop, 
    DWORD  dwWidth, 
    DWORD  dwHeight,
    DWORD  dwFormat,
    DWORD  dwBltFlags, 
    DWORD  dwSrcKeyColor, 
    DWORD  dwDstKeyColor,
    DWORD *PM4Entries);

//
// Include header PM4 definition
//
#define  _ATIDXINC_H    1
#include "tplates.h"


__inline DWORD ByteAlign(DWORD Operand, DWORD Alignment)
{
    return ((Operand + (Alignment -1)) & ~(Alignment -1));
}

#define RECTCOUNTLIMIT          64   // Should be cacl as (CMDBUF_SIZE – MAX_PREABLE_SIZE)/(MAX_NUMBER_OF_BYTES_PER_EACH_RECTBLT)

typedef struct _CMDBUF_STATS
{
    DWORD   dwLastSeenSplitPoint;
    DWORD   dwSplitPointCo;
    DWORD   dwDeselectedSlotCo;         // Count of times when Slot handle has beem set to NULL allocation
    DWORD   dwResListSize;
    DWORD   dwDrawCmdCo;
}CMDBUF_STATS, *PCMDBUF_STATS;

typedef struct _R2D3DDevice
{
    HANDLE                  hDevice;        // Runtime device handle
    DXGK_DEVICEINFO     ddiDeviceInfo;  // Returned to runtime
    PHW_DEVICE_EXTENSION    pAdapter;       // Adapter for device global info
    UINT                    ulCurSplitOffset; // Offset of first DWORD past the last drawing command

#if DBG
    CMDBUF_STATS            sCmdBufStats;
#endif

    //
    // Table for all resources that can be used by GPU at once
    //
    union
    {
        R2ResourceTable     resTable;
        DWORD               resArray[D3D_RES_ALL];
    };    

} R2D3DDevice, *PR2D3DDevice;

typedef struct
{
    DWORD           dwEngineID;
    PR2D3DDevice    pDevice;
}R2D3DContext, *PR2D3DContext;

//
// Definition used by memory transfer routine
//

_inline DWORD
MakeAtiOffPitch(
    DWORD   dwAtiOffset,
    DWORD   dwAtiPitch,
    DWORD   dwAtiTile)
{
    return (((dwAtiPitch << DST_PITCH_OFFSET__DST_PITCH__SHIFT) & 
             DST_PITCH_OFFSET__DST_PITCH_MASK)                     | 
            ((dwAtiOffset << DST_PITCH_OFFSET__DST_OFFSET__SHIFT) & 
             DST_PITCH_OFFSET__DST_OFFSET_MASK)                    |
            ((dwAtiTile << DST_PITCH_OFFSET__DST_TILE__SHIFT) & 
             DST_PITCH_OFFSET__DST_TILE_MASK));
}

//
// Support for KMD present
//
typedef enum _E_FLUSHFREE {
    FLUSH_ONLY     = 1,
    FREE_ONLY      = 2,
    FLUSH_AND_FREE = 3
} E_FLUSHFREE;

DWORD
MPSrcCopyBlt(
    LPDDHSLSURFACEDESC  lpSurfDescSrc,
    D3DKMT_HANDLE       hSrcAllocation,
    LPDDHSLSURFACEDESC  lpSurfDescDst, 
    D3DKMT_HANDLE       hDstAllocation,
    LPDDHAL_BLTDATA     lpBltData, 
    LPCMDBUFF           lpCBCurrent);

DWORD
MPColorFill(
    LPDDHSLSURFACEDESC  lpSurfDescDst,
    D3DKMT_HANDLE       hAllocation,
    LPDDHAL_BLTDATA     lpBltData,
    LPCMDBUFF           lpCBCurrent);

//
// Definition for special command in qsentry.c
//
#define dwRBCmd     dwReserved9xLib

#define SUBMIT_RING_BUFFER      1
#define QUERY_TIME_STAMP        2
#define SUBMIT_DMA_BUFFER       3

//
// Get video mode info from mode index
//
typedef PVOID   HDAL;

BOOL  DALGetModeVMIEx(HDAL hDAL, VIDEO_MODE_INFORMATION FAR * lpVMI,
                      ULONG ulDriverID, ULONG ulModeIndex);

//
// Defintion for register access macros and functions
//
ULONG
ReadMmRegisterUlong(
    PVOID pvMmBaseAddress,
    ULONG ulRegister
    );

VOID
WriteMmRegisterUlong(
    PVOID pvMmBaseAddress,
    ULONG ulRegister,
    ULONG ulValue
    );

#define ATI_INPD(p, r)              ReadMmRegisterUlong((p), (r))

#define ATI_OUTPD(p, r, v)          WriteMmRegisterUlong((p), (r), (v))

#endif // _R2KMDDIH_


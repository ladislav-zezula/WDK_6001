/*****************************************************************************\
*
*                           *******************
*                           *   SAMPLE CODE   *
*                           *******************
*
* Copyright (c) 2003 Microsoft Corporation.  All rights reserved.
\*****************************************************************************/


#define DONT_USE_CMMQS  1

#define  INITGUID
#include "r2kmddi.h"
#include "debug.h"
#include "privaloc.h"
#include "cwddeci.h"
#include "cwddedi.h"
#include <evntrace.h>

#ifdef ENABLE_COMCONTROL
#include "cloneumkm.h"
#endif


VOID vAsicRegisterSGTlocation(PHW_DEVICE_EXTENSION pHwDeviceExtension);
void LDDReserveQSMem(PHW_DEVICE_EXTENSION pHwDeviceExtension);
BOOL bAsicResetGui(PHW_DEVICE_EXTENSION pHwDeviceExtension);

DWORD   gdwDMAPacketId = 1;
BOOL    gbEnableDMASplitting = TRUE;

// Used to get a resource enty will NULL handle generated
#define RESITEM_RELEASED 0xffffffff

#define RBCMD_SIZE_INDWORDS (0x20)

#define SURFACE0_INFO__SURF0_TILE_MODE__SHIFT              0x00000010

#define ATI_TAG '_ITA'
#define ACPI_HARDWARE_ID 0xFFFF
#define MAX_SOURCE_MODES    3   // assumes max of 3 modes on a source.
#define MAX_TARGET_MODES    3   // assumes max of 3 modes on a target.

BOOLEAN gLoggingEnabled = FALSE;
ULONG gLoggingFlags = 0;
UCHAR gLoggingLevel = 0;

// {A7BF27A0-7401-4733-9FED-FDB51067FECC}
DEFINE_GUID(R200_DUMMY_LOGGING,
0xa7bf27a0, 0x7401, 0x4733, 0x9f, 0xed, 0xfd, 0xb5, 0x10, 0x67, 0xfe, 0xcc);

VOID
DummyTrace(
    HW_DEVICE_EXTENSION* Adapter
    );
#define DUMMY_TRACE(Adapter)    {if (gLoggingEnabled) DummyTrace(Adapter);}


NTSTATUS
SetVidPnSourceStatus(
    IN PVOID MiniportDeviceContext,
    IN D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId,
    IN BOOLEAN Enable
    );

NTSTATUS InitRingBuffer(PHW_DEVICE_EXTENSION pHwDeviceExtension);

VOID RestoreLastFenceToHwRegister(
    IN HW_DEVICE_EXTENSION *pAdapter
    )
{
    // Restore last completed fence into hardware register.
    *((volatile ULONG *)(((DWORD *)pAdapter->pvMmr) + mmGUI_SCRATCH_REG0)) = pAdapter->PrevSubmitFenceIDArray[MULTI_ENGINE_NODE_3D];
    *((volatile ULONG *)(((DWORD *)pAdapter->pvMmr) + mmGUI_SCRATCH_REG4)) = pAdapter->PrevPreemptFenceIDArray[MULTI_ENGINE_NODE_3D];

    *((volatile ULONG *)(((DWORD *)pAdapter->pvMmr) + mmGUI_SCRATCH_REG2)) = pAdapter->PrevSubmitFenceIDArray[MULTI_ENGINE_NODE_VIDEO];
    *((volatile ULONG *)(((DWORD *)pAdapter->pvMmr) + mmGUI_SCRATCH_REG6)) = pAdapter->PrevPreemptFenceIDArray[MULTI_ENGINE_NODE_VIDEO];
}

BOOL AreAllAllocationsDXVARenderTargets(DXGKARG_RENDER* pRenderDDI)
{
    DWORD               dwIdx;
    PR2AllocationInfo   pDrvData;

    for (dwIdx = 0; dwIdx < pRenderDDI->AllocationListSize; dwIdx++)
    {
        pDrvData = (PR2AllocationInfo)pRenderDDI->pAllocationList[dwIdx].hDeviceSpecificAllocation;
        
        if (pDrvData != NULL)
        {            
            if (pDrvData->bDXVARenderTarget == FALSE)
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

//
// Per adapter DDI entry points
//
NTSTATUS
D3DDDIQueryAdapterInfo(
    VOID                               *InterfaceContext,
    CONST DXGKARG_QUERYADAPTERINFO     *pDDIQAIData);

NTSTATUS
D3DDDICreateDevice(
    VOID                           *InterfaceContext,
    DXGKARG_CREATEDEVICE           *pDDICDD);

NTSTATUS
D3DDDICreateAllocation(
    VOID                           *InterfaceContext,
    DXGKARG_CREATEALLOCATION       *pDDICAData);

NTSTATUS
D3DDDIDescribeAllocation(
    VOID*                       InterfaceContext,
    DXGKARG_DESCRIBEALLOCATION* pDDIDescribeAlloc);

NTSTATUS
D3DDDIGetStandardAllocationDriverData(
    VOID                                     *InterfaceContext,
    DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA       *pDDIGetStandardAllocationDriverData);

NTSTATUS
D3DDDIDestroyAllocation(
    VOID                                   *InterfaceContext,
    CONST DXGKARG_DESTROYALLOCATION        *pDDIDAData);

NTSTATUS
D3DDDIOpenAllocation(
    VOID                                   *InterfaceContext,
    CONST DXGKARG_OPENALLOCATION           *pDDIDAData);

NTSTATUS
D3DDDIAcquireSwizzlingRange(
    VOID                                 *InterfaceContext,
    DXGKARG_ACQUIRESWIZZLINGRANGE        *pDDIASRData);

NTSTATUS
D3DDDIReleaseSwizzlingRange(
    VOID                                *InterfaceContext,
    CONST DXGKARG_RELEASESWIZZLINGRANGE *pDDIRSRData);

NTSTATUS
D3DDDISubmitCommand(
    VOID                               *InterfaceContext,
    CONST DXGKARG_SUBMITCOMMAND        *pDDISCData);

NTSTATUS
D3DDDIQueryCurrentFence(
    VOID                               *InterfaceContext,
    UINT                               *plCurrentFence);

NTSTATUS
D3DDDIControlInterrupt(
    VOID                               *InterfaceContext,
    CONST DXGK_INTERRUPT_TYPE          InterruptType,
    BOOLEAN                            EnableInterrupt);

NTSTATUS
D3DDDIBuildPagingBuffer(
    HANDLE                          hAdapter,
    DXGKARG_BUILDPAGINGBUFFER      *pParam);

NTSTATUS
D3DDDIPatchDmaBuffer(
    VOID                       *InterfaceContext,
    CONST DXGKARG_PATCH        *pDDIPatchDmaBuffer);

NTSTATUS
SetPointerShape(
    HW_DEVICE_EXTENSION    *pHwDeviceExtension,
    DWORD                   Output,
    DWORD                   Flags,
    DWORD                   cxCursor,
    DWORD                   cyCursor,
    DWORD                   lSrcDelta,
    CONST VOID*             pPixels);

VOID
SetPointerPosition(
    HW_DEVICE_EXTENSION    *pHwDeviceExtension,
    DWORD                   Output,
    BOOL                    Visible,
    DWORD                   Column,
    DWORD                   Row);

VOID
SetupPrimarySurfaceAllocationInfo(
    D3DDDIFORMAT            Format,
    VIDEO_MODE_INFORMATION *pModeInfo,
    DWORD                   dwPSMCAddress,
    DWORD                   dwCaps,
    R2AllocationInfo       *pPSAllocInfo);

//
// Per device DDI entry points
//
NTSTATUS
D3DDDIDestroyDevice(
    HANDLE  hDevice);

NTSTATUS
D3DDDIOpenAllocation(
    HANDLE                              hDevice,
    CONST DXGKARG_OPENALLOCATION   *pDDIOAData);

NTSTATUS
D3DDDICloseAllocation(
    HANDLE                              hDevice,
    CONST DXGKARG_CLOSEALLOCATION  *pDDICAData);

NTSTATUS
D3DDDIRenderInternal(
    HANDLE                  hContext,
    DXGKARG_RENDER          *pDDIRenderData,
    BOOL                    bFromPresent);

NTSTATUS
D3DDDIRender(
    HANDLE              hDevice,
    DXGKARG_RENDER *pDDIRenderData);

NTSTATUS
D3DDDIPresent(
    HANDLE                  hDevice,
    DXGKARG_PRESENT    *pDDIPresentData);

NTSTATUS
D3DDDIPreemptCommand(
    HANDLE hAdapter,
    CONST DXGKARG_PREEMPTCOMMAND* pDDIPCData);

NTSTATUS
D3DDDISetVidPnSourceVisibility(
    HANDLE,
    CONST DXGKARG_SETVIDPNSOURCEVISIBILITY*);

NTSTATUS D3DDDIResetFromTimeout(
    HANDLE hAdapter);

NTSTATUS D3DDDIRestartFromTimeout(
    HANDLE hAdapter);

NTSTATUS
D3DDDIEscape(
    VOID                       *InterfaceContext,
    CONST DXGKARG_ESCAPE   *pDDIEscape);

NTSTATUS
D3DDDICollectDbgInfo(
    HANDLE                            hAdapter,
    CONST DXGKARG_COLLECTDBGINFO *pDDICollectDbgInfo);

// VidPN management LDDM display miniport DDIs

NTSTATUS
D3DDDICommitVidPn(
    HANDLE                          i_hAdapter,
    CONST DXGKARG_COMMITVIDPN*  i_pDDICommitVidPN);

NTSTATUS
D3DDDIIsSupportedVidPn_Test
(
    IN     VOID*                          i_pvInterfaceContext,
    IN OUT DXGKARG_ISSUPPORTEDVIDPN*  io_dmddi_pIsSupportedVidPnArg
);

NTSTATUS
D3DDDIIsSupportedVidPn_XddmParity
(
    IN     VOID*                          i_pvInterfaceContext,
    IN OUT DXGKARG_ISSUPPORTEDVIDPN*  io_dmddi_pIsSupportedVidPnArg
);

NTSTATUS
D3DDDIUpdateActiveVidPnPresentPath
(
    HANDLE                                            hAdapter,
    CONST DXGKARG_UPDATEACTIVEVIDPNPRESENTPATH*   pDDIUpdateActiveVidPnPresentPath
);



NTSTATUS
D3DDDIRecommendFunctionalVidPn_XddmParity
(
    CONST VOID* CONST                                  i_pvInterfaceContext,
    CONST DXGKARG_RECOMMENDFUNCTIONALVIDPN* CONST  i_pRecommendFunctionalVidPnArg
);


NTSTATUS
D3DDDIRecommendFunctionalVidPn_Test
(
    CONST VOID* CONST                                  i_pvInterfaceContext,
    CONST DXGKARG_RECOMMENDFUNCTIONALVIDPN* CONST  i_pRecommendFunctionalVidPnArg
);


NTSTATUS
D3DDDIEnumVidPnCofuncModality_XddmParity
(
    VOID* CONST                                       i_pvInterfaceContext,
    CONST DXGKARG_ENUMVIDPNCOFUNCMODALITY* CONST  i_pEnumVidPnCofuncModalityArg
);


NTSTATUS
D3DDDIEnumVidPnCofuncModality_Test
(
    VOID* CONST                                       i_pvInterfaceContext,
    CONST DXGKARG_ENUMVIDPNCOFUNCMODALITY* CONST  i_pEnumVidPnCofuncModalityArg
);

enum
{
    NUMBER_OF_VIDEO_OUTPUT_CODECS = 2,
    NUMBER_OF_VIDEO_PRESENT_SOURCES = NUMBER_OF_VIDEO_OUTPUT_CODECS,

    // Video present source IDs must be from a 0-based dense index set.
    VIDPN_SOURCE1_ID = 0,
    VIDPN_SOURCE2_ID = 1,

    NUMBER_OF_VIDEO_OUTPUTS  = 2,
    NUMBER_OF_VIDEO_PRESENT_TARGETS = NUMBER_OF_VIDEO_OUTPUTS,

    // Video present target IDs must be from a 0-based dense index set.
    VIDPN_TARGET1_ID = 0 | HW_ID_DISPLAY_CHILD,
    VIDPN_TARGET2_ID = 1 | HW_ID_DISPLAY_CHILD,
};

NTSTATUS
AcquireAvailableXddmDisplayModeSet
(
    CONST HW_DEVICE_EXTENSION*  i_pHwDeviceExtension,
    VIDEO_MODE_INFORMATION**    o_ppXddmDisplayModeSet,
    SIZE_T*                     o_psztNumXddmDisplayModesAcquired
);


BOOLEAN IsVidPnSourceIdValid( IN  D3DDDI_VIDEO_PRESENT_SOURCE_ID  i_VidPnSourceId );
BOOLEAN IsVidPnTargetIdValid( IN  D3DDDI_VIDEO_PRESENT_TARGET_ID  i_VidPnTargetId );

#ifdef ENABLE_COMCONTROL

//Methods for COM control support

NTSTATUS
    R200GetChildData(
    __in  PHW_DEVICE_EXTENSION PrimaryHwDeviceExtension,
       __inout  ULONG *pulCount,
       __in ULONG ulFlag,
       __inout_ecount(*pulCount) ULONG* pulID
    );
NTSTATUS GetID(__in HW_DEVICE_EXTENSION *pHwDeviceExtension, __inout PR200_GetIDData pGetIDData );
NTSTATUS GetActiveTopology(__in HW_DEVICE_EXTENSION *pHwDeviceExtension, __inout PR200_TopologyData pTopologyData);
ULONG GetConnectedTargetIDs(__in HW_DEVICE_EXTENSION *pHwDeviceExtension,__inout_ecount(ulCount) ULONG * pulIdx, __in ULONG Index,__in ULONG ulCount);
ULONG GetConnectedTargetCount(__in PHW_DEVICE_EXTENSION HwDeviceExtension);

#ifdef ALLOC_PRAGMA
#pragma alloc_text(PAGE,R200GetChildData)
#pragma alloc_text(PAGE,GetID)
#pragma alloc_text(PAGE,GetActiveTopology)
#pragma alloc_text(PAGE,GetConnectedTargetIDs)
#pragma alloc_text(PAGE,GetConnectedTargetCount)
#endif

#endif



VP_STATUS
GetRegistryUlongCallback(
    __in  PHW_DEVICE_EXTENSION pHwDeviceExtension,
    __inout  PVOID pvContext,
    __in PWSTR pwszName,
    __in_bcount(ulLength)  PVOID pvData,
    __in  ULONG ulLength
    );

void EnforceHwSegRestrictions(HW_DEVICE_EXTENSION *pAdapter, DXGK_ALLOCATIONINFO *pAllocInfo);

BOOLEAN AtiDMAInterrupt_enable(PHW_DEVICE_EXTENSION pHwDeviceExtension, DWORD dwIRQSource);
BOOLEAN AtiVSyncInterrupt_enable(PHW_DEVICE_EXTENSION pHwDeviceExtension);
BOOLEAN AtiVSyncInterrupt_disable(PHW_DEVICE_EXTENSION pHwDeviceExtension);

NTSTATUS PresentPreRenderCmdBufProcessing(DXGKARG_RENDER* pRenderArg, D3DKMT_HANDLE hSrc, D3DKMT_HANDLE hDst);

//
// Definition for EngDebugBreak
//
#ifdef DEBUG
#define EngDebugBreak   DbgBreakPoint
#else
#define EngDebugBreak()
#endif

//
// Pseudo handle for primary surface
//
#define PRIMARY_SURFACE_ALLOCATION_HANDLE   ((D3DKMT_HANDLE)'PSAH')

//
// D3D DDI implementation
//

VOID
D3DDDIInterfaceReference(
    PVOID   pContext)
{
}

VOID
D3DDDIInterfaceDereference(
    PVOID   pContext)
{
}

typedef enum {DMA_PACKET_TYPE_INVALID=0, DMA_PACKET_TYPE_PRESENT_FLIP, DMA_PACKET_TYPE_PRESENT_COLORFILL, DMA_PACKET_TYPE_PRESENT_BLT, DMA_PACKET_TYPE_RENDER} R200_DAMPACKET_TYPE;

typedef struct _R200_DMA_PRIVATEDATA
{
    BOOL                bBreakOnSubmit;
    DWORD               dwPacketId;
    R200_DAMPACKET_TYPE Type;
} R200_DMA_PRIVATEDATA, *PR200_DMA_PRIVATEDATA;

BOOL R200AGPEnabled(PHW_DEVICE_EXTENSION    pHwDeviceExtension)
{
    if (CapEnabled(pHwDeviceExtension->dwCailCaps, DDI_CAP_AGP))
    {
        return (pHwDeviceExtension->agpApertureBase.QuadPart &&
                pHwDeviceExtension->agpApertureSize.QuadPart);
    }
    else
    {
        return (FALSE);
    }
}

//This macro checks if a value is a power of two.
__inline DWORD IsPowerOfTwo(DWORD dwValue)
{
 return ((dwValue & (dwValue-1)) == 0);
}

VOID DALSetPalette(HDAL hDAL, ULONG ulDriverID, LPDEVCLUT lpPalette,
                   ULONG ulStart, ULONG ulLength);

NTSTATUS APIENTRY
D3DDDISetPalette(
    VOID                           *InterfaceContext,
    CONST DXGKARG_SETPALETTE   *pSetPalette)
{
    PHW_DEVICE_EXTENSION    pHwDeviceExtension = ((PHW_DEVICE_EXTENSION*)InterfaceContext)[0];

    DALSetPalette(pHwDeviceExtension->pvhDal,
                  pSetPalette->VidPnSourceId,
                  (LPDEVCLUT)pSetPalette->pLookupTable,
                  pSetPalette->FirstEntry,
                  pSetPalette->NumEntries);

    return (STATUS_SUCCESS);
}

NTSTATUS APIENTRY
D3DDDISetPointerShape(
    VOID                               *InterfaceContext,
    CONST DXGKARG_SETPOINTERSHAPE  *pPointerAttributes)
{

    NTSTATUS    stRet;
    UINT        Flags;

    //
    // Coverting into local flags as SetPointerShape can't compile if d3dukmdt.h is included there
    //
    Flags  = (pPointerAttributes->Flags.Monochrome) ? USE_MONOCURSOR : 0;
    Flags |= (pPointerAttributes->Flags.Color) ? (USE_COLORCURSOR | USE_ALPHACURSOR) : 0;

    ASSERT(Flags);

    stRet = SetPointerShape(((PHW_DEVICE_EXTENSION*)InterfaceContext)[0],
                           pPointerAttributes->VidPnSourceId,
                           Flags,
                           pPointerAttributes->Width,
                           pPointerAttributes->Height,
                           pPointerAttributes->Pitch,
                           pPointerAttributes->pPixels);

    
    
    if (NT_SUCCESS(stRet))
    {
        return STATUS_SUCCESS;
    }
    else if (stRet == STATUS_NO_MEMORY)
    {
        return STATUS_NO_MEMORY;
    }
    else
    {
        DPF(DBG_ERROR, "SetPointerShape: Unsupported code path");
//        DBG_BREAK;
        return STATUS_SUCCESS;
    }
}


NTSTATUS APIENTRY
D3DDDISetPointerPosition(
    VOID                                   *InterfaceContext,
    CONST DXGKARG_SETPOINTERPOSITION   *pSetPos)
{
    SetPointerPosition(((PHW_DEVICE_EXTENSION*)InterfaceContext)[0],
                       pSetPos->VidPnSourceId,
                       pSetPos->Flags.Visible,
                       pSetPos->X,
                       pSetPos->Y);

    return (STATUS_SUCCESS);
}


#define INDEX_DMA_COPY_BUFFER  0
#define INDEX_START_IO_BUFFER  1
#define INDEX_AA_FONT_CACHE    2
#define INDEX_MMLIB_BUFFER_AGP 3
#define INDEX_MMLIB_BUFFER_PCI 4
#define INDEX_MMLIB_BUFFER_VID 5

#define CB_SIZE_BYTES 64*1024

extern BOOL gbVidMMPrimary;


VOID
vEnableBusmastering(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    )
//
// DESCRIPTION:
//  Turn on bus mastering in BUS_CNTL for PM4 support
//
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//
// RETURN VALUE:
//  None.
//
//
{
    ULONG ulData;

    //
    // Ensure DMA is enabled in the HBIU [GG] 20/03/00
    //
    ulData  = *(((DWORD *)pHwDeviceExtension->pvMmr) + mmBUS_CNTL);
    ulData &= ~BUS_CNTL__BUS_MASTER_DIS;
    *(((DWORD *)pHwDeviceExtension->pvMmr) + mmBUS_CNTL) = ulData;
}

VOID
vSetAgpBaseAndTop(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    )
//
// DESCRIPTION:
//  Set AGP base and extent for PM4 support
//
// PARAMETERS:
//  pHwDeviceExtension  Points to per-adapter device extension.
//
// RETURN VALUE:
//  None.
//
//
{
    ULONG ulData;

    if (!R200AGPEnabled(pHwDeviceExtension))
    {
        //
        // If AGP is disabled by software, AGP is explicitly disabled in the ASIC.
        //
        // Ensure that AGP is disabled by making sure the start address
        // is higher than the "top" address.
        //

        *(((DWORD *)pHwDeviceExtension->pvMmr) + mmMC_AGP_LOCATION) = MC_AGP_LOCATION__MC_AGP_START_MASK;
        *(((DWORD *)pHwDeviceExtension->pvMmr) + mmAGP_BASE)        = 0;
    }
    else
    {
        ULONG   ulAgpBaseReg, ulAgpTop;

        // mmAGP_BASE reflects the host CPUs idea of where AGP space is,
        // *not* where the ASIC believes AGP space resides.
        ulAgpBaseReg = pHwDeviceExtension->agpPhysicalAddress.LowPart;
        *(((DWORD *)pHwDeviceExtension->pvMmr) + mmAGP_BASE)        = ulAgpBaseReg;

        // MC_AGP_LOCATION reflects the memory controller address of where
        // AGP space is, and how large AGP space is.  Note that for the time
        // being, we simply make the location identical to AGP_BASE.
        ulAgpTop = ulAgpBaseReg + (ULONG )(pHwDeviceExtension->agpApertureSize.LowPart - 1);
        *(((DWORD *)pHwDeviceExtension->pvMmr) + mmMC_AGP_LOCATION) = (ulAgpTop & MC_AGP_LOCATION__MC_AGP_TOP_MASK) | (ulAgpBaseReg >> 16);
    }
}

static VOID
SetPciAgpState(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    )
{
    // Do we need to disable bus mastering before setting AGP location?

    vSetAgpBaseAndTop(pHwDeviceExtension);

    vEnableBusmastering(pHwDeviceExtension);
}

NTSTATUS
R200QueryAdapterInfo(
    R200AdapterInfo             *pR200AdapterInfo,
    PHW_DEVICE_EXTENSION        pHwDeviceExtension,
    UINT                        Size)
{
    if (Size < sizeof(R200AdapterInfo))
    {
        return STATUS_INVALID_PARAMETER;
    }

    pR200AdapterInfo->ulChipID             = pHwDeviceExtension->usDeviceId;
    pR200AdapterInfo->ulFamily             = pHwDeviceExtension->ulChipFamily;
    pR200AdapterInfo->ulVramInstalled      = pHwDeviceExtension->ulVRamSizeAvailable;
    pR200AdapterInfo->ulVramType           = pHwDeviceExtension->ulVRamType;
    pR200AdapterInfo->ulVramBitWidth       = pHwDeviceExtension->ulVRamBitWidth;
    pR200AdapterInfo->usXClock             = pHwDeviceExtension->usXclkFreq;
    pR200AdapterInfo->usMClock             = pHwDeviceExtension->usMclkFreq;
    pR200AdapterInfo->ulSubsystemID        = pHwDeviceExtension->usSubSystemId;
    pR200AdapterInfo->ulNBCaps             = pHwDeviceExtension->ulNBCaps;
    pR200AdapterInfo->usNBVendorID         = pHwDeviceExtension->usNbVendorId;
    pR200AdapterInfo->usNBDeviceID         = pHwDeviceExtension->usNbDeviceId;
    pR200AdapterInfo->usSBVendorID         = pHwDeviceExtension->usSbVendorId;
    pR200AdapterInfo->usSBDeviceID         = pHwDeviceExtension->usSbDeviceId;

    // The following fields are not actually useful
    pR200AdapterInfo->ulNBType             = 0;
    pR200AdapterInfo->ulSBType             = 0;
    pR200AdapterInfo->ulSBCaps             = 0;
    //
    // ulCaps1 is used by CheckPrimaryTiling()
    // NOTE : The primary is probably not tiled when display DLL is gone.
    //        When primary is tiled, ulCaps1 should be
    //             CIASICRANGESCAPS1_TILING_CAP          |
    //             CIASICRANGESCAPS1_PRIMARYTILED_MACRO
    //
    pR200AdapterInfo->ulCaps1              = 0;  // Not tiled in any way

    pR200AdapterInfo->ulEmulatedRevision   = 3;

    // It can be safely assumed that almost all current CPUs support MMX
    pR200AdapterInfo->ulCiCpuCaps = CICPUFLAG_MMX | CICPUFLAG_CPUID;

    pR200AdapterInfo->ulGartSupported      = 0;

    if (R200AGPEnabled(pHwDeviceExtension))
    {
        pR200AdapterInfo->ulGartSupported  |= R200_GART_AGP;
    }

     return STATUS_SUCCESS;
}

NTSTATUS
D3DDDIQueryAdapterInfo(
    VOID                           *InterfaceContext,
    CONST DXGKARG_QUERYADAPTERINFO *pDDIQAIData)
{
    PHW_DEVICE_EXTENSION    pHwDeviceExtension = ((PHW_DEVICE_EXTENSION*)InterfaceContext)[0];
    DXGK_DRIVERCAPS        *pDriverCaps;
    DXGK_QUERYSEGMENTIN    *pQuerySegmentIn  = (DXGK_QUERYSEGMENTIN *)pDDIQAIData->pInputData;
    DXGK_QUERYSEGMENTOUT   *pQuerySegmentOut = (DXGK_QUERYSEGMENTOUT *)pDDIQAIData->pOutputData;
    PMEMHEAP_COMBINED_POOL  pMHP;
    PMEMHEAP_POOL           pMHPPool;
    DWORD                   dwTotalPoolSize;
    DWORD                   dwMinSegmentSize = 0;
    DWORD                   PoolSize;
    NTSTATUS                Ret;
    ULONG                   ulDXVASegSub = 0;
    ULONG                   ulFBSegSub = 0;
    ULONG                   ulAGPSegSub = 0;

    switch (pDDIQAIData->Type)
    {
    case DXGKQAITYPE_UMDRIVERPRIVATE:
        {
            R200AdapterInfo    *pR200AdapterInfo;

            pR200AdapterInfo = (R200AdapterInfo *)pDDIQAIData->pOutputData;

            // return info such as chip ID in the private driver data
            if (R200QueryAdapterInfo(pR200AdapterInfo, pHwDeviceExtension, pDDIQAIData->OutputDataSize) != STATUS_SUCCESS)
            {
                return (STATUS_INVALID_PARAMETER);
            }
        }
        break;

    case DXGKQAITYPE_DRIVERCAPS:
        pDriverCaps = (DXGK_DRIVERCAPS*) pDDIQAIData->pOutputData;

        pDriverCaps->PointerCaps.Monochrome = TRUE;
        pDriverCaps->PointerCaps.Color = TRUE;
        pDriverCaps->PointerCaps.Reserved = 0;
        pDriverCaps->MaxPointerWidth = CURSOR_MAX_X;
        pDriverCaps->MaxPointerHeight = CURSOR_MAX_Y;
        pHwDeviceExtension->ulAsicBugs |= ASICBUG_CUR_MODE_NOT_LOCKABLE;

        pDriverCaps->HighestAcceptableAddress.QuadPart = 0xFFFFFFFF;
        pDriverCaps->MaxAllocationListSlotId = D3D_RES_ALL;
        pDriverCaps->NumberOfSwizzlingRanges = 8;
        // Driver doesn't use message based interrupt.
        pDriverCaps->InterruptMessageNumber = 0;
        pDriverCaps->GammaRampCaps.Gamma_Rgb256x3x16 = TRUE;
        pDriverCaps->MaxQueuedFlipOnVSync = 1;
        pDriverCaps->FlipCaps.FlipOnVSyncWithNoWait = TRUE;
        pDriverCaps->FlipCaps.FlipOnVSyncMmIo = TRUE;
        pDriverCaps->SchedulingCaps.MultiEngineAware = TRUE;
        pDriverCaps->GpuEngineTopology.NbAsymetricProcessingNodes = MULTI_ENGINE_COUNT;
        pDriverCaps->MemoryManagementCaps.PagingNode = 0;

        break;

    case DXGKQAITYPE_QUERYSEGMENT:

        //
        // Get the CMM pool information.
        //
        pMHP = pHwDeviceExtension->pMHP_info;

        dwTotalPoolSize = pMHP->dwVidMmPoolSizes[MHP_POOL_TYPE_FRAME_BUFFER];

        if (DlGetRegistryParameters(pHwDeviceExtension->DeviceHandle,
                                    L"LDDMMinFBSize",
                                    FALSE,
                                    GetRegistryUlongCallback,
                                    &dwMinSegmentSize) == NO_ERROR)
        {
            if (dwMinSegmentSize > dwTotalPoolSize)
            {
                PoolSize = dwTotalPoolSize;
            }
            else if (dwMinSegmentSize < 8*1024*1024)
            {
                PoolSize = 8*1024*1024;
            }
            else
            {
                PoolSize = dwMinSegmentSize;
            }
        }
        else
        {
            PoolSize = dwTotalPoolSize;
        }

        //
        // Set AGP aperture base and size
        //
        pHwDeviceExtension->agpApertureBase = pQuerySegmentIn->AgpApertureBase;
        pHwDeviceExtension->agpApertureSize = pQuerySegmentIn->AgpApertureSize;

        if (pHwDeviceExtension->bDXVASegment)
        {
            pQuerySegmentOut->NbSegment = 2;
        }
        else
        {
            pQuerySegmentOut->NbSegment = 1;
        }
        if ((pHwDeviceExtension->ulMultiCrtcFlags & HW_MCRTC_PRIMARY) &&
            (0 != pQuerySegmentIn->AgpApertureSize.QuadPart))
        {
            pQuerySegmentOut->NbSegment++;
        }

        // 
        // Convert IDs to 0-based subscripts, then validate them for OACR.
        //
        ulDXVASegSub = pHwDeviceExtension->ulDXVASegID - 1;
        ulDXVASegSub = (ulDXVASegSub < pHwDeviceExtension->ulDXVASegID ? ulDXVASegSub : 0);

        ulFBSegSub = pHwDeviceExtension->ulFBSegID - 1;
        ulFBSegSub = (ulFBSegSub < pHwDeviceExtension->ulFBSegID ? ulFBSegSub : 0);

        ulAGPSegSub = pHwDeviceExtension->ulAGPSegID - 1;
        ulAGPSegSub = (ulAGPSegSub < pHwDeviceExtension->ulAGPSegID ? ulAGPSegSub : 0);

        if (NULL != pQuerySegmentOut->pSegmentDescriptor)
        {
            DWORD   dwCMMPoolSize;

            pMHPPool = &pMHP->mhpIndividualPool[MHP_POOL_TYPE_FRAME_BUFFER];

            RtlZeroMemory(pQuerySegmentOut->pSegmentDescriptor,
                          pQuerySegmentOut->NbSegment*sizeof(DXGK_SEGMENTDESCRIPTOR));

            dwCMMPoolSize = pMHPPool->dwMHP_TotalBytes;

            pQuerySegmentOut->pSegmentDescriptor[ulFBSegSub].BaseAddress.QuadPart = dwCMMPoolSize;
            pQuerySegmentOut->pSegmentDescriptor[ulFBSegSub].CpuTranslatedAddress.QuadPart = pMHPPool->dwMHP_ASIC_BaseAddr +
                                                                                    dwCMMPoolSize;

            if (pHwDeviceExtension->bDXVASegment)
            {

                pQuerySegmentOut->pSegmentDescriptor[ulFBSegSub].Size = PoolSize - (32 * 1024 * 1024);
            }
            else
            {
                pQuerySegmentOut->pSegmentDescriptor[ulFBSegSub].Size = PoolSize;
            }

            pQuerySegmentOut->pSegmentDescriptor[ulFBSegSub].Size &= (~(PAGE_SIZE - 1));
            pQuerySegmentOut->pSegmentDescriptor[ulFBSegSub].Flags.CpuVisible = TRUE;



            if (pHwDeviceExtension->bDXVASegment)
            {
                pQuerySegmentOut->pSegmentDescriptor[ulDXVASegSub].BaseAddress.QuadPart =
                    dwCMMPoolSize + pQuerySegmentOut->pSegmentDescriptor[ulFBSegSub].Size;
                pQuerySegmentOut->pSegmentDescriptor[ulDXVASegSub].CpuTranslatedAddress.QuadPart =
                    pMHPPool->dwMHP_ASIC_BaseAddr +
                    dwCMMPoolSize +
                    pQuerySegmentOut->pSegmentDescriptor[ulFBSegSub].Size;

                pQuerySegmentOut->pSegmentDescriptor[ulDXVASegSub].Size  = PoolSize - pQuerySegmentOut->pSegmentDescriptor[ulFBSegSub].Size;
                pQuerySegmentOut->pSegmentDescriptor[ulDXVASegSub].Size &= (~(PAGE_SIZE - 1));
                pQuerySegmentOut->pSegmentDescriptor[ulDXVASegSub].Flags.CpuVisible = TRUE;

                pHwDeviceExtension->lDXVASegmentAddress.QuadPart =
                    pHwDeviceExtension->lfbPhysicalAddress.QuadPart +
                    (LONGLONG) dwCMMPoolSize +
                    (LONGLONG) pQuerySegmentOut->pSegmentDescriptor[ulFBSegSub].Size;
            }
            else
            {
                pHwDeviceExtension->lDXVASegmentAddress.QuadPart =
                    pHwDeviceExtension->lfbPhysicalAddress.QuadPart +
                    (LONGLONG)dwCMMPoolSize;
            }

            //
            // Agp segment.
            //
            if ((pHwDeviceExtension->ulMultiCrtcFlags & HW_MCRTC_PRIMARY) &&
                (0 != pQuerySegmentIn->AgpApertureSize.QuadPart))
            {
                pQuerySegmentOut->pSegmentDescriptor[ulAGPSegSub].Flags.Agp = TRUE;

                //
                // These values are ignored by the OS, they are used internally in ReservePrivateBuffers
                //
                pQuerySegmentOut->pSegmentDescriptor[ulAGPSegSub].BaseAddress.QuadPart = 0;
                pQuerySegmentOut->pSegmentDescriptor[ulAGPSegSub].CpuTranslatedAddress = pMHP->mhpIndividualPool[MHP_POOL_TYPE_AGP].physMHP_HostBaseAddr;
                pQuerySegmentOut->pSegmentDescriptor[ulAGPSegSub].Size                 = pMHP->mhpIndividualPool[MHP_POOL_TYPE_AGP].dwMHP_TotalBytes;

            }

            //
            // This hw initial should not be done here, ideally the segments would have been decided at
            // StartDevice time and here we would just report them back to the OS
            //

            //
            // Reserve graphics memory resources for internal use before
            // returning the rest to the OS for management.
            //
            {
                VOID *ppBaseVirtualAddress[32];

                // Fill in virtual base addresses for all the segments
                //
                UINT i;
                memset(ppBaseVirtualAddress, 0, sizeof(ppBaseVirtualAddress));
                for (i = 0; i < pQuerySegmentOut->NbSegment; i++)
                {
                    if (pQuerySegmentOut->pSegmentDescriptor[i].Flags.Agp)
                    {
                        ppBaseVirtualAddress[i] = pMHP->mhpIndividualPool[MHP_POOL_TYPE_AGP].pvMHP_CPU_BaseAddr;
                    }
                    else
                    {
                        // Assume local memory...
                        ppBaseVirtualAddress[i] = pHwDeviceExtension->pvLfbBaseAddress;
                    }
                }

                pHwDeviceExtension->pPrivateBuffers = ReservePrivateBuffers(pHwDeviceExtension->DeviceHandle,
                                                                            pHwDeviceExtension->pDmaAdapterGUI,
                                                                            pQuerySegmentOut->NbSegment,
                                                                            pQuerySegmentOut->pSegmentDescriptor,
                                                                            ppBaseVirtualAddress);
                if (pHwDeviceExtension->pPrivateBuffers == NULL)
                {
                    return STATUS_UNSUCCESSFUL;
                }

                Ret=InitRingBuffer(pHwDeviceExtension);
                if (Ret != STATUS_SUCCESS)
                {
                    return Ret;
                }
            }
        }

        //
        // Setup the Paging buffer information.
        //
        if ((pHwDeviceExtension->ulMultiCrtcFlags & HW_MCRTC_PRIMARY) &&
            (0 != pQuerySegmentIn->AgpApertureSize.QuadPart))
        {
            pQuerySegmentOut->PagingBufferSegmentId = pHwDeviceExtension->ulAGPSegID;
        }
        else
        {
            //
            // Use paging buffer in contiguous physical memory.
            //
            pQuerySegmentOut->PagingBufferSegmentId = 0;
        }


        pQuerySegmentOut->PagingBufferSize = 64*1024;
        pQuerySegmentOut->PagingBufferPrivateDataSize = 0;

        break;
    }

    return (STATUS_SUCCESS);
}


NTSTATUS
D3DDDIResetFromTimeout(
    HANDLE  hAdapter)
{

    HW_DEVICE_EXTENSION* pAdapter = ((PHW_DEVICE_EXTENSION*)hAdapter)[0];

    // disable vsync interrupt
    AtiVSyncInterrupt_disable(pAdapter);

    // Reset Asic
    bAsicResetGui(pAdapter);
    qs_ResetAndInitializeGUIAndAssertPM4(pAdapter->pQs, RESETGUI_RESET_AND_INIT | RESETGUI_ASSERTPM4_OFF);

    // Setup asic again
    vAsicRegisterSGTlocation(pAdapter);
    QS_RegisterBuffers(pAdapter->pQs);
    qs_ResetAndInitializeGUIAndAssertPM4(pAdapter->pQs, RESETGUI_RESET_AND_INIT | RESETGUI_ASSERTPM4_ON);
    AtiDMAInterrupt_enable(pAdapter, pAdapter->dwIRQSource);
    LDDReserveQSMem(pAdapter);
    QsInsertDummyRingBufCmd(pAdapter->pQs);     //This will ensure the flush packets it done now and not in D3DDDISubmitCommand
    RestoreLastFenceToHwRegister(pAdapter);


    return STATUS_SUCCESS;
}

NTSTATUS
D3DDDIRestartFromTimeout(
    HANDLE  hAdapter)
{

    HW_DEVICE_EXTENSION* pAdapter = ((PHW_DEVICE_EXTENSION*)hAdapter)[0];

    //
    // Enable vsync interrupt.
    //
    AtiVSyncInterrupt_enable(pAdapter);

    return STATUS_SUCCESS;
}


#ifdef ENABLE_COMCONTROL

NTSTATUS GetID(__in HW_DEVICE_EXTENSION *pHwDeviceExtension, __inout PR200_GetIDData pGetIDData )
{
    NTSTATUS ntStatus = STATUS_SUCCESS;
    ULONG ulCount;
    ULONG * pulID = NULL;

    PAGED_CODE();

    __try
    {
        if(pGetIDData->pulID != NULL)
        {
            ULONG ulAlloc = 0;
            //Get the source/target id's
            ProbeForRead(pGetIDData->pulCount, sizeof(ULONG), sizeof(ULONG));
            RtlCopyMemory(&ulCount, pGetIDData->pulCount, sizeof(ULONG));
            ulAlloc = ulCount * sizeof(ULONG);
            if (ulAlloc < ulCount)
            {
                return STATUS_INVALID_PARAMETER;
            }
            else
            {
                pulID = (ULONG *)ExAllocatePoolWithTag(	NonPagedPool,ulAlloc,ATI_TAG);
                if(NULL == pulID)
                {
                    return STATUS_NO_MEMORY;
                }
            }
        }
    }
    __except(EXCEPTION_EXECUTE_HANDLER)
    {
        return STATUS_INVALID_PARAMETER;
    }

        ntStatus = R200GetChildData(pHwDeviceExtension, &ulCount, pGetIDData->ulFlags, pulID);

    if (NT_SUCCESS(ntStatus))
    {
        __try
        {
            if(pulID != NULL)
            {
                ProbeForWrite(pGetIDData->pulID, ulCount*sizeof(ULONG), sizeof(ULONG));    
                RtlCopyMemory(pGetIDData->pulID, pulID,ulCount*sizeof(ULONG));
            }else
            {
                //if pulId is null return the source/target count
                ProbeForWrite(pGetIDData->pulCount, sizeof(ULONG), sizeof(ULONG));
                   RtlCopyMemory(pGetIDData->pulCount, &ulCount, sizeof(ULONG));
            }

        }__except(EXCEPTION_EXECUTE_HANDLER)
        {
            ntStatus = STATUS_INVALID_PARAMETER;
        }
    }
    
    //delete memory
    if(NULL != pulID)
    {
        ExFreePoolWithTag(pulID, ATI_TAG);
    }

    return ntStatus;
}

NTSTATUS GetActiveTopology(__in PHW_DEVICE_EXTENSION PrimaryHwDeviceExtension, __inout PR200_TopologyData pTopologyData)
{
    NTSTATUS ntStatus = STATUS_SUCCESS;
    ULONG ulDisplayMask = 0;
    ULONG ulActiveTargetCount = 0;
    ULONG ulIdx = 0;
    ULONG ulCurrentDisplay =0;
    PHW_DEVICE_EXTENSION HwDeviceExtension = NULL;
    PHW_DEVICE_EXTENSION SecondaryDeviceExtension = NULL;
    ULONG ulCount;
    ULONG * pulTargetID = NULL;

    
    PAGED_CODE();

    if(PrimaryHwDeviceExtension == NULL)
    {
        return STATUS_INVALID_PARAMETER;
    }

    SecondaryDeviceExtension = (PHW_DEVICE_EXTENSION)PrimaryHwDeviceExtension->pvHwOtherDevExt;

    if(pTopologyData->ulSourceID == 0)
    {
        HwDeviceExtension = PrimaryHwDeviceExtension;
    }else
    {
        HwDeviceExtension = SecondaryDeviceExtension;
    }
    __try
    {
        if(pTopologyData->pulTargetID != NULL)
        {
            //Get the active target id's
            ProbeForRead(pTopologyData->pulCount, sizeof(ULONG), sizeof(ULONG));
            RtlCopyMemory(&ulCount, pTopologyData->pulCount, sizeof(ULONG));

            pulTargetID = (ULONG *)ExAllocatePoolWithTag(NonPagedPool,
                                                                                    ulCount*sizeof(ULONG),
                                                                                    ATI_TAG);
            if(NULL == pulTargetID)
            {
                return STATUS_NO_MEMORY;
            }
        }
        }__except(EXCEPTION_EXECUTE_HANDLER)
      {
          return STATUS_INVALID_PARAMETER;
      }

    if(pTopologyData->pulTargetID == NULL)
    {
        //Get the number of active targets associated with this source
            
        for (ulDisplayMask = 0; ulDisplayMask < HwDeviceExtension->ulNumberDisplays; ulDisplayMask++)
        {
            ulCurrentDisplay = (1 << ulDisplayMask);

            if (HwDeviceExtension->ulConnectedDisplays & ulCurrentDisplay)
            {
                //
                // This monitor is connected... see if it's active.
                //

                if ( HwDeviceExtension->ulActiveDisplays & ulCurrentDisplay )
                {
                //
                // The monitor is active. By default leave it active in the desired configuration.
                //
                ulActiveTargetCount++;
                }
            }
        }
        ulCount = ulActiveTargetCount;       
        __try
        {
            ProbeForWrite(pTopologyData->pulCount, sizeof(ULONG), sizeof(ULONG));   
           RtlCopyMemory(pTopologyData->pulCount, &ulCount, sizeof(ULONG));
        
        }__except(EXCEPTION_EXECUTE_HANDLER)
       {
           ntStatus= STATUS_INVALID_PARAMETER;
       }
    }else
    {
        //Get the target ID's associated with this source
           for( ulIdx=0; ulIdx<HwDeviceExtension->ulNumberDisplays;ulIdx++)
        {
            ulCurrentDisplay = (1 << ulIdx);

            //
            // If this is an ACPI adapter then fill in the IDs with the ACPI IDs.
            // Otherwise, use the standard IDs.
            //

            if (HwDeviceExtension->ulConnectedDisplays & ulCurrentDisplay)
            {
            //
            // This monitor is connected... see if it's active
            //                  
                if ( HwDeviceExtension->ulActiveDisplays & ulCurrentDisplay )
                {
            

                if (HwDeviceExtension->AcpiChildren != NULL)
                {
                    if (ulCurrentDisplay & HwDeviceExtension->ulaDisplayTypeVector[DISPLAY_MONITOR])
                    {
                    pulTargetID[ulActiveTargetCount] = HW_ID_ACPI_MONITOR | HW_ID_DISPLAY_CHILD;
                    }
                    else if (ulCurrentDisplay & HwDeviceExtension->ulaDisplayTypeVector[DISPLAY_TELEVISION])
                    {
                    pulTargetID[ulActiveTargetCount]  = HW_ID_ACPI_TV | HW_ID_DISPLAY_CHILD;
                    }
                    else if (ulCurrentDisplay & HwDeviceExtension->ulaDisplayTypeVector[DISPLAY_LCDPANEL])
                    {
                    pulTargetID[ulActiveTargetCount]  = HW_ID_ACPI_FLAT_PANEL | HW_ID_DISPLAY_CHILD;
                    }
                    else if (ulCurrentDisplay & HwDeviceExtension->ulaDisplayTypeVector[DISPLAY_DIGITALFLATPANEL])
                    {
                    pulTargetID[ulActiveTargetCount]  = HW_ID_ACPI_DIGITAL_FLAT_PANEL | HW_ID_DISPLAY_CHILD;
                    }
                }else
                {
                    pulTargetID[ulActiveTargetCount]  = ulIdx| HW_ID_DISPLAY_CHILD;
                }
                ulActiveTargetCount++;
                }
            }
            }
           ASSERT(ulCount == ulActiveTargetCount);
        __try
        {
            ProbeForWrite(pTopologyData->pulTargetID, ulActiveTargetCount*sizeof(ULONG), sizeof(ULONG));        
            RtlCopyMemory(pTopologyData->pulTargetID, pulTargetID, ulActiveTargetCount*sizeof(ULONG));

        }__except(EXCEPTION_EXECUTE_HANDLER)
              {
                  ntStatus= STATUS_INVALID_PARAMETER;
              }

    }

    //delete memory
    if(NULL != pulTargetID)
    {
            ExFreePoolWithTag(pulTargetID, ATI_TAG);
    }

    return ntStatus;
}


NTSTATUS 
    R200GetChildData(
    __in  PHW_DEVICE_EXTENSION PrimaryHwDeviceExtension,
       __inout  ULONG *pulCount,
       __in ULONG ulFlag,
       __inout_ecount(*pulCount) ULONG* pulID
    )
{

    NTSTATUS Status = STATUS_SUCCESS;
    ULONG ulIdx =0;
    ULONG ulConnectedTargetCount=0;
    ULONG ulSourceID=0;
    PHW_DEVICE_EXTENSION HwDeviceExtension;
    PHW_DEVICE_EXTENSION SecondaryHwDeviceExtension;

    PAGED_CODE();

    if(PrimaryHwDeviceExtension == NULL)
    {
        return STATUS_INVALID_PARAMETER;
    }

    SecondaryHwDeviceExtension = (PHW_DEVICE_EXTENSION) PrimaryHwDeviceExtension->pvHwOtherDevExt;
    if (PrimaryHwDeviceExtension->ulConnectedDisplays > 0)
    {
            //
            // Primary is connected.
            //          
            HwDeviceExtension = PrimaryHwDeviceExtension;      
    }
    else
    {
            //
            // Secondary is connected, or if not, just default to primary.
            //
            if (SecondaryHwDeviceExtension->ulConnectedDisplays > 0)
            {
                HwDeviceExtension = SecondaryHwDeviceExtension;             
            }
            else
            {
                HwDeviceExtension = PrimaryHwDeviceExtension;               
            }
    }

    if(ulFlag == 1)
    {
        //Get the sources
        if(pulID == NULL)
        {
            //Get count
            *pulCount=2;          
        }else
        {
            //Get ID array
            for(ulIdx=0; ulIdx<*pulCount;ulIdx++)
            {
                pulID[ulIdx]=ulSourceID;    
                ulSourceID++;
            }
        }
        }else
        {
            //Get the targets
            if(pulID == NULL)
            {
                //Get target count
                *pulCount=GetConnectedTargetCount(HwDeviceExtension);
            }else
            {
                //Get target ID array
                ulIdx=GetConnectedTargetIDs(HwDeviceExtension, pulID,0,*pulCount);
                ulConnectedTargetCount = ulIdx;
                
                ASSERT(*pulCount == ulConnectedTargetCount);
            }  
        
        }
    
    return STATUS_SUCCESS;

}

ULONG GetConnectedTargetCount(
    __in PHW_DEVICE_EXTENSION HwDeviceExtension)
{
    ULONG ulConnectedTargets =0;
    ULONG ulIdx =0;
    ULONG ulCurrentDisplay =0;
    
    PAGED_CODE();

    for(ulIdx=0; ulIdx<HwDeviceExtension->ulNumberDisplays;ulIdx++)
    {
        ulCurrentDisplay = (1 << ulIdx);

        //
        // If this is an ACPI adapter then fill in the IDs with the ACPI IDs.
        // Otherwise, use the standard IDs.
        //

        if (HwDeviceExtension->ulConnectedDisplays & ulCurrentDisplay)
        {
        //
        // This monitor is connected... 
        //  
         ulConnectedTargets++;
        }
    }

    return ulConnectedTargets;
}

ULONG GetConnectedTargetIDs(
    __in PHW_DEVICE_EXTENSION HwDeviceExtension,
    __inout_ecount(ulCount) ULONG * pulID,
    __in ULONG ulIndex,
    __in ULONG ulCount)
{
    
    ULONG ulConnectedTargetCount =0;
    ULONG ulIdx =0;
    ULONG ulCurrentIndex =0;
    ULONG ulCurrentDisplay =0;

    PAGED_CODE();

    ulCurrentIndex= ulIndex;
    
    for(ulIdx=0; ulIdx<HwDeviceExtension->ulNumberDisplays;ulIdx++)
    {
        ulCurrentDisplay = (1 << ulIdx);

        //
        // If this is an ACPI adapter then fill in the IDs with the ACPI IDs.
        // Otherwise, use the standard IDs.
        //

        if (HwDeviceExtension->ulConnectedDisplays & ulCurrentDisplay)
        {
        //
        // This monitor is connected... 
        //  
          if(ulCurrentIndex < ulCount)
         {         
            if (HwDeviceExtension->AcpiChildren != NULL)
            {
                if (ulCurrentDisplay & HwDeviceExtension->ulaDisplayTypeVector[DISPLAY_MONITOR])
                {
                pulID[ulCurrentIndex] = HW_ID_ACPI_MONITOR | HW_ID_DISPLAY_CHILD;
                }
                else if (ulCurrentDisplay & HwDeviceExtension->ulaDisplayTypeVector[DISPLAY_TELEVISION])
                {
                pulID[ulCurrentIndex]  = HW_ID_ACPI_TV | HW_ID_DISPLAY_CHILD;
                }
                else if (ulCurrentDisplay & HwDeviceExtension->ulaDisplayTypeVector[DISPLAY_LCDPANEL])
                {
                pulID[ulCurrentIndex]  = HW_ID_ACPI_FLAT_PANEL | HW_ID_DISPLAY_CHILD;
                }
                else if (ulCurrentDisplay & HwDeviceExtension->ulaDisplayTypeVector[DISPLAY_DIGITALFLATPANEL])
                {
                pulID[ulCurrentIndex]  = HW_ID_ACPI_DIGITAL_FLAT_PANEL | HW_ID_DISPLAY_CHILD;
                }
            }else
            {
                pulID[ulCurrentIndex]  = ulIdx| HW_ID_DISPLAY_CHILD;
            }
            ulConnectedTargetCount++;
            ulCurrentIndex++;    
           }
        }
    }
    return ulConnectedTargetCount;

}
#endif



NTSTATUS
D3DDDIEscape(
    VOID                       *InterfaceContext,
    CONST DXGKARG_ESCAPE   *pDDIEscape)
{
    HW_DEVICE_EXTENSION        *pAdapter  = ((PHW_DEVICE_EXTENSION *)InterfaceContext)[0];
    R2D3DDevice                *pR2D3DDev = (R2D3DDevice *)pDDIEscape->hDevice;
    NTSTATUS    Status = STATUS_INVALID_PARAMETER;
    
#ifdef ENABLE_COMCONTROL     

    R200_EscData * pEscapeData;
    if(pDDIEscape->PrivateDriverDataSize >= sizeof(R200_ESCCODE))
    {

        pEscapeData = (R200_EscData*) pDDIEscape->pPrivateDriverData;
        
        switch(pEscapeData->dwEscapeCode)
        {
            case R200_GETID:
                if(pDDIEscape->PrivateDriverDataSize == sizeof(R200_EscData))
                {
                    Status =GetID(pAdapter, &(pEscapeData->sGetIDData));
              return Status;
                }
                break;
            case R200_GETTOPOLOGY:
                if(pDDIEscape->PrivateDriverDataSize == sizeof(R200_EscData))
                {
                    Status =GetActiveTopology(pAdapter, &(pEscapeData->sTopologyData));
              return Status;
                }
                break;
        }
    }
#endif



    return Status;
}



#define COLLECT_DBG_INFO_UNKNOWN_REASEON_SZ "************:Unknown reason..."

NTSTATUS
D3DDDICollectDbgInfo(
    HANDLE                            hAdapter,
    CONST DXGKARG_COLLECTDBGINFO *pDDICollectDbgInfo)
{
    NTSTATUS Status = STATUS_UNSUCCESSFUL;

    switch (pDDICollectDbgInfo->Reason)
    {
    default:
        if (pDDICollectDbgInfo->BufferSize >= sizeof(COLLECT_DBG_INFO_UNKNOWN_REASEON_SZ))
        {
            RtlCopyMemory(pDDICollectDbgInfo->pBuffer,
                          COLLECT_DBG_INFO_UNKNOWN_REASEON_SZ,
                          sizeof(COLLECT_DBG_INFO_UNKNOWN_REASEON_SZ));

            {
                DWORD* p_dwBuffer = (DWORD*)pDDICollectDbgInfo->pBuffer;
                p_dwBuffer[0] = DXGK_SECONDARY_BUCKETING_TAG;
                p_dwBuffer[1] = 0xBADF00D;
                p_dwBuffer[2] = pDDICollectDbgInfo->Reason;
            }

            Status = STATUS_SUCCESS;
        }
    }

    return Status;
}

UINT TestPrivateMode = 0;

NTSTATUS
D3DDDICreateAllocation(
    VOID                           *InterfaceContext,
    DXGKARG_CREATEALLOCATION   *pDDICAData)
{
    PHW_DEVICE_EXTENSION            pAdapter;
    NTSTATUS                        ntStatus;
    UINT                            i;
    DXGK_ALLOCATIONINFO        *pAllocInfo;
    PR2AllocationInfo               pDrvAllocInfo;      //Driver private surface struct that will be passed into future calls
    R2DDICreateAllocationData      *pR2AllocData;
    R2DDICreateAllocationData       r2ShadowAllocInfo;
    DWORD                           DXVASeg;
    DWORD                           AGPSeg;

    //
    // Get the adapter
    //
    pAdapter  = ((PHW_DEVICE_EXTENSION*)InterfaceContext)[0];

    ntStatus = STATUS_SUCCESS;
    AGPSeg   = pAdapter->ulAGPSegID;
    DXVASeg  = pAdapter->ulDXVASegID;

    DUMMY_TRACE(pAdapter);

    //
    // Map AGP segment to local video memory
    //
    if (! R200AGPEnabled(pAdapter))
    {
        AGPSeg = 1;
    }

    for (i = 0, pAllocInfo = pDDICAData->pAllocationInfo;
         i < pDDICAData->NumAllocations;
         i++, pAllocInfo++)
    {
#pragma prefast(disable: __WARNING_MEMORY_LEAK, "This memory will be freed by another function" )
        pDrvAllocInfo =
            (PR2AllocationInfo)ExAllocatePoolWithTag(PagedPool,
                                                     sizeof(R2AllocationInfo),
                                                     'R2SA');
#pragma prefast(enable: 14 )

        //
        // Return the allocation info pointer as handle
        //
        pAllocInfo->hAllocation = (HANDLE)pDrvAllocInfo;

        pAllocInfo->AllocationPriority = D3DDDI_ALLOCATIONPRIORITY_NORMAL;

        if (! pDrvAllocInfo)
        {
            ntStatus = STATUS_NO_MEMORY;
            break;
        }
        memset(pDrvAllocInfo, 0, sizeof(R2AllocationInfo));

        pR2AllocData =
            (R2DDICreateAllocationData *)pAllocInfo->pPrivateDriverData;

        if (! pR2AllocData)
        {
            ntStatus = STATUS_INVALID_PARAMETER;
            break;
        }

        //
        // Save the allocation info for later use
        //
        *pDrvAllocInfo = pR2AllocData->sAllocInfo;
        pDrvAllocInfo->hslSurfDesc.lpddPixelFormat = &pDrvAllocInfo->ddPixelFormat;

        pDrvAllocInfo->hslSurfDesc.hSurfInfoHandle    = NULL;
        pDrvAllocInfo->hslSurfDesc.hATISurfInfoHandle = NULL;

        //
        // Fill in information for the actual VIDMM allocation
        //
        pAllocInfo->Size = ByteAlign(pR2AllocData->sAllocInfo.dwPitch,
                                     pR2AllocData->sAllocInfo.dwPitchAlign)*
                           ByteAlign(pR2AllocData->sAllocInfo.dwHeight,
                                     pR2AllocData->sAllocInfo.dwHeightAlign);
        pAllocInfo->Alignment = pR2AllocData->sAllocInfo.dwOffsetAlign;

        // Store alloc size, used when creating tiled surface aperture
        pDrvAllocInfo->dwAllocSize = (DWORD)pAllocInfo->Size;


        //
        // Validate the size and alignment
        //
        if ((! pAllocInfo->Size) || (! pAllocInfo->Alignment))
        {
            ntStatus = STATUS_INVALID_PARAMETER;
            break;
        }

        if ((pR2AllocData != NULL) && (pR2AllocData->sAllocInfo.bShared))
        {
            if (!pDrvAllocInfo->bDXVARenderTarget)
            {
                pAllocInfo->Flags.CpuVisible = TRUE;
            }
        }
        else
        {
            pAllocInfo->Flags.CpuVisible = TRUE;

        }


        //
        // Is surface tiled
        //
        if ((pR2AllocData->sAllocInfo.dwFlags & (HSL_SURF_IS_TILED | HSL_SURF_IS_MICROTILED)) != 0)
        {
            pAllocInfo->Flags.Swizzled = TRUE;
        }

        // R200 does not support 24bpp, but for a while we DDraw would pass 24bpp surface creates to the driver
        ASSERT(pR2AllocData->sAllocInfo.hslSurfDesc.dwBPP != 24 || (pR2AllocData->sAllocInfo.ddPixelFormat.dwFlags & DDPF_RGB) == 0);

        if (((pR2AllocData != NULL) && (pR2AllocData->sAllocInfo.bShared)) &&
                ! (pDrvAllocInfo->bDXVARenderTarget))
        {
            // Shared surfaces can be lockable, but only if they are placed in aperture memory
            pAllocInfo->PreferredSegment.Value   = AGPSeg;  // AGP memory
            pAllocInfo->SupportedReadSegmentSet  = 1 << (AGPSeg - 1);
            pAllocInfo->SupportedWriteSegmentSet = 1 << (AGPSeg - 1);
        }
        else if (pR2AllocData->sAllocInfo.dwHeap)
        {
            pAllocInfo->PreferredSegment.Value   = AGPSeg;  // AGP memory
            pAllocInfo->SupportedReadSegmentSet  = 1 << (AGPSeg - 1);
            pAllocInfo->SupportedWriteSegmentSet = 1 << (AGPSeg - 1);
        }
        else if (pR2AllocData->sAllocInfo.bCPUOptimized)
        {
            pAllocInfo->PreferredSegment.Value   = AGPSeg;  // AGP memory
            pAllocInfo->SupportedReadSegmentSet  = 1 << (AGPSeg - 1);
            pAllocInfo->SupportedWriteSegmentSet = 1 << (AGPSeg - 1);

            pAllocInfo->Flags.CpuVisible = TRUE;
            pAllocInfo->Flags.Cached = TRUE;

            ASSERT((pR2AllocData->sAllocInfo.dwFlags & (HSL_SURF_IS_TILED | HSL_SURF_IS_MICROTILED)) == 0);
        }
        else
        {
            if (pDrvAllocInfo->bDXVARenderTarget)
            {

                pAllocInfo->PreferredSegment.Value   = DXVASeg;  // DXVA segment
                pAllocInfo->SupportedReadSegmentSet  = 1 << (DXVASeg - 1);
                pAllocInfo->SupportedWriteSegmentSet = 1 << (DXVASeg - 1);
                if (R200AGPEnabled(pAdapter))
                {
                    pAllocInfo->EvictionSegmentSet = 1 << (AGPSeg - 1);
                }
            }
            else
            {
                pAllocInfo->PreferredSegment.Value = 1;  // Local video memory

                //
                // Allow video memory texture to be put into AGP
                //
                if (pR2AllocData->sAllocInfo.dwCaps & DDSCAPS_TEXTURE)
                {
                    pAllocInfo->SupportedReadSegmentSet  = 1 |
                                                           (1 << (DXVASeg - 1)) |
                                                           (1 << (AGPSeg - 1));
                    pAllocInfo->SupportedWriteSegmentSet = 1 |
                                                           (1 << (DXVASeg - 1)) |
                                                           (1 << (AGPSeg - 1));

                    if (R200AGPEnabled(pAdapter))
                    {
                        pAllocInfo->EvictionSegmentSet   = 1 << (AGPSeg - 1);
                    }
                }
                else
                {
                    pAllocInfo->SupportedReadSegmentSet  = 1 | (1 << (DXVASeg - 1));
                    pAllocInfo->SupportedWriteSegmentSet = 1 | (1 << (DXVASeg - 1));
                    if (R200AGPEnabled(pAdapter))
                    {
                        pAllocInfo->EvictionSegmentSet       = 1 << (AGPSeg - 1);
                    }
                }
            }
        }


        //
        // Make sure that dwMCOffset is set to 0
        //
        pDrvAllocInfo->vidMemData.dwMCOffset = 0;

        //
        // Ensure alloc segments requests are supported by device
        //
        EnforceHwSegRestrictions(pAdapter, pAllocInfo);


    }

    if (! (NT_SUCCESS(ntStatus)))
    {
        for (i = 0, pAllocInfo = pDDICAData->pAllocationInfo;
             i < pDDICAData->NumAllocations;
             i++, pAllocInfo++)
        {
            if (pAllocInfo->hAllocation)
            {
                ExFreePool(pAllocInfo->hAllocation);
                pAllocInfo->hAllocation = NULL;
            }
        }
    }

    return (ntStatus);
}

NTSTATUS
D3DDDIDestroyAllocation(
    VOID                                   *InterfaceContext,
    CONST DXGKARG_DESTROYALLOCATION    *pDDIDAData)
{
    UINT    i;

    for (i = 0; i < pDDIDAData->NumAllocations; i++)
    {
        ExFreePool(pDDIDAData->pAllocationList[i]);
    }

    //
    // Current R200 driver doesn't create resource structure
    //
    if (pDDIDAData->Flags.DestroyResource &&
        pDDIDAData->hResource)
    {
        ExFreePool(pDDIDAData->hResource);
    }

    return (STATUS_SUCCESS);
}


//
// Helper function to build DST_PITCH_OFFSET
//
_inline DWORD
MakeSurfTilePitchOffset(
    DWORD   dwMCOffset,
    DWORD   dwAlignedPitch,
    DWORD   dwSurfFlags)
{
    DWORD   dwTilePitchOffset;

    dwTilePitchOffset =
        ((dwMCOffset >> 10) & DST_PITCH_OFFSET__DST_OFFSET_MASK) |
        (((dwAlignedPitch >> 6) <<
          DST_PITCH_OFFSET__DST_PITCH__SHIFT) &
         DST_PITCH_OFFSET__DST_PITCH_MASK)                       |
        ((dwSurfFlags & HSL_SURF_IS_TILED) ?
         (1 << DST_PITCH_OFFSET__DST_TILE__SHIFT) : 0)           |
        ((dwSurfFlags & HSL_SURF_IS_MICROTILED) ?
         (1 << (DST_PITCH_OFFSET__DST_TILE__SHIFT + 1)) : 0);

    return (dwTilePitchOffset);
}

__inline DWORD GetPhyAddrFromSurfTilePitchOffset(DWORD dwSurfTilePitchOffsetVal)
{
    return (dwSurfTilePitchOffsetVal & DST_PITCH_OFFSET__DST_OFFSET_MASK) << 10;
}

__inline DWORD GetPitchFromSurfTilePitchOffset(DWORD dwTilePitchOffset)
{
    return (((dwTilePitchOffset) & DST_PITCH_OFFSET__DST_PITCH_MASK) >> DST_PITCH_OFFSET__DST_PITCH__SHIFT) << 6;
}

VOID GetPixelFormatAndPVAM
(
   CONST ULONG                             i_ulNumRedBits,
   CONST ULONG                             i_ulNumGreenBits,
   CONST ULONG                             i_ulNumBlueBits,
   CONST ULONG                             i_ulRedMask,
   CONST ULONG                             i_ulGreenMask,
   CONST ULONG                             i_ulBlueMask,
   __out D3DDDIFORMAT*                     o_pPixelFormat,
   __out D3DKMDT_PIXEL_VALUE_ACCESS_MODE*  o_pPixelValueAccessMode
);

NTSTATUS
GetVideoModeInfo
(
  IN    HW_DEVICE_EXTENSION*                i_pHwDeviceExtension,
  CONST D3DKMDT_SHAREDPRIMARYSURFACEDATA*   i_pSharedPrimarySurfaceData,
  OUT   VIDEO_MODE_INFORMATION*             o_pVidModeInfo
)
{
    // Find the matching display mode.
    VIDEO_MODE_INFORMATION*  pXddmDisplayModeSet            = NULL;
    SIZE_T                   sztNumXddmDisplayModesAcquired = 0;
    DWORD                    dwCurrentModeIndex             = 0;

    // Acquire the XDDM display mode set for this present path.
    NTSTATUS ntStatus = AcquireAvailableXddmDisplayModeSet(i_pHwDeviceExtension,
                                                           &pXddmDisplayModeSet,
                                                           &sztNumXddmDisplayModesAcquired);

    if ( !NT_SUCCESS(ntStatus) )
    {
        return ntStatus;
    }

    // Search through the available XDDM display modes until we find a mode that matches
    // the determined pinned source and target modes.
    for ( dwCurrentModeIndex = 0;
          dwCurrentModeIndex < sztNumXddmDisplayModesAcquired;
          ++dwCurrentModeIndex )
    {
        D3DDDIFORMAT                     PixelFormat          = D3DDDIFMT_UNKNOWN;
        D3DKMDT_PIXEL_VALUE_ACCESS_MODE  PixelValueAccessMode = D3DKMDT_PVAM_UNINITIALIZED;

        // Alias current XDDM display mode for easier access.
        CONST VIDEO_MODE_INFORMATION*  pCurrentXddmDisplayMode = &pXddmDisplayModeSet[dwCurrentModeIndex];

        // Obtain pixel format and value access mode for the current XDDM display mode.
        GetPixelFormatAndPVAM(pCurrentXddmDisplayMode->NumberRedBits,
                              pCurrentXddmDisplayMode->NumberGreenBits,
                              pCurrentXddmDisplayMode->NumberBlueBits,
                              pCurrentXddmDisplayMode->RedMask,
                              pCurrentXddmDisplayMode->GreenMask,
                              pCurrentXddmDisplayMode->BlueMask,
                              &PixelFormat,
                              &PixelValueAccessMode);

        // ASSUMPTION: We don't need pixel value access mode since whether it's direct or palette based mode
        //             is implied from the pixel format and we don't care if the palette is preset or settable
        //             for finding a matching display mode.
        UNREFERENCED_PARAMETER(PixelValueAccessMode);

        // If the current XDDM display mode matches the source/target mode parameters, stop the search.
        if ( (i_pSharedPrimarySurfaceData->Format == PixelFormat)
             &&
             (i_pSharedPrimarySurfaceData->Width == pCurrentXddmDisplayMode->VisScreenWidth)
             &&
             (i_pSharedPrimarySurfaceData->Height == pCurrentXddmDisplayMode->VisScreenHeight)
             &&
             (i_pSharedPrimarySurfaceData->RefreshRate.Numerator / i_pSharedPrimarySurfaceData->RefreshRate.Denominator == pCurrentXddmDisplayMode->Frequency) )
        {
            // INVARIANT: Current mode matches the modality of the specified VidPN present path.

            // NOTE: We know that denominator will be 1 here because all XDDM display mode VSync frequencies are integer,
            //       (see PopulateTargetModeSet_XddmParity code for details).
            ASSERT( i_pSharedPrimarySurfaceData->RefreshRate.Denominator == 1 );

            // Report current mode's parameters to the caller.
            *o_pVidModeInfo = *pCurrentXddmDisplayMode;

            break;
        }
    }

    // Dispose of the temporary XDDM mode set used to produce the respective LDDM source/target mode sets.
    ExFreePool(pXddmDisplayModeSet);

    if ( dwCurrentModeIndex == sztNumXddmDisplayModesAcquired )
    {
        // INVARIANT: We couldn't find a matching XDM display mode for the specified pinned source/target modes.
        return STATUS_INVALID_PARAMETER;
    }

    return STATUS_SUCCESS;
}


VOID
SetupPrimarySurfaceAllocationInfo(
    D3DDDIFORMAT            Format,
    VIDEO_MODE_INFORMATION *pModeInfo,
    DWORD                   dwPSMCAddress,
    DWORD                   dwCaps,
    R2AllocationInfo       *pPSAllocInfo)
{
    DDPIXELFORMAT          *pPixFmt;
    DDHSLSURFACEDESC       *pHSLSurfDesc;

    memset(pPSAllocInfo, 0, sizeof(R2AllocationInfo));

    pHSLSurfDesc = &pPSAllocInfo->hslSurfDesc;

    pPSAllocInfo->dwBytesPerPixel = pModeInfo->BitsPerPlane/8;
    pPSAllocInfo->dwPitch         = pModeInfo->ScreenStride;
    pPSAllocInfo->dwPitchAlign    = 1;
    pPSAllocInfo->dwHeight        = pModeInfo->VisScreenHeight;
    pPSAllocInfo->dwHeightAlign   = 1;
    pPSAllocInfo->dwOffsetAlign   = PAGE_SIZE;
    pPSAllocInfo->dwCaps          = dwCaps;

    pHSLSurfDesc->dwBPP    = pModeInfo->BitsPerPlane;
    pHSLSurfDesc->dwWidth  = pModeInfo->VisScreenWidth;
    pHSLSurfDesc->dwHeight = pModeInfo->VisScreenHeight;
    pHSLSurfDesc->lPitch   = pPSAllocInfo->dwPitch;
    pHSLSurfDesc->dwCaps   = dwCaps;

    //
    // NOTE: Only 32/16/8 BPP formats are supported
    //
    pPixFmt = &pPSAllocInfo->ddPixelFormat;
    pPixFmt->dwSize        = sizeof(DDPIXELFORMAT);
    pPixFmt->dwRBitMask    = pModeInfo->RedMask;
    pPixFmt->dwGBitMask    = pModeInfo->GreenMask;
    pPixFmt->dwBBitMask    = pModeInfo->BlueMask;

    switch (Format)
    {
        case D3DDDIFMT_A8R8G8B8 :
            pPixFmt->dwFlags            = DDPF_RGB | DDPF_ALPHAPIXELS;
            pPixFmt->dwRGBBitCount      = 32;
            pPixFmt->dwRGBAlphaBitMask  = 0xff000000;
            break;

        case D3DDDIFMT_X8R8G8B8 :
            pPixFmt->dwFlags       = DDPF_RGB;
            pPixFmt->dwRGBBitCount = 32;
            break;

        case D3DDDIFMT_R5G6B5 :
            pPixFmt->dwFlags       = DDPF_RGB;
            pPixFmt->dwRGBBitCount = 16;
            break;

        case D3DDDIFMT_P8 :
            pPixFmt->dwFlags       = DDPF_PALETTEINDEXED8 | DDPF_RGB;
            pPixFmt->dwRGBBitCount = 8;
            break;

        default :
            DPF(DBG_ERROR, "SetupPrimarySurfaceAllocationInfo : Unsupported primary surface format 0x%lx\n", Format);
            DBG_BREAK;
            break;
    }

    pHSLSurfDesc->lpddPixelFormat = &pPSAllocInfo->ddPixelFormat;

    //
    // Set up handle and physical address
    //
    if (dwCaps & DDSCAPS_PRIMARYSURFACE)
    {
        //
        // Prepare the MC address so that patching works for D3DDDIPresent
        //
        pHSLSurfDesc->hAllocation           = PRIMARY_SURFACE_ALLOCATION_HANDLE;
        pHSLSurfDesc->dwMCOffset            = dwPSMCAddress;
        pPSAllocInfo->vidMemData.dwMCOffset = dwPSMCAddress;
    }
}

//
// NOTE: 1. Eventually there will be a routine for flipping in FS
//       2. D3DDDIRender has special primary surface workaround that breaks
//          BLT in fullscreen mode.
//
NTSTATUS
R200Flip(
    R2D3DDevice            *pR2D3DDev,
    DXGKARG_PRESENT    *pDDIPresentData,
    UINT                    nOutput);

NTSTATUS
R200SetMode(
    HW_DEVICE_EXTENSION*            pAdapter,
    DWORD                           dwModeIndex,
    D3DDDI_VIDEO_PRESENT_SOURCE_ID  VidPnSourceId,
    DWORD                           dwMCAddressPS);

NTSTATUS
D3DDDIPresent(
    HANDLE                          hContext,
    DXGKARG_PRESENT            *pDDIPresentData)
{
    NTSTATUS                        status;
    R2D3DDevice                    *pR2D3DDev;
    PR2D3DContext                   pR2D3DConext;
    HW_DEVICE_EXTENSION            *pAdapter;
    UINT                            i;
    UINT                           *pDMABuf;
    CONST RECT*                     pRect;
    RECT                            ScreenRect;
    UINT                            SubRectCnt;
    INT                             XOffset, YOffset;
    INT                             dwSrcWidth = 0, dwDstWidth, dwSrcHeight = 0, dwDstHeight;
    INT                             dwSrcLeft = 0, dwDstLeft = 0, dwSrcTop = 0, dwDstTop = 0;
    R2AllocationInfo                srcPrimarySurfAllocInfo, dstPrimarySurfAllocInfo;
    R2AllocationInfo               *pSrcAllocInfo, *pDstAllocInfo;
    UINT                            dwFormat;
    DXGKRNL_INTERFACE              *pCallback;
    CMDBUFF                         ddCmdBuf;
    DWORD                           dwMultiOffsetValue = 0;
    PR200_DMA_PRIVATEDATA           pDmaPrivateData;

    //
    // Get back the R200 device and adapter
    //
    pR2D3DConext = (PR2D3DContext)hContext;
    pR2D3DDev = pR2D3DConext->pDevice;
    pAdapter  = (HW_DEVICE_EXTENSION *)pR2D3DDev->pAdapter;
    pCallback = &(pAdapter->ddiCallback);

    //
    // Get the source and destionation allocation info
    //
    pSrcAllocInfo = (PR2AllocationInfo)pDDIPresentData->pAllocationList[DXGK_PRESENT_SOURCE_INDEX].hDeviceSpecificAllocation;
    if (pSrcAllocInfo)
    {
        //
        // Set up the allocation handle for BLT
        //
        pSrcAllocInfo->hslSurfDesc.hAllocation = pSrcAllocInfo->vidMemData.hAllocation;
    }
    else if (!pDDIPresentData->Flags.ColorFill)
    {
        return (STATUS_ILLEGAL_INSTRUCTION);
    }


    if (pDDIPresentData->pDmaBuffer == NULL)     //  a valid case
    {
        // For 1 type of present-flip (MMIO flips), the present DDI is called with a NULL DMA buffer, and NULL DMA buffer private data.
        return STATUS_SUCCESS;
    }
    else if (pDDIPresentData->pDmaBufferPrivateData == NULL)
    {
        ASSERT(FALSE);
        return (STATUS_ILLEGAL_INSTRUCTION);
    }

    //
    // Get DMA buffer private data
    //

    pDmaPrivateData = (PR200_DMA_PRIVATEDATA)pDDIPresentData->pDmaBufferPrivateData;
    if (pDDIPresentData->DmaBufferPrivateDataSize != sizeof(R200_DMA_PRIVATEDATA))
    {
        ASSERT(FALSE);
        return (STATUS_ILLEGAL_INSTRUCTION);
    }

    RtlZeroMemory(pDmaPrivateData, sizeof(R200_DMA_PRIVATEDATA));
    pDmaPrivateData->dwPacketId = InterlockedAnd(&gdwDMAPacketId, 1);

    pDstAllocInfo = (PR2AllocationInfo)pDDIPresentData->pAllocationList[DXGK_PRESENT_DESTINATION_INDEX].hDeviceSpecificAllocation;
    if (pDstAllocInfo)
    {
        //
        // Set up the dst allocation handle for BLT
        //
        pDstAllocInfo->hslSurfDesc.hAllocation = pDstAllocInfo->vidMemData.hAllocation;;
    }
    else if (!pDDIPresentData->Flags.Flip)
    {
        return (STATUS_ILLEGAL_INSTRUCTION);
    }

    //
    // Calculate the start of the DMA buffer and resource list
    //
    pDMABuf = pDDIPresentData->pDmaBuffer;

    //
    // NOTE : R200 requires that DMA buffer has to be QUADWORD aligned,
    //        so a NOP is added to each BLT. !! See Submit2dTransBlt
    //

    if (pDDIPresentData->Flags.Blt)
    {
        RECT   *pSrcRect = &pDDIPresentData->SrcRect;
        RECT   *pDstRect = &pDDIPresentData->DstRect;

        pDmaPrivateData->Type = DMA_PACKET_TYPE_PRESENT_BLT;

        pRect      = pDDIPresentData->pDstSubRects;
        SubRectCnt = pDDIPresentData->SubRectCnt;

#if  RECTCOUNTLIMIT
        //double check with ASSERTs
        ASSERT(pDDIPresentData->SubRectCnt > pDDIPresentData->MultipassOffset);

        pRect = pRect + pDDIPresentData->MultipassOffset;

        if (SubRectCnt - pDDIPresentData->MultipassOffset > RECTCOUNTLIMIT)
        {
            SubRectCnt = RECTCOUNTLIMIT;
            pDDIPresentData->MultipassOffset += RECTCOUNTLIMIT;
        }
        else
        {
            SubRectCnt = SubRectCnt - pDDIPresentData->MultipassOffset;
            pDDIPresentData->MultipassOffset = 0;
        }
#endif

        XOffset    = pSrcRect->left - pDstRect->left;
        YOffset    = pSrcRect->top  - pDstRect->top;

        dwSrcWidth  = pSrcRect->right  - pSrcRect->left;
        dwSrcHeight = pSrcRect->bottom - pSrcRect->top;
        dwDstWidth  = pDstRect->right  - pDstRect->left;
        dwDstHeight = pDstRect->bottom - pDstRect->top;

        dwSrcLeft = pSrcRect->left;
        dwSrcTop  = pSrcRect->top;
        dwDstLeft = pDstRect->left;
        dwDstTop  = pDstRect->top;
    }
    else if (pDDIPresentData->Flags.Flip)
    {
        ScreenRect.left   = ScreenRect.top = 0;
        ScreenRect.right  = pAdapter->curModeInfo[VIDPN_SOURCE1_ID].VisScreenWidth;
        ScreenRect.bottom = pAdapter->curModeInfo[VIDPN_SOURCE1_ID].VisScreenHeight;

        pDmaPrivateData->Type = DMA_PACKET_TYPE_PRESENT_FLIP;

        pRect      = &ScreenRect;
        SubRectCnt = 1;
        XOffset    = 0;
        YOffset    = 0;

        dwSrcWidth  = dwDstWidth  = ScreenRect.right;
        dwSrcHeight = dwDstHeight = ScreenRect.bottom;

        dwSrcLeft = dwDstLeft = dwDstLeft = dwDstTop = 0;

        return (R200Flip(pR2D3DDev,
                         pDDIPresentData,
                         pSrcAllocInfo->VidPnSourceId));
    }
    else if (pDDIPresentData->Flags.ColorFill)
    {
        ASSERT(pDDIPresentData->SubRectCnt >= pDDIPresentData->MultipassOffset);
        pRect      = pDDIPresentData->pDstSubRects + pDDIPresentData->MultipassOffset;
        SubRectCnt = pDDIPresentData->SubRectCnt - pDDIPresentData->MultipassOffset;
        dwDstWidth = dwDstHeight = 1;

        pDmaPrivateData->Type = DMA_PACKET_TYPE_PRESENT_COLORFILL;

        // Store Multi pass offset as we are going to zero it just in case we
        // get to finish all the rects this call
        dwMultiOffsetValue = pDDIPresentData->MultipassOffset;
        pDDIPresentData->MultipassOffset = 0;
    }
    else
    {
        return (STATUS_ILLEGAL_INSTRUCTION);
    }

    //
    // Make sure neither dstWidth nor dstHeight is 0
    //
    if ((! dwDstWidth) || (! dwDstHeight))
    {
        return (STATUS_ILLEGAL_INSTRUCTION);
    }

    //
    // Set up the command buffer
    //
    memset(&ddCmdBuf, 0, sizeof(ddCmdBuf));
    ddCmdBuf.pList      = pDDIPresentData->pDmaBuffer;
    ddCmdBuf.lpCBOffset = (DWORD_PTR)ddCmdBuf.pList;
    //
    // Command buffer size (64KB) is set in D3DDDICreateDevice;
    //
    ddCmdBuf.dwCBLeftDW = pDDIPresentData->DmaSize/4;

    if (pDstAllocInfo == NULL)
    {
        return (STATUS_ILLEGAL_INSTRUCTION);
    }

    for (i = 0; i < SubRectCnt; i++, pRect++)
    {
        DDHSLSURFACEDESC    surfDesc;
        DDHAL_BLTDATA       bltData;

        //
        // Set up BLT data
        //
        memset(&bltData, 0, sizeof(DDHAL_BLTDATA));
        memcpy(&bltData.rDest, pRect, sizeof(RECT));

        if (pDDIPresentData->Flags.ColorFill)
        {
            bltData.bltFX.dwFillColor = pDDIPresentData->Color;
            if (MPColorFill(&pDstAllocInfo->hslSurfDesc, pDstAllocInfo->vidMemData.hAllocation, &bltData, &ddCmdBuf) == FALSE)
            {
                // Failed because not enough space in command buffer, set multi split point
                pDDIPresentData->MultipassOffset = dwMultiOffsetValue + i;
                break;
            }
        }
        else
        {
            bltData.rSrc.left   = (pRect->left   - dwDstLeft)*dwSrcWidth/dwDstWidth  + dwSrcLeft;
            bltData.rSrc.right  = (pRect->right  - dwDstLeft)*dwSrcWidth/dwDstWidth  + dwSrcLeft;
            bltData.rSrc.top    = (pRect->top    - dwDstTop)*dwSrcHeight/dwDstHeight + dwSrcTop;
            bltData.rSrc.bottom = (pRect->bottom - dwDstTop)*dwSrcHeight/dwDstHeight + dwSrcTop;

            if (pDDIPresentData->Flags.SrcColorKey)
            {
                bltData.dwFlags |= DDBLT_KEYSRCOVERRIDE;
                bltData.bltFX.ddckSrcColorkey.dwColorSpaceLowValue = pDDIPresentData->Color;
            }
            else if (pDDIPresentData->Flags.DstColorKey)
            {
                bltData.dwFlags |= DDBLT_KEYDESTOVERRIDE;
                bltData.bltFX.ddckDestColorkey.dwColorSpaceLowValue = pDDIPresentData->Color;
            }

            status = MPSrcCopyBlt(&pSrcAllocInfo->hslSurfDesc,
                                  pSrcAllocInfo->vidMemData.hAllocation,
                                  &pDstAllocInfo->hslSurfDesc,
                                  pDstAllocInfo->vidMemData.hAllocation,
                                  &bltData,
                                  &ddCmdBuf);
            if (!NT_SUCCESS(status))
            {
        return STATUS_INSUFFICIENT_RESOURCES ;  
            }
        }
    }

    //
    // Command buffer is filled by BLT, run it through D3DDDIRender
    //
    if (ddCmdBuf.dwCBLeftDW < pDDIPresentData->DmaSize/4)
    {
        //
        // NOTE: DMA buffer is used as command buffer, it is not cacheable,
        //       investigate if read back from it is too slow
        //
        //
        DXGKARG_RENDER  ddiRender = {ddCmdBuf.pList,
                                         (DWORD)(((LPBYTE)ddCmdBuf.lpCBOffset) -
                                                 ((LPBYTE)ddCmdBuf.pList))};
        D3DKMT_HANDLE   hSrc;

        ddiRender.pDmaBuffer       = pDDIPresentData->pDmaBuffer;
        ddiRender.DmaSize          = pDDIPresentData->DmaSize;
        ddiRender.pAllocationList  = pDDIPresentData->pAllocationList;
        ddiRender.AllocationListSize = DXGK_PRESENT_MAX_INDEX+1;
        ddiRender.pDmaBufferPrivateData = pDDIPresentData->pDmaBufferPrivateData;
        ddiRender.DmaBufferPrivateDataSize = pDDIPresentData->DmaBufferPrivateDataSize;
        ddiRender.pPatchLocationListOut = pDDIPresentData->pPatchLocationListOut;
        ddiRender.PatchLocationListOutSize = pDDIPresentData->PatchLocationListOutSize;

        if (pSrcAllocInfo)
        {
            hSrc = pSrcAllocInfo->vidMemData.hAllocation;
        }
        else
        {
            hSrc = 0;
        }

        status = PresentPreRenderCmdBufProcessing(&ddiRender, hSrc, pDstAllocInfo->vidMemData.hAllocation);
        if (STATUS_SUCCESS != status)
        {
            return (status);
        }

        status = D3DDDIRenderInternal(hContext, &ddiRender, TRUE);
        if (STATUS_SUCCESS != status)
        {
            return (status);
        }

        //
        // Pass new Private data pointer back
        //
        pDDIPresentData->pDmaBufferPrivateData = ddiRender.pDmaBufferPrivateData;

        pDMABuf = ddiRender.pDmaBuffer;
        pDDIPresentData->pPatchLocationListOut  = ddiRender.pPatchLocationListOut;
        pDDIPresentData->PatchLocationListOutSize = ddiRender.PatchLocationListOutSize;
    }
    else
    {
        //
        // Something is wrong, the command buffer is empty
        //
        DPF(DBG_ERROR, "D3DDDIPresent : DMA buffer is empty, why? Normally this means the blit code has failed\n");
        DBG_BREAK;

        
        //
        // In the event of a unexpected error the driver should return STATUS_GRAPHICS_CANNOTCOLORCONVERT, if the driver
        // returns this the runtime will force the application to quit, so only return STATUS_GRAPHICS_CANNOTCOLORCONVERT
        // when the driver cannot perform the Present
        return STATUS_GRAPHICS_CANNOTCOLORCONVERT;
    }

    //
    // Return the DMA buffer and resource list pointer to the runtime
    //
    pDDIPresentData->pDmaBuffer    = pDMABuf;

#if  RECTCOUNTLIMIT
    if (0 != pDDIPresentData->MultipassOffset)
    {
        return STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER;
    }
#endif

    return (STATUS_SUCCESS);
}


//
// Helper function to build DST_PITCH_OFFSET
//

_inline DWORD
PatchSurfPitchOffsetTile(
    DWORD   dwMCOffset,
    DWORD   dwTilePitchOffset)
{
    DWORD   dwResOffset;

    //
    // Extract real offset into the allocation
    //
    dwResOffset = (dwTilePitchOffset &
                   DST_PITCH_OFFSET__DST_OFFSET_MASK) << 10;

    if (dwResOffset > (128 * 1024 * 1024))
    {
        EngDebugBreak();
     return -1;
    }

    //
    // Calculate the MC offset field for the DST_PITCH_OFFSET register
    //
    dwMCOffset = ((dwMCOffset + dwResOffset) >> 10) &
                 DST_PITCH_OFFSET__DST_OFFSET_MASK;

    //
    // Mask off the offset field from the input
    //
    dwTilePitchOffset = dwTilePitchOffset &
                        (~DST_PITCH_OFFSET__DST_OFFSET_MASK);

    //
    // Return the newly assembled DST_PITCH_OFFSET register
    //
    return (dwTilePitchOffset | dwMCOffset);
}

#define RESLIST_DEBUG_BREAK_ON_INVALID_HANDLE       0x00000001
#define RESLIST_DEBUG_BREAK_ON_NONZERO_RESOFFSET    0x00000002
#define RESLIST_DEBUG_FORCE_RENDER2PRIM             0x00000004

DWORD   dwRLDebug = 0;


NTSTATUS
R200PatchPhysicalAddress(
    HW_DEVICE_EXTENSION             *pHwDeviceExtension,
    VOID*                           pDmaAddr,
    CONST DXGK_ALLOCATIONLIST       *pAllocationListEntry,
    CONST D3DDDI_PATCHLOCATIONLIST  *pPatchEntry
    )
{
    DWORD                   dwResMCAddr;
    DWORD*                  pPhyAddr;

    pPhyAddr = (DWORD *)((BYTE*)pDmaAddr + pPatchEntry->PatchOffset);

    //
    // Calculate the R200 memory controller address
    //

    dwResMCAddr = pAllocationListEntry->PhysicalAddress.LowPart;

    if ((pHwDeviceExtension->ulFBSegID == pAllocationListEntry->SegmentId) ||
            (pHwDeviceExtension->ulDXVASegID == pAllocationListEntry->SegmentId))
    {
        ASSERT(dwResMCAddr >= pHwDeviceExtension->ulVRamSizeAvailable);
        ASSERT(dwResMCAddr < pHwDeviceExtension->ulVRamSizeInstalled);
        dwResMCAddr +=
            pHwDeviceExtension->lfbMemoryControllerAddress.LowPart;
    }
    else
    {
        ASSERT(pHwDeviceExtension->ulAGPSegID == pAllocationListEntry->SegmentId);
        ASSERT(dwResMCAddr >= pHwDeviceExtension->agpMemoryControllerAddress.LowPart);
    }


    //
    // Patching depends on the type of resource
    //
    switch (pPatchEntry->DriverId)
    {
    case mmRB3D_COLOROFFSET:

    case mmRB3D_DEPTHOFFSET:

    case mmPP_TXOFFSET_0:
    case mmPP_TXOFFSET_1:
    case mmPP_TXOFFSET_2:
    case mmPP_TXOFFSET_3:
    case mmPP_TXOFFSET_4:
    case mmPP_TXOFFSET_5:
        //
        // For textures, tiling flags are part of the offset.
        //

    case mmPP_CUBIC_OFFSET_F1_0:
    case mmPP_CUBIC_OFFSET_F2_0:
    case mmPP_CUBIC_OFFSET_F3_0:
    case mmPP_CUBIC_OFFSET_F4_0:
    case mmPP_CUBIC_OFFSET_F5_0:
    case mmPP_CUBIC_OFFSET_F1_1:
    case mmPP_CUBIC_OFFSET_F2_1:
    case mmPP_CUBIC_OFFSET_F3_1:
    case mmPP_CUBIC_OFFSET_F4_1:
    case mmPP_CUBIC_OFFSET_F5_1:
    case mmPP_CUBIC_OFFSET_F1_2:
    case mmPP_CUBIC_OFFSET_F2_2:
    case mmPP_CUBIC_OFFSET_F3_2:
    case mmPP_CUBIC_OFFSET_F4_2:
    case mmPP_CUBIC_OFFSET_F5_2:
    case mmPP_CUBIC_OFFSET_F1_3:
    case mmPP_CUBIC_OFFSET_F2_3:
    case mmPP_CUBIC_OFFSET_F3_3:
    case mmPP_CUBIC_OFFSET_F4_3:
    case mmPP_CUBIC_OFFSET_F5_3:
    case mmPP_CUBIC_OFFSET_F1_4:
    case mmPP_CUBIC_OFFSET_F2_4:
    case mmPP_CUBIC_OFFSET_F3_4:
    case mmPP_CUBIC_OFFSET_F4_4:
    case mmPP_CUBIC_OFFSET_F5_4:
    case mmPP_CUBIC_OFFSET_F1_5:
    case mmPP_CUBIC_OFFSET_F2_5:
    case mmPP_CUBIC_OFFSET_F3_5:
    case mmPP_CUBIC_OFFSET_F4_5:
    case mmPP_CUBIC_OFFSET_F5_5:

    case mmDST_OFFSET:
    case mmSRC_OFFSET:
    case mmCP_GUI_SRC_ADDR:
    case mmCP_GUI_DST_ADDR:
    case mmCRTC_OFFSET:

    //
    // Type3 PM4 packets that have to be patched
    //
    case PM4_PACKET3_INDX_BUFFER:
        *pPhyAddr = dwResMCAddr + pPatchEntry->AllocationOffset;
        break;

    case PM4_PACKET3_3D_LOAD_VBPNTR:
        // This command has been superceeded by VB_BASE and VB_OFFSET
        DBG_BREAK;
        *pPhyAddr = dwResMCAddr + pPatchEntry->AllocationOffset;
        break;

    case PM4_PACKET3_CNTL_TRANS_BITBLT:
    case PM4_PACKET3_CNTL_PAINT:
        //
        // NOTE : Offset alignment of the surface is implied,
        //        and *pPhyAddr contains offset, pitch and tile
        //

        *pPhyAddr = PatchSurfPitchOffsetTile(dwResMCAddr,
                                             pPatchEntry->AllocationOffset);
     if(*pPhyAddr == -1)
        return STATUS_UNSUCCESSFUL;
        break;

    case PM4_PACKET3_VB_BASE_ADDR :
        *pPhyAddr = dwResMCAddr + pPatchEntry->AllocationOffset;
        break;

    case mmPP_SRC_OFFSET_0:
    case mmPP_SRC_OFFSET_1:
    case mmPP_SRC_OFFSET_2:
    case mmPP_SRC_OFFSET_3:
    case mmPP_SRC_OFFSET_4:
    case mmPP_SRC_OFFSET_5:
    case mmPP_SRC_OFFSET_6:
    case mmPP_SRC_OFFSET_7:
    case mmPP_SRC_OFFSET_8:
    case mmPP_SRC_OFFSET_9:
    case mmPP_SRC_OFFSET_10:
    case mmPP_SRC_OFFSET_11:
    case mmPP_SRC_OFFSET_12:
    case mmPP_SRC_OFFSET_13:
    case mmPP_SRC_OFFSET_14:
    case mmPP_SRC_OFFSET_15:
    case mmPP_SRC_OFFSET_16:
    case mmPP_SRC_OFFSET_17:
        *pPhyAddr = dwResMCAddr + pPatchEntry->AllocationOffset - pHwDeviceExtension->lDXVASegmentAddress.LowPart;
        break;

    case PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1:
        {
            DWORD   dwFlags;
            DWORD   dwAddr;

            // The top 7 bits and the bottom 4 bits are flags, so we need to mask them off
            // and restore them after the add.  The allocation addresses should be 256 byte aligned.
            dwFlags = pPatchEntry->AllocationOffset & 0xfe00000f;
            dwAddr = pPatchEntry->AllocationOffset & ~0xfe00000f;
            *pPhyAddr = ((dwResMCAddr + (dwAddr)) - pHwDeviceExtension->lDXVASegmentAddress.LowPart) | dwFlags;
            break;
        }

    //
    // Unknow PM4 packet
    //
    default:
        EngDebugBreak();
        *pPhyAddr = dwResMCAddr;
        return (STATUS_INVALID_PARAMETER);

    } // End of switch (...)

    return (STATUS_SUCCESS);
}

#define GetType3OpCode(n) ((n & 0xFF00) >> 8)


_inline VOID
R200SetCurRLEntry(
    R2D3DDevice                    *pR2D3DDev,
    DXGK_ALLOCATIONLIST            *pAllocationList,
    D3DDDI_PATCHLOCATIONLIST      **ppCurPatchEntry,
    UINT                            ulResID,
    DWORD                           dwAllocationIdx,
    UINT                           *pulCmdBufStart,
    UINT                           *pulCmdBufCurPos,
    UINT                            ulResourceOffset,
    UINT                            ulSlotId,
    BOOLEAN                         WriteOperation)
{
    D3DDDI_PATCHLOCATIONLIST        *pCurPatchEntry = *ppCurPatchEntry;
    UINT                            ulCmdBufOffset = (DWORD)(((PBYTE)pulCmdBufCurPos) - ((PBYTE)pulCmdBufStart));
#ifndef VIDMMPMS
    R2AllocationInfo               *pAllocInfo;
#endif

    //
    // Get the allocation info
    //
    pAllocInfo = (PR2AllocationInfo)pAllocationList[dwAllocationIdx].hDeviceSpecificAllocation;

    if (pAllocInfo == NULL && ulResID != RESITEM_RELEASED)
    {
        DXGK_ALLOCATIONLIST         Allocation = {0};
        D3DDDI_PATCHLOCATIONLIST    Patch = {0};

        // In a production driver we should fail any CmdBuf that references a resource that requires
        // patching but has a NULL handle because this could be an error by the user mode driver or
        // security attack by a malicious application, an un-patched resource will probably result in
        // read/write to system RAM causing corruption or unauthorized access to system RAM
        //
        // In the preamble of this sample driver the user mode driver places references to resources that
        // are not used by the hw and hence have a NULL handle (ie all the texture stages).
        // The sample user mode driver could be changed to only place reference to resources that are
        // used (and will have valid resource handles) into the preamble but we may not get time to
        // make this change. Because of this the KM driver cannot differentiate between the preamble
        // case and a resource that is going to be used by the hw and has a NULL
        // handle (this would result in system RAM corruption)
        //
        // So in this sample driver we will patch this physical address to the primary surfaces so we will
        // not corrupt system RAM and we can see the corruption
        Allocation.SegmentId               = 1; //FB SegID
        Patch.DriverId                = ulResID;
        Patch.AllocationOffset        = ulResourceOffset;
        Patch.PatchOffset             = ulCmdBufOffset;
        Allocation.PhysicalAddress.LowPart = pR2D3DDev->pAdapter->dwLastPrimSurfFBOffset;
        R200PatchPhysicalAddress(pR2D3DDev->pAdapter, pulCmdBufStart, &Allocation, &Patch);

        return;
    }

    //
    // Break when offset within resource is not NULL
    //
    if ((dwRLDebug & RESLIST_DEBUG_BREAK_ON_NONZERO_RESOFFSET) && (ulResourceOffset))
    {
        EngDebugBreak();
    }

    //
    // Initialize the resource list entry
    //
    memset(pCurPatchEntry, 0, sizeof(D3DDDI_PATCHLOCATIONLIST));

    //
    // Set the resource list entry
    //
    pCurPatchEntry->AllocationIndex = dwAllocationIdx;
    pCurPatchEntry->SlotId           = ulSlotId;
    pCurPatchEntry->DriverId         = ulResID;
    pCurPatchEntry->PatchOffset      = ulCmdBufOffset;
    pCurPatchEntry->SplitOffset      = pR2D3DDev->ulCurSplitOffset;
    pCurPatchEntry->AllocationOffset = ulResourceOffset;

    DPF(DBG_RESOURCE_LIST, "New PatchEntry CmdBuf 0x%08lx AllocIdx 0x%08x, SlotID 0x%08x, PatchOff 0x%08x, SplitOff 0x%08x\n", pulCmdBufStart, pCurPatchEntry->AllocationIndex, pCurPatchEntry->SlotId, pCurPatchEntry->PatchOffset, pCurPatchEntry->SplitOffset);

#if DBG
    // Update stats
    pR2D3DDev->sCmdBufStats.dwResListSize++;
    if (pR2D3DDev->sCmdBufStats.dwLastSeenSplitPoint != pR2D3DDev->ulCurSplitOffset)
    {
        pR2D3DDev->sCmdBufStats.dwLastSeenSplitPoint = pR2D3DDev->ulCurSplitOffset;
        pR2D3DDev->sCmdBufStats.dwSplitPointCo++;
    }
#endif

    // If physical address is given we need to prepatch the patch point
    if (pAllocationList[dwAllocationIdx].SegmentId != 0 && ulResID != RESITEM_RELEASED)
    {
        DPF(DBG_RESOURCE_LIST, "PrePatching CmdBuf 0x%08lx AllocIdx 0x%08x\n", pulCmdBufStart, pCurPatchEntry->AllocationIndex);
        R200PatchPhysicalAddress(pR2D3DDev->pAdapter, pulCmdBufStart, &pAllocationList[dwAllocationIdx], pCurPatchEntry);
    }

    //
    // Move on to the next resource list entry
    //
    *ppCurPatchEntry = (pCurPatchEntry + 1);
}

//
// This functions parses type3 PM4 packet and return the size of buffer parsed
DWORD
R200ParseType3PM4Packet(
    PR2D3DDevice                    pR2D3DDev,
    D3DDDI_PATCHLOCATIONLIST      **ppCurPatch,
    DWORD                          *pPM4BufStart,
    DWORD                          *pPM4Packet,
    DWORD                          *pPM4BufEnd,
    DXGK_ALLOCATIONLIST*            pAllocationList)
{
    DXGKRNL_INTERFACE              *pCallback;
    D3DDDI_PATCHLOCATIONLIST       *pCurPatch = *ppCurPatch;
    DWORD                           dwType3Header, dwOpCode;
    DWORD                           dwPacketSize;
    DWORD                           dwMCFrameBufStart;
    DWORD                           dwAllocationIdx;
    DWORD                          *pPhyAddr;
    BOOL                            bDrawingCmd=FALSE;

    pCallback = &(pR2D3DDev->pAdapter->ddiCallback);

    //
    // Getthe header for the type 3 PM4 packet
    //
    dwType3Header = *pPM4Packet;

    //
    // Calculate the size of the type 3 packet
    //
    dwPacketSize = ((dwType3Header & 0x3FFF0000) >> 16) + 2;

    dwOpCode = (dwType3Header & (0xFF00)) >> 8;
    switch (dwOpCode)
    {
    case GetType3OpCode(PM4_PACKET3_NOP):
        {
            D3DResourceID   d3dResID = (dwType3Header & 0xFF);
            D3DKMT_HANDLE   hNewHanlde = *(D3DKMT_HANDLE *)(pPM4Packet + 1);

            // PM4 packet count field is used to store the Allocation Idx
            dwAllocationIdx = (dwType3Header & 0x3FFF0000) >> 16;

            //
            // Handle the resource binding
            //
            if (d3dResID < D3D_RES_ALL)
            {
                DPF(DBG_RES_HANDLES, "New resource handle, Base 0x%08lx, Offset 0x%lx, ResID 0x%lx, New Idx 0x%lx, New hanlde 0x%lx, Old Idx 0x%lx\n", pPM4BufStart, (PBYTE)pPM4Packet-(PBYTE)pPM4BufStart, d3dResID, dwAllocationIdx, hNewHanlde, pR2D3DDev->resArray[d3dResID]);

                //
                // Check if resorce is being released, that is it had a valid
                // handle before and now it is being set to zero
                if (dwAllocationIdx == 0 && pR2D3DDev->resArray[d3dResID] != 0)
                {
                    // Create resource entry to indicate this resource has been free'd
                    R200SetCurRLEntry(pR2D3DDev,
                                      pAllocationList,
                                      &pCurPatch,
                                      RESITEM_RELEASED,     //Zero ResId
                                      0,                    //Index 0 Allocation
                                      pPM4BufStart,
                                      pPM4Packet,
                                      0,
                                      d3dResID,
                                      0);

#if DBG
                    pR2D3DDev->sCmdBufStats.dwDeselectedSlotCo++;
#endif
                }
                pR2D3DDev->resArray[d3dResID] = dwAllocationIdx;

                // UM driver overloaded the count field with the allocationList index, we now need
                // to write the correct value into the count for the hw
                *pPM4Packet = (dwType3Header & ~0x3FFF0000);  //All handle NOP have a zero COUNT

                // Correct the packet size
                dwPacketSize = 2;

            }
        }
        break;

    case GetType3OpCode(PM4_PACKET3_3D_DRAW_IMMD):
    case GetType3OpCode(PM4_PACKET3_3D_DRAW_VBUF):
    case GetType3OpCode(PM4_PACKET3_3D_DRAW_INDX):
    case GetType3OpCode(PM4_PACKET3_3D_DRAW_INDX_2):
        //
        // These type3 PM4 packets don't refer to any video memory resources
        // but we still need to track things for split points
        //
        bDrawingCmd=TRUE;
        break;

    case GetType3OpCode(PM4_PACKET3_3D_LOAD_VBPNTR):
        {
            DWORD   i, dwNumArrays;
            UINT    ulSlotID;

            dwNumArrays = (*(pPM4Packet + 1)) &
                          SE_VTX_NUM_ARRAYS__VTX_NUM_ARRAYS_MASK;
            if (dwNumArrays > VS_MAX_NUM_STREAMS)
            {
                return (-1);
            }

            //
            // Patch the physical address of vertex buffer(s)
            //
            ulSlotID=D3D_RES_STREAM_0;
            for (i = 0; i < dwNumArrays; i++, ulSlotID++)
            {
                pPhyAddr = pPM4Packet  +
                           1           +   // VTX_NUM_ARRAYS
                           ((i/2) + 1) +   // VTX_AOS_ATTR(n)(n+1)
                           (i + 1);        // VTX_AOS_ADDR(n)

                dwAllocationIdx = pR2D3DDev->resTable.dwStreamsIdx[i];

                //
                // Record the vertex buffer pointer in the resource list
                //
                R200SetCurRLEntry(pR2D3DDev,
                                  pAllocationList,
                                  &pCurPatch,
                                  PM4_PACKET3_3D_LOAD_VBPNTR,
                                  dwAllocationIdx,
                                  pPM4BufStart,
                                  pPhyAddr,
                                  *pPhyAddr,
                                  ulSlotID,
                                  0);
            }
        }
        break;
    case GetType3OpCode(PM4_PACKET3_INDX_BUFFER):
        {
            pPhyAddr = pPM4Packet + 2;

            dwAllocationIdx = pR2D3DDev->resTable.dwIndexBufferIdx;

            //
            // Record the index buffer pointer in the resource list
            //
            R200SetCurRLEntry(pR2D3DDev,
                              pAllocationList,
                              &pCurPatch,
                              PM4_PACKET3_INDX_BUFFER,
                              dwAllocationIdx,
                              pPM4BufStart,
                              pPhyAddr,
                              *pPhyAddr,
                              D3D_RES_INDEX_BUFFER,
                              0);
        }
        break;

    //
    // BLT between surfaces with larger pitches
    //
    case GetType3OpCode(PM4_PACKET3_CNTL_TRANS_BITBLT):
        {
            DWORD   dwGUIMasterCntl;

            dwGUIMasterCntl = *(pPM4Packet + 1);

            if ((dwGUIMasterCntl &
                     (DP_GUI_MASTER_CNTL__GMC_SRC_PITCH_OFFSET_CNTL |
                      DP_GUI_MASTER_CNTL__GMC_DST_PITCH_OFFSET_CNTL)) !=
                (DP_GUI_MASTER_CNTL__GMC_SRC_PITCH_OFFSET_CNTL |
                 DP_GUI_MASTER_CNTL__GMC_DST_PITCH_OFFSET_CNTL))
            {
                dwPacketSize = -1;
                break;
            }

            //
            // Record the SRC and DST allocation handle in the resource list
            //
            pPhyAddr = pPM4Packet + 2;

            if (GetPhyAddrFromSurfTilePitchOffset(*pPhyAddr) > 128*1024*1024)
            {
                 EngDebugBreak();
            }

            R200SetCurRLEntry(pR2D3DDev,
                              pAllocationList,
                              &pCurPatch,
                              PM4_PACKET3_CNTL_TRANS_BITBLT,
                              pR2D3DDev->resTable.dwSrc2DIdx,
                              pPM4BufStart,
                              pPhyAddr,
                              *pPhyAddr,
                              D3D_RES_SRC_2D,
                              0);

            pPhyAddr++;


            if (GetPhyAddrFromSurfTilePitchOffset(*pPhyAddr) > 128*1024*1024)
            {
                 EngDebugBreak();
            }

            R200SetCurRLEntry(pR2D3DDev,
                              pAllocationList,
                              &pCurPatch,
                              PM4_PACKET3_CNTL_TRANS_BITBLT,
                              pR2D3DDev->resTable.dwDst2DIdx,
                              pPM4BufStart,
                              pPhyAddr,
                              *pPhyAddr,
                              D3D_RES_DST_2D,
                              TRUE);

            bDrawingCmd=TRUE;
        }
        break;

    //
    // This is used for 2D color fill and clearing render target,
    // and tiling is fully supported.
    //
    case GetType3OpCode(PM4_PACKET3_CNTL_PAINT):
        {
            DWORD                           dwGUIMasterCntl;
            R2AllocationInfo               *pDrvAllocInfo;

            //
            // Set the default value for the packet size
            //
            dwPacketSize = -1;

            dwGUIMasterCntl = *(pPM4Packet + 1);
            if (! (dwGUIMasterCntl &
                   DP_GUI_MASTER_CNTL__GMC_DST_PITCH_OFFSET_CNTL))
            {
                break;
            }

            dwAllocationIdx = pR2D3DDev->resTable.dwDst2DIdx;

            //
            // Get the driver allocation info
            //
            pDrvAllocInfo=(PR2AllocationInfo)pAllocationList[dwAllocationIdx].hDeviceSpecificAllocation;

            if (pDrvAllocInfo)
            {
                DWORD   dwAlignedPitch;
                DWORD   dwTilePitchOffset;

                dwAlignedPitch    = GetPitchFromSurfTilePitchOffset(*(pPM4Packet + 2));
                dwTilePitchOffset =
                        MakeSurfTilePitchOffset(0,              // Res offset
                                                dwAlignedPitch,
                                                pDrvAllocInfo->dwFlags);

                R200SetCurRLEntry(pR2D3DDev,
                                  pAllocationList,
                                  &pCurPatch,
                                  PM4_PACKET3_CNTL_PAINT,
                                  dwAllocationIdx,
                                  pPM4BufStart,
                                  pPM4Packet + 2,
                                  dwTilePitchOffset,
                                  D3D_RES_DST_2D,
                                  TRUE);

                dwPacketSize = ((dwType3Header & 0x3FFF0000) >> 16) + 2;
            }
#ifdef DEBUG
            else
            {
                //
                // No resource list entry is added in this case
                //
                EngDebugBreak();
            }
#endif
            //
            // Set the 2D DST handle to NULL
            //
            pR2D3DDev->resTable.dwDst2DIdx = 0;

            bDrawingCmd=TRUE;
        }
        break;

    case GetType3OpCode(PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV):
        {
            dwAllocationIdx = pR2D3DDev->resTable.dwDXVADestAllocationIdx;
            if (dwAllocationIdx == 0)
            {
                dwPacketSize = -1;
                EngDebugBreak();
            }

            // There are INTRA block packets, 1D vector packets, and 2D vector packets

            dwPacketSize = ((dwType3Header & 0x3FFF0000) >> 16) + 2;
            if (dwPacketSize >= 10)
            {
                switch (pPM4Packet[2])
                {
                case 7:  // PM4F_INTRA_MBLOCK
                    pPhyAddr = pPM4Packet + 4;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pAllocationList,
                                    &pCurPatch,
                                    PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                    dwAllocationIdx,
                                    pPM4BufStart,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_DXVA_DEST_ALLOCATION,
                                    TRUE);

                    pPhyAddr = pPM4Packet + 7;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pAllocationList,
                                    &pCurPatch,
                                    PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                    dwAllocationIdx,
                                    pPM4BufStart,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_DXVA_DEST_ALLOCATION,
                                    TRUE);

                    pPhyAddr = pPM4Packet + 9;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pAllocationList,
                                    &pCurPatch,
                                    PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                    dwAllocationIdx,
                                    pPM4BufStart,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_DXVA_DEST_ALLOCATION,
                                    TRUE);
                    break;

                case 6: // PM4F_1D_2VECTOR
                    pPhyAddr = pPM4Packet + 5;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pAllocationList,
                                    &pCurPatch,
                                    PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                    dwAllocationIdx,
                                    pPM4BufStart,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_DXVA_DEST_ALLOCATION,
                                    TRUE);

                    pPhyAddr = pPM4Packet + 8;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pAllocationList,
                                    &pCurPatch,
                                    PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                    dwAllocationIdx,
                                    pPM4BufStart,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_DXVA_DEST_ALLOCATION,
                                    TRUE);

                    if (pPM4Packet[9] != 3)
                    {
                        pPhyAddr = pPM4Packet + 12;
                        R200SetCurRLEntry(pR2D3DDev,
                                        pAllocationList,
                                        &pCurPatch,
                                        PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                        dwAllocationIdx,
                                        pPM4BufStart,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_DEST_ALLOCATION,
                                        TRUE);

                        pPhyAddr = pPM4Packet + 15;
                        R200SetCurRLEntry(pR2D3DDev,
                                        pAllocationList,
                                        &pCurPatch,
                                        PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                        dwAllocationIdx,
                                        pPM4BufStart,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_DEST_ALLOCATION,
                                        TRUE);

                        pPhyAddr = pPM4Packet + 19;
                        R200SetCurRLEntry(pR2D3DDev,
                                        pAllocationList,
                                        &pCurPatch,
                                        PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                        dwAllocationIdx,
                                        pPM4BufStart,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_DEST_ALLOCATION,
                                        TRUE);

                        pPhyAddr = pPM4Packet + 22;
                        R200SetCurRLEntry(pR2D3DDev,
                                        pAllocationList,
                                        &pCurPatch,
                                        PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                        dwAllocationIdx,
                                        pPM4BufStart,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_DEST_ALLOCATION,
                                        TRUE);
                    }
                    else
                    {
                        pPhyAddr = pPM4Packet + 10;
                        R200SetCurRLEntry(pR2D3DDev,
                                        pAllocationList,
                                        &pCurPatch,
                                        PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                        dwAllocationIdx,
                                        pPM4BufStart,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_DEST_ALLOCATION,
                                        TRUE);
                    }
                    break;

                case 5: // PM4F_2D_2VECTOR
                    pPhyAddr = pPM4Packet + 6;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pAllocationList,
                                    &pCurPatch,
                                    PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                    dwAllocationIdx,
                                    pPM4BufStart,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_DXVA_DEST_ALLOCATION,
                                    TRUE);

                    pPhyAddr = pPM4Packet + 10;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pAllocationList,
                                    &pCurPatch,
                                    PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                    dwAllocationIdx,
                                    pPM4BufStart,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_DXVA_DEST_ALLOCATION,
                                    TRUE);

                    if (pPM4Packet[11] != 3)
                    {
                        pPhyAddr = pPM4Packet + 15;
                        R200SetCurRLEntry(pR2D3DDev,
                                        pAllocationList,
                                        &pCurPatch,
                                        PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                        dwAllocationIdx,
                                        pPM4BufStart,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_DEST_ALLOCATION,
                                        TRUE);

                        pPhyAddr = pPM4Packet + 19;
                        R200SetCurRLEntry(pR2D3DDev,
                                        pAllocationList,
                                        &pCurPatch,
                                        PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                        dwAllocationIdx,
                                        pPM4BufStart,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_DEST_ALLOCATION,
                                        TRUE);

                        pPhyAddr = pPM4Packet + 24;
                        R200SetCurRLEntry(pR2D3DDev,
                                        pAllocationList,
                                        &pCurPatch,
                                        PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                        dwAllocationIdx,
                                        pPM4BufStart,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_DEST_ALLOCATION,
                                        TRUE);

                        pPhyAddr = pPM4Packet + 28;
                        R200SetCurRLEntry(pR2D3DDev,
                                        pAllocationList,
                                        &pCurPatch,
                                        PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                        dwAllocationIdx,
                                        pPM4BufStart,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_DEST_ALLOCATION,
                                        TRUE);
                    }
                    else
                    {
                        pPhyAddr = pPM4Packet + 12;
                        R200SetCurRLEntry(pR2D3DDev,
                                        pAllocationList,
                                        &pCurPatch,
                                        PM4_PACKET3_MPEG_IDCT_MACROBLOCK_REV + 1,
                                        dwAllocationIdx,
                                        pPM4BufStart,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_DEST_ALLOCATION,
                                        TRUE);
                    }
                    break;

                default:
                    dwPacketSize = -1;
                    EngDebugBreak();
                    break;
                }
            }
        }

        bDrawingCmd=TRUE;
        break;

    case GetType3OpCode(PM4_PACKET3_VB_OFFSET):
        //No patching required
        break;

    case GetType3OpCode(PM4_PACKET3_VB_BASE_ADDR):
        {
            DWORD   dwStreamIdx;

            // Find stream index
            pPhyAddr = pPM4Packet + 2;
            dwStreamIdx=pPM4Packet[1] - 0xea;
            if (dwStreamIdx >= VS_MAX_NUM_STREAMS)
            {
                DBG_BREAK;
                return -1;
            }

            R200SetCurRLEntry(pR2D3DDev,
                        pAllocationList,
                        &pCurPatch,
                        PM4_PACKET3_VB_BASE_ADDR,
                        pR2D3DDev->resTable.dwStreamsIdx[dwStreamIdx],
                        pPM4BufStart,
                        pPhyAddr,
                        0,
                        D3D_RES_STREAM_0 + dwStreamIdx,
                        0);
            break;
        }

    default:
        dwPacketSize = -1;
        EngDebugBreak();
        break;
    }

    //
    // Return the resource list entry pointer
    //
    *ppCurPatch = pCurPatch;

    // If this was a drawing packet, record the offset of next PM packet
    if (bDrawingCmd == TRUE)
    {
        //
        // If we want to allow DMA splitting then update current split point to
        // after last drawing operation
        //
        if (gbEnableDMASplitting == TRUE)
        {
            pR2D3DDev->ulCurSplitOffset= (DWORD)((PBYTE)pPM4Packet - (PBYTE)pPM4BufStart + (dwPacketSize * 4));
        }

#if DBG
        pR2D3DDev->sCmdBufStats.dwDrawCmdCo++;
#endif
        DPF(DBG_DRAWCMD, "Drawing PM4 packet (0x%lx), Base 0x%08lx, Offset 0x%lx\n", dwOpCode, pPM4BufStart, (PBYTE)pPM4Packet - (PBYTE)pPM4BufStart);
    }

    return (dwPacketSize);
}

NTSTATUS
D3DDDIRender(
    HANDLE                  hContext,
    DXGKARG_RENDER     *pDDIRenderData)
{
    return D3DDDIRenderInternal(hContext, pDDIRenderData, FALSE);
}


NTSTATUS
D3DDDIRenderInternal(
    HANDLE                  hContext,
    DXGKARG_RENDER          *pDDIRenderData,
    BOOL                    bFromPresent)
{
    PR2D3DDevice            pR2D3DDev;
    PR2D3DContext           pR2D3DConext;
    PHW_DEVICE_EXTENSION    pAdapter;
    DWORD                   dwPM4Entries;
    DWORD                  *pPM4Buf, *pPM4BufEnd, *pCurPM4Packet;
    DWORD                  *pRegStart;
    DWORD                   dwPM4PacketSize, dwPM4PacketHeader;
    DWORD                   dwPM4RegCount, dwPM4RegStart, dwPM4RegEnd;
    DWORD                   dwAllocationIdx;
    DWORD                  *pPhyAddr;
    PR200_DMA_PRIVATEDATA   pDmaPrivateData;
    DWORD                   dwPatchLocationCount;
    NTSTATUS                Status = STATUS_SUCCESS;
#if defined(LHVIDMM)
    LONGLONG                llFence = 0xDEADBEEF;
    D3DDDI_PATCHLOCATIONLIST *pPatchCur, *pPatchEnd;
#endif
    PUMD_CMDBUF_INFO        pPm4PacketInfo;
    BOOL                    bDXVACmdBuf = FALSE;

    //
    // Get the device and adapter
    //
    pR2D3DConext = (PR2D3DContext)hContext;
    pR2D3DDev = pR2D3DConext->pDevice;
    pAdapter  = (PHW_DEVICE_EXTENSION)pR2D3DDev->pAdapter;

    //
    // Get DMA buffer private data
    //
    pDmaPrivateData=(PR200_DMA_PRIVATEDATA)pDDIRenderData->pDmaBufferPrivateData;
    if (bFromPresent == FALSE)
    {        
        ASSERT(pDmaPrivateData == NULL || pDDIRenderData->DmaBufferPrivateDataSize == sizeof(R200_DMA_PRIVATEDATA));
        RtlZeroMemory(pDmaPrivateData, sizeof(R200_DMA_PRIVATEDATA));
        pDmaPrivateData->dwPacketId=InterlockedAnd(&gdwDMAPacketId, 1);
        pDmaPrivateData->Type = DMA_PACKET_TYPE_RENDER;        
    }

    //
    // Make sure the DMA buffer is big enough
    //
    if (pDDIRenderData->DmaSize < pDDIRenderData->CommandLength)
    {
        DBG_BREAK;
        return (STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER);
    }

    dwPM4Entries = pDDIRenderData->CommandLength >> 2;

    //
    // Set up the curren resource list entry pointer
    // NOTE: It is assumed that the resource list is always big enough
    //
    pPatchCur = pDDIRenderData->pPatchLocationListOut;
    pPatchEnd = pDDIRenderData->pPatchLocationListOut + pDDIRenderData->PatchLocationListOutSize;


    //
    // Parse DX10 command buffer to generate the resource list
    //

    __try   //  access to command buffer
    { 
        pPM4Buf = (LPDWORD)(pDDIRenderData->pCommand);

        pPM4BufEnd    = pPM4Buf + dwPM4Entries;
        pCurPM4Packet = pPM4Buf;

        // Check if UMD debug packet is at start of cmd buf
        pPm4PacketInfo = (PUMD_CMDBUF_INFO)pPM4Buf;    
        if (pPm4PacketInfo->dwInfoNopHeader == PM4_INFO_PACKET_HEADER && bFromPresent == FALSE)
        {
            if (pPm4PacketInfo->dwBreakIntoDebugger != 0)
            {
                DBG_BREAK;
            }

        }
        else
        {
            pPm4PacketInfo = NULL;
        }

        //
        // Init split point info
        //
        pR2D3DDev->ulCurSplitOffset=0;
        DPF(DBG_RESOURCE_LIST, "Render cmd buf, Base 0x%lx, ID 0x%lx, Size 0x%lx\n", pDDIRenderData->pCommand, pDmaPrivateData->dwPacketId, pDDIRenderData->CommandLength);

#if DBG
        // Zero CmdBuf stats
        memset(&pR2D3DDev->sCmdBufStats, 0, sizeof(pR2D3DDev->sCmdBufStats));

        {
            DWORD   dwIdx;

            DPF(DBG_RES_HANDLES, "Alloc table for CmdBuf at 0x%08lx\n", pDDIRenderData->pCommand);
            for (dwIdx=0; dwIdx < pDDIRenderData->AllocationListSize; dwIdx++)
            {
                R2AllocationInfo*    pAllocInfo = (PR2AllocationInfo)pDDIRenderData->pAllocationList[dwIdx].hDeviceSpecificAllocation;
                DWORD               dwHandle = 0;

                if (pAllocInfo != NULL)
                {
                    dwHandle = pAllocInfo->vidMemData.hAllocation;
                }
                DPF(DBG_RES_HANDLES, "AllocIdx %ld, Hanlde 0x%08lx\n, SegId %ld, PhysAddr 0x%08lx", dwIdx, dwHandle, pDDIRenderData->pAllocationList[dwIdx].SegmentId, pDDIRenderData->pAllocationList[dwIdx].PhysicalAddress.LowPart);
            }
        }
#endif
    }
    __except(EXCEPTION_EXECUTE_HANDLER)
    {
        EngDebugBreak();
        return (STATUS_PRIVILEGED_INSTRUCTION);
    }

#if defined(LHVIDMM)

    __try       //  command buffer access
    {


        do
        {
            //
            // dwPM4PacketSize of -1 indicates wrongly formated PM4 packet
            //
            dwPM4PacketSize = -1;

            dwPM4PacketHeader = *pCurPM4Packet;
            switch (dwPM4PacketHeader >> 30)
            {
            case 0:

                dwPM4RegCount = ((dwPM4PacketHeader & 0x3FFF0000) >> 16) + 1;
                dwPM4RegStart = dwPM4PacketHeader & 0x00003FFF;

                dwPM4PacketSize = 1 + dwPM4RegCount;

                //
                // Check if the write-one-reg flag is set
                //
                if (dwPM4PacketHeader & 0x00008000)
                {
                    dwPM4RegEnd   = dwPM4RegStart;
                    dwPM4RegCount = 1;
                }
                else
                {
                    dwPM4RegEnd   = dwPM4RegStart + dwPM4RegCount - 1;
                }

                //
                // Check if there is enough patch entry for maximal number of
                // resource reference in this packet
                //
                if ((pPatchCur + dwPM4RegCount) >= pPatchEnd)
                {
                    Status = STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER;
                    dwPM4Entries = (DWORD)(pCurPM4Packet - pPM4Buf);
                    EngDebugBreak();
                    goto Render_Exit;
                }

                //
                // Prepare the pointer to the current physical address offset
                //
                pRegStart = pCurPM4Packet + 1;

                //
                // Check if VIDMEM resources (2D/RT/Z/TEX/VB/VS/PS/DMA) are used
                //
                if ((dwPM4RegStart <= mmRB3D_COLOROFFSET) &&        // 0x710
                    (dwPM4RegEnd   >= mmRB3D_COLOROFFSET))
                {
                    dwAllocationIdx= pR2D3DDev->resTable.dwRenderTargetIdx;
                    pPhyAddr    = pRegStart + mmRB3D_COLOROFFSET - dwPM4RegStart;

    #ifdef DEBUG
                    if (dwRLDebug & RESLIST_DEBUG_FORCE_RENDER2PRIM)
                    {
                        *pPhyAddr += pAdapter->dwLastPrimSurfFBOffset + pAdapter->lfbMemoryControllerAddress.LowPart;
                    }
                    else
    #endif
                    {
                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmRB3D_COLOROFFSET,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_RENDER_TARGET,
                                        TRUE);
                    }
                }
                if ((dwPM4RegStart <= mmRB3D_DEPTHOFFSET) &&        // 0x709
                    (dwPM4RegEnd   >= mmRB3D_DEPTHOFFSET))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwZBufferIdx;
                    pPhyAddr    = pRegStart + mmRB3D_DEPTHOFFSET - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmRB3D_DEPTHOFFSET,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_ZBUFFER,
                                    TRUE);
                }
                if ((dwPM4RegStart <= mmPP_TXOFFSET_0) &&           // 0x717
                    (dwPM4RegEnd   >= mmPP_TXOFFSET_0))
                {
                    // DXVA packets require PP_TXOFFSET_0 to be zero so we do not want to patch it.
                    // This is ok as no hw access will be performed through this zero value address.
                    // Ideally a production driver would not have code like this as it does pose a 
                    // security issue
                    if (bDXVACmdBuf == FALSE)
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[0][0];
                        pPhyAddr    = pRegStart + mmPP_TXOFFSET_0 - dwPM4RegStart;
                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_TXOFFSET_0,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_TEXTURE_0,
                                        0);
                    }
                }
                if ((dwPM4RegStart <= mmPP_TXOFFSET_1) &&           // 0x71D
                    (dwPM4RegEnd   >= mmPP_TXOFFSET_1))
                {
                    // DXVA packets require PP_TXOFFSET_1 to be zero so we do not want to patch it.
                    // This is ok as no hw access will be performed through this zero value address.
                    // Ideally a production driver would not have code like this as it does pose a 
                    // security issue
                    if (bDXVACmdBuf == FALSE)
                    {                
                        dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[1][0];
                        pPhyAddr    = pRegStart + mmPP_TXOFFSET_1 - dwPM4RegStart;
                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_TXOFFSET_1,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_TEXTURE_1,
                                        0);
                    }
                }
                if ((dwPM4RegStart <= mmPP_TXOFFSET_2) &&           // 0x723
                    (dwPM4RegEnd   >= mmPP_TXOFFSET_2))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[2][0];
                    pPhyAddr    = pRegStart + mmPP_TXOFFSET_2 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_TXOFFSET_2,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_TEXTURE_2,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_TXOFFSET_3) &&           // 0xB52
                    (dwPM4RegEnd   >= mmPP_TXOFFSET_3))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[3][0];
                    pPhyAddr    = pRegStart + mmPP_TXOFFSET_3 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_TXOFFSET_3,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_TEXTURE_3,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_TXOFFSET_4) &&           // 0xB58
                    (dwPM4RegEnd   >= mmPP_TXOFFSET_4))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[4][0];
                    pPhyAddr    = pRegStart + mmPP_TXOFFSET_4 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_TXOFFSET_4,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_TEXTURE_4,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_TXOFFSET_5) &&           // 0xB5E
                    (dwPM4RegEnd   >= mmPP_TXOFFSET_5))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[5][0];
                    pPhyAddr    = pRegStart + mmPP_TXOFFSET_5 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_TXOFFSET_5,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_TEXTURE_5,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F1_0) &&    // 0xB41
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F1_0))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[0][1];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F1_0 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F1_0,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_0_FACE_1,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F2_0) &&    // 0xB42
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F2_0))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[0][2];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F2_0 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F2_0,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_0_FACE_2,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F3_0) &&    // 0xB43
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F3_0))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[0][3];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F3_0 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F3_0,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_0_FACE_3,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F4_0) &&    // 0xB44
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F4_0))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[0][4];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F4_0 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F4_0,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_0_FACE_4,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F5_0) &&    // 0xB45
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F5_0))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[0][5];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F5_0 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F5_0,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_0_FACE_5,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F1_1) &&    // 0xB47
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F1_1))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[1][1];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F1_1 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F1_1,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_1_FACE_1,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F2_1) &&    // 0xB48
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F2_1))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[1][2];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F2_1 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F2_1,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_1_FACE_2,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F3_1) &&    // 0xB49
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F3_1))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[1][3];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F3_1 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F3_1,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_1_FACE_3,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F4_1) &&    // 0xB4A
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F4_1))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[1][4];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F4_1 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F4_1,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_1_FACE_4,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F5_1) &&    // 0xB4B
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F5_1))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[1][5];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F5_1 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F5_1,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_1_FACE_5,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F1_2) &&    // 0xB4D
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F1_2))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[2][1];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F1_2 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F1_2,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_2_FACE_1,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F2_2) &&    // 0xB4E
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F2_2))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[2][2];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F2_2 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F2_2,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_2_FACE_2,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F3_2) &&    // 0xB4F
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F3_2))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[2][3];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F3_2 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F3_2,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_2_FACE_3,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F4_2) &&    // 0xB50
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F4_2))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[2][4];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F4_2 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F4_2,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_2_FACE_4,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F5_2) &&    // 0xB51
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F5_2))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[2][5];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F5_2 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F5_2,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_2_FACE_5,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F1_3) &&    // 0xB53
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F1_3))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[3][1];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F1_3 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F1_3,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_3_FACE_1,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F2_3) &&    // 0xB54
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F2_3))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[3][2];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F2_3 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F2_3,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_3_FACE_2,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F3_3) &&    // 0xB55
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F3_3))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[3][3];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F3_3 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F3_3,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_3_FACE_3,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F4_3) &&    // 0xB56
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F4_3))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[3][4];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F4_3 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F4_3,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_3_FACE_4,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F5_3) &&    // 0xB57
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F5_3))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[3][5];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F5_3 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F5_3,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_3_FACE_5,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F1_4) &&    // 0xB59
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F1_4))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[4][1];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F1_4 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F1_4,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_4_FACE_1,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F2_4) &&    // 0xB5A
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F2_4))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[4][2];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F2_4 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F2_4,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_4_FACE_2,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F3_4) &&    // 0xB5B
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F3_4))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[4][3];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F3_4 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F3_4,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_4_FACE_3,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F4_4) &&    // 0xB5C
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F4_4))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[4][4];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F4_4 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F4_4,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_4_FACE_4,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F5_4) &&    // 0xB5D
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F5_4))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[4][5];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F5_4 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F5_4,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_4_FACE_5,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F1_5) &&    // 0xB5F
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F1_5))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[5][1];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F1_5 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F1_5,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_5_FACE_1,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F2_5) &&    // 0xB60
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F2_5))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[5][2];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F2_5 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F2_5,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_5_FACE_2,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F3_5) &&    // 0xB61
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F3_5))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[5][3];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F3_5 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F3_5,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_5_FACE_3,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F4_5) &&    // 0xB62
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F4_5))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[5][4];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F4_5 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F4_5,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_5_FACE_4,
                                    0);
                }
                if ((dwPM4RegStart <= mmPP_CUBIC_OFFSET_F5_5) &&    // 0xB63
                    (dwPM4RegEnd   >= mmPP_CUBIC_OFFSET_F5_5))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwTexturesIdx[5][5];
                    pPhyAddr    = pRegStart + mmPP_CUBIC_OFFSET_F5_5 - dwPM4RegStart;
                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmPP_CUBIC_OFFSET_F5_5,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_CUBEMAP_5_FACE_5,
                                    0);
                }
                // 2D engine surfaces
                if ((dwPM4RegStart <= mmDST_OFFSET) &&              // 0x501
                    (dwPM4RegEnd   >= mmDST_OFFSET))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwDst2DIdx;
                    pPhyAddr    = pRegStart + mmDST_OFFSET - dwPM4RegStart;

                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmDST_OFFSET,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_DST_2D,
                                    TRUE);
                }
                if ((dwPM4RegStart <= mmSRC_OFFSET) &&              // 0x56B
                    (dwPM4RegEnd   >= mmSRC_OFFSET))
                {
                    dwAllocationIdx = pR2D3DDev->resTable.dwSrc2DIdx;
                    pPhyAddr    = pRegStart + mmSRC_OFFSET - dwPM4RegStart;

                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmSRC_OFFSET,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_SRC_2D,
                                    0);
                }
                // DMA engine operation
                //
                if ((dwPM4RegStart <= mmCP_GUI_DST_ADDR) &&         // 0x1C9
                    (dwPM4RegEnd   >= mmCP_GUI_DST_ADDR))
                {
                    //
                    //
                    dwAllocationIdx = pR2D3DDev->resTable.dwDstGUIDMAIdx;
                    pPhyAddr    = pRegStart + mmCP_GUI_DST_ADDR - dwPM4RegStart;

                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmCP_GUI_DST_ADDR,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_GUI_DMA_DST,
                                    TRUE);
                }
                if ((dwPM4RegStart <= mmCP_GUI_SRC_ADDR) &&         // 0x1C8
                    (dwPM4RegEnd   >= mmCP_GUI_SRC_ADDR))
                {
                    //
                    // 3D uses it to render indexed primitives with HW index
                    // buffer that is not DWORD aligned.
                    //
                    dwAllocationIdx = pR2D3DDev->resTable.dwSrcGUIDMAIdx;
                    pPhyAddr    = pRegStart + mmCP_GUI_SRC_ADDR - dwPM4RegStart;

                    R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                    &pPatchCur,
                                    mmCP_GUI_SRC_ADDR,
                                    dwAllocationIdx,
                                    pPM4Buf,
                                    pPhyAddr,
                                    *pPhyAddr,
                                    D3D_RES_GUI_DMA_SRC,
                                    TRUE);
                }
                if ((dwPM4RegStart >= mmPP_SRC_OFFSET_0) &&         // 0x610
                    (dwPM4RegEnd <= mmPP_SRC_OFFSET_17))
                {
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_0) &&         // 0x610
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_0))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[0][0];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_0 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                    pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_0,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_OFFSET_Y0,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_1) &&         // 0x611
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_1))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[0][1];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_1 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_1,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_PITCH_Y0,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_2) &&         // 0x612
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_2))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[0][2];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_2 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_2,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_OFFSET_U0,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_3) &&         // 0x613
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_3))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[0][3];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_3 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_3,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_OFFSET_U0_PITCH_UV,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_4) &&         // 0x614
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_4))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[0][4];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_4 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_4,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_OFFSET_V0,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_5) &&         // 0x615
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_5))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[0][5];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_5 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_5,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_OFFSET_V0_PITCH_UV,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_6) &&         // 0x616
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_6))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[1][0];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_6 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_6,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_OFFSET_Y1,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_7) &&         // 0x617
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_7))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[1][1];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_7 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_7,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_PITCH_Y1,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_8) &&         // 0x618
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_8))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[1][2];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_8 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_8,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_OFFSET_U1,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_9) &&         // 0x619
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_9))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[1][3];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_9 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_9,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_OFFSET_U1_PITCH_UV,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_10) &&         // 0x61a
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_10))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[1][4];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_10 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_10,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_OFFSET_V1,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_11) &&         // 0x620
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_11))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[1][5];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_11 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_11,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_OFFSET_V1_PITCH_UV,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_12) &&         // 0x621
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_12))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[2][0];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_12 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_12,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_OFFSET_Y2,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_13) &&         // 0x622
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_13))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[2][1];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_13 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_13,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_PITCH_Y2,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_14) &&         // 0x623
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_14))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[2][2];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_14 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_14,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_OFFSET_U2,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_15) &&         // 0x624
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_15))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[2][3];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_15 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_15,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_OFFSET_U2_PITCH_UV,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_16) &&         // 0x625
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_16))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[2][4];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_16 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_16,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_OFFSET_V2,
                                        0);
                    }
                    if ((dwPM4RegStart <= mmPP_SRC_OFFSET_17) &&         // 0x626
                        (dwPM4RegEnd   >= mmPP_SRC_OFFSET_17))
                    {
                        dwAllocationIdx = pR2D3DDev->resTable.dwDXVAIdx[2][5];
                        pPhyAddr    = pRegStart + mmPP_SRC_OFFSET_17 - dwPM4RegStart;

                        R200SetCurRLEntry(pR2D3DDev,
                                        pDDIRenderData->pAllocationList,
                                        &pPatchCur,
                                        mmPP_SRC_OFFSET_17,
                                        dwAllocationIdx,
                                        pPM4Buf,
                                        pPhyAddr,
                                        *pPhyAddr,
                                        D3D_RES_DXVA_OFFSET_V2_PITCH_UV,
                                        0);
                    }
                }
                if ((dwPM4RegStart <= mmSE_MC_BUF_BASE) &&          // 0x679
                    (dwPM4RegEnd   >= mmSE_MC_BUF_BASE))
                {
                    pPhyAddr    = pRegStart + mmSE_MC_BUF_BASE - dwPM4RegStart;
                    *pPhyAddr   = pAdapter->lDXVASegmentAddress.LowPart;

                    // Remember this is a DXVA command buffer
                    bDXVACmdBuf = TRUE;

                    // In the past we have seen TDR's because some of the DXVA surfaces where not in the 
                    // DXVA segment.
                    ASSERT(AreAllAllocationsDXVARenderTargets(pDDIRenderData) == TRUE);
                }
                break;

            case 1:
            case 2:
                dwPM4PacketSize = -1;
                EngDebugBreak();
                break;

            case 3:
                //
                // The 3D_LOAD_VBPNTR needs at most 12 RL entry, which is the
                // maximal number of resources can be used in a type3 PM4 packet.
                //
                if ((pPatchCur + 12) >= pPatchEnd)
                {
                    Status = STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER;
                    dwPM4Entries = (DWORD)(pCurPM4Packet - pPM4Buf);
                    EngDebugBreak();
                    goto Render_Exit;
                }

                //
                // Size of type3 PM4 packet is harder to calculate
                //
                dwPM4PacketSize = R200ParseType3PM4Packet(pR2D3DDev,
                                                        &pPatchCur,
                                                        pPM4Buf,
                                                        pCurPM4Packet,
                                                        pPM4BufEnd,
                                                        pDDIRenderData->pAllocationList);
                break;
            default:
                // HSLDPF(E_ERROR_MESSAGE, "DX10 command buffer : Wrong PM4 packet");
                EngDebugBreak();
                return (STATUS_ILLEGAL_INSTRUCTION);
            }

            if (dwPM4PacketSize == -1)
            {

                return (STATUS_INVALID_HANDLE);
            }

            //
            // Move on to the next PM4 packet
            //
            pCurPM4Packet += dwPM4PacketSize;

        } while (pCurPM4Packet < pPM4BufEnd);
    }
    __except(EXCEPTION_EXECUTE_HANDLER)
    {
        EngDebugBreak();
        return (STATUS_PRIVILEGED_INSTRUCTION);
    }
#endif // LHVIDMM

Render_Exit:

    if (0 == dwPM4Entries)
    {
        //
        // Something is wrong, the command buffer is empty
        // Dxgkrnl protects against this so we should nenver see it
        //
        DPF(DBG_ERROR, "D3DDDIPresent : CmdBuf is empty\n");
        DBG_BREAK;
    }

    //
    // Return to current resource list entry
    //
    pDDIRenderData->pPatchLocationListOut= pPatchCur;

    //
    // Copy command buffer into DMA buffer, which contains offsets into the
    // resources and is ready to be patched
    //
    // NOTE: Present uses DMA buffer as the command buffer
    //

    __try // accessing command buffer
    {
        if (pDDIRenderData->pDmaBuffer != pDDIRenderData->pCommand)
        {
            memcpy(pDDIRenderData->pDmaBuffer,
                pDDIRenderData->pCommand,
                dwPM4Entries*sizeof(DWORD));
        }
    }
    __except(EXCEPTION_EXECUTE_HANDLER)
    {
        EngDebugBreak();
        return (STATUS_PRIVILEGED_INSTRUCTION);
    }

    if (STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER == Status)
    {
        // Need to declare how far we've gone in command buffer
        pDDIRenderData->MultipassOffset += (dwPM4Entries*sizeof(DWORD));
    }

    //
    // NOTE : R200 requires that DMA buffer has to be QUADWORD aligned,
    //        it is better handled here
    //
    if (dwPM4Entries & 1)
    {
        *(((DWORD *)pDDIRenderData->pDmaBuffer) + dwPM4Entries) =
            PM4_PACKET2_NOP;
        dwPM4Entries++;
    }

    //
    // Return the current DMA buffer pointer
    //
    ((UCHAR *)pDDIRenderData->pDmaBuffer) += (dwPM4Entries*sizeof(DWORD));

    //
    // Return next private data addr
    //
    pDDIRenderData->pDmaBufferPrivateData=(PVOID)((PBYTE)pDDIRenderData->pDmaBufferPrivateData + sizeof(R200_DMA_PRIVATEDATA));

    if (Status == STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER)
    {
        // This will result in visual errors as we will create a DMA buffer that contains the command buffer
        // upto this point and not the complete command buffer
        DBG_BREAK;
        Status = STATUS_SUCCESS;
    }
    return Status;
}

//
// Program pitch and offset
//

#define RADEON_PACK_TILE_LINEAR             0
#define RADEON_PACK_TILE_TILED              1
#define RADEON_PACK_TILE_MICROTILED         2
#define RADEON_PACK_OFFSET_SHIFT            10
#define RADEON_PACK_PITCH_SHIFT             6

#define FULL_SC_BOTTOM_RIGHT             (((DEFAULT_SC_BOTTOM_RIGHT__DEFAULT_SC_RIGHT_MASK >> 1) \
                                            & DEFAULT_SC_BOTTOM_RIGHT__DEFAULT_SC_RIGHT_MASK)     \
                                            | ((DEFAULT_SC_BOTTOM_RIGHT__DEFAULT_SC_BOTTOM_MASK >> 1) \
                                            & DEFAULT_SC_BOTTOM_RIGHT__DEFAULT_SC_BOTTOM_MASK))


static VOID
R200SetPitchOffset(
    HW_DEVICE_EXTENSION    *pHwDeviceExtension,
    DWORD                   dwCRTCIndex,
    DWORD                   dwMCOffsetPS,
    DWORD                   dwAlignedPitchInBytes,
    DWORD                   dwTilingMode)
{
    DWORD   dwPackedOffset = 0;
    DWORD   dwPackedPitch = 0;
    DWORD   dwPackedTileMode = 0;
    DWORD   dwPitchOffset = 0;

    // These tiling setting are currently the same for all
    // versions of Radeon (100, 200, and 300). [RA]
    switch (dwTilingMode)
    {
    case CMM_TILING_MODE__NONE:
        dwPackedTileMode = RADEON_PACK_TILE_LINEAR;
        break;
    case CMM_TILING_MODE__MACRO:
        dwPackedTileMode = RADEON_PACK_TILE_TILED;
        break;
    case CMM_TILING_MODE__MICRO:
        dwPackedTileMode = RADEON_PACK_TILE_MICROTILED;
        break;
    case CMM_TILING_MODE__MACRO_MICRO:
        dwPackedTileMode =  RADEON_PACK_TILE_TILED |
                            RADEON_PACK_TILE_MICROTILED;
        break;
    default:
        ASSERT(FALSE);
        break;
    }

    // Determine the packed offset...
    // Note, need to reference "RADEON_PACK_OFFSET_SHIFT" to determine
    // how much to "pack".
    dwPackedOffset  = dwMCOffsetPS >> RADEON_PACK_OFFSET_SHIFT;
    // Determine the packed pitch...
    // Note, need to reference "RADEON_PACK_PITCH_SHIFT" to determine
    // how much to "pack".
    // Note, must be a multiple of 64 bytes!!!!
    dwPackedPitch   = dwAlignedPitchInBytes >> RADEON_PACK_PITCH_SHIFT;

    // First, or in the offset...
    dwPitchOffset = ((dwPackedOffset << DST_PITCH_OFFSET__DST_OFFSET__SHIFT)
                    & DST_PITCH_OFFSET__DST_OFFSET_MASK);

    // Now, or in the Pitch.
    dwPitchOffset |= ((dwPackedPitch << DST_PITCH_OFFSET__DST_PITCH__SHIFT)
                    & DST_PITCH_OFFSET__DST_PITCH_MASK);

    // Finally, or in the tiling....
    dwPitchOffset |= ((dwPackedTileMode << DST_PITCH_OFFSET__DST_TILE__SHIFT)
                    & DST_PITCH_OFFSET__DST_TILE_MASK);

    if (dwCRTCIndex == 0)
    {
        *(((DWORD *)pHwDeviceExtension->pvMmr) + mmDEFAULT_PITCH_OFFSET)    = dwPitchOffset;
        *(((DWORD *)pHwDeviceExtension->pvMmr) + mmDEFAULT_SC_BOTTOM_RIGHT) = FULL_SC_BOTTOM_RIGHT;
    }
    else
    {
        ASSERT(dwCRTCIndex == 1);

        *(((DWORD *)pHwDeviceExtension->pvMmr) + mmDEFAULT2_PITCH_OFFSET)    = dwPitchOffset;
        *(((DWORD *)pHwDeviceExtension->pvMmr) + mmDEFAULT2_SC_BOTTOM_RIGHT) = FULL_SC_BOTTOM_RIGHT;
    }
}

//
// WARNING: Untested code.
//
// NOTE: This only works when 9000/9700 is working in multi-head mode.
//       (not in multi-card mode)
//

static NTSTATUS
R200SetMode(
    HW_DEVICE_EXTENSION*            pHwDeviceExtension,
    DWORD                           dwModeIndex,
    D3DDDI_VIDEO_PRESENT_SOURCE_ID  VidPnSourceId,
    DWORD                           dwMCOffsetPS)
{
    ULONG DALSetModeVMI(HDAL hDAL, ULONG ulDriverID, VIDEO_MODE_INFORMATION *lpVMI,
                    ULONG ulDisplayOffset, ULONG ulDisplayPitch, BOOL bForce);

    HDAL                    hDAL;
    VIDEO_MODE_INFORMATION  videoModeInfo;

    if(VidPnSourceId >= 2)
    {
        return STATUS_INVALID_PARAMETER;
    }

    hDAL = (HDAL)pHwDeviceExtension->pvhDal;

    if (!DALGetModeVMIEx(hDAL, &videoModeInfo, VidPnSourceId, dwModeIndex))
    {
        return STATUS_INVALID_PARAMETER;
    }

    if (0 == DALSetModeVMI(hDAL,
                           VidPnSourceId,
                           &videoModeInfo,
                           dwMCOffsetPS,
                           0,
                           TRUE))
    {
        return STATUS_INVALID_PARAMETER;
    }

    pHwDeviceExtension->curModeInfo[VidPnSourceId] = videoModeInfo;

    if (pHwDeviceExtension->pvHwOtherDevExt)
    {
        HW_DEVICE_EXTENSION    *pHwDevExt;

        pHwDevExt = (HW_DEVICE_EXTENSION *)pHwDeviceExtension->pvHwOtherDevExt;
        pHwDevExt->curModeInfo[VidPnSourceId] = videoModeInfo;
    }

    //
    // Set pitch and offset
    //

    R200SetPitchOffset(pHwDeviceExtension,
                       VidPnSourceId,
                       dwMCOffsetPS,
                       videoModeInfo.ScreenStride,
                       CMM_TILING_MODE__NONE);

    pHwDeviceExtension->bModeDriverHandled = TRUE;     // We do the drawing

    return STATUS_SUCCESS;
}


NTSTATUS
D3DDDISetVidPnSourceAddress(
    HANDLE                                  hAdapter,
    CONST DXGKARG_SETVIDPNSOURCEADDRESS*    pDDISetVidPnSourceAddress)
{
    HW_DEVICE_EXTENSION*            pAdapter  = ((PHW_DEVICE_EXTENSION*)hAdapter)[0];
    D3DDDI_VIDEO_PRESENT_SOURCE_ID  VidPnSourceId = pDDISetVidPnSourceAddress->VidPnSourceId;

    //
    // Remember the primary's physical address
    //
    pAdapter->curPrimaryOffset[VidPnSourceId] = pDDISetVidPnSourceAddress->PrimaryAddress.LowPart;

    //
    // Store offset of primary surface from FB of the last primary surfaces
    // created, this is used in R200SetCurRLEntry() to resources with inclaid
    // handles to the primary surface.  This can be removed when we remove
    // the chance of invalid handles in the preamble (Bug 949206)
    //
    pAdapter->dwLastPrimSurfFBOffset = pDDISetVidPnSourceAddress->PrimaryAddress.LowPart;

    //
    // And setup source address to DAC.
    //
    if (VidPnSourceId != 0)
    {
        ATI_OUTPD(pAdapter->pvMmr, mmCRTC2_OFFSET, pDDISetVidPnSourceAddress->PrimaryAddress.LowPart);
    }
    else
    {
        ATI_OUTPD(pAdapter->pvMmr, mmCRTC_OFFSET, pDDISetVidPnSourceAddress->PrimaryAddress.LowPart);
    }

    return STATUS_SUCCESS;
}


NTSTATUS
D3DDDISetVidPnSourceVisibility(
    HANDLE                                   hAdapter,
    CONST DXGKARG_SETVIDPNSOURCEVISIBILITY*  pDDISetVidPnSourceVisibility)
{
    //
    // Defined in dal.c.
    //
    VOID DALSetDisplayOnController(HDAL hDal, ULONG ulController, ULONG ulDisplays);

    NTSTATUS                        Status;
    HW_DEVICE_EXTENSION*            pAdapter  = ((PHW_DEVICE_EXTENSION*)hAdapter)[0];
    HW_DEVICE_EXTENSION*            pAtlAdapter;
    D3DDDI_VIDEO_PRESENT_SOURCE_ID  VidPnSourceId = pDDISetVidPnSourceVisibility->VidPnSourceId;

    //
    // HACK HACK
    // SetVidPnSourceStatus() expects to to use different HeExt for different heads but D3DDDISetOutputState
    // used one HwExt with 0 & 1 CRT index.
    //
    // The DDI will be cleaned up in the near future to solve this inconsistence
    //
    if (pDDISetVidPnSourceVisibility->VidPnSourceId == 1)
    {
        // Use other HwExt to call SetViewStatus()
        pAtlAdapter = pAdapter->pvHwOtherDevExt;
    }
    else
    {
        // Use given HwExt to call SetViewStatus()
        pAtlAdapter = pAdapter;
    }

    if (pDDISetVidPnSourceVisibility->Visible)
    {
        ASSERT(VidPnSourceId < 2);

        //
        // This path could be called repeatedly so
        // Disable head always before enabled, otherwise R200 bandwidth calculation
        // as it will fail to subtract the banwidth from existing mode
        //
        SetVidPnSourceStatus((PVOID)&pAtlAdapter, 0, FALSE);

        //
        // Enable the head first
        //
        SetVidPnSourceStatus((PVOID)&pAtlAdapter, 0, TRUE);

        //
        // Set the active displays at this point.
        //
        
        if (pAdapter->ulEnabledDisplays > 0)
        {
            DALSetDisplayOnController(pAdapter->pvhDal, VidPnSourceId, pAdapter->ulEnabledDisplays);
        }

        //
        // NOTE: It is assumed that primary surface is always in local
        //       video memory, and passed in physical address is just
        //       an offset into the local video memory segment.
        //
        Status = R200SetMode(pAdapter,
                             pAdapter->curModeInfo[VidPnSourceId].ModeIndex,
                             VidPnSourceId,
                             pAdapter->curPrimaryOffset[VidPnSourceId]);
    }
    else
    {
        // R200 sample miniport doesn't currently support this, but real production driver should stop touching the primary at this point.
        Status = STATUS_SUCCESS;
    }

    return Status;
}


NTSTATUS
D3DDDIUpdateActiveVidPnPresentPath
(
    HANDLE                                        hAdapter,
    CONST DXGKARG_UPDATEACTIVEVIDPNPRESENTPATH*   pUpdateActiveVidPnPresentPathArg
)
{
    return STATUS_SUCCESS;
}


// NOTE: Production driver should use this method to recommend modes supported by monitor.
//       Note that GDI will not prune any modes explicitly listed as supported in the monitor mode set.
NTSTATUS
D3DDDIRecommendMonitorModes
(
    HANDLE                                hAdapter,
    CONST DXGKARG_RECOMMENDMONITORMODES*  pRecommendMonitorModesArg
)
{
    D3DKMDT_HMONITORSOURCEMODESET               hMonitorSourceModeSet          = pRecommendMonitorModesArg->hMonitorSourceModeSet;
    CONST DXGK_MONITORSOURCEMODESET_INTERFACE*  pMonitorSourceModeSetInterface = pRecommendMonitorModesArg->pMonitorSourceModeSetInterface;
    D3DKMDT_MONITOR_SOURCE_MODE*                pMonitorSourceModeInfo         = NULL;
    NTSTATUS                                    Status                         = STATUS_SUCCESS;


    // R200 sample driver doesn't provide a set of modes for a monitor allowing OS to use a default one. 
    // NOTE: Production driver may provide appropriate for a monitor set of modes if it wants to do that.
    // The sample code shown below may be used as an example.
/*
    // Recommend 800x600@60Hz as a preferred mode to test API.
    // This mode is not picked because it is not exposed in the target mode set.
    {
        // Create new mode.
        Status = pMonitorSourceModeSetInterface->pfnCreateNewModeInfo(hMonitorSourceModeSet, &pMonitorSourceModeInfo);

        if ( !NT_SUCCESS(Status) )
        {
            return Status;
        }

        // Populate new mode.
        {
            D3DKMDT_VIDEO_SIGNAL_INFO*  pVideoSignalInfo = &pMonitorSourceModeInfo->VideoSignalInfo;

            pMonitorSourceModeInfo->ColorBasis                            = D3DKMDT_CB_SRGB;
            pMonitorSourceModeInfo->ColorCoeffDynamicRanges.FirstChannel  = 8;
            pMonitorSourceModeInfo->ColorCoeffDynamicRanges.SecondChannel = 8;
            pMonitorSourceModeInfo->ColorCoeffDynamicRanges.ThirdChannel  = 8;
            pMonitorSourceModeInfo->ColorCoeffDynamicRanges.FourthChannel = 0;
            pMonitorSourceModeInfo->Preference                            = D3DKMDT_MP_PREFERRED;

            pVideoSignalInfo->ActiveSize.cx         = 800;
            pVideoSignalInfo->ActiveSize.cy         = 600;
            pVideoSignalInfo->TotalSize.cx          = 1056;
            pVideoSignalInfo->TotalSize.cy          = 628;
            pVideoSignalInfo->VideoStandard         = D3DKMDT_VSS_VESA_DMT;
            pVideoSignalInfo->VSyncFreq.Numerator   = 60317;                   // 60 [Hz]
            pVideoSignalInfo->VSyncFreq.Denominator = 1000;
            pVideoSignalInfo->HSyncFreq.Numerator   = 37879;                // 37.879[KHz]
            pVideoSignalInfo->HSyncFreq.Denominator = 1;
            pVideoSignalInfo->PixelRate             = 40000000;             // 40[MHz]
            pVideoSignalInfo->ScanLineOrdering      = D3DDDI_VSSLO_PROGRESSIVE;
        }

        // Add new mode.
        Status = pMonitorSourceModeSetInterface->pfnAddMode(hMonitorSourceModeSet, pMonitorSourceModeInfo);

        if ( !NT_SUCCESS(Status) )
        {
            return Status;
        }
    }
*/


    return STATUS_SUCCESS;
}

NTSTATUS
D3DDDIRecommendVidPnTopology
(
    HANDLE                                 hAdapter,
    CONST DXGKARG_RECOMMENDVIDPNTOPOLOGY*  pRecommendVidPnTopologyArg
)
{

    return STATUS_GRAPHICS_NO_RECOMMENDED_VIDPN_TOPOLOGY;
}



NTSTATUS
D3DDDICreateDevice(
    VOID                       *InterfaceContext,
    DXGKARG_CREATEDEVICE   *pDDICDD)
{
    PHW_DEVICE_EXTENSION        pAdapter;
    R2D3DDevice                *pR2D3DDev;

    //
    // Get the adapter
    //
    pAdapter  = ((PHW_DEVICE_EXTENSION*)InterfaceContext)[0];



    //
    // Allocation memory for the new D3D device, non-paged because it is used in Submit
    //
    pR2D3DDev = ExAllocatePoolWithTag(NonPagedPool,
                                      sizeof(R2D3DDevice),
                                      'R2DV');
    if (! pR2D3DDev)
    {
        return (STATUS_NO_MEMORY);
    }
    memset(pR2D3DDev, 0, sizeof(R2D3DDevice));

    //
    // Set up the D3D device
    //
    pR2D3DDev->hDevice  = pDDICDD->hDevice;
    pR2D3DDev->pAdapter = pAdapter;


    pDDICDD->hDevice = pR2D3DDev;

    return (STATUS_SUCCESS);
}


NTSTATUS
D3DDDIDestroyDevice(
    HANDLE  hDevice)
{

    ExFreePool(hDevice);

    return (STATUS_SUCCESS);
}

NTSTATUS 
D3DDDICreateContext(
    IN_CONST_HANDLE                 hDevice,
    INOUT_PDXGKARG_CREATECONTEXT    pCreateContext)
{
    PR2D3DDevice    pR2D3DDev = (PR2D3DDevice)hDevice;    
    PR2D3DContext   pR2D3DContext;    

    //
    // NOTE :
    // The R200 driver pretends to the OS that it uses two separate independent ring buffers one for 3d and
    // one for video, but the driver really puts them both in the same ring buffer.  This was done to simplify 
    // the task of testing the OS changes, a production driver should not do this.
    //

    // Check node is valid
    if (pCreateContext->NodeOrdinal >= MULTI_ENGINE_COUNT)
    {
        return STATUS_INVALID_PARAMETER;
    }
    
    // Allocated memory for context, non-paged because it is used in Submit
    pR2D3DContext = ExAllocatePoolWithTag(NonPagedPool, sizeof(R2D3DContext), 'R2CX');
    if (pR2D3DContext == NULL)
    {
        return STATUS_NO_MEMORY;
    }

    // At the moment dxgkrnl calls us with a NULL hDevice for the paging node
    // This will change soon but until it does we need to protect against it
    if (pR2D3DDev != NULL)
    {
        //
        // Decide DMA buffer segment and size
        // NOTE: DmaBufferSegment is a bitmask of supported segments
        //
        if (R200AGPEnabled(pR2D3DDev->pAdapter))
        {
            pCreateContext->ContextInfo.DmaBufferSegmentSet = (1 << (pR2D3DDev->pAdapter->ulAGPSegID-1));
        }
        else
        {
            //
            // Use DMA buffer in contiguous physical memory.
            //
            pCreateContext->ContextInfo.DmaBufferSegmentSet = 0;
        }


        pCreateContext->ContextInfo.DmaBufferSize = DMABUF_SIZE;
        pCreateContext->ContextInfo.AllocationListSize  = 3*ONE_K;
        pCreateContext->ContextInfo.PatchLocationListSize = pCreateContext->ContextInfo.AllocationListSize;


        //
        // The R200 driver doesn't use the driver private data structure
        // associated with each DMA buffer.
        //
        pCreateContext->ContextInfo.DmaBufferPrivateDataSize = sizeof(R200_DMA_PRIVATEDATA);
    }
        
    pR2D3DContext->dwEngineID = pCreateContext->NodeOrdinal;
    pR2D3DContext->pDevice = pR2D3DDev;
    pCreateContext->hContext = (HANDLE)pR2D3DContext;

    // Keep a count of Video engine contexts as we have to handle Preempt DDI differently if 
    // there is any possibility there may be 3D engine and Video engine packets to be pre-empted
    if (pR2D3DContext->dwEngineID == MULTI_ENGINE_NODE_VIDEO)
    {
        InterlockedIncrement(&pR2D3DDev->pAdapter->dwVideoEngineContextCo);
    }


    return STATUS_SUCCESS;
}

NTSTATUS 
D3DDDIDestroyContext(
    IN_CONST_HANDLE     hContext
    )
{
    PR2D3DContext   psContext=(PR2D3DContext)hContext;

    if (psContext->dwEngineID == MULTI_ENGINE_NODE_VIDEO)
    {
        InterlockedDecrement(&psContext->pDevice->pAdapter->dwVideoEngineContextCo);
    }

    
    ExFreePool(hContext);

    return STATUS_SUCCESS;
}



//#define DMALOGSIZE  0x400000
#if DMALOGSIZE
static BYTE DMALog[DMALOGSIZE]={0};
static BOOL DMALogWrapped = FALSE;
static UINT DMALogStop = 0;
#endif

//
// NOTE: From the original QS code, the length of DMA buffer has to be QWORD
//       aligned, this can cause an interesting problem when DMA buffer is
//       not split on a QWORD boundary, it seems to require that a NOP has
//       to be patched into the DMA buffer and the original instruction saved
//       in some kind of context; special care has to be taken for the end of
//       the DMA buffer, even if the size of the whole DMA buffer is QWORD
//       aligned, the last part of it for execution may not be.
//
NTSTATUS
D3DDDIPatchDmaBuffer(
    VOID                          *InterfaceContext,
    CONST DXGKARG_PATCH       *pDDIPatchData)
{
    HW_DEVICE_EXTENSION            *pAdapter;
    UINT                            i;
    PR200_DMA_PRIVATEDATA           pDmaPrivateData;
#if DMALOGSIZE
    UINT SubmissionSize = 0;
#endif // DMALOGSIZE

    //
    // Ignore Patch called on paging buffer, we have nothing to patch for them.
    //

    if (pDDIPatchData->Flags.Paging)
    {
        return STATUS_SUCCESS;
    }


    //
    // Get private DMA buffer data, and check if we want to break into the debugger
    //
    pDmaPrivateData=(PR200_DMA_PRIVATEDATA)pDDIPatchData->pDmaBufferPrivateData;
    ASSERT(pDmaPrivateData == NULL || (pDDIPatchData->DmaBufferPrivateDataSize == sizeof(R200_DMA_PRIVATEDATA)));
    if (pDmaPrivateData != NULL && pDmaPrivateData->bBreakOnSubmit == TRUE)
    {
        DBG_BREAK;
    }

    //
    // Get the adapter pointer
    //
    pAdapter  = ((PHW_DEVICE_EXTENSION*)InterfaceContext)[0];

    for (i = pDDIPatchData->PatchLocationListSubmissionStart;
         i < pDDIPatchData->PatchLocationListSubmissionLength;
         i++)
    {
        //
        // Check that resource item is a patch rather than a deselected resouce item
        //
        if (pDDIPatchData->pPatchLocationList[i].DriverId != RESITEM_RELEASED)
        {
            //
            // Patch the physical address for this allocation
            //
            R200PatchPhysicalAddress(pAdapter, pDDIPatchData->pDmaBuffer, &pDDIPatchData->pAllocationList[pDDIPatchData->pPatchLocationList[i].AllocationIndex], &pDDIPatchData->pPatchLocationList[i]);
        }
    }

#if DMALOGSIZE
    SubmissionSize = pDDIPatchData->DmaBufferSubmissionEndOffset -
                     pDDIPatchData->DmaBufferSubmissionStartOffset;
    if (DMALogStop + SubmissionSize >= DMALOGSIZE)
    {
        //erase old log
        memset(&DMALog[DMALogStop], 0, DMALOGSIZE - DMALogStop);
        DMALogStop = 0;
        DMALogWrapped = TRUE;
    }

    ASSERT(DMALogStop + SubmissionSize < DMALOGSIZE);

    memcpy(&DMALog[DMALogStop], (PBYTE)pDDIPatchData->pDmaBuffer + pDDIPatchData->DmaBufferSubmissionStartOffset, SubmissionSize);
    DMALogStop += SubmissionSize;
#endif

    return (STATUS_SUCCESS);
}


NTSTATUS D3DDDIPreemptCommand(HANDLE hAdapter, CONST DXGKARG_PREEMPTCOMMAND* pDDIPCData)
{
    HW_DEVICE_EXTENSION     *pAdapter;
    QS_PARAM                qsParam;
    DWORD                   dwCurRbPatchOff;
    DWORD                   dwPreemptCmdOff;
    PDWORD                  pdwRBBase;
    DWORD                   dwRBSizeInDWords;
    DWORD                   dwCurRbReadOff;
    DWORD                   dwNopSize;


    // Get the adapter
    pAdapter = ((PHW_DEVICE_EXTENSION*)hAdapter)[0];


    // Get ring buffer info
    QsGetRBInfo(pAdapter->pQs, &pdwRBBase, &dwRBSizeInDWords, &dwPreemptCmdOff);

    // This routine relies on the fact that the ring buffer is a power of two DWORDs in size
    ASSERT(IsPowerOfTwo(dwRBSizeInDWords));

    // Read current HW RB ROff
    dwCurRbReadOff = *(volatile DWORD *)(((DWORD *)pAdapter->pvMmr) + mmCP_RB_RPTR);

    // Place Preempt fence and interupt cmd in RB
    memset(&qsParam, 0, sizeof(QS_PARAM));
    qsParam.dwSize  = sizeof(QS_PARAM);
    qsParam.lTimeStamp.HighPart = 0;
    qsParam.lTimeStamp.LowPart  = pDDIPCData->PreemptionFenceId;
    QsSubmitPreemptCmd(pAdapter->pQs, &qsParam, MULTI_ENGINE_NODE_3D);      // This needs to be replaced with EngineID when DDI supplies it

    // If Read and Write offset are the same then we have no more packets to
    // process, so just return.  In future we may be able to not put the PreEmpt
    // command if we can return a special code to VidSch to inidctae we are done
    // see bug 999819
    if (dwCurRbReadOff == dwPreemptCmdOff)
    {
        return STATUS_SUCCESS;
    }

    // Because the R200 does not really use a separate ring buffer for video and just pretends it does 
    // to the OS then if we have different engine packets in the ring buffer then preemption is harder
    // so we will just wait for all packets to complete and not try to preempt any DMA buffers
    if (pAdapter->dwVideoEngineContextCo == 0)
    {
        // To avoid dealing with the wrap case we will shift the current read offset up by the
        // size of one ring buffer and also shift the current read offset up if needed, the result
        // is that we can subtract the offsets without worrying about ring buffer wrapping
        if (dwPreemptCmdOff > dwCurRbReadOff)
        {
            // Read offset is behind the current Write offset, so both offsets are on same ring
            // buffer wrap count so we also need to shift the read offset up by ring buffer
            dwCurRbReadOff += dwRBSizeInDWords;
        }
        else
        {
            // Read offset is one ring buffer wrap behind the write offset, in this case we do not
            // adjust the read offset
        }
        dwPreemptCmdOff += dwRBSizeInDWords;

        // Start at the rb offset where the preempt command was placed and work back
        dwCurRbPatchOff = dwPreemptCmdOff;

        // Loop through packets from last submitted packet to last packet the HW has not read
        while (TRUE)
        {
            // Move back one slot, watch out for Rb wrap case.  We know th first packet in the Rb is either
            // at offset 0x10 or 0x20 (this alternates with each wrap)
            if (dwCurRbPatchOff != dwRBSizeInDWords + 0x10 && dwCurRbPatchOff != dwRBSizeInDWords + 0x20)
            {
                // No wrap so easy
                dwCurRbPatchOff -= RBCMD_SIZE_INDWORDS;
            }
            else
            {
                //
                // Previous packet wrapped, so we know that when we wrap the Rb code add 0x10 DWORDs
                // to the effective packet size,
                //
                dwCurRbPatchOff -= RBCMD_SIZE_INDWORDS + 0x10;
            }

            // Check we have not gone back past the hw Read offset
            if (dwCurRbPatchOff < dwCurRbReadOff)
            {
                // Finished NOPing packets
                break;
            }

            // Calc number of DWORD's so jump from current write offset to Preempt packet
            dwNopSize = dwPreemptCmdOff-dwCurRbPatchOff;

            //Nop current packet
            *(pdwRBBase + (dwCurRbPatchOff & (dwRBSizeInDWords-1))) = PM4_PACKET3_NOP | ((dwNopSize - 2) << 16);
        }
    }
   
    return STATUS_SUCCESS;
}



NTSTATUS
D3DDDISubmitCommand(
    VOID                               *pKmdContext,
    CONST DXGKARG_SUBMITCOMMAND    *pDDISCData)
{
    HW_DEVICE_EXTENSION                *pAdapter;
    QS_PARAM                            qsParam;
    ULONGLONG                          *pPhyAddr;
    ULONGLONG                           PhyAddr;
    PR200_DMA_PRIVATEDATA               pDmaPrivateData;
    DWORD                               dwOldRBOffset;         //Stored as DWORD count
    DWORD                               dwNewRBOffset;         //Stored as DWORD count
    PR2D3DContext                       pR2D3DContext = (PR2D3DContext)pDDISCData->hContext;

    //
    // Get private DMA buffer data, and check if we want to break into the debugger
    //
    pDmaPrivateData=(PR200_DMA_PRIVATEDATA)pDDISCData->pDmaBufferPrivateData;
    ASSERT(pDmaPrivateData == NULL || (pDDISCData->DmaBufferPrivateDataSize == sizeof(R200_DMA_PRIVATEDATA)));
    ASSERT(pDmaPrivateData == NULL || (pDmaPrivateData->Type != DMA_PACKET_TYPE_INVALID));
    if (pDmaPrivateData != NULL && pDmaPrivateData->bBreakOnSubmit == TRUE)
    {
        DBG_BREAK;
    }

    //
    // Get the adapter
    //
    pAdapter = ((PHW_DEVICE_EXTENSION*)pKmdContext)[0];


    //
    // Submit the DMA buffer using QS
    //
    memset(&qsParam, 0, sizeof(QS_PARAM));

    qsParam.dwSize  = sizeof(QS_PARAM);

    qsParam.dwFlags = QS_FLAG_SUBMIT_RING_COMMAND;
    qsParam.dwRBCmd = SUBMIT_DMA_BUFFER;

    //
    // Set up timestamp associated with the DMA buffer (from RT)
    //
    qsParam.lTimeStamp.HighPart = 0;
    qsParam.lTimeStamp.LowPart  = pDDISCData->SubmissionFenceId;

    {
        //
        // Submit HW DMA buffer to the chip
        //

        //
        // Set up the virtual address for the DMA buffer
        //
        qsParam.pList = NULL;

        //
        // Set up physical address for the DMA buffer
        //
        pPhyAddr  = (ULONGLONG *)&qsParam.padding[0];
        PhyAddr   = pDDISCData->DmaBufferPhysicalAddress.QuadPart +
                    pDDISCData->DmaBufferSubmissionStartOffset;
        if (1 == pDDISCData->DmaBufferSegmentId)
        {
            PhyAddr += pAdapter->lfbMemoryControllerAddress.QuadPart;
        }
        qsParam.dwListSize = pDDISCData->DmaBufferSubmissionEndOffset -
                             pDDISCData->DmaBufferSubmissionStartOffset;
        *pPhyAddr = PhyAddr;
    }


#if DEBUG
    dwOldRBOffset = QsGetCurRBWOffset(pAdapter->pQs);
#endif

    // Send DMA packet to the hw
    if (uQSSubmitList(pAdapter->pQs, &qsParam, pR2D3DContext != NULL ? pR2D3DContext->dwEngineID : 0) != QS_OK)
    {
        EngDebugBreak();
    }

    //
    // The Preempt routine relies on the fact the each submit packet takes
    // 128 bytes in the ring buffer
    //
    ASSERT((((dwNewRBOffset=QsGetCurRBWOffset(pAdapter->pQs)) == 0x10 || dwNewRBOffset == 0x20) && dwNewRBOffset + 0x40000 /*Rb size in DWORDs*/ - dwOldRBOffset == RBCMD_SIZE_INDWORDS + 0x10) || (dwNewRBOffset - dwOldRBOffset == RBCMD_SIZE_INDWORDS));

    return (STATUS_SUCCESS);
}

typedef struct _ATI_QUERYCURRENTFENCE {
    HW_DEVICE_EXTENSION *pHwDeviceExtension;
    UINT                NodeOrdinal;
    UINT                *plCurrentFence;
} ATI_QUERYCURRENTFENCE;

BOOLEAN Ati_QueryCurrentFence(PVOID Context);

NTSTATUS
D3DDDIQueryCurrentFence(
    VOID     *pKmdContext,
    UINT     *plCurrentFence)
{
    HW_DEVICE_EXTENSION  *pAdapter;
    ATI_QUERYCURRENTFENCE AtiQueryCurrentFence;

    //
    // Get the adapter
    //
    pAdapter = ((PHW_DEVICE_EXTENSION*)pKmdContext)[0];

    //
    // Raise irql to interrupt level to sync with interrupt callback.
    //
    AtiQueryCurrentFence.pHwDeviceExtension = pAdapter;
    AtiQueryCurrentFence.plCurrentFence = plCurrentFence;
    AtiQueryCurrentFence.NodeOrdinal = MULTI_ENGINE_NODE_3D;    // This needs to be replaced with EngineID when DDI supplies it
    if (DlSynchronizeExecution(pAdapter->DeviceHandle,
                               VpHighPriority,
                               Ati_QueryCurrentFence,
                               (PVOID) &AtiQueryCurrentFence,
                               0)) // MSI Message Number
    {
        return STATUS_SUCCESS;
    }
    else
    {
        return STATUS_UNSUCCESSFUL;
    }
}

NTSTATUS
D3DDDIControlInterrupt(
    VOID                      *pKmdContext,
    CONST DXGK_INTERRUPT_TYPE  InterruptType,
    BOOLEAN                    EnableInterrupt)
{
    NTSTATUS Status;
    HW_DEVICE_EXTENSION  *pAdapter;

    //
    // Get the adapter
    //
    pAdapter = ((PHW_DEVICE_EXTENSION*)pKmdContext)[0];

    switch (InterruptType)
    {
    case DXGK_INTERRUPT_CRTC_VSYNC:

        if (EnableInterrupt)
        {
            AtiVSyncInterrupt_enable(pAdapter);
        }
        else
        {
            AtiVSyncInterrupt_disable(pAdapter);
        }

        Status = STATUS_SUCCESS;
        break;

    default:

        Status = STATUS_NOT_IMPLEMENTED;
        break;
    }

    return Status;
}

NTSTATUS
D3DDDIBuildPagingBuffer(
    HANDLE                          hAdapter,
    DXGKARG_BUILDPAGINGBUFFER  *pParam)
{
    HW_DEVICE_EXTENSION            *pAdapter;
    R2AllocationInfo               *pAllocInfo;
    DWORD                           dwMCOffsetSrc;
    DWORD                           dwMCOffsetDst;
    DWORD                          *pDMABuf;
    DWORD                           dwNbPages;
    DWORD                           dwDmaSizeLeft = pParam->DmaSize;
    PMDL                            pSrcMdl;
    PPFN_NUMBER                     pSrcPfn;
    PMDL                            pDstMdl;
    PPFN_NUMBER                     pDstPfn;
    DWORD                           i;
    DWORD                           dwSrcTileCtl = 0;
    DWORD                           dwDstTileCtl = 0;
    DWORD                           dw2dBltFmt;
    DWORD                           dwPitch;
    DWORD                           dwWidth;
    DWORD                           dwHeight;
    BOOL                            bPerformRectangularCopy = FALSE;


   //
   //Sample driver only supports DXGK_OPERATION_TRANSFER
   //Production driver must support all other types of memory operations specified in WDK documentation
   //
    if (DXGK_OPERATION_TRANSFER != pParam->Operation)
    {
        return STATUS_SUCCESS;
    }

    //
    // Get the adapter
    //
    pAdapter  = ((PHW_DEVICE_EXTENSION*)hAdapter)[0];


    //
    // Get the driver allocation info
    //
    pAllocInfo = (R2AllocationInfo *)pParam->Transfer.hAllocation;

    //
    // Ignore notification for which we don't have to transfer anything.
    //

    if (pParam->Transfer.TransferSize == 0)
    {
        return STATUS_SUCCESS;
    }

    //
    // Decide if we should use Rectangular or Linear copy, if surface is tiled we
    // have to do a rectangular blit.
    // If posible we want to do a rectangular copy becuase it is likely to reduce
    // the ammount of data required, this is not currently done see bug 999576
    //
    if (pParam->Transfer.Flags.Swizzle || pParam->Transfer.Flags.Unswizzle)
    {
        DWORD   dwTileCtl = 0;

        // Until we support swizzled mipmaps we cannot handle them here
        if ((pAllocInfo->dwCaps & DDSCAPS_MIPMAP) == 0)
        {
            // Ok rectangular copy it is
            bPerformRectangularCopy = TRUE;

            // Is surface macro tiled
            if ((pAllocInfo->dwFlags & HSL_SURF_IS_TILED) != 0)
            {
                dwTileCtl = 1;
            }

            // Is surface micro tiled
            if ((pAllocInfo->dwFlags & HSL_SURF_IS_MICROTILED) != 0)
            {
                dwTileCtl |= 2;
            }

            // Are we being asked to transfer swizzeled (tiled) data from FB to AGP/sysmem
            // and unswiddle it
            if (pParam->Transfer.Flags.Unswizzle)
            {
                // Yes we are, so source is tiled
                dwSrcTileCtl = dwTileCtl;
            }
            // No, are being asked to tranfer unswiddled data from AGP/sysmem
            // into FB and swizzling the data on the way
            else if (pParam->Transfer.Flags.Swizzle)
            {
                // Yes dest is tiled
                dwDstTileCtl = dwTileCtl;
            }

            // Rectangular surface copy so we will use the surface X, Y and pitch
            dwPitch  = pAllocInfo->hslSurfDesc.lPitch;
            dwWidth  = pAllocInfo->hslSurfDesc.dwWidth;
            dwHeight = pAllocInfo->hslSurfDesc.dwHeight;

            // Calc 2D blit format we need to use
            switch (pAllocInfo->hslSurfDesc.dwBPP)
            {
                case 8 :
                    dw2dBltFmt = DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__8BPP_CLUT | DP_GUI_MASTER_CNTL__GMC_SRC_DATATYPE__SAME_AS_DST;
                    break;

                case 16 :
                    dw2dBltFmt = DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__16BPP_565 | DP_GUI_MASTER_CNTL__GMC_SRC_DATATYPE__SAME_AS_DST;
                    break;

                case 32 :
                    dw2dBltFmt = DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__32BPP_8888 | DP_GUI_MASTER_CNTL__GMC_SRC_DATATYPE__SAME_AS_DST;
                    break;

                default :
                    // Not sure of the format, best we can do is use a linear copy,if surface is tiled it will be wrong!
                    DBG_BREAK;
                    bPerformRectangularCopy = FALSE;
            }
        }
        else
        {
            // When buildpaging buffer is called to transfer a multi-level surface (eg MipMap) all
            // levels must be sizzled/deswizzled at the same time, this sample driver currently does
            // not support this, in this sample driver the user mode driver does not allow any lockable
            // MipMap surfaces to be swizzled.  For performance reasons a production driver may want to
            // support sizzling for lockable multi-level surfaces
            EngDebugBreak();         
        }
    }

    // Are we doing a linear copy
    if (bPerformRectangularCopy == FALSE)
    {
        dwPitch  = PAGE_SIZE;
        dwWidth  = PAGE_SIZE >> 2;
        dwHeight = (DWORD)pParam->Transfer.TransferSize/PAGE_SIZE;
        dw2dBltFmt = DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__32BPP_8888 | DP_GUI_MASTER_CNTL__GMC_SRC_DATATYPE__SAME_AS_DST;
    }

    //
    // Check if MDL is used for either source or destination and if so
    // go through the slow PAGE copy path.
    //
    if ((0 == pParam->Transfer.Source.SegmentId) ||
        (0 == pParam->Transfer.Destination.SegmentId))
    {
        //
        // Either the source or the destination is described by an MDL. We'll
        // need to do the transfer one page at a time.
        //

        //
        // Calculate the total number of pages we will need to transfer.
        //

        dwNbPages = (DWORD)pParam->Transfer.TransferSize / PAGE_SIZE;

        //
        // Setup the MDL/PFN information for the source and destination (one may
        // not be used.
        //

        pSrcMdl = pParam->Transfer.Source.pMdl;
        pSrcPfn = (PPFN_NUMBER)(pSrcMdl+1);
        pDstMdl = pParam->Transfer.Destination.pMdl;
        pDstPfn = (PPFN_NUMBER)(pDstMdl+1);

        //
        // Loop generating the blit token for each page to transfer.
        // Note that we may run out of DMA buffer during the loop.
        // In that case we will return an error and ask for more DMA buffer
        // space. When this occurs we don't want to transfer the pages we've
        // transfered. For this purpose, the dxg kernel will initialize
        // MultipassOffset to 0 for the first time we are called for this
        // particular blit operation and will leave it untouched as it calls
        // us with successive DMA buffer to fill in. We will use this
        // MultipassOffset field to save the page where we left off in each
        // successive pass.
        //

        ASSERT(pParam->MultipassOffset<dwNbPages);
        for (i = pParam->MultipassOffset; i < dwNbPages; i++)
        {
            //
            // Check to see if there is enough space for one blit.
            //

            if (dwDmaSizeLeft < (4 + SUBMIT_2D_BLT_SIZE)*sizeof(DWORD))
            {
                //
                // We will need more DMA buffer space to complete the operation.
                // Store our current location in MultipassOffset so we can
                // continue from where we are on the next pass.
                //
                pParam->MultipassOffset = i;
                return STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER;
            }
            dwDmaSizeLeft -= (4 + SUBMIT_2D_BLT_SIZE)*sizeof(DWORD);

            //
            // Setup the source.
            //

            if (0 == pParam->Transfer.Source.SegmentId)
            {
                dwMCOffsetSrc = (DWORD)pSrcPfn[i] << PAGE_SHIFT;
            }
            else
            {
                dwMCOffsetSrc = pParam->Transfer.Source.SegmentAddress.LowPart +
                                pParam->Transfer.TransferOffset +
                                i*PAGE_SIZE;
                if (pAdapter->ulFBSegID == pParam->Transfer.Source.SegmentId ||
                    pAdapter->ulDXVASegID == pParam->Transfer.Source.SegmentId)
                {
                    //Sorce is in FB
                    ASSERT(dwMCOffsetSrc >= pAdapter->ulVRamSizeAvailable);
                    ASSERT(dwMCOffsetSrc < pAdapter->ulVRamSizeInstalled);
                    dwMCOffsetSrc += pAdapter->lfbMemoryControllerAddress.LowPart;
                }
                else
                {
                    ASSERT(pAdapter->ulAGPSegID == pParam->Transfer.Source.SegmentId);
                    ASSERT(dwMCOffsetSrc >= pAdapter->agpMemoryControllerAddress.LowPart);
                }
            }

            //
            // Setup the destination.
            //

            if (0 == pParam->Transfer.Destination.SegmentId)
            {
                dwMCOffsetDst = (DWORD)pDstPfn[i] << PAGE_SHIFT;
            }
            else
            {
                dwMCOffsetDst = pParam->Transfer.Destination.SegmentAddress.LowPart +
                                pParam->Transfer.TransferOffset +
                                i*PAGE_SIZE;
                if ((pAdapter->ulFBSegID == pParam->Transfer.Destination.SegmentId) ||
                    (pAdapter->ulDXVASegID == pParam->Transfer.Destination.SegmentId))
                {
                    // Dest is in FB
                    ASSERT(dwMCOffsetDst >= pAdapter->ulVRamSizeAvailable);
                    ASSERT(dwMCOffsetDst < pAdapter->ulVRamSizeInstalled);
                    dwMCOffsetDst += pAdapter->lfbMemoryControllerAddress.LowPart;
                }
                else
                {
                    ASSERT(pParam->Transfer.Destination.SegmentId == pAdapter->ulAGPSegID);
                    ASSERT(dwMCOffsetDst >= pAdapter->agpMemoryControllerAddress.LowPart);
                }
            }

            ASSERT(dwSrcTileCtl == 0);
            ASSERT(dwDstTileCtl == 0);

            //
            // Memory transfer is 2D operation, so 3D cache has to be flushed and freed
            //
            pDMABuf = pParam->pDmaBuffer;
            pDMABuf[0] = mmRB3D_ZCACHE_CTLSTAT;
            pDMABuf[1] = RB3D_ZCACHE_CTLSTAT__ZC_FLUSH | RB3D_ZCACHE_CTLSTAT__ZC_FREE;
            pDMABuf[2] = mmRB3D_DSTCACHE_CTLSTAT;
            pDMABuf[3] = RB3D_DSTCACHE_CTLSTAT__DC_FLUSH_MASK |
                         RB3D_DSTCACHE_CTLSTAT__DC_FREE_MASK;
            pDMABuf   += 4;

            //
            // Memory transfers are page aligned and regarded as A8R8G8B8
            // Memory offset is in the unit of 1KB and pitch is in the unite of 64bytes
            //
            pDMABuf = Submit2dBlt2(MakeAtiOffPitch(dwMCOffsetSrc >> 10, PAGE_SIZE >> 6, 0),
                              0,                         // dwSrcLeft
                              0,                         // dwSrcTop
                              MakeAtiOffPitch(dwMCOffsetDst >> 10, PAGE_SIZE >> 6, 0),
                              0,                         // dwDstLeft
                              0,                         // dwDstTop
                              PAGE_SIZE >> 2,            // dwWidth,
                              1,                         // dwHeight,
                              DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__32BPP_8888 |
                                  DP_GUI_MASTER_CNTL__GMC_SRC_DATATYPE__SAME_AS_DST,
                              0,                         // dwBltFlags
                              0,                         // dwSrcKeyColor
                              0,                         // dwDstKeyColor
                              pDMABuf);

            //
            // Update the write pointer so dxgkrnl can calculate how many byte we've
            // written into the buffer.
            //
            pParam->pDmaBuffer = pDMABuf;
        }
    }
    else
    {
        //
        // Check to see if there is enough space for one blit.
        //
        if (dwDmaSizeLeft < (4 + SUBMIT_2D_BLT_SIZE)*sizeof(DWORD))
        {
            //
            // We will need more DMA buffer space to complete the operation.
            //
            return STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER;
        }

        //
        // Convert offset to physical address if src is in local video memory
        //
        dwMCOffsetSrc = pParam->Transfer.Source.SegmentAddress.LowPart +
                        pParam->Transfer.TransferOffset;
        if ((pAdapter->ulFBSegID == pParam->Transfer.Source.SegmentId) ||
            (pAdapter->ulDXVASegID == pParam->Transfer.Source.SegmentId))
        {
            // Source in FB
            ASSERT(dwMCOffsetSrc >= pAdapter->ulVRamSizeAvailable);
            ASSERT(dwMCOffsetSrc < pAdapter->ulVRamSizeInstalled);
            dwMCOffsetSrc += pAdapter->lfbMemoryControllerAddress.LowPart;
        }
        else
        {
            ASSERT(pAdapter->ulAGPSegID == pParam->Transfer.Source.SegmentId);
            ASSERT(dwMCOffsetSrc >= pAdapter->agpMemoryControllerAddress.LowPart);
        }

        //
        // Convert offset to physical address if dst is in local video memory
        //
        dwMCOffsetDst = pParam->Transfer.Destination.SegmentAddress.LowPart +
                        pParam->Transfer.TransferOffset;
        if ((pAdapter->ulFBSegID == pParam->Transfer.Destination.SegmentId) ||
            (pAdapter->ulDXVASegID == pParam->Transfer.Destination.SegmentId))
        {
            // Dest in FB
            ASSERT(dwMCOffsetDst >= pAdapter->ulVRamSizeAvailable);
            ASSERT(dwMCOffsetDst < pAdapter->ulVRamSizeInstalled);
            dwMCOffsetDst += pAdapter->lfbMemoryControllerAddress.LowPart;
        }
        else
        {
            ASSERT(pAdapter->ulAGPSegID == pParam->Transfer.Destination.SegmentId);
            ASSERT(dwMCOffsetDst >= pAdapter->agpMemoryControllerAddress.LowPart);
        }

        //
        // Memory transfer is 2D operation, so 3D cache has to be flushed and freed
        //
        pDMABuf = pParam->pDmaBuffer;
        pDMABuf[0] = mmRB3D_ZCACHE_CTLSTAT;
        pDMABuf[1] = RB3D_ZCACHE_CTLSTAT__ZC_FLUSH | RB3D_ZCACHE_CTLSTAT__ZC_FREE;
        pDMABuf[2] = mmRB3D_DSTCACHE_CTLSTAT;
        pDMABuf[3] = RB3D_DSTCACHE_CTLSTAT__DC_FLUSH_MASK |
                     RB3D_DSTCACHE_CTLSTAT__DC_FREE_MASK;
        pDMABuf   += 4;

        //
        // Memory transfers are page aligned and regarded as A8R8G8B8
        // Memory offset is in the unit of 1KB and pitch is in the unite of 64bytes
        //
        pDMABuf = Submit2dBlt2(MakeAtiOffPitch(dwMCOffsetSrc >> 10, dwPitch >> 6, dwSrcTileCtl),
                          0,                         // dwSrcLeft
                          0,                         // dwSrcTop
                          MakeAtiOffPitch(dwMCOffsetDst >> 10, dwPitch >> 6, dwDstTileCtl),
                          0,                         // dwDstLeft
                          0,                         // dwDstTop
                          dwWidth,                   // dwWidth,
                          dwHeight,                  // dwHeight,
                          dw2dBltFmt,                // dwFormat
                          0,                         // dwBltFlags
                          0,                         // dwSrcKeyColor
                          0,                         // dwDstKeyColor
                          pDMABuf);

        //
        // Update the write pointer so dxgkrnl can calculate how many byte we've
        // written into the buffer.
        //
        pParam->pDmaBuffer = pDMABuf;
    }

    return STATUS_SUCCESS;
}

//
// Convert enumerated GUI bitmap format
//

__inline DWORD
ColorMaskFromGUIFormat(
    DWORD   dwFormat)
{
    register rval=0;

    switch (dwFormat & DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE_MASK )
    {
    case DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__8BPP_CLUT:    // 8 bit rgb mask
        rval = 0xFF;
        break;
    case DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__16BPP_1555:   // 15 bit rgb mask
        rval = 0x7FFF;
        break;
    case DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__16BPP_565:    // 16 bit rgb mask
        rval = 0xFFFF;
        break;
    case DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__32BPP_8888:   // 32 bit rgb mask
        rval = 0x00FFFFFF;
        break;
    default:
        rval = 0xFFFFFFFF;
        break;
    }

    return rval;
}


// Use 2D engine to move data
LPDWORD
Submit2dBlt2(
    DWORD   dwSrcOffPtch,
    DWORD   dwSrcLeft,
    DWORD   dwSrcTop,
    DWORD   dwDstOffPtch,
    DWORD   dwDstLeft,
    DWORD   dwDstTop,
    DWORD   dwWidth,
    DWORD   dwHeight,
    DWORD   dwFormat,
    DWORD   dwBltFlags,
    DWORD   dwSrcKeyColor,
    DWORD   dwDstKeyColor,
    DWORD  *PM4Entries)
{

    //
    // Use Type 0 packets because setting the tiling options does not appear to work
    // with Type3 packet
    //
    PM4Entries[0]  = MakeRegWriteConsec(mmDP_GUI_MASTER_CNTL, 1);
    PM4Entries[1]  = DP_GUI_MASTER_CNTL__GMC_SRC_PITCH_OFFSET_CNTL |
                     DP_GUI_MASTER_CNTL__GMC_DST_PITCH_OFFSET_CNTL |
                     DP_GUI_MASTER_CNTL__GMC_SRC_CLIPPING |
                     DP_GUI_MASTER_CNTL__GMC_DST_CLIPPING |
                     DP_GUI_MASTER_CNTL__GMC_BRUSH_DATATYPE__SOLID_COLOR_RESERVED |
                     dwFormat |
                     DP_GUI_MASTER_CNTL__GMC_ROP3__SRCCPY |
                     DP_GUI_MASTER_CNTL__GMC_DP_SRC_SOURCE__VIDEO_MEM |
                     DP_GUI_MASTER_CNTL__GMC_CLR_CMP_FCN_DIS |
                     DP_GUI_MASTER_CNTL__GMC_WR_MSK_DIS;                    // DP_GUI_MCNTL

    PM4Entries[2]  = MakeRegWriteConsec(mmDST_OFFSET, 2);
    PM4Entries[3]  = ((dwDstOffPtch & DST_PITCH_OFFSET__DST_OFFSET_MASK) >> DST_PITCH_OFFSET__DST_OFFSET__SHIFT) << 10;                                    // DST_OFFSET
    PM4Entries[4]  = ((dwDstOffPtch & DST_PITCH_OFFSET__DST_PITCH_MASK) >> DST_PITCH_OFFSET__DST_PITCH__SHIFT) << 6;;                                        // DST_PITCH

    PM4Entries[5]  = MakeRegWriteConsec(mmSRC_OFFSET, 2);
    PM4Entries[6]  = ((dwSrcOffPtch & DST_PITCH_OFFSET__DST_OFFSET_MASK) >> DST_PITCH_OFFSET__DST_OFFSET__SHIFT) << 10;;                                    // SRC_OFFSET
    PM4Entries[7]  = ((dwSrcOffPtch & DST_PITCH_OFFSET__DST_PITCH_MASK) >> DST_PITCH_OFFSET__DST_PITCH__SHIFT) << 6;                                        // SRC_PITCH

    PM4Entries[8]  = MakeRegWriteConsec(mmDP_DST_ENDIAN, 2);
    PM4Entries[9]  = 0;                                                     // DP_DST_ENDIAN
    PM4Entries[10] = 0;                                                     // DP_SRC_ENDIAN

    PM4Entries[11] = MakeRegWriteConsec(mmDP_CNTL_XDIR_YDIR_YMAJOR, 1);
    PM4Entries[12] = DP_CNTL_XDIR_YDIR_YMAJOR__DST_X_DIR | DP_CNTL_XDIR_YDIR_YMAJOR__DST_Y_DIR;

    PM4Entries[13] = MakeRegWriteConsec(mmSC_TOP_LEFT, 3);
    PM4Entries[14] = 0x00000000;                                            // SC_TOP_LEFT
    PM4Entries[15] = ((dwDstTop+dwHeight) << 16) | (dwDstLeft+dwWidth);     // SC_BOTTOM_RIGHT
    PM4Entries[16] = ((dwSrcTop + dwHeight) << 16) | (dwSrcLeft + dwWidth);;     // SRC_SC_BOTTOM_RIGHT

    PM4Entries[17] = MakeRegWriteConsec(mmDST_TILE, 2);
    PM4Entries[18] = (dwDstOffPtch & DST_PITCH_OFFSET__DST_TILE_MASK) >> DST_PITCH_OFFSET__DST_TILE__SHIFT; // DST_TILE
    PM4Entries[19] = (dwSrcOffPtch & DST_PITCH_OFFSET__DST_TILE_MASK) >> DST_PITCH_OFFSET__DST_TILE__SHIFT; // SRC_TILE

    PM4Entries[20] = MakeRegWriteConsec(mmCLR_CMP_CNTL, 4);
    PM4Entries[21] = 0;                                                   // CLR_CMP_CNTL
    PM4Entries[22] = dwSrcKeyColor;                                         // CLR_CMP_CLR_SRC
    PM4Entries[23] = dwDstKeyColor;                                         // CLR_CMP_CLR_DST
    PM4Entries[24] = ColorMaskFromGUIFormat(dwFormat);                    // CLR_CMP_MSK

    PM4Entries[25] = MakeRegWriteConsec(mmSRC_X_Y, 3);
    PM4Entries[26] = (dwSrcLeft << 16) | (dwSrcTop);                             // SRC_X_Y
    PM4Entries[27] = (dwDstLeft << 16) | (dwDstTop);                            // DST_X_Y
    PM4Entries[28] = (dwWidth << 16) | (dwHeight);                              // DST_WIDTH_HEIGHT (initiator)

    PM4Entries+=29;

    return PM4Entries;
}



//
// Called by interrupt handler to notify the DMA interrupt
//
NTSTATUS
D3DDDINotifyDMAInterrupt(
    HW_DEVICE_EXTENSION                *pAdapter)
{
    DXGKRNL_INTERFACE                     *pCallback;
    DXGKCB_NOTIFY_INTERRUPT                VidSchNotifyInt;
    DXGKARGCB_NOTIFY_INTERRUPT_DATA    notifyInt = {0};
    ULONG                                  NewPreemptFenceID;
    ULONG                                  NewSubmitFenceID;
    UINT                                   EngineIdx;
    NTSTATUS                               Status=STATUS_SUCCESS;


    pCallback = &(pAdapter->ddiCallback);

    if (! pAdapter->pVidSchINTCB)
    {
        return (STATUS_SUCCESS);
    }

    VidSchNotifyInt = (DXGKCB_NOTIFY_INTERRUPT)pAdapter->pVidSchINTCB;


    for (EngineIdx = 0; EngineIdx < MULTI_ENGINE_COUNT; EngineIdx++)


    {
        //
        // Read the timestamp back from the chip
        //
        NewSubmitFenceID  = *(volatile ULONG *)(((DWORD *)pAdapter->pvMmr) + mmGUI_SCRATCH_REG0 + (EngineIdx * 2));
        NewPreemptFenceID = *(volatile ULONG *)(((DWORD *)pAdapter->pvMmr) + mmGUI_SCRATCH_REG4 + (EngineIdx * 2));


        // Check if we have had preempt FenceID update
        if (NewPreemptFenceID != pAdapter->PrevPreemptFenceIDArray[EngineIdx])
        {
            notifyInt.InterruptType = DXGK_INTERRUPT_DMA_PREEMPTED;
            notifyInt.DmaPreempted.PreemptionFenceId    = NewPreemptFenceID;
            notifyInt.DmaPreempted.LastCompletedFenceId = NewSubmitFenceID;
            notifyInt.DmaPreempted.NodeOrdinal = EngineIdx;

            VidSchNotifyInt(pAdapter->DeviceHandle, &notifyInt);

            pAdapter->PrevPreemptFenceIDArray[EngineIdx] = NewPreemptFenceID;
            pAdapter->PrevSubmitFenceIDArray[EngineIdx]  = NewSubmitFenceID;

            // indicate caller need to queue dpc.
            Status = STATUS_MORE_PROCESSING_REQUIRED;
        } 
        else if (NewSubmitFenceID != pAdapter->PrevSubmitFenceIDArray[EngineIdx])            
        {
            // Check if we have had submit FenceID update

            notifyInt.InterruptType = DXGK_INTERRUPT_DMA_COMPLETED;
            notifyInt.DmaCompleted.SubmissionFenceId = NewSubmitFenceID;
            notifyInt.DmaCompleted.NodeOrdinal = EngineIdx;

            VidSchNotifyInt(pAdapter->DeviceHandle, &notifyInt);

            pAdapter->PrevSubmitFenceIDArray[EngineIdx] = NewSubmitFenceID;

            // indicate caller need to queue dpc.
            Status = STATUS_MORE_PROCESSING_REQUIRED;
        }
    }

    return Status;
}

NTSTATUS
D3DDDINotifyVSyncInterrupt(
    HW_DEVICE_EXTENSION                *pAdapter,
    BOOLEAN                             VSyncOnCrtc1,
    BOOLEAN                             VSyncOnCrtc2)
{
    DXGKRNL_INTERFACE                    *pCallback;
    DXGKCB_NOTIFY_INTERRUPT              VidSchNotifyInt;
    DXGKARGCB_NOTIFY_INTERRUPT_DATA  notifyInt = {0};
    DWORD CrtcOffset;

    pCallback = &(pAdapter->ddiCallback);
    if (! pAdapter->pVidSchINTCB)
    {
        return (STATUS_SUCCESS);
    }
    VidSchNotifyInt = (DXGKCB_NOTIFY_INTERRUPT)pAdapter->pVidSchINTCB;

    if (VSyncOnCrtc1)
    {
        notifyInt.InterruptType = DXGK_INTERRUPT_CRTC_VSYNC;
        notifyInt.CrtcVsync.VidPnTargetId = VIDPN_TARGET1_ID;
        CrtcOffset = *(volatile ULONG *)(((DWORD *)pAdapter->pvMmr) + mmCRTC_OFFSET);
        notifyInt.CrtcVsync.PhysicalAddress.HighPart = 0;
        notifyInt.CrtcVsync.PhysicalAddress.LowPart  = (CrtcOffset & 0x03FFFFFF);
        // ASSERT((CrtcOffset & CRTC_OFFSET__CRTC_GUI_TRIG_OFFSET) == 0);
        VidSchNotifyInt(pCallback->DeviceHandle, &notifyInt);
    }
    if (VSyncOnCrtc2)
    {
        notifyInt.InterruptType = DXGK_INTERRUPT_CRTC_VSYNC;
        notifyInt.CrtcVsync.VidPnTargetId = VIDPN_TARGET2_ID;
        CrtcOffset = *(volatile ULONG *)(((DWORD *)pAdapter->pvMmr) + mmCRTC2_OFFSET);
        notifyInt.CrtcVsync.PhysicalAddress.HighPart = 0;
        notifyInt.CrtcVsync.PhysicalAddress.LowPart  = (CrtcOffset & 0x03FFFFFF);
        // ASSERT((CrtcOffset & CRTC_OFFSET__CRTC_GUI_TRIG_OFFSET) == 0);
        VidSchNotifyInt(pCallback->DeviceHandle, &notifyInt);
    }

    return (STATUS_SUCCESS);
}

//
// Called by interrupt handler to notify the DMA/VSync interrupt
//
NTSTATUS
D3DDDINotifyDPC(
    HW_DEVICE_EXTENSION                *pAdapter)
{
    DXGKRNL_INTERFACE                    *pCallback;
    DXGKCB_NOTIFY_DPC                     VidSchNotifyDpc;

    pCallback = &(pAdapter->ddiCallback);

    if (! pAdapter->pVidSchDPCCB)
    {
        return (STATUS_SUCCESS);
    }

    VidSchNotifyDpc = (DXGKCB_NOTIFY_DPC)pAdapter->pVidSchDPCCB;

    VidSchNotifyDpc(pAdapter->DeviceHandle);

    return (STATUS_SUCCESS);
}

extern VOID
Ati_PM4Interrupt_DPC(PVOID MiniportDeviceContext, PVOID Context);

BOOLEAN
Ati_QueryCurrentFence(
    PVOID Context)
{
    ATI_QUERYCURRENTFENCE *pAtiQueryCurrentFence = (ATI_QUERYCURRENTFENCE *) Context;
    HW_DEVICE_EXTENSION *pHwDeviceExtension  = pAtiQueryCurrentFence->pHwDeviceExtension;

    //
    // Notify the GPU scheduler if we haven't reported latest fence.
    //
    if (D3DDDINotifyDMAInterrupt(pHwDeviceExtension) == STATUS_MORE_PROCESSING_REQUIRED)
    {
        //
        // And queue DPC as well for GPU scheduler callback.
        //
        DlQueueDpc(pHwDeviceExtension->DeviceHandle);
    }

    //
    // Return the fence id where driver at.
    //
    *(pAtiQueryCurrentFence->plCurrentFence) = pHwDeviceExtension->PrevSubmitFenceIDArray[pAtiQueryCurrentFence->NodeOrdinal];

    return TRUE;
}

UINT g_ScanLine = 0;

NTSTATUS
D3DDDIGetScanLine(
    VOID*                   InterfaceContext,
    DXGKARG_GETSCANLINE*    pGetScanLine)
{
    if (++g_ScanLine > 1100)
    {
        g_ScanLine = 0;
    }

    pGetScanLine->ScanLine = g_ScanLine;
    pGetScanLine->InVerticalBlank = g_ScanLine > 1024;

    return (STATUS_SUCCESS);
}

__inline BOOL
R200IsInVBlank(
    HW_DEVICE_EXTENSION    *pAdapter,
    D3DDDI_VIDEO_PRESENT_SOURCE_ID  VidPnSourceId)
{
    ULONG   ulScanline, ulVDisp;

    if (VidPnSourceId != 0)
    {
        ulScanline = ATI_INPD(pAdapter->pvMmr, mmCRTC2_VLINE_CRNT_VLINE);
        ulVDisp = ATI_INPD(pAdapter->pvMmr, mmCRTC2_V_TOTAL_DISP);
    }
    else
    {
        ulScanline = ATI_INPD(pAdapter->pvMmr, mmCRTC_VLINE_CRNT_VLINE);
        ulVDisp = ATI_INPD(pAdapter->pvMmr, mmCRTC_V_TOTAL_DISP);
    }

    ulScanline = (ulScanline &
                  CRTC_VLINE_CRNT_VLINE__CRTC_CRNT_VLINE_MASK) >>
                 CRTC_VLINE_CRNT_VLINE__CRTC_CRNT_VLINE__SHIFT;

    ulVDisp = (ulVDisp &
               CRTC_V_TOTAL_DISP__CRTC_V_DISP_MASK) >>
              CRTC_V_TOTAL_DISP__CRTC_V_DISP__SHIFT;

    //
    // Handle the line double case for lower resolution
    //
    if (ulVDisp <= 300)
    {
        ulScanline /= 2;
    }

    return (ulScanline > ulVDisp);
}

__inline void
R200ConnectVSYNC(
    HW_DEVICE_EXTENSION            *pAdapter,
    D3DDDI_VIDEO_PRESENT_SOURCE_ID  VidPnSourceId,
    BOOL                            bConnect)
{
    ULONG   ulCRTCOffsetCntl;

    //
    // Read back CRTC offset control register
    //
    if (VidPnSourceId != 0)
    {
        ulCRTCOffsetCntl = ATI_INPD(pAdapter->pvMmr, mmCRTC2_OFFSET_CNTL);
    }
    else
    {
        ulCRTCOffsetCntl = ATI_INPD(pAdapter->pvMmr, mmCRTC_OFFSET_CNTL);
    }

    //
    // Change the bit that controls if the flip is synced with VSYNC
    //
    if (bConnect)
    {
        ulCRTCOffsetCntl &= ~CRTC_OFFSET_CNTL__CRTC_OFFSET_FLIP_CNTL;
        ulCRTCOffsetCntl |= CRTC_OFFSET_CNTL__CRTC_GUI_TRIG_OFFSET_LEFT_EN;
    }
    else
    {
        ulCRTCOffsetCntl |= CRTC_OFFSET_CNTL__CRTC_OFFSET_FLIP_CNTL;
        ulCRTCOffsetCntl |= CRTC_OFFSET_CNTL__CRTC_GUI_TRIG_OFFSET_LEFT_EN;
    }

    //
    // Wait for VBlank to avoid flicking
    //
    while (! R200IsInVBlank(pAdapter, VidPnSourceId));

    //
    // Write the changed CRTC offset control register
    //
    if (VidPnSourceId != 0)
    {
        ATI_OUTPD(pAdapter->pvMmr, mmCRTC2_OFFSET_CNTL, ulCRTCOffsetCntl);
    }
    else
    {
        ATI_OUTPD(pAdapter->pvMmr, mmCRTC_OFFSET_CNTL, ulCRTCOffsetCntl);
    }

}

NTSTATUS
R200Flip(
    R2D3DDevice                    *pR2D3DDev,
    DXGKARG_PRESENT            *pDDIPresentData,
    D3DDDI_VIDEO_PRESENT_SOURCE_ID  VidPnSourceId)
{
    HW_DEVICE_EXTENSION    *pAdapter = pR2D3DDev->pAdapter;
    UINT                   *pDMABuf;
    D3DDDI_PATCHLOCATIONLIST *pPatch, *pPatchLast;
    DXGK_ALLOCATIONLIST*    pAllocationList;
    DWORD                   dwFormat;
    DWORD                   dwSrcOffsetPitch, dwDstOffsetPitch;
    ULONG                   ulCurFlipFlags, ulDifFlipFlags;

    ASSERT(VidPnSourceId < 2);

    //
    //Sample driver checks the flip flags are changed and sets the HW state accordingly.
    //Production driver should not program hardware at Present DDI.
    //Refer WDK documentation for details.
    //
    ulCurFlipFlags = (pDDIPresentData->FlipInterval == D3DDDI_FLIPINTERVAL_IMMEDIATE);
    ulDifFlipFlags = ulCurFlipFlags ^ pAdapter->ulFlipFlags[VidPnSourceId];
    if (ulDifFlipFlags)
    {
        if (ulCurFlipFlags)
        {
            R200ConnectVSYNC(pAdapter, VidPnSourceId, FALSE);
        }
        else
        {
            R200ConnectVSYNC(pAdapter, VidPnSourceId, TRUE);
        }
    }

    //
    // Remember the current flip flags
    //
    pAdapter->ulFlipFlags[VidPnSourceId] = ulCurFlipFlags;

    if (NULL == pDDIPresentData->pDmaBuffer)
    {
        return STATUS_SUCCESS;
    }

    //
    // Return next private data addr
    //
    pDDIPresentData->pDmaBufferPrivateData = (PVOID)((PBYTE)pDDIPresentData->pDmaBufferPrivateData + sizeof(R200_DMA_PRIVATEDATA));

    //
    // Set the DMA buffer and resource list pointers
    //
    pDMABuf = pDDIPresentData->pDmaBuffer;
    pPatch  = pDDIPresentData->pPatchLocationListOut;
    pAllocationList = pDDIPresentData->pAllocationList;

    //
    // The real flip path for pinned back buffers
    //
    // NOTE: It is important to CRTC_GUI_TRIG_OFFSET_LEFT_EN in
    //       the mmCRTC_OFFSET_CNTL register set, so that WAIT_UNTIL
    //       for flip works
    //
    if (VidPnSourceId != 0)
    {
        pDMABuf[0]  = mmRB3D_DSTCACHE_CTLSTAT;
        pDMABuf[1]  = RB3D_DSTCACHE_CTLSTAT__DC_FLUSH_MASK;
        pDMABuf[2]  = mmWAIT_UNTIL;
        pDMABuf[3]  = WAIT_UNTIL__WAIT_3D_IDLECLEAN | WAIT_UNTIL__WAIT_2D_IDLECLEAN;
        pDMABuf[4]  = mmCRTC2_OFFSET;
        pDMABuf[5]  = 0;                 // Patched in later

        if (pDDIPresentData->Flags.FlipWithNoWait)
        {
            //
            // Return the DMA buffer and resource list pointer to the runtime
            //
            pDDIPresentData->pDmaBuffer = pDMABuf + 6;
        }
        else
        {
            //
            // Ask the ASIC to wait for the flip to finish
            //
            pDMABuf[6]  = mmWAIT_UNTIL;
            pDMABuf[7]  = WAIT_UNTIL__ENG_DISPLAY_SELECT;
            pDMABuf[8]  = mmWAIT_UNTIL;
            pDMABuf[9]  = WAIT_UNTIL__WAIT_CRTC_PFLIP | WAIT_UNTIL__ENG_DISPLAY_SELECT;
            pDMABuf[10] = mmWAIT_UNTIL;
            pDMABuf[11] = 0;

            //
            // Return the DMA buffer and resource list pointer to the runtime
            //
            pDDIPresentData->pDmaBuffer = pDMABuf + 12;
        }
    }
    else
    {
        pDMABuf[0] = mmRB3D_DSTCACHE_CTLSTAT;
        pDMABuf[1] = RB3D_DSTCACHE_CTLSTAT__DC_FLUSH_MASK;
        pDMABuf[2] = mmWAIT_UNTIL;
        pDMABuf[3] = WAIT_UNTIL__WAIT_3D_IDLECLEAN | WAIT_UNTIL__WAIT_2D_IDLECLEAN;
        pDMABuf[4] = mmCRTC_OFFSET;
        pDMABuf[5] = 0;                 // Patched in later

        if (pDDIPresentData->Flags.FlipWithNoWait)
        {
            //
            // Return the DMA buffer and resource list pointer to the runtime
            //
            pDDIPresentData->pDmaBuffer = pDMABuf + 6;
        }
        else
        {
            //
            // Ask the ASIC to wait for the flip to finish
            //
            pDMABuf[6] = mmWAIT_UNTIL;
            pDMABuf[7] = WAIT_UNTIL__WAIT_CRTC_PFLIP;

            //
            // Return the DMA buffer and resource list pointer to the runtime
            //
            pDDIPresentData->pDmaBuffer = pDMABuf + 8;
        }
    }

    //
    // Set up the resource list to patch in the source's physical address
    //
    pPatch->AllocationIndex      = DXGK_PRESENT_SOURCE_INDEX;

    pPatch->DriverId         = mmCRTC_OFFSET;
    pPatch->SlotId           = 0;
    pPatch->AllocationOffset = 0 - pAdapter->lfbMemoryControllerAddress.LowPart;
    pPatch->PatchOffset      = 5*sizeof(DWORD);  // See command stream above

    pPatch->SplitOffset      = 0;

    if (pAllocationList[DXGK_PRESENT_SOURCE_INDEX].SegmentId != 0)
    {
        DPF(DBG_RESOURCE_LIST, "PrePatching CmdBuf 0x%08lx AllocIdx 0x%08x\n", pDMABuf+5, DXGK_PRESENT_SOURCE_INDEX);
        R200PatchPhysicalAddress(pR2D3DDev->pAdapter, pDMABuf, &pAllocationList[DXGK_PRESENT_SOURCE_INDEX], pPatch);
    }

    pDDIPresentData->pPatchLocationListOut = pPatch + 1;

    return (STATUS_SUCCESS);
}

NTSTATUS
D3DDDIDescribeAllocation(
    VOID*                       InterfaceContext,
    DXGKARG_DESCRIBEALLOCATION* pDDIDescribeAlloc)
{
    R2AllocationInfo*   pAllocInfo = (R2AllocationInfo*)pDDIDescribeAlloc->hAllocation;
    pDDIDescribeAlloc->Width = pAllocInfo->hslSurfDesc.dwWidth;
    pDDIDescribeAlloc->Height = pAllocInfo->hslSurfDesc.dwHeight;
    pDDIDescribeAlloc->RefreshRate = pAllocInfo->RefreshRate;

    if (4 == pAllocInfo->dwBytesPerPixel)
    {
        pDDIDescribeAlloc->Format = D3DDDIFMT_A8R8G8B8;
    }
    else if (3 == pAllocInfo->dwBytesPerPixel)
    {
        pDDIDescribeAlloc->Format = D3DDDIFMT_R8G8B8;
    }
    else if (2 == pAllocInfo->dwBytesPerPixel)
    {
        pDDIDescribeAlloc->Format = D3DDDIFMT_R5G6B5;
    }
    else if (1 == pAllocInfo->dwBytesPerPixel)
    {
        pDDIDescribeAlloc->Format = D3DDDIFMT_P8;
    }
    else
    {
        return STATUS_INVALID_PARAMETER;
    }

    return STATUS_SUCCESS;
}

//
// Handles primary surface/shadow buffer creation
//
#define     SURF_IS_PALETTIZED      0x00000400

NTSTATUS
D3DDDIGetStandardAllocationDriverData(
    VOID                                     *InterfaceContext,
    DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA   *pDDIGetStandardAllocationDriverData)
{
    HW_DEVICE_EXTENSION                *pAdapter;
    R2DDICreateAllocationData          *pR200CreateAllocData;
    R2AllocationInfo                   *pDrvAllocData;

    //
    // Check if caller just wants the size of the buffer we would create
    //
    if (pDDIGetStandardAllocationDriverData->pAllocationPrivateDriverData == NULL)
    {
        pDDIGetStandardAllocationDriverData->AllocationPrivateDriverDataSize = sizeof(R2DDICreateAllocationData);
        return STATUS_SUCCESS;
    }

    //
    // Get the adapter back
    //
    pAdapter = ((PHW_DEVICE_EXTENSION*)InterfaceContext)[0];

    // Get ptr to buffer to fill in
    pR200CreateAllocData = (R2DDICreateAllocationData*)pDDIGetStandardAllocationDriverData->pAllocationPrivateDriverData;
    if (pDDIGetStandardAllocationDriverData->AllocationPrivateDriverDataSize != sizeof(R2DDICreateAllocationData))
    {
        return STATUS_INVALID_PARAMETER;
    }
    pR200CreateAllocData->bStandardAllocation = TRUE;

    pDrvAllocData = &pR200CreateAllocData->sAllocInfo;
    pDrvAllocData->hslSurfDesc.lpddPixelFormat = &pDrvAllocData->ddPixelFormat;
    pDrvAllocData->VidPnSourceId = D3DDDI_ID_NOTAPPLICABLE;

    switch (pDDIGetStandardAllocationDriverData->StandardAllocationType)
    {
        case D3DKMDT_STANDARDALLOCATION_SHAREDPRIMARYSURFACE :
        {
            enum
            {
                DDSCAPS_SHAREDPRIMARYSURFACE = DDSCAPS_PRIMARYSURFACE
                                             | DDSCAPS_VIDEOMEMORY
                                             | DDSCAPS_LOCALVIDMEM
            };

            VIDEO_MODE_INFORMATION              vidModeInfo;
            NTSTATUS ntStatus;
            D3DKMDT_SHAREDPRIMARYSURFACEDATA*   pPrimSurf = pDDIGetStandardAllocationDriverData->pCreateSharedPrimarySurfaceData;
            RtlZeroMemory(&vidModeInfo, sizeof(VIDEO_MODE_INFORMATION));

            ntStatus = GetVideoModeInfo(pAdapter, pPrimSurf, &vidModeInfo);

            if ( !NT_SUCCESS(ntStatus) )
            {
                return ntStatus;
            }

            pR200CreateAllocData->CreateDataFormat = pPrimSurf->Format;

            SetupPrimarySurfaceAllocationInfo(pPrimSurf->Format,
                                              &vidModeInfo,
                                              0,              // dwPSMCAddress,
                                              DDSCAPS_SHAREDPRIMARYSURFACE,
                                              pDrvAllocData);

            // NOTE: Only shared primaries are associated with a VidPN source.
            pDrvAllocData->VidPnSourceId = pPrimSurf->VidPnSourceId;
            pDrvAllocData->RefreshRate = pPrimSurf->RefreshRate;

            if ((pDrvAllocData->ddPixelFormat.dwFlags & DDPF_PALETTEINDEXED8) != 0)
            {
                pDrvAllocData->dwFlags|=SURF_IS_PALETTIZED;
            }

            break;
        }

        case D3DKMDT_STANDARDALLOCATION_SHADOWSURFACE :
        {
            enum
            {
                DDSCAPS_SHADOWSURFACE = DDSCAPS_VIDEOMEMORY
                                      | DDSCAPS_OFFSCREENPLAIN
            };

            D3DKMDT_SHADOWSURFACEDATA*  pShadowBuf = pDDIGetStandardAllocationDriverData->pCreateShadowSurfaceData;

            switch (pShadowBuf->Format)
            {
            case D3DDDIFMT_P8:
                pDrvAllocData->dwBytesPerPixel = 1;
                pDrvAllocData->ddPixelFormat.dwFlags            = DDPF_PALETTEINDEXED8 | DDPF_RGB;
                pDrvAllocData->ddPixelFormat.dwRGBAlphaBitMask  = 0;
                pDrvAllocData->ddPixelFormat.dwRBitMask         = 0;
                pDrvAllocData->ddPixelFormat.dwGBitMask         = 0;
                pDrvAllocData->ddPixelFormat.dwBBitMask         = 0;

                break;
            case D3DDDIFMT_R5G6B5:
                pDrvAllocData->ddPixelFormat.dwFlags            = DDPF_RGB;
                pDrvAllocData->dwBytesPerPixel = 2;
                pDrvAllocData->ddPixelFormat.dwRGBAlphaBitMask  = 0;
                pDrvAllocData->ddPixelFormat.dwRBitMask         = 0x0000F800;
                pDrvAllocData->ddPixelFormat.dwGBitMask         = 0x000007E0;
                pDrvAllocData->ddPixelFormat.dwBBitMask         = 0x0000001F;
                break;
            case D3DDDIFMT_A8R8G8B8:
                pDrvAllocData->ddPixelFormat.dwFlags            = DDPF_RGB;
                pDrvAllocData->dwBytesPerPixel = 4;
                pDrvAllocData->ddPixelFormat.dwRGBAlphaBitMask  = 0xFF000000;
                pDrvAllocData->ddPixelFormat.dwRBitMask         = 0x00FF0000;
                pDrvAllocData->ddPixelFormat.dwGBitMask         = 0x0000FF00;
                pDrvAllocData->ddPixelFormat.dwBBitMask         = 0x000000FF;
                break;
            default:
                return STATUS_INVALID_PARAMETER;
            }

            pR200CreateAllocData->CreateDataFormat = pShadowBuf->Format;

            pDrvAllocData->dwPitch         = pShadowBuf->Width * pDrvAllocData->dwBytesPerPixel;

            pDrvAllocData->dwPitchAlign    = 0x80;
            pDrvAllocData->dwHeight        = pShadowBuf->Height;
            pDrvAllocData->dwHeightAlign   = 1;
            pDrvAllocData->dwOffsetAlign   = PAGE_SIZE;

            pDrvAllocData->dwCaps   = DDSCAPS_VIDEOMEMORY | DDSCAPS_OFFSCREENPLAIN;

            pDrvAllocData->hslSurfDesc.dwBPP    = pDrvAllocData->dwBytesPerPixel * 8;
            pDrvAllocData->hslSurfDesc.dwWidth  = pShadowBuf->Width;
            pDrvAllocData->hslSurfDesc.dwHeight = pDrvAllocData->dwHeight;
            pDrvAllocData->hslSurfDesc.lPitch   = ByteAlign(pDrvAllocData->dwPitch,
                                                  pDrvAllocData->dwPitchAlign);

            //driver must output it back if it's D3DKMDT_SHADOWSURFACEDATA
            pShadowBuf->Pitch = pDrvAllocData->hslSurfDesc.lPitch;

            pDrvAllocData->ddPixelFormat.dwSize        = sizeof(DDPIXELFORMAT);
            pDrvAllocData->ddPixelFormat.dwRGBBitCount = pDrvAllocData->hslSurfDesc.dwBPP;

            if (R200AGPEnabled(pAdapter))
            {
                pDrvAllocData->dwHeap  = 1;
                pDrvAllocData->dwCaps |= DDSCAPS_NONLOCALVIDMEM;
            }
            else
            {
                pDrvAllocData->dwHeap  = 0;
                pDrvAllocData->dwCaps |= DDSCAPS_LOCALVIDMEM;
            }

            break;
        }

        case D3DKMDT_STANDARDALLOCATION_STAGINGSURFACE :
        {
            D3DKMDT_STAGINGSURFACEDATA* pStagingBufferInfo = pDDIGetStandardAllocationDriverData->pCreateStagingSurfaceData;

            //
            // D3DDDIFMT_X8R8G8B8 is the only format for this type of surface
            //
            pR200CreateAllocData->CreateDataFormat = D3DDDIFMT_X8R8G8B8;

            pDrvAllocData->dwBytesPerPixel = 4;
            pDrvAllocData->dwPitch         = pStagingBufferInfo->Width * pDrvAllocData->dwBytesPerPixel;

            pDrvAllocData->dwPitchAlign    = 0x80;
            pDrvAllocData->dwHeight        = pStagingBufferInfo->Height;
            pDrvAllocData->dwHeightAlign   = 1;
            pDrvAllocData->dwOffsetAlign   = PAGE_SIZE;

            pDrvAllocData->dwCaps   = DDSCAPS_VIDEOMEMORY | DDSCAPS_OFFSCREENPLAIN;

            pDrvAllocData->hslSurfDesc.dwBPP    = pDrvAllocData->dwBytesPerPixel * 8;
            pDrvAllocData->hslSurfDesc.dwWidth  = pStagingBufferInfo->Width;
            pDrvAllocData->hslSurfDesc.dwHeight = pDrvAllocData->dwHeight;
            pDrvAllocData->hslSurfDesc.lPitch   = ByteAlign(pDrvAllocData->dwPitch,
                                                  pDrvAllocData->dwPitchAlign);

            //driver must output it back if it's D3DKMDT_STAGINGSURFACEDATA
            pStagingBufferInfo->Pitch = pDrvAllocData->hslSurfDesc.lPitch;

            pDrvAllocData->ddPixelFormat.dwSize        = sizeof(DDPIXELFORMAT);
            pDrvAllocData->ddPixelFormat.dwFlags       = DDPF_RGB;
            pDrvAllocData->ddPixelFormat.dwRGBBitCount = 32;
            pDrvAllocData->ddPixelFormat.dwRBitMask    = 0x00FF0000;
            pDrvAllocData->ddPixelFormat.dwGBitMask    = 0x0000FF00;
            pDrvAllocData->ddPixelFormat.dwBBitMask    = 0x000000FF;

            if (R200AGPEnabled(pAdapter))
            {
                pDrvAllocData->dwHeap  = 1;
                pDrvAllocData->dwCaps |= DDSCAPS_NONLOCALVIDMEM;
            }
            else
            {
                pDrvAllocData->dwHeap  = 0;
                pDrvAllocData->dwCaps |= DDSCAPS_LOCALVIDMEM;
            }

            break;
        }
        default :
        {
            return STATUS_INVALID_PARAMETER;
        }

    }

    // Create data UM driver will use to in the OpenCall
    pR200CreateAllocData->CreateDataPool=D3DDDIPOOL_LOCALVIDMEM;
    pR200CreateAllocData->CreateDataMultisampleType=D3DDDIMULTISAMPLE_NONE;
    pR200CreateAllocData->CreateDataMultisampleQuality=0;
    pR200CreateAllocData->CreateDataSurfCount=1;
    pR200CreateAllocData->CreateDataMipLevels=0;
    pR200CreateAllocData->CreateDataFvf=0;
    pR200CreateAllocData->CreateDataVidPnSourceId=pDrvAllocData->VidPnSourceId;
    pR200CreateAllocData->CreateDataSurfDepth=0;
    pR200CreateAllocData->CreateDataFlags.Value=0;
    if (pDDIGetStandardAllocationDriverData->StandardAllocationType == D3DKMDT_STANDARDALLOCATION_SHAREDPRIMARYSURFACE)
    {
        pR200CreateAllocData->CreateDataFlags.Primary = TRUE;
    }

    return STATUS_SUCCESS;
}

void EnforceHwSegRestrictions(HW_DEVICE_EXTENSION *pAdapter, DXGK_ALLOCATIONINFO *pAllocInfo)
{
    //
    // 8500 DV does not support AGP writes
    //
    if (pAdapter->usDeviceId == 0x4242)
    {
        pAllocInfo->SupportedWriteSegmentSet&=~(1 << (pAdapter->ulAGPSegID - 1));
        if (pAllocInfo->SupportedWriteSegmentSet == 0)
        {
            // Writes have to be supported in at least one device segment
            pAllocInfo->SupportedWriteSegmentSet=1;
            pAllocInfo->SupportedReadSegmentSet|=1;
        }
        pAllocInfo->EvictionSegmentSet&=~(1 << (pAdapter->ulAGPSegID - 1));
    }

    return;
}



NTSTATUS
D3DDDIAcquireSwizzlingRange(
    VOID                                *InterfaceContext,
    DXGKARG_ACQUIRESWIZZLINGRANGE   *pDDIASRData)
{
    PHW_DEVICE_EXTENSION            pHwDeviceExtension = ((PHW_DEVICE_EXTENSION*)InterfaceContext)[0];
    DXGKARGCB_GETHANDLEDATA         sHandleData = {0};
    PR2AllocationInfo               pAllocInfo;
    DXGK_INTERFACESPECIFICDATA      *pCallback;
    PTILED_SURFACE_INFO             pTiledSurf=NULL;
    DWORD                           SurfLowerBoundRegVal;
    DWORD                           SurfUpperBoundRegVal;
    DWORD                           SurfInfoRegVal;
    DWORD                           SurfPitchInOctoWords;
    DWORD                           TiledSurfRegBase;

    // R200 apetures only function on FB memory
    if (pDDIASRData->SegmentId != pHwDeviceExtension->ulFBSegID && pDDIASRData->SegmentId != pHwDeviceExtension->ulDXVASegID)
    {
        DBG_BREAK;
        return STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED;
    }

    pAllocInfo=(PR2AllocationInfo)pDDIASRData->hAllocation;
    ASSERT(pAllocInfo->dwAllocSize != 0);
    ASSERT((pAllocInfo->dwFlags & (HSL_SURF_IS_TILED | HSL_SURF_IS_MICROTILED)) != 0);

    //Check that this surface passes to pitch constraints of tiled surfaces
    SurfPitchInOctoWords=pAllocInfo->dwPitch/16;
    if ((pAllocInfo->dwCaps & DDSCAPS_ZBUFFER) == 0)
    {
        // Colour surface
        if ((pAllocInfo->dwFlags & HSL_SURF_IS_TILED) != 0)
        {
            // Ok R200 rquires pitch to be in 16 octowords and 512 or less
            if ((SurfPitchInOctoWords % 16) != 0 || SurfPitchInOctoWords > 512)
            {
                return STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED;
            }
        }
        else
        {
            // Pitch needs to be less than 1024 octowords
            if (SurfPitchInOctoWords >= 1024)
            {
                return STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED;
            }
        }
    }
    else
    {
        // Z buffer, check BPP
        if (pAllocInfo->hslSurfDesc.dwBPP == 16)
        {
            // Octoworkd pitch but be between 1 and 257
            if (SurfPitchInOctoWords < 1 || SurfPitchInOctoWords > 257)
            {
                return STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED;
            }
        }
        else
        {
            // 32bit Z buffer, must be even number of octowords from 2 to 514
            if ((SurfPitchInOctoWords % 2) != 0 || SurfPitchInOctoWords < 2 || SurfPitchInOctoWords > 514)
            {
                return STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED;
            }
        }
    }

    pTiledSurf=&pHwDeviceExtension->sTiledSurf[pDDIASRData->RangeId];
    ASSERT(FALSE == pTiledSurf->bEnabled);

    // Now create surface register values
    SurfLowerBoundRegVal=SURFACE0_LOWER_BOUND__SURF_LOWER_MASK & pDDIASRData->CPUTranslatedAddress.LowPart;
    SurfUpperBoundRegVal=SURFACE0_UPPER_BOUND__SURF_UPPER_MASK & (pDDIASRData->CPUTranslatedAddress.LowPart + pAllocInfo->dwAllocSize - 1);

    SurfInfoRegVal=SURFACE0_INFO__SURF0_PITCHSEL_MASK & SurfPitchInOctoWords;

    if ((pAllocInfo->dwFlags & (HSL_SURF_IS_TILED | HSL_SURF_IS_MICROTILED)) == (HSL_SURF_IS_TILED | HSL_SURF_IS_MICROTILED))
    {
        SurfInfoRegVal|=3 << SURFACE0_INFO__SURF0_TILE_MODE__SHIFT;
    }
    else if ((pAllocInfo->dwFlags & (HSL_SURF_IS_TILED | HSL_SURF_IS_MICROTILED)) == HSL_SURF_IS_TILED)
    {
        SurfInfoRegVal|=1 << SURFACE0_INFO__SURF0_TILE_MODE__SHIFT;
    }
    else if ((pAllocInfo->dwFlags & (HSL_SURF_IS_TILED | HSL_SURF_IS_MICROTILED)) == HSL_SURF_IS_MICROTILED)
    {
        SurfInfoRegVal|=2 << SURFACE0_INFO__SURF0_TILE_MODE__SHIFT;;
    }

    // Surface tiled apeture regs are arranged in blocks of 3 regs, SURFACEx_LOWER_BOUND
    // then SURFACEx_UPPER_BOUND and then SURFACEx_INFO, find reg num of SURFACEx_LOWER_BOUND for this set
    TiledSurfRegBase = mmSURFACE0_LOWER_BOUND + ((mmSURFACE1_LOWER_BOUND - mmSURFACE0_LOWER_BOUND) * pDDIASRData->RangeId);

    //Now program the aperture
    WriteMmRegisterUlong(pHwDeviceExtension->pvMmr, TiledSurfRegBase, SurfLowerBoundRegVal);
    WriteMmRegisterUlong(pHwDeviceExtension->pvMmr, TiledSurfRegBase+1, SurfUpperBoundRegVal);
    WriteMmRegisterUlong(pHwDeviceExtension->pvMmr, TiledSurfRegBase+2, SurfInfoRegVal);

    //Store the surface this aperture is set to
    pTiledSurf->bEnabled=TRUE;
    pTiledSurf->pSurfData=pAllocInfo;

    return STATUS_SUCCESS;
}

NTSTATUS
D3DDDIReleaseSwizzlingRange(
    VOID                                    *InterfaceContext,
    CONST DXGKARG_RELEASESWIZZLINGRANGE *pDDIRSRData)
{
    PR2AllocationInfo               pAllocInfo;
    PTILED_SURFACE_INFO             pTiledSurf = NULL;
    DWORD                           dwIdx;
    PHW_DEVICE_EXTENSION            pHwDeviceExtension = ((PHW_DEVICE_EXTENSION*)InterfaceContext)[0];
    DWORD                           TiledSurfInfoReg;


    pAllocInfo = (PR2AllocationInfo)pDDIRSRData->hAllocation;

    pTiledSurf = &pHwDeviceExtension->sTiledSurf[pDDIRSRData->RangeId];
    ASSERT(TRUE == pTiledSurf->bEnabled);

    // Now clear the mapping
    TiledSurfInfoReg = mmSURFACE0_INFO + ((mmSURFACE1_LOWER_BOUND - mmSURFACE0_LOWER_BOUND) * pDDIRSRData->RangeId);
    WriteMmRegisterUlong(pHwDeviceExtension->pvMmr, TiledSurfInfoReg, 0);

    // That aperture is avaliable now
    pTiledSurf->bEnabled = FALSE;

    return STATUS_SUCCESS;
}


//==================================//
// Implementations of MMDMM support //
//==================================//


/////////////////////////////////////////////////////////////////
// Code shared between multiple MMDMM support implementations. //
/////////////////////////////////////////////////////////////////

BOOLEAN
DoesScanlineOrderingMatch
(
  CONST VIDEO_MODE_INFORMATION*     i_pVidModeInfo,
  CONST D3DKMDT_VIDEO_SIGNAL_INFO*  i_pVideoSignalInfo
)
{
    switch ( i_pVideoSignalInfo->ScanLineOrdering )
    {
        case D3DDDI_VSSLO_PROGRESSIVE:
        {
            return ((i_pVidModeInfo->AttributeFlags & VIDEO_MODE_INTERLACED) == 0);
        }

        case D3DDDI_VSSLO_INTERLACED_UPPERFIELDFIRST:
        case D3DDDI_VSSLO_INTERLACED_LOWERFIELDFIRST:
        {
            return ((i_pVidModeInfo->AttributeFlags & VIDEO_MODE_INTERLACED) == VIDEO_MODE_INTERLACED);
        }

        default:
            EngDebugBreak();
    }

    return FALSE;

} // DoesScanlineOrderingMatch()


NTSTATUS
GetVideoModeInfoFromPresentPathInfo
(
  IN        HW_DEVICE_EXTENSION*              i_pHwDeviceExtension,
  IN        D3DKMDT_HVIDPN                    i_hVidPn,
  CONST     D3DDDI_VIDEO_PRESENT_SOURCE_ID    i_VidPnSourceId,
  CONST     D3DKMDT_VIDPN_PRESENT_PATH_INDEX  i_PathIndex,
  __out_opt D3DDDI_VIDEO_PRESENT_TARGET_ID*   o_VidPnTargetId,
  OUT       VIDEO_MODE_INFORMATION*           o_pVidModeInfo
)
{
    DXGKRNL_INTERFACE*           pDxgKrnlCallback    = &(i_pHwDeviceExtension->ddiCallback);
    CONST DXGK_VIDPN_INTERFACE*  pVidPnInterface = NULL;

    // Parameter validation (checked-only).
    {
        ASSERT( ARGUMENT_PRESENT(i_pHwDeviceExtension) );
        ASSERT( ARGUMENT_PRESENT(i_hVidPn) );
        ASSERT( ARGUMENT_PRESENT(o_pVidModeInfo) );

        // ASSUMPTION: This assumes VidPN source IDs are elements of a 0-based dense set.
        ASSERT( IsVidPnSourceIdValid(i_VidPnSourceId) );
    }

    // Output parameter initialization.
    RtlZeroMemory(o_pVidModeInfo, sizeof(*o_pVidModeInfo));

    // Acquire the VidPN object management interface v.1.0 from Windows Graphics Kernel.
    {
        NTSTATUS ntStatus = pDxgKrnlCallback->DxgkCbQueryVidPnInterface(i_hVidPn,
                                                                        DXGK_VIDPN_INTERFACE_VERSION_V1,
                                                                        &pVidPnInterface);

        ASSERT( NT_SUCCESS(ntStatus) );
        ASSERT( ARGUMENT_PRESENT(pVidPnInterface) );
    }

    // Determine the XDDM display mode index from the specified VidPN and affected VidPN source
    {
        D3DKMDT_HVIDPNTOPOLOGY               hVidPnTopology          = NULL;
        CONST DXGK_VIDPNTOPOLOGY_INTERFACE*  pVidPnTopologyInterface = NULL;
        D3DDDI_VIDEO_PRESENT_TARGET_ID       VidPnTargetId           = D3DDDI_ID_UNINITIALIZED;

        // Get VidPN topology object.
        {
            NTSTATUS ntStatus = pVidPnInterface->pfnGetTopology(i_hVidPn,
                                                                &hVidPnTopology,
                                                                &pVidPnTopologyInterface);

            // ASSUMPTION: Specified VidPN must have a valid topology object.
            ASSERT( NT_SUCCESS(ntStatus) );
        }

        //
        // Find the target connected to the specified source.
        {
            NTSTATUS ntStatus = pVidPnTopologyInterface->pfnEnumPathTargetsFromSource(hVidPnTopology,
                                                                                      i_VidPnSourceId,
                                                                                      i_PathIndex,
                                                                                      &VidPnTargetId);

            if (! NT_SUCCESS(ntStatus) )
            {
                //
                // This can be expected.
                //
                return ntStatus;
            }
        }

        if ( VidPnTargetId == D3DDDI_ID_UNINITIALIZED )
        {
            // INVARIANT: There is no present path originating from the specified VidPN source.
            return STATUS_GRAPHICS_PATH_NOT_IN_TOPOLOGY;
        }

        // Validate obtained VidPN target ID (checked-only).
        ASSERT( IsVidPnTargetIdValid(VidPnTargetId) );

        //
        // Set the return target ID value if caller asked for it.
        //
        if (o_VidPnTargetId != NULL)
        {
            *o_VidPnTargetId = VidPnTargetId;
        }

        // Find an XDDM display mode matching the obtained source and target modes.
        {
            D3DKMDT_HVIDPNSOURCEMODESET               hVidPnSourceModeSet          = NULL;
            CONST DXGK_VIDPNSOURCEMODESET_INTERFACE*  pVidPnSourceModeSetInterface = NULL;
            D3DKMDT_HVIDPNTARGETMODESET               hVidPnTargetModeSet          = NULL;
            CONST DXGK_VIDPNTARGETMODESET_INTERFACE*  pVidPnTargetModeSetInterface = NULL;
            CONST D3DKMDT_VIDPN_SOURCE_MODE*          pPinnedVidPnSourceModeInfo   = NULL;
            CONST D3DKMDT_VIDPN_TARGET_MODE*          pPinnedVidPnTargetModeInfo   = NULL;
            NTSTATUS                                  ntRetStatus                  = STATUS_SUCCESS;

            // Acquire pinned source/target modes
            {
                // First source.
                {
                    // Acquire the source mode set handle.
                    {
                        NTSTATUS ntStatus = pVidPnInterface->pfnAcquireSourceModeSet(i_hVidPn,
                                                                                     i_VidPnSourceId,
                                                                                     &hVidPnSourceModeSet,
                                                                                     &pVidPnSourceModeSetInterface);

                        // ASSUMPTION: Specified VidPN must have a valid cofunctional
                        //             source mode set object on the specified source.
                        ASSERT( NT_SUCCESS(ntStatus) );
                    }

                    // Obtain the pinned source mode info.
                    {
                        NTSTATUS ntStatus = pVidPnSourceModeSetInterface->pfnAcquirePinnedModeInfo(hVidPnSourceModeSet,
                                                                                                   &pPinnedVidPnSourceModeInfo);

                        // ASSUMPTION: Specified VidPN must have a source mode pinned on the specified source.
                        ASSERT( NT_SUCCESS(ntStatus) && (ntStatus != STATUS_GRAPHICS_MODE_NOT_PINNED) );
                    }
                }

                // Then target.
                {
                    // Acquire the target mode set handle.
                    {
                        NTSTATUS ntStatus = pVidPnInterface->pfnAcquireTargetModeSet(i_hVidPn,
                                                                                     VidPnTargetId,
                                                                                     &hVidPnTargetModeSet,
                                                                                     &pVidPnTargetModeSetInterface);

                        // ASSUMPTION: Specified VidPN must have a valid cofunctional
                        //             target mode set object on the specified target.
                        ASSERT( NT_SUCCESS(ntStatus) );
                    }

                    // Obtain the pinned target mode info.
                    {
                        NTSTATUS ntStatus = pVidPnTargetModeSetInterface->pfnAcquirePinnedModeInfo(hVidPnTargetModeSet,
                                                                                                   &pPinnedVidPnTargetModeInfo);

                        // ASSUMPTION: Specified VidPN must have a target mode pinned on the specified target.
                        ASSERT( NT_SUCCESS(ntStatus) && (ntStatus != STATUS_GRAPHICS_MODE_NOT_PINNED) );
                    }
                }
            }

            // Find the matching display mode.
            {
                VIDEO_MODE_INFORMATION*  pXddmDisplayModeSet            = NULL;
                SIZE_T                   sztNumXddmDisplayModesAcquired = 0;
                DWORD                    dwCurrentModeIndex             = 0;

                // Acquire the XDDM display mode set for this present path.
                {
                    NTSTATUS ntStatus = AcquireAvailableXddmDisplayModeSet(i_pHwDeviceExtension,
                                                                           &pXddmDisplayModeSet,
                                                                           &sztNumXddmDisplayModesAcquired);

                    if ( !NT_SUCCESS(ntStatus) )
                    {
                        ASSERT(FALSE);
                        ntRetStatus = ntStatus;
                        goto cleanup;
                    }
                }

                // Search through the available XDDM display modes until we find a mode that matches
                // the determined pinned source and target modes.
                for ( dwCurrentModeIndex = 0;
                      dwCurrentModeIndex < sztNumXddmDisplayModesAcquired;
                      ++dwCurrentModeIndex )
                {
                    D3DDDIFORMAT                     PixelFormat          = D3DDDIFMT_UNKNOWN;
                    D3DKMDT_PIXEL_VALUE_ACCESS_MODE  PixelValueAccessMode = D3DKMDT_PVAM_UNINITIALIZED;

                    // Alias current XDDM display mode for easier access.
                    CONST VIDEO_MODE_INFORMATION*  pCurrentXddmDisplayMode = &pXddmDisplayModeSet[dwCurrentModeIndex];

                    // Alias pinned source mode's graphics info for easier access.
                    CONST D3DKMDT_GRAPHICS_RENDERING_FORMAT*  pGraphicsInfo = &pPinnedVidPnSourceModeInfo->Format.Graphics;

                    // Alias pinned target mode's video signal info for easier access.
                    CONST D3DKMDT_VIDEO_SIGNAL_INFO*  pVideoSignalInfo = &pPinnedVidPnTargetModeInfo->VideoSignalInfo;

                    // Obtain pixel format and value access mode for the current XDDM display mode.
                    GetPixelFormatAndPVAM(pCurrentXddmDisplayMode->NumberRedBits,
                                          pCurrentXddmDisplayMode->NumberGreenBits,
                                          pCurrentXddmDisplayMode->NumberBlueBits,
                                          pCurrentXddmDisplayMode->RedMask,
                                          pCurrentXddmDisplayMode->GreenMask,
                                          pCurrentXddmDisplayMode->BlueMask,
                                          &PixelFormat,
                                          &PixelValueAccessMode);

                    // ASSUMPTION: We don't need pixel value access mode since whether it's direct or palette based mode
                    //             is implied from the pixel format and we don't care if the palette is preset or settable
                    //             for finding a matching display mode.
                    UNREFERENCED_PARAMETER(PixelValueAccessMode);

                    // NOTE: We know that denominator will be 1 here because all XDDM display mode VSync frequencies are integer,
                    //       (see PopulateTargetModeSet_XddmParity code for details).
                    ASSERT( pVideoSignalInfo->VSyncFreq.Denominator == 1 );

                    // If the current XDDM display mode matches the source/target mode parameters, stop the search.
                    if ( (pGraphicsInfo->PixelFormat == PixelFormat)
                         &&
                         (pVideoSignalInfo->ActiveSize.cx == pCurrentXddmDisplayMode->VisScreenWidth)
                         &&
                         (pVideoSignalInfo->ActiveSize.cy == pCurrentXddmDisplayMode->VisScreenHeight)
                         &&
                         (pVideoSignalInfo->VSyncFreq.Numerator == pCurrentXddmDisplayMode->Frequency)
                         &&
                         DoesScanlineOrderingMatch(pCurrentXddmDisplayMode, pVideoSignalInfo) )
                    {
                        // INVARIANT: Current mode matches the modality of the specified VidPN present path.

                        // Report current mode's parameters to the caller.
                        *o_pVidModeInfo = *pCurrentXddmDisplayMode;

                        ntRetStatus = STATUS_SUCCESS;
                        break;
                    }
                }

                // Dispose of the temporary XDDM mode set used to produce the respective LDDM source/target mode sets.
                ExFreePool(pXddmDisplayModeSet);

                if ( dwCurrentModeIndex == sztNumXddmDisplayModesAcquired )
                {
                    // INVARIANT: We couldn't find a matching XDM display mode for the specified pinned source/target modes.
                    ntRetStatus = STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED;
                }
            }

cleanup:
            // Release acquired source/target mode set handles and pinned mode info.
            {
                // First source.
                {
                    // First pinned mode info.
                    {
                        NTSTATUS  ntStatus = pVidPnSourceModeSetInterface->pfnReleaseModeInfo(hVidPnSourceModeSet,
                                                                                              pPinnedVidPnSourceModeInfo);

                        // ASSUMPTION: Release must succeed.
                        ASSERT( NT_SUCCESS(ntStatus) );
                    }

                    // Release acquired source mode set handle.
                    {
                        NTSTATUS  ntStatus = pVidPnInterface->pfnReleaseSourceModeSet(i_hVidPn,
                                                                                          hVidPnSourceModeSet);

                        // ASSUMPTION: Release must succeed.
                        ASSERT( NT_SUCCESS(ntStatus) );
                    }
                }

                // Then target.
                {
                    // First pinned mode info.
                    {
                        NTSTATUS  ntStatus = pVidPnTargetModeSetInterface->pfnReleaseModeInfo(hVidPnTargetModeSet,
                                                                                              pPinnedVidPnTargetModeInfo);

                        // ASSUMPTION: Release must succeed.
                        ASSERT( NT_SUCCESS(ntStatus) );
                    }

                    // Release acquired target mode set handle.
                    {
                        NTSTATUS  ntStatus = pVidPnInterface->pfnReleaseTargetModeSet(i_hVidPn,
                                                                                      hVidPnTargetModeSet);

                        // ASSUMPTION: Release must succeed.
                        ASSERT( NT_SUCCESS(ntStatus) );
                    }
                }
            }
        }
    }

    return STATUS_SUCCESS;

} // GetVideoModeInfoFromPresentPathInfo().


NTSTATUS
CommitVidPnPresentPath(
    HW_DEVICE_EXTENSION*            i_pHwDeviceExtension,
    D3DKMDT_HVIDPN                  i_hVidPn,
    D3DDDI_VIDEO_PRESENT_SOURCE_ID  i_VidPnSourceId)
{
    VIDEO_MODE_INFORMATION          VidModeInfo        = {0};
    BOOLEAN                         bIsPathBeingAdded  = TRUE;
    D3DDDI_VIDEO_PRESENT_SOURCE_ID  VidPnTargetId = D3DDDI_ID_UNINITIALIZED;
    BOOL                            bDone = FALSE;
    BOOL                            bAddedPath = FALSE;
    D3DKMDT_VIDPN_PRESENT_PATH_INDEX PathIndex = 0;

    ASSERT  ( IsVidPnSourceIdValid ( i_VidPnSourceId ) );

    // Determine the index of XDDM display mode matching the present path modality originating from the specified VidPN's source.
    while (TRUE)
    {
        NTSTATUS ntStatus = GetVideoModeInfoFromPresentPathInfo(i_pHwDeviceExtension,
                                                                i_hVidPn,
                                                                i_VidPnSourceId,
                                                                PathIndex,
                                                                &VidPnTargetId,
                                                                &VidModeInfo);

        if ( (ntStatus == STATUS_GRAPHICS_PATH_NOT_IN_TOPOLOGY)       // all paths originating from specified source have been processed
             ||
             (ntStatus == STATUS_GRAPHICS_SOURCE_NOT_IN_TOPOLOGY) )   // there are no paths originating from specified source
        {
            break;
        }
        else if ( !NT_SUCCESS(ntStatus) )
        {
            return ntStatus;
        }

        // INVARIANT: ntStatus == STATUS_SUCCESS
        {
            //
            // NOTE: Real production driver should do an actual mode change in this function rather than cache the mode index
            //       and do the mode change on DXGK_INTERFACE::pfnSetVidPnSourceState like this sample code does.
            //       This was only done here to reuse existing XDDM infrastructure.
            //
            // Cache mode related information.
            i_pHwDeviceExtension->curModeInfo[i_VidPnSourceId].ModeIndex = VidModeInfo.ModeIndex;

            //
            // Setup which monitors we want to enable on which source(controller).
            //
            VidPnTargetId &= ~(HW_ID_DISPLAY_CHILD);

            //
            // Enable the display.
            //
            if (i_pHwDeviceExtension->AcpiChildren != NULL)
            {
                switch (VidPnTargetId)
                {
                case HW_ID_ACPI_MONITOR:
                    i_pHwDeviceExtension->ulEnabledDisplays |= i_pHwDeviceExtension->ulaDisplayTypeVector[DISPLAY_MONITOR];
                    break;
                case HW_ID_ACPI_TV:
                    i_pHwDeviceExtension->ulEnabledDisplays |= i_pHwDeviceExtension->ulaDisplayTypeVector[DISPLAY_TELEVISION];
                    break;
                case HW_ID_ACPI_FLAT_PANEL:
                    i_pHwDeviceExtension->ulEnabledDisplays |= i_pHwDeviceExtension->ulaDisplayTypeVector[DISPLAY_LCDPANEL];
                    break;
                case HW_ID_ACPI_DIGITAL_FLAT_PANEL:
                    i_pHwDeviceExtension->ulEnabledDisplays |= i_pHwDeviceExtension->ulaDisplayTypeVector[DISPLAY_DIGITALFLATPANEL];
                    break;
                default:
                    // Non-ACPI child displays.
                    // In this case do nothing.
                    break;
                }
            }
            else
            {
                i_pHwDeviceExtension->ulEnabledDisplays |= (1 << (EXTRACT_DISPLAY_INDEX(VidPnTargetId)));
            }
        }

        PathIndex++;
    }

    //
    // Check to see if any paths are present.
    //
    if (PathIndex == 0)
    {
        NTSTATUS              ntStatus;
        HW_DEVICE_EXTENSION*  pAtlAdapter;

        // INVARIANT: There are no active present paths on the source.
        i_pHwDeviceExtension->curModeInfo[i_VidPnSourceId].ModeIndex = 0;

        if (i_VidPnSourceId == 1)
        {
            // Use other HwExt to call SetVidPnSourceStatus()
            pAtlAdapter = i_pHwDeviceExtension->pvHwOtherDevExt;
        }
        else
        {
            // Use given HwExt to call SetVidPnSourceStatus()
            pAtlAdapter = i_pHwDeviceExtension;
        }

        // Disable the CRTC
        ntStatus = SetVidPnSourceStatus((PVOID)&pAtlAdapter, 0, FALSE);

        if ( !NT_SUCCESS(ntStatus) )
        {
            return ntStatus;
        }

    }

    return STATUS_SUCCESS;

} // CommitVidPnPresentPath


NTSTATUS
D3DDDICommitVidPn(
    HANDLE                          i_hAdapter,
    CONST DXGKARG_COMMITVIDPN*  i_pDDICommitVidPN)
{
    HW_DEVICE_EXTENSION*            pHwDeviceExtension = ((PHW_DEVICE_EXTENSION*)i_hAdapter)[0];
    D3DKMDT_HVIDPN                  hVidPn             = i_pDDICommitVidPN->hFunctionalVidPn;
    D3DDDI_VIDEO_PRESENT_SOURCE_ID  VidPnSourceId      = i_pDDICommitVidPN->AffectedVidPnSourceId;

    ASSERT( IsVidPnSourceIdValid(VidPnSourceId) );

    //
    // Reset the enabled displays.
    //
    pHwDeviceExtension->ulEnabledDisplays = 0;

    return CommitVidPnPresentPath(pHwDeviceExtension,
                                           hVidPn,
                                           VidPnSourceId);

} // D3DDDICommitVidPn()


typedef NTSTATUS (*PFN_POPULATE_VIDPN_PRESENT_PATH_COFUNCMODALITY)
                    (CONST HW_DEVICE_EXTENSION*                   i_pHwDeviceExtension,
                     CONST D3DKMDT_HVIDPN                         i_hVidPn,
                     CONST D3DKMDT_VIDPN_PRESENT_PATH* CONST      i_pVidPnPresentPath,
                     CONST DXGK_VIDPN_INTERFACE* CONST            i_pDxgVidPnInterface,
                     CONST D3DKMDT_ENUMCOFUNCMODALITY_PIVOT_TYPE  i_EnumPivotType,
                     BOOLEAN* CONST                               i_arr_bIsSourceModeSetPopulated);

NTSTATUS
AddSourceMode
(
    CONST D3DKMDT_HVIDPNSOURCEMODESET                      i_hSourceModeSet,
    CONST DXGK_VIDPNSOURCEMODESET_INTERFACE* CONST         i_pDxgkVidPnSourceModeSetInterface,
    CONST D3DKMDT_GRAPHICS_RENDERING_FORMAT* CONST         i_pVidPnSourceModeInfo,
    __out_opt D3DKMDT_VIDEO_PRESENT_SOURCE_MODE_ID* CONST  o_pVidPnSourceModeId,
    CONST D3DKMDT_VIDEO_PRESENT_SOURCE_MODE_ID             i_VidPnSourceModeId
)
{
    D3DKMDT_VIDPN_SOURCE_MODE*  pVidPnSourceMode = NULL;

    // Acquire mode info placeholder.
    {
        NTSTATUS ntStatus = i_pDxgkVidPnSourceModeSetInterface->pfnCreateNewModeInfo(i_hSourceModeSet,
                                                                                     &pVidPnSourceMode);
        if ( !NT_SUCCESS(ntStatus) )
        {
            return ntStatus;
        }

        ASSERT( ARGUMENT_PRESENT(pVidPnSourceMode) );
    }

    // Populate mode info.
    {
        // Set the source mode ID, if provided by the caller (otherwise OS will assign one).
        if ( i_VidPnSourceModeId != D3DDDI_ID_UNINITIALIZED)
        {
            pVidPnSourceMode->Id = i_VidPnSourceModeId;
        }

        pVidPnSourceMode->Type            = D3DKMDT_RMT_GRAPHICS;
        pVidPnSourceMode->Format.Graphics = *i_pVidPnSourceModeInfo;
    }

    // Store the ID before adding the mode (and invalidating pVidPnSourceMode).
    if ( o_pVidPnSourceModeId )
    {
        *o_pVidPnSourceModeId = pVidPnSourceMode->Id;
    }

    // Add the mode.
    {
        NTSTATUS ntStatus = i_pDxgkVidPnSourceModeSetInterface->pfnAddMode(i_hSourceModeSet,
                                                                           pVidPnSourceMode);
        if ( !NT_SUCCESS(ntStatus) )
        {
            // Release the source mode info placeholder, in case we failed to add it to the mode set.
            {
                NTSTATUS ntReleaseStatus = i_pDxgkVidPnSourceModeSetInterface->pfnReleaseModeInfo(i_hSourceModeSet,
                                                                                                  pVidPnSourceMode);
                ASSERT( NT_SUCCESS(ntReleaseStatus) );
            }

            return ntStatus;
        }
    }

    return STATUS_SUCCESS;

} // AddSourceMode function


NTSTATUS
AddTargetMode
(
    CONST D3DKMDT_HVIDPNTARGETMODESET                      i_hTargetModeSet,
    CONST DXGK_VIDPNTARGETMODESET_INTERFACE* CONST         i_pDxgkVidPnTargetModeSetInterface,
    CONST D3DKMDT_VIDEO_SIGNAL_INFO* CONST                 i_pVidPnTargetModeInfo,
    __out_opt D3DKMDT_VIDEO_PRESENT_TARGET_MODE_ID* CONST  o_pVidPnTargetModeId,
    CONST D3DKMDT_VIDEO_PRESENT_TARGET_MODE_ID             i_VidPnTargetModeId,
    CONST D3DKMDT_MODE_PREFERENCE                          i_Preference
)
{
    D3DKMDT_VIDPN_TARGET_MODE*  pVidPnTargetMode = NULL;

    // Acquire mode info placeholder.
    {
        NTSTATUS ntStatus = i_pDxgkVidPnTargetModeSetInterface->pfnCreateNewModeInfo(i_hTargetModeSet,
                                                                                     &pVidPnTargetMode);
        if ( !NT_SUCCESS(ntStatus) )
        {
            return ntStatus;
        }

        ASSERT( ARGUMENT_PRESENT(pVidPnTargetMode) );
    }

    // Populate mode info
    {
        // Set the source mode ID, if provided by the caller (otherwise OS will assign one).
        if ( i_VidPnTargetModeId != D3DDDI_ID_UNINITIALIZED)
        {
            pVidPnTargetMode->Id = i_VidPnTargetModeId;
        }

        pVidPnTargetMode->VideoSignalInfo = *i_pVidPnTargetModeInfo;

        pVidPnTargetMode->Preference = i_Preference;
    }

    // Store the ID before adding the mode (and invalidating pVidPnTargetMode).
    if ( o_pVidPnTargetModeId )
    {
        *o_pVidPnTargetModeId = pVidPnTargetMode->Id;
    }

    // Add the mode.
    {
        NTSTATUS ntStatus = i_pDxgkVidPnTargetModeSetInterface->pfnAddMode(i_hTargetModeSet,
                                                                           pVidPnTargetMode);
        if ( !NT_SUCCESS(ntStatus) )
        {
            // Release the target mode info placeholder, in case we failed to add it to the mode set.
            {
                NTSTATUS ntReleaseStatus = i_pDxgkVidPnTargetModeSetInterface->pfnReleaseModeInfo(i_hTargetModeSet,
                                                                                                  pVidPnTargetMode);
                ASSERT( NT_SUCCESS(ntReleaseStatus) );
            }

            return ntStatus;
        }
    }

    return STATUS_SUCCESS;

} // AddTargetMode function


NTSTATUS
EnumVidPnCofuncModality
(
    VOID* CONST                                       i_pvInterfaceContext,
    CONST DXGKARG_ENUMVIDPNCOFUNCMODALITY* CONST      i_pEnumVidPnCofuncModalityArg,
    PFN_POPULATE_VIDPN_PRESENT_PATH_COFUNCMODALITY    i_pfnPopulateVidPnPresentPathCofuncModality,
    BOOLEAN* CONST                                    i_arr_bIsSourceModeSetPopulated
)
/*++
Routine Description:
    Implementation of D3DDDIEnumVidPnCofuncModality reused with different versions of provided mode enumeration routine.

Arguments:
    i_pvInterfaceContext
      - TBD

    i_pEnumVidPnCofuncModalityArg
      - TBD

    i_pfnPopulateVidPnPresentPathCofuncModality
      - TBD

Return Value:
    STATUS_SUCCESS
      - Request has been completed successfully.

    STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE
      - Constraining VidPn contains an invalid video present source.

    STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET
      - Constraining VidPn contains an invalid video present target.

    STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED
      - Specified constraining VidPn's modality is not supported. (e.g. changes in memory
        bandwidth/capacity constraints might have invalidated previously valid modes).

    STATUS_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED
      - Specified constraining VidPn is not supported (e.g. monitor HPD might have invalidated
        a previously valid topology).

    STATUS_NO_MEMORY
      - Enough memory could not be allocated for the result set.

Side Effects:
    TBD

Allocation ownership semantics:
    TBD

Remarks:
    TBD

Environment:
    Kernel mode. PASSIVE_LEVEL.

--*/
{
    PHW_DEVICE_EXTENSION               pHwDeviceExtension          = NULL;
    DXGKRNL_INTERFACE*                 pDxgKrnlCallback            = NULL;
    D3DKMDT_HVIDPN                     hConstrainingVidPn          = NULL;
    DXGK_VIDPN_INTERFACE*              pDxgkVidPnInterface         = NULL;
    D3DKMDT_HVIDPNTOPOLOGY             hConstrainingVidPnTopology  = NULL;
    DXGK_VIDPNTOPOLOGY_INTERFACE*      pDxgkVidPnTopologyInterface = NULL;

    // Parameter validation (checked-only).
    {
        ASSERT( ARGUMENT_PRESENT(i_pvInterfaceContext) );
        ASSERT( ARGUMENT_PRESENT(i_pEnumVidPnCofuncModalityArg) );
        ASSERT( ARGUMENT_PRESENT(i_pEnumVidPnCofuncModalityArg->hConstrainingVidPn) );
        ASSERT( ARGUMENT_PRESENT(i_pfnPopulateVidPnPresentPathCofuncModality) );
        ASSERT( ARGUMENT_PRESENT(i_arr_bIsSourceModeSetPopulated) );
    }

    // Caller must pass adapter's h/w device extension as the interface context.
    pHwDeviceExtension = ((PHW_DEVICE_EXTENSION*)i_pvInterfaceContext)[0];
    pDxgKrnlCallback = &(pHwDeviceExtension->ddiCallback);

    // Alias the constraining VidPN for easier access.
    hConstrainingVidPn = i_pEnumVidPnCofuncModalityArg->hConstrainingVidPn;

    // Acquire the VidPN object management interface from Windows Graphics Kernel.
    {
        NTSTATUS ntStatus = pDxgKrnlCallback->DxgkCbQueryVidPnInterface(hConstrainingVidPn,
                                                                        DXGK_VIDPN_INTERFACE_VERSION_V1,
                                                                        &pDxgkVidPnInterface);

        ASSERT( NT_SUCCESS(ntStatus) );
        ASSERT( ARGUMENT_PRESENT(pDxgkVidPnInterface) );
    }

    // Acquire constraining VidPN's topology object.
    {
        NTSTATUS ntStatus = pDxgkVidPnInterface->pfnGetTopology(hConstrainingVidPn,
                                                                &hConstrainingVidPnTopology,
                                                                &pDxgkVidPnTopologyInterface);

        ASSERT( NT_SUCCESS(ntStatus) );
        ASSERT( ARGUMENT_PRESENT(hConstrainingVidPnTopology) );
        ASSERT( ARGUMENT_PRESENT(pDxgkVidPnTopologyInterface) );
    }

    // Clear the cofunctional mode set enumeration progress table.
    {
        D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;

        for ( VidPnSourceId = 0;
              VidPnSourceId < NUMBER_OF_VIDEO_PRESENT_SOURCES;
              ++VidPnSourceId )
        {
            i_arr_bIsSourceModeSetPopulated[VidPnSourceId] = FALSE;
        }
    }

    // For each path in the topology, populate its source/target mode sets.
    {
        CONST D3DKMDT_VIDPN_PRESENT_PATH*  pCurrentVidPnPresentPath = NULL;

        // Get the info of the first path in the topology.
        {
            NTSTATUS ntStatus = pDxgkVidPnTopologyInterface->pfnAcquireFirstPathInfo(hConstrainingVidPnTopology,
                                                                                     &pCurrentVidPnPresentPath);

            if ( !NT_SUCCESS(ntStatus) )
            {
                // The only reason this is expected to fail is a low memory condition in case memory
                // is being allocated for source mode info by the Windows Graphics kernel service.
                ASSERT( ntStatus == STATUS_NO_MEMORY );

                return ntStatus;
            }
        }

        // Until all present paths in the topology are processed:
        while ( pCurrentVidPnPresentPath )
        {
            // NOTE: Real driver would have used these parameters to determine cofunctional mode sets.
            //       With our fictitious h/w constraints result the mode sets are invariant with respect to these parameters.
            UNREFERENCED_PARAMETER(pCurrentVidPnPresentPath->ContentTransformation);
            UNREFERENCED_PARAMETER(pCurrentVidPnPresentPath->ImportanceOrdinal);

            // NOTE: Real driver should populate this support with
            // real supported rotation / scaling modes based on the VidPn, current rotation / scaling modes, and currently
            // pinned source / target modes(if pinned).
            {
                NTSTATUS ntStatus;

                BOOLEAN bUpdateTransformationSupport = FALSE;

                // Setup the supported rotation / scaling modes.
                D3DKMDT_VIDPN_PRESENT_PATH PresentPathInfo;

                RtlZeroMemory(&PresentPathInfo, sizeof(PresentPathInfo));

                // Copy the current transformation settings.
                PresentPathInfo.VidPnSourceId = pCurrentVidPnPresentPath->VidPnSourceId;
                PresentPathInfo.VidPnTargetId = pCurrentVidPnPresentPath->VidPnTargetId;
                PresentPathInfo.ContentTransformation = pCurrentVidPnPresentPath->ContentTransformation;
                PresentPathInfo.CopyProtection = pCurrentVidPnPresentPath->CopyProtection;

                // Only update the sets if they're not currently pinned.
                if (pCurrentVidPnPresentPath->ContentTransformation.Scaling == D3DKMDT_VPPS_UNPINNED)
                {
                    bUpdateTransformationSupport = TRUE;

                    PresentPathInfo.ContentTransformation.ScalingSupport.Identity = TRUE;
                    PresentPathInfo.ContentTransformation.ScalingSupport.Centered = TRUE;
                    PresentPathInfo.ContentTransformation.ScalingSupport.Stretched = TRUE;
                }

                if (pCurrentVidPnPresentPath->ContentTransformation.Rotation == D3DKMDT_VPPR_UNPINNED)
                {
                    bUpdateTransformationSupport = TRUE;

                    PresentPathInfo.ContentTransformation.RotationSupport.Identity = TRUE;
                    PresentPathInfo.ContentTransformation.RotationSupport.Rotate90 = TRUE;
                    PresentPathInfo.ContentTransformation.RotationSupport.Rotate180 = TRUE;
                    PresentPathInfo.ContentTransformation.RotationSupport.Rotate270 = TRUE;
                }

                if (bUpdateTransformationSupport)
                {
                    ntStatus  = pDxgkVidPnTopologyInterface->pfnUpdatePathSupportInfo(hConstrainingVidPnTopology,
                                                                                      &PresentPathInfo);

                    if ( !NT_SUCCESS(ntStatus) )
                    {
                        return ntStatus;
                    }
                }
            }

            // Populate the cofunctional source and target mode sets for the current VidPN present path,
            // given the specified constraining VidPN.
            {
                D3DKMDT_ENUMCOFUNCMODALITY_PIVOT_TYPE EnumPivotType = D3DKMDT_EPT_NOPIVOT;

                switch ( i_pEnumVidPnCofuncModalityArg->EnumPivotType )
                {
                    case D3DKMDT_EPT_VIDPNSOURCE:
                    {
                        if ( i_pEnumVidPnCofuncModalityArg->EnumPivot.VidPnSourceId == pCurrentVidPnPresentPath->VidPnSourceId )
                        {
                            // INVARIANT: Current present path's source is the pivot of this enumeration.
                            EnumPivotType = D3DKMDT_EPT_VIDPNSOURCE;
                        }

                        break;
                    }

                    case D3DKMDT_EPT_VIDPNTARGET:
                    {
                        if ( i_pEnumVidPnCofuncModalityArg->EnumPivot.VidPnTargetId == pCurrentVidPnPresentPath->VidPnTargetId )
                        {
                            // INVARIANT: Current present path's target is the pivot of this enumeration.
                            EnumPivotType = D3DKMDT_EPT_VIDPNTARGET;
                        }
                        break;
                    }

                    case D3DKMDT_EPT_NOPIVOT:
                        break;

                    case D3DKMDT_EPT_SCALING:
                    case D3DKMDT_EPT_ROTATION:
                        break;

                    default:
                    {
                        ASSERT( (i_pEnumVidPnCofuncModalityArg->EnumPivotType == D3DKMDT_EPT_VIDPNSOURCE)
                                ||
                                (i_pEnumVidPnCofuncModalityArg->EnumPivotType == D3DKMDT_EPT_VIDPNTARGET)
                                ||
                                (i_pEnumVidPnCofuncModalityArg->EnumPivotType == D3DKMDT_EPT_NOPIVOT)
                                ||
                                (i_pEnumVidPnCofuncModalityArg->EnumPivotType == D3DKMDT_EPT_SCALING)
                                ||
                                (i_pEnumVidPnCofuncModalityArg->EnumPivotType == D3DKMDT_EPT_ROTATION) );

                        return STATUS_INVALID_PARAMETER;
                    }
                }

                // Populate current present path's source and target mode sets using the function provided by the caller.
                {
                    // Determine the right h/w device extension based on the current present path's source ID.
                    HW_DEVICE_EXTENSION*  pCurrentPresentPathHwDeviceExtension = NULL;
                    {
                        switch ( pCurrentVidPnPresentPath->VidPnSourceId )
                        {
                            case VIDPN_SOURCE1_ID:
                                pCurrentPresentPathHwDeviceExtension = pHwDeviceExtension;
                                break;

                            case VIDPN_SOURCE2_ID:
                                pCurrentPresentPathHwDeviceExtension = pHwDeviceExtension->pvHwOtherDevExt;
                                break;
                        }
                    }

                    // Populate cofunctional modality of the current present path.
                    {
                        NTSTATUS ntStatus = i_pfnPopulateVidPnPresentPathCofuncModality(pCurrentPresentPathHwDeviceExtension,
                                                                                        hConstrainingVidPn,
                                                                                        pCurrentVidPnPresentPath,
                                                                                        pDxgkVidPnInterface,
                                                                                        EnumPivotType,
                                                                                        i_arr_bIsSourceModeSetPopulated);

                        if ( !NT_SUCCESS(ntStatus) )
                        {

                           // Return the error to the caller
                           return ntStatus;
                        }
                    }
               }
            }

            // Traverse to the next path in the topology.
            {
                CONST D3DKMDT_VIDPN_PRESENT_PATH*  pNextVidPnPresentPath = NULL;

                // Get the info of the next present path in the topology.
                {
                    NTSTATUS ntStatus = pDxgkVidPnTopologyInterface->pfnAcquireNextPathInfo(hConstrainingVidPnTopology,
                                                                                            pCurrentVidPnPresentPath,
                                                                                            &pNextVidPnPresentPath);

                    if ( !NT_SUCCESS(ntStatus) )
                    {
                        // The only reason this is expected to fail is a low memory condition in case memory
                        // is being allocated for source mode info by the Windows Graphics kernel service.
                        ASSERT( ntStatus == STATUS_NO_MEMORY );

                        return ntStatus;
                    }
                }

                // Release the no longer needed info of the last present path.
                {
                    NTSTATUS ntStatus = pDxgkVidPnTopologyInterface->pfnReleasePathInfo(hConstrainingVidPnTopology,
                                                                                        pCurrentVidPnPresentPath);

                    ASSERT( NT_SUCCESS(ntStatus) );
                }

                // Point VidPN topology iterator to the next present path in the topology.
                pCurrentVidPnPresentPath = pNextVidPnPresentPath;
            }
        }
    }

    return STATUS_SUCCESS;

} // EnumVidPnCofuncModality function




//////////////////////////////////////////
// LDDM->Xddm mode enumeration adapters //
//////////////////////////////////////////


NTSTATUS
D3DDDIRecommendFunctionalVidPn_Test
(
    VOID* CONST                                        i_pvInterfaceContext,
    CONST DXGKARG_RECOMMENDFUNCTIONALVIDPN* CONST  i_pRecommendFunctionalVidPnArg
)
{
    return STATUS_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN;

} // D3DDDIRecommendFunctionalVidPn_XddmParity function


VOID GetPixelFormatAndPVAM
(
   CONST ULONG                             i_ulNumRedBits,
   CONST ULONG                             i_ulNumGreenBits,
   CONST ULONG                             i_ulNumBlueBits,
   CONST ULONG                             i_ulRedMask,
   CONST ULONG                             i_ulGreenMask,
   CONST ULONG                             i_ulBlueMask,
   __out D3DDDIFORMAT*                     o_pPixelFormat,
   __out D3DKMDT_PIXEL_VALUE_ACCESS_MODE*  o_pPixelValueAccessMode
)
{
    // NOTE: XDDM display mode descriptor specified pixel format via masks and color channel bit-widths.
    //       LDDM source mode descriptor contains a D3DDDIFORMAT enum which lets the miniport specify exactly what
    //       type the source content is stored in.

    // Parameter validation (checked-only).
    {
        ASSERT( ARGUMENT_PRESENT(o_pPixelFormat) );
        ASSERT( ARGUMENT_PRESENT(o_pPixelValueAccessMode) );
    }

    // Initialize output parameters with default values.
    {
        *o_pPixelFormat          = D3DDDIFMT_UNKNOWN;
        *o_pPixelValueAccessMode = D3DKMDT_PVAM_UNINITIALIZED;
    }

    // Map XDDM pixel format representation into its LDDM equivalent.
    if ( (i_ulNumRedBits == 8) && (i_ulNumGreenBits == 8) && (i_ulNumBlueBits == 8) )
    {
        if ( (i_ulRedMask == 0) && (i_ulGreenMask == 0) && (i_ulBlueMask == 0) )
        {
            // INVARIANT: This is an 8-bpp indexed display mode.

            *o_pPixelFormat          = D3DDDIFMT_P8;
            *o_pPixelValueAccessMode = D3DKMDT_PVAM_PRESETPALETTE;
        }
        else if ( (i_ulRedMask == 0xFF0000) && (i_ulGreenMask == 0xFF00) && (i_ulBlueMask == 0xFF) )
        {
            // INVARIANT: This is a 24/32 bpp display mode.
            //
            // ASSUMPTION: XDDM display mode descriptor doesn't support the notion of the 4th channel, so there
            //             is no way for us to know if it's a 24 or a 32 bpp mode. We assume 32 bpp, since that's
            //             what this miniport reports for such modes.

            *o_pPixelFormat          = D3DDDIFMT_A8R8G8B8;
            *o_pPixelValueAccessMode = D3DKMDT_PVAM_DIRECT;
        }
        // else add your mapping here
    }
    else if ( (i_ulNumRedBits == 5) && (i_ulNumGreenBits == 6) && (i_ulNumBlueBits == 5) )
    {
        // INVARIANT: This is a 16 bpp display mode.

        if ( (i_ulRedMask == 0xF800) && (i_ulGreenMask == 0x7E0) && (i_ulBlueMask == 0x1F) )
        {
            *o_pPixelFormat          = D3DDDIFMT_R5G6B5;
            *o_pPixelValueAccessMode = D3DKMDT_PVAM_DIRECT;
        }
        // else add your mapping here
    }
    // else return with default values for output parameters.

} // GetPixelFormatAndPVAM function


SIZE_T DivideAndRound
(
  SIZE_T  i_sztNumerator,
  SIZE_T  i_sztDenominator
)
{
    SIZE_T  sztTruncatedQuotient = (i_sztNumerator / i_sztDenominator);

    if ( (((10*i_sztNumerator) / i_sztDenominator) - 10*sztTruncatedQuotient) < 5 )
    {
        return  sztTruncatedQuotient;
    }
    else
    {
        return  sztTruncatedQuotient + 1;
    }
}

NTSTATUS
PopulateSourceModeSet_XddmParity
(
  CONST D3DKMDT_HVIDPN                            i_hVidPn,
  CONST DXGK_VIDPN_INTERFACE* CONST               i_pDxgkVidPnInterface,
  CONST D3DDDI_VIDEO_PRESENT_SOURCE_ID            i_VidPnSourceId,
  CONST D3DDDI_VIDEO_PRESENT_TARGET_ID            i_VidPnTargetId,
  CONST SIZE_T                                    i_sztNumOfXddmDisplayModes,
  CONST VIDEO_MODE_INFORMATION*                   i_pXddmDisplayModeSet,
  BOOLEAN* CONST                                  i_arr_bIsSourceModeSetPopulated
)
{
    D3DKMDT_HVIDPNSOURCEMODESET               hSourceModeSet                   = NULL;
    CONST DXGK_VIDPNSOURCEMODESET_INTERFACE*  pDxgkVidPnSourceModeSetInterface = NULL;

    // Parameter validation (checked-only)
    {
        ASSERT( ARGUMENT_PRESENT(i_pDxgkVidPnInterface) );
        ASSERT( ARGUMENT_PRESENT(i_pXddmDisplayModeSet) );
    }

    // Avoid updating mode sets that already have a pinned mode.
    {
        D3DKMDT_HVIDPNSOURCEMODESET hVidPnSourceModeSet;
        CONST D3DKMDT_VIDPN_SOURCE_MODE*          pPinnedVidPnSourceMode           = NULL;
        BOOLEAN bUpdateSourceModeSet = TRUE;

        // Acquire the source mode set on this present path.
        {
            NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnAcquireSourceModeSet(i_hVidPn,
                                                                               i_VidPnSourceId,
                                                                               &hVidPnSourceModeSet,
                                                                               &pDxgkVidPnSourceModeSetInterface);
            if ( !NT_SUCCESS(ntStatus) )
            {
                return ntStatus;
            }
        }

        // Get the mode pinned in this source set (if any).
        {
            NTSTATUS ntStatus = pDxgkVidPnSourceModeSetInterface->pfnAcquirePinnedModeInfo(hVidPnSourceModeSet,
                                                                                           &pPinnedVidPnSourceMode);
            if ( ntStatus == STATUS_GRAPHICS_MODE_NOT_PINNED )
            {
                pPinnedVidPnSourceMode = NULL;
            }
            else if ( !NT_SUCCESS(ntStatus) )
            {
                return ntStatus;
            }
        }

        // Check to see if there is a pinned mode.
        if ( pPinnedVidPnSourceMode )
        {
            NTSTATUS ntStatus = pDxgkVidPnSourceModeSetInterface->pfnReleaseModeInfo(hVidPnSourceModeSet,
                                                                                     pPinnedVidPnSourceMode);
            ASSERT( NT_SUCCESS(ntStatus) );

            // We do not need to update the source mode set.
            bUpdateSourceModeSet = FALSE;
        }

        // Release acquired source mode set.
        {
            NTSTATUS ntReleaseStatus = i_pDxgkVidPnInterface->pfnReleaseSourceModeSet(i_hVidPn,
                                                                                      hVidPnSourceModeSet);
            ASSERT( NT_SUCCESS(ntReleaseStatus) );
        }

        if (!bUpdateSourceModeSet)
        {
            return STATUS_SUCCESS;
        }
    }

    // Make sure we didn't populate this source's mode set already (i.e. clone-view).
    if ( !i_arr_bIsSourceModeSetPopulated[i_VidPnSourceId] )
    {
        D3DKMDT_VIDEO_PRESENT_SOURCE_MODE_ID    VidPnSourceModeIndex             = 0;
        D3DKMDT_HVIDPNTARGETMODESET             hVidPnTargetModeSet              = NULL;
        DXGK_VIDPNTARGETMODESET_INTERFACE*  pDxgkVidPnTargetModeSetInterface = NULL;

        // Determine what mode is pinned on this present path's target (if any).
        D3DKMDT_VIDPN_TARGET_MODE*  pPinnedVidPnTargetMode = NULL;
        {
            // Acquire the target mode set on this present path.
            {
                NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnAcquireTargetModeSet(i_hVidPn,
                                                                                   i_VidPnTargetId,
                                                                                   &hVidPnTargetModeSet,
                                                                                   &pDxgkVidPnTargetModeSetInterface);
                if ( !NT_SUCCESS(ntStatus) )
                {
                    return ntStatus;
                }
            }

            // Get the mode pinned in this target set (if any).
            {
                NTSTATUS ntStatus = pDxgkVidPnTargetModeSetInterface->pfnAcquirePinnedModeInfo(hVidPnTargetModeSet,
                                                                                               &pPinnedVidPnTargetMode);
                if ( ntStatus == STATUS_GRAPHICS_MODE_NOT_PINNED )
                {
                    pPinnedVidPnTargetMode = NULL;
                }
                else if ( !NT_SUCCESS(ntStatus) )
                {
                    // Release acquired target mode set.
                    {
                        NTSTATUS ntReleaseStatus = i_pDxgkVidPnInterface->pfnReleaseTargetModeSet(i_hVidPn,
                                                                                                  hVidPnTargetModeSet);
                        ASSERT( NT_SUCCESS(ntReleaseStatus) );
                    }

                    return ntStatus;
                }
            }
        }

        // Create a new source mode set.
        {
            NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnCreateNewSourceModeSet(i_hVidPn,
                                                                                 i_VidPnSourceId,
                                                                                 &hSourceModeSet,
                                                                                 &pDxgkVidPnSourceModeSetInterface);
            ASSERT( NT_SUCCESS(ntStatus) );
            ASSERT( ARGUMENT_PRESENT(hSourceModeSet) );
            ASSERT( ARGUMENT_PRESENT(pDxgkVidPnSourceModeSetInterface) );
        }

        // For each XDDM display mode (to be potentially added to the source mode set):
        for ( VidPnSourceModeIndex = 0;
              VidPnSourceModeIndex < i_sztNumOfXddmDisplayModes;
              ++VidPnSourceModeIndex )
        {
            D3DKMDT_GRAPHICS_RENDERING_FORMAT     VidPnSourceModeInfo     = {0};
            CONST VIDEO_MODE_INFORMATION*         pCurrentXddmDisplayMode = &i_pXddmDisplayModeSet[VidPnSourceModeIndex];

            // Skip this display mode if its target mode parameters do not match those of the mode pinned on this present path's target (if any).
            if ( pPinnedVidPnTargetMode )
            {
                // Alias VidPN target mode's parameters for easier access.
                D3DKMDT_VIDEO_SIGNAL_INFO*  pPinnedVidPnTargetModeInfo = &pPinnedVidPnTargetMode->VideoSignalInfo;
                UINT                        unVSyncFreq                = 0;

                unVSyncFreq = (UINT)DivideAndRound(pPinnedVidPnTargetModeInfo->VSyncFreq.Numerator,
                                                   pPinnedVidPnTargetModeInfo->VSyncFreq.Denominator);

                if ( (pPinnedVidPnTargetModeInfo->ActiveSize.cx != pCurrentXddmDisplayMode->VisScreenWidth)
                     ||
                     (pPinnedVidPnTargetModeInfo->ActiveSize.cy != pCurrentXddmDisplayMode->VisScreenHeight)
                     ||
                     (unVSyncFreq != pCurrentXddmDisplayMode->Frequency) )
                {
                    continue;
                }
            }

            // INVARIANT: Current XDDM display mode's source mode parameters can be enumerated on this present path's source.

            // Populate VidPnSourceModeInfo based on the current XDDM display mode's info.
            {
                GetPixelFormatAndPVAM(pCurrentXddmDisplayMode->NumberRedBits,
                                      pCurrentXddmDisplayMode->NumberGreenBits,
                                      pCurrentXddmDisplayMode->NumberBlueBits,
                                      pCurrentXddmDisplayMode->RedMask,
                                      pCurrentXddmDisplayMode->GreenMask,
                                      pCurrentXddmDisplayMode->BlueMask,
                                      &VidPnSourceModeInfo.PixelFormat,
                                      &VidPnSourceModeInfo.PixelValueAccessMode);

                VidPnSourceModeInfo.PrimSurfSize.cx      = pCurrentXddmDisplayMode->VisScreenWidth;
                VidPnSourceModeInfo.PrimSurfSize.cy      = pCurrentXddmDisplayMode->VisScreenHeight;
                VidPnSourceModeInfo.VisibleRegionSize.cx = pCurrentXddmDisplayMode->VisScreenWidth;
                VidPnSourceModeInfo.VisibleRegionSize.cy = pCurrentXddmDisplayMode->VisScreenHeight;
                VidPnSourceModeInfo.Stride               = pCurrentXddmDisplayMode->ScreenStride;
                VidPnSourceModeInfo.ColorBasis           = D3DKMDT_CB_SRGB;
            }

            // Add source mode based on the newly created source mode descriptor.
            {
                NTSTATUS ntStatus = AddSourceMode(hSourceModeSet,
                                                  pDxgkVidPnSourceModeSetInterface,
                                                  &VidPnSourceModeInfo,
                                                  NULL,
                                                  D3DDDI_ID_UNINITIALIZED);

                // NOTE: Having OS complain about mode ID uniquess is fine, since this means we are currently
                // processing an XDDM mode whose source mode information subset is identical to one we
                // already processed (e.g. difference is in refresh rate that is not captured in source mode info).
                ASSERT( NT_SUCCESS(ntStatus) || (ntStatus == STATUS_GRAPHICS_MODE_ALREADY_IN_MODESET) );
            }
        }

        // NOTE: This mode will be rejected on mode change by R200 since it's not in the DAL mode list table.
        //
        // Report NTSC_M as supported mode to test TV mode enumeration.
        //
        do // once
        {
            D3DKMDT_GRAPHICS_RENDERING_FORMAT VidPnSourceModeInfo = {0};

            // Don't enumerate this mode if present path has an incompatible mode pinned on its target (if any).
            if ( pPinnedVidPnTargetMode )
            {
                D3DKMDT_VIDEO_SIGNAL_INFO*  pPinnedVidPnTargetModeInfo = &pPinnedVidPnTargetMode->VideoSignalInfo;

                if ( (pPinnedVidPnTargetModeInfo->VideoStandard != D3DKMDT_VSS_NTSC_M)
                     ||
                     (pPinnedVidPnTargetModeInfo->ActiveSize.cx != 720)
                     ||
                     (pPinnedVidPnTargetModeInfo->ActiveSize.cy != 525)
                     ||
                     (pPinnedVidPnTargetModeInfo->VSyncFreq.Numerator != 60000)
                     ||
                     (pPinnedVidPnTargetModeInfo->VSyncFreq.Denominator != 1001)
                     ||
                     (pPinnedVidPnTargetModeInfo->HSyncFreq.Numerator != 1573427)
                     ||
                     (pPinnedVidPnTargetModeInfo->HSyncFreq.Denominator != 100)
                     ||
                     (pPinnedVidPnTargetModeInfo->PixelRate != 3579545)
                     ||
                     (pPinnedVidPnTargetModeInfo->ScanLineOrdering != D3DDDI_VSSLO_INTERLACED_UPPERFIELDFIRST) )
                {
                    break;
                }
            }

            // Populate VidPnSourceModeInfo based on the current XDDM display mode's info.
            {
                VidPnSourceModeInfo.PrimSurfSize.cx      = 720;
                VidPnSourceModeInfo.PrimSurfSize.cy      = 525;
                VidPnSourceModeInfo.VisibleRegionSize.cx = 720;
                VidPnSourceModeInfo.VisibleRegionSize.cy = 525;
                VidPnSourceModeInfo.PixelFormat          = D3DDDIFMT_A8R8G8B8;
                VidPnSourceModeInfo.Stride               = 1024; // bogus value to make OS happy.
                VidPnSourceModeInfo.ColorBasis           = D3DKMDT_CB_YPBPR;
                VidPnSourceModeInfo.PixelValueAccessMode = D3DKMDT_PVAM_DIRECT;
            }

            // Add source mode based on the newly created source mode descriptor.
            {
                NTSTATUS ntStatus = AddSourceMode(hSourceModeSet,
                                                  pDxgkVidPnSourceModeSetInterface,
                                                  &VidPnSourceModeInfo,
                                                  NULL,
                                                  D3DDDI_ID_UNINITIALIZED);

                ASSERT( NT_SUCCESS(ntStatus) );
            }
        }
        while (FALSE);

        // Release resources acquired for population of the source mode set.
        {
            // Release pinned mode info first (if any).
            if ( pPinnedVidPnTargetMode )
            {
                NTSTATUS ntStatus = pDxgkVidPnTargetModeSetInterface->pfnReleaseModeInfo(hVidPnTargetModeSet,
                                                                                         pPinnedVidPnTargetMode);
                ASSERT( NT_SUCCESS(ntStatus) );
            }

            // Then release the target mode set.
            {
                NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnReleaseTargetModeSet(i_hVidPn,
                                                                                   hVidPnTargetModeSet);
                ASSERT( NT_SUCCESS(ntStatus) );
            }
        }

        // INVARIANT: All resources acquired in this function, except for the created source mode set
        //            to be assigned to the specified VidPN target have been released.

        // Assign the newly populated mode set to the specified present path's source, auto-releasing reference to this mode set.
        // NOTE: This substitutes whatever previous cofunctional mode set that was assigned to this source (if any).
        // NOTE: OS will make sure to pin the same mode in the newly assigned mode set that was pinned in the old one.
        {
            NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnAssignSourceModeSet(i_hVidPn,
                                                                              i_VidPnSourceId,
                                                                              hSourceModeSet);
            ASSERT( NT_SUCCESS(ntStatus) );
        }

        // Mark specified present path's source as processed to make sure we don't try to populate it again
        // in case of topologies with clone-view associations.
        i_arr_bIsSourceModeSetPopulated[i_VidPnSourceId] = TRUE;
    }
    else
    {
        // INVARIANT: Mode set on this source has already been populated because this source is
        //            shared between two (or more) paths in a clone-view association.

        // Assert here to see when this codepath is being trigerred (if ever).
        ASSERT( i_arr_bIsSourceModeSetPopulated[i_VidPnSourceId] );
    }

    return STATUS_SUCCESS;

} // PopulateSourceModeSet_XddmParity function


NTSTATUS
PopulateTargetModeSet_XddmParity
(
  CONST D3DKMDT_HVIDPN                  i_hVidPn,
  CONST DXGK_VIDPN_INTERFACE* CONST     i_pDxgkVidPnInterface,
  CONST D3DDDI_VIDEO_PRESENT_SOURCE_ID  i_VidPnSourceId,
  CONST D3DDDI_VIDEO_PRESENT_TARGET_ID  i_VidPnTargetId,
  CONST SIZE_T                          i_sztNumOfXddmDisplayModes,
  CONST VIDEO_MODE_INFORMATION*         i_pXddmDisplayModeSet
)
{
    D3DKMDT_HVIDPNTARGETMODESET               hTargetModeSet                   = NULL;
    CONST DXGK_VIDPNTARGETMODESET_INTERFACE*  pDxgkVidPnTargetModeSetInterface = NULL;
    D3DKMDT_VIDEO_PRESENT_TARGET_MODE_ID      VidPnTargetModeIndex             = 0;
    CONST D3DKMDT_VIDPN_SOURCE_MODE*          pPinnedVidPnSourceMode           = NULL;
    D3DKMDT_HVIDPNSOURCEMODESET               hVidPnSourceModeSet              = NULL;
    CONST DXGK_VIDPNSOURCEMODESET_INTERFACE*  pDxgkVidPnSourceModeSetInterface = NULL;

    // Parameter validation (checked-only)
    {
        ASSERT( ARGUMENT_PRESENT(i_pDxgkVidPnInterface) );
        ASSERT( ARGUMENT_PRESENT(i_pXddmDisplayModeSet) );
    }

    // Avoid updating mode sets that already have a pinned mode.
    {
        D3DKMDT_HVIDPNTARGETMODESET hVidPnTargetModeSet;
        CONST D3DKMDT_VIDPN_TARGET_MODE*          pPinnedVidPnTargetMode           = NULL;
        BOOLEAN bUpdateTargetModeSet = TRUE;

        // Acquire the Target mode set on this present path.
        {
            NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnAcquireTargetModeSet(i_hVidPn,
                                                                               i_VidPnTargetId,
                                                                               &hVidPnTargetModeSet,
                                                                               &pDxgkVidPnTargetModeSetInterface);
            if ( !NT_SUCCESS(ntStatus) )
            {
                return ntStatus;
            }
        }

        // Get the mode pinned in this Target set (if any).
        {
            NTSTATUS ntStatus = pDxgkVidPnTargetModeSetInterface->pfnAcquirePinnedModeInfo(hVidPnTargetModeSet,
                                                                                           &pPinnedVidPnTargetMode);
            if ( ntStatus == STATUS_GRAPHICS_MODE_NOT_PINNED )
            {
                pPinnedVidPnTargetMode = NULL;
            }
            else if ( !NT_SUCCESS(ntStatus) )
            {
                return ntStatus;
            }
        }

        // Check to see if there is a pinned mode.
        if ( pPinnedVidPnTargetMode )
        {
            NTSTATUS ntStatus = pDxgkVidPnTargetModeSetInterface->pfnReleaseModeInfo(hVidPnTargetModeSet,
                                                                                     pPinnedVidPnTargetMode);
            ASSERT( NT_SUCCESS(ntStatus) );

            // We do not need to update the Target mode set.
            bUpdateTargetModeSet = FALSE;
        }

        // Release acquired Target mode set.
        {
            NTSTATUS ntReleaseStatus = i_pDxgkVidPnInterface->pfnReleaseTargetModeSet(i_hVidPn,
                                                                                      hVidPnTargetModeSet);
            ASSERT( NT_SUCCESS(ntReleaseStatus) );
        }

        if (!bUpdateTargetModeSet)
        {
            return STATUS_SUCCESS;
        }
    }

    // NOTE: There is no way we can revisit the same target twice by enumerating over each of the present paths
    //       in VidPN's topology once, so we don't maintain a progress table for targets.

    // Determine what mode is pinned on this present path's source (if any).
    {
        // Acquire the source mode set on this present path.
        {
            NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnAcquireSourceModeSet(i_hVidPn,
                                                                               i_VidPnSourceId,
                                                                               &hVidPnSourceModeSet,
                                                                               &pDxgkVidPnSourceModeSetInterface);
            if ( !NT_SUCCESS(ntStatus) )
            {
                return ntStatus;
            }
        }

        // Get the mode pinned in this source set (if any).
        {
            NTSTATUS ntStatus = pDxgkVidPnSourceModeSetInterface->pfnAcquirePinnedModeInfo(hVidPnSourceModeSet,
                                                                                           &pPinnedVidPnSourceMode);
            if ( ntStatus == STATUS_GRAPHICS_MODE_NOT_PINNED )
            {
                pPinnedVidPnSourceMode = NULL;
            }
            else if ( !NT_SUCCESS(ntStatus) )
            {
                // Release acquired source mode set.
                {
                    NTSTATUS ntReleaseStatus = i_pDxgkVidPnInterface->pfnReleaseSourceModeSet(i_hVidPn,
                                                                                              hVidPnSourceModeSet);
                    ASSERT( NT_SUCCESS(ntReleaseStatus) );
                }

                return ntStatus;
            }
        }
    }

    // Create a new target mode set.
    {
        NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnCreateNewTargetModeSet(i_hVidPn,
                                                                             i_VidPnTargetId,
                                                                             &hTargetModeSet,
                                                                             &pDxgkVidPnTargetModeSetInterface);
        ASSERT( NT_SUCCESS(ntStatus) );
        ASSERT( ARGUMENT_PRESENT(hTargetModeSet) );
        ASSERT( ARGUMENT_PRESENT(pDxgkVidPnTargetModeSetInterface) );
    }

    // For each mode to be added to the target mode set:
    for ( VidPnTargetModeIndex = 0;
          VidPnTargetModeIndex < i_sztNumOfXddmDisplayModes;
          ++VidPnTargetModeIndex )
    {
        D3DKMDT_VIDEO_SIGNAL_INFO      VidPnTargetModeInfo     = {0};
        CONST VIDEO_MODE_INFORMATION*  pCurrentXddmDisplayMode = &i_pXddmDisplayModeSet[VidPnTargetModeIndex];

        // Skip this display mode if its source mode parameters do not match those of the mode pinned on this present path's source (if any).
        if ( pPinnedVidPnSourceMode )
        {
                CONST D3DKMDT_GRAPHICS_RENDERING_FORMAT*  pPinnedVidPnSourceModeInfo = &(pPinnedVidPnSourceMode->Format.Graphics);
                D3DDDIFORMAT                              XddmModePixelFormat        = D3DDDIFMT_UNKNOWN;
                D3DKMDT_PIXEL_VALUE_ACCESS_MODE           XddmModePixelVam           = D3DKMDT_PVAM_UNINITIALIZED;

                GetPixelFormatAndPVAM(pCurrentXddmDisplayMode->NumberRedBits,
                                      pCurrentXddmDisplayMode->NumberGreenBits,
                                      pCurrentXddmDisplayMode->NumberBlueBits,
                                      pCurrentXddmDisplayMode->RedMask,
                                      pCurrentXddmDisplayMode->GreenMask,
                                      pCurrentXddmDisplayMode->BlueMask,
                                      &XddmModePixelFormat,
                                      &XddmModePixelVam);

                if ( (pPinnedVidPnSourceModeInfo->PrimSurfSize.cx != pCurrentXddmDisplayMode->VisScreenWidth)
                     ||
                     (pPinnedVidPnSourceModeInfo->PrimSurfSize.cy != pCurrentXddmDisplayMode->VisScreenHeight)
                     ||
                     (pPinnedVidPnSourceModeInfo->PixelFormat != XddmModePixelFormat)
                     ||
                     (pPinnedVidPnSourceModeInfo->PixelValueAccessMode != XddmModePixelVam) )
                {
                    continue;
                }
        }

        // INVARIANT: Current XDDM display mode's target mode parameters can be enumerated on this present path's target.

        // Populate VidPnTargetModeInfo based on the current Xddm display mode's info.
        {
            VidPnTargetModeInfo.VideoStandard         = D3DKMDT_VSS_OTHER;
            VidPnTargetModeInfo.TotalSize.cx          = D3DKMDT_DIMENSION_NOTSPECIFIED;
            VidPnTargetModeInfo.TotalSize.cy          = D3DKMDT_DIMENSION_NOTSPECIFIED;
            VidPnTargetModeInfo.ActiveSize.cx         = pCurrentXddmDisplayMode->VisScreenWidth;
            VidPnTargetModeInfo.ActiveSize.cy         = pCurrentXddmDisplayMode->VisScreenHeight;
            VidPnTargetModeInfo.VSyncFreq.Numerator   = pCurrentXddmDisplayMode->Frequency;
            VidPnTargetModeInfo.VSyncFreq.Denominator = 1;

    //  Production driver should not use D3DKMDT_FREQUENCY_NOTSPECIFIED. It have to provide
    //  appropriate values for HSyncFreq and PixelRate.

            VidPnTargetModeInfo.HSyncFreq.Numerator   = D3DKMDT_FREQUENCY_NOTSPECIFIED;
            VidPnTargetModeInfo.HSyncFreq.Denominator = D3DKMDT_FREQUENCY_NOTSPECIFIED;
            VidPnTargetModeInfo.PixelRate             = D3DKMDT_FREQUENCY_NOTSPECIFIED;

            if ( pCurrentXddmDisplayMode->AttributeFlags & VIDEO_MODE_INTERLACED )
            {
                // NOTE: R200 doesn't distinguish between upper and lower field interlaced modes, so always report upper field.
                VidPnTargetModeInfo.ScanLineOrdering = D3DDDI_VSSLO_INTERLACED_UPPERFIELDFIRST;
            }
            else
            {
                VidPnTargetModeInfo.ScanLineOrdering = D3DDDI_VSSLO_PROGRESSIVE;
            }
        }

        // Add target mode based on the newly created target mode descriptor.
        {
            NTSTATUS ntStatus = AddTargetMode(hTargetModeSet,
                                              pDxgkVidPnTargetModeSetInterface,
                                              &VidPnTargetModeInfo,
                                              NULL,
                                              D3DDDI_ID_UNINITIALIZED,
                                              D3DKMDT_MP_NOTPREFERRED);

            // NOTE: Having OS complain about mode ID uniquess is fine, since this means we are currently
            // processing an XDDM mode whose target mode information subset is identical to one we
            // already processed (e.g. difference is in bits per pixel that is not captured in target mode info).
            ASSERT( NT_SUCCESS(ntStatus) || (ntStatus == STATUS_GRAPHICS_MODE_ALREADY_IN_MODESET) );
        }
    }

    // NOTE: This mode will be rejected on mode change by R200 since it's not in the DAL mode list table.
    //
    // Report NTSC_M as supported mode to test TV mode enumeration.
    //
    do // once
    {
        D3DKMDT_VIDEO_SIGNAL_INFO  VidPnTargetModeInfo = {0};

        // Don't enumerate this mode if present path has an incompatible mode pinned on its source (if any).
        if ( pPinnedVidPnSourceMode )
        {
            CONST D3DKMDT_GRAPHICS_RENDERING_FORMAT*  pPinnedVidPnSourceModeInfo = &(pPinnedVidPnSourceMode->Format.Graphics);

            if ( (pPinnedVidPnSourceModeInfo->PrimSurfSize.cx != 720)
                 ||
                 (pPinnedVidPnSourceModeInfo->PrimSurfSize.cy != 525)
                 ||
                 (pPinnedVidPnSourceModeInfo->PixelFormat != D3DDDIFMT_A8R8G8B8) )
            {
                break;
            }
        }

        // Populate new mode.
        {
            VidPnTargetModeInfo.VideoStandard         = D3DKMDT_VSS_NTSC_M;
            VidPnTargetModeInfo.TotalSize.cx          = 720;
            VidPnTargetModeInfo.TotalSize.cy          = 525;
            VidPnTargetModeInfo.ActiveSize.cx         = 720;
            VidPnTargetModeInfo.ActiveSize.cy         = 525;
            VidPnTargetModeInfo.VSyncFreq.Numerator   = 60000;              // 59.94[Hz]
            VidPnTargetModeInfo.VSyncFreq.Denominator = 1001;
            VidPnTargetModeInfo.HSyncFreq.Numerator   = 1573427;            // 15,734.27[Hz]
            VidPnTargetModeInfo.HSyncFreq.Denominator = 100;
            VidPnTargetModeInfo.PixelRate             = 3579545;            // 3,579,545[Hz]
            VidPnTargetModeInfo.ScanLineOrdering      = D3DDDI_VSSLO_INTERLACED_UPPERFIELDFIRST;
        }

        // Add target mode based on the newly created target mode descriptor.
        {
            NTSTATUS ntStatus = AddTargetMode(hTargetModeSet,
                                              pDxgkVidPnTargetModeSetInterface,
                                              &VidPnTargetModeInfo,
                                              NULL,
                                              D3DDDI_ID_UNINITIALIZED,
                                              D3DKMDT_MP_NOTPREFERRED);

            ASSERT( NT_SUCCESS(ntStatus) );
        }
    }
    while (FALSE);

    // Release resources acquired for population of the target mode set.
    {
        // Release pinned source mode info first (if any).
        if ( pPinnedVidPnSourceMode )
        {
            NTSTATUS ntStatus = pDxgkVidPnSourceModeSetInterface->pfnReleaseModeInfo(hVidPnSourceModeSet,
                                                                                     pPinnedVidPnSourceMode);
            ASSERT( NT_SUCCESS(ntStatus) );
        }

        // Then release the source mode set.
        {
            NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnReleaseSourceModeSet(i_hVidPn,
                                                                               hVidPnSourceModeSet);
            ASSERT( NT_SUCCESS(ntStatus) );
        }
    }

    // INVARIANT: All resources acquired in this function, except for the created target mode set
    //            to be assigned to the specified VidPN target have been released.


    // Assign the newly populated mode set to the specified present path's target, auto-releasing reference to this mode set.
    // NOTE: This substitutes whatever previous cofunctional mode set that was assigned to this target (if any).
    // NOTE: OS will make sure to pin the same mode in the newly assigned mode set that was pinned in the old one.
    {
        NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnAssignTargetModeSet(i_hVidPn,
                                                                          i_VidPnTargetId,
                                                                          hTargetModeSet);

        ASSERT (NT_SUCCESS(ntStatus) );
    }

    return STATUS_SUCCESS;
} // PopulateTargetModeSet_XddmParity function


// Prototypes from dal.h
ULONG
DALGetNumberModesAvailable
(
  HDAL   i_hDal,
  ULONG  i_ulDriverId
);

ULONG
DALGetModesAvailableVMI
(
  HDAL                        i_hDal,
  ULONG                       i_ulDriverId,
  VIDEO_MODE_INFORMATION FAR* p_pXddmDisplayModeSet,
  ULONG                       i_ulModes
);


NTSTATUS
AcquireAvailableXddmDisplayModeSet
(
    CONST HW_DEVICE_EXTENSION*  i_pHwDeviceExtension,
    VIDEO_MODE_INFORMATION**    o_ppXddmDisplayModeSet,
    SIZE_T*                     o_psztNumXddmDisplayModesAcquired
)
{
    SIZE_T                   sztNumXddmDisplayModes         = 0;
    VIDEO_MODE_INFORMATION*  pXddmDisplayModeSet            = NULL;
    HDAL                     hDAL                           = NULL;
    SIZE_T                   sztNumXddmDisplayModesAcquired = 0;

    // Parameter validation (checked-only).
    {
        ASSERT( ARGUMENT_PRESENT(i_pHwDeviceExtension) );
        ASSERT( ARGUMENT_PRESENT(o_ppXddmDisplayModeSet) );
        ASSERT( ARGUMENT_PRESENT(o_psztNumXddmDisplayModesAcquired) );
    }

    // Output parameter initialization.
    {
        *o_ppXddmDisplayModeSet            = NULL;
        *o_psztNumXddmDisplayModesAcquired = 0;
    }

    // Obtain DAL handle from the specified h/w extension.
    hDAL = (HDAL)i_pHwDeviceExtension->pvhDal;

    // Determine number of modes in the XDDM display mode set.
    {
        VIDEO_NUM_MODES*  pVidNumModes = NULL;

        sztNumXddmDisplayModes = DALGetNumberModesAvailable(hDAL, i_pHwDeviceExtension->ulDriverID);

        // Mode set must not be empty (checked-only).
        ASSERT(sztNumXddmDisplayModes != 0);

        if ( sztNumXddmDisplayModes == 0 )
        {
            return STATUS_UNSUCCESSFUL;
        }
    }

    // Allocate memory to hold XDDM display mode set.
    {
        pXddmDisplayModeSet =
            (VIDEO_MODE_INFORMATION*)ExAllocatePoolWithTag(PagedPool,
                                                           sztNumXddmDisplayModes*sizeof(VIDEO_MODE_INFORMATION),
                                                           'R2DM');

        if ( pXddmDisplayModeSet == NULL )
        {
            return STATUS_NO_MEMORY;
        }
    }

    // Acquire the mode set.
    {
        sztNumXddmDisplayModesAcquired = DALGetModesAvailableVMI(hDAL,
                                                                 i_pHwDeviceExtension->ulDriverID,
                                                                 pXddmDisplayModeSet,
                                                                 (ULONG)sztNumXddmDisplayModes);
    }

    // Populate output parameters.
    {
        *o_ppXddmDisplayModeSet            = pXddmDisplayModeSet;
        *o_psztNumXddmDisplayModesAcquired = sztNumXddmDisplayModesAcquired;
    }

    return STATUS_SUCCESS;
}



NTSTATUS
PopulateVidPnPresentPathCofuncModality_XddmParity
(
    CONST HW_DEVICE_EXTENSION*                   i_pHwDeviceExtension,
    CONST D3DKMDT_HVIDPN                         i_hConstrainingVidPn,
    CONST D3DKMDT_VIDPN_PRESENT_PATH* CONST      i_pVidPnPresentPathToEnumModesOn,
    CONST DXGK_VIDPN_INTERFACE* CONST            i_pDxgkVidPnInterface,
    CONST D3DKMDT_ENUMCOFUNCMODALITY_PIVOT_TYPE  i_pEnumPivotType,
    BOOLEAN* CONST                               i_arr_bIsSourceModeSetPopulated
)
/*++
Routine Description:
    Populates cofunctional video present source and target modes for the specified VidPN present path
    in the specified constraining VidPN.

Arguments:
    i_pHwDeviceExtension
      - H/w device extension of this adapter's VidPN source.

    i_hConstrainingVidPn
      - Handle of the VidPN with respect to which enumerated modality must be cofunctional.

    i_pVidPnPresentPathToEnumModesOn
      - Video present path whose modality is being enumerated.

    i_pDxgkVidPnInterface
      - DXGK_VIDPN_INTERFACE interface exposed by Windows Graphics kernel service, using which
        specified VidPN is to be managed.

    i_pEnumPivotType
      - Specifies what is the type of this enumeration's pivot (i.e. owner of a mode set that must not
        be updated, since it is guaranteed by the OS to not have been changed).
        If (i_pEnumPivotType==D3DKMDT_EPT_VIDPNSOURCE) source mode set must not be updated, else
        if (i_pEnumPivotType==D3DKMDT_EPT_VIDPNTARGET) target mode set must not be updated, else
        if (i_pEnumPivotType==D3DKMDT_EPT_NOPIVOT) both source and target mode set need to be updated, if changed.
        No other values are permitted.

    i_arr_bIsSourceModeSetPopulated
      - Progress-tracking predicate vector representing already VidPN source that have already been processed.

Return Value:
    STATUS_SUCCESS
      - Request has been completed successfully.

    STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE
      - Constraining VidPN contains an invalid video present source.

    STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET
      - Constraining VidPN contains an invalid video present target.

    STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED
      - Specified constraining VidPN's modality is not supported.

    STATUS_NO_MEMORY
      - Enough memory could not be allocated for the result set.

Side Effects:
    TBD

Allocation ownership semantics:
    TBD

Remarks:
    If a mode was pinned on the VidPN path's source or target in question, and its mode set changes,
    the index of the pinned mode needs to be updated to point to the same mode in the new cofunctional
    mode set.

Environment:
    Kernel mode. PASSIVE_LEVEL.

--*/
{

    // ASSUMPTION: Let's assume that the supported mode set is static (i.e. not affected by
    //             video memory capacity/bandwidth constraints).

    SIZE_T                   sztNumXddmDisplayModesAcquired = 0;
    VIDEO_MODE_INFORMATION*  pXddmDisplayModeSet            = NULL;
    NTSTATUS                 ntStatus                       = STATUS_SUCCESS;

    // ASSUMPTION: Specified present path is part of the constraining VidPN's topology.

    // Parameter validation (checked-only).
    {
        ASSERT( ARGUMENT_PRESENT(i_pHwDeviceExtension) );
        ASSERT( ARGUMENT_PRESENT(i_hConstrainingVidPn) );
        ASSERT( ARGUMENT_PRESENT(i_pVidPnPresentPathToEnumModesOn) );
    }

    // Acquire the XDDM display mode set for this present path.
    {
        ntStatus = AcquireAvailableXddmDisplayModeSet(i_pHwDeviceExtension,
                                                      &pXddmDisplayModeSet,
                                                      &sztNumXddmDisplayModesAcquired);

        if ( !NT_SUCCESS(ntStatus) )
        {
            return ntStatus;
        }
    }

    // NOTE: VIDEO_MODE_INFORMATION::{X|Y}Millimeter are not used in LDDM. This information is properly obtained from the monitor descriptor.
    //       In Xddm this was a poorly defined parameter, and this driver has always returned (320, 240) irrespective of the connected monitor.

    // Populate cofunctional mode sets of the specified VidPN present path using Xddm mode enumeration.
    {

        do // once
        {
            // First populate target mode set, making sure it is compatible with the respective monitor source mode set.
            if ( i_pEnumPivotType != D3DKMDT_EPT_VIDPNTARGET )
            {
                ntStatus = PopulateTargetModeSet_XddmParity(i_hConstrainingVidPn,
                                                            i_pDxgkVidPnInterface,
                                                            i_pVidPnPresentPathToEnumModesOn->VidPnSourceId,
                                                            i_pVidPnPresentPathToEnumModesOn->VidPnTargetId,
                                                            sztNumXddmDisplayModesAcquired,
                                                            pXddmDisplayModeSet);

                if ( !NT_SUCCESS(ntStatus) )
                {
                    break;
                }


            }

            // Then populate the source mode set cofunctional to the populated target mode set.
            if ( i_pEnumPivotType != D3DKMDT_EPT_VIDPNSOURCE )
            {

                ntStatus = PopulateSourceModeSet_XddmParity(i_hConstrainingVidPn,
                                                            i_pDxgkVidPnInterface,
                                                            i_pVidPnPresentPathToEnumModesOn->VidPnSourceId,
                                                            i_pVidPnPresentPathToEnumModesOn->VidPnTargetId,
                                                            sztNumXddmDisplayModesAcquired,
                                                            pXddmDisplayModeSet,
                                                            i_arr_bIsSourceModeSetPopulated);

                if ( !NT_SUCCESS(ntStatus) )
                {
                    break;
                }
            }
        }
        while (FALSE);

    }

    // Dispose of the temporary XDDM mode set used to produce the respective LDDM source/target mode sets.
    ExFreePool(pXddmDisplayModeSet);

    return ntStatus;

} // PopulateVidPnPresentPathCofuncModality_XddmParity function




NTSTATUS
D3DDDIEnumVidPnCofuncModality_XddmParity
(
    VOID* CONST                                   i_pvInterfaceContext,
    CONST DXGKARG_ENUMVIDPNCOFUNCMODALITY* CONST  i_pEnumVidPnCofuncModalityArg
)
/*++
Routine Description:
    Entry point for EnumVidPnCofuncModality VidPn management query, called from DX Graphics Kernel

Arguments:
    i_pvInterfaceContext
      - Handle to the adapter for which the specified VidPn is to be created.

    i_pEnumVidPnCofuncModalityArg
      - TBD

Return Value:
    STATUS_SUCCESS
      - Request has been completed successfully.

    STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE
      - Constraining VidPn contains an invalid video present source.

    STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET
      - Constraining VidPn contains an invalid video present target.

    STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED
      - Specified constraining VidPn's modality is not supported. (e.g. changes in memory
        bandwidth/capacity constraints might have invalidated previously valid modes).

    STATUS_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED
      - Specified constraining VidPn is not supported (e.g. monitor HPD might have invalidated
        a previously valid topology).

    STATUS_NO_MEMORY
      - Enough memory could not be allocated for the result set.

Side Effects:
    TBD

Allocation ownership semantics:
    TBD

Remarks:
    TBD

Environment:
    Kernel mode. PASSIVE_LEVEL.

--*/
{
    BOOLEAN arr_bIsSourceModeSetPopulated[NUMBER_OF_VIDEO_PRESENT_SOURCES] =
       {
         FALSE,
         FALSE
       };

    return EnumVidPnCofuncModality(i_pvInterfaceContext,
                                   i_pEnumVidPnCofuncModalityArg,
                                   PopulateVidPnPresentPathCofuncModality_XddmParity,
                                   arr_bIsSourceModeSetPopulated);

} // D3DDDIEnumVidPnCofuncModality_XddmParity function





//////////////////////////////////////////////////////
// VidPN (video present network) management methods //
//////////////////////////////////////////////////////

// VidPn constraints for a fictitious display adapter which supports:
// 1. Two video present sources VIDPN_SOURCE1_ID and VIDPN_SOURCE2_ID;
// 2. Two video present targets VIDPN_TARGET1_ID and VIDPN_TARGET2_ID;
// 3. Both sources support mode set {640x480x32, 800x600x32, 1024x768x32};
// 4. Both targets support mode set {VDMT75HZ, VESA900602, VESA901101A};
// 5. H/w scaling is not supported (i.e. spatial resolution on source and target modes must be the same);
// 6. Only one video present path can use (1024x768x32, VESA901101A).


D3DKMDT_GRAPHICS_RENDERING_FORMAT   g_VidPnSourceMode640x480x32
    = {
       {640,480},                                     // PrimSurfSize
       {640,480},                                     // VisibleRegionSize
       2560,                                          // Stride
       D3DDDIFMT_A8R8G8B8,                            // PixelFormat
       D3DKMDT_CB_SRGB,                               // ColorBasis
       D3DKMDT_PVAM_DIRECT};                          // PixelValueAccessMode


D3DKMDT_GRAPHICS_RENDERING_FORMAT   g_VidPnSourceMode800x600x32
    = {
       {800, 600},                                    // PrimSurfSize
       {800, 600},                                    // VisibleRegionSize
       3328,                                          // Stride
       D3DDDIFMT_A8R8G8B8,                            // PixelFormat
       D3DKMDT_CB_SRGB,                               // ColorBasis
       D3DKMDT_PVAM_DIRECT};                          // PixelValueAccessMode


D3DKMDT_GRAPHICS_RENDERING_FORMAT   g_VidPnSourceMode1024x768x8
    = {
       {1024, 768},                                   // PrimSurfSize
       {1024, 768},                                   // VisibleRegionSize
       1024,                                          // Stride
       D3DDDIFMT_P8,                                  // PixelFormat
       D3DKMDT_CB_SRGB,                               // ColorBasis
       D3DKMDT_PVAM_SETTABLEPALETTE};                 // PixelValueAccessMode


D3DKMDT_GRAPHICS_RENDERING_FORMAT   g_VidPnSourceMode1024x768x32
    = {
       {1024, 768},                                   // PrimSurfSize
       {1024, 768},                                   // VisibleRegionSize
       4096,                                          // Stride
       D3DDDIFMT_A8R8G8B8,                            // PixelFormat
       D3DKMDT_CB_SRGB,                               // ColorBasis
       D3DKMDT_PVAM_DIRECT};                          // PixelValueAccessMode


D3DKMDT_VIDEO_SIGNAL_INFO           g_VidPnTargetModeVDMT75HZ
    = {
       D3DKMDT_VSS_VESA_DMT,                          // VideoStandard
       {840, 500},                                    // TotalSize
       {640, 480},                                    // ActiveSize
       {75, 1},                                       // VSyncFreq
       {37500, 1},                                    // HSyncFreq
       31500000,                                      // PixelRate
       D3DDDI_VSSLO_PROGRESSIVE};                     // ScanLineOrdering


D3DKMDT_VIDEO_SIGNAL_INFO           g_VidPnTargetModeVESA900602
    = {
       D3DKMDT_VSS_VESA_DMT,                          // VideoStandard
       {1056, 628},                                   // TotalSize
       {800, 600},                                    // ActiveSize
       {60317, 1000},                                 // VSyncFreq
       {37879, 1},                                    // HSyncFreq
       40000000,                                      // PixelRate
       D3DDDI_VSSLO_PROGRESSIVE};                     // ScanLineOrdering



D3DKMDT_VIDEO_SIGNAL_INFO           g_VidPnTargetModeVESA901101A
    = {
       D3DKMDT_VSS_VESA_DMT,                          // VideoStandard
       {1344, 806},                                   // TotalSize
       {1024, 768},                                   // ActiveSize
       {60004, 1000},                                 // VSyncFreq
       {48363, 1},                                    // HSyncFreq
       65000000,                                      // PixelRate
       D3DDDI_VSSLO_PROGRESSIVE};                     // ScanLineOrdering


SIZE_T g_NumAllVidPnSourceModes[NUMBER_OF_VIDEO_PRESENT_SOURCES] =
   {
     4,
     4
   };

SIZE_T g_NumAllVidPnTargetModes[NUMBER_OF_VIDEO_PRESENT_TARGETS] =
   {
     3,
     3
   };

D3DKMDT_GRAPHICS_RENDERING_FORMAT*  g_AllVidPnSourceModes[NUMBER_OF_VIDEO_PRESENT_SOURCES][4] =
   {
     {&g_VidPnSourceMode640x480x32, &g_VidPnSourceMode800x600x32, &g_VidPnSourceMode1024x768x8, &g_VidPnSourceMode1024x768x32},
     {&g_VidPnSourceMode640x480x32, &g_VidPnSourceMode800x600x32, &g_VidPnSourceMode1024x768x8, &g_VidPnSourceMode1024x768x32}
   };


D3DKMDT_VIDEO_PRESENT_SOURCE_MODE_ID  g_AllVidPnXddmSourceModeId[4] =
    {
        283,    //  640 x 480 x 32 @ 75Hz R200 XDDM display mode index
        207,    //  800 x 600 x 32 @ 60Hz R200 XDDM display mode index
        187,    // 1024 x 768 x  8 @ 60Hz R200 XDDM display mode index
        163     // 1024 x 768 x 32 @ 60Hz R200 XDDM display mode index
    };


D3DKMDT_VIDEO_SIGNAL_INFO*  g_AllVidPnTargetModes[NUMBER_OF_VIDEO_PRESENT_TARGETS][3] =
   {
     {&g_VidPnTargetModeVDMT75HZ, &g_VidPnTargetModeVESA900602, &g_VidPnTargetModeVESA901101A},
     {&g_VidPnTargetModeVDMT75HZ, &g_VidPnTargetModeVESA900602, &g_VidPnTargetModeVESA901101A}
   };



NTSTATUS
D3DDDIIsSupportedVidPn_Test
(
    IN     VOID*                          i_pvInterfaceContext,
    IN OUT DXGKARG_ISSUPPORTEDVIDPN*  io_dmddi_pIsSupportedVidPnArg
)
/*++
Routine Description:
    Entry point for IsSupportedVidPn VidPn management query, called from DX Graphics Kernel

Arguments:
    i_pvInterfaceContext
      - Handle to the adapter for which the specified VidPn is to be created.

    io_dmddi_pIsSupportedVidPnArg
      - TBD

Return Value:
    STATUS_SUCCESS
      - Request has been completed successfully.

    STATUS_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED
      - Specified VidPn topology is not supported by the video card.

    STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY
      - Specified VidPn topology is invalid (e.g. single video present target
        can not point to two video present sources simultaneously, monitor
        must be attached to each target that is part of the topology, etc.).

    STATUS_NO_MEMORY
      - Enough memory could not be allocated for the result set.

    TBD
      - TBD

Side Effects:
    TBD

Allocation ownership semantics:
    TBD

Remarks:
    TBD

Environment:
    Kernel mode. PASSIVE_LEVEL.
--*/
{
    PHW_DEVICE_EXTENSION  pHwDeviceExtension;

    ASSERT( ARGUMENT_PRESENT(i_pvInterfaceContext) );
    ASSERT( ARGUMENT_PRESENT(io_dmddi_pIsSupportedVidPnArg) );
    ASSERT( ARGUMENT_PRESENT(io_dmddi_pIsSupportedVidPnArg->hDesiredVidPn) );

    // Caller must pass adapter's h/w device extension as the interface context
    pHwDeviceExtension = ((PHW_DEVICE_EXTENSION*)i_pvInterfaceContext)[0];

    io_dmddi_pIsSupportedVidPnArg->IsVidPnSupported = TRUE;

    return STATUS_SUCCESS;
}

NTSTATUS
D3DDDIIsSupportedVidPn_XddmParity
(
    IN     VOID*                          i_pvInterfaceContext,
    IN OUT DXGKARG_ISSUPPORTEDVIDPN*      io_dmddi_pIsSupportedVidPnArg
)
/*++
Routine Description:
    Entry point for IsSupportedVidPn VidPn management query, called from DX Graphics Kernel

Arguments:
    i_pvInterfaceContext
      - Handle to the adapter for which the specified VidPn is to be created.

    io_dmddi_pIsSupportedVidPnArg
      - TBD

Return Value:
    STATUS_SUCCESS
      - Request has been completed successfully.

    STATUS_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED
      - Specified VidPn topology is not supported by the video card.

    STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY
      - Specified VidPn topology is invalid (e.g. single video present target
        can not point to two video present sources simultaneously, monitor
        must be attached to each target that is part of the topology, etc.).

    STATUS_NO_MEMORY
      - Enough memory could not be allocated for the result set.

    TBD
      - TBD

Side Effects:
    TBD

Allocation ownership semantics:
    TBD

Remarks:
    TBD

Environment:
    Kernel mode. PASSIVE_LEVEL.

--*/
{
    PHW_DEVICE_EXTENSION  pHwDeviceExtension;

    BOOLEAN arr_bIsSourceModeSetPopulated[NUMBER_OF_VIDEO_PRESENT_SOURCES] =
    {
      FALSE,
      FALSE
    };

    DXGKARG_ENUMVIDPNCOFUNCMODALITY EnumVidPnCofuncModalityArg = {0};

    UINT uiSourceIndex;

    ASSERT( ARGUMENT_PRESENT(i_pvInterfaceContext) );
    ASSERT( ARGUMENT_PRESENT(io_dmddi_pIsSupportedVidPnArg) );
    ASSERT( ARGUMENT_PRESENT(io_dmddi_pIsSupportedVidPnArg->hDesiredVidPn) );

    // Caller must pass adapter's h/w device extension as the interface context
    pHwDeviceExtension = ((PHW_DEVICE_EXTENSION*)i_pvInterfaceContext)[0];

    // Set output parameter to true since we don't have a real test.
    io_dmddi_pIsSupportedVidPnArg->IsVidPnSupported = TRUE;

    return STATUS_SUCCESS;
}

NTSTATUS
AddPresentPath
(
    CONST D3DKMDT_HVIDPNTOPOLOGY                     i_hVidPnTopology,
    CONST DXGK_VIDPNTOPOLOGY_INTERFACE* CONST    i_pDxgkVidPnTopologyInterface,
    CONST D3DDDI_VIDEO_PRESENT_SOURCE_ID             i_SourceId,
    CONST D3DDDI_VIDEO_PRESENT_TARGET_ID             i_TargetId,
    CONST D3DKMDT_VIDPN_PRESENT_PATH_IMPORTANCE      i_ImportanceOrdinal,
    CONST D3DKMDT_VIDPN_PRESENT_PATH_SCALING         i_ContentScaling,
    CONST D3DKMDT_VIDPN_PRESENT_PATH_ROTATION        i_ContentRotation,
    CONST D3DKMDT_VIDPN_PRESENT_PATH_SCALING_SUPPORT i_ContentScalingSupport,
    CONST D3DKMDT_VIDPN_PRESENT_PATH_ROTATION_SUPPORT i_ContentRotationSupport
)
{
    D3DKMDT_VIDPN_PRESENT_PATH*  pVidPnPresentPath = NULL;

    // Create new present path info.
    {
        NTSTATUS ntStatus = i_pDxgkVidPnTopologyInterface->pfnCreateNewPathInfo(i_hVidPnTopology,
                                                                                &pVidPnPresentPath);
        if ( !NT_SUCCESS(ntStatus) )
        {
            return ntStatus;
        }

        ASSERT( ARGUMENT_PRESENT(pVidPnPresentPath) );
    }

    // Populate present path parameters.
    {
        pVidPnPresentPath->VidPnSourceId                                    = i_SourceId;
        pVidPnPresentPath->VidPnTargetId                                    = i_TargetId;
        pVidPnPresentPath->ImportanceOrdinal                                = i_ImportanceOrdinal;
        pVidPnPresentPath->ContentTransformation.Scaling                    = i_ContentScaling;
        pVidPnPresentPath->ContentTransformation.Rotation                   = i_ContentRotation;
     pVidPnPresentPath->ContentTransformation.ScalingSupport         = i_ContentScalingSupport;
     pVidPnPresentPath->ContentTransformation.RotationSupport        = i_ContentRotationSupport;
        pVidPnPresentPath->VisibleFromActiveTLOffset.cx                     = 0;
        pVidPnPresentPath->VisibleFromActiveTLOffset.cy                     = 0;
        pVidPnPresentPath->VisibleFromActiveBROffset.cx                     = 0;
        pVidPnPresentPath->VisibleFromActiveBROffset.cy                     = 0;
        pVidPnPresentPath->VidPnTargetColorBasis                            = D3DKMDT_CB_SRGB;
        pVidPnPresentPath->VidPnTargetColorCoeffDynamicRanges.FirstChannel  = 8;
        pVidPnPresentPath->VidPnTargetColorCoeffDynamicRanges.SecondChannel = 8;
        pVidPnPresentPath->VidPnTargetColorCoeffDynamicRanges.ThirdChannel  = 8;
        pVidPnPresentPath->VidPnTargetColorCoeffDynamicRanges.FourthChannel = 0;
    }

    // Add the path.
    {
        NTSTATUS ntStatus = i_pDxgkVidPnTopologyInterface->pfnAddPath(i_hVidPnTopology,
                                                                      pVidPnPresentPath);
        if ( !NT_SUCCESS(ntStatus) )
        {
            return ntStatus;
        }
    }

    return STATUS_SUCCESS;
}


NTSTATUS
AtiGetChildStatusArrayForHotkey(
    __in  PHW_DEVICE_EXTENSION PrimaryHwDeviceExtension,
    __in  PDESIRED_CHILD_STATUS *pDesiredChildStatus
    )
{
    NTSTATUS Status = STATUS_SUCCESS;
    PDESIRED_CHILD_STATUS pDesiredStatus;
    ULONG ulDisplayMask;
    ULONG ulActiveTargetCount = 0;
    ULONG ulConnectedTargetCount = 0;
    ULONG ulActiveSource;
    PHW_DEVICE_EXTENSION HwDeviceExtension;
    PHW_DEVICE_EXTENSION SecondaryHwDeviceExtension;

    if ((PrimaryHwDeviceExtension == NULL) ||
        (pDesiredChildStatus == NULL))
    {
        return STATUS_INVALID_PARAMETER;
    }

    *pDesiredChildStatus = NULL;

    SecondaryHwDeviceExtension = (PHW_DEVICE_EXTENSION) PrimaryHwDeviceExtension->pvHwOtherDevExt;

    if (PrimaryHwDeviceExtension->ulActiveDisplays > 0)
    {
        //
        // If both sources are already active, then fail the call.
        //
        if (SecondaryHwDeviceExtension->ulActiveDisplays > 0)
        {
            return STATUS_SUCCESS;
        }

        //
        // Primary is active.
        //
        HwDeviceExtension = PrimaryHwDeviceExtension;
        ulActiveSource = 0;
    }
    else
    {
        //
        // Secondary is active, or if not, just default to primary.
        //
        if (SecondaryHwDeviceExtension->ulActiveDisplays > 0)
        {
            HwDeviceExtension = SecondaryHwDeviceExtension;
            ulActiveSource = 1;
        }
        else
        {
            HwDeviceExtension = PrimaryHwDeviceExtension;
            ulActiveSource = 0;
        }
    }

    pDesiredStatus = ExAllocatePoolWithTag(PagedPool,
                                           sizeof(DESIRED_CHILD_STATUS) * HwDeviceExtension->ulNumberDisplays,
                                           ATI_TAG);

    if (pDesiredStatus == NULL)
    {
        return STATUS_NO_MEMORY;
    }

    //
    // This will have a side effect of setting all SourceId to 0, which is what we want for
    // this implementation.
    //
    RtlZeroMemory(pDesiredStatus, sizeof(DESIRED_CHILD_STATUS) * HwDeviceExtension->ulNumberDisplays);

    //
    // Select a monitor based on what's connected and what's active.
    // We cycle between different possible configurations based on what's connected.
    //

    for (ulDisplayMask = 0; ulDisplayMask < HwDeviceExtension->ulNumberDisplays; ulDisplayMask++)
    {
        ULONG ulCurrentDisplay = (1 << ulDisplayMask);

#pragma prefast( disable: __WARNING_POTENTIAL_WRITE_OVERRUN )
        pDesiredStatus[ulDisplayMask].bActive = FALSE;
#pragma prefast( enable: 412 )

        if (HwDeviceExtension->ulConnectedDisplays & ulCurrentDisplay)
        {
            //
            // This monitor is connected... see if it's active.
            //

            if ( HwDeviceExtension->ulActiveDisplays & ulCurrentDisplay )
            {
                //
                // The monitor is active. By default leave it active in the desired configuration.
                //
                ulActiveTargetCount++;
                pDesiredStatus[ulDisplayMask].bActive = TRUE;
            }

            ulConnectedTargetCount++;

        }

        pDesiredStatus[ulDisplayMask].ulSourceId = ulActiveSource;

        //
        // If this is an ACPI adapter then fill in the IDs with the ACPI IDs.
        // Otherwise, use the standard IDs.
        //

        if (HwDeviceExtension->AcpiChildren != NULL)
        {
            if (ulCurrentDisplay & HwDeviceExtension->ulaDisplayTypeVector[DISPLAY_MONITOR])
            {
                pDesiredStatus[ulDisplayMask].ulTargetId = HW_ID_ACPI_MONITOR | HW_ID_DISPLAY_CHILD;
            }
            else if (ulCurrentDisplay & HwDeviceExtension->ulaDisplayTypeVector[DISPLAY_TELEVISION])
            {
                pDesiredStatus[ulDisplayMask].ulTargetId = HW_ID_ACPI_TV | HW_ID_DISPLAY_CHILD;
            }
            else if (ulCurrentDisplay & HwDeviceExtension->ulaDisplayTypeVector[DISPLAY_LCDPANEL])
            {
                pDesiredStatus[ulDisplayMask].ulTargetId = HW_ID_ACPI_FLAT_PANEL | HW_ID_DISPLAY_CHILD;
            }
            else if (ulCurrentDisplay & HwDeviceExtension->ulaDisplayTypeVector[DISPLAY_DIGITALFLATPANEL])
            {
                pDesiredStatus[ulDisplayMask].ulTargetId = HW_ID_ACPI_DIGITAL_FLAT_PANEL | HW_ID_DISPLAY_CHILD;
            }
            else
            {   // Non-ACPI child displays.
                // Mark the display as not active.
                pDesiredStatus[ulDisplayMask].bActive = FALSE;
            }
        }
        else
        {
            pDesiredStatus[ulDisplayMask].ulTargetId = ulDisplayMask | HW_ID_DISPLAY_CHILD;
        }
    }

    //
    // Make sure we have connected targets.
    //

    if (ulConnectedTargetCount == 0)
    {
        ExFreePoolWithTag(pDesiredStatus, ATI_TAG);
        return STATUS_SUCCESS;
    }

    //
    // Check to see if all connected targets are active.
    //
    if (ulActiveTargetCount >= ulConnectedTargetCount)
    {
        //
        // This indicates we should reset all targets to not active, and mark
        // a single target as active.
        //

        BOOL bMarkedActive = FALSE;

        for (ulDisplayMask = 0; ulDisplayMask < HwDeviceExtension->ulNumberDisplays; ulDisplayMask++)
        {
            ULONG ulCurrentDisplay = (1 << ulDisplayMask);

            pDesiredStatus[ulDisplayMask].bActive = FALSE;

            if ((!bMarkedActive) && (HwDeviceExtension->ulConnectedDisplays & ulCurrentDisplay))
            {
                //
                // Mark a single connected target as active.
                //
                pDesiredStatus[ulDisplayMask].bActive = TRUE;
                bMarkedActive = TRUE;
            }

        }
    }
    else
    {
        //
        // This indicates we should cycle to the next configuration.
        //
        BOOL bDeactivateOldTarget = FALSE;
        BOOL bActivateNewTarget = FALSE;

        for (ulDisplayMask = 0; ulDisplayMask < HwDeviceExtension->ulNumberDisplays; ulDisplayMask++)
        {
            ULONG ulCurrentDisplay = (1 << ulDisplayMask);

            if (!bDeactivateOldTarget)
            {
#pragma prefast( disable: __WARNING_POTENTIAL_READ_OVERRUN )
                if (pDesiredStatus[ulDisplayMask].bActive)
                {
                    pDesiredStatus[ulDisplayMask].bActive = FALSE;
                    bDeactivateOldTarget = TRUE;
                }
#pragma prefast( enable: 411 )
            }
            else
            {
                //
                // A target has already been deactivated.
                //
                if (!bActivateNewTarget)
                {
                    if (HwDeviceExtension->ulConnectedDisplays & ulCurrentDisplay)
                    {
                        pDesiredStatus[ulDisplayMask].bActive = TRUE;
                        bActivateNewTarget = TRUE;
                    }
                }
            }

       }

       //
       // Make sure we were able to cycle properly.
       //

       if (!bDeactivateOldTarget || !bActivateNewTarget)
       {
            //
            // If not, just mark all connected displays as active.
            //
            for (ulDisplayMask = 0; ulDisplayMask < HwDeviceExtension->ulNumberDisplays; ulDisplayMask++)
            {
                ULONG ulCurrentDisplay = (1 << ulDisplayMask);

                if (HwDeviceExtension->ulConnectedDisplays & ulCurrentDisplay)
                {
                    pDesiredStatus[ulDisplayMask].bActive = TRUE;
                }
            }
       }
    }

    *pDesiredChildStatus = pDesiredStatus;



    return Status;
}


NTSTATUS
D3DDDIRecommendFunctionalVidPn_XddmParity
(
    VOID* CONST                                    i_pvInterfaceContext,
    CONST DXGKARG_RECOMMENDFUNCTIONALVIDPN* CONST  i_pRecommendFunctionalVidPnArg
)
/*++
Routine Description:
    Entry point for RecommendFunctionalVidPn VidPn management query, called from DX Graphics Kernel.
    Currently only DXGK_RFVR_HOTKEY is implemented. For this reason, we will
    return a topology containing a path contain the source and targets suggested by the
    ACPI query in miniport.c The mode will be a hard-coded 800x600.

Arguments:
    i_pvInterfaceContext
      - Handle to the adapter for which the specified VidPn is to be created.

    i_pRecommendFunctionalVidPnArg
      - Arguments to perform the recommend.

Return Value:
    STATUS_SUCCESS
      - Request has been completed successfully.

    STATUS_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN
      - No VidPn to recommend.

    STATUS_NO_MEMORY
      - Unable to allocate memory.

Side Effects:
    TBD

Allocation ownership semantics:
    TBD

Remarks:
    TBD

Environment:
    Kernel mode. PASSIVE_LEVEL.

--*/
{
    PHW_DEVICE_EXTENSION               pHwDeviceExtension          = NULL;
    D3DKMDT_HVIDPN                     hRecommendedFunctionalVidPn = NULL;
    DXGKRNL_INTERFACE*                 pDxgKrnlCallback            = NULL;
    DXGK_VIDPN_INTERFACE*              pDxgkVidPnInterface         = NULL;
    D3DKMDT_HVIDPNTOPOLOGY             hRecommendedVidPnTopology   = NULL;
    DXGK_VIDPNTOPOLOGY_INTERFACE*      pDxgkVidPnTopologyInterface = NULL;
    BOOL                               bAddedPath                  = FALSE;
    ULONG                              ChildIndex;
    D3DKMDT_VIDPN_PRESENT_PATH_SCALING_SUPPORT ScalingSupport = {0};
    D3DKMDT_VIDPN_PRESENT_PATH_ROTATION_SUPPORT RotationSupport = {0};

    ASSERT( ARGUMENT_PRESENT(i_pvInterfaceContext) );
    ASSERT( ARGUMENT_PRESENT(i_pRecommendFunctionalVidPnArg->hRecommendedFunctionalVidPn) );

    UNREFERENCED_PARAMETER(i_pRecommendFunctionalVidPnArg->NumberOfVidPnTargets);
    UNREFERENCED_PARAMETER(i_pRecommendFunctionalVidPnArg->pVidPnTargetPrioritizationVector);

    // Alias the constraining VidPN for easier access.
    hRecommendedFunctionalVidPn = i_pRecommendFunctionalVidPnArg->hRecommendedFunctionalVidPn;

    // Caller must pass adapter's h/w device extension as the interface context.
    pHwDeviceExtension = ((PHW_DEVICE_EXTENSION*)i_pvInterfaceContext)[0];
    pDxgKrnlCallback = &(pHwDeviceExtension->ddiCallback);

    // Acquire the VidPN object management interface from Windows Graphics Kernel.
    {
        NTSTATUS ntStatus = pDxgKrnlCallback->DxgkCbQueryVidPnInterface(hRecommendedFunctionalVidPn,
                                                                        DXGK_VIDPN_INTERFACE_VERSION_V1,
                                                                        &pDxgkVidPnInterface);
        ASSERT( NT_SUCCESS(ntStatus) );
        ASSERT( ARGUMENT_PRESENT(pDxgkVidPnInterface) );
    }

    // Get topology sub-object of the VidPN object provided to us by the OS.
    {
        NTSTATUS ntStatus = pDxgkVidPnInterface->pfnGetTopology(hRecommendedFunctionalVidPn,
                                                                &hRecommendedVidPnTopology,
                                                                &pDxgkVidPnTopologyInterface);
        ASSERT( NT_SUCCESS(ntStatus) );
        ASSERT( ARGUMENT_PRESENT(hRecommendedVidPnTopology) );
        ASSERT( ARGUMENT_PRESENT(pDxgkVidPnTopologyInterface) );
    }

    // ASSUMPTION: OS should have provided us with an empty topology.

    switch (i_pRecommendFunctionalVidPnArg->RequestReason)
    {
    case DXGK_RFVR_USERMODE:
    #ifdef ENABLE_COMCONTROL
    {
        NTSTATUS ntStatus;
        ULONG Idx =0;
        PDESIRED_CHILD_STATUS pDesiredChildStatus =NULL ;
        if (NULL != i_pRecommendFunctionalVidPnArg->pPrivateDriverData)
        {
            R200_SetTopologyData * pSetTopologyData;
            pSetTopologyData = (R200_SetTopologyData* )i_pRecommendFunctionalVidPnArg->pPrivateDriverData;
            if(pSetTopologyData->dwCode == 1)
            {
                pDesiredChildStatus = ExAllocatePoolWithTag(PagedPool,
                                   sizeof(DESIRED_CHILD_STATUS) * pSetTopologyData->ulCount,
                                   ATI_TAG);

                if (pDesiredChildStatus == NULL)
                {
                    return STATUS_NO_MEMORY;
                }

                 for(Idx =0 ;Idx < pSetTopologyData->ulCount;Idx++) 
                {
                    if(pSetTopologyData->dwMode == 1)
                    {
                        //Set to clone, fo setting to clone all targets must be active
                        pDesiredChildStatus[Idx].bActive = TRUE; 
                    }else
                    {
                            //Set to singleview, only first target will be active
                                        if(Idx == 0)
                                        {               
                                            pDesiredChildStatus[Idx].bActive = TRUE; //Target ID sent is the one we want to make active
                                        }else
                                        {
                                            pDesiredChildStatus[Idx].bActive = FALSE;
                                        }
                                   }
                    pDesiredChildStatus[Idx].ulSourceId =pSetTopologyData->ulCloneSourceID;
                    pDesiredChildStatus[Idx].ulTargetId =pSetTopologyData->pulTargetID[Idx];                    
                    
                }
        
            for (Idx = 0; Idx < pSetTopologyData->ulCount; Idx++)
            {
                if (!pDesiredChildStatus[Idx].bActive)
                {
                    //
                    // This child is not active
                    //

                    continue;

                }

                // Populate the VidPN topology object with the recommended topology.
                {
                    // Add the present path
                    {
                           //Set the scaling/rotation support sets
                           ScalingSupport.Identity = TRUE;
               RotationSupport.Identity = TRUE;
                        ntStatus = AddPresentPath(hRecommendedVidPnTopology,
                                                  pDxgkVidPnTopologyInterface,
                                                  pDesiredChildStatus[Idx].ulSourceId,
                                                  pDesiredChildStatus[Idx].ulTargetId,
                                                  bAddedPath ? D3DKMDT_VPPI_SECONDARY : D3DKMDT_VPPI_PRIMARY,
                                                  D3DKMDT_VPPS_IDENTITY,
                                                  D3DKMDT_VPPR_IDENTITY,
                                                  ScalingSupport,
                                                  RotationSupport
                                                  );
                        ASSERT( NT_SUCCESS(ntStatus) );

                        bAddedPath = TRUE;
                    }
                }

                // Populate VidPN sources and targets with recommended cofunctional mode sets and pinned modes.
                {
                    // Populate mode set of VidPN source
                    {
                        D3DKMDT_HVIDPNSOURCEMODESET             hSourceModeSet                   = NULL;
                        DXGK_VIDPNSOURCEMODESET_INTERFACE*      pDxgkVidPnSourceModeSetInterface = NULL;
                        D3DKMDT_VIDPN_SOURCE_MODE*              pVidPnSourceMode                 = NULL;
                        D3DKMDT_VIDEO_PRESENT_SOURCE_MODE_ID    SourceModeIdToPin                = D3DDDI_ID_UNINITIALIZED;

                        // Create a new source mode set and acquire its handle/interface.
                        {
                            ntStatus = pDxgkVidPnInterface->pfnCreateNewSourceModeSet(hRecommendedFunctionalVidPn,
                                                                                               pDesiredChildStatus[Idx].ulSourceId,
                                                                                               &hSourceModeSet,
                                                                                               &pDxgkVidPnSourceModeSetInterface);
                            ASSERT( NT_SUCCESS(ntStatus) );
                            ASSERT( ARGUMENT_PRESENT(hSourceModeSet) );
                            ASSERT( ARGUMENT_PRESENT(pDxgkVidPnSourceModeSetInterface) );
                        }

                        // Add mode to be pinned.
                        {
                            // Remember the ID of the mode to be pinned (since adding mode will invalidate pVidPnSourceMode).
                            // Sample driver always sets 1024x768x32 mode.                            
                            // Ideally in the production driver this mode should be computed from the capabilities of the source & target(s),
                            // given previously pinned source/targets.
                            //
                            ntStatus = AddSourceMode(hSourceModeSet,
                                                              pDxgkVidPnSourceModeSetInterface,
                                                              &g_VidPnSourceMode1024x768x32,
                                                              &SourceModeIdToPin,
                                                              g_AllVidPnXddmSourceModeId[3]);   // 1024 x 768 x 32 @ 60Hz R200 XDDM display mode index
                            ASSERT( NT_SUCCESS(ntStatus) );
                        }

                        // Pin 1024x768 source mode on source
                        {
                            ntStatus = pDxgkVidPnSourceModeSetInterface->pfnPinMode(hSourceModeSet,
                                                                                             SourceModeIdToPin);
                            ASSERT( NT_SUCCESS(ntStatus) );
                        }

                        // Assign the recommended source cofunctional mode set.
                        {
                            ntStatus = pDxgkVidPnInterface->pfnAssignSourceModeSet(hRecommendedFunctionalVidPn,
                                                                                            pDesiredChildStatus[Idx].ulSourceId,
                                                                                            hSourceModeSet);
                            ASSERT( NT_SUCCESS(ntStatus) );
                        }
                    }

                    // Populate mode set of VidPN target.
                    {
                        D3DKMDT_HVIDPNTARGETMODESET             hTargetModeSet                   = NULL;
                        DXGK_VIDPNTARGETMODESET_INTERFACE*      pDxgkVidPnTargetModeSetInterface = NULL;
                        D3DKMDT_VIDPN_TARGET_MODE*              pVidPnTargetMode                 = NULL;
                        D3DKMDT_VIDEO_PRESENT_TARGET_MODE_ID    TargetModeIdToPin                = D3DDDI_ID_UNINITIALIZED;

                        // Create a new target mode set and acquire its handle/interface.
                        {
                            ntStatus = pDxgkVidPnInterface->pfnCreateNewTargetModeSet(hRecommendedFunctionalVidPn,
                                                                                               pDesiredChildStatus[Idx].ulTargetId,
                                                                                               &hTargetModeSet,
                                                                                               &pDxgkVidPnTargetModeSetInterface);

                            ASSERT( NT_SUCCESS(ntStatus) );
                            ASSERT( ARGUMENT_PRESENT(hTargetModeSet) );
                            ASSERT( ARGUMENT_PRESENT(pDxgkVidPnTargetModeSetInterface) );
                        }

                        // NOTE: We are enumerating only VESA901101A since that is the only mode cofunctional with
                        //       with the source mode of this present path.

                        // Add mode to be pinned.
                        {
                            // Remember the ID of the mode to be pinned (since adding mode will invalidate pVidPnTargetMode).
                            ntStatus = AddTargetMode(hTargetModeSet,
                                                              pDxgkVidPnTargetModeSetInterface,
                                                              &g_VidPnTargetModeVESA901101A,
                                                              &TargetModeIdToPin,
                                                              D3DDDI_ID_UNINITIALIZED,
                                                              D3DKMDT_MP_NOTPREFERRED);
                            ASSERT( NT_SUCCESS(ntStatus) );
                        }

                        // Pin VESA900602 target mode on the target.
                        {
                            ntStatus = pDxgkVidPnTargetModeSetInterface->pfnPinMode(hTargetModeSet,
                                                                                             TargetModeIdToPin);
                            ASSERT( NT_SUCCESS(ntStatus) );
                        }

                        // Assign the recommended target cofunctional mode set.
                        {
                            ntStatus = pDxgkVidPnInterface->pfnAssignTargetModeSet(hRecommendedFunctionalVidPn,
                                                                                            pDesiredChildStatus[Idx].ulTargetId,
                                                                                            hTargetModeSet);
                            ASSERT( NT_SUCCESS(ntStatus) );
                        }
                    }

                }
            }// for

        }

            if(NULL != pDesiredChildStatus)
            {
                ExFreePoolWithTag(pDesiredChildStatus,ATI_TAG);
            }

            return STATUS_SUCCESS;
        }
        return STATUS_SUCCESS;
    }
        break;
        #endif
    case DXGK_RFVR_HOTKEY:
        {
            NTSTATUS ntStatus;
            PDESIRED_CHILD_STATUS pDesiredChildStatus = NULL;

            ntStatus = AtiGetChildStatusArrayForHotkey(pHwDeviceExtension,
                                                       &pDesiredChildStatus);

            if (!NT_SUCCESS(ntStatus))
            {
                return ntStatus;
            }

            if (pDesiredChildStatus == NULL)
            {
                return STATUS_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN;
            }

            //
            // Loop through the child status and for any active ones, we set it up in the VidPn.
            // The mode it recommends will always be 800x600.
            // Ideally this mode should be computed from the capabilities of the source & target(s),
            // given previously pinned source/targets.
            //

            for (ChildIndex = 0; ChildIndex < pHwDeviceExtension->ulNumberDisplays; ChildIndex++)
            {
                if (!pDesiredChildStatus[ChildIndex].bActive)
                {
                    //
                    // This child is not active
                    //

                    continue;

                }

                // Populate the VidPN topology object with the recommended topology.
                {
                    // Add the present path
                    {
                           //Set the scaling/rotation support sets
                           ScalingSupport.Identity = TRUE;
               RotationSupport.Identity = TRUE;

                        ntStatus = AddPresentPath(hRecommendedVidPnTopology,
                                                  pDxgkVidPnTopologyInterface,
                                                  pDesiredChildStatus[ChildIndex].ulSourceId,
                                                  pDesiredChildStatus[ChildIndex].ulTargetId,
                                                  bAddedPath ? D3DKMDT_VPPI_SECONDARY : D3DKMDT_VPPI_PRIMARY,
                                                  D3DKMDT_VPPS_IDENTITY,
                                                  D3DKMDT_VPPR_IDENTITY,
                                                  ScalingSupport,
                                                  RotationSupport);
                        ASSERT( NT_SUCCESS(ntStatus) );

                        bAddedPath = TRUE;
                    }
                }

                // Populate VidPN sources and targets with recommended cofunctional mode sets and pinned modes.
                {
                    // Populate mode set of VidPN source
                    {
                        D3DKMDT_HVIDPNSOURCEMODESET             hSourceModeSet                   = NULL;
                        DXGK_VIDPNSOURCEMODESET_INTERFACE*      pDxgkVidPnSourceModeSetInterface = NULL;
                        D3DKMDT_VIDPN_SOURCE_MODE*              pVidPnSourceMode                 = NULL;
                        D3DKMDT_VIDEO_PRESENT_SOURCE_MODE_ID    SourceModeIdToPin                = D3DDDI_ID_UNINITIALIZED;

                        // Create a new source mode set and acquire its handle/interface.
                        {
                            ntStatus = pDxgkVidPnInterface->pfnCreateNewSourceModeSet(hRecommendedFunctionalVidPn,
                                                                                               pDesiredChildStatus[ChildIndex].ulSourceId,
                                                                                               &hSourceModeSet,
                                                                                               &pDxgkVidPnSourceModeSetInterface);
                            ASSERT( NT_SUCCESS(ntStatus) );
                            ASSERT( ARGUMENT_PRESENT(hSourceModeSet) );
                            ASSERT( ARGUMENT_PRESENT(pDxgkVidPnSourceModeSetInterface) );
                        }

                        // Add mode to be pinned.
                        {
                            // Remember the ID of the mode to be pinned (since adding mode will invalidate pVidPnSourceMode).
                            ntStatus = AddSourceMode(hSourceModeSet,
                                                              pDxgkVidPnSourceModeSetInterface,
                                                              &g_VidPnSourceMode800x600x32,
                                                              &SourceModeIdToPin,
                                                              g_AllVidPnXddmSourceModeId[1]);  // 800x600x32@60Hz R200 XDDM mode index.
                            ASSERT( NT_SUCCESS(ntStatus) );
                        }

                        // Pin 800x600 source mode on source
                        {
                            ntStatus = pDxgkVidPnSourceModeSetInterface->pfnPinMode(hSourceModeSet,
                                                                                             SourceModeIdToPin);
                            ASSERT( NT_SUCCESS(ntStatus) );
                        }

                        // Assign the recommended source cofunctional mode set.
                        {
                            ntStatus = pDxgkVidPnInterface->pfnAssignSourceModeSet(hRecommendedFunctionalVidPn,
                                                                                            pDesiredChildStatus[ChildIndex].ulSourceId,
                                                                                            hSourceModeSet);
                            ASSERT( NT_SUCCESS(ntStatus) );
                        }
                    }

                    // Populate mode set of VidPN target.
                    {
                        D3DKMDT_HVIDPNTARGETMODESET             hTargetModeSet                   = NULL;
                        DXGK_VIDPNTARGETMODESET_INTERFACE*      pDxgkVidPnTargetModeSetInterface = NULL;
                        D3DKMDT_VIDPN_TARGET_MODE*              pVidPnTargetMode                 = NULL;
                        D3DKMDT_VIDEO_PRESENT_TARGET_MODE_ID    TargetModeIdToPin                = D3DDDI_ID_UNINITIALIZED;

                        // Create a new target mode set and acquire its handle/interface.
                        {
                            ntStatus = pDxgkVidPnInterface->pfnCreateNewTargetModeSet(hRecommendedFunctionalVidPn,
                                                                                               pDesiredChildStatus[ChildIndex].ulTargetId,
                                                                                               &hTargetModeSet,
                                                                                               &pDxgkVidPnTargetModeSetInterface);

                            ASSERT( NT_SUCCESS(ntStatus) );
                            ASSERT( ARGUMENT_PRESENT(hTargetModeSet) );
                            ASSERT( ARGUMENT_PRESENT(pDxgkVidPnTargetModeSetInterface) );
                        }

                        // NOTE: We are enumerating only VESA900602 since that is the only mode cofunctional with
                        //       with the source mode of this present path.

                        // Add mode to be pinned.
                        {
                            // Remember the ID of the mode to be pinned (since adding mode will invalidate pVidPnTargetMode).
                            ntStatus = AddTargetMode(hTargetModeSet,
                                                              pDxgkVidPnTargetModeSetInterface,
                                                              &g_VidPnTargetModeVESA900602,
                                                              &TargetModeIdToPin,
                                                              D3DDDI_ID_UNINITIALIZED,
                                                              D3DKMDT_MP_NOTPREFERRED);
                            ASSERT( NT_SUCCESS(ntStatus) );
                        }

                        // Pin VESA900602 target mode on the target.
                        {
                            ntStatus = pDxgkVidPnTargetModeSetInterface->pfnPinMode(hTargetModeSet,
                                                                                             TargetModeIdToPin);
                            ASSERT( NT_SUCCESS(ntStatus) );
                        }

                        // Assign the recommended target cofunctional mode set.
                        {
                            ntStatus = pDxgkVidPnInterface->pfnAssignTargetModeSet(hRecommendedFunctionalVidPn,
                                                                                            pDesiredChildStatus[ChildIndex].ulTargetId,
                                                                                            hTargetModeSet);
                            ASSERT( NT_SUCCESS(ntStatus) );
                        }
                    }

                }
            }// for

            // INVARIANT: Recommended functional VidPN is fully populated.

            if (pDesiredChildStatus != NULL)
            {
                ExFreePoolWithTag(pDesiredChildStatus, ATI_TAG);
            }

            return STATUS_SUCCESS;
        }

    default:
        {
            return STATUS_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN;
        }
    }

}


BOOLEAN
IsVidPnSourceIdValid
(
    IN  D3DDDI_VIDEO_PRESENT_SOURCE_ID  i_VidPnSourceId
)
/*++
Routine Description:
    Predicate determining whether the specified VidPn source ID is valid.

Arguments:
    i_VidPnSourceId
      - Video present source ID whose validity is in question.

Return Value:
    TRUE
      - Specified VidPn source ID is valid

    FALSE
      - Otherwise.

Allocation ownership semantics:
    N/A.

Remarks:
    TBD.

Environment:
    Kernel mode. PASSIVE_LEVEL.

--*/
{

   return  (i_VidPnSourceId == VIDPN_SOURCE1_ID) || (i_VidPnSourceId == VIDPN_SOURCE2_ID);

} // IsVidPnSourceIdValid predicate


BOOLEAN
IsVidPnTargetIdValid
(
    IN  D3DDDI_VIDEO_PRESENT_TARGET_ID  i_VidPnTargetId
)
/*++
Routine Description:
    Predicate determining whether the specified VidPn target ID is valid.

Arguments:
    i_VidPnTargetId - Video present target ID whose validity is in question.

Return Value:
    TRUE  - Specified VidPn target ID is valid
    FALSE - Otherwise.

Allocation ownership semantics:
    N/A.

Remarks:
    TBD.

Environment:
    Kernel mode. PASSIVE_LEVEL.

--*/
{
   //
   // Child Ids is composed with the HW_ID_DISPLAY_CHILD bit
   // and the monitor ID. E.g. 0x10000100.
   //
   return  ((i_VidPnTargetId & HW_ID_DISPLAY_CHILD) > 0);

} // IsVidPnTargetIdValid predicate


BOOLEAN
CompareSpatialResolutions
(
   CONST D3DKMDT_2DREGION* CONST  i_pSize1,
   CONST D3DKMDT_2DREGION* CONST  i_pSize2
)
/*++
Routine Description:
    Compares two VidPn source mode descriptors.

Arguments:
    TBD

Return Value:
    Predicate specifying whether parameters are bit-wise identical.

Allocation ownership semantics:
    Caller must allocate and deallocate both arguments.

Remarks:
    TBD.

Environment:
    Kernel mode. PASSIVE_LEVEL.

--*/
{

   return ( (i_pSize1->cx == i_pSize2->cx)
            &&
            (i_pSize1->cy == i_pSize2->cy) );

} // CompareSpatialResolutions predicate


BOOLEAN
CompareVidPnSourceModes
(
   CONST D3DKMDT_GRAPHICS_RENDERING_FORMAT* CONST  i_pVidPnSourceMode1,
   CONST D3DKMDT_GRAPHICS_RENDERING_FORMAT* CONST  i_pVidPnSourceMode2
)
/*++
Routine Description:
    Compares two VidPn source mode descriptors.

Arguments:
    i_pVidPnSourceMode1
      - Descriptor of the first VidPn source mode.

    i_pVidPnSourceMode2
      - Descriptor of the second VidPn source mode.

Return Value:
    Predicate specifying whether parameters are bit-wise identical.

Allocation ownership semantics:
    Caller must allocate and deallocate both arguments.

Remarks:
    TBD.

Environment:
    Kernel mode. PASSIVE_LEVEL.

--*/
{

   SIZE_T sztEqualPortionLength = RtlCompareMemory((VOID*)i_pVidPnSourceMode1,
                                                   (VOID*)i_pVidPnSourceMode2,
                                                   sizeof(D3DKMDT_GRAPHICS_RENDERING_FORMAT));

   return (sztEqualPortionLength == sizeof(D3DKMDT_GRAPHICS_RENDERING_FORMAT));

} // CompareVidPnSourceModes predicate



BOOLEAN
CompareVidPnTargetModes
(
   CONST D3DKMDT_VIDEO_SIGNAL_INFO* CONST  i_pVidPnTargetMode1,
   CONST D3DKMDT_VIDEO_SIGNAL_INFO* CONST  i_pVidPnTargetMode2
)
/*++
Routine Description:
    Compares two VidPN target mode descriptors.

Arguments:
    i_pVidPnTargetMode1
      - Descriptor of the first VidPn target mode.

    i_pVidPnTargetMode2
      - Descriptor of the second VidPn target mode.

Return Value:
    Predicate specifying whether parameters are bit-wise identical.

Allocation ownership semantics:
    Caller must allocate and deallocate both arguments.

Remarks:
    TBD.

Environment:
    Kernel mode. PASSIVE_LEVEL.

--*/
{

   SIZE_T sztEqualPortionLength = RtlCompareMemory((VOID*)i_pVidPnTargetMode1,
                                                   (VOID*)i_pVidPnTargetMode2,
                                                   sizeof(D3DKMDT_VIDEO_SIGNAL_INFO));

   return (sztEqualPortionLength == sizeof(D3DKMDT_VIDEO_SIGNAL_INFO));

} // CompareVidPnTargetModes predicate



BOOLEAN Is1024x768SourceModeInfo
(
  CONST D3DKMDT_GRAPHICS_RENDERING_FORMAT* CONST  pVidPnSourceModeInfo
)
{

    ASSERT( ARGUMENT_PRESENT(pVidPnSourceModeInfo) );

    if ( (pVidPnSourceModeInfo->PrimSurfSize.cx != 1024)
         ||
         (pVidPnSourceModeInfo->PrimSurfSize.cy != 768) )
    {
        return FALSE;
    }

    return TRUE;

} // Is1024x768SourceModeInfo predicate


BOOLEAN IsVesa901101aTargetMode
(
  CONST D3DKMDT_VIDPN_TARGET_MODE* CONST  pVidPnTargetMode
)
{

    ASSERT( ARGUMENT_PRESENT(pVidPnTargetMode) );

    // Now check the target (if a mode is pinned on it).
    if ( !CompareVidPnTargetModes(&pVidPnTargetMode->VideoSignalInfo, &g_VidPnTargetModeVESA901101A) )
    {
        return FALSE;
    }

    return TRUE;

} // IsVesa901101aTargetMode predicate


BOOLEAN
CompareVidPnPresentPaths
(
    CONST D3DKMDT_VIDPN_PRESENT_PATH* CONST  i_pVidPnPresentPath1,
    CONST D3DKMDT_VIDPN_PRESENT_PATH* CONST  i_pVidPnPresentPath2
)
/*++
Routine Description:
    Compares two VidPN target mode descriptors.

Arguments:
    i_pVidPnTargetMode1
      - Descriptor of the first VidPn target mode.

    i_pVidPnTargetMode2
      - Descriptor of the second VidPn target mode.

Return Value:
    Predicate specifying whether parameters are bit-wise identical.

Side Effects:
    None.

Allocation ownership semantics:
    Caller must allocate and deallocate both arguments.

Remarks:
    TBD.

Environment:
    Kernel mode. PASSIVE_LEVEL.

--*/
{

   SIZE_T sztEqualPortionLength = RtlCompareMemory((VOID*)i_pVidPnPresentPath1,
                                                   (VOID*)i_pVidPnPresentPath2,
                                                   sizeof(D3DKMDT_VIDPN_PRESENT_PATH));

   return (sztEqualPortionLength == sizeof(D3DKMDT_VIDPN_PRESENT_PATH));

} // CompareVidPnPresentPaths predicate


NTSTATUS
Is1024x768PinnedOnAnotherSource
(
  CONST D3DKMDT_HVIDPN                   i_hVidPn,
  CONST D3DDDI_VIDEO_PRESENT_SOURCE_ID   i_VidPnSourceId,
  CONST DXGK_VIDPN_INTERFACE* CONST  i_pDxgkVidPnInterface,
  __out BOOLEAN* CONST                   o_pbResult
)
{
    D3DKMDT_HVIDPNTOPOLOGY                   hVidPnTopology              = NULL;
    CONST DXGK_VIDPNTOPOLOGY_INTERFACE*  pDxgkVidPnTopologyInterface = NULL;
    CONST D3DKMDT_VIDPN_PRESENT_PATH*        pCurrentVidPnPresentPath    = NULL;

    // Set default return value
    *o_pbResult = FALSE;

    i_pDxgkVidPnInterface->pfnGetTopology(i_hVidPn,
                                          &hVidPnTopology,
                                          &pDxgkVidPnTopologyInterface);

    // Get the info of the first path in the topology
    {
        NTSTATUS ntStatus = pDxgkVidPnTopologyInterface->pfnAcquireFirstPathInfo(hVidPnTopology,
                                                                                 &pCurrentVidPnPresentPath);

        if ( !NT_SUCCESS(ntStatus) )
        {
            // The only reason this is expected to fail is a low memory condition in case memory
            // is being allocated for source mode info by the Windows Graphics kernel service.
            ASSERT( ntStatus == STATUS_NO_MEMORY );

            return ntStatus;
        }
    }

    // For each present path in the topology of the constraining VidPN:
    while ( pCurrentVidPnPresentPath && (*o_pbResult == FALSE) )
    {

        // If current path has source different from that specified,
        // determine if 1024x768 is pinned on current path's source.
        if ( pCurrentVidPnPresentPath->VidPnSourceId != i_VidPnSourceId )
        {
            D3DKMDT_HVIDPNSOURCEMODESET                   hVidPnSourceModeSet             = NULL;
            CONST DXGK_VIDPNSOURCEMODESET_INTERFACE*  pDxgVidPnSourceModeSetInterface = NULL;
            D3DKMDT_VIDPN_SOURCE_MODE*                    pPinnedVidPnSourceMode          = NULL;

            // Acquire current path's source mode set.
            {
                NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnAcquireSourceModeSet(i_hVidPn,
                                                                                   pCurrentVidPnPresentPath->VidPnSourceId,
                                                                                       &hVidPnSourceModeSet,
                                                                                       &pDxgVidPnSourceModeSetInterface);
                if( !NT_SUCCESS(ntStatus) )
                {
                    return ntStatus;
                }
            }

            // Acquire pinned mode info.
            {
                NTSTATUS ntStatus = pDxgVidPnSourceModeSetInterface->pfnAcquirePinnedModeInfo(hVidPnSourceModeSet,
                                                                                              &pPinnedVidPnSourceMode);
                if ( ntStatus == STATUS_GRAPHICS_MODE_NOT_PINNED )
                {
                    pPinnedVidPnSourceMode = NULL;
                }
                else if ( !NT_SUCCESS(ntStatus) )
                {
                    // The only reason this is expected to fail is a low memory condition in case memory
                    // is being allocated for source mode info by the Windows Graphics kernel service.
                    ASSERT( ntStatus == STATUS_NO_MEMORY );

                    return ntStatus;
                }
            }

            if ( pPinnedVidPnSourceMode )
            {
                if ( Is1024x768SourceModeInfo(&(pPinnedVidPnSourceMode->Format.Graphics)) )
                {
                    *o_pbResult = TRUE;
                }

                // Release pinned mode info.
                {
                    NTSTATUS ntStatus = pDxgVidPnSourceModeSetInterface->pfnReleaseModeInfo(hVidPnSourceModeSet,
                                                                                            pPinnedVidPnSourceMode);
                    ASSERT( NT_SUCCESS(ntStatus) );
                }
            }

            // Release source mode set.
            {
                NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnReleaseSourceModeSet(i_hVidPn,
                                                                                   hVidPnSourceModeSet);

                ASSERT( NT_SUCCESS(ntStatus) );
            }
        }
        // else skip to the next path.

        // Traverse to the next path in the topology.
        {
            CONST D3DKMDT_VIDPN_PRESENT_PATH*  pNextVidPnPresentPath = NULL;

            // Get the info of the next present path in the topology.
            {
                NTSTATUS ntStatus = pDxgkVidPnTopologyInterface->pfnAcquireNextPathInfo(hVidPnTopology,
                                                                                        pCurrentVidPnPresentPath,
                                                                                        &pNextVidPnPresentPath);

                if ( !NT_SUCCESS(ntStatus) )
                {
                    // The only reason this is expected to fail is a low memory condition in case memory
                    // is being allocated for source mode info by the Windows Graphics kernel service.
                    ASSERT( ntStatus == STATUS_NO_MEMORY );

                    return ntStatus;
                }
            }

            // Release the no longer needed info of the last present path.
            {
                NTSTATUS ntStatus = pDxgkVidPnTopologyInterface->pfnReleasePathInfo(hVidPnTopology,
                                                                                    pCurrentVidPnPresentPath);

                ASSERT( NT_SUCCESS(ntStatus) );
            }

            // Point VidPN topology iterator to the next present path in the topology.
            pCurrentVidPnPresentPath = pNextVidPnPresentPath;
        }
    }

    return STATUS_SUCCESS;

} // Is1024x768PinnedOnAnotherSource predicate


NTSTATUS
IsVesa901101aPinnedOnAnotherTarget
(
  CONST D3DKMDT_HVIDPN                   i_hVidPn,
  CONST D3DDDI_VIDEO_PRESENT_TARGET_ID   i_VidPnTargetId,
  CONST DXGK_VIDPN_INTERFACE* CONST  i_pDxgkVidPnInterface,
  __out BOOLEAN* CONST                   o_pbResult
)
{
    D3DKMDT_HVIDPNTOPOLOGY                   hVidPnTopology              = NULL;
    CONST DXGK_VIDPNTOPOLOGY_INTERFACE*  pDxgkVidPnTopologyInterface = NULL;
    CONST D3DKMDT_VIDPN_PRESENT_PATH*        pCurrentVidPnPresentPath    = NULL;

    // Set default return value
    *o_pbResult = FALSE;

    i_pDxgkVidPnInterface->pfnGetTopology(i_hVidPn,
                                          &hVidPnTopology,
                                          &pDxgkVidPnTopologyInterface);

    // Get the info of the first path in the topology
    {
        NTSTATUS ntStatus = pDxgkVidPnTopologyInterface->pfnAcquireFirstPathInfo(hVidPnTopology,
                                                                                 &pCurrentVidPnPresentPath);

        if ( !NT_SUCCESS(ntStatus) )
        {
            // The only reason this is expected to fail is a low memory condition in case memory
            // is being allocated for target mode info by the Windows Graphics kernel service.
            ASSERT( ntStatus == STATUS_NO_MEMORY );

            return ntStatus;
        }
    }

    // For each present path in the topology of the constraining VidPN:
    while ( pCurrentVidPnPresentPath && (*o_pbResult == FALSE) )
    {
        // If current path has target different from that specified,
        // determine if Vesa901101a is pinned on current path's target.
        if ( pCurrentVidPnPresentPath->VidPnTargetId != i_VidPnTargetId )
        {
            D3DKMDT_HVIDPNTARGETMODESET                   hVidPnTargetModeSet             = NULL;
            CONST DXGK_VIDPNTARGETMODESET_INTERFACE*  pDxgVidPnTargetModeSetInterface = NULL;
            D3DKMDT_VIDPN_TARGET_MODE*                    pPinnedVidPnTargetMode          = NULL;

            // Acquire current path's target mode set.
            {
                NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnAcquireTargetModeSet(i_hVidPn,
                                                                                   pCurrentVidPnPresentPath->VidPnTargetId,
                                                                                   &hVidPnTargetModeSet,
                                                                                   &pDxgVidPnTargetModeSetInterface);
                if( !NT_SUCCESS(ntStatus) )
                {
                    return ntStatus;
                }
            }

            // Acquire pinned mode info.
            {
                NTSTATUS ntStatus = pDxgVidPnTargetModeSetInterface->pfnAcquirePinnedModeInfo(hVidPnTargetModeSet,
                                                                                              &pPinnedVidPnTargetMode);
                if ( ntStatus == STATUS_GRAPHICS_MODE_NOT_PINNED )
                {
                    pPinnedVidPnTargetMode = NULL;
                }
                else if ( !NT_SUCCESS(ntStatus) )
                {
                    // The only reason this is expected to fail is a low memory condition in case memory
                    // is being allocated for target mode info by the Windows Graphics kernel service.
                    ASSERT( ntStatus == STATUS_NO_MEMORY );

                    return ntStatus;
                }
            }

            if ( pPinnedVidPnTargetMode )
            {
                if ( IsVesa901101aTargetMode(pPinnedVidPnTargetMode) )
                {
                    *o_pbResult = TRUE;
                }

                // Release pinned mode info.
                {
                    NTSTATUS ntStatus = pDxgVidPnTargetModeSetInterface->pfnReleaseModeInfo(hVidPnTargetModeSet,
                                                                                            pPinnedVidPnTargetMode);
                    ASSERT( NT_SUCCESS(ntStatus) );
                }
            }

            // Release target mode set.
            {
                NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnReleaseTargetModeSet(i_hVidPn,
                                                                                   hVidPnTargetModeSet);

                ASSERT( NT_SUCCESS(ntStatus) );
            }
        }
        // else skip to the next path.

        // Traverse to the next path in the topology.
        {
            CONST D3DKMDT_VIDPN_PRESENT_PATH*  pNextVidPnPresentPath = NULL;

            // Get the info of the next present path in the topology.
            {
                NTSTATUS ntStatus = pDxgkVidPnTopologyInterface->pfnAcquireNextPathInfo(hVidPnTopology,
                                                                                        pCurrentVidPnPresentPath,
                                                                                        &pNextVidPnPresentPath);

                if ( !NT_SUCCESS(ntStatus) )
                {
                    // The only reason this is expected to fail is a low memory condition in case memory
                    // is being allocated for target mode info by the Windows Graphics kernel service.
                    ASSERT( ntStatus == STATUS_NO_MEMORY );

                    return ntStatus;
                }
            }

            // Release the no longer needed info of the last present path.
            {
                NTSTATUS ntStatus = pDxgkVidPnTopologyInterface->pfnReleasePathInfo(hVidPnTopology,
                                                                                    pCurrentVidPnPresentPath);

                ASSERT( NT_SUCCESS(ntStatus) );
            }

            // Point VidPN topology iterator to the next present path in the topology.
            pCurrentVidPnPresentPath = pNextVidPnPresentPath;
        }
    }

    return STATUS_SUCCESS;

} // IsVesa901101aPinnedOnAnotherTarget predicate


NTSTATUS
DetermineSourceModeSet_Test
(
    CONST D3DKMDT_HVIDPN                            i_hVidPn,
    CONST D3DKMDT_VIDPN_PRESENT_PATH* CONST         i_pVidPnPresentPath,
    CONST DXGK_VIDPN_INTERFACE* CONST               i_pDxgkVidPnInterface,
    __out_bcount(MAX_SOURCE_MODES) BOOLEAN* CONST   o_arr_bSourceModeInclusion,
    CONST SIZE_T                                    i_sztNumSourceModes
)
{
    D3DKMDT_HVIDPNTARGETMODESET                   hVidPnTargetModeSet             = NULL;
    CONST DXGK_VIDPNTARGETMODESET_INTERFACE*  pDxgVidPnTargetModeSetInterface = NULL;
    D3DKMDT_VIDPN_TARGET_MODE*                    pPinnedVidPnTargetModeInfo      = NULL;
    BOOLEAN*                                      pbSourceModeInclusion           = o_arr_bSourceModeInclusion;
    D3DKMDT_VIDEO_PRESENT_SOURCE_MODE_ID          SourceModeId                    = 0;

    // Acquire pinned target mode info (if any).
    {
        // First, acquire respective target mode set.
        {
            NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnAcquireTargetModeSet(i_hVidPn,
                                                                               i_pVidPnPresentPath->VidPnTargetId,
                                                                               &hVidPnTargetModeSet,
                                                                               &pDxgVidPnTargetModeSetInterface);
            if( !NT_SUCCESS(ntStatus) )
            {
                return ntStatus;
            }
        }

        // Then, acquire mode info itself.
        {
            NTSTATUS ntStatus = pDxgVidPnTargetModeSetInterface->pfnAcquirePinnedModeInfo(hVidPnTargetModeSet,
                                                                                          &pPinnedVidPnTargetModeInfo);
            if ( ntStatus == STATUS_GRAPHICS_MODE_NOT_PINNED )
            {
                pPinnedVidPnTargetModeInfo = NULL;
            }
            else if ( !NT_SUCCESS(ntStatus) )
            {
                return ntStatus;
            }
        }
    }

    // Enumerate all the modes, except possibly 1024x768 in case it's already pinned somewhere else.
    for ( SourceModeId = 0;
          SourceModeId < i_sztNumSourceModes && SourceModeId < MAX_SOURCE_MODES;
          ++SourceModeId, ++pbSourceModeInclusion )
    {
        // Alias current source mode's parameters for easier access.
        CONST D3DKMDT_GRAPHICS_RENDERING_FORMAT*  pSourceModeInfo = g_AllVidPnSourceModes[i_pVidPnPresentPath->VidPnSourceId][SourceModeId];


        // Skip the current source mode if enumerating it would invalidate HC1.
        if ( pPinnedVidPnTargetModeInfo
             &&
             !CompareSpatialResolutions(&pPinnedVidPnTargetModeInfo->VideoSignalInfo.ActiveSize,
                                        &g_AllVidPnSourceModes[i_pVidPnPresentPath->VidPnSourceId][SourceModeId]->VisibleRegionSize) )
        {
            // ASSUMPTION: If a mode is already pinned on the target then it does not invalidate HC1 and HC2 because
            //             OS validates each mode it pins by calling miniport's IsSupportedVidPn.

            *pbSourceModeInclusion = FALSE;
            continue;
        }

        // INVARIANT: Enumerating current source mode will not invalidate HC1.

        // Skip the current source mode if enumerating it would invalidate HC2.
        if ( Is1024x768SourceModeInfo(pSourceModeInfo) )
        {
            BOOLEAN  bIs1024x768PinnedOnAnotherSource = FALSE;

            // Determine if 1024x768 is pinned on any other source.
            {
                NTSTATUS ntStatus = Is1024x768PinnedOnAnotherSource(i_hVidPn,
                                                                    i_pVidPnPresentPath->VidPnSourceId,
                                                                    i_pDxgkVidPnInterface,
                                                                    &bIs1024x768PinnedOnAnotherSource);
                if ( !NT_SUCCESS(ntStatus) )
                {
                    return ntStatus;
                }
            }

            if ( bIs1024x768PinnedOnAnotherSource )
            {
                *pbSourceModeInclusion = FALSE;
                continue;
            }
        }

        // INVARIANT: Enumerating current source mode will not invalidate neither HC1 nor HC2.

        // Include current source mode in the enumerated mode set.
        *pbSourceModeInclusion = TRUE;
    }

    // Release pinned target mode info (if previously acquired).
    if ( pPinnedVidPnTargetModeInfo )
    {
        // First, release mode info first.
        {
            NTSTATUS ntStatus = pDxgVidPnTargetModeSetInterface->pfnReleaseModeInfo(hVidPnTargetModeSet,
                                                                                    pPinnedVidPnTargetModeInfo);
            ASSERT( NT_SUCCESS(ntStatus) );
        }

        // Then release the handle to its mode set.
        {
            NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnReleaseTargetModeSet(i_hVidPn,
                                                                               hVidPnTargetModeSet);
            ASSERT( NT_SUCCESS(ntStatus) );
        }
    }

    return STATUS_SUCCESS;

} // DetermineSourceModeSet_Test function


NTSTATUS
DetermineTargetModeSet_Test
(
    CONST D3DKMDT_HVIDPN                            i_hVidPn,
    CONST D3DKMDT_VIDPN_PRESENT_PATH* CONST         i_pVidPnPresentPath,
    CONST DXGK_VIDPN_INTERFACE* CONST               i_pDxgkVidPnInterface,
    __out_bcount(MAX_TARGET_MODES) BOOLEAN* CONST   o_arr_bTargetModeInclusion,
    CONST SIZE_T                                    i_sztNumTargetModes
)
{
    D3DKMDT_HVIDPNSOURCEMODESET                   hVidPnSourceModeSet             = NULL;
    CONST DXGK_VIDPNSOURCEMODESET_INTERFACE*      pDxgVidPnSourceModeSetInterface = NULL;
    D3DKMDT_VIDPN_SOURCE_MODE*                    pPinnedVidPnSourceModeInfo      = NULL;
    BOOLEAN*                                      pbTargetModeInclusion           = o_arr_bTargetModeInclusion;
    D3DKMDT_VIDEO_PRESENT_TARGET_MODE_ID          TargetModeId                    = 0;

    // Acquire pinned source mode info (if any).
    {
        // Acquire path's source mode set.
        {
            NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnAcquireSourceModeSet(i_hVidPn,
                                                                               i_pVidPnPresentPath->VidPnSourceId,
                                                                               &hVidPnSourceModeSet,
                                                                               &pDxgVidPnSourceModeSetInterface);
            if( !NT_SUCCESS(ntStatus) )
            {
                return ntStatus;
            }
        }

        // Acquire pinned mode info.
        {
            NTSTATUS ntStatus = pDxgVidPnSourceModeSetInterface->pfnAcquirePinnedModeInfo(hVidPnSourceModeSet,
                                                                                          &pPinnedVidPnSourceModeInfo);
            if ( ntStatus == STATUS_GRAPHICS_MODE_NOT_PINNED )
            {
                pPinnedVidPnSourceModeInfo = NULL;
            }
            else if ( !NT_SUCCESS(ntStatus) )
            {
                return ntStatus;
            }
        }
    }

    // If a mode is pinned on the source
    if ( pPinnedVidPnSourceModeInfo )
    {
        ASSERT( pPinnedVidPnSourceModeInfo->Type == D3DKMDT_RMT_GRAPHICS );

        // Enumerate only modes with matching spatial resolution on the target (see HC1).
        {
            for ( TargetModeId = 0;
                  TargetModeId < i_sztNumTargetModes && TargetModeId < MAX_TARGET_MODES;
                  ++TargetModeId, ++pbTargetModeInclusion )
            {
                // ASSUMPTION: If a mode is pinned it's assumed it does not invalidate HC1 and HC2 because
                //             OS validates each mode it pins by calling miniport's IsSupportedVidPn.

                if ( CompareSpatialResolutions(&pPinnedVidPnSourceModeInfo->Format.Graphics.VisibleRegionSize,
                                               &g_AllVidPnTargetModes[i_pVidPnPresentPath->VidPnTargetId & ~HW_ID_DISPLAY_CHILD][TargetModeId]->ActiveSize) )
                {
                    *pbTargetModeInclusion = TRUE;
                }
            }
        }
        // Release pinned mode info.
        {
            NTSTATUS ntStatus = pDxgVidPnSourceModeSetInterface->pfnReleaseModeInfo(hVidPnSourceModeSet,
                                                                                    pPinnedVidPnSourceModeInfo);
            ASSERT( NT_SUCCESS(ntStatus) );
        }

        // Release acquired source mode set.
        {
            NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnReleaseSourceModeSet(i_hVidPn,
                                                                               hVidPnSourceModeSet);
            ASSERT( NT_SUCCESS(ntStatus) );
        }
    }
    else // if no mode is pinned on the target
    {
        // Enumerate all the modes, except possibly VESA901101A in case it's already pinned somewhere else.
        for ( TargetModeId = 0;
              TargetModeId < i_sztNumTargetModes && TargetModeId < MAX_TARGET_MODES;
              ++TargetModeId, ++pbTargetModeInclusion )
        {
            D3DKMDT_VIDEO_SIGNAL_INFO*  pTargetModeInfo = g_AllVidPnTargetModes[i_pVidPnPresentPath->VidPnTargetId & ~HW_ID_DISPLAY_CHILD][TargetModeId];

            if ( !CompareVidPnTargetModes(pTargetModeInfo, &g_VidPnTargetModeVESA901101A) )
            {
                *pbTargetModeInclusion = TRUE;
            }
            else // if current mode is VESA901101A
            {
                BOOLEAN bIsVesa901101aPinnedOnAnotherTarget = FALSE;

                // Determine if VESA901101A is pinned on any other source.
                {
                    NTSTATUS ntStatus = IsVesa901101aPinnedOnAnotherTarget(i_hVidPn,
                                                                           i_pVidPnPresentPath->VidPnTargetId,
                                                                           i_pDxgkVidPnInterface,
                                                                           &bIsVesa901101aPinnedOnAnotherTarget);
                    if ( !NT_SUCCESS(ntStatus) )
                    {
                        return ntStatus;
                    }
                }

                if ( !bIsVesa901101aPinnedOnAnotherTarget )
                {
                    *pbTargetModeInclusion = TRUE;
                }
                // else don't enumerate VESA901101A on this path's target (see HC2).
            }
        }
    }

    return STATUS_SUCCESS;

} // DetermineTargetModeSet_Test function


NTSTATUS
PopulateSourceModeSet_Test
(
    CONST D3DKMDT_HVIDPN                   i_hVidPn,
    CONST DXGK_VIDPN_INTERFACE* CONST      i_pDxgkVidPnInterface,
    CONST D3DDDI_VIDEO_PRESENT_SOURCE_ID   i_VidPnSourceId,
    CONST BOOLEAN* CONST                   i_arr_bSourceModesToEnum,
    BOOLEAN* CONST                         i_arr_bIsSourceModeSetPopulated
)
{

    D3DKMDT_HVIDPNSOURCEMODESET               hSourceModeSet                   = NULL;
    CONST DXGK_VIDPNSOURCEMODESET_INTERFACE*  pDxgkVidPnSourceModeSetInterface = NULL;

    // Make sure we didn't populate this source's mode set already (i.e. clone-view).
    if ( !i_arr_bIsSourceModeSetPopulated[i_VidPnSourceId] )
    {
        D3DKMDT_VIDEO_PRESENT_SOURCE_MODE_ID SourceModeIndex = 0;

        // Create a new source mode set.
        {
            NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnCreateNewSourceModeSet(i_hVidPn,
                                                                                 i_VidPnSourceId,
                                                                                 &hSourceModeSet,
                                                                                 &pDxgkVidPnSourceModeSetInterface);
            ASSERT( NT_SUCCESS(ntStatus) );
            ASSERT( ARGUMENT_PRESENT(hSourceModeSet) );
            ASSERT( ARGUMENT_PRESENT(pDxgkVidPnSourceModeSetInterface) );
        }

        // For each mode to be added to the source mode set:
        for ( SourceModeIndex = 0;
              SourceModeIndex < g_NumAllVidPnSourceModes[i_VidPnSourceId];
              ++SourceModeIndex )
        {
            if ( i_arr_bSourceModesToEnum[SourceModeIndex] )
            {
                NTSTATUS ntStatus = AddSourceMode(hSourceModeSet,
                                                  pDxgkVidPnSourceModeSetInterface,
                                                  g_AllVidPnSourceModes[i_VidPnSourceId][SourceModeIndex],
                                                  NULL,
                                                  g_AllVidPnXddmSourceModeId[SourceModeIndex]);  // R200 Xddm mode index.
                ASSERT( NT_SUCCESS(ntStatus) );
            }
            // else this mode won't be enumerated.
        }

        // Assign the newly populated mode set to the specified present path's source.
        // NOTE: This substitutes whatever previous cofunctional mode set that was assigned to this source (if any).
        // NOTE: OS will make sure to pin the same mode in the newly assigned mode set that was pinned in the old one.
        {
            NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnAssignSourceModeSet(i_hVidPn,
                                                                              i_VidPnSourceId,
                                                                              hSourceModeSet);
            ASSERT( NT_SUCCESS(ntStatus) );
        }

        // Mark specified present path's source as processed to make sure we don't try to populate it again
        // in case of topologies with clone-view associations.
        i_arr_bIsSourceModeSetPopulated[i_VidPnSourceId] = TRUE;
    }
    else
    {
        // INVARIANT: Mode set on this source has already been populated because this source is
        //            shared between two (or more) paths in a clone-view association.
    }

    return STATUS_SUCCESS;

} // PopulateSourceModeSet_Test function



NTSTATUS
PopulateTargetModeSet_Test
(
    CONST D3DKMDT_HVIDPN                   i_hVidPn,
    CONST DXGK_VIDPN_INTERFACE* CONST      i_pDxgkVidPnInterface,
    CONST D3DDDI_VIDEO_PRESENT_TARGET_ID   i_VidPnTargetId,
    CONST BOOLEAN* CONST                   i_arr_bTargetModesToEnum
)
{

    D3DKMDT_HVIDPNTARGETMODESET               hTargetModeSet                   = NULL;
    CONST DXGK_VIDPNTARGETMODESET_INTERFACE*  pDxgkVidPnTargetModeSetInterface = NULL;

    D3DKMDT_VIDEO_PRESENT_TARGET_MODE_ID TargetModeIndex = 0;

    // NOTE: There is no way we can revisit the same target twice by enumerating over each of the present paths
    //       in VidPN's topology once, so we don't maintain a progress table for targets.

    // Create a new target mode set.
    {
        NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnCreateNewTargetModeSet(i_hVidPn,
                                                                             i_VidPnTargetId,
                                                                             &hTargetModeSet,
                                                                             &pDxgkVidPnTargetModeSetInterface);
        ASSERT( NT_SUCCESS(ntStatus) );
        ASSERT( ARGUMENT_PRESENT(hTargetModeSet) );
        ASSERT( ARGUMENT_PRESENT(pDxgkVidPnTargetModeSetInterface) );
    }

    // For each mode to be added to the target mode set:
    for ( TargetModeIndex = 0;
          TargetModeIndex < g_NumAllVidPnTargetModes[i_VidPnTargetId & ~HW_ID_DISPLAY_CHILD];
          ++TargetModeIndex )
    {
        if ( i_arr_bTargetModesToEnum[TargetModeIndex] )
        {
            // Remember the ID of the mode to be pinned (since adding mode will invalidate pVidPnTargetMode).
            NTSTATUS ntStatus = AddTargetMode(hTargetModeSet,
                                              pDxgkVidPnTargetModeSetInterface,
                                              g_AllVidPnTargetModes[i_VidPnTargetId & ~HW_ID_DISPLAY_CHILD][TargetModeIndex],
                                              NULL,
                                              D3DDDI_ID_UNINITIALIZED,
                                              D3DKMDT_MP_NOTPREFERRED);
            ASSERT( NT_SUCCESS(ntStatus) );
        }
        // else this mode won't be enumerated.
    }

    // Assign the newly populated mode set to the specified present path's target.
    // NOTE: This substitutes whatever previous cofunctional mode set that was assigned to this target (if any).
    // NOTE: OS will make sure to pin the same mode in the newly assigned mode set that was pinned in the old one.
    {
        NTSTATUS ntStatus = i_pDxgkVidPnInterface->pfnAssignTargetModeSet(i_hVidPn,
                                                                          i_VidPnTargetId,
                                                                          hTargetModeSet);
        ASSERT( NT_SUCCESS(ntStatus) );
    }

    return STATUS_SUCCESS;

} // PopulateTargetModeSet_Test function





NTSTATUS
PopulateVidPnPresentPathCofuncModality_Test
(
    CONST HW_DEVICE_EXTENSION*                   i_pHwDeviceExtension,
    CONST D3DKMDT_HVIDPN                         i_hConstrainingVidPn,
    CONST D3DKMDT_VIDPN_PRESENT_PATH* CONST      i_pVidPnPresentPathToEnumModesOn,
    CONST DXGK_VIDPN_INTERFACE* CONST        i_pDxgkVidPnInterface,
    CONST D3DKMDT_ENUMCOFUNCMODALITY_PIVOT_TYPE  i_pEnumPivotType,
    BOOLEAN* CONST                               i_arr_bIsSourceModeSetPopulated
)
/*++
Routine Description:
    Populates cofunctional video present source and target modes for the specified VidPN present path
    in the specified constraining VidPN.

Arguments:
    i_pHwDeviceExtension
      - H/w device extension of this adapter's VidPN source.

    i_hConstrainingVidPn
      - Handle of the VidPN with respect to which enumerated modality must be cofunctional.

    i_pVidPnPresentPathToEnumModesOn
      - Video present path whose modality is being enumerated.

    i_pDxgkVidPnInterface
      - DXGK_VIDPN_INTERFACE interface exposed by Windows Graphics kernel service, using which
        specified VidPN is to be managed.

    i_pEnumPivotType
      - Specifies what is the type of this enumeration's pivot (i.e. owner of a mode set that must not
        be updated, since it is guaranteed by the OS to not have been changed).
        If (i_pEnumPivotType==D3DKMDT_EPT_VIDPNSOURCE) source mode set must not be updated, else
        if (i_pEnumPivotType==D3DKMDT_EPT_VIDPNTARGET) target mode set must not be updated, else
        if (i_pEnumPivotType==D3DKMDT_EPT_NOPIVOT) both source and target mode set need to be updated, if changed.
        No other values are permitted.

    i_arr_bIsSourceModeSetPopulated
      - Progress-tracking predicate vector representing already VidPN source that have already been processed.

Return Value:
    STATUS_SUCCESS
      - Request has been completed successfully.

    STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE
      - Constraining VidPn contains an invalid video present source.

    STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET
      - Constraining VidPn contains an invalid video present target.

    STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED
      - Specified constraining VidPn's modality is not supported.

    STATUS_NO_MEMORY
      - Enough memory could not be allocated for the result set.

Side Effects:
    TBD

Allocation ownership semantics:
    TBD

Remarks:
    If a mode was pinned on the VidPn path's source or target in question, and its mode set changes,
    the index of the pinned mode needs to be updated to point to the same mode in the new cofunctional
    mode set.

Environment:
    Kernel mode. PASSIVE_LEVEL.

--*/
{

    // ASSUMPTION: Let's assume that the supported mode set is static (i.e. not affected by
    //             video memory capacity/bandwidth constraints).

    // ASSUMPTION: Our only constraints on the supported mode sets here will be that:
    //              HC1. H/w scaling is not supported (i.e. spatial resolution on source and target
    //                   modes must be the same);
    //              HC2. Only one video present path can use (1024x768x32, VESA901101A) source/target
    //                   modes.

    // ASSUMPTION: Specified VidPN path is part of the constraining VidPN's topology.

    BOOLEAN  bEnum1024x768x32_VESA901101A = TRUE;
    BOOLEAN  arr_bSourceModesToEnum[MAX_SOURCE_MODES]    = {FALSE, FALSE, FALSE};   // assumes max of 3 modes on a source.
    BOOLEAN  arr_bTargetModesToEnum[MAX_TARGET_MODES]    = {FALSE, FALSE, FALSE};   // assumes max of 3 modes on a target.

    // Parameter validation (checked-only)
    {
        ASSERT( ARGUMENT_PRESENT(i_hConstrainingVidPn) );
        ASSERT( ARGUMENT_PRESENT(i_pVidPnPresentPathToEnumModesOn) );
    }

    // (1) Determine what mode(s) to enumerate on the source and target of the specified present path.
    //     and store them in "to-enumerate" predicate vectors.
    {
        // (1.1) First determine the source mode set
        {
            NTSTATUS ntStatus = DetermineSourceModeSet_Test(i_hConstrainingVidPn,
                                                           i_pVidPnPresentPathToEnumModesOn,
                                                           i_pDxgkVidPnInterface,
                                                           arr_bSourceModesToEnum,
                                                           g_NumAllVidPnSourceModes[i_pVidPnPresentPathToEnumModesOn->VidPnSourceId]);

            if( !NT_SUCCESS(ntStatus) )
            {
                return ntStatus;
            }
        }

        // (1.2) Then determine the target mode set
        {
            NTSTATUS ntStatus = DetermineTargetModeSet_Test(i_hConstrainingVidPn,
                                                           i_pVidPnPresentPathToEnumModesOn,
                                                           i_pDxgkVidPnInterface,
                                                           arr_bTargetModesToEnum,
                                                           g_NumAllVidPnTargetModes[i_pVidPnPresentPathToEnumModesOn->VidPnTargetId & ~HW_ID_DISPLAY_CHILD]);
            if( !NT_SUCCESS(ntStatus) )
            {
                return ntStatus;
            }
        }
    }


    // NOTE: In a real driver handling this request from the OS, at this point in the control flow, the driver
    //       would have prepared a cofunctional mode set for each source/target in the VidPN's topology, using
    //       memorhy bandwidth and capacity calculations, as well as video output codec routing restrictions.
    //       In this sample, we just rely on a hard-coded mode set, making sure to comply with the fictitious
    //       constraints defined above.

    // (2) Populate cofunctional mode sets of the specified VidPN present path.
    {
        // (2.1) First handle the source.
        if ( i_pEnumPivotType != D3DKMDT_EPT_VIDPNSOURCE )
        {
            NTSTATUS ntStatus = PopulateSourceModeSet_Test(i_hConstrainingVidPn,
                                                           i_pDxgkVidPnInterface,
                                                           i_pVidPnPresentPathToEnumModesOn->VidPnSourceId,
                                                           arr_bSourceModesToEnum,
                                                           i_arr_bIsSourceModeSetPopulated);

            if ( !NT_SUCCESS(ntStatus) )
            {
                return ntStatus;
            }
        }

        // (2.2) Then the target
        if ( i_pEnumPivotType != D3DKMDT_EPT_VIDPNTARGET )
        {
            NTSTATUS ntStatus = PopulateTargetModeSet_Test(i_hConstrainingVidPn,
                                                           i_pDxgkVidPnInterface,
                                                           i_pVidPnPresentPathToEnumModesOn->VidPnTargetId,
                                                           arr_bTargetModesToEnum);

            if ( !NT_SUCCESS(ntStatus) )
            {
                return ntStatus;
            }
        }
    }

    return STATUS_SUCCESS;

} // PopulateVidPnPresentPathCofuncModality_Test function

NTSTATUS
D3DDDIEnumVidPnCofuncModality_Test
(
    VOID* CONST                                       i_pvInterfaceContext,
    CONST DXGKARG_ENUMVIDPNCOFUNCMODALITY* CONST  i_pEnumVidPnCofuncModalityArg
)
/*++
Routine Description:
    Entry point for EnumVidPnCofuncModality VidPn management query, called from DX Graphics Kernel

Arguments:
    i_pvInterfaceContext
      - Handle to the adapter for which the specified VidPn is to be created.

    i_pEnumVidPnCofuncModalityArg
      - TBD

Return Value:
    STATUS_SUCCESS
      - Request has been completed successfully.

    STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE
      - Constraining VidPn contains an invalid video present source.

    STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET
      - Constraining VidPn contains an invalid video present target.

    STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED
      - Specified constraining VidPn's modality is not supported. (e.g. changes in memory
        bandwidth/capacity constraints might have invalidated previously valid modes).

    STATUS_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED
      - Specified constraining VidPn is not supported (e.g. monitor HPD might have invalidated
        a previously valid topology).

    STATUS_NO_MEMORY
      - Enough memory could not be allocated for the result set.

Side Effects:
    TBD

Allocation ownership semantics:
    TBD

Remarks:
    TBD

Environment:
    Kernel mode. PASSIVE_LEVEL.

--*/
{
    BOOLEAN arr_bIsSourceModeSetPopulated[NUMBER_OF_VIDEO_PRESENT_SOURCES] =
       {
         FALSE,
         FALSE
       };

    return EnumVidPnCofuncModality(i_pvInterfaceContext,
                                   i_pEnumVidPnCofuncModalityArg,
                                   PopulateVidPnPresentPathCofuncModality_Test,
                                   arr_bIsSourceModeSetPopulated);

} // D3DDDIEnumVidPnCofuncModality_Test function


//
// Initialize QS/CMM stuff
//
NTSTATUS InitRingBuffer(PHW_DEVICE_EXTENSION pHwDeviceExtension)
{
    BOOLEAN rOk;

    //
    // Enable bus mastering before initializing PM4.
    // Assume AGP is available
    //
    SetPciAgpState(pHwDeviceExtension);

    //
    // Initialize PM4 ring
    //
    pHwDeviceExtension->pQs = QS_Initialize(
                                    pHwDeviceExtension->ulChipFamily,
                                    pHwDeviceExtension->usDeviceId,
                                    pHwDeviceExtension->ucRevision,
                                    pHwDeviceExtension,
                                    pHwDeviceExtension->pPrivateBuffers);
    ASSERT(pHwDeviceExtension->pQs != NULL);

    // No local memory was actually reserved for CMM...
    pHwDeviceExtension->ulVRamSizeAvailable = 0;

    // Enable interrupts but avoid generating interrupts for dummy submissions with incorrect fence...
    uQSSynchronize(pHwDeviceExtension->pQs);

    pHwDeviceExtension->pfn_bAsicPM4InterruptAck(pHwDeviceExtension);
    rOk = AtiDMAInterrupt_enable(pHwDeviceExtension, pHwDeviceExtension->dwIRQSource);
    ASSERT(rOk);

    if (rOk == FALSE)
    {
        return STATUS_UNSUCCESSFUL;
    }

    return STATUS_SUCCESS;
}

NTSTATUS
D3DDDIOpenAllocation(
    VOID                                *InterfaceContext,
    CONST DXGKARG_OPENALLOCATION    *pDDIDAData)
{
    DWORD dwIdx;
    DXGKRNL_INTERFACE              *pCallback;
    PR2D3DDevice                    pR2D3DDev;
    PHW_DEVICE_EXTENSION            pAdapter;

    pR2D3DDev = (PR2D3DDevice)InterfaceContext;
    pAdapter  = (PHW_DEVICE_EXTENSION)pR2D3DDev->pAdapter;
    pCallback = &(pAdapter->ddiCallback);

    for (dwIdx=0; dwIdx < pDDIDAData->NumAllocations; dwIdx++)
    {
        DXGKARGCB_GETHANDLEDATA         getHandleData = {0};
        R2AllocationInfo*                pAllocInfo;

        getHandleData.hObject = pDDIDAData->pOpenAllocation[dwIdx].hAllocation;
        getHandleData.Type    = DXGK_HANDLE_ALLOCATION;
        pAllocInfo = (PR2AllocationInfo)pCallback->DxgkCbGetHandleData(&getHandleData);
        pDDIDAData->pOpenAllocation[dwIdx].hDeviceSpecificAllocation = (HANDLE)pAllocInfo;
        pAllocInfo->vidMemData.hAllocation = pDDIDAData->pOpenAllocation[dwIdx].hAllocation;
    }

    return STATUS_SUCCESS;
}

VOID
D3DDDIControlEtwLogging(
    IN BOOLEAN Enable,
    IN ULONG Flags,
    IN UCHAR Level
    )
{
    gLoggingEnabled = Enable;
    gLoggingFlags = Flags;
    gLoggingLevel = Level;
}

VOID
DummyTrace(
    HW_DEVICE_EXTENSION* Adapter
    )
{
    //
    // Ask dxgkrnl to to log the event with the event logger.
    //

    Adapter->ddiCallback.DxgkCbLogEtwEvent(&R200_DUMMY_LOGGING,
                                           EVENT_TRACE_TYPE_INFO,
                                           0,
                                           NULL);
}

NTSTATUS PresentPreRenderCmdBufProcessing(DXGKARG_RENDER* pRenderArg, D3DKMT_HANDLE hSrc, D3DKMT_HANDLE hDst)
{
    DWORD   *pPM4Buf, *pPM4BufEnd, *pCurPM4Packet;
    DWORD   dwPM4PacketSize, dwPM4PacketHeader;
    DWORD   dwPM4RegCount;
    DWORD   dwOpCode;
    DWORD   dwCurAllocationListIdx=0;   //Idx of next slot to use

    pPM4Buf = (PDWORD)pRenderArg->pCommand;
    pPM4BufEnd = (PDWORD)((PBYTE)pPM4Buf + pRenderArg->CommandLength);
    pCurPM4Packet = pPM4Buf;

    do
    {
        //
        // dwPM4PacketSize of -1 indicates wrongly formated PM4 packet
        //
        dwPM4PacketSize = -1;

        dwPM4PacketHeader = *pCurPM4Packet;
        switch (dwPM4PacketHeader >> 30)
        {
        case 0:
            dwPM4RegCount = ((dwPM4PacketHeader & 0x3FFF0000) >> 16) + 1;
            dwPM4PacketSize = 1 + dwPM4RegCount;
            break;

        case 1:
        case 2:
            dwPM4PacketSize = -1;
            break;

        case 3:
            //
            // Calculate the size of the type 3 packet
            //
            dwPM4PacketSize = ((dwPM4PacketHeader & 0x3FFF0000) >> 16) + 2;
            dwOpCode = (dwPM4PacketHeader & (0xFF00)) >> 8;

            if (dwOpCode == GetType3OpCode(PM4_PACKET3_NOP))
            {
                D3DResourceID   d3dResID = (D3DResourceID)(dwPM4PacketHeader & 0xFF);
                D3DKMT_HANDLE   hNew = *(D3DKMT_HANDLE *)(pCurPM4Packet + 1);
                DWORD           dwIdx;

                if (d3dResID < D3D_RES_ALL)
                {
                    if (hNew == hSrc)
                    {
                        dwIdx = DXGK_PRESENT_SOURCE_INDEX;
                    }
                    else if (hNew == hDst)
                    {
                        dwIdx = DXGK_PRESENT_DESTINATION_INDEX;
                    }
                    else
                    {
                        DBG_BREAK;
                        return STATUS_ILLEGAL_INSTRUCTION;
                    }

                    // We overload the PM4 type 3 NOP packet count field with the Allocation list Idx, KM driver
                    // can place the correct count value into the packet header during Render as all the handle NOP
                    // packets are the same size
                    *pCurPM4Packet = (dwPM4PacketHeader & ~0x3FFF0000) + (dwIdx << 16);
                }
            }

            break;
        default:
            DBG_BREAK;
            return STATUS_ILLEGAL_INSTRUCTION;
        }

        if (dwPM4PacketSize == -1)
        {
            DBG_BREAK;
            return STATUS_ILLEGAL_INSTRUCTION;
        }

        //
        // Move on to the next PM4 packet
        //
        pCurPM4Packet += dwPM4PacketSize;

    }while (pCurPM4Packet < pPM4BufEnd);

    return STATUS_SUCCESS;
}

NTSTATUS
D3DDDICloseAllocation(
    HANDLE                              hDevice,
    CONST DXGKARG_CLOSEALLOCATION  *pDDICAData)
{
    return STATUS_SUCCESS;
}



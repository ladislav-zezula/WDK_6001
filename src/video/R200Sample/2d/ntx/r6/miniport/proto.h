

/*****************************************************************************\
*
*  Module Name    PROTO.H
*  Project        Longhorn
*  Device         R200
*
*  Description    Contains all function prototypes in the miniport
*                 (excluding the DAL portion).
*
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
\*****************************************************************************/

#ifndef _PROTO_H_
#define _PROTO_H_

#include "init.h"
#include "cwddeci.h"
#include "cail.h"

///////////////////////////////////////////////////
// Prototypes for functions in Radeon miniport.  //
///////////////////////////////////////////////////


//
// Prototypes for functions supplied by COMMON.C.
//
BOOL
GetAgpServices(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

BOOL
GetTimedOpServices(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VOID
GetRegistryDisableFlags(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID pFlagsBuffer
    );

// This declaration also appears in mmlib's mmlibutl.c
VP_STATUS
ReadRomImage(
    __in     PHW_DEVICE_EXTENSION   pHwDeviceExtension,
    __out_bcount(ulLength)  PVOID   pvDestination,
    __in     ULONG                  ulRomOffset,
    __in     ULONG                  ulLength
    );

UCHAR
GetAgpCapsLocation(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG *PciSlotNumber
    );

ULONG
SetAgpConfiguration(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

BOOL
bSetAgpFastWrite(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PCI_SLOT_NUMBER PciSlotNumber
    );

BOOL
bCheckAgpDataRate(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

BOOL
bSetAgpDataRate(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VP_STATUS
EnableBusAccess(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulAccessFlags
    );

VP_STATUS
MapDisplayTypesFromVector(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VP_STATUS
GetConnectedDisplays(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VP_STATUS
GetConnectedDisplaysFromBios(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VOID
UpdateDALRegistry(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VP_STATUS
vpsEnableView(
   PHW_DEVICE_EXTENSION pHwDeviceExtension
   );

VP_STATUS
vpsRedistributeDisplayDevices(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
   );


VOID
vDisableView(
   PHW_DEVICE_EXTENSION pHwDeviceExtension
   );

VOID
vTriggerEnumeration(
   PHW_DEVICE_EXTENSION pHwDeviceExtension
   );

PHYSICAL_ADDRESS
ReservePhysicalAddressRange(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulSize
    );

//
// Prototypes for functions supplied by DEBUG.C
//

#ifdef ASSERT
    #undef ASSERT
#endif

#if (DBG)

// PREfast version of ASSERT calls a noreturn function to make the debug break non-continuable.
#ifdef _PREFAST_
    __declspec(noreturn) void  die(__in  char* pDbgMsg);  // noreturn function

    #define ASSERT(b)  DebugAssert(b, __FILE__, __LINE__), ( (!(b)) ? die("no return") : 0 )
#else
    #define ASSERT(b)  DebugAssert(b, __FILE__, __LINE__)
#endif

VOID
DebugAssert(
    BOOL bCondition,
    PUCHAR szFileName,
    ULONG ulLine
    );

#else   // DBG

#define ASSERT(b)                                   NULL
#define DebugAssert(a1, a2, a3)                     NULL

#endif  // DBG

//
// Prototypes for functions supplied by ENTRY.C.
//

NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    );

VP_STATUS
AtiFindAdapter(
    __in      PHW_DEVICE_EXTENSION pHwDeviceExtension,
    __in_opt  PVOID pvHwContext,
    __in_opt  PWSTR pwszArgumentString,
    __in      PVIDEO_PORT_CONFIG_INFO pConfigInfo,
    __in      PUCHAR pucAgain
    );

BOOLEAN
AtiInitialize(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

BOOLEAN
AtiStartIO(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );

VP_STATUS
AtipSetPowerState(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulHwId,
    PVIDEO_POWER_MANAGEMENT pVideoPowerMgmt
    );

VP_STATUS
AtiGetVideoChildDescriptor(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_CHILD_ENUM_INFO pChildEnumInfo,
    PVIDEO_CHILD_TYPE pChildType,
    PVOID pvChildDescriptor,
    PULONG pulHwDeviceId,
    PULONG pulUnused
    );

// MP_VPE
BOOLEAN
AtiInterrupt(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VOID
Ati_PM4Interrupt_DPC(
    PVOID MiniportDeviceContext,
    PVOID Context);

// *** begin PM4_INTERRUPT code ***
BOOLEAN
AtiDMAInterrupt_enable(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    DWORD dwIRQSource
    );

BOOLEAN
AtiDMAInterrupt_disable(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    DWORD dwIRQSource
    );
// *** end PM4_INTERRUPT code ***

BOOLEAN
AtiVSyncInterrupt_enable(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

BOOLEAN
AtiVSyncInterrupt_disable(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

NTSTATUS
AtiQueryInterfaceEx(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PQUERY_INTERFACE pQueryInterface
    );

VOID GetMMLibMemSize(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VOID MMLibMemInitialize(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

// Prototypes for functions supplied by POWER.C

VP_STATUS
EnumerateACPIDisplayDevices(
    IN PHW_DEVICE_EXTENSION pHwDeviceExtension,
    IN PVIDEO_CHILD_ENUM_INFO pChildEnumInfo,
    OUT PVIDEO_CHILD_TYPE pChildType,
    OUT PVOID pvChildDescriptor,
    OUT PULONG pulHwDeviceId,
    OUT PULONG bMoreChildren
    );

VP_STATUS
EnumerateNonACPIDisplayDevices(
    IN PHW_DEVICE_EXTENSION pHwDeviceExtension,
    IN PVIDEO_CHILD_ENUM_INFO pChildEnumInfo,
    OUT PVIDEO_CHILD_TYPE pChildType,
    OUT PVOID pvChildDescriptor,
    OUT PULONG pulHwDeviceId,
    OUT PULONG bMoreChildren
    );

ULONG
EnumerateMonitorStatus(
    IN PHW_DEVICE_EXTENSION pHwDeviceExtension,
    IN BOOL bDALGetDisplayEDID,
    IN ULONG ulDisplayIndex
    );

ULONG
EncodeDisplayDeviceId(
    IN PHW_DEVICE_EXTENSION pHwDeviceExtension,
    IN ULONG ulDisplayIndex
    );

VP_STATUS
SetAdapterPowerState(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulHwDeviceId,
    PVIDEO_POWER_MANAGEMENT pVideoPowerMgmt
    );

VP_STATUS
SetNonACPIDisplayPowerState(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulHwDeviceId,
    PVIDEO_POWER_MANAGEMENT pVideoPowerMgmt
    );

VP_STATUS
SetACPIDisplayPowerState(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulHwDeviceId,
    PVIDEO_POWER_MANAGEMENT pVideoPowerMgmt
    );

VP_STATUS
SetDisplayPowerState(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulDisplayIndex,
    PVIDEO_POWER_MANAGEMENT pVideoPowerMgmt
    );

ULONG
ulGetMobileChildState(
  PHW_DEVICE_EXTENSION pHwDeviceExtension,
  ULONG ulHwDeviceId
  );

ULONG
ulGetDesktopChildState(
  PHW_DEVICE_EXTENSION pHwDeviceExtension,
  ULONG ulHwDeviceId
  );
BOOL
bIsACPIDisplayActive(
  PHW_DEVICE_EXTENSION pHwDeviceExtension,
  ULONG ulHwDeviceId
  );

BOOL
bIsNonACPIDisplayActive(
  PHW_DEVICE_EXTENSION pHwDeviceExtension,
  ULONG ulHwDeviceId
  );




//
// Prototypes for functions supplied by FIND.C
//

BOOL bIsBridgeDevicePresent(
    PCI_COMMON_CONFIG *pPciInfo
    );

VOID
RegisterHDE(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VOID
InitializeDeviceExtension(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_PORT_CONFIG_INFO pConfigInfo
    );

VP_STATUS
FindAdapter(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PUCHAR pucAgain
    );

VP_STATUS
GetResources(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    USHORT usDeviceId
    );
VOID
GetRegistryConfig(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VP_STATUS
GetVgaEnabledResources(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    BOOL bHalfVideoAssessRange
    );

VP_STATUS
GetVgaDisabledResources(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    BOOL bHalfVideoAssessRange
    );

BOOL
GetVgaDisabledRomImage(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VOID
FreeResources(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VP_STATUS
CheckDeviceRevision(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PPCI_SLOT_NUMBER pPciSlotNumber
    );

BOOL
GetVgaEnabledRomImage(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

BOOL
AllocateAgpResources(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

BOOL
InitSGTtables(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

//
// Prototypes for functions supplied by INIT.C.
//


VOID
DefineMemoryTag(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );


VOID
GetRegistryAdapterInfo(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PADAPTER_INFO pAdapterInfo
    );

VOID
SetRegistryAdapterInfo(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VP_STATUS
GetRegistryCallback(
    __in     PHW_DEVICE_EXTENSION pHwDeviceExtension,
    __inout  PVOID pvContext,
    __in     PWSTR pwszName,
    __in_bcount(ulLength)  PVOID pvData,
    __in     ULONG ulLength
    );

VP_STATUS
GetRegistryUlongCallback(
    __in  PHW_DEVICE_EXTENSION pHwDeviceExtension,
    __inout  PVOID pvContext,
    __in PWSTR pwszName,
    __in_bcount(ulLength)  PVOID pvData,
    __in  ULONG ulLength
    );

PWSTR
GetDeviceDescription(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PULONG pulSize,
    PULONG pulStringChangeFlags
    );

PUCHAR
FindStringInRomImage(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PUCHAR pszString,
    ULONG ulStartOffset,
    ULONG ulEndOffset
    );

VOID
StoreDALDefaultMode(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

//
// Prototypes for functions supplied by io*.c.
//
//

VP_STATUS
IoctlVideoQueryPublicAccessRanges(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );

VP_STATUS
IoctlVideoFreePublicAccessRanges(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );
VP_STATUS
IoctlVideoQueryCurrentMode(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );

VP_STATUS
IoctlVideoQueryAvailModes(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );

VP_STATUS
IoctlVideoQueryNumAvailModes(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );

VP_STATUS
IoctlVideoSetColorRegisters(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );



VP_STATUS
IoctlVideoResetDevice(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );


VP_STATUS
IoctlVideoSetPowerManagement(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );
VP_STATUS
IoctlVideoGetPowerManagement(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );


VP_STATUS
IoctlVideoShareVideoMemory(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );

VP_STATUS
IoctlVideoUnshareVideoMemory(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );

VP_STATUS
IoctlVideoHandleVideoParameters(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );

VP_STATUS
IoctlVideoGetChildState(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );

VP_STATUS
IoctlVideoValidateChildStateConfiguration(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );

VP_STATUS
IoctlVideoSetChildStateConfiguration(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );


//
// Prototypes for functions supplied by RAGEIO.C
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
///////////////////////////////////////////////////////
// Prototypes for functions supplied by ASIC.C
///////////////////////////////////////////////////////

USHORT
uAsicQueryChipID(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

UCHAR
uAsicQueryChipRevisionId(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

ULONG
ulAsicQueryChipInternalRevision(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VOID
vAsicClearDPMSBit(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID pvMmr
    );

VOID
vAsicSetDPMSBit(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVOID pvMmr
    );

VP_STATUS
vpAsicSetMemoryControllerRanges(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VOID
vAsicRegisterSGTlocation(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

BOOL
bAsicResetGui(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VOID
vAsicSetNBCaps(
  PHW_DEVICE_EXTENSION pHwDeviceExtension,
  PVOID pvMmr);


VOID
vAsicQuietDown(
    PVOID pvMmr
    );

ULONG
ulAsicReadConfigMemsize(
    PVOID pvMmr
    );


VOID vAsicInitializeDeviceExtension (
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );


///////////////////////////////////////////////////////
// Prototypes for functions supplied by ASICR6.C
///////////////////////////////////////////////////////
VP_STATUS
vpAsicInt10_R6(
    PHW_DEVICE_EXTENSION  pHwDeviceExtension,
    PVIDEO_X86_BIOS_ARGUMENTS pBiosArguments
    );

BOOL
bAsicAreHdpAperturesSameMapping_R6(
    PVOID pvMmr
    );

VOID
vAsicProgramSckPrescale1_R6(
    PVOID pvMmr,
    DWORD sck_prescale
    );

VOID
vAsicSwInterruptClear_R6(
    PVOID pvMmr
    );

VOID
vAsicSetVideoMuxCntlGeyserville_R6(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulIndex
    );

BOOLEAN
vAsicSetFpIntConnectivityState_R6(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    ULONG ulIndex
    );

VOID
vAsicPCIworkaround_UMA(
      PHW_DEVICE_EXTENSION pHwDeviceExtension
      );

VOID
vAsicTurnOffHwCursor_R6(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

VOID
vAsicResetHw_R6(
    PHW_DEVICE_EXTENSION  pHwDeviceExtension
    );
/*
 * Support functions in functions table for PM4 Interrupts
 */

BOOL bAsicPM4InterruptAck_R6 (PHW_DEVICE_EXTENSION pHwDeviceExtension);

BOOL bAsicPM4InterruptEnable_R6 (PHW_DEVICE_EXTENSION pHwDeviceExtension,
                                     DWORD dwIRQSource);

BOOL bAsicPM4InterruptDisable_R6 (PHW_DEVICE_EXTENSION pHwDeviceExtension,
                                      DWORD dwIRQSource);

///////////////////////////////////////////////////////
// Prototypes for functions supplied by DDL.C
///////////////////////////////////////////////////////


VOID
DDLDebugPrint(
    __in  ULONG ulDebugLevel,
    __in  PCHAR pcDebugMessage,
    ...
    );

BOOL
DDLBiosInt10(
    HDDL hDDL,
    PVIDEO_X86_BIOS_ARGUMENTS pBiosArguments
    );

PFNGCOENABLE*
DDLGetControllerObjects(
    HDDL hDDL,
    LPULONG lpulTotalControllerObjects
    );
PFNGDOENABLE*
DDLGetDisplayObjects(
    HDDL hDDL,
    LPULONG lpulTotalDisplayObjects
    );

VOID
DDLGetHwAsicID(
    HDDL hDDL,
    LPHW_ASIC_ID lpHwAsicID
    );

BOOL
DDLGetMonitorInfo(
    HDDL hDDL,
    LPMONITOR_INFO lpMonitorInfo
    );

BOOL
DDLGetRegistryParameters(
    HDDL hDDL,
    __in __nullterminated LPUCHAR pValueName,
    __out_bcount_part(*pulValueLength, *pulValueLength) PVOID pValueData,
    __inout PULONG pulValueLength
    );

ULONG FAR
DDLGetRegistryPathName(
    HDDL hDDL,
    LPUCHAR lpPathName
    );

BOOL
DDLSetRegistryParameters(
    HDDL hDDL,
    LPUCHAR pValueName,
    PVOID pValueData,
    ULONG ulValueLength
    );

BOOL
DDLShareModeTable(
    HDDL hDDL,
    LPVOID lpModeTable,
    ULONG ulConnectedDisplays
    );

PUCHAR
DDLFindPhysicalVgaMemory(
    HDDL hDDL,
    ULONG ulLength,
    PUSHORT pusRealSegment
    );

VOID
DDLWriteVgaIo2PortUchar(
    HDDL hDDL,
    ULONG ulPort,
    UCHAR ucValue
    );

BOOLEAN
DDLIsDeviceMemoryPhysical(
    PVOID pvStartAddress,
    ULONG ulLength
    );

VP_STATUS
DDLGetRegistryCallback(
    __in     HDDL hDDL,
    __inout  PVOID pvContext,
    __in     PWSTR pwszName,
    __in_bcount(ulLength)  PVOID pvData,
    __in     ULONG ulLength
    );

ULONG FAR
DDLGetReferenceFreq(
    HDDL hDDL
    );

ULONG
DDLGetDriverOptions(
    HDDL hDDL
    );

VOID FAR
DDLGetAdapterID(
    __in     HDDL hDDL,
    __inout_bcount(256) /*MAX_REGISTRY_PATH*/  LPCHAR lpcDriverID
    );

BOOL
DDLMessageCode(
      HDDL hDDL,
      ULONG ulDriverId,
      ULONG ulMessageCode,
      ULONG ulBufSize,
      PVOID pvBuf
      );

VOID FAR
DDLRegisterAND(
    HDDL hDDL,
    ULONG ulOffset,
    ULONG ulMask
    );

VOID FAR
DDLRegisterOR(
    HDDL hDDL,
    ULONG ulOffset,
    ULONG ulMask
    );

ULONG FAR
DDLReadCMOS(
    HDDL hDDL,
    ULONG ulCMOSAddress
    );

VOID FAR
DDLWriteCMOS(
    HDDL hDDL,
    ULONG ulCMOSAddress,
    ULONG ulCMOSValue
    );

BOOL
DDLTVAccess(
    HDDL hDDL,
    ULONG ulBustype,
    LPVOID pvBusData
    );

VOID FAR
DDLSbcToDbc(
    HDDL hDDL,
    LPUCHAR pStringName,
    LPUCHAR lpDoubleByte
    );

VOID
DDLEventNotification(
    HDDL hDDL,
    LPEVENTINFO lpEventInfo
    );

VP_STATUS
DDLMapControllersToDrivers(
    PHW_DEVICE_EXTENSION pHwDeviceExtension
    );

#ifdef LHVIDMM
VP_STATUS
IoctlVideoQuerySegmentDescriptor(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );
VP_STATUS
IoctlVideoQueryPagingBufferDescriptor(
    PHW_DEVICE_EXTENSION pHwDeviceExtension,
    PVIDEO_REQUEST_PACKET pVideoRequestPacket
    );
#endif


VP_STATUS IoctlVideoQueryPointerCapabilities(HW_DEVICE_EXTENSION*, VIDEO_REQUEST_PACKET*);

/******************************Public*Definition***************************\
* BLTFAST.C
\**************************************************************************/

#if (!defined(USE_SIMPLE_COPY) && defined(_X86_))

VOID FastCopy_DFB32TODFB32(VOID* pVDst, VOID* pVSrc, LONG  lDstDelta,
                           LONG  lSrcDelta, POINT ptlSrc, RECTL  rclDst,
                           VOID* pPal);

#else /* defined(_X86_) */
#endif /* defined(_X86_) */

VOID Copy_DFB32TODFB32(VOID* pVDst, VOID* pVSrc, LONG lDstDelta,
                       LONG lSrcDelta, POINT ptlSrc, RECTL rclDst,
                       VOID*  pPal);

BOOL Copy_DIB1TODFB32(VOID*  pVDst, VOID*  pVSrc, LONG   lDstDelta,
                      LONG   lSrcDelta, POINT ptlSrc, RECTL  rclDst,
                      VOID*  pPal);

#endif  // _PROTO_H_


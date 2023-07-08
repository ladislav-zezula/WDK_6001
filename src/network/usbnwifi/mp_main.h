/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    Mp_Main.h

Abstract:
    Mp layer major functions
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created

Notes:

--*/
#ifndef _NATIVE_WIFI_MAIN_H_

#define _NATIVE_WIFI_MAIN_H_


//
// Driver Entry and Exit Points
//
NTSTATUS
DriverEntry(
    IN    PDRIVER_OBJECT        DriverObject,
    IN    PUNICODE_STRING        RegistryPath
    );


VOID
DriverUnload(
    IN    PDRIVER_OBJECT            DriverObject
    );


//
// Handlers for Entry Points from NDIS
//

NDIS_STATUS 
MPInitialize(
    IN  NDIS_HANDLE                        MiniportAdapterHandle,
    IN  NDIS_HANDLE                        MiniportDriverContext,
    IN  PNDIS_MINIPORT_INIT_PARAMETERS     MiniportInitParameters
    );


NDIS_STATUS 
MPRestart(
    IN  NDIS_HANDLE     MiniportAdapterContext,
    IN  PNDIS_MINIPORT_RESTART_PARAMETERS   MiniportRestartParameters
    );


NDIS_STATUS 
MPPause(
    IN  NDIS_HANDLE      MiniportAdapterContext,
    IN  PNDIS_MINIPORT_PAUSE_PARAMETERS     MiniportPauseParameters
    );


VOID MPHalt(
    IN  NDIS_HANDLE             MiniportAdapterContext,
    IN  NDIS_HALT_ACTION        HaltAction
    );


BOOLEAN 
MPISR(
    IN  NDIS_HANDLE     MiniportInterruptContext,
    OUT PBOOLEAN        pbQueueMiniportHandleInterrupt,
    OUT PULONG          TargetProcessors
    );

VOID
MPHandleInterrupt(
    IN  NDIS_HANDLE     MiniportAdapterContext,
    IN  PVOID           MiniportDpcContext,
    IN  PULONG          NdisReserved1,
    IN  PULONG          NdisReserved2
    );

VOID
MPEnableInterrupt(
    IN  NDIS_HANDLE     MiniportInterruptContext
    );


VOID
MPDisableInterrupt(
    IN  NDIS_HANDLE     MiniportInterruptContext
    );


NDIS_STATUS
MPRequest(
    IN  NDIS_HANDLE         MiniportAdapterContext,
    IN  PNDIS_OID_REQUEST   NdisRequest
    );

VOID MPCancelRequest(
    IN NDIS_HANDLE hMiniportAdapterContext,
    IN PVOID       RequestId
    );

NDIS_STATUS
MPSetOptions(
    IN NDIS_HANDLE  NdisMiniportDriverHandle,
    IN NDIS_HANDLE  MiniportDriverContext
    );


VOID
MPSendNetBufferLists(
    IN  NDIS_HANDLE         MiniportAdapterContext,
    IN  PNET_BUFFER_LIST    NetBufferList,
    IN  NDIS_PORT_NUMBER    PortNumber,
    IN  ULONG               SendFlags
    );

VOID
MPProcessSGList(
    IN  PDEVICE_OBJECT          pDeviceObject,
    IN  PVOID                   pIrp,
    IN  PSCATTER_GATHER_LIST    pSGList,
    IN  PVOID                   Context
    );

VOID MPAllocateComplete(
    IN  NDIS_HANDLE             MiniportAdapterContext,
    IN  PVOID                   VirtualAddress,
    IN  PNDIS_PHYSICAL_ADDRESS  PhysicalAddress,
    IN  ULONG                   Length,
    IN  PVOID                   Context
    );


VOID 
MPReturnNetBufferLists(
    IN  NDIS_HANDLE         MiniportAdapterContext,
    IN  PNET_BUFFER_LIST    NetBufferLists,
    IN  ULONG               ReturnFlags
    );


BOOLEAN
MPCheckForHang(
    IN  NDIS_HANDLE     MiniportAdapterContext
    );


NDIS_STATUS
MPReset(
    IN  NDIS_HANDLE     MiniportAdapterContext,
    OUT PBOOLEAN        AddressingReset
    );


VOID 
MPCancelSendNetBufferLists(
    IN  NDIS_HANDLE     MiniportAdapterContext,
    IN  PVOID           CancelId
    );


VOID
MPDevicePnPEvent(
    IN NDIS_HANDLE              MiniportAdapterContext,
    IN PNET_DEVICE_PNP_EVENT    NetDevicePnPEvent
    );

VOID MPAdapterShutdown(
    IN  NDIS_HANDLE             MiniportAdapterContext,
    IN  NDIS_SHUTDOWN_ACTION    ShutdownAction
    );


INLINE 
BOOLEAN
MpRemoveAdapter(
    IN PADAPTER pAdapter
    );





//
// Functions that will be used by Miniport internally.
// Mostly consist of helper API. Their implementation
// is spread around in other files.
//


NDIS_STATUS
MpInitializeSendEngine(
    PADAPTER            Adapter
    );

VOID
MpReinitializeSendEngine(
    IN PADAPTER     Adapter
    );

VOID
MpTerminateSendEngine(
    IN PADAPTER Adapter
    );

BOOL
MPCanTransmit(
    IN PADAPTER         Adapter
    );

PMP_TX_MSDU
MPReserveTxResources(
    IN PADAPTER                 Adapter,
    IN PNET_BUFFER_LIST         NetBufferList
    );

VOID
MpSendTxMSDUs(
    IN PADAPTER         Adapter,
    IN PMP_TX_MSDU      pTxd,
    IN ULONG            NumTxd,
    IN BOOLEAN          DispatchLevel
    );

NDIS_STATUS
MpSendSingleTxMSDU(
    IN PADAPTER         Adapter,
    IN PMP_TX_MSDU      pTxd,
    IN BOOLEAN          DispatchLevel
    );

NDIS_STATUS
MpTransmitTxMSDU(
    IN PADAPTER         Adapter,
    IN PMP_TX_MSDU      pTxd,
    IN BOOLEAN          DispatchLevel
    );

VOID
MpSendReadyTxMSDUs(
    IN  PADAPTER        Adapter,
    IN BOOLEAN          DispatchLevel
    );

VOID
MpHandleSendCompleteInterrupt(
    IN PADAPTER         Adapter
    );

VOID
MpCompleteQueuedTxMSDUs(
    IN PADAPTER    Adapter
    );

VOID
MpCompleteQueuedNBL(
    IN PADAPTER    Adapter
    );

NDIS_STATUS
MpGetAdapterStatus(
    IN PADAPTER         Adapter
    );

 
NDIS_STATUS
MpResetInternalRoutine(
    IN PADAPTER             Adapter,
    IN MP_RESET_TYPE        ResetType
    ) ;

VOID
MpDot11ResetWorkItem(
    IN WDFWORKITEM  WorkItem
    );

VOID
MpNdisResetWorkItem(
    IN WDFWORKITEM  WorkItem
    );

VOID
MpDot11ResetComplete(
    IN  PADAPTER                Adapter,
    IN  PDOT11_RESET_REQUEST    pDot11ResetRequest
    );


VOID
MpHandleDefaultReceiveInterrupt(
    IN PADAPTER         Adapter,
    PNIC_RX_FRAGMENT    NicFragment,
    IN size_t           Size  
    );

VOID
MpHandleRawReceiveInterrupt(
    IN PADAPTER         Adapter,
    PNIC_RX_FRAGMENT    NicFragment,
    IN size_t           Size
    ) ;

VOID
MpHandleSafeModeReceiveInterrupt(
    IN PADAPTER         Adapter,
    PNIC_RX_FRAGMENT    NicFragment,
    IN size_t           Size
    );

VOID
MpExpireReassemblingPackets(
    IN  PADAPTER    Adapter,
    IN  BOOLEAN     DispatchLevel
    );

VOID
MpPSPacketsManagerDeliverDTIMPackets(
    IN  PADAPTER                    Adapter
    );

VOID
MpResetMacMIBs(
    IN  PADAPTER    Adapter
    );

VOID
MpResetPhyMIBs(
    IN  PADAPTER    Adapter
    );

VOID
MpAdjustReceiveHandler(
    IN PADAPTER         pAdapter
    );

#endif  // _NATIVE_WIFI_MAIN_H_


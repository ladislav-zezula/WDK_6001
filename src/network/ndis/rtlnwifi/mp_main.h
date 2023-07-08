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







//
// Functions that will be used by Miniport internally.
// Mostly consist of helper API. Their implementation
// is spread around in other files.
//


NDIS_STATUS
MpInitializeSendEngine(
    PADAPTER            pAdapter
    );

VOID
MpReinitializeSendEngine(
    IN PADAPTER     pAdapter
    );

VOID
MpTerminateSendEngine(
    IN PADAPTER pAdapter
    );

BOOL
MPCanTransmit(
    IN PADAPTER         pAdapter
    );

PMP_TX_MSDU
MPReserveTxResources(
    IN PADAPTER                 pAdapter,
    IN PNET_BUFFER_LIST         NetBufferList
    );

VOID
MpSendTxMSDUs(
    IN PADAPTER         pAdapter,
    IN PMP_TX_MSDU      pTxd,
    IN ULONG            NumTxd,
    IN BOOLEAN          DispatchLevel
    );

NDIS_STATUS
MpSendSingleTxMSDU(
    IN PADAPTER         pAdapter,
    IN PMP_TX_MSDU      pTxd,
    IN BOOLEAN          DispatchLevel
    );

NDIS_STATUS
MpTransmitTxMSDU(
    IN PADAPTER         pAdapter,
    IN PMP_TX_MSDU      pTxd,
    IN BOOLEAN          DispatchLevel
    );

VOID
MpSendReadyTxMSDUs(
    IN  PADAPTER        pAdapter,
    IN BOOLEAN          DispatchLevel
    );

VOID
MpHandleSendCompleteInterrupt(
    IN PADAPTER         pAdapter
    );

VOID
MpCompleteQueuedTxMSDUs(
    IN PADAPTER    pAdapter
    );

VOID
MpCompleteQueuedNBL(
    IN PADAPTER    pAdapter
    );

NDIS_STATUS
MpGetAdapterStatus(
    IN PADAPTER         pAdapter
    );

NDIS_STATUS
MpResetInternalRoutine(
    IN PADAPTER             pAdapter,
    IN DOT11_RESET_TYPE     ResetType
    );

VOID
MpDot11ResetWorkItem(
    IN PVOID            Context,
    IN NDIS_HANDLE      NdisIoWorkItemHandle
    );

VOID
MpResetWorkItem(
    IN PVOID            Context,
    IN NDIS_HANDLE      NdisIoWorkItemHandle
    );

/*
VOID
MpDot11ResetComplete(
    IN  PADAPTER                pAdapter,
    IN  PDOT11_RESET_REQUEST    pDot11ResetRequest
    );

*/

VOID
MpHandleDefaultReceiveInterrupt(
    IN PADAPTER         pAdapter
    );

VOID
MpHandleRawReceiveInterrupt(
    IN PADAPTER         pAdapter
    );

VOID
MpHandleSafeModeReceiveInterrupt(
    IN PADAPTER         pAdapter
    );

VOID
MpExpireReassemblingPackets(
    IN  PADAPTER    pAdapter,
    IN  BOOLEAN     DispatchLevel
    );

VOID
MpPSPacketsManagerDeliverDTIMPackets(
    IN  PADAPTER                    pAdapter
    );

VOID
MpResetMacMIBs(
    IN  PADAPTER    pAdapter
    );

VOID
MpResetPhyMIBs(
    IN  PADAPTER    pAdapter
    );

VOID
MpAdjustReceiveHandler(
    IN PADAPTER         pAdapter
    );

#endif  // _NATIVE_WIFI_MAIN_H_


/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

Module Name:

   NDISWDM.C

Abstract:

    This sample provides an example of minimal driver intended for education
    purposes. Neither the driver or its sample test programs are intended
    for use in a production environment.

--*/

#include "ndiswdm.h"

//
// Functions that are not tagged PAGEABLE by the pragma as shown below are
// by default resident (NONPAGEABLE) in memory. Make sure you don't acquire
// spinlock or raise the IRQL in a pageable function. It's okay to call
// another nonpageable function that runs at DISPATCH_LEVEL from a
// pageable function.
//
#pragma NDIS_INIT_FUNCTION(DriverEntry)
#pragma NDIS_PAGEABLE_FUNCTION(MPInitialize)
#pragma NDIS_PAGEABLE_FUNCTION(MPHalt)
#pragma NDIS_PAGEABLE_FUNCTION(MPUnload)

#ifdef NDIS51_MINIPORT
#pragma NDIS_PAGEABLE_FUNCTION(MPPnPEventNotify)
#endif

INT             MPDebugLevel = MP_WARNING;

NDIS_HANDLE     NdisMiniportDriverHandle = NULL;
NDIS_HANDLE     MiniportDriverContext = NULL;

NTSTATUS
DriverEntry(
    __in struct _DRIVER_OBJECT *DriverObject,
    __in PUNICODE_STRING RegistryPath)
/*++
Routine Description:

    In the context of its DriverEntry function, a miniport driver associates
    itself with NDIS, specifies the NDIS version that it is using, and
    registers its entry points.


Arguments:
    PVOID DriverObject - pointer to the driver object.
    PVOID RegistryPath - pointer to the driver registry path.

    Return Value:

    NDIS_STATUS_xxx code

--*/
{

    NDIS_STATUS                             Status;
    NDIS_MINIPORT_DRIVER_CHARACTERISTICS    MPChar;
    WDF_DRIVER_CONFIG                       config;
    NTSTATUS                                ntStatus;

    DEBUGP(MP_INFO, ("---> NDISWDF sample built on "__DATE__" at "__TIME__ "\n"));
    DEBUGP(MP_INFO, ("---> Sample is built with NDIS Version %d.%d\n",
                            MP_NDIS_MAJOR_VERSION, MP_NDIS_MINOR_VERSION));

    //
    // Make sure we are compatible with the version of NDIS supported by OS.
    //
    if (NdisGetVersion() < ((MP_NDIS_MAJOR_VERSION << 16) | MP_NDIS_MINOR_VERSION)){
        DEBUGP(MP_ERROR, ("This version of driver is not support on this OS\n"));
        return NDIS_STATUS_FAILURE;
    }


    WDF_DRIVER_CONFIG_INIT(&config, WDF_NO_EVENT_CALLBACK);
    //
    // Set WdfDriverInitNoDispatchOverride flag to tell the framework
    // not to provide dispatch routines for the driver. In other words,
    // the framework must not intercept IRPs that the I/O manager has
    // directed to the driver. In this case, it will be handled by NDIS
    // port driver.
    //
    config.DriverInitFlags |= WdfDriverInitNoDispatchOverride;

    ntStatus = WdfDriverCreate(DriverObject,
                                            RegistryPath,
                                            WDF_NO_OBJECT_ATTRIBUTES,
                                            &config,
                                            WDF_NO_HANDLE);
    if (!NT_SUCCESS(ntStatus)){
        DEBUGP(MP_ERROR, ("WdfDriverCreate failed\n"));
        return NDIS_STATUS_FAILURE;
    }

    //
    // Fill in the Miniport characteristics structure with the version numbers
    // and the entry points for driver-supplied MiniportXxx
    //
    NdisZeroMemory(&MPChar, sizeof(MPChar));


    MPChar.Header.Type = NDIS_OBJECT_TYPE_MINIPORT_DRIVER_CHARACTERISTICS,
    MPChar.Header.Size = sizeof(NDIS_MINIPORT_DRIVER_CHARACTERISTICS);
    MPChar.Header.Revision = NDIS_MINIPORT_DRIVER_CHARACTERISTICS_REVISION_1;
    MPChar.MajorNdisVersion             = MP_NDIS_MAJOR_VERSION;
    MPChar.MinorNdisVersion             = MP_NDIS_MINOR_VERSION;
    MPChar.MajorDriverVersion           = NIC_MAJOR_DRIVER_VERSION;
    MPChar.MinorDriverVersion           = NIC_MINOR_DRIVER_VERISON;

    MPChar.SetOptionsHandler            = MPSetOptions;

    MPChar.InitializeHandlerEx          = MPInitialize;
    MPChar.HaltHandlerEx                = MPHalt;

    MPChar.UnloadHandler                = MPUnload,

    MPChar.PauseHandler                 = MPPause;
    MPChar.RestartHandler               = MPRestart;
    MPChar.OidRequestHandler            = MPOidRequest;
    MPChar.SendNetBufferListsHandler    = MPSendNetBufferLists;
    MPChar.ReturnNetBufferListsHandler  = MPReturnNetBufferLists;
    MPChar.CancelSendHandler            = MPCancelSendNetBufferLists;
    MPChar.DevicePnPEventNotifyHandler  = MPPnPEventNotify;
    MPChar.ShutdownHandlerEx            = MPShutdown;
    MPChar.CheckForHangHandlerEx        = MPCheckForHang;
    MPChar.ResetHandlerEx               = MPReset;
    MPChar.CancelOidRequestHandler      = MPCancelOidRequest;

    MPChar.Flags = NDIS_WDM_DRIVER;

    DEBUGP(MP_LOUD, ("Calling NdisMRegisterMiniportDriver...\n"));

    //
    // Registers miniport's entry points with the NDIS library as the first
    // step in NIC driver initialization. The NDIS will call the
    // MiniportInitialize when the device is actually started by the PNP
    // manager.
    //
    Status = NdisMRegisterMiniportDriver(DriverObject,
                                         RegistryPath,
                                         (PNDIS_HANDLE)MiniportDriverContext,
                                         &MPChar,
                                         &NdisMiniportDriverHandle);

    if (Status != NDIS_STATUS_SUCCESS) {
        DEBUGP(MP_ERROR, ("NdisMRegisterMiniportDriver Status = 0x%08x\n", Status));
    }

    DEBUGP(MP_TRACE, ("<--- DriverEntry\n"));
    return Status;

}



NDIS_STATUS
MPInitialize(
    IN  NDIS_HANDLE                        MiniportAdapterHandle,
    IN  NDIS_HANDLE                        MiniportDriverContext,
    IN  PNDIS_MINIPORT_INIT_PARAMETERS     MiniportInitParameters
    )
/*++
Routine Description:

    The MiniportInitialize function is a required function. Here is the
    list of things this function typically performs:

        Set the miniport attributes.
        Read configuration parameters from the registry.
        Allocate memory.
        Allocate the NET_BUFFER_LIST pool and the NET_BUFFER pool.
        Register the interrupt handler.
        Allocate scatter/gather DMA resources.
        Read and write to the bus-specific configuration space.

    MiniportInitialize runs at IRQL = PASSIVE_LEVEL.

Arguments:

    MiniportAdapterHandle   The handle NDIS uses to refer to us
    MiniportDriverContext   Handle passed to NDIS when we registered the driver
    MiniportInitParameters  Initialization parameters contains a pointer
                            to a list of the allocated hardware resources
                            for the miniport adapter

Return Value:

    NDIS_STATUS_xxx code

--*/
{
    NDIS_STATUS         Status = NDIS_STATUS_SUCCESS;
    PMP_ADAPTER         Adapter = NULL;
    NTSTATUS               ntStatus;
    ULONG                  nameLength;
    WDF_OBJECT_ATTRIBUTES  attributes;

    UNREFERENCED_PARAMETER(MiniportDriverContext);
    UNREFERENCED_PARAMETER(MiniportInitParameters);

    DEBUGP(MP_TRACE, ("---> MPInitialize\n"));

    PAGED_CODE();

    do {
        //
        // Allocate adapter context structure and initialize all the
        // memory resources for sending and receiving packets.
        //
        Status = NICAllocAdapter(&Adapter);
        if (Status != NDIS_STATUS_SUCCESS)
        {
            Adapter = NULL;
            break;
        }

        MP_INC_REF(Adapter);

        Adapter->AdapterHandle = MiniportAdapterHandle;

        //
        // NdisMGetDeviceProperty function enables us to get the:
        // PDO - created by the bus driver to represent our device.
        // FDO - created by NDIS to represent our miniport as a function
        //              driver.
        // NextDeviceObject - deviceobject of another driver (filter)
        //                      attached to us at the bottom.
        // Since our driver is talking to NDISPROT, the NextDeviceObject
        // is not useful. But if we were to talk to a driver that we
        // are attached to as part of the devicestack then NextDeviceObject
        // would be our target DeviceObject for sending read/write Requests.
        //

        NdisMGetDeviceProperty(MiniportAdapterHandle,
                           &Adapter->Pdo,
                           &Adapter->Fdo,
                           &Adapter->NextDeviceObject,
                           NULL,
                           NULL);

        ntStatus = IoGetDeviceProperty (Adapter->Pdo,
                                      DevicePropertyDeviceDescription,
                                      NIC_ADAPTER_NAME_SIZE,
                                      Adapter->AdapterDesc,
                                      &nameLength);

        if (!NT_SUCCESS (ntStatus))
        {
            DEBUGP (MP_ERROR, ("IoGetDeviceProperty failed (0x%x)\n",
                                            ntStatus));
            Status = NDIS_STATUS_FAILURE;
            break;
        }

        WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, WDF_DEVICE_INFO);

        ntStatus = WdfDeviceMiniportCreate(WdfGetDriver(),
                                         &attributes,
                                         Adapter->Fdo,
                                         Adapter->NextDeviceObject,
                                         Adapter->Pdo,
                                         &Adapter->WdfDevice);
        if (!NT_SUCCESS (ntStatus))
        {
            DEBUGP (MP_ERROR, ("WdfDeviceMiniportCreate failed (0x%x)\n",
                                            ntStatus));
            Status = NDIS_STATUS_FAILURE;
            break;
        }

        //
        // Get WDF miniport device context.
        //
        GetWdfDeviceInfo(Adapter->WdfDevice)->Adapter = Adapter;

        MP_SET_FLAG(Adapter, fMP_INIT_IN_PROGRESS);

        //
        // Read Advanced configuration information from the registry
        //

        Status = NICReadRegParameters(Adapter);
        if (Status != NDIS_STATUS_SUCCESS)
        {
            break;
        }

        //
        // Get the Adapter Resources & Initialize the hardware.
        //

        Status = NICInitializeAdapter(Adapter);
        if (Status != NDIS_STATUS_SUCCESS) {
            Status = NDIS_STATUS_FAILURE;
            break;
        }

        Status = NICSetAttributes(Adapter);
        if (Status != NDIS_STATUS_SUCCESS)
        {
            break;
        }

        Adapter->AdapterState = NicRunning;

    } WHILE (FALSE);

    if (Adapter && Status != NDIS_STATUS_SUCCESS) {
        MPHalt(Adapter, NdisHaltDeviceInitializationFailed);
    }

    DEBUGP(MP_TRACE, ("<--- MPInitialize Status = 0x%08x%\n", Status));

    return Status;

}



VOID
MPHalt(
    IN  NDIS_HANDLE             MiniportAdapterContext,
    IN  NDIS_HALT_ACTION        HaltAction
    )
/*++

Routine Description:

    Halt handler is called when NDIS receives IRP_MN_STOP_DEVICE,
    IRP_MN_SUPRISE_REMOVE or IRP_MN_REMOVE_DEVICE requests from the
    PNP manager. Here, the driver should free all the resources acquired
    in MiniportInitialize and stop access to the hardware. NDIS will
    not submit any further request once this handler is invoked.

    1) Free and unmap all I/O resources.
    2) Disable interrupt and deregister interrupt handler.
    3) Cancel all queued up timer callbacks.
    4) Finally wait indefinitely for all the outstanding receive
        packets indicated to the protocol to return.

    MiniportHalt runs at IRQL = PASSIVE_LEVEL.


Arguments:

    MiniportAdapterContext  Pointer to our adapter
    HaltAction              The reason adapter is being halted

Return Value:

    None.

--*/
{
    PMP_ADAPTER       Adapter = (PMP_ADAPTER) MiniportAdapterContext;
    BOOLEAN           bDone=TRUE;
    LONG              nHaltCount = 0;

    DEBUGP(MP_WARNING, ("---> MPHalt\n"));

    PAGED_CODE();

    MP_SET_FLAG(Adapter, fMP_HALT_IN_PROGRESS);

    MP_CLEAR_FLAG(Adapter, fMP_POST_WRITES);
    MP_CLEAR_FLAG(Adapter, fMP_POST_READS);

    NICUnregisterExCallback(Adapter);

    //
    // Call Shutdown handler to disable interrupt and turn the hardware off
    // by issuing a full reset
    //
   if (HaltAction != NdisHaltDeviceSurpriseRemoved)
    {
        MPShutdown(MiniportAdapterContext, NdisShutdownPowerOff);
    }

    //
    // WdfIoTargetStop will cancel all the outstanding I/O and wait
    // for them to complete before returning. WdfIoTargetStop  with the
    //  action type WdfIoTargetCancelSentIo can be called at IRQL PASSIVE_LEVEL only.
    //
    if (Adapter->IoTarget) {
        WdfIoTargetStop(Adapter->IoTarget, WdfIoTargetCancelSentIo );
    }

#ifdef INTERFACE_WITH_NDISPROT
    //
    // Close the remote IoTarget.
    // Local Iotargets are created, opened and later closed
    // by the framework and hence the driver doesn't need to close them.
    //
    if (Adapter->IoTarget) {
        WdfIoTargetClose(Adapter->IoTarget);
    }
#endif

    //
    // Flush to make sure currently executing workitem has run to completion.
    //
    if (Adapter->ReadWorkItem) {
        WdfWorkItemFlush(Adapter->ReadWorkItem);
    }

    if (Adapter->WorkItemForNdisRequest) {
        WdfWorkItemFlush(Adapter->WorkItemForNdisRequest);
    }

    if (Adapter->ExecutiveCallbackWorkItem) {
        WdfWorkItemFlush(Adapter->ExecutiveCallbackWorkItem);
    }

    //
    // Free the packets on SendWaitList
    //
    NICFreeQueuedSendNetBufferLists(Adapter);

    //
    // Decrement the ref count which was incremented in MPInitialize
    //

    MP_DEC_REF(Adapter);

    DEBUGP(MP_INFO, ("RefCount=%d --- waiting!\n", MP_GET_REF(Adapter)));

    NdisWaitEvent(&Adapter->HaltEvent, 0);

    do {

        bDone = TRUE;

        //
        // Are all the packets indicated up returned?
        //
        if (Adapter->nIndicatedNetBufferList)
        {
            DEBUGP(MP_INFO, ("nPacketsIndicated = %d\n", Adapter->nIndicatedNetBufferList));
            bDone = FALSE;
        }

        //
        // Are there any outstanding send packets?
        //
        if (Adapter->nBusySend)
        {
            DEBUGP(MP_INFO, ("nBusySend = %d\n", Adapter->nBusySend));
            bDone = FALSE;
        }

        if (bDone)
        {
            break;
        }

        if ((++nHaltCount % 100) == 0)
        {
            DEBUGP(MP_ERROR, ("Halt timed out!!!\n"));
            ASSERT(FALSE);
        }

        DEBUGP(MP_INFO, ("MPHalt - waiting ...\n"));
        NdisMSleep(1000);

    } WHILE (TRUE);

    ASSERT(bDone);

    NICFreeRecvResources(Adapter);
    NICFreeSendResources(Adapter);
    NICFreeAdapter(Adapter);

    DEBUGP(MP_WARNING, ("<--- MPHalt\n"));
}

NDIS_STATUS
MPReset(
    IN  NDIS_HANDLE     MiniportAdapterContext,
    OUT PBOOLEAN        AddressingReset
    )
/*++

Routine Description:

    An NDIS 6.0 miniport driver's reset function can cancel pending OID
    requests and send requests in the context of a reset.
    NDIS no longer performs such cancellations. Alternatively,
    the miniport driver can complete pending OID requests
    and send requests after the reset completes.

    MiniportReset function can be called at either IRQL PASSIVE_LEVEL
    or IRQL = DISPATCH_LEVEL.

Arguments:

    AddressingReset         To let NDIS know whether we need help from it with our reset
    MiniportAdapterContext  Pointer to our adapter

Return Value:

    NDIS_STATUS_SUCCESS
    NDIS_STATUS_PENDING
    NDIS_STATUS_RESET_IN_PROGRESS
    NDIS_STATUS_HARD_ERRORS

Note:

--*/
{
    PMP_ADAPTER       Adapter = (PMP_ADAPTER) MiniportAdapterContext;
    NDIS_STATUS Status = NDIS_STATUS_SUCCESS;

    DEBUGP(MP_TRACE, ("---> MPReset\n"));

    *AddressingReset = TRUE;

    ASSERT(Adapter->ResetPending == FALSE);

    NdisAcquireSpinLock(&Adapter->Lock);

    ASSERT(!MP_TEST_FLAG(Adapter, fMP_HALT_IN_PROGRESS));

    //
    // Is this adapter already doing a reset?
    //
    if (MP_TEST_FLAG(Adapter, fMP_RESET_IN_PROGRESS))
    {
        Status = NDIS_STATUS_RESET_IN_PROGRESS;
        goto EXIT;
    }

    MP_SET_FLAG(Adapter, fMP_RESET_IN_PROGRESS);

    //
    // If there is a pending request, we must wait for it to complete
    // before completing the reset. Since the reset handler is called
    // at DISPATCH_LEVEL, we can't really wait here. So we will return
    // STATUS_PENDING, and in the completion handler for forwarded
    // OID requests, we will call NdisMResetComplete().
    //
    if (Adapter->PendingOidNdisRequest){
        Adapter->ResetPending = TRUE;
        Status = NDIS_STATUS_PENDING;
    }

EXIT:

    NdisReleaseSpinLock(&Adapter->Lock);

    DEBUGP(MP_TRACE, ("<--- MPReset\n"));

    return Status;
}

VOID
MPUnload(
    IN  PDRIVER_OBJECT  DriverObject
    )
/*++

Routine Description:

    The unload handler is called during driver unload to free up resources
    acquired in DriverEntry. Note that an unload handler differs from
    a MiniportHalt function in that the unload handler has a more global
    scope, whereas the scope of the MiniportHalt function is restricted
    to a particular miniport driver instance.

    During an unload operation, an NDIS 6.0 miniport driver must deregister
    the miniport driver by calling NdisMDeregisterMiniportDriver
    and passing the MiniportDriverHandle as a parameter.
    The driver obtained the MiniportDriverHandle when it called
    NdisMRegisterMiniportDriver.

    Runs at IRQL = PASSIVE_LEVEL.

Arguments:

    DriverObject        Not used

Return Value:

    None

--*/
{
    DEBUGP(MP_TRACE, ("--> MPUnload\n"));

    UNREFERENCED_PARAMETER(DriverObject);

    PAGED_CODE();

    WdfDriverMiniportUnload(WdfGetDriver());

    NdisMDeregisterMiniportDriver(NdisMiniportDriverHandle);

    DEBUGP(MP_TRACE, ("<--- MPUnload\n"));
}

VOID
MPShutdown(
    IN NDIS_HANDLE MiniportAdapterContext,
    IN  NDIS_SHUTDOWN_ACTION    ShutdownAction
    )
/*++

Routine Description:

    The MiniportShutdown handler restores a NIC to its initial state when
    the system is shut down, whether by the user or because an unrecoverable
    system error occurred. This is to ensure that the NIC is in a known
    state and ready to be reinitialized when the machine is rebooted after
    a system shutdown occurs for any reason, including a crash dump.

    Here just disable the interrupt and stop the DMA engine.
    Do not free memory resources or wait for any packet transfers
    to complete.


    Runs at an arbitrary IRQL <= DIRQL. So do not call any passive-level
    function.

Arguments:

    MiniportAdapterContext  Pointer to our adapter
    ShutdownAction - reason for shutting down the miniport driver

Return Value:

    None

--*/
{
    PMP_ADAPTER Adapter = (PMP_ADAPTER) MiniportAdapterContext;

    UNREFERENCED_PARAMETER(Adapter);
    UNREFERENCED_PARAMETER(ShutdownAction);

    DEBUGP(MP_TRACE, ("---> MPShutdown\n"));

    DEBUGP(MP_TRACE, ("<--- MPShutdown\n"));

}

BOOLEAN
MPCheckForHang(
    IN NDIS_HANDLE MiniportAdapterContext
    )
/*++

Routine Description:

    The MiniportCheckForHang handler is called to report the state of the
    NIC, or to monitor the responsiveness of an underlying device driver.
    This is an optional function. If this handler is not specified, NDIS
    judges the driver unresponsive when the driver holds
    MiniportQueryInformation or MiniportSetInformation requests for a
    time-out interval (deafult 4 sec), and then calls the driver's
    MiniportReset function. A NIC driver's MiniportInitialize function can
    extend NDIS's time-out interval by calling NdisMSetAttributesEx to
    avoid unnecessary resets.

    Always runs at IRQL = DISPATCH_LEVEL.

Arguments:

    MiniportAdapterContext  Pointer to our adapter

Return Value:

    TRUE    NDIS calls the driver's MiniportReset function.
    FALSE   Everything is fine

Note:
    CheckForHang handler is called in the context of a timer DPC.
    take advantage of this fact when acquiring/releasing spinlocks

--*/
{
    UNREFERENCED_PARAMETER(MiniportAdapterContext);

    DEBUGP(MP_LOUD, ("---> MPCheckForHang\n"));

    DEBUGP(MP_LOUD, ("<--- MPCheckForHang\n"));
    return(FALSE);
}

NDIS_STATUS
MPPause(
    IN  NDIS_HANDLE                         MiniportAdapterContext,
    IN  PNDIS_MINIPORT_PAUSE_PARAMETERS     MiniportPauseParameters
    )
/*++

Routine Description:

    Miniport pause and restart are new features introduced in NDIS 6.0.
    NDIS calls a miniport driver's MiniportPause function to stop
    data flow before a Plug and Play operation, such as adding or
    removing a filter driver or binding or unbinding a protocol driver,
    is performed. The adapter remains in the Pausing state until the
    pause operation has completed.

    When in the Paused state, a miniport driver can indicate status by
    calling the NdisMIndicateStatusEx function. In addition, the miniport
    driver should do the following:
    - Wait for all calls to the NdisMIndicateReceiveNetBufferLists
        function to return.
    - Wait for NDIS to return the ownership of all NET_BUFFER_LIST
        structures from outstanding receive indications to the miniport
        driver's MiniportReturnNetBufferLists function.
    - Complete all outstanding send requests by calling NdisMSendNetBufferListsComplete.
    - Reject all new send requests made to its MiniportSendNetBufferLists
        function by immediately calling the NdisMSendNetBufferListsComplete
        function. The driver should set the completion status in each
        NET_BUFFER_LIST structure to NDIS_STATUS_PAUSED.
    - Continue to handle OID requests in its MiniportOidRequest function.
    - Not stop the adapter completely if doing so prevents the driver
        from handling OID requests or providing status indications.
    - Not free the resources that the driver allocated during initialization.
    - Continue to handle DevicePnPEvent notifications.

    NDIS calls the miniport driver's MiniportRestart function to cause
    the miniport to return the adapter to the Running state.
    During the restart, the miniport driver must complete any tasks
    that are required to resume send and receive operations before
    completing the restart request.

Argument:

    MiniportAdapterContext  Pointer to our adapter

Return Value:

    NDIS_STATUS_SUCCESS
    NDIS_STATUS_PENDING

NOTE: A miniport can't fail the pause request

--*/
{
    PMP_ADAPTER         Adapter = (PMP_ADAPTER) MiniportAdapterContext;
    NDIS_STATUS         Status;

    UNREFERENCED_PARAMETER(MiniportPauseParameters);

    DEBUGP(MP_TRACE, ("---> MPPause\n"));

    ASSERT(Adapter->AdapterState == NicRunning);

    NdisAcquireSpinLock(&Adapter->RecvLock);
    Adapter->AdapterState = NicPausing;
    NdisReleaseSpinLock(&Adapter->RecvLock);

    do
    {
        //
        // Complete all the pending sends
        //
        NdisAcquireSpinLock(&Adapter->SendLock);

        NICFreeQueuedSendNetBufferLists(Adapter);

        NdisReleaseSpinLock(&Adapter->SendLock);

        NdisAcquireSpinLock(&Adapter->RecvLock);
        if (Adapter->nIndicatedNetBufferList == 0)
        {
            Adapter->AdapterState = NicPaused;
            Status = NDIS_STATUS_SUCCESS;
        }
        else
        {
            Status = NDIS_STATUS_PENDING;
        }
        NdisReleaseSpinLock(&Adapter->RecvLock);

    }

    WHILE (FALSE);

    DEBUGP(MP_TRACE, ("<--- MPPause 0x%x\n", Status));
    return Status;
}

NDIS_STATUS
MPRestart(
    IN  NDIS_HANDLE                         MiniportAdapterContext,
    IN  PNDIS_MINIPORT_RESTART_PARAMETERS   MiniportRestartParameters
    )
/*++

Routine Description:

    NDIS calls the miniport driver's MiniportRestart function to cause
    the miniport to return the adapter to the Running state.
    During the restart, the miniport driver must complete any tasks
    that are required to resume send and receive operations before
    completing the restart request.

Argument:

    MiniportAdapterContext  Pointer to our adapter

Return Value:

    NDIS_STATUS_SUCCESS
    NDIS_STATUS_PENDING  Can it return pending
    NDIS_STATUS_XXX      The driver fails to restart


--*/
{
    PMP_ADAPTER                  Adapter = (PMP_ADAPTER)MiniportAdapterContext;
    PNDIS_RESTART_ATTRIBUTES     NdisRestartAttributes;
    PNDIS_RESTART_GENERAL_ATTRIBUTES  NdisGeneralAttributes;

    UNREFERENCED_PARAMETER(MiniportRestartParameters);

    DEBUGP(MP_TRACE, ("---> MPRestart\n"));

    NdisRestartAttributes = MiniportRestartParameters->RestartAttributes;

    //
    // If NdisRestartAttributes is not NULL, then miniport can modify
    // generic attributes and add new media specific info attributes
    // at the end. Otherwise, NDIS restarts the miniport because
    // of other reason, miniport should not try to modify/add attributes
    //
    if (NdisRestartAttributes != NULL)
    {

        ASSERT(NdisRestartAttributes->Oid == OID_GEN_MINIPORT_RESTART_ATTRIBUTES);

        NdisGeneralAttributes = (PNDIS_RESTART_GENERAL_ATTRIBUTES)NdisRestartAttributes->Data;

        //
        // Check to see if we need to change any attributes, for example,
        // the driver can change the current MAC address here. Or the
        // driver can add media specific info attributes.
        //
    }

    NdisAcquireSpinLock(&Adapter->RecvLock);
    Adapter->AdapterState = NicRunning;
    NdisReleaseSpinLock(&Adapter->RecvLock);

    DEBUGP(MP_TRACE, ("<--- MPRestart\n"));
    return NDIS_STATUS_SUCCESS;

}


VOID
MPPnPEventNotify(
    IN  NDIS_HANDLE             MiniportAdapterContext,
    IN  PNET_DEVICE_PNP_EVENT   NetDevicePnPEvent
    )
/*++

Routine Description:

    MPPnPEventNotify is to handle PnP notification messages.
    An NDIS miniport driver with a WDM lower edge should export a
    MiniportPnPEventNotify function so that it can be notified
    when its NIC is removed without prior notification through
    the user interface. When a miniport driver receives
    notification of a surprise removal, it should note internally
    that the device has been removed and cancel any pending Requests
    that it sent down to the underlying bus driver. After calling
    the MiniportPnPEventNotify function to indicate the surprise
    removal, NDIS calls the miniport's MiniportHalt function.
    If the miniport driver receives any requests to send packets
    or query or set OIDs before its MiniportHalt function is
    called, it should immediately complete such requests with a
    status value of NDIS_STATUS_NOT_ACCEPTED.

    All NDIS 5.1 miniport drivers must export a MPPnPEventNotify
    function.

    Runs at IRQL = PASSIVE_LEVEL in the context of system thread.

    Available - NDIS5.1 (WinXP) and later.

Arguments:

    MiniportAdapterContext      Pointer to our adapter
    PnPEvent                    Self-explanatory

Return Value:

    None

--*/
{
    PMP_ADAPTER             Adapter;
    PNDIS_POWER_PROFILE     NdisPowerProfile;
    NDIS_DEVICE_PNP_EVENT   PnPEvent;
    PVOID                   InformationBuffer;
    ULONG                   InformationBufferLength;

    DEBUGP(MP_TRACE, ("---> MPPnPEventNotify\n"));


    Adapter = (PMP_ADAPTER)MiniportAdapterContext;
    PnPEvent = NetDevicePnPEvent->DevicePnPEvent;
    InformationBuffer = NetDevicePnPEvent->InformationBuffer;
    InformationBufferLength = NetDevicePnPEvent->InformationBufferLength;

    //
    // NDIS currently sends only SurpriseRemoved and
    // PowerProfileChange Notification events.
    //
    switch (PnPEvent)
    {
        case NdisDevicePnPEventQueryRemoved:
            //
            // Called when NDIS receives IRP_MN_QUERY_REMOVE_DEVICE.
            //
            DEBUGP(MP_LOUD, ("MPPnPEventNotify: NdisDevicePnPEventQueryRemoved\n"));
            break;

        case NdisDevicePnPEventRemoved:
            //
            // Called when NDIS receives IRP_MN_REMOVE_DEVICE.
            // NDIS calls MiniportHalt function after this call returns.
            //
            DEBUGP(MP_LOUD, ("MPPnPEventNotify: NdisDevicePnPEventRemoved\n"));
            break;

        case NdisDevicePnPEventSurpriseRemoved:
            //
            // Called when NDIS receives IRP_MN_SUPRISE_REMOVAL.
            // NDIS calls MiniportHalt function after this call returns.
            //
            MP_SET_FLAG(Adapter, fMP_SURPRISE_REMOVED);
            DEBUGP(MP_LOUD, ("MPPnPEventNotify: NdisDevicePnPEventSurpriseRemoved\n"));
            break;

        case NdisDevicePnPEventQueryStopped:
            //
            // Called when NDIS receives IRP_MN_QUERY_STOP_DEVICE. ??
            //
            DEBUGP(MP_LOUD, ("MPPnPEventNotify: NdisDevicePnPEventQueryStopped\n"));
            break;

        case NdisDevicePnPEventStopped:
            //
            // Called when NDIS receives IRP_MN_STOP_DEVICE.
            // NDIS calls MiniportHalt function after this call returns.
            //
            //
            DEBUGP(MP_LOUD, ("MPPnPEventNotify: NdisDevicePnPEventStopped\n"));
            break;

        case NdisDevicePnPEventPowerProfileChanged:
            //
            // After initializing a miniport driver and after miniport driver
            // receives an OID_PNP_SET_POWER notification that specifies
            // a device power state of NdisDeviceStateD0 (the powered-on state),
            // NDIS calls the miniport's MiniportPnPEventNotify function with
            // PnPEvent set to NdisDevicePnPEventPowerProfileChanged.
            //
            DEBUGP(MP_LOUD, ("MPPnPEventNotify: NdisDevicePnPEventPowerProfileChanged\n"));

            if (InformationBufferLength == sizeof(NDIS_POWER_PROFILE)) {
                NdisPowerProfile = (PNDIS_POWER_PROFILE)InformationBuffer;
                if (*NdisPowerProfile == NdisPowerProfileBattery) {
                    DEBUGP(MP_LOUD,
                        ("The host system is running on battery power\n"));
                }
                if (*NdisPowerProfile == NdisPowerProfileAcOnLine) {
                    DEBUGP(MP_LOUD,
                        ("The host system is running on AC power\n"));
               }
            }
            break;

        default:
            DEBUGP(MP_ERROR, ("MPPnPEventNotify: unknown PnP event %x \n", PnPEvent));
            break;
    }

    DEBUGP(MP_TRACE, ("<--- MPPnPEventNotify\n"));

}

NDIS_STATUS
MPSetOptions(
    IN NDIS_HANDLE  NdisMiniportDriverHandle,
    IN NDIS_HANDLE  MiniportDriverContext
    )
/*++

Routine Description:

    MiniportSetOptions function is called by NDIS to ask the
    miniport driver to register its optional handlers.
    A miniport driver must call NdisSetOptionalHandler f
    rom its MiniportSetOptions function to register its
    optional handlers with NDIS.

Arguments:


Return Value:

    None

--*/
{
    UNREFERENCED_PARAMETER(NdisMiniportDriverHandle);
    UNREFERENCED_PARAMETER(MiniportDriverContext);

    DEBUGP(MP_TRACE, ("---> MPSetOptions\n"));

    DEBUGP(MP_TRACE, ("<--- MPSetOptions\n"));

    return (NDIS_STATUS_SUCCESS);
}



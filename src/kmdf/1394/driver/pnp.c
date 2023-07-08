/*++

Copyright (c) Microsoft Corporation

Module Name:

    pnp.c

Abstract

--*/

//#define INITGUID
#include "pch.h"

#ifdef ALLOC_PRAGMA
#pragma alloc_text (PAGE, t1394_EvtDeviceAdd)
#pragma alloc_text (PAGE, t1394_EvtPrepareHardware)
#pragma alloc_text (PAGE, t1394_EvtReleaseHardware)
#pragma alloc_text (PAGE, t1394_EvtDeviceD0Exit)
#pragma alloc_text (PAGE, DbgDevicePowerString)
#endif

NTSTATUS
t1394_EvtDeviceAdd(
    IN WDFDRIVER        Driver,
    IN PWDFDEVICE_INIT  DeviceInit
    )
/*++
Routine Description:

    EvtDeviceAdd is called by the framework in response to AddDevice
    call from the PnP manager.

Arguments:

    Driver - Handle to a framework driver object created in DriverEntry

    DeviceInit - Pointer to a framework-allocated WDFDEVICE_INIT structure.

Return Value:

    NTSTATUS

--*/
{
    NTSTATUS                        status = STATUS_SUCCESS;
    PDEVICE_EXTENSION               deviceExtension;
    PNODE_DEVICE_EXTENSION          pNodeExt;
    WDF_PNPPOWER_EVENT_CALLBACKS    pnpPowerCallbacks;
    WDF_OBJECT_ATTRIBUTES           fdoAttributes,lockAttributes;
    WDFDEVICE                       device;
    WDF_DEVICE_PNP_CAPABILITIES     pnpCaps;
    WDF_IO_QUEUE_CONFIG             ioQueueConfig;
    WDF_IO_TARGET_OPEN_PARAMS       openParams;

    UNREFERENCED_PARAMETER(Driver);

    PAGED_CODE();

    ENTER("t1394_PnpAddDevice");

    //
    // Zero out the PnpPowerCallbacks structure.
    //
    WDF_PNPPOWER_EVENT_CALLBACKS_INIT(&pnpPowerCallbacks);

    //
    // Set Callbacks for any of the functions we are interested in.
    // If no callback is set, Framework will take the default action
    // by itself.

    //
    // These two callbacks set up and tear down hardware state,
    // specifically that which only has to be done once.
    //

    pnpPowerCallbacks.EvtDevicePrepareHardware = t1394_EvtPrepareHardware;
    pnpPowerCallbacks.EvtDeviceReleaseHardware = t1394_EvtReleaseHardware;

    pnpPowerCallbacks.EvtDeviceSelfManagedIoCleanup =
        t1394_EvtDeviceSelfManagedIoCleanup;

    pnpPowerCallbacks.EvtDeviceD0Entry = t1394_EvtDeviceD0Entry;
    pnpPowerCallbacks.EvtDeviceD0Exit  = t1394_EvtDeviceD0Exit;

    //
    // Register the PnP and power callbacks. Power policy related callbacks
    // will be registered// later in SotwareInit.
    //
    WdfDeviceInitSetPnpPowerEventCallbacks(DeviceInit, &pnpPowerCallbacks);
    if ( !NT_SUCCESS(status)) {
        TRACE(TL_ERROR, ("WdfDeviceInitSetPnpPowerEventCallbacks failed %x\n",
                         status));
        return status;
    }

    WdfDeviceInitSetExclusive(DeviceInit, FALSE);

    //
    // Specify the size and type of device context.
    //
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&fdoAttributes, DEVICE_EXTENSION);

    status = WdfDeviceCreate(&DeviceInit, &fdoAttributes, &device);

    if ( !NT_SUCCESS(status)) {
        TRACE(TL_ERROR, ("WdfDeviceInitialize failed %x\n", status));
        return status;
    }


    deviceExtension = GetDeviceContext (device);
    deviceExtension->WdfDevice = device;

    TRACE(TL_TRACE, ("PDO(0x%p) FDO(0x%p), Lower(0x%p) DevExt (0x%p)\n",
                     WdfDeviceWdmGetPhysicalDevice (device),
                     WdfDeviceWdmGetDeviceObject (device),
                     WdfDeviceWdmGetAttachedDevice(device),
                     deviceExtension));

    //
    // Tell the Framework that this device will need an interface so that
    // application can interact with it.
    //

    status = WdfDeviceCreateDeviceInterface(
                 device,
#if defined(_1394VDEV_DRIVER_)
                 (LPGUID) &GUID_1394VDEV,
#else
                 (LPGUID) &GUID_1394DIAG,
#endif
                 NULL
             );

    if (!NT_SUCCESS (status)) {
        TRACE(TL_ERROR, ("WdfDeviceCreateDeviceInterface failed %x\n", status));
        return status;
    }

    //
    // Tell the framework to set the SurpriseRemovalOK in the DeviceCaps so
    // that you don't get the popup in usermode (on Win2K) when you surprise
    // remove the device.
    //
    WDF_DEVICE_PNP_CAPABILITIES_INIT(&pnpCaps);
    pnpCaps.SurpriseRemovalOK = WdfTrue;

    WdfDeviceSetPnpCapabilities(device, &pnpCaps);

    // save the device object we created as our physical device object
    deviceExtension->PhysicalDeviceObject =
        WdfDeviceWdmGetPhysicalDevice (device);

    if (deviceExtension->PhysicalDeviceObject == NULL) {
        TRACE(TL_ERROR, ("WdfDeviceWdmGetPhysicalDevice: NULL DeviceObject\n"));
        return STATUS_UNSUCCESSFUL;
    }

    //
    // This is our default IoTarget representing the deviceobject
    // we are attached to.
    //
    deviceExtension->StackIoTarget = WdfDeviceGetIoTarget(device);
    deviceExtension->StackDeviceObject = WdfDeviceWdmGetAttachedDevice(device);

    if (deviceExtension->StackDeviceObject == NULL) {
        TRACE(TL_ERROR, ("WdfDeviceWdmGetAttachedDevice: NULL DeviceObject\n"));
        return STATUS_UNSUCCESSFUL;
    }

    //
    // Get the port device object from the passed in PhysicalDeviceObject
    // created by the 1394 stack for us.
    // Note: we can't use the top of the stack and get its device extension
    // in case there is a filter driver between us and our PDO.
    //
    pNodeExt = WdfDeviceWdmGetPhysicalDevice(device)->DeviceExtension;
    deviceExtension->PortDeviceObject = pNodeExt->PortDeviceObject;

    TRACE(TL_TRACE, ("PortDeviceObject = 0x%x\n",
                     deviceExtension->PortDeviceObject));

    //
    // Create a automanaged queue for dispatching ioctl requests.
    // All other requests are automatically failed by the framework.
    // By creating an automanaged queue we don't have to worry about
    // PNP/Power synchronization.
    // A default queue gets all the requests that are not
    // configure-fowarded using WdfDeviceConfigureRequestDispatching.
    //
    WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE(
        &ioQueueConfig,
        WdfIoQueueDispatchParallel
    );

    ioQueueConfig.EvtIoDeviceControl = t1394_EvtIoDeviceControl;

    status = WdfIoQueueCreate(
                 deviceExtension->WdfDevice,
                 &ioQueueConfig,
                 WDF_NO_OBJECT_ATTRIBUTES,
                 &deviceExtension->IoctlQueue // queue handle
             );

    if (!NT_SUCCESS (status)) {
         TRACE(TL_ERROR, ("WdfIoQueueCreate failed 0x%x\n", status));
        return status;
    }

    //
    // Create an additional queue to hold bus reset requests.
    //
    WDF_IO_QUEUE_CONFIG_INIT(
        &ioQueueConfig,
        WdfIoQueueDispatchManual
        );

    status = WdfIoQueueCreate (
                   deviceExtension->WdfDevice,
                   &ioQueueConfig,
                   WDF_NO_OBJECT_ATTRIBUTES,
                   &deviceExtension->BusResetRequestsQueue
                   );

    if(!NT_SUCCESS (status)){
        TRACE(TL_ERROR, ("Error Creating Reset Request Queue 0x%x\n",
                         status));
        return status;
    }

    //
    // Create another IoTarget representing PortDeviceObject so that
    // we can send async requests in rawmode directly to the port device.
    //
    WDF_IO_TARGET_OPEN_PARAMS_INIT_EXISTING_DEVICE(&openParams,
                                                pNodeExt->PortDeviceObject);
    status = WdfIoTargetCreate(device,
                                WDF_NO_OBJECT_ATTRIBUTES,
                                &deviceExtension->PortDeviceIoTarget);
    if (!NT_SUCCESS (status)) {
        TRACE(TL_ERROR, ("WdfIoTargetCreate failed 0x%x\n", status));
        return status;
    }

    status = WdfIoTargetOpen(deviceExtension->PortDeviceIoTarget, &openParams);
    if (!NT_SUCCESS (status)) {
        TRACE(TL_ERROR, ("WdfIoTargetCreate failed 0x%x\n", status));
        return status;
    }


    WDF_OBJECT_ATTRIBUTES_INIT(&lockAttributes);
    lockAttributes.ParentObject = device;
    // initialize the spinlock/list to store the bus reset irps...

    status = WdfSpinLockCreate(&lockAttributes,&deviceExtension->CromSpinLock );
    if(!NT_SUCCESS(status)){
         TRACE(TL_ERROR, ("WdfSpinLockCreate CromSpinLock "
                          "failed 0x%x\n", status));
        return status;
    }


    WDF_OBJECT_ATTRIBUTES_INIT(&lockAttributes);
    lockAttributes.ParentObject = device;

    status = WdfSpinLockCreate(&lockAttributes,
                               &deviceExtension->AsyncSpinLock );
    if(!NT_SUCCESS(status)){
         TRACE(TL_ERROR, ("WdfSpinLockCreate AsyncSpinLock "
                          "failed 0x%x\n", status));
        return status;
    }

    WDF_OBJECT_ATTRIBUTES_INIT(&lockAttributes);
    lockAttributes.ParentObject = device;

    status = WdfSpinLockCreate(&lockAttributes,
                               &deviceExtension->IsochSpinLock );
    if(!NT_SUCCESS(status)){
         TRACE(TL_ERROR, ("WdfSpinLockCreate IsochSpinLock "
                          "failed 0x%x\n", status));
        return status;
    }

    WDF_OBJECT_ATTRIBUTES_INIT(&lockAttributes);
    lockAttributes.ParentObject = device;

    status = WdfSpinLockCreate(&lockAttributes,
                               &deviceExtension->IsochResourceSpinLock );
    if(!NT_SUCCESS(status)){
         TRACE(TL_ERROR, ("WdfSpinLockCreate IsochResourceSpinLock "
                          "failed 0x%x\n", status));
        return status;
    }
    InitializeListHead(&deviceExtension->CromData);
    InitializeListHead(&deviceExtension->AsyncAddressData);
    InitializeListHead(&deviceExtension->IsochDetachData);
    InitializeListHead(&deviceExtension->IsochResourceData);

    EXIT("t1394_PnpAddDevice", status);

    return(status);
} // t1394_PnpAddDevice

NTSTATUS
t1394_EvtPrepareHardware (
    WDFDEVICE      Device,
    WDFCMRESLIST   Resources,
    WDFCMRESLIST   ResourcesTranslated
    )
/*++

Routine Description:

    EvtDeviceStart event callback performs operations that are necessary
    to make the driver's device operational. The framework calls the driver's
    EvtDeviceStart callback when the PnP manager sends an IRP_MN_START_DEVICE
    request to the driver stack.

Arguments:

    Device - Handle to a framework device object.

Return Value:

    WDF status code

--*/
{
    NTSTATUS            status = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension;

    UNREFERENCED_PARAMETER(Resources);
    UNREFERENCED_PARAMETER(ResourcesTranslated);

    PAGED_CODE();

    TRACE(TL_TRACE, ( "--> t1394_EvtPrepareHardware\n"));

    deviceExtension = GetDeviceContext(Device);

    status = t1394_BusResetNotification( Device,
                                         NULL,
                                         REGISTER_NOTIFICATION_ROUTINE );

    TRACE(TL_TRACE, ( "<-- t1394_EvtPrepareHardware\n"));

    return status;
}

NTSTATUS
t1394_EvtReleaseHardware(
    IN  WDFDEVICE Device,
    IN  WDFCMRESLIST ResourcesTranslated
    )
/*++

Routine Description:

    EvtDeviceReleaseHardware is called by the framework whenever the PnP manager
    is revoking ownership of our resources.  This may be in response to either
    IRP_MN_STOP_DEVICE or IRP_MN_REMOVE_DEVICE.  The callback is made before
    passing down the IRP to the lower driver.

    In this callback, do anything necessary to free those resources.

Arguments:

    Device - Handle to a framework device object.

Return Value:

    NTSTATUS - Failures will be logged, but not acted on.

--*/
{
    NTSTATUS status;

    UNREFERENCED_PARAMETER(ResourcesTranslated);

    PAGED_CODE();

    TRACE(TL_TRACE, ( "--> t1394_EvtReleaseHardware\n"));

    status = t1394_BusResetNotification(Device,
                                        NULL,
                                        DEREGISTER_NOTIFICATION_ROUTINE );

    TRACE(TL_TRACE, ( "<-- t1394_EvtReleaseHardware\n"));

    return status;
}

NTSTATUS
t1394_EvtDeviceD0Entry(
    IN  WDFDEVICE Device,
    IN  WDF_POWER_DEVICE_STATE PreviousState
    )
/*++

Routine Description:

    EvtDeviceD0Entry event callback must perform any operations that are
    necessary before the specified device is used.  It will be called every
    time the hardware needs to be (re-)initialized.  This includes after
    IRP_MN_START_DEVICE, IRP_MN_CANCEL_STOP_DEVICE, IRP_MN_CANCEL_REMOVE_DEVICE,
    IRP_MN_SET_POWER-D0.

    This function is not marked pageable because this function is in the
    device power up path. When a function is marked pagable and the code
    section is paged out, it will generate a page fault which could impact
    the fast resume behavior because the client driver will have to wait
    until the system drivers can service this page fault.

    This function runs at PASSIVE_LEVEL, even though it is not paged.  A
    driver can optionally make this function pageable if DO_POWER_PAGABLE
    is set.  Even if DO_POWER_PAGABLE isn't set, this function still runs
    at PASSIVE_LEVEL.  In this case, though, the function absolutely must
    not do anything that will cause a page fault.

Arguments:

    Device - Handle to a framework device object.

    PreviousState - Device power state which the device was in most recently.
        If the device is being newly started, this will be
        PowerDeviceUnspecified.

Return Value:

    NTSTATUS

--*/
{
    NTSTATUS   status = STATUS_SUCCESS;

    UNREFERENCED_PARAMETER(PreviousState);

    TRACE(TL_TRACE, (
                "-->t1394_EvtDeviceD0Entry - coming from %s\n",
                DbgDevicePowerString(PreviousState)));

    // update the generation count
    t1394_UpdateGenerationCount(Device);

    TRACE(TL_TRACE, ( "<--t1394_EvtDeviceD0Entry\n"));

    return status;
}


NTSTATUS
t1394_EvtDeviceD0Exit(
    IN  WDFDEVICE Device,
    IN  WDF_POWER_DEVICE_STATE TargetState
    )
/*++

Routine Description:

   EvtDeviceD0Exit event callback must perform any operations that are
   necessary before the specified device is moved out of the D0 state.  If the
   driver needs to save hardware state before the device is powered down, then
   that should be done here.

   This function runs at PASSIVE_LEVEL, though it is generally not paged.  A
   driver can optionally make this function pageable if DO_POWER_PAGABLE is set.

   Even if DO_POWER_PAGABLE isn't set, this function still runs at
   PASSIVE_LEVEL.  In this case, though, the function absolutely must not do
   anything that will cause a page fault.

Arguments:

    Device - Handle to a framework device object.

    TargetState - Device power state which the device will be put in once this
        callback is complete.

Return Value:

    NTSTATUS

--*/
{
    UNREFERENCED_PARAMETER(Device);
    UNREFERENCED_PARAMETER(TargetState);

    TRACE(TL_TRACE, (
                "-->t1394_EvtDeviceD0Exit - moving to %s\n",
                DbgDevicePowerString(TargetState)));

    PAGED_CODE();

    TRACE(TL_TRACE, ( "<--t1394_EvtDeviceD0Exit\n"));

    return STATUS_SUCCESS;
}


VOID
t1394_EvtDeviceSelfManagedIoCleanup(
    IN  WDFDEVICE Device
    )
/*++

Routine Description:

    EvtDeviceSelfManagedIoCleanup is called by the Framework when the device is
    being torn down, either in response to IRP_MN_REMOVE_DEVICE or
    IRP_MN_SURPRISE_REMOVE_DEVICE.  It will be called only once.  Its job is to
    stop all outstanding I/O in the driver that the Framework is not managing.

Arguments:

    Device - Handle to a framework device object.

Return Value:

    None

--*/
{
    PDEVICE_EXTENSION   deviceExtension;
    PLIST_ENTRY         listEntry;

    ENTER("t1394_PnpRemoveDevice");

    deviceExtension = GetDeviceContext(Device);

    TRACE(TL_WARNING, ("Removing 1394VDEV.SYS.\n"));

    // lets free up any crom data structs we've allocated...

    WdfSpinLockAcquire(deviceExtension->CromSpinLock);

    while (!IsListEmpty(&deviceExtension->CromData)) {

        PCROM_DATA      CromData;

        // get struct off list

        listEntry = RemoveHeadList(&deviceExtension->CromData);
        CromData = CONTAINING_RECORD(listEntry, CROM_DATA, CromList);

        // need to free up everything associated with this allocate...
        if (CromData)
        {
            if (CromData->Buffer)
                ExFreePoolWithTag(CromData->Buffer, POOLTAG_1394);

            if (CromData->pMdl)
                IoFreeMdl(CromData->pMdl);

            // we already checked CromData
            ExFreePoolWithTag(CromData, POOLTAG_1394);
        }
    }


    WdfSpinLockRelease(deviceExtension->CromSpinLock);

    // lets free up any allocated addresses and deallocate all
    // memory associated with them...

    WdfSpinLockAcquire(deviceExtension->AsyncSpinLock);

    while (!IsListEmpty(&deviceExtension->AsyncAddressData)) {

        PASYNC_ADDRESS_DATA     AsyncAddressData;

        // get struct off list
        listEntry = RemoveHeadList(&deviceExtension->AsyncAddressData);

        AsyncAddressData = CONTAINING_RECORD(listEntry, ASYNC_ADDRESS_DATA,
                                                                            AsyncAddressList);

        // need to free up everything associated with this allocate...
        if (AsyncAddressData->pMdl)
            IoFreeMdl(AsyncAddressData->pMdl);

        if (AsyncAddressData->Buffer)
            ExFreePoolWithTag(AsyncAddressData->Buffer, POOLTAG_1394);

        if (AsyncAddressData->AddressRange)
            ExFreePoolWithTag(AsyncAddressData->AddressRange, POOLTAG_1394);

        ExFreePoolWithTag(AsyncAddressData, POOLTAG_1394);
    }


    WdfSpinLockRelease(deviceExtension->AsyncSpinLock);

    //
    // Free up any attached isoch buffers
    // TODO: There are known bugs in this code path
    //
    WHILE (TRUE) {

        WdfSpinLockAcquire(deviceExtension->IsochSpinLock);

        if (!IsListEmpty(&deviceExtension->IsochDetachData)) {

            PISOCH_DETACH_DATA  IsochDetachData;

            IsochDetachData = (PISOCH_DETACH_DATA)
                RemoveHeadList(&deviceExtension->IsochDetachData);

            TRACE(TL_TRACE, ("Surprise Removal: IsochDetachData = 0x%x\n",
                             IsochDetachData));

            KeCancelTimer(&IsochDetachData->Timer);

            WdfSpinLockRelease(deviceExtension->IsochSpinLock);

            TRACE(TL_TRACE, ("Surprise Removal: IsochDetachData->Irp = 0x%x\n",
                             IsochDetachData->Request));

            // need to save the status of the attach
            // we'll clean up in the same spot for success's and timeout's
            IsochDetachData->AttachStatus = STATUS_SUCCESS;

            // detach no matter what...
            IsochDetachData->bDetach = TRUE;

            t1394_IsochCleanup(IsochDetachData);
        }
        else {

            WdfSpinLockRelease(deviceExtension->IsochSpinLock);
            break;
        }
    }

    //
    // Remove any isoch resource data
    //
    WHILE (TRUE) {

        WdfSpinLockAcquire(deviceExtension->IsochResourceSpinLock);

        if (!IsListEmpty(&deviceExtension->IsochResourceData)) {

            PISOCH_RESOURCE_DATA    IsochResourceData = NULL;

            listEntry = RemoveHeadList(&deviceExtension->CromData);

            IsochResourceData = CONTAINING_RECORD(listEntry,
                                                  ISOCH_RESOURCE_DATA,
                                                  IsochResourceList);

            WdfSpinLockRelease(deviceExtension->IsochResourceSpinLock);

            TRACE(TL_TRACE, ("Surprise Removal: IsochResourceData = 0x%x\n",
                             IsochResourceData));

            if (IsochResourceData) {

                PIRB          pIrb;
                WDFREQUEST    request;
             NTSTATUS status;

                TRACE(TL_TRACE, ("Surprise Removal: Freeing hResource = 0x%x\n",
                                 IsochResourceData->hResource));

                status = WdfRequestCreate(
                    WDF_NO_OBJECT_ATTRIBUTES,
                    deviceExtension->StackIoTarget,
                    &request);

                if (!NT_SUCCESS(status)) {
                    TRACE(TL_ERROR, ("Failed to allocate request %x\n", status));
                }
                else {

                    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

                    if (!pIrb) {

                        WdfObjectDelete(request);

                        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
                    }
                    else {

                        RtlZeroMemory (pIrb, sizeof (IRB));
                        pIrb->FunctionNumber = REQUEST_ISOCH_FREE_RESOURCES;
                        pIrb->Flags = 0;
                        pIrb->u.IsochFreeResources.hResource = IsochResourceData->hResource;

                        status = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, request, pIrb);

                        if (!NT_SUCCESS(status)) {

                            TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", status));
                        }

                        ExFreePoolWithTag(pIrb, POOLTAG_1394);
                        WdfObjectDelete(request);
                    }
                }
            }
        }
        else {


            WdfSpinLockRelease(deviceExtension->IsochResourceSpinLock);
            break;
        }
    }

    EXIT("t1394_PnpRemoveDevice", STATUS_SUCCESS);

} // t1394_PnpRemoveDevice


PCHAR
DbgDevicePowerString(
    IN WDF_POWER_DEVICE_STATE Type
    )
/*++

Updated Routine Description:
    DbgDevicePowerString does not change in this stage of the function driver.

--*/
{
    PAGED_CODE();

    switch (Type) {
    case WdfPowerDeviceInvalid:
        return "WdfPowerDeviceInvalid";
    case WdfPowerDeviceD0:
        return "WdfPowerDeviceD0";
    case PowerDeviceD1:
        return "WdfPowerDeviceD1";
    case WdfPowerDeviceD2:
        return "WdfPowerDeviceD2";
    case WdfPowerDeviceD3:
        return "WdfPowerDeviceD3";
    case WdfPowerDeviceD3Final:
        return "WdfPowerDeviceD3Final";
    case WdfPowerDevicePrepareForHibernation:
        return "WdfPowerDevicePrepareForHibernation";
    case WdfPowerDeviceMaximum:
        return "PowerDeviceMaximum";
    default:
        return "UnKnown Device Power State";
    }
}



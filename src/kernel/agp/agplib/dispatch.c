/*++

Copyright (c) 1997  Microsoft Corporation

Module Name:

    dispatch.c

Abstract:

    IRP dispatching routines for the common AGPLIB library


--*/
#include "agplib.h"

//
// Two flavors of each dispatch routine, one for the target (AGP bridge) filter and
// one for the master (video card) filter.
//

NTSTATUS
AgpTargetDispatchPnp(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp,
    IN PTARGET_EXTENSION Extension
    );

NTSTATUS
AgpMasterDispatchPnp(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp,
    IN PMASTER_EXTENSION Extension
    );

NTSTATUS
AgpTargetDispatchPower(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp,
    IN PTARGET_EXTENSION Extension
    );

NTSTATUS
AgpMasterDispatchPower(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp,
    IN PMASTER_EXTENSION Extension
    );

IO_COMPLETION_ROUTINE AgpMasterPowerUpCompletion;

IO_COMPLETION_ROUTINE AgpTargetPowerUpCompletion;

NTSTATUS
AgpLibValidateAgp(
    IN PMASTER_EXTENSION Extension
    );

#ifdef ALLOC_PRAGMA
#pragma alloc_text(PAGE, AgpDispatchPnp)
#pragma alloc_text(PAGE, AgpDispatchDeviceControl)
#pragma alloc_text(PAGE, AgpDispatchWmi)
#pragma alloc_text(PAGE, AgpTargetDispatchPnp)
#pragma alloc_text(PAGE, AgpMasterDispatchPnp)
#endif



NTSTATUS
AgpDispatchPnp(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp
    )
/*++

Routine Description:

    Main dispatch routine for PNP irps sent to the AGP bus filter driver

Arguments:

    DeviceObject - Supplies the AGP device object

    Irp - Supplies the PNP Irp.

Return Value:

    NTSTATUS

--*/
{
    PCOMMON_EXTENSION Extension = DeviceObject->DeviceExtension;

    PAGED_CODE();

    //
    // We're deleted, fail the irp
    //
    if (Extension->Deleted == TRUE) {
        Irp->IoStatus.Status = STATUS_DELETE_PENDING;
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
        return STATUS_DELETE_PENDING;
    }

    ASSERT(Extension->AttachedDevice != NULL);

    if (Extension->Type == AgpTargetFilter) {
        return(AgpTargetDispatchPnp(DeviceObject,
                                    Irp,
                                    DeviceObject->DeviceExtension));
    } else {
        ASSERT(Extension->Type == AgpMasterFilter);
        return(AgpMasterDispatchPnp(DeviceObject,
                                    Irp,
                                    DeviceObject->DeviceExtension));
    }
}


NTSTATUS
AgpDispatchPower(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp
    )
/*++

Routine Description:

    Main dispatch routine for power irps sent to the AGP bus filter driver

Arguments:

    DeviceObject - Supplies the AGP device object

    Irp - Supplies the power Irp.

Return Value:

    NTSTATUS

--*/
{
    PCOMMON_EXTENSION Extension = DeviceObject->DeviceExtension;

    //
    // We're deleted, fail the irp
    //
    if (Extension->Deleted == TRUE) {
        Irp->IoStatus.Status = STATUS_DELETE_PENDING;
        PoStartNextPowerIrp(Irp);
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
        return STATUS_DELETE_PENDING;
    }

    ASSERT(Extension->AttachedDevice != NULL);

   if (Extension->Type == AgpTargetFilter) {
        return(AgpTargetDispatchPower(DeviceObject,
                                      Irp,
                                      DeviceObject->DeviceExtension));
    } else {
        ASSERT(Extension->Type == AgpMasterFilter);
        return(AgpMasterDispatchPower(DeviceObject,
                                      Irp,
                                      DeviceObject->DeviceExtension));
    }
}


NTSTATUS
AgpTargetDispatchPnp(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp,
    IN PTARGET_EXTENSION Extension
    )
/*++

Routine Description:

    Dispatch routine for PNP irps sent to the AGP bus filter driver
    attached to the target (AGP bridge) PDO.

Arguments:

    DeviceObject - Supplies the AGP target device object

    Irp - Supplies the PNP Irp.

    Extension - Supplies the AGP target device extension

Return Value:

    NTSTATUS

--*/

{
    NTSTATUS Status = STATUS_NOT_SUPPORTED;
    PIO_STACK_LOCATION  irpStack        = IoGetCurrentIrpStackLocation( Irp );

    PAGED_CODE();

    AGPLOG(AGP_IRPTRACE,
           ("AgpTargetDispatchPnp: IRP 0x%x\n", irpStack->MinorFunction));

    switch (irpStack->MinorFunction) {
        case IRP_MN_FILTER_RESOURCE_REQUIREMENTS:
            AGPLOG(AGP_NOISE,
                   ("AgpTargetDispatchPnp: IRP_MN_FILTER_RESOURCE_REQUIREMENTS to %p\n",
                    DeviceObject));

            Status = AgpFilterResourceRequirements(DeviceObject, Irp, Extension);
            break;

        case IRP_MN_QUERY_RESOURCES:
            AGPLOG(AGP_NOISE,
                   ("AgpTargetDispatchPnp: IRP_MN_QUERY_RESOURCES to %p\n",
                    DeviceObject));

            //
            // We must handle this IRP on the way back so we can add the AGP
            // resources on to it. Set a completion routine.
            //
            IoCopyCurrentIrpStackLocationToNext(Irp);
            IoSetCompletionRoutine(Irp,
                                   AgpQueryResources,
                                   Extension,
                                   TRUE,
                                   FALSE,
                                   FALSE);
            Status = IoCallDriver(Extension->CommonExtension.AttachedDevice, Irp);
            return Status ;

        case IRP_MN_QUERY_DEVICE_RELATIONS:
            if (irpStack->Parameters.QueryDeviceRelations.Type == BusRelations) {
                KEVENT event;

                KeInitializeEvent(&event, NotificationEvent, FALSE);

                //
                // We must handle this IRP on the way back so that we can attach
                // a filter to any child PDOs of our PCI-PCI bridge.
                //
                IoCopyCurrentIrpStackLocationToNext(Irp);
                IoSetCompletionRoutine(Irp,
                                       AgpSetEventCompletion,
                                       &event,
                                       TRUE,
                                       TRUE,
                                       TRUE);

                Status = IoCallDriver(Extension->CommonExtension.AttachedDevice, Irp);

                //
                // If we did things asynchronously then wait on our event
                //
                if (Status == STATUS_PENDING) {

                    //
                    // We do a KernelMode wait so that our stack where the
                    // event is doesn't get paged out!
                    //
                    KeWaitForSingleObject(&event,
                                          Executive,
                                          KernelMode,
                                          FALSE,
                                          NULL);
                    Status = Irp->IoStatus.Status;
                }

                if (NT_SUCCESS(Status)) {
                    Status = AgpAttachDeviceRelations(DeviceObject,
                                                      Irp,
                                                      Extension);
                    Irp->IoStatus.Status = Status;
                }

                IoCompleteRequest(Irp, IO_NO_INCREMENT);
                return Status;

            } else {
                break;
            }

        case IRP_MN_START_DEVICE:
            //
            // We need to hook this in order to filter out any AGP
            // resources that have been added.
            //
            return(AgpStartTarget(Irp, Extension));

        case IRP_MN_QUERY_REMOVE_DEVICE:
        case IRP_MN_QUERY_STOP_DEVICE:
        case IRP_MN_CANCEL_REMOVE_DEVICE:

            //
            // We can always succeed this.
            //
            Status = STATUS_SUCCESS;
            break;

        case IRP_MN_REMOVE_DEVICE:
            AgpDisableAperture(GET_AGP_CONTEXT(Extension));

            //
            // Pass the irp down
            //
            IoSkipCurrentIrpStackLocation(Irp);
            Status = IoCallDriver(Extension->CommonExtension.AttachedDevice, Irp);

            //
            // Clean up and delete ourselves
            //
            AgpWmiDeRegistration(Extension);
            AgpVerifierStop(Extension);
            Extension->CommonExtension.Deleted = TRUE;
            IoDetachDevice(Extension->CommonExtension.AttachedDevice);
            Extension->CommonExtension.AttachedDevice = NULL;
            RELEASE_BUS_INTERFACE(Extension);
            if (Extension->FavoredMemory.Ranges) {
               ExFreePool(Extension->FavoredMemory.Ranges);
            }
            if (Extension->Resources) {
                ExFreePool(Extension->Resources);
            }
            if (Extension->ResourcesTranslated) {
                ExFreePool(Extension->ResourcesTranslated);
            }
            //ExFreePool(Extension->Lock);
            IoDeleteDevice(DeviceObject);
            return(Status);

        case IRP_MN_STOP_DEVICE:
            AgpDisableAperture(GET_AGP_CONTEXT(Extension));
            Status = STATUS_SUCCESS;
            break;  // forward irp down the stack

    }

    ASSERT(Status != STATUS_PENDING);

    if (Status != STATUS_NOT_SUPPORTED) {

        Irp->IoStatus.Status = Status;
    }

    if (NT_SUCCESS(Status) || (Status == STATUS_NOT_SUPPORTED)) {

        //
        // Forward IRP to PCI driver
        //
        IoSkipCurrentIrpStackLocation(Irp);
        return(IoCallDriver(Extension->CommonExtension.AttachedDevice, Irp));

    } else {

        Status = Irp->IoStatus.Status;
        IoCompleteRequest(Irp, IO_NO_INCREMENT) ;
        return Status ;
    }
}


NTSTATUS
AgpDispatchDeviceControl(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp
    )
/*++

Routine Description:

    Main dispatch routine for device control irps sent to the AGP bus filter driver

    AGP currently does not support any device controls. So we just pass everything
    down and hope the PDO knows what to do with it.

Arguments:

    DeviceObject - Supplies the AGP device object

    Irp - Supplies the power Irp.

Return Value:

    NTSTATUS

--*/
{
    PCOMMON_EXTENSION Extension = DeviceObject->DeviceExtension;
    PAGED_CODE();

    //
    // We're deleted, fail the irp
    //
    if (Extension->Deleted == TRUE) {
        Irp->IoStatus.Status = STATUS_DELETE_PENDING;
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
        return STATUS_DELETE_PENDING;
    }

    ASSERT(Extension->AttachedDevice != NULL);

    IoSkipCurrentIrpStackLocation(Irp);
    return(IoCallDriver(Extension->AttachedDevice, Irp));
}


NTSTATUS
AgpDispatchWmi(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp
    )
/*++

Routine Description:

    Main dispatch routine for system control irps sent to the AGP bus filter
    driver.

    AGP currently does not support any WMI IRPs, so we just pass everything
    down and hope the PDO knows what to do with it.

Arguments:

    DeviceObject - Supplies the AGP device object

    Irp - Supplies the power Irp.

Return Value:

    NTSTATUS

--*/
{
    PCOMMON_EXTENSION Extension = DeviceObject->DeviceExtension;
    PAGED_CODE();

    //
    // We're deleted, fail the irp
    //
    if (Extension->Deleted == TRUE) {
        Irp->IoStatus.Status = STATUS_DELETE_PENDING;
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
        return STATUS_DELETE_PENDING;
    }

    ASSERT(Extension->AttachedDevice != NULL);

    //
    // Return AGP info for target device
    //
    if (Extension->Type == AgpTargetFilter) {
        return AgpSystemControl(DeviceObject, Irp);
    }

    IoSkipCurrentIrpStackLocation(Irp);
    return(IoCallDriver(Extension->AttachedDevice, Irp));
}


NTSTATUS
AgpTargetDispatchPower(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp,
    IN PTARGET_EXTENSION Extension
    )
{
    PIO_STACK_LOCATION  irpStack        = IoGetCurrentIrpStackLocation( Irp );

    AGPLOG(AGP_IRPTRACE,
           ("AgpTargetDispatchPower: IRP 0x%x\n", irpStack->MinorFunction));

    //
    // All we keep track of are Dx states. PCI is responsible for mapping
    // S-states into D states.
    //


    if ((irpStack->MinorFunction == IRP_MN_SET_POWER) &&
        (irpStack->Parameters.Power.Type == DevicePowerState) &&
        (irpStack->Parameters.Power.State.DeviceState == PowerDeviceD0)) {

        NTSTATUS Status;

        //
        // We need to reinitialize the target when this IRP has been completed
        // by the lower drivers. Set up our completion handler to finish this.
        //
        IoCopyCurrentIrpStackLocationToNext(Irp);
        IoSetCompletionRoutine(Irp,
                               AgpTargetPowerUpCompletion,
                               Extension,
                               TRUE,
                               FALSE,
                               FALSE);

        IoMarkIrpPending(Irp);
        PoStartNextPowerIrp(Irp);
        Status = PoCallDriver(Extension->CommonExtension.AttachedDevice, Irp);
        return STATUS_PENDING;
    }

    //
    // Just forward to target device
    //
    PoStartNextPowerIrp(Irp);
    IoSkipCurrentIrpStackLocation(Irp);
    return(PoCallDriver(Extension->CommonExtension.AttachedDevice, Irp));
}


NTSTATUS
AgpMasterDispatchPnp(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp,
    IN PMASTER_EXTENSION Extension
    )
/*++

Routine Description:

    Dispatch routine for PNP irps sent to the AGP bus filter driver
    attached to the device PDOs.

Arguments:

    DeviceObject - Supplies the AGP device object

    Irp - Supplies the PNP Irp.

    Extension - Supplies the AGP bridge device extension

Return Value:

    NTSTATUS

--*/

{
    PIO_STACK_LOCATION  irpStack        = IoGetCurrentIrpStackLocation( Irp );
    PAGP_BUS_INTERFACE_STANDARD Interface;
    NTSTATUS Status;

    PAGED_CODE();

    AGPLOG(AGP_IRPTRACE,
           ("AgpMasterDispatchPnp: IRP 0x%x\n", irpStack->MinorFunction));

    switch (irpStack->MinorFunction) {
        case IRP_MN_QUERY_INTERFACE:

#if 0
            AGPLOG(AGP_IRPTRACE,
                   ("\tSize=0x%x, Version=%d\n"
                    "\tGUID=0x%08x-0x%04x-0x%04x-0x%02x-"
                    "0x%02x-0x%02x-0x%02x-0x%02x-0x%02x-0x%02x-0x%02x\n",
                    irpStack->Parameters.QueryInterface.Size,
                    irpStack->Parameters.QueryInterface.Version,
                    *(PULONG)irpStack->Parameters.QueryInterface.InterfaceType,
                    *((PUSHORT)irpStack->Parameters.QueryInterface.InterfaceType + 2),
                    *((PUSHORT)irpStack->Parameters.QueryInterface.InterfaceType + 3),
                    *((PUCHAR)irpStack->Parameters.QueryInterface.InterfaceType + 8),
                    *((PUCHAR)irpStack->Parameters.QueryInterface.InterfaceType + 9),
                    *((PUCHAR)irpStack->Parameters.QueryInterface.InterfaceType + 10),

                    *((PUCHAR)irpStack->Parameters.QueryInterface.InterfaceType + 11),
                    *((PUCHAR)irpStack->Parameters.QueryInterface.InterfaceType + 12),
                    *((PUCHAR)irpStack->Parameters.QueryInterface.InterfaceType + 13),
                    *((PUCHAR)irpStack->Parameters.QueryInterface.InterfaceType + 14),
                    *((PUCHAR)irpStack->Parameters.QueryInterface.InterfaceType + 15)));

#endif

            //
            // The only IRP we look for here is IRP_MN_QUERY_INTERFACE for
            // GUID_AGP_BUS_INTERFACE_STANDARD.
            //
            if ((RtlEqualMemory(
                irpStack->Parameters.QueryInterface.InterfaceType,
                &GUID_AGP_BUS_INTERFACE_STANDARD,
                sizeof(GUID))) &&
                (((irpStack->Parameters.QueryInterface.Size >=
                   sizeof(AGP_BUS_INTERFACE_STANDARD)) &&
                  (irpStack->Parameters.QueryInterface.Version ==
                   AGP_BUS_INTERFACE_V5)) ||
                  ((irpStack->Parameters.QueryInterface.Size >=
                   AGP_BUS_INTERFACE_V4_SIZE) &&
                  (irpStack->Parameters.QueryInterface.Version ==
                   AGP_BUS_INTERFACE_V4)) ||                   
                 ((irpStack->Parameters.QueryInterface.Size >=
                   AGP_BUS_INTERFACE_V3_SIZE) &&
                  (irpStack->Parameters.QueryInterface.Version ==
                   AGP_BUS_INTERFACE_V3)) ||
                 ((irpStack->Parameters.QueryInterface.Size >=
                   AGP_BUS_INTERFACE_V2_SIZE) &&
                  (irpStack->Parameters.QueryInterface.Version ==
                   AGP_BUS_INTERFACE_V2)) ||
                 ((irpStack->Parameters.QueryInterface.Size >=
                   AGP_BUS_INTERFACE_V1_SIZE) &&
                  (irpStack->Parameters.QueryInterface.Version ==
                   AGP_BUS_INTERFACE_V1))) &&
                NT_SUCCESS(AgpLibValidateAgp(Extension))) {

                Interface = (PAGP_BUS_INTERFACE_STANDARD)irpStack->Parameters.QueryInterface.Interface;

                Interface->Version =
                    irpStack->Parameters.QueryInterface.Version;
                Interface->AgpContext = Extension;
                Interface->InterfaceReference = AgpInterfaceReference;
                Interface->InterfaceDereference = AgpInterfaceDereference;
                Interface->ReserveMemory = AgpInterfaceReserveMemory;
                Interface->ReleaseMemory = AgpInterfaceReleaseMemory;
                Interface->CommitMemory = AgpInterfaceCommitMemory;
                Interface->FreeMemory = AgpInterfaceFreeMemory;
                Interface->GetMappedPages = AgpInterfaceGetMappedPages;

                Status = STATUS_SUCCESS;
                if (Interface->Version == AGP_BUS_INTERFACE_V1) 
                {
                    Interface->Size = AGP_BUS_INTERFACE_V1_SIZE;                
                } 
                else 
                {
                    Interface->SetRate = AgpInterfaceSetRate;
                
                    if (Interface->Version == AGP_BUS_INTERFACE_V2) 
                    {
                        Interface->Size = sizeof(AGP_BUS_INTERFACE_V2_SIZE);
                    } 
                    else 
                    {
                        Interface->MaxPhysicalAddress = AgpMaximumAddress;
                        Interface->MapMemory = AgpInterfaceMapMemory;
                        Interface->UnMapMemory = AgpInterfaceUnMapMemory;
                        Interface->AgpBase = Extension->Target->GartBase;
                        Interface->AgpSize = Extension->Target->GartLengthInPages * PAGE_SIZE;

                        if (Interface->Version == AGP_BUS_INTERFACE_V3) 
                        {
                            Interface->Size = sizeof(AGP_BUS_INTERFACE_V3_SIZE);
                        }
                        else
                        {
                            
                            Interface->FlushChipsetCaches = AgpInterfaceFlushChipsetCaches;
                            Interface->CheckIntegrity = AgpInterfaceCheckIntegrity;

                            if (Interface->Version == AGP_BUS_INTERFACE_V4) 
                            {
                                Interface->Size = sizeof(AGP_BUS_INTERFACE_V4_SIZE);
                            }
                            else
                            {
                                Interface->Size = sizeof(AGP_BUS_INTERFACE_STANDARD);
                                Interface->MapMemoryEx = AgpInterfaceMapMemoryEx;
                                Interface->UnMapMemoryEx = AgpInterfaceUnMapMemoryEx;
                                Interface->FlushGartTLB = AgpInterfaceFlushGartTLB;
                                Interface->CheckGuardPage = AgpInterfaceCheckGuardPage;
                                Interface->GetAgpInfo = AgpInterfaceGetAgpInfo;
                            }
                        }
                    }
                }

                Interface->Capabilities = Extension->Capabilities;

                //
                // Reference this interface. 
                //

                if (NT_SUCCESS(Status)) 
                {
                    Interface->InterfaceReference(Extension);
                }

                //
                // Complete the IRP successfully
                //
                Irp->IoStatus.Status = Status;
                // AGPLOG(AGP_IRPTRACE, ("\tOK.\n"));
            } // else { AGPLOG(AGP_IRPTRACE, ("\tNO!\n")); }
            break;

        case IRP_MN_REMOVE_DEVICE:
            if (0 != Extension->InterfaceCount) 
            {
                KeBugCheckEx(AGP_INTERNAL,
                             AGP_BUGCHECK_INTERFACE_NOT_RELEASE,
                             Extension->InterfaceCount,
                             0,
                             0);
            }
            
            AGPLOG(AGP_NOISE,
                   ("AgpMasterDispatchPnp: removing device due to IRP_MN_REMOVE_DEVICE\n"));

            //
            // PNP is supposed to send us a QUERY_REMOVE before any REMOVE. That is
            // when we check that we are actually in a state where we can be removed.
            // Like all PNP rules, there is an exception - if the START is failed
            // after we have succeeded it, then we get a REMOVE without a QUERY_REMOVE.
            // Obviously this is totally fatal if we have given out interfaces or
            // have pages mapped in the GART. Not much we can do about it then.
            //
            ASSERT(Extension->InterfaceCount == 0);
            ASSERT(Extension->ReservedPages == 0);

            //
            // Ignore the remove request and just send the IRP down. We can't remove ourself 
            // from the stack since we won't get another chance of getting onto the stack 
            // otherwise.
            //
            break;

        case IRP_MN_STOP_DEVICE:
            if (0 != Extension->InterfaceCount) 
            {
                KeBugCheckEx(AGP_INTERNAL,
                             AGP_BUGCHECK_INTERFACE_NOT_RELEASE,
                             Extension->InterfaceCount,
                             0,
                             0);
            }            
            AGPLOG(AGP_NOISE,
                   ("AgpMasterDispatchPnp: stopping device due to IRP_MN_STOP_DEVICE\n"));

            //
            // Just pass the IRP on down
            //
            break;

        case IRP_MN_START_DEVICE:
            AGPLOG(AGP_NOISE,
                   ("AgpMasterDispatchPnp: starting device due to IRP_MN_START_DEVICE\n"));
            break;  // forward IRP down the stack
    }

    //
    // Just forward to target device
    //
    IoSkipCurrentIrpStackLocation(Irp);
    return(IoCallDriver(Extension->CommonExtension.AttachedDevice, Irp));
}

NTSTATUS
AgpMasterDispatchPower(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp,
    IN PMASTER_EXTENSION Extension
    )
{
    PIO_STACK_LOCATION  irpStack        = IoGetCurrentIrpStackLocation( Irp );

    AGPLOG(AGP_IRPTRACE,
           ("AgpMasterDispatchPower: IRP 0x%x\n", irpStack->MinorFunction));

    //
    // All we keep track of are Dx states. Videoport is responsible for mapping
    // S-states into D states.
    //
    if ((irpStack->MinorFunction == IRP_MN_SET_POWER) &&
        (irpStack->Parameters.Power.Type == DevicePowerState) &&
        (irpStack->Parameters.Power.State.DeviceState == PowerDeviceD0)) {

        NTSTATUS Status;

        //
        // We need to reinitialize the master when this IRP has been completed
        // by the lower drivers. Set up a completion routine.
        //
        IoCopyCurrentIrpStackLocationToNext(Irp);
        IoSetCompletionRoutine(Irp,
                               AgpMasterPowerUpCompletion,
                               Extension,
                               TRUE,
                               FALSE,
                               FALSE);

        IoMarkIrpPending(Irp);
        PoStartNextPowerIrp(Irp);
        Status = PoCallDriver(Extension->CommonExtension.AttachedDevice, Irp);
        return STATUS_PENDING;
    }

    //
    // Just forward to target device
    //
    PoStartNextPowerIrp(Irp);
    IoSkipCurrentIrpStackLocation(Irp);
    return(PoCallDriver(Extension->CommonExtension.AttachedDevice, Irp));
}


NTSTATUS
AgpMasterPowerUpCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PMASTER_EXTENSION Extension
    )
/*++

Routine Description:

    Powerup completion routine for the master device. It reinitializes the
    master registers.

Arguments:

    DeviceObject - supplies the master device object.

    Irp - Supplies the IRP_MN_SET_POWER irp.

    Extension - Supplies the master extension

Return Value:

    Status

--*/

{
    NTSTATUS Status;
    ULONG CurrentCapabilities;

    if (Irp->PendingReturned) {
        IoMarkIrpPending(Irp);
    }

    Status = AgpInitializeMaster(GET_AGP_CONTEXT_FROM_MASTER(Extension),
                                 &CurrentCapabilities);
    ASSERT(CurrentCapabilities == Extension->Capabilities);
    if (!NT_SUCCESS(Status)) {
        Irp->IoStatus.Status = Status;
    }

    return STATUS_SUCCESS;
}


NTSTATUS
AgpTargetPowerUpCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PTARGET_EXTENSION Extension
    )
/*++

Routine Description:

    Powerup completion routine for the target device. It reinitializes the
    GART aperture

Arguments:

    DeviceObject - supplies the master device object.

    Irp - Supplies the IRP_MN_SET_POWER irp.

    Extension - Supplies the target extension

Return Value:

    Status

--*/

{
    NTSTATUS Status;

    if (Irp->PendingReturned) {
        IoMarkIrpPending(Irp);
    }

    //
    // Now it is safe to reinitialize the target. All we do here
    // is reset the aperture
    //
    if (Extension->GartLengthInPages != 0) {
        Status = AgpSetAperture(GET_AGP_CONTEXT(Extension),
                                Extension->GartBase,
                                Extension->GartLengthInPages);
        if (!NT_SUCCESS(Status)) {
            Irp->IoStatus.Status = Status;
        }
    }

    return STATUS_SUCCESS;
}


NTSTATUS
AgpSetEventCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PKEVENT Event
    )
/*++

Routine Description:

    This routine is used as a completion routine when an IRP is passed
    down the stack but more processing must be done on the way back up.
    The effect of using this as a completion routine is that the IRP
    will not be destroyed in IoCompleteRequest as called by the lower
    level object.  The event which is a KEVENT is signaled to allow
    processing to continue

Arguments:

    DeviceObject - Supplies the device object

    Irp - The IRP we are processing

    Event - Supplies the event to be signaled

Return Value:

    STATUS_MORE_PROCESSING_REQUIRED

--*/

{
    ASSERT(Event);

    //
    // This can be called at DISPATCH_LEVEL so must not be paged
    //
    KeSetEvent(Event, IO_NO_INCREMENT, FALSE);

    return STATUS_MORE_PROCESSING_REQUIRED;
}

VOID
AGPFastIoDetachCallback(
    __in  PDEVICE_OBJECT  DeviceObject,
    __in  PDEVICE_OBJECT  LowerDeviceObject
    )
/*++

Routine Description:

    This routine is called when the device object beneath this bus filter
    has called IoDeleteDevice. We detach and delete ourselves now...

Arguments:

    DeviceObject        - The DeviceObject that must be removed
    LowerDeviceObject   - The DeviceObject we are detaching from.

Return Value:

--*/
{
    PMASTER_EXTENSION Extension = (PMASTER_EXTENSION)DeviceObject->DeviceExtension;

    ASSERT(Extension->CommonExtension.AttachedDevice == LowerDeviceObject);

    //
    // For AGP Master FDO we remove ourself from the stack when PCI send us this
    // request. For AGP Master FDO we can't remove ourself from the driver stack
    // during IRP_MN_REMOVE_DEVICE since we wouldn't have any way of getting back
    // onto the stack when it is rebuilt (ex: driver upgrade). This request is
    // sent by PCI when the PDO is really going away.
    //

    if (Extension->CommonExtension.Type == AgpMasterFilter)
    {
        //
        // Make sure the target knows there is no longer any master on the bus.
        //
        
        Extension->Target->ChildDevice = NULL;
        
        //
        // Mark the extension as deleted (so it's easy to see in the debugger 
        // that this extension was freed in case we ever touch it afterward.
        //

        Extension->CommonExtension.Deleted = TRUE;
        
        //
        // Detach ourself from the GPU driver stack.
        //

        IoDetachDevice(Extension->CommonExtension.AttachedDevice);
        Extension->CommonExtension.AttachedDevice = NULL;

        //
        // Release our bus interface. 
        //

        RELEASE_BUS_INTERFACE(Extension);
        
        //
        // Destroy this device.
        //

        IoDeleteDevice(DeviceObject);
    }
}


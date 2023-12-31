/*++

Copyright (c) 1998  Microsoft Corporation

Module Name:

    isochapi.c

Abstract

--*/

#include "pch.h"


NTSTATUS
t1394_IsochAllocateBandwidth(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN ULONG            nMaxBytesPerFrameRequested,
    IN ULONG            fulSpeed,
    OUT PHANDLE         phBandwidth,
    OUT PULONG          pBytesPerFrameAvailable,
    OUT PULONG          pSpeedSelected
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_IsochAllocateBandwidth");

    TRACE(TL_TRACE, ("nMaxBytesPerFrameRequested = 0x%x\n", nMaxBytesPerFrameRequested));
    TRACE(TL_TRACE, ("fulSpeed = 0x%x\n", fulSpeed));

    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochAllocateBandwidth;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ISOCH_ALLOCATE_BANDWIDTH;
    pIrb->Flags = 0;
    pIrb->u.IsochAllocateBandwidth.nMaxBytesPerFrameRequested = nMaxBytesPerFrameRequested;
    pIrb->u.IsochAllocateBandwidth.fulSpeed = fulSpeed;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (NT_SUCCESS(ntStatus)) {

        *phBandwidth = pIrb->u.IsochAllocateBandwidth.hBandwidth;
        *pBytesPerFrameAvailable = pIrb->u.IsochAllocateBandwidth.BytesPerFrameAvailable;
        *pSpeedSelected = pIrb->u.IsochAllocateBandwidth.SpeedSelected;

        TRACE(TL_TRACE, ("hBandwidth = 0x%x\n", *phBandwidth));
        TRACE(TL_TRACE, ("BytesPerFrameAvailable = 0x%x\n", *pBytesPerFrameAvailable));

        // lets see if we got the speed we wanted
        if (fulSpeed != pIrb->u.IsochAllocateBandwidth.SpeedSelected) {

            TRACE(TL_TRACE, ("Different bandwidth speed selected.\n"));
        }

        TRACE(TL_TRACE, ("SpeedSelected = 0x%x\n", *pSpeedSelected));
    }
    else {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_IsochAllocateBandwidth:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_IsochAllocateBandwidth", ntStatus);
    return(ntStatus);
} // t1394_IsochAllocateBandwidth

NTSTATUS
t1394_IsochAllocateChannel(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN ULONG            nRequestedChannel,
    OUT PULONG          pChannel,
    OUT PLARGE_INTEGER  pChannelsAvailable
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_IsochAllocateChannel");

    TRACE(TL_TRACE, ("nRequestedChannel = 0x%x\n", nRequestedChannel));

    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochAllocateChannel;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ISOCH_ALLOCATE_CHANNEL;
    pIrb->Flags = 0;
    pIrb->u.IsochAllocateChannel.nRequestedChannel = nRequestedChannel;

        ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (NT_SUCCESS(ntStatus)) {

        *pChannel = pIrb->u.IsochAllocateChannel.Channel;
        *pChannelsAvailable = pIrb->u.IsochAllocateChannel.ChannelsAvailable;

        TRACE(TL_TRACE, ("Channel = 0x%x\n", *pChannel));
        TRACE(TL_TRACE, ("ChannelsAvailable.LowPart = 0x%x\n", pChannelsAvailable->LowPart));
        TRACE(TL_TRACE, ("ChannelsAvailable.HighPart = 0x%x\n", pChannelsAvailable->HighPart));
    }
    else {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_IsochAllocateChannel:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_IsochAllocateChannel", ntStatus);
    return(ntStatus);
} // t1394_IsochAllocateChannel

NTSTATUS
t1394_IsochAllocateResources(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN ULONG            fulSpeed,
    IN ULONG            fulFlags,
    IN ULONG            nChannel,
    IN ULONG            nMaxBytesPerFrame,
    IN ULONG            nNumberOfBuffers,
    IN ULONG            nMaxBufferSize,
    IN ULONG            nQuadletsToStrip,
    OUT PHANDLE         phResource
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_IsochAllocateResources");

    TRACE(TL_TRACE, ("fulSpeed = 0x%x\n", fulSpeed));
    TRACE(TL_TRACE, ("fulFlags = 0x%x\n", fulFlags));
    TRACE(TL_TRACE, ("nChannel = 0x%x\n", nChannel));
    TRACE(TL_TRACE, ("nMaxBytesPerFrame = 0x%x\n", nMaxBytesPerFrame));
    TRACE(TL_TRACE, ("nNumberOfBuffers = 0x%x\n", nNumberOfBuffers));
    TRACE(TL_TRACE, ("nMaxBufferSize = 0x%x\n", nMaxBufferSize));
    TRACE(TL_TRACE, ("nQuadletsToStrip = 0x%x\n", nQuadletsToStrip));

    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochAllocateResources;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ISOCH_ALLOCATE_RESOURCES;
    pIrb->Flags = 0;
    pIrb->u.IsochAllocateResources.fulSpeed = fulSpeed;
    pIrb->u.IsochAllocateResources.fulFlags = fulFlags;
    pIrb->u.IsochAllocateResources.nChannel = nChannel;
    pIrb->u.IsochAllocateResources.nMaxBytesPerFrame = nMaxBytesPerFrame;
    pIrb->u.IsochAllocateResources.nNumberOfBuffers = nNumberOfBuffers;
    pIrb->u.IsochAllocateResources.nMaxBufferSize = nMaxBufferSize;
    pIrb->u.IsochAllocateResources.nQuadletsToStrip = nQuadletsToStrip;

        ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (NT_SUCCESS(ntStatus)) {

        PISOCH_RESOURCE_DATA  IsochResourceData;

        *phResource = pIrb->u.IsochAllocateResources.hResource;

        TRACE(TL_TRACE, ("hResource = 0x%x\n", *phResource));

        // need to add to our list...
        IsochResourceData = ExAllocatePoolWithTag(NonPagedPool,
                                                  sizeof(ISOCH_RESOURCE_DATA),
                                                  POOLTAG_1394);
        if (IsochResourceData) {

            IsochResourceData->hResource = pIrb->u.IsochAllocateResources.hResource;

            WdfSpinLockAcquire(deviceExtension->IsochResourceSpinLock);

            InsertHeadList(&deviceExtension->IsochResourceData,
                           &IsochResourceData->IsochResourceList);

            WdfSpinLockRelease(deviceExtension->IsochResourceSpinLock);
        }
        else {

            TRACE(TL_WARNING, ("Failed to allocate IsochResourceData!\n"));
        }
    }
    else {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_IsochAllocateResources:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_IsochAllocateResources", ntStatus);
    return(ntStatus);
} // t1394_IsochAllocateResources

NTSTATUS
t1394_IsochAttachBuffers(
    IN WDFDEVICE                    Device,
    IN WDFREQUEST                   Request,
    IN ULONG                        outputBufferLength,
    IN HANDLE                       hResource,
    IN ULONG                        nNumberOfDescriptors,
    OUT PISOCH_DESCRIPTOR           pIsochDescriptor,
    IN OUT PRING3_ISOCH_DESCRIPTOR  R3_IsochDescriptor
    )
{
    NTSTATUS                    ntStatus            = STATUS_SUCCESS;
    PDEVICE_EXTENSION           deviceExtension     = GetDeviceContext(Device);
    PIRB                        pIrb;
    ULONG                       i;
    ULONG                       j;
    PISOCH_DETACH_DATA          pIsochDetachData    = NULL;
    PRING3_ISOCH_DESCRIPTOR     pR3TempDescriptor   = NULL;
    PIO_STACK_LOCATION          NextIrpStack        = NULL;
    LARGE_INTEGER               deltaTime;
    PIRP                        newIrp              = NULL;
    CCHAR                       StackSize;

    ENTER("t1394_IsochAttachBuffers");

    TRACE(TL_TRACE, ("outputBufferLength = 0x%x\n", outputBufferLength));
    TRACE(TL_TRACE, ("hResource = 0x%x\n", hResource));
    TRACE(TL_TRACE, ("nNumberOfDescriptors = 0x%x\n", nNumberOfDescriptors));
    TRACE(TL_TRACE, ("R3_IsochDescriptor = 0x%x\n", R3_IsochDescriptor));

    if(!nNumberOfDescriptors)
    {
        TRACE(TL_WARNING, ("IsochAttachBuffers: Invalid nNumberOfDescriptors = 0x%x\n",
                           nNumberOfDescriptors));
        ntStatus = STATUS_INVALID_PARAMETER;
        goto Exit_IsochAttachBuffers;
    }

    //
    // Just assume that we are being passed a Request that was created in UserMode
    // and allocate one here, because we need to keep an Request around for
    // the callback routine.  Must submit this asynchronously so use IoAllocateIrp
    //
    StackSize = deviceExtension->StackDeviceObject->StackSize;
    newIrp = IoAllocateIrp (StackSize, FALSE);

    if (!newIrp) {

        TRACE(TL_ERROR, ("Failed to allocate newIrp!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochAttachBuffers;
    }

    //
    // allocate the irb
    //
    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochAttachBuffers;
    } // if

    //
    // allocate our isoch descriptors
    //
    pIsochDescriptor = ExAllocatePoolWithTag(NonPagedPool,
                                             sizeof(ISOCH_DESCRIPTOR)*nNumberOfDescriptors,
                                             POOLTAG_1394);

    if (!pIsochDescriptor) {

        TRACE(TL_ERROR, ("Failed to allocate pIsochDescriptor!\n"));
        if (pIrb)
            ExFreePoolWithTag(pIrb, POOLTAG_1394);

        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochAttachBuffers;
    }

    pR3TempDescriptor = R3_IsochDescriptor;
    for (i=0;i < nNumberOfDescriptors; i++) {

        TRACE(TL_TRACE, ("pR3TempDescriptor = 0x%x\n", pR3TempDescriptor));
        TRACE(TL_TRACE, ("pR3TempDescriptor->fulFlags = 0x%x\n", pR3TempDescriptor->fulFlags));
        TRACE(TL_TRACE, ("pR3TempDescriptor->ulLength = 0x%x\n", pR3TempDescriptor->ulLength));
        TRACE(TL_TRACE, ("pR3TempDescriptor->nMaxBytesPerFrame = 0x%x\n", pR3TempDescriptor->nMaxBytesPerFrame));
        TRACE(TL_TRACE, ("pR3TempDescriptor->ulSynch = 0x%x\n", pR3TempDescriptor->ulSynch));
        TRACE(TL_TRACE, ("pR3TempDescriptor->ulTag = 0x%x\n", pR3TempDescriptor->ulTag));
        TRACE(TL_TRACE, ("pR3TempDescriptor->CycleTime.CL_CycleOffset = 0x%x\n", pR3TempDescriptor->CycleTime.CL_CycleOffset));
        TRACE(TL_TRACE, ("pR3TempDescriptor->CycleTime.CL_CycleCount = 0x%x\n", pR3TempDescriptor->CycleTime.CL_CycleCount));
        TRACE(TL_TRACE, ("pR3TempDescriptor->CycleTime.CL_SecondCount = 0x%x\n", pR3TempDescriptor->CycleTime.CL_SecondCount));
        TRACE(TL_TRACE, ("pR3TempDescriptor->Data = 0x%x\n", &pR3TempDescriptor->Data));

        TRACE(TL_TRACE, ("pIsochDescriptor[%x] = 0x%x\n", i, &pIsochDescriptor[i]));

        // if we have a ulLength, create the Mdl. if not, Mdl=NULL
        if (pR3TempDescriptor->ulLength) {

            pIsochDescriptor[i].Mdl = IoAllocateMdl (pR3TempDescriptor->Data,
                                                     pR3TempDescriptor->ulLength,
                                                     FALSE,
                                                     FALSE,
                                                     NULL);


            if (!pIsochDescriptor[i].Mdl)
            {
                // we failed to alloc our mdl for this descriptor, free the previosly alloc'd mdls, and exit
                TRACE(TL_WARNING, ("Failed to allocate MDL for isoch descriptor num = 0x%x\n", i));

                for (j = 0; j < i; j++)
                {
                    if (pIsochDescriptor[j].Mdl)
                    {
                        IoFreeMdl (pIsochDescriptor[j].Mdl);
                    }
                }
                ExFreePoolWithTag(pIrb, POOLTAG_1394);
                ExFreePoolWithTag(pIsochDescriptor, POOLTAG_1394);
                ntStatus = STATUS_INVALID_PARAMETER;
                goto Exit_IsochAttachBuffers;
            }

            MmBuildMdlForNonPagedPool(pIsochDescriptor[i].Mdl);
            pIsochDescriptor[i].ulLength = MmGetMdlByteCount(pIsochDescriptor[i].Mdl);
        }
        else {

            pIsochDescriptor[i].Mdl = NULL;
            pIsochDescriptor[i].ulLength = pR3TempDescriptor->ulLength;
        }

        pIsochDescriptor[i].fulFlags = pR3TempDescriptor->fulFlags;
        pIsochDescriptor[i].nMaxBytesPerFrame = pR3TempDescriptor->nMaxBytesPerFrame;
        pIsochDescriptor[i].ulSynch = pR3TempDescriptor->ulSynch;
        pIsochDescriptor[i].ulTag = pR3TempDescriptor->ulTag;
        pIsochDescriptor[i].CycleTime = pR3TempDescriptor->CycleTime;

        if (pR3TempDescriptor->bUseCallback) {

            //
            // i'm hoping this is the last descriptor. they should have only set this in the
            // last descriptor, since elsewhere it's not supported.
            //
            if (i != nNumberOfDescriptors-1) {

                TRACE(TL_TRACE, ("Callback on descriptor prior to last!\n"));

                // setting callback to NULL
                pIsochDescriptor[i].Callback = NULL;
            }
            else {

                // need to save hResource, numDescriptors and Request to use when detaching.
                // this needs to be done before we submit the irp, since the isoch callback
                // can be called before the submitirpsynch call completes.
                pIsochDetachData = ExAllocatePoolWithTag(NonPagedPool,
                                                         sizeof(ISOCH_DETACH_DATA),
                                                         POOLTAG_1394);

                if (!pIsochDetachData)
                {
                    for (j = 0; j < i; j++)
                    {
                        if (pIsochDescriptor[j].Mdl)
                        {
                            IoFreeMdl (pIsochDescriptor[j].Mdl);
                        }
                    }
                    ExFreePoolWithTag(pIrb, POOLTAG_1394);
                    TRACE(TL_ERROR, ("Failed to allocate pIsochDetachData!\n"));
                    ExFreePoolWithTag(pIsochDescriptor, POOLTAG_1394);
                    ntStatus = STATUS_INSUFFICIENT_RESOURCES;
                    goto Exit_IsochAttachBuffers;
                }

                pIsochDetachData->AttachIrb = pIrb;


                WdfSpinLockAcquire(deviceExtension->IsochSpinLock);
                InsertHeadList(&deviceExtension->IsochDetachData, &pIsochDetachData->IsochDetachList);

                WdfSpinLockRelease(deviceExtension->IsochSpinLock);

                KeInitializeTimer(&pIsochDetachData->Timer);
                KeInitializeDpc(&pIsochDetachData->TimerDpc, t1394_IsochTimeout, pIsochDetachData);

                deltaTime.LowPart = ISOCH_DETACH_TIMEOUT_VALUE;
                deltaTime.HighPart = -1;
                KeSetTimer(&pIsochDetachData->Timer, deltaTime, &pIsochDetachData->TimerDpc);

                pIsochDetachData->outputBufferLength = outputBufferLength;
                pIsochDetachData->DeviceExtension = deviceExtension;
                pIsochDetachData->hResource = hResource;
                pIsochDetachData->numIsochDescriptors = nNumberOfDescriptors;
                pIsochDetachData->IsochDescriptor = pIsochDescriptor;
                pIsochDetachData->Request = Request;
                pIsochDetachData->newIrp = newIrp;
                pIsochDetachData->bDetach = pR3TempDescriptor->bAutoDetach;

                pIsochDescriptor[i].Callback = t1394_IsochCallback;

                pIsochDescriptor[i].Context1 = deviceExtension;
                pIsochDescriptor[i].Context2 = pIsochDetachData;

                TRACE(TL_TRACE, ("IsochAttachBuffers: pIsochDetachData = 0x%x\n", pIsochDetachData));
                TRACE(TL_TRACE, ("IsochAttachBuffers: pIsochDetachData->Request = 0x%x\n", pIsochDetachData->Request));
            }
        }
        else {

            pIsochDescriptor[i].Callback = NULL;
        }

        TRACE(TL_TRACE, ("pIsochDescriptor[%x].fulFlags = 0x%x\n", i, pIsochDescriptor[i].fulFlags));
        TRACE(TL_TRACE, ("pIsochDescriptor[%x].ulLength = 0x%x\n", i, pIsochDescriptor[i].ulLength));
        TRACE(TL_TRACE, ("pIsochDescriptor[%x].nMaxBytesPerFrame = 0x%x\n", i, pIsochDescriptor[i].nMaxBytesPerFrame));
        TRACE(TL_TRACE, ("pIsochDescriptor[%x].ulSynch = 0x%x\n", i, pIsochDescriptor[i].ulSynch));
        TRACE(TL_TRACE, ("pIsochDescriptor[%x].ulTag = 0x%x\n", i, pIsochDescriptor[i].ulTag));
        TRACE(TL_TRACE, ("pIsochDescriptor[%x].CycleTime.CL_CycleOffset = 0x%x\n", i, pIsochDescriptor[i].CycleTime.CL_CycleOffset));
        TRACE(TL_TRACE, ("pIsochDescriptor[%x].CycleTime.CL_CycleCount = 0x%x\n", i, pIsochDescriptor[i].CycleTime.CL_CycleCount));
        TRACE(TL_TRACE, ("pIsochDescriptor[%x].CycleTime.CL_SecondCount = 0x%x\n", i, pIsochDescriptor[i].CycleTime.CL_SecondCount));

        pR3TempDescriptor =
           (PRING3_ISOCH_DESCRIPTOR)((ULONG_PTR)pR3TempDescriptor +
                                     pIsochDescriptor[i].ulLength +
                                     sizeof(RING3_ISOCH_DESCRIPTOR));
    } // for


    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ISOCH_ATTACH_BUFFERS;
    pIrb->Flags = 0;
    pIrb->u.IsochAttachBuffers.hResource = hResource;
    pIrb->u.IsochAttachBuffers.nNumberOfDescriptors = nNumberOfDescriptors;
    pIrb->u.IsochAttachBuffers.pIsochDescriptor = pIsochDescriptor;

    // mark our original irp pending
    //IoMarkIrpPending(Irp);

    //
    // Submit the newIrp directly to the driver below us
    //
    NextIrpStack = IoGetNextIrpStackLocation(newIrp);
    NextIrpStack->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;
    NextIrpStack->Parameters.DeviceIoControl.IoControlCode = IOCTL_1394_CLASS;
    NextIrpStack->Parameters.Others.Argument1 = pIrb;

    IoSetCompletionRoutine( newIrp,
                            t1394_IsochAttachCompletionRoutine,
                            pIsochDetachData,
                            TRUE,
                            TRUE,
                            TRUE
                            );

    IoCallDriver(deviceExtension->StackDeviceObject, newIrp);
    ntStatus = STATUS_PENDING;

Exit_IsochAttachBuffers:

    EXIT("t1394_IsochAttachBuffers", ntStatus);
    return(ntStatus);
} // t1394_IsochAttachBuffers

NTSTATUS
t1394_IsochDetachBuffers(
    IN WDFDEVICE       Device,
    IN WDFREQUEST                 Request,
    IN HANDLE               hResource,
    IN ULONG                nNumberOfDescriptors,
    IN PISOCH_DESCRIPTOR    IsochDescriptor
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;
    ULONG               i;

    ENTER("");

    TRACE(TL_TRACE, ("hResource = 0x%x\n", hResource));
    TRACE(TL_TRACE, ("nNumberOfDescriptors = 0x%x\n", nNumberOfDescriptors));
    TRACE(TL_TRACE, ("IsochDescriptor = 0x%x\n", IsochDescriptor));


    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochDetachBuffers;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ISOCH_DETACH_BUFFERS;
    pIrb->Flags = 0;
    pIrb->u.IsochDetachBuffers.hResource = hResource;
    pIrb->u.IsochDetachBuffers.nNumberOfDescriptors = nNumberOfDescriptors;
    pIrb->u.IsochDetachBuffers.pIsochDescriptor = IsochDescriptor;

        ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }
    else
    {
        // if we detached the descriptor, free up the allocations
        for (i=0; i<nNumberOfDescriptors; i++)
        {
            if (IsochDescriptor[i].Mdl)
            {
                IoFreeMdl(IsochDescriptor[i].Mdl);
            }
        }
        ExFreePoolWithTag(IsochDescriptor, POOLTAG_1394);
    }

Exit_IsochDetachBuffers:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_IsochDetachBuffers", ntStatus);
    return(ntStatus);
} // t1394_IsochDetachBuffers

NTSTATUS
t1394_IsochFreeBandwidth(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN HANDLE           hBandwidth
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_IsochFreeBandwidth");

    TRACE(TL_TRACE, ("hBandwidth = 0x%x\n", hBandwidth));


    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochFreeBandwidth;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ISOCH_FREE_BANDWIDTH;
    pIrb->Flags = 0;
    pIrb->u.IsochFreeBandwidth.hBandwidth = hBandwidth;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_IsochFreeBandwidth:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_IsochFreeBandwidth", ntStatus);
    return(ntStatus);
} // t1394_IsochFreeBandwidth

NTSTATUS
t1394_IsochFreeChannel(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN ULONG            nChannel
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_IsochFreeChannel");

    TRACE(TL_TRACE, ("nChannel = 0x%x\n", nChannel));

    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochFreeChannel;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ISOCH_FREE_CHANNEL;
    pIrb->Flags = 0;
    pIrb->u.IsochFreeChannel.nChannel = nChannel;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_IsochFreeChannel:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_IsochFreeChannel", ntStatus);
    return(ntStatus);
} // t1394_IsochFreeChannel

NTSTATUS
t1394_IsochFreeResources(
    IN WDFDEVICE   Device,
    IN WDFREQUEST  Request,
    IN HANDLE      hResource
    )
{
    NTSTATUS              ntStatus            = STATUS_SUCCESS;
    PDEVICE_EXTENSION     deviceExtension     = GetDeviceContext(Device);
    PIRB                  pIrb                = NULL;
    PISOCH_RESOURCE_DATA  IsochResourceData   = NULL;
    PLIST_ENTRY           listHead;
    PLIST_ENTRY           thisEntry;

    ENTER("t1394_IsochFreeResources");

    TRACE(TL_TRACE, ("hResource = 0x%x\n", hResource));

    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochFreeResources;
    } // if

    // remove this one from our list...

    WdfSpinLockAcquire(deviceExtension->IsochResourceSpinLock);

    listHead = &deviceExtension->IsochResourceData;

    for(thisEntry = listHead->Flink;
                    thisEntry != listHead;
                    IsochResourceData = NULL, thisEntry = thisEntry->Flink)
    {
        IsochResourceData = CONTAINING_RECORD(thisEntry,
                                              ISOCH_RESOURCE_DATA,
                                              IsochResourceList);

        if (IsochResourceData->hResource == hResource) {
            TRACE(TL_TRACE, ("Removing hResource = 0x%x\n", hResource));
            RemoveEntryList(&IsochResourceData->IsochResourceList);
            ExFreePoolWithTag(IsochResourceData, POOLTAG_1394);
            break;
        }
    }


    WdfSpinLockRelease(deviceExtension->IsochResourceSpinLock);

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ISOCH_FREE_RESOURCES;
    pIrb->Flags = 0;
    pIrb->u.IsochFreeResources.hResource = hResource;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_IsochFreeResources:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_IsochFreeResources", ntStatus);
    return(ntStatus);
} // t1394_IsochFreeResources

NTSTATUS
t1394_IsochListen(
    IN WDFDEVICE        Device,
    IN WDFREQUEST       Request,
    IN HANDLE           hResource,
    IN ULONG            fulFlags,
    IN CYCLE_TIME       StartTime
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_IsochListen");

    TRACE(TL_TRACE, ("hResource = 0x%x\n", hResource));
    TRACE(TL_TRACE, ("fulFlags = 0x%x\n", fulFlags));
    TRACE(TL_TRACE, ("StartTime.CL_CycleOffset = 0x%x\n", StartTime.CL_CycleOffset));
    TRACE(TL_TRACE, ("StartTime.CL_CycleCount = 0x%x\n", StartTime.CL_CycleCount));
    TRACE(TL_TRACE, ("StartTime.CL_SecondCount = 0x%x\n", StartTime.CL_SecondCount));


    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochListen;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ISOCH_LISTEN;
    pIrb->Flags = 0;
    pIrb->u.IsochListen.hResource = hResource;
    pIrb->u.IsochListen.fulFlags = fulFlags;
    pIrb->u.IsochListen.StartTime = StartTime;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_IsochListen:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_IsochListen", ntStatus);
    return(ntStatus);
} // t1394_IsochListen

NTSTATUS
t1394_IsochQueryCurrentCycleTime(
    IN WDFDEVICE        Device,
    IN WDFREQUEST       Request,
    OUT PCYCLE_TIME     pCurrentCycleTime
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_IsochQueryCurrentCycleTime");

    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochQueryCurrentCycleTime;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ISOCH_QUERY_CYCLE_TIME;
    pIrb->Flags = 0;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (NT_SUCCESS(ntStatus)) {

        *pCurrentCycleTime = pIrb->u.IsochQueryCurrentCycleTime.CycleTime;

        TRACE(TL_TRACE, ("CurrentCycleTime.CL_CycleOffset = 0x%x\n",
                         pCurrentCycleTime->CL_CycleOffset));
        TRACE(TL_TRACE, ("CurrentCycleTime.CL_CycleCount = 0x%x\n",
                         pCurrentCycleTime->CL_CycleCount));
        TRACE(TL_TRACE, ("CurrentCycleTime.CL_SecondCount = 0x%x\n",
                         pCurrentCycleTime->CL_SecondCount));
    }
    else {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_IsochQueryCurrentCycleTime:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_IsochQueryCurrentCycleTime", ntStatus);
    return(ntStatus);
} // t1394_IsochQueryCurrentCycleTime

NTSTATUS
t1394_IsochQueryResources(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN ULONG            fulSpeed,
    OUT PULONG          pBytesPerFrameAvailable,
    OUT PLARGE_INTEGER  pChannelsAvailable
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_IsochQueryResources");

    TRACE(TL_TRACE, ("fulSpeed = 0x%x\n", fulSpeed));


    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochQueryResources;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ISOCH_QUERY_RESOURCES;
    pIrb->Flags = 0;
    pIrb->u.IsochQueryResources.fulSpeed = fulSpeed;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (NT_SUCCESS(ntStatus)) {

        *pBytesPerFrameAvailable = pIrb->u.IsochQueryResources.BytesPerFrameAvailable;
        *pChannelsAvailable = pIrb->u.IsochQueryResources.ChannelsAvailable;

        TRACE(TL_TRACE, ("BytesPerFrameAvailable = 0x%x\n",
                         *pBytesPerFrameAvailable));
        TRACE(TL_TRACE, ("ChannelsAvailable.LowPart = 0x%x\n",
                         pChannelsAvailable->LowPart));
        TRACE(TL_TRACE, ("ChannelsAvailable.HighPart = 0x%x\n",
                         pChannelsAvailable->HighPart));
    }
    else {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_IsochQueryResources:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_IsochQueryResources", ntStatus);
    return(ntStatus);
} // t1394_IsochQueryResources

NTSTATUS
t1394_IsochSetChannelBandwidth(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN HANDLE           hBandwidth,
    IN ULONG            nMaxBytesPerFrame
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_IsochSetChannelBandwidth");

    TRACE(TL_TRACE, ("hBandwidth = 0x%x\n", hBandwidth));
    TRACE(TL_TRACE, ("nMaxBytesPerFrame = 0x%x\n", nMaxBytesPerFrame));


    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochSetChannelBandwidth;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ISOCH_SET_CHANNEL_BANDWIDTH;
    pIrb->Flags = 0;
    pIrb->u.IsochSetChannelBandwidth.hBandwidth = hBandwidth;
    pIrb->u.IsochSetChannelBandwidth.nMaxBytesPerFrame = nMaxBytesPerFrame;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_IsochSetChannelBandwidth:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_IsochSetChannelBandwidth",  ntStatus);
    return(ntStatus);
} // t1394_IsochSetChannelBandwidth


NTSTATUS
t1394_IsochModifyStreamProperties(
    IN WDFDEVICE       Device,
    IN WDFREQUEST                 Request,
    IN HANDLE               hResource,
    IN ULARGE_INTEGER       ChannelMask,
    IN ULONG                fulSpeed
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochModifyStreamProperties;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ISOCH_MODIFY_STREAM_PROPERTIES;
    pIrb->Flags = 0;
    pIrb->u.IsochModifyStreamProperties.hResource       = hResource;
    pIrb->u.IsochModifyStreamProperties.ChannelMask     = ChannelMask;
    pIrb->u.IsochModifyStreamProperties.fulSpeed        = fulSpeed;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_IsochModifyStreamProperties:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_IsochModifyStreamProperties", ntStatus);
    return ntStatus;
}

NTSTATUS
t1394_IsochStop(
    IN WDFDEVICE        Device,
    IN WDFREQUEST       Request,
    IN HANDLE           hResource,
    IN ULONG            fulFlags
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_IsochStop");

    TRACE(TL_TRACE, ("hResource = 0x%x\n", hResource));
    TRACE(TL_TRACE, ("fulFlags = 0x%x\n", fulFlags));


    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochStop;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ISOCH_STOP;
    pIrb->Flags = 0;
    pIrb->u.IsochStop.hResource = hResource;
    pIrb->u.IsochStop.fulFlags = fulFlags;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_IsochStop:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_IsochStop", ntStatus);
    return(ntStatus);
} // t1394_IsochStop

NTSTATUS
t1394_IsochTalk(
    IN WDFDEVICE        Device,
    IN WDFREQUEST       Request,
    IN HANDLE           hResource,
    IN ULONG            fulFlags,
    CYCLE_TIME          StartTime
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_IsochTalk");

    TRACE(TL_TRACE, ("hResource = 0x%x\n", hResource));
    TRACE(TL_TRACE, ("fulFlags = 0x%x\n", fulFlags));
    TRACE(TL_TRACE, ("StartTime.CL_CycleOffset = 0x%x\n", StartTime.CL_CycleOffset));
    TRACE(TL_TRACE, ("StartTime.CL_CycleCount = 0x%x\n", StartTime.CL_CycleCount));
    TRACE(TL_TRACE, ("StartTime.CL_SecondCount = 0x%x\n", StartTime.CL_SecondCount));

    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_IsochTalk;
    } // if

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_ISOCH_TALK;
    pIrb->Flags = 0;
    pIrb->u.IsochTalk.hResource = hResource;
    pIrb->u.IsochTalk.fulFlags = fulFlags;
    pIrb->u.IsochTalk.StartTime = StartTime;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_IsochTalk:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_IsochTalk", ntStatus);
    return(ntStatus);
} // t1394_IsochTalk

void
t1394_IsochCallback(
    IN PDEVICE_EXTENSION    DeviceExtension,
    IN PISOCH_DETACH_DATA   IsochDetachData
    )
{
    ENTER("t1394_IsochCallback");

    if (!IsochDetachData)
    {
        goto Exit_IsochCallback;
    }

    // make sure somebody else isn't already handling cleaning up for this request

    WdfSpinLockAcquire(DeviceExtension->IsochSpinLock);
    if (t1394_IsOnList(&IsochDetachData->IsochDetachList, &DeviceExtension->IsochDetachData))
    {

        RemoveEntryList(&IsochDetachData->IsochDetachList);

        WdfSpinLockRelease(DeviceExtension->IsochSpinLock);
        KeCancelTimer(&IsochDetachData->Timer);

        TRACE(TL_TRACE, ("IsochCallback: IsochDetachData = 0x%x\n", IsochDetachData));
        TRACE(TL_TRACE, ("IsochCallback: IsochDetachData->Request = 0x%x\n", IsochDetachData->Request));
        TRACE(TL_TRACE, ("IsochCallback: IsochDetachData->newIrp = 0x%x\n", IsochDetachData->newIrp));

        // need to save the status of the attach
        // we'll clean up in the same spot for success's and timeout's
        // TODO: IsochDetachData->AttachStatus = IsochDetachData->Irp->IoStatus.Status;
        t1394_IsochCleanup(IsochDetachData);
    }
    else
    {
        TRACE(TL_TRACE, ("IsochCallback: Entry 0x%x not on List 0x%x\n",
        IsochDetachData->IsochDetachList, DeviceExtension->IsochDetachData));

        WdfSpinLockRelease(DeviceExtension->IsochSpinLock);

    }

Exit_IsochCallback:
    EXIT("t1394_IsochCallback", 0);
} // t1394_IsochCallback

void
t1394_IsochTimeout(
    IN PKDPC                Dpc,
    IN PISOCH_DETACH_DATA   IsochDetachData,
    IN PVOID                SystemArgument1,
    IN PVOID                SystemArgument2
    )
{
    PDEVICE_EXTENSION   DeviceExtension;

    UNREFERENCED_PARAMETER(Dpc);
    UNREFERENCED_PARAMETER(SystemArgument1);
    UNREFERENCED_PARAMETER(SystemArgument2);

    ENTER("t1394_IsochTimeout");
    TRACE(TL_WARNING, ("Isoch Timeout!\n"));

    //
    // ISSUE: the device extension we are referencing comes from the IsochDetachData
    // but it is possible this memory has been freed before we enter this function.
    // The only way to check is to validate against our DeviceExtension->IsochDetachList
    // but if the IsochDetachData has been freed then that won't be accessible
    //
    DeviceExtension = IsochDetachData->DeviceExtension;
    if (DeviceExtension)
    {
        // make sure nobody else has already handled this request yet

        WdfSpinLockAcquire(DeviceExtension->IsochSpinLock);
        if (t1394_IsOnList(&IsochDetachData->IsochDetachList, &DeviceExtension->IsochDetachData))
        {
            RemoveEntryList(&IsochDetachData->IsochDetachList);

            WdfSpinLockRelease(DeviceExtension->IsochSpinLock);


            if(KeCancelTimer(&IsochDetachData->Timer))
            {

                TRACE(TL_TRACE, ("IsochTimeout: IsochDetachData = 0x%x\n", IsochDetachData));
                TRACE(TL_TRACE, ("IsochTimeout: IsochDetachData->Irp = 0x%x\n", IsochDetachData->Request));
                TRACE(TL_TRACE, ("IsochTimeout: IsochDetachData->newIrp = 0x%x\n", IsochDetachData->newIrp));

                // need to save the status of the attach
                // we'll clean up in the same spot for success's and timeout's
                IsochDetachData->AttachStatus = STATUS_TIMEOUT;
                t1394_IsochCleanup(IsochDetachData);
            }
        }
        else
        {

            WdfSpinLockRelease(DeviceExtension->IsochSpinLock);

        }
    }

    EXIT("t1394_IsochTimeout", 0);
} // t1394_IsochTimeout

void
t1394_IsochCleanup(
    IN PISOCH_DETACH_DATA   IsochDetachData
    )
{
    ULONG               i;
    PDEVICE_EXTENSION   DeviceExtension;

    ENTER("t1394_IsochCleanup");

    //
    // see if we need to detach this buffer
    //
    if (!IsochDetachData)
    {
        goto Exit_IsochDetachBuffers;
    }

    DeviceExtension = IsochDetachData->DeviceExtension;

    if (!DeviceExtension)
    {
        goto Exit_IsochDetachBuffers;
    }

    if (IsochDetachData->bDetach) {

        PIRB                pIrb;
        NTSTATUS            ntStatus;
        PIO_STACK_LOCATION  NextIrpStack;

        pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

        if (!pIrb) {

            TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
            TRACE(TL_WARNING, ("Can't detach buffer!\n"));
            ntStatus = STATUS_INSUFFICIENT_RESOURCES;
            goto Exit_IsochDetachBuffers;
        } // if

        // save the irb in our detach data context
        IsochDetachData->DetachIrb = pIrb;

        RtlZeroMemory (pIrb, sizeof (IRB));
        pIrb->FunctionNumber = REQUEST_ISOCH_DETACH_BUFFERS;
        pIrb->Flags = 0;
        pIrb->u.IsochDetachBuffers.hResource = IsochDetachData->hResource;
        pIrb->u.IsochDetachBuffers.nNumberOfDescriptors = IsochDetachData->numIsochDescriptors;
        pIrb->u.IsochDetachBuffers.pIsochDescriptor = IsochDetachData->IsochDescriptor;

        NextIrpStack = IoGetNextIrpStackLocation(IsochDetachData->newIrp);
        NextIrpStack->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;
        NextIrpStack->Parameters.DeviceIoControl.IoControlCode = IOCTL_1394_CLASS;
        NextIrpStack->Parameters.Others.Argument1 = pIrb;

        IoSetCompletionRoutine( IsochDetachData->newIrp,
                                t1394_IsochDetachCompletionRoutine,
                                IsochDetachData,
                                TRUE,
                                TRUE,
                                TRUE
                                );

        IoCallDriver(DeviceExtension->StackDeviceObject, IsochDetachData->newIrp);
    }
    else {

        TRACE(TL_TRACE, ("Complete Irp.\n"));

        if (IsochDetachData->AttachIrb)
        {
            ExFreePoolWithTag(IsochDetachData->AttachIrb, POOLTAG_1394);
        }

        for (i=0; i<IsochDetachData->numIsochDescriptors; i++)
        {
            if (IsochDetachData->IsochDescriptor[i].Mdl)
            {
                IoFreeMdl(IsochDetachData->IsochDescriptor[i].Mdl);
            }
        }

        ExFreePoolWithTag(IsochDetachData->IsochDescriptor, POOLTAG_1394);

        //IsochDetachData->Irp->IoStatus.Status = IsochDetachData->AttachStatus;

        // only set this if its a success...
        if (NT_SUCCESS(IsochDetachData->AttachStatus))
        {
            //IsochDetachData->Irp->IoStatus.Information = IsochDetachData->outputBufferLength;
        }

        //
        // Complete original Irp and free the one we allocated in
        // IsochAttachBuffers
        //
        WdfRequestCompleteWithInformation(IsochDetachData->Request,
                                          IsochDetachData->AttachStatus,
                                          IsochDetachData->outputBufferLength);
        IoFreeIrp (IsochDetachData->newIrp);

        // all done with IsochDetachData, lets deallocate it...
        ExFreePoolWithTag(IsochDetachData, POOLTAG_1394);
    }

Exit_IsochDetachBuffers:

    EXIT("t1394_IsochCleanup", 0);
} // t1394_IsochCleanup

NTSTATUS
t1394_IsochDetachCompletionRoutine(
    IN PDEVICE_OBJECT       Device,
    IN PIRP                 Irp,
    IN PISOCH_DETACH_DATA   IsochDetachData
    )
{
    NTSTATUS        ntStatus = STATUS_SUCCESS;
    ULONG           i;

    UNREFERENCED_PARAMETER(Device);
    UNREFERENCED_PARAMETER(Irp);
    UNREFERENCED_PARAMETER(ntStatus);

    ENTER("t1394_IsochDetachCompletionRoutine");

    if (!IsochDetachData) {

        TRACE(TL_WARNING, ("Invalid IsochDetachData\n"));
        goto Exit_IsochDetachCompletionRoutine;
    }

    if (IsochDetachData->DetachIrb)
    {
        ExFreePoolWithTag(IsochDetachData->DetachIrb, POOLTAG_1394);
    }
    TRACE(TL_TRACE, ("Now lets complete the Irp.\n"));

    if (IsochDetachData->AttachIrb)
        ExFreePoolWithTag(IsochDetachData->AttachIrb, POOLTAG_1394);

    for (i=0; i<IsochDetachData->numIsochDescriptors; i++)
    {

        if (IsochDetachData->IsochDescriptor[i].Mdl)
        {
            IoFreeMdl(IsochDetachData->IsochDescriptor[i].Mdl);
        }
    }

    if (IsochDetachData->IsochDescriptor)
    {
        ExFreePoolWithTag(IsochDetachData->IsochDescriptor, POOLTAG_1394);
    }

    // only set this if its a success...
    if (NT_SUCCESS(IsochDetachData->AttachStatus))
    {
        //IsochDetachData->Irp->IoStatus.Information = IsochDetachData->outputBufferLength;
    }

    //IsochDetachData->Irp->IoStatus.Status = IsochDetachData->AttachStatus;

    //
    // Complete original Irp and free the one we allocated in
    // IsochAttachBuffers
    //
    WdfRequestCompleteWithInformation(IsochDetachData->Request, IsochDetachData->AttachStatus, IsochDetachData->outputBufferLength);
    IoFreeIrp (IsochDetachData->newIrp);

    // all done with IsochDetachData, lets deallocate it...
    ExFreePoolWithTag(IsochDetachData, POOLTAG_1394);

Exit_IsochDetachCompletionRoutine:

    EXIT("t1394_IsochDetachCompletionRoutine", ntStatus);
    return(STATUS_MORE_PROCESSING_REQUIRED);
} // t1394_IsochDetachCompletionRoutine

NTSTATUS
t1394_IsochAttachCompletionRoutine(
    IN PDEVICE_OBJECT       Device,
    IN PIRP                 Irp,
    IN PISOCH_DETACH_DATA   IsochDetachData
    )
{
    PDEVICE_EXTENSION   DeviceExtension;
    NTSTATUS            ntStatus = STATUS_SUCCESS;
    ULONG               i;

    UNREFERENCED_PARAMETER(Device);
    UNREFERENCED_PARAMETER(Irp);

    ENTER("t1394_IsochAttachCompletionRoutine");

    if (!IsochDetachData)
    {
        TRACE(TL_WARNING, ("IsochAttachCompletionRoutine: IsochDetachData = 0x%x\n",
                           IsochDetachData));
        IoFreeIrp (Irp);
        goto Exit_IsochAttachCompletionRoutine;
    }

    if (!NT_SUCCESS(Irp->IoStatus.Status))
    {
        // make sure this irp is still on the device extension list, meaning no one else
        // has already handled this yet
        DeviceExtension = IsochDetachData->DeviceExtension;

        WdfSpinLockAcquire(DeviceExtension->IsochSpinLock);
        if (t1394_IsOnList(&IsochDetachData->IsochDetachList, &DeviceExtension->IsochDetachData))
        {
            RemoveEntryList(&IsochDetachData->IsochDetachList);
            KeCancelTimer(&IsochDetachData->Timer);

            WdfSpinLockRelease(DeviceExtension->IsochSpinLock);
        }
        else
        {
            // just bomb out here

            WdfSpinLockRelease(DeviceExtension->IsochSpinLock);
            goto Exit_IsochAttachCompletionRoutine;
        }
        TRACE(TL_ERROR, ("Isoch Attach Failed! = 0x%x\n", Irp->IoStatus.Status));
        ntStatus = Irp->IoStatus.Status;

        if (!IsochDetachData)
        {
            goto Exit_IsochAttachCompletionRoutine;
        }

        DeviceExtension = IsochDetachData->DeviceExtension;

        TRACE(TL_TRACE, ("IsochAttachCompletionRoutine: IsochDetachData = 0x%x\n", IsochDetachData));
        TRACE(TL_TRACE, ("IsochAttachCompletionRoutine: IsochDetachData->Request = 0x%x\n", IsochDetachData->Request));
        TRACE(TL_TRACE, ("IsochAttachCompletionRoutine: IsochDetachData->newIrp = 0x%x\n", IsochDetachData->newIrp));
        TRACE(TL_TRACE, ("Now lets complete Irp.\n"));

        if (IsochDetachData->AttachIrb)
        {
            ExFreePoolWithTag(IsochDetachData->AttachIrb, POOLTAG_1394);
        }

        for (i=0; i<IsochDetachData->numIsochDescriptors; i++)
        {
            if (IsochDetachData->IsochDescriptor[i].Mdl)
            {
                IoFreeMdl(IsochDetachData->IsochDescriptor[i].Mdl);
            }
        }

        ExFreePoolWithTag(IsochDetachData->IsochDescriptor, POOLTAG_1394);

        //
        // Complete original Irp and free the one we allocated in
        // IsochAttachBuffers
        //
        //IsochDetachData->Irp->IoStatus = Irp->IoStatus;
        // TODO:
        WdfRequestCompleteWithInformation(IsochDetachData->Request, Irp->IoStatus.Status, 0);
        IoFreeIrp (IsochDetachData->newIrp);

        // all done with IsochDetachData, lets deallocate it...
        ExFreePoolWithTag(IsochDetachData, POOLTAG_1394);
    }

Exit_IsochAttachCompletionRoutine:

    EXIT("t1394_IsochAttachCompletionRoutine", ntStatus);
    return(STATUS_MORE_PROCESSING_REQUIRED);
} // t1394_IsochAttachCompletionRoutine



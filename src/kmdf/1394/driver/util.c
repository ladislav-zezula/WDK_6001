/*++

Copyright (c) 1999  Microsoft Corporation

Module Name:

    util.c

Abstract

--*/

#include "pch.h"

NTSTATUS
t1394_SubmitIrpSynch(
    IN WDFIOTARGET       IoTarget,
    IN WDFREQUEST        Request,
    IN PIRB              Irb
    )
{
    NTSTATUS            ntStatus = STATUS_SUCCESS;

    WDF_REQUEST_SEND_OPTIONS    option;
    WDF_MEMORY_DESCRIPTOR descriptor;

    UNREFERENCED_PARAMETER(Request);

    ENTER("t1394_SubmitIrpSynch");

    ASSERT(KeGetCurrentIrql() < DISPATCH_LEVEL);
    ASSERT(Irb);

    WDF_REQUEST_SEND_OPTIONS_INIT(&option, WDF_REQUEST_SEND_OPTION_SYNCHRONOUS);

    TRACE(TL_TRACE, ("t1394_SubmitIrpSynch: Irp is pending...\n"));

    WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(&descriptor, Irb, sizeof (IRB));

    ntStatus = WdfIoTargetSendInternalIoctlOthersSynchronously(IoTarget, NULL, IOCTL_1394_CLASS, &descriptor, NULL, NULL, &option, NULL);
    if (!NT_SUCCESS(ntStatus)) {
            TRACE(TL_ERROR, ("WdfIoTargetSendInternalIoctlSynchronouslyOthers Failed with status %x\n",ntStatus));
    }

    EXIT("t1394_SubmitIrpSynch", ntStatus);
    return(ntStatus);
} // t1394_SubmitIrpSynch


BOOLEAN
t1394_IsOnList(
    PLIST_ENTRY        Entry,
    PLIST_ENTRY        List
    )
{
    PLIST_ENTRY TempEntry;

    for(
        TempEntry = List->Flink;
        TempEntry != List;
        TempEntry = TempEntry->Flink
        )
    {
        if (TempEntry == Entry)
        {
            TRACE(TL_TRACE, ("Entry 0x%x found on list 0x%x\n", Entry, List));
            return TRUE;
        }
    }

    TRACE(TL_TRACE, ("Entry 0x%x not found on list 0x%x\n", Entry, List));
    return FALSE;
}


VOID
t1394_UpdateGenerationCount (
    IN WDFDEVICE Device
    )
{
    PDEVICE_EXTENSION       deviceExtension = GetDeviceContext(Device);
    NTSTATUS                ntStatus        = STATUS_SUCCESS;
    PIRB                    Irb                = NULL;
    WDFREQUEST request = NULL;

    ENTER("t1394_UpdateGenerationCountWorkItem");

    ntStatus = WdfRequestCreate(
        WDF_NO_OBJECT_ATTRIBUTES,
        deviceExtension->StackIoTarget,
        &request);

    if (!NT_SUCCESS(ntStatus)) {
        TRACE(TL_ERROR, ("Failed to allocate request!\n"));
        goto Exit_UpdateGenerationCountWorkItem;
    }

    // allocate irb
    Irb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);
    if (!Irb)
    {
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        TRACE(TL_ERROR, ("Failed to allocate Irb!\n"));
        goto Exit_UpdateGenerationCountWorkItem;
    }

    // send request down stack
    RtlZeroMemory (Irb, sizeof (IRB));
    Irb->FunctionNumber = REQUEST_GET_GENERATION_COUNT;
    Irb->Flags = 0;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, request, Irb);

    // update DeviceExtension->GenerationCount
    if (NT_SUCCESS(ntStatus))
    {
        deviceExtension->GenerationCount = Irb->u.GetGenerationCount.GenerationCount;
        TRACE(TL_TRACE, ("GenerationCount = 0x%x\n", deviceExtension->GenerationCount));
    }
    else
    {
        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_UpdateGenerationCountWorkItem:

    if (request)
    {
        WdfObjectDelete(request);
    }

    if (Irb)
    {
        ExFreePoolWithTag(Irb,POOLTAG_1394);
    }

    EXIT("t1394_UpdateGenerationCountWorkItem", ntStatus);

    return;
}




/*++

Copyright (c) Microsoft Corporation

Module Name:

    1394api.c

Abstract

--*/

// todo:
//      t1394_Control
//      t1394_GetMaxSpeedBetweenDevices
//      t1394_GetConfigurationInformation
//      t1394_SendPhyConfigurationPacket
//      t1394_GetSpeedTopologyMaps
//      t1394_BusResetNotification

#include "pch.h"

NTSTATUS
t1394_GetLocalHostInformation(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN ULONG            nLevel,
    IN OUT PULONG       UserStatus,
    IN OUT PVOID        Information
    )
{
    NTSTATUS                ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION       deviceExtension = GetDeviceContext(Device);
    PIRB                    pIrb            = NULL;
    GET_LOCAL_HOST_INFO7    LocalHostInfo7  = {0};
    GET_LOCAL_HOST_INFO6    LocalHostInfo6  = {0};
    GET_LOCAL_HOST_INFO5    LocalHostInfo5  = {0};

    ENTER("t1394_GetLocalHostInformation");

    TRACE(TL_TRACE, ("nLevel = 0x%x\n", nLevel));
    TRACE(TL_TRACE, ("Information = 0x%x\n", Information));

    // allocate irb
    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_GetLocalHostInformation;
    } // if


    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_GET_LOCAL_HOST_INFO;
    pIrb->Flags = 0;
    pIrb->u.GetLocalHostInformation.nLevel = nLevel;

    if (nLevel == 7) {

        // need to ensure that no one passed us an GET_LOCAL_HOST_INFO7 structure that just
        // piggy backed on the GET_LOCAL_HOST_INFORMATION struct, if they did this will cause
        // data misalignment errors in 64 bit because 1394bus will be expecting that structure to
        // be aligned correctly
        RtlCopyMemory (&LocalHostInfo7, Information, sizeof (GET_LOCAL_HOST_INFO7));
        pIrb->u.GetLocalHostInformation.Information = &LocalHostInfo7;

        TRACE(TL_TRACE, ("HostDmaCapabilities = 0x%p\n", LocalHostInfo7.HostDmaCapabilities));
        TRACE(TL_TRACE, ("MaxDmaBufferSize High = 0x%x\n", LocalHostInfo7.MaxDmaBufferSize.HighPart));
        TRACE(TL_TRACE, ("MaxDmaBufferSize Low = 0x%x\n", LocalHostInfo7.MaxDmaBufferSize.LowPart));

    }
    else if (nLevel == 6) {

        LocalHostInfo6.CsrBaseAddress.Off_High = ((PGET_LOCAL_HOST_INFO6)Information)->CsrBaseAddress.Off_High;
        LocalHostInfo6.CsrBaseAddress.Off_Low = ((PGET_LOCAL_HOST_INFO6)Information)->CsrBaseAddress.Off_Low;
        LocalHostInfo6.CsrDataLength = ((PGET_LOCAL_HOST_INFO6)Information)->CsrDataLength;

        // Pointer math needed to correct size differential between data structures on WIN64 only
        // LocalHostInfo6.CsrDataBuffer is UCHAR @ 4 bytes, Information->CsrDataBuffer is a PVIOD @ 8 bytes
        LocalHostInfo6.CsrDataBuffer = ((PCHAR)&(((PGET_LOCAL_HOST_INFO6)Information)->CsrDataLength)) + sizeof (ULONG);
        pIrb->u.GetLocalHostInformation.Information = &LocalHostInfo6;

        TRACE(TL_TRACE, ("CsrBaseAddress.Off_High = 0x%x\n", LocalHostInfo6.CsrBaseAddress.Off_High));
        TRACE(TL_TRACE, ("CsrBaseAddress.Off_Low = 0x%x\n", LocalHostInfo6.CsrBaseAddress.Off_Low));
        TRACE(TL_TRACE, ("CsrDataLength = 0x%x\n", LocalHostInfo6.CsrDataLength));
        TRACE(TL_TRACE, ("CsrDataBuffer = 0x%p\n", LocalHostInfo6.CsrDataBuffer));
    }
    else if (nLevel == 5)
    {
        // need to ensure that no one passed us an GET_LOCAL_HOST_INFO5 structure that just
        // piggy backed on the GET_LOCAL_HOST_INFORMATION struct, if they did this will cause
        // data misalignment errors in 64 bit because 1394bus will be expecting that structure to
        // be aligned correctly
        RtlCopyMemory (&LocalHostInfo5, Information, sizeof (GET_LOCAL_HOST_INFO5));
        pIrb->u.GetLocalHostInformation.Information = &LocalHostInfo5;

        TRACE(TL_TRACE, ("ConfigRom = 0x%p\n", LocalHostInfo5.ConfigRom));
        TRACE(TL_TRACE, ("ConfigRomLength = 0x%x\n", LocalHostInfo5.ConfigRomLength));
    }
    else {

        pIrb->u.GetLocalHostInformation.Information = Information;
    }


    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        if (ntStatus == STATUS_INVALID_BUFFER_SIZE) {

            // we have to set status=success, otherwise, we don't get
            // the size value passed up to ring 3.
            ntStatus = STATUS_SUCCESS;
            *UserStatus = 122;

            TRACE(TL_WARNING, ("Invalid Buffer Size. nLevel = 0x%x\n", nLevel));

            // see if it's a config rom request or a csr request
            if (nLevel == 5) {

                // it is, lets print out the size
                TRACE(TL_TRACE, ("ConfigRomLength = 0x%x\n", LocalHostInfo5.ConfigRomLength));

                // neet to set this in the information struct we were passed down
                RtlCopyMemory(Information, &LocalHostInfo5, sizeof (GET_LOCAL_HOST_INFO5));
            }
            else if (nLevel == 6) {

                // csr, print out size
                TRACE(TL_TRACE, ("CsrDataLength needed = 0x%x\n", LocalHostInfo6.CsrDataLength));

                // need to set this in the information struct we were passed down
                ((PGET_LOCAL_HOST_INFO6)Information)->CsrDataLength = LocalHostInfo6.CsrDataLength;
            }
            else if (nLevel == 7) {

                // copy the results of the struct passed down
                RtlCopyMemory(Information, &LocalHostInfo7, sizeof (GET_LOCAL_HOST_INFO7));
            }
        }
        else {

            TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
        }
    }
    else {

        *UserStatus = 0;

        if (nLevel == 1) {

            PGET_LOCAL_HOST_INFO1   LocalHostInfo1;

            LocalHostInfo1 = (PGET_LOCAL_HOST_INFO1)Information;

            TRACE(TL_TRACE, ("UniqueId.LowPart = 0x%x\n",
                             LocalHostInfo1->UniqueId.LowPart));
            TRACE(TL_TRACE, ("UniqueId.HighPart = 0x%x\n",
                             LocalHostInfo1->UniqueId.HighPart));
        }
        else if (nLevel == 2) {

            PGET_LOCAL_HOST_INFO2   LocalHostInfo2;

            LocalHostInfo2 = (PGET_LOCAL_HOST_INFO2)Information;

            TRACE(TL_TRACE, ("HostCapabilities = 0x%x\n",
                             LocalHostInfo2->HostCapabilities));
            TRACE(TL_TRACE, ("MaxAsyncReadRequest = 0x%x\n",
                             LocalHostInfo2->MaxAsyncReadRequest));
            TRACE(TL_TRACE, ("MaxAsyncWriteRequest = 0x%x\n",
                             LocalHostInfo2->MaxAsyncWriteRequest));
        }
        else if (nLevel == 3) {

            PGET_LOCAL_HOST_INFO3   LocalHostInfo3;

            LocalHostInfo3 = (PGET_LOCAL_HOST_INFO3)Information;

            TRACE(TL_TRACE, ("deciWattsSupplied = 0x%x\n",
                             LocalHostInfo3->deciWattsSupplied));
            TRACE(TL_TRACE, ("Voltage = 0x%x\n", LocalHostInfo3->Voltage));
        }
        else if (nLevel == 4) {

            PGET_LOCAL_HOST_INFO4   LocalHostInfo4;

            LocalHostInfo4 = (PGET_LOCAL_HOST_INFO4)Information;

            TRACE(TL_TRACE, ("Context = 0x%x\n", LocalHostInfo4->Context));
        }
        else if (nLevel == 5) {

            PGET_LOCAL_HOST_INFO5   pLocalHostInfo5;

            pLocalHostInfo5 = (PGET_LOCAL_HOST_INFO5)Information;

            TRACE(TL_TRACE, ("ConfigRomLength = 0x%x\n", pLocalHostInfo5->ConfigRomLength));

            // IDEAIDEA: add some debug spew for whatever we are getting...
        }
        else if (nLevel == 6) {

            // IDEAIDEA: add some debug spew for whatever we are getting...

        }
        else if (nLevel == 7) {

            // need to copy the results back into the original address space passed in
            TRACE(TL_TRACE, ("HostDmaCapabilities = 0x%x\n",
                             LocalHostInfo7.HostDmaCapabilities));
            TRACE(TL_TRACE, ("MaxDmaBufferSize Low = 0x%x\n",
                             LocalHostInfo7.MaxDmaBufferSize.LowPart));
            TRACE(TL_TRACE, ("MaxDmaBufferSize High = 0x%x\n",
                             LocalHostInfo7.MaxDmaBufferSize.HighPart));

            RtlCopyMemory(Information, &LocalHostInfo7, sizeof (GET_LOCAL_HOST_INFO7));
        }
        else {

            TRACE(TL_WARNING, ("Returned success on invalid nLevel = 0x%x\n", nLevel));
        }
    }


Exit_GetLocalHostInformation:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_GetLocalHostInformation", ntStatus);
    return(ntStatus);
} // t1394_GetLocalHostInformation

NTSTATUS
t1394_Get1394AddressFromDeviceObject(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN ULONG            fulFlags,
    OUT PNODE_ADDRESS   pNodeAddress
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_Get1394AddressFromDeviceObject");

    TRACE(TL_TRACE, ("fulFlags = 0x%x\n", fulFlags));

    // allocate irb
    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_Get1394AddressFromDeviceObject;
    } // if


    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_GET_ADDR_FROM_DEVICE_OBJECT;
    pIrb->Flags = 0;
    pIrb->u.Get1394AddressFromDeviceObject.fulFlags = fulFlags;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (NT_SUCCESS(ntStatus)) {

        *pNodeAddress = pIrb->u.Get1394AddressFromDeviceObject.NodeAddress;

        TRACE(TL_TRACE, ("NodeAddres.NA_Node_Number = 0x%x\n", pNodeAddress->NA_Node_Number));
        TRACE(TL_TRACE, ("NodeAddres.NA_Bus_Number = 0x%x\n", pNodeAddress->NA_Bus_Number));
    }
    else {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }


Exit_Get1394AddressFromDeviceObject:

    if(pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_Get1394AddressFromDeviceObject", ntStatus);
    return(ntStatus);
} // t1394_Get1394AddressFromDeviceObject

NTSTATUS
t1394_Control(
    IN WDFDEVICE   Device,
    IN WDFREQUEST  Request
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);

    UNREFERENCED_PARAMETER(Request);
    UNREFERENCED_PARAMETER(deviceExtension);

    ENTER("t1394_Control");

    ntStatus = STATUS_NOT_IMPLEMENTED;

    EXIT("t1394_Control", ntStatus);
    return(ntStatus);
} // t1394_Control

NTSTATUS
t1394_GetMaxSpeedBetweenDevices(
    IN WDFDEVICE        Device,
    IN WDFREQUEST       Request,
    IN ULONG            fulFlags,
    IN ULONG            ulNumberOfDestinations,
    IN PDEVICE_OBJECT   hDestinationDeviceObjects[64],
    OUT PULONG          fulSpeed
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;
    ULONG               i;

    ENTER("t1394_GetMaxSpeedBetweenDevices");

    TRACE(TL_TRACE, ("Device = 0x%x\n", Device));
    TRACE(TL_TRACE, ("Request = 0x%x\n", Request));
    TRACE(TL_TRACE, ("fulFlags = 0x%x\n", fulFlags));
    TRACE(TL_TRACE, ("ulNumberOfDestinations = 0x%x\n", ulNumberOfDestinations));

    for (i=0; i<ulNumberOfDestinations; i++) {

        TRACE(TL_TRACE, ("hDestinationDeviceObjects[%d] = 0x%x\n", i, hDestinationDeviceObjects[i]));
    }

    // allocate irb
    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);
    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_GetMaxSpeedBetweenDevices;
    } // if



    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_GET_SPEED_BETWEEN_DEVICES;
    pIrb->Flags = 0;
    pIrb->u.GetMaxSpeedBetweenDevices.fulFlags = fulFlags;
    pIrb->u.GetMaxSpeedBetweenDevices.ulNumberOfDestinations = ulNumberOfDestinations;

    for (i=0; i<ulNumberOfDestinations; i++) {

        pIrb->u.GetMaxSpeedBetweenDevices.hDestinationDeviceObjects[i] = hDestinationDeviceObjects[i];
    }

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (NT_SUCCESS(ntStatus)) {

        *fulSpeed = pIrb->u.GetMaxSpeedBetweenDevices.fulSpeed;

        TRACE(TL_TRACE, ("fulSpeed = 0x%x\n", *fulSpeed));
    }
    else {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }


Exit_GetMaxSpeedBetweenDevices:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_GetMaxSpeedBetweenDevices", ntStatus);
    return(ntStatus);
} // t1394_GetMaxSpeedBetweenDevices

NTSTATUS
t1394_SetDeviceXmitProperties(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN ULONG            fulSpeed,
    IN ULONG            fulPriority
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_SetDeviceXmitProperties");

    TRACE(TL_TRACE, ("fulSpeed = 0x%x\n", fulSpeed));
    TRACE(TL_TRACE, ("fulPriority = 0x%x\n", fulPriority));

    // allocate irb
    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);
    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_SetDeviceXmitProperties;
    } // if


    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_SET_DEVICE_XMIT_PROPERTIES;
    pIrb->Flags = 0;
    pIrb->u.SetDeviceXmitProperties.fulSpeed = fulSpeed;
    pIrb->u.SetDeviceXmitProperties.fulPriority = fulPriority;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }


Exit_SetDeviceXmitProperties:

    if(pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_SetDeviceXmitProperties", ntStatus);
    return(ntStatus);
} // t1394_SetDeviceXmitProperties

NTSTATUS
t1394_GetConfigurationInformation(
    IN WDFDEVICE   Device,
    IN WDFREQUEST  Request
    )
{
#if 1
    UNREFERENCED_PARAMETER(Device);
    UNREFERENCED_PARAMETER(Request);

    return(STATUS_NOT_IMPLEMENTED);
#else

    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_GetConfigurationInformation");
/*
        struct {
            PCONFIG_ROM     ConfigRom;                          // Pointer to config rom
            ULONG           UnitDirectoryBufferSize;
            PVOID           UnitDirectory;                      // Pointer to unit directory
            IO_ADDRESS      UnitDirectoryLocation;              // Starting Location of Unit Directory
            ULONG           UnitDependentDirectoryBufferSize;
            PVOID           UnitDependentDirectory;
            IO_ADDRESS      UnitDependentDirectoryLocation;
            ULONG           VendorLeafBufferSize;               // Size available to get vendor leafs
            PTEXTUAL_LEAF   VendorLeaf;                         // Pointer to vendor leafs
            ULONG           ModelLeafBufferSize;                // Size available to get model leafs
            PTEXTUAL_LEAF   ModelLeaf;                          // Pointer to model leafs
        } GetConfigurationInformation;
*/

    // allocate irb
    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);
    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_GetConfigurationInformation;
    } // if


    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_GET_CONFIGURATION_INFO;
    pIrb->Flags = 0;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (NT_SUCCESS(ntStatus)) {

        TRACE(TL_TRACE, ("ConfigRom->CR_Info = 0x%x\n",
            pIrb->u.GetConfigurationInformation.ConfigRom->CR_Info));
        TRACE(TL_TRACE, ("ConfigRom->CR_Signiture = 0x%x\n",
            pIrb->u.GetConfigurationInformation.ConfigRom->CR_Signiture));
        TRACE(TL_TRACE, ("ConfigRom->CR_BusInfoBlockCaps = 0x%x\n",
            pIrb->u.GetConfigurationInformation.ConfigRom->CR_BusInfoBlockCaps));
        TRACE(TL_TRACE, ("ConfigRom->CR_Node_UniqueID[0] = 0x%x\n",
            pIrb->u.GetConfigurationInformation.ConfigRom->CR_Node_UniqueID[0]));
        TRACE(TL_TRACE, ("ConfigRom->CR_Node_UniqueID[1] = 0x%x\n",
            pIrb->u.GetConfigurationInformation.ConfigRom->CR_Node_UniqueID[1]));
        TRACE(TL_TRACE, ("ConfigRom->CR_Root_Info = 0x%x\n",
            pIrb->u.GetConfigurationInformation.ConfigRom->CR_Root_Info));

        TRACE(TL_TRACE, ("UnitDirectoryBufferSize = 0x%x\n",
            pIrb->u.GetConfigurationInformation.UnitDirectoryBufferSize));
        TRACE(TL_TRACE, ("UnitDirectory = 0x%x\n", pIrb->u.GetConfigurationInformation.UnitDirectory));
        TRACE(TL_TRACE, ("UnitDirectoryLocation.NA_Bus_Number = 0x%x\n",
            pIrb->u.GetConfigurationInformation.UnitDirectoryLocation.IA_Destination_ID.NA_Bus_Number));
        TRACE(TL_TRACE, ("UnitDirectoryLocation.NA_Node_Number = 0x%x\n",
            pIrb->u.GetConfigurationInformation.UnitDirectoryLocation.IA_Destination_ID.NA_Node_Number));
        TRACE(TL_TRACE, ("UnitDirectoryLocation.Off_High = 0x%x\n",
            pIrb->u.GetConfigurationInformation.UnitDirectoryLocation.IA_Destination_Offset.Off_High));
        TRACE(TL_TRACE, ("UnitDirectoryLocation.Off_Low = 0x%x\n",
            pIrb->u.GetConfigurationInformation.UnitDirectoryLocation.IA_Destination_Offset.Off_Low));

        TRACE(TL_TRACE, ("UnitDependentDirectoryBufferSize = 0x%x\n",
            pIrb->u.GetConfigurationInformation.UnitDependentDirectoryBufferSize));
        TRACE(TL_TRACE, ("UnitDependentDirectory = 0x%x\n",
            pIrb->u.GetConfigurationInformation.UnitDependentDirectory));
        TRACE(TL_TRACE, ("UnitDependentDirectoryLocation.NA_Bus_Number = 0x%x\n",
            pIrb->u.GetConfigurationInformation.UnitDependentDirectoryLocation.IA_Destination_ID.NA_Bus_Number));
        TRACE(TL_TRACE, ("UnitDependentDirectoryLocation.NA_Node_Number = 0x%x\n",
            pIrb->u.GetConfigurationInformation.UnitDependentDirectoryLocation.IA_Destination_ID.NA_Node_Number));
        TRACE(TL_TRACE, ("UnitDependentDirectoryLocation.Off_High = 0x%x\n",
            pIrb->u.GetConfigurationInformation.UnitDependentDirectoryLocation.IA_Destination_Offset.Off_High));
        TRACE(TL_TRACE, ("UnitDependentDirectoryLocation.Off_Low = 0x%x\n",
            pIrb->u.GetConfigurationInformation.UnitDependentDirectoryLocation.IA_Destination_Offset.Off_Low));

        TRACE(TL_TRACE, ("VendorLeafBufferSize = 0x%x\n",
            pIrb->u.GetConfigurationInformation.VendorLeafBufferSize));
        TRACE(TL_TRACE, ("VendorLeaf->TL_CRC = 0x%x\n",
            pIrb->u.GetConfigurationInformation.VendorLeaf->TL_CRC));
        TRACE(TL_TRACE, ("VendorLeaf->TL_Length = 0x%x\n",
            pIrb->u.GetConfigurationInformation.VendorLeaf->TL_Length));
        TRACE(TL_TRACE, ("VendorLeaf->TL_Spec_Id = 0x%x\n",
            pIrb->u.GetConfigurationInformation.VendorLeaf->TL_Spec_Id));
        TRACE(TL_TRACE, ("VendorLeaf->TL_Language_Id = 0x%x\n",
            pIrb->u.GetConfigurationInformation.VendorLeaf->TL_Language_Id));

        TRACE(TL_TRACE, ("ModelLeafBufferSize = 0x%x\n",
            pIrb->u.GetConfigurationInformation.ModelLeafBufferSize));
        TRACE(TL_TRACE, ("ModelLeaf->TL_CRC = 0x%x\n",
            pIrb->u.GetConfigurationInformation.ModelLeaf->TL_CRC));
        TRACE(TL_TRACE, ("ModelLeaf->TL_Length = 0x%x\n",
            pIrb->u.GetConfigurationInformation.ModelLeaf->TL_Length));
        TRACE(TL_TRACE, ("ModelLeaf->TL_Spec_Id = 0x%x\n",
            pIrb->u.GetConfigurationInformation.ModelLeaf->TL_Spec_Id));
        TRACE(TL_TRACE, ("ModelLeaf->TL_Language_Id = 0x%x\n",
            pIrb->u.GetConfigurationInformation.ModelLeaf->TL_Language_Id));
    }
    else {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_GetConfigurationInformation:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_GetConfigurationInformation", ntStatus);
    return(ntStatus);

#endif

} // t1394_GetConfigurationInformation

NTSTATUS
t1394_BusReset(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN ULONG            fulFlags
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_BusReset");

    TRACE(TL_TRACE, ("fulFlags = 0x%x\n", fulFlags));

    // allocate irb
    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);
    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_BusReset;
    } // if


    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_BUS_RESET;
    pIrb->Flags = 0;
    pIrb->u.BusReset.fulFlags = fulFlags;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }


Exit_BusReset:

    if(pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_BusReset", ntStatus);
    return(ntStatus);
} // t1394_BusReset

NTSTATUS
t1394_GetGenerationCount(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN OUT PULONG       GenerationCount
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_GetGenerationCount");

    // allocate irb
    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);
    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_GetGenerationCount;
    } // if


    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_GET_GENERATION_COUNT;
    pIrb->Flags = 0;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (NT_SUCCESS(ntStatus)) {

        *GenerationCount = pIrb->u.GetGenerationCount.GenerationCount;
        TRACE(TL_TRACE, ("GenerationCount = 0x%x\n", *GenerationCount));
    }
    else {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }


Exit_GetGenerationCount:

    if(pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_GetGenerationCount", ntStatus);
    return(ntStatus);
} // t1394_GetGenerationCount

NTSTATUS
t1394_SendPhyConfigurationPacket(
    IN WDFDEVICE               Device,
    IN WDFREQUEST                         Request,
    IN PHY_CONFIGURATION_PACKET     PhyConfigurationPacket
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;

    ENTER("t1394_SendPhyConfigurationPacket");

    TRACE(TL_TRACE, ("PCP_Phys_ID = 0x%x\n", PhyConfigurationPacket.PCP_Phys_ID));
    TRACE(TL_TRACE, ("PCP_Packet_ID = 0x%x\n", PhyConfigurationPacket.PCP_Packet_ID));
    TRACE(TL_TRACE, ("PCP_Gap_Count = 0x%x\n", PhyConfigurationPacket.PCP_Gap_Count));
    TRACE(TL_TRACE, ("PCP_Set_Gap_Count = 0x%x\n", PhyConfigurationPacket.PCP_Set_Gap_Count));
    TRACE(TL_TRACE, ("PCP_Force_Root = 0x%x\n", PhyConfigurationPacket.PCP_Force_Root));
    TRACE(TL_TRACE, ("PCP_Reserved1 = 0x%x\n", PhyConfigurationPacket.PCP_Reserved1));
    TRACE(TL_TRACE, ("PCP_Reserved2 = 0x%x\n", PhyConfigurationPacket.PCP_Reserved2));
    TRACE(TL_TRACE, ("PCP_Inverse = 0x%x\n", PhyConfigurationPacket.PCP_Inverse));

    // allocate irb
    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);
    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_SendPhyConfigurationPacket;
    } // if



    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_SEND_PHY_CONFIG_PACKET;
    pIrb->Flags = 0;
    pIrb->u.SendPhyConfigurationPacket.PhyConfigurationPacket = PhyConfigurationPacket;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }


Exit_SendPhyConfigurationPacket:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    EXIT("t1394_SendPhyConfigurationPacket", ntStatus);
    return(ntStatus);
} // t1394_SendPhyConfigurationPacket

NTSTATUS
t1394_SetLocalHostProperties(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN ULONG            nLevel,
    IN PVOID            Information
    )
{
    NTSTATUS                ntStatus                = STATUS_SUCCESS;
    PDEVICE_EXTENSION       deviceExtension         = GetDeviceContext(Device);
    PIRB                    pIrb                    = NULL;
    PSET_LOCAL_HOST_PROPS3  R0_SetLocalHostProps3   = NULL;
    PCROM_DATA              CromData                = NULL;
    PLIST_ENTRY listHead, thisEntry;

    ENTER("t1394_SetLocalHostProperties");

    // allocate irb
    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);
    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_SetLocalHostProperties;
    } // if



    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_SET_LOCAL_HOST_PROPERTIES;
    pIrb->Flags = 0;
    pIrb->u.SetLocalHostProperties.nLevel = nLevel;

    TRACE(TL_TRACE, ("nLevel = 0x%x\n", nLevel));
    TRACE(TL_TRACE, ("Information = 0x%x\n", Information));

    if (nLevel == SET_LOCAL_HOST_PROPERTIES_GAP_COUNT) {

        PSET_LOCAL_HOST_PROPS2  SetLocalHostProps2;

        SetLocalHostProps2 = (PSET_LOCAL_HOST_PROPS2)Information;

        TRACE(TL_TRACE, ("GapCountLowerBound = 0x%x\n", SetLocalHostProps2->GapCountLowerBound));

        pIrb->u.SetLocalHostProperties.Information = Information;
    }
    else if (nLevel == SET_LOCAL_HOST_PROPERTIES_MODIFY_CROM) {

        PSET_LOCAL_HOST_PROPS3  SetLocalHostProps3;

        SetLocalHostProps3 = (PSET_LOCAL_HOST_PROPS3)Information;

        TRACE(TL_TRACE, ("fulFlags = 0x%x\n", SetLocalHostProps3->fulFlags));
        TRACE(TL_TRACE, ("hCromData = 0x%x\n", SetLocalHostProps3->hCromData));
        TRACE(TL_TRACE, ("nLength = 0x%x\n", SetLocalHostProps3->nLength));

        // since we need to create a mdl, we'll create another setlocalhostprops3
        // and pass that down to the bus driver
        R0_SetLocalHostProps3 = ExAllocatePoolWithTag(NonPagedPool,
                                                      sizeof(SET_LOCAL_HOST_PROPS3),
                                                      POOLTAG_1394);

        if (!R0_SetLocalHostProps3) {

            TRACE(TL_ERROR, ("Failed to allocate R0_SetLocalHostProps3!\n"));
            if (pIrb) {
                ExFreePoolWithTag(pIrb, POOLTAG_1394);
                pIrb = NULL;
            }

            ntStatus = STATUS_INSUFFICIENT_RESOURCES;
            goto Exit_SetLocalHostProperties;
        } // if

        TRACE(TL_TRACE, ("R0_SetLocalHostProps3 = 0x%x\n", R0_SetLocalHostProps3));

        // copy over the contents...
        RtlCopyMemory( R0_SetLocalHostProps3,
                       SetLocalHostProps3,
                       sizeof(SET_LOCAL_HOST_PROPS3)
                       );

        // branch, depending if we are adding or removing
        if (R0_SetLocalHostProps3->fulFlags == SLHP_FLAG_ADD_CROM_DATA) {

            // we are adding an entry. let's get our crom data struct...
            CromData = ExAllocatePoolWithTag(NonPagedPool,
                                             sizeof(CROM_DATA),
                                             POOLTAG_1394);

            if (!CromData) {

                TRACE(TL_ERROR, ("Failed to allocate CromData!\n"));
                if (pIrb) {
                    ExFreePoolWithTag(pIrb, POOLTAG_1394);
                    pIrb = NULL;
                }

                if (R0_SetLocalHostProps3)
                    ExFreePoolWithTag(R0_SetLocalHostProps3, POOLTAG_1394);

                ntStatus = STATUS_INSUFFICIENT_RESOURCES;
                goto Exit_SetLocalHostProperties;
            }

            // let's allocate our buffer...
            CromData->Buffer = ExAllocatePoolWithTag(NonPagedPool,
                                                     R0_SetLocalHostProps3->nLength,
                                                     POOLTAG_1394);

            TRACE(TL_TRACE, ("CromData->Buffer = 0x%x\n", CromData->Buffer));

            if (!CromData->Buffer) {

                TRACE(TL_ERROR, ("Failed to allocate CromData->Buffer!\n"));
                if (pIrb) {
                    ExFreePoolWithTag(pIrb, POOLTAG_1394);
                    pIrb = NULL;
                }

                if (R0_SetLocalHostProps3)
                    ExFreePoolWithTag(R0_SetLocalHostProps3, POOLTAG_1394);

                if (CromData)
                    ExFreePoolWithTag(CromData, POOLTAG_1394);

                ntStatus = STATUS_INSUFFICIENT_RESOURCES;
                goto Exit_SetLocalHostProperties;
            }

            // copy over contents (mdl == ring 3 buffer)
            RtlCopyMemory(CromData->Buffer,
                          &SetLocalHostProps3->Mdl,
                          SetLocalHostProps3->nLength);

            R0_SetLocalHostProps3->Mdl = IoAllocateMdl (CromData->Buffer,
                                                        R0_SetLocalHostProps3->nLength,
                                                        FALSE,
                                                        FALSE,
                                                        NULL);
            if(R0_SetLocalHostProps3->Mdl == NULL) {

                TRACE(TL_ERROR, ("Failed to allocate mdl for CromData->Buffer!\n"));
                if (pIrb) {
                    ExFreePoolWithTag(pIrb, POOLTAG_1394);
                    pIrb = NULL;
                }

                if (R0_SetLocalHostProps3)
                    ExFreePoolWithTag(R0_SetLocalHostProps3, POOLTAG_1394);

                if (CromData)
                    ExFreePoolWithTag(CromData, POOLTAG_1394);

                ntStatus = STATUS_INSUFFICIENT_RESOURCES;
                goto Exit_SetLocalHostProperties;

            }
            MmBuildMdlForNonPagedPool(R0_SetLocalHostProps3->Mdl);

            TRACE(TL_TRACE, ("Mdl = 0x%x\n", R0_SetLocalHostProps3->Mdl));
        }
        else if (SetLocalHostProps3->fulFlags == SLHP_FLAG_REMOVE_CROM_DATA) {

            TRACE(TL_TRACE, ("hCromData = 0x%x\n", R0_SetLocalHostProps3->hCromData));
        }

        pIrb->u.SetLocalHostProperties.Information = (PVOID)R0_SetLocalHostProps3;
    }

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        if (nLevel == SET_LOCAL_HOST_PROPERTIES_MODIFY_CROM) {

            if (R0_SetLocalHostProps3 &&
                R0_SetLocalHostProps3->fulFlags == SLHP_FLAG_ADD_CROM_DATA) {

                if (R0_SetLocalHostProps3->Mdl)
                    IoFreeMdl(R0_SetLocalHostProps3->Mdl);

                if (CromData) {
                    if (CromData->Buffer) {
                        ExFreePoolWithTag(CromData->Buffer, POOLTAG_1394);
                    }
                    ExFreePoolWithTag(CromData, POOLTAG_1394);
                }
            }

            if (R0_SetLocalHostProps3)
                ExFreePoolWithTag(R0_SetLocalHostProps3, POOLTAG_1394);
        }

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }
    else {

        if (nLevel == SET_LOCAL_HOST_PROPERTIES_MODIFY_CROM) {
            //
            // branch, depending if we are adding or removing
            //
            if (R0_SetLocalHostProps3 &&
                R0_SetLocalHostProps3->fulFlags == SLHP_FLAG_ADD_CROM_DATA) {

                PSET_LOCAL_HOST_PROPS3  SetLocalHostProps3;

                SetLocalHostProps3 = Information;
                SetLocalHostProps3->hCromData = R0_SetLocalHostProps3->hCromData;

                TRACE(TL_TRACE, ("hCromData = 0x%x\n", SetLocalHostProps3->hCromData));

                if (CromData) {

                    CromData->hCromData = SetLocalHostProps3->hCromData;
                    CromData->pMdl = R0_SetLocalHostProps3->Mdl;

                    // need to add to our list...

                    WdfSpinLockAcquire(deviceExtension->CromSpinLock);
                    InsertHeadList(&deviceExtension->CromData, &CromData->CromList);

                    WdfSpinLockRelease(deviceExtension->CromSpinLock);
                }
            }
            else if (R0_SetLocalHostProps3 &&
                     R0_SetLocalHostProps3->fulFlags == SLHP_FLAG_REMOVE_CROM_DATA) {

                // have to find our struct...

                WdfSpinLockAcquire(deviceExtension->CromSpinLock);

                listHead = &deviceExtension->CromData;

                for(thisEntry = listHead->Flink;
                                thisEntry != listHead;
                                CromData = NULL, thisEntry = thisEntry->Flink)
                {
                    CromData = CONTAINING_RECORD(thisEntry, CROM_DATA, CromList);
                    if (CromData->hCromData == R0_SetLocalHostProps3->hCromData) {
                        RemoveEntryList(&CromData->CromList);
                        break;
                    }
                }

                WdfSpinLockRelease(deviceExtension->CromSpinLock);

                if (CromData) {

                    if (CromData->Buffer)
                        ExFreePoolWithTag(CromData->Buffer, POOLTAG_1394);

                    if (CromData->pMdl)
                        IoFreeMdl(CromData->pMdl);

                    ExFreePoolWithTag(CromData, POOLTAG_1394);
                }
            }

            if (R0_SetLocalHostProps3)
                ExFreePoolWithTag(R0_SetLocalHostProps3, POOLTAG_1394);
        }
    }


Exit_SetLocalHostProperties:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }


    EXIT("t1394_SetLocalHostProperties", ntStatus);
    return(ntStatus);
} // t1394_SetLocalHostProperties

VOID
t1394_BusResetRoutineWorkItem(
    IN WDFWORKITEM  WorkItem
)
{
    WDFDEVICE      Device= WdfWorkItemGetParentObject(WorkItem);

    t1394_UpdateGenerationCount(Device);

    WdfObjectDelete(WorkItem);
}

VOID
t1394_BusResetRoutine(
    IN PVOID    Context
    )
{
    WDFDEVICE      Device= Context;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    NTSTATUS            status    = STATUS_SUCCESS;
    WDFREQUEST      request;
    WDF_WORKITEM_CONFIG     workitemConfig;
    WDFWORKITEM             hWorkItem;
    WDF_OBJECT_ATTRIBUTES attributes;

    ENTER("t1394_BusResetRoutine");

    TRACE(TL_TRACE, ("Context = 0x%x\n", Context));

    WDF_WORKITEM_CONFIG_INIT(&workitemConfig, t1394_BusResetRoutineWorkItem);

    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
    attributes.ParentObject = Device;

    status = WdfWorkItemCreate( &workitemConfig,
                                &attributes,
                                &hWorkItem);

    if (!NT_SUCCESS(status)) {
        TRACE(TL_ERROR, ("Failed to create workitem %x\n", status));
        return;
    }

    //
    // Execute this work item.
    //
    WdfWorkItemEnqueue(hWorkItem);

    //
    // If we have any bus reset notify irps, then nows the
    // time to complete them.
    //
    WHILE (TRUE) {

        status = WdfIoQueueRetrieveNextRequest(
                     deviceExtension->BusResetRequestsQueue,
                     &request
                     );

        if(NT_SUCCESS(status)){

            TRACE(TL_TRACE, ("Completing BusReset Request = 0x%p\n", request));
            WdfRequestCompleteWithInformation(request, STATUS_SUCCESS, 0);
            // continue;
        }else {
            ASSERTMSG("WdfIoQueueRetrieveNextRequest failed", status == STATUS_NO_MORE_ENTRIES);
            break;
        }
    }

    EXIT("t1394_BusResetRoutine", status);
} // t1394_BusResetRoutine


NTSTATUS
t1394_BusResetNotification(
    IN WDFDEVICE   Device,
    IN WDFREQUEST             Request,
    IN ULONG            fulFlags
    )
{
    NTSTATUS            ntStatus        = STATUS_SUCCESS;
    PDEVICE_EXTENSION   deviceExtension = GetDeviceContext(Device);
    PIRB                pIrb            = NULL;
    WDFREQUEST newRequest = NULL;

    ENTER("t1394_BusResetNotification");

    TRACE(TL_TRACE, ("fulFlags = 0x%x\n", fulFlags));

    // allocate irb
    pIrb = ExAllocatePoolWithTag(NonPagedPool, sizeof(IRB), POOLTAG_1394);

    if (!pIrb) {

        TRACE(TL_ERROR, ("Failed to allocate pIrb!\n"));
        ntStatus = STATUS_INSUFFICIENT_RESOURCES;
        goto Exit_BusResetNotification;
    } // if

    if(!Request) {
        ntStatus = WdfRequestCreate(
            WDF_NO_OBJECT_ATTRIBUTES,
            deviceExtension->StackIoTarget,
            &newRequest);

        if (!NT_SUCCESS(ntStatus)) {
            TRACE(TL_ERROR, ("Failed to allocate request!\n"));
            goto Exit_BusResetNotification;
        }

        Request = newRequest;
    }

    RtlZeroMemory (pIrb, sizeof (IRB));
    pIrb->FunctionNumber = REQUEST_BUS_RESET_NOTIFICATION;
    pIrb->Flags = 0;
    pIrb->u.BusResetNotification.fulFlags = fulFlags;
    pIrb->u.BusResetNotification.ResetRoutine = t1394_BusResetRoutine;
    pIrb->u.BusResetNotification.ResetContext = Device;

    ntStatus = t1394_SubmitIrpSynch(deviceExtension->StackIoTarget, Request, pIrb);

    if (!NT_SUCCESS(ntStatus)) {

        TRACE(TL_ERROR, ("SubmitIrpSync failed = 0x%x\n", ntStatus));
    }

Exit_BusResetNotification:

    if (pIrb)
    {
        ExFreePoolWithTag(pIrb, POOLTAG_1394);
    }

    if (newRequest)
    {
        WdfObjectDelete(newRequest);
    }


    EXIT("t1394_BusResetNotification", ntStatus);
    return(ntStatus);
} // t1394_BusResetNotification



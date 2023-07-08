/*++

Copyright (c) 1997  Microsoft Corporation

Module Name:

    init.c

Abstract:

    Common initialization routine for the AGP filter driver


--*/
#include "agplib.h"

//
// Local function prototypes
//

DRIVER_ADD_DEVICE AgpAddDevice;

NTSTATUS
AgpBuildHackTable(
    IN OUT PAGP_HACK_TABLE_ENTRY *AgpHackTable,
    IN HANDLE HackTableKey
    );

NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    );

DRIVER_UNLOAD AgpDriverUnload;

VOID
AgpInitFavoredMemoryRanges(
   IN PTARGET_EXTENSION Extension);

VOID
AgpLowMemInit(
    );

VOID
AgpLowMemTerminate(
    );

#ifdef ALLOC_PRAGMA
#pragma alloc_text(PAGE, AgpAddDevice)
#pragma alloc_text(PAGE, DriverEntry)
#pragma alloc_text(PAGE, AgpDriverUnload)
#pragma alloc_text(PAGE, AgpAttachDeviceRelations)
#pragma alloc_text(INIT, AgpBuildHackTable)
#pragma alloc_text(PAGE, AgpInitFavoredMemoryRanges)
#endif

#if DBG
ULONG AgpLogLevel = 0;
#else
ULONG AgpLogLevel = 0;
#endif
ULONG AgpStopLevel = 0;
PDRIVER_OBJECT AgpDriver;

GLOBALS Globals = { { 0, UNICODE_NULL }, 0, 0,
#if DBG
                    (AGP_GART_ACCESS_VERIFICATION |
                     AGP_GART_GUARD_VERIFICATION |
                     AGP_GART_CORRUPTION_VERIFICATION |
                     AGP_TLB_FLUSHING_VERIFICATION |
                     AGP_CHIPSET_CACHE_FLUSHING_VERIFICATION |
                     AGP_LOW_MEMORY_VERIFICATION),

#else
                    0,
#endif
                    0
};

FAST_IO_DISPATCH AGPFastIoDispatch;

//
// Table of hacks for broken hardware read from the registry at init
//
PAGP_HACK_TABLE_ENTRY AgpDeviceHackTable = NULL;
PAGP_HACK_TABLE_ENTRY AgpGlobalHackTable = NULL;
ULONGLONG AgpImageHack = 0;

#define HACKFMT_VENDORDEV         (sizeof(L"VVVVDDDD") - sizeof(UNICODE_NULL))
#define HACKFMT_VENDORDEVREVISION (sizeof(L"VVVVDDDDRR") - sizeof(UNICODE_NULL))
#define HACKFMT_SUBSYSTEM         (sizeof(L"VVVVDDDDSSSSssss") - sizeof(UNICODE_NULL))
#define HACKFMT_SUBSYSTEMREVISION (sizeof(L"VVVVDDDDSSSSssssRR") - sizeof(UNICODE_NULL))
#define HACKFMT_MAX_LENGTH        HACKFMT_SUBSYSTEMREVISION

#define HACKFMT_DEVICE_OFFSET     4
#define HACKFMT_SUBVENDOR_OFFSET  8
#define HACKFMT_SUBSYSTEM_OFFSET 12
#define HACKFMT_REVISION_OFFSET  16

NTSTATUS
AgpAddDevice(
    IN PDRIVER_OBJECT DriverObject,
    IN PDEVICE_OBJECT PhysicalDeviceObject
    )
{
    NTSTATUS Status;
    PDEVICE_OBJECT Device;
    PTARGET_EXTENSION Extension;
    UCHAR CapabilityID;

    PAGED_CODE();

    //
    // Create our device
    //
    Status = IoCreateDevice(DriverObject,
                            sizeof(TARGET_EXTENSION)  + AgpExtensionSize - sizeof(ULONGLONG),
                            NULL,
                            FILE_DEVICE_BUS_EXTENDER,
                            FILE_DEVICE_SECURE_OPEN, // Not really necessary in our case as we don't support create
                            FALSE,
                            &Device);
    if (!NT_SUCCESS(Status)) 
    {
        AGPLOG(AGP_CRITICAL,("AgpAddDevice: IoCreateDevice failed %08lx\n",Status));
        return(Status);
    }

    //
    // Initialize the device extension
    //
    Extension = Device->DeviceExtension;
    Extension->CommonExtension.Type = AgpTargetFilter;
    Extension->CommonExtension.Deleted = FALSE;
    Extension->CommonExtension.Signature = TARGET_SIG;

    if (AgpImageHack & AGPLIB_IMAGE_HACK_USE_LEGACY_BUS_INTERFACE) 
    {
        PCI_AGP_CAPABILITY TargetCap;
    
        Extension->CommonExtension.BusInterface.SetBusData =
            ApLegacySetBusData;
        Extension->CommonExtension.BusInterface.GetBusData =
            ApLegacyGetBusData;
        Extension->CommonExtension.BusInterface.InterfaceReference =
            ApLegacyInterfaceReference;
        Extension->CommonExtension.BusInterface.InterfaceDereference =
            ApLegacyInterfaceDereference;

        Status = AgpLibGetTargetCapability(GET_AGP_CONTEXT(Extension),
                                           &TargetCap);
    
        if (!NT_SUCCESS(Status)) 
        {
            AGPLOG(AGP_CRITICAL, ("AgpAddDevice: Failed to get AGP capability from the h2p bridge.\n"));
            IoDeleteDevice(Device);
            return Status;
        }
    
        CapabilityID = TargetCap.Header.CapabilityID;
    }
    else
    {
#if (WINVER > 0x501)
        Status =
            ApQueryAgpTargetBusInterface(PhysicalDeviceObject,
                                         &Extension->CommonExtension.BusInterface, 
                                         &CapabilityID);
#else
        Status = STATUS_NOT_IMPLEMENTED;
#endif // (WINVER > 0x501)
    
        //
        // Perhaps this OS doesn't support the new AGP_TARGET_BUS_INTERFACE, then
        // we can still support the target bridge without using HalGet/SetBusData
        // we just have to do a bit more work, and probe to see if there is an AGP
        // target capability on this bridge device
        //
#ifndef AGP_INTERFACE_TEST
        if (!NT_SUCCESS(Status)) 
        {
            Status = ApQueryBusInterface(PhysicalDeviceObject,
                                         &Extension->CommonExtension.BusInterface);
            if (NT_SUCCESS(Status)) 
            {
                PCI_AGP_CAPABILITY TargetCap;
                
                //
                // Look for the target bride capability
                //
                Status = AgpLibGetTargetCapability(GET_AGP_CONTEXT(Extension),
                                                   &TargetCap);
                if (NT_SUCCESS(Status)) 
                {
    
#if !defined(_IA64_)  
                    //
                    // If this is a 3.5 capability bridge, then it must
                    // have the right ID (0xE)!
                    //
                    if (TargetCap.Header.CapabilityID !=
                        PCI_CAPABILITY_ID_AGP_TARGET) 
                    {
                        if ((TargetCap.Major == 3) &&
                            (TargetCap.Minor == 5)) 
                        {  
                            AGPLOG(AGP_CRITICAL,
                                   ("AgpAddDevice: Incorrect AGP3.5 Target "
                                    "CapabilityID (2), should be 0xE!\n"));
                            IoDeleteDevice(Device);
                            return STATUS_NO_SUCH_DEVICE;                    
                        }
                    }
#endif // !defined(_IA64_)                
    
                    CapabilityID = TargetCap.Header.CapabilityID;
    
                    //
                    // For our UAGP35 driver to work on older OS, we will
                    // attempt to override the bus interface with
                    // HalGet/SetBusData functions that access the host, if
                    // we can find an AGP capability there, otherwise we
                    // will leave well enough alone so other drivers will
                    // continue to get the same behavior they've always had,
                    // namely bus interface still munges whatever, and lib
                    // behavior defaults to traditional/non-bridge w/respect
                    // to resource handling
                    //
                } 
                else 
                {                                
                    BUS_INTERFACE_STANDARD BusInterfaceSave;

                    CapabilityID = PCI_CAPABILITY_ID_AGP;

#if (WINVER < 0x502)
                    //
                    // Save the bus interface
                    // 
                    BusInterfaceSave.SetBusData =
                        Extension->CommonExtension.BusInterface.SetBusData;
                    BusInterfaceSave.GetBusData =
                        Extension->CommonExtension.BusInterface.GetBusData;
                    BusInterfaceSave.InterfaceReference =
                        Extension->CommonExtension.BusInterface.InterfaceReference;
                    BusInterfaceSave.InterfaceDereference =
                        Extension->CommonExtension.BusInterface.InterfaceDereference;
                    Extension->CommonExtension.BusInterface.SetBusData =
                        ApLegacySetBusData;
                    Extension->CommonExtension.BusInterface.GetBusData =
                        ApLegacyGetBusData;
                    Extension->CommonExtension.BusInterface.InterfaceReference =
                        ApLegacyInterfaceReference;
                    Extension->CommonExtension.BusInterface.InterfaceDereference =
                        ApLegacyInterfaceDereference;
                    
                    Status = AgpLibGetTargetCapability(GET_AGP_CONTEXT(Extension),
                                                       &TargetCap);

                    if (!NT_SUCCESS(Status)) 
                    {
                        Extension->CommonExtension.BusInterface.SetBusData =
                            BusInterfaceSave.SetBusData;
                        Extension->CommonExtension.BusInterface.GetBusData =
                            BusInterfaceSave.GetBusData;                    
                        Extension->CommonExtension.BusInterface.InterfaceReference =
                            BusInterfaceSave.InterfaceReference;
                        Extension->CommonExtension.BusInterface.InterfaceDereference =
                            BusInterfaceSave.InterfaceDereference;                    
                    }
#endif // (WINVER < 0x502)    

                    Status = STATUS_SUCCESS; // We do have a bus interface
                }
            }
        }
#endif // AGP_INTERFACE_TEST
    }

    if (!NT_SUCCESS(Status)) 
    {            
        AGPLOG(AGP_CRITICAL,
               ("AgpAddDevice: query for bus interface failed %08lx\n", Status));
        IoDeleteDevice(Device);
        return(STATUS_NO_SUCH_DEVICE);
    }
    Extension->ChildDevice = NULL;
    Extension->Resources = NULL;
    Extension->ResourcesTranslated = NULL;
    Extension->FavoredMemory.NumRanges = 0;
    Extension->FavoredMemory.Ranges = NULL;
    Extension->GartBase.QuadPart = 0;
    Extension->GartLengthInPages = 0;
    Extension->AgpBase.QuadPart = (ULONGLONG)-1;
    Extension->AgpSize = 0;
    Extension->Agp3BridgeResourceIndex = JUNK_INDEX;

    Extension->AgpV_Ctx.VerifierDpcEnable = FALSE;
    Extension->AgpV_Ctx.VerifierCommand = Globals.AgpCommand;
    Extension->AgpV_Ctx.VerifierFlags = Globals.VerifierFlags;
    Extension->AgpV_Ctx.PlatformInit = NULL;
    Extension->AgpV_Ctx.PlatformWorker = NULL;
    Extension->AgpV_Ctx.PlatformStop = NULL;
    Extension->AgpV_Ctx.PowerCallbackObj = NULL;

    InitializeListHead(&Extension->AgpV_Ctx.AllocationList);
    ExInitializeFastMutex(&Extension->AgpV_Ctx.VerifierLock);
    KeInitializeTimer(&Extension->AgpV_Ctx.VerifierTimer);
    KeInitializeDpc(&Extension->AgpV_Ctx.VerifierDpc,
                    AgpVerifierDpc,
                    Extension);

    if (CapabilityID == PCI_CAPABILITY_ID_AGP_TARGET) 
    {
            Extension->StartTarget = Agp3StartTargetBridge;
            Extension->FilterResourceRquirements =
                Agp3FilterResourceRequirementsBridge;
    } 
    else 
    {
        ASSERT(CapabilityID == PCI_CAPABILITY_ID_AGP);
            Extension->StartTarget = AgpStartTargetHost;
            Extension->FilterResourceRquirements =
                AgpFilterResourceRequirementsHost;
    }

/*    Extension->Lock = ExAllocatePoolWithTag(NonPagedPool, sizeof(FAST_MUTEX), 'MFgA');
    if (Extension->Lock == NULL) {
        AGPLOG(AGP_CRITICAL,
               ("AgpAddDevice: allocation of fast mutext failed\n"));
        RELEASE_BUS_INTERFACE(Extension);
        IoDeleteDevice(Device);
        return(STATUS_INSUFFICIENT_RESOURCES);
    }
    ExInitializeFastMutex(Extension->Lock);  */

    //
    // Attach to the supplied PDO
    //
    Extension->CommonExtension.AttachedDevice = IoAttachDeviceToDeviceStack(Device, PhysicalDeviceObject);
    if (Extension->CommonExtension.AttachedDevice == NULL) 
    {
        //
        // The attach failed.
        //
        AGPLOG(AGP_CRITICAL,
               ("AgpAddDevice: IoAttachDeviceToDeviceStack from %p to %p failed\n",
               Device,
               PhysicalDeviceObject));
        RELEASE_BUS_INTERFACE(Extension);
        //ExFreePool(Extension->Lock);
        IoDeleteDevice(Device);
        return(STATUS_INSUFFICIENT_RESOURCES);
    }

    //
    // Figure out our favored memory ranges
    //
    AgpInitFavoredMemoryRanges(Extension);

    //
    // Allocated and initalize the Gart guard pages that will be mapped into every empty 
    // gart translation table entry
    //
    if (AgpGuardRegionInit(Extension) == FALSE)
    {        
        IoDetachDevice(Extension->CommonExtension.AttachedDevice);
        RELEASE_BUS_INTERFACE(Extension);
        IoDeleteDevice(Device);
        return(STATUS_INSUFFICIENT_RESOURCES);        
    }
    
    //
    // Finally call the chipset-specific code for target initialization
    //
    Status = AgpInitializeTarget(GET_AGP_CONTEXT(Extension), Extension->AgpGuardPagePhys);
    if (!NT_SUCCESS(Status)) 
    {
        AGPLOG(AGP_CRITICAL,
               ("AgpAddDevice: AgpInitializeTarget on device %p failed %08lx\n",
                Device,
                Status));
        AgpGuardRegionFree(Extension);
        IoDetachDevice(Extension->CommonExtension.AttachedDevice);
        RELEASE_BUS_INTERFACE(Extension);
        //ExFreePool(Extension->Lock);
        IoDeleteDevice(Device);
        return(Status);
    }

    Extension->PDO = PhysicalDeviceObject;
    Extension->Self = Device;

    Status = AgpWmiRegistration(Extension);
    if (!NT_SUCCESS(Status)) 
    {
        AGPLOG(AGP_CRITICAL, ("AgpWmiRegistration failed %08lx\n", Status));
        AgpGuardRegionFree(Extension);
        IoDetachDevice(Extension->CommonExtension.AttachedDevice);
        RELEASE_BUS_INTERFACE(Extension);
        //ExFreePool(Extension->Lock);
        IoDeleteDevice(Device);
        return Status;
    }
    Device->Flags &= ~DO_DEVICE_INITIALIZING;

    return STATUS_SUCCESS;
}

NTSTATUS
AgpBuildHackTable(
    IN OUT PAGP_HACK_TABLE_ENTRY *AgpHackTable,
    IN HANDLE HackTableKey
    )
{

    NTSTATUS status;
    PKEY_FULL_INFORMATION keyInfo = NULL;
    ULONG hackCount, size, index;
    USHORT temp;
    PAGP_HACK_TABLE_ENTRY entry;
    ULONGLONG data;
    PKEY_VALUE_FULL_INFORMATION valueInfo = NULL;
    ULONG valueInfoSize = sizeof(KEY_VALUE_FULL_INFORMATION)
                          + HACKFMT_MAX_LENGTH +
                          + sizeof(ULONGLONG);

    //
    // Get the key info so we know how many hack values there are.
    // This does not change during system initialization.
    //

    status = ZwQueryKey(HackTableKey,
                        KeyFullInformation,
                        NULL,
                        0,
                        &size
                        );

    if (status != STATUS_BUFFER_TOO_SMALL) {
        ASSERT(!NT_SUCCESS(status));
        goto cleanup;
    }

    ASSERT(size > 0);

    keyInfo = ExAllocatePool(PagedPool, size);

    if (!keyInfo) {
        status = STATUS_INSUFFICIENT_RESOURCES;
        goto cleanup;
    }

    status = ZwQueryKey(HackTableKey,
                        KeyFullInformation,
                        keyInfo,
                        size,
                        &size
                        );

    if (!NT_SUCCESS(status)) {
        goto cleanup;
    }

    hackCount = keyInfo->Values;
    if (hackCount > (hackCount + 1)) 
    {
        goto cleanup;
    }

    ExFreePool(keyInfo);
    keyInfo = NULL;

    //
    // Allocate and initialize the hack table
    //

    *AgpHackTable = ExAllocatePool(NonPagedPool,
                                  (hackCount + 1) * sizeof(AGP_HACK_TABLE_ENTRY)
                                  );

    if (!*AgpHackTable) {
        status = STATUS_INSUFFICIENT_RESOURCES;
        goto cleanup;
    }


    //
    // Allocate a valueInfo buffer big enough for the biggest valid
    // format and a ULONGLONG worth of data.
    //

    valueInfo = ExAllocatePool(PagedPool, valueInfoSize);

    if (!valueInfo) {
        status = STATUS_INSUFFICIENT_RESOURCES;
        goto cleanup;
    }

    entry = *AgpHackTable;

    for (index = 0; index < hackCount; index++) {

        status = ZwEnumerateValueKey(HackTableKey,
                                     index,
                                     KeyValueFullInformation,
                                     valueInfo,
                                     valueInfoSize,
                                     &size
                                     );

        if (!NT_SUCCESS(status)) {
            if (status == STATUS_BUFFER_OVERFLOW || status == STATUS_BUFFER_TOO_SMALL) {
                //
                // All out data is of fixed length and the buffer is big enough
                // so this can't be for us.
                //

                continue;
            } else {
                goto cleanup;
            }
        }

        //
        // Get pointer to the data if its of the right type
        //

        if ((valueInfo->Type == REG_BINARY) &&
            (valueInfo->DataLength == sizeof(ULONGLONG))) {
            data = *(ULONGLONG UNALIGNED *)(((PUCHAR)valueInfo) + valueInfo->DataOffset);
        } else {
            //
            // We only deal in ULONGLONGs
            //

            continue;
        }

        //
        // Now see if the name is formatted like we expect it to be:
        // VVVVDDDD
        // VVVVDDDDRR
        // VVVVDDDDSSSSssss
        // VVVVDDDDSSSSssssRR

        if ((valueInfo->NameLength != HACKFMT_VENDORDEV) &&
            (valueInfo->NameLength != HACKFMT_VENDORDEVREVISION) &&
            (valueInfo->NameLength != HACKFMT_SUBSYSTEM) &&
            (valueInfo->NameLength != HACKFMT_SUBSYSTEMREVISION)) {

            //
            // This isn't ours
            //

            AGPLOG(
                AGP_CRITICAL,
                ("Skipping hack entry with invalid length name\n"
                 ));

            continue;
        }


        //
        // This looks plausable - try to parse it and fill in a hack table
        // entry
        //

        RtlZeroMemory(entry, sizeof(AGP_HACK_TABLE_ENTRY));

        //
        // Look for DeviceID and VendorID (VVVVDDDD)
        //

        if (!AgpStringToUSHORT(valueInfo->Name, 
                               valueInfo->NameLength, 
                               &entry->VendorID)) {
            continue;
        }

        if (!AgpStringToUSHORT(valueInfo->Name + HACKFMT_DEVICE_OFFSET,
                               valueInfo->NameLength - HACKFMT_DEVICE_OFFSET*sizeof(UNICODE_NULL),
                               &entry->DeviceID)) {
            continue;
        }


        //
        // Look for SubsystemVendorID/SubSystemID (SSSSssss)
        //

        if ((valueInfo->NameLength == HACKFMT_SUBSYSTEM) ||
            (valueInfo->NameLength == HACKFMT_SUBSYSTEMREVISION)) {

            if (!AgpStringToUSHORT(valueInfo->Name + HACKFMT_SUBVENDOR_OFFSET,
                                   valueInfo->NameLength - HACKFMT_SUBVENDOR_OFFSET*sizeof(UNICODE_NULL),
                                   &entry->SubVendorID)) {
                continue;
            }

            if (!AgpStringToUSHORT(valueInfo->Name + HACKFMT_SUBSYSTEM_OFFSET,
                                   valueInfo->NameLength - HACKFMT_SUBSYSTEM_OFFSET*sizeof(UNICODE_NULL),
                                   &entry->SubSystemID)) {
                continue;
            }

            entry->Flags |= AGP_HACK_FLAG_SUBSYSTEM;
        }

        //
        // Look for RevisionID (RR)
        //

        if ((valueInfo->NameLength == HACKFMT_VENDORDEVREVISION) ||
            (valueInfo->NameLength == HACKFMT_SUBSYSTEMREVISION)) {
            if (AgpStringToUSHORT(valueInfo->Name +
                                  HACKFMT_REVISION_OFFSET, 
                                  valueInfo->NameLength - HACKFMT_REVISION_OFFSET*sizeof(UNICODE_NULL),
                                  &temp)) {
                entry->RevisionID = temp & 0xFF;
                entry->Flags |= AGP_HACK_FLAG_REVISION;
            } else {
                continue;
            }
        }

        ASSERT(entry->VendorID != 0xFFFF);

        //
        // Fill in the entry
        //

        entry->DeviceFlags = data;

        AGPLOG(
            AGP_CRITICAL,
            ("Adding Hack entry for Vendor:0x%04x Device:0x%04x ",
            entry->VendorID, entry->DeviceID
            ));

        if (entry->Flags & AGP_HACK_FLAG_SUBSYSTEM) {
            AGPLOG(
                AGP_CRITICAL,
                ("SybSys:0x%04x SubVendor:0x%04x ",
                 entry->SubSystemID, entry->SubVendorID
                 ));
        }

        if (entry->Flags & AGP_HACK_FLAG_REVISION) {
            AGPLOG(
                AGP_CRITICAL,
                ("Revision:0x%02x",
                 (ULONG) entry->RevisionID
                 ));
        }

        AGPLOG(
            AGP_CRITICAL,
            (" = 0x%I64x\n",
             entry->DeviceFlags
             ));

        entry++;
    }

    ASSERT(entry < (*AgpHackTable + hackCount + 1));

    //
    // Terminate the table with an invalid VendorID
    //

    entry->VendorID = 0xFFFF;

    ExFreePool(valueInfo);

    return STATUS_SUCCESS;

cleanup:

    ASSERT(!NT_SUCCESS(status));

    if (keyInfo) {
        ExFreePool(keyInfo);
    }

    if (valueInfo) {
        ExFreePool(valueInfo);
    }

    if (*AgpHackTable) {
        ExFreePool(*AgpHackTable);
        *AgpHackTable = NULL;
    }

    return status;

}


VOID
AgpInitFavoredMemoryRanges(
   IN PTARGET_EXTENSION Extension)
/*++

Routine Description:

    Determines the optimum memory ranges for AGP physical memory
    allocation by calling the ACPI BANK method provided by the
    AGP northbridge in order to determine which physical memory
    ranges are decoded by that northbridge.

    Initializes the FavoredMemory sturcture in the target extension
    with the proper ranges.

    If this routine fails, then the FavoredMemory structure
    is left untouched in its initialized state (i.e. no favored memory
    ranges found).

Arguments:

    Extension - The target extension.


Return Value:

    NONE. Upon failure,

--*/

{
   PDEVICE_OBJECT LowerPdo;
   IO_STATUS_BLOCK IoStatus;
   PIRP Irp;
   KEVENT event;
   NTSTATUS Status;
   ACPI_EVAL_INPUT_BUFFER inputBuffer;
   UCHAR ResultBuffer[sizeof(ACPI_EVAL_OUTPUT_BUFFER) + MAX_MBAT_SIZE];
   PACPI_EVAL_OUTPUT_BUFFER outputBuffer;
   PACPI_METHOD_ARGUMENT MethodArg;
   PMBAT Mbat;
   UCHAR i;
   USHORT j;

   PAGED_CODE(); 
    
   //
   // Get an event to wait on
   //

   KeInitializeEvent(&event, NotificationEvent, FALSE);

   // Get a PDO where we will send the request IRP.

   LowerPdo = Extension->CommonExtension.AttachedDevice;

   //
   // Initialize the input parameters and the output buffer.
   //
   RtlZeroMemory( &inputBuffer, sizeof(ACPI_EVAL_INPUT_BUFFER) );
   inputBuffer.MethodNameAsUlong = CM_BANK_METHOD;
   inputBuffer.Signature = ACPI_EVAL_INPUT_BUFFER_SIGNATURE;
   outputBuffer = (PACPI_EVAL_OUTPUT_BUFFER)ResultBuffer;

   //
   // Build the request to call the BANK method.
   //
   Irp = IoBuildDeviceIoControlRequest(
        IOCTL_ACPI_EVAL_METHOD,
        LowerPdo,
        &inputBuffer,
        sizeof(ACPI_EVAL_INPUT_BUFFER),
        outputBuffer,
        sizeof(ResultBuffer),
        FALSE,
        &event,
        &IoStatus
        );

   if (!Irp)
   {
      return;
   }

   //
   // Send to the ACPI driver
   //
   Status = IoCallDriver ( LowerPdo, Irp);
   if (Status == STATUS_PENDING)
   {
         KeWaitForSingleObject( &event, Executive, KernelMode, FALSE, NULL);
         Status = IoStatus.Status;
   }

   if (NT_SUCCESS(Status))
   {
      AGPLOG(AGP_NOISE, ("AGPLIB: ACPI BANK Method Executed.\n"));

      //
      // Sanity check method results
      //

      MethodArg = outputBuffer->Argument;
      if ((outputBuffer->Signature == ACPI_EVAL_OUTPUT_BUFFER_SIGNATURE) &&
          (MethodArg->DataLength >= sizeof(MBAT)) &&
          (MethodArg->Type == ACPI_METHOD_ARGUMENT_BUFFER))
      {

         AGPLOG(AGP_NOISE, ("AGPLIB: MBAT appears valid.\n"));

         //
         // Grab the MBAT and see if we can parse it
         //

         Mbat = (PMBAT)MethodArg->Data;

         if (Mbat->TableVersion == MBAT_VERSION) {
            AGPLOG(AGP_NOISE, ("AGPLIB: Parsing MBAT.\n"));

             //
             // Calculate the number of favored ranges mentioned
             // in the MBAT
             //

             i=Mbat->ValidEntryBitmap;
             while(i)
             {
                Extension->FavoredMemory.NumRanges++;
                i = i & (i-1);
             }

             AGPLOG(AGP_NOISE, ("AGPLIB: %u favored ranges found.\n",
                      Extension->FavoredMemory.NumRanges));

             if(Extension->FavoredMemory.NumRanges == 0) return;

             //
             // Allocate the favored memory range structure in our device
             // extension
             //

             Extension->FavoredMemory.Ranges =
                ExAllocatePool(NonPagedPool, sizeof(AGP_MEMORY_RANGE) *
                               Extension->FavoredMemory.NumRanges);

             if (Extension->FavoredMemory.Ranges == NULL) {
                Extension->FavoredMemory.NumRanges = 0;
                return;
             }


             //
             // Initialize the favored memory ranges in our extension
             // based upon the MBAT
             //

             i=0;
             j=0;
             while(Mbat->ValidEntryBitmap)
             {
                if (Mbat->ValidEntryBitmap & 1)
                {
                   if (Mbat->DecodeRange[i].Lower.QuadPart > AgpMaximumAddress.QuadPart) {
                      // This range is invalid since its lower address is above
                      // the highest allowable address

                      AGPLOG(AGP_NOISE, ("AGPLIB: Invalid MBAT Range ==> %I64x - %I64x\n",
                               Mbat->DecodeRange[i].Lower.QuadPart,
                               Mbat->DecodeRange[i].Upper.QuadPart));

                      // Pretend like this range never existed ...
                      //

                      Extension->FavoredMemory.NumRanges--;

                   }
                   else
                   {

                     // This is a valid range.

                     Extension->FavoredMemory.Ranges[j].Lower.QuadPart =
                         Mbat->DecodeRange[i].Lower.QuadPart;
                     Extension->FavoredMemory.Ranges[j].Upper.QuadPart =
                         Mbat->DecodeRange[i].Upper.QuadPart;


                     AGPLOG(AGP_NOISE, ("AGPLIB: MBAT Range ==> %I64x - %I64x\n",
                              Mbat->DecodeRange[i].Lower.QuadPart,
                              Mbat->DecodeRange[i].Upper.QuadPart));

                     if(Extension->FavoredMemory.Ranges[j].Upper.QuadPart >
                        AgpMaximumAddress.QuadPart)
                     {
                        AGPLOG(AGP_NOISE, ("AGPLIB: Adjusting range to fit within maximum allowable address.\n"));
                        Extension->FavoredMemory.Ranges[j].Upper.QuadPart =
                           AgpMaximumAddress.QuadPart;
                     }

                     j++;
                   }
                }
                Mbat->ValidEntryBitmap >>= 1;
                i++;
             }

         } else {

            AGPLOG(AGP_WARNING, ("AGPLIB: Unknown MBAT version.\n"));

         }

}


    }
}


NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    )

/*++

Routine Description:

    Entrypoint needed to initialize the AGP filter.

Arguments:

    DriverObject - Pointer to the driver object created by the system.

    RegistryPath - Pointer to the unicode registry service path.

Return Value:

    NT status.

--*/

{
    NTSTATUS Status;
    HANDLE serviceKey, paramsKey;
    UNICODE_STRING UnicodeString;
    OBJECT_ATTRIBUTES attributes;

    PAGED_CODE();

    //
    // Save the RegistryPath for WMI
    //
    Globals.RegistryPath.MaximumLength =
        RegistryPath->Length + sizeof(UNICODE_NULL);

    Globals.RegistryPath.Length = RegistryPath->Length;

    Globals.RegistryPath.Buffer =
        ExAllocatePoolWithTag(PagedPool,
                              Globals.RegistryPath.MaximumLength,
                              'GpgA'
                              );    

    if (!Globals.RegistryPath.Buffer) {
        return STATUS_INSUFFICIENT_RESOURCES;
    }
   
    RtlCopyUnicodeString(&Globals.RegistryPath, RegistryPath);

    AgpDriver = DriverObject;

    DriverObject->DriverExtension->AddDevice = AgpAddDevice;
    DriverObject->DriverUnload               = AgpDriverUnload;

    DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = AgpDispatchDeviceControl;
    DriverObject->MajorFunction[IRP_MJ_PNP] = AgpDispatchPnp;
    DriverObject->MajorFunction[IRP_MJ_POWER] = AgpDispatchPower;
    DriverObject->MajorFunction[IRP_MJ_SYSTEM_CONTROL] = AgpDispatchWmi;

    //
    // Fill out the Fast Io Detach callback for our master filter
    //
    RtlZeroMemory(&AGPFastIoDispatch, sizeof(FAST_IO_DISPATCH)) ;
    AGPFastIoDispatch.SizeOfFastIoDispatch = sizeof(FAST_IO_DISPATCH) ;
    AGPFastIoDispatch.FastIoDetachDevice = AGPFastIoDetachCallback ;
    DriverObject->FastIoDispatch = &AGPFastIoDispatch ;

    //
    // Read the image hack.
    //

    AgpImageHack = AgpQueryImageHack();

    RtlInitUnicodeString(&UnicodeString,
                         L"\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\"
                         L"Control");

    //
    // Open the global hack key and retrieve the gloabl hack table
    //
    InitializeObjectAttributes(&attributes,
                               &UnicodeString,
                               OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE,
                               NULL,
                               NULL
                               );

    Status = ZwOpenKey(&serviceKey,
                       KEY_READ,
                       &attributes
                       );

    //
    // We must succeed here, there are devices that can freeze a system,
    // and something is really wrong if we can't access these values
    //
    if (!NT_SUCCESS(Status)) {
        AgpDriverUnload(DriverObject);
        return Status;
    }

    AgpOpenKey(L"AGP", serviceKey, &paramsKey, &Status);

    ZwClose(serviceKey);

    if (!NT_SUCCESS(Status)) {
        AgpDriverUnload(DriverObject);
        return Status;
    }

    Status = AgpBuildHackTable(&AgpGlobalHackTable, paramsKey);

    //
    // Look for AGP VerifierFlags
    //
    {
        ULONG Length;
        NTSTATUS VerifierStatus;
        UNICODE_STRING UnicodeString2;

        struct {
            KEY_VALUE_PARTIAL_INFORMATION Inf;
            UCHAR Data[3];
        } PartialInformation;

        RtlInitUnicodeString(&UnicodeString2, L"VerifierFlags");

        VerifierStatus = ZwQueryValueKey(paramsKey,
                                         &UnicodeString2,
                                         KeyValuePartialInformation,
                                         &PartialInformation,
                                         sizeof(PartialInformation),
                                         &Length);
        
        if (NT_SUCCESS(VerifierStatus)) {
            Globals.VerifierFlags = *((PULONG)(PartialInformation.Inf.Data));           
        }
    }

    if (0 != Globals.VerifierFlags) 
    {
        AGPLOG(AGP_NOISE, 
               ("Agp verifier enabled with flags 0x%08X.\n",
               Globals.VerifierFlags));
    }
    else
    {
        AGPLOG(AGP_NOISE, 
               ("Agp verifier disabled.\n"));
    }

    ZwClose(paramsKey);

    if (!NT_SUCCESS(Status)) {
        AgpDriverUnload(DriverObject);
        return Status;
    }

    //
    // Open our service key and retrieve any platform hack(s)
    //
    InitializeObjectAttributes(&attributes,
                               RegistryPath,
                               OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE,
                               NULL,
                               NULL
                               );

    Status = ZwOpenKey(&serviceKey,
                       KEY_READ,
                       &attributes
                       );

    //
    // Maybe their chipset is so burly, it doesn't require any hacks!
    //
    if (!NT_SUCCESS(Status)) {
        goto Done;
    }

    AgpOpenKey(L"Parameters", serviceKey, &paramsKey, &Status);

    ZwClose(serviceKey);

    //
    // Don't care
    //
    if (!NT_SUCCESS(Status)) {
        goto Done;
    }

    //
    // Again, disregard status
    //
    AgpBuildHackTable(&AgpDeviceHackTable, paramsKey);

    ZwClose(paramsKey);

Done:

    if (Globals.VerifierFlags & AGP_LOW_MEMORY_VERIFICATION) 
    {
        AgpLowMemInit();
    }

    return STATUS_SUCCESS;
}



VOID
AgpDriverUnload(
    IN PDRIVER_OBJECT DriverObject
    )
/*++

Routine Description:

    Entrypoint used to unload the AGP driver

Arguments:

    DriverObject - Pointer to the driver object created by the system

Return Value:

    None

--*/
{
    PAGED_CODE();
    
    if (AgpDeviceHackTable != NULL) {
        ExFreePool(AgpDeviceHackTable);
        AgpDeviceHackTable = NULL;
    }

    if (AgpGlobalHackTable != NULL) {
        ExFreePool(AgpGlobalHackTable);
        AgpGlobalHackTable = NULL;
    }

    if (Globals.RegistryPath.Buffer != NULL) {
        ExFreePool(Globals.RegistryPath.Buffer);
        Globals.RegistryPath.Buffer = NULL; 
    }

    AgpLowMemTerminate();
}



NTSTATUS
AgpAttachDeviceRelations(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PTARGET_EXTENSION Extension
    )
/*++

Routine Description:

    Completion routine for BusRelations IRP_MN_QUERY_DEVICE_RELATIONS irps sent
    to the PCI-PCI bridge PDO.  In order to handle QUERY_INTERFACE irps sent
    from the AGP device, we must attach to its PDO.  That means we attach to
    all the child PDOs of the PCI-PCI bridge.

Arguments:

    DeviceObject - Supplies the device object

    Irp - Supplies the IRP_MN_QUERY_DEVICE_RELATIONS irp

    Extension - Supplies the AGP device extension.

Return Value:

    NTSTATUS

--*/

{
    NTSTATUS Status;
    PDEVICE_RELATIONS Relations;
    ULONG i;
    PDEVICE_OBJECT NewDevice;
    PMASTER_EXTENSION NewExtension;
    AGP_CRITICAL_ROUTINE_CONTEXT routineContext;
#if DBG
    ULONG MasterCount=0;
#endif

    PAGED_CODE();

    //
    // If we have already attached, don't do it again.
    //
    if (Extension->ChildDevice != NULL) {
        return(STATUS_SUCCESS);
    }

    Relations = (PDEVICE_RELATIONS)Irp->IoStatus.Information;
    //
    // If somebody completed the IRP with success, but never
    // filled in the Relations field, then assume there are
    // no children and we don't have to do anything.
    //
    if (Relations == NULL) {
        return(STATUS_SUCCESS);
    }

    for (i=0; i<Relations->Count; i++) {

        //
        // Create a device object to attach to this PDO.
        //
        Status = IoCreateDevice(AgpDriver,
                                sizeof(MASTER_EXTENSION),
                                NULL,
                                FILE_DEVICE_BUS_EXTENDER,
                                0,
                                FALSE,
                                &NewDevice);
        if (!NT_SUCCESS(Status)) {
            AGPLOG(AGP_CRITICAL,("AgpAttachDeviceRelations: IoCreateDevice failed %08lx\n",Status));
            continue;
        }

        //
        // Initialize the device extension
        //

        NewExtension = NewDevice->DeviceExtension;
        NewExtension->CommonExtension.Deleted = FALSE;
        NewExtension->CommonExtension.Type = AgpMasterFilter;
        NewExtension->CommonExtension.Signature = MASTER_SIG;
        Status = ApQueryBusInterface(Relations->Objects[i], &NewExtension->CommonExtension.BusInterface);
        if (!NT_SUCCESS(Status)) {
            AGPLOG(AGP_CRITICAL,
                   ("AgpAttachDeviceRelations: query for bus interface failed %08lx\n", Status));
            IoDeleteDevice(NewDevice);
            continue;
        }
        NewExtension->Target = Extension;
        NewExtension->InterfaceCount = 0;
        NewExtension->ReservedPages = 0;
                                                // until we see the IRP_MN_START
        Extension->ChildDevice = NewExtension;

        //
        // Attach to the specified device
        //
        NewExtension->CommonExtension.AttachedDevice = IoAttachDeviceToDeviceStack(NewDevice, Relations->Objects[i]);
        if (NewExtension->CommonExtension.AttachedDevice == NULL) {
            //
            // The attach failed. Not really fatal, AGP just won't work for that device.
            //
            AGPLOG(AGP_CRITICAL,
                   ("AgpAttachDeviceRelations: IoAttachDeviceToDeviceStack from %p to %p failed\n",
                   NewDevice,
                   Relations->Objects[i]));
            RELEASE_BUS_INTERFACE(NewExtension);
            IoDeleteDevice(NewDevice);
            Extension->ChildDevice = NULL;
            continue;
        }

        //
        // Propagate the PDO's requirements
        //
        NewDevice->StackSize = NewExtension->CommonExtension.AttachedDevice->StackSize + 1;
        NewDevice->AlignmentRequirement = NewExtension->CommonExtension.AttachedDevice->AlignmentRequirement;
        if (NewExtension->CommonExtension.AttachedDevice->Flags & DO_POWER_PAGABLE) {
            NewDevice->Flags |= DO_POWER_PAGABLE;
        }

        //
        // Finally call the chipset-specific code for master initialization
        //
        routineContext.Gate = 1;
        routineContext.Barrier = 1;
        routineContext.Routine = (PCRITICALROUTINE)AgpInitializeMaster;
        routineContext.Extension = GET_AGP_CONTEXT(Extension);
        routineContext.Context = &NewExtension->Capabilities;
#if (WINVER < 0x502) || defined(AGP_DEBUG_MASTER_INIT)
        Status = AgpInitializeMaster(GET_AGP_CONTEXT(Extension),
                                     &NewExtension->Capabilities);
#else
        Status = (NTSTATUS)KeIpiGenericCall(AgpExecuteCriticalSystemRoutine,
                                            (ULONG_PTR)&routineContext
                                            );
#endif
        if (!NT_SUCCESS(Status)) {
            AGPLOG(AGP_CRITICAL,
                   ("AgpAttachDeviceRelations: AgpInitializeMaster on device %p failed %08lx\n",
                    NewDevice,
                    Status));
            IoDetachDevice(NewExtension->CommonExtension.AttachedDevice);
            RELEASE_BUS_INTERFACE(NewExtension);
            IoDeleteDevice(NewDevice);
            Extension->ChildDevice = NULL;
            continue;
        }

        //
        // Now that we're done at IPI-level, and we found our Master, let's
        // initialize the AGP Verifier
        //
        AgpVerifierInitialize(Extension);
        
        NewDevice->Flags &= ~DO_DEVICE_INITIALIZING;

//
// We can't do this if DBG because looping through here to catch/ASSERT
// multiple AGP masters will *always* incorrectly change our target context
//
#if 0
        //
        // Check to make sure there is only one AGP master on the bus. There can be more
        // than one device (multifunction device) but only one must have AGP capabilities
        //
        MasterCount++;
        ASSERT(MasterCount == 1);
#else
        break;
#endif

    }

    return(STATUS_SUCCESS);
}







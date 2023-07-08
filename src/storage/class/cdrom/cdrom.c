/*--

Copyright (C) Microsoft Corporation, 1991 - 1999

Module Name:

    cdrom.c

Abstract:

    The CDROM class driver tranlates IRPs to SRBs with embedded CDBs
    and sends them to its devices through the port driver.

Environment:

    kernel mode only

Notes:

    SCSI Tape, CDRom and Disk class drivers share common routines
    that can be found in the CLASS directory (..\ntos\dd\class).

Revision History:

--*/

#define DEBUG_MAIN_SOURCE   1
#include "stddef.h"
#include "string.h"

#include "ntddk.h"
#include "classpnp.h"
#include "ntddstor.h"
#include "cdrom.h"

#include "ntstrsafe.h"

#ifdef DEBUG_USE_WPP
#include "cdrom.tmh"
#endif

#ifdef ALLOC_PRAGMA

#pragma alloc_text(INIT, DriverEntry)

#pragma alloc_text(PAGE, CdRomUnload)
#pragma alloc_text(PAGE, CdRomAddDevice)
#pragma alloc_text(PAGE, CdRomCreateDeviceObject)
#pragma alloc_text(PAGE, CdRomStartDevice)
#pragma alloc_text(PAGE, ScanForSpecial)
#pragma alloc_text(PAGE, ScanForSpecialHandler)
#pragma alloc_text(PAGE, CdRomRemoveDevice)
#pragma alloc_text(PAGE, CdRomGetDeviceParameter)
#pragma alloc_text(PAGE, CdRomSetDeviceParameter)
#pragma alloc_text(PAGE, CdRomPickDvdRegion)
#pragma alloc_text(PAGE, CdRomIsPlayActive)
#pragma alloc_text(PAGE, CdRomInitDevice)
#pragma alloc_text(PAGE, CdRomSetRawReadInfo)

#pragma alloc_text(PAGEHITA, HitachiProcessError)
#pragma alloc_text(PAGEHIT2, HitachiProcessErrorGD2000)

#pragma alloc_text(PAGETOSH, ToshibaProcessErrorCompletion)
#pragma alloc_text(PAGETOSH, ToshibaProcessError)

#endif

// make a forced-inline function to get better checking and annotations
__forceinline BOOLEAN IS_READ_WRITE_REQUEST( __in IO_STACK_LOCATION const * irpStack )
{
    return ((irpStack->MajorFunction == IRP_MJ_READ)  ||
            (irpStack->MajorFunction == IRP_MJ_WRITE) ||
            ((irpStack->MajorFunction == IRP_MJ_DEVICE_CONTROL) &&
             (irpStack->Parameters.DeviceIoControl.IoControlCode == IOCTL_CDROM_RAW_READ)
             )
            );
}



NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    )

/*++

Routine Description:

    This routine initializes the cdrom class driver.

Arguments:

    DriverObject - Pointer to driver object created by system.

    RegistryPath - Pointer to the name of the services node for this driver.

Return Value:

    The function value is the final status from the initialization operation.

--*/

{
    CLASS_INIT_DATA InitializationData = {0};
    CLASS_INTERPRET_SENSE_INFO2 interpret2 = {0};
    CLASS_WORKING_SET workingSet = {0};

    PCDROM_DRIVER_EXTENSION driverExtension;
    NTSTATUS status;

    PAGED_CODE();

    WPP_INIT_TRACING(DriverObject, RegistryPath);

    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                "CDROM.SYS DriverObject %p loading\n", DriverObject));

    status = IoAllocateDriverObjectExtension(DriverObject,
                                             CDROM_DRIVER_EXTENSION_ID,
                                             sizeof(CDROM_DRIVER_EXTENSION),
                                             &driverExtension);

    if (!NT_SUCCESS(status)) {
        TracePrint((TRACE_LEVEL_FATAL, TRACE_FLAG_INIT,
                    "DriverEntry !! no DriverObjectExtension %x\n", status));
        return status;
    }

    //
    // always zero the memory, since we are now reloading the driver.
    //

    RtlZeroMemory(driverExtension, sizeof(CDROM_DRIVER_EXTENSION));

    //
    // Zero InitData
    //

    RtlZeroMemory (&InitializationData, sizeof(CLASS_INIT_DATA));

    //
    // Set sizes
    //

    InitializationData.InitializationDataSize = sizeof(CLASS_INIT_DATA);

    InitializationData.FdoData.DeviceExtensionSize = DEVICE_EXTENSION_SIZE;

    InitializationData.FdoData.DeviceType = FILE_DEVICE_CD_ROM;
    InitializationData.FdoData.DeviceCharacteristics =
        FILE_REMOVABLE_MEDIA | FILE_DEVICE_SECURE_OPEN;

    //
    // Set entry points
    //

    InitializationData.FdoData.ClassError = CdRomErrorHandler;
    InitializationData.FdoData.ClassInitDevice = CdRomInitDevice;
    InitializationData.FdoData.ClassStartDevice = CdRomStartDevice;
    InitializationData.FdoData.ClassStopDevice = CdRomStopDevice;
    InitializationData.FdoData.ClassRemoveDevice = CdRomRemoveDevice;

    InitializationData.FdoData.ClassReadWriteVerification = CdRomReadWriteVerification;
    InitializationData.FdoData.ClassDeviceControl = CdRomDeviceControlDispatch;

    InitializationData.FdoData.ClassPowerDevice = CdRomPowerHandler;
    InitializationData.FdoData.ClassShutdownFlush = CdRomShutdownFlush;
    InitializationData.FdoData.ClassCreateClose = CdRomCreateClose;

    InitializationData.ClassStartIo = CdRomStartIo;
    InitializationData.ClassAddDevice = CdRomAddDevice;

    InitializationData.ClassTick = CdRomTickHandler;
    InitializationData.ClassUnload = CdRomUnload;

    //
    // Call the class init routine
    //
    status = ClassInitialize( DriverObject, RegistryPath, &InitializationData);
    if (!NT_SUCCESS(status)) {
        TracePrint((TRACE_LEVEL_FATAL, TRACE_FLAG_INIT,
                    "DriverEntry !! Failed ClassInitialize %x\n",
                    status
                    ));
        return status;
    }

    //
    // CDROM serializes everything via StartIO, and doesn't support
    // multiple simultaneous split requests, so limit the number of
    // packets created by classpnp.
    //
    workingSet.Size = sizeof(CLASS_WORKING_SET);
    workingSet.XferPacketsWorkingSetMaximum = 3;
    workingSet.XferPacketsWorkingSetMinimum = 1;
    status = ClassInitializeEx(DriverObject, &ClassGuidWorkingSet, &workingSet);
    if (!NT_SUCCESS(status)) {
        TracePrint((TRACE_LEVEL_FATAL, TRACE_FLAG_INIT,
                    "DriverEntry !! Failed ClassInitializeEx (working set) %x\n",
                    status
                    ));
        return status;
    }

    //
    // Request use of the new InterpretSenseInfo functionality
    //

    interpret2.Size = sizeof(CLASS_INTERPRET_SENSE_INFO2);
    interpret2.HistoryCount                 = 3;
    interpret2.Compress                     = CompressSrbHistoryData;
    interpret2.Interpret                    = InterpretSenseInfo2;

    status = ClassInitializeEx(DriverObject, &ClassGuidSenseInfo2, &interpret2);
    if (!NT_SUCCESS(status)) {
        TracePrint((TRACE_LEVEL_FATAL, TRACE_FLAG_INIT,
                    "DriverEntry !! Failed ClassInitializeEx (history) %x\n",
                    status
                    ));
        return status;
    }

    return status;

} // end DriverEntry()


__control_entrypoint(DeviceDriver)
VOID
CdRomUnload(
    IN PDRIVER_OBJECT DriverObject
    )
{
    PAGED_CODE();
    UNREFERENCED_PARAMETER(DriverObject);
    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                "CDROM.SYS DriverObject %p unloading\n", DriverObject));
    WPP_CLEANUP(DriverObject);
    return;
} // end CdRomUnload()


__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomAddDevice(
    IN PDRIVER_OBJECT DriverObject,
    IN PDEVICE_OBJECT PhysicalDeviceObject
    )

/*++

Routine Description:

    This routine creates and initializes a new FDO for the corresponding
    PDO.  It may perform property queries on the FDO but cannot do any
    media access operations.

Arguments:

    DriverObject - CDROM class driver object.

    Pdo - the physical device object we are being added to

Return Value:

    status

--*/

{
    NTSTATUS status;

    PAGED_CODE();

    //
    // Get the address of the count of the number of cdroms already initialized.
    //

    status = CdRomCreateDeviceObject(DriverObject,
                                     PhysicalDeviceObject);

    //
    // Note: this always increments driver extension counter
    //       it will eventually wrap, and fail additions
    //       if an existing cdrom has the given number.
    //       so unlikely that we won't even bother considering
    //       this case, since the cure is quite likely worse
    //       than the symptoms.
    //

    if(NT_SUCCESS(status)) {

        //
        // keep track of the total number of active cdroms in IoGet(),
        // as some programs use this to determine when they have found
        // all the cdroms in the system.
        //

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_PNP, "CDROM.SYS Add succeeded\n"));
        IoGetConfigurationInformation()->CdRomCount++;

    } else {

        TracePrint((TRACE_LEVEL_FATAL, TRACE_FLAG_PNP,
                    "CDROM.SYS Add failed! %x\n", status));

    }

    return status;
}


NTSTATUS
CdRomCreateDeviceObject(
    IN PDRIVER_OBJECT DriverObject,
    IN PDEVICE_OBJECT PhysicalDeviceObject
    )

/*++

Routine Description:

    This routine creates an object for the device and then calls the
    SCSI port driver for media capacity and sector size.

Arguments:

    DriverObject - Pointer to driver object created by system.
    PortDeviceObject - to connect to SCSI port driver.
    DeviceCount - Number of previously installed CDROMs.
    PortCapabilities - Pointer to structure returned by SCSI port
        driver describing adapter capabilites (and limitations).
    LunInfo - Pointer to configuration information for this device.

Return Value:

    NTSTATUS

--*/
{
    UCHAR ntNameBuffer[64] = {0};
    STRING ntNameString = {0};
    NTSTATUS status;

    PDEVICE_OBJECT lowerDevice = NULL;
    PDEVICE_OBJECT deviceObject = NULL;
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = NULL;
    PCDROM_DATA cdData = NULL;
    PCDROM_DRIVER_EXTENSION driverExtension = NULL;
    ULONG deviceNumber;

    CCHAR                   dosNameBuffer[64] = {0};
    CCHAR                   deviceNameBuffer[64] = {0};
    STRING                  deviceNameString = {0};
    STRING                  dosString = {0};
    UNICODE_STRING          dosUnicodeString = {0};
    UNICODE_STRING          unicodeString = {0};

    PAGED_CODE();

    //
    // Claim the device. Note that any errors after this
    // will goto the generic handler, where the device will
    // be released.
    //

    lowerDevice = IoGetAttachedDeviceReference(PhysicalDeviceObject);

    status = ClassClaimDevice(lowerDevice, FALSE);

    if(!NT_SUCCESS(status)) {

        //
        // Someone already had this device - we're in trouble
        //

        ObDereferenceObject(lowerDevice);
        return status;
    }

    //
    // Create device object for this device by first getting a unique name
    // for the device and then creating it.
    //

    driverExtension = IoGetDriverObjectExtension(DriverObject,
                                                 CDROM_DRIVER_EXTENSION_ID);
    ASSERT(driverExtension != NULL);

    //
    // InterlockedCdRomCounter is biased by 1.
    //

    deviceNumber = InterlockedIncrement(&driverExtension->InterlockedCdRomCounter) - 1;
    status = RtlStringCchPrintfA(ntNameBuffer, RTL_NUMBER_OF(ntNameBuffer), "\\Device\\CdRom%d", deviceNumber);
    if (!NT_SUCCESS(status)) {
        TracePrint((TRACE_LEVEL_FATAL, TRACE_FLAG_PNP,
                    "CreateCdRomDeviceObjects: Format device name failed with error: 0x%X\n", status));
        goto CreateCdRomDeviceObjectExit;
    }


    status = ClassCreateDeviceObject(DriverObject,
                                     ntNameBuffer,
                                     PhysicalDeviceObject,
                                     TRUE,
                                     &deviceObject);

    if (!NT_SUCCESS(status)) {
        TracePrint((TRACE_LEVEL_FATAL, TRACE_FLAG_PNP,
                    "CreateCdRomDeviceObjects: Can not create device %s\n",
                    ntNameBuffer));

        goto CreateCdRomDeviceObjectExit;
    }

    //
    // NOTE: This must be called here because the storage stack
    //       ignores the fact that IO should not occur until the
    //       storage stack is actually _started_.  Sigh....
    //
    // since StartIo() will call IoStartNextPacket() on error, allowing
    // StartIo() to be non-recursive prevents stack overflow bugchecks in
    // severe error cases (such as fault-injection in the verifier).
    //
    // the only difference is that the thread context may be different
    // in StartIo() than in the caller of IoStartNextPacket().
    //
    IoSetStartIoAttributes(deviceObject, TRUE, TRUE);

    //
    // Indicate that IRPs should include MDLs.
    //

    SET_FLAG(deviceObject->Flags, DO_DIRECT_IO);

    fdoExtension = deviceObject->DeviceExtension;

    //
    // Back pointer to device object.
    //

    fdoExtension->CommonExtension.DeviceObject = deviceObject;

    //
    // This is the physical device.
    //

    fdoExtension->CommonExtension.PartitionZeroExtension = fdoExtension;

    //
    // Initialize lock count to zero. The lock count is used to
    // disable the ejection mechanism when media is mounted.
    //

    fdoExtension->LockCount = 0;

    //
    // Save system cdrom number
    //

    fdoExtension->DeviceNumber = deviceNumber;

    //
    // Set the alignment requirements for the device based on the
    // host adapter requirements
    //

    if (lowerDevice->AlignmentRequirement > deviceObject->AlignmentRequirement) {
        deviceObject->AlignmentRequirement = lowerDevice->AlignmentRequirement;
    }

    //
    // Save the device descriptors
    //

    fdoExtension->AdapterDescriptor = NULL;

    fdoExtension->DeviceDescriptor = NULL;

    //
    // Clear the SrbFlags and disable synchronous transfers
    //

    fdoExtension->SrbFlags = SRB_FLAGS_DISABLE_SYNCH_TRANSFER;

    //
    // Finally, attach to the PDO
    //

    fdoExtension->LowerPdo = PhysicalDeviceObject;

    fdoExtension->CommonExtension.LowerDeviceObject =
        IoAttachDeviceToDeviceStack(deviceObject, PhysicalDeviceObject);

    if(fdoExtension->CommonExtension.LowerDeviceObject == NULL) {

        //
        // Uh - oh, we couldn't attach
        // cleanup and return
        //

        status = STATUS_UNSUCCESSFUL;
        goto CreateCdRomDeviceObjectExit;
    }

    //
    // CdRom uses an extra stack location for synchronizing it's start io
    // routine
    //

    deviceObject->StackSize++;

    //
    // cdData is used a few times below
    //

    cdData = fdoExtension->CommonExtension.DriverData;

    //
    // For NTMS to be able to easily determine drives-drv. letter matches.
    //

    status = CdRomCreateWellKnownName( deviceObject );

    if (!NT_SUCCESS(status)) {
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_PNP,
                    "CdromCreateDeviceObjects: unable to create symbolic "
                    "link for device %wZ\n", &fdoExtension->CommonExtension.DeviceName));
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_PNP,
                    "CdromCreateDeviceObjects: (non-fatal error)\n"));
    }

    ClassUpdateInformationInRegistry(deviceObject, "CdRom",
                                     fdoExtension->DeviceNumber, NULL, 0);

    //
    // from above IoGetAttachedDeviceReference
    //

    ObDereferenceObject(lowerDevice);

    //
    // need to init timerlist here in case a remove occurs
    // without a start, since we check the list is empty on remove.
    //

    cdData->DelayedRetryIrp = NULL;
    cdData->DelayedRetryInterval = 0;

    cdData->UpdateCapacityIrp = NULL;

#ifdef ENABLE_RPC0
    //
    // need this to be initialized for RPC Phase 1 drives (rpc0)
    //

    KeInitializeMutex(&cdData->Rpc0RegionMutex, 0);
#endif // ENABLE_RPC0

    //
    // The device is initialized properly - mark it as such.
    //

    CLEAR_FLAG(deviceObject->Flags, DO_DEVICE_INITIALIZING);

    return(STATUS_SUCCESS);

CreateCdRomDeviceObjectExit:

    //
    // Release the device since an error occured.
    //

    // ClassClaimDevice(PortDeviceObject,
    //                      LunInfo,
    //                      TRUE,
    //                      NULL);

    //
    // from above IoGetAttachedDeviceReference
    //

    ObDereferenceObject(lowerDevice);

    if (deviceObject != NULL) {
        IoDeleteDevice(deviceObject);
    }

    return status;

} // end CreateCdRomDeviceObject()


__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomInitDevice(
    IN PDEVICE_OBJECT Fdo
    )

/*++

Routine Description:

    This routine will complete the cd-rom initialization.  This includes
    allocating sense info buffers and srb s-lists, reading drive capacity
    and setting up Media Change Notification (autorun).

    This routine will not clean up allocate resources if it fails - that
    is left for device stop/removal

Arguments:

    Fdo - a pointer to the functional device object for this device

Return Value:

    status

--*/

{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;

    PVOID senseData = NULL;

    ULONG timeOut;
    PCDROM_DATA cddata = (PCDROM_DATA)(commonExtension->DriverData);

    BOOLEAN changerDevice;
    BOOLEAN isMmcDevice = FALSE;
    BOOLEAN isAACS      = FALSE;
    BOOLEAN isDvdDevice = FALSE;
    BOOLEAN isWriterDrive = FALSE;

    ULONG bps;
    ULONG lastBit;


    NTSTATUS status = STATUS_SUCCESS;

    PAGED_CODE();

    //
    // Build the lookaside list for srb's for the physical disk.  Should only
    // need a couple.
    //

    ClassInitializeSrbLookasideList(&(fdoExtension->CommonExtension),
                                    CDROM_SRB_LIST_SIZE);

    //
    // Allocate request sense buffer.
    //

    senseData = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                      SENSE_BUFFER_SIZE,
                                      CDROM_TAG_SENSE_INFO);

    if (senseData == NULL) {

        //
        // The buffer cannot be allocated.
        //

        status = STATUS_INSUFFICIENT_RESOURCES;
        goto CdRomInitDeviceExit;
    }

    //
    // Set the sense data pointer in the device extension.
    //

    fdoExtension->SenseData = senseData;

    //
    // CDROMs are not partitionable so starting offset is 0.
    //

    commonExtension->StartingOffset.LowPart = 0;
    commonExtension->StartingOffset.HighPart = 0;

    //
    // Set timeout value in seconds.
    //

    timeOut = ClassQueryTimeOutRegistryValue(Fdo);
    if ((timeOut != 0) && (timeOut <= 30 * 60)) { // 30 minutes
        fdoExtension->TimeOutValue = timeOut;
    } else {
        fdoExtension->TimeOutValue = SCSI_CDROM_TIMEOUT;
    }

    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
              "Fdo %p timeout is set to %x seconds",
              Fdo,
              fdoExtension->TimeOutValue
              ));


    //
    // Set up media change support defaults.
    //

    KeInitializeSpinLock(&cddata->DelayedRetrySpinLock);

    cddata->DelayedRetryIrp = NULL;
    cddata->DelayedRetryInterval = 0;
    cddata->Mmc.WriteAllowed = FALSE;
    cddata->Mmc.IsWriter = FALSE;
    cddata->ReadWriteRetryDelay100nsUnits = WRITE_RETRY_DELAY_DVD_1x;


    //
    // Scan for  controllers that require special processing.
    //

    ScanForSpecial(Fdo);

    //
    // Determine the maximum page-aligned and non-page-aligned transfer
    // lengths here, so we needn't do this in common READ/WRITE code paths
    //
    {
        ULONG maxAlignedTransfer;
        ULONG maxUnalignedTransfer;

        //
        // start with the number of pages the adapter can support
        //
        maxAlignedTransfer = fdoExtension->AdapterDescriptor->MaximumPhysicalPages;
        maxUnalignedTransfer = fdoExtension->AdapterDescriptor->MaximumPhysicalPages;

        //
        // Unaligned buffers could cross a page boundary.
        //
        if (maxUnalignedTransfer > 1) {
            maxUnalignedTransfer--;
        }

        //
        // if we'd overflow multiplying by page size, just max out the
        // transfer length allowed by the number of pages limit.
        //
        if (maxAlignedTransfer >= (((ULONG)-1) / PAGE_SIZE)) {
            maxAlignedTransfer = (ULONG)-1;
        } else {
            maxAlignedTransfer *= PAGE_SIZE;
        }
        if (maxUnalignedTransfer >= (((ULONG)-1) / PAGE_SIZE)) {
            maxUnalignedTransfer = (ULONG)-1;
        } else {
            maxUnalignedTransfer *= PAGE_SIZE;
        }

        //
        // finally, take the smaller of the above and the adapter's
        // reported maximum number of bytes per transfer.
        //
        maxAlignedTransfer   = min(maxAlignedTransfer,   fdoExtension->AdapterDescriptor->MaximumTransferLength);
        maxUnalignedTransfer = min(maxUnalignedTransfer, fdoExtension->AdapterDescriptor->MaximumTransferLength);

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                  "FDO %p Max aligned/unaligned transfer size is %x/%x\n",
                  Fdo,
                  maxAlignedTransfer,
                  maxUnalignedTransfer
                  ));
        cddata->MaxPageAlignedTransferBytes = maxAlignedTransfer;
        cddata->MaxUnalignedTransferBytes = maxUnalignedTransfer;

    }

    //
    // Allocate scratch buffer -- Must occur after determining
    // max transfer size, but before other CD specific detection
    // (which relies upon this buffer).
    //
    if (!ScratchBuffer_Allocate(cddata, Fdo->StackSize+2))
    {
        status = STATUS_INSUFFICIENT_RESOURCES;
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                    "Failed to allocate scratch buffer, failing  %!STATUS!\n",
                    status
                    ));
        goto CdRomInitDeviceExit;
    }

    //
    // cache the device's inquiry data
    //
    status = CdRompCacheDeviceInquiryData(fdoExtension);
    if (!NT_SUCCESS(status)) {
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                    "Failed to cache the device's inquiry data, failng %!STATUS!\n",
                    status
                    ));
        goto CdRomInitDeviceExit;
    }

    //
    // Determine if the drive is MMC-Capable
    //

    CdRomIsDeviceMmcDevice(Fdo, &isMmcDevice, &isAACS, &isDvdDevice, &isWriterDrive);

#ifdef ENABLE_AACS_TESTING
    if (isMmcDevice)
    {
        isAACS = TRUE; // just force it true for testing
    }
#endif // ENABLE_AACS_TESTING

    if (!isMmcDevice) {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                  "Fdo %p Device is not an MMC compliant device, so setting to read-only (legacy) mode",
                  Fdo
                  ));
        SET_FLAG(Fdo->Characteristics, FILE_READ_ONLY_DEVICE);

    } else {

        //
        // the drive supports at least a subset of MMC commands
        // (and therefore supports READ_CD, etc...)
        //

        cddata->Mmc.IsMmc = TRUE;
        cddata->Mmc.IsAACS = isAACS;
        cddata->Mmc.IsWriter = isWriterDrive;

        //
        // allocate a buffer for all the capabilities and such
        //

        status = CdRomAllocateMmcResources(Fdo);
        if (!NT_SUCCESS(status)) {
            goto CdRomInitDeviceExit;
        }

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                  "FDO %p GET_CONFIGURATION buffer %p\n",
                  Fdo,
                  cddata->Mmc.CapabilitiesBuffer
                  ));

        //
        // Flag the StartIo routine to update its state and hook in the error handler
        //
        cddata->Mmc.UpdateState = CdromMmcUpdateRequired;
        cddata->ErrorHandler = CdRomMmcErrorHandler;

        SET_FLAG(fdoExtension->DeviceFlags, DEV_SAFE_START_UNIT);

        //
        // Read the CDROM mode sense page to get additional info for raw read
        // requests.
        //

        CdRomSetRawReadInfo(Fdo);

        //
        // Update the timeout value for devices which support GET_CONFIG
        //

        CdRomUpdateTimeoutValueForMmcDevice(Fdo);

    }

    //
    // Set the default geometry for the cdrom to match what NT 4 used.
    // Classpnp will use these values to compute the cylinder count rather
    // than using it's NT 5.0 defaults.
    //

    fdoExtension->DiskGeometry.TracksPerCylinder = 0x40;
    fdoExtension->DiskGeometry.SectorsPerTrack = 0x20;

    //
    // Do READ CAPACITY. This SCSI command returns the last sector address
    // on the device and the bytes per sector. These are used to calculate
    // the drive capacity in bytes.
    //
    // NOTE: This should be change to send the Srb synchronously, then
    // call CdRomInterpretReadCapacity() to properly setup the defaults.
    //

    status = ClassReadDriveCapacity(Fdo);

    bps = fdoExtension->DiskGeometry.BytesPerSector;

    if (!NT_SUCCESS(status) || !bps) {

        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                    "CdRomStartDevice: Can't read capacity for device %wZ\n",
                    &(fdoExtension->CommonExtension.DeviceName)));

        //
        // Set disk geometry to default values (per ISO 9660).
        //

        bps = 2048;
        fdoExtension->SectorShift = 11;
        commonExtension->PartitionLength.QuadPart = (LONGLONG)(0x7fffffff);

    } else {

        //
        // Insure that bytes per sector is a power of 2
        // This corrects a problem with the HP 4020i CDR where it
        // returns an incorrect number for bytes per sector.
        //

        lastBit = (ULONG) -1;
        while (bps) {
            lastBit++;
            bps = bps >> 1;
        }

        bps = 1 << lastBit;
    }
    fdoExtension->DiskGeometry.BytesPerSector = bps;
    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,  "CdRomInitDevice: Calc'd bps = %x\n", bps));


    ClassInitializeMediaChangeDetection(fdoExtension, "CdRom");
    
    //
    //set drive device type
    //

    if (isDvdDevice)
    {
        cddata->DriveDeviceType = FILE_DEVICE_DVD;
    }
    else
    {
        cddata->DriveDeviceType = FILE_DEVICE_CD_ROM;
    }

    //
    // test for audio read capabilities
    //

    if (cddata->DriveDeviceType == FILE_DEVICE_DVD) {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                    "CdRomInitDevice: DVD Devices require START_UNIT\n"));
        SET_FLAG(fdoExtension->DeviceFlags, DEV_SAFE_START_UNIT);

    } else if ((fdoExtension->DeviceDescriptor->BusType != BusTypeScsi)  &&
               (fdoExtension->DeviceDescriptor->BusType != BusTypeAta)   &&
               (fdoExtension->DeviceDescriptor->BusType != BusTypeAtapi) &&
               (fdoExtension->DeviceDescriptor->BusType != BusTypeUnknown)
               ) {

        //
        // devices on the newer busses require START_UNIT
        //

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                  "CdRomDetermineRawReadCapabilities: Devices for newer "
                  "busses require START_UNIT\n"));
        SET_FLAG(fdoExtension->DeviceFlags, DEV_SAFE_START_UNIT);

    }

    //
    // Register interfaces for this device.
    //

    {
        UNICODE_STRING interfaceName = {0};

        RtlInitUnicodeString(&interfaceName, NULL);

        status = IoRegisterDeviceInterface(fdoExtension->LowerPdo,
                                           (LPGUID) &CdRomClassGuid,
                                           NULL,
                                           &interfaceName);

        if(NT_SUCCESS(status)) {

            cddata->CdromInterfaceString = interfaceName;

            status = IoSetDeviceInterfaceState(
                        &interfaceName,
                        TRUE);

            if(!NT_SUCCESS(status)) {

                TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                            "CdromInitDevice: Unable to register cdrom "
                            "DCA for fdo %p [%lx]\n",
                            Fdo, status));
            }
        }
    }

    return(STATUS_SUCCESS);

CdRomInitDeviceExit:

    CdRomDeAllocateMmcResources(Fdo);
    ScratchBuffer_Deallocate(cddata);
    RtlZeroMemory(&(cddata->Mmc), sizeof(CDROM_MMC_EXTENSION));

    return status;

}


__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomStartDevice(
    IN PDEVICE_OBJECT Fdo
    )
/*++

Routine Description:

    This routine starts the timer for the cdrom

Arguments:

    Fdo - a pointer to the functional device object for this device

Return Value:

    status

--*/

{
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PCDROM_DATA cddata = (PCDROM_DATA)(commonExtension->DriverData);
    PDVD_COPY_PROTECT_KEY copyProtectKey;
    PDVD_RPC_KEY rpcKey;
    IO_STATUS_BLOCK ioStatus = {0};
    ULONG bufferLen;

#ifdef ENABLE_RPC0
    //
    // if we have a DVD-ROM
    //    if we have a rpc0 device
    //        fake a rpc2 device
    //    if device does not have a dvd region set
    //        select a dvd region for the user
    //

    cddata->DvdRpc0Device = FALSE;
#endif // ENABLE_RPC0

    //
    // check to see if we have a DVD device
    //

    if (cddata->DriveDeviceType != FILE_DEVICE_DVD) {
        return STATUS_SUCCESS;
    }

    //
    // we got a DVD drive.
#ifdef ENABLE_RPC0
    // now, figure out if we have a RPC0 device
#endif // ENABLE_RPC0
    //

    bufferLen = DVD_RPC_KEY_LENGTH;
    copyProtectKey =
        (PDVD_COPY_PROTECT_KEY)ExAllocatePoolWithTag(PagedPool,
                                                     bufferLen,
                                                     DVD_TAG_RPC2_CHECK);

    if (copyProtectKey == NULL) {
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    //
    // get the device region
    //
    RtlZeroMemory (copyProtectKey, bufferLen);
    copyProtectKey->KeyLength = DVD_RPC_KEY_LENGTH;
    copyProtectKey->KeyType = DvdGetRpcKey;

    //
    // Build a request for READ_KEY
    //
    ClassSendDeviceIoControlSynchronous(
        IOCTL_DVD_READ_KEY,
        Fdo,
        copyProtectKey,
        DVD_RPC_KEY_LENGTH,
        DVD_RPC_KEY_LENGTH,
        FALSE,
        &ioStatus
        );

#ifdef ENABLE_RPC0
    if (!NT_SUCCESS(ioStatus.Status)) {

        ASSERTMSG("Found RPC0 device\n", FALSE);
        //
        // we have a rpc0 device
        //
        // NOTE: THIS MODIFIES THE BEHAVIOR OF THE IOCTL
        //

        cddata->DvdRpc0Device = TRUE;

        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_PNP,
                    "CdromStartDevice (%p): RPC Phase 1 drive detected\n",
                    Fdo));

        //
        // note: we could force this chosen now, but it's better to reduce
        // the number of code paths that could be taken.  always delay to
        // increase the percentage code coverage.
        //

        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_PNP,
                  "CdromStartDevice (%p): Delay DVD Region Selection\n",
                  Fdo));

        cddata->Rpc0SystemRegion           = 0xff;
        cddata->Rpc0SystemRegionResetCount = DVD_MAX_REGION_RESET_COUNT;
        cddata->PickDvdRegion              = 1;
        cddata->Rpc0RetryRegistryCallback  = 1;
        ExFreePool(copyProtectKey);
        return STATUS_SUCCESS;

    } else {
#else  // !ENABLE_RPC0
    if (NT_SUCCESS(ioStatus.Status)) {
#endif // ENABLE_RPC0

        rpcKey = (PDVD_RPC_KEY) copyProtectKey->KeyData;

        //
        // TypeCode of zero means that no region has been set.
        //

        if (rpcKey->TypeCode == 0) {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_PNP,
                        "CdromStartDevice (%p): must choose DVD region\n",
                        Fdo));
            cddata->PickDvdRegion = 1;
            CdRomPickDvdRegion(Fdo);
        }
    }

    ExFreePool (copyProtectKey);

    return STATUS_SUCCESS;
}


__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomStopDevice(
    IN PDEVICE_OBJECT DeviceObject,
    IN UCHAR Type
    )
{
    return STATUS_SUCCESS;
}


__control_entrypoint(DeviceDriver)
VOID
CdRomStartIo(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP Irp
    )
{

    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PIO_STACK_LOCATION  currentIrpStack = IoGetCurrentIrpStackLocation(Irp);
    PIO_STACK_LOCATION  nextIrpStack = IoGetNextIrpStackLocation(Irp);
    PIO_STACK_LOCATION  irpStack;
    PIRP                irp2 = NULL;
    ULONG               transferPages;
    ULONG               transferByteCount = currentIrpStack->Parameters.Read.Length;
    LARGE_INTEGER       startingOffset = currentIrpStack->Parameters.Read.ByteOffset;
    PCDROM_DATA         cdData;
    PSCSI_REQUEST_BLOCK srb = NULL;
    PCDB                cdb;
    PUCHAR              senseBuffer = NULL;
    PVOID               dataBuffer;
    NTSTATUS            status;
    KIRQL oldIrql;


    IoMarkIrpPending(Irp);

    cdData = (PCDROM_DATA)(fdoExtension->CommonExtension.DriverData);

    //
    // First things first -- check if the IRP was cancelled and complete here if so
    // this ensures that classpnp-sent irps (read/write) will get a reasonable
    // chance for cancellation.
    //

    if (Irp->Cancel)
    {
        Irp->IoStatus.Status = STATUS_CANCELLED;
        Irp->IoStatus.Information = 0;
        CdRomCompleteIrpAndStartNextPacketSafely(Fdo,Irp);
        return;
    }

    //
    // If the device is in exclusive mode, check whether the request is from
    // the handle that locked the device.
    //

    if (EXCLUSIVE_MODE(cdData) && !EXCLUSIVE_OWNER(cdData, currentIrpStack->FileObject)) {

        //
        // Request is not from exclusive owner, check whether this is a storage request.
        // Only non storage requests can be processed.
        //

        if ( (currentIrpStack->MajorFunction == IRP_MJ_DEVICE_CONTROL) &&
             (CdRomIsBlockedStorageIoctl(Irp) == TRUE) ) {
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "CdRomStartIo: Access Denied! Device in exclusive mode.\n"));

            Irp->IoStatus.Information = 0;
            Irp->IoStatus.Status = STATUS_ACCESS_DENIED;
            CdRomCompleteIrpAndStartNextPacketSafely(Fdo,Irp);
            return;
        }
    }

    //
    // If this is a write request and writes are currently
    // not allowed then set the mmc state to update required.
    //

    if ((cdData->Mmc.WriteAllowed == FALSE) &&
        ((currentIrpStack->MajorFunction == IRP_MJ_WRITE) ||
         ((currentIrpStack->MajorFunction == IRP_MJ_DEVICE_CONTROL) &&
          ((currentIrpStack->Parameters.DeviceIoControl.IoControlCode == IOCTL_DISK_IS_WRITABLE) ||
           (currentIrpStack->Parameters.DeviceIoControl.IoControlCode == IOCTL_DISK_VERIFY))))) {

        //
        // The MMC update function queues and retries the requests in
        // CdRompFlushDelayedList. The request will be retried in infinite loop
        // if the write state is not changed. Set Argument3 to indicate that this
        // request is triggering MMC update. When the IRP is retried, do not
        // trigger update. This will let the request fall thru and appropriate
        // action will be taken by the request handler.
        //

        if (!(nextIrpStack->Parameters.Others.Argument3)) {

            nextIrpStack->Parameters.Others.Argument3 =  (PVOID) 1;
            InterlockedCompareExchange(&(cdData->Mmc.UpdateState),
                                   CdromMmcUpdateRequired,
                                   CdromMmcUpdateComplete);

            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_RW,
                       "CdRomStartIo: Received request that requires write access [%p]. Update MMC capabilities.\n",
                       Irp));
        } else {

            nextIrpStack->Parameters.Others.Argument3 =  (PVOID) 0;
        }
    }

    //
    // if this test is true, then we will exit the routine within this
    // code block, queueing the irp for later completion.
    //

    if ((cdData->Mmc.IsMmc) &&
        (cdData->Mmc.UpdateState != CdromMmcUpdateComplete)
        ) {

        ULONG queueDepth;
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_RW,
                   "CdRomStartIo: [%p] Device needs to update capabilities\n",
                   Irp));
        ASSERT(cdData->Mmc.IsMmc);
        ASSERT(cdData->Mmc.CapabilitiesIrp != NULL);
        ASSERT(cdData->Mmc.CapabilitiesIrp != Irp);

        //
        // NOTE - REF #0002
        //
        // the state was either UpdateRequired (which means we will
        // have to start the work item) or UpdateStarted (which means
        // we have already started the work item at least once -- may
        // transparently change to UpdateComplete).
        //
        // if it's update required, we just queue it, change to UpdateStarted,
        // start the workitem, and start the next packet.
        //
        // else, we must queue the item and check the queue depth.  if the
        // queue depth is equal to 1, that means the worker item from the
        // previous attempt has already de-queued the items, so we should
        // call this routine again (retry) as an optimization rather than
        // re-add it this irp to the queue.  since this is tail recursion,
        // it won't take much/any stack to do this.
        //
        // NOTE: This presumes the following items are true:
        //
        // we only add to the list from CdRomStartIo(), which is serialized.
        // we only set to UpdateStarted from CdRomStartIo(), and only if
        //    the state was UpdateRequired.
        // we only set to UpdateRequired from CdRomMmcErrorHandler(), and
        //    only if the state was UpdateComplete.
        // we only set to UpdateComplete from the workitem, and assert the
        //    state was UpdateStarted.
        // we flush the entire queue in one atomic operation in the workitem,
        //    except in the special case described above when we dequeue
        //    the request immediately.
        //
        // order of operations is vitally important: queue, then test the depth
        // this will prevent lost irps.
        //

        KeAcquireSpinLock(&cdData->Mmc.DelayedIrpsLock, &oldIrql);
        InsertTailList(&cdData->Mmc.DelayedIrpsList, &Irp->Tail.Overlay.ListEntry);
        queueDepth = ++cdData->Mmc.NumDelayedIrps;
        KeReleaseSpinLock(&cdData->Mmc.DelayedIrpsLock, oldIrql);

        if (queueDepth == 1) {

            if (cdData->Mmc.UpdateState == CdromMmcUpdateRequired) {
                LONG oldState;

                //
                // should free any old partition list info that
                // we've previously saved away and then start the WorkItem
                //

                oldState = InterlockedExchange(&cdData->Mmc.UpdateState,
                                               CdromMmcUpdateStarted);
                ASSERT(oldState == CdromMmcUpdateRequired);

                IoQueueWorkItem(cdData->Mmc.CapabilitiesWorkItem,
                                CdRomUpdateMmcDriveCapabilities,
                                DelayedWorkQueue,
                                NULL);

            } else {

                //
                // they *just* finished updating, so we should flush the list
                // back onto the StartIo queue and start the next packet.
                //

                CdRompFlushDelayedList(Fdo, &(cdData->Mmc), STATUS_SUCCESS, FALSE);

            }

        }

        //
        // start the next packet so we don't deadlock....
        //

        IoStartNextPacket(Fdo, TRUE);
        return;

    }

    //
    // If this is an attempt to synchronize the IOCTL, complete it immediately
    // IRP_MJ_SET_EA was used because only one ULONG can be set by user-mode apps
    // (if at all) for this IOCTL, preventing attacks which "guess" cdrom's
    // magic number.  The completion routine will set the event without calling
    // IoStartNextPacket().
    //

    if ((currentIrpStack->MajorFunction == IRP_MJ_SET_EA) &&
        (currentIrpStack->Parameters.Others.Argument1 == CdRomSynchronizeIoctlWithStartIo) &&
        (currentIrpStack->Parameters.Others.Argument2 == CdRomSynchronizeIoctlWithStartIo) &&
        (currentIrpStack->Parameters.Others.Argument3 == CdRomSynchronizeIoctlWithStartIo) &&
        (currentIrpStack->Parameters.Others.Argument4 == CdRomSynchronizeIoctlWithStartIo) )
    {
        TracePrint((TRACE_LEVEL_FATAL, TRACE_FLAG_IOCTL, "CdRomStartIo: Serialized with passive-level IOCTL for Irp \n"));
        Irp->IoStatus.Status = STATUS_SUCCESS;
        Irp->IoStatus.Information = 0;
        ClassReleaseRemoveLock(Fdo, Irp); // caller must have temporary remove lock held
        ClassCompleteRequest(Fdo, Irp, IO_CD_ROM_INCREMENT);
        return;
    }

    //
    // If the flag is set in the device object
    // force a verify for READ, WRITE and RAW_READ requests
    // Note that ioctls are passed through....
    //

    if (TEST_FLAG(Fdo->Flags, DO_VERIFY_VOLUME) &&
        IS_READ_WRITE_REQUEST(currentIrpStack)) {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_RW,
                    "CdRomStartIo: [%p] Volume needs verified\n", Irp));

        if (!(currentIrpStack->Flags & SL_OVERRIDE_VERIFY_VOLUME)) {

            if (Irp->Tail.Overlay.Thread) {
                IoSetHardErrorOrVerifyDevice(Irp, Fdo);
            }

            Irp->IoStatus.Status = STATUS_VERIFY_REQUIRED;

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_RW,
                        "CdRomStartIo: [%p] Calling UpdateCapcity - "
                        "ioctl event = %p\n",
                        Irp,
                        nextIrpStack->Parameters.Others.Argument1
                      ));

            //
            // our device control dispatch routine stores an event in the next
            // stack location to signal when startio has completed.  We need to
            // pass this in so that the update capacity completion routine can
            // set it rather than completing the Irp.
            //

            status = CdRomUpdateCapacity(fdoExtension,
                                         Irp,
                                         nextIrpStack->Parameters.Others.Argument1
                                         );

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_RW,
                        "CdRomStartIo: [%p] UpdateCapacity returned %lx\n",
                        Irp, status));
            return;
        }
    }

    if (currentIrpStack->MajorFunction == IRP_MJ_READ ||
        currentIrpStack->MajorFunction == IRP_MJ_WRITE ) {

        ULONG maximumTransferLength = fdoExtension->AdapterDescriptor->MaximumTransferLength;
        BOOLEAN isValid = TRUE;

        if (!fdoExtension->DiskGeometry.BytesPerSector) {
            fdoExtension->DiskGeometry.BytesPerSector = 2048;
        }

        if (!fdoExtension->SectorShift) {
            fdoExtension->SectorShift = 11;
        }

        //
        // Perform some basic validation up front
        //
        if (TEST_FLAG(startingOffset.QuadPart, fdoExtension->DiskGeometry.BytesPerSector - 1) ||
            TEST_FLAG(transferByteCount,       fdoExtension->DiskGeometry.BytesPerSector - 1)) {
            isValid = FALSE;
        }

        //
        // validate the request against the current mmc schema
        //
        {
            FEATURE_NUMBER schema = cdData->Mmc.ValidationSchema;
            //
            // We validate read requests according to the RandomWritable schema, except in the
            // case of IncrementalStreamingWritable, wherein  the drive is responsible for all
            // of the verification
            //
            if (currentIrpStack->MajorFunction == IRP_MJ_READ) {
    
                if (!cdData->Mmc.WriteAllowed) {
    
                    //
                    // standard legacy validation of read irps
                    // if writing is not allowed on the media
                    //
                    schema =  FeatureRandomWritable;
    
                } else if (schema != FeatureIncrementalStreamingWritable) {
    
                    //
                    // standard legacy validation of read irps
                    // if not using streaming writes on writable media
                    //
                    schema =  FeatureRandomWritable;
    
                }
            }
    
            //
            // Fail write requests to read-only media
            //
            if (currentIrpStack->MajorFunction == IRP_MJ_WRITE && !(cdData->Mmc.WriteAllowed)) {
    
                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_RW,  "CdRomStartIo: Write request to read-only media\n"));
                isValid = FALSE;
            }
    
            //
            // Validate the request according to the chosen schema
            //
            if (isValid) {
    
                switch (schema) {
    
                    case FeatureDefectManagement:
                    case FeatureRandomWritable:
                        //
                        // Ensure that the request is within bounds for ROM drives.
                        // Writer drives do not need to have bounds as outbounds request should not damage the drive.
                        //
                        if(!cdData->Mmc.IsWriter)
                        {
                            if (startingOffset.QuadPart >= commonExtension->PartitionLength.QuadPart ||
                                startingOffset.QuadPart < 0) {
        
                                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_RW,  "CdRomStartIo: Request is out of bounds\n"));
                                isValid = FALSE;
        
                            } else {
        
                                ULONGLONG bytesRemaining = commonExtension->PartitionLength.QuadPart - startingOffset.QuadPart;
        
                                if ((ULONGLONG)transferByteCount > bytesRemaining) {
        
                                    TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_RW,  "CdRomStartIo: Request is out of bounds\n"));
                                    isValid = FALSE;
                                }
                            }
                        }
                        break;
    
                    case FeatureRigidRestrictedOverwrite:
                        //
                        // Ensure that the number of blocks is a multiple of the blocking size
                        //
                        if (((transferByteCount >> fdoExtension->SectorShift) % cdData->Mmc.Blocking) != 0) {
    
                            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_RW,  "CdRomStartIo: Number of blocks is not a multiple of the blocking size (%x)\n", cdData->Mmc.Blocking));
                            isValid = FALSE;
                        }
    
                        //
                        // Fall through
                        //
    
                    case FeatureRestrictedOverwrite:
                        //
                        // Ensure that the request begins on a blocking boundary
                        //
                        if ((Int64ShrlMod32(startingOffset.QuadPart, fdoExtension->SectorShift) % cdData->Mmc.Blocking) != 0) {
    
                            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_RW,  "CdRomStartIo: Starting block is not a multiple of the blocking size (%x)\n", cdData->Mmc.Blocking));
                            isValid = FALSE;
                        }
                        break;
    
                    case FeatureIncrementalStreamingWritable:
                        //
                        // Let the drive handle the verification
                        //
                        break;
    
                    default:
                        //
                        // Unknown schema. Fail the request
                        //
                        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_RW,  "CdRomStartIo: Unknown validation schema (%x)\n", schema));
                        isValid = FALSE;
                        break;
                }
            }
        } // end of mmc schema validation

        if (!isValid) {

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_RW,
                        "CdRomStartIo: [%p] Device %p failing invalid Io request\n",
                        Irp, Fdo));

            Irp->IoStatus.Information = 0;
            Irp->IoStatus.Status = STATUS_INVALID_DEVICE_REQUEST;
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_RW, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
            CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
            return;
        }

        //
        // Add partition byte offset to make starting byte relative to
        // beginning of disk.
        //

        currentIrpStack->Parameters.Read.ByteOffset.QuadPart +=
            (fdoExtension->CommonExtension.StartingOffset.QuadPart);

        ClassSplitRequest(Fdo, Irp, maximumTransferLength);
        return;

    } else if (currentIrpStack->MajorFunction == IRP_MJ_DEVICE_CONTROL) {

        //
        // Allocate an irp, srb and associated structures.
        //

        irp2 = IoAllocateIrp((CCHAR)(Fdo->StackSize+1),
                              FALSE);

        if (!irp2) {
            Irp->IoStatus.Information = 0;
            Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
            CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
            return;
        }

        srb = ExAllocatePoolWithTag(NonPagedPool,
                                    sizeof(SCSI_REQUEST_BLOCK),
                                    CDROM_TAG_SRB);
        if (!srb) {
            IoFreeIrp(irp2);
            Irp->IoStatus.Information = 0;
            Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
            CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
            return;
        }

        RtlZeroMemory(srb, sizeof(SCSI_REQUEST_BLOCK));

        cdb = (PCDB)srb->Cdb;

        //
        // Allocate sense buffer.
        //

        senseBuffer = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                            SENSE_BUFFER_SIZE,
                                            CDROM_TAG_SENSE_INFO);

        if (!senseBuffer) {
            ExFreePool(srb);
            IoFreeIrp(irp2);
            Irp->IoStatus.Information = 0;
            Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
            CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
            return;
        }

        RtlZeroMemory(senseBuffer, SENSE_BUFFER_SIZE);

        //
        // Set up the irp.
        //

        IoSetNextIrpStackLocation(irp2);
        irp2->IoStatus.Status = STATUS_SUCCESS;
        irp2->IoStatus.Information = 0;
        irp2->Flags = 0;
        irp2->UserBuffer = NULL;

        //
        // Save the device object and irp in a private stack location.
        //

        irpStack = IoGetCurrentIrpStackLocation(irp2);
        irpStack->DeviceObject = Fdo;
        irpStack->Parameters.Others.Argument2 = (PVOID) Irp;

        //
        // The retry count will be in the real Irp, as the retry logic will
        // recreate our private irp.
        //

        if (!(nextIrpStack->Parameters.Others.Argument1)) {

            //
            // Only jam this in if it doesn't exist. The completion routines can
            // call StartIo directly in the case of retries and resetting it will
            // cause infinite loops.
            //

            nextIrpStack->Parameters.Others.Argument1 = (PVOID) MAXIMUM_RETRIES;
        }

        //
        // keep track of the new irp as Argument3
        //

        nextIrpStack->Parameters.Others.Argument3 = irp2;


        //
        // Construct the IRP stack for the lower level driver.
        //

        irpStack = IoGetNextIrpStackLocation(irp2);
        irpStack->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;
        irpStack->Parameters.DeviceIoControl.IoControlCode = IOCTL_SCSI_EXECUTE_IN;
        irpStack->Parameters.Scsi.Srb = srb;

        IoSetCompletionRoutine(irp2,
                               CdRomDeviceControlCompletion,
                               srb,
                               TRUE,
                               TRUE,
                               TRUE);
        //
        // Setup those fields that are generic to all requests.
        //

        srb->Length = SCSI_REQUEST_BLOCK_SIZE;
        srb->Function = SRB_FUNCTION_EXECUTE_SCSI;
        srb->SrbStatus = srb->ScsiStatus = 0;
        srb->NextSrb = 0;
        srb->OriginalRequest = irp2;
        srb->SenseInfoBufferLength = SENSE_BUFFER_SIZE;
        srb->SenseInfoBuffer = senseBuffer;

        if ((currentIrpStack->Parameters.DeviceIoControl.IoControlCode & 3) == METHOD_BUFFERED){
            /*
             *  The kernel allocated the output buffer for us and did not initialize it.
             *  We may not return the entire read length, so zero out the return buffer in order to avoid
             *  returning part of an uninitialized kernel buffer.
             */
            if (currentIrpStack->Parameters.DeviceIoControl.OutputBufferLength > currentIrpStack->Parameters.DeviceIoControl.InputBufferLength){
                RtlZeroMemory((PUCHAR)Irp->AssociatedIrp.SystemBuffer+currentIrpStack->Parameters.DeviceIoControl.InputBufferLength,
                                        currentIrpStack->Parameters.DeviceIoControl.OutputBufferLength-currentIrpStack->Parameters.DeviceIoControl.InputBufferLength);
            }
        }


        switch (currentIrpStack->Parameters.DeviceIoControl.IoControlCode) {


        case IOCTL_CDROM_RAW_READ: {
            //
            // Determine whether the drive is currently in raw or cooked mode,
            // and which command to use to read the data.
            //
            RAW_READ_INFO rawReadInfo;
            PVOID outputVirtAddr = NULL;
            ULONG  startingSector;

            //
            // Since this ioctl is METHOD_OUT_DIRECT, we need to copy away
            // the input buffer before interpreting it.  This prevents a
            // malicious app from messing with the input buffer while we
            // are interpreting it.
            //
            rawReadInfo = *(PRAW_READ_INFO)currentIrpStack->Parameters.DeviceIoControl.Type3InputBuffer;

            if (currentIrpStack->Parameters.DeviceIoControl.OutputBufferLength){

                //
                // Make sure that any user buffer that we pass down to
                // the hardware is properly aligned
                //
                ASSERT(Irp->MdlAddress);
                outputVirtAddr = MmGetMdlVirtualAddress(Irp->MdlAddress);
                if ((ULONG_PTR)outputVirtAddr & fdoExtension->AdapterDescriptor->AlignmentMask){
                    ASSERT(!((ULONG_PTR)outputVirtAddr & fdoExtension->AdapterDescriptor->AlignmentMask));
                    ExFreePool(senseBuffer);
                    ExFreePool(srb);
                    IoFreeIrp(irp2);
                    Irp->IoStatus.Information = 0;
                    Irp->IoStatus.Status = STATUS_INVALID_PARAMETER;
                    TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                    CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                    return;
                }
            }


                //
                // Free the recently allocated irp, as we don't need it.
                //

                IoFreeIrp(irp2);

                cdb = (PCDB)srb->Cdb;
                RtlZeroMemory(cdb, CDB12GENERIC_LENGTH);

                //
                // Setup cdb depending upon the sector type we want.
                //

                switch (rawReadInfo.TrackMode) {
                case CDDA:
                    transferByteCount  = rawReadInfo.SectorCount * RAW_SECTOR_SIZE;
                    cdb->READ_CD.ExpectedSectorType = CD_DA_SECTOR;
                    cdb->READ_CD.IncludeUserData = 1;
                    cdb->READ_CD.HeaderCode = 3;
                    cdb->READ_CD.IncludeSyncData = 1;
                    break;

                case YellowMode2:
                    transferByteCount  = rawReadInfo.SectorCount * RAW_SECTOR_SIZE;
                    cdb->READ_CD.ExpectedSectorType = YELLOW_MODE2_SECTOR;
                    cdb->READ_CD.IncludeUserData = 1;
                    cdb->READ_CD.HeaderCode = 1;
                    cdb->READ_CD.IncludeSyncData = 1;
                    break;

                case XAForm2:
                    transferByteCount  = rawReadInfo.SectorCount * RAW_SECTOR_SIZE;
                    cdb->READ_CD.ExpectedSectorType = FORM2_MODE2_SECTOR;
                    cdb->READ_CD.IncludeUserData = 1;
                    cdb->READ_CD.HeaderCode = 3;
                    cdb->READ_CD.IncludeSyncData = 1;
                    break;

                case RawWithC2AndSubCode:
                    if (!cdData->Mmc.ReadCdC2Pointers ||
                        !cdData->Mmc.ReadCdSubCode) {

                        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                                  "Request to read C2 & Subcode rejected.  "
                                  "Is C2 supported: %d   Is Subcode supported: %d\n",
                                  cdData->Mmc.ReadCdC2Pointers,
                                  cdData->Mmc.ReadCdSubCode
                                  ));

                        ExFreePool(senseBuffer);
                        ExFreePool(srb);
                        Irp->IoStatus.Information = 0;
                        Irp->IoStatus.Status = STATUS_INVALID_DEVICE_REQUEST;

                        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                        CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                        return;
                    }

                    transferByteCount  = rawReadInfo.SectorCount * CD_RAW_SECTOR_WITH_C2_AND_SUBCODE_SIZE;
                    cdb->READ_CD.ExpectedSectorType = 0;    // Any sector type
                    cdb->READ_CD.IncludeUserData = 1;
                    cdb->READ_CD.HeaderCode = 3;            // Header and subheader returned
                    cdb->READ_CD.IncludeSyncData = 1;
                    cdb->READ_CD.ErrorFlags = 2;            // C2 and block error
                    cdb->READ_CD.SubChannelSelection = 1;   // raw subchannel data
                    break;

                case RawWithC2:
                    if (!cdData->Mmc.ReadCdC2Pointers) {

                        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                                  "Request to read C2 rejected because drive does not "
                                  "report support for C2 pointers\n"
                                  ));

                        ExFreePool(senseBuffer);
                        ExFreePool(srb);
                        Irp->IoStatus.Information = 0;
                        Irp->IoStatus.Status = STATUS_INVALID_DEVICE_REQUEST;

                        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                        CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                        return;
                    }

                    transferByteCount  = rawReadInfo.SectorCount * CD_RAW_SECTOR_WITH_C2_SIZE;
                    cdb->READ_CD.ExpectedSectorType = 0;    // Any sector type
                    cdb->READ_CD.IncludeUserData = 1;
                    cdb->READ_CD.HeaderCode = 3;            // Header and subheader returned
                    cdb->READ_CD.IncludeSyncData = 1;
                    cdb->READ_CD.ErrorFlags = 2;            // C2 and block error
                    break;

                case RawWithSubCode:

                    if (!cdData->Mmc.ReadCdSubCode) {

                        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                                  "Request to read subcode rejected because drive does "
                                  "not report support for reading the subcode data\n"
                                  ));
                        ExFreePool(senseBuffer);
                        ExFreePool(srb);
                        Irp->IoStatus.Information = 0;
                        Irp->IoStatus.Status = STATUS_INVALID_DEVICE_REQUEST;

                        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                        CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                        return;
                    }

                    transferByteCount  = rawReadInfo.SectorCount * CD_RAW_SECTOR_WITH_SUBCODE_SIZE;
                    cdb->READ_CD.ExpectedSectorType = 0;    // Any sector type
                    cdb->READ_CD.IncludeUserData = 1;
                    cdb->READ_CD.HeaderCode = 3;            // Header and subheader returned
                    cdb->READ_CD.IncludeSyncData = 1;
                    cdb->READ_CD.SubChannelSelection = 1;   // raw subchannel data
                    break;

                default:
                    ExFreePool(senseBuffer);
                    ExFreePool(srb);
                    Irp->IoStatus.Information = 0;
                    Irp->IoStatus.Status = STATUS_INVALID_PARAMETER;

                    TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                    CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                    return;
                }

                //
                // Calculate starting offset.
                //

                startingSector = (ULONG)(rawReadInfo.DiskOffset.QuadPart >> fdoExtension->SectorShift);

                srb->OriginalRequest = Irp;
                srb->SrbFlags = fdoExtension->SrbFlags;
                SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
                SET_FLAG(srb->SrbFlags, SRB_FLAGS_DATA_IN);
                srb->DataTransferLength = transferByteCount;
                srb->TimeOutValue = fdoExtension->TimeOutValue;
                srb->DataBuffer = outputVirtAddr;
                srb->CdbLength = 12;
                srb->SrbStatus = srb->ScsiStatus = 0;

                //
                // Fill in CDB fields.
                //

                cdb->READ_CD.OperationCode = SCSIOP_READ_CD;
                cdb->READ_CD.TransferBlocks[2]  = (UCHAR) (rawReadInfo.SectorCount & 0xFF);
                cdb->READ_CD.TransferBlocks[1]  = (UCHAR) (rawReadInfo.SectorCount >> 8 );
                cdb->READ_CD.TransferBlocks[0]  = (UCHAR) (rawReadInfo.SectorCount >> 16);


                cdb->READ_CD.StartingLBA[3]  = (UCHAR) (startingSector & 0xFF);
                cdb->READ_CD.StartingLBA[2]  = (UCHAR) ((startingSector >>  8));
                cdb->READ_CD.StartingLBA[1]  = (UCHAR) ((startingSector >> 16));
                cdb->READ_CD.StartingLBA[0]  = (UCHAR) ((startingSector >> 24));


                nextIrpStack->MajorFunction = IRP_MJ_SCSI;
                nextIrpStack->Parameters.Scsi.Srb = srb;

                // HACKHACK - REF #0001

                //
                // Set up IoCompletion routine address.
                //

                IoSetCompletionRoutine(Irp,
                                       CdRomXACompletion,
                                       srb,
                                       TRUE,
                                       TRUE,
                                       TRUE);

                IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, Irp);
                return;
        }

        //
        // the _EX version does the same thing on the front end
        //

        case IOCTL_DISK_GET_LENGTH_INFO:
        case IOCTL_DISK_GET_DRIVE_GEOMETRY_EX:
        case IOCTL_DISK_GET_DRIVE_GEOMETRY:
        case IOCTL_CDROM_GET_DRIVE_GEOMETRY_EX:
        case IOCTL_CDROM_GET_DRIVE_GEOMETRY: {

            //
            // Issue ReadCapacity to update device extension
            // with information for current media.
            //

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "CdRomStartIo: Get drive geometry/length "
                        "info (%p)\n", Irp));

            //
            // setup remaining srb and cdb parameters.
            //

            srb->SrbFlags = fdoExtension->SrbFlags;
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DATA_IN);
            srb->DataTransferLength = sizeof(READ_CAPACITY_DATA);
            srb->CdbLength = 10;
            srb->TimeOutValue = fdoExtension->TimeOutValue;

            dataBuffer = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                               sizeof(READ_CAPACITY_DATA),
                                               CDROM_TAG_READ_CAP);
            if (!dataBuffer) {
                ExFreePool(senseBuffer);
                ExFreePool(srb);
                IoFreeIrp(irp2);
                Irp->IoStatus.Information = 0;
                Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;

                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                return;

            }

            irp2->MdlAddress = IoAllocateMdl(dataBuffer,
                                            sizeof(READ_CAPACITY_DATA),
                                            FALSE,
                                            FALSE,
                                            (PIRP) NULL);

            if (!irp2->MdlAddress) {
                ExFreePool(senseBuffer);
                ExFreePool(srb);
                ExFreePool(dataBuffer);
                IoFreeIrp(irp2);
                Irp->IoStatus.Information = 0;
                Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;

                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                return;
            }

            //
            // Prepare the MDL
            //

            MmBuildMdlForNonPagedPool(irp2->MdlAddress);

            srb->DataBuffer = dataBuffer;
            cdb->CDB10.OperationCode = SCSIOP_READ_CAPACITY;

            IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp2);
            return;
        }

        case IOCTL_CDROM_GET_CONFIGURATION: {

            PGET_CONFIGURATION_IOCTL_INPUT inputBuffer;

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "CdRomStartIo: Get configuration (%p)\n", Irp));

            inputBuffer = (PGET_CONFIGURATION_IOCTL_INPUT)Irp->AssociatedIrp.SystemBuffer;

            if (!cdData->Mmc.IsMmc) {
                ExFreePool(senseBuffer);
                ExFreePool(srb);
                IoFreeIrp(irp2);
                Irp->IoStatus.Information = 0;
                Irp->IoStatus.Status = STATUS_INVALID_DEVICE_REQUEST;
                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                return;
            }

            //The maximum number of bytes that a Drive may return 
            //to describe its Features in one GET CONFIGURATION Command is 65,534
            transferByteCount = min(currentIrpStack->Parameters.DeviceIoControl.OutputBufferLength, (MAXUSHORT - 1));

            //
            // If this is a TYPE ONE request and if this device can't handle this
            // request, then we need to send TYPE ALL request to the device and
            // convert the data in the completion routine. If required allocate a big
            // buffer to get both configuration and feature header.
            //
            if ((inputBuffer->RequestType == SCSI_GET_CONFIGURATION_REQUEST_TYPE_ONE) &&
                TEST_FLAG(cdData->HackFlags, CDROM_HACK_BAD_TYPE_ONE_GET_CONFIG)) {
                transferByteCount = max(transferByteCount,
                                        sizeof(GET_CONFIGURATION_HEADER) + sizeof(FEATURE_HEADER));
            }

            dataBuffer = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                               transferByteCount,
                                               CDROM_TAG_GET_CONFIG);
            if (!dataBuffer) {
                ExFreePool(senseBuffer);
                ExFreePool(srb);
                IoFreeIrp(irp2);
                Irp->IoStatus.Information = 0;
                Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;
                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                return;
            }

            /*
             *  Zero out input buffer in case the device returns fewer bytes than advertized,
             *  which would cause us to return uninitialized kernel memory.
             */
            RtlZeroMemory(dataBuffer, transferByteCount);

            irp2->MdlAddress = IoAllocateMdl(dataBuffer,
                                             transferByteCount,
                                             FALSE,
                                             FALSE,
                                             (PIRP) NULL);
            if (!irp2->MdlAddress) {
                ExFreePool(dataBuffer);
                ExFreePool(senseBuffer);
                ExFreePool(srb);
                IoFreeIrp(irp2);
                Irp->IoStatus.Information = 0;
                Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;
                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                return;
            }

            MmBuildMdlForNonPagedPool(irp2->MdlAddress);

            //
            // setup remaining srb and cdb parameters
            //

            srb->SrbFlags = fdoExtension->SrbFlags;
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DATA_IN);
            srb->DataTransferLength = transferByteCount;
            srb->CdbLength = 10;
            srb->TimeOutValue = fdoExtension->TimeOutValue;
            srb->DataBuffer = dataBuffer;

            cdb->GET_CONFIGURATION.OperationCode = SCSIOP_GET_CONFIGURATION;
            cdb->GET_CONFIGURATION.AllocationLength[0] = (UCHAR)(transferByteCount >> 8);
            cdb->GET_CONFIGURATION.AllocationLength[1] = (UCHAR)(transferByteCount & 0xff);

            cdb->GET_CONFIGURATION.StartingFeature[0] = (UCHAR)(inputBuffer->Feature >> 8);
            cdb->GET_CONFIGURATION.StartingFeature[1] = (UCHAR)(inputBuffer->Feature & 0xff);
            cdb->GET_CONFIGURATION.RequestType        = (UCHAR)(inputBuffer->RequestType);

            //
            // If the device does not support TYPE ONE get configuration commands
            // then change the request type to TYPE ALL. Convert the returned data to
            // TYPE ONE format in the completion routine.
            //
            if ((inputBuffer->RequestType == SCSI_GET_CONFIGURATION_REQUEST_TYPE_ONE) &&
                TEST_FLAG(cdData->HackFlags, CDROM_HACK_BAD_TYPE_ONE_GET_CONFIG)) {

                TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                           "CdRomStartIo: Changing TYPE_ONE Get Config to TYPE_ALL\n"));
                cdb->GET_CONFIGURATION.RequestType = SCSI_GET_CONFIGURATION_REQUEST_TYPE_ALL;
            }

            IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp2);
            return;
        }

        case IOCTL_DISK_VERIFY: {

            PVERIFY_INFORMATION verifyInfo = Irp->AssociatedIrp.SystemBuffer;
            LARGE_INTEGER byteOffset = {0};
            ULONG         sectorOffset;
            USHORT        sectorCount;

            if (!cdData->Mmc.WriteAllowed) {
                ExFreePool(senseBuffer);
                ExFreePool(srb);
                IoFreeIrp(irp2);
                Irp->IoStatus.Information = 0;
                Irp->IoStatus.Status = STATUS_MEDIA_WRITE_PROTECTED;
                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                return;
            }

            //
            // Verify sectors
            //

            srb->CdbLength = 10;

            cdb->CDB10.OperationCode = SCSIOP_VERIFY;

            //
            // Add disk offset to starting sector.
            //

            byteOffset.QuadPart = commonExtension->StartingOffset.QuadPart +
                                  verifyInfo->StartingOffset.QuadPart;

            //
            // prevent overflow returning success but only validating small area
            //
            if ((commonExtension->StartingOffset.QuadPart + verifyInfo->StartingOffset.QuadPart < commonExtension->StartingOffset.QuadPart) ||
                ((verifyInfo->Length >> fdoExtension->SectorShift) > MAXUSHORT) ||
                ((byteOffset.QuadPart >> fdoExtension->SectorShift) > MAXULONG) ) {
                ExFreePool(senseBuffer);
                ExFreePool(srb);
                IoFreeIrp(irp2);
                Irp->IoStatus.Information = 0;
                Irp->IoStatus.Status = STATUS_INVALID_PARAMETER;
                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                return;
            }


            //
            // Convert byte offset to sector offset.
            //

            sectorOffset = (ULONG)(byteOffset.QuadPart >> fdoExtension->SectorShift);

            //
            // Convert ULONG byte count to USHORT sector count.
            //

            sectorCount = (USHORT)(verifyInfo->Length >> fdoExtension->SectorShift);

            //
            // Move little endian values into CDB in big endian format.
            //

            cdb->CDB10.LogicalBlockByte0 = ((PFOUR_BYTE)&sectorOffset)->Byte3;
            cdb->CDB10.LogicalBlockByte1 = ((PFOUR_BYTE)&sectorOffset)->Byte2;
            cdb->CDB10.LogicalBlockByte2 = ((PFOUR_BYTE)&sectorOffset)->Byte1;
            cdb->CDB10.LogicalBlockByte3 = ((PFOUR_BYTE)&sectorOffset)->Byte0;

            cdb->CDB10.TransferBlocksMsb = ((PFOUR_BYTE)&sectorCount)->Byte1;
            cdb->CDB10.TransferBlocksLsb = ((PFOUR_BYTE)&sectorCount)->Byte0;

            //
            // The verify command is used by the NT FORMAT utility and
            // requests are sent down for 5% of the volume size. The
            // request timeout value is calculated based on the number of
            // sectors verified.
            //
            if (sectorCount != 0) {
                // sectorCount is a USHORT, so no overflow here...
                srb->TimeOutValue = ((sectorCount + 128) / 128) * fdoExtension->TimeOutValue;
            } else {
                srb->TimeOutValue = fdoExtension->TimeOutValue;
            }

            IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp2);
            return;
        }

        case IOCTL_STORAGE_CHECK_VERIFY:
        case IOCTL_DISK_CHECK_VERIFY:
        case IOCTL_CDROM_CHECK_VERIFY: {

            //
            // Since a test unit ready is about to be performed, reset the
            // timer value to decrease the opportunities for it to race with
            // this code.
            //

            ClassResetMediaChangeTimer(fdoExtension);

            //
            // Set up the SRB/CDB
            //

            srb->CdbLength = 6;
            cdb->CDB6GENERIC.OperationCode = SCSIOP_TEST_UNIT_READY;
            srb->TimeOutValue = fdoExtension->TimeOutValue * 2;
            srb->SrbFlags = fdoExtension->SrbFlags;
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_NO_DATA_TRANSFER);


            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "CdRomStartIo: [%p] Sending CHECK_VERIFY irp %p\n",
                        Irp, irp2));
            IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp2);
            return;
        }

        case IOCTL_DVD_READ_STRUCTURE: {

            CdRomDeviceControlDvdReadStructure(Fdo, Irp, irp2, srb);
            return;

        }

        case IOCTL_DVD_END_SESSION: {
            CdRomDeviceControlDvdEndSession(Fdo, Irp, irp2, srb);
            return;
        }

        case IOCTL_DVD_START_SESSION:
        case IOCTL_DVD_READ_KEY: {

            CdRomDeviceControlDvdStartSessionReadKey(Fdo, Irp, irp2, srb);
            return;

        }


        case IOCTL_DVD_SEND_KEY:
        case IOCTL_DVD_SEND_KEY2: {

            CdRomDeviceControlDvdSendKey (Fdo, Irp, irp2, srb);
            return;


        }

        case IOCTL_CDROM_READ_TOC_EX: {

            PCDROM_READ_TOC_EX inputBuffer = Irp->AssociatedIrp.SystemBuffer;

            //The data length field of READ TOC Command occupies two bytes
            transferByteCount = min(currentIrpStack->Parameters.DeviceIoControl.OutputBufferLength, MAXUSHORT);

            dataBuffer = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                               transferByteCount,
                                               CDROM_TAG_TOC);
            if (!dataBuffer) {
                ExFreePool(senseBuffer);
                ExFreePool(srb);
                IoFreeIrp(irp2);
                Irp->IoStatus.Information = 0;
                Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;

                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                return;

            }

            /*
             *  Zero out input buffer in case the device returns fewer bytes than advertized,
             *  which would cause us to return uninitialized kernel memory.
             */
            RtlZeroMemory(dataBuffer, transferByteCount);

            irp2->MdlAddress = IoAllocateMdl(dataBuffer,
                                            transferByteCount,
                                            FALSE,
                                            FALSE,
                                            (PIRP) NULL);

            if (!irp2->MdlAddress) {
                ExFreePool(senseBuffer);
                ExFreePool(srb);
                ExFreePool(dataBuffer);
                IoFreeIrp(irp2);
                Irp->IoStatus.Information = 0;
                Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;

                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                return;
            }

            //
            // setup the request per user request
            // do validity checking in devctl dispatch, not here
            //

            cdb->READ_TOC.OperationCode = SCSIOP_READ_TOC;
            cdb->READ_TOC.Msf = inputBuffer->Msf;
            cdb->READ_TOC.Format2 = inputBuffer->Format;
            cdb->READ_TOC.StartingTrack = inputBuffer->SessionTrack;
            cdb->READ_TOC.AllocationLength[0] = (UCHAR)(transferByteCount >> 8);
            cdb->READ_TOC.AllocationLength[1] = (UCHAR)(transferByteCount & 0xff);

            //
            // Prepare the MDL
            //

            MmBuildMdlForNonPagedPool(irp2->MdlAddress);

            //
            // do the standard stuff....
            //

            srb->SrbFlags = fdoExtension->SrbFlags;
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DATA_IN);
            srb->DataTransferLength = transferByteCount;
            srb->CdbLength = 10;
            srb->TimeOutValue = fdoExtension->TimeOutValue;
            srb->DataBuffer = dataBuffer;

            IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp2);
            return;
        }

        case IOCTL_CDROM_GET_LAST_SESSION:
        case IOCTL_CDROM_READ_TOC: {

            if (currentIrpStack->Parameters.DeviceIoControl.IoControlCode ==
                IOCTL_CDROM_GET_LAST_SESSION) {
                //
                // Set format to return first and last session numbers.
                //
                cdb->READ_TOC.Format2 = CDROM_READ_TOC_EX_FORMAT_SESSION;
            } else {
                //
                // Use MSF addressing
                //
                cdb->READ_TOC.Msf = 1;
            }


            transferByteCount = min(currentIrpStack->Parameters.DeviceIoControl.OutputBufferLength, sizeof(CDROM_TOC));

            //
            // Set size of TOC structure.
            //
            cdb->READ_TOC.AllocationLength[0] = (UCHAR) (transferByteCount >> 8);
            cdb->READ_TOC.AllocationLength[1] = (UCHAR) (transferByteCount & 0xFF);

            //
            // setup remaining srb and cdb parameters.
            //
            srb->SrbFlags = fdoExtension->SrbFlags;
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DATA_IN);
            srb->DataTransferLength = transferByteCount;
            srb->CdbLength = 10;
            srb->TimeOutValue = fdoExtension->TimeOutValue;

            dataBuffer = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                               transferByteCount,
                                               CDROM_TAG_TOC);
            if (!dataBuffer) {
                ExFreePool(senseBuffer);
                ExFreePool(srb);
                IoFreeIrp(irp2);
                Irp->IoStatus.Information = 0;
                Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;

                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                return;

            }

            /*
             *  Zero out input buffer in case the device returns fewer bytes than advertized,
             *  which would cause us to return uninitialized kernel memory.
             */
            RtlZeroMemory(dataBuffer, transferByteCount);

            irp2->MdlAddress = IoAllocateMdl(dataBuffer,
                                            transferByteCount,
                                            FALSE,
                                            FALSE,
                                            (PIRP) NULL);

            if (!irp2->MdlAddress) {
                ExFreePool(senseBuffer);
                ExFreePool(srb);
                ExFreePool(dataBuffer);
                IoFreeIrp(irp2);
                Irp->IoStatus.Information = 0;
                Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;

                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                return;
            }

            //
            // Prepare the MDL
            //

            MmBuildMdlForNonPagedPool(irp2->MdlAddress);

            srb->DataBuffer = dataBuffer;
            cdb->READ_TOC.OperationCode = SCSIOP_READ_TOC;

            IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp2);
            return;

        }

        case IOCTL_CDROM_PLAY_AUDIO_MSF: {

            PCDROM_PLAY_AUDIO_MSF inputBuffer = Irp->AssociatedIrp.SystemBuffer;

            //
            // Set up the SRB/CDB
            //

            srb->CdbLength = 10;
            cdb->PLAY_AUDIO_MSF.OperationCode = SCSIOP_PLAY_AUDIO_MSF;

            cdb->PLAY_AUDIO_MSF.StartingM = inputBuffer->StartingM;
            cdb->PLAY_AUDIO_MSF.StartingS = inputBuffer->StartingS;
            cdb->PLAY_AUDIO_MSF.StartingF = inputBuffer->StartingF;

            cdb->PLAY_AUDIO_MSF.EndingM = inputBuffer->EndingM;
            cdb->PLAY_AUDIO_MSF.EndingS = inputBuffer->EndingS;
            cdb->PLAY_AUDIO_MSF.EndingF = inputBuffer->EndingF;

            srb->TimeOutValue = fdoExtension->TimeOutValue;
            srb->SrbFlags = fdoExtension->SrbFlags;
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_NO_DATA_TRANSFER);

            IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp2);
            return;

        }

        case IOCTL_CDROM_READ_Q_CHANNEL: {

            PCDROM_SUB_Q_DATA_FORMAT inputBuffer =
                             Irp->AssociatedIrp.SystemBuffer;

            //
            // Allocate buffer for subq channel information.
            //

            dataBuffer = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                               sizeof(SUB_Q_CHANNEL_DATA),
                                               CDROM_TAG_SUB_Q);

            if (!dataBuffer) {
                ExFreePool(senseBuffer);
                ExFreePool(srb);
                IoFreeIrp(irp2);
                Irp->IoStatus.Information = 0;
                Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;

                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                return;

            }

            /*
             *  Zero out input buffer in case the device returns fewer bytes than advertized,
             *  which would cause us to return uninitialized kernel memory.
             */
            RtlZeroMemory(dataBuffer, sizeof(SUB_Q_CHANNEL_DATA));

            irp2->MdlAddress = IoAllocateMdl(dataBuffer,
                                             sizeof(SUB_Q_CHANNEL_DATA),
                                             FALSE,
                                             FALSE,
                                             (PIRP) NULL);

            if (!irp2->MdlAddress) {
                ExFreePool(senseBuffer);
                ExFreePool(srb);
                ExFreePool(dataBuffer);
                IoFreeIrp(irp2);
                Irp->IoStatus.Information = 0;
                Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;

                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                return;
            }

            //
            // Prepare the MDL
            //

            MmBuildMdlForNonPagedPool(irp2->MdlAddress);

            srb->DataBuffer = dataBuffer;

            //
            // Always logical unit 0, but only use MSF addressing
            // for IOCTL_CDROM_CURRENT_POSITION
            //

            if (inputBuffer->Format==IOCTL_CDROM_CURRENT_POSITION)
                cdb->SUBCHANNEL.Msf = CDB_USE_MSF;

            //
            // Return subchannel data
            //

            cdb->SUBCHANNEL.SubQ = CDB_SUBCHANNEL_BLOCK;

            //
            // Specify format of informatin to return
            //

            cdb->SUBCHANNEL.Format = inputBuffer->Format;

            //
            // Specify which track to access (only used by Track ISRC reads)
            //

            if (inputBuffer->Format==IOCTL_CDROM_TRACK_ISRC) {
                cdb->SUBCHANNEL.TrackNumber = inputBuffer->Track;
            }

            //
            // Set size of channel data -- however, this is dependent on
            // what information we are requesting (which Format)
            //

            switch( inputBuffer->Format ) {

                case IOCTL_CDROM_CURRENT_POSITION:
                    transferByteCount = sizeof(SUB_Q_CURRENT_POSITION);
                    break;

                case IOCTL_CDROM_MEDIA_CATALOG:
                    transferByteCount = sizeof(SUB_Q_MEDIA_CATALOG_NUMBER);
                    break;

                case IOCTL_CDROM_TRACK_ISRC:
                    transferByteCount = sizeof(SUB_Q_TRACK_ISRC);
                    break;
            }

            cdb->SUBCHANNEL.AllocationLength[0] = (UCHAR) (transferByteCount >> 8);
            cdb->SUBCHANNEL.AllocationLength[1] = (UCHAR) (transferByteCount &  0xFF);
            cdb->SUBCHANNEL.OperationCode = SCSIOP_READ_SUB_CHANNEL;
            srb->SrbFlags = fdoExtension->SrbFlags;
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DATA_IN);
            srb->DataTransferLength = transferByteCount;
            srb->CdbLength = 10;
            srb->TimeOutValue = fdoExtension->TimeOutValue;

            IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp2);
            return;

        }

        case IOCTL_CDROM_PAUSE_AUDIO: {

            cdb->PAUSE_RESUME.OperationCode = SCSIOP_PAUSE_RESUME;
            cdb->PAUSE_RESUME.Action = CDB_AUDIO_PAUSE;

            srb->CdbLength = 10;
            srb->TimeOutValue = fdoExtension->TimeOutValue;
            srb->SrbFlags = fdoExtension->SrbFlags;
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_NO_DATA_TRANSFER);

            IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp2);
            return;
        }

        case IOCTL_CDROM_RESUME_AUDIO: {

            cdb->PAUSE_RESUME.OperationCode = SCSIOP_PAUSE_RESUME;
            cdb->PAUSE_RESUME.Action = CDB_AUDIO_RESUME;

            srb->CdbLength = 10;
            srb->TimeOutValue = fdoExtension->TimeOutValue;
            srb->SrbFlags = fdoExtension->SrbFlags;
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_NO_DATA_TRANSFER);

            IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp2);
            return;
        }

        case IOCTL_CDROM_SEEK_AUDIO_MSF: {

            PCDROM_SEEK_AUDIO_MSF inputBuffer = Irp->AssociatedIrp.SystemBuffer;
            ULONG                 logicalBlockAddress;

            logicalBlockAddress = MSF_TO_LBA(inputBuffer->M, inputBuffer->S, inputBuffer->F);

            cdb->SEEK.OperationCode      = SCSIOP_SEEK;
            cdb->SEEK.LogicalBlockAddress[0] = ((PFOUR_BYTE)&logicalBlockAddress)->Byte3;
            cdb->SEEK.LogicalBlockAddress[1] = ((PFOUR_BYTE)&logicalBlockAddress)->Byte2;
            cdb->SEEK.LogicalBlockAddress[2] = ((PFOUR_BYTE)&logicalBlockAddress)->Byte1;
            cdb->SEEK.LogicalBlockAddress[3] = ((PFOUR_BYTE)&logicalBlockAddress)->Byte0;

            srb->CdbLength = 10;
            srb->TimeOutValue = fdoExtension->TimeOutValue;
            srb->SrbFlags = fdoExtension->SrbFlags;
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_NO_DATA_TRANSFER);

            IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp2);
            return;

        }

        case IOCTL_CDROM_STOP_AUDIO: {

            cdb->START_STOP.OperationCode = SCSIOP_START_STOP_UNIT;
            cdb->START_STOP.Immediate = 1;
            cdb->START_STOP.Start = 0;
            cdb->START_STOP.LoadEject = 0;

            srb->CdbLength = 6;
            srb->TimeOutValue = fdoExtension->TimeOutValue;

            srb->SrbFlags = fdoExtension->SrbFlags;
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_NO_DATA_TRANSFER);

            IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp2);
            return;
        }

        case IOCTL_CDROM_GET_VOLUME:
        case IOCTL_CDROM_SET_VOLUME: {

            dataBuffer = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                        MODE_DATA_SIZE,
                                        CDROM_TAG_VOLUME);

            if (!dataBuffer) {
                ExFreePool(senseBuffer);
                ExFreePool(srb);
                IoFreeIrp(irp2);
                Irp->IoStatus.Information = 0;
                Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;

                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                return;
            }

            /*
             *  Zero out input buffer in case the device returns fewer bytes than advertized,
             *  which would cause us to return uninitialized kernel memory.
             */
            RtlZeroMemory(dataBuffer, MODE_DATA_SIZE);

            irp2->MdlAddress = IoAllocateMdl(dataBuffer,
                                            MODE_DATA_SIZE,
                                            FALSE,
                                            FALSE,
                                            (PIRP) NULL);

            if (!irp2->MdlAddress) {
                ExFreePool(senseBuffer);
                ExFreePool(srb);
                ExFreePool(dataBuffer);
                IoFreeIrp(irp2);
                Irp->IoStatus.Information = 0;
                Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;

                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", Irp, Irp->IoStatus.Status));
                CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
                return;
            }

            //
            // Prepare the MDL
            //

            MmBuildMdlForNonPagedPool(irp2->MdlAddress);
            srb->DataBuffer = dataBuffer;

            RtlZeroMemory(dataBuffer, MODE_DATA_SIZE);


            cdb->MODE_SENSE10.OperationCode = SCSIOP_MODE_SENSE10;
            cdb->MODE_SENSE10.PageCode = CDROM_AUDIO_CONTROL_PAGE;
            cdb->MODE_SENSE10.AllocationLength[0] = (UCHAR)(MODE_DATA_SIZE >> 8);
            cdb->MODE_SENSE10.AllocationLength[1] = (UCHAR)(MODE_DATA_SIZE & 0xFF);
            srb->CdbLength = 10;

            srb->TimeOutValue = fdoExtension->TimeOutValue;
            srb->DataTransferLength = MODE_DATA_SIZE;
            srb->SrbFlags = fdoExtension->SrbFlags;
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DATA_IN);

            if (currentIrpStack->Parameters.DeviceIoControl.IoControlCode == IOCTL_CDROM_SET_VOLUME) {

                //
                // Setup a different completion routine as the mode sense data is needed in order
                // to send the mode select.
                //

                IoSetCompletionRoutine(irp2,
                                       CdRomSetVolumeIntermediateCompletion,
                                       srb,
                                       TRUE,
                                       TRUE,
                                       TRUE);

            }

            IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp2);
            return;

        }

        case IOCTL_STORAGE_SET_READ_AHEAD: {

            PSTORAGE_SET_READ_AHEAD readAhead = Irp->AssociatedIrp.SystemBuffer;

            ULONG blockAddress;
            PFOUR_BYTE fourByte = (PFOUR_BYTE) &blockAddress;

            //
            // setup the SRB for a set readahead command
            //

            cdb->SET_READ_AHEAD.OperationCode = SCSIOP_SET_READ_AHEAD;

            blockAddress = (ULONG) (readAhead->TriggerAddress.QuadPart >>
                                    fdoExtension->SectorShift);

            cdb->SET_READ_AHEAD.TriggerLBA[0] = fourByte->Byte3;
            cdb->SET_READ_AHEAD.TriggerLBA[1] = fourByte->Byte2;
            cdb->SET_READ_AHEAD.TriggerLBA[2] = fourByte->Byte1;
            cdb->SET_READ_AHEAD.TriggerLBA[3] = fourByte->Byte0;

            blockAddress = (ULONG) (readAhead->TargetAddress.QuadPart >>
                                    fdoExtension->SectorShift);

            cdb->SET_READ_AHEAD.ReadAheadLBA[0] = fourByte->Byte3;
            cdb->SET_READ_AHEAD.ReadAheadLBA[1] = fourByte->Byte2;
            cdb->SET_READ_AHEAD.ReadAheadLBA[2] = fourByte->Byte1;
            cdb->SET_READ_AHEAD.ReadAheadLBA[3] = fourByte->Byte0;

            srb->CdbLength = 12;
            srb->TimeOutValue = fdoExtension->TimeOutValue;

            srb->SrbFlags = fdoExtension->SrbFlags;
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
            SET_FLAG(srb->SrbFlags, SRB_FLAGS_NO_DATA_TRANSFER);

            IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp2);
            return;
        }

        case IOCTL_DISK_GET_DRIVE_LAYOUT:
        case IOCTL_DISK_GET_DRIVE_LAYOUT_EX:
        case IOCTL_DISK_GET_PARTITION_INFO:
        case IOCTL_DISK_GET_PARTITION_INFO_EX: {

            ASSERT(irp2);
            ASSERT(senseBuffer);
            ASSERT(srb);

            ExFreePool(srb);
            ExFreePool(senseBuffer);
            IoFreeIrp(irp2);

            //
            // NOTE: should probably update the media's capacity first...
            //

            CdromFakePartitionInfo(commonExtension, Irp);
            return;
        }

        case IOCTL_DISK_IS_WRITABLE: {

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "CdRomStartIo: DiskIsWritable (%p) - returning %s\n",
                        Irp, (cdData->Mmc.WriteAllowed ? "TRUE" : "false")));

            ASSERT(irp2);
            ASSERT(senseBuffer);
            ASSERT(srb);

            ExFreePool(srb);
            ExFreePool(senseBuffer);
            IoFreeIrp(irp2);

            Irp->IoStatus.Information = 0;

            //
            // Even though this media is writable, the requester of this IOCTL really
            // wants to know if thw media behaves like any other disk or not. This is
            // so if FeatureDefectManagement and FeatureRandomWritable are current on
            // the drive-represented by the FeatureDefectManagement validation schema
            //

            if (cdData->Mmc.WriteAllowed && cdData->Mmc.ValidationSchema == FeatureDefectManagement) {
                Irp->IoStatus.Status = STATUS_SUCCESS;
            } else {
                Irp->IoStatus.Status = STATUS_MEDIA_WRITE_PROTECTED;
            }

            CdRomCompleteIrpAndStartNextPacketSafely(Fdo, Irp);
            return;
        }

        case IOCTL_CDROM_SET_SPEED: {

            CdRomSetSpeed(Fdo, Irp, irp2, srb);
            return;
        }

        case IOCTL_AACS_READ_MEDIA_KEY_BLOCK_SIZE:
        case IOCTL_AACS_READ_MEDIA_KEY_BLOCK:
        {
            AacsGetMediaKeyBlock(Fdo, Irp, irp2, srb);
            return;
        }
        case IOCTL_AACS_START_SESSION:
        {
            AacsGetAgid(Fdo, Irp, irp2, srb);
            return;
        }
        case IOCTL_AACS_END_SESSION:
        {
            AacsReleaseAgid(Fdo, Irp, irp2, srb);
            return;
        }
        case IOCTL_AACS_SEND_CERTIFICATE:
        {
            AacsSendHostCertificate(Fdo, Irp, irp2, srb);
            return;
        }
        case IOCTL_AACS_GET_CERTIFICATE:
        {
            AacsGetDriveCertificate(Fdo, Irp, irp2, srb);
            return;
        }
        case IOCTL_AACS_GET_CHALLENGE_KEY:
        {
            AacsGetChallengeKey(Fdo, Irp, irp2, srb);
            return;
        }
        case IOCTL_AACS_SEND_CHALLENGE_KEY:
        {
            AacsSendChallengeKey(Fdo, Irp, irp2, srb);
            return;
        }
        case IOCTL_AACS_READ_VOLUME_ID:
        {
            AacsReadVolumeID(Fdo, Irp, irp2, srb);
            return;
        }
        case IOCTL_AACS_READ_SERIAL_NUMBER:
        {
            AacsReadSerialNumber(Fdo, Irp, irp2, srb);
            return;
        }
        case IOCTL_AACS_READ_MEDIA_ID:
        {
            AacsReadMediaID(Fdo, Irp, irp2, srb);
            return;
        }
        case IOCTL_AACS_READ_BINDING_NONCE:
        {
            AacsReadBindingNonce(Fdo, Irp, irp2, srb);
            return;
        }
        case IOCTL_AACS_GENERATE_BINDING_NONCE:
        {
            AacsGenerateBindingNonce(Fdo, Irp, irp2, srb);
            return;
        }

        default:
        {
            static BOOLEAN breakOnCodePath = TRUE;
            UCHAR uniqueAddress;

            if (breakOnCodePath)
            {
                ASSERT(!"Using new serialization method -- check how this gets hit!");
            }

            // QUESTION -- DOES THIS *EVER* GET HIT?
            // Just complete the request - CdRomClassIoctlCompletion will take
            // care of setting the event w/o calling IoStartNextPacket()
            // NOTE: THIS IS A SYNCHRONIZATION METHOD!!!

            ASSERT(irp2);
            ASSERT(senseBuffer);
            ASSERT(srb);
            ExFreePool(srb);
            ExFreePool(senseBuffer);
            IoFreeIrp(irp2);

            ClassAcquireRemoveLock(Fdo, (PIRP)&uniqueAddress);
            ClassReleaseRemoveLock(Fdo, Irp);
            ClassCompleteRequest(Fdo, Irp, IO_NO_INCREMENT);
            ClassReleaseRemoveLock(Fdo, (PIRP)&uniqueAddress);
            return;
        }

        } // end switch()
    } else if (currentIrpStack->MajorFunction == IRP_MJ_SHUTDOWN ||
               currentIrpStack->MajorFunction == IRP_MJ_FLUSH_BUFFERS) {

        currentIrpStack->Parameters.Others.Argument1 = 0;
        Irp->IoStatus.Status = STATUS_SUCCESS;
        CdRomShutdownFlushCompletion(Fdo, NULL, Irp);
        return;

    }

    //
    // If a read or an unhandled IRP_MJ_XX, end up here. The unhandled IRP_MJ's
    // are expected and composed of AutoRun Irps, at present.
    //

    IoCallDriver(commonExtension->LowerDeviceObject, Irp);
    return;
}


__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomReadWriteVerification(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    )

/*++

Routine Description:

    This is the entry called by the I/O system for read requests.
    It builds the SRB and sends it to the port driver.

Arguments:

    DeviceObject - the system object for the device.
    Irp - IRP involved.

Return Value:

    NT Status

--*/

{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = DeviceObject->DeviceExtension;
    PCDROM_DATA cdData = (PCDROM_DATA)(commonExtension->DriverData);
    PIO_STACK_LOCATION irpStack = IoGetCurrentIrpStackLocation(Irp);

    //
    // note: we are no longer failing write commands immediately
    //       they are now failed in StartIo based upon media ability
    //

    //
    // If the cd is playing music then reject this request.
    //

    if (PLAY_ACTIVE(fdoExtension)) {
        Irp->IoStatus.Status = STATUS_DEVICE_BUSY;
        return STATUS_DEVICE_BUSY;
    }

    //
    // If the device is in exclusive mode, check whether the request is from
    // the handle that locked the device.
    //

    if (EXCLUSIVE_MODE(cdData) && !EXCLUSIVE_OWNER(cdData, irpStack->FileObject)) {

        //
        // This request is not from the owner. We can't let the operation go.
        //

        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_RW, "CdRomReadWriteVerification: Access Denied! Device in exclusive mode.\n"));

        Irp->IoStatus.Status = STATUS_ACCESS_DENIED;
        return STATUS_ACCESS_DENIED;
    }

    return STATUS_SUCCESS;

} // end CdRomReadWriteVerification()


VOID
ScanForSpecialHandler(
    PFUNCTIONAL_DEVICE_EXTENSION FdoExtension,
    ULONG_PTR HackFlags
    )
{
    PCOMMON_DEVICE_EXTENSION commonExtension;
    PCDROM_DATA cdData;

    PAGED_CODE();

    CLEAR_FLAG(HackFlags, CDROM_HACK_INVALID_FLAGS);

    commonExtension = &(FdoExtension->CommonExtension);
    cdData = (PCDROM_DATA)(commonExtension->DriverData);
    cdData->HackFlags = HackFlags;

    return;
}

VOID
ScanForSpecial(
    PDEVICE_OBJECT DeviceObject
    )

/*++

Routine Description:

    This function checks to see if an SCSI logical unit requires an special
    initialization or error processing.

Arguments:

    DeviceObject - Supplies the device object to be tested.

    InquiryData - Supplies the inquiry data returned by the device of interest.

    PortCapabilities - Supplies the capabilities of the device object.

Return Value:

    None.

--*/

{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension;
    PCDROM_DATA cdData;

    PAGED_CODE();

    fdoExtension = DeviceObject->DeviceExtension;
    commonExtension = DeviceObject->DeviceExtension;
    cdData = (PCDROM_DATA)(commonExtension->DriverData);


    //
    // set our hack flags
    //

    ClassScanForSpecial(fdoExtension, CdromHackItems, ScanForSpecialHandler);

    //
    // All CDRom's can ignore the queue lock failure for power operations
    // and do not require handling the SpinUp case (unknown result of sending
    // a cdrom a START_UNIT command -- may eject disks?)
    //
    // We send the stop command mostly to stop outstanding asynch operations
    // (like audio playback) from running when the system is powered off.
    // Because of this and the unlikely chance that a PLAY command will be
    // sent in the window between the STOP and the time the machine powers down
    // we don't require queue locks.  This is important because without them
    // classpnp's power routines will send the START_STOP_UNIT command to the
    // device whether or not it supports locking (atapi does not support locking
    // and if we requested them we would end up not stopping audio on atapi
    // devices).
    //

    SET_FLAG(fdoExtension->ScanForSpecialFlags, CLASS_SPECIAL_DISABLE_SPIN_UP);
    SET_FLAG(fdoExtension->ScanForSpecialFlags, CLASS_SPECIAL_NO_QUEUE_LOCK);

    if (TEST_FLAG(cdData->HackFlags, CDROM_HACK_HITACHI_1750)
        && ( fdoExtension->AdapterDescriptor->AdapterUsesPio )
        ) {

        //
        // Read-ahead must be disabled in order to get this cdrom drive
        // to work on scsi adapters that use PIO.
        //


        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                    "CdRom ScanForSpecial:  Found Hitachi CDR-1750S.\n"));

        //
        // Setup an error handler to reinitialize the cd rom after it is reset.
        //

        cdData->ErrorHandler = HitachiProcessError;

        //
        // Lock down the hitachi error processing code.
        //

        MmLockPagableCodeSection(HitachiProcessError);
        SET_FLAG(cdData->HackFlags, CDROM_HACK_LOCKED_PAGES);


    } else if (TEST_FLAG(cdData->HackFlags, CDROM_HACK_TOSHIBA_SD_W1101)) {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                    "CdRom ScanForSpecial: Found Toshiba SD-W1101 DVD-RAM "
                    "-- This drive will *NOT* support DVD-ROM playback.\n"));

    } else if (TEST_FLAG(cdData->HackFlags, CDROM_HACK_HITACHI_GD_2000)) {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                    "CdRom ScanForSpecial: Found Hitachi GD-2000\n"));

        //
        // Setup an error handler to spin up the drive when it idles out
        // since it seems to like to fail to spin itself back up on its
        // own for a REPORT_KEY command.  It may also lose the AGIDs that
        // it has given, which will result in DVD playback failures.
        // This routine will just do what it can...
        //

        cdData->ErrorHandler = HitachiProcessErrorGD2000;

        //
        // this drive may require START_UNIT commands to spin
        // the drive up when it's spun itself down.
        //

        SET_FLAG(fdoExtension->DeviceFlags, DEV_SAFE_START_UNIT);

        //
        // Lock down the hitachi error processing code.
        //

        MmLockPagableCodeSection(HitachiProcessErrorGD2000);
        SET_FLAG(cdData->HackFlags, CDROM_HACK_LOCKED_PAGES);

    } else if (TEST_FLAG(cdData->HackFlags, CDROM_HACK_FUJITSU_FMCD_10x)) {

        //
        // When Read command is issued to FMCD-101 or FMCD-102 and there is a music
        // cd in it. It takes longer time than SCSI_CDROM_TIMEOUT before returning
        // error status.
        //

        fdoExtension->TimeOutValue = 20;

    } else if (TEST_FLAG(cdData->HackFlags, CDROM_HACK_DEC_RRD)) {

        PMODE_PARM_READ_WRITE_DATA modeParameters;
        SCSI_REQUEST_BLOCK         srb = {0};
        PCDB                       cdb;
        NTSTATUS                   status;


        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                    "CdRom ScanForSpecial:  Found DEC RRD.\n"));

        cdData->IsDecRrd = TRUE;

        //
        // Setup an error handler to reinitialize the cd rom after it is reset?
        //
        //commonExtension->DevInfo->ClassError = DecRrdProcessError;

        //
        // Found a DEC RRD cd-rom.  These devices do not pass MS HCT
        // multi-media tests because the DEC firmware modifieds the block
        // from the PC-standard 2K to 512.  Change the block transfer size
        // back to the PC-standard 2K by using a mode select command.
        //

        modeParameters = ExAllocatePoolWithTag(NonPagedPool,
                                               sizeof(MODE_PARM_READ_WRITE_DATA),
                                               CDROM_TAG_MODE_DATA
                                               );
        if (modeParameters == NULL) {
            return;
        }

        RtlZeroMemory(modeParameters, sizeof(MODE_PARM_READ_WRITE_DATA));
        RtlZeroMemory(&srb,           sizeof(SCSI_REQUEST_BLOCK));

        //
        // Set the block length to 2K.
        //

        modeParameters->ParameterListHeader.BlockDescriptorLength =
                sizeof(MODE_PARAMETER_BLOCK);

        //
        // Set block length to 2K (0x0800) in Parameter Block.
        //

        modeParameters->ParameterListBlock.BlockLength[0] = 0x00; //MSB
        modeParameters->ParameterListBlock.BlockLength[1] = 0x08;
        modeParameters->ParameterListBlock.BlockLength[2] = 0x00; //LSB

        //
        // Build the mode select CDB.
        //

        srb.CdbLength = 6;
        srb.TimeOutValue = fdoExtension->TimeOutValue;

        cdb = (PCDB)srb.Cdb;
        cdb->MODE_SELECT.PFBit               = 1;
        cdb->MODE_SELECT.OperationCode       = SCSIOP_MODE_SELECT;
        cdb->MODE_SELECT.ParameterListLength = HITACHI_MODE_DATA_SIZE;

        //
        // Send the request to the device.
        //

        status = ClassSendSrbSynchronous(DeviceObject,
                                         &srb,
                                         modeParameters,
                                         sizeof(MODE_PARM_READ_WRITE_DATA),
                                         TRUE);

        if (!NT_SUCCESS(status)) {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                        "CdRom ScanForSpecial: Setting DEC RRD to 2K block"
                        "size failed [%x]\n", status));
        }
        ExFreePool(modeParameters);

    } else if (TEST_FLAG(cdData->HackFlags, CDROM_HACK_TOSHIBA_XM_3xx)) {

        SCSI_REQUEST_BLOCK srb = {0};
        PCDB               cdb;
        ULONG              length;
        PUCHAR             buffer;
        NTSTATUS           status;

        //
        // Set the density code and the error handler.
        //

        length =
            sizeof(MODE_READ_RECOVERY_PAGE) +
            MODE_BLOCK_DESC_LENGTH +
            MODE_HEADER_LENGTH;

        RtlZeroMemory(&srb, sizeof(SCSI_REQUEST_BLOCK));

        //
        // Build the MODE SENSE CDB.
        //

        srb.CdbLength = 6;
        cdb = (PCDB)srb.Cdb;

        //
        // Set timeout value from device extension.
        //

        srb.TimeOutValue = fdoExtension->TimeOutValue;

        cdb->MODE_SENSE.OperationCode = SCSIOP_MODE_SENSE;
        cdb->MODE_SENSE.PageCode = 0x1;
        // NOTE: purposely not setting DBD because it is what is needed.
        cdb->MODE_SENSE.AllocationLength = (UCHAR)length;

        buffer = ExAllocatePoolWithTag(
            NonPagedPoolCacheAligned,
            (sizeof(MODE_READ_RECOVERY_PAGE) + MODE_BLOCK_DESC_LENGTH + MODE_HEADER_LENGTH),
            CDROM_TAG_MODE_DATA);

        if (!buffer) {
            return;
        }

        status = ClassSendSrbSynchronous(DeviceObject,
                                         &srb,
                                         buffer,
                                         length,
                                         FALSE);

        ((PERROR_RECOVERY_DATA)buffer)->BlockDescriptor.DensityCode = 0x83;
        ((PERROR_RECOVERY_DATA)buffer)->Header.ModeDataLength = 0x0;

        RtlCopyMemory(&cdData->recoveryData, buffer, sizeof(ERROR_RECOVERY_DATA));

        RtlZeroMemory(&srb, sizeof(SCSI_REQUEST_BLOCK));

        //
        // Build the MODE SENSE CDB.
        //

        srb.CdbLength = 6;
        cdb = (PCDB)srb.Cdb;

        //
        // Set timeout value from device extension.
        //

        srb.TimeOutValue = fdoExtension->TimeOutValue;

        cdb->MODE_SELECT.OperationCode = SCSIOP_MODE_SELECT;
        cdb->MODE_SELECT.PFBit = 1;
        cdb->MODE_SELECT.ParameterListLength = (UCHAR)length;

        status = ClassSendSrbSynchronous(DeviceObject,
                                         &srb,
                                         buffer,
                                         length,
                                         TRUE);

        if (!NT_SUCCESS(status)) {

            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                        "Cdrom.ScanForSpecial: Setting density code on Toshiba failed [%x]\n",
                        status));
        }

        cdData->ErrorHandler = ToshibaProcessError;

        //
        // Lock down the toshiba error section.
        //

        MmLockPagableCodeSection(ToshibaProcessError);
        SET_FLAG(cdData->HackFlags, CDROM_HACK_LOCKED_PAGES);

        ExFreePool(buffer);

    }

    if (TEST_FLAG(cdData->HackFlags, CDROM_HACK_LOCKED_PAGES)) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "Locking pages for error handler\n"));
    }


    return;
}


VOID
HitachiProcessErrorGD2000(
    PDEVICE_OBJECT Fdo,
    PSCSI_REQUEST_BLOCK OriginalSrb,
    NTSTATUS *Status,
    BOOLEAN *Retry
    )
/*++

Routine Description:

   This routine checks the type of error.  If the error suggests that the
   drive has spun down and cannot reinitialize itself, send a
   START_UNIT or READ to the device.  This will force the drive to spin
   up.  This drive also loses the AGIDs it has granted when it spins down,
   which may result in playback failure the first time around.

Arguments:

    DeviceObject - Supplies a pointer to the device object.

    Srb - Supplies a pointer to the failing Srb.

    Status - return the final status for this command?

    Retry - return if the command should be retried.

Return Value:

    None.

--*/
{
    PSENSE_DATA senseBuffer = OriginalSrb->SenseInfoBuffer;

    UNREFERENCED_PARAMETER(Status);
    UNREFERENCED_PARAMETER(Retry);

    if (!TEST_FLAG(OriginalSrb->SrbStatus, SRB_STATUS_AUTOSENSE_VALID)) {
        return;
    }

    if (((senseBuffer->SenseKey & 0xf) == SCSI_SENSE_HARDWARE_ERROR) &&
        (senseBuffer->AdditionalSenseCode == 0x44)) {

        PFUNCTIONAL_DEVICE_EXTENSION fdoExtension;
        PIRP                irp;
        PIO_STACK_LOCATION  irpStack;
        PCOMPLETION_CONTEXT context;
        PSCSI_REQUEST_BLOCK newSrb;
        PCDB                cdb;

        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_GENERAL,
                    "HitachiProcessErrorGD2000 (%p) => Internal Target "
                    "Failure Detected -- spinning up drive\n", Fdo));

        //
        // the request should be retried because the device isn't ready
        //

        *Retry = TRUE;
        *Status = STATUS_DEVICE_NOT_READY;

        //
        // send a START_STOP unit to spin up the drive
        // NOTE: this temporarily violates the StartIo serialization
        //       mechanism, but the completion routine on this will NOT
        //       call StartNextPacket(), so it's a temporary disruption
        //       of the serialization only.
        //

        ClassSendStartUnit(Fdo);

    }

    return;
}


VOID
HitachiProcessError(
    PDEVICE_OBJECT DeviceObject,
    PSCSI_REQUEST_BLOCK Srb,
    NTSTATUS *Status,
    BOOLEAN *Retry
    )
/*++

Routine Description:

   This routine checks the type of error.  If the error indicates CD-ROM the
   CD-ROM needs to be reinitialized then a Mode sense command is sent to the
   device.  This command disables read-ahead for the device.

Arguments:

    DeviceObject - Supplies a pointer to the device object.

    Srb - Supplies a pointer to the failing Srb.

    Status - Not used.

    Retry - Not used.

Return Value:

    None.

--*/

{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PSENSE_DATA         senseBuffer = Srb->SenseInfoBuffer;
    LARGE_INTEGER       largeInt = {0};
    PUCHAR              modePage;
    PIO_STACK_LOCATION  irpStack;
    PIRP                irp;
    PSCSI_REQUEST_BLOCK srb;
    PCOMPLETION_CONTEXT context;
    PCDB                cdb;
    __in_range(0, FILE_512_BYTE_ALIGNMENT) ULONG_PTR alignment;

    UNREFERENCED_PARAMETER(Status);
    UNREFERENCED_PARAMETER(Retry);

    largeInt.QuadPart = (LONGLONG) 1;

    //
    // Check the status.  The initialization command only needs to be sent
    // if UNIT ATTENTION is returned.
    //

    if (!(Srb->SrbStatus & SRB_STATUS_AUTOSENSE_VALID)) {

        //
        // The drive does not require reinitialization.
        //

        return;
    }

    //
    // Found an HITACHI cd-rom that does not work with PIO
    // adapters when read-ahead is enabled.  Read-ahead is disabled by
    // a mode select command.  The mode select page code is zero and the
    // length is 6 bytes.  All of the other bytes should be zero.
    //

    if ((senseBuffer->SenseKey & 0xf) == SCSI_SENSE_UNIT_ATTENTION) {

        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_GENERAL,
                    "HitachiProcessError: Reinitializing the CD-ROM.\n"));

        //
        // Send the special mode select command to disable read-ahead
        // on the CD-ROM reader.
        //

        alignment = DeviceObject->AlignmentRequirement ?
            DeviceObject->AlignmentRequirement : 1;

        context = ExAllocatePoolWithTag(
            NonPagedPool,
            sizeof(COMPLETION_CONTEXT) +  HITACHI_MODE_DATA_SIZE + (ULONG)alignment,
            CDROM_TAG_HITACHI_ERROR
            );

        if (context == NULL) {

            //
            // If there is not enough memory to fulfill this request,
            // simply return. A subsequent retry will fail and another
            // chance to start the unit.
            //

            return;
        }

        context->DeviceObject = DeviceObject;
        srb = &context->Srb;

        RtlZeroMemory(srb, SCSI_REQUEST_BLOCK_SIZE);

        //
        // Write length to SRB.
        //

        srb->Length = SCSI_REQUEST_BLOCK_SIZE;

        //
        // Set up SCSI bus address.
        //

        srb->Function = SRB_FUNCTION_EXECUTE_SCSI;
        srb->TimeOutValue = fdoExtension->TimeOutValue;

        //
        // Set the transfer length.
        //

        srb->DataTransferLength = HITACHI_MODE_DATA_SIZE;
        srb->SrbFlags = fdoExtension->SrbFlags;
        SET_FLAG(srb->SrbFlags, SRB_FLAGS_DATA_OUT);
        SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_AUTOSENSE);
        SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);

        //
        // The data buffer must be aligned.
        //

        srb->DataBuffer = (PVOID) (((ULONG_PTR) (context + 1) + (alignment - 1)) &
            ~(alignment - 1));


        //
        // Build the HITACHI read-ahead mode select CDB.
        //

        srb->CdbLength = 6;
        cdb = (PCDB)srb->Cdb;
        cdb->MODE_SENSE.LogicalUnitNumber = srb->Lun;
        cdb->MODE_SENSE.OperationCode = SCSIOP_MODE_SELECT;
        cdb->MODE_SENSE.AllocationLength = HITACHI_MODE_DATA_SIZE;

        //
        // Initialize the mode sense data.
        //

        modePage = srb->DataBuffer;

        RtlZeroMemory(modePage, HITACHI_MODE_DATA_SIZE);

        //
        // Set the page length field to 6.
        //

        modePage[5] = 6;

        //
        // Build the asynchronous request to be sent to the port driver.
        //

        irp = IoBuildAsynchronousFsdRequest(IRP_MJ_WRITE,
                                           DeviceObject,
                                           srb->DataBuffer,
                                           srb->DataTransferLength,
                                           &largeInt,
                                           NULL);

        if (irp == NULL) {

            //
            // If there is not enough memory to fulfill this request,
            // simply return. A subsequent retry will fail and another
            // chance to start the unit.
            //

            ExFreePool(context);
            return;
        }

        ClassAcquireRemoveLock(DeviceObject, irp);

        IoSetCompletionRoutine(irp,
                   (PIO_COMPLETION_ROUTINE)ClassAsynchronousCompletion,
                   context,
                   TRUE,
                   TRUE,
                   TRUE);

        irpStack = IoGetNextIrpStackLocation(irp);

        irpStack->MajorFunction = IRP_MJ_SCSI;

        srb->OriginalRequest = irp;

        //
        // Save SRB address in next stack for port driver.
        //

        irpStack->Parameters.Scsi.Srb = (PVOID)srb;

        //
        // Set up IRP Address.
        //

        (VOID)IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp);

    }
}


NTSTATUS
ToshibaProcessErrorCompletion(
    PDEVICE_OBJECT DeviceObject,
    PIRP Irp,
    PVOID Context
    )

/*++

Routine Description:

    Completion routine for the ClassError routine to handle older Toshiba units
    that require setting the density code.

Arguments:

    DeviceObject - Supplies a pointer to the device object.

    Irp - Pointer to irp created to set the density code.

    Context - Supplies a pointer to the Mode Select Srb.


Return Value:

    STATUS_MORE_PROCESSING_REQUIRED

--*/

{

    PSCSI_REQUEST_BLOCK srb = Context;

    //
    // Free all of the allocations.
    //

    ClassReleaseRemoveLock(DeviceObject, Irp);

    ExFreePool(srb->DataBuffer);
    ExFreePool(srb);
    IoFreeMdl(Irp->MdlAddress);
    IoFreeIrp(Irp);

    //
    // Indicate the I/O system should stop processing the Irp completion.
    //

    return STATUS_MORE_PROCESSING_REQUIRED;
}


VOID
ToshibaProcessError(
    PDEVICE_OBJECT DeviceObject,
    PSCSI_REQUEST_BLOCK Srb,
    NTSTATUS *Status,
    BOOLEAN *Retry
    )

/*++

Routine Description:

   This routine checks the type of error.  If the error indicates a unit attention,
   the density code needs to be set via a Mode select command.

Arguments:

    DeviceObject - Supplies a pointer to the device object.

    Srb - Supplies a pointer to the failing Srb.

    Status - Not used.

    Retry - Not used.

Return Value:

    None.

--*/

{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = DeviceObject->DeviceExtension;

    PCDROM_DATA         cdData = (PCDROM_DATA)(commonExtension->DriverData);
    PSENSE_DATA         senseBuffer = Srb->SenseInfoBuffer;
    PIO_STACK_LOCATION  irpStack;
    PIRP                irp;
    PSCSI_REQUEST_BLOCK srb;
    ULONG               length;
    PCDB                cdb;
    PUCHAR              dataBuffer;


    if (!(Srb->SrbStatus & SRB_STATUS_AUTOSENSE_VALID)) {
        return;
    }

    //
    // The Toshiba's require the density code to be set on power up and media changes.
    //

    if ((senseBuffer->SenseKey & 0xf) == SCSI_SENSE_UNIT_ATTENTION) {


        irp = IoAllocateIrp((CCHAR)(DeviceObject->StackSize+1),
                              FALSE);

        if (!irp) {
            return;
        }

        srb = ExAllocatePoolWithTag(NonPagedPool,
                                    sizeof(SCSI_REQUEST_BLOCK),
                                    CDROM_TAG_TOSHIBA_ERROR);
        if (!srb) {
            IoFreeIrp(irp);
            return;
        }


        length = sizeof(ERROR_RECOVERY_DATA);
        dataBuffer = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                           length,
                                           CDROM_TAG_TOSHIBA_ERROR);
        if (!dataBuffer) {
            ExFreePool(srb);
            IoFreeIrp(irp);
            return;
        }

        /*
         *  Zero out input buffer in case the device returns fewer bytes than advertized,
         *  which would cause us to return uninitialized kernel memory.
         */
        RtlZeroMemory(dataBuffer, length);

        irp->MdlAddress = IoAllocateMdl(dataBuffer,
                                        length,
                                        FALSE,
                                        FALSE,
                                        (PIRP) NULL);

        if (!irp->MdlAddress) {
            ExFreePool(srb);
            ExFreePool(dataBuffer);
            IoFreeIrp(irp);
            return;
        }

        //
        // Prepare the MDL
        //

        MmBuildMdlForNonPagedPool(irp->MdlAddress);

        RtlZeroMemory(srb, sizeof(SCSI_REQUEST_BLOCK));

        srb->DataBuffer = dataBuffer;
        cdb = (PCDB)srb->Cdb;

        //
        // Set up the irp.
        //

        IoSetNextIrpStackLocation(irp);
        irp->IoStatus.Status = STATUS_SUCCESS;
        irp->IoStatus.Information = 0;
        irp->Flags = 0;
        irp->UserBuffer = NULL;

        //
        // Save the device object and irp in a private stack location.
        //

        irpStack = IoGetCurrentIrpStackLocation(irp);
        irpStack->DeviceObject = DeviceObject;

        //
        // Construct the IRP stack for the lower level driver.
        //

        irpStack = IoGetNextIrpStackLocation(irp);
        irpStack->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;
        irpStack->Parameters.DeviceIoControl.IoControlCode = IOCTL_SCSI_EXECUTE_OUT;
        irpStack->Parameters.Scsi.Srb = srb;

        IoSetCompletionRoutine(irp,
                               ToshibaProcessErrorCompletion,
                               srb,
                               TRUE,
                               TRUE,
                               TRUE);

        ClassAcquireRemoveLock(DeviceObject, irp);

        srb->Length = SCSI_REQUEST_BLOCK_SIZE;
        srb->Function = SRB_FUNCTION_EXECUTE_SCSI;
        srb->SrbStatus = srb->ScsiStatus = 0;
        srb->NextSrb = 0;
        srb->OriginalRequest = irp;
        srb->SenseInfoBufferLength = 0;

        //
        // Set the transfer length.
        //

        srb->DataTransferLength = length;
        srb->SrbFlags = fdoExtension->SrbFlags;
        SET_FLAG(srb->SrbFlags, SRB_FLAGS_DATA_OUT);
        SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_AUTOSENSE);
        SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
        SET_FLAG(srb->SrbFlags, SRB_FLAGS_NO_QUEUE_FREEZE);


        srb->CdbLength = 6;
        cdb->MODE_SELECT.OperationCode = SCSIOP_MODE_SELECT;
        cdb->MODE_SELECT.PFBit = 1;
        cdb->MODE_SELECT.ParameterListLength = (UCHAR)length;

        //
        // Copy the Mode page into the databuffer.
        //

        RtlCopyMemory(srb->DataBuffer, &cdData->recoveryData, length);

        //
        // Set the density code.
        //

        ((PERROR_RECOVERY_DATA)srb->DataBuffer)->BlockDescriptor.DensityCode = 0x83;

        IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, irp);
    }
}


BOOLEAN
CdRomIsPlayActive(
    IN PDEVICE_OBJECT DeviceObject
    )

/*++

Routine Description:

    This routine determines if the cd is currently playing music.

Arguments:

    DeviceObject - Device object to test.

Return Value:

    TRUE if the device is playing music.

--*/
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    IO_STATUS_BLOCK ioStatus = {0};
    PSUB_Q_CURRENT_POSITION currentBuffer;

    PAGED_CODE();

    //
    // if we don't think it is playing audio, don't bother checking.
    //

    if (!PLAY_ACTIVE(fdoExtension)) {
        return(FALSE);
    }

    currentBuffer = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                          sizeof(SUB_Q_CURRENT_POSITION),
                                          CDROM_TAG_PLAY_ACTIVE);

    if (currentBuffer == NULL) {
        return(FALSE);
    }

    ((PCDROM_SUB_Q_DATA_FORMAT) currentBuffer)->Format = IOCTL_CDROM_CURRENT_POSITION;
    ((PCDROM_SUB_Q_DATA_FORMAT) currentBuffer)->Track = 0;

    //
    // Build the synchronous request to be sent to ourself
    // to perform the request.
    //

    ClassSendDeviceIoControlSynchronous(
        IOCTL_CDROM_READ_Q_CHANNEL,
        DeviceObject,
        currentBuffer,
        sizeof(CDROM_SUB_Q_DATA_FORMAT),
        sizeof(SUB_Q_CURRENT_POSITION),
        FALSE,
        &ioStatus);

    if (!NT_SUCCESS(ioStatus.Status)) {
        ExFreePool(currentBuffer);
        return FALSE;
    }

    //
    // should update the playactive flag here.
    //

    if (currentBuffer->Header.AudioStatus == AUDIO_STATUS_IN_PROGRESS) {
        PLAY_ACTIVE(fdoExtension) = TRUE;
    } else {
        PLAY_ACTIVE(fdoExtension) = FALSE;
    }

    ExFreePool(currentBuffer);

    return(PLAY_ACTIVE(fdoExtension));

}


__control_entrypoint(DeviceDriver)
VOID
CdRomTickHandler(
    IN PDEVICE_OBJECT DeviceObject
    )

/*++

Routine Description:

    This routine handles the once per second timer provided by the
    Io subsystem.  It is used to do delayed retries for cdroms.

Arguments:

    DeviceObject - what to check.

Return Value:

    None.

--*/

{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = DeviceObject->DeviceExtension;

    ULONG isRemoved;

    KIRQL             oldIrql;

    PIRP              heldIrpList;
    PIRP              nextIrp;
    PLIST_ENTRY       listEntry;
    PCDROM_DATA       cddata;
    PIO_STACK_LOCATION irpStack;
    UCHAR             uniqueAddress;

    isRemoved = ClassAcquireRemoveLock(DeviceObject, (PIRP) &uniqueAddress);

    //
    // We stop the timer before deleting the device.  It's safe to keep going
    // if the flag value is REMOVE_PENDING because the removal thread will be
    // blocked trying to stop the timer.
    //

    ASSERT(isRemoved != REMOVE_COMPLETE);

    //
    // This routine is reasonably safe even if the device object has a pending
    // remove

    cddata = commonExtension->DriverData;

    //
    // Since cdrom is completely synchronized there can never be more than one
    // irp delayed for retry at any time.
    //

    KeAcquireSpinLock(&(cddata->DelayedRetrySpinLock), &oldIrql);

    if(cddata->DelayedRetryIrp != NULL) {

        PIRP irp = cddata->DelayedRetryIrp;

        //
        // If we've got a delayed retry at this point then there had beter
        // be an interval for it.
        //

        ASSERT(cddata->DelayedRetryInterval != 0);
        cddata->DelayedRetryInterval--;

        if(isRemoved) {

            //
            // This device is removed - flush the timer queue
            //

            cddata->DelayedRetryIrp = NULL;
            cddata->DelayedRetryInterval = 0;

            KeReleaseSpinLock(&(cddata->DelayedRetrySpinLock), oldIrql);

            ClassReleaseRemoveLock(DeviceObject, irp);

            //
            //Special work to be done for delayed retry IRP.
            //
            if (irp == cddata->UpdateCapacityIrp)
            {
                //
                //Release the resources and compelete associated IRP.
                //The UpdateCapacityIrp should not be completed as it's not sent out yet.
                //
                PIRP                originalIrp;
                PSCSI_REQUEST_BLOCK srb;

                irpStack = IoGetCurrentIrpStackLocation(irp);
                originalIrp = (PIRP)irpStack->Parameters.Others.Argument2;

                //
                //Complete the original IRP
                //

                if(originalIrp)
                {
                    originalIrp->IoStatus.Status = STATUS_INVALID_DEVICE_REQUEST;
                    originalIrp->IoStatus.Information = 0;
                    ClassCompleteRequest(DeviceObject, originalIrp, IO_CD_ROM_INCREMENT);
                }

                //
                // Release allocated resources.
                //

                irpStack = IoGetNextIrpStackLocation(irp);
                srb = (PSCSI_REQUEST_BLOCK)irpStack->Parameters.Scsi.Srb;
                if (srb)
                {
                    if (srb->SenseInfoBuffer)
                    {
                        ExFreePool(srb->SenseInfoBuffer);
                    }
                    if (srb->DataBuffer)
                    {
                        ExFreePool(srb->DataBuffer);
                    }
                    ExFreePool(srb);
                }
                if (irp->MdlAddress) 
                {
                    IoFreeMdl(irp->MdlAddress);
                }
                IoFreeIrp(irp);
                cddata->UpdateCapacityIrp = NULL;
            }
            else if (irp != cddata->Mmc.CapabilitiesIrp)
            {
                //
                //The CapabilitiesIrp should not be completed as it's not sent out yet.
                //
                ClassCompleteRequest(DeviceObject, irp, IO_CD_ROM_INCREMENT);
            }

        } else if (cddata->DelayedRetryInterval == 0) {

            //
            // Submit this IRP to the lower driver.  This IRP does not
            // need to be remembered here.  It will be handled again when
            // it completes.
            //

            cddata->DelayedRetryIrp = NULL;

            KeReleaseSpinLock(&(cddata->DelayedRetrySpinLock), oldIrql);

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,
                        "CdRomTickHandler: Reissuing request %p (thread = %p)\n",
                        irp,
                        irp->Tail.Overlay.Thread));

            //
            // feed this to the appropriate port driver
            //

            CdRomRerunRequest(fdoExtension, irp, cddata->DelayedRetryResend);
        } else {
            KeReleaseSpinLock(&(cddata->DelayedRetrySpinLock), oldIrql);
        }
    } else {
        KeReleaseSpinLock(&(cddata->DelayedRetrySpinLock), oldIrql);
    }

    ClassReleaseRemoveLock(DeviceObject, (PIRP) &uniqueAddress);
}


NTSTATUS
CdRomUpdateGeometryCompletion(
    PDEVICE_OBJECT DeviceObject,
    PIRP Irp,
    PVOID Context
    )

/*++

Routine Description:

    This routine andles the completion of the test unit ready irps
    used to determine if the media has changed.  If the media has
    changed, this code signals the named event to wake up other
    system services that react to media change (aka AutoPlay).

Arguments:

    DeviceObject - the object for the completion
    Irp - the IRP being completed
    Context - the SRB from the IRP

Return Value:

    NTSTATUS

--*/

{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension;
    PCDROM_DATA              cdData;

    PSCSI_REQUEST_BLOCK srb = (PSCSI_REQUEST_BLOCK) Context;
    PREAD_CAPACITY_DATA readCapacityBuffer;
    PIO_STACK_LOCATION  irpStack;
    NTSTATUS            status;
    BOOLEAN             retry;
    ULONG               retryCount;
    ULONG               lastSector;
    PIRP                originalIrp;
    UCHAR               uniqueAddress;

    //
    // Get items saved in the private IRP stack location.
    //

    irpStack = IoGetCurrentIrpStackLocation(Irp);
    retryCount = (ULONG)(ULONG_PTR) irpStack->Parameters.Others.Argument1;
    originalIrp = (PIRP) irpStack->Parameters.Others.Argument2;

    if (!DeviceObject) {
        DeviceObject = irpStack->DeviceObject;
    }
    ASSERT(DeviceObject);

    fdoExtension = DeviceObject->DeviceExtension;
    commonExtension = DeviceObject->DeviceExtension;
    cdData = (PCDROM_DATA)(commonExtension->DriverData);
    readCapacityBuffer = srb->DataBuffer;

    if ((NT_SUCCESS(Irp->IoStatus.Status)) && (SRB_STATUS(srb->SrbStatus) == SRB_STATUS_SUCCESS)) {

        CdRomInterpretReadCapacity(DeviceObject, readCapacityBuffer);

    } else {

        ULONG retryInterval;

        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_GENERAL,
                    "CdRomUpdateGeometryCompletion: [%p] unsuccessful "
                    "completion of buddy-irp %p (status - %lx)\n",
                    originalIrp, Irp, Irp->IoStatus.Status));

        if (srb->SrbStatus & SRB_STATUS_QUEUE_FROZEN) {
            ClassReleaseQueue(DeviceObject);
        }

        retry = ClassInterpretSenseInfo(DeviceObject,
                                        srb,
                                        IRP_MJ_SCSI,
                                        0,
                                        retryCount,
                                        &status,
                                        &retryInterval);
        if (retry) {
            retryCount--;
            if ((retryCount) && (commonExtension->IsRemoved == NO_REMOVE)) {
                PCDB cdb;

                TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,
                            "CdRomUpdateGeometryCompletion: [%p] Retrying "
                            "request %p .. thread is %p\n",
                            originalIrp, Irp, Irp->Tail.Overlay.Thread));

                //
                // set up a one shot timer to get this process started over
                //

                irpStack->Parameters.Others.Argument1 = ULongToPtr( retryCount );
                irpStack->Parameters.Others.Argument2 = (PVOID) originalIrp;
                irpStack->Parameters.Others.Argument3 = (PVOID) 2;

                //
                // Setup the IRP to be submitted again in the timer routine.
                //

                irpStack = IoGetNextIrpStackLocation(Irp);
                irpStack->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;
                irpStack->Parameters.DeviceIoControl.IoControlCode = IOCTL_SCSI_EXECUTE_IN;
                irpStack->Parameters.Scsi.Srb = srb;
                IoSetCompletionRoutine(Irp,
                                       CdRomUpdateGeometryCompletion,
                                       srb,
                                       TRUE,
                                       TRUE,
                                       TRUE);

                //
                // Set up the SRB for read capacity.
                //

                srb->CdbLength = 10;
                srb->TimeOutValue = fdoExtension->TimeOutValue;
                srb->SrbStatus = srb->ScsiStatus = 0;
                srb->NextSrb = 0;
                srb->Length = SCSI_REQUEST_BLOCK_SIZE;
                srb->Function = SRB_FUNCTION_EXECUTE_SCSI;
                srb->SrbFlags = fdoExtension->SrbFlags;
                SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
                SET_FLAG(srb->SrbFlags, SRB_FLAGS_DATA_IN);
                srb->DataTransferLength = sizeof(READ_CAPACITY_DATA);

                //
                // Set up the CDB
                //

                cdb = (PCDB) &srb->Cdb[0];
                cdb->CDB10.OperationCode = SCSIOP_READ_CAPACITY;

                //
                // Requests queued onto this list will be sent to the
                // lower level driver during CdRomTickHandler
                //

                CdRomRetryRequest(fdoExtension, Irp, retryInterval, TRUE);

                return STATUS_MORE_PROCESSING_REQUIRED;
            }

            if (commonExtension->IsRemoved != NO_REMOVE) {

                //
                // We cannot retry the request.  Fail it.
                //

                originalIrp->IoStatus.Status = STATUS_DEVICE_DOES_NOT_EXIST;

            } else {

                //
                // This has been bounced for a number of times.  Error the
                // original request.
                //

                originalIrp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;
                RtlZeroMemory(&(fdoExtension->DiskGeometry),
                              sizeof(DISK_GEOMETRY));
                fdoExtension->DiskGeometry.BytesPerSector = 2048;
                fdoExtension->SectorShift = 11;
                commonExtension->PartitionLength.QuadPart =
                    (LONGLONG)(0x7fffffff);
                fdoExtension->DiskGeometry.MediaType = RemovableMedia;
            }
        } else {

            //
            // Set up reasonable defaults
            //

            RtlZeroMemory(&(fdoExtension->DiskGeometry),
                          sizeof(DISK_GEOMETRY));
            fdoExtension->DiskGeometry.BytesPerSector = 2048;
            fdoExtension->SectorShift = 11;
            commonExtension->PartitionLength.QuadPart = (LONGLONG)(0x7fffffff);
            fdoExtension->DiskGeometry.MediaType = RemovableMedia;
        }
    }

    //
    // Free resources held.
    //

    ExFreePool(srb->SenseInfoBuffer);
    ExFreePool(srb->DataBuffer);
    ExFreePool(srb);
    if (Irp->MdlAddress) {
        IoFreeMdl(Irp->MdlAddress);
    }
    IoFreeIrp(Irp);
    Irp = NULL;

    //
    //Clear the value of UpdateCapacityIrp.
    //
    cdData->UpdateCapacityIrp = NULL;

    if (originalIrp->Tail.Overlay.Thread) {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,
                    "CdRomUpdateGeometryCompletion: [%p] completing "
                    "original IRP\n", originalIrp));

    } else {

        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_GENERAL,
                   "CdRomUpdateGeometryCompletion: completing irp %p which has "
                   "no thread\n", originalIrp));

    }

    {
        // NOTE: should the original irp be sent down to the device object?
        //       it probably should if the SL_OVERRIDER_VERIFY_VOLUME flag
        //       is set!
        KIRQL oldIrql;
        PIO_STACK_LOCATION realIrpStack;

        realIrpStack = IoGetCurrentIrpStackLocation(originalIrp);
        oldIrql = KeRaiseIrqlToDpcLevel();

        if (TEST_FLAG(realIrpStack->Flags, SL_OVERRIDE_VERIFY_VOLUME)) {
            CdRomStartIo(DeviceObject, originalIrp);
        } else {
            originalIrp->IoStatus.Status = STATUS_VERIFY_REQUIRED;
            originalIrp->IoStatus.Information = 0;
            CdRomCompleteIrpAndStartNextPacketSafely(DeviceObject, originalIrp);
        }
        KeLowerIrql(oldIrql);
    }

    return STATUS_MORE_PROCESSING_REQUIRED;
}


NTSTATUS
CdRomUpdateCapacity(
    IN PFUNCTIONAL_DEVICE_EXTENSION DeviceExtension,
    IN PIRP IrpToComplete,
    IN OPTIONAL PKEVENT IoctlEvent
    )

/*++

Routine Description:

    This routine updates the capacity of the disk as recorded in the device extension.
    It also completes the IRP given with STATUS_VERIFY_REQUIRED.  This routine is called
    when a media change has occurred and it is necessary to determine the capacity of the
    new media prior to the next access.

Arguments:

    DeviceExtension - the device to update
    IrpToComplete - the request that needs to be completed when done.

Return Value:

    NTSTATUS

--*/

{
    PCOMMON_DEVICE_EXTENSION commonExtension = (PCOMMON_DEVICE_EXTENSION) DeviceExtension;
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = (PFUNCTIONAL_DEVICE_EXTENSION) DeviceExtension;
    PCDROM_DATA cdData = (PCDROM_DATA)(commonExtension->DriverData);

    PCDB                cdb;
    PIRP                irp;
    PSCSI_REQUEST_BLOCK srb;
    PREAD_CAPACITY_DATA capacityBuffer;
    PIO_STACK_LOCATION  irpStack;
    PUCHAR              senseBuffer;
    NTSTATUS            status;

    irp = IoAllocateIrp((CCHAR)(commonExtension->DeviceObject->StackSize+1),
                        FALSE);

    if (irp) {

        //
        //update UpdateCapacityIrp
        //
        cdData->UpdateCapacityIrp = irp;

        srb = ExAllocatePoolWithTag(NonPagedPool,
                                    sizeof(SCSI_REQUEST_BLOCK),
                                    CDROM_TAG_UPDATE_CAP);
        if (srb) {
            capacityBuffer = ExAllocatePoolWithTag(
                                NonPagedPoolCacheAligned,
                                sizeof(READ_CAPACITY_DATA),
                                CDROM_TAG_UPDATE_CAP);

            if (capacityBuffer) {


                senseBuffer = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                                    SENSE_BUFFER_SIZE,
                                                    CDROM_TAG_UPDATE_CAP);

                if (senseBuffer) {

                    irp->MdlAddress = IoAllocateMdl(capacityBuffer,
                                                    sizeof(READ_CAPACITY_DATA),
                                                    FALSE,
                                                    FALSE,
                                                    (PIRP) NULL);

                    if (irp->MdlAddress) {

                        //
                        // Have all resources.  Set up the IRP to send for the capacity.
                        //

                        IoSetNextIrpStackLocation(irp);
                        irp->IoStatus.Status = STATUS_SUCCESS;
                        irp->IoStatus.Information = 0;
                        irp->Flags = 0;
                        irp->UserBuffer = NULL;

                        //
                        // Save the device object and retry count in a private stack location.
                        //

                        irpStack = IoGetCurrentIrpStackLocation(irp);
                        irpStack->DeviceObject = commonExtension->DeviceObject;
                        irpStack->Parameters.Others.Argument1 = (PVOID) MAXIMUM_RETRIES;
                        irpStack->Parameters.Others.Argument2 = (PVOID) IrpToComplete;

                        //
                        // Construct the IRP stack for the lower level driver.
                        //

                        irpStack = IoGetNextIrpStackLocation(irp);
                        irpStack->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;
                        irpStack->Parameters.DeviceIoControl.IoControlCode = IOCTL_SCSI_EXECUTE_IN;
                        irpStack->Parameters.Scsi.Srb = srb;
                        IoSetCompletionRoutine(irp,
                                               CdRomUpdateGeometryCompletion,
                                               srb,
                                               TRUE,
                                               TRUE,
                                               TRUE);
                        //
                        // Prepare the MDL
                        //

                        MmBuildMdlForNonPagedPool(irp->MdlAddress);


                        //
                        // Set up the SRB for read capacity.
                        //

                        RtlZeroMemory(srb, sizeof(SCSI_REQUEST_BLOCK));
                        RtlZeroMemory(senseBuffer, SENSE_BUFFER_SIZE);
                        srb->CdbLength = 10;
                        srb->TimeOutValue = DeviceExtension->TimeOutValue;
                        srb->SrbStatus = srb->ScsiStatus = 0;
                        srb->NextSrb = 0;
                        srb->Length = SCSI_REQUEST_BLOCK_SIZE;
                        srb->Function = SRB_FUNCTION_EXECUTE_SCSI;
                        srb->SrbFlags = DeviceExtension->SrbFlags;
                        SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
                        SET_FLAG(srb->SrbFlags, SRB_FLAGS_DATA_IN);
                        srb->DataBuffer = capacityBuffer;
                        srb->DataTransferLength = sizeof(READ_CAPACITY_DATA);
                        srb->OriginalRequest = irp;
                        srb->SenseInfoBuffer = senseBuffer;
                        srb->SenseInfoBufferLength = SENSE_BUFFER_SIZE;

                        //
                        // Set up the CDB
                        //

                        cdb = (PCDB) &srb->Cdb[0];
                        cdb->CDB10.OperationCode = SCSIOP_READ_CAPACITY;

                        //
                        // Set the return value in the IRP that will be completed
                        // upon completion of the read capacity.
                        //

                        IrpToComplete->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                        IoMarkIrpPending(IrpToComplete);

                        IoCallDriver(commonExtension->LowerDeviceObject, irp);

                        //
                        // status is not checked because the completion routine for this
                        // IRP will always get called and it will free the resources.
                        //

                        return STATUS_PENDING;

                    } else {
                        ExFreePool(senseBuffer);
                        ExFreePool(capacityBuffer);
                        ExFreePool(srb);
                        IoFreeIrp(irp);
                    }
                } else {
                    ExFreePool(capacityBuffer);
                    ExFreePool(srb);
                    IoFreeIrp(irp);
                }
            } else {
                ExFreePool(srb);
                IoFreeIrp(irp);
            }
        } else {
            IoFreeIrp(irp);
        }
    }

    //
    //Clear the value of UpdateCapacityIrp.
    //
    cdData->UpdateCapacityIrp = NULL;

    //
    // complete the original irp with a failure.
    // ISSUE-2000/07/05-henrygab - find a way to avoid failure.
    //

    RtlZeroMemory(&(fdoExtension->DiskGeometry),
                  sizeof(DISK_GEOMETRY));
    fdoExtension->DiskGeometry.BytesPerSector = 2048;
    fdoExtension->SectorShift = 11;
    commonExtension->PartitionLength.QuadPart =
        (LONGLONG)(0x7fffffff);
    fdoExtension->DiskGeometry.MediaType = RemovableMedia;

    IrpToComplete->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;
    IrpToComplete->IoStatus.Information = 0;

    TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_GENERAL, "Cdrom: [%p] Bailing with status %lx\n", IrpToComplete, IrpToComplete->IoStatus.Status));
    CdRomCompleteIrpAndStartNextPacketSafely(commonExtension->DeviceObject,
                                             IrpToComplete);
    return STATUS_INSUFFICIENT_RESOURCES;
}


__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomRemoveDevice(
    IN PDEVICE_OBJECT DeviceObject,
    IN UCHAR Type
    )

/*++

Routine Description:

    This routine is responsible for releasing any resources in use by the
    cdrom driver and shutting down it's timer routine.  This routine is called
    when all outstanding requests have been completed and the device has
    disappeared - no requests may be issued to the lower drivers.

Arguments:

    DeviceObject - the device object being removed

Return Value:

    none - this routine may not fail

--*/

{
    PFUNCTIONAL_DEVICE_EXTENSION deviceExtension =
        DeviceObject->DeviceExtension;

    PCDROM_DATA cdData = deviceExtension->CommonExtension.DriverData;

    PAGED_CODE();

    if((Type == IRP_MN_QUERY_REMOVE_DEVICE) ||
       (Type == IRP_MN_CANCEL_REMOVE_DEVICE)) {
        return STATUS_SUCCESS;
    }

    if(cdData->DelayedRetryIrp != NULL) {
        cdData->DelayedRetryInterval = 1;
        CdRomTickHandler(DeviceObject);
    }

    if (Type == IRP_MN_REMOVE_DEVICE){

        CdRomDeAllocateMmcResources(DeviceObject);
        ScratchBuffer_Deallocate(cdData);

        if (deviceExtension->DeviceDescriptor) {
            ExFreePool(deviceExtension->DeviceDescriptor);
            deviceExtension->DeviceDescriptor = NULL;
        }

        if (deviceExtension->AdapterDescriptor) {
            ExFreePool(deviceExtension->AdapterDescriptor);
            deviceExtension->AdapterDescriptor = NULL;
        }

        if (deviceExtension->SenseData) {
            ExFreePool(deviceExtension->SenseData);
            deviceExtension->SenseData = NULL;
        }

        if (cdData->CachedInquiryData) {
            ExFreePool(cdData->CachedInquiryData);
            cdData->CachedInquiryData = NULL;
            cdData->CachedInquiryDataByteCount = 0;
        }

        ASSERT(cdData->CachedInquiryDataByteCount == 0); // else Data would be non-NULL

        ClassDeleteSrbLookasideList(&deviceExtension->CommonExtension);
    }

    if(cdData->CdromInterfaceString.Buffer != NULL) {
        IoSetDeviceInterfaceState(
            &(cdData->CdromInterfaceString),
            FALSE);
        RtlFreeUnicodeString(&(cdData->CdromInterfaceString));
        RtlInitUnicodeString(&(cdData->CdromInterfaceString), NULL);
    }

    if(cdData->VolumeInterfaceString.Buffer != NULL) {
        IoSetDeviceInterfaceState(
            &(cdData->VolumeInterfaceString),
            FALSE);
        RtlFreeUnicodeString(&(cdData->VolumeInterfaceString));
        RtlInitUnicodeString(&(cdData->VolumeInterfaceString), NULL);
    }

    CdRomDeleteWellKnownName(DeviceObject);

    ASSERT(cdData->DelayedRetryIrp == NULL);

    if(Type == IRP_MN_REMOVE_DEVICE) {

        if (TEST_FLAG(cdData->HackFlags, CDROM_HACK_LOCKED_PAGES)) {

            //
            // unlock locked pages by locking (to get Mm pointer)
            // and then unlocking twice.
            //

            PVOID locked;

            if (TEST_FLAG(cdData->HackFlags, CDROM_HACK_HITACHI_1750)) {

                locked = MmLockPagableCodeSection(HitachiProcessError);

            } else if (TEST_FLAG(cdData->HackFlags, CDROM_HACK_HITACHI_GD_2000)) {

                locked = MmLockPagableCodeSection(HitachiProcessErrorGD2000);

            } else if (TEST_FLAG(cdData->HackFlags, CDROM_HACK_TOSHIBA_XM_3xx )) {

                locked = MmLockPagableCodeSection(ToshibaProcessError);

            } else {
                
                // this is a problem!
                // workaround by locking this twice, once for us and
                // once for the non-existant locker from ScanForSpecial
                PVOID locked2;
                ASSERT(!"hack flags show locked section, but none exists?");
                locked = MmLockPagableCodeSection(CdRomRemoveDevice);
                locked2 = MmLockPagableCodeSection(CdRomRemoveDevice);
                ASSERT( locked == locked2 );


            }

            MmUnlockPagableImageSection(locked);
            MmUnlockPagableImageSection(locked);

        }

        //
        // keep the system-wide count accurate, as
        // programs use this info to know when they
        // have found all the cdroms in a system.
        //

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_PNP,
                    "CDROM.SYS Remove device\n"));
        IoGetConfigurationInformation()->CdRomCount--;
    }

    //
    // so long, and thanks for all the fish!
    //

    return STATUS_SUCCESS;
}


NTSTATUS
CdRomCreateWellKnownName(
    IN PDEVICE_OBJECT DeviceObject
    )
/*++

Routine Description:

    This routine creates a symbolic link to the cdrom device object
    under \dosdevices.  The number of the cdrom device does not neccessarily
    match between \dosdevices and \device, but usually will be the same.

    Saves the buffer

Arguments:

    DeviceObject -

Return Value:

    NTSTATUS

--*/
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = DeviceObject->DeviceExtension;
    PCDROM_DATA cdromData = commonExtension->DriverData;

    UNICODE_STRING unicodeLinkName = {0};
    WCHAR wideLinkName[64] = {0};
    PWCHAR savedName;

    LONG cdromNumber = fdoExtension->DeviceNumber;

    NTSTATUS status;

    //
    // if already linked, assert then return
    //

    if (cdromData->WellKnownName.Buffer != NULL) {

        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_INIT,
                    "CdRomCreateWellKnownName: link already exists %p\n",
                    cdromData->WellKnownName.Buffer));
        ASSERT(FALSE);
        return STATUS_UNSUCCESSFUL;

    }

    //
    // find an unused CdRomNN to link to
    //

    do {

        status = RtlStringCchPrintfW(wideLinkName, RTL_NUMBER_OF(wideLinkName), L"\\DosDevices\\CdRom%d", cdromNumber);
        if (!NT_SUCCESS(status)) {
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_INIT,
                        "CdRomCreateWellKnownName: Format symbolic link failed with error: 0x%X\n", status));
            return status;
        }


        RtlInitUnicodeString(&unicodeLinkName, wideLinkName);
        status = IoCreateSymbolicLink(&unicodeLinkName,
                                      &(commonExtension->DeviceName));

        cdromNumber++;

    } while((status == STATUS_OBJECT_NAME_COLLISION) ||
            (status == STATUS_OBJECT_NAME_EXISTS));

    if (!NT_SUCCESS(status)) {

        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_INIT,
                    "CdRomCreateWellKnownName: Error %lx linking %wZ to "
                    "device %wZ\n",
                    status,
                    &unicodeLinkName,
                    &(commonExtension->DeviceName)));
        return status;

    }

    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                "CdRomCreateWellKnownName: successfully linked %wZ "
                "to device %wZ\n",
                &unicodeLinkName,
                &(commonExtension->DeviceName)));

    //
    // Save away the symbolic link name in the driver data block.  We need
    // it so we can delete the link when the device is removed.
    //

    savedName = ExAllocatePoolWithTag(PagedPool,
                                      unicodeLinkName.MaximumLength,
                                      CDROM_TAG_STRINGS);

    if (savedName == NULL) {
        IoDeleteSymbolicLink(&unicodeLinkName);
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    RtlCopyMemory(savedName,
                  unicodeLinkName.Buffer,
                  unicodeLinkName.MaximumLength);

    RtlInitUnicodeString(&(cdromData->WellKnownName), savedName);

    //
    // the name was saved and the link created
    //

    return STATUS_SUCCESS;
}


VOID
CdRomDeleteWellKnownName(
    IN PDEVICE_OBJECT DeviceObject
    )
{
    PCOMMON_DEVICE_EXTENSION commonExtension = DeviceObject->DeviceExtension;
    PCDROM_DATA cdromData = commonExtension->DriverData;

    if(cdromData->WellKnownName.Buffer != NULL) {

        IoDeleteSymbolicLink(&(cdromData->WellKnownName));
        ExFreePool(cdromData->WellKnownName.Buffer);
        cdromData->WellKnownName.Buffer = NULL;
        cdromData->WellKnownName.Length = 0;
        cdromData->WellKnownName.MaximumLength = 0;

    }
    return;
}


NTSTATUS
CdRomGetDeviceParameter (
    IN PDEVICE_OBJECT Fdo,
    __in IN PWSTR ParameterName,
    IN OUT PULONG ParameterValue
    )
/*++

Routine Description:

    retrieve a devnode registry parameter

Arguments:

    DeviceObject - Cdrom Device Object

    ParameterName - parameter name to look up

    ParameterValuse - default parameter value

Return Value:

    NT Status

--*/
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    NTSTATUS                 status;
    HANDLE                   deviceParameterHandle;
    RTL_QUERY_REGISTRY_TABLE queryTable[2] = {0};
    ULONG                    defaultParameterValue;

    PAGED_CODE();

    //
    // open the given parameter
    //
    status = IoOpenDeviceRegistryKey(fdoExtension->LowerPdo,
                                     PLUGPLAY_REGKEY_DRIVER,
                                     KEY_READ,
                                     &deviceParameterHandle);

    if(NT_SUCCESS(status)) {

        RtlZeroMemory(queryTable, sizeof(queryTable));

        defaultParameterValue = *ParameterValue;

        queryTable->Flags         = RTL_QUERY_REGISTRY_DIRECT | RTL_QUERY_REGISTRY_REQUIRED;
        queryTable->Name          = ParameterName;
        queryTable->EntryContext  = ParameterValue;
        queryTable->DefaultType   = REG_NONE;
        queryTable->DefaultData   = NULL;
        queryTable->DefaultLength = 0;

        status = RtlQueryRegistryValues(RTL_REGISTRY_HANDLE,
                                        (PWSTR) deviceParameterHandle,
                                        queryTable,
                                        NULL,
                                        NULL);
        if (!NT_SUCCESS(status)) {

            *ParameterValue = defaultParameterValue;
        }

        //
        // close what we open
        //
        ZwClose(deviceParameterHandle);
    }

    return status;

} // CdRomGetDeviceParameter


NTSTATUS
CdRomSetDeviceParameter (
    IN PDEVICE_OBJECT Fdo,
    __in IN PWSTR ParameterName,
    IN ULONG ParameterValue
    )
/*++

Routine Description:

    save a devnode registry parameter

Arguments:

    DeviceObject - Cdrom Device Object

    ParameterName - parameter name

    ParameterValuse - parameter value

Return Value:

    NT Status

--*/
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    NTSTATUS                 status;
    HANDLE                   deviceParameterHandle;

    PAGED_CODE();

    //
    // open the given parameter
    //
    status = IoOpenDeviceRegistryKey(fdoExtension->LowerPdo,
                                     PLUGPLAY_REGKEY_DRIVER,
                                     KEY_READ | KEY_WRITE,
                                     &deviceParameterHandle);

    if(NT_SUCCESS(status)) {

        status = RtlWriteRegistryValue(
                    RTL_REGISTRY_HANDLE,
                    (PWSTR) deviceParameterHandle,
                    ParameterName,
                    REG_DWORD,
                    &ParameterValue,
                    sizeof (ParameterValue));

        //
        // close what we open
        //
        ZwClose(deviceParameterHandle);
    }

    return status;

} // CdromSetDeviceParameter


VOID
CdRomPickDvdRegion(
    IN PDEVICE_OBJECT Fdo
    )
/*++

Routine Description:

    pick a default dvd region

Arguments:

    DeviceObject - Cdrom Device Object

Return Value:

    NT Status

--*/
{
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PCDROM_DATA cddata = (PCDROM_DATA)(commonExtension->DriverData);

    //
    // these five pointers all point to dvdReadStructure or part of
    // its data, so don't deallocate them more than once!
    //

    PDVD_READ_STRUCTURE dvdReadStructure;
    PDVD_COPY_PROTECT_KEY copyProtectKey;
    PDVD_COPYRIGHT_DESCRIPTOR dvdCopyRight;
    PDVD_RPC_KEY rpcKey;
    PDVD_SET_RPC_KEY dvdRpcKey;

    IO_STATUS_BLOCK ioStatus = {0};
    ULONG bufferLen;
    UCHAR mediaRegion;
    ULONG pickDvdRegion;
    ULONG defaultDvdRegion;
    ULONG dvdRegion;

    PAGED_CODE();

    if ((pickDvdRegion = InterlockedExchange(&cddata->PickDvdRegion, 0)) == 0) {

        //
        // it was non-zero, so either another thread will do this, or
        // we no longer need to pick a region
        //

        return;
    }

#ifdef ENABLE_RPC0
    //
    // short-circuit if license agreement violated
    //

    if (cddata->DvdRpc0LicenseFailure) {
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "DVD License failure.  Refusing to pick a region\n"));
        InterlockedExchange(&cddata->PickDvdRegion, 0);
        return;
    }
#endif // ENABLE_RPC0


    bufferLen = max(
                    max(sizeof(DVD_DESCRIPTOR_HEADER) +
                            sizeof(DVD_COPYRIGHT_DESCRIPTOR),
                        sizeof(DVD_READ_STRUCTURE)
                        ),
                    max(DVD_RPC_KEY_LENGTH,
                        DVD_SET_RPC_KEY_LENGTH
                        )
                    );

    dvdReadStructure = (PDVD_READ_STRUCTURE)
        ExAllocatePoolWithTag(PagedPool, bufferLen, DVD_TAG_DVD_REGION);

    if (dvdReadStructure == NULL) {
        InterlockedExchange(&cddata->PickDvdRegion, pickDvdRegion);
        return;
    }

#ifdef ENABLE_RPC0
    if (cddata->DvdRpc0Device && cddata->Rpc0RetryRegistryCallback) {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomPickDvdRegion (%p): now retrying RPC0 callback\n",
                    Fdo));

        //
        // get the registry settings again
        //

        ioStatus.Status = CdRomGetRpc0Settings(Fdo);

        if (ioStatus.Status == STATUS_LICENSE_VIOLATION) {

            //
            // if this is the returned error, then
            // the routine should have set this!
            //

            ASSERT(cddata->DvdRpc0LicenseFailure);
            cddata->DvdRpc0LicenseFailure = 1;
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "CdRomPickDvdRegion (%p): "
                        "setting to fail all dvd ioctls due to CSS licensing "
                        "failure.\n", Fdo));

            pickDvdRegion = 0;
            goto getout;

        }

        //
        // get the device region, again
        //

        copyProtectKey = (PDVD_COPY_PROTECT_KEY)dvdReadStructure;
        RtlZeroMemory(copyProtectKey, bufferLen);
        copyProtectKey->KeyLength = DVD_RPC_KEY_LENGTH;
        copyProtectKey->KeyType = DvdGetRpcKey;

        //
        // Build a request for READ_KEY
        //

        ClassSendDeviceIoControlSynchronous(
            IOCTL_DVD_READ_KEY,
            Fdo,
            copyProtectKey,
            DVD_RPC_KEY_LENGTH,
            DVD_RPC_KEY_LENGTH,
            FALSE,
            &ioStatus);

        if (!NT_SUCCESS(ioStatus.Status)) {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "CdRomPickDvdRegion: Unable to get "
                        "device RPC data (%x)\n", ioStatus.Status));
            pickDvdRegion = 0;
            goto getout;
        }

        //
        // now that we have gotten the device's RPC data,
        // we have set the device extension to usable data.
        // no need to call back into this section of code again
        //

        cddata->Rpc0RetryRegistryCallback = 0;


        rpcKey = (PDVD_RPC_KEY) copyProtectKey->KeyData;

        //
        // TypeCode of zero means that no region has been set.
        //

        if (rpcKey->TypeCode != 0) {
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "CdRomPickDvdRegion (%p): DVD Region already "
                        "chosen\n", Fdo));
            pickDvdRegion = 0;
            goto getout;
        }

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomPickDvdRegion (%p): must choose initial DVD "
                    " Region\n", Fdo));
    }
#endif // ENABLE_RPC0



    copyProtectKey = (PDVD_COPY_PROTECT_KEY) dvdReadStructure;

    dvdCopyRight = (PDVD_COPYRIGHT_DESCRIPTOR)
        ((PDVD_DESCRIPTOR_HEADER) dvdReadStructure)->Data;

    //
    // get the media region
    //

    RtlZeroMemory (dvdReadStructure, bufferLen);
    dvdReadStructure->Format = DvdCopyrightDescriptor;

    //
    // Build and send a request for READ_KEY
    //

    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                "CdRomPickDvdRegion (%p): Getting Copyright Descriptor\n",
                Fdo));

    ClassSendDeviceIoControlSynchronous(
        IOCTL_DVD_READ_STRUCTURE,
        Fdo,
        dvdReadStructure,
        sizeof(DVD_READ_STRUCTURE),
        sizeof (DVD_DESCRIPTOR_HEADER) +
        sizeof(DVD_COPYRIGHT_DESCRIPTOR),
        FALSE,
        &ioStatus
        );
    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                "CdRomPickDvdRegion (%p): Got Copyright Descriptor %x\n",
                Fdo, ioStatus.Status));

    if ((NT_SUCCESS(ioStatus.Status)) &&
        (dvdCopyRight->CopyrightProtectionType == 0x01)
        ) {

        //
        // keep the media region bitmap around
        // a 1 means ok to play
        //

        if (dvdCopyRight->RegionManagementInformation == 0xff) {
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                      "CdRomPickDvdRegion (%p): RegionManagementInformation "
                      "is set to dis-allow playback for all regions.  This is "
                      "most likely a poorly authored disc.  defaulting to all "
                      "region disc for purpose of choosing initial region\n",
                      Fdo));
            dvdCopyRight->RegionManagementInformation = 0;
        }


        mediaRegion = ~dvdCopyRight->RegionManagementInformation;

    } else {

        //
        // could be media, can't set the device region
        //

#ifdef ENABLE_RPC0
        if (!cddata->DvdRpc0Device) {
#endif // ENABLE_RPC0

            //
            // can't automatically pick a default region on a rpc2 drive
            // without media, so just exit
            //
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "CdRomPickDvdRegion (%p): failed to auto-choose "
                        "a region due to status %x getting copyright "
                        "descriptor\n", Fdo, ioStatus.Status));
            goto getout;

#ifdef ENABLE_RPC0
        } else {

            //
            // for an RPC0 drive, we can try to pick a region for
            // the drive
            //

            mediaRegion = 0x0;
        }
#endif // ENABLE_RPC0

    }

    //
    // get the device region
    //

    RtlZeroMemory (copyProtectKey, bufferLen);
    copyProtectKey->KeyLength = DVD_RPC_KEY_LENGTH;
    copyProtectKey->KeyType = DvdGetRpcKey;

    //
    // Build and send a request for READ_KEY for RPC key
    //

    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                "CdRomPickDvdRegion (%p): Getting RpcKey\n",
                Fdo));
    ClassSendDeviceIoControlSynchronous(
        IOCTL_DVD_READ_KEY,
        Fdo,
        copyProtectKey,
        DVD_RPC_KEY_LENGTH,
        DVD_RPC_KEY_LENGTH,
        FALSE,
        &ioStatus
        );
    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                "CdRomPickDvdRegion (%p): Got RpcKey %x\n",
                Fdo, ioStatus.Status));

    if (!NT_SUCCESS(ioStatus.Status)) {

        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "CdRomPickDvdRegion (%p): failed to get RpcKey from "
                    "a DVD Device\n", Fdo));
        goto getout;

    }

    //
    // so we now have what we can get for the media region and the
    // drive region.  we will not set a region if the drive has one
    // set already (mask is not all 1's), nor will we set a region
    // if there are no more user resets available.
    //

    rpcKey = (PDVD_RPC_KEY) copyProtectKey->KeyData;


    if (rpcKey->RegionMask != 0xff) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomPickDvdRegion (%p): not picking a region since "
                    "it is already chosen\n", Fdo));
        goto getout;
    }

    if (rpcKey->UserResetsAvailable <= 1) {
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "CdRomPickDvdRegion (%p): not picking a region since "
                    "only one change remains\n", Fdo));
        goto getout;
    }

    defaultDvdRegion = 0;

    //
    // the proppage dvd class installer sets
    // this key based upon the system locale
    //

    CdRomGetDeviceParameter (
        Fdo,
        DVD_DEFAULT_REGION,
        &defaultDvdRegion
        );

    if (defaultDvdRegion > DVD_MAX_REGION) {

        //
        // the registry has a bogus default
        //

        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "CdRomPickDvdRegion (%p): registry has a bogus default "
                    "region value of %x\n", Fdo, defaultDvdRegion));
        defaultDvdRegion = 0;

    }

    //
    // if defaultDvdRegion == 0, it means no default.
    //

    //
    // we will select the initial dvd region for the user
    //

    if ((defaultDvdRegion != 0) &&
        (mediaRegion &
         (1 << (defaultDvdRegion - 1))
         )
        ) {

        //
        // first choice:
        // the media has region that matches
        // the default dvd region.
        //

        dvdRegion = (1 << (defaultDvdRegion - 1));

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomPickDvdRegion (%p): Choice #1: media matches "
                    "drive's default, chose region %x\n", Fdo, dvdRegion));


    } else if (mediaRegion) {

        //
        // second choice:
        // pick the lowest region number
        // from the media
        //

        UCHAR mask;

        mask = 1;
        dvdRegion = 0;
        while (mediaRegion && !dvdRegion) {

            //
            // pick the lowest bit
            //
            dvdRegion = mediaRegion & mask;
            mask <<= 1;
        }

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomPickDvdRegion (%p): Choice #2: choosing lowest "
                    "media region %x\n", Fdo, dvdRegion));

    } else if (defaultDvdRegion) {

        //
        // third choice:
        // default dvd region from the dvd class installer
        //

        dvdRegion = (1 << (defaultDvdRegion - 1));
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomPickDvdRegion (%p): Choice #3: using default "
                    "region for this install %x\n", Fdo, dvdRegion));

    } else {

        //
        // unable to pick one for the user -- this should rarely
        // happen, since the proppage dvd class installer sets
        // the key based upon the system locale
        //
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "CdRomPickDvdRegion (%p): Choice #4: failed to choose "
                    "a media region\n", Fdo));
        goto getout;

    }

    //
    // now that we've chosen a region, set the region by sending the
    // appropriate request to the drive
    //

    RtlZeroMemory (copyProtectKey, bufferLen);
    copyProtectKey->KeyLength = DVD_SET_RPC_KEY_LENGTH;
    copyProtectKey->KeyType = DvdSetRpcKey;
    dvdRpcKey = (PDVD_SET_RPC_KEY) copyProtectKey->KeyData;
    dvdRpcKey->PreferredDriveRegionCode = (UCHAR) ~dvdRegion;

    //
    // Build and send request for SEND_KEY
    //
    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                "CdRomPickDvdRegion (%p): Sending new Rpc Key to region %x\n",
                Fdo, dvdRegion));

    ClassSendDeviceIoControlSynchronous(
        IOCTL_DVD_SEND_KEY2,
        Fdo,
        copyProtectKey,
        DVD_SET_RPC_KEY_LENGTH,
        0,
        FALSE,
        &ioStatus);
    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                "CdRomPickDvdRegion (%p): Sent new Rpc Key %x\n",
                Fdo, ioStatus.Status));

    if (!NT_SUCCESS(ioStatus.Status)) {
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL, "CdRomPickDvdRegion (%p): unable to set dvd initial "
                     " region code (%x)\n", Fdo, ioStatus.Status));
    } else {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "CdRomPickDvdRegion (%p): Successfully set dvd "
                     "initial region\n", Fdo));
        pickDvdRegion = 0;
    }

getout:
    if (dvdReadStructure) {
        ExFreePool (dvdReadStructure);
    }

    //
    // update the new PickDvdRegion value
    //

    InterlockedExchange(&cddata->PickDvdRegion, pickDvdRegion);

    return;
}


NTSTATUS
CdRomRetryRequest(
    IN PFUNCTIONAL_DEVICE_EXTENSION FdoExtension,
    IN PIRP Irp,
    IN ULONG Delay,
    IN BOOLEAN ResendIrp
    )
{
    PCDROM_DATA cdData;
    KIRQL oldIrql;

    if(Delay == 0) {
        return CdRomRerunRequest(FdoExtension, Irp, ResendIrp);
    }

    cdData = FdoExtension->CommonExtension.DriverData;

    KeAcquireSpinLock(&(cdData->DelayedRetrySpinLock), &oldIrql);

    ASSERT(cdData->DelayedRetryIrp == NULL);
    ASSERT(cdData->DelayedRetryInterval == 0);

    cdData->DelayedRetryIrp = Irp;
    cdData->DelayedRetryInterval = Delay;
    cdData->DelayedRetryResend = ResendIrp;

    KeReleaseSpinLock(&(cdData->DelayedRetrySpinLock), oldIrql);

    return STATUS_PENDING;
}


NTSTATUS
CdRomRerunRequest(
    IN PFUNCTIONAL_DEVICE_EXTENSION FdoExtension,
    IN OPTIONAL PIRP Irp,
    IN BOOLEAN ResendIrp
    )
{
    if(ResendIrp) {
        return IoCallDriver(FdoExtension->CommonExtension.LowerDeviceObject,
                            Irp);
    } else {
        KIRQL oldIrql;

        oldIrql = KeRaiseIrqlToDpcLevel();
        CdRomStartIo(FdoExtension->DeviceObject, Irp);
        KeLowerIrql(oldIrql);
        return STATUS_MORE_PROCESSING_REQUIRED;
    }
}


/*++

Routine Description:

    This routine just checks for media change sense/asc/ascq and
    also for other events, such as bus resets.  this is used to
    determine if the device behaviour has changed, to allow for
    read and write operations to be allowed and/or disallowed.

Arguments:

    ISSUE-2000/3/30-henrygab - not fully doc'd

Return Value:

    NTSTATUS

--*/
NTSTATUS
CdRomMmcErrorHandler(
    IN PDEVICE_OBJECT Fdo,
    IN PSCSI_REQUEST_BLOCK Srb,
    OUT PNTSTATUS Status,
    OUT PBOOLEAN Retry
    )
{
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PCDROM_DATA cdData = (PCDROM_DATA) commonExtension->DriverData;
    BOOLEAN queryCapabilities = FALSE;
    BOOLEAN mediaChange = FALSE;
    PCDB cdb = (PCDB)Srb->Cdb;

    if (TEST_FLAG(Srb->SrbStatus, SRB_STATUS_AUTOSENSE_VALID)) {

        PCDROM_DATA cddata = (PCDROM_DATA)commonExtension->DriverData;
        PSENSE_DATA senseBuffer = Srb->SenseInfoBuffer;

        //
        // the following sense keys could indicate a change in
        // capabilities.
        //

        //
        // we used to expect this to be serialized, and only hit from our
        // own routine. we now allow some requests to continue during our
        // processing of the capabilities update in order to allow
        // IoReadPartitionTable() to succeed.
        //

        switch (senseBuffer->SenseKey & 0xf) {

        case SCSI_SENSE_NOT_READY: {
            if (senseBuffer->AdditionalSenseCode ==
                SCSI_ADSENSE_NO_MEDIA_IN_DEVICE) {

                if (cddata->Mmc.WriteAllowed) {
                    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,
                               "CdromErrorHandler: media removed, writes will be "
                               "failed until new media detected\n"));
                }

                // NOTE - REF #0002
                cddata->Mmc.WriteAllowed = FALSE;
            } else
            if (senseBuffer->AdditionalSenseCode == SCSI_ADSENSE_LUN_NOT_READY) {

                if (senseBuffer->AdditionalSenseCodeQualifier ==
                    SCSI_SENSEQ_BECOMING_READY) {
                    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,
                               "CdromErrorHandler: media becoming ready, "
                               "SHOULD notify shell of change time by sending "
                               "GESN request immediately!\n"));
                } else if (((senseBuffer->AdditionalSenseCodeQualifier ==
                             SCSI_SENSEQ_OPERATION_IN_PROGRESS) ||
                            (senseBuffer->AdditionalSenseCodeQualifier ==
                             SCSI_SENSEQ_LONG_WRITE_IN_PROGRESS)
                            ) &&
                           ((Srb->Cdb[0] == SCSIOP_READ) ||
                            (Srb->Cdb[0] == SCSIOP_READ6) ||
                            (Srb->Cdb[0] == SCSIOP_READ_CAPACITY) ||
                            (Srb->Cdb[0] == SCSIOP_READ_CD) ||
                            (Srb->Cdb[0] == SCSIOP_READ_CD_MSF) ||
                            (Srb->Cdb[0] == SCSIOP_READ_TOC) ||
                            (Srb->Cdb[0] == SCSIOP_WRITE) ||
                            (Srb->Cdb[0] == SCSIOP_WRITE6) ||
                            (Srb->Cdb[0] == SCSIOP_READ_TRACK_INFORMATION) ||
                            (Srb->Cdb[0] == SCSIOP_READ_DISK_INFORMATION)
                            )
                           ) {
                    TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_GENERAL,
                               "CdromErrorHandler: LONG_WRITE or "
                               "OP_IN_PROGRESS for limited subset of cmds -- "
                               "setting retry to TRUE\n"));
                    *Retry = TRUE;
                    *Status = STATUS_DEVICE_BUSY;
                }
            }
            break;
        } // end SCSI_SENSE_NOT_READY

        case SCSI_SENSE_UNIT_ATTENTION: {
            switch (senseBuffer->AdditionalSenseCode) {
            case SCSI_ADSENSE_MEDIUM_CHANGED: {

                //
                // always update if the medium may have changed
                //

                // NOTE - REF #0002
                cddata->Mmc.WriteAllowed = FALSE;
                InterlockedCompareExchange(&(cddata->Mmc.UpdateState),
                                           CdromMmcUpdateRequired,
                                           CdromMmcUpdateComplete);

                TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,
                           "CdromErrorHandler: media change detected, need to "
                           "update drive capabilities\n"));
                mediaChange = TRUE;
                break;

            } // end SCSI_ADSENSE_MEDIUM_CHANGED

            case SCSI_ADSENSE_BUS_RESET: {

                // NOTE - REF #0002
                cddata->Mmc.WriteAllowed = FALSE;
                InterlockedCompareExchange(&(cddata->Mmc.UpdateState),
                                           CdromMmcUpdateRequired,
                                           CdromMmcUpdateComplete);

                TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,
                           "CdromErrorHandler: bus reset detected, need to "
                           "update drive capabilities\n"));
                break;

            } // end SCSI_ADSENSE_BUS_RESET

            case SCSI_ADSENSE_OPERATOR_REQUEST: {

                BOOLEAN b = FALSE;

                switch (senseBuffer->AdditionalSenseCodeQualifier) {
                case SCSI_SENSEQ_MEDIUM_REMOVAL: {

                    //
                    // eject notification currently handled by classpnp
                    //

                    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,
                               "CdromErrorHandler: Eject requested by user\n"));
                    *Retry = TRUE;
                    *Status = STATUS_DEVICE_BUSY;
                    break;
                }

                case SCSI_SENSEQ_WRITE_PROTECT_DISABLE:
                    b = TRUE;
                case SCSI_SENSEQ_WRITE_PROTECT_ENABLE: {

                    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,
                               "CdromErrorHandler: Write protect %s requested "
                               "by user\n",
                               (b ? "disable" : "enable")));
                    *Retry = TRUE;
                    *Status = STATUS_DEVICE_BUSY;
                    // NOTE - REF #0002
                    cddata->Mmc.WriteAllowed = FALSE;
                    InterlockedCompareExchange(&(cddata->Mmc.UpdateState),
                                               CdromMmcUpdateRequired,
                                               CdromMmcUpdateComplete);
                    break;

                }

                } // end of AdditionalSenseCodeQualifier switch


                break;

            } // end SCSI_ADSENSE_OPERATOR_REQUEST

            default: {
                TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_GENERAL,
                           "CdromErrorHandler: Unit attention %02x/%02x\n",
                           senseBuffer->AdditionalSenseCode,
                           senseBuffer->AdditionalSenseCodeQualifier));
                break;
            }

            } // end of AdditionSenseCode switch
            break;

        } // end SCSI_SENSE_UNIT_ATTENTION

        case SCSI_SENSE_ILLEGAL_REQUEST: {
            if (senseBuffer->AdditionalSenseCode == SCSI_ADSENSE_WRITE_PROTECT) {

                if (cddata->Mmc.WriteAllowed) {
                    TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_GENERAL,
                               "CdromErrorHandler: media was writable, but "
                               "failed request with WRITE_PROTECT error...\n"));
                }
                // NOTE - REF #0002
                // do not update all the capabilities just because
                // we can't write to the disc.
                cddata->Mmc.WriteAllowed = FALSE;
            }
            break;
        } // end SCSI_SENSE_ILLEGAL_REQUEST

        } // end of SenseKey switch

        // Check if we failed to set the DVD region key and send appropriate error
        if (cdb->CDB16.OperationCode == SCSIOP_SEND_KEY) {
            if (cdb->SEND_KEY.KeyFormat == DvdSetRpcKey) {
                if (senseBuffer->AdditionalSenseCode == SCSI_ADSENSE_NO_MEDIA_IN_DEVICE) {
                    // media of appropriate region required
                    *Status = STATUS_NO_MEDIA_IN_DEVICE;
                    *Retry = FALSE;
                } else if ((senseBuffer->SenseKey == SCSI_SENSE_ILLEGAL_REQUEST) &&
                           (senseBuffer->AdditionalSenseCode == SCSI_ADSENSE_COPY_PROTECTION_FAILURE) &&
                           (senseBuffer->AdditionalSenseCodeQualifier == SCSI_SENSEQ_MEDIA_CODE_MISMATCHED_TO_LOGICAL_UNIT)) {
                    // media of appropriate region required
                    *Status = STATUS_CSS_REGION_MISMATCH;
                    *Retry = FALSE;
                } else if ((senseBuffer->SenseKey == SCSI_SENSE_ILLEGAL_REQUEST) &&
                           (senseBuffer->AdditionalSenseCode == SCSI_ADSENSE_INVALID_MEDIA) &&
                           (senseBuffer->AdditionalSenseCodeQualifier == SCSI_SENSEQ_INCOMPATIBLE_FORMAT)) {
                    // media of appropriate region required
                    *Status = STATUS_CSS_REGION_MISMATCH;
                    *Retry = FALSE;
                }
            }
        }
    } // end of SRB_STATUS_AUTOSENSE_VALID

    //
    // On media change, if device speed should be reset to default then
    // queue a workitem to send the commands to the device. Do this on
    // media arrival as some device will fail this command if no media
    // is present. Ignore the fake media change from classpnp driver.
    //

    if ((mediaChange == TRUE) && (*Status != STATUS_MEDIA_CHANGED)) {

        if (cdData->RestoreDefaults == TRUE) {

            PIO_WORKITEM workItem;

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL, "CdRomMmcErrorHandler: Restore device default speed for %p\n", Fdo));

            workItem = IoAllocateWorkItem(Fdo);

            if (workItem) {
                IoQueueWorkItem(workItem, CdRomRestoreDefaultSpeed, DelayedWorkQueue, workItem);
                cdData->RestoreDefaults = FALSE;
            }
        }
    }
    return STATUS_SUCCESS;
}

/*++

Routine Description:

    This routine checks for a device-specific error handler
    and calls it if it exists.  This allows multiple drives
    that require their own error handler to co-exist.

--*/
__control_entrypoint(DeviceDriver)
VOID
CdRomErrorHandler(
    PDEVICE_OBJECT DeviceObject,
    PSCSI_REQUEST_BLOCK Srb,
    NTSTATUS *Status,
    BOOLEAN *Retry
    )
{
    PCOMMON_DEVICE_EXTENSION commonExtension = DeviceObject->DeviceExtension;
    PCDROM_DATA cddata = (PCDROM_DATA)commonExtension->DriverData;
    PSENSE_DATA sense = Srb->SenseInfoBuffer;

    if ((Srb->SenseInfoBufferLength >=
         RTL_SIZEOF_THROUGH_FIELD(SENSE_DATA,AdditionalSenseCodeQualifier)) &&
        TEST_FLAG(Srb->SrbStatus, SRB_STATUS_AUTOSENSE_VALID)) {

        //
        //  Many non-WHQL certified drives (mostly CD-RW) return
        //  2/4/0 when they have no media instead of the obvious
        //  choice of:
        //
        //      SCSI_SENSE_NOT_READY/SCSI_ADSENSE_NO_MEDIA_IN_DEVICE
        //
        //  These drives should not pass WHQL certification due
        //  to this discrepency.
        //
        //  However, we have to retry on 2/4/0 (Not ready, LUN not ready,
        //  no info) and also 3/2/0 (no seek complete).
        //
        //  These conditions occur when the shell tries to examine an
        //  injected CD (e.g. for autoplay) before the CD is spun up.
        //
        //  The drive should be returning an ASCQ of SCSI_SENSEQ_BECOMING_READY
        //  (0x01) in order to comply with WHQL standards.
        //
        //  The default retry timeout of one second is acceptable to balance
        //  these discrepencies.  don't modify the status, though....
        //

        if (((sense->SenseKey & 0xf) == SCSI_SENSE_NOT_READY) &&
            (sense->AdditionalSenseCode == SCSI_ADSENSE_LUN_NOT_READY) &&
            (sense->AdditionalSenseCodeQualifier == SCSI_SENSEQ_CAUSE_NOT_REPORTABLE)
            ) {

            *Retry = TRUE;

        } else if (((sense->SenseKey & 0xf) == SCSI_SENSE_NOT_READY) &&
            (sense->AdditionalSenseCode == SCSI_ADSENSE_LUN_NOT_READY) &&
            (sense->AdditionalSenseCodeQualifier == SCSI_SENSEQ_LONG_WRITE_IN_PROGRESS)
            ) {

            //
            // This has been seen as a transcient failure on some drives
            //

            *Retry = TRUE;

        } else if (((sense->SenseKey & 0xf) == SCSI_SENSE_MEDIUM_ERROR) &&
                   (sense->AdditionalSenseCode == SCSI_ADSENSE_NO_SEEK_COMPLETE) &&
                   (sense->AdditionalSenseCodeQualifier == 0x00)
                   ) {

            *Retry = TRUE;

        } else if ((sense->AdditionalSenseCode == 0x57) &&
                   (sense->AdditionalSenseCodeQualifier == 0x00)
                   ) {

            //
            // UNABLE_TO_RECOVER_TABLE_OF_CONTENTS
            // the Matshita CR-585 returns this for all read commands
            // on blank CD-R and CD-RW media, and we need to handle
            // this for READ_CD detection ability.
            //

            *Retry = FALSE;
            *Status = STATUS_UNRECOGNIZED_MEDIA;

        }

    } else {
        //
        // If get configuration command is failing and if the request type is TYPE ONE
        // then most likely the device does not support this request type. Set the
        // flag so that the TYPE ONE requests will be tried as TYPE ALL requets.
        //
        if ((SRB_STATUS(Srb->SrbStatus) != SRB_STATUS_SUCCESS) &&
            (SRB_STATUS(Srb->SrbStatus) != SRB_STATUS_DATA_OVERRUN) &&
            (((PCDB)Srb->Cdb)->CDB10.OperationCode == SCSIOP_GET_CONFIGURATION) &&
            (((PCDB)Srb->Cdb)->GET_CONFIGURATION.RequestType == SCSI_GET_CONFIGURATION_REQUEST_TYPE_ONE)) {

            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_GENERAL,
                       "CdromErrorHandler: TYPE ONE GetConfiguration failed. Set hack flag and retry.\n"));
            SET_FLAG(cddata->HackFlags, CDROM_HACK_BAD_TYPE_ONE_GET_CONFIG);
            *Retry = TRUE;
        }
    }

    //
    // tail recursion in both cases takes no stack
    //

    if (cddata->ErrorHandler) {
        cddata->ErrorHandler(DeviceObject, Srb, Status, Retry);
    }
    return;
}


/*++

Routine Description:

    This routine is called for a shutdown and flush IRPs.
    These are sent by the system before it actually shuts
    down or when the file system does a flush.

Arguments:

    DriverObject - Pointer to device object to being shutdown by system.

    Irp - IRP involved.

Return Value:

    NT Status

--*/
__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomShutdownFlush(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    )
{
    IoMarkIrpPending(Irp);
    IoStartPacket(DeviceObject, Irp, NULL, NULL);
    return STATUS_PENDING;

}

/*++

Routine Description:

    This routine is called for intermediate work a shutdown or
    flush IRPs would need to do.  We just want to free our resources
    and return STATUS_MORE_PROCESSING_REQUIRED.

Arguments:

    DeviceObject - NULL?

    Irp - IRP to free

    Context - NULL

Return Value:

    NT Status

--*/
NTSTATUS
CdRomShutdownFlushCompletion(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP NewIrp,
    IN PIRP OriginalIrp
    )
{
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PIO_STACK_LOCATION originalIrpStack;
    ULONG_PTR iteration;
    NTSTATUS status = STATUS_SUCCESS;

    ASSERT(OriginalIrp);

    originalIrpStack = IoGetCurrentIrpStackLocation(OriginalIrp);

    //
    // always use a new irp so we can call
    // CdRomCompleteIrpAndStartNextPacketSafely() from this routine.
    //

    if (NewIrp != NULL) {
        status = NewIrp->IoStatus.Status;
        IoFreeIrp(NewIrp);
        NewIrp = NULL;
    }

    if (!NT_SUCCESS(status)) {
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_GENERAL, "Cdrom: [%p] Bailing with status %lx\n", OriginalIrp, OriginalIrp->IoStatus.Status));
        goto SafeExit;
    }

    //
    // the current irpstack saves the counter which states
    // what part of the multi-part shutdown or flush we are in.
    //

    iteration = (ULONG_PTR)originalIrpStack->Parameters.Others.Argument1;
    iteration++;
    originalIrpStack->Parameters.Others.Argument1 = (PVOID)iteration;

    switch (iteration) {
    case 2:
        if (originalIrpStack->MajorFunction != IRP_MJ_SHUTDOWN) {
            //
            // then we don't want to send the unlock command
            // the incrementing of the state was done above.
            // return the completion routine's result.
            //
            return CdRomShutdownFlushCompletion(Fdo, NULL, OriginalIrp);
        }
        // else fall through....

    case 1: {

        PIRP                newIrp = NULL;
        PSCSI_REQUEST_BLOCK newSrb = NULL;
        PCDB                newCdb = NULL;
        PIO_STACK_LOCATION  newIrpStack = NULL;
        ULONG               isRemoved;

        newIrp = IoAllocateIrp((CCHAR)(Fdo->StackSize+1), FALSE);
        if (newIrp == NULL) {
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_GENERAL, "Cdrom: [%p] Bailing with status %lx\n", OriginalIrp, OriginalIrp->IoStatus.Status));
            status = STATUS_INSUFFICIENT_RESOURCES;
            goto SafeExit;
        }
        newSrb = ExAllocatePoolWithTag(NonPagedPool,
                                        sizeof(SCSI_REQUEST_BLOCK),
                                        CDROM_TAG_SRB);
        if (newSrb == NULL) {
            IoFreeIrp(newIrp);
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_GENERAL, "Cdrom: [%p] Bailing with status %lx\n", OriginalIrp, OriginalIrp->IoStatus.Status));
            status = STATUS_INSUFFICIENT_RESOURCES;
            goto SafeExit;
        }

        //
        // ClassIoComplete will free the SRB, but we need a routine
        // that will free the irp.  then just call ClassSendAsync,
        // and don't care about the return value, since the completion
        // routine will be called anyways.
        //

        IoSetNextIrpStackLocation(newIrp);
        newIrpStack = IoGetCurrentIrpStackLocation(newIrp);
        newIrpStack->DeviceObject = Fdo;
        IoSetCompletionRoutine(newIrp,
                               CdRomShutdownFlushCompletion,
                               OriginalIrp,
                               TRUE, TRUE, TRUE);
        IoSetNextIrpStackLocation(newIrp);
        newIrpStack = IoGetCurrentIrpStackLocation(newIrp);
        newIrpStack->DeviceObject = Fdo;

        //
        // setup the request
        //

        RtlZeroMemory(newSrb, sizeof(SCSI_REQUEST_BLOCK));
        newCdb = (PCDB)(newSrb->Cdb);

        newSrb->QueueTag = SP_UNTAGGED;
        newSrb->QueueAction = SRB_SIMPLE_TAG_REQUEST;
        newSrb->Function = SRB_FUNCTION_EXECUTE_SCSI;

        //
        // tell classpnp not to call StartNextPacket()
        //

        newSrb->SrbFlags = SRB_FLAGS_DONT_START_NEXT_PACKET;

        if (iteration == 1) {

            //
            // first synchronize the cache
            //

            newSrb->TimeOutValue = fdoExtension->TimeOutValue * 4;
            newSrb->CdbLength = 10;
            newCdb->SYNCHRONIZE_CACHE10.OperationCode = SCSIOP_SYNCHRONIZE_CACHE;

        } else if (iteration == 2) {

            //
            // then unlock the medium
            //

            ASSERT( originalIrpStack->MajorFunction == IRP_MJ_SHUTDOWN );

            newSrb->TimeOutValue = fdoExtension->TimeOutValue;
            newSrb->CdbLength = 6;
            newCdb->MEDIA_REMOVAL.OperationCode = SCSIOP_MEDIUM_REMOVAL;
            newCdb->MEDIA_REMOVAL.Prevent = FALSE;

        }


        isRemoved = ClassAcquireRemoveLock(Fdo, newIrp);
        if (isRemoved) {
            IoFreeIrp(newIrp);
            ExFreePool(newSrb);
            ClassReleaseRemoveLock(Fdo, newIrp);
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_GENERAL, "Cdrom: [%p] Bailing with status %lx\n", OriginalIrp, OriginalIrp->IoStatus.Status));
            status = STATUS_DEVICE_DOES_NOT_EXIST;
            goto SafeExit;
        }
        ClassSendSrbAsynchronous(Fdo, newSrb, newIrp, NULL, 0, FALSE);
        break;
    }

    case 3: {

        PSCSI_REQUEST_BLOCK srb;
        PIO_STACK_LOCATION nextIrpStack = IoGetNextIrpStackLocation(OriginalIrp);

        //
        // forward this request to the device appropriately,
        // don't use this completion routine anymore...
        //

        srb = ExAllocatePoolWithTag(NonPagedPool,
                                    sizeof(SCSI_REQUEST_BLOCK),
                                    CDROM_TAG_SRB);
        if (srb == NULL) {
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_GENERAL, "Cdrom: [%p] Bailing with status %lx\n", OriginalIrp, OriginalIrp->IoStatus.Status));
            status = STATUS_INSUFFICIENT_RESOURCES;
            goto SafeExit;
        }

        RtlZeroMemory(srb, SCSI_REQUEST_BLOCK_SIZE);
        srb->Length = SCSI_REQUEST_BLOCK_SIZE;
        srb->TimeOutValue = fdoExtension->TimeOutValue * 4;
        srb->QueueTag = SP_UNTAGGED;
        srb->QueueAction = SRB_SIMPLE_TAG_REQUEST;
        srb->SrbFlags = fdoExtension->SrbFlags;
        srb->CdbLength = 0;
        srb->OriginalRequest = OriginalIrp;

        if (originalIrpStack->MajorFunction == IRP_MJ_SHUTDOWN) {
            srb->Function = SRB_FUNCTION_SHUTDOWN;
        } else {
            srb->Function = SRB_FUNCTION_FLUSH;
        }

        //
        // Set up IoCompletion routine address.
        //

        IoSetCompletionRoutine(OriginalIrp,
                               ClassIoComplete,
                               srb,
                               TRUE, TRUE, TRUE);

        //
        // Set the retry count to zero.
        //

        originalIrpStack->Parameters.Others.Argument4 = (PVOID) 0;

        //
        // Get next stack location and set major function code.
        //

        nextIrpStack->MajorFunction = IRP_MJ_SCSI;

        //
        // Set up SRB for execute scsi request.
        // Save SRB address in next stack for port driver.
        //

        nextIrpStack->Parameters.Scsi.Srb = srb;

        //
        // Call the port driver to process the request.
        //

        IoCallDriver(commonExtension->LowerDeviceObject, OriginalIrp);

        break;

    }
    default: {
        ASSERT(FALSE);
        break;
    }

    } // end switch

    status = STATUS_SUCCESS;

SafeExit:

    if (!NT_SUCCESS(status)) {
        OriginalIrp->IoStatus.Status = status;
        CdRomCompleteIrpAndStartNextPacketSafely(Fdo, OriginalIrp);
    }

    //
    // always return STATUS_MORE_PROCESSING_REQUIRED, so noone else tries
    // to access the new irp that we free'd....
    //

    return STATUS_MORE_PROCESSING_REQUIRED;

} // end CdromShutdownFlush()


VOID
CdromFakePartitionInfo(
    IN PCOMMON_DEVICE_EXTENSION CommonExtension,
    IN PIRP Irp
    )
{
    PIO_STACK_LOCATION currentIrpStack = IoGetCurrentIrpStackLocation(Irp);
    ULONG ioctl = currentIrpStack->Parameters.DeviceIoControl.IoControlCode;
    PVOID systemBuffer = Irp->AssociatedIrp.SystemBuffer;

    ASSERT(systemBuffer);

    if ((ioctl != IOCTL_DISK_GET_DRIVE_LAYOUT) &&
        (ioctl != IOCTL_DISK_GET_DRIVE_LAYOUT_EX) &&
        (ioctl != IOCTL_DISK_GET_PARTITION_INFO) &&
        (ioctl != IOCTL_DISK_GET_PARTITION_INFO_EX)) {
        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_GENERAL,
                    "CdromFakePartitionInfo: unhandled ioctl %x\n", ioctl));
        Irp->IoStatus.Status = STATUS_INTERNAL_ERROR;
        Irp->IoStatus.Information = 0;
        CdRomCompleteIrpAndStartNextPacketSafely(CommonExtension->DeviceObject,
                                                 Irp);
        return;
    }

    //
    // nothing to fail from this point on, so set the size appropriately
    // and set irp's status to success.
    //

    TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_GENERAL,
                "CdromFakePartitionInfo: incoming ioctl %x\n", ioctl));


    Irp->IoStatus.Status = STATUS_SUCCESS;
    switch (ioctl) {
    case IOCTL_DISK_GET_DRIVE_LAYOUT:
        Irp->IoStatus.Information = FIELD_OFFSET(DRIVE_LAYOUT_INFORMATION,
                                                 PartitionEntry[1]);
        RtlZeroMemory(systemBuffer, FIELD_OFFSET(DRIVE_LAYOUT_INFORMATION,
                                                 PartitionEntry[1]));
        break;
    case IOCTL_DISK_GET_DRIVE_LAYOUT_EX:
        Irp->IoStatus.Information = FIELD_OFFSET(DRIVE_LAYOUT_INFORMATION_EX,
                                                 PartitionEntry[1]);
        RtlZeroMemory(systemBuffer, FIELD_OFFSET(DRIVE_LAYOUT_INFORMATION_EX,
                                                 PartitionEntry[1]));
        break;
    case IOCTL_DISK_GET_PARTITION_INFO:
        Irp->IoStatus.Information = sizeof(PARTITION_INFORMATION);
        RtlZeroMemory(systemBuffer, sizeof(PARTITION_INFORMATION));
        break;
    case IOCTL_DISK_GET_PARTITION_INFO_EX:
        Irp->IoStatus.Information = sizeof(PARTITION_INFORMATION_EX);
        RtlZeroMemory(systemBuffer, sizeof(PARTITION_INFORMATION_EX));
        break;
    default:
        ASSERT(!"Invalid ioctl should not have reached this point\n");
        break;
    }

    //
    // if we are getting the drive layout, then we need to start by
    // adding some of the non-partition stuff that says we have
    // exactly one partition available.
    //


    if (ioctl == IOCTL_DISK_GET_DRIVE_LAYOUT) {

        PDRIVE_LAYOUT_INFORMATION layout;
        layout = (PDRIVE_LAYOUT_INFORMATION)systemBuffer;
        layout->PartitionCount = 1;
        layout->Signature = 1;
        systemBuffer = (PVOID)(layout->PartitionEntry);
        ioctl = IOCTL_DISK_GET_PARTITION_INFO;

    } else if (ioctl == IOCTL_DISK_GET_DRIVE_LAYOUT_EX) {

        PDRIVE_LAYOUT_INFORMATION_EX layoutEx;
        layoutEx = (PDRIVE_LAYOUT_INFORMATION_EX)systemBuffer;
        layoutEx->PartitionStyle = PARTITION_STYLE_MBR;
        layoutEx->PartitionCount = 1;
        layoutEx->Mbr.Signature = 1;
        systemBuffer = (PVOID)(layoutEx->PartitionEntry);
        ioctl = IOCTL_DISK_GET_PARTITION_INFO_EX;

    }

    //
    // NOTE: the local var 'ioctl' is now modified to either EX or
    // non-EX version. the local var 'systemBuffer' is now pointing
    // to the partition information structure.
    //

    if (ioctl == IOCTL_DISK_GET_PARTITION_INFO) {

        PPARTITION_INFORMATION partitionInfo;
        partitionInfo = (PPARTITION_INFORMATION)systemBuffer;
        partitionInfo->RewritePartition = FALSE;
        partitionInfo->RecognizedPartition = TRUE;
        partitionInfo->PartitionType = PARTITION_FAT32;
        partitionInfo->BootIndicator = FALSE;
        partitionInfo->HiddenSectors = 0;
        partitionInfo->StartingOffset.QuadPart = 0;
        partitionInfo->PartitionLength = CommonExtension->PartitionLength;
        partitionInfo->PartitionNumber = 0;

    } else {

        PPARTITION_INFORMATION_EX partitionInfo;
        partitionInfo = (PPARTITION_INFORMATION_EX)systemBuffer;
        partitionInfo->PartitionStyle = PARTITION_STYLE_MBR;
        partitionInfo->RewritePartition = FALSE;
        partitionInfo->Mbr.RecognizedPartition = TRUE;
        partitionInfo->Mbr.PartitionType = PARTITION_FAT32;
        partitionInfo->Mbr.BootIndicator = FALSE;
        partitionInfo->Mbr.HiddenSectors = 0;
        partitionInfo->StartingOffset.QuadPart = 0;
        partitionInfo->PartitionLength = CommonExtension->PartitionLength;
        partitionInfo->PartitionNumber = 0;

    }
    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,
                "CdromFakePartitionInfo: finishing ioctl %x\n",
                currentIrpStack->Parameters.DeviceIoControl.IoControlCode));

    //
    // complete the irp
    //

    CdRomCompleteIrpAndStartNextPacketSafely(CommonExtension->DeviceObject,
                                             Irp);
    return;

}



NTSTATUS
CdRomSetRawReadInfo(
    PDEVICE_OBJECT Fdo
    )
/*++

Routine Description:

    This routine reads the CDROM capabilities mode page and save information
    in the device extension needed for raw reads.

Arguments:

    Fdo

Return Value:

    NT Status

--*/
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PCDROM_DATA cddata = (PCDROM_DATA)(commonExtension->DriverData);
    PUCHAR buffer = NULL;
    NTSTATUS status;
    ULONG count;

    PAGED_CODE();

    //
    // Check whether the device can return C2 error flag bits and the block
    // error byte.  If so, save this info and fill in appropriate flag during
    // raw read requests.
    //

    //
    // Start by checking the GET_CONFIGURATION data
    //
    {
        PFEATURE_DATA_CD_READ cdReadHeader;
        ULONG additionalLength = sizeof(FEATURE_DATA_CD_READ) - sizeof(FEATURE_HEADER);

        cdReadHeader = CdRomFindFeaturePage(cddata->Mmc.CapabilitiesBuffer,
                                            cddata->Mmc.CapabilitiesBufferSize,
                                            FeatureCdRead);

        if ((cdReadHeader != NULL) &&
            (cdReadHeader->Header.AdditionalLength >= additionalLength) &&
            (cdReadHeader->C2ErrorData)
            ) {
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                      "FDO %p GET_CONFIG shows ability to read C2 error bits\n",
                      Fdo
                      ));
            cddata->Mmc.ReadCdC2Pointers = TRUE;    // Device returns C2 error info.
        }
    }

    //
    // Unfortunately, the only way to check for the ability to read R-W subcode
    // information is via MODE_SENSE.  Do so here, and check the C2 bit as well
    // in case the drive has a firmware bug where it fails to report this ability
    // in GET_CONFIG (which some drives do).
    //

    for (count = 0; count < 6; count++) {

        SCSI_REQUEST_BLOCK srb = {0};
        PCDB cdb;
        ULONG bufferLength;

        RtlZeroMemory(&srb, sizeof(srb));
        cdb = (PCDB)srb.Cdb;

        //
        // Build the MODE SENSE CDB.  Try 10-byte CDB first.
        //

        if ((count/3) == 0) {

            bufferLength = sizeof(CDVD_CAPABILITIES_PAGE)  +
                           sizeof(MODE_PARAMETER_HEADER10) +
                           sizeof(MODE_PARAMETER_BLOCK);

            cdb->MODE_SENSE10.OperationCode = SCSIOP_MODE_SENSE10;
            cdb->MODE_SENSE10.Dbd = 1;
            cdb->MODE_SENSE10.PageCode = MODE_PAGE_CAPABILITIES;
            cdb->MODE_SENSE10.AllocationLength[0] = (UCHAR)(bufferLength >> 8);
            cdb->MODE_SENSE10.AllocationLength[1] = (UCHAR)(bufferLength >> 0);
            srb.CdbLength = 10;

        } else {

            bufferLength = sizeof(CDVD_CAPABILITIES_PAGE) +
                           sizeof(MODE_PARAMETER_HEADER)  +
                           sizeof(MODE_PARAMETER_BLOCK);

            cdb->MODE_SENSE.OperationCode = SCSIOP_MODE_SENSE;
            cdb->MODE_SENSE.Dbd = 1;
            cdb->MODE_SENSE.PageCode = MODE_PAGE_CAPABILITIES;
            cdb->MODE_SENSE.AllocationLength = (UCHAR)bufferLength;
            srb.CdbLength = 6;
        }

        //
        // Set timeout value from device extension.
        //
        srb.TimeOutValue = fdoExtension->TimeOutValue;

        buffer = ExAllocatePoolWithTag(NonPagedPool, bufferLength, CDROM_TAG_MODE_DATA);

        if (buffer == NULL) {
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                      "CdRomSetRawReadInfo: cannot allocate "
                      "buffer, so not setting raw read info for FDO %p\n",
                      Fdo
                      ));
            status = STATUS_INSUFFICIENT_RESOURCES;
            goto FnExit;
        }

        RtlZeroMemory(buffer, bufferLength);

        status = ClassSendSrbSynchronous(
                     Fdo,
                     &srb,
                     buffer,
                     bufferLength,
                     FALSE);

        if (NT_SUCCESS(status) ||
            (status == STATUS_DATA_OVERRUN) ||
            (status == STATUS_BUFFER_OVERFLOW))
        {
            PCDVD_CAPABILITIES_PAGE capabilities = NULL;
            ULONG capabilitiesLength = 0;

            // determine where the capabilities page really is
            if ((count/3) == 0) {
                PMODE_PARAMETER_HEADER10 p = (PMODE_PARAMETER_HEADER10)buffer;
                capabilities =
                    (PCDVD_CAPABILITIES_PAGE)(buffer +
                                              sizeof(MODE_PARAMETER_HEADER10) +
                                              (p->BlockDescriptorLength[0] * 256) +
                                              p->BlockDescriptorLength[1]
                                              );
            } else {
                PMODE_PARAMETER_HEADER p = (PMODE_PARAMETER_HEADER)buffer;
                capabilities =
                    (PCDVD_CAPABILITIES_PAGE)(buffer +
                                              sizeof(MODE_PARAMETER_HEADER) +
                                              p->BlockDescriptorLength
                                              );
            }

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                      "FDO %p CDVD Capabilities buffer %p\n",
                      Fdo,
                      buffer
                      ));

            if (capabilities->PageCode == MODE_PAGE_CAPABILITIES) {

                if (capabilities->C2Pointers) {

                    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                              "FDO %p supports C2 error bits in READ_CD command\n",
                              Fdo
                              ));
                    cddata->Mmc.ReadCdC2Pointers = TRUE;
                }

                if (capabilities->RWSupported) {

                    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                              "FDO %p supports raw subcode in READ_CD command\n",
                              Fdo
                              ));
                    cddata->Mmc.ReadCdSubCode = TRUE;
                }

                break;
            }
        }

        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                  "FDO %p failed %x byte mode sense, status %x\n",
                  Fdo,
                  (((count/3) == 0) ? 10 : 6),
                  status
                  ));

        ExFreePool(buffer);
        buffer = NULL;
    }

    if (count == 6) {

        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                  "CdRomGetRawReadInfo: FDO %p "
                  "couldn't get mode sense data\n",
                  Fdo
                  ));
    }

FnExit:

    if (buffer) {
        ExFreePool(buffer);
    }

    return status;
}

NTSTATUS
CdRomPowerHandler(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    )
/*++

Routine Description:

    This routine is called when a power IRP is received. If the request
    is for powering up from hibernation or standby, then it will
    invalidate the MMC capabilities cached by the CDROM driver. The actual
    update will take place when the next I/O is received. Then it will
    call the default power handler in the classpnp driver.

Arguments:

    DeviceObject    - Device object
    Irp             - Power IRP

Return Value:

    NT Status returned by ClassSpinDownPowerHandler.

--*/
{
    PIO_STACK_LOCATION irpStack = IoGetCurrentIrpStackLocation(Irp);

    //
    // If we invalidate the state during power down, then any I/O request
    // received immediately after the power request could trigger the
    // update and we will lose the update required request upon power up.
    // So invalidate the state during power up. Also do this only for
    // the system power IRP.
    //

    if ((irpStack->MinorFunction == IRP_MN_SET_POWER) &&
        (irpStack->Parameters.Power.Type == SystemPowerState) &&
        (irpStack->Parameters.Power.State.SystemState == PowerSystemWorking)) {

        PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
        PCDROM_DATA cdData = (PCDROM_DATA)(fdoExtension->CommonExtension.DriverData);

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_POWER, "CdRomPowerHandler: System powering up. Invalidate MMC capabilities\n"));

        InterlockedCompareExchange(&(cdData->Mmc.UpdateState),
                               CdromMmcUpdateRequired,
                               CdromMmcUpdateComplete);
    }
    return ClassSpinDownPowerHandler(DeviceObject,Irp);
}

NTSTATUS
CdRomCreateClose(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP Irp
    )
/*++

Routine Description:

    This routine is called when a create or close IRP is received.
    If a close IRP is received, this function checks whether the device
    is in exclusive mode. If it is and the close request is from the
    exclusive owner, then the caller did not unlock the device. So this
    function will unlock the device for normal use.

Arguments:

    DeviceObject    - Device object
    Irp             - Create/Close IRP

Return Value:

    NT Status.

--*/
{
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PIO_STACK_LOCATION irpStack = IoGetCurrentIrpStackLocation(Irp);
    NTSTATUS status = STATUS_SUCCESS;

    if (irpStack->MajorFunction == IRP_MJ_CLOSE) {

        PCDROM_DATA cdData = (PCDROM_DATA)commonExtension->DriverData;

        if (EXCLUSIVE_MODE(cdData) && EXCLUSIVE_OWNER(cdData, irpStack->FileObject)) {

            //
            // We have received a close while in exclusive mode.
            // This could happen if the owner did not send unlock IOCTL
            // or the application terminated. Make sure this is from the
            // owner and unlock the device.
            //

            return CdRomUnlockDevice(Fdo, Irp);
        }
    }

    ClassReleaseRemoveLock(Fdo, Irp);
    ClassCompleteRequest(Fdo, Irp, IO_NO_INCREMENT);
    return STATUS_SUCCESS;
}

PVOID
CdRomAllocateDataBuffer(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb,
    IN ULONG TransferLength,
    IN ULONG Tag
    )
/*++

Routine Description:

    This routine allocates a buffer and builds an MDL for using with
    an IOCTL request. This also sets the DataBuffer and DataTransferLength
    in the given SRB. In case of failure this will complete the failed
    request and start the next request.

Arguments:

    Fdo             - Device object
    OriginalIrp     - IRP with the IOCTL request
    NewIrp          - IRP_MJ_SCSI IRP targeted for the lower driver
    Srb             - SRB for the new request
    TransferLength  - The size of the data buffer
    Tag             - Tag for the buffer

Return Value:

    Pointer to the allocated data buffer. NULL on failure.

--*/
{
    PVOID dataBuffer;

    dataBuffer = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                       TransferLength,
                                       Tag);
    if (dataBuffer != NULL) {

        NewIrp->MdlAddress = IoAllocateMdl(dataBuffer,
                                        TransferLength,
                                        FALSE,
                                        FALSE,
                                        (PIRP) NULL);
        if (NewIrp->MdlAddress != NULL) {
            RtlZeroMemory(dataBuffer, TransferLength);
            Srb->DataBuffer = dataBuffer;
            Srb->DataTransferLength = TransferLength;
            MmBuildMdlForNonPagedPool(NewIrp->MdlAddress);
            return dataBuffer;
        }
    }
    if (dataBuffer != NULL) {
        ExFreePool(dataBuffer);
    }
    ExFreePool(Srb->SenseInfoBuffer);
    ExFreePool(Srb);
    IoFreeIrp(NewIrp);
    OriginalIrp->IoStatus.Information = 0;
    OriginalIrp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;
    TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", OriginalIrp, OriginalIrp->IoStatus.Status));
    CdRomCompleteIrpAndStartNextPacketSafely(Fdo, OriginalIrp);
    return NULL;
}


/*++

Routine Description:

    This routine zeros out the scratch buffer.

Arguments:

    CdData - Pointer to CDROM device extension for this logical unit.

Return Value:

    None

--*/
VOID
ScratchBuffer_ResetItems(
    __in PCDROM_DATA CdData,
    BOOLEAN ResetRequestHistory
    )
{
    ASSERT(CdData->ScratchHistory    != NULL);
    ASSERT(CdData->ScratchSense      != NULL);
    ASSERT(CdData->ScratchSrb        != NULL);
    ASSERT(CdData->ScratchIrp        != NULL);
    ASSERT(CdData->ScratchBufferSize != 0);
    ASSERT(CdData->ScratchBuffer     != NULL);
    ASSERT(CdData->ScratchBufferMdl  != NULL);
    ASSERT(CdData->ScratchInUse      != 0);

    if (ResetRequestHistory)
    {
        PSRB_HISTORY history = CdData->ScratchHistory;
        RtlZeroMemory(history->History, sizeof(SRB_HISTORY_ITEM) * history->TotalHistoryCount);
        history->ClassDriverUse[0] = 0;
        history->ClassDriverUse[1] = 0;
        history->ClassDriverUse[2] = 0;
        history->ClassDriverUse[3] = 0;
        history->UsedHistoryCount  = 0;
    }

    RtlZeroMemory(CdData->ScratchSense, sizeof(SENSE_DATA));
    RtlZeroMemory(CdData->ScratchSrb, sizeof(SCSI_REQUEST_BLOCK));
    IoReuseIrp(CdData->ScratchIrp, STATUS_NOT_SUPPORTED);
    KeClearEvent(&CdData->ScratchEvent);

    return;
}

VOID
ScratchBuffer_SendSynchronousSrb(
    __in PFUNCTIONAL_DEVICE_EXTENSION FdoExtension
    )
{
    PCDROM_DATA cdData = FdoExtension->CommonExtension.DriverData;
    PSCSI_REQUEST_BLOCK srb = cdData->ScratchSrb;
    PSRB_HISTORY history = cdData->ScratchHistory;
    PSRB_HISTORY_ITEM item;
    NTSTATUS status;

    // NOTE: SRBs typically IGNORE the status value returned in the IRP(!)
    // We cannot reliably use the status from the IoStatus.Status block.
    // What a broken architecture....  Work around it by starting with errors....
    srb->InternalStatus = STATUS_INTERNAL_ERROR;
    srb->SrbStatus = SRB_STATUS_INTERNAL_ERROR;

    // update history pre-command
    {
        // sending a packet implies a new history unit is to be used.
        ASSERT( history->UsedHistoryCount <= history->TotalHistoryCount );
    
        // if already all used up, remove at least one history unit
        if (history->UsedHistoryCount == history->TotalHistoryCount )
        {
            CompressSrbHistoryData(FdoExtension->DeviceObject, history);
            ASSERT( history->UsedHistoryCount < history->TotalHistoryCount );
        }
    
        // thus, since we are about to increment the count, it must now be less...
        ASSERT( history->UsedHistoryCount < history->TotalHistoryCount );
    
        // increment the number of history units in use
        history->UsedHistoryCount++;
    
        // determine index to use
        item = &( history->History[ history->UsedHistoryCount-1 ] );
    
        // zero out the history item
        RtlZeroMemory(item, sizeof(SRB_HISTORY_ITEM));
    
        // Query the tick count and store in the history
        KeQueryTickCount(&item->TickCountSent);
    }


    // Send the request and wait for it to complete
    status = IoCallDriver(FdoExtension->CommonExtension.LowerDeviceObject, cdData->ScratchIrp);
    if (status == STATUS_PENDING)
    {
        KeWaitForSingleObject(&(cdData->ScratchEvent), Executive, KernelMode, FALSE, NULL);
    }

    // update this history block, including "normalized" sense data
    {
        ULONG senseSize;

        // Query the tick count and store in the history
        KeQueryTickCount(&item->TickCountCompleted);
    
        // Copy the SRB Status...
        item->SrbStatus = srb->SrbStatus;
    
        // Determine the amount of valid sense data
        if (srb->SenseInfoBufferLength >= RTL_SIZEOF_THROUGH_FIELD(SENSE_DATA, AdditionalSenseLength))
        {
            PSENSE_DATA sense = (PSENSE_DATA)srb->SenseInfoBuffer;
            senseSize =
                RTL_SIZEOF_THROUGH_FIELD(SENSE_DATA, AdditionalSenseLength) +
                sense->AdditionalSenseLength;
            senseSize = min(senseSize, sizeof(SENSE_DATA));
        }
        else
        {
            senseSize = srb->SenseInfoBufferLength;
        }

        // Normalize the sense data copy in the history
        RtlZeroMemory(&(item->NormalizedSenseData), sizeof(SENSE_DATA));
        RtlCopyMemory(&(item->NormalizedSenseData),
                      srb->SenseInfoBuffer,
                      senseSize
                      );
    }

    return;
}

VOID
ScratchBuffer_SetupForSynchronousSrb(
    __in PFUNCTIONAL_DEVICE_EXTENSION FdoExtension,
    __in ULONG   MaximumTransferLength,
    __in BOOLEAN GetDataFromDevice
    )
{
    PCDROM_DATA cdData = (PCDROM_DATA)(FdoExtension->CommonExtension.DriverData);
    PIRP irp = cdData->ScratchIrp;
    PSCSI_REQUEST_BLOCK srb = cdData->ScratchSrb;
    PIO_STACK_LOCATION irpStack;

    // prepare the irp to have a valid "current" irpstack
    IoSetNextIrpStackLocation(irp);

    // the Irp must show the MDL's address for the transfer
    irp->MdlAddress = cdData->ScratchBufferMdl;

    // set to use the full scratch buffer via the scratch SRB
    irpStack = IoGetNextIrpStackLocation(irp);
    irpStack->MajorFunction = IRP_MJ_SCSI;
    irpStack->Parameters.DeviceIoControl.IoControlCode = IOCTL_SCSI_EXECUTE_IN;
    irpStack->Parameters.Scsi.Srb = srb;
    IoSetCompletionRoutine(irp, CdRompSendSrbSynchronousCompletion, &(cdData->ScratchEvent), TRUE, TRUE, TRUE);
    KeClearEvent(&cdData->ScratchEvent);

    // prepare the SRB with default values
    srb->Length = SCSI_REQUEST_BLOCK_SIZE;
    srb->Function = SRB_FUNCTION_EXECUTE_SCSI;
    srb->QueueAction = SRB_SIMPLE_TAG_REQUEST;
    srb->SrbStatus = 0;
    srb->ScsiStatus = 0;
    srb->NextSrb = NULL;
    srb->OriginalRequest = irp;
    srb->SenseInfoBufferLength = SENSE_BUFFER_SIZE;
    srb->SenseInfoBuffer = cdData->ScratchSense;

    srb->CdbLength = 16; // to cause failures if not set correctly -- CD devices limited to 12 bytes for now...

    srb->DataBuffer = cdData->ScratchBuffer;
    srb->DataTransferLength = min(cdData->ScratchBufferSize, MaximumTransferLength);
    srb->TimeOutValue = FdoExtension->TimeOutValue;
    srb->SrbFlags = FdoExtension->SrbFlags;
    SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
    SET_FLAG(srb->SrbFlags, SRB_FLAGS_NO_QUEUE_FREEZE);

    if (MaximumTransferLength == 0)
    {
        NOTHING;
    }
    else if (GetDataFromDevice)
    {
        SET_FLAG(srb->SrbFlags, SRB_FLAGS_DATA_IN);
    }
    else
    {
        SET_FLAG(srb->SrbFlags, SRB_FLAGS_DATA_OUT);
    }

    return;
}

NTSTATUS
CdRompSendSrbSynchronousCompletion(
    __in_opt PDEVICE_OBJECT DeviceObject,
    __in PIRP Irp,
    __in PKEVENT Context
    )
{
    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,
                "CdRompSendSynchronousCompletion: %p %p %p\n",
                DeviceObject, Irp, Context
                ));
    UNREFERENCED_PARAMETER(DeviceObject);
    KeSetEvent(Context, IO_NO_INCREMENT, FALSE);
    return STATUS_MORE_PROCESSING_REQUIRED;
}

BOOLEAN
ScratchBuffer_InterpretSrbError(
    __in PFUNCTIONAL_DEVICE_EXTENSION FdoExtension,
    __in ULONG TimesAlreadyRetried,
    __out NTSTATUS * Status,
    __out __range(0,MAXIMUM_RETRY_FOR_SINGLE_IO_IN_100NS_UNITS)
    LONGLONG * RetryIn100nsUnits
    )
{
    PCDROM_DATA cdData = FdoExtension->CommonExtension.DriverData;
    BOOLEAN retry;

    ASSERT(cdData->ScratchInUse != 0);

    if (SRB_STATUS(cdData->ScratchSrb->SrbStatus) == SRB_STATUS_SUCCESS)
    {
        *Status = STATUS_SUCCESS;
        *RetryIn100nsUnits = 0;
        retry = FALSE;
    }
    else
    {
        retry = InterpretSenseInfo2(
            FdoExtension->DeviceObject,
            cdData->ScratchIrp,
            cdData->ScratchSrb,
            IRP_MJ_SCSI,
            IOCTL_SCSI_EXECUTE_IN,
            TimesAlreadyRetried,
            cdData->ScratchHistory,
            Status,
            RetryIn100nsUnits
            );
    }
    return retry;
}

/*++

Routine Description:

    This routine frees the scratch buffer/mdl, if allocated.

Arguments:

    CdData - Pointer to CDROM device extension for this logical unit.

Return Value:

    None

--*/
VOID
ScratchBuffer_Deallocate(
    __in PCDROM_DATA Cddata
    )
{
    ASSERT(Cddata->ScratchInUse == 0);

    if (Cddata->ScratchHistory != NULL)
    {
        ExFreePool(Cddata->ScratchHistory);
        Cddata->ScratchHistory = NULL;
    }
    if (Cddata->ScratchSense != NULL)
    {
        ExFreePool(Cddata->ScratchSense);
        Cddata->ScratchSense = NULL;
    }
    if (Cddata->ScratchSrb != NULL)
    {
        ExFreePool(Cddata->ScratchSrb);
        Cddata->ScratchSrb = NULL;
    }
    if (Cddata->ScratchIrp != NULL)
    {
        IoFreeIrp(Cddata->ScratchIrp);
        Cddata->ScratchIrp = NULL;
    }
    if (Cddata->ScratchBufferSize != 0)
    {
        Cddata->ScratchBufferSize = 0;
    }
    if (Cddata->ScratchBufferMdl != NULL)
    {
        IoFreeMdl(Cddata->ScratchBufferMdl);
        Cddata->ScratchBufferMdl = NULL;
    }
    if (Cddata->ScratchBuffer != NULL)
    {
        ExFreePool(Cddata->ScratchBuffer);
        Cddata->ScratchBuffer = NULL;
    }
    return;
}

/*++

Routine Description:

    This routine allocated the scratch buffer for the logical unit.

Arguments:

    CdData - Pointer to CDROM device extension for this logical unit.

Return Value:

    TRUE if was able to allocate the buffer/mdl.
    FALSE otherwise

--*/
BOOLEAN
ScratchBuffer_Allocate(
    __in PCDROM_DATA Cddata,
    __in CCHAR IrpStackSizeRequired
    )
{
    NTSTATUS status = STATUS_SUCCESS;

    ASSERT(Cddata->ScratchInUse == 0);

    // quick-exit if already allocated
    if ((Cddata->ScratchBuffer     != NULL) &&
        (Cddata->ScratchBufferMdl  != NULL) &&
        (Cddata->ScratchBufferSize != 0)    &&
        (Cddata->ScratchIrp        != NULL) &&
        (Cddata->ScratchSrb        != NULL) &&
        (Cddata->ScratchHistory    != NULL)
        )
    {
        return TRUE;
    }

    // validate max transfer already determined
    ASSERT(Cddata->MaxPageAlignedTransferBytes != 0);

    // validate no partially-saved state
    ASSERT(Cddata->ScratchBuffer     == NULL);
    ASSERT(Cddata->ScratchBufferMdl  == NULL);
    ASSERT(Cddata->ScratchBufferSize == 0);
    ASSERT(Cddata->ScratchIrp        == NULL);

    // limit the scratch buffer to between 4k and 64k (so data length fits into USHORT -- req'd for many commands)
    Cddata->ScratchBufferSize = min(Cddata->MaxPageAlignedTransferBytes, (64*1024));
    Cddata->ScratchBufferSize = max(Cddata->ScratchBufferSize,           PAGE_SIZE);

    // allocate the buffer
    if (NT_SUCCESS(status))
    {
        Cddata->ScratchBuffer = ExAllocatePoolWithTag(NonPagedPool,
                                                      Cddata->ScratchBufferSize,
                                                      CDROM_TAG_SCRATCH
                                                      );
        if (Cddata->ScratchBuffer == NULL)
        {
            status = STATUS_INSUFFICIENT_RESOURCES;
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                        "Failed to allocate scratch buffer of %x bytes\n",
                        Cddata->ScratchBufferSize
                        ));
        }
        else if (BYTE_OFFSET(Cddata->ScratchBuffer) != 0)
        {
            status = STATUS_INTERNAL_ERROR;
            TracePrint((TRACE_LEVEL_FATAL, TRACE_FLAG_INIT,
                        "Allocation of %x bytes non-paged pool was not "
                        "allocated on page boundary?  STATUS_INTERNAL_ERROR\n",
                        Cddata->ScratchBufferSize
                        ));
        }
    }

    // allocate the MDL
    if (NT_SUCCESS(status))
    {
        Cddata->ScratchBufferMdl =
            IoAllocateMdl(Cddata->ScratchBuffer,
                          Cddata->ScratchBufferSize,
                          FALSE, FALSE, NULL
                          );
        if (Cddata->ScratchBufferMdl == NULL)
        {
            status = STATUS_INSUFFICIENT_RESOURCES;
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                        "Failed to allocate MDL for %x byte buffer\n",
                        Cddata->ScratchBufferSize
                        ));
        }
        else
        {
            MmBuildMdlForNonPagedPool(Cddata->ScratchBufferMdl);
        }
    }

    // allocate the Irp
    if (NT_SUCCESS(status))
    {
        Cddata->ScratchIrp = IoAllocateIrp(IrpStackSizeRequired, FALSE);
        if (Cddata->ScratchIrp == NULL)
        {
            status = STATUS_INSUFFICIENT_RESOURCES;
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                        "Failed to allocate scratch MDL for %x stack size\n",
                        IrpStackSizeRequired
                        ));
        }
    }

    // allocate the srb
    if (NT_SUCCESS(status))
    {
        Cddata->ScratchSrb = ExAllocatePoolWithTag(NonPagedPool,
                                                   sizeof(SCSI_REQUEST_BLOCK),
                                                   CDROM_TAG_SCRATCH
                                                   );
        if (Cddata->ScratchSrb == NULL)
        {
            status = STATUS_INSUFFICIENT_RESOURCES;
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                        "Failed to allocate scratch SRB\n"
                        ));
        }
    }

    // allocate the sense buffer
    if (NT_SUCCESS(status))
    {
        Cddata->ScratchSense = ExAllocatePoolWithTag(NonPagedPool,
                                                     sizeof(SENSE_DATA),
                                                     CDROM_TAG_SCRATCH
                                                     );
        if (Cddata->ScratchSense == NULL)
        {
            status = STATUS_INSUFFICIENT_RESOURCES;
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                        "Failed to allocate scratch sense data\n"
                        ));
        }
    }

    // allocate the SRB history data
    if (NT_SUCCESS(status))
    {
        size_t allocationSize = sizeof(SRB_HISTORY) - sizeof(SRB_HISTORY_ITEM);
        allocationSize += 20 * sizeof(SRB_HISTORY_ITEM);

        Cddata->ScratchHistory = ExAllocatePoolWithTag(NonPagedPool,
                                                       allocationSize,
                                                       CDROM_TAG_SCRATCH
                                                       );
        if (Cddata->ScratchHistory == NULL)
        {
            status = STATUS_INSUFFICIENT_RESOURCES;
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                        "Failed to allocate scratch history buffer\n"
                        ));
        }
        else
        {
            // must be initialized here...
            RtlZeroMemory(Cddata->ScratchHistory, allocationSize);
            Cddata->ScratchHistory->TotalHistoryCount = 20;
        }
    }

    // As a last step, initialize the scratch event
    if (NT_SUCCESS(status))
    {
        KeInitializeEvent(&(Cddata->ScratchEvent), SynchronizationEvent, FALSE);
    }

    // cleanup on failure
    if (!NT_SUCCESS(status))
    {
        ScratchBuffer_Deallocate(Cddata);
    }
    return NT_SUCCESS(status);
}

NTSTATUS
ResendIoctlForSplitCdb(
    __in PDEVICE_OBJECT DeviceObject,
    __inout PIRP OriginalIrp,
    __inout PIRP ReuseIrp,
    __inout PSCSI_REQUEST_BLOCK Srb,
    __in ULONG DataTransferLength
    )
{
    // we've either got a MDL, or there's no data buffer
    ASSERT((ReuseIrp->MdlAddress != NULL) || (Srb->DataBuffer == NULL));
    ASSERT((DataTransferLength == 0)      || (Srb->DataBuffer != NULL));

    // reinitialize the irp to send back down
    {
        PMDL mdl = ReuseIrp->MdlAddress;
        IoReuseIrp(ReuseIrp, STATUS_NOT_SUPPORTED);
        ReuseIrp->MdlAddress = mdl;
    }

    // reset the SRB fields individually to save many things
    {
        ASSERT(Srb->Length == SCSI_REQUEST_BLOCK_SIZE);
        ASSERT(Srb->Function == SRB_FUNCTION_EXECUTE_SCSI);
        ASSERT(Srb->OriginalRequest == ReuseIrp);
        ASSERT(Srb->SenseInfoBufferLength == SENSE_BUFFER_SIZE);
        ASSERT(Srb->SenseInfoBuffer != NULL);

        Srb->SrbStatus   = SRB_STATUS_PENDING;
        Srb->ScsiStatus  = SCSISTAT_GOOD;
        Srb->PathId      = 0;
        Srb->TargetId    = 0;
        Srb->Lun         = 0;
        Srb->QueueTag    = 0;
        //Srb->QueueAction = x;           // leave as-is per last send of this command
        //Srb->CdbLength = x;             // leave as-is per last send of this command
        //Srb->SenseInfoBufferLength = x; // leave as-is per last send of this command
        //Srb->SrbFlags = x;              // leave as-is per last send of this command
        Srb->DataTransferLength = DataTransferLength;
        //Srb->TimeOutValue = x;          // leave as-is per last send of this command
        //Srb->DataBuffer = x;            // leave as-is per last send of this command
        //Srb->SenseInfoBuffer = x;       // leave as-is per last send of this command
        Srb->NextSrb = NULL;
        // Srb->OriginalRequest = x;      // leave as-is per last send of this command
        Srb->SrbExtension = NULL;
        Srb->InternalStatus = 0;
        //Srb->Cdb[] = {0};               // leave as-is per last send of this command
    }

    // set the IRP again to send the command back down the CDROM stack
    {
        // This code is based on that within StartIo() for IOCTLs
        PIO_STACK_LOCATION irpStack;
        PIO_STACK_LOCATION nextStack;
        IoSetNextIrpStackLocation(ReuseIrp);
        irpStack = IoGetCurrentIrpStackLocation(ReuseIrp);
        irpStack->DeviceObject = DeviceObject;
        irpStack->Parameters.Others.Argument2 = (PVOID)OriginalIrp;

        nextStack = IoGetNextIrpStackLocation(ReuseIrp);
        nextStack->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;
        nextStack->Parameters.DeviceIoControl.IoControlCode = IOCTL_SCSI_EXECUTE_IN;
        nextStack->Parameters.Scsi.Srb = Srb;

        IoSetCompletionRoutine(ReuseIrp,
                               CdRomDeviceControlCompletion,
                               Srb,
                               TRUE,
                               TRUE,
                               TRUE);
    }

    // reset some of the original irp fields also
    {
        PIO_STACK_LOCATION originalIrpNextStack = IoGetNextIrpStackLocation(OriginalIrp);

        // reset retry count to five since one IO completed OK
        originalIrpNextStack->Parameters.Others.Argument1 = UlongToPtr(MAXIMUM_RETRIES);
        // reset next irp pointer
        ASSERT( originalIrpNextStack->Parameters.Others.Argument3 == ReuseIrp);
        originalIrpNextStack->Parameters.Others.Argument3 = ReuseIrp;
    }

    // send the irp back down the stack
    {
        PFUNCTIONAL_DEVICE_EXTENSION fdoExtension;
        IoMarkIrpPending(ReuseIrp);

        fdoExtension = DeviceObject->DeviceExtension;
        IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, ReuseIrp);
    }
    return STATUS_MORE_PROCESSING_REQUIRED;
}

NTSTATUS
CdRomSynchronizeIoctlWithStartIo(
    __in PDEVICE_OBJECT Fdo,
    __in PIRP Irp,
    __in PDRIVER_DISPATCH IoctlHandlerWhenSynchronized  // NOTE: NOT CALLED IF IRP IS CANCELLED!
    )
{
    NTSTATUS waitStatus = STATUS_UNSUCCESSFUL;
    NTSTATUS status;
    PIO_STACK_LOCATION irpStack = IoGetCurrentIrpStackLocation(Irp);
    PIO_STACK_LOCATION nextStack = IoGetNextIrpStackLocation(Irp);

    UCHAR uniqueAddress = 0;

    BOOLEAN mustCallStartNextPacket = TRUE;

    KEVENT event; KeInitializeEvent(&event, NotificationEvent, FALSE);

    // validate we're only calling this as passive level
    if (KeGetCurrentIrql() != PASSIVE_LEVEL) {
        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "CdRomSynchronizeIoctlWithStartIO: IOCTL must be called at passive level.\n"));
        Irp->IoStatus.Status = STATUS_INVALID_DEVICE_REQUEST;
        Irp->IoStatus.Information = 0;
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
        return STATUS_INVALID_DEVICE_REQUEST;
    }
    // validate we're only calling this for IOCTLs
    if (irpStack->MajorFunction != IRP_MJ_DEVICE_CONTROL) {
        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "CdRomSynchronizeIoctlWithStartIO: only valid for IOCTLs.\n"));
        Irp->IoStatus.Status = STATUS_INVALID_DEVICE_REQUEST;
        Irp->IoStatus.Information = 0;
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
        return STATUS_INVALID_DEVICE_REQUEST;
    }

    // copy the stack down a notch
    IoCopyCurrentIrpStackLocationToNext(Irp);

    // set a completion routine whose sole purpose is the setting of the event
    IoSetCompletionRoutine(Irp, CdRomClassIoctlCompletion, &event, TRUE, TRUE, TRUE);

    // set the next stack location as active
    IoSetNextIrpStackLocation(Irp);

    // set the next stack location's parameters so StartIO can quickly stop
    // dealing with the queue....
    nextStack->MajorFunction = IRP_MJ_SET_EA; // not used by storage, only uses one ULONG of parameters
    nextStack->Parameters.Others.Argument1 = CdRomSynchronizeIoctlWithStartIo;
    nextStack->Parameters.Others.Argument2 = CdRomSynchronizeIoctlWithStartIo;
    nextStack->Parameters.Others.Argument3 = CdRomSynchronizeIoctlWithStartIo;
    nextStack->Parameters.Others.Argument4 = CdRomSynchronizeIoctlWithStartIo;

    // Override volume verifies on this stack location so that we
    // will be forced through the synchronization.  Once this
    // location goes away we get the old value back
    SET_FLAG(nextStack->Flags, SL_OVERRIDE_VERIFY_VOLUME);

    // acquire an extra remove lock since classpnp releases this irp when it completes
    // don't worry, we'll re-acquire it soon after
    ClassAcquireRemoveLock(Fdo, (PIRP)&uniqueAddress);

    // Ensure this thread (typically a user thread) is not suspended while
    // we have stopped the StartIO queue
    // BIG QUESTION : Will this prevent alert when thread is terminating below???
    KeEnterCriticalRegion();

    // send the request to the StartIO queue in a cancellable manner
    IoStartPacket(Fdo, Irp, NULL, CdRomCancelFromStartIO);

    // Wait for CdRomClassIoctlCompletion to set the event. This
    // ensures serialization remains intact for these device controls.
    // Must wait in alertable manner to allow cancellation
    // of this irp to properly be processed.
    while (waitStatus != STATUS_SUCCESS)
    {
        waitStatus = KeWaitForSingleObject(&event, Executive, KernelMode, TRUE, NULL);
        if (waitStatus == STATUS_SUCCESS) // must check equality -- STATUS_ALERTED is success code
        {
            // do nothing
        }
        else if (waitStatus != STATUS_ALERTED)
        {
            // do nothing
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_QUEUE,
                        "Irp %p on device object %p had a non-alert, non-success result from wait (%!HRESULT!)\n",
                        Irp,
                        Fdo,
                        waitStatus
                        ));
            ASSERT(FALSE);
        }
        else if (PsIsThreadTerminating(PsGetCurrentThread()))
        {
            // the thread was alerted and is terminating, so cancel the irp
            if (IoCancelIrp(Irp))
            {
                // cancellation routine was called
                TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_QUEUE,
                            "Irp %p on device object %p had a cancel routine called\n",
                            Irp,
                            Fdo
                            ));
            }
            else
            {
                TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_QUEUE,
                            "Irp %p on device object %p only had its cancel flag set\n",
                            Irp,
                            Fdo
                            ));
            }
        }
        else
        {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_QUEUE,
                        "SPURIOUS ALERT waiting for Irp %p on device object %p (%!STATUS!)\n",
                        Irp,
                        Fdo,
                        waitStatus
                        ));
        }
    } // end of wait loop on the event

    // because we've waited an unknown amount of time, should check
    // the cancelled flag to immediately fail the irp as appropriate
    if (Irp->Cancel)
    {
        // must detect if we've stopped the StartIO queue
        if ((nextStack->Parameters.Others.Argument1 == CdRomCancelFromStartIO) &&
            (nextStack->Parameters.Others.Argument2 == CdRomCancelFromStartIO) &&
            (nextStack->Parameters.Others.Argument3 == CdRomCancelFromStartIO) &&
            (nextStack->Parameters.Others.Argument4 == CdRomCancelFromStartIO) )
        {
            mustCallStartNextPacket = FALSE;
        }
        // the request was cancelled, thus we should always stop
        // processing here if possible.
        status = STATUS_CANCELLED;
        Irp->IoStatus.Status = STATUS_CANCELLED;
        Irp->IoStatus.Information = 0;
        ClassReleaseRemoveLock(Fdo, Irp);
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
    }
    else if (!NT_SUCCESS(Irp->IoStatus.Status))
    {
        // propogate status... most likely ACCESS DENIED.  Note that the queue
        // will not be frozen in this case.
        mustCallStartNextPacket = FALSE;
        status = Irp->IoStatus.Status;
        ClassReleaseRemoveLock(Fdo, Irp);
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
    }
    else
    {
        // Synchronization completed successfully.  Call the requested routine
        status = IoctlHandlerWhenSynchronized(Fdo, Irp);
    }

    // also need to explicitly call StartNextPacket if the queue was stalled
    if (mustCallStartNextPacket)
    {
        KIRQL irql;
        KeRaiseIrql(DISPATCH_LEVEL, &irql);
        IoStartNextPacket(Fdo, TRUE);
        KeLowerIrql(irql);
    }

    // now that the queue was restarted, can exit the critical region
    KeLeaveCriticalRegion();

    // finally, release the extra removelock.  This is needed to this point
    // to ensure it's safe to call IoStartNextPacket() (per earlier comments)
    ClassReleaseRemoveLock(Fdo, (PIRP)&uniqueAddress);
    return status;
}

VOID
CdRomCancelFromStartIO(
    __in PDEVICE_OBJECT Fdo,
    __in PIRP Irp
    )

/*++

Routine Description:

    This routine is called from the I/O system when a request is cancelled.

    N.B.  The cancel spinlock is already held upon entry to this routine.

Arguments:

    DeviceObject - Pointer to class device object.

    Irp - Pointer to the request packet to be cancelled.

Return Value:

    None.

--*/
{
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PCDROM_DATA cdData = (PCDROM_DATA)commonExtension->DriverData;
    BOOLEAN removedFromQueue = FALSE;

    // first, let's try getting the Irp out of the StartIO queue
    if (KeRemoveEntryDeviceQueue(&Fdo->DeviceQueue, &Irp->Tail.Overlay.DeviceQueueEntry)) {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_QUEUE,
                    "Irp %p on device object %p is being cancelled.\n",
                    Irp,
                    Fdo
                    ));
        removedFromQueue = TRUE;

    }

    // not there? try the MMC delayed work queue
    if (!removedFromQueue)
    {
        // it's possible it's in the MMC delayed work queue
        PLIST_ENTRY currentListPosition;
        PLIST_ENTRY startPosition;
        PLIST_ENTRY itemToFind = (PLIST_ENTRY) &(Irp->Tail.Overlay.DeviceQueueEntry);

        KeAcquireSpinLockAtDpcLevel(&cdData->Mmc.DelayedIrpsLock);

        // search the whole delayed MMC list for it....
        startPosition =  &cdData->Mmc.DelayedIrpsList;
        currentListPosition = &cdData->Mmc.DelayedIrpsList;

        do
        {
            currentListPosition = currentListPosition->Flink;
        }
        while ((currentListPosition != startPosition) && (currentListPosition != itemToFind));

        if (currentListPosition == itemToFind)
        {
            RemoveEntryList(currentListPosition);
            --cdData->Mmc.NumDelayedIrps;
            removedFromQueue = TRUE;
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_QUEUE,
                        "Irp %p on device object %p is being cancelled from delayed MMC update queue.\n",
                        Irp,
                        Fdo
                        ));
        }
        KeReleaseSpinLockFromDpcLevel(&cdData->Mmc.DelayedIrpsLock);
    }

    // Not there either?  Perhaps the delayed retry irp?
    if (!removedFromQueue)
    {
        // it's also possible it's a delayed retry irp if we use this for anything other than IOCTLs
        KeAcquireSpinLockAtDpcLevel(&(cdData->DelayedRetrySpinLock));
        if (cdData->DelayedRetryIrp == Irp)
        {
            cdData->DelayedRetryIrp = NULL;
            cdData->DelayedRetryInterval = 0;
            cdData->DelayedRetryResend = FALSE;
            removedFromQueue = TRUE;
        }
        KeReleaseSpinLockFromDpcLevel(&(cdData->DelayedRetrySpinLock));
    }

    // I don't see any other queues in CDROM at this point, so release the cancel spinlock
    IoReleaseCancelSpinLock(Irp->CancelIrql);

    if (removedFromQueue)
    {
        // ensure we tag the irpstack uniquely to indicate we've cancelled
        // prior to the StartIO queue (neccessary when synchronizing with it)
        {
            PIO_STACK_LOCATION irpStack = IoGetCurrentIrpStackLocation(Irp);
            irpStack->Parameters.Others.Argument1 = CdRomCancelFromStartIO;
            irpStack->Parameters.Others.Argument2 = CdRomCancelFromStartIO;
            irpStack->Parameters.Others.Argument3 = CdRomCancelFromStartIO;
            irpStack->Parameters.Others.Argument4 = CdRomCancelFromStartIO;
        }
        // Complete the request with STATUS_CANCELLED.
        Irp->IoStatus.Status = STATUS_CANCELLED;
        Irp->IoStatus.Information = 0;
        ClassReleaseRemoveLock(Fdo, Irp);
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
    }
    else
    {
        // this is an ERROR when StartIO attributes have been set properly....
        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_QUEUE,
                    "Irp %p on device object %p was requested to be cancelled -- NOT IN QUEUE?!\n",
                    Irp,
                    Fdo
                    ));
    }
    return;


}

NTSTATUS
CdRompCacheDeviceInquiryData(
    __in PFUNCTIONAL_DEVICE_EXTENSION FdoExtension
    )
{
    PCDROM_DATA cdData = FdoExtension->CommonExtension.DriverData;
    NTSTATUS status = STATUS_SUCCESS;
    ULONG timesAlreadyRetried = 0;
    ULONG timesSucceeded = 0;
    ULONG requestedInquiryTransferBytes = MINIMUM_CDROM_INQUIRY_SIZE; //per spec, device should return at least 36 bytes.
    C_ASSERT( RTL_SIZEOF_THROUGH_FIELD(INQUIRYDATA, AdditionalLength) <= 8 );
    BOOLEAN shouldRetry = TRUE;
    LONGLONG retryIn100nsUnits = 0;

    BOOLEAN retryOnDataUnderrun = TRUE;

    PINQUIRYDATA tmpInquiry = NULL;
    ULONG tmpInquiryByteCount = 0;

    // this ensures that the strings vendorID, productID, and firmwareRevision
    // are all available in the inquiry data.  In addition, MMC spec requires
    // all type 5 devices to have minimum 36 bytes of inquiry.
    static const UCHAR minInquiryAdditionalLength =
        MINIMUM_CDROM_INQUIRY_SIZE -
        RTL_SIZEOF_THROUGH_FIELD(INQUIRYDATA, AdditionalLength);

    C_ASSERT( RTL_SIZEOF_THROUGH_FIELD(INQUIRYDATA, ProductRevisionLevel) == MINIMUM_CDROM_INQUIRY_SIZE );
    C_ASSERT( RTL_SIZEOF_THROUGH_FIELD(INQUIRYDATA, ProductRevisionLevel) == 36 );

    // short-circuit here for if already cached for this device
    // required to avoid use of scratch buffer after initialization
    // of MCN code.
    if (cdData->CachedInquiryData != NULL)
    {
        ASSERT(cdData->CachedInquiryDataByteCount != 0);
        return STATUS_SUCCESS;
    }

    // use the scratch buffer....
    ScratchBuffer_BeginUse(cdData);

    // retrieve the inquiry data
    while (shouldRetry)
    {
        PSCSI_REQUEST_BLOCK srb = cdData->ScratchSrb;
        PCDB cdb = (PCDB)(srb->Cdb);

        // this is needed, to reset the IRP, etc.
        ScratchBuffer_ResetItems(cdData, FALSE);

        
        ScratchBuffer_SetupForSynchronousSrb(FdoExtension,
                                             requestedInquiryTransferBytes,
                                             TRUE);

        srb->CdbLength = 6;
        cdb->AsByte[0] = SCSIOP_INQUIRY;
        cdb->AsByte[3] = (UCHAR)( requestedInquiryTransferBytes >> (8*1) );
        cdb->AsByte[4] = (UCHAR)( requestedInquiryTransferBytes >> (8*0) );

        ScratchBuffer_SendSynchronousSrb(FdoExtension);

        shouldRetry = ScratchBuffer_InterpretSrbError(FdoExtension,
                                                      timesAlreadyRetried,
                                                      &status,
                                                      &retryIn100nsUnits
                                                      );
        if (shouldRetry)
        {
            LARGE_INTEGER t; t.QuadPart = retryIn100nsUnits;
            timesAlreadyRetried++;
            KeDelayExecutionThread(KernelMode, FALSE, &t);
        }
        else if (NT_SUCCESS(status)) // workarounds and hacks go here for retry...
        {
            // succeeded!
            timesSucceeded++;

            // ensure we got some non-zero data....
            // This is done so we don't accidentally work around the 
            // ATAPI.SYS bug when no data was transferred.
            if (NT_SUCCESS(status))
            {
                PULONG tmp = cdData->ScratchBuffer;
                ULONG i = RTL_SIZEOF_THROUGH_FIELD(INQUIRYDATA, ProductRevisionLevel) / sizeof(ULONG);
                C_ASSERT( RTL_SIZEOF_THROUGH_FIELD(INQUIRYDATA, ProductRevisionLevel) % sizeof(ULONG) == 0 );
    
                // wouldn't you know it -- there is no RtlIsMemoryZero() function; Make one up.
                for ( ; i != 0; i--)
                {
                    if (*tmp != 0)
                    {
                        break; // out of this inner FOR loop -- guarantees 'i != 0'
                    }
                    tmp++;
                }
    
                if (i == 0) // all loop'd successfully
                {
                    // should never occur to successfully get all zero'd data
                    status = STATUS_DEVICE_PROTOCOL_ERROR;
                }
            }

            // workaround an ATAPI.SYS bug where additional length field is set to zero
            if (NT_SUCCESS(status))
            {
                INQUIRYDATA * scratchInquiry = (INQUIRYDATA *)cdData->ScratchBuffer;
                if (scratchInquiry->AdditionalLength == 0)
                {
                    scratchInquiry->AdditionalLength = minInquiryAdditionalLength;
                }
            }

            // determine how much inquiry the device says it has, and request exactly that much
            if (NT_SUCCESS(status) && (timesSucceeded == 1))
            {
                INQUIRYDATA const * scratchInquiry = (INQUIRYDATA const *)cdData->ScratchBuffer;

                requestedInquiryTransferBytes =
                    scratchInquiry->AdditionalLength +
                    RTL_SIZEOF_THROUGH_FIELD(INQUIRYDATA, AdditionalLength);
                shouldRetry = TRUE;
            }
        }
        else if (retryOnDataUnderrun)
        {
            //
            //Workaround for drive reports that it has more INQUIRY data than reality. 
            //

            if ((cdData->ScratchSrb->SrbStatus == SRB_STATUS_DATA_OVERRUN) &&
                (cdData->ScratchSrb->DataTransferLength < requestedInquiryTransferBytes) &&
                (cdData->ScratchSrb->DataTransferLength >= MINIMUM_CDROM_INQUIRY_SIZE))
            {
                //
                //Port driver says buffer size mismatch (buffer underrun), 
                //retry with the real buffer size it could return.
                //

                requestedInquiryTransferBytes = cdData->ScratchSrb->DataTransferLength;
                shouldRetry = TRUE;

                //
                //Only retry once for this situation.
                //

                retryOnDataUnderrun = FALSE;
            }
        }
        // else failed, so don't do anything with the buffer...
    }



    // determine how many bytes of valid data were retrieved
    if (NT_SUCCESS(status))
    {
        INQUIRYDATA const * scratchInquiry = (INQUIRYDATA const *)cdData->ScratchBuffer;
        
        // ensure sufficient data was provided
        if (scratchInquiry->AdditionalLength < minInquiryAdditionalLength)
        {
            status = STATUS_DEVICE_PROTOCOL_ERROR;
        }
        else
        {
            // looks like the inquiry data was transferred
            tmpInquiryByteCount = cdData->ScratchSrb->DataTransferLength;
        }
    }

    // allocate and cache the inquiry data copy
    if (NT_SUCCESS(status))
    {
        tmpInquiry = ExAllocatePoolWithTag(NonPagedPool,
                                           tmpInquiryByteCount,
                                           CDROM_TAG_INQUIRY
                                           );
        if (tmpInquiry == NULL)
        {
            status = STATUS_INSUFFICIENT_RESOURCES;
        }
        else
        {
            RtlCopyMemory(tmpInquiry, cdData->ScratchBuffer, tmpInquiryByteCount);
        }
    }

    // if everything succeeded, then (and only then) modify the device extension
    if (NT_SUCCESS(status))
    {
        cdData->CachedInquiryData = tmpInquiry;
        cdData->CachedInquiryDataByteCount = tmpInquiryByteCount;
    }
    else
    {
        FREE_POOL(tmpInquiry);
    }

    // need to mark the scratch buffer as 'not in use'
    ScratchBuffer_EndUse(cdData);


    return status;
}




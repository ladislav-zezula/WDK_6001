/*--

Copyright (C) Microsoft Corporation, 2000

Module Name:

    mmc.c

Abstract:

    This file is used to extend cdrom.sys to detect and use mmc-compatible
    drives' capabilities more wisely.

Environment:

    kernel mode only

Notes:

    SCSI Tape, CDRom and Disk class drivers share common routines
    that can be found in the CLASS directory (..\ntos\dd\class).

Revision History:

--*/

#include "ntddk.h"
#include "classpnp.h"
#include "cdrom.h"

#ifdef DEBUG_USE_WPP
#include "mmc.tmh"
#endif

VOID
CdRompPrintAllFeaturePages(
    __in_bcount(Usable) PGET_CONFIGURATION_HEADER Buffer,
    ULONG const Usable
    );
NTSTATUS
CdRomUpdateMmcDriveCapabilitiesCompletion(
    __in_opt PDEVICE_OBJECT Unused,
    __in     PIRP Irp,
    __in     PDEVICE_OBJECT Fdo
    );
VOID
CdRomPrepareUpdateCapabilitiesIrp(
    __in PDEVICE_OBJECT Fdo
    );

NTSTATUS
CdRompGetConfiguration(
    __in  PDEVICE_OBJECT Fdo,
    __out_bcount_part(BufferSize, *ValidBytes)
          PGET_CONFIGURATION_HEADER Buffer,
          ULONG const BufferSize,
    __out PULONG ValidBytes,
          FEATURE_NUMBER const StartingFeature,
          ULONG const RequestedType
    );

VOID
CdRompUpdateMmcWriteCapability(
    __in_bcount(bufferByteSize) PGET_CONFIGURATION_HEADER buffer,
          ULONG const bufferByteSize,
          BOOLEAN const current, // TRUE == can drive write now, FALSE == can drive ever write
    __out PBOOLEAN writable,
    __out PFEATURE_NUMBER validationSchema,
    __out PULONG blockingFactor
    );

#ifdef ALLOC_PRAGMA

#pragma alloc_text(PAGE, CdRompGetConfiguration)
#pragma alloc_text(PAGE, CdRomGetConfiguration)
#pragma alloc_text(PAGE, CdRomIsDeviceMmcDevice)
#pragma alloc_text(PAGE, CdRompPrintAllFeaturePages)
#pragma alloc_text(PAGE, CdRompUpdateMmcWriteCapability)
#pragma alloc_text(PAGE, CdRomUpdateMmcDriveCapabilities)
#pragma alloc_text(PAGE, CdRomDeAllocateMmcResources)
#pragma alloc_text(PAGE, CdRomAllocateMmcResources)
#pragma alloc_text(PAGE, CdRomUpdateTimeoutValueForMmcDevice)

#endif

/*++

    NOT DOCUMENTED YET - may be called at up to DISPATCH_LEVEL
    if memory is non-paged
    PRESUMES ALL DATA IS ACCESSIBLE based on FeatureBuffer

--*/
VOID
CdRomFindProfileInProfiles(
    __in  FEATURE_DATA_PROFILE_LIST const * ProfileHeader,
          FEATURE_PROFILE_TYPE const ProfileToFind,
          BOOLEAN const CurrentOnly,
    __out PBOOLEAN Found
    )
{
    FEATURE_DATA_PROFILE_LIST_EX const * profile;
    ULONG numberOfProfiles;
    ULONG i;


    *Found = FALSE;

    if (ProfileHeader->Header.AdditionalLength % 2 != 0) {
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_GENERAL,
                   "Profile total length %x is not integral multiple of 4\n",
                   ProfileHeader->Header.AdditionalLength));
        ASSERT(FALSE);
        return;
    }

    numberOfProfiles = ProfileHeader->Header.AdditionalLength / 4;
    profile = ProfileHeader->Profiles; // zero-sized array

    for (i = 0; i < numberOfProfiles; i++) {

        FEATURE_PROFILE_TYPE currentProfile;

        currentProfile =
            (profile->ProfileNumber[0] << 8) |
            (profile->ProfileNumber[1] & 0xff);

        if (currentProfile == ProfileToFind) {

            if (profile->Current || (!CurrentOnly))
            {
                *Found = TRUE;
            }

        }

        profile++;
    }
    return;

}

/*++

    NOT DOCUMENTED YET - may be called at up to DISPATCH_LEVEL
    if memory is non-paged

--*/
PVOID
CdRomFindFeaturePage(
    __in_bcount(Length) PGET_CONFIGURATION_HEADER FeatureBuffer,
    ULONG const Length,
    FEATURE_NUMBER const Feature
    )
{
    PUCHAR buffer;
    PUCHAR limit;
    ULONG  validLength;

    if (Length < sizeof(GET_CONFIGURATION_HEADER) + sizeof(FEATURE_HEADER)) {
        return NULL;
    }

    //
    // Calculate the length of valid data available in the
    // capabilities buffer from the DataLength field
    //

    REVERSE_BYTES(&validLength, FeatureBuffer->DataLength);

    validLength += RTL_SIZEOF_THROUGH_FIELD(GET_CONFIGURATION_HEADER, DataLength);

    //
    // set limit to point to first illegal address
    //

    limit  = (PUCHAR)FeatureBuffer;
    limit += min(Length, validLength);

    //
    // set buffer to point to first page
    //

    buffer = FeatureBuffer->Data;

    //
    // loop through each page until we find the requested one, or
    // until it's not safe to access the entire feature header
    // (if equal, have exactly enough for the feature header)
    //
    while (buffer + sizeof(FEATURE_HEADER) <= limit) {

        PFEATURE_HEADER header = (PFEATURE_HEADER)buffer;
        FEATURE_NUMBER thisFeature;

        thisFeature  =
            (header->FeatureCode[0] << 8) |
            (header->FeatureCode[1]);

        if (thisFeature == Feature) {

            PUCHAR temp;

            //
            // if don't have enough memory to safely access all the feature
            // information, return NULL
            //
            temp = buffer;
            temp += sizeof(FEATURE_HEADER);
            temp += header->AdditionalLength;

            if (temp > limit) {

                //
                // this means the transfer was cut-off, an insufficiently
                // small buffer was given, or other arbitrary error.  since
                // it's not safe to view the amount of data (even though
                // the header is safe) in this feature, pretend it wasn't
                // transferred at all...
                //

                TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_GENERAL,
                           "Feature %x exists, but not safe to access all its "
                           "data.  returning NULL\n", Feature));
                return NULL;
            } else {
                return buffer;
            }
        }

        if ((header->AdditionalLength % 4) &&
            !(Feature >= 0xff00 && Feature <= 0xffff)) {
            return NULL;
        }

        buffer += sizeof(FEATURE_HEADER);
        buffer += header->AdditionalLength;

    }
    return NULL;
}

/*++

Private so we can later expose to someone wanting to use a preallocated buffer

--*/
NTSTATUS
CdRompGetConfiguration(
    __in  PDEVICE_OBJECT Fdo,
    __out_bcount_part(BufferSize, *ValidBytes)
          PGET_CONFIGURATION_HEADER Buffer,
          ULONG const BufferSize,
    __out PULONG ValidBytes,
          FEATURE_NUMBER const StartingFeature,
          ULONG const RequestedType
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension;
    PCDROM_DATA cdData;
    SCSI_REQUEST_BLOCK srb = {0};
    PCDB cdb;
    NTSTATUS status;

    PAGED_CODE();
    ASSERT(Buffer);
    ASSERT(ValidBytes);

    *ValidBytes = 0;

    RtlZeroMemory(&srb, sizeof(SCSI_REQUEST_BLOCK));
    RtlZeroMemory(Buffer, BufferSize);

    fdoExtension = Fdo->DeviceExtension;
    cdData = (PCDROM_DATA)(fdoExtension->CommonExtension.DriverData);

    if (TEST_FLAG(cdData->HackFlags, CDROM_HACK_BAD_GET_CONFIG_SUPPORT)) {
        return STATUS_INVALID_DEVICE_REQUEST;
    }

    if (BufferSize > 0xFFFC)
    {
        // cannot request more than 0xFFFC bytes in one request
        // Eventually will "stitch" together multiple requests if needed
        // Today, no drive has anywhere close to 4k.....
        return CdRompGetConfiguration(Fdo, Buffer, 0xFFFC, ValidBytes, StartingFeature, RequestedType);
    }

    srb.TimeOutValue = CDROM_GET_CONFIGURATION_TIMEOUT;
    srb.CdbLength = 10;

    cdb = (PCDB)srb.Cdb;
    cdb->GET_CONFIGURATION.OperationCode = SCSIOP_GET_CONFIGURATION;
    cdb->GET_CONFIGURATION.RequestType = (UCHAR)RequestedType;
    cdb->GET_CONFIGURATION.StartingFeature[0] = (UCHAR)(StartingFeature >> 8);
    cdb->GET_CONFIGURATION.StartingFeature[1] = (UCHAR)(StartingFeature & 0xff);
    cdb->GET_CONFIGURATION.AllocationLength[0] = (UCHAR)(BufferSize >> 8);
    cdb->GET_CONFIGURATION.AllocationLength[1] = (UCHAR)(BufferSize & 0xff);

    status = ClassSendSrbSynchronous(Fdo,  &srb,  Buffer,
                                     BufferSize, FALSE);

    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
               "CdromGetConfiguration: Status was %x\n", status));

    if (NT_SUCCESS(status) || (status == STATUS_BUFFER_OVERFLOW) || (status == STATUS_DATA_OVERRUN)) {

        ULONG returned = srb.DataTransferLength;
        PGET_CONFIGURATION_HEADER header = (PGET_CONFIGURATION_HEADER)Buffer;
        ULONG available =
            (header->DataLength[0] << (8*3)) |
            (header->DataLength[1] << (8*2)) |
            (header->DataLength[2] << (8*1)) |
            (header->DataLength[3] << (8*0)) ;
        available += RTL_SIZEOF_THROUGH_FIELD(GET_CONFIGURATION_HEADER, DataLength);


        __analysis_assume(srb.DataTransferLength <= BufferSize);

        // The true usable amount of data returned is the lesser of
        // * the returned data per the srb.DataTransferLength field
        // * the total size per the GET_CONFIGURATION_HEADER
        // This is because ATAPI can't tell how many bytes really
        // were transferred on success when using DMA.
        if (available < returned)
        {
            returned = available;
        }

        ASSERT(returned <= BufferSize);
        *ValidBytes = (ULONG)returned;
        return STATUS_SUCCESS;

    } else {

        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                   "CdromGetConfiguration: failed %x\n", status));
        return status;

    }
    ASSERT(FALSE);
    return STATUS_UNSUCCESSFUL;
}

/*++

    Allocates buffer with configuration info, returns STATUS_SUCCESS
    or an error if one occurred

    NOTE: does not handle case where more than 65000 bytes are returned,
          which requires multiple calls with different starting feature
          numbers.

--*/
NTSTATUS
CdRomGetConfiguration(
    __in  PDEVICE_OBJECT Fdo,
    __deref_out_bcount_full(*BytesReturned)
          PGET_CONFIGURATION_HEADER *Buffer, // this routine allocates this memory
    __out PULONG BytesReturned,
          FEATURE_NUMBER const StartingFeature,
          ULONG const RequestedType
    )
{
    GET_CONFIGURATION_HEADER header = {0};  // eight bytes, not a lot
    PGET_CONFIGURATION_HEADER buffer;
    ULONG returned;
    ULONG size;
    ULONG i;
    NTSTATUS status;

    PAGED_CODE();


    *Buffer = NULL;
    *BytesReturned = 0;

    buffer = NULL;
    returned = 0;

    //
    // send the first request down to just get the header
    //

    status = CdRompGetConfiguration(Fdo, &header, sizeof(header),
                                    &returned, StartingFeature, RequestedType);

    if (!NT_SUCCESS(status)) {
        return status;
    }

    //
    // now try again, using information returned to allocate
    // just enough memory
    //

    size = header.DataLength[0] << 24 |
           header.DataLength[1] << 16 |
           header.DataLength[2] <<  8 |
           header.DataLength[3] <<  0 ;


    for (i = 0; i < 4; i++) {

        //
        // the datalength field is the size *following*
        // itself, so adjust accordingly
        //

        size += 4*sizeof(UCHAR);

        //
        // make sure the size is reasonable
        //

        if (size <= sizeof(FEATURE_HEADER)) {
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                       "CdromGetConfiguration: drive reports only %x bytes?\n",
                       size));
            return STATUS_UNSUCCESSFUL;
        }

        //
        // allocate the memory
        //

        buffer = (PGET_CONFIGURATION_HEADER)
                 ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                       size,
                                       CDROM_TAG_FEATURE);

        if (buffer == NULL) {
            return STATUS_INSUFFICIENT_RESOURCES;
        }

        //
        // send the first request down to just get the header
        //

        status = CdRompGetConfiguration(Fdo, buffer, size, &returned,
                                        StartingFeature, RequestedType);

        if (!NT_SUCCESS(status)) {
            ExFreePool(buffer);
            return status;
        }

        if (returned > size) {
            ExFreePool(buffer);
            return STATUS_INTERNAL_ERROR;
        }

        returned = buffer->DataLength[0] << 24 |
                   buffer->DataLength[1] << 16 |
                   buffer->DataLength[2] <<  8 |
                   buffer->DataLength[3] <<  0 ;
        returned += 4*sizeof(UCHAR);

        if (returned <= size) {
            *Buffer = buffer;
            *BytesReturned = size;  // amount of 'safe' memory
            return STATUS_SUCCESS;
        }

        //
        // else retry using the new size....
        //

        size = returned;
        ExFreePool(buffer);
        buffer = NULL;

    }

    //
    // it failed after a number of attempts, so just fail.
    //

    TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
               "CdRomGetConfiguration: Failed %d attempts to get all feature "
               "information\n", i));
    return STATUS_IO_DEVICE_ERROR;
}

VOID
CdRomIsDeviceMmcDevice(
    __in  PDEVICE_OBJECT Fdo,
    __out PBOOLEAN IsMmc,
    __out PBOOLEAN IsAACS,
    __out PBOOLEAN IsDvdDevice,
    __out PBOOLEAN IsWriterDrive
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PCDROM_DATA cdData = commonExtension->DriverData;
    NTSTATUS status;
    ULONG size;
    ULONG previouslyFailed;

    PAGED_CODE();
    ASSERT( commonExtension->IsFdo );

    *IsMmc  = FALSE;
    *IsAACS = FALSE;
    *IsDvdDevice = FALSE;
    *IsWriterDrive = FALSE;

    //
    // read the registry in case the drive failed previously,
    // and a timeout is occurring.
    //

    previouslyFailed = FALSE;
    ClassGetDeviceParameter(fdoExtension,
                            CDROM_SUBKEY_NAME,
                            CDROM_NON_MMC_DRIVE_NAME,
                            &previouslyFailed
                            );

    if (previouslyFailed) {
        SET_FLAG(cdData->HackFlags, CDROM_HACK_BAD_GET_CONFIG_SUPPORT);
    }

    //
    // read from the registry in case the drive reports bad profile lengths
    //
    previouslyFailed = FALSE;
    ClassGetDeviceParameter(fdoExtension,
                            CDROM_SUBKEY_NAME,
                            CDROM_NON_MMC_VENDOR_SPECIFIC_PROFILE,
                            &previouslyFailed
                            );

    if (previouslyFailed) {
        SET_FLAG(cdData->HackFlags, CDROM_HACK_BAD_VENDOR_PROFILES);
    }

    //
    // check for the ProfileList feature to determine if the drive is MMC compliant
    // and set the "size" local variable to total GetConfig data size available.
    // NOTE: This will exit this function in some error paths.
    //
    {
        PGET_CONFIGURATION_HEADER localHeader;
        ULONG usable;

        ScratchBuffer_BeginUse(cdData);

        localHeader = cdData->ScratchBuffer;
        status = CdRompGetConfiguration(Fdo,
                                        localHeader,
                                        sizeof(GET_CONFIGURATION_HEADER),
                                        &usable,
                                        FeatureProfileList,
                                        SCSI_GET_CONFIGURATION_REQUEST_TYPE_ALL);

        if (status == STATUS_INVALID_DEVICE_REQUEST ||
            status == STATUS_NO_MEDIA_IN_DEVICE     ||
            status == STATUS_IO_DEVICE_ERROR        ||
            status == STATUS_IO_TIMEOUT) {

            ScratchBuffer_EndUse(cdData);

            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                       "GetConfiguration Failed (%x), device %p not mmc-compliant\n",
                       status, Fdo
                       ));
            
            previouslyFailed = TRUE;
            ClassSetDeviceParameter(fdoExtension,
                                    CDROM_SUBKEY_NAME,
                                    CDROM_NON_MMC_DRIVE_NAME,
                                    previouslyFailed
                                    );

            return;

        } else if (!NT_SUCCESS(status)) {

            ScratchBuffer_EndUse(cdData);

            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                       "GetConfiguration Failed, status %x -- defaulting to -ROM\n",
                       status));

            return;

        } else if (usable < sizeof(GET_CONFIGURATION_HEADER)) {

            ScratchBuffer_EndUse(cdData);

            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                       "GetConfiguration Failed, returned only %x bytes!\n", usable));
            previouslyFailed = TRUE;
            ClassSetDeviceParameter(fdoExtension,
                                    CDROM_SUBKEY_NAME,
                                    CDROM_NON_MMC_DRIVE_NAME,
                                    previouslyFailed
                                    );
            return;
        }

        size = (localHeader->DataLength[0] << 24) |
               (localHeader->DataLength[1] << 16) |
               (localHeader->DataLength[2] <<  8) |
               (localHeader->DataLength[3] <<  0) ;


        if ((size <= 4) || (size + 4 < size)) {

            ScratchBuffer_EndUse(cdData);

            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                       "GetConfiguration Failed, claims MMC support but doesn't "
                       "correctly return config length! (%x)\n",
                       size
                       ));
            previouslyFailed = TRUE;
            ClassSetDeviceParameter(fdoExtension,
                                    CDROM_SUBKEY_NAME,
                                    CDROM_NON_MMC_DRIVE_NAME,
                                    previouslyFailed
                                    );

            return;

        } else if ((size % 4) != 0) {

            if ((size % 2) != 0) {
                ScratchBuffer_EndUse(cdData);

                TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                           "GetConfiguration Failed, returned odd number of bytes %x!\n",
                           size
                           ));
                previouslyFailed = TRUE;
                ClassSetDeviceParameter(fdoExtension,
                                        CDROM_SUBKEY_NAME,
                                        CDROM_NON_MMC_DRIVE_NAME,
                                        previouslyFailed
                                        );
                return;

            } else {

                if (TEST_FLAG(cdData->HackFlags, CDROM_HACK_BAD_VENDOR_PROFILES)) {
                    // we've already caught this and ASSERT'd once, so don't do it again
                } else {
                    TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                               "GetConfiguration returned a size that is not per spec (%x bytes), this is probably because of a vendor specific data header with a size not divisible by 4.\n",
                               size
                               ));
                    previouslyFailed = TRUE;
                    ClassSetDeviceParameter(fdoExtension,
                                            CDROM_SUBKEY_NAME,
                                            CDROM_NON_MMC_VENDOR_SPECIFIC_PROFILE,
                                            previouslyFailed
                                            );
                }

            }
        }
        size += 4; // sizeof the datalength fields
        ScratchBuffer_EndUse(cdData);

    }

    *IsMmc = TRUE;

    // This code doesn't handle total get config size over 64k
    ASSERT( size <= MAXUSHORT );
    ASSERT( size <= cdData->ScratchBufferSize );


    // get the list of _all_ features
    {
        PGET_CONFIGURATION_HEADER configBuffer = cdData->ScratchBuffer;
        ULONG usable;

        ScratchBuffer_BeginUse(cdData);

        status = CdRompGetConfiguration(Fdo,
                                        configBuffer,
                                        cdData->ScratchBufferSize,
                                        &usable,
                                        FeatureProfileList,
                                        SCSI_GET_CONFIGURATION_REQUEST_TYPE_ALL);

        if (NT_SUCCESS(status)) {

            PFEATURE_HEADER header = NULL;
            FEATURE_NUMBER  validationSchema;
            ULONG           blockingFactor;

            // print all the feature pages (DBG only)
            CdRompPrintAllFeaturePages(configBuffer, usable);

            // if AACS feature exists, enable AACS flag in the driver
            header = CdRomFindFeaturePage(configBuffer, usable, FeatureAACS);
            if (header) {
                TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                            "Reporting AACS support for device due to GET_CONFIGURATION showing support\n"
                            ));
                *IsAACS = TRUE;
            }

            // Check if it's a DVD device
            header = CdRomFindFeaturePage(configBuffer, usable, FeatureDvdRead);
            if (header) {
                *IsDvdDevice = TRUE;
            }

            // check if drive is writer
            CdRompUpdateMmcWriteCapability(configBuffer,
                                          usable,
                                          FALSE,
                                          IsWriterDrive,
                                          &validationSchema,
                                          &blockingFactor);
        }

        ScratchBuffer_EndUse(cdData);
    }

    //
    // Check for SCSI_GET_CONFIGURATION_REQUEST_TYPE_ONE support in the device.
    // NOTE: This will exit this function in some error paths.
    //
    {
        PGET_CONFIGURATION_HEADER configBuffer = NULL;
        ULONG featureSize = sizeof(GET_CONFIGURATION_HEADER)+sizeof(FEATURE_HEADER);
        ULONG usable;

        //
        // read the registry in case the drive failed previously,
        // and a timeout is occurring.
        //

        previouslyFailed = FALSE;
        ClassGetDeviceParameter(fdoExtension,
                                CDROM_SUBKEY_NAME,
                                CDROM_TYPE_ONE_GET_CONFIG_NAME,
                                &previouslyFailed
                                );

        if (previouslyFailed) {
            SET_FLAG(cdData->HackFlags, CDROM_HACK_BAD_TYPE_ONE_GET_CONFIG);
            return;
        }

        //
        // Get only the config and feature header
        //

        ScratchBuffer_BeginUse(cdData);
        configBuffer = cdData->ScratchBuffer;

        status = CdRompGetConfiguration(Fdo,
                                        configBuffer,
                                        featureSize,
                                        &usable,
                                        FeatureProfileList,
                                        SCSI_GET_CONFIGURATION_REQUEST_TYPE_ONE);

        if (!NT_SUCCESS(status) || (usable < featureSize)) {

            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                       "Type One GetConfiguration Failed. Usable buffer size: %d\n", usable));
            previouslyFailed = TRUE;

        } else {

            PFEATURE_HEADER featureHeader;
            ULONG totalAvailableBytes = 0;
            ULONG expectedAvailableBytes = 0;

            REVERSE_BYTES(&totalAvailableBytes, configBuffer->DataLength);
            totalAvailableBytes += RTL_SIZEOF_THROUGH_FIELD(GET_CONFIGURATION_HEADER, DataLength);

            featureHeader = (PFEATURE_HEADER) ((PUCHAR)configBuffer + sizeof(GET_CONFIGURATION_HEADER));
            expectedAvailableBytes =
                sizeof(GET_CONFIGURATION_HEADER) +
                sizeof(FEATURE_HEADER) +
                featureHeader->AdditionalLength;

            if (totalAvailableBytes > expectedAvailableBytes) {

                //
                // Device is returning more than required size. Most likely the device
                // is returning TYPE ALL data. Set the flag to use TYPE ALL for TYPE ONE
                // requets
                //
                TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                           "Type One GetConfiguration Failed. "
                           "Device returned %d bytes instead of %d bytes\n",
                           size, featureSize));
                previouslyFailed = TRUE;

            }
        }
        ScratchBuffer_EndUse(cdData);

        if (previouslyFailed == TRUE) {

            ClassSetDeviceParameter(fdoExtension,
                                    CDROM_SUBKEY_NAME,
                                    CDROM_TYPE_ONE_GET_CONFIG_NAME,
                                    previouslyFailed
                                    );

            SET_FLAG(cdData->HackFlags, CDROM_HACK_BAD_TYPE_ONE_GET_CONFIG);
        }

    }

    return;
}

VOID
CdRompPrintAllFeaturePages(
    __in_bcount(Usable) PGET_CONFIGURATION_HEADER Buffer,
    ULONG const Usable
    )
{
#if DBG
    PFEATURE_HEADER header;

////////////////////////////////////////////////////////////////////////////////
// items expected to ALWAYS be current if they exist
////////////////////////////////////////////////////////////////////////////////
    header = CdRomFindFeaturePage(Buffer, Usable, FeatureProfileList);
    if (header != NULL) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: CurrentProfile %x "
                   "with %x bytes of data at %p\n",
                   Buffer->CurrentProfile[0] << 8 |
                   Buffer->CurrentProfile[1],
                   Usable, Buffer));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureCore);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "CORE Features"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureMorphing);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Morphing"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureRemovableMedium);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Removable Medium"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeaturePowerManagement);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Power Management"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureEmbeddedChanger);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Embedded Changer"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureMicrocodeUpgrade);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Microcode Update"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureTimeout);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Timeouts"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureLogicalUnitSerialNumber);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "LUN Serial Number"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureFirmwareDate);
    if (header) {

        ULONG featureSize = header->AdditionalLength;
        featureSize += RTL_SIZEOF_THROUGH_FIELD(FEATURE_HEADER, AdditionalLength);

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                   "Currently supports" : "Is able to support"),
                   "Firmware Date"
                   ));

        if (featureSize >= RTL_SIZEOF_THROUGH_FIELD(FEATURE_DATA_FIRMWARE_DATE, Minute))
        {
            PFEATURE_DATA_FIRMWARE_DATE date = (PFEATURE_DATA_FIRMWARE_DATE)header;
            // show date as "YYYY/MM/DD hh:mm", which is 18 chars (17+NULL)
            UCHAR dateString[18] = { 0 };
            dateString[ 0] = date->Year[0];
            dateString[ 1] = date->Year[1];
            dateString[ 2] = date->Year[2];
            dateString[ 3] = date->Year[3];
            dateString[ 4] = '/';
            dateString[ 5] = date->Month[0];
            dateString[ 6] = date->Month[1];
            dateString[ 7] = '/';
            dateString[ 8] = date->Day[0];
            dateString[ 9] = date->Day[1];
            dateString[10] = ' ';
            dateString[11] = ' ';
            dateString[12] = date->Hour[0];
            dateString[13] = date->Hour[1];
            dateString[14] = ':';
            dateString[15] = date->Minute[0];
            dateString[16] = date->Minute[1];
            dateString[17] = 0;
            // SECONDS IS NOT AVAILABLE ON EARLY IMPLEMENTATIONS -- ignore it
            //dateString[17] = ':';
            //dateString[18] = date->Seconds[0];
            //dateString[19] = date->Seconds[1];
            //dateString[20] = 0;
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                        "CdromGetConfiguration: Firmware Date/Time %s (UTC)\n",
                        dateString
                        ));
        }
    }

////////////////////////////////////////////////////////////////////////////////
// items expected not to always be current
////////////////////////////////////////////////////////////////////////////////


    header = CdRomFindFeaturePage(Buffer, Usable, FeatureWriteProtect);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Software Write Protect"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureRandomReadable);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Random Reads"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureMultiRead);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Multi-Read"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureCdRead);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "reading from CD-ROM/R/RW"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureDvdRead);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "DVD Structure Reads"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureRandomWritable);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Random Writes"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureIncrementalStreamingWritable);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Incremental Streaming Writing"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureSectorErasable);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Sector Erasable Media"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureFormattable);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Formatting"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureDefectManagement);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "defect management"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureWriteOnce);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Write Once Media"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureRestrictedOverwrite);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Restricted Overwrites"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureCdrwCAVWrite);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "CD-RW CAV recording"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureMrw);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Mount Rainier media"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureEnhancedDefectReporting);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Enhanced Defect Reporting"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureDvdPlusRW);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "DVD+RW media"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureRigidRestrictedOverwrite);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Rigid Restricted Overwrite"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureCdTrackAtOnce);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "CD Recording (Track At Once)"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureCdMastering);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "CD Recording (Mastering)"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureDvdRecordableWrite);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "DVD Recording (Mastering)"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureDDCDRead);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "DD CD Reading"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureDDCDRWrite);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "DD CD-R Writing"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureDDCDRWWrite);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "DD CD-RW Writing"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureLayerJumpRecording);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Layer Jump Recording"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureHDDVDRead);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "HD-DVD Reading"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureHDDVDWrite);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "HD-DVD Writing"
                   ));
    }


    header = CdRomFindFeaturePage(Buffer, Usable, FeatureSMART);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "S.M.A.R.T."
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureCDAudioAnalogPlay);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Analogue CD Audio Operations"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureDvdCSS);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "DVD CSS"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureRealTimeStreaming);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "Real-time Streaming Reads"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureDiscControlBlocks);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "DVD Disc Control Blocks"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureDvdCPRM);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "DVD CPRM"
                   ));
    }

    header = CdRomFindFeaturePage(Buffer, Usable, FeatureAACS);
    if (header) {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                   "CdromGetConfiguration: %s %s\n",
                   (header->Current ?
                    "Currently supports" : "Is able to support"),
                   "AACS"
                   ));
    }
#endif // DBG
    return;
}

NTSTATUS
CdRomUpdateMmcDriveCapabilitiesCompletion(
    __in_opt PDEVICE_OBJECT Unused,
    __in     PIRP Irp,
    __in     PDEVICE_OBJECT Fdo
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCDROM_DATA cdData = fdoExtension->CommonExtension.DriverData;
    PCDROM_MMC_EXTENSION mmcData = &(cdData->Mmc);
    PSCSI_REQUEST_BLOCK srb = &(mmcData->CapabilitiesSrb);
    PIO_STACK_LOCATION irpStack = IoGetCurrentIrpStackLocation(Irp);
    NTSTATUS status = STATUS_UNSUCCESSFUL;
    PIRP delayedIrp;


    // completion routine should retry as neccessary.
    // when success, clear the flag to allow startio to proceed.
    // else fail original request when retries are exhausted.

    ASSERT(mmcData->CapabilitiesIrp == Irp);

    // for now, if succeeded, just print the new pages.

    if (SRB_STATUS(srb->SrbStatus) != SRB_STATUS_SUCCESS) {

        //
        // ISSUE-2000/4/20-henrygab - should we try to reallocate if size
        //                            available became larger than what we
        //                            originally allocated?  otherwise, it
        //                            is possible (not probable) that we
        //                            would miss the feature.  can check
        //                            that by looking at the header size
        //                            and comparing it to requested data
        //                            size.
        //

        BOOLEAN retry;
        ULONG retryInterval;

        //
        // Release the queue if it is frozen.
        //

        if (srb->SrbStatus & SRB_STATUS_QUEUE_FROZEN) {
            ClassReleaseQueue(Fdo);
        }

        retry = ClassInterpretSenseInfo(
                    Fdo,
                    srb,
                    irpStack->MajorFunction,
                    0,
                    MAXIMUM_RETRIES - ((ULONG)(ULONG_PTR)irpStack->Parameters.Others.Argument4),
                    &status,
                    &retryInterval);

        //
        // DATA_OVERRUN is not an error in this case....
        //

        if (status == STATUS_DATA_OVERRUN) {
            status = STATUS_SUCCESS;
        }

        //
        // override verify_volume based on original irp's settings
        //

        if (TEST_FLAG(irpStack->Flags, SL_OVERRIDE_VERIFY_VOLUME) &&
            status == STATUS_VERIFY_REQUIRED) {
            status = STATUS_IO_DEVICE_ERROR;
            retry = TRUE;
        }

        if (retry && ((ULONG)(ULONG_PTR)irpStack->Parameters.Others.Argument4)--) {

            LARGE_INTEGER delay;
            delay.QuadPart = retryInterval;
            delay.QuadPart *= (LONGLONG)1000 * 1000 * 10;

            //
            // retry the request
            //

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_INIT,
                       "Not using ClassRetryRequest Yet\n"));
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                       "Retry update capabilities %p\n", Irp));
            CdRomPrepareUpdateCapabilitiesIrp(Fdo);

            CdRomRetryRequest(fdoExtension, Irp, retryInterval, TRUE);

            //
            // ClassRetryRequest(Fdo, Irp, delay);
            //

            return STATUS_MORE_PROCESSING_REQUIRED;

        }

    } else {

        status = STATUS_SUCCESS;

    }

    Irp->IoStatus.Status = status;

    KeSetEvent(&mmcData->CapabilitiesEvent, IO_CD_ROM_INCREMENT, FALSE);


    return STATUS_MORE_PROCESSING_REQUIRED;
}

VOID
CdRomPrepareUpdateCapabilitiesIrp(
    __in PDEVICE_OBJECT Fdo
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCDROM_DATA cdData = fdoExtension->CommonExtension.DriverData;
    PCDROM_MMC_EXTENSION mmcData = &(cdData->Mmc);
    PIO_STACK_LOCATION nextStack;
    PSCSI_REQUEST_BLOCK srb;
    PCDB cdb;
    ULONG bufferSize;
    PIRP irp;

    ASSERT(mmcData->UpdateState);
    ASSERT(mmcData->NumDelayedIrps != 0);
    ASSERT(mmcData->CapabilitiesIrp != NULL);
    ASSERT(mmcData->CapabilitiesMdl != NULL);
    ASSERT(mmcData->CapabilitiesBuffer);
    ASSERT(mmcData->CapabilitiesBufferSize != 0);
    ASSERT(fdoExtension->SenseData);

    //
    // do *NOT* call IoReuseIrp(), since it would zero out our
    // current irp stack location, which we really don't want
    // to happen.  it would also set the current irp stack location
    // to one greater than currently exists (to give max irp usage),
    // but we don't want that either, since we use the top irp stack.
    //
    // IoReuseIrp(mmcData->CapabilitiesIrp, STATUS_UNSUCCESSFUL);
    //

    irp = mmcData->CapabilitiesIrp;
    srb = &(mmcData->CapabilitiesSrb);
    cdb = (PCDB)(srb->Cdb);
    bufferSize = mmcData->CapabilitiesBufferSize;

    //
    // zero stuff out
    //

    RtlZeroMemory(srb, sizeof(SCSI_REQUEST_BLOCK));
    RtlZeroMemory(fdoExtension->SenseData, sizeof(SENSE_DATA));
    RtlZeroMemory(mmcData->CapabilitiesBuffer, bufferSize);

    //
    // setup the srb
    //

    srb->TimeOutValue = CDROM_GET_CONFIGURATION_TIMEOUT;
    srb->Length = SCSI_REQUEST_BLOCK_SIZE;
    srb->Function = SRB_FUNCTION_EXECUTE_SCSI;
    srb->SenseInfoBufferLength = SENSE_BUFFER_SIZE;
    srb->SenseInfoBuffer = fdoExtension->SenseData;
    srb->DataBuffer = mmcData->CapabilitiesBuffer;
    srb->QueueAction = SRB_SIMPLE_TAG_REQUEST;
    srb->DataTransferLength = mmcData->CapabilitiesBufferSize;
    srb->ScsiStatus = 0;
    srb->SrbStatus = 0;
    srb->NextSrb = NULL;
    srb->OriginalRequest = irp;
    srb->SrbFlags = fdoExtension->SrbFlags;
    srb->CdbLength = 10;
    SET_FLAG(srb->SrbFlags, SRB_FLAGS_DATA_IN);
    SET_FLAG(srb->SrbFlags, SRB_FLAGS_NO_QUEUE_FREEZE);

    //
    // setup the cdb
    //

    cdb->GET_CONFIGURATION.OperationCode = SCSIOP_GET_CONFIGURATION;
    cdb->GET_CONFIGURATION.RequestType = SCSI_GET_CONFIGURATION_REQUEST_TYPE_CURRENT;
    cdb->GET_CONFIGURATION.StartingFeature[0] = 0;
    cdb->GET_CONFIGURATION.StartingFeature[1] = 0;
    cdb->GET_CONFIGURATION.AllocationLength[0] = (UCHAR)(bufferSize >> 8);
    cdb->GET_CONFIGURATION.AllocationLength[1] = (UCHAR)(bufferSize & 0xff);

    //
    // setup the irp
    //

    nextStack = IoGetNextIrpStackLocation(irp);
    nextStack->MajorFunction = IRP_MJ_SCSI;
    nextStack->Parameters.Scsi.Srb = srb;
    irp->MdlAddress = mmcData->CapabilitiesMdl;
    irp->AssociatedIrp.SystemBuffer = mmcData->CapabilitiesBuffer;
    IoSetCompletionRoutine(irp, CdRomUpdateMmcDriveCapabilitiesCompletion, Fdo,
                           TRUE, TRUE, TRUE);

    return;

}

VOID
CdRompUpdateMmcWriteCapability(
    __in_bcount(bufferByteSize) PGET_CONFIGURATION_HEADER buffer,
          ULONG const bufferByteSize,
          BOOLEAN const currentOnly, // TRUE == can drive write now, FALSE == can drive ever write
    __out PBOOLEAN writable,
    __out PFEATURE_NUMBER validationSchema,
    __out PULONG blockingFactor
    )
{
    //
    // this routine is used to check if the drive can currently (current==TRUE)
    // or can ever (current==FALSE) write to media with the current CDROM.SYS
    // driver.  this check parses the GET_CONFIGURATION response data to search
    // for the appropriate features and/or if they are current.
    //
    // this function should not allocate any resources, and thus may safely
    // return from any point within the function.
    //
    PAGED_CODE();

    *writable = FALSE;
    *validationSchema = 0;
    *blockingFactor = 1;


    //
    // if the drive supports hardware defect management and random writes, that's
    // sufficient to allow writes.
    //
    {
        PFEATURE_HEADER defectHeader;
        PFEATURE_HEADER writableHeader;

        defectHeader   = CdRomFindFeaturePage(buffer,
                                              bufferByteSize,
                                              FeatureDefectManagement);
        writableHeader = CdRomFindFeaturePage(buffer,
                                              bufferByteSize,
                                              FeatureRandomWritable);

        if (defectHeader == NULL || writableHeader == NULL)
        {
            // cannot write this way
        }
        else if (!currentOnly)
        {
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                        "CdRomUpdateMmc => Writes supported (defect management)\n"));
            *writable = TRUE;
            return;
        }
        else if (defectHeader->Current && writableHeader->Current)
        {
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                        "CdRomUpdateMmc => Writes *allowed* (defect management)\n"));
            *writable = TRUE;
            *validationSchema = FeatureDefectManagement;
            return;
        }
    }

    //
    // Certain validation schema require the blocking factor
    // This is a best-effort attempt to ensure that illegal
    // requests do not make it to drive
    //
    {
        PFEATURE_HEADER header;
        ULONG additionalLength;

        //
        // Certain validation schema require the blocking factor
        // This is a best-effort attempt to ensure  that illegal
        // requests do not make it to drive
        //
        additionalLength = RTL_SIZEOF_THROUGH_FIELD(FEATURE_DATA_RANDOM_READABLE, Blocking) - sizeof(FEATURE_HEADER);

        header = CdRomFindFeaturePage(buffer,
                                      bufferByteSize,
                                      FeatureRandomReadable);

        if (header != NULL && header->Current &&
            header->AdditionalLength >= additionalLength)
        {

            PFEATURE_DATA_RANDOM_READABLE feature = (PFEATURE_DATA_RANDOM_READABLE)header;
            *blockingFactor = (feature->Blocking[0] << 8) | feature->Blocking[1];
        }
    }

    //
    // the majority of features to indicate write capability
    // indicate this by a single feature existance/current bit.
    // thus, can use a table-based method for the majority
    // of the detection....
    //
    {
        typedef struct {
            FEATURE_NUMBER  FeatureToFind;    // the ones allowed
            FEATURE_NUMBER  ValidationSchema; // and their related schema
        } FEATURE_TO_WRITE_SCHEMA_MAP;

        static FEATURE_TO_WRITE_SCHEMA_MAP const FeaturesToAllowWritesWith[] = {
            { FeatureRandomWritable,               FeatureRandomWritable               },
            { FeatureRigidRestrictedOverwrite,     FeatureRigidRestrictedOverwrite     },
            { FeatureRestrictedOverwrite,          FeatureRestrictedOverwrite          },
            { FeatureIncrementalStreamingWritable, FeatureIncrementalStreamingWritable },
        };

        ULONG xyzzy;
        for (xyzzy = 0; xyzzy < RTL_NUMBER_OF(FeaturesToAllowWritesWith); xyzzy++)
        {
            PFEATURE_HEADER header = CdRomFindFeaturePage(buffer,
                                                          bufferByteSize,
                                                          FeaturesToAllowWritesWith[xyzzy].FeatureToFind);
            if (header == NULL)
            {
                // cannot write using this method
            }
            else if (!currentOnly)
            {
                TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                            "CdRomUpdateMmc => Writes supported (feature %04x)\n",
                            FeaturesToAllowWritesWith[xyzzy].FeatureToFind
                            ));
                *writable = TRUE;
                return;
            }
            else if (header->Current)
            {
                TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                            "CdRomUpdateMmc => Writes *allowed* (feature %04x)\n",
                            FeaturesToAllowWritesWith[xyzzy].FeatureToFind
                            ));
                *writable = TRUE;
                *validationSchema = FeaturesToAllowWritesWith[xyzzy].ValidationSchema;
                return;
            }
        } // end xyzzy loop
    }

    //
    // unfortunately, DVD+R media doesn't require IncrementalStreamingWritable feature
    // to be explicitly set AND it has a seperate bit in the feature to indicate
    // being able to write to this media type. Thus, use a special case of the above code.
    //
    {
        PFEATURE_DATA_DVD_PLUS_R header;
        ULONG additionalLength = FIELD_OFFSET(FEATURE_DATA_DVD_PLUS_R, Reserved2[0]) - sizeof(FEATURE_HEADER);
        header = CdRomFindFeaturePage(buffer,
                                      bufferByteSize,
                                      FeatureDvdPlusR);

        if (header == NULL || (header->Header.AdditionalLength < additionalLength) || (!header->Write))
        {
            // cannot write this way
        }
        else if (!currentOnly)
        {
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                        "CdRomUpdateMmc => Writes supported (feature %04x)\n",
                        FeatureDvdPlusR
                        ));
            *writable = TRUE;
            return;
        }
        else if (header->Header.Current)
        {
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                        "CdRomUpdateMmc => Writes *allowed* (feature %04x)\n",
                        FeatureDvdPlusR
                        ));
            *writable = TRUE;
            *validationSchema = FeatureIncrementalStreamingWritable;
            return;
        }
    }

    //
    // unfortunately, DVD+R DL media doesn't require IncrementalStreamingWritable feature
    // to be explicitly set AND it has a seperate bit in the feature to indicate
    // being able to write to this media type. Thus, use a special case of the above code.
    //
    {
        PFEATURE_DATA_DVD_PLUS_R_DUAL_LAYER header;
        ULONG additionalLength = FIELD_OFFSET(FEATURE_DATA_DVD_PLUS_R_DUAL_LAYER, Reserved2[0]) - sizeof(FEATURE_HEADER);
        header = CdRomFindFeaturePage(buffer,
                                      bufferByteSize,
                                      FeatureDvdPlusRDualLayer);

        if (header == NULL || (header->Header.AdditionalLength < additionalLength) || (!header->Write))
        {
            // cannot write this way
        }
        else if (!currentOnly)
        {
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                        "CdRomUpdateMmc => Writes supported (feature %04x)\n",
                        FeatureDvdPlusRDualLayer
                        ));
            *writable = TRUE;
            return;
        }
        else if (header->Header.Current)
        {
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                        "CdRomUpdateMmc => Writes *allowed* (feature %04x)\n",
                        FeatureDvdPlusRDualLayer
                        ));
            *writable = TRUE;
            *validationSchema = FeatureIncrementalStreamingWritable;
            return;
        }
    }

    //
    // There are currently a number of drives on the market
    // that fail to report:
    // (a) FeatureIncrementalStreamingWritable as current
    //     for CD-R / DVD-R profile.
    // (b) FeatureRestrictedOverwrite as current for CD-RW
    //     profile
    // (c) FeatureRigidRestrictedOverwrite as current for
    //     DVD-RW profile
    //
    // Thus, use the profiles also.
    //
    {
        PFEATURE_HEADER header;
        header = CdRomFindFeaturePage(buffer,
                                      bufferByteSize,
                                      FeatureProfileList);

        if (header != NULL && header->Current)
        {
            //
            // verify buffer bounds -- the below routine presumes full profile list provided
            //
            PUCHAR bufferEnd = ((PUCHAR)buffer) + bufferByteSize;
            PUCHAR headerEnd = ((PUCHAR)header) + header->AdditionalLength + RTL_SIZEOF_THROUGH_FIELD(FEATURE_HEADER, AdditionalLength);
            if (bufferEnd >= headerEnd) // this _should_ never occurr, but....
            {
                //
                // Profiles don't contain any data other than current/not current.
                // thus, can generically loop through them to see if any of the
                // below (in order of preference) are current.
                //
                typedef struct {
                    FEATURE_PROFILE_TYPE ProfileToFind;    // the ones allowed
                    FEATURE_NUMBER       ValidationSchema; // and their related schema
                } PROFILE_TO_WRITE_SCHEMA_MAP;

                static PROFILE_TO_WRITE_SCHEMA_MAP const ProfilesToAllowWritesWith[] = {
                    { ProfileDvdRewritable,  FeatureRigidRestrictedOverwrite     },
                    { ProfileCdRewritable,   FeatureRestrictedOverwrite },
                    { ProfileDvdRecordable,  FeatureIncrementalStreamingWritable },
                    { ProfileCdRecordable,   FeatureIncrementalStreamingWritable },
                };

                ULONG xyzzy;
                for (xyzzy = 0; xyzzy < RTL_NUMBER_OF(ProfilesToAllowWritesWith); xyzzy++)
                {
                    BOOLEAN exists = FALSE;
                    CdRomFindProfileInProfiles((PFEATURE_DATA_PROFILE_LIST)header,
                                               ProfilesToAllowWritesWith[xyzzy].ProfileToFind,
                                               currentOnly,
                                               &exists
                                               );
                    if (exists)
                    {
                        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
                                    "CdRomUpdateMmc => Writes %s (profile %04x)\n",
                                    (currentOnly ? "*allowed*" : "supported"),
                                    FeatureDvdPlusR
                                    ));

                        *writable = TRUE;
                        *validationSchema = ProfilesToAllowWritesWith[xyzzy].ValidationSchema;
                        return;
                    }
                } // end xyzzy loop
            } // end if (bufferEnd >= headerEnd)

        } // end if (header != NULL && header->Current)
    }

    // nothing matched to say it's writable.....
    return;
}

VOID
CdRomUpdateMmcDriveCapabilities(
    __in PDEVICE_OBJECT Fdo,
    __reserved PVOID Context
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PCDROM_DATA cdData = fdoExtension->CommonExtension.DriverData;
    PCDROM_MMC_EXTENSION mmcData = &(cdData->Mmc);
    PIO_STACK_LOCATION thisStack = IoGetCurrentIrpStackLocation(mmcData->CapabilitiesIrp);
    PSCSI_REQUEST_BLOCK srb = &(mmcData->CapabilitiesSrb);
    NTSTATUS status;

    PAGED_CODE();

    UNREFERENCED_PARAMETER(Context);
    ASSERT(Context == NULL);

    //
    // NOTE: a remove lock is unneccessary, since the delayed irp
    // will have said lock held for itself, preventing a remove.
    //
    CdRomPrepareUpdateCapabilitiesIrp(Fdo);

    ASSERT(thisStack->Parameters.Others.Argument1 == Fdo);
    ASSERT(thisStack->Parameters.Others.Argument2 == mmcData->CapabilitiesBuffer);
    ASSERT(thisStack->Parameters.Others.Argument3 == &(mmcData->CapabilitiesSrb));

    mmcData->WriteAllowed = FALSE; // default to read-only

    //
    // set max retries, and also allow volume verify override based on
    // original (delayed) irp
    //

    thisStack->Parameters.Others.Argument4 = (PVOID)MAXIMUM_RETRIES;

    //
    // send to self... note that SL_OVERRIDE_VERIFY_VOLUME is not required,
    // as this is IRP_MJ_INTERNAL_DEVICE_CONTROL
    //

    IoCallDriver(commonExtension->LowerDeviceObject, mmcData->CapabilitiesIrp);

    KeWaitForSingleObject(&mmcData->CapabilitiesEvent,
                          Executive, KernelMode, FALSE, NULL);

    status = mmcData->CapabilitiesIrp->IoStatus.Status;

    if (!NT_SUCCESS(status)) {

        goto FinishDriveUpdate;

    }

    //
    // we've updated the feature set, so update whether or not reads and writes
    // are allowed or not.
    //

    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_INIT,
               "CdRomUpdateMmc => Succeeded "
               "--------------------"
               "--------------------\n"));

    /*++

    NOTE: It is important to only use srb->DataTransferLength worth
          of data at this point, since the bufferSize is what is
          *available* to use, not what was *actually* used.

    --*/

#if DBG
    CdRompPrintAllFeaturePages(mmcData->CapabilitiesBuffer,
                               srb->DataTransferLength);
#endif // DBG

    //
    // update whether or not writes are allowed
    // this should be the *ONLY* place writes are set to allowed
    //
    {
        BOOLEAN writeAllowed = FALSE;
        FEATURE_NUMBER validationSchema = 0;
        ULONG blockingFactor = 1;

        CdRompUpdateMmcWriteCapability(mmcData->CapabilitiesBuffer,
                                      srb->DataTransferLength,
                                      TRUE,
                                      &writeAllowed,
                                      &validationSchema,
                                      &blockingFactor
                                      );

        mmcData->WriteAllowed = writeAllowed;
        mmcData->ValidationSchema = validationSchema;
        mmcData->Blocking = blockingFactor;
    }

    //
    // Update the guesstimate for the drive's write speed
    // Use the GetConfig profile first as a quick-guess based
    // on media "type", then continue with media-specific
    // queries for older media types, and use GET_PERFORMANCE
    // for all unknown/future media types.
    //
    {
        // pseudo-code:
        // 1) Determine default based on profile (slowest for media)
        // 2) Determine default based on MODE PAGE 2Ah
        // 3) Determine default based on GET PERFORMANCE data
        // 4) Choose fastest reported speed (-1 == none reported)
        // 5) If all failed (returned -1), go with very safe (slow) default
        //
        // This ensures that the retries do not overload the drive's processor.
        // Sending at highest possible speed for the media is OK, because the
        // major downside is drive processor usage.  (bus usage too, but most
        // storage is becoming a point-to-point link.)

        FEATURE_PROFILE_TYPE const profile =
            mmcData->CapabilitiesBuffer->CurrentProfile[0] << (8*1) |
            mmcData->CapabilitiesBuffer->CurrentProfile[1] << (8*0) ;
        LONGLONG t1;
        LONGLONG t2;
        LONGLONG t3;
        LONGLONG t4;
        LONGLONG final;

        t1 = CdRompRetryTimeGuessBasedOnProfile(profile);
        t2 = CdRompRetryTimeDetectionBasedOnModePage2A(Fdo);
        t3 = CdRompRetryTimeDetectionBasedOnGetPerformance(Fdo, TRUE);
        t4 = CdRompRetryTimeDetectionBasedOnGetPerformance(Fdo, FALSE);

        // use the "fastest" value returned
        final = MAXLONGLONG;
        if (t4 != -1)
        {
            final = min(final, t4);
        }
        if (t3 != -1)
        {
            final = min(final, t3);
        }
        if (t2 != -1)
        {
            final = min(final, t2);
        }
        if (t1 != -1)
        {
            final = min(final, t1);
        }
        if (final == MAXLONGLONG)
        {
            // worst case -- use relatively slow default....
            final = WRITE_RETRY_DELAY_CD_4x;
        }

        cdData->ReadWriteRetryDelay100nsUnits = final;
    }

    status = STATUS_SUCCESS;

FinishDriveUpdate:

    CdRompFlushDelayedList(Fdo, mmcData, status, TRUE);

    return;
}

__range(-1,MAXIMUM_RETRY_FOR_SINGLE_IO_IN_100NS_UNITS)
LONGLONG
CdRompRetryTimeGuessBasedOnProfile(
    FEATURE_PROFILE_TYPE const Profile
    )
{
    LONGLONG result = -1; // this means we have no idea
    switch (Profile)
    {
    case ProfileInvalid:               // = 0x0000,
    case ProfileNonRemovableDisk:      // = 0x0001,
    case ProfileRemovableDisk:         // = 0x0002,
    case ProfileMOErasable:            // = 0x0003,
    case ProfileMOWriteOnce:           // = 0x0004,
    case ProfileAS_MO:                 // = 0x0005,
    // Reserved                             0x0006 - 0x0007,
    // Reserved                             0x000b - 0x000f,
    // Reserved                             0x0017 - 0x0019
    // Reserved                             0x001C - 001F
    // Reserved                             0x0023 - 0x0029
    // Reserved                             0x002C - 0x003F
    // Reserved                             0x0044 - 0x004F
    // Reserved                             0x0053 - 0xfffe
    case ProfileNonStandard:          //  = 0xffff
    default:
    {
        NOTHING; // no default
        break;
    }

    case ProfileCdrom:                 // = 0x0008,
    case ProfileCdRecordable:          // = 0x0009,
    case ProfileCdRewritable:          // = 0x000a,
    case ProfileDDCdrom:               // = 0x0020, // obsolete
    case ProfileDDCdRecordable:        // = 0x0021, // obsolete
    case ProfileDDCdRewritable:        // = 0x0022, // obsolete
    {
        // 4x is ok as all CD drives have
        // at least 64k*4 (256k) buffer
        // and this is just a first-pass
        // guess based only on profile
        result = WRITE_RETRY_DELAY_CD_4x;
        break;
    }
    case ProfileDvdRom:                // = 0x0010,
    case ProfileDvdRecordable:         // = 0x0011,
    case ProfileDvdRam:                // = 0x0012,
    case ProfileDvdRewritable:         // = 0x0013,  // restricted overwrite
    case ProfileDvdRWSequential:       // = 0x0014,
    case ProfileDvdDashRLayerJump:     // = 0x0016,
    case ProfileDvdPlusRW:             // = 0x001A,
    case ProfileDvdPlusR:              // = 0x001B,
    {
        result = WRITE_RETRY_DELAY_DVD_1x;
        break;
    }
    case ProfileDvdDashRDualLayer:     // = 0x0015,
    case ProfileDvdPlusRWDualLayer:    // = 0x002A,
    case ProfileDvdPlusRDualLayer:     // = 0x002B,
    {
        result = WRITE_RETRY_DELAY_DVD_1x;
        break;
    }

    case ProfileBDRom:                 // = 0x0040,
    case ProfileBDRSequentialWritable: // = 0x0041,  // BD-R 'SRM'
    case ProfileBDRRandomWritable:     // = 0x0042,  // BD-R 'RRM'
    case ProfileBDRewritable:          // = 0x0043,
    {
        // I could not find specifications for the
        // minimal 1x data rate for BD media.  Use
        // HDDVD values for now, since they are
        // likely to be similar.  Also, all media
        // except for CD, DVD, and AS-MO should
        // already fully support GET_CONFIG, so
        // this guess is only used if we fail to
        // get a performance descriptor....
        result = WRITE_RETRY_DELAY_HDDVD_1x;
        break;
    }

    case ProfileHDDVDRom:              // = 0x0050,
    case ProfileHDDVDRecordable:       // = 0x0051,
    case ProfileHDDVDRam:              // = 0x0052,
    {
        // All HDDVD drives support GET_PERFORMANCE
        // so this guess is fine at 1x....
        result = WRITE_RETRY_DELAY_HDDVD_1x;
        break;
    }

    // addition of any further profile types is not
    // technically required as GET PERFORMANCE
    // should succeed for all future drives.  However,
    // it is useful in case GET PERFORMANCE does
    // fail for other reasons (i.e. bus resets, etc)

    } // end switch(Profile)


    return result;
}

__range(-1,MAXIMUM_RETRY_FOR_SINGLE_IO_IN_100NS_UNITS)
LONGLONG
CdRompRetryTimeDetectionBasedOnModePage2A(
    __in PDEVICE_OBJECT Fdo
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCDROM_DATA cdData = fdoExtension->CommonExtension.DriverData;


    NTSTATUS status;
    ULONG timesAlreadyRetried = 0;
    BOOLEAN shouldRetry = TRUE;
    LONGLONG retryIn100nsUnits = 0;
    LONGLONG result = -1;

    ScratchBuffer_BeginUse(cdData);

    while (shouldRetry)
    {
        PSCSI_REQUEST_BLOCK srb = cdData->ScratchSrb;
        PCDB cdb = (PCDB)(srb->Cdb);
        ULONG transferSize = min(0xFFF0, cdData->ScratchBufferSize);

        ASSERT(transferSize >= 1024);

        ScratchBuffer_SetupForSynchronousSrb(fdoExtension, 0xFFF0, TRUE);
    
        cdb->MODE_SENSE10.OperationCode = SCSIOP_MODE_SENSE10;
        cdb->MODE_SENSE10.Dbd           = 1;
        cdb->MODE_SENSE10.PageCode      = MODE_PAGE_CAPABILITIES;
        cdb->MODE_SENSE10.AllocationLength[0] = (UCHAR)(transferSize >> 8);
        cdb->MODE_SENSE10.AllocationLength[1] = (UCHAR)(transferSize & 0xFF);
        srb->CdbLength = 10;
    
        ScratchBuffer_SendSynchronousSrb(fdoExtension);
    
        shouldRetry = ScratchBuffer_InterpretSrbError(fdoExtension,
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
    }

    // analyze the data on success....
    if (NT_SUCCESS(status))
    {
        MODE_PARAMETER_HEADER10 const * header = cdData->ScratchBuffer;
        CDVD_CAPABILITIES_PAGE const * page = NULL;
        ULONG dataLength =
            (header->ModeDataLength[0] << (8*1)) |
            (header->ModeDataLength[1] << (8*0)) ;

        // no possible overflow
        if (dataLength != 0)
        {
            dataLength += RTL_SIZEOF_THROUGH_FIELD(MODE_PARAMETER_HEADER10, ModeDataLength);
        }

        // If it's not abundantly clear, we really don't trust the drive
        // to be returning valid data.  Get the page pointer and usable
        // size of the page here...
        if (dataLength < sizeof(MODE_PARAMETER_HEADER10))
        {
            dataLength = 0;
        }
        else if (dataLength > cdData->ScratchBufferSize)
        {
            dataLength = 0;
        }
        else if ((header->BlockDescriptorLength[1] == 0) &&
                 (header->BlockDescriptorLength[0] == 0))
        {
            dataLength -= sizeof(MODE_PARAMETER_HEADER10);
            page = (CDVD_CAPABILITIES_PAGE const *)(header + 1);
        }
        else if ((header->BlockDescriptorLength[1] == 0) &&
                 (header->BlockDescriptorLength[0] == sizeof(MODE_PARAMETER_BLOCK)))
        {
            dataLength -= sizeof(MODE_PARAMETER_HEADER10);
            dataLength -= min(dataLength, sizeof(MODE_PARAMETER_BLOCK));
            page = (CDVD_CAPABILITIES_PAGE const *)
                ( ((UCHAR)header) +
                  sizeof(MODE_PARAMETER_HEADER10) +
                  sizeof(MODE_PARAMETER_BLOCK)
                  );
        }

        // Change dataLength from the size available per the header to
        // the size available per the page itself.
        if ((page != NULL) &&
            (dataLength >= RTL_SIZEOF_THROUGH_FIELD(CDVD_CAPABILITIES_PAGE, PageLength))
            )
        {
            dataLength = min(dataLength, ((ULONG)(page->PageLength) + 2));
        }

        // Ignore the page if the fastest write speed field isn't available.
        if ((page != NULL) &&
            (dataLength < RTL_SIZEOF_THROUGH_FIELD(CDVD_CAPABILITIES_PAGE, WriteSpeedMaximum))
            )
        {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                        "ModePage 2Ah was requested, but drive reported "
                        "only %x bytes (%x needed). Ignoring.\n",
                        dataLength,
                        RTL_SIZEOF_THROUGH_FIELD(CDVD_CAPABILITIES_PAGE, WriteSpeedMaximum)
                        ));
            page = NULL;
        }

        // Verify the page we requested is the one the drive actually provided
        if ((page != NULL) && (page->PageCode != MODE_PAGE_CAPABILITIES))
        {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                        "ModePage 2Ah was requested, but drive reported "
                        "page %x\n",
                        page->PageCode
                        ));
            page = NULL;
        }

        // If _everything_ succeeded, then use the speed value in the page!
        if (page != NULL)
        {
            ULONG temp =
                (page->WriteSpeedMaximum[0] << (8*1)) |
                (page->WriteSpeedMaximum[1] << (8*0)) ;
            // stored as 1,000 byte increments...
            temp *= 1000;
            // typically stored at 2448 bytes/sector due to CD media
            // error up to 20% high by presuming it returned 2048 data
            // and convert to sectors/second
            temp /= 2048;
            // currently: sectors/sec
            // ignore too-small or zero values
            if (temp != 0)
            {
                result = ConvertSectorsPerSecondTo100nsUnitsFor64kWrite(temp);
            }
        }
    }


    ScratchBuffer_EndUse(cdData);

    return result;
}

__range(-1,MAXIMUM_RETRY_FOR_SINGLE_IO_IN_100NS_UNITS)
LONGLONG
CdRompRetryTimeDetectionBasedOnGetPerformance(
    __in PDEVICE_OBJECT Fdo,
    BOOLEAN UseLegacyNominalPerformance
    )
{
    typedef struct _GET_PERFORMANCE_HEADER {
        UCHAR TotalDataLength[4]; // not including this field
        UCHAR Except : 1;
        UCHAR Write  : 1;
        UCHAR Reserved0 : 6;
        UCHAR Reserved1[3];
    } GET_PERFORMANCE_HEADER, *PGET_PERFORMANCE_HEADER;
    C_ASSERT( sizeof(GET_PERFORMANCE_HEADER) == 8);

    typedef struct _GET_PERFORMANCE_NOMINAL_PERFORMANCE_DESCRIPTOR {
        UCHAR StartLba[4];
        UCHAR StartPerformance[4];
        UCHAR EndLba[4];
        UCHAR EndPerformance[4];
    } GET_PERFORMANCE_NOMINAL_PERFORMANCE_DESCRIPTOR, *PGET_PERFORMANCE_NOMINAL_PERFORMANCE_DESCRIPTOR;
    C_ASSERT( sizeof(GET_PERFORMANCE_NOMINAL_PERFORMANCE_DESCRIPTOR) == 16);


    typedef struct _GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR {
        UCHAR MixedReadWrite          : 1;
        UCHAR GuaranteedForWholeMedia : 1;
        UCHAR Reserved0_RDD           : 1;
        UCHAR WriteRotationControl    : 2;
        UCHAR Reserved1               : 3;
        UCHAR Reserved2[3];

        UCHAR MediaCapacity[4];
        UCHAR ReadSpeedKilobytesPerSecond[4];
        UCHAR WriteSpeedKilobytesPerSecond[4];
    } GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR, *PGET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR;
    C_ASSERT( sizeof(GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR) == 16);

    


    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCDROM_DATA cdData = fdoExtension->CommonExtension.DriverData;


    NTSTATUS status;
    ULONG timesAlreadyRetried = 0;
    BOOLEAN shouldRetry = TRUE;
    LONGLONG retryIn100nsUnits = 0;
    LONGLONG result = -1;

    // transfer size -- descriptors + 8 byte header
    // Note: this size is identical for both descriptor types
    C_ASSERT( sizeof(GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR) == sizeof(GET_PERFORMANCE_NOMINAL_PERFORMANCE_DESCRIPTOR));

    ULONG const maxDescriptors = min(200, (cdData->ScratchBufferSize-sizeof(GET_PERFORMANCE_HEADER))/sizeof(GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR));
    ULONG validDescriptors = 0;

    ScratchBuffer_BeginUse(cdData);

    while (shouldRetry)
    {
        PSCSI_REQUEST_BLOCK srb = cdData->ScratchSrb;
        PCDB cdb = (PCDB)(srb->Cdb);
        C_ASSERT( sizeof(GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR) == sizeof(GET_PERFORMANCE_NOMINAL_PERFORMANCE_DESCRIPTOR) );


        // this is needed, to reset the IRP, etc.
        ScratchBuffer_ResetItems(cdData, FALSE);

        // Note: this size is identical for both descriptor types
        ScratchBuffer_SetupForSynchronousSrb(fdoExtension,
                                             sizeof(GET_PERFORMANCE_HEADER) + (maxDescriptors*sizeof(GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR)),
                                             TRUE);

        if (UseLegacyNominalPerformance)
        {
            cdb->GET_PERFORMANCE.OperationCode = SCSIOP_GET_PERFORMANCE;
            cdb->GET_PERFORMANCE.Except = 0;
            cdb->GET_PERFORMANCE.Write = 1;
            cdb->GET_PERFORMANCE.Tolerance = 2; // only defined option
            cdb->GET_PERFORMANCE.MaximumNumberOfDescriptors[1] = (UCHAR)maxDescriptors;
            cdb->GET_PERFORMANCE.Type = 0; // legacy nominal descriptors
            srb->CdbLength = 12;
        }
        else
        {
            cdb->GET_PERFORMANCE.OperationCode = SCSIOP_GET_PERFORMANCE;
            cdb->GET_PERFORMANCE.MaximumNumberOfDescriptors[1] = (UCHAR)maxDescriptors;
            cdb->GET_PERFORMANCE.Type = 3; // write speed
            srb->CdbLength = 12;
        }

        ScratchBuffer_SendSynchronousSrb(fdoExtension);

        shouldRetry = ScratchBuffer_InterpretSrbError(fdoExtension,
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
    }

    // determine how many valid descriptors there actually are
    if (NT_SUCCESS(status))
    {
        GET_PERFORMANCE_HEADER const * header = (GET_PERFORMANCE_HEADER const *)cdData->ScratchBuffer;
        ULONG temp1 =
            (header->TotalDataLength[0] << (8*3)) |
            (header->TotalDataLength[1] << (8*2)) |
            (header->TotalDataLength[2] << (8*1)) |
            (header->TotalDataLength[3] << (8*0)) ;

        // adjust data size for header
        if (temp1 + RTL_SIZEOF_THROUGH_FIELD(GET_PERFORMANCE_HEADER, TotalDataLength) < temp1)
        {
            temp1 = 0;
        }
        else if (temp1 != 0)
        {
            temp1 += RTL_SIZEOF_THROUGH_FIELD(GET_PERFORMANCE_HEADER, TotalDataLength);
        }

        if (temp1 == 0)
        {
            // no data returned
        }
        else if (temp1 <= sizeof(GET_PERFORMANCE_HEADER))
        {
            // only the header returned, no descriptors
        }
        else if (UseLegacyNominalPerformance &&
                 ((header->Except != 0) || (header->Write == 0))
                 )
        {
            // bad data being returned -- ignore it
        }
        else if (!UseLegacyNominalPerformance &&
                 ((header->Except != 0) || (header->Write != 0))
                 )
        {
            // returning Performance (Type 0) data, not requested Write Speed (Type 3) data
        }
        else if ( (temp1 - sizeof(GET_PERFORMANCE_HEADER)) % sizeof(GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR) != 0)
        {
            // Note: this size is identical for both descriptor types
            C_ASSERT( sizeof(GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR) == sizeof(GET_PERFORMANCE_NOMINAL_PERFORMANCE_DESCRIPTOR));

            // not returning valid data....
        }
        else // save how many are usable
        {
            // Note: this size is identical for both descriptor types
            C_ASSERT( sizeof(GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR) == sizeof(GET_PERFORMANCE_NOMINAL_PERFORMANCE_DESCRIPTOR));

            // take the smaller usable value
            temp1 = min(temp1, cdData->ScratchSrb->DataTransferLength);
            // then determine the usable descriptors
            validDescriptors = (temp1 - sizeof(GET_PERFORMANCE_HEADER)) / sizeof(GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR);
        }
    }

    // The drive likely supports this command.
    // Verify the data makes sense.
    if (NT_SUCCESS(status))
    {
        ULONG i;
        GET_PERFORMANCE_HEADER const * header = (GET_PERFORMANCE_HEADER const *)cdData->ScratchBuffer;
        GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR const * descriptor = (GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR const *)(header+1); // pointer math

        // NOTE: We could write this loop twice, once for each write descriptor type
        //       However, the only fields of interest are the writeKBps field (Type 3) and
        //       the EndPerformance field (Type 0), which both exist in the same exact
        //       location and have essentially the same meaning.  So, just use the same
        //       loop/structure pointers for both of the to simplify the readability of
        //       this code.  The C_ASSERT()s here verify this at compile-time.

        C_ASSERT( sizeof(GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR) == sizeof(GET_PERFORMANCE_NOMINAL_PERFORMANCE_DESCRIPTOR));
        C_ASSERT( FIELD_OFFSET(GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR, WriteSpeedKilobytesPerSecond) ==
                  FIELD_OFFSET(GET_PERFORMANCE_NOMINAL_PERFORMANCE_DESCRIPTOR, EndPerformance)
                  );
        C_ASSERT( RTL_FIELD_SIZE(GET_PERFORMANCE_WRITE_SPEED_DESCRIPTOR, WriteSpeedKilobytesPerSecond) ==
                  RTL_FIELD_SIZE(GET_PERFORMANCE_NOMINAL_PERFORMANCE_DESCRIPTOR, EndPerformance)
                  );

        // loop through them all, and find the fastest listed write speed
        for (i = 0; NT_SUCCESS(status) && (i <validDescriptors); descriptor++, i++)
        {
            ULONG const writeKBps =
                (descriptor->WriteSpeedKilobytesPerSecond[0] << (8*3)) |
                (descriptor->WriteSpeedKilobytesPerSecond[1] << (8*2)) |
                (descriptor->WriteSpeedKilobytesPerSecond[2] << (8*1)) |
                (descriptor->WriteSpeedKilobytesPerSecond[3] << (8*0)) ;

            // Avoid overflow and still have good estimates
            // 0x1 0000 0000 / 1000  == 0x00418937 == maximum writeKBps to multiple first
            ULONG const sectorsPerSecond =
                (writeKBps > 0x00418937) ? // would overflow occur by multiplying by 1000?
                ((writeKBps / 2048) * 1000) : // must divide first, minimal loss of accuracy
                ((writeKBps * 1000) / 2048) ; // must multiply first, avoid loss of accuracy

            if (sectorsPerSecond <= 0)
            {
                break; // out of the loop -- no longer valid data (very defensive programming)
            }

            // we have at least one valid result, so prevent returning -1 as our result
            if (result == -1) { result = MAXLONGLONG; }

            // take the fastest speed (smallest wait time) we've found thus far
            result = min(result, ConvertSectorsPerSecondTo100nsUnitsFor64kWrite(sectorsPerSecond));
        }
    }

    ScratchBuffer_EndUse(cdData);
    
    return result;
}

// NOTE: cannot be paged due to spinlock acquisition
VOID
CdRompFlushDelayedList(
    __in PDEVICE_OBJECT Fdo,
    __in PCDROM_MMC_EXTENSION MmcData,
         NTSTATUS Status,
         BOOLEAN const CalledFromWorkItem
    )
{
    LIST_ENTRY irpList;
    PLIST_ENTRY listEntry;
    KIRQL oldIrql;

    // NOTE - REF #0002
    //
    // need to set the new state first to prevent deadlocks.
    // this is only done from the workitem, to prevent any
    // edge cases where we'd "lose" the UpdateRequired
    //
    // then, must ignore the state, since it's not guaranteed to
    // be the same any longer.  the only thing left is to handle
    // all the delayed irps by flushing the queue and sending them
    // back onto the StartIo queue for the device.
    //

    if (CalledFromWorkItem) {

        LONG oldState;
        LONG newState;

        if (NT_SUCCESS(Status)) {
            newState = CdromMmcUpdateComplete;
        } else {
            newState = CdromMmcUpdateRequired;
        }

        oldState = InterlockedCompareExchange(&MmcData->UpdateState,
                                              newState,
                                              CdromMmcUpdateStarted);
        ASSERT(oldState == CdromMmcUpdateStarted);

    } else {

        //
        // just flushing the queue if not called from the workitem,
        // and we don't want to ever fail the queue in those cases.
        //

        ASSERT(NT_SUCCESS(Status));

    }

    /*
     *  Get all the delayed IRPs into a private list first to avoid an infinite loop
     *  where irps are added to the DelayedIrpsList while we are siphoning them off.
     */
    InitializeListHead(&irpList);
    KeAcquireSpinLock(&MmcData->DelayedIrpsLock, &oldIrql);
    while (!IsListEmpty(&MmcData->DelayedIrpsList)){
        listEntry = RemoveHeadList(&MmcData->DelayedIrpsList);
        InsertTailList(&irpList, listEntry);
        ASSERT(MmcData->NumDelayedIrps > 0);
        MmcData->NumDelayedIrps--;
    }
    ASSERT(MmcData->NumDelayedIrps == 0);
    KeReleaseSpinLock(&MmcData->DelayedIrpsLock, oldIrql);

    // if this assert fires, it means that we have started
    // a workitem when the previous workitem took the delayed
    // irp.  if this happens, then the logic in HACKHACK #0002
    // is either flawed or the rules set within are not being
    // followed.  this would require investigation.
    ASSERT(!IsListEmpty(&irpList));

    //
    // now either succeed or fail all the delayed irps, according
    // to the update status.
    //

    while (!IsListEmpty(&irpList)){
        PIRP irp;

        listEntry = RemoveHeadList(&irpList);
        irp = CONTAINING_RECORD(listEntry, IRP, Tail.Overlay.ListEntry);

        irp->Tail.Overlay.DriverContext[0] = 0;
        irp->Tail.Overlay.DriverContext[1] = 0;
        irp->Tail.Overlay.DriverContext[2] = 0;
        irp->Tail.Overlay.DriverContext[3] = 0;

        if (NT_SUCCESS(Status)) {

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,
                       "CdRomUpdateMmc => Re-sending delayed irp %p\n",
                       irp));
            IoStartPacket(Fdo, irp, NULL, NULL);

        } else {

            PIO_STACK_LOCATION irpStack = IoGetCurrentIrpStackLocation(irp);

            if (irpStack->Flags & SL_OVERRIDE_VERIFY_VOLUME &&
                Status == STATUS_VERIFY_REQUIRED) {

                Status = STATUS_IO_DEVICE_ERROR;
            }

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,
                       "CdRomUpdateMmc => Failing delayed irp %p with "
                       " status %x\n", irp, Status));
            irp->IoStatus.Information = 0;
            irp->IoStatus.Status = Status;
            ClassReleaseRemoveLock(Fdo, irp);
            IoCompleteRequest(irp, IO_CD_ROM_INCREMENT);

        }

    } // while (list)

    return;

}

VOID
CdRomDeAllocateMmcResources(
    __in PDEVICE_OBJECT Fdo
    )
{
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PCDROM_DATA cddata = commonExtension->DriverData;
    PCDROM_MMC_EXTENSION mmcData = &cddata->Mmc;
    NTSTATUS status;

    PAGED_CODE();

    if (mmcData->CapabilitiesWorkItem) {
        IoFreeWorkItem(mmcData->CapabilitiesWorkItem);
        mmcData->CapabilitiesWorkItem = NULL;
    }
    if (mmcData->CapabilitiesIrp) {
        IoFreeIrp(mmcData->CapabilitiesIrp);
        mmcData->CapabilitiesIrp = NULL;
    }
    if (mmcData->CapabilitiesMdl) {
        IoFreeMdl(mmcData->CapabilitiesMdl);
        mmcData->CapabilitiesMdl = NULL;
    }
    if (mmcData->CapabilitiesBuffer) {
        ExFreePool(mmcData->CapabilitiesBuffer);
        mmcData->CapabilitiesBuffer = NULL;
    }
    mmcData->CapabilitiesBuffer = 0;
    mmcData->IsMmc = FALSE;
    mmcData->WriteAllowed = FALSE;

    return;
}

NTSTATUS
CdRomAllocateMmcResources(
    __in PDEVICE_OBJECT Fdo
    )
{
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PCDROM_DATA cddata = commonExtension->DriverData;
    PCDROM_MMC_EXTENSION mmcData = &cddata->Mmc;
    PIO_STACK_LOCATION irpStack;
    NTSTATUS status;

    PAGED_CODE();

    ASSERT(mmcData->CapabilitiesWorkItem == NULL);
    ASSERT(mmcData->CapabilitiesIrp == NULL);
    ASSERT(mmcData->CapabilitiesMdl == NULL);
    ASSERT(mmcData->CapabilitiesBuffer == NULL);
    ASSERT(mmcData->CapabilitiesBufferSize == 0);

    status = CdRomGetConfiguration(Fdo,
                                   &mmcData->CapabilitiesBuffer,
                                   &mmcData->CapabilitiesBufferSize,
                                   FeatureProfileList,
                                   SCSI_GET_CONFIGURATION_REQUEST_TYPE_ALL);
    if (!NT_SUCCESS(status)) {
        ASSERT(mmcData->CapabilitiesBuffer     == NULL);
        ASSERT(mmcData->CapabilitiesBufferSize == 0);
        return status;
    }
    ASSERT(mmcData->CapabilitiesBuffer     != NULL);
    ASSERT(mmcData->CapabilitiesBufferSize != 0);

    mmcData->CapabilitiesMdl = IoAllocateMdl(mmcData->CapabilitiesBuffer,
                                             mmcData->CapabilitiesBufferSize,
                                             FALSE, FALSE, NULL);
    if (mmcData->CapabilitiesMdl == NULL) {
        ExFreePool(mmcData->CapabilitiesBuffer);
        mmcData->CapabilitiesBufferSize = 0;
        return STATUS_INSUFFICIENT_RESOURCES;
    }


    mmcData->CapabilitiesIrp = IoAllocateIrp(Fdo->StackSize + 2, FALSE);
    if (mmcData->CapabilitiesIrp == NULL) {
        IoFreeMdl(mmcData->CapabilitiesMdl);
        ExFreePool(mmcData->CapabilitiesBuffer);
        mmcData->CapabilitiesBufferSize = 0;
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    mmcData->CapabilitiesWorkItem = IoAllocateWorkItem(Fdo);
    if (mmcData->CapabilitiesWorkItem == NULL) {
        IoFreeIrp(mmcData->CapabilitiesIrp);
        IoFreeMdl(mmcData->CapabilitiesMdl);
        ExFreePool(mmcData->CapabilitiesBuffer);
        mmcData->CapabilitiesBufferSize = 0;
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    //
    // everything has been allocated, so now prepare it all....
    //

    MmBuildMdlForNonPagedPool(mmcData->CapabilitiesMdl);
    InitializeListHead(&mmcData->DelayedIrpsList);
    KeInitializeSpinLock(&mmcData->DelayedIrpsLock);
    mmcData->NumDelayedIrps = 0;

    //
    // use the extra stack for internal bookkeeping
    //
    IoSetNextIrpStackLocation(mmcData->CapabilitiesIrp);
    irpStack = IoGetCurrentIrpStackLocation(mmcData->CapabilitiesIrp);
    irpStack->Parameters.Others.Argument1 = Fdo;
    irpStack->Parameters.Others.Argument2 = mmcData->CapabilitiesBuffer;
    irpStack->Parameters.Others.Argument3 = &(mmcData->CapabilitiesSrb);
    // arg 4 is the retry count

    //
    // set the completion event to FALSE for now
    //

    KeInitializeEvent(&mmcData->CapabilitiesEvent,
                      SynchronizationEvent, FALSE);
    return STATUS_SUCCESS;

}

VOID
CdRomUpdateTimeoutValueForMmcDevice(
    __in PDEVICE_OBJECT Fdo
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PCDROM_DATA cdData = commonExtension->DriverData;
    NTSTATUS status = STATUS_SUCCESS;

    PGET_CONFIGURATION_HEADER configBuffer;
    ULONG usable;

    PAGED_CODE();

    ScratchBuffer_BeginUse(cdData);
    configBuffer = cdData->ScratchBuffer;
    ASSERT(configBuffer != NULL);

    // get the list of _all_ features 
    status = CdRompGetConfiguration(Fdo,
                                    configBuffer,
                                    cdData->ScratchBufferSize,
                                    &usable,
                                    FeatureProfileList,
                                    SCSI_GET_CONFIGURATION_REQUEST_TYPE_ALL);

    if (NT_SUCCESS(status))
    {
        // check if it's writable
        BOOLEAN writable;
        FEATURE_NUMBER validationSchema;
        ULONG blockingFactor;
        CdRompUpdateMmcWriteCapability(configBuffer,
                                      usable,
                                      FALSE,
                                      &writable,
                                      &validationSchema,
                                      &blockingFactor);
        if (writable)
        {
            // OPC can really take this long per IMAPIv1 timeout....
            fdoExtension->TimeOutValue = max(fdoExtension->TimeOutValue, 260);
        }
    }
    ScratchBuffer_EndUse(cdData);
    return;
}


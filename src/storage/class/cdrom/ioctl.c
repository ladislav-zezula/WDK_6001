/*--

Copyright (C) Microsoft Corporation, 1999 - 1999

Module Name:

    ioctl.c

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

#include "stddef.h"
#include "string.h"

#include "ntddk.h"

#include "classpnp.h"
#include "ntddstor.h"
#include "cdrom.h"
#include "ioevent.h"
#include "ntintsafe.h"

#ifdef DEBUG_USE_WPP
#include "ioctl.tmh"
#endif

#ifdef ALLOC_PRAGMA

#pragma alloc_text(PAGE, CdRomDeviceControlExclusiveAccess)
#pragma alloc_text(PAGE, CdRomQueryLockState)
#pragma alloc_text(PAGE, CdRomLockDevice)
#pragma alloc_text(PAGE, CdRomUnlockDevice)

#endif

#if DBG
    PUCHAR READ_DVD_STRUCTURE_FORMAT_STRINGS[DvdMaxDescriptor+1] = {
        "Physical",
        "Copyright",
        "DiskKey",
        "BCA",
        "Manufacturer",
        "Unknown"
    };
#endif // DBG

#define DEFAULT_CDROM_SECTORS_PER_TRACK 32
#define DEFAULT_TRACKS_PER_CYLINDER     64



__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomDeviceControlDispatch(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    )
/*++

Routine Description:

    This is the NT device control handler for CDROMs.

Arguments:

    DeviceObject - for this CDROM

    Irp - IO Request packet

Return Value:

    NTSTATUS

--*/
{
    PFUNCTIONAL_DEVICE_EXTENSION  fdoExtension = DeviceObject->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = DeviceObject->DeviceExtension;

    PIO_STACK_LOCATION irpStack = IoGetCurrentIrpStackLocation(Irp);
    PIO_STACK_LOCATION nextStack;
    PCDROM_DATA        cdData = (PCDROM_DATA)(commonExtension->DriverData);

    PVOID outputBuffer;
    ULONG bytesTransferred = 0;
    NTSTATUS status;
    NTSTATUS status2;
    KIRQL    irql;

    ULONG ioctlCode;
    ULONG baseCode;
    ULONG functionCode;

    //
    // If the device is in exclusive mode, check whether the request is from
    // the handle that locked the device.
    //
    if (EXCLUSIVE_MODE(cdData) && !EXCLUSIVE_OWNER(cdData, irpStack->FileObject)) {

        //
        // Request is not from exclusive owner, check whether this is a storage request.
        // Only non storage requests can be processed.
        //

        if (CdRomIsBlockedStorageIoctl(Irp) == TRUE) {

            ioctlCode = irpStack->Parameters.DeviceIoControl.IoControlCode;
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                      "CdRomDeviceControlDispatch: Device in exclusive mode! Failing Ioctl %lx\n",
                      ioctlCode));

            status = STATUS_ACCESS_DENIED;
            Irp->IoStatus.Status = status;
            Irp->IoStatus.Information = 0;

            //
            // Complete the request.
            //

            ClassReleaseRemoveLock(DeviceObject, Irp);
            ClassCompleteRequest(DeviceObject, Irp, IO_DISK_INCREMENT);
            return status;
        }
    }

RetryControl:

    Irp->IoStatus.Information = 0;

    //
    // if this is a class driver ioctl then we need to change the base code
    // to IOCTL_CDROM_BASE so that the switch statement can handle it.
    //
    // WARNING - currently the scsi class ioctl function codes are between
    // 0x200 & 0x300.  this routine depends on that fact
    //

    ioctlCode = irpStack->Parameters.DeviceIoControl.IoControlCode;
    baseCode = ioctlCode >> 16;
    functionCode = (ioctlCode & (~0xffffc003)) >> 2;

    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                "CdRomDeviceControl: Ioctl Code = %lx, Base Code = %lx,"
                " Function Code = %lx\n",
                ioctlCode,
                baseCode,
                functionCode
              ));

    if((functionCode >= 0x200) && (functionCode <= 0x300)) {

        ioctlCode = (ioctlCode & 0x0000ffff) | CTL_CODE(IOCTL_CDROM_BASE, 0, 0, 0);

        TracePrint((TRACE_LEVEL_VERBOSE, TRACE_FLAG_IOCTL,
                    "CdRomDeviceControl: Class Code - new ioctl code is %lx\n",
                    ioctlCode));

        irpStack->Parameters.DeviceIoControl.IoControlCode = ioctlCode;

    }

    switch (ioctlCode) {

    case IOCTL_CDROM_GET_INQUIRY_DATA: {

        // Handle this IOCTL immediately (no queues, always cached data)
        ULONG dataLength = 0;
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength != 0) {

            // Always copy as much data as possible
            dataLength = min(cdData->CachedInquiryDataByteCount,
                             irpStack->Parameters.DeviceIoControl.OutputBufferLength
                             );
            RtlCopyMemory(Irp->AssociatedIrp.SystemBuffer,
                          cdData->CachedInquiryData,
                          dataLength
                          );

        }

        // set the data length field in the irp so buffer gets copied to caller
        Irp->IoStatus.Information = dataLength;

        // and finally decide between two possible status values
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength < cdData->CachedInquiryDataByteCount) {
            status = STATUS_BUFFER_TOO_SMALL;
        } else {
            status = STATUS_SUCCESS;
        }

        break; // complete the irp
    }

    case IOCTL_STORAGE_QUERY_PROPERTY: {
        PSTORAGE_PROPERTY_QUERY query =  Irp->AssociatedIrp.SystemBuffer;
        if (!EXCLUSIVE_MODE(cdData) || 
            EXCLUSIVE_OWNER(cdData, irpStack->FileObject) ||
            (query->QueryType == PropertyExistsQuery)) {
            //
            // If the ioctl has come in at passive level then we will synchronize
            // with our start-io routine when sending the ioctl.  If the ioctl
            // has come in at a higher interrupt level and it was not handled
            // above then it's unlikely to be a request for the class DLL - however
            // we'll still use it's common code to forward the request through.
            //

            if (KeGetCurrentIrql() == PASSIVE_LEVEL) {

                return CdRomSynchronizeIoctlWithStartIo(DeviceObject, Irp, ClassDeviceControl);

            } else {

                return ClassDeviceControl(DeviceObject, Irp);

            }
        }
        else {

            if (irpStack->Parameters.DeviceIoControl.InputBufferLength < sizeof(STORAGE_PROPERTY_QUERY)) {

                status = STATUS_INFO_LENGTH_MISMATCH;
                break;
            }

            if ((query != NULL) && 
                (query->QueryType == PropertyStandardQuery) &&
                ( (query->PropertyId == StorageDeviceProperty)|| 
                  (query->PropertyId == StorageAdapterProperty) )){
                //
                //The request is not from original owner, but we have cached information. Return cached information.
                //
                
                if (query->PropertyId == StorageDeviceProperty) {
                    ULONG dataTransferSize = 0;
                    PSTORAGE_DEVICE_DESCRIPTOR outputDescriptor = Irp->AssociatedIrp.SystemBuffer;
                    CHAR *localDescriptorBuffer = (CHAR*)fdoExtension->DeviceDescriptor;
                    
                    // check output buffer length
                    if (irpStack->Parameters.DeviceIoControl.OutputBufferLength == 0)
                    {
                        //
                        // According to MSDN, an output buffer of size 0 can be used to determine if a property exists
                        // so this must be a success case with no data transferred
                        //
                        Irp->IoStatus.Information = 0;
                        status = STATUS_SUCCESS;
                        break;
                    }
                    else if (irpStack->Parameters.DeviceIoControl.OutputBufferLength < sizeof(STORAGE_DESCRIPTOR_HEADER))
                    {
                        //
                        // Buffer too small
                        //
                        Irp->IoStatus.Information = fdoExtension->DeviceDescriptor->Size;
                        status = STATUS_BUFFER_TOO_SMALL;
                        break;
                    }

                    // transfer as much data out as the buffer will allow
                    dataTransferSize = min(irpStack->Parameters.DeviceIoControl.OutputBufferLength, fdoExtension->DeviceDescriptor->Size);
                    RtlCopyMemory(outputDescriptor,
                                  fdoExtension->DeviceDescriptor,
                                  dataTransferSize);

                    // walk through and update offset variables to reflect data that didn't make it into the output buffer
                    if ((dataTransferSize >= RTL_SIZEOF_THROUGH_FIELD(STORAGE_DEVICE_DESCRIPTOR, VendorIdOffset)) &&
                        (fdoExtension->DeviceDescriptor->VendorIdOffset != 0) &&
                        (fdoExtension->DeviceDescriptor->VendorIdOffset != 0xFFFFFFFF))
                    {
                        // set VendorIdOffset appropriately
                        if (dataTransferSize < (fdoExtension->DeviceDescriptor->VendorIdOffset + strlen(localDescriptorBuffer+fdoExtension->DeviceDescriptor->VendorIdOffset)))
                        {
                            outputDescriptor->VendorIdOffset = 0;
                        }
                    }

                    if ((dataTransferSize >= RTL_SIZEOF_THROUGH_FIELD(STORAGE_DEVICE_DESCRIPTOR, ProductIdOffset)) &&
                        (fdoExtension->DeviceDescriptor->ProductIdOffset != 0) &&
                        (fdoExtension->DeviceDescriptor->ProductIdOffset != 0xFFFFFFFF))
                    {
                        // set ProductIdOffset appropriately
                        if (dataTransferSize < (fdoExtension->DeviceDescriptor->ProductIdOffset + strlen(localDescriptorBuffer+fdoExtension->DeviceDescriptor->ProductIdOffset)))
                        {
                            outputDescriptor->ProductIdOffset = 0;
                        }
                    }

                    if ((dataTransferSize >= RTL_SIZEOF_THROUGH_FIELD(STORAGE_DEVICE_DESCRIPTOR, ProductRevisionOffset)) &&
                        (fdoExtension->DeviceDescriptor->ProductRevisionOffset != 0) &&
                        (fdoExtension->DeviceDescriptor->ProductRevisionOffset != 0xFFFFFFFF))
                    {
                        // set ProductRevisionOffset appropriately
                        if (dataTransferSize < (fdoExtension->DeviceDescriptor->ProductRevisionOffset + strlen(localDescriptorBuffer+fdoExtension->DeviceDescriptor->ProductRevisionOffset)))
                        {
                            outputDescriptor->ProductRevisionOffset = 0;
                        }
                    }

                    if ((dataTransferSize >= RTL_SIZEOF_THROUGH_FIELD(STORAGE_DEVICE_DESCRIPTOR, SerialNumberOffset)) &&
                        (fdoExtension->DeviceDescriptor->SerialNumberOffset != 0) &&
                        (fdoExtension->DeviceDescriptor->SerialNumberOffset != 0xFFFFFFFF))
                    {
                        // set SerialNumberOffset appropriately
                        if (dataTransferSize < (fdoExtension->DeviceDescriptor->SerialNumberOffset + strlen(localDescriptorBuffer+fdoExtension->DeviceDescriptor->SerialNumberOffset)))
                        {
                            //
                            // NOTE: I'm setting this to 0 since that is what most port drivers do
                            //       [this could cause issues with SCSI port devices whose clients expect -1 in this field]
                            //
                            outputDescriptor->SerialNumberOffset = 0;
                        }
                    }
                    
                    // set status
                    Irp->IoStatus.Information = dataTransferSize;
                    status = STATUS_SUCCESS;

                    break;
                }
                else if (query->PropertyId == StorageAdapterProperty) {
                    ULONG dataTransferSize = 0;
                    if (irpStack->Parameters.DeviceIoControl.OutputBufferLength == 0)
                    {
                        //
                        // According to MSDN, an output buffer of size 0 can be used to determine if a property exists
                        // so this must be a success case with no data transferred
                        //
                        Irp->IoStatus.Information = 0;
                        status = STATUS_SUCCESS;
                        break;
                    }
                    else if (irpStack->Parameters.DeviceIoControl.OutputBufferLength < sizeof(STORAGE_DESCRIPTOR_HEADER))
                    {
                        //
                        // Buffer too small
                        //
                        Irp->IoStatus.Information = fdoExtension->AdapterDescriptor->Size;
                        status = STATUS_BUFFER_TOO_SMALL;
                        break;
                    }

                    // copy as much data out as the buffer will allow
                    dataTransferSize = min(irpStack->Parameters.DeviceIoControl.OutputBufferLength, fdoExtension->AdapterDescriptor->Size);
                    RtlCopyMemory(query,
                                  fdoExtension->AdapterDescriptor,
                                  dataTransferSize);
                    
                    // set status
                    Irp->IoStatus.Information = dataTransferSize;
                    status = STATUS_SUCCESS;

                    break;
                }
            }
            else
            {
                //
                //The request is not from original owner and there is no cached information. Fail the request.
                //

                ioctlCode = irpStack->Parameters.DeviceIoControl.IoControlCode;
                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                          "CdRomDeviceControlDispatch: Device in exclusive mode! Failing Ioctl %lx\n",
                          ioctlCode));

                status = STATUS_ACCESS_DENIED;
                Irp->IoStatus.Status = status;
                Irp->IoStatus.Information = 0;

                //
                // Complete the request.
                //

                ClassReleaseRemoveLock(DeviceObject, Irp);
                ClassCompleteRequest(DeviceObject, Irp, IO_DISK_INCREMENT);
                return status;
            }
        }
    }

    case IOCTL_STORAGE_GET_MEDIA_TYPES_EX: {

        PGET_MEDIA_TYPES  mediaTypes = Irp->AssociatedIrp.SystemBuffer;
        PDEVICE_MEDIA_INFO mediaInfo = &mediaTypes->MediaInfo[0];
        ULONG sizeNeeded;

        sizeNeeded = sizeof(GET_MEDIA_TYPES);

        //
        // IsMmc is static...
        //

        if (cdData->Mmc.IsMmc) {
            sizeNeeded += sizeof(DEVICE_MEDIA_INFO) * 1; // return two media types
        }

        //
        // Ensure that buffer is large enough.
        //

        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength <
            sizeNeeded) {

            //
            // Buffer too small.
            //

            Irp->IoStatus.Information = sizeNeeded;
            status = STATUS_BUFFER_TOO_SMALL;
            break;
        }

        RtlZeroMemory(Irp->AssociatedIrp.SystemBuffer, sizeNeeded);

        //
        // ISSUE-2000/5/11-henrygab - need to update GET_MEDIA_TYPES_EX
        //

        mediaTypes->DeviceType = cdData->DriveDeviceType;

        mediaTypes->MediaInfoCount = 1;
        mediaInfo->DeviceSpecific.RemovableDiskInfo.MediaType = CD_ROM;
        mediaInfo->DeviceSpecific.RemovableDiskInfo.NumberMediaSides = 1;
        mediaInfo->DeviceSpecific.RemovableDiskInfo.MediaCharacteristics = MEDIA_READ_ONLY;
        mediaInfo->DeviceSpecific.RemovableDiskInfo.Cylinders.QuadPart = fdoExtension->DiskGeometry.Cylinders.QuadPart;
        mediaInfo->DeviceSpecific.RemovableDiskInfo.TracksPerCylinder = fdoExtension->DiskGeometry.TracksPerCylinder;
        mediaInfo->DeviceSpecific.RemovableDiskInfo.SectorsPerTrack = fdoExtension->DiskGeometry.SectorsPerTrack;
        mediaInfo->DeviceSpecific.RemovableDiskInfo.BytesPerSector = fdoExtension->DiskGeometry.BytesPerSector;

        if (cdData->Mmc.IsMmc) {

            //
            // also report a removable disk
            //
            mediaTypes->MediaInfoCount += 1;

            mediaInfo++;
            mediaInfo->DeviceSpecific.RemovableDiskInfo.MediaType = RemovableMedia;
            mediaInfo->DeviceSpecific.RemovableDiskInfo.NumberMediaSides = 1;
            mediaInfo->DeviceSpecific.RemovableDiskInfo.MediaCharacteristics = MEDIA_READ_WRITE;
            mediaInfo->DeviceSpecific.RemovableDiskInfo.Cylinders.QuadPart = fdoExtension->DiskGeometry.Cylinders.QuadPart;
            mediaInfo->DeviceSpecific.RemovableDiskInfo.TracksPerCylinder = fdoExtension->DiskGeometry.TracksPerCylinder;
            mediaInfo->DeviceSpecific.RemovableDiskInfo.SectorsPerTrack = fdoExtension->DiskGeometry.SectorsPerTrack;
            mediaInfo->DeviceSpecific.RemovableDiskInfo.BytesPerSector = fdoExtension->DiskGeometry.BytesPerSector;
            mediaInfo--;

        }

        //
        // Status will either be success, if media is present, or no media.
        // It would be optimal to base from density code and medium type, but not all devices
        // have values for these fields.
        //

        //
        // Send a TUR to determine if media is present.
        //

        if (!EXCLUSIVE_MODE(cdData) || EXCLUSIVE_OWNER(cdData, irpStack->FileObject)) {

            SCSI_REQUEST_BLOCK srb = {0};
            PCDB cdb = (PCDB)srb.Cdb;

            srb.CdbLength = 6;
            cdb->CDB6GENERIC.OperationCode = SCSIOP_TEST_UNIT_READY;

            //
            // Set timeout value.
            //

            srb.TimeOutValue = fdoExtension->TimeOutValue;

            status = ClassSendSrbSynchronous(DeviceObject,
                                             &srb,
                                             NULL,
                                             0,
                                             FALSE);

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                       "CdRomDeviceControl: GET_MEDIA_TYPES status of TUR - %lx\n", status));

            if (NT_SUCCESS(status)) {

                //
                // set the disk's media as current if we can write to it.
                //

                if (cdData->Mmc.IsMmc && cdData->Mmc.WriteAllowed) {

                    mediaInfo++;
                    SET_FLAG(mediaInfo->DeviceSpecific.RemovableDiskInfo.MediaCharacteristics,
                             MEDIA_CURRENTLY_MOUNTED);
                    mediaInfo--;

                } else {

                    SET_FLAG(mediaInfo->DeviceSpecific.RemovableDiskInfo.MediaCharacteristics,
                             MEDIA_CURRENTLY_MOUNTED);
                }
            }
        }

        Irp->IoStatus.Information = sizeNeeded;
        status = STATUS_SUCCESS;
        break;
    }


    case IOCTL_CDROM_RAW_READ: {

        LARGE_INTEGER  startingOffset = {0};
        ULONGLONG      transferBytes = 0;
        ULONGLONG      endOffset;
        ULONGLONG      mdlBytes;
        RAW_READ_INFO  rawReadInfo;

        //
        // Check that ending sector is on disc and buffers are there and of
        // correct size.
        //

        if (!irpStack->Parameters.DeviceIoControl.Type3InputBuffer){
            /*
             *  This is a call from user space.  This is the only time that we need to validate parameters.
             *  Validate the input and get the input buffer into Type3InputBuffer
             *  so the rest of the code will be uniform.
             */
            if (Irp->AssociatedIrp.SystemBuffer){
                irpStack->Parameters.DeviceIoControl.Type3InputBuffer = Irp->AssociatedIrp.SystemBuffer;
                if (irpStack->Parameters.DeviceIoControl.InputBufferLength < sizeof(RAW_READ_INFO)){
                    Irp->IoStatus.Information = sizeof(RAW_READ_INFO);
                    status = STATUS_BUFFER_TOO_SMALL;
                    break;
                }
            }
            else {
                status = STATUS_INVALID_PARAMETER;
                break;
            }
        }

        /*
         *  Since this ioctl is METHOD_OUT_DIRECT, we need to copy away the input buffer before interpreting it.
         *  This prevents a malicious app from messing with the input buffer while we are interpreting it.
         */
        rawReadInfo = *(PRAW_READ_INFO)irpStack->Parameters.DeviceIoControl.Type3InputBuffer;

        startingOffset.QuadPart = rawReadInfo.DiskOffset.QuadPart;

        if (rawReadInfo.TrackMode == CDDA        ||
            rawReadInfo.TrackMode == YellowMode2 ||
            rawReadInfo.TrackMode == XAForm2     ) {

        transferBytes = (ULONGLONG)rawReadInfo.SectorCount * RAW_SECTOR_SIZE;

        } else if (rawReadInfo.TrackMode == RawWithSubCode) {

            transferBytes = (ULONGLONG)rawReadInfo.SectorCount * CD_RAW_SECTOR_WITH_SUBCODE_SIZE;

        } else if (rawReadInfo.TrackMode == RawWithC2) {

            transferBytes = (ULONGLONG)rawReadInfo.SectorCount * CD_RAW_SECTOR_WITH_C2_SIZE;

        } else if (rawReadInfo.TrackMode == RawWithC2AndSubCode) {

            transferBytes = (ULONGLONG)rawReadInfo.SectorCount * CD_RAW_SECTOR_WITH_C2_AND_SUBCODE_SIZE;

        } else {

            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                      "CdRomDeviceControl: Invalid TrackMode type %x for XA read\n",
                      rawReadInfo.TrackMode
                      ));

        }

        endOffset = (ULONGLONG)rawReadInfo.SectorCount * COOKED_SECTOR_SIZE;
        endOffset += startingOffset.QuadPart;

        //
        // check for overflows....
        //
        if (rawReadInfo.SectorCount == 0) {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "CdRomDeviceControl: Invalid I/O parameters for XA "
                        "Read (zero sectors requested)\n"));
            status = STATUS_INVALID_PARAMETER;
            break;
        }
        if (transferBytes < (ULONGLONG)(rawReadInfo.SectorCount)) {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "CdRomDeviceControl: Invalid I/O parameters for XA "
                        "Read (TransferBytes Overflow)\n"));
            status = STATUS_INVALID_PARAMETER;
            break;
        }
        if (endOffset < (ULONGLONG)startingOffset.QuadPart) {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "CdRomDeviceControl: Invalid I/O parameters for XA "
                        "Read (EndingOffset Overflow)\n"));
            status = STATUS_INVALID_PARAMETER;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength <
            transferBytes) {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "CdRomDeviceControl: Invalid I/O parameters for XA "
                        "Read (Bad buffer size)\n"));
            status = STATUS_INVALID_PARAMETER;
            break;
        }
        if (endOffset > (ULONGLONG)commonExtension->PartitionLength.QuadPart) {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "CdRomDeviceControl: Invalid I/O parameters for XA "
                        "Read (Request Out of Bounds)\n"));
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        //
        // cannot validate the MdlAddress, since it is not included in any
        // other location per the DDK and file system calls.
        //

        //
        // validate the mdl describes at least the number of bytes
        // requested from us.
        //

        mdlBytes = (ULONGLONG)MmGetMdlByteCount(Irp->MdlAddress);
        if (mdlBytes < transferBytes) {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "CdRomDeviceControl: Invalid MDL %s, Irp %p\n",
                        "size (5)", Irp));
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        //
        // check the buffer for alignment
        // This is important for x86 as some busses (ie ATAPI)
        // require word-aligned buffers.
        //

        if ( ((ULONG_PTR)MmGetMdlVirtualAddress(Irp->MdlAddress)) &
             fdoExtension->AdapterDescriptor->AlignmentMask
            )
        {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                      "CdRomDeviceControl: Invalid I/O parameters for "
                      "XA Read (Buffer %p not aligned with mask %x\n",
                      irpStack->Parameters.DeviceIoControl.Type3InputBuffer,
                      fdoExtension->AdapterDescriptor->AlignmentMask));
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        //
        // Validate the request is not too large for the adapter
        //
        {
            BOOLEAN bufferIsPageAligned = FALSE;
            ULONG maxLength;

            //
            // if buffer is not page-aligned, then subtract one as the
            // transfer could cross a page boundary.
            //
            if ((((ULONG_PTR)MmGetMdlVirtualAddress(Irp->MdlAddress)) & (PAGE_SIZE-1)) == 0) {
                bufferIsPageAligned = TRUE;
            }

            if (bufferIsPageAligned) {
                maxLength = cdData->MaxPageAlignedTransferBytes;
            } else {
                maxLength = cdData->MaxUnalignedTransferBytes;
            }

            if (transferBytes > maxLength) {
                TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                          "CdRomDeviceControl: The XA Read (type %x) would require %I64x bytes, "
                          "but the adapter can only handle %x bytes (for a%saligned buffer)\n",
                          rawReadInfo.TrackMode,
                          transferBytes,
                          maxLength,
                          (bufferIsPageAligned ? " " : "n un")
                          ));
                status = STATUS_INVALID_PARAMETER;
                break;
            }
        }

        //
        // HACKHACK - REF #0001
        // The retry count will be in this irp's IRP_MN function,
        // as the new irp was freed, and we therefore cannot use
        // this irp's next stack location for this function.
        // This may be a good location to store this info for
        // when we remove RAW_READ (mode switching), as we will
        // no longer have the nextIrpStackLocation to play with
        // when that occurs
        //
        irpStack->MinorFunction = MAXIMUM_RETRIES; // HACKHACK - REF #0001

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;
    }

    case IOCTL_DISK_GET_DRIVE_GEOMETRY_EX:
    case IOCTL_CDROM_GET_DRIVE_GEOMETRY_EX: {
        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomDeviceControl: Get drive geometryEx\n"));
        if ( irpStack->Parameters.DeviceIoControl.OutputBufferLength <
             FIELD_OFFSET(DISK_GEOMETRY_EX, Data)) {
            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = FIELD_OFFSET(DISK_GEOMETRY_EX, Data);
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }

    case IOCTL_DISK_GET_DRIVE_GEOMETRY:
    case IOCTL_CDROM_GET_DRIVE_GEOMETRY: {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomDeviceControl: Get drive geometry\n"));

        if ( irpStack->Parameters.DeviceIoControl.OutputBufferLength <
            sizeof( DISK_GEOMETRY ) ) {

            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = sizeof(DISK_GEOMETRY);
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;
    }

    case IOCTL_CDROM_READ_TOC_EX: {

        PCDROM_READ_TOC_EX inputBuffer;

        if (CdRomIsPlayActive(DeviceObject)) {
            status = STATUS_DEVICE_BUSY;
            break;
        }

        if (irpStack->Parameters.DeviceIoControl.InputBufferLength <
            sizeof(CDROM_READ_TOC_EX)) {
            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }

        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength <
            MINIMUM_CDROM_READ_TOC_EX_SIZE) {
            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = MINIMUM_CDROM_READ_TOC_EX_SIZE;
            break;
        }

        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength >
            ((USHORT)-1)) {
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength &
            fdoExtension->AdapterDescriptor->AlignmentMask) {
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        inputBuffer = Irp->AssociatedIrp.SystemBuffer;

        if ((inputBuffer->Reserved1 != 0) ||
            (inputBuffer->Reserved2 != 0) ||
            (inputBuffer->Reserved3 != 0)) {
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        //
        // NOTE: when adding new formats, ensure that first two bytes
        //       specify the amount of additional data available.
        //

        if ((inputBuffer->Format == CDROM_READ_TOC_EX_FORMAT_TOC     ) ||
            (inputBuffer->Format == CDROM_READ_TOC_EX_FORMAT_FULL_TOC) ||
            (inputBuffer->Format == CDROM_READ_TOC_EX_FORMAT_CDTEXT  )) {

            // SessionTrack field is used

        } else
        if ((inputBuffer->Format == CDROM_READ_TOC_EX_FORMAT_SESSION) ||
            (inputBuffer->Format == CDROM_READ_TOC_EX_FORMAT_PMA)     ||
            (inputBuffer->Format == CDROM_READ_TOC_EX_FORMAT_ATIP)) {

            // SessionTrack field is reserved

            if (inputBuffer->SessionTrack != 0) {
                status = STATUS_INVALID_PARAMETER;
                break;
            }

        } else {
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }

    case IOCTL_CDROM_GET_LAST_SESSION: {

        //
        // If the cd is playing music then reject this request.
        //

        if (CdRomIsPlayActive(DeviceObject)) {
            status = STATUS_DEVICE_BUSY;
            break;
        }

        //
        // Make sure the caller is requesting enough data to make this worth
        // our while.
        //

        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength <
            sizeof(CDROM_TOC_SESSION_DATA)) {

            //
            // they didn't request the entire TOC -- use _EX version
            // for partial transfers and such.
            //

            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = sizeof(CDROM_TOC_SESSION_DATA);
            break;
        }

        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength &
            fdoExtension->AdapterDescriptor->AlignmentMask) {
            status = STATUS_INVALID_PARAMETER;
            break;
        }


        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;
    }

    case IOCTL_CDROM_READ_TOC:  {

        //
        // If the cd is playing music then reject this request.
        //

        if (CdRomIsPlayActive(DeviceObject)) {
            status = STATUS_DEVICE_BUSY;
            break;
        }

        //
        // Make sure the caller is requesting enough data to make this worth
        // our while.
        //

        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength <
            sizeof(CDROM_TOC)) {

            //
            // they didn't request the entire TOC -- use _EX version
            // for partial transfers and such.
            //

            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = sizeof(CDROM_TOC);
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength &
            fdoExtension->AdapterDescriptor->AlignmentMask) {
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;
    }

    case IOCTL_CDROM_PLAY_AUDIO_MSF: {

        //
        // Play Audio MSF
        //

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomDeviceControl: Play audio MSF\n"));

        if (irpStack->Parameters.DeviceIoControl.InputBufferLength <
            sizeof(CDROM_PLAY_AUDIO_MSF)) {

            //
            // Indicate unsuccessful status.
            //

            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;
    }

    case IOCTL_CDROM_SEEK_AUDIO_MSF: {


        //
        // Seek Audio MSF
        //

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomDeviceControl: Seek audio MSF\n"));

        if (irpStack->Parameters.DeviceIoControl.InputBufferLength <
            sizeof(CDROM_SEEK_AUDIO_MSF)) {

            //
            // Indicate unsuccessful status.
            //

            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;

    }

    case IOCTL_CDROM_PAUSE_AUDIO: {

        //
        // Pause audio
        //

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomDeviceControl: Pause audio\n"));

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;

        break;
    }

    case IOCTL_CDROM_RESUME_AUDIO: {

        //
        // Resume audio
        //

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomDeviceControl: Resume audio\n"));

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;
    }

    case IOCTL_CDROM_READ_Q_CHANNEL: {

        PCDROM_SUB_Q_DATA_FORMAT inputBuffer =
                         Irp->AssociatedIrp.SystemBuffer;
        ULONG transferByteCount;

        if(irpStack->Parameters.DeviceIoControl.InputBufferLength <
            sizeof(CDROM_SUB_Q_DATA_FORMAT)) {

            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }

        //
        // check for all valid types of request
        //
        if (inputBuffer->Format == IOCTL_CDROM_CURRENT_POSITION) {
            transferByteCount = sizeof(SUB_Q_CURRENT_POSITION);
        } else if (inputBuffer->Format == IOCTL_CDROM_MEDIA_CATALOG) {
            transferByteCount = sizeof(SUB_Q_MEDIA_CATALOG_NUMBER);
        } else if (inputBuffer->Format == IOCTL_CDROM_TRACK_ISRC) {
            transferByteCount = sizeof(SUB_Q_TRACK_ISRC);
        } else {
            status = STATUS_INVALID_PARAMETER;
            Irp->IoStatus.Information = 0;
            break;
        }

        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength <
            transferByteCount) {
            Irp->IoStatus.Information = transferByteCount;
            status = STATUS_BUFFER_TOO_SMALL;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;
    }

    case IOCTL_CDROM_GET_VOLUME: {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomDeviceControl: Get volume control\n"));

        //
        // Verify user buffer is large enough for data.
        //

        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength <
            sizeof(VOLUME_CONTROL)) {

            //
            // Indicate unsuccessful status and no data transferred.
            //

            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = sizeof(VOLUME_CONTROL);
            break;

        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;
    }

    case IOCTL_CDROM_SET_VOLUME: {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomDeviceControl: Set volume control\n"));

        if (irpStack->Parameters.DeviceIoControl.InputBufferLength <
            sizeof(VOLUME_CONTROL)) {

            //
            // Indicate unsuccessful status.
            //

            status = STATUS_INFO_LENGTH_MISMATCH;
            break;

        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;
    }

    case IOCTL_CDROM_STOP_AUDIO: {

        //
        // Stop play.
        //

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomDeviceControl: Stop audio\n"));

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;
    }

    case IOCTL_STORAGE_CHECK_VERIFY:
    case IOCTL_DISK_CHECK_VERIFY:
    case IOCTL_CDROM_CHECK_VERIFY: {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomDeviceControl: [%p] Check Verify\n", Irp));

        if((irpStack->Parameters.DeviceIoControl.OutputBufferLength) &&
           (irpStack->Parameters.DeviceIoControl.OutputBufferLength < sizeof(ULONG))) {

           TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                       "CdRomDeviceControl: Check Verify: media count "
                       "buffer too small\n"));

           status = STATUS_BUFFER_TOO_SMALL;
           Irp->IoStatus.Information = sizeof(ULONG);
           break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;
    }

    case IOCTL_DVD_READ_STRUCTURE: {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "DvdDeviceControl: [%p] IOCTL_DVD_READ_STRUCTURE\n", Irp));

#ifdef ENABLE_RPC0
        if (cdData->DvdRpc0Device && cdData->DvdRpc0LicenseFailure) {
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl: License Failure\n"));
            status = STATUS_COPY_PROTECTION_FAILURE;
            break;
        }

        if (cdData->DvdRpc0Device && cdData->Rpc0RetryRegistryCallback) {
            //
            // if currently in-progress, this will just return.
            // prevents looping by doing that interlockedExchange()
            //
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl: PickRegion() from "
                        "READ_STRUCTURE\n"));
            CdRomPickDvdRegion(DeviceObject);
        }
#endif // ENABLE_RPC0


        if(irpStack->Parameters.DeviceIoControl.InputBufferLength <
           sizeof(DVD_READ_STRUCTURE)) {

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl - READ_STRUCTURE: input buffer "
                        "length too small (was %d should be %d)\n",
                        irpStack->Parameters.DeviceIoControl.InputBufferLength,
                        sizeof(DVD_READ_STRUCTURE)));
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        if(irpStack->Parameters.DeviceIoControl.OutputBufferLength <
           sizeof(READ_DVD_STRUCTURES_HEADER)) {

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl - READ_STRUCTURE: output buffer "
                        "cannot hold header information\n"));
            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = sizeof(READ_DVD_STRUCTURES_HEADER);
            break;
        }

        if(irpStack->Parameters.DeviceIoControl.OutputBufferLength >
           MAXUSHORT) {

            //
            // key length must fit in two bytes
            //
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl - READ_STRUCTURE: output buffer "
                        "too large\n"));
            status = STATUS_INVALID_PARAMETER;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength &
            fdoExtension->AdapterDescriptor->AlignmentMask) {
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;
    }

    case IOCTL_DVD_START_SESSION: {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "DvdDeviceControl: [%p] IOCTL_DVD_START_SESSION\n", Irp));

#ifdef ENABLE_RPC0
        if (cdData->DvdRpc0Device && cdData->DvdRpc0LicenseFailure) {
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl: License Failure\n"));
            status = STATUS_COPY_PROTECTION_FAILURE;
            break;
        }
#endif // ENABLE_RPC0

        if(irpStack->Parameters.DeviceIoControl.OutputBufferLength <
           sizeof(DVD_SESSION_ID)) {

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl: DVD_START_SESSION - output "
                        "buffer too small\n"));
            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = sizeof(DVD_SESSION_ID);
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;
    }

    case IOCTL_DVD_SEND_KEY:
    case IOCTL_DVD_SEND_KEY2: {

        PDVD_COPY_PROTECT_KEY key = Irp->AssociatedIrp.SystemBuffer;
        ULONG keyLength;

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "DvdDeviceControl: [%p] IOCTL_DVD_SEND_KEY\n", Irp));

#ifdef ENABLE_RPC0
        if (cdData->DvdRpc0Device && cdData->DvdRpc0LicenseFailure) {
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl: License Failure\n"));
            status = STATUS_COPY_PROTECTION_FAILURE;
            break;
        }
#endif // ENABLE_RPC0

        if((irpStack->Parameters.DeviceIoControl.InputBufferLength <
            sizeof(DVD_COPY_PROTECT_KEY)) ||
           (irpStack->Parameters.DeviceIoControl.InputBufferLength !=
            key->KeyLength)) {

            //
            // Key is too small to have a header or the key length doesn't
            // match the input buffer length.  Key must be invalid
            //

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl: [%p] IOCTL_DVD_SEND_KEY - "
                        "key is too small or does not match KeyLength\n",
                        Irp));
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        //
        // allow only certain key type (non-destructive) to go through
        // IOCTL_DVD_SEND_KEY (which only requires READ access to the device)
        //
        if (ioctlCode == IOCTL_DVD_SEND_KEY) {

            if ((key->KeyType != DvdChallengeKey) &&
                (key->KeyType != DvdBusKey2) &&
                (key->KeyType != DvdInvalidateAGID)) {

                status = STATUS_INVALID_PARAMETER;
                break;
            }
        } else {

            if ((key->KeyType != DvdChallengeKey) &&
                (key->KeyType != DvdBusKey1) &&
                (key->KeyType != DvdBusKey2) &&
                (key->KeyType != DvdTitleKey) &&
                (key->KeyType != DvdAsf) &&
                (key->KeyType != DvdSetRpcKey) &&
                (key->KeyType != DvdGetRpcKey) &&
                (key->KeyType != DvdDiskKey) &&
                (key->KeyType != DvdInvalidateAGID)) {
                status = STATUS_INVALID_PARAMETER;
                break;
            }

        }
#ifdef ENABLE_RPC0
        if (cdData->DvdRpc0Device) {

            if (key->KeyType == DvdSetRpcKey) {

                PDVD_SET_RPC_KEY rpcKey = (PDVD_SET_RPC_KEY) key->KeyData;

                if (irpStack->Parameters.DeviceIoControl.InputBufferLength <
                    DVD_SET_RPC_KEY_LENGTH) {

                    status = STATUS_INVALID_PARAMETER;
                    break;
                }

                //
                // we have a request to set region code
                // on a RPC0 device which doesn't support
                // region coding.
                //
                // we have to fake it.
                //

                KeWaitForMutexObject(
                    &cdData->Rpc0RegionMutex,
                    UserRequest,
                    KernelMode,
                    FALSE,
                    NULL
                    );

                if (cdData->DvdRpc0Device && cdData->Rpc0RetryRegistryCallback) {
                    //
                    // if currently in-progress, this will just return.
                    // prevents looping by doing that interlockedExchange()
                    //
                    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                                "DvdDeviceControl: PickRegion() from "
                                "SEND_KEY\n"));
                    CdRomPickDvdRegion(DeviceObject);
                }

                if (cdData->Rpc0SystemRegion == rpcKey->PreferredDriveRegionCode) {

                    //
                    // nothing to change
                    //
                    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                                "DvdDeviceControl (%p) => not changing "
                                "regions -- requesting current region\n",
                                DeviceObject));
                    status = STATUS_SUCCESS;

                } else if (cdData->Rpc0SystemRegionResetCount == 0) {

                    //
                    // not allowed to change it again
                    //

                    TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                                "DvdDeviceControl (%p) => no more region "
                                "changes are allowed for this device\n",
                                DeviceObject));
                    status = STATUS_CSS_RESETS_EXHAUSTED;

                } else {

                    ULONG i;
                    UCHAR mask;
                    ULONG bufferLen;
                    PDVD_READ_STRUCTURE dvdReadStructure;
                    PDVD_COPYRIGHT_DESCRIPTOR dvdCopyRight;
                    IO_STATUS_BLOCK ioStatus = {0};
                    UCHAR mediaRegionData;

                    mask = ~rpcKey->PreferredDriveRegionCode;

                    if (CountOfSetBitsUChar(mask) != 1) {

                        status = STATUS_INVALID_DEVICE_REQUEST;
                        break;
                    }

                    //
                    // this test will always be TRUE except during initial
                    // automatic selection of the first region.
                    //

                    if (cdData->Rpc0SystemRegion != 0xff) {

                        //
                        // make sure we have a media in the drive with the same
                        // region code if the drive is already has a region set
                        //

                        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                                    "DvdDeviceControl (%p) => Checking "
                                    "media region\n",
                                    DeviceObject));

                        bufferLen = max(sizeof(DVD_DESCRIPTOR_HEADER) +
                                            sizeof(DVD_COPYRIGHT_DESCRIPTOR),
                                        sizeof(DVD_READ_STRUCTURE)
                                        );

                        dvdReadStructure = (PDVD_READ_STRUCTURE)
                            ExAllocatePoolWithTag(PagedPool,
                                                  bufferLen,
                                                  DVD_TAG_RPC2_CHECK);

                        if (dvdReadStructure == NULL) {
                            status = STATUS_INSUFFICIENT_RESOURCES;
                            KeReleaseMutex(&cdData->Rpc0RegionMutex,FALSE);
                            break;
                        }

                        dvdCopyRight = (PDVD_COPYRIGHT_DESCRIPTOR)
                            ((PDVD_DESCRIPTOR_HEADER) dvdReadStructure)->Data;

                        //
                        // check to see if we have a DVD device
                        //

                        RtlZeroMemory (dvdReadStructure, bufferLen);
                        dvdReadStructure->Format = DvdCopyrightDescriptor;

                        //
                        // Build a request for READ_KEY
                        //
                        ClassSendDeviceIoControlSynchronous(
                            IOCTL_DVD_READ_STRUCTURE,
                            DeviceObject,
                            dvdReadStructure,
                            sizeof(DVD_READ_STRUCTURE),
                            sizeof(DVD_DESCRIPTOR_HEADER) +
                                sizeof(DVD_COPYRIGHT_DESCRIPTOR),
                            FALSE,
                            &ioStatus);

                        //
                        // this is just to prevent bugs from creeping in
                        // if status is not set later in development
                        //

                        status = ioStatus.Status;

                        //
                        // handle errors
                        //

                        if (!NT_SUCCESS(status)) {
                            KeReleaseMutex(&cdData->Rpc0RegionMutex,FALSE);
                            ExFreePool(dvdReadStructure);
                            status = STATUS_INVALID_DEVICE_REQUEST;
                            break;
                        }

                        //
                        // save the mediaRegionData before freeing the
                        // allocated memory
                        //

                        mediaRegionData =
                            dvdCopyRight->RegionManagementInformation;
                        ExFreePool(dvdReadStructure);

                        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                                    "DvdDeviceControl (%p) => new mask is %x"
                                    " MediaRegionData is %x\n", DeviceObject,
                                    rpcKey->PreferredDriveRegionCode,
                                    mediaRegionData));

                        //
                        // the media region must match the requested region
                        // for RPC0 drives for initial region selection
                        //

                        if (((UCHAR)~(mediaRegionData | rpcKey->PreferredDriveRegionCode)) == 0) {
                            KeReleaseMutex(&cdData->Rpc0RegionMutex,FALSE);
                            status = STATUS_CSS_REGION_MISMATCH;
                            break;
                        }

                    }

                    //
                    // now try to set the region
                    //

                    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                                "DvdDeviceControl (%p) => Soft-Setting "
                                "region of RPC1 device to %x\n",
                                DeviceObject,
                                rpcKey->PreferredDriveRegionCode
                                ));

                    status = CdRomSetRpc0Settings(DeviceObject,
                                                  rpcKey->PreferredDriveRegionCode);

                    if (!NT_SUCCESS(status)) {
                        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                                    "DvdDeviceControl (%p) => Could not "
                                    "set region code (%x)\n",
                                    DeviceObject, status
                                    ));
                    } else {

                        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                                    "DvdDeviceControl (%p) => New region set "
                                    " for RPC1 drive\n", DeviceObject));

                        //
                        // if it worked, our extension is already updated.
                        // release the mutex
                        //

                        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "DvdDeviceControl (%p) => DVD current "
                                     "region bitmap  0x%x\n", DeviceObject,
                                     cdData->Rpc0SystemRegion));
                        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "DvdDeviceControl (%p) => DVD region "
                                     " reset Count     0x%x\n", DeviceObject,
                                     cdData->Rpc0SystemRegionResetCount));
                    }

                }

                KeReleaseMutex(&cdData->Rpc0RegionMutex,FALSE);
                break;
            } // end of key->KeyType == DvdSetRpcKey
        } // end of Rpc0Device hacks
#endif // ENABLE_RPC0

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
        break;
    }

    case IOCTL_DVD_READ_KEY: {

        PDVD_COPY_PROTECT_KEY keyParameters = Irp->AssociatedIrp.SystemBuffer;
        ULONG keyLength;

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "DvdDeviceControl: [%p] IOCTL_DVD_READ_KEY\n", Irp));

#ifdef ENABLE_RPC0
        if (cdData->DvdRpc0Device && cdData->DvdRpc0LicenseFailure) {
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl: License Failure\n"));
            status = STATUS_COPY_PROTECTION_FAILURE;
            break;
        }

        if (cdData->DvdRpc0Device && cdData->Rpc0RetryRegistryCallback) {
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl: PickRegion() from READ_KEY\n"));
            CdRomPickDvdRegion(DeviceObject);
        }
#endif // ENABLE_RPC0


        if(irpStack->Parameters.DeviceIoControl.InputBufferLength <
            sizeof(DVD_COPY_PROTECT_KEY)) {

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl: EstablishDriveKey - challenge "
                        "key buffer too small\n"));

            status = STATUS_INVALID_PARAMETER;
            break;

        }

        switch(keyParameters->KeyType) {

            case DvdChallengeKey: {
                C_ASSERT(sizeof(DVD_COPY_PROTECT_KEY) <= DVD_CHALLENGE_KEY_LENGTH);
                keyLength = DVD_CHALLENGE_KEY_LENGTH;
                break;
            }
            case DvdBusKey1:
            case DvdBusKey2: {
                C_ASSERT(sizeof(DVD_COPY_PROTECT_KEY) <= DVD_BUS_KEY_LENGTH);
                keyLength = DVD_BUS_KEY_LENGTH;
                break;
            }
            case DvdTitleKey: {
                C_ASSERT(sizeof(DVD_COPY_PROTECT_KEY) <= DVD_TITLE_KEY_LENGTH);
                keyLength = DVD_TITLE_KEY_LENGTH;
                break;
            }
            case DvdAsf: {
                C_ASSERT(sizeof(DVD_COPY_PROTECT_KEY) <= DVD_ASF_LENGTH);
                keyLength = DVD_ASF_LENGTH;
                break;
            }
            case DvdDiskKey: {
                C_ASSERT(sizeof(DVD_COPY_PROTECT_KEY) <= DVD_DISK_KEY_LENGTH);
                keyLength = DVD_DISK_KEY_LENGTH;
                break;
            }
            case DvdGetRpcKey: {
                C_ASSERT(sizeof(DVD_COPY_PROTECT_KEY) <= DVD_RPC_KEY_LENGTH);
                keyLength = DVD_RPC_KEY_LENGTH;
                break;
            }
            default: {
                keyLength = sizeof(DVD_COPY_PROTECT_KEY);
                break;
            }
        }

        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength <
            keyLength) {

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl: EstablishDriveKey - output "
                        "buffer too small\n"));
            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = keyLength;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength &
            fdoExtension->AdapterDescriptor->AlignmentMask) {
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        if (keyParameters->KeyType == DvdGetRpcKey) {

            CdRomPickDvdRegion(DeviceObject);
        }

#ifdef ENABLE_RPC0
        if ((keyParameters->KeyType == DvdGetRpcKey) &&
            (cdData->DvdRpc0Device)) {

            PDVD_RPC_KEY rpcKey;
            rpcKey = (PDVD_RPC_KEY)keyParameters->KeyData;
            RtlZeroMemory (rpcKey, sizeof (*rpcKey));

            KeWaitForMutexObject(
                &cdData->Rpc0RegionMutex,
                UserRequest,
                KernelMode,
                FALSE,
                NULL
                );

            //
            // make up the data
            //
            rpcKey->UserResetsAvailable = cdData->Rpc0SystemRegionResetCount;
            rpcKey->ManufacturerResetsAvailable = 0;
            if (cdData->Rpc0SystemRegion == 0xff) {
                rpcKey->TypeCode = 0;
            } else {
                rpcKey->TypeCode = 1;
            }
            rpcKey->RegionMask = (UCHAR) cdData->Rpc0SystemRegion;
            rpcKey->RpcScheme = 1;

            KeReleaseMutex(
                &cdData->Rpc0RegionMutex,
                FALSE
                );

            Irp->IoStatus.Information = DVD_RPC_KEY_LENGTH;
            status = STATUS_SUCCESS;
            break;

        } else
#endif // ENABLE_RPC0
        if (keyParameters->KeyType == DvdDiskKey) {

            PDVD_COPY_PROTECT_KEY keyHeader;
            PDVD_READ_STRUCTURE readStructureRequest;

            //
            // Special case - build a request to get the dvd structure
            // so we can get the disk key.
            //

            //
            // save the key header so we can restore the interesting
            // parts later
            //

            keyHeader = ExAllocatePoolWithTag(NonPagedPool,
                                              sizeof(DVD_COPY_PROTECT_KEY),
                                              DVD_TAG_READ_KEY);

            if(keyHeader == NULL) {

                //
                // Can't save the context so return an error
                //

                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                            "DvdDeviceControl - READ_KEY: unable to "
                            "allocate context\n"));
                status = STATUS_INSUFFICIENT_RESOURCES;
                break;
            }

            RtlCopyMemory(keyHeader,
                          Irp->AssociatedIrp.SystemBuffer,
                          sizeof(DVD_COPY_PROTECT_KEY));

            IoCopyCurrentIrpStackLocationToNext(Irp);

            nextStack = IoGetNextIrpStackLocation(Irp);

            nextStack->Parameters.DeviceIoControl.IoControlCode =
                IOCTL_DVD_READ_STRUCTURE;

            readStructureRequest = Irp->AssociatedIrp.SystemBuffer;
            readStructureRequest->Format = DvdDiskKeyDescriptor;
            readStructureRequest->BlockByteOffset.QuadPart = 0;
            readStructureRequest->LayerNumber = 0;
            readStructureRequest->SessionId = keyHeader->SessionId;

            nextStack->Parameters.DeviceIoControl.InputBufferLength =
                sizeof(DVD_READ_STRUCTURE);

            nextStack->Parameters.DeviceIoControl.OutputBufferLength =
                sizeof(READ_DVD_STRUCTURES_HEADER) + sizeof(DVD_DISK_KEY_DESCRIPTOR);

            IoSetCompletionRoutine(Irp,
                                   CdRomDvdReadDiskKeyCompletion,
                                   (PVOID) keyHeader,
                                   TRUE,
                                   TRUE,
                                   TRUE);

            {
                UCHAR uniqueAddress;
                ClassAcquireRemoveLock(DeviceObject, (PIRP)&uniqueAddress);
                ClassReleaseRemoveLock(DeviceObject, Irp);

                IoMarkIrpPending(Irp);
                IoCallDriver(commonExtension->DeviceObject, Irp);
                ClassReleaseRemoveLock(DeviceObject, (PIRP)&uniqueAddress);
                status = STATUS_PENDING;
                UNREFERENCED_PARAMETER(status); // disables prefast warning; defensive coding...
            }

            return STATUS_PENDING;

        } else {

            IoMarkIrpPending(Irp);
            IoStartPacket(DeviceObject, Irp, NULL, NULL);

        }
        return STATUS_PENDING;
    }

    case IOCTL_DVD_END_SESSION: {

        PDVD_SESSION_ID sessionId = Irp->AssociatedIrp.SystemBuffer;

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "DvdDeviceControl: [%p] END_SESSION\n", Irp));

#ifdef ENABLE_RPC0
        if (cdData->DvdRpc0Device && cdData->DvdRpc0LicenseFailure) {
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl: License Failure\n"));
            status = STATUS_COPY_PROTECTION_FAILURE;
            break;
        }
#endif // ENABLE_RPC0

        if(irpStack->Parameters.DeviceIoControl.InputBufferLength <
            sizeof(DVD_SESSION_ID)) {

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl: EndSession - input buffer too "
                        "small\n"));
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        IoMarkIrpPending(Irp);

        if(*sessionId == DVD_END_ALL_SESSIONS) {

            UCHAR uniqueAddress;

            ClassAcquireRemoveLock(DeviceObject, (PIRP)&uniqueAddress);
            ClassReleaseRemoveLock(DeviceObject, Irp);

            status = CdRomDvdEndAllSessionsCompletion(DeviceObject, Irp, NULL);

            ClassReleaseRemoveLock(DeviceObject, (PIRP)&uniqueAddress);

            if(status == STATUS_SUCCESS) {

                //
                // Just complete the request - it was never issued to the
                // lower device
                //

                break;

            } else {

                return STATUS_PENDING;

            }
        }

        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;
    }

    case IOCTL_DVD_GET_REGION: {

        PDVD_COPY_PROTECT_KEY copyProtectKey;
        ULONG keyLength;
        IO_STATUS_BLOCK ioStatus = {0};
        PDVD_DESCRIPTOR_HEADER dvdHeader;
        PDVD_COPYRIGHT_DESCRIPTOR copyRightDescriptor;
        PDVD_REGION dvdRegion;
        PDVD_READ_STRUCTURE readStructure;
        PDVD_RPC_KEY rpcKey;

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "DvdDeviceControl: [%p] IOCTL_DVD_GET_REGION\n", Irp));

#ifdef ENABLE_RPC0
        if (cdData->DvdRpc0Device && cdData->DvdRpc0LicenseFailure) {
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl: License Failure\n"));
            status = STATUS_COPY_PROTECTION_FAILURE;
            break;
        }
#endif // ENABLE_RPC0

        if(irpStack->Parameters.DeviceIoControl.OutputBufferLength <
            sizeof(DVD_REGION)) {

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl: output buffer DVD_REGION too small\n"));
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        //
        // figure out how much data buffer we need
        //

        keyLength = max(sizeof(DVD_DESCRIPTOR_HEADER) +
                            sizeof(DVD_COPYRIGHT_DESCRIPTOR),
                        sizeof(DVD_READ_STRUCTURE)
                        );
        keyLength = max(keyLength,
                        DVD_RPC_KEY_LENGTH
                        );

        //
        // round the size to nearest ULONGLONG -- why?
        // could this be to deal with device alignment issues?
        //

        keyLength += sizeof(ULONGLONG) - (keyLength & (sizeof(ULONGLONG) - 1));

        readStructure = ExAllocatePoolWithTag(NonPagedPool,
                                              keyLength,
                                              DVD_TAG_READ_KEY);
        if (readStructure == NULL) {
            status = STATUS_INSUFFICIENT_RESOURCES;
            break;
        }

        RtlZeroMemory (readStructure, keyLength);
        readStructure->Format = DvdCopyrightDescriptor;

        //
        // Build a request for READ_STRUCTURE
        //

        ClassSendDeviceIoControlSynchronous(
            IOCTL_DVD_READ_STRUCTURE,
            DeviceObject,
            readStructure,
            keyLength,
            sizeof(DVD_DESCRIPTOR_HEADER) +
                sizeof(DVD_COPYRIGHT_DESCRIPTOR),
            FALSE,
            &ioStatus);

        status = ioStatus.Status;

        if (!NT_SUCCESS(status)) {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "CdRomDvdGetRegion => read structure failed %x\n",
                        status));
            ExFreePool(readStructure);
            break;
        }

        //
        // we got the copyright descriptor, so now get the region if possible
        //

        dvdHeader = (PDVD_DESCRIPTOR_HEADER) readStructure;
        copyRightDescriptor = (PDVD_COPYRIGHT_DESCRIPTOR) dvdHeader->Data;

        //
        // the original irp's systembuffer has a copy of the info that
        // should be passed down in the request
        //

        dvdRegion = Irp->AssociatedIrp.SystemBuffer;

        dvdRegion->CopySystem = copyRightDescriptor->CopyrightProtectionType;
        dvdRegion->RegionData = copyRightDescriptor->RegionManagementInformation;

        //
        // now reuse the buffer to request the copy protection info
        //

        copyProtectKey = (PDVD_COPY_PROTECT_KEY) readStructure;
        RtlZeroMemory (copyProtectKey, DVD_RPC_KEY_LENGTH);
        copyProtectKey->KeyLength = DVD_RPC_KEY_LENGTH;
        copyProtectKey->KeyType = DvdGetRpcKey;

        //
        // send a request for READ_KEY
        //

        ClassSendDeviceIoControlSynchronous(
            IOCTL_DVD_READ_KEY,
            DeviceObject,
            copyProtectKey,
            DVD_RPC_KEY_LENGTH,
            DVD_RPC_KEY_LENGTH,
            FALSE,
            &ioStatus);
        status = ioStatus.Status;

        if (!NT_SUCCESS(status)) {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "CdRomDvdGetRegion => read key failed %x\n",
                        status));
            ExFreePool(readStructure);
            break;
        }

        //
        // the request succeeded.  if a supported scheme is returned,
        // then return the information to the caller
        //

        rpcKey = (PDVD_RPC_KEY) copyProtectKey->KeyData;

        if (rpcKey->RpcScheme == 1) {

            if (rpcKey->TypeCode) {

                dvdRegion->SystemRegion = ~rpcKey->RegionMask;
                dvdRegion->ResetCount = rpcKey->UserResetsAvailable;

            } else {

                //
                // the drive has not been set for any region
                //

                dvdRegion->SystemRegion = 0;
                dvdRegion->ResetCount = rpcKey->UserResetsAvailable;
            }
            Irp->IoStatus.Information = sizeof(DVD_REGION);

        } else {

            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "CdRomDvdGetRegion => rpcKey->RpcScheme != 1\n"));
            status = STATUS_INVALID_DEVICE_REQUEST;
        }

        ExFreePool(readStructure);
        break;
    }


    case IOCTL_STORAGE_SET_READ_AHEAD: {

        if(irpStack->Parameters.DeviceIoControl.InputBufferLength <
           sizeof(STORAGE_SET_READ_AHEAD)) {

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "DvdDeviceControl: SetReadAhead buffer too small\n"));
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;
    }

    case IOCTL_DISK_IS_WRITABLE: {

        // all verification done in StartIo()
        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);

        return STATUS_PENDING;

    }

    case IOCTL_DISK_GET_DRIVE_LAYOUT: {

        ULONG size;

        //
        // we always fake zero or one partitions, and one partition
        // structure is included in DRIVE_LAYOUT_INFORMATION
        //

        size = FIELD_OFFSET(DRIVE_LAYOUT_INFORMATION, PartitionEntry[1]);

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomDeviceControl: Get drive layout\n"));
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength < size) {
            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = size;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;


    }
    case IOCTL_DISK_GET_DRIVE_LAYOUT_EX: {

        ULONG size;

        //
        // we always fake zero or one partitions, and one partition
        // structure is included in DRIVE_LAYOUT_INFORMATION_EX
        //

        size = FIELD_OFFSET(DRIVE_LAYOUT_INFORMATION_EX, PartitionEntry[1]);

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomDeviceControl: Get drive layout ex\n"));
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength < size) {
            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = size;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;

    }


    case IOCTL_DISK_GET_PARTITION_INFO: {

        //
        // Check that the buffer is large enough.
        //

        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength <
            sizeof(PARTITION_INFORMATION)) {

            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = sizeof(PARTITION_INFORMATION);
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;

    }
    case IOCTL_DISK_GET_PARTITION_INFO_EX: {

        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength <
            sizeof(PARTITION_INFORMATION_EX)) {

            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = sizeof(PARTITION_INFORMATION_EX);
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }

    case IOCTL_DISK_VERIFY: {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "IOCTL_DISK_VERIFY to device %p through irp %p\n",
                    DeviceObject, Irp));

        //
        // Validate buffer length.
        //

        if (irpStack->Parameters.DeviceIoControl.InputBufferLength <
            sizeof(VERIFY_INFORMATION)) {

            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }
        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }

    case IOCTL_DISK_GET_LENGTH_INFO: {

        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength <
            sizeof(GET_LENGTH_INFORMATION)) {
            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = sizeof(GET_LENGTH_INFORMATION);
            break;
        }
        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }

    case IOCTL_CDROM_GET_CONFIGURATION: {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "IOCTL_CDROM_GET_CONFIGURATION to via irp %p\n", Irp));

        //
        // Validate buffer length.
        //

        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength <
            sizeof(GET_CONFIGURATION_HEADER)) {
            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = sizeof(GET_CONFIGURATION_HEADER);
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength > 0xffff) {
            // output buffer is too large
            status = STATUS_INVALID_BUFFER_SIZE;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength &
            fdoExtension->AdapterDescriptor->AlignmentMask) {
            // buffer is not proper size multiple
            status = STATUS_INVALID_PARAMETER;
            break;
        }

#if defined (_WIN64)
        if (IoIs32bitProcess(Irp)) {

            PGET_CONFIGURATION_IOCTL_INPUT32 inputBuffer;

            if (irpStack->Parameters.DeviceIoControl.InputBufferLength <
                sizeof(GET_CONFIGURATION_IOCTL_INPUT32)) {
                status = STATUS_INFO_LENGTH_MISMATCH;
                break;
            }
            //
            // also verify the arguments are reasonable.
            //

            inputBuffer = Irp->AssociatedIrp.SystemBuffer;
            if (inputBuffer->Feature > 0xffff) {
                status = STATUS_INVALID_PARAMETER;
                break;
            }
            if ((inputBuffer->RequestType != SCSI_GET_CONFIGURATION_REQUEST_TYPE_ONE) &&
                (inputBuffer->RequestType != SCSI_GET_CONFIGURATION_REQUEST_TYPE_CURRENT) &&
                (inputBuffer->RequestType != SCSI_GET_CONFIGURATION_REQUEST_TYPE_ALL)) {
                status = STATUS_INVALID_PARAMETER;
                break;
            }
            if (inputBuffer->Reserved[0] || inputBuffer->Reserved[1]) {
                status = STATUS_INVALID_PARAMETER;
                break;
            }
        }
        else
#endif
        {
            PGET_CONFIGURATION_IOCTL_INPUT inputBuffer;

            if (irpStack->Parameters.DeviceIoControl.InputBufferLength <
                sizeof(GET_CONFIGURATION_IOCTL_INPUT)) {
                status = STATUS_INFO_LENGTH_MISMATCH;
                break;
            }
            //
            // also verify the arguments are reasonable.
            //

            inputBuffer = Irp->AssociatedIrp.SystemBuffer;
            if (inputBuffer->Feature > 0xffff) {
                status = STATUS_INVALID_PARAMETER;
                break;
            }
            if ((inputBuffer->RequestType != SCSI_GET_CONFIGURATION_REQUEST_TYPE_ONE) &&
                (inputBuffer->RequestType != SCSI_GET_CONFIGURATION_REQUEST_TYPE_CURRENT) &&
                (inputBuffer->RequestType != SCSI_GET_CONFIGURATION_REQUEST_TYPE_ALL)) {
                status = STATUS_INVALID_PARAMETER;
                break;
            }
            if (inputBuffer->Reserved[0] || inputBuffer->Reserved[1]) {
                status = STATUS_INVALID_PARAMETER;
                break;
            }
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;

    }

    case IOCTL_CDROM_EXCLUSIVE_ACCESS: {

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "IOCTL_CDROM_EXCLUSIVE_ACCESS to via irp %p\n", Irp));

        status = CdRomDeviceControlExclusiveAccess(DeviceObject, Irp);
        return status;
    }

    case IOCTL_CDROM_SET_SPEED: {

        CDROM_SPEED_REQUEST requestType;
        ULONG requiredLength;

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "IOCTL_CDROM_SET_SPEED to via irp %p\n", Irp));

        if (irpStack->Parameters.DeviceIoControl.InputBufferLength < sizeof(CDROM_SPEED_REQUEST)) {
            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }

        //
        // Get the request type using CDROM_SET_SPEED structure
        //
        requestType = ((PCDROM_SET_SPEED)Irp->AssociatedIrp.SystemBuffer)->RequestType;

        if (requestType > CdromSetStreaming) {
            //
            // Unknown request type.
            //
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        if (requestType == CdromSetSpeed) {

            requiredLength = sizeof(CDROM_SET_SPEED);

        } else {

            //
            // Don't send SET STREAMING command if this is not a MMC compliant device
            //

            if (cdData->Mmc.IsMmc == FALSE) {
                status = STATUS_INVALID_DEVICE_REQUEST;
                break;
            }

            requiredLength = sizeof(CDROM_SET_STREAMING);
        }

        if (irpStack->Parameters.DeviceIoControl.InputBufferLength < requiredLength) {

            //
            // Input buffer too small
            //
            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }

    case IOCTL_AACS_READ_MEDIA_KEY_BLOCK_SIZE:
    {
        PAACS_LAYER_NUMBER layerNumber = (PAACS_LAYER_NUMBER)Irp->AssociatedIrp.SystemBuffer;
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "AACS: Querying MKB Size\n"
                    ));
        if (!cdData->Mmc.IsAACS)
        {
            status = STATUS_INVALID_DEVICE_REQUEST;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.InputBufferLength != sizeof(AACS_LAYER_NUMBER))
        {
            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength < sizeof(ULONG))
        {
            status = STATUS_BUFFER_TOO_SMALL;
            Irp->IoStatus.Information = sizeof(ULONG);
            break;
        }
        else if (irpStack->Parameters.DeviceIoControl.OutputBufferLength > sizeof(ULONG))
        {
            status = STATUS_INVALID_BUFFER_SIZE;
            break;
        }
        if (*layerNumber > 255)
        {
            status = STATUS_INVALID_PARAMETER;
            break;
        }
        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }
    case IOCTL_AACS_READ_MEDIA_KEY_BLOCK:
    {
        PAACS_LAYER_NUMBER layerNumber = (PAACS_LAYER_NUMBER)Irp->AssociatedIrp.SystemBuffer;
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "AACS: Querying full MKB with bufferSize of %x bytes\n",
                    irpStack->Parameters.DeviceIoControl.OutputBufferLength
                    ));
        if (!cdData->Mmc.IsAACS)
        {
            status = STATUS_INVALID_DEVICE_REQUEST;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.InputBufferLength != sizeof(AACS_LAYER_NUMBER))
        {
            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }
        // This is a variable-length structure, but we're pretty sure
        // it can never be less than eight bytes...
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength < 8)
        {
            Irp->IoStatus.Information = 8;
            status = STATUS_BUFFER_TOO_SMALL;
            break;
        }
        if (*layerNumber > 255)
        {
            status = STATUS_INVALID_PARAMETER;
            break;
        }
        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }
    case IOCTL_AACS_START_SESSION:
    {
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "AACS: Requesting AGID\n"
                    ));
        if (!cdData->Mmc.IsAACS)
        {
            status = STATUS_INVALID_DEVICE_REQUEST;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength < sizeof(DVD_SESSION_ID))
        {
            Irp->IoStatus.Information = sizeof(DVD_SESSION_ID);
            status = STATUS_BUFFER_TOO_SMALL;
            break;
        }
        else if (irpStack->Parameters.DeviceIoControl.OutputBufferLength > sizeof(DVD_SESSION_ID))
        {
            status = STATUS_INVALID_BUFFER_SIZE;
            break;
        }
        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }
    case IOCTL_AACS_SEND_CERTIFICATE:
    {
        DVD_SESSION_ID sessionId;
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "AACS: Sending host certificate to drive\n"
                    ));
        if (!cdData->Mmc.IsAACS)
        {
            status = STATUS_INVALID_DEVICE_REQUEST;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.InputBufferLength != sizeof(AACS_SEND_CERTIFICATE))
        {
            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }
        sessionId = ((PAACS_SEND_CERTIFICATE)(Irp->AssociatedIrp.SystemBuffer))->SessionId;
        if (sessionId > MAX_COPY_PROTECT_AGID)
        {
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }
    case IOCTL_AACS_GET_CERTIFICATE:
    {
        DVD_SESSION_ID sessionId;
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "AACS: Querying drive certificate\n"
                    ));
        if (!cdData->Mmc.IsAACS)
        {
            status = STATUS_INVALID_DEVICE_REQUEST;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.InputBufferLength != sizeof(DVD_SESSION_ID))
        {
            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength < sizeof(AACS_CERTIFICATE))
        {
            Irp->IoStatus.Information = sizeof(AACS_CERTIFICATE);
            status = STATUS_BUFFER_TOO_SMALL;
            break;
        }
        else if (irpStack->Parameters.DeviceIoControl.OutputBufferLength > sizeof(AACS_CERTIFICATE))
        {
            status = STATUS_INVALID_BUFFER_SIZE;
            break;
        }
        sessionId = *((PDVD_SESSION_ID)(Irp->AssociatedIrp.SystemBuffer));
        if (sessionId > MAX_COPY_PROTECT_AGID)
        {
            status = STATUS_INVALID_PARAMETER;
            break;
        }
        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }
    case IOCTL_AACS_GET_CHALLENGE_KEY:
    {
        DVD_SESSION_ID sessionId;
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "AACS: Querying drive challenge key\n"
                    ));
        if (!cdData->Mmc.IsAACS)
        {
            status = STATUS_INVALID_DEVICE_REQUEST;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.InputBufferLength != sizeof(DVD_SESSION_ID))
        {
            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength < sizeof(AACS_CHALLENGE_KEY))
        {
            Irp->IoStatus.Information = sizeof(AACS_CHALLENGE_KEY);
            status = STATUS_BUFFER_TOO_SMALL;
            break;
        }
        else if (irpStack->Parameters.DeviceIoControl.OutputBufferLength > sizeof(AACS_CHALLENGE_KEY))
        {
            status = STATUS_INVALID_BUFFER_SIZE;
            break;
        }
        sessionId = *((PDVD_SESSION_ID)(Irp->AssociatedIrp.SystemBuffer));
        if (sessionId > MAX_COPY_PROTECT_AGID)
        {
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }
    case IOCTL_AACS_SEND_CHALLENGE_KEY:
    {
        DVD_SESSION_ID sessionId;
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "AACS: Sending drive challenge key\n"
                    ));
        if (!cdData->Mmc.IsAACS)
        {
            status = STATUS_INVALID_DEVICE_REQUEST;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.InputBufferLength != sizeof(AACS_SEND_CHALLENGE_KEY))
        {
            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }
        sessionId = ((PAACS_SEND_CHALLENGE_KEY)(Irp->AssociatedIrp.SystemBuffer))->SessionId;
        if (sessionId > MAX_COPY_PROTECT_AGID)
        {
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }
    case IOCTL_AACS_READ_VOLUME_ID:
    {
        DVD_SESSION_ID sessionId;
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "AACS: Reading volume ID\n"
                    ));
        if (!cdData->Mmc.IsAACS)
        {
            status = STATUS_INVALID_DEVICE_REQUEST;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.InputBufferLength != sizeof(DVD_SESSION_ID))
        {
            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength < sizeof(AACS_VOLUME_ID))
        {
            Irp->IoStatus.Information = sizeof(AACS_VOLUME_ID);
            status = STATUS_BUFFER_TOO_SMALL;
            break;
        }
        else if (irpStack->Parameters.DeviceIoControl.OutputBufferLength > sizeof(AACS_VOLUME_ID))
        {
            status = STATUS_INVALID_BUFFER_SIZE;
            break;
        }
        sessionId = *((PDVD_SESSION_ID)(Irp->AssociatedIrp.SystemBuffer));
        if (sessionId > MAX_COPY_PROTECT_AGID)
        {
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }
    case IOCTL_AACS_READ_SERIAL_NUMBER:
    {
        DVD_SESSION_ID sessionId;
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "AACS: Reading Serial Number\n"
                    ));
        if (!cdData->Mmc.IsAACS)
        {
            status = STATUS_INVALID_DEVICE_REQUEST;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.InputBufferLength != sizeof(DVD_SESSION_ID))
        {
            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength < sizeof(AACS_SERIAL_NUMBER))
        {
            Irp->IoStatus.Information = sizeof(AACS_SERIAL_NUMBER);
            status = STATUS_BUFFER_TOO_SMALL;
            break;
        }
        else if (irpStack->Parameters.DeviceIoControl.OutputBufferLength > sizeof(AACS_SERIAL_NUMBER))
        {
            status = STATUS_INVALID_BUFFER_SIZE;
            break;
        }
        sessionId = *((PDVD_SESSION_ID)(Irp->AssociatedIrp.SystemBuffer));
        if (sessionId > MAX_COPY_PROTECT_AGID)
        {
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }
    case IOCTL_AACS_READ_MEDIA_ID:
    {
        DVD_SESSION_ID sessionId;
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "AACS: Reading media ID\n"
                    ));
        if (!cdData->Mmc.IsAACS)
        {
            status = STATUS_INVALID_DEVICE_REQUEST;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.InputBufferLength != sizeof(DVD_SESSION_ID))
        {
            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength < sizeof(AACS_MEDIA_ID))
        {
            Irp->IoStatus.Information = sizeof(AACS_MEDIA_ID);
            status = STATUS_BUFFER_TOO_SMALL;
            break;
        }
        else if (irpStack->Parameters.DeviceIoControl.OutputBufferLength > sizeof(AACS_MEDIA_ID))
        {
            status = STATUS_INVALID_BUFFER_SIZE;
            break;
        }
        sessionId = *((PDVD_SESSION_ID)(Irp->AssociatedIrp.SystemBuffer));
        if (sessionId > MAX_COPY_PROTECT_AGID)
        {
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }
    case IOCTL_AACS_READ_BINDING_NONCE:
    case IOCTL_AACS_GENERATE_BINDING_NONCE:
    {
        PAACS_READ_BINDING_NONCE input;
        if (ioctlCode == IOCTL_AACS_GENERATE_BINDING_NONCE)
        {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "AACS: Generating new binding nonce\n"
                        ));
        }
        else
        {
            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "AACS: Reading existing binding nonce\n"
                        ));
        }
        if (!cdData->Mmc.IsAACS)
        {
            status = STATUS_INVALID_DEVICE_REQUEST;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.InputBufferLength != sizeof(AACS_READ_BINDING_NONCE))
        {
            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.OutputBufferLength < sizeof(AACS_BINDING_NONCE))
        {
            Irp->IoStatus.Information = sizeof(AACS_BINDING_NONCE);
            status = STATUS_BUFFER_TOO_SMALL;
            break;
        }
        else if (irpStack->Parameters.DeviceIoControl.OutputBufferLength > sizeof(AACS_BINDING_NONCE))
        {
            status = STATUS_INVALID_BUFFER_SIZE;
            break;
        }
        input = (PAACS_READ_BINDING_NONCE)(Irp->AssociatedIrp.SystemBuffer);
        if (input->SessionId > MAX_COPY_PROTECT_AGID)
        {
            status = STATUS_INVALID_PARAMETER;
            break;
        }
        if (input->NumberOfSectors > 255)
        {
            status = STATUS_INVALID_PARAMETER;
            break;
        }
        if (input->StartLba > MAXULONG)
        {
            status = STATUS_INVALID_PARAMETER;
            break;
        }

        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }
    case IOCTL_AACS_END_SESSION:
    {
        DVD_SESSION_ID sessionId;
        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "AACS: Reading volume ID\n"
                    ));
        if (!cdData->Mmc.IsAACS)
        {
            status = STATUS_INVALID_DEVICE_REQUEST;
            break;
        }
        if (irpStack->Parameters.DeviceIoControl.InputBufferLength != sizeof(DVD_SESSION_ID))
        {
            status = STATUS_INFO_LENGTH_MISMATCH;
            break;
        }

        // special-case for DVD_END_ALL_SESSIONS
        sessionId = *((PDVD_SESSION_ID)(Irp->AssociatedIrp.SystemBuffer));
        if(sessionId == DVD_END_ALL_SESSIONS)
        {
            // this routine just sends this IOCTL to us repeatedly,
            // once for each of sessionIDs 0..3.
            UCHAR uniqueAddress;
            ClassAcquireRemoveLock(DeviceObject, (PIRP)&uniqueAddress);
            ClassReleaseRemoveLock(DeviceObject, Irp);
            status = CdRomDvdEndAllSessionsCompletion(DeviceObject, Irp, NULL);
            ClassReleaseRemoveLock(DeviceObject, (PIRP)&uniqueAddress);
            if(status == STATUS_SUCCESS)
            {
                break;

            }
            else
            {
                return STATUS_PENDING;
            }
        }
        IoMarkIrpPending(Irp);
        IoStartPacket(DeviceObject, Irp, NULL, NULL);
        return STATUS_PENDING;
    }
    default: {

        //
        // If the ioctl has come in at passive level then we will synchronize
        // with our start-io routine when sending the ioctl.  If the ioctl
        // has come in at a higher interrupt level and it was not handled
        // above then it's unlikely to be a request for the class DLL - however
        // we'll still use it's common code to forward the request through.
        //

        if (KeGetCurrentIrql() == PASSIVE_LEVEL) {

            return CdRomSynchronizeIoctlWithStartIo(DeviceObject, Irp, ClassDeviceControl);

        } else {

            return ClassDeviceControl(DeviceObject, Irp);

        }

    } // end default case

    } // end switch()

    if (status == STATUS_VERIFY_REQUIRED) {

        //
        // If the status is verified required and this request
        // should bypass verify required then retry the request.
        //

        if (irpStack->Flags & SL_OVERRIDE_VERIFY_VOLUME) {
            status = STATUS_IO_DEVICE_ERROR;
            UNREFERENCED_PARAMETER(status); // disables prefast warning; defensive coding...
            goto RetryControl;
        }
    }

    if (IoIsErrorUserInduced(status)) {

        if (Irp->Tail.Overlay.Thread) {
            IoSetHardErrorOrVerifyDevice(Irp, DeviceObject);
        }

    }

    //
    // Update IRP with completion status.
    //

    Irp->IoStatus.Status = status;

    //
    // Complete the request.
    //

    ClassReleaseRemoveLock(DeviceObject, Irp);
    ClassCompleteRequest(DeviceObject, Irp, IO_DISK_INCREMENT);
    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                "CdRomDeviceControl: Status is %lx\n", status));
    return status;

} // end CdRomDeviceControl()


NTSTATUS
CdRomClassIoctlCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    )
/*++

Routine Description:

    This routine signals the event used by CdRomDeviceControl to synchronize
    class driver (and lower level driver) ioctls with cdrom's startio routine.
    The irp completion is short-circuited so that CdRomDeviceControlDispatch
    can reissue it once it wakes up.

Arguments:

    DeviceObject - the device object
    Irp - the request we are synchronizing
    Context - a PKEVENT that we need to signal

Return Value:

    NTSTATUS

--*/
{
    PKEVENT syncEvent = (PKEVENT) Context;

    TracePrint((TRACE_LEVEL_VERBOSE, TRACE_FLAG_IOCTL,
                "CdRomClassIoctlCompletion: setting event for irp %p\n", Irp));

    //
    // We released the lock when we completed this request.  Reacquire it.
    //

    ClassAcquireRemoveLock(DeviceObject, Irp);

    KeSetEvent(syncEvent, IO_DISK_INCREMENT, FALSE);

    return STATUS_MORE_PROCESSING_REQUIRED;
}


NTSTATUS
CdRomDeviceControlCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = DeviceObject->DeviceExtension;

    PCDROM_DATA         cdData = (PCDROM_DATA)(commonExtension->DriverData);

    PIO_STACK_LOCATION  irpStack        = IoGetCurrentIrpStackLocation(Irp);
    PIO_STACK_LOCATION  realIrpStack;
    PIO_STACK_LOCATION  realIrpNextStack;

    PSCSI_REQUEST_BLOCK srb     = Context;

    PIRP                realIrp = NULL;

    NTSTATUS            status;
    BOOLEAN             retry;

    //
    // Extract the 'real' irp from the irpstack.
    //

    realIrp = (PIRP) irpStack->Parameters.Others.Argument2;
    realIrpStack = IoGetCurrentIrpStackLocation(realIrp);
    realIrpNextStack = IoGetNextIrpStackLocation(realIrp);

    //
    // check that we've really got the correct irp
    //

    ASSERT(realIrpNextStack->Parameters.Others.Argument3 == Irp);

    //
    // Check SRB status for success of completing request.
    //

    if (SRB_STATUS(srb->SrbStatus) != SRB_STATUS_SUCCESS) {

        ULONG retryInterval;

        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "CdRomDeviceControlCompletion: Irp %p, Srb %p Real Irp %p Status %lx\n",
                    Irp,
                    srb,
                    realIrp,
                    srb->SrbStatus));


        //
        // Release the queue if it is frozen.
        //

        if (srb->SrbStatus & SRB_STATUS_QUEUE_FROZEN) {
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "CdRomDeviceControlCompletion: Releasing Queue\n"));
            ClassReleaseQueue(DeviceObject);
        }

        retry = ClassInterpretSenseInfo(DeviceObject,
                                        srb,
                                        irpStack->MajorFunction,
                                        irpStack->Parameters.DeviceIoControl.IoControlCode,
                                        MAXIMUM_RETRIES - ((ULONG)(ULONG_PTR)realIrpNextStack->Parameters.Others.Argument1),
                                        &status,
                                        &retryInterval);

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                    "CdRomDeviceControlCompletion: IRP will %sbe retried\n",
                    (retry ? "" : "not ")));

        //
        // Some of the Device Controls need special cases on non-Success status's.
        //

        if (realIrpStack->MajorFunction == IRP_MJ_DEVICE_CONTROL) {
            if ((realIrpStack->Parameters.DeviceIoControl.IoControlCode == IOCTL_CDROM_GET_LAST_SESSION) ||
                (realIrpStack->Parameters.DeviceIoControl.IoControlCode == IOCTL_CDROM_READ_TOC)         ||
                (realIrpStack->Parameters.DeviceIoControl.IoControlCode == IOCTL_CDROM_READ_TOC_EX)      ||
                (realIrpStack->Parameters.DeviceIoControl.IoControlCode == IOCTL_CDROM_GET_CONFIGURATION)||
                (realIrpStack->Parameters.DeviceIoControl.IoControlCode == IOCTL_CDROM_GET_VOLUME)) {

                if (status == STATUS_DATA_OVERRUN) {
                    status = STATUS_SUCCESS;
                    retry = FALSE;
                }
            }

            if (realIrpStack->Parameters.DeviceIoControl.IoControlCode == IOCTL_CDROM_READ_Q_CHANNEL) {
                PLAY_ACTIVE(fdoExtension) = FALSE;
            }
        }

        //
        // If the status is verified required and the this request
        // should bypass verify required then retry the request.
        //

        if (realIrpStack->Flags & SL_OVERRIDE_VERIFY_VOLUME &&
            status == STATUS_VERIFY_REQUIRED) {

            // note: status gets overwritten here
            status = STATUS_IO_DEVICE_ERROR;
            retry = TRUE;

            if (((realIrpStack->MajorFunction == IRP_MJ_DEVICE_CONTROL) ||
                 (realIrpStack->MajorFunction == IRP_MJ_INTERNAL_DEVICE_CONTROL)
                ) &&
                ((realIrpStack->Parameters.DeviceIoControl.IoControlCode ==
                  IOCTL_CDROM_CHECK_VERIFY) ||
                 (realIrpStack->Parameters.DeviceIoControl.IoControlCode ==
                  IOCTL_STORAGE_CHECK_VERIFY) ||
                 (realIrpStack->Parameters.DeviceIoControl.IoControlCode ==
                  IOCTL_STORAGE_CHECK_VERIFY2) ||
                 (realIrpStack->Parameters.DeviceIoControl.IoControlCode ==
                  IOCTL_DISK_CHECK_VERIFY)
                )
               ) {

                //
                // Update the geometry information, as the media could have
                // changed. The completion routine for this will complete
                // the real irp and start the next packet.
                //

                if (srb->SenseInfoBuffer) {
                    ExFreePool(srb->SenseInfoBuffer);
                }
                if (srb->DataBuffer) {
                    ExFreePool(srb->DataBuffer);
                }
                ExFreePool(srb); srb = NULL;

                if (Irp->MdlAddress) {
                    IoFreeMdl(Irp->MdlAddress);
                    Irp->MdlAddress = NULL;
                }

                IoFreeIrp(Irp);
                Irp = NULL;

                status = CdRomUpdateCapacity(fdoExtension, realIrp, NULL);
                TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                            "CdRomDeviceControlCompletion: [%p] "
                            "CdRomUpdateCapacity completed with status %lx\n",
                            realIrp, status));

                //
                // needed to update the capacity.
                // the irp's already handed off to CdRomUpdateCapacity().
                // we've already free'd the current irp.
                // nothing left to do in this code path.
                //

                return STATUS_MORE_PROCESSING_REQUIRED;

            } // end of ioctls to update capacity

        }

        if (retry && ((ULONG)(ULONG_PTR)realIrpNextStack->Parameters.Others.Argument1)--) {

            if (((ULONG)(ULONG_PTR)realIrpNextStack->Parameters.Others.Argument1)) {

                //
                // Retry request.
                //

                TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                            "Retry request %p - Calling StartIo\n", Irp));


                ExFreePool(srb->SenseInfoBuffer);
                if (srb->DataBuffer) {
                    ExFreePool(srb->DataBuffer);
                }
                ExFreePool(srb);
                if (Irp->MdlAddress) {
                    IoFreeMdl(Irp->MdlAddress);
                }

                realIrpNextStack->Parameters.Others.Argument3 = (PVOID)-1;
                IoFreeIrp(Irp);

                CdRomRetryRequest(fdoExtension, realIrp, retryInterval, FALSE);
                return STATUS_MORE_PROCESSING_REQUIRED;
            }

            //
            // Exhausted retries. Fall through and complete the request with
            // the appropriate status.
            //

        }

        if ((realIrpStack->MajorFunction == IRP_MJ_DEVICE_CONTROL) &&
            (realIrpStack->Parameters.DeviceIoControl.IoControlCode == IOCTL_CDROM_SET_SPEED)) {

            //
            // If set speed request fails then we should disable the restore speed option.
            // Otherwise we will try to restore to default speed on next media change,
            // if requested by the caller.
            //

            cdData->RestoreDefaults = FALSE;
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "CdRomSetSpeed: Disable restore default\n"));
        }

    } else {

        //
        // Set status for successful request.
        //

        status = STATUS_SUCCESS;

    }

#ifdef ENABLE_AACS_TESTING
    switch (realIrpStack->Parameters.DeviceIoControl.IoControlCode)
    {
        case IOCTL_AACS_READ_MEDIA_KEY_BLOCK_SIZE:
        {
            static const UCHAR results[] = { 0x80, 0x02, 0x00, 0x02 };
            RtlCopyMemory(srb->DataBuffer, results, SIZEOF_ARRAY(results));
            status = STATUS_SUCCESS;
            break;
        }
        case IOCTL_AACS_READ_MEDIA_KEY_BLOCK:
        {
            static const UCHAR results[] = { 0x80, 0x02, 0x00, 0x02 };
            static const UCHAR defaultFill = 0x30; // '0'
            RtlFillMemory(srb->DataBuffer, 0x8004, defaultFill);
            RtlCopyMemory(srb->DataBuffer, results, SIZEOF_ARRAY(results));
            status = STATUS_SUCCESS;
            break;
        }
        case IOCTL_AACS_START_SESSION:
        {
            static const UCHAR results[] = { 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0 };
            RtlCopyMemory(srb->DataBuffer, results, SIZEOF_ARRAY(results));
            status = STATUS_SUCCESS;
            break;
        }
        case IOCTL_AACS_END_SESSION:
        case IOCTL_AACS_SEND_CERTIFICATE:
        case IOCTL_AACS_SEND_CHALLENGE_KEY:
        {
            status = STATUS_SUCCESS;
            break;
        }
        case IOCTL_AACS_GET_CERTIFICATE:
        {
            static const UCHAR results[] = { 0x00, 0x72, 0x00, 0x00 };
            static const UCHAR defaultFill = 0x31; // '1'
            RtlFillMemory(srb->DataBuffer, 0x0074, defaultFill);
            RtlCopyMemory(srb->DataBuffer, results, SIZEOF_ARRAY(results));
            status = STATUS_SUCCESS;
            break;
        }
        case IOCTL_AACS_GET_CHALLENGE_KEY:
        {
            static const UCHAR results[] = { 0x00, 0x52, 0x00, 0x00 };
            static const UCHAR defaultFill = 0x32; // '2'
            RtlFillMemory(srb->DataBuffer, 0x0054, defaultFill);
            RtlCopyMemory(srb->DataBuffer, results, SIZEOF_ARRAY(results));
            status = STATUS_SUCCESS;
            break;
        }
        case IOCTL_AACS_READ_VOLUME_ID:
        {
            static const UCHAR results[] = { 0x00, 0x22, 0x00, 0x00 };
            static const UCHAR defaultFill = 0x33; // '3'
            RtlFillMemory(srb->DataBuffer, 0x0024, defaultFill);
            RtlCopyMemory(srb->DataBuffer, results, SIZEOF_ARRAY(results));
            status = STATUS_SUCCESS;
            break;
        }
        case IOCTL_AACS_READ_SERIAL_NUMBER:
        {
            static const UCHAR results[] = { 0x00, 0x22, 0x00, 0x00 };
            static const UCHAR defaultFill = 0x34; // '4'
            RtlFillMemory(srb->DataBuffer, 0x0024, defaultFill);
            RtlCopyMemory(srb->DataBuffer, results, SIZEOF_ARRAY(results));
            status = STATUS_SUCCESS;
            break;
        }
        case IOCTL_AACS_READ_MEDIA_ID:
        {
            static const UCHAR results[] = { 0x00, 0x22, 0x00, 0x00 };
            static const UCHAR defaultFill = 0x35; // '5'
            RtlFillMemory(srb->DataBuffer, 0x0024, defaultFill);
            RtlCopyMemory(srb->DataBuffer, results, SIZEOF_ARRAY(results));
            status = STATUS_SUCCESS;
            break;
        }
        case IOCTL_AACS_READ_BINDING_NONCE:
        {
            static const UCHAR results[] = { 0x00, 0x22, 0x00, 0x00 };
            static const UCHAR defaultFill = 0x36; // '6'
            RtlFillMemory(srb->DataBuffer, 0x0024, defaultFill);
            RtlCopyMemory(srb->DataBuffer, results, SIZEOF_ARRAY(results));
            status = STATUS_SUCCESS;
            break;
        }
        case IOCTL_AACS_GENERATE_BINDING_NONCE:
        {
            static const UCHAR results[] = { 0x00, 0x22, 0x00, 0x00 };
            static const UCHAR defaultFill = 0x37; // '7'
            RtlFillMemory(srb->DataBuffer, 0x0024, defaultFill);
            RtlCopyMemory(srb->DataBuffer, results, SIZEOF_ARRAY(results));
            status = STATUS_SUCCESS;
            break;
        }
        default:
        {
            // nothing by default
            break;
        }
    }
#endif ENABLE_AACS_TESTING


    if (NT_SUCCESS(status)) {

        BOOLEAN b = FALSE;


        switch (realIrpStack->Parameters.DeviceIoControl.IoControlCode) {

        case IOCTL_DISK_VERIFY: {
            //
            // nothing to do but return the status...
            //
            break;
        }

        case IOCTL_CDROM_SET_SPEED:
        case IOCTL_STORAGE_SET_READ_AHEAD:
        case IOCTL_CDROM_SET_VOLUME:
        case IOCTL_DVD_END_SESSION:
        case IOCTL_DVD_SEND_KEY:
        case IOCTL_DVD_SEND_KEY2: {

            //
            // nothing to return
            //
            realIrp->IoStatus.Information = 0;
            break;
        }

        case IOCTL_CDROM_PLAY_AUDIO_MSF: {

            PLAY_ACTIVE(fdoExtension) = TRUE;
            realIrp->IoStatus.Information = 0;
            break;
        }
        case IOCTL_CDROM_STOP_AUDIO:
        case IOCTL_CDROM_PAUSE_AUDIO: {

            PLAY_ACTIVE(fdoExtension) = FALSE;
            realIrp->IoStatus.Information = 0;
            break;
        }

        case IOCTL_CDROM_SEEK_AUDIO_MSF:
        case IOCTL_CDROM_RESUME_AUDIO: {
            realIrp->IoStatus.Information = 0;
            break;
        }

        case IOCTL_CDROM_GET_CONFIGURATION: {
            status = CdRomGetConfigCompletion(DeviceObject, Irp, srb);
            break;
        }

        case IOCTL_DISK_GET_LENGTH_INFO: {

            PGET_LENGTH_INFORMATION lengthInfo;

            CdRomInterpretReadCapacity(DeviceObject,
                                       (PREAD_CAPACITY_DATA)srb->DataBuffer);

            lengthInfo = (PGET_LENGTH_INFORMATION)realIrp->AssociatedIrp.SystemBuffer;
            lengthInfo->Length = commonExtension->PartitionLength;
            realIrp->IoStatus.Information = sizeof(GET_LENGTH_INFORMATION);
            status = STATUS_SUCCESS;
            break;
        }

        case IOCTL_DISK_GET_DRIVE_GEOMETRY_EX:
        case IOCTL_CDROM_GET_DRIVE_GEOMETRY_EX: {

            PDISK_GEOMETRY_EX geometryEx;

            CdRomInterpretReadCapacity(DeviceObject,
                                       (PREAD_CAPACITY_DATA)srb->DataBuffer);

            geometryEx = (PDISK_GEOMETRY_EX)(realIrp->AssociatedIrp.SystemBuffer);
            geometryEx->DiskSize = commonExtension->PartitionLength;
            geometryEx->Geometry = fdoExtension->DiskGeometry;
            realIrp->IoStatus.Information =
                FIELD_OFFSET(DISK_GEOMETRY_EX, Data);
            break;
        }

        case IOCTL_DISK_GET_DRIVE_GEOMETRY:
        case IOCTL_CDROM_GET_DRIVE_GEOMETRY: {

            PDISK_GEOMETRY geometry;

            CdRomInterpretReadCapacity(DeviceObject,
                                       (PREAD_CAPACITY_DATA)srb->DataBuffer);

            geometry = (PDISK_GEOMETRY)(realIrp->AssociatedIrp.SystemBuffer);
            *geometry = fdoExtension->DiskGeometry;
            realIrp->IoStatus.Information = sizeof(DISK_GEOMETRY);
            break;
        }

        case IOCTL_DISK_CHECK_VERIFY:
        case IOCTL_STORAGE_CHECK_VERIFY:
        case IOCTL_CDROM_CHECK_VERIFY: {

            if((realIrpStack->Parameters.DeviceIoControl.IoControlCode == IOCTL_CDROM_CHECK_VERIFY) &&
               (realIrpStack->Parameters.DeviceIoControl.OutputBufferLength)) {

                *((PULONG)realIrp->AssociatedIrp.SystemBuffer) =
                    commonExtension->PartitionZeroExtension->MediaChangeCount;

                realIrp->IoStatus.Information = sizeof(ULONG);
            } else {
                realIrp->IoStatus.Information = 0;
            }

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "CdRomDeviceControlCompletion: [%p] completing "
                        "CHECK_VERIFY buddy irp %p\n", realIrp, Irp));
            break;
        }

        case IOCTL_CDROM_READ_TOC_EX: {

            if (srb->DataTransferLength < MINIMUM_CDROM_READ_TOC_EX_SIZE) {
                status = STATUS_INVALID_DEVICE_REQUEST;
                break;
            }

            //
            // Copy the returned info into the user buffer.
            //

            RtlMoveMemory(realIrp->AssociatedIrp.SystemBuffer,
                          srb->DataBuffer,
                          srb->DataTransferLength);

            //
            // update information field.
            //

            realIrp->IoStatus.Information = srb->DataTransferLength;
            break;
        }


        case IOCTL_CDROM_GET_LAST_SESSION:
        case IOCTL_CDROM_READ_TOC: {

            //
            // Copy the returned info into the user buffer.
            //

            RtlMoveMemory(realIrp->AssociatedIrp.SystemBuffer,
                          srb->DataBuffer,
                          srb->DataTransferLength);

            //
            // update information field.
            //

            realIrp->IoStatus.Information = srb->DataTransferLength;
            break;
        }

        case IOCTL_DVD_READ_STRUCTURE: {

            DVD_STRUCTURE_FORMAT format = ((PDVD_READ_STRUCTURE) realIrp->AssociatedIrp.SystemBuffer)->Format;

            PDVD_DESCRIPTOR_HEADER header = realIrp->AssociatedIrp.SystemBuffer;

            FOUR_BYTE fourByte = {0};
            PTWO_BYTE twoByte;
            UCHAR tmp;

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "DvdDeviceControlCompletion - IOCTL_DVD_READ_STRUCTURE: completing irp %p (buddy %p)\n",
                        Irp,
                        realIrp));

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "DvdDCCompletion - READ_STRUCTURE: descriptor format of %d\n", format));

            RtlMoveMemory(header,
                          srb->DataBuffer,
                          srb->DataTransferLength);

            //
            // Cook the data.  There are a number of fields that really
            // should be byte-swapped for the caller.
            //

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                      "DvdDCCompletion - READ_STRUCTURE:\n"
                      "\tHeader at %p\n"
                      "\tDvdDCCompletion - READ_STRUCTURE: data at %p\n"
                      "\tDataBuffer was at %p\n"
                      "\tDataTransferLength was %lx\n",
                      header,
                      header->Data,
                      srb->DataBuffer,
                      srb->DataTransferLength));

            //
            // First the fields in the header
            //

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "READ_STRUCTURE: header->Length %lx -> ",
                           header->Length));
            REVERSE_SHORT(&header->Length);
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "%lx\n", header->Length));

            //
            // Now the fields in the descriptor
            //

            if(format == DvdPhysicalDescriptor) {

                PDVD_LAYER_DESCRIPTOR layer = (PDVD_LAYER_DESCRIPTOR) &(header->Data[0]);

                TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "READ_STRUCTURE: StartingDataSector %lx -> ",
                               layer->StartingDataSector));
                REVERSE_LONG(&(layer->StartingDataSector));
                TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "%lx\n", layer->StartingDataSector));

                TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "READ_STRUCTURE: EndDataSector %lx -> ",
                               layer->EndDataSector));
                REVERSE_LONG(&(layer->EndDataSector));
                TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "%lx\n", layer->EndDataSector));

                TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "READ_STRUCTURE: EndLayerZeroSector %lx -> ",
                               layer->EndLayerZeroSector));
                REVERSE_LONG(&(layer->EndLayerZeroSector));
                TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "%lx\n", layer->EndLayerZeroSector));
            }

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "Status is %lx\n", Irp->IoStatus.Status));
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "DvdDeviceControlCompletion - "
                        "IOCTL_DVD_READ_STRUCTURE: data transfer length of %d\n",
                        srb->DataTransferLength));

            realIrp->IoStatus.Information = srb->DataTransferLength;
            break;
        }

        case IOCTL_DVD_READ_KEY: {

            PDVD_COPY_PROTECT_KEY copyProtectKey = realIrp->AssociatedIrp.SystemBuffer;

            PCDVD_KEY_HEADER keyHeader = srb->DataBuffer;
            ULONG dataLength;

            ULONG transferLength =
                srb->DataTransferLength -
                FIELD_OFFSET(CDVD_KEY_HEADER, Data);

            //
            // Adjust the data length to ignore the two reserved bytes in the
            // header.
            //

            dataLength = (keyHeader->DataLength[0] << 8) +
                         keyHeader->DataLength[1];
            dataLength -= 2;

            //
            // take the minimum of the transferred length and the
            // length as specified in the header.
            //

            if(dataLength < transferLength) {
                transferLength = dataLength;
            }

            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "DvdDeviceControlCompletion: [%p] - READ_KEY with "
                        "transfer length of (%d or %d) bytes\n",
                        Irp,
                        dataLength,
                        srb->DataTransferLength - 2));

            //
            // Copy the key data into the return buffer
            //
            if(copyProtectKey->KeyType == DvdTitleKey) {

                RtlMoveMemory(copyProtectKey->KeyData,
                              keyHeader->Data + 1,
                              transferLength - 1);
                copyProtectKey->KeyData[transferLength - 1] = 0;

                //
                // If this is a title key then we need to copy the CGMS flags
                // as well.
                //
                copyProtectKey->KeyFlags = *(keyHeader->Data);

            } else {

                RtlMoveMemory(copyProtectKey->KeyData,
                              keyHeader->Data,
                              transferLength);
            }

            copyProtectKey->KeyLength = sizeof(DVD_COPY_PROTECT_KEY);
            copyProtectKey->KeyLength += transferLength;

            realIrp->IoStatus.Information = copyProtectKey->KeyLength;
            break;
        }

        case IOCTL_DVD_START_SESSION: {

            PDVD_SESSION_ID sessionId = realIrp->AssociatedIrp.SystemBuffer;

            PCDVD_KEY_HEADER keyHeader = srb->DataBuffer;
            PCDVD_REPORT_AGID_DATA keyData = (PCDVD_REPORT_AGID_DATA) keyHeader->Data;

            *sessionId = keyData->AGID;

            realIrp->IoStatus.Information = sizeof(DVD_SESSION_ID);

            break;
        }




        case IOCTL_CDROM_READ_Q_CHANNEL: {

            PSUB_Q_CHANNEL_DATA userChannelData = realIrp->AssociatedIrp.SystemBuffer;
            PCDROM_SUB_Q_DATA_FORMAT inputBuffer = realIrp->AssociatedIrp.SystemBuffer;
            PSUB_Q_CHANNEL_DATA subQPtr = srb->DataBuffer;

#if DBG
            switch( inputBuffer->Format ) {

            case IOCTL_CDROM_CURRENT_POSITION:
                TracePrint((TRACE_LEVEL_VERBOSE, TRACE_FLAG_IOCTL,"CdRomDeviceControlCompletion: Audio Status is %u\n", subQPtr->CurrentPosition.Header.AudioStatus ));
                TracePrint((TRACE_LEVEL_VERBOSE, TRACE_FLAG_IOCTL,"CdRomDeviceControlCompletion: ADR = 0x%x\n", subQPtr->CurrentPosition.ADR ));
                TracePrint((TRACE_LEVEL_VERBOSE, TRACE_FLAG_IOCTL,"CdRomDeviceControlCompletion: Control = 0x%x\n", subQPtr->CurrentPosition.Control ));
                TracePrint((TRACE_LEVEL_VERBOSE, TRACE_FLAG_IOCTL,"CdRomDeviceControlCompletion: Track = %u\n", subQPtr->CurrentPosition.TrackNumber ));
                TracePrint((TRACE_LEVEL_VERBOSE, TRACE_FLAG_IOCTL,"CdRomDeviceControlCompletion: Index = %u\n", subQPtr->CurrentPosition.IndexNumber ));
                TracePrint((TRACE_LEVEL_VERBOSE, TRACE_FLAG_IOCTL,"CdRomDeviceControlCompletion: Absolute Address = %x\n", *((PULONG)subQPtr->CurrentPosition.AbsoluteAddress) ));
                TracePrint((TRACE_LEVEL_VERBOSE, TRACE_FLAG_IOCTL,"CdRomDeviceControlCompletion: Relative Address = %x\n", *((PULONG)subQPtr->CurrentPosition.TrackRelativeAddress) ));
                break;

            case IOCTL_CDROM_MEDIA_CATALOG:
                TracePrint((TRACE_LEVEL_VERBOSE, TRACE_FLAG_IOCTL,"CdRomDeviceControlCompletion: Audio Status is %u\n", subQPtr->MediaCatalog.Header.AudioStatus ));
                TracePrint((TRACE_LEVEL_VERBOSE, TRACE_FLAG_IOCTL,"CdRomDeviceControlCompletion: Mcval is %u\n", subQPtr->MediaCatalog.Mcval ));
                break;

            case IOCTL_CDROM_TRACK_ISRC:
                TracePrint((TRACE_LEVEL_VERBOSE, TRACE_FLAG_IOCTL,"CdRomDeviceControlCompletion: Audio Status is %u\n", subQPtr->TrackIsrc.Header.AudioStatus ));
                TracePrint((TRACE_LEVEL_VERBOSE, TRACE_FLAG_IOCTL,"CdRomDeviceControlCompletion: Tcval is %u\n", subQPtr->TrackIsrc.Tcval ));
                break;

            }
#endif

            //
            // Update the play active status.
            //

            if (subQPtr->CurrentPosition.Header.AudioStatus == AUDIO_STATUS_IN_PROGRESS) {

                PLAY_ACTIVE(fdoExtension) = TRUE;

            } else {

                PLAY_ACTIVE(fdoExtension) = FALSE;

            }

            //
            // Check if output buffer is large enough to contain
            // the data.
            //

            if (realIrpStack->Parameters.DeviceIoControl.OutputBufferLength <
                srb->DataTransferLength) {

                srb->DataTransferLength =
                    realIrpStack->Parameters.DeviceIoControl.OutputBufferLength;
            }

            //
            // Copy our buffer into users.
            //

            RtlMoveMemory(userChannelData,
                          subQPtr,
                          srb->DataTransferLength);

            realIrp->IoStatus.Information = srb->DataTransferLength;
            break;
        }

        case IOCTL_CDROM_GET_VOLUME: {

            PAUDIO_OUTPUT audioOutput;
            PVOLUME_CONTROL volumeControl = realIrp->AssociatedIrp.SystemBuffer;
            ULONG i;
            ULONG bytesTransferred;

            audioOutput = ClassFindModePage((PCHAR)srb->DataBuffer,
                                            srb->DataTransferLength,
                                            CDROM_AUDIO_CONTROL_PAGE,
                                            FALSE);

            //
            // Verify the page is as big as expected.
            //

            bytesTransferred = (ULONG)((PCHAR) audioOutput - (PCHAR) srb->DataBuffer) +
                                sizeof(AUDIO_OUTPUT);

            if (audioOutput != NULL &&
                srb->DataTransferLength >= bytesTransferred) {

                for (i=0; i<4; i++) {
                    volumeControl->PortVolume[i] =
                        audioOutput->PortOutput[i].Volume;
                }

                //
                // Set bytes transferred in IRP.
                //

                realIrp->IoStatus.Information = sizeof(VOLUME_CONTROL);

            } else {
                realIrp->IoStatus.Information = 0;
                status = STATUS_INVALID_DEVICE_REQUEST;
            }

            break;
        }

        case IOCTL_AACS_READ_MEDIA_KEY_BLOCK_SIZE:
        {
            PDVD_DESCRIPTOR_HEADER header = srb->DataBuffer;
            PCDB cdb = (PCDB)srb->Cdb;
            UCHAR thisPackNumber = cdb->READ_DVD_STRUCTURE.RMDBlockNumber[3];
            UCHAR otherPacks = header->Reserved[1];

            // validate and zero-base the otherPacks
            if (otherPacks == 0)
            {
                TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                            "AACS: Device is reporting zero total packs (invalid)\n"
                            ));
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                break;
            }
            otherPacks--;

            // if not already requested last pack, do so now
            if (otherPacks != thisPackNumber)
            {
                // re-send the command for the other pack number.
                // this is safe here because NT_SUCCESS() is TRUE,
                // and all the rest of this routine does is SetHardError()
                // and release of resources we're still about to use.

                // re-zero the output buffer
                RtlZeroMemory(srb->DataBuffer, sizeof(READ_DVD_STRUCTURES_HEADER));

                // modify the CDB to get the very last pack of the MKB
                cdb->READ_DVD_STRUCTURE.RMDBlockNumber[3] = otherPacks;

                return ResendIoctlForSplitCdb(DeviceObject,
                                               realIrp,
                                               Irp,
                                               srb,
                                               sizeof(READ_DVD_STRUCTURES_HEADER)
                                               );
            }

            // this request already got the last pack
            // so just interpret the data

            REVERSE_SHORT(&header->Length);
            if (header->Length < sizeof(DVD_DESCRIPTOR_HEADER) - RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length))
            {
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
            }
            else
            {
                ULONG totalSize = header->Length;
                // subtract out any remaining bytes in the header
                // to get the number of usable bytes in this pack
                totalSize -=
                    sizeof(DVD_DESCRIPTOR_HEADER) -
                    RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length);
                totalSize += otherPacks * AACS_MKB_PACK_SIZE;

                // save the result and complete the request
                *((PULONG)(realIrp->AssociatedIrp.SystemBuffer)) = totalSize;
                realIrp->IoStatus.Information = sizeof(ULONG);
                realIrp->IoStatus.Status = STATUS_SUCCESS;
            }
            break;
        }
        case IOCTL_AACS_READ_MEDIA_KEY_BLOCK:
        {
            PDVD_DESCRIPTOR_HEADER header = srb->DataBuffer;
            PCDB cdb = (PCDB)srb->Cdb;
            UCHAR thisPackNumber = cdb->READ_DVD_STRUCTURE.RMDBlockNumber[3];
            UCHAR otherPacks = header->Reserved[1];

            // validate and zero-base the otherPacks
            if (otherPacks == 0)
            {
                TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                            "AACS: Device is reporting zero total packs (invalid)\n"
                            ));
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                break;
            }
            otherPacks--;
            
            // make length field native byte ordering
            REVERSE_SHORT(&header->Length);

            // exit if getting invalid data from the drive
            if (header->Length < sizeof(DVD_DESCRIPTOR_HEADER) - RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length))
            {
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                break;
            }

            // success, how many bytes to copy for this pack?
            {
                ULONG totalSize = header->Length;
                ULONG originalBufferSize;

                // subtract out any remaining bytes in the header
                // to get the number of usable bytes in this pack
                totalSize -=
                    sizeof(DVD_DESCRIPTOR_HEADER) -
                    RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length);

                // if not the final pack, this should be a full transfer per spec
                ASSERT( (totalSize == AACS_MKB_PACK_SIZE) || (thisPackNumber == otherPacks) );

                // validate the user's buffer is large enough to accept the full data
                originalBufferSize = realIrpStack->Parameters.DeviceIoControl.OutputBufferLength;

                if (originalBufferSize < totalSize + (AACS_MKB_PACK_SIZE*thisPackNumber))
                {
                    // just return a slightly bigger-than-normal size
                    realIrp->IoStatus.Information = (otherPacks+1)*AACS_MKB_PACK_SIZE;
                    realIrp->IoStatus.Status = STATUS_BUFFER_TOO_SMALL;
                    break;
                }
                else
                {
                    PUCHAR whereToCopy;
                    // determine where to copy to the user's memory
                    whereToCopy = realIrp->AssociatedIrp.SystemBuffer;
                    whereToCopy += AACS_MKB_PACK_SIZE * thisPackNumber;
    
                    RtlCopyMemory(whereToCopy, header->Data, totalSize);

                    // update the Information field here because we already
                    // have calculated the size of the block
                    realIrp->IoStatus.Information = totalSize + (AACS_MKB_PACK_SIZE * thisPackNumber);
                    realIrp->IoStatus.Status = STATUS_SUCCESS;
                }
            }

            // if there are more packs to get from the device, send it again....
            if (thisPackNumber != otherPacks)
            {
                // re-send the command for the next pack number.
                // this is safe here because NT_SUCCESS() is TRUE,
                // and all the rest of this routine does is SetHardError()
                // and release of resources we're still about to use.

                // re-zero the output buffer
                RtlZeroMemory(srb->DataBuffer, sizeof(READ_DVD_STRUCTURES_HEADER));

                // modify the CDB to get the next pack of the MKB
                cdb->READ_DVD_STRUCTURE.RMDBlockNumber[3]++;

                // modify the SRB to be resent
                return ResendIoctlForSplitCdb(DeviceObject,
                                               realIrp,
                                               Irp,
                                               srb,
                                               AACS_MKB_PACK_SIZE + sizeof(READ_DVD_STRUCTURES_HEADER)
                                               );
            }
            // else, that was the end of the transfer, so just complete the request
            break;
        }
        case IOCTL_AACS_START_SESSION:
        {
            PDVD_SESSION_ID sessionId = realIrp->AssociatedIrp.SystemBuffer;
            PCDVD_KEY_HEADER keyHeader = srb->DataBuffer;
            PCDVD_REPORT_AGID_DATA keyData = (PCDVD_REPORT_AGID_DATA) keyHeader->Data;

            *sessionId = (DVD_SESSION_ID)(keyData->AGID);
            realIrp->IoStatus.Information = sizeof(DVD_SESSION_ID);
            break;
        }
        case IOCTL_AACS_END_SESSION:
        case IOCTL_AACS_SEND_CERTIFICATE:
        case IOCTL_AACS_SEND_CHALLENGE_KEY:
        {
            break; // no data returned from the drive
        }
        case IOCTL_AACS_GET_CERTIFICATE:
        {
            PDVD_DESCRIPTOR_HEADER header = srb->DataBuffer;
            ULONG dataLengthToCopy = sizeof(AACS_CERTIFICATE);

            // make length field native byte ordering
            REVERSE_SHORT(&header->Length);

            // exit if getting invalid data from the drive
            if (header->Length < sizeof(DVD_DESCRIPTOR_HEADER) - RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length))
            {
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                break;
            }

            // adjust data length to reflect only the addition data
            header->Length -= sizeof(DVD_DESCRIPTOR_HEADER) - RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length);

            // exit if the drive is returning an unexpected data size
            if (header->Length != dataLengthToCopy)
            {
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                break;
            }

            // else copy the data to the user's buffer
            RtlCopyMemory(realIrp->AssociatedIrp.SystemBuffer, header->Data, dataLengthToCopy);
            realIrp->IoStatus.Information = dataLengthToCopy;
            break;
        }
        case IOCTL_AACS_GET_CHALLENGE_KEY:
        {
            PDVD_DESCRIPTOR_HEADER header = srb->DataBuffer;
            ULONG dataLengthToCopy = sizeof(AACS_CHALLENGE_KEY);

            // make length field native byte ordering
            REVERSE_SHORT(&header->Length);

            // exit if getting invalid data from the drive
            if (header->Length < sizeof(DVD_DESCRIPTOR_HEADER) - RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length))
            {
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                break;
            }

            // adjust data length to reflect only the addition data
            header->Length -= sizeof(DVD_DESCRIPTOR_HEADER) - RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length);

            // exit if the drive is returning an unexpected data size
            if (header->Length != dataLengthToCopy)
            {
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                break;
            }

            // else copy the data to the user's buffer
            RtlCopyMemory(realIrp->AssociatedIrp.SystemBuffer, header->Data, dataLengthToCopy);
            realIrp->IoStatus.Information = dataLengthToCopy;
            break;
        }
        case IOCTL_AACS_READ_VOLUME_ID:
        {
            PDVD_DESCRIPTOR_HEADER header = srb->DataBuffer;
            ULONG dataLengthToCopy = sizeof(AACS_VOLUME_ID);

            // make length field native byte ordering
            REVERSE_SHORT(&header->Length);

            // exit if getting invalid data from the drive
            if (header->Length < sizeof(DVD_DESCRIPTOR_HEADER) - RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length))
            {
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                break;
            }

            // adjust data length to reflect only the addition data
            header->Length -= sizeof(DVD_DESCRIPTOR_HEADER) - RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length);

            // exit if the drive is returning an unexpected data size
            if (header->Length != dataLengthToCopy)
            {
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                break;
            }

            // else copy the data to the user's buffer
            RtlCopyMemory(realIrp->AssociatedIrp.SystemBuffer, header->Data, dataLengthToCopy);
            realIrp->IoStatus.Information = dataLengthToCopy;
            break;
        }
        case IOCTL_AACS_READ_SERIAL_NUMBER:
        {
            PDVD_DESCRIPTOR_HEADER header = srb->DataBuffer;
            ULONG dataLengthToCopy = sizeof(AACS_SERIAL_NUMBER);

            // make length field native byte ordering
            REVERSE_SHORT(&header->Length);

            // exit if getting invalid data from the drive
            if (header->Length < sizeof(DVD_DESCRIPTOR_HEADER) - RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length))
            {
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                break;
            }

            // adjust data length to reflect only the addition data
            header->Length -= sizeof(DVD_DESCRIPTOR_HEADER) - RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length);

            // exit if the drive is returning an unexpected data size
            if (header->Length != dataLengthToCopy)
            {
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                break;
            }

            // else copy the data to the user's buffer
            RtlCopyMemory(realIrp->AssociatedIrp.SystemBuffer, header->Data, dataLengthToCopy);
            realIrp->IoStatus.Information = dataLengthToCopy;
            break;
        }
        case IOCTL_AACS_READ_MEDIA_ID:
        {
            PDVD_DESCRIPTOR_HEADER header = srb->DataBuffer;
            ULONG dataLengthToCopy = sizeof(AACS_MEDIA_ID);

            // make length field native byte ordering
            REVERSE_SHORT(&header->Length);

            // exit if getting invalid data from the drive
            if (header->Length < sizeof(DVD_DESCRIPTOR_HEADER) - RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length))
            {
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                break;
            }

            // adjust data length to reflect only the addition data
            header->Length -= sizeof(DVD_DESCRIPTOR_HEADER) - RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length);

            // exit if the drive is returning an unexpected data size
            if (header->Length != dataLengthToCopy)
            {
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                break;
            }

            // else copy the data to the user's buffer
            RtlCopyMemory(realIrp->AssociatedIrp.SystemBuffer, header->Data, dataLengthToCopy);
            realIrp->IoStatus.Information = dataLengthToCopy;
            break;
        }
        case IOCTL_AACS_GENERATE_BINDING_NONCE:
        case IOCTL_AACS_READ_BINDING_NONCE:
        {
            PDVD_DESCRIPTOR_HEADER header = srb->DataBuffer;
            ULONG dataLengthToCopy = sizeof(AACS_BINDING_NONCE);

            // make length field native byte ordering
            REVERSE_SHORT(&header->Length);

            // exit if getting invalid data from the drive
            if (header->Length < sizeof(DVD_DESCRIPTOR_HEADER) - RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length))
            {
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                break;
            }

            // adjust data length to reflect only the addition data
            header->Length -= sizeof(DVD_DESCRIPTOR_HEADER) - RTL_SIZEOF_THROUGH_FIELD(DVD_DESCRIPTOR_HEADER, Length);

            // exit if the drive is returning an unexpected data size
            if (header->Length != dataLengthToCopy)
            {
                realIrp->IoStatus.Information = 0;
                realIrp->IoStatus.Status = STATUS_IO_DEVICE_ERROR;
                break;
            }

            // else copy the data to the user's buffer
            RtlCopyMemory(realIrp->AssociatedIrp.SystemBuffer, header->Data, dataLengthToCopy);
            realIrp->IoStatus.Information = dataLengthToCopy;
            break;
        }

        default:

            ASSERT(FALSE);
            realIrp->IoStatus.Information = 0;
            status = STATUS_INVALID_DEVICE_REQUEST;

        } // end switch()
    }

    //
    // Deallocate srb and sense buffer.
    //

    if (srb->DataBuffer) {
        ExFreePool(srb->DataBuffer);
    }
    if (srb->SenseInfoBuffer) {
        ExFreePool(srb->SenseInfoBuffer);
    }
    ExFreePool(srb); srb = NULL;

    if (realIrp->PendingReturned) {
        IoMarkIrpPending(realIrp);
    }

    if (Irp->MdlAddress) {
        IoFreeMdl(Irp->MdlAddress);
    }

    IoFreeIrp(Irp);

    //
    // Set status in completing IRP.
    //

    realIrp->IoStatus.Status = status;

    //
    // Set the hard error if necessary.
    //

    if (!NT_SUCCESS(status) && IoIsErrorUserInduced(status)) {

        //
        // Store DeviceObject for filesystem, and clear
        // in IoStatus.Information field.
        //

        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "CdRomDeviceCompletion - Setting Hard Error on realIrp %p\n",
                    realIrp));
        if (realIrp->Tail.Overlay.Thread) {
            IoSetHardErrorOrVerifyDevice(realIrp, DeviceObject);
        }

        realIrp->IoStatus.Information = 0;
    }

    //
    // note: must complete the realIrp, as the completed irp (above)
    //       was self-allocated.
    //

    CdRomCompleteIrpAndStartNextPacketSafely(DeviceObject, realIrp);
    return STATUS_MORE_PROCESSING_REQUIRED;
}


NTSTATUS
CdRomSetVolumeIntermediateCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION deviceExtension = DeviceObject->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = DeviceObject->DeviceExtension;

    PIO_STACK_LOCATION  irpStack = IoGetCurrentIrpStackLocation(Irp);
    PIO_STACK_LOCATION  realIrpStack;
    PIO_STACK_LOCATION  realIrpNextStack;
    PSCSI_REQUEST_BLOCK srb     = Context;
    PIRP                realIrp = NULL;
    NTSTATUS            status;
    BOOLEAN             retry;

    //
    // Extract the 'real' irp from the irpstack.
    //

    realIrp = (PIRP) irpStack->Parameters.Others.Argument2;
    realIrpStack = IoGetCurrentIrpStackLocation(realIrp);
    realIrpNextStack = IoGetNextIrpStackLocation(realIrp);

    //
    // Check SRB status for success of completing request.
    //

    if (SRB_STATUS(srb->SrbStatus) != SRB_STATUS_SUCCESS) {

        ULONG retryInterval;

        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "CdRomSetVolumeIntermediateCompletion: Irp %p, Srb %p, Real Irp %p\n",
                    Irp,
                    srb,
                    realIrp));

        //
        // Release the queue if it is frozen.
        //

        if (srb->SrbStatus & SRB_STATUS_QUEUE_FROZEN) {
            ClassReleaseQueue(DeviceObject);
        }


        retry = ClassInterpretSenseInfo(DeviceObject,
                                            srb,
                                            irpStack->MajorFunction,
                                            irpStack->Parameters.DeviceIoControl.IoControlCode,
                                            MAXIMUM_RETRIES - ((ULONG)(ULONG_PTR)realIrpNextStack->Parameters.Others.Argument1),
                                            &status,
                                            &retryInterval);

        if (status == STATUS_DATA_OVERRUN) {
            status = STATUS_SUCCESS;
            retry = FALSE;
        }

        //
        // If the status is verified required and the this request
        // should bypass verify required then retry the request.
        //

        if (realIrpStack->Flags & SL_OVERRIDE_VERIFY_VOLUME &&
            status == STATUS_VERIFY_REQUIRED) {

            status = STATUS_IO_DEVICE_ERROR;
            retry = TRUE;
        }

        if (retry && ((ULONG)(ULONG_PTR)realIrpNextStack->Parameters.Others.Argument1)--) {

            if (((ULONG)(ULONG_PTR)realIrpNextStack->Parameters.Others.Argument1)) {

                //
                // Retry request.
                //

                TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                            "Retry request %p - Calling StartIo\n", Irp));


                ExFreePool(srb->SenseInfoBuffer);
                ExFreePool(srb->DataBuffer);
                ExFreePool(srb);
                if (Irp->MdlAddress) {
                    IoFreeMdl(Irp->MdlAddress);
                }

                IoFreeIrp(Irp);

                CdRomRetryRequest(deviceExtension,
                                  realIrp,
                                  retryInterval,
                                  FALSE);

                return STATUS_MORE_PROCESSING_REQUIRED;

            }

            //
            // Exhausted retries. Fall through and complete the request with the appropriate status.
            //

        }
    } else {

        //
        // Set status for successful request.
        //

        status = STATUS_SUCCESS;

    }

    if (NT_SUCCESS(status)) {

        PAUDIO_OUTPUT   audioInput = NULL;
        PAUDIO_OUTPUT   audioOutput;
        PVOLUME_CONTROL volumeControl = realIrp->AssociatedIrp.SystemBuffer;
        ULONG           i,bytesTransferred,headerLength;
        PVOID           dataBuffer;
        PCDB            cdb;

        audioInput = ClassFindModePage((PCHAR)srb->DataBuffer,
                                             srb->DataTransferLength,
                                             CDROM_AUDIO_CONTROL_PAGE,
                                             FALSE);

        //
        // Check to make sure the mode sense data is valid before we go on
        //

        if(audioInput == NULL) {

            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "Mode Sense Page %d not found\n",
                        CDROM_AUDIO_CONTROL_PAGE));

            realIrp->IoStatus.Information = 0;
            realIrp->IoStatus.Status = STATUS_INVALID_DEVICE_REQUEST;
            goto SafeExit;
        }

            headerLength = sizeof(MODE_PARAMETER_HEADER10);

        bytesTransferred = sizeof(AUDIO_OUTPUT) + headerLength;

        //
        // Allocate a new buffer for the mode select.
        //

        dataBuffer = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                    bytesTransferred,
                                    CDROM_TAG_VOLUME_INT);

        if (!dataBuffer) {
            realIrp->IoStatus.Information = 0;
            realIrp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;
            goto SafeExit;
        }

        RtlZeroMemory(dataBuffer, bytesTransferred);

        //
        // Rebuild the data buffer to include the user requested values.
        //

        audioOutput = (PAUDIO_OUTPUT) ((PCHAR) dataBuffer + headerLength);

        for (i=0; i<4; i++) {
            audioOutput->PortOutput[i].Volume =
                volumeControl->PortVolume[i];
            audioOutput->PortOutput[i].ChannelSelection =
                audioInput->PortOutput[i].ChannelSelection;
        }

        audioOutput->CodePage = CDROM_AUDIO_CONTROL_PAGE;
        audioOutput->ParameterLength = sizeof(AUDIO_OUTPUT) - 2;
        audioOutput->Immediate = MODE_SELECT_IMMEDIATE;

        //
        // Free the old data buffer, mdl.
        //

        IoFreeMdl(Irp->MdlAddress);
        Irp->MdlAddress = NULL;
        ExFreePool(srb->DataBuffer);

        //
        // set the data buffer to new allocation, so it can be
        // freed in the exit path
        //

        srb->DataBuffer = dataBuffer;

        //
        // rebuild the srb.
        //

        cdb = (PCDB)srb->Cdb;
        RtlZeroMemory(cdb, CDB12GENERIC_LENGTH);

        srb->SrbStatus = srb->ScsiStatus = 0;
        srb->SrbFlags = deviceExtension->SrbFlags;
        SET_FLAG(srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
        SET_FLAG(srb->SrbFlags, SRB_FLAGS_DATA_OUT);
        srb->DataTransferLength = bytesTransferred;

            cdb->MODE_SELECT10.OperationCode = SCSIOP_MODE_SELECT10;
            cdb->MODE_SELECT10.ParameterListLength[0] = (UCHAR) (bytesTransferred >> 8);
            cdb->MODE_SELECT10.ParameterListLength[1] = (UCHAR) (bytesTransferred & 0xFF);
            cdb->MODE_SELECT10.PFBit = 1;
            srb->CdbLength = 10;

        //
        // Prepare the MDL
        //

        Irp->MdlAddress = IoAllocateMdl(dataBuffer,
                                        bytesTransferred,
                                        FALSE,
                                        FALSE,
                                        (PIRP) NULL);

        if (!Irp->MdlAddress) {
            realIrp->IoStatus.Information = 0;
            realIrp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;
            goto SafeExit;
        }

        MmBuildMdlForNonPagedPool(Irp->MdlAddress);

        irpStack = IoGetNextIrpStackLocation(Irp);
        irpStack->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;
        irpStack->Parameters.DeviceIoControl.IoControlCode = IOCTL_SCSI_EXECUTE_IN;
        irpStack->Parameters.Scsi.Srb = srb;

        //
        // reset the irp completion.
        //

        IoSetCompletionRoutine(Irp,
                               CdRomDeviceControlCompletion,
                               srb,
                               TRUE,
                               TRUE,
                               TRUE);
        //
        // Call the port driver.
        //

        IoCallDriver(commonExtension->LowerDeviceObject, Irp);

        return STATUS_MORE_PROCESSING_REQUIRED;
    }

SafeExit:

    //
    // Deallocate srb and sense buffer.
    //

    if (srb) {
        if (srb->DataBuffer) {
            ExFreePool(srb->DataBuffer);
        }
        if (srb->SenseInfoBuffer) {
            ExFreePool(srb->SenseInfoBuffer);
        }
        ExFreePool(srb);
    }

    if (Irp->PendingReturned) {
      IoMarkIrpPending(Irp);
    }

    if (realIrp->PendingReturned) {
        IoMarkIrpPending(realIrp);
    }

    if (Irp->MdlAddress) {
        IoFreeMdl(Irp->MdlAddress);
    }

    IoFreeIrp(Irp);

    //
    // Set status in completing IRP.
    //

    realIrp->IoStatus.Status = status;

    //
    // Set the hard error if necessary.
    //

    if (!NT_SUCCESS(status) && IoIsErrorUserInduced(status)) {

        //
        // Store DeviceObject for filesystem, and clear
        // in IoStatus.Information field.
        //

        if (realIrp->Tail.Overlay.Thread) {
            IoSetHardErrorOrVerifyDevice(realIrp, DeviceObject);
        }
        realIrp->IoStatus.Information = 0;
    }

    CdRomCompleteIrpAndStartNextPacketSafely(DeviceObject, realIrp);
    return STATUS_MORE_PROCESSING_REQUIRED;
}

NTSTATUS
CdRomDvdEndAllSessionsCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    )

/*++

Routine Description:

    This routine will setup the next stack location to issue an end session
    to the device.  It will increment the session id in the system buffer
    and issue an END_SESSION for that AGID if the AGID is valid.

    When the new AGID is > 3 this routine will complete the request.

Arguments:

    DeviceObject - the device object for this drive

    Irp - the request

    Context - done

Return Value:

    STATUS_MORE_PROCESSING_REQUIRED if there is another AGID to clear
    status otherwise.

--*/

{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PDVD_SESSION_ID sessionId = Irp->AssociatedIrp.SystemBuffer;
    NTSTATUS status;

    if(++(*sessionId) >= MAX_COPY_PROTECT_AGID) {

        //
        // We're done here - just return success and let the io system
        // continue to complete it.
        //

        return STATUS_SUCCESS;

    }

    IoCopyCurrentIrpStackLocationToNext(Irp);
    IoSetCompletionRoutine(Irp,
                           CdRomDvdEndAllSessionsCompletion,
                           NULL,
                           TRUE,
                           FALSE,
                           FALSE);
    IoMarkIrpPending(Irp);
    IoCallDriver(fdoExtension->CommonExtension.DeviceObject, Irp);

    //
    // At this point we have to assume the irp may have already been
    // completed.  Ignore the returned status and return.
    //
    return STATUS_MORE_PROCESSING_REQUIRED;
}

NTSTATUS
CdRomDvdReadDiskKeyCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    )

/*++

Routine Description:

    This routine handles the completion of a request to obtain the disk
    key from the dvd media.  It will transform the raw 2K of key data into
    a DVD_COPY_PROTECT_KEY structure and copy back the saved key parameters
    from the context pointer before returning.

Arguments:

    DeviceObject -

    Irp -

    Context - a DVD_COPY_PROTECT_KEY pointer which contains the key
              parameters handed down by the caller.

Return Value:

    STATUS_SUCCESS;

--*/

{
    PDVD_COPY_PROTECT_KEY savedKey = Context;

    PREAD_DVD_STRUCTURES_HEADER rawKey = Irp->AssociatedIrp.SystemBuffer;
    PDVD_COPY_PROTECT_KEY outputKey = Irp->AssociatedIrp.SystemBuffer;

    if (NT_SUCCESS(Irp->IoStatus.Status)) {

        //
        // Shift the data down to its new position.
        //

        RtlMoveMemory(outputKey->KeyData,
                      rawKey->Data,
                      sizeof(DVD_DISK_KEY_DESCRIPTOR));

        RtlCopyMemory(outputKey,
                      savedKey,
                      sizeof(DVD_COPY_PROTECT_KEY));

        outputKey->KeyLength = DVD_DISK_KEY_LENGTH;

        Irp->IoStatus.Information = DVD_DISK_KEY_LENGTH;

    } else {

        TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                    "DiskKey Failed with status %x, %p (%x) bytes\n",
                    Irp->IoStatus.Status,
                    (PVOID)Irp->IoStatus.Information,
                    ((rawKey->Length[0] << 16) | rawKey->Length[1])
                    ));

    }

    //
    // release the context block
    //

    ExFreePool(Context);

    return STATUS_SUCCESS;
}

NTSTATUS
CdRomXACompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    )

/*++

Routine Description:

    This routine executes when the port driver has completed a request.
    It looks at the SRB status in the completing SRB and if not success
    it checks for valid request sense buffer information. If valid, the
    info is used to update status with more precise message of type of
    error. This routine deallocates the SRB.

Arguments:

    DeviceObject - Supplies the device object which represents the logical
        unit.

    Irp - Supplies the Irp which has completed.

    Context - Supplies a pointer to the SRB.

Return Value:

    NT status

--*/

{
    PIO_STACK_LOCATION irpStack = IoGetCurrentIrpStackLocation(Irp);
    PSCSI_REQUEST_BLOCK srb = Context;
    PFUNCTIONAL_DEVICE_EXTENSION deviceExtension = DeviceObject->DeviceExtension;
    NTSTATUS status;
    BOOLEAN retry;


    //
    // Check SRB status for success of completing request.
    //

    if (SRB_STATUS(srb->SrbStatus) != SRB_STATUS_SUCCESS) {

        ULONG retryInterval;

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "CdromXAComplete: IRP %p  SRB %p  Status %x\n",
                    Irp, srb, srb->SrbStatus));

        //
        // Release the queue if it is frozen.
        //

        if (srb->SrbStatus & SRB_STATUS_QUEUE_FROZEN) {
            ClassReleaseQueue(DeviceObject);
        }

        retry = ClassInterpretSenseInfo(
            DeviceObject,
            srb,
            irpStack->MajorFunction,
            irpStack->MajorFunction == IRP_MJ_DEVICE_CONTROL ? irpStack->Parameters.DeviceIoControl.IoControlCode : 0,
            MAXIMUM_RETRIES - irpStack->MinorFunction, // HACKHACK - REF #0001
            &status,
            &retryInterval);

        //
        // If the status is verified required and the this request
        // should bypass verify required then retry the request.
        //

        if (irpStack->Flags & SL_OVERRIDE_VERIFY_VOLUME &&
            status == STATUS_VERIFY_REQUIRED) {

            status = STATUS_IO_DEVICE_ERROR;
            retry = TRUE;
        }

        if (retry) {

            if (irpStack->MinorFunction != 0) { // HACKHACK - REF #0001

                irpStack->MinorFunction--;      // HACKHACK - REF #0001

                //
                // Retry request.
                //

                TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                            "CdRomXACompletion: Retry request %p (%x) - "
                            "Calling StartIo\n", Irp, irpStack->MinorFunction));


                ExFreePool(srb->SenseInfoBuffer);
                ExFreePool(srb);

                //
                // Call StartIo directly since IoStartNextPacket hasn't been called,
                // the serialisation is still intact.
                //

                CdRomRetryRequest(deviceExtension,
                                  Irp,
                                  retryInterval,
                                  FALSE);

                return STATUS_MORE_PROCESSING_REQUIRED;

            }

            //
            // Exhausted retries, fall through and complete the request
            // with the appropriate status
            //

            TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_IOCTL,
                        "CdRomXACompletion: Retries exhausted for irp %p\n",
                        Irp));

        }

    } else {

        //
        // Set status for successful request.
        //

        status = STATUS_SUCCESS;

    } // end if (SRB_STATUS(srb->SrbStatus) ...

    //
    // Return SRB to nonpaged pool.
    //

    ExFreePool(srb->SenseInfoBuffer);
    ExFreePool(srb);

    //
    // Set status in completing IRP.
    //

    Irp->IoStatus.Status = status;

    //
    // Set the hard error if necessary.
    //

    if (!NT_SUCCESS(status) &&
        IoIsErrorUserInduced(status) &&
        Irp->Tail.Overlay.Thread != NULL ) {

        //
        // Store DeviceObject for filesystem, and clear
        // in IoStatus.Information field.
        //

        IoSetHardErrorOrVerifyDevice(Irp, DeviceObject);
        Irp->IoStatus.Information = 0;
    }

    //
    // If pending has be returned for this irp then mark the current stack as
    // pending.
    //

    if (Irp->PendingReturned) {
      IoMarkIrpPending(Irp);
    }

    {
        KIRQL oldIrql = KeRaiseIrqlToDpcLevel();
        IoStartNextPacket(DeviceObject, TRUE);
        KeLowerIrql(oldIrql);
    }
    ClassReleaseRemoveLock(DeviceObject, Irp);

    return status;
}


VOID
CdRomDeviceControlDvdReadStructure(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PIO_STACK_LOCATION currentIrpStack = IoGetCurrentIrpStackLocation(OriginalIrp);
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCDB cdb = (PCDB)Srb->Cdb;
    PVOID dataBuffer;

    PDVD_READ_STRUCTURE request;
    USHORT dataLength;
    ULONG blockNumber;
    PFOUR_BYTE fourByte;

    ASSERT(currentIrpStack->Parameters.DeviceIoControl.OutputBufferLength <= MAXUSHORT); // verified by IOCTL dispatch handler

    dataLength =
        (USHORT)currentIrpStack->Parameters.DeviceIoControl.OutputBufferLength;

    request = OriginalIrp->AssociatedIrp.SystemBuffer;
    blockNumber =
        (ULONG)(request->BlockByteOffset.QuadPart >> fdoExtension->SectorShift);
    fourByte = (PFOUR_BYTE) &blockNumber;

    Srb->CdbLength = 12;
    Srb->TimeOutValue = fdoExtension->TimeOutValue;
    Srb->SrbFlags = fdoExtension->SrbFlags;
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DATA_IN);

    cdb->READ_DVD_STRUCTURE.OperationCode = SCSIOP_READ_DVD_STRUCTURE;
    cdb->READ_DVD_STRUCTURE.RMDBlockNumber[0] = fourByte->Byte3;
    cdb->READ_DVD_STRUCTURE.RMDBlockNumber[1] = fourByte->Byte2;
    cdb->READ_DVD_STRUCTURE.RMDBlockNumber[2] = fourByte->Byte1;
    cdb->READ_DVD_STRUCTURE.RMDBlockNumber[3] = fourByte->Byte0;
    cdb->READ_DVD_STRUCTURE.LayerNumber   = request->LayerNumber;
    cdb->READ_DVD_STRUCTURE.Format        = (UCHAR)request->Format;

#if DBG
    {
        if ((UCHAR)request->Format > DvdMaxDescriptor) {
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "READ_DVD_STRUCTURE format %x = %s (%x bytes)\n",
                        (UCHAR)request->Format,
                        READ_DVD_STRUCTURE_FORMAT_STRINGS[DvdMaxDescriptor],
                        dataLength
                        ));
        } else {
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "READ_DVD_STRUCTURE format %x = %s (%x bytes)\n",
                        (UCHAR)request->Format,
                        READ_DVD_STRUCTURE_FORMAT_STRINGS[(UCHAR)request->Format],
                        dataLength
                        ));
        }
    }
#endif // DBG

    if (request->Format == DvdDiskKeyDescriptor) {

        cdb->READ_DVD_STRUCTURE.AGID = (UCHAR) request->SessionId;

    }

    cdb->READ_DVD_STRUCTURE.AllocationLength[0] = (UCHAR)(dataLength >> 8);
    cdb->READ_DVD_STRUCTURE.AllocationLength[1] = (UCHAR)(dataLength & 0xff);
    Srb->DataTransferLength = dataLength;

    dataBuffer = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                       dataLength,
                                       DVD_TAG_READ_STRUCTURE);

    if (!dataBuffer) {
        ExFreePool(Srb->SenseInfoBuffer);
        ExFreePool(Srb);
        IoFreeIrp(NewIrp);
        OriginalIrp->IoStatus.Information = 0;
        OriginalIrp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;

        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", OriginalIrp, OriginalIrp->IoStatus.Status));
        CdRomCompleteIrpAndStartNextPacketSafely(Fdo, OriginalIrp);
        return;
    }

    /*
     *  Zero out input buffer in case the device returns fewer bytes than advertized,
     *  which would cause us to return uninitialized kernel memory.
     */
    RtlZeroMemory(dataBuffer, dataLength);

    NewIrp->MdlAddress = IoAllocateMdl(dataBuffer,
                                       dataLength,
                                       FALSE,
                                       FALSE,
                                       (PIRP) NULL);

    if (NewIrp->MdlAddress == NULL) {
        ExFreePool(dataBuffer);
        ExFreePool(Srb->SenseInfoBuffer);
        ExFreePool(Srb);
        IoFreeIrp(NewIrp);
        OriginalIrp->IoStatus.Information = 0;
        OriginalIrp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;

        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", OriginalIrp, OriginalIrp->IoStatus.Status));
        CdRomCompleteIrpAndStartNextPacketSafely(Fdo, OriginalIrp);
        return;
    }

    //
    // Prepare the MDL
    //

    MmBuildMdlForNonPagedPool(NewIrp->MdlAddress);

    Srb->DataBuffer = dataBuffer;

    IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);

    return;
}


VOID
CdRomDeviceControlDvdEndSession(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCDB cdb = (PCDB)Srb->Cdb;

    PDVD_SESSION_ID sessionId = OriginalIrp->AssociatedIrp.SystemBuffer;

    Srb->CdbLength = 12;
    Srb->TimeOutValue = fdoExtension->TimeOutValue;
    Srb->SrbFlags = fdoExtension->SrbFlags;
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_NO_DATA_TRANSFER);

    cdb->SEND_KEY.OperationCode = SCSIOP_SEND_KEY;
    cdb->SEND_KEY.AGID = (UCHAR) (*sessionId);
    cdb->SEND_KEY.KeyFormat = DVD_INVALIDATE_AGID;

    IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);
    return;

}


VOID
CdRomDeviceControlDvdStartSessionReadKey(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PIO_STACK_LOCATION currentIrpStack = IoGetCurrentIrpStackLocation(OriginalIrp);
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCDB cdb = (PCDB)Srb->Cdb;
    NTSTATUS status;

    PDVD_COPY_PROTECT_KEY keyParameters;
    PCDVD_KEY_HEADER keyBuffer = NULL;

    ULONG keyLength, result;

    ULONG allocationLength;
    PFOUR_BYTE fourByte;

    //
    // Both of these use REPORT_KEY commands.
    // Determine the size of the input buffer
    //


    TRY {

        if(currentIrpStack->Parameters.DeviceIoControl.IoControlCode ==
           IOCTL_DVD_READ_KEY) {

            keyParameters = OriginalIrp->AssociatedIrp.SystemBuffer;

            status = RtlULongSub(currentIrpStack->Parameters.DeviceIoControl.OutputBufferLength,
                                 sizeof(DVD_COPY_PROTECT_KEY), &result);
            if (!NT_SUCCESS(status)) {
                LEAVE;
            }

            status = RtlULongAdd(result, sizeof(CDVD_KEY_HEADER), &keyLength);
            if (!NT_SUCCESS(status)) {
                LEAVE;
            }

            //The data length field of REPORT KEY Command occupies two bytes
            keyLength = min(keyLength, MAXUSHORT);

        } else {

            keyParameters = NULL;
            keyLength = sizeof(CDVD_KEY_HEADER) +
                        sizeof(CDVD_REPORT_AGID_DATA);
        }

        keyBuffer = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                          keyLength,
                                          DVD_TAG_READ_KEY);

        if(keyBuffer == NULL) {

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "IOCTL_DVD_READ_KEY - couldn't allocate "
                        "%d byte buffer for key\n",
                        keyLength));
            status = STATUS_INSUFFICIENT_RESOURCES;
            LEAVE;
        }


        NewIrp->MdlAddress = IoAllocateMdl(keyBuffer,
                                           keyLength,
                                           FALSE,
                                           FALSE,
                                           (PIRP) NULL);

        if(NewIrp->MdlAddress == NULL) {

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "IOCTL_DVD_READ_KEY - couldn't create mdl\n"));
            status = STATUS_INSUFFICIENT_RESOURCES;
            LEAVE;
        }

        MmBuildMdlForNonPagedPool(NewIrp->MdlAddress);

        Srb->DataBuffer = keyBuffer;
        Srb->CdbLength = 12;

        cdb->REPORT_KEY.OperationCode = SCSIOP_REPORT_KEY;

        allocationLength = keyLength;
        fourByte = (PFOUR_BYTE) &allocationLength;
        cdb->REPORT_KEY.AllocationLength[0] = fourByte->Byte1;
        cdb->REPORT_KEY.AllocationLength[1] = fourByte->Byte0;

        Srb->DataTransferLength = keyLength;

        //
        // set the specific parameters....
        //

        if(currentIrpStack->Parameters.DeviceIoControl.IoControlCode ==
           IOCTL_DVD_READ_KEY) {

            if(keyParameters->KeyType == DvdTitleKey) {

                ULONG logicalBlockAddress;

                logicalBlockAddress = (ULONG)
                    (keyParameters->Parameters.TitleOffset.QuadPart >>
                     fdoExtension->SectorShift);

                fourByte = (PFOUR_BYTE) &(logicalBlockAddress);

                cdb->REPORT_KEY.LogicalBlockAddress[0] = fourByte->Byte3;
                cdb->REPORT_KEY.LogicalBlockAddress[1] = fourByte->Byte2;
                cdb->REPORT_KEY.LogicalBlockAddress[2] = fourByte->Byte1;
                cdb->REPORT_KEY.LogicalBlockAddress[3] = fourByte->Byte0;
            }

            cdb->REPORT_KEY.KeyFormat = (UCHAR)keyParameters->KeyType;
            cdb->REPORT_KEY.AGID = (UCHAR) keyParameters->SessionId;
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "CdRomDvdReadKey => sending irp %p for irp %p (%s)\n",
                        NewIrp, OriginalIrp, "READ_KEY"));

        } else {

            cdb->REPORT_KEY.KeyFormat = DVD_REPORT_AGID;
            cdb->REPORT_KEY.AGID = 0;
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "CdRomDvdReadKey => sending irp %p for irp %p (%s)\n",
                        NewIrp, OriginalIrp, "START_SESSION"));
        }

        Srb->TimeOutValue = fdoExtension->TimeOutValue;
        Srb->SrbFlags = fdoExtension->SrbFlags;
        SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DATA_IN);

        IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);

        status = STATUS_SUCCESS;

    } FINALLY {

        if (!NT_SUCCESS(status)) {

            //
            // An error occured during setup - free resources and
            // complete this request.
            //
            if (NewIrp->MdlAddress != NULL) {
                IoFreeMdl(NewIrp->MdlAddress);
            }

            if (keyBuffer != NULL) {
                ExFreePool(keyBuffer);
            }
            ExFreePool(Srb->SenseInfoBuffer);
            ExFreePool(Srb);
            IoFreeIrp(NewIrp);

            OriginalIrp->IoStatus.Information = 0;
            OriginalIrp->IoStatus.Status = status;

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", OriginalIrp, OriginalIrp->IoStatus.Status));
            CdRomCompleteIrpAndStartNextPacketSafely(Fdo, OriginalIrp);

        } // end !NT_SUCCESS
    }
    return;
}


VOID
CdRomDeviceControlDvdSendKey(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCDB cdb = (PCDB)Srb->Cdb;

    PDVD_COPY_PROTECT_KEY key;
    PCDVD_KEY_HEADER keyBuffer = NULL;

    NTSTATUS status;
    ULONG keyLength, result;
    PFOUR_BYTE fourByte;

    key = OriginalIrp->AssociatedIrp.SystemBuffer;

    TRY {

        status = RtlULongSub(key->KeyLength, sizeof(DVD_COPY_PROTECT_KEY), &result);
        if (!NT_SUCCESS(status)) {
            LEAVE;
        }

        status = RtlULongAdd(result, sizeof(CDVD_KEY_HEADER), &keyLength);
        if (!NT_SUCCESS(status)) {
            LEAVE;
        }

        //The data length field of SEND KEY Command occupies two bytes
        keyLength = min(keyLength, MAXUSHORT);

        keyBuffer = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                          keyLength,
                                          DVD_TAG_SEND_KEY);

        if(keyBuffer == NULL) {

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "IOCTL_DVD_SEND_KEY - couldn't allocate "
                        "%d byte buffer for key\n",
                        keyLength));
            status = STATUS_INSUFFICIENT_RESOURCES;
            LEAVE;
        }

        RtlZeroMemory(keyBuffer, keyLength);

        //
        // keylength is decremented here by two because the
        // datalength does not include the header, which is two
        // bytes.  keylength is immediately incremented later
        // by the same amount.
        //

        keyLength -= 2;
        fourByte = (PFOUR_BYTE) &keyLength;
        keyBuffer->DataLength[0] = fourByte->Byte1;
        keyBuffer->DataLength[1] = fourByte->Byte0;
        keyLength += 2;

        //
        // copy the user's buffer to our own allocated buffer
        //

        RtlMoveMemory(keyBuffer->Data,
                      key->KeyData,
                      key->KeyLength - sizeof(DVD_COPY_PROTECT_KEY));


        NewIrp->MdlAddress = IoAllocateMdl(keyBuffer,
                                           keyLength,
                                           FALSE,
                                           FALSE,
                                           (PIRP) NULL);

        if(NewIrp->MdlAddress == NULL) {
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                        "IOCTL_DVD_SEND_KEY - couldn't create mdl\n"));
            status = STATUS_INSUFFICIENT_RESOURCES;
            LEAVE;
        }


        MmBuildMdlForNonPagedPool(NewIrp->MdlAddress);

        Srb->CdbLength = 12;
        Srb->DataBuffer = keyBuffer;
        Srb->DataTransferLength = keyLength;

        Srb->TimeOutValue = fdoExtension->TimeOutValue;
        Srb->SrbFlags = fdoExtension->SrbFlags;
        SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DATA_OUT);

        cdb->REPORT_KEY.OperationCode = SCSIOP_SEND_KEY;

        fourByte = (PFOUR_BYTE) &keyLength;

        cdb->SEND_KEY.ParameterListLength[0] = fourByte->Byte1;
        cdb->SEND_KEY.ParameterListLength[1] = fourByte->Byte0;
        cdb->SEND_KEY.KeyFormat = (UCHAR)key->KeyType;
        cdb->SEND_KEY.AGID = (UCHAR) key->SessionId;

        if (key->KeyType == DvdSetRpcKey) {
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "IOCTL_DVD_SEND_KEY - Setting RPC2 drive region\n"));
        } else {
            TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
                        "IOCTL_DVD_SEND_KEY - key type %x\n", key->KeyType));
        }

        IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);

        status = STATUS_SUCCESS;

    } FINALLY {

        if (!NT_SUCCESS(status)) {

            //
            // An error occured during setup - free resources and
            // complete this request.
            //

            if (NewIrp->MdlAddress != NULL) {
                IoFreeMdl(NewIrp->MdlAddress);
            }

            if (keyBuffer != NULL) {
                ExFreePool(keyBuffer);
            }

            ExFreePool(Srb->SenseInfoBuffer);
            ExFreePool(Srb);
            IoFreeIrp(NewIrp);

            OriginalIrp->IoStatus.Information = 0;
            OriginalIrp->IoStatus.Status = status;

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "Cdrom: [%p] Bailing with status %lx\n", OriginalIrp, OriginalIrp->IoStatus.Status));
            CdRomCompleteIrpAndStartNextPacketSafely(Fdo, OriginalIrp);

        }
    }

    return;
}


VOID
CdRomInterpretReadCapacity(
    IN PDEVICE_OBJECT Fdo,
    IN PREAD_CAPACITY_DATA ReadCapacityBuffer
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    ULONG               lastSector;
    ULONG               bps;
    ULONG               lastBit;
    ULONG               tmp;

    ASSERT(ReadCapacityBuffer);
    ASSERT(commonExtension->IsFdo);

    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,
                "CdRomInterpretReadCapacity: Entering\n"));

    //
    // Swizzle bytes from Read Capacity and translate into
    // the necessary geometry information in the device extension.
    //

    tmp = ReadCapacityBuffer->BytesPerBlock;
    ((PFOUR_BYTE)&bps)->Byte0 = ((PFOUR_BYTE)&tmp)->Byte3;
    ((PFOUR_BYTE)&bps)->Byte1 = ((PFOUR_BYTE)&tmp)->Byte2;
    ((PFOUR_BYTE)&bps)->Byte2 = ((PFOUR_BYTE)&tmp)->Byte1;
    ((PFOUR_BYTE)&bps)->Byte3 = ((PFOUR_BYTE)&tmp)->Byte0;

    //
    // Insure that bps is a power of 2.
    // This corrects a problem with the HP 4020i CDR where it
    // returns an incorrect number for bytes per sector.
    //

    if (!bps) {
        bps = 2048;
    } else {
        lastBit = (ULONG) -1;
        while (bps) {
            lastBit++;
            bps = bps >> 1;
        }
        bps = 1 << lastBit;
    }

    fdoExtension->DiskGeometry.BytesPerSector = bps;

    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL, "CdRomInterpretReadCapacity: Calculated bps %#x\n",
                fdoExtension->DiskGeometry.BytesPerSector));

    //
    // Copy last sector in reverse byte order.
    //

    tmp = ReadCapacityBuffer->LogicalBlockAddress;
    ((PFOUR_BYTE)&lastSector)->Byte0 = ((PFOUR_BYTE)&tmp)->Byte3;
    ((PFOUR_BYTE)&lastSector)->Byte1 = ((PFOUR_BYTE)&tmp)->Byte2;
    ((PFOUR_BYTE)&lastSector)->Byte2 = ((PFOUR_BYTE)&tmp)->Byte1;
    ((PFOUR_BYTE)&lastSector)->Byte3 = ((PFOUR_BYTE)&tmp)->Byte0;

    //
    // Calculate sector to byte shift.
    //

    WHICH_BIT(bps, fdoExtension->SectorShift);

    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,"CdRomInterpretReadCapacity: Sector size is %d\n",
        fdoExtension->DiskGeometry.BytesPerSector));

    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_GENERAL,"CdRomInterpretReadCapacity: Number of Sectors is %d\n",
        lastSector + 1));

    //
    // Calculate media capacity in bytes.
    //

    commonExtension->PartitionLength.QuadPart = (LONGLONG)(lastSector + 1);

    //
    // we've defaulted to 32/64 forever.  don't want to change this now...
    //

    fdoExtension->DiskGeometry.TracksPerCylinder = 0x40;
    fdoExtension->DiskGeometry.SectorsPerTrack = 0x20;

    //
    // Calculate number of cylinders.
    //

    fdoExtension->DiskGeometry.Cylinders.QuadPart = (LONGLONG)((lastSector + 1) / (32 * 64));

    commonExtension->PartitionLength.QuadPart =
        (commonExtension->PartitionLength.QuadPart << fdoExtension->SectorShift);


    ASSERT(TEST_FLAG(Fdo->Characteristics, FILE_REMOVABLE_MEDIA));

    //
    // This device supports removable media.
    //

    fdoExtension->DiskGeometry.MediaType = RemovableMedia;

    return;
}

NTSTATUS
CdRomGetConfigCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PSCSI_REQUEST_BLOCK Srb
    )

/*++

Routine Description:


    Some CDROM devices do not handle the GET CONFIGURATION commands with
    TYPE ONE request. The command will time out causing a bus reset.
    To avoid this problem we set a device flag during start device if the device
    fails a TYPE ONE request. If this flag is set the TYPE ONE requests will be
    tried as TYPE ALL request and the data will be converted to TYPE ONE format
    in this routine.

Arguments:

    DeviceObject - Supplies the device object which represents the logical unit.

    Irp - Supplies the Irp which has completed.

    Srb - SRB.

Return Value:

    NT status

--*/
{
    PCOMMON_DEVICE_EXTENSION    commonExtension = DeviceObject->DeviceExtension;
    PCDROM_DATA         cdData = (PCDROM_DATA)(commonExtension->DriverData);
    PIO_STACK_LOCATION  irpStack = IoGetCurrentIrpStackLocation(Irp);
    PFEATURE_HEADER     featureHeader;
    FEATURE_NUMBER      requestedFeature;
    FEATURE_NUMBER      thisFeature;
    ULONG               totalLength = 0;
    ULONG               dataLength = 0;
    ULONG               featureLength = 0;
    ULONG               headerLength = 0;
    NTSTATUS            status = STATUS_SUCCESS;
    PIRP                realIrp = NULL;
    PIO_STACK_LOCATION  realIrpStack;

    PGET_CONFIGURATION_IOCTL_INPUT  inputBuffer;
    PGET_CONFIGURATION_HEADER       header;

    realIrp = (PIRP) irpStack->Parameters.Others.Argument2;
    realIrpStack = IoGetCurrentIrpStackLocation(realIrp);

    inputBuffer = (PGET_CONFIGURATION_IOCTL_INPUT)realIrp->AssociatedIrp.SystemBuffer;

    //
    // Get the feature requested by the caller
    //
    requestedFeature = inputBuffer->Feature;

    if ((inputBuffer->RequestType == SCSI_GET_CONFIGURATION_REQUEST_TYPE_ONE) &&
        TEST_FLAG(cdData->HackFlags, CDROM_HACK_BAD_TYPE_ONE_GET_CONFIG)) {

        if (Srb->DataTransferLength < sizeof(GET_CONFIGURATION_HEADER)) {
            //
            // Not enough data to calculate the data length.
            // So assume feature is not present
            //
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "CdRomGetConfigCompletion: No get config header!\n"));
            status = STATUS_INVALID_DEVICE_REQUEST;
            return status;
        }

        //
        // Calculate the length of valid data available in the
        // capabilities buffer from the DataLength field
        //

        header = (PGET_CONFIGURATION_HEADER) Srb->DataBuffer;
        REVERSE_BYTES(&totalLength, header->DataLength);

        totalLength += RTL_SIZEOF_THROUGH_FIELD(GET_CONFIGURATION_HEADER, DataLength);

        //
        // Make sure the we have enough data in the SRB
        //
        totalLength = min(totalLength, Srb->DataTransferLength);

        //
        // If we have received enough data from the device
        // check for the given feature.
        //
        if (totalLength >= (sizeof(GET_CONFIGURATION_HEADER) + sizeof(FEATURE_HEADER))) {

            //
            // Feature information is present. Verify the feature.
            //
            featureHeader = (PFEATURE_HEADER) ( (PUCHAR)Srb->DataBuffer + sizeof(GET_CONFIGURATION_HEADER));

            thisFeature  =
                (featureHeader->FeatureCode[0] << 8) |
                (featureHeader->FeatureCode[1]);

            if (thisFeature == requestedFeature) {
                //
                // Calculate the feature length
                //
                featureLength = sizeof(FEATURE_HEADER) + featureHeader->AdditionalLength;
            }
        }

        //
        // Calculate the total size
        //
        totalLength = sizeof(GET_CONFIGURATION_HEADER) + featureLength;

        headerLength = totalLength -
                        RTL_SIZEOF_THROUGH_FIELD(GET_CONFIGURATION_HEADER, DataLength);

        REVERSE_BYTES(header->DataLength, &headerLength);

        dataLength = min(totalLength, realIrpStack->Parameters.DeviceIoControl.OutputBufferLength);

        RtlMoveMemory((PUCHAR)realIrp->AssociatedIrp.SystemBuffer,
                       header,
                       dataLength);
         // Set the number of bytes to be returned

        realIrp->IoStatus.Information = dataLength;


    } else {

        //
        // No conversion required, just copy the data
        //

        RtlMoveMemory(realIrp->AssociatedIrp.SystemBuffer,
                      Srb->DataBuffer,
                      Srb->DataTransferLength);
        realIrp->IoStatus.Information = Srb->DataTransferLength;
    }
    return status;
}

NTSTATUS
CdRomDeviceControlExclusiveAccess(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP Irp
    )
/*++

Routine Description:

    This function services IOCTL_CDROM_EXCLUSIVE_ACCESS. This
    handles three different types requests, ExclusiveAccessQueryState,
    ExclusiveAccessLockDevice and ExclusiveAccessUnlockDevice. This
    will validate the input and send the request to the startIO routine
    with an event and will wait. When the startIO routine handles this,
    it will just set the event, which will wake this function to
    continue the processing of the IOCTL in passive level. The appropriate
    function is called to handle each type of request.

Arguments:

    Fdo - Supplies the device object for the CDROM device.

    Irp - Supplies the Irp for the request.

Return Value:

    NT status

--*/
{
    PIO_STACK_LOCATION irpStack = IoGetCurrentIrpStackLocation(Irp);
    PCDROM_EXCLUSIVE_ACCESS exclusiveAccess;
    NTSTATUS status = STATUS_SUCCESS;

    Irp->IoStatus.Information = 0;

    if (KeGetCurrentIrql() != PASSIVE_LEVEL) {
        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "CdRomDeviceControlExclusiveAccess: IOCTL must be called at passive level.\n"));
        status = STATUS_INVALID_DEVICE_REQUEST;
        goto ExAccessErrorExit;
    }

    if (irpStack->Parameters.DeviceIoControl.InputBufferLength < sizeof(CDROM_EXCLUSIVE_ACCESS)) {

        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "CdRomDeviceControlExclusiveAccess: Input buffer too small\n"));
        status = STATUS_INFO_LENGTH_MISMATCH;
        goto ExAccessErrorExit;
    }

    exclusiveAccess = (PCDROM_EXCLUSIVE_ACCESS) Irp->AssociatedIrp.SystemBuffer;

    switch (exclusiveAccess->RequestType) {

        case ExclusiveAccessQueryState: {

            if (irpStack->Parameters.DeviceIoControl.OutputBufferLength <
                sizeof(CDROM_EXCLUSIVE_LOCK_STATE)) {

                //
                // Output buffer too small.
                //

                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "CdRomDeviceControlExclusiveAccess: Output buffer too small\n"));
                Irp->IoStatus.Information = sizeof(CDROM_EXCLUSIVE_LOCK_STATE);
                status = STATUS_BUFFER_TOO_SMALL;
                goto ExAccessErrorExit;
            }
            break;
        }

        case ExclusiveAccessLockDevice: {

            if (irpStack->Parameters.DeviceIoControl.InputBufferLength <
                sizeof(CDROM_EXCLUSIVE_LOCK)) {

                //
                // Input buffer too small
                //

                TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "CdRomDeviceControlExclusiveAccess: Input buffer too small\n"));
                status = STATUS_INFO_LENGTH_MISMATCH;
                goto ExAccessErrorExit;
            }
            break;
        }
        case ExclusiveAccessUnlockDevice: {
            //
            // Nothing to check
            //
            break;
        }

        default:{
            //
            // Unknown request type.
            //
            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "CdRomDeviceControlExclusiveAccess: Invalid request type\n"));
            status = STATUS_INVALID_PARAMETER;
            goto ExAccessErrorExit;
        }
    }

    //
    // Call the request handlers to process the request
    //

    switch (exclusiveAccess->RequestType) {

        case ExclusiveAccessQueryState: {
            status = CdRomSynchronizeIoctlWithStartIo(Fdo, Irp, CdRomQueryLockState);
            break;
        }

        case ExclusiveAccessLockDevice: {
            status = CdRomSynchronizeIoctlWithStartIo(Fdo, Irp, CdRomLockDevice);
            break;
        }

        case ExclusiveAccessUnlockDevice: {
            status = CdRomSynchronizeIoctlWithStartIo(Fdo, Irp, CdRomUnlockDevice);
            break;
        }

    }

    return status;

ExAccessErrorExit:

    ClassReleaseRemoveLock(Fdo,Irp);
    Irp->IoStatus.Status = status;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return status;
}

NTSTATUS
CdRomQueryLockState(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP Irp
    )
/*++

Routine Description:

    This function handles ExclusiveAccessQueryState request type.
    This will return the current lock state and the owner name
    if the device is locked.

Arguments:

    Fdo - Supplies the device object for the CDROM device.

    Irp - Supplies the Irp for the request.

Return Value:

    NT status

--*/
{
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PCDROM_DATA cdData = (PCDROM_DATA)commonExtension->DriverData;
    PCDROM_EXCLUSIVE_LOCK_STATE exclusiveLockState;
    NTSTATUS status = STATUS_SUCCESS;

    exclusiveLockState = (PCDROM_EXCLUSIVE_LOCK_STATE) Irp->AssociatedIrp.SystemBuffer;

    RtlZeroMemory(exclusiveLockState, sizeof(CDROM_EXCLUSIVE_LOCK_STATE));

    if (EXCLUSIVE_MODE(cdData)) {

        //
        // Device is locked for exclusive use
        //

        exclusiveLockState->LockState = TRUE;

        RtlCopyMemory(&exclusiveLockState->CallerName,
                      &cdData->CallerName,
                      CDROM_EXCLUSIVE_CALLER_LENGTH);

    } else {

        //
        // Device is not locked
        //

        exclusiveLockState->LockState = FALSE;
    }
    ClassReleaseRemoveLock(Fdo,Irp);
    Irp->IoStatus.Status = status;
    Irp->IoStatus.Information = sizeof(CDROM_EXCLUSIVE_LOCK_STATE);
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return status;
}


NTSTATUS
CdRomLockDevice(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP Irp
    )
/*++

Routine Description:

    This function handles ExclusiveAccessLockDevice request type.
    This will validate the input and lock the device if it is
    not already locked. This will store the caller name in the
    device extension and send an event log for tracking purposes.

Arguments:

    Fdo - Supplies the device object for the CDROM device.

    Irp - Supplies the Irp for the request.

Return Value:

    NT status

--*/
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PCDROM_DATA cdData = (PCDROM_DATA)commonExtension->DriverData;
    PIO_STACK_LOCATION irpStack = IoGetCurrentIrpStackLocation(Irp);
    PFILE_OBJECT fileObject = irpStack->FileObject;
    PFILE_OBJECT_EXTENSION fsContext = NULL;
    PCDROM_EXCLUSIVE_LOCK exclusiveLock;
    PIO_ERROR_LOG_PACKET logEntry;
    NTSTATUS status = STATUS_SUCCESS;
    ULONG idx, nameLength;


    exclusiveLock = (PCDROM_EXCLUSIVE_LOCK) Irp->AssociatedIrp.SystemBuffer;

    //
    // Validate the caller name string
    //

    for (idx = 0; idx < CDROM_EXCLUSIVE_CALLER_LENGTH &&
                        exclusiveLock->CallerName[idx] != '\0'; idx++) {

        if (!ValidChar(exclusiveLock->CallerName[idx])) {

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                            "CdRomLockDevice: Invalid characters in caller name\n"));
            status = STATUS_INVALID_PARAMETER;
            goto LockDeviceExit;
        }
    }

    if ((idx == 0) || (idx >= CDROM_EXCLUSIVE_CALLER_LENGTH)) {

        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                            "CdRomLockDevice: Not a valid null terminated string.\n"));
        status = STATUS_INVALID_PARAMETER;
        goto LockDeviceExit;

    } else {
        nameLength = idx+1; // Add 1 for the NULL character
        ASSERT(nameLength <= CDROM_EXCLUSIVE_CALLER_LENGTH);
    }

    //
    // Check to make sure we have a file object extension to keep track of this
    // request. If not we'll fail it.
    //

    if (fileObject != NULL) {
        fsContext = ClassGetFsContext(commonExtension, fileObject);
    }

    if (fsContext == NULL) {

        //
        // This handle isn't setup correctly.  We can't let the
        // operation go.
        //

        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "CdRomLockDevice: Unable to lock device, invalid file object\n"));

        status = STATUS_INVALID_HANDLE;
        goto LockDeviceExit;
    }

    //
    // If the file system is still mounted on this device fail the request,
    // unless the force lock flag is set.
    //

    if ((TEST_FLAG(exclusiveLock->Access.Flags, CDROM_LOCK_IGNORE_VOLUME) == FALSE) &&
        (ClassGetVpb(fdoExtension->DeviceObject) != NULL) &&
        (ClassGetVpb(fdoExtension->DeviceObject)->Flags & VPB_MOUNTED)) {

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "CdRomLockDevice: Unable to lock device, file system mounted\n"));
            status = STATUS_INVALID_DEVICE_STATE;
            goto LockDeviceExit;
    }

    //
    // Lock the device for exclusive access if the device is not already locked
    //

    if (InterlockedCompareExchangePointer(&cdData->ExclusiveOwner, fileObject, NULL) == NULL) {

        CLASS_MEDIA_CHANGE_CONTEXT mcnContext;

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "CdRomLockDevice: Entering exclusive mode! Device locked by file object %p\n", fileObject));

        //
        // Zero out the CallerName before storing it in the extension
        //

        RtlZeroMemory(&cdData->CallerName, CDROM_EXCLUSIVE_CALLER_LENGTH);
        RtlCopyMemory(&cdData->CallerName,
                      &exclusiveLock->CallerName,
                      nameLength);

        //
        // Disable MCN and send notification
        //

        ClassDisableMediaChangeDetection(fdoExtension);
        InterlockedIncrement(&(fsContext->McnDisableCount));

        ClassSendNotification(fdoExtension,
                               &GUID_IO_CDROM_EXCLUSIVE_LOCK,
                               0,
                               NULL);

        //
        // Log an informational event with the caller name
        //

        logEntry = IoAllocateErrorLogEntry(
                            fdoExtension->DeviceObject,
                           sizeof(IO_ERROR_LOG_PACKET) + CDROM_EXCLUSIVE_CALLER_LENGTH);

        if (logEntry != NULL) {

            PUCHAR dumpDataPtr = (PUCHAR) logEntry->DumpData;

            logEntry->FinalStatus       = STATUS_SUCCESS;
            logEntry->ErrorCode         = IO_CDROM_EXCLUSIVE_LOCK;
            logEntry->SequenceNumber    = 0;
            logEntry->MajorFunctionCode = IRP_MJ_DEVICE_CONTROL;
            logEntry->IoControlCode     = IOCTL_CDROM_EXCLUSIVE_ACCESS;
            logEntry->RetryCount        = 0;
            logEntry->UniqueErrorValue  = 0x1;
            logEntry->DumpDataSize      = CDROM_EXCLUSIVE_CALLER_LENGTH;

            RtlCopyMemory(dumpDataPtr,
                            (PUCHAR)&cdData->CallerName,
                            CDROM_EXCLUSIVE_CALLER_LENGTH);

            //
            // Write the error log packet.
            //

            IoWriteErrorLogEntry(logEntry);
        }

    } else {

        TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "CdRomLockDevice: Unable to lock device, device already locked.\n"));

        status = STATUS_ACCESS_DENIED;
    }

LockDeviceExit:
    ClassReleaseRemoveLock(Fdo,Irp);
    Irp->IoStatus.Status = status;
    Irp->IoStatus.Information = 0;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return status;

}

NTSTATUS
CdRomUnlockDevice(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP Irp
    )
/*++

Routine Description:

    This function handles ExclusiveAccessUnlockDevice request type.
    This function will unlock a locked device if the request comes
    from the exclusive owner.

Arguments:

    Fdo - Supplies the device object for the CDROM device.

    Irp - Supplies the Irp for the request.

Return Value:

    NT status

--*/
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PCDROM_DATA cdData = (PCDROM_DATA)commonExtension->DriverData;
    PIO_STACK_LOCATION irpStack = IoGetCurrentIrpStackLocation(Irp);
    NTSTATUS status = STATUS_SUCCESS;

    PAGED_CODE();

    //
    // Unlock the device from exclusive mode if the request is
    // from the file object which locked it.
    //

    if (irpStack->MajorFunction == IRP_MJ_DEVICE_CONTROL) {

        PFILE_OBJECT fileObject = irpStack->FileObject;
        PFILE_OBJECT_EXTENSION fsContext = NULL;

        if (!EXCLUSIVE_MODE(cdData)) {

            //
            // Device is not locked for exclusive access.
            // Can not process unlock request.
            //

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "CdRomUnlockDevice: Device not locked for exclusive access, can't unlock device.\n"));
            status = STATUS_INVALID_DEVICE_REQUEST;
            goto UnlockExit;
        }

        //
        // Device is in exclusive mode. Check whether this is from the owner.
        //

        if (!EXCLUSIVE_OWNER(cdData, fileObject)) {

            //
            // Request not from the exclusive owner, can't unlock the device.
            //

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL,
                       "CdRomUnlockDevice: Unable to unlock device, invalid file object\n"));

            status = STATUS_INVALID_HANDLE;
            goto UnlockExit;
        }

        if (fileObject != NULL) {
            fsContext = ClassGetFsContext(commonExtension, fileObject);
        }

        if (fsContext == NULL) {

            TracePrint((TRACE_LEVEL_ERROR, TRACE_FLAG_IOCTL, "CdRomUnlockDevice: Unable to unlock device, invalid file object %p\n", fileObject));

            status = STATUS_INVALID_HANDLE;
            goto UnlockExit;
        }

        //
        // Enable MCN
        //

        if (InterlockedDecrement(&(fsContext->McnDisableCount)) == 0) {
            ClassEnableMediaChangeDetection(fdoExtension);
        }
    }

    //
    // Update the media change count
    //
    InterlockedIncrement(&fdoExtension->MediaChangeCount);

    //
    // Set DO_VERIFY_VOLUME so that the file system will remount on it.
    //

    if ((ClassGetVpb(fdoExtension->DeviceObject) != NULL) &&
        (ClassGetVpb(fdoExtension->DeviceObject)->Flags & VPB_MOUNTED) ) {

        SET_FLAG(fdoExtension->DeviceObject->Flags, DO_VERIFY_VOLUME);
    }

    //
    // Set MMC state to update required
    //

    cdData->Mmc.WriteAllowed = FALSE;
    InterlockedCompareExchange(&(cdData->Mmc.UpdateState),
                               CdromMmcUpdateRequired,
                               CdromMmcUpdateComplete);

    //
    // Send unlock notification
    //

    ClassSendNotification(fdoExtension,
                           &GUID_IO_CDROM_EXCLUSIVE_UNLOCK,
                           0,
                           NULL);

    InterlockedExchangePointer(&cdData->ExclusiveOwner,  NULL);

    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "CdRomUnlockDevice: Device unlocked\n"));

UnlockExit:
    ClassReleaseRemoveLock(Fdo,Irp);
    Irp->IoStatus.Status = status;
    Irp->IoStatus.Information = 0;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return status;
}

BOOLEAN
CdRomIsBlockedStorageIoctl(
    IN PIRP Irp
    )
/*++

Routine Description:

    This routine check whether the given IOCTL is a storage IOCTL.
    If the device type of the IOCTL is one of the storage type
    then it is considered as a storage IOCTL.

Arguments:

    Irp - Supplies the Irp for the request.

Return Value:

    TRUE    - Storage IOCTL
    FALSE   - Non-storage IOCTL

--*/
{
    PIO_STACK_LOCATION irpStack = IoGetCurrentIrpStackLocation(Irp);
    ULONG ioctlCode;
    ULONG baseCode;

    ioctlCode = irpStack->Parameters.DeviceIoControl.IoControlCode;

    baseCode = DEVICE_TYPE_FROM_CTL_CODE(ioctlCode);

    //
    // Allow minimum set of commands that are required for the disk manager
    // to show the CD device, while in exclusive mode.
    // Note: These commands should not generate any requests to the device,
    //       and thus must be handled directly in StartIO during exclusive
    //       access (except for the exclusive owner, of course). 
    //

    if (ioctlCode == IOCTL_SCSI_GET_ADDRESS           ||
        ioctlCode == IOCTL_STORAGE_GET_HOTPLUG_INFO   ||
        ioctlCode == IOCTL_STORAGE_GET_DEVICE_NUMBER  ||
        ioctlCode == IOCTL_STORAGE_GET_MEDIA_TYPES_EX ||
        ioctlCode == IOCTL_CDROM_EXCLUSIVE_ACCESS     ||
        ioctlCode == IOCTL_CDROM_GET_INQUIRY_DATA    ){

        return FALSE;
    }

    if(ioctlCode == IOCTL_STORAGE_QUERY_PROPERTY){
        PSTORAGE_PROPERTY_QUERY query =  Irp->AssociatedIrp.SystemBuffer;
        if (query != NULL) {

            if (query->QueryType == PropertyExistsQuery) {
                //
                //This one should be safe and does not generate request to device.
                //
                return FALSE;
            }
            else if ((query->QueryType == PropertyStandardQuery) &&
                     ((query->PropertyId == StorageDeviceProperty) || 
                      (query->PropertyId == StorageAdapterProperty))) {
                //
                //We will return cached information for this case.
                //
                return FALSE;
            }
        }
    }

    if (baseCode == IOCTL_SCSI_BASE    ||
        baseCode == IOCTL_DISK_BASE    ||
        baseCode == IOCTL_CDROM_BASE   ||
        baseCode == IOCTL_STORAGE_BASE ||
        baseCode == IOCTL_DVD_BASE     ){

        return TRUE;
    }

    return FALSE;
}

VOID
CdRomSetSpeed(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
/*++

Routine Description:

    This function handles IOCTL_CDROM_SET_SPEED request. This will
    build appropriate SRB & CDB and send it to the lower driver.

Arguments:

    Fdo         - Supplies the device object for the CDROM device.
    OriginalIrp - IRP with the IOCTL request
    NewIrp      - IRP_MJ_SCSI IRP targeted for the lower driver
    Srb         - SRB for the new request

Return Value:

    None

--*/
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PCOMMON_DEVICE_EXTENSION commonExtension = Fdo->DeviceExtension;
    PCDROM_DATA cdData = (PCDROM_DATA)commonExtension->DriverData;
    PCDB cdb = (PCDB)Srb->Cdb;
    CDROM_SPEED_REQUEST requestType;

    //
    // Get the request type using CDROM_SET_SPEED structure
    //
    requestType = ((PCDROM_SET_SPEED)OriginalIrp->AssociatedIrp.SystemBuffer)->RequestType;

    if (requestType == CdromSetSpeed) {

        PCDROM_SET_SPEED speed = OriginalIrp->AssociatedIrp.SystemBuffer;

        Srb->TimeOutValue = fdoExtension->TimeOutValue;
        Srb->SrbFlags = fdoExtension->SrbFlags;
        SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
        SET_FLAG(Srb->SrbFlags, SRB_FLAGS_NO_DATA_TRANSFER);

        Srb->CdbLength = 12;
        cdb->SET_CD_SPEED.OperationCode = SCSIOP_SET_CD_SPEED;
        cdb->SET_CD_SPEED.RotationControl = speed->RotationControl;
        REVERSE_BYTES_SHORT(&cdb->SET_CD_SPEED.ReadSpeed, &speed->ReadSpeed);
        REVERSE_BYTES_SHORT(&cdb->SET_CD_SPEED.WriteSpeed, &speed->WriteSpeed);

    } else {

        PCDROM_SET_STREAMING stream = OriginalIrp->AssociatedIrp.SystemBuffer;
        PPERFORMANCE_DESCRIPTOR perfDescriptor;
        ULONG transferLength = sizeof(PERFORMANCE_DESCRIPTOR);

        perfDescriptor = CdRomAllocateDataBuffer(Fdo, OriginalIrp, NewIrp, Srb, transferLength, CDROM_TAG_STREAM);

        if (perfDescriptor == NULL) {
            return;
        }

        perfDescriptor->RandomAccess = stream->RandomAccess;
        perfDescriptor->Exact = stream->SetExact;
        perfDescriptor->RestoreDefaults = stream->RestoreDefaults;
        perfDescriptor->WriteRotationControl = stream->RotationControl;

        REVERSE_BYTES(&perfDescriptor->StartLba,  &stream->StartLba);
        REVERSE_BYTES(&perfDescriptor->EndLba,    &stream->EndLba);
        REVERSE_BYTES(&perfDescriptor->ReadSize,  &stream->ReadSize);
        REVERSE_BYTES(&perfDescriptor->ReadTime,  &stream->ReadTime);
        REVERSE_BYTES(&perfDescriptor->WriteSize, &stream->WriteSize);
        REVERSE_BYTES(&perfDescriptor->WriteTime, &stream->WriteTime);

        Srb->TimeOutValue = fdoExtension->TimeOutValue;
        Srb->SrbFlags = fdoExtension->SrbFlags;
        SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
        SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DATA_OUT);

        Srb->CdbLength = 12;
        cdb->SET_STREAMING.OperationCode = SCSIOP_SET_STREAMING;
        REVERSE_BYTES_SHORT(&cdb->SET_STREAMING.ParameterListLength, &transferLength);

        cdData->RestoreDefaults = stream->Persistent ? FALSE : TRUE;

        TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "CdRomSetSpeed: Restore default speed on media change set to %s\n",
                   cdData->RestoreDefaults ? "true" : "false"));
    }

    IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);

    return;
}

VOID
CdRomRestoreDefaultSpeed(
    IN PDEVICE_OBJECT Fdo,
    IN PIO_WORKITEM WorkItem
    )
/*++

Routine Description:

    This workitem is called on a media change when the CDROM device
    speed should be restored to the default value.

Arguments:

    Fdo      - Supplies the device object for the CDROM device.
    WorkItem - Supplies the pointer to the workitem.

Return Value:

    None

--*/
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = Fdo->DeviceExtension;
    PPERFORMANCE_DESCRIPTOR perfDescriptor;
    ULONG transferLength = sizeof(PERFORMANCE_DESCRIPTOR);
    NTSTATUS status;
    SCSI_REQUEST_BLOCK srb = {0};
    PCDB cdb = (PCDB)srb.Cdb;

    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL, "CdRomRestoreDefaultSpeed: Restore device speed for %p\n", Fdo));

    perfDescriptor = ExAllocatePoolWithTag(NonPagedPoolCacheAligned,
                                           transferLength,
                                           CDROM_TAG_STREAM);
    if (perfDescriptor == NULL) {
        return;
    }

    RtlZeroMemory(perfDescriptor, transferLength);

    perfDescriptor->RestoreDefaults = TRUE;

    srb.DataBuffer = perfDescriptor;
    srb.DataTransferLength = transferLength;
    srb.TimeOutValue = fdoExtension->TimeOutValue;
    srb.SrbFlags = fdoExtension->SrbFlags;
    SET_FLAG(srb.SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
    SET_FLAG(srb.SrbFlags, SRB_FLAGS_DATA_OUT);

    srb.CdbLength = 12;
    cdb->SET_STREAMING.OperationCode = SCSIOP_SET_STREAMING;
    REVERSE_BYTES_SHORT(&cdb->SET_STREAMING.ParameterListLength, &transferLength);

    status = ClassSendSrbSynchronous(Fdo,
                                     &srb,
                                     perfDescriptor,
                                     transferLength,
                                     TRUE);
    TracePrint((TRACE_LEVEL_INFORMATION, TRACE_FLAG_IOCTL,
               "CdRomRestoreDefaultSpeed: Set Streaming command completed with status: 0x%X\n", status));

    ExFreePool(perfDescriptor);
    IoFreeWorkItem(WorkItem);
    return;
}



/*--
Copyright (C) Microsoft Corporation
--*/

#include "string.h"
#include "ntddk.h"
#include "classpnp.h"
#include "ntddstor.h"
#include "ntstrsafe.h"


#include "cdrom.h"

#ifdef DEBUG_USE_WPP
#include "aacs.tmh"
#endif

#ifdef ALLOC_PRAGMA
//#pragma alloc_text(INIT, Xyzzy)
#endif


VOID
UnimplementedAACSFunction(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
/*++

Routine Description:

    This function returns failure for currently unimplemented AACS ioctls.
    The newIrp and SRB were allocated for this IO by the StartIO routine,
    and must therefore be free'd on any failure paths.

Arguments:

    Fdo         - Supplies the device object for the CDROM device.
    OriginalIrp - IRP with the IOCTL request
    NewIrp      - IRP_MJ_SCSI IRP targeted for the lower driver
    Srb         - SRB for the new request

Return Value:

    None

--*/
{
    // not implemented, so just complete the request directly
    // NOTE: Srb->DataBuffer and NewIrp->Mdl are always NULL here
    ASSERT(Srb->DataBuffer == NULL);
    ExFreePool(Srb->SenseInfoBuffer);
    ExFreePool(Srb);
    Srb = NULL;
    ASSERT(NewIrp->MdlAddress == NULL);
    IoFreeIrp(NewIrp);
    NewIrp = NULL;

    OriginalIrp->IoStatus.Information = 0;
    OriginalIrp->IoStatus.Status = STATUS_UNSUCCESSFUL;
    TracePrint((TRACE_LEVEL_WARNING, TRACE_FLAG_INIT,
                "AACS: XYZZY: Failing IOCTL %x with STATUS_UNSUCCESSFUL\n", 
                IoGetCurrentIrpStackLocation(OriginalIrp)->Parameters.DeviceIoControl.IoControlCode
                ));

    CdRomCompleteIrpAndStartNextPacketSafely(Fdo, OriginalIrp);
    return;
}

VOID
AacsGetMediaKeyBlock(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PIO_STACK_LOCATION currentIrpStack = IoGetCurrentIrpStackLocation(OriginalIrp);
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PAACS_LAYER_NUMBER layerNumber = (PAACS_LAYER_NUMBER)OriginalIrp->AssociatedIrp.SystemBuffer;
    PCDB cdb = (PCDB)Srb->Cdb;
    ULONG dataTransferLength = sizeof(READ_DVD_STRUCTURES_HEADER);

    if (currentIrpStack->Parameters.DeviceIoControl.IoControlCode == IOCTL_AACS_READ_MEDIA_KEY_BLOCK)
    {
        dataTransferLength += AACS_MKB_PACK_SIZE; // maximum size for this transfer is one pack + header
    }

    // allocate the buffer
    if (!CdRomAllocateDataBuffer(DeviceObject, OriginalIrp, NewIrp, Srb, dataTransferLength, AACS_TAG_MKB))
    {
        return;
    }

    // fill in the CDB
    cdb->READ_DVD_STRUCTURE.OperationCode = SCSIOP_READ_DVD_STRUCTURE;
    // cdb->AsByte[1] = 0x01; // AACS sub-command not required for this
    // RMDBlockNumber is set to zero....
    cdb->READ_DVD_STRUCTURE.LayerNumber = (UCHAR)(*layerNumber);
    cdb->READ_DVD_STRUCTURE.Format = 0x83; // MKB
    cdb->READ_DVD_STRUCTURE.AllocationLength[0] = (UCHAR)(dataTransferLength >> (8*1));
    cdb->READ_DVD_STRUCTURE.AllocationLength[1] = (UCHAR)(dataTransferLength >> (8*0));
    Srb->CdbLength = 12;
    Srb->TimeOutValue = fdoExtension->TimeOutValue;
    Srb->SrbFlags = fdoExtension->SrbFlags;
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DATA_IN);

    IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);

    return;
}

VOID
AacsGetAgid(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PCDB cdb = (PCDB)Srb->Cdb;
    ULONG dataTransferLength = sizeof(CDVD_KEY_HEADER) + sizeof(CDVD_REPORT_AGID_DATA);

    // allocate the buffer
    if (!CdRomAllocateDataBuffer(DeviceObject, OriginalIrp, NewIrp, Srb, dataTransferLength, AACS_TAG_MKB))
    {
        return;
    }

    // fill in the CDB
    cdb->REPORT_KEY.OperationCode = SCSIOP_REPORT_KEY;
    cdb->AsByte[7] = 0x02; // AACS key class
    cdb->REPORT_KEY.AllocationLength[0] = (UCHAR)(dataTransferLength >> (8*1));
    cdb->REPORT_KEY.AllocationLength[1] = (UCHAR)(dataTransferLength >> (8*0));
    cdb->REPORT_KEY.KeyFormat = 0x00; // DVD_REPORT_AGID?

    Srb->CdbLength = 12;
    Srb->TimeOutValue = fdoExtension->TimeOutValue;
    Srb->SrbFlags = fdoExtension->SrbFlags;
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DATA_IN);

    IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);

    return;
}

VOID
AacsReleaseAgid(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PDVD_SESSION_ID sessionID = (PDVD_SESSION_ID)OriginalIrp->AssociatedIrp.SystemBuffer;
    PCDB cdb = (PCDB)Srb->Cdb;

    // fill in the CDB
    cdb->SEND_KEY.OperationCode = SCSIOP_SEND_KEY;
    cdb->AsByte[7] = 0x02; // AACS key class
    cdb->SEND_KEY.AGID = (UCHAR)(*sessionID);
    cdb->SEND_KEY.KeyFormat = DVD_INVALIDATE_AGID;

    Srb->CdbLength = 12;
    Srb->TimeOutValue = fdoExtension->TimeOutValue;
    Srb->SrbFlags = fdoExtension->SrbFlags;
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_NO_DATA_TRANSFER);

    IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);
    return;
}

VOID
AacsSendHostCertificate(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PAACS_SEND_CERTIFICATE input = (PAACS_SEND_CERTIFICATE)(OriginalIrp->AssociatedIrp.SystemBuffer);
    PCDB cdb = (PCDB)Srb->Cdb;
    ULONG dataTransferLength = sizeof(CDVD_KEY_HEADER) + sizeof(AACS_CERTIFICATE);

    // allocate the buffer
    if (!CdRomAllocateDataBuffer(DeviceObject, OriginalIrp, NewIrp, Srb, dataTransferLength, AACS_TAG_CERT))
    {
        return;
    }

    // copy the input buffer to the data buffer for the transfer
    {
        PCDVD_KEY_HEADER header = Srb->DataBuffer;
        ULONG tmp;
        tmp  = dataTransferLength;
        tmp -= RTL_SIZEOF_THROUGH_FIELD(CDVD_KEY_HEADER, DataLength);

        header->DataLength[0] = (UCHAR)(tmp >> (8*1));
        header->DataLength[1] = (UCHAR)(tmp >> (8*0));
        RtlCopyMemory(header->Data, &(input->Certificate), sizeof(AACS_CERTIFICATE));
    }

    // fill in the CDB
    cdb->SEND_KEY.OperationCode = SCSIOP_SEND_KEY;
    cdb->AsByte[7] = 0x02; // AACS key class
    cdb->SEND_KEY.ParameterListLength[0] = (UCHAR)(dataTransferLength >> (8*1));
    cdb->SEND_KEY.ParameterListLength[1] = (UCHAR)(dataTransferLength >> (8*0));
    cdb->SEND_KEY.AGID = (UCHAR)( input->SessionId );
    cdb->SEND_KEY.KeyFormat = 0x01; // Send Host Challenge Certificate

    Srb->CdbLength = 12;
    Srb->TimeOutValue = fdoExtension->TimeOutValue;
    Srb->SrbFlags = fdoExtension->SrbFlags;
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DATA_OUT);

    IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);
    return;
}

VOID
AacsGetDriveCertificate(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PDVD_SESSION_ID input = (PDVD_SESSION_ID)(OriginalIrp->AssociatedIrp.SystemBuffer);
    PCDB cdb = (PCDB)Srb->Cdb;
    ULONG dataTransferLength = sizeof(CDVD_KEY_HEADER) + sizeof(AACS_CERTIFICATE);

    // allocate the buffer
    if (!CdRomAllocateDataBuffer(DeviceObject, OriginalIrp, NewIrp, Srb, dataTransferLength, AACS_TAG_CERT))
    {
        return;
    }

    // fill in the CDB
    cdb->REPORT_KEY.OperationCode = SCSIOP_REPORT_KEY;
    cdb->AsByte[7] = 0x02; // AACS key class
    cdb->REPORT_KEY.AllocationLength[0] = (UCHAR)(dataTransferLength >> (8*1));
    cdb->REPORT_KEY.AllocationLength[1] = (UCHAR)(dataTransferLength >> (8*0));
    cdb->REPORT_KEY.AGID = (UCHAR)(*input);
    cdb->REPORT_KEY.KeyFormat = 0x01; // Return a drive certificate challenge

    Srb->CdbLength = 12;
    Srb->TimeOutValue = fdoExtension->TimeOutValue;
    Srb->SrbFlags = fdoExtension->SrbFlags;
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DATA_IN);

    IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);
    return;
}

VOID
AacsGetChallengeKey(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PDVD_SESSION_ID input = (PDVD_SESSION_ID)(OriginalIrp->AssociatedIrp.SystemBuffer);
    PCDB cdb = (PCDB)Srb->Cdb;
    ULONG dataTransferLength = sizeof(CDVD_KEY_HEADER) + sizeof(AACS_CHALLENGE_KEY);

    // allocate the buffer
    if (!CdRomAllocateDataBuffer(DeviceObject, OriginalIrp, NewIrp, Srb, dataTransferLength, AACS_TAG_CHALLENGE))
    {
        return;
    }

    // fill in the CDB
    cdb->REPORT_KEY.OperationCode = SCSIOP_REPORT_KEY;
    cdb->AsByte[7] = 0x02; // AACS key class
    cdb->REPORT_KEY.AllocationLength[0] = (UCHAR)(dataTransferLength >> (8*1));
    cdb->REPORT_KEY.AllocationLength[1] = (UCHAR)(dataTransferLength >> (8*0));
    cdb->REPORT_KEY.AGID = (UCHAR)(*input);
    cdb->REPORT_KEY.KeyFormat = 0x02; // Return a drive certificate challenge

    Srb->CdbLength = 12;
    Srb->TimeOutValue = fdoExtension->TimeOutValue;
    Srb->SrbFlags = fdoExtension->SrbFlags;
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DATA_IN);

    IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);
    return;
}

VOID
AacsSendChallengeKey(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PAACS_SEND_CHALLENGE_KEY input = (PAACS_SEND_CHALLENGE_KEY)(OriginalIrp->AssociatedIrp.SystemBuffer);
    PCDB cdb = (PCDB)Srb->Cdb;
    ULONG dataTransferLength = sizeof(CDVD_KEY_HEADER) + sizeof(AACS_CHALLENGE_KEY);

    // allocate the buffer
    if (!CdRomAllocateDataBuffer(DeviceObject, OriginalIrp, NewIrp, Srb, dataTransferLength, AACS_TAG_CHALLENGE))
    {
        return;
    }

    // copy the input buffer to the data buffer for the transfer
    {
        PCDVD_KEY_HEADER header = Srb->DataBuffer;
        ULONG tmp;
        tmp  = dataTransferLength;
        tmp -= RTL_SIZEOF_THROUGH_FIELD(CDVD_KEY_HEADER, DataLength);

        header->DataLength[0] = (UCHAR)(tmp >> (8*1));
        header->DataLength[1] = (UCHAR)(tmp >> (8*0));
        RtlCopyMemory(header->Data, &(input->ChallengeKey), sizeof(AACS_CHALLENGE_KEY));
    }

    // fill in the CDB
    cdb->SEND_KEY.OperationCode = SCSIOP_SEND_KEY;
    cdb->AsByte[7] = 0x02; // AACS key class
    cdb->SEND_KEY.ParameterListLength[0] = (UCHAR)(dataTransferLength >> (8*1));
    cdb->SEND_KEY.ParameterListLength[1] = (UCHAR)(dataTransferLength >> (8*0));
    cdb->SEND_KEY.AGID = (UCHAR)( input->SessionId );
    cdb->SEND_KEY.KeyFormat = 0x02; // Send Host Challenge Certificate

    Srb->CdbLength = 12;
    Srb->TimeOutValue = fdoExtension->TimeOutValue;
    Srb->SrbFlags = fdoExtension->SrbFlags;
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DATA_OUT);

    IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);
    return;
}

VOID
AacsReadVolumeID(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PDVD_SESSION_ID input = (PDVD_SESSION_ID)(OriginalIrp->AssociatedIrp.SystemBuffer);
    PCDB cdb = (PCDB)Srb->Cdb;
    ULONG dataTransferLength = sizeof(CDVD_KEY_HEADER) + sizeof(AACS_VOLUME_ID);

    // allocate the buffer
    if (!CdRomAllocateDataBuffer(DeviceObject, OriginalIrp, NewIrp, Srb, dataTransferLength, AACS_TAG_CHALLENGE))
    {
        return;
    }

    // fill in the CDB
    cdb->READ_DVD_STRUCTURE.OperationCode = SCSIOP_READ_DVD_STRUCTURE;
    cdb->READ_DVD_STRUCTURE.Format = 0x80; // Return the AACS volumeID
    cdb->READ_DVD_STRUCTURE.AllocationLength[0] = (UCHAR)(dataTransferLength >> (8*1));
    cdb->READ_DVD_STRUCTURE.AllocationLength[1] = (UCHAR)(dataTransferLength >> (8*0));
    cdb->READ_DVD_STRUCTURE.AGID = (UCHAR)(*input);

    Srb->CdbLength = 12;
    Srb->TimeOutValue = fdoExtension->TimeOutValue;
    Srb->SrbFlags = fdoExtension->SrbFlags;
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DATA_IN);

    IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);
    return;
}

VOID
AacsReadSerialNumber(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PDVD_SESSION_ID input = (PDVD_SESSION_ID)(OriginalIrp->AssociatedIrp.SystemBuffer);
    PCDB cdb = (PCDB)Srb->Cdb;
    ULONG dataTransferLength = sizeof(CDVD_KEY_HEADER) + sizeof(AACS_SERIAL_NUMBER);

    // allocate the buffer
    if (!CdRomAllocateDataBuffer(DeviceObject, OriginalIrp, NewIrp, Srb, dataTransferLength, AACS_TAG_CHALLENGE))
    {
        return;
    }

    // fill in the CDB
    cdb->READ_DVD_STRUCTURE.OperationCode = SCSIOP_READ_DVD_STRUCTURE;
    cdb->READ_DVD_STRUCTURE.Format = 0x81; // Return the AACS volumeID
    cdb->READ_DVD_STRUCTURE.AllocationLength[0] = (UCHAR)(dataTransferLength >> (8*1));
    cdb->READ_DVD_STRUCTURE.AllocationLength[1] = (UCHAR)(dataTransferLength >> (8*0));
    cdb->READ_DVD_STRUCTURE.AGID = (UCHAR)(*input);

    Srb->CdbLength = 12;
    Srb->TimeOutValue = fdoExtension->TimeOutValue;
    Srb->SrbFlags = fdoExtension->SrbFlags;
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DATA_IN);

    IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);
    return;
}

VOID
AacsReadMediaID(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PDVD_SESSION_ID input = (PDVD_SESSION_ID)(OriginalIrp->AssociatedIrp.SystemBuffer);
    PCDB cdb = (PCDB)Srb->Cdb;
    ULONG dataTransferLength = sizeof(CDVD_KEY_HEADER) + sizeof(AACS_MEDIA_ID);

    // allocate the buffer
    if (!CdRomAllocateDataBuffer(DeviceObject, OriginalIrp, NewIrp, Srb, dataTransferLength, AACS_TAG_CHALLENGE))
    {
        return;
    }

    // fill in the CDB
    cdb->READ_DVD_STRUCTURE.OperationCode = SCSIOP_READ_DVD_STRUCTURE;
    cdb->READ_DVD_STRUCTURE.Format = 0x82; // Return the AACS volumeID
    cdb->READ_DVD_STRUCTURE.AllocationLength[0] = (UCHAR)(dataTransferLength >> (8*1));
    cdb->READ_DVD_STRUCTURE.AllocationLength[1] = (UCHAR)(dataTransferLength >> (8*0));
    cdb->READ_DVD_STRUCTURE.AGID = (UCHAR)(*input);

    Srb->CdbLength = 12;
    Srb->TimeOutValue = fdoExtension->TimeOutValue;
    Srb->SrbFlags = fdoExtension->SrbFlags;
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DATA_IN);

    IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);
    return;
}

VOID
AacsReadBindingNonce(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PAACS_READ_BINDING_NONCE input = (PAACS_READ_BINDING_NONCE)(OriginalIrp->AssociatedIrp.SystemBuffer);
    PCDB cdb = (PCDB)Srb->Cdb;
    ULONG dataTransferLength = sizeof(CDVD_KEY_HEADER) + sizeof(AACS_BINDING_NONCE);

    // allocate the buffer
    if (!CdRomAllocateDataBuffer(DeviceObject, OriginalIrp, NewIrp, Srb, dataTransferLength, AACS_TAG_CHALLENGE))
    {
        return;
    }

    // fill in the CDB
    cdb->REPORT_KEY.OperationCode = SCSIOP_REPORT_KEY;
    cdb->REPORT_KEY.LogicalBlockAddress[0] = (UCHAR)( input->StartLba >> (3*8) );
    cdb->REPORT_KEY.LogicalBlockAddress[1] = (UCHAR)( input->StartLba >> (2*8) );
    cdb->REPORT_KEY.LogicalBlockAddress[2] = (UCHAR)( input->StartLba >> (1*8) );
    cdb->REPORT_KEY.LogicalBlockAddress[3] = (UCHAR)( input->StartLba >> (0*8) );
    cdb->AsByte[6] = (UCHAR)( input->NumberOfSectors );
    cdb->AsByte[7] = 0x02; // AACS key class
    cdb->REPORT_KEY.AllocationLength[0] = (UCHAR)(dataTransferLength >> (8*1));
    cdb->REPORT_KEY.AllocationLength[1] = (UCHAR)(dataTransferLength >> (8*0));
    cdb->REPORT_KEY.AGID = (UCHAR)( input->SessionId );
    cdb->REPORT_KEY.KeyFormat = 0x21; // Return an existing binding nonce

    Srb->CdbLength = 12;
    Srb->TimeOutValue = fdoExtension->TimeOutValue;
    Srb->SrbFlags = fdoExtension->SrbFlags;
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DATA_IN);

    IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);
    return;
}

VOID
AacsGenerateBindingNonce(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    )
{
    PFUNCTIONAL_DEVICE_EXTENSION fdoExtension = DeviceObject->DeviceExtension;
    PAACS_READ_BINDING_NONCE input = (PAACS_READ_BINDING_NONCE)(OriginalIrp->AssociatedIrp.SystemBuffer);
    PCDB cdb = (PCDB)Srb->Cdb;
    ULONG dataTransferLength = sizeof(CDVD_KEY_HEADER) + sizeof(AACS_BINDING_NONCE);

    // allocate the buffer
    if (!CdRomAllocateDataBuffer(DeviceObject, OriginalIrp, NewIrp, Srb, dataTransferLength, AACS_TAG_CHALLENGE))
    {
        return;
    }

    // fill in the CDB
    cdb->REPORT_KEY.OperationCode = SCSIOP_REPORT_KEY;
    cdb->REPORT_KEY.LogicalBlockAddress[0] = (UCHAR)( input->StartLba >> (3*8) );
    cdb->REPORT_KEY.LogicalBlockAddress[1] = (UCHAR)( input->StartLba >> (2*8) );
    cdb->REPORT_KEY.LogicalBlockAddress[2] = (UCHAR)( input->StartLba >> (1*8) );
    cdb->REPORT_KEY.LogicalBlockAddress[3] = (UCHAR)( input->StartLba >> (0*8) );
    cdb->AsByte[6] = (UCHAR)( input->NumberOfSectors );
    cdb->AsByte[7] = 0x02; // AACS key class
    cdb->REPORT_KEY.AllocationLength[0] = (UCHAR)(dataTransferLength >> (8*1));
    cdb->REPORT_KEY.AllocationLength[1] = (UCHAR)(dataTransferLength >> (8*0));
    cdb->REPORT_KEY.AGID = (UCHAR)( input->SessionId );
    cdb->REPORT_KEY.KeyFormat = 0x20; // Generate a new binding nonce

    Srb->CdbLength = 12;
    Srb->TimeOutValue = fdoExtension->TimeOutValue;
    Srb->SrbFlags = fdoExtension->SrbFlags;
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
    SET_FLAG(Srb->SrbFlags, SRB_FLAGS_DATA_IN);

    IoCallDriver(fdoExtension->CommonExtension.LowerDeviceObject, NewIrp);
    return;
}



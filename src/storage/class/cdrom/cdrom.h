/*++

Copyright (C) Microsoft Corporation, 1991 - 1999

Module Name:

    cdromp.h

Abstract:

    Private header file for cdrom.sys.  This contains private
    structure and function declarations as well as constant
    values which do not need to be exported.

Author:

Environment:

    kernel mode only

Notes:


Revision History:

--*/

#ifndef __CDROMP_H__
#define __CDROMP_H__

#include "ntddmmc.h"
#include "ntddcdvd.h"
#include "specstrings.h"

//
// This prototype is needed because, although NTIFS.H is now shipping with
// the WDK, I can't include both it and the other headers we already use.
//
#ifndef PsIsThreadTerminating
NTKERNELAPI
BOOLEAN
PsIsThreadTerminating(
    __in PETHREAD Thread
    );
#endif // PsIsThreadTerminating()

//
// Set component ID for DbgPrintEx calls
//
#ifndef DEBUG_COMP_ID
#define DEBUG_COMP_ID   DPFLTR_CDROM_ID
#endif

//
// Include header file and setup GUID for tracing
//
#include <storswtr.h>
#define WPP_GUID_CDROM          (A4196372, C3C4, 42d5, 87BF, 7EDB2E9BCC27)
#ifndef WPP_CONTROL_GUIDS
#define WPP_CONTROL_GUIDS   WPP_CONTROL_GUIDS_NORMAL_FLAGS(WPP_GUID_CDROM)
#endif

extern GUID ClassGuidSenseInfo2;
extern GUID ClassGuidWorkingSet;
extern CLASSPNP_SCAN_FOR_SPECIAL_INFO CdromHackItems[];

#define CDROM_GET_CONFIGURATION_TIMEOUT    (0x4)

#define CDROM_HACK_DEC_RRD                 (0x00000001)
#define CDROM_HACK_FUJITSU_FMCD_10x        (0x00000002)
#define CDROM_HACK_HITACHI_1750            (0x00000004)
#define CDROM_HACK_HITACHI_GD_2000         (0x00000008)
#define CDROM_HACK_TOSHIBA_SD_W1101        (0x00000010)
#define CDROM_HACK_TOSHIBA_XM_3xx          (0x00000020)
//#define CDROM_HACK_NEC_CDDA                (0x00000040) -- obsolete
//#define CDROM_HACK_PLEXTOR_CDDA            (0x00000080) -- obsolete
#define CDROM_HACK_BAD_GET_CONFIG_SUPPORT  (0x00000100)
//#define CDROM_HACK_FORCE_READ_CD_DETECTION (0x00000200) -- obsolete
//#define CDROM_HACK_READ_CD_SUPPORTED       (0x00000400) -- obsolete
#define CDROM_HACK_BAD_TYPE_ONE_GET_CONFIG (0x00000800)
#define CDROM_HACK_BAD_VENDOR_PROFILES     (0x00001000)
#define CDROM_HACK_LOCKED_PAGES            (0x80000000) // not a valid flag to save

#define CDROM_HACK_VALID_FLAGS             (0x00001fff)
#define CDROM_HACK_INVALID_FLAGS           (~CDROM_HACK_VALID_FLAGS)


// A 64k buffer to be written takes the following amount of time:
//   1x    CD ==     75 sectors/sec == 0.4266667 seconds == 4266667 100ns units
//   4x    CD ==    300 sectors/sec == 0.1066667 seconds == 1066667 100ns units
//  10x    CD ==    300 sectors/sec == 0.0426667 seconds ==  426667 100ns units
//   1x   DVD ==    676 sectors/sec == 0.0473373 seconds ==  473373 100ns units
//  16x   DVD == 10,816 sectors/sec == 0.0029586 seconds ==   29586 100ns units
//   1x HDDVD ==  2,230 sectors/sec == 0.0143498 seconds ==  143498 100ns units


#define WRITE_RETRY_DELAY_CD_1x    ((LONGLONG)4266667)
#define WRITE_RETRY_DELAY_CD_4x    ((LONGLONG)1066667)
#define WRITE_RETRY_DELAY_CD_10x   ((LONGLONG) 426667)
#define WRITE_RETRY_DELAY_DVD_1x   ((LONGLONG) 473373)
#define WRITE_RETRY_DELAY_DVD_4x   ((LONGLONG) 118343)
#define WRITE_RETRY_DELAY_DVD_16x  ((LONGLONG)  29586)
#define WRITE_RETRY_DELAY_HDDVD_1x ((LONGLONG) 143498)

typedef struct _ERROR_RECOVERY_DATA {
    MODE_PARAMETER_HEADER   Header;
    MODE_PARAMETER_BLOCK BlockDescriptor;
    MODE_READ_RECOVERY_PAGE ReadRecoveryPage;
} ERROR_RECOVERY_DATA, *PERROR_RECOVERY_DATA;

//
// CdRom specific addition to device extension.
//

typedef struct _CDROM_DRIVER_EXTENSION {
    ULONG InterlockedCdRomCounter;
    PVOID Reserved[3];
} CDROM_DRIVER_EXTENSION, *PCDROM_DRIVER_EXTENSION;

#define CdromMmcUpdateComplete 0
#define CdromMmcUpdateRequired 1
#define CdromMmcUpdateStarted  2

typedef struct _CDROM_MMC_EXTENSION {

    ULONG        IsMmc;        // allow quick checks
    ULONG        IsAACS;
    ULONG        IsWriter;      //the drive is a writer or not
    ULONG        WriteAllowed;  //allow write request or not

    //
    // The feature number  defines the  level  and form  of
    // validation that needs to be performed on Io requests
    //

    FEATURE_NUMBER ValidationSchema;
    ULONG Blocking;

    LONG UpdateState;

    LIST_ENTRY DelayedIrpsList;
    ULONG NumDelayedIrps;
    KSPIN_LOCK DelayedIrpsLock;

    PIO_WORKITEM              CapabilitiesWorkItem;
    PIRP                      CapabilitiesIrp;
    PMDL                      CapabilitiesMdl;
    PGET_CONFIGURATION_HEADER CapabilitiesBuffer;
    ULONG                     CapabilitiesBufferSize;
    KEVENT                    CapabilitiesEvent;
    SCSI_REQUEST_BLOCK        CapabilitiesSrb;

    BOOLEAN ReadCdC2Pointers;
    BOOLEAN ReadCdSubCode;

} CDROM_MMC_EXTENSION, *PCDROM_MMC_EXTENSION;


#define CDROM_DRIVER_EXTENSION_ID CdRomAddDevice

typedef struct _CDROM_DATA {

    //
    // Pointer to the cdrom driver extension
    //

    PCDROM_DRIVER_EXTENSION DriverExtension;


    //
    // These bits allow detection of when to requery the
    // drive's capabilities.
    //

    CDROM_MMC_EXTENSION Mmc;

    //
    // hack flags for ScanForSpecial routines
    //

    ULONG_PTR HackFlags;

    //
    // the error handling routines need to be per-device,
    // not per-driver....
    //

    PCLASS_ERROR ErrorHandler;

    //
    // Indicates whether an audio play operation
    // is currently being performed.
    // Only thing this does is prevent reads and
    // toc requests while playing audio.
    //

    BOOLEAN PlayActive;

    //
    // This points to an irp which needs to be delayed for a bit before a
    // retry can be attempted.  The interval counter is set by the deferring
    // routine and will be decremented to zero in the tick handler.  Once
    // the counter goes to zero the irp will be issued again.
    // DelayedRetryResend controls whether the irp is resent to the lower
    // driver (TRUE) or reissued into the startio routine (FALSE)
    //

    BOOLEAN DelayedRetryResend;

    PIRP DelayedRetryIrp;

    ULONG DelayedRetryInterval;

    KSPIN_LOCK DelayedRetrySpinLock;

    //
    // indicate we need to pick a default dvd region
    // for the user if we can
    //

    ULONG PickDvdRegion;

    //
    // The interface strings registered for this device.
    //

    UNICODE_STRING CdromInterfaceString;
    UNICODE_STRING VolumeInterfaceString;

    //
    // The well known name link for this device.
    //

    UNICODE_STRING WellKnownName;

#ifdef ENABLE_RPC0
    //
    // keep track of what type of DVD device we are
    //

    BOOLEAN DvdRpc0Device;
    BOOLEAN DvdRpc0LicenseFailure;
    UCHAR   Rpc0SystemRegion;           // bitmask, one means prevent play
    UCHAR   Rpc0SystemRegionResetCount;
    ULONG   Rpc0RetryRegistryCallback;   // one until initial region choosen
    KMUTEX  Rpc0RegionMutex;
#endif // ENABLE_RPC0

    //
    // We need to distinguish between the two...
    //

    ULONG MaxPageAlignedTransferBytes;
    ULONG MaxUnalignedTransferBytes;

    //
    // Indicates that this is a DEC RRD cdrom.
    // This drive requires software to fix responses
    // from the faulty firmware
    //

    BOOLEAN IsDecRrd;

    //
    // Storage for the error recovery page. This is used
    // as the method to switch block sizes for some drive-specific
    // error recovery routines.
    //

    ERROR_RECOVERY_DATA recoveryData;

    //
    // Indicates that the device is in exclusive mode and only
    // the requests from the exclusive owner will be processed.
    //

    PFILE_OBJECT ExclusiveOwner;

    //
    // Caller name of the owner, if the device is
    // in exclusive mode.
    //

    UCHAR CallerName[CDROM_EXCLUSIVE_CALLER_LENGTH];

    //
    // Indicates that the device speed should be set to
    // default value on the next media change.
    //

    BOOLEAN RestoreDefaults;

    //
    // Many commands get double-buffered.  Since the max
    // transfer size is typically 64k, most of these requests
    // can be handled with a single pre-allocated buffer.
    // AACS support depends upon this buffer being available.
    // Unfortunately, the mix with CLASSPNP prevents effective
    // use of these buffers because CLASSPNP free's buffers
    // on behalf of CDROM.... :(
    //

    __field_range(4*1024, 64*1024)       ULONG   ScratchBufferSize; // 0x1000..0x10000 (4k..64k)
    __field_bcount(ScratchBufferSize)    PVOID   ScratchBuffer;     // used to get data for clients
    PMDL    ScratchBufferMdl;  // used to get data for clients

    //
    // This irp/srb can really only be used when serialized
    // (i.e. StartIO) _AND_ when CLASSPNP will not free
    // the irp.  The most obvious case is when updating
    // the MMC capabilities.  Use of the existing IRP was
    // avoided only to avoid breaking code that presumed
    // that irp was partially setup in any way.  Users of
    // the ScratchIrp shall not presume any state in the
    // Irp.
    //

    PIRP                 ScratchIrp;
    PSRB_HISTORY         ScratchHistory;
    PSCSI_REQUEST_BLOCK  ScratchSrb;
    PSENSE_DATA          ScratchSense;
    KEVENT               ScratchEvent;

    //
    // For debugging, set/clear this field when using
    // the scratch buffers/irps
    //

    PVOID ScratchInUse;
    __nullterminated CHAR const *
          ScratchInUseFileName;
    ULONG ScratchInUseLineNumber;


    //
    // How long to wait between retries if a READ/WRITE irp
    // gets a LWIP (2/4/7, 2/4/8)?
    //

    LONGLONG ReadWriteRetryDelay100nsUnits;
    
    //
    // Cached Device Type information. Maybe FILE_DEVICE_CD_ROM or FILE_DEVICE_DVD
    // CommonExtension.DevInfo->DeviceType maybe FILE_DEVICE_CD_ROM when this field is FILE_DEVICE_DVD
    //
    DEVICE_TYPE  DriveDeviceType;

    __field_bcount(CachedInquiryDataByteCount)
    PINQUIRYDATA CachedInquiryData;
    ULONG        CachedInquiryDataByteCount;

    //
    //This is only a place to remember the UpdateCapacityIrp. 
    //So we could use it to check when the device is going to be removed, 
    //if "DelayedRetryIrp" is UpdateCapacityIrp, it should not be completed as it's not sent out yet.
    //
    PIRP                 UpdateCapacityIrp;

} CDROM_DATA, *PCDROM_DATA;



#define DEVICE_EXTENSION_SIZE sizeof(FUNCTIONAL_DEVICE_EXTENSION) + sizeof(CDROM_DATA)
#define SCSI_CDROM_TIMEOUT          10
#define SCSI_CHANGER_BONUS_TIMEOUT  10
#define HITACHI_MODE_DATA_SIZE      12
#define MODE_DATA_SIZE              64
#define RAW_SECTOR_SIZE           2352
#define COOKED_SECTOR_SIZE        2048
#define CDROM_SRB_LIST_SIZE          4

#define PLAY_ACTIVE(x) (((PCDROM_DATA)(x->CommonExtension.DriverData))->PlayActive)

#define MSF_TO_LBA(Minutes,Seconds,Frames) \
                (ULONG)((60 * 75 * (Minutes)) + (75 * (Seconds)) + ((Frames) - 150))

#define DEC_TO_BCD(x) (((x / 10) << 4) + (x % 10))

//
// Sector types for READ_CD
//

#define ANY_SECTOR                0
#define CD_DA_SECTOR              1
#define YELLOW_MODE1_SECTOR       2
#define YELLOW_MODE2_SECTOR       3
#define FORM2_MODE1_SECTOR        4
#define FORM2_MODE2_SECTOR        5

#define MAX_COPY_PROTECT_AGID     4

#ifdef ExAllocatePool
#undef ExAllocatePool
#define ExAllocatePool #assert(FALSE)
#endif

#define CDROM_TAG_GET_CONFIG    'cCcS'  // "ScCc" - ioctl GET_CONFIGURATION
#define CDROM_TAG_DC_EVENT      'ECcS'  // "ScCE" - device control synch event
#define CDROM_TAG_FEATURE       'FCcS'  // "ScCF" - allocated by CdRomGetConfiguration(), free'd by caller
#define CDROM_TAG_DISK_GEOM     'GCcS'  // "ScCG" - disk geometry buffer
#define CDROM_TAG_HITACHI_ERROR 'HCcS'  // "ScCH" - hitachi error buffer
#define CDROM_TAG_SENSE_INFO    'ICcS'  // "ScCI" - sense info buffers
#define CDROM_TAG_POWER_IRP     'iCcS'  // "ScCi" - irp for power request
#define CDROM_TAG_SRB           'SCcS'  // "ScCS" - srb allocation
#define CDROM_TAG_STRINGS       'sCcS'  // "ScCs" - assorted string data
#define CDROM_TAG_MODE_DATA     'MCcS'  // "ScCM" - mode data buffer
#define CDROM_TAG_READ_CAP      'PCcS'  // "ScCP" - read capacity buffer
#define CDROM_TAG_PLAY_ACTIVE   'pCcS'  // "ScCp" - play active checks
#define CDROM_TAG_SUB_Q         'QCcS'  // "ScCQ" - read sub q buffer
#define CDROM_TAG_RAW           'RCcS'  // "ScCR" - raw mode read buffer
#define CDROM_TAG_TOC           'TCcS'  // "ScCT" - read toc buffer
#define CDROM_TAG_TOSHIBA_ERROR 'tCcS'  // "ScCt" - toshiba error buffer
#define CDROM_TAG_DEC_ERROR     'dCcS'  // "ScCt" - DEC error buffer
#define CDROM_TAG_UPDATE_CAP    'UCcS'  // "ScCU" - update capacity path
#define CDROM_TAG_VOLUME        'VCcS'  // "ScCV" - volume control buffer
#define CDROM_TAG_VOLUME_INT    'vCcS'  // "ScCv" - volume control buffer
#define CDROM_TAG_SCRATCH       'cScS'  // "ScSc" - Scratch buffer (usually 64k)
#define CDROM_TAG_INQUIRY       'nIcS'  // "ScIn" - Cached inquiry buffer

#define DVD_TAG_READ_STRUCTURE  'SVcS'  // "ScVS" - used for dvd structure reads
#define DVD_TAG_READ_KEY        'kVcS'  // "ScVk" - read buffer for dvd key
#define DVD_TAG_SEND_KEY        'KVcS'  // "ScVK" - write buffer for dvd key
#define DVD_TAG_RPC2_CHECK      'sVcS'  // "ScVs" - read buffer for dvd/rpc2 check
#define DVD_TAG_DVD_REGION      'tVcS'  // "ScVt" - read buffer for rpc2 check
#define DVD_TAG_SECURITY        'XVcS'  // "ScVX" - security descriptor

#define AACS_TAG_MKB            'kMcS'  // "ScMk" - Media Key Block
#define AACS_TAG_CERT           'rCcS'  // "ScCr" - Host or Drive Certificate
#define AACS_TAG_CHALLENGE      'hCcS'  // "ScCh" - Challenge key
//
// Tag definition for Scsi Cdrom Ioctl (SCIx)
//
#define CDROM_TAG_STREAM        '0ICS'  // "SCI0" - set stream buffer


#define CDROM_SUBKEY_NAME        (L"CdRom")  // store new settings here
#define CDROM_READ_CD_NAME       (L"ReadCD") // READ_CD support previously detected
#define CDROM_NON_MMC_DRIVE_NAME (L"NonMmc") // MMC commands hang
#define CDROM_TYPE_ONE_GET_CONFIG_NAME (L"NoTypeOneGetConfig") // Type One Get Config commands not supported
#define CDROM_NON_MMC_VENDOR_SPECIFIC_PROFILE (L"NonMmcVendorSpecificProfile") // GET_CONFIG returns vendor specific header
                                                                               // profiles that are not per spec
                                                                               // (length divisible by 4)
//
// DVD Registry Value Names for RPC0 Device
//
#define DVD_DEFAULT_REGION       (L"DefaultDvdRegion")    // this is init. by the dvd class installer
#define DVD_CURRENT_REGION       (L"DvdR")
#define DVD_REGION_RESET_COUNT   (L"DvdRCnt")
#define DVD_MAX_REGION_RESET_COUNT  2
#define DVD_MAX_REGION              8

//
// AACS defines
//
#define AACS_MKB_PACK_SIZE 0x8000 // does not include header


/*++

Routine Description:

    This routine grabs an extra remove lock using a local variable
    for a unique tag.  It then completes the irp in question, and
    the just-acquired removelock guarantees that it is still safe
    to call IoStartNextPacket().  When that finishes, we release
    the newly acquired RemoveLock and return.

Arguments:

    DeviceObject - the device object for the StartIo queue
    Irp - the request we are completing

Return Value:

    None

Notes:

    This is implemented as an inline function to allow the compiler
    to optimize this as either a function call or as actual inline code.

    This routine will not work with IoXxxRemoveLock() calls, as the
    behavior is different.  ClassXxxRemoveLock() calls succeed until
    the remove has completed, while IoXxxRemoveLock() calls fail as
    soon as the call to IoReleaseRemoveLockAndWait() has been called.
    The Class version allows this routine to work in a safe manner.

    replaces the following two lines:
        IoStartNextPacket(DeviceObject, TRUE);
        ClassReleaseRemoveLock(DeviceObject, Irp);
    and raises irql as needed to call IoStartNextPacket()

--*/
__inline
VOID
CdRomCompleteIrpAndStartNextPacketSafely(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    )
{
    UCHAR uniqueAddress;
    KIRQL oldIrql = KeGetCurrentIrql();

    ClassAcquireRemoveLock(DeviceObject, (PIRP)&uniqueAddress);
    ClassReleaseRemoveLock(DeviceObject, Irp);
    ClassCompleteRequest(DeviceObject, Irp, IO_CD_ROM_INCREMENT);

    if (oldIrql > DISPATCH_LEVEL) {
        ASSERT(!"Cannot call IoStartNextPacket at raised IRQL!");
    } else if (oldIrql < DISPATCH_LEVEL) {
        KeRaiseIrqlToDpcLevel();
    } else { //  (oldIrql == DISPATCH_LEVEL)
        NOTHING;
    }

    IoStartNextPacket(DeviceObject, TRUE);

    if (oldIrql > DISPATCH_LEVEL) {
        ASSERT(!"Cannot call IoStartNextPacket at raised IRQL!");
    } else if (oldIrql < DISPATCH_LEVEL) {
        KeLowerIrql(oldIrql);
    } else { //  (oldIrql == DISPATCH_LEVEL)
        NOTHING;
    }

    ClassReleaseRemoveLock(DeviceObject, (PIRP)&uniqueAddress);


    return;
}

__inline
BOOLEAN
ValidChar(UCHAR Ch)
{
    if (((Ch >= '0') && (Ch <= '9')) ||
        (((Ch|0x20) >= 'a') && ((Ch|0x20) <= 'z')) ||
        (strchr(" .,:;_-", Ch) != NULL)) {
        return TRUE;
    }
    return FALSE;
}

#define EXCLUSIVE_MODE(_CdData)                 (_CdData->ExclusiveOwner != NULL)
#define EXCLUSIVE_OWNER(_CdData, _FileObject)   (_CdData->ExclusiveOwner == _FileObject)


VOID
CdRomDeviceControlDvdReadStructure(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
CdRomDeviceControlDvdEndSession(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
CdRomDeviceControlDvdStartSessionReadKey(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
CdRomDeviceControlDvdSendKey(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );



NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    );

__control_entrypoint(DeviceDriver)
VOID
CdRomUnload(
    IN PDRIVER_OBJECT DriverObject
    );

__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomAddDevice(
    IN PDRIVER_OBJECT DriverObject,
    IN PDEVICE_OBJECT Pdo
    );

NTSTATUS
CdRomOpenClose(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    );

__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomReadWriteVerification(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    );

NTSTATUS
CdRomSwitchMode(
    IN PDEVICE_OBJECT DeviceObject,
    IN ULONG SectorSize,
    IN PIRP  OriginalRequest
    );

__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomDeviceControlDispatch(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    );

NTSTATUS
CdRomDeviceControlCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    );

NTSTATUS
CdRomSetVolumeIntermediateCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    );

NTSTATUS
CdRomXACompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    );

NTSTATUS
CdRomClassIoctlCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    );

__control_entrypoint(DeviceDriver)
VOID
CdRomStartIo(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    );

__control_entrypoint(DeviceDriver)
VOID
CdRomTickHandler(
    IN PDEVICE_OBJECT DeviceObject
    );

NTSTATUS
CdRomUpdateCapacity(
    IN PFUNCTIONAL_DEVICE_EXTENSION DeviceExtension,
    IN PIRP IrpToComplete,
    IN OPTIONAL PKEVENT IoctlEvent
    );

NTSTATUS
CdRomCreateDeviceObject(
    IN PDRIVER_OBJECT DriverObject,
    IN PDEVICE_OBJECT Pdo
    );

VOID
ScanForSpecialHandler(
    PFUNCTIONAL_DEVICE_EXTENSION FdoExtension,
    ULONG_PTR HackFlags
    );

VOID
ScanForSpecial(
    PDEVICE_OBJECT DeviceObject
    );

BOOLEAN
CdRomIsPlayActive(
    IN PDEVICE_OBJECT DeviceObject
    );

__control_entrypoint(DeviceDriver)
VOID
CdRomErrorHandler(
    PDEVICE_OBJECT DeviceObject,
    PSCSI_REQUEST_BLOCK Srb,
    NTSTATUS *Status,
    BOOLEAN *Retry
    );

VOID
HitachiProcessErrorGD2000(
    PDEVICE_OBJECT DeviceObject,
    PSCSI_REQUEST_BLOCK Srb,
    NTSTATUS *Status,
    BOOLEAN *Retry
    );

VOID
HitachiProcessError(
    PDEVICE_OBJECT DeviceObject,
    PSCSI_REQUEST_BLOCK Srb,
    NTSTATUS *Status,
    BOOLEAN *Retry
    );

VOID
ToshibaProcessError(
    PDEVICE_OBJECT DeviceObject,
    PSCSI_REQUEST_BLOCK Srb,
    NTSTATUS *Status,
    BOOLEAN *Retry
    );

NTSTATUS
ToshibaProcessErrorCompletion(
    PDEVICE_OBJECT DeviceObject,
    PIRP Irp,
    PVOID Context
    );

VOID
CdRomCreateNamedEvent(
    IN PFUNCTIONAL_DEVICE_EXTENSION DeviceExtension,
    IN ULONG DeviceNumber
    );

__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomInitDevice(
    IN PDEVICE_OBJECT Fdo
    );

__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomStartDevice(
    IN PDEVICE_OBJECT Fdo
    );

__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomStopDevice(
    IN PDEVICE_OBJECT DeviceObject,
    IN UCHAR Type
    );

__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomRemoveDevice(
    IN PDEVICE_OBJECT DeviceObject,
    IN UCHAR Type
    );

NTSTATUS
CdRomDvdEndAllSessionsCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    );

NTSTATUS
CdRomDvdReadDiskKeyCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    );

NTSTATUS
CdRomCreateWellKnownName(
    IN PDEVICE_OBJECT DeviceObject
    );

VOID
CdRomDeleteWellKnownName(
    IN PDEVICE_OBJECT DeviceObject
    );

NTSTATUS
CdRomGetDeviceParameter (
    IN PDEVICE_OBJECT DeviceObject,
    __in IN PWSTR ParameterName,
    IN OUT PULONG ParameterValue
    );

NTSTATUS
CdRomSetDeviceParameter (
    IN PDEVICE_OBJECT DeviceObject,
    __in IN PWSTR ParameterName,
    IN ULONG ParameterValue
    );

VOID
CdRomPickDvdRegion (
    IN PDEVICE_OBJECT Fdo
);

NTSTATUS
CdRomRetryRequest(
    IN PFUNCTIONAL_DEVICE_EXTENSION FdoExtension,
    IN PIRP Irp,
    IN ULONG Delay,
    IN BOOLEAN ResendIrp
    );

NTSTATUS
CdRomRerunRequest(
    IN PFUNCTIONAL_DEVICE_EXTENSION FdoExtension,
    IN OPTIONAL PIRP Irp,
    IN BOOLEAN ResendIrp
    );

NTSTATUS
CdRomGetRpc0Settings(
    IN PDEVICE_OBJECT Fdo
    );

#ifdef ENABLE_RPC0
NTSTATUS
CdRomSetRpc0Settings(
    IN PDEVICE_OBJECT Fdo,
    IN UCHAR NewRegion
    );
#endif // ENABLE_RPC0

__control_entrypoint(DeviceDriver)
NTSTATUS
CdRomShutdownFlush(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    );

NTSTATUS
CdRomSetRawReadInfo(
    PDEVICE_OBJECT Fdo
    );

////////////////////////////////////////////////////////////////////////////////

VOID
CdRomIsDeviceMmcDevice(
    __in PDEVICE_OBJECT Fdo,
    __out PBOOLEAN IsMmc,
    __out PBOOLEAN IsAACS,
    __out PBOOLEAN IsDvdDevice,
    __out PBOOLEAN IsWriterDrive
    );

NTSTATUS
CdRomMmcErrorHandler(
    IN PDEVICE_OBJECT Fdo,
    IN PSCSI_REQUEST_BLOCK Srb,
    OUT PNTSTATUS Status,
    OUT PBOOLEAN Retry
    );

PVOID
CdRomFindFeaturePage(
    __in_bcount(Length) PGET_CONFIGURATION_HEADER FeatureBuffer,
    ULONG const Length,
    FEATURE_NUMBER const Feature
    );

NTSTATUS
CdRomGetConfiguration(
    __in  PDEVICE_OBJECT Fdo,
    __deref_out_bcount_full(*BytesReturned)  // this routine allocates this memory
          PGET_CONFIGURATION_HEADER *Buffer, // this routine allocates this memory
    __out PULONG BytesReturned,
          FEATURE_NUMBER const StartingFeature,
          ULONG const RequestedType
    );

VOID
CdRomUpdateMmcDriveCapabilities(
    __in PDEVICE_OBJECT Fdo,
    __reserved PVOID Context
    );

VOID
CdRomUpdateTimeoutValueForMmcDevice(
    __in PDEVICE_OBJECT Fdo
    );

VOID
CdRomFindProfileInProfiles(
    __in  FEATURE_DATA_PROFILE_LIST const * ProfileHeader,
          FEATURE_PROFILE_TYPE const ProfileToFind,
          BOOLEAN const CurrentOnly,
    __out PBOOLEAN Found
    );

NTSTATUS
CdRomAllocateMmcResources(
    __in PDEVICE_OBJECT Fdo
    );

VOID
CdRomDeAllocateMmcResources(
    __in PDEVICE_OBJECT Fdo
    );

VOID
CdromFakePartitionInfo(
    IN PCOMMON_DEVICE_EXTENSION CommonExtension,
    IN PIRP Irp
    );

VOID
CdRomInterpretReadCapacity(
    IN PDEVICE_OBJECT Fdo,
    IN PREAD_CAPACITY_DATA ReadCapacityBuffer
    );

NTSTATUS
CdRomShutdownFlushCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    );

VOID
CdRompFlushDelayedList(
    __in PDEVICE_OBJECT Fdo,
    __in PCDROM_MMC_EXTENSION MmcData,
         NTSTATUS Status,
         BOOLEAN const CalledFromWorkItem
    );

NTSTATUS
CdRomPowerHandler(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    );

NTSTATUS
CdRomGetConfigCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    );

NTSTATUS
CdRomCreateClose(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP Irp
    );

NTSTATUS
CdRomDeviceControlExclusiveAccess(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP Irp
    );

NTSTATUS
CdRomQueryLockState(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP Irp
    );

NTSTATUS
CdRomLockDevice(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP Irp
    );

NTSTATUS
CdRomUnlockDevice(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP Irp
    );

BOOLEAN
CdRomIsBlockedStorageIoctl(
    IN PIRP Irp
    );

PVOID
CdRomAllocateDataBuffer(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb,
    IN ULONG TransferLength,
    IN ULONG Tag
    );

VOID
CdRomSetSpeed(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
CdRomRestoreDefaultSpeed(
    IN PDEVICE_OBJECT Fdo,
    IN PIO_WORKITEM WorkItem
    );


NTSTATUS
ResendIoctlForSplitCdb(
    __in PDEVICE_OBJECT DeviceObject,
    __inout PIRP OriginalIrp,
    __inout PIRP ReuseIrp,
    __inout PSCSI_REQUEST_BLOCK Srb,
    __in ULONG DataTransferLength
    );


VOID
CdRomCancelFromStartIO(
    __in PDEVICE_OBJECT DeviceObject,
    __in PIRP Irp
    );

NTSTATUS
CdRomSynchronizeIoctlWithStartIo(
    __in PDEVICE_OBJECT DeviceObject,
    __in PIRP Irp,
    __in PDRIVER_DISPATCH IoctlHandlerWhenSynchronized  // NOTE: NOT CALLED IF IRP IS CANCELLED!
    );

BOOLEAN
InterpretSenseInfo2(
    __in  PDEVICE_OBJECT Fdo,
    __in_opt PIRP OriginalRequest,
    __in  PSCSI_REQUEST_BLOCK Srb,
          UCHAR MajorFunctionCode,
          ULONG IoDeviceCode,
          ULONG PreviousRetryCount,
    // const except for bits explicitly set aside for class driver to update
    __in_opt SRB_HISTORY * RequestHistory,
    __out NTSTATUS * Status,
    __out __range(0,MAXIMUM_RETRY_FOR_SINGLE_IO_IN_100NS_UNITS)
    LONGLONG * RetryIn100nsUnits
    );

VOID
CompressSrbHistoryData(
    __in     PDEVICE_OBJECT DeviceObject,
    __inout  PSRB_HISTORY   RequestHistory
    );

VOID
ScratchBuffer_Deallocate(
    __in PCDROM_DATA CdData
    );

BOOLEAN
ScratchBuffer_Allocate(
    __in PCDROM_DATA CdData,
    __in CCHAR IrpStackSizeRequired
    );

VOID
ScratchBuffer_ResetItems(
    __in PCDROM_DATA CdData,
    BOOLEAN ResetRequestHistory
    );

#if DBG
    #define ScratchBuffer_BeginUse(cdData) ScratchBuffer_BeginUseX((cdData), __FILE__, __LINE__)
#else
    #define ScratchBuffer_BeginUse(cdData) ScratchBuffer_BeginUseX((cdData), NULL, -1)
#endif

__inline VOID ScratchBuffer_BeginUseX(__inout PCDROM_DATA CdData, __in UCHAR const * File, ULONG Line)
{
    // NOTE: these are not "real" locks.  They are simply to help
    //       avoid multiple uses of the scratch buffer. Thus, it
    //       is not critical to have atomic operations here.
    PVOID tmp = InterlockedCompareExchangePointer(&(CdData->ScratchInUse), (PVOID)-1, 0);
    ASSERT(tmp == 0);
    CdData->ScratchInUseFileName = File;
    CdData->ScratchInUseLineNumber = Line;
    ScratchBuffer_ResetItems(CdData,  TRUE);
    return;
}
__inline VOID ScratchBuffer_EndUse(__inout PCDROM_DATA CdData)
{
    // NOTE: these are not "real" locks.  They are simply to help
    //       avoid multiple uses of the scratch buffer.  Thus, it
    //       is not critical to have atomic operations here.
    PVOID tmp = InterlockedCompareExchangePointer(&(CdData->ScratchInUse), 0, (PVOID)-1);
    ASSERT(tmp == ((PVOID)-1));
    CdData->ScratchInUseFileName = NULL;
    CdData->ScratchInUseLineNumber = 0;
    return;
}

__inline __range(0,MAXIMUM_RETRY_FOR_SINGLE_IO_IN_100NS_UNITS)
LONGLONG
ConvertSectorsPerSecondTo100nsUnitsFor64kWrite(
    __range(1,0xFFFFFFFF) ULONG SectorsPerSecond // zero would cause divide-by-zero
    )
{
    //     64k write 
    // ---------------- == time per 64k write
    //  sectors/second
    //
    //  (32 / N) == seconds
    //  (32 / N) * (1,000,000,000) == nanoseconds
    //  (32 / N) * (1,000,000,000) / 100 == 100ns increments
    //  (32 * 10,000,000) / N == 100ns increments
    //
    //  320,000,000 / N == 100ns increments
    //  And this is safe to run in kernel-mode (no floats)
    //

    // this assert ensures that we _never_ can return a value
    // larger than the maximum allowed.
    C_ASSERT(320000000 < MAXIMUM_RETRY_FOR_SINGLE_IO_IN_100NS_UNITS);

    return 320000000 / SectorsPerSecond;
}

BOOLEAN
ScratchBuffer_InterpretSrbError(
    __in PFUNCTIONAL_DEVICE_EXTENSION FdoExtension,
    __in ULONG TimesAlreadyRetried,
    __out NTSTATUS * Status,
    __out __range(0,MAXIMUM_RETRY_FOR_SINGLE_IO_IN_100NS_UNITS)
    LONGLONG * RetryIn100nsUnits
    );

VOID
ScratchBuffer_SetupForSynchronousSrb(
    __in PFUNCTIONAL_DEVICE_EXTENSION FdoExtension,
    __in ULONG MaximumTransferLength,
    BOOLEAN GetDataFromDevice
    );

VOID
ScratchBuffer_SendSynchronousSrb(
    __in PFUNCTIONAL_DEVICE_EXTENSION FdoExtension
    );

VOID
ScratchBuffer_SendSynchronousSrbWithRetries(
    __in PFUNCTIONAL_DEVICE_EXTENSION FdoExtension
    );


__range(-1,MAXIMUM_RETRY_FOR_SINGLE_IO_IN_100NS_UNITS)
LONGLONG
CdRompRetryTimeGuessBasedOnProfile(
    FEATURE_PROFILE_TYPE const Profile
    );

__range(-1,MAXIMUM_RETRY_FOR_SINGLE_IO_IN_100NS_UNITS)
LONGLONG
CdRompRetryTimeDetectionBasedOnModePage2A(
    __in PDEVICE_OBJECT Fdo
    );

__range(-1,MAXIMUM_RETRY_FOR_SINGLE_IO_IN_100NS_UNITS)
LONGLONG
CdRompRetryTimeDetectionBasedOnGetPerformance(
    __in PDEVICE_OBJECT Fdo,
    BOOLEAN UseLegacyNominalPerformance
    );

NTSTATUS
CdRompSendSrbSynchronousCompletion(
    __in_opt PDEVICE_OBJECT DeviceObject,
    __in PIRP Irp,
    __in PKEVENT Context
    );

NTSTATUS
CdRompCacheDeviceInquiryData(
    __in PFUNCTIONAL_DEVICE_EXTENSION FdoExtension
    );

BOOLEAN
IsDeviceAACSCapable(
    __in PDEVICE_OBJECT DeviceObject
    );

VOID
UnimplementedAACSFunction(
    IN PDEVICE_OBJECT Fdo,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
AacsGetMediaKeyBlock(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
AacsGetAgid(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
AacsReleaseAgid(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
AacsSendHostCertificate(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
AacsGetDriveCertificate(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
AacsGetChallengeKey(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
AacsSendChallengeKey(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
AacsReadVolumeID(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
AacsReadSerialNumber(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
AacsReadMediaID(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
AacsReadBindingNonce(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );

VOID
AacsGenerateBindingNonce(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP OriginalIrp,
    IN PIRP NewIrp,
    IN PSCSI_REQUEST_BLOCK Srb
    );


#ifndef SIZEOF_ARRAY
    #define SIZEOF_ARRAY(ar)        (sizeof(ar)/sizeof((ar)[0]))
#endif // !defined(SIZEOF_ARRAY)


#endif // __CDROMP_H__



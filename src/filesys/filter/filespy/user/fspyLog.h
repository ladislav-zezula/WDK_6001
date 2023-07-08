/*++

Copyright (c) 1989-1999  Microsoft Corporation

Module Name:

    log.h

Abstract:

    This module contains the structures and prototypes used by the user
    program to retrieve and see the log records recorded by filespy.sys.

Environment:

    User mode


--*/
#ifndef __FSPYLOG_H__
#define __FSPYLOG_H__

#include <stdio.h>
#include "filespy.h"

#define BUFFER_SIZE     8192

typedef struct _LOG_CONTEXT{
    HANDLE  Device;
    BOOLEAN LogToScreen;
    BOOLEAN LogToFile;
    ULONG   VerbosityFlags;     //  FS_VF_DUMP_PARAMETERS, etc.
    FILE   *OutputFile;

    BOOLEAN NextLogToScreen;

    // For synchronizing shutting down of both threads
    BOOLEAN CleaningUp;
    HANDLE  ShutDown;
}LOG_CONTEXT, *PLOG_CONTEXT;

DWORD WINAPI
RetrieveLogRecords (
    __in LPVOID lpParameter
    );

VOID
IrpFileDump (
    __in ULONG SequenceNumber,
    __in PWCHAR Name,
    __in ULONG NameLength,
    __in PRECORD_IRP RecordIrp,
    __in FILE *File,
    __in ULONG Verbosity
    );

VOID
IrpScreenDump (
    __in ULONG SequenceNumber,
    __in PWCHAR Name,
    __in ULONG NameLength,
    __in PRECORD_IRP RecordIrp,
    __in ULONG Verbosity
    );

VOID
FastIoFileDump (
    __in ULONG SequenceNumber,
    __in PWCHAR Name,
    __in ULONG NameLength,
    __in PRECORD_FASTIO RecordFastIo,
    __in FILE *File
    );

VOID
FastIoScreenDump (
    __in ULONG SequenceNumber,
    __in PWCHAR Name,
    __in ULONG NameLength,
    __in PRECORD_FASTIO RecordFastIo
    );

#if WINVER >= 0x0501 /* See comment in DriverEntry */

VOID
FsFilterOperationFileDump (
    __in ULONG SequenceNumber,
    __in PWCHAR Name,
    __in ULONG NameLength,
    __in PRECORD_FS_FILTER_OPERATION RecordFsFilterOp,
    __in FILE *File
    );

VOID
FsFilterOperationScreenDump (
    __in ULONG SequenceNumber,
    __in PWCHAR Name,
    __in ULONG NameLength,
    __in PRECORD_FS_FILTER_OPERATION RecordFsFilterOp
    );

#endif

#if WINVER >= 0x0600

VOID
TxNotifyFileDump (
    __in ULONG SequenceNumber,
    __in PWCHAR Name,
    __in ULONG NameLength,
    __in PRECORED_TRANSACTION pRecordTx,
    __in FILE *File
);

VOID
TxNotifyScreenDump (
    __in ULONG SequenceNumber,
    __in PWCHAR Name,
    __in ULONG NameLength,
    __in PRECORED_TRANSACTION pRecordTx
);

#endif

#define IRP_NOCACHE                     0x00000001
#define IRP_PAGING_IO                   0x00000002
#define IRP_SYNCHRONOUS_API             0x00000004
#define IRP_SYNCHRONOUS_PAGING_IO       0x00000040

#if WINVER >= 0x0501
#define FS_FILTER_ACQUIRE_FOR_SECTION_SYNCHRONIZATION    (UCHAR)-1
#define FS_FILTER_RELEASE_FOR_SECTION_SYNCHRONIZATION    (UCHAR)-2
#define FS_FILTER_ACQUIRE_FOR_MOD_WRITE                  (UCHAR)-3
#define FS_FILTER_RELEASE_FOR_MOD_WRITE                  (UCHAR)-4
#define FS_FILTER_ACQUIRE_FOR_CC_FLUSH                   (UCHAR)-5
#define FS_FILTER_RELEASE_FOR_CC_FLUSH                   (UCHAR)-6
#endif

//
//  Verbosity flags.
//

#define FS_VF_DUMP_PARAMETERS           0x00000001

#endif __FSPYLOG_H__


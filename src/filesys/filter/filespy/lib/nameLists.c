/*++

Copyright (c) 1989-1999  Microsoft Corporation

Module Name:

    irpNameList.c

Abstract:

    This module contains an array of unicode IRP names.


Environment:

    User mode


--*/

#include <ntifs.h>
#include "filespyLib.h"

//
//  List of unicode irp names
//

PWCHAR IrpNameList[IRP_MJ_MAXIMUM_FUNCTION+1] = 
{
    L"IRP_MJ_CREATE",
    L"IRP_MJ_CREATE_NAMED_PIPE",
    L"IRP_MJ_CLOSE",
    L"IRP_MJ_READ",
    L"IRP_MJ_WRITE",
    L"IRP_MJ_QUERY_INFORMATION",
    L"IRP_MJ_SET_INFORMATION",
    L"IRP_MJ_QUERY_EA",
    L"IRP_MJ_SET_EA",
    L"IRP_MJ_FLUSH_BUFFERS",
    L"IRP_MJ_QUERY_VOLUME_INFORMATION",
    L"IRP_MJ_SET_VOLUME_INFORMATION",
    L"IRP_MJ_DIRECTORY_CONTROL",
    L"IRP_MJ_FILE_SYSTEM_CONTROL",
    L"IRP_MJ_DEVICE_CONTROL",
    L"IRP_MJ_INTERNAL_DEVICE_CONTROL",
    L"IRP_MJ_SHUTDOWN",
    L"IRP_MJ_LOCK_CONTROL",
    L"IRP_MJ_CLEANUP",
    L"IRP_MJ_CREATE_MAILSLOT",
    L"IRP_MJ_QUERY_SECURITY",
    L"IRP_MJ_SET_SECURITY",
    L"IRP_MJ_POWER",
    L"IRP_MJ_SYSTEM_CONTROL",
    L"IRP_MJ_DEVICE_CHANGE",
    L"IRP_MJ_QUERY_QUOTA",
    L"IRP_MJ_SET_QUOTA",
    L"IRP_MJ_PNP"
};


PWCHAR FastIoNameList[FASTIO_MAX_OPERATION] =
{
    L"CHECK_IF_POSSIBLE",
    L"READ",
    L"WRITE",
    L"QUERY_BASIC_INFO",
    L"QUERY_STANDARD_INFO",
    L"LOCK",
    L"UNLOCK_SINGLE",
    L"UNLOCK_ALL",
    L"UNLOCK_ALL_BY_KEY",
    L"DEVICE_CONTROL",
    L"DETACH_DEVICE",
    L"QUERY_NETWORK_OPEN_INFO",
    L"MDL_READ",
    L"MDL_READ_COMPLETE",
    L"MDL_WRITE",
    L"MDL_WRITE_COMPLETE",
    L"READ_COMPRESSED",
    L"WRITE_COMPRESSED",
    L"MDL_READ_COMPLETE_COMPRESSED",
    L"PREPARE_MDL_WRITE",
    L"MDL_WRITE_COMPLETE_COMPRESSED",
    L"QUERY_OPEN_STRING",
};


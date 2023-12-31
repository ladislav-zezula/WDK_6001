/*++

Copyright (2) 2003 Microsoft Corporation

Module Name:

    kxagplib.h

Abstract:

    This module contains definitions for the AMD K8/9 AGP registers


--*/

#ifndef __KXAGPLIB_H__
#define __KXAGPLIB_H__

NTSTATUS
KxInitializeLib(
    VOID
    );

NTSTATUS
KxSetApertureBase(
    PHYSICAL_ADDRESS PhysAddr
    );

NTSTATUS
KxSetGartBase(
    PHYSICAL_ADDRESS PhysAddr
    );

NTSTATUS
KxSetApertureSize(
    ULONG Size
    );

NTSTATUS
KxGetApertureSize(
    PULONG Size
    );

NTSTATUS
KxSetApertureEnable(
    BOOLEAN ApEnable,
    BOOLEAN CPU_Enable,
    BOOLEAN IO_Enable
    );

NTSTATUS
KxInvalidateGartTLB(
    VOID
    );

VOID KxGetDriverAgpInfo(
    OUT PAGP_INFO_DRIVER AgpDriverInfo
    );

#endif // __KXAGPLIB_H__


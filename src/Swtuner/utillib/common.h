/**************************************************************************

    BDA/AVStream Simulated Hardware Sample

    Copyright (c) Microsoft Corporation.  All rights reserved.

    File:

        Common.h

    Abstract:

        Utility Code header file.  

    History:

        created 10/21/2004

**************************************************************************/

/*************************************************

    Standard Includes

*************************************************/

extern "C" {
#include <wdm.h>
}

#include <windef.h>
#include <ntstrsafe.h>
#include <stdio.h>
#include <stdlib.h>
#include <windef.h>
#define NOBITMAP
#include <mmreg.h>
#undef NOBITMAP
#include <unknown.h>
#include <ks.h>
#include <ksmedia.h>
#include <bdatypes.h>
#include <bdamedia.h>
#include <kcom.h>
/*
VOID
ParGetDriverParameterDword(
    IN     PUNICODE_STRING ServicePath,
    IN     PWSTR           ParameterName,
    IN OUT PULONG          ParameterValue
   );*/

NTSTATUS
PptRegGetDword(
    IN     ULONG   RelativeTo,
    IN     __nullterminated PWSTR   Path,
    IN     __nullterminated PWSTR   ParameterName,
    IN OUT PULONG  ParameterValue
    );

NTSTATUS
PptRegSetDword(
    IN  ULONG  RelativeTo,               
    IN  __nullterminated PWSTR  Path,
    IN  __nullterminated PWSTR  ParameterName,
    IN  PULONG ParameterValue
    );

NTSTATUS
PptRegGetSz(
    IN      ULONG  RelativeTo,               
    IN      __nullterminated PWSTR  Path,
    IN      __nullterminated PWSTR  ParameterName,
    IN OUT  PUNICODE_STRING ParameterValue
    );
/*
NTSTATUS
PptRegSetSz(
    IN  ULONG  RelativeTo,               
    IN  PWSTR  Path,
    IN  PWSTR  ParameterName,
    IN  PWSTR  ParameterValue
    );*/

NTSTATUS
PptRegGetDeviceParameterDword(
    IN     PDEVICE_OBJECT  Pdo,
    IN     __nullterminated PWSTR           ParameterName,
    IN OUT PULONG          ParameterValue
    );

NTSTATUS
PptRegSetDeviceParameterDword(
    IN PDEVICE_OBJECT  Pdo,
    IN __nullterminated PWSTR           ParameterName,
    IN PULONG          ParameterValue
    );

#pragma warning( push )
#pragma warning( disable : 4201 )
#include <ks.h>
#pragma warning( pop )

// {3CF32F0E-83FA-417e-B521-08503E1AA1D5}
#define STATIC_KSNAME_CaptureNodePropertySet\
    0x3cf32f0e, 0x83fa, 0x417e, 0xb5, 0x21, 0x8, 0x50, 0x3e, 0x1a, 0xa1, 0xd5
DEFINE_GUIDSTRUCT("3cf32f0e-83fa-417e-B521-08503E1AA1D5", KSNAME_CaptureNodePropertySet);
#define KSNAME_CaptureNodePropertySet DEFINE_GUIDNAMED(KSNAME_CaptureNodePropertySet)

typedef enum
{
    KSPROPERTY_CAPTURENODE_SETFREQ,
    KSPROPERTY_CAPTURENODE_SETFILENAME
} KSPROPERTY_CAPTURENODE;

typedef struct {
    KSPROPERTY Property;
    ULONG  Frequency;                   // Hz
} KSPROPERTY_CAPNODE_FREQUENCY_S, *PKSPROPERTY_CAPNODE_FREQUENCY_S;

typedef struct {
    KSPROPERTY Property;
    WCHAR  FileName[MAX_PATH];                   // Hz
} KSPROPERTY_CAPNODE_FILENAME_S, *PKSPROPERTY_CAPNODE_FILENAME_S;

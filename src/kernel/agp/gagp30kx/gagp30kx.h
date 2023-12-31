/*++

Copyright (2) 2002 Microsoft Corporation

Module Name:

    gagp30kx.h

Abstract:

    This module contains definitions for the MS AGP v3 Filter Driver


--*/

#include "kxagplib.h"
#include <dontuse.h>

#ifndef __GAGP30KX_H__
#define __GAGP30KX_H__

#define APERTURE_BASE        0x10
#define APERTURE_BASE64_MASK 0x04

#define ON  1
#define OFF 0

typedef enum _AGP35_AP_SIZE {
//    AP_SIZE_4096MB = 0x000, // IO Resource descriptor's size is only 32-bits!
    AP_SIZE_2048MB = 0x800,
    AP_SIZE_1024MB = 0xC00,
    AP_SIZE_512MB  = 0xE00,
    AP_SIZE_256MB  = 0xF00,
    AP_SIZE_128MB  = 0xF20,
    AP_SIZE_64MB   = 0xF30,
    AP_SIZE_32MB   = 0xF38,
    AP_SIZE_16MB   = 0xF3C,
    AP_SIZE_8MB    = 0xF3E,
    AP_SIZE_4MB    = 0xF3F,
} AGP35_AP_SIZE, *PAGP35_AP_SIZE;

typedef enum _AGPKX_AP_SIZE {
    AP_KX_SIZE_2048MB = 0x80000000,
    AP_KX_SIZE_1024MB = 0x40000000,
    AP_KX_SIZE_512MB  = 0x20000000,
    AP_KX_SIZE_256MB  = 0x10000000,
    AP_KX_SIZE_128MB  = 0x8000000,
    AP_KX_SIZE_64MB   = 0x4000000,
    AP_KX_SIZE_32MB   = 0x2000000
} AGPKX_AP_SIZE, *PAGPKX_AP_SIZE;

//
// We'll probably never use 64-bit PTE support,
// but we'll define the corresponding structures,
// and make the code explicit when using 32-bit
// format
//
typedef struct _GART_ENTRY_SW32 {
    ULONG State    : 4;
    ULONG Reserved : 28;
} GART_ENTRY_SW32, *PGART_ENTRY_SW32;

//
// GART Entry states are defined so that all software-only states
// have the Valid bit set and the page value will point to the guard page
//
#define GART_ENTRY_VALID        1           //  0001
#define GART_ENTRY_FREE         0xd         //  1101
#define GART_ENTRY_COHERENT     2           //  0010

#define GART_ENTRY_CC           GART_ENTRY_COHERENT
#define GART_ENTRY_WC           4           //  0100
#define GART_ENTRY_UC           8           //  1000

#define GART_ENTRY_GUARD  (GART_ENTRY_WC | GART_ENTRY_UC | GART_ENTRY_CC | GART_ENTRY_VALID)

#define GART_ENTRY_RESERVED_WC  (GART_ENTRY_WC | GART_ENTRY_VALID)
#define GART_ENTRY_RESERVED_UC  (GART_ENTRY_UC | GART_ENTRY_VALID)
#define GART_ENTRY_RESERVED_CC  (GART_ENTRY_CC | GART_ENTRY_VALID)

#define GART_ENTRY_VALID_WC     (GART_ENTRY_VALID)
#define GART_ENTRY_VALID_UC     (GART_ENTRY_VALID)
#define GART_ENTRY_VALID_CC     (GART_ENTRY_VALID | GART_ENTRY_COHERENT)

#define VERIFIER_ENABLED (AgpV_PTE32.Hard.Valid)

#define PTE40_TO_PFN64(GartPte) ((ULONGLONG)((ULONGLONG)(GartPte)->Hard.PageLow + ((ULONGLONG)(GartPte)->Hard.PageHigh << (PAGE_SHIFT + PAGE_HIGH_SHIFT))))

#define VERIFIER_PFN(GartPte) \
    ((PTE40_TO_PFN64(GartPte) >= PTE40_TO_PFN64(&AgpV_PTE32)) &&   \
    ((PTE40_TO_PFN64(GartPte) < (PTE40_TO_PFN64(&AgpV_PTE32) + (ULONGLONG)AGP_GUARD_RANGE_SIZE_IN_PAGES))))

//
// When the verifier is enabled, we also need to make sure that the
// PFN is equal to our verifier PFN, otherwise this entry is either
// a non-coherent mapped, or guard entry
//
#define GartEntryFree(GartPte) \
    (((GartPte)->Soft.State == GART_ENTRY_FREE) && \
     (!(VERIFIER_ENABLED && !VERIFIER_PFN(GartPte))))

//
// When the verifier is enabled, we need to make sure the PFN
// is equal to the verifier PFN, otherwise this is either a
// coherent-mapped, or guard page entry
//
#define GartEntryReserved(GartPte) \
    ((((GartPte)->Soft.State == GART_ENTRY_RESERVED_CC) || \
      ((GartPte)->Soft.State == GART_ENTRY_RESERVED_UC) || \
      ((GartPte)->Soft.State == GART_ENTRY_RESERVED_WC)) && \
     (!(VERIFIER_ENABLED && !VERIFIER_PFN(GartPte))))

//
// If the verifier is enabled, then in addition to match on
// requested state type, PFN must match the verifier PFN
//
#define GartEntryReservedAs(GartPte, Type) \
    (((GartPte)->Soft.State == (Type)) && \
     (!(VERIFIER_ENABLED && !VERIFIER_PFN(GartPte))))

//
// If the verifier is enabled, then an entry is mapped if it has
// one of the valid soft state types, i.e., not guard, and the PFN
// is not the verifier PFN
//
#define GartEntryMapped(GartPte) \
    ((((GartPte)->Soft.State == GART_ENTRY_VALID_WC) || \
      ((GartPte)->Soft.State == GART_ENTRY_VALID_UC) || \
      ((GartPte)->Soft.State == GART_ENTRY_VALID_CC)) && \
      (!(VERIFIER_ENABLED && VERIFIER_PFN(GartPte))))

typedef struct _GART_ENTRY_SW64 {
    ULONGLONG State    : 4;
    ULONGLONG Reserved : 60;
} GART_ENTRY_SW64, *PGART_ENTRY_SW64;

typedef struct _GART_ENTRY_HW32 {
    ULONG Valid     :  1;
    ULONG Coherent  :  1;
    ULONG Reserved  :  2;
    ULONG PageHigh  :  8;
    ULONG PageLow   : 20;
} GART_ENTRY_HW32, *PGART_ENTRY_HW32;

#define PAGE_HIGH_SHIFT 20

#define PAGE_HIGH_MASK 0xFF
#define PAGE_LOW_MASK 0xFFFFF

typedef struct _GART_ENTRY_HW64 {
    ULONGLONG Valid     :  1;
    ULONGLONG Coherent  :  1;
    ULONGLONG Reserved  :  2;
    ULONGLONG PageHigh  :  8;
    ULONGLONG PageLow   : 20;
    ULONGLONG PageHigh2 : 32;
} GART_ENTRY_HW64, *PGART_ENTRY_HW64;

typedef struct _GART_PTE32 {
    union {
        GART_ENTRY_HW32 Hard;
        GART_ENTRY_SW32 Soft;
        ULONG AsULONG;
    };
} GART_PTE32, *PGART_PTE32;

typedef struct _GART_PTE64 {
    union {
        GART_ENTRY_HW64 Hard;
        GART_ENTRY_SW64 Soft;
        ULONGLONG AsULONGLONG;
    };
} GART_PTE64, *PGART_PTE64;

//
// Define the MS AGP3-specific extension
//
typedef struct _GAGP30KX_EXTENSION {
    PHYSICAL_ADDRESS ApertureStart;
    PHYSICAL_ADDRESS GartPhysical;
    ULONGLONG        SpecialTarget;
    __deref_volatile __field_ecount_opt(GartLength) PGART_PTE32 Gart;
    ULONG            GartLength;
    ULONG            ApertureLength;
    ULONG            DeviceId;
    ULONG            CapabilityId;
    BOOLEAN          GlobalEnable;
    BOOLEAN          FourGBEnable;
    BOOLEAN          HostTxEnable;
    BOOLEAN          CoherentEnable;
} GAGP30KX_EXTENSION, *PGAGP30KX_EXTENSION;

//
// These flags are passed via the registry in the special reserve section
// of AGP device flags
//
#define AGP_FLAG_PRIVATE_HOST_TX_OVERRIDE    0x0000000000100000L
#define AGP_FLAG_PRIVATE_VIA_AGP2_RATE_PATCH 0x0000000000200000L
#define AGP_FLAG_PRIVATE_ENABLE_MP_SUPPORT   0x0000000000400000L
#define AGP_FLAG_PRIVATE_IGNORE_CAPS_VERSION 0x0000000000800000L

//
// Verifier definitions
//
extern GART_PTE32 AgpV_PTE32;
extern ULONG AgpV_Flags;
extern ULONG AgpV_GartCachePteOffset;

NTSTATUS
AgpV_PlatformInit(
    IN PVOID AgpContext,
    IN OUT PULONG VerifierFlags
    );

VOID
AgpV_PlatformWorker(
    IN PVOID AgpContext
    );

VOID
AgpV_PlatformStop(
    IN PVOID AgpContext
    );

ULONG __inline ConvertPhysAddrToPTEVal(PHYSICAL_ADDRESS PhysAddr)
{
    GART_PTE32 AgpPTE32;

    AgpPTE32.AsULONG = 0;
    AgpPTE32.Hard.PageLow = (ULONG)((PhysAddr.QuadPart >> PAGE_SHIFT) & PAGE_LOW_MASK);
    AgpPTE32.Hard.PageHigh = (ULONG)((PhysAddr.QuadPart >> (PAGE_SHIFT + PAGE_HIGH_SHIFT)) & PAGE_HIGH_MASK);
    AgpPTE32.Hard.Valid = 1;

    return AgpPTE32.AsULONG;
}

#endif // __GAGP30KX_H__


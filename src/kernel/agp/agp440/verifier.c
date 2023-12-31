/*++

Copyright (2) 2003 Microsoft Corporation

Module Name:

    verifier.c

Abstract:

    This module implements the AGP verifier platform support functions


--*/

#include "agp440.h"

#ifdef ALLOC_PRAGMA
#pragma alloc_text(PAGE, AgpV_PlatformInit)
#pragma alloc_text(PAGE, AgpV_PlatformWorker)
#pragma alloc_text(PAGE, AgpV_PlatformStop)
#endif

GART_PTE AgpV_PTE = { 0, 0, 0 };
ULONG AgpV_Flags = 0;
ULONG AgpV_GartCachePteOffset = 0;

static ULONG GartCacheChecksum = 0;
static int GartCacheChecksum_r = 55665;

#define FLUSH_CHECKSUM(x) \
    (x) = 0; \
    GartCacheChecksum_r = 55665;

#define _c1_ 52845
#define _c2_ 22719

__forceinline
VOID
AgpV_SimpleChecksum(
    IN PULONG Checksum,
    IN ULONG Data
    )
/*++

Routine Description:

    Implement a simple ULONG checksum routine to save us the trouble
    of having to scan the entire Gart-cache if our Gart contents haven't
    changed

    Reference: http://users.stargate.net/~newcomer/checksum.htm

Arguments:

    Checksum - The checksum we are calculating

    Data - Data to add to checksum

Return Value:

    None

--*/
{
    PUCHAR buf = (PUCHAR)&Data;
    UCHAR Cipher = (buf[0] ^ (GartCacheChecksum_r >> 8));

    GartCacheChecksum_r = ((Cipher + GartCacheChecksum_r) * _c1_) + _c2_;    

    *Checksum += Cipher;

    Cipher = (buf[1] ^ (GartCacheChecksum_r >> 8));
    GartCacheChecksum_r = ((Cipher + GartCacheChecksum_r) * _c1_) + _c2_;    

    *Checksum += Cipher;
}


NTSTATUS
AgpV_PlatformInit(
    IN PAGP440_EXTENSION AgpContext,
    IN OUT PULONG VerifierFlags
    )
/*++

Routine Description:

    If successful, the platform will always map free AGP Gart entries to
    the supplied page, otherwise the platform-dependent portions of AGP
    verification will not be enabled, also initializes and enables any
    other platform-dependent AGP verification, such as a Gart-cache

Arguments:

    AgpContext - Platform context structure

    VerifierFlags - AGP Verification enables

Return Value:

    NTSTATUS

--*/
{
    PAGED_CODE();

    AgpV_Flags = *VerifierFlags;
    
    return STATUS_SUCCESS;
}


VOID
AgpV_PlatformWorker(
    IN PAGP440_EXTENSION AgpContext
    )
/*++

Routine Description:

    Performs platform verification as a periodic worker thread,
    and calls KeBugCheckEx with the appropriate AGP error code
    when appropriate

Arguments:

    Extension - Platfrom context structure

Return Value:

    VOID

--*/
{
    PAGED_CODE();
    
    if (AgpV_Flags & AGP_GART_CORRUPTION_VERIFICATION) {
        if (AgpContext->Gart != NULL) {
            ULONG Index;
            ULONG NewChecksum;
            
            FLUSH_CHECKSUM(NewChecksum);
            
            //
            // Compute a checksum for the Gart
            //
            for (Index = 0; Index < AgpV_GartCachePteOffset; Index++) {
                AgpV_SimpleChecksum(&NewChecksum,
                                    AgpContext->Gart[Index].AsUlong); 
            }
            
            //
            // If the checksum does not match, store the new checksum, and
            // verify the contents of the Gart against our Gart-cache
            //
            if (NewChecksum != GartCacheChecksum) {
                GartCacheChecksum = NewChecksum;
                
                for (Index = 0; Index < AgpV_GartCachePteOffset; Index++) {
                    
                    if (AgpContext->Gart[Index].AsUlong !=
                        AgpContext->Gart[AgpV_GartCachePteOffset + Index].AsUlong){
                        
                        AGPLOG(AGP_CRITICAL, ("AgpVerify: AGP Gart corruption "
                                              "detected GartBase=%x, offset=%x, "
                                              "GartCacheBase=%x\n",
                                              AgpContext->Gart,
                                              Index * sizeof(GART_PTE),
                                              (PCCHAR)AgpContext->Gart +
                                              AgpContext->GartLength));
                        
#if DBG
                        ASSERT(0);
#elif (WINVER > 0x501)
                        KeBugCheckEx(AGP_GART_CORRUPTION,
                                     (ULONG_PTR)AgpContext->Gart,
                                     Index * sizeof(GART_PTE),
                                     (ULONG_PTR)((PCCHAR)AgpContext->Gart +
                                                 AgpContext->GartLength),
                                     0);
#endif
                    }
                }
                AGPLOG(AGP_VERIFY, ("G")); // Expensive Gart verification
                
            //
            // The checksum matched our previous one, so we avoid
            // having to compare against the Gart-cache
            //
            } else {
                AGPLOG(AGP_VERIFY, ("g")); // Relatively cheap Gart verifier
            }

        //
        // The Gart hasn't been allocated yet, nop
        //
        } else {
            AGPLOG(AGP_VERIFY, (".")); // Nop
        }
    }
}



VOID
AgpV_PlatformStop(
    IN PVOID AgpContext
    )
/*++

Routine Description:

    Perform any necessary verifier cleanup in the AGP platform

Arguments:

    AgpContext - Platform context structure

Return Value:

    None

--*/
{
    PAGED_CODE();
    
    AgpV_GartCachePteOffset = 0;
    AgpV_Flags = 0;
}


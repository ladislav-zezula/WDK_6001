

/*****************************************************************************\
* 
*  Module Name    PRIVALOC.H
*  Project        R200 Longhorn Sample Driver
*
*  Description    Buffers reserved privately by the miniport
*
*  Coppyright (c) 1998-2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
\*****************************************************************************/


#ifndef PRIVALOC_H
#define PRIVALOC_H


#ifdef __cplusplus
extern "C" {
#endif

/** Type of internal buffer. All memory for internal buffers 
    must be reserved by the driver prior to reporting all the 
    rest of the memory to Video Memory Manager.
*/
typedef enum _PRIVALLOC_BUFFER_TYPE
{
    PRIVALLOC_BUFFER_FIRST,

    PRIVALLOC_BUFFER_CURSOR = PRIVALLOC_BUFFER_FIRST,
    PRIVALLOC_BUFFER_RING,
    PRIVALLOC_BUFFER_DMATABLE,
    PRIVALLOC_BUFFER_WRITEBACK,

    // TODO: Fix is needed in UMD to get rid of this. 
    // When UMD passes in invalid handle and KMD wants to ignore it, 
    // KMD would patch in this allocation just in case ASIC actually 
    // uses the memory. This way ASIC is somewhat less likely to hang 
    // (corruption is more likely to occur instead). Doing this subverts 
    // security and wastes memory.
    PRIVALLOC_BUFFER_IGNOREDINVALIDHANDLE,

    PRIVALLOC_BUFFER_LAST,

} PRIVALLOC_BUFFER_TYPE;


/** Type of graphics memory used for privately allocated buffer
*/
typedef enum _PRIVALLOC_MEMORY_TYPE
{
        // Not allocated
        //
    PRIVALLOC_MEMORY_NONE,

        // Frame buffer memory
        //
    PRIVALLOC_MEMORY_LOCAL,

        // AGP or write-combined PCI Express
        //
    PRIVALLOC_MEMORY_USWC,

        // PCI non-pageable contiguous 
        //
    PRIVALLOC_MEMORY_COMMON,

} PRIVALLOC_MEMORY_TYPE;


/** All properties for private allocation buffer are saved in 
    this structure. 
*/
typedef struct _PRIVALLOC_BUFFER_PROPERTIES
{
    PRIVALLOC_MEMORY_TYPE   MemType;
    UINT                    SegmentId;

    UINT                    SizeInBytes;

    UINT                    McAddress;
    UINT                    McOffset;
    VOID                   *pVirtualAddress;

    //
    // Original unaligned values may be needed if memory is to be freed explicitly
    //

    UINT                    McAddressUnaligned;
    VOID                   *pVirtualAddressUnaligned;

} PRIVALLOC_BUFFER_PROPERTIES;


/** Decrease the original size of every segment by the amount of memory 
    needed for internal buffer allocation.
*/
__allocator VOID *ReservePrivateBuffers (
    VOID                           *DeviceHandle,
    VOID                           *pDmaAdapter,
    UINT                            nSegments,
    VOID                           *pSegmentDesc,
    VOID                          **ppBaseVirtualAddress
    );

/** Free private buffers
*/
VOID FreePrivateBuffers (
    VOID                   *pContext
    );

/** Get allocation parameters for specified internal buffer
*/
CONST PRIVALLOC_BUFFER_PROPERTIES *GetPrivateBufferParams (
    VOID                   *pContext,
    PRIVALLOC_BUFFER_TYPE   BufferType
    );


#ifdef __cplusplus
}
#endif

#endif  // PRIVALOC_H


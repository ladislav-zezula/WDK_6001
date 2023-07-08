

/** \file cmm.h
*   \brief Header file for Central Memory Manager 
*
*  CopyRight (c) 2001-2002 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*/

/** \addtogroup cmmapi */
//@{

#ifndef _CMM_H
#define _CMM_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************Type*Definitions*****************************\
* 
\****************************************************************************/
#ifdef _H2INC

#ifndef ULONG
#define ULONG unsigned long
#endif //ULONG

#ifndef LONG
#define LONG long
#endif //LONG

#ifndef DWORD
#define DWORD unsigned long
#endif //DWORD

#ifndef CHAR
#define CHAR char
#endif //CHAR

#ifndef HWND
#define HWND unsigned long
#endif //HWND

#endif //_H2INC

#ifndef _WIN64

#ifndef ULONG_PTR
typedef ULONG ULONG_PTR;
#endif // ULONG_PTR
 
#endif // _WIN64

typedef ULONG_PTR       CMM_HDEVICE;
typedef ULONG_PTR       CMM_HCLIENT;
typedef ULONG_PTR       CMM_HSURF;

/**
   Possible tiling modes for all asics.
*/
typedef enum _CMM_TILING_MODE_ENUM
{
    CMM_TILING_MODE__DEFAULT            = 0,
    CMM_TILING_MODE__NONE               = 1,
    CMM_TILING_MODE__MACRO              = 2,
    CMM_TILING_MODE__MICRO              = 3,
    CMM_TILING_MODE__MACRO_MICRO        = 4,
    CMM_TILING_MODE__16Z                = 5,
    CMM_TILING_MODE__32Z                = 6,
    CMM_TILING_MODE__MICRO_4X4          = 7,
    CMM_TILING_MODE__MACRO_MICRO_4X4    = 8,

    /** On R400, tiling modes are not selectable by software.
     *   Thus we use the CMM_TILING_MODE_ENUM to distinguish
     *   among supported surface formats.  At present there
     *   are three: LINEAR (signified by TILING_MODE__NONE),
     *   2D, and 3D SLICE.
     */
    CMM_TILING_MODE__2D                 = 9,  // R400 only
    CMM_TILING_MODE__3D_SLICE           = 10  // R400 only
} CMM_TILING_MODE_ENUM;    
typedef DWORD CMM_TILING_MODE;

#define COUNT_CMM_TILING_MODES 11             // sizeof cannot be used to count enumerators

    /** R400 pixel formats below are derived from register spec 1.47
     */
typedef enum _CMM_PIXEL_FORMAT_ENUM
{
  CMM_PIXEL_FORMAT__8                    = 2,   // Valid on all ASICs
  CMM_PIXEL_FORMAT__5_6_5                = 4,   // Valid on all ASICs
  CMM_PIXEL_FORMAT__8_8_8_8              = 6,   // Valid on all ASICs

  CMM_PIXEL_FORMAT__8BPP                 = 8,   // Alias for backward compatibility: Not valid on R400 
  CMM_PIXEL_FORMAT__16BPP                = 16,  // Alias for backward compatibility: Not valid on R400 
  CMM_PIXEL_FORMAT__32BPP                = 32,  // Alias for backward compatibility: Not valid on R400 

  CMM_PIXEL_FORMAT__16_16_16_16          = 26,  
  CMM_PIXEL_FORMAT__32_32_32_32          = 35,  

  CMM_PIXEL_FORMAT__DEFAULT              = 0xffffffff

} CMM_PIXEL_FORMAT_ENUM;
typedef DWORD CMM_PIXEL_FORMAT;


typedef enum _CMM_SURFACE_ROTATION {
    CMM_SURFACE_ROTATION__0       = 0,
    CMM_SURFACE_ROTATION__90      = 1,
    CMM_SURFACE_ROTATION__180     = 2,
    CMM_SURFACE_ROTATION__270     = 3,
    CMM_SURFACE_ROTATION__DEFAULT = 4
} CMM_SURFACE_ROTATION;


/** Resources that can be assigned to clients through CMMAssignResource */
typedef enum _CMM_RESOURCE_TYPE
{
    CMM_RESOURCE__NONE,
    CMM_RESOURCE__RTS,
    CMM_RESOURCE__VIZ_QUERY

} CMM_RESOURCE_TYPE;

typedef DWORD CMM_RESOURCE_TYPE_ENUM; 

typedef DWORD CMM_RESOURCE;

#define CMM_RESOURCE__INVALID  0xffffffff


/**
   CMM Return Codes 
*/
typedef enum _CMM_RETURNCODE
{
    // General codes
    /** Return code when the action succeeded */
    CMM_OK                                  = 0,

    /** Non-specific CMM error */
    CMM_ERROR                               = 1,
    
    // Resource availibility codes
    /** Not enough Frame buffer memory to fulfill the request.*/
    CMM_ERROR_NO_MEMORY_FB                  = 10,

    /** Not enough AGP memory to fulfill the request.*/
    CMM_ERROR_NO_MEMORY_AGP                 = 11,

    /** Not enough PCI GART memory to fulfill the request.*/
    CMM_ERROR_NO_MEMORY_PCIGART             = 12,

    /** Not enough PCI physically contiguous non-pageable memory to fulfill the request.*/
    CMM_ERROR_NO_MEMORY_PCI                 = 13,

    /** Not enough ASIC Z mask memory to fulfill the request.*/
    CMM_ERROR_NO_MEMORY_ZMASK               = 14,

    /** Not enough ASIC Hi-Z memory to fulfill the request.*/
    CMM_ERROR_NO_MEMORY_HIZ                 = 15,

    /** There was not enough memory to add this lock to the CMM internal lock information store. */
    CMM_ERROR_NO_MEMORY                     = 16,

    /** No apertures available at this time.*/
    CMM_ERROR_NO_APERTURES                  = 17,

    /** Not enough ASIC Colour mask memory to fulfill the request.*/
    CMM_ERROR_NO_MEMORY_CMASK               = 18,

    /** Not enough Invisible Frame buffer memory to fulfill the request.*/
    CMM_ERROR_NO_MEMORY_FB_INVISIBLE        = 19,

    /** Not enough ATI GART memory to fulfill the request.*/
    CMM_ERROR_NO_MEMORY_ATIAGP              = 20,

    // Invalid data codes
    /** Invalid device */
    CMM_ERROR_INVALID_DEVICE                = 100,

    /** The specified hClient is not valid or has been unregistered. */
    CMM_ERROR_INVALID_CLIENT                = 101,

    /** Invalid bits specified in flags */
    CMM_ERROR_INVALID_FLAGS                 = 102,

    /** The specified hSurface is not valid.
     *  In this case, the surface can be considered free
     *  (if the user is sure the hSurface specified was correct).
     */
    CMM_ERROR_INVALID_SURFACE               = 103,

    /** Size of input parameter does not match CMM’s size */
    CMM_ERROR_INPUTSIZE_MISMATCH            = 104,

    /** Size of output parameter does not match CMM’s size */
    CMM_ERROR_OUTPUTSIZE_MISMATCH           = 105,

    /** The currently available CMM does not support this feature.*/
    CMM_ERROR_ACTION_NOT_SUPPORTED          = 106,

    /** The memory controller address is invalid for the specified device.*/
    CMM_ERROR_INVALID_MCADDRESS             = 107,

    CMM_ERROR_INVALID_OPCODE                = 108,

    /** The specified memory is already locked.*/
    CMM_ERROR_REDUNDANT_OPERATION           = 109,

    /** The requested memory space already has an active lock.*/
    CMM_ERROR_BUSY                          = 110,

    /** The size of the memory is too large to be locked.*/
    CMM_ERROR_TOO_LARGE                     = 111,

    /** The specified locked memory handle is not valid.*/
    CMM_ERROR_INVALID_HANDLE                = 112,

    /** The memory could be locked down but not mapped into either PCI or AGP space.*/
    CMM_ERROR_MAP_FAILED                    = 113,

    /** The operating system call to unlock the memory failed.*/
    CMM_ERROR_UNLOCK_FAILED                 = 114,

    /** Only a subset of the request was locked.
     *  This is not an error condition. It is a notification that some,
     * but not all memory was locked. The caller must still call the unlock
     * function to unlock the subset
     */
    CMM_ERROR_INCOMPLETE                    = 115,

    CMM_ERROR_ACTION_DISABLED               = 116,

    CMM_ERROR_INVALID_PROCESS               = 117,

    // State related codes.
    /** Required interaction with the ASIC is not available,
     *  and the operation cannot be completed at this time.*/
    CMM_ERROR_HARDWARE_NOT_ACTIVE           = 200,

    /** Surface already has an aperture reserved.*/
    CMM_ERROR_APERATURE_ALREADY_ASSIGNED    = 201,

    /** The specified hSurface has been lost.*/
    CMM_ERROR_SURFACE_LOST                  = 202,

    /** This ASIC/memory cannot achieve the specified tiling mode.*/
    CMM_ERROR_SURFACE_INVALID_TILING_MODE   = 203,

    /** Lost surface data was not saved for recovery,
     *  and even if plenty of resources are available,
     *  the surface will not be recovered (and should be freed with a call
     *  to CMMFreeSurface).
     */
    CMM_ERROR_SURFACE_UNRECOVERABLE         = 204,

    CMM_ERROR_SURFACE_DESTROYED             = 205,

    CMM_ERROR_SURFACE_NOT_LOST              = 206,

    /** Request can not be satisfied due to desired BPP **/
    CMM_ERROR_SURFACE_INVALID_BPP           = 207,

    /** Request to change tiling mode unacceptable **/
    CMM_ERROR_INVALID_TILINGMODE_CHANGE     = 208,

    /** No valid shared client for this driver instance **/
    CMM_ERROR_INVALID_SHARED_CLIENT         = 209,

    /** The HW has no more available overlays. **/
    CMM_ERROR_NO_HW_OVERLAY                 = 210,

    /** Combination of pixel format and tiling mode is unsupported
     *    even though each property by itself is within range. **/
    CMM_ERROR_SURFACE_INVALID_FORMAT        = 211,

    /* CMM has no more resource tokens of the requested
     *    type available for assignment.
     */
    CMM_ERROR_NO_TOKEN                      = 212,

    /* CMM does not have enough resource tokens of the requested
     *    type to complete the current request for multiple-token
     *    assignment.
     */
    CMM_ERROR_TOO_FEW_TOKENS                = 213,

    /* CMM does not assign resources of this type. (See
     *  CMM_RESOURCE_TYPE for enumeration of supported types.)
     */
    CMM_ERROR_INVALID_RESOURCE_TYPE         = 214,


} CMM_RETURNCODE;    



//////////////////////////////////////////////////////////////////////////////
// Client flags
//////////////////////////////////////////////////////////////////////////////


typedef enum _CMM_CLIENT
{
    CMM_CLIENT__CMM,
    CMM_CLIENT__DVD,
    CMM_CLIENT__OVERLAY,
    CMM_CLIENT__CAPTURE,
    CMM_CLIENT__2D,
    CMM_CLIENT__OGL,
    CMM_CLIENT__DD_D3D,
    CMM_CLIENT__DEFAULT

} CMM_CLIENT;

typedef DWORD CMM_CLIENT_ENUM;

typedef enum _CMM_TOKEN
{
    CMM_TOKEN__ID_00,
    CMM_TOKEN__ID_01,
    CMM_TOKEN__ID_02,
    CMM_TOKEN__ID_03,
    CMM_TOKEN__ID_04,
    CMM_TOKEN__ID_05,
    CMM_TOKEN__ID_06,
    CMM_TOKEN__ID_07,
    CMM_TOKEN__ID_08,
    CMM_TOKEN__ID_09,
    CMM_TOKEN__ID_10,
    CMM_TOKEN__ID_11,
    CMM_TOKEN__ID_12,
    CMM_TOKEN__ID_13,
    CMM_TOKEN__ID_14,
    CMM_TOKEN__ID_15,
    CMM_TOKEN__MAX_RT_TOKENS,
    CMM_TOKEN__MAX_VIZQ_TOKENS = 64,
    CMM_TOKEN__MAX_TOKENS = CMM_TOKEN__MAX_VIZQ_TOKENS,
    CMM_TOKEN__UNAVAILABLE                               // CMM_TOKENS__MAX_TOKENS + 1
} CMM_TOKEN;


// Client mode informtion
// Default is CMM_CLIENT_FLAG_MODE_RING3.
/** Specifies a Ring 0 client, which means a client linked directly into the display driver under WinNT.*/
#define CMM_CLIENT_FLAG_MODE_RING0                  0x00000001

/**Specifies a Ring3 client (default if no mode flag specified).*/
#define CMM_CLIENT_FLAG_MODE_RING3                  0x00000002

#define CMM_CLIENT_FLAG_MODE_MASK                   0x0000000F


// Client owner information
/** Code to distinguish DirectDraw/D3D surfaces*/
#define CMM_CLIENT_FLAG_OWNER_DD_D3D                0x00000010

/** Code to distinguish OpenGL surfaces*/
#define CMM_CLIENT_FLAG_OWNER_OGL                   0x00000020

/** Code to distinguish DVD surfaces*/
#define CMM_CLIENT_FLAG_OWNER_DVD                   0x00000030

/** Code to distinguish 2D surfaces*/
#define CMM_CLIENT_FLAG_OWNER_2D                    0x00000040

/** Code to distinguish Queue Server surfaces*/
#define CMM_CLIENT_FLAG_OWNER_QS                    0x00000050

/** Code to distinguish CMM surfaces*/
#define CMM_CLIENT_FLAG_OWNER_CMM                   0x00000060

/** Code to distinguish DDMapMemory surfaces*/
#define CMM_CLIENT_FLAG_OWNER_DDMAP_MEMORY          0x00000070

//** These 2 internal flags are used to support ON_ALLOC clients*/
#define CMM_CLIENT_FLAG_OWNER_MAPCLIENT_FB          0x00000080
#define CMM_CLIENT_FLAG_OWNER_MAPCLIENT_OTHERS      0x00000090


/** Default surface owners*/
#define CMM_CLIENT_FLAG_OWNER_UNKNOWN               0x000000E0

#define CMM_CLIENT_FLAG_OWNER_MASK                  0x000000F0


// Client owner information

/** This client will always map the surface to the active process
 *  at allocation time (first AGP surface).*/
#define CMM_CLIENT_FLAG_MEMMAP_ON_ALLOC             0x00000100

/** This client will map the entire address space for the requested
 * process during the call to CMMRegisterClient.*/
#define CMM_CLIENT_FLAG_MEMMAP_ON_REGISTER          0x00000200

/** This client will never map any of its surface allocations for Ring3 access.*/
#define CMM_CLIENT_FLAG_MEMMAP_NEVER                0x00000300

/** This client will map the surface to ring3 on a per surface basis */
#define CMM_CLIENT_FLAG_MEMMAP_ON_SURF_ALLOC        0x00000400

#define CMM_CLIENT_FLAG_MEMMAP_MASK                 0x00000F00


// Client general/request information 

/** (for NT variants only) This client will not create a Driver object to trigger
 *  a callback on process termination for auto-cleaning of the client’s resources.*/
#define CMM_CLIENT_FLAG_REQUEST_NO_DRVOBJ           0x00001000

/** If the client does not plan on calling unregister (since they are simply searching for an existing client o use)… they need to set this flag*/
#define CMM_CLIENT_FLAG_REQUEST_NO_UNREGISTER       0x00002000

/** Request the CMM use the hProcess field of this structure rather
 *  than ask the OS for the active process.*/
#define CMM_CLIENT_FLAG_REQUEST_OVERRIDE_PROCESS    0x00004000

/** Triggers the search for a client with the same characteristics (including associated process).
 *  If not found, this call will return error.*/
#define CMM_CLIENT_FLAG_REQUEST_MUST_EXIST          0x00008000

/** This client will only map the FB to the desired process and not any other resources.
 *  This support exists for the required capabilities of DdMapMemory.*/
#define CMM_CLIENT_FLAG_REQUEST_ONLY_MAP_FB         0x00010000

/** If the client wishes the resources associated with the mapping client
 *  to NEVER be shared with any other client this flag will guarantee  private ownership.
 *  Note, over use of this flag could severly deplete system resources causing future mappings to fail.*/
#define CMM_CLIENT_FLAG_REQUEST_NO_MAP_SHARING      0x00020000

/** If the client wishes to allocate HIGH_PRIORITY surfaces, they need
 *  to set this flag...
 *  The behavior for high priority surfaces is to only evict surfaces 
 *  that are owned by clients that support high priority surfaces
 *  (of non-high priority memstate).  This signal is also used to trigger
 *  the QS surface eviction notificaiton support (see QS.DOC for details).*/
#define CMM_CLIENT_FLAG_REQUEST_ALLOW_HIGH_PRIORITY 0x00040000

#define CMM_CLIENT_FLAG_REQUEST_MASK                0x000FF000

#define CMM_CLIENT_FLAG_RESERVED_MASK               0xFFF00000
#define CMM_CLIENT_FLAG_RESERVED_ACTIVITY_MASK      0xF0000000


//////////////////////////////////////////////////////////////////////////////
// Surface descriptor flags used in allocating surfaces.
//////////////////////////////////////////////////////////////////////////////
// Flags to determine the memory pool.
// Note, default behavior depends on surface type.
/** Request the surface be allocated in the FrameBuffer.
 *  If there is not enough FB memory, the call will fail.
 */
#define CMM_SURFDESC_FLAG_POOL_FB                   0x00000001

/** Request the surface be allocated in the AGP.
 *  If there is not enough AGP memory, the call will fail.
 */
#define CMM_SURFDESC_FLAG_POOL_AGP                  0x00000002

/** Request the surface be allocated in the memory managed by the ASICs GART table. For
 *  the ASICs prior to the R400, the PCI GART will be always used. For the R400, the
 *  ATI GART with PCI bus mastering will be used if the physical address is within 1TB.
 *  The PCI GART will be used if the physical address is more than 1TB. By default, the memory
 *  will be cacheable. If the flag CMM_SURFDESC_FLAG_REQUEST_NONLOCAL_USWC is also specified,
 *  the memory will be write-combined. If there is not enough PCIGART memory, the call will fail.
 */
#define CMM_SURFDESC_FLAG_POOL_PCIGART              0x00000003
#define CMM_SURFDESC_FLAG_POOL_ATI_PCI              CMM_SURFDESC_FLAG_POOL_PCIGART

/**  Request the surface be allocated in the general physical non-pageable memory, using the
 *   PCI protocol. This pool tag is linked to the CMM_SURFDESC_FLAG_POOL_PCIGART pool tag
 *   as all PCI memory access must go through the GART for security protections.
 */
#define CMM_SURFDESC_FLAG_POOL_PCI                  0x00000004

/** Request the surface be allocated in the pageable system memory.
 *  This is equivalent to EngAllocMem for NT variants EXCEPT these allocations are safe
 * for access across driver instances (pdev).
 */
#define CMM_SURFDESC_FLAG_POOL_PAGEABLE_SYSTEM      0x00000005

/** Request the surface be allocated in the invisible part of the FrameBuffer.
 *  If there is not enough FB memory, the call will fail.
 */
#define CMM_SURFDESC_FLAG_POOL_FB_INVISIBLE         0x00000006

/** Request the surface be allocated in the memory managed by the ASICs ATI GART
 *  and using AGP bus mastering.  By default, the memory will be cacheable. If
 *  the flag CMM_SURFDESC_FLAG_REQUEST_NONLOCAL_USWC is also specified, the memory
 *  will be write-combined. If there is not enough ATIGART memory, the call will fail.
 */ 
#define CMM_SURFDESC_FLAG_POOL_ATI_AGP              0x00000007

/** Searches all the memory types that are capable of access from the ASIC
 *  (currently defined as everything but pageable).
 */
#define CMM_SURFDESC_FLAG_POOL_ANY_ASIC_ACCESSIBLE  0x0000000E

#define CMM_SURFDESC_FLAG_POOL_MASK                 0x0000000F

// Flags to determine how the surface is treated after
// allocation, or memory characteristics.
// Note, discardable means CMM can free without clients
// knowledge.
// Default is CMM_SURFDESC_FLAG_MEMSTATE_NONRECOVERABLE.
// Note, all non-local memory is non-losable (unless specified as
// discardable).

/** Signals the memory manager that this surface can be discarded from the heap
 *  at any time (for more important surfaces); but, requires client notification.
 *  This is more for DFBs, and the CMM current supports a callback to 2D client
 * for removing DFBs (currently NT variants only).
 */
#define CMM_SURFDESC_FLAG_MEMSTATE_DISCARDABLE      0x00000010

/** Signals that the memory manager needs to preserve the contents of this surface;
 *  and, must not remove the surface unless given no other choice.
 *  That is, the contents of this surface will automatically be preserve across
 *  hibernation, and under extra-ordinary conditions,
 *  the CMM may have to remove this surface (for possible recovery) during a mode set.
 */
#define CMM_SURFDESC_FLAG_MEMSTATE_RECOVERABLE      0x00000020

/** Signals that the memory manager need NOT preserve the contents of this surface;
 *  but, must not remove the surface unless given no other choice.
 *  That is, the contents of this surface will NOT be preserved across hibernation,
 *  and under extra-ordinary conditions, the CMM may have to remove this surface
 *  (but NO possible recovery) during a mode set.
 *  NOTE, this is the default surface type for Frame buffer surfaces.
 */
#define CMM_SURFDESC_FLAG_MEMSTATE_UNRECOVERABLE    0x00000030

/** This surface will never be removed or moved within the heap.
 *  Note, this surface is currently not supported for Frame Buffer memory,
 *  and is the default type for all other memory types.
 */
#define CMM_SURFDESC_FLAG_MEMSTATE_NONLOSABLE       0x00000040

/** This surface can be removed from the heap at any time without client notification.
 *  This memory state is currently ONLY used internally in the CMM for managing Lost
 *  direct draw surfaces.
 */
#define CMM_SURFDESC_FLAG_MEMSTATE_REMOVABLE        0x00000050

/** This surface type is the same as "RECOVERABLE"; however, an allocation request
 *  of this surface type will force the eviction of any other surface type
 *  (including "RECOVERABLE") that is owned by the same client owner type 
 *  (such as OGL).
 */
#define CMM_SURFDESC_FLAG_MEMSTATE_HIGH_PRIORITY    0x00000060

/** This surface type is used to categorize surfaces that "linked"
 *  or directly associated to the primary surface.  That is, this
 *  surface will be considered owned by the driver instance, and 
 *  will only be evicted/deleted.. when the primary is 
 *  evicted/deleted; and, this surface will reside in the FB 
 *  NEXT to the primary (and will evict any non-linked to primary
 *  surfaces in its way).
 *  Note, this surface state is currently only allowed for 2D clients.
 */
#define CMM_SURFDESC_FLAG_MEMSTATE_LINK_TO_PRIMARY  0x00000070

#define CMM_SURFDESC_FLAG_MEMSTATE_MASK             0x000000F0

// Flags to determine required resources and alignments.
// Default is CMM_SURFDESC_FLAG_SURF_GENERAL

/** Surfaces use by 2D component for general cache purposes
 * (temp buffers, glyphs, etc.).
 */
#define CMM_SURFDESC_FLAG_SURF_2D_CACHE             0x00000100

/** Surfaces used for storing Device Formatted Bitmaps
 *  (which are consider discardable surfaces in the CMM).
 */
#define CMM_SURFDESC_FLAG_SURF_DFB                  0x00000200

/** Surfaces used for overlay support. */
#define CMM_SURFDESC_FLAG_SURF_OVERLAY              0x00000300

/** Surfaces used for caching HW cursors.*/
#define CMM_SURFDESC_FLAG_SURF_CURSOR_CACHE         0x00000400

/** Flag indicates that this is the Primary surface.*/
#define CMM_SURFDESC_FLAG_SURF_PRIMARY              0x00000500

/** Surface used for purpose not characterized.*/
#define CMM_SURFDESC_FLAG_SURF_GENERAL              0x00000600

/** Texture surface */
#define CMM_SURFDESC_FLAG_SURF_TEXTURE              0x00000700

/** Z buffer surface */
#define CMM_SURFDESC_FLAG_SURF_ZBUFFER              0x00000800

/** Surface shared by all active desktop applications
 *  (under a given component) to use a single z-buffer
 * the same size as the desktop.
 */
#define CMM_SURFDESC_FLAG_SURF_ZBUFFER_SHARED       0x00000900

/** Surface shared by all active desktop applications
 *  (under a given component) to use a single overlay
 * the same size as the desktop.
 */
#define CMM_SURFDESC_FLAG_SURF_OVERLAY_SHARED       0x00000A00

/** Reserved surface type */
#define CMM_SURFDESC_FLAG_SURF_RESERVED_01          0x00000B00

/** Surface that will be flipped to (or blted from)
 * responsible for final rendering contents.
 * Same logic applied to as back surfaces.
 */
#define CMM_SURFDESC_FLAG_SURF_BACK                 0x00000C00

/**Surface shared by all active desktop applications
 * (under a given component) to use a single back buffer
 * the same size as the desktop.
 * Note, CMM allows the bpp to be of different size from
 * the primary.
 */
#define CMM_SURFDESC_FLAG_SURF_BACK_SHARED          0x00000D00
#define CMM_SURFDESC_FLAG_SURF_BACK_SHARED_1        0x00000D00

/**Surface shared by all active desktop applications
 * (under a given component) to use as single back buffer
 * the same size as the desktop. 
 * This is to allow a second shared back buffer...
 * Note, CMM allows the bpp to be of different size from
 * the primary.
 */
#define CMM_SURFDESC_FLAG_SURF_BACK_SHARED_2        0x00000E00

/**Surface shared by all active desktop applications
 * (under a given component) to use as single back buffer
 * the same size as the desktop. 
 * This is to allow a third shared back buffer...
 * Note, CMM allows the bpp to be of different size from
 * the primary.
 */
#define CMM_SURFDESC_FLAG_SURF_BACK_SHARED_3        0x00000F00


#define CMM_SURFDESC_FLAG_SURF_MASK                 0x0000FF00

// Flags to determine location within a pool.
// Default is CMM_SURFDESC_FLAG_LOCATION_ALLOC_FROM_LOW.

/** Search algorithm for desired location in the
 *  requested pool is to start at the beginning of the pool.
 */
#define CMM_SURFDESC_FLAG_LOCATION_ALLOC_FROM_LOW   0x00010000

/** Search algorithm for desired location in the
 *  requested pool is to start at the end of the pool.
 */
#define CMM_SURFDESC_FLAG_LOCATION_ALLOC_FROM_HIGH  0x00020000

#define CMM_SURFDESC_FLAG_LOCATION_MASK             0x00030000

/** Client will accept partial allocation of zmask 
 * or cmask from CMMAllocateSurface/Cache.
 */
#define CMM_SURFDESC_FLAG_REQUEST_PARTIAL_ALLOC_OK  0x00040000

// The last 13 bits are dedicated to special request flags.
/** User requests Colour cache memory.
 *  Will always fail if not supported by ASIC.
 */
#define CMM_SURFDESC_FLAG_REQUEST_ALLOC_CMASK       0x00080000

/** User requests Zmask memory for the Z surface
 * being allocated.  Will always fail if not supported by ASIC.
 */
#define CMM_SURFDESC_FLAG_REQUEST_ALLOC_ZMASK       0x00100000

/** User requests Hierarchical Z memory for the Z surface
 *  being allocated. Will always fail if not supported by ASIC.
 */
#define CMM_SURFDESC_FLAG_REQUEST_ALLOC_HIZ         0x00200000

// Flags to characterize possible memory type within a pool.
// These are only applicable to non-local memory (not FB).

/** User will only accept USWC cached memory for this
 * non-local memory request.
 */
#define CMM_SURFDESC_FLAG_REQUEST_NONLOCAL_USWC     0x00400000

/** User will only accept uncached memory for this
 *  non-local memory request.
 */
#define CMM_SURFDESC_FLAG_REQUEST_NONLOCAL_NON_USWC 0x00800000

/** Hints to the CMM that this surface will never
 *  need to be mapped to process address space.
 *  This flag is designed for Direct Draw use since FB surfaces
 *  do not need mappings, and some applications never allocate
 *  non-local surfaces (thus avoiding the mapping of all non-local pools).
 *  Note, this was required to workaround a W2K issue related to palette corruption.
 */
#define CMM_SURFDESC_FLAG_REQUEST_NO_RING3_MAPPING  0x00800000


// For frame buffer surfaces, the user may request that the
// surface is past any possible mode size and will never be lost
// (just as no non-local memory will every be lost.
#define CMM_SURFDESC_FLAG_REQUEST_FB_NONLOSABLE     0x01000000

/** The surface will be directly fetch from by the CRTC
 *  and needs to be marked as Displayable for alignment
 *  and other considerations.
 *  Note, these surfaces must also be FB surfaces.
 */
#define CMM_SURFDESC_FLAG_REQUEST_SURF_DISPLAYABLE  0x04000000

/** If the user wants to only consider a given memory bank, 
 *  they need to set this flag.
 */
#define CMM_SURFDESC_FLAG_REQUEST_USE_MEMBANK       0x08000000

/** This surface must be able to hold more then one
 * tiling aperture at any given time (for surfaces such as monolithic mipmaps).
 */
#define CMM_SURFDESC_FLAG_REQUEST_USE_MULTI_APERT   0x10000000

/** Used to force the CMM to allocate to a specific Memory controller address.
 *  If any surface currently resides at this location,
 *  it will be evicted by the CMM.
 *  Note, this flag should currently only be used by the 2D driver
 *  during allocation of primary surface.
 */
#define CMM_SURFDESC_FLAG_REQUEST_FORCE_MC_LOCATION 0x20000000

/** If the user wants to override the use of the surface values
 *  when allocating a cache.
 *  This flag is ONLY VALID for the entry point CMMAllocCache!
 */
#define CMM_SURFDESC_FLAG_REQUEST_OVERRIDE          0x40000000

/** Request the acquiring of a tiling aperture during the allocation.
 *  If no aperture is available, the allocation will fail.
 */
#define CMM_SURFDESC_FLAG_REQUEST_APERTURE          0x80000000

#define CMM_SURFDESC_FLAG_REQUEST_MASK              0xFFF80000

//////////////////////////////////////////////////////////////////////////////
// Surface information flags use to describe allocated surfaces...
//////////////////////////////////////////////////////////////////////////////
// Flags to describe the memory pool.
/** The surface is allocated in the FrameBuffer.*/
#define CMM_SURFINFO_FLAG_POOL_FB                   0x00000001

/** The surface is allocated in AGP.*/
#define CMM_SURFINFO_FLAG_POOL_AGP                  0x00000002

/** The surface is allocated in the memory managed by the ASICs PCI/ATI GART table.*/
#define CMM_SURFINFO_FLAG_POOL_PCIGART              0x00000003
#define CMM_SURFINFO_FLAG_POOL_ATIPCI               CMM_SURFINFO_FLAG_POOL_PCIGART

/** The surface is allocated in the general physical contiguous non-pageable memory.*/
#define CMM_SURFINFO_FLAG_POOL_PCI                  0x00000004

/** The surface is allocated in pageable system memory.*/
#define CMM_SURFINFO_FLAG_POOL_PAGEABLE_SYSTEM      0x00000005

/** The surface is allocated in the FrameBuffer, but in the invisible portion.*/
#define CMM_SURFINFO_FLAG_POOL_FB_INVISIBLE         0x00000006

/** The surface is allocated in the memory managed by the ATI GART table via AGP bus mastering. */
#define CMM_SURFINFO_FLAG_POOL_ATIAGP               0x00000007

#define CMM_SURFINFO_FLAG_POOL_MASK                 0x0000000F

// Flags to describe "static" nature or state of surface.
/** Signals the memory manager that this surface can be discarded from
    the heap at any time (for more important surfaces); but, requires client notification.
    This is more for DFBs, and the CMM current supports a callback to 2D client
    for removing DFBs (currently NT variants only).
*/
#define CMM_SURFINFO_FLAG_MEMSTATE_DISCARDABLE      0x00000010

/** Signals that the memory manager needs to preserve the contents of this surface;
    and, must not remove the surface unless given no other choice.
    That is, the contents of this surface will automatically be preserve
    across hibernation and under extra-ordinary conditions the CMM may
    have to remove this surface (for possible recovery) during a mode set.*/
#define CMM_SURFINFO_FLAG_MEMSTATE_RECOVERABLE      0x00000020

/** Signals that the memory manager need NOT preserve the contents of this surface;
    but, must not remove the surface unless given no other choice.
    That is, the contents of this surface will NOT be preserved across hibernation,
    and under extra-ordinary conditions,the CMM may have to remove this surface
    (but NO possible recovery) during a mode set. NOTE, this is the default surface type
    for Frame buffer surfaces.
*/
#define CMM_SURFINFO_FLAG_MEMSTATE_UNRECOVERABLE    0x00000030

/** This surface will never be removed or moved within the heap.
    Note, this surface is currently not supported for Frame Buffer memory,
    and is the default type for all other memory types. */
#define CMM_SURFINFO_FLAG_MEMSTATE_NONLOSABLE       0x00000040

/** This surface can be removed from the heap at any time without
    client notification.  This memory state is currently ONLY used internally
    in the CMM for managing Lost direct draw surfaces.*/
#define CMM_SURFINFO_FLAG_MEMSTATE_REMOVABLE        0x00000050

/** This surface type is the same as "RECOVERABLE"; however, an allocation request
 *  of this surface type will force the eviction of any other surface type
 *  (including "RECOVERABLE") that is owned by the same client owner type 
 *  (such as OGL).
 */
#define CMM_SURFINFO_FLAG_MEMSTATE_HIGH_PRIORITY    0x00000060

/** This surface type is used to categorize surfaces that "linked"
 *  or directly associated to the primary surface.  That is, this
 *  surface will be considered owned by the driver instance, and 
 *  will only be evicted/deleted.. when the primary is 
 *  evicted/deleted; and, this surface will reside in the FB 
 *  NEXT to the primary (and will evict any non-linked to primary
 *  surfaces in its way).
 *  Note, this surface state is currently only allowed for 2D clients.
 */
#define CMM_SURFINFO_FLAG_MEMSTATE_LINK_TO_PRIMARY  0x00000070

#define CMM_SURFINFO_FLAG_MEMSTATE_MASK             0x000000F0

// Flags to decribe relevant surface use.
/** Surfaces use by 2D component for general cache purposes (temp buffers, glyphs, etc…).*/
#define CMM_SURFINFO_FLAG_SURF_2D_CACHE             0x00000100

/** Surfaces used for storing Device Formatted Bitmaps
    (which are consider discardable surfaces in the CMM).*/
#define CMM_SURFINFO_FLAG_SURF_DFB                  0x00000200

/** Surfaces used for overlay support.*/
#define CMM_SURFINFO_FLAG_SURF_OVERLAY              0x00000300

/** Surfaces used for caching HW cursors.*/
#define CMM_SURFINFO_FLAG_SURF_CURSOR_CACHE         0x00000400

/** Flag indicates this is the Primary surface.*/
#define CMM_SURFINFO_FLAG_SURF_PRIMARY              0x00000500

/** Surface used for purpose not characterized.*/
#define CMM_SURFINFO_FLAG_SURF_GENERAL              0x00000600

/** Texture Surface */
#define CMM_SURFINFO_FLAG_SURF_TEXTURE              0x00000700

/** Z buffer surface */
#define CMM_SURFINFO_FLAG_SURF_ZBUFFER              0x00000800

/** Surface shared by all active desktop applications (under a given component)
    to use a single z-buffer the same size as the desktop.
*/
#define CMM_SURFINFO_FLAG_SURF_ZBUFFER_SHARED       0x00000900

/** Surface shared by all active desktop applications (under a given component)
    to use a single overlay buffer the same size as the desktop.
*/
#define CMM_SURFINFO_FLAG_SURF_OVERLAY_SHARED       0x00000A00

#define CMM_SURFINFO_FLAG_SURF_RESERVED_01          0x00000B00

/** Surface that will be flipped to (or blted from)
    responsible for final rendering contents.
    Same logic applied to as back surfaces below.*/
#define CMM_SURFINFO_FLAG_SURF_BACK                 0x00000C00

/** Surface shared by all active desktop applications (under a given component)
    to use a single back buffer the same size as the desktop.
    This may be of different bpp then the primary.
*/
#define CMM_SURFINFO_FLAG_SURF_BACK_SHARED          0x00000D00
#define CMM_SURFINFO_FLAG_SURF_BACK_SHARED_1        0x00000D00

/** Surface shared by all active desktop applications (under a given component)
    to use a single back buffer the same size as the desktop.
    This may be of different bpp then the primary.
    This surface type should be used for the "second" back buffer.
*/
#define CMM_SURFINFO_FLAG_SURF_BACK_SHARED_2   0x00000E00

/** Surface shared by all active desktop applications (under a given component)
    to use a single back buffer the same size as the desktop.
    This may be of different bpp then the primary.
    This surface type should be used for the "third" back buffer.
*/
#define CMM_SURFINFO_FLAG_SURF_BACK_SHARED_3        0x00000F00

#define CMM_SURFINFO_FLAG_SURF_MASK                 0x0000FF00

// General information flags
#define CMM_SURFINFO_FLAG_GENERAL_SURF_LOST         0x00010000
#define CMM_SURFINFO_FLAG_GENERAL_SURF_DESTROYED    0x00020000
#define CMM_SURFINFO_FLAG_GENERAL_USING_APERTURES   0x00040000
#define CMM_SURFINFO_FLAG_GENERAL_USING_TEMP_APERTS 0x00080000
#define CMM_SURFINFO_FLAG_GENERAL_SECONDARY_DEVICE  0x00100000 // Obsolete

/** The surface will be directly fetch from by the CRTC and needs
    to be marked as Displayable for alignment and other considerations.
    Note, these surfaces must also be FB surfaces.
*/
#define CMM_SURFINFO_FLAG_GENERAL_SURF_DISPLAYABLE  0x00200000
#define CMM_SURFINFO_FLAG_GENERAL_16BPP_IS_565      0x00400000
#define CMM_SURFINFO_FLAG_GENERAL_NONLOCAL_USWC     0x00800000
#define CMM_SURFINFO_FLAG_GENERAL_USE_MULTI_APERT   0x10000000
#define CMM_SURFINFO_FLAG_GENERAL_MASK              0xFFFF0000

//////////////////////////////////////////////////////////////////////////////
// Flags related to freeing surfaces.
//////////////////////////////////////////////////////////////////////////////
// Default setting is IMMEDIATELY.

/** Free the surface only after the timestamp defined for this surface has retired. */
#define CMM_FREESURF_FLAG_ON_TIMESTAMP_RETIRED      0x00000001

/** Free the surface only after the timestamp defined for this surface has ben consumed. */
#define CMM_FREESURF_FLAG_ON_TIMESTAMP_CONSUMED     0x00000002

/** Free the surface immediately */
#define CMM_FREESURF_FLAG_IMMEDIATELY               0x00000004

//////////////////////////////////////////////////////////////////////////////
// Flags related to assigning apertures...
//////////////////////////////////////////////////////////////////////////////

/** Surface access will occur outside the protection of the graphics mutex
 *  (such as a DD surface lock).  That is access could occur at any time.
 */
#define CMM_APERT_FLAG_UNPROTECTED_ACCESS           0x00000001

/** Surface access will NOT occur outside the protection of the
 *  graphics mutex (surface is only access by a driver under the mutex).
 */
#define CMM_APERT_FLAG_PROTECTED_ACCESS             0x00000002

/** Surface access is only temporary and is occurring from
 *  within a driver under the graphics mutex.
 *  This aperture use may internally override the use of
 *  CMM_APERT_FLAG_PROTECTED_ACCESS, 
 *  but never CMM_APERT_FLAG_UNPROTECTED_ACCESS,
 *  and should be freed immediately by the client.
 */
#define CMM_APERT_FLAG_TEMP_ACCESS                  0x00000004

/** Client sets this flag to request that CMMSetAperture reformat the
 *  surface contents according to the new tile format.  Currently this
 *  flag is ignored unless the surface is the active primary surface.
 */
#define CMM_APERT_FLAG_PRESERVE_SURF_CONTENTS       0x00000008

//////////////////////////////////////////////////////////////////////////////
// Flags related to locking memory...
//////////////////////////////////////////////////////////////////////////////

/** Request the memory to be locked in AGP space */
#define CMM_LOCK_FLAG_AGP                           0x00000001

/** Request the memory to be locked in PCI space */
#define CMM_LOCK_FLAG_PCI                           0x00000002

/** If the memory cannot be locked into AGP space completely
 *  (so the entire requested block is contiguous),
 * then this function will try to lock the memory into PCI space.
 */
#define CMM_LOCK_FLAG_CONTIGUOUS                    0x00000004

//////////////////////////////////////////////////////////////////////////////
// Flags related to unlocking memory...
//////////////////////////////////////////////////////////////////////////////
/** Unlock the memory only after the timestamp defined for this memory has been retired.*/
#define CMM_UNLOCK_FLAG_ON_TIMESTAMP_RETIRED        0x00000001

/** Unlock the memory only after the timestamp defined for this memory has been consumed.*/
#define CMM_UNLOCK_FLAG_ON_TIMESTAMP_CONSUMED       0x00000002

#define CMM_UNLOCK_FLAG_IMMEDIATELY                 0x00000004

//////////////////////////////////////////////////////////////////////////////
// General flags related to the state of the CMM.
//////////////////////////////////////////////////////////////////////////////

/** Indicates all rings are stored in AGP.*/
#define CMM_GENERAL_FLAG_RING_IN_AGP                0x00000001

/** Indicates all rings are stored in the frame buffer.*/
#define CMM_GENERAL_FLAG_RING_IN_FB                 0x00000002

/**Indicates all rings are stored in ASIC managed PCI/GART memory.*/
#define CMM_GENERAL_FLAG_RING_IN_PCIGART            0x00000004

/** Indicates all rings are stored in physically contiguous non-pageable PCI memory.*/
#define CMM_GENERAL_FLAG_RING_IN_PCI                0x00000008

/** Indicates indirect buffer reserve space is in AGP.*/
#define CMM_GENERAL_FLAG_IBUF_RESERVE_IN_AGP        0x00000010

/** Indicates indirect buffer reserve space is in the frame buffer.*/
#define CMM_GENERAL_FLAG_IBUF_RESERVE_IN_FB         0x00000020

/** Indicates indirect buffer reserve space is in ASIC managed PCI/GART memory.*/
#define CMM_GENERAL_FLAG_IBUF_RESERVE_IN_PCIGART    0x00000040

/** Indicates indirect buffer reserve space is in physically contiguous non-pageable PCI memory.*/
#define CMM_GENERAL_FLAG_IBUF_RESERVE_IN_PCI        0x00000080

/** Obsolete flag */
#define CMM_GENERAL_FLAG_SECONDARY_DEVICE_ACTIVE    0x00000100

/** All rings are in cached USWC non-local memory.*/
#define CMM_GENERAL_FLAG_RING_IN_USWC               0x00000200

/** Indirect buffer reserve is in cached USWC non-local memory.*/
#define CMM_GENERAL_FLAG_IBUF_RESERVE_IN_USWC       0x00000400

/** A call to CMMGetGeneralInfo will correctly populate the
 * CMM_GENERAL_INFO field dwNumberOfUniqueDisplays.
 */
#define CMM_GENERAL_FLAG_UNIQUE_DISPLAYS_REPORTED   0x00000800

/** This version of the CMM includes the special support to handle
 * DdMapMemory (using MSF_MapMemory and MSF_UnmapMemory calls).
 */
#define CMM_GENERAL_FLAG_DDRAW_MAPPING_SUPPORT      0x00001000

/** This version of the CMM includes support for high priority
 *  surface allocation (for clients registered as such).
 */
#define CMM_GENERAL_FLAG_HIGH_PRIORITY_SURF_SUPPORT 0x00002000

/** This version of the CMM includes support for primary link
 *  surface allocation (for 2D client ONLY).
 */
#define CMM_GENERAL_FLAG_PRIMARY_LINK_SURF_SUPPORT  0x00004000

/** This version of the CMM includes support for managing
 *  Viz Query IDs
 */
#define CMM_GENERAL_FLAG_VIZ_QUERY_SUPPORT          0x00008000

//////////////////////////////////////////////////////////////////////////////
// Flags for CMMGetPoolInfo
//////////////////////////////////////////////////////////////////////////////
/** Report on Frame Buffer pools */
#define CMM_POOL_INFO_FLAG_FB                       0x00000001
/** Report on Invisible Frame Buffer pools */
#define CMM_POOL_INFO_FLAG_FB_INVISIBLE             0x00000002
/** Report on AGP Buffer pools */
#define CMM_POOL_INFO_FLAG_AGP                      0x00000004
/** Report on PCI Buffer pools */
#define CMM_POOL_INFO_FLAG_PCI                      0x00000008
/** Report on PCIGart Buffer pools */
#define CMM_POOL_INFO_FLAG_PCI_GART                 0x00000010
/** Report on ATIGart Buffer pools */
#define CMM_POOL_INFO_FLAG_ATI_AGP                  0x00000020
/** Report on Pageable Buffer pools */
#define CMM_POOL_INFO_FLAG_PAGEABLE                 0x00000040
/** Report on all ASIC Accessable Buffer pools */
#define CMM_POOL_INFO_FLAG_ALL_ASIC_POOLS           0x0000003f
/** Report on all Buffer pools */
#define CMM_POOL_INFO_FLAG_ALL_POOLS                0x0000007f

/** Include client's discarable surfaces into the pool free bytes count.
    These are all surfaces that are marked as discardble by the client but
    have not yet been put into the free pool. */
#define CMM_POOL_INFO_FLAG_INCLUDE_DISCARDABLES     0x10000000

/** Include all timestamped surfaces into the pool free bytes count.
    These are all timestamped surfaces that should be considered freed but have not
    yet been put into the free pool. */
#define CMM_POOL_INFO_FLAG_INCLUDE_TS_SURFACES      0x20000000

/** Force a cleanup of all expired TS surfaces before calcualting free space.
*/
#define CMM_POOL_INFO_FLAG_RELEASE_TS_SURFACES      0x40000000

/** Retrieve a client name given an hClient.
 *  - Input Structure:       none
 *  - Output Structure:      sClientNameOutput
 */
#define CMM_DEBUG_FLAG_GET_CLIENT_NAME              0x00000002

/** Gets a summary of the total resources used by a given client.
 *  - Input Structure:       none
 *  - Output Structure:      sClientOutput
 */
#define CMM_DEBUG_FLAG_GET_CLIENT_RESOURCES         0x00000004

/** Call reserved for non-exposed interface for Win32
 *  memory tool used for debugging CMM support.
 *  - Input Structure:       sMemToolInput
 *  - Output Structure:      sMemToolOutput
 */
#define CMM_DEBUG_FLAG_MEMTOOL_CALL                 0x00000008

/** Featured used to allow clients to tag surface based
 *  on driver activity (entry points used from, etc…).
 *  - Input Structure:       sSurfaceTagInput
 *  - Output Structure:      sSurfaceTagOutput
 */
#define CMM_DEBUG_FLAG_SET_SURFACE_TAG              0x00000010

/** Provide client with tag information for a given surface.
 *  - Input Structure:       sSurfaceTagInput (dwTag field ignored)
 *  - Output Structure:      sSurfaceTagOutput
 */
#define CMM_DEBUG_FLAG_GET_SURFACE_TAGS             0x00000020

/**  Feature to allow clients to retrieve client and
 *  surface information based on a MCAddress.
 *  - Input Structure:       sFindInput (CMM_DEBUG_INPUT hClient field ignored).
 *  - Output Structure:      sFindOutput
 */
#define CMM_DEBUG_FLAG_FIND_HCLIENT_AND_HSURF       0x00000040

#define CMM_DEBUG_GET_TOTAL_NODES                   0x00000080
#define CMM_DEBUG_GET_POOLTYPE_NODES                0x00000100
#define CMM_DEBUG_GET_NODE_DATA                     0x00000200
#define CMM_DEBUG_GET_POOL_DATA                     0x00000400
#define CMM_DEBUG_GET_SURF_FROM_ADDR                0x00000800
#define CMM_DEBUG_DUMP_NODES_TO_FILE                0x00001000
//#define CMM_DEBUG_PASSTHROUGH                       0x00002000 // discontinued
#define CMM_DEBUG_DUMP_INPUT_TO_FILE                0x00004000
#define CMM_DEBUG_GET_HEAP                          0x00010000
#define CMM_DEBUG_GET_HEAP_ID                       0x00020000


// Temporary CMM_DEBUG_DEFINES
#define CMM_DUMP_FILE_START_FLAG 0xAAAAAAAA
#define CMM_DUMP_NEW_POOL_TYPE_FLAG 0xAAAAAAAB
#define CMM_DUMP_POOL_FLAG 0xAAAAAAAC
#define CMM_DUMP_ALLOC_NODES_FLAG 0xAAAAAAAD
#define CMM_DUMP_FREE_NODES_FLAG 0xAAAAAAAE
#define CMM_DUMP_TS_NODES_FLAG 0xAAAAAAAF

// **************************************IMPORTANT***************************
// **************************************Comment Start **********************
// No field in the structures below can be aligned on the boundary smaller 
// than its type length !! Padding size must always provide 16-byte alignment!

/** \brief Client descriptor
 *
 * User filled structure describing the CMM client.
 */
typedef struct _CMM_CLIENT_DESCRIPTOR_
{
  /** Size of this structure.*/
  DWORD             dwSize;
  
  /** Flags related to the client.
   * See definitions of CMM_CLIENT_FLAG_???? above.
   * Since Ring0 clients most likely want the process determination and
   * address mapping to occur at ALLOC time, these clients probably want
   * to set the flag CMM_CLIENT_FLAG_REQUEST_MAP_ON_ALLOC.
   */
  DWORD             dwClientFlags;
  
  /** Normally, the CMM with query the active process, but this could
   * cause problems for DDraw (since it has its own process).  This field
   * forces the CMM to use this handle to represent the process.
   */
  HANDLE            hProcessOverride;

  /** Identifies the client to CMM.  CMM_CLIENT enumerators replace
   *  CMM_CLIENT_FLAG_OWNER_XXX for purposes of registration
   *  Required by RTS support.
   */
  CMM_CLIENT_ENUM   eClientID;

#ifdef _WIN64
  /** If this is a 64bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[3];
#else
  /** If this is a 32bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[4];
#endif // _WIN64
} CMM_CLIENT_DESCRIPTOR;

/** \brief Client information
 *
 * CMM filled structure defining a registered CMM client. 
 */
typedef struct _CMM_CLIENT_INFO_
{
  /** Size of this structure. */
  DWORD             dwSize;
  
  /** Flags related to the client.
   * See definitions of CMM_CLIENT_FLAG_???? above.
   */
  DWORD             dwClientFlags;

  /** Reference handle for CMM in tracking clients.  
   * Note, this is a 64bit value under a 64bit OS.
   */
  CMM_HCLIENT       hClient;

  /** Process instance represents the number of 
   * times this Process has been registered.  Note,
   * resources mappings are only freed when the last 
   * CMM for this process is unregistered.
   * Note, this is not used for Unregister client.
   */
  DWORD             dwProcessInstance;  
  
#ifdef _WIN64
  /** If this is a 64bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[3];
#else
  /** If this is a 32bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[4];
#endif // _WIN64
} CMM_CLIENT_INFO;

/** \brief Surface Descriptor
 *
 * User filled structure to describing the surface to allocate.
 */
typedef struct _CMM_SURF_DESCRIPTOR_
{
  /** Size of this structure.*/
  DWORD             dwSize;
  
  /** Request information related to the surface
   * See definitions of CMM_SURFDESC_FLAG_???? above.
   */
  DWORD             dwSurfDescFlags;

  /** Reference handle for CMM in tracking clients.  
   * Note, this is a 64bit value under a 64bit OS.
   */
  CMM_HCLIENT       hClient;

  /** For Frame buffer request, the client may wish to only
   *  consider a specific memory bank (requires the flag
   *  CMM_SURFDESC_FLAG_REQUEST_USE_MEMBANK).
   */
  DWORD             dwMemoryBank;

  /** Tiling state. See tiling mode enums for more information.
  */
  CMM_TILING_MODE   dwTilingMode;
    
  /** General Surface information.
   *  Desired Bits per pixel. See pixel format enums.
   */
  CMM_PIXEL_FORMAT  dwBitsPerPixel;

  /** Desired Surface width in pixels (without alignment) */
  DWORD             dwUnalignedWidthInPixels;

  /** Desired Surface height (wihtout alignment) */
  DWORD             dwUnalignedHeight;

  /** Pitch alignment in bytes override.  
   *  This is not the actual pitch, but the desired granularity of 
   *  the final pitch value.
   *  Note, if the client wishes the CMM to figure this out (auto-align)
   *  this field should be set to 0.
   */
  DWORD             dwPitchAlignmentInBytesOverride;

  /** Height alignment override.
   *  This is not the actual height, but the desired granularity of 
   *  the final height value.
   *  Note, if the client wishes the CMM to figure this out (auto-align)
   * this field should be set to 0.
   */
  DWORD             dwHeightAlignmentOverride;
  
  /** Requested byte MCAddress alignment. 
   * This is not the actual MCAddress, but the desired granularity of 
   * the final MCAddress.
   * Note, if the client wishes the CMM to figure this out,
   * this field should be set to 0.
   */
  DWORD             dwMCAddressByteAlignmentOverride;

  /** Color key for shared overlay surface.
   * The shared overlay support requires the client to pass in 
   * a color that is defined in the same format as this
   * surface (the shared overlay buffer).
   */
  DWORD             dwOverlayColorKey;

#ifdef _WIN64
  /** If this is a 64bit system, this is the padding to make 16 byte alignment. */
  DWORD             padding[7];
#else
  /** If this is a 32bit system, this is the padding to make 16 byte alignment. */
  DWORD             padding[8];
#endif // _WIN64
} CMM_SURF_DESCRIPTOR;

/** Client input structure to specify the size of a linear allocation request */

typedef struct _CMM_LINEAR_ALLOCATION_
{
  /** Size of this structure.*/
  DWORD             dwSize;
  
  /** Request information related to the surface
   * See definitions of CMM_SURFDESC_FLAG_???? above.
   */
  DWORD             dwSurfDescFlags;

  /** Reference handle for CMM in tracking clients.  
   * Note, this is a 64bit value under a 64bit OS.
   */
  CMM_HCLIENT       hClient;

  /** Length of linear allocation request (in bytes) */
  DWORD             dwLength;

  /** Requested byte MCAddress alignment. 
   * This is not the actual MCAddress, but the desired granularity of 
   * the final MCAddress.  CMM expects this value to be a power
   * of 2.  The allocation call will fail if it is not.
   */
  DWORD             dwMCAddressByteAlignment;

  /** For Frame buffer request, the client may wish to only
   *  consider a specific memory bank (requires the flag
   *  CMM_SURFDESC_FLAG_REQUEST_USE_MEMBANK).
   */
  DWORD             dwMemoryBank;

#ifdef _WIN64
  /** If this is a 64bit system, this is the padding to make 16 byte alignment. */
  DWORD             dwPadding[1];
#endif
} CMM_LINEAR_ALLOCATION;

/**  CMM_RESOURCE_DESCRIPTOR is input to CMMAssignResource and CMMReleaseResource.
 *    CMM expects that every unused field will be set to zero.
 */
typedef struct _CMM_RESOURCE_DESCRIPTOR
{
  /** Size of this structure.*/
  DWORD                  dwSize;

  /** Reference handle for CMM in tracking clients.  
   * Note, this is a 64bit value under a 64bit OS.
   */
  CMM_HCLIENT            hClient;

  /** Type of resource to be assigned */
  CMM_RESOURCE_TYPE_ENUM eResourceType;

  /** The number of resource IDs requested or returned.
   */
  DWORD                  dwCount;

  /**  When requesting assignment of a resource by CMMAssignResource,
   *   client allocates an array of DWORDs comprising dwCount elements and
   *   passes the address of that array in pResource. CMM will write assigned
   *   resource IDs into this array.
   *   
   *   When releasing a resource, client writes the resource IDs into 
   *   an array of DWORDs and passes the address in pResource. 
   *  
   */ 
  CMM_RESOURCE           *pResource;

#ifdef _WIN64
  /** On a 64bit system, this is the padding to make 16 byte alignment. */
  DWORD                  dwPadding[1];
#else
  /** On a 32bit system, this is the padding to make 16 byte alignment. */
  DWORD                  dwPadding[3];
#endif


} CMM_RESOURCE_DESCRIPTOR;


/** \brief Surface information
 *
 * CMM filled structure defining an allocated surface.
 */
typedef struct _CMM_SURF_INFO_
{
  /** Size of this structure.*/
  DWORD             dwSize;
  
  /** Surface flags such as tiling state, AGP, etc...
   * See definitions of CMM_SURFINFO_FLAG_????
   */
  DWORD             dwSurfInfoFlags;
  
  /** Reference handle for CMM to an allocated surface.
   * Note, under a 64 bit OS, this is a 64 bit value.
   */
  CMM_HSURF         hSurface;
  
  /** Virtual address to the surface mapped to the process associated with
   * the CMM registered client (or calling process for allocation).
   */
  void              *pRing3Address;

  /** Kernel mode virtual address to the surface.*/
  void              *pRing0Address;

  /** Tiling state.  On R400, reports surface array dimensionality.
   * See tiling mode enums for more information.*/
  CMM_TILING_MODE   dwTilingMode;
  
  /** General Surface information.
   *   Currently bits per pixel, but on R400 CMM_PIXEL_FORMAT_ENUM.
   */
  CMM_PIXEL_FORMAT  dwBitsPerPixel;

  /** Surface width in pixels (without alignment)*/
  DWORD             dwWidthInPixels;

  /** Surface height (without alignment)*/
  DWORD             dwHeight;

  /** Aligned pitch in bytes.*/
  DWORD             dwAlignedPitchInBytes;

  /** Aligned height.*/
  DWORD             dwAlignedHeight;

  /** ASIC 32 bit Memory Control address to the surface.*/
  DWORD             dwMCAddress;

  /** 0 based offset from start of the pool (particularly usefull
   * for FB information pertaining to DAC).
   */
  DWORD             dwPoolBasedOffset;

  /** Offset of the ASICs Z mask memory.*/
  DWORD             dwZMask_Offset;

  /** Size (in bytes) of the ASICs Z mask memory.
   * A size of 0 indicates no ZMask memory.
   */
  DWORD             dwZMask_Bytes;

  /** Size (in blocks) of the ASICs Z mask memory.
   * A size of 0 indicates no ZMask memory.
   */
  DWORD             dwZMask_Blocks;

  /** Offset of the ASICs Hi-Z memory.*/
  DWORD             dwHiZ_Offset;

  /** Size (in bytes) of the ASICs Hi-Z mask memory.
   * A size of 0 indicates no ZMask memory.
   */
  DWORD             dwHiZ_Bytes;

  /** Size (in blocks) of the ASICs Hi-Z mask memory.
   * A size of 0 indicates no ZMask memory.
   */
  DWORD             dwHiZ_Blocks;

  /** Offset of the ASICs Colour mask memory.*/
  DWORD             dwCMask_Offset;

  /** Size (in bytes) of the ASICs Colour mask memory.
   * A size of 0 indicates no ZMask memory.
   */
  DWORD             dwCMask_Bytes;

  /** Size (in blocks) of the ASICs Colour mask memory.
   * A size of 0 indicates no ZMask memory.
   */
  DWORD             dwCMask_Blocks;

  /** Total surface memory size in bytes.*/
  DWORD             dwSurfaceMemorySizeInBytes;

#ifdef _WIN64
  /** If this is a 64bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[10];
#else
  /** If this is a 32bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[13];
#endif // _WIN64

} CMM_SURF_INFO;

/** \brief Cache descriptor
 *
 * User filled structure defining an surface for some desired action.
 */
typedef struct _CMM_SURF_REQUEST_
{
  /** Size of this structure.*/
  DWORD             dwSize;
  
  /** Request information related to the type of cache.
   *  Note, same flags you would have set for CMMAllocSurface,
   *  since this is the real path for allocating caches.
   *  See definitions of CMM_SURFDESC_FLAG_????.
   */
  DWORD             dwSurfDescFlags;

  /** Reference handle for CMM in tracking clients.  
   *  Note, this is a 64bit value under a 64bit OS.
   */
  CMM_HCLIENT       hClient;

  /** Reference handle for CMM in tracking surfaces.  
   *  Note, this is a 64bit value under a 64bit OS.
   */
  CMM_HSURF         hSurface;

  /** Value that will be used to override the bits per pixel
   *  if the OVERRIDE flag is set when
   *  allocating a cache for a surface. Note that ALL of the Override fields
   *  must have legitimate values if the OVERRIDE flag is set.
   */
  DWORD             dwOverrideBitsPerPixel;

  /** Value that will be used to override the aligned pitch in bytes
   *  if the OVERRIDE flag is set when
   *  allocating a cache for a surface. Note that ALL of the Override fields
   *  must have legitimate values if the OVERRIDE flag is set.
   */
  DWORD             dwOverrideAlignedPitchInBytes;

  /** Value that will be used to override the aligned height
   *  if the OVERRIDE flag is set when
   *  allocating a cache for a surface. Note that ALL of the Override fields
   *  must have legitimate values if the OVERRIDE flag is set.
   */
  DWORD             dwOverrideAlignedHeight;

#ifdef _WIN64
  /** If this is a 64bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[3];
#else
  /** If this is a 32bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[5];
#endif // _WIN64
} CMM_SURF_REQUEST;

/** \brief Surface descriptor
 *
 * User filled structure for controlling FreeSurface operation.
 */
typedef struct _CMM_FREESURF_INPUT_
{
  /** Size of this structure.*/
  DWORD             dwSize;
  
  /** Request information related to the surface
   *  See definitions of CMM_FREESURF_FLAG_????.
   *  Default condition is to free immediately.
   */
  DWORD             dwFreeSurfFlags;
  
  /** Reference handle for CMM in tracking clients.
   *  Note, this is a 64bit value under a 64bit OS.
   */
  CMM_HCLIENT       hClient;

  /** Reference handle for CMM to an allocated surface.
   *  Note, under a 64 bit OS, this is a 64 bit value.
   */
  CMM_HSURF         hSurface;
  
  /** Possible timestamp to use on freeing the surface.
   *  Only reference if one of the following flags set:
   *   CMM_FREESURF_FLAG_ON_TIMESTAMP_RETIRED
   *   CMM_FREESURF_FLAG_ON_TIMESTAMP_CONSUMED
   *  Note, the QS_TIMESTAMP type is defined in QS.H.
   */
  QS_TIMESTAMP      liTimeStamp;
  
#ifdef _WIN64
  /** If this is a 64bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[4];
#else
  /** If this is a 32bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[6];
#endif // _WIN64
} CMM_FREESURF_INPUT;

/** \brief Aperture descriptor
 *
 * User filled structure defining the surface and tiling mode for a
 * desired aperture assignment.
 */
typedef struct _CMM_APERTURE_DESCRIPTOR_
{
  /** Size of this structure.*/
  DWORD             dwSize;
  
  /** See flag defines "CMM_APERT_FLAG_???".*/
  DWORD             dwApertFlags;
  
  /** Reference handle for CMM surface.
   *  Note, this is a 64bit value under a 64bit OS.
   */
  CMM_HSURF         hSurface;

  /** Tiling state.  See tiling mode enums for more information...
   *  Override value in case client manages state outside of CMM.
   *  A value of 0 will cause CMM to use hSurf to determine.
   */
  CMM_TILING_MODE   dwTilingModeOverride;
    
  /** Pitch in bytes of surface to receive aperture.
   *  Override value in case client manages state outside of CMM.
   *  A value of CMM_TILING_MODE__DEFAULT will cause CMM to use
   *  hSurf to determine.
   */
  DWORD             dwPitchInBytesOverride;

  /** Height of the surface to recieve aperture...
   * Override value in case client manages state outside of CMM.
   * A value of 0 will cause CMM to use hSurf to determine.
   */
  DWORD             dwHeightOverride;

  /** GPU Memory controller address of surface to receive aperture.
   *  Override value in case client manages state outside of CMM.
   *  A value of 0 will cause CMM to use hSurf to determine.
   */
  DWORD             dwMCAddressOverride;

  /** Width in pixels of the surface to recieve aperture...
   * Override value in case client manages state outside of CMM.
   * A value of 0 will cause CMM to calculate the pixel width
   * of the surface based on pixel format and byte pitch.
   * Will be ignored on ASICS prior to R400.
   */
  DWORD             dwWidthOverride;

  /** Pixel format of surface to receive aperture.
   *  Override value in case client manages state outside of CMM.
   *  A value of CMM_PIXEL_FORMAT__DEFAULT will cause CMM to use
   *  hSurf to determine.  WARNING: Use the ENUM. The value of
   *  PIXEL_FORMAT__DEFAULT may not be zero, since 0 encodes
   *  a valid R400 pixel format.
   *  Will be ignored on ASICs prior to R400.
   */
  DWORD             dwPixelFormatOverride;

  /** Slice index of surface to receive aperture.
   *  This value is REQUIRED for 3D-sliced surfaces.
   *  Will be ignored on ASICs prior to R400.
   */
  DWORD             dwSliceIndex;
  
#ifdef _WIN64
  /** If this is a 64bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[1];
#else
  /** If this is a 32bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[2];
#endif // _WIN64
} CMM_APERTURE_DESCRIPTOR;

/** \brief Memory lock request
 *
 * User filled structure used to request locking of memory.
 */
typedef struct _CMM_LOCK_MEMORY_INPUT_
{
  /** Size of this structure.*/
  DWORD             dwSize;
  
  /** See flag defines "CMM_LOCK_FLAG_???".*/
  DWORD             dwLockFlags;

  /** Reference handle for CMM in tracking clients.  
   *  Note, this is a 64bit value under a 64bit OS.
   */
  CMM_HCLIENT       hClient;

  /** The virtual address to lock.*/
  PVOID             pvAddress;

  /** Handle from a previous call to lock memory. This should
   *  be 0 (zero) unless the previous call returned an error
   *  that indicated only some of the memory was locked.
   */
  HANDLE            hLockedMemory;

  /** How much memory to lock.*/
  DWORD             dwLockSize;

#ifdef _WIN64
  /** If this is a 64bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[3];
#else
  /** If this is a 32bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[2];
#endif // _WIN64

} CMM_LOCK_MEMORY_INPUT, *PCMM_LOCK_MEMORY_INPUT;

/** \brief Memory lock response
 *
 * Memory lock response structure returned after locking memory
 */
typedef struct _CMM_LOCK_MEMORY_OUTPUT_
{
  /** Size of this structure.*/
  DWORD             dwSize;
  
  /** See flag defines "CMM_LOCK_FLAG_???".*/
  DWORD             dwLockFlags;

  /** Reference handle for CMM memory locking.  
   *  Note, this is a 64bit value under a 64bit OS.
   */
  HANDLE            hLockedMemory;

  /** The Memory Controller address for the caller to use to get access
   *  to the locked memory.
   */
  DWORD             dwMCAddress;

  /** How much memory was locked.*/
  DWORD             dwLockedSize;

#ifdef _WIN64
  /** If this is a 64bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[2];
#else
  /** If this is a 32bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[3];
#endif // _WIN64

} CMM_LOCK_MEMORY_OUTPUT, *PCMM_LOCK_MEMORY_OUTPUT;

/** \brief Memory unlock request
 *
 *  User filled structure used to request unlocking of memory
 *  after it was previously locked.
 */
typedef struct _CMM_UNLOCK_MEMORY_INPUT_
{
  /** Size of this structure.*/
  DWORD             dwSize;
  
  // See flag defines "CMM_UNLOCK_FLAG_???" above...
  DWORD             dwUnlockFlags;

  /** Reference handle for CMM in tracking clients.  
   *  Note, this is a 64bit value under a 64bit OS.
   */
  CMM_HCLIENT       hClient;

  /** Reference handle for CMM memory locking.  
   *  Note, this is a 64bit value under a 64bit OS.
   */
  HANDLE            hLockedMemory;

  /** Possible timestamp to use on freeing the surface.
   *  Only reference if one of the following flags set:
   *    CMM_UNLOCK_FLAG_ON_TIMESTAMP_RETIRED
   *    CMM_UNLOCK_FLAG_ON_TIMESTAMP_CONSUMED
   *  Note, the QS_TIMESTAMP type is defined in QS.H.
   */
  QS_TIMESTAMP      liTimeStamp;
  
#ifdef _WIN64
  /** If this is a 64bit system, this is the padding to make 16 byte alignment.*/
  //DWORD             padding[0];
#else
  /** If this is a 32bit system, this is the padding to make 16 byte alignment.*/
  DWORD             padding[2];
#endif // _WIN64

} CMM_UNLOCK_MEMORY_INPUT, *PCMM_UNLOCK_MEMORY_INPUT;

/** \brief CMM Info
 *  Info describing the state of resources managed by CMM.
 */

#pragma pack (push, 1)

#define CMM_GENERAL_INFO_NUM_DWORD_SPARES 16
typedef struct _CMM_GENERAL_INFO_
{
  /** Size of this structure.*/
  DWORD             dwSize;

  /** General Memory flags...
   * See definitions of CMM_GENERAL_FLAG_????.
   */
  DWORD             dwGeneralFlags;
  
  /** Local Visible Frame buffer memory size*/
  DWORD             dwTotalBytes_FB;

  /** Local Visible Frame buffer available memory size*/
  DWORD             dwAvailableBytes_FB;

  /** Local Frame buffer memory memory controller base address*/
  DWORD             dwMCAddress_FBBase;
  
  /** AGP memory size (not including dynamic reserves...)*/
  DWORD             dwTotalBytes_AGP;

  /** AGP memory available size (not including dynamic reserves...)*/
  DWORD             dwAvailableBytes_AGP;

  /** AGP memory controller address base*/
  DWORD             dwMCAddress_AGPBase;

  /** PCI-gart memory size*/
  DWORD             dwTotalBytes_PCIGart;

  /** PCI-gart available memory size*/
  DWORD             dwAvailableBytes_PCIGart;

  /** PCI-gart memory controller address*/
  DWORD             dwMCAddress_PCIGartBase;

  /** PCI nonpageable contiguous memory size (not including dynamic reserves...)*/
  DWORD             dwTotalBytes_PCI;

  /** PCI nonpageable available memory */
  DWORD             dwAvailableBytes_PCI;

  /** PCI nonpageable memory controller address*/
  DWORD             dwMCAddress_PCIBase;

  /** Local Frame buffer pointer.*/
  PVOID             pvCPUAddress_FBBase;

  /** Padding to align LARGE_INTEGER on 16 byte boundary */
  DWORD             dwSpare1;

  /** Local Frame buffer pointer.*/
  LARGE_INTEGER     physHostAddress_FBBase;

  /** AGP pointers*/
  PVOID             pvCPUAddress_AGPBase;

  /** Padding to align LARGE_INTEGER on 16 byte boundary */
  DWORD             dwSpare2;

  /** AGP pointers*/
  LARGE_INTEGER     physHostAddress_AGPBase;

  /** PCI-Gart pointer.*/
  PVOID             pvCPUAddress_PCIGartBase;

  /** Padding to align LARGE_INTEGER on 16 byte boundary */
  DWORD             dwSpare3;

  /** PCI-Gart pointer.*/
  LARGE_INTEGER     physHostAddress_PCIGartBase;

  /** PCI non-pageable pointer.*/
  PVOID             pvCPUAddress_PCIBase;

  /** Padding to align LARGE_INTEGER on 16 byte boundary */
  DWORD             dwSpare4;

  /** PCI non-pageable pointer.*/
  LARGE_INTEGER     physHostAddress_PCIBase;

  /** Total number of tiling apertures*/
  DWORD             dwTotalApertures;
  
  /** Size of the ring buffer in bytes*/
  DWORD             dwTotalBytes_PM4Ring;

  /** Memory Controller address of the ring buffer*/
  DWORD             dwMCAddress_PM4RingBase;

  /** Amount of reserved i-buffer space in bytes.
   *  Note, this represents only the memory dedicated exclusively
   *  to indirect buffers and not the total memory available for
   *  indirect buffer use.
   */
  DWORD             dwTotalBytes_PM4IBufferReserve;

  /** Memory Controller address of reserved i-buffer space.*/
  DWORD             dwMCAddress_PM4IBufferReserve;
  
  /** Total number of memory banks available.*/
  DWORD             dwTotalMemBanks;
  
  /** Total amount of FB memory reserved as non-losable across
   *  mode sets and hibernation.
   */
  DWORD             dwTotalBytes_FBNonLosableMem;

  /** Avaialable amount of FB memory reserved as non-losable across
   *  mode sets and hibernation.
   */
  DWORD             dwAvailableBytes_FBNonLosableMem;

  /** The amount of memory that is reserved and not available 
   *  for allocation in FB memory.
   *  This information is required by DDraw to obtain accurate 
   *  estimates on memory usability.
   *  Reserved memory includes things like:
   *  - Primary surface.
   *  - BIOS EDID information.
   *  - FB pad for render engine workaround (Rage128).
   *  - HW cursor cache.
   *  - QS Ring buffer.
   *  - QS indirect buffer reserve.
   */
  DWORD             dwReservedBytes_Local;

  /** The amount of memory that is reserved and not available 
   *  for allocation in AGP memory.
   *  This information is required by DDraw to obtain accurate 
   *  estimates on memory usability.
   *  Reserved memory includes things like:
   *  - Primary surface.
   *  - BIOS EDID information.
   *  - FB pad for render engine workaround (Rage128).
   *  - HW cursor cache.
   *  - QS Ring buffer.
   *  - QS indirect buffer reserve.
   */
  DWORD             dwReservedBytes_AGP;

  /** The amount of memory that is reserved and not available 
   *  for allocation in PCT GART memory.
   *  This information is required by DDraw to obtain accurate 
   *  estimates on memory usability.
   *  Reserved memory includes things like:
   *  - Primary surface.
   *  - BIOS EDID information.
   *  - FB pad for render engine workaround (Rage128).
   *  - HW cursor cache.
   *  - QS Ring buffer.
   *  - QS indirect buffer reserve.
   */
  DWORD             dwReservedBytes_PCIGart;

  /** Total amount of commited AGP memory */
  DWORD             dwTotalCommitedAGPMem;

  /** Total amount of Pageable memory*/
  DWORD             dwTotalBytes_Pageable;

  /** Available amount of Pageable memory*/
  DWORD             dwAvailableBytes_Pageable;

  /** CPU address of Pageable memory*/
  PVOID             pvCPUAddress_PageableBase;

  /** Number of unique displays*/
  DWORD             dwNumberOfUniqueDisplays;

  /** CMM Version number */
  unsigned short    wCMM_version;

  /** Count of removable surfaces */
  unsigned short    wRemovableSurfCount;

  /** Local Invisible Frame buffer memory size*/
  DWORD             dwTotalBytes_InvisibleFB;

  /** Local Invisible Frame buffer available memory size*/
  DWORD             dwAvailableBytes_InvisibleFB;

  /** Local Invisible Frame buffer memory memory controller base address*/
  DWORD             dwMCAddress_InvisibleFBBase;
  
  /** Total memory mapped by the ATI AGP */
  DWORD             dwTotalBytes_ATIAGP;

  /** Total memory used from the ATI AGP */
  DWORD             dwAvailableBytes_ATIAGP;

  // Spare space for future expansion
  DWORD             dwSpare[CMM_GENERAL_INFO_NUM_DWORD_SPARES];

} CMM_GENERAL_INFO;

typedef struct _CMM_POOL_INFO_REQUEST
{
  /** Size of this structure.*/
  DWORD             dwSize;

  /** Pool Info request flags flags...
   * See definitions of CMM_POOL_INFO_REQUEST_FLAG_????.
   */
  DWORD             dwPoolInfoRequestFlags;

  /** Padding for expansion */
  DWORD             padding[2];

} CMM_POOL_INFO_REQUEST;

typedef struct _CMM_POOL_INFO_
{
  /** Size of this structure.*/
  DWORD             dwSize;

  /** Local Frame buffer memory size*/
  DWORD             dwTotalBytes_FB;

  /** Local Frame buffer free memory size*/
  DWORD             dwFreeBytes_FB;

  /** Invisible Frame buffer memory size*/
  DWORD             dwTotalBytes_FB_Invisible;

  /** Invisible Frame buffer free memory size*/
  DWORD             dwFreeBytes_FB_Invisible;

  /** AGP memory size*/
  DWORD             dwTotalBytes_AGP;

  /** AGP free memory size*/
  DWORD             dwFreeBytes_AGP;

  /** PCI memory size*/
  DWORD             dwTotalBytes_PCI;

  /** PCI free memory size*/
  DWORD             dwFreeBytes_PCI;

  /** PCI GART memory size*/
  DWORD             dwTotalBytes_PCIGart;

  /** PCI GART free memory size*/
  DWORD             dwFreeBytes_PCIGart;

  /** ATI AGP memory size*/
  DWORD             dwTotalBytes_ATIAGP;

  /** ATI GART free memory size*/
  DWORD             dwFreeBytes_ATIAGP;

  /** Pageable memory size*/
  DWORD             dwTotalBytes_Pageable;

  /** Pageable free memory size*/
  DWORD             dwFreeBytes_Pageable;

  /** Padding for expansion */
  DWORD             padding[6];

} CMM_POOL_INFO;
#pragma pack ()

/**
 * Function command codes... (which match function definitions below)
 */
typedef enum _CMM_COMMAND
{
   CMM_COMMAND_REGISTER_CLIENT      = 1,
   CMM_COMMAND_UNREGISTER_CLIENT    = 2,
   CMM_COMMAND_ALLOCATE_SURFACE     = 3, 
   CMM_COMMAND_FREE_SURFACE         = 4,
   CMM_COMMAND_QUERY_SURFACE_INFO   = 5,
   CMM_COMMAND_ALLOC_CACHE          = 6,
   CMM_COMMAND_RECOVER_SURFACE      = 7,
   CMM_COMMAND_SET_APERTURE         = 8,
   CMM_COMMAND_FREE_APERTURE        = 9,
   CMM_COMMAND_GET_GENERAL_INFO     = 10,
   CMM_COMMAND_DEBUG                = 11,
   CMM_COMMAND_FREE_CACHE           = 12,
   CMM_COMMAND_LOCK_MEMORY          = 13,
   CMM_COMMAND_UNLOCK_MEMORY        = 14,
   CMM_COMMAND_GET_POOL_INFO        = 15,
   CMM_COMMAND_ASSIGN_RESOURCE      = 16,
   CMM_COMMAND_RELEASE_RESOURCE     = 17
} CMM_COMMAND;    

// If included while building the CMM don't include external
// function prototypes unless explicitly required.
#if !defined(BUILDING_CMM) || defined(INCLUDE_CMM_H_FUNCTIONS)

/****************************************************************************\
* Function definitions.
* Note, these calls should not be made directly by Ring3 clients; but,
* rather are defined here for Ring0 clients and reference.
\****************************************************************************/

/** Registers a Process for using the CMM.

    The CMM requires at least one CMM registered client per process for functionality.
    That is, the CMM is responsible for managing resources as well as correctly mapping
    resources into the process address space of the running application/drivers. 
    CMM_OK is returned upon success and an error condition otherwise.  

    No client can use the CMM without first registering with the CMM.
    This includes the 2D drivers as well.

    Registering clients under the same process will have no negative impact such as
    "extra" resource mapping for the CMM creates only one client per process
    (given the client characteristics are the same).
    The CMM will share client definition between components (OGL, QS, DVD, ect…).

    Components may choose to have a single CMM client for multiple processes,
    and have process address mapping/unmapping occur during CMMAllocSurface and CMMFreeSurface.
    To do so, CMM clients must specify “-1” as the hProcess input and set the flag
    CMM_CLIENT_FLAG_MEMMAP_ON_ALLOC
    (or CMM_CLIENT_FLAG_MEMMAP_NEVER if no Ring3 mapping Is ever desired).

    \param hDevice Handle of the target hardware device.
    \param pInput Pointer to a user filled structure describing the client.
    \param pOutput Pointer to CMM filled structure that defines the client (includes a hClient)..
*/
CMM_RETURNCODE __stdcall CMMRegisterClient  (
                                            CMM_HDEVICE             hDevice, 
                                            CMM_CLIENT_DESCRIPTOR   *pInput,
                                            CMM_CLIENT_INFO         *pOutput
                                            );

/** Unregisters a registered CMM client.

    This is simply to unregister the CMM registered client.
    CMM_OK is returned upon success and an error condition otherwise

    All successfully registered clients should successfully unregister for system stability.
    Failure to unregister can cause resource “leaking” that can only be corrected by a system
    reboot (since resources are preserved across mode sets).

    NT variants support Driver Objects that trigger a callback on process termination.
    This callback is used to auto-clean CMM client’s resources.

    \param hDevice Handle of the target hardware device.
    \param pInput Pointer to a client filled structure describing the CMM client to unregister.
*/
CMM_RETURNCODE __stdcall CMMUnregisterClient(
                                            CMM_HDEVICE             hDevice,
                                            CMM_CLIENT_INFO         *pInput
                                            );

/** Allocates resource memory for the desired surface.

    Allocates the necessary resources for the requested surface type.
    If the request cannot be met exactly as specified, an error code is returned;
    and, the client may choose to modify the request.

    CMM_OK is returned upon success and an error condition otherwise.

    Z surfaces will allocate other Z resources, such as Z-mask or Hi-Z ASIC cache memory,
    if the user requests these resources.  To do so, the user must set the flags
    CMM_SURFDESC_FLAG_REQUEST_ALLOC_ZMASK and/or CMM_SURFDESC_FLAG_REQUEST_ALLOC_ZMASK in
    the CMM_SURF_DESCRIPTOR structure field dwSurfDescFlags.

    The field dwMemoryBank will only be referenced if the flag CMM_SURFDESC_FLAG_LOCATION_USE_MEMBANK
    is set, and the value should always be less then the number of banks reported by the call to
    CMMGetGeneralInfo (field dwTotalMemBanks), since the bank request is a 0-based number.

    CMM_SURFDESC_FLAG_REQUEST_FORCE_MC_LOCATION forces an allocation to a specific Memory controller
    address, but should only be used by the 2D driver for restoring the primary associated with a
    disabled driver instance (pdev).

    \param hDevice Handle of the target hardware device.
    \param pInput Pointer to user filled structure describing the desired surface.
    \param pOutput Pointer to CMM filled structure describing the surface (includes a hSurf).
*/
CMM_RETURNCODE __stdcall CMMAllocSurface    (  
                                            CMM_HDEVICE             hDevice, 
                                            CMM_SURF_DESCRIPTOR     *pInput, 
                                            CMM_SURF_INFO           *pOutput
                                            );


/** Frees resources allocated for the desired surface.

    Free the resources associated with the given surface.  

    CMM_OK is returned upon success and an error condition otherwise.  

    A free of a Z surface will free any Z-Mask or Hi-Z memory associated with the surface.

    All allocated surfaces (through call to CMMAllocSurface) MUST have a matching call to CMMFreeSurface.
    If a given surface is lost, the client may choose to free the surface (CMMFreeSurface) or recover
    the surface (CMMRecoverSurface).  If a surface is recovered, the original hSurface need not be freed;
    but, if the Surface is simply unrecoverable, the client must call CMMFreeSurface.

    \param hDevice Handle of the target hardware device.
    \param pInput Pointer to user filled structure describing the surface.
*/
CMM_RETURNCODE __stdcall CMMFreeSurface     (
                                            CMM_HDEVICE             hDevice, 
                                            CMM_FREESURF_INPUT      *pInput
                                            );

/** Client request for information regarding a given surface.

    Clients can use this routine to acquire a surface_info structure given a
    CMM handle to a Surface. 

    To Query information about the Primary surface for the given device,
    simply pass in NULL for the hInput parameter.

    Clients should Query all FB surfaces not marked as "NON_LOSABLE" after a mode
    set to make sure the surface has not been lost.
    If the surface is lost, clients may choose to try and recover the surface
    with a call to CMMRecoverSurface.

    Note, surfaces are never lost due to hibernation; but, the contents will only be preserved
    if the surface is marked as CMM_SURFDESC_FLAG_MEMSTATE_RECOVERABLE.

    CMM_OK is returned upon success and an error condition otherwise.

    \param hDevice Handle of the target hardware device.
    \param pInput Pointer to a client filled structure that defines the CMM surface.
    \param pOutput Pointer to a CMM_SURF_INFO structure defining the surface.
     See CMMAllocSurface description of “pOutput” for more information.

*/
CMM_RETURNCODE __stdcall CMMQuerySurfaceInfo(
                                            CMM_HDEVICE             hDevice, 
                                            CMM_SURF_REQUEST        *pInput, 
                                            CMM_SURF_INFO           *pOutput 
                                            );
                                            
/** Client request to allocate ASIC cache resources (such as Z mask memory) against a surface.
    Note, this also can be done during the call to CMMAllocSurface.

    \param hDevice Handle of the target hardware device.
    \param pInput – Pointer to a client filled structure that defines the CMM surface to
    allocate the caches for.
    \param pOutput Pointer to a CMM_SURF_INFO structure defining the surface.
    See CMMAllocSurface description of “pOutput” for more information.
*/
CMM_RETURNCODE __stdcall CMMAllocCache      (  
                                            CMM_HDEVICE             hDevice, 
                                            CMM_SURF_REQUEST        *pInput, 
                                            CMM_SURF_INFO           *pOutput
                                            );

/** Client request to free ASIC cache resources (such as Z mask memory) against a surface.
    Note, this also can be done during the call to CMMFreeSurface.

    \param hDevice Handle of the target hardware device.
    \param pInput Pointer to a client filled structure that defines the CMM surface
    to free the caches from.
*/
CMM_RETURNCODE __stdcall CMMFreeCache       (  
                                            CMM_HDEVICE             hDevice, 
                                            CMM_SURF_REQUEST        *pInput
                                            );

/** Client request to recover a lost surface.

    Clients can use this routine to recover a lost surface due to a desktop mode change. 

    Recovered surfaces will retain the same characteristics as the original surface;
    however, the FB location (and possible Z resources) may be different.

    Note, surfaces are never lost due to hibernation; but, the contents will only be preserved
    if the surface is marked as CMM_SURFDESC_FLAG_MEMSTATE_RECOVERABLE.

    CMM_OK is returned upon success and an error condition otherwise. 

    \param hDevice Handle of the target hardware device.
    \param pInput Pointer to a client filled structure that defines the lost CMM surface.
    \param pOutput Pointer to a CMM_SURF_INFO structure defining the surface.
    See CMMAllocSurface description of “pOutput” for more information.
*/
CMM_RETURNCODE __stdcall CMMRecoverSurface(
                                            CMM_HDEVICE             hDevice, 
                                            CMM_SURF_REQUEST        *pInput, 
                                            CMM_SURF_INFO           *pOutput 
                                            );


/** Prepare a surface for host access if the surface is tiled.
    Clients should use this routine if host access is desired on a given surface 
    and the surface is tiled.  Once host access is complete,
    the client should call CMMFreeAperture.

    CMM_OK is returned upon success and an error condition otherwise.

    \param hDevice Handle of the target hardware device.
    \param pInput pointer to client filled structure describing the aperture to set.
*/
CMM_RETURNCODE __stdcall CMMSetAperture     (
                                            CMM_HDEVICE             hDevice, 
                                            CMM_APERTURE_DESCRIPTOR *pInput
                                            );

/** Frees previously assigned aperture(s).

    Clients need to have matching calls to CMMFreeAperture for all calls to
    CMMSetAperture when host access is complete.

    Note, if multiple apertures are associated with this surface, all the apertures will be freed.

   CMM_OK is returned upon success and an error condition otherwise.

    \param hDevice Handle of the target hardware device.
    \param pInput pointer to client filled structure describing the aperture to free.

*/
CMM_RETURNCODE __stdcall CMMFreeAperture    (
                                            CMM_HDEVICE             hDevice, 
                                            CMM_APERTURE_DESCRIPTOR *pInput);



/** Returns general information about the CMM.

    Reports general CMM information back to the calling client.

    CMM_OK is returned upon success and an error condition otherwise.

    \param hDevice Handle of the target hardware device.
    \param pOutput pointer to CMM filled structure describing the state of the CMM
*/
CMM_RETURNCODE __stdcall CMMGetGeneralInfo  (
                                            CMM_HDEVICE             hDevice, 
                                            CMM_GENERAL_INFO        *pOutput
                                            );

/** Returns information on each CMM pool.

    Reports pool information back to the calling client.

    CMM_OK is returned upon success and an error condition otherwise.

    \param hDevice Handle of the target hardware device.
    \param pInput pointer to user filled structure describing options on obtaining pool information.
    \param pOutput pointer to CMM filled structure describing the pool information.
*/
CMM_RETURNCODE __stdcall CMMGetPoolInfo  (
                                            CMM_HDEVICE             hDevice, 
                                            CMM_POOL_INFO_REQUEST   *pInput,
                                            CMM_POOL_INFO           *pOutput
                                         );

/** Locks an area of virtual memory into either PCI or AGP space
    and returns an ASIC accessible memory controller address.

    Clients should use this routine if a hardware mapping of a system memory address is desired.
    Once the mapping is no longer necessary, the client should call CMMUnlockMemory.

    Memory can be locked into either PCI or AGP space.
    If CMM_LOCK_FLAG_AGP and CMM_LOCK_FLAG_PCI are both specified,
    this routine will attempt to lock the memory into AGP space.
    It will NOT attempt to lock the memory into PCI space.

    When locking memory into AGP space, it is possible that only a portion of the
    requested memory will be locked. If that is the case,
    this function will return CMM_ERROR_INCOMPLETE and dwSize will indicate how
    many bytes were actually locked.
    The client can then call this function again (specifying the handle returned
    in the first call) to lock more of the memory.
    The function will return a new memory controller address (in dwMCAddress),
    which will NOT be contiguous with the previous memory controller address.
    The function may again return CMM_ERROR_INCOMPLETE indicating that the entire block
    is still not locked down. After the client has finished using the locked memory,
    the client only needs to call CMMUnlockMemory once to unlock all of the memory for
    the specified handle.

    In the preceding case, if the client specified CMM_LOCK_FLAG_CONTIGUOUS and the CMM
    could not map the entire block so that it is contiguous in AGP space, the block will
    be locked into PCI space. The output dwLockFlags will indicate which memory space the
    block has been locked into.

    CMM_OK is returned upon success and an error condition otherwise.

    \param hDevice Handle of the target hardware device.
    \param pInput Pointer to user-filled structure describing the lock request.
    \param pOutput Pointer to CMM-filled structure describing the lock result.
*/
CMM_RETURNCODE __stdcall CMMLockMemory      (
                                            CMM_HDEVICE                 hDevice, 
                                            CMM_LOCK_MEMORY_INPUT       *pInput,
                                            CMM_LOCK_MEMORY_OUTPUT      *pOutput
                                            );

/** Unlocks a previously locked area of virtual memory.

    Unlocks memory previously locked by CMMLockMemory.

    CMM_OK is returned upon success and an error condition otherwise.

    \param hDevice Handle of the target hardware device.
    \param pInput Pointer to user filled structure describing the unlock request.
*/
CMM_RETURNCODE __stdcall CMMUnlockMemory    (
                                            CMM_HDEVICE                 hDevice, 
                                            CMM_UNLOCK_MEMORY_INPUT     *pInput
                                            );


CMM_RETURNCODE __stdcall CMMAllocSurface1D  (  
                                            CMM_HDEVICE             hDevice, 
                                            CMM_LINEAR_ALLOCATION   *pInput, 
                                            CMM_SURF_INFO           *pOutput
                                            );


/** Requests that CMM reserve a token-signified resource for use by the client.
    At present, the resources available through this interface are R400
    real-time streams and Viz-query IDs.
 
    The client may request as many resources as it requires in a single call.  
    CMM will fail the call if it cannot assign all of the tokens requested,
    returning CMM_ERROR_TOO_FEW_TOKENS to signal that the client may try again
    with a smaller request or CMM_ERROR_NO_TOKEN if the cupboard is
    bare.
    
    The client may alternatively request resource tokens one at a time, 
    calling the interface repeatedly.  In this case client should set
    the dwCount field of the RESOURCE_DESCRIPTOR is set to 1.  CMM will fail
    the call with CMM_ERROR_NO_TOKEN if no assignment is possible.  

    In either case, client must allocate a buffer of RESOURCE_DESCRIPTOR.dwCount
    DWORDs and submit a pointer to that buffer in RESOURCE_DESCRIPTOR.pResource.
 
    Upon return, a resource ID will be written into dwCount elements of the
    DWORD array to which RESOURCE_DESCRIPTOR.pResource points.  In case CMM
    cannot assign all dwCount IDs to the client, CMM_TOKEN__UNAVAILABLE will
    be written to all dwCount elements of the array.
  
    CMM_OK is returned upon assignment of all requested IDs.
 
    \param hDevice Handle of the target hardware device.
    \param pInput  Pointer to the RESOURCE_DESCRIPTOR structure specifying the resource.

*/
CMM_RETURNCODE __stdcall CMMAssignResource(
                                           CMM_HDEVICE             hDevice,
                                           CMM_RESOURCE_DESCRIPTOR *pInput
                                           );

/** Releases resources that have been encumbered through CMMAssignResource().
 
    The client specifies the IDs of the resources to be released in an
    array pointed to by the pResource field of the RESOURCE_DESCRIPTOR.
    The number of elements in the array must be specified in the dwCount
    field.
 
    The client may release as many resources as it wishes in a single call.  
    The client may alternatively release resource tokens one at a time,
    calling the interface repeatedly. See CMMAssignResource for more details.
   
    CMM_OK is returned upon success and an error condition otherwise.
 
    \param hDevice Handle of the target hardware device.
    \param pInput  Pointer to the RESOURCE_DESCRIPTOR structure specifying the resource.
*/
CMM_RETURNCODE __stdcall CMMReleaseResource(
                                           CMM_HDEVICE             hDevice,
                                           CMM_RESOURCE_DESCRIPTOR *pInput
                                           );

#endif // BUILDING_CMM

#ifdef __cplusplus
}
#endif

#endif /*_CMM_H*/
//@}




//    
//  $Workfile: atisurfp.h $
//  $Revision: 16 $
//
//  Description:
//
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

 
#ifndef _ATISURFP_H_

#define _ATISURFP_H_

#include "atiddhsl.h"
#include "atidxinc.h"
#include <d3dumddi.h>

#define ATIMAXBLTQUEUE  12
#define MSBLTQUEUE      3

/*
 * ATISurfInfo structure contains all the ATi specific data
 * that is relevant to each DirectDraw surface.
*/
typedef struct _ATISURFINFO
{
    DWORD dwSize;
    DWORD dwSurfFlags;       // Holds surface specifics (i.e. does surface 
                             // need CRTC syncronization, does surface have timestamp etc.)
    DWORD dwSurfFlags2;      // For future use!
    DWORD dwVtxBuffFlags;    // Used to hold specific info about vertex buffer surface

    // Each Command buffer has a unique index. If a surface is used in a CB, the surface
    // is stamped with this CB's index. If a surface is involved in page flip, the surface 
    // is stamped and the index is safed in dwTSFlipIndex. 
    DWORD dwTSIndex;         // hold timestamp index which is equal a CB's index
    DWORD dwTSFlipIndex;     // hold timestamp flip index which is equal a CB's index

    DWORD dwTSWrapStamp;     // holds the Dev's dwCBWrapStamp at when the surf was timestamped
    DWORD dwTSFlipWrapStamp; // holds the Dev's dwCBWrapStamp at when the surf was flip timestamped

    DWORD_PTR dwSurfOffset;  // This value holds the surface offset from the framebuffer or AGP
                             // aperture. NOTE: This is offset is a BYTE offset
    DWORD dwSurfPitch;       // This pitch value is again applicable to every surface 
    DWORD dwSurfPixFrmt;     // Pixel format of the surface(RAGE128 specific)
    DWORD dwColorPitch;      // Holds the color pitch used in the RB3D_COLORPITCH register
    DWORD dwColorFormat;     // Holds the color format used in the RB3D_CNTL register
    DWORD dwBytesPerPixel;   // Holds the bytes per pixel.
    DWORD dwTiledPtchSel;    // This value is *ONLY* valid if the surface is tiled. If the surface is
                             // tiled, this value will hold the TiledPitchSel value(i.e. 1=64bytes etc).
    DWORD dwHeap;            // Heap that was actually used to allocate the video memory
                             // NOTE: We need to use this when destroying the surface!.
    union
    {
#ifdef UMD
        D3DKMT_HANDLE  hAllocation; // Allocation handle
#endif
        FLATPTR fpVidMem;    // This value is used to hold the original fpVidMem
    };
    ULONG_PTR hSurface;      // Cache Handle for win2k, null for win9x.
    LPVOID lpRing3Addr;      // linear address in ring3 space, on win9x, this is the same as fpVidMem.
                             // On win2k, it's the mapped address if the memory is in agp, 
                             //           0 if the memory is in local vidmem.
    DWORD dwVPEBufferMask;   // READ ONLY, it will can be written only by the VPE HAL!!!!!     

    DWORD_PTR dwTexMCOffset; // This value is used to store the modified or  AGP surface
                             // offset!!                
    DWORD dwTexelFormat;     // Holds the texel format used in the Rage 5 PP_TXFORMAT_0 register
    DWORD dwTexLOG2Pitch;    // Texture LOG2 pitch.
    DWORD dwTexLOG2Size;     // This field holds the LOG2 size of the textre. If the texture
                             // is not square, this will be the LOG2 size of the largest dimension.
    DWORD dwTexLOG2Width;    // This field holds the LOG2 width of the texture.
    DWORD dwTexLOG2Height;   // This field holds the LOG2 height of the texture.
    FLATPTR MipOffsets[12];
    struct _CMDBUFF* lpCmdBuff;

    // Blt Queue Implementation introduced DX8
    DWORD bltQueue[ATIMAXBLTQUEUE];
    DWORD dwBltQueueIndex;
    DWORD dwBltQueueSize;

#if (DIRECT3D_VERSION >= 0x0900)
    // for light weight mipmap.
    ULONG_PTR	 MipfpVidMem[12];
#endif

    DWORD dwFCCDepthOffset;  
    DWORD dwFCCHeight;      

    ULONG_PTR hSurfaceBaseMipMap;      // CMM Handle for BaseMipMap surface 

#if (DIRECT3D_VERSION >= 0x0900)
    DWORD dwSrcXOffset;        // Source X offset 
    DWORD dwSrcYOffset;        // Source Y offset
    DWORD dwDstXOffset;        // Destination X offset
    DWORD dwDstYOffset;        // Destination Y offset
    float flXFactor;           // X stretch factor
    float flYFactor;           // Y stretch factor
#endif
}ATISURFINFO, *LPATISURFINFO;


/*
 * GetSurfInfo:
 * This macro returns the LPATISURFINFO ptr (if there is one). 
 */
_inline LPATISURFINFO GetATISurfInfoPtr(LPDDRAWI_DDRAWSURFACE_LCL lpDDSurf)
{
  //HSLASSERT( lpDDSurf->lpGbl->dwReserved1 != 0 );
  return  ((LPATISURFINFO) (lpDDSurf->lpGbl->dwReserved1));
}

/****************************************************************************/
//** Valid values for the dwSurfFlags field of the ATISurfInfo structure.
/****************************************************************************/


//Indicates whether or not a DDRAW surface has a TimeStamp
//associated with or not
#define     SURF_HAS_TSTAMP         0x00000001

//Indicates whether or not a DDRAW surface needs to be 
//syncronized with the verical blank. This is only used
//for "flippable" surfaces (i.e. it causes a GUI lock until VBLANK).
// No longer used ... superceded by HSL_SURF_NEEDS_CRTC_SYNC
//#define     SURF_NEEDS_CRTC_SYNC    0x00000004

//Thid flag indicates whether or not the surface is a YUV planar OVERLAY. If
//flag is set, this also indicates that the Y.V and U offsets of ATISURFINFO
//structure are valid!
#define     SURF_IS_YUVPLANAR       0x00000008

//This flag indicates whether or not the surface is in a tiled format!!
// No longer used ... superceded by HSL_SURF_IS_TILED
//#define     SURF_IS_TILED           0x02000000

//Indicates whether or not a DDRAW surface has a TimeStamp associated
//with a flip operation
//associated with or not
#define     SURF_HAS_FLIP_TSTAMP    0x00000020


//Indicates whether or not a TEXTURE surface has a power of two size
#define     SURF_IS_POWER_OF_TWO    0x00000080

//This flag indicates whether or not the surface is YUV.
#define     SURF_IS_YUV             0x00000100

//This flag indicates whether or not the surface is microtiled (textures only).
// No longer used ... superceded by HSL_SURF_IS_MICROTILED
//#define     SURF_IS_MICROTILED      0x40000000

//This flag indicates whether or not the surface is palettized.
#define     SURF_IS_PALETTIZED      0x00000400

#define     SURF_IS_PRIMARY         0x00001000

#define     SURF_IS_FSBACKBUFFER    0x00002000

#define     SURF_IS_DYNAMIC         0x00010000

// This flag indicates that the surface has stretch factor
#define     SURF_HAS_SFACTOR        0x00020000

//How many ATISURFINFO blocks can we have
#define MAX_ATISURFINFO_ARRAYS   256

//How much memory is allocated for each ATISURFINFO array
#define ATISurfInfoArraySize   (1024*256)

//We should make sure that each ATISURFINFO struct starts on a 32byte boundary 
#define ATISurfInfoSizeAligned (((sizeof(ATISURFINFO))+31) & ~31)

//How many ATISURFINFO structures can be allocated in each array
#define ATISurfInfosPerBlock   ((ATISurfInfoArraySize) / ATISurfInfoSizeAligned)

// Indicates blt queue entry is invalid.
#define EMPTY_BLTQUEUE_ENTRY 0xFFFFFFFF

#endif


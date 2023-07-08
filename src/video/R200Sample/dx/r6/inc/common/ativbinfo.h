

//    
//  Workfile: ativbinfo.h
//
//  Description:
//      Vertex Buffer declarations and definitions.
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _ATIVBINFO_H
#define _ATIVBINFO_H
/*
 * ATIVERTEXBUFFER structure contains all the ATi specific data
 * that is relevant to each local vertex buffer.
*/
#include "atidxinc.h"
#include "atiddhsl.h"

// Much like D3DVECTOR, but contains a w component.
typedef struct _ATIVECTOR
{
  float x;
  float y;
  float z;
  float w;
} ATIVECTOR, *LPATIVECTOR;

typedef enum
{
    ATI_SURFACE       = 1,
    ATI_VERTEXBUFFER  = 2,          // Vertex buffers and index buffers
    ATI_FORCE_DWORD   = 0x7fffffff, /* force 32-bit size enum */
} ATIHANDLETYPE;

typedef struct _ATIVERTEXBUFFER
{
    // This must be the first member of this structure
    // Surfaces and VB share the surface list. This
    // DWORD allows us to tell if any given pointer
    // in that list points to a surface or a VB.
    ATIHANDLETYPE  handleType;

    DWORD      dwSurfFlags;     // Kept for compatiblity with ATISURFINFO 

    // dwVbuffPendingCB_ID means that this surface is used by a CB 
    // with ID = dwVbuffPendingCB_ID. This CB is either not submitted 
    // or it is submitted but we don't know if its time is elasped. 
    // Each surface can at most in one un-submitted CB!
    // Also, because the CB_ID is reused, it is possible that when
    // we later try to see if the CB_ID has elapsed, it is possible that
    // the information has been overwritten. The WrapStamp is used to
    // test for this.

    DWORD      dwVbuffPendingCB_ID;     
    DWORD      dwVbuffCBWrapStamp;

    // Context index to find context pointer in lpD3DDevice.
    DWORD      dwhContextID;             

    // WARNING!!!! The above section must match the top half of the
    // ATISURFINFO exactly, they both use the same macros!!!

    DWORD      dwBuffFlags;        //Used to hold specific info about vertex buffer surface
    DDHSLVIDMEMDATA   sVtxListData;  // Structure returned from sDdHslVideoMemoryAlloc
    LPVOID     lpVtxList;          //Pointer to Vertex List created by QS

    //The equivalent of lpVtxList in Ring3 space. For win9x, this is the same as
    //lpVtxList. For win2k, it's the mapped addr. if the vb is in agp, 0 if vb is in 
    //local vidmem.
    LPVOID     lpVtxListRing3;     

    INT	       QS_ListOffset;	    //offset from the base of the GART
    ULONG_PTR  QS_HInList;         //Handle returned by QS
    DWORD      QS_ListSize;        //Size of list as allocated

    DWORD      dwRequestedListSize; // Size of list as requested by the client

    INT	       QS_OrigListOffset;

    LPDDRAWI_DIRECTDRAW_LCL lpDDLcl;
    LPDDRAWI_DIRECTDRAW_GBL lpDDGbl;

    DWORD      dwBytesRemaining;   //Number of bytes remaining in vertex buffer
    LPBYTE     lpVbSpace;          // byte pointer to next place to write vertices

    DWORD                    dwSysVBListSize;

    DWORD                    dwHandle;
    ATIVECTOR pvecBoundingBox[8];

    DWORD                   dwStreamOffset;  // the stream offset in bytes from D3DHAL_DP2SETSTREAMSOURCE2

} ATIVERTEXBUFFER, *LPATIVERTEXBUFFER;

__inline LPATIVERTEXBUFFER GetSurfVBuffPtr(LPDDRAWI_DDRAWSURFACE_LCL lpDDSurf)
{
    return( (LPATIVERTEXBUFFER)(lpDDSurf->dwReserved1) );
}

__inline LPVOID GetSurfVBuffRing3Addr(LPDDRAWI_DDRAWSURFACE_LCL lpDDSurf)
{
    HSLASSERT( GetSurfVBuffPtr(lpDDSurf) != 0 );
    return GetSurfVBuffPtr(lpDDSurf)->lpVtxListRing3;
}

//Functions in ddexbuf.c
DWORD CALLBACK CanCreateExecuteBuffer32(LPDDHAL_CANCREATESURFACEDATA lpd);
DWORD CALLBACK CreateExecuteBuffer32(LPDDHAL_CREATESURFACEDATA  pcsd);
DWORD CALLBACK DestroyExecuteBuffer32(LPDDHAL_DESTROYSURFACEDATA lpd);
DWORD CALLBACK LockExecuteBuffer32(LPDDHAL_LOCKDATA lpd);
DWORD CALLBACK UnlockExecuteBuffer32(LPDDHAL_UNLOCKDATA lpd);

#endif //_ATIVBINFO_H


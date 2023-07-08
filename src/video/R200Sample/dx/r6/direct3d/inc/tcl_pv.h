

//    
//  Workfile: tcl_pv.h
//
//  Description: TCL Process Vertices
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 2000, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _TCL_PV_H__
#define _TCL_PV_H__

BOOL
TclProcessVertices( LPATID3DCNTX pCtxt, LPATIVERTEXBUFFER pProcVB, LPATIVERTEXBUFFER pSrcVB, 
                    LPDWORD pdwFVFStride, LPDWORD pdwFVFSize, LPDWORD pdwFVFType, LPDWORD pdwPostColorSize,
                    DWORD dwNumVertices, WORD wStartIndex, WORD wStopIndex );




#define TCLPV_LDFLAGS_NO_NORMAL  0x00000001

typedef struct _TCLPVLIGHTINGDATA
{
  // Misc. flags
  DWORD           dwFlags;

  // Input Vertex Data
  LPATIVECTOR     pvVtxM;
  LPATIVECTOR     pvNormM;
  LPATIFLOATCOLOR pfVtxDiffuse;
  LPATIFLOATCOLOR pfVtxSpecular;


  // Vertex Stride Data
  DWORD           dwVtxStride;
  DWORD           dwNormStride;
  DWORD           dwDiffuseStride;
  DWORD           dwSpecularStride;

  // Output Color
  LPDWORD         pdwOutputColor;
  DWORD           dwOutputStride;

  // Scratch space floating point lit colors
  ATIFLOATCOLOR   fLitDiffuse;
  ATIFLOATCOLOR   fLitSpecular;

  // Materials and global ambient
  ATIFLOATCOLOR   fGlobalAmbient;
  ATIFLOATCOLOR   fMatEmissive;
  ATIFLOATCOLOR   fMatAmbient;
  ATIFLOATCOLOR   fMatDiffuse;
  ATIFLOATCOLOR   fMatSpecular;

  TclMaterialSrc  tclMaterialSrc;  

  DWORD           dwNumVerticesInVb;


    E_TCL_MAT_SRC   eMatEmiSrc;
    E_TCL_MAT_SRC   eMatAmbSrc;
    E_TCL_MAT_SRC   eMatDiffSrc;
    E_TCL_MAT_SRC   eMatSpecSrc;

} TCLPVLIGHTINGDATA, *LPTCLPVLIGHTINGDATA;

#define LVFLAGS_DIFFUSE         0x00000001L
#define LVFLAGS_SPECULAR        0x00000002L
#define LVFLAGS_CLIPPED         0x00000004L
#define LVFLAGS_VERTEXFOG       0x00000008L
#define LVFLAGS_VTXFOG_RANGE    0x00000010L


#endif // _TCL_PV_H__


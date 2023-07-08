

//
//  Workfile: atidrawprim.h
//
//  Description: Common header for routines that implement DrawPrimitives232()
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _ATI_DRAWPRIM_H
#define _ATI_DRAWPRIM_H

#include <DriverSpecs.h>

__user_code

// external includes

#include "tplates.h"
#include "d3d_hw_enum.h"

// private D3D includes

#include "writerendstate.h"
#include "d3ddevice.h"
//#include "rage6_offset.h"
#include "radeon.h"

typedef DWORD (__fastcall *PDP2FUNCTION)(LPD3DHAL_DRAWPRIMITIVES2DATA lpdp2d, LPATID3DCNTX pCtxt);
DWORD __fastcall DrawPrimitives232Dx7(LPD3DHAL_DRAWPRIMITIVES2DATA lpdp2d, LPATID3DCNTX pCtxt);
DWORD __fastcall DrawPrimitives232Dx8(LPD3DHAL_DRAWPRIMITIVES2DATA lpdp2d, LPATID3DCNTX pCtxt);

typedef struct _DP2FLAGS
{
    BYTE        uData : 2,              // applicable data
                bStateOp : 1,           // is state
                bDraw7Op : 1,           // is DX7 drawing
                bDraw8Op : 1,           // is DX8 drawing
                bNonDraw8 : 1,          // is non drawing DX8 op
                bUnused1 : 1,           //
                bUnused2 : 1;           //
} DP2FLAGS;

#define bDraw7OpImm bNonDraw8

extern DP2FLAGS DP2Flags[256];

HRESULT __fastcall DP2DrawStates(LPD3DHAL_DRAWPRIMITIVES2DATA lpdp2d,
                                 LPATID3DCNTX pCtxt,
                                 LPD3DHAL_DP2COMMAND *lppIns,
                                 LPD3DHAL_DP2COMMAND lpInsEnd);

//
// Nomenclature for drawprim render functions
//--------------------------------------------
//
// DX7 Runtime can pass us a variety of opcodes for different primitive types.
// An effort has been made to name the render routines to indicate both
// the meaning of the opcode from the runtime and the implementation choice.
//
// Render routine names have the following construction:
//     <FillMode><VertexSource><Pm4Func><PrimType><PrimOrg>
//
// FillMode = Solid, WFrame or Point
// VertexSource = Imm, VbDir (vbuff direct) or VbIdx (vbuff indexed)
// Pm4Func      = Cbvd (cbuff vertex data) or Hwvb (hw vbuff)
// PrimType     = Tri, Line or Point
// PrimOrg      = List, Strip or Fan
//
// eg SolidVbdirCbvdTriFan() is a routine for solid filled triangle fans, where
//    the runtime gives us an ordered (non-indexed) vertex buffer and we copy
//    the vertices to a PM4 command buffer.
//
//    SolidVbdirHwvbTriFan() would implement the same call from the run time,
//    but use a hw vertex buffer for the drawing.

// Max _D3DHAL_DP2OPERATION enum is currently 43, so we allow up to 63
// entries for the function pointer table.
// Use bit 7 (or in 0x40) to select vertex buffer functions as needed,
// Table will be reloaded when draw mode changes from solid
// to Wireframe or Point, so no need for larger table.
// The additional 64 entries is for primitives culled by viewport culling
#define ATI_MAX_DRAW_FUNCS (128+64)
#define ATI_DTBL_SIZE (ATI_MAX_DRAW_FUNCS*sizeof(PRENDTRI))
#define ATI_MAX_PRIM_TYPE 64
#define ATI_VVIT_SIZE (ATI_MAX_DRAW_FUNCS*sizeof(PVALIDATETRI))

// enum used instead of true/false so it can be added to the opcode
// for DrawTable lookup without additional operations
typedef enum _EATI_VTX_LOC {
    ATI_CBVD = 0x00L,
    ATI_HWVB = 0x40L,
    ATI_CULLED = 0x80L
} EATI_VTX_LOC;

#define ATI_MAX_DRAW_FUNCS_DX8 8
#define ATI_MAX_IDX_DRAW_FUNCS_DX8 16
#define ATI_DP_TABLE_SIZE_DX8 (ATI_MAX_DRAW_FUNCS_DX8*sizeof(PDX8RENDTRI))
#define ATI_DIP_TABLE_SIZE_DX8 (ATI_MAX_IDX_DRAW_FUNCS_DX8*sizeof(PDX8RENDIDXTRI))
#define ATI_PS_TABLE_SIZE_DX8 (ATI_MAX_DRAW_FUNCS_DX8*sizeof(PDX8RENDPS))
#define ATI_IPS_TABLE_SIZE_DX8 (ATI_MAX_IDX_DRAW_FUNCS_DX8*sizeof(PDX8RENDIDXPS))

typedef enum _EATI_VTX_LOC_DX8 {
    ATI_CBVD_DX8 = 0,
    ATI_HWVB_DX8 = 4
} EATI_VTX_LOC_DX8;

typedef enum _EATI_IDX_LOC_DX8 {
    ATI_CBID_DX8      = 0,
    ATI_HWIB_DX8      = 8
} EATI_VTX_LOC_DX8;


#define GET_INDEX_AS_DWORD(PFROM, SIZE) (DWORD)(SIZE == 2)?(*(LPWORD)(PFROM)):(*(LPDWORD)(PFROM))

// ValidateVertexIndex prototypes
BOOL bValidateAlwaysPass(LPD3DHAL_DP2COMMAND lpIns, DWORD dwVertexLength);
BOOL bValidatePointList(LPD3DHAL_DP2COMMAND lpIns, DWORD dwVertexLength);
BOOL bValidateIndexedLineList(LPD3DHAL_DP2COMMAND lpIns, DWORD dwVertexLength);
BOOL bValidateIndexedTriList(LPD3DHAL_DP2COMMAND lpIns, DWORD dwVertexLength);
BOOL bValidateLineList(LPD3DHAL_DP2COMMAND lpIns, DWORD dwVertexLength);
BOOL bValidateLineStrip(LPD3DHAL_DP2COMMAND lpIns, DWORD dwVertexLength);
BOOL bValidateIndexedLineStrip(LPD3DHAL_DP2COMMAND lpIns, DWORD dwVertexLength);
BOOL bValidateTriList(LPD3DHAL_DP2COMMAND lpIns, DWORD dwVertexLength);
BOOL bValidateTriFanStrip(LPD3DHAL_DP2COMMAND lpIns, DWORD dwVertexLength);
BOOL bValidateIndexedTriFanStrip(LPD3DHAL_DP2COMMAND lpIns, DWORD dwVertexLength);
BOOL bValidateIndexedTriList2(LPD3DHAL_DP2COMMAND lpIns, DWORD dwVertexLength);
BOOL bValidateIndexedLineList2(LPD3DHAL_DP2COMMAND lpIns, DWORD dwVertexLength);

// drawprim prototypes

// Null function to catch unexpected OpCodes

LPD3DHAL_DP2COMMAND
UnknownOpCodeFunc(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                   LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                   DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum );

// Solid Triangles

LPD3DHAL_DP2COMMAND
SolidImmCbvdTriFan(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                   LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                   DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
SolidVbdirCbvdTris(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                   LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                   DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
SolidVbidxCbvdTriList(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                      LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                      DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
SolidVbidxCbvdTriStrip(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                       LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                       DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
SolidVbidxCbvdTriFan(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                     LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                     DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
SolidVbidxHwvbTriList(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                      LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                      DWORD dwStampCount, DWORD dwVertexNum );

LPD3DHAL_DP2COMMAND
SolidVbidxHwvbTriList2(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                       LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                       DWORD dwStampCount, DWORD dwVertexNum );

LPD3DHAL_DP2COMMAND
SolidVbidxHwvbTriStrip(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                       LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                       DWORD dwStampCount, DWORD dwVertexNum );

LPD3DHAL_DP2COMMAND
SolidVbidxHwvbTriFan(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                     LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                     DWORD dwStampCount, DWORD dwVertexNum );

LPD3DHAL_DP2COMMAND
SolidVbdirHwvbTriList(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                      LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                      DWORD dwStampCount, DWORD dwVertexNum );

LPD3DHAL_DP2COMMAND
SolidVbdirHwvbTriStrip(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                       LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                       DWORD dwStampCount, DWORD dwVertexNum );

LPD3DHAL_DP2COMMAND
SolidVbdirHwvbTriFan(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                     LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                     DWORD dwStampCount, DWORD dwVertexNum );

// Lines

LPD3DHAL_DP2COMMAND
SolidImmCbvdLineList(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                     LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                     DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
SolidVbdirCbvdLineList(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                       LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                       DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
SolidVbdirCbvdLineStrip(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                        LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                        DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
SolidVbidxCbvdLineList(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                       LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                       DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
SolidVbidxCbvdLineStrip(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                        LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                        DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
SolidVbidxHwvbLineList(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                       LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                       DWORD dwStampCount, DWORD dwVertexNum );

LPD3DHAL_DP2COMMAND
SolidVbidxHwvbLineList2(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                        LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                        DWORD dwStampCount, DWORD dwVertexNum );

LPD3DHAL_DP2COMMAND
SolidVbidxHwvbLineStrip(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                        LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                        DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
SolidVbdirHwvbLineList(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                       LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                       DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
SolidVbdirHwvbLineStrip(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                        LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                        DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

// Points

LPD3DHAL_DP2COMMAND
SolidVbdirCbvdPointList(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                        LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                        DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
SolidVbdirHwvbPointList(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                        LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                        DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

// PointSprites
void RenderPointSprites(LPATID3DCNTX pCtxt, DWORD dwPrimType, DWORD dwNumPrimitives,
                        DWORD dwStampCount);

void RenderIndexedPointSprites(LPATID3DCNTX pCtxt, DWORD dwPrimType,
                               DWORD dwIndexByteOffset, DWORD dwNumPrimitives,
                               DWORD dwStampCount);

void RenderOnePointSpriteFromVertexSW(LPATID3DCNTX pCtxt, LPDWORD lpVertices, LPDWORD lpVerticesFlatShading,
                                    DWORD dwStampCount);

void RenderOnePointSpriteFromVertexTCL(LPATID3DCNTX pCtxt, LPDWORD lpVertices, LPDWORD lpVerticesFlatShading,
                                    DWORD dwStampCount);

void RenderOneQuad(LPATID3DCNTX pCtxt, LPDWORD v, DWORD dwStampCount);


void RenderPointListPointSprite(LPATID3DCNTX pCtxt, DWORD dwNumPrimitives,
                                DWORD dwStampCount);

void RenderTriangleListPointSprite(LPATID3DCNTX pCtxt, DWORD dwNumPrimitives,
                                   DWORD dwStampCount);

void RenderTriangleFanPointSprite(LPATID3DCNTX pCtxt, DWORD dwNumPrimitives,
                                  DWORD dwStampCount);

void RenderTriangleStripPointSprite(LPATID3DCNTX pCtxt, DWORD dwNumPrimitives,
                                    DWORD dwStampCount);

void RenderIndxPointListPointSprite(LPATID3DCNTX pCtxt, DWORD dwNumPrimitives,
                                    DWORD dwIndexByteOffset, DWORD dwStampCount);

void RenderIndxTriangleListPointSprite(LPATID3DCNTX pCtxt, DWORD dwNumPrimitives,
                                       DWORD dwIndexByteOffset, DWORD dwStampCount);

void RenderIndxTriangleFanPointSprite(LPATID3DCNTX pCtxt, DWORD dwNumPrimitives,
                                      DWORD dwIndexByteOffset, DWORD dwStampCount);

void RenderIndxTriangleStripPointSprite(LPATID3DCNTX pCtxt, DWORD dwNumPrimitives,
                                        DWORD dwIndexByteOffset, DWORD dwStampCount);

// Wireframe Triangles, with vertices in command buffer

LPD3DHAL_DP2COMMAND
WframeImmCbvdTriFan(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                    LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                    DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
WframeVbdirCbvdTris(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                    LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                    DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
WframeVbidxCbvdTriList(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                       LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                       DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
WframeVbidxCbvdTris(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                    LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                    DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

// Wireframe Triangles, with vertices in hardware vertex buffer

LPD3DHAL_DP2COMMAND
WframeVbdirHwvbTris(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                    LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                    DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
WframeVbidxHwvbTriList(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                       LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                       DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
WframeVbidxHwvbTris(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                    LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                    DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

// PointMode Triangles, with vertices in command buffer

LPD3DHAL_DP2COMMAND
PointImmCbvdTriFan(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                    LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                    DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
PointVbdirCbvdTris(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                    LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                    DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
PointVbidxCbvdTris(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                    LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                    DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

// PointMode Triangles, with vertices in hardware vertex buffer

LPD3DHAL_DP2COMMAND
PointVbdirHwvbTris(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                   LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                   DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

LPD3DHAL_DP2COMMAND
PointVbidxHwvbTris(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                   LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                   DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum);

///////////////////////////////////////////////////////////////////////////////////
//
// Viewport culled primtives
//
///////////////////////////////////////////////////////////////////////////////////
LPD3DHAL_DP2COMMAND
CulledVbdirHwvbPointList( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                      LPD3DTLVERTEX lpVertices, DWORD dwFVFSize,
                      DWORD dwFVFType, DWORD dwStampCount, DWORD dwVertexNum );
LPD3DHAL_DP2COMMAND
CulledVbdirHwvbLineList( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                         LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                         DWORD dwStampCount, DWORD dwVertexNum );
LPD3DHAL_DP2COMMAND
CulledVbdirHwvbLineStrip( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                          LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                          DWORD dwStampCount, DWORD dwVertexNum );
LPD3DHAL_DP2COMMAND
CulledVbdirHwvbTriList( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                        LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                        DWORD dwStampCount, DWORD dwVertexNum );
LPD3DHAL_DP2COMMAND
CulledVbdirHwvbTriStrip( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                         LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                         DWORD dwStampCount, DWORD dwVertexNum );
LPD3DHAL_DP2COMMAND
CulledVbdirHwvbTriFan( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                       LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                       DWORD dwStampCount, DWORD dwVertexNum );
LPD3DHAL_DP2COMMAND
CulledVbidxHwvbLineList( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                         LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                         DWORD dwStampCount, DWORD dwVertexNum );
LPD3DHAL_DP2COMMAND
CulledVbidxHwvbLineList2( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                         LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                         DWORD dwStampCount, DWORD dwVertexNum );
LPD3DHAL_DP2COMMAND
CulledVbidxHwvbLineStrip( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                          LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                          DWORD dwStampCount, DWORD dwVertexNum );
LPD3DHAL_DP2COMMAND
CulledVbidxHwvbTriList( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                        LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                        DWORD dwStampCount, DWORD dwVertexNum );
LPD3DHAL_DP2COMMAND
CulledVbidxHwvbTriList2( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                         LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                         DWORD dwStampCount, DWORD dwVertexNum );
LPD3DHAL_DP2COMMAND
CulledVbidxHwvbTriStrip( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                         LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                         DWORD dwStampCount, DWORD dwVertexNum );
LPD3DHAL_DP2COMMAND
CulledVbidxHwvbTriFan( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND lpIns,
                       LPD3DTLVERTEX lpVertices, DWORD dwFVFSize, DWORD dwFVFType,
                       DWORD dwStampCount, DWORD dwVertexNum );

HRESULT CopyNonDegenPrims(LPATID3DCNTX pCtxt,
                       DWORD dwPrimCount,
                       D3DPRIMITIVETYPE ePrimType,
                       DWORD dwPm4PrimType,
                       DWORD dwStampCount,
                       DWORD dwIndexBase,
                       LPBYTE lpcIndexCurrent);

void AdjustGuardBandForPointSprite(LPATID3DCNTX pCtxt);

DWORD PsTxCoordWkArdHelper(LPATID3DCNTX pCtxt,
                           LPBOOL lpbTxUnitMask,
                           LPBOOL lpbTxNonPow2Mask);

void PsTxCoordWkArdSaveAndOverWriteRegs(LPATID3DCNTX pCtxt,
                                        BOOL bTxUnitMask,
                                        BOOL bTxNonPow2Mask,
                                        LPDWORD dwOrigTxW,
                                        LPDWORD dwOrigTxH);

void PsTxCoordWkArdWriteCmdBuff(LPDWORD PM4Entries,
                                LPATID3DCNTX pCtxt,
                                BOOL bTexUnitMask,
                                BOOL bTxNonPow2Mask);

void PsTxCoordWkArdRestoreOrigRegs(LPATID3DCNTX pCtxt,
                                   BOOL bTxUnitMask,
                                   BOOL bTxNonPow2Mask,
                                   LPDWORD dwOrigTxW,
                                   LPDWORD dwOrigTxH);

HRESULT DrawDx8SolidSysVB(LPATID3DCNTX pCtxt,
                       DWORD dwPrimCount,
                       D3DPRIMITIVETYPE ePrimType,
                       DWORD dwStampCount);

HRESULT DrawDx8WfPtSysVB(LPATID3DCNTX pCtxt,
                       DWORD dwPrimCount,
                       D3DPRIMITIVETYPE ePrimType,
                       DWORD dwStampCount);

HRESULT DrawDx8SolidHWVB(LPATID3DCNTX pCtxt,
                       DWORD dwPrimCount,
                       D3DPRIMITIVETYPE ePrimType,
                       DWORD dwStampCount);

HRESULT DrawDx8WfPtHWVB(LPATID3DCNTX pCtxt,
                       DWORD dwPrimCount,
                       D3DPRIMITIVETYPE ePrimType,
                       DWORD dwStampCount);

HRESULT DrawDx8IndexedSolidSysVB(LPATID3DCNTX pCtxt,
                              DWORD dwIndexByteOffset,
                              DWORD dwPrimCount,
                              D3DPRIMITIVETYPE ePrimType,
                              DWORD dwStampCount);

HRESULT DrawDx8IndexedWfPtSysVB(LPATID3DCNTX pCtxt,
                              DWORD dwIndexByteOffset,
                              DWORD dwPrimCount,
                              D3DPRIMITIVETYPE ePrimType,
                              DWORD dwStampCount);

HRESULT DrawDx8HwIndexedSolidHWVB(LPATID3DCNTX pCtxt,
                              DWORD dwIndexByteOffset,
                              DWORD dwPrimCount,
                              D3DPRIMITIVETYPE ePrimType,
                              DWORD dwStampCount);

HRESULT DrawDx8IndexedSolidHWVB(LPATID3DCNTX pCtxt,
                              DWORD dwIndexByteOffset,
                              DWORD dwPrimCount,
                              D3DPRIMITIVETYPE ePrimType,
                              DWORD dwStampCount);

HRESULT DrawDx8IndexedSolidHWVBNoDegen(LPATID3DCNTX pCtxt,
                                    DWORD dwIndexByteOffset,
                                    DWORD dwPrimCount,
                                    D3DPRIMITIVETYPE ePrimType,
                                    DWORD dwStampCount);

HRESULT DrawDx8IndexedWfPtHWVB(LPATID3DCNTX pCtxt,
                              DWORD dwIndexByteOffset,
                              DWORD dwPrimCount,
                              D3DPRIMITIVETYPE ePrimType,
                              DWORD dwStampCount);

void DrawDx8ClippedTriFan(LPATID3DCNTX pCtxt,
                          DWORD dwPrimCount,
                          D3DPRIMITIVETYPE ePrimType,
                          DWORD dwStampCount,
                          DWORD dwEdgeFlags);

void DrawDx8WfPtINDX( LPATID3DCNTX pCtxt,
                      DWORD dwPrimCount,
                      D3DPRIMITIVETYPE ePrimType,
                      DWORD dwStampCount,
                      BOOL bUsingIndexBuffer,
                      LPBYTE lpcIndexCurrent );

void DrawDx8WfPtIMMD( LPATID3DCNTX pCtxt,
                      DWORD dwPrimCount,
                      D3DPRIMITIVETYPE ePrimType,
                      DWORD dwStampCount,
                      BOOL bUsingIndexBuffer,
                      LPBYTE lpcIndexCurrent );

void DrawDx8WfPtFlatHwVpFix( LPATID3DCNTX pCtxt,
                             DWORD dwPrimCount,
                             D3DPRIMITIVETYPE ePrimType,
                             DWORD dwStampCount,
                             BOOL bUsingIndexBuffer,
                             LPBYTE lpcIndexCurrent );

void DrawDx8WfPtFlatHwVpHWVBFix( LPATID3DCNTX pCtxt,
                                 DWORD dwPrimCount,
                                 D3DPRIMITIVETYPE ePrimType,
                                 DWORD dwStampCount,
                                 BOOL bUsingIndexBuffer,
                                 LPBYTE lpcIndexCurrent );

void InitIndicesForFirstPrim( DWORD *pdwIdx1,
                              DWORD *pdwIdx2,
                              DWORD *pdwIdx3,
                              BOOL  bUsingIndexBuffer,
                              PBYTE *ppcIndexCurrent,
                              DWORD dwIndexStride);

void UpdateIndicesForNextPrim( DWORD            *pdwIdx1,
                               DWORD            *pdwIdx2,
                               DWORD            *pdwIdx3,
                               D3DPRIMITIVETYPE ePrimType,
                               BOOL             bEvenPrim,
                               BOOL             bUsingIndexBuffer,
                               PBYTE            *ppcIndexCurrent,
                               DWORD            dwIndexStride);

void SetFlatShadeVertexToHw( LPATID3DCNTX pCtxt, DWORD dwVertexNumber );

///////////////////////////////////////////////////////////////////////////////////

//
// Utility functions used in draw routines
//

void SetNonIndexedVBPacket(LPATID3DCNTX pCtxt, DWORD dwNumIndicies, WORD wIndex,
                           DWORD dwOpcode, DWORD dwFVFSize, DWORD dwFVFType, DWORD dwStampCount);

LPWORD SetIndexedVBPacket(
    LPATID3DCNTX pCtxt, LPWORD lpPrims, DWORD dwNumWordsToCopy,
    DWORD dwNumIndices, DWORD dwIndexBase, DWORD dwPrimType,
    DWORD dwFVFSize, DWORD dwFVFType, LPWORD lpwPreData, DWORD dwStampCount );

// Indexed primitive hang work-around -- See SetIndexedVBPacketTriList() for details
LPWORD SetIndexedVBPacketTriList(
    LPATID3DCNTX pCtxt, LPWORD lpPrims, DWORD dwNumWordsToCopy,
    DWORD dwNumIndices, DWORD dwIndexBase, DWORD dwPrimType,
    DWORD dwFVFSize, DWORD dwFVFType, LPWORD lpwPreData, DWORD dwStampCount );

#define IS_VALID_VERTEX_INDEX( dwVertexLength, dwIndex)                            \
    (/* ((DWORD)dwIndex >= 0) && always true */ ((DWORD)dwIndex < dwVertexLength))

#define NEXTINSTRUCTION(ptr, type, num, extrabytes)                            \
    ptr = (LPD3DHAL_DP2COMMAND)((LPBYTE)ptr + sizeof(D3DHAL_DP2COMMAND) +      \
                                ((num) * sizeof(type)) + (extrabytes))

// Fine to skip straight out if no vertex buffers are live
#define PARSE_ERROR_AND_EXIT( pDP2Data, pIns, pStartIns, ddrvalue)             \
   {                                                                           \
            pDP2Data->dwErrorOffset = (DWORD)((LPBYTE)pIns - (LPBYTE)pStartIns); \
            pDP2Data->ddrval = (HRESULT)ddrvalue;                                       \
            goto Exit_DrawPrimitives2;                                         \
   }

// If hw vertex buffers are in use they MUST be swapped prior to exit
#define PARSE_OPCODE_ERROR_AND_EXIT( pDP2Data, pIns, pStartIns, ddrvalue)      \
   {                                                                           \
            pDP2Data->dwErrorOffset = (DWORD)((LPBYTE)pIns - (LPBYTE)pStartIns);        \
            pDP2Data->ddrval = ddrvalue;                                       \
            goto VertexBufferSwap;                                         \
   }

#ifdef STRICT_LIMITS_CHECK
#define CHECK_CMDBUF_LIMITS( pDP2Data, pBuf)                                   \
   {                                                                           \
        LPBYTE pBase,pEnd;                                                     \
        pBase = (LPBYTE)((ULONG_PTR)pDP2Data->lpDDCommands->lpGbl->fpVidMem +             \
                        pDP2Data->dwCommandOffset);                            \
        pEnd  = pBase + pDP2Data->dwCommandLength;                             \
        if (! ((LPBYTE)pBuf < pEnd) && ( pBase <= (LPBYTE)pBuf)) {             \
            HSLDPF(E_DATA_DUMP,"DX6 D3D: Trying to read past Command Buffer limits "          \
                    "%x %x %x",pBase ,(LPBYTE)pBuf ,pEnd );                    \
            PARSE_ERROR_AND_EXIT( pDP2Data, lpIns, lpInsStart,                 \
                                  D3DERR_COMMAND_UNPARSED      );              \
        }                                                                      \
    }
#else
#define CHECK_CMDBUF_LIMITS( pDP2Data, pBuf)
#endif

#define GetMaxDwordsPerPacket(pCtx, dwMaxDWPerPkt)                                               \
{                                                                                                \
    DWORD dwPreambleSize = GetStateSizeNeeded(pCtx);                                             \
    dwMaxDWPerPkt = MIN(pCtx->CmdBuff.pQSParam->dwCmdBufSizeInDWORDs -dwPreambleSize-SIZE_OF_PRIM_HEADER, MAX_PACKET_SIZE_DWORDS);  \
}

#define IsTriFan(dpPrimitiveType)                       \
    (dpPrimitiveType==D3DDP2OP_TRIANGLEFAN ||           \
     dpPrimitiveType==D3DDP2OP_INDEXEDTRIANGLEFAN)?1:0

// Macro to determine if pointsprites or wide points are to be used or just normal points
#define IS_POINTSPRITE_ACTIVE(pCtxt)                                                        \
 ( (pCtxt->dwPointSpriteFlags & ATI_TCL_PTSPR_ENABLED)                                  ||  \
   (pCtxt->dwPointSpriteFlags & ATI_TCL_PTSPR_PER_VTX_PSIZE)                            ||  \
   (pCtxt->dwPointSpriteFlags & ATI_TCL_PTSPR_COMPUTE_PSIZE)                            ||  \
   (pCtxt->fPointSize != 1.0f))

// Macro to determine if triangle is culled
#define Culling(dwCullMode,v0,v1,v2) ((dwCullMode > D3DCULL_NONE) &&                          \
    ((dwCullMode==D3DCULL_CCW && (v1.sx-v0.sx)*(v2.sy-v0.sy)<=(v2.sx-v0.sx)*(v1.sy-v0.sy)) || \
     (dwCullMode==D3DCULL_CW  && (v1.sx-v0.sx)*(v2.sy-v0.sy)>=(v2.sx-v0.sx)*(v1.sy-v0.sy)) ) )

// Macros to copy data into newly created point sprite vertices
#define COPY_PS_INTO_BUFFER(lpVerts, dwFillOffset, dwOriginalOffset)  \
    {                                                                 \
    *(lpVtx[0] + dwFillOffset) =                                      \
    *(lpVtx[1] + dwFillOffset) =                                      \
    *(lpVtx[2] + dwFillOffset) =                                      \
    *(lpVtx[3] + dwFillOffset) = *(lpVerts + dwOriginalOffset);       \
    }

#define SET_DEFAULT_PS_TEX_VALUE_SW(dwFillOffset)       \
    {                                                   \
    *(LPD3DVALUE)(lpVtx[0] + dwFillOffset) = 0.0f;      \
    *(LPD3DVALUE)(lpVtx[1] + dwFillOffset) = 1.0f;      \
    *(LPD3DVALUE)(lpVtx[2] + dwFillOffset) = 0.0f;      \
    *(LPD3DVALUE)(lpVtx[3] + dwFillOffset) = 1.0f;      \
                                                        \
    *(LPD3DVALUE)(lpVtx[0] + dwFillOffset + 1) = 0.0f;  \
    *(LPD3DVALUE)(lpVtx[1] + dwFillOffset + 1) = 0.0f;  \
    *(LPD3DVALUE)(lpVtx[2] + dwFillOffset + 1) = 1.0f;  \
    *(LPD3DVALUE)(lpVtx[3] + dwFillOffset + 1) = 1.0f;  \
    }

#define SET_DEFAULT_PS_TEX_VALUE_TCL(dwFillOffset)      \
    {                                                   \
    *(LPD3DVALUE)(lpVtx[0] + dwFillOffset)     = 0.0f;  \
    *(LPD3DVALUE)(lpVtx[1] + dwFillOffset)     = 1.0f;  \
    *(LPD3DVALUE)(lpVtx[2] + dwFillOffset)     = 0.0f;  \
    *(LPD3DVALUE)(lpVtx[3] + dwFillOffset)     = 1.0f;  \
                                                        \
    *(LPD3DVALUE)(lpVtx[0] + dwFillOffset + 1) = 1.0f;  \
    *(LPD3DVALUE)(lpVtx[1] + dwFillOffset + 1) = 1.0f;  \
    *(LPD3DVALUE)(lpVtx[2] + dwFillOffset + 1) = 0.0f;  \
    *(LPD3DVALUE)(lpVtx[3] + dwFillOffset + 1) = 0.0f;  \
    }


void vSetDrawPrimTable( LPATID3DCNTX pCtxt, LPD3DDEVICE lpD3DDev );

void DrawPrimVertexBufferSwap( LPD3DHAL_DRAWPRIMITIVES2DATA lpdp2d,
                          LPATID3DCNTX                 pContext,
                          struct _ATIVERTEXBUFFER     *lpATIVtxBuff );

__inline void InsertStallIntoPm4Stream( LPATID3DCNTX pCtxt )
{
  LPDWORD pdwMyCommand = GetPM4Entries(2,&pCtxt->CmdBuff);
  *pdwMyCommand++ = MakeRegWriteConsec(mmWAIT_UNTIL, 1);
  *pdwMyCommand++ = WAIT_UNTIL__WAIT_3D_IDLE;
  SubmitPM4EntriesToHw(2,0,&pCtxt->CmdBuff);
}

__inline void InsertWaitHwIdleIntoPm4Stream(LPATID3DCNTX pCtxt, DWORD dwFlags)
{
  LPDWORD pdwMyCommand = GetPM4Entries(2,&pCtxt->CmdBuff);
  *pdwMyCommand++ = MakeRegWriteConsec(mmWAIT_UNTIL, 1);
  *pdwMyCommand++ = dwFlags;
  SubmitPM4EntriesToHw(2,0,&pCtxt->CmdBuff);
}


// Called from dx8 non-indexed primitive op codes. The return value is stored in
// pCtxt->dpLastPrimitiveType which is of the dx7 D3DHAL_DP2OPERATION type.
__inline D3DHAL_DP2OPERATION Dx8PrimTypeToDx7OpCode(D3DPRIMITIVETYPE primTypeDx8)
{
    static D3DHAL_DP2OPERATION xlate[7] = { 0,
                                            D3DDP2OP_POINTS,
                                            D3DDP2OP_LINELIST,
                                            D3DDP2OP_LINESTRIP,
                                            D3DDP2OP_TRIANGLELIST,
                                            D3DDP2OP_TRIANGLESTRIP,
                                            D3DDP2OP_TRIANGLEFAN };

    HSLASSERT(primTypeDx8 != 0 && primTypeDx8 < sizeof(xlate));
    return xlate[primTypeDx8];
}

// Called from dx8 indexed primitive op codes. The return value is stored in
// pCtxt->dpLastPrimitiveType which is of the dx7 D3DHAL_DP2OPERATION type.
__inline D3DHAL_DP2OPERATION Dx8PrimTypeToIndexedDx7OpCode(D3DPRIMITIVETYPE primTypeDx8)
{
    static D3DHAL_DP2OPERATION xlate[7] = { 0,
                                            D3DDP2OP_POINTS,
                                            D3DDP2OP_INDEXEDLINELIST,
                                            D3DDP2OP_INDEXEDLINESTRIP,
                                            D3DDP2OP_INDEXEDTRIANGLELIST2,
                                            D3DDP2OP_INDEXEDTRIANGLESTRIP,
                                            D3DDP2OP_INDEXEDTRIANGLEFAN };

    HSLASSERT(primTypeDx8 != 0 && primTypeDx8 < sizeof(xlate));
    return xlate[primTypeDx8];
}

__inline DWORD GetVertexCountForDx8Prim(LPATID3DCNTX pCtxt,
                                        D3DPRIMITIVETYPE ePrimType,
                                        DWORD dwPrimCount)
{
    LPD3DDEVICE lpD3DDev = (LPD3DDEVICE)GetD3DDevice(pCtxt);
    DWORD dwVertexCount = (dwPrimCount - 1)
                          * lpD3DDev->aStridePerPrim[ePrimType]
                          + lpD3DDev->aVertsPerPrim[ePrimType];
    return dwVertexCount;
}

__inline
LPDWORD
CopyOneVertexData(
    __in    LPATID3DCNTX    pCtxt,
    __out_bcount(dwFVFHwSize)  LPDWORD lpPM4,
    __in    LPD3DTLVERTEX   lpV,
    __in    DWORD           dwFVFHwSize
    )
{
   DWORD       dwStage;
   LPTEXSTAGE  lpStage;
   LPBYTE      lpTexCoordOffsets;
   DWORD       dwCopySize;

   if (!(pCtxt->dwReArrangeVtxElement))
   {
     //add texture coords which is used and not include in the vertex,
     //because hw filter has problem in the triange which three
     //texture coordinates are all(0,0), driver has to make them diffrent.
     if (!pCtxt->dwTexCoordsNotIncluded)
     {
        memcpy(lpPM4,lpV,dwFVFHwSize);
        lpPM4= (DWORD *)((LPBYTE)lpPM4 + dwFVFHwSize);
     }
     else
     {
        memcpy(lpPM4,lpV,dwFVFHwSize-8);
        lpPM4= (DWORD *)((LPBYTE)lpPM4 + dwFVFHwSize-8);

        *lpPM4++=*((DWORD*)(&(pCtxt->fTexCoordsDelta)));
        *lpPM4++=*((DWORD*)(&(pCtxt->fTexCoordsDelta)));
        if (pCtxt->fTexCoordsDelta>=(3*TEXCOORDSDELTA))
        {
           pCtxt->fTexCoordsDelta = TEXCOORDSDELTA;
        }
        else
        {
           pCtxt->fTexCoordsDelta = pCtxt->fTexCoordsDelta+TEXCOORDSDELTA;
        }
      }

   }
   else
   {
     //copy vertex date.
     dwCopySize=pCtxt->dwTexCoordOffset<<2;
     if (dwCopySize <= dwFVFHwSize)  // is the check really needed?
     {
        memcpy(lpPM4,lpV,dwCopySize);
        lpPM4= (DWORD *)((LPBYTE)lpPM4 + dwCopySize);
     }
     else
     {
         HSLASSERT(dwCopySize <= dwFVFHwSize);
     }

    //copy texture coordinate sets.
     for (dwStage = 0; dwStage<ATI_MAX_NUM_TEX_UNITS && dwCopySize<dwFVFHwSize; dwStage++)
     {
         lpStage  = &pCtxt->texStageInfo.TexStageList[dwStage];
         dwCopySize +=2*sizeof(D3DVALUE);
         lpTexCoordOffsets=(LPBYTE)lpV + (pCtxt->dwTexCoordOffset<<2)
                                       + lpStage->dwState[D3DTSS_TEXCOORDINDEX]*2*sizeof(D3DVALUE);
         memcpy(lpPM4,lpTexCoordOffsets,2*sizeof(D3DVALUE));
         lpPM4= (DWORD *)((LPBYTE)lpPM4 + 2*sizeof(D3DVALUE));
     }
   }
   return lpPM4;
}

__inline VOID SetTIUWorkaroundPacket(LPATID3DCNTX pCtxt)
{
}


__inline VOID SetPointSpriteCommandPacket(LPATID3DCNTX pCtxt, DWORD dwCullReg, DWORD dwOutputVtxReg)
{
}

__inline VOID ForceDisableHOS(LPATID3DCNTX pCtxt)
{
    DWORD *pdwPm4Entries;
    pdwPm4Entries = GetPM4Entries(4,&pCtxt->CmdBuff);
    set_SE_VAP_CNTL_hos_ena(&pCtxt->SeVapCntl_reg, 0);
    set_SE_VAP_CNTL_vf_max_vtx_num(&pCtxt->SeVapCntl_reg, 9);
    pdwPm4Entries = SetOneRegPM4(pdwPm4Entries, mmSE_TCL_STATE_FLUSH_REG, 0);
    pdwPm4Entries = SetOneRegPM4(pdwPm4Entries, mmSE_VAP_CNTL, pCtxt->SeVapCntl_reg.u32All);
    SubmitPM4EntriesToHw(4,0,&pCtxt->CmdBuff);
}

// Disables cylindrical wrap.
__inline VOID DisableCylindicalWrap(LPATID3DCNTX pCtxt)
{
    DWORD dwTxFilterMask  = ~(PP_TXFILTER_0__WRAPEN_S_MASK | PP_TXFILTER_0__WRAPEN_T_MASK);
    DWORD dwTxFormatXMask = ~(PP_TXFORMAT_X_0__WRAPEN_Q_MASK);

    LPDWORD Pm4Entries;

    Pm4Entries = GetPM4Entries(24, &pCtxt->CmdBuff);

    *Pm4Entries++ = mmPP_TXFILTER_0;
    *Pm4Entries++ = (pCtxt->PpTxFilter0_reg.u32All & dwTxFilterMask);

    *Pm4Entries++ = mmPP_TXFILTER_1;
    *Pm4Entries++ = (pCtxt->PpTxFilter1_reg.u32All & dwTxFilterMask);

    *Pm4Entries++ = mmPP_TXFILTER_2;
    *Pm4Entries++ = (pCtxt->PpTxFilter2_reg.u32All & dwTxFilterMask);

    *Pm4Entries++ = mmPP_TXFILTER_3;
    *Pm4Entries++ = (pCtxt->PpTxFilter3_reg.u32All & dwTxFilterMask);

    *Pm4Entries++ = mmPP_TXFILTER_4;
    *Pm4Entries++ = (pCtxt->PpTxFilter4_reg.u32All & dwTxFilterMask);

    *Pm4Entries++ = mmPP_TXFILTER_5;
    *Pm4Entries++ = (pCtxt->PpTxFilter5_reg.u32All & dwTxFilterMask);

    *Pm4Entries++ = mmPP_TXFORMAT_X_0;
    *Pm4Entries++ = (pCtxt->PpTxFormatX0_reg.u32All & dwTxFormatXMask);

    *Pm4Entries++ = mmPP_TXFORMAT_X_1;
    *Pm4Entries++ = (pCtxt->PpTxFormatX1_reg.u32All & dwTxFormatXMask);

    *Pm4Entries++ = mmPP_TXFORMAT_X_2;
    *Pm4Entries++ = (pCtxt->PpTxFormatX2_reg.u32All & dwTxFormatXMask);

    *Pm4Entries++ = mmPP_TXFORMAT_X_3;
    *Pm4Entries++ = (pCtxt->PpTxFormatX3_reg.u32All & dwTxFormatXMask);

    *Pm4Entries++ = mmPP_TXFORMAT_X_4;
    *Pm4Entries++ = (pCtxt->PpTxFormatX4_reg.u32All & dwTxFormatXMask);

    *Pm4Entries++ = mmPP_TXFORMAT_X_5;
    *Pm4Entries++ = (pCtxt->PpTxFormatX5_reg.u32All & dwTxFormatXMask);

    SubmitPM4EntriesToHw(24,0,&pCtxt->CmdBuff);
}

__inline VOID ResetCylindicalWrap(LPATID3DCNTX pCtxt)
{
    LPDWORD Pm4Entries;

    Pm4Entries = GetPM4Entries(24, &pCtxt->CmdBuff);

    *Pm4Entries++ = mmPP_TXFILTER_0;
    *Pm4Entries++ = (pCtxt->PpTxFilter0_reg.u32All);

    *Pm4Entries++ = mmPP_TXFILTER_1;
    *Pm4Entries++ = (pCtxt->PpTxFilter1_reg.u32All);

    *Pm4Entries++ = mmPP_TXFILTER_2;
    *Pm4Entries++ = (pCtxt->PpTxFilter2_reg.u32All);

    *Pm4Entries++ = mmPP_TXFILTER_3;
    *Pm4Entries++ = (pCtxt->PpTxFilter3_reg.u32All);

    *Pm4Entries++ = mmPP_TXFILTER_4;
    *Pm4Entries++ = (pCtxt->PpTxFilter4_reg.u32All);

    *Pm4Entries++ = mmPP_TXFILTER_5;
    *Pm4Entries++ = (pCtxt->PpTxFilter5_reg.u32All);

    *Pm4Entries++ = mmPP_TXFORMAT_X_0;
    *Pm4Entries++ = (pCtxt->PpTxFormatX0_reg.u32All);

    *Pm4Entries++ = mmPP_TXFORMAT_X_1;
    *Pm4Entries++ = (pCtxt->PpTxFormatX1_reg.u32All);

    *Pm4Entries++ = mmPP_TXFORMAT_X_2;
    *Pm4Entries++ = (pCtxt->PpTxFormatX2_reg.u32All);

    *Pm4Entries++ = mmPP_TXFORMAT_X_3;
    *Pm4Entries++ = (pCtxt->PpTxFormatX3_reg.u32All);

    *Pm4Entries++ = mmPP_TXFORMAT_X_4;
    *Pm4Entries++ = (pCtxt->PpTxFormatX4_reg.u32All);

    *Pm4Entries++ = mmPP_TXFORMAT_X_5;
    *Pm4Entries++ = (pCtxt->PpTxFormatX5_reg.u32All);

    SubmitPM4EntriesToHw(24,0,&pCtxt->CmdBuff);
}


extern void R200ZeroLengthLineBugWorkaround( LPATID3DCNTX pCtxt );

extern __inline void SetFlatShadeVertexToHw( LPATID3DCNTX pCtxt, DWORD dwVertexNumber );

#define FLAT_SHADE_VTX__USE_VTX_0  0

#endif // _ATI_DRAWPRIM_H


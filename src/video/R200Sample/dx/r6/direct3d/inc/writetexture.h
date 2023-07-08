

//    
//  Workfile: texturestage.h
//
//  Description:
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 2000, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//


#ifndef ATI_WRITETEXTURE_H
#define ATI_WRITETEXTURE_H

#include "atidxinc.h"
//#include "d3dcntx.h" 

//*****************************************************************************
// Defines
//*****************************************************************************

// Define used for jump table boundary index check.
#ifdef DEBUG
#define END_VOIDFUNC_TABLE VoidfuncJumpTableError
#else
#define END_VOIDFUNC_TABLE
#endif

//*****************************************************************************
// Enumerations
//*****************************************************************************

//*****************************************************************************
// Data Structures
//*****************************************************************************


typedef union {
    struct _TXCBLENDREC
    {
        unsigned arg1: 4;
        unsigned reserved1: 1;
        unsigned arg2: 4;
        unsigned reserved2: 1;
        unsigned arg3: 4;
        unsigned reserved3: 1;
        unsigned compArg1: 1;
        unsigned compArg2: 1;
        unsigned compArg3: 1;
        unsigned blendCntl: 3;
        unsigned scaleTx: 2;
        unsigned clampTx: 1;
        unsigned outputToT0: 1;
        unsigned outputToT1: 1;
        unsigned outputToT2: 1; //This bit is only used in tex blender.
    };
    unsigned int u32All;
} TxCBlendRec;

typedef union {
    struct _TXABLENDREC
    {
        unsigned arg1: 4;
        unsigned arg2: 4;
        unsigned arg3: 4;
        unsigned dotalpha: 1;
        unsigned reserved: 2;
        unsigned compArg1: 1;
        unsigned compArg2: 1;
        unsigned compArg3: 1;
        unsigned blendCntl: 3;
        unsigned scaleTx: 2;
        unsigned clampTx: 1;
        unsigned outputToT0: 1;
        unsigned outputToT1: 1;
        unsigned outputToT2: 1; //This bit is only used in alpha blender.
    };
    unsigned int u32All;
} TxABlendRec;


void SetTexFilter0( struct _ATID3DCNTX *pCtx, enum _D3DTEXTURESTAGESTATETYPE TSState, DWORD dwValue);
void SetTexFilter1( struct _ATID3DCNTX *pCtx, enum _D3DTEXTURESTAGESTATETYPE TSState, DWORD dwValue);
void SetTexFilter2( struct _ATID3DCNTX *pCtx, enum _D3DTEXTURESTAGESTATETYPE TSState, DWORD dwValue);

void SetTexFilter_WrapUVW0( struct _ATID3DCNTX *pCtx, DWORD dwValueWrapU, DWORD dwValueWrapV, DWORD dwValueWrapW );
void SetTexFilter_WrapUVW1( struct _ATID3DCNTX *pCtx, DWORD dwValueWrapU, DWORD dwValueWrapV, DWORD dwValueWrapW );
void SetTexFilter_WrapUVW2( struct _ATID3DCNTX *pCtx, DWORD dwValueWrapU, DWORD dwValueWrapV, DWORD dwValueWrapW );

void SetCubeMapSize0( struct _ATID3DCNTX *pCtx, DWORD dwField, DWORD dwValue);
void SetCubeMapSize1( struct _ATID3DCNTX *pCtx, DWORD dwField, DWORD dwValue);
void SetCubeMapSize2( struct _ATID3DCNTX *pCtx, DWORD dwField, DWORD dwValue);

void SetCubeOffsets0( struct _ATID3DCNTX *pCtx, struct _ATISURFCNTX* lpCurTexMap);
void SetCubeOffsets1( struct _ATID3DCNTX *pCtx, struct _ATISURFCNTX* lpCurTexMap);
void SetCubeOffsets2( struct _ATID3DCNTX *pCtx, struct _ATISURFCNTX* lpCurTexMap);

void SetTexFmt0( struct _ATID3DCNTX *pCtx, struct _ATISURFCNTX* lpCurTexMap);
void SetTexFmt1( struct _ATID3DCNTX *pCtx, struct _ATISURFCNTX* lpCurTexMap);
void SetTexFmt2( struct _ATID3DCNTX *pCtx, struct _ATISURFCNTX* lpCurTexMap);

void SetTexOffset0( struct _ATID3DCNTX *pCtx, DWORD dwValue);
void SetTexOffset1( struct _ATID3DCNTX *pCtx, DWORD dwValue);
void SetTexOffset2( struct _ATID3DCNTX *pCtx, DWORD dwValue);

void SetBorderColor0( struct _ATID3DCNTX *pCtx, DWORD dwValue);
void SetBorderColor1( struct _ATID3DCNTX *pCtx, DWORD dwValue);
void SetBorderColor2( struct _ATID3DCNTX *pCtx, DWORD dwValue);

void SetTxFilterReg( struct _ATID3DCNTX *pCtx, DWORD dwUnit);
void SetCubicEnvRegs( struct _ATID3DCNTX *pCtx, DWORD dwUnit);
void UpdateTexStateAndBorder( struct _ATID3DCNTX *pCtx, DWORD dwD3DStage);

#ifdef DEBUG
void VoidfuncJumpTableError();
#endif

//*****************************************************************************
// Prototypes for Chaplin (R200)
//*****************************************************************************

void SetTexFilter3( struct _ATID3DCNTX *pCtx, enum _D3DTEXTURESTAGESTATETYPE TSState, DWORD dwValue);
void SetTexFilter4( struct _ATID3DCNTX *pCtx, enum _D3DTEXTURESTAGESTATETYPE TSState, DWORD dwValue);
void SetTexFilter5( struct _ATID3DCNTX *pCtx, enum _D3DTEXTURESTAGESTATETYPE TSState, DWORD dwValue);

void SetTexFilter_WrapUVW3( struct _ATID3DCNTX *pCtx, DWORD dwValueWrapU, DWORD dwValueWrapV, DWORD dwValueWrapW );
void SetTexFilter_WrapUVW4( struct _ATID3DCNTX *pCtx, DWORD dwValueWrapU, DWORD dwValueWrapV, DWORD dwValueWrapW );
void SetTexFilter_WrapUVW5( struct _ATID3DCNTX *pCtx, DWORD dwValueWrapU, DWORD dwValueWrapV, DWORD dwValueWrapW );

void SetTexFilter_Cubemap3( struct _ATID3DCNTX *pCtx, DWORD dwValue);
void SetTexFilter_Cubemap4( struct _ATID3DCNTX *pCtx, DWORD dwValue);
void SetTexFilter_Cubemap5( struct _ATID3DCNTX *pCtx, DWORD dwValue);

void SetCubeMapSize3( struct _ATID3DCNTX *pCtx, DWORD dwField, DWORD dwValue);
void SetCubeMapSize4( struct _ATID3DCNTX *pCtx, DWORD dwField, DWORD dwValue);
void SetCubeMapSize5( struct _ATID3DCNTX *pCtx, DWORD dwField, DWORD dwValue);

void SetCubeOffsets3( struct _ATID3DCNTX *pCtx, struct _ATISURFCNTX* lpCurTexMap);
void SetCubeOffsets4( struct _ATID3DCNTX *pCtx, struct _ATISURFCNTX* lpCurTexMap);
void SetCubeOffsets5( struct _ATID3DCNTX *pCtx, struct _ATISURFCNTX* lpCurTexMap);

void SetTexFmt3( struct _ATID3DCNTX *pCtx, struct _ATISURFCNTX* lpCurTexMap);
void SetTexFmt4( struct _ATID3DCNTX *pCtx, struct _ATISURFCNTX* lpCurTexMap);
void SetTexFmt5( struct _ATID3DCNTX *pCtx, struct _ATISURFCNTX* lpCurTexMap);

void SetTexOffset3( struct _ATID3DCNTX *pCtx, DWORD dwValue);
void SetTexOffset4( struct _ATID3DCNTX *pCtx, DWORD dwValue);
void SetTexOffset5( struct _ATID3DCNTX *pCtx, DWORD dwValue);

void SetPPCntlTexBlend3( struct _ATID3DCNTX *pCtx, DWORD dwValue);
void SetPPCntlTexBlend4( struct _ATID3DCNTX *pCtx, DWORD dwValue);
void SetPPCntlTexBlend5( struct _ATID3DCNTX *pCtx, DWORD dwValue);

void SetBorderColor3( struct _ATID3DCNTX *pCtx, DWORD dwValue);
void SetBorderColor4( struct _ATID3DCNTX *pCtx, DWORD dwValue);
void SetBorderColor5( struct _ATID3DCNTX *pCtx, DWORD dwValue);

#endif // ATI_WRITETEXTURE_H


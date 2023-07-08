

//    
//  $Workfile: stateset.h $
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _STATESET_H__
#define _STATESET_H__

#include "atidxinc.h"
#include "d3dcntx.h"

#define STATESETGROWSIZE 16
#define DP2CMDGROWSIZE 256

HRESULT AtiRecRenderStates(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND lpCmd, LPDWORD lpStateMirror);
HRESULT AtiRecTextureStageStates(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiRecViewport(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiRecWRange(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiRecMaterial(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiRecZRange(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiRecSetLight(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiRecCreateLight(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiRecTransform(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiRecMultiplyTransform(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);

HRESULT AtiRecUserClipPlane(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiRecVertexShader(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiRecVertexShaderConst(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiRecStreamSource(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiRecSetIndices(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiRecSetPixelShader(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiRecSetPixelShaderConst(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);

extern HRESULT AtiSetTransform( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *ppCmd );
extern HRESULT AtiMultiplyTransform( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *ppCmd );

extern HRESULT AtiSetViewport( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *ppCmd );
extern HRESULT AtiSetZrange( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *ppCmd );
extern HRESULT AtiSetMaterial( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *ppCmd );
extern HRESULT AtiCreateLight( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *ppCmd );
extern HRESULT AtiSetLight( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *ppCmd );
extern HRESULT AtiSetUserClipPlane( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *ppCmd );
extern HRESULT AtiSetTextureStageStates(LPATID3DCNTX lpCntx, LPD3DHAL_DP2COMMAND *lppCmd);
extern HRESULT AtiSetRenderStates(LPATID3DCNTX lpD3DCntx, LPD3DHAL_DP2COMMAND lpCmd, LPDWORD lpStateMirror);
extern HRESULT AtiSetWRange( LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd );
extern HRESULT AtiSetVertexShader(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
extern HRESULT AtiSetVertexShaderConst(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
extern HRESULT AtiSetStreamSource(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
extern HRESULT AtiSetIndices(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
extern HRESULT AtiSetPixelShader(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
extern HRESULT AtiSetPixelShaderConst(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);

HRESULT BeginStateSet(LPATID3DCNTX pContext, LPD3DHAL_DP2STATESET lpStateSetOp);
HRESULT EndStateSet(LPATID3DCNTX pContext, DWORD dwStateSetHandle);
HRESULT DeleteStateSet(LPATID3DCNTX pContext, DWORD dwStateSetHandle);
HRESULT ExecuteStateSet(LPATID3DCNTX pContext, DWORD dwStateSetHandle, LPDWORD lpdwRStates);
HRESULT CaptureStateSet(LPATID3DCNTX pContext, DWORD dwStateSetHandle);
HRESULT CreateStateSet(LPATID3DCNTX pContext, LPD3DHAL_DP2STATESET lpStateSetOp);

float * WritePSConstantToCommand( LPATID3DCNTX pContext, float *pfConstData, DWORD dwConstIndex );

#if (DIRECT3D_VERSION >= 0x0900)
HRESULT AtiRecScissorRect(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *lppCmd);
extern HRESULT AtiSetScissorRect(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *lppCmd);

HRESULT AtiRecVertexShaderConstB(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiRecVertexShaderConstI(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
extern HRESULT AtiSetVertexShaderConstB(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
extern HRESULT AtiSetVertexShaderConstI(LPATID3DCNTX pContext, LPD3DHAL_DP2COMMAND *lppCmd);
#endif // (DIRECT3D_VERSION >= 0x0900)

#endif //_STATESET_H__


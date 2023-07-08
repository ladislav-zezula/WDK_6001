

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


#ifndef ATI_TEXTURESTAGE_H
#define ATI_TEXTURESTAGE_H

#include "atidxinc.h"
#include "atid3ddefs.h"

//*****************************************************************************
// Defines
//*****************************************************************************
//
// When TextureStageStates are converted to a PixelShader Program the worst
// case number of tokens required is 100 Tokens Total, so any value above
// that should be sufficient
//
//   Begin and End Tokens    (2 Tokens)
//   0 Constant Declarations (18 tokens each)
//   6 Texure Declarations   (3 Tokens each)     
//   8 RGB instructions      (5 Tokens each)
//   8 Alpha Instructions    (5 Tokens Each)

#define MAX_LEGACY_TOKENS  128    // max legacy-converted shader program 

//*****************************************************************************
// Enumerations
//*****************************************************************************

//*****************************************************************************
// Data Structures
//*****************************************************************************

//Compilation Data struction for converting TextureStageStates to a PixelShader
//program. (R200 only)
typedef struct _TEXTURESTAGE_COMPILATION_INFO
{
    //The Texture Register chosen to be used as D3DTA_CURRENT
    DWORD dwTACurrentReg;

    //The stage when D3DTA_CURRENT is first written to.  Per the SDK, any stage
    //reading from D3DTA_CURRENT before it is written to will read DIFFUSE
    //instead.
    DWORD dwStageTACurrValid; 

    //The Texture Register chosen to be used as D3DTA_TEMP
    DWORD dwTATempReg;

    //The stage when D3DTA_TEMP is first written to.  Per the SDK, any stage
    //reading from D3DTA_TEMP before it is written to will read DIFFUSE
    //instead.
    DWORD dwStageTATempValid; 

    //Tracks which stages are using a texture and which texture register they 
    //are using
    DWORD dwStagesUsingTexture[MAX_TEXSTAGE]; 

    //Track the stage performing the D3DTOP_BUMPENVMAP(LUMINANCE)
    DWORD dwStagePerformingBump;
    BOOL  bBumpmap;

#if(DIRECT3D_VERSION >= 0x0900)
    BOOL bLineAAEnabled;
#endif

} TEXTURESTAGE_COMPILATION_INFO, *LPTEXTURESTAGE_COMPILATION_INFO;

HRESULT AtiSetTextureStageStates( struct _ATID3DCNTX *pCtx, LPD3DHAL_DP2COMMAND *lppCmd);


DWORD Rad2RecalcTexStages( struct _ATID3DCNTX *pCtx, DWORD dwMaxStage );

DWORD TexStagesToPixShader( struct _ATID3DCNTX *pContext, 
                            struct _TSS *pTSS, 
                            __out_ecount(dwMaxSize) LPDWORD data,
                            DWORD maxSize, 
                            __out_ecount(MAX_TEXSTAGE) DWORD dwPSRegAssign[] );

DWORD TexArgToPixRegister( DWORD dwTArg, DWORD eType, DWORD dwOp, 
                           DWORD dwStage, DWORD dwTexHndl,
                           LPTEXTURESTAGE_COMPILATION_INFO lpTSSCompInfo);

DWORD TexStageToPixInst( struct _TSS *pTSS, LPDWORD lpData, DWORD iStage,
                         LPTEXTURESTAGE_COMPILATION_INFO lpTSSCompInfo, 
                         DWORD eType, BOOL bIsCoIssue, BOOL bIsLastInstruction );


enum _ETEXCOORDTYPE GetHWTexCoordType( DWORD dwTexUnit, struct _ATISURFCNTX *lpTexMap, 
                         struct _TEXSTAGE *lpStage,  struct _RAD2PIXELSHADER *lpPS, 
                         DWORD dwNumCoords, enum _PS_SHADER_PASS ePass );
void Rad2ProcessTexCoords( struct _ATID3DCNTX *pContext );
void Rad2ProcessEyeRoute( struct _ATID3DCNTX *pContext, DWORD dwNumTexCoordSets );
void Rad2ProcessTexCoordRouting ( struct _ATID3DCNTX *pContext, ETXROUTING_MODE eTxRouting );
void Rad2ProcessTexCoordDepthMode( struct _ATID3DCNTX *pContext );

#endif // ATI_TEXTURESTAGE_H


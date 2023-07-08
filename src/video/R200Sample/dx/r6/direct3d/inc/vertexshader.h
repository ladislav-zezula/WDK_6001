

//    
//  Workfile: VertexShader.h
//
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 2000-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _VERTEXSHADER_H__ 
#define _VERTEXSHADER_H__


///////////////////////////////////////////////////////////////////////////////
// Definitions

#define VS_TOKEN_DATA_SKIP      0x10000000

#define VS_STREAM_UNDEFINED     0xffffffff
#define VS_STREAM_TWEENBLEND    0x40000000
#define VS_STREAM_SOLO          0x80000000

// Shader flags
#define VS_TWEENING_ENABLED     0x00000001
#define VS_RHW1_ENABLED         0x00000002
#define VS_NORMAL1_ENABLED      0x00000004
#define VS_USES_PSC             0x00000008
#define VS_HAS_LOCAL_CONST      0x00000010
#define VS_PVS_SHADER           0x80000000 // if this bit is not set, the shader uses 
                                           // the fixed function pipeline

#define VS_DECL_HASPARSED       0x00000200
#define VS_DECL_POSITIONT       0x00000400
#define VS_NORMAL0_ENABLED      0x00000800

// Memory allocation flags
#define VS_CODE_IN_AGP_MEM      0x00000001
#define VS_CODE_IN_FB_MEM       0x00000002
#define VS_CODE_IN_QS_HEAP      0x80000000


// Vector allocation flags
#define VS_FORCE_ALLOC_IN_SYS   0x00000000
#define VS_TRY_ALLOC_IN_AGP     0x00000001
#define VS_TRY_ALLOC_IN_FB      0x00000002

#define VS_TRY_ALLOC_ALL        0xffffffff

//
// defines for the fixed function vector locations
//
#define ATI_VEC_LOC_POSITION0     0x00    
#define ATI_VEC_LOC_NORMAL0       0x01     
#define ATI_VEC_LOC_COLOR0        0x02
#define ATI_VEC_LOC_COLOR1        0x03
#define ATI_VEC_LOC_COLOR2        0x04
#define ATI_VEC_LOC_COLOR3        0x05
#define ATI_VEC_LOC_TEXTURE0      0x06
#define ATI_VEC_LOC_TEXTURE1      0x07
#define ATI_VEC_LOC_TEXTURE2      0x08
#define ATI_VEC_LOC_TEXTURE3      0x09
#define ATI_VEC_LOC_TEXTURE4      0x0A
#define ATI_VEC_LOC_TEXTURE5      0x0B
#define ATI_VEC_LOC_BLENDWEIGHT   0x0C
#define ATI_VEC_LOC_POSITION1     0x0D
#define ATI_VEC_LOC_NORMAL1       0x0E
#define ATI_VEC_LOC_PSIZE         0x0F
#define ATI_VEC_LOC_BLENDINDICES  0x14
#define ATI_VEC_LOC_LAST          0x14

#define ATI_VEC_LOC_ENTRIES  ATI_VEC_LOC_LAST + 1

// PVS code optimization defines
#define ATI_PVS_OPT_NUM_POS          1
#define ATI_PVS_OPT_NUM_ATTR         2
#define ATI_PVS_OPT_NUM_TEX          6

// Limits the number of output registers to optimize
#define ATI_PVS_OPT_LIMIT   (ATI_PVS_OPT_NUM_POS + ATI_PVS_OPT_NUM_ATTR + ATI_PVS_OPT_NUM_TEX)
#define ATI_PVS_MAX_OPT_TYPES        15

//Added for DX9
//Shader handletype for DX9. 
#define ATI_VS_DECL        1
#define ATI_VS_FUNC        2

// Dx9 changes GET_REGTYPE macro. Our driver still need dx8 type GET_REGTYPE.
#if (DIRECT3D_VERSION >= 0x0900)
#define GET_REGTYPE(_RegFile) \
    (((_RegFile)&(D3DSP_REGTYPE_MASK))|\
     ((_RegFile)&(D3DSP_REGTYPE_MASK2)))

#else

#define GET_REGTYPE(_RegFile) D3DSI_GETREGTYPE(_RegFile)

#endif//DIRECT3D_VERSION >= 0x0900


// The following typedef is used for our PVS instruction optimization routine
typedef struct _ATIPVSOPTIMIZATION
{
    DWORD                             dwPVSOptimizeCode[128];  // Optimization flags

    ATITCLRAD2INPUTVTXVECTORADDR_cmd  pvsInputVecAddr;                       // vector indirection regs
    regSE_TCL_OUTPUT_VTX_COMP_SEL     pvsRegSeTclOutVtxCompSel;              // output sel reg

} ATIPVSOPTIMIZATION, *LPATIPVSOPTIMIZATION;

/*
 * ATIVTXSHADERCONST structure is used to track vertex shader constant store updates
*/
typedef struct _ATIVTXSHADERCONST
{
    DWORD   dwRegStart;
    DWORD   dwCount;
} ATIVTXSHADERCONST, *LPATIVTXSHADERCONST;

typedef struct _ATIVTXSHADERSTREAMDEF
{
    DWORD   dwStream;        // The stream number this element is in
    DWORD   dwOffset;        // The offset (set in ParseDeclBody)
    DWORD   dwSize;          // The number of DWORDS in this element
    DWORD   dwStride;        // The number of DWORDS to the next element

} ATIVTXSHADERSTREAMDEF, *LPATIVTXSHADERSTREAMDEF;

#if (DIRECT3D_VERSION >= 0x0900)
/*
* Mapping between the Shader DCL statements and the Declaration 
*/
typedef struct _ATIDECLMAPPING
{
    D3DDECLUSAGE       Usage;      // Semantics
    DWORD              UsageIndex;
    DWORD              RegIndex;
}ATIDECLMAPPING, *LPATIDECLMAPPING;

typedef struct _ATIELEMUSEDINFO 
{
    DWORD              IndexInFunc;
    BOOL               bUsedInPVS;
    DWORD              SkipDW;
    BOOL               bForceNewVtxArray;
}ATIELEMUSEDINFO, *LPATIELEMUSEDINFO;

#endif //(DIRECT3D_VERSION >= 0x0900)
/*
 * ATIVTXSHADER structure contains all the ATi specific data
 * that is relevant to each vertex shader.
*/

typedef struct _ATIVTXSHADER
{
    DWORD        dwHandle;         // Shader handle
    DWORD        dwFlags;          // Contain vertex shader related info.

    DWORD        dwFvf;
    DWORD        dwVecUsed;        // Contain input vector(s) used

    // Declaration
    DWORD        dwDeclSize;       // Shader declaration size in bytes
    WORD         wPSCRegs[VS_NUM_PSC_ENTRIES]; // PSC stream definitions

    // Shader code
    DWORD        dwDxCodeSize;     // Size (bytes) of DirectX shader code
    LPVOID       pDxCode;          // Copy of DirectX shader code

    ATIVTXSHADERMEMALLOC pVSCodeMemAlloc;  // Structure to hold code memory info
    ATIVTXSHADERMEMALLOC pVSLocalStateMemAlloc; // Structure to hold state memory info

    LPATIVECTOR  pCode;            // Assembled ATI shader code
    DWORD        dwCodeLength;     // Code length in instructions/vectors
    DWORD        dwLastPosInst;    // Last instruction to update output position vector
    DWORD        dwOutVtxEncoding; // Encoding of the output vertex components

    LPATIVECTOR  pPosCode;         // Assembled ATI shader code for position
    DWORD        dwPosCodeLength;  // Code length in instructions/vectors

    // Shader constant updates
    ATILIST      alConstUpdates;   // Constant data update list (if applicable) associated with the shader
    DWORD        dwNumConstUpdates; // Number of valid entries in the constant update list
    LPATIVECTOR  pConstStore;      // Constant data (if applicable) associated with the shader
    DWORD        dwStateLength;    // max length in vectors of constant data used by this shader

    DWORD        dwNumArrays;                         // Number of vtx arrays used by this shader.
    // add 1 to the following to account for the Tessellator stream
    DWORD        pdwStreamIndex[VS_MAX_NUM_ARRAYS+1]; // Hold stream index for given array
    DWORD        pdwCount[VS_MAX_NUM_ARRAYS+1];       // Hold vertex array's dword count.
    DWORD        pdwOffset[VS_MAX_NUM_ARRAYS+1];      // Hold vertex array's base offset.

    // This structure is set in ParseDeclBody and is used to set
    // up the vertex arrays for ASICs without PSC
    ATIVTXSHADERSTREAMDEF vsStreamDef[VS_MAX_NUM_STREAM_ELEMENTS];

    // Structure used to optimize the PVS code on the 2nd pass
    ATIPVSOPTIMIZATION pvsOptimizeData;

    // used to remember what fields we are generating data for
    WORD         wGenerateDataInfo[ATI_VEC_LOC_ENTRIES];
    DWORD        dwNumRealElements;
    DWORD        dwNumTessElements;
    DWORD        dwStreamIndexReMap[VS_MAX_NUM_ARRAYS+1];

    DWORD        dwCheckSum;

    regSE_VTX_FMT_0     SeVtxFmt0_reg;
    regSE_VTX_FMT_1     SeVtxFmt1_reg;

    // Software vertex shader
    struct _SWVTXSHADER *pSWShader;
#if (DIRECT3D_VERSION >= 0x0900)
    //New for DX9.
    D3DVERTEXELEMENT9  AtiVtxElement[MAXD3DDECLLENGTH];       
    ATIELEMUSEDINFO    AtiElemUsedInfo[MAXD3DDECLLENGTH];    
    ATIDECLMAPPING     AtiDeclMapping[VS_NUM_PSC_ENTRIES];    
    DWORD              dwNumDeclMapping;
    DWORD              dwNumElements;
    DWORD              dwLastDeclMapped;
#endif

} ATIVTXSHADER, *LPATIVTXSHADER;


#if (DIRECT3D_VERSION >= 0x0900)
//We temporarily use same structure ATIVERTEXSHADER as ATIVSDECL and ATIVSFUNC.
//They will be separate later.
/*
 * ATIVSDECL structure contains all the ATi specific data
 * that is relevant to each vertex shader declaration.
*/
typedef ATIVTXSHADER   ATIVSDECL;
typedef LPATIVTXSHADER LPATIVSDECL;

/*
 * ATIVSFUNC structure contains all the ATi specific data
 * that is relevant to each vertex shader function.
*/

typedef ATIVTXSHADER   ATIVSFUNC;
typedef LPATIVTXSHADER LPATIVSFUNC;

#endif // (DIRECT3D_VERSION >= 0x0900)


///////////////////////////////////////////////////////////////////////////////
// Function Prototypes

extern HRESULT VS_CreateVtxShader(LPATID3DCNTX pCtxt,
                                  LPD3DHAL_DP2CREATEVERTEXSHADER pCreateShader);
extern HRESULT VS_SetVtxShader(LPATID3DCNTX pContext, DWORD dwShaderHandle,
                               LPBOOL pbValidFVFCode);
extern void VS_SetVtxShader2(LPATID3DCNTX pCtxt, LPATIVTXSHADER  pAtiVertexShader);
extern HRESULT VS_DeleteVtxShader(LPATID3DCNTX pContext, DWORD dwShaderHandle);
extern VOID    VS_SetGlobalConstStore(LPATID3DCNTX pCtxt, DWORD dwRegStart,
                                      DWORD dwCount, LPATIVECTOR pConstData);
extern VOID VS_CreateConstUpdate(LPATID3DCNTX pCtxt, LPATIVTXSHADER pAtiVtxShader,
                                 DWORD dwStart, DWORD dwCount, LPATIVECTOR pVector);
extern HRESULT AtiSetVertexShader(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *lppCmd);

extern HRESULT AtiSetVertexShaderConst(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *lppCmd);

extern void VS_Stall(LPATIVTXSHADERMEMALLOC pVSMemAlloc, LPD3DDEVICE pD3DDev);

extern void VS_DeleteAllVtxShaders(LPATID3DCNTX pCtxt);

#if (DIRECT3D_VERSION >= 0x0900)
extern HRESULT VS_CreateVSDecl(LPATID3DCNTX pCtxt,
                               D3DHAL_DP2CREATEVERTEXSHADERDECL *pCVSDecl,
                               LPD3DVERTEXELEMENT9 pDecl);
extern HRESULT VS_CreateVSFunc(LPATID3DCNTX pCtxt,
                               D3DHAL_DP2CREATEVERTEXSHADERFUNC *pCVSFunc,
                               LPDWORD pCode);
extern HRESULT AtiSetVertexShaderDecl(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *lppCmd);
extern HRESULT AtiSetVertexShaderFunc(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *lppCmd);
extern HRESULT VS_DeleteVSDecl(LPATID3DCNTX pContext, DWORD dwVSDeclHandle);
extern HRESULT VS_DeleteVSFunc(LPATID3DCNTX pContext, DWORD dwVSFuncHandle);
extern void CombineVSDeclAndFunc(LPATID3DCNTX pCtxt);

extern HRESULT AtiSetVertexShaderConstB(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *lppCmd);
extern HRESULT AtiSetVertexShaderConstI(LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *lppCmd);

#endif // (DIRECT3D_VERSION >= 0x0900)


///////////////////////////////////////////////////////////////////////////////
// inline functions

/******************************************************************************
* __inline DWORD VS_GetComponentSize()
*
* Args:
*   dwDataType
*  
* Returns: Component size in dwords of dwDataType
*
* Description:
*
* Notes:
*
******************************************************************************/
__inline DWORD VS_GetComponentSize(DWORD dwDataType)
{
#if (DIRECT3D_VERSION >= 0x0900)
    switch(dwDataType)
    {
    case D3DDECLTYPE_FLOAT1: // 1D float expanded to (value, 0., 0., 1.)
        return 1;
    case D3DDECLTYPE_FLOAT2: // 2D float expanded to (value, value, 0., 1.)
        return 2;
    case D3DDECLTYPE_FLOAT3: // 3D float expanded to (value, value, value, 1.)
    default:
        return 3;
    case D3DDECLTYPE_FLOAT4: // 4D float
        return 4;
    case D3DDECLTYPE_D3DCOLOR:   // 4D packed unsigned bytes mapped to 0. to 1. range
        return 1;
    case D3DDECLTYPE_UBYTE4:  // 4D unsigned byte
    case D3DDECLTYPE_UBYTE4N: // Each of 4 bytes is normalized by dividing to 255.0
        return 1;
    case D3DDECLTYPE_SHORT2:  // 2D signed short expanded to (value, value, 0., 1.)
    case D3DDECLTYPE_SHORT2N: // 2D unsigned short normalized (v[0]/65535.0, v[1]/65535.0, 0., 1.) 
        return 1;
    case D3DDECLTYPE_SHORT4:  // 4D signed short
    case D3DDECLTYPE_SHORT4N: // 4D unsigned short normalized (v[0]/65535.0, v[1]/65535.0, v[2]/65535.0, v[3]/65535.0)
        return 2;
    case D3DDECLTYPE_FLOAT16_2: // Two 16-bit floating point values, expanding to (value, value, 0., 1.)
        return 1;
    case D3DDECLTYPE_FLOAT16_4: // Four 16-bit floating point values
        return 2;
    case D3DDECLTYPE_DEC3N: // 3D signed 10 10 10 format normalized and expanding to (v[0]/511.0, v[1]/511.0, v[2]/511.0, 1.)
        return 1;
    case D3DDECLTYPE_UDEC3: // 3D signed 10 10 10 format expanding to (value, value, value, 1.)
        return 1;
    }
#else
    switch(dwDataType)
    {
    case D3DVSDT_FLOAT1: // 1D float expanded to (value, 0., 0., 1.)
        return 1;
    case D3DVSDT_FLOAT2: // 2D float expanded to (value, value, 0., 1.)
        return 2;
    case D3DVSDT_FLOAT3: // 3D float expanded to (value, value, value, 1.)
    default:
        return 3;
    case D3DVSDT_FLOAT4: // 4D float
        return 4;
    case D3DVSDT_D3DCOLOR:   // 4D packed unsigned bytes mapped to 0. to 1. range
    //case D3DVSDT_PACKEDBYTE: // Input is in D3DCOLOR format (ARGB) expanded to (R, G, B, A)
        return 1;
    case D3DVSDT_UBYTE4: // 4D unsigned byte
        return 1;
    case D3DVSDT_SHORT2: // 2D signed short expanded to (value, value, 0., 1.)
        return 1;
    case D3DVSDT_SHORT4: // 4D signed short
        return 2;
    }
#endif // (DIRECT3D_VERSION >= 0x0900)

}

/******************************************************************************
* __inline BOOL VS_CheckHandleForFVF()
*
* Args:
*   dwShaderHandle  vertex shader handle
*  
* Returns: TRUE if the handle is an FVF, FALSE if it is an actual shader handle
*
* Description:
*   If zero, the handle is a (NULL) shader.
*   Otherwise, if the least signicant bit is set to 0, the shader
*   is an FVF. Otherwise, it is a shader.
*
* Notes:
*
******************************************************************************/
__inline BOOL VS_CheckHandleForFVF(LPATID3DCNTX pCtxt)
{
    DWORD   dwHandle;

#if (DIRECT3D_VERSION >= 0x0900)
    if (pCtxt->dwDXInterfaceVersion >= ATI_DX9_INTERFACE)
    {
        dwHandle = pCtxt->dwCurrVSDeclHandle;
    }
    else
#endif //(DIRECT3D_VERSION >= 0x0900)
    {
        dwHandle = pCtxt->dwCurrVtxShaderHandle;
    }

    if (dwHandle == 0)
    {
        return FALSE;
    }

    if (dwHandle & 0x00000001)  // There is no MS define for this bit.
    {
        return FALSE; // Not an FVF
    }
    else
    {
        return TRUE;
    }

}

/******************************************************************************
* __inline BOOL ISCurrVSDeclHandleZero()
*
* Args:
*   pCtxt  
*  
* Returns: TRUE if the handle is zero, FALSE if it is not zero.
*
* Description:
*   If zero, the handle is a (NULL) shader.
*   Otherwise, if the least signicant bit is set to 0, the shader
*   is an FVF. Otherwise, it is a shader.
*
* Notes:
*
******************************************************************************/
__inline BOOL ISCurrVSDeclHandleZero(LPATID3DCNTX pCtxt)
{
    DWORD   dwHandle;

#if (DIRECT3D_VERSION >= 0x0900)
    if (pCtxt->dwDXInterfaceVersion >= ATI_DX9_INTERFACE)
    {
        dwHandle = pCtxt->dwCurrVSDeclHandle;
    }
    else
#endif // (DIRECT3D_VERSION >= 0x0900)
    {
        dwHandle = pCtxt->dwCurrVtxShaderHandle;
    }

    if (dwHandle == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}

/******************************************************************************
* __inline BOOL IsPureFVFandNoPVS()
*
* Args:
*   LPATID3DCNTX 
*  
* Returns: TRUE if the handle is an FVF and no PVS, FALSE if it is an actual shader handle or has FVF.
*
* Description:
*
* Notes:
*
******************************************************************************/
__inline BOOL IsPureFVFandNoPVS(LPATID3DCNTX pCtxt)
{
#if (DIRECT3D_VERSION >= 0x0900)
    if (pCtxt->dwDXInterfaceVersion >= ATI_DX9_INTERFACE)
    {
        if (VS_CheckHandleForFVF(pCtxt))
        { 
            if (pCtxt->dwCurrVSFuncHandle && 
                ((pCtxt->dwCurrVSDeclHandle & D3DFVF_POSITION_MASK) != D3DFVF_XYZRHW)) 
            {
                return FALSE;
            }
            else
            {
                return TRUE;
            }
          
        }
        else
        {
            return FALSE;
        }
    }    
    else
#endif //(DIRECT3D_VERSION >= 0x0900)
    {
        return (VS_CheckHandleForFVF(pCtxt));
    }
}

/******************************************************************************
* __inline DWORD VS_CalcBlendWt()
*
* Args:
*   dwDataType
*  
* Returns: 
*
* Description:
*
* Notes:
*
******************************************************************************/
__inline DWORD VS_CalcBlendWt(DWORD dwDataType)
{
#if (DIRECT3D_VERSION >= 0x0900)
    switch (dwDataType)
    {
    case D3DDECLTYPE_FLOAT1: 
        return 1;
    case D3DDECLTYPE_FLOAT2: 
        return 2;
    case D3DDECLTYPE_FLOAT3: 
        return 3;
    case D3DDECLTYPE_FLOAT4: 
        return 4;
    default:
        HSLASSERT((dwDataType == D3DDECLTYPE_FLOAT1) || 
                  (dwDataType == D3DDECLTYPE_FLOAT2) || 
                  (dwDataType == D3DDECLTYPE_FLOAT3) || 
                  (dwDataType == D3DDECLTYPE_FLOAT4));
        return 0;
    }
#else
    switch (dwDataType)
    {
    case D3DVSDT_FLOAT1: 
        return 1;
    case D3DVSDT_FLOAT2: 
        return 2;
    case D3DVSDT_FLOAT3: 
        return 3;
    case D3DVSDT_FLOAT4: 
        return 4;
    default:
        HSLASSERT((dwDataType == D3DVSDT_FLOAT1) || 
                  (dwDataType == D3DVSDT_FLOAT2) || 
                  (dwDataType == D3DVSDT_FLOAT3) || 
                  (dwDataType == D3DVSDT_FLOAT4));
        return 0;
    }
#endif
}

/******************************************************************************
* __inline DWORD VS_HandleToTableIndex()
*
* Args:
*   dwHandle  vertex shader handle
*  
* Returns: the associated vertex shader table index
*
* Description:
*   Returns the associated vertex shader table index from the vertex
*   vertex shader handle
*
* Notes:
*
******************************************************************************/
__inline DWORD VS_HandleToTableIndex(DWORD dwHandle)
{
    return (dwHandle >> 1) - 1;
}



/******************************************************************************
* __inline DWORD VS_TableIndexToHandle()
*
* Args:
*   dwIndex  vertex shader table index
*  
* Returns: the associated vertex shader handle
*
* Description:
*   Returns the associated vertex shader handle from the vertex
*   vertex shader table index
*
* Notes:
*   This currently isn't used, but we may need it someday...
*
******************************************************************************/
__inline DWORD VS_TableIndexToHandle(DWORD dwIndex)
{
    return ((dwIndex+1) << 1) + 1;
}


#if (DIRECT3D_VERSION >= 0x0900)
/******************************************************************************
* __inline LPATIVSDECL VS_GetVSDecl()
*
* Args:
*   dwHandle  vertex shader handle
*  
* Returns: the a pointer to the shader decl if the handle is valid and not zero.
*          Otherwise, it returns NULL.
*
* Description:
*
* Notes:
*   
******************************************************************************/
__inline LPATIVSDECL VS_GetVSDecl(LPATID3DCNTX pCtxt, DWORD dwHandle)
{
    if (dwHandle == 0)
    {
        return NULL;
    }

    return (LPATIVSDECL)AL_GetEntry(&pCtxt->alVSDeclList, 
                                    VS_HandleToTableIndex(dwHandle));
}
/******************************************************************************
* __inline LPATIVSFUNC VS_GetVSFunc()
*
* Args:
*   dwHandle  vertex shader handle
*  
* Returns: the a pointer to the shader func if the handle is valid and not zero.
*          Otherwise, it returns NULL.
*
* Description:
*
* Notes:
*   
******************************************************************************/
__inline LPATIVSFUNC VS_GetVSFunc(LPATID3DCNTX pCtxt, DWORD dwHandle)
{
    if (dwHandle == 0)
    {
        return NULL;
    }

    return (LPATIVSFUNC)AL_GetEntry(&pCtxt->alVSFuncList, dwHandle);
}

__inline BOOL IsPositionTHandle(LPATID3DCNTX pCtxt)
{
    if (pCtxt->dwDXInterfaceVersion >= ATI_DX9_INTERFACE)
    {
        LPATIVSDECL pAtiVSDecl = VS_GetVSDecl(pCtxt, pCtxt->dwCurrVSDeclHandle);
        
        if (pAtiVSDecl && pAtiVSDecl->dwFlags & VS_DECL_POSITIONT)
        { 
            return TRUE;          
        }
        else
        {
            return FALSE;
        }
    }    
    else
    {
        return FALSE;
    }
}

#endif //(DIRECT3D_VERSION >= 0x0900)

/******************************************************************************
* __inline LPATIVTXSHADER VS_GetShader()
*
* Args:
*   dwHandle  vertex shader handle
*  
* Returns: the a pointer to the shader if the handle is valid and not zero.
*          Otherwise, it returns NULL.
*
* Description:
*
* Notes:
*   
******************************************************************************/
__inline LPATIVTXSHADER VS_GetShader(LPATID3DCNTX pCtxt)
{
#if (DIRECT3D_VERSION >= 0x0900)
    if (pCtxt->dwDXInterfaceVersion >= ATI_DX9_INTERFACE)
    {
        LPATIVSDECL pAtiVSDecl;

        if (pCtxt->dwCurrVSDeclHandle == 0)
        {
            return  NULL;
        }

        pAtiVSDecl = VS_GetVSDecl(pCtxt, pCtxt->dwCurrVSDeclHandle);
    if (!pAtiVSDecl)
    {
        return NULL;
    }

        if ((pAtiVSDecl->dwFlags & VS_DECL_POSITIONT) || (pCtxt->dwCurrVSFuncHandle == 0))
        {
            return ((LPATIVTXSHADER) pAtiVSDecl);
        }

        return (LPATIVTXSHADER)VS_GetVSFunc(pCtxt, pCtxt->dwCurrVSFuncHandle);
    }
    else
#endif //(DIRECT3D_VERSION >= 0x0900)
    {
        if (pCtxt->dwCurrVtxShaderHandle == 0)
        {
            return NULL;
        }

        return (LPATIVTXSHADER)AL_GetEntry(&pCtxt->alVertexShaderList, 
                                           VS_HandleToTableIndex(pCtxt->dwCurrVtxShaderHandle));
    }
}

/******************************************************************************
* __inline LPATIVECTOR VS_AllocVectors()
*
* Args:
*   pCtxt             Current context
*   dwNumVectors      number of vectors to allocate
*  
* Returns: pointer to allocated vector space; NULL otherwise
*
* Description:
*   Allocates the dwNumVectors number of ATIVECTORS from system memory
*   for the caller
*
* Notes:
*   Use VS_FreeVectors() to free the allocated memory
*   
******************************************************************************/
__inline LPATIVECTOR VS_AllocVectors(LPATID3DCNTX pCtxt, DWORD dwNumVectors)
{
    LPD3DDEVICE             lpD3DDev = GetD3DDevice(pCtxt);
    LPATIVECTOR             pVectors = NULL;
    DWORD                   dwSize   = 0;
       
    if (dwNumVectors > (ULONG_MAX / sizeof(ATIVECTOR)))  // Handle overflow
    {
        HSLDPF(E_ERROR_MESSAGE, "Error! VS_AllocVectors: dwSize will overflow");
        return NULL;
    }

    dwSize   = dwNumVectors * sizeof(ATIVECTOR);

    pVectors = 
        (LPATIVECTOR)pDdHslSharedMemCallocEx(GetATIDeviceInfo(lpD3DDev), dwSize);
    if (NULL == pVectors)
    {
        HSLDPF(E_ERROR_MESSAGE, 
               "Error! VS_AllocVectors: Allocation failed");
    }
    
    return pVectors;
}


/******************************************************************************
* __inline LPATIVECTOR VS_AllocVectorsEx()
*
* Args:
*   pCtxt             Current context
*   dwNumVectors      number of vectors to allocate
*  
* Returns: pointer to allocated vector space; NULL otherwise
*
* Description:
*   Allocates the dwNumVectors number of ATIVECTORS from memory
*   for the caller
*
* Notes:
*   If a vertexshader is passed in, we assume that PVS code is trying to be 
*   stored.  We will try to store PVS code allocate from video memory.  If a 
*   vertexshader is not passed in, the memory will be allocated from system memory.
*
*   Use VS_FreeVectors() to free the allocated memory
*   
******************************************************************************/
__inline LPATIVECTOR VS_AllocVectorsEx(LPATID3DCNTX pCtxt, DWORD dwNumVectors, 
                                       LPATIVTXSHADERMEMALLOC pVSMemAlloc, DWORD dwMemFlags)
{
    LPDDRAWI_DIRECTDRAW_GBL pDdGbl   = pCtxt->lpDDGbl;
    LPD3DDEVICE             pD3DDev  = pCtxt->pD3DDevice;
    LPATIVECTOR             pVectors = NULL;
    DWORD                   dwSize   = 0;
       
    if (dwNumVectors > (ULONG_MAX / sizeof(ATIVECTOR)))  // Handle overflow
    {
        HSLDPF(E_ERROR_MESSAGE, "Error! VS_AllocVectorsEx: dwSize will overflow");
        return NULL;
    }

    dwSize   = dwNumVectors * sizeof(ATIVECTOR);

    if (pVectors == NULL)
    {
        // If we're here either we:
        //    - are forcing the PVS code to be placed in system memory
        //    - have no free video memory for the PVS code
        pVectors = (LPATIVECTOR)pDdHslSharedMemCallocEx(GetATIDeviceInfo(pD3DDev), dwSize);
        if (NULL == pVectors)
        {
            HSLDPF(E_ERROR_MESSAGE, "Error! VS_AllocVectorsEx: Allocation failed");
        }
    }

    HSLDPF(E_VERTEXSHADER_DATA, "VS_AllocVectorsEx: Total PVS allocated...AGP: %08x  FB: %08x", 
           pD3DDev->dwPVSAgpAllocated, pD3DDev->dwPVSLocalAllocated);
    return pVectors;
}



/******************************************************************************
* __inline VOID VS_FreeVectors()
*
* Args:
*   pCtxt          Current context
*   pVectors      pointer to ATIVECTORs to free
*  
* Returns: N/A
*
* Description:
*   Frees prior allocated ATIVECTORS via the VS_AllocVectors routine
*
* Notes:
*   Used in conjunction with VS_AllocVectors()
*   
******************************************************************************/
__inline VOID VS_FreeVectors(LPATID3DCNTX pCtxt, LPATIVECTOR pVectors)
{
    LPD3DDEVICE pD3DDev = pCtxt->pD3DDevice;
    
    if (NULL != pVectors)
    {
        bDdHslSharedMemFreeEx(GetATIDeviceInfo(pD3DDev), pVectors);
    }
}



/******************************************************************************
* __inline VOID VS_FreeVectorsEx()
*
* Args:
*   pCtxt          Current context
*   pVectors      pointer to ATIVECTORs to free
*  
* Returns: N/A
*
* Description:
*   Frees prior allocated ATIVECTORS via the VS_AllocVectors routine
*
* Notes:
*   Used in conjunction with VS_AllocVectors()
*   
******************************************************************************/
__inline VOID VS_FreeVectorsEx(LPATID3DCNTX pCtxt, LPATIVECTOR pVectors, LPATIVTXSHADERMEMALLOC pVSMemAlloc)
{
    LPDDRAWI_DIRECTDRAW_GBL pDdGbl     = pCtxt->lpDDGbl;
    LPD3DDEVICE             pD3DDev    = pCtxt->pD3DDevice;
    LPVOID                  lpATIDXObj = GetATIDeviceInfo(pD3DDev);

    if (pD3DDev->AtiD3dRegistry.bIsVbDdHeapsEnabled)
    {
        VS_Stall(pVSMemAlloc, pD3DDev);

        if (pVSMemAlloc->pCodeData.lpVideoMemory != NULL)
        {
            if (pVSMemAlloc->dwAllocFlags & VS_CODE_IN_AGP_MEM)
            {
                bDdHslVideoMemoryFree(lpATIDXObj, pDdGbl,
                                      &(pVSMemAlloc->pCodeData),
                                      E_VIDMEM_HEAP_AGP);

                pD3DDev->dwPVSAgpAllocated -= pVSMemAlloc->QS_ListSize;
                pVSMemAlloc->pCodeData.lpVideoMemory = NULL;
            }
            else if (pVSMemAlloc->dwAllocFlags & VS_CODE_IN_FB_MEM)
            {
                bDdHslVideoMemoryFree(lpATIDXObj, pDdGbl,
                                      &(pVSMemAlloc->pCodeData),
                                      E_VIDMEM_HEAP_FRAMEBUFFER);

                pD3DDev->dwPVSLocalAllocated -= pVSMemAlloc->QS_ListSize;
                pVSMemAlloc->pCodeData.lpVideoMemory = NULL;
            }
        }
        else // Could be system mem
        {
            if (NULL != pVectors)
            {
                bDdHslSharedMemFreeEx(GetATIDeviceInfo(pD3DDev), pVectors);
            }
        }
    }
    else
    {
        if ((pVSMemAlloc->dwAllocFlags & VS_CODE_IN_AGP_MEM))
        {
            QS_PARAM       *pQSParam    = pD3DDev->pQSParam;
            QS_FUNC2       *pQS_APIFunc = pD3DDev->pQS_APIFunc;
            QS_RETURNCODE   qsRet       = QS_OK;

            pQSParam->lTimeStamp = pD3DDev->TimeStampArray[pVSMemAlloc->dwPVSPendingCB_ID].QsTstamp;
            pQSParam->hInList = pVSMemAlloc->QS_HInList;
            pQSParam->dwFlags = QS_FLAG_FREE_ONTIMESTAMP;

            qsRet = pQS_APIFunc->QSFreeList2(pD3DDev->QSHDevice, pQSParam);

            if (qsRet != QS_OK)
            {
                HSLDPF(E_ERROR_MESSAGE, "VS_FreeVectors: QSFreeList returning error!");
            }

            pD3DDev->dwPVSAgpAllocated -= pVSMemAlloc->QS_ListSize;
        }
        else // system memory
        {
            if (NULL != pVectors)
            {
                bDdHslSharedMemFreeEx(GetATIDeviceInfo(pD3DDev), pVectors);
            }
        }
    }
    pVectors = NULL;
    HSLDPF(E_VERTEXSHADER_DATA, "VS_FreeVectorsEx: Total PVS allocated...AGP: %08x  FB: %08x", 
           pD3DDev->dwPVSAgpAllocated, pD3DDev->dwPVSLocalAllocated);
}


/******************************************************************************
* __inline BOOL VS_AllocDxCodeStore()
*
* Args:
*   pAtiVtxShader     ATI Vertex Shader structure to contain the allocated
*                     DirectX code store
*   dwDxCodeSize      Size in bytes of the DirectX code store
*  
* Returns: TRUE if allocation was successful; FALSE otherwise
*
* Description:
*   Allocates dwDxCodeSize bytes for the DirectX vertex shader code store
*   and stores the code size and pointer to store in the ATI shader structure
*
* Notes:
*   Use VS_FreeDxCodeStore() to free the allocated memory
*   
******************************************************************************/
__inline BOOL VS_AllocDxCodeStore(LPVOID lpATIDXObj, LPATIVTXSHADER pAtiVtxShader, DWORD dwDxCodeSize)
{
    pAtiVtxShader->pDxCode = 
        (LPATIVTXSHADER)pDdHslSharedMemCallocEx(lpATIDXObj, dwDxCodeSize);
    if (NULL == pAtiVtxShader->pDxCode)
    {
        return FALSE;
    }

    pAtiVtxShader->dwDxCodeSize = dwDxCodeSize;
    
    return TRUE;
}



/******************************************************************************
* __inline VOID VS_FreeDxCodeStore()
*
* Args:
*   pAtiVtxShader     ATI Vertex Shader structure that contains the allocated
*                     DirectX code store
*  
* Returns: N/A
*
* Description:
*   Frees prior allocated DirectX vertex shader code store
*
* Notes:
*   Used in conjunction with VS_AllocDxCodeStore()
*   
******************************************************************************/
__inline VOID VS_FreeDxCodeStore(LPVOID lpATIDXObj, LPATIVTXSHADER pAtiVtxShader)
{
    if (pAtiVtxShader->pDxCode)
    {
        bDdHslSharedMemFreeEx(lpATIDXObj, pAtiVtxShader->pDxCode);
        pAtiVtxShader->pDxCode = NULL;
    }
    pAtiVtxShader->dwDxCodeSize = 0;
}


/******************************************************************************
* __inline DWORD ATI_D3DSI_GETCOMMENTSIZE()
*
* Args:
*   dwInst  DirectX shader comment instruction
*  
* Returns: N/A
*
* Description:
*   Returns the size of the shader comment instruction
*
* Notes:
*   This really should be provided by Microsoft.
*   
******************************************************************************/
__inline DWORD ATI_D3DSI_GETCOMMENTSIZE(DWORD dwInst)
{
  return (((dwInst) & D3DSI_COMMENTSIZE_MASK) >> D3DSI_COMMENTSIZE_SHIFT);
}

/******************************************************************************
* __inline VOID VS_ResetOptimizationStruct()
*
* Args:
*   pPvsOptData  pointer to PVS optimization struct
*  
* Returns: zilch
*
* Description:
*   Clears the structure of all optimizations
*
* Notes:
*   
******************************************************************************/
__inline VOID VS_ResetOptimizationStruct(LPATIPVSOPTIMIZATION pPvsOptData)
{
    // Use only computed values
    pPvsOptData->pvsRegSeTclOutVtxCompSel.u32All = 0xffffffff;

    SetTclRad2InputVertexAddrCmdHeaders(&pPvsOptData->pvsInputVecAddr);
    set_SE_TCL_INPUT_VTX_VECTOR_ADDR_1_vtx_color_0_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr1, ATI_VEC_LOC_COLOR0);
    set_SE_TCL_INPUT_VTX_VECTOR_ADDR_1_vtx_color_1_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr1, ATI_VEC_LOC_COLOR1);

    set_SE_TCL_INPUT_VTX_VECTOR_ADDR_2_vtx_tex_0_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr2, ATI_VEC_LOC_TEXTURE0);
    set_SE_TCL_INPUT_VTX_VECTOR_ADDR_2_vtx_tex_1_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr2, ATI_VEC_LOC_TEXTURE1);
    set_SE_TCL_INPUT_VTX_VECTOR_ADDR_2_vtx_tex_2_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr2, ATI_VEC_LOC_TEXTURE2);
    set_SE_TCL_INPUT_VTX_VECTOR_ADDR_2_vtx_tex_3_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr2, ATI_VEC_LOC_TEXTURE3);

    set_SE_TCL_INPUT_VTX_VECTOR_ADDR_3_vtx_tex_4_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr3, ATI_VEC_LOC_TEXTURE4);
    set_SE_TCL_INPUT_VTX_VECTOR_ADDR_3_vtx_tex_5_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr3, ATI_VEC_LOC_TEXTURE5);
}

/******************************************************************************
* __inline VOID VS_SetStreamDefinition()
*
* Args:
*   
*  
* Returns: N/A
*
* Description:
*   Sets up the stream definition so that the AOS can be set properly
*
* Notes:
*   
******************************************************************************/
__inline VOID VS_SetStreamDefinition(LPATIVTXSHADER pAtiVtxShader, DWORD dwElementType, 
                                     DWORD dwStream, DWORD dwOffset, DWORD dwComponentSize,
                                     DWORD dwComponentStride)
{
    pAtiVtxShader->vsStreamDef[dwElementType].dwStream = dwStream;
    pAtiVtxShader->vsStreamDef[dwElementType].dwOffset = dwOffset;
    pAtiVtxShader->vsStreamDef[dwElementType].dwSize   = dwComponentSize;
    pAtiVtxShader->vsStreamDef[dwElementType].dwStride = dwComponentStride;
}

/******************************************************************************
* __inline VOID VS_InitializeStreamDef()
*
* Args:
*   
*  
* Returns: N/A
*
* Description:
*  Initializes the stream definition struct
*
* Notes:
*   
******************************************************************************/
__inline VOID VS_InitializeStreamDef(LPATIVTXSHADER pAtiVtxShader)
{
    DWORD i;

    for (i = 0; i < VS_MAX_NUM_STREAM_ELEMENTS; i++)
    {
        pAtiVtxShader->vsStreamDef[i].dwStream = VS_STREAM_UNDEFINED;
    }
}


#endif


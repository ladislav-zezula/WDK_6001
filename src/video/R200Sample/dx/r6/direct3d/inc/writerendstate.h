

//    
//  File: writerendstate.h
//
//  Description: Header file for writerendstate.c
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//
#ifndef ATI_WRITERENDSTATE_H
#define ATI_WRITERENDSTATE_H

#include "d3dcntx.h"
#include "atiddhsl.h"


DWORD GetStateSizeNeeded(LPATID3DCNTX lpATID3DCntx);
void Rad2SetRenderStateToHw(LPATID3DCNTX lpATID3DCntx);
DWORD Rad2RecalcTexStages(LPATID3DCNTX pContext, DWORD dwMaxStage);
void UpdateTextureContext(LPATID3DCNTX pCtxt);

PDWORD EmbedGenericHandleIntoCmdBuf(PDWORD pdwCmdBuf, LPATID3DCNTX pCtxt, D3DResourceID ResID, D3DKMT_HANDLE hSurf);


__inline PDWORD EmbedSurfHandleIntoCmdBuf(PDWORD pdwCmdBuf, LPATID3DCNTX pCtxt, D3DResourceID ResID)
{
    LPATISURFCNTX   pSurfCtx;
    D3DKMT_HANDLE   hSurf;

    HSLASSERT(ResID < D3D_RES_STREAM_0 || ResID > D3D_RES_INDEX_BUFFER);

    pdwCmdBuf[0] = PM4_PACKET3_LDDM_HANDLE(ResID);
    pSurfCtx=(LPATISURFCNTX)pCtxt->resSurfArray[ResID];    
    if (pSurfCtx != NULL && pSurfCtx->dwLockCount == 0)
    {
        hSurf=pSurfCtx->hAllocation;
    }
    else
    {
        hSurf=0;
    }
    *((D3DKMT_HANDLE *)(pdwCmdBuf + 1)) = hSurf;

    return pdwCmdBuf+(1 + sizeof(D3DKMT_HANDLE)/sizeof(DWORD));
}

__inline PDWORD EmbedCubeMapFaceHandleIntoCmdBuf(PDWORD pdwCmdBuf, LPATID3DCNTX pCtxt, DWORD dwSurfIdx, DWORD dwFaceIdx)
{
    LPATISURFCNTX   pSurfCtx;
    D3DResourceID   ResID;   
    D3DKMT_HANDLE   hSurf;

    HSLASSERT(dwSurfIdx <= 5);
    HSLASSERT(dwFaceIdx >= 1 && dwFaceIdx <= 6);

    ResID = (D3D_RES_TEXTURE_0 + dwSurfIdx*6 + dwFaceIdx);
    pdwCmdBuf[0] = PM4_PACKET3_LDDM_HANDLE(ResID);
    pSurfCtx=(LPATISURFCNTX)pCtxt->resSurfArray[ResID];     
    if (pSurfCtx != NULL && pSurfCtx->dwLockCount == 0)
    {
        hSurf=pSurfCtx->ActiveTextureInfo.hCubeAllocation[dwFaceIdx];
    }
    else
    {
        hSurf=0;
    }
    *((D3DKMT_HANDLE *)(pdwCmdBuf + 1)) = hSurf;

    return pdwCmdBuf+(1 + sizeof(D3DKMT_HANDLE)/sizeof(DWORD));
}

__inline PDWORD EmbedVBHandleIntoCmdBuf(PDWORD pdwCmdBuf, LPATID3DCNTX pCtxt, D3DResourceID ResID)
{
    LPATIVERTEXBUFFER pVB;
    D3DKMT_HANDLE   hSurf;

    HSLASSERT(ResID >= D3D_RES_STREAM_0 && ResID <= D3D_RES_INDEX_BUFFER);

    pdwCmdBuf[0] = PM4_PACKET3_LDDM_HANDLE(ResID);
    pVB=(LPATIVERTEXBUFFER)pCtxt->resSurfArray[ResID]; 
    if (pVB != NULL)
    {
        hSurf=pVB->sVtxListData.hAllocation;
    }
    else
    {
        hSurf=0;
    }    
    *((D3DKMT_HANDLE *)(pdwCmdBuf + 1)) = hSurf;

    return pdwCmdBuf+(1 + sizeof(D3DKMT_HANDLE)/sizeof(DWORD));
}


__inline PDWORD EmbedIBHandleIntoCmdBuf(PDWORD pdwCmdBuf, LPATID3DCNTX pCtxt)
{
    LPATIVERTEXBUFFER pVB;
    D3DKMT_HANDLE   hSurf;

    pVB=(LPATIVERTEXBUFFER)pCtxt->resSurfArray[D3D_RES_INDEX_BUFFER];
    if (pVB != NULL)
    {
        hSurf=pVB->sVtxListData.hAllocation;
    }
    else
    {
        hSurf=0;
    }    
    
    pdwCmdBuf[0]                        = PM4_PACKET3_LDDM_HANDLE(D3D_RES_INDEX_BUFFER);
    *((D3DKMT_HANDLE *)(pdwCmdBuf + 1)) = hSurf;
    pdwCmdBuf                          += (1 + sizeof(D3DKMT_HANDLE)/sizeof(DWORD));
        
    pdwCmdBuf[0]                        = PM4_PACKET3_LDDM_HANDLE(D3D_RES_GUI_DMA_SRC);
    *((D3DKMT_HANDLE *)(pdwCmdBuf + 1)) = hSurf;
    pdwCmdBuf                          += (1 + sizeof(D3DKMT_HANDLE)/sizeof(DWORD));

    return pdwCmdBuf;
}



/*****************************************************************************
*  __inline int FloatToFixed(float val, DWORD int_bits, DWORD frac_bits)
*
* Args:
*       val       (in)  input float value
*       int_bits  (in)  number of integer bits (includes sign bit)
*       frac_bits (in)  number of fractional bits
*
* Returns: Fixed point two's complement number.
*          High-end bits past the sign bit are 0's.
*
* Description:
*       converts from floating point into a fixed point number.
* NOTES:
*   The current implementation is straightforward, but could be
*   optimized.
*
******************************************************************************/

__inline int FloatToFixed(float val, DWORD int_bits, DWORD frac_bits)
{
    int rval;

    if (val == 0.0f)
    {
        rval = 0;
    }
    else
    {
        // first, determine the largest positive and negative numbers we can
        // represent, and clamp the input to that valid range.

        float maxVal = (float)(0x0001 << (int_bits-1)) -
                       (1.0f / (float)(0x0001 << frac_bits));          // largest positive
        float minVal = (float) -(0x0001 << (int_bits-1));              // largest negative


        HSLASSERT(int_bits + frac_bits <= 32);    // cant handle more than 32 bits.

        if (val > maxVal) val = maxVal;           // clamp to valid range.
        if (val < minVal) val = minVal;

        rval = (int) (val * (0x00001 << frac_bits));

        rval &= 0xFFFFFFFF - (0xFFFFFFFF << (int_bits + frac_bits));  // mask off unused bits.
    }

    /*********************
    {
    char buf[80];
    sprintf(buf, "FloatToFixed: In:%f,  Out:0x%08x", val, rval);
    HSLDPF(E_DEBUG1, buf);
    }
    **********************/
    return rval;
}

/*****************************************************************************
*  __inline int FloatToUnsignedFixed(float val, DWORD int_bits, DWORD frac_bits)
*
* Args:
*       val       (in)  input float value
*       int_bits  (in)  number of integer bits 
*       frac_bits (in)  number of fractional bits
*
* Returns: Fixed point unsigned number.
*
* Description:
*       converts from float into a fixed point unsigned number.
* NOTES:
*   The current implementation is straightforward, but could be
*   optimized.
*
******************************************************************************/

__inline int FloatToUnsignedFixed(float val, DWORD int_bits, DWORD frac_bits)
{
    int rval;

    // clamp all negative numbers to zero
    if (val <= 0.0f)
    {
        rval = 0;
    }
    else if (val > 0.0f)
    {
        // determine the largest number we can represent, and clamp to that valid range.
        float maxVal = (float)(0x0001 << int_bits) -
                       (1.0f / (float)(0x0001 << frac_bits));

        HSLASSERT(int_bits + frac_bits <= 32);    // cant handle more than 32 bits.

        if (val > maxVal) 
        {
            val = maxVal;           // clamp to valid range.
        }

        rval = (int) (val * (0x00001 << frac_bits));

        rval &= 0xFFFFFFFF - (0xFFFFFFFF << (int_bits + frac_bits));  // mask off unused bits.
    }

    /*********************
    {
    char buf[80];
    sprintf(buf, "FloatToFixed: In:%f,  Out:0x%08x", val, rval);
    HSLDPF(E_DEBUG1, buf);
    }
    **********************/
    return rval;
}


// Macros for writing to PM4 buffers where the PM4Entries
// have already been reserved
//

#define SET_REG_SEQ_PM4(dwRegAddr, FirstRegVal, dwNumRegs)      \
{                                                               \
    *pdwPm4++ = MakeRegWriteConsec((dwRegAddr), (dwNumRegs));   \
    memcpy(pdwPm4, &(FirstRegVal), (dwNumRegs)*4);              \
    pdwPm4 += (dwNumRegs);                                      \
}

#define SET_ONE_REG_PM4(dwRegAddr, dwRegVal)    \
{                                               \
    *pdwPm4++ = (dwRegAddr);                    \
    *pdwPm4++ = (dwRegVal);                     \
}

__inline LPDWORD SetOneRegPM4(LPDWORD pdwOutput, DWORD dwRegAddr, DWORD dwRegVal)
{
    LPDWORD pdwPm4 = pdwOutput;
    *pdwPm4++ = MakeRegWriteConsec(dwRegAddr, 1);
    *pdwPm4++ = dwRegVal;
    return pdwPm4;
}

__inline LPDWORD SetRegSeqPM4(LPDWORD pdwOutput, DWORD dwFirstRegAddr, LPDWORD pdwRegVal, DWORD dwNumRegs)
{
    LPDWORD pdwPm4 = pdwOutput;
    *pdwPm4++ = MakeRegWriteConsec(dwFirstRegAddr, dwNumRegs);
    memcpy(pdwPm4, pdwRegVal, dwNumRegs*sizeof(DWORD));
    pdwPm4 += dwNumRegs;
    return pdwPm4;
}


__inline LPDWORD SetTclVectorSeqPM4(LPDWORD pdwOutput,
                                    DWORD dwOctwordOffset, DWORD dwOctwordStride,
                                    LPATIVECTOR pVectors, DWORD dwNumVectors)
{
    LPDWORD pdwUpdatedOut = pdwOutput;
    DWORD   dwNumDwords = (dwNumVectors << 2);

    pdwUpdatedOut[0] = mmSE_TCL_VECTOR_INDX_REG;
    pdwUpdatedOut[1] = (dwOctwordStride << 16) | dwOctwordOffset;
    pdwUpdatedOut[2] = MakeRegWriteNonConsec(mmSE_TCL_VECTOR_DATA_REG, dwNumDwords);
    AtiDwordCopy(&pdwUpdatedOut[3], (LPDWORD)pVectors, dwNumDwords);

    pdwUpdatedOut += dwNumDwords + 3;
    return pdwUpdatedOut;
}


__inline LPDWORD SetTclScalarSeqPM4(LPDWORD pdwOutput,
                                    DWORD dwDwordOffset, DWORD dwDwordStride,
                                    LPDWORD pScalars, DWORD dwNumScalars)
{
    LPDWORD pdwUpdatedOut = pdwOutput;

    pdwUpdatedOut[0] = mmSE_TCL_SCALAR_INDX_REG;
    pdwUpdatedOut[1] = (dwDwordStride << 16) | dwDwordOffset;
    pdwUpdatedOut[2] = MakeRegWriteNonConsec(mmSE_TCL_SCALAR_DATA_REG, dwNumScalars);
    AtiDwordCopy(&pdwUpdatedOut[3], pScalars, dwNumScalars);

    pdwUpdatedOut += dwNumScalars+3;

    return pdwUpdatedOut;
}

#endif // ATI_WRITERENDSTATE_H





//
//  $Workfile: vertexarray.h $
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _VERTEXARRAY_H__
#define _VERTEXARRAY_H__

#include "cast.h"


#ifdef DEBUG
#define USE_VBNOP_DUMPPKT
#define VBNOP_DUMPPKT_DWORDS (1 + ATI_MAX_NUM_AOS*(sizeof(PVOID)/sizeof(DWORD)))
#define IBNOP_DUMPPKT_DWORDS (1 + sizeof(PVOID)/sizeof(DWORD))
#else
#define VBNOP_DUMPPKT_DWORDS 0
#define IBNOP_DUMPPKT_DWORDS 0
#endif
#define VBNOP_DUMPPKT_CODE          0xC6
#define IBNOP_DUMPPKT_CODE          0xC7
#define IBNOP_GUI_DMA_DUMPPKT_CODE  0xC8

extern void vAOS_Initialize(LPATID3DCNTX pCtxt);

extern void vAOS_BindVbToVtxArray(LPATID3DCNTX pCtxt, LPATIVERTEXBUFFER pVb, INT dwArrayIndex,
                                  INT dwOffset, DWORD dwStride, DWORD dwCount);

extern VOID vAOS_UpdateVtxArray(LPATID3DCNTX pCtxt, INT dwBaseVtxIndex);
extern VOID vAOS_UpdateVtxArrayMultiStream(LPATID3DCNTX pCtxt, INT	dwBaseVtxIndex, DWORD dwMinIndex, DWORD dwVertexNum);
extern VOID vAOS_UpdateVtxArraySingleStream(LPATID3DCNTX pCtxt, INT dwBaseVtxByteOffset);

extern LPDWORD pdwAOS_WriteState(LPATID3DCNTX pCtxt, LPDWORD pdwPm4);

extern void vAOS_InvalidateArrays(LPATID3DCNTX pCtxt);
extern BOOL vAOS_IsVBInSysMem(LPATID3DCNTX pCtxt);
extern void vAOS_SetTStampInfoForVBs(LPATID3DCNTX pCtxt, LPD3DCMDBUFF lpCmdB);


#if (DIRECT3D_VERSION >= 0x0900)
extern void vCopyQuadXYToPM4ForAALine(LPDWORD pdwSrc, PDWORD pdwDest, LPATIVTXARRAY pVa, DWORD dwIndex, float x, float y);
extern void vCalDeltaXYForAALine(LPATID3DCNTX pCtxt, PDWORD pdwSrc, PDWORD pdwSrcNext, float *pX, float *pY);
#endif  //#if (DIRECT3D_VERSION >= 0x0900)



__inline DWORD vAOS_ComputeVertexSize(LPATID3DCNTX pCtxt)
{
    DWORD         dwI, dwSizeByte;
    LPATIVTXARRAY pVa;

    {
        pVa        = pCtxt->lpVtxArray;
        dwSizeByte = 0;

        for (dwI = 0; dwI < pCtxt->SeVtxNumArrays_reg.bitfields.VTX_NUM_ARRAYS; dwI++)
        {
            dwSizeByte += (pVa->dwCount << 2);

            pVa++;
        }

        if (pCtxt->dwReArrangeVtxElement & ARRANGE_CHANGESIZE)
        {
            HSLASSERT(pCtxt->SeVtxNumArrays_reg.bitfields.VTX_NUM_ARRAYS == 1);
#if (DIRECT3D_VERSION >= 0x0900)
            dwSizeByte = pCtxt->dwDxVtxHwSize;
#endif
            dwSizeByte -= (((pCtxt->dwReArrangeVtxElement & 0xFFFF0000)>>16) *sizeof(D3DVALUE));
        }
#if (DIRECT3D_VERSION >= 0x0900)
        if (pCtxt->dwReArrangeVtxElement & ARRANGE_SKIP_PSIZE)
        {
            HSLASSERT(pCtxt->SeVtxNumArrays_reg.bitfields.VTX_NUM_ARRAYS == 1);
            dwSizeByte -= sizeof(D3DVALUE);
        }
#endif
        return dwSizeByte;
    }
}

_inline LPDWORD DX8CopyOneVertexData(LPATID3DCNTX pCtxt,LPDWORD pdwDest,LPDWORD lpStart)
{
    DWORD       dwStage;
    LPTEXSTAGE  lpStage;
    LPBYTE      lpTexCoordOffsets;
    DWORD       dwCopySize;
    DWORD       dwFVFHwSize = vAOS_ComputeVertexSize(pCtxt);

#if (DIRECT3D_VERSION >= 0x0900)
    if (pCtxt->dwReArrangeVtxElement & ARRANGE_SKIP_PSIZE)
    {
        DWORD   dwAfterPSize;
        dwCopySize=pCtxt->dwTexCoordOffset<<2;

        //copy vertex date before PSIZE
        memcpy(pdwDest,lpStart,pCtxt->dwPSizeOffset);
        pdwDest= (DWORD *)((LPBYTE)pdwDest + pCtxt->dwPSizeOffset);

        // Copy vertex date after PSIZE and before texture coordinate,
        // if the data size is not equal to zero.  Also, handle any potential overflows.
        dwAfterPSize = (dwCopySize > sizeof(D3DVALUE)) ? dwCopySize - pCtxt->dwPSizeOffset - sizeof(D3DVALUE) : 0;

        if (dwAfterPSize != 0 && dwAfterPSize < (dwCopySize - sizeof(D3DVALUE)))  
        {
            memcpy(pdwDest,((LPBYTE)lpStart + pCtxt->dwPSizeOffset + sizeof(D3DVALUE)),dwAfterPSize);
            pdwDest= (DWORD *)((LPBYTE)pdwDest + dwAfterPSize);
        }

        if (pCtxt->dwReArrangeVtxElement & (~ARRANGE_SKIP_PSIZE))
        {
            //copy texture coordinate sets.
            for (dwStage = 0; dwStage<ATI_MAX_NUM_TEX_UNITS && dwCopySize<dwFVFHwSize; dwStage++)
            {
                lpStage     = &pCtxt->texStageInfo.TexStageList[dwStage];
                dwCopySize += 2*sizeof(D3DVALUE);
                lpTexCoordOffsets = (LPBYTE)lpStart +
                                    pCtxt->dwTexCoordSetOffset[lpStage->dwState[D3DTSS_TEXCOORDINDEX]&0xFFFF];
                memcpy(pdwDest, lpTexCoordOffsets, 2*sizeof(D3DVALUE));
                pdwDest = (DWORD *)((LPBYTE)pdwDest + 2*sizeof(D3DVALUE));
            }
        }
        else
        {
            DWORD dwTempSize = dwFVFHwSize - (dwCopySize-sizeof(D3DVALUE));
            if (dwTempSize)
            {
                //copy texture coordinate sets.
                memcpy(pdwDest,(LPBYTE)lpStart + (pCtxt->dwTexCoordOffset<<2), dwTempSize);
                pdwDest = (DWORD *)((LPBYTE)pdwDest + dwTempSize);
            }
        }
    }
    else
#endif  //(DIRECT3D_VERSION >= 0x0900)
    {
        //copy vertex date.
        dwCopySize=pCtxt->dwTexCoordSetOffset[0];
        memcpy(pdwDest, lpStart, dwCopySize);
        pdwDest= (DWORD *)((LPBYTE)pdwDest + dwCopySize);

        //copy texture coordinate sets.
        for (dwStage = 0; (dwStage<ATI_MAX_NUM_TEX_UNITS) && (dwCopySize<dwFVFHwSize); dwStage++)
        {
            lpStage     = &pCtxt->texStageInfo.TexStageList[dwStage];
            dwCopySize += pCtxt->dwHWSizeofTexCoordSet[dwStage];
            lpTexCoordOffsets = (LPBYTE)lpStart + pCtxt->dwTexCoordSetOffset[lpStage->dwState[D3DTSS_TEXCOORDINDEX]&0xFFFF];
            memcpy(pdwDest, lpTexCoordOffsets, pCtxt->dwHWSizeofTexCoordSet[dwStage]);
            pdwDest = (DWORD *)((LPBYTE)pdwDest + pCtxt->dwHWSizeofTexCoordSet[dwStage]);
        }
    }

    return pdwDest;
}


__inline VOID vAOS_DecrCurrentPosition(LPATID3DCNTX pCtxt, DWORD dwNumOfVertices)
{
    DWORD         dwI;
    LPATIVTXARRAY pVa;

    pVa = pCtxt->lpVtxArray;
    for(dwI = 0; dwI < pCtxt->SeVtxNumArrays_reg.bitfields.VTX_NUM_ARRAYS; dwI++)
    {
        pVa->lpdwCurrent -= (pVa->dwStride * dwNumOfVertices);
        pVa++;
    }
}

__inline PDWORD vAOS_CopyFirstVertex(LPATID3DCNTX pCtxt, PDWORD pdwDest)
{
    DWORD         dwI;
    LPATIVTXARRAY pVa;

    pVa = pCtxt->lpVtxArray;

    if (! pCtxt->dwReArrangeVtxElement)
    {
        for(dwI = 0; dwI < pCtxt->SeVtxNumArrays_reg.bitfields.VTX_NUM_ARRAYS; dwI++)
        {
            memcpy (pdwDest, pVa->lpdwStart, pVa->dwCount << 2);
            pdwDest += pVa->dwCount;
            pVa++;
        }
    }
    else
    {
        HSLASSERT(pCtxt->SeVtxNumArrays_reg.bitfields.VTX_NUM_ARRAYS <= 1);

        pdwDest=DX8CopyOneVertexData(pCtxt,pdwDest,pVa->lpdwStart);
        pVa++;
    }

    //add texture coords which is used and not include in the vertex,
    //because hw filter has problem in the triange which three
    //texture coordinates are all(0,0), driver has to make them diffrent.
    if (pCtxt->dwTexCoordsNotIncluded)
    {
        *pdwDest++ = *((DWORD *)(&(pCtxt->fTexCoordsDelta)));
        *pdwDest++ = *((DWORD *)(&(pCtxt->fTexCoordsDelta)));

        if (pCtxt->fTexCoordsDelta >= (3*TEXCOORDSDELTA))
        {
            pCtxt->fTexCoordsDelta = TEXCOORDSDELTA;
        }
        else
        {
            pCtxt->fTexCoordsDelta = pCtxt->fTexCoordsDelta+TEXCOORDSDELTA;
        }
    }

    return pdwDest;
}

__inline PDWORD vAOS_CopyCurrentAndIncr(LPATID3DCNTX pCtxt, PDWORD pdwDest)
{
    DWORD           dwI;
    LPATIVTXARRAY   pVa;

    DWORD           dwHwDWs = pCtxt->dwDxVtxHwSize / sizeof(DWORD);
    LPDWORD         pdwSrc = NULL;
    DWORD           dwFVFHwType = pCtxt->dwAtiOutputVtxFmt;

    pVa = pCtxt->lpVtxArray;
    {
        if (! pCtxt->dwReArrangeVtxElement)
        {
            for (dwI = 0; dwI < pCtxt->SeVtxNumArrays_reg.bitfields.VTX_NUM_ARRAYS; dwI++)
            {
                memcpy(pdwDest, pVa->lpdwCurrent, pVa->dwCount << 2);
                pVa->lpdwCurrent += pVa->dwStride;
                pdwDest += pVa->dwCount;
                pVa++;
            }
        }
        else
        {
            HSLASSERT(pCtxt->SeVtxNumArrays_reg.bitfields.VTX_NUM_ARRAYS <= 1);

            pdwDest=DX8CopyOneVertexData(pCtxt,pdwDest,pVa->lpdwCurrent);
            pVa->lpdwCurrent += pVa->dwStride;
            pVa++;
        }

        if (pCtxt->dwTexCoordsNotIncluded)
        {
            *pdwDest++=*((DWORD*)(&(pCtxt->fTexCoordsDelta)));
            *pdwDest++=*((DWORD*)(&(pCtxt->fTexCoordsDelta)));

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

    return pdwDest;
}



__inline PDWORD vAOS_CopyIndexedCurrentAndIncr(LPATID3DCNTX pCtxt, PDWORD pdwDest, DWORD dwIndex)
{
    DWORD         dwI;
    LPATIVTXARRAY pVa;

    pVa = pCtxt->lpVtxArray;

    if (!pCtxt->dwReArrangeVtxElement)
    {
        for(dwI = 0; dwI < pCtxt->SeVtxNumArrays_reg.bitfields.VTX_NUM_ARRAYS; dwI++)
        {
            memcpy (pdwDest, pVa->lpdwCurrent + (dwIndex * pVa->dwStride), pVa->dwCount << 2);
            pdwDest += pVa->dwCount;
            pVa++;
        }
    }
    else
    {
        HSLASSERT(pCtxt->SeVtxNumArrays_reg.bitfields.VTX_NUM_ARRAYS <= 1);

        pdwDest=DX8CopyOneVertexData(pCtxt,pdwDest,pVa->lpdwCurrent + dwIndex * pVa->dwStride);
        pVa++;
    }

    if (pCtxt->dwTexCoordsNotIncluded)
    {
        *pdwDest++=*((DWORD*)(&(pCtxt->fTexCoordsDelta)));
        *pdwDest++=*((DWORD*)(&(pCtxt->fTexCoordsDelta)));
        if (pCtxt->fTexCoordsDelta>=(3*TEXCOORDSDELTA))
        {
            pCtxt->fTexCoordsDelta = TEXCOORDSDELTA;
        }
        else
        {
            pCtxt->fTexCoordsDelta = pCtxt->fTexCoordsDelta+TEXCOORDSDELTA;
        }
    }

    return pdwDest;
}

__inline DWORD vAOS_ComputeVertexStride(LPATID3DCNTX pCtxt)
{
    DWORD         dwI, dwStrideByte;
    LPATIVTXARRAY pVa;

    pVa = pCtxt->lpVtxArray;
    dwStrideByte = 0;
    for (dwI = 0; dwI < pCtxt->SeVtxNumArrays_reg.bitfields.VTX_NUM_ARRAYS; dwI++)
    {
        dwStrideByte += (pVa->dwStride << 2);
        pVa++;
    }

    return dwStrideByte;
}

#define CHECK_INDEX(pCtxt,dwIndex) ((dwIndex) < (pCtxt)->dwOrigMaxIndex)

__inline VOID vAOS_SetIndexRange(LPATID3DCNTX pCtxt, DWORD dwMinIndex, DWORD dwMaxIndex)
{
#ifdef UMD
    if (! dwMaxIndex)
    {
        dwMaxIndex = 0x00FFFFFF;
    }
#endif

    pCtxt->dwOrigMaxIndex = dwMaxIndex;

    if (pCtxt->pD3DDevice->AtiD3dRegistry.bR200IndexBufferRangeFix)
    {
        pCtxt->dwMinIndex = 0;
        pCtxt->dwMaxIndex = 0x00FFFFFF;
    }
    else
    {
        pCtxt->dwMinIndex = dwMinIndex;
        pCtxt->dwMaxIndex = dwMaxIndex;
    }

    {
        LPDWORD pdwPm4 = GetPM4Entries(4, &pCtxt->CmdBuff);

        if (pCtxt->dwIndexStride == 2)
        {
            dwMinIndex = MIN(dwMinIndex, 0xFFFF);
            dwMaxIndex = MIN(dwMaxIndex, 0xFFFF);
        }

        *pdwPm4++ = mmSE_VF_MAX_VTX_INDX;
        *pdwPm4++ = dwMaxIndex;
        *pdwPm4++ = mmSE_VF_MIN_VTX_INDX;
        *pdwPm4++ = dwMinIndex;
        SubmitPM4EntriesToHw(4, 0, &pCtxt->CmdBuff);
    }
}

#if (DIRECT3D_VERSION >= 0x0900)
/*******************************************************************
* The following function is a workaroung for last pixel render
* state. It copys two vertexs very time.
*
********************************************************************/
__inline PDWORD vLastPixelWorkaroundForLineList(LPATID3DCNTX pCtxt, PDWORD pdwDest)
{
    LPATIVTXARRAY pVa;
    LPDWORD       pdwSrc0R, pdwSrc0W, pdwSrc1R, pdwSrc1W;
    float         x1, y1, x0, y0, length;
    float         fXscale, fYscale;

    fXscale = pCtxt->SeVportXScale_reg.f32All;
    fYscale = pCtxt->SeVportYScale_reg.f32All;

    pVa = pCtxt->lpVtxArray;

    if (fXscale < 0)
    {
        fXscale = -fXscale;
    }
    else if (fXscale == 0.0f)
    {
        fXscale = 1.0f;
    }

    if (fYscale < 0)
    {
        fYscale = -fYscale;
    }
    else if (fYscale == 0.0f)
    {
        fYscale = 1.0f;
    }

    // 1st vertex
    pdwSrc0W = pdwSrc0R = pVa->lpdwCurrent;
    x0 = SAMEBITS_CAST(float, *pdwSrc0R) * fXscale;
    y0 = SAMEBITS_CAST(float, *(++pdwSrc0R)) * fYscale;

    //2nd vertex
    pdwSrc1W = pdwSrc1R = pdwSrc0W + pVa->dwStride;
    x1 = SAMEBITS_CAST(float, *pdwSrc1R) * fXscale;
    y1 = SAMEBITS_CAST(float, *(++pdwSrc1R)) * fYscale;

    length =  (float) sqrt((y1 - y0) * (y1 - y0) + (x1 - x0) * (x1 - x0));

    // adjust the 2nd vertex
    if (x1 >= x0 && length != 0)
    {
        x1 = (x1 + (x1 - x0)/length) / fXscale;
    }
    else if (length != 0)
    {
        x1 = (x1 - (x0 - x1)/length) / fXscale;
    }

    if (y1 >= y0 && length != 0)
    {
        y1 = (y1 + (y1 - y0)/length) / fYscale;
    }
    else if (length != 0)
    {
        y1 = (y1 - (y0 - y1)/length) / fYscale;
    }

    //write the adjusted 2nd vertex to buffer
    *pdwSrc1W++ = SAMEBITS_CAST(DWORD, x1);
    *pdwSrc1W++ = SAMEBITS_CAST(DWORD, y1);

    pdwDest = vAOS_CopyCurrentAndIncr(pCtxt, pdwDest);
    pdwDest = vAOS_CopyCurrentAndIncr(pCtxt, pdwDest);

    return pdwDest;
}

/*******************************************************************
* The following function is a workaroung for last pixel render
* state.
*
********************************************************************/
__inline PDWORD vLastPixelWorkaroundForIdxLineList(LPATID3DCNTX pCtxt, PDWORD pdwDest, LPBYTE lpcIdxCurrent)
{
     LPATIVTXARRAY pVa;
     DWORD         dwIndex0, dwIndex1;
     LPDWORD       pdwSrc;
     float         x1, y1, x0, y0, length;
     float         fXscale, fYscale;

     fXscale = pCtxt->SeVportXScale_reg.f32All;
     fYscale = pCtxt->SeVportYScale_reg.f32All;

     pVa = pCtxt->lpVtxArray;

     if (fXscale < 0)
     {
         fXscale = -fXscale;
     }
     else if (fXscale == 0.0f)
     {
         fXscale = 1.0f;
     }

     if (fYscale < 0)
     {
         fYscale = -fYscale;
     }
     else if (fYscale == 0.0f)
     {
         fYscale = 1.0f;
     }

     dwIndex0 = *((LPWORD) lpcIdxCurrent);
     dwIndex1 = *((LPWORD) (lpcIdxCurrent + 2));

     pdwSrc = pVa->lpdwCurrent + (dwIndex0 * pVa->dwStride);
     x0 = SAMEBITS_CAST(float, *pdwSrc) * fXscale;
     y0 = SAMEBITS_CAST(float, *(++pdwSrc)) * fYscale;

     pdwSrc = pVa->lpdwCurrent + (dwIndex1 * pVa->dwStride);
     x1 = SAMEBITS_CAST(float, *pdwSrc) * fXscale;
     y1 = SAMEBITS_CAST(float, *(++pdwSrc)) * fYscale;

     length =  (float) sqrt((y1 - y0) * (y1 - y0) + (x1 - x0) * (x1 - x0));

     if (x1 >= x0 && length != 0)
     {
         x1 = (x1 + (x1 - x0)/length) / fXscale;
     }
     else if (length != 0)
     {
         x1 = (x1 - (x0 - x1)/length) / fXscale;
     }

     if (y1 >= y0 && length != 0)
     {
         y1 = (y1 + (y1 - y0)/length) / fYscale;
     }
     else if (length != 0)
     {
         y1 = (y1 - (y0 - y1)/length) / fYscale;
     }

     pdwSrc = pVa->lpdwCurrent + (dwIndex1 * pVa->dwStride);
     *pdwSrc++ = SAMEBITS_CAST(DWORD, x1);
     *pdwSrc++ = SAMEBITS_CAST(DWORD, y1);

     pdwDest = vAOS_CopyIndexedCurrentAndIncr(pCtxt, pdwDest, dwIndex0);
     pdwDest = vAOS_CopyIndexedCurrentAndIncr(pCtxt, pdwDest, dwIndex1);

     return pdwDest;
}


__inline PDWORD vAOS_CopyCurrentAndIncrAALine(LPATID3DCNTX pCtxt, PDWORD pdwDest)
{
    DWORD         dwI;
    LPATIVTXARRAY pVa;

    struct QuadXY
    {
        float x;
        float y;
    };

    struct  QuadXY Quad[2][2];

    float   deltaX, deltaY;

    DWORD   dwHwDWs = pCtxt->dwDxVtxHwSize / sizeof(DWORD);
    LPDWORD pdwSrc, pdwSrcNext;
    DWORD   dwFVFHwType = pCtxt->dwAtiOutputVtxFmt;


    pVa = pCtxt->lpVtxArray;


    {
        if (! pCtxt->dwReArrangeVtxElement)
        {
            for (dwI = 0; dwI < pCtxt->SeVtxNumArrays_reg.bitfields.VTX_NUM_ARRAYS; dwI++)
            {
                pdwSrc = pVa->lpdwCurrent;
                pdwSrcNext = pVa->lpdwCurrent + pVa->dwStride;

                vCalDeltaXYForAALine(pCtxt, pdwSrc, pdwSrcNext, &deltaX, &deltaY);

                //calculate the built quad vertexs
                //v00
                pdwSrc = pVa->lpdwCurrent;
                Quad[0][0].x = SAMEBITS_CAST(float, *pdwSrc++) - deltaY;
                Quad[0][0].y = SAMEBITS_CAST(float, *pdwSrc++) - deltaX;

                //v01
                pdwSrc = pVa->lpdwCurrent;
                Quad[0][1].x = SAMEBITS_CAST(float, *pdwSrc++) + deltaY;
                Quad[0][1].y = SAMEBITS_CAST(float, *pdwSrc++) + deltaX;

                //v10
                pdwSrc = pVa->lpdwCurrent + pVa->dwStride;
                Quad[1][0].x = SAMEBITS_CAST(float, *pdwSrc++) + deltaY;
                Quad[1][0].y = SAMEBITS_CAST(float, *pdwSrc++) + deltaX;

                //v11
                pdwSrc = pVa->lpdwCurrent + pVa->dwStride;
                Quad[1][1].x = SAMEBITS_CAST(float, *pdwSrc++) - deltaY;
                Quad[1][1].y = SAMEBITS_CAST(float, *pdwSrc++) - deltaX;

                //send vertex to HW for trangle 0-1-2
                //v00
                pdwSrc = pVa->lpdwCurrent;
                vCopyQuadXYToPM4ForAALine(pdwSrc, pdwDest, pVa, 0, Quad[0][0].x, Quad[0][0].y);
                pdwDest += pVa->dwCount;

                //v01
                pdwSrc = pVa->lpdwCurrent;
                vCopyQuadXYToPM4ForAALine(pdwSrc, pdwDest, pVa, 0, Quad[0][1].x, Quad[0][1].y);
                pdwDest += pVa->dwCount;

                //v10
                pdwSrc = pVa->lpdwCurrent = pVa->lpdwCurrent + pVa->dwStride;
                vCopyQuadXYToPM4ForAALine(pdwSrc, pdwDest, pVa, 0, Quad[1][0].x, Quad[1][0].y);
                pdwDest += pVa->dwCount;


                //send vertex to HW for triangle 0-2-3
                //v00
                pdwSrc = pVa->lpdwCurrent = pVa->lpdwCurrent -  pVa->dwStride;
                vCopyQuadXYToPM4ForAALine(pdwSrc, pdwDest, pVa, 0, Quad[0][0].x, Quad[0][0].y);
                pdwDest += pVa->dwCount;

                //v10
                pdwSrc = pVa->lpdwCurrent = pVa->lpdwCurrent +  pVa->dwStride;
                vCopyQuadXYToPM4ForAALine(pdwSrc, pdwDest, pVa, 0, Quad[1][0].x, Quad[1][0].y);
                pdwDest += pVa->dwCount;

                //v11
                pdwSrc = pVa->lpdwCurrent;
                vCopyQuadXYToPM4ForAALine(pdwSrc, pdwDest, pVa, 0, Quad[1][1].x, Quad[1][1].y);
                pdwDest += pVa->dwCount;
                //end of sending vertex to HW

                pVa->lpdwCurrent += pVa->dwStride;
                pVa++;
                pVa++;

            }
        }
        else
        {
            HSLASSERT(pCtxt->SeVtxNumArrays_reg.bitfields.VTX_NUM_ARRAYS <= 1);

            pdwDest=DX8CopyOneVertexData(pCtxt,pdwDest,pVa->lpdwCurrent);
            pVa->lpdwCurrent += pVa->dwStride;
            pVa++;

        }
    }

    return pdwDest;
}


__inline PDWORD vAOS_CopyIndexedCurrentAndIncrAALine(LPATID3DCNTX pCtxt, PDWORD pdwDest, DWORD dwIndex, DWORD dwIndexNext)
{
    DWORD         dwI;
    LPATIVTXARRAY pVa;
    LPDWORD       pdwSrc, pdwSrcNext;

    struct QuadXY
    {
        float x;
        float y;
    };
    struct QuadXY Quad[2][2];
    float deltaX, deltaY;

    pVa = pCtxt->lpVtxArray;

    if (! pCtxt->dwReArrangeVtxElement)
    {
        for (dwI = 0; dwI < pCtxt->SeVtxNumArrays_reg.bitfields.VTX_NUM_ARRAYS; dwI++)
        {
            pdwSrc = pVa->lpdwCurrent + (dwIndex * pVa->dwStride);
            pdwSrcNext = pVa->lpdwCurrent + (dwIndexNext * pVa->dwStride);

            vCalDeltaXYForAALine(pCtxt, pdwSrc, pdwSrcNext, &deltaX, &deltaY);


            //calculate built quad vertex
            //v00
            pdwSrc = pVa->lpdwCurrent + (dwIndex * pVa->dwStride);
            Quad[0][0].x = SAMEBITS_CAST(float, *pdwSrc++) - deltaY;
            Quad[0][0].y = SAMEBITS_CAST(float, *pdwSrc++) - deltaX;

            //v01
            pdwSrc = pVa->lpdwCurrent + (dwIndex * pVa->dwStride);
            Quad[0][1].x = SAMEBITS_CAST(float, *pdwSrc++) + deltaY;
            Quad[0][1].y = SAMEBITS_CAST(float, *pdwSrc++) + deltaX;

            //v10
            pdwSrc = pVa->lpdwCurrent + (dwIndexNext * pVa->dwStride);
            Quad[1][0].x = SAMEBITS_CAST(float, *pdwSrc++) + deltaY;
            Quad[1][0].y = SAMEBITS_CAST(float, *pdwSrc++) + deltaX;

            //v11
            pdwSrc = pVa->lpdwCurrent + (dwIndexNext * pVa->dwStride);
            Quad[1][1].x = SAMEBITS_CAST(float, *pdwSrc++) - deltaY;
            Quad[1][1].y = SAMEBITS_CAST(float, *pdwSrc++) - deltaX;

            //send vertex to HW for trangle 0-1-2
            //v00
            pdwSrc = pVa->lpdwCurrent + (dwIndex * pVa->dwStride);
            vCopyQuadXYToPM4ForAALine(pdwSrc, pdwDest, pVa, dwIndex, Quad[0][0].x, Quad[0][0].y);
            pdwDest += pVa->dwCount;

            //v01
            pdwSrc = pVa->lpdwCurrent + (dwIndex * pVa->dwStride);
            vCopyQuadXYToPM4ForAALine(pdwSrc, pdwDest, pVa, dwIndex, Quad[0][1].x, Quad[0][1].y);
            pdwDest += pVa->dwCount;

            //v10
            pdwSrc = pVa->lpdwCurrent + (dwIndexNext * pVa->dwStride);
            vCopyQuadXYToPM4ForAALine(pdwSrc, pdwDest, pVa, dwIndexNext, Quad[1][0].x, Quad[1][0].y);
            pdwDest += pVa->dwCount;

            //send vertex to HW for triangle 0-2-3
            //v00
            pdwSrc = pVa->lpdwCurrent + (dwIndex * pVa->dwStride);
            vCopyQuadXYToPM4ForAALine(pdwSrc, pdwDest, pVa, dwIndex, Quad[0][0].x, Quad[0][0].y);
            pdwDest += pVa->dwCount;

            //v10
            pdwSrc = pVa->lpdwCurrent + (dwIndexNext * pVa->dwStride);
            vCopyQuadXYToPM4ForAALine(pdwSrc, pdwDest, pVa, dwIndexNext, Quad[1][0].x, Quad[1][0].y);
            pdwDest += pVa->dwCount;

            //v11
            pdwSrc = pVa->lpdwCurrent + (dwIndexNext * pVa->dwStride);
            vCopyQuadXYToPM4ForAALine(pdwSrc, pdwDest, pVa, dwIndexNext, Quad[1][1].x, Quad[1][1].y);
            pdwDest += pVa->dwCount;
            //end of sending vertex to HW

            pVa++;
        }
    }
    else
    {
        HSLASSERT(pCtxt->SeVtxNumArrays_reg.bitfields.VTX_NUM_ARRAYS <= 1);

        pdwDest=DX8CopyOneVertexData(pCtxt,pdwDest,pVa->lpdwCurrent + dwIndex * pVa->dwStride);
        pVa++;
    }

    if (pCtxt->dwTexCoordsNotIncluded)
    {
        *pdwDest++=*((DWORD*)(&(pCtxt->fTexCoordsDelta)));
        *pdwDest++=*((DWORD*)(&(pCtxt->fTexCoordsDelta)));

        if (pCtxt->fTexCoordsDelta>=(3*TEXCOORDSDELTA))
        {
            pCtxt->fTexCoordsDelta = TEXCOORDSDELTA;
        }
        else
        {
            pCtxt->fTexCoordsDelta = pCtxt->fTexCoordsDelta+TEXCOORDSDELTA;
        }
    }

    return pdwDest;
}

#endif //#if (DIRECT3D_VERSION >= 0x0900)


#endif


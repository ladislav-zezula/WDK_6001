

#ifndef _HOS_H__
#define _HOS_H__
//
//  $Workfile: hos.h $
//  $Revision: $
//
//  Description:
//
//  Last modification:
//     $Author: $
//     $Date: $
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 2000-2002, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//
#include "hwvertexshader.h"
#include "r6xid.h"

//=============================================================================
// General HOS functions:
extern VOID    HOS_SetHOSState(LPATID3DCNTX pCtxt, LPD3DDEVICE lpD3DDev);

extern VOID    HOS_TessellateVerticesByRectPatch(LPATID3DCNTX pCtxt, LPD3DHAL_DP2DRAWRECTPATCH pDrawRectPatch,
                                                 DWORD dwStampCount);
extern VOID    HOS_TessellateVerticesByTriPatch(LPATID3DCNTX pCtxt, LPD3DHAL_DP2DRAWTRIPATCH pDrawTriPatch,
                                                DWORD dwStampCount);

#define ATI_MAX_PATCH_SEGS          8
#define ATI_MAX_PATCH_SEGS_FLOAT    (8.0f)

//=============================================================================

//-----------------------------------------------------------------------------
// NPatch defs
#define HOS_NP_TESS_NONE        0
#define HOS_NP_TESS_LINEAR      1
#define HOS_NP_TESS_QUADRATIC   2
#define HOS_NP_TESS_CUBIC       3

//-----------------------------------------------------------------------------
// NPatch functions:

#if (DIRECT3D_VERSION >= 0x0900)
/******************************************************************************
* __inline void SetSeHosVecInterpOrderforPosandNor()
*
* Args:
*   pCtxt     Flag for the position to change.
*   dwPos     Position vector.
*   dwNor     Normal vector.
*
* Returns: none
*
* Description:
*
* Notes:
*
******************************************************************************/

__inline void SetSeHosVecInterpOrderforPosandNor(LPATID3DCNTX pCtxt, DWORD dwPos, DWORD dwNor)
{
   if (dwPos<8)
   {
      pCtxt->tclHosVecInterpCmd.HosVecInterp0.u32All &= ~ (SE_HOS_VEC_INTERP_0__HOS_INTERP_ORDER_0_MASK <<(4*dwPos));
      pCtxt->tclHosVecInterpCmd.HosVecInterp0.u32All |= (pCtxt->dwPositionTessType <<(4*dwPos));
   }
   else
   {
      pCtxt->tclHosVecInterpCmd.HosVecInterp1.u32All &= ~ (SE_HOS_VEC_INTERP_0__HOS_INTERP_ORDER_0_MASK <<(4*(dwPos-8)));
      pCtxt->tclHosVecInterpCmd.HosVecInterp1.u32All |= (pCtxt->dwPositionTessType <<(4*(dwPos-8)));
   }
   if (dwNor<8)
   {
      pCtxt->tclHosVecInterpCmd.HosVecInterp0.u32All &= ~ (SE_HOS_VEC_INTERP_0__HOS_INTERP_ORDER_0_MASK <<(4*dwNor));
      pCtxt->tclHosVecInterpCmd.HosVecInterp0.u32All |= (pCtxt->dwNormalTessType <<(4*dwNor));
   }
   else
   {
      pCtxt->tclHosVecInterpCmd.HosVecInterp1.u32All &= ~ (SE_HOS_VEC_INTERP_0__HOS_INTERP_ORDER_0_MASK <<(4*(dwNor-8)));
      pCtxt->tclHosVecInterpCmd.HosVecInterp1.u32All |= (pCtxt->dwNormalTessType <<(4*(dwNor-8)));
   }
}
#endif //(DIRECT3D_VERSION >= 0x0900)

//=============================================================================


#define ATI_PATCH_HANDLE_TABLE_SIZE     256

#define HOS_RT_TESS_NONE        0
#define HOS_RT_TESS_POSITION    1
#define HOS_RT_TESS_NORMAL      2
#define HOS_RT_TESS_UV          3

#define RECT_PATCH 0
#define TRI_PATCH  1


typedef struct _ATIRTPATCHCACHEDDATA
{
    DWORD dwNumPoints;
    WORD  wNewPSCRegs[VS_NUM_PSC_ENTRIES];
    BOOL  bUniform;
    BOOL  bDegenerate;
    DWORD NumElements;

    LPVOID pdwMGMMatrices;  //NEED TO ALLOCATE/DEALLOCATE MEMORY FOR THIS!!
    DWORD order;
    DWORD basis;

} ATIRTPATCHCACHEDDATA, *LPATIRTPATCHCACHEDDATA;


typedef struct _ATIRTPATCHMESHDATA
{
    BOOL  bSegsHaveChanged;
    FLOAT fSegs[4];
    BOOL  iso_dir;
    DWORD num_iso;
    DWORD num_tri;
    FLOAT *edge_ptr;
    FLOAT *iso_ptr;
    FLOAT *iso_indx_ptr;
    FLOAT *mvert_ptr;
    FLOAT *indx_ptr;
    DWORD num_elements;
    DWORD iso_stride;
    DWORD vert_stride;
    LPATIVTXSHADER pAtiVtxShader;
    LPVOID pdwMeshData;  //NEED TO ALLOCATE/DEALLOCATE MEMORY FOR THIS!!

} ATIRTPATCHMESHDATA, *LPATIRTPATCHMESHDATA;


typedef struct _ATIRTPATCHCACHEDINFO
{
    // keep a copy of the patch handle here
    DWORD dwPatchHandle;

    // keep track of the current vertex shader
    DWORD dwVertexShaderHandle;

    ATIRTPATCHCACHEDDATA pPatchCachedData;
    ATIRTPATCHMESHDATA   pPatchMeshData;

} ATIRTPATCHCACHEDINFO, *LPATIRTPATCHCACHEDINFO;



// RectPatch functions
extern BOOL  RECT_ComputeCachableInfo(LPATID3DCNTX pCtxt, D3DRECTPATCH_INFO rInfo, LPATIRTPATCHCACHEDINFO pCachedInfo);
extern BOOL  RECT_ComputeMesh(LPATID3DCNTX pCtxt, LPATIRTPATCHCACHEDINFO pCachedInfo);
extern VOID  RECT_GenerateVertParam(LPATIRTPATCHCACHEDINFO pPatchInfo);
extern VOID  RECT_ComputeIso(FLOAT t, LPATIRTPATCHCACHEDINFO pPatchInfo,unsigned iso_dir);
extern VOID  RECT_ComputeVertData(LPATIRTPATCHCACHEDINFO pPatchInfo,FLOAT t,unsigned indx,BOOL degenerate,DWORD vert_indx);
VOID  RECT_DegenIso(LPATIRTPATCHCACHEDINFO pPatchInfo);
VOID  RECT_GenerateVertices(LPATIRTPATCHCACHEDINFO pPatchInfo,LPDWORD pVertices);
VOID  RECT_GenerateVertciesFromMesh(LPATID3DCNTX pCtxt, LPATIRTPATCHCACHEDINFO pPatchInfo);

// TriPatch functions
extern BOOL  TRI_ComputeCachableInfo(LPATID3DCNTX pCtxt, D3DTRIPATCH_INFO tInfo, LPATIRTPATCHCACHEDINFO pCachedInfo);
extern VOID  TRI_ComputeMesh(LPATID3DCNTX pCtxt, LPATIRTPATCHCACHEDINFO pCachedInfo);

extern VOID HOS_ComputeMGM(DWORD element, DWORD component,DWORD stride,FLOAT *control_points, FLOAT *o_cntrl_pts,
                           DWORD basis, DWORD order, BOOL type);

// Must define 1 from each group for textures...
// ...the texture coordinate set, and...
#define HOS_TEX_SET_0_VALUE     0x00001000
#define HOS_TEX_SET_1_VALUE     0x00002000
#define HOS_TEX_SET_2_VALUE     0x00004000
#define HOS_TEX_SET_3_VALUE     0x00008000
#define HOS_TEX_SET_4_VALUE     0x00010000
#define HOS_TEX_SET_5_VALUE     0x00020000

// ...the float within the set
#define HOS_TC0_VALUE     0x10000000
#define HOS_TC1_VALUE     0x20000000
#define HOS_TC2_VALUE     0x40000000
#define HOS_TC3_VALUE     0x80000000



extern LPVOID  HOS_AllocateCachedInfoMemory(LPVOID lpATIDXObj, DWORD dwSpace);
extern VOID    HOS_FreeCachedInfoMemory(LPVOID lpATIDXObj, LPVOID pCachedInfo);
extern HRESULT HOS_RenderMesh(LPATID3DCNTX pCtxt, LPATIVTXSHADER pAtiVtxShader, LPDWORD pVertices,
                              DWORD dwFVFDxSizeInDw, DWORD dwNumVertices);
extern VOID    HOS_DestyoyPatchList(LPVOID lpATIDXObj, LPATILIST pPatchHandleList);

extern LPVOID  HOS_ReorderVertexElements(LPATID3DCNTX pCtxt, LPATIVTXSHADER pAtiVtxShader,
                                         LPATIRTPATCHCACHEDINFO pCachedInfo);



/******************************************************************************
* __inline LPVOID HOS_AllocateCachedInfoMemory()
*
* Args:
*
* Returns: Nothing
*
* Description:
*   Allocates memory based on how much cache is needed for this patch
*
* Notes:
*
******************************************************************************/
__inline LPVOID HOS_AllocateCachedInfoMemory(LPVOID lpATIDXObj, DWORD dwSpace)
{
    LPVOID pCachedInfo = pDdHslSharedMemCallocEx(lpATIDXObj, dwSpace);
    if (NULL == pCachedInfo)
    {
        HSLDPF(E_ERROR_MESSAGE,
            "HOS_AllocateCachedInfoMemory: Allocation failed");
    }
    return pCachedInfo;
}

/******************************************************************************
* __inline LPVOID HOS_FreeCachedInfoMemory()
*
* Args:
*   pInfo   pointer to allocated memory holding cached info
*
* Returns: Nothing
*
* Description:
*   Frees memory
*
* Notes:
*
******************************************************************************/
__inline VOID HOS_FreeCachedInfoMemory(LPVOID lpATIDXObj, LPVOID pInfo)
{
    if(pInfo)
    {
        BOOL bFree = bDdHslSharedMemFreeEx( lpATIDXObj, pInfo );
        if (!bFree)
        {
            HSLDPF(E_ERROR_MESSAGE,
                "HOS_FreeCachedInfoMemory: Memory not freed");
        }
    }
}

/******************************************************************************
* __inline LPVOID HOS_SetPatchHandle()
*
* Args:
*
* Returns: An index into the hash table
*
* Description:
*   Use this function to find an empty index into our table
*
* Notes:
*     The hash key generation function is:
*       ( ((handle & 0x000FF000)>>12) + (handle & 0x000000FF) ) % 0x00000100
*       ex.
*           handle = 0x89ABCDEF
*           key = (BC + EF)%0x100 = (188+239)%256 = 171
*
*    NOTE: Ther reason we use BC and EF are because if the app uses pointers
*          to their control points as their handles, there is a good chance that
*          EF will not change much.  And if they just number their patches
*          sequentially BC will likely not change at all.  This way, we can spread
*          out the entries for either case.
*
******************************************************************************/
__inline LPVOID HOS_SetPatchHandle(LPATID3DCNTX pCtxt, DWORD dwHandle)
{
    // Find the index into the table
    LPD3DDEVICE         lpD3DDev=GetD3DDevice(pCtxt);
    LPVOID              lpATIDXObj = GetATIDeviceInfo(lpD3DDev);
    LPVOID pSlot = NULL;
    LPATIRTPATCHCACHEDINFO rtTemp;
    DWORD dwIndex = (((dwHandle & 0x000FF000)>>12) + (dwHandle & 0x000000FF)) % ATI_PATCH_HANDLE_TABLE_SIZE;

    pSlot = AL_GetEntry(&pCtxt->alRTPatchHandleList, dwIndex);
    if(pSlot == NULL)
    {
        HSLDPF(E_ERROR_MESSAGE, "HOS_HashHandleIntoTable: Cannot find table index");
        return NULL;
    }
    if( ((LPDlinkList)pSlot)->dwNodeSize == 0)
    {
        // need to allocate a new DLink list.
        vDL_Initialize( (LPDlinkList)pSlot, sizeof(ATIRTPATCHCACHEDINFO) );
    }
    // generate an entry into the table
    rtTemp = (LPATIRTPATCHCACHEDINFO)pvDL_Alloc(lpATIDXObj, (LPDlinkList)pSlot);

    if ( rtTemp != NULL )
    {
        // fill it out
        rtTemp->dwPatchHandle = dwHandle;
        rtTemp->dwVertexShaderHandle = pCtxt->dwCurrVtxShaderHandle;
        rtTemp->pPatchCachedData.pdwMGMMatrices = NULL;

        // Put it into the table
        vDL_Insert( (LPDlinkList)pSlot, rtTemp, NULL );
    }

    // return the pointer to the info...not the slot in the ATILIST
    return rtTemp;
}

/******************************************************************************
* __inline LPVOID HOS_GetHandleFromTable()
*
* Args:
*
* Returns: an index into the hash table where the handle is
*
* Description:
*   Use this function to find an index to a handle in our table
*
* Notes:
*   This is the reverse of HOS_SetPatchHandle.
*
******************************************************************************/
__inline LPVOID HOS_GetHandleFromTable(LPATID3DCNTX pCtxt, DWORD dwHandle)
{
    // Find the index into the table
    DWORD dwIndex = (((dwHandle & 0x000FF000)>>12) + (dwHandle & 0x000000FF)) % ATI_PATCH_HANDLE_TABLE_SIZE;
    DWORD dwNumAttempts;
    LPVOID pSlot = NULL;
    LPATIRTPATCHCACHEDINFO rtTemp;

    pSlot = AL_GetEntry(&pCtxt->alRTPatchHandleList, dwIndex);

    if( pSlot == NULL )
    {
        HSLDPF(E_ERROR_MESSAGE, "HOS_GetHandleFromTable: Cannot find table index");
        return NULL;
    }

    dwNumAttempts = dwDl_GetNumNodesInList((LPDlinkList)pSlot);
    rtTemp = pvDL_GetHead((LPDlinkList)pSlot);

    while(dwNumAttempts > 0)
    {
        if(rtTemp->dwPatchHandle == dwHandle)
        {
            return rtTemp;
        }
        rtTemp = pvDL_GetNext((LPDlinkList)pSlot, rtTemp);
        dwNumAttempts--;
    }
    // Could not find the node
    return NULL;
}

/******************************************************************************
* __inline VOID HOS_DeletePatchHandle()
*
* Args:
*
* Returns: An index into the hash table
*
* Description:
*   Use this function to delete an entry from our table
*
* Notes:
*
******************************************************************************/
__inline VOID HOS_DeletePatchHandle(LPATID3DCNTX pCtxt, DWORD dwHandle)
{
    // Find the index into the table
    LPD3DDEVICE         lpD3DDev=GetD3DDevice(pCtxt);
    LPVOID              lpATIDXObj = GetATIDeviceInfo(lpD3DDev);
    LPVOID pSlot = NULL;
    LPATIRTPATCHCACHEDINFO rtTemp;
    DWORD dwIndex = (((dwHandle & 0x000FF000)>>12) + (dwHandle & 0x000000FF)) % ATI_PATCH_HANDLE_TABLE_SIZE;
    DWORD dwNumAttempts;

    pSlot = AL_GetEntry(&pCtxt->alRTPatchHandleList, dwIndex);

    if( pSlot == NULL )
    {
        HSLDPF(E_INFO_MESSAGE, "HOS_DeletePatchHandle: Cannot find table index");
        return;
    }

    dwNumAttempts = dwDl_GetNumNodesInList((LPDlinkList)pSlot);
    rtTemp = pvDL_GetHead((LPDlinkList)pSlot);

    while(dwNumAttempts > 0)
    {
        if(rtTemp->dwPatchHandle == dwHandle)
        {
            HOS_FreeCachedInfoMemory(lpATIDXObj, rtTemp->pPatchCachedData.pdwMGMMatrices);
            HOS_FreeCachedInfoMemory(lpATIDXObj, rtTemp->pPatchMeshData.pdwMeshData);
            vDL_Remove((LPDlinkList)pSlot, rtTemp);
            vDL_Free((LPDlinkList)pSlot, rtTemp);
            return;
        }
        rtTemp = pvDL_GetNext((LPDlinkList)pSlot, rtTemp);
        dwNumAttempts--;
    }
    // Could not find the node...just exit
}


/******************************************************************************
* __inline WORD HOS_GetVectorIfPSCDefined()
*
* Args:
*
* Returns: a DWORD
*
* Description:
*   Copys the vector (if it exists) into dwFillMe.  Returns the data type of the
*   element...-1 if there is no element
*
* Notes:
*   Change dwFillMe
*
******************************************************************************/
__inline DWORD HOS_GetVectorIfPSCDefined(LPWORD wPscRegs, DWORD dwElement, LPDWORD pdwVert,
                                         __out_ecount(4) LPDWORD dwFillMe, DWORD dwNumRealElements, LPDWORD pdwRegNum)
{
    DWORD i,j,temp;
    for(i = 0; i < dwNumRealElements; i++)
    {
        DWORD dwPscReg = wPscRegs[i];
        DWORD dwComponentSize = VS_GetComponentSizeFromATIDef( dwPscReg & SE_PROG_STREAM_CNTL_0__DATA_TYPE_0_MASK);
        DWORD dwRegElement = (wPscRegs[i] & SE_PROG_STREAM_CNTL_0__DST_VEC_LOC_0_MASK)
                              >> SE_PROG_STREAM_CNTL_0__DST_VEC_LOC_0__SHIFT;

        // Tell PREFast that dwComponentSize <= 4, because VS_GetComponentSizeFromATIDef returns 0, 1, 2, 4.
        __analysis_assume(dwComponentSize <= 4);

        if(dwRegElement == dwElement)
        {
            // we have a match, return this PSC register
            //return wPscRegs[i];

                // we have a match...we should be pointing to the vector we want to copy...lets do it
                for(j = 0; j < dwComponentSize; j++)
                {
                    temp = *pdwVert++;
                    dwFillMe[j] = temp;

                }
                *pdwRegNum = i;
                return (wPscRegs[i] & SE_PROG_STREAM_CNTL_0__DATA_TYPE_0_MASK);
        }
        pdwVert += dwComponentSize;
    }
    // nothing exists for this element
    return -1;
}


/******************************************************************************
* __inline WORD HOS_CheckIfVirtualDefined()
*
* Args:
*
* Returns: a WORD
*
* Description:
*   The value of the generate field
*
* Notes:
*
******************************************************************************/
__inline WORD HOS_CheckIfVirtualDefined(LPWORD wGenerateDataInfo, DWORD dwElement)
{
    if(wGenerateDataInfo[dwElement])
    {
        // we have a match, return this data
        return wGenerateDataInfo[dwElement];
    }
    // nothing exists for this element
    return 0;
}


/******************************************************************************
* __inline DWORD HOS_GetTessellationTypeForElement()
*
* Args:
*
* Returns: a DWORD
*
* Description:
*   The type of tessellation for this element
*
* Notes:
*
*
******************************************************************************/
__inline DWORD HOS_GetTessellationTypeForElement(LPATIVTXSHADER pAtiVtxShader,
                                                 LPATIRTPATCHCACHEDINFO pPatchInfo,
                                                 DWORD dwElementNumber,
                                                 DWORD dwNumElements)
{
    DWORD i;

    for(i = 0; i < dwNumElements; i++)
    {
        DWORD dwRegElement = (pPatchInfo->pPatchCachedData.wNewPSCRegs[i] & SE_PROG_STREAM_CNTL_0__DST_VEC_LOC_0_MASK)
                              >> SE_PROG_STREAM_CNTL_0__DST_VEC_LOC_0__SHIFT;

        // check the PSC regs for this element
        if(dwRegElement == dwElementNumber)
        {
            // check the tessellation type
            if (dwElementNumber < ARRAYSIZE(pAtiVtxShader->wGenerateDataInfo) &&
                pAtiVtxShader->wGenerateDataInfo[dwElementNumber])
            {
                // we have a virtual element, return the tessellation type
                return (pAtiVtxShader->wGenerateDataInfo[dwElementNumber] >> 14);
            }
            else
            {
                return HOS_RT_TESS_POSITION;
            }
        }
        if(dwRegElement > dwElementNumber)
        {
            // since the wNewPSCRegs are in ascending order, we know the element
            // doesn't exist once we've grabbed a PSC register with a higher element
            // number, so we can early exit
            continue;
        }
    }
    // this element doesn't exist.
    return HOS_RT_TESS_NONE;

}


/******************************************************************************
* __inline DWORD HOS_GetElementToGenerateFrom()
*
* Args:
*
* Returns: a DWORD
*
* Description:
*   The type of tessellation for this element
*
* Notes:
*
*
******************************************************************************/
__inline DWORD HOS_GetElementToGenerateFrom(LPATIVTXSHADER pAtiVtxShader,
                                            LPATIRTPATCHCACHEDINFO pPatchInfo,
                                            DWORD dwElementNumber,
                                            DWORD dwNumElements)
{
    DWORD i;

    for(i = 0; i < dwNumElements; i++)
    {
        DWORD dwRegElement = (pPatchInfo->pPatchCachedData.wNewPSCRegs[i] & SE_PROG_STREAM_CNTL_0__DST_VEC_LOC_0_MASK)
                              >> SE_PROG_STREAM_CNTL_0__DST_VEC_LOC_0__SHIFT;

        // check the PSC regs for this elementy
        if(dwRegElement == dwElementNumber)
        {
            // check the tessellation type
            if (dwElementNumber < ARRAYSIZE(pAtiVtxShader->wGenerateDataInfo) &&
                pAtiVtxShader->wGenerateDataInfo[dwElementNumber])
            {
                // we have a virtual element, return the tessellation type
                return (pAtiVtxShader->wGenerateDataInfo[dwElementNumber] & 0x0000fff);
            }
            else
            {
                return -1;
            }
        }
        if(dwRegElement > dwElementNumber)
        {
            // since the wNewPSCRegs are in ascending order, we know the element
            // doesn't exist once we've grabbed a PSC register with a higher element
            // number, so we can early exit
            continue;
        }
    }
    // this element doesn't exist.
    return -1;

}

/******************************************************************************
* __inline BOOL HOS_NumSegsHaveChanged()
*
* Args:
*
* Returns: a BOOL
*
* Description:
*   returns true if any of the segment info has changed
*
* Notes:
*
******************************************************************************/
__inline BOOL HOS_NumSegsHaveChanged(FLOAT fOldSegs[], FLOAT fNewSegs[])
{
    if(fOldSegs[0] != fNewSegs[0])
    {
        return TRUE;
    }
    if(fOldSegs[1] != fNewSegs[1])
    {
        return TRUE;
    }
    if(fOldSegs[2] != fNewSegs[2])
    {
        return TRUE;
    }
    if(fOldSegs[3] != fNewSegs[3])
    {
        return TRUE;
    }
    return FALSE;
}

#endif  // _HOS_H__


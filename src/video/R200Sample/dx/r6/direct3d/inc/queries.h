

//
//  $Workfile: queries.h $
//
//  Description:
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2002, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//
/*****************************************************************************\
 *                                                                           *
 * DESCRIPTION:                                                              *
 *                                                                           *
 * QUERIES.H                                                                 *
 *                                                                           *
 * This file contains all the definitions supporting Asynchronous Query      *
 * Operations                                                                *
 *                                                                           *
 * (c) 2002 ATI Technologies Inc.  (unpublished)                             *
 *                                                                           *
 * All rights reserved.                                                      *   
 * The year included in the foregoing notice is the year of creation of the work.*
\*****************************************************************************/
#ifndef _QUERIES_H_
#define _QUERIES_H_

#if   (DIRECT3D_VERSION >= 0x0900)

#include "atidrawprim.h" 
#include "atisurfinfo.h"
#include "d3dcntx.h"

#define ATI_ZPASS_DATA_DEFAULT  0xFFFFFFFF

HRESULT ATICreateQuery(LPATID3DCNTX pCtxt, LPD3DHAL_DP2CREATEQUERY pCreateQuery);
HRESULT ATIDeleteQuery(LPATID3DCNTX pCtxt, LPD3DHAL_DP2DELETEQUERY pDeleteQuery);
HRESULT ATIIssueQuery(LPATID3DCNTX pCtxt, LPD3DHAL_DP2ISSUEQUERY pIssueQuery);
DWORD   ATINotifyQueryResult(LPATID3DCNTX pCtxt, LPBYTE lpCBStart, DWORD dwCBLen);

__inline LPATIQUERY GetQuery(LPATID3DCNTX pCtxt, DWORD dwIndex )
{
    return (LPATIQUERY)AL_GetEntry(&pCtxt->queryList, dwIndex);
}

#endif //(DIRECT3D_VERSION >= 0x0900)

#endif // _QUERIES_H_

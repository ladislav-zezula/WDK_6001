

//    
//  Workfile: procFVF.h
//
//  Description:
//
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, 2000 ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _PROCFVF_H_
#define _PROCFVF_H_

#include "tcl_state.h"     //for definition of ATI_REEVALUTE_FVF.
#include "texturestage.h"
#include "hwvertexshader.h"

DWORD AtiCheckFVF( LPATID3DCNTX pCtxt, DWORD dwDxFvfType, LPDWORD pdwDxVtxSize,
                   LPDWORD pdwDxVtxHwSize, LPDWORD pdwAtiInputVtxFmt );

// The process FVF routines differ based on ASIC. One of the routines 
// is assigned to pCtxt->processFVF at initialization
DWORD Rad2ProcessFVF( LPATID3DCNTX pCtxt, DWORD dwDxFvfType, LPDWORD pdwVtxStride,
                      LPDWORD pdwVtxCount, LPDWORD pdwAtiInputVtxFmt );

DWORD Rad2AtiCheckFVF(LPATID3DCNTX pCtxt, DWORD dwDxFvfType, LPDWORD pdwDxVtxSize,
                      LPDWORD pdwDxVtxHwSize, LPDWORD pdwAtiInputVtxFmt);
BOOL SpecularAvailable( LPATID3DCNTX pCtxt );
VOID UpdateFVFforPVMS( LPATID3DCNTX pCtxt );

void CheckTexCoordsNotIncluded(LPATID3DCNTX pCtxt);

#endif // _PROCFVF_H_


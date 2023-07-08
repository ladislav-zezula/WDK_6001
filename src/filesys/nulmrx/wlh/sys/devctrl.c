/*++

Copyright (c) 1989 - 1999   Microsoft Corporation

Module Name:

    devctrl.c

Abstract:

    This module implements DeviceIoControl operations.

--*/

#include "precomp.h"
#pragma hdrstop

//
//  The local debug trace level
//

RXDT_DefineCategory(DEVCTRL);

#define Dbg                              (DEBUG_TRACE_DEVCTRL)


//
//  forwards & code allocation pragmas
//
#ifdef ALLOC_PRAGMA
#pragma alloc_text(PAGE, NulMRxIoCtl)
#endif

   
NTSTATUS
NulMRxIoCtl(
      IN OUT PRX_CONTEXT RxContext)
/*++

Routine Description:

   This routine performs an IOCTL operation.
   
Arguments:

    RxContext - the RDBSS context

Return Value:

    RXSTATUS - The return status for the operation

Notes:


--*/
{
    NTSTATUS Status = STATUS_INVALID_DEVICE_REQUEST;
    __notnull PMRX_FCB Fcb = RxContext->pFcb;
    __notnull PMRX_FOBX Fobx = RxContext->pFobx;
    __notnull PMRX_SRV_OPEN pSrvOpen = Fobx->pSrvOpen;
    NulMRxGetFcbExtension(Fcb,pFcbExtension);
    PMRX_NET_ROOT pNetRoot = Fcb->pNetRoot;
    PMRX_SRV_CALL pSrvCall = pNetRoot->pSrvCall;
    UNICODE_STRING RootName;
    NulMRxGetDeviceExtension(RxContext,pDeviceExtension);
    PLOWIO_CONTEXT LowIoContext  = &RxContext->LowIoContext;
    ULONG IoControlCode = LowIoContext->ParamsFor.FsCtl.FsControlCode;
    PUNICODE_STRING RemainingName = pSrvOpen->pAlreadyPrefixedName;
    UNICODE_STRING  StatsFile;
    NulMRxGetNetRootExtension(pNetRoot,pNetRootExtension);
    
    RxTraceEnter("NulMRxIoCtl");
    PAGED_CODE();
 
    switch (IoControlCode) {

        default:        
        //ASSERT(!"unimplemented major function");
		break;
    }

    RxTraceLeave(Status);
    return Status;
}


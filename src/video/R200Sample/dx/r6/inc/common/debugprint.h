

//    
//  Workfile: debugprint.h
//
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 2000-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//
#ifndef _DEBUGPRINT_H
#define _DEBUGPRINT_H

#include "atidxinc.h"

#define MAX_DEBUG_STRLEN        256

void
DebugPrint(
    __in      PCHAR     prefix,
    __in      PCHAR     sFmt,
    __in_opt  va_list   ap
    );

void
GetDebugString(
    __in_bcount(MAX_DEBUG_STRLEN)  char  *szMessage,
    __in      PCHAR     sFmt,
    __in_opt  va_list   ap
    );

#endif //_DEBUGPRINT_H



//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//
#ifndef  _DDHSL_H
#define  _DDHSL_H

#include "atiddhsl.h"

typedef struct 
{
  EDDHSLDEBUGLEVEL eLevel;
  char *String;
  DWORD dwEnable;
} HSL_DEBUGENTRY;

extern HSL_DEBUGENTRY HSLDebugTable[];

#endif




//    
//  $Workfile: atidefs.h $
//
//  Description:
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef ATIDEFS_H
#define ATIDEFS_H 

#include "features.h"

// General Defines file
// this file will be included at the VERY TOP
// of most files, so no dependants please!


#define MAX_MIPMAP_LEVEL            11         
#define ATiMinTextureWH             1
#define ATiMaxTextureWH             2048
#define ATI_GUARD_BAND              2048

#define FirstContext                1                   
#define ContextPerBlock             256

#define MAX_BANDWIDTH_PIXEL_DROPOUT     465000000L

typedef void (*VOIDFUNC)();

#endif // ATIDEFS_H



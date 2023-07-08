

/*****************************************************************************\
*
*  Module Name    ver_nt2d.h
*  Project        Longhorn
*  Device         R200
*
*  Description    Header file containing version number information for
*                 the miniport
*
*  (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
\*****************************************************************************/
#include <ntverp.h>

#define _QUOTE(x) #x
#define STRINGIZE(y) _QUOTE(y)

// Matching the OS build number
#define ATI_BUILD_NO                VER_PRODUCTBUILD

#define R200_VER_PRODUCTVERSION_STR   "7.14.01." STRINGIZE(ATI_BUILD_NO)
#define R200_VER_PRODUCTVERSION_NUM    7,14,01,ATI_BUILD_NO


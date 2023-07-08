

/*****************************************************************************\
* 
*  Module Name    atios.h
*  Project        asic_reg
*  Devices        R128/M3/R6
*  Owner          XP/Longhorn Component Team
*
*  Description    Common OS definitions for all R128/M3/R6 components to use
*                 (if not defined within the appropriate DDK).
*  
*
*  Copyright (c) 2002 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
*  Initial Revision - Mario Filipas [03/07/2002]
*
\*****************************************************************************/

#ifndef _ATIOS_H
#define _ATIOS_H

#include "atiassert.h"

//
// Definitions for specifying operating system platforms.  This is determined
// on the fly by the miniport and is communicated to other components if
// deemed necessary (i.e. unified driver).
//
// Format of these definitions: 0x<OSMajor><OsMinor><SPMajor> 
//
#define WINNT_NT            0x400
#define WINNT_2K            0x500
#define WINNT_XP            0x510
#define WINNT_XPSP1         0x511
#define WINNT_XPSP2         0x512
#define WINNT_XPNET         0x520
#define WINNT_LONGHORN      0x600

//
// Macros to determine the exact operating system revision.
//

#define IS_OPERATING_SYSTEM_NT(p) \
            ((WINNT_NT == (p)) ? TRUE : FALSE)

#define IS_OPERATING_SYSTEM_2K(p) \
            ((WINNT_2K == (p)) ? TRUE : FALSE)

#define IS_OPERATING_SYSTEM_XP(p) \
            ((WINNT_XP == (p)) ? TRUE : FALSE)

#define IS_OPERATING_SYSTEM_XPSP1(p) \
            ((WINNT_XPSP1 == (p)) ? TRUE : FALSE)

#define IS_OPERATING_SYSTEM_XPSP2(p) \
            ((WINNT_XPSP2 == (p)) ? TRUE : FALSE)

#define IS_OPERATING_SYSTEM_XPNET(p) \
            ((WINNT_XPNET == (p)) ? TRUE : FALSE)

#define IS_OPERATING_SYSTEM_LONGHORN(p) \
            ((WINNT_LONGHORN == (p)) ? TRUE : FALSE)

//
// Macros to determine the range of operating system revision.
//

#define IS_OPERATING_SYSTEM_2K_OR_GREATER(p) \
            ((WINNT_2K <= (p)) ? TRUE : FALSE)

#define IS_OPERATING_SYSTEM_XP_OR_GREATER(p) \
            ((WINNT_XP <= (p)) ? TRUE : FALSE)

#define IS_OPERATING_SYSTEM_XPSP1_OR_GREATER(p) \
            ((WINNT_XPSP1 <= (p)) ? TRUE : FALSE)

#define IS_OPERATING_SYSTEM_XP_SERIES(p) \
            (((WINNT_XP <= (p)) && (WINNT_LONGHORN > (p))) ? TRUE : FALSE)

#define IS_OPERATING_SYSTEM_LONGHORN_OR_GREATER(p) \
            ((WINNT_LONGHORN <= (p)) ? TRUE : FALSE)

#endif  // _ATIOS_H



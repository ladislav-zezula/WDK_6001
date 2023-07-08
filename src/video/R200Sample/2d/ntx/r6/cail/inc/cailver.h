

/****************************************************************************\
* 
*  Module Name    cailver.h
*  Project        Common ASIC Initialization Library
*  Device         Radeon (9x/NT5+)
*
*  Description    Version data for builds of cail.lib
*  
*
*  Copyright (c) 2002 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
\****************************************************************************/

#ifndef _CAILVER_H
#define _CAILVER_H

#define CAIL_NT50_VER       "5.0035"
#define CAIL_NT51_VER       "6.0035"

#define CAIL_VERSION        35


// Define the version number based on the CPU and OS

#ifdef ITANIUM

#define CPU_STR "IA64"

#ifdef NT51
    #define CAIL_VERSION_STR "[ATI LIB=CAIL.LIB,"CAIL_NT51_VER","CPU_STR"]"
#endif

#endif // ITANIUM


#ifdef AMD64

#define CPU_STR "AMD64"

#ifdef NT51
    #define CAIL_VERSION_STR "[ATI LIB=CAIL.LIB,"CAIL_NT51_VER","CPU_STR"]"
#endif

#endif // AMD64

#ifdef IA32

#define CPU_STR "IA32"

#ifdef NT50
    #define CAIL_VERSION_STR "[ATI LIB=CAIL.LIB,"CAIL_NT50_VER","CPU_STR"]"
#endif
#ifdef NT51
    #define CAIL_VERSION_STR "[ATI LIB=CAIL.LIB,"CAIL_NT51_VER","CPU_STR"]"
#endif

#endif // IA32


#endif // _CAILVER_H


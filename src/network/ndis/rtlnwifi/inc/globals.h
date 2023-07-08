/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    Globals.h

Abstract:
    Global defines
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created

Notes:

--*/
#ifndef _NATIVE_WIFI_GLOBALS_H

#define _NATIVE_WIFI_GLOBALS_H

//
// Some macros to make code more readable
//


#ifndef INLINE
    #define INLINE      __inline
#endif


#ifndef EXTERN
    #define EXTERN      extern
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif


#ifndef BOOL
typedef int BOOL;
#endif

#ifndef DWORD
typedef unsigned long       DWORD;
#endif

#ifndef MIN
    #define MIN(a, b)                  ((a) < (b)? a : b)
#endif  // MIN
#ifndef MAX
    #define MAX(a, b)                  ((a) > (b)? a : b)
#endif  // MAX
//
//
// Interlocked bit manipulation interfaces
//
#define MP_INTERLOCKED_SET_BITS(Flags, Flag) \
    InterlockedOr((PLONG)(Flags), Flag)

#define MP_INTERLOCKED_CLEAR_BITS(Flags, Flag) \
    InterlockedAnd((PLONG)Flags, ~(Flag))


#endif  // _NATIVE_WIFI_GLOBALS_H


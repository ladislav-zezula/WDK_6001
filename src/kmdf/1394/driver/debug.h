/*++

Copyright (c) 1998 Microsoft Corporation

Module Name:

    debug.h

Abstract:

--*/

#if DBG

#if _1394VDEV_DRIVER_
#define _DRIVERNAME_  "1394VDEV"
#else
#define _DRIVERNAME_ "1394DIAG"
#endif


#define TL_TRACE        0
#define TL_WARNING      1
#define TL_ERROR        2
#define TL_FATAL        3

extern unsigned char t1394DebugLevel;

#define TRACE( l, x )                       \
    if( (l) >= t1394DebugLevel ) {      \
        KdPrint( (_DRIVERNAME_ ": ") );     \
        KdPrint( x );                       \
    }


#define ENTER(n)        TRACE(TL_TRACE, ("%s Enter\n", n))

#define EXIT(n,x)                                   \
    if(NT_SUCCESS(__pragma(warning(disable:4127)) x __pragma(warning(disable:4127)))) { \
        TRACE(TL_TRACE, ("%s Exit = %x\n", n, x));  \
    }                                               \
    else {                                          \
        TRACE(TL_ERROR, ("%s Exit = %x\n", n, x));  \
    }

#else  // DBG

#define TRACE( l, x )

#define ENTER(n)
#define EXIT(n,x)

#endif // DBG




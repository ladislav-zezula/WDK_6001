/*++

Copyright (c) 1998  Microsoft Corporation

Module Name: 

    debug.c

--*/

#define _DEBUG_C
#include "pch.h"
#undef _DEBUG_C

void
WriteToEditWindow(
    IN HANDLE   hWnd,
    IN PUCHAR   lpszFormat, 
    IN ... 
    )
{
    char    buf[1024] = "1394API: ";
    va_list ap;

    va_start(ap, lpszFormat);

//wvsprintf( &buf[9], lpszFormat, ap );

    StringCbVPrintf(
        &buf[9],
        (1015 * sizeof(buf[0])),
        lpszFormat,
        ap
    );

    if (hWnd)
        WriteTextToEditControl(hWnd, buf);

    va_end(ap);
}

void 
DbgPrt(
    IN HANDLE   hWnd,
    IN PUCHAR   lpszFormat,
    IN ... 
    )
{
    char    buf[1024] = "1394API: ";
    va_list ap;

    va_start(ap, lpszFormat);

//    wvsprintf( &buf[9], lpszFormat, ap );

    StringCbVPrintf(
        &buf[9],
        (1015 * sizeof(buf[0])),
        lpszFormat,
        ap
    );

#if defined(DBG)
    OutputDebugStringA(buf);
#endif

    if (hWnd)
        WriteTextToEditControl(hWnd, buf);

    va_end(ap);
}



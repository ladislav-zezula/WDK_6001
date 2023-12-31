/*++

Copyright (c) 1998  Microsoft Corporation

Module Name: 

    debug.h
--*/

#define TL_TRACE    0
#define TL_WARNING  1
#define TL_ERROR    2
#define TL_FATAL    3

extern ULONG TraceLevel;

#define TRACE(tl, x)                \
    if ( (tl) >= TraceLevel ) {     \
        DbgPrt x ;                  \
    } else {                        \
        WriteToEditWindow x;        \
    }

void
DbgPrt(
    IN HANDLE   hWnd,
    IN PUCHAR   lpszFormat, 
    IN ... 
    );
    
void
WriteToEditWindow(
    IN HANDLE   hWnd,
    IN PUCHAR   lpszFormat, 
    IN ... 
    );


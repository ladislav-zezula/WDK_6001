/*++

Copyright (c) 1997-1998 Microsoft Corporation

Module Name: 

    util.h

Abstract

    Prototype, defines for util functions.

--*/

HANDLE
OpenDevice(
    HANDLE       hWnd,
    __in PSTR    szDeviceName,
    BOOL         bOverLapped
    );

VOID
WriteTextToEditControl(
    HWND         hWndEdit, 
    __in PCHAR   str
    );

// Generic singly linked list routines

typedef struct _LIST_NODE {
    struct _LIST_NODE *Next;
} LIST_NODE, *PLIST_NODE;

void 
InsertTailList(
    PLIST_NODE head, 
    PLIST_NODE entry
    );

BOOL 
RemoveEntryList(
    PLIST_NODE head, 
    PLIST_NODE entry
    );

void 
InsertHeadList(
    PLIST_NODE head, 
    PLIST_NODE entry
    );

BOOL
IsNodeOnList(
    PLIST_NODE head, 
    PLIST_NODE entry
    );



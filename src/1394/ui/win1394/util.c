/*++

Copyright (c) 1997-1998  Microsoft Corporation

Module Name: 

    util.c

Abstract

    Misc. functions that are convient to have around.
--*/

#define _UTIL_C
#include "pch.h"
#undef _UTIL_C

HANDLE
OpenDevice(
    HANDLE       hWnd,
    __in PSTR    szDeviceName
    )
{
    HANDLE  hDevice;
    CHAR    tmpBuff[STRING_SIZE];

    hDevice = CreateFile( szDeviceName,
                          GENERIC_WRITE | GENERIC_READ,
                          FILE_SHARE_WRITE | FILE_SHARE_READ,
                          NULL,
                          OPEN_EXISTING,
                          FILE_FLAG_OVERLAPPED,
                          NULL
                          );

	if (hDevice == INVALID_HANDLE_VALUE) {

        TRACE(TL_ERROR, (hWnd, "Failed to open device!\n"));

        if (hWnd) {
            //wsprintf(tmpBuff, "Error Opening Device!\r\n\r\n");
            StringCbPrintf(tmpBuff, (STRING_SIZE * sizeof(tmpBuff[0])), "Error Opening Device!\r\n\r\n");
            WriteTextToEditControl(hWnd, tmpBuff);
        }
    }

    return(hDevice);
} // OpenDevice

VOID
WriteTextToEditControl(
    HWND         hWndEdit, 
    __in PCHAR   str
    )
{
    INT     iLength;

    // get the end of buffer for edit control
    iLength = GetWindowTextLength(hWndEdit);

    // set current selection to that offset
    SendMessage(hWndEdit, EM_SETSEL, iLength, iLength);

    // add text
    SendMessage(hWndEdit, EM_REPLACESEL, 0, (LPARAM) str);

} // WriteTextToEditControl

//
// Generic singly linked list routines.
//

//***********************************************************************
//
void 
InsertTailList(
    PLIST_NODE head, 
    PLIST_NODE entry
    )
{
PLIST_NODE pCurrent = head;

    entry->pNext = 0;
    while(pCurrent->pNext)
        pCurrent = pCurrent->pNext;
    pCurrent->pNext = entry;

}

//***********************************************************************
//
BOOL 
RemoveEntryList(
    PLIST_NODE head, 
    PLIST_NODE entry
    )
{
PLIST_NODE pCurrent = head;

    while(pCurrent->pNext != entry){
        pCurrent = pCurrent->pNext;
        if(pCurrent == 0) return FALSE;
    }
    pCurrent->pNext = entry->pNext;
    return TRUE;
}
    


//***********************************************************************
//
void 
InsertHeadList(
    PLIST_NODE head, 
    PLIST_NODE entry
    )
{
    entry->pNext = head->pNext;
    head->pNext = entry;
}

//****************************************************************************
//
BOOL 
IsNodeOnList(
    PLIST_NODE head, 
    PLIST_NODE entry
    )
{
PLIST_NODE pCurrent = head;

    while(pCurrent->pNext != entry){
        pCurrent = pCurrent->pNext;
        if(pCurrent == 0) return FALSE;
    }
    return TRUE;
}



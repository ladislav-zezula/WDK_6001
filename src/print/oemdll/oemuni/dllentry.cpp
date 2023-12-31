//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//  ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//  PARTICULAR PURPOSE.
//
//  Copyright  1998 - 2003  Microsoft Corporation.  All Rights Reserved.
//
//  FILE:   dllentry.cpp
//
//
//  PURPOSE:  Source module for DLL entry function(s).
//
//
//  Functions:
//          DllMain
//
//
//
//  PLATFORMS:  Windows XP, Windows Server 2003
//
//
//  History:
//          06/24/03    xxx created.
//
//

#include "precomp.h"

// Need to export these functions as c declarations.
//
extern "C" {


///////////////////////////////////////////////////////////
//
// DLL entry point
//

// DllMain isn't called/used for kernel mode version.
//
BOOL WINAPI DllMain(HINSTANCE hInst, WORD wReason, LPVOID lpReserved)
{
    OEMDBG(DBG_VERBOSE, L"DllMain entry.");

    UNREFERENCED_PARAMETER(hInst);
    UNREFERENCED_PARAMETER(lpReserved);

    switch(wReason)
    {
        case DLL_PROCESS_ATTACH:
        VERBOSE(DLLTEXT("Process attach.\r\n"));
        break;

        case DLL_THREAD_ATTACH:
        VERBOSE(DLLTEXT("Thread attach.\r\n"));
        break;

        case DLL_PROCESS_DETACH:
        VERBOSE(DLLTEXT("Process detach.\r\n"));
        break;

        case DLL_THREAD_DETACH:
        VERBOSE(DLLTEXT("Thread detach.\r\n"));
        break;
    }

    return TRUE;
}





}  // extern "C" closing bracket



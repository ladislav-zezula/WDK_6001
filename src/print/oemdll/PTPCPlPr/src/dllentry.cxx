//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//  ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//  PARTICULAR PURPOSE.
//
//  Copyright  1998 - 2005  Microsoft Corporation.  All Rights Reserved.
//
//  FILE:	dllentry.cxx
//    
//  PURPOSE:  Source module for DLL entry function(s).
//

#include "precomp.hxx"
#include "oem.hxx"
#include "debug.hxx"
#include "globals.hxx"

// Need to export these functions as c declarations.
extern "C" {

///////////////////////////////////////////////////////////
//
// DLL entry point
//
BOOL WINAPI DllMain(HINSTANCE hInst, WORD wReason, LPVOID )
{
    switch(wReason)
    {
    case DLL_PROCESS_ATTACH:
        VERBOSE(DLLTEXT("Process attach.\r\n"));
        ghInstance = hInst;
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


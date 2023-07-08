/*++

Copyright (c) 2005 Microsoft Corporation

All rights reserved.

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

File Name:

   dllentry.cpp

Abstract:

   Implementation of the page scaling filter dllentry points. Dllmain only
   stores the instance handle. DllGetClassObject calls on to a generic
   filter get class object template function.

--*/

#include "precomp.h"
#include "debug.h"
#include "globals.h"
#include "scaleflt.h"
#include "xdexcept.h"
#include "getfltob.h"

/*++

Routine Name:

    DllMain

Routine Description:

    Entry point to the page scaling filter which is called when a new process is started

Arguments:

    hInst - Handle to the DLL module.
    wReason - Indicates why the DLL entry-point function is being called.

Return Value:

    TRUE

--*/
BOOL WINAPI
DllMain(
    __in     HINSTANCE hInst,
    __in     WORD      wReason,
    __in_opt LPVOID
    )
{
    switch (wReason)
    {
        case DLL_PROCESS_ATTACH:
        {
            g_hInstance = hInst;
        }
        break;
    }

    return TRUE;
}

/*++

Routine Name:

    DllCanUnloadNow

Routine Description:

    Determines whether the DLL is in use.
    If not, the caller can unload the DLL from memory.

Arguments:

    None

Return Value:

    HRESULT
    S_OK    - Dll can unload
    S_FALSE - Dll can't unload

--*/
STDAPI
DllCanUnloadNow()
{
    if (g_cServerLocks == 0)
    {
        return S_OK ;
    }
    else
    {
        return S_FALSE;
    }
}

/*++

Routine Name:

    DllGetClassObject

Routine Description:

    Retrieves the class object for the DLL.
    Called from within the CoGetClassObject function.

Arguments:

    rclsid - CLSID that will associate the correct data and code.
    riid - Reference to the identifier of the interface that the caller is to use to communicate with the class object.
    ppv - Address of pointer variable that receives the interface pointer requested in riid.

Return Value:

    HRESULT
    S_OK                      - On success
    E_*                       - On error
    CLASS_E_CLASSNOTAVAILABLE - On unsupported class

--*/
STDAPI
DllGetClassObject(
    __in        REFCLSID    rclsid,
    __in        REFIID      riid,
    __deref_out LPVOID FAR* ppv
    )
{
    return GetFilterObject<CPageScalingFilter>(rclsid, riid, ppv);
}



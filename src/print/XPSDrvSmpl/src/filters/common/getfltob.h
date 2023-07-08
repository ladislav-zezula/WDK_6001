/*++

Copyright (c) 2005 Microsoft Corporation

All rights reserved.

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

File Name:

   getfltob.h

Abstract:

   This file defines a template function that accepts the filter class
   type and implements DllGetClassObject functionality. This saves repeating
   essentially the same code for each filter.

--*/

#pragma once

template <class _T>
HRESULT
GetFilterObject(
    __in  REFCLSID rclsid,
    __in  REFIID   riid,
    __out VOID**   ppv
    )
{
    HRESULT hr = S_OK;

    if (SUCCEEDED(hr = CHECK_POINTER(ppv, E_POINTER)))
    {
        *ppv = NULL;

        //
        // Make sure the appropriate filter is being requested
        //
        if (rclsid == _T::GetCLSID())
        {
            _T* pFilter = NULL;

            try
            {
                pFilter = new _T;
                hr = CHECK_POINTER(pFilter, E_OUTOFMEMORY);
            }
            catch (CXDException& e)
            {
                if (pFilter != NULL)
                {
                    delete pFilter;
                    pFilter = NULL;
                }

                hr = e;
            }

            if (SUCCEEDED(hr))
            {
                //
                // Get the requested interface.
                //
                hr = pFilter->QueryInterface(riid, ppv);

                //
                // Release the IUnknown pointer.
                // (If QueryInterface failed, component will delete itself.)
                //
                pFilter->Release();
            }
        }
        else
        {
            hr =  CLASS_E_CLASSNOTAVAILABLE;
        }
    }

    ERR_ON_HR(hr);
    return hr;
}



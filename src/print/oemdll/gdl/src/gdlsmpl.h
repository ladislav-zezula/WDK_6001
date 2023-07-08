//+--------------------------------------------------------------------------
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//  ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//  PARTICULAR PURPOSE.
//
//  Copyright  1997 - 2006  Microsoft Corporation.  All Rights Reserved.
//
//  FILE:       gdlsmpl.h
//
//  PURPOSE:    COM implementation of a UI module that uses GDL.  CAbstractOemUI2
//              is defined in intrface.h, and contains a default implementation of
//              all methods not specific to this sample.
//
//  PLATFORMS:  Windows 2000, 
//              Windows XP, 
//              Windows Server 2003, 
//              Windows Vista
//
//--------------------------------------------------------------------------

#pragma once

///////////////////////////////////////
//          Globals
///////////////////////////////////////

extern HINSTANCE   ghInstance;
    // Module's Instance handle from DLLEntry of process.

#define OEM_SIGNATURE               'GDLS'
#define OEM_VERSION                 0x00000001L

class COemUI2: public CAbstractOemUI2
{
public:

    COemUI2() :
        m_pCoreHelper(NULL) 
    {}

    //
    // Method for publishing Driver interface.
    //
    STDMETHOD(PublishDriverInterface)(THIS_ IUnknown *pIUnknown);

    //
    // Get OEM dll related information
    //
    STDMETHOD(GetInfo) (THIS_ 
        DWORD  dwMode, 
        __out_bcount(cbSize) PVOID  pBuffer, 
        DWORD  cbSize,
        PDWORD pcbNeeded);

    //
    // OEMDevMode
    //
    STDMETHOD(DevMode) (THIS_  DWORD  dwMode, POEMDMPARAM pOemDMParam);

    //
    // OEMDocumentPropertySheets
    //
    STDMETHOD(DocumentPropertySheets) (THIS_
            PPROPSHEETUI_INFO   pPSUIInfo,
            LPARAM              lParam
            );

    virtual ~COemUI2();

protected:

    HRESULT
    DbgShowGPDVersion();

    HRESULT 
    LoadGDLSnapshot(
        __out IXMLDOMDocument2 **ppDOMSnapshot
        );

    IPrintCoreHelperUni* m_pCoreHelper;
        // Pointer to the helper interface introduced in Windows Vista.
};





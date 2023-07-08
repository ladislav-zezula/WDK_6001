/*++

Copyright (C) Microsoft Corporation, All Rights Reserved

Module Name:

    Device.h

Abstract:

    This module contains the type definitions for the UMDF Socketecho sample
    driver's device callback class.

Environment:

    Windows User-Mode Driver Framework (WUDF)

--*/

#pragma once


class ATL_NO_VTABLE CMyDevice : 
    public CComObjectRootEx<CComMultiThreadModel>,
    public IFileCallbackCleanup,
    public IFileCallbackClose
{
public:

DECLARE_NOT_AGGREGATABLE(CMyDevice)

BEGIN_COM_MAP(CMyDevice)
    COM_INTERFACE_ENTRY(IFileCallbackCleanup)
    COM_INTERFACE_ENTRY(IFileCallbackClose)
END_COM_MAP()

public:
    
    //IFileCallbackCleanup
    STDMETHOD_(void,OnCleanupFile)(__in IWDFFile* pWdfFileObject);
    //IFileCallbackClose
    STDMETHOD_(void,OnCloseFile)(__in IWDFFile* pWdfFileObject);
public:

      CMyDevice();
    ~CMyDevice();
	
    HRESULT 
     Initialize( 
     	__in IWDFDriver * FxDriver,
     	__in IWDFDeviceInitialize * FxDeviceInit);
    
    HRESULT
    Configure(
        );

    IWDFDevice *
    GetFxDevice(
        )
    {
        return m_FxDevice;
    }
    VOID
    GetDeviceConnectionParams(__in LPSTR *hostStr,__in LPSTR *portStr);

private:
    CComPtr<IWDFDevice> m_FxDevice;
    HRESULT  SetDeviceContextFromPropertyStore();
    HRESULT  GetAnsiValFromPropVariant( __in PROPVARIANT val,__inout LPSTR *PropertyValueA);
    LPSTR     m_hostStr;
    LPSTR     m_portStr;
    
};


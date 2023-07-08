//-----------------------------------------------------------------------
// <copyright file="WSSDevice.h" company="Microsoft">
//      Copyright (c) 2006 Microsoft Corporation. All rights reserved.
// </copyright>
//
// Module:
//      WSSDevice.h
//
// Description:
//      This class implements the IPnpCallbackHardware
//      interface.  It represents the UMDF device instance, and allows
//      access to the device.
//
//-----------------------------------------------------------------------

#pragma once

#include "BasicDDI.h"

class IWSSTransport;

class ATL_NO_VTABLE CWSSDevice :
    public CComObjectRootEx<CComMultiThreadModel>,
    public IPnpCallbackHardware
{
public:
    virtual ~CWSSDevice();

public:
    DECLARE_NOT_AGGREGATABLE(CWSSDevice)

    BEGIN_COM_MAP(CWSSDevice)
        COM_INTERFACE_ENTRY(IPnpCallbackHardware)
    END_COM_MAP()

    //
    // IPnpCallbackHardware
    //
    STDMETHOD (OnPrepareHardware)(/*[in]*/ IWDFDevice* pWdfDevice);

    STDMETHOD (OnReleaseHardware)(/*[in]*/ IWDFDevice* pWdfDevice);

public:
    static HRESULT CreateDeviceInstance(
        WSSDevicePtr*                   ppDevice,
        IWDFDeviceInitialize*           pDeviceInit
        );

    HRESULT FinalConstruct();
    void    FinalRelease();

    HRESULT InitializeClassExtension();
    HRESULT ProcessIoControl(
        IWDFIoQueue*     pQueue,
        IWDFIoRequest*   pRequest,
        ULONG            ControlCode,
        SIZE_T           InputBufferSizeInBytes,
        SIZE_T           OutputBufferSizeInBytes,
        DWORD*           pcbWritten
        );

protected:
    CWSSDevice();

    //
    // Device helper methods
    //
    HRESULT BasicDriverInitialization(void);
    HRESULT BasicDriverShutdown(void);

private:
    //
    // DDI
    //
    CComPtr<ISideShowClassExtension>    m_pClassExtension;
    CComObject<CWssBasicDDI>*           m_pBasicDriver;

    //
    // Store the IWDFDevice pointer so we can use it later for eventing
    //
    CComPtr<IWDFDevice>                 m_pWdfDevice;
};



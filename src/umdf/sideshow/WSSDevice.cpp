//-----------------------------------------------------------------------
// <copyright file="WSSDevice.cpp" company="Microsoft">
//      Copyright (c) 2006 Microsoft Corporation.  All rights reserved.
// </copyright>
//
// Module:
//      WSSDevice.cpp
//
// Description:
//      This file implements the CWSSDevice class.
//
//-----------------------------------------------------------------------

#include "Common.h"
#include "WSSDevice.h"
#include <WindowsSideShowDriverEvents.h>

#include <setupapi.h>
#include <strsafe.h>
#include <devguid.h>

// Basic Driver
#include "DataManager.h"
#include "Renderer.h"
#include "DeviceSpecific.h"

bool g_fDeviceIsValid = false;
CDevice g_Device; // Singleton object
CDataManager* g_pDataManager = NULL;


/////////////////////////////////////////////////////////////////////////
//
// CWSSDevice::CWSSDevice
//
// Object constructor function; initializes various members
//
/////////////////////////////////////////////////////////////////////////
CWSSDevice::CWSSDevice() :
m_pWdfDevice(NULL),
m_pClassExtension(NULL),
m_pBasicDriver(NULL)
{
}

/////////////////////////////////////////////////////////////////////////
//
// CWSSDevice::~CWSSDevice
//
// Object destructor function
//
/////////////////////////////////////////////////////////////////////////
CWSSDevice::~CWSSDevice()
{
}

/////////////////////////////////////////////////////////////////////////
//
// CWSSDevice::FinalRelease
//
// Called by ATL before deleting this object.
//
/////////////////////////////////////////////////////////////////////////
void CWSSDevice::FinalRelease()
{
    if (NULL != m_pBasicDriver)
    {
        m_pBasicDriver->Release();
    }
}

/////////////////////////////////////////////////////////////////////////
//
// CWSSDevice::FinalConstruct()
//
// Called by ATL after creating this object.
//
/////////////////////////////////////////////////////////////////////////
HRESULT CWSSDevice::FinalConstruct()
{
    HRESULT hr = S_OK;

    //
    // Create the Driver object which implements ISideShowEnhancedDriver
    //
    hr = CComObject<CWssBasicDDI>::CreateInstance(&m_pBasicDriver);
    if (SUCCEEDED(hr) && m_pBasicDriver)
    {
        m_pBasicDriver->AddRef();
    }

    return hr;
}

/////////////////////////////////////////////////////////////////////////
//
// CWSSDevice::CreateDeviceInstance
//
// This static method is used to create and initialize an instance of
// CWSSDevice for use with a given hardware device.
//
// Parameters:
//      out_ppDevice - pointer to an instance of CWSSDevice (out ptr)
//      pDeviceInit  - pointer to an interface used to initialize the device
//
// Return Values:
//      S_OK: object created successfully
//
/////////////////////////////////////////////////////////////////////////
HRESULT CWSSDevice::CreateDeviceInstance(
    WSSDevicePtr * out_ppDevice,
    IWDFDeviceInitialize* pDeviceInit
    )
{
    HRESULT hr = S_OK;
    CComObject<CWSSDevice>* pMyDevice = NULL;

    //
    // Set device properties.
    //
    pDeviceInit->SetLockingConstraint(WdfDeviceLevel);

    //
    // Make sure we aren't the power policy owner
    //
    pDeviceInit->SetPowerPolicyOwnership(FALSE);

    //
    // Create the device instance
    //
    hr = CComObject<CWSSDevice>::CreateInstance(&pMyDevice);

    if (SUCCEEDED(hr) && NULL != pMyDevice)
    {
        *out_ppDevice = pMyDevice;
        pMyDevice->AddRef();
    }
    else
    {
        *out_ppDevice = NULL;
    }

    return hr;
}


/////////////////////////////////////////////////////////////////////////
//
// CWSSDevice::OnPrepareHardware
//
// Called by UMDF to prepare the hardware for use.
//
// Parameters:
//      pWdfDevice - pointer to an IWDFDevice object representing the
//      device
//
// Return Values:
//      S_OK: success
//
/////////////////////////////////////////////////////////////////////////
HRESULT CWSSDevice::OnPrepareHardware(IWDFDevice* pWdfDevice)
{
    HRESULT hr = S_OK;

    //
    // Store the IWDFDevice pointer locally
    //
    m_pWdfDevice = pWdfDevice;

    if ((NULL == m_pWdfDevice) ||
        (NULL == m_pBasicDriver))
    {
        return E_UNEXPECTED;
    }

    hr = BasicDriverInitialization();
    if (FAILED(hr))
    {
        // ERROR
    }

    if (SUCCEEDED(hr))
    {
        hr = InitializeClassExtension();
        if (FAILED(hr))
        {
            // ERROR: Failed to register the driver with the class extension
        }        
    }

    return hr;
}

/////////////////////////////////////////////////////////////////////////
//
// CWSSDevice::OnReleaseHardware
//
// Called by WUDF to uninitialize the hardware.
//
// Parameters:
//      pWdfDevice - pointer to an IWDFDevice object for the device
//
// Return Values:
//      S_OK:
//
/////////////////////////////////////////////////////////////////////////
HRESULT CWSSDevice::OnReleaseHardware(IWDFDevice* pWdfDevice)
{
    HRESULT hr = S_OK;

    //
    // Cleanup the DDI object
    //
    if (m_pBasicDriver != NULL)
    {
        hr = m_pBasicDriver->Deinitialize();
    }

    //
    // Shutdown the device specific components
    //
    BasicDriverShutdown();

    //
    // Release the Class Extension
    //
    if (m_pClassExtension != NULL)
    {
        m_pClassExtension->Uninitialize(pWdfDevice);
        m_pClassExtension.Release();
    }

    //
    // Release the IWDFDevice handle, if it matches
    //
    if (pWdfDevice == m_pWdfDevice.p)
    {
        m_pWdfDevice.Release();
    }

    return hr;
}

/////////////////////////////////////////////////////////////////////////
//
// CWSSDevice::InitializeClassExtension
//
// This method initializes the Windows SideShow class extension component.
//
// Return Values:
//      S_OK:
//
/////////////////////////////////////////////////////////////////////////
HRESULT CWSSDevice::InitializeClassExtension()
{
    HRESULT hr = S_OK;

    if (m_pClassExtension == NULL)
    {
        //
        // Construct a SideShowClassExtension object to process IOCTLs.
        //
        hr = CoCreateInstance(CLSID_SideShowClassExtension,
                              NULL,
                              CLSCTX_INPROC_SERVER,
                              IID_ISideShowClassExtension,
                              (VOID**)&m_pClassExtension);
        if (FAILED(hr))
        {
            // ERROR: Failed to CoCreate CLSID_SideShowClassExtension
        }
    }

    //
    // Create an instance of our Driver and register it with the Windows SideShow
    // class extension object.  The Windows SideShow class extension Object is now ready to
    // accept forwarded WPD IOCTLs.
    //
    if (SUCCEEDED(hr))
    {
        hr = m_pClassExtension->Initialize(m_pWdfDevice, m_pBasicDriver);
        if (FAILED(hr))
        {
            // ERROR: Failed to register CWssBasicDDI with class extension
        }
    }

    return hr;
}

/////////////////////////////////////////////////////////////////////////
//
// CWSSDevice::ProcessIoControl
//
// This method is a helper that takes the incoming IOCTL and forwards
// it to the Windows SideShow Class Extension for processing.
//
// Parameters:
//      pQueue                  - [in] pointer to the UMDF queue that handled the request
//      pRequest                - [in] pointer to the request
//      ControlCode             - [in] the IOCTL code
//      InputBufferSizeInBytes  - [in] size of the incoming IOCTL buffer
//      OutputBufferSizeInBytes - [out] size of the outgoing IOCTL buffer
//      pcbWritten              - pointer to a DWORD containing the number of bytes returned
//
// Return Values:
//      S_OK:
//
/////////////////////////////////////////////////////////////////////////
HRESULT CWSSDevice::ProcessIoControl(/* [in] */ IWDFIoQueue*     pQueue,
                                     /* [in] */ IWDFIoRequest*   pRequest,
                                     /* [in] */ ULONG            ControlCode,
                                     /* [in] */ SIZE_T           InputBufferSizeInBytes,
                                     /* [in] */ SIZE_T           OutputBufferSizeInBytes,
                                     /* [out]*/ DWORD*           pcbWritten)
{
    if (m_pClassExtension == NULL)
    {
        return E_UNEXPECTED;
    }

    HRESULT hr = S_OK;

    hr = m_pClassExtension->OnProcessIoControl(pQueue,
                                               pRequest,
                                               ControlCode,
                                               InputBufferSizeInBytes,
                                               OutputBufferSizeInBytes,
                                               pcbWritten);

    return hr;
}


/////////////////////////////////////////////////////////////////////////
//
// CWSSDevice::BasicDriverInitialization
//
// This method initializes the driver
//
// Parameters:
//      void - (unused argument)
//
// Return Values:
//      S_OK:
//
/////////////////////////////////////////////////////////////////////////
HRESULT CWSSDevice::BasicDriverInitialization(void)
{
    HRESULT hr = S_OK;

    // Initialize the Basic DDI
    CComPtr<IWDFNamedPropertyStore> pStore;

    hr = m_pWdfDevice->RetrieveDevicePropertyStore(NULL, WdfPropertyStoreCreateIfMissing, &pStore, NULL);
    if (SUCCEEDED(hr))
    {
        hr = m_pBasicDriver->Initialize(pStore);
    }

    // Order of initialization: Device display, GDIPlus, DataManager, Device buttons (second thread)
    if (SUCCEEDED(hr))
    {
        if (S_OK == DeviceDisplayInitialization())
        {
            g_fDeviceIsValid = true;
        }
    }

    if (SUCCEEDED(hr))
    {
        hr = CRendererBase::GDIPlusInitialization();
    }

    if (SUCCEEDED(hr))
    {
        g_pDataManager = new CDataManager(CNodeDefaultBackground(CRendererBase::GetDefaultBackgroundTitle(), wcslen(CRendererBase::GetDefaultBackgroundTitle()) + 1,
                                                                 CRendererBase::GetDefaultBackgroundBody(), wcslen(CRendererBase::GetDefaultBackgroundBody()) + 1,
                                                                 NULL, 0)); // Singleton object        
        if (NULL == g_pDataManager)
        {
            // ERROR: new g_pDataManager failed: Critical failure
            hr = E_OUTOFMEMORY;
        }
    }

    if (SUCCEEDED(hr))
    {
        hr = DeviceButtonsInitialization();
    }

    return hr;
}


/////////////////////////////////////////////////////////////////////////
//
// CWSSDevice::BasicDriverShutdown
//
// This method cleans up the driver
//
// Parameters:
//      void - (unused argument)
//
// Return Values:
//      S_OK:
//
/////////////////////////////////////////////////////////////////////////
HRESULT CWSSDevice::BasicDriverShutdown(void)
{
    // Order of shutdown: Device buttons (second thread), DataManager, GDIPlus, Device display
    DeviceButtonsShutdown();
    if (NULL != g_pDataManager)
    {
        delete g_pDataManager;
        g_pDataManager = NULL;
    }
    CRendererBase::GDIPlusShutdown();
    DeviceDisplayShutdown();
    return S_OK;
}


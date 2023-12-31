
#include "stdafx.h"
#include "Driver.h"
#include "Device.h"
#include "Queue.h"

CDriver::CDriver()
{


}

//
// The framework call this function when device is detected. This driver
// creates a device callback object and
//
HRESULT
CDriver::OnDeviceAdd(
        IWDFDriver* pDriver,
        IWDFDeviceInitialize* pDeviceInit
        )
/*++

Routine Description:

    The framework calls this function when a device is being added to
    the driver stack.

Arguments:

    IWDFDriver           - Framework interface.  The driver uses this
                           interface to create device objects.
    IWDFDeviceInitialize - Framework interface.  The driver uses this
                           interface to set device parameters before
                           creating the device obeject.

Return Value:

   HRESULT S_OK - Device added successfully

--*/
{


    HRESULT hr = S_OK;
    CComPtr<IUnknown> pDeviceCallback;

    if (hr == S_OK)
    {
        WpdBaseDriver *pWpdBaseDriver = NULL;

        //
        // Create the WPD driver object that handles all WPD messages for this device
        //
        pWpdBaseDriver = new WpdBaseDriver();
        if(pWpdBaseDriver == NULL)
        {
            hr = E_OUTOFMEMORY;
        }

        if(SUCCEEDED(hr))
        {
            //
            // Create device callback object
            //
            hr = CDevice::CreateInstance(&pDeviceCallback, pDeviceInit, pWpdBaseDriver);
        }

        //
        // Set device properties.
        //
        if (SUCCEEDED(hr))
        {
            pDeviceInit->SetLockingConstraint(WdfDeviceLevel);

        }

        //
        // This driver has no special power management requirements and so
        // we set power policy ownership to UMDF to indicate that UMDF should
        // handle powermanagement for us.
        //
        pDeviceInit->SetPowerPolicyOwnership(FALSE);

        //
        // Create WDFDevice.
        //
        CComPtr<IWDFDevice> pIWDFDevice;
        if(SUCCEEDED(hr))
        {
            hr = pDriver->CreateDevice(
                    pDeviceInit,
                    pDeviceCallback,
                    &pIWDFDevice);
        }

        //
        // Assign pWpdBaseDriver to the device object.  Each UMDF device requires its own instance of
        // a WpdBaseDriver to handle WPD messages.
        //
        if(SUCCEEDED(hr))
        {
            hr = pIWDFDevice->AssignContext(this, (void*)pWpdBaseDriver);
            if(SUCCEEDED(hr))
            {
                //  AddRef the WpdBaseDriver object since it is not stored with the
                //  device context.
                pWpdBaseDriver->AddRef();
            }
        }

        //
        // Create queue callback object
        //
        IUnknown *pIUnknown = NULL;
        if(S_OK == hr)
        {
            hr = CQueue::CreateInstance(&pIUnknown);
        }

        //
        // Configure the default queue.
        //
        if(S_OK == hr)
        {
            CComPtr<IWDFIoQueue> pDefaultQueue;
            hr = pIWDFDevice->CreateIoQueue(
                              pIUnknown,
                              TRUE,                         // bDefaultQueue
                              WdfIoQueueDispatchSequential,
                              TRUE,                         // bPowerManaged
                              FALSE,                        // bAllowZeroLengthRequests
                              &pDefaultQueue);
        }

        pDeviceCallback = NULL;
        pIWDFDevice = NULL;

        //
        // It is fine to release the interface on the callback object.
        // The framework has its own refcount on this object and will
        // provide an interface when calling into the driver.
        //
        pIUnknown = NULL;

        // Release the WpdBaseDriver object.  If it was successfully added to the device context,
        // it was already addref'd above. Releasing it here ensures it will be destroyed if
        // an error occured and it could not be added to the device context.
        SAFE_RELEASE(pWpdBaseDriver);
    }

    return hr;
}

void
CDriver::OnDeinitialize(
    IWDFDriver* pDriver
    )
/*++

Routine Description:

    The framework calls this function just before de-initializing itself. All
    WDF framework resources should be released by driver before returning from this call.

Arguments:

Return Value:

--*/
{
    UNREFERENCED_PARAMETER(pDriver);
    return;
}

HRESULT
CDriver::OnInitialize(
    IWDFDriver* pDriver
    )
/*++

Routine Description:

    The framework calls this function just after loading the driver. The driver can
    perform any global, device independent intialization in this routine.

Arguments:

Return Value:

--*/
{
    UNREFERENCED_PARAMETER(pDriver);
    return S_OK;
}

STDMETHODIMP_ (void)
CDriver::OnCleanup(
    IWDFObject* pWdfObject
    )
{
    // Release the base driver object
    HRESULT         hr              = S_OK;
    WpdBaseDriver*  pWpdBaseDriver  = NULL;

    hr = pWdfObject->RetrieveContext((void**)&pWpdBaseDriver);
    if((hr == S_OK) && (pWpdBaseDriver != NULL))
    {
        pWpdBaseDriver->Release();
        pWpdBaseDriver = NULL;
    }
}


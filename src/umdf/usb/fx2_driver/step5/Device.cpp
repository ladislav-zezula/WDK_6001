/*++
 
Copyright (C) Microsoft Corporation, All Rights Reserved.

Module Name:

    Device.cpp

Abstract:

    This module contains the implementation of the UMDF Skeleton sample driver's
    device callback object.

    The skeleton sample device does very little.  It does not implement either
    of the PNP interfaces so once the device is setup, it won't ever get any
    callbacks until the device is removed.

Environment:

   Windows User-Mode Driver Framework (WUDF)

--*/

#include "internal.h"
#include "initguid.h"
#include "usb_hw.h"

#include "device.tmh"

CMyDevice::~CMyDevice(
    )
{
}

HRESULT
CMyDevice::CreateInstance(
    __in IWDFDriver *FxDriver,
    __in IWDFDeviceInitialize * FxDeviceInit,
    __out PCMyDevice *Device
    )
/*++
 
  Routine Description:

    This method creates and initializs an instance of the skeleton driver's 
    device callback object.

  Arguments:

    FxDeviceInit - the settings for the device.

    Device - a location to store the referenced pointer to the device object.

  Return Value:

    Status

--*/
{
    PCMyDevice device;
    HRESULT hr;

    //
    // Allocate a new instance of the device class.
    //

    device = new CMyDevice();

    if (NULL == device)
    {
        return E_OUTOFMEMORY;
    }

    //
    // Initialize the instance.
    //

    hr = device->Initialize(FxDriver, FxDeviceInit);

    if (SUCCEEDED(hr)) 
    {
        *Device = device;
    } 
    else 
    {
        device->Release();
    }

    return hr;
}

HRESULT
CMyDevice::Initialize(
    __in IWDFDriver           * FxDriver,
    __in IWDFDeviceInitialize * FxDeviceInit
    )
/*++
 
  Routine Description:

    This method initializes the device callback object and creates the
    partner device object.

    The method should perform any device-specific configuration that:
        *  could fail (these can't be done in the constructor)
        *  must be done before the partner object is created -or-
        *  can be done after the partner object is created and which aren't 
           influenced by any device-level parameters the parent (the driver
           in this case) might set.

  Arguments:

    FxDeviceInit - the settings for this device.

  Return Value:

    status.

--*/
{
    IWDFDevice *fxDevice = NULL;

    HRESULT hr = S_OK;

    //
    // Configure things like the locking model before we go to create our 
    // partner device.
    //

    //
    // TODO: Set the locking model.  The skeleton uses device level
    //       locking, but you can choose "none" as well.
    //

    FxDeviceInit->SetLockingConstraint(WdfDeviceLevel);

    //
    // TODO: If you're writing a filter driver then indicate that here. 
    //
    // FxDeviceInit->SetFilter();
    //
        
    //
    // TODO: Any per-device initialization which must be done before 
    //       creating the partner object.
    //

    //
    // Create a new FX device object and assign the new callback object to 
    // handle any device level events that occur.
    //

    //
    // QueryIUnknown references the IUnknown interface that it returns
    // (which is the same as referencing the device).  We pass that to 
    // CreateDevice, which takes its own reference if everything works.
    //

    if (SUCCEEDED(hr)) 
    {
        IUnknown *unknown = this->QueryIUnknown();

        hr = FxDriver->CreateDevice(FxDeviceInit, unknown, &fxDevice);

        unknown->Release();
    }

    //
    // If that succeeded then set our FxDevice member variable.
    //

    if (SUCCEEDED(hr)) 
    {
        m_FxDevice = fxDevice;

        //
        // Drop the reference we got from CreateDevice.  Since this object
        // is partnered with the framework object they have the same 
        // lifespan - there is no need for an additional reference.
        //

        fxDevice->Release();
    }

    return hr;
}

HRESULT
CMyDevice::Configure(
    VOID
    )
/*++
 
  Routine Description:

    This method is called after the device callback object has been initialized 
    and returned to the driver.  It would setup the device's queues and their 
    corresponding callback objects.

  Arguments:

    FxDevice - the framework device object for which we're handling events.

  Return Value:

    status

--*/
{   
    HRESULT hr = S_OK;

    hr = CMyReadWriteQueue::CreateInstance(this, &m_ReadWriteQueue);

    if (FAILED(hr))
    {
        return hr;
    }

    //
    // We use default queue for read/write
    //
    
    hr = m_ReadWriteQueue->Configure();

    m_ReadWriteQueue->Release();

    //
    // Create the control queue and configure forwarding for IOCTL requests.
    //

    if (SUCCEEDED(hr)) 
    {
        hr = CMyControlQueue::CreateInstance(this, &m_ControlQueue);

        if (SUCCEEDED(hr)) 
        {
            hr = m_ControlQueue->Configure();
            if (SUCCEEDED(hr)) 
            {
                m_FxDevice->ConfigureRequestDispatching(
                                m_ControlQueue->GetFxQueue(),
                                WdfRequestDeviceIoControl,
                                true
                                );
            }
            m_ControlQueue->Release();
        }
    }

    //
    // Create a manual I/O queue to hold requests for notification when
    // the switch state changes.
    //
    // We provide the device as the callback object even though the 
    // manual queue won't raise any events.
    //

    IUnknown * pQueueCallbackInterface = this->QueryIUnknown();

    hr = m_FxDevice->CreateIoQueue(pQueueCallbackInterface,
                                   FALSE,
                                   WdfIoQueueDispatchManual,
                                   false,
                                   false,
                                   &m_SwitchChangeQueue);
    
    //
    // Fx queue would take its own reference, release the reference that QueryIUnknown took
    //
    
    SAFE_RELEASE(pQueueCallbackInterface);

    //
    // Release creation reference as object tree will keep a reference
    //
    
    m_SwitchChangeQueue->Release();

    if (SUCCEEDED(hr)) 
    {
        hr = m_FxDevice->CreateDeviceInterface(&GUID_DEVINTERFACE_OSRUSBFX2,
                                               NULL);
    }

    return hr;
}

HRESULT
CMyDevice::QueryInterface(
    __in REFIID InterfaceId,
    __deref_out PVOID *Object
    )
/*++
 
  Routine Description:

    This method is called to get a pointer to one of the object's callback
    interfaces.  

    Since the skeleton driver doesn't support any of the device events, this
    method simply calls the base class's BaseQueryInterface.

    If the skeleton is extended to include device event interfaces then this 
    method must be changed to check the IID and return pointers to them as
    appropriate.

  Arguments:

    InterfaceId - the interface being requested

    Object - a location to store the interface pointer if successful

  Return Value:

    S_OK or E_NOINTERFACE

--*/
{
    HRESULT hr;

    if (IsEqualIID(InterfaceId, __uuidof(IPnpCallbackHardware)))
    {
        *Object = QueryIPnpCallbackHardware();
        hr = S_OK;    
    }
    else if(IsEqualIID(InterfaceId, __uuidof(IRequestCallbackRequestCompletion))) 
    {    
        *Object = QueryIRequestCallbackRequestCompletion();
        hr = S_OK;  
    }
    else
    {
        hr = CUnknown::QueryInterface(InterfaceId, Object);
    }

    return hr;
}

HRESULT
CMyDevice::OnPrepareHardware(
    __in IWDFDevice * /* FxDevice */
    )
/*++

Routine Description:

    This routine is invoked to ready the driver
    to talk to hardware. It opens the handle to the 
    device and talks to it using the WINUSB interface.
    It invokes WINUSB to discver the interfaces and stores
    the information related to bulk endpoints.

Arguments:

    FxDevice  : Pointer to the WDF device interface

Return Value:

    HRESULT 

--*/
{
    PWSTR deviceName = NULL;
    DWORD deviceNameCch = 0;

    HRESULT hr;

    //
    // Get the device name.
    // Get the length to allocate first
    //

    hr = m_FxDevice->RetrieveDeviceName(NULL, &deviceNameCch);

    if (FAILED(hr))
    {
        TraceEvents(TRACE_LEVEL_ERROR, 
                    TEST_TRACE_DEVICE, 
                    "%!FUNC! Cannot get device name %!hresult!",
                    hr
                    );
    }

    //
    // Allocate the buffer
    //

    if (SUCCEEDED(hr))
    {
        deviceName = new WCHAR[deviceNameCch];

        if (deviceName == NULL)
        {
            hr = E_OUTOFMEMORY;
        }
    }

    //
    // Get the actual name
    //

    if (SUCCEEDED(hr))
    {
        hr = m_FxDevice->RetrieveDeviceName(deviceName, &deviceNameCch);

        if (FAILED(hr))
        {
            TraceEvents(TRACE_LEVEL_ERROR, 
                        TEST_TRACE_DEVICE, 
                        "%!FUNC! Cannot get device name %!hresult!",
                        hr
                        );
        }
    }

    if (SUCCEEDED(hr))
    {
        TraceEvents(TRACE_LEVEL_INFORMATION, 
                    TEST_TRACE_DEVICE, 
                    "%!FUNC! Device name %S",
                    deviceName
                    );
    }

    //
    // Create USB I/O Targets and configure them
    //

    if (SUCCEEDED(hr))
    {
        hr = CreateUsbIoTargets();
    }

    if (SUCCEEDED(hr))
    {
        ULONG length = sizeof(m_Speed);

        hr = m_pIUsbTargetDevice->RetrieveDeviceInformation(DEVICE_SPEED, 
                                                            &length,
                                                            &m_Speed);
        if (FAILED(hr)) 
        {
            TraceEvents(TRACE_LEVEL_ERROR, 
                        TEST_TRACE_DEVICE, 
                        "%!FUNC! Cannot get usb device speed information %!HRESULT!",
                        hr
                        );
        }
    }

    if (SUCCEEDED(hr)) 
    {
        TraceEvents(TRACE_LEVEL_INFORMATION, 
                    TEST_TRACE_DEVICE, 
                    "%!FUNC! Speed - %x\n",
                    m_Speed
                    );
    }

    if (SUCCEEDED(hr))
    {
        hr = ConfigureUsbPipes();
    }

    if (SUCCEEDED(hr))
    {
        //
        // If the device stack allows read to remain pending across power-down
        // and up, it can be initiated during OnPrepareHardware
        //
        // If the device stack doesn't allow the read to remain pending (i.e. it
        // cancels the pending read during power transition) driver will have to
        // stop sending pending read during D0Exit and re-initiate it during
        // D0Entry
        //
        // USB core actually doesn't allow read to remain pending across power
        // transition but WinUSB does. Since we are layered above WinUSB we don't 
        // need to manage pending read across power transitions.
        //
        
        hr =  InitiatePendingRead();        
    }

    delete[] deviceName;

    return hr;
}

HRESULT
CMyDevice::OnReleaseHardware(
    __in IWDFDevice * /* FxDevice */
    )
/*++

Routine Description:

    This routine is invoked when the device is being removed or stopped
    It releases all resources allocated for this device.

Arguments:

    FxDevice - Pointer to the Device object.

Return Value:

    HRESULT - Always succeeds.

--*/
{
    //
    // Delete USB Target Device WDF Object, this will in turn
    // delete all the children - interface and the pipe objects
    //
    // This makes sure that 
    //    1. We drain the the pending read which does not come from an I/O queue
    //    2. We remove USB target objects from object tree (and thereby free them)
    //       before any potential subsequent OnPrepareHardware creates new ones
    //
    // m_pIUsbTargetDevice could be NULL if OnPrepareHardware failed so we need
    // to guard against that
    //

    if (m_pIUsbTargetDevice)
    {
        m_pIUsbTargetDevice->DeleteWdfObject();
    }
    
    return S_OK;
}

HRESULT
CMyDevice::CreateUsbIoTargets(
    )
/*++

Routine Description:

    This routine creates Usb device, interface and pipe objects

Arguments:

    None

Return Value:

    HRESULT
--*/
{
    HRESULT                 hr;
    UCHAR                   NumEndPoints = 0;
    IWDFUsbTargetFactory *  pIUsbTargetFactory = NULL;
    IWDFUsbTargetDevice *   pIUsbTargetDevice = NULL;
    IWDFUsbInterface *      pIUsbInterface = NULL;
    IWDFUsbTargetPipe *     pIUsbPipe = NULL;
    
    hr = m_FxDevice->QueryInterface(IID_PPV_ARGS(&pIUsbTargetFactory));

    if (FAILED(hr))
    {
        TraceEvents(TRACE_LEVEL_ERROR, 
                    TEST_TRACE_DEVICE, 
                    "%!FUNC! Cannot get usb target factory %!HRESULT!",
                    hr
                    );        
    }

    if (SUCCEEDED(hr)) 
    {
        hr = pIUsbTargetFactory->CreateUsbTargetDevice(
                                                  &pIUsbTargetDevice);
        if (FAILED(hr))
        {
            TraceEvents(TRACE_LEVEL_ERROR, 
                        TEST_TRACE_DEVICE, 
                        "%!FUNC! Unable to create USB Device I/O Target %!HRESULT!",
                        hr
                        );        
        }
        else
        {
            m_pIUsbTargetDevice = pIUsbTargetDevice;

            //
            // Release the creation reference as object tree will maintain a reference
            //
            
            pIUsbTargetDevice->Release();            
        }
    }

    if (SUCCEEDED(hr)) 
    {
        UCHAR NumInterfaces = pIUsbTargetDevice->GetNumInterfaces();

        WUDF_TEST_DRIVER_ASSERT(1 == NumInterfaces);
        
        hr = pIUsbTargetDevice->RetrieveUsbInterface(0, &pIUsbInterface);
        if (FAILED(hr))
        {
            TraceEvents(TRACE_LEVEL_ERROR, 
                        TEST_TRACE_DEVICE, 
                        "%!FUNC! Unable to retrieve USB interface from USB Device I/O Target %!HRESULT!",
                        hr
                        );        
        }
        else
        {
            m_pIUsbInterface = pIUsbInterface;

            pIUsbInterface->Release(); //release creation reference                        
        }
    }

    if (SUCCEEDED(hr)) 
    {
        NumEndPoints = pIUsbInterface->GetNumEndPoints();

        if (NumEndPoints != NUM_OSRUSB_ENDPOINTS) {
            hr = E_UNEXPECTED;
            TraceEvents(TRACE_LEVEL_ERROR, 
                        TEST_TRACE_DEVICE, 
                        "%!FUNC! Has %d endpoints, expected %d, returning %!HRESULT! ", 
                        NumEndPoints,
                        NUM_OSRUSB_ENDPOINTS,
                        hr
                        );
        }
    }

    if (SUCCEEDED(hr)) 
    {
        for (UCHAR PipeIndex = 0; PipeIndex < NumEndPoints; PipeIndex++)
        {
            hr = pIUsbInterface->RetrieveUsbPipeObject(PipeIndex, 
                                                  &pIUsbPipe);

            if (FAILED(hr))
            {
                TraceEvents(TRACE_LEVEL_ERROR, 
                            TEST_TRACE_DEVICE, 
                            "%!FUNC! Unable to retrieve USB Pipe for PipeIndex %d, %!HRESULT!",
                            PipeIndex,
                            hr
                            );        
            }
            else
            {
                if ( pIUsbPipe->IsInEndPoint() )
                {
                    if ( UsbdPipeTypeInterrupt == pIUsbPipe->GetType() )
                    {
                        m_pIUsbInterruptPipe = pIUsbPipe;
                    }
                    else if ( UsbdPipeTypeBulk == pIUsbPipe->GetType() )
                    {
                        m_pIUsbInputPipe = pIUsbPipe;
                    }
                    else
                    {
                        pIUsbPipe->DeleteWdfObject();
                    }                      
                }
                else if ( pIUsbPipe->IsOutEndPoint() && (UsbdPipeTypeBulk == pIUsbPipe->GetType()) )
                {
                    m_pIUsbOutputPipe = pIUsbPipe;
                }
                else
                {
                    pIUsbPipe->DeleteWdfObject();
                }
    
                SAFE_RELEASE(pIUsbPipe); //release creation reference
            }
        }

        if (NULL == m_pIUsbInputPipe || NULL == m_pIUsbOutputPipe)
        {
            hr = E_UNEXPECTED;
            TraceEvents(TRACE_LEVEL_ERROR, 
                        TEST_TRACE_DEVICE, 
                        "%!FUNC! Input or output pipe not found, returning %!HRESULT!",
                        hr
                        );        
        }
    }

    SAFE_RELEASE(pIUsbTargetFactory);

    return hr;
}

HRESULT
CMyDevice::ConfigureUsbPipes(
    )
/*++

Routine Description:

    This routine retrieves the IDs for the bulk end points of the USB device.

Arguments:

    None

Return Value:

    HRESULT
--*/
{
    HRESULT                 hr = S_OK;
    LONG                    timeout;

    //
    // Set timeout policies for input/output pipes
    //

    if (SUCCEEDED(hr)) 
    {
        timeout = ENDPOINT_TIMEOUT;

        hr = m_pIUsbInputPipe->SetPipePolicy(PIPE_TRANSFER_TIMEOUT,
                                             sizeof(timeout),
                                             &timeout);
        if (FAILED(hr))
        {
            TraceEvents(TRACE_LEVEL_ERROR, 
                        TEST_TRACE_DEVICE, 
                        "%!FUNC! Unable to set timeout policy for input pipe %!HRESULT!",
                        hr
                        );
        }
    }
        
    if (SUCCEEDED(hr)) 
    {
        timeout = ENDPOINT_TIMEOUT;

        hr = m_pIUsbOutputPipe->SetPipePolicy(PIPE_TRANSFER_TIMEOUT,
                                             sizeof(timeout),
                                             &timeout);
        if (FAILED(hr)) 
        {
            TraceEvents(TRACE_LEVEL_ERROR, 
                        TEST_TRACE_DEVICE, 
                        "%!FUNC! Unable to set timeout policy for output pipe %!HRESULT!",
                        hr
                        );
        }
    }

    return hr;
}

HRESULT
CMyDevice::SetBarGraphDisplay(
    __in PBAR_GRAPH_STATE BarGraphState
    )
/*++
 
  Routine Description:

    This method synchronously sets the bar graph display on the OSR USB-FX2 
    device using the buffers in the FxRequest as input.

  Arguments:

    FxRequest - the request to set the bar-graph info.

  Return Value:

    Status

--*/
{
    WINUSB_CONTROL_SETUP_PACKET setupPacket;

    ULONG bytesTransferred;

    HRESULT hr = S_OK;

    //
    // Setup the control packet.
    //

    WINUSB_CONTROL_SETUP_PACKET_INIT( &setupPacket,
                                      BmRequestHostToDevice,
                                      BmRequestToDevice,
                                      USBFX2LK_SET_BARGRAPH_DISPLAY,
                                      0,
                                      0 );

    //
    // Issue the request to WinUsb.
    //

    hr = SendControlTransferSynchronously(
                &(setupPacket.WinUsb),
                (PUCHAR) BarGraphState,
                sizeof(BAR_GRAPH_STATE),
                &bytesTransferred
                );


    return hr;
}

HRESULT
CMyDevice::SendControlTransferSynchronously(
    __in PWINUSB_SETUP_PACKET SetupPacket,
    __inout_ecount(BufferLength) PBYTE Buffer,
    __in ULONG BufferLength,
    __out PULONG LengthTransferred
    )
{
    HRESULT hr = S_OK;
    IWDFIoRequest *pWdfRequest = NULL;
    IWDFDriver * FxDriver = NULL;
    IWDFMemory * FxMemory = NULL; 
    IWDFRequestCompletionParams * FxComplParams = NULL;
    IWDFUsbRequestCompletionParams * FxUsbComplParams = NULL;

    *LengthTransferred = 0;
    
    hr = m_FxDevice->CreateRequest( NULL, //pCallbackInterface
                                    NULL, //pParentObject
                                    &pWdfRequest);

    if (SUCCEEDED(hr))
    {
        m_FxDevice->GetDriver(&FxDriver);

        hr = FxDriver->CreatePreallocatedWdfMemory( Buffer,
                                                    BufferLength,
                                                    NULL, //pCallbackInterface
                                                    pWdfRequest, //pParetObject
                                                    &FxMemory );
    }

    if (SUCCEEDED(hr))
    {
        hr = m_pIUsbTargetDevice->FormatRequestForControlTransfer( pWdfRequest,
                                                                   SetupPacket,
                                                                   FxMemory,
                                                                   NULL); //TransferOffset
    }                                                          
                        
    if (SUCCEEDED(hr))
    {
        hr = pWdfRequest->Send( m_pIUsbTargetDevice,
                                WDF_REQUEST_SEND_OPTION_SYNCHRONOUS,
                                0); //Timeout
    }

    if (SUCCEEDED(hr))
    {
        pWdfRequest->GetCompletionParams(&FxComplParams);

        hr = FxComplParams->GetCompletionStatus();
    }

    if (SUCCEEDED(hr))
    {
        HRESULT hrQI = FxComplParams->QueryInterface(IID_PPV_ARGS(&FxUsbComplParams));
        WUDF_TEST_DRIVER_ASSERT(SUCCEEDED(hrQI));

        WUDF_TEST_DRIVER_ASSERT( WdfUsbRequestTypeDeviceControlTransfer == 
                            FxUsbComplParams->GetCompletedUsbRequestType() );

        FxUsbComplParams->GetDeviceControlTransferParameters( NULL,
                                                             LengthTransferred,
                                                             NULL,
                                                             NULL );
    }

    SAFE_RELEASE(FxUsbComplParams);
    SAFE_RELEASE(FxComplParams);
    SAFE_RELEASE(FxMemory);

    pWdfRequest->DeleteWdfObject();        
    SAFE_RELEASE(pWdfRequest);

    SAFE_RELEASE(FxDriver);

    return hr;
}

WDF_IO_TARGET_STATE
CMyDevice::GetTargetState(
    IWDFIoTarget * pTarget
    )
{
    IWDFIoTargetStateManagement * pSateMgmt = NULL;
    WDF_IO_TARGET_STATE state;

    HRESULT hrQI = pTarget->QueryInterface(IID_PPV_ARGS(&pSateMgmt));
    WUDF_TEST_DRIVER_ASSERT((SUCCEEDED(hrQI) && pSateMgmt));
    
    state = pSateMgmt->GetState();

    SAFE_RELEASE(pSateMgmt);
    
    return state;
}
    
HRESULT
CMyDevice::InitiatePendingRead(
    VOID
    )
/*++
 
  Routine Description:

    This routine starts up a cycling read on the interrupt pipe.  As each 
    read completes it will start up the next one.

  Arguments:
    
    None

  Return Value:

    Status

--*/
{
    HRESULT hr = S_OK;
    IWDFIoRequest * FxRequest = NULL;
    IWDFMemory * FxMemory = NULL;
    IWDFDriver * FxDriver = NULL;
    IRequestCallbackRequestCompletion * FxComplCallback = NULL;

    hr = m_FxDevice->CreateRequest(NULL, NULL, &FxRequest);

    if (SUCCEEDED(hr))
    {
        m_FxDevice->GetDriver(&FxDriver);
        
        hr = FxDriver->CreatePreallocatedWdfMemory( (PBYTE) &m_SwitchStateBuffer,
                                                    sizeof(m_SwitchStateBuffer),
                                                    NULL, //pCallbackInterface
                                                    FxRequest, //pParetObject
                                                    &FxMemory );        
    }

    if (SUCCEEDED(hr))
    {
        hr = m_pIUsbInterruptPipe->FormatRequestForRead(FxRequest,
                                                        NULL, //pFile - IoTarget would apply its file
                                                        FxMemory, 
                                                        NULL, //Memory offset
                                                        NULL);  //Device offset                                                                                   
    }

    if (SUCCEEDED(hr))
    {
        HRESULT hrQI = this->QueryInterface(IID_PPV_ARGS(&FxComplCallback));
        WUDF_TEST_DRIVER_ASSERT((SUCCEEDED(hrQI) && FxComplCallback));
        
        FxRequest->SetCompletionCallback(FxComplCallback, NULL);

        hr = FxRequest->Send(m_pIUsbInterruptPipe, 0, 0);
    }

    if (FAILED(hr) && FxRequest)
    {
        m_InterruptReadProblem = hr;

        //
        // We won't get a completion, so satisfy app request with failure now
        //
        
        ServiceSwitchChangeQueue(m_SwitchState, 
                                 hr,
                                 NULL);
        
        FxRequest->DeleteWdfObject();
    }


    SAFE_RELEASE(FxRequest);
    SAFE_RELEASE(FxMemory);
    SAFE_RELEASE(FxDriver);
    SAFE_RELEASE(FxComplCallback);

    return hr;
}

VOID
CMyDevice::OnCompletion(
    IWDFIoRequest*                 FxRequest,
    IWDFIoTarget*                  pIoTarget,
    IWDFRequestCompletionParams*   pParams,
    PVOID                          pContext
    )
{
    UNREFERENCED_PARAMETER(pIoTarget);
    UNREFERENCED_PARAMETER(pContext);

    IWDFUsbRequestCompletionParams * pUsbComplParams = NULL;
    IWDFMemory * FxMemory = NULL;
    SIZE_T bytesRead = 0;
    HRESULT hrCompletion = pParams->GetCompletionStatus();

    TraceEvents(TRACE_LEVEL_INFORMATION, 
                TEST_TRACE_DEVICE, 
                "%!FUNC! Pending read completed with %!hresult!",
                hrCompletion
                );

    if (FAILED(hrCompletion))
    {
        m_InterruptReadProblem = hrCompletion;
    }
    else
    {
        //
        // Get the switch state
        //
        
        HRESULT hrQI = pParams->QueryInterface(IID_PPV_ARGS(&pUsbComplParams));
        WUDF_TEST_DRIVER_ASSERT( (SUCCEEDED(hrQI) && pUsbComplParams) );

        pUsbComplParams->GetPipeReadParameters(&FxMemory, &bytesRead, NULL);
        WUDF_TEST_DRIVER_ASSERT(bytesRead == sizeof(m_SwitchState));

        PVOID pBuff = FxMemory->GetDataBuffer(NULL);

        CopyMemory(&m_SwitchState, pBuff, sizeof(m_SwitchState));
    }
        
    FxRequest->DeleteWdfObject();

    //
    // Satisfy application request for switch change notification
    //
    
    ServiceSwitchChangeQueue(m_SwitchState, 
                             hrCompletion,
                             NULL);

    //
    // Re-initiate pending read if I/O Target is not stopped/removed
    //
    
    if (WdfIoTargetStarted == GetTargetState(m_pIUsbInterruptPipe))
    {
        InitiatePendingRead();
    }

    SAFE_RELEASE(pUsbComplParams);
    SAFE_RELEASE(FxMemory);
}

VOID
CMyDevice::ServiceSwitchChangeQueue(
    __in SWITCH_STATE NewState,
    __in HRESULT CompletionStatus,
    __in_opt IWDFFile *SpecificFile
    )
/*++
 
  Routine Description:

    This method processes switch-state change notification requests as 
    part of reading the OSR device's interrupt pipe.  As each read completes
    this pulls all pending I/O off the switch change queue and completes
    each request with the current switch state.

  Arguments:

    NewState - the state of the switches

    CompletionStatus - all pending operations are completed with this status.

    SpecificFile - if provided only requests for this file object will get
                   completed.

  Return Value:

    None

--*/
{
    IWDFIoRequest *fxRequest;

    HRESULT enumHr = S_OK;

    do 
    {
        HRESULT hr;

        //
        // Get the next request.
        //

        if (NULL != SpecificFile)
        {
            enumHr = m_SwitchChangeQueue->RetrieveNextRequestByFileObject(
                                            SpecificFile,
                                            &fxRequest
                                            );
        }
        else
        {
            enumHr = m_SwitchChangeQueue->RetrieveNextRequest(&fxRequest);
        }

        //
        // if we got one then complete it.
        //

        if (SUCCEEDED(enumHr)) 
        {
            if (SUCCEEDED(CompletionStatus)) 
            {
                IWDFMemory *fxMemory;

                //
                // First copy the result to the request buffer.
                //

                fxRequest->GetOutputMemory(&fxMemory );

                hr = fxMemory->CopyFromBuffer(0, 
                                              &NewState, 
                                              sizeof(SWITCH_STATE));
                fxMemory->Release();
            }
            else 
            {
                hr = CompletionStatus;
            }

            //
            // Complete the request with the status of the copy (or the completion
            // status if that was an error).
            //

            if (SUCCEEDED(hr)) 
            {
                fxRequest->CompleteWithInformation(hr, sizeof(SWITCH_STATE));
            }
            else
            {
                fxRequest->Complete(hr);
            }

            fxRequest->Release();            
        }
    }
    while (SUCCEEDED(enumHr));
}




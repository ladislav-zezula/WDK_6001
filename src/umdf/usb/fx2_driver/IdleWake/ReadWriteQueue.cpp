/*++

Copyright (c) Microsoft Corporation, All Rights Reserved

Module Name:

    queue.cpp

Abstract:

    This file implements the I/O queue interface and performs
    the read/write/ioctl operations.

Environment:

    Windows User-Mode Driver Framework (WUDF)

--*/

#include "internal.h"
#include "ReadWriteQueue.tmh"

VOID
CMyReadWriteQueue::OnCompletion(
    IWDFIoRequest*                 pWdfRequest,
    IWDFIoTarget*                  pIoTarget,
    IWDFRequestCompletionParams*   pParams,
    PVOID                          pContext
    )
{
    UNREFERENCED_PARAMETER(pIoTarget);
    UNREFERENCED_PARAMETER(pContext);
    
    pWdfRequest->CompleteWithInformation(
        pParams->GetCompletionStatus(),
        pParams->GetInformation()
        );
}

void
CMyReadWriteQueue::ForwardFormattedRequest(
    __in IWDFIoRequest*                         pRequest,
    __in IWDFIoTarget*                          pIoTarget
    )
{
    //
    //First set the completion callback
    //

    IRequestCallbackRequestCompletion * pCompletionCallback = NULL;    
    HRESULT hrQI = this->QueryInterface(IID_PPV_ARGS(&pCompletionCallback));
    WUDF_TEST_DRIVER_ASSERT(SUCCEEDED(hrQI) && (NULL != pCompletionCallback));
    
    pRequest->SetCompletionCallback(
        pCompletionCallback,
        NULL
        );

    pCompletionCallback->Release();
    pCompletionCallback = NULL;

    //
    //Send down the request
    //
    
    HRESULT hrSend = S_OK;
    hrSend = pRequest->Send(pIoTarget, 
                            0,  //flags
                            0); //timeout
    
    if (FAILED(hrSend))
    {
        pRequest->CompleteWithInformation(hrSend, 0);
    }

    return;
}


CMyReadWriteQueue::CMyReadWriteQueue(
    __in PCMyDevice Device
    ) : 
    CMyQueue(Device)
{
}

//
// Queue destructor.
// Free up the buffer, wait for thread to terminate and 
//

CMyReadWriteQueue::~CMyReadWriteQueue(
    VOID
    )
/*++

Routine Description:


    IUnknown implementation of Release

Aruments:


Return Value:

    ULONG (reference count after Release)

--*/
{
    TraceEvents(TRACE_LEVEL_INFORMATION, 
                TEST_TRACE_QUEUE, 
                "%!FUNC! Entry"
                );

}


HRESULT
STDMETHODCALLTYPE
CMyReadWriteQueue::QueryInterface(
    __in REFIID InterfaceId,
    __deref_out PVOID *Object
    )
/*++

Routine Description:


    Query Interface

Aruments:
    
    Follows COM specifications

Return Value:

    HRESULT indicatin success or failure

--*/
{
    HRESULT hr;


    if (IsEqualIID(InterfaceId, __uuidof(IQueueCallbackWrite))) 
    {
        hr = S_OK;
        *Object = QueryIQueueCallbackWrite(); 
    } 
    else if (IsEqualIID(InterfaceId, __uuidof(IQueueCallbackRead))) 
    {
        hr = S_OK;
        *Object = QueryIQueueCallbackRead(); 
    } 
    else if (IsEqualIID(InterfaceId, __uuidof(IRequestCallbackRequestCompletion))) 
    {
        hr = S_OK;
        *Object = QueryIRequestCallbackRequestCompletion(); 
    }    
    else if (IsEqualIID(InterfaceId, __uuidof(IQueueCallbackIoStop))) 
    {
        hr = S_OK;
        *Object = QueryIQueueCallbackIoStop(); 
    }    
    else 
    {
        hr = CMyQueue::QueryInterface(InterfaceId, Object);
    }

    return hr;
}

//
// Initialize 
//

HRESULT 
CMyReadWriteQueue::CreateInstance(
    __in PCMyDevice Device,
    __out PCMyReadWriteQueue *Queue
    )
/*++

Routine Description:


    CreateInstance creates an instance of the queue object.

Aruments:
    
    ppUkwn - OUT parameter is an IUnknown interface to the queue object

Return Value:

    HRESULT indicatin success or failure

--*/
{
    PCMyReadWriteQueue queue;
    HRESULT hr = S_OK;

    queue = new CMyReadWriteQueue(Device);

    if (NULL == queue)
    {
        hr = E_OUTOFMEMORY;
    }

    //
    // Call the queue callback object to initialize itself.  This will create 
    // its partner queue framework object.
    //

    if (SUCCEEDED(hr))
    {        
        hr = queue->Initialize();
    }

    if (SUCCEEDED(hr)) 
    {
        *Queue = queue;
    }
    else
    {
        SAFE_RELEASE(queue);
    }

    return hr;
}

HRESULT
CMyReadWriteQueue::Initialize(
    )
{
    HRESULT hr;

    //
    // First initialize the base class.  This will create the partner FxIoQueue
    // object and setup automatic forwarding of I/O controls.
    //
    
    //
    // We are above the power policy owner in the stack (winusb.sys) and so we 
    // should not use power-managed queues
    //
    hr = __super::Initialize(WdfIoQueueDispatchParallel, 
                             true, 
                             false // Not power managed
                             );

    //
    // return the status.
    //

    return hr;
}

STDMETHODIMP_ (void)
CMyReadWriteQueue::OnWrite(
        /* [in] */ IWDFIoQueue *pWdfQueue,
        /* [in] */ IWDFIoRequest *pWdfRequest,
        /* [in] */ SIZE_T BytesToWrite
         )
/*++

Routine Description:


    Write dispatch routine
    IQueueCallbackWrite

Aruments:
    
    pWdfQueue - Framework Queue instance
    pWdfRequest - Framework Request  instance
    BytesToWrite - Lenth of bytes in the write buffer

    Allocate and copy data to local buffer
Return Value:

    VOID

--*/
{
    UNREFERENCED_PARAMETER(pWdfQueue);
    
    TraceEvents(TRACE_LEVEL_INFORMATION,
                TEST_TRACE_QUEUE,
                "%!FUNC!: Queue %p Request %p BytesToTransfer %d\n",
                this,
                pWdfRequest,
                (ULONG)(ULONG_PTR)BytesToWrite
                );

    HRESULT hr = S_OK;
    IWDFMemory * pInputMemory = NULL;
    IWDFUsbTargetPipe * pOutputPipe = m_Device->GetOutputPipe();

    pWdfRequest->GetInputMemory(&pInputMemory);
    
    hr = pOutputPipe->FormatRequestForWrite(
                                pWdfRequest,
                                NULL, //pFile
                                pInputMemory,
                                NULL, //Memory offset
                                NULL  //DeviceOffset
                                );

    if (FAILED(hr))
    {
        pWdfRequest->Complete(hr);
    }
    else
    {
        ForwardFormattedRequest(pWdfRequest, pOutputPipe);
    }

    SAFE_RELEASE(pInputMemory);
    
    return;
}

STDMETHODIMP_ (void)
CMyReadWriteQueue::OnRead(
        /* [in] */ IWDFIoQueue *pWdfQueue,
        /* [in] */ IWDFIoRequest *pWdfRequest,
        /* [in] */ SIZE_T BytesToRead
         )
/*++

Routine Description:


    Read dispatch routine
    IQueueCallbackRead

Aruments:
    
    pWdfQueue - Framework Queue instance
    pWdfRequest - Framework Request  instance
    BytesToRead - Lenth of bytes in the read buffer

    Copy available data into the read buffer
Return Value:

    VOID

--*/
{
    UNREFERENCED_PARAMETER(pWdfQueue);
    
    TraceEvents(TRACE_LEVEL_INFORMATION,
                TEST_TRACE_QUEUE,
                "%!FUNC!: Queue %p Request %p BytesToTransfer %d\n",
                this,
                pWdfRequest,
                (ULONG)(ULONG_PTR)BytesToRead
                );

    HRESULT hr = S_OK;
    IWDFMemory * pOutputMemory = NULL;

    pWdfRequest->GetOutputMemory(&pOutputMemory);
    
    hr = m_Device->GetInputPipe()->FormatRequestForRead(
                                pWdfRequest,
                                NULL, //pFile
                                pOutputMemory,
                                NULL, //Memory offset
                                NULL  //DeviceOffset
                                );

    if (FAILED(hr))
    {
        pWdfRequest->Complete(hr);
    }
    else
    {
        ForwardFormattedRequest(pWdfRequest, m_Device->GetInputPipe());
    }

    SAFE_RELEASE(pOutputMemory);
    
    return;
}

STDMETHODIMP_ (void)
CMyReadWriteQueue::OnIoStop(
    __in IWDFIoQueue *   pWdfQueue,
    __in IWDFIoRequest * pWdfRequest,
    __in ULONG           ActionFlags
    )
{
    UNREFERENCED_PARAMETER(pWdfQueue);

    //
    // We don't expect the the flag WdfRequestStopRequestCancelable because
    // we never marked the requests cancelable
    //
    // If the request is cancelable, driver will need to unmark it before
    // acknowledging it (more about acknowledging below)
    //
    // If the request was sent to I/O target, it isn't possible for it to be
    // marked cancelable because such request can not be sent to I/O target
    //
    WUDF_TEST_DRIVER_ASSERT(!(ActionFlags & WdfRequestStopRequestCancelable));
    
    //
    // Because of device level locking we know that if our driver
    // owns the request and we get here, our OnRead/OnWrite callback
    // has returned and the request has been sent to I/O target
    //

    if (ActionFlags == WdfRequestStopActionSuspend )
    {
        //
        // UMDF does not support an equivalent to WdfRequestStopAcknowledge.
        //
        // Cancel the request so that the power management operation can continue.
        //
        // NOTE: if cancelling the request would have an adverse affect and if the 
        //       requests are expected to complete very quickly then leaving the 
        //       request running may be a better option.
        //
        
        pWdfRequest->CancelSentRequest();
    }
    else if(ActionFlags == WdfRequestStopActionPurge)
    {
        //
        // Cancel the sent request since we are asked to purge the request
        //
        
        pWdfRequest->CancelSentRequest();
    }

    return;        
}


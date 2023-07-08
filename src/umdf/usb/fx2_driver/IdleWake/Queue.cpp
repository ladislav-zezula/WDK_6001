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
#include "queue.tmh"

CMyQueue::CMyQueue(
    __in PCMyDevice Device
    ) : 
    m_FxQueue(NULL),
    m_Device(Device),
    m_QueueStopEvent(NULL)
{
}

//
// Queue destructor.
// Free up the buffer, wait for thread to terminate and 
//

CMyQueue::~CMyQueue(
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

    if (NULL != m_QueueStopEvent)
    {
        CloseHandle(m_QueueStopEvent);
    }
}


HRESULT
STDMETHODCALLTYPE
CMyQueue::QueryInterface(
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

    if(IsEqualIID(InterfaceId, __uuidof(IQueueCallbackStateChange))) 
    {    
        *Object = QueryIQueueCallbackStateChange();
        hr = S_OK;  
    }
    else
    {
        hr = CUnknown::QueryInterface(InterfaceId, Object);
    }

    return hr;
}

//
// Initialize 
//

HRESULT
CMyQueue::Initialize(
    __in WDF_IO_QUEUE_DISPATCH_TYPE DispatchType,
    __in bool Default,
    __in bool PowerManaged
    )
{
    IWDFIoQueue *fxQueue = NULL;
    HRESULT hr = S_OK;

    m_QueueStopEvent = CreateEvent(
                                NULL,  //lpEventAttributes
                                TRUE,  //bManualReset
                                FALSE, //bInitialState
                                NULL   //lpName
                                );
        
    if (NULL == m_QueueStopEvent)
    {
        DWORD error = GetLastError();
        
        TraceEvents(TRACE_LEVEL_ERROR, 
                    TEST_TRACE_DEVICE, 
                    "%!FUNC! CreateEvent failed, error: %d",
                    error
                    );

        hr = HRESULT_FROM_WIN32(error);        
    }
    
    //
    // Create the I/O Queue object.
    //

    if (SUCCEEDED(hr))
    {
        IUnknown *callback = QueryIUnknown();

        hr = m_Device->GetFxDevice()->CreateIoQueue(
                                        callback,
                                        Default,
                                        DispatchType,
                                        PowerManaged,
                                        FALSE,
                                        &fxQueue
                                        );
        callback->Release();
    }

    if (SUCCEEDED(hr))
    {
        m_FxQueue = fxQueue;

        //
        // Release the creation reference on the queue.  This object will be 
        // destroyed before the queue so we don't need to have a reference out 
        // on it.
        //

        fxQueue->Release();
    }

    return hr;
}

HRESULT
CMyQueue::Configure(
    VOID
    )
{
    return S_OK;
}

VOID
CMyQueue::StopFxQueueSynchronously(
    )
/*++

Routine Description:

    This routine stops the paired fx queue synchronously
    
    The UMDF DDI IWDFIoQueue::StopSynchronously has a bug and hence
    does not work correctly

    This is the reason we implement synchronous stop in terms of asynchronous
    stop and wait for an event that the asyncrhonous callback (OnStateChange)
    sets
    
--*/
{
    IQueueCallbackStateChange * queueStateChangeCallback;
    queueStateChangeCallback = this->QueryIQueueCallbackStateChange();

    m_FxQueue->Stop(queueStateChangeCallback);
    WaitForSingleObject(m_QueueStopEvent, INFINITE);

    SAFE_RELEASE(queueStateChangeCallback);
}

void 
CMyQueue::OnStateChange(
    __in IWDFIoQueue *      pWdfQueue,
    __in WDF_IO_QUEUE_STATE QueueState
    )
/*++

Routine Description:

    This routine is invoked to notify driver about queue state change.
    We use it to get completion of async operation Stop for our
    ReadWrite or the Control Queue

Arguments:

    pWdfQueue  : Queue whose state changed
    QueueState : New queue state

Return Value:

    HRESULT 

--*/
{
    UNREFERENCED_PARAMETER(pWdfQueue);

    //
    // Check if the queue is stopped (i.e. WdfIoQueueDispatchRequests is not set)
    //
    // All other flags can be set even when queue has transitioned to stopped state.
    // Queue can accept requests, may have queued requests and may have outstanding
    // Requests to the driver that driver acknoledges during Stop
    //
    if (0 == (QueueState & WdfIoQueueDispatchRequests))
    {
        SetEvent(m_QueueStopEvent);
    }
}





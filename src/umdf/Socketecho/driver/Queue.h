/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    queue.h

Abstract:

    This is the header file for queue callback methods class.

Environment:

    user mode only

Revision History:

--*/

#pragma once

//
// Queue Callback Object.
//

class ATL_NO_VTABLE CMyQueue : 
    public CComObjectRootEx<CComMultiThreadModel>,
    public IQueueCallbackCreate,
    public IQueueCallbackRead, 
    public IQueueCallbackWrite,
    public IRequestCallbackRequestCompletion
    
{
public:

DECLARE_NOT_AGGREGATABLE(CMyQueue)

BEGIN_COM_MAP(CMyQueue)
    COM_INTERFACE_ENTRY(IQueueCallbackCreate)
    COM_INTERFACE_ENTRY(IQueueCallbackRead)
    COM_INTERFACE_ENTRY(IQueueCallbackWrite)
    COM_INTERFACE_ENTRY(IRequestCallbackRequestCompletion)
END_COM_MAP()

public:
    //IQueueCallbackRead
    STDMETHOD_(void,OnRead)(
	    			__in IWDFIoQueue* pWdfQueue,
	    			__in IWDFIoRequest* pWdfRequest,
	    			__in SIZE_T NumOfBytesToRead);
    //IQueueCallbackWrite
    STDMETHOD_(void,OnWrite)(
    				__in IWDFIoQueue* pWdfQueue,
    				__in IWDFIoRequest* pWdfRequest,
    				__in SIZE_T NumOfBytesToWrite);
    //IQueueCallbackCreate
    STDMETHOD_(void,OnCreateFile)(
    				__in IWDFIoQueue* pWdfQueue,
    				__in IWDFIoRequest* pWDFRequest,
    				__in IWDFFile* pWdfFileObject);
   // IRequestCallbackRequestCompletion
   STDMETHOD_(void,OnCompletion)(
   				__in IWDFIoRequest* pWdfRequest,
   				__in IWDFIoTarget* pTarget,
   				__in IWDFRequestCompletionParams* pCompletionParams,
   				__in void* pContext);

public:
    CMyQueue();
    ~CMyQueue();

    HRESULT Initialize(__in CMyDevice * Device);

    HRESULT
    Configure(
        );
    
private:
    CComPtr<IWDFIoQueue> m_FxQueue;

    //
    // Unreferenced pointer to the parent device.
    //

    CMyDevice * m_Device;

    VOID SendRequestToFileTarget( __in IWDFIoRequest* pWdfRequest);    
   
	
};


typedef struct _FileContext
{
	CConnection *pConnection ;
	
	CComPtr<IWDFIoTarget> pFileTarget;

}FileContext;
	


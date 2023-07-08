//
//  Windows Server (Printing) Driver Development Kit Samples.
//
//  Sample Print Provider template.
//
//  Copyright (c) 1990 - 2005 Microsoft Corporation.
//  All Rights Reserved.
//
//
//  This source code is intended only as a supplement to Microsoft
//  Development Tools and/or on-line documentation.  See these other
//  materials for detailed information regarding Microsoft code samples.
// 
//  THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
//  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//  PARTICULAR PURPOSE.
//

#include "precomp.h"
#pragma hdrstop

#include "acallback.hpp"
#include "notifydata.hpp"

//
// Default Constructor
//

CPrintOEMAsyncNotifyCallback::
CPrintOEMAsyncNotifyCallback(
    HANDLE      unregisterEvent
    ):
    m_cRef(1),
    m_unregisterEvent(unregisterEvent)
{
    m_hValid = (m_unregisterEvent != NULL) ? S_OK : E_FAIL;
}

//
// Destructor
//
CPrintOEMAsyncNotifyCallback::
~CPrintOEMAsyncNotifyCallback(
    )
{
    //
    // If this instance of the object is being deleted, then the reference 
    // count should be zero.
    //
    assert(0 == m_cRef);
}

//
// Validates object state
//
HRESULT
CPrintOEMAsyncNotifyCallback::
IsValid(
    VOID
    ) const
{
    return m_hValid;
}

//
// IUnknown Method
//
STDMETHODIMP
CPrintOEMAsyncNotifyCallback::
QueryInterface(
    __in    REFIID      riid,
    __out   VOID**      ppv
    )
{
    HRESULT hrResult = E_POINTER;

    if (ppv)
    {
        hrResult = E_NOINTERFACE;

        *ppv = NULL;

        if (riid == IID_IPrintAsyncNotifyCallback || 
            riid == IID_IUnknown)
        {
            *ppv = reinterpret_cast<VOID *>(this);
            hrResult = S_OK;
        }
    }

    if (SUCCEEDED(hrResult))
    {
        reinterpret_cast<IUnknown *>(*ppv)->AddRef();
    }

    return hrResult;
}

//
// IUnknown Method
//
STDMETHODIMP_(ULONG)
CPrintOEMAsyncNotifyCallback::
AddRef(
    VOID
    )
{
    return InterlockedIncrement(&m_cRef);
}

//
// IUnknown Method
//
STDMETHODIMP_(ULONG)
CPrintOEMAsyncNotifyCallback::
Release(
    VOID
    )
{
    ULONG cRef = InterlockedDecrement(&m_cRef);

    if (cRef == 0)
    {
        delete this;
        return 0;
    }
    return cRef;
}

//
// OnEventNotify is the notification method that gets called.
//
STDMETHODIMP
CPrintOEMAsyncNotifyCallback::
OnEventNotify(
    __in_opt IPrintAsyncNotifyChannel*       pIAsynchNotifyChannel,
    __in     IPrintAsyncNotifyDataObject*    pNotification
    )
{
    HRESULT                     hrResult            = E_FAIL;
    EOEMDataSchema*             pAction             = NULL;
    ULONG                       notificationLength  = 0;
    PrintAsyncNotificationType* notificationType    = NULL;
    
    if (pNotification)
    {
        if (SUCCEEDED(hrResult = pNotification->AcquireData(reinterpret_cast<BYTE**>(&pAction), 
                                                            &notificationLength, 
                                                            &notificationType)))
        {
            if (*notificationType == NOTIFICATION_RELEASE)
            {
                MessageBox(NULL, L"Printer deleted", L"Unregister...", MB_OK);
                SetEvent(m_unregisterEvent);
            }
            else if (pAction)
            {
                switch (*pAction)
                {
                    case SERVER_START_DOC:
                    {
                        MessageBox(NULL, L"Start Doc", L"Server notification", MB_OK);
                        break;
                    }
                    case SERVER_END_DOC:
                    {
                        MessageBox(NULL,  L"End Doc", L"Server notification", MB_OK);
                        break;
                    }
                    case SERVER_END_DIALOG:
                    {
                        MessageBox(NULL,  L"End dialog", L"Server notification", MB_OK);
                        break;
                    }
                    default:
                    {
                        MessageBox(NULL,  L"Unknown data format", L"Server notification", MB_OK);
                        break;
                    }
                }
            }

            pNotification->ReleaseData();
        }
    }

    if (pIAsynchNotifyChannel)
    {
        ReplyOnEventNotify(pIAsynchNotifyChannel);              
    }
 
    return hrResult;
}

//
// ChannelClosed
//
HRESULT
CPrintOEMAsyncNotifyCallback::
ChannelClosed(
    __in_opt IPrintAsyncNotifyChannel*       pIAsynchNotifyChannel,
    __in     IPrintAsyncNotifyDataObject*    pNotification
    )
{
    HRESULT                     hrResult            = E_FAIL;
    EOEMDataSchema*             pAction             = NULL;
    ULONG                       notificationLength  = 0;
    PrintAsyncNotificationType* notificationType    = NULL;
    
    if (pIAsynchNotifyChannel)
    {
        hrResult = S_OK;

        if (pNotification)
        {
            if (SUCCEEDED(hrResult = pNotification->AcquireData(reinterpret_cast<BYTE**>(&pAction), 
                                                                &notificationLength, 
                                                                &notificationType)))
            {
                if (pAction && *pAction == SERVER_END_DIALOG)
                {
                    MessageBox(NULL,  L"End dialog", L"Server notification", MB_OK);                    
                }
                else
                {
                    MessageBox(NULL,  L"Unknown data format", L"Server notification", MB_OK);
                }

                pNotification->ReleaseData();
            }
        }
    }

    return hrResult;
}

//
// ReplyOnEventNotify
// 
HRESULT
CPrintOEMAsyncNotifyCallback::
ReplyOnEventNotify(
    __in IPrintAsyncNotifyChannel*   pIAsynchNotifyChannel
    )
{
    HRESULT                         hrResult           = E_FAIL;
    CPrintOEMAsyncNotifyDataObject* pINotifyDataObject = NULL;
    EOEMDataSchema                  clientResponse     = CLIENT_ACKNOWLEDGED;
    
    if (pIAsynchNotifyChannel)
    {    
        pINotifyDataObject = new CPrintOEMAsyncNotifyDataObject(reinterpret_cast<BYTE*>(&clientResponse), 
                                                                sizeof(EOEMDataSchema), 
                                                                const_cast<GUID*>(&SAMPLE_NOTIFICATION_UI));

        if (SUCCEEDED(hrResult = pINotifyDataObject ? pINotifyDataObject->IsValid() : E_OUTOFMEMORY))
        {
            hrResult = pIAsynchNotifyChannel->CloseChannel(pINotifyDataObject);
        }

        pIAsynchNotifyChannel->Release();           
    }

    return hrResult;
}




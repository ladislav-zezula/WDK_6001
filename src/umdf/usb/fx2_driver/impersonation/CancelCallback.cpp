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
#include "cancelCallback.tmh"

CCancelCallback::CCancelCallback(
    VOID
    ) : 
    m_Canceled(false),
    m_Event(NULL)
{
}

CCancelCallback::~CCancelCallback(
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
    if (m_Event != NULL)
    {
        CloseHandle(m_Event);
    }

    return;
}

PCCancelCallback
CCancelCallback::CreateAndInitialize(
    VOID
    )
/*++
 
  Routine Description:

    This is the factory method for CCancelCallback.  It allocates the 
    object and initializes it.

  Arguments:

    None

  Return Value:

    A pointer to a CCancelCallback object or NULL
    if there was insufficient memory to allocate one.

--*/
{
    PCCancelCallback callback = new CCancelCallback();

    if (callback != NULL)
    {
        callback->m_Event = CreateEvent(NULL, 
                                        TRUE, 
                                        FALSE, 
                                        NULL);

        if (callback->m_Event == NULL)
        {
            delete callback;
            callback = NULL;
        }
    }

    return callback;
}

HRESULT
STDMETHODCALLTYPE
CCancelCallback::QueryInterface(
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

    if (InterfaceId == __uuidof(IRequestCallbackCancel))
    {
        AddRef();
        *Object = static_cast<IRequestCallbackCancel *>(this);
        hr = S_OK;
    }
    else
    {
        hr = CUnknown::QueryInterface(InterfaceId, Object);
    }

    return hr;
}

VOID
CCancelCallback::OnCancel(
    __in IWDFIoRequest * /* Request */
    )
{
    m_Canceled = true;
    SetEvent(m_Event);
}


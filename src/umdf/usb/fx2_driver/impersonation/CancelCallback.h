/*++

Copyright (c) Microsoft Corporation, All Rights Reserved

Module Name:

    CallbackCancel.h

Abstract:

    This file defines the cancel callback interface.  This is used to 
    register for cancel notifications while synchronously handling
    I/O requests.

Environment:

    Windows User-Mode Driver Framework (WUDF)

--*/

#pragma once

//
// Queue Callback Object.
//

class CCancelCallback : 
    public CUnknown,
    public IRequestCallbackCancel
{
protected:    

    //
    // Has the request been cancelled yet?
    //

    bool m_Canceled;

    //
    // Event handle on which one can wait for
    // cancellation.
    //

    HANDLE m_Event;

public:

    CCancelCallback(
        VOID
        );

    virtual ~CCancelCallback();

public:

    //
    // Public methods.
    //

    bool 
    IsCanceled(
        VOID
        )
    {
        return m_Canceled;
    }

    bool
    WaitForEvent(
        __in ULONG Timeout
        )
    {
        return (WaitForSingleObject(m_Event, Timeout) == NO_ERROR);
    }


    //
    // Public interface query methods.
    //

    IRequestCallbackCancel* 
    QueryIRequestCallbackCancel(
        VOID
        )
    {
        AddRef();
        return static_cast<IRequestCallbackCancel *>(this);
    }

    //
    // Public static methods.
    //

    static
    PCCancelCallback 
    CreateAndInitialize(
        VOID
        );

    
    //
    // IUnknown
    //

    STDMETHOD_(ULONG,AddRef) (VOID) {return __super::AddRef();}

    STDMETHOD_(ULONG,Release) (VOID) {return __super::Release();}

    STDMETHOD_(HRESULT, QueryInterface)(
        __in REFIID InterfaceId, 
        __deref_out PVOID *Object
        );

    //
    // IRequestCallbackCancel.
    //

    VOID
    STDMETHODCALLTYPE
    OnCancel(
        __in IWDFIoRequest *Request
        );

};


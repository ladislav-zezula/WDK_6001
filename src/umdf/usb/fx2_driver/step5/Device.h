/*++

Copyright (C) Microsoft Corporation, All Rights Reserved

Module Name:

    Device.h

Abstract:

    This module contains the type definitions for the UMDF Skeleton sample
    driver's device callback class.

Environment:

    Windows User-Mode Driver Framework (WUDF)

--*/

#pragma once
#include "internal.h"

#define ENDPOINT_TIMEOUT        10000
#define NUM_OSRUSB_ENDPOINTS    3

//
// Define the vendor commands supported by our device
//
#define USBFX2LK_SET_BARGRAPH_DISPLAY       0xD8

//
// Class for the iotrace driver.
//

class CMyDevice : 
    public CUnknown,
    public IPnpCallbackHardware, 
    public IRequestCallbackRequestCompletion    
{

//
// Private data members.
//
private:
    //
    // Weak reference to framework device
    //    
    IWDFDevice *m_FxDevice;

    // 
    // Weak reference to the control queue
    //
    PCMyReadWriteQueue      m_ReadWriteQueue;

    // 
    // Weak reference to the control queue
    //
    PCMyControlQueue        m_ControlQueue;

    //
    // USB Device I/O Target
    //
    IWDFUsbTargetDevice *   m_pIUsbTargetDevice;

    //
    // USB Interface
    //
    IWDFUsbInterface *      m_pIUsbInterface;

    //
    // USB Input pipe for Reads
    //
    IWDFUsbTargetPipe *     m_pIUsbInputPipe;

    //
    // USB Output pipe for writes
    //
    IWDFUsbTargetPipe *     m_pIUsbOutputPipe;

    //
    // USB interrupt pipe
    //
    IWDFUsbTargetPipe *     m_pIUsbInterruptPipe;

    //
    // Device Speed (Low, Full, High)
    //
    UCHAR                   m_Speed;    

    //
    // Current switch state
    //
    SWITCH_STATE            m_SwitchState;

    //
    // If reads stopped because of a transient problem, the error status
    // is stored here.
    //

    HRESULT                 m_InterruptReadProblem;
    
    //
    // Switch state buffer - this might hold the transient value
    // m_SwitchState holds stable value of the switch state
    //
    SWITCH_STATE            m_SwitchStateBuffer;

    //
    // A manual queue to hold requests for changes in the I/O switch state.
    //

    IWDFIoQueue *           m_SwitchChangeQueue;

//
// Private methods.
//

private:

    CMyDevice(
        VOID
        ) :
        m_FxDevice(NULL),
        m_ControlQueue(NULL),            
        m_ReadWriteQueue(NULL),
        m_SwitchChangeQueue(NULL),
        m_pIUsbTargetDevice(NULL),
        m_pIUsbInterface(NULL),
        m_pIUsbInputPipe(NULL),
        m_pIUsbOutputPipe(NULL),
        m_pIUsbInterruptPipe(NULL),
        m_Speed(0),
        m_InterruptReadProblem(S_OK)
    {
    }

    ~CMyDevice(
        );

    HRESULT
    Initialize(
        __in IWDFDriver *FxDriver,
        __in IWDFDeviceInitialize *FxDeviceInit
        );

    //
    // Helper methods
    //

    HRESULT
    CreateUsbIoTargets(
        VOID
        );

    
    HRESULT
    ConfigureUsbPipes(
        );
    
    HRESULT
    SendControlTransferSynchronously(
        __in PWINUSB_SETUP_PACKET SetupPacket,
        __inout_ecount(BufferLength) PBYTE Buffer,
        __in ULONG BufferLength,
        __out PULONG LengthTransferred
        );

    static
    WDF_IO_TARGET_STATE
    GetTargetState(
        IWDFIoTarget * pTarget
        );
    
    HRESULT
    InitiatePendingRead(
        );

    VOID
    ServiceSwitchChangeQueue(
        __in SWITCH_STATE NewState,
        __in HRESULT CompletionStatus,
        __in_opt IWDFFile *SpecificFile
        );

//
// Public methods
//
public:

    //
    // The factory method used to create an instance of this driver.
    //
    
    static
    HRESULT
    CreateInstance(
        __in IWDFDriver *FxDriver,
        __in IWDFDeviceInitialize *FxDeviceInit,
        __out PCMyDevice *Device
        );

    IWDFDevice *
    GetFxDevice(
        VOID
        )
    {
        return m_FxDevice;
    }

    HRESULT
    Configure(
        VOID
        );

    IPnpCallbackHardware *
    QueryIPnpCallbackHardware(
        VOID
        )
    {
        AddRef();
        return static_cast<IPnpCallbackHardware *>(this);
    }

    IRequestCallbackRequestCompletion *
    QueryIRequestCallbackRequestCompletion(
        VOID
        )
    {
        AddRef();
        return static_cast<IRequestCallbackRequestCompletion *>(this);
    }

    HRESULT
    SetBarGraphDisplay(
        __in PBAR_GRAPH_STATE BarGraphState
        );

    //
    //returns a weak reference to input pipe
    //DO NOT release it
    //
    IWDFUsbTargetPipe *
    GetInputPipe(
        )
    {
        return m_pIUsbInputPipe;
    }

    //
    //returns a weak reference to output pipe
    //DO NOT release it
    //
    IWDFUsbTargetPipe *
    GetOutputPipe(
        )
    {
        return m_pIUsbOutputPipe;
    }

    IWDFIoQueue *
    GetSwitchChangeQueue(
        VOID
        )
    {
        return m_SwitchChangeQueue;
    }
    
    PSWITCH_STATE
    GetCurrentSwitchState(
        VOID
        )
    {
        return &m_SwitchState;
    }

//
// COM methods
//
public:

    //
    // IUnknown methods.
    //

    virtual
    ULONG
    STDMETHODCALLTYPE
    AddRef(
        VOID
        )
    {
        return __super::AddRef();
    }

    virtual
    ULONG
    STDMETHODCALLTYPE
    Release(
        VOID
       )
    {
        return __super::Release();
    }

    virtual
    HRESULT
    STDMETHODCALLTYPE
    QueryInterface(
        __in REFIID InterfaceId,
        __deref_out PVOID *Object
        );

    //
    // IPnpCallbackHardware
    //

    virtual
    HRESULT
    STDMETHODCALLTYPE
    OnPrepareHardware(
            __in IWDFDevice *FxDevice
            );

    virtual
    HRESULT
    STDMETHODCALLTYPE
    OnReleaseHardware(
        __in IWDFDevice *FxDevice
        );

    //
    // IRequestCallbackRequestCompletion
    //
    virtual
    void
    STDMETHODCALLTYPE
    OnCompletion(
        IWDFIoRequest*                 FxRequest,
        IWDFIoTarget*                  pIoTarget,
        IWDFRequestCompletionParams*   pParams,
        PVOID                          pContext
        );        
};

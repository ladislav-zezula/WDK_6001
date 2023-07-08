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
#define USBFX2LK_READ_7SEGMENT_DISPLAY      0xD4
#define USBFX2LK_READ_SWITCHES              0xD6
#define USBFX2LK_READ_BARGRAPH_DISPLAY      0xD7
#define USBFX2LK_SET_BARGRAPH_DISPLAY       0xD8
#define USBFX2LK_IS_HIGH_SPEED              0xD9
#define USBFX2LK_REENUMERATE                0xDA
#define USBFX2LK_SET_7SEGMENT_DISPLAY       0xDB

typedef struct {
    UCHAR Segments;
} SEVEN_SEGMENT, *PSEVEN_SEGMENT;

//
// Context for the impersonation callback.
//

typedef struct 
{
    PFILE_PLAYBACK PlaybackInfo;

    HANDLE FileHandle;

    HRESULT Hr;
} PLAYBACK_IMPERSONATION_CONTEXT, *PPLAYBACK_IMPERSONATION_CONTEXT;

//
// Class for the iotrace driver.
//

class CMyDevice : 
    public CUnknown,
    public IPnpCallbackHardware, 
    public IRequestCallbackRequestCompletion, 
    public IImpersonateCallback
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
    // The bus type for this device (used here for
    // illustrative purposes only)
    //

    GUID m_BusTypeGuid;

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
        ZeroMemory(&m_BusTypeGuid, sizeof(m_BusTypeGuid));
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
    GetBusTypeGuid(
        VOID
        );

    HRESULT
    CreateUsbIoTargets(
        VOID
        );

    
    HRESULT
    ConfigureUsbPipes(
        );
    
    HRESULT
    IndicateDeviceReady(
        VOID
        );

    //
    // Helper functions
    //
    
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

    IImpersonateCallback *
    QueryIImpersonateCallback(
        VOID
        )
    {
        AddRef();
        return static_cast<IImpersonateCallback *>(this);
   }

    HRESULT
    GetBarGraphDisplay(
        __in PBAR_GRAPH_STATE BarGraphState
        );

    HRESULT
    SetBarGraphDisplay(
        __in PBAR_GRAPH_STATE BarGraphState
        );

    HRESULT
    GetSevenSegmentDisplay(
        __in PSEVEN_SEGMENT SevenSegment
        );

    HRESULT
    SetSevenSegmentDisplay(
        __in PSEVEN_SEGMENT SevenSegment
        );

    bool
    EncodeSegmentValue(
        __in UCHAR Character,
        __out SEVEN_SEGMENT *SevenSegment
        );

    HRESULT
    ReadSwitchState(
        __in PSWITCH_STATE SwitchState
        );

    HRESULT
    PlaybackFile(
        __in PFILE_PLAYBACK PlaybackInfo,
        __in IWDFIoRequest *FxRequest
        );

    //
    //returns a weak reference to the target USB device
    //DO NOT release it
    //
    IWDFUsbTargetDevice *
    GetUsbTargetDevice(
        )
    {
        return m_pIUsbTargetDevice;
    }

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
        __in IWDFIoRequest*                 FxRequest,
        __in IWDFIoTarget*                  pIoTarget,
        __in IWDFRequestCompletionParams*   pParams,
        __in PVOID                          pContext
        );        

    //
    // IImpersonateCallback
    //

    virtual
    VOID
    STDMETHODCALLTYPE
    OnImpersonate(
        __in PVOID Context
        );
};



/**************************************************************************

    AVStream Simulated Hardware Sample

    Copyright (c) Microsoft Corporation.  All rights reserved.

    File:

        device.h

    Abstract:

        The header for the device level of the simulated hardware.  This is
        not actually the hardware simulation itself.  The hardware simulation
        is contained in hwsim.*, image.*.
        
    History:

        created 3/9/2001

**************************************************************************/

class CEncoderDevice :
    public IHardwareSink {

private:
    //
    // The AVStream device we're associated with.
    //
    PKSDEVICE m_Device;

    //
    // Number of pins with resources acquired.  This is used as a locking
    // mechanism for resource acquisition on the device.
    //
    LONG m_PinsWithResources;

    //
    // Since we don't have physical hardware, this provides the hardware
    // simulation.  m_HardwareSimulation provides the fake ISR, fake DPC,
    // etc...  m_TsSynth provides a place to put transport stream synthesis
    // in software.
    //
    CHardwareSimulation *m_HardwareSimulation;
    CTsSynthesizer *m_TsSynth;

    //
    // Frequency on the tuner
    //
    ULONG m_ulFrequency;

    //
    // The number of ISR's that have occurred since capture started.
    //
    ULONG m_InterruptTime;

    //
    // The last reading of mappings completed.
    //
    ULONG m_LastMappingsCompleted;

    //
    // The Dma adapter object we acquired through IoGetDmaAdapter() during
    // Pnp start.  This must be initialized with AVStream in order to perform
    // Dma directly into the capture buffers.
    //
    PADAPTER_OBJECT m_DmaAdapterObject;

    //
    // The number of map registers returned from IoGetDmaAdapter().
    //
    ULONG m_NumberOfMapRegisters;

    //
    // The capture sink.  When we complete scatter / gather mappings, we
    // notify the capture sink.
    //
    IEncoderSink *m_EncoderSink;

    //
    // The video info header we're basing hardware settings on.  The pin
    // provides this to us when acquiring resources and must guarantee its
    // stability until resources are released.
    //
    PBDA_TRANSPORT_INFO m_TransportInfo;

    //
    // Cleanup():
    //
    // This is the free callback for the bagged capture device.  Not providing
    // one will call ExFreePool, which is not what we want for a constructed
    // C++ object.  This simply deletes the capture device.
    //
    static
    void
    Cleanup (
        IN CEncoderDevice *EncDevice
        )
    {
        delete EncDevice;
    }

    // CleanupHW()
    //
    // Cleanup the hwsimulation object associated with this device.  This is the
    // free callback for the bagged hwsim.
    //
    static
    void
    CleanupHW(
          IN CHardwareSimulation *hwSim
          ) 
    {
    delete hwSim;
    }
    
    //
    // CleanupSynth():
    //
    // Cleanup the image synth associated with this device.  This is the
    // free callback for the bagged image synth.
    //
    static
    void
    CleanupSynth (
        IN CTsSynthesizer *TsSynth
        )
    {
        delete TsSynth;
    }

    //
    // PnpStart():
    //
    // This is the Pnp start routine for our simulated hardware.  Note that
    // DispatchStart bridges to here in the context of the CEncoderDevice.
    //
    NTSTATUS
    PnpStart (
        IN PCM_RESOURCE_LIST TranslatedResourceList,
        IN PCM_RESOURCE_LIST UntranslatedResourceList
        );

    //
    // PnpStop():
    //
    // This is the Pnp stop routine for our simulated hardware.  Note that
    // DispatchStop bridges to here in the context of the CEncoderDevice.
    //
    void
    PnpStop (
        );

public:

    ULONG  ScanSensingRange;          // R - max range (kHz) in which tuner can detect an analog signal
    ULONG  FineTuneSensingRange;      // R - max range (kHz) in which tuner can detect an digital signal

    ULONG  MinFrequency;                // R - Hz
    ULONG  MaxFrequency;                // R - Hz
    ULONG  SettlingTime;                // milliSeconds
    ULONG  FreqRange;
    ULONG  StandardsSupported;
    LARGE_INTEGER   TotalScanTime;
    BOOL   ScanInitialization;
    ULONG  LockedFrequency;
    UNICODE_STRING    FileName; 
    PVOID EventData;
    UNICODE_STRING StreamLocation;
    //
    // CEncoderDevice():
    //
    // The capture device class constructor.  Since everything should have
    // been zero'ed by the new operator, don't bother setting anything to
    // zero or NULL.  Only initialize non-NULL, non-0 fields.
    //
    CEncoderDevice (
        IN PKSDEVICE Device
        ) :
        m_Device (Device)
    {
        KeInitializeSpinLock(&EventHandlerSpinLock);
        SettlingTime = 100;
        MinFrequency = 471383000;
        MaxFrequency = 800000000;
        FreqRange = MaxFrequency - MinFrequency;
        ScanSensingRange = 3000000;
        FineTuneSensingRange = 150000;
        ScanInitialization = FALSE;
        StandardsSupported = KS_AnalogVideo_PAL_B | KS_AnalogVideo_PAL_D | KS_AnalogVideo_PAL_G | KS_AnalogVideo_PAL_H | KS_AnalogVideo_PAL_I | KS_AnalogVideo_PAL_M | KS_AnalogVideo_PAL_N;
        LockedFrequency = 0;
        FileName.Buffer = NULL;
        RtlZeroMemory(&StreamLocation, sizeof(StreamLocation));
    }

    //
    // ~CEncoderDevice():
    //
    // The capture device destructor.
    //
    ~CEncoderDevice (
        )
    {
        if(EventData)
            ExFreePool(EventData);
    }

    //
    // DispatchCreate():
    //
    // This is the Add Device dispatch for the capture device.  It creates
    // the CEncoderDevice and associates it with the device via the bag.
    //
    static
    NTSTATUS
    DispatchCreate (
        IN PKSDEVICE Device
        );
    //
    // DispatchPnpStart():
    //
    // This is the Pnp Start dispatch for the capture device.  It simply
    // bridges to PnpStart() in the context of the CEncoderDevice.
    //
    static
    NTSTATUS
    DispatchPnpStart (
        IN PKSDEVICE Device,
        IN PIRP Irp,
        IN PCM_RESOURCE_LIST TranslatedResourceList,
        IN PCM_RESOURCE_LIST UntranslatedResourceList
        )
    {
        return 
            (reinterpret_cast <CEncoderDevice *> (Device -> Context)) ->
            PnpStart (
                TranslatedResourceList,
                UntranslatedResourceList
                );
    }

    //
    // DispatchPnpStop():
    //
    // This is the Pnp stop dispatch for the capture device.  It simply
    // bridges to PnpStop() in the context of the CEncoderDevice.
    //
    static
    void
    DispatchPnpStop (
        IN PKSDEVICE Device,
        IN PIRP Irp
        )
    {
        return
            (reinterpret_cast <CEncoderDevice *> (Device -> Context)) ->
            PnpStop (
                );
    }

    //
    // AcquireHardwareResources():
    //
    // Called to acquire hardware resources for the device based on a given
    // video info header.  This will fail if another object has already
    // acquired hardware resources since we emulate a single capture
    // device.
    //
    NTSTATUS
    AcquireHardwareResources (
        IN IEncoderSink *EncoderSink,
        IN PBDA_TRANSPORT_INFO TransportInfo
        );

    //
    // ReleaseHardwareResources():
    //
    // Called to release hardware resources for the device.
    //
    void
    ReleaseHardwareResources (
        );

    //
    // Start():
    //
    // Called to start the hardware simulation.  This causes us to simulate
    // interrupts, simulate filling buffers with synthesized data, etc...
    //
    NTSTATUS
    Start (
        );

    //
    // Pause():
    //
    // Called to pause or unpause the hardware simulation.  This will be
    // indentical to a start or stop but it will not reset formats and 
    // counters.
    //
    NTSTATUS
    Pause (
        IN BOOLEAN Pausing
        );

    //
    // Stop():
    //
    // Called to stop the hardware simulation.  This causes interrupts to
    // stop issuing.  When this call returns, the "fake" hardware has
    // stopped accessing all s/g buffers, etc...
    //
    NTSTATUS
    Stop (
        );

    //
    // ProgramScatterGatherMappings():
    //
    // Called to program the hardware simulation's scatter / gather table.
    // This synchronizes with the "fake" ISR and hardware simulation via
    // a spinlock.
    //
    ULONG
    ProgramScatterGatherMappings (
        IN PUCHAR *Buffer,
        IN PKSMAPPING Mappings,
        IN ULONG MappingsCount
        );

    //
    // QueryInterruptTime():
    //
    // Determine the frame number that this frame corresponds to.  
    //
    ULONG
    QueryInterruptTime (
        );

    //
    // IHardwareSink::Interrupt():
    //
    // The interrupt service routine as called through the hardware sink
    // interface.  The "fake" hardware uses this method to inform the device
    // of a "fake" ISR.  The routine is called at dispatch level and must
    // be in locked code.
    //
    virtual
    void
    Interrupt (
        );

    void
    SetFrequency (
        ULONG ulFrequency
    );

    void
    GetFrequency (
        ULONG *ulFrequency
    );

    PKSEVENT_ENTRY pScanEvent;
    KSPIN_LOCK EventHandlerSpinLock;

};



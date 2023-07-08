//==========================================================================;
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
//  PURPOSE.
//
//  Copyright (c) Microsoft Corporation.  All Rights Reserved.
//
//==========================================================================;
/**************************************************************************
    File    : anlgtuner.cpp 
    Abstract: Contains dispatch routines, property handlers and intersect 
              handlers for the tuner filter
**************************************************************************/

#include "anlgtuner.h"

DWORD 
GetDWORDAttribute(IN __nullterminated LPWSTR AttributeName,  OUT DWORD& AttributeValue)
{
    // 1) Convert dword frequency to string.
    // 2) find matching key in registry
    // 3) read SignalQuality value from registry.
    // 4) pass key back to caller.
    
    NTSTATUS Status = STATUS_SUCCESS;
    UNICODE_STRING KeyName;
    KeyName.Buffer = (LPWSTR)ExAllocatePoolWithTag(NonPagedPool,
                                              MAX_PATH+1, 
                                              MS_SAMPLE_ANALOG_POOL_TAG
                                              );
    KeyName.Length = MAX_PATH;
    KeyName.MaximumLength = MAX_PATH;

    UNICODE_STRING StubName;
    RtlInitUnicodeString(&StubName, L"\\Registry\\Machine\\System\\AnlgSWTuner\\Device Parameters\\");
    RtlCopyUnicodeString(&KeyName, &StubName);
    DbgPrint("KeyName %S\n", KeyName.Buffer);
    Status = PptRegGetDword(RTL_REGISTRY_ABSOLUTE, 
                        KeyName.Buffer,
                        AttributeName, 
                        &AttributeValue);
    
    if (!NT_SUCCESS(Status))
    {
        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
        // There was an error, use the default filename.
        AttributeValue= 0;
    }
    return Status;
}

DWORD 
GetSensingRanges( OUT DWORD& FineTuneSensingRange, OUT DWORD& ScanSensingRange)
{
    // 1) Convert dword frequency to string.
    // 2) find matching key in registry
    // 3) read SignalQuality value from registry.
    // 4) pass key back to caller.
    
    NTSTATUS Status = STATUS_SUCCESS;
   
    Status = GetDWORDAttribute( L"FineTuneSensingRange", FineTuneSensingRange);
    
    if (!NT_SUCCESS(Status))
    {
        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
        // There was an error, use the default filename.
        FineTuneSensingRange = 0;
    }
    DbgPrint("FineTuneSensingRange %ld\n", FineTuneSensingRange);

    Status = GetDWORDAttribute( L"ScanSensingRange", ScanSensingRange);
    
    if (!NT_SUCCESS(Status))
    {
        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
        // There was an error, use the default filename.
        ScanSensingRange = 0;
    }
    DbgPrint("ScanSensingRange %ld\n", ScanSensingRange);

    return Status;
}

DWORD 
GetMinMaxFrequency(OUT DWORD& MinFreq, OUT DWORD& MaxFreq )
{
    NTSTATUS Status = STATUS_SUCCESS;
    Status = GetDWORDAttribute( L"MinFrequency", MinFreq);
    
    if (!NT_SUCCESS(Status))
    {
        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
        // There was an error, use the default filename.
        MinFreq = 0;
    }
    DbgPrint("MinFreq %ld\n", MinFreq);

    Status = GetDWORDAttribute( L"MaxFrequency", MaxFreq);
    
    if (!NT_SUCCESS(Status))
    {
        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
        // There was an error, use the default filename.
        MaxFreq = 0;
    }
    DbgPrint("MaxFreq %ld\n", MaxFreq);

    return Status;
}

DWORD 
GetSettlingTimeStandardSupported(OUT DWORD& SettlingTime, OUT DWORD& Standards)
{
    NTSTATUS Status = STATUS_SUCCESS;
    Status = GetDWORDAttribute( L"SettlingTime", SettlingTime);
    
    if (!NT_SUCCESS(Status))
    {
        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
        // There was an error, use the default filename.
        SettlingTime = 0;
    }
    DbgPrint("SettlingTime %ld\n", SettlingTime);

    Status = GetDWORDAttribute( L"TvStandardSupported", Standards);
    
    if (!NT_SUCCESS(Status))
    {
        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
        // There was an error, use the default filename.
        Standards = 0;
    }
    DbgPrint("TvStandardSupported %ld\n", Standards);

    return Status;
}

DWORD 
GetHardwareScanning( OUT BOOLEAN& HardwareAssistedScanning)
{
    // 1) Convert dword frequency to string.
    // 2) find matching key in registry
    // 3) read SignalPresent value from registry.
    // 4) pass key back to caller.
    HardwareAssistedScanning = FALSE;
    
    NTSTATUS Status = STATUS_SUCCESS;
    DWORD HardwareScanning = 0;
    Status = GetDWORDAttribute(L"HardwareScanning", HardwareScanning);
    
    if (!NT_SUCCESS(Status))
    {
        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
    }

    if (HardwareScanning == 0)
    {
        HardwareAssistedScanning = FALSE;
    }
    else
    {
        HardwareAssistedScanning = TRUE;
    }
    
    DbgPrint("HardwareAssistedScanning %ld\n", HardwareAssistedScanning);

    return Status;
}

NTSTATUS AnlgTunerFilterCreate(IN PKSFILTER Filter, IN PIRP Irp) 
{
    NTSTATUS Status = STATUS_SUCCESS;

    if(!Filter)
    {
    return STATUS_UNSUCCESSFUL;
    }
    if(!Irp)
    {
    return STATUS_UNSUCCESSFUL;
    }
    
    PKSDEVICE pKsDevice = KsFilterGetDevice(Filter);
    if(!pKsDevice) 
    {
    return Status;
    }

    BOOL pPinDirection[2] = {TRUE, TRUE};
    KSPIN_MEDIUM pMediumList[2] = 
    {
    {
        GUID_AnlgTunerPinMediumVideoOut, 0, 0
    },
    {
        GUID_AnlgTunerPinMediumAudioOut, 0, 0
    }
    };

   Status = KsRegisterFilterWithNoKSPins(
         pKsDevice->PhysicalDeviceObject,
         &KSCATEGORY_TVTUNER,
         2,
         pPinDirection,
         pMediumList,
         NULL 
         );
    
   return Status;
}

NTSTATUS AnlgTunerFilterClose(IN PKSFILTER Filter, IN PIRP Irp)
{
    return STATUS_SUCCESS;
}


NTSTATUS AnlgTunerFrequencyGetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_TUNER_FREQUENCY_S pRequest,
    IN OUT PKSPROPERTY_TUNER_FREQUENCY_S pData
)
{

    ASSERT(Irp);
    PKSFILTER pFilter = KsGetFilterFromIrp(Irp);
    PKSDEVICE pDevice = KsFilterGetDevice(pFilter);

    CEncoderDevice* pEncDevice = (CEncoderDevice *)(pDevice->Context);

    pEncDevice->GetFrequency(&pData->Frequency);
    pData->LastFrequency = pData->Frequency;
    pData->TuningFlags = KS_TUNER_TUNING_EXACT;
    pData->Channel = 4;
    pData->Country = 1;

    return STATUS_SUCCESS;
}

NTSTATUS AnlgTunerFrequencySetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_TUNER_FREQUENCY_S pRequest,
    IN OUT PKSPROPERTY_TUNER_FREQUENCY_S pData
)
{ 
    ASSERT(Irp);
    PKSFILTER pFilter = KsGetFilterFromIrp(Irp);
    PKSDEVICE pDevice = KsFilterGetDevice(pFilter);

    CEncoderDevice* pEncDevice = (CEncoderDevice *)(pDevice->Context);
    pEncDevice->SetFrequency(pRequest->Frequency);

    return STATUS_SUCCESS;
}

NTSTATUS AnlgTunerInputGetHandler
(
    PIRP Irp,
    IN PKSPROPERTY_TUNER_INPUT_S pRequest,
    IN OUT PKSPROPERTY_TUNER_INPUT_S pData
) {

    pData->InputIndex = 0;
    return STATUS_SUCCESS;
}

NTSTATUS AnlgTunerCapsGetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_TUNER_CAPS_S pRequest,
    IN OUT PKSPROPERTY_TUNER_CAPS_S pData
) {
    pData->ModesSupported = KSPROPERTY_TUNER_MODE_TV;
    pData->VideoMedium = PinMediumVideoOut;
    pData->TVAudioMedium = PinMediumAudioOut;
    return STATUS_SUCCESS;
}

NTSTATUS AnlgTunerModeGetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_TUNER_MODE_S pRequest,
    IN OUT PKSPROPERTY_TUNER_MODE_S pData

) { 
    pData->Mode = KSPROPERTY_TUNER_MODE_TV;
    return STATUS_SUCCESS;
}

NTSTATUS AnlgTunerModeCapsGetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_TUNER_MODE_CAPS_S pRequest,
    IN OUT PKSPROPERTY_TUNER_MODE_CAPS_S pData

) {
    
    pData->StandardsSupported = KS_AnalogVideo_PAL_B | KS_AnalogVideo_PAL_D | KS_AnalogVideo_PAL_G | KS_AnalogVideo_PAL_H | KS_AnalogVideo_PAL_I | KS_AnalogVideo_PAL_M | KS_AnalogVideo_PAL_N;
    pData->NumberOfInputs = 2;
    pData->Strategy = KS_TUNER_STRATEGY_DRIVER_TUNES;
    // This is sleeping time for vidctl
    pData->SettlingTime = 0;

    // Reasonable values required. Otherwise kstvtune will decide no channels fit.
    pData->MinFrequency = 471383000;
    pData->MaxFrequency = 900000000;
    return STATUS_SUCCESS;

}

NTSTATUS AnlgTunerStandardGetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_TUNER_STANDARD_S pRequest,
    IN OUT PKSPROPERTY_TUNER_STANDARD_S pData
) {

    pData->Standard = KS_AnalogVideo_PAL_B | KS_AnalogVideo_PAL_D | KS_AnalogVideo_PAL_G | KS_AnalogVideo_PAL_H | KS_AnalogVideo_PAL_I | KS_AnalogVideo_PAL_M | KS_AnalogVideo_PAL_N;
    return STATUS_SUCCESS;

}
NTSTATUS AnlgTunerStatusGetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_TUNER_STATUS_S pRequest,
    IN OUT PKSPROPERTY_TUNER_STATUS_S pData
) {
    
    pData->CurrentFrequency = 500000000;
    pData->PLLOffset = 0;
    pData->SignalStrength = 100;
    pData->Busy = FALSE;
    return STATUS_SUCCESS;
}

NTSTATUS AnlgTunerScanCapsGetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_TUNER_SCAN_CAPS_S pRequest,
    IN OUT PKSPROPERTY_TUNER_SCAN_CAPS_S pData
)
{
    ASSERT(Irp);
    PKSFILTER pFilter = KsGetFilterFromIrp(Irp);
    BOOLEAN bScanning = TRUE;
    RtlCopyMemory(pData, pRequest, sizeof(KSPROPERTY_TUNER_SCAN_CAPS_S));
    NTSTATUS Status = STATUS_SUCCESS;

    GetHardwareScanning(bScanning);

    pData->fSupportsHardwareAssistedScanning = bScanning;

    if(pData->SupportedBroadcastStandards == 0)
    {
        pData->SupportedBroadcastStandards = 2;
    }
    else
    {
        __try
        {
            ProbeForWrite(pData->GUIDBucket, pData->lengthofBucket,sizeof(UCHAR));
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
          Status = GetExceptionCode();
          return Status;
        }
        
        if (pData->lengthofBucket <= (sizeof(GUID)*2))
        {
            Status = STATUS_BUFFER_TOO_SMALL;
            return Status;
        }
            
        GUID* guid = reinterpret_cast<GUID*>(pData->GUIDBucket);
        RtlCopyMemory(guid++, &ANALOG_TV_NETWORK_TYPE, sizeof(GUID));
        RtlCopyMemory(guid++, &DIGITAL_CABLE_NETWORK_TYPE, sizeof(GUID));
    }
   return STATUS_SUCCESS;
}

NTSTATUS AnlgTunerAnalogCapsGetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_TUNER_NETWORKTYPE_SCAN_CAPS_S pRequest,
    IN OUT PKSPROPERTY_TUNER_NETWORKTYPE_SCAN_CAPS_S pData
)
{
    ASSERT(Irp);
    PKSFILTER pFilter = KsGetFilterFromIrp(Irp);
    PKSDEVICE pDevice = KsFilterGetDevice(pFilter);
    NTSTATUS Status = STATUS_SUCCESS;

    CEncoderDevice* pEncDevice = reinterpret_cast<CEncoderDevice *>(pDevice->Context);
    RtlCopyMemory(pData, pRequest, sizeof(KSPROPERTY_TUNER_NETWORKTYPE_SCAN_CAPS_S));

    if(pData->NetworkTunerCapabilities && pData->BufferSize)
    {
        __try
        {
            ProbeForWrite(pData->NetworkTunerCapabilities, pData->BufferSize , sizeof(UCHAR));
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
          Status = GetExceptionCode();
          return Status;
        }
        if(pData->NetworkType == ANALOG_TV_NETWORK_TYPE)
        {
            __try
            {
                ProbeForWrite(pData->NetworkTunerCapabilities, sizeof(TUNER_ANALOG_CAPS_S),sizeof(UCHAR));
            }
            __except (EXCEPTION_EXECUTE_HANDLER) {
            Status = GetExceptionCode();
            return Status;
            }
            GetSensingRanges( pEncDevice->FineTuneSensingRange, pEncDevice->ScanSensingRange );
            GetMinMaxFrequency( pEncDevice->MinFrequency, pEncDevice->MaxFrequency );
            GetSettlingTimeStandardSupported( pEncDevice->SettlingTime, pEncDevice->StandardsSupported );

            PTUNER_ANALOG_CAPS_S pAnalog_Caps = reinterpret_cast<PTUNER_ANALOG_CAPS_S>(pData->NetworkTunerCapabilities);
            pAnalog_Caps->StandardsSupported = pEncDevice->StandardsSupported;
            pAnalog_Caps->SettlingTime = pEncDevice->SettlingTime;
            pAnalog_Caps->MinFrequency = pEncDevice->MinFrequency;
            pAnalog_Caps->MaxFrequency = pEncDevice->MaxFrequency;
            pAnalog_Caps->Mode = KSPROPERTY_TUNER_MODE_TV;
            pAnalog_Caps->ScanSensingRange = pEncDevice->ScanSensingRange;
            pAnalog_Caps->FineTuneSensingRange = pEncDevice->FineTuneSensingRange;
        }
    }
    else
    {
        return STATUS_UNSUCCESSFUL;
    }
    return STATUS_SUCCESS;
}



NTSTATUS AnlgTunerScanStatusGetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_TUNER_SCAN_STATUS_S pRequest,
    IN OUT PKSPROPERTY_TUNER_SCAN_STATUS_S pData
)
{
    ASSERT(Irp);
    PKSFILTER pFilter = KsGetFilterFromIrp(Irp);
    PKSDEVICE pDevice = KsFilterGetDevice(pFilter);

    CEncoderDevice* pEncDevice = reinterpret_cast<CEncoderDevice *>(pDevice->Context);
    PEventHandlerData EventData = reinterpret_cast<PEventHandlerData>(pEncDevice->EventData);
    ASSERT(EventData);

    pData->LockStatus = EventData->StatusCode;

    if(EventData->StatusCode == Tuner_LockType_Locked) 
        pData->CurrentFrequency = pEncDevice->LockedFrequency;
    else
        pData->CurrentFrequency = EventData->CurrentFrequency;

    return STATUS_SUCCESS;
}

NTSTATUS AnlgTunerStandardModeGetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_TUNER_STANDARD_MODE_S pRequest,
    IN OUT PKSPROPERTY_TUNER_STANDARD_MODE_S pData
)
{
    return STATUS_SUCCESS;
}

NTSTATUS AnlgTunerStandardModeSetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_TUNER_STANDARD_MODE_S pRequest,
    IN OUT PKSPROPERTY_TUNER_STANDARD_MODE_S pData
)
{
    return STATUS_SUCCESS;
}

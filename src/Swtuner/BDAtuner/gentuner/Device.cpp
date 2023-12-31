/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    device.cpp

Abstract:

    Device driver core, initialization, etc.

--*/

#define KSDEBUG_INIT

#include "BDATuner.h"
#include "wdmdebug.h"

#ifdef ALLOC_DATA_PRAGMA
#pragma const_seg("PAGECONST")
#endif // ALLOC_DATA_PRAGMA

#ifdef ALLOC_PRAGMA
#pragma code_seg("PAGE")
#endif // ALLOC_PRAGMA



extern "C"
NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPathName
    )
/*++

Routine Description:

    Sets up the driver object.

Arguments:

    DriverObject -
        Driver object for this instance.

    RegistryPathName -
        Contains the registry path which was used to load this instance.

Return Values:

    Returns STATUS_SUCCESS if the driver was initialized.

--*/
{
    NTSTATUS    Status = STATUS_SUCCESS;

    _DbgPrintF(DEBUGLVL_VERBOSE,("DriverEntry"));

    // DEBUG_BREAK;

    Status = KsInitializeDriver( DriverObject,
                                 RegistryPathName,
                                 &DeviceDescriptor);

    // DEBUG_BREAK;

    return Status;
}

//  Driver Global Device instance #
//
static ULONG    ulDeviceInstance = 0;

STDMETHODIMP_(NTSTATUS)
CDevice::
Create(
    IN PKSDEVICE Device
    )
{
    NTSTATUS    Status = STATUS_SUCCESS;
    CDevice *   pDevice = NULL;

    // DEBUG_BREAK;

    _DbgPrintF(DEBUGLVL_VERBOSE,("CDevice::Create"));

    ASSERT(Device);


    //  Allocate memory for the our device class.
    //
    pDevice = new(PagedPool,MS_SAMPLE_TUNER_POOL_TAG) CDevice; // Tags the allocated memory 

    
    
    if (pDevice)
    {

       //
        // Add the item to the object bag if we were successful.
        // Whenever the device goes away, the bag is cleaned up and
        // we will be freed.
        //
        // For backwards compatibility with DirectX 8.0, we must grab
        // the device mutex before doing this.  For Windows XP, this is
        // not required, but it is still safe.
        //
        KsAcquireDevice (Device);
        Status = KsAddItemToObjectBag (
            Device -> Bag,
            reinterpret_cast <PVOID> (pDevice),
	    NULL
            );
        KsReleaseDevice (Device);

        if (!NT_SUCCESS (Status)) {
            delete pDevice;
	    return Status;
        }

        //  Point the KSDEVICE at our device class.
        //
        Device->Context = pDevice;
    
        //  Point back to the KSDEVICE.
        //
        pDevice->m_pKSDevice = Device;

        //  Make the resource available for a filter to use.
        //
        pDevice->m_ulcResourceUsers = 0;
        pDevice->m_ulCurResourceID = 0;

        //  Get the instance number of this device.
        //
        pDevice->m_ulDeviceInstance = ulDeviceInstance++;

        //  Set the implementation GUID.  For cases where a single
        //  driver is used for multiple implementations the INF
        //  which installs the device would write the implementation
        //  GUID into the registery.  This code would then
        //  read the Implementation GUID from the registry.
        //
        pDevice->m_guidImplemenation = KSMEDIUMSETID_MyImplementation;
    } else
    {
        Status = STATUS_INSUFFICIENT_RESOURCES;
    }

    return Status;
}


STDMETHODIMP_(NTSTATUS)
CDevice::
Start(
    IN PKSDEVICE            pKSDevice,
    IN PIRP                 pIrp,
    IN PCM_RESOURCE_LIST    pTranslatedResourceList OPTIONAL,
    IN PCM_RESOURCE_LIST    pUntranslatedResourceList OPTIONAL
    )
{
    NTSTATUS            Status = STATUS_SUCCESS;
    CDevice *           pDevice;
    PKSFILTERFACTORY    pKSFilterFactory = NULL;


    // DEBUG_BREAK;

    _DbgPrintF( DEBUGLVL_VERBOSE, ("CDevice::Start"));
    ASSERT( pKSDevice);

    // DEBUG_BREAK;

    pDevice = reinterpret_cast<CDevice *>(pKSDevice->Context);
    ASSERT(pDevice);

    // initialize private class variables in pDevice here

    //  Initialize the hardware.
    //
    Status = pDevice->InitializeHW();
    if (Status == STATUS_SUCCESS)
    {
        //  Create the the Filter Factory.  This factory is used to
        //  create instances of the filter.
        //
        Status = BdaCreateFilterFactoryEx( pKSDevice,
                                           &InitialFilterDescriptor,
                                           &BdaFilterTemplate,
                                           &pKSFilterFactory
                                       );
    }

    if ((Status == STATUS_SUCCESS) && pKSFilterFactory)
    {
        BdaFilterFactoryUpdateCacheData( 
                        pKSFilterFactory,
                        BdaFilterTemplate.pFilterDescriptor
                        );
    }

    return Status;
}


NTSTATUS
CDevice::
InitializeHW(
    )
{
    NTSTATUS    Status = STATUS_SUCCESS;

    //
    //  Initialize the device hardware here.
    //

    return Status;
}

DWORD 
GetDWORDAttributeFromFrequency(IN DWORD dwFreq, IN __nullterminated LPWSTR AttributeName,  OUT DWORD& AttributeValue)
{
    // 1) Convert dword frequency to string.
    // 2) find matching key in registry
    // 3) read SignalQuality value from registry.
    // 4) pass key back to caller.
    
    NTSTATUS Status = STATUS_SUCCESS;
    UNICODE_STRING KeyName;
    KeyName.Buffer = (LPWSTR)ExAllocatePoolWithTag(NonPagedPool,
                                              MAX_PATH+1, 
                                              MS_SAMPLE_TUNER_POOL_TAG
                                              );
    KeyName.Length = MAX_PATH;
    KeyName.MaximumLength = MAX_PATH;

    UNICODE_STRING StubName;
    RtlInitUnicodeString(&StubName, L"\\Registry\\Machine\\System\\PSWTuner\\Device Parameters\\");

    RtlCopyUnicodeString(&KeyName, &StubName);

    UNICODE_STRING Freq;
    Freq.Buffer = (LPWSTR)ExAllocatePoolWithTag(NonPagedPool,
                                              MAX_PATH+1, 
                                              MS_SAMPLE_TUNER_POOL_TAG
                                              );
    Freq.Length = MAX_PATH;
    Freq.MaximumLength = MAX_PATH;
    
    RtlZeroMemory(Freq.Buffer,  MAX_PATH+1);
    RtlIntegerToUnicodeString(dwFreq, 10, &Freq);

    //DbgPrint("Converted Frequency value %S\n", Freq.Buffer);

    RtlAppendUnicodeStringToString(&KeyName, &Freq);

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
    //DbgPrint("%S %ld\n", AttributeName, AttributeValue);

    return Status;
}


DWORD 
GetSignalQualityFromFrequency(IN DWORD dwFreq, OUT DWORD& SignalQuality)
{
    // 1) Convert dword frequency to string.
    // 2) find matching key in registry
    // 3) read SignalQuality value from registry.
    // 4) pass key back to caller.
    
    NTSTATUS Status = STATUS_SUCCESS;
   
    Status = GetDWORDAttributeFromFrequency(dwFreq, L"SignalQuality", SignalQuality);
    
    if (!NT_SUCCESS(Status))
    {
        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
        // There was an error, use the default filename.
        SignalQuality = 0;
    }
    DbgPrint("SignalQuality %ld\n", SignalQuality);

    return Status;
}

DWORD 
GetSignalStrengthFromFrequency(IN DWORD dwFreq, OUT DWORD& SignalStrength)
{
    // 1) Convert dword frequency to string.
    // 2) find matching key in registry
    // 3) read SignalStrength value from registry.
    // 4) pass key back to caller.
    
    NTSTATUS Status = STATUS_SUCCESS;
    Status = GetDWORDAttributeFromFrequency(dwFreq, L"SignalStrength", SignalStrength);
    
    if (!NT_SUCCESS(Status))
    {
        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
        // There was an error, use the default filename.
        SignalStrength = 0;
    }
    DbgPrint("SignalStrength %ld\n", SignalStrength);

    return Status;
}
DWORD 
GetSignalPresentFromFrequency(IN DWORD dwFreq, OUT BOOLEAN& SignalPresent)
{
    // 1) Convert dword frequency to string.
    // 2) find matching key in registry
    // 3) read SignalPresent value from registry.
    // 4) pass key back to caller.
    SignalPresent = FALSE;
    
    NTSTATUS Status = STATUS_SUCCESS;
    DWORD dwSignalPresent = 0;
    Status = GetDWORDAttributeFromFrequency(dwFreq, L"SignalPresent", dwSignalPresent);
    
    if (!NT_SUCCESS(Status))
    {
        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
    }

    if (dwSignalPresent == 0)
    {
        SignalPresent = FALSE;
    }
    else
    {
        SignalPresent = TRUE;
    }
    
    DbgPrint("SignalPresent %ld\n", SignalPresent);

    return Status;
}

DWORD 
GetSignalLockedFromFrequency(IN DWORD dwFreq, OUT BOOLEAN& SignalLocked)
{
    // 1) Convert dword frequency to string.
    // 2) find matching key in registry
    // 3) read SignalLocked value from registry.
    // 4) pass key back to caller.
    SignalLocked = FALSE;
    
    NTSTATUS Status = STATUS_SUCCESS;
    DWORD dwSignalLocked = 0;
    Status = GetDWORDAttributeFromFrequency(dwFreq, L"SignalLocked", dwSignalLocked);
    
    if (!NT_SUCCESS(Status))
    {
        DbgPrint( "%s  Error reading the registry 0x%08x\n", __FUNCTION__, Status); 
    }
    if (dwSignalLocked == 0)
    {
        SignalLocked = FALSE;
    }
    else
    {
        SignalLocked = TRUE;
    }
    
    DbgPrint("SignalLocked %ld\n", SignalLocked);

    return Status;
}


NTSTATUS
CDevice::
GetStatus(
    PBDATUNER_DEVICE_STATUS     pDeviceStatus
    )
{
    NTSTATUS    Status = STATUS_SUCCESS;
    pDeviceStatus->fCarrierPresent = FALSE;
    pDeviceStatus->fSignalLocked = FALSE;
    pDeviceStatus->dwSignalQuality = 0;
    pDeviceStatus->dwSignalStrength = 0;

    //
    //  Get the signal status from the HW here
    //

    //  Since we don't have HW we'll fake it here.
    //
    if ( 0 )
    {
        LONGLONG    llhzFrequency;

        //  Let's pretend that Channels 10, 25, 38, and 39 have
        //  active ATSC signals and channels 4, 5 and 7 have analog
        //  signals present.
        //
        llhzFrequency = m_CurResource.ulCarrierFrequency;
        llhzFrequency *= m_CurResource.ulFrequencyMultiplier;
        llhzFrequency /= 1000;
        if (   (llhzFrequency == (LONGLONG) 193250L)
            || (llhzFrequency == (LONGLONG) 199250L)
            || (llhzFrequency == (LONGLONG) 205250L)
            || (llhzFrequency == (LONGLONG) 211250L)
           )
        {
            pDeviceStatus->dwSignalStrength = 2;
            pDeviceStatus->dwSignalQuality = 99;
            pDeviceStatus->fCarrierPresent = TRUE;
            pDeviceStatus->fSignalLocked = TRUE;
        }
        else if (   (llhzFrequency == (LONGLONG) 67250L)
                 || (llhzFrequency == (LONGLONG) 77250L)
                 || (llhzFrequency == (LONGLONG) 83250L)
                )
        {
            pDeviceStatus->fCarrierPresent = TRUE;
            pDeviceStatus->fSignalLocked = FALSE;
        }
        else
        {
            pDeviceStatus->fCarrierPresent = FALSE;
            pDeviceStatus->fSignalLocked = FALSE;
        }
    }

    // Override the default values with the values stored in the registry.
    GetSignalQualityFromFrequency(m_CurResource.ulCarrierFrequency, pDeviceStatus->dwSignalQuality);
    GetSignalStrengthFromFrequency(m_CurResource.ulCarrierFrequency, pDeviceStatus->dwSignalStrength);
    GetSignalLockedFromFrequency(m_CurResource.ulCarrierFrequency, pDeviceStatus->fSignalLocked);
    GetSignalPresentFromFrequency(m_CurResource.ulCarrierFrequency, pDeviceStatus->fCarrierPresent);
    

    return Status;
}


NTSTATUS
CDevice::
AcquireResources(
    PBDATUNER_DEVICE_RESOURCE   pNewResource,
    PULONG                      pulAcquiredResourceID
    )
{
    NTSTATUS    Status = STATUS_SUCCESS;
    LONGLONG    ulhzFrequency;

    //
    //  Validate the requested resource here.
    //

    //  Check to see if the resources are being used by another
    //  filter instance.
    //
    if (!m_ulcResourceUsers)
    {
        m_CurResource = *pNewResource;

        //  Generate a new resource ID and hand it back.
        //
        m_ulCurResourceID += 25;
        *pulAcquiredResourceID = m_ulCurResourceID;
        m_ulcResourceUsers += 1;

        //
        //  Configure the new resource on the hardware here.
        //
    }
#ifdef RESOURCE_SHARING
    //  For resource sharing the IsEqualResource method should be
    //  implemented
    //
    else if (IsEqualResource( pNewResource, &m_CurResource))
    {
        *pulAcquiredResourceID = m_ulCurResourceID;
        m_ulcResourceUsers += 1;
    }
#endif // RESOURCE_SHARING
    else
    {
        //  We only allow one active filter at a time in this implementation.
        //
        Status = STATUS_DEVICE_BUSY;
    }

    return Status;
}


NTSTATUS
CDevice::
UpdateResources(
    PBDATUNER_DEVICE_RESOURCE   pNewResource,
    ULONG                       ulResourceID
    )
{
    NTSTATUS    Status = STATUS_SUCCESS;
    LONGLONG    ulhzFrequency;

    //
    //  Validate the requested resource here.
    //

    //  Check to see if the resources are being used by another
    //  filter instance.
    //
    if (   m_ulcResourceUsers
        && (ulResourceID == m_ulCurResourceID)
       )
    {
        m_CurResource = *pNewResource;

        //
        //  Configure the updated resource on the hardware here.
        //
    }
    else
    {
        //  We only allow one active filter at a time in this implementation.
        //
        Status = STATUS_INVALID_DEVICE_REQUEST;
    }

    return Status;
}


NTSTATUS
CDevice::
ReleaseResources(
    ULONG                   ulResourceID
    )
{
    NTSTATUS    Status = STATUS_SUCCESS;

    if (   m_ulcResourceUsers
        && (ulResourceID == m_ulCurResourceID)
       )
    {
        //  Free the resource to be used by another filter.
        //
        m_ulcResourceUsers--;
    }
    else
    {
        Status = STATUS_INVALID_DEVICE_REQUEST;
    }

    return Status;
}


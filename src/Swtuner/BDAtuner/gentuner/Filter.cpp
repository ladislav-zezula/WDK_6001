/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    filter.cpp

Abstract:

    Filter core, initialization, etc.

--*/

#include "BDATuner.h"
#include "..\..\utillib\common.h"

#ifdef ALLOC_DATA_PRAGMA
#pragma const_seg("PAGECONST")
#endif // ALLOC_DATA_PRAGMA

#ifdef ALLOC_PRAGMA
#pragma code_seg("PAGE")
#endif // ALLOC_PRAGMA

#ifndef arraysize
    #define arraysize(p) (sizeof(p)/sizeof((p)[0]))
#endif

#define MS_SAMPLE_TUNER_POOL_TAG 'TadB'

PCWSTR NAMED_PIPE_NAME = L"\\??\\C:\\Windows\\system32\\FrequencyPipe.txt";
PCWSTR FREQUENCY_PIPE_NAME = L"\\??\\C:\\FrequencyToRead.txt";
PCWSTR CAPTURENAME = L"Sample BDA Capture";
PCWSTR FRIENDLYNAME = L"FriendlyName";

#ifdef IOCTL_DRIVER

NTSTATUS
SendIOCTL (
    CFilter *pFilter,
    ULONG     ulIoctl,
    PVOID     pData,
    ULONG     ulpData,
    PVOID     pcbData,
    ULONG     ulcbData

)

//////////////////////////////////////////////////////////////////////////////
{
    PIRP pIrp                      = NULL;
    NTSTATUS ntStatus              = STATUS_SUCCESS;
    IO_STATUS_BLOCK  IoStatusBlock = {0};

    //
    // Create a control request block
    //
    pIrp = IoBuildDeviceIoControlRequest(
                ulIoctl,
                pFilter->pDevObject,
                pData,
                ulpData,
                pcbData,                            // Optional output buffer
                ulcbData,                            // Optional output buffer length
                FALSE,                         // InternalDeviceIoControl == FALSE
                NULL,                         // Optional Event
                &IoStatusBlock);

    if (pIrp != NULL)
    {
        PIO_STACK_LOCATION   pNextStackLocation;

        pNextStackLocation = IoGetNextIrpStackLocation(pIrp);
        if (pNextStackLocation)
        {
            pNextStackLocation->FileObject = pFilter->pFiObject;
            pNextStackLocation->MajorFunction = IRP_MJ_DEVICE_CONTROL;
            pNextStackLocation->Parameters.DeviceIoControl.IoControlCode = IOCTL_KS_PROPERTY;
   
            IoStatusBlock.Status = STATUS_SUCCESS;
            ntStatus = IoCallDriver( pFilter->pDevObject, pIrp);
    
            if (ntStatus  != STATUS_SUCCESS ||
                IoStatusBlock.Status != STATUS_SUCCESS)
            {
                DbgPrint( "Error Code from SendIoCtl is %x and Iostatus code is %x \n", ntStatus,IoStatusBlock.Status);
                ntStatus = STATUS_UNSUCCESSFUL;
            }
        }
        else
        {
            ntStatus = STATUS_UNSUCCESSFUL;
        }
    }
    else
    {
        ntStatus = STATUS_UNSUCCESSFUL;
    }
    return ntStatus;
}

#endif

DWORD WriteDWORDToFile(DWORD dwToWrite)
{
   OBJECT_ATTRIBUTES FileObject;
   UNICODE_STRING    FileName; 
   NTSTATUS          Status;
    HANDLE _hFrequencyPipeHandle;
    UNICODE_STRING namedPipe;
    OBJECT_ATTRIBUTES attr;

    DbgPrint( "WriteDWORDToFile:: %d\n", dwToWrite);

    RtlInitUnicodeString ( &namedPipe, FREQUENCY_PIPE_NAME);

    InitializeObjectAttributes ( 
        &attr,
        &namedPipe,
        OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE,
        NULL,
        NULL
        );

    IO_STATUS_BLOCK ioStatusBlock;

    Status = ZwCreateFile( &_hFrequencyPipeHandle, 
                                GENERIC_WRITE, 
                                &attr, 
                                &ioStatusBlock, 
                                NULL, 
                                0, 
                                FILE_SHARE_WRITE, 
                                FILE_OPEN_IF, 
                                FILE_SYNCHRONOUS_IO_NONALERT|FILE_NON_DIRECTORY_FILE, 
                                NULL,
                                0 ); 

    if(!NT_SUCCESS(Status)) 
    {
        DbgPrint( "ReadDWORDFromFile  Error Creating the File 0x%08x\n", Status); 
    }
       
    Status = ZwWriteFile(_hFrequencyPipeHandle,
              NULL,
              NULL,
              NULL,
              &ioStatusBlock,
              &dwToWrite,
              sizeof(dwToWrite),
               NULL,
              NULL);

    if (!NT_SUCCESS(Status)) {
        DbgPrint( "VidReadWorkItem::ZwWriteFile Failed 0x%08X\n", Status);
    return Status;
    }

    Status = ZwClose(_hFrequencyPipeHandle);
    if (!NT_SUCCESS(Status)) 
    {
        DbgPrint( "VidReadWorkItem::ZwWriteFile Failed 0x%08X\n", Status);
    }    
    return Status;
}

/*
** Constructor() method of the CFilter class
**
**    Creates the filter object,
**    associates it with the device object, and 
**    initializes member variables for it.
**
*/
CFilter::CFilter()
{
    NTSTATUS    Status = STATUS_SUCCESS;
    UNICODE_STRING usName, DriverName;
    OBJECT_ATTRIBUTES objAttrib = {0};
    IO_STATUS_BLOCK IoStatusBlock = {0};
    PFILE_OBJECT fileObject;

    PDEVICE_OBJECT   pDeviceObject, pdObject = NULL;
    PFILE_OBJECT     pFileObject = NULL;
    HANDLE           hFileHandle = 0;

    KIRQL       Irql;
    PWSTR       pwstr = (PWSTR)NULL;
    PWSTR       pwstr1 = (PWSTR)NULL;

    KeInitializeSpinLock(&spinLock);
    pDevObject = NULL;
    pFiObject = NULL;
}

CFilter::~CFilter()
{
    NTSTATUS    Status = STATUS_SUCCESS;

    PDEVICE_OBJECT   pDeviceObject = NULL;
    PFILE_OBJECT     pFileObject = NULL;
    HANDLE           hFileHandle = 0;
    KIRQL            Irql;

    KeAcquireSpinLock( &this->spinLock, &Irql);

    if (pDevObject)
    {
        pDeviceObject = this->pDevObject;
        this->pDevObject = NULL;
    }
    if(pFiObject)
    {
        pFileObject = this->pFiObject;
        this->pFiObject = NULL;
    }
    KeReleaseSpinLock( &this->spinLock, Irql);

    if (pDeviceObject)
    {
        ObDereferenceObject(pDeviceObject);
        pDeviceObject = NULL;
    }

    if (pFileObject)
    {
        ObDereferenceObject(pFileObject);
        pFileObject = NULL;
    }
    if(hFileHandle)
    {
        ZwClose( hFileHandle);
        hFileHandle = 0;
    }
}

/*
** Create() method of the CFilter class
**
**    Creates the filter object,
**    associates it with the device object, and 
**    initializes member variables for it.
**
*/
STDMETHODIMP_(NTSTATUS)
CFilter::Create(
    IN OUT PKSFILTER pKSFilter,
    IN PIRP Irp
    )
{
    NTSTATUS    Status = STATUS_SUCCESS;
    ULONG       ulPinId;  // just useful when no network provider is present
    PKSDEVICE   pKSDevice = NULL;
    CDevice *   pDevice = NULL;

    _DbgPrintF(DEBUGLVL_VERBOSE,("FilterCreate"));

    ASSERT(pKSFilter);
    ASSERT(Irp);


    //  Create a filter object for the filter instance.
    //
    CFilter* pFilter = new(PagedPool,MS_SAMPLE_TUNER_POOL_TAG) CFilter; // Tags the allocated memory
    if (!pFilter)
    {
        Status = STATUS_INSUFFICIENT_RESOURCES;
        goto errExit;
    }
    //  Link the filter context to the passed in pointer to the KSFILTER structure.
    //
    pKSFilter->Context = pFilter;

    //  Point to the KS device object for this filter.
    //
    pKSDevice = KsFilterGetDevice( pKSFilter);
    ASSERT( pKSDevice);
    if (!pKSDevice)
    {
        Status = STATUS_DEVICE_NOT_CONNECTED;
        goto errExit;
    }

    //  Get the device object from the retrieved pointer to the KSDevice for this filter.
    //
    pDevice = reinterpret_cast<CDevice *>(pKSDevice->Context);
    ASSERT( pDevice);
    if (!pDevice)
    {
        Status = STATUS_DEVICE_NOT_CONNECTED;
        goto errExit;
    }

    //  Link the filter context to the device context.
    //  That is, set the filter's device pointer data member to the obtained device pointer.
    //
    pFilter->m_pDevice = pDevice;

    //  Initialize member variables.
    //
    pFilter->m_KsState = KSSTATE_STOP;
    pFilter->m_BdaChangeState = BDA_CHANGES_COMPLETE;
    pFilter->m_ulResourceID = 0;

#if ATSC_RECEIVER
    //  Configure the initial resource for ATSC reception of channel 39.
    pFilter->m_CurResource.ulCarrierFrequency = 621250L;
    pFilter->m_CurResource.ulFrequencyMultiplier = 1000;

#elif DVBT_RECEIVER
    //  Configure the initial resource for DVBT .
    pFilter->m_CurResource.ulCarrierFrequency = 754000L;
    pFilter->m_CurResource.ulFrequencyMultiplier = 1000;
#endif


#if ATSC_RECEIVER
    pFilter->m_CurResource.guidDemodulator = KSNODE_BDA_8VSB_DEMODULATOR;
#elif DVBT_RECEIVER
    pFilter->m_CurResource.guidDemodulator = KSNODE_BDA_COFDM_DEMODULATOR;
#endif
    pFilter->m_fResourceAcquired = FALSE;

    //  Call the BDA support library to initialize the
    //  filter instance with the default template topology.
    //
    Status = BdaInitFilter( pKSFilter, &BdaFilterTemplate);
    if (NT_ERROR( Status))
    {
        goto errExit;
    }

#ifdef NO_NETWORK_PROVIDER
    //
    //  This code can be used for initial testing of a filter when
    //  a network provider can't be used to configure the filter.
    //  This situation may arise when the receiver topology includes
    //  filters that have not yet been written or when a new network
    //  type does not yet have a network provider implementation.
    //
    //  This code should NOT be used when a driver is delivered into
    //  a working BDA receiver solution.
    //

    //  Create the transport output pin
    //
    Status = BdaCreatePin( pKSFilter, 
                           PIN_TYPE_TRANSPORT, 
                           &ulOutputPinId
                           );
    if (!NT_SUCCESS(Status))
    {
        goto errExit;
    }
    
    //  Create the topology between the antenna input and
    //  transport output pins.
    //
    //  Note that the antenna input pin was automatically created
    //  because it was included in the pin descriptor list of the
    //  initial filter descriptor passed to BdaCreateFilterFactory.
    //
    Status = BdaCreateTopology( pKSFilter, 
                                INITIAL_ANNTENNA_PIN_ID, 
                                ulOutputPinId
                                );
    if (!NT_SUCCESS(Status))
    {
        goto errExit;
    }

#endif // NO_NETWORK_PROVIDER

exit:
    return Status;

errExit:
    if (pFilter)
    {
        delete pFilter;
    }
    pKSFilter->Context = NULL;

    goto exit;
}


/*
** FilterClose() method of the CFilter class
**
**    Deletes the previously created filter object.
**
*/
STDMETHODIMP_(NTSTATUS)
CFilter::FilterClose(
    IN OUT PKSFILTER Filter,
    IN PIRP Irp
    )
{
    _DbgPrintF(DEBUGLVL_VERBOSE,("FilterClose"));

    ASSERT(Filter);
    ASSERT(Irp);

    CFilter* filter = reinterpret_cast<CFilter*>(Filter->Context);
    ASSERT(filter);

    delete filter;

    return STATUS_SUCCESS;
}

/*
** StartChanges() method of the CFilter class
**
**    Puts the filter into change state.  All changes to BDA topology
**    and properties changed after this will be in effect only after
**    a call to the CFilter::CommitChanges() method.
**
*/
NTSTATUS
CFilter::StartChanges(
    IN PIRP         pIrp,
    IN PKSMETHOD    pKSMethod,
    OPTIONAL PVOID  pvIgnored
    )
{
    NTSTATUS        Status = STATUS_SUCCESS;
    CFilter *       pFilter;

    ASSERT( pIrp);
    ASSERT( pKSMethod);

    //  Obtain a "this" pointer to the filter object.
    //
    //  Because the property dispatch table calls the CFilter::StartChanges() method 
    //  directly, the method must retrieve a pointer to the underlying filter object.
    //
    pFilter = reinterpret_cast<CFilter *>(KsGetFilterFromIrp(pIrp)->Context);
    ASSERT( pFilter);

    //  Call the BDA support library to 
    //  reset any pending BDA topolgoy changes.
    //
    Status = BdaStartChanges( pIrp);
    if (NT_SUCCESS( Status))
    {
        //  Reset any pending resource changes.
        //
        pFilter->m_NewResource = pFilter->m_CurResource;
        pFilter->m_BdaChangeState = BDA_CHANGES_COMPLETE;
    }

    return Status;
}


/*
** CheckChanges() method of the CFilter class
**
**    Checks the changes to BDA interfaces that have occured since the
**    last call to the CFilter::StartChanges() method.  Returns the identical 
**    result that the CFilter::CommitChanges() method returns.
**
*/
NTSTATUS
CFilter::CheckChanges(
    IN PIRP         pIrp,
    IN PKSMETHOD    pKSMethod,
    OPTIONAL PVOID  pvIgnored
    )
{
    NTSTATUS            Status = STATUS_SUCCESS;
    CFilter *           pFilter;
    BDA_CHANGE_STATE    topologyChangeState;

    ASSERT( pIrp);
    ASSERT( pKSMethod);

    //  Obtain a "this" pointer to the filter object.
    //
    //  Because the property dispatch table calls the CFilter::CheckChanges() method 
    //  directly, the method must retrieve a pointer to the underlying filter object.
    //
    pFilter = reinterpret_cast<CFilter *>(KsGetFilterFromIrp(pIrp)->Context);
    ASSERT( pFilter);

    //  Call the BDA support library to 
    //  verify a new set of BDA topology changes.
    //
    Status = BdaCheckChanges( pIrp);
    if (NT_SUCCESS( Status))
    {
        //
        //  Validate the new resource list here.
        //  In this driver the new resource list is always valid.
        //
    }

    return Status;
}


// copied from ks...shdevice.cpp
NTSTATUS
CFilter::GetRegistryValue(
    __in HANDLE KeyHandle,
    __in_bcount(ValueNameLength) PWCHAR wszValueName,
    __in ULONG ValueNameLength,
    __out_bcount(*DataLength) PVOID pData,
    __inout PULONG DataLength
    )
{
    NTSTATUS status = STATUS_INSUFFICIENT_RESOURCES;
    UNICODE_STRING keyName;
    ULONG length;
    PKEY_VALUE_FULL_INFORMATION fullInfo;


    RtlInitUnicodeString(&keyName, wszValueName);
    
    length = sizeof(KEY_VALUE_FULL_INFORMATION) + 
            ValueNameLength + (*DataLength);
            
    fullInfo = (PKEY_VALUE_FULL_INFORMATION)ExAllocatePoolWithTag(NonPagedPool, length, MS_SAMPLE_TUNER_POOL_TAG); 
     
    if (fullInfo) { 
       
        status = ZwQueryValueKey(
                    KeyHandle,
                   &keyName,
                    KeyValueFullInformation,
                    fullInfo,
                    length,
                   &length
                    );
                        
        if (NT_SUCCESS(status)){

            ASSERT(fullInfo->DataLength <= *DataLength); 

             memcpy(pData,((PUCHAR) fullInfo) + fullInfo->DataOffset,fullInfo->DataLength);
        }            
        *DataLength = fullInfo->DataLength;
        ExFreePoolWithTag(fullInfo, MS_SAMPLE_TUNER_POOL_TAG);
    }        
    return (status);
}
/*
** CommitChanges() method of the CFilter class
**
**    Checks and commits the changes to BDA interfaces that have occured since the
**    last call to the CFilter::StartChanges() method.  
**
*/
NTSTATUS
CFilter::CommitChanges(
    IN PIRP         pIrp,
    IN PKSMETHOD    pKSMethod,
    OPTIONAL PVOID  pvIgnored
    )
{
    NTSTATUS        Status = STATUS_SUCCESS;
    CFilter *       pFilter;
    ULONG           BytesReturned;

#if PROPERTYSET_CAPTUREDRIVER
    UNICODE_STRING usName;
    PDEVICE_OBJECT   pDeviceObject = NULL;
    PFILE_OBJECT     pFileObject = NULL;
    KIRQL       Irql;
    ANSI_STRING DestinationString;
    PWSTR pSymbolicString;
    ULONG dwLength;
    WCHAR wszTemp[MAX_PATH];
    UNICODE_STRING  SymbolicLinkListU, SymbolicLinkListV;
    HANDLE  DeviceInterfaceKey = NULL;
#endif

    ASSERT( pIrp);
    ASSERT( pKSMethod);

    //  Obtain a "this" pointer to the filter object.
    //
    //  Because the property dispatch table calls the CFilter::CommitChanges() method 
    //  directly, the method must retrieve a pointer to the underlying filter object.
    //
    pFilter = reinterpret_cast<CFilter *>(KsGetFilterFromIrp(pIrp)->Context);
    ASSERT( pFilter);

    //
    //  Validate the new resource list here.
    //  In this driver the new resource list is always valid.
    //

    //  Mark the changes as having been made.
    //
    pFilter->m_CurResource = pFilter->m_NewResource;
    pFilter->m_BdaChangeState = BDA_CHANGES_COMPLETE;

#if PROPERTYSET_CAPTUREDRIVER
    PWSTR pDeviceList = NULL;
    if(pFilter && (!(pFilter->pDevObject) || !(pFilter->pFiObject)))
    {
    Status = IoGetDeviceInterfaces( (GUID *) &KSCATEGORY_BDA_RECEIVER_COMPONENT,
                                    NULL,
                                    0,
                                    &pDeviceList);

        if (Status == STATUS_SUCCESS)
        {
            DbgPrint( "Got Device Interfaces");
            pSymbolicString = pDeviceList;
            do
            {
                if(pSymbolicString)
                {
                    RtlInitUnicodeString( &usName, pSymbolicString);
                    if (NT_SUCCESS(Status = IoOpenDeviceInterfaceRegistryKey(
                                        &usName,                // IN PUNICODE_STRING SymbolicLinkName,
                                        STANDARD_RIGHTS_READ,   // IN ACCESS_MASK DesiredAccess,
                                        &DeviceInterfaceKey     // OUT PHANDLE DeviceInterfaceKey
                                        )))
                        {
                            dwLength = sizeof(wszTemp);
                            Status = GetRegistryValue(DeviceInterfaceKey, (PWCHAR)FRIENDLYNAME, sizeof(FRIENDLYNAME), (PVOID)wszTemp, &dwLength);
                            if( !NT_SUCCESS(Status ))
                            {
                                    DbgPrint( "GetRegistryValue failed error is %d\n", Status);
                            }
                            else 
                            {
                                RtlInitUnicodeString(&SymbolicLinkListU, CAPTURENAME);
                                RtlInitUnicodeString(&SymbolicLinkListV, wszTemp);
                                if(RtlCompareUnicodeString(&SymbolicLinkListU, &SymbolicLinkListV, TRUE) == 0)
                                {
                                    Status = STATUS_SUCCESS;
                                    break;
                                }
                            }
                        }
                }
                pSymbolicString += (usName.Length + sizeof(UNICODE_NULL)) / sizeof(WCHAR);
            }while(*pSymbolicString != UNICODE_NULL);

            if(DeviceInterfaceKey)
                ZwClose(DeviceInterfaceKey);

            RtlUnicodeStringToAnsiString(&DestinationString, &usName, TRUE);
            DbgPrint( "The symbolic Link is %s\n",DestinationString.Buffer);

            Status = IoGetDeviceObjectPointer (
                    &usName,
                    FILE_ALL_ACCESS,
                    &pFileObject,
                    &pDeviceObject);
            if (Status == STATUS_SUCCESS) 
            {
                    DbgPrint( "Got IoGetDeviceObjectPointer");
                    ObReferenceObject(pDeviceObject);
                    ObReferenceObject(pFileObject);
                    KeAcquireSpinLock( &pFilter->spinLock, &Irql);
                    {
                        PDEVICE_OBJECT   pDeviceObjectT;
                        
                        pDeviceObjectT = pFilter->pDevObject;
                        pFilter->pDevObject = pDeviceObject;
                        pDeviceObject = pDeviceObjectT;
                    }
                    {
                        PFILE_OBJECT     pFileObjectT;

                        pFileObjectT = pFilter->pFiObject;
                        pFilter->pFiObject = pFileObject;
                        pFileObject = pFileObjectT;
                    }
                    KeReleaseSpinLock( &pFilter->spinLock, Irql);
            }
            else
            {
                DbgPrint( "IoGetDeviceObjectPointer returned %x\n", Status);
            }
        }
        else
        {
            pFilter->pDevObject = NULL;
            pFilter->pFiObject = NULL;
            DbgPrint( "Error from IoGetDeviceInterfaces..Status is %x\n", Status);
        }
        if(pDeviceList)
        {
            ExFreePool(pDeviceList);
            pDeviceList = NULL;
        }
        if(DestinationString.Buffer)
            RtlFreeAnsiString(&DestinationString);
    }
#endif

    //
    // Push the new tuning information to the capture filter's connection by writing the dword to a file.
    //
    if(pFilter->pDevObject && pFilter->pFiObject)
    {
        ULONG freq;

        freq = pFilter->m_CurResource.ulCarrierFrequency;

        KSPROPERTY_CAPNODE_FREQUENCY_S ksPNode;
        ksPNode.Property.Set    = KSNAME_CaptureNodePropertySet;
        ksPNode.Property.Id     = KSPROPERTY_CAPTURENODE_SETFREQ;
        ksPNode.Property.Flags  = KSPROPERTY_TYPE_SET; 
        ksPNode.Frequency  = freq; 

#ifdef IOCTL_DRIVER
        Status = SendIOCTL(     pFilter, 
                                IOCTL_KS_PROPERTY, 
                                &ksPNode, 
                                sizeof( KSPROPERTY_CAPNODE_FREQUENCY_S),
                                &ksPNode, 
                                sizeof( KSPROPERTY_CAPNODE_FREQUENCY_S)
                                );
#else
       DbgPrint( "Performing KsSynchronousIoControlDevice");
       Status = KsSynchronousIoControlDevice(
                        pFilter->pFiObject,
                        KernelMode,
                        IOCTL_KS_PROPERTY,
                        &ksPNode,
                        sizeof(KSPROPERTY_CAPNODE_FREQUENCY_S),
                        &ksPNode,
                        sizeof(KSPROPERTY_CAPNODE_FREQUENCY_S),
                        &BytesReturned);
#endif

        if(Status != STATUS_SUCCESS)
        {
            WriteDWORDToFile(pFilter->m_CurResource.ulCarrierFrequency);
        }
    }
    else
    {
        WriteDWORDToFile(pFilter->m_CurResource.ulCarrierFrequency);
    }

    if (pFilter->m_KsState != KSSTATE_STOP)
    {
        //  Commit the resources on the underlying device
        //
        Status = pFilter->AcquireResources( );
        ASSERT( NT_SUCCESS( Status));
    }

    //  Call the BDA support library to 
    //  commit a new set of BDA topology changes.
    //
    Status = BdaCommitChanges( pIrp);
    return Status;
}


/*
** GetChangeState() method of the CFilter class
**
**    Returns the current BDA change state.
**
*/
NTSTATUS
CFilter::GetChangeState(
    IN PIRP         pIrp,
    IN PKSMETHOD    pKSMethod,
    OUT PULONG      pulChangeState
    )
{
    NTSTATUS            Status = STATUS_SUCCESS;
    CFilter *           pFilter;
    BDA_CHANGE_STATE    topologyChangeState;

    ASSERT( pIrp);
    ASSERT( pKSMethod);
    // pulChangeState needs to be verified because minData is zero
    // in the KSMETHOD_ITEM definition in bdamedia.h
    if (!pulChangeState)
    {
        pIrp->IoStatus.Information = sizeof(ULONG);
        return STATUS_MORE_ENTRIES;
    }   

    //  Obtain a "this" pointer to the filter object.
    //
    //  Because the property dispatch table calls the CFilter::GetChangeState() method 
    //  directly, the method must retrieve a pointer to the underlying filter object.
    //
    pFilter = reinterpret_cast<CFilter *>(KsGetFilterFromIrp(pIrp)->Context);
    ASSERT( pFilter);


    //  Call the BDA support library to 
    //  verify for any pending BDA topology changes.
    //
    Status = BdaGetChangeState( pIrp, &topologyChangeState);
    if (NT_SUCCESS( Status))
    {
        //  Figure out if there are changes pending.
        //
        if (   (topologyChangeState == BDA_CHANGES_PENDING)
            || (pFilter->m_BdaChangeState == BDA_CHANGES_PENDING)
           )
        {
            *pulChangeState = BDA_CHANGES_PENDING;
        }
        else
        {
            *pulChangeState = BDA_CHANGES_COMPLETE;
        }
    }


    return Status;
}


/*
** GetMedium() method of the CFilter class
**
** Identifies specific connection on a communication bus 
**
*/
NTSTATUS
CFilter::GetMedium(
    IN PIRP             pIrp,
    IN PKSMETHOD        pKSProperty,
    OUT KSPIN_MEDIUM *  pKSMedium
    )
{
    NTSTATUS            Status = STATUS_SUCCESS;
    CFilter *           pFilter;
    ULONG               ulPinType;
    PKSFILTER           pKSFilter;
    KSP_PIN *           pKSPPin = (KSP_PIN *) pKSProperty;

    ASSERT( pIrp);
    ASSERT( pKSProperty);
    // pulChangeState needs to be verified because minData is zero
    // in the KSMETHOD_ITEM definition in bdamedia.h
    if (!pKSMedium)
    {
        pIrp->IoStatus.Information = sizeof(KSPIN_MEDIUM);
        return STATUS_MORE_ENTRIES;
    }   


    //  Obtain a "this" pointer to the filter object.
    //
    //  Because the property dispatch table calls the CFilter::CreateTopology() method 
    //  directly, the method must retrieve a pointer to the underlying filter object.
    //
    pFilter = reinterpret_cast<CFilter *>(KsGetFilterFromIrp(pIrp)->Context);
    ASSERT( pFilter);

    //  Because there is a max of one instance of each pin for a given filter
    //  instance, we can use the same GUID for the medium on each pin.
    //

    //  We use a GUID specific to this implementation of the
    //  device to differentiate from other implemenations of the same
    //  device.
    //
    Status = pFilter->m_pDevice->GetImplementationGUID( &pKSMedium->Set);
    if (!NT_SUCCESS( Status))
    {
        pKSMedium->Set = KSMEDIUMSETID_Standard;
        Status = STATUS_SUCCESS;
    }

    //  Further, we must differentiate this instance of this implementation
    //  from other intances of the same implementation.  We use a device
    //  instance number to do this.
    //
    Status = pFilter->m_pDevice->GetDeviceInstance( &pKSMedium->Id);
    if (!NT_SUCCESS( Status))
    {
        pKSMedium->Id = 0;
        Status = STATUS_SUCCESS;
    }

    //  Across all filters that represent this device there can only be one
    //  input pin instance and one output pin instance with the same
    //  media type so we don't have to distinguish between pin instances.
    //
    pKSMedium->Flags = 0;

    DbgPrint("%s Id %d\n", __FUNCTION__, pKSMedium->Id);

    return Status;
}


/*
** CreateTopology() method of the CFilter class
**
**    Keeps track of the topology association between input and output pins
**
*/
NTSTATUS
CFilter::CreateTopology(
    IN PIRP         pIrp,
    IN PKSMETHOD    pKSMethod,
    PVOID           pvIgnored
    )
{
    NTSTATUS            Status = STATUS_SUCCESS;
    CFilter *           pFilter;
    ULONG               ulPinType;
    PKSFILTER           pKSFilter;

    ASSERT( pIrp);
    ASSERT( pKSMethod);

    //  Obtain a "this" pointer to the filter object.
    //
    //  Because the property dispatch table calls the CFilter::CreateTopology() method 
    //  directly, the method must retrieve a pointer to the underlying filter object.
    //
    pFilter = reinterpret_cast<CFilter *>(KsGetFilterFromIrp(pIrp)->Context);
    ASSERT( pFilter);

    //
    //  Configure the hardware to complete its internal connection between
    //  the input pin and output pin here.
    //

    //  Call the BDA support library to create the standard topology and 
    //  validate the method, instance count, etc.
    //
    Status = BdaMethodCreateTopology( pIrp, pKSMethod, pvIgnored);


    return Status;
}


/*
** SetDemodulator ()
**
**    Sets the type of the demodulator.
**
** Arguments:
**
**
** Returns:
**
** Side Effects:  none
*/
STDMETHODIMP_(NTSTATUS)
CFilter::SetDemodulator(
    IN const GUID *       pguidDemodulator
    )
{
    NTSTATUS        Status = STATUS_SUCCESS;
    ASSERT (pguidDemodulator);
    if (!pguidDemodulator)
    {
        return STATUS_INVALID_PARAMETER;
    }   

    //  Make sure the demodulator is supported.
    //
//#if ATSC_RECEIVER
    if (IsEqualGUID( pguidDemodulator, &KSNODE_BDA_8VSB_DEMODULATOR) ||
//#elif DVBT_RECEIVER
        IsEqualGUID( pguidDemodulator, &KSNODE_BDA_COFDM_DEMODULATOR) ||
//#elif DVBS_RECEIVER
        IsEqualGUID( pguidDemodulator, &KSNODE_BDA_QPSK_DEMODULATOR) ||
//#elif CABLE_RECEIVER
        IsEqualGUID( pguidDemodulator, &KSNODE_BDA_QAM_DEMODULATOR))
//#endif
    {
        m_NewResource.guidDemodulator = *pguidDemodulator;
        m_BdaChangeState = BDA_CHANGES_PENDING;
    }
    else
    {
        Status = STATUS_NOT_SUPPORTED;
    }

    return Status;
}


/*
** GetStatus() method of the CFilter class
**
**    Gets the current device status for this filter instance.
**
*/
NTSTATUS
CFilter::GetStatus(
    PBDATUNER_DEVICE_STATUS     pDeviceStatus
    )
{
    if (m_KsState == KSSTATE_STOP)
    {
        //  If we're in stop state then the device status
        //  doesn't reflect our resource list.
        //
        pDeviceStatus->fCarrierPresent = FALSE;
        pDeviceStatus->fSignalLocked = FALSE;
        return STATUS_SUCCESS;
    }
    else
    {
        ASSERT( m_pDevice);
        return m_pDevice->GetStatus( pDeviceStatus);
    }
};


/*
** AcquireResources() method of the CFilter class
**
**    Acquires resources for the underlying device.
**
*/
NTSTATUS
CFilter::AcquireResources(
    )
{
    NTSTATUS        Status = STATUS_SUCCESS;

    if (m_fResourceAcquired)
    {
        Status = m_pDevice->UpdateResources(
                                &m_CurResource,
                                m_ulResourceID
                                );
    }
    else
    {
        //  Commit the resources on the underlying device
        //
        Status = m_pDevice->AcquireResources(
                                &m_CurResource,
                                &m_ulResourceID
                                );
        m_fResourceAcquired = NT_SUCCESS( Status);
    }
    
    return Status;
}


/*
** ReleaseResources() method of the CFilter class
**
**    Releases resources from the underlying device.
**
*/
NTSTATUS
CFilter::ReleaseResources(
    )
{
    NTSTATUS        Status = STATUS_SUCCESS;

    //  Release the resources on the underlying device
    //
    if (m_fResourceAcquired)
    {
        Status = m_pDevice->ReleaseResources(
                                m_ulResourceID
                                );
        m_ulResourceID = 0;
        m_fResourceAcquired = FALSE;
    }

    return Status;
}

NTSTATUS
CFilter::PutFrequency(
    IN ULONG        ulBdaParameter
    )
{
    DbgPrint( "CFilter::PutFrequency %d\n", ulBdaParameter);
    m_NewResource.ulCarrierFrequency = ulBdaParameter;
    m_BdaChangeState = BDA_CHANGES_PENDING;

    return STATUS_SUCCESS;
}

NTSTATUS
CFilter::GetFrequency(
    IN PULONG        pulBdaParameter
    )
{
    *pulBdaParameter = m_CurResource.ulCarrierFrequency;
    
    return STATUS_SUCCESS;
}

NTSTATUS
CFilter::PutMultiplier(
    IN ULONG ulBdaParameter
    )
{
    DbgPrint( "CFilter::PutMultiplier %d\n", ulBdaParameter);
    m_NewResource.ulFrequencyMultiplier = ulBdaParameter;
    m_BdaChangeState = BDA_CHANGES_PENDING;

    return STATUS_SUCCESS;
}

NTSTATUS
CFilter::GetMultiplier(
    IN PULONG        pulBdaParameter
    )
{
    *pulBdaParameter = m_CurResource.ulFrequencyMultiplier;
     return STATUS_SUCCESS;
}

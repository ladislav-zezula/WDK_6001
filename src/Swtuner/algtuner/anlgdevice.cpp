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

/***************************************************************************
    File    : device.cpp
    Abstract: Contains the driver entry and dispatch routines for the device
****************************************************************************/
#include "device.h"

extern "C"
NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPathName
    )

{
    NTSTATUS    Status = STATUS_SUCCESS;

    _DbgPrintF(DEBUGLVL_VERBOSE,("DriverEntry"));
    Status = KsInitializeDriver( DriverObject,
                                 RegistryPathName,
                                 &DeviceDescriptor);
    return Status;
}


STDMETHODIMP_(NTSTATUS)
Create(
    IN PKSDEVICE Device
    )
{
    NTSTATUS    Status = STATUS_SUCCESS;
    return Status;
}


STDMETHODIMP_(NTSTATUS)
Start(
    IN PKSDEVICE            pKSDevice,
    IN PIRP                 pIrp,
    IN PCM_RESOURCE_LIST    pTranslatedResourceList OPTIONAL,
    IN PCM_RESOURCE_LIST    pUntranslatedResourceList OPTIONAL
    )
{
    NTSTATUS            Status = STATUS_SUCCESS;
    PKSFILTERFACTORY    pKSFilterFactory = NULL;

    ASSERT( pKSDevice);

    return Status;
}



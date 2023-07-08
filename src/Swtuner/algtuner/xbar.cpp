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
    File    : xbar.cpp
    Abstract: Contains dispatch routines, property handlers and intersect
              handlers for the Crossbar Filter
**************************************************************************/

#include "xbar.h"
NTSTATUS XBarFilterCreate(IN PKSFILTER Filter, IN PIRP Irp) 
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
    BOOL pPinDirection[4] = {FALSE, FALSE, TRUE, TRUE};
    KSPIN_MEDIUM pMediumList[4] = 
    {
	{
	    GUID_AnlgTunerPinMediumVideoOut, 0, 0
	},
	{
	    GUID_TVAudioPinMediumAudioOut, 0, 0
	},	
	{
	    GUID_XBarPinMediumVideoOut, 0, 0
	},
	{
	    GUID_XBarPinMediumAudioOut, 0, 0
	}
    };
    
    Status = KsRegisterFilterWithNoKSPins(
                 pKsDevice->PhysicalDeviceObject,
		 &KSCATEGORY_CROSSBAR,
		 4,
		 pPinDirection,
		 pMediumList,
		 NULL
		 );

    return Status;

}

NTSTATUS XBarFilterClose(IN PKSFILTER Filter, IN PIRP Irp)
{
    return STATUS_SUCCESS;
}


NTSTATUS XBarPinInfoGetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_CROSSBAR_PININFO_S pRequest,
    IN OUT PKSPROPERTY_CROSSBAR_PININFO_S pData
) {
    if (pRequest->Direction == KSPIN_DATAFLOW_IN) {
	if (pRequest->Index == 1) {
	    pData->Medium = PinMediumAudioIn;
	    pData->PinType = KS_PhysConn_Audio_Tuner;
	}
	if (pRequest->Index == 0) {
	    pData->Medium = PinMediumVideoIn;
	    pData->PinType = KS_PhysConn_Video_Tuner;
	}
    }
    if (pRequest->Direction == KSPIN_DATAFLOW_OUT) {
	if (pRequest->Index == 1) {
	    pData->Medium = PinMediumAudioOut;
	    pData->PinType = KS_PhysConn_Audio_Tuner;
	}
	if (pRequest->Index == 0) {
	    pData->Medium = PinMediumVideoOut;
	    pData->PinType = KS_PhysConn_Video_Tuner;
	}
    }
    return STATUS_SUCCESS;

}

NTSTATUS XBarCapsGetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_CROSSBAR_CAPS_S pRequest,
    IN OUT PKSPROPERTY_CROSSBAR_CAPS_S pData
 ) {

    pData->NumberOfInputs = 2;
    pData->NumberOfOutputs = 2;

    return STATUS_SUCCESS;
}


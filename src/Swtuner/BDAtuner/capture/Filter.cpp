/**************************************************************************

    AVStream Simulated Hardware Sample

    Copyright (c) Microsoft Corporation.  All rights reserved.

    File:

        filter.cpp

    Abstract:

        This file contains the filter level implementation for the 
        capture filter.

    History:

        created 3/12/2001

**************************************************************************/

/**************************************************************************

    PAGEABLE CODE

**************************************************************************/

#include "bdacap.h"
#ifdef ALLOC_PRAGMA
#pragma code_seg("PAGE")
#endif // ALLOC_PRAGMA

NTSTATUS
CCaptureFilter::
DispatchCreate (
    IN PKSFILTER Filter,
    IN PIRP Irp
    )

/*++

Routine Description:

    This is the creation dispatch for the capture filter.  It creates
    the CCaptureFilter object, associates it with the AVStream filter
    object, and bag the CCaptureFilter for later cleanup.

Arguments:

    Filter -
        The AVStream filter being created

    Irp -
        The creation Irp

Return Value:
    
    Success / failure

--*/

{

    PAGED_CODE();

    NTSTATUS Status = STATUS_SUCCESS;

    CCaptureFilter *CapFilter = new (NonPagedPool, 'RysI') CCaptureFilter (Filter);

    if (!CapFilter) {
        //
        // Return failure if we couldn't create the filter.
        //
        Status = STATUS_INSUFFICIENT_RESOURCES;

    } else {
        //
        // Add the item to the object bag if we we were successful. 
        // Whenever the filter closes, the bag is cleaned up and we will be
        // freed.
        //
        Status = KsAddItemToObjectBag (
            Filter -> Bag,
            reinterpret_cast <PVOID> (CapFilter),
            reinterpret_cast <PFNKSFREE> (CCaptureFilter::Cleanup)
            );

        if (!NT_SUCCESS (Status)) {
            delete CapFilter;
        } else {
            Filter -> Context = reinterpret_cast <PVOID> (CapFilter);
        }

    }

    return Status;
}

NTSTATUS 
CCaptureFilter::ProcessFrequencyFromTuner(
    IN PIRP pIrp,
    IN PKSPROPERTY_CAPNODE_FREQUENCY_S pRequest,
    IN OUT PKSPROPERTY_CAPNODE_FREQUENCY_S pData
)
{
    PAGED_CODE();

    // Make sure that we received correct property request
    if( !IsEqualGUID( KSNAME_CaptureNodePropertySet, pRequest->Property.Set ) )
        return STATUS_NOT_IMPLEMENTED;

    if( pRequest->Property.Id != KSPROPERTY_CAPTURENODE_SETFREQ )
        return STATUS_INVALID_PARAMETER;

    // Get the filter this property corresponds to
    ASSERT(pIrp);
    PKSFILTER pKsFilter = KsGetFilterFromIrp( pIrp );
    if( pKsFilter == NULL )
        return STATUS_INVALID_PARAMETER;

    PKSDEVICE Device = KsFilterGetDevice(pKsFilter);
    CCaptureDevice* pDevice = reinterpret_cast<CCaptureDevice *>(Device->Context);

    NTSTATUS ntStatus = STATUS_SUCCESS;

    if( pRequest->Property.Flags & KSPROPERTY_TYPE_SET )
        ntStatus = pDevice->SetFrequency( &pRequest->Frequency );
    else
    {
        ULONG ulSize = IoGetCurrentIrpStackLocation( pIrp )->Parameters.DeviceIoControl.OutputBufferLength;
        if( ulSize < sizeof( KSPROPERTY_CAPNODE_FREQUENCY_S ) )
            ntStatus = STATUS_BUFFER_TOO_SMALL;
        else
        {
            pRequest->Frequency = pDevice->Get_theFrequency();
            pIrp->IoStatus.Information = sizeof( KSPROPERTY_CAPNODE_FREQUENCY_S );
        }
    }
    return ntStatus;
}

NTSTATUS 
CCaptureFilter::ProcessFileName(
    IN PIRP pIrp,
    IN PKSPROPERTY_CAPNODE_FILENAME_S pRequest,
    IN OUT PKSPROPERTY_CAPNODE_FILENAME_S pData
)
{
    PAGED_CODE();

    // Make sure that we received correct property request
    if( !IsEqualGUID( KSNAME_CaptureNodePropertySet, pRequest->Property.Set ) )
        return STATUS_NOT_IMPLEMENTED;

    if( pRequest->Property.Id != KSPROPERTY_CAPTURENODE_SETFILENAME )
        return STATUS_INVALID_PARAMETER;

    // Get the filter this property corresponds to
    ASSERT(pIrp);
    PKSFILTER pKsFilter = KsGetFilterFromIrp( pIrp );
    if( pKsFilter == NULL )
        return STATUS_INVALID_PARAMETER;

    PKSDEVICE Device = KsFilterGetDevice(pKsFilter);
    CCaptureDevice* pDevice = reinterpret_cast<CCaptureDevice *>(Device->Context);

    NTSTATUS ntStatus = STATUS_SUCCESS;

    if( pRequest->Property.Flags & KSPROPERTY_TYPE_SET )
	{
//        ntStatus = pDevice->SetFrequency( &pRequest->Frequency );
	}
    else
    {
        ULONG ulSize = IoGetCurrentIrpStackLocation( pIrp )->Parameters.DeviceIoControl.OutputBufferLength;
        if( ulSize < sizeof( KSPROPERTY_CAPNODE_FILENAME_S ) )
            ntStatus = STATUS_BUFFER_TOO_SMALL;
        else
        {
            pIrp->IoStatus.Information = sizeof( KSPROPERTY_CAPNODE_FILENAME_S );
        }
    }
    return ntStatus;
}
/**************************************************************************

    DESCRIPTOR AND DISPATCH LAYOUT

**************************************************************************/

GUID g_PINNAME_VIDEO_CAPTURE = {STATIC_PINNAME_VIDEO_CAPTURE};

//
// CaptureFilterCategories:
//
// The list of category GUIDs for the capture filter.
//
const
GUID
CaptureFilterCategories [CAPTURE_FILTER_CATEGORIES_COUNT] = {
    STATICGUIDOF (KSCATEGORY_BDA_RECEIVER_COMPONENT)
};


//  Medium GUIDs for the Transport Output Pin.
//
//  This insures contection to the correct Capture Filter pin.
//
// {60FAB82F-D605-4A33-A099-D809A08B7F71}
#define GUID_BdaSWRcv   0x60FAB82F,  0xD605, 0x4A33, 0xA0, 0x99, 0xD8, 0x09, 0xA0, 0x8B, 0x7F, 0x71

const KSPIN_MEDIUM TransportPinMedium =
{
    GUID_BdaSWRcv, 0, 0
};


//
//  BDA Sample Tune Frequency Filter
//
//  Define dispatch routines for specific properties.
//
//  One property is used to get and set the tuner's center frequency. 
//  For this property, define dispatch routines to get and set the frequency.
//
//  Other properties can be used to get and set the tuner's frequency range,
//  as well as to report signal strength.
//
//  These properties must be supported by BDA and 
//  defined elsewhere (for example, in Bdamedia.h).
//
DEFINE_KSPROPERTY_TABLE(SampleTunerNodeFrequencyProperties)
{
    DEFINE_KSPROPERTY_ITEM_BDA_RF_TUNER_FREQUENCY(
        CCapturePin::GetCenterFrequency,
        CCapturePin::PutCenterFrequency
        ),
    DEFINE_KSPROPERTY_ITEM_BDA_RF_TUNER_FREQUENCY_MULTIPLIER(
        NULL, NULL
        ),

#ifdef SATELLITE_TUNER
    DEFINE_KSPROPERTY_ITEM_BDA_RF_TUNER_POLARITY(
        NULL, NULL
        ),
    DEFINE_KSPROPERTY_ITEM_BDA_RF_TUNER_RANGE(
        NULL, NULL
        ),
#endif // SATELLITE_TUNER

#ifdef CHANNEL_BASED_TUNER
    DEFINE_KSPROPERTY_ITEM_BDA_RF_TUNER_TRANSPONDER(
        NULL, NULL
        ),
#endif // CHANNEL_BASED_TUNER

#ifdef DVBT_TUNER
    DEFINE_KSPROPERTY_ITEM_BDA_RF_TUNER_BANDWIDTH(
        NULL, NULL
        ),
#endif // DVBT_TUNER
};

//  Define the Property Sets for the sample tuner node from the 
//  previously defined node properties and from property sets
//  that BDA supports.
//  These supported property sets must be defined elsewhere 
//  (for example, in Bdamedia.h).
//
//  Associate the sample tuner node with the antenna input pin. 
//
DEFINE_KSPROPERTY_SET_TABLE(SampleTunerNodePropertySets)
{
    DEFINE_KSPROPERTY_SET
    (
        &KSPROPSETID_BdaFrequencyFilter,    // Property Set defined elsewhere
        SIZEOF_ARRAY(SampleTunerNodeFrequencyProperties),  // Number of properties in the array
        SampleTunerNodeFrequencyProperties,  // Property set array
        0,      // FastIoCount
        NULL    // FastIoTable
    ),
};


//
//  Define the Automation Table for the BDA sample tuner node.
//
DEFINE_KSAUTOMATION_TABLE(SampleTunerNodeAutomation) {
    DEFINE_KSAUTOMATION_PROPERTIES(SampleTunerNodePropertySets),
    DEFINE_KSAUTOMATION_METHODS_NULL,
    DEFINE_KSAUTOMATION_EVENTS_NULL
};

//
// CaptureFilterPinDescriptors:
//
// The list of pin descriptors on the capture filter.  
//
const 
KSPIN_DESCRIPTOR_EX
CaptureFilterPinDescriptors [CAPTURE_FILTER_PIN_COUNT] = {
    //
    // Capture Input Pin
    //
    {
        &InputPinDispatch,
        &SampleTunerNodeAutomation, //NULL,             
        {
            NULL,                           // Interfaces (NULL, 0 == default)
            0,
            1,  // Mediums
            &TransportPinMedium,
            SIZEOF_ARRAY (CaptureInPinDataRanges), // Range Count
            CaptureInPinDataRanges,           // Ranges
            KSPIN_DATAFLOW_IN,              // Dataflow
            KSPIN_COMMUNICATION_BOTH,       // Communication
            NULL,         // Category
            NULL,         // Name
            0                               // Reserved
        },
        
        KSPIN_FLAG_DO_NOT_USE_STANDARD_TRANSPORT | 
        KSPIN_FLAG_FRAMES_NOT_REQUIRED_FOR_PROCESSING | 
        KSPIN_FLAG_FIXED_FORMAT,
        1,      // InstancesPossible
        1,      // InstancesNecessary
        NULL,   // Allocator Framing
        NULL    // PinIntersectHandler
    },

    //
    // Capture Output Pin
    //
    {
        &CapturePinDispatch,
        NULL,             
        {
            NULL,                           // Interfaces (NULL, 0 == default)
            0,
            NULL,                           // Mediums (NULL, 0 == default)
            0,
            SIZEOF_ARRAY (CaptureOutPinDataRanges), // Range Count
            CaptureOutPinDataRanges,           // Ranges
            KSPIN_DATAFLOW_OUT,             // Dataflow
            KSPIN_COMMUNICATION_BOTH,       // Communication
            NULL,         // Category
            NULL,         // Name
            0                               // Reserved
        },
        
#if !defined(_BUILD_SW_TUNER_ON_X64)
        KSPIN_FLAG_GENERATE_MAPPINGS |      // Pin Flags
#endif
        KSPIN_FLAG_PROCESS_IN_RUN_STATE_ONLY,
        1,                                  // Instances Possible
        1,                                  // Instances Necessary
        &CapturePinAllocatorFraming,        // Allocator Framing
        NULL                                // Format Intersect Handler
    }
    
};

//
// CaptureFilterDispatch:
//
// This is the dispatch table for the capture filter.  It provides notification
// of creation, closure, processing (for filter-centrics, not for the capture
// filter), and resets (for filter-centrics, not for the capture filter).
//
const 
KSFILTER_DISPATCH
CaptureFilterDispatch = {
    CCaptureFilter::DispatchCreate,         // Filter Create
    NULL,                                   // Filter Close
    NULL,                                   // Filter Process
    NULL                                    // Filter Reset
};

//
//  Define the name GUID for our digital capture filter.
//
//  NOTE!  You must use a different GUID for each type of filter that
//  your driver exposes.
//
#define STATIC_KSNAME_BdaSWCaptureFilter\
    074649feL, 0x2dd8, 0x4c12, 0x8a, 0x23, 0xbd, 0x82, 0x8b, 0xad, 0xff, 0xfa
DEFINE_GUIDSTRUCT("074649FE-2DD8-4C12-8A23-BD828BADFFFA", KSNAME_BdaSWCaptureFilter);
#define KSNAME_BdaSWCaptureFilter DEFINE_GUIDNAMED(KSNAME_BdaSWCaptureFilter)


//  Must match the KSSTRING used in the installation INFs interface sections
//  AND must match the KSNAME GUID above.
//
#define KSSTRING_BdaSWCaptureFilter L"{074649FE-2DD8-4C12-8A23-BD828BADFFFA}"

// Create a connection through the capture filter so that graph render will
// work.
//
const
KSTOPOLOGY_CONNECTION FilterConnections[] =
{   // KSFILTER_NODE  is defined as ((ULONG)-1) in ks.h 
    { KSFILTER_NODE, 0,                 KSFILTER_NODE, 1 }
};

DEFINE_KSPROPERTY_TABLE(SampleCaptureNodeSetFrequencyProperties)
{
	DEFINE_KSPROPERTY_ITEM								
	(

		KSPROPERTY_CAPTURENODE_SETFREQ,						// Property
		CCaptureFilter::ProcessFrequencyFromTuner,					// Get Handler
		sizeof(KSPROPERTY_CAPNODE_FREQUENCY_S),		    // MinProperty
		sizeof(KSPROPERTY_CAPNODE_FREQUENCY_S),			// MinData
		CCaptureFilter::ProcessFrequencyFromTuner,					// Set Handler
		NULL,											// Values
		0,												// RelationsCount
		NULL,											// Relations
		NULL,											// SupportHandler
		0									            // SerializedSize
        ),
	DEFINE_KSPROPERTY_ITEM								
	(

		KSPROPERTY_CAPTURENODE_SETFILENAME,						// Property
		CCaptureFilter::ProcessFileName,					// Get Handler
		sizeof(KSPROPERTY_CAPNODE_FILENAME_S),		    // MinProperty
		sizeof(KSPROPERTY_CAPNODE_FILENAME_S),			// MinData
		CCaptureFilter::ProcessFileName,					// Set Handler
		NULL,											// Values
		0,												// RelationsCount
		NULL,											// Relations
		NULL,											// SupportHandler
		0									            // SerializedSize
        )
};

DEFINE_KSPROPERTY_SET_TABLE(SampleCaptureNodePropertySets)
{
    DEFINE_KSPROPERTY_SET
    (
        &KSNAME_CaptureNodePropertySet,    // Property Set defined elsewhere
        SIZEOF_ARRAY(SampleCaptureNodeSetFrequencyProperties),  // Number of properties in the array
        SampleCaptureNodeSetFrequencyProperties,  // Property set array
        0,      // FastIoCount
        NULL    // FastIoTable
    ),
};

DEFINE_KSAUTOMATION_TABLE(SampleCaptureNodeAutomation) {
    DEFINE_KSAUTOMATION_PROPERTIES(SampleCaptureNodePropertySets),
    DEFINE_KSAUTOMATION_METHODS_NULL,
    DEFINE_KSAUTOMATION_EVENTS_NULL
};


//
// CaptureFilterDescription:
//
// The descriptor for the capture filter.
//
const 
KSFILTER_DESCRIPTOR 
CaptureFilterDescriptor = {
    &CaptureFilterDispatch,                 // Dispatch Table
    &SampleCaptureNodeAutomation,                                   // Automation Table
    KSFILTER_DESCRIPTOR_VERSION,            // Version
    0,                                      // Flags
    &KSNAME_BdaSWCaptureFilter,             // Reference GUID

    // Pin Descriptor Table
    //
    // PinDescriptorsCount; exposes all template pins 
    // PinDescriptorSize; size of each item
    // PinDescriptors; table of pin descriptors
    //
    DEFINE_KSFILTER_PIN_DESCRIPTORS (CaptureFilterPinDescriptors),

    // Category Table
    //
    // CategoriesCount; number of categories in the table
    // Categories; table of categories
    //
    DEFINE_KSFILTER_CATEGORIES (CaptureFilterCategories),

    //  Node Descriptor Table
    //
    // NodeDescriptorsCount; exposes all template nodes
    // NodeDescriptorSize; size of each item
    // NodeDescriptors; table of node descriptors
    //
    0,
    sizeof (KSNODE_DESCRIPTOR),
    NULL,

    //  Filter connection table
    //
    // ConnectionsCount; number of connections in the table
    // Connections; table of connections
    //
    DEFINE_KSFILTER_CONNECTIONS(FilterConnections), 

    NULL                                    // Component ID
};




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
    File    : anlgcapture.cpp
    Abstract: Contains dispatch routines, property handlers and intersect
              handlers for the Analog Capture Filter
**************************************************************************/

#include "anlgcapture.h"
NTSTATUS AnlgCaptureFilterCreate(IN PKSFILTER Filter, IN PIRP Irp) 
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
    BOOL pPinDirection[5] = {FALSE, FALSE, TRUE, TRUE, TRUE};
    KSPIN_MEDIUM pMediumList[5] = 
    {
	{
	    GUID_XBarPinMediumVideoOut, 0, 0
	},
	{
	    GUID_XBarPinMediumAudioOut, 0, 0
	},
	{
	    GUID_AnlgCapturePinMediumVideoOut, 0, 0
	},
	{
	    GUID_AnlgCapturePinMediumAudioOut, 0, 0
	},
	{
	    GUID_AnlgCapturePinMediumVBIOut, 0, 0
	}
    };
    
    GUID pCategoryList[5]; 
    pCategoryList[0] = PINNAME_VIDEO_CAPTURE;
    pCategoryList[1] = PINNAME_VIDEO_CAPTURE;
    pCategoryList[2] = PINNAME_VIDEO_CAPTURE;
    pCategoryList[3] = PINNAME_VIDEO_CAPTURE;
    pCategoryList[4] = PINNAME_VIDEO_CAPTURE;


    Status = KsRegisterFilterWithNoKSPins(
                 pKsDevice->PhysicalDeviceObject,
		 &KSCATEGORY_VIDEO,
		 5,
		 pPinDirection,
		 pMediumList,
		 pCategoryList
		 );

    if(!NT_SUCCESS(Status))
    {
	return Status;
    }

    return Status;

}

NTSTATUS AnlgCaptureFilterClose(IN PKSFILTER Filter, IN PIRP Irp)
{
    return STATUS_SUCCESS;
}


NTSTATUS VideoInIntersectDataFormat(
        IN PVOID pContext,
        IN PIRP pIrp,
        IN PKSP_PIN Pin,
        IN PKSDATARANGE DataRange,
        IN PKSDATARANGE MatchingDataRange,
        IN ULONG DataBufferSize,
        OUT PVOID Data OPTIONAL,
        OUT PULONG DataSize
) {

    if ( DataBufferSize == 0)
    {
        *DataSize = sizeof( KS_DATARANGE_ANALOGVIDEO);
		return STATUS_BUFFER_OVERFLOW;
    } 

	PKS_DATARANGE_ANALOGVIDEO DataRangeVideo =
	(PKS_DATARANGE_ANALOGVIDEO) DataRange;
    
    if (DataRange -> FormatSize < sizeof (KS_DATARANGE_ANALOGVIDEO)) 
    {
	return STATUS_NO_MATCH;
    } 
    
    RtlCopyMemory(
		  Data,
		  DataRangeVideo,
		  sizeof (KS_DATARANGE_ANALOGVIDEO));
    *DataSize = sizeof(KS_DATARANGE_ANALOGVIDEO);
    
    return STATUS_SUCCESS;
}


NTSTATUS AudioInIntersectDataFormat(
        IN PVOID pContext,
        IN PIRP pIrp,
        IN PKSP_PIN Pin,
        IN PKSDATARANGE DataRange,
        IN PKSDATARANGE MatchingDataRange,
        IN ULONG DataBufferSize,
        OUT PVOID Data OPTIONAL,
        OUT PULONG DataSize
) {

    if ( DataBufferSize == 0)
    {
        *DataSize = sizeof( KSDATARANGE_AUDIO);
		return STATUS_BUFFER_OVERFLOW;
    } 

   PKSDATARANGE_AUDIO DataRangeAudio =
	(PKSDATARANGE_AUDIO) DataRange;
    
    if (DataRange -> FormatSize < sizeof (KSDATARANGE_AUDIO)) 
    {
	return STATUS_NO_MATCH;
    } 
    
    RtlCopyMemory(
		  Data,
		  DataRangeAudio,
		  sizeof (KSDATARANGE_AUDIO));
    *DataSize = sizeof(KSDATARANGE_AUDIO);
    
    return STATUS_SUCCESS;
}


static
NTSTATUS
VideoOutIntersectDataFormat(
    IN PVOID piKSFilter,                    //Pointer to KS filter structure.
    IN PIRP pIrp,                           //Pointer to data intersection
                                            //property request.
    IN PKSP_PIN pPinInstance,               //Pinter to structure indicating
                                            //pin in question.
    IN PKSDATARANGE pCallerDataRange,       //Pointer to the caller data
                                            //structure that should be
                                            //intersected.
    IN PKSDATARANGE pDescriptorDataRange,   //Pointer to the descriptor data

    IN DWORD dwBufferSize,                  //Size in bytes of the target
                                            //buffer structure. For size
                                            //queries, this value will be zero.
    OUT OPTIONAL PVOID pData,               //Pointer to the target data
                                            //structure representing the best
                                            //format in the intersection.
    OUT PDWORD pdwDataSize                  //Pointer to size of target data
                                            //format structure.
     )
{

	PKSFILTER pKSFilter = (PKSFILTER) piKSFilter;

	//invalid parameters?
    if( !pKSFilter || !pIrp || !pPinInstance ||
        !pCallerDataRange || !pDescriptorDataRange || !pdwDataSize )
    {
        return STATUS_UNSUCCESSFUL;
    }

    NTSTATUS Status = STATUS_UNSUCCESSFUL;

    //set output data size
    if (IsEqualGUID(pDescriptorDataRange->Specifier,
		    KSDATAFORMAT_SPECIFIER_VIDEOINFO)) {    

        //*** start intersection ***//

        //check if given datarange GUID matches to our datarange information
        if( pCallerDataRange->FormatSize != sizeof(KS_DATARANGE_VIDEO) )
        {
            return STATUS_NO_MATCH;
        }

        //map given data ranges on video information structures
        //for some reason only a subpart of the KS_DATARANGE_VIDEO is used for intersection
        //this subpart is casted to KS_DATAFORMAT_VIDEOINFOHEADER and contains only
        //KSDATAFORMAT and KS_VIDEOINFOHEADER, see pTargetVideoDataRange
        PKS_DATARANGE_VIDEO pCallerVideoDataRange =
            reinterpret_cast <PKS_DATARANGE_VIDEO> (pCallerDataRange);
        PKS_DATARANGE_VIDEO pDescriptorVideoDataRange =
            reinterpret_cast <PKS_DATARANGE_VIDEO> (pDescriptorDataRange);
        PKS_DATAFORMAT_VIDEOINFOHEADER pTargetVideoDataRange =
            reinterpret_cast <PKS_DATAFORMAT_VIDEOINFOHEADER> (pData);

        //check if all other important fields match
        if( pCallerVideoDataRange->bFixedSizeSamples        !=
                pDescriptorVideoDataRange->bFixedSizeSamples        ||
            pCallerVideoDataRange->bTemporalCompression     !=
                pDescriptorVideoDataRange->bTemporalCompression     ||
            pCallerVideoDataRange->StreamDescriptionFlags   !=
                pDescriptorVideoDataRange->StreamDescriptionFlags   ||
            pCallerVideoDataRange->MemoryAllocationFlags    !=
                pDescriptorVideoDataRange->MemoryAllocationFlags    ||

           (RtlCompareMemory(&pCallerVideoDataRange->ConfigCaps,
                             &pDescriptorVideoDataRange->ConfigCaps,
                             sizeof(KS_VIDEO_STREAM_CONFIG_CAPS))) !=
                             sizeof(KS_VIDEO_STREAM_CONFIG_CAPS)    )
        {
            return STATUS_NO_MATCH;
        }

	{
	    ULONG VideoHeaderSize = KS_SIZE_VIDEOHEADER(
		  &pCallerVideoDataRange->VideoInfoHeader
		  );
	    ULONG DataRangeSize = 
		FIELD_OFFSET(KS_DATARANGE_VIDEO, VideoInfoHeader) +
		VideoHeaderSize;
	    if (
		VideoHeaderSize < pCallerVideoDataRange->
		   VideoInfoHeader.bmiHeader.biSize ||
		DataRangeSize < VideoHeaderSize ||
		DataRangeSize > pCallerVideoDataRange->
		   DataRange.FormatSize
		) {
		return STATUS_INVALID_PARAMETER;
	    }
	}

	ULONG FormatSize;
	FormatSize = sizeof(KSDATAFORMAT) + 
	    KS_SIZE_VIDEOHEADER (&pCallerVideoDataRange->VideoInfoHeader);

        *pdwDataSize = FormatSize;

        //check for size only query
        if( dwBufferSize == 0 )
        {
            return STATUS_BUFFER_OVERFLOW;
        }


        //check if output buffer size is sufficient
        if( dwBufferSize < *pdwDataSize )
        {
            return STATUS_BUFFER_TOO_SMALL;
        }

        //copy the data range structure from our decriptor into the target format buffer,
        //for some reason two different names where given to the same structure
        //KSDATARANGE equals exactly KSDATAFORMAT
        pTargetVideoDataRange->DataFormat =
            static_cast <KSDATAFORMAT> (pDescriptorVideoDataRange->DataRange);

        //as mentioned above the target data range structure differs from the
        //caller and the descriptor structures, so the size is also different
        //and has to be set correctly
        pTargetVideoDataRange->DataFormat.FormatSize = *pdwDataSize;

        //copy the video info header structure from the caller into the target
        //buffer,we have to check at this time whether the requested caller
        //video format fits our capabilities (not implemented right now)
	RtlCopyMemory(
	    &pTargetVideoDataRange->VideoInfoHeader,
	    &pCallerVideoDataRange->VideoInfoHeader,
	    KS_SIZE_VIDEOHEADER (&pCallerVideoDataRange->VideoInfoHeader));

        //If there is a format change (e.g. a new resolution) the size is not updated
        //automatically, so we have to calculate it here. There is a macro that multiplies
        //the width and height and that also aligns the size to DWORDs
        pTargetVideoDataRange->VideoInfoHeader.bmiHeader.biSizeImage =
            pTargetVideoDataRange->DataFormat.SampleSize =
            KS_DIBSIZE(pTargetVideoDataRange->VideoInfoHeader.bmiHeader);

        Status = STATUS_SUCCESS;
    } else if (IsEqualGUID(pDescriptorDataRange->Specifier,
	     KSDATAFORMAT_SPECIFIER_VIDEOINFO2)) {

        //*** start intersection ***//

        //check if given datarange GUID matches to our datarange information
        if( pCallerDataRange->FormatSize != sizeof(KS_DATARANGE_VIDEO2) )
        {
            return STATUS_NO_MATCH;
        }

        //map given data ranges on video information structures
        //for some reason only a subpart of the KS_DATARANGE_VIDEO is
        //used for intersection this subpart is casted to
        //KS_DATAFORMAT_VIDEOINFOHEADER and contains only
        //KSDATAFORMAT and KS_VIDEOINFOHEADER, see pTargetVideoDataRange
        PKS_DATARANGE_VIDEO2 pCallerVideoDataRange =
            reinterpret_cast <PKS_DATARANGE_VIDEO2> (pCallerDataRange);
        PKS_DATARANGE_VIDEO2 pDescriptorVideoDataRange =
            reinterpret_cast <PKS_DATARANGE_VIDEO2> (pDescriptorDataRange);
        PKS_DATAFORMAT_VIDEOINFOHEADER2 pTargetVideoDataRange =
            reinterpret_cast <PKS_DATAFORMAT_VIDEOINFOHEADER2> (pData);

        //check if all other important fields match
        if( pCallerVideoDataRange->bFixedSizeSamples        !=
                pDescriptorVideoDataRange->bFixedSizeSamples        ||
            pCallerVideoDataRange->bTemporalCompression     !=
                pDescriptorVideoDataRange->bTemporalCompression     ||
            pCallerVideoDataRange->StreamDescriptionFlags   !=
                pDescriptorVideoDataRange->StreamDescriptionFlags   ||
            pCallerVideoDataRange->MemoryAllocationFlags    !=
                pDescriptorVideoDataRange->MemoryAllocationFlags    ||

           (RtlCompareMemory(&pCallerVideoDataRange->ConfigCaps,
                             &pDescriptorVideoDataRange->ConfigCaps,
                             sizeof(KS_VIDEO_STREAM_CONFIG_CAPS))) !=
                             sizeof(KS_VIDEO_STREAM_CONFIG_CAPS)    )
        {
            return STATUS_NO_MATCH;
        }

	{
	    ULONG VideoHeaderSize = KS_SIZE_VIDEOHEADER(
		  &pCallerVideoDataRange->VideoInfoHeader
		  );
	    ULONG DataRangeSize = 
		FIELD_OFFSET(KS_DATARANGE_VIDEO, VideoInfoHeader) +
		VideoHeaderSize;
	    if (
		VideoHeaderSize < pCallerVideoDataRange->
		   VideoInfoHeader.bmiHeader.biSize ||
		DataRangeSize < VideoHeaderSize ||
		DataRangeSize > pCallerVideoDataRange->
		   DataRange.FormatSize
		) {
		return STATUS_INVALID_PARAMETER;
	    }
	}

	ULONG FormatSize;
	FormatSize = sizeof(KSDATAFORMAT) + 
	    KS_SIZE_VIDEOHEADER (&pCallerVideoDataRange->VideoInfoHeader);


        *pdwDataSize = FormatSize;

        //check for size only query
        if( dwBufferSize == 0 )
        {
            return STATUS_BUFFER_OVERFLOW;
        }

        //check if output buffer size is sufficient
        if( dwBufferSize < *pdwDataSize )
        {
            return STATUS_BUFFER_TOO_SMALL;
        }

        //copy the data range structure from our decriptor into the target
        //format buffer, for some reason two different names where given
        //to the same structure KSDATARANGE equals exactly KSDATAFORMAT
        pTargetVideoDataRange->DataFormat =
            static_cast <KSDATAFORMAT> (pDescriptorVideoDataRange->DataRange);
        //as mentioned above the target data range structure differs from the
        //caller and the descriptor structures, so the size is also different
        //and has to be set correctly
        pTargetVideoDataRange->DataFormat.FormatSize = *pdwDataSize;

        //copy the video info header structure from the caller into the target
        //buffer, we have to check at this time whether the requested caller
        //video formatfits our capabilities (not implemented right now)
	RtlCopyMemory(
	    &pTargetVideoDataRange->VideoInfoHeader2,
	    &pCallerVideoDataRange->VideoInfoHeader,
	    KS_SIZE_VIDEOHEADER (&pCallerVideoDataRange->VideoInfoHeader));

        //If there is a format change (e.g. a new resolution) the size is
        //not updated automatically, so we have to calculate it here.
        //There is a macro that multiplies the width and height and that
        //also aligns the size to DWORDs
        pTargetVideoDataRange->VideoInfoHeader2.bmiHeader.biSizeImage =
            pTargetVideoDataRange->DataFormat.SampleSize =
            KS_DIBSIZE(pTargetVideoDataRange->VideoInfoHeader2.bmiHeader);

        Status = STATUS_SUCCESS;
    } else {
	*pdwDataSize = 0;
	Status = STATUS_NO_MATCH;
    }

    return Status;
}


static
NTSTATUS
AudioOutIntersectDataFormat (
    IN PVOID pContext,
    IN PIRP Irp,
    IN PKSP_PIN PinInstance,
    IN PKSDATARANGE CallerDataRange,
    IN PKSDATARANGE DescriptorDataRange,
    IN ULONG BufferSize,
    OUT PVOID Data OPTIONAL,
    OUT PULONG DataSize
    )

/*++

Routine Description:

    The intersect handler for the audio capture pin.  This is really quite
    simple because the audio pin only exposes the number of channels,
    sampling frequency, etc...  that the wave file it is synthesizing from
    contains.

Arguments:

    Filter -
        Contains a void pointer to the  filter structure.

    Irp -
        Contains a pointer to the data intersection property request.

    PinInstance -
        Contains a pointer to a structure indicating the pin in question.

    CallerDataRange -
        Contains a pointer to one of the data ranges supplied by the client
        in the data intersection request.  The format type, subtype and
        specifier are compatible with the DescriptorDataRange.

    DescriptorDataRange -
        Contains a pointer to one of the data ranges from the pin descriptor
        for the pin in question.  The format type, subtype and specifier are
        compatible with the CallerDataRange.

    BufferSize -
        Contains the size in bytes of the buffer pointed to by the Data
        argument.  For size queries, this value will be zero.

    Data -
        Optionally contains a pointer to the buffer to contain the data 
        format structure representing the best format in the intersection 
        of the two data ranges.  For size queries, this pointer will be 
        NULL.

    DataSize -
        Contains a pointer to the location at which to deposit the size 
        of the data format.  This information is supplied by the function 
        when the format is actually delivered and in response to size 
        queries.

Return Value:

    STATUS_SUCCESS if there is an intersection and it fits in the supplied
    buffer, STATUS_BUFFER_OVERFLOW for successful size queries, 
    STATUS_NO_MATCH if the intersection is empty, or 
    STATUS_BUFFER_TOO_SMALL if the supplied buffer is too small.

--*/


{
    
    PAGED_CODE();

    //
    // Because the only range we expose is such that it will match
    // KSDATARANGE_AUDIO, it is safe to interpret the data structures as
    // KSDATARANGE_AUDIO.  This is due to the fact that AVStream will have
    // prematched the GUIDs for us.
    //
    PKSDATARANGE_AUDIO CallerAudioRange =
        reinterpret_cast <PKSDATARANGE_AUDIO> (CallerDataRange);

    PKSDATARANGE_AUDIO DescriptorAudioRange =
        reinterpret_cast <PKSDATARANGE_AUDIO> (DescriptorDataRange);

    //
    // We are returning a KSDATAFORMAT_WAVEFORMATEX.  Specify such if a size
    // query happens.
    //
    if (BufferSize == 0) {
        *DataSize = sizeof (KSDATAFORMAT_WAVEFORMATEX);
        return STATUS_BUFFER_OVERFLOW;
    }

    if (BufferSize < sizeof (KSDATAFORMAT_WAVEFORMATEX)) {
        return STATUS_BUFFER_TOO_SMALL;
    }

    //
    // Match the blocks.  We only support one format (not really a range), so
    // this intersection aught to be really simple.  It's more of a check
    // if the format we are going to use intersects somewhere in 
    // CallerAudioRange.
    //
    if (DescriptorAudioRange -> MaximumChannels > 
            CallerAudioRange -> MaximumChannels ||
        DescriptorAudioRange -> MinimumBitsPerSample <
            CallerAudioRange -> MinimumBitsPerSample ||
        DescriptorAudioRange -> MinimumBitsPerSample >
            CallerAudioRange -> MaximumBitsPerSample ||
        DescriptorAudioRange -> MinimumSampleFrequency <
            CallerAudioRange -> MinimumSampleFrequency ||
        DescriptorAudioRange -> MinimumSampleFrequency >
            CallerAudioRange -> MaximumSampleFrequency) {

        //
        // If the descriptor's "range" (more of a single format specified
        // in a range) doesn't intersect the caller's, no match the call.
        //
        *DataSize = sizeof (KSDATAFORMAT_WAVEFORMATEX);
        return STATUS_NO_MATCH;

    }

    //
    // Build the format.
    //
    PKSDATAFORMAT_WAVEFORMATEX WaveFormat =
        reinterpret_cast <PKSDATAFORMAT_WAVEFORMATEX> (Data);

    RtlCopyMemory (
        &WaveFormat -> DataFormat,
        &DescriptorAudioRange -> DataRange,
        sizeof (KSDATAFORMAT)
        );

    WaveFormat -> WaveFormatEx.wFormatTag = WAVE_FORMAT_PCM;
    WaveFormat -> WaveFormatEx.nChannels = 
        (WORD)DescriptorAudioRange -> MaximumChannels;
    WaveFormat -> WaveFormatEx.nSamplesPerSec =
        DescriptorAudioRange -> MaximumSampleFrequency;
    WaveFormat -> WaveFormatEx.wBitsPerSample =
        (WORD)DescriptorAudioRange -> MaximumBitsPerSample;
    WaveFormat -> WaveFormatEx.nBlockAlign =
        (WaveFormat -> WaveFormatEx.wBitsPerSample / 8) *
        WaveFormat -> WaveFormatEx.nChannels;
    WaveFormat -> WaveFormatEx.nAvgBytesPerSec =
        WaveFormat -> WaveFormatEx.nBlockAlign *
        WaveFormat -> WaveFormatEx.nSamplesPerSec;
    WaveFormat -> WaveFormatEx.cbSize = 0;
    WaveFormat -> DataFormat.SampleSize = 
        WaveFormat -> WaveFormatEx.nBlockAlign;

    *DataSize = sizeof (KSDATAFORMAT_WAVEFORMATEX);

    return STATUS_SUCCESS;

}

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//  This is the intersect handler for comparison of a data range.
//  of the analog VBI out pin.(Needs no class environment to intersect
//  the format, because the format that is supported is already
//  given in the filter descriptor).
//
// Settings:
//  A match occurs under three conditions:
//  (1) if the major format of the range passed matches a pin factory range,
//  (2) if the sub-format matches,
//  (3) if the specifier is KSDATAFORMAT_SPECIFIER_VBI.
//  Since the data range size may be variable, it is not validated beyond
//  checking that it is at least the size of a data range structure.
//  (KSDATAFORMAT_SPECIFIER_VBI)
//
// Remarks:
//  There is a bug so we always get all formats from the descriptor 
//  even if they do not match with the current video standard detected
//  in the decoder property (see correct handling in the video classes).
//  To set up the right format, we ask the decoder for the current format 
//  and if it does not match to the pCallerDataRange, we return 
//  STATUS_NO_MATCH to get called again with the next format from the 
//  descriptor.
//  If it matches our decoder setting, we write it to the target format
//  pData.
//
// Return Value:
//  STATUS_SUCCESS           If a matching range is found and it fits
//                           in the supplied buffer.
//  STATUS_UNSUCCESSFUL      Operation failed,
//                           the function parameters are zero.
//  STATUS_BUFFER_OVERFLOW   For successful size queries. (in that case
//                           the buffer size is zero and has to be set
//                           to the right value before return)
//  STATUS_BUFFER_TOO_SMALL  If the supplied buffer is too small.
//  STATUS_NO_MATCH             (a) if the intersection is empty, or
//                              (b) if no matching range was found
//
//////////////////////////////////////////////////////////////////////////////
static
NTSTATUS AnlgVBIOutIntersectDataFormat
(
    IN PVOID pvKSFilter,                 //Pointer to KS filter structure.
    IN PIRP      pIrp,                      //Pointer to data intersection
                                            //property request.
    IN PKSP_PIN  pPinInstance,              //Pointer to structure indicating
                                            //pin in question.
    IN PKSDATARANGE pCallerDataRange,       //Pointer to the caller data
                                            //structure that should be
                                            //intersected.
    IN PKSDATARANGE pDescriptorDataRange,   //Pointer to the descriptor data
                                            //structure, see AnlgVbiFormats.h.
    IN ULONG     dwBufferSize,              //Size in bytes of the target
                                            //buffer structure. For size
                                            //queries, this value is zero.
    OUT OPTIONAL PVOID pData,               //Pointer to the target data
                                            //structure representing the best
                                            //format in the intersection.
    OUT PULONG   pdwDataSize                //Pointer to size of target data
                                            //format structure.
)
{

    PKSFILTER pKSFilter;
    pKSFilter = (PKSFILTER) pvKSFilter;

    //invalid parameters?
    if( !pKSFilter || !pIrp || !pPinInstance ||
        !pCallerDataRange || !pDescriptorDataRange || !pdwDataSize )
    {
        return STATUS_UNSUCCESSFUL;
    }
    //set output data size
    *pdwDataSize = sizeof(KS_DATAFORMAT_VBIINFOHEADER);
    //check for size only query
    if( dwBufferSize == 0 )
    {
        //BUGBUG: we have to return "buffer overflow",
        //because this is what is expected on the other side,
        //any other return value will cause a wrong handling of
        //the size parameter
        return STATUS_BUFFER_OVERFLOW;
    }
    //check if output buffer size is sufficient
    if( dwBufferSize < *pdwDataSize )
    {
        return STATUS_BUFFER_TOO_SMALL;
    }

    //*** start intersection ***//

    //check if given datarange GUID matches to VBI
    const GUID VBIInfoSpecifier =
        {STATICGUIDOF(KSDATAFORMAT_SPECIFIER_VBI)};
    if( !IsEqualGUID(pCallerDataRange->Specifier, VBIInfoSpecifier) ||
        pCallerDataRange->FormatSize != sizeof(KS_DATARANGE_VIDEO_VBI) )
    {
        return STATUS_NO_MATCH;
    }

    PKS_DATARANGE_VIDEO_VBI pCallerVbiDataRange =
        reinterpret_cast <PKS_DATARANGE_VIDEO_VBI> (pCallerDataRange);
    PKS_DATARANGE_VIDEO_VBI pDescriptorVbiDataRange =
        reinterpret_cast <PKS_DATARANGE_VIDEO_VBI> (pDescriptorDataRange);
    PKS_DATAFORMAT_VBIINFOHEADER pTargetVbiDataRange =
        reinterpret_cast <PKS_DATAFORMAT_VBIINFOHEADER> (pData);

    //check if all other important fields match
    if(
        (pCallerVbiDataRange->bFixedSizeSamples !=
            pDescriptorVbiDataRange->bFixedSizeSamples) ||
        (pCallerVbiDataRange->bTemporalCompression !=
            pDescriptorVbiDataRange->bTemporalCompression) ||
        (pCallerVbiDataRange->StreamDescriptionFlags !=
            pDescriptorVbiDataRange->StreamDescriptionFlags) ||
        (pCallerVbiDataRange->MemoryAllocationFlags !=
            pDescriptorVbiDataRange->MemoryAllocationFlags)
       )
    {
        return STATUS_NO_MATCH;
    }

    pTargetVbiDataRange->DataFormat =
        static_cast <KSDATAFORMAT> (pDescriptorVbiDataRange->DataRange);

    pTargetVbiDataRange->DataFormat.FormatSize = *pdwDataSize;

    pTargetVbiDataRange->VBIInfoHeader =
            pDescriptorVbiDataRange->VBIInfoHeader;

    return STATUS_SUCCESS;
}


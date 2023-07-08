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
    File    : anlgcapture.h
    Abstract: Contains the pin and filter descriptors for the Analog 
              Capture Filter
**************************************************************************/

#include "common.h"

NTSTATUS AnlgCaptureFilterCreate(IN PKSFILTER Filter, IN PIRP Irp);
NTSTATUS AnlgCaptureFilterClose(IN PKSFILTER Filter, IN PIRP Irp);

static NTSTATUS VideoInIntersectDataFormat(
        IN PVOID pContext,
        IN PIRP pIrp,
        IN PKSP_PIN Pin,
        IN PKSDATARANGE DataRange,
        IN PKSDATARANGE MatchingDataRange,
        IN ULONG DataBufferSize,
        OUT PVOID Data OPTIONAL,
        OUT PULONG DataSize
        );

static NTSTATUS AudioInIntersectDataFormat(
        IN PVOID pContext,
        IN PIRP pIrp,
        IN PKSP_PIN Pin,
        IN PKSDATARANGE DataRange,
        IN PKSDATARANGE MatchingDataRange,
        IN ULONG DataBufferSize,
        OUT PVOID Data OPTIONAL,
        OUT PULONG DataSize
        );

static NTSTATUS AnlgVBIOutIntersectDataFormat
(
    IN PVOID pvKSFilter,                 
    IN PIRP      pIrp,                      
    IN PKSP_PIN  pPinInstance,              
    IN PKSDATARANGE pCallerDataRange,       
    IN PKSDATARANGE pDescriptorDataRange,   
    IN ULONG     dwBufferSize,              
    OUT OPTIONAL PVOID pData,               
    OUT PULONG   pdwDataSize                
    );

const KSFILTER_DISPATCH AnlgCaptureFilterDispatch = 
{
    AnlgCaptureFilterCreate, // Filter Create
    AnlgCaptureFilterClose,  // Filter Close
    NULL,                    // Filter Process
    NULL                     // Filter Reset
};


NTSTATUS AnlgCaptureCapsGetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_VIDEODECODER_CAPS_S pRequest,
    IN OUT PKSPROPERTY_VIDEODECODER_CAPS_S pData
){ return STATUS_SUCCESS;}

NTSTATUS AnlgCaptureCapsSetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY_VIDEODECODER_CAPS_S pRequest,
    IN OUT PKSPROPERTY_VIDEODECODER_CAPS_S pData
){ return STATUS_SUCCESS;}

NTSTATUS AnlgCaptureAllocGetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY pRequest,
    IN OUT PVOID pData
){ return STATUS_SUCCESS;}

NTSTATUS AnlgCaptureDroppedFramesGetHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY pRequest,
    IN OUT PVOID pData
){ return STATUS_SUCCESS;}

NTSTATUS AnlgCaptureGenericHandler
(
    IN PIRP Irp,
    IN PKSPROPERTY pRequest,
    IN OUT PVOID pData
){ return STATUS_SUCCESS;}

DEFINE_KSPROPERTY_TABLE(AnlgCaptureFilterPropertyTable)
{
    DEFINE_KSPROPERTY_ITEM                              
    (
        KSPROPERTY_VIDEOCONTROL_CAPS,                   // Property
        AnlgCaptureGenericHandler,                      // Get Handler
        sizeof(KSPROPERTY),                             // Min Property
        0,                                              // Min Data
        AnlgCaptureGenericHandler,                      // Set Handler
        NULL,                                           // Values
        0,                                              // Relations Count
        NULL,                                           // Relations
        NULL,                                           // Support Handler
        0                                               // Serialized Size
    ),
    DEFINE_KSPROPERTY_ITEM                              
    (
        KSPROPERTY_VIDEOCONTROL_ACTUAL_FRAME_RATE,      // Property
        AnlgCaptureGenericHandler,                      // Get Handler
        sizeof(KSPROPERTY),                             // Set Handler
        0,                                              // Min Property
        AnlgCaptureGenericHandler,                      // Min Data
        NULL,                                           // Values
        0,                                              // Relations Count
        NULL,                                           // Relations
        NULL,                                           // Support Handler
        0                                               // Serialized Size
    ),
    DEFINE_KSPROPERTY_ITEM                              
    (
        KSPROPERTY_VIDEOCONTROL_FRAME_RATES,            // Property
        AnlgCaptureGenericHandler,                      // Get Handler
        sizeof(KSPROPERTY),                             // Min Property 
        0,                                              // Min Data
        AnlgCaptureGenericHandler,                      // Set Handler
        NULL,                                           // Values
        0,                                              // Relations Count
        NULL,                                           // Relations
        NULL,                                           // Support Handler
        0                                               // Serialized Size
    ),
    DEFINE_KSPROPERTY_ITEM                              
    (
        KSPROPERTY_VIDEOCONTROL_MODE,                   // Property
        AnlgCaptureGenericHandler,                      // Get Handler
        sizeof(KSPROPERTY),                             // Min Property
        0,                                              // Min Data
        AnlgCaptureGenericHandler,                      // Set Handler
        NULL,                                           // Values
        0,                                              // Relations Count
        NULL,                                           // Relations
        NULL,                                           // Support Handler
        0                                               // Serialized Size
    )
};
DEFINE_KSPROPERTY_TABLE(DecoderPropertyTable)
{
    DEFINE_KSPROPERTY_ITEM                              
    (
        KSPROPERTY_VIDEODECODER_CAPS,                   // Property
        AnlgCaptureGenericHandler,                      // Get Handler
        sizeof(KSPROPERTY),                             // Min Property
        0,                                              // Min Data
        AnlgCaptureGenericHandler,                      // Set Handler
        NULL,                                           // Values
        0,                                              // Relations Count
        NULL,                                           // Relations
        NULL,                                           // Support Handler
        0                                               // Serialized Size
    ),
    DEFINE_KSPROPERTY_ITEM                              
    (
        KSPROPERTY_VIDEODECODER_OUTPUT_ENABLE,          // Property
        AnlgCaptureGenericHandler,                      // Get Handler
        sizeof(KSPROPERTY),                             // Set Handler
        0,                                              // Min Property
        AnlgCaptureGenericHandler,                      // Min Data
        NULL,                                           // Values
        0,                                              // Relations Count
        NULL,                                           // Relations
        NULL,                                           // Support Handler
        0                                               // Serialized Size
    ),
    DEFINE_KSPROPERTY_ITEM                              
    (
        KSPROPERTY_VIDEODECODER_STANDARD,               // Property
        AnlgCaptureGenericHandler,                      // Get Handler
        sizeof(KSPROPERTY),                             // Min Property
        0,                                              // Min Data
        AnlgCaptureGenericHandler,                      // Set Handler
        NULL,                                           // Values
        0,                                              // Relations Count
        NULL,                                           // Relations
        NULL,                                           // Support Handler
        0                                               // Serialized Size
     ),
    DEFINE_KSPROPERTY_ITEM                              
    (
        KSPROPERTY_VIDEODECODER_STATUS,                 // Property
        AnlgCaptureGenericHandler,                      // Get Handler
        sizeof(KSPROPERTY),                             // Min Property
        0,                                              // Min Data
        AnlgCaptureGenericHandler,                      // Set Handler
        NULL,                                           // Values
        0,                                              // Relations Count
        NULL,                                           // Relations
        NULL,                                           // Support Handler
        0                                               // Serialized Size
    ),
    DEFINE_KSPROPERTY_ITEM                              
    (
        KSPROPERTY_VIDEODECODER_VCR_TIMING,             // Property
        AnlgCaptureGenericHandler,                      // Get Handler
        sizeof(KSPROPERTY),                             // Min Property
        0,                                              // Min Data
        AnlgCaptureGenericHandler,                      // Set Handler
        NULL,                                           // Values
        0,                                              // Relations Count
        NULL,                                           // Relations
        NULL,                                           // Support Handler
        0                                               // Serialized Size
    )
};

DEFINE_KSPROPERTY_TABLE(AnlgCaptureConnectionPropertyTable)
{
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_CONNECTION_ALLOCATORFRAMING,
        AnlgCaptureAllocGetHandler,                   // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        sizeof(KSALLOCATOR_FRAMING),                  // MinData
        FALSE,                                        // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    )
};

DEFINE_KSPROPERTY_TABLE(AnlgCaptureDroppedFramesProperties)
{
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_DROPPEDFRAMES_CURRENT,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
};

DEFINE_KSPROPERTY_TABLE(VideoCompressionPropertyTable)
{
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VIDEOCOMPRESSION_GETINFO,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VIDEOCOMPRESSION_KEYFRAME_RATE,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VIDEOCOMPRESSION_OVERRIDE_FRAME_SIZE,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VIDEOCOMPRESSION_OVERRIDE_KEYFRAME,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VIDEOCOMPRESSION_PFRAMES_PER_KEYFRAME,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VIDEOCOMPRESSION_QUALITY,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VIDEOCOMPRESSION_WINDOWSIZE,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
};
DEFINE_KSPROPERTY_TABLE(ProCampPropertyTable)
{
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VIDEOPROCAMP_BACKLIGHT_COMPENSATION,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VIDEOPROCAMP_BRIGHTNESS,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VIDEOPROCAMP_COLORENABLE,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VIDEOPROCAMP_CONTRAST,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VIDEOPROCAMP_GAMMA,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VIDEOPROCAMP_SATURATION,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VIDEOPROCAMP_SHARPNESS,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE,
        AnlgCaptureGenericHandler,                    // GetSupported or Handler
        sizeof(KSPROPERTY),                           // MinProperty
        0,                                            // MinData
        AnlgCaptureGenericHandler,                    // SetSupported or Handler
        NULL,                                         // Values
        0,                                            // RelationsCount
        NULL,                                         // Relations
        NULL,                                         // SupportHandler
        0                                             // SerializedSize
    ),
};

DEFINE_KSPROPERTY_SET_TABLE(AnlgCaptureFilterPropertySetTable)
{
    DEFINE_KSPROPERTY_SET
    (
        &PROPSETID_VIDCAP_VIDEOCONTROL,               // Set
        SIZEOF_ARRAY(AnlgCaptureFilterPropertyTable), // PropertiesCount
        AnlgCaptureFilterPropertyTable,               // PropertyItems
        0,                                            // FastIoCount
        NULL                                          // FastIoTable
    ),
    DEFINE_KSPROPERTY_SET
    ( 
        &PROPSETID_VIDCAP_DROPPEDFRAMES,                  // Set
        SIZEOF_ARRAY(AnlgCaptureDroppedFramesProperties), // PropertiesCount
        AnlgCaptureDroppedFramesProperties,               // PropertyItem
        0,                                                // FastIoCount
        NULL                                              // FastIoTable
    ),
    DEFINE_KSPROPERTY_SET
    (
        &PROPSETID_VIDCAP_VIDEOCOMPRESSION,               // Set
        SIZEOF_ARRAY(VideoCompressionPropertyTable),      // PropertiesCount
        VideoCompressionPropertyTable,                    // PropertyItems
        0,                                                // FastIoCount
        NULL                                              // FastIoTable
    ),
    DEFINE_KSPROPERTY_SET
    (
        &PROPSETID_VIDCAP_VIDEODECODER,                  // Set
        SIZEOF_ARRAY(DecoderPropertyTable),              // PropertiesCount
        DecoderPropertyTable,                            // PropertyItems
        0,                                               // FastIoCount
        NULL                                             // FastIoTable
    ),
    DEFINE_KSPROPERTY_SET
    (
        &KSPROPSETID_Connection,                          // Set
        SIZEOF_ARRAY(AnlgCaptureConnectionPropertyTable), // PropertiesCount
        AnlgCaptureConnectionPropertyTable,               // PropertyItems
        0,                                                // FastIoCount
        NULL                                              // FastIoTable
    ),
    DEFINE_KSPROPERTY_SET
    (
        &PROPSETID_VIDCAP_VIDEOPROCAMP,                   // Set
        SIZEOF_ARRAY(ProCampPropertyTable),               // PropertiesCount
        ProCampPropertyTable,                             // PropertyItems
        0,                                                // FastIoCount
        NULL                                              // FastIoTable
    )
};


DEFINE_KSAUTOMATION_TABLE(AnlgCaptureFilterAutomation) 
{
    DEFINE_KSAUTOMATION_PROPERTIES(AnlgCaptureFilterPropertySetTable),
    DEFINE_KSAUTOMATION_METHODS_NULL,
    DEFINE_KSAUTOMATION_EVENTS_NULL
};

const KSPIN_MEDIUM PinMediumAudioIn =
{
    GUID_XBarPinMediumAudioOut, 0, 0
};

const KSPIN_MEDIUM PinMediumVideoIn =
{
    GUID_XBarPinMediumVideoOut, 0, 0
};

const KSPIN_MEDIUM PinMediumAudioOut =
{
    GUID_AnlgCapturePinMediumAudioOut, 0, 0
};

const KSPIN_MEDIUM PinMediumVideoOut =
{
    GUID_AnlgCapturePinMediumVideoOut, 0, 0
};


const KSPIN_MEDIUM PinMediumVBIOut =
{
    GUID_AnlgCapturePinMediumVBIOut,
    0, 0
};

#define D_X 320 
#define D_Y 240
#define ABS(x) ((x) < 0 ? (-(x)) : (x))

#ifndef mmioFOURCC    
#define mmioFOURCC( ch0, ch1, ch2, ch3 )                \
        ( (DWORD)(BYTE)(ch0) | ( (DWORD)(BYTE)(ch1) << 8 ) |    \
        ( (DWORD)(BYTE)(ch2) << 16 ) | ( (DWORD)(BYTE)(ch3) << 24 ) )
#endif
#define FOURCC_YUV422       mmioFOURCC('U', 'Y', 'V', 'Y')


const 
KS_DATARANGE_VIDEO 
AnlgCaptureVideoOutPinRange = {

    //
    // KSDATARANGE
    //
    {   
        sizeof (KS_DATARANGE_VIDEO),            // FormatSize
        0,                                      // Flags
        D_X * D_Y * 2,                          // SampleSize
        0,                                      // Reserved
        STATICGUIDOF (KSDATAFORMAT_TYPE_VIDEO), // aka. MEDIATYPE_Video
        0x59565955, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 
            0x00, 0x38, 0x9b, 0x71,             // aka. MEDIASUBTYPE_UYVY,
        STATICGUIDOF (KSDATAFORMAT_SPECIFIER_VIDEOINFO) // aka. FORMAT_VideoInfo
    },

    TRUE,               // BOOL,  bFixedSizeSamples (all samples same size?)
    TRUE,               // BOOL,  bTemporalCompression (all I frames?)
    0,                  // Reserved (was StreamDescriptionFlags)
    0,                  // Reserved (was MemoryAllocationFlags   
                        //           (KS_VIDEO_ALLOC_*))

    //
    // _KS_VIDEO_STREAM_CONFIG_CAPS  
    //
    {
        STATICGUIDOF( KSDATAFORMAT_SPECIFIER_VIDEOINFO ), // GUID
        KS_AnalogVideo_NTSC_M |
        KS_AnalogVideo_PAL_B | KS_AnalogVideo_PAL_D | KS_AnalogVideo_PAL_G | KS_AnalogVideo_PAL_H | KS_AnalogVideo_PAL_I | KS_AnalogVideo_PAL_M | KS_AnalogVideo_PAL_N,                    // AnalogVideoStandard
        720,480,        // InputSize, (the inherent size of the incoming signal
                    //             with every digitized pixel unique)
        160,120,        // MinCroppingSize, smallest rcSrc cropping rect allowed
        720,480,        // MaxCroppingSize, largest  rcSrc cropping rect allowed
        8,              // CropGranularityX, granularity of cropping size
        1,              // CropGranularityY
        8,              // CropAlignX, alignment of cropping rect 
        1,              // CropAlignY;
        160, 120,       // MinOutputSize, smallest bitmap stream can produce
        720, 480,       // MaxOutputSize, largest  bitmap stream can produce
        8,              // OutputGranularityX, granularity of output bitmap size
        1,              // OutputGranularityY;
        0,              // StretchTapsX  (0 no stretch, 1 pix dup, 2 interp...)
        0,              // StretchTapsY
        0,              // ShrinkTapsX 
        0,              // ShrinkTapsY 
        333667,         // MinFrameInterval, 100 nS units
        640000000,      // MaxFrameInterval, 100 nS units
        8 * 2 * 30 * 160 * 120,  // MinBitsPerSecond;
        8 * 2 * 30 * 720 * 480   // MaxBitsPerSecond;
    }, 
        
    //
    // KS_VIDEOINFOHEADER (default format)
    //
    {
        0,0,0,0,                            // RECT  rcSource; 
        0,0,0,0,                            // RECT  rcTarget; 
        D_X * D_Y * 2 * 30,                 // DWORD dwBitRate;
        0L,                                 // DWORD dwBitErrorRate; 
        333667,                             // REFERENCE_TIME  AvgTimePerFrame;   
        sizeof (KS_BITMAPINFOHEADER),       // DWORD biSize;
        D_X,                                // LONG  biWidth;
        D_Y,                                // LONG  biHeight;
        1,                                  // WORD  biPlanes;
        16,                                 // WORD  biBitCount;
        FOURCC_YUV422,                      // DWORD biCompression;
        D_X * D_Y * 2,                      // DWORD biSizeImage;
        0,                                  // LONG  biXPelsPerMeter;
        0,                                  // LONG  biYPelsPerMeter;
        0,                                  // DWORD biClrUsed;
        0                                   // DWORD biClrImportant;
    }
}; 

#include "anlgvbioutformats.h"
const PKSDATARANGE AnlgCaptureVBIOutPinRanges[] =
{
    (PKSDATARANGE) &FormatVBI_NTSC,

    // Add more formats here if additional transport formats are supported.
    //
};

static  KS_DATARANGE_ANALOGVIDEO AnlgCaptureVideoInPinRange = 
{
    // KS_DATARANGE_ANALOGVIDEO
    {   
        sizeof (KS_DATARANGE_ANALOGVIDEO),      // FormatSize
        0,                                      // Flags
        sizeof (KS_TVTUNER_CHANGE_INFO),        // SampleSize
        0,                                      // Reserved

        STATIC_KSDATAFORMAT_TYPE_ANALOGVIDEO,   // aka MEDIATYPE_AnalogVideo
        STATIC_KSDATAFORMAT_SUBTYPE_NONE,
        STATIC_KSDATAFORMAT_SPECIFIER_ANALOGVIDEO, // aka FORMAT_AnalogVideo
    },
    // KS_ANALOGVIDEOINFO
    {
        0, 0, 720, 480,         // rcSource;                
        0, 0, 720, 480,         // rcTarget;        
        720,                    // dwActiveWidth;   
        480,                    // dwActiveHeight;  
        0,                      // REFERENCE_TIME  AvgTimePerFrame; 
    }
};
const PKSDATARANGE AnlgCaptureVideoInPinRanges[] =
{
    (PKSDATARANGE) &AnlgCaptureVideoInPinRange,

    // Add more formats here if additional transport formats are supported.
    //
};


const KSDATARANGE_AUDIO AnlgCaptureAudioInPinRange = 
{
    {
        sizeof(KSDATARANGE),
        0,
        0,
        0,
        0x482dee1, 0x7817, 0x11cf, 0x8a, 0x3, 0x0, 0xaa, 0x0, 0x6e, 0xcb, 0x65,
        STATICGUIDOF(KSDATAFORMAT_SUBTYPE_NONE),
        STATICGUIDOF(KSDATAFORMAT_SPECIFIER_NONE)
    },
    0, 0, 0, 0, 0
};

static PKSDATAFORMAT AnlgCaptureAudioInPinRanges[] =
{
    (PKSDATAFORMAT) &AnlgCaptureAudioInPinRange,

    // Add more formats here if additional transport formats are supported.
    //
};


static PKSDATAFORMAT AnlgCaptureVideoOutPinRanges[] =
{
    (PKSDATAFORMAT) &AnlgCaptureVideoOutPinRange,

    // Add more formats here if additional transport formats are supported.
    //
};

static
NTSTATUS
VideoOutIntersectDataFormat(
    IN PVOID piKSFilter,                    
    IN PIRP pIrp,                           
    IN PKSP_PIN pPinInstance,               
    IN PKSDATARANGE pCallerDataRange,       
    IN PKSDATARANGE pDescriptorDataRange,   
    IN DWORD dwBufferSize,                  
    OUT OPTIONAL PVOID pData,               
    OUT PDWORD pdwDataSize                  
   );


const KSDATARANGE_AUDIO AnlgCaptureAudioOutPinRange = 
{
    {
    sizeof(KSDATARANGE_AUDIO),
    0,
    0,
    0,
    STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
    STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
    STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
    },
    2,      // maximum channel
    16,      // min bits per sample
    16,      // max bits per sample
    32000,   // min frequency
    32000    // max frequency
};

static PKSDATAFORMAT AnlgCaptureAudioOutPinRanges[] =
{
    (PKSDATAFORMAT) &AnlgCaptureAudioOutPinRange,

    // Add more formats here if additional transport formats are supported.
    //
};

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
    );


const KSPIN_DESCRIPTOR_EX AnlgCapturePinDescriptors[] =
{ 
    {
    NULL,                                               // Dispatch
    NULL,                                               // Automation
    {                                                   // Pin Descriptor
        0,                                              // Interfaces Count
        NULL,                                           // Interfaces
        1,                                              // Mediums Count
        &PinMediumVideoIn,                              // Mediums
        SIZEOF_ARRAY(AnlgCaptureVideoInPinRanges),      // Data Range Count
        AnlgCaptureVideoInPinRanges,                    // Data Ranges
        KSPIN_DATAFLOW_IN,                              // Data Flow
        KSPIN_COMMUNICATION_BOTH,                       // Communication
       (GUID *) &PINNAME_VIDEO_CAPTURE,                 // Category
       (GUID *) &PINNAME_VIDEOTUNERIN,                  // Name
        0                                               // Constrained Data Range
    },
    KSPIN_FLAG_DO_NOT_USE_STANDARD_TRANSPORT |
    KSPIN_FLAG_FRAMES_NOT_REQUIRED_FOR_PROCESSING |
    KSPIN_FLAG_FIXED_FORMAT,                            // Flags
    1,                                                  // Instances Necessary
    1,                                                  // Instances Possible
    NULL,                                               // Allocator Framing
    VideoInIntersectDataFormat                          // Intersect Handler
    },
    {
    NULL,                                               // Dispatch
    NULL,                                               // Automation
    {                                                   // Pin Descriptor
        0,                                              // Interfaces Count
        NULL,                                           // Interfaces
        1,                                              // Mediums Count
        &PinMediumAudioIn,                              // Mediums
        SIZEOF_ARRAY(AnlgCaptureAudioInPinRanges),      // Data Range Count
        AnlgCaptureAudioInPinRanges,                    // Data Ranges
        KSPIN_DATAFLOW_IN,                              // Data Flow
        KSPIN_COMMUNICATION_BOTH,                       // Communication
        (GUID *) &PINNAME_VIDEO_CAPTURE,                // Category
        (GUID *) &PINNAME_AUDIOTUNERIN,                 // Name
        0                                               // Constrained Data Range
    },
    KSPIN_FLAG_DO_NOT_USE_STANDARD_TRANSPORT | 
    KSPIN_FLAG_FRAMES_NOT_REQUIRED_FOR_PROCESSING | 
    KSPIN_FLAG_FIXED_FORMAT,                            // Flags
    1,                                                  // Instances Possible
    0,                                                  // Instances necessary
    NULL,                                               // Allocator Framing
    AudioInIntersectDataFormat                          // Intersect Handler
    },
    {
    NULL,                                               // Dispatch
    NULL,                                               // Automation
    {                                                   // Pin Descriptor
        0,                                              // Interfaces Count
        NULL,                                           // Interfaces
        1,                                              // Mediums Count
        &PinMediumVideoOut,                             // Mediums
        SIZEOF_ARRAY(AnlgCaptureVideoOutPinRanges),     // Data Range Count
        AnlgCaptureVideoOutPinRanges,                   // Data Ranges
        KSPIN_DATAFLOW_OUT,                             // Data Flow
        KSPIN_COMMUNICATION_BOTH,                       // Data Communication
        (GUID *) &PINNAME_VIDEO_CAPTURE,                // Category
        (GUID *) &PINNAME_YUVOUT,                       // Name
        0                                               // Constrained Data Range
    },
    KSPIN_FLAG_DO_NOT_USE_STANDARD_TRANSPORT | 
    KSPIN_FLAG_FRAMES_NOT_REQUIRED_FOR_PROCESSING | 
    KSPIN_FLAG_FIXED_FORMAT,                            // Flags
    1,                                                  // Instances possible
    1,                                                  // Instances necessary
    NULL,                                               // Allocator Framing
    VideoOutIntersectDataFormat                         // Intersect Handler
    },
    {
    NULL,                                               // Dispatch
    NULL,                                               // Automation
    {                                                   // Pin Descriptor
        0,                                              // Interfaces Count
        NULL,                                           // Interfaces
        1,                                              // Mediums Count
        &PinMediumAudioOut,                             // Mediums
        SIZEOF_ARRAY(AnlgCaptureAudioOutPinRanges),     // Data Range Count
        AnlgCaptureAudioOutPinRanges,                   // Data Ranges
        KSPIN_DATAFLOW_OUT,                             // Data Flow
        KSPIN_COMMUNICATION_BOTH,                       // Communication
        (GUID *) &PINNAME_VIDEO_CAPTURE,                // Category
       (GUID *) &PINNAME_AUDIOPCMOUT,                   // Name
        0                                               // Constrained Data Range
    },
    KSPIN_FLAG_DO_NOT_USE_STANDARD_TRANSPORT | 
    KSPIN_FLAG_FRAMES_NOT_REQUIRED_FOR_PROCESSING | 
    KSPIN_FLAG_FIXED_FORMAT,                            // Flags
    1,                                                  // Instances Possible
    0,                                                  // Instances necessary
    NULL,                                               // Allocator Framing
    AudioOutIntersectDataFormat                         // Intersect Handler
    },
    {
    NULL,                                               // Dispatch
    NULL,                                               // Automation
    {                                                   // Pin Descriptor
        0,                                              // Interfaces Count
        NULL,                                           // Interfaces
        1,                                              // Mediums Count
        &PinMediumVBIOut,                               // Mediums
        SIZEOF_ARRAY(AnlgCaptureVBIOutPinRanges),       // Data Range Count
        AnlgCaptureVBIOutPinRanges,                     // Data Ranges
        KSPIN_DATAFLOW_OUT,                             // Data Flow
        KSPIN_COMMUNICATION_BOTH,                       // Communication
            (GUID *) &PINNAME_VIDEO_CAPTURE,            // Category
            (GUID *) &PINNAME_VBI,                      // Name
        0                                               // Constrained Data Range
    },
    KSPIN_FLAG_DO_NOT_USE_STANDARD_TRANSPORT | 
    KSPIN_FLAG_FRAMES_NOT_REQUIRED_FOR_PROCESSING | 
    KSPIN_FLAG_FIXED_FORMAT,                            // Flags
    1,                                                  // Instances Possible
    0,                                                  // Instances necessary
    NULL,                                               // Allocator Framing
    AnlgVBIOutIntersectDataFormat                       // Intersect Handler
    }

};

const
GUID
CaptureFilterCategories [2] = {
    STATICGUIDOF (KSCATEGORY_VIDEO),
    STATICGUIDOF (KSCATEGORY_CAPTURE)
};

const
KSTOPOLOGY_CONNECTION FilterConnections[] =
{
    { KSFILTER_NODE, 0,                 KSFILTER_NODE, 2 },
    { KSFILTER_NODE, 1,                 KSFILTER_NODE, 3 }
};

extern
DEFINE_KSFILTER_DESCRIPTOR(BdaAnlgCaptureFilterDescriptor)
{
    &AnlgCaptureFilterDispatch,                                 // Dispatch
    &AnlgCaptureFilterAutomation,                               // AutomationTable
    KSFILTER_DESCRIPTOR_VERSION,                                // Version
    0,                                                          // Flags
    &KSNAME_BdaAnlgCaptureFilter,                               // ReferenceGuid
    DEFINE_KSFILTER_PIN_DESCRIPTORS(AnlgCapturePinDescriptors), // PinDescriptorsCount
    DEFINE_KSFILTER_CATEGORIES(CaptureFilterCategories),        // CategoriesCount
    DEFINE_KSFILTER_NODE_DESCRIPTORS_NULL,                      // Node Descriptors
    DEFINE_KSFILTER_CONNECTIONS(FilterConnections),             // Topology
    NULL                                                        // ComponentId
};



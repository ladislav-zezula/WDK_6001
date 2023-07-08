

/****************************************************************************\
*
*  Module Name    dalbase.h
*  Project        ATI Display Abstraction Layer
*  Device         RageProPNP / Rage128 (Win95/98 & WinNT 4.0/5.0)
*
*  Description    base header file for Display Abstraction Layer 0.90
*                 containing common type definitions and defines
*
*  Copyright (c) 1998-2002 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  Refer to DAL Developers Guide & Programming Reference Rev 0.90 for usage
*
*  LOG OF CHANGES
*
*  03-31-98   1.0 [GG] initial revision
*
\****************************************************************************/

#ifndef _DALBASE_H
#define _DALBASE_H

#if defined(_X86_)
#pragma pack(push,1)
#endif

#define DAL_REVISION_MAJOR 0x0000
#define DAL_REVISION_MINOR 0x9000

#define DAL_REVISION ((QS_REVISION_MAJOR << 16) | QS_REVISION_MINOR)

#define GDO_CAPS_ACTIVATE_BEFORE_DETECT      0x00000001L
#define GDO_CAPS_GDO_WITH_LID                0x00000002L
#define GDO_CAPS_RESERVED0                   0x00000004L
#define GDO_CAPS_REPORT_ONLY_EDID            0x00000008L


#define MAX_NO_MONITOR_INFO_MODES            30
#define MAX_NUM_FIXEDDISPLAY_MODES           25
#define DEFAULT_DISPLAY_REFRESH_RATE         60

#define BWV_MAX_NUMBER_CONTROLLERS           2

// These are return code for bValidateMonitorRangeMode() function
#define FEATURE_NOT_SUPPORTED   0x00000001L
#define RES_SUPPORTED           0x00000002L
#define RES_NOT_SUPPORTED       0x00000003L

  // ++ These defines are obsolete, use the ones defined in DALDDC.H instead
#define EDID_VERSION_10         0x00000100
#define EDID_VERSION_11         0x00000101
#define EDID_VERSION_12         0x00000102
#define EDID_VERSION_13         0x00000103
#define EDID_VERSION_20         0x00000200
#define EDID_VERSION_SIMULATED  0xFFFFFFFF
  // --

#define EDID_DISPLAY_NAME_SIZE  20

#define OVERLAY_FORMAT_YUY2     0x00000001 // 4-2-2 (16bits) format, packed
#define OVERLAY_FORMAT_UYVY     0x00000002 // 4-2-2 (16bits) format, packed
#define OVERLAY_FORMAT_YV12     0x00000003 // 4-2-0 (12bits) format, planar
#define OVERLAY_FORMAT_YVU9     0x00000004 // (9bits) ??, planar
#define OVERLAY_FORMAT_IF09     0x00000005 // (9bits) ??, planar
#define OVERLAY_FORMAT_RGB565   0x00000006 // 16 bits, packed
#define OVERLAY_FORMAT_RGB555   0x00000007 // 16 bits, packed
#define OVERLAY_FORMAT_RGB32    0x00000008 // 32 bits, packed

// These options are used in the bFindClosest mode
#define DAL_OPTIONS_DIRECTDRAWMODE     0x00000001
#define DAL_OPTIONS_EXACTFREQUENCY     0x00000002
#define DAL_OPTIONS_LOWRESMODE         0x00000004
#define DAL_OPTIONS_DONOTLOWERVIEW     0x00000008
#define DAL_OPTIONS_BESTVIEW           0x00000010
// Return codes from ulSetPowerState Function 
#define SETPOWERSTATE_OK                                    1
#define SETPOWERSTATE_FAILED_MULTIPLECONTROLLERSACTIVE      2
#define SETPOWERSTATE_FAILED_MULTIPLEDISPLAYSACTIVE         3
#define SETPOWERSTATE_FAILED_LCDPANELDNOTACTIVE             4
#define SETPOWERSTATE_FAILED_FEATUREDISABLEDINOPTION        5
#define SETPOWERSTATE_FAILED_CURRENTSTATESAMETOREQUESTED    6
#define SETPOWERSTATE_FAILED_NOBANDWIDTH                    7
#define SETPOWERSTATE_FAILED_INVALIDPOWERSTATE              8
#define SETPOWERSTATE_FAILED_NOBWAT32BPPOKAT16BPP           9
// ulR6SetPowerState hook function can return this code if
// POWERplay state has been set without mode set
#define SETPOWERSTATE_DONE                                 10

#define SETPOWERSTATE_RETURNACTION_FORCEMODECHANGE          1

// This is used for ulMiscInfo parameter for UpdateBIOSDisplayInfo
#define GCO_UPDATE_CMOS         0x00000001L  // Bit 0: Update CMOS 

// Return codes from ulR6ValidateClockConfig
#define SETCLOCK_OK                                         1
#define SETCLOCK_FAILED_SKIPSAMESETTINGS                    2
#define SETCLOCK_FAILED_ASICNOTSUPPORT                      3
#define SETCLOCK_FAILED_CLOCKOUTOFRANGE                     4
#define SETCLOCK_FAILED_NOBANDWIDTH                         5
#define SETCLOCK_FAILED_WRONGCLOCKFLAG                      6

//
// This is the CRTC timing structure to be used by all
// DAL components.
//
typedef struct _DAL_CRTC_TIMING
{
    USHORT usFlags;                     // flags to indicate various conditions
    USHORT usHorizontalTotal;           // horizontal totol time
    USHORT usHorizontalDisplay;         // horizontal address time
    USHORT usHorizontalSyncStart;       // horizontal sync start
    USHORT usHorizontalSyncWidth;       // horizontal sync time
    USHORT usVerticalTotal;             // vertical total time
    USHORT usVerticalDisplay;           // vertical address time
    USHORT usVerticalSyncStart;         // vertical sync start
    USHORT usVerticalSyncWidth;         // vertical sync time
    USHORT usPixelClock;                // pixel clock frequency to use
    USHORT usHorizontalOverscanRight;   // right overscan width
    USHORT usHorizontalOverscanLeft;    // left overscan width
    USHORT usVerticalOverscanBottom;    // bottom overscan width
    USHORT usVerticalOverscanTop;       // top overscan width
    USHORT usOverscan8B;                // 8bpp and blue overscan color
    USHORT usOverscanGR;                // green and red overscan color
} DAL_CRTC_TIMING, FAR *LPDAL_CRTC_TIMING;

// DAL_DISPLAY_DETAIL_TIMING structure will be passed to GCO
// at set mode with detailed timing for GCO to set the mode.
typedef struct _DAL_DISPLAY_TIMING_INFO
{
  ULONG             ulDisplayID;            // DAL display ID
  ULONG             ulDisplayType;          // Display type (DFP, CRT, LCD)
  ULONG             ulEDIDManufacturerName; // Manufactureres name
  ULONG             ulEDIDDisplayProductID; // Product ID as per EDID
  ULONG             ulEDIDStructureVersion; // Edid structure version
  DAL_CRTC_TIMING   sDisplayDetailedTiming; // Detailed Timing obtained form EDID
} DAL_DISPLAY_TIMING_INFO, FAR *LPDAL_DISPLAY_TIMING_INFO;

// Flags used for manipulating the DAL_CRTC_TIMING structure.
//
#define CRTC_DOUBLE_SCAN                    0x0001
#define CRTC_INTERLACED                     0x0002
#define CRTC_H_SYNC_POLARITY                0x0004
#define CRTC_V_SYNC_POLARITY                0x0008
#define USE_DEFAULT_POLARITY                0x0010
#define CRTC_ONLY_DETAILED_TIMINGS_EXIST    0x0020
#define CRTC_NOT_RECOMMENDED_BY_DAL         0x0040
#define CRTC_PANEL_MODE                     0x1000 // If this bit is set in flags field then it means
                                                   // resolution is panel specific e.g 1400x1050 etc.

#define DAL_GCO_MAX_POWERSTATE              8      // should be the same as MAX_NUM_POWERSAVING_BLOCKS
                                                   // in combios.h
#define DAL_POWERSTATE_NORMAL               1

#define DAL_GCOPOWERSTATE_FLAGS_MEMORYSHARESCORECLK        0x00000001L
#define DAL_GCOPOWERSTATE_FLAGS_CORESHARESMEMORYCLK        0x00000002L
#define DAL_GCOPOWERSTATE_FLAGS_LOWVOLTAGE                 0x00000004L
#define DAL_GCOPOWERSTATE_FLAGS_LOWPANELREFRESHRATE        0x00000008L
#define DAL_GCOPOWERSTATE_FLAGS_OVERCLOCKED                0x00000010L
#define DAL_GCOPOWERSTATE_FLAGS_ENABLESLEEP                0x00000020L
#define DAL_GCOPOWERSTATE_FLAGS_ENABLELOADBALANCING        0x00000040L
#define DAL_GCOPOWERSTATE_FLAGS_DEFAULTFORDC               0x00000080L
#define DAL_GCOPOWERSTATE_FLAGS_DEFAULTFORDCLOW            0x00000100L
#define DAL_GCOPOWERSTATE_FLAGS_POWERSAVINGMODE            0x00000200L
#define DAL_GCOPOWERSTATE_FLAGS_THERMALDIODEMODE           0x00000400L

#define DAL_GCOCLOCKINFO_FLAGS_MEMORYSHARESCORECLK         0x00000001L
#define DAL_GCOCLOCKINFO_FLAGS_CORESHARESMEMORYCLK         0x00000002L
      
typedef struct _DAL_GCOPOWERSTATE
{
    ULONG       ulFlags;
    ULONG       ulMemoryClock;
    ULONG       ulCoreClock;
    ULONG       ulRefreshRate;
    ULONG       ulReserved[4];  

} DAL_GCOPOWERSTATE, FAR *LPDAL_GCOPOWERSTATE;

typedef struct _DAL_ADAPTERPOWERSTATES
{
  DAL_GCOPOWERSTATE sGCOPowerState[DAL_GCO_MAX_POWERSTATE];

} DAL_ADAPTERPOWERSTATES, FAR *LPDAL_ADAPTERPOWERSTATES;


//ADJUSTMENT_PARAMETERS ulFlags:
#define ADJUSTMENT_PARAMETERS_DEFAULT_HORIZ_SIZE        0x00000001L
#define ADJUSTMENT_PARAMETERS_DEFAULT_VERT_SIZE         0x00000002L
#define ADJUSTMENT_PARAMETERS_DEFAULT_HORIZ_POSITION    0x00000004L
#define ADJUSTMENT_PARAMETERS_DEFAULT_VERT_POSITION     0x00000008L
#define ADJUSTMENT_PARAMETERS_DEFAULT_PANEL_REFRESH_RATE  0x00000010L

//ulModifier for HW_ADJUSTMENT_PARAMETERS
#define ADJUSTMENT_MODIFIER_CRTC_MODETIMING              0x00000001L
#define ADJUSTMENT_MODIFIER_CRTC_POSITION                0x00000002L
#define ADJUSTMENT_MODIFIER_CRTC_SIZE                    0x00000003L
#define ADJUSTMENT_MODIFIER_CRTC_PLL                     0x00000004L
#define ADJUSTMENT_MODIFIER_CRTC_PIXELCLOCK              0x00000005L

//GCO service type provide to GDO, use one at a time.
#define DAL_GCOSERVICE_TYPE_QUERY_SUPPORT                0x00000001L
#define DAL_GCOSERVICE_TYPE_POSITION_ADJUSTMENT          0x00000002L
#define DAL_GCOSERVICE_TYPE_SIZE_ADJUSTMENT              0x00000003L
#define DAL_GCOSERVICE_TYPE_GETCURRENTTIMING             0x00000004L
#define DAL_GCOSERVICE_TYPE_SETMODE                      0x00000005L
#define DAL_GCOSERVICE_TYPE_SETOVERSCAN                  0x00000006L
#define DAL_GCOSERVICE_TYPE_SETCOLORMATRIX_ADJUSTMENT    0x00000007L

//Return value for GCO_SERIVE
# define DAL_GCOSERVICE_SUCCESS                      0x00000000L
# define DAL_GCOSERVICE_FAILED                       0x00000001L
# define DAL_GCOSERVICE_NOAVAILABLE                  0x00000002L

// define for GXO_COLORMATRIX_ADJUSTMENT.ulType
#define DAL_COLORMATRIX_RESERVED00                       0x00000000L
#define DAL_COLORMATRIX_BRIGHTNESS                       0x00000001L
#define DAL_COLORMATRIX_SATURATION                       0x00000002L
#define DAL_COLORMATIRX_CONTRAST                         0x00000003L
#define DAL_COLORMATRIX_HUE                              0x00000004L

typedef struct _GXO_POSITION_SIZE_ADJUSTMENT
{
  LONG lVerticalAdjust;
  LONG lHorizontalAdjust;
}GXO_POSITION_SIZE_ADJUSTMENT, FAR * LPGXO_POSITION_SIZE_ADJUSTMENT;

typedef struct _GCO_QUERY_SUPPORT
{
  ULONG ulServiceSupport;
  ULONG ulReserved;
}GCO_QUERY_SUPPORT, FAR * LPGCO_QUERY_SUPPORT;

typedef struct _GXO_SERVICE_SETOVERSCAN
{
  ULONG ulLeft;       // in pixel unit
  ULONG ulTop;        // in pixel unit
  ULONG ulRight;      // in pixel unit
  ULONG ulBottom;     // in pixel unit
}GXO_SERVICE_SETOVERSCAN, FAR * LPGXO_SERVICE_SETOVERSCAN;

typedef struct _GXO_COLORMATRIX_ADJUSTMENT
{
  ULONG ulType;
  LONG  lAdjust;
} GXO_COLORMATRIX_ADJUSTMENT, FAR * LPGXO_COLORMATRIX_ADJUSTMENT;

typedef struct _GCO_SERVICE
{
  ULONG ulSize;
  ULONG ulDisplayType;
  ULONG ulServiceType;
  ULONG ulReserved;
  union 
  {
    GCO_QUERY_SUPPORT            sQueryService;
    GXO_POSITION_SIZE_ADJUSTMENT sPositionSizeAdjustment;
    DAL_CRTC_TIMING              sGetCurrentTiming;
    GXO_SERVICE_SETOVERSCAN      sOverscan;
    GXO_COLORMATRIX_ADJUSTMENT   sColorMatrixAdjustment;
  };
} GCO_SERVICE, FAR *LPGCO_SERVICE;

typedef struct _DAL_GCOCLK_SETTING
{
  ULONG ulDefaultClk;
  ULONG ulCurrentClk;
  ULONG ulMaxSetClk;
  ULONG ulMinSetClk;
  ULONG ulReserved[4];
} DAL_GCOCLK_SETTING, FAR *LPDAL_GCOCLK_SETTING;

typedef struct _DAL_ADAPTERCLOCK_INFO
{
  ULONG ulSize;
  ULONG ulFlag;          //indicate clock related configuration flag.
  DAL_GCOCLK_SETTING sMemoryClk;
  DAL_GCOCLK_SETTING sCoreClk;
  ULONG ulReserved[2];
  
} DAL_ADAPTERCLOCK_INFO, FAR *LPDAL_ADAPTERCLOCK_INFO;

typedef struct _DAL_GCOCLK_CONFIG
{
  ULONG ulSize;
  ULONG ulFlag;
  ULONG ulMemClk;
  ULONG ulCoreClk;
  ULONG ulReserved[4];
} DAL_GCOCLK_CONFIG, FAR *LPDAL_GCOCLK_CONFIG;

//All gxo have to zero out this structure before use.
typedef struct _ADJUSTMENT_PARAMETERS
{  
    ULONG       ulSize;                //Introduced for Atomic family, size of this structure.
    ULONG       ulModifier;            //Introduced for Atomic family, indicate one of the adjustment
    ULONG       ulDisplayType;         //Introduced for Atomic family, indicate the client

//Options for this struture:
//1.) Timing adjustment
   
    USHORT      usCRTC_H_TOTAL;         // Horizontal total (pixels * 8)
    USHORT      usCRTC_H_SYNC_START;    // Horizontal sync start (pixels * 8)
    USHORT      usCRTC_V_TOTAL;         // Vertical tatal
    USHORT      usCRTC_V_SYNC_START;    // Vertical sync start

    //PLL stuff 10 bit for extended PLL
    //for secondary CRTC there is only extended
//2.) PLL adjustment.

    USHORT      usPLL_REF_DIV;
    USHORT      usPLL_FB_DIV;           // This is for VClock (CRTC1 & CRTC2),
    USHORT      usPLL_FRAC_FB_DIV;      // Set to 0 if fractional FB Div is not supported
    UCHAR       ucPLL_POST_DIV;

//3.) PixelClock adjustment (Used by DisplaySetRefreshRate, Make sure to set other options to zero when used.)
    USHORT      usPixelClock;

//4.) Default position /adjustment information  
    ULONG       ulFlags;

} ADJUSTMENT_PARAMETERS, FAR *LPADJUSTMENT_PARAMETERS;


typedef struct _DEVCLUT
{
  UCHAR ucRed;
  UCHAR ucGreen;
  UCHAR ucBlue;
  UCHAR ucReserved;
} DEVCLUT, FAR *LPDEVCLUT;

typedef struct _DEVCLUT16
{
  USHORT usRed;
  USHORT usGreen;
  USHORT usBlue;
  USHORT usReserved;
} DEVCLUT16, FAR *LPDEVCLUT16;



#define DEVMODEFLAG_INTERLACED         0x00000001
#define DEVMODEFLAG_DIRECTDRAW         0x00000002
#define DEVMODEFLAG_LARGEDESKTOP       0x00000004
#define DEVMODEFLAG_VIEWRESTRICTED     0x00000008
#define DEVMODEFLAG_DEFAULTFREQUENCY   0x00000010
#define DEVMODEFLAG_OPTIMUMFREQUENCY   0x00000020
#define DEVMODEFLAG_DDMODEVALIDATE     0x00000040
#define DEVMODEFLAG_NONSTANDARDMODE    0x00000080
#define DEVMODEFLAG_CVMODE             0x00000100
#define DEVMODEFLAG_USE565             0x00000200
#define DEVMODEFLAG_DEFINEDFREQUENCY   0x00000400
#define DEVMODEFLAG_USE4444            0x00000800
#define DEVMODEFLAG_FORCEVIEWMODE      0x00001000
#define DEVMODEFLAG_DDEXCLUSIVEMODE    0x00002000
#define DEVMODEFLAG_DOUBLESCAN         0x00004000
#define DEVMODEFLAG_FIXEDDISPLAYMODE   0x00008000  
#define DEVMODEFLAG_CUSTOMREFRESHRATE  0x00010000  
#define DEVMODEFLAG_VIRTUALDESKTOP     0x00020000  

typedef struct _DEVMODE_INFO
{
  ULONG ulModeFlags;
  ULONG ulPelsWidth;
  ULONG ulPelsHeight;
  ULONG ulBitsPerPixel;
  ULONG ulDisplayFrequency;
} DEVMODE_INFO, FAR *LPDEVMODE_INFO;

typedef struct _RESOLUTION_INFO
{
  ULONG ulPelsWidth;
  ULONG ulPelsHeight;
} DALRESOLUTION_INFO, FAR *LPDALRESOLUTION_INFO;

typedef struct _BWV_MODEINFO
{
  ULONG                     ulPixelFormat;      
  ULONG                     ulSclQuality;         
  DAL_CRTC_TIMING           sDispTiming;        
  DEVMODE_INFO              sTimingMode;
  DALRESOLUTION_INFO        sDstRes;
  DALRESOLUTION_INFO        sViewRes;

} DALBWV_MODEINFO, FAR *LPDALBWV_MODEINFO;

typedef struct _BWV_OVERLAYINFO
{
 ULONG ulOverlayWidth;
 ULONG ulOverlayHeight;
 ULONG ulOverlayType;
 ULONG ulOverlayBackendBpp;

}DALBWV_OVERLAYINFO, FAR *LPDALBWV_OVERLAYINFO;

typedef struct _BWVALIDATE_CAPTUREINFO
{
  //To be confirmed.
  ULONG      ulFrameRate;
  ULONG      ulVideoWidth;
  ULONG      ulVideoHeight;
  ULONG      ulVBIWidth;
  ULONG      ulVBIHeight;
  ULONG      ulReserved1;
  ULONG      ulReserved2;

}DALBWV_CAPTUREINFO, FAR *LPDALBWV_CAPTUREINFO;

typedef struct _BWVALIDATE
{
  ULONG ulFlags;
  ULONG ulEngClk;                                               // engine clock in 10KHz unit
  ULONG ulMemClk;                                               // memory clock in 10KHz unit

  ULONG aulDisplayType[BWV_MAX_NUMBER_CONTROLLERS];             // array of display types  
  // mode info
  DALBWV_MODEINFO aModeInfo[BWV_MAX_NUMBER_CONTROLLERS];        // array of mode info
  // overlay info
  DALBWV_OVERLAYINFO aOverlayInfo[BWV_MAX_NUMBER_CONTROLLERS];  // array of overlay mode info
  // capture info
  DALBWV_CAPTUREINFO aCaptureInfo[BWV_MAX_NUMBER_CONTROLLERS];  // array of capture mode info

} DALBWVALIDATE, FAR *LPDALBWVALIDATE;

enum
{
  POWERSTATE_ON = 1,
  POWERSTATE_STANDBY,
  POWERSTATE_SUSPEND,
  POWERSTATE_OFF
};

enum
{
  ACPI_CM_POWERSTATE_D0 = 1,
  ACPI_CM_POWERSTATE_D1 = 2,
  ACPI_CM_POWERSTATE_D2 = 4,
  ACPI_CM_POWERSTATE_D3 = 8
};

enum
{
  GAMMAMODE_DESKTOP = 0,
  GAMMAMODE_FULLSCREENGAMING
};

typedef struct _EDID_BUFFER
{
    ULONG   ulSize;
    ULONG   ulFormatId;
    UCHAR   aucEdidDataBuffer[256];
} EDID_BUFFER, FAR *LPEDID_BUFFER;

#define EDID_DETAILED_V1x_FLAG_BIT1         0x02
#define EDID_DETAILED_V1x_FLAG_BIT2         0x04
#define EDID_DETAILED_V1x_FLAG_BIT3         0x08
#define EDID_DETAILED_V1x_FLAG_BIT4         0x10
#define EDID_DETAILED_V1x_FLAG_INTERLACED   0x80

// Structure definition for EDID detailed timing section
typedef struct _EDID_DETAILED_V11
{
   USHORT usPixelClock;       // Pixel Clock
   UCHAR ucHActiveL8;         // H.Active[7-0]
   UCHAR ucHBlankingL8;       // H.Blanking[7-0]
   UCHAR ucHActive_HBlankU4;  // 7-4:H.Active[11-8], 3-0:H.blanking[11-8]
   UCHAR ucVActiveL8;         // V.Active[7-0]
   UCHAR ucVBlankingL8;       // V.Blanking[7-0]
   UCHAR ucVActive_VBlankU4;  // 7-4:V.Active[11-8], 3-0:V.blanking[11-8]
   UCHAR ucHSyncOffsetL8;     // H.SyncOffset[7-0]
   UCHAR ucHSyncWidthL8;      // H.SyncWidth[7-0]
   UCHAR ucVSyncOffset_VSyncWidthL4; // 7-4:V.SyncOffset[3-0], 3-0:V.SyncWidth[3-0]
   UCHAR ucHSyncOffset_HSyncWidth_VSyncOffset_VSyncWidth;  // 7,6:HSyncOffset[9,8], 5,4:HSyncWidth[9,8], 3,2:VSyncOffset[5,4], 1,0:VSyncWidth[5,4]
   UCHAR ucHImageSize;        // mm, lower 8 bits
   UCHAR ucVImageSize;        // mm, lower 8 bits
   UCHAR ucHVImageSizeU4;     // 7-4:H.ImageSize[11-8], 3-0:V.ImageSize[11-8]
   UCHAR ucHBorder;           // H.Border in pixels
   UCHAR ucVBorder;           // V.Border in lines
   UCHAR ucFlags;             // Interlace, stereo, H.Polarity, V.Polaritym, SConfig, Reserved
} EDID_DETAILED_V11, FAR *LPEDID_DETAILED_V11;

typedef struct _EDID_STANDARD_TIMING
{
    UCHAR ucHorizontalActive;                       // (Horizontal Active pixels / 8) - 1
    UCHAR ucAspectAndRefreshRate;                   // Bits 6-7 = aspect ratio, bits 0-5 = refresh rate - 60
} EDID_STANDARD_TIMING, *LPEDID_STANDARD_TIMING;

// Structure definition for DDC EDID information block
typedef struct _EDID_DATA_V11
{
   UCHAR aucHeader [8];
   UCHAR aucVendorID [10];
   UCHAR aucVersion [2];
   UCHAR aucBasicDisplayParameters [5];
   UCHAR aucColorCharacteristics [10];
   UCHAR aucEstablishedTimings [3];
   USHORT ausStandardTimings [8];
   EDID_DETAILED_V11 EDIDDetailedTimings [4];
   UCHAR ucExtensionFlag;
   UCHAR ucChecksum;
} EDID_DATA_V11, FAR *LPEDID_DATA_V11;

// Structure definition for DDC EDID 2.0 information block
typedef struct _EDID_DATA_V20
{
   UCHAR ucVersion;
   UCHAR aucVendorID [7];
   UCHAR aucManufacturerID[32];
   UCHAR aucSerialNumber[16];
   UCHAR aucReserved[8];
   UCHAR aucDisplayInterfaceParameters[15];
   UCHAR aucDisplayDeviceDescription[5];
   UCHAR aucDisplayResponseTime[2];
   UCHAR aucColorDescription[28];
   UCHAR aucDisplaySpatialDescription[10];
   UCHAR ucReserved;
   UCHAR ucGTFInformation;
   UCHAR aucMapofTimingInfo[2];
   UCHAR aucTimingDescriptions[127];
   UCHAR ucChecksum;
} EDID_DATA_V20, FAR *LPEDID_DATA_V20;

typedef struct _EDID_DETAILED_V11 EDID_DETAILED_V1X, FAR *LPEDID_DETAILED_V1X;

typedef struct _EDID_DATA_V1X
{
   UCHAR aucHeader [8];
   UCHAR aucVendorID [10];
   UCHAR aucVersion [2];
   UCHAR aucBasicDisplayParameters [5];
   UCHAR aucColorCharacteristics [10];
   UCHAR aucEstablishedTimings [3];
   EDID_STANDARD_TIMING ausStandardTimings [8];
   EDID_DETAILED_V1X    EDIDDetailedTimings[4];
   UCHAR ucExtensionFlag;
   UCHAR ucChecksum;
}EDID_DATA_V1X, FAR * LPEDID_DATA_V1X;

typedef struct _FREQUENCY_RANGE
{
   USHORT usMax_Frequency;
   USHORT usMin_Frequency;
} FREQUENCY_RANGE, FAR *LPFREQUENCY_RAGNE;

#define MODESUPPORTEDFLAG_EXACT_FREQ   0x00000001 // Flag to indicate only this frequecy
                                                  // is supported

typedef struct _MODE_SUPPORTED
{
    ULONG   ulModeFlags;
    ULONG   ulHorizontalRes;
    ULONG   ulVerticalRes;
    ULONG   ulRefreshRate;
}MODE_SUPPORTED, FAR *LPMODE_SUPPORTED;

typedef enum _MACROVISION_MODE
{
  MACROVISION_MODE_NO_MV = 0,
  MACROVISION_MODE_NO_COLORBURST,
  MACROVISION_MODE_2LINE_CLRBURST,
  MACROVISION_MODE_4LINE_CLRBURST
} MACROVISION_MODE, FAR *LPMACROVISION_MODE;


#define MONITORINFO_DISPLAYCAPS_FIXEDDISPLAY      0x00000001 // Flag to indicate that
                                                             // the display device could
                                                             // not be changed.

#define MONITORINFO_DISPLAYCAPS_USEOSMONITORINFO  0x80000000 // Is this should be here???

typedef struct _MONITOR_INFO
{
    ULONG   ulMaxHorizontalRes;
    ULONG   ulMaxVerticalRes;
    ULONG   ulMaxRefreshRate;
    ULONG   ulMinHorizontalFreq;
    ULONG   ulMaxHorizontalFreq;
    ULONG   ulUseOverride;
    ULONG   ulDisplayCaps;
    MODE_SUPPORTED  aModeSupported[MAX_NO_MONITOR_INFO_MODES];
    EDID_BUFFER     EDIDRegMonInfo;
    
}MONITOR_INFO, FAR *LPMONITOR_INFO;

typedef struct _MONITOR_RANGE_LIMTS
{
    ULONG   ulMinVerticalRate;
    ULONG   ulMaxVerticalRate;
    ULONG   ulMinHorizontalRate;
    ULONG   ulMaxHorizontalRate;
    ULONG   ulMaxPixelClock;
}MONITOR_RANGE_LIMITS, FAR *LPMONITOR_RANGE_LIMITS;

#define DDC_INFO_FLAG_MONITORRANGELIMITSUPPORTED      0x00000001L
#define DDC_INFO_FLAG_DONTUSEEDIDDETAILEDTIMING       0x00000002L
#define DDC_INFO_FLAG_RESTRICTTOVESAMODETIMING        0x00000004L
#define DDC_INFO_FLAG_DONOTUSEEDIDMAXPIXCLK           0x00000008L

typedef struct _DDC_INFO
{
    UCHAR           DDCDisplayName[EDID_DISPLAY_NAME_SIZE];
    ULONG           ulDDCInfoFlag;
    ULONG           ulDDCManufacturerName;
    ULONG           ulDDCProductCode;
    ULONG           ulDDCEdidVersion;
    MODE_SUPPORTED  DDCMaxModeSupported;
    MONITOR_RANGE_LIMITS sMonitorRangeLimits;
    DEVMODE_INFO    sPreferredMode;
}DDC_INFO, FAR *LPDDC_INFO;

typedef struct _DISPLAYMANUFACTURER_RESTRICTION_INFO
{
    ULONG           ulDDCManufacturerName;
    ULONG           ulDDCProductCode;
    ULONG           ulDDCInfoFlag;
}DISPLAYMANUFACTURER_RESTRICTION_INFO, *LPDISPLAYMANUFACTURER_RESTRICTION_INFO;
 

enum
{
  VRAM_FASTPAGE = 1,
  VRAM_EDO,
  VRAM_WRAM,
  VRAM_SDRSDRAM,
  VRAM_DDRSDRAM,
  VRAM_SDRSGRAM,
  VRAM_DDRSGRAM,
  VRAM_INBEDDED,
  VRAM_RAMBUS
};

// DAL_DISPLAYDEVICEINFO structure will be used by GDOs
// to pass device info to DAL.
typedef struct _DAL_DISPLAYDEVICEINFO
{
    ULONG  ulOutputType;		      // Composite/SVIDEO/Analog/Digital/...
    ULONG  ulFlag;
    ULONG  ulConnectorType;
    ULONG  ulReserved2;
    ULONG  ulReserved3;
    ULONG  ulReserved4;
} DAL_DISPLAYDEVICEINFO, FAR *LPDAL_DISPLAYDEVICEINFO;

//
// Flags used for manipulating the DAL_DISPLAYDEVICEINFO structure.
//
#define DAL_DISPLAY_OUTPUTTYPE_UNKNOWN                        0
#define DAL_DISPLAY_OUTPUTTYPE_COMPOSITE                      1
#define DAL_DISPLAY_OUTPUTTYPE_SVIDEO                         2
#define DAL_DISPLAY_OUTPUTTYPE_ANALOG                         3
#define DAL_DISPLAY_OUTPUTTYPE_DIGITAL                        4

#define DAL_DISPLAY_FEATUREFLAG_SMARTDETECTION_SUPPORTED      0x00000001

#ifdef WIN9X_BUILD

typedef struct _VIDEO_MODE_INFORMATION {
    ULONG Length;
    ULONG ModeIndex;
    ULONG VisScreenWidth;
    ULONG VisScreenHeight;
    ULONG ScreenStride;
    ULONG NumberOfPlanes;
    ULONG BitsPerPlane;
    ULONG Frequency;
    ULONG XMillimeter;
    ULONG YMillimeter;
    ULONG NumberRedBits;
    ULONG NumberGreenBits;
    ULONG NumberBlueBits;
    ULONG RedMask;
    ULONG GreenMask;
    ULONG BlueMask;
    ULONG AttributeFlags;
    ULONG VideoMemoryBitmapWidth;
    ULONG VideoMemoryBitmapHeight;
    ULONG DriverSpecificAttributeFlags;
} VIDEO_MODE_INFORMATION, FAR *LPVIDEO_MODE_INFORMATION;

//
// Bit definitions for Attribute Flags
//

#define VIDEO_MODE_COLOR            0x0001  // 0 = Mono-compatible, 1 = Color
#define VIDEO_MODE_GRAPHICS         0x0002  // 0 = Text mode, 1 = Graphics
#define VIDEO_MODE_PALETTE_DRIVEN   0x0004  // 0 = Colors are direct
                                            // 1 = Colors are index to a palette
#define VIDEO_MODE_MANAGED_PALETTE  0x0008  // 0 = Palette is fixed (must be
                                            //     queried from miniport
                                            // 1 = Palette is settable.
#define VIDEO_MODE_INTERLACED       0x0010  // 1 = Mode is interlaced
                                            // 0 = non-interlaced
#define VIDEO_MODE_NO_OFF_SCREEN    0x0020  // 1 = Offscreen memory CAN NOT be
                                            //     used to store information.
                                            // 0 = Offscreen memory is available
#define VIDEO_MODE_NO_64_BIT_ACCESS 0x0040  // 1 = 64 bit memory writes to frame
                                            //     buffer are not handled properly.
                                            // 0 = 64 bit memory writes to frame
                                            //     buffer are handled properly.

//
// DALBWVALIDATE.ulFlags: bit vector field
//

// If this bit is set, GCO will validate primary controller
// bandwidth; otherwise, it will assume primary controller 
// is not on.
#define DAL_BWV_PRIMARYVALIDATION         0x00000001

// This bit will only be used when 
// DAL_BWV_PRIMARYVALIDATION is set.
// If it is set, GCO will use mode info in the 
// lpModeInfo[DAL_PRIMARY_CONTROLLER] to validate primary
// badnwidth; otherwise, it will use current mode setting 
// in the GCO.  
#define DAL_BWV_PRIMARYUSEGIVENMODEINFO   0x00000002

// This bit will only be used when 
// DAL_BWV_PRIMARYVALIDATION is set.
#define DAL_BWV_PRIMARYOVERLAY            0x00000004

// This bit will only be used when 
// DAL_BWV_PRIMARYVALIDATION is set.
#define DAL_BWV_PRIMARYCAPTURE            0x00000008

// If this bit is set, GCO will validate secondary controller
// bandwidth; otherwise, it will assume secondary controller 
// is not on.
#define DAL_BWV_SECONDARYVALIDATION       0x00010000

// This bit will only be used when 
// DAL_BWV_SECONDARYVALIDATION is set.
// If it is set, GCO will use mode info in the 
// lpModeInfo[DAL_PRIMARY_CONTROLLER] to validate primary
// badnwidth; otherwise, it will use current mode setting 
// in the GCO.  
#define DAL_BWV_SECONDARYUSEGIVENMODEINFO 0x00000002

// This bit will only be used when 
// DAL_BWV_SECONDARYVALIDATION is set.
#define DAL_BWV_SECONDARYOVERLAY          0x00000004

// This bit will only be used when 
// DAL_BWV_SECONDARYVALIDATION is set.
#define DAL_BWV_SECONDARYCAPTURE          0x00000008

//
//Length - Length of the structure in bytes. Also used to do verisioning.
//
//ModeIndex - Number used to set this mode when calling the miniport driver.
//
//VisScreenWidth - Number of visible horizontal pixels on a scan line
//
//VisScreenHeight - Number of visible lines (or scan lines)
//
//ScreenStride - Delta, in *BYTES*, between the start of two scan lines.
//
//    NOTE: the width and height are in pixels, but the stride is in bytes !!!
//
//NumberOfPlanes - Number of separate planes combined by the device.
//
//BitsPerPlane - Number of bits per pixel on a plane.
//
//Frequency - Screen Frequency, in Hertz.
//
//XMillimeter - Size of the horizontal active region on the output device,
//    in millimeters.
//
//YMillimeter - Size of the vertical active region on the output device,
//    in millimeters.
//
//NumberRedBits - Number of bits in the red DAC.
//
//NumberGreenBits - Number of bits in the green DAC.
//
//NumberBlueBits - Number of bits in the blue DAC.
//
//RedMask - Red color Mask for device with direct color modes. Bits turned
//    on indicate the bit is of color Red.
//
//GreenMask - Green color Mask for device with direct color modes. Bits
//    turned on indicate the bit is of color Green.
//
//BlueMask - Blue color Mask for device with direct color modes. Bits
//    turned on indicate the bit is of color Blue.
//
//AttributeFlags. Flags indicating certain behavior for the device.
//
//VideoMemoryBitmapWidth - Width of the video memory bitmap.
//    VisScreenWidth <= VideoMemoryBitmapWidth <= ScreenStride
//
//VideoMemoryBitmapHeight - Height of the video memory bitmap.
//   VisScreenHeight <= VideoMemoryBitmapHeight = VideoRamLength / ScreenStride
//
//DriverSpecificAttributeFlags - Flags indicating certain behavior for the
//   device that are private to the miniport\display driver.
//


typedef struct _VIDEO_NUM_MODES {
    ULONG NumModes;
    ULONG ModeInformationLength;
} VIDEO_NUM_MODES, FAR *LPVIDEO_NUM_MODES;

//
//NumModes - Returns the number of modes supported by the kernel driver.
//
//ModeInformationLength - Length of the VIDEO_MODE_INFORMATION structure
//    for the IOCTL_VIDEO QUERY_AVAILABLE_MODES IOCTL.

#endif  // WIN9X_BUILD


// The following registry keys are shared among DAL - GCOs - GDOs
#define DALREGKEY_DDC1SUPPORT                    "DALRULE_DDC1SUPPORT"
#define DALREGKEY_MAXDDC1TRIES                   "DALOPTION_MAXDDC1TRIES"


// options definition,used for GCOProcessMiscINFO to get/set required info from GCO
#define GCO_PROCESSMISCINFO_VGAACTIVEDISPLAY     0x00000001L

//DisplayGetDeviceConfig related defination.
//ulConnectorType:Indicates type of the connector.
#define DAL_DISPLAY_CONTYPE_UNKNOWN           0
#define DAL_DISPLAY_CONTYPE_VGA               1
#define DAL_DISPLAY_CONTYPE_DVI_D             2
#define DAL_DISPLAY_CONTYPE_DVI_I             3
#define DAL_DISPLAY_CONTYPE_ATICVDONGLE_NA    4 
#define DAL_DISPLAY_CONTYPE_ATICVDONGLE_JP    5 
#define DAL_DISPLAY_CONTYPE_ATICVDONGLE_NONI2C   6 

//ulDeviceConfigCap
//Indicates what device configuration capabilities are supported. 
//DisplaySetDeviceConfig can be called for one of the supported capabilities only
// or the call will fail.

#define DAL_DISPLAY_DEVCONFIGCAP_480I         0x00000001
#define DAL_DISPLAY_DEVCONFIGCAP_480P         0x00000002
#define DAL_DISPLAY_DEVCONFIGCAP_540P         0x00000004
#define DAL_DISPLAY_DEVCONFIGCAP_720P         0x00000008
#define DAL_DISPLAY_DEVCONFIGCAP_1080I        0x00000010
#define DAL_DISPLAY_DEVCONFIGCAP_1080P        0x00000020
#define DAL_DISPLAY_DEVCONFIGCAP_16_9         0x00000040

#define DAL_DISPLAY_DEVCONFIGCAP_D1           0x00000001
#define DAL_DISPLAY_DEVCONFIGCAP_D2           0x00000002
#define DAL_DISPLAY_DEVCONFIGCAP_D3           0x00000004
#define DAL_DISPLAY_DEVCONFIGCAP_D4           0x00000008
#define DAL_DISPLAY_DEVCONFIGCAP_D5           0x00000010

#define DAL_DISPLAY_DEVCONFIGCAPEX_CVDONGLEOVERIDE  0x00000001
#define DAL_DISPLAY_DEVCONFIGCAPEX_CVMODEUNDERSCAN  0x00000002

//Bit vectors used for both dongle type
#define DAL_DISPLAY_DEVDATA_FLAG_UNDERSCAN   0x00000001

// The following is applicable to CONTYPE_ATICVDONGLE_NA only
#define DAL_DISPLAY_DEVDATA_480I        0x00000001
#define DAL_DISPLAY_DEVDATA_480P        0x00000002
#define DAL_DISPLAY_DEVDATA_540P        0x00000004
#define DAL_DISPLAY_DEVDATA_720P        0x00000008
#define DAL_DISPLAY_DEVDATA_1080I       0x00000010
#define DAL_DISPLAY_DEVDATA_1080P       0x00000020
#define DAL_DISPLAY_DEVDATA_16_9        0x00000040

#define DAL_DISPLAY_DEVDATA_NA_MASK  (DAL_DISPLAY_DEVDATA_480I| \
                                      DAL_DISPLAY_DEVDATA_480P| \
                                      DAL_DISPLAY_DEVDATA_540P| \
                                      DAL_DISPLAY_DEVDATA_720P| \
                                      DAL_DISPLAY_DEVDATA_1080I| \
                                      DAL_DISPLAY_DEVDATA_1080P| \
                                      DAL_DISPLAY_DEVDATA_16_9)


// The following is applicable to CONTYPE_ATICVDONGLE_JP only
#define DAL_DISPLAY_DEVDATA_D1          0x00000001
#define DAL_DISPLAY_DEVDATA_D2          0x00000002
#define DAL_DISPLAY_DEVDATA_D3          0x00000004
#define DAL_DISPLAY_DEVDATA_D4          0x00000008
#define DAL_DISPLAY_DEVDATA_D5          0x00000010

#define DAL_DISPLAY_DEVDATA_JP_MASK  (DAL_DISPLAY_DEVDATA_D1| \
                                      DAL_DISPLAY_DEVDATA_D2| \
                                      DAL_DISPLAY_DEVDATA_D3| \
                                      DAL_DISPLAY_DEVDATA_D4| \
                                      DAL_DISPLAY_DEVDATA_D5)

#define DAL_DISPLAY_DEVCONFIGCAP_NA_MASK  DAL_DISPLAY_DEVDATA_NA_MASK
#define DAL_DISPLAY_DEVCONFIGCAP_JP_MASK  DAL_DISPLAY_DEVDATA_JP_MASK
///////////////////////////////////////////////////////////////////////////
// DisplaySetConfig function related define
///////////////////////////////////////////////////////////////////////////
//ulDeviceConfigOption
#define DAL_DISPLAY_DEVCFGOPT_SETCVDONGLEOVERRIDE     1
#define DAL_DISPLAY_DEVCFGOPT_RESETCVDONGLEOVERRIDE   2

// DALDISPPREFEROPTIONS.ulOptions.  Bit vector
#define DAL_DISPPREFEROPTION_DISALLOW_PANNING_DEVCAP    0x00000001
#define DAL_DISPPREFEROPTION_DISALLOW_PANNING_BW        0x00000002 
#define DAL_DISPPREFEROPTION_HIGHER_DISP_RES            0x00000004
#define DAL_DISPPREFEROPTION_UP_SCALE                   0x00000008
#define DAL_DISPPREFEROPTION_DOWN_SCALE                 0x00000010
#define DAL_DISPPREFEROPTION_PRESERVE_ASPECT_RATIO      0x00000020
#define DAL_DISPPREFEROPTION_DONOT_USE_PANEL_SCALER     0x00000040

typedef struct _DISPPREFEROPTIONS
{
  ULONG ulOptions;
  ULONG ulMinSclQuality;
  ULONG ulMaxSclQuality;
} DALDISPPREFEROPTIONS, FAR *LPDALDISPPREFEROPTIONS;

#if defined(_X86_)
#pragma pack(pop)
#endif

#endif /*_DALBASE_H*/


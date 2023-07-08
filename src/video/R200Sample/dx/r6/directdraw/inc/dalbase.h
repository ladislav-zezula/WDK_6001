
 
/****************************************************************************\
*
*  Module Name    dalbase.h
*  Project        ATI Display Abstraction Layer
*  Device         RageProPNP / Rage128 (Win95/98 & WinNT 4.0/5.0)
*
*  Description    base header file for Display Abstraction Layer 0.90
*                 containing common type definitions and defines
*
*  (c) 1998 ATI Technologies Inc. (unpublished)
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

#pragma pack(1)

#define DAL_REVISION_MAJOR 0x0000
#define DAL_REVISION_MINOR 0x9000

#define DAL_REVISION ((QS_REVISION_MAJOR << 16) | QS_REVISION_MINOR)

#define GDO_CAPS_ACTIVATE_BEFORE_DETECT      0x00000001
#define MAX_NO_MONITOR_INFO_MODES            30

#define EDID_VERSION_10         0x00000100
#define EDID_VERSION_11         0x00000101
#define EDID_VERSION_12         0x00000102
#define EDID_VERSION_SIMULATED  0xFFFFFFFF
#define EDID_DISPLAY_NAME_SIZE  20

#define OVERLAY_FORMAT_YUY2     0x00000001 // 4-2-2 (16bits) format, packed
#define OVERLAY_FORMAT_UYVY     0x00000002 // 4-2-2 (16bits) format, packed
#define OVERLAY_FORMAT_YV12     0x00000003 // 4-2-0 (12bits) format, planar
#define OVERLAY_FORMAT_YVU9     0x00000004 // (9bits) ??, planar
#define OVERLAY_FORMAT_IF09     0x00000005 // (9bits) ??, planar
#define OVERLAY_FORMAT_RGB565   0x00000006 // 16 bits, packed
#define OVERLAY_FORMAT_RGB555   0x00000007 // 16 bits, packed
#define OVERLAY_FORMAT_RGB32    0x00000008 // 32 bits, packed

typedef struct _ADJUSTMENT_PARAMETERS
{

    USHORT      usCRTC_H_TOTAL;         // Horizontal total (pixels * 8)
    USHORT      usCRTC_H_SYNC_START;    // Horizontal sync start (pixels * 8)
    USHORT      usCRTC_V_TOTAL;         // Vertical tatal
    USHORT      usCRTC_V_SYNC_START;    // Vertical sync start

    //PLL stuff 10 bit for extended PLL
    //for secondary CRTC there is only extended

    USHORT      usPLL_REF_DIV;
    USHORT      usPLL_FB_DIV;           // This is for VClock (CRTC1 & CRTC2),
    UCHAR       ucPLL_POST_DIV;

} ADJUSTMENT_PARAMETERS, FAR *LPADJUSTMENT_PARAMETERS;


typedef struct _DEVCLUT
{
  UCHAR ucRed;
  UCHAR ucGreen;
  UCHAR ucBlue;
  UCHAR ucReserved;
} DEVCLUT, FAR *LPDEVCLUT;


#define DEVMODEFLAG_INTERLACED         0x00000001
#define DEVMODEFLAG_DIRECTDRAW         0x00000002
#define DEVMODEFLAG_LARGEDESKTOP       0x00000004
#define DEVMODEFLAG_VIEWRESTRICTED     0x00000008
#define DEVMODEFLAG_DEFUALTFREQUENCY   0x00000010
#define DEVMODEFLAG_OPTIMUMFREQUENCY   0x00000020
#define DEVMODEFLAG_DDMODEVALIDATE     0x00000040

typedef struct _DEVMODE_INFO
{
  ULONG ulModeFlags;
  ULONG ulPelsWidth;
  ULONG ulPelsHeight;
  ULONG ulBitsPerPixel;
  ULONG ulDisplayFrequency;
} DEVMODE_INFO, FAR *LPDEVMODE_INFO;

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

typedef struct _MONITOR_INFO
{
    ULONG   ulMaxHorizontalRes;
    ULONG   ulMaxVerticalRes;
    ULONG   ulMaxRefreshRate;
    ULONG   ulUseOverride;
    ULONG   ulDDCDisplay;
    MODE_SUPPORTED  aModeSupported[MAX_NO_MONITOR_INFO_MODES];
}MONITOR_INFO, FAR *LPMONITOR_INFO;

typedef struct _DDC_INFO
{
    UCHAR           DDCDisplayName[EDID_DISPLAY_NAME_SIZE];
    ULONG           ulDDCManufacturerName;
    ULONG           ulDDCProductCode;
    ULONG           ulDDCEdidVersion;
    MODE_SUPPORTED  DDCMaxModeSupported;
}DDC_INFO, FAR *LPDDC_INFO;

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

#pragma pack()

#endif /*_DALBASE_H*/


//
// $Archive: /3D/D3D/d3drage5/Rage5Direct3D/inc/ddraw/dalbase.h $
// $Author: Jweyman $
// $Revision: 2 $
// $Date: 2/16/99 5:19p $
// $Modtime: 2/16/99 4:55p $
// $History: dalbase.h $
// 
// *****************  Version 2  *****************
// User: Jweyman      Date: 2/16/99    Time: 5:19p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/ddraw
// added header/footer
//


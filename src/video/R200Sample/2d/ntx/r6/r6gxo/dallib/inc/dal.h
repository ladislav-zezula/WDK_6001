

/****************************************************************************\
*
*  Module Name    dal.h
*  Project        ATI Display Abstraction Layer
*  Device         RageProPNP / Rage128 (Win95/98 & WinNT 4.0/5.0)
*
*  Description    header file for Display Abstraction Layer 0.90
*
*
*  (c) 1998-2002 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  Refer to DAL Developers Guide & Programming Reference Rev 0.90 for usage
*
\****************************************************************************/

#ifndef _DAL_H
#define _DAL_H

#ifdef WIN9X_BUILD
#include <windows.h>
#include <memory.h>
#include <string.h>
#endif

#ifdef NT_BUILD
#include <ntddk.h>
#include <ntintsafe.h>
#include <dispmprt.h>
#endif

#include <driverspecs.h>

#ifdef DEBUG
#ifndef DBG
#define DBG
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_X86_)
#pragma pack(push, 1)
#endif

#define R200_TAG                        '002R'
#define BIOS_INFO_TABLE_OFFSET          0x0078
#define BIOS_INFO_TABLE_SIGNATURE       0x54504C24 // for '$LPT'
#define DRIVER_OPTIONS_16BPP_555        0x00000001 // By default we will assume
                                                   // 565 for 16 bpp. If this flag
                                                   // is set in DDLGetDriverOptions
                                                   // return value we will use 555
#define DAL_DEFAULT_ADAPTER_FREQUENCY   60
#define DAL_OPTIMUM_ADAPTER_FREQUENCY   250
#define DAL_DEFAULT_RETRYDDCWRITETIMES  0

#define DAL_ADJUSTMENT_OK               1
#define DAL_ADJUSTMENT_FAILED           2
#define DAL_ADJUSTMENT_REBOOT_REQUIRED  3

#define DAL_SET_DISPLAY_ADJUSTMENTS             1
#define DAL_GET_DISPLAY_ADJUSTMENTS             2
#define DAL_SET_DISPLAY_DEFAULT_ADJUSTMENTS     3

#define DAL_SET_DEFAULT_OBJECTMAP               0
#define DAL_SET_OBJECTMAP_DEFAULTS_ON_PRIMARY   1
#define DAL_SET_OBJECTMAP_DEFAULTS_1_DEVICE_CRT 2
#define DAL_SET_OBJECTMAP_DEFAULTS_CV           3

#define DAL_ENABLE_DRIVER_OK                                    1
#define DAL_ENABLE_DRIVER_DISPLAY_ALLOC_FAILURE                 2
#define DAL_ENABLE_DRIVER_CONTROLLER_ALLOC__FAILURE             3
#define DAL_ENABLE_DRIVER_BANDWIDTH_FAILURE                     4
#define DAL_ENABLE_DRIVER_INVALID_DRIVER_ID                     5
#define DAL_ENABLE_DRIVER_NOT_ENUOGH_DISPLAYS                   6
#define DAL_ENABLE_DRIVER_DISPLAYS_FOR_PRIMARY_INVALID          7
#define DAL_ENABLE_DRIVER_FUNCTION_DISABLED                     8

#define DAL_HTIME_ADJUSTMENT_BASIC                  0
#define DAL_HTIME_ADJUSTMENT_ONE_CONTROLLER         1
#define DAL_HTIME_ADJUSTMENT_TWO_CONTROLLERS        2

#define DAL_GETEXPANSIONSETTING_CMOS                0
#define DAL_GETEXPANSIONSETTING_HW                  1

#define DAL_TILINGMODE_LINEAR                       0
#define DAL_TILINGMODE_MACRO                        1
#define DAL_TILINGMODE_MICRO                        2
#define DAL_TILINGMODE_MACROMICRO                   3

#define CRC_ENABLE        1 
#define CRC_READ          2 
#define CRC_NOTREADY      0 

#define DAL_PRIMARY_CONTROLLER                      0
#define DAL_SECONDARY_CONTROLLER                    1
#define DAL_VGA_CONTROLLER                          DAL_PRIMARY_CONTROLLER

#define MMR_MEMMAPPED_REG 1
#define MMR_INDEXED_REG	  2

#define VPSYNC_LOW_PRIORITY             1
#define VPSYNC_MEDIUM_PRIORITY          2
#define VPSYNC_HIGH_PRIORITY            3

#define DAL_OVERLAY_32BPP_FULLBW                   0x00000001L
#define DAL_OVERLAY_32BPP_HALFBW                   0x00000002L
#define DAL_OVERLAY_16BPP_FULLBW                   0x00000003L

// Primary definition is in cwddedi.h
#ifndef MAX_REGISTRY_PATH
#define MAX_REGISTRY_PATH                       256 // Number of chars
#endif

/******************************Public*Definition*****************************\
*
* WINDOWS TYPE DEFINITIONS
*
\****************************************************************************/


#ifdef _NTDDK_

/*
typedef unsigned long BOOL;
typedef UCHAR        BYTE;

typedef HANDLE       FAR LPHANDLE;

typedef struct _POINT
{
  LONG  x;
  LONG  y;
} POINT, FAR *LPPOINT;

typedef struct tagSIZE
{
  LONG cx;
  LONG cy;
} SIZE, FAR *LPSIZE;

typedef struct _RECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT, FAR *LPRECT;
*/

#endif

#ifdef _INC_WINDOWS
#define BOOL ULONG
typedef char            CHAR;
typedef unsigned char   UCHAR;
typedef          short  SHORT;
typedef unsigned short  USHORT;
typedef unsigned long   ULONG;
typedef unsigned short  wchar_t;
typedef wchar_t         WCHAR;

typedef struct _W9X_POINT
{
  LONG  x;
  LONG  y;
} W9XPOINT, FAR *LPW9XPOINT;

typedef struct tagW9X_SIZE
{
  LONG cx;
  LONG cy;
} W9XSIZE, FAR *LPW9XSIZE;

typedef struct _W9X_RECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} W9XRECT, FAR *LPW9XRECT;

#define POINT   W9XPOINT
#define SIZE    W9XSIZE
#define RECT    W9XRECT

#define LPPOINT   LPW9XPOINT
#define LPSIZE    LPW9XSIZE
#define LPRECT    LPW9XRECT

#endif

typedef CHAR   FAR   *LPCHAR;
typedef void   FAR   *LPVOID;
typedef LONG   FAR   *LPLONG;
typedef ULONG  FAR   *LPULONG;
typedef UCHAR  FAR   *LPUCHAR;
typedef SHORT  FAR   *LPSHORT;
typedef USHORT FAR   *LPUSHORT;

#if !defined(NTBUILD) && (_WIN32_WINNT < 0x500) && !defined(ULONG_PTR)
typedef ULONG  ULONG_PTR;
#endif

typedef struct _FIXEDPOINT   FIXEDPOINT;
typedef struct _FIXEDPOINT   FAR *LPFIXEDPOINT;

typedef struct _BANDWID_TIME BANDWID_TIME;
typedef struct _BANDWID_TIME FAR *LPBANDWID_TIME;



/******************************Public*Definition*****************************\
*
* DEFINED VALUES
*
\****************************************************************************/

#define MAX_NUMBER_ENGINE         2                               

#define MAX_NUMBER_CONTROLLERS       2
#define MAX_NUMBER_DISPLAYS          7

#define HW_CONTROLLER_EXTENSION_SIZE 9216
#define HW_DISPLAY_EXTENSION_SIZE    2048
#define MAX_LCD_REFRESH_COUNT        3

#define HW_DISPLAY_TYPE_CRT                            0x00000001
#define HW_DISPLAY_TYPE_LCD                            0x00000002
#define HW_DISPLAY_TYPE_TV                             0x00000004
#define HW_DISPLAY_TYPE_DFP                            0x00000008
#define HW_DISPLAY_TYPE_CRT_2NDDAC                     0x00000010
#define HW_DISPLAY_TYPE_DFP_EXTTMDS                    0x00000020
#define HW_DISPLAY_TYPE_CV                             0x00000040
#define HW_DISPLAY_RESERVED07                          0x00000080
#define HW_DISPLAY_RESERVED08                          0x00000100
#define HW_DISPLAY_RESERVED09                          0x00000200
#define HW_DISPLAY_RESERVED0A                          0x00000400
#define HW_DISPLAY_RESERVED0B                          0x00000800
#define HW_DISPLAY_RESERVED0C                          0x00001000
#define HW_DISPLAY_RESERVED0D                          0x00002000
#define HW_DISPLAY_RESERVED0E                          0x00004000
#define HW_DISPLAY_RESERVED0F                          0x00008000
#define HW_DISPLAY_RESERVED10                          0x00010000
#define HW_DISPLAY_RESERVED11                          0x00020000
#define HW_DISPLAY_RESERVED12                          0x00040000
#define HW_DISPLAY_RESERVED13                          0x00080000
#define HW_DISPLAY_RESERVED14                          0x00100000
#define HW_DISPLAY_RESERVED15                          0x00200000
#define HW_DISPLAY_RESERVED16                          0x00400000
#define HW_DISPLAY_RESERVED17                          0x00800000
#define HW_DISPLAY_RESERVED18                          0x01000000
#define HW_DISPLAY_CV_UNDERSCAN                        0x02000000
#define HW_DISPLAY_DFP_MULTISYNC                       0x04000000
#define HW_DISPLAY_DFP_EXPANSION                       0x08000000
#define HW_DISPLAY_DFP                                 0x10000000
#define HW_DISPLAY_EXPANSION                           0x20000000
#define HW_DISPLAY_TV_STANDARD_PAL                     0x40000000
#define HW_DISPLAY_TV_STANDARD_NTSC                    0x80000000
#define HW_DISPLAY_UNKNOWN                             0x00000000

// DFP bootup behavior, define just display types mask - VG
#define HW_DISPLAY_TYPES_MASK                          (HW_DISPLAY_TYPE_CRT         \
                                                       | HW_DISPLAY_TYPE_LCD        \
                                                       | HW_DISPLAY_TYPE_TV         \
                                                       | HW_DISPLAY_TYPE_DFP        \
                                                       | HW_DISPLAY_TYPE_CV         \
                                                       | HW_DISPLAY_TYPE_CRT_2NDDAC \
                                                       | HW_DISPLAY_TYPE_DFP_EXTTMDS)

#define HW_DISPLAY_TYPES_CRT_MASK                      ( HW_DISPLAY_TYPE_CRT \
                                                        |HW_DISPLAY_TYPE_CRT_2NDDAC)

#define HW_DISPLAY_TYPES_DFP_MASK                      ( HW_DISPLAY_TYPE_DFP \
                                                        |HW_DISPLAY_TYPE_DFP_EXTTMDS)

#define HW_DISPLAY_TYPES_DIGITAL_MASK                  ( HW_DISPLAY_TYPE_LCD \
                                                        |HW_DISPLAY_TYPES_DFP_MASK)

#define DISPLAY_ADJUST_HORIZONTAL                      0x00000001
#define DISPLAY_ADJUST_VERTICAL                        0x00000002

#define GCO_HOOK_TEXT_CURSOR_BLINKING_ADJUSTMENT       0x00000001L
#define GCO_HOOK_OVERLAY_GAMMA_ADJUSTMENT              0x00000002L
#define GCO_HOOK_RATIOMETRIC_EXPANSION_ADJUSTMENT      0x00000004L
#define GCO_HOOK_OVERLAY_COLOR_GAMMA_ADJUSTMENT        0x00000008L
#define GCO_HOOK_OVERLAY_CONTRAST_ADJUSTMENT           0x00000010L
#define GCO_HOOK_OVERLAY_SATURATION_ADJUSTMENT         0x00000020L
#define GCO_HOOK_OVERLAY_HUE_ADJUSTMENT                0x00000040L
#define GCO_HOOK_OVERLAY_CHROMACITY_ADJUSTMENT         0x00000080L
#define GCO_HOOK_OVERLAY_BLACKWHITELEVEL_ADJUSTMENT    0x00000100L
#define GCO_HOOK_GETCRC                                0x00000200L
#define GCO_HOOK_GETHWDATA                             0x00000400L
#define GCO_HOOK_GETMODETIMING                         0x00000800L
#define GCO_CALCULATE_PEAK_MEMORY_BANDWIDTH            0x00001000L
#define GCO_HOOK_SETMODEEXTENDED                       0x00002000L
#define GCO_HOOK_ISDEVICEMAPPINGSUPPORTED              0x00004000L
#define GCO_HOOK_UPDATEBIOSDISPLAYINFO                 0x00008000L
#define GCO_HOOK_GAMMA16                               0x00010000L
#define GCO_HOOK_GETEXPANSIONSETTING                   0x00020000L
#define GCO_HOOK_GET_CONTROLLER_TIMINGS                0x00040000L
#define GCO_HOOK_ADJUST_HORIZONTAL_TIME                0x00080000L
#define GCO_CALCULATE_HALFFRAMEBUFFER_BANDWIDTH        0x00100000L
#define GCO_CALCULATE_HALFFRAMEBUFFER_HTIME            0x00200000L
#define GCO_HOOK_ENABLE_OVERLAY                        0x00400000L
#define GCO_HOOK_DFP_SIZE                              0x00800000L
#define GCO_HOOK_ACPI                                  0x01000000L
#define GCO_HOOK_SET_DISPLAY_OFFSET                    0x02000000L
#define GCO_HOOK_GET_HARDWARE_INFO_TABLE               0x04000000L
#define GCO_HOOK_GET_MULTIMEDIA_TABLE                  0x08000000L
#define GCO_CALCULATE_MEMORY_BANDWIDTH                 0x10000000L
#define GCO_CALCULATE_HORIZONTAL_TIME                  0x20000000L
#define GCO_HOOK_GAMMA_CORRECTION                      0x40000000L
#define GCO_HOOK_MODE_CHANGES                          0x80000000L

#define GCO_HOOK2_VALIDATEMODE                         0x00000001L
#define GCO_HOOK2_OVERLAYALLOCATION                    0x00000002L
#define GCO_HOOK2_CONTROLLERTESTHARNESS                0x00000004L
#define GCO_HOOK2_GETSYSTEMBIOSINFO                    0x00000008L
#define GCO_HOOK2_OVERLAY_ALPHA_ADJUSTMENT             0x00000010L
#define GCO_HOOK2_POWERPLAY                            0x00000020L
#define GCO_HOOK2_SETPOWERSTATE                        0x00000040L
#define GCO_HOOK2_GETCLKINFO                           0x00000080L
#define GCO_HOOK2_SETCLKCONFIG                         0x00000100L
#define GCO_HOOK2_CALCULATE_PEAK_MEMORY_BANDWIDTH_EX   0x00000200L
#define GCO_HOOK2_CALCULATE_MODE_BANDWIDTH_EX          0x00000400L
#define GCO_HOOK2_SETEVENT                             0x00000800L
#define GCO_HOOK2_PROCESSMISCINFO                      0x00001000L
#define GCO_HOOK2_GETDISPLAYXYPOS                      0x00002000L
#define GCO_HOOK2_SETDISPLAYXYPOS                      0x00004000L
#define GCO_HOOK2_SETCRTCTILELINE                      0x00008000L
#define GCO_HOOK2_GETREDUCEDBLANKINGADJUSTMENT         0x00010000L
#define GCO_HOOK2_SETREDUCEDBLANKINGADJUSTMENT         0x00020000L
#define GCO_HOOK2_GETTMDSiCOHERENTMODEADJUSTMENT       0x00040000L
#define GCO_HOOK2_SETTMDSiCOHERENTMODEADJUSTMENT       0x00080000L
#define GCO_HOOK2_RESERVED14                           0x00100000L
#define GCO_HOOK2_RESERVED15                           0x00200000L
#define GCO_HOOK2_RESERVED16                           0x00400000L
#define GCO_HOOK2_RESERVED17                           0x00800000L
#define GCO_HOOK2_RESERVED18                           0x01000000L
#define GCO_HOOK2_RESERVED19                           0x02000000L
#define GCO_HOOK2_RESERVED1A                           0x04000000L
#define GCO_HOOK2_RESERVED1B                           0x08000000L
#define GCO_HOOK2_RESERVED1C                           0x10000000L
#define GCO_HOOK2_RESERVED1D                           0x20000000L
#define GCO_HOOK2_GCO_PROVIDE_SERVICE                  0x40000000L
#define GCO_HOOK2_SETMODEEXTENDED2                     0x80000000L

#define GCO_HOOK3_SETSCALER                            0x00000001L
#define GCO_HOOK3_VALIDATEALLBW                        0x00000002L
#define GCO_HOOK3_GETASPECRATIO                        0x00000004L
#define GCO_HOOK3_GETDISPPREFEROPTIONS                 0x00000008L
#define GCO_HOOK3_OVERLAYALLOCATIONEX                  0x00000010L
#define GCO_HOOK3_GETPALETTE                           0x00000020L

#define GCO_EVENT_SETDDEXCLUSIVEMODE                   0x00000001L
#define GCO_EVENT_RESETDDEXCLUSIVEMODE                 0x00000002L
#define GCO_EVENT_ENABLEEXTDESKTOPMODE                 0x00000003L
#define GCO_EVENT_DISABLEEXTDESKTOPMODE                0x00000004L
#define GCO_EVENT_FORCENORMALPOWERSTATE                0x00000005L
#define GCO_EVENT_SETTILINGMODE                        0x00000006L
#define GCO_EVENT_RESUME                               0x00000007L

#define GDO_HOOK_BRIGHTNESS_ADJUSTMENT                 0x00000001L
#define GDO_HOOK_CHROMA_FLICKER_REMOVAL_ADJUSTMENT     0x00000002L
#define GDO_HOOK_COLOR_CONTROL_ADJUSTMENT              0x00000004L
#define GDO_HOOK_CONTRAST_ADJUSTMENT                   0x00000008L
#define GDO_HOOK_VERTICAL_POSITION_ADJUSTMENT          0x00000010L
#define GDO_HOOK_HORIZONTAL_POSITION_ADJUSTMENT        0x00000020L
#define GDO_HOOK_VERTICAL_SIZE_ADJUSTMENT              0x00000040L
#define GDO_HOOK_HORIZONTAL_SIZE_ADJUSTMENT            0x00000080L
#define GDO_HOOK_DOT_CRAWL_ADJUSTMENT                  0x00000100L
#define GDO_HOOK_FILTER_SVIDEO_ADJUSTMENT              0x00000200L
#define GDO_HOOK_FILTER_COMP_ADJUSTMENT                0x00000400L
#define GDO_HOOK_GAMMA_ADJUSTMENT                      0x00000800L
#define GDO_HOOK_LUMA_FLICKER_REMOVAL_ADJUSTMENT       0x00001000L
#define GDO_HOOK_OVERSCAN_ADJUSTMENT                   0x00002000L
#define GDO_HOOK_VIDEO_STANDARD_ADJUSTMENT             0x00004000L
#define GDO_HOOK_VIDEO_SIGNAL_STANDARD_ADJUSTMENT      0x00008000L
#define GDO_HOOK_MULTIMEDIAPASSTHRU_ADJUSTMENT         0x00010000L
#define GDO_HOOK_INTERLACED                            0x00020000L
#define GDO_HOOK_HORIZONTAL_SYNC                       0x00040000L
#define GDO_HOOK_VERTICAL_SYNC                         0x00080000L
#define GDO_HOOK_COMPOSITE_SYNC                        0x00100000L
#define GDO_HOOK_FRAMEMODULATION                       0x00200000L
#define GDO_HOOK_HUE_ADJUSTMENT                        0x00400000L
#define GDO_HOOK_SATURATION_ADJUSTMENT                 0x00800000L
#define GDO_HOOK_TEMPERATURE_ADJUSTMENT                0x01000000L
#define GDO_HOOK_COLORSPACECONVERSION                  0x02000000L
#define GDO_ENDOF_ADJUSTMENTS                          0x04000000L

#define GDO_HOOK_BLANKING                              0x04000000L
#define GDO_HOOK_GET_EDID_DATA                         0x08000000L // Obsolete!
#define GDO_HOOK_LIDSTATE                              0x10000000L
#define GDO_HOOK_MODE_CHANGES                          0x20000000L
#define GDO_HOOK_DPMS                                  0x40000000L
#define GDO_HOOK_MACROVISION                           0x80000000L

#define GDO_HOOK2_PREADJUSTMENTCHANGE                  0x00000001L
#define GDO_HOOK2_POSTADJUSTMENTCHANGE                 0x00000002L
#define GDO_HOOK2_ALIGNER                              0x00000004L
#define GDO_HOOK2_DISPLAYTESTHARNESS                   0x00000008L
#define GDO_HOOK2_SETDSPLCONNECTOR                     0x00000010L
#define GDO_HOOK2_DDCPREDDCQUERY                       0x00000020L
#define GDO_HOOK2_DDCREADLINE                          0x00000040L
#define GDO_HOOK2_DDCWRITELINE                         0x00000080L
#define GDO_HOOK2_DDCPOSTDDCQUERY                      0x00000100L
#define GDO_HOOK2_ENABLESIBLING                        0x00000200L
#define GDO_HOOK2_GETPMREFRESHRATE_SUPPORTED           0x00000400L
#define GDO_HOOK2_SETREFRESHRATE_SUPPORTED             0x00000800L
#define GDO_HOOK2_HOTPLUGABLEDEVICE                    0x00001000L
#define GDO_HOOK2_INITIALIZE_DEVICE                    0x00002000L
#define GDO_HOOK2_CGMS_ADJUSTMENT                      0x00004000L
#define GDO_HOOK2_DISPLAYGETDEVICEINFO                 0x00008000L
#define GDO_HOOK2_MACROVISION_SUPPORT_CHECK            0x00010000L //Per mode
#define GDO_HOOK2_I2C_SUPPORT                          0x00020000L
#define GDO_HOOK2_SETPOWERSTATE                        0x00040000L
#define GDO_HOOK2_GETFIXEDDISPLAYMODES                 0x00080000L
#define GDO_HOOK2_GETFIXEDDISPLAYMODETIMING            0x00100000L
#define GDO_HOOK2_DISPLAYISMODESUPPORTED_EX            0x00200000L
#define GDO_HOOK2_SETMODEEXTENDED                      0x00400000L
#define GDO_HOOK2_ACPI                                 0x00800000L
#define GDO_HOOK2_GET_MONITOR_INFO                     0x01000000L

#define DAL_CONTROLLER_CAPS_EXPANSION                  0x00000001L
#define DAL_CONTROLLER_CAPS_OVERLAY                    0x00000002L
#define DAL_CONTROLLER_CAPS_VGA                        0x00000004L
#define DAL_CONTROLLER_CAPS_HW_CURSOR                  0x00000008L
#define DAL_CONTROLLER_CAPS_HW_ICON                    0x00000010L
#define DAL_CONTROLLER_CAPS_OVERLAY_GAMMA              0x00000020L
#define DAL_CONTROLLER_CAPS_CURSOR_BLINK               0x00000040L
#define DAL_CONTROLLER_CAPS_EXCLUSIVE_HW_CURSOR_ICON   0x00000080L
#define DAL_CONTROLLER_CAPS_SWITCHABLE_OVERLAY         0x00000100L
#define DAL_CONTROLLER_CAPS_SHADOW_REGISTER_SET        0x00000200L
#define DAL_CONTROLLER_CAPS_BWCALCULATION              0x00000400L
#define DAL_CONTROLLER_CAPS_RESERVED12                 0x00000800L
#define DAL_CONTROLLER_CAPS_AMC8BIT_PORT1              0x00001000L
#define DAL_CONTROLLER_CAPS_AMC8BIT_PORT2              0x00002000L
#define DAL_CONTROLLER_CAPS_AMC16BIT_PORT              0x00004000L /*16Bit VIP port physically shared with 8bit port1 and port2*/
#define DAL_CONTROLLER_CAPS_RESERVED0x00008000         0x00008000L
#define DAL_CONTROLLER_CAPS_SETCRT2ANDTVEXCLUSIVE      0x00010000L
#define DAL_CONTROLLER_CAPS_SETCVEXCLUSIVE             0x00020000L // twdal#8674
#define DAL_CONTROLLER_CAPS_HTIMETWOCRTC               0x00040000L

#define DAL_CONTROLLER_OVERLAY_ALLOCATED               0x00000001L //for ulControllerFlags
#define DAL_CONTROLLER_OVERLAY_RGB                     0x00000002L

#define DAL_MULTIMEDIA_AMC_8BIT_PORT1                  0x00000001L //for ulMultiMediaInfo
#define DAL_MULTIMEDIA_AMC_8BIT_PORT2                  0x00000002L
#define DAL_MULTIMEDIA_AMC_16BIT_PORT                 (0x00000004L | \
                                     DAL_MULTIMEDIA_AMC_8BIT_PORT1 | \
                                     DAL_MULTIMEDIA_AMC_8BIT_PORT2)

#define DRIVERSTATE_PSEUDOLARGEDESKTOPSET              0x00000001L

#define DAL_DISPLAY_ECAPS_MACROVISIONSUPPORTED         0x00000001L
#define DAL_DISPLAY_ECAPS_HPDSUPPORTED                 0x00000002L
#define DAL_DISPLAY_ECAPS_USEDSHAREDRESOURCE           0x00000004L
#define DAL_DISPLAY_ECAPS_DUMBDONGLEINTERFACE          0x00000008L
//#define DAL_DISPLAY_ECAPS_GCOSETADJUSTMENT             0x00000010L //atomic GCO take over size,position, Hsyc adjustment 

#define DAL_DISPLAY_TVTYPE_IMPACTTV_1                  1
#define DAL_DISPLAY_TVTYPE_IMPACTTV_2A                 2
#define DAL_DISPLAY_TVTYPE_IMPACTTV_2B                 3
#define DAL_DISPLAY_TVTYPE_IMPACTTV_2PLUSA             4
#define DAL_DISPLAY_TVTYPE_IMPACTTV_2PLUSB             5
#define DAL_DISPLAY_TVTYPE_IMPACTTV_LTPRO              6
#define DAL_DISPLAY_TVTYPE_RIPPER                      7

#define DAL_DISPLAY_VIDEO_FORMAT_NTSC_M                0x00000001L
#define DAL_DISPLAY_VIDEO_FORMAT_NTSC_M_JPN            0x00000002L
#define DAL_DISPLAY_VIDEO_FORMAT_NTSC_N                0x00000004L
#define DAL_DISPLAY_VIDEO_FORMAT_PAL_B                 0x00000008L
#define DAL_DISPLAY_VIDEO_FORMAT_PAL_COMB_N            0x00000010L
#define DAL_DISPLAY_VIDEO_FORMAT_PAL_D                 0x00000020L
#define DAL_DISPLAY_VIDEO_FORMAT_PAL_G                 0x00000040L
#define DAL_DISPLAY_VIDEO_FORMAT_PAL_H                 0x00000080L
#define DAL_DISPLAY_VIDEO_FORMAT_PAL_I                 0x00000100L
#define DAL_DISPLAY_VIDEO_FORMAT_PAL_K                 0x00000200L
#define DAL_DISPLAY_VIDEO_FORMAT_PAL_K1                0x00000400L
#define DAL_DISPLAY_VIDEO_FORMAT_PAL_L                 0x00000800L
#define DAL_DISPLAY_VIDEO_FORMAT_PAL_M                 0x00001000L
#define DAL_DISPLAY_VIDEO_FORMAT_PAL_N                 0x00002000L
#define DAL_DISPLAY_VIDEO_FORMAT_SECAM_D               0x00004000L
#define DAL_DISPLAY_VIDEO_FORMAT_SECAM_K               0x00008000L
#define DAL_DISPLAY_VIDEO_FORMAT_SECAM_K1              0x00010000L
#define DAL_DISPLAY_VIDEO_FORMAT_SECAM_L               0x00020000L

#define DAL_EVENT_DRIVERENABLE                         0x00000001L
#define DAL_EVENT_DRIVERDISABLE                        0x00000002L
#define DAL_EVENT_DRIVERSETMODE                        0x00000003L
#define DAL_EVENT_DRIVERRESETMODE                      0x00000004L
#define DAL_EVENT_CONTROLLERPREMODECHANGE              0x00000005L
#define DAL_EVENT_CONTROLLERPOSTMODECHANGE             0x00000006L

#define DAL_MODECHANGE_MAJOR_DESKTOPRESORBPPCHANGE     0x00000001L
#define DAL_MODECHANGE_MAJOR_VIEWRESORBPPCHANGE        0x00000002L
#define DAL_MODECHANGE_MINOR_RATIOMETRICEXPANSIONON    0x00000001L
#define DAL_MODECHANGE_MINOR_VIEWRESCHANGE             0x00000002L
#define DAL_MODECHANGE_MINOR_EXPANSIONONCHANGE         0x00000004L

  // I2C lines, parameter for DDCReadLine and DDCWriteLine hooks
#define DAL_DDC_I2C_LINE_SDA          0
#define DAL_DDC_I2C_LINE_SCL          1

#define DAL_GCO_MEMSEG_MIN_INDEX                       0
#define DAL_GCO_MEMSEG_MAX_INDEX                       (DAL_GCO_MEMSEG_MIN_INDEX+MAX_NUMBER_CONTROLLERS-1)
#define DAL_GDO_MEMSEG_MIN_INDEX                       (DAL_GCO_MEMSEG_MAX_INDEX+1)
#define DAL_GDO_MEMSEG_MAX_INDEX       		       (DAL_GDO_MEMSEG_MIN_INDEX+MAX_NUMBER_DISPLAYS-1)
#define DAL_MAX_MEMSEG_ALLOCATION                      (DAL_GDO_MEMSEG_MAX_INDEX+1)

#define DAL_I2C_GET_DATA_FROM_GDO          0    //Write back data stream 
#define DAL_I2C_GET_ADDR_FROM_GDO          1    //located address
#define DAL_I2C_SET_DATA_TO_GDO            2    //raw device data
#define DAL_I2C_SET_ADDR_TO_GDO            3    //scanned address
#define DAL_I2C_SET_DATA_TO_GDO_OVERRIDE   4    //DAL device data
#define DAL_I2C_GET_DEVICE_DATA_FROM_GDO   5    //device data in DAL's format
#define DAL_I2C_GET_DEVICE_CAP_FROM_GDO    6    //device cap
#define DAL_I2C_DEVICE_DATA_TRANSLATE      7    //Translate gdo format to dal format
#define DAL_I2C_DEVICE_DATA_UNDERSCAN      8    //Gdo will use underscan modetiming


#define EIAJ_DONGLE_ADDRESS                0x42  
/******************************Public*Definition*****************************\
*
* DAL TYPE DEFINITIONS
*
\****************************************************************************/

typedef struct _DALMEMSEG
{
  ULONG  ulSize;
  LPVOID lpMem;
} DALMEMSEG, FAR *LPDALMEMSEG;

typedef struct _SDALMEM
{
  ULONG     ulSize;
  ULONG     ulNumEntries;
  DALMEMSEG aMemSeg[DAL_MAX_MEMSEG_ALLOCATION];
} SDALMEM, FAR *LPDALMEM;

typedef void FAR *HDAL;
typedef void FAR *HDDL;
typedef void FAR *HGCO;
typedef void FAR *HGDO;

typedef struct _HW_ADJUSTMENT            HW_ADJUSTMENT;
typedef struct _HW_ADJUSTMENT            FAR *LPHW_ADJUSTMENT;
typedef struct _HW_ASIC_ID               HW_ASIC_ID;
typedef struct _HW_ASIC_ID               FAR *LPHW_ASIC_ID;
typedef struct _HW_CONTROLLER_ENABLEDATA HW_CONTROLLER_ENABLEDATA;
typedef struct _HW_CONTROLLER_ENABLEDATA FAR *LPHW_CONTROLLER_ENABLEDATA;
typedef struct _HW_DISPLAY_ENABLEDATA    HW_DISPLAY_ENABLEDATA;
typedef struct _HW_DISPLAY_ENABLEDATA    FAR *LPHW_DISPLAY_ENABLEDATA;

typedef struct _ADJUSTMENT_PARAMETERS    ADJUSTMENT_PARAMETERS;
typedef struct _ADJUSTMENT_PARAMETERS    FAR *LPADJUSTMENT_PARAMETERS;

typedef struct _DEVCLUT                  DEVCLUT;
typedef struct _DEVCLUT                  FAR *LPDEVCLUT;
typedef struct _DEVMODE_INFO             DEVMODE_INFO;
typedef struct _DEVMODE_INFO             FAR *LPDEVMODE_INFO;

typedef struct _GCO_QUERY_STRUCTURE      GCO_QUERY_STRUCTURE;
typedef struct _GCO_QUERY_STRUCTURE      FAR *LPGCO_QUERY_STRUCTURE;
typedef struct _GCO_CONTROLLER_TIMINGS   GCO_CONTROLLER_TIMINGS;
typedef struct _GCO_CONTROLLER_TIMINGS   FAR *LPGCO_CONTROLLER_TIMINGS;
typedef struct _GCO_HW_REGISTER          GCO_HW_REGISTER;
typedef struct _GCO_HW_REGISTER          FAR *LPGCO_HW_REGISTER;
typedef struct _GCO_SYSTEMBIOSINFO       FAR *LPGCO_SYSTEMBIOSINFO;
typedef struct _GCO_SERVICE              FAR *LPGCO_SERVICE;
typedef struct _RESOLUTION_INFO          FAR *LPDALRESOLUTION_INFO;
typedef struct _BWV_MODEINFO             FAR *LPDALBWV_MODEINFO;
typedef struct _BWVALIDATE               FAR *LPDALBWVALIDATE;

typedef enum   _MACROVISION_MODE         MACROVISION_MODE;

typedef struct _HORIZONTAL_TIME          HORIZONTAL_TIME;
typedef struct _HORIZONTAL_TIME          FAR * LPHORIZONTAL_TIME;

#include "dalbase.h"
#include "libver.h"

/******************************Public*Definition*****************************\
*
* FUNCTION TYPEDEF
*
* This FUNCTION TYPEDEF must be defined after DAL TYPE DEFINITIONS. Otherwise
* it will cause compiler errors in 16 bit build environment.
\****************************************************************************/

typedef BOOL (FAR *PFNDALTIMINGS)(LPHANDLE, ULONG, LPADJUSTMENT_PARAMETERS);

typedef VOID (FAR *PFNGCODISABLE)(HGCO);   // (VOID FAR)RageProDisable, (VOID FAR)RageProAcceleratorToVgaMode
typedef BOOL (FAR *PFNGCOENABLE)(HDDL, HGCO, LPHW_ASIC_ID, LPHW_CONTROLLER_ENABLEDATA);  // (BOOL FAR)RageProEnable
typedef BOOL (FAR *PFNGCOENUMERATEMODE)(HGCO, LPDEVMODE_INFO, ULONG, ULONG);  // (BOOL FAR)RageProEnumerateStandardModes
typedef VOID (FAR *PFNGCOGETCRTCLINE)(HGCO, ULONG, LPULONG);
typedef VOID (FAR *PFNGCOGETGAMMA)(HGCO, ULONG, LPDEVCLUT);    // (VOID FAR)RageProGetGammaCorrection, (VOID FAR)RageProSetGammaCorrection
typedef VOID (FAR *PFNGCOGETGAMMA16)(HGCO, ULONG, LPDEVCLUT16);    // (VOID FAR)RageProGetGammaCorrection, (VOID FAR)RageProSetGammaCorrection
typedef VOID (FAR *PFNGCOGETBLINKOVERLAY)(HGCO, LPHW_ADJUSTMENT);       // (VOID FAR)RageProGetTextCursorBlinkingAdjustment
typedef BOOL (FAR *PFNGCONONSTANDARDMODE)(HGCO, LPDEVMODE_INFO, ULONG); // (BOOL FAR)RageProIsNonStandardModeSupported
typedef VOID (FAR *PFNGCOMODECHANGE)(HGCO, LPDEVMODE_INFO, ULONG); // (VOID FAR)RageProPreModeChange, (VOID FAR)RageProPostModeChange
typedef VOID (FAR *PFNGCOSETMODE)(HGCO, LPDEVMODE_INFO, ULONG, ULONG, ULONG, ULONG);  // (BOOL FAR)RageProSetMode
typedef VOID (FAR *PFNGCOSETPALETTE)(HGCO, ULONG, LPDEVCLUT, ULONG, ULONG);  // 
typedef VOID (FAR *PFNGCOGETPALETTE)(HGCO, ULONG, LPDEVCLUT, ULONG, ULONG);  // 
typedef VOID (FAR *PFNGCOSETBLINKOVERLAY)(HGCO, LONG);  // (VOID FAR)RageProSetTextCursorBlinkingAdjustment
typedef VOID (FAR *PFNGCOSETDISPLAYOFFSET)(HGCO, ULONG, ULONG);
typedef BOOL (FAR *PFNGCOTIMINGS)(HGCO, ULONG, LPADJUSTMENT_PARAMETERS);  // (BOOL FAR)RageProSetAdjustmentTimings
typedef BOOL (FAR *PFNGCOGETMULTIMEDIATABLE)(HGCO, LPUCHAR, LPULONG); // RageProGetMultimediaTable
typedef BOOL (FAR *PFNGCOGETHARDWAREINFOTABLE)(HGCO, LPUCHAR, LPULONG); // RageProGetHardwareInfoTable
typedef VOID (FAR *PFNGCOGETINFO)(HGCO, ULONG, LPGCO_QUERY_STRUCTURE);
typedef BOOL (FAR *PFNGCOGETSYSTEMBIOSINFO)(HGCO, ULONG, LPGCO_SYSTEMBIOSINFO);  // This function will get system BIOS related infromation
// EPR# 36064 typedef VOID (FAR *PFNGCOSETPOWERSTATE)(HGCO, ULONG);
typedef VOID (FAR *PFNGCOSETDFPSIZE)(HGCO, ULONG, ULONG, ULONG);
typedef VOID (FAR *PFNGCOGETPOWERSTATECAPS)(HGCO, LPULONG);
typedef VOID (FAR *PFNGCOENABLEOVERLAY)(HGCO, ULONG);
typedef VOID (FAR *PFNGCOGETCRTCTIMINGS)(HGCO, ULONG, LPGCO_CONTROLLER_TIMINGS);
typedef BOOL (FAR *PFNGCOGETEXPANSION)(HGCO, ULONG, ULONG);
typedef VOID (FAR *PFNGCOUPDATEBIOSDISPLAYINFO)(HGCO, LPULONG, ULONG, ULONG, ULONG);
typedef BOOL (FAR *PFNGCOISDEVICEMAPPINGSUPPORTED)(HGCO, ULONG, ULONG);
typedef BOOL (FAR *PFNGCOSETMODEEXTENDED)(HGCO, LPDEVMODE_INFO, ULONG, ULONG, ULONG, ULONG,
                                          LPDAL_DISPLAY_TIMING_INFO);
typedef BOOL (FAR *PFNGCOSETMODEEXTENDED2)(HGCO, LPDEVMODE_INFO, ULONG, ULONG,
                                           LPDAL_DISPLAY_TIMING_INFO);
typedef ULONG (FAR *PFNGCOSERVICE)(HGCO, ULONG, LPGCO_SERVICE);

typedef BOOL (FAR *PFNGCOVALIDATEMODE)(HGCO, ULONG, LPDEVMODE_INFO, LPDAL_DISPLAY_TIMING_INFO);
typedef VOID (FAR *PFNGCOGETTOTALHTIME)(HGCO, LPHORIZONTAL_TIME, LPDEVMODE_INFO, ULONG);
typedef VOID (FAR *PFNGCOGETTOTALBW)(HGCO, LPFIXEDPOINT);

typedef VOID (FAR *PFNGCOCALCMODEBW)(HGCO, LPDEVMODE_INFO, LPFIXEDPOINT);
typedef VOID (FAR *PFNGCOCALCMODEBWEX)(HGCO, LPDEVMODE_INFO, LPDAL_CRTC_TIMING, LPFIXEDPOINT, ULONG);
typedef VOID (FAR *PFNGCOCALCOVBW)(HGCO, ULONG, LPDEVMODE_INFO, LPFIXEDPOINT);
typedef VOID (FAR *PFNGCOCALCVIDEOBW)(HGCO, LPDEVMODE_INFO, LPFIXEDPOINT);
typedef BOOL (FAR *PFNGCOCALCHFBBW)(HGCO, LPDEVMODE_INFO, LPFIXEDPOINT);

typedef VOID (FAR *PFNGCOCALCMODEHTIME)(HGCO, LPDEVMODE_INFO, LPHORIZONTAL_TIME);
typedef VOID (FAR *PFNGCOCALCOVHTIME)(HGCO, ULONG, LPDEVMODE_INFO, LPHORIZONTAL_TIME);
typedef VOID (FAR *PFNGCOCALCVIDEOHTIME)(HGCO, LPDEVMODE_INFO, LPHORIZONTAL_TIME);
typedef BOOL (FAR *PFNGCOCALCHFBHTIME)(HGCO, LPDEVMODE_INFO, LPHORIZONTAL_TIME);
typedef BOOL (FAR *PFNGCOCALCHTIMEADJUST)(HGCO, LPHORIZONTAL_TIME, LPHORIZONTAL_TIME, LPDEVMODE_INFO, ULONG, LPULONG);
typedef ULONG (FAR *PFNGCOGETCRC)(HGCO, ULONG,ULONG);
typedef ULONG (FAR *PFNGCOGETHARDWAREDATA)(HGCO,ULONG,ULONG,LPGCO_HW_REGISTER);
typedef BOOL (FAR *PFNGETMODETIMING)(HGCO, ULONG, LPDEVMODE_INFO, LPDAL_CRTC_TIMING);
typedef BOOL (FAR *PFNGETDETAILEDMODETIMING)(HGCO, ULONG, LPDEVMODE_INFO, LPDAL_CRTC_TIMING); 

typedef BOOL (FAR *PFNGCOGETPOWERSTATE)(HGCO, LPULONG, LPULONG, LPDAL_ADAPTERPOWERSTATES);
typedef ULONG (FAR *PFNGCOSETPOWERSTATE)(HGCO, ULONG);
typedef ULONG (FAR *PFNGCOVALIDATEPOWERSTATE)(HGCO, ULONG, ULONG, LPDAL_CRTC_TIMING, DEVMODE_INFO);
typedef VOID (FAR *PFNGCOSETPOWERSTATEEX)(HGCO, ULONG, ULONG);

typedef BOOL (FAR *PFNGCOALLOCOVERLAY)(HGCO, ULONG, ULONG,ULONG,ULONG);
typedef BOOL (FAR *PFNGCOALLOCOVERLAYEX)(HGCO, ULONG, ULONG,ULONG,ULONG,ULONG);
typedef VOID (FAR *PFNGCOFREEOVERLAY)(HGCO, ULONG);
typedef ULONG (FAR *PFNGCOCONTROLLERTESTHARNESS) (HGCO, LPVOID, LPVOID);
typedef VOID (FAR *PFNGCOGETCLOCKINFO)(HGCO, LPDAL_ADAPTERCLOCK_INFO);
typedef ULONG (FAR *PFNGCOVALIDATECLOCKCONFIG)(HGCO, LPDAL_GCOCLK_CONFIG);
typedef BOOL (FAR *PFNGCOSETEVENT)(HGCO, ULONG, ULONG, ULONG);

typedef VOID (FAR *PFNGCOPROCESSMISCINFO)(HGCO, ULONG, ULONG, LPVOID);

typedef VOID (FAR *PFNGCOGETDISPLAYXYPOS)(HGCO, ULONG, LPULONG, LPULONG);
typedef VOID (FAR *PFNGCOSETDISPLAYXYPOS)(HGCO, ULONG, ULONG, ULONG);

typedef VOID (FAR *PFNGCOSETCRTCTILELINE)(HGCO, ULONG, ULONG);

typedef BOOL (FAR *PFNGCOSETSCALER)(HGCO, ULONG, LPDALRESOLUTION_INFO, LPDALRESOLUTION_INFO, ULONG);
typedef BOOL (FAR *PFNGCOVALIDATEALLBW)(HGCO, ULONG, LPDALBWVALIDATE, ULONG);
typedef BOOL (FAR *PFNGCOGETASPECRATIO)(HGCO, ULONG, ULONG, LPDALBWV_MODEINFO, LPDALRESOLUTION_INFO,ULONG, ULONG);
typedef VOID (FAR *PFNGCOGETDISPPREFEROPTIONS)(HGCO, ULONG, ULONG, LPDALDISPPREFEROPTIONS, ULONG);

typedef VOID (FAR *PFNGDODISABLE)(HGDO);
typedef BOOL (FAR *PFNGDOENABLE)(HDDL, HGDO, LPHW_ASIC_ID, LPHW_DISPLAY_ENABLEDATA);
typedef VOID (FAR *PFNGDOBLANKING)(HGDO, ULONG, BOOL);
typedef BOOL (FAR *PFNGDOCONNECT)(HGDO);
typedef BOOL (FAR *PFNGDOLIDSTATE)(HGDO);
typedef VOID (FAR *PFNGDODISPLAYONOFF)(HGDO, ULONG);
typedef VOID (FAR *PFNGDOSETDPMS)(HGDO, ULONG);
typedef VOID (FAR *PFNGDOSETADJUSTMENT)(HGDO, LONG);
typedef ULONG (FAR *PFNGDOSETVIDEOSTANDARDADJUSTMENT)(HGDO, LONG);
typedef VOID (FAR *PFNGDOSETOVERSCANADJUSTMENT)(HGDO, LONG);
typedef VOID (FAR *PFNGDOSETMULTIMEDIAADJUSTMENT)(HGDO, LONG);
typedef VOID (FAR *PFNGDOSETPOSITIONADJUSTMENT)(HGDO, LONG, LONG);
typedef BOOL (FAR *PFNGDOSETSIZEADJUSTMENT)(HGDO, LONG, LONG);
typedef VOID (FAR *PFNGDOMODE)(HGDO, LPDEVMODE_INFO, ULONG, PFNDALTIMINGS, LPHANDLE);
typedef VOID (FAR *PFNGDOPPMODE)(HGDO, LPDEVMODE_INFO);
typedef BOOL (FAR *PFNGDOMODESUPPORTED)(HGDO, LPDEVMODE_INFO, ULONG);
typedef BOOL (FAR *PFNGDOMODESUPPORTEDEX)(HGDO, LPDEVMODE_INFO, LPDAL_CRTC_TIMING, ULONG);
typedef VOID (FAR *PFNGDOGETADJUSTMENT)(HGDO, LPHW_ADJUSTMENT, LPDEVMODE_INFO);
typedef VOID (FAR *PFNGDOSETMACROVISIONMODE)(HGDO, MACROVISION_MODE);
typedef BOOL (FAR *PFNGDOGETEDIDDATA)(HGDO, LPEDID_BUFFER); // Obsolete!
typedef BOOL (FAR *PFNSETDSPLCONNECTOR)(HGDO, USHORT);
typedef BOOL (FAR *PFNDDCPREDDCQUERY)(HGDO);
typedef BOOL (FAR *PFNDDCREADLINE)(HGDO, USHORT);
typedef VOID (FAR *PFNDDCWRITELINE)(HGDO, BOOL, USHORT);
typedef VOID (FAR *PFNDDCPOSTDDCQUERY)(HGDO, BOOL);
typedef BOOL (FAR *PFNGDOGETMONITORINFO)(HGDO, LPMONITOR_INFO);
typedef VOID (FAR *PFNGDOSETPOWERSTATE)(HGDO, ULONG);
typedef VOID (FAR *PFNGDOINITIALIZEDEVICE)(HGDO, EDID_BUFFER);
typedef BOOL (FAR *PFNGDOISDEVICEHOTPLUGGABLE)(HGDO);
typedef BOOL (FAR *PFNGDOPPADJUSTMENTCHANGE)(HGDO);
typedef BOOL (FAR *PFNGDOALIGNER)(HGDO);
typedef ULONG (FAR *PFNGDODISPLAYTESTHARNESS) (HGDO, LPVOID, LPVOID);
typedef ULONG (FAR *PFNGDOENABLESIBLING) (HDDL, HGDO, HGDO, LPHW_ASIC_ID, LPHW_DISPLAY_ENABLEDATA);
typedef ULONG (FAR *PFNGDOGETSUPPORTEDREFRESHRATE) (HGDO, LPVOID, ULONG);
typedef VOID (FAR *PFNGDOSETREFRESHRATE) (HGDO, ULONG);
typedef VOID (FAR *PFNGDODISPLAYGETDEVICEINFO)(HGDO, LPDAL_DISPLAYDEVICEINFO);
typedef BOOL (FAR *PFNGDOVALIDATEMVSUPPORT)(HGDO);
typedef ULONG (FAR *PFNGDOGETSETI2CDATA)(HGDO, LPVOID, ULONG, ULONG);
typedef VOID (FAR *PFNGDOSETPOWERSTATEEX)(HGDO, ULONG);
typedef ULONG (FAR *PFNGDOGETFIXEDDISPLAYMODES)(HGDO, LPDEVMODE_INFO, ULONG);
typedef BOOL (FAR *PFNGETFIXEDDISPLAYMODETIMING)(HGCO, LPDEVMODE_INFO, LPDAL_CRTC_TIMING);
typedef VOID (FAR *PFNGDOMODEEXTENDED)(HGDO, LPDEVMODE_INFO, ULONG,
                                       PFNDALTIMINGS, LPHANDLE, ULONG);

typedef struct _HW_ADJUSTMENT
{
  union
  {
    LONG lDefault;
    LONG lValue;
  };
  LONG   lMin;
  LONG   lMax;
  LONG   lStep;
} HW_ADJUSTMENT, FAR *LPHW_ADJUSTMENT;

// This definition belongs to ulFeatureFlags inside HW_ASIC_ID struct
#define HW_ASIC_FEATURE_MULTIFUNCTION                          0x00000001L


// The following flags communicate properties of the runtime
//  environment from 2D to DAL in ulRuntimeFlags
#define HW_ASIC_RUNTIME_IKOS                                   0x00000001L

typedef struct _HW_ASIC_ID
{
  ULONG    ulChipFamily;
  ULONG    ulChipID;
  ULONG    ulHwInternalRev;
  ULONG    ulVRamInstalled;
  ULONG    ulVRamType;
  ULONG    ulVRamBitWidth;
  ULONG    ulReferenceFrequency;
  ULONG    ulDisplayDevnode;
  LPVOID   lpIO;
  LPVOID   lpMMR;
  LPVOID   lpRomBaseAddress;
  LPVOID   lpRomHeader;
  LPVOID   lpFrameBuffer;
  LPUCHAR  lpucVgaBuffer;
  USHORT   usRealSegment;
  UCHAR    ucAGPSpeed;
  UCHAR    ucPadding;
  ULONG    ulFeatureFlags;
  ULONG    ulRuntimeFlags;
  ULONG    ulReserved2;
} HW_ASIC_ID, FAR *LPHW_ASIC_ID;

#define GCO_QUERY_STRUCTURE_FLAGS_TILEENABLED                  0x00000001L

typedef struct _GCO_QUERY_STRUCTURE
{
  ULONG ulDisplayOffset;
  ULONG ulHorizontalRefreshRate;
  ULONG ulRedMask;
  ULONG ulGreenMask;
  ULONG ulBlueMask;
  ULONG ulFlags;

  ULONG ulTileWidthBytes;
  ULONG ulTileHeightLines;
  ULONG ulTileLineStart;

} GCO_QUERY_STRUCTURE, FAR *LPGCO_QUERY_STRUCTURE;

typedef struct _GCO_SYSTEMBIOSINFO
{
  ULONG ulDisplayTypesRequestEnable;
  ULONG ulReserved[6];
} GCO_SYSTEMBIOSINFO, FAR *LPGCO_SYSTEMBIOSINFO;

typedef struct _GCO_CONTROLLER_TIMINGS
{
  ULONG ulHorizontalTotal;
  ULONG ulVerticalTotal;
  ULONG ulHorizontalDisplay;
  ULONG ulVerticalDisplay;
  ULONG ulPixelClock;         // In 10Khz
} GCO_CONTROLLER_TIMINGS, FAR *LPGCO_CONTROLLER_TIMINGS;

typedef struct _GCO_HW_REGISTER
{
	ULONG ulRegOffset;           
 	ULONG ulRegOffsetIndexMask;
	ULONG ulIndexValue;           //Index's Index
 	ULONG ulIndexValueShiftLeft;  //Index could be in the middle.
	ULONG ulIndexDataOffset; 
 	ULONG ulReserved1;
 	ULONG ulReserved2;
        ULONG ulReserved3;
}GCO_HW_REGISTER, FAR *LPGCO_HW_REGISTER;	

typedef struct _FIXEDPOINT   // define 32.8 fixed-point format
{
  ULONG       Integral;      // 32-bit integral part
  ULONG       Fractional;    // 8-bit fractional part
} FIXEDPOINT, FAR *LPFIXEDPOINT;

typedef struct _HORIZONTAL_TIME
{
  FIXEDPOINT fHActiveTime;
  FIXEDPOINT fHBlankTime;

} HORIZONTAL_TIME, FAR *LPHORIZONTAL_TIME;

typedef struct _ALLOCATED_BW
{
  FIXEDPOINT    Controller;
  FIXEDPOINT    Overlay;
  FIXEDPOINT    DVDSubpivture;
  FIXEDPOINT    HalfFrameBuffer;
} ALLOCATED_BW, FAR *LPALLOCATED_BW;

typedef struct _GDO_DISPLAYREFRESHRATECAPS
{
    ULONG ulSize;
    ULONG ulDefaultRefreshRate;
    ULONG ulNumLowRefreshRates;
    ULONG ulLowRefreshRate[MAX_LCD_REFRESH_COUNT];
    ULONG ulReserved1;
    ULONG ulReserved2;
    ULONG ulReserved3;
    ULONG ulReserved4;
    ULONG ulReserved5;
}GDO_DISPLAYREFRESHRATECAPS, FAR *LPGDO_DISPLAYREFRESHRATECAPS;

typedef struct _PRIO_ELEM
{
  BOOL              bEnabled;
  ULONG             ulMappedController;
  HORIZONTAL_TIME   sHTime;
} PRIO_ELEM, FAR* LPPRIO_ELEM;

typedef struct _GCO_MISC_INFO_VGA_ACTIVE_DISPLAY
{
	ULONG ulSize;           
 	ULONG ulVGAActiveDisplay;
} GCO_MISC_INFO_VGA_ACTIVE_DISPLAY, FAR *LPGCO_MISC_INFO_VGA_ACTIVE_DISPLAY;

typedef struct _HW_CONTROLLER_ENABLEDATA
{
  ULONG                    ulSize;  // required as first entry in structure [GG]
  ULONG                    ulControllerVersion;
  ULONG                    ulNumberOfControllers;
  BOOL                     bEnabledAtBoot[MAX_NUMBER_CONTROLLERS];
  ULONG                    aControllerCaps[MAX_NUMBER_CONTROLLERS];
  ULONG                    ulFunctionHooks;
  ULONG                    ulFunctionHooks2;
  ULONG                    ulFunctionHooks3;
  LPUCHAR                  lpAdapterName;
  FIXEDPOINT               sAvailBandwidth;
  FIXEDPOINT               sAvailPeakBandwidth;
  FIXEDPOINT               sTotalBandwidthNormal;
  FIXEDPOINT               sTotalBandwidthDelta;
  PFNGCOGETTOTALHTIME      pfnGetTotalHTime;
  PFNGCOGETTOTALBW         pfnGetTotalBandwidth;
  PFNGCOCALCMODEBW         pfnCalculateModeBandwidth;
  PFNGCOCALCMODEBW         pfnCalculatePeakModeBandwidth;
  PFNGCOCALCOVBW           pfnCalculateOverlayBandwidth;
  PFNGCOCALCVIDEOBW        pfnCalculateVideoBandwidth;
  PFNGCOCALCVIDEOBW        pfnCalculatePeakVideoBandwidth;
  PFNGCOCALCHFBBW          pfnCalculateHFBBandwidth;
  PFNGCOCALCMODEHTIME      pfnCalculateModeHorizontalTime;
  PFNGCOCALCOVHTIME        pfnCalculateOverlayHorizontalTime;
  PFNGCOCALCVIDEOHTIME     pfnCalculateVideoHorizontalTime;
  PFNGCOCALCHFBHTIME       pfnCalculateHFBHorizontalTime;
  PFNGCOCALCHTIMEADJUST    pfnCalculateHTimeAdjustment;
  PFNGCODISABLE            pfnDisable;
  PFNGCOENABLE             pfnEnable;
  PFNGCOENUMERATEMODE      pfnEnumerateStandardModes;
  PFNGCOGETCRTCLINE        pfnGetCrtcLine;
  PFNGCOGETGAMMA           pfnGetGammaCorrection;
  PFNGCOGETGAMMA16         pfnGetGamma16Correction;
  PFNGCOGETBLINKOVERLAY    pfnGetTextCursorBlinkingAdjustment;
  PFNGCOGETBLINKOVERLAY    pfnGetOverlayGammaAdjustment;
  PFNGCOGETMULTIMEDIATABLE pfnGetMultimediaTable;
  PFNGCOGETHARDWAREINFOTABLE  pfnGetHardwareInfoTable;
  PFNGCOGETINFO            pfnGetInfo;
  PFNGCOGETPOWERSTATECAPS  pfnGetPowerStateCaps;
  PFNGCONONSTANDARDMODE    pfnIsNonStandardModeSupported;
  PFNGCOTIMINGS            pfnSetAdjustmentTimings; //added to support programming of CRTC adjustment related routines by GCO
  PFNGCOMODECHANGE         pfnPreModeChange;
  PFNGCOMODECHANGE         pfnPostModeChange;
  PFNGCOSETDFPSIZE         pfnSetDFPSize;
  PFNGCOGETGAMMA           pfnSetGammaCorrection;
  PFNGCOGETGAMMA16         pfnSetGamma16Correction;
  PFNGCOSETMODE            pfnSetMode;
  PFNGCOSETPALETTE         pfnSetPalette;
  PFNGCOGETPALETTE         pfnGetPalette;
  PFNGCOSETBLINKOVERLAY    pfnSetTextCursorBlinkingAdjustment;
  PFNGCOSETBLINKOVERLAY    pfnSetOverlayGammaAdjustment;
  PFNGCOSETDISPLAYOFFSET   pfnSetDisplayOffset;
  // EPR# 36064 remove obsolete function  PFNGCOSETPOWERSTATE      pfnSetPowerState;
  PFNGCOENABLEOVERLAY      pfnEnableOverlay;
  PFNGCOGETCRTCTIMINGS     pfnGetCrtcTimings;
  PFNGCOGETEXPANSION       pfnGetExpansionSetting;
  PFNGCOUPDATEBIOSDISPLAYINFO    pfnUpdateBIOSDisplayInfo;
  PFNGCOSETMODEEXTENDED          pfnSetModeExtended;
  PFNGCOISDEVICEMAPPINGSUPPORTED pfnIsDeviceMappingSupported;
  PFNGCOGETBLINKOVERLAY    pfnGetOverlayColorGammaAdjustment;
  PFNGCOSETBLINKOVERLAY    pfnSetOverlayColorGammaAdjustment;
  PFNGCOGETBLINKOVERLAY    pfnGetOverlayContrastAdjustment;
  PFNGCOSETBLINKOVERLAY    pfnSetOverlayContrastAdjustment;
  PFNGCOGETBLINKOVERLAY    pfnGetOverlaySaturationAdjustment;
  PFNGCOSETBLINKOVERLAY    pfnSetOverlaySaturationAdjustment;
  PFNGCOGETBLINKOVERLAY    pfnGetOverlayHueAdjustment;
  PFNGCOSETBLINKOVERLAY    pfnSetOverlayHueAdjustment;
  PFNGCOGETBLINKOVERLAY    pfnGetOverlayChromacityAdjustment;
  PFNGCOSETBLINKOVERLAY    pfnSetOverlayChromacityAdjustment;
  PFNGCOGETBLINKOVERLAY    pfnGetOverlayBlackWhiteLevelAdjustment;
  PFNGCOSETBLINKOVERLAY    pfnSetOverlayBlackWhiteLevelAdjustment;
  PFNGCOGETCRC             pfnGetCRC;
  PFNGCOGETHARDWAREDATA    pfnGetHardwareData;
  PFNGETMODETIMING         pfnGetModeTiming;
  PFNGCOVALIDATEMODE       pfnValidateMode;
  PFNGCOALLOCOVERLAY       pfnAllocOverlay;
  PFNGCOALLOCOVERLAYEX       pfnAllocOverlayEx;
  PFNGCOFREEOVERLAY        pfnFreeOverlay;
  PFNGCOCONTROLLERTESTHARNESS  pfnControllerTestHarness;
  PFNGCOGETSYSTEMBIOSINFO      pfnGetSystemBIOSInfo;
  PFNGCOGETBLINKOVERLAY    pfnGetOverlayAlphaAdjustment;
  PFNGCOSETBLINKOVERLAY    pfnSetOverlayAlphaAdjustment;
  PFNGCOGETPOWERSTATE      pfnGetPowerState;
  PFNGCOSETPOWERSTATE      pfnSetPowerState;
  PFNGCOVALIDATEPOWERSTATE pfnValidatePowerState;
  PFNGCOSETPOWERSTATEEX    pfnGCOSetPowerState;
  PFNGCOGETCLOCKINFO       pfnGetClockInfo;
  PFNGCOVALIDATECLOCKCONFIG   pfnValidateClockConfig;
  PFNGCOCALCMODEBWEX       pfnCalculateModeBandwidthEx;
  PFNGCOCALCMODEBWEX       pfnCalculatePeakModeBandwidthEx;
  PFNGETDETAILEDMODETIMING pfnGCOGetDetailedTiming;
  PFNGCOSETEVENT           pfnGCOSetEvent;
  PFNGCOPROCESSMISCINFO    pfnGCOProcessMiscInfo;
  PFNGCOGETDISPLAYXYPOS    pfnGCOGetDisplayXYPos;
  PFNGCOSETDISPLAYXYPOS    pfnGCOSetDisplayXYPos;
  PFNGCOSETCRTCTILELINE    pfnGCOSetCRTCTileLine;
  PFNGCOGETBLINKOVERLAY    pfnGetReducedBlankingAdjustment;
  PFNGCOSETBLINKOVERLAY    pfnSetReducedBlankingAdjustment;
  PFNGCOGETBLINKOVERLAY    pfnGetTMDSiCoherentModeAdjustment;
  PFNGCOSETBLINKOVERLAY    pfnSetTMDSiCoherentModeAdjustment;
  PFNGCOSETMODEEXTENDED2   pfnSetModeExtended2;
  PFNGCOSERVICE            pfnGcoService;
  PFNGCOSETSCALER          pfnSetScaler;
  PFNGCOVALIDATEALLBW      pfnValidateAllBw;
  PFNGCOGETASPECRATIO      pfnAdjViewForAspecRatio;
  PFNGCOGETDISPPREFEROPTIONS pfnGetDispPreferOptions;
} HW_CONTROLLER_ENABLEDATA, FAR *LPHW_CONTROLLER_ENABLEDATA;


typedef struct _HW_DISPLAY_ENABLEDATA
{
  //Following filled up by DAL
  ULONG                         ulSize;  // required as first entry in structure [GG]
  LPHANDLE                      lpParameter;
  PFNGCOSERVICE                 pfnGcoService;  //Init in DAL, used by GDO call back.
  
  //Following filled up in Gdo.
  ULONG                         ulDisplayVersion;
  ULONG                         ulDisplayType;
  BOOL                          bEnabledAtBoot;
  ULONG                         ulDisplayCaps;
  ULONG                         ulSharedResDisplayType;     //Indicate the other party of DisplayType
  ULONG                         ulExtendedCaps;
  ULONG                         ulExtendedType;
  ULONG                         ulFunctionHooks;
  ULONG                         ulFunctionHooks2;
  ULONG                         ulHPDInterruptBitmap;
  LPUCHAR                       lpDisplayName;
  ULONG                         ulDefaultRefreshRate;
  USHORT                        usI2CWriteStartAddr;
  USHORT                        usI2CWriteLastAddr;
  PFNGDOBLANKING                pfnBlanking;
  PFNGDODISABLE                 pfnDisable;
  PFNGDOENABLE                  pfnEnable;
  PFNGDOGETADJUSTMENT           pfnGetBrightnessAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetChromaFlickerAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetColorControlAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetContrastAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetDisplayPositionAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetDisplaySizeAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetDotCrawlAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetFilterSVideoAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetFilterCompAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetGammaAdjustment;
  PFNGDOLIDSTATE                pfnGetLidState;
  PFNGDOGETADJUSTMENT           pfnGetLumaFlickerAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetOverscanAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetMultimediaPassThruAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetSyncCompositeAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetSyncHorizontalAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetSyncVerticalAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetVideoStandardAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetVideoSignalStandardAdjustment;
  PFNGDOGETEDIDDATA             pfnGetEdidData; // Obsolete !
  PFNSETDSPLCONNECTOR           pfnSetDisplayConnector;
  PFNDDCPREDDCQUERY             pfnDDC_I2C_PreDDCQuery;
  PFNDDCREADLINE                pfnDDC_I2C_ReadLine;
  PFNDDCWRITELINE               pfnDDC_I2C_WriteLine;
  PFNDDCPOSTDDCQUERY            pfnDDC_I2C_PostDDCQuery;
  PFNGDOGETMONITORINFO          pfnGetMonitorInfo;
  PFNGDOCONNECT                 pfnIsDisplayPhysicallyConnected;
  PFNGDOMODESUPPORTED           pfnIsModeSupported;
  PFNGDOPPMODE                  pfnPreModeChange;
  PFNGDOPPMODE                  pfnPostModeChange;
  PFNGDOSETADJUSTMENT           pfnSetBrightnessAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetChromaFlickerAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetColorControlAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetContrastAdjustment;
  PFNGDODISPLAYONOFF            pfnSetDisplayOff;
  PFNGDODISPLAYONOFF            pfnSetDisplayOn;
  PFNGDOSETPOSITIONADJUSTMENT   pfnSetDisplayPositionAdjustment;
  PFNGDOSETSIZEADJUSTMENT       pfnSetDisplaySizeAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetDotCrawlAdjustment;
  PFNGDOSETDPMS                 pfnSetDPMS;
  PFNGDOSETADJUSTMENT           pfnSetFilterSVideoAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetFilterCompAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetGammaAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetLumaFlickerAdjustment;
  PFNGDOSETMACROVISIONMODE      pfnSetMacrovisionMode;
  PFNGDOMODE                    pfnSetMode;
  PFNGDOSETOVERSCANADJUSTMENT   pfnSetOverscanAdjustment;
  PFNGDOSETPOWERSTATE           pfnSetPowerState;
  PFNGDOSETMULTIMEDIAADJUSTMENT pfnSetMultimediaPassThruAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetSyncCompositeAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetSyncHorizontalAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetSyncVerticalAdjustment;
  PFNGDOSETVIDEOSTANDARDADJUSTMENT  pfnSetVideoStandardAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetVideoSignalStandardAdjustment;
  PFNGDOINITIALIZEDEVICE        pfnInitializeDevice;
  PFNGDOISDEVICEHOTPLUGGABLE    pfnIsDeviceHotPluggable;
  PFNGDOPPADJUSTMENTCHANGE      pfnPreAdjustmentChange;
  PFNGDOPPADJUSTMENTCHANGE      pfnPostAdjustmentChange;
  PFNGDOALIGNER                 pfnAligner;
  PFNGDODISPLAYTESTHARNESS      pfnDisplayTestHarness;
  PFNGDOENABLESIBLING           pfnEnableSibling;
  PFNGDOGETADJUSTMENT           pfnGetSaturationAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetSaturationAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetHueAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetHueAdjustment;
  PFNGDOGETADJUSTMENT           pfnGetTemperatureAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetTemperatureAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetCGMSAdjustment;
  PFNGDOGETSUPPORTEDREFRESHRATE     pfnGetSupportedRefreshRate;  //To get supported low refresh rate .
  PFNGDOSETREFRESHRATE          pfnSetRefreshRate;               //Set a specific refresh rate.
  PFNGDOGETADJUSTMENT           pfnGetFrameModulation;
  PFNGDOSETADJUSTMENT           pfnSetFrameModulation;           //set DFP frame modulation
  PFNGDODISPLAYGETDEVICEINFO    pfnDisplayGetDeviceInfo;
  PFNGDOVALIDATEMVSUPPORT       pfnValideMvSupport;
  PFNGDOGETSETI2CDATA           pfnGetSetI2CData;
  PFNGDOSETPOWERSTATE           pfnGDOSetPowerState;
  PFNGDOGETFIXEDDISPLAYMODES    pfnGetFixedDisplayModes;         //For NON_standard Fixed mode enumeration use
  PFNGETFIXEDDISPLAYMODETIMING  pfnGetFixedDisplayModeTiming;
  PFNGDOMODESUPPORTEDEX         pfnIsModeSupportedEx;
  PFNGDOMODEEXTENDED            pfnSetModeExtended;
  PFNGDOGETADJUSTMENT           pfnGetColorSpaceConversionAdjustment;
  PFNGDOSETADJUSTMENT           pfnSetColorSpaceConversionAdjustment;
} HW_DISPLAY_ENABLEDATA, FAR *LPHW_DISPLAY_ENABLEDATA;


typedef struct _EVENTINFO
{
  ULONG            ulSize;
  ULONG            ulController;
  ULONG            ulDriverID;
  ULONG            ulEvent;
  ULONG            ulModeMajorFlag;
  ULONG            ulModeMinorFlag;
  SIZE             sDesktop;
  DEVMODE_INFO     sModeInfo;
  ULONG            ulReserved[4];
} EVENTINFO, FAR *LPEVENTINFO;


#ifndef NT_BUILD
typedef struct _VIDEO_X86_BIOS_ARGUMENTS
{
  ULONG Eax;
  ULONG Ebx;
  ULONG Ecx;
  ULONG Edx;
  ULONG Esi;
  ULONG Edi;
  ULONG Ebp;
} VIDEO_X86_BIOS_ARGUMENTS, FAR *PVIDEO_X86_BIOS_ARGUMENTS;
#endif /* NT_BUILD */



/******************************Public*Definition*****************************\
*
* DAL MACROS
*
\****************************************************************************/


#define DALDBG_ENTRY_EXIT 2
#define DALDBG_DETAIL     1
#define DALDBG_NORMAL     0


#ifdef DBG

// PREfast version of DALASSERT calls a noreturn function to make the debug break non-continuable.
// __debugbreak() resolves to an inline INT 3 on x86 and to DebugBreak() on other HW. 
#ifdef _PREFAST_
    __declspec(noreturn) void  die(__in  char* pDbgMsg);  // noreturn function

    #define DALASSERT(x, y) if (!(x)) { DDLDebugPrint(0,y); __debugbreak(); die(y);}   
#else
    #define DALASSERT(x, y) if (!(x)) { DDLDebugPrint(0,y); __debugbreak();}
#endif

#define DALDEBUG(arg) DDLDebugPrint arg

#else /* DBG */

#define DALASSERT(x, y)
#define DALDEBUG(arg)

#endif /* DBG */


#ifdef WIN9X_BUILD

#define COMPAREMEMORY(d,s,l)
#define MOVEMEMORY(d,s,l) _fmemmove((LPVOID)d, (LPVOID)s, (size_t)l)
#define WRITEREGUCHAR(d,s,l) _fmemmove((LPVOID)d, (LPVOID)s, (size_t)l)
#define READREGUCHAR(d,s,l)  _fmemmove((LPVOID)d, (LPVOID)s, (size_t)l)
#define ZEROMEMORY(p,l) _fmemset((LPVOID)p, (char)0, (size_t)l)

#define IOREADULONG(p,r)
#define IOWRITEULONG(p,r,v)
#define IOWRITEUCHAR(p,r,v)

#define MMREADULONG(lp,r) asmMM_ReadULONG(lp, r)
#define MMWRITEULONG(lp,r,v) asmMM_WriteULONG(lp, r, v)

#define MMWRITEUCHAR(p,r,v,n) (*(((LPUCHAR)((LPULONG)p+r)) + n) = v)
#define MMREADUCHAR(p,r,n) (*(((LPUCHAR)((LPULONG)p+r)) + n))

//for reading memory map bios area
#define MMBAREADULONG(lp,r)  *((ULONG FAR*)((UCHAR FAR*) lp + r ))
#define MMBAREADUSHORT(lp,r) *((USHORT FAR*)((UCHAR FAR*) lp + r ))
#define MMBAREADUCHAR(lp,r) *((UCHAR FAR*)((UCHAR FAR*) lp + r ))
#define MMBAREADBUFFER(lp,r,d,l) _fmemmove((LPVOID)d, (LPVOID)((UCHAR FAR*)lp + r), (size_t)l)

#define SYNCEXECUTION(p,r,d,v) d(v)
#define CODESEGMENT _based(_segname("_CODE"))

    // This is a temporary workaround because BOOLEAN is not defined in Win9x.
    // In NT DDK this is defined with BOOLEAN (== unsigned char). The BOOL 
    // type (== long) is known to both Win9x and NT projects. Mismatching 
    // type in NT won't matter because either 0 or 1 is returned and BOOL
    // is wider than BOOLEAN.
    //
  typedef
  BOOL  // BOOL instead of BOOLEAN!
  (*PMINIPORT_SYNCHRONIZE_ROUTINE)(
      void *Context
      );

#ifdef NDEBUG
#define STALLEXECUTION(l) DALSTALLEXECUTION(l)
#else  /* NDEBUG */
#define STALLEXECUTION(l)
#endif /* NDEBUG */

VOID asmMM_WriteULONG(LPVOID lp, ULONG r, ULONG v);
ULONG asmMM_ReadULONG(LPVOID lp, ULONG r);

VOID DALSTALLEXECUTION(ULONG ulCounter);
VOID asmStallExecution(USHORT usDelay);
VOID asmReadCounter();

#else /* WIN9X_BUILD */

#define COMPAREMEMORY(d,s,l) RtlCompareMemory((LPVOID)d, (LPVOID)s,\
                                                    (ULONG)l)
#define MOVEMEMORY(d,s,l) RtlMoveMemory((LPVOID)d, (LPVOID)s, (ULONG)l)
#define WRITEREGUCHAR(d,s,l) VideoPortWriteRegisterBufferUchar((PUCHAR)d, (PUCHAR)s, \
                                                               (ULONG)l)
#define READREGUCHAR(d,s,l) READ_REGISTER_BUFFER_UCHAR((PUCHAR)d, (PUCHAR)s, \
                                                               (ULONG)l)
#define ZEROMEMORY(p,l) RtlZeroMemory((LPVOID)p, (ULONG)l)

#define IOREADULONG(p,r) READ_PORT_ULONG((LPULONG)p + r)
#define IOWRITEULONG(p,r,v) WRITE_PORT_ULONG(((LPULONG)p + r),v)
#define IOWRITEUCHAR(p,r,v) WRITE_PORT_UCHAR(((LPUCHAR)p + r),v)

#define MMREADULONG(p,r) READ_REGISTER_ULONG((LPULONG)p + r)
#define MMWRITEULONG(p,r,v) WRITE_REGISTER_ULONG(((LPULONG)p + r),v)

#define MMWRITEUCHAR(p,r,v,n) WRITE_REGISTER_UCHAR((LPUCHAR)((LPULONG)p+r)+n,v)
#define MMREADUCHAR(p,r,n) READ_REGISTER_UCHAR((LPUCHAR)((LPULONG)p+r)+n)

#define CODESEGMENT  

//for reading memory map bios area

//#define MMBAREADULONG(p,r) READ_REGISTER_ULONG((LPULONG)((LPUCHAR)p + r))
__inline ULONG MMBAREADULONG(LPVOID p, ULONG r)
{
    ULONG ulData;

    READ_REGISTER_BUFFER_UCHAR(((LPUCHAR)p + r), (LPUCHAR) &ulData, sizeof(ULONG));
    return ulData;
}

//#define MMBAREADUSHORT(p,r) READ_REGISTER_USHORT((LPUSHORT)((LPUCHAR)p + r))
__inline USHORT MMBAREADUSHORT(LPVOID p, ULONG r)
{
    USHORT ulData;

    READ_REGISTER_BUFFER_UCHAR(((LPUCHAR)p + r), (LPUCHAR) &ulData, sizeof(USHORT));
    return ulData;
}

#define MMBAREADUCHAR(p,r) READ_REGISTER_UCHAR((LPUCHAR)((LPUCHAR)p + r))
#define MMBAREADBUFFER(p,r,d,l) READ_REGISTER_BUFFER_UCHAR((LPUCHAR)p + r, (LPUCHAR)d, (ULONG)l)

//
// TODO: YB: Temporary definition here to get DlSynchronizeExecution to work
//

PVOID
GetDeviceHandle(
    PVOID HwDeviceExtension
    );
    
#define SYNCEXECUTION(p,r,d,v) DlSynchronizeExecution(GetDeviceHandle(p),r,d,v,0)
#define STALLEXECUTION(l) KeStallExecutionProcessor(l)

#endif /* WIN9X_BUILD */



/******************************Public*Definition*****************************\
*
* DAL FUNCTION PROTOTYPES
*
\****************************************************************************/

BOOL  DALAllocOverlay(HDAL hDAL, ULONG ulController, ULONG ulWidthBytes, ULONG ulHeight, ULONG ulOverlayType);

ULONG
DALCWDDE(
    __in    HDAL   hDAL,
    __in_bcount(ulInputSize)    LPVOID  lpInput,
    __in    ULONG  ulInputSize,
    __out_bcount(ulOutputSize)  LPVOID  lpOutput,
    __in    ULONG   ulOutputSize,
    __out   LPLONG  lpInfoSize
    );

VOID  DALDisable(VOID);
VOID  DALDisableInstance(HDAL hDAL);
VOID  DALDisableDriverInstance(HDAL hDAL, ULONG ulDriverID, BOOL bPrimaryDriver);

BOOL  DALEnable(VOID);
BOOL  DALEnableInstance(HDAL hDAL, HDDL hDDL, ULONG ulDrivers, LPDALMEM lpaAdditionalMemSeg);
ULONG DALEnableDriverInstance(HDAL hDAL, ULONG ulDriverID);
ULONG DALResumeInstance(HDAL hDAL, ULONG ulDrivers, ULONG ulPowerState);

VOID  DALFreeOverlay(HDAL hDAL, ULONG ulController);
BOOL  DALQueryOverlayStatus(HDAL hDAL, ULONG ulController);
BOOL  DALGetDefaultMode(HDAL hDAL, ULONG ulDriverID, LPDEVMODE_INFO lpMI);
ULONG DALGetDPMS(HDAL hDAL);

VOID  DALUpdateObjectMap(HDAL hDAL, ULONG ulDriverID);
ULONG DALModifyMappedDisplays(HDAL hDAL, ULONG ulDriverID, ULONG ulController);
ULONG DALGetPrimaryControllerDisplayMap(HDAL hDAL); 
VOID DALSetDisplayOnController(HDAL hDal, ULONG ulController, ULONG ulDisplays);

VOID  DALGetGammaCorrection(HDAL hDAL, ULONG ulDriverID, LPDEVCLUT lpaGamma);
VOID  DALGetGamma16Correction(HDAL hDAL, ULONG ulDriverID, LPDEVCLUT16 lpaGamma16);
ULONG DALGetGraphicsControllerInfo(HDAL hDAL, ULONG ulDriverID);
ULONG DALGetHDALSize(LPULONG lpulDALSize, LPDALMEM lpaAdditionalMemSeg);

BOOL  DALGetMode(HDAL hDAL, LPDEVMODE_INFO lpMI, LPRECT lprtView,
                 LPRECT lprtPanLock, ULONG ulController);
BOOL  DALGetModeVMI(HDAL hDAL, VIDEO_MODE_INFORMATION FAR * lpVMI,
                    ULONG ulDriverID);
BOOL  DALGetModeVMIEx(HDAL hDAL, VIDEO_MODE_INFORMATION FAR * lpVMI,
                      ULONG ulDriverID, ULONG ulModeIndex);

ULONG DALGetModesAvailable(HDAL hDAL, ULONG ulDriverID, LPDEVMODE_INFO lpaMI,
                           ULONG ulModes);
ULONG DALGetModesAvailableVMI(HDAL hDAL, ULONG ulDriverID,
                              VIDEO_MODE_INFORMATION FAR *lpaVMI, ULONG ulModes);

ULONG DALGetNumberModesAvailable(HDAL hDAL, ULONG ulDriverID);

BOOL  DALShareModeTable(HDAL hDal, LPVOID lpModeTable, ULONG ulConnectedDisplays);
BOOL  DALUnShareModeTable(HDAL hDal, LPVOID lpModeTable, ULONG ulConnectedDisplays);

VOID  DALResetMode(HDAL hDAL, ULONG ulDriverID);

BOOL
DALGetDisplayEDID(
    __in    HDAL    hDAL,
    __in    ULONG   ulDriverID,
    __in    ULONG   ulDisplayIndex,
    __out_bcount(ulLength)  LPUCHAR  lpucQueryBuffer,
    __in    ULONG   ulLength
    );

VOID  DALSetDisplayDPMS(HDAL hDAL, ULONG ulDriverID, ULONG ulState, ULONG ulDisplayIndex);
VOID  DALVGASetDisplayDPMS(HDAL hDAL, ULONG ulDriverID, ULONG ulState, ULONG ulDisplayIndex);
VOID  DALSetDPMS(HDAL hDAL, ULONG ulState);
VOID  DALSetPowerState(HDAL hDAL, ULONG ulState);

ULONG DALGetGammaMode(HDAL hDAL, ULONG ulDriverID);
VOID  DALSetGammaMode(HDAL hDAL, ULONG ulDriverID, ULONG ulGammaMode);

VOID  DALSetGammaCorrection(HDAL hDAL, ULONG ulDriverID, LPDEVCLUT lpaGamma);
VOID  DALSetGamma16Correction(HDAL hDAL, ULONG ulDriverID, LPDEVCLUT16 lpaGamma16);

ULONG DALGetMacrovisionMode(HDAL hDAL, ULONG ulDriverID);
BOOL  DALSetMacrovisionMode(HDAL hDAL, ULONG ulDriverID,
                            MACROVISION_MODE eMacrovisionMode, ULONG ulKey);

BOOL  DALActivateMacrovision(HDAL hDAL, ULONG ulDriverID, LPULONG lpKey);
BOOL  DALDeactivateMacrovision(HDAL hDAL, ULONG ulDriverID, ULONG ulKey);

ULONG DALValidateMVKey(HDAL hDAL, ULONG ulDriverID, ULONG ulKey);
LPVOID DALGetMVKeyInfo(HDAL hDAL,ULONG ulKey);


ULONG DALMV7(HDAL hDAL, ULONG ulDriverID, LPVOID lpVideoParameters);

ULONG DALSetMode(HDAL hDAL, ULONG ulDriverID, LPDEVMODE_INFO lpMI, ULONG ulDisplayOffset,
                 ULONG ulDisplayPitch, BOOL bForce);

ULONG DALSetModeVMI(HDAL hDAL, ULONG ulDriverID, VIDEO_MODE_INFORMATION FAR *lpVMI,
                    ULONG ulDisplayOffset, ULONG ulDisplayPitch, BOOL bForce);

VOID  DALSetPalette(HDAL hDAL, ULONG ulDriverID, LPDEVCLUT lpPalette,
                    ULONG ulStart, ULONG ulLength);

ULONG DALValidateMode(HDAL hDAL, ULONG ulDriverID, LPDEVMODE_INFO lpMI,
                      BOOL bForce);

BOOL DALSetAdjustmentTimings(LPHANDLE lpParameter, ULONG ulController, LPADJUSTMENT_PARAMETERS lpAdjustmentParameters);

ULONG ulDALDisplayGetEDID( HDAL hDAL, ULONG ulDisplayIndex, LPVOID lpEdidBuffer );

ULONG DALGetDisplaysPhysicallyConnected(HDAL hDAL, ULONG ulDriverID);
ULONG DALGetDisplaysActive(HDAL  hDAL, ULONG ulDriverID);

VOID DALModifyObjectMap(HDAL hDAL, 
                        ULONG ulDriverID, 
                        LPULONG lpaControllersMap, 
                        LPULONG lpaDisplays);

VOID DALEnableDDExclusiveMode(HDAL hDAL, ULONG ulDriverID) ;

VOID DALDisableDDExclusiveMode(HDAL hDAL, ULONG ulDriverID) ;

VOID DALSwitchFSDOSToWindows(HDAL hDAL, ULONG ulDriverID);

VOID DALSwitchWindowsToFSDOS(HDAL hDAL, ULONG ulDriverID);

ULONG DALGetNumberOfDrivers(HDAL hDAL);

ULONG DALGetDriverState(HDAL hDAL, ULONG ulDriverID);

ULONG DALSetTilingMode(HDAL hDAL, ULONG ulDriverID, ULONG ulTilingMode);

VOID DALSetBlanking(HDAL hDAL, ULONG ulDriverID, BOOL bBlank);

ULONG DALSetModeEx(HDAL hDAL, ULONG ulDriverID, LPDEVMODE_INFO lpMode, BOOL bForce);

VOID DALPostSetMode(HDAL hDAL, ULONG ulDriverID, LPDEVMODE_INFO lpMI);
ULONG ulDALGcoService(LPHANDLE lpParameter, ULONG ulController, LPGCO_SERVICE lpGcoService);
/******************************Public*Definition*****************************\
*
* DDL FUNCTION PROTOTYPES
*
\****************************************************************************/

// DDL  return code
#define DDL_RESULT_OK                            0x00000000L
#define DDL_RESULT_GENERIC_ERROR                 0x00000001L

#define DDL_RESULT_BIOS_EXEC_TABLE_NOTFOUND      0x00000100L
#define DDL_RESULT_BIOS_EXEC_PARAMETER_ERROR     0x00000101L
#define DDL_RESULT_BIOS_EXEC_PARSER_ERROR        0x00000102L

BOOL DDLBiosInt10(HDDL hDDL, PVIDEO_X86_BIOS_ARGUMENTS pBiosArguments);

VOID
DDLDebugPrint(
    __in  ULONG     ulDebugLevel,
    __in  LPCHAR    lpDebugMessage,
    ...
    );

PFNGCOENABLE* DDLGetControllerObjects(HDDL hddl, LPULONG lpultotalcontrollerobjects);
PFNGDOENABLE* DDLGetDisplayObjects(HDDL hddl, LPULONG lpultotaldisplayobjects);

VOID DDLGetHwAsicID(HDDL hDDL, LPHW_ASIC_ID lpHwAsicID);

VOID  DDLEventNotification(HDDL hDDL, LPEVENTINFO lpEventInfo);

BOOL DDLGetRegistryParameters(HDDL hDDL,
                              __in __nullterminated LPUCHAR pValueName,
                              __out_bcount_part(*pulValueLength, *pulValueLength) LPVOID pValueData,
                              __inout LPULONG pulValueLength);
BOOL  DDLSetRegistryParameters(HDDL hDDL, LPUCHAR  lpValueName, LPVOID lpValueData,
                               ULONG uValueLength);

BOOL FAR DDLGetMonitorInfo(HDDL hDDL, LPMONITOR_INFO lpMonitorInfo);

ULONG FAR DDLGetRegistryPathName(HDDL hDDL, LPUCHAR lpPathName);

VOID FAR DDLRegisterAND(HDDL hDDL, ULONG ulOffset, ULONG ulMask);
VOID FAR DDLRegisterOR(HDDL hDDL, ULONG ulOffset, ULONG ulMask);

BOOL FAR DDLGetDriverInfo(HDDL hDDL, LPULONG lpDrivers);

ULONG FAR DDLGetDriverOptions(HDDL hDDL);

VOID FAR
DDLGetAdapterID(
    __in     HDDL       hDDL,
    __inout_bcount(256) /*MAX_REGISTRY_PATH*/  LPCHAR lpcDriverID
    );

BOOL FAR
DDLGetDriversToLoad(
    __in     HDDL       hDDL,
    __inout  LPULONG    lpDrivers,
    __in     LPCHAR     lpDeviceName
    );

BOOL FAR DDLShareModeTable(HDDL hDDL, LPVOID lpModeTable, ULONG ulConnectedDisplays);

ULONG FAR DDLReadCMOS(HDDL hDDL, ULONG ulCMOSAddress);
VOID FAR DDLWriteCMOS(HDDL hDDL, ULONG ulCMOSAddress, ULONG ulCMOSValue);

BOOL FAR DDLMessageCode(HDDL hDDL, ULONG ulDriverId, ULONG ulMessageCode, ULONG ulBufSize, LPVOID pvBuf);

BOOL FAR DDLSynchronizeExecution(HDDL hDDL, LPVOID lpSyncRoutine, LPVOID lpContext, USHORT usPriority);

BOOL FAR DDLQueryTableRevision(HDDL hDDL, USHORT usTableIndex, LPUSHORT lpusTableRev);

ULONG FAR DDLExecBiosTable(HDDL hDDL, LPVOID lpParaSpace, USHORT usTableIndex);

#if defined(_X86_)
#pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif

#endif /*_DAL_H*/


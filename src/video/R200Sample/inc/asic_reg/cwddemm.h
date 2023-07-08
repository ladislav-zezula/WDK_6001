

/****************************************************************************\
*
*  Module Name    cwddemm.h
*  Project        CWDDE
*
*  Description    Multimedia CWDDE (CWDDEMM) structure definitions.
*
*
*  Copyright (c) 1998-1999 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
*  Version: 1.1
*
*  LOG OF CHANGES
*
*
\****************************************************************************/

#ifndef _CWDDEMM_H_
#define _CWDDEMM_H_

#pragma pack(1)


//*************************************************************************
// CWDDEMM defines
//*************************************************************************
#define CWDDEMM_VERSION_MINOR                   0x00000004
#define CWDDEMM_VERSION_MAJOR                   0x00000001
#define CWDDEMM_VERSION (((ULONG)CWDDEMM_VERSION_MAJOR<<16) | CWDDEMM_VERSION_MINOR)

#define CWDDEMM_GetVersion                   0x00140000
#define CWDDEMM_AllocAMCPort                 0x00140001
#define CWDDEMM_AllocMemBandwidth            0x00140002
#define CWDDEMM_FreeAMCPort                  0x00140003
#define CWDDEMM_FreeMemBandwidth             0x00140004
#define CWDDEMM_GetAsicId                    0x00140005
#define CWDDEMM_GetHardwareConfigTable       0x00140006
#define CWDDEMM_GetMultimediaConfigTable     0x00140007
#define CWDDEMM_AllocOverlay                 0x00140008
#define CWDDEMM_FreeOverlay                  0x00140009
#define CWDDEMM_ConfigureBandwidthTest       0x0014000A
#define CWDDEMM_GetDisplayDeviceNode         0x0014000B
#define CWDDEMM_GetJanusAPIPointer           0x0014000C
#define CWDDEMM_GetMiniVDDName               0x0014000D
#define CWDDEMM_Unuse14000E                  0x0014000E
#define CWDDEMM_Unuse14000F                  0x0014000F
#define CWDDEMM_Test_GetCRC                  0x00140010
#define CWDDEMM_Test_GetBandwidthData        0x00140011
#define CWDDEMM_Test_GetHardwareData         0x00140012
#define CWDDEMM_RegisterVPEAccess            0x00140013
#define CWDDEMM_UnregisterVPEAccess          0x00140014
#define CWDDEMM_GetVPEAccess                 0x00140015
#define CWDDEMM_VPEAccess                    0x00140016
#define CWDDEMM_ValidateOverlayTheaterMode   0x00140017
#define CWDDEMM_SetOverlayTheaterMode        0x00140018
#define CWDDEMM_ResetOverlayTheaterMode      0x00140019
#define CWDDEMM_Supported                    0x0014001A
#define CWDDEMM_AllocOverlayEx               0x0014001B

// Windows 9x/ Windows NT
#define CONTROL_CONFIG_CWDDEMM               0x07306

///////////////////////////////////////////////////////////////////////////
// CWDDEMM return codes
///////////////////////////////////////////////////////////////////////////
// Warning: These codes are depreciated and are being phased out. [AM]
//          Use CWDDE_ERR codes instead.
///////////////////////////////////////////////////////////////////////////
#define CWDDEMM_OK                                0
#define CWDDEMM_ERR_UNSUPPORTED                   1
#define CWDDEMM_ERR_OUTOFRANGE                    2
#define CWDDEMM_ERR_BADINPUTSIZE                  3
#define CWDDEMM_ERR_BADOUTPUTSIZE                 4
#define CWDDEMM_ERR_BADINPUT                      5
#define CWDDEMM_ERR_NOTAVAILABLE                  6

#define DAL_ENABLE_BANDWIDTH_CHECK                1
#define DAL_ENABLE_HTIME_CHECK                    2

//*************************************************************************
// CWDDEMM Structures
//*************************************************************************

typedef struct tagCWDDEMMCMD
{
    ULONG ulSize;     // size of CWDDEMMCMD
    ULONG ulEscape32;   // 32 bit subfunction code
    ULONG ulHandle;
    ULONG ulDriverReserved;
}CWDDEMMCMD;

typedef struct tagMM_ULONG
{
    ULONG ulSize;
    ULONG ulValue;
}MM_ULONG;

typedef struct tagMM_ALLOCAMCPORT
{
    ULONG ulSize;         // size of MM_ALLOCAMCPORT
    ULONG ulPortId;       // port identification
    ULONG ulReserved1;    //N/A
}MM_ALLOCAMCPORT;

// Port ids:
#define MM_8BIT_VIDEO_PORT1      0x00000001
#define MM_8BIT_VIDEO_PORT2      0x00000002
#define MM_16BIT_VIDEO_PORT      0x00000003

typedef struct tagMM_ALLOCBANDWIDTH
{
    ULONG ulSize;         // size of MM_ALLOCAMCPORT
    ULONG ulFrameRate;    // microseconds per field
    ULONG ulVideoWidth;   // video width in bytes
    ULONG ulVideoHeight;   // video height
    ULONG ulVBIWidth;     // vertical blank interval width in bytes
    ULONG ulVBIHeight;     // vertical blank interval height
    ULONG ulCaptureEngine;// capture engine code
    ULONG ulReserved1;    //N/A
}MM_ALLOCBANDWIDTH;

// Capture engine codes:
#define MM_CAPTURE_ENGINE0      0x00000001
#define MM_CAPTURE_ENGINE1      0x00000002

typedef struct tagMM_ALLOCOVERLAY
{
    ULONG ulSize;         // size of MM_ALLOCOVERLAY
    ULONG ulController;   // CRT Controller index base 0
    ULONG ulWidth;        // overlay width in bytes
    ULONG ulHeight;       // overlay height
    ULONG ulOverlayFormat;// overlay format
    ULONG ulReserved1;    //N/A
}MM_ALLOCOVERLAY;

typedef struct tagMM_ALLOCOVERLAYEX
{
    ULONG ulSize;               // size of MM_ALLOCOVERLAY
    ULONG ulController;         // CRT Controller index base 0
    ULONG ulWidth;              // overlay width in bytes
    ULONG ulHeight;             // overlay height
    ULONG ulOverlayFormat;      // overlay format
    ULONG ulBackendOverlayBpp;    
    ULONG ulReserved1;          //N/A
    ULONG ulReserved2;          //N/A
    ULONG ulReserved3;          //N/A
    ULONG ulReserved4;          //N/A
}MM_ALLOCOVERLAYEX;

// Overlay formats:
#define OVERLAY_FORMAT_YUY2     0x00000001 // 4-2-2 (16 bits) format, packed
#define OVERLAY_FORMAT_UYVY     0x00000002 // 4-2-2 (16 bits) format, packed
#define OVERLAY_FORMAT_YV12     0x00000003 // 4-2-0 (12 bits) format, planar
#define OVERLAY_FORMAT_YVU9     0x00000004 // 9 bits, planar
#define OVERLAY_FORMAT_IF09     0x00000005 // 9 bits, planar
#define OVERLAY_FORMAT_RGB565   0x00000006 // 16 bits, packed
#define OVERLAY_FORMAT_RGB555   0x00000007 // 16 bits, packed
#define OVERLAY_FORMAT_RGB32    0x00000008 // 32 bits, packed

typedef struct tagMM_CONFIGTEST
{
    ULONG    ulSize;         // size of MM_CONFIGTEST
    ULONG    ulEnableBandwidthCheck;   //TRUE to enable memory bandwidth
                                       // checking, FALSE to disable checking
    ULONG    ulReserved1;    //N/A
}MM_CONFIGTEST;

typedef struct tagMM_ASICID
{
    ULONG    ulSize;         // size of MM_ASICID
    ULONG    ulAsicId;
    ULONG    ulReserved1;    //N/A
}MM_ASICID;


typedef struct tagMM_HDWCONFIG
{
    ULONG    ulSize;               // size of MM_HDWCONFIG structure in bytes
                                   // including a buffer for BIOS hardware configuration table
    ULONG    ulBytesReturned;      // size of aData array (returned)
//  UCHAR    aData[VARIABLE_LENGTH] - video BIOS hardware configuration table
}MM_HDWCONFIG;


typedef struct tagMM_MULTIMEDIATABLE
{
    ULONG    ulSize;                // size of MM_MULTIMEDIATABLE structure in bytes
                                    // including a buffer for BIOS multimedia table
    ULONG    ulBytesReturned;       // size of aData array (returned)
//  UCHAR    aData[VARIABLE_LENGTH] - video BIOS multimedia configuration table
}MM_MULTIMEDIATABLE;

typedef struct tagMM_MINIVDDNAME
{
    ULONG    ulSize;               // size of MM_MINIVDDNAME structure in bytes
    CHAR     szVDDName[17];        // Mini VDD Name (null terminated string)
}MM_MINIVDDNAME;

//CRC related
#define TESTCRC_ENABLE_CRC        0x00000001 //EnableCRC only.
#define TESTCRC_READ_CRC          0x00000002 //Bypass EnableCRC, GetCRC,Restore Back  DAC_CNTL Register value
#define TESTCRC_GETCRC_ERR        0x00000004 

typedef struct tagMM_TESTCRCINPUT
{
    ULONG    ulSize;         
    ULONG    ulGetCRCFlag;
    ULONG    ulReserved2;
    ULONG    ulReserved3;
}MM_TESTCRCINPUT;

#ifndef _DAL_H
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
#endif

#ifndef _DALBASE_H
typedef struct _DEVMODE_INFO
{
  ULONG ulModeFlags;
  ULONG ulPelsWidth;
  ULONG ulPelsHeight;
  ULONG ulBitsPerPixel;
  ULONG ulDisplayFrequency;
} DEVMODE_INFO, FAR *LPDEVMODE_INFO;
#endif

typedef struct tagMM_BANDWIDTHDATA
{
    ULONG    ulSize;         	
    FIXEDPOINT aAvailableBandwidth; 
    FIXEDPOINT sRequestedModeBandwidth;
    FIXEDPOINT sRequestedOverlayBandwidth;
    FIXEDPOINT sRequestedVideoBandwidth;
    FIXEDPOINT sRequestedHFBBandwidth;
    HORIZONTAL_TIME sAvailableHTime; 
    HORIZONTAL_TIME sRequestedModeHTime;
    HORIZONTAL_TIME sRequestedOverlayHTime;
    HORIZONTAL_TIME sRequestedVideoHTime;
    HORIZONTAL_TIME sRequestedHFBHTime;
    DEVMODE_INFO dmInfo;
    ULONG ulDisplayType;
    ULONG ulReserved1;    //N/A

}MM_BANDWIDTHDATA;

typedef struct MM_BANDWIDTHDATAOUT
{
   ULONG ulSize;
   MM_BANDWIDTHDATA Mm_BandwidthData;
   ULONG Reserved1;
   ULONG Reserved2;
}MM_BANDWIDTHDATAOUT;

typedef struct tagMM_HARDWAREDATAINPUT
{
   ULONG ulOptionFlag;
   ULONG ulRegOffset;           
   ULONG ulRegOffsetIndexMask;
   ULONG ulIndexValue;           //Index's Index
   ULONG ulIndexValueShiftLeft;  //Index could be in the middle.
   ULONG ulIndexDataOffset; 
   ULONG ulReserved1;
   ULONG ulReserved2;
   ULONG ulReserved3;
}MM_HARDWAREDATAINPUT;

typedef struct tagMM_VPE_ACCESS_DATA
{
    ULONG    ulSize;                // size of MM_ VPE_ACCESS_DATA structure in bytes
    ULONG    ulCallbackRtn;         // 32-bit offset of the VPE access routine
    ULONG    ulRefData;             // reference data
}MM_VPE_ACCESS_DATA;

typedef struct tagMM_VARIABLE_LENGTH_BLOCK
{
    ULONG    ulSize;                 // size of MM_VARIABLE_LENGTH_BLOCK structure in bytes
//  UCHAR    aData[VARIABLE_LENGTH]; // variable length data
}MM_VARIABLE_LENGTH_BLOCK;


#define CWDDEMM_OVERLAYCLONEMODE_FLAG_CURRENTVIEW  0x00000001 // current view option flag
#define CWDDEMM_OVERLAYCLONEMODE_FLAG_TVMMMODE     0x00000002 // TV multimedia mode request
#define CWDDEMM_OVERLAYCLONEMODE_FLAG_NTSC         0x00000004 // TV standard change request
#define CWDDEMM_OVERLAYCLONEMODE_FLAG_PAL          0x00000008 // TV standard change request

typedef struct tagMM_OVERLAYCLONEMODE
{
    ULONG ulSize;                // size of MM_OVERLAYCLONEMODE structure in bytes
    ULONG ulFlags;               // Set the option flag
    ULONG ulViewResolutionCx;    // Horizontal view resolution in pixels (width)
    ULONG ulViewResolutionCy;    // Vertical view resolution in pixels (height)
    ULONG ulColorDepth;          // requested color depth
    ULONG ulVerticalRefreshRate; // requested refresh rate
    ULONG ulReserved[4];
} MM_OVERLAYCLONEMODE;

typedef struct tagMM_SUPPORTED
{
  ULONG ulSize;
  ULONG ulEscape;
  ULONG ulSubFunction;
  ULONG ulReserved;
}MM_SUPPORTED;

#pragma pack()

#endif //_CWDDEMM_H_


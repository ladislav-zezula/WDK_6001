

//
//  $Workfile: cwdde.h $
//  $Revision: 3 $
//
//  Description:
//
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//


#ifndef CWDDE__H__
#define CWDDE__H__


// ANYVIEW

#define ANYVIEW_RES_SETMODE             0x7200
#define ANYVIEW_RES_SETVARS             0x7201
#define ANYVIEW_PIX_SETMODE             0x7202
#define ANYVIEW_BLANK                   0x7203
#define ANYVIEW_VIRTDESK                0x7204
#define ANYVIEW_ZOOM                    0x7205
#define ANYVIEW_GET_INFOSTRUCT          0x7206
#define ANYVIEW_CALIBRATE               0x7207
#define ANYVIEW_COLORCORRECT            0x7208
#define ANYVIEW_ESCAPE_FUNCTION         0x7209
#define ANYVIEW_DRV                     0x720A

// Configuration

#define Control_ConfigIsSupported       0x7300
#define Control_ConfigIsEnabled         0x7301
#define Control_GetConfiguration        0x7302

#ifndef Control_Config_CWDDE32 // also defined in cwddeci.h
#define Control_Config_CWDDE32          0x7306
#endif

// ROM query

#define Control_ROMQueryIsSupported     0x7310
#define Control_ROMQueryIsEnabled       0x7311
#define Control_GetROMQuery             0x7312

// Engine semaphone

#define Control_EngSemIsSupported       0x7320
#define Control_EngSemIsEnabled         0x7321
#define Control_GetSemaphorePtr         0x7322
#define Control_EngineShareBegin        0x7323
#define Control_EngineShareEnd          0x7324
#define Control_EngineVRAMAccessGetPtr  0x7325

// Virtual aperture

#define Control_VirtApertIsSupported    0x7330
#define Control_VirtApertIsEnabled      0x7331
#define Control_FlushVirtualAperture    0x7332
#define Control_GetBufferFlagPtr        0x7333

// Timewarp

#define Control_TimewarpIsSupported     0x7340
#define Control_TimewarpIsEnabled       0x7341
#define Control_TimewarpEnable          0x7342
#define Control_TimewarpDisable         0x7343

// Deskscan

#define Control_DeskScanIsSupported     0x7350
#define Control_DeskScanIsEnabled       0x7351
#define Control_DeskScan_PANLEFT        0x7352
#define Control_DeskScan_PANRIGHT       0x7353
#define Control_DeskScan_PANUP          0x7354
#define Control_DeskScan_PANDOWN        0x7355
#define Control_DeskScan_ZOOMIN         0x7356
#define Control_DeskScan_ZOOMOUT        0x7357
#define Control_DeskScan_PANLOCK        0x7358
#define Control_DeskScan_PANUNLOCK      0x7359
#define Control_DeskScan_GETSCREENPOS   0x735A
#define Control_DeskScan_SETSCREENPOS   0x735B
#define Control_DeskScan_PanCallback    0x735D

// DPMS

#define Control_DPMSIsSupported         0x7360
#define Control_DPMSIsEnabled           0x7361
#define Control_DPMS_ON                 0x7362
#define Control_DPMS_STANDBY            0x7363
#define Control_DPMS_SUSPEND            0x7364
#define Control_DPMS_OFF                0x7365

// Crystal fonts

#define Control_CrystalIsSupported      0x7370
#define Control_CrystalIsEnabled        0x7371
#define Control_SetCrystalGamma         0x7372
#define Control_GetCrystalGamma         0x7373

// Callback

#define Control_CallbackIsSupported     0x7380
#define Control_CallbackIsEnabled       0x7381
#define Control_CallCallback            0x7382

// Gamma correction

#define Control_GammaIsSupported        0x7390
#define Control_GammaIsEnabled          0x7391
#define Control_SetGamma                0x7392
#define Control_GetGamma                0x7393

// Display mode

#define Control_DisplaymodeIsSupported  0x73A0
#define Control_DisplaymodeIsEnabled    0x73A1
#define Control_DisplayModeCaps         0x73A2
#define Control_GetDisplaymode          0x73A3
#define Control_DisplaymodeEnum         0x73A4
#define Control_CheckDisplaymode        0x73A5
#define Control_SetDisplaymode          0x73A6
#define Control_SetCursorDoubleMode     0x73A7
#define Control_GetCursorDoubleMode     0x73A8


// LCD Feature Group

#define CWDDE32_LCD_IsSupported         0x000b0000
#define CWDDE32_LCD_IsEnabled           0x000b0001
#define CWDDE32_LCD_GetCaps             0x000b0002
#define CWDDE32_LCD_GetConfig           0x000b0003
#define CWDDE32_LCD_SetConfig           0x000b0004


// Test

#define Control_TestIsSupported         0x73B0
#define Control_TestIsEnabled           0x73B1
#define Control_TestTextEnable          0x73B2
#define Control_TestTextDisable         0x73B3

//Overlay

#define Control_DCIOverlayOnOff          0x73ED
#define DCIOverlayOn                             0x00000000
#define DCIOverlayOff                        0x00000001
#define DCIOverlayCheck                      0x00000002

//----------------------------------------------------------------------------
// D C I  Control Block FuncCode definitions
//----------------------------------------------------------------------------

#define Control_DCIEnable                            0x73E2
#define Control_DCIDisable                           0x73E3
#define Control_DCIAccessDevice                      0x73EC
//
#define ACCESSDEVICEDATA_SUBFUNC_ALLOC               0x00000001
#define ACCESSDEVICEDATA_SUBFUNC_FREE                0x00000002
#define ACCESSDEVICEDATA_SUBFUNC_QUERY               0x00000003
//
#define ACCESSDEVICECODE_CONNECTOR                   0x00000001
#define ACCESSDEVICECODE_OVERLAY                     0x00000002

//
#define DCICBFUNCCODE_MODESWITCHBEGIN                0x00000001
#define DCICBFUNCCODE_MODESWITCHEND                  0x00000002
#define DCICBFUNCCODE_FULLSCREENDOSENTER             0x00000003
#define DCICBFUNCCODE_FULLSCREENDOSEXIT              0x00000004
#define DCICBFUNCCODE_PANCALLBACK32                  0x00000005
#define DCICBFUNCCODE_DXDESTROYDRIVER                0x00000006
#define DCICBFUNCCODE_HEAPSIZECHANGE                 0x00000007

typedef struct struct_PTR48
{
    DWORD Offset;
    WORD  Selector;
    WORD  Reserved;
}
PTR48;


//
// ATIConfig
//

typedef struct struct_ATIConfig
{
    BYTE  ATISig[10];
    BYTE  Filler1[2];
    BYTE  DriverName[9];
    BYTE  Filler2[3];
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwDesktopWidth;
    DWORD dwDesktopHeight;
    DWORD dwEnginePitch;
    DWORD dwRealRamAvail;
    DWORD VGABoundary;
    DWORD dwBpp;
    DWORD dwBoardBpp;
    DWORD dwColorFormat;
    DWORD dwAlphaBitMask;
    DWORD dwConfigBits;
    DWORD dwAsicRevision;
    DWORD dwROMVersion;
    DWORD dwBoardType;
    DWORD dwApertureType;
    PTR48 AperturePtr;
    DWORD DisplayOffset;
    PTR48 MemRegPtr;
    DWORD dwExtDevice[8];
    PTR48 MemReg1Ptr;

}
ATIConfig;

// dwConfigBits definitions

#define ATICONFIG_CONFIGBITS_PAL_MGR_ON 0x00000001

// dwColorFormat definitions

#define ATICONFIG_COLORFMT_4            0x00000000L
#define ATICONFIG_COLORFMT_4_Packed     0x00000001L
#define ATICONFIG_COLORFMT_8            0x00000002L
#define ATICONFIG_COLORFMT_RGB332       0x00000003L
#define ATICONFIG_COLORFMT_Crystal8     0x00000004L
#define ATICONFIG_COLORFMT_RGB555       0x00000005L
#define ATICONFIG_COLORFMT_RGB565       0x00000006L
#define ATICONFIG_COLORFMT_RGB655       0x00000007L
#define ATICONFIG_COLORFMT_RGB664       0x00000008L
#define ATICONFIG_COLORFMT_RGB888       0x00000009L
#define ATICONFIG_COLORFMT_BGR888       0x0000000AL
#define ATICONFIG_COLORFMT_aRGB8888     0x0000000BL
#define ATICONFIG_COLORFMT_RGBa8888     0x0000000CL
#define ATICONFIG_COLORFMT_aBGR8888     0x0000000DL
#define ATICONFIG_COLORFMT_BGRa8888     0x0000000EL

// dwBoardType

#define ATICONFIG_BOARDTYPE_UNDEFINED   0x00000000L
#define ATICONFIG_BOARDTYPE_MACH8       0x00000001L
#define ATICONFIG_BOARDTYPE_MACH32      0x00000002L
#define ATICONFIG_BOARDTYPE_MACH64      0x00000003L

// dwApertureType

#define ATICONFIG_APERTURETYPE_NONE     0x00000000L
#define ATICONFIG_APERTURETYPE_BLITTING 0x00000001L
#define ATICONFIG_APERTURETYPE_BANKED   0x00000002L
#define ATICONFIG_APERTURETYPE_LINEAR   0x00000003L

#define  Control_GetDisplayMode  0x73a3
#define  Control_CheckDisplayMode  0x73a5
#define  Control_SetDisplayMode  0x73a6

typedef  unsigned short ushort;
typedef  unsigned char  uchar;

typedef  struct   {
      long  ScrWidth;
      long  ScrHeight;
      long  ScrColorFormat;
      long  DesktopWidth;
      long  DesktopHeight;
      long  SystemColorFormat;
         } CWDDE_ModeInfo;

typedef  struct {
ushort  RQSize;                 //  ;size of query structure in bytes
uchar       RQRevision;            //   ;revision of query structure
uchar       RQNbrModeTbls;         //   ;number of mode tables
ushort  RQModeTbls;             //  ;offset in bytes to mode tables
uchar       RQModeTblSize;         //   ;size of each mode table in bytes
uchar       RQVGAType;             //   ;0 = disabled, 1 = enabled
ushort  RQAsicRev;              //  ;ASIC revision
uchar       RQVGASize;             //   ;VGA boudary in aperture
uchar       RQMemSize;             //   ;amount of RAM on card
uchar       RQDACType;             //   ;type of DAC on card
uchar       RQMemType;             //   ;type of RAM chips
uchar       RQBusType;             //   ;type of host bus we use
uchar       RQMonitorAlias;     //  ;category of monitor assumed
ushort  RQApertureLoc;          //  ;aperture location in Mb (0-4095)
uchar       RQApertureCfg;         //   ;aperture configuration
uchar       RQColourSupport;        //  ;colour formats supported
uchar       RQRAMDACFeature;        //  ;supported RAMDAC features
uchar       RQReserved15;           //
ushort  RQCurModeTbl;           //  ;not implemented
uchar       RQReserved18_1F[8];
   }  ROMQueryHeader, FAR *LPROMQ;

typedef  struct {
    ushort   mt_width;            // ;display resolution width  - in pixels    0
    ushort   mt_height;           // ;display resolution height - in pixels    02
    uchar    mt_MaxPixelDepth; // ;maximum pixel depth                      04
    uchar    mt_ModeNumber;    //   ;send this to BIOS to set this mode       05
   ushort   mt_eeprom_off;    //                                           06
   ushort   dummy1;           // 08
   ushort   dummy2;           // 0a
   ushort   dummy3;           // 0c
   uchar    mt_crtc_h_total; //                                            0e
   uchar    mt_crtc_h_disp;  //                                            0f
   uchar    mt_crtc_h_sync_strt;    //                                     10
   uchar    mt_crtc_h_sync_wid;     //                                     11
   ushort   mt_crtc_v_total;        //                                     12
   ushort   mt_crtc_v_disp;         //                                     14
   ushort   mt_crtc_v_sync_strt;    //                                     16
   uchar    mt_crtc_v_sync_wid;     //                                     18
   uchar    mt_clock_cntl;          //                                     19
   ushort   mt_dotclock;            //                                     1a
   ushort   mt_misc_stuff;          // ctrc_h_total_dly etc
   ushort   mt_ovr_wid;             //                                     1e
   ushort   mt_ovr_clr_b_8;         //                                     20
   ushort   mt_ovr_clr_g_r;         //                                     22
}  ModeTable, FAR *LPModeTable;

typedef struct tagOVERLAYONOFFDATA
{
    DWORD   dwSize;                     //size of OVERLAYONOFFDATA structure in bytes
    DWORD       dwSubFunc;                  //code indicating what to do (On,Off or Check)
    DWORD       dwOverlayWidth;         //width of Overlay
    DWORD       dwOverlayHeight;            //height of Overlay
    DWORD      dwfccFormat;                 //format of overlay (YUY2,UYVY etc.)
    DWORD       dwbitMasks[3];              //for non-standard RGB Modes like 565
}   OVERLAYONOFFDATA;


typedef struct tagDESKSCANSCREENPOS
  {
    WORD wVirtDeskX;
    WORD wVirtDeskY;
  }
DESKSCANSCREENPOS;

typedef struct tagACCESSDEVICEDATA
{
 DWORD      dwSize;                   //Size of struct in bytes
 DWORD      dwSubFunc;                //Code indicating function requested
 DWORD      dwAccessDeviceCode;       //Code indicating the device requested
 DWORD      lpAccessCallbackFuncPtr;  //Far pointer to the client's callback function
} ACCESSDEVICEDATA;

typedef struct tagVRAMPtr
  {
    DWORD  VRAMPtrBeginAccess;
    DWORD  VRAMPtrEndAccess;
  } VRAMPtr;

typedef struct tagCWDDE32CMDBUF
{
    DWORD   dwSize;
    DWORD   dwFuncId;
    DWORD   dwSizeInput;
    DWORD   dwlpInData;
    DWORD   dwSizeOutput;
    DWORD   dwlpOutData;
}
CWDDE32CMDBUF, FAR *LPCWDDE32CMDBUF;

typedef struct tagATIBM
{
    DWORD   dwSize;
    DWORD   dwModuleId;
    DWORD   lpfnGetLockedContMem;
    DWORD   lpfnFreeLockedContMem;
    DWORD   lpfnSubmitGUIList;
    DWORD   lpfnSubmitSysList;
    DWORD   lpfnGetSysXferStatus;
    DWORD   lpfnLockMem;
    DWORD   lpfnUnlockMem;
    DWORD   lpfnXlateLinToPhys;
    DWORD   lpfnXlateLinRangeToPhys;
}
ATIBM, FAR *LPATIBM;


typedef struct tagGetCapsOutputBuffer
{
    DWORD    dwSize;
    DWORD    dwVersion;
    DWORD    dwCardNumber;
    DWORD    dwPanelID;
    BYTE    bColorPanel;
    BYTE    bPanelConstruction;
    WORD    wPanelType;
    BYTE    bRedBitsPerPrimary;
    BYTE    bGreenBitsPerPrimary;
    BYTE    bBlueBitsPerPrimary;
    BYTE    bReservedBitsPerPrimary;
    DWORD    dwHorizontalSize;
    DWORD    dwVerticalSize;
    DWORD    dwPixelClock;
    DWORD    dwCapabilities;
    DWORD    dwInverseControl;
    DWORD    dwShadingControl;
    DWORD    dwContrastControl;
    DWORD    dwBrightnessControl;
    WORD    wHorizontalPositioningControl;
    WORD    wVerticalPositioningControl;
    WORD    wHorizontalExpansionControl;
    WORD    wVerticalExpansionControl;
    DWORD    dwTextCursorSizeControl;
    DWORD    dwTextCursorBlinkingControl;
    DWORD    dwHardwareIconControl;
    DWORD    dwActiveDisplayControl;
    DWORD    dwFrameBufferSize;
    DWORD    dwFrameBufferPointer;

}
GETCAPSOUTPUTBUFFER, FAR *LPGETCAPSOUTPUTBUFFER;

typedef struct tagGetConfigBuffer
{
    DWORD    dwSize;
    DWORD    dwVersion;
    DWORD    dwCardNumber;
    DWORD    dwCapabilities;
    DWORD    dwInverseControl;
    DWORD    dwShadingControl;
    DWORD    dwContrastControl;
    DWORD    dwBrightnessControl;
    WORD     wHorizontalPositioningControl;
    WORD     wVerticalPositioningControl;
    WORD     wHorizontalExpansionControl;
    WORD     wVerticalExpansionControl;
    DWORD    dwTextCursorSizeControl;
    DWORD    dwTextCursorBlinkingControl;
    DWORD    dwHardwareIconControl;
    DWORD    dwActiveDisplayControl;

}
GETCONFIGBUFFER, FAR *LPGETCONFIGBUFFER;

typedef struct tagGetCapsInputBuffer
{
 DWORD        dwSize;
 DWORD        dwCount;
 DWORD        dwCardNumber;
}
GETCAPSINPUTBUFFER,FAR *LPGETCAPSINPUTBUFFER;
#endif  // CWDDE__H__



//
// $Archive: /3D/D3D/d3drage5/Rage5Direct3D/inc/ddraw/cwdde.h $
// $Author: Merwin $
// $Revision: 3 $
// $Date: 4/08/99 5:01p $
// $Modtime: 4/08/99 4:23p $
// $History: cwdde.h $
//
// *****************  Version 3  *****************
// User: Merwin       Date: 4/08/99    Time: 5:01p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/ddraw
// Rage 128 merge - memory leak fix
//
// *****************  Version 2  *****************
// User: Jweyman      Date: 2/16/99    Time: 5:19p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/ddraw
// added header/footer
//


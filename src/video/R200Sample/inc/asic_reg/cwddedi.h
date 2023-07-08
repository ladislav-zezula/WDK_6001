

/****************************************************************************\
*
*  Module Name    cwddedi.h
*  Project        R200
*
*  Description    ExtEscape function support is based on ATI's unique
*                 control code 0x7306 with a unified input parameter
*                 structure CWDDECMD as defined in this header file.
*                 The Escape32 defines a number of sub functions, which
*                 are grouped based on the following feature sets:
*
*                 Feature Group                  Sub Function Code
*                 CWDDE 32 - Configuration       0x0001XXXX
*                 CWDDE 32 - Rom Query           0x0002XXXX
*                 CWDDE 32 - Deskscan            0x0003XXXX
*                 CWDDE 32 - DPMS                0x0004XXXX
*                 CWDDE 32 - Gamma               0x0005XXXX
*                 CWDDE 32 - Display Mode        0x0006XXXX
*                 CWDDE 32 - Switches            0x0007XXXX
*                 CWDDE 32 - Screen Ajustment    0x0008XXXX
*                 CWDDE 32 - DCI                 0x0009XXXX
*                 CWDDE 32 - TV Out              0x000AXXXX
*                 CWDDE 32 - LCD                 0x000BXXXX
*                 CWDDE 32 - DDGamma             0x000CXXXX
*                 CWDDE DI - Adapter Routines    0x0011XXXX
*                 CWDDE DI - Controller Routines 0x0012XXXX
*                 CWDDE DI - Display Routines    0x0013XXXX
*                 CWDDE MM - Multimedia Routines 0x0014XXXX
*                 CWDDE HK - Hot Key Routines    0x0020XXXX
*                 CWDDE CI - Component Routines  0x0040XXXX
*                 CWDDE QC - Queue Server & Central
*                            Memory Manager      0x0060XXXX
*
*
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
\****************************************************************************/

#ifndef _CWDDEDI_H_
#define _CWDDEDI_H_

#pragma pack(push,1)

#define MAX_REGISTRY_PATH                       256 // Number of chars
#define MAX_SAVEDATA                            256 // Number of ULONGs
#define MAX_MESSAGECODEBUFFER_SIZE              256 // number of UCHAR
#define MAX_NUM_CONTROLLERS                     2
//*************************************************************************
// CWDDE defines
//*************************************************************************
#define Control_Config_CWDDE32                  0x07306

#define CWDDEDI_VERSION_MINOR                   0x00000007
#define CWDDEDI_VERSION_MAJOR                   0x00000001
#define CWDDEDI_VERSION (((ULONG)CWDDEDI_VERSION_MAJOR<<16) | CWDDEDI_VERSION_MINOR)

#define CWDDEDI_AdapterGetCaps                  0x00110001
#define CWDDEDI_AdapterGetInfo                  0x00110002
#define CWDDEDI_AdapterFlushSaveData            0x00110005
#define CWDDEDI_ControllerGetConfig             0x00120002
#define CWDDEDI_ControllerSetConfig             0x00120003
#define CWDDEDI_DisplayGetCaps                  0x00130000

///////////////////////////////////////////////////////////////////////////
// CWDDE return codes
///////////////////////////////////////////////////////////////////////////
#define CWDDE_OK                                0
#define CWDDE_OK_RESTART                        1
#define CWDDE_ERR_UNSUPPORTED                   2
#define CWDDE_ERR_OUTOFRANGE                    3
#define CWDDE_ERR_BADINPUTSIZE                  4
#define CWDDE_ERR_BADOUTPUTSIZE                 5
#define CWDDE_ERR_BADINPUT                      6
#define CWDDE_ERR_FUNCTION_FAILED               7
#define CWDDE_ERR_OVERLAY_PRESENT               8
#define CWDDE_ERR_FUNCTION_DISABLED             9

///////////////////////////////////////////////////////////////////////////
// Controller cap defines
///////////////////////////////////////////////////////////////////////////
#define CWDDEDI_CONTROLLER_CHANGE_FLAG_ENABLE_DISPLAYS  0x00000080

///////////////////////////////////////////////////////////////////////////
// Display type defines
///////////////////////////////////////////////////////////////////////////
#define DISPLAY_MONITOR                         0
#define DISPLAY_TELEVISION                      1
#define DISPLAY_LCDPANEL                        2
#define DISPLAY_DIGITALFLATPANEL                3
#define DISPLAY_COMPONENTVIDEO                  4

//*************************************************************************
// CWDDEC Structures
//*************************************************************************
#ifndef _CWDDECMD_
#define _CWDDECMD_
typedef struct tagCWDDECMD
{
    // CWDDECMD structure.
    ULONG ulSize;// size of CWDDECMD
    ULONG ulEscape32;// 32 bit escape code
    ULONG ulIndex;// index
    ULONG ulDriverReserved;
}CWDDECMD;
#endif  /* _CWDDECMD_ */

///////////////////////////////////////////////////////////////////////////
// Adapter structures
///////////////////////////////////////////////////////////////////////////
typedef struct tagADAPTERCAPS
{
    ULONG ulSize;
    ULONG ulAdapterID;
    ULONG ulNumControllers;
    ULONG ulNumDisplays;
    ULONG ulNumOverlays;
    ULONG ulCaps;
    ULONG ulReserved2;
    ULONG ulReserved3;
}ADAPTERCAPS;

typedef struct tagADAPTERINFO
{
    ULONG ulSize;
    ULONG ulDisplaysHaveLoad;
    ULONG ulHotPluggableDisplays;
    ULONG ulReserved1;
    ULONG ulReserved2;
}ADAPTERINFO;

typedef struct tagSAVEDATA
{
    ULONG ulSize;
    char cStrName[MAX_REGISTRY_PATH];
    ULONG ulReturnSize;
    ULONG ulBuffer[MAX_SAVEDATA];
}SAVEDATA;

///////////////////////////////////////////////////////////////////////////
// Controller structures
///////////////////////////////////////////////////////////////////////////
typedef struct tagCONTROLLERCONFIG
{
    ULONG ulSize;
    ULONG ulControllerIndex;
    LONG  lViewResolutionCx;
    LONG  lViewResolutionCy;
    LONG  lViewPositionX;
    LONG  lViewPositionY;
    LONG  lPanViewLockLeft;
    LONG  lPanViewLockTop;
    LONG  lPanViewLockRight;
    LONG  lPanViewLockBottom;
    ULONG ulEnabledDisplays;
    ULONG ulVerticalRefresh;
    LONG lExpansion;
    LONG lOverlayGamma;
    LONG lCursorBlinkSpeed;
    ULONG ulLockSmartView;
    union
    {
      ULONG ulChangeFlag;                   // for ControllerSetConfig
      ULONG ulHwStatusFlag;                 // for ControllerGetConfig
    };
    ULONG ulControllerConfigflag;
    ULONG ulReserved1;
}CONTROLLERCONFIG;

typedef struct tagOUTPUTULONG
{
    ULONG ulSize;
    ULONG ulValue;
}OUTPUTULONG;

///////////////////////////////////////////////////////////////////////////
// Display structures
///////////////////////////////////////////////////////////////////////////
typedef struct tagDISPLAYCAPS
{
    ULONG ulSize;
    ULONG ulDisplayType;
    LONG lMaxResolutionCx;
    LONG lMaxResolutionCy;
    ULONG ulConfig;
    ULONG ulExtendedCaps;
    ULONG ulExtendedType;
    ULONG ulHPDInterruptBitMap;
}DISPLAYCAPS;

#pragma pack(pop)

#endif //_CWDDEDI_H_



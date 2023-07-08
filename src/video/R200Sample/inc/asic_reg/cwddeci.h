

/****************************************************************************\
*
*  Module Name    cwddeci.h
*  Project        R200
*
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
*
\****************************************************************************/

#ifndef _CWDDECI_H_
#define _CWDDECI_H_

#ifdef _WIN64
#pragma pack(8)
#else
#pragma pack(1)
#endif // _WIN64

#ifdef _H2INC
#ifndef ULONG 
typedef unsigned long ULONG;
#endif

#ifndef ULONG_PTR
typedef unsigned long ULONG_PTR;
#endif

#ifndef PVOID 
typedef void * PVOID;
#endif

#ifndef CHAR
typedef char CHAR;
#endif

#ifndef UCHAR
typedef unsigned char UCHAR;
#endif

#ifndef USHORT 
typedef unsigned short USHORT;
#endif
#endif

/****************************************************************************\
* CWDDE defines
\****************************************************************************/

#ifndef Control_Config_CWDDE32
#define Control_Config_CWDDE32                  0x07306
#endif

#define CWDDECI_VERSION_MAJOR                   0x00000001
#define CWDDECI_VERSION_MINOR                   0x00000041

#define CWDDECI_VERSION (((ULONG)CWDDECI_VERSION_MAJOR<<16) | CWDDECI_VERSION_MINOR)


/****************************************************************************\
* CWDDE Sub Functions
\****************************************************************************/
#define CWDDECI_CPUIDENTIFICATION               0x00400102
#define CWDDECI_GETASICID                       0x00400103
#define CWDDECI_GETASICACCESSRANGES             0x00400104
#define CWDDECI_CHIPSETIDENTIFICATION           0x00400105

#define CWDDECI_EXCLUSIVEMODE                   0x00400111
#define CWDDECI_GAMMAMODE                       0x0040011A

/****************************************************************************\
* CWDDE Return Codes
\****************************************************************************/

#define CWDDECI_OK                                0x00000000
#define CWDDECI_ERROR                             0x00000001
#define CWDDECI_NOTSUPPORTED                      0x00000002
#define CWDDECI_ERR_BADINPUTSIZE                  0x00000003
#define CWDDECI_ERR_BADOUTPUTSIZE                 0x00000004
#define CWDDECI_ERR_BADINPUT                      0x00000005
#define CWDDECI_ERR_BADOUTPUT                     0x00000006
#define CWDDECI_NOTFOUND                          0x00000007

/****************************************************************************\
* CWDDE Caps & Flags
\****************************************************************************/

// defines for CICPUCAPS.ulFlags field
#define CICPUFLAG_CPUID                         0x00000001
#define CICPUFLAG_MMX                           0x00000004

// defines for CIASICRANGES.ulCaps1
#define CIASICRANGESCAPS1_TILING_CAP            0x00000002
#define CIASICRANGESCAPS1_PRIMARYTILED_MACRO    0x00000004

// defines for CICHIPSETID.ulSBType
#define CISBTYPE_1543C                          0x00002000

// caps for CICHIPSETID.ulNBCaps
#define CINBCAPS_AGPREAD                        0x00000001
#define CINBCAPS_AGPWRITE                       0x00000002
#define CINBCAPS_AGPFASTWRITE                   0x00000004
#define CINBCAPS_PCIBUSMASTERREAD               0x00000008
#define CINBCAPS_PCIBUSMASTERWRITE              0x00000010
#define CINBCAPS_MASK                           (CINBCAPS_AGPREAD | \
                                                CINBCAPS_AGPWRITE | \
                                                CINBCAPS_AGPFASTWRITE | \
                                                CINBCAPS_PCIBUSMASTERREAD | \
                                                CINBCAPS_PCIBUSMASTERWRITE)

// defines for CIFRAMEIN.ulFlags
#define CIFRAMEIN_COUNTDDFLIP                   0x00010000 // counting method: DD flip
#define CIFRAMEIN_COUNTDDBLT                    0x00020000 // counting method: DD blt
#define CIFRAMEIN_COUNTDRVSWAPBUF               0x00040000 // counting method: DrvSwapBuffers
#define CIFRAMEIN_COUNTZCLEAR                   0x00080000 // counting method: Z clear
#define CIFRAMEIN_COUNTFRAMEDRAWN               0x00100000 // counting method: using CIFRAMEDRAWN
#define CIFRAMEIN_COUNTDONE                     0x00000001 // set when n frames has finished
#define CIFRAMEIN_WAITMODESWITCH                0x00000002 // waiting for a mode switch to start counting
#define CIFRAMEIN_STARTCOUNTING                 0x00000004 // set before count of n frames has started
#define CIFRAMEIN_GETCAPTURELCL                 0x00000100 // using a surface for screen capture
#define CIFRAMEIN_GETFRAMESLEFT                 0x80000000 // retrieving number of frames left to be played

// defines for CIGAMMAMODE.ulFunction field (enum)
#define CIGAMMAMODE_GETGAMMAMODE                0x00000003
#define CIGAMMAMODE_SETGAMMAMODE                0x00000004

// defines for CIGAMMAMODE.ulGammaMode field (enum)
#define CIGAMMAMODE_DESKTOP                     0x00000000
#define CIGAMMAMODE_FULLSCREENGAMING            0x00000001

// defines for CIBUSTESTINFO.ulBusCaps field
#define CIBUSTESTINFO_BUSCAPS_PCIREAD           0x00000001
#define CIBUSTESTINFO_BUSCAPS_AGPREAD           0x00000002
#define CIBUSTESTINFO_BUSCAPS_PCIWRITE          0x00000004
#define CIBUSTESTINFO_BUSCAPS_AGPWRITE          0x00000008
#define CIBUSTESTINFO_BUSCAPS_FASTFBWRITE       0x00000010

/***************************************************************************\
* CWDDE Structures
\****************************************************************************/

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

typedef struct tagCICPUCAPS
{
    ULONG ulSize;
    ULONG ulFlags;
    ULONG ulType;
    ULONG ulCr0;
    ULONG ulCr2;
    ULONG ulCr3;
    ULONG ulCr4;
    ULONG ulPadding[9];// aligned on 16byte boundary
} CICPUCAPS;

typedef struct tagCIASICID
{
    ULONG ulSize;
    ULONG ulFlags;
    ULONG ulChipID;// Vendor and Device ID
    ULONG ulFamily;
    ULONG ulEmulatedRevision;
    ULONG ulVramInstalled;
    ULONG ulVramType;
    ULONG ulVramBitWidth;
    USHORT usXClock;   // core clock in MHz
    USHORT usMClock;   // memory clock in MHz
    ULONG ulSubsystemID;  // subsystem ID and subsystem vendor ID
    ULONG ulPadding[6];// aligned on 16byte boundary
} CIASICID;

typedef struct tagCIASICRANGES
{
    ULONG ulSize;
    ULONG ulFlags;
    PVOID pIo;
    PVOID pMmrSelector;
    PVOID pMmr;
    PVOID pVramSelector;
    PVOID pVram;
    ULONG_PTR ulVramBase;
    ULONG_PTR ulAgpBase;
    ULONG_PTR ulPm4Base;
    ULONG ulModeWidth;
    ULONG ulModeHeight;
    ULONG ulModeBpp;
    ULONG ulRotation;
    ULONG_PTR ulPCIGartBase; // correlates to ulAgpBase field, excect via PCIGart
    ULONG ulCaps1;
    ULONG_PTR ulVRAMHeapStart;
    ULONG_PTR ulVRAMHeapEnd;
    ULONG ulPadding[6];// aligned on 16byte boundary
} CIASICRANGES;

typedef struct tagCICHIPSETID
{
    ULONG ulSize;
    ULONG ulFlags;
    ULONG ulNBCaps;
    ULONG ulSBCaps;
    USHORT usNBVendorID;
    USHORT usNBDeviceID;
    USHORT usSBVendorID;
    USHORT usSBDeviceID;
    ULONG ulNBType;
    ULONG ulSBType;
    ULONG ulPadding[14];// aligned on 16byte boundary
} CICHIPSETID;

typedef struct tagCICALLBACKDATA_DCI
{
    ULONG ulSize;                    // Size of the structure
    ULONG ulReserved1;
    ULONG ulReserved2;
    ULONG ulCBViewResolutionY;       // CRTC height
    ULONG ulCBViewPositionX;         // Panning mode view position x coordinate
    ULONG ulCBViewPositionY;         // Panning mode view position y coordinate
    ULONG ulCBExpansion;             // Expansion mode
    ULONG ulReserved3;
    ULONG ulCBExpandedResolutionY;   // Vertical resolution for panel expansion
    ULONG ulReserved5;
    ULONG ulCBCurrentCRTC;           // The current CRTC among the active ones as in the ulCBConnectedCRTCs
    ULONG ulCBConnectedCRTCs;        // A bit-vector of active CRTCs
    ULONG ulCBOverlayActiveCRTC;     // Current CRTC for switchable overlay
    ULONG ulCBScreenOffset;          // Display buffer beginning offset
    ULONG ulReserved6;
    ULONG ulCBViewResolutionX;       // CRTC width
    ULONG ulModeBpp;
    ULONG ulModeWidth;               // Desktop width
    ULONG ulModeHeight;              // Desktop height
    ULONG ulScreenPitch;
    ULONG ulCaps1;                   // Same caps as set in CIASICRANGES
    ULONG ulPadding[3];              // aligned on 16byte boundary
} CICALLBACKDATA_DCI;

typedef struct tagCIULONG
{
    ULONG ulSize;
    ULONG ulData;
} CIULONG;

typedef struct tagCIEXCLUSIVEMODE
{
    ULONG ulSize;
    ULONG ulExclusiveMode;
} CIEXCLUSIVEMODE;

typedef struct tagCIFRAMEIN
{
    ULONG ulSize;
    ULONG ulNumFrames;
    PVOID pCallbackData;
    ULONG ulFlags;
    ULONG ulPadding[12];
} CIFRAMEIN;

typedef struct tagCIGAMMAMODE
{
    ULONG ulSize;
    ULONG ulFunction;
    ULONG ulGammaMode;
    ULONG ulPadding[5];
} CIGAMMAMODE;

#pragma pack()

#endif /*_CWDDECI_H_ */


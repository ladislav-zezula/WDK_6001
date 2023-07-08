

/****************************************************************************\
*
*  Module Name    COMBIOS.H
*  Project        For R128/M3/Rage 6
*  Device         R128/M3/Rage 6
*
*  Description    Shared header file defining BIOS ROM structures for DAL components
*
*  Copyright (c) 1998-2000 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
\****************************************************************************/

#ifndef _COMBIOS_H
#define _COMBIOS_H

#pragma pack(1)                         // BIOS data must use byte aligment

// Define offset to location of ROM header.
#define OFFSET_TO_POINTER_TO_ROM_HEADER         0x48L


#define MIN_COMPATIBLE_BIOS_HEADER_TYPE         2

#define MAX_NO_OF_LCD_RES_TIMING                25                                          

#define MAX_PLL_CNTL_ENTRIES                    8   // twdal#9190

// Define string names for identification within the ROM
#define BIOS_AURORA  ".AUR"            // string to identify Aurora in first 1K of ROM
#define BIOS_KC1     ".KC1"            // string to identify King City 1 in first 1K of ROM
#define BIOS_KC2     ".KC2"            // string to identify King City 2 in first 1K of ROM


// Structure which will store the ROM header.
typedef struct _ROM_HEADER
{
    UCHAR  ucTypeDefinition;
    UCHAR  ucExtFunctionCode;
    UCHAR  ucOemID1;
    UCHAR  ucOemID2;
    UCHAR  ucBiosMajorRev;
    UCHAR  ucBiosMinorRev;
    USHORT usStructureSize;
    USHORT usPointerToSmi;
    USHORT usPointerToPmid;
    USHORT usPointerToInitTable;
    USHORT usPointerToCrcChecksumBlock;
    USHORT usPointerToConfigFilename;
    USHORT usPointerToLogonMessage;
    USHORT usPointerToMiscInfo;
    USHORT usPciBusDevInitCode;
    USHORT usBiosRuntimeSegmentAddress;
    USHORT usIoBaseAddress;
    USHORT usSubsystemVendorID;
    USHORT usSubsystemID;
    USHORT usPostVendorID;
    USHORT usInt10Offset;
    USHORT usInt10Segment;
    USHORT usMonitorInfo;
    USHORT usPointerToConfigBlock;
    USHORT usPointerToDacDelayInfo;
    USHORT usPointerToCapDataStruct;
    USHORT usPointerToInternalCrtTables;
    USHORT usPointerToPllInfoBlock;
    USHORT usPointerToTVInfoTable;
    USHORT usPointerToDFPInfoTable;
    USHORT usPointerToHWConfigTable;
    USHORT usPointerToMMConfigTable;
    ULONG  ulTVStdPatchTableSignature;
    USHORT usPointerToTVStdPatchTable;
    USHORT usPointerToPanelInfoTable;
    USHORT usPointerToAsicInfoTable;
    USHORT usPointerToAuroraInfoTable;            // 44h-45h
    USHORT usPointerToPllInitTable;               // 46h-47h
    USHORT usPointerToMemoryConfigTable;          // 48h-49h
    USHORT usPointerToSaveMaskTable;              // 4ah
    USHORT usPointerHardCodedEdid;                    
    USHORT usPointerToExtendedInitTable1;             
    USHORT usPointerToExtendedInitTable2; 
    USHORT usPointerToDynamicClkTable;            // 52h
    USHORT usPointerToReservedMemoryTable;        
    USHORT usPointerToBridgetInitTable;
    USHORT usPointerToExtTMDSInitTable;
    USHORT usPointerToMemClkInfoTable;
    USHORT usPointerToExtDACTable;
    USHORT usPointerToMiscInfoTable;
} ROM_HEADER, FAR *LPROM_HEADER;

// Memory clock information table related definition
#define BIOS_REV12_ROM_HEADER_SIZE      0x5C

#define MEM_CLK_INFO_HEADER_ID          0x01
#define MEM_CLK_INFO_PRE_MEM_RESET_ID   0x02
#define MEM_CLK_INFO_PLL_CHANGE_ID      0x03
#define MEM_CLK_INFO_REG_CHANGE_ID      0x04
#define MEM_CLK_INFO_POST_MEM_RESET_ID  0x05
#define MEM_CLK_INFO_MC_REG_CHANGE_ID   0x06

#define REG_CHANGE_TABLE_END_MARKER     0xFFFF

typedef struct _ROM_PLL_CHANGE_TABLE
{
    UCHAR  ucPLLRegOffset;
    ULONG  ulAndMaskData;
    ULONG  ulOrMaskData;
} ROM_PLL_CHANGE_TABLE, FAR *LPROM_PLL_CHANGE_TABLE;

typedef struct _ROM_REG_CHANGE_TABLE
{
    USHORT  usRegisterOffset;
    ULONG   ulAndMaskData;
    ULONG   ulOrMaskData;
} ROM_REG_CHANGE_TABLE, FAR *LPROM_REG_CHANGE_TABLE;

typedef struct _ROM_MC_REG_CHANGE_TABLE
{
    UCHAR   ucMCRegOffset;
    ULONG   ulAndMaskData;
    ULONG   ulOrMaskData;
} ROM_MC_REG_CHANGE_TABLE, FAR *LPROM_MC_REG_CHANGE_TABLE;

typedef struct _ROM_MEM_CLK_RANGE_BLOCK
{
    UCHAR   ucBlockID;
    USHORT  usMinClkFreq;
    USHORT  usMaxClkFreq;
} ROM_MEM_CLK_RANGE_BLOCK, FAR *LPROM_MEM_CLK_RANGE_BLOCK;

typedef struct _ROM_TABLE_OFFSET_BLOCK
{
    UCHAR   ucBlockID;
    USHORT  usTableOffset;
} ROM_TABLE_OFFSET_BLOCK, FAR *LPROM_TABLE_OFFSET_BLOCK;

// Structure which will store the ROM's MISC INFO.
typedef struct _ROM_MISC_INFO
{
    ULONG ulControllerTypes;
    ULONG ulBusType;
    ULONG ulMemoryType;
} ROM_MISC_INFO, FAR *LPROM_MISC_INFO;
// Structure which will store the ROM's PLL BLOCK.
typedef struct _ROM_PLL_BLOCK
{
    UCHAR  ucPLLBiosVersion;                // Usually 6.
    UCHAR  ucStructureSize;             // Size in bytes.
    UCHAR  ucDotClockEntry;             // Dot clock entry used for accelerated modes.
    UCHAR  ucDotClockEntryVga;          // Dot clock entry used for extended VGA modes.
    USHORT usPointerToInternalClock;    // Offset into internal clock table used for by VGA parameter table.
    USHORT usPointerToFreqTable;        // Offset into actual programmed frequency table at POST.
    USHORT usXclkSetting;               // XCLK setting, (memory clock in 10 KHz units).
    USHORT usMclkSetting;               // MCLK setting, (engine clock in 10 KHz units).
    UCHAR  ucPllInfoBlockNumber;        // Number of PLL information block to follow, currently value is 3.
    UCHAR  ucPllInfoBlockSize;          // Size of each PLL information block.
    USHORT usDotClockRefFreq;           // Reference frequency of the dot clock.
    USHORT usDotClockRefDiv;            // Reference Divider of the dot clock.
    ULONG  ulDotClockMinFreq;           // Min Frequency supported before post divider for the dot clock.
    ULONG  ulDotClockMaxFreq;           // Max Frequency can be supported for the dot clock.
    USHORT usMclkRefFreq;               // Reference frequency of the MCLK, engine clock.
    USHORT usMclkRefDiv;                // Reference Divider of the MCLK, engine clock.
    ULONG  ulMclkMinFreq;               // Min Frequency supported before post divider for MCLK, engine clock.
    ULONG  ulMclkMaxFreq;               // Max Frequency can be supported for the MCLK, engine clock.
    USHORT usXclkRefFreq;               // Reference frequency of the XCLK, memory clock.
    USHORT usXclkRefDiv;                // Reference Divider of the XCLK, memory clock.
    ULONG  ulXclkMinFreq;               // Min Frequency supported before post divider for XCLK, memory clock.
    ULONG  ulXclkMaxFreq;               // Max Frequency can be supported for the XCLK, memory clock.
    
    //this is the PLL Information Table Extended structure
    //version 10
    UCHAR  ucNumberOfExtendedPllBlocks;

    UCHAR  ucSizePLLDefinition;

    USHORT ulCrystalFrequencyPixelClockPLL;          //(in 10 KHz unit)                         
    ULONG  ulMinInputPixelClockPLLFrequency;         //(in 10 KHz units)
    ULONG  ulMaxInputPixelClockPLLFrequency;         //(in 10 KHz units)
    ULONG  ulMinOutputPixelClockPLLFrequency;        //(in 10 KHz units)
    ULONG  ulMaxOutputPixelClockPLLFrequency;        //(in 10 KHz units)

    
    //version 11
    USHORT ulCrystalFrequencyEngineClockPLL;         //(in 10 KHz units)                         
    ULONG  ulMinInputFrequencyEngineClockPLL;        //(in 10 KHz units)
    ULONG  ulMaxInputFrequencyEngineClockPLL;        //(in 10 KHz units)
    ULONG  ulMinOutputFrequencyEngineClockPLL;       //(in 10 KHz units)
    ULONG  ulMaxOutputFrequencyEngineClockPLL;       //(in 10 KHz units)

    USHORT ulCrystalFrequencyMemoryClockPLL;         //(in 10 KHz units)                         
    ULONG  ulMinInputFrequencyMemoryClockPLL;        //(in 10 KHz units)
    ULONG  ulMaxInputFrequencyMemoryClockPLL;        //(in 10 KHz units)
    ULONG  ulMinOutputFrequencyMemoryClockPLL;       //(in 10 KHz units)
    ULONG  ulMaxOutputFrequencyMemoryClockPLL;       //(in 10 KHz units)    
    
    ULONG  ulMaximumDACOutputFrequency;              //(in 10 KHz units)
  
} ROM_PLL_BLOCK, FAR *LPROM_PLL_BLOCK;


// Structure which will store the ROM's hardware config block.
#define BIOSHWCONFIGTABLE_VIDEOPORT_AMCDVS0     0x01
#define BIOSHWCONFIGTABLE_VIDEOPORT_ZVVP        0x02
#define BIOSHWCONFIGTABLE_VIDEOPORT_AMCDVS1     0x04
#define BIOSHWCONFIGTABLE_VIDEOPORT_VIP16       0x08

typedef struct _HW_CONFIG_TABLE
{
    ULONG   ulSignature;                // HW info table signature string "$ATI"
    UCHAR   ucRevision;                 // HW info table revision
    UCHAR   ucStructureSize;            // HW info table size
    UCHAR   ucI2CType;                  // I2C type (normal GP_IO, ImpactTV GP_IO, Dedicated I2C pin, etc)
    UCHAR   ucTVOutInfo;                // Type of TV out supported (3:0) and video out crystal frequency (6:4) and TV data port (7)
    UCHAR   ucVideoPortInfo;            // Provides the video port capabilities
    UCHAR   ucHostPortInfo;             // Provides host port configuration information
} HW_CONFIG_TABLE, FAR *LPHW_CONFIG_TABLE;

// Structure which will store the ROM's Multimedia table block.
typedef struct _MM_CONFIG_TABLE
{
    UCHAR   ucTunerInfo;                // Type of tuner installed on the adapter (4:0) and video input for tuner (7:5)
    UCHAR   ucAudioChipInfo;            // List the audio chip type (3:0) product type (4) and OEM revision (7:5)
    UCHAR   ucProductID;                // Defines as OEM ID or ATI board ID dependent on product type setting
    UCHAR   ucMiscInfo1;                // Tuner voltage (1:0) HW teletext support (3:2) FM audio decoder (5:4) reserved (6) audio scrambling (7)
    UCHAR   ucMiscInfo2;                // I2S input config (0) I2S output config (1) I2S Audio Chip (4:2) SPDIF Output Config (5) reserved (7:6)
    UCHAR   ucMiscInfo3;                // Video Decoder Type (3:0) Video In Standard/Crystal (7:4)
    UCHAR   ucMiscInfo4;                // Video Decoder Host Config (2:0) reserved (7:3)
    UCHAR   ucVideoInput0Info;          // Video Input 0 Type (1:0) F/B setting (2) physical connector ID (5:3) reserved (7:6)
    UCHAR   ucVideoInput1Info;          // Video Input 1 Type (1:0) F/B setting (2) physical connector ID (5:3) reserved (7:6)
    UCHAR   ucVideoInput2Info;          // Video Input 2 Type (1:0) F/B setting (2) physical connector ID (5:3) reserved (7:6)
    UCHAR   ucVideoInput3Info;          // Video Input 3 Type (1:0) F/B setting (2) physical connector ID (5:3) reserved (7:6)
    UCHAR   ucVideoInput4Info;          // Video Input 4 Type (1:0) F/B setting (2) physical connector ID (5:3) reserved (7:6)
} MM_CONFIG_TABLE, FAR *LPMM_CONFIG_TABLE;

typedef struct _FP_INFO
{
    UCHAR   ucTableRevision;
    UCHAR   usTableSize;
    UCHAR   ucChipType;
    UCHAR   ucPanelStandard;
    UCHAR   usPanelID;
    USHORT  usEDIDptr;

} FP_INFO, FAR *LP_FP_INFO;

#define PANELINFOTABLE_PANELCAPS_SETDEIPATTERN        0x01  // This flag will set the I-Pattern on DE during blank
#define PANELINFOTABLE_PANELCAPS_USEDIRECTRATIOVALUE  0x04  // This flag will make the driver use ratio value directly from BIOS Table
#define PANELINFOTABLE_PANELCAPS_DONTSETSSBUFRESETEN  0x08  // This flag will make the driver not set the LVDS_SS_GEN_CNTL__SS_BUF_RESET_EN bit.
#define PANELINFOTABLE_PANELCAPS_EXPANSION_DIS        0x10  // This flag will make the driver disable expansion.
#define PANELINFOTABLE_PANELCAPS_BACKLIGHTOFF         0x20  // This flag will turn off backlight during driver mode change.
#define PANELINFOTABLE_PANELCAPS_DISABLECRTCEN        0x40  // This flag will disable (reset) CRTC_EN during driver mode change
#define PANELINFOTABLE_PANELCAPS_PRESERVEDASPECTEXP   0x80  // This flag means that Offset of Mode Parameter Table to some other resolution
                                                            // points to Expansion Mode Parameter Table which preservs mode's aspect ratio

#define PANELINFOTABLE_PANELREFRESH_LVDSINTERFACE     0x01  // This bit (1) indicates that LCD is using the LVDS interface. 
                                                            // (0 will mean it is using the digital interface)

typedef struct _PANEL_INFORMATION_TABLE
{
    UCHAR   ucPanelIdentification;
    UCHAR   ucPanelIDString[24];
    USHORT  usHorizontalSize;
    USHORT  usVerticalSize;
    USHORT  usFlatPanelType;
    UCHAR   ucRedBitsPerPrimary;
    UCHAR   ucGreenBitsPerPrimary;
    UCHAR   ucBlueBitsPerPrimary;
    UCHAR   ucReservedBitsPerPrimary;
    UCHAR   ucPanelCaps;
    UCHAR   ucPowerSequenceDelayStepsInMS;           
    UCHAR   ucSupportedRefreshRateExtended;
    USHORT  usExtendedPanelInfoTable;
    USHORT  usPtrToHalfFrameBufferInformationTable; 
    USHORT  usVccOntoBlOn;
    USHORT  usOffDelay;
    USHORT  usRefDiv;
    UCHAR   ucPostDiv;
    USHORT  usFeedBackDiv;
    UCHAR   ucSpreadSpectrumType;
    USHORT  usSpreadSpectrumPercentage;
    UCHAR   ucBackLightLevel;
    UCHAR   ucBiasLevel;      
    UCHAR   ucPowerSequenceDelay;
    ULONG   ulPanelData;
    UCHAR   ucPanelRefreshRateData;
    USHORT  usSupportedRefreshRate;
    USHORT  usModeTableOffset[MAX_NO_OF_LCD_RES_TIMING];
}PANEL_INFORMATION_TABLE, FAR *LPPANEL_INFORMATION_TABLE;

typedef struct _EXTENDED_PANEL_INFO_TABLE
{
  UCHAR  ucExtendedPanelInfoTableVer;
  UCHAR  ucSSDelay;
  UCHAR  ucSSStepSizeIndex;

}EXTENDED_PANEL_INFO_TABLE, FAR *LPEXTENDED_PANEL_INFO_TABLE;

typedef struct _HALF_FRAME_BUFFER_INFORMATION_TABLE
{
    ULONG   ulSizeOffScreenMemoryForHalfFrameBuffer;           
    ULONG   ulPtrToReservedOffScreenMemoryForHalfFrameBuffer;       
}HALF_FRAME_BUFFER_INFORMATION_TABLE, FAR *LPHALF_FRAME_BUFFER_INFORMATION_TABLE;

typedef struct _LCD_MODE_TABLE_CENTER
{
    USHORT  usHorizontalRes;
    USHORT  usVerticalRes;
    UCHAR   ucModeType;
    USHORT  usOffset2ExpParamTable;
    USHORT  usOffset2TvParamTable;
    USHORT  usPixelClock;
    USHORT  usPixelClockAdjustment;
    USHORT  usFpPos;
    UCHAR   ucReserved;
    UCHAR   ucMiscBits;
    USHORT  usCrtcHTotal;
    USHORT  usCrtcHDisp;
    USHORT  usCrtcHSyncStrt;
    UCHAR   ucCrtcHSyncWid;
    USHORT  usCrtcVTotal;
    USHORT  usCrtcVDisp;
    USHORT  usCrtcVSyncStrt;
    UCHAR   ucOvrWidTop;
}LCD_MODE_TABLE_CENTER,  FAR *LPLCD_MODE_TABLE_CENTER;

#define LCD_MODE_TABLE_CENTER_EXP_SUPPORT      0x08

typedef struct _LCD_MODE_TABLE_EXP
{
    USHORT  usPixelClock;
    USHORT  usPixelClockAdjustment;
    USHORT  usFpPos;
    UCHAR   ucReserved;
    UCHAR   ucMiscBits;
    USHORT  usCrtcHTotal;
    USHORT  usCrtcHDisp;
    USHORT  usCrtcHSyncStrt;
    UCHAR   ucCrtcHSyncWid;
    USHORT  usCrtcVTotal;
    USHORT  usCrtcVDisp;
    USHORT  usCrtcVSyncStrt;
    UCHAR   ucOvrWidTop;
    USHORT  usHorizontalBlendRatio;
    ULONG   ulVgaVertStretching;
    USHORT  usCopVertStretching;
    USHORT  usVgaExtVertStretching;
}LCD_MODE_TABLE_EXP, FAR *LPLCD_MODE_TABLE_EXP;

#define MOBILE_INFO_TABLE_REV2    2
#define MOBILE_INFO_TABLE_REV3    3
#define MOBILE_INFO_TABLE_REV4    4
#define MOBILE_INFO_TABLE_REV5    5
#define MOBILE_INFO_TABLE_REV6    6

// Mobile Information Table
typedef struct _MOBILE_INFO_TABLE
{
    UCHAR   ucTableRev;       // 0
    UCHAR   ucSize;           // 1
    UCHAR   ucReserved1;      // 2
    UCHAR   ucInfoFlag;       // 3
    UCHAR   ucReserved2;      // 4
    UCHAR   ucReserved3;      // 5
    USHORT  usReserved1;      // 6 - 7
    UCHAR   ucCrtI2C;         // 8
    ULONG   ulGPIOPullLow;    // 9 - 12
    ULONG   ulGPIODefault;    // 13- 16
    USHORT  usOffsetToPowerSavingTable;
    USHORT  usOffsetToGPIOSuspendStateTable;
    USHORT  usOffsetToLCDDDCInfoTable;
    USHORT  usOffsetToTmdsOnOffInfoTable;

}MOBILE_INFO_TABLE, FAR *LPMOBILE_INFO_TABLE;

// LCD DDC Information Table
typedef struct _LCDDDC_INFO_TABLE
{
    UCHAR   ucTableRev;       // 0
    UCHAR   ucSize;           // 1
    UCHAR   ucDDCLine;        // 2
    ULONG   ulI2CClockMask;   // 3 - 6
    ULONG   ulI2CDataMask;    // 7 - A

}LCDDDC_INFO_TABLE, FAR *LPLCDDDC_INFO_TABLE;

// Panel Link Information Table
typedef struct _TMDSONOFF_INFO_TABLE
{
    UCHAR   ucTableRev;
    UCHAR   ucFlags;
    USHORT  usOffsetToPowerOnSeqTable;
    USHORT  usOffsetToPowerOffSeqTable;

}TMDSONOFF_INFO_TABLE, FAR *LPTMDSONOFF_INFO_TABLE;

typedef struct _TMDS_POWERON_SEQ_TABLE
{
    UCHAR   ucTableRev;
    ULONG   ulGPIOVccAndMask;
    ULONG   ulGPIOVccOrMask;
    USHORT  usDelay1;
    ULONG   ulGPIOVddAndMask;
    ULONG   ulGPIOVddOrMask;
    USHORT  usDelay2;
    ULONG   ulGPIOBlonAndMask;
    ULONG   ulGPIOBlonOrMask;
    USHORT  usDelay3;

}TMDS_POWERON_SEQ_TABLE, FAR *LPTMDS_POWERON_SEQ_TABLE;

typedef struct _TMDS_POWEROFF_SEQ_TABLE
{
    UCHAR   ucTableRev;
    ULONG   ulGPIOBlonAndMask;
    ULONG   ulGPIOBlonOrMask;
    USHORT  usDelay1;
    ULONG   ulGPIOVddAndMask;
    ULONG   ulGPIOVddOrMask;
    USHORT  usDelay2;
    ULONG   ulGPIOVccAndMask;
    ULONG   ulGPIOVccOrMask;
    USHORT  usDelay3;

}TMDS_POWEROFF_SEQ_TABLE, FAR *LPTMDS_POWEROFF_SEQ_TABLE;

typedef struct _TMDS_PLL_CNTL_BLOCK   // twdal#9190
{
    USHORT  usClockUpperRange;
    ULONG   ulPllSetting;
}TMDS_PLL_CNTL_BLOCK, FAR *LPTMDS_PLL_CNTL_BLOCK;


typedef struct _ROM_DFP_INFO_TABLE   // twdal#9190
{
    UCHAR   ucDFPInfoTableRev;
    UCHAR   ucDFPInfoTableSize;
    USHORT  usOffsetDetailedTimingTable;
    UCHAR   ucReserved;
    UCHAR   ucNumberOfClockRanges;
    USHORT  usMaxPixelClock;
    ULONG   ulInitValueTmdsPllCntl;
    ULONG   ulFinalValueTmdsPllCntl;
    TMDS_PLL_CNTL_BLOCK  sTmdsPllCntlBlock[MAX_PLL_CNTL_ENTRIES];
}ROM_DFP_INFO_TABLE, FAR *LPROM_DFP_INFO_TABLE;

#define MOBILE_POWER_SAVING_BLOCK_FLAG_SPLITCLK               0x0000
#define MOBILE_POWER_SAVING_BLOCK_FLAG_MCLK_SRC_SPLL          0x0001
#define MOBILE_POWER_SAVING_BLOCK_FLAG_SCLK_SRC_MPLL          0x0002
#define MOBILE_POWER_SAVING_BLOCK_FLAG_VOLTAGE_DROP           0x0004
#define MOBILE_POWER_SAVING_BLOCK_FLAG_VOLTAGE_DROP_POLARITY  0x0008
#define MOBILE_POWER_SAVING_BLOCK_FLAG_LCD_LOW_REFRESHRATE    0x0010

#define MOBILE_POWER_SAVING_BLOCK_FLAG_OVERCLOCKED            0x0080
#define MOBILE_POWER_SAVING_BLOCK_FLAG_DYN_HALF_SPEED_EN      0x0100
#define MOBILE_POWER_SAVING_BLOCK_FLAG_DYN_CORE_VOLTAGE_EN    0x0200
#define MOBILE_POWER_SAVING_BLOCK_FLAG_SLEEP_EN               0x0400
#define MOBILE_POWER_SAVING_BLOCK_FLAG_LOAD_BALANCING_EN      0x0800
#define MOBILE_POWER_SAVING_BLOCK_FLAG_DEFAULT_FOR_DC         0x1000
#define MOBILE_POWER_SAVING_BLOCK_FLAG_DEFAULT_FOR_DCLOW      0x2000
#define MOBILE_POWER_SAVING_BLOCK_FLAG_POWER_SAVING_MODE      0x4000
#define MOBILE_POWER_SAVING_BLOCK_FLAG_THERMAL_DIODE_MODE     0x8000

typedef struct _MOBILE_POWER_SAVING_BLOCK
{
    USHORT  usFlags;
    ULONG   ulMemoryClock;
    ULONG   ulCoreClock;
    UCHAR   ucLCDLowRefreshRate;
    USHORT  usVoltageDropGPIORegister;
    UCHAR   usVoltageDropGPIOPin;
    USHORT  usOffsetToPPlayMemRstSeqTable;

}MOBILE_POWER_SAVING_BLOCK, FAR *LPMOBILE_POWER_SAVING_BLOCK;

#define MAX_NUM_POWERSAVING_BLOCKS    8
#define MAX_NUM_MEMRST_BLOCKS         8
#define MEM_RESET_TBALE_END_MARKER    0xFF

#define MOBILE_POWER_SAVING_TABLE_REV2   2
#define MOBILE_POWER_SAVING_TABLE_REV3   3
#define MOBILE_POWER_SAVING_TABLE_REV4   4

// Power Saving Table
typedef struct _MOBILE_POWER_SAVING_TABLE
{
    UCHAR   ucTableRev;       // 0
    UCHAR   ucSize;           // 1
    UCHAR   ucNumberOfPowerSavingBlock; // 2
    USHORT  usOffsetToMemRstSequenceTable; // 3 - 4
    MOBILE_POWER_SAVING_BLOCK  sMobilePowerSavingBlock[MAX_NUM_POWERSAVING_BLOCKS];

}MOBILE_POWER_SAVING_TABLE, FAR *LPMOBILE_POWER_SAVING_TABLE;

typedef struct _MOBILE_GPIO_STATE_BLOCK
{
    USHORT  usOffsetToGPIORegister;
    ULONG   ulGPIO_MASK;
    ULONG   ulGPIO_SETTINGS;
}MOBILE_GPIO_STATE_BLOCK, FAR *LPMOBILE_GPIO_STATE_BLOCK;

#define MAX_NUM_GPIO_REGISTERS        30

typedef struct _MOBILE_GPIO_INFO_TABLE
{
    UCHAR   ucTableRev;       // 0
    UCHAR   ucSize;           // 1
    UCHAR   ucNumberOfGPIOBlock; // 2
    MOBILE_GPIO_STATE_BLOCK  sMobileGPIOStateBlock[MAX_NUM_GPIO_REGISTERS];
}MOBILE_GPIO_INFO_TABLE, FAR *LPMOBILE_GPIO_INFO_TABLE;

typedef struct _MEMRST_BLOCK
{
    UCHAR   ucRegCommand1;
    USHORT  usRegMode1;
    UCHAR   ucRegCommand2;
    USHORT  usRegMode2;
    UCHAR   ucRegCommand3;
}MEMRST_BLOCK, FAR * LPMEMRST_BLOCK;

typedef struct _MEMRST_TABLE
{
    MEMRST_BLOCK  sMemResetBlock[MAX_NUM_MEMRST_BLOCKS];
}MEMRST_TABLE, FAR *LPMEMRST_TABLE;

// constants for ucTableRevision
#define     FP_INFO_REV0                 0x0
#define     FP_INFO_REV1                 0x1

// constants for ucChipType in FP_INFO
#define     SILICON_IMAGE_1024X768       0x1
#define     SILICON_IMAGE_1280X1024      0x2
#define     SILICON_IMAGE_1600X1200      0x3

// these constants are a little different in rev 1.
#define     FP_640X480                   0x0
#define     FP_800X600                   0x1
#define     FP_1024X768                  0x2
#define     FP_1280X1024                 0x3

// constants of ucPanelStandard in FP_INFO
#define     FP_STANDARD_TFT              0x1
#define     FP_STANDARD_DSTN             0x2

// constants for usPanelID in FP_INFO
#define     TOSHIBA_PANEL                0x01

// Define offsets to different parts of the VGA memory needed for BIOS calls.
#define VGA_OFFSET_OFF_SCREEN_COLOR_TEXT 0x0001A000      // x86 real mode segment 0xBA00
#define VGA_OFFSET_COLOR_TEXT            0x00018000      // x86 real mode segment 0xB800
#define VGA_OFFSET_OFF_SCREEN_MONO_TEXT  0x00012000      // x86 real mode segment 0xB200
#define VGA_OFFSET_MONO_TEXT             0x00010000      // x86 real mode segment 0xB000

//
// The  following bits are defined for M3 Scratch registers usage only.
//

// bit definitions for BIOS_4_SCRATCH 
#define mmBIOS_CONNECT_INFO              mmBIOS_4_SCRATCH
#define BCI_CRT_MONO                     0x00000001L
#define BCI_CRT_COLOR                    0x00000002L
#define BCI_LCD                          0x00000004L
#define BCI_DFP                          0x00000008L
#define BCI_TV_COMPOSITE                 0x00000010L
#define BCI_TV_SVIDEO                    0x00000020L
#define BCI_CRT_FORCE                    0x00000100L
#define BCI_TV_FORCE                     0x00000200L
#define BCI_PANEL_ID_MASK                 0x000F0000L

// The  following bits are used for BIOS usage only
                                      
//#define PANEL_ID_MASK                     0x000f0000L
#define LCD_REFRESH_MASK                    0x1f000000L
//#define TV_STANDARD_MASK                  0x0f000000L
#define LCD_REFRESH_SHIFT                   0x00000018L 

//#define PANEL_INFORMATION_TABLE related shift
#define PANELINFO_SUPPORTEDREFRESHRATE_EXTENDED_SHIFT 0x0010
#define PANELINFO_PANELREFRESHRATEDATA_SHIFT          0x04
#define PANELINFO_PANELREFRESHRATEDATA_EXTENDED_SHIFT 0x01
#define PANELINFO_PANELREFRESHRATEDATA_EXTENDED_MASK  0x08


// bit definitions for BIOS_5_SCRATCH 
#define mmBIOS_DISPLAY_INFO               mmBIOS_5_SCRATCH
#define BDI_REQ_LCD                       0x00000001L
#define BDI_REQ_CRT                       0x00000002L
#define BDI_REQ_TV                        0x00000004L
#define BDI_REQ_DFP                       0x00000008L
#define BDI_REQ_CRTC_LCD                  0x00000010L
#define BDI_REQ_CRTC_CRT                  0x00000020L
#define BDI_REQ_CRTC_TV                   0x00000040L
#define BDI_REQ_CRTC_DFP                  0x00000080L
#define BDI_LCD_STATE                     0x00000100L
#define BDI_CRT_STATE                     0x00000200L
#define BDI_TV_STATE                      0x00000400L
#define BDI_DFP_STATE                     0x00000800L
#define BDI_LCD_CRTC_STATE                0x00001000L
#define BDI_CRT_CRTC_STATE                0x00002000L
#define BDI_TV_CRTC_STATE                 0x00004000L
#define BDI_DFP_CRTC_STATE                0x00008000L
#define BDI_ACC_REQ_LCD                   0x00010000L
#define BDI_ACC_REQ_CRT                   0x00020000L
#define BDI_ACC_REQ_TV                    0x00040000L
#define BDI_ACC_REQ_DFP                   0x00080000L

// bit definitions for BIOS_7_SCRATCH
#define mmBIOS_MISC_INFO                  mmBIOS_7_SCRATCH
#define BMI_EXP_REQ_TEXT_H                0x00000001L
#define BMI_EXP_REQ_TEXT_V                0x00000002L
#define BMI_EXP_REQ_GRAPH_H               0x00000004L
#define BMI_EXP_REQ_GRAPH_V               0x00000008L

// The  following bits are used for BIOS usage only
/*
#define DPMS_STATE_MASK                   0x00000300L
#define SET_LCD                           0x00010000L
#define SET_CRT                           0x00020000L
#define SET_TV                            0x00040000L
#define SET_DFP                           0x00080000L
#define SET_CRTC_LCD                      0x00100000L
#define SET_CRTC_CRT                      0x00200000L
#define SET_CRTC_TV                       0x00400000L
#define SET_CRTC_DFP                      0x00800000L
*/                                        
#define BMI_DEVICE_CHANGE                 0x01000000L
#define BMI_EXP_CHANGE                    0x02000000L
#define BMI_ACC_MODE                      0x08000000L
#define BMI_EXT_DESKTOP_MODE              0x10000000L
#define BMI_LID_STATE                     0x80000000L




//********************************************************************************
// The  following bits are defined for R6/Piglet/M6 Scratch registers usage only.
//********************************************************************************

// bit definitions for BIOS_4_SCRATCH
#define R6D_S4_CRT1_MONO                 0x00000001L
#define R6D_S4_CRT1_COLOR                0x00000002L
#define R6D_S4_LCD1                      0x00000004L
#define R6D_S4_DFP1                      0x00000008L
#define R6D_S4_TV1_COMPOSITE             0x00000010L
#define R6D_S4_TV1_SVIDEO                0x00000020L
#define R6D_S4_CRT1_FORCE                0x00000040L
#define R6D_S4_TV1_FORCE                 0x00000080L

#define R6D_S4_CRT2_MONO                 0x00000100L
#define R6D_S4_CRT2_COLOR                0x00000200L
#define R6D_S4_LCD2                      0x00000400L
#define R6D_S4_DFP2                      0x00000800L
#define R6D_S4_TV2_COMPOSITE             0x00001000L
#define R6D_S4_TV2_SVIDEO                0x00002000L
#define R6D_S4_CRT2_FORCE                0x00004000L
#define R6D_S4_TV2_FORCE                 0x00008000L
#define R6D_S4_EXPANSION_MODE            0x00010000L  // if set, expansion to other than
                                                      // panel size
#define R6D_S4_THERMAL_STATE             0x00100000L
#define R6D_S4_THERMAL_CHANGE            0x00800000L

// bit definitions for BIOS_5_SCRATCH
#define R6D_S5_LCD1_STATE                0x00000001L
#define R6D_S5_CRT1_STATE                0x00000002L
#define R6D_S5_TV1_STATE                 0x00000004L
#define R6D_S5_DFP1_STATE                0x00000008L
#define R6D_S5_LCD2_STATE                0x00000010L
#define R6D_S5_CRT2_STATE                0x00000020L
#define R6D_S5_TV2_STATE                 0x00000040L
#define R6D_S5_DFP2_STATE                0x00000080L

#define R6D_S5_LCD1_CRTC_STATE           0x00000100L
#define R6D_S5_CRT1_CRTC_STATE           0x00000200L
#define R6D_S5_TV1_CRTC_STATE            0x00000400L
#define R6D_S5_DFP1_CRTC_STATE           0x00000800L
#define R6D_S5_LCD2_CRTC_STATE           0x00001000L
#define R6D_S5_CRT2_CRTC_STATE           0x00002000L
#define R6D_S5_TV2_CRTC_STATE            0x00004000L
#define R6D_S5_DFP2_CRTC_STATE           0x00008000L

#define R6D_S5_ACTIVE_INFO_MASK          (R6D_S5_LCD1_STATE  \
                                        | R6D_S5_CRT1_STATE  \
                                        | R6D_S5_TV1_STATE   \
                                        | R6D_S5_DFP1_STATE  \
                                        | R6D_S5_LCD2_STATE  \
                                        | R6D_S5_CRT2_STATE  \
                                        | R6D_S5_TV2_STATE   \
                                        | R6D_S5_DFP2_STATE)

#define R6D_S5_ACTIVE_CRTC_INFO_MASK    (R6D_S5_LCD1_CRTC_STATE \
                                        | R6D_S5_CRT1_CRTC_STATE \
                                        | R6D_S5_TV1_CRTC_STATE  \
                                        | R6D_S5_DFP1_CRTC_STATE \
                                        | R6D_S5_LCD2_CRTC_STATE \
                                        | R6D_S5_CRT2_CRTC_STATE \
                                        | R6D_S5_TV2_CRTC_STATE  \
                                        | R6D_S5_DFP2_CRTC_STATE)


#define R6D_S5_ACC_REQ_LCD1              0x00010000L
#define R6D_S5_ACC_REQ_CRT1              0x00020000L
#define R6D_S5_ACC_REQ_TV1               0x00040000L
#define R6D_S5_ACC_REQ_DFP1              0x00080000L
#define R6D_S5_ACC_REQ_LCD2              0x00100000L
#define R6D_S5_ACC_REQ_CRT2              0x00200000L
#define R6D_S5_ACC_REQ_TV2               0x00400000L
#define R6D_S5_ACC_REQ_DFP2              0x00800000L

#define R6D_S5_ACC_REQ_INFO_MASK         (R6D_S5_ACC_REQ_LCD1  \
                                        | R6D_S5_ACC_REQ_CRT1  \
                                        | R6D_S5_ACC_REQ_TV1   \
                                        | R6D_S5_ACC_REQ_DFP1  \
                                        | R6D_S5_ACC_REQ_LCD2  \
                                        | R6D_S5_ACC_REQ_CRT2  \
                                        | R6D_S5_ACC_REQ_TV2   \
                                        | R6D_S5_ACC_REQ_DFP2)

#define R6D_S5_REQ_LCD1                  0x01000000L
#define R6D_S5_REQ_CRT1                  0x02000000L
#define R6D_S5_REQ_TV1                   0x04000000L
#define R6D_S5_REQ_DFP1                  0x08000000L
#define R6D_S5_REQ_LCD2                  0x10000000L
#define R6D_S5_REQ_CRT2                  0x20000000L
#define R6D_S5_REQ_TV2                   0x40000000L
#define R6D_S5_REQ_DFP2                  0x80000000L


#define R6D_S5_REQ_INFO                  (R6D_S5_REQ_LCD1   \
                                        | R6D_S5_REQ_CRT1   \
                                        | R6D_S5_REQ_TV1    \
                                        | R6D_S5_REQ_DFP1   \
                                        | R6D_S5_REQ_LCD2   \
                                        | R6D_S5_REQ_CRT2   \
                                        | R6D_S5_REQ_TV2    \
                                        | R6D_S5_REQ_DFP2)

// bit definitions for BIOS_6_SCRATCH
#define R6D_S6_DEVICE_CHANGE             0x00000001L
#define R6D_S6_EXPANSION_CHANGE          0x00000002L
#define R6D_S6_ACC_MODE_CHANGE           0x00000004L
#define R6D_S6_EXT_DESKTOP_MODE          0x00000008L

#define R6D_S6_LID_STATE                 0x00000010L
#define R6D_S6_DOCK_STATE                0x00000020L
#define R6D_S6_LID_CHANGE                0x00000040L   //spec.rev.2.0
#define R6D_S6_DOCK_CHANGE               0x00000080L

#define R6D_S6_EXP_REQ_TEXT_H            0x00000100L
#define R6D_S6_EXP_REQ_GRAPH_H           0x00000200L
#define R6D_S6_EXP_REQ_TEXT_V            0x00000400L
#define R6D_S6_EXP_REQ_GRAPH_V           0x00000800L

#define R6D_S6_FIREGL_SUPPORT            0x00002000L
#define R6D_S6_VRAM_SAVE_RESTORE_REQ     0x00004000L
#define R6D_S6_INT_GEN_BY_VBIOS          0x00008000L

#define R6D_S6_DPMS_STATE_STANDBY        0x01000000L
#define R6D_S6_DPMS_STATE_SUSPEND        0x02000000L
#define R6D_S6_DPMS_STATE_OFF            0x03000000L
#define R6D_S6_DPMS_STATE_MASK           0x03000000L
#define R6D_S6_DPMS_STATE_SHIFT          0x00000018L
#define R6D_S6_DISPLAY_DPMS_STATE_MASK   0x00F00000L  
#define R6D_S6_DISPLAY_DPMS_STATE_SHIFT  0x00000014L

// This bit is used by the drivers to indicate it is
// in the middle of some critcal section code. Driver
// will set and rest the flag.
#define R6D_S6_DRV_CRITICAL_SECTION      0x08000000L
#define R6D_S6_PM4_DET                   0x10000000L
#define R6D_S6_DISPLAY_SWITCHING_FLAG    0x40000000L


//*********************************************************************
// BIOS function CALLS
//*********************************************************************

#define BIOS_FUNCTION_LCD_DFP_SERVICES         0xA082          // LCD/DFP services
#define SUB_FUNCTION_SET_REQEXPANSIONMODE      0x0307          // BL=0x07, BH=0x03: Set Request Expansion Mode in CMOS
#define PARAMETER_NORMALEXPANSIONMODE          0x0000          // CL Parameter for Normal Expansion Mode
#define PARAMETER_OTHEREXPANSIONMODE           0x0001          // CL Parameter for Other Expansion Mode

#define BIOS_FUNCTION_SET_CMOS_INFO            0xA08B          // Set CMOS Information
#define SUB_FUNCTION_UPDATE_DISPLAY_INFO       0x8000          // Sub function 80
#define SUB_FUNCTION_UPDATE_EXPANSION_INFO     0x8100          // Sub function 80

#define BIOS_FUNCTION_LCD_CONTROL              0xA08E          // Function to turn on and off lcd via BIOS
#define SUB_FUNCTION_TURN_LCD_ONOFF            0x0000          // Sub function 00
#define PARAMETER_LCD_ON                       0x0001          // CL Parameter for ON
#define PARAMETER_LCD_OFF                      0x0000          // CL Parameter for OFF

#define BIOS_FUNCTION_GET_SYSTEM_BIOS_INFO      0xA08F          // Get LID state/Get CMOS Info
#define SUB_FUNCTION_GET_LIDSTATE               0x0700          // Sub function 7
#define SUB_FUNCTION_GET_REQ_DISPLAY_FROM_SBIOS 0x0800          // Sub function 8
#define SUB_FUNCTION_OUT_OFF_CRITICAL_SECTION   0x8300          // Sub function 83
#define SUB_FUNCTION_GET_REQ_DISPLAY_FROM_SBIOS_MODE   0x8800   // Sub function 88 (with Windows/DOS mode parameter)
#define PARAMETER_WINDOWS_MODE                  0x0001          // Windows mode parameter  

#define BIOS_FUNCTION_VESADPMS                  0x4F10          // Set DPMS 
#define SUB_FUNCTION_SET_DPMS                   0x0001          // BL: Sub function 01 
#define SUB_FUNCTION_GET_DPMS                   0x0002          // BL: Sub function 02 
#define PARAMETER_VESADPMS_ON                   0x0000          // BH Parameter for DPMS ON.  
#define PARAMETER_VESADPMS_STANDBY              0x0100          // BH Parameter for DPMS STANDBY  
#define PARAMETER_VESADPMS_SUSPEND              0x0200          // BH Parameter for DPMS SUSPEND
#define PARAMETER_VESADPMS_OFF                  0x0400          // BH Parameter for DPMS OFF
#define PARAMETER_VESADPMS_REDUCEON             0x0800          // BH Parameter for DPMS REDUCE ON (NOT SUPPORTED)

#define BIOS_FUNCTION_DEVICEONOFF              0xA08E         // Set Device on/off
#define SUB_FUNCTION_DEVICEONOFF_DRIVER        0x0000         // BH : 00  Driver call video bios for Device on/off   
#define PARAMETER_DEVICEONOFF_DEVICEOFF        0x0000         // CL : 00  Device off   
#define PARAMETER_DEVICEONOFF_DEVICEON         0x0001         // CL : 01  Device on 
#define PARAMETER_DEVICEONOFF_DPMS             0x0080         // CL : bit 7 Set DPMS .
#define PARAMETER_DEVICEONOFF_REQUESTED_MASK   0xFF00         // CH Parameter for requested device
#define PARAMETER_DEVICEONOFF_REQUESTED_SHIFT  0x0008         // CH Parameter for requested device  

#define BIOS_RETURN_CODE_MASK                   0x0000FF00L
#define BIOS_REGH_MASK                          0x0000FF00L
#define BIOS_REGL_MASK                          0x000000FFL

#define LCD1_ACTIVE                     0x0001
#define CRT1_ACTIVE                     0x0002 
#define TV1_ACTIVE                      0x0004
#define DFP1_ACTIVE                     0x0008
#define CRT2_ACTIVE                     0x0020 
#define DFP2_ACTIVE                     0x0080

#define LCD1_CONNECTED                  0x0100
#define CRT1_CONNECTED                  0x0200 
#define TV1_CONNECTED                   0x0400
#define DFP1_CONNECTED                  0x0800
#define CRT2_CONNECTED                  0x2000 
#define DFP2_CONNECTED                  0x8000

#define LCD1_AVAILABLE                  LCD1_ACTIVE
#define CRT1_AVAILABLE                  CRT1_ACTIVE
#define TV1_AVAILABLE                   TV1_ACTIVE
#define DFP1_AVAILABLE                  DFP1_ACTIVE
#define CRT2_AVAILABLE                  CRT2_ACTIVE
#define DFP2_AVAILABLE                  DFP2_ACTIVE

#define LCD1_SBIOS_REQ                  LCD1_ACTIVE
#define CRT1_SBIOS_REQ                  CRT1_ACTIVE
#define TV1_SBIOS_REQ                   TV1_ACTIVE 
#define DFP1_SBIOS_REQ                  DFP1_ACTIVE
#define CRT2_SBIOS_REQ                  CRT2_ACTIVE
#define DFP2_SBIOS_REQ                  DFP2_ACTIVE

//
// Define for BusType of the RomMiscInfo structure.
// AGP or PCI
//
#define BUSTYPE_PCI               0x20494350 // ' ICP' (or 'PCI ' backwards)
#define BUSTYPE_AGP               0x20504741 // ' PGA' (or 'AGP ' backwards)

//
// Define the various memory types available.
//
#define MEMTYPE_SDR_SGRAM_11      0x31534753  // '1SGS' (or 'SGS1' backwards)
#define MEMTYPE_SDR_SGRAM_21      0x32534753  // '2SGS' (or 'SGS2' backwards)
#define MEMTYPE_SDR_SDRAM_11      0x31534453  // '1SDS' (or 'SDS1' backwards)
#define MEMTYPE_SDR_SDRAM_21      0x32534453  // '2SDS' (or 'SDS2' backwards)
#define MEMTYPE_DDR_SGRAM         0x31444753  // '1DGS' (or 'SGD1' backwards)
#define MEMTYPE_DDR_SDRAM         0x31444744  // '1DGD' (or 'DGD1' backwards)
#define MEMTYPE_DDR_SDRAM_NO_DLL  0x314E4744  // '1NGD' (or 'DGN1' backwards)
#define MEMTYPE_UNKNOWN           0x4F4E5544  // 'ONUD' (or 'DUNO' backwards)
#define MEMTYPE_DDR_SGRAM_NO_DLL  MEMTYPE_DDR_SDRAM_NO_DLL  //EPR#50364
// 
// TODO: What should be in the Combios.h, we shouldn't 
// have any one asic specific
// [RC] Mar 23, 00 - removed ifdef RAGE6
//

//
// TODO: Is this the right place for this
// See R6$INIT7.ASM and R6$INITC.ASM
//
#define EXTENDED_REGISTER_TABLE_END                 0x00
#define EXTENDED_REGISTER_TABLE_DELAY_REGLOAD_BIT	0x8000
#define EXTENDED_REGISTER_TABLE_ANDOR_REGLOAD_BIT	0x4000
#define EXTENDED_REGISTER_TABLE_IO_REGLOAD_BIT		0x2000
#define EXTENDED_REGISTER_TABLE_MASK_OF_REGS_FLAG   0x1FFF


//
// See R6$CLK.ASM
// 
#define PLL_TABLE_END                   0x00
#define PLL_TABLE_SPECIAL_COMMAND_BIT	0x80
#define PLL_TABLE_ANDOR_PLL_BIT         0x40
#define PLL_TABLE_INDEX_MASK            0x3f
#define PLL_TABLE_SC_1                  0x01
#define PLL_TABLE_SC_2                  0x02
#define PLL_TABLE_SC_3                  0x03
#define PLL_TABLE_SC_4                  0x04
#define PLL_TABLE_SC_5                  0x05
#define PLL_TABLE_SC_MAX_COUNTER        1000
#define pllWAIT_MC_BUSY_MASK            0x00010000
#define pllWAIT_DLL_READY_MASK          0x00080000
#define ROM_EXTENDED_MEMORY_CONFIG_TABLE_LENGTH     0x3000
#define SGRAM_RESET_TABLE_WAIT_MC_STATUS            0x0f
#define SGRAM_RESET_TABLE_END                       0xff
#define MEM_SDRAM_MODE_REG__MEM_SDRAM_RESET_COMPLETE_MASK \
(MEM_SDRAM_MODE_REG__MC_INIT_COMPLETE_MASK | \
 MEM_SDRAM_MODE_REG__MEM_SDRAM_RESET_MASK)

#define ROM_EXTENDED_MEMORY_CONFIG_TABLE_LENGTH 0x3000
#define ROM_EXTENDED_REGISTER_INIT_TABLE_LENGTH 0x2000
#define ROM_PLL_INIT_TABLE_LENGTH               0x3000
#define SGRAM_RESET_TABLE_WAIT_MC_STATUS        0x0f
#define SGRAM_RESET_TABLE_END                   0xff
#define MEM_SDRAM_MODE_REG__MEM_SDRAM_RESET_COMPLETE_MASK \
(MEM_SDRAM_MODE_REG__MC_INIT_COMPLETE_MASK | \
 MEM_SDRAM_MODE_REG__MEM_SDRAM_RESET_MASK)

typedef struct _ROM_EXTENDED_REGISTER_INIT_TABLE_ENTRY_FORMAT1
{
    USHORT usIndex;
    ULONG  ulData;
} ROM_EXTENDED_REGISTER_INIT_TABLE_ENTRY_FORMAT1,
        FAR *LPROM_EXTENDED_REGISTER_INIT_TABLE_ENTRY_FORMAT1;

typedef struct _ROM_EXTENDED_REGISTER_INIT_TABLE_ENTRY_FORMAT2
{
    //
    // This formst is now used by the Rage128 BIOS
    // 
    USHORT usIndex;      // MMR Index offset to register
    ULONG  ulOrMask;      
    ULONG  ulAndMask;
} ROM_EXTENDED_REGISTER_INIT_TABLE_ENTRY_FORMAT2,
        FAR *LPROM_EXTENDED_REGISTER_INIT_TABLE_ENTRY_FORMAT2;

typedef struct _ROM_EXTENDED_REGISTER_INIT_TABLE_ENTRY_FORMAT3
{
    //
    // This format is now used by the Rage6 BIOS
    //
    USHORT usIndex;      // MMR Index offset to register
    ULONG  ulAndValue;
    ULONG  ulOrValue;      
} ROM_EXTENDED_REGISTER_INIT_TABLE_ENTRY_FORMAT3,
        FAR *LPROM_EXTENDED_REGISTER_INIT_TABLE_ENTRY_FORMAT3;


typedef struct _ROM_PLL_INIT_TABLE_ENTRY1
{
    UCHAR ucIndex;
    UCHAR ucOffset;
    UCHAR ucAndMask;
    UCHAR ucOrMask;
} ROM_PLL_INIT_TABLE_ENTRY1, FAR *LPROM_PLL_INIT_TABLE_ENTRY1;

typedef struct _ROM_PLL_INIT_TABLE_ENTRY2
{
    UCHAR ucIndex;
    ULONG ulData;
} ROM_PLL_INIT_TABLE_ENTRY2, FAR *LPROM_PLL_INIT_TABLE_ENTRY2;

typedef struct _ROM_MEMORY_CONFIG_TABLE_ENTRY
{
    UCHAR ucMemSize;
    UCHAR ucAddrMapping;
} ROM_MEMORY_CONFIG_TABLE_ENTRY, FAR *LPROM_MEMORY_CONFIG_TABLE_ENTRY;

typedef struct _SGRAM_RESET_TABLE_ENTRY
{
    UCHAR ucResetPattern;
    USHORT usModeReg;
} SGRAM_RESET_TABLE_ENTRY, *LPSGRAM_RESET_TABLE_ENTRY;

#define MAMMASBOY_MCLK_CNTL_POST_MASK        0x0000ffff
#define MAMMASBOY_SCLK_CNTL_POST_MASK        0x0000000f
#define MAMMASBOY_PLL_CNTL_MASK              (~0xffffc7ff)


#define VESA_PM_SERVICES                         0x4f10
#define VESA_SET_POWER_STATE_BL                  0x01
#define VESA_REQUESTED_POWER_STATE_BH_ON         0x00 
#define VESA_REQUESTED_POWER_STATE_BH_STANDBY    0x01
#define VESA_REQUESTED_POWER_STATE_BH_SUSPEND    0x02
#define VESA_REQUESTED_POWER_STATE_BH_OFF        0x04




//
//  Bridget Table        
//

typedef struct _ROM_BRIDGET_REGISTER_INIT_TABLE_ENTRY_FORMAT1
{
    USHORT usIndex;
    ULONG  ulData;
} ROM_BRIDGET_REGISTER_INIT_TABLE_ENTRY_FORMAT1,
        FAR *LPROM_BRIDGET_REGISTER_INIT_TABLE_ENTRY_FORMAT1;



typedef struct _ROM_BRIDGET_REGISTER_INIT_TABLE_ENTRY_FORMAT2
{
    USHORT usIndex;      // MMR Index offset to register
    ULONG  ulAndValue;
    ULONG  ulOrValue;      
} ROM_BRIDGET_REGISTER_INIT_TABLE_ENTRY_FORMAT2,
        FAR *LPROM_BRIDGET_REGISTER_INIT_TABLE_ENTRY_FORMAT2;


#define BRIDGET_REGISTER_TABLE_MASK_OF_REGS_FLAG    0x1FFF
#define BRIDGET_REGISTER_TABLE_ANDOR_REGLOAD_BIT	0x4000
#define BRIDGET_TABLE_END                           0x00



//
// External TMDS table
//

typedef struct _ROM_EXTTMDS_TABLE_HEADER
{ 
    UCHAR  ucTableRev;
    USHORT usTableSize;
    UCHAR  ucNoBlocks;
} ROM_EXTTMDS_TABLE_HEADER, FAR *LPROM_EXTTMDS_TABLE_HEADER;

typedef struct _ROM_EXTTMDS_BLOCK_HEADER
{ 
    USHORT usMaxFreq;
    UCHAR  ucI2CSlaveAddr;
    UCHAR  ucI2CLine;
    UCHAR  ucConnectorId;
    UCHAR  ucFlags;
} ROM_EXTTMDS_BLOCK_HEADER, FAR *LPROM_EXTTMDS_BLOCK_HEADER;

typedef struct _ROM_EXTTMDS_CMD_ENTRY
{ 
    USHORT usIndex;
} ROM_EXTTMDS_CMD_ENTRY, FAR *LPROM_EXTTMDS_CMD_ENTRY;

typedef ROM_EXTENDED_REGISTER_INIT_TABLE_ENTRY_FORMAT1 ROM_EXTTMDS_MMWRITE_CMD_ENTRY;
typedef ROM_EXTENDED_REGISTER_INIT_TABLE_ENTRY_FORMAT3 ROM_EXTTMDS_MMMASKWRITE_CMD_ENTRY;
typedef ROM_EXTENDED_REGISTER_INIT_TABLE_ENTRY_FORMAT3 ROM_EXTTMDS_PLLMASKWRITE_CMD_ENTRY;

typedef struct _ROM_EXTTMDS_DELAYMICROSEC_CMD_ENTRY 
{
    USHORT usIndex;
    USHORT usData;
} ROM_EXTTMDS_DELAYMICROSEC_CMD_ENTRY, FAR *LPROM_EXTTMDS_DELAYMICROSEC_CMD_ENTRY;

typedef struct _ROM_EXTTMDS_I2CWRITE_CMD_ENTRY 
{
    USHORT usIndex;
    UCHAR  ucData;
} ROM_EXTTMDS_I2CWRITE_CMD_ENTRY, FAR *LPROM_EXTTMDS_I2CWRITE_CMD_ENTRY;

// .usIndex
#define ROM_EXTTMDS_INDEX_CMD_MMWRITE           0
#define ROM_EXTTMDS_INDEX_CMD_MMMASKWRITE       2
#define ROM_EXTTMDS_INDEX_CMD_DELAYMICROSEC     4
#define ROM_EXTTMDS_INDEX_CMD_PLLMASKWRITE      5
#define ROM_EXTTMDS_INDEX_CMD_I2CWRITE          6
#define ROM_EXTTMDS_INDEX_OFFSET_MASK           0x1fff
#define ROM_EXTTMDS_INDEX_CMD_SHIFT             13
#define ROM_EXTTMDS_INDEX_END                   0xffff

// ROM_EXTTMDS_BLOCK_HEADER.ucFlags
#define ROM_EXTTMDS_FLAG_LINKTYPE_MASK          0x01
#define ROM_EXTTMDS_FLAG_INITDEFAULT_MASK       0x80

#define ROM_EXTTMDS_FLAG_LINKTYPE_SINGLELINK    0x00000000
#define ROM_EXTTMDS_FLAG_LINKTYPE_DUALLINK      0x00000001

// ROM_EXTTMDS_BLOCK_HEADER.ucI2CLine
#define ROM_EXTTMDS_I2CLINE_MONID               1
#define ROM_EXTTMDS_I2CLINE_DVI                 2
#define ROM_EXTTMDS_I2CLINE_VGA                 3
#define ROM_EXTTMDS_I2CLINE_CRT2                4
#define ROM_EXTTMDS_I2CLINE_MM                  5


// Connector table - applicable from Piglet and later ASICs
//	byte 0 	(embedded revision)
//		[7:4]	= number of chips (valid number 1 - 15)
//		[3:0]	= revision number of table (valid number 1 - 15)
//
//	byte 1 (Chip info)
//		[7:4]	= chip number, max. 15 (valid number 1 - 15)
//		[3:0]	= number of connectors for that chip, (valid number 1 - 15)
//			(number of connectors = number of 'Connector info' entries for that chip)
//	
//	byte 2,3 (Connector info)
//		[15:12]	- connector type
//			= 0 	- no connector		
//			= 1 	- proprietary
//			= 2 	- CRT
//			= 3 	- DVI-I
//			= 4  	- DVI-D
//			= 5-15	- reserved for future expansion
//		[11:8]	- DDC line pair used for that connector
//			= 0 	- no DDC
//			= 1 	- MONID 0/1
//			= 2 	- DVI_DDC
//			= 3 	- VGA_DDC
//			= 4 	- CRT2_DDC
//			= 5-15	- reserved for future expansion
//    [5] - bit indicating presence of multiplexer for TV,CRT2
//		[7:6]	- reserved for future expansion
//		[4]	- TMDS type
//			= 0 	- internal TMDS
//			= 1  	- external TMDS
//		[3:1]	- reserved for future expansion
//		[0]	- DAC associated with that connector
//			= 0	- CRT DAC
//			= 1	- non-CRT DAC (e.g. TV DAC, external DAC ..)	
//
//	byte 4,5,6... 	- byte 4,5 can be another "Connector info" word describing another connector
//			- or byte 5 is a "Chip info" byte for anther chip, then start with byte 5,6 to describe connectors for that chip
//			- or byte 5 = 0 if all connectors for all chips on board have been described, no more connector left to describe.
//	......
//	......
//
#define BIOS_CONNECTOR_INFO__TYPE__MASK                   0xF000
#define BIOS_CONNECTOR_INFO__TYPE__SHIFT                  0x0000000C
#define BIOS_CONNECTOR_TYPE__NONE                         0x00000000
#define BIOS_CONNECTOR_TYPE__PROPRIETARY                  0x00000001
#define BIOS_CONNECTOR_TYPE__CRT                          0x00000002
#define BIOS_CONNECTOR_TYPE__DVI_I                        0x00000003
#define BIOS_CONNECTOR_TYPE__DVI_D                        0x00000004

#define BIOS_CONNECTOR_INFO__DDC_LINE__MASK               0x0F00
#define BIOS_CONNECTOR_INFO__DDC_LINE__SHIFT              0x00000008
#define BIOS_DDC_LINE__NONE                               0x00000000
#define BIOS_DDC_LINE__MONID01                            0x00000001
#define BIOS_DDC_LINE__DVI                                0x00000002
#define BIOS_DDC_LINE__VGA                                0x00000003
#define BIOS_DDC_LINE__CRT2                               0x00000004
#define BIOS_DDC_LINE__GPIOPAD                            0x00000005
#define BIOS_DDC_LINE__ZV_LCDPAD                          0x00000006

#define BIOS_CONNECTOR_INFO__TMDS_TYPE                    0x0010
#define BIOS_CONNECTOR_INFO__TMDS_TYPE__SHIFT             0x00000004
#define BIOS_TMDS_TYPE__INTERNAL                          0x00000000
#define BIOS_TMDS_TYPE__EXTERNAL                          0x00000001

#define BIOS_CONNECTOR_INFO__DAC_TYPE                     0x0001
#define BIOS_CONNECTOR_INFO__DAC_TYPE__SHIFT              0x00000000
#define BIOS_DAC_TYPE__CRT                                0x00000000
#define BIOS_DAC_TYPE__NON_CRT                            0x00000001

#define BIOS_CONNECTOR_INFO__MUX_MASK                     0x00000020
#define BIOS_CONNECTOR_INFO__MUX_SHIFT                    0x00000005

typedef struct _BIOS_CONNECTOR_INFO
{
  USHORT usConnectorInfo;
} BIOS_CONNECTOR_INFO, FAR *LPBIOS_CONNECTOR_INFO;

#define BIOS_CHIPINFO_HEADER__CHIP_NUMBER__MASK           0xF0
#define BIOS_CHIPINFO_HEADER__CHIP_NUMBER__SHIFT          0x00000004

#define BIOS_CHIPINFO_HEADER__NUMBER_OF_CONNECTORS__MASK  0x0F
#define BIOS_CHIPINFO_HEADER__NUMBER_OF_CONNECTORS__SHIFT 0x00000000

#define BIOS_CHIPINFO__MAX_NUMBER_OF_CONNECTORS           0x00000010

typedef struct _BIOS_CONNECTOR_CHIPINFO
{   UCHAR                 ucChipHeader;
    BIOS_CONNECTOR_INFO   sConnectorInfo[BIOS_CHIPINFO__MAX_NUMBER_OF_CONNECTORS];
} BIOS_CONNECTOR_CHIPINFO, FAR *LPBIOS_CONNECTOR_CHIPINFO;

#define BIOS_CONNECTOR_HEADER__NUMBER_OF_CHIPS__MASK      0xF0
#define BIOS_CONNECTOR_HEADER__NUMBER_OF_CHIPS__SHIFT     0x00000004

#define BIOS_CONNECTOR_HEADER__TABLE_REVISION__MASK       0x0F
#define BIOS_CONNECTOR_HEADER__TABLE_REVISION__SHIFT      0x00000000

#define BIOS_CONNECTOR_TABLE__MAX_NUMBER_OF_CHIPS         0x00000010

typedef struct _BIOS_CONNECTOR_TABLE
{   UCHAR                     ucConnectorHeader;
    BIOS_CONNECTOR_CHIPINFO   sChipConnectorInfo[BIOS_CONNECTOR_TABLE__MAX_NUMBER_OF_CHIPS];
} BIOS_CONNECTOR_TABLE, FAR *LPBIOS_CONNECTOR_TABLE;


//
//Miscellaneous Information Table
//
//Offset( byte )	                Content
//000h 	Miscellaneous Information Table revision                        0	1
//001h 	Bit 0	= 0	- extended desktop / dual-view is not supported		
//		        = 1	- extended desktop / dual-view is supported	        X	X
//	    Bits 7 - 1	= 0000000b	- reserved		
//002h	Size of Miscellaneous Information Table in bytes		            X
//003h - 004h	Offset of ASIC Initialization Table 3, if non-zero		    X
//005h - 006h	Offset of ASIC Initialization Table 4, if non-zero		    X
//007h - 008h	Offset of Detected Memory Information Table, if non-zero 	X
//

typedef struct _BIOS_MISC_INFO_TABLE
{   UCHAR ueVersioncMiscInfoTabl;
    UCHAR ucInfo0;
} BIOS_MISC_INFO_TABLE, FAR *LPBIOS_MISC_INFO_TABLE;

typedef struct _BIOS_MISC_EXT_INFO_TABLE
{   
    BIOS_MISC_INFO_TABLE sBiosMiscInfoHead;
    UCHAR ucSize;
    USHORT usPointerToExtendedInitTable3;
    USHORT usPointerToExtendedInitTable4;
    USHORT usPointerToDetectedMemoryConfigTable;
} BIOS_MISC_INFO_EXT_TABLE, FAR *LPBIOS_MISC_EXT_INFO_TABLE;

#define BIOS_MISC_INFO_TABLE__INFO0__DUALVIEW__MASK       0x01

//
//Detected Memory Configuration Table

//Offset( byte )	                 Content
//000h	Detected Memory Configuration Table revision
//001h - 004h	Programming value of MEM_CNTL register for detected memory configuration
//005h - 006h	Detected memory size in MB
//
typedef struct _BIOS_DETECTED_MEM_CONFIG_TABLE
{   UCHAR ucVersioncDetectedMemConfigTabl;
    ULONG ulMemCntl;                         
    USHORT usMemSize;                        
} BIOS_DETECTED_MEM_CONFIG_TABLE, FAR *LPBIOS_DETECTED_MEM_CONFIG_TABLE;

//
//Reserved Memory Table
//
//Offset( byte )	                 Content
//000h - 001h	Starting address of memory reserved ( from top of physical memory ) in KB
//002h - 003h	Size of memory reserved in KB
//
typedef struct _BIOS_RESERVED_MEMORY_TABLE 
{
    USHORT usStartAddr;
    USHORT usMemSize;
} BIOS_RESERVED_MEMORY_TABLE, FAR *LBIOS_RESERVED_MEMORY_TABLE;

#pragma pack() // BIOS data must use byte aligment

#endif /* _COMBIOS_H */


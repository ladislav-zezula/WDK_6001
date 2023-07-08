

/*****************************************************************************\
* 
*  Module Name    bgf.h
*  Project        Rage6 Windows
*  Device         Rage
*
*  Description    header file for Rage driver
*  
*
*  (c) 1998-2001 ATI Technologies Inc. (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
\*****************************************************************************/

#ifndef _BGF_H
#define _BGF_H

//-------------------------------------------------------------------------------------------
// King City constants used to program the PAL and DAC

// These are all Output signals
#define  KCPAL_0_WANT_DISPLAY      0x004 // Pulse this bit 0-4-0 to req 
#define  KCPAL_0_DONE_DISPLAY      0x000 //  switch of display
#define  KCPAL_TRIGGER_EVENT       0x002 //
#define  KCPAL_0_MASTER_J2OFF      0x080 // set on master (chip1) only
#define  KCPAL_0_MASTER_C2ON       0x100 // set on master (chip1) only
#define  KCPAL_0_MASTER_C1ON       0x010 // set on master (chip1) only
#define  KCPAL_0_MASTER_C0ON       0x008 // set on master (chip1) only

// This is an input signal used to synchronize rendering on both chips.
#define  KCPAL_0_TRIGGER_EVENT     0x002

// These are all Input signals used to read status of PAL 
// switching mechanism

#define  KCPAL_1_VLOCK             0x08  // VID3 on VIPPAD1_A = VLOCK?
#define  KCPAL_1_HLOCK             0x04  // VID2 on VIPPAD1_A = HLOCK?
#define  KCPAL_1_VLOCK_HLOCK       (KCPAL_1_HLOCK | KCPAL_1_VLOCK)
#define  KCPAL_1_GCOMP_MAS         0x02  // VID1 on VIPPAD1_A = GCOMP(dacadj)
                                         // On MASTER (AGP/chip1) only
#define  KCPAL_1_FLIP1_SLV         0x02  // VID1 on VIPPAD1_A = FLIP1?
                                         // On SLAVE (PCI/chip2) only
#define  KCPAL_1_FLIP0_SLV         0x01  // VID1 on VIPPAD1_A = FLIP0?
                                         // On SLAVE (PCI/chip2) only
#define  KCPAL_1_MASTER_SLV        0x01  // VID0 on VIPPAD1_A = Status of PAL
                                         // 0 = AGP displayed, 1 = PCI 
                                         // On SLAVE (PCI/chip2) only

// WARNING --- The following KCPAL BITS MUST NOT CHANGE WHILE MAXX MODE RUNS
// eg ::  TVODATA[0] is used as the WAITEXTERNAL_EVENT input, and TVODATA[1] 
//          is used as set external event (which goes to other chip).
//          If the above 2 bits are not set correctly, then the 
//          WAIT_EXTERNAL_EVENT thing breaks.
#define  KCPAL_0_SETMASK          0x3ff   // enable TVODATA[8:0]
#define  KCPAL_0_SETENABLE        0x3fe   // TVODATA[8:1] = output, [0]=input.
#define  KCPAL_1_SETMASK          0xff    // enable VID[7:0]
#define  KCPAL_1_SETENABLE        0x0     // VID[7:0] all input

// -- These two are used to set mmI2C_CNTL_0, mmI2C_CNTL_1
#define  KCI2C_MAGIC1              0x14140027
#define  KCI2C_MAGIC2              0x28030000

// These are used when doing ASIC flips
#define  KCPAL_0_MASTER_FN_HSYNCFLIP  0
#define  KCPAL_0_MASTER_FN_ALT_LINES  (KCPAL_0_MASTER_C0ON)
#define  KCPAL_0_MASTER_FN_VSYNCFLIP  (KCPAL_0_MASTER_C1ON)
#define  KCPAL_0_MASTER_FN_FORCESLAVE (KCPAL_0_MASTER_C1ON | KCPAL_0_MASTER_C1ON)

//-------------------------------------------------------------------------------------------
// Althought there is no 100% way to choose a number won't be conflict with system.
// Normally, Devnode is a high memory address with some translation.
// The best way to choose this number should be a low number.
#define VIRTUAL_KC2SGDMSEC_DEVNODE  0x00008001
#define VIRTUAL_KC2P2PMSEC_DEVNODE  0x00008002

// R100 chip apertures under Bridget SGD mode
#define KC2SGDM_IOSize     0x00000200  // 256   * 2
//#define KC2SGDM_MMRSize    0x00100000  // 512KB * 2
#define KC2SGDM_MMRSize    0x00020000  // 64KB * 2
#define KC2SGDM_VRAMSize   0x08000000  // 64MB  * 2

// Bridget chip MMR aperture
#define BRIDGET_MMR_APERTURE_SIZE       (1*1024)

// Bridget register setting
#define BUS_P_CNTL__DEFAULT_SETTING	               0x5133a0b0
										// ( BUS_P_CNTL__BUS_READ_COMBINE_EN |
										//   US_P_CNTL__BUS_WRT_COMBINE_EN |
                                        //   BUS_P_CNTL__BIOS_ROM_WRT_EN |
                                        //   BUS_P_CNTL__BUS_PCI_READ_RETRY_EN |
                                        //   BUS_P_CNTL__BUS_PCI_WRT_RETRY_EN |
                                        //   (0x00030000 & BUS_P_CNTL__BUS_RETRY_WS_MASK) |
                                        //   BUS_P_CNTL__BUS_MSTR_RD_MULT |
                                        //   BUS_P_CNTL__BUS_MSTR_RD_LINE |
                                        //   BUS_P_CNTL__BUS_RD_DISCARD_EN |
                                        //   BUS_P_CNTL__BUS_MSTR_DISCONNECT_EN |
                                        //   BUS_P_CNTL__BUS_READ_BURST )
#define BUS_X_CNTL__DEFAULT_SETTING	               0x5133a0b0
#define BUS_Y_CNTL__DEFAULT_SETTING	               0x5133a0b0
#define AGPS_CTRL__DEFAULT_SETTING                 0xe0
#define BIF_MISC__DEFAULT_SETTING                  0x0
#define BUS_X_SARB_CNTL_B__DEFAULT_SETTING         0x4020
#define BUS_Y_SARB_CNTL_A__DEFAULT_SETTING         0x021f704a
#define MST_PRERD_CNTL__DEFAULT_SETTING            0x203
#define RESYNC_CNTL__DEFAULT_SETTING               0x0
#define HW_DEBUG__DEFAULT_SETTING                  0x8

#define PAD_MANUAL_OVERRIDE_MASK   0x00010000

#endif /* end _BGF_H */


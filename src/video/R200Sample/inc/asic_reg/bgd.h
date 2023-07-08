

#ifndef _bridgetd_h
#define _bridgetd_h

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

/************************************************************************
 *
 * Module Name:  bridgetd.h
 * Project:      bridget Register dword offset
 * Device:       bridget
 *
 * Description:  Header file for bridget
 *
 * (c) 2001 ATI Technologies Inc.  (unpublished)
 *
 *	 All rights reserved.
 *	 The year included in the foregoing notice is the year of creation of the work.
 *
 ************************************************************************
 *                                                                      *
 *
 * $$File:       /proj/bridget/devel_slindsay/reg/release/bridget.chip
 * $$ASIC Name:  bridget
 * $$Regs Rev:   Chip Spec 1.15
 * $$Date :      Tue Jan 16 13:36:36 2001

 *
 */



// [gdConfig] : cfg Registers

#define cfgVENDOR_ID                             0x0000
#define cfgDEVICE_ID                             0x0000
#define cfgCOMMAND                               0x0001
#define cfgSTATUS                                0x0001
#define cfgREVISION_ID                           0x0002
#define cfgREGPROG_INF                           0x0002
#define cfgSUB_CLASS_BG                          0x0002
#define cfgBASE_CODE                             0x0002
#define cfgCACHE_LINE                            0x0003
#define cfgLATENCY                               0x0003
#define cfgHEADER_BG                             0x0003
#define cfgBIST                                  0x0003
#define cfgBAR10REG                              0x0004
#define cfgBAR14REG                              0x0005
#define cfgBAR18REG                              0x0006
#define cfgBAR1CREG                              0x0007
#define cfgBAR20REG                              0x0008
#define cfgBAR24REG                              0x0009
#define cfgBAR30REG                              0x000C
#define cfgBAR38REG                              0x000E
#define cfgCAPABILITIES_PTR                      0x000D
#define cfgINTERRUPT_LINE                        0x000F
#define cfgINTERRUPT_PIN                         0x000F
#define cfgBRIDGE_CONTROL_X                      0x000F
#define cfgPMI_CAP_ID                            0x0014
#define cfgPMI_NXT_CAP_PTR                       0x0014
#define cfgPMI_PMC_REG                           0x0014
#define cfgPM_STATUS                             0x0015
#define cfgPMCSR_BSE                             0x0015
#define cfgPMI_DATA                              0x0015
#define cfgAGP_CAP_ID                            0x0016
#define cfgAGP_STATUS                            0x0017
#define cfgAGP_COMMAND                           0x0018
#define cfgTYPE1_P2PB_AGP_COMMAND_X              0x0058
#define cfgBAR10WMASK                            0x0028
#define cfgBAR14WMASK                            0x0029
#define cfgBAR18WMASK                            0x002A
#define cfgBAR1CWMASK                            0x002B
#define cfgBAR20WMASK                            0x002C
#define cfgBAR24WMASK                            0x002D
#define cfgBAR30WMASK                            0x002E
#define cfgBAR38WMASK                            0x002F
#define cfgBAR3EWMASK                            0x0030

// [p2pbConfig] : cfg Registers

#define cfgVENDOR_ID                             0x0000
#define cfgDEVICE_ID_Y                           0x0000
#define cfgP2PB_COMMAND_Y                        0x0001
#define cfgP2PB_STATUS_Y                         0x0001
#define cfgREVISION_ID                           0x0002
#define cfgREGPROG_INF                           0x0002
#define cfgSUB_CLASS_BG                          0x0002
#define cfgBASE_CODE                             0x0002
#define cfgP2PB_CACHE_LINE_Y                     0x0003
#define cfgP2PB_LATENCY_Y                        0x0003
#define cfgHEADER_Y                              0x0003
#define cfgBIST                                  0x0003
#define cfgP2PB_BUSNUM_Y                         0x0006
#define cfgP2PB_IO_BASE_Y                        0x0007
#define cfgP2PB_MEM_BASE_Y                       0x0008
#define cfgP2PB_PREFETCH_MEM_BASE_Y              0x0009
#define cfgIO_BASE_UPPER_16BITS_Y                0x000C
#define cfgIO_LIMIT_UPPER_16BITS_Y               0x000C
#define cfgCAPABILITIES_PTR_Y                    0x000D
#define cfgP2PB_INTERRUPT_LINE_Y                 0x000F
#define cfgBRIDGE_CONTROL_Y                      0x000F
#define cfgPMI_CAP_ID                            0x0014
#define cfgPMI_NXT_CAP_PTR                       0x0014
#define cfgPMI_PMC_REG                           0x0014
#define cfgPM_STATUS_Y                           0x0015
#define cfgPMCSR_BSE_Y                           0x0015
#define cfgPMI_DATA                              0x0015
#define cfgAGP_CAP_ID_Y                          0x0016
#define cfgAGP_STATUS_Y                          0x0017
#define cfgP2PB_AGP_COMMAND_Y                    0x0018
#define cfgTYPE1_P2PB_AGP_COMMAND_Y              0x0058

// [regAper] : mm Registers

#define mmBUS_P_CNTL                             0x0020
#define mmBUS_X_CNTL                             0x0021
#define mmBUS_Y_CNTL                             0x0022
#define mmBUS_P_PAD_CTLR_STRENGTH                0x0023
#define mmBUS_P_PAD_CTLR_UPDATE                  0x0024
#define mmBUS_X_PAD_CTLR_STRENGTH                0x003A
#define mmBUS_X_PAD_CTLR_UPDATE                  0x003B
#define mmBUS_Y_PAD_CTLR_STRENGTH                0x004A
#define mmFW_CNTL_BG                             0x0025
#define mmFW_STATUS_BG                           0x0026
#define mmAGP_CNTL_BG                            0x0027
#define mmBROADCAST_INDEX                        0x0030
#define mmBROADCAST_DATA                         0x0031
#define mmBROADCAST_OFFSET_X                     0x0032
#define mmBROADCAST_OFFSET_Y                     0x0033
#define mmBROADCAST_REMAP_XY                     0x0034
#define mmAGPS_CTRL                              0x0037
#define mmMARB_RESPONSE_WINDOW                   0x0060
#define mmMARB_CTRL                              0x0061
#define mmAGP2PCI_REMAPPING_OFFSET               0x0062
#define mmBUS_X_SARB_CNTL_A                      0x0064
#define mmBUS_X_SARB_CNTL_B                      0x0065
#define mmBUS_Y_SARB_CNTL_A                      0x0066
#define mmBUS_Y_SARB_CNTL_B                      0x0067
#define mmMST_PRERD_CNTL                         0x0068
#define mmBIF_MISC                               0x0069
#define mmPARB_ARBITOR_CNTL                      0x006A
#define mmPARB_TIMEOUT_CNTL                      0x006B
#define mmARBITRATION_STATUS                     0x006C
#define mmBYTE_SWAP_CNTL                         0x006D
#define mmBUS_X_PULL_UPDN_CNTL                   0x006E
#define mmBUS_Y_PULL_UPDN_CNTL                   0x006F
#define mmHW_DEBUG                               0x0070
#define mmRESYNC_CNTL                            0x0071
#define mmAGP_RESYNC_CNTL                        0x0072
#define mmALT_SECSTATUS_AND_BUSCONTROL_X         0x0074
#define mmALT_SECSTATUS_AND_BUSCONTROL_Y         0x0075
#define mmSGD_SEC_LAT_TIMER                      0x0076
#define mmCONFIG_XSTRAP1                         0x00B5
#define mmTEST_DEBUG_CNTL_BG                     0x00B6
#define mmTEST_DEBUG_MUX_BG                      0x00B7
#define mmTEST_DEBUG_OUT_BG                      0x00B8
#define mmROMMUX_CNTL                            0x00BA
#define mmTEST_GPIOPAD_MASK_BG                   0x00BB
#define mmSEPROM_CNTL1_BG                        0x00BE
#define mmSEPROM_CNTL2_BG                        0x00BF
#define mmAGP_PLL_CNTL_P                         0x00C0
#define mmAGP_PLL_CNTL_X                         0x00C1
#define mmAGP_PLL_CNTL_Y                         0x00C2
#define mmPLL_TEST_CNTL_BG                       0x00C3
#define mmCONFIG_XSTRAP2                         0x00C4
#define mmSTRAP_SCRATCH_REG                      0x00C5


#ifdef __cplusplus
}
#endif  // __cplusplus

#endif // _bridgetb_h





#ifndef _khanix_h
#define _khanix_h

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

/************************************************************************
 *
 * Module Name:  khanix.h
 * Project:      khan Register indirect
 * Device:       khan
 *
 * Description:  Header file for khan
 *
 * (c) 2001 ATI Technologies Inc.  (unpublished)
 *
 *	 All rights reserved.
 *	 The year included in the foregoing notice is the year of creation of the work.
 *
 ************************************************************************
 *                                                                      *
 *
 * $$File:       ../../../../cmn_lib/src/chip/reg/khan.chip
 * $$ASIC Name:  khan
 * $$Regs Rev:   Chip Spec 1.32
 * $$Date :      Thu Nov 08 02:20:54 2001

 *
 */



// [VGASEQIND] : Indirect Registers

#define ixSEQ02                                    0x0002
#define ixSEQ04                                    0x0004
#define ixSEQ00                                    0x0000
#define ixSEQ01                                    0x0001
#define ixSEQ03                                    0x0003

// [VGACRTIND] : Indirect Registers

#define ixCRT1E                                    0x001E
#define ixCRT1F                                    0x001F
#define ixCRT22                                    0x0022
#define ixCRT1E_S                                  0x005E
#define ixCRT1F_S                                  0x005F
#define ixCRT22_S                                  0x0062
#define ixCRT14                                    0x0014
#define ixCRT17                                    0x0017
#define ixCRT14_S                                  0x0054
#define ixCRT17_S                                  0x0057
#define ixCRT00                                    0x0000
#define ixCRT01                                    0x0001
#define ixCRT02                                    0x0002
#define ixCRT03                                    0x0003
#define ixCRT04                                    0x0004
#define ixCRT05                                    0x0005
#define ixCRT06                                    0x0006
#define ixCRT07                                    0x0007
#define ixCRT08                                    0x0008
#define ixCRT09                                    0x0009
#define ixCRT0A                                    0x000A
#define ixCRT0B                                    0x000B
#define ixCRT0C                                    0x000C
#define ixCRT0D                                    0x000D
#define ixCRT0E                                    0x000E
#define ixCRT0F                                    0x000F
#define ixCRT10                                    0x0010
#define ixCRT11                                    0x0011
#define ixCRT12                                    0x0012
#define ixCRT13                                    0x0013
#define ixCRT15                                    0x0015
#define ixCRT16                                    0x0016
#define ixCRT18                                    0x0018
#define ixCRT00_S                                  0x0040
#define ixCRT01_S                                  0x0041
#define ixCRT02_S                                  0x0042
#define ixCRT03_S                                  0x0043
#define ixCRT04_S                                  0x0044
#define ixCRT05_S                                  0x0045
#define ixCRT06_S                                  0x0046
#define ixCRT07_S                                  0x0047
#define ixCRT08_S                                  0x0048
#define ixCRT09_S                                  0x0049
#define ixCRT0A_S                                  0x004A
#define ixCRT0B_S                                  0x004B
#define ixCRT0C_S                                  0x004C
#define ixCRT0D_S                                  0x004D
#define ixCRT0E_S                                  0x004E
#define ixCRT0F_S                                  0x004F
#define ixCRT10_S                                  0x0050
#define ixCRT11_S                                  0x0051
#define ixCRT12_S                                  0x0052
#define ixCRT13_S                                  0x0053
#define ixCRT15_S                                  0x0055
#define ixCRT16_S                                  0x0056
#define ixCRT18_S                                  0x0058

// [VGAGRPHIND] : Indirect Registers

#define ixGRA00                                    0x0000
#define ixGRA01                                    0x0001
#define ixGRA02                                    0x0002
#define ixGRA03                                    0x0003
#define ixGRA04                                    0x0004
#define ixGRA06                                    0x0006
#define ixGRA07                                    0x0007
#define ixGRA08                                    0x0008
#define ixGRA05                                    0x0005

// [VGAATTRIND] : Indirect Registers

#define ixATTR00                                   0x0000
#define ixATTR01                                   0x0001
#define ixATTR02                                   0x0002
#define ixATTR03                                   0x0003
#define ixATTR04                                   0x0004
#define ixATTR05                                   0x0005
#define ixATTR06                                   0x0006
#define ixATTR07                                   0x0007
#define ixATTR08                                   0x0008
#define ixATTR09                                   0x0009
#define ixATTR0A                                   0x000A
#define ixATTR0B                                   0x000B
#define ixATTR0C                                   0x000C
#define ixATTR0D                                   0x000D
#define ixATTR0E                                   0x000E
#define ixATTR0F                                   0x000F
#define ixATTR10                                   0x0010
#define ixATTR11                                   0x0011
#define ixATTR12                                   0x0012
#define ixATTR13                                   0x0013
#define ixATTR14                                   0x0014

// [CLKIND] : Indirect Registers

#define ixVCLK_ECP_CNTL                            0x0008
#define ixBYTE_CLK_AUX_CNTL                        0x0026
#define ixDISP_TEST_MACRO_RW_WRITE                 0x001A
#define ixDISP_TEST_MACRO_RW_READ                  0x001B
#define ixDISP_TEST_MACRO_RW_DATA                  0x001C
#define ixDISP_TEST_MACRO_RW_CNTL                  0x001D
#define ixPIXCLKS_CNTL                             0x002D
#define ixPPLL_DIV_0                               0x0004
#define ixPPLL_DIV_1                               0x0005
#define ixPPLL_DIV_2                               0x0006
#define ixPPLL_DIV_3                               0x0007
#define ixHTOTAL_CNTL                              0x0009
#define ixPLL_TEST_CNTL                            0x0013
#define ixP2PLL_DIV_0                              0x002C
#define ixHTOTAL2_CNTL                             0x002E
#define ixCLK_PIN_CNTL                             0x0001
#define ixPPLL_CNTL                                0x0002
#define ixPPLL_REF_DIV                             0x0003
#define ixSPLL_CNTL                                0x000C
#define ixSPLL_AUX_CNTL                            0x0024
#define ixSCLK_CNTL2                               0x001E
#define ixSCLK_CNTL                                0x000D
#define ixAGP_PLL_CNTL                             0x000B
#define ixTV_PLL_FINE_CNTL                         0x0020
#define ixTV_PLL_CNTL                              0x0021
#define ixTV_PLL_CNTL1                             0x0022
#define ixTV_DTO_INCREMENTS                        0x0023
#define ixP2PLL_CNTL                               0x002A
#define ixP2PLL_REF_DIV                            0x002B
#define ixSSPLL_CNTL                               0x0030
#define ixSSPLL_REF_DIV                            0x0031
#define ixSSPLL_DIV_0                              0x0032
#define ixSS_INT_CNTL                              0x0033
#define ixSS_TST_CNTL                              0x0034
#define ixSCLK_MORE_CNTL                           0x0035
#define ixCLK_PWRMGT_CNTL                          0x0014
#define ixPLL_PWRMGT_CNTL                          0x0015
#define ixM_SPLL_REF_FB_DIV                        0x000A
#define ixMPLL_CNTL                                0x000E
#define ixMPLL_AUX_CNTL                            0x0025
#define ixMDLL_RDCK                                0x0010
#define ixMCLK_CNTL                                0x0012
#define ixMCLK_MISC                                0x001F
#define ixCG_TEST_MACRO_RW_WRITE                   0x0016
#define ixCG_TEST_MACRO_RW_READ                    0x0017
#define ixCG_TEST_MACRO_RW_DATA                    0x0018
#define ixCG_TEST_MACRO_RW_CNTL                    0x0019

// [MCIND] : Indirect Registers

#define ixMC_IMP_STATUS                            0x002E
#define ixMC_PERF_CNTL                             0x0000
#define ixMC_PERF_CNT0_SEL                         0x0001
#define ixMC_PERF_CNT1_SEL                         0x0002
#define ixMC_PERF_CNT2_SEL                         0x0003
#define ixMC_PERF_CNT3_SEL                         0x0004
#define ixMC_PERF_CNT4_SEL                         0x0005
#define ixMC_PERF_CNT5_SEL                         0x0006
#define ixMC_PERF_CNT6_SEL                         0x0007
#define ixMC_PERF_CNT7_SEL                         0x0008
#define ixMC_PERF_MEMCH_SEL                        0x0009
#define ixMC_PERF_REGION_0_R3                      0x000A
#define ixMC_PERF_REGION_1_R3                      0x000B
#define ixMC_PERF_COUNT_0_R3                       0x000C
#define ixMC_PERF_COUNT_1_R3                       0x000D
#define ixMC_PERF_COUNT_2_R3                       0x000E
#define ixMC_PERF_COUNT_3_R3                       0x000F
#define ixMC_PERF_COUNT_4                          0x0010
#define ixMC_PERF_COUNT_5                          0x0011
#define ixMC_PERF_COUNT_6                          0x0012
#define ixMC_PERF_COUNT_7                          0x0013
#define ixMC_PERF_COUNT_MEMCH_A_R3                 0x0014
#define ixMC_PERF_COUNT_MEMCH_B_R3                 0x0015
#define ixMC_PERF_COUNT_MEMCH_C                    0x0016
#define ixMC_PERF_COUNT_MEMCH_D                    0x0017
#define ixMC_IMP_CNTL_R3                           0x0018
#define ixMC_CHP_IO_CNTL_A0_R3                     0x0019
#define ixMC_CHP_IO_CNTL_A1_R3                     0x001A
#define ixMC_CHP_IO_CNTL_B0_R3                     0x001B
#define ixMC_CHP_IO_CNTL_B1_R3                     0x001C
#define ixMC_CHP_IO_CNTL_C0                        0x001D
#define ixMC_CHP_IO_CNTL_C1                        0x001E
#define ixMC_CHP_IO_CNTL_D0                        0x001F
#define ixMC_CHP_IO_CNTL_D1                        0x0020
#define ixMC_IMP_CNTL_0_R3                         0x0021
#define ixMC_ELPIDA_CNTL                           0x0022
#define ixMC_CHP_IO_OE_CNTL_CD                     0x0023
#define ixMC_READ_CNTL_CD                          0x0024
#define ixMC_INIT_WR_LAT_TIMER                     0x0025
#define ixMC_DEBUG_CNTL                            0x0026
#define ixMC_BIST_CNTL_0                           0x0028
#define ixMC_BIST_CNTL_1                           0x0029
#define ixMC_BIST_CNTL_2                           0x002A
#define ixMC_BIST_CNTL_3                           0x002B
#define ixMC_BIST_CNTL_4                           0x002C
#define ixMC_BIST_CNTL_5                           0x002D
#define ixMC_DLL_CNTL                              0x002F


#ifdef __cplusplus
}
#endif  // __cplusplus

#endif // _khanb_h


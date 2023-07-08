

#if !defined (_RV350F_HEADER_)
#define _RV350F_HEADER_
/*
*
*	Register Spec Release:  Chip Spec 1.30
*
*
*	 (c) 2000 ATI Technologies Inc.  (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*/

/*******************************************************
 * GB Enums
 *******************************************************/


/*******************************************************
 * GA Enums
 *******************************************************/


/*******************************************************
 * SU Enums
 *******************************************************/


/*******************************************************
 * RS Enums
 *******************************************************/


/*******************************************************
 * SC Enums
 *******************************************************/


/*******************************************************
 * TX Enums
 *******************************************************/


/*******************************************************
 * US Enums
 *******************************************************/


/*******************************************************
 * FG Enums
 *******************************************************/


/*******************************************************
 * CB Enums
 *******************************************************/


/*******************************************************
 * ZB Enums
 *******************************************************/


/*******************************************************
 * E2 Enums
 *******************************************************/


/*******************************************************
 * VAP Enums
 *******************************************************/


/*******************************************************
 * MC Enums
 *******************************************************/


/*******************************************************
 * RBBM Enums
 *******************************************************/

/*******************************************************
 * BIF Enums
 *******************************************************/

/*
 * AGP_COMMAND__DATA_RATE
 */

#define AGP_COMMAND__DATA_RATE__v2_1X                      0x00000001
#define AGP_COMMAND__DATA_RATE__v2_2X                      0x00000002
#define AGP_COMMAND__DATA_RATE__v2_4X                      0x00000004

#define AGP_COMMAND__DATA_RATE__v3_4X                      0x00000001
#define AGP_COMMAND__DATA_RATE__v3_8X                      0x00000002


/*******************************************************
 * HDP Enums
 *******************************************************/

/*******************************************************
 * DISPLAY Enums
 *******************************************************/

#define DISP_OUTPUT_CNTL__DISP_DAC_SOURCE__PRIMARYCRTC     0x00000000
#define DISP_OUTPUT_CNTL__DISP_DAC_SOURCE__SECONDARYCRTC   0x00000001
#define DISP_OUTPUT_CNTL__DISP_DAC_SOURCE__RMX             0x00000002
#define DISP_OUTPUT_CNTL__DISP_DAC_SOURCE__YPbPr           0x00000003

#define DISP_OUTPUT_CNTL__DISP_TVDAC_SOURCE__PRIMARYCRTC   0x00000000
#define DISP_OUTPUT_CNTL__DISP_TVDAC_SOURCE__SECONDARYCRTC 0x00000001
#define DISP_OUTPUT_CNTL__DISP_TVDAC_SOURCE__RMX           0x00000002
#define DISP_OUTPUT_CNTL__DISP_TVDAC_SOURCE__YPbPr         0x00000003

#define DISP_OUTPUT_CNTL__DISP_TRANS_SOURCE__PRIMARYCRTC   0x00000000
#define DISP_OUTPUT_CNTL__DISP_TRANS_SOURCE__SECONDARYCRTC 0x00000001
#define DISP_OUTPUT_CNTL__DISP_TRANS_SOURCE__RMX           0x00000002

#define LVDS_PLL_CNTL__LVDS_SRC_SEL__SECONDARYCRTC_R3      0x00040000

#define TV_DAC_CNTL__STD__PAL                              0x00000000
#define TV_DAC_CNTL__STD__NTSC                             0x00000001
#define TV_DAC_CNTL__STD__PS2                              0x00000002
#define TV_DAC_CNTL__STD__RS343                            0x00000003


/*******************************************************
 * CP Enums
 *******************************************************/

/*******************************************************
 * VIP Enums
 *******************************************************/

#define I2C_CNTL_0__I2C_PRESCALE_A_MASK                   0x00ff0000
#define I2C_CNTL_0__I2C_PRESCALE_B_MASK                   0xff000000
#define I2C_CNTL_0__I2C_PRESCALE_A__SHIFT                 0x00000010
#define I2C_CNTL_0__I2C_PRESCALE_B__SHIFT                 0x00000018


/*******************************************************
 * CG Enums
 *******************************************************/

/*
 * CLK_PWRMGT_CNTL__ACTIVE_HILO_LAT enum
 */

#define CLK_PWRMGT_CNTL__ACTIVE_HILO_LAT__5CLKS            0x00000000
#define CLK_PWRMGT_CNTL__ACTIVE_HILO_LAT__12CLKS           0x00000001
#define CLK_PWRMGT_CNTL__ACTIVE_HILO_LAT__20CLKS           0x00000002
#define CLK_PWRMGT_CNTL__ACTIVE_HILO_LAT__32CLKS           0x00000003

/*
 * CLK_PWRMGT_CNTL__DYN_STOP_MODE enum
 */

#define CLK_PWRMGT_CNTL__DYN_STOP_MODE__10CLKS             0x00000000
#define CLK_PWRMGT_CNTL__DYN_STOP_MODE__20CLKS             0x00000001
#define CLK_PWRMGT_CNTL__DYN_STOP_MODE__140CLKS            0x00000007


/*******************************************************
 * CGM Enums
 *******************************************************/

/*******************************************************
 * IDCT Enums
 *******************************************************/

/*******************************************************
 * TVOUT Enums
 *******************************************************/

#endif


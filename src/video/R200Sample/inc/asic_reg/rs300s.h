

#if !defined (_superman_SHIFT_HEADER)
#define _superman_SHIFT_HEADER
/*
*	superman_shift.h
*
*	Register Spec Release:  Chip Spec 1.21
*
*
*	 (c) 2000 ATI Technologies Inc.  (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
*/

// GENENB
#define	GENENB__BLK_IO_BASE__SHIFT                         0x00000000

// MM_INDEX
#define	MM_INDEX__MM_ADDR__SHIFT                           0x00000000
#define	MM_INDEX__MM_APER__SHIFT                           0x0000001f

// MM_DATA
#define	MM_DATA__MM_DATA__SHIFT                            0x00000000

// BUS_CNTL
#define	BUS_CNTL__BUS_DBL_RESYNC__SHIFT                    0x00000000
#define	BUS_CNTL__BUS_MSTR_RESET__SHIFT                    0x00000001
#define	BUS_CNTL__BUS_FLUSH_BUF__SHIFT                     0x00000002
#define	BUS_CNTL__BUS_STOP_REQ_DIS__SHIFT                  0x00000003
#define	BUS_CNTL__BUS_READ_COMBINE_EN__SHIFT               0x00000004
#define	BUS_CNTL__BUS_WRT_COMBINE_EN__SHIFT                0x00000005
#define	BUS_CNTL__BUS_MASTER_DIS__SHIFT                    0x00000006
#define	BUS_CNTL__BIOS_ROM_WRT_EN__SHIFT                   0x00000007
#define	BUS_CNTL__BUS_PREFETCH_MODE__SHIFT                 0x00000008
#define	BUS_CNTL__BUS_VGA_PREFETCH_EN__SHIFT               0x0000000a
#define	BUS_CNTL__BUS_SGL_READ_DISABLE__SHIFT              0x0000000b
#define	BUS_CNTL__BIOS_DIS_ROM__SHIFT                      0x0000000c
#define	BUS_CNTL__BUS_PCI_READ_RETRY_EN__SHIFT             0x0000000d
#define	BUS_CNTL__BUS_AGP_AD_STEPPING_EN__SHIFT            0x0000000e
#define	BUS_CNTL__BUS_PCI_WRT_RETRY_EN__SHIFT              0x0000000f
#define	BUS_CNTL__BUS_RETRY_WS__SHIFT                      0x00000010
#define	BUS_CNTL__BUS_MSTR_RD_MULT__SHIFT                  0x00000014
#define	BUS_CNTL__BUS_MSTR_RD_LINE__SHIFT                  0x00000015
#define	BUS_CNTL__BUS_SUSPEND__SHIFT                       0x00000016
#define	BUS_CNTL__LAT_16X__SHIFT                           0x00000017
#define	BUS_CNTL__BUS_RD_DISCARD_EN__SHIFT                 0x00000018
#define	BUS_CNTL__ENFRCWRDY__SHIFT                         0x00000019
#define	BUS_CNTL__BUS_MSTR_WS__SHIFT                       0x0000001a
#define	BUS_CNTL__BUS_PARKING_DIS__SHIFT                   0x0000001b
#define	BUS_CNTL__BUS_MSTR_DISCONNECT_EN__SHIFT            0x0000001c
#define	BUS_CNTL__SERR_EN__SHIFT                           0x0000001d
#define	BUS_CNTL__BUS_READ_BURST__SHIFT                    0x0000001e
#define	BUS_CNTL__BUS_RDY_READ_DLY__SHIFT                  0x0000001f

// HI_STAT
#define	HI_STAT__AGP_BUSY__SHIFT                           0x00000003

// BUS_CNTL1
#define	BUS_CNTL1__PMI_IO_DISABLE__SHIFT                   0x00000000
#define	BUS_CNTL1__PMI_MEM_DISABLE__SHIFT                  0x00000001
#define	BUS_CNTL1__PMI_BM_DISABLE__SHIFT                   0x00000002
#define	BUS_CNTL1__PMI_INT_DISABLE__SHIFT                  0x00000003
#define	BUS_CNTL1__BUS2_WBF_DURING_REG_WRT_EN__SHIFT       0x00000004
#define	BUS_CNTL1__BUS2_IMMEDIATE_PMI_DISABLE__SHIFT       0x00000005
#define	BUS_CNTL1__BUS2_VGA_REG_COHERENCY_DIS__SHIFT       0x00000008
#define	BUS_CNTL1__BUS2_VGA_MEM_COHERENCY_DIS__SHIFT       0x00000009
#define	BUS_CNTL1__BUS2_HDP_REG_COHERENCY_DIS__SHIFT       0x0000000a
#define	BUS_CNTL1__BUS2_GUI_INITIATOR_COHERENCY_DIS__SHIFT 0x0000000b
#define	BUS_CNTL1__BUS2_VGA_FW_COHERENCY_DIS__SHIFT        0x0000000c
#define	BUS_CNTL1__BUS2_ACCEL_FW_COHERENCY_DIS__SHIFT      0x0000000d
#define	BUS_CNTL1__BUS2_RD_PANIC_VAL__SHIFT                0x00000010
#define	BUS_CNTL1__BUS2_WRT_PANIC_VAL__SHIFT               0x00000014
#define	BUS_CNTL1__MOBILE_PLATFORM_SEL__SHIFT              0x0000001a
#define	BUS_CNTL1__SEND_SBA_LATENCY__SHIFT                 0x0000001c
#define	BUS_CNTL1__AGPCLK_VALID__SHIFT                     0x0000001f

// CONFIG_CNTL
#define	CONFIG_CNTL__APER_REG_ENDIAN__SHIFT                0x00000004
#define	CONFIG_CNTL__CFG_VGA_RAM_EN__SHIFT                 0x00000008
#define	CONFIG_CNTL__CFG_VGA_IO_DIS__SHIFT                 0x00000009
#define	CONFIG_CNTL__CFG_ATI_REV_ID__SHIFT                 0x00000010

// CONFIG_MEMSIZE
#define	CONFIG_MEMSIZE__CONFIG_MEMSIZE_R2__SHIFT           0x00000014

// CONFIG_APER_0_BASE
#define	CONFIG_APER_0_BASE__APER_0_BASE__SHIFT             0x00000019

// CONFIG_APER_1_BASE
#define	CONFIG_APER_1_BASE__APER_1_BASE__SHIFT             0x00000018

// CONFIG_APER_SIZE
#define	CONFIG_APER_SIZE__APER_SIZE__SHIFT                 0x00000018

// CONFIG_REG_1_BASE
#define	CONFIG_REG_1_BASE__REG_APER_1_SELECT__SHIFT        0x0000000f
#define	CONFIG_REG_1_BASE__REG_1_BASE__SHIFT               0x00000010

// CONFIG_REG_APER_SIZE
#define	CONFIG_REG_APER_SIZE__REG_APER_SIZE__SHIFT         0x00000000

// FW_CNTL
#define	FW_CNTL__WBF_WM_MAX__SHIFT                         0x00000000
#define	FW_CNTL__WBF_WM_MIN__SHIFT                         0x00000004
#define	FW_CNTL__DISCONNECT_W_DATA_STOPTRDY_MIN__SHIFT     0x00000008
#define	FW_CNTL__DISCONNECT_WO_DATA_STOPTRDY_MIN__SHIFT    0x0000000c
#define	FW_CNTL__HOLD_FW_FIFO__SHIFT                       0x00000010
#define	FW_CNTL__FORCE_FW_WBF__SHIFT                       0x00000011
#define	FW_CNTL__DIS_FW_WBF__SHIFT                         0x00000012
#define	FW_CNTL__DISCONNECT_MODE__SHIFT                    0x00000013
#define	FW_CNTL__DIS_WBF_WAIT_FOR_FRAME__SHIFT             0x00000015
#define	FW_CNTL__EN_TRDY_WAIT_FOR_FIFOAVL__SHIFT           0x00000016
#define	FW_CNTL__TRDY_WS_COUNT__SHIFT                      0x00000017
#define	FW_CNTL__DIS_FW_ROTATION__SHIFT                    0x0000001b
#define	FW_CNTL__FORCE_TRDY_1WS__SHIFT                     0x0000001c
#define	FW_CNTL__IGNORE_STRAP_FW_DIS__SHIFT                0x0000001d
#define	FW_CNTL__FW_MISC__SHIFT                            0x0000001e

// FW_STATUS
#define	FW_STATUS__FW_IDLE__SHIFT                          0x00000000
#define	FW_STATUS__STAT_FW_CLEAN__SHIFT                    0x00000001
#define	FW_STATUS__FW_WAVL__SHIFT                          0x0000001b

// AGP_CNTL
#define	AGP_CNTL__MAX_IDLE_CLK__SHIFT                      0x00000000
#define	AGP_CNTL__HOLD_RD_FIFO__SHIFT                      0x00000008
#define	AGP_CNTL__HOLD_RQ_FIFO__SHIFT                      0x00000009
#define	AGP_CNTL__EN_2X_STBB__SHIFT                        0x0000000a
#define	AGP_CNTL__FORCE_FULL_SBA__SHIFT                    0x0000000b
#define	AGP_CNTL__SBA_DIS__SHIFT                           0x0000000c
#define	AGP_CNTL__AGP_REV_ID__SHIFT                        0x0000000d
#define	AGP_CNTL__REG_CRIPPLE_AGP4X__SHIFT                 0x0000000e
#define	AGP_CNTL__REG_CRIPPLE_AGP2X4X__SHIFT               0x0000000f
#define	AGP_CNTL__FORCE_INT_VREF__SHIFT                    0x00000010
#define	AGP_CNTL__PENDING_SLOTS_VAL__SHIFT                 0x00000011
#define	AGP_CNTL__PENDING_SLOTS_SEL__SHIFT                 0x00000013
#define	AGP_CNTL__EN_EXTENDED_AD_STB_2X__SHIFT             0x00000014
#define	AGP_CNTL__DIS_QUEUED_GNT_FIX__SHIFT                0x00000015
#define	AGP_CNTL__EN_RDATA2X4X_MULTIRESET__SHIFT           0x00000016
#define	AGP_CNTL__EN_RBFCALM__SHIFT                        0x00000017
#define	AGP_CNTL__FORCE_EXT_VREF__SHIFT                    0x00000018
#define	AGP_CNTL__DIS_RBF__SHIFT                           0x00000019
#define	AGP_CNTL__DELAY_FIRST_SBA_EN__SHIFT                0x0000001a
#define	AGP_CNTL__DELAY_FIRST_SBA_VAL__SHIFT               0x0000001b
#define	AGP_CNTL__AGP_MISC_R2__SHIFT                       0x0000001e

// BM_STATUS
#define	BM_STATUS__BUS_MASTER_STATUS__SHIFT                0x00000000

// AIC_CTRL
#define	AIC_CTRL__TRANSLATE_EN__SHIFT                      0x00000000
#define	AIC_CTRL__DIS_OUT_OF_PCI_GART_ACCESS__SHIFT        0x00000001
#define	AIC_CTRL__HW_1_DEBUG__SHIFT                        0x00000002
#define	AIC_CTRL__HW_2_DEBUG__SHIFT                        0x00000003
#define	AIC_CTRL__HW_3_DEBUG__SHIFT                        0x00000004
#define	AIC_CTRL__HW_4_DEBUG__SHIFT                        0x00000005
#define	AIC_CTRL__HW_5_DEBUG__SHIFT                        0x00000006
#define	AIC_CTRL__HW_6_DEBUG__SHIFT                        0x00000007
#define	AIC_CTRL__HW_7_DEBUG__SHIFT                        0x00000008
#define	AIC_CTRL__HW_8_DEBUG__SHIFT                        0x00000009
#define	AIC_CTRL__HW_9_DEBUG__SHIFT                        0x0000000a
#define	AIC_CTRL__HW_A_DEBUG__SHIFT                        0x0000000b
#define	AIC_CTRL__HW_B_DEBUG__SHIFT                        0x0000000c
#define	AIC_CTRL__HW_C_DEBUG__SHIFT                        0x0000000d
#define	AIC_CTRL__HW_D_DEBUG__SHIFT                        0x0000000e
#define	AIC_CTRL__HW_E_DEBUG__SHIFT                        0x0000000f
#define	AIC_CTRL__HW_F_DEBUG__SHIFT                        0x00000010
#define	AIC_CTRL__HW_10_DEBUG__SHIFT                       0x00000011
#define	AIC_CTRL__HW_11_DEBUG__SHIFT                       0x00000012
#define	AIC_CTRL__HW_12_DEBUG__SHIFT                       0x00000013
#define	AIC_CTRL__HW_13_DEBUG__SHIFT                       0x00000014
#define	AIC_CTRL__HW_14_DEBUG__SHIFT                       0x00000015
#define	AIC_CTRL__HW_15_DEBUG__SHIFT                       0x00000016
#define	AIC_CTRL__HW_16_DEBUG__SHIFT                       0x00000017
#define	AIC_CTRL__HW_17_DEBUG__SHIFT                       0x00000018
#define	AIC_CTRL__HW_18_DEBUG__SHIFT                       0x00000019
#define	AIC_CTRL__HW_19_DEBUG__SHIFT                       0x0000001a
#define	AIC_CTRL__HW_1A_DEBUG__SHIFT                       0x0000001b
#define	AIC_CTRL__HW_1B_DEBUG__SHIFT                       0x0000001c
#define	AIC_CTRL__HW_1C_DEBUG__SHIFT                       0x0000001d
#define	AIC_CTRL__HW_1D_DEBUG__SHIFT                       0x0000001e
#define	AIC_CTRL__HW_1E_DEBUG__SHIFT                       0x0000001f

// AIC_STAT
#define	AIC_STAT__AIC_TLB_VLD__SHIFT                       0x00000000
#define	AIC_STAT__AIC_STAT1__SHIFT                         0x00000001
#define	AIC_STAT__AIC_STAT0__SHIFT                         0x00000002

// AIC_PT_BASE
#define	AIC_PT_BASE__AIC_PT_BASE__SHIFT                    0x0000000c

// AIC_LO_ADDR
#define	AIC_LO_ADDR__AIC_LO_ADDR__SHIFT                    0x0000000c

// AIC_HI_ADDR
#define	AIC_HI_ADDR__AIC_HI_ADDR__SHIFT                    0x0000000c

// AIC_TLB_ADDR
#define	AIC_TLB_ADDR__AIC_TLB_ADDR__SHIFT                  0x0000000c

// AIC_TLB_DATA
#define	AIC_TLB_DATA__AIC_TLB_DATA__SHIFT                  0x0000000c

// VENDOR_ID
#define	VENDOR_ID__VENDOR_ID__SHIFT                        0x00000000

// DEVICE_ID
#define	DEVICE_ID__DEVICE_ID__SHIFT                        0x00000000

// COMMAND
#define	COMMAND__IO_ACCESS_EN__SHIFT                       0x00000000
#define	COMMAND__MEM_ACCESS_EN__SHIFT                      0x00000001
#define	COMMAND__BUS_MASTER_EN__SHIFT                      0x00000002
#define	COMMAND__SPECIAL_CYCLE_EN__SHIFT                   0x00000003
#define	COMMAND__MEM_WRITE_INVALIDATE_EN__SHIFT            0x00000004
#define	COMMAND__PAL_SNOOP_EN__SHIFT                       0x00000005
#define	COMMAND__PARITY_ERROR_EN__SHIFT                    0x00000006
#define	COMMAND__SERR_EN__SHIFT                            0x00000008
#define	COMMAND__FAST_B2B_EN__SHIFT                        0x00000009
#define	COMMAND__INT_DISABLE__SHIFT                        0x0000000a

// STATUS
#define	STATUS__INT_STATUS__SHIFT                          0x00000003
#define	STATUS__CAP_LIST__SHIFT                            0x00000004
#define	STATUS__PCI_66_EN__SHIFT                           0x00000005
#define	STATUS__UDF_EN__SHIFT                              0x00000006
#define	STATUS__FAST_BACK_CAPABLE__SHIFT                   0x00000007
#define	STATUS__DEVSEL_TIMING__SHIFT                       0x00000009
#define	STATUS__SIGNAL_TARGET_ABORT__SHIFT                 0x0000000b
#define	STATUS__RECEIVED_TARGET_ABORT__SHIFT               0x0000000c
#define	STATUS__RECEIVED_MASTER_ABORT__SHIFT               0x0000000d
#define	STATUS__SIGNALED_SYSTEM_ERROR__SHIFT               0x0000000e
#define	STATUS__PARITY_ERROR_DETECTED__SHIFT               0x0000000f

// REVISION_ID
#define	REVISION_ID__MINOR_REV_ID__SHIFT                   0x00000000
#define	REVISION_ID__MAJOR_REV_ID__SHIFT                   0x00000004

// REGPROG_INF
#define	REGPROG_INF__REG_LEVEL_PROG_INF__SHIFT             0x00000000

// SUB_CLASS
#define	SUB_CLASS__SUB_CLASS_INF__SHIFT                    0x00000007

// BASE_CODE
#define	BASE_CODE__BASE_CLASS_CODE__SHIFT                  0x00000000

// CACHE_LINE
#define	CACHE_LINE__CACHE_LINE_SIZE__SHIFT                 0x00000000

// LATENCY
#define	LATENCY__LATENCY_TIMER__SHIFT                      0x00000000

// HEADER
#define	HEADER__HEADER_TYPE__SHIFT                         0x00000000
#define	HEADER__DEVICE_TYPE__SHIFT                         0x00000007

// BIST
#define	BIST__BIST_COMP__SHIFT                             0x00000000
#define	BIST__BIST_STRT__SHIFT                             0x00000006
#define	BIST__BIST_CAP__SHIFT                              0x00000007

// MEM_BASE
#define	MEM_BASE__PREFETCH_EN__SHIFT                       0x00000003
#define	MEM_BASE__MEM_BASE__SHIFT                          0x00000019

// IO_BASE
#define	IO_BASE__BLOCK_IO_BIT__SHIFT                       0x00000000
#define	IO_BASE__IO_BASE__SHIFT                            0x00000008

// REG_BASE
#define	REG_BASE__REG_BASE__SHIFT                          0x00000010

// ADAPTER_ID
#define	ADAPTER_ID__SUBSYSTEM_VENDOR_ID__SHIFT             0x00000000
#define	ADAPTER_ID__SUBSYSTEM_ID__SHIFT                    0x00000010

// BIOS_ROM
#define	BIOS_ROM__BIOS_ROM_EN__SHIFT                       0x00000000
#define	BIOS_ROM__BIOS_BASE_ADDR__SHIFT                    0x00000011

// CAPABILITIES_PTR
#define	CAPABILITIES_PTR__CAP_PTR__SHIFT                   0x00000000

// INTERRUPT_LINE
#define	INTERRUPT_LINE__INTERRUPT_LINE__SHIFT              0x00000000

// INTERRUPT_PIN
#define	INTERRUPT_PIN__INTERRUPT_PIN__SHIFT                0x00000000

// MIN_GRANT
#define	MIN_GRANT__MIN_GNT__SHIFT                          0x00000000

// MAX_LATENCY
#define	MAX_LATENCY__MAX_LAT__SHIFT                        0x00000000

// ADAPTER_ID_W
#define	ADAPTER_ID_W__SUBSYSTEM_VENDOR_ID__SHIFT           0x00000000
#define	ADAPTER_ID_W__SUBSYSTEM_ID__SHIFT                  0x00000010

// PMI_CAP_ID
#define	PMI_CAP_ID__PMI_CAP_ID__SHIFT                      0x00000000

// PMI_NXT_CAP_PTR
#define	PMI_NXT_CAP_PTR__PMI_NXT_CAP_PTR__SHIFT            0x00000000

// PMI_PMC_REG
#define	PMI_PMC_REG__PMI_VERSION__SHIFT                    0x00000000
#define	PMI_PMC_REG__PMI_PME_CLOCK__SHIFT                  0x00000003
#define	PMI_PMC_REG__PMI_DEV_SPECIFIC_INIT__SHIFT          0x00000005
#define	PMI_PMC_REG__PMI_D1_SUPPORT__SHIFT                 0x00000009
#define	PMI_PMC_REG__PMI_D2_SUPPORT__SHIFT                 0x0000000a
#define	PMI_PMC_REG__PMI_PME_SUPPORT__SHIFT                0x0000000b

// PM_STATUS
#define	PM_STATUS__PMI_POWER_STATE__SHIFT                  0x00000000
#define	PM_STATUS__PMI_PME_EN__SHIFT                       0x00000008
#define	PM_STATUS__PMI_DATA_SELECT__SHIFT                  0x00000009
#define	PM_STATUS__PMI_DATA_SCALE__SHIFT                   0x0000000d
#define	PM_STATUS__PMI_PME_STATUS__SHIFT                   0x0000000f

// PMI_DATA
#define	PMI_DATA__PMI_DATA__SHIFT                          0x00000000

// AGP_CAP_ID
#define	AGP_CAP_ID__CAP_ID__SHIFT                          0x00000000
#define	AGP_CAP_ID__NEXT_PTR__SHIFT                        0x00000008
#define	AGP_CAP_ID__AGP_MINOR__SHIFT                       0x00000010
#define	AGP_CAP_ID__AGP_MAJOR__SHIFT                       0x00000014

// AGP_STATUS
#define	AGP_STATUS__RATE1X_4X__SHIFT                       0x00000000
#define	AGP_STATUS__RATE2X_8X__SHIFT                       0x00000001
#define	AGP_STATUS__RATE4X__SHIFT                          0x00000002
#define	AGP_STATUS__MODE_AGP30__SHIFT                      0x00000003
#define	AGP_STATUS__FW__SHIFT                              0x00000004
#define	AGP_STATUS__MODE_4G__SHIFT                         0x00000005
#define	AGP_STATUS__SBA__SHIFT                             0x00000009
#define	AGP_STATUS__CAL_CYCLE__SHIFT                       0x0000000a
#define	AGP_STATUS__ISOCH_SUPPORT__SHIFT                   0x00000011
#define	AGP_STATUS__RQ__SHIFT                              0x00000018

// AGP_COMMAND
#define	AGP_COMMAND__DATA_RATE__SHIFT                      0x00000000
#define	AGP_COMMAND__FW_EN__SHIFT                          0x00000004
#define	AGP_COMMAND__MODE_4G_EN__SHIFT                     0x00000005
#define	AGP_COMMAND__AGP_EN__SHIFT                         0x00000008
#define	AGP_COMMAND__SBA_EN__SHIFT                         0x00000009
#define	AGP_COMMAND__PARQSZ__SHIFT                         0x0000000d
#define	AGP_COMMAND__RQ_DEPTH__SHIFT                       0x00000018

// F1_VENDOR_ID
#define	F1_VENDOR_ID__F1_VENDOR_ID__SHIFT                  0x00000000

// F1_DEVICE_ID
#define	F1_DEVICE_ID__F1_DEVICE_ID__SHIFT                  0x00000000

// F1_COMMAND
#define	F1_COMMAND__F1_IO_ACCESS_EN__SHIFT                 0x00000000
#define	F1_COMMAND__F1_MEM_ACCESS_EN__SHIFT                0x00000001
#define	F1_COMMAND__F1_BUS_MASTER_EN__SHIFT                0x00000002
#define	F1_COMMAND__F1_FAST_B2B_EN__SHIFT                  0x00000009

// F1_STATUS
#define	F1_STATUS__F1_CAP_LIST__SHIFT                      0x00000004
#define	F1_STATUS__F1_PCI_66_EN__SHIFT                     0x00000005
#define	F1_STATUS__F1_UDF_EN__SHIFT                        0x00000006
#define	F1_STATUS__F1_FAST_BACK_CAPABLE__SHIFT             0x00000007
#define	F1_STATUS__F1_DEVSEL_TIMING__SHIFT                 0x00000009
#define	F1_STATUS__F1_SIGNAL_TARGET_ABORT__SHIFT           0x0000000b
#define	F1_STATUS__F1_RECEIVED_TARGET_ABORT__SHIFT         0x0000000c
#define	F1_STATUS__F1_RECEIVED_MASTER_ABORT__SHIFT         0x0000000d
#define	F1_STATUS__F1_PARITY_ERROR_DETECTED__SHIFT         0x0000000f

// F1_REVISION_ID
#define	F1_REVISION_ID__F1_MINOR_REV_ID__SHIFT             0x00000000
#define	F1_REVISION_ID__F1_MAJOR_REV_ID__SHIFT             0x00000004

// F1_REGPROG_INF
#define	F1_REGPROG_INF__F1_REG_LEVEL_PROG_INF__SHIFT       0x00000000

// F1_SUB_CLASS
#define	F1_SUB_CLASS__F1_SUB_CLASS_INF__SHIFT              0x00000007

// F1_BASE_CODE
#define	F1_BASE_CODE__F1_BASE_CLASS_CODE__SHIFT            0x00000000

// F1_CACHE_LINE
#define	F1_CACHE_LINE__F1_CACHE_LINE_SIZE__SHIFT           0x00000000

// F1_LATENCY
#define	F1_LATENCY__F1_LATENCY_TIMER__SHIFT                0x00000000

// F1_HEADER
#define	F1_HEADER__F1_HEADER_TYPE__SHIFT                   0x00000000
#define	F1_HEADER__F1_DEVICE_TYPE__SHIFT                   0x00000007

// F1_BIST
#define	F1_BIST__F1_BIST_COMP__SHIFT                       0x00000000
#define	F1_BIST__F1_BIST_STRT__SHIFT                       0x00000006
#define	F1_BIST__F1_BIST_CAP__SHIFT                        0x00000007

// F1_MEM_BASE
#define	F1_MEM_BASE__F1_PREFETCH_EN__SHIFT                 0x00000003
#define	F1_MEM_BASE__F1_MEM_BASE__SHIFT                    0x00000019

// F1_REG_BASE
#define	F1_REG_BASE__F1_REG_BASE__SHIFT                    0x00000010

// F1_ADAPTER_ID
#define	F1_ADAPTER_ID__F1_SUBSYSTEM_VENDOR_ID__SHIFT       0x00000000
#define	F1_ADAPTER_ID__F1_SUBSYSTEM_ID__SHIFT              0x00000010

// F1_CAPABILITIES_PTR
#define	F1_CAPABILITIES_PTR__F1_CAP_PTR__SHIFT             0x00000000

// F1_INTERRUPT_LINE
#define	F1_INTERRUPT_LINE__F1_INTERRUPT_LINE__SHIFT        0x00000000

// F1_INTERRUPT_PIN
#define	F1_INTERRUPT_PIN__F1_INTERRUPT_PIN__SHIFT          0x00000000

// F1_MIN_GRANT
#define	F1_MIN_GRANT__F1_MIN_GNT__SHIFT                    0x00000000

// F1_MAX_LATENCY
#define	F1_MAX_LATENCY__F1_MAX_LAT__SHIFT                  0x00000000

// F1_PMI_CAP_ID
#define	F1_PMI_CAP_ID__F1_PMI_CAP_ID__SHIFT                0x00000000

// F1_PMI_NXT_CAP_PTR
#define	F1_PMI_NXT_CAP_PTR__F1_PMI_NXT_CAP_PTR__SHIFT      0x00000000

// F1_PMI_PMC_REG
#define	F1_PMI_PMC_REG__F1_PMI_VERSION__SHIFT              0x00000000
#define	F1_PMI_PMC_REG__F1_PMI_PME_CLOCK__SHIFT            0x00000003
#define	F1_PMI_PMC_REG__F1_PMI_DEV_SPECIFIC_INIT__SHIFT    0x00000005
#define	F1_PMI_PMC_REG__F1_PMI_D1_SUPPORT__SHIFT           0x00000009
#define	F1_PMI_PMC_REG__F1_PMI_D2_SUPPORT__SHIFT           0x0000000a
#define	F1_PMI_PMC_REG__F1_PMI_PME_SUPPORT__SHIFT          0x0000000b

// F1_PM_STATUS
#define	F1_PM_STATUS__F1_PMI_POWER_STATE__SHIFT            0x00000000
#define	F1_PM_STATUS__F1_PMI_PME_EN__SHIFT                 0x00000008
#define	F1_PM_STATUS__F1_PMI_DATA_SELECT__SHIFT            0x00000009
#define	F1_PM_STATUS__F1_PMI_DATA_SCALE__SHIFT             0x0000000d
#define	F1_PM_STATUS__F1_PMI_PME_STATUS__SHIFT             0x0000000f

// F1_PMI_DATA
#define	F1_PMI_DATA__F1_PMI_DATA__SHIFT                    0x00000000

// F1_AGP_CAP_ID
#define	F1_AGP_CAP_ID__F1_CAP_ID__SHIFT                    0x00000000
#define	F1_AGP_CAP_ID__F1_NEXT_PTR__SHIFT                  0x00000008
#define	F1_AGP_CAP_ID__F1_AGP_MINOR__SHIFT                 0x00000010
#define	F1_AGP_CAP_ID__F1_AGP_MAJOR__SHIFT                 0x00000014

// F1_AGP_STATUS
#define	F1_AGP_STATUS__F1_RATE1X_4X__SHIFT                 0x00000000
#define	F1_AGP_STATUS__F1_RATE2X_8X__SHIFT                 0x00000001
#define	F1_AGP_STATUS__F1_RATE4X__SHIFT                    0x00000002
#define	F1_AGP_STATUS__F1_MODE_AGP30__SHIFT                0x00000003
#define	F1_AGP_STATUS__F1_FW__SHIFT                        0x00000004
#define	F1_AGP_STATUS__F1_MODE_4G__SHIFT                   0x00000005
#define	F1_AGP_STATUS__F1_SBA__SHIFT                       0x00000009
#define	F1_AGP_STATUS__F1_CAL_CYCLE__SHIFT                 0x0000000a
#define	F1_AGP_STATUS__F1_ISOCH_SUPPORT__SHIFT             0x00000011
#define	F1_AGP_STATUS__F1_RQ__SHIFT                        0x00000018

// F1_AGP_COMMAND
#define	F1_AGP_COMMAND__F1_DATA_RATE__SHIFT                0x00000000
#define	F1_AGP_COMMAND__F1_FW_EN__SHIFT                    0x00000004
#define	F1_AGP_COMMAND__F1_MODE_4G_EN__SHIFT               0x00000005
#define	F1_AGP_COMMAND__F1_AGP_EN__SHIFT                   0x00000008
#define	F1_AGP_COMMAND__F1_SBA_EN__SHIFT                   0x00000009
#define	F1_AGP_COMMAND__F1_PARQSZ__SHIFT                   0x0000000d
#define	F1_AGP_COMMAND__F1_RQ_DEPTH__SHIFT                 0x00000018

// GENMO_WT
#define	GENMO_WT__GENMO_MONO_ADDRESS_B__SHIFT              0x00000000
#define	GENMO_WT__VGA_RAM_EN__SHIFT                        0x00000001
#define	GENMO_WT__VGA_CKSEL__SHIFT                         0x00000002
#define	GENMO_WT__ODD_EVEN_MD_PGSEL__SHIFT                 0x00000005
#define	GENMO_WT__VGA_HSYNC_POL__SHIFT                     0x00000006
#define	GENMO_WT__VGA_VSYNC_POL__SHIFT                     0x00000007

// GENMO_RD
#define	GENMO_RD__GENMO_MONO_ADDRESS_B__SHIFT              0x00000000
#define	GENMO_RD__VGA_RAM_EN__SHIFT                        0x00000001
#define	GENMO_RD__VGA_CKSEL__SHIFT                         0x00000002
#define	GENMO_RD__ODD_EVEN_MD_PGSEL__SHIFT                 0x00000005
#define	GENMO_RD__VGA_HSYNC_POL__SHIFT                     0x00000006
#define	GENMO_RD__VGA_VSYNC_POL__SHIFT                     0x00000007

// CRTC_GEN_CNTL
#define	CRTC_GEN_CNTL__CRTC_DBL_SCAN_EN__SHIFT             0x00000000
#define	CRTC_GEN_CNTL__CRTC_INTERLACE_EN__SHIFT            0x00000001
#define	CRTC_GEN_CNTL__CRTC_C_SYNC_EN__SHIFT               0x00000004
#define	CRTC_GEN_CNTL__CRTC_PIX_WIDTH__SHIFT               0x00000008
#define	CRTC_GEN_CNTL__CRTC_ICON_EN__SHIFT                 0x0000000f
#define	CRTC_GEN_CNTL__CRTC_CUR_EN__SHIFT                  0x00000010
#define	CRTC_GEN_CNTL__CRTC_VSTAT_MODE__SHIFT              0x00000011
#define	CRTC_GEN_CNTL__CRTC_CUR_MODE__SHIFT                0x00000014
#define	CRTC_GEN_CNTL__CRTC_EXT_DISP_EN__SHIFT             0x00000018
#define	CRTC_GEN_CNTL__CRTC_EN__SHIFT                      0x00000019
#define	CRTC_GEN_CNTL__CRTC_DISP_REQ_EN_B__SHIFT           0x0000001a

// DAC_CNTL
#define	DAC_CNTL__DAC_RANGE_CNTL__SHIFT                    0x00000000
#define	DAC_CNTL__DAC_BLANKING__SHIFT                      0x00000002
#define	DAC_CNTL__DAC_CMP_EN__SHIFT                        0x00000003
#define	DAC_CNTL__DAC_CMP_OUT_R__SHIFT                     0x00000004
#define	DAC_CNTL__DAC_CMP_OUT_G__SHIFT                     0x00000005
#define	DAC_CNTL__DAC_CMP_OUT_B__SHIFT                     0x00000006
#define	DAC_CNTL__DAC_CMP_OUTPUT__SHIFT                    0x00000007
#define	DAC_CNTL__DAC_8BIT_EN__SHIFT                       0x00000008
#define	DAC_CNTL__DAC_4BPP_PIX_ORDER__SHIFT                0x00000009
#define	DAC_CNTL__DAC_VGA_ADR_EN__SHIFT                    0x0000000d
#define	DAC_CNTL__DAC_EXPAND_MODE__SHIFT                   0x0000000e
#define	DAC_CNTL__DAC_PDWN__SHIFT                          0x0000000f
#define	DAC_CNTL__CRT_SENSE__SHIFT                         0x00000010
#define	DAC_CNTL__CRT_DETECTION_ON__SHIFT                  0x00000011
#define	DAC_CNTL__DAC_CRC_CONT_EN__SHIFT                   0x00000012
#define	DAC_CNTL__DAC_CRC_EN__SHIFT                        0x00000013
#define	DAC_CNTL__DAC_CRC_FIELD__SHIFT                     0x00000014
#define	DAC_CNTL__DAC_LUT_COUNTER_LIMIT__SHIFT             0x00000015
#define	DAC_CNTL__DAC_LUT_READ_SEL__SHIFT                  0x00000017
#define	DAC_CNTL__DAC_MASK__SHIFT                          0x00000018

// MEM_CNTL
#define	MEM_CNTL__MEM_NUM_CHANNELS__SHIFT                  0x00000000
#define	MEM_CNTL__MC_USE_B_CH_ONLY__SHIFT                  0x00000001
#define	MEM_CNTL__DISABLE_AP__SHIFT                        0x00000002
#define	MEM_CNTL__HALF_MODE__SHIFT                         0x00000003
#define	MEM_CNTL__MEM_BANK_MAPPING_A__SHIFT                0x00000004
#define	MEM_CNTL__MEM_ADDR_MAPPING_A__SHIFT                0x00000008
#define	MEM_CNTL__MEM_BANK_MAPPING_B__SHIFT                0x00000014
#define	MEM_CNTL__MEM_ADDR_MAPPING_B__SHIFT                0x00000018

// EXT_MEM_CNTL
#define	EXT_MEM_CNTL__MEM_TRP__SHIFT                       0x00000000
#define	EXT_MEM_CNTL__MEM_TRCD__SHIFT                      0x00000002
#define	EXT_MEM_CNTL__MEM_TRAS__SHIFT                      0x00000004
#define	EXT_MEM_CNTL__MEM_TRRD__SHIFT                      0x00000008
#define	EXT_MEM_CNTL__MEM_TR2W__SHIFT                      0x0000000a
#define	EXT_MEM_CNTL__MEM_TWR__SHIFT                       0x0000000c
#define	EXT_MEM_CNTL__MEM_TW2R__SHIFT                      0x0000000e
#define	EXT_MEM_CNTL__MEM_TR2R__SHIFT                      0x00000010
#define	EXT_MEM_CNTL__MEM_TWR_MODE__SHIFT                  0x00000012
#define	EXT_MEM_CNTL__MEM_REFRESH_DIS__SHIFT               0x00000014
#define	EXT_MEM_CNTL__MEM_REFRESH_COUNT__SHIFT             0x00000015
#define	EXT_MEM_CNTL__MEM_REFRESH_RATE__SHIFT              0x00000018

// MC_AGP_LOCATION
#define	MC_AGP_LOCATION__MC_AGP_START__SHIFT               0x00000000
#define	MC_AGP_LOCATION__MC_AGP_TOP__SHIFT                 0x00000010

// MC_CNTL_A5
#define	MC_CNTL_A5__Reserved0__SHIFT                       0x00000000
#define	MC_CNTL_A5__DISABLE_CPU__SHIFT                     0x00000001
#define	MC_CNTL_A5__Reserved1__SHIFT                       0x00000003
#define	MC_CNTL_A5__DISABLE_AGP__SHIFT                     0x00000004
#define	MC_CNTL_A5__DISP_HiPri__SHIFT                      0x00000005
#define	MC_CNTL_A5__DLL_Reset__SHIFT                       0x00000006
#define	MC_CNTL_A5__DLL_PwrDown__SHIFT                     0x00000007
#define	MC_CNTL_A5__DLL_Ready__SHIFT                       0x00000008
#define	MC_CNTL_A5__Reserved2__SHIFT                       0x00000009
#define	MC_CNTL_A5__DISP_HiPri2__SHIFT                     0x0000000b
#define	MC_CNTL_A5__Reserved3__SHIFT                       0x0000000c
#define	MC_CNTL_A5__SELF_RF_DIS__SHIFT                     0x00000012
#define	MC_CNTL_A5__DISABLE_BYPASS__SHIFT                  0x00000013
#define	MC_CNTL_A5__Reserved4__SHIFT                       0x00000014
#define	MC_CNTL_A5__SEQ_ARB_MODE__SHIFT                    0x00000015
#define	MC_CNTL_A5__MC_CLEAN_GC__SHIFT                     0x00000016
#define	MC_CNTL_A5__MEM_DYNAMIC_CKE__SHIFT                 0x00000017
#define	MC_CNTL_A5__MEM_SDRAM_TRI_EN__SHIFT                0x00000018
#define	MC_CNTL_A5__MEM_DYN_REC_CTRL__SHIFT                0x00000019
#define	MC_CNTL_A5__Reserved5__SHIFT                       0x0000001a
#define	MC_CNTL_A5__MC_PDN_MODE__SHIFT                     0x0000001b
#define	MC_CNTL_A5__MC_STARTUP__SHIFT                      0x0000001d
#define	MC_CNTL_A5__MC_PWRDOWN__SHIFT                      0x0000001e
#define	MC_CNTL_A5__MC_RESTART__SHIFT                      0x0000001f

// MEM_INIT_LATENCY_TIMER
#define	MEM_INIT_LATENCY_TIMER__MEM_RB0R_INIT_LAT__SHIFT   0x00000000
#define	MEM_INIT_LATENCY_TIMER__MEM_RB1R_INIT_LAT__SHIFT   0x00000004
#define	MEM_INIT_LATENCY_TIMER__MEM_PPR_INIT_LAT__SHIFT    0x00000008
#define	MEM_INIT_LATENCY_TIMER__MEM_DISPR_INIT_LAT__SHIFT  0x0000000c
#define	MEM_INIT_LATENCY_TIMER__MEM_RB0W_INIT_LAT__SHIFT   0x00000010
#define	MEM_INIT_LATENCY_TIMER__MEM_RB1W_INIT_LAT__SHIFT   0x00000014
#define	MEM_INIT_LATENCY_TIMER__MEM_FIXED_INIT_LAT__SHIFT  0x00000018
#define	MEM_INIT_LATENCY_TIMER__SAME_PAGE_PRIO__SHIFT      0x0000001c

// MEM_SDRAM_MODE_REG
#define	MEM_SDRAM_MODE_REG__MEM_MODE_REG_A5__SHIFT         0x00000000
#define	MEM_SDRAM_MODE_REG__Reserved0_A5__SHIFT            0x00000010
#define	MEM_SDRAM_MODE_REG__MEM_CAS_LATENCY__SHIFT         0x00000014
#define	MEM_SDRAM_MODE_REG__Reserved1__SHIFT               0x00000017
#define	MEM_SDRAM_MODE_REG__MC_INIT_COMPLETE__SHIFT        0x0000001c
#define	MEM_SDRAM_MODE_REG__Reserved2__SHIFT               0x0000001d
#define	MEM_SDRAM_MODE_REG__MEM_CFG_TYPE__SHIFT            0x0000001e
#define	MEM_SDRAM_MODE_REG__MEM_SDRAM_RESET__SHIFT         0x0000001f

// AGP_BASE
#define	AGP_BASE__AGP_BASE_ADDR__SHIFT                     0x00000000

// MC_LIMIT
#define	MC_LIMIT__R6_RD_IDLE_LIMIT__SHIFT                  0x00000000
#define	MC_LIMIT__R6_RD_PH_LIMIT__SHIFT                    0x00000005
#define	MC_LIMIT__R6_WR_IDLE_LIMIT__SHIFT                  0x00000008
#define	MC_LIMIT__R6_WR_PH_LIMIT__SHIFT                    0x0000000d
#define	MC_LIMIT__NB_RD_IDLE_LIMIT__SHIFT                  0x00000010
#define	MC_LIMIT__NB_RD_PH_LIMIT__SHIFT                    0x00000015
#define	MC_LIMIT__NB_WR_IDLE_LIMIT__SHIFT                  0x00000018
#define	MC_LIMIT__NB_WR_PH_LIMIT__SHIFT                    0x0000001d

// MEM_IO_CNTL_B0_U1
#define	MEM_IO_CNTL_B0_U1__MEM_N_CKB__SHIFT                0x00000000
#define	MEM_IO_CNTL_B0_U1__MEM_N_AB__SHIFT                 0x00000005
#define	MEM_IO_CNTL_B0_U1__MEM_N_DQMB__SHIFT               0x0000000a
#define	MEM_IO_CNTL_B0_U1__MEM_N_DQSB__SHIFT               0x0000000f

// MEM_IO_CNTL_B1_U1
#define	MEM_IO_CNTL_B1_U1__MEM_P_CKB__SHIFT                0x00000000
#define	MEM_IO_CNTL_B1_U1__MEM_P_AB__SHIFT                 0x00000005
#define	MEM_IO_CNTL_B1_U1__MEM_P_DQMB__SHIFT               0x0000000a
#define	MEM_IO_CNTL_B1_U1__MEM_P_DQSB__SHIFT               0x0000000f
#define	MEM_IO_CNTL_B1_U1__CLKB_ENABLE__SHIFT              0x00000016

// MC_DEBUG_R2
#define	MC_DEBUG_R2__IGNORE_RW_PENALTY_RB0R__SHIFT         0x00000000
#define	MC_DEBUG_R2__IGNORE_RW_PENALTY_RB1R__SHIFT         0x00000001
#define	MC_DEBUG_R2__IGNORE_RW_PENALTY_RB0W__SHIFT         0x00000002
#define	MC_DEBUG_R2__IGNORE_RW_PENALTY_RB1W__SHIFT         0x00000003
#define	MC_DEBUG_R2__IGNORE_RW_PENALTY_DISPR__SHIFT        0x00000004
#define	MC_DEBUG_R2__IGNORE_RW_PENALTY_PPR__SHIFT          0x00000005
#define	MC_DEBUG_R2__IGNORE_RW_PENALTY_FIXED__SHIFT        0x00000006
#define	MC_DEBUG_R2__MEM_VIPW_PRIORITY__SHIFT              0x00000008
#define	MC_DEBUG_R2__MC_PWRMAN_EN__SHIFT                   0x0000000a
#define	MC_DEBUG_R2__CLKA1b_ENABLE__SHIFT                  0x0000000b
#define	MC_DEBUG_R2__CLKB0b_ENABLE__SHIFT                  0x0000000c
#define	MC_DEBUG_R2__CLKB1b_ENABLE__SHIFT                  0x0000000d
#define	MC_DEBUG_R2__DEBUG4__SHIFT                         0x0000000e
#define	MC_DEBUG_R2__MC_BIST_EN__SHIFT                     0x0000000f
#define	MC_DEBUG_R2__MC_BIST_CTRL__SHIFT                   0x00000010
#define	MC_DEBUG_R2__DEBUG0__SHIFT                         0x00000014
#define	MC_DEBUG_R2__DEBUG1__SHIFT                         0x00000015
#define	MC_DEBUG_R2__DEBUG2__SHIFT                         0x00000016
#define	MC_DEBUG_R2__DEBUG3__SHIFT                         0x00000017
#define	MC_DEBUG_R2__MC_DEBUG__SHIFT                       0x00000018
#define	MC_DEBUG_R2__PWR_DOWN_MEM__SHIFT                   0x0000001c
#define	MC_DEBUG_R2__SWAP_CS__SHIFT                        0x0000001d
#define	MC_DEBUG_R2__BLOCK_CS0__SHIFT                      0x0000001e
#define	MC_DEBUG_R2__IKOSE__SHIFT                          0x0000001f

// MC_STATUS
#define	MC_STATUS__MEM_PWRUP_COMPL_A__SHIFT                0x00000000
#define	MC_STATUS__MEM_PWRUP_COMPL_B__SHIFT                0x00000001
#define	MC_STATUS__MC_IDLE__SHIFT                          0x00000002
#define	MC_STATUS__SYSM_IDLE__SHIFT                        0x00000010
#define	MC_STATUS__SYSM_SHUTDOWN__SHIFT                    0x00000011
#define	MC_STATUS__SYSM_PARKED__SHIFT                      0x00000012
#define	MC_STATUS__DLL_READY__SHIFT                        0x00000013

// MEM_IO_OE_CNTL
#define	MEM_IO_OE_CNTL__MEM_DQ_OE_EXTEND_A__SHIFT          0x00000000
#define	MEM_IO_OE_CNTL__MEM_DQ_OE_POSITION_A__SHIFT        0x00000002
#define	MEM_IO_OE_CNTL__MEM_QS_OE_EXTEND_A__SHIFT          0x00000004
#define	MEM_IO_OE_CNTL__MEM_QS_OE_POSITION_A__SHIFT        0x00000006
#define	MEM_IO_OE_CNTL__MEM_DQ_OE_EXTEND_B__SHIFT          0x00000008
#define	MEM_IO_OE_CNTL__MEM_DQ_OE_POSITION_B__SHIFT        0x0000000a
#define	MEM_IO_OE_CNTL__MEM_QS_OE_EXTEND_B__SHIFT          0x0000000c
#define	MEM_IO_OE_CNTL__MEM_QS_OE_POSITION_B__SHIFT        0x0000000e
#define	MEM_IO_OE_CNTL__MEM_DYNAMIC_CKE__SHIFT             0x00000010
#define	MEM_IO_OE_CNTL__MEM_SDRAM_TRI_EN__SHIFT            0x00000011

// GC_NB_TOM
#define	GC_NB_TOM__MC_FB_START__SHIFT                      0x00000000
#define	GC_NB_TOM__MC_FB_TOP__SHIFT                        0x00000010

// AGP_BASE_2_A5
#define	AGP_BASE_2_A5__AGP_BASE_ADDR_2__SHIFT              0x00000000

// MC_NB_MC_INDEX
#define	MC_NB_MC_INDEX__MC_NB_MC_IND_ADDR__SHIFT           0x00000000
#define	MC_NB_MC_INDEX__MC_NB_MC_IND_WR_EN__SHIFT          0x00000008

// MC_NB_MC_DATA
#define	MC_NB_MC_DATA__MC_NBMC_DATA__SHIFT                 0x00000000

// MC_FB_LOCATION
#define	MC_FB_LOCATION__MC_FB_START__SHIFT                 0x00000000
#define	MC_FB_LOCATION__MC_FB_TOP__SHIFT                   0x00000010

// GRA00
#define	GRA00__GRPH_SET_RESET0__SHIFT                      0x00000000
#define	GRA00__GRPH_SET_RESET1__SHIFT                      0x00000001
#define	GRA00__GRPH_SET_RESET2__SHIFT                      0x00000002
#define	GRA00__GRPH_SET_RESET3__SHIFT                      0x00000003

// GRA01
#define	GRA01__GRPH_SET_RESET_ENA0__SHIFT                  0x00000000
#define	GRA01__GRPH_SET_RESET_ENA1__SHIFT                  0x00000001
#define	GRA01__GRPH_SET_RESET_ENA2__SHIFT                  0x00000002
#define	GRA01__GRPH_SET_RESET_ENA3__SHIFT                  0x00000003

// GRA02
#define	GRA02__GRPH_CCOMP__SHIFT                           0x00000000

// GRA03
#define	GRA03__GRPH_ROTATE__SHIFT                          0x00000000
#define	GRA03__GRPH_FN_SEL__SHIFT                          0x00000003

// GRA04
#define	GRA04__GRPH_RMAP__SHIFT                            0x00000000

// GRA06
#define	GRA06__GRPH_GRAPHICS__SHIFT                        0x00000000
#define	GRA06__GRPH_ODDEVEN__SHIFT                         0x00000001
#define	GRA06__GRPH_ADRSEL__SHIFT                          0x00000002

// GRA07
#define	GRA07__GRPH_XCARE0__SHIFT                          0x00000000
#define	GRA07__GRPH_XCARE1__SHIFT                          0x00000001
#define	GRA07__GRPH_XCARE2__SHIFT                          0x00000002
#define	GRA07__GRPH_XCARE3__SHIFT                          0x00000003

// GRA08
#define	GRA08__GRPH_BMSK__SHIFT                            0x00000000

// SEQ02
#define	SEQ02__SEQ_MAP0_EN__SHIFT                          0x00000000
#define	SEQ02__SEQ_MAP1_EN__SHIFT                          0x00000001
#define	SEQ02__SEQ_MAP2_EN__SHIFT                          0x00000002
#define	SEQ02__SEQ_MAP3_EN__SHIFT                          0x00000003

// SEQ04
#define	SEQ04__SEQ_256K__SHIFT                             0x00000001
#define	SEQ04__SEQ_ODDEVEN__SHIFT                          0x00000002
#define	SEQ04__SEQ_CHAIN__SHIFT                            0x00000003

// CRT1E
#define	CRT1E__GRPH_DEC_RD1__SHIFT                         0x00000001

// CRT1F
#define	CRT1F__GRPH_DEC_RD0__SHIFT                         0x00000000

// CRT22
#define	CRT22__GRPH_LATCH_DATA__SHIFT                      0x00000000

// CRT1E_S
#define	CRT1E_S__GRPH_DEC_RD1_M__SHIFT                     0x00000001

// CRT1F_S
#define	CRT1F_S__GRPH_DEC_RD0_M__SHIFT                     0x00000000

// CRT22_S
#define	CRT22_S__GRPH_LATCH_DATA_M__SHIFT                  0x00000000

// HOST_PATH_CNTL
#define	HOST_PATH_CNTL__HDP_WRITE_THROUGH_CACHE_DIS__SHIFT 0x00000016
#define	HOST_PATH_CNTL__HDP_APER_CNTL__SHIFT               0x00000017
#define	HOST_PATH_CNTL__HP_LIN_RD_CACHE_DIS__SHIFT         0x00000018
#define	HOST_PATH_CNTL__HP_RBBM_LOCK_DIS__SHIFT            0x00000019
#define	HOST_PATH_CNTL__HDP_SOFT_RESET__SHIFT              0x0000001a
#define	HOST_PATH_CNTL__HDP_READ_BUFFER_INVALIDATE__SHIFT  0x0000001b
#define	HOST_PATH_CNTL__HDP_WRITE_COMBINER_TIMEOUT__SHIFT  0x0000001c
#define	HOST_PATH_CNTL__HP_TEST_RST_CNTL__SHIFT            0x0000001f

// MEM_VGA_WP_SEL
#define	MEM_VGA_WP_SEL__MEM_VGA_WPS0__SHIFT                0x00000000
#define	MEM_VGA_WP_SEL__MEM_VGA_WPS1__SHIFT                0x00000010

// MEM_VGA_RP_SEL
#define	MEM_VGA_RP_SEL__MEM_VGA_RPS0__SHIFT                0x00000000
#define	MEM_VGA_RP_SEL__MEM_VGA_RPS1__SHIFT                0x00000010

// HDP_DEBUG
#define	HDP_DEBUG__HDP_0_DEBUG__SHIFT                      0x00000000
#define	HDP_DEBUG__HDP_1_DEBUG__SHIFT                      0x00000001
#define	HDP_DEBUG__HDP_2_DEBUG__SHIFT                      0x00000002
#define	HDP_DEBUG__HDP_3_DEBUG__SHIFT                      0x00000003
#define	HDP_DEBUG__HDP_4_DEBUG__SHIFT                      0x00000004
#define	HDP_DEBUG__HDP_5_DEBUG__SHIFT                      0x00000005
#define	HDP_DEBUG__HDP_6_DEBUG__SHIFT                      0x00000006
#define	HDP_DEBUG__HDP_7_DEBUG__SHIFT                      0x00000007

// SW_SEMAPHORE
#define	SW_SEMAPHORE__SW_SEMAPHORE__SHIFT                  0x00000000

// SURFACE_CNTL
#define	SURFACE_CNTL__SURF_TRANSLATION_DIS__SHIFT          0x00000008
#define	SURFACE_CNTL__NONSURF_AP0_SWP__SHIFT               0x00000014
#define	SURFACE_CNTL__NONSURF_AP1_SWP__SHIFT               0x00000016

// SURFACE0_LOWER_BOUND
#define	SURFACE0_LOWER_BOUND__SURF_LOWER__SHIFT            0x00000000

// SURFACE1_LOWER_BOUND
#define	SURFACE1_LOWER_BOUND__SURF_LOWER__SHIFT            0x00000000

// SURFACE2_LOWER_BOUND
#define	SURFACE2_LOWER_BOUND__SURF_LOWER__SHIFT            0x00000000

// SURFACE3_LOWER_BOUND
#define	SURFACE3_LOWER_BOUND__SURF_LOWER__SHIFT            0x00000000

// SURFACE4_LOWER_BOUND
#define	SURFACE4_LOWER_BOUND__SURF_LOWER__SHIFT            0x00000000

// SURFACE5_LOWER_BOUND
#define	SURFACE5_LOWER_BOUND__SURF_LOWER__SHIFT            0x00000000

// SURFACE6_LOWER_BOUND
#define	SURFACE6_LOWER_BOUND__SURF_LOWER__SHIFT            0x00000000

// SURFACE7_LOWER_BOUND
#define	SURFACE7_LOWER_BOUND__SURF_LOWER__SHIFT            0x00000000

// SURFACE0_UPPER_BOUND
#define	SURFACE0_UPPER_BOUND__SURF_UPPER__SHIFT            0x00000000

// SURFACE1_UPPER_BOUND
#define	SURFACE1_UPPER_BOUND__SURF_UPPER__SHIFT            0x00000000

// SURFACE2_UPPER_BOUND
#define	SURFACE2_UPPER_BOUND__SURF_UPPER__SHIFT            0x00000000

// SURFACE3_UPPER_BOUND
#define	SURFACE3_UPPER_BOUND__SURF_UPPER__SHIFT            0x00000000

// SURFACE4_UPPER_BOUND
#define	SURFACE4_UPPER_BOUND__SURF_UPPER__SHIFT            0x00000000

// SURFACE5_UPPER_BOUND
#define	SURFACE5_UPPER_BOUND__SURF_UPPER__SHIFT            0x00000000

// SURFACE6_UPPER_BOUND
#define	SURFACE6_UPPER_BOUND__SURF_UPPER__SHIFT            0x00000000

// SURFACE7_UPPER_BOUND
#define	SURFACE7_UPPER_BOUND__SURF_UPPER__SHIFT            0x00000000

// SURFACE0_INFO
#define	SURFACE0_INFO__SURF0_PITCHSEL__SHIFT               0x00000000
#define	SURFACE0_INFO__SURF0_TILE_MODE_R2__SHIFT           0x00000010
#define	SURFACE0_INFO__SURF0_AP0_SWP__SHIFT                0x00000014
#define	SURFACE0_INFO__SURF0_AP1_SWP__SHIFT                0x00000016
#define	SURFACE0_INFO__SURF0_WRITE_FLAG__SHIFT             0x00000018
#define	SURFACE0_INFO__SURF0_READ_FLAG__SHIFT              0x00000019

// SURFACE1_INFO
#define	SURFACE1_INFO__SURF1_PITCHSEL__SHIFT               0x00000000
#define	SURFACE1_INFO__SURF1_TILE_MODE_R2__SHIFT           0x00000010
#define	SURFACE1_INFO__SURF1_AP0_SWP__SHIFT                0x00000014
#define	SURFACE1_INFO__SURF1_AP1_SWP__SHIFT                0x00000016
#define	SURFACE1_INFO__SURF1_WRITE_FLAG__SHIFT             0x00000018
#define	SURFACE1_INFO__SURF1_READ_FLAG__SHIFT              0x00000019

// SURFACE2_INFO
#define	SURFACE2_INFO__SURF2_PITCHSEL__SHIFT               0x00000000
#define	SURFACE2_INFO__SURF2_TILE_MODE_R2__SHIFT           0x00000010
#define	SURFACE2_INFO__SURF2_AP0_SWP__SHIFT                0x00000014
#define	SURFACE2_INFO__SURF2_AP1_SWP__SHIFT                0x00000016
#define	SURFACE2_INFO__SURF2_WRITE_FLAG__SHIFT             0x00000018
#define	SURFACE2_INFO__SURF2_READ_FLAG__SHIFT              0x00000019

// SURFACE3_INFO
#define	SURFACE3_INFO__SURF3_PITCHSEL__SHIFT               0x00000000
#define	SURFACE3_INFO__SURF3_TILE_MODE_R2__SHIFT           0x00000010
#define	SURFACE3_INFO__SURF3_AP0_SWP__SHIFT                0x00000014
#define	SURFACE3_INFO__SURF3_AP1_SWP__SHIFT                0x00000016
#define	SURFACE3_INFO__SURF3_WRITE_FLAG__SHIFT             0x00000018
#define	SURFACE3_INFO__SURF3_READ_FLAG__SHIFT              0x00000019

// SURFACE4_INFO
#define	SURFACE4_INFO__SURF4_PITCHSEL__SHIFT               0x00000000
#define	SURFACE4_INFO__SURF4_TILE_MODE_R2__SHIFT           0x00000010
#define	SURFACE4_INFO__SURF4_AP0_SWP__SHIFT                0x00000014
#define	SURFACE4_INFO__SURF4_AP1_SWP__SHIFT                0x00000016
#define	SURFACE4_INFO__SURF4_WRITE_FLAG__SHIFT             0x00000018
#define	SURFACE4_INFO__SURF4_READ_FLAG__SHIFT              0x00000019

// SURFACE5_INFO
#define	SURFACE5_INFO__SURF5_PITCHSEL__SHIFT               0x00000000
#define	SURFACE5_INFO__SURF5_TILE_MODE_R2__SHIFT           0x00000010
#define	SURFACE5_INFO__SURF5_AP0_SWP__SHIFT                0x00000014
#define	SURFACE5_INFO__SURF5_AP1_SWP__SHIFT                0x00000016
#define	SURFACE5_INFO__SURF5_WRITE_FLAG__SHIFT             0x00000018
#define	SURFACE5_INFO__SURF5_READ_FLAG__SHIFT              0x00000019

// SURFACE6_INFO
#define	SURFACE6_INFO__SURF6_PITCHSEL__SHIFT               0x00000000
#define	SURFACE6_INFO__SURF6_TILE_MODE_R2__SHIFT           0x00000010
#define	SURFACE6_INFO__SURF6_AP0_SWP__SHIFT                0x00000014
#define	SURFACE6_INFO__SURF6_AP1_SWP__SHIFT                0x00000016
#define	SURFACE6_INFO__SURF6_WRITE_FLAG__SHIFT             0x00000018
#define	SURFACE6_INFO__SURF6_READ_FLAG__SHIFT              0x00000019

// SURFACE7_INFO
#define	SURFACE7_INFO__SURF7_PITCHSEL__SHIFT               0x00000000
#define	SURFACE7_INFO__SURF7_TILE_MODE_R2__SHIFT           0x00000010
#define	SURFACE7_INFO__SURF7_AP0_SWP__SHIFT                0x00000014
#define	SURFACE7_INFO__SURF7_AP1_SWP__SHIFT                0x00000016
#define	SURFACE7_INFO__SURF7_WRITE_FLAG__SHIFT             0x00000018
#define	SURFACE7_INFO__SURF7_READ_FLAG__SHIFT              0x00000019

// SURFACE_ACCESS_FLAGS
#define	SURFACE_ACCESS_FLAGS__SURF0_WRITE_FLAG__SHIFT      0x00000000
#define	SURFACE_ACCESS_FLAGS__SURF1_WRITE_FLAG__SHIFT      0x00000001
#define	SURFACE_ACCESS_FLAGS__SURF2_WRITE_FLAG__SHIFT      0x00000002
#define	SURFACE_ACCESS_FLAGS__SURF3_WRITE_FLAG__SHIFT      0x00000003
#define	SURFACE_ACCESS_FLAGS__SURF4_WRITE_FLAG__SHIFT      0x00000004
#define	SURFACE_ACCESS_FLAGS__SURF5_WRITE_FLAG__SHIFT      0x00000005
#define	SURFACE_ACCESS_FLAGS__SURF6_WRITE_FLAG__SHIFT      0x00000006
#define	SURFACE_ACCESS_FLAGS__SURF7_WRITE_FLAG__SHIFT      0x00000007
#define	SURFACE_ACCESS_FLAGS__NONSURF_WRITE_FLAG__SHIFT    0x00000008
#define	SURFACE_ACCESS_FLAGS__LINEAR_WRITE_FLAG__SHIFT     0x00000009
#define	SURFACE_ACCESS_FLAGS__VGA_WRITE_FLAG__SHIFT        0x0000000a
#define	SURFACE_ACCESS_FLAGS__SURF0_READ_FLAG__SHIFT       0x00000010
#define	SURFACE_ACCESS_FLAGS__SURF1_READ_FLAG__SHIFT       0x00000011
#define	SURFACE_ACCESS_FLAGS__SURF2_READ_FLAG__SHIFT       0x00000012
#define	SURFACE_ACCESS_FLAGS__SURF3_READ_FLAG__SHIFT       0x00000013
#define	SURFACE_ACCESS_FLAGS__SURF4_READ_FLAG__SHIFT       0x00000014
#define	SURFACE_ACCESS_FLAGS__SURF5_READ_FLAG__SHIFT       0x00000015
#define	SURFACE_ACCESS_FLAGS__SURF6_READ_FLAG__SHIFT       0x00000016
#define	SURFACE_ACCESS_FLAGS__SURF7_READ_FLAG__SHIFT       0x00000017
#define	SURFACE_ACCESS_FLAGS__NONSURF_READ_FLAG__SHIFT     0x00000018
#define	SURFACE_ACCESS_FLAGS__LINEAR_READ_FLAG__SHIFT      0x00000019
#define	SURFACE_ACCESS_FLAGS__VGA_READ_FLAG__SHIFT         0x0000001a

// SURFACE_ACCESS_CLR
#define	SURFACE_ACCESS_CLR__SURF0_WRITE_FLAG_CLR__SHIFT    0x00000000
#define	SURFACE_ACCESS_CLR__SURF1_WRITE_FLAG_CLR__SHIFT    0x00000001
#define	SURFACE_ACCESS_CLR__SURF2_WRITE_FLAG_CLR__SHIFT    0x00000002
#define	SURFACE_ACCESS_CLR__SURF3_WRITE_FLAG_CLR__SHIFT    0x00000003
#define	SURFACE_ACCESS_CLR__SURF4_WRITE_FLAG_CLR__SHIFT    0x00000004
#define	SURFACE_ACCESS_CLR__SURF5_WRITE_FLAG_CLR__SHIFT    0x00000005
#define	SURFACE_ACCESS_CLR__SURF6_WRITE_FLAG_CLR__SHIFT    0x00000006
#define	SURFACE_ACCESS_CLR__SURF7_WRITE_FLAG_CLR__SHIFT    0x00000007
#define	SURFACE_ACCESS_CLR__NONSURF_WRITE_FLAG_CLR__SHIFT  0x00000008
#define	SURFACE_ACCESS_CLR__LINEAR_WRITE_FLAG_CLR__SHIFT   0x00000009
#define	SURFACE_ACCESS_CLR__VGA_WRITE_FLAG_CLR__SHIFT      0x0000000a
#define	SURFACE_ACCESS_CLR__SURF0_READ_FLAG_CLR__SHIFT     0x00000010
#define	SURFACE_ACCESS_CLR__SURF1_READ_FLAG_CLR__SHIFT     0x00000011
#define	SURFACE_ACCESS_CLR__SURF2_READ_FLAG_CLR__SHIFT     0x00000012
#define	SURFACE_ACCESS_CLR__SURF3_READ_FLAG_CLR__SHIFT     0x00000013
#define	SURFACE_ACCESS_CLR__SURF4_READ_FLAG_CLR__SHIFT     0x00000014
#define	SURFACE_ACCESS_CLR__SURF5_READ_FLAG_CLR__SHIFT     0x00000015
#define	SURFACE_ACCESS_CLR__SURF6_READ_FLAG_CLR__SHIFT     0x00000016
#define	SURFACE_ACCESS_CLR__SURF7_READ_FLAG_CLR__SHIFT     0x00000017
#define	SURFACE_ACCESS_CLR__NONSURF_READ_FLAG_CLR__SHIFT   0x00000018
#define	SURFACE_ACCESS_CLR__LINEAR_READ_FLAG_CLR__SHIFT    0x00000019
#define	SURFACE_ACCESS_CLR__VGA_READ_FLAG_CLR__SHIFT       0x0000001a

// GRPH8_IDX
#define	GRPH8_IDX__GRPH_IDX__SHIFT                         0x00000000

// GRPH8_DATA
#define	GRPH8_DATA__GRPH_DATA__SHIFT                       0x00000000

// GRA05
#define	GRA05__GRPH_WRITE_MODE__SHIFT                      0x00000000
#define	GRA05__GRPH_READ1__SHIFT                           0x00000003
#define	GRA05__CGA_ODDEVEN__SHIFT                          0x00000004
#define	GRA05__GRPH_OES__SHIFT                             0x00000005
#define	GRA05__GRPH_PACK__SHIFT                            0x00000006

// SEQ8_IDX
#define	SEQ8_IDX__SEQ_IDX__SHIFT                           0x00000000

// SEQ8_DATA
#define	SEQ8_DATA__SEQ_DATA__SHIFT                         0x00000000

// CRTC8_IDX
#define	CRTC8_IDX__VCRTC_IDX__SHIFT                        0x00000000

// CRTC8_DATA
#define	CRTC8_DATA__VCRTC_DATA__SHIFT                      0x00000000

// CRT14
#define	CRT14__UNDRLN_LOC__SHIFT                           0x00000000
#define	CRT14__ADDR_CNT_BY4__SHIFT                         0x00000005
#define	CRT14__DOUBLE_WORD__SHIFT                          0x00000006

// CRT17
#define	CRT17__RA0_AS_A13B__SHIFT                          0x00000000
#define	CRT17__RA1_AS_A14B__SHIFT                          0x00000001
#define	CRT17__VCOUNT_BY2__SHIFT                           0x00000002
#define	CRT17__ADDR_CNT_BY2__SHIFT                         0x00000003
#define	CRT17__WRAP_A15TOA0__SHIFT                         0x00000005
#define	CRT17__BYTE_MODE__SHIFT                            0x00000006
#define	CRT17__CRTC_SYNC_EN__SHIFT                         0x00000007

// CRT14_S
#define	CRT14_S__UNDRLN_LOC_S__SHIFT                       0x00000000
#define	CRT14_S__ADDR_CNT_BY4_M__SHIFT                     0x00000005
#define	CRT14_S__DOUBLE_WORD_M__SHIFT                      0x00000006

// CRT17_S
#define	CRT17_S__RA0_AS_A13B_M__SHIFT                      0x00000000
#define	CRT17_S__RA1_AS_A14B_M__SHIFT                      0x00000001
#define	CRT17_S__VCOUNT_BY2_S__SHIFT                       0x00000002
#define	CRT17_S__ADDR_CNT_BY2_M__SHIFT                     0x00000003
#define	CRT17_S__WRAP_A15TOA0_M__SHIFT                     0x00000005
#define	CRT17_S__BYTE_MODE_M__SHIFT                        0x00000006
#define	CRT17_S__CRTC_SYNC_EN_M__SHIFT                     0x00000007

// GEN_INT_CNTL
#define	GEN_INT_CNTL__CRTC_VBLANK_MASK__SHIFT              0x00000000
#define	GEN_INT_CNTL__CRTC_VLINE_MASK__SHIFT               0x00000001
#define	GEN_INT_CNTL__CRTC_VSYNC_MASK__SHIFT               0x00000002
#define	GEN_INT_CNTL__SNAPSHOT_MASK__SHIFT                 0x00000003
#define	GEN_INT_CNTL__FP_DETECT_MASK__SHIFT                0x00000004
#define	GEN_INT_CNTL__CRTC2_VLINE_MASK__SHIFT              0x00000005
#define	GEN_INT_CNTL__CRTC2_VSYNC_MASK__SHIFT              0x00000006
#define	GEN_INT_CNTL__SNAPSHOT2_MASK__SHIFT                0x00000007
#define	GEN_INT_CNTL__CRTC2_VBLANK_MASK__SHIFT             0x00000009
#define	GEN_INT_CNTL__FP2_DETECT_MASK__SHIFT               0x0000000a
#define	GEN_INT_CNTL__VSYNC_DIFF_OVER_LIMIT_MASK__SHIFT    0x0000000b
#define	GEN_INT_CNTL__GUI_IDLE_MASK__SHIFT                 0x00000013
#define	GEN_INT_CNTL__SW_INT_EN__SHIFT                     0x00000019
#define	GEN_INT_CNTL__GEYSERVILLE_MASK__SHIFT              0x0000001b
#define	GEN_INT_CNTL__HDCP_AUTHORIZED_INT_MASK__SHIFT      0x0000001c
#define	GEN_INT_CNTL__DVI_I2C_INT_MASK__SHIFT              0x0000001d
#define	GEN_INT_CNTL__GUIDMA_MASK__SHIFT                   0x0000001e
#define	GEN_INT_CNTL__VIDDMA_MASK__SHIFT                   0x0000001f

// GEN_INT_STATUS
#define	GEN_INT_STATUS__CRTC_VBLANK_STAT__SHIFT            0x00000000
#define	GEN_INT_STATUS__CRTC_VBLANK_STAT_AK__SHIFT         0x00000000
#define	GEN_INT_STATUS__CRTC_VLINE_STAT__SHIFT             0x00000001
#define	GEN_INT_STATUS__CRTC_VLINE_STAT_AK__SHIFT          0x00000001
#define	GEN_INT_STATUS__CRTC_VSYNC_STAT__SHIFT             0x00000002
#define	GEN_INT_STATUS__CRTC_VSYNC_STAT_AK__SHIFT          0x00000002
#define	GEN_INT_STATUS__SNAPSHOT_STAT__SHIFT               0x00000003
#define	GEN_INT_STATUS__SNAPSHOT_STAT_AK__SHIFT            0x00000003
#define	GEN_INT_STATUS__FP_DETECT_STAT__SHIFT              0x00000004
#define	GEN_INT_STATUS__FP_DETECT_STAT_AK__SHIFT           0x00000004
#define	GEN_INT_STATUS__CRTC2_VLINE_STAT__SHIFT            0x00000005
#define	GEN_INT_STATUS__CRTC2_VLINE_STAT_AK__SHIFT         0x00000005
#define	GEN_INT_STATUS__CRTC2_VSYNC_STAT__SHIFT            0x00000006
#define	GEN_INT_STATUS__CRTC2_VSYNC_STAT_AK__SHIFT         0x00000006
#define	GEN_INT_STATUS__SNAPSHOT2_STAT__SHIFT              0x00000007
#define	GEN_INT_STATUS__SNAPSHOT2_STAT_AK__SHIFT           0x00000007
#define	GEN_INT_STATUS__CAP0_INT_ACTIVE__SHIFT             0x00000008
#define	GEN_INT_STATUS__CRTC2_VBLANK_STAT__SHIFT           0x00000009
#define	GEN_INT_STATUS__CRTC2_VBLANK_STAT_AK__SHIFT        0x00000009
#define	GEN_INT_STATUS__FP2_DETECT_STAT__SHIFT             0x0000000a
#define	GEN_INT_STATUS__FP2_DETECT_STAT_AK__SHIFT          0x0000000a
#define	GEN_INT_STATUS__VSYNC_DIFF_OVER_LIMIT_STAT__SHIFT  0x0000000b
#define	GEN_INT_STATUS__VSYNC_DIFF_OVER_LIMIT_STAT_AK__SHIFT 0x0000000b
#define	GEN_INT_STATUS__GUI_IDLE_STAT__SHIFT               0x00000013
#define	GEN_INT_STATUS__GUI_IDLE_STAT_AK__SHIFT            0x00000013
#define	GEN_INT_STATUS__SW_INT__SHIFT                      0x00000019
#define	GEN_INT_STATUS__SW_INT_AK__SHIFT                   0x00000019
#define	GEN_INT_STATUS__SW_INT_SET__SHIFT                  0x0000001a
#define	GEN_INT_STATUS__GEYSERVILLE_STAT__SHIFT            0x0000001b
#define	GEN_INT_STATUS__GEYSERVILLE_STAT_AK__SHIFT         0x0000001b
#define	GEN_INT_STATUS__HDCP_AUTHORIZED_INT_STAT__SHIFT    0x0000001c
#define	GEN_INT_STATUS__HDCP_AUTHORIZED_INT_AK__SHIFT      0x0000001c
#define	GEN_INT_STATUS__DVI_I2C_INT_STAT__SHIFT            0x0000001d
#define	GEN_INT_STATUS__DVI_I2C_INT_AK__SHIFT              0x0000001d
#define	GEN_INT_STATUS__GUIDMA_STAT__SHIFT                 0x0000001e
#define	GEN_INT_STATUS__GUIDMA_AK__SHIFT                   0x0000001e
#define	GEN_INT_STATUS__VIDDMA_STAT__SHIFT                 0x0000001f
#define	GEN_INT_STATUS__VIDDMA_AK__SHIFT                   0x0000001f

// CRTC_EXT_CNTL
#define	CRTC_EXT_CNTL__CRTC_VGA_XOVERSCAN__SHIFT           0x00000000
#define	CRTC_EXT_CNTL__VGA_BLINK_RATE__SHIFT               0x00000001
#define	CRTC_EXT_CNTL__VGA_ATI_LINEAR__SHIFT               0x00000003
#define	CRTC_EXT_CNTL__VGA_128KAP_PAGING__SHIFT            0x00000004
#define	CRTC_EXT_CNTL__VGA_TEXT_132__SHIFT                 0x00000005
#define	CRTC_EXT_CNTL__VGA_XCRT_CNT_EN__SHIFT              0x00000006
#define	CRTC_EXT_CNTL__CRTC_HSYNC_DIS__SHIFT               0x00000008
#define	CRTC_EXT_CNTL__CRTC_VSYNC_DIS__SHIFT               0x00000009
#define	CRTC_EXT_CNTL__CRTC_DISPLAY_DIS__SHIFT             0x0000000a
#define	CRTC_EXT_CNTL__CRTC_SYNC_TRISTATE__SHIFT           0x0000000b
#define	CRTC_EXT_CNTL__CRTC_HSYNC_TRISTATE__SHIFT          0x0000000c
#define	CRTC_EXT_CNTL__CRTC_VSYNC_TRISTATE__SHIFT          0x0000000d
#define	CRTC_EXT_CNTL__CRT_ON__SHIFT                       0x0000000f
#define	CRTC_EXT_CNTL__VGA_CUR_B_TEST__SHIFT               0x00000011
#define	CRTC_EXT_CNTL__VGA_PACK_DIS__SHIFT                 0x00000012
#define	CRTC_EXT_CNTL__VGA_MEM_PS_EN__SHIFT                0x00000013
#define	CRTC_EXT_CNTL__VCRTC_IDX_MASTER__SHIFT             0x00000018

// WAIT_UNTIL
#define	WAIT_UNTIL__WAIT_CRTC_PFLIP__SHIFT                 0x00000000
#define	WAIT_UNTIL__WAIT_RE_CRTC_VLINE__SHIFT              0x00000001
#define	WAIT_UNTIL__WAIT_FE_CRTC_VLINE__SHIFT              0x00000002
#define	WAIT_UNTIL__WAIT_CRTC_VLINE__SHIFT                 0x00000003
#define	WAIT_UNTIL__WAIT_DMA_VIPH0_IDLE__SHIFT             0x00000004
#define	WAIT_UNTIL__WAIT_DMA_VIPH1_IDLE__SHIFT             0x00000005
#define	WAIT_UNTIL__WAIT_DMA_VIPH2_IDLE__SHIFT             0x00000006
#define	WAIT_UNTIL__WAIT_DMA_VIPH3_IDLE__SHIFT             0x00000007
#define	WAIT_UNTIL__WAIT_DMA_VID_IDLE__SHIFT               0x00000008
#define	WAIT_UNTIL__WAIT_DMA_GUI_IDLE__SHIFT               0x00000009
#define	WAIT_UNTIL__WAIT_CMDFIFO__SHIFT                    0x0000000a
#define	WAIT_UNTIL__WAIT_OV0_FLIP__SHIFT                   0x0000000b
#define	WAIT_UNTIL__WAIT_OV0_SLICEDONE__SHIFT              0x0000000c
#define	WAIT_UNTIL__WAIT_2D_IDLE__SHIFT                    0x0000000e
#define	WAIT_UNTIL__WAIT_3D_IDLE__SHIFT                    0x0000000f
#define	WAIT_UNTIL__WAIT_2D_IDLECLEAN__SHIFT               0x00000010
#define	WAIT_UNTIL__WAIT_3D_IDLECLEAN__SHIFT               0x00000011
#define	WAIT_UNTIL__WAIT_HOST_IDLECLEAN__SHIFT             0x00000012
#define	WAIT_UNTIL__WAIT_EXTERN_SIG__SHIFT                 0x00000013
#define	WAIT_UNTIL__CMDFIFO_ENTRIES__SHIFT                 0x00000014
#define	WAIT_UNTIL__WAIT_BOTH_CRTC_PFLIP__SHIFT            0x0000001e
#define	WAIT_UNTIL__ENG_DISPLAY_SELECT__SHIFT              0x0000001f

// ISYNC_CNTL
#define	ISYNC_CNTL__ISYNC_ANY2D_IDLE3D__SHIFT              0x00000000
#define	ISYNC_CNTL__ISYNC_ANY3D_IDLE2D__SHIFT              0x00000001
#define	ISYNC_CNTL__ISYNC_TRIG2D_IDLE3D__SHIFT             0x00000002
#define	ISYNC_CNTL__ISYNC_TRIG3D_IDLE2D__SHIFT             0x00000003
#define	ISYNC_CNTL__ISYNC_WAIT_IDLEGUI__SHIFT              0x00000004
#define	ISYNC_CNTL__ISYNC_CPSCRATCH_IDLEGUI__SHIFT         0x00000005

// RBBM_GUICNTL
#define	RBBM_GUICNTL__HOST_DATA_SWAP__SHIFT                0x00000000

// RBBM_STATUS
#define	RBBM_STATUS__CMDFIFO_AVAIL__SHIFT                  0x00000000
#define	RBBM_STATUS__HIRQ_ON_RBB__SHIFT                    0x00000008
#define	RBBM_STATUS__CPRQ_ON_RBB__SHIFT                    0x00000009
#define	RBBM_STATUS__CFRQ_ON_RBB__SHIFT                    0x0000000a
#define	RBBM_STATUS__HIRQ_IN_RTBUF__SHIFT                  0x0000000b
#define	RBBM_STATUS__CPRQ_IN_RTBUF__SHIFT                  0x0000000c
#define	RBBM_STATUS__CFRQ_IN_RTBUF__SHIFT                  0x0000000d
#define	RBBM_STATUS__CF_PIPE_BUSY__SHIFT                   0x0000000e
#define	RBBM_STATUS__ENG_EV_BUSY__SHIFT                    0x0000000f
#define	RBBM_STATUS__CP_CMDSTRM_BUSY__SHIFT                0x00000010
#define	RBBM_STATUS__E2_BUSY__SHIFT                        0x00000011
#define	RBBM_STATUS__RB2D_BUSY__SHIFT                      0x00000012
#define	RBBM_STATUS__RB3D_BUSY__SHIFT                      0x00000013
#define	RBBM_STATUS__VAP_BUSY__SHIFT                       0x00000014
#define	RBBM_STATUS__RE_BUSY__SHIFT                        0x00000015
#define	RBBM_STATUS__TAM_BUSY__SHIFT                       0x00000016
#define	RBBM_STATUS__TDM_BUSY__SHIFT                       0x00000017
#define	RBBM_STATUS__PB_BUSY__SHIFT                        0x00000018
#define	RBBM_STATUS__TIM_BUSY__SHIFT                       0x00000019
#define	RBBM_STATUS__GUI_ACTIVE__SHIFT                     0x0000001f

// RBBM_CNTL
#define	RBBM_CNTL__RB_SETTLE__SHIFT                        0x00000000
#define	RBBM_CNTL__ABORTCLKS_HI__SHIFT                     0x00000004
#define	RBBM_CNTL__ABORTCLKS_CP__SHIFT                     0x00000008
#define	RBBM_CNTL__ABORTCLKS_CFIFO__SHIFT                  0x0000000c
#define	RBBM_CNTL__CPQ_DATA_SWAP__SHIFT                    0x00000011
#define	RBBM_CNTL__NO_ABORT_IDCT__SHIFT                    0x00000015
#define	RBBM_CNTL__NO_ABORT_BIOS__SHIFT                    0x00000016
#define	RBBM_CNTL__NO_ABORT_TVOUT__SHIFT                   0x00000017
#define	RBBM_CNTL__NO_ABORT_CP__SHIFT                      0x00000018
#define	RBBM_CNTL__NO_ABORT_HI__SHIFT                      0x00000019
#define	RBBM_CNTL__NO_ABORT_HDP__SHIFT                     0x0000001a
#define	RBBM_CNTL__NO_ABORT_MC__SHIFT                      0x0000001b
#define	RBBM_CNTL__NO_ABORT_AIC__SHIFT                     0x0000001c
#define	RBBM_CNTL__NO_ABORT_VIP__SHIFT                     0x0000001d
#define	RBBM_CNTL__NO_ABORT_DISP__SHIFT                    0x0000001e
#define	RBBM_CNTL__NO_ABORT_CG__SHIFT                      0x0000001f

// RBBM_SOFT_RESET
#define	RBBM_SOFT_RESET__SOFT_RESET_CP__SHIFT              0x00000000
#define	RBBM_SOFT_RESET__SOFT_RESET_HI__SHIFT              0x00000001
#define	RBBM_SOFT_RESET__SOFT_RESET_VAP__SHIFT             0x00000002
#define	RBBM_SOFT_RESET__SOFT_RESET_RE__SHIFT              0x00000003
#define	RBBM_SOFT_RESET__SOFT_RESET_PP__SHIFT              0x00000004
#define	RBBM_SOFT_RESET__SOFT_RESET_E2__SHIFT              0x00000005
#define	RBBM_SOFT_RESET__SOFT_RESET_RB__SHIFT              0x00000006
#define	RBBM_SOFT_RESET__SOFT_RESET_HDP__SHIFT             0x00000007
#define	RBBM_SOFT_RESET__SOFT_RESET_MC__SHIFT              0x00000008
#define	RBBM_SOFT_RESET__SOFT_RESET_AIC__SHIFT             0x00000009
#define	RBBM_SOFT_RESET__SOFT_RESET_VIP__SHIFT             0x0000000a
#define	RBBM_SOFT_RESET__SOFT_RESET_DISP__SHIFT            0x0000000b
#define	RBBM_SOFT_RESET__SOFT_RESET_CG__SHIFT              0x0000000c

// NQWAIT_UNTIL
#define	NQWAIT_UNTIL__WAIT_GUI_IDLE__SHIFT                 0x00000000

// RBBM_DEBUG
#define	RBBM_DEBUG__RBBM_DEBUG_R2__SHIFT                   0x00000000

// RBBM_CMDFIFO_ADDR
#define	RBBM_CMDFIFO_ADDR__CMDFIFO_ADDR__SHIFT             0x00000000

// RBBM_CMDFIFO_DATAL
#define	RBBM_CMDFIFO_DATAL__CMDFIFO_DATAL__SHIFT           0x00000000

// RBBM_CMDFIFO_DATAH
#define	RBBM_CMDFIFO_DATAH__CMDFIFO_DATAH__SHIFT           0x00000000

// RBBM_CMDFIFO_STAT
#define	RBBM_CMDFIFO_STAT__CMDFIFO_RPTR__SHIFT             0x00000000
#define	RBBM_CMDFIFO_STAT__CMDFIFO_WPTR__SHIFT             0x00000008

// RBBM_PERF_CNTL
#define	RBBM_PERF_CNTL__PERFSEL1__SHIFT                    0x00000000
#define	RBBM_PERF_CNTL__CLR_PERF1__SHIFT                   0x00000006
#define	RBBM_PERF_CNTL__EN_PERF1__SHIFT                    0x00000007
#define	RBBM_PERF_CNTL__PERFSEL2__SHIFT                    0x00000008
#define	RBBM_PERF_CNTL__CLR_PERF2__SHIFT                   0x0000000e
#define	RBBM_PERF_CNTL__EN_PERF2__SHIFT                    0x0000000f
#define	RBBM_PERF_CNTL__SYNC_SEL__SHIFT                    0x0000001f

// RBBM_PERF_COUNT1
#define	RBBM_PERF_COUNT1__PERF_COUNT1__SHIFT               0x00000000

// RBBM_PERF_COUNT2
#define	RBBM_PERF_COUNT2__PERF_COUNT2__SHIFT               0x00000000

// GENFC_RD
#define	GENFC_RD__VSYNC_SEL_R__SHIFT                       0x00000003

// GENFC_WT
#define	GENFC_WT__VSYNC_SEL_W__SHIFT                       0x00000003

// GENS0
#define	GENS0__SENSE_SWITCH__SHIFT                         0x00000004
#define	GENS0__CRT_INTR__SHIFT                             0x00000007

// GENS1
#define	GENS1__NO_DIPLAY__SHIFT                            0x00000000
#define	GENS1__VGA_VSTATUS__SHIFT                          0x00000003
#define	GENS1__PIXEL_READ_BACK__SHIFT                      0x00000004

// DAC_DATA
#define	DAC_DATA__DAC_DATA__SHIFT                          0x00000000

// DAC_MASK
#define	DAC_MASK__DAC_MASK__SHIFT                          0x00000000

// DAC_R_INDEX
#define	DAC_R_INDEX__DAC_R_INDEX__SHIFT                    0x00000000

// DAC_W_INDEX
#define	DAC_W_INDEX__DAC_W_INDEX__SHIFT                    0x00000000

// SEQ00
#define	SEQ00__SEQ_RST0B__SHIFT                            0x00000000
#define	SEQ00__SEQ_RST1B__SHIFT                            0x00000001

// SEQ01
#define	SEQ01__SEQ_DOT8__SHIFT                             0x00000000
#define	SEQ01__SEQ_SHIFT2__SHIFT                           0x00000002
#define	SEQ01__SEQ_PCLKBY2__SHIFT                          0x00000003
#define	SEQ01__SEQ_SHIFT4__SHIFT                           0x00000004
#define	SEQ01__SEQ_MAXBW__SHIFT                            0x00000005

// SEQ03
#define	SEQ03__SEQ_FONT_B1__SHIFT                          0x00000000
#define	SEQ03__SEQ_FONT_B2__SHIFT                          0x00000001
#define	SEQ03__SEQ_FONT_A1__SHIFT                          0x00000002
#define	SEQ03__SEQ_FONT_A2__SHIFT                          0x00000003
#define	SEQ03__SEQ_FONT_B0__SHIFT                          0x00000004
#define	SEQ03__SEQ_FONT_A0__SHIFT                          0x00000005

// CRT00
#define	CRT00__H_TOTAL__SHIFT                              0x00000000

// CRT01
#define	CRT01__H_DISP_END__SHIFT                           0x00000000

// CRT02
#define	CRT02__H_BLANK_START__SHIFT                        0x00000000

// CRT03
#define	CRT03__H_BLANK_END__SHIFT                          0x00000000
#define	CRT03__H_DE_SKEW__SHIFT                            0x00000005
#define	CRT03__CR10CR11_R_DIS_B__SHIFT                     0x00000007

// CRT04
#define	CRT04__H_SYNC_START__SHIFT                         0x00000000

// CRT05
#define	CRT05__H_SYNC_END__SHIFT                           0x00000000
#define	CRT05__H_SYNC_SKEW__SHIFT                          0x00000005
#define	CRT05__H_BLANK_END_B5__SHIFT                       0x00000007

// CRT06
#define	CRT06__V_TOTAL__SHIFT                              0x00000000

// CRT07
#define	CRT07__V_TOTAL_B8__SHIFT                           0x00000000
#define	CRT07__V_DISP_END_B8__SHIFT                        0x00000001
#define	CRT07__V_SYNC_START_B8__SHIFT                      0x00000002
#define	CRT07__V_BLANK_START_B8__SHIFT                     0x00000003
#define	CRT07__LINE_CMP_B8__SHIFT                          0x00000004
#define	CRT07__V_TOTAL_B9__SHIFT                           0x00000005
#define	CRT07__V_DISP_END_B9__SHIFT                        0x00000006
#define	CRT07__V_SYNC_START_B9__SHIFT                      0x00000007

// CRT08
#define	CRT08__ROW_SCAN_START__SHIFT                       0x00000000
#define	CRT08__BYTE_PAN__SHIFT                             0x00000005

// CRT09
#define	CRT09__MAX_ROW_SCAN__SHIFT                         0x00000000
#define	CRT09__V_BLANK_START_B9__SHIFT                     0x00000005
#define	CRT09__LINE_CMP_B9__SHIFT                          0x00000006
#define	CRT09__DOUBLE_CHAR_HEIGHT__SHIFT                   0x00000007

// CRT0A
#define	CRT0A__CURSOR_START__SHIFT                         0x00000000
#define	CRT0A__CURSOR_DISABLE__SHIFT                       0x00000005

// CRT0B
#define	CRT0B__CURSOR_END__SHIFT                           0x00000000
#define	CRT0B__CURSOR_SKEW__SHIFT                          0x00000005

// CRT0C
#define	CRT0C__DISP_START__SHIFT                           0x00000000

// CRT0D
#define	CRT0D__DISP_START__SHIFT                           0x00000000

// CRT0E
#define	CRT0E__CURSOR_LOC_HI__SHIFT                        0x00000000

// CRT0F
#define	CRT0F__CURSOR_LOC_LO__SHIFT                        0x00000000

// CRT10
#define	CRT10__V_SYNC_START__SHIFT                         0x00000000

// CRT11
#define	CRT11__V_SYNC_END__SHIFT                           0x00000000
#define	CRT11__V_INTR_CLR__SHIFT                           0x00000004
#define	CRT11__V_INTR_EN__SHIFT                            0x00000005
#define	CRT11__SEL5_REFRESH_CYC__SHIFT                     0x00000006
#define	CRT11__C0T7_WR_ONLY__SHIFT                         0x00000007

// CRT12
#define	CRT12__V_DISP_END__SHIFT                           0x00000000

// CRT13
#define	CRT13__DISP_PITCH__SHIFT                           0x00000000

// CRT15
#define	CRT15__V_BLANK_START__SHIFT                        0x00000000

// CRT16
#define	CRT16__V_BLANK_END__SHIFT                          0x00000000

// CRT18
#define	CRT18__LINE_CMP__SHIFT                             0x00000000

// CRT00_S
#define	CRT00_S__H_TOTAL_S__SHIFT                          0x00000000

// CRT01_S
#define	CRT01_S__H_DISP_END_S__SHIFT                       0x00000000

// CRT02_S
#define	CRT02_S__H_BLANK_START_S__SHIFT                    0x00000000

// CRT03_S
#define	CRT03_S__H_BLANK_END_S__SHIFT                      0x00000000
#define	CRT03_S__H_DE_SKEW_S__SHIFT                        0x00000005
#define	CRT03_S__CR10CR11_R_DIS_B_M__SHIFT                 0x00000007

// CRT04_S
#define	CRT04_S__H_SYNC_START_S__SHIFT                     0x00000000

// CRT05_S
#define	CRT05_S__H_SYNC_END_S__SHIFT                       0x00000000
#define	CRT05_S__H_SYNC_SKEW_S__SHIFT                      0x00000005
#define	CRT05_S__H_BLANK_END_B5_S__SHIFT                   0x00000007

// CRT06_S
#define	CRT06_S__V_TOTAL_S__SHIFT                          0x00000000

// CRT07_S
#define	CRT07_S__V_TOTAL_B8_S__SHIFT                       0x00000000
#define	CRT07_S__V_DISP_END_B8_S__SHIFT                    0x00000001
#define	CRT07_S__V_SYNC_START_B8_S__SHIFT                  0x00000002
#define	CRT07_S__V_BLANK_START_B8_S__SHIFT                 0x00000003
#define	CRT07_S__LINE_CMP_B8_M__SHIFT                      0x00000004
#define	CRT07_S__V_TOTAL_B9_S__SHIFT                       0x00000005
#define	CRT07_S__V_DISP_END_B9_S__SHIFT                    0x00000006
#define	CRT07_S__V_SYNC_START_B9_S__SHIFT                  0x00000007

// CRT08_S
#define	CRT08_S__ROW_SCAN_START_M__SHIFT                   0x00000000
#define	CRT08_S__BYTE_PAN_M__SHIFT                         0x00000005

// CRT09_S
#define	CRT09_S__MAX_ROW_SCAN_S__SHIFT                     0x00000000
#define	CRT09_S__V_BLANK_START_B9_S__SHIFT                 0x00000005
#define	CRT09_S__LINE_CMP_B9_M__SHIFT                      0x00000006
#define	CRT09_S__DOUBLE_CHAR_HEIGHT_M__SHIFT               0x00000007

// CRT0A_S
#define	CRT0A_S__CURSOR_START_S__SHIFT                     0x00000000
#define	CRT0A_S__CURSOR_DISABLE_M__SHIFT                   0x00000005

// CRT0B_S
#define	CRT0B_S__CURSOR_END_S__SHIFT                       0x00000000
#define	CRT0B_S__CURSOR_SKEW_M__SHIFT                      0x00000005

// CRT0C_S
#define	CRT0C_S__DISP_START_M__SHIFT                       0x00000000

// CRT0D_S
#define	CRT0D_S__DISP_START_M__SHIFT                       0x00000000

// CRT0E_S
#define	CRT0E_S__CURSOR_LOC_HI_M__SHIFT                    0x00000000

// CRT0F_S
#define	CRT0F_S__CURSOR_LOC_LO_M__SHIFT                    0x00000000

// CRT10_S
#define	CRT10_S__V_SYNC_START_S__SHIFT                     0x00000000

// CRT11_S
#define	CRT11_S__V_SYNC_END_S__SHIFT                       0x00000000
#define	CRT11_S__V_INTR_CLR_M__SHIFT                       0x00000004
#define	CRT11_S__V_INTR_EN_M__SHIFT                        0x00000005
#define	CRT11_S__SEL5_REFRESH_CYC_M__SHIFT                 0x00000006
#define	CRT11_S__C0T7_WR_ONLY_M__SHIFT                     0x00000007

// CRT12_S
#define	CRT12_S__V_DISP_END_S__SHIFT                       0x00000000

// CRT13_S
#define	CRT13_S__DISP_PITCH_M__SHIFT                       0x00000000

// CRT15_S
#define	CRT15_S__V_BLANK_START_S__SHIFT                    0x00000000

// CRT16_S
#define	CRT16_S__V_BLANK_END_S__SHIFT                      0x00000000

// CRT18_S
#define	CRT18_S__LINE_CMP_M__SHIFT                         0x00000000

// ATTRX
#define	ATTRX__ATTR_IDX__SHIFT                             0x00000000
#define	ATTRX__ATTR_PAL_RW_ENB__SHIFT                      0x00000005

// ATTRDW
#define	ATTRDW__ATTR_DATA__SHIFT                           0x00000000

// ATTRDR
#define	ATTRDR__ATTR_DATA__SHIFT                           0x00000000

// ATTR00
#define	ATTR00__ATTR_PAL__SHIFT                            0x00000000

// ATTR01
#define	ATTR01__ATTR_PAL__SHIFT                            0x00000000

// ATTR02
#define	ATTR02__ATTR_PAL__SHIFT                            0x00000000

// ATTR03
#define	ATTR03__ATTR_PAL__SHIFT                            0x00000000

// ATTR04
#define	ATTR04__ATTR_PAL__SHIFT                            0x00000000

// ATTR05
#define	ATTR05__ATTR_PAL__SHIFT                            0x00000000

// ATTR06
#define	ATTR06__ATTR_PAL__SHIFT                            0x00000000

// ATTR07
#define	ATTR07__ATTR_PAL__SHIFT                            0x00000000

// ATTR08
#define	ATTR08__ATTR_PAL__SHIFT                            0x00000000

// ATTR09
#define	ATTR09__ATTR_PAL__SHIFT                            0x00000000

// ATTR0A
#define	ATTR0A__ATTR_PAL__SHIFT                            0x00000000

// ATTR0B
#define	ATTR0B__ATTR_PAL__SHIFT                            0x00000000

// ATTR0C
#define	ATTR0C__ATTR_PAL__SHIFT                            0x00000000

// ATTR0D
#define	ATTR0D__ATTR_PAL__SHIFT                            0x00000000

// ATTR0E
#define	ATTR0E__ATTR_PAL__SHIFT                            0x00000000

// ATTR0F
#define	ATTR0F__ATTR_PAL__SHIFT                            0x00000000

// ATTR10
#define	ATTR10__ATTR_GRPH_MODE__SHIFT                      0x00000000
#define	ATTR10__ATTR_MONO_EN__SHIFT                        0x00000001
#define	ATTR10__ATTR_LGRPH_EN__SHIFT                       0x00000002
#define	ATTR10__ATTR_BLINK_EN__SHIFT                       0x00000003
#define	ATTR10__ATTR_PANTOPONLY__SHIFT                     0x00000005
#define	ATTR10__ATTR_PCLKBY2__SHIFT                        0x00000006
#define	ATTR10__ATTR_CSEL_EN__SHIFT                        0x00000007

// ATTR11
#define	ATTR11__ATTR_OVSC__SHIFT                           0x00000000

// ATTR12
#define	ATTR12__ATTR_MAP_EN__SHIFT                         0x00000000
#define	ATTR12__ATTR_VSMUX__SHIFT                          0x00000004

// ATTR13
#define	ATTR13__ATTR_PPAN__SHIFT                           0x00000000

// ATTR14
#define	ATTR14__ATTR_CSEL1__SHIFT                          0x00000000
#define	ATTR14__ATTR_CSEL2__SHIFT                          0x00000002

// VCLK_ECP_CNTL
#define	VCLK_ECP_CNTL__VCLK_SRC_SEL__SHIFT                 0x00000000
#define	VCLK_ECP_CNTL__VCLK_INVERT__SHIFT                  0x00000004
#define	VCLK_ECP_CNTL__PIXCLK_SRC_INVERT__SHIFT            0x00000005
#define	VCLK_ECP_CNTL__PIXCLK_ALWAYS_ONb__SHIFT            0x00000006
#define	VCLK_ECP_CNTL__PIXCLK_DAC_ALWAYS_ONb__SHIFT        0x00000007
#define	VCLK_ECP_CNTL__ECP_DIV__SHIFT                      0x00000008
#define	VCLK_ECP_CNTL__ECP_FORCE_ON__SHIFT                 0x00000012
#define	VCLK_ECP_CNTL__SUBCLK_FORCE_ON__SHIFT              0x00000013

// DISP_TEST_MACRO_RW_WRITE
#define	DISP_TEST_MACRO_RW_WRITE__TEST_MACRO_RW_WRITE1__SHIFT 0x00000000
#define	DISP_TEST_MACRO_RW_WRITE__TEST_MACRO_RW_WRITE2__SHIFT 0x0000000e

// DISP_TEST_MACRO_RW_READ
#define	DISP_TEST_MACRO_RW_READ__TEST_MACRO_RW_READ1__SHIFT 0x00000000
#define	DISP_TEST_MACRO_RW_READ__TEST_MACRO_RW_READ2__SHIFT 0x00000010

// DISP_TEST_MACRO_RW_DATA
#define	DISP_TEST_MACRO_RW_DATA__TEST_MACRO_RW_DATA__SHIFT 0x00000000

// DISP_TEST_MACRO_RW_CNTL
#define	DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_START__SHIFT 0x00000000
#define	DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_OP__SHIFT   0x00000001
#define	DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_MODE__SHIFT 0x00000004
#define	DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_MISMATCH_SEL__SHIFT 0x00000006
#define	DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_MISMATCH__SHIFT 0x0000000f
#define	DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_ENABLE__SHIFT 0x00000010
#define	DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_SCLK_NEG_ENABLE__SHIFT 0x00000011

// PIXCLKS_CNTL
#define	PIXCLKS_CNTL__PIX2CLK_SRC_SEL__SHIFT               0x00000000
#define	PIXCLKS_CNTL__PIX2CLK_INVERT__SHIFT                0x00000004
#define	PIXCLKS_CNTL__PIX2CLK_SRC_INVERT__SHIFT            0x00000005
#define	PIXCLKS_CNTL__PIX2CLK_ALWAYS_ONb__SHIFT            0x00000006
#define	PIXCLKS_CNTL__PIX2CLK_DAC_ALWAYS_ONb__SHIFT        0x00000007
#define	PIXCLKS_CNTL__PIXCLK_TV_SRC_SEL__SHIFT             0x00000008
#define	PIXCLKS_CNTL__PIXCLK_BLEND_ALWAYS_ONb__SHIFT       0x0000000b
#define	PIXCLKS_CNTL__PIXCLK_GV_ALWAYS_ONb__SHIFT          0x0000000c
#define	PIXCLKS_CNTL__PIXCLK_DIG_TMDS_ALWAYS_ONb__SHIFT    0x0000000d
#define	PIXCLKS_CNTL__PIXCLK_LVDS_ALWAYS_ONb__SHIFT        0x0000000e
#define	PIXCLKS_CNTL__PIXCLK_TMDS_ALWAYS_ONb__SHIFT        0x0000000f

// CRTC_STATUS
#define	CRTC_STATUS__CRTC_VBLANK_CUR__SHIFT                0x00000000
#define	CRTC_STATUS__CRTC_VBLANK_SAVE__SHIFT               0x00000001
#define	CRTC_STATUS__CRTC_VBLANK_SAVE_CLEAR__SHIFT         0x00000001
#define	CRTC_STATUS__CRTC_VLINE_SYNC__SHIFT                0x00000002
#define	CRTC_STATUS__CRTC_FRAME__SHIFT                     0x00000003

// GPIO_VGA_DDC
#define	GPIO_VGA_DDC__VGA_DCC_DATA_OUTPUT__SHIFT           0x00000000
#define	GPIO_VGA_DDC__VGA_DDC_CLK_OUTPUT__SHIFT            0x00000001
#define	GPIO_VGA_DDC__VGA_DDC_DATA_INPUT__SHIFT            0x00000008
#define	GPIO_VGA_DDC__VGA_DDC_CLK_INPUT__SHIFT             0x00000009
#define	GPIO_VGA_DDC__VGA_DDC_DATA_OUT_EN__SHIFT           0x00000010
#define	GPIO_VGA_DDC__VGA_DDC_CLK_OUT_EN__SHIFT            0x00000011

// GPIO_DVI_DDC
#define	GPIO_DVI_DDC__DVI_DDC_DATA_OUTPUT__SHIFT           0x00000000
#define	GPIO_DVI_DDC__DVI_DDC_CLK_OUTPUT__SHIFT            0x00000001
#define	GPIO_DVI_DDC__DVI_DDC_DATA_INPUT__SHIFT            0x00000008
#define	GPIO_DVI_DDC__DVI_DDC_CLK_INPUT__SHIFT             0x00000009
#define	GPIO_DVI_DDC__DVI_DDC_DATA_OUT_EN__SHIFT           0x00000010
#define	GPIO_DVI_DDC__DVI_DDC_CLK_OUT_EN__SHIFT            0x00000011
#define	GPIO_DVI_DDC__SW_WANTS_TO_USE_DVI_I2C__SHIFT       0x00000014
#define	GPIO_DVI_DDC__SW_CAN_USE_DVI_I2C__SHIFT            0x00000014
#define	GPIO_DVI_DDC__SW_DONE_USING_DVI_I2C__SHIFT         0x00000015
#define	GPIO_DVI_DDC__HDCP_NEEDS_DVI_I2C__SHIFT            0x00000015
#define	GPIO_DVI_DDC__ABORT_HDCP_DVI_I2C__SHIFT            0x00000016
#define	GPIO_DVI_DDC__HW_USING_DVI_I2C__SHIFT              0x00000016

// GPIO_MONID
#define	GPIO_MONID__GPIO_MONID_0_OUTPUT__SHIFT             0x00000000
#define	GPIO_MONID__GPIO_MONID_1_OUTPUT__SHIFT             0x00000001
#define	GPIO_MONID__GPIO_MONID_0_INPUT__SHIFT              0x00000008
#define	GPIO_MONID__GPIO_MONID_1_INPUT__SHIFT              0x00000009
#define	GPIO_MONID__GPIO_MONID_0_OUT_EN__SHIFT             0x00000010
#define	GPIO_MONID__GPIO_MONID_1_OUT_EN__SHIFT             0x00000011

// GPIO_CRT2_DDC
#define	GPIO_CRT2_DDC__CRT2_DDC_DATA_OUTPUT__SHIFT         0x00000000
#define	GPIO_CRT2_DDC__CRT2_DDC_CLK_OUTPUT__SHIFT          0x00000001
#define	GPIO_CRT2_DDC__CRT2_DDC_DATA_INPUT__SHIFT          0x00000008
#define	GPIO_CRT2_DDC__CRT2_DDC_CLK_INPUT__SHIFT           0x00000009
#define	GPIO_CRT2_DDC__CRT2_DDC_DATA_OUT_EN__SHIFT         0x00000010
#define	GPIO_CRT2_DDC__CRT2_DDC_CLK_OUT_EN__SHIFT          0x00000011

// PALETTE_INDEX
#define	PALETTE_INDEX__PALETTE_W_INDEX__SHIFT              0x00000000
#define	PALETTE_INDEX__PALETTE_R_INDEX__SHIFT              0x00000010

// PALETTE_DATA
#define	PALETTE_DATA__PALETTE_DATA_B__SHIFT                0x00000000
#define	PALETTE_DATA__PALETTE_DATA_G__SHIFT                0x00000008
#define	PALETTE_DATA__PALETTE_DATA_R__SHIFT                0x00000010

// PALETTE_30_DATA
#define	PALETTE_30_DATA__PALETTE_DATA_B__SHIFT             0x00000000
#define	PALETTE_30_DATA__PALETTE_DATA_G__SHIFT             0x0000000a
#define	PALETTE_30_DATA__PALETTE_DATA_R__SHIFT             0x00000014

// CRTC_H_TOTAL_DISP
#define	CRTC_H_TOTAL_DISP__CRTC_H_TOTAL__SHIFT             0x00000000
#define	CRTC_H_TOTAL_DISP__CRTC_H_DISP__SHIFT              0x00000010

// CRTC_H_SYNC_STRT_WID
#define	CRTC_H_SYNC_STRT_WID__CRTC_H_SYNC_STRT_PIX__SHIFT  0x00000000
#define	CRTC_H_SYNC_STRT_WID__CRTC_H_SYNC_STRT_CHAR__SHIFT 0x00000003
#define	CRTC_H_SYNC_STRT_WID__CRTC_H_SYNC_WID__SHIFT       0x00000010
#define	CRTC_H_SYNC_STRT_WID__CRTC_H_SYNC_POL__SHIFT       0x00000017
#define	CRTC_H_SYNC_STRT_WID__CRTC_H_SYNC_SKEW_TUNE__SHIFT 0x00000018
#define	CRTC_H_SYNC_STRT_WID__CRTC_H_SYNC_SKEW_TUNE_MODE__SHIFT 0x0000001c

// CRTC_V_TOTAL_DISP
#define	CRTC_V_TOTAL_DISP__CRTC_V_TOTAL__SHIFT             0x00000000
#define	CRTC_V_TOTAL_DISP__CRTC_V_DISP__SHIFT              0x00000010

// CRTC_V_SYNC_STRT_WID
#define	CRTC_V_SYNC_STRT_WID__CRTC_V_SYNC_STRT__SHIFT      0x00000000
#define	CRTC_V_SYNC_STRT_WID__CRTC_V_SYNC_WID__SHIFT       0x00000010
#define	CRTC_V_SYNC_STRT_WID__CRTC_V_SYNC_POL__SHIFT       0x00000017

// CRTC_VLINE_CRNT_VLINE
#define	CRTC_VLINE_CRNT_VLINE__CRTC_VLINE__SHIFT           0x00000000
#define	CRTC_VLINE_CRNT_VLINE__CRTC_CRNT_VLINE__SHIFT      0x00000010

// CRTC_CRNT_FRAME
#define	CRTC_CRNT_FRAME__CRTC_CRNT_FRAME__SHIFT            0x00000000

// CRTC_GUI_TRIG_VLINE
#define	CRTC_GUI_TRIG_VLINE__CRTC_GUI_TRIG_VLINE_START__SHIFT 0x00000000
#define	CRTC_GUI_TRIG_VLINE__CRTC_GUI_TRIG_VLINE_INV__SHIFT 0x0000000f
#define	CRTC_GUI_TRIG_VLINE__CRTC_GUI_TRIG_VLINE_END__SHIFT 0x00000010
#define	CRTC_GUI_TRIG_VLINE__CRTC_GUI_TRIG_VLINE_STALL__SHIFT 0x0000001e
#define	CRTC_GUI_TRIG_VLINE__CRTC_GUI_TRIG_VLINE__SHIFT    0x0000001f

// CRTC_DEBUG
#define	CRTC_DEBUG__CRTC_GUI_TRIG_BYPASS_EN__SHIFT         0x00000000
#define	CRTC_DEBUG__GUI_TRIG_VLINE_BYPASS__SHIFT           0x00000001
#define	CRTC_DEBUG__GUI_TRIG_OFFSET_BYPASS__SHIFT          0x00000002
#define	CRTC_DEBUG__GUI_TRIG_PITCH_ADD_BYPASS__SHIFT       0x00000003

// CRTC_OFFSET_RIGHT
#define	CRTC_OFFSET_RIGHT__CRTC_OFFSET_RIGHT__SHIFT        0x00000000
#define	CRTC_OFFSET_RIGHT__CRTC_GUI_TRIG_OFFSET__SHIFT     0x0000001e
#define	CRTC_OFFSET_RIGHT__CRTC_OFFSET_LOCK__SHIFT         0x0000001f

// CRTC_OFFSET
#define	CRTC_OFFSET__CRTC_OFFSET__SHIFT                    0x00000000
#define	CRTC_OFFSET__CRTC_GUI_TRIG_OFFSET__SHIFT           0x0000001e
#define	CRTC_OFFSET__CRTC_OFFSET_LOCK__SHIFT               0x0000001f

// CRTC_OFFSET_CNTL
#define	CRTC_OFFSET_CNTL__CRTC_TILE_LINE__SHIFT            0x00000000
#define	CRTC_OFFSET_CNTL__CRTC_TILE_LINE_RIGHT__SHIFT      0x00000004
#define	CRTC_OFFSET_CNTL__CRTC_TILE_EN_RIGHT__SHIFT        0x0000000e
#define	CRTC_OFFSET_CNTL__CRTC_TILE_EN__SHIFT              0x0000000f
#define	CRTC_OFFSET_CNTL__CRTC_OFFSET_FLIP_CNTL__SHIFT     0x00000010
#define	CRTC_OFFSET_CNTL__CRTC_STEREO_OFFSET_EN__SHIFT     0x00000011
#define	CRTC_OFFSET_CNTL__CRTC_STEREO_SYNC_EN__SHIFT       0x00000012
#define	CRTC_OFFSET_CNTL__CRTC_STEREO_SYNC_OUT_EN__SHIFT   0x00000014
#define	CRTC_OFFSET_CNTL__CRTC_STEREO_SYNC__SHIFT          0x00000015
#define	CRTC_OFFSET_CNTL__CRTC_GUI_TRIG_OFFSET_LEFT_EN__SHIFT 0x0000001c
#define	CRTC_OFFSET_CNTL__CRTC_GUI_TRIG_OFFSET_RIGHT_EN__SHIFT 0x0000001d
#define	CRTC_OFFSET_CNTL__CRTC_GUI_TRIG_OFFSET__SHIFT      0x0000001e
#define	CRTC_OFFSET_CNTL__CRTC_OFFSET_LOCK__SHIFT          0x0000001f

// CRTC_PITCH
#define	CRTC_PITCH__CRTC_PITCH__SHIFT                      0x00000000
#define	CRTC_PITCH__CRTC_PITCH_RIGHT__SHIFT                0x00000010

// OVR_CLR
#define	OVR_CLR__OVR_CLR_B__SHIFT                          0x00000000
#define	OVR_CLR__OVR_CLR_G__SHIFT                          0x00000008
#define	OVR_CLR__OVR_CLR_R__SHIFT                          0x00000010

// OVR_WID_LEFT_RIGHT
#define	OVR_WID_LEFT_RIGHT__OVR_WID_RIGHT__SHIFT           0x00000000
#define	OVR_WID_LEFT_RIGHT__OVR_WID_LEFT__SHIFT            0x00000010

// OVR_WID_TOP_BOTTOM
#define	OVR_WID_TOP_BOTTOM__OVR_WID_BOTTOM__SHIFT          0x00000000
#define	OVR_WID_TOP_BOTTOM__OVR_WID_TOP__SHIFT             0x00000010

// DISPLAY_BASE_ADDR
#define	DISPLAY_BASE_ADDR__DISPLAY_BASE_ADDR__SHIFT        0x00000000

// SNAPSHOT_VH_COUNTS
#define	SNAPSHOT_VH_COUNTS__SNAPSHOT_HCOUNT__SHIFT         0x00000000
#define	SNAPSHOT_VH_COUNTS__SNAPSHOT_VCOUNT__SHIFT         0x00000010

// SNAPSHOT_F_COUNT
#define	SNAPSHOT_F_COUNT__SNAPSHOT_F_COUNT__SHIFT          0x00000000

// N_VIF_COUNT
#define	N_VIF_COUNT__N_VIF_COUNT_VAL__SHIFT                0x00000000
#define	N_VIF_COUNT__GENLOCK_SOURCE_SEL__SHIFT             0x0000001f

// SNAPSHOT_VIF_COUNT
#define	SNAPSHOT_VIF_COUNT__LSNAPSHOT_VIF_COUNT__SHIFT     0x00000000
#define	SNAPSHOT_VIF_COUNT__USNAPSHOT_VIF_COUNT__SHIFT     0x0000000a
#define	SNAPSHOT_VIF_COUNT__AUTO_SNAPSHOT_TAKEN_RD__SHIFT  0x00000018
#define	SNAPSHOT_VIF_COUNT__AUTO_SNAPSHOT_TAKEN_WR__SHIFT  0x00000018
#define	SNAPSHOT_VIF_COUNT__MANUAL_SNAPSHOT_NOW__SHIFT     0x00000019

// FP_CRTC_H_TOTAL_DISP
#define	FP_CRTC_H_TOTAL_DISP__FP_CRTC_H_TOTAL__SHIFT       0x00000000
#define	FP_CRTC_H_TOTAL_DISP__FP_CRTC_H_DISP__SHIFT        0x00000010

// FP_CRTC_V_TOTAL_DISP
#define	FP_CRTC_V_TOTAL_DISP__FP_CRTC_V_TOTAL__SHIFT       0x00000000
#define	FP_CRTC_V_TOTAL_DISP__FP_CRTC_V_DISP__SHIFT        0x00000010

// CRT_CRTC_H_SYNC_STRT_WID
#define	CRT_CRTC_H_SYNC_STRT_WID__CRT_CRTC_H_SYNC_STRT_CHAR__SHIFT 0x00000003
#define	CRT_CRTC_H_SYNC_STRT_WID__CRT_CRTC_H_SYNC_WID__SHIFT 0x00000010

// CRT_CRTC_V_SYNC_STRT_WID
#define	CRT_CRTC_V_SYNC_STRT_WID__CRT_CRTC_V_SYNC_STRT__SHIFT 0x00000000
#define	CRT_CRTC_V_SYNC_STRT_WID__CRT_CRTC_V_SYNC_WID__SHIFT 0x00000010

// CUR_OFFSET
#define	CUR_OFFSET__CUR_OFFSET__SHIFT                      0x00000000
#define	CUR_OFFSET__CUR_LOCK__SHIFT                        0x0000001f

// CUR_HORZ_VERT_POSN
#define	CUR_HORZ_VERT_POSN__CUR_VERT_POSN__SHIFT           0x00000000
#define	CUR_HORZ_VERT_POSN__CUR_HORZ_POSN__SHIFT           0x00000010
#define	CUR_HORZ_VERT_POSN__CUR_LOCK__SHIFT                0x0000001f

// CUR_HORZ_VERT_OFF
#define	CUR_HORZ_VERT_OFF__CUR_VERT_OFF__SHIFT             0x00000000
#define	CUR_HORZ_VERT_OFF__CUR_HORZ_OFF__SHIFT             0x00000010
#define	CUR_HORZ_VERT_OFF__CUR_LOCK__SHIFT                 0x0000001f

// CUR_CLR0
#define	CUR_CLR0__CUR_CLR0_B__SHIFT                        0x00000000
#define	CUR_CLR0__CUR_CLR0_G__SHIFT                        0x00000008
#define	CUR_CLR0__CUR_CLR0_R__SHIFT                        0x00000010

// CUR_CLR1
#define	CUR_CLR1__CUR_CLR1_B__SHIFT                        0x00000000
#define	CUR_CLR1__CUR_CLR1_G__SHIFT                        0x00000008
#define	CUR_CLR1__CUR_CLR1_R__SHIFT                        0x00000010

// FP_HORZ_VERT_ACTIVE
#define	FP_HORZ_VERT_ACTIVE__FP_VERT_ACTIVE_SIZE__SHIFT    0x00000000
#define	FP_HORZ_VERT_ACTIVE__FP_HORZ_ACTIVE_SIZE__SHIFT    0x00000010

// CRTC_MORE_CNTL
#define	CRTC_MORE_CNTL__CRTC_HORZ_BLANK_MODE_SEL__SHIFT    0x00000000
#define	CRTC_MORE_CNTL__CRTC_VERT_BLANK_MODE_SEL__SHIFT    0x00000001
#define	CRTC_MORE_CNTL__CRTC_AUTO_HORZ_CENTER_EN__SHIFT    0x00000002
#define	CRTC_MORE_CNTL__CRTC_AUTO_VERT_CENTER_EN__SHIFT    0x00000003
#define	CRTC_MORE_CNTL__CRTC_H_CUTOFF_ACTIVE_EN__SHIFT     0x00000004
#define	CRTC_MORE_CNTL__CRTC_V_CUTOFF_ACTIVE_EN__SHIFT     0x00000005
#define	CRTC_MORE_CNTL__FORCE_H_EVEN_PIXEL_COUNT__SHIFT    0x00000006
#define	CRTC_MORE_CNTL__RMX_H_FILT_COEFFICIENT__SHIFT      0x00000018
#define	CRTC_MORE_CNTL__RMX_H_FILTER_EN__SHIFT             0x0000001b
#define	CRTC_MORE_CNTL__RMX_V_FILT_COEFFICIENT__SHIFT      0x0000001c
#define	CRTC_MORE_CNTL__RMX_V_FILTER_EN__SHIFT             0x0000001f

// DAC_EXT_CNTL
#define	DAC_EXT_CNTL__DAC2_FORCE_BLANK_OFF_EN__SHIFT       0x00000000
#define	DAC_EXT_CNTL__DAC2_FORCE_DATA_EN__SHIFT            0x00000001
#define	DAC_EXT_CNTL__DAC_FORCE_BLANK_OFF_EN__SHIFT        0x00000004
#define	DAC_EXT_CNTL__DAC_FORCE_DATA_EN__SHIFT             0x00000005
#define	DAC_EXT_CNTL__DAC_FORCE_DATA_SEL__SHIFT            0x00000006
#define	DAC_EXT_CNTL__DAC_FORCE_DATA__SHIFT                0x00000008

// FP_GEN_CNTL
#define	FP_GEN_CNTL__FP_ON__SHIFT                          0x00000000
#define	FP_GEN_CNTL__FP_BLANK_EN__SHIFT                    0x00000001
#define	FP_GEN_CNTL__TMDS_EN__SHIFT                        0x00000002
#define	FP_GEN_CNTL__PANEL_FORMAT__SHIFT                   0x00000003
#define	FP_GEN_CNTL__NO_OF_GREY__SHIFT                     0x00000004
#define	FP_GEN_CNTL__FP_RST_FM__SHIFT                      0x00000006
#define	FP_GEN_CNTL__FP_EN_TMDS__SHIFT                     0x00000007
#define	FP_GEN_CNTL__FP_DETECT_SENSE__SHIFT                0x00000008
#define	FP_GEN_CNTL__FP_DETECT_INT_POL__SHIFT              0x00000009
#define	FP_GEN_CNTL__FP_DETECT_EN__SHIFT                   0x0000000c
#define	FP_GEN_CNTL__FP_SRC_SEL__SHIFT                     0x0000000d
#define	FP_GEN_CNTL__FP_USE_VGA_HVSYNC__SHIFT              0x0000000e
#define	FP_GEN_CNTL__FP_USE_VGA_SYNC_POLARITY__SHIFT       0x0000000f
#define	FP_GEN_CNTL__CRTC_DONT_SHADOW_VPAR__SHIFT          0x00000010
#define	FP_GEN_CNTL__CRTC_DONT_SHADOW_HEND__SHIFT          0x00000011
#define	FP_GEN_CNTL__CRTC_USE_SHADOWED_VEND__SHIFT         0x00000012
#define	FP_GEN_CNTL__CRTC_USE_SHADOWED_ROWCUR__SHIFT       0x00000013
#define	FP_GEN_CNTL__RMX_HVSYNC_CONTROL_EN__SHIFT          0x00000014
#define	FP_GEN_CNTL__DFP_SYNC_SEL__SHIFT                   0x00000015
#define	FP_GEN_CNTL__CRTC_LOCK_8DOT__SHIFT                 0x00000016
#define	FP_GEN_CNTL__CRT_SYNC_SEL__SHIFT                   0x00000017
#define	FP_GEN_CNTL__FP_USE_SHADOW_EN__SHIFT               0x00000018
#define	FP_GEN_CNTL__DONT_RST_CHAREN__SHIFT                0x00000019
#define	FP_GEN_CNTL__CRT_SYNC_ALT_SEL__SHIFT               0x0000001a
#define	FP_GEN_CNTL__CRTC_USE_NONSHADOW_HPARAMS_FOR_BLANK__SHIFT 0x0000001b
#define	FP_GEN_CNTL__CRTC_USE_NONSHADOW_VPARAMS_FOR_BLANK__SHIFT 0x0000001c
#define	FP_GEN_CNTL__CRTC_VGA_XOVERSCAN_COLOR__SHIFT       0x0000001d
#define	FP_GEN_CNTL__CRTC_VGA_XOVERSCAN_DIVBY2_EN__SHIFT   0x0000001e

// FP2_GEN_CNTL
#define	FP2_GEN_CNTL__FP2_BLANK_EN__SHIFT                  0x00000001
#define	FP2_GEN_CNTL__FP2_ON__SHIFT                        0x00000002
#define	FP2_GEN_CNTL__FP2_PANEL_FORMAT__SHIFT              0x00000003
#define	FP2_GEN_CNTL__FP2_NO_OF_GREY__SHIFT                0x00000004
#define	FP2_GEN_CNTL__FP2_RST_FM__SHIFT                    0x00000006
#define	FP2_GEN_CNTL__FP2_DETECT_SENSE__SHIFT              0x00000008
#define	FP2_GEN_CNTL__FP2_DETECT_INT_POL__SHIFT            0x00000009
#define	FP2_GEN_CNTL__FP2_SRC_SEL__SHIFT                   0x0000000d
#define	FP2_GEN_CNTL__FP2_FP_POL__SHIFT                    0x00000010
#define	FP2_GEN_CNTL__FP2_LP_POL__SHIFT                    0x00000011
#define	FP2_GEN_CNTL__FP2_SCK_POL__SHIFT                   0x00000012
#define	FP2_GEN_CNTL__FP2_LCD_CNTL__SHIFT                  0x00000013
#define	FP2_GEN_CNTL__FP2_PAD_FLOP_EN__SHIFT               0x00000016
#define	FP2_GEN_CNTL__FP2_CRC_EN__SHIFT                    0x00000017
#define	FP2_GEN_CNTL__FP2_CRC_READ_EN__SHIFT               0x00000018
#define	FP2_GEN_CNTL__FP2_B_ON__SHIFT                      0x00000019

// FP_HORZ_STRETCH
#define	FP_HORZ_STRETCH__FP_HORZ_STRETCH_RATIO__SHIFT      0x00000000
#define	FP_HORZ_STRETCH__FP_HORZ_PANEL_SIZE__SHIFT         0x00000010
#define	FP_HORZ_STRETCH__FP_HORZ_STRETCH_EN__SHIFT         0x00000019
#define	FP_HORZ_STRETCH__FP_HORZ_STRETCH_MODE__SHIFT       0x0000001a
#define	FP_HORZ_STRETCH__FP_AUTO_HORZ_RATIO__SHIFT         0x0000001b
#define	FP_HORZ_STRETCH__FP_LOOP_STRETCH__SHIFT            0x0000001c
#define	FP_HORZ_STRETCH__RMX_AUTO_RATIO_HORZ_INC__SHIFT    0x0000001f

// FP_VERT_STRETCH
#define	FP_VERT_STRETCH__FP_VERT_STRETCH_RATIO__SHIFT      0x00000000
#define	FP_VERT_STRETCH__FP_VERT_PANEL_SIZE__SHIFT         0x0000000c
#define	FP_VERT_STRETCH__FP_VERT_STRETCH_EN__SHIFT         0x00000019
#define	FP_VERT_STRETCH__FP_VERT_STRETCH_MODE__SHIFT       0x0000001a
#define	FP_VERT_STRETCH__FP_AUTO_VERT_RATIO__SHIFT         0x0000001b
#define	FP_VERT_STRETCH__RMX_H_FILTER_INIT__SHIFT          0x0000001c
#define	FP_VERT_STRETCH__RMX_V_FILTER_INIT__SHIFT          0x0000001d
#define	FP_VERT_STRETCH__RMX_AUTO_RATIO_VERT_INC__SHIFT    0x0000001f

// TMDS_CNTL
#define	TMDS_CNTL__TMDS_CTL0__SHIFT                        0x00000000
#define	TMDS_CNTL__TMDS_CTL1__SHIFT                        0x00000001
#define	TMDS_CNTL__TMDS_CTL2__SHIFT                        0x00000002
#define	TMDS_CNTL__TMDS_CTL3__SHIFT                        0x00000003
#define	TMDS_CNTL__TMDS_DEBUG_HSYNC__SHIFT                 0x00000004
#define	TMDS_CNTL__TMDS_DEBUG_VSYNC__SHIFT                 0x00000005
#define	TMDS_CNTL__TMDS_DEBUG_DE__SHIFT                    0x00000006
#define	TMDS_CNTL__TMDS_DEBUG_EN__SHIFT                    0x00000007
#define	TMDS_CNTL__TMDS_CTL_FB_SEL__SHIFT                  0x00000008
#define	TMDS_CNTL__TMDS_CTL_FB_DEL__SHIFT                  0x0000000a
#define	TMDS_CNTL__TMDS_STEREOSYNC_CTL_SEL__SHIFT          0x0000000c
#define	TMDS_CNTL__TMDS_SYNC_CHAR_EN__SHIFT                0x00000010
#define	TMDS_CNTL__TMDS_SYNC_CONT__SHIFT                   0x00000018
#define	TMDS_CNTL__TMDS_DPCUM_TST__SHIFT                   0x00000019
#define	TMDS_CNTL__TMDS_DPCUM_IN__SHIFT                    0x0000001a
#define	TMDS_CNTL__TMDS_CRC_EN__SHIFT                      0x0000001e
#define	TMDS_CNTL__TMDS_RB_SWITCH_EN__SHIFT                0x0000001f

// TMDS_SYNC_CHAR_SETA
#define	TMDS_SYNC_CHAR_SETA__TMDS_SYNC_CHAR0__SHIFT        0x00000000
#define	TMDS_SYNC_CHAR_SETA__TMDS_SYNC_CHAR1__SHIFT        0x00000010

// TMDS_SYNC_CHAR_SETB
#define	TMDS_SYNC_CHAR_SETB__TMDS_SYNC_CHAR2__SHIFT        0x00000000
#define	TMDS_SYNC_CHAR_SETB__TMDS_SYNC_CHAR3__SHIFT        0x00000010

// TMDS_CRC
#define	TMDS_CRC__TMDS_CRCRGB__SHIFT                       0x00000000

// TMDS_TRANSMITTER_CNTL
#define	TMDS_TRANSMITTER_CNTL__TMDS_PLLEN__SHIFT           0x00000000
#define	TMDS_TRANSMITTER_CNTL__TMDS_PLLRST__SHIFT          0x00000001
#define	TMDS_TRANSMITTER_CNTL__TMDS_MODE_SEL__SHIFT        0x00000002
#define	TMDS_TRANSMITTER_CNTL__TMDS_REGSEL__SHIFT          0x00000004
#define	TMDS_TRANSMITTER_CNTL__TMDS_HALF_CLK_RST__SHIFT    0x00000006
#define	TMDS_TRANSMITTER_CNTL__TMDS_RAN_PAT_RST__SHIFT     0x00000007
#define	TMDS_TRANSMITTER_CNTL__TMDS_TSTPIX__SHIFT          0x00000008
#define	TMDS_TRANSMITTER_CNTL__TMDS_REG__SHIFT             0x00000012
#define	TMDS_TRANSMITTER_CNTL__ICHCSEL__SHIFT              0x0000001c
#define	TMDS_TRANSMITTER_CNTL__ITCLKSEL__SHIFT             0x0000001d
#define	TMDS_TRANSMITTER_CNTL__TMDS_RAN_PAT_SEL__SHIFT     0x0000001e

// TMDS_PLL_CNTL
#define	TMDS_PLL_CNTL__TMDS_PLLPCP__SHIFT                  0x00000000
#define	TMDS_PLL_CNTL__TMDS_PLLPVG__SHIFT                  0x00000003
#define	TMDS_PLL_CNTL__TMDS_PLLPDC__SHIFT                  0x00000006
#define	TMDS_PLL_CNTL__TMDS_PLLPVS__SHIFT                  0x00000008

// TMDS_PATTERN_GEN_SEED
#define	TMDS_PATTERN_GEN_SEED__PATTERN_SEED__SHIFT         0x00000000

// ICON_OFFSET
#define	ICON_OFFSET__ICON_OFFSET__SHIFT                    0x00000000
#define	ICON_OFFSET__BLANK_SCREEN1__SHIFT                  0x0000001b
#define	ICON_OFFSET__DONT_DS_ICON__SHIFT                   0x0000001c
#define	ICON_OFFSET__ICON_LOCK__SHIFT                      0x0000001f

// ICON_HORZ_VERT_POSN
#define	ICON_HORZ_VERT_POSN__ICON_VERT_POSN__SHIFT         0x00000000
#define	ICON_HORZ_VERT_POSN__ICON_HORZ_POSN__SHIFT         0x00000010
#define	ICON_HORZ_VERT_POSN__ICON_LOCK__SHIFT              0x0000001f

// ICON_HORZ_VERT_OFF
#define	ICON_HORZ_VERT_OFF__ICON_VERT_OFF__SHIFT           0x00000000
#define	ICON_HORZ_VERT_OFF__ICON_HORZ_OFF__SHIFT           0x00000010
#define	ICON_HORZ_VERT_OFF__ICON_LOCK__SHIFT               0x0000001f

// ICON_CLR0
#define	ICON_CLR0__ICON_CLR0_B__SHIFT                      0x00000000
#define	ICON_CLR0__ICON_CLR0_G__SHIFT                      0x00000008
#define	ICON_CLR0__ICON_CLR0_R__SHIFT                      0x00000010

// ICON_CLR1
#define	ICON_CLR1__ICON_CLR1_B__SHIFT                      0x00000000
#define	ICON_CLR1__ICON_CLR1_G__SHIFT                      0x00000008
#define	ICON_CLR1__ICON_CLR1_R__SHIFT                      0x00000010

// FP_H_SYNC_STRT_WID
#define	FP_H_SYNC_STRT_WID__FP_H_SYNC_STRT_PIX__SHIFT      0x00000000
#define	FP_H_SYNC_STRT_WID__FP_H_SYNC_STRT_CHAR__SHIFT     0x00000003
#define	FP_H_SYNC_STRT_WID__FP_H_SYNC_WID__SHIFT           0x00000010
#define	FP_H_SYNC_STRT_WID__FP_H_SYNC_POL__SHIFT           0x00000017

// FP_V_SYNC_STRT_WID
#define	FP_V_SYNC_STRT_WID__FP_V_SYNC_STRT__SHIFT          0x00000000
#define	FP_V_SYNC_STRT_WID__FP_V_SYNC_WID__SHIFT           0x00000010
#define	FP_V_SYNC_STRT_WID__FP_V_SYNC_POL__SHIFT           0x00000017

// LVDS_DIGTMDS_CRC
#define	LVDS_DIGTMDS_CRC__LVDS_CRC_SIG_RGB__SHIFT          0x00000000
#define	LVDS_DIGTMDS_CRC__LVDS_CRC_SIG_C__SHIFT            0x00000018

// LVDS_GEN_CNTL
#define	LVDS_GEN_CNTL__LVDS_ON__SHIFT                      0x00000000
#define	LVDS_GEN_CNTL__LVDS_DISPLAY_DIS__SHIFT             0x00000001
#define	LVDS_GEN_CNTL__LVDS_PANEL_TYPE__SHIFT              0x00000002
#define	LVDS_GEN_CNTL__LVDS_PANEL_FORMAT__SHIFT            0x00000003
#define	LVDS_GEN_CNTL__LVDS_NO_OF_GREY__SHIFT              0x00000004
#define	LVDS_GEN_CNTL__LVDS_RST_FM__SHIFT                  0x00000006
#define	LVDS_GEN_CNTL__LVDS_EN__SHIFT                      0x00000007
#define	LVDS_GEN_CNTL__LVDS_BL_MOD_LEVEL__SHIFT            0x00000008
#define	LVDS_GEN_CNTL__LVDS_BL_MOD_EN__SHIFT               0x00000010
#define	LVDS_GEN_CNTL__LVDS_BL_CLK_SEL__SHIFT              0x00000011
#define	LVDS_GEN_CNTL__LVDS_DIGON__SHIFT                   0x00000012
#define	LVDS_GEN_CNTL__LVDS_BLON__SHIFT                    0x00000013
#define	LVDS_GEN_CNTL__LVDS_FP_POL__SHIFT                  0x00000014
#define	LVDS_GEN_CNTL__LVDS_LP_POL__SHIFT                  0x00000015
#define	LVDS_GEN_CNTL__LVDS_DTM_POL__SHIFT                 0x00000016
#define	LVDS_GEN_CNTL__LVDS_SRC_SEL__SHIFT                 0x00000017
#define	LVDS_GEN_CNTL__LVDS_RESERVED_BITS__SHIFT           0x00000018
#define	LVDS_GEN_CNTL__LVDS_FPDI_EN__SHIFT                 0x0000001b
#define	LVDS_GEN_CNTL__LVDS_HSYNC_DELAY__SHIFT             0x0000001c

// LVDS_PLL_CNTL
#define	LVDS_PLL_CNTL__LVDS_CRC_DE_ONLY__SHIFT             0x00000000
#define	LVDS_PLL_CNTL__LVDS_LVPVS__SHIFT                   0x00000001
#define	LVDS_PLL_CNTL__LVDS_LPPVG__SHIFT                   0x00000005
#define	LVDS_PLL_CNTL__LVDS_LPPDC__SHIFT                   0x00000008
#define	LVDS_PLL_CNTL__LVDS_LPPCP__SHIFT                   0x0000000a
#define	LVDS_PLL_CNTL__LVDS_SS_DISP_EN__SHIFT              0x0000000d
#define	LVDS_PLL_CNTL__LVDS_PRG__SHIFT                     0x0000000e
#define	LVDS_PLL_CNTL__LVDS_PLL_EN__SHIFT                  0x00000010
#define	LVDS_PLL_CNTL__LVDS_PLL_RESET__SHIFT               0x00000011
#define	LVDS_PLL_CNTL__LVDS_CRC_EN__SHIFT                  0x00000014
#define	LVDS_PLL_CNTL__LVDS_CRC_UP24__SHIFT                0x00000015
#define	LVDS_PLL_CNTL__LVDS_TEST_DATA_OUT__SHIFT           0x00000016
#define	LVDS_PLL_CNTL__LVDS_TEST_DATA_SEL__SHIFT           0x00000019
#define	LVDS_PLL_CNTL__LCDENG_TEST_MODE__SHIFT             0x0000001c

// AUX_WINDOW_HORZ_CNTL
#define	AUX_WINDOW_HORZ_CNTL__AUX_WIN_HORZ_START__SHIFT    0x00000000
#define	AUX_WINDOW_HORZ_CNTL__AUX_WIN_HORZ_END__SHIFT      0x0000000c
#define	AUX_WINDOW_HORZ_CNTL__AUX_WIN_EN__SHIFT            0x00000018
#define	AUX_WINDOW_HORZ_CNTL__AUX_WIN_OUT_DELAY__SHIFT     0x00000019
#define	AUX_WINDOW_HORZ_CNTL__RESERVED__SHIFT              0x0000001e
#define	AUX_WINDOW_HORZ_CNTL__AUX_WIN_LOCK__SHIFT          0x0000001f

// AUX_WINDOW_VERT_CNTL
#define	AUX_WINDOW_VERT_CNTL__AUX_WIN_VERT_START__SHIFT    0x00000000
#define	AUX_WINDOW_VERT_CNTL__AUX_WIN_VERT_END__SHIFT      0x00000010
#define	AUX_WINDOW_VERT_CNTL__AUX_WINDOW_POL__SHIFT        0x0000001e
#define	AUX_WINDOW_VERT_CNTL__AUX_WIN_LOCK__SHIFT          0x0000001f

// DVI_I2C_CNTL_0
#define	DVI_I2C_CNTL_0__I2C_DONE__SHIFT                    0x00000000
#define	DVI_I2C_CNTL_0__I2C_NACK__SHIFT                    0x00000001
#define	DVI_I2C_CNTL_0__I2C_HALT__SHIFT                    0x00000002
#define	DVI_I2C_CNTL_0__I2C_SOFT_RST__SHIFT                0x00000005
#define	DVI_I2C_CNTL_0__I2C_DRIVE_EN__SHIFT                0x00000006
#define	DVI_I2C_CNTL_0__I2C_DRIVE_SEL__SHIFT               0x00000007
#define	DVI_I2C_CNTL_0__I2C_START__SHIFT                   0x00000008
#define	DVI_I2C_CNTL_0__I2C_STOP__SHIFT                    0x00000009
#define	DVI_I2C_CNTL_0__I2C_RECEIVE__SHIFT                 0x0000000a
#define	DVI_I2C_CNTL_0__I2C_ABORT__SHIFT                   0x0000000b
#define	DVI_I2C_CNTL_0__I2C_GO__SHIFT                      0x0000000c
#define	DVI_I2C_CNTL_0__SW_WANTS_TO_USE_DVI_I2C__SHIFT     0x0000000d
#define	DVI_I2C_CNTL_0__SW_CAN_USE_DVI_I2C__SHIFT          0x0000000d
#define	DVI_I2C_CNTL_0__SW_DONE_USING_DVI_I2C__SHIFT       0x0000000e
#define	DVI_I2C_CNTL_0__HW_NEEDS_DVI_I2C__SHIFT            0x0000000e
#define	DVI_I2C_CNTL_0__ABORT_HW_DVI_I2C__SHIFT            0x0000000f
#define	DVI_I2C_CNTL_0__HW_USING_DVI_I2C__SHIFT            0x0000000f
#define	DVI_I2C_CNTL_0__I2C_PRESCALE__SHIFT                0x00000010

// DVI_I2C_CNTL_1
#define	DVI_I2C_CNTL_1__I2C_DATA_COUNT__SHIFT              0x00000000
#define	DVI_I2C_CNTL_1__I2C_ADDR_COUNT__SHIFT              0x00000008
#define	DVI_I2C_CNTL_1__I2C_SEL__SHIFT                     0x00000010
#define	DVI_I2C_CNTL_1__I2C_EN__SHIFT                      0x00000011
#define	DVI_I2C_CNTL_1__I2C_TIME_LIMIT__SHIFT              0x00000018

// DVI_I2C_DATA
#define	DVI_I2C_DATA__I2C_DATA__SHIFT                      0x00000000

// LVDS_SS_GEN_CNTL
#define	LVDS_SS_GEN_CNTL__SS_EXT_EN__SHIFT                 0x00000001
#define	LVDS_SS_GEN_CNTL__SS_EXT_SEL__SHIFT                0x00000002
#define	LVDS_SS_GEN_CNTL__SS_BUF_EN__SHIFT                 0x00000003
#define	LVDS_SS_GEN_CNTL__SS_BUF_OFFSET__SHIFT             0x00000004
#define	LVDS_SS_GEN_CNTL__SS_BUF_RESET_EN__SHIFT           0x0000000b
#define	LVDS_SS_GEN_CNTL__SS_BUF_STRENGTH__SHIFT           0x0000000c
#define	LVDS_SS_GEN_CNTL__LVDSPWR_STRENGTH__SHIFT          0x0000000e
#define	LVDS_SS_GEN_CNTL__LVDS_PWRSEQ_DELAY1__SHIFT        0x00000010
#define	LVDS_SS_GEN_CNTL__LVDS_PWRSEQ_DELAY2__SHIFT        0x00000014
#define	LVDS_SS_GEN_CNTL__LVDS_CLK_PATTERN__SHIFT          0x00000018

// GRPH_BUFFER_CNTL
#define	GRPH_BUFFER_CNTL__GRPH_START_REQ__SHIFT            0x00000000
#define	GRPH_BUFFER_CNTL__GRPH_STOP_REQ__SHIFT             0x00000008
#define	GRPH_BUFFER_CNTL__GRPH_CRITICAL_POINT__SHIFT       0x00000010
#define	GRPH_BUFFER_CNTL__GRPH_CRITICAL_CNTL__SHIFT        0x0000001c
#define	GRPH_BUFFER_CNTL__GRPH_BUFFER_SIZE__SHIFT          0x0000001d
#define	GRPH_BUFFER_CNTL__GRPH_CRITICAL_AT_SOF__SHIFT      0x0000001e
#define	GRPH_BUFFER_CNTL__GRPH_STOP_CNTL__SHIFT            0x0000001f

// VGA_BUFFER_CNTL
#define	VGA_BUFFER_CNTL__VGA_START_REQ__SHIFT              0x00000000
#define	VGA_BUFFER_CNTL__VGA_STOP_REQ__SHIFT               0x00000008
#define	VGA_BUFFER_CNTL__VGA_CRITICAL_POINT__SHIFT         0x00000010

// LVDS_PWM_CNTL
#define	LVDS_PWM_CNTL__PWM_CLK_CONF_A5__SHIFT              0x00000000
#define	LVDS_PWM_CNTL__ENA_BL__SHIFT                       0x00000010
#define	LVDS_PWM_CNTL__LVDS_SWAP__SHIFT                    0x00000011
#define	LVDS_PWM_CNTL__LVDS_MACRO_CLK_SHIFT__SHIFT         0x00000012
#define	LVDS_PWM_CNTL__LVDS_2ND_CHAN_VS__SHIFT             0x00000013
#define	LVDS_PWM_CNTL__LVDS_2ND_CHAN_HS__SHIFT             0x00000014
#define	LVDS_PWM_CNTL__LVDS_2ND_CHAN_DE__SHIFT             0x00000015

// CRTC2_H_TOTAL_DISP
#define	CRTC2_H_TOTAL_DISP__CRTC2_H_TOTAL__SHIFT           0x00000000
#define	CRTC2_H_TOTAL_DISP__CRTC2_H_DISP__SHIFT            0x00000010

// CRTC2_H_SYNC_STRT_WID
#define	CRTC2_H_SYNC_STRT_WID__CRTC2_H_SYNC_STRT_PIX__SHIFT 0x00000000
#define	CRTC2_H_SYNC_STRT_WID__CRTC2_H_SYNC_STRT_CHAR__SHIFT 0x00000003
#define	CRTC2_H_SYNC_STRT_WID__CRTC2_H_SYNC_WID__SHIFT     0x00000010
#define	CRTC2_H_SYNC_STRT_WID__CRTC2_H_SYNC_POL__SHIFT     0x00000017

// CRTC2_V_TOTAL_DISP
#define	CRTC2_V_TOTAL_DISP__CRTC2_V_TOTAL__SHIFT           0x00000000
#define	CRTC2_V_TOTAL_DISP__CRTC2_V_DISP__SHIFT            0x00000010

// CRTC2_V_SYNC_STRT_WID
#define	CRTC2_V_SYNC_STRT_WID__CRTC2_V_SYNC_STRT__SHIFT    0x00000000
#define	CRTC2_V_SYNC_STRT_WID__CRTC2_V_SYNC_WID__SHIFT     0x00000010
#define	CRTC2_V_SYNC_STRT_WID__CRTC2_V_SYNC_POL__SHIFT     0x00000017

// CRTC2_VLINE_CRNT_VLINE
#define	CRTC2_VLINE_CRNT_VLINE__CRTC2_VLINE__SHIFT         0x00000000
#define	CRTC2_VLINE_CRNT_VLINE__CRTC2_CRNT_VLINE__SHIFT    0x00000010

// CRTC2_CRNT_FRAME
#define	CRTC2_CRNT_FRAME__CRTC2_CRNT_FRAME__SHIFT          0x00000000

// CRTC2_GUI_TRIG_VLINE
#define	CRTC2_GUI_TRIG_VLINE__CRTC2_GUI_TRIG_VLINE_START__SHIFT 0x00000000
#define	CRTC2_GUI_TRIG_VLINE__CRTC2_GUI_TRIG_VLINE_INV__SHIFT 0x0000000f
#define	CRTC2_GUI_TRIG_VLINE__CRTC2_GUI_TRIG_VLINE_END__SHIFT 0x00000010
#define	CRTC2_GUI_TRIG_VLINE__CRTC2_GUI_TRIG_VLINE_STALL__SHIFT 0x0000001e
#define	CRTC2_GUI_TRIG_VLINE__CRTC2_GUI_TRIG_VLINE__SHIFT  0x0000001f

// CRTC2_DEBUG
#define	CRTC2_DEBUG__CRTC2_GUI_TRIG_BYPASS_EN__SHIFT       0x00000000
#define	CRTC2_DEBUG__CRTC2_GUI_TRIG_VLINE_BYPASS__SHIFT    0x00000001
#define	CRTC2_DEBUG__CRTC2_GUI_TRIG_OFFSET_BYPASS__SHIFT   0x00000002
#define	CRTC2_DEBUG__CRTC2_GUI_TRIG_PITCH_ADD_BYPASS__SHIFT 0x00000003

// CRTC2_OFFSET
#define	CRTC2_OFFSET__CRTC2_OFFSET__SHIFT                  0x00000000
#define	CRTC2_OFFSET__CRTC2_GUI_TRIG_OFFSET__SHIFT         0x0000001e
#define	CRTC2_OFFSET__CRTC2_OFFSET_LOCK__SHIFT             0x0000001f

// CRTC2_OFFSET_CNTL
#define	CRTC2_OFFSET_CNTL__CRTC2_TILE_LINE__SHIFT          0x00000000
#define	CRTC2_OFFSET_CNTL__CRTC2_TILE_EN__SHIFT            0x0000000f
#define	CRTC2_OFFSET_CNTL__CRTC2_OFFSET_FLIP_CNTL__SHIFT   0x00000010
#define	CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET_LEFT_EN__SHIFT 0x0000001c
#define	CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET__SHIFT    0x0000001e
#define	CRTC2_OFFSET_CNTL__CRTC2_OFFSET_LOCK__SHIFT        0x0000001f

// CRTC2_PITCH
#define	CRTC2_PITCH__CRTC2_PITCH__SHIFT                    0x00000000

// OVR2_CLR
#define	OVR2_CLR__OVR2_CLR_B__SHIFT                        0x00000000
#define	OVR2_CLR__OVR2_CLR_G__SHIFT                        0x00000008
#define	OVR2_CLR__OVR2_CLR_R__SHIFT                        0x00000010

// OVR2_WID_LEFT_RIGHT
#define	OVR2_WID_LEFT_RIGHT__OVR2_WID_RIGHT__SHIFT         0x00000000
#define	OVR2_WID_LEFT_RIGHT__OVR2_WID_LEFT__SHIFT          0x00000010

// OVR2_WID_TOP_BOTTOM
#define	OVR2_WID_TOP_BOTTOM__OVR2_WID_BOTTOM__SHIFT        0x00000000
#define	OVR2_WID_TOP_BOTTOM__OVR2_WID_TOP__SHIFT           0x00000010

// CRTC2_DISPLAY_BASE_ADDR
#define	CRTC2_DISPLAY_BASE_ADDR__CRTC2_DISPLAY_BASE_ADDR__SHIFT 0x00000000

// SNAPSHOT2_VH_COUNTS
#define	SNAPSHOT2_VH_COUNTS__SNAPSHOT2_HCOUNT__SHIFT       0x00000000
#define	SNAPSHOT2_VH_COUNTS__SNAPSHOT2_VCOUNT__SHIFT       0x00000010

// SNAPSHOT2_F_COUNT
#define	SNAPSHOT2_F_COUNT__SNAPSHOT2_F_COUNT__SHIFT        0x00000000

// N_VIF2_COUNT
#define	N_VIF2_COUNT__N_VIF2_COUNT_VAL__SHIFT              0x00000000
#define	N_VIF2_COUNT__GENLOCK2_SOURCE_SEL__SHIFT           0x0000001f

// SNAPSHOT2_VIF_COUNT
#define	SNAPSHOT2_VIF_COUNT__LSNAPSHOT2_VIF_COUNT__SHIFT   0x00000000
#define	SNAPSHOT2_VIF_COUNT__USNAPSHOT2_VIF_COUNT__SHIFT   0x0000000a
#define	SNAPSHOT2_VIF_COUNT__AUTO_SNAPSHOT2_TAKEN_RD__SHIFT 0x00000018
#define	SNAPSHOT2_VIF_COUNT__AUTO_SNAPSHOT2_TAKEN_WR__SHIFT 0x00000018
#define	SNAPSHOT2_VIF_COUNT__MANUAL_SNAPSHOT2_NOW__SHIFT   0x00000019

// LVDS_DSTN_CNTL1
#define	LVDS_DSTN_CNTL1__LVDS_PANEL_TYPE__SHIFT            0x00000000
#define	LVDS_DSTN_CNTL1__LVDS_PANEL_FORMAT__SHIFT          0x00000002
#define	LVDS_DSTN_CNTL1__LVDS_NO_OF_GREY__SHIFT            0x00000004
#define	LVDS_DSTN_CNTL1__SCK_POL__SHIFT                    0x00000007
#define	LVDS_DSTN_CNTL1__INVERSE_VIDEO__SHIFT              0x00000008
#define	LVDS_DSTN_CNTL1__BIASON__SHIFT                     0x00000009
#define	LVDS_DSTN_CNTL1__XBUF_SIZE__SHIFT                  0x0000000a
#define	LVDS_DSTN_CNTL1__SCLK_DELAY__SHIFT                 0x0000000e
#define	LVDS_DSTN_CNTL1__HFB_TEST_MODE__SHIFT              0x00000012
#define	LVDS_DSTN_CNTL1__VERT_PANEL_SIZE__SHIFT            0x00000013
#define	LVDS_DSTN_CNTL1__USE_AUTO_FP_POS__SHIFT            0x0000001f

// LVDS_DSTN_CNTL2
#define	LVDS_DSTN_CNTL2__BIAS_MODE_EN__SHIFT               0x00000000
#define	LVDS_DSTN_CNTL2__BIAS_MODE_LEVEL__SHIFT            0x00000001
#define	LVDS_DSTN_CNTL2__LVDS_PWRSEQ_DELAY3__SHIFT         0x00000009
#define	LVDS_DSTN_CNTL2__LOWER_PANEL_VPOS__SHIFT           0x0000000d
#define	LVDS_DSTN_CNTL2__LH_POS_ADJUST__SHIFT              0x00000019
#define	LVDS_DSTN_CNTL2__DSTNFIFO_BURST__SHIFT             0x0000001b

// LVDS_DSTN_CNTL3
#define	LVDS_DSTN_CNTL3__XBUF_BASE__SHIFT                  0x00000000
#define	LVDS_DSTN_CNTL3__FP_POS__SHIFT                     0x00000011
#define	LVDS_DSTN_CNTL3__DEBUG0__SHIFT                     0x0000001d

// CUR2_OFFSET
#define	CUR2_OFFSET__CUR2_OFFSET__SHIFT                    0x00000000
#define	CUR2_OFFSET__CUR2_LOCK__SHIFT                      0x0000001f

// CUR2_HORZ_VERT_POSN
#define	CUR2_HORZ_VERT_POSN__CUR2_VERT_POSN__SHIFT         0x00000000
#define	CUR2_HORZ_VERT_POSN__CUR2_HORZ_POSN__SHIFT         0x00000010
#define	CUR2_HORZ_VERT_POSN__CUR2_LOCK__SHIFT              0x0000001f

// CUR2_HORZ_VERT_OFF
#define	CUR2_HORZ_VERT_OFF__CUR2_VERT_OFF__SHIFT           0x00000000
#define	CUR2_HORZ_VERT_OFF__CUR2_HORZ_OFF__SHIFT           0x00000010
#define	CUR2_HORZ_VERT_OFF__CUR2_LOCK__SHIFT               0x0000001f

// CUR2_CLR0
#define	CUR2_CLR0__CUR2_CLR0_B__SHIFT                      0x00000000
#define	CUR2_CLR0__CUR2_CLR0_G__SHIFT                      0x00000008
#define	CUR2_CLR0__CUR2_CLR0_R__SHIFT                      0x00000010

// CUR2_CLR1
#define	CUR2_CLR1__CUR2_CLR1_B__SHIFT                      0x00000000
#define	CUR2_CLR1__CUR2_CLR1_G__SHIFT                      0x00000008
#define	CUR2_CLR1__CUR2_CLR1_R__SHIFT                      0x00000010

// FP_H2_SYNC_STRT_WID
#define	FP_H2_SYNC_STRT_WID__FP_H2_SYNC_STRT_PIX__SHIFT    0x00000000
#define	FP_H2_SYNC_STRT_WID__FP_H2_SYNC_STRT_CHAR__SHIFT   0x00000003
#define	FP_H2_SYNC_STRT_WID__FP_H2_SYNC_WID__SHIFT         0x00000010
#define	FP_H2_SYNC_STRT_WID__FP_H2_SYNC_POL__SHIFT         0x00000017

// FP_V2_SYNC_STRT_WID
#define	FP_V2_SYNC_STRT_WID__FP_V2_SYNC_STRT__SHIFT        0x00000000
#define	FP_V2_SYNC_STRT_WID__FP_V2_SYNC_WID__SHIFT         0x00000010
#define	FP_V2_SYNC_STRT_WID__FP_V2_SYNC_POL__SHIFT         0x00000017

// ICON2_OFFSET
#define	ICON2_OFFSET__ICON2_OFFSET__SHIFT                  0x00000000
#define	ICON2_OFFSET__BLANK_SCREEN2__SHIFT                 0x0000001b
#define	ICON2_OFFSET__DONT_DS_ICON2__SHIFT                 0x0000001c
#define	ICON2_OFFSET__ICON2_LOCK__SHIFT                    0x0000001f

// ICON2_HORZ_VERT_POSN
#define	ICON2_HORZ_VERT_POSN__ICON2_VERT_POSN__SHIFT       0x00000000
#define	ICON2_HORZ_VERT_POSN__ICON2_HORZ_POSN__SHIFT       0x00000010
#define	ICON2_HORZ_VERT_POSN__ICON2_LOCK__SHIFT            0x0000001f

// ICON2_HORZ_VERT_OFF
#define	ICON2_HORZ_VERT_OFF__ICON2_VERT_OFF__SHIFT         0x00000000
#define	ICON2_HORZ_VERT_OFF__ICON2_HORZ_OFF__SHIFT         0x00000010
#define	ICON2_HORZ_VERT_OFF__ICON2_LOCK__SHIFT             0x0000001f

// ICON2_CLR0
#define	ICON2_CLR0__ICON2_CLR0_B__SHIFT                    0x00000000
#define	ICON2_CLR0__ICON2_CLR0_G__SHIFT                    0x00000008
#define	ICON2_CLR0__ICON2_CLR0_R__SHIFT                    0x00000010

// ICON2_CLR1
#define	ICON2_CLR1__ICON2_CLR1_B__SHIFT                    0x00000000
#define	ICON2_CLR1__ICON2_CLR1_G__SHIFT                    0x00000008
#define	ICON2_CLR1__ICON2_CLR1_R__SHIFT                    0x00000010

// GRPH2_BUFFER_CNTL
#define	GRPH2_BUFFER_CNTL__GRPH2_START_REQ__SHIFT          0x00000000
#define	GRPH2_BUFFER_CNTL__GRPH2_STOP_REQ__SHIFT           0x00000008
#define	GRPH2_BUFFER_CNTL__GRPH2_CRITICAL_POINT__SHIFT     0x00000010
#define	GRPH2_BUFFER_CNTL__GRPH2_CRITICAL_CNTL__SHIFT      0x0000001c
#define	GRPH2_BUFFER_CNTL__GRPH2_BUFFER_SIZE__SHIFT        0x0000001d
#define	GRPH2_BUFFER_CNTL__GRPH2_CRITICAL_AT_SOF__SHIFT    0x0000001e
#define	GRPH2_BUFFER_CNTL__GRPH2_STOP_CNTL__SHIFT          0x0000001f

// CRTC2_GEN_CNTL
#define	CRTC2_GEN_CNTL__CRTC2_DBL_SCAN_EN__SHIFT           0x00000000
#define	CRTC2_GEN_CNTL__CRTC2_INTERLACE_EN__SHIFT          0x00000001
#define	CRTC2_GEN_CNTL__CRTC2_SYNC_TRISTATE__SHIFT         0x00000004
#define	CRTC2_GEN_CNTL__CRTC2_HSYNC_TRISTATE__SHIFT        0x00000005
#define	CRTC2_GEN_CNTL__CRTC2_VSYNC_TRISTATE__SHIFT        0x00000006
#define	CRTC2_GEN_CNTL__CRT2_ON__SHIFT                     0x00000007
#define	CRTC2_GEN_CNTL__CRTC2_PIX_WIDTH__SHIFT             0x00000008
#define	CRTC2_GEN_CNTL__CRTC2_ICON_EN__SHIFT               0x0000000f
#define	CRTC2_GEN_CNTL__CRTC2_CUR_EN__SHIFT                0x00000010
#define	CRTC2_GEN_CNTL__CRTC2_CUR_MODE__SHIFT              0x00000014
#define	CRTC2_GEN_CNTL__CRTC2_DISPLAY_DIS__SHIFT           0x00000017
#define	CRTC2_GEN_CNTL__CRTC2_EN__SHIFT                    0x00000019
#define	CRTC2_GEN_CNTL__CRTC2_DISP_REQ_EN_B__SHIFT         0x0000001a
#define	CRTC2_GEN_CNTL__CRTC2_C_SYNC_EN__SHIFT             0x0000001b
#define	CRTC2_GEN_CNTL__CRTC2_HSYNC_DIS__SHIFT             0x0000001c
#define	CRTC2_GEN_CNTL__CRTC2_VSYNC_DIS__SHIFT             0x0000001d

// CRTC2_STATUS
#define	CRTC2_STATUS__CRTC2_VBLANK_CUR__SHIFT              0x00000000
#define	CRTC2_STATUS__CRTC2_VBLANK_SAVE__SHIFT             0x00000001
#define	CRTC2_STATUS__CRTC2_VBLANK_SAVE_CLEAR__SHIFT       0x00000001
#define	CRTC2_STATUS__CRTC2_VLINE_SYNC__SHIFT              0x00000002
#define	CRTC2_STATUS__CRTC2_FRAME__SHIFT                   0x00000003

// OV0_Y_X_START
#define	OV0_Y_X_START__OV0_X_START__SHIFT                  0x00000000
#define	OV0_Y_X_START__OV0_Y_START__SHIFT                  0x00000010

// OV0_Y_X_END
#define	OV0_Y_X_END__OV0_X_END__SHIFT                      0x00000000
#define	OV0_Y_X_END__OV0_Y_END__SHIFT                      0x00000010

// OV0_PIPELINE_CNTL
#define	OV0_PIPELINE_CNTL__OV0_DISP_PIPE_DELAY__SHIFT      0x00000000

// OV0_REG_LOAD_CNTL
#define	OV0_REG_LOAD_CNTL__OV0_LOCK__SHIFT                 0x00000000
#define	OV0_REG_LOAD_CNTL__OV0_VBLANK_DURING_LOCK__SHIFT   0x00000001
#define	OV0_REG_LOAD_CNTL__OV0_STALL_GUI_UNTIL_FLIP__SHIFT 0x00000002
#define	OV0_REG_LOAD_CNTL__OV0_LOCK_READBACK__SHIFT        0x00000003
#define	OV0_REG_LOAD_CNTL__OV0_FLIP_READBACK__SHIFT        0x00000004

// OV0_SCALE_CNTL
#define	OV0_SCALE_CNTL__OV0_NO_READ_BEHIND_SCAN__SHIFT     0x00000001
#define	OV0_SCALE_CNTL__OV0_HORZ_PICK_NEAREST__SHIFT       0x00000002
#define	OV0_SCALE_CNTL__OV0_VERT_PICK_NEAREST__SHIFT       0x00000003
#define	OV0_SCALE_CNTL__OV0_SIGNED_UV__SHIFT               0x00000004
#define	OV0_SCALE_CNTL__OV0_GAMMA_SEL__SHIFT               0x00000005
#define	OV0_SCALE_CNTL__OV0_SURFACE_FORMAT__SHIFT          0x00000008
#define	OV0_SCALE_CNTL__OV0_ADAPTIVE_DEINT__SHIFT          0x0000000c
#define	OV0_SCALE_CNTL__OV0_CRTC_SEL__SHIFT                0x0000000e
#define	OV0_SCALE_CNTL__OV0_BURST_PER_PLANE__SHIFT         0x00000010
#define	OV0_SCALE_CNTL__OV0_DOUBLE_BUFFER_REGS__SHIFT      0x00000018
#define	OV0_SCALE_CNTL__OV0_BANDWIDTH__SHIFT               0x0000001a
#define	OV0_SCALE_CNTL__OV0_LIN_TRANS_BYPASS__SHIFT        0x0000001c
#define	OV0_SCALE_CNTL__OV0_INT_EMU__SHIFT                 0x0000001d
#define	OV0_SCALE_CNTL__OV0_OVERLAY_EN__SHIFT              0x0000001e
#define	OV0_SCALE_CNTL__OV0_SOFT_RESET__SHIFT              0x0000001f

// OV0_V_INC
#define	OV0_V_INC__OV0_V_INC__SHIFT                        0x00000008

// OV0_P1_V_ACCUM_INIT
#define	OV0_P1_V_ACCUM_INIT__OV0_P1_MAX_LN_IN_PER_LN_OUT__SHIFT 0x00000000
#define	OV0_P1_V_ACCUM_INIT__OV0_P1_V_ACCUM_INIT__SHIFT    0x0000000f

// OV0_P23_V_ACCUM_INIT
#define	OV0_P23_V_ACCUM_INIT__OV0_P23_MAX_LN_IN_PER_LN_OUT__SHIFT 0x00000000
#define	OV0_P23_V_ACCUM_INIT__OV0_P23_V_ACCUM_INIT__SHIFT  0x0000000f

// OV0_P1_BLANK_LINES_AT_TOP
#define	OV0_P1_BLANK_LINES_AT_TOP__OV0_P1_BLNK_LN_AT_TOP_M1__SHIFT 0x00000000
#define	OV0_P1_BLANK_LINES_AT_TOP__OV0_P1_ACTIVE_LINES_M1__SHIFT 0x00000010

// OV0_P23_BLANK_LINES_AT_TOP
#define	OV0_P23_BLANK_LINES_AT_TOP__OV0_P23_BLNK_LN_AT_TOP_M1__SHIFT 0x00000000
#define	OV0_P23_BLANK_LINES_AT_TOP__OV0_P23_ACTIVE_LINES_M1__SHIFT 0x00000010

// OV0_BASE_ADDR
#define	OV0_BASE_ADDR__OV0_BASE_ADDR__SHIFT                0x00000000

// OV0_VID_BUF0_BASE_ADRS
#define	OV0_VID_BUF0_BASE_ADRS__OV0_VID_BUF_PITCH_SEL__SHIFT 0x00000000
#define	OV0_VID_BUF0_BASE_ADRS__RESERVED_BIT1__SHIFT       0x00000001
#define	OV0_VID_BUF0_BASE_ADRS__OV0_VID_BUF_BASE_ADRS__SHIFT 0x00000004
#define	OV0_VID_BUF0_BASE_ADRS__RESERVED_BIT31_28__SHIFT   0x0000001c

// OV0_VID_BUF1_BASE_ADRS
#define	OV0_VID_BUF1_BASE_ADRS__OV0_VID_BUF_PITCH_SEL__SHIFT 0x00000000
#define	OV0_VID_BUF1_BASE_ADRS__RESERVED_BIT1__SHIFT       0x00000001
#define	OV0_VID_BUF1_BASE_ADRS__OV0_VID_BUF_BASE_ADRS__SHIFT 0x00000004
#define	OV0_VID_BUF1_BASE_ADRS__RESERVED_BIT31_28__SHIFT   0x0000001c

// OV0_VID_BUF2_BASE_ADRS
#define	OV0_VID_BUF2_BASE_ADRS__OV0_VID_BUF_PITCH_SEL__SHIFT 0x00000000
#define	OV0_VID_BUF2_BASE_ADRS__RESERVED_BIT1__SHIFT       0x00000001
#define	OV0_VID_BUF2_BASE_ADRS__OV0_VID_BUF_BASE_ADRS__SHIFT 0x00000004
#define	OV0_VID_BUF2_BASE_ADRS__RESERVED_BIT31_28__SHIFT   0x0000001c

// OV0_VID_BUF3_BASE_ADRS
#define	OV0_VID_BUF3_BASE_ADRS__OV0_VID_BUF_PITCH_SEL__SHIFT 0x00000000
#define	OV0_VID_BUF3_BASE_ADRS__RESERVED_BIT1__SHIFT       0x00000001
#define	OV0_VID_BUF3_BASE_ADRS__OV0_VID_BUF_BASE_ADRS__SHIFT 0x00000004
#define	OV0_VID_BUF3_BASE_ADRS__RESERVED_BIT31_28__SHIFT   0x0000001c

// OV0_VID_BUF4_BASE_ADRS
#define	OV0_VID_BUF4_BASE_ADRS__OV0_VID_BUF_PITCH_SEL__SHIFT 0x00000000
#define	OV0_VID_BUF4_BASE_ADRS__RESERVED_BIT1__SHIFT       0x00000001
#define	OV0_VID_BUF4_BASE_ADRS__OV0_VID_BUF_BASE_ADRS__SHIFT 0x00000004
#define	OV0_VID_BUF4_BASE_ADRS__RESERVED_BIT31_28__SHIFT   0x0000001c

// OV0_VID_BUF5_BASE_ADRS
#define	OV0_VID_BUF5_BASE_ADRS__OV0_VID_BUF_PITCH_SEL__SHIFT 0x00000000
#define	OV0_VID_BUF5_BASE_ADRS__RESERVED_BIT1__SHIFT       0x00000001
#define	OV0_VID_BUF5_BASE_ADRS__OV0_VID_BUF_BASE_ADRS__SHIFT 0x00000004
#define	OV0_VID_BUF5_BASE_ADRS__RESERVED_BIT31_28__SHIFT   0x0000001c

// OV0_VID_BUF_PITCH0_VALUE
#define	OV0_VID_BUF_PITCH0_VALUE__OV0_PITCH_VALUE__SHIFT   0x00000004
#define	OV0_VID_BUF_PITCH0_VALUE__OV0_PITCH_SKIP_LINES__SHIFT 0x0000001a
#define	OV0_VID_BUF_PITCH0_VALUE__OV0_PITCH_IN_TILES_LSBS__SHIFT 0x0000001c

// OV0_VID_BUF_PITCH1_VALUE
#define	OV0_VID_BUF_PITCH1_VALUE__OV0_PITCH_VALUE__SHIFT   0x00000004
#define	OV0_VID_BUF_PITCH1_VALUE__OV0_PITCH_SKIP_LINES__SHIFT 0x0000001a
#define	OV0_VID_BUF_PITCH1_VALUE__OV0_PITCH_IN_TILES_LSBS__SHIFT 0x0000001c

// OV0_AUTO_FLIP_CNTRL
#define	OV0_AUTO_FLIP_CNTRL__OV0_SOFT_BUF_NUM__SHIFT       0x00000000
#define	OV0_AUTO_FLIP_CNTRL__OV0_SOFT_REPEAT_FIELD__SHIFT  0x00000003
#define	OV0_AUTO_FLIP_CNTRL__OV0_SOFT_BUF_ODD__SHIFT       0x00000004
#define	OV0_AUTO_FLIP_CNTRL__OV0_IGNORE_REPEAT_FIELD__SHIFT 0x00000005
#define	OV0_AUTO_FLIP_CNTRL__OV0_SOFT_EOF_TOGGLE__SHIFT    0x00000006
#define	OV0_AUTO_FLIP_CNTRL__OV0_VID_PORT_SELECT__SHIFT    0x00000008
#define	OV0_AUTO_FLIP_CNTRL__OV0_P1_FIRST_LINE_EVEN__SHIFT 0x00000010
#define	OV0_AUTO_FLIP_CNTRL__OV0_SHIFT_EVEN_DOWN__SHIFT    0x00000012
#define	OV0_AUTO_FLIP_CNTRL__OV0_SHIFT_ODD_DOWN__SHIFT     0x00000013
#define	OV0_AUTO_FLIP_CNTRL__OV0_FIELD_POL_SOURCE__SHIFT   0x00000017

// OV0_DEINTERLACE_PATTERN
#define	OV0_DEINTERLACE_PATTERN__OV0_DEINT_PAT__SHIFT      0x00000000
#define	OV0_DEINTERLACE_PATTERN__OV0_DEINT_PAT_PNTR__SHIFT 0x00000018
#define	OV0_DEINTERLACE_PATTERN__OV0_DEINT_PAT_LEN_M1__SHIFT 0x0000001c

// OV0_SUBMIT_HISTORY
#define	OV0_SUBMIT_HISTORY__OV0_NEXT_BUF_NUM__SHIFT        0x00000000
#define	OV0_SUBMIT_HISTORY__OV0_NEXT_IS_ODD__SHIFT         0x00000004
#define	OV0_SUBMIT_HISTORY__OV0_CURR_BUF_NUM__SHIFT        0x00000008
#define	OV0_SUBMIT_HISTORY__OV0_CURR_IS_ODD__SHIFT         0x0000000c
#define	OV0_SUBMIT_HISTORY__OV0_PREV_BUF_NUM__SHIFT        0x00000010
#define	OV0_SUBMIT_HISTORY__OV0_PREV_IS_ODD__SHIFT         0x00000014

// OV0_H_INC
#define	OV0_H_INC__OV0_P1_H_INC__SHIFT                     0x00000000
#define	OV0_H_INC__OV0_P23_H_INC__SHIFT                    0x00000010

// OV0_STEP_BY
#define	OV0_STEP_BY__OV0_P1_H_STEP_BY__SHIFT               0x00000000
#define	OV0_STEP_BY__OV0_P1_PREDWNSC_RATIO__SHIFT          0x00000004
#define	OV0_STEP_BY__OV0_P23_H_STEP_BY__SHIFT              0x00000008
#define	OV0_STEP_BY__OV0_P23_PREDWNSC_RATIO__SHIFT         0x0000000c

// OV0_P1_H_ACCUM_INIT
#define	OV0_P1_H_ACCUM_INIT__OV0_P1_H_ACCUM_INIT__SHIFT    0x0000000f
#define	OV0_P1_H_ACCUM_INIT__OV0_PRESHIFT_P1_TO__SHIFT     0x0000001c

// OV0_P23_H_ACCUM_INIT
#define	OV0_P23_H_ACCUM_INIT__OV0_P23_H_ACCUM_INIT__SHIFT  0x0000000f
#define	OV0_P23_H_ACCUM_INIT__OV0_PRESHIFT_P23_TO__SHIFT   0x0000001c

// OV0_P1_X_START_END
#define	OV0_P1_X_START_END__OV0_P1_X_END__SHIFT            0x00000000
#define	OV0_P1_X_START_END__OV0_P1_X_START__SHIFT          0x00000010

// OV0_P2_X_START_END
#define	OV0_P2_X_START_END__OV0_P2_X_END__SHIFT            0x00000000
#define	OV0_P2_X_START_END__OV0_P2_X_START__SHIFT          0x00000010

// OV0_P3_X_START_END
#define	OV0_P3_X_START_END__OV0_P3_X_END__SHIFT            0x00000000
#define	OV0_P3_X_START_END__OV0_P3_X_START__SHIFT          0x00000010

// OV0_FILTER_CNTL
#define	OV0_FILTER_CNTL__OV0_HC_COEF_ON_HORZ_Y__SHIFT      0x00000000
#define	OV0_FILTER_CNTL__OV0_HC_COEF_ON_HORZ_UV__SHIFT     0x00000001
#define	OV0_FILTER_CNTL__OV0_HC_COEF_ON_VERT_Y__SHIFT      0x00000002
#define	OV0_FILTER_CNTL__OV0_HC_COEF_ON_VERT_UV__SHIFT     0x00000003

// OV0_FOUR_TAP_COEF_0
#define	OV0_FOUR_TAP_COEF_0__OV0_COEF_0TH_TAP__SHIFT       0x00000000
#define	OV0_FOUR_TAP_COEF_0__OV0_COEF_1ST_TAP__SHIFT       0x00000008
#define	OV0_FOUR_TAP_COEF_0__OV0_COEF_2ND_TAP__SHIFT       0x00000010
#define	OV0_FOUR_TAP_COEF_0__OV0_COEF_3RD_TAP__SHIFT       0x00000018

// OV0_FOUR_TAP_COEF_1
#define	OV0_FOUR_TAP_COEF_1__OV0_COEF_0TH_TAP__SHIFT       0x00000000
#define	OV0_FOUR_TAP_COEF_1__OV0_COEF_1ST_TAP__SHIFT       0x00000008
#define	OV0_FOUR_TAP_COEF_1__OV0_COEF_2ND_TAP__SHIFT       0x00000010
#define	OV0_FOUR_TAP_COEF_1__OV0_COEF_3RD_TAP__SHIFT       0x00000018

// OV0_FOUR_TAP_COEF_2
#define	OV0_FOUR_TAP_COEF_2__OV0_COEF_0TH_TAP__SHIFT       0x00000000
#define	OV0_FOUR_TAP_COEF_2__OV0_COEF_1ST_TAP__SHIFT       0x00000008
#define	OV0_FOUR_TAP_COEF_2__OV0_COEF_2ND_TAP__SHIFT       0x00000010
#define	OV0_FOUR_TAP_COEF_2__OV0_COEF_3RD_TAP__SHIFT       0x00000018

// OV0_FOUR_TAP_COEF_3
#define	OV0_FOUR_TAP_COEF_3__OV0_COEF_0TH_TAP__SHIFT       0x00000000
#define	OV0_FOUR_TAP_COEF_3__OV0_COEF_1ST_TAP__SHIFT       0x00000008
#define	OV0_FOUR_TAP_COEF_3__OV0_COEF_2ND_TAP__SHIFT       0x00000010
#define	OV0_FOUR_TAP_COEF_3__OV0_COEF_3RD_TAP__SHIFT       0x00000018

// OV0_FOUR_TAP_COEF_4
#define	OV0_FOUR_TAP_COEF_4__OV0_COEF_0TH_TAP__SHIFT       0x00000000
#define	OV0_FOUR_TAP_COEF_4__OV0_COEF_1ST_TAP__SHIFT       0x00000008
#define	OV0_FOUR_TAP_COEF_4__OV0_COEF_2ND_TAP__SHIFT       0x00000010
#define	OV0_FOUR_TAP_COEF_4__OV0_COEF_3RD_TAP__SHIFT       0x00000018

// OV0_FLAG_CNTRL
#define	OV0_FLAG_CNTRL__OV0_HI_PRI_MCREQ__SHIFT            0x00000000
#define	OV0_FLAG_CNTRL__OV0_HI_PRI_FORCE__SHIFT            0x00000008
#define	OV0_FLAG_CNTRL__OV0_LUMA_10BIT_EN__SHIFT           0x0000000c
#define	OV0_FLAG_CNTRL__OV0_CHROMA_10BIT_EN__SHIFT         0x0000000d

// OV0_SLICE_CNTL
#define	OV0_SLICE_CNTL__OV0_SLICE_LAST_LINE__SHIFT         0x00000000
#define	OV0_SLICE_CNTL__OV0_SLICEDONE_STAT__SHIFT          0x0000001e
#define	OV0_SLICE_CNTL__OV0_MPEG_EOF_TOGGLE__SHIFT         0x0000001f

// OV0_VID_KEY_CLR_LOW
#define	OV0_VID_KEY_CLR_LOW__OV0_VID_KEY_Cb_BLUE_LOW__SHIFT 0x00000000
#define	OV0_VID_KEY_CLR_LOW__OV0_VID_KEY_Y_GREEN_LOW__SHIFT 0x0000000a
#define	OV0_VID_KEY_CLR_LOW__OV0_VID_KEY_Cr_RED_LOW__SHIFT 0x00000014

// OV0_VID_KEY_CLR_HIGH
#define	OV0_VID_KEY_CLR_HIGH__OV0_VID_KEY_Cb_BLUE_HIGH__SHIFT 0x00000000
#define	OV0_VID_KEY_CLR_HIGH__OV0_VID_KEY_Y_GREEN_HIGH__SHIFT 0x0000000a
#define	OV0_VID_KEY_CLR_HIGH__OV0_VID_KEY_Cr_RED_HIGH__SHIFT 0x00000014

// OV0_GRPH_KEY_CLR_LOW
#define	OV0_GRPH_KEY_CLR_LOW__OV0_GRPH_KEY_BLUE_LOW__SHIFT 0x00000000
#define	OV0_GRPH_KEY_CLR_LOW__OV0_GRPH_KEY_GREEN_LOW__SHIFT 0x00000008
#define	OV0_GRPH_KEY_CLR_LOW__OV0_GRPH_KEY_RED_LOW__SHIFT  0x00000010
#define	OV0_GRPH_KEY_CLR_LOW__OV0_GRPH_KEY_ALPHA_LOW__SHIFT 0x00000018

// OV0_GRPH_KEY_CLR_HIGH
#define	OV0_GRPH_KEY_CLR_HIGH__OV0_GRPH_KEY_BLUE_HIGH__SHIFT 0x00000000
#define	OV0_GRPH_KEY_CLR_HIGH__OV0_GRPH_KEY_GREEN_HIGH__SHIFT 0x00000008
#define	OV0_GRPH_KEY_CLR_HIGH__OV0_GRPH_KEY_RED_HIGH__SHIFT 0x00000010
#define	OV0_GRPH_KEY_CLR_HIGH__OV0_GRPH_KEY_ALPHA_HIGH__SHIFT 0x00000018

// OV0_KEY_CNTL
#define	OV0_KEY_CNTL__OV0_VIDEO_KEY_FN__SHIFT              0x00000000
#define	OV0_KEY_CNTL__OV0_GRAPHICS_KEY_FN__SHIFT           0x00000004
#define	OV0_KEY_CNTL__OV0_CMP_MIX__SHIFT                   0x00000008

// OV0_TEST
#define	OV0_TEST__OV0_MIN_OFFSET_EN__SHIFT                 0x00000001
#define	OV0_TEST__OV0_SUBPIC_ONLY__SHIFT                   0x00000003
#define	OV0_TEST__OV0_SWAP_UV__SHIFT                       0x00000005
#define	OV0_TEST__OV0_NOROUNDUP__SHIFT                     0x00000006
#define	OV0_TEST__OV0_ADAPTIVE_DEINT_ADJ__SHIFT            0x0000000c
#define	OV0_TEST__OV0_READ_BEHIND_SCAN_MARGIN__SHIFT       0x00000010

// OV1_Y_X_START
#define	OV1_Y_X_START__OV1_X_START__SHIFT                  0x00000000
#define	OV1_Y_X_START__OV1_Y_START__SHIFT                  0x00000010

// OV1_Y_X_END
#define	OV1_Y_X_END__OV1_X_END__SHIFT                      0x00000000
#define	OV1_Y_X_END__OV1_Y_END__SHIFT                      0x00000010

// OV1_PIPELINE_CNTL
#define	OV1_PIPELINE_CNTL__OV1_DISP_PIPE_DELAY__SHIFT      0x00000000

// DISP_MISC_CNTL
#define	DISP_MISC_CNTL__SOFT_RESET_GRPH_PP__SHIFT          0x00000000
#define	DISP_MISC_CNTL__SOFT_RESET_SUBPIC_PP__SHIFT        0x00000001
#define	DISP_MISC_CNTL__SOFT_RESET_OV0_PP__SHIFT           0x00000002
#define	DISP_MISC_CNTL__SOFT_RESET_GRPH_SCLK__SHIFT        0x00000004
#define	DISP_MISC_CNTL__SOFT_RESET_SUBPIC_SCLK__SHIFT      0x00000005
#define	DISP_MISC_CNTL__SOFT_RESET_OV0_SCLK__SHIFT         0x00000006
#define	DISP_MISC_CNTL__SYNC_STRENGTH__SHIFT               0x00000008
#define	DISP_MISC_CNTL__SYNC_PAD_FLOP_EN__SHIFT            0x0000000a
#define	DISP_MISC_CNTL__SOFT_RESET_GRPH2_PP__SHIFT         0x0000000c
#define	DISP_MISC_CNTL__SOFT_RESET_GRPH2_SCLK__SHIFT       0x0000000f
#define	DISP_MISC_CNTL__SOFT_RESET_LVDS__SHIFT             0x00000010
#define	DISP_MISC_CNTL__SOFT_RESET_TMDS__SHIFT             0x00000011
#define	DISP_MISC_CNTL__SOFT_RESET_DIG_TMDS__SHIFT         0x00000012
#define	DISP_MISC_CNTL__SOFT_RESET_TV__SHIFT               0x00000013
#define	DISP_MISC_CNTL__PALETTE2_MEM_RD_MARGIN__SHIFT      0x00000014
#define	DISP_MISC_CNTL__PALETTE_MEM_RD_MARGIN__SHIFT       0x00000018
#define	DISP_MISC_CNTL__RMX_BUF_MEM_RD_MARGIN__SHIFT       0x0000001c

// DAC_MACRO_CNTL
#define	DAC_MACRO_CNTL__DAC_WHITE_CNTL__SHIFT              0x00000000
#define	DAC_MACRO_CNTL__DAC_BG_ADJ__SHIFT                  0x00000008
#define	DAC_MACRO_CNTL__DAC_PDWN_R__SHIFT                  0x00000010
#define	DAC_MACRO_CNTL__DAC_PDWN_G__SHIFT                  0x00000011
#define	DAC_MACRO_CNTL__DAC_PDWN_B__SHIFT                  0x00000012

// DISP_PWR_MAN
#define	DISP_PWR_MAN__DISP_PWR_MAN_D3_CRTC_EN__SHIFT       0x00000000
#define	DISP_PWR_MAN__DISP2_PWR_MAN_D3_CRTC2_EN__SHIFT     0x00000004
#define	DISP_PWR_MAN__DISP_PWR_MAN_DPMS__SHIFT             0x00000008
#define	DISP_PWR_MAN__DISP_D3_RST__SHIFT                   0x00000010
#define	DISP_PWR_MAN__DISP_D3_REG_RST__SHIFT               0x00000011
#define	DISP_PWR_MAN__DISP_D3_GRPH_RST__SHIFT              0x00000012
#define	DISP_PWR_MAN__DISP_D3_SUBPIC_RST__SHIFT            0x00000013
#define	DISP_PWR_MAN__DISP_D3_OV0_RST__SHIFT               0x00000014
#define	DISP_PWR_MAN__DISP_D1D2_GRPH_RST__SHIFT            0x00000015
#define	DISP_PWR_MAN__DISP_D1D2_SUBPIC_RST__SHIFT          0x00000016
#define	DISP_PWR_MAN__DISP_D1D2_OV0_RST__SHIFT             0x00000017
#define	DISP_PWR_MAN__DIG_TMDS_ENABLE_RST__SHIFT           0x00000018
#define	DISP_PWR_MAN__TV_ENABLE_RST__SHIFT                 0x00000019
#define	DISP_PWR_MAN__AUTO_PWRUP_EN__SHIFT                 0x0000001a

// DISP_TEST_DEBUG_CNTL
#define	DISP_TEST_DEBUG_CNTL__DISP_TEST_DISPENG__SHIFT     0x00000000
#define	DISP_TEST_DEBUG_CNTL__DISP_TEST_PALETTE__SHIFT     0x00000001
#define	DISP_TEST_DEBUG_CNTL__DISP_TEST_DAC__SHIFT         0x00000002
#define	DISP_TEST_DEBUG_CNTL__DISP_TEST_OV0SCALE__SHIFT    0x00000004
#define	DISP_TEST_DEBUG_CNTL__DISP_TEST_CLK__SHIFT         0x00000005
#define	DISP_TEST_DEBUG_CNTL__DISP_TEST_DISP2ENG__SHIFT    0x00000008
#define	DISP_TEST_DEBUG_CNTL__DISP_TEST_PALETTE2__SHIFT    0x00000009
#define	DISP_TEST_DEBUG_CNTL__DISP_GRPH2_UNDERFLOW__SHIFT  0x00000010
#define	DISP_TEST_DEBUG_CNTL__DISP_GRPH2_UNDERFLOW_CLR__SHIFT 0x00000010
#define	DISP_TEST_DEBUG_CNTL__DISP_CUR2_UNDERFLOW__SHIFT   0x00000011
#define	DISP_TEST_DEBUG_CNTL__DISP_CUR2_UNDERFLOW_CLR__SHIFT 0x00000011
#define	DISP_TEST_DEBUG_CNTL__DISP_GRPH_UNDERFLOW__SHIFT   0x00000018
#define	DISP_TEST_DEBUG_CNTL__DISP_GRPH_UNDERFLOW_CLR__SHIFT 0x00000018
#define	DISP_TEST_DEBUG_CNTL__DISP_CUR_UNDERFLOW__SHIFT    0x00000019
#define	DISP_TEST_DEBUG_CNTL__DISP_CUR_UNDERFLOW_CLR__SHIFT 0x00000019
#define	DISP_TEST_DEBUG_CNTL__DISP_OV0_UNDERFLOW__SHIFT    0x0000001a
#define	DISP_TEST_DEBUG_CNTL__DISP_OV0_UNDERFLOW_CLR__SHIFT 0x0000001a

// DISP_HW_DEBUG
#define	DISP_HW_DEBUG__DISP_HW_0_DEBUG__SHIFT              0x00000000
#define	DISP_HW_DEBUG__DISP_HW_1_DEBUG__SHIFT              0x00000001
#define	DISP_HW_DEBUG__DISP_HW_2_DEBUG__SHIFT              0x00000002
#define	DISP_HW_DEBUG__DISP_HW_3_DEBUG__SHIFT              0x00000003
#define	DISP_HW_DEBUG__DISP_HW_4_DEBUG__SHIFT              0x00000004
#define	DISP_HW_DEBUG__CRT2_DISP1_SEL__SHIFT               0x00000005
#define	DISP_HW_DEBUG__DISP_HW_6_DEBUG__SHIFT              0x00000006
#define	DISP_HW_DEBUG__DISP_HW_7_DEBUG__SHIFT              0x00000007
#define	DISP_HW_DEBUG__DISP_HW_8_DEBUG__SHIFT              0x00000008
#define	DISP_HW_DEBUG__DISP_HW_9_DEBUG__SHIFT              0x00000009
#define	DISP_HW_DEBUG__DISP_HW_A_DEBUG__SHIFT              0x0000000a
#define	DISP_HW_DEBUG__DISP_HW_B_DEBUG__SHIFT              0x0000000b
#define	DISP_HW_DEBUG__DISP_HW_C_DEBUG__SHIFT              0x0000000c
#define	DISP_HW_DEBUG__DISP_HW_D_DEBUG__SHIFT              0x0000000d
#define	DISP_HW_DEBUG__DISP_HW_E_DEBUG__SHIFT              0x0000000e
#define	DISP_HW_DEBUG__DISP_HW_F_DEBUG__SHIFT              0x0000000f
#define	DISP_HW_DEBUG__DISP_HW_10_DEBUG__SHIFT             0x00000010
#define	DISP_HW_DEBUG__DISP_HW_11_DEBUG__SHIFT             0x00000011

// DAC_CRC_SIG1
#define	DAC_CRC_SIG1__DAC_CRC_SIG_B__SHIFT                 0x00000000
#define	DAC_CRC_SIG1__DAC_CRC_SIG_G__SHIFT                 0x00000010

// DAC_CRC_SIG2
#define	DAC_CRC_SIG2__DAC_CRC_SIG_R__SHIFT                 0x00000000
#define	DAC_CRC_SIG2__DAC_CRC_SIG_C__SHIFT                 0x00000010

// OV0_LIN_TRANS_A
#define	OV0_LIN_TRANS_A__OV0_LIN_TRANS_Cb_R_M6__SHIFT      0x00000004
#define	OV0_LIN_TRANS_A__OV0_LIN_TRANS_Y_R_M6__SHIFT       0x00000014

// OV0_LIN_TRANS_B
#define	OV0_LIN_TRANS_B__OV0_LIN_TRANS_OFF_R__SHIFT        0x00000000
#define	OV0_LIN_TRANS_B__OV0_LIN_TRANS_Cr_R_M6__SHIFT      0x00000014

// OV0_LIN_TRANS_C
#define	OV0_LIN_TRANS_C__OV0_LIN_TRANS_Cb_G_M6__SHIFT      0x00000004
#define	OV0_LIN_TRANS_C__OV0_LIN_TRANS_Y_G_M6__SHIFT       0x00000014

// OV0_LIN_TRANS_D
#define	OV0_LIN_TRANS_D__OV0_LIN_TRANS_OFF_G__SHIFT        0x00000000
#define	OV0_LIN_TRANS_D__OV0_LIN_TRANS_Cr_G_M6__SHIFT      0x00000014

// OV0_LIN_TRANS_E
#define	OV0_LIN_TRANS_E__OV0_LIN_TRANS_Cb_B_M6__SHIFT      0x00000004
#define	OV0_LIN_TRANS_E__OV0_LIN_TRANS_Y_B_M6__SHIFT       0x00000014

// OV0_LIN_TRANS_F
#define	OV0_LIN_TRANS_F__OV0_LIN_TRANS_OFF_B__SHIFT        0x00000000
#define	OV0_LIN_TRANS_F__OV0_LIN_TRANS_Cr_B_M6__SHIFT      0x00000014

// OV0_GAMMA_0_F
#define	OV0_GAMMA_0_F__OV0_GAMMA_0_F_OFFSET__SHIFT         0x00000000
#define	OV0_GAMMA_0_F__OV0_GAMMA_0_F_SLOPE__SHIFT          0x00000010

// OV0_GAMMA_10_1F
#define	OV0_GAMMA_10_1F__OV0_GAMMA_10_1F_OFFSET__SHIFT     0x00000000
#define	OV0_GAMMA_10_1F__OV0_GAMMA_10_1F_SLOPE__SHIFT      0x00000010

// OV0_GAMMA_20_3F
#define	OV0_GAMMA_20_3F__OV0_GAMMA_20_3F_OFFSET__SHIFT     0x00000000
#define	OV0_GAMMA_20_3F__OV0_GAMMA_20_3F_SLOPE__SHIFT      0x00000010

// OV0_GAMMA_40_7F
#define	OV0_GAMMA_40_7F__OV0_GAMMA_40_7F_OFFSET__SHIFT     0x00000000
#define	OV0_GAMMA_40_7F__OV0_GAMMA_40_7F_SLOPE__SHIFT      0x00000010

// OV0_GAMMA_380_3BF
#define	OV0_GAMMA_380_3BF__OV0_GAMMA_380_3BF_OFFSET__SHIFT 0x00000000
#define	OV0_GAMMA_380_3BF__OV0_GAMMA_380_3BF_SLOPE__SHIFT  0x00000010

// OV0_GAMMA_3C0_3FF
#define	OV0_GAMMA_3C0_3FF__OV0_GAMMA_3C0_3FF_OFFSET__SHIFT 0x00000000
#define	OV0_GAMMA_3C0_3FF__OV0_GAMMA_3C0_3FF_SLOPE__SHIFT  0x00000010

// DISP_MERGE_CNTL
#define	DISP_MERGE_CNTL__DISP_ALPHA_MODE__SHIFT            0x00000000
#define	DISP_MERGE_CNTL__DISP_ALPHA_INV__SHIFT             0x00000002
#define	DISP_MERGE_CNTL__DISP_ALPHA_PREMULT__SHIFT         0x00000003
#define	DISP_MERGE_CNTL__DISP_RGB_OFFSET_EN__SHIFT         0x00000008
#define	DISP_MERGE_CNTL__DISP_GRPH_ALPHA__SHIFT            0x00000010
#define	DISP_MERGE_CNTL__DISP_OV0_ALPHA__SHIFT             0x00000018

// DISP_OUTPUT_CNTL
#define	DISP_OUTPUT_CNTL__DISP_DAC_SOURCE__SHIFT           0x00000000
#define	DISP_OUTPUT_CNTL__DISP_RMX_SOURCE__SHIFT           0x00000008
#define	DISP_OUTPUT_CNTL__DISP_RMX_DITH_EN__SHIFT          0x0000000a
#define	DISP_OUTPUT_CNTL__DISP_TV_EVEN_FLAG_CNTL__SHIFT    0x0000001b

// DISP2_MERGE_CNTL
#define	DISP2_MERGE_CNTL__DISP2_RGB_OFFSET_EN__SHIFT       0x00000008

// DAC_CRC2_SIG1
#define	DAC_CRC2_SIG1__DAC_CRC2_SIG_B__SHIFT               0x00000000
#define	DAC_CRC2_SIG1__DAC_CRC2_SIG_G__SHIFT               0x00000010

// DAC_CRC2_SIG2
#define	DAC_CRC2_SIG2__DAC_CRC2_SIG_R__SHIFT               0x00000000
#define	DAC_CRC2_SIG2__DAC_CRC2_SIG_C__SHIFT               0x00000010

// RMX_HORZ_PHASE
#define	RMX_HORZ_PHASE__RMX_HORZ_START_PHASE__SHIFT        0x00000000
#define	RMX_HORZ_PHASE__RMX_H_ACC_INIT__SHIFT              0x0000000c
#define	RMX_HORZ_PHASE__RMX_V_ACC_INIT__SHIFT              0x0000000d
#define	RMX_HORZ_PHASE__RMX_VERT_START_PHASE__SHIFT        0x00000010

// HDCP_GEN_CNTL
#define	HDCP_GEN_CNTL__HDCP_AUTHORIZED_INT_STAT__SHIFT     0x00000000
#define	HDCP_GEN_CNTL__HDCP_AUTHORIZED_INT_AK__SHIFT       0x00000000
#define	HDCP_GEN_CNTL__HDCP_AUTHORIZED_INT_POL__SHIFT      0x00000001
#define	HDCP_GEN_CNTL__HDCP_AUTHORIZED_INT_MASK__SHIFT     0x00000002
#define	HDCP_GEN_CNTL__HOT_PLUG_AFFECTS_HDCP_EN__SHIFT     0x00000003
#define	HDCP_GEN_CNTL__HDCP_AUTHORIZED__SHIFT              0x00000004
#define	HDCP_GEN_CNTL__HDCP_RESET__SHIFT                   0x00000005
#define	HDCP_GEN_CNTL__HDCP_I2C_SCL_DRIVE_EN__SHIFT        0x00000006
#define	HDCP_GEN_CNTL__HDCP_I2C_SDA_DRIVE_EN__SHIFT        0x00000007
#define	HDCP_GEN_CNTL__HDCP_I2C_TIME_LIMIT__SHIFT          0x00000008
#define	HDCP_GEN_CNTL__HDCP_I2C_PRESCALE__SHIFT            0x00000010

// HDCP_CONTROL
#define	HDCP_CONTROL__HDCP_CONTROL__SHIFT                  0x00000000

// HDCP_DATA_UPPER
#define	HDCP_DATA_UPPER__HDCP_DATA_UPPER__SHIFT            0x00000000

// HDCP_DATA_LOWER
#define	HDCP_DATA_LOWER__HDCP_DATA_LOWER__SHIFT            0x00000000

// HDCP_DEBUG
#define	HDCP_DEBUG__HDCP_DEBUG_EN__SHIFT                   0x00000000
#define	HDCP_DEBUG__I2C_CNTL_REGS_AFFECT_HDCP_I2C__SHIFT   0x00000001
#define	HDCP_DEBUG__SW_CAN_QUEUE_I2C_GO__SHIFT             0x00000002
#define	HDCP_DEBUG__USE_HDCP_I2C_SHORT_READS__SHIFT        0x00000003
#define	HDCP_DEBUG__HDCP_DEBUG_BIT4__SHIFT                 0x00000004
#define	HDCP_DEBUG__HDCP_DEBUG_BIT5__SHIFT                 0x00000005
#define	HDCP_DEBUG__HDCP_DEBUG_BIT6__SHIFT                 0x00000006
#define	HDCP_DEBUG__HDCP_DEBUG_BIT7__SHIFT                 0x00000007
#define	HDCP_DEBUG__HDCP_DEBUG_ADDR__SHIFT                 0x00000008
#define	HDCP_DEBUG__HDCP_DEBUG_DATA__SHIFT                 0x00000010

// CLOCK_CNTL_INDEX
#define	CLOCK_CNTL_INDEX__PLL_ADDR_M6__SHIFT               0x00000000
#define	CLOCK_CNTL_INDEX__PLL_WR_EN__SHIFT                 0x00000007
#define	CLOCK_CNTL_INDEX__PPLL_DIV_SEL__SHIFT              0x00000008

// CLOCK_CNTL_DATA
#define	CLOCK_CNTL_DATA__PLL_DATA__SHIFT                   0x00000000

// PPLL_DIV_0
#define	PPLL_DIV_0__PPLL_FB0_DIV__SHIFT                    0x00000000
#define	PPLL_DIV_0__PPLL_ATOMIC_UPDATE_W__SHIFT            0x0000000f
#define	PPLL_DIV_0__PPLL_ATOMIC_UPDATE_R__SHIFT            0x0000000f
#define	PPLL_DIV_0__PPLL_POST0_DIV__SHIFT                  0x00000010
#define	PPLL_DIV_0__PPLL_FB_DIV_FRACTION__SHIFT            0x00000013
#define	PPLL_DIV_0__PPLL_FB_DIV_FRACTION_UPDATE__SHIFT     0x00000016
#define	PPLL_DIV_0__PPLL_FB_DIV_FRACTION_EN__SHIFT         0x00000017

// PPLL_DIV_1
#define	PPLL_DIV_1__PPLL_FB1_DIV__SHIFT                    0x00000000
#define	PPLL_DIV_1__PPLL_ATOMIC_UPDATE_W__SHIFT            0x0000000f
#define	PPLL_DIV_1__PPLL_ATOMIC_UPDATE_R__SHIFT            0x0000000f
#define	PPLL_DIV_1__PPLL_POST1_DIV__SHIFT                  0x00000010

// PPLL_DIV_2
#define	PPLL_DIV_2__PPLL_FB2_DIV__SHIFT                    0x00000000
#define	PPLL_DIV_2__PPLL_ATOMIC_UPDATE_W__SHIFT            0x0000000f
#define	PPLL_DIV_2__PPLL_ATOMIC_UPDATE_R__SHIFT            0x0000000f
#define	PPLL_DIV_2__PPLL_POST2_DIV__SHIFT                  0x00000010

// PPLL_DIV_3
#define	PPLL_DIV_3__PPLL_FB3_DIV__SHIFT                    0x00000000
#define	PPLL_DIV_3__PPLL_ATOMIC_UPDATE_W__SHIFT            0x0000000f
#define	PPLL_DIV_3__PPLL_ATOMIC_UPDATE_R__SHIFT            0x0000000f
#define	PPLL_DIV_3__PPLL_POST3_DIV__SHIFT                  0x00000010

// HTOTAL_CNTL
#define	HTOTAL_CNTL__HTOT_PIX_SLIP__SHIFT                  0x00000000
#define	HTOTAL_CNTL__HTOT_VCLK_SLIP__SHIFT                 0x00000008
#define	HTOTAL_CNTL__HTOT_PPLL_SLIP__SHIFT                 0x00000010
#define	HTOTAL_CNTL__HTOT_CNTL_EDGE__SHIFT                 0x00000018
#define	HTOTAL_CNTL__HTOT_CNTL_VGA_EN__SHIFT               0x0000001c

// PLL_TEST_CNTL
#define	PLL_TEST_CNTL__TST_SRC_SEL_M6__SHIFT               0x00000000
#define	PLL_TEST_CNTL__TST_SRC_INV__SHIFT                  0x00000007
#define	PLL_TEST_CNTL__TST_DIVIDERS__SHIFT                 0x00000008
#define	PLL_TEST_CNTL__PLL_MASK_READ_B__SHIFT              0x00000009
#define	PLL_TEST_CNTL__TESTCLK_MUX_SEL__SHIFT              0x0000000c
#define	PLL_TEST_CNTL__ANALOG_MON_M6__SHIFT                0x0000000f
#define	PLL_TEST_CNTL__TEST_COUNT__SHIFT                   0x00000018

// P2PLL_DIV_0
#define	P2PLL_DIV_0__P2PLL_FB_DIV__SHIFT                   0x00000000
#define	P2PLL_DIV_0__P2PLL_ATOMIC_UPDATE_W__SHIFT          0x0000000f
#define	P2PLL_DIV_0__P2PLL_ATOMIC_UPDATE_R__SHIFT          0x0000000f
#define	P2PLL_DIV_0__P2PLL_POST_DIV__SHIFT                 0x00000010
#define	P2PLL_DIV_0__P2PLL_FB_DIV_FRACTION__SHIFT          0x00000013
#define	P2PLL_DIV_0__P2PLL_FB_DIV_FRACTION_UPDATE__SHIFT   0x00000016
#define	P2PLL_DIV_0__P2PLL_FB_DIV_FRACTION_EN__SHIFT       0x00000017

// HTOTAL2_CNTL
#define	HTOTAL2_CNTL__HTOT2_PIX_SLIP__SHIFT                0x00000000
#define	HTOTAL2_CNTL__HTOT2_PIX2CLK_SLIP__SHIFT            0x00000008
#define	HTOTAL2_CNTL__HTOT2_P2PLL_SLIP__SHIFT              0x00000010
#define	HTOTAL2_CNTL__HTOT2_CNTL_EDGE__SHIFT               0x00000018
#define	HTOTAL2_CNTL__HTOT2_CNTL_UPDATE__SHIFT             0x0000001c

// DAC_CNTL2
#define	DAC_CNTL2__DAC_CLK_SEL__SHIFT                      0x00000000
#define	DAC_CNTL2__DAC2_CLK_SEL__SHIFT                     0x00000001
#define	DAC_CNTL2__PALETTE_ACCESS_CNTL__SHIFT              0x00000005
#define	DAC_CNTL2__DAC2_CMP_EN__SHIFT                      0x00000007
#define	DAC_CNTL2__DAC2_CMP_OUT_R__SHIFT                   0x00000008
#define	DAC_CNTL2__DAC2_CMP_OUT_G__SHIFT                   0x00000009
#define	DAC_CNTL2__DAC2_CMP_OUT_B__SHIFT                   0x0000000a
#define	DAC_CNTL2__DAC2_CMP_OUTPUT__SHIFT                  0x0000000b
#define	DAC_CNTL2__DAC2_EXPAND_MODE__SHIFT                 0x0000000e
#define	DAC_CNTL2__CRT2_SENSE__SHIFT                       0x00000010
#define	DAC_CNTL2__CRT2_DETECTION_ON__SHIFT                0x00000011
#define	DAC_CNTL2__DAC_CRC2_CONT_EN__SHIFT                 0x00000012
#define	DAC_CNTL2__DAC_CRC2_EN__SHIFT                      0x00000013
#define	DAC_CNTL2__DAC_CRC2_FIELD__SHIFT                   0x00000014
#define	DAC_CNTL2__DAC2_LUT_COUNTER_LIMIT__SHIFT           0x00000015

// TV_MASTER_CNTL
#define	TV_MASTER_CNTL__TV_ASYNC_RST__SHIFT                0x00000000
#define	TV_MASTER_CNTL__CRT_ASYNC_RST__SHIFT               0x00000001
#define	TV_MASTER_CNTL__RESTART_PHASE_FIX__SHIFT           0x00000003
#define	TV_MASTER_CNTL__TV_FIFO_ASYNC_RST__SHIFT           0x00000004
#define	TV_MASTER_CNTL__MV_BP_LEVEL_FIX_EN__SHIFT          0x00000005
#define	TV_MASTER_CNTL__EXTRA_BIT_ONE_0__SHIFT             0x00000006
#define	TV_MASTER_CNTL__CRT_FIFO_CE_EN__SHIFT              0x00000009
#define	TV_MASTER_CNTL__TV_FIFO_CE_EN__SHIFT               0x0000000a
#define	TV_MASTER_CNTL__RE_SYNC_NOW_SEL__SHIFT             0x0000000e
#define	TV_MASTER_CNTL__EXTRA_BIT_ZERO_1__SHIFT            0x00000010
#define	TV_MASTER_CNTL__EXTRA_BIT_ONE_1__SHIFT             0x00000011
#define	TV_MASTER_CNTL__EXTRA_BIT_ZERO_2__SHIFT            0x00000012
#define	TV_MASTER_CNTL__EXTRA_BIT_ONE_2__SHIFT             0x00000013
#define	TV_MASTER_CNTL__TVCLK_ALWAYS_ONb__SHIFT            0x0000001e
#define	TV_MASTER_CNTL__TV_ON__SHIFT                       0x0000001f

// TV_RGB_CNTL
#define	TV_RGB_CNTL__UV_DITHER_EN__SHIFT                   0x00000002
#define	TV_RGB_CNTL__SWITCH_TO_BLUE__SHIFT                 0x00000004
#define	TV_RGB_CNTL__RGB_DITHER_EN__SHIFT                  0x00000005
#define	TV_RGB_CNTL__RGB_SRC_SEL__SHIFT                    0x00000008
#define	TV_RGB_CNTL__RGB_CONVERT_BY_PASS__SHIFT            0x0000000a
#define	TV_RGB_CNTL__RE_SYNC_NOW_POS__SHIFT                0x0000000b
#define	TV_RGB_CNTL__IGNORE_ODD_LINES__SHIFT               0x0000000d
#define	TV_RGB_CNTL__DSP_VCOUNT_RST__SHIFT                 0x0000000e
#define	TV_RGB_CNTL__DSP2_VCOUNT_RST__SHIFT                0x0000000f
#define	TV_RGB_CNTL__UVRAM_READ_MARGIN__SHIFT              0x00000010
#define	TV_RGB_CNTL__FIFORAM_FFMACRO_READ_MARGIN__SHIFT    0x00000014
#define	TV_RGB_CNTL__RGB_ATTEN_SEL__SHIFT                  0x00000018
#define	TV_RGB_CNTL__RGB_ATTEN_VAL__SHIFT                  0x0000001c

// TV_SYNC_CNTL
#define	TV_SYNC_CNTL__SYNC_OE__SHIFT                       0x00000000
#define	TV_SYNC_CNTL__SYNC_OUT__SHIFT                      0x00000001
#define	TV_SYNC_CNTL__SYNC_IN__SHIFT                       0x00000002
#define	TV_SYNC_CNTL__SYNC_PUB__SHIFT                      0x00000003
#define	TV_SYNC_CNTL__SYNC_PD__SHIFT                       0x00000004
#define	TV_SYNC_CNTL__TV_SYNC_IO_DRIVE__SHIFT              0x00000005
#define	TV_SYNC_CNTL__SYNC_MX__SHIFT                       0x00000008

// TV_HTOTAL
#define	TV_HTOTAL__D_HTOTAL__SHIFT                         0x00000000

// TV_HDISP
#define	TV_HDISP__D_HDISP__SHIFT                           0x00000000

// TV_HSTART
#define	TV_HSTART__D_HSTART__SHIFT                         0x00000000

// TV_HCOUNT
#define	TV_HCOUNT__D_HCOUNT__SHIFT                         0x00000000

// TV_VTOTAL
#define	TV_VTOTAL__D_VTOTAL__SHIFT                         0x00000000

// TV_VDISP
#define	TV_VDISP__D_VDISP__SHIFT                           0x00000000

// TV_VCOUNT
#define	TV_VCOUNT__D_VCOUNT__SHIFT                         0x00000000

// TV_FTOTAL
#define	TV_FTOTAL__D_FTOTAL__SHIFT                         0x00000000

// TV_FCOUNT
#define	TV_FCOUNT__D_FCOUNT__SHIFT                         0x00000000

// TV_FRESTART
#define	TV_FRESTART__D_FRESTART__SHIFT                     0x00000000

// TV_HRESTART
#define	TV_HRESTART__D_HRESTART__SHIFT                     0x00000000

// TV_VRESTART
#define	TV_VRESTART__D_VRESTART__SHIFT                     0x00000000

// TV_HOST_READ_DATA
#define	TV_HOST_READ_DATA__HOST_RD_DATA_W0__SHIFT          0x00000000
#define	TV_HOST_READ_DATA__HOST_RD_DATA_W1__SHIFT          0x00000010

// TV_HOST_WRITE_DATA
#define	TV_HOST_WRITE_DATA__HOST_WT_DATA_W0__SHIFT         0x00000000
#define	TV_HOST_WRITE_DATA__HOST_WT_DATA_W1__SHIFT         0x00000010

// TV_HOST_RD_WT_CNTL
#define	TV_HOST_RD_WT_CNTL__HOST_ADR__SHIFT                0x00000000
#define	TV_HOST_RD_WT_CNTL__HOST_FIFO_RD__SHIFT            0x0000000c
#define	TV_HOST_RD_WT_CNTL__HOST_FIFO_RD_ACK__SHIFT        0x0000000d
#define	TV_HOST_RD_WT_CNTL__HOST_FIFO_WT__SHIFT            0x0000000e
#define	TV_HOST_RD_WT_CNTL__HOST_FIFO_WT_ACK__SHIFT        0x0000000f

// TV_VSCALER_CNTL1
#define	TV_VSCALER_CNTL1__UV_INC__SHIFT                    0x00000000
#define	TV_VSCALER_CNTL1__UV_THINNER__SHIFT                0x00000010
#define	TV_VSCALER_CNTL1__Y_W_EN__SHIFT                    0x00000018
#define	TV_VSCALER_CNTL1__Y_DEL_W_SIG__SHIFT               0x0000001a
#define	TV_VSCALER_CNTL1__RESTART_FIELD__SHIFT             0x0000001d

// TV_TIMING_CNTL
#define	TV_TIMING_CNTL__H_INC__SHIFT                       0x00000000
#define	TV_TIMING_CNTL__REQ_DELAY__SHIFT                   0x00000010
#define	TV_TIMING_CNTL__REQ_Y_FIRST__SHIFT                 0x00000013
#define	TV_TIMING_CNTL__MV_VBIPULSE_ENB__SHIFT             0x00000014
#define	TV_TIMING_CNTL__FORCE_BURST_ALWAYS__SHIFT          0x00000015
#define	TV_TIMING_CNTL__UV_POST_SCALE_BYPASS__SHIFT        0x00000017
#define	TV_TIMING_CNTL__UV_OUTPUT_POST_SCALE__SHIFT        0x00000018

// TV_VSCALER_CNTL2
#define	TV_VSCALER_CNTL2__DITHER_MODE__SHIFT               0x00000000
#define	TV_VSCALER_CNTL2__Y_OUTPUT_DITHER_EN__SHIFT        0x00000001
#define	TV_VSCALER_CNTL2__UV_OUTPUT_DITHER_EN__SHIFT       0x00000002
#define	TV_VSCALER_CNTL2__UV_TO_BUF_DITHER_EN__SHIFT       0x00000003
#define	TV_VSCALER_CNTL2__UV_ACCUM_INIT__SHIFT             0x00000018

// TV_Y_FALL_CNTL
#define	TV_Y_FALL_CNTL__Y_FALL_ACCUM_INIT__SHIFT           0x00000000
#define	TV_Y_FALL_CNTL__Y_FALL_PING_PONG__SHIFT            0x00000010
#define	TV_Y_FALL_CNTL__Y_COEF_EN__SHIFT                   0x00000011
#define	TV_Y_FALL_CNTL__Y_COEF_VALUE__SHIFT                0x00000018

// TV_Y_RISE_CNTL
#define	TV_Y_RISE_CNTL__Y_RISE_ACCUM_INIT__SHIFT           0x00000000
#define	TV_Y_RISE_CNTL__Y_RISE_PING_PONG__SHIFT            0x00000010
#define	TV_Y_RISE_CNTL__MV_STRIPE_ENB__SHIFT               0x00000011
#define	TV_Y_RISE_CNTL__MV_BPPULSE_ENB__SHIFT              0x00000012
#define	TV_Y_RISE_CNTL__MV_ZONE_1_PHASE__SHIFT             0x00000014
#define	TV_Y_RISE_CNTL__MV_ZONE_2_PHASE__SHIFT             0x00000015
#define	TV_Y_RISE_CNTL__MV_ZONE_3_PHASE__SHIFT             0x00000016

// TV_Y_SAW_TOOTH_CNTL
#define	TV_Y_SAW_TOOTH_CNTL__Y_SAW_TOOTH_AMP__SHIFT        0x00000000
#define	TV_Y_SAW_TOOTH_CNTL__Y_SAW_TOOTH_SLOPE__SHIFT      0x00000010

// TV_UPSAMP_AND_GAIN_CNTL
#define	TV_UPSAMP_AND_GAIN_CNTL__YUPSAMP_EN__SHIFT         0x00000000
#define	TV_UPSAMP_AND_GAIN_CNTL__YUPSAMP_FLAT__SHIFT       0x00000001
#define	TV_UPSAMP_AND_GAIN_CNTL__UVUPSAMP_EN__SHIFT        0x00000002
#define	TV_UPSAMP_AND_GAIN_CNTL__UVUPSAMP_FLAT__SHIFT      0x00000003
#define	TV_UPSAMP_AND_GAIN_CNTL__YUPSAMP_WINDOW_CNTL__SHIFT 0x00000004
#define	TV_UPSAMP_AND_GAIN_CNTL__YUPSAMP_COEF_SEL__SHIFT   0x00000005
#define	TV_UPSAMP_AND_GAIN_CNTL__Y_BREAK_EN__SHIFT         0x00000008
#define	TV_UPSAMP_AND_GAIN_CNTL__UV_BREAK_EN__SHIFT        0x0000000a

// TV_GAIN_LIMIT_SETTINGS
#define	TV_GAIN_LIMIT_SETTINGS__Y_GAIN_LIMIT__SHIFT        0x00000000
#define	TV_GAIN_LIMIT_SETTINGS__UV_GAIN_LIMIT__SHIFT       0x00000010

// TV_LINEAR_GAIN_SETTINGS
#define	TV_LINEAR_GAIN_SETTINGS__Y_GAIN__SHIFT             0x00000000
#define	TV_LINEAR_GAIN_SETTINGS__UV_GAIN__SHIFT            0x00000010

// TV_MODULATOR_CNTL1
#define	TV_MODULATOR_CNTL1__YY_FILT_BLEND__SHIFT           0x00000000
#define	TV_MODULATOR_CNTL1__YFLT_EN__SHIFT                 0x00000002
#define	TV_MODULATOR_CNTL1__UVFLT_EN__SHIFT                0x00000003
#define	TV_MODULATOR_CNTL1__ALT_PHASE_EN__SHIFT            0x00000006
#define	TV_MODULATOR_CNTL1__SYNC_TIP_LEVEL__SHIFT          0x00000007
#define	TV_MODULATOR_CNTL1__SET_UP_LEVEL__SHIFT            0x00000008
#define	TV_MODULATOR_CNTL1__BLANK_LEVEL__SHIFT             0x00000010
#define	TV_MODULATOR_CNTL1__SLEW_RATE_LIMIT__SHIFT         0x00000017
#define	TV_MODULATOR_CNTL1__FORCE_BLACK_WHITE__SHIFT       0x00000018
#define	TV_MODULATOR_CNTL1__MV_VSYNC_AMP__SHIFT            0x0000001a
#define	TV_MODULATOR_CNTL1__MV_HSYNC_AMP__SHIFT            0x0000001b
#define	TV_MODULATOR_CNTL1__CY_FILT_BLEND__SHIFT           0x0000001c

// TV_MODULATOR_CNTL2
#define	TV_MODULATOR_CNTL2__U_BURST_LEVEL__SHIFT           0x00000000
#define	TV_MODULATOR_CNTL2__V_BURST_LEVEL__SHIFT           0x00000010
#define	TV_MODULATOR_CNTL2__SETUP_DELAY__SHIFT             0x0000001a

// TV_MV_MODE_CNTL
#define	TV_MV_MODE_CNTL__MV_AGC_CYC_MODE__SHIFT            0x00000000
#define	TV_MV_MODE_CNTL__MV_AGC_CYC_TMODE_EN__SHIFT        0x00000001
#define	TV_MV_MODE_CNTL__MV_AGC_AMPL_STEP__SHIFT           0x00000002
#define	TV_MV_MODE_CNTL__MV_AGC_CLK_DEVIDE_SEL__SHIFT      0x00000006
#define	TV_MV_MODE_CNTL__MV_OVRB_EN__SHIFT                 0x00000007
#define	TV_MV_MODE_CNTL__MV_OVRB_LEVEL__SHIFT              0x00000008

// TV_MV_STRIPE_CNTL
#define	TV_MV_STRIPE_CNTL__MV_LINE_1_PHASE__SHIFT          0x00000000
#define	TV_MV_STRIPE_CNTL__MV_LINE_2_PHASE__SHIFT          0x00000002
#define	TV_MV_STRIPE_CNTL__MV_LINE_3_PHASE__SHIFT          0x00000004
#define	TV_MV_STRIPE_CNTL__MV_LINE_4_PHASE__SHIFT          0x00000006
#define	TV_MV_STRIPE_CNTL__MV_LINE_5_PHASE__SHIFT          0x00000008

// TV_MV_LEVEL_CNTL
#define	TV_MV_LEVEL_CNTL__MV_BLANK_LEVEL__SHIFT            0x00000000
#define	TV_MV_LEVEL_CNTL__MV_SETUP_LEVEL__SHIFT            0x00000008
#define	TV_MV_LEVEL_CNTL__MV_AGC_AMPL_A__SHIFT             0x00000010
#define	TV_MV_LEVEL_CNTL__MV_AGC_AMPL_B__SHIFT             0x00000018

// TV_MV_LEVEL_CNTL2
#define	TV_MV_LEVEL_CNTL2__MV_AGC_AMPL_MAX__SHIFT          0x00000000
#define	TV_MV_LEVEL_CNTL2__MV_BP_LEVEL__SHIFT              0x00000008

// TV_PRE_DAC_MUX_CNTL
#define	TV_PRE_DAC_MUX_CNTL__Y_RED_EN__SHIFT               0x00000000
#define	TV_PRE_DAC_MUX_CNTL__C_GRN_EN__SHIFT               0x00000001
#define	TV_PRE_DAC_MUX_CNTL__CMP_BLU_EN__SHIFT             0x00000002
#define	TV_PRE_DAC_MUX_CNTL__DAC_DITHER_EN__SHIFT          0x00000003
#define	TV_PRE_DAC_MUX_CNTL__RED_MX__SHIFT                 0x00000004
#define	TV_PRE_DAC_MUX_CNTL__GRN_MX__SHIFT                 0x00000008
#define	TV_PRE_DAC_MUX_CNTL__BLU_MX__SHIFT                 0x0000000c
#define	TV_PRE_DAC_MUX_CNTL__FORCE_DAC_DATA__SHIFT         0x00000010

// TV_DAC_CNTL
#define	TV_DAC_CNTL__NBLANK__SHIFT                         0x00000000
#define	TV_DAC_CNTL__NHOLD__SHIFT                          0x00000001
#define	TV_DAC_CNTL__PEDESTAL__SHIFT                       0x00000002
#define	TV_DAC_CNTL__DETECT__SHIFT                         0x00000004
#define	TV_DAC_CNTL__CMPOUT__SHIFT                         0x00000005
#define	TV_DAC_CNTL__BGSLEEP__SHIFT                        0x00000006
#define	TV_DAC_CNTL__STD__SHIFT                            0x00000008
#define	TV_DAC_CNTL__MON__SHIFT                            0x0000000c
#define	TV_DAC_CNTL__BGADJ__SHIFT                          0x00000010
#define	TV_DAC_CNTL__DACADJ__SHIFT                         0x00000014
#define	TV_DAC_CNTL__RDACPD__SHIFT                         0x00000018
#define	TV_DAC_CNTL__GDACPD__SHIFT                         0x00000019
#define	TV_DAC_CNTL__BDACPD__SHIFT                         0x0000001a
#define	TV_DAC_CNTL__RDACDET__SHIFT                        0x0000001d
#define	TV_DAC_CNTL__GDACDET__SHIFT                        0x0000001e
#define	TV_DAC_CNTL__BDACDET__SHIFT                        0x0000001f

// TV_CRC_CNTL
#define	TV_CRC_CNTL__V_COMP_DATA_EN__SHIFT                 0x00000000
#define	TV_CRC_CNTL__V_COMP_GATE__SHIFT                    0x00000002
#define	TV_CRC_CNTL__V_COMP_EN__SHIFT                      0x00000003
#define	TV_CRC_CNTL__RST_SUBC_ONRSTRT__SHIFT               0x00000004
#define	TV_CRC_CNTL__CRC_TV_RSTRT_SEL__SHIFT               0x00000005

// TV_VIDEO_PORT_SIG
#define	TV_VIDEO_PORT_SIG__CRC_SIG__SHIFT                  0x00000000

// TV_VBI_CC_CNTL
#define	TV_VBI_CC_CNTL__VBI_CC_DATA__SHIFT                 0x00000000
#define	TV_VBI_CC_CNTL__VBI_CC_WT__SHIFT                   0x00000018
#define	TV_VBI_CC_CNTL__VBI_CC_WT_ACK__SHIFT               0x00000019
#define	TV_VBI_CC_CNTL__VBI_CC_HOLD__SHIFT                 0x0000001a
#define	TV_VBI_CC_CNTL__VBI_DECODE_EN__SHIFT               0x0000001f

// TV_VBI_EDS_CNTL
#define	TV_VBI_EDS_CNTL__VBI_EDS_DATA__SHIFT               0x00000000
#define	TV_VBI_EDS_CNTL__VBI_EDS_WT__SHIFT                 0x00000018
#define	TV_VBI_EDS_CNTL__VBI_EDS_WT_ACK__SHIFT             0x00000019
#define	TV_VBI_EDS_CNTL__VBI_EDS_HOLD__SHIFT               0x0000001a

// TV_VBI_20BIT_CNTL
#define	TV_VBI_20BIT_CNTL__VBI_20BIT_DATA0__SHIFT          0x00000000
#define	TV_VBI_20BIT_CNTL__VBI_20BIT_DATA1__SHIFT          0x00000010
#define	TV_VBI_20BIT_CNTL__VBI_20BIT_WT__SHIFT             0x00000018
#define	TV_VBI_20BIT_CNTL__VBI_20BIT_WT_ACK__SHIFT         0x00000019
#define	TV_VBI_20BIT_CNTL__VBI_20BIT_HOLD__SHIFT           0x0000001a

// TV_VBI_DTO_CNTL
#define	TV_VBI_DTO_CNTL__VBI_CC_DTO_P__SHIFT               0x00000000
#define	TV_VBI_DTO_CNTL__VBI_20BIT_DTO_P__SHIFT            0x00000010

// TV_VBI_LEVEL_CNTL
#define	TV_VBI_LEVEL_CNTL__VBI_CC_LEVEL__SHIFT             0x00000000
#define	TV_VBI_LEVEL_CNTL__VBI_20BIT_LEVEL__SHIFT          0x00000008
#define	TV_VBI_LEVEL_CNTL__VBI_CLK_RUNIN_GAIN__SHIFT       0x00000010

// TV_UV_ADR
#define	TV_UV_ADR__MAX_UV_ADR__SHIFT                       0x00000000
#define	TV_UV_ADR__TABLE1_BOT_ADR__SHIFT                   0x00000008
#define	TV_UV_ADR__TABLE3_TOP_ADR__SHIFT                   0x00000010
#define	TV_UV_ADR__MV_DECODE_EN__SHIFT                     0x00000018
#define	TV_UV_ADR__HCODE_TABLE_SEL__SHIFT                  0x00000019
#define	TV_UV_ADR__VCODE_TABLE_SEL__SHIFT                  0x0000001b
#define	TV_UV_ADR__MV_LINES_PER_STRIPE__SHIFT              0x0000001d
#define	TV_UV_ADR__SWITCH_TABLE_REQ__SHIFT                 0x0000001f

// TV_VSYNC_DIFF_CNTL
#define	TV_VSYNC_DIFF_CNTL__VSYNC_DIFF_MEASURE_EN__SHIFT   0x00000000
#define	TV_VSYNC_DIFF_CNTL__VSYNC_RESTART_AT_LIMIT__SHIFT  0x00000001
#define	TV_VSYNC_DIFF_CNTL__VSYNC_HW_LOCK_EN__SHIFT        0x00000002
#define	TV_VSYNC_DIFF_CNTL__VSYNC_HW_LOCK_TYPE__SHIFT      0x00000003
#define	TV_VSYNC_DIFF_CNTL__VSYNC_SLIP_REQ_EN__SHIFT       0x00000004
#define	TV_VSYNC_DIFF_CNTL__INVERT_LOCK_CNTL__SHIFT        0x00000005
#define	TV_VSYNC_DIFF_CNTL__SLIP_DURING_HSYNC_ONLY__SHIFT  0x00000006
#define	TV_VSYNC_DIFF_CNTL__RESTART_TWICE__SHIFT           0x00000007
#define	TV_VSYNC_DIFF_CNTL__DELAY_RESTART__SHIFT           0x00000008

// TV_VSYNC_DIFF_LIMITS
#define	TV_VSYNC_DIFF_LIMITS__DIFF_LIMIT_LOW__SHIFT        0x00000000
#define	TV_VSYNC_DIFF_LIMITS__DIFF_LIMIT_HIGH__SHIFT       0x00000010

// TV_VSYNC_DIFF_RD_DATA
#define	TV_VSYNC_DIFF_RD_DATA__UPDATE_END_TOGGLE__SHIFT    0x00000000
#define	TV_VSYNC_DIFF_RD_DATA__VSYNC_DIFF__SHIFT           0x00000001
#define	TV_VSYNC_DIFF_RD_DATA__VSYNC_DIFF_OVERFLOW__SHIFT  0x0000000d
#define	TV_VSYNC_DIFF_RD_DATA__TV_FIRST__SHIFT             0x0000000e
#define	TV_VSYNC_DIFF_RD_DATA__UPDATE_START_TOGGLE__SHIFT  0x0000000f

// CP_RB_BASE
#define	CP_RB_BASE__RB_BASE__SHIFT                         0x00000002

// CP_RB_CNTL
#define	CP_RB_CNTL__RB_BUFSZ__SHIFT                        0x00000000
#define	CP_RB_CNTL__RB_BLKSZ__SHIFT                        0x00000008
#define	CP_RB_CNTL__BUF_SWAP__SHIFT                        0x00000010
#define	CP_RB_CNTL__MAX_FETCH__SHIFT                       0x00000012
#define	CP_RB_CNTL__RB_NO_UPDATE__SHIFT                    0x0000001b
#define	CP_RB_CNTL__RB_RPTR_WR_ENA__SHIFT                  0x0000001f

// CP_RB_RPTR_ADDR
#define	CP_RB_RPTR_ADDR__RB_RPTR_SWAP__SHIFT               0x00000000
#define	CP_RB_RPTR_ADDR__RB_RPTR_ADDR__SHIFT               0x00000002

// CP_RB_RPTR
#define	CP_RB_RPTR__RB_RPTR__SHIFT                         0x00000000

// CP_RB_RPTR_WR
#define	CP_RB_RPTR_WR__RB_RPTR_WR__SHIFT                   0x00000000

// CP_RB_WPTR
#define	CP_RB_WPTR__RB_WPTR__SHIFT                         0x00000000

// CP_RB_WPTR_DELAY
#define	CP_RB_WPTR_DELAY__PRE_WRITE_TIMER__SHIFT           0x00000000
#define	CP_RB_WPTR_DELAY__PRE_WRITE_LIMIT__SHIFT           0x0000001c

// CP_IB_BASE
#define	CP_IB_BASE__IB_BASE__SHIFT                         0x00000002

// CP_IB_BUFSZ
#define	CP_IB_BUFSZ__IB_BUFSZ__SHIFT                       0x00000000

// CP_IB2_BASE
#define	CP_IB2_BASE__IB2_BASE__SHIFT                       0x00000002

// CP_IB2_BUFSZ
#define	CP_IB2_BUFSZ__IB2_BUFSZ__SHIFT                     0x00000000

// CP_CSQ_CNTL
#define	CP_CSQ_CNTL__CSQ_CNT_PRIMARY_R2__SHIFT             0x00000000
#define	CP_CSQ_CNTL__CSQ_CNT_INDIRECT_R2__SHIFT            0x00000009
#define	CP_CSQ_CNTL__CSQ_CNT_INDIRECT2__SHIFT              0x00000012
#define	CP_CSQ_CNTL__CSQ_MODE__SHIFT                       0x0000001c

// CP_CSQ_APER_PRIMARY
#define	CP_CSQ_APER_PRIMARY__CP_CSQ_APER_PRIMARY__SHIFT    0x00000000

// CP_CSQ_APER_INDIRECT
#define	CP_CSQ_APER_INDIRECT__CP_CSQ_APER_INDIRECT__SHIFT  0x00000000

// CP_CSQ_APER_INDIRECT2
#define	CP_CSQ_APER_INDIRECT2__CP_CSQ_APER_INDIRECT2__SHIFT 0x00000000

// CP_CSQ_MODE
#define	CP_CSQ_MODE__INDIRECT2_START__SHIFT                0x00000000
#define	CP_CSQ_MODE__INDIRECT1_START__SHIFT                0x00000008
#define	CP_CSQ_MODE__CSQ_INDIRECT2_MODE__SHIFT             0x0000001a
#define	CP_CSQ_MODE__CSQ_INDIRECT2_ENABLE__SHIFT           0x0000001b
#define	CP_CSQ_MODE__CSQ_INDIRECT1_MODE__SHIFT             0x0000001c
#define	CP_CSQ_MODE__CSQ_INDIRECT1_ENABLE__SHIFT           0x0000001d
#define	CP_CSQ_MODE__CSQ_PRIMARY_MODE__SHIFT               0x0000001e
#define	CP_CSQ_MODE__CSQ_PRIMARY_ENABLE__SHIFT             0x0000001f

// CP_ME_CNTL
#define	CP_ME_CNTL__ME_STAT__SHIFT                         0x00000000
#define	CP_ME_CNTL__ME_STATMUX__SHIFT                      0x00000010
#define	CP_ME_CNTL__ME_BUSY__SHIFT                         0x0000001d
#define	CP_ME_CNTL__ME_MODE__SHIFT                         0x0000001e
#define	CP_ME_CNTL__ME_STEP__SHIFT                         0x0000001f

// CP_ME_RAM_ADDR
#define	CP_ME_RAM_ADDR__ME_RAM_ADDR__SHIFT                 0x00000000

// CP_ME_RAM_RADDR
#define	CP_ME_RAM_RADDR__ME_RAM_RADDR__SHIFT               0x00000000

// CP_ME_RAM_DATAH
#define	CP_ME_RAM_DATAH__ME_RAM_DATAH__SHIFT               0x00000000

// CP_ME_RAM_DATAL
#define	CP_ME_RAM_DATAL__ME_RAM_DATAL__SHIFT               0x00000000

// CP_DEBUG
#define	CP_DEBUG__CP_DEBUG__SHIFT                          0x00000000

// SCRATCH_REG0
#define	SCRATCH_REG0__SCRATCH_REG0__SHIFT                  0x00000000
#define	GUI_SCRATCH_REG0__SCRATCH_REG0__SHIFT              0x00000000

// SCRATCH_REG1
#define	SCRATCH_REG1__SCRATCH_REG1__SHIFT                  0x00000000
#define	GUI_SCRATCH_REG1__SCRATCH_REG1__SHIFT              0x00000000

// SCRATCH_REG2
#define	SCRATCH_REG2__SCRATCH_REG2__SHIFT                  0x00000000
#define	GUI_SCRATCH_REG2__SCRATCH_REG2__SHIFT              0x00000000

// SCRATCH_REG3
#define	SCRATCH_REG3__SCRATCH_REG3__SHIFT                  0x00000000
#define	GUI_SCRATCH_REG3__SCRATCH_REG3__SHIFT              0x00000000

// SCRATCH_REG4
#define	SCRATCH_REG4__SCRATCH_REG4__SHIFT                  0x00000000
#define	GUI_SCRATCH_REG4__SCRATCH_REG4__SHIFT              0x00000000

// SCRATCH_REG5
#define	SCRATCH_REG5__SCRATCH_REG5__SHIFT                  0x00000000
#define	GUI_SCRATCH_REG5__SCRATCH_REG5__SHIFT              0x00000000

// SCRATCH_REG6
#define	SCRATCH_REG6__SCRATCH_REG6__SHIFT                  0x00000000
#define	GUI_SCRATCH_REG6__SCRATCH_REG6__SHIFT              0x00000000

// SCRATCH_REG7
#define	SCRATCH_REG7__SCRATCH_REG7__SHIFT                  0x00000000
#define	GUI_SCRATCH_REG7__SCRATCH_REG7__SHIFT              0x00000000

// SCRATCH_UMSK
#define	SCRATCH_UMSK__SCRATCH_UMSK_R2__SHIFT               0x00000000
#define	SCRATCH_UMSK__SCRATCH_SWAP__SHIFT                  0x00000010

// SCRATCH_ADDR
#define	SCRATCH_ADDR__SCRATCH_ADDR__SHIFT                  0x00000005

// DMA_GUI_TABLE_ADDR
#define	DMA_GUI_TABLE_ADDR__CP_SYNC__SHIFT                 0x00000000
#define	DMA_GUI_TABLE_ADDR__TABLE_ADDR__SHIFT              0x00000004

// DMA_GUI_SRC_ADDR
#define	DMA_GUI_SRC_ADDR__SRC_ADDR__SHIFT                  0x00000000

// DMA_GUI_DST_ADDR
#define	DMA_GUI_DST_ADDR__DST_ADDR__SHIFT                  0x00000000

// DMA_GUI_COMMAND
#define	DMA_GUI_COMMAND__BYTE_COUNT__SHIFT                 0x00000000
#define	DMA_GUI_COMMAND__SRC_SWAP__SHIFT                   0x00000016
#define	DMA_GUI_COMMAND__DST_SWAP__SHIFT                   0x00000018
#define	DMA_GUI_COMMAND__SAS__SHIFT                        0x0000001a
#define	DMA_GUI_COMMAND__DAS__SHIFT                        0x0000001b
#define	DMA_GUI_COMMAND__SAIC__SHIFT                       0x0000001c
#define	DMA_GUI_COMMAND__DAIC__SHIFT                       0x0000001d
#define	DMA_GUI_COMMAND__INTDIS__SHIFT                     0x0000001e
#define	DMA_GUI_COMMAND__EOL__SHIFT                        0x0000001f

// DMA_GUI_STATUS
#define	DMA_GUI_STATUS__DTAQ_AVAIL__SHIFT                  0x00000000
#define	DMA_GUI_STATUS__LAST_TABLE_NUM__SHIFT              0x00000008
#define	DMA_GUI_STATUS__CURRENT_TABLE_NUM__SHIFT           0x0000000c
#define	DMA_GUI_STATUS__ABORT_EN__SHIFT                    0x00000014
#define	DMA_GUI_STATUS__ACTIVE__SHIFT                      0x00000015
#define	DMA_GUI_STATUS__SWAP__SHIFT                        0x00000016

// DMA_GUI_ACT_DSCRPTR
#define	DMA_GUI_ACT_DSCRPTR__TABLE_ADDR__SHIFT             0x00000004

// CP_GUI_SRC_ADDR
#define	CP_GUI_SRC_ADDR__CP_GUI_SRC_ADDR__SHIFT            0x00000000

// CP_GUI_DST_ADDR
#define	CP_GUI_DST_ADDR__CP_GUI_DST_ADDR__SHIFT            0x00000000

// CP_GUI_COMMAND
#define	CP_GUI_COMMAND__CP_GUI_COMMAND__SHIFT              0x00000000

// DMA_VID_TABLE_ADDR
#define	DMA_VID_TABLE_ADDR__CP_SYNC__SHIFT                 0x00000000
#define	DMA_VID_TABLE_ADDR__TABLE_ADDR__SHIFT              0x00000004

// DMA_VID_SRC_ADDR
#define	DMA_VID_SRC_ADDR__SRC_ADDR__SHIFT                  0x00000000

// DMA_VID_DST_ADDR
#define	DMA_VID_DST_ADDR__DST_ADDR__SHIFT                  0x00000000

// DMA_VID_COMMAND
#define	DMA_VID_COMMAND__BYTE_COUNT__SHIFT                 0x00000000
#define	DMA_VID_COMMAND__SRC_SWAP__SHIFT                   0x00000016
#define	DMA_VID_COMMAND__DST_SWAP__SHIFT                   0x00000018
#define	DMA_VID_COMMAND__SAS__SHIFT                        0x0000001a
#define	DMA_VID_COMMAND__DAS__SHIFT                        0x0000001b
#define	DMA_VID_COMMAND__SAIC__SHIFT                       0x0000001c
#define	DMA_VID_COMMAND__DAIC__SHIFT                       0x0000001d
#define	DMA_VID_COMMAND__INTDIS__SHIFT                     0x0000001e
#define	DMA_VID_COMMAND__EOL__SHIFT                        0x0000001f

// DMA_VID_STATUS
#define	DMA_VID_STATUS__DTAQ_AVAIL__SHIFT                  0x00000000
#define	DMA_VID_STATUS__LAST_TABLE_NUM__SHIFT              0x00000008
#define	DMA_VID_STATUS__CURRENT_TABLE_NUM__SHIFT           0x0000000c
#define	DMA_VID_STATUS__ABORT_EN__SHIFT                    0x00000014
#define	DMA_VID_STATUS__ACTIVE__SHIFT                      0x00000015
#define	DMA_VID_STATUS__SWAP__SHIFT                        0x00000016

// DMA_VID_ACT_DSCRPTR
#define	DMA_VID_ACT_DSCRPTR__TABLE_ADDR__SHIFT             0x00000004

// CP_VID_SRC_ADDR
#define	CP_VID_SRC_ADDR__CP_VID_SRC_ADDR__SHIFT            0x00000000

// CP_VID_DST_ADDR
#define	CP_VID_DST_ADDR__CP_VID_DST_ADDR__SHIFT            0x00000000

// CP_VID_COMMAND
#define	CP_VID_COMMAND__CP_VID_COMMAND__SHIFT              0x00000000

// CP_CSQ2_STAT
#define	CP_CSQ2_STAT__CSQ_WPTR_INDIRECT__SHIFT             0x00000000
#define	CP_CSQ2_STAT__CSQ_RPTR_INDIRECT2__SHIFT            0x00000009
#define	CP_CSQ2_STAT__CSQ_WPTR_INDIRECT2__SHIFT            0x00000012

// CP_CSQ_ADDR
#define	CP_CSQ_ADDR__CSQ_ADDR_R2__SHIFT                    0x00000002

// CP_CSQ_DATA
#define	CP_CSQ_DATA__CSQ_DATA__SHIFT                       0x00000000

// CP_CSQ_STAT
#define	CP_CSQ_STAT__CSQ_RPTR_PRIMARY_R2__SHIFT            0x00000000
#define	CP_CSQ_STAT__CSQ_WPTR_PRIMARY_R2__SHIFT            0x00000009
#define	CP_CSQ_STAT__CSQ_RPTR_INDIRECT_R2__SHIFT           0x00000012

// CP_STAT
#define	CP_STAT__MRU_BUSY__SHIFT                           0x00000000
#define	CP_STAT__MWU_BUSY__SHIFT                           0x00000001
#define	CP_STAT__RSIU_BUSY__SHIFT                          0x00000002
#define	CP_STAT__RCIU_BUSY__SHIFT                          0x00000003
#define	CP_STAT__CSF_PRIMARY_BUSY__SHIFT                   0x00000009
#define	CP_STAT__CSF_INDIRECT_BUSY__SHIFT                  0x0000000a
#define	CP_STAT__CSQ_PRIMARY_BUSY__SHIFT                   0x0000000b
#define	CP_STAT__CSQ_INDIRECT_BUSY__SHIFT                  0x0000000c
#define	CP_STAT__CSI_BUSY__SHIFT                           0x0000000d
#define	CP_STAT__CSF_INDIRECT2_BUSY__SHIFT                 0x0000000e
#define	CP_STAT__CSQ_INDIRECT2_BUSY__SHIFT                 0x0000000f
#define	CP_STAT__GUIDMA_BUSY__SHIFT                        0x0000001c
#define	CP_STAT__VIDDMA_BUSY__SHIFT                        0x0000001d
#define	CP_STAT__CMDSTRM_BUSY__SHIFT                       0x0000001e
#define	CP_STAT__CP_BUSY__SHIFT                            0x0000001f

// SE_PORT_DATA0
#define	SE_PORT_DATA0__DATAPORT0__SHIFT                    0x00000000

// SE_PORT_DATA1
#define	SE_PORT_DATA1__DATAPORT1__SHIFT                    0x00000000

// SE_PORT_DATA2
#define	SE_PORT_DATA2__DATAPORT2__SHIFT                    0x00000000

// SE_PORT_DATA3
#define	SE_PORT_DATA3__DATAPORT3__SHIFT                    0x00000000

// SE_PORT_DATA4
#define	SE_PORT_DATA4__DATAPORT4__SHIFT                    0x00000000

// SE_PORT_DATA5
#define	SE_PORT_DATA5__DATAPORT5__SHIFT                    0x00000000

// SE_PORT_DATA6
#define	SE_PORT_DATA6__DATAPORT6__SHIFT                    0x00000000

// SE_PORT_DATA7
#define	SE_PORT_DATA7__DATAPORT7__SHIFT                    0x00000000

// SE_PORT_DATA8
#define	SE_PORT_DATA8__DATAPORT8__SHIFT                    0x00000000

// SE_PORT_DATA9
#define	SE_PORT_DATA9__DATAPORT9__SHIFT                    0x00000000

// SE_PORT_DATA10
#define	SE_PORT_DATA10__DATAPORT10__SHIFT                  0x00000000

// SE_PORT_DATA11
#define	SE_PORT_DATA11__DATAPORT11__SHIFT                  0x00000000

// SE_PORT_DATA12
#define	SE_PORT_DATA12__DATAPORT12__SHIFT                  0x00000000

// SE_PORT_DATA13
#define	SE_PORT_DATA13__DATAPORT13__SHIFT                  0x00000000

// SE_PORT_DATA14
#define	SE_PORT_DATA14__DATAPORT14__SHIFT                  0x00000000

// SE_PORT_DATA15
#define	SE_PORT_DATA15__DATAPORT15__SHIFT                  0x00000000

// SE_PORT_IDX0
#define	SE_PORT_IDX0__IDXPORT0__SHIFT                      0x00000000

// SE_PORT_IDX1
#define	SE_PORT_IDX1__IDXPORT1__SHIFT                      0x00000000

// SE_PORT_IDX2
#define	SE_PORT_IDX2__IDXPORT2__SHIFT                      0x00000000

// SE_PORT_IDX3
#define	SE_PORT_IDX3__IDXPORT3__SHIFT                      0x00000000

// SE_PORT_IDX4
#define	SE_PORT_IDX4__IDXPORT4__SHIFT                      0x00000000

// SE_PORT_IDX5
#define	SE_PORT_IDX5__IDXPORT5__SHIFT                      0x00000000

// SE_PORT_IDX6
#define	SE_PORT_IDX6__IDXPORT6__SHIFT                      0x00000000

// SE_PORT_IDX7
#define	SE_PORT_IDX7__IDXPORT7__SHIFT                      0x00000000

// SE_PORT_IDX8
#define	SE_PORT_IDX8__IDXPORT8__SHIFT                      0x00000000

// SE_PORT_IDX9
#define	SE_PORT_IDX9__IDXPORT9__SHIFT                      0x00000000

// SE_PORT_IDX10
#define	SE_PORT_IDX10__IDXPORT10__SHIFT                    0x00000000

// SE_PORT_IDX11
#define	SE_PORT_IDX11__IDXPORT11__SHIFT                    0x00000000

// SE_PORT_IDX12
#define	SE_PORT_IDX12__IDXPORT12__SHIFT                    0x00000000

// SE_PORT_IDX13
#define	SE_PORT_IDX13__IDXPORT13__SHIFT                    0x00000000

// SE_PORT_IDX14
#define	SE_PORT_IDX14__IDXPORT14__SHIFT                    0x00000000

// SE_PORT_IDX15
#define	SE_PORT_IDX15__IDXPORT15__SHIFT                    0x00000000

// SE_VAP_CNTL
#define	SE_VAP_CNTL__TCL_ENA__SHIFT                        0x00000000
#define	SE_VAP_CNTL__PROG_VTX_SHADER_ENA__SHIFT            0x00000002
#define	SE_VAP_CNTL__PER_VTX_MTX_SEL_ENA__SHIFT            0x00000003
#define	SE_VAP_CNTL__SINGLE_BUF_STATE_ENA__SHIFT           0x00000004
#define	SE_VAP_CNTL__FORCE_W_TO_ONE__SHIFT                 0x00000010
#define	SE_VAP_CNTL__D3D_TEX_DEFAULT__SHIFT                0x00000011
#define	SE_VAP_CNTL__VF_MAX_VTX_NUM__SHIFT                 0x00000012
#define	SE_VAP_CNTL__DX_CLIP_SPACE_DEF__SHIFT              0x00000016

// SE_VF_CNTL
#define	SE_VF_CNTL__PRIM_TYPE__SHIFT                       0x00000000
#define	SE_VF_CNTL__PRIM_WALK__SHIFT                       0x00000004
#define	SE_VF_CNTL__COLOR_ORDER__SHIFT                     0x00000006
#define	SE_VF_CNTL__TCL_OUTPUT_CTL_ENA__SHIFT              0x00000009
#define	SE_VF_CNTL__PROG_STREAM_ENA__SHIFT                 0x0000000a
#define	SE_VF_CNTL__INDEX_SIZE__SHIFT                      0x0000000b
#define	SE_VF_CNTL__NUM_VERTICES__SHIFT                    0x00000010

// SE_VTX_FMT_0
#define	SE_VTX_FMT_0__VTX_Z0_PRESENT__SHIFT                0x00000000
#define	SE_VTX_FMT_0__VTX_W0_PRESENT__SHIFT                0x00000001
#define	SE_VTX_FMT_0__VTX_BLEND_WEIGHT_CNT__SHIFT          0x00000002
#define	SE_VTX_FMT_0__VTX_PV_MTX_SEL_PRESENT__SHIFT        0x00000005
#define	SE_VTX_FMT_0__VTX_N0_PRESENT__SHIFT                0x00000006
#define	SE_VTX_FMT_0__VTX_PT_SIZE_PRESENT__SHIFT           0x00000007
#define	SE_VTX_FMT_0__VTX_DISCRETE_FOG_PRESENT__SHIFT      0x00000008
#define	SE_VTX_FMT_0__VTX_SHININESS_0_PRESENT__SHIFT       0x00000009
#define	SE_VTX_FMT_0__VTX_SHININESS_1_PRESENT__SHIFT       0x0000000a
#define	SE_VTX_FMT_0__VTX_COLOR_0_FMT__SHIFT               0x0000000b
#define	SE_VTX_FMT_0__VTX_COLOR_1_FMT__SHIFT               0x0000000d
#define	SE_VTX_FMT_0__VTX_COLOR_2_FMT__SHIFT               0x0000000f
#define	SE_VTX_FMT_0__VTX_COLOR_3_FMT__SHIFT               0x00000011
#define	SE_VTX_FMT_0__VTX_COLOR_4_FMT__SHIFT               0x00000013
#define	SE_VTX_FMT_0__VTX_COLOR_5_FMT__SHIFT               0x00000015
#define	SE_VTX_FMT_0__VTX_COLOR_6_FMT__SHIFT               0x00000017
#define	SE_VTX_FMT_0__VTX_COLOR_7_FMT__SHIFT               0x00000019
#define	SE_VTX_FMT_0__VTX_XY1_PRESENT__SHIFT               0x0000001c
#define	SE_VTX_FMT_0__VTX_Z1_PRESENT__SHIFT                0x0000001d
#define	SE_VTX_FMT_0__VTX_W1_PRESENT__SHIFT                0x0000001e
#define	SE_VTX_FMT_0__VTX_N1_PRESENT__SHIFT                0x0000001f

// SE_VTX_FMT_1
#define	SE_VTX_FMT_1__TEX_0_COMP_CNT__SHIFT                0x00000000
#define	SE_VTX_FMT_1__TEX_1_COMP_CNT__SHIFT                0x00000003
#define	SE_VTX_FMT_1__TEX_2_COMP_CNT__SHIFT                0x00000006
#define	SE_VTX_FMT_1__TEX_3_COMP_CNT__SHIFT                0x00000009
#define	SE_VTX_FMT_1__TEX_4_COMP_CNT__SHIFT                0x0000000c
#define	SE_VTX_FMT_1__TEX_5_COMP_CNT__SHIFT                0x0000000f

// SE_TCL_OUTPUT_VTX_FMT_0
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_Z0_PRESENT__SHIFT     0x00000000
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_W0_PRESENT__SHIFT     0x00000001
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_BLEND_WEIGHT_CNT__SHIFT 0x00000002
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_PV_MTX_SEL_PRESENT__SHIFT 0x00000005
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_N0_PRESENT__SHIFT     0x00000006
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_PT_SIZE_PRESENT__SHIFT 0x00000007
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_DISCRETE_FOG_PRESENT__SHIFT 0x00000008
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_SHININESS_0_PRESENT__SHIFT 0x00000009
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_SHININESS_1_PRESENT__SHIFT 0x0000000a
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_0_FMT__SHIFT    0x0000000b
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_1_FMT__SHIFT    0x0000000d
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_2_FMT__SHIFT    0x0000000f
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_3_FMT__SHIFT    0x00000011
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_4_FMT__SHIFT    0x00000013
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_5_FMT__SHIFT    0x00000015
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_6_FMT__SHIFT    0x00000017
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_7_FMT__SHIFT    0x00000019
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_XY1_PRESENT__SHIFT    0x0000001c
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_Z1_PRESENT__SHIFT     0x0000001d
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_W1_PRESENT__SHIFT     0x0000001e
#define	SE_TCL_OUTPUT_VTX_FMT_0__VTX_N1_PRESENT__SHIFT     0x0000001f

// SE_TCL_OUTPUT_VTX_FMT_1
#define	SE_TCL_OUTPUT_VTX_FMT_1__TEX_0_COMP_CNT__SHIFT     0x00000000
#define	SE_TCL_OUTPUT_VTX_FMT_1__TEX_1_COMP_CNT__SHIFT     0x00000003
#define	SE_TCL_OUTPUT_VTX_FMT_1__TEX_2_COMP_CNT__SHIFT     0x00000006
#define	SE_TCL_OUTPUT_VTX_FMT_1__TEX_3_COMP_CNT__SHIFT     0x00000009
#define	SE_TCL_OUTPUT_VTX_FMT_1__TEX_4_COMP_CNT__SHIFT     0x0000000c
#define	SE_TCL_OUTPUT_VTX_FMT_1__TEX_5_COMP_CNT__SHIFT     0x0000000f

// SE_VPORT_XSCALE
#define	SE_VPORT_XSCALE__VPORT_XSCALE__SHIFT               0x00000000

// SE_VPORT_XOFFSET
#define	SE_VPORT_XOFFSET__VPORT_XOFFSET__SHIFT             0x00000000

// SE_VPORT_YSCALE
#define	SE_VPORT_YSCALE__VPORT_YSCALE__SHIFT               0x00000000

// SE_VPORT_YOFFSET
#define	SE_VPORT_YOFFSET__VPORT_YOFFSET__SHIFT             0x00000000

// SE_VPORT_ZSCALE
#define	SE_VPORT_ZSCALE__VPORT_ZSCALE__SHIFT               0x00000000

// SE_VPORT_ZOFFSET
#define	SE_VPORT_ZOFFSET__VPORT_ZOFFSET__SHIFT             0x00000000

// SE_VTE_CNTL
#define	SE_VTE_CNTL__VPORT_X_SCALE_ENA__SHIFT              0x00000000
#define	SE_VTE_CNTL__VPORT_X_OFFSET_ENA__SHIFT             0x00000001
#define	SE_VTE_CNTL__VPORT_Y_SCALE_ENA__SHIFT              0x00000002
#define	SE_VTE_CNTL__VPORT_Y_OFFSET_ENA__SHIFT             0x00000003
#define	SE_VTE_CNTL__VPORT_Z_SCALE_ENA__SHIFT              0x00000004
#define	SE_VTE_CNTL__VPORT_Z_OFFSET_ENA__SHIFT             0x00000005
#define	SE_VTE_CNTL__VTX_XY_FMT__SHIFT                     0x00000008
#define	SE_VTE_CNTL__VTX_Z_FMT__SHIFT                      0x00000009
#define	SE_VTE_CNTL__VTX_W0_FMT__SHIFT                     0x0000000a
#define	SE_VTE_CNTL__VTX_W0_NORMALIZE__SHIFT               0x0000000b
#define	SE_VTE_CNTL__VTX_ST_DENORMALIZED__SHIFT            0x0000000c

// SE_W0_RANGE
#define	SE_W0_RANGE__W0_RANGE__SHIFT                       0x00000000

// SE_VTX_NUM_ARRAYS
#define	SE_VTX_NUM_ARRAYS__VTX_NUM_ARRAYS_M9__SHIFT        0x00000000
#define	SE_VTX_NUM_ARRAYS__VTX_REUSE_DISABLE__SHIFT        0x00000004
#define	SE_VTX_NUM_ARRAYS__VC_PFETCH__SHIFT                0x0000000e

// SE_VTX_AOS_ATTR01
#define	SE_VTX_AOS_ATTR01__VTX_AOS_COUNT0_R2__SHIFT        0x00000000
#define	SE_VTX_AOS_ATTR01__VTX_AOS_STRIDE0_R2__SHIFT       0x00000008
#define	SE_VTX_AOS_ATTR01__VTX_AOS_COUNT1_R2__SHIFT        0x00000010
#define	SE_VTX_AOS_ATTR01__VTX_AOS_STRIDE1_R2__SHIFT       0x00000018

// SE_VTX_AOS_ADDR0
#define	SE_VTX_AOS_ADDR0__VTX_AOS_ADDR0__SHIFT             0x00000002

// SE_VTX_AOS_ADDR1
#define	SE_VTX_AOS_ADDR1__VTX_AOS_ADDR1__SHIFT             0x00000002

// SE_VTX_AOS_ATTR23
#define	SE_VTX_AOS_ATTR23__VTX_AOS_COUNT2_R2__SHIFT        0x00000000
#define	SE_VTX_AOS_ATTR23__VTX_AOS_STRIDE2_R2__SHIFT       0x00000008
#define	SE_VTX_AOS_ATTR23__VTX_AOS_COUNT3_R2__SHIFT        0x00000010
#define	SE_VTX_AOS_ATTR23__VTX_AOS_STRIDE3_R2__SHIFT       0x00000018

// SE_VTX_AOS_ADDR2
#define	SE_VTX_AOS_ADDR2__VTX_AOS_ADDR2__SHIFT             0x00000002

// SE_VTX_AOS_ADDR3
#define	SE_VTX_AOS_ADDR3__VTX_AOS_ADDR3__SHIFT             0x00000002

// SE_VTX_AOS_ATTR45
#define	SE_VTX_AOS_ATTR45__VTX_AOS_COUNT4_R2__SHIFT        0x00000000
#define	SE_VTX_AOS_ATTR45__VTX_AOS_STRIDE4_R2__SHIFT       0x00000008
#define	SE_VTX_AOS_ATTR45__VTX_AOS_COUNT5_R2__SHIFT        0x00000010
#define	SE_VTX_AOS_ATTR45__VTX_AOS_STRIDE5_R2__SHIFT       0x00000018

// SE_VTX_AOS_ADDR4
#define	SE_VTX_AOS_ADDR4__VTX_AOS_ADDR4__SHIFT             0x00000002

// SE_VTX_AOS_ADDR5
#define	SE_VTX_AOS_ADDR5__VTX_AOS_ADDR5__SHIFT             0x00000002

// SE_VTX_AOS_ATTR67
#define	SE_VTX_AOS_ATTR67__VTX_AOS_COUNT6_R2__SHIFT        0x00000000
#define	SE_VTX_AOS_ATTR67__VTX_AOS_STRIDE6_R2__SHIFT       0x00000008
#define	SE_VTX_AOS_ATTR67__VTX_AOS_COUNT7_R2__SHIFT        0x00000010
#define	SE_VTX_AOS_ATTR67__VTX_AOS_STRIDE7_R2__SHIFT       0x00000018

// SE_VTX_AOS_ADDR6
#define	SE_VTX_AOS_ADDR6__VTX_AOS_ADDR6__SHIFT             0x00000002

// SE_VTX_AOS_ADDR7
#define	SE_VTX_AOS_ADDR7__VTX_AOS_ADDR7__SHIFT             0x00000002

// SE_VTX_AOS_ATTR89
#define	SE_VTX_AOS_ATTR89__VTX_AOS_COUNT8_R2__SHIFT        0x00000000
#define	SE_VTX_AOS_ATTR89__VTX_AOS_STRIDE8_R2__SHIFT       0x00000008
#define	SE_VTX_AOS_ATTR89__VTX_AOS_COUNT9_R2__SHIFT        0x00000010
#define	SE_VTX_AOS_ATTR89__VTX_AOS_STRIDE9_R2__SHIFT       0x00000018

// SE_VTX_AOS_ADDR8
#define	SE_VTX_AOS_ADDR8__VTX_AOS_ADDR8__SHIFT             0x00000002

// SE_VTX_AOS_ADDR9
#define	SE_VTX_AOS_ADDR9__VTX_AOS_ADDR9__SHIFT             0x00000002

// SE_VTX_AOS_ATTR1011
#define	SE_VTX_AOS_ATTR1011__VTX_AOS_COUNT10_R2__SHIFT     0x00000000
#define	SE_VTX_AOS_ATTR1011__VTX_AOS_STRIDE10_R2__SHIFT    0x00000008
#define	SE_VTX_AOS_ATTR1011__VTX_AOS_COUNT11_R2__SHIFT     0x00000010
#define	SE_VTX_AOS_ATTR1011__VTX_AOS_STRIDE11_R2__SHIFT    0x00000018

// SE_VTX_AOS_ADDR10
#define	SE_VTX_AOS_ADDR10__VTX_AOS_ADDR10__SHIFT           0x00000002

// SE_VTX_AOS_ADDR11
#define	SE_VTX_AOS_ADDR11__VTX_AOS_ADDR11__SHIFT           0x00000002

// SE_VF_MAX_VTX_INDX
#define	SE_VF_MAX_VTX_INDX__MAX_INDX__SHIFT                0x00000000

// SE_VF_MIN_VTX_INDX
#define	SE_VF_MIN_VTX_INDX__MIN_INDX__SHIFT                0x00000000

// SE_VAP_PERF_CNTL_0
#define	SE_VAP_PERF_CNTL_0__PERF_SEL_0__SHIFT              0x00000000
#define	SE_VAP_PERF_CNTL_0__CLR_PERF_0__SHIFT              0x00000004
#define	SE_VAP_PERF_CNTL_0__EN_PERF_0__SHIFT               0x00000005
#define	SE_VAP_PERF_CNTL_0__NUM_VERTS_TO_BYPASS_0__SHIFT   0x00000008
#define	SE_VAP_PERF_CNTL_0__NUM_VERTS_TO_COUNT_0__SHIFT    0x00000010

// SE_VAP_PERF_CNTL_1
#define	SE_VAP_PERF_CNTL_1__PERF_SEL_1__SHIFT              0x00000000
#define	SE_VAP_PERF_CNTL_1__CLR_PERF_1__SHIFT              0x00000004
#define	SE_VAP_PERF_CNTL_1__EN_PERF_1__SHIFT               0x00000005
#define	SE_VAP_PERF_CNTL_1__NUM_VERTS_TO_BYPASS_1__SHIFT   0x00000008
#define	SE_VAP_PERF_CNTL_1__NUM_VERTS_TO_COUNT_1__SHIFT    0x00000010

// SE_VAP_PERF_COUNT_0
#define	SE_VAP_PERF_COUNT_0__PERF_COUNT_0__SHIFT           0x00000000

// SE_VAP_PERF_COUNT_1
#define	SE_VAP_PERF_COUNT_1__PERF_COUNT_1__SHIFT           0x00000000

// SE_DEBUG
#define	SE_DEBUG__SE_DEBUG__SHIFT                          0x00000000

// SE_VAP_CNTL_STATUS
#define	SE_VAP_CNTL_STATUS__VC_SWAP__SHIFT                 0x00000000
#define	SE_VAP_CNTL_STATUS__TCL_BYPASS__SHIFT              0x00000008
#define	SE_VAP_CNTL_STATUS__TCL_BUSY__SHIFT                0x0000000b
#define	SE_VAP_CNTL_STATUS__PERF_BUSY__SHIFT               0x00000010
#define	SE_VAP_CNTL_STATUS__PRIMITIVE_BYPASS_BUSY__SHIFT   0x00000018
#define	SE_VAP_CNTL_STATUS__RCP_BUSY__SHIFT                0x00000019
#define	SE_VAP_CNTL_STATUS__VAPB_RBIU_SLAVE_BUSY__SHIFT    0x0000001a
#define	SE_VAP_CNTL_STATUS__MIU_BUSY__SHIFT                0x0000001b
#define	SE_VAP_CNTL_STATUS__VC_BUSY__SHIFT                 0x0000001c
#define	SE_VAP_CNTL_STATUS__VF_BUSY__SHIFT                 0x0000001d
#define	SE_VAP_CNTL_STATUS__REGPIPE_BUSY__SHIFT            0x0000001e
#define	SE_VAP_CNTL_STATUS__VAP_BUSY__SHIFT                0x0000001f

// SE_PROG_STREAM_CNTL_0
#define	SE_PROG_STREAM_CNTL_0__DATA_TYPE_0__SHIFT          0x00000000
#define	SE_PROG_STREAM_CNTL_0__SKIP_DWORDS_0__SHIFT        0x00000004
#define	SE_PROG_STREAM_CNTL_0__DST_VEC_LOC_0__SHIFT        0x00000008
#define	SE_PROG_STREAM_CNTL_0__LAST_VEC_0__SHIFT           0x0000000d
#define	SE_PROG_STREAM_CNTL_0__SIGNED_0__SHIFT             0x0000000e
#define	SE_PROG_STREAM_CNTL_0__NORMALIZE_0__SHIFT          0x0000000f
#define	SE_PROG_STREAM_CNTL_0__DATA_TYPE_1__SHIFT          0x00000010
#define	SE_PROG_STREAM_CNTL_0__SKIP_DWORDS_1__SHIFT        0x00000014
#define	SE_PROG_STREAM_CNTL_0__DST_VEC_LOC_1__SHIFT        0x00000018
#define	SE_PROG_STREAM_CNTL_0__LAST_VEC_1__SHIFT           0x0000001d
#define	SE_PROG_STREAM_CNTL_0__SIGNED_1__SHIFT             0x0000001e
#define	SE_PROG_STREAM_CNTL_0__NORMALIZE_1__SHIFT          0x0000001f

// SE_PROG_STREAM_CNTL_1
#define	SE_PROG_STREAM_CNTL_1__DATA_TYPE_2__SHIFT          0x00000000
#define	SE_PROG_STREAM_CNTL_1__SKIP_DWORDS_2__SHIFT        0x00000004
#define	SE_PROG_STREAM_CNTL_1__DST_VEC_LOC_2__SHIFT        0x00000008
#define	SE_PROG_STREAM_CNTL_1__LAST_VEC_2__SHIFT           0x0000000d
#define	SE_PROG_STREAM_CNTL_1__SIGNED_2__SHIFT             0x0000000e
#define	SE_PROG_STREAM_CNTL_1__NORMALIZE_2__SHIFT          0x0000000f
#define	SE_PROG_STREAM_CNTL_1__DATA_TYPE_3__SHIFT          0x00000010
#define	SE_PROG_STREAM_CNTL_1__SKIP_DWORDS_3__SHIFT        0x00000014
#define	SE_PROG_STREAM_CNTL_1__DST_VEC_LOC_3__SHIFT        0x00000018
#define	SE_PROG_STREAM_CNTL_1__LAST_VEC_3__SHIFT           0x0000001d
#define	SE_PROG_STREAM_CNTL_1__SIGNED_3__SHIFT             0x0000001e
#define	SE_PROG_STREAM_CNTL_1__NORMALIZE_3__SHIFT          0x0000001f

// SE_PROG_STREAM_CNTL_2
#define	SE_PROG_STREAM_CNTL_2__DATA_TYPE_4__SHIFT          0x00000000
#define	SE_PROG_STREAM_CNTL_2__SKIP_DWORDS_4__SHIFT        0x00000004
#define	SE_PROG_STREAM_CNTL_2__DST_VEC_LOC_4__SHIFT        0x00000008
#define	SE_PROG_STREAM_CNTL_2__LAST_VEC_4__SHIFT           0x0000000d
#define	SE_PROG_STREAM_CNTL_2__SIGNED_4__SHIFT             0x0000000e
#define	SE_PROG_STREAM_CNTL_2__NORMALIZE_4__SHIFT          0x0000000f
#define	SE_PROG_STREAM_CNTL_2__DATA_TYPE_5__SHIFT          0x00000010
#define	SE_PROG_STREAM_CNTL_2__SKIP_DWORDS_5__SHIFT        0x00000014
#define	SE_PROG_STREAM_CNTL_2__DST_VEC_LOC_5__SHIFT        0x00000018
#define	SE_PROG_STREAM_CNTL_2__LAST_VEC_5__SHIFT           0x0000001d
#define	SE_PROG_STREAM_CNTL_2__SIGNED_5__SHIFT             0x0000001e
#define	SE_PROG_STREAM_CNTL_2__NORMALIZE_5__SHIFT          0x0000001f

// SE_PROG_STREAM_CNTL_3
#define	SE_PROG_STREAM_CNTL_3__DATA_TYPE_6__SHIFT          0x00000000
#define	SE_PROG_STREAM_CNTL_3__SKIP_DWORDS_6__SHIFT        0x00000004
#define	SE_PROG_STREAM_CNTL_3__DST_VEC_LOC_6__SHIFT        0x00000008
#define	SE_PROG_STREAM_CNTL_3__LAST_VEC_6__SHIFT           0x0000000d
#define	SE_PROG_STREAM_CNTL_3__SIGNED_6__SHIFT             0x0000000e
#define	SE_PROG_STREAM_CNTL_3__NORMALIZE_6__SHIFT          0x0000000f
#define	SE_PROG_STREAM_CNTL_3__DATA_TYPE_7__SHIFT          0x00000010
#define	SE_PROG_STREAM_CNTL_3__SKIP_DWORDS_7__SHIFT        0x00000014
#define	SE_PROG_STREAM_CNTL_3__DST_VEC_LOC_7__SHIFT        0x00000018
#define	SE_PROG_STREAM_CNTL_3__LAST_VEC_7__SHIFT           0x0000001d
#define	SE_PROG_STREAM_CNTL_3__SIGNED_7__SHIFT             0x0000001e
#define	SE_PROG_STREAM_CNTL_3__NORMALIZE_7__SHIFT          0x0000001f

// SE_PROG_STREAM_CNTL_4
#define	SE_PROG_STREAM_CNTL_4__DATA_TYPE_8__SHIFT          0x00000000
#define	SE_PROG_STREAM_CNTL_4__SKIP_DWORDS_8__SHIFT        0x00000004
#define	SE_PROG_STREAM_CNTL_4__DST_VEC_LOC_8__SHIFT        0x00000008
#define	SE_PROG_STREAM_CNTL_4__LAST_VEC_8__SHIFT           0x0000000d
#define	SE_PROG_STREAM_CNTL_4__SIGNED_8__SHIFT             0x0000000e
#define	SE_PROG_STREAM_CNTL_4__NORMALIZE_8__SHIFT          0x0000000f
#define	SE_PROG_STREAM_CNTL_4__DATA_TYPE_9__SHIFT          0x00000010
#define	SE_PROG_STREAM_CNTL_4__SKIP_DWORDS_9__SHIFT        0x00000014
#define	SE_PROG_STREAM_CNTL_4__DST_VEC_LOC_9__SHIFT        0x00000018
#define	SE_PROG_STREAM_CNTL_4__LAST_VEC_9__SHIFT           0x0000001d
#define	SE_PROG_STREAM_CNTL_4__SIGNED_9__SHIFT             0x0000001e
#define	SE_PROG_STREAM_CNTL_4__NORMALIZE_9__SHIFT          0x0000001f

// SE_PROG_STREAM_CNTL_5
#define	SE_PROG_STREAM_CNTL_5__DATA_TYPE_10__SHIFT         0x00000000
#define	SE_PROG_STREAM_CNTL_5__SKIP_DWORDS_10__SHIFT       0x00000004
#define	SE_PROG_STREAM_CNTL_5__DST_VEC_LOC_10__SHIFT       0x00000008
#define	SE_PROG_STREAM_CNTL_5__LAST_VEC_10__SHIFT          0x0000000d
#define	SE_PROG_STREAM_CNTL_5__SIGNED_10__SHIFT            0x0000000e
#define	SE_PROG_STREAM_CNTL_5__NORMALIZE_10__SHIFT         0x0000000f
#define	SE_PROG_STREAM_CNTL_5__DATA_TYPE_11__SHIFT         0x00000010
#define	SE_PROG_STREAM_CNTL_5__SKIP_DWORDS_11__SHIFT       0x00000014
#define	SE_PROG_STREAM_CNTL_5__DST_VEC_LOC_11__SHIFT       0x00000018
#define	SE_PROG_STREAM_CNTL_5__LAST_VEC_11__SHIFT          0x0000001d
#define	SE_PROG_STREAM_CNTL_5__SIGNED_11__SHIFT            0x0000001e
#define	SE_PROG_STREAM_CNTL_5__NORMALIZE_11__SHIFT         0x0000001f

// SE_PROG_STREAM_CNTL_6
#define	SE_PROG_STREAM_CNTL_6__DATA_TYPE_12__SHIFT         0x00000000
#define	SE_PROG_STREAM_CNTL_6__SKIP_DWORDS_12__SHIFT       0x00000004
#define	SE_PROG_STREAM_CNTL_6__DST_VEC_LOC_12__SHIFT       0x00000008
#define	SE_PROG_STREAM_CNTL_6__LAST_VEC_12__SHIFT          0x0000000d
#define	SE_PROG_STREAM_CNTL_6__SIGNED_12__SHIFT            0x0000000e
#define	SE_PROG_STREAM_CNTL_6__NORMALIZE_12__SHIFT         0x0000000f
#define	SE_PROG_STREAM_CNTL_6__DATA_TYPE_13__SHIFT         0x00000010
#define	SE_PROG_STREAM_CNTL_6__SKIP_DWORDS_13__SHIFT       0x00000014
#define	SE_PROG_STREAM_CNTL_6__DST_VEC_LOC_13__SHIFT       0x00000018
#define	SE_PROG_STREAM_CNTL_6__LAST_VEC_13__SHIFT          0x0000001d
#define	SE_PROG_STREAM_CNTL_6__SIGNED_13__SHIFT            0x0000001e
#define	SE_PROG_STREAM_CNTL_6__NORMALIZE_13__SHIFT         0x0000001f

// SE_PROG_STREAM_CNTL_7
#define	SE_PROG_STREAM_CNTL_7__DATA_TYPE_14__SHIFT         0x00000000
#define	SE_PROG_STREAM_CNTL_7__SKIP_DWORDS_14__SHIFT       0x00000004
#define	SE_PROG_STREAM_CNTL_7__DST_VEC_LOC_14__SHIFT       0x00000008
#define	SE_PROG_STREAM_CNTL_7__LAST_VEC_14__SHIFT          0x0000000d
#define	SE_PROG_STREAM_CNTL_7__SIGNED_14__SHIFT            0x0000000e
#define	SE_PROG_STREAM_CNTL_7__NORMALIZE_14__SHIFT         0x0000000f
#define	SE_PROG_STREAM_CNTL_7__DATA_TYPE_15__SHIFT         0x00000010
#define	SE_PROG_STREAM_CNTL_7__SKIP_DWORDS_15__SHIFT       0x00000014
#define	SE_PROG_STREAM_CNTL_7__DST_VEC_LOC_15__SHIFT       0x00000018
#define	SE_PROG_STREAM_CNTL_7__LAST_VEC_15__SHIFT          0x0000001d
#define	SE_PROG_STREAM_CNTL_7__SIGNED_15__SHIFT            0x0000001e
#define	SE_PROG_STREAM_CNTL_7__NORMALIZE_15__SHIFT         0x0000001f

// SE_VTX_STATE_CNTL
#define	SE_VTX_STATE_CNTL__COLOR_0_ASSEMBLY_CNTL__SHIFT    0x00000000
#define	SE_VTX_STATE_CNTL__COLOR_1_ASSEMBLY_CNTL__SHIFT    0x00000002
#define	SE_VTX_STATE_CNTL__COLOR_2_ASSEMBLY_CNTL__SHIFT    0x00000004
#define	SE_VTX_STATE_CNTL__COLOR_3_ASSEMBLY_CNTL__SHIFT    0x00000006
#define	SE_VTX_STATE_CNTL__COLOR_4_ASSEMBLY_CNTL__SHIFT    0x00000008
#define	SE_VTX_STATE_CNTL__COLOR_5_ASSEMBLY_CNTL__SHIFT    0x0000000a
#define	SE_VTX_STATE_CNTL__COLOR_6_ASSEMBLY_CNTL__SHIFT    0x0000000c
#define	SE_VTX_STATE_CNTL__COLOR_7_ASSEMBLY_CNTL__SHIFT    0x0000000e
#define	SE_VTX_STATE_CNTL__UPDATE_USER_COLOR_0_ENA__SHIFT  0x00000010
#define	SE_VTX_STATE_CNTL__UPDATE_USER_COLOR_1_ENA__SHIFT  0x00000011
#define	SE_VTX_STATE_CNTL__USE_ADDR_IND_TBL__SHIFT         0x00000012

// SE_VTX_STATE_IND_REG_0
#define	SE_VTX_STATE_IND_REG_0__ADDR_0__SHIFT              0x00000000
#define	SE_VTX_STATE_IND_REG_0__ADDR_1__SHIFT              0x00000008
#define	SE_VTX_STATE_IND_REG_0__ADDR_2__SHIFT              0x00000010
#define	SE_VTX_STATE_IND_REG_0__ADDR_3__SHIFT              0x00000018

// SE_VTX_STATE_IND_REG_1
#define	SE_VTX_STATE_IND_REG_1__ADDR_4__SHIFT              0x00000000
#define	SE_VTX_STATE_IND_REG_1__ADDR_5__SHIFT              0x00000008
#define	SE_VTX_STATE_IND_REG_1__ADDR_6__SHIFT              0x00000010
#define	SE_VTX_STATE_IND_REG_1__ADDR_7__SHIFT              0x00000018

// SE_VTX_STATE_IND_REG_2
#define	SE_VTX_STATE_IND_REG_2__ADDR_8__SHIFT              0x00000000
#define	SE_VTX_STATE_IND_REG_2__ADDR_9__SHIFT              0x00000008
#define	SE_VTX_STATE_IND_REG_2__ADDR_10__SHIFT             0x00000010
#define	SE_VTX_STATE_IND_REG_2__ADDR_11__SHIFT             0x00000018

// SE_VTX_STATE_IND_REG_3
#define	SE_VTX_STATE_IND_REG_3__ADDR_12__SHIFT             0x00000000
#define	SE_VTX_STATE_IND_REG_3__ADDR_13__SHIFT             0x00000008
#define	SE_VTX_STATE_IND_REG_3__ADDR_14__SHIFT             0x00000010
#define	SE_VTX_STATE_IND_REG_3__ADDR_15__SHIFT             0x00000018

// SE_VTX_STATE_IND_REG_4
#define	SE_VTX_STATE_IND_REG_4__ADDR_16__SHIFT             0x00000000
#define	SE_VTX_STATE_IND_REG_4__ADDR_17__SHIFT             0x00000008
#define	SE_VTX_STATE_IND_REG_4__ADDR_18__SHIFT             0x00000010
#define	SE_VTX_STATE_IND_REG_4__ADDR_19__SHIFT             0x00000018

// SE_VTX_STATE_IND_REG_5
#define	SE_VTX_STATE_IND_REG_5__ADDR_20__SHIFT             0x00000000
#define	SE_VTX_STATE_IND_REG_5__ADDR_21__SHIFT             0x00000008
#define	SE_VTX_STATE_IND_REG_5__ADDR_22__SHIFT             0x00000010
#define	SE_VTX_STATE_IND_REG_5__ADDR_23__SHIFT             0x00000018

// SE_VTX_STATE_IND_REG_6
#define	SE_VTX_STATE_IND_REG_6__ADDR_24__SHIFT             0x00000000
#define	SE_VTX_STATE_IND_REG_6__ADDR_25__SHIFT             0x00000008
#define	SE_VTX_STATE_IND_REG_6__ADDR_26__SHIFT             0x00000010
#define	SE_VTX_STATE_IND_REG_6__ADDR_27__SHIFT             0x00000018

// SE_VTX_STATE_IND_REG_7
#define	SE_VTX_STATE_IND_REG_7__ADDR_28__SHIFT             0x00000000
#define	SE_VTX_STATE_IND_REG_7__ADDR_29__SHIFT             0x00000008
#define	SE_VTX_STATE_IND_REG_7__ADDR_30__SHIFT             0x00000010
#define	SE_VTX_STATE_IND_REG_7__ADDR_31__SHIFT             0x00000018

// SE_VTX_STATE_IND_REG_8
#define	SE_VTX_STATE_IND_REG_8__ADDR_32__SHIFT             0x00000000
#define	SE_VTX_STATE_IND_REG_8__ADDR_33__SHIFT             0x00000008
#define	SE_VTX_STATE_IND_REG_8__ADDR_34__SHIFT             0x00000010
#define	SE_VTX_STATE_IND_REG_8__ADDR_35__SHIFT             0x00000018

// SE_VTX_STATE_IND_REG_9
#define	SE_VTX_STATE_IND_REG_9__ADDR_36__SHIFT             0x00000000
#define	SE_VTX_STATE_IND_REG_9__ADDR_37__SHIFT             0x00000008
#define	SE_VTX_STATE_IND_REG_9__ADDR_38__SHIFT             0x00000010
#define	SE_VTX_STATE_IND_REG_9__ADDR_39__SHIFT             0x00000018

// SE_VTX_STATE_IND_REG_10
#define	SE_VTX_STATE_IND_REG_10__ADDR_40__SHIFT            0x00000000
#define	SE_VTX_STATE_IND_REG_10__ADDR_41__SHIFT            0x00000008
#define	SE_VTX_STATE_IND_REG_10__ADDR_42__SHIFT            0x00000010
#define	SE_VTX_STATE_IND_REG_10__ADDR_43__SHIFT            0x00000018

// SE_VTX_STATE_IND_REG_11
#define	SE_VTX_STATE_IND_REG_11__ADDR_44__SHIFT            0x00000000
#define	SE_VTX_STATE_IND_REG_11__ADDR_45__SHIFT            0x00000008
#define	SE_VTX_STATE_IND_REG_11__ADDR_46__SHIFT            0x00000010
#define	SE_VTX_STATE_IND_REG_11__ADDR_47__SHIFT            0x00000018

// SE_VTX_STATE_IND_REG_12
#define	SE_VTX_STATE_IND_REG_12__ADDR_48__SHIFT            0x00000000
#define	SE_VTX_STATE_IND_REG_12__ADDR_49__SHIFT            0x00000008
#define	SE_VTX_STATE_IND_REG_12__ADDR_50__SHIFT            0x00000010
#define	SE_VTX_STATE_IND_REG_12__ADDR_51__SHIFT            0x00000018

// SE_VTX_STATE_IND_REG_13
#define	SE_VTX_STATE_IND_REG_13__ADDR_52__SHIFT            0x00000000
#define	SE_VTX_STATE_IND_REG_13__ADDR_53__SHIFT            0x00000008
#define	SE_VTX_STATE_IND_REG_13__ADDR_54__SHIFT            0x00000010
#define	SE_VTX_STATE_IND_REG_13__ADDR_55__SHIFT            0x00000018

// SE_VTX_STATE_IND_REG_14
#define	SE_VTX_STATE_IND_REG_14__ADDR_56__SHIFT            0x00000000
#define	SE_VTX_STATE_IND_REG_14__ADDR_57__SHIFT            0x00000008
#define	SE_VTX_STATE_IND_REG_14__ADDR_58__SHIFT            0x00000010
#define	SE_VTX_STATE_IND_REG_14__ADDR_59__SHIFT            0x00000018

// SE_VTX_STATE_IND_REG_15
#define	SE_VTX_STATE_IND_REG_15__ADDR_60__SHIFT            0x00000000
#define	SE_VTX_STATE_IND_REG_15__ADDR_61__SHIFT            0x00000008
#define	SE_VTX_STATE_IND_REG_15__ADDR_62__SHIFT            0x00000010
#define	SE_VTX_STATE_IND_REG_15__ADDR_63__SHIFT            0x00000018

// SE_TCL_VECTOR_INDX_REG
#define	SE_TCL_VECTOR_INDX_REG__OCTWORD_OFFSET_R2__SHIFT   0x00000000
#define	SE_TCL_VECTOR_INDX_REG__OCTWORD_STRIDE__SHIFT      0x00000010
#define	SE_TCL_VECTOR_INDX_REG__DWORD_COUNT__SHIFT         0x0000001c

// SE_TCL_VECTOR_DATA_REG
#define	SE_TCL_VECTOR_DATA_REG__DATA_REGISTER__SHIFT       0x00000000

// SE_TCL_SCALAR_INDX_REG
#define	SE_TCL_SCALAR_INDX_REG__DWORD_OFFSET_R2__SHIFT     0x00000000
#define	SE_TCL_SCALAR_INDX_REG__DWORD_STRIDE__SHIFT        0x00000010

// SE_TCL_SCALAR_DATA_REG
#define	SE_TCL_SCALAR_DATA_REG__DATA_REGISTER__SHIFT       0x00000000

// SE_TCL_MATRIX_SEL_0
#define	SE_TCL_MATRIX_SEL_0__MODELVIEW_MTX_0_SEL__SHIFT    0x00000000
#define	SE_TCL_MATRIX_SEL_0__MODELVIEW_MTX_1_SEL__SHIFT    0x00000008
#define	SE_TCL_MATRIX_SEL_0__MODELVIEW_MTX_2_SEL__SHIFT    0x00000010
#define	SE_TCL_MATRIX_SEL_0__MODELVIEW_MTX_3_SEL__SHIFT    0x00000018

// SE_TCL_MATRIX_SEL_1
#define	SE_TCL_MATRIX_SEL_1__IT_MODELVIEW_MTX_0_SEL__SHIFT 0x00000000
#define	SE_TCL_MATRIX_SEL_1__IT_MODELVIEW_MTX_1_SEL__SHIFT 0x00000008
#define	SE_TCL_MATRIX_SEL_1__IT_MODELVIEW_MTX_2_SEL__SHIFT 0x00000010
#define	SE_TCL_MATRIX_SEL_1__IT_MODELVIEW_MTX_3_SEL__SHIFT 0x00000018

// SE_TCL_MATRIX_SEL_2
#define	SE_TCL_MATRIX_SEL_2__MODEL2CLIP_MTX_0_SEL__SHIFT   0x00000000
#define	SE_TCL_MATRIX_SEL_2__MODEL2CLIP_MTX_1_SEL__SHIFT   0x00000008
#define	SE_TCL_MATRIX_SEL_2__MODEL2CLIP_MTX_2_SEL__SHIFT   0x00000010
#define	SE_TCL_MATRIX_SEL_2__MODEL2CLIP_MTX_3_SEL__SHIFT   0x00000018

// SE_TCL_MATRIX_SEL_3
#define	SE_TCL_MATRIX_SEL_3__TEX_XFORM_MTX_0_SEL__SHIFT    0x00000000
#define	SE_TCL_MATRIX_SEL_3__TEX_XFORM_MTX_1_SEL__SHIFT    0x00000008
#define	SE_TCL_MATRIX_SEL_3__TEX_XFORM_MTX_2_SEL__SHIFT    0x00000010
#define	SE_TCL_MATRIX_SEL_3__TEX_XFORM_MTX_3_SEL__SHIFT    0x00000018

// SE_TCL_MATRIX_SEL_4
#define	SE_TCL_MATRIX_SEL_4__TEX_XFORM_MTX_4_SEL__SHIFT    0x00000000
#define	SE_TCL_MATRIX_SEL_4__TEX_XFORM_MTX_5_SEL__SHIFT    0x00000008

// SE_TCL_PER_VTX_MTX_CNTL
#define	SE_TCL_PER_VTX_MTX_CNTL__MV_MTX_0_INDX__SHIFT      0x00000000
#define	SE_TCL_PER_VTX_MTX_CNTL__ITMV_MTX_0_INDX__SHIFT    0x00000008
#define	SE_TCL_PER_VTX_MTX_CNTL__M2C_MTX_0_INDX__SHIFT     0x00000010

// SE_TCL_OUTPUT_VTX_COMP_SEL
#define	SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_XYZW_SEL__SHIFT    0x00000000
#define	SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_COLOR_0_SEL__SHIFT 0x00000008
#define	SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_COLOR_1_SEL__SHIFT 0x00000009
#define	SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_0_SEL__SHIFT   0x00000010
#define	SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_1_SEL__SHIFT   0x00000011
#define	SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_2_SEL__SHIFT   0x00000012
#define	SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_3_SEL__SHIFT   0x00000013
#define	SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_4_SEL__SHIFT   0x00000014
#define	SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_5_SEL__SHIFT   0x00000015
#define	SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_DISCRETE_FOG_SEL__SHIFT 0x00000018
#define	SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_PT_SIZE_SEL__SHIFT 0x00000019
#define	SE_TCL_OUTPUT_VTX_COMP_SEL__FORCE_IN_ORDER_PROC__SHIFT 0x0000001f

// SE_TCL_INPUT_VTX_VECTOR_ADDR_0
#define	SE_TCL_INPUT_VTX_VECTOR_ADDR_0__VERTEX_POSITION_ADDR__SHIFT 0x00000000

// SE_TCL_INPUT_VTX_VECTOR_ADDR_1
#define	SE_TCL_INPUT_VTX_VECTOR_ADDR_1__VTX_COLOR_0_ADDR__SHIFT 0x00000000
#define	SE_TCL_INPUT_VTX_VECTOR_ADDR_1__VTX_COLOR_1_ADDR__SHIFT 0x00000008

// SE_TCL_INPUT_VTX_VECTOR_ADDR_2
#define	SE_TCL_INPUT_VTX_VECTOR_ADDR_2__VTX_TEX_0_ADDR__SHIFT 0x00000000
#define	SE_TCL_INPUT_VTX_VECTOR_ADDR_2__VTX_TEX_1_ADDR__SHIFT 0x00000008
#define	SE_TCL_INPUT_VTX_VECTOR_ADDR_2__VTX_TEX_2_ADDR__SHIFT 0x00000010
#define	SE_TCL_INPUT_VTX_VECTOR_ADDR_2__VTX_TEX_3_ADDR__SHIFT 0x00000018

// SE_TCL_INPUT_VTX_VECTOR_ADDR_3
#define	SE_TCL_INPUT_VTX_VECTOR_ADDR_3__VTX_TEX_4_ADDR__SHIFT 0x00000000
#define	SE_TCL_INPUT_VTX_VECTOR_ADDR_3__VTX_TEX_5_ADDR__SHIFT 0x00000008

// SE_TCL_LIGHT_MODEL_CNTL_0
#define	SE_TCL_LIGHT_MODEL_CNTL_0__LIGHTING_ENA__SHIFT     0x00000000
#define	SE_TCL_LIGHT_MODEL_CNTL_0__LIGHTING_IN_MODEL__SHIFT 0x00000001
#define	SE_TCL_LIGHT_MODEL_CNTL_0__LOCAL_VIEWER__SHIFT     0x00000002
#define	SE_TCL_LIGHT_MODEL_CNTL_0__NORMALIZE_NORMAL__SHIFT 0x00000003
#define	SE_TCL_LIGHT_MODEL_CNTL_0__RESCALE_NORMAL__SHIFT   0x00000004
#define	SE_TCL_LIGHT_MODEL_CNTL_0__SPECULAR_ENA__SHIFT     0x00000005
#define	SE_TCL_LIGHT_MODEL_CNTL_0__DIFFUSE_SPECULAR_COMBINE__SHIFT 0x00000006
#define	SE_TCL_LIGHT_MODEL_CNTL_0__ALPHA_LIGHTING__SHIFT   0x00000007
#define	SE_TCL_LIGHT_MODEL_CNTL_0__LOC_LIGHT_W_SCALE_SUB__SHIFT 0x00000008
#define	SE_TCL_LIGHT_MODEL_CNTL_0__NO_NORMAL_DO_AMB_ONLY__SHIFT 0x00000009
#define	SE_TCL_LIGHT_MODEL_CNTL_0__TWO_SIDED_LIGHTING_ENA__SHIFT 0x0000000a
#define	SE_TCL_LIGHT_MODEL_CNTL_0__FRONT_SHININESS_SRC__SHIFT 0x0000000b
#define	SE_TCL_LIGHT_MODEL_CNTL_0__BACK_SHININESS_SRC__SHIFT 0x0000000d
#define	SE_TCL_LIGHT_MODEL_CNTL_0__WAIT_ON_CLIP_DIS__SHIFT 0x0000000f
#define	SE_TCL_LIGHT_MODEL_CNTL_0__CLIP_DBL_BUF_ENA__SHIFT 0x00000010

// SE_TCL_LIGHT_MODEL_CNTL_1
#define	SE_TCL_LIGHT_MODEL_CNTL_1__FRONT_EMISSIVE_SRC__SHIFT 0x00000000
#define	SE_TCL_LIGHT_MODEL_CNTL_1__FRONT_AMBIENT_SRC__SHIFT 0x00000004
#define	SE_TCL_LIGHT_MODEL_CNTL_1__FRONT_DIFFUSE_SRC__SHIFT 0x00000008
#define	SE_TCL_LIGHT_MODEL_CNTL_1__FRONT_SPECULAR_SRC__SHIFT 0x0000000c
#define	SE_TCL_LIGHT_MODEL_CNTL_1__BACK_EMISSIVE_SRC__SHIFT 0x00000010
#define	SE_TCL_LIGHT_MODEL_CNTL_1__BACK_AMBIENT_SRC__SHIFT 0x00000014
#define	SE_TCL_LIGHT_MODEL_CNTL_1__BACK_DIFFUSE_SRC__SHIFT 0x00000018
#define	SE_TCL_LIGHT_MODEL_CNTL_1__BACK_SPECULAR_SRC__SHIFT 0x0000001c

// SE_TCL_PER_LIGHT_CNTL_0
#define	SE_TCL_PER_LIGHT_CNTL_0__LIGHT_ENA_0__SHIFT        0x00000000
#define	SE_TCL_PER_LIGHT_CNTL_0__AMBIENT_ENA_0__SHIFT      0x00000001
#define	SE_TCL_PER_LIGHT_CNTL_0__SPECULAR_ENA_0__SHIFT     0x00000002
#define	SE_TCL_PER_LIGHT_CNTL_0__LOCAL_LIGHT_0__SHIFT      0x00000003
#define	SE_TCL_PER_LIGHT_CNTL_0__SPOT_ENA_0__SHIFT         0x00000004
#define	SE_TCL_PER_LIGHT_CNTL_0__SPOT_DUAL_CONE_0__SHIFT   0x00000005
#define	SE_TCL_PER_LIGHT_CNTL_0__RNG_ATT_ENA_0__SHIFT      0x00000006
#define	SE_TCL_PER_LIGHT_CNTL_0__RNG_ATT_CONSTANT_ENA_0__SHIFT 0x00000007
#define	SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_1BIT_NUM0__SHIFT 0x00000008
#define	SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_1BIT_NUM1__SHIFT 0x00000009
#define	SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_1BIT_NUM2__SHIFT 0x0000000a
#define	SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_1BIT_NUM3__SHIFT 0x0000000b
#define	SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_2BIT_NUM0__SHIFT 0x0000000c
#define	SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_2BIT_NUM1__SHIFT 0x0000000e
#define	SE_TCL_PER_LIGHT_CNTL_0__LIGHT_ENA_1__SHIFT        0x00000010
#define	SE_TCL_PER_LIGHT_CNTL_0__AMBIENT_ENA_1__SHIFT      0x00000011
#define	SE_TCL_PER_LIGHT_CNTL_0__SPECULAR_ENA_1__SHIFT     0x00000012
#define	SE_TCL_PER_LIGHT_CNTL_0__LOCAL_LIGHT_1__SHIFT      0x00000013
#define	SE_TCL_PER_LIGHT_CNTL_0__SPOT_ENA_1__SHIFT         0x00000014
#define	SE_TCL_PER_LIGHT_CNTL_0__SPOT_DUAL_CONE_1__SHIFT   0x00000015
#define	SE_TCL_PER_LIGHT_CNTL_0__RNG_ATT_ENA_1__SHIFT      0x00000016
#define	SE_TCL_PER_LIGHT_CNTL_0__RNG_ATT_CONSTANT_ENA_1__SHIFT 0x00000017
#define	SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_1BIT_NUM0__SHIFT 0x00000018
#define	SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_1BIT_NUM1__SHIFT 0x00000019
#define	SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_1BIT_NUM2__SHIFT 0x0000001a
#define	SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_1BIT_NUM3__SHIFT 0x0000001b
#define	SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_2BIT_NUM0__SHIFT 0x0000001c
#define	SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_2BIT_NUM1__SHIFT 0x0000001e

// SE_TCL_PER_LIGHT_CNTL_1
#define	SE_TCL_PER_LIGHT_CNTL_1__LIGHT_ENA_2__SHIFT        0x00000000
#define	SE_TCL_PER_LIGHT_CNTL_1__AMBIENT_ENA_2__SHIFT      0x00000001
#define	SE_TCL_PER_LIGHT_CNTL_1__SPECULAR_ENA_2__SHIFT     0x00000002
#define	SE_TCL_PER_LIGHT_CNTL_1__LOCAL_LIGHT_2__SHIFT      0x00000003
#define	SE_TCL_PER_LIGHT_CNTL_1__SPOT_ENA_2__SHIFT         0x00000004
#define	SE_TCL_PER_LIGHT_CNTL_1__SPOT_DUAL_CONE_2__SHIFT   0x00000005
#define	SE_TCL_PER_LIGHT_CNTL_1__RNG_ATT_ENA_2__SHIFT      0x00000006
#define	SE_TCL_PER_LIGHT_CNTL_1__RNG_ATT_CONSTANT_ENA_2__SHIFT 0x00000007
#define	SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_1BIT_NUM0__SHIFT 0x00000008
#define	SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_1BIT_NUM1__SHIFT 0x00000009
#define	SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_1BIT_NUM2__SHIFT 0x0000000a
#define	SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_1BIT_NUM3__SHIFT 0x0000000b
#define	SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_2BIT_NUM0__SHIFT 0x0000000c
#define	SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_2BIT_NUM1__SHIFT 0x0000000e
#define	SE_TCL_PER_LIGHT_CNTL_1__LIGHT_ENA_3__SHIFT        0x00000010
#define	SE_TCL_PER_LIGHT_CNTL_1__AMBIENT_ENA_3__SHIFT      0x00000011
#define	SE_TCL_PER_LIGHT_CNTL_1__SPECULAR_ENA_3__SHIFT     0x00000012
#define	SE_TCL_PER_LIGHT_CNTL_1__LOCAL_LIGHT_3__SHIFT      0x00000013
#define	SE_TCL_PER_LIGHT_CNTL_1__SPOT_ENA_3__SHIFT         0x00000014
#define	SE_TCL_PER_LIGHT_CNTL_1__SPOT_DUAL_CONE_3__SHIFT   0x00000015
#define	SE_TCL_PER_LIGHT_CNTL_1__RNG_ATT_ENA_3__SHIFT      0x00000016
#define	SE_TCL_PER_LIGHT_CNTL_1__RNG_ATT_CONSTANT_ENA_3__SHIFT 0x00000017
#define	SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_1BIT_NUM0__SHIFT 0x00000018
#define	SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_1BIT_NUM1__SHIFT 0x00000019
#define	SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_1BIT_NUM2__SHIFT 0x0000001a
#define	SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_1BIT_NUM3__SHIFT 0x0000001b
#define	SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_2BIT_NUM0__SHIFT 0x0000001c
#define	SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_2BIT_NUM1__SHIFT 0x0000001e

// SE_TCL_PER_LIGHT_CNTL_2
#define	SE_TCL_PER_LIGHT_CNTL_2__LIGHT_ENA_4__SHIFT        0x00000000
#define	SE_TCL_PER_LIGHT_CNTL_2__AMBIENT_ENA_4__SHIFT      0x00000001
#define	SE_TCL_PER_LIGHT_CNTL_2__SPECULAR_ENA_4__SHIFT     0x00000002
#define	SE_TCL_PER_LIGHT_CNTL_2__LOCAL_LIGHT_4__SHIFT      0x00000003
#define	SE_TCL_PER_LIGHT_CNTL_2__SPOT_ENA_4__SHIFT         0x00000004
#define	SE_TCL_PER_LIGHT_CNTL_2__SPOT_DUAL_CONE_4__SHIFT   0x00000005
#define	SE_TCL_PER_LIGHT_CNTL_2__RNG_ATT_ENA_4__SHIFT      0x00000006
#define	SE_TCL_PER_LIGHT_CNTL_2__RNG_ATT_CONSTANT_ENA_4__SHIFT 0x00000007
#define	SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_1BIT_NUM0__SHIFT 0x00000008
#define	SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_1BIT_NUM1__SHIFT 0x00000009
#define	SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_1BIT_NUM2__SHIFT 0x0000000a
#define	SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_1BIT_NUM3__SHIFT 0x0000000b
#define	SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_2BIT_NUM0__SHIFT 0x0000000c
#define	SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_2BIT_NUM1__SHIFT 0x0000000e
#define	SE_TCL_PER_LIGHT_CNTL_2__LIGHT_ENA_5__SHIFT        0x00000010
#define	SE_TCL_PER_LIGHT_CNTL_2__AMBIENT_ENA_5__SHIFT      0x00000011
#define	SE_TCL_PER_LIGHT_CNTL_2__SPECULAR_ENA_5__SHIFT     0x00000012
#define	SE_TCL_PER_LIGHT_CNTL_2__LOCAL_LIGHT_5__SHIFT      0x00000013
#define	SE_TCL_PER_LIGHT_CNTL_2__SPOT_ENA_5__SHIFT         0x00000014
#define	SE_TCL_PER_LIGHT_CNTL_2__SPOT_DUAL_CONE_5__SHIFT   0x00000015
#define	SE_TCL_PER_LIGHT_CNTL_2__RNG_ATT_ENA_5__SHIFT      0x00000016
#define	SE_TCL_PER_LIGHT_CNTL_2__RNG_ATT_CONSTANT_ENA_5__SHIFT 0x00000017
#define	SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_1BIT_NUM0__SHIFT 0x00000018
#define	SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_1BIT_NUM1__SHIFT 0x00000019
#define	SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_1BIT_NUM2__SHIFT 0x0000001a
#define	SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_1BIT_NUM3__SHIFT 0x0000001b
#define	SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_2BIT_NUM0__SHIFT 0x0000001c
#define	SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_2BIT_NUM1__SHIFT 0x0000001e

// SE_TCL_PER_LIGHT_CNTL_3
#define	SE_TCL_PER_LIGHT_CNTL_3__LIGHT_ENA_6__SHIFT        0x00000000
#define	SE_TCL_PER_LIGHT_CNTL_3__AMBIENT_ENA_6__SHIFT      0x00000001
#define	SE_TCL_PER_LIGHT_CNTL_3__SPECULAR_ENA_6__SHIFT     0x00000002
#define	SE_TCL_PER_LIGHT_CNTL_3__LOCAL_LIGHT_6__SHIFT      0x00000003
#define	SE_TCL_PER_LIGHT_CNTL_3__SPOT_ENA_6__SHIFT         0x00000004
#define	SE_TCL_PER_LIGHT_CNTL_3__SPOT_DUAL_CONE_6__SHIFT   0x00000005
#define	SE_TCL_PER_LIGHT_CNTL_3__RNG_ATT_ENA_6__SHIFT      0x00000006
#define	SE_TCL_PER_LIGHT_CNTL_3__RNG_ATT_CONSTANT_ENA_6__SHIFT 0x00000007
#define	SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_1BIT_NUM0__SHIFT 0x00000008
#define	SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_1BIT_NUM1__SHIFT 0x00000009
#define	SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_1BIT_NUM2__SHIFT 0x0000000a
#define	SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_1BIT_NUM3__SHIFT 0x0000000b
#define	SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_2BIT_NUM0__SHIFT 0x0000000c
#define	SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_2BIT_NUM1__SHIFT 0x0000000e
#define	SE_TCL_PER_LIGHT_CNTL_3__LIGHT_ENA_7__SHIFT        0x00000010
#define	SE_TCL_PER_LIGHT_CNTL_3__AMBIENT_ENA_7__SHIFT      0x00000011
#define	SE_TCL_PER_LIGHT_CNTL_3__SPECULAR_ENA_7__SHIFT     0x00000012
#define	SE_TCL_PER_LIGHT_CNTL_3__LOCAL_LIGHT_7__SHIFT      0x00000013
#define	SE_TCL_PER_LIGHT_CNTL_3__SPOT_ENA_7__SHIFT         0x00000014
#define	SE_TCL_PER_LIGHT_CNTL_3__SPOT_DUAL_CONE_7__SHIFT   0x00000015
#define	SE_TCL_PER_LIGHT_CNTL_3__RNG_ATT_ENA_7__SHIFT      0x00000016
#define	SE_TCL_PER_LIGHT_CNTL_3__RNG_ATT_CONSTANT_ENA_7__SHIFT 0x00000017
#define	SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_1BIT_NUM0__SHIFT 0x00000018
#define	SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_1BIT_NUM1__SHIFT 0x00000019
#define	SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_1BIT_NUM2__SHIFT 0x0000001a
#define	SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_1BIT_NUM3__SHIFT 0x0000001b
#define	SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_2BIT_NUM0__SHIFT 0x0000001c
#define	SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_2BIT_NUM1__SHIFT 0x0000001e

// SE_TCL_DEBUG_0
#define	SE_TCL_DEBUG_0__DEBUG_RD_SEL_ENA__SHIFT            0x00000000
#define	SE_TCL_DEBUG_0__DEBUG_RD_SEL__SHIFT                0x00000001
#define	SE_TCL_DEBUG_0__DEBUG_IMM_RD__SHIFT                0x00000002
#define	SE_TCL_DEBUG_0__ST_UPD_FIFO_SZ__SHIFT              0x00000003
#define	SE_TCL_DEBUG_0__DIS_CLIP_ERR_DETECT__SHIFT         0x00000005

// SE_TCL_STATE_FLUSH_REG
#define	SE_TCL_STATE_FLUSH_REG__DATA_REGISTER__SHIFT       0x00000000

// SE_TCL_FPU_LATENCY_R2
#define	SE_TCL_FPU_LATENCY_R2__VE_ENG_LATENCY__SHIFT       0x00000000
#define	SE_TCL_FPU_LATENCY_R2__VE_MULT_LATENCY__SHIFT      0x00000005
#define	SE_TCL_FPU_LATENCY_R2__VE_ACCUM_LATENCY__SHIFT     0x0000000a
#define	SE_TCL_FPU_LATENCY_R2__SC_ENG_LATENCY__SHIFT       0x0000000f
#define	SE_TCL_FPU_LATENCY_R2__VE_OUT_LATENCY__SHIFT       0x00000014
#define	SE_TCL_FPU_LATENCY_R2__SC_MATH_LATENCY__SHIFT      0x00000019
#define	SE_TCL_FPU_LATENCY_R2__RSVD_LTNCY_2BIT__SHIFT      0x0000001e

// SE_TCL_TEX_PROC_CNTL_2
#define	SE_TCL_TEX_PROC_CNTL_2__TCG_COMP_MASK_0__SHIFT     0x00000000
#define	SE_TCL_TEX_PROC_CNTL_2__TCG_COMP_MASK_1__SHIFT     0x00000004
#define	SE_TCL_TEX_PROC_CNTL_2__TCG_COMP_MASK_2__SHIFT     0x00000008
#define	SE_TCL_TEX_PROC_CNTL_2__TCG_COMP_MASK_3__SHIFT     0x0000000c
#define	SE_TCL_TEX_PROC_CNTL_2__TCG_COMP_MASK_4__SHIFT     0x00000010
#define	SE_TCL_TEX_PROC_CNTL_2__TCG_COMP_MASK_5__SHIFT     0x00000014

// SE_TCL_TEX_PROC_CNTL_3
#define	SE_TCL_TEX_PROC_CNTL_3__TCG_INPUT_TEX_0__SHIFT     0x00000000
#define	SE_TCL_TEX_PROC_CNTL_3__TCG_INPUT_TEX_1__SHIFT     0x00000004
#define	SE_TCL_TEX_PROC_CNTL_3__TCG_INPUT_TEX_2__SHIFT     0x00000008
#define	SE_TCL_TEX_PROC_CNTL_3__TCG_INPUT_TEX_3__SHIFT     0x0000000c
#define	SE_TCL_TEX_PROC_CNTL_3__TCG_INPUT_TEX_4__SHIFT     0x00000010
#define	SE_TCL_TEX_PROC_CNTL_3__TCG_INPUT_TEX_5__SHIFT     0x00000014

// SE_TCL_TEX_PROC_CNTL_0
#define	SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_0__SHIFT   0x00000000
#define	SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_1__SHIFT   0x00000001
#define	SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_2__SHIFT   0x00000002
#define	SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_3__SHIFT   0x00000003
#define	SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_4__SHIFT   0x00000004
#define	SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_5__SHIFT   0x00000005
#define	SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_0__SHIFT     0x00000008
#define	SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_1__SHIFT     0x00000009
#define	SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_2__SHIFT     0x0000000a
#define	SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_3__SHIFT     0x0000000b
#define	SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_4__SHIFT     0x0000000c
#define	SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_5__SHIFT     0x0000000d
#define	SE_TCL_TEX_PROC_CNTL_0__TCG_FORCE_W_TO_ONE__SHIFT  0x00000010

// SE_TCL_TEX_PROC_CNTL_1
#define	SE_TCL_TEX_PROC_CNTL_1__TEX_CS_PROC_SRC_0__SHIFT   0x00000000
#define	SE_TCL_TEX_PROC_CNTL_1__TEX_CS_PROC_SRC_1__SHIFT   0x00000004
#define	SE_TCL_TEX_PROC_CNTL_1__TEX_CS_PROC_SRC_2__SHIFT   0x00000008
#define	SE_TCL_TEX_PROC_CNTL_1__TEX_CS_PROC_SRC_3__SHIFT   0x0000000c
#define	SE_TCL_TEX_PROC_CNTL_1__TEX_CS_PROC_SRC_4__SHIFT   0x00000010
#define	SE_TCL_TEX_PROC_CNTL_1__TEX_CS_PROC_SRC_5__SHIFT   0x00000014

// SE_TCL_TEX_CYL_WRAP_CNTL
#define	SE_TCL_TEX_CYL_WRAP_CNTL__TEX_CYL_WRAP_0__SHIFT    0x00000000
#define	SE_TCL_TEX_CYL_WRAP_CNTL__TEX_CYL_WRAP_1__SHIFT    0x00000004
#define	SE_TCL_TEX_CYL_WRAP_CNTL__TEX_CYL_WRAP_2__SHIFT    0x00000008
#define	SE_TCL_TEX_CYL_WRAP_CNTL__TEX_CYL_WRAP_3__SHIFT    0x0000000c
#define	SE_TCL_TEX_CYL_WRAP_CNTL__TEX_CYL_WRAP_4__SHIFT    0x00000010
#define	SE_TCL_TEX_CYL_WRAP_CNTL__TEX_CYL_WRAP_5__SHIFT    0x00000014

// SE_TCL_UCP_VTX_BLEND_CNTL
#define	SE_TCL_UCP_VTX_BLEND_CNTL__UCP_IN_CLIP_SPACE__SHIFT 0x00000000
#define	SE_TCL_UCP_VTX_BLEND_CNTL__UCP_IN_MODEL_SPACE__SHIFT 0x00000001
#define	SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_0__SHIFT        0x00000002
#define	SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_1__SHIFT        0x00000003
#define	SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_2__SHIFT        0x00000004
#define	SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_3__SHIFT        0x00000005
#define	SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_4__SHIFT        0x00000006
#define	SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_5__SHIFT        0x00000007
#define	SE_TCL_UCP_VTX_BLEND_CNTL__FOG_MODE__SHIFT         0x00000008
#define	SE_TCL_UCP_VTX_BLEND_CNTL__RNG_BASED_FOG__SHIFT    0x0000000a
#define	SE_TCL_UCP_VTX_BLEND_CNTL__CLIP_DISABLE__SHIFT     0x0000000b
#define	SE_TCL_UCP_VTX_BLEND_CNTL__BLEND_OP_CNT__SHIFT     0x0000000c
#define	SE_TCL_UCP_VTX_BLEND_CNTL__USE_ST_BLEND_OP_CNT__SHIFT 0x0000000f
#define	SE_TCL_UCP_VTX_BLEND_CNTL__POSITION_BLEND_OPERATION__SHIFT 0x00000010
#define	SE_TCL_UCP_VTX_BLEND_CNTL__NORMAL_BLEND_OPERATION__SHIFT 0x00000011
#define	SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_SRC_0__SHIFT  0x00000012
#define	SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_SRC_1__SHIFT  0x00000013
#define	SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_SRC_2__SHIFT  0x00000014
#define	SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_SRC_3__SHIFT  0x00000015
#define	SE_TCL_UCP_VTX_BLEND_CNTL__BLEND_WEIGHT_MINUS_ONE__SHIFT 0x00000016
#define	SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_USE_PROJ_MTX__SHIFT 0x00000017
#define	SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_2_OPTIMIZE__SHIFT 0x00000018
#define	SE_TCL_UCP_VTX_BLEND_CNTL__CULL_EQ_0_ENA__SHIFT    0x00000019
#define	SE_TCL_UCP_VTX_BLEND_CNTL__CULL_METHOD__SHIFT      0x0000001a
#define	SE_TCL_UCP_VTX_BLEND_CNTL__CULLING_FF_DIR__SHIFT   0x0000001c
#define	SE_TCL_UCP_VTX_BLEND_CNTL__CULL_FF_ENA__SHIFT      0x0000001d
#define	SE_TCL_UCP_VTX_BLEND_CNTL__CULL_BF_ENA__SHIFT      0x0000001e
#define	SE_TCL_UCP_VTX_BLEND_CNTL__UCP_CULL_ONLY_ENA__SHIFT 0x0000001f

// SE_TCL_POINT_SPRITE_CNTL
#define	SE_TCL_POINT_SPRITE_CNTL__PS_MULT__SHIFT           0x00000000
#define	SE_TCL_POINT_SPRITE_CNTL__PS_LIN_ATT_ZERO__SHIFT   0x00000003
#define	SE_TCL_POINT_SPRITE_CNTL__PS_USE_MODEL_EYE_VEC__SHIFT 0x00000004
#define	SE_TCL_POINT_SPRITE_CNTL__PS_ATT_ALPHA__SHIFT      0x00000005
#define	SE_TCL_POINT_SPRITE_CNTL__PS_UCP_MODE__SHIFT       0x00000006
#define	SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_0__SHIFT      0x00000008
#define	SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_1__SHIFT      0x00000009
#define	SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_2__SHIFT      0x0000000a
#define	SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_3__SHIFT      0x0000000b
#define	SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_4__SHIFT      0x0000000c
#define	SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_5__SHIFT      0x0000000d
#define	SE_TCL_POINT_SPRITE_CNTL__PS_SE_SEL_STATE_SIZE__SHIFT 0x00000010
#define	SE_TCL_POINT_SPRITE_CNTL__PS_DIS_VV_EARLY_EXIT__SHIFT 0x00000011

// SE_PVS_CNTL
#define	SE_PVS_CNTL__PVS_FIRST_INST__SHIFT                 0x00000000
#define	SE_PVS_CNTL__PVS_XYZW_VALID_INST__SHIFT            0x0000000a
#define	SE_PVS_CNTL__PVS_LAST_INST__SHIFT                  0x00000014

// SE_PVS_CONST_CNTL
#define	SE_PVS_CONST_CNTL__PVS_CONST_BASE_OFFSET__SHIFT    0x00000000
#define	SE_PVS_CONST_CNTL__PVS_MAX_CONST_ADDR__SHIFT       0x00000010

// SE_VTX_ST_POS_0_X_4
#define	SE_VTX_ST_POS_0_X_4__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_POS_0_Y_4
#define	SE_VTX_ST_POS_0_Y_4__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_POS_0_Z_4
#define	SE_VTX_ST_POS_0_Z_4__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_POS_0_W_4
#define	SE_VTX_ST_POS_0_W_4__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_NORM_0_X
#define	SE_VTX_ST_NORM_0_X__DATA_REGISTER__SHIFT           0x00000000

// SE_VTX_ST_NORM_0_Y
#define	SE_VTX_ST_NORM_0_Y__DATA_REGISTER__SHIFT           0x00000000

// SE_VTX_ST_NORM_0_Z
#define	SE_VTX_ST_NORM_0_Z__DATA_REGISTER__SHIFT           0x00000000

// SE_VTX_ST_PVMS
#define	SE_VTX_ST_PVMS__DATA_REGISTER__SHIFT               0x00000000

// SE_VTX_ST_CLR_0_R
#define	SE_VTX_ST_CLR_0_R__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_0_G
#define	SE_VTX_ST_CLR_0_G__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_0_B
#define	SE_VTX_ST_CLR_0_B__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_0_A
#define	SE_VTX_ST_CLR_0_A__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_1_R
#define	SE_VTX_ST_CLR_1_R__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_1_G
#define	SE_VTX_ST_CLR_1_G__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_1_B
#define	SE_VTX_ST_CLR_1_B__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_1_A
#define	SE_VTX_ST_CLR_1_A__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_2_R
#define	SE_VTX_ST_CLR_2_R__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_2_G
#define	SE_VTX_ST_CLR_2_G__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_2_B
#define	SE_VTX_ST_CLR_2_B__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_2_A
#define	SE_VTX_ST_CLR_2_A__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_3_R
#define	SE_VTX_ST_CLR_3_R__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_3_G
#define	SE_VTX_ST_CLR_3_G__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_3_B
#define	SE_VTX_ST_CLR_3_B__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_3_A
#define	SE_VTX_ST_CLR_3_A__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_4_R
#define	SE_VTX_ST_CLR_4_R__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_4_G
#define	SE_VTX_ST_CLR_4_G__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_4_B
#define	SE_VTX_ST_CLR_4_B__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_4_A
#define	SE_VTX_ST_CLR_4_A__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_5_R
#define	SE_VTX_ST_CLR_5_R__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_5_G
#define	SE_VTX_ST_CLR_5_G__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_5_B
#define	SE_VTX_ST_CLR_5_B__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_5_A
#define	SE_VTX_ST_CLR_5_A__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_6_R
#define	SE_VTX_ST_CLR_6_R__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_6_G
#define	SE_VTX_ST_CLR_6_G__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_6_B
#define	SE_VTX_ST_CLR_6_B__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_6_A
#define	SE_VTX_ST_CLR_6_A__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_7_R
#define	SE_VTX_ST_CLR_7_R__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_7_G
#define	SE_VTX_ST_CLR_7_G__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_7_B
#define	SE_VTX_ST_CLR_7_B__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_CLR_7_A
#define	SE_VTX_ST_CLR_7_A__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_0_S
#define	SE_VTX_ST_TEX_0_S__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_0_T
#define	SE_VTX_ST_TEX_0_T__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_0_R
#define	SE_VTX_ST_TEX_0_R__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_0_Q
#define	SE_VTX_ST_TEX_0_Q__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_1_S
#define	SE_VTX_ST_TEX_1_S__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_1_T
#define	SE_VTX_ST_TEX_1_T__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_1_R
#define	SE_VTX_ST_TEX_1_R__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_1_Q
#define	SE_VTX_ST_TEX_1_Q__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_2_S
#define	SE_VTX_ST_TEX_2_S__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_2_T
#define	SE_VTX_ST_TEX_2_T__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_2_R
#define	SE_VTX_ST_TEX_2_R__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_2_Q
#define	SE_VTX_ST_TEX_2_Q__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_3_S
#define	SE_VTX_ST_TEX_3_S__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_3_T
#define	SE_VTX_ST_TEX_3_T__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_3_R
#define	SE_VTX_ST_TEX_3_R__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_3_Q
#define	SE_VTX_ST_TEX_3_Q__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_4_S
#define	SE_VTX_ST_TEX_4_S__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_4_T
#define	SE_VTX_ST_TEX_4_T__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_4_R
#define	SE_VTX_ST_TEX_4_R__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_4_Q
#define	SE_VTX_ST_TEX_4_Q__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_5_S
#define	SE_VTX_ST_TEX_5_S__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_5_T
#define	SE_VTX_ST_TEX_5_T__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_5_R
#define	SE_VTX_ST_TEX_5_R__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_TEX_5_Q
#define	SE_VTX_ST_TEX_5_Q__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_PNT_SPRT_SZ
#define	SE_VTX_ST_PNT_SPRT_SZ__DATA_REGISTER__SHIFT        0x00000000

// SE_VTX_ST_DISC_FOG
#define	SE_VTX_ST_DISC_FOG__DATA_REGISTER__SHIFT           0x00000000

// SE_VTX_ST_SHININESS_0
#define	SE_VTX_ST_SHININESS_0__DATA_REGISTER__SHIFT        0x00000000

// SE_VTX_ST_SHININESS_1
#define	SE_VTX_ST_SHININESS_1__DATA_REGISTER__SHIFT        0x00000000

// SE_VTX_ST_BLND_WT_0
#define	SE_VTX_ST_BLND_WT_0__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_BLND_WT_1
#define	SE_VTX_ST_BLND_WT_1__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_BLND_WT_2
#define	SE_VTX_ST_BLND_WT_2__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_BLND_WT_3
#define	SE_VTX_ST_BLND_WT_3__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_POS_1_X
#define	SE_VTX_ST_POS_1_X__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_POS_1_Y
#define	SE_VTX_ST_POS_1_Y__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_POS_1_Z
#define	SE_VTX_ST_POS_1_Z__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_POS_1_W
#define	SE_VTX_ST_POS_1_W__DATA_REGISTER__SHIFT            0x00000000

// SE_VTX_ST_NORM_1_X
#define	SE_VTX_ST_NORM_1_X__DATA_REGISTER__SHIFT           0x00000000

// SE_VTX_ST_NORM_1_Y
#define	SE_VTX_ST_NORM_1_Y__DATA_REGISTER__SHIFT           0x00000000

// SE_VTX_ST_NORM_1_Z
#define	SE_VTX_ST_NORM_1_Z__DATA_REGISTER__SHIFT           0x00000000

// SE_VTX_ST_SPARE_43C
#define	SE_VTX_ST_SPARE_43C__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_USR_CLR_0_R
#define	SE_VTX_ST_USR_CLR_0_R__DATA_REGISTER__SHIFT        0x00000000

// SE_VTX_ST_USR_CLR_0_G
#define	SE_VTX_ST_USR_CLR_0_G__DATA_REGISTER__SHIFT        0x00000000

// SE_VTX_ST_USR_CLR_0_B
#define	SE_VTX_ST_USR_CLR_0_B__DATA_REGISTER__SHIFT        0x00000000

// SE_VTX_ST_USR_CLR_0_A
#define	SE_VTX_ST_USR_CLR_0_A__DATA_REGISTER__SHIFT        0x00000000

// SE_VTX_ST_USR_CLR_1_R
#define	SE_VTX_ST_USR_CLR_1_R__DATA_REGISTER__SHIFT        0x00000000

// SE_VTX_ST_USR_CLR_1_G
#define	SE_VTX_ST_USR_CLR_1_G__DATA_REGISTER__SHIFT        0x00000000

// SE_VTX_ST_USR_CLR_1_B
#define	SE_VTX_ST_USR_CLR_1_B__DATA_REGISTER__SHIFT        0x00000000

// SE_VTX_ST_USR_CLR_1_A
#define	SE_VTX_ST_USR_CLR_1_A__DATA_REGISTER__SHIFT        0x00000000

// SE_VTX_ST_CLR_0_PKD
#define	SE_VTX_ST_CLR_0_PKD__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_CLR_1_PKD
#define	SE_VTX_ST_CLR_1_PKD__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_CLR_2_PKD
#define	SE_VTX_ST_CLR_2_PKD__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_CLR_3_PKD
#define	SE_VTX_ST_CLR_3_PKD__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_CLR_4_PKD
#define	SE_VTX_ST_CLR_4_PKD__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_CLR_5_PKD
#define	SE_VTX_ST_CLR_5_PKD__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_CLR_6_PKD
#define	SE_VTX_ST_CLR_6_PKD__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_CLR_7_PKD
#define	SE_VTX_ST_CLR_7_PKD__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_POS_0_X_2
#define	SE_VTX_ST_POS_0_X_2__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_POS_0_Y_2
#define	SE_VTX_ST_POS_0_Y_2__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_PAR_CLR_LD
#define	SE_VTX_ST_PAR_CLR_LD__DATA_REGISTER__SHIFT         0x00000000

// SE_VTX_ST_USR_CLR_PKD
#define	SE_VTX_ST_USR_CLR_PKD__DATA_REGISTER__SHIFT        0x00000000

// SE_VTX_ST_POS_0_X_3
#define	SE_VTX_ST_POS_0_X_3__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_POS_0_Y_3
#define	SE_VTX_ST_POS_0_Y_3__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_POS_0_Z_3
#define	SE_VTX_ST_POS_0_Z_3__DATA_REGISTER__SHIFT          0x00000000

// SE_VTX_ST_END_OF_PKT
#define	SE_VTX_ST_END_OF_PKT__DATA_REGISTER__SHIFT         0x00000000

// RE_SOLID_COLOR
#define	RE_SOLID_COLOR__SOLID_COLOR__SHIFT                 0x00000000

// RE_WIDTH_HEIGHT
#define	RE_WIDTH_HEIGHT__WIDTH__SHIFT                      0x00000000
#define	RE_WIDTH_HEIGHT__HEIGHT__SHIFT                     0x00000010

// RE_POINTSIZE
#define	RE_POINTSIZE__POINTSIZE__SHIFT                     0x00000000
#define	RE_POINTSIZE__MAXPOINTSIZE__SHIFT                  0x00000010

// SE_CNTL
#define	SE_CNTL__FFACE_CULL_DIR__SHIFT                     0x00000000
#define	SE_CNTL__BFACE_CULL_FCN__SHIFT                     0x00000001
#define	SE_CNTL__FFACE_CULL_FCN__SHIFT                     0x00000003
#define	SE_CNTL__FLAT_SHADE_VTX__SHIFT                     0x00000006
#define	SE_CNTL__DIFFUSE_SHADE_FCN__SHIFT                  0x00000008
#define	SE_CNTL__ALPHA_SHADE_FCN__SHIFT                    0x0000000a
#define	SE_CNTL__SPECULAR_SHADE_FCN__SHIFT                 0x0000000c
#define	SE_CNTL__FOG_SHADE_FCN__SHIFT                      0x0000000e
#define	SE_CNTL__ZBIAS_EN_POINT__SHIFT                     0x00000010
#define	SE_CNTL__ZBIAS_EN_LINE__SHIFT                      0x00000011
#define	SE_CNTL__ZBIAS_EN_TRI__SHIFT                       0x00000012
#define	SE_CNTL__WIDELINE_EN__SHIFT                        0x00000014
#define	SE_CNTL__DISCRETE_FOG_SHADE_FCN__SHIFT             0x00000018
#define	SE_CNTL__VTX_PIXCENTER__SHIFT                      0x0000001b
#define	SE_CNTL__ROUND_MODE__SHIFT                         0x0000001c
#define	SE_CNTL__ROUND_PRECISION__SHIFT                    0x0000001e

// RE_CNTL
#define	RE_CNTL__STIPPLE_ENABLE__SHIFT                     0x00000000
#define	RE_CNTL__SCISSOR_ENABLE__SHIFT                     0x00000001
#define	RE_CNTL__PATTERN_ENABLE__SHIFT                     0x00000002
#define	RE_CNTL__PERSPECTIVE_ENABLE__SHIFT                 0x00000003
#define	RE_CNTL__JITTER_ENABLE__SHIFT                      0x00000004
#define	RE_CNTL__POINT_SMOOTH__SHIFT                       0x00000005
#define	RE_CNTL__VTX_SAVE_T0_N3__SHIFT                     0x00000008
#define	RE_CNTL__VTX_SAVE_T1_N3__SHIFT                     0x00000009
#define	RE_CNTL__VTX_SAVE_T2_N3__SHIFT                     0x0000000a
#define	RE_CNTL__VTX_SAVE_T3_N3__SHIFT                     0x0000000b
#define	RE_CNTL__VTX_SAVE_T4_N3__SHIFT                     0x0000000c
#define	RE_CNTL__VTX_STQ0_ROUTE__SHIFT                     0x00000010
#define	RE_CNTL__VTX_STQ1_ROUTE__SHIFT                     0x00000012
#define	RE_CNTL__VTX_STQ2_ROUTE__SHIFT                     0x00000014
#define	RE_CNTL__VTX_STQ3_ROUTE__SHIFT                     0x00000016
#define	RE_CNTL__VTX_STQ4_ROUTE__SHIFT                     0x00000018
#define	RE_CNTL__VTX_STQ5_ROUTE__SHIFT                     0x0000001a

// RE_PERF_CNTL
#define	RE_PERF_CNTL__CULL_PRESETUP__SHIFT                 0x00000002
#define	RE_PERF_CNTL__CULL_POSTSETUP__SHIFT                0x00000003
#define	RE_PERF_CNTL__BLOCK_DISABLE__SHIFT                 0x00000004
#define	RE_PERF_CNTL__PERFSEL0__SHIFT                      0x00000008
#define	RE_PERF_CNTL__CLR_PERF0__SHIFT                     0x0000000d
#define	RE_PERF_CNTL__EN_PERF0__SHIFT                      0x0000000e
#define	RE_PERF_CNTL__PERFSEL1__SHIFT                      0x00000010
#define	RE_PERF_CNTL__CLR_PERF1__SHIFT                     0x00000015
#define	RE_PERF_CNTL__EN_PERF1__SHIFT                      0x00000016
#define	RE_PERF_CNTL__PERFSEL2__SHIFT                      0x00000018
#define	RE_PERF_CNTL__CLR_PERF2__SHIFT                     0x0000001d
#define	RE_PERF_CNTL__EN_PERF2__SHIFT                      0x0000001e

// RE_PERF_COUNT_0
#define	RE_PERF_COUNT_0__PERF_COUNT__SHIFT                 0x00000000

// RE_PERF_COUNT_1
#define	RE_PERF_COUNT_1__PERF_COUNT__SHIFT                 0x00000000

// RE_PERF_COUNT_2
#define	RE_PERF_COUNT_2__PERF_COUNT__SHIFT                 0x00000000

// RE_DEBUG0
#define	RE_DEBUG0__RE_DWORD__SHIFT                         0x00000000

// RE_DEBUG1
#define	RE_DEBUG1__RE_DWORD__SHIFT                         0x00000000

// RE_DEBUG2
#define	RE_DEBUG2__RE_DWORD__SHIFT                         0x00000000

// RE_DEBUG3
#define	RE_DEBUG3__RE_DWORD__SHIFT                         0x00000000

// RE_DEBUG4
#define	RE_DEBUG4__RE_DWORD__SHIFT                         0x00000000

// RE_DEBUG5
#define	RE_DEBUG5__RE_DWORD__SHIFT                         0x00000000

// RE_DEBUG6
#define	RE_DEBUG6__RE_DWORD__SHIFT                         0x00000000

// RE_DEBUG7
#define	RE_DEBUG7__ONE_PRIM_PER_PASS__SHIFT                0x00000004
#define	RE_DEBUG7__RE_DBG_DATA_M9__SHIFT                   0x00000005

// RE_TOP_LEFT
#define	RE_TOP_LEFT__X_LEFT__SHIFT                         0x00000000
#define	RE_TOP_LEFT__Y_TOP__SHIFT                          0x00000010

// RE_MISC
#define	RE_MISC__STIPPLE_X_OFFSET__SHIFT                   0x00000000
#define	RE_MISC__STIPPLE_Y_OFFSET__SHIFT                   0x00000008
#define	RE_MISC__STIPPLE_BIT_ORDER__SHIFT                  0x00000010

// RE_STIPPLE_ADDR
#define	RE_STIPPLE_ADDR__STIPPLE_ADDR__SHIFT               0x00000000

// RE_STIPPLE_DATA
#define	RE_STIPPLE_DATA__STIPPLE_DATA__SHIFT               0x00000000

// RE_LINE_PATTERN
#define	RE_LINE_PATTERN__LINE_PATTERN__SHIFT               0x00000000
#define	RE_LINE_PATTERN__REPEAT_COUNT__SHIFT               0x00000010
#define	RE_LINE_PATTERN__PATTERN_START__SHIFT              0x00000018
#define	RE_LINE_PATTERN__PATTERN_BIT_ORDER__SHIFT          0x0000001c
#define	RE_LINE_PATTERN__AUTO_RESET_ENABLE__SHIFT          0x0000001d

// RE_LINE_STATE
#define	RE_LINE_STATE__CURRENT_PTR__SHIFT                  0x00000000
#define	RE_LINE_STATE__CURRENT_COUNT__SHIFT                0x00000008

// RE_SCISSOR_TL_0
#define	RE_SCISSOR_TL_0__X_LEFT__SHIFT                     0x00000000
#define	RE_SCISSOR_TL_0__Y_TOP__SHIFT                      0x00000010

// RE_SCISSOR_BR_0
#define	RE_SCISSOR_BR_0__X_RIGHT__SHIFT                    0x00000000
#define	RE_SCISSOR_BR_0__Y_BOTTOM__SHIFT                   0x00000010

// RE_SCISSOR_TL_1
#define	RE_SCISSOR_TL_1__X_LEFT__SHIFT                     0x00000000
#define	RE_SCISSOR_TL_1__Y_TOP__SHIFT                      0x00000010

// RE_SCISSOR_BR_1
#define	RE_SCISSOR_BR_1__X_RIGHT__SHIFT                    0x00000000
#define	RE_SCISSOR_BR_1__Y_BOTTOM__SHIFT                   0x00000010

// RE_SCISSOR_TL_2
#define	RE_SCISSOR_TL_2__X_LEFT__SHIFT                     0x00000000
#define	RE_SCISSOR_TL_2__Y_TOP__SHIFT                      0x00000010

// RE_SCISSOR_BR_2
#define	RE_SCISSOR_BR_2__X_RIGHT__SHIFT                    0x00000000
#define	RE_SCISSOR_BR_2__Y_BOTTOM__SHIFT                   0x00000010

// RE_AUX_SCISSOR_CNTL
#define	RE_AUX_SCISSOR_CNTL__SCISSOR_UNION_ENABLE__SHIFT   0x00000014
#define	RE_AUX_SCISSOR_CNTL__EXCLUSIVE_SCISSOR_0__SHIFT    0x00000018
#define	RE_AUX_SCISSOR_CNTL__EXCLUSIVE_SCISSOR_1__SHIFT    0x00000019
#define	RE_AUX_SCISSOR_CNTL__EXCLUSIVE_SCISSOR_2__SHIFT    0x0000001a
#define	RE_AUX_SCISSOR_CNTL__SCISSOR_ENABLE_0__SHIFT       0x0000001c
#define	RE_AUX_SCISSOR_CNTL__SCISSOR_ENABLE_1__SHIFT       0x0000001d
#define	RE_AUX_SCISSOR_CNTL__SCISSOR_ENABLE_2__SHIFT       0x0000001e

// RE_JITTER_TABLE0
#define	RE_JITTER_TABLE0__SAMPLE_SEL_00__SHIFT             0x00000000
#define	RE_JITTER_TABLE0__SAMPLE_SEL_10__SHIFT             0x00000004
#define	RE_JITTER_TABLE0__SAMPLE_SEL_20__SHIFT             0x00000008
#define	RE_JITTER_TABLE0__SAMPLE_SEL_30__SHIFT             0x0000000c
#define	RE_JITTER_TABLE0__SAMPLE_SEL_01__SHIFT             0x00000010
#define	RE_JITTER_TABLE0__SAMPLE_SEL_11__SHIFT             0x00000014
#define	RE_JITTER_TABLE0__SAMPLE_SEL_21__SHIFT             0x00000018
#define	RE_JITTER_TABLE0__SAMPLE_SEL_31__SHIFT             0x0000001c

// RE_JITTER_TABLE1
#define	RE_JITTER_TABLE1__SAMPLE_SEL_02__SHIFT             0x00000000
#define	RE_JITTER_TABLE1__SAMPLE_SEL_12__SHIFT             0x00000004
#define	RE_JITTER_TABLE1__SAMPLE_SEL_22__SHIFT             0x00000008
#define	RE_JITTER_TABLE1__SAMPLE_SEL_32__SHIFT             0x0000000c
#define	RE_JITTER_TABLE1__SAMPLE_SEL_03__SHIFT             0x00000010
#define	RE_JITTER_TABLE1__SAMPLE_SEL_13__SHIFT             0x00000014
#define	RE_JITTER_TABLE1__SAMPLE_SEL_23__SHIFT             0x00000018
#define	RE_JITTER_TABLE1__SAMPLE_SEL_33__SHIFT             0x0000001c

// PP_FOG_TABLE_INDEX
#define	PP_FOG_TABLE_INDEX__FOG_INDEX__SHIFT               0x00000000

// PP_FOG_TABLE_DATA
#define	PP_FOG_TABLE_DATA__FOG_DATA__SHIFT                 0x00000000

// SE_ZBIAS_FACTOR
#define	SE_ZBIAS_FACTOR__ZBIAS_FACTOR__SHIFT               0x00000000

// SE_ZBIAS_CONSTANT
#define	SE_ZBIAS_CONSTANT__ZBIAS_CONSTANT__SHIFT           0x00000000

// SE_LINE_WIDTH
#define	SE_LINE_WIDTH__LINE_WIDTH__SHIFT                   0x00000000
#define	SE_LINE_WIDTH__MINPOINTSIZE__SHIFT                 0x00000010

// RE_W_BIAS
#define	RE_W_BIAS__W_BIAS__SHIFT                           0x00000000

// SE_MC_SRC2_CNTL
#define	SE_MC_SRC2_CNTL__MC_X2__SHIFT                      0x00000000
#define	SE_MC_SRC2_CNTL__MC_Y2__SHIFT                      0x00000010
#define	SE_MC_SRC2_CNTL__MC_SEC_SRC_PITCH_MUL__SHIFT       0x0000001e

// SE_MC_SRC1_CNTL
#define	SE_MC_SRC1_CNTL__MC_X1__SHIFT                      0x00000000
#define	SE_MC_SRC1_CNTL__MC_Y1__SHIFT                      0x00000010
#define	SE_MC_SRC1_CNTL__MC_IDCT_ENB__SHIFT                0x0000001c
#define	SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB__SHIFT             0x0000001d
#define	SE_MC_SRC1_CNTL__MC_SRC_PITCH_MUL__SHIFT           0x0000001e

// SE_MC_DST_CNTL
#define	SE_MC_DST_CNTL__MC_DST_Y__SHIFT                    0x00000000
#define	SE_MC_DST_CNTL__MC_DST_X__SHIFT                    0x00000010
#define	SE_MC_DST_CNTL__MC_DST_PITCH_MUL__SHIFT            0x0000001e

// SE_MC_CNTL_START
#define	SE_MC_CNTL_START__MC_CNTL_SRC_1_INDEX__SHIFT       0x00000000
#define	SE_MC_CNTL_START__MC_CNTL_DST_OFFSET__SHIFT        0x00000004
#define	SE_MC_CNTL_START__MC_ALPHA_ENB__SHIFT              0x00000019
#define	SE_MC_CNTL_START__MC_CNTL_SRC_2_INDEX__SHIFT       0x0000001a
#define	SE_MC_CNTL_START__MC_CNTL_WIDTH_HEIGHT_SEL__SHIFT  0x0000001d

// SE_MC_BUF_BASE
#define	SE_MC_BUF_BASE__MC_BUF_BASE__SHIFT                 0x00000018

// PP_TXFILTER_0
#define	PP_TXFILTER_0__MAG_FILTER__SHIFT                   0x00000000
#define	PP_TXFILTER_0__MIN_FILTER__SHIFT                   0x00000001
#define	PP_TXFILTER_0__MAX_ANIS__SHIFT                     0x00000005
#define	PP_TXFILTER_0__MAX_MIP_LEVEL__SHIFT                0x00000010
#define	PP_TXFILTER_0__YUV_TO_RGB__SHIFT                   0x00000014
#define	PP_TXFILTER_0__YUV_TEMPERATURE__SHIFT              0x00000015
#define	PP_TXFILTER_0__WRAPEN_S__SHIFT                     0x00000016
#define	PP_TXFILTER_0__CLAMP_S__SHIFT                      0x00000017
#define	PP_TXFILTER_0__WRAPEN_T__SHIFT                     0x0000001a
#define	PP_TXFILTER_0__CLAMP_T__SHIFT                      0x0000001b
#define	PP_TXFILTER_0__KILL_LT_0__SHIFT                    0x0000001e
#define	PP_TXFILTER_0__BORDER_MODE__SHIFT                  0x0000001f

// PP_TXFILTER_1
#define	PP_TXFILTER_1__MAG_FILTER__SHIFT                   0x00000000
#define	PP_TXFILTER_1__MIN_FILTER__SHIFT                   0x00000001
#define	PP_TXFILTER_1__MAX_ANIS__SHIFT                     0x00000005
#define	PP_TXFILTER_1__MAX_MIP_LEVEL__SHIFT                0x00000010
#define	PP_TXFILTER_1__YUV_TO_RGB__SHIFT                   0x00000014
#define	PP_TXFILTER_1__YUV_TEMPERATURE__SHIFT              0x00000015
#define	PP_TXFILTER_1__WRAPEN_S__SHIFT                     0x00000016
#define	PP_TXFILTER_1__CLAMP_S__SHIFT                      0x00000017
#define	PP_TXFILTER_1__WRAPEN_T__SHIFT                     0x0000001a
#define	PP_TXFILTER_1__CLAMP_T__SHIFT                      0x0000001b
#define	PP_TXFILTER_1__KILL_LT_0__SHIFT                    0x0000001e
#define	PP_TXFILTER_1__BORDER_MODE__SHIFT                  0x0000001f

// PP_TXFILTER_2
#define	PP_TXFILTER_2__MAG_FILTER__SHIFT                   0x00000000
#define	PP_TXFILTER_2__MIN_FILTER__SHIFT                   0x00000001
#define	PP_TXFILTER_2__MAX_ANIS__SHIFT                     0x00000005
#define	PP_TXFILTER_2__MAX_MIP_LEVEL__SHIFT                0x00000010
#define	PP_TXFILTER_2__YUV_TO_RGB__SHIFT                   0x00000014
#define	PP_TXFILTER_2__YUV_TEMPERATURE__SHIFT              0x00000015
#define	PP_TXFILTER_2__WRAPEN_S__SHIFT                     0x00000016
#define	PP_TXFILTER_2__CLAMP_S__SHIFT                      0x00000017
#define	PP_TXFILTER_2__WRAPEN_T__SHIFT                     0x0000001a
#define	PP_TXFILTER_2__CLAMP_T__SHIFT                      0x0000001b
#define	PP_TXFILTER_2__KILL_LT_0__SHIFT                    0x0000001e
#define	PP_TXFILTER_2__BORDER_MODE__SHIFT                  0x0000001f

// PP_TXFILTER_3
#define	PP_TXFILTER_3__MAG_FILTER__SHIFT                   0x00000000
#define	PP_TXFILTER_3__MIN_FILTER__SHIFT                   0x00000001
#define	PP_TXFILTER_3__MAX_ANIS__SHIFT                     0x00000005
#define	PP_TXFILTER_3__MAX_MIP_LEVEL__SHIFT                0x00000010
#define	PP_TXFILTER_3__YUV_TO_RGB__SHIFT                   0x00000014
#define	PP_TXFILTER_3__YUV_TEMPERATURE__SHIFT              0x00000015
#define	PP_TXFILTER_3__WRAPEN_S__SHIFT                     0x00000016
#define	PP_TXFILTER_3__CLAMP_S__SHIFT                      0x00000017
#define	PP_TXFILTER_3__WRAPEN_T__SHIFT                     0x0000001a
#define	PP_TXFILTER_3__CLAMP_T__SHIFT                      0x0000001b
#define	PP_TXFILTER_3__KILL_LT_0__SHIFT                    0x0000001e
#define	PP_TXFILTER_3__BORDER_MODE__SHIFT                  0x0000001f

// PP_TXFILTER_4
#define	PP_TXFILTER_4__MAG_FILTER__SHIFT                   0x00000000
#define	PP_TXFILTER_4__MIN_FILTER__SHIFT                   0x00000001
#define	PP_TXFILTER_4__MAX_ANIS__SHIFT                     0x00000005
#define	PP_TXFILTER_4__MAX_MIP_LEVEL__SHIFT                0x00000010
#define	PP_TXFILTER_4__YUV_TO_RGB__SHIFT                   0x00000014
#define	PP_TXFILTER_4__YUV_TEMPERATURE__SHIFT              0x00000015
#define	PP_TXFILTER_4__WRAPEN_S__SHIFT                     0x00000016
#define	PP_TXFILTER_4__CLAMP_S__SHIFT                      0x00000017
#define	PP_TXFILTER_4__WRAPEN_T__SHIFT                     0x0000001a
#define	PP_TXFILTER_4__CLAMP_T__SHIFT                      0x0000001b
#define	PP_TXFILTER_4__KILL_LT_0__SHIFT                    0x0000001e
#define	PP_TXFILTER_4__BORDER_MODE__SHIFT                  0x0000001f

// PP_TXFILTER_5
#define	PP_TXFILTER_5__MAG_FILTER__SHIFT                   0x00000000
#define	PP_TXFILTER_5__MIN_FILTER__SHIFT                   0x00000001
#define	PP_TXFILTER_5__MAX_ANIS__SHIFT                     0x00000005
#define	PP_TXFILTER_5__MAX_MIP_LEVEL__SHIFT                0x00000010
#define	PP_TXFILTER_5__YUV_TO_RGB__SHIFT                   0x00000014
#define	PP_TXFILTER_5__YUV_TEMPERATURE__SHIFT              0x00000015
#define	PP_TXFILTER_5__WRAPEN_S__SHIFT                     0x00000016
#define	PP_TXFILTER_5__CLAMP_S__SHIFT                      0x00000017
#define	PP_TXFILTER_5__WRAPEN_T__SHIFT                     0x0000001a
#define	PP_TXFILTER_5__CLAMP_T__SHIFT                      0x0000001b
#define	PP_TXFILTER_5__KILL_LT_0__SHIFT                    0x0000001e
#define	PP_TXFILTER_5__BORDER_MODE__SHIFT                  0x0000001f

// PP_TXFORMAT_0
#define	PP_TXFORMAT_0__TXFORMAT__SHIFT                     0x00000000
#define	PP_TXFORMAT_0__APPLE_YUV__SHIFT                    0x00000005
#define	PP_TXFORMAT_0__ALPHA_ENABLE__SHIFT                 0x00000006
#define	PP_TXFORMAT_0__NON_POWER2__SHIFT                   0x00000007
#define	PP_TXFORMAT_0__TXWIDTH__SHIFT                      0x00000008
#define	PP_TXFORMAT_0__TXHEIGHT__SHIFT                     0x0000000c
#define	PP_TXFORMAT_0__FACE_WIDTH_5__SHIFT                 0x00000010
#define	PP_TXFORMAT_0__FACE_HEIGHT_5__SHIFT                0x00000014
#define	PP_TXFORMAT_0__ST_ROUTE_R2__SHIFT                  0x00000018
#define	PP_TXFORMAT_0__LOOKUP_DISABLE__SHIFT               0x0000001b
#define	PP_TXFORMAT_0__ALPHA_MASK_ENABLE__SHIFT            0x0000001c
#define	PP_TXFORMAT_0__CHROMA_KEY_ENABLE__SHIFT            0x0000001d

// PP_TXFORMAT_1
#define	PP_TXFORMAT_1__TXFORMAT__SHIFT                     0x00000000
#define	PP_TXFORMAT_1__APPLE_YUV__SHIFT                    0x00000005
#define	PP_TXFORMAT_1__ALPHA_ENABLE__SHIFT                 0x00000006
#define	PP_TXFORMAT_1__NON_POWER2__SHIFT                   0x00000007
#define	PP_TXFORMAT_1__TXWIDTH__SHIFT                      0x00000008
#define	PP_TXFORMAT_1__TXHEIGHT__SHIFT                     0x0000000c
#define	PP_TXFORMAT_1__FACE_WIDTH_5__SHIFT                 0x00000010
#define	PP_TXFORMAT_1__FACE_HEIGHT_5__SHIFT                0x00000014
#define	PP_TXFORMAT_1__ST_ROUTE_R2__SHIFT                  0x00000018
#define	PP_TXFORMAT_1__LOOKUP_DISABLE__SHIFT               0x0000001b
#define	PP_TXFORMAT_1__ALPHA_MASK_ENABLE__SHIFT            0x0000001c
#define	PP_TXFORMAT_1__CHROMA_KEY_ENABLE__SHIFT            0x0000001d

// PP_TXFORMAT_2
#define	PP_TXFORMAT_2__TXFORMAT__SHIFT                     0x00000000
#define	PP_TXFORMAT_2__APPLE_YUV__SHIFT                    0x00000005
#define	PP_TXFORMAT_2__ALPHA_ENABLE__SHIFT                 0x00000006
#define	PP_TXFORMAT_2__NON_POWER2__SHIFT                   0x00000007
#define	PP_TXFORMAT_2__TXWIDTH__SHIFT                      0x00000008
#define	PP_TXFORMAT_2__TXHEIGHT__SHIFT                     0x0000000c
#define	PP_TXFORMAT_2__FACE_WIDTH_5__SHIFT                 0x00000010
#define	PP_TXFORMAT_2__FACE_HEIGHT_5__SHIFT                0x00000014
#define	PP_TXFORMAT_2__ST_ROUTE_R2__SHIFT                  0x00000018
#define	PP_TXFORMAT_2__LOOKUP_DISABLE__SHIFT               0x0000001b
#define	PP_TXFORMAT_2__ALPHA_MASK_ENABLE__SHIFT            0x0000001c
#define	PP_TXFORMAT_2__CHROMA_KEY_ENABLE__SHIFT            0x0000001d

// PP_TXFORMAT_3
#define	PP_TXFORMAT_3__TXFORMAT__SHIFT                     0x00000000
#define	PP_TXFORMAT_3__APPLE_YUV__SHIFT                    0x00000005
#define	PP_TXFORMAT_3__ALPHA_ENABLE__SHIFT                 0x00000006
#define	PP_TXFORMAT_3__NON_POWER2__SHIFT                   0x00000007
#define	PP_TXFORMAT_3__TXWIDTH__SHIFT                      0x00000008
#define	PP_TXFORMAT_3__TXHEIGHT__SHIFT                     0x0000000c
#define	PP_TXFORMAT_3__FACE_WIDTH_5__SHIFT                 0x00000010
#define	PP_TXFORMAT_3__FACE_HEIGHT_5__SHIFT                0x00000014
#define	PP_TXFORMAT_3__ST_ROUTE__SHIFT                     0x00000018
#define	PP_TXFORMAT_3__LOOKUP_DISABLE__SHIFT               0x0000001b
#define	PP_TXFORMAT_3__ALPHA_MASK_ENABLE__SHIFT            0x0000001c
#define	PP_TXFORMAT_3__CHROMA_KEY_ENABLE__SHIFT            0x0000001d

// PP_TXFORMAT_4
#define	PP_TXFORMAT_4__TXFORMAT__SHIFT                     0x00000000
#define	PP_TXFORMAT_4__APPLE_YUV__SHIFT                    0x00000005
#define	PP_TXFORMAT_4__ALPHA_ENABLE__SHIFT                 0x00000006
#define	PP_TXFORMAT_4__NON_POWER2__SHIFT                   0x00000007
#define	PP_TXFORMAT_4__TXWIDTH__SHIFT                      0x00000008
#define	PP_TXFORMAT_4__TXHEIGHT__SHIFT                     0x0000000c
#define	PP_TXFORMAT_4__FACE_WIDTH_5__SHIFT                 0x00000010
#define	PP_TXFORMAT_4__FACE_HEIGHT_5__SHIFT                0x00000014
#define	PP_TXFORMAT_4__ST_ROUTE__SHIFT                     0x00000018
#define	PP_TXFORMAT_4__LOOKUP_DISABLE__SHIFT               0x0000001b
#define	PP_TXFORMAT_4__ALPHA_MASK_ENABLE__SHIFT            0x0000001c
#define	PP_TXFORMAT_4__CHROMA_KEY_ENABLE__SHIFT            0x0000001d

// PP_TXFORMAT_5
#define	PP_TXFORMAT_5__TXFORMAT__SHIFT                     0x00000000
#define	PP_TXFORMAT_5__APPLE_YUV__SHIFT                    0x00000005
#define	PP_TXFORMAT_5__ALPHA_ENABLE__SHIFT                 0x00000006
#define	PP_TXFORMAT_5__NON_POWER2__SHIFT                   0x00000007
#define	PP_TXFORMAT_5__TXWIDTH__SHIFT                      0x00000008
#define	PP_TXFORMAT_5__TXHEIGHT__SHIFT                     0x0000000c
#define	PP_TXFORMAT_5__FACE_WIDTH_5__SHIFT                 0x00000010
#define	PP_TXFORMAT_5__FACE_HEIGHT_5__SHIFT                0x00000014
#define	PP_TXFORMAT_5__ST_ROUTE__SHIFT                     0x00000018
#define	PP_TXFORMAT_5__LOOKUP_DISABLE__SHIFT               0x0000001b
#define	PP_TXFORMAT_5__ALPHA_MASK_ENABLE__SHIFT            0x0000001c
#define	PP_TXFORMAT_5__CHROMA_KEY_ENABLE__SHIFT            0x0000001d

// PP_TXFORMAT_X_0
#define	PP_TXFORMAT_X_0__TXDEPTH__SHIFT                    0x00000000
#define	PP_TXFORMAT_X_0__VOLUME_FILTER__SHIFT              0x00000004
#define	PP_TXFORMAT_X_0__CLAMP_MODE__SHIFT                 0x00000007
#define	PP_TXFORMAT_X_0__WRAPEN_Q__SHIFT                   0x00000008
#define	PP_TXFORMAT_X_0__CLAMP_Q__SHIFT                    0x00000009
#define	PP_TXFORMAT_X_0__MIN_MIP_LEVEL__SHIFT              0x0000000c
#define	PP_TXFORMAT_X_0__TEX_COORD_TYPE__SHIFT             0x00000010
#define	PP_TXFORMAT_X_0__LOD_BIAS__SHIFT                   0x00000013

// PP_TXFORMAT_X_1
#define	PP_TXFORMAT_X_1__TXDEPTH__SHIFT                    0x00000000
#define	PP_TXFORMAT_X_1__VOLUME_FILTER__SHIFT              0x00000004
#define	PP_TXFORMAT_X_1__CLAMP_MODE__SHIFT                 0x00000007
#define	PP_TXFORMAT_X_1__WRAPEN_Q__SHIFT                   0x00000008
#define	PP_TXFORMAT_X_1__CLAMP_Q__SHIFT                    0x00000009
#define	PP_TXFORMAT_X_1__MIN_MIP_LEVEL__SHIFT              0x0000000c
#define	PP_TXFORMAT_X_1__TEX_COORD_TYPE__SHIFT             0x00000010
#define	PP_TXFORMAT_X_1__LOD_BIAS__SHIFT                   0x00000013

// PP_TXFORMAT_X_2
#define	PP_TXFORMAT_X_2__TXDEPTH__SHIFT                    0x00000000
#define	PP_TXFORMAT_X_2__VOLUME_FILTER__SHIFT              0x00000004
#define	PP_TXFORMAT_X_2__CLAMP_MODE__SHIFT                 0x00000007
#define	PP_TXFORMAT_X_2__WRAPEN_Q__SHIFT                   0x00000008
#define	PP_TXFORMAT_X_2__CLAMP_Q__SHIFT                    0x00000009
#define	PP_TXFORMAT_X_2__MIN_MIP_LEVEL__SHIFT              0x0000000c
#define	PP_TXFORMAT_X_2__TEX_COORD_TYPE__SHIFT             0x00000010
#define	PP_TXFORMAT_X_2__LOD_BIAS__SHIFT                   0x00000013

// PP_TXFORMAT_X_3
#define	PP_TXFORMAT_X_3__TXDEPTH__SHIFT                    0x00000000
#define	PP_TXFORMAT_X_3__VOLUME_FILTER__SHIFT              0x00000004
#define	PP_TXFORMAT_X_3__CLAMP_MODE__SHIFT                 0x00000007
#define	PP_TXFORMAT_X_3__WRAPEN_Q__SHIFT                   0x00000008
#define	PP_TXFORMAT_X_3__CLAMP_Q__SHIFT                    0x00000009
#define	PP_TXFORMAT_X_3__MIN_MIP_LEVEL__SHIFT              0x0000000c
#define	PP_TXFORMAT_X_3__TEX_COORD_TYPE__SHIFT             0x00000010
#define	PP_TXFORMAT_X_3__LOD_BIAS__SHIFT                   0x00000013

// PP_TXFORMAT_X_4
#define	PP_TXFORMAT_X_4__TXDEPTH__SHIFT                    0x00000000
#define	PP_TXFORMAT_X_4__VOLUME_FILTER__SHIFT              0x00000004
#define	PP_TXFORMAT_X_4__CLAMP_MODE__SHIFT                 0x00000007
#define	PP_TXFORMAT_X_4__WRAPEN_Q__SHIFT                   0x00000008
#define	PP_TXFORMAT_X_4__CLAMP_Q__SHIFT                    0x00000009
#define	PP_TXFORMAT_X_4__MIN_MIP_LEVEL__SHIFT              0x0000000c
#define	PP_TXFORMAT_X_4__TEX_COORD_TYPE__SHIFT             0x00000010
#define	PP_TXFORMAT_X_4__LOD_BIAS__SHIFT                   0x00000013

// PP_TXFORMAT_X_5
#define	PP_TXFORMAT_X_5__TXDEPTH__SHIFT                    0x00000000
#define	PP_TXFORMAT_X_5__VOLUME_FILTER__SHIFT              0x00000004
#define	PP_TXFORMAT_X_5__CLAMP_MODE__SHIFT                 0x00000007
#define	PP_TXFORMAT_X_5__WRAPEN_Q__SHIFT                   0x00000008
#define	PP_TXFORMAT_X_5__CLAMP_Q__SHIFT                    0x00000009
#define	PP_TXFORMAT_X_5__MIN_MIP_LEVEL__SHIFT              0x0000000c
#define	PP_TXFORMAT_X_5__TEX_COORD_TYPE__SHIFT             0x00000010
#define	PP_TXFORMAT_X_5__LOD_BIAS__SHIFT                   0x00000013

// PP_TEX_SIZE_0
#define	PP_TEX_SIZE_0__TEX_USIZE__SHIFT                    0x00000000
#define	PP_TEX_SIZE_0__TEX_VSIZE__SHIFT                    0x00000010
#define	PP_TEX_SIZE_0__SIGNED_RGB__SHIFT                   0x0000001e
#define	PP_TEX_SIZE_0__SIGNED_ALPHA__SHIFT                 0x0000001f

// PP_TEX_SIZE_1
#define	PP_TEX_SIZE_1__TEX_USIZE__SHIFT                    0x00000000
#define	PP_TEX_SIZE_1__TEX_VSIZE__SHIFT                    0x00000010
#define	PP_TEX_SIZE_1__SIGNED_RGB__SHIFT                   0x0000001e
#define	PP_TEX_SIZE_1__SIGNED_ALPHA__SHIFT                 0x0000001f

// PP_TEX_SIZE_2
#define	PP_TEX_SIZE_2__TEX_USIZE__SHIFT                    0x00000000
#define	PP_TEX_SIZE_2__TEX_VSIZE__SHIFT                    0x00000010
#define	PP_TEX_SIZE_2__SIGNED_RGB__SHIFT                   0x0000001e
#define	PP_TEX_SIZE_2__SIGNED_ALPHA__SHIFT                 0x0000001f

// PP_TEX_SIZE_3
#define	PP_TEX_SIZE_3__TEX_USIZE__SHIFT                    0x00000000
#define	PP_TEX_SIZE_3__TEX_VSIZE__SHIFT                    0x00000010
#define	PP_TEX_SIZE_3__SIGNED_RGB__SHIFT                   0x0000001e
#define	PP_TEX_SIZE_3__SIGNED_ALPHA__SHIFT                 0x0000001f

// PP_TEX_SIZE_4
#define	PP_TEX_SIZE_4__TEX_USIZE__SHIFT                    0x00000000
#define	PP_TEX_SIZE_4__TEX_VSIZE__SHIFT                    0x00000010
#define	PP_TEX_SIZE_4__SIGNED_RGB__SHIFT                   0x0000001e
#define	PP_TEX_SIZE_4__SIGNED_ALPHA__SHIFT                 0x0000001f

// PP_TEX_SIZE_5
#define	PP_TEX_SIZE_5__TEX_USIZE__SHIFT                    0x00000000
#define	PP_TEX_SIZE_5__TEX_VSIZE__SHIFT                    0x00000010
#define	PP_TEX_SIZE_5__SIGNED_RGB__SHIFT                   0x0000001e
#define	PP_TEX_SIZE_5__SIGNED_ALPHA__SHIFT                 0x0000001f

// PP_TXPITCH_0
#define	PP_TXPITCH_0__TXPITCH__SHIFT                       0x00000005
#define	PP_TXPITCH_0__TEX_TAG_CNTL_RV__SHIFT               0x0000001d

// PP_TXPITCH_1
#define	PP_TXPITCH_1__TXPITCH__SHIFT                       0x00000005
#define	PP_TXPITCH_1__TEX_TAG_CNTL_RV__SHIFT               0x0000001d

// PP_TXPITCH_2
#define	PP_TXPITCH_2__TXPITCH__SHIFT                       0x00000005
#define	PP_TXPITCH_2__TEX_TAG_CNTL_RV__SHIFT               0x0000001d

// PP_TXPITCH_3
#define	PP_TXPITCH_3__TXPITCH__SHIFT                       0x00000005
#define	PP_TXPITCH_3__TEX_TAG_CNTL_RV__SHIFT               0x0000001d

// PP_TXPITCH_4
#define	PP_TXPITCH_4__TXPITCH__SHIFT                       0x00000005
#define	PP_TXPITCH_4__TEX_TAG_CNTL_RV__SHIFT               0x0000001d

// PP_TXPITCH_5
#define	PP_TXPITCH_5__TXPITCH__SHIFT                       0x00000005
#define	PP_TXPITCH_5__TEX_TAG_CNTL_RV__SHIFT               0x0000001d

// PP_BORDER_COLOR_0
#define	PP_BORDER_COLOR_0__BORD_COLOR__SHIFT               0x00000000

// PP_BORDER_COLOR_1
#define	PP_BORDER_COLOR_1__BORD_COLOR__SHIFT               0x00000000

// PP_BORDER_COLOR_2
#define	PP_BORDER_COLOR_2__BORD_COLOR__SHIFT               0x00000000

// PP_BORDER_COLOR_3
#define	PP_BORDER_COLOR_3__BORD_COLOR__SHIFT               0x00000000

// PP_BORDER_COLOR_4
#define	PP_BORDER_COLOR_4__BORD_COLOR__SHIFT               0x00000000

// PP_BORDER_COLOR_5
#define	PP_BORDER_COLOR_5__BORD_COLOR__SHIFT               0x00000000

// PP_CUBIC_FACES_0
#define	PP_CUBIC_FACES_0__FACE_WIDTH_1__SHIFT              0x00000000
#define	PP_CUBIC_FACES_0__FACE_HEIGHT_1__SHIFT             0x00000004
#define	PP_CUBIC_FACES_0__FACE_WIDTH_2__SHIFT              0x00000008
#define	PP_CUBIC_FACES_0__FACE_HEIGHT_2__SHIFT             0x0000000c
#define	PP_CUBIC_FACES_0__FACE_WIDTH_3__SHIFT              0x00000010
#define	PP_CUBIC_FACES_0__FACE_HEIGHT_3__SHIFT             0x00000014
#define	PP_CUBIC_FACES_0__FACE_WIDTH_4__SHIFT              0x00000018
#define	PP_CUBIC_FACES_0__FACE_HEIGHT_4__SHIFT             0x0000001c

// PP_CUBIC_FACES_1
#define	PP_CUBIC_FACES_1__FACE_WIDTH_1__SHIFT              0x00000000
#define	PP_CUBIC_FACES_1__FACE_HEIGHT_1__SHIFT             0x00000004
#define	PP_CUBIC_FACES_1__FACE_WIDTH_2__SHIFT              0x00000008
#define	PP_CUBIC_FACES_1__FACE_HEIGHT_2__SHIFT             0x0000000c
#define	PP_CUBIC_FACES_1__FACE_WIDTH_3__SHIFT              0x00000010
#define	PP_CUBIC_FACES_1__FACE_HEIGHT_3__SHIFT             0x00000014
#define	PP_CUBIC_FACES_1__FACE_WIDTH_4__SHIFT              0x00000018
#define	PP_CUBIC_FACES_1__FACE_HEIGHT_4__SHIFT             0x0000001c

// PP_CUBIC_FACES_2
#define	PP_CUBIC_FACES_2__FACE_WIDTH_1__SHIFT              0x00000000
#define	PP_CUBIC_FACES_2__FACE_HEIGHT_1__SHIFT             0x00000004
#define	PP_CUBIC_FACES_2__FACE_WIDTH_2__SHIFT              0x00000008
#define	PP_CUBIC_FACES_2__FACE_HEIGHT_2__SHIFT             0x0000000c
#define	PP_CUBIC_FACES_2__FACE_WIDTH_3__SHIFT              0x00000010
#define	PP_CUBIC_FACES_2__FACE_HEIGHT_3__SHIFT             0x00000014
#define	PP_CUBIC_FACES_2__FACE_WIDTH_4__SHIFT              0x00000018
#define	PP_CUBIC_FACES_2__FACE_HEIGHT_4__SHIFT             0x0000001c

// PP_CUBIC_FACES_3
#define	PP_CUBIC_FACES_3__FACE_WIDTH_1__SHIFT              0x00000000
#define	PP_CUBIC_FACES_3__FACE_HEIGHT_1__SHIFT             0x00000004
#define	PP_CUBIC_FACES_3__FACE_WIDTH_2__SHIFT              0x00000008
#define	PP_CUBIC_FACES_3__FACE_HEIGHT_2__SHIFT             0x0000000c
#define	PP_CUBIC_FACES_3__FACE_WIDTH_3__SHIFT              0x00000010
#define	PP_CUBIC_FACES_3__FACE_HEIGHT_3__SHIFT             0x00000014
#define	PP_CUBIC_FACES_3__FACE_WIDTH_4__SHIFT              0x00000018
#define	PP_CUBIC_FACES_3__FACE_HEIGHT_4__SHIFT             0x0000001c

// PP_CUBIC_FACES_4
#define	PP_CUBIC_FACES_4__FACE_WIDTH_1__SHIFT              0x00000000
#define	PP_CUBIC_FACES_4__FACE_HEIGHT_1__SHIFT             0x00000004
#define	PP_CUBIC_FACES_4__FACE_WIDTH_2__SHIFT              0x00000008
#define	PP_CUBIC_FACES_4__FACE_HEIGHT_2__SHIFT             0x0000000c
#define	PP_CUBIC_FACES_4__FACE_WIDTH_3__SHIFT              0x00000010
#define	PP_CUBIC_FACES_4__FACE_HEIGHT_3__SHIFT             0x00000014
#define	PP_CUBIC_FACES_4__FACE_WIDTH_4__SHIFT              0x00000018
#define	PP_CUBIC_FACES_4__FACE_HEIGHT_4__SHIFT             0x0000001c

// PP_CUBIC_FACES_5
#define	PP_CUBIC_FACES_5__FACE_WIDTH_1__SHIFT              0x00000000
#define	PP_CUBIC_FACES_5__FACE_HEIGHT_1__SHIFT             0x00000004
#define	PP_CUBIC_FACES_5__FACE_WIDTH_2__SHIFT              0x00000008
#define	PP_CUBIC_FACES_5__FACE_HEIGHT_2__SHIFT             0x0000000c
#define	PP_CUBIC_FACES_5__FACE_WIDTH_3__SHIFT              0x00000010
#define	PP_CUBIC_FACES_5__FACE_HEIGHT_3__SHIFT             0x00000014
#define	PP_CUBIC_FACES_5__FACE_WIDTH_4__SHIFT              0x00000018
#define	PP_CUBIC_FACES_5__FACE_HEIGHT_4__SHIFT             0x0000001c

// PP_TXMULTI_CTL_0
#define	PP_TXMULTI_CTL_0__LOOKUP_DISABLE_1__SHIFT          0x00000000
#define	PP_TXMULTI_CTL_0__TEX_COORD_TYPE_1__SHIFT          0x00000001
#define	PP_TXMULTI_CTL_0__ST_ROUTE_1__SHIFT                0x00000004
#define	PP_TXMULTI_CTL_0__CLAMP_MODE__SHIFT                0x00000008
#define	PP_TXMULTI_CTL_0__ST_ROUTE_2__SHIFT                0x00000018

// PP_TXMULTI_CTL_1
#define	PP_TXMULTI_CTL_1__LOOKUP_DISABLE_1__SHIFT          0x00000000
#define	PP_TXMULTI_CTL_1__TEX_COORD_TYPE_1__SHIFT          0x00000001
#define	PP_TXMULTI_CTL_1__ST_ROUTE_1__SHIFT                0x00000004
#define	PP_TXMULTI_CTL_1__CLAMP_MODE__SHIFT                0x00000008
#define	PP_TXMULTI_CTL_1__ST_ROUTE_2__SHIFT                0x00000018

// PP_TXMULTI_CTL_2
#define	PP_TXMULTI_CTL_2__LOOKUP_DISABLE_1__SHIFT          0x00000000
#define	PP_TXMULTI_CTL_2__TEX_COORD_TYPE_1__SHIFT          0x00000001
#define	PP_TXMULTI_CTL_2__ST_ROUTE_1__SHIFT                0x00000004
#define	PP_TXMULTI_CTL_2__CLAMP_MODE__SHIFT                0x00000008
#define	PP_TXMULTI_CTL_2__ST_ROUTE_2__SHIFT                0x00000018

// PP_TXMULTI_CTL_3
#define	PP_TXMULTI_CTL_3__LOOKUP_DISABLE_1__SHIFT          0x00000000
#define	PP_TXMULTI_CTL_3__TEX_COORD_TYPE_1__SHIFT          0x00000001
#define	PP_TXMULTI_CTL_3__ST_ROUTE_1__SHIFT                0x00000004
#define	PP_TXMULTI_CTL_3__CLAMP_MODE__SHIFT                0x00000008
#define	PP_TXMULTI_CTL_3__ST_ROUTE_2__SHIFT                0x00000018

// PP_TXMULTI_CTL_4
#define	PP_TXMULTI_CTL_4__LOOKUP_DISABLE_1__SHIFT          0x00000000
#define	PP_TXMULTI_CTL_4__TEX_COORD_TYPE_1__SHIFT          0x00000001
#define	PP_TXMULTI_CTL_4__ST_ROUTE_1__SHIFT                0x00000004
#define	PP_TXMULTI_CTL_4__CLAMP_MODE__SHIFT                0x00000008
#define	PP_TXMULTI_CTL_4__ST_ROUTE_2__SHIFT                0x00000018

// PP_TXMULTI_CTL_5
#define	PP_TXMULTI_CTL_5__LOOKUP_DISABLE_1__SHIFT          0x00000000
#define	PP_TXMULTI_CTL_5__TEX_COORD_TYPE_1__SHIFT          0x00000001
#define	PP_TXMULTI_CTL_5__ST_ROUTE_1__SHIFT                0x00000004
#define	PP_TXMULTI_CTL_5__CLAMP_MODE__SHIFT                0x00000008
#define	PP_TXMULTI_CTL_5__ST_ROUTE_2__SHIFT                0x00000018

// PP_CNTL
#define	PP_CNTL__TEX_0_ENABLE__SHIFT                       0x00000004
#define	PP_CNTL__TEX_1_ENABLE__SHIFT                       0x00000005
#define	PP_CNTL__TEX_2_ENABLE__SHIFT                       0x00000006
#define	PP_CNTL__TEX_3_ENABLE__SHIFT                       0x00000007
#define	PP_CNTL__TEX_4_ENABLE__SHIFT                       0x00000008
#define	PP_CNTL__TEX_5_ENABLE__SHIFT                       0x00000009
#define	PP_CNTL__FILTER_ROUND_MODE__SHIFT                  0x0000000a
#define	PP_CNTL__TEX_BLEND_7_ENABLE__SHIFT                 0x0000000b
#define	PP_CNTL__TEX_BLEND_0_ENABLE__SHIFT                 0x0000000c
#define	PP_CNTL__TEX_BLEND_1_ENABLE__SHIFT                 0x0000000d
#define	PP_CNTL__TEX_BLEND_2_ENABLE__SHIFT                 0x0000000e
#define	PP_CNTL__TEX_BLEND_3_ENABLE__SHIFT                 0x0000000f
#define	PP_CNTL__TEX_BLEND_4_ENABLE__SHIFT                 0x00000010
#define	PP_CNTL__TEX_BLEND_5_ENABLE__SHIFT                 0x00000011
#define	PP_CNTL__TEX_BLEND_6_ENABLE__SHIFT                 0x00000012
#define	PP_CNTL__MULTI_PASS_ENABLE__SHIFT                  0x00000013
#define	PP_CNTL__SPECULAR_ENABLE__SHIFT                    0x00000015
#define	PP_CNTL__FOG_ENABLE__SHIFT                         0x00000016
#define	PP_CNTL__ALPHA_TEST_ENABLE__SHIFT                  0x00000017
#define	PP_CNTL__ANTI_ALIAS_CTL__SHIFT                     0x00000018
#define	PP_CNTL__MC_ENABLE__SHIFT                          0x0000001f

// PP_CNTL_X
#define	PP_CNTL_X__TEX_0_ENABLE_PASS_1__SHIFT              0x00000000
#define	PP_CNTL_X__TEX_1_ENABLE_PASS_1__SHIFT              0x00000001
#define	PP_CNTL_X__TEX_2_ENABLE_PASS_1__SHIFT              0x00000002
#define	PP_CNTL_X__TEX_3_ENABLE_PASS_1__SHIFT              0x00000003
#define	PP_CNTL_X__TEX_4_ENABLE_PASS_1__SHIFT              0x00000004
#define	PP_CNTL_X__TEX_5_ENABLE_PASS_1__SHIFT              0x00000005
#define	PP_CNTL_X__INDIRECT_REGS__SHIFT                    0x00000006
#define	PP_CNTL_X__TEX_BLEND_A0_ENABLE__SHIFT              0x0000000c
#define	PP_CNTL_X__TEX_BLEND_A1_ENABLE__SHIFT              0x0000000d
#define	PP_CNTL_X__TEX_BLEND_A2_ENABLE__SHIFT              0x0000000e
#define	PP_CNTL_X__TEX_BLEND_A3_ENABLE__SHIFT              0x0000000f
#define	PP_CNTL_X__TEX_BLEND_A4_ENABLE__SHIFT              0x00000010
#define	PP_CNTL_X__TEX_BLEND_A5_ENABLE__SHIFT              0x00000011
#define	PP_CNTL_X__TEX_BLEND_A6_ENABLE__SHIFT              0x00000012
#define	PP_CNTL_X__TEX_BLEND_A7_ENABLE__SHIFT              0x00000013
#define	PP_CNTL_X__SHADER_OUTPUT_CNTL__SHIFT               0x0000001f

// PP_MISC
#define	PP_MISC__REF_ALPHA__SHIFT                          0x00000000
#define	PP_MISC__ALPHA_TEST_OP__SHIFT                      0x00000008
#define	PP_MISC__CHROMA_FUNC__SHIFT                        0x00000010
#define	PP_MISC__CHROMA_KEY_MODE__SHIFT                    0x00000012
#define	PP_MISC__RIGHT_HAND_CUBE__SHIFT                    0x00000018

// PP_CHROMA_COLOR
#define	PP_CHROMA_COLOR__CHROMA_COLOR__SHIFT               0x00000000

// PP_CHROMA_MASK
#define	PP_CHROMA_MASK__CHROMA_MASK__SHIFT                 0x00000000

// PP_FOG_COLOR
#define	PP_FOG_COLOR__FOG_COLOR__SHIFT                     0x00000000
#define	PP_FOG_COLOR__FOG_TABLE__SHIFT                     0x00000018
#define	PP_FOG_COLOR__FOG_INDEX_SEL_R2__SHIFT              0x00000019

// PP_PERF_COUNT0
#define	PP_PERF_COUNT0__PP_CACHE_COUNT__SHIFT              0x00000000

// PP_MC_CONTEXT
#define	PP_MC_CONTEXT__MC_BUF_BASE__SHIFT                  0x00000000
#define	PP_MC_CONTEXT__SRC1_INDEX__SHIFT                   0x00000008
#define	PP_MC_CONTEXT__SRC2_INDEX__SHIFT                   0x0000000c
#define	PP_MC_CONTEXT__MC_FUNC__SHIFT                      0x0000000f
#define	PP_MC_CONTEXT__DST_PITCH_MUL__SHIFT                0x00000012
#define	PP_MC_CONTEXT__SRC_2_PITCH_MUL__SHIFT              0x00000014
#define	PP_MC_CONTEXT__SRC_1_PITCH_MUL__SHIFT              0x00000016
#define	PP_MC_CONTEXT__MC_CNTL_WIDTH_HEIGHT_SEL__SHIFT     0x00000018

// PP_LUMI_MATRIX
#define	PP_LUMI_MATRIX__LSCALE__SHIFT                      0x00000000
#define	PP_LUMI_MATRIX__LOFFSET__SHIFT                     0x00000010

// PP_ROT_MATRIX0
#define	PP_ROT_MATRIX0__M00__SHIFT                         0x00000000
#define	PP_ROT_MATRIX0__M10__SHIFT                         0x00000010

// PP_ROT_MATRIX1
#define	PP_ROT_MATRIX1__M01__SHIFT                         0x00000000
#define	PP_ROT_MATRIX1__M11__SHIFT                         0x00000010

// PP_TRI_PERF
#define	PP_TRI_PERF__TRI_JUICE__SHIFT                      0x00000000

// PP_PERF_CNTL
#define	PP_PERF_CNTL__RR_FIFO_SCALE__SHIFT                 0x00000000
#define	PP_PERF_CNTL__REQUEST_SCALE__SHIFT                 0x00000002
#define	PP_PERF_CNTL__PP_COUNT_CTL__SHIFT                  0x00000004

// PP_TXOFFSET_0
#define	PP_TXOFFSET_0__ENDIAN_SWAP__SHIFT                  0x00000000
#define	PP_TXOFFSET_0__MACRO_TILE__SHIFT                   0x00000002
#define	PP_TXOFFSET_0__MICRO_TILE__SHIFT                   0x00000003
#define	PP_TXOFFSET_0__TXOFFSET__SHIFT                     0x00000005

// PP_TXOFFSET_1
#define	PP_TXOFFSET_1__ENDIAN_SWAP__SHIFT                  0x00000000
#define	PP_TXOFFSET_1__MACRO_TILE__SHIFT                   0x00000002
#define	PP_TXOFFSET_1__MICRO_TILE__SHIFT                   0x00000003
#define	PP_TXOFFSET_1__TXOFFSET__SHIFT                     0x00000005

// PP_TXOFFSET_2
#define	PP_TXOFFSET_2__ENDIAN_SWAP__SHIFT                  0x00000000
#define	PP_TXOFFSET_2__MACRO_TILE__SHIFT                   0x00000002
#define	PP_TXOFFSET_2__MICRO_TILE__SHIFT                   0x00000003
#define	PP_TXOFFSET_2__TXOFFSET__SHIFT                     0x00000005

// PP_TXOFFSET_3
#define	PP_TXOFFSET_3__ENDIAN_SWAP__SHIFT                  0x00000000
#define	PP_TXOFFSET_3__MACRO_TILE__SHIFT                   0x00000002
#define	PP_TXOFFSET_3__MICRO_TILE__SHIFT                   0x00000003
#define	PP_TXOFFSET_3__TXOFFSET__SHIFT                     0x00000005

// PP_TXOFFSET_4
#define	PP_TXOFFSET_4__ENDIAN_SWAP__SHIFT                  0x00000000
#define	PP_TXOFFSET_4__MACRO_TILE__SHIFT                   0x00000002
#define	PP_TXOFFSET_4__MICRO_TILE__SHIFT                   0x00000003
#define	PP_TXOFFSET_4__TXOFFSET__SHIFT                     0x00000005

// PP_TXOFFSET_5
#define	PP_TXOFFSET_5__ENDIAN_SWAP__SHIFT                  0x00000000
#define	PP_TXOFFSET_5__MACRO_TILE__SHIFT                   0x00000002
#define	PP_TXOFFSET_5__MICRO_TILE__SHIFT                   0x00000003
#define	PP_TXOFFSET_5__TXOFFSET__SHIFT                     0x00000005

// PP_CUBIC_OFFSET_F1_0
#define	PP_CUBIC_OFFSET_F1_0__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F1_0__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F1_0__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F1_0__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F1_1
#define	PP_CUBIC_OFFSET_F1_1__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F1_1__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F1_1__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F1_1__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F1_2
#define	PP_CUBIC_OFFSET_F1_2__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F1_2__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F1_2__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F1_2__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F1_3
#define	PP_CUBIC_OFFSET_F1_3__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F1_3__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F1_3__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F1_3__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F1_4
#define	PP_CUBIC_OFFSET_F1_4__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F1_4__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F1_4__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F1_4__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F1_5
#define	PP_CUBIC_OFFSET_F1_5__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F1_5__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F1_5__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F1_5__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F2_0
#define	PP_CUBIC_OFFSET_F2_0__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F2_0__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F2_0__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F2_0__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F2_1
#define	PP_CUBIC_OFFSET_F2_1__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F2_1__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F2_1__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F2_1__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F2_2
#define	PP_CUBIC_OFFSET_F2_2__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F2_2__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F2_2__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F2_2__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F2_3
#define	PP_CUBIC_OFFSET_F2_3__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F2_3__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F2_3__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F2_3__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F2_4
#define	PP_CUBIC_OFFSET_F2_4__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F2_4__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F2_4__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F2_4__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F2_5
#define	PP_CUBIC_OFFSET_F2_5__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F2_5__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F2_5__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F2_5__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F3_0
#define	PP_CUBIC_OFFSET_F3_0__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F3_0__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F3_0__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F3_0__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F3_1
#define	PP_CUBIC_OFFSET_F3_1__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F3_1__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F3_1__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F3_1__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F3_2
#define	PP_CUBIC_OFFSET_F3_2__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F3_2__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F3_2__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F3_2__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F3_3
#define	PP_CUBIC_OFFSET_F3_3__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F3_3__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F3_3__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F3_3__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F3_4
#define	PP_CUBIC_OFFSET_F3_4__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F3_4__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F3_4__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F3_4__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F3_5
#define	PP_CUBIC_OFFSET_F3_5__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F3_5__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F3_5__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F3_5__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F4_0
#define	PP_CUBIC_OFFSET_F4_0__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F4_0__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F4_0__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F4_0__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F4_1
#define	PP_CUBIC_OFFSET_F4_1__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F4_1__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F4_1__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F4_1__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F4_2
#define	PP_CUBIC_OFFSET_F4_2__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F4_2__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F4_2__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F4_2__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F4_3
#define	PP_CUBIC_OFFSET_F4_3__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F4_3__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F4_3__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F4_3__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F4_4
#define	PP_CUBIC_OFFSET_F4_4__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F4_4__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F4_4__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F4_4__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F4_5
#define	PP_CUBIC_OFFSET_F4_5__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F4_5__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F4_5__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F4_5__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F5_0
#define	PP_CUBIC_OFFSET_F5_0__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F5_0__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F5_0__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F5_0__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F5_1
#define	PP_CUBIC_OFFSET_F5_1__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F5_1__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F5_1__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F5_1__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F5_2
#define	PP_CUBIC_OFFSET_F5_2__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F5_2__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F5_2__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F5_2__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F5_3
#define	PP_CUBIC_OFFSET_F5_3__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F5_3__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F5_3__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F5_3__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F5_4
#define	PP_CUBIC_OFFSET_F5_4__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F5_4__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F5_4__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F5_4__FACE_OFFSET__SHIFT           0x00000005

// PP_CUBIC_OFFSET_F5_5
#define	PP_CUBIC_OFFSET_F5_5__ENDIAN_SWAP__SHIFT           0x00000000
#define	PP_CUBIC_OFFSET_F5_5__MACRO_TILE__SHIFT            0x00000002
#define	PP_CUBIC_OFFSET_F5_5__MICRO_TILE__SHIFT            0x00000003
#define	PP_CUBIC_OFFSET_F5_5__FACE_OFFSET__SHIFT           0x00000005

// PP_TAM_DEBUG0
#define	PP_TAM_DEBUG0__TAM_DWORD__SHIFT                    0x00000000

// PP_TAM_DEBUG1
#define	PP_TAM_DEBUG1__TAM_DWORD__SHIFT                    0x00000000

// PP_TAM_DEBUG2
#define	PP_TAM_DEBUG2__TAM_DWORD__SHIFT                    0x00000000

// PP_TDM_DEBUG0
#define	PP_TDM_DEBUG0__TDM_DWORD__SHIFT                    0x00000000

// PP_TDM_DEBUG1
#define	PP_TDM_DEBUG1__TDM_DWORD__SHIFT                    0x00000000

// PP_TDM_DEBUG2
#define	PP_TDM_DEBUG2__TDM_DWORD__SHIFT                    0x00000000

// PP_PB_DEBUG0
#define	PP_PB_DEBUG0__PB_DWORD__SHIFT                      0x00000000

// PP_PB_DEBUG1
#define	PP_PB_DEBUG1__PB_DWORD__SHIFT                      0x00000000

// PP_PB_DEBUG2
#define	PP_PB_DEBUG2__PB_DWORD__SHIFT                      0x00000000

// PP_TAM_DEBUG3
#define	PP_TAM_DEBUG3__TAM_DWORD__SHIFT                    0x00000000

// PP_TDM_DEBUG3
#define	PP_TDM_DEBUG3__TDM_DWORD__SHIFT                    0x00000000

// PP_PB_DEBUG3
#define	PP_PB_DEBUG3__PB_DWORD__SHIFT                      0x00000000

// PP_SRC_OFFSET_0
#define	PP_SRC_OFFSET_0__MC_OFFSET__SHIFT                  0x00000005

// PP_SRC_OFFSET_1
#define	PP_SRC_OFFSET_1__MC_OFFSET__SHIFT                  0x00000005

// PP_SRC_OFFSET_2
#define	PP_SRC_OFFSET_2__MC_OFFSET__SHIFT                  0x00000005

// PP_SRC_OFFSET_3
#define	PP_SRC_OFFSET_3__MC_OFFSET__SHIFT                  0x00000005

// PP_SRC_OFFSET_4
#define	PP_SRC_OFFSET_4__MC_OFFSET__SHIFT                  0x00000005

// PP_SRC_OFFSET_5
#define	PP_SRC_OFFSET_5__MC_OFFSET__SHIFT                  0x00000005

// PP_SRC_OFFSET_6
#define	PP_SRC_OFFSET_6__MC_OFFSET__SHIFT                  0x00000005

// PP_SRC_OFFSET_7
#define	PP_SRC_OFFSET_7__MC_OFFSET__SHIFT                  0x00000005

// PP_SRC_OFFSET_8
#define	PP_SRC_OFFSET_8__MC_OFFSET__SHIFT                  0x00000005

// PP_SRC_OFFSET_9
#define	PP_SRC_OFFSET_9__MC_OFFSET__SHIFT                  0x00000005

// PP_SRC_OFFSET_10
#define	PP_SRC_OFFSET_10__MC_OFFSET__SHIFT                 0x00000005

// PP_SRC_OFFSET_11
#define	PP_SRC_OFFSET_11__MC_OFFSET__SHIFT                 0x00000005

// PP_SRC_OFFSET_12
#define	PP_SRC_OFFSET_12__MC_OFFSET__SHIFT                 0x00000005

// PP_SRC_OFFSET_13
#define	PP_SRC_OFFSET_13__MC_OFFSET__SHIFT                 0x00000005

// PP_SRC_OFFSET_14
#define	PP_SRC_OFFSET_14__MC_OFFSET__SHIFT                 0x00000005

// PP_SRC_OFFSET_15
#define	PP_SRC_OFFSET_15__MC_OFFSET__SHIFT                 0x00000005

// PP_SRC_OFFSET_16
#define	PP_SRC_OFFSET_16__MC_OFFSET__SHIFT                 0x00000005

// PP_SRC_OFFSET_17
#define	PP_SRC_OFFSET_17__MC_OFFSET__SHIFT                 0x00000005

// PP_TFACTOR_SIGN
#define	PP_TFACTOR_SIGN__SGN_TF0_B__SHIFT                  0x00000000
#define	PP_TFACTOR_SIGN__SGN_TF0_G__SHIFT                  0x00000001
#define	PP_TFACTOR_SIGN__SGN_TF0_R__SHIFT                  0x00000002
#define	PP_TFACTOR_SIGN__SGN_TF0_A__SHIFT                  0x00000003
#define	PP_TFACTOR_SIGN__SGN_TF1_B__SHIFT                  0x00000004
#define	PP_TFACTOR_SIGN__SGN_TF1_G__SHIFT                  0x00000005
#define	PP_TFACTOR_SIGN__SGN_TF1_R__SHIFT                  0x00000006
#define	PP_TFACTOR_SIGN__SGN_TF1_A__SHIFT                  0x00000007
#define	PP_TFACTOR_SIGN__SGN_TF2_B__SHIFT                  0x00000008
#define	PP_TFACTOR_SIGN__SGN_TF2_G__SHIFT                  0x00000009
#define	PP_TFACTOR_SIGN__SGN_TF2_R__SHIFT                  0x0000000a
#define	PP_TFACTOR_SIGN__SGN_TF2_A__SHIFT                  0x0000000b
#define	PP_TFACTOR_SIGN__SGN_TF3_B__SHIFT                  0x0000000c
#define	PP_TFACTOR_SIGN__SGN_TF3_G__SHIFT                  0x0000000d
#define	PP_TFACTOR_SIGN__SGN_TF3_R__SHIFT                  0x0000000e
#define	PP_TFACTOR_SIGN__SGN_TF3_A__SHIFT                  0x0000000f
#define	PP_TFACTOR_SIGN__SGN_TF4_B__SHIFT                  0x00000010
#define	PP_TFACTOR_SIGN__SGN_TF4_G__SHIFT                  0x00000011
#define	PP_TFACTOR_SIGN__SGN_TF4_R__SHIFT                  0x00000012
#define	PP_TFACTOR_SIGN__SGN_TF4_A__SHIFT                  0x00000013
#define	PP_TFACTOR_SIGN__SGN_TF5_B__SHIFT                  0x00000014
#define	PP_TFACTOR_SIGN__SGN_TF5_G__SHIFT                  0x00000015
#define	PP_TFACTOR_SIGN__SGN_TF5_R__SHIFT                  0x00000016
#define	PP_TFACTOR_SIGN__SGN_TF5_A__SHIFT                  0x00000017
#define	PP_TFACTOR_SIGN__SGN_TF6_B__SHIFT                  0x00000018
#define	PP_TFACTOR_SIGN__SGN_TF6_G__SHIFT                  0x00000019
#define	PP_TFACTOR_SIGN__SGN_TF6_R__SHIFT                  0x0000001a
#define	PP_TFACTOR_SIGN__SGN_TF6_A__SHIFT                  0x0000001b
#define	PP_TFACTOR_SIGN__SGN_TF7_B__SHIFT                  0x0000001c
#define	PP_TFACTOR_SIGN__SGN_TF7_G__SHIFT                  0x0000001d
#define	PP_TFACTOR_SIGN__SGN_TF7_R__SHIFT                  0x0000001e
#define	PP_TFACTOR_SIGN__SGN_TF7_A__SHIFT                  0x0000001f

// PP_TFACTOR_0
#define	PP_TFACTOR_0__TFACTOR__SHIFT                       0x00000000

// PP_TFACTOR_1
#define	PP_TFACTOR_1__TFACTOR__SHIFT                       0x00000000

// PP_TFACTOR_2
#define	PP_TFACTOR_2__TFACTOR__SHIFT                       0x00000000

// PP_TFACTOR_3
#define	PP_TFACTOR_3__TFACTOR__SHIFT                       0x00000000

// PP_TFACTOR_4
#define	PP_TFACTOR_4__TFACTOR__SHIFT                       0x00000000

// PP_TFACTOR_5
#define	PP_TFACTOR_5__TFACTOR__SHIFT                       0x00000000

// PP_TFACTOR_6
#define	PP_TFACTOR_6__TFACTOR__SHIFT                       0x00000000

// PP_TFACTOR_7
#define	PP_TFACTOR_7__TFACTOR__SHIFT                       0x00000000

// PP_PIXSHADER_I0_C0
#define	PP_PIXSHADER_I0_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I0_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I0_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I0_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I0_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I0_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I0_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I0_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I0_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I0_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I0_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I0_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I0_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I0_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I0_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I0_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I1_C0
#define	PP_PIXSHADER_I1_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I1_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I1_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I1_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I1_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I1_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I1_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I1_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I1_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I1_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I1_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I1_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I1_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I1_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I1_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I1_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I2_C0
#define	PP_PIXSHADER_I2_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I2_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I2_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I2_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I2_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I2_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I2_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I2_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I2_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I2_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I2_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I2_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I2_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I2_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I2_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I2_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I3_C0
#define	PP_PIXSHADER_I3_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I3_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I3_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I3_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I3_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I3_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I3_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I3_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I3_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I3_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I3_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I3_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I3_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I3_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I3_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I3_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I4_C0
#define	PP_PIXSHADER_I4_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I4_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I4_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I4_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I4_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I4_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I4_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I4_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I4_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I4_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I4_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I4_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I4_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I4_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I4_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I4_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I5_C0
#define	PP_PIXSHADER_I5_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I5_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I5_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I5_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I5_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I5_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I5_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I5_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I5_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I5_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I5_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I5_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I5_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I5_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I5_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I5_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I6_C0
#define	PP_PIXSHADER_I6_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I6_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I6_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I6_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I6_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I6_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I6_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I6_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I6_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I6_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I6_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I6_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I6_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I6_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I6_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I6_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I7_C0
#define	PP_PIXSHADER_I7_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I7_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I7_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I7_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I7_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I7_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I7_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I7_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I7_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I7_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I7_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I7_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I7_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I7_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I7_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I7_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I0_C1
#define	PP_PIXSHADER_I0_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I0_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I0_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I0_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I0_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I0_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_PIXSHADER_I0_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_PIXSHADER_I0_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I0_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I0_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_PIXSHADER_I1_C1
#define	PP_PIXSHADER_I1_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I1_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I1_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I1_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I1_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I1_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_PIXSHADER_I1_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_PIXSHADER_I1_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I1_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I1_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_PIXSHADER_I2_C1
#define	PP_PIXSHADER_I2_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I2_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I2_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I2_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I2_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I2_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_PIXSHADER_I2_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_PIXSHADER_I2_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I2_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I2_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_PIXSHADER_I3_C1
#define	PP_PIXSHADER_I3_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I3_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I3_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I3_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I3_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I3_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_PIXSHADER_I3_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_PIXSHADER_I3_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I3_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I3_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_PIXSHADER_I4_C1
#define	PP_PIXSHADER_I4_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I4_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I4_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I4_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I4_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I4_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_PIXSHADER_I4_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_PIXSHADER_I4_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I4_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I4_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_PIXSHADER_I5_C1
#define	PP_PIXSHADER_I5_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I5_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I5_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I5_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I5_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I5_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_PIXSHADER_I5_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_PIXSHADER_I5_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I5_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I5_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_PIXSHADER_I6_C1
#define	PP_PIXSHADER_I6_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I6_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I6_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I6_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I6_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I6_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_PIXSHADER_I6_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_PIXSHADER_I6_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I6_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I6_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_PIXSHADER_I7_C1
#define	PP_PIXSHADER_I7_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I7_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I7_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I7_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I7_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I7_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_PIXSHADER_I7_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_PIXSHADER_I7_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I7_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I7_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_PIXSHADER_I0_A0
#define	PP_PIXSHADER_I0_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I0_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I0_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I0_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I0_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I0_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I0_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I0_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I0_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I0_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I0_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I0_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I0_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I0_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I0_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I0_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I1_A0
#define	PP_PIXSHADER_I1_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I1_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I1_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I1_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I1_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I1_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I1_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I1_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I1_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I1_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I1_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I1_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I1_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I1_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I1_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I1_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I2_A0
#define	PP_PIXSHADER_I2_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I2_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I2_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I2_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I2_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I2_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I2_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I2_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I2_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I2_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I2_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I2_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I2_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I2_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I2_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I2_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I3_A0
#define	PP_PIXSHADER_I3_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I3_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I3_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I3_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I3_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I3_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I3_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I3_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I3_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I3_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I3_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I3_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I3_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I3_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I3_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I3_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I4_A0
#define	PP_PIXSHADER_I4_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I4_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I4_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I4_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I4_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I4_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I4_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I4_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I4_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I4_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I4_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I4_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I4_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I4_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I4_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I4_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I5_A0
#define	PP_PIXSHADER_I5_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I5_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I5_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I5_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I5_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I5_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I5_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I5_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I5_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I5_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I5_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I5_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I5_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I5_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I5_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I5_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I6_A0
#define	PP_PIXSHADER_I6_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I6_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I6_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I6_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I6_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I6_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I6_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I6_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I6_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I6_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I6_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I6_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I6_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I6_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I6_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I6_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I7_A0
#define	PP_PIXSHADER_I7_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_PIXSHADER_I7_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_PIXSHADER_I7_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_PIXSHADER_I7_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_PIXSHADER_I7_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_PIXSHADER_I7_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_PIXSHADER_I7_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_PIXSHADER_I7_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_PIXSHADER_I7_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_PIXSHADER_I7_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_PIXSHADER_I7_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_PIXSHADER_I7_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_PIXSHADER_I7_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_PIXSHADER_I7_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_PIXSHADER_I7_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_PIXSHADER_I7_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_PIXSHADER_I0_A1
#define	PP_PIXSHADER_I0_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I0_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I0_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I0_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I0_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I0_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_PIXSHADER_I0_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I0_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I0_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_PIXSHADER_I1_A1
#define	PP_PIXSHADER_I1_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I1_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I1_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I1_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I1_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I1_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_PIXSHADER_I1_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I1_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I1_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_PIXSHADER_I2_A1
#define	PP_PIXSHADER_I2_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I2_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I2_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I2_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I2_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I2_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_PIXSHADER_I2_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I2_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I2_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_PIXSHADER_I3_A1
#define	PP_PIXSHADER_I3_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I3_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I3_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I3_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I3_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I3_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_PIXSHADER_I3_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I3_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I3_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_PIXSHADER_I4_A1
#define	PP_PIXSHADER_I4_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I4_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I4_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I4_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I4_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I4_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_PIXSHADER_I4_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I4_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I4_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_PIXSHADER_I5_A1
#define	PP_PIXSHADER_I5_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I5_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I5_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I5_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I5_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I5_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_PIXSHADER_I5_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I5_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I5_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_PIXSHADER_I6_A1
#define	PP_PIXSHADER_I6_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I6_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I6_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I6_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I6_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I6_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_PIXSHADER_I6_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I6_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I6_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_PIXSHADER_I7_A1
#define	PP_PIXSHADER_I7_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_PIXSHADER_I7_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_PIXSHADER_I7_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_PIXSHADER_I7_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_PIXSHADER_I7_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_PIXSHADER_I7_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_PIXSHADER_I7_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_PIXSHADER_I7_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_PIXSHADER_I7_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I0_C0
#define	PP_ADRSHADER_I0_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I0_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I0_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I0_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I0_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I0_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I0_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I0_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I0_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I0_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I0_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I0_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I0_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I0_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I0_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I0_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I1_C0
#define	PP_ADRSHADER_I1_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I1_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I1_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I1_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I1_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I1_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I1_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I1_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I1_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I1_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I1_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I1_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I1_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I1_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I1_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I1_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I2_C0
#define	PP_ADRSHADER_I2_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I2_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I2_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I2_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I2_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I2_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I2_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I2_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I2_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I2_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I2_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I2_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I2_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I2_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I2_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I2_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I3_C0
#define	PP_ADRSHADER_I3_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I3_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I3_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I3_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I3_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I3_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I3_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I3_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I3_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I3_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I3_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I3_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I3_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I3_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I3_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I3_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I4_C0
#define	PP_ADRSHADER_I4_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I4_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I4_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I4_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I4_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I4_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I4_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I4_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I4_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I4_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I4_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I4_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I4_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I4_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I4_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I4_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I5_C0
#define	PP_ADRSHADER_I5_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I5_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I5_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I5_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I5_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I5_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I5_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I5_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I5_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I5_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I5_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I5_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I5_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I5_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I5_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I5_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I6_C0
#define	PP_ADRSHADER_I6_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I6_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I6_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I6_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I6_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I6_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I6_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I6_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I6_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I6_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I6_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I6_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I6_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I6_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I6_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I6_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I7_C0
#define	PP_ADRSHADER_I7_C0__COLOR_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I7_C0__COLOR_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I7_C0__COLOR_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I7_C0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I7_C0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I7_C0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I7_C0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I7_C0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I7_C0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I7_C0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I7_C0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I7_C0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I7_C0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I7_C0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I7_C0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I7_C0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I0_C1
#define	PP_ADRSHADER_I0_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I0_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I0_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I0_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I0_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I0_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_ADRSHADER_I0_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_ADRSHADER_I0_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I0_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I0_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I1_C1
#define	PP_ADRSHADER_I1_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I1_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I1_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I1_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I1_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I1_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_ADRSHADER_I1_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_ADRSHADER_I1_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I1_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I1_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I2_C1
#define	PP_ADRSHADER_I2_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I2_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I2_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I2_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I2_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I2_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_ADRSHADER_I2_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_ADRSHADER_I2_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I2_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I2_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I3_C1
#define	PP_ADRSHADER_I3_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I3_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I3_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I3_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I3_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I3_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_ADRSHADER_I3_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_ADRSHADER_I3_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I3_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I3_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I4_C1
#define	PP_ADRSHADER_I4_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I4_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I4_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I4_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I4_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I4_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_ADRSHADER_I4_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_ADRSHADER_I4_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I4_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I4_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I5_C1
#define	PP_ADRSHADER_I5_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I5_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I5_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I5_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I5_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I5_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_ADRSHADER_I5_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_ADRSHADER_I5_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I5_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I5_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I6_C1
#define	PP_ADRSHADER_I6_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I6_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I6_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I6_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I6_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I6_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_ADRSHADER_I6_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_ADRSHADER_I6_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I6_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I6_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I7_C1
#define	PP_ADRSHADER_I7_C1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I7_C1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I7_C1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I7_C1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I7_C1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I7_C1__OUTPUT_MASK__SHIFT             0x00000014
#define	PP_ADRSHADER_I7_C1__OUTPUT_ROTATE__SHIFT           0x00000018
#define	PP_ADRSHADER_I7_C1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I7_C1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I7_C1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I0_A0
#define	PP_ADRSHADER_I0_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I0_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I0_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I0_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I0_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I0_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I0_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I0_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I0_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I0_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I0_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I0_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I0_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I0_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I0_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I0_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I1_A0
#define	PP_ADRSHADER_I1_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I1_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I1_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I1_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I1_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I1_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I1_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I1_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I1_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I1_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I1_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I1_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I1_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I1_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I1_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I1_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I2_A0
#define	PP_ADRSHADER_I2_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I2_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I2_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I2_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I2_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I2_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I2_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I2_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I2_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I2_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I2_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I2_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I2_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I2_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I2_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I2_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I3_A0
#define	PP_ADRSHADER_I3_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I3_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I3_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I3_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I3_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I3_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I3_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I3_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I3_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I3_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I3_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I3_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I3_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I3_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I3_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I3_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I4_A0
#define	PP_ADRSHADER_I4_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I4_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I4_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I4_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I4_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I4_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I4_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I4_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I4_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I4_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I4_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I4_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I4_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I4_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I4_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I4_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I5_A0
#define	PP_ADRSHADER_I5_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I5_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I5_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I5_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I5_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I5_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I5_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I5_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I5_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I5_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I5_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I5_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I5_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I5_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I5_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I5_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I6_A0
#define	PP_ADRSHADER_I6_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I6_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I6_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I6_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I6_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I6_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I6_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I6_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I6_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I6_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I6_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I6_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I6_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I6_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I6_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I6_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I7_A0
#define	PP_ADRSHADER_I7_A0__ALPHA_ARG_A__SHIFT             0x00000000
#define	PP_ADRSHADER_I7_A0__ALPHA_ARG_B__SHIFT             0x00000005
#define	PP_ADRSHADER_I7_A0__ALPHA_ARG_C__SHIFT             0x0000000a
#define	PP_ADRSHADER_I7_A0__COMP_ARG_A__SHIFT              0x00000010
#define	PP_ADRSHADER_I7_A0__BIAS_ARG_A__SHIFT              0x00000011
#define	PP_ADRSHADER_I7_A0__SCALE_ARG_A__SHIFT             0x00000012
#define	PP_ADRSHADER_I7_A0__NEG_ARG_A__SHIFT               0x00000013
#define	PP_ADRSHADER_I7_A0__COMP_ARG_B__SHIFT              0x00000014
#define	PP_ADRSHADER_I7_A0__BIAS_ARG_B__SHIFT              0x00000015
#define	PP_ADRSHADER_I7_A0__SCALE_ARG_B__SHIFT             0x00000016
#define	PP_ADRSHADER_I7_A0__NEG_ARG_B__SHIFT               0x00000017
#define	PP_ADRSHADER_I7_A0__COMP_ARG_C__SHIFT              0x00000018
#define	PP_ADRSHADER_I7_A0__BIAS_ARG_C__SHIFT              0x00000019
#define	PP_ADRSHADER_I7_A0__SCALE_ARG_C__SHIFT             0x0000001a
#define	PP_ADRSHADER_I7_A0__NEG_ARG_C__SHIFT               0x0000001b
#define	PP_ADRSHADER_I7_A0__BLEND_CTL__SHIFT               0x0000001c

// PP_ADRSHADER_I0_A1
#define	PP_ADRSHADER_I0_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I0_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I0_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I0_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I0_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I0_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_ADRSHADER_I0_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I0_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I0_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I1_A1
#define	PP_ADRSHADER_I1_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I1_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I1_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I1_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I1_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I1_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_ADRSHADER_I1_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I1_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I1_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I2_A1
#define	PP_ADRSHADER_I2_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I2_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I2_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I2_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I2_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I2_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_ADRSHADER_I2_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I2_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I2_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I3_A1
#define	PP_ADRSHADER_I3_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I3_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I3_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I3_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I3_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I3_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_ADRSHADER_I3_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I3_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I3_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I4_A1
#define	PP_ADRSHADER_I4_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I4_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I4_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I4_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I4_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I4_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_ADRSHADER_I4_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I4_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I4_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I5_A1
#define	PP_ADRSHADER_I5_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I5_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I5_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I5_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I5_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I5_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_ADRSHADER_I5_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I5_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I5_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I6_A1
#define	PP_ADRSHADER_I6_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I6_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I6_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I6_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I6_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I6_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_ADRSHADER_I6_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I6_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I6_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// PP_ADRSHADER_I7_A1
#define	PP_ADRSHADER_I7_A1__F0_SEL__SHIFT                  0x00000000
#define	PP_ADRSHADER_I7_A1__F1_SEL__SHIFT                  0x00000004
#define	PP_ADRSHADER_I7_A1__OUTPUT_SCALE__SHIFT            0x00000008
#define	PP_ADRSHADER_I7_A1__OUTPUT_CLAMP__SHIFT            0x0000000c
#define	PP_ADRSHADER_I7_A1__OUTPUT_SELECT__SHIFT           0x00000010
#define	PP_ADRSHADER_I7_A1__DOT_ALPHA__SHIFT               0x00000014
#define	PP_ADRSHADER_I7_A1__REPLICATE_ARG_A__SHIFT         0x0000001a
#define	PP_ADRSHADER_I7_A1__REPLICATE_ARG_B__SHIFT         0x0000001c
#define	PP_ADRSHADER_I7_A1__REPLICATE_ARG_C__SHIFT         0x0000001e

// RB2D_ROP
#define	RB2D_ROP__ROP__SHIFT                               0x00000010

// RB2D_CLRCMP_SRC
#define	RB2D_CLRCMP_SRC__CLRCMP_SRC__SHIFT                 0x00000000

// RB2D_CLRCMP_DST
#define	RB2D_CLRCMP_DST__CLRCMP_DST__SHIFT                 0x00000000

// RB2D_CLRCMP_FLIPE
#define	RB2D_CLRCMP_FLIPE__CLRCMP_FLIPE__SHIFT             0x00000000

// RB2D_CLRCMP_CNTL
#define	RB2D_CLRCMP_CNTL__FCN_SRC__SHIFT                   0x00000000
#define	RB2D_CLRCMP_CNTL__FCN_DST__SHIFT                   0x00000008
#define	RB2D_CLRCMP_CNTL__SRC__SHIFT                       0x00000018

// RB2D_CLRCMP_MSK
#define	RB2D_CLRCMP_MSK__CLRCMP_MSK__SHIFT                 0x00000000

// RB2D_WRITEMASK
#define	RB2D_WRITEMASK__WRITEMASK__SHIFT                   0x00000000

// RB2D_DATATYPE
#define	RB2D_DATATYPE__DP_DST_DATATYPE__SHIFT              0x00000000
#define	RB2D_DATATYPE__DP_BRUSH_DATATYPE__SHIFT            0x00000008

// RB2D_GUI_MASTER_CNTL
#define	RB2D_GUI_MASTER_CNTL__GMC_BRUSH_DATATYPE__SHIFT    0x00000004
#define	RB2D_GUI_MASTER_CNTL__GMC_DST_DATATYPE__SHIFT      0x00000008
#define	RB2D_GUI_MASTER_CNTL__GMC_ROP__SHIFT               0x00000010
#define	RB2D_GUI_MASTER_CNTL__GMC_CLR_CMP_FCN_DIS__SHIFT   0x0000001c
#define	RB2D_GUI_MASTER_CNTL__GMC_WR_MSK_DIS__SHIFT        0x0000001e

// RB2D_BRUSHDATA_0
#define	RB2D_BRUSHDATA_0__BRUSHDATA__SHIFT                 0x00000000

// RB2D_BRUSHDATA_1
#define	RB2D_BRUSHDATA_1__BRUSHDATA__SHIFT                 0x00000000

// RB2D_BRUSHDATA_2
#define	RB2D_BRUSHDATA_2__BRUSHDATA__SHIFT                 0x00000000
#define	RB2D_BRUSH_FRGD_CLR__BRUSHDATA__SHIFT              0x00000000

// RB2D_BRUSHDATA_3
#define	RB2D_BRUSHDATA_3__BRUSHDATA__SHIFT                 0x00000000
#define	RB2D_BRUSH_BKGD_CLR__BRUSHDATA__SHIFT              0x00000000

// RB2D_BRUSHDATA_4
#define	RB2D_BRUSHDATA_4__BRUSHDATA__SHIFT                 0x00000000

// RB2D_BRUSHDATA_5
#define	RB2D_BRUSHDATA_5__BRUSHDATA__SHIFT                 0x00000000

// RB2D_BRUSHDATA_6
#define	RB2D_BRUSHDATA_6__BRUSHDATA__SHIFT                 0x00000000

// RB2D_BRUSHDATA_7
#define	RB2D_BRUSHDATA_7__BRUSHDATA__SHIFT                 0x00000000

// RB2D_BRUSHDATA_8
#define	RB2D_BRUSHDATA_8__BRUSHDATA__SHIFT                 0x00000000

// RB2D_BRUSHDATA_9
#define	RB2D_BRUSHDATA_9__BRUSHDATA__SHIFT                 0x00000000

// RB2D_BRUSHDATA_10
#define	RB2D_BRUSHDATA_10__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_11
#define	RB2D_BRUSHDATA_11__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_12
#define	RB2D_BRUSHDATA_12__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_13
#define	RB2D_BRUSHDATA_13__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_14
#define	RB2D_BRUSHDATA_14__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_15
#define	RB2D_BRUSHDATA_15__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_16
#define	RB2D_BRUSHDATA_16__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_17
#define	RB2D_BRUSHDATA_17__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_18
#define	RB2D_BRUSHDATA_18__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_19
#define	RB2D_BRUSHDATA_19__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_20
#define	RB2D_BRUSHDATA_20__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_21
#define	RB2D_BRUSHDATA_21__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_22
#define	RB2D_BRUSHDATA_22__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_23
#define	RB2D_BRUSHDATA_23__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_24
#define	RB2D_BRUSHDATA_24__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_25
#define	RB2D_BRUSHDATA_25__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_26
#define	RB2D_BRUSHDATA_26__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_27
#define	RB2D_BRUSHDATA_27__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_28
#define	RB2D_BRUSHDATA_28__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_29
#define	RB2D_BRUSHDATA_29__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_30
#define	RB2D_BRUSHDATA_30__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_31
#define	RB2D_BRUSHDATA_31__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_32
#define	RB2D_BRUSHDATA_32__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_33
#define	RB2D_BRUSHDATA_33__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_34
#define	RB2D_BRUSHDATA_34__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_35
#define	RB2D_BRUSHDATA_35__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_36
#define	RB2D_BRUSHDATA_36__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_37
#define	RB2D_BRUSHDATA_37__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_38
#define	RB2D_BRUSHDATA_38__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_39
#define	RB2D_BRUSHDATA_39__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_40
#define	RB2D_BRUSHDATA_40__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_41
#define	RB2D_BRUSHDATA_41__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_42
#define	RB2D_BRUSHDATA_42__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_43
#define	RB2D_BRUSHDATA_43__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_44
#define	RB2D_BRUSHDATA_44__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_45
#define	RB2D_BRUSHDATA_45__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_46
#define	RB2D_BRUSHDATA_46__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_47
#define	RB2D_BRUSHDATA_47__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_48
#define	RB2D_BRUSHDATA_48__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_49
#define	RB2D_BRUSHDATA_49__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_50
#define	RB2D_BRUSHDATA_50__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_51
#define	RB2D_BRUSHDATA_51__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_52
#define	RB2D_BRUSHDATA_52__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_53
#define	RB2D_BRUSHDATA_53__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_54
#define	RB2D_BRUSHDATA_54__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_55
#define	RB2D_BRUSHDATA_55__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_56
#define	RB2D_BRUSHDATA_56__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_57
#define	RB2D_BRUSHDATA_57__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_58
#define	RB2D_BRUSHDATA_58__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_59
#define	RB2D_BRUSHDATA_59__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_60
#define	RB2D_BRUSHDATA_60__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_61
#define	RB2D_BRUSHDATA_61__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_62
#define	RB2D_BRUSHDATA_62__BRUSHDATA__SHIFT                0x00000000

// RB2D_BRUSHDATA_63
#define	RB2D_BRUSHDATA_63__BRUSHDATA__SHIFT                0x00000000

// RB2D_DSTCACHE_MODE
#define	RB2D_DSTCACHE_MODE__DC_BYPASS__SHIFT               0x00000000
#define	RB2D_DSTCACHE_MODE__DC_LINE_SIZE__SHIFT            0x00000002
#define	RB2D_DSTCACHE_MODE__DC_AUTOFLUSH_ENABLE__SHIFT     0x00000008
#define	RB2D_DSTCACHE_MODE__DC_AUTOFREE_ENABLE__SHIFT      0x0000000a
#define	RB2D_DSTCACHE_MODE__DC_FORCE_RMW__SHIFT            0x00000010
#define	RB2D_DSTCACHE_MODE__DC_DISABLE_RI_FILL__SHIFT      0x00000018
#define	RB2D_DSTCACHE_MODE__DC_DISABLE_RI_READ__SHIFT      0x00000019
#define	RB2D_DSTCACHE_MODE__DC_DISABLE_MASK_CHK__SHIFT     0x0000001a

// RB2D_DSTCACHE_CTLSTAT
#define	RB2D_DSTCACHE_CTLSTAT__DC_FLUSH__SHIFT             0x00000000
#define	RB2D_DSTCACHE_CTLSTAT__DC_FREE__SHIFT              0x00000002
#define	RB2D_DSTCACHE_CTLSTAT__DC_BUSY__SHIFT              0x0000001f

// RB2D_SRC_ENDIAN
#define	RB2D_SRC_ENDIAN__SRC_ENDIAN__SHIFT                 0x00000000

// RB2D_DST_ENDIAN
#define	RB2D_DST_ENDIAN__DST_ENDIAN__SHIFT                 0x00000000

// RB2D_PD1_DATA
#define	RB2D_PD1_DATA__PD1_DATA__SHIFT                     0x00000000

// RB2D_PD2_DATA
#define	RB2D_PD2_DATA__PD2_DATA__SHIFT                     0x00000000

// RB2D_WRITEBACK_DATA_LO
#define	RB2D_WRITEBACK_DATA_LO__WRITEBACK_DATA_LO__SHIFT   0x00000000

// RB2D_WRITEBACK_DATA_HI
#define	RB2D_WRITEBACK_DATA_HI__WRITEBACK_DATA_HI__SHIFT   0x00000000

// RB2D_WRITEBACK_ADDR
#define	RB2D_WRITEBACK_ADDR__WRITEBACK_ADDR__SHIFT         0x00000003

// RB3D_BLENDCOLOR
#define	RB3D_BLENDCOLOR__ARGB__SHIFT                       0x00000000

// RB3D_ABLENDCNTL
#define	RB3D_ABLENDCNTL__COMB_FCN__SHIFT                   0x0000000c
#define	RB3D_ABLENDCNTL__SRCBLEND__SHIFT                   0x00000010
#define	RB3D_ABLENDCNTL__DESTBLEND__SHIFT                  0x00000018

// RB3D_BLENDCNTL
#define	RB3D_BLENDCNTL__COMB_FCN_R2__SHIFT                 0x0000000c
#define	RB3D_BLENDCNTL__SRCBLEND__SHIFT                    0x00000010
#define	RB3D_BLENDCNTL__DESTBLEND__SHIFT                   0x00000018

// RB3D_DEPTHOFFSET
#define	RB3D_DEPTHOFFSET__DEPTHOFFSET_R2__SHIFT            0x0000000c

// RB3D_DEPTHPITCH
#define	RB3D_DEPTHPITCH__DEPTHPITCH_R2__SHIFT              0x00000005
#define	RB3D_DEPTHPITCH__DEPTHENDIAN__SHIFT                0x00000012

// RB3D_ZSTENCILCNTL
#define	RB3D_ZSTENCILCNTL__DEPTHFORMAT__SHIFT              0x00000000
#define	RB3D_ZSTENCILCNTL__ZFUNC__SHIFT                    0x00000004
#define	RB3D_ZSTENCILCNTL__STENCILFUNC__SHIFT              0x0000000c
#define	RB3D_ZSTENCILCNTL__STENCILFAIL__SHIFT              0x00000010
#define	RB3D_ZSTENCILCNTL__STENCILZPASS__SHIFT             0x00000014
#define	RB3D_ZSTENCILCNTL__STENCILZFAIL__SHIFT             0x00000018
#define	RB3D_ZSTENCILCNTL__FORCEZCLEAR__SHIFT              0x0000001b
#define	RB3D_ZSTENCILCNTL__ZCOMPRESSION__SHIFT             0x0000001c
#define	RB3D_ZSTENCILCNTL__FORCEZDIRTY__SHIFT              0x0000001d
#define	RB3D_ZSTENCILCNTL__ZWRITEENABLE__SHIFT             0x0000001e
#define	RB3D_ZSTENCILCNTL__ZDECOMPRESSION__SHIFT           0x0000001f

// RB3D_DEPTHCLEARVALUE
#define	RB3D_DEPTHCLEARVALUE__DEPTHCLEARVALUE__SHIFT       0x00000000

// RB3D_ZMASKOFFSET
#define	RB3D_ZMASKOFFSET__ZMASKOFFSET_R2__SHIFT            0x00000004

// RB3D_CNTL
#define	RB3D_CNTL__ALPHA_BLEND_ENABLE__SHIFT               0x00000000
#define	RB3D_CNTL__PLANE_MASK_ENABLE__SHIFT                0x00000001
#define	RB3D_CNTL__DITHER_ENABLE__SHIFT                    0x00000002
#define	RB3D_CNTL__ROUND_ENABLE__SHIFT                     0x00000003
#define	RB3D_CNTL__SCALE_DITHER__SHIFT                     0x00000004
#define	RB3D_CNTL__DITHER_INIT__SHIFT                      0x00000005
#define	RB3D_CNTL__ROP_ENABLE__SHIFT                       0x00000006
#define	RB3D_CNTL__STENCIL_ENABLE__SHIFT                   0x00000007
#define	RB3D_CNTL__Z_ENABLE__SHIFT                         0x00000008
#define	RB3D_CNTL__DEPTHXY_OFFSET_ENABLE__SHIFT            0x00000009
#define	RB3D_CNTL__COLORFORMAT__SHIFT                      0x0000000a
#define	RB3D_CNTL__CLRCMP_FLIPE_ENABLE__SHIFT              0x0000000e
#define	RB3D_CNTL__SEPARATE_ALPHA_ENABLE__SHIFT            0x00000010

// RB3D_COLOROFFSET
#define	RB3D_COLOROFFSET__COLOROFFSET__SHIFT               0x00000004

// RB3D_COLORPITCH
#define	RB3D_COLORPITCH__COLORPITCH__SHIFT                 0x00000003
#define	RB3D_COLORPITCH__COLORTILE__SHIFT                  0x00000010
#define	RB3D_COLORPITCH__COLORMICROTILE__SHIFT             0x00000011
#define	RB3D_COLORPITCH__COLORENDIAN__SHIFT                0x00000012

// RB3D_DEPTHXY_OFFSET
#define	RB3D_DEPTHXY_OFFSET__DEPTHX_OFFSET__SHIFT          0x00000000
#define	RB3D_DEPTHXY_OFFSET__DEPTHY_OFFSET__SHIFT          0x00000010

// RB3D_CLRCMP_FLIPE
#define	RB3D_CLRCMP_FLIPE__CLRCMP_FLIPE__SHIFT             0x00000000

// RB3D_CLRCMP_CLR
#define	RB3D_CLRCMP_CLR__CLRCMP_CLR__SHIFT                 0x00000000

// RB3D_CLRCMP_MSK
#define	RB3D_CLRCMP_MSK__CLRCMP_MSK__SHIFT                 0x00000000

// RB3D_ZMASK_WRINDEX
#define	RB3D_ZMASK_WRINDEX__ZMASK_WRINDEX_R2__SHIFT        0x00000004

// RB3D_ZMASK_DWORD
#define	RB3D_ZMASK_DWORD__ZMASKDWORD__SHIFT                0x00000000

// RB3D_ZMASK_RDINDEX
#define	RB3D_ZMASK_RDINDEX__ZMASK_RDINDEX_R2__SHIFT        0x00000004

// RB3D_STENCILREFMASK
#define	RB3D_STENCILREFMASK__STENCILREF__SHIFT             0x00000000
#define	RB3D_STENCILREFMASK__STENCILMASK__SHIFT            0x00000010
#define	RB3D_STENCILREFMASK__STENCILWRITEMASK__SHIFT       0x00000018

// RB3D_ROPCNTL
#define	RB3D_ROPCNTL__ROP__SHIFT                           0x00000008

// RB3D_PLANEMASK
#define	RB3D_PLANEMASK__PLANEMASK__SHIFT                   0x00000000

// RB3D_ZCACHE_MODE
#define	RB3D_ZCACHE_MODE__ZMASK_RAM_RM__SHIFT              0x00000008
#define	RB3D_ZCACHE_MODE__ZC_DISABLE_RI_FILL__SHIFT        0x00000018
#define	RB3D_ZCACHE_MODE__ZC_DISABLE_RI_READ__SHIFT        0x00000019
#define	RB3D_ZCACHE_MODE__ZC_DISABLE_RI_FLUSH__SHIFT       0x0000001b

// RB3D_ZCACHE_CTLSTAT
#define	RB3D_ZCACHE_CTLSTAT__ZC_FLUSH__SHIFT               0x00000000
#define	RB3D_ZCACHE_CTLSTAT__ZC_FREE__SHIFT                0x00000002
#define	RB3D_ZCACHE_CTLSTAT__ZC_BUSY__SHIFT                0x0000001f

// RB3D_DSTCACHE_MODE
#define	RB3D_DSTCACHE_MODE__DC_BYPASS__SHIFT               0x00000000
#define	RB3D_DSTCACHE_MODE__DC_LINE_SIZE__SHIFT            0x00000002
#define	RB3D_DSTCACHE_MODE__DC_AUTOFLUSH_ENABLE__SHIFT     0x00000008
#define	RB3D_DSTCACHE_MODE__DC_AUTOFREE_ENABLE__SHIFT      0x0000000a
#define	RB3D_DSTCACHE_MODE__DC_FORCE_RMW__SHIFT            0x00000010
#define	RB3D_DSTCACHE_MODE__DC_DISABLE_RI_FILL__SHIFT      0x00000018
#define	RB3D_DSTCACHE_MODE__DC_DISABLE_RI_READ__SHIFT      0x00000019
#define	RB3D_DSTCACHE_MODE__DC_DISABLE_MASK_CHK__SHIFT     0x0000001a

// RB3D_DSTCACHE_CTLSTAT
#define	RB3D_DSTCACHE_CTLSTAT__DC_FLUSH__SHIFT             0x00000000
#define	RB3D_DSTCACHE_CTLSTAT__DC_FREE__SHIFT              0x00000002
#define	RB3D_DSTCACHE_CTLSTAT__DC_BUSY__SHIFT              0x0000001f

// RB3D_PD0_DATA
#define	RB3D_PD0_DATA__DISABLE_RB__SHIFT                   0x00000000

// RB3D_DSTPERF_CNTL
#define	RB3D_DSTPERF_CNTL__PERFSEL0__SHIFT                 0x00000000
#define	RB3D_DSTPERF_CNTL__CLR_PERF0__SHIFT                0x00000004
#define	RB3D_DSTPERF_CNTL__EN_PERF0__SHIFT                 0x00000005
#define	RB3D_DSTPERF_CNTL__PERFSEL1__SHIFT                 0x00000008
#define	RB3D_DSTPERF_CNTL__CLR_PERF1__SHIFT                0x0000000c
#define	RB3D_DSTPERF_CNTL__EN_PERF1__SHIFT                 0x0000000d

// RB3D_PD1_DATA
#define	RB3D_PD1_DATA__RB3D_DBG_DISABLE_ZMASK_L0__SHIFT    0x00000000
#define	RB3D_PD1_DATA__PD1_DATA_R2__SHIFT                  0x00000001

// RB3D_PD1_ADDR
#define	RB3D_PD1_ADDR__PD1_ADDR__SHIFT                     0x00000000

// RB3D_PD2_DATA
#define	RB3D_PD2_DATA__PD2_DATA__SHIFT                     0x00000000

// RB3D_PD3_DATA
#define	RB3D_PD3_DATA__PD3_DATA__SHIFT                     0x00000000

// RB3D_WRITEBACK_DATA_LO
#define	RB3D_WRITEBACK_DATA_LO__WRITEBACK_DATA_LO__SHIFT   0x00000000

// RB3D_WRITEBACK_DATA_HI
#define	RB3D_WRITEBACK_DATA_HI__WRITEBACK_DATA_HI__SHIFT   0x00000000

// RB3D_WRITEBACK_ADDR
#define	RB3D_WRITEBACK_ADDR__WRITEBACK_ADDR__SHIFT         0x00000003

// RB3D_ZPERF_CNTL
#define	RB3D_ZPERF_CNTL__PERFSEL0__SHIFT                   0x00000000
#define	RB3D_ZPERF_CNTL__CLR_PERF0__SHIFT                  0x00000004
#define	RB3D_ZPERF_CNTL__EN_PERF0__SHIFT                   0x00000005
#define	RB3D_ZPERF_CNTL__PERFSEL1__SHIFT                   0x00000008
#define	RB3D_ZPERF_CNTL__CLR_PERF1__SHIFT                  0x0000000c
#define	RB3D_ZPERF_CNTL__EN_PERF1__SHIFT                   0x0000000d

// RB3D_ZPASS_DATA
#define	RB3D_ZPASS_DATA__ZPASS_DATA__SHIFT                 0x00000000

// RB3D_ZPASS_ADDR
#define	RB3D_ZPASS_ADDR__ZPASS_ADDR__SHIFT                 0x00000002

// RB3D_ZPERF_COUNT_0
#define	RB3D_ZPERF_COUNT_0__PERF_COUNT__SHIFT              0x00000000

// RB3D_ZPERF_COUNT_1
#define	RB3D_ZPERF_COUNT_1__PERF_COUNT__SHIFT              0x00000000

// RB3D_CRC_CNTL
#define	RB3D_CRC_CNTL__CRC_PP_FB_EN__SHIFT                 0x00000000
#define	RB3D_CRC_CNTL__CRC_PP_FB_CLEAR__SHIFT              0x00000001
#define	RB3D_CRC_CNTL__CRC_PP_FB_RDSEL__SHIFT              0x00000004
#define	RB3D_CRC_CNTL__CRC_RB0W_EN__SHIFT                  0x00000008
#define	RB3D_CRC_CNTL__CRC_RB0W_CLEAR__SHIFT               0x00000009
#define	RB3D_CRC_CNTL__CRC_RB0W_RDSEL__SHIFT               0x0000000c
#define	RB3D_CRC_CNTL__CRC_RB1W_EN__SHIFT                  0x00000010
#define	RB3D_CRC_CNTL__CRC_RB1W_CLEAR__SHIFT               0x00000011
#define	RB3D_CRC_CNTL__CRC_RB1W_RDSEL__SHIFT               0x00000014

// RB3D_CRC_PP_FB
#define	RB3D_CRC_PP_FB__CRC__SHIFT                         0x00000000

// RB3D_CRC_RB0W
#define	RB3D_CRC_RB0W__CRC__SHIFT                          0x00000000

// RB3D_CRC_RB1W
#define	RB3D_CRC_RB1W__CRC__SHIFT                          0x00000000

// DST_OFFSET
#define	DST_OFFSET__DST_OFFSET__SHIFT                      0x00000000

// DST_PITCH
#define	DST_PITCH__DST_PITCH__SHIFT                        0x00000000

// DST_TILE
#define	DST_TILE__DST_TILE__SHIFT                          0x00000000

// DST_PITCH_OFFSET
#define	DST_PITCH_OFFSET__DST_OFFSET__SHIFT                0x00000000
#define	DST_PITCH_OFFSET__DST_PITCH__SHIFT                 0x00000016
#define	DST_PITCH_OFFSET__DST_TILE__SHIFT                  0x0000001e

// DST_X
#define	DST_X__DST_X__SHIFT                                0x00000000

// DST_Y
#define	DST_Y__DST_Y__SHIFT                                0x00000000

// DST_X_Y
#define	DST_X_Y__DST_Y__SHIFT                              0x00000000
#define	DST_X_Y__DST_X__SHIFT                              0x00000010

// DST_Y_X
#define	DST_Y_X__DST_X__SHIFT                              0x00000000
#define	DST_Y_X__DST_Y__SHIFT                              0x00000010

// DST_WIDTH
#define	DST_WIDTH__DST_WIDTH__SHIFT                        0x00000000

// DST_HEIGHT
#define	DST_HEIGHT__DST_HEIGHT__SHIFT                      0x00000000

// DST_WIDTH_HEIGHT
#define	DST_WIDTH_HEIGHT__DST_HEIGHT__SHIFT                0x00000000
#define	DST_WIDTH_HEIGHT__DST_WIDTH__SHIFT                 0x00000010

// DST_HEIGHT_WIDTH
#define	DST_HEIGHT_WIDTH__DST_WIDTH__SHIFT                 0x00000000
#define	DST_HEIGHT_WIDTH__DST_HEIGHT__SHIFT                0x00000010

// DST_HEIGHT_WIDTH_8
#define	DST_HEIGHT_WIDTH_8__DST_WIDTH__SHIFT               0x00000010
#define	DST_HEIGHT_WIDTH_8__DST_HEIGHT__SHIFT              0x00000018

// DST_HEIGHT_Y
#define	DST_HEIGHT_Y__DST_Y__SHIFT                         0x00000000
#define	DST_HEIGHT_Y__DST_HEIGHT__SHIFT                    0x00000010

// DST_WIDTH_X
#define	DST_WIDTH_X__DST_X__SHIFT                          0x00000000
#define	DST_WIDTH_X__DST_WIDTH__SHIFT                      0x00000010

// DST_WIDTH_X_INCY
#define	DST_WIDTH_X_INCY__DST_X__SHIFT                     0x00000000
#define	DST_WIDTH_X_INCY__DST_WIDTH__SHIFT                 0x00000010

// DST_LINE_START
#define	DST_LINE_START__DST_START_X__SHIFT                 0x00000000
#define	DST_LINE_START__DST_START_Y__SHIFT                 0x00000010

// DST_LINE_END
#define	DST_LINE_END__DST_END_X__SHIFT                     0x00000000
#define	DST_LINE_END__DST_END_Y__SHIFT                     0x00000010

// DST_LINE_PATCOUNT
#define	DST_LINE_PATCOUNT__LINE_PATCOUNT__SHIFT            0x00000000
#define	DST_LINE_PATCOUNT__BRES_CNTL__SHIFT                0x00000008

// DP_DST_ENDIAN
#define	DP_DST_ENDIAN__DST_ENDIAN__SHIFT                   0x00000000

// BRUSH_Y_X
#define	BRUSH_Y_X__BRUSH_X__SHIFT                          0x00000000
#define	BRUSH_Y_X__BRUSH_Y__SHIFT                          0x00000008

// BRUSH_DATA0
#define	BRUSH_DATA0__BRUSH_DATA__SHIFT                     0x00000000

// BRUSH_DATA1
#define	BRUSH_DATA1__BRUSH_DATA__SHIFT                     0x00000000

// BRUSH_DATA2
#define	BRUSH_DATA2__BRUSH_DATA__SHIFT                     0x00000000

// BRUSH_DATA3
#define	BRUSH_DATA3__BRUSH_DATA__SHIFT                     0x00000000

// BRUSH_DATA4
#define	BRUSH_DATA4__BRUSH_DATA__SHIFT                     0x00000000

// BRUSH_DATA5
#define	BRUSH_DATA5__BRUSH_DATA__SHIFT                     0x00000000

// BRUSH_DATA6
#define	BRUSH_DATA6__BRUSH_DATA__SHIFT                     0x00000000

// BRUSH_DATA7
#define	BRUSH_DATA7__BRUSH_DATA__SHIFT                     0x00000000

// BRUSH_DATA8
#define	BRUSH_DATA8__BRUSH_DATA__SHIFT                     0x00000000

// BRUSH_DATA9
#define	BRUSH_DATA9__BRUSH_DATA__SHIFT                     0x00000000

// BRUSH_DATA10
#define	BRUSH_DATA10__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA11
#define	BRUSH_DATA11__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA12
#define	BRUSH_DATA12__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA13
#define	BRUSH_DATA13__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA14
#define	BRUSH_DATA14__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA15
#define	BRUSH_DATA15__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA16
#define	BRUSH_DATA16__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA17
#define	BRUSH_DATA17__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA18
#define	BRUSH_DATA18__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA19
#define	BRUSH_DATA19__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA20
#define	BRUSH_DATA20__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA21
#define	BRUSH_DATA21__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA22
#define	BRUSH_DATA22__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA23
#define	BRUSH_DATA23__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA24
#define	BRUSH_DATA24__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA25
#define	BRUSH_DATA25__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA26
#define	BRUSH_DATA26__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA27
#define	BRUSH_DATA27__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA28
#define	BRUSH_DATA28__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA29
#define	BRUSH_DATA29__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA30
#define	BRUSH_DATA30__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA31
#define	BRUSH_DATA31__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA32
#define	BRUSH_DATA32__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA33
#define	BRUSH_DATA33__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA34
#define	BRUSH_DATA34__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA35
#define	BRUSH_DATA35__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA36
#define	BRUSH_DATA36__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA37
#define	BRUSH_DATA37__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA38
#define	BRUSH_DATA38__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA39
#define	BRUSH_DATA39__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA40
#define	BRUSH_DATA40__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA41
#define	BRUSH_DATA41__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA42
#define	BRUSH_DATA42__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA43
#define	BRUSH_DATA43__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA44
#define	BRUSH_DATA44__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA45
#define	BRUSH_DATA45__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA46
#define	BRUSH_DATA46__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA47
#define	BRUSH_DATA47__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA48
#define	BRUSH_DATA48__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA49
#define	BRUSH_DATA49__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA50
#define	BRUSH_DATA50__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA51
#define	BRUSH_DATA51__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA52
#define	BRUSH_DATA52__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA53
#define	BRUSH_DATA53__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA54
#define	BRUSH_DATA54__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA55
#define	BRUSH_DATA55__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA56
#define	BRUSH_DATA56__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA57
#define	BRUSH_DATA57__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA58
#define	BRUSH_DATA58__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA59
#define	BRUSH_DATA59__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA60
#define	BRUSH_DATA60__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA61
#define	BRUSH_DATA61__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA62
#define	BRUSH_DATA62__BRUSH_DATA__SHIFT                    0x00000000

// BRUSH_DATA63
#define	BRUSH_DATA63__BRUSH_DATA__SHIFT                    0x00000000

// DP_BRUSH_FRGD_CLR
#define	DP_BRUSH_FRGD_CLR__DP_BRUSH_FRGD_CLR__SHIFT        0x00000000

// DP_BRUSH_BKGD_CLR
#define	DP_BRUSH_BKGD_CLR__DP_BRUSH_BKGD_CLR__SHIFT        0x00000000

// SRC_OFFSET
#define	SRC_OFFSET__SRC_OFFSET__SHIFT                      0x00000000

// SRC_PITCH
#define	SRC_PITCH__SRC_PITCH__SHIFT                        0x00000000

// SRC_TILE
#define	SRC_TILE__SRC_TILE__SHIFT                          0x00000000

// SRC_PITCH_OFFSET
#define	SRC_PITCH_OFFSET__SRC_OFFSET__SHIFT                0x00000000
#define	SRC_PITCH_OFFSET__SRC_PITCH__SHIFT                 0x00000016
#define	SRC_PITCH_OFFSET__SRC_TILE__SHIFT                  0x0000001e

// SRC_X
#define	SRC_X__SRC_X__SHIFT                                0x00000000

// SRC_Y
#define	SRC_Y__SRC_Y__SHIFT                                0x00000000

// SRC_X_Y
#define	SRC_X_Y__SRC_Y__SHIFT                              0x00000000
#define	SRC_X_Y__SRC_X__SHIFT                              0x00000010

// SRC_Y_X
#define	SRC_Y_X__SRC_X__SHIFT                              0x00000000
#define	SRC_Y_X__SRC_Y__SHIFT                              0x00000010

// SRC_CLUT_ADDRESS
#define	SRC_CLUT_ADDRESS__SRC_CLUT_ADDRESS__SHIFT          0x00000000

// SRC_CLUT_DATA
#define	SRC_CLUT_DATA__SRC_CLUT_DATA__SHIFT                0x00000000

// SRC_CLUT_DATA_RD
#define	SRC_CLUT_DATA_RD__SRC_CLUT_DATA__SHIFT             0x00000000

// HOST_DATA0
#define	HOST_DATA0__HOST_DATA__SHIFT                       0x00000000

// HOST_DATA1
#define	HOST_DATA1__HOST_DATA__SHIFT                       0x00000000

// HOST_DATA2
#define	HOST_DATA2__HOST_DATA__SHIFT                       0x00000000

// HOST_DATA3
#define	HOST_DATA3__HOST_DATA__SHIFT                       0x00000000

// HOST_DATA4
#define	HOST_DATA4__HOST_DATA__SHIFT                       0x00000000

// HOST_DATA5
#define	HOST_DATA5__HOST_DATA__SHIFT                       0x00000000

// HOST_DATA6
#define	HOST_DATA6__HOST_DATA__SHIFT                       0x00000000

// HOST_DATA7
#define	HOST_DATA7__HOST_DATA__SHIFT                       0x00000000

// HOST_DATA_LAST
#define	HOST_DATA_LAST__HOST_DATA_LAST__SHIFT              0x00000000

// DP_SRC_ENDIAN
#define	DP_SRC_ENDIAN__SRC_ENDIAN__SHIFT                   0x00000000

// DP_SRC_FRGD_CLR
#define	DP_SRC_FRGD_CLR__DP_SRC_FRGD_CLR__SHIFT            0x00000000

// DP_SRC_BKGD_CLR
#define	DP_SRC_BKGD_CLR__DP_SRC_BKGD_CLR__SHIFT            0x00000000

// SC_LEFT
#define	SC_LEFT__SC_LEFT__SHIFT                            0x00000000

// SC_RIGHT
#define	SC_RIGHT__SC_RIGHT__SHIFT                          0x00000000

// SC_TOP
#define	SC_TOP__SC_TOP__SHIFT                              0x00000000

// SC_BOTTOM
#define	SC_BOTTOM__SC_BOTTOM__SHIFT                        0x00000000

// SRC_SC_RIGHT
#define	SRC_SC_RIGHT__SC_RIGHT__SHIFT                      0x00000000

// SRC_SC_BOTTOM
#define	SRC_SC_BOTTOM__SC_BOTTOM__SHIFT                    0x00000000

// DP_CNTL
#define	DP_CNTL__DST_X_DIR__SHIFT                          0x00000000
#define	DP_CNTL__DST_Y_DIR__SHIFT                          0x00000001
#define	DP_CNTL__DST_TILE__SHIFT                           0x00000003

// DP_CNTL_XDIR_YDIR_YMAJOR
#define	DP_CNTL_XDIR_YDIR_YMAJOR__DST_Y_DIR__SHIFT         0x0000000f
#define	DP_CNTL_XDIR_YDIR_YMAJOR__DST_X_DIR__SHIFT         0x0000001f

// DP_DATATYPE
#define	DP_DATATYPE__DP_DST_DATATYPE__SHIFT                0x00000000
#define	DP_DATATYPE__DP_BRUSH_DATATYPE__SHIFT              0x00000008
#define	DP_DATATYPE__DP_SRC_DATATYPE__SHIFT                0x00000010
#define	DP_DATATYPE__DP_BYTE_PIX_ORDER__SHIFT              0x0000001e

// DP_MIX
#define	DP_MIX__DP_SRC_SOURCE__SHIFT                       0x00000008
#define	DP_MIX__DP_ROP3__SHIFT                             0x00000010

// DP_WRITE_MSK
#define	DP_WRITE_MSK__DP_WRITE_MSK__SHIFT                  0x00000000

// DP_XOP
#define	DP_XOP__XOP_A__SHIFT                               0x00000000
#define	DP_XOP__XOP_B__SHIFT                               0x00000008
#define	DP_XOP__XOP_C__SHIFT                               0x00000010
#define	DP_XOP__XOP_OP__SHIFT                              0x00000018

// CLR_CMP_CLR_SRC
#define	CLR_CMP_CLR_SRC__CLR_CMP_CLR_SRC__SHIFT            0x00000000

// CLR_CMP_CLR_DST
#define	CLR_CMP_CLR_DST__CLR_CMP_CLR_DST__SHIFT            0x00000000

// CLR_CMP_CNTL
#define	CLR_CMP_CNTL__CLR_CMP_FCN_SRC__SHIFT               0x00000000
#define	CLR_CMP_CNTL__CLR_CMP_FCN_DST__SHIFT               0x00000008
#define	CLR_CMP_CNTL__CLR_CMP_SRC__SHIFT                   0x00000018

// CLR_CMP_MSK
#define	CLR_CMP_MSK__CLR_CMP_MSK__SHIFT                    0x00000000

// DSTCACHE_MODE
#define	DSTCACHE_MODE__DSTCACHE_MODE__SHIFT                0x00000000

// DSTCACHE_CTLSTAT
#define	DSTCACHE_CTLSTAT__DSTCACHE_CTLSTAT__SHIFT          0x00000000

// PD2_DATA
#define	PD2_DATA__PD2_DATA__SHIFT                          0x00000000

// DEFAULT_PITCH_OFFSET
#define	DEFAULT_PITCH_OFFSET__DEFAULT_OFFSET__SHIFT        0x00000000
#define	DEFAULT_PITCH_OFFSET__DEFAULT_PITCH__SHIFT         0x00000016
#define	DEFAULT_PITCH_OFFSET__DEFAULT_TILE__SHIFT          0x0000001e

// DEFAULT_SC_BOTTOM_RIGHT
#define	DEFAULT_SC_BOTTOM_RIGHT__DEFAULT_SC_RIGHT__SHIFT   0x00000000
#define	DEFAULT_SC_BOTTOM_RIGHT__DEFAULT_SC_BOTTOM__SHIFT  0x00000010

// DEFAULT2_PITCH_OFFSET
#define	DEFAULT2_PITCH_OFFSET__DEFAULT_OFFSET__SHIFT       0x00000000
#define	DEFAULT2_PITCH_OFFSET__DEFAULT_PITCH__SHIFT        0x00000016
#define	DEFAULT2_PITCH_OFFSET__DEFAULT_TILE__SHIFT         0x0000001e

// DEFAULT2_SC_BOTTOM_RIGHT
#define	DEFAULT2_SC_BOTTOM_RIGHT__DEFAULT_SC_RIGHT__SHIFT  0x00000000
#define	DEFAULT2_SC_BOTTOM_RIGHT__DEFAULT_SC_BOTTOM__SHIFT 0x00000010

// DP_GUI_MASTER_CNTL
#define	DP_GUI_MASTER_CNTL__GMC_SRC_PITCH_OFFSET_CNTL__SHIFT 0x00000000
#define	DP_GUI_MASTER_CNTL__GMC_DST_PITCH_OFFSET_CNTL__SHIFT 0x00000001
#define	DP_GUI_MASTER_CNTL__GMC_SRC_CLIPPING__SHIFT        0x00000002
#define	DP_GUI_MASTER_CNTL__GMC_DST_CLIPPING__SHIFT        0x00000003
#define	DP_GUI_MASTER_CNTL__GMC_BRUSH_DATATYPE__SHIFT      0x00000004
#define	DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE__SHIFT        0x00000008
#define	DP_GUI_MASTER_CNTL__GMC_SRC_DATATYPE__SHIFT        0x0000000c
#define	DP_GUI_MASTER_CNTL__GMC_BYTE_PIX_ORDER__SHIFT      0x0000000e
#define	DP_GUI_MASTER_CNTL__GMC_DEFAULT_SEL__SHIFT         0x0000000f
#define	DP_GUI_MASTER_CNTL__GMC_ROP3__SHIFT                0x00000010
#define	DP_GUI_MASTER_CNTL__GMC_DP_SRC_SOURCE__SHIFT       0x00000018
#define	DP_GUI_MASTER_CNTL__GMC_SRC_DATATYPE2__SHIFT       0x0000001b
#define	DP_GUI_MASTER_CNTL__GMC_CLR_CMP_FCN_DIS__SHIFT     0x0000001c
#define	DP_GUI_MASTER_CNTL__GMC_WR_MSK_DIS__SHIFT          0x0000001e

// SC_TOP_LEFT
#define	SC_TOP_LEFT__SC_LEFT__SHIFT                        0x00000000
#define	SC_TOP_LEFT__SC_TOP__SHIFT                         0x00000010

// SC_BOTTOM_RIGHT
#define	SC_BOTTOM_RIGHT__SC_RIGHT__SHIFT                   0x00000000
#define	SC_BOTTOM_RIGHT__SC_BOTTOM__SHIFT                  0x00000010

// SRC_SC_BOTTOM_RIGHT
#define	SRC_SC_BOTTOM_RIGHT__SC_RIGHT__SHIFT               0x00000000
#define	SRC_SC_BOTTOM_RIGHT__SC_BOTTOM__SHIFT              0x00000010

// DEBUG0

// DEBUG1

// DEBUG2

// DEBUG3

// DEBUG4

// DEBUG5

// DEBUG6

// DEBUG7

// DEBUG8

// DEBUG9

// DEBUG10

// DEBUG11

// DEBUG12

// DEBUG13

// DEBUG14

// DEBUG15

// BIOS_0_SCRATCH
#define	BIOS_0_SCRATCH__BIOS_SCRATCH__SHIFT                0x00000000

// BIOS_1_SCRATCH
#define	BIOS_1_SCRATCH__BIOS_SCRATCH__SHIFT                0x00000000

// BIOS_2_SCRATCH
#define	BIOS_2_SCRATCH__BIOS_SCRATCH__SHIFT                0x00000000

// BIOS_3_SCRATCH
#define	BIOS_3_SCRATCH__BIOS_SCRATCH__SHIFT                0x00000000

// BIOS_4_SCRATCH
#define	BIOS_4_SCRATCH__BIOS_SCRATCH__SHIFT                0x00000000

// BIOS_5_SCRATCH
#define	BIOS_5_SCRATCH__BIOS_SCRATCH__SHIFT                0x00000000

// BIOS_6_SCRATCH
#define	BIOS_6_SCRATCH__BIOS_SCRATCH__SHIFT                0x00000000

// BIOS_7_SCRATCH
#define	BIOS_7_SCRATCH__BIOS_SCRATCH__SHIFT                0x00000000

// CONFIG_XSTRAP
#define	CONFIG_XSTRAP__VGA_DISABLE__SHIFT                  0x00000000
#define	CONFIG_XSTRAP__ENINTB__SHIFT                       0x00000003
#define	CONFIG_XSTRAP__AGPSKEW__SHIFT                      0x00000006
#define	CONFIG_XSTRAP__X1CLK_SKEW__SHIFT                   0x00000008
#define	CONFIG_XSTRAP__ID_DISABLE__SHIFT                   0x0000000e
#define	CONFIG_XSTRAP__AP_SIZE__SHIFT                      0x00000010
#define	CONFIG_XSTRAP__ROMIDCFG__SHIFT                     0x00000014
#define	CONFIG_XSTRAP__BUSCFG__SHIFT                       0x00000018

// TEST_DEBUG_CNTL
#define	TEST_DEBUG_CNTL__TEST_DEBUG_OUT_EN__SHIFT          0x00000000
#define	TEST_DEBUG_CNTL__TEST_DEBUG_IN_EN__SHIFT           0x00000001
#define	TEST_DEBUG_CNTL__TEST_IDDQ_EN__SHIFT               0x00000002
#define	TEST_DEBUG_CNTL__TEST_BLOCK_SEL__SHIFT             0x00000008
#define	TEST_DEBUG_CNTL__TEST_ENABLE__SHIFT                0x0000000f
#define	TEST_DEBUG_CNTL__TEST_DELAY_IN__SHIFT              0x00000010

// TEST_DEBUG_MUX
#define	TEST_DEBUG_MUX__TEST_DEBUG_SEL__SHIFT              0x00000000
#define	TEST_DEBUG_MUX__TEST_CLK0__SHIFT                   0x00000008
#define	TEST_DEBUG_MUX__TEST_CLK0_INV__SHIFT               0x0000000f
#define	TEST_DEBUG_MUX__TEST_CLK1__SHIFT                   0x00000010
#define	TEST_DEBUG_MUX__TEST_CLK1_INV__SHIFT               0x00000017

// TEST_DEBUG_OUT
#define	TEST_DEBUG_OUT__TEST_DEBUG_OUTR_U1__SHIFT          0x00000000

// VIDEOMUX_CNTL
#define	VIDEOMUX_CNTL__ROM_CLK_DIVIDE__SHIFT               0x00000010
#define	VIDEOMUX_CNTL__STR_ROMCLK__SHIFT                   0x00000015
#define	VIDEOMUX_CNTL__VIP_INTERNAL_DEBUG_SEL__SHIFT       0x00000016
#define	VIDEOMUX_CNTL__GEYSERVILLE_SENSE__SHIFT            0x00000019
#define	VIDEOMUX_CNTL__GEYSERVILLE_INT_POL__SHIFT          0x0000001a

// VIPPAD_STRENGTH
#define	VIPPAD_STRENGTH__ZV_LCDDATA_STRENGTH__SHIFT        0x00000000
#define	VIPPAD_STRENGTH__ZV_LCDCNTL_STRENGTH__SHIFT        0x00000008
#define	VIPPAD_STRENGTH__GPIO_STRENGTH__SHIFT              0x0000000c

// GPIOPAD_MASK
#define	GPIOPAD_MASK__GPIO_MASK__SHIFT                     0x00000000

// GPIOPAD_A
#define	GPIOPAD_A__GPIO_A__SHIFT                           0x00000000

// GPIOPAD_EN
#define	GPIOPAD_EN__GPIO_EN__SHIFT                         0x00000000

// GPIOPAD_Y
#define	GPIOPAD_Y__GPIO_Y__SHIFT                           0x00000000

// ZV_LCDPAD_MASK
#define	ZV_LCDPAD_MASK__ZV_LCDDATA_MASK_U1__SHIFT          0x00000000
#define	ZV_LCDPAD_MASK__ZV_LCDCNTL_MASK__SHIFT             0x00000018

// ZV_LCDPAD_A
#define	ZV_LCDPAD_A__ZV_LCDDATA_A_U1__SHIFT                0x00000000
#define	ZV_LCDPAD_A__ZV_LCDCNTL_A__SHIFT                   0x00000018

// ZV_LCDPAD_EN
#define	ZV_LCDPAD_EN__ZV_LCDDATA_EN_U1__SHIFT              0x00000000
#define	ZV_LCDPAD_EN__ZV_LCDCNTL_EN__SHIFT                 0x00000018

// ZV_LCDPAD_Y
#define	ZV_LCDPAD_Y__ZV_LCDDATA_Y_U1__SHIFT                0x00000000
#define	ZV_LCDPAD_Y__ZV_LCDCNTL_Y__SHIFT                   0x00000018

// EXTERN_TRIG_CNTL
#define	EXTERN_TRIG_CNTL__EXTERN_TRIG_CLR__SHIFT           0x00000000
#define	EXTERN_TRIG_CNTL__EXTERN_TRIG_READ__SHIFT          0x00000001

// STRAP_CNTL_REG
#define	STRAP_CNTL_REG__PANEL_ID__SHIFT                    0x00000000
#define	STRAP_CNTL_REG__MULTIMEDIA__SHIFT                  0x00000005

// SEPROM_CNTL1
#define	SEPROM_CNTL1__WRITE_ENABLE__SHIFT                  0x00000000
#define	SEPROM_CNTL1__WRITE_DISABLE__SHIFT                 0x00000001
#define	SEPROM_CNTL1__READ_CONFIG__SHIFT                   0x00000002
#define	SEPROM_CNTL1__WRITE_CONFIG__SHIFT                  0x00000003
#define	SEPROM_CNTL1__READ_STATUS__SHIFT                   0x00000004
#define	SEPROM_CNTL1__SECT_TO_SRAM__SHIFT                  0x00000005
#define	SEPROM_CNTL1__READY_BUSY__SHIFT                    0x00000007
#define	SEPROM_CNTL1__SEPROM_BUSY__SHIFT                   0x00000008
#define	SEPROM_CNTL1__BCNT_OVER_WTE_EN__SHIFT              0x00000009
#define	SEPROM_CNTL1__RB_MASKB__SHIFT                      0x0000000a
#define	SEPROM_CNTL1__SOFT_RESET__SHIFT                    0x0000000b
#define	SEPROM_CNTL1__STATE_IDLEb__SHIFT                   0x0000000c
#define	SEPROM_CNTL1__BYTE_CNT__SHIFT                      0x00000010
#define	SEPROM_CNTL1__SCK_PRESCALE__SHIFT                  0x00000018

// SEPROM_CNTL2
#define	SEPROM_CNTL2__WAIT_CYCLE__SHIFT                    0x00000000
#define	SEPROM_CNTL2__AUTO_ADDR_SAMPLE__SHIFT              0x00000008
#define	SEPROM_CNTL2__SEC_COMMAND__SHIFT                   0x00000010

// VIP_HW_DEBUG
#define	VIP_HW_DEBUG__VIP_HW_6_DEBUG__SHIFT                0x00000006
#define	VIP_HW_DEBUG__VIP_HW_7_DEBUG__SHIFT                0x00000007
#define	VIP_HW_DEBUG__VIP_HW_8_DEBUG__SHIFT                0x00000008
#define	VIP_HW_DEBUG__VIP_HW_C_DEBUG__SHIFT                0x0000000c
#define	VIP_HW_DEBUG__VIP_HW_D_DEBUG__SHIFT                0x0000000d
#define	VIP_HW_DEBUG__VIP_HW_E_DEBUG__SHIFT                0x0000000e
#define	VIP_HW_DEBUG__VIP_HW_F_DEBUG__SHIFT                0x0000000f

// MEDIA_0_SCRATCH
#define	MEDIA_0_SCRATCH__MEDIA_0_SCRATCH__SHIFT            0x00000000

// MEDIA_1_SCRATCH
#define	MEDIA_1_SCRATCH__MEDIA_1_SCRACH__SHIFT             0x00000000

// CLK_PIN_CNTL
#define	CLK_PIN_CNTL__DONT_USE_XTALIN__SHIFT               0x00000004
#define	CLK_PIN_CNTL__SLOW_CLOCK_SOURCE__SHIFT             0x00000005
#define	CLK_PIN_CNTL__CG_CLK_TO_OUTPIN__SHIFT              0x0000000b
#define	CLK_PIN_CNTL__CG_COUNT_UP_TO_OUTPIN__SHIFT         0x0000000c
#define	CLK_PIN_CNTL__ACCESS_REGS_IN_SUSPEND__SHIFT        0x0000000d
#define	CLK_PIN_CNTL__CG_SPARE__SHIFT                      0x0000000e
#define	CLK_PIN_CNTL__SCLK_DYN_START_CNTL__SHIFT           0x0000000f
#define	CLK_PIN_CNTL__CP_CLK_RUNNING__SHIFT                0x00000010
#define	CLK_PIN_CNTL__CG_SPARE_RD__SHIFT                   0x00000011
#define	CLK_PIN_CNTL__PWRSEQ_DELAY__SHIFT                  0x00000018

// PPLL_CNTL
#define	PPLL_CNTL__PPLL_RESET__SHIFT                       0x00000000
#define	PPLL_CNTL__PPLL_SLEEP__SHIFT                       0x00000001
#define	PPLL_CNTL__PPLL_TST_EN__SHIFT                      0x00000002
#define	PPLL_CNTL__PPLL_REFCLK_SEL__SHIFT                  0x00000004
#define	PPLL_CNTL__PPLL_FBCLK_SEL__SHIFT                   0x00000005
#define	PPLL_CNTL__PPLL_TCPOFF__SHIFT                      0x00000006
#define	PPLL_CNTL__PPLL_TVCOMAX__SHIFT                     0x00000007
#define	PPLL_CNTL__PPLL_PCP__SHIFT                         0x00000008
#define	PPLL_CNTL__PPLL_PVG__SHIFT                         0x0000000b
#define	PPLL_CNTL__PPLL_PDC__SHIFT                         0x0000000e
#define	PPLL_CNTL__PPLL_ATOMIC_UPDATE_EN__SHIFT            0x00000010
#define	PPLL_CNTL__PPLL_VGA_ATOMIC_UPDATE_EN__SHIFT        0x00000011
#define	PPLL_CNTL__PPLL_ATOMIC_UPDATE_SYNC__SHIFT          0x00000012
#define	PPLL_CNTL__PPLL_DISABLE_AUTO_RESET__SHIFT          0x00000013

// PPLL_REF_DIV
#define	PPLL_REF_DIV__PPLL_REF_DIV__SHIFT                  0x00000000
#define	PPLL_REF_DIV__PPLL_ATOMIC_UPDATE_W__SHIFT          0x0000000f
#define	PPLL_REF_DIV__PPLL_ATOMIC_UPDATE_R__SHIFT          0x0000000f
#define	PPLL_REF_DIV__PPLL_REF_DIV_SRC__SHIFT              0x00000010
#define	PPLL_REF_DIV__PPLL_REF_DIV_ACC__SHIFT              0x00000012

// SPLL_CNTL
#define	SPLL_CNTL__SPLL_SLEEP__SHIFT                       0x00000000
#define	SPLL_CNTL__SPLL_RESET__SHIFT                       0x00000001
#define	SPLL_CNTL__SPLL_TST_EN__SHIFT                      0x00000002
#define	SPLL_CNTL__SPLL_REFCLK_SEL__SHIFT                  0x00000004
#define	SPLL_CNTL__SPLL_FBCLK_SEL__SHIFT                   0x00000005
#define	SPLL_CNTL__SPLL_TCPOFF__SHIFT                      0x00000006
#define	SPLL_CNTL__SPLL_TVCOMAX__SHIFT                     0x00000007
#define	SPLL_CNTL__SPLL_PCP__SHIFT                         0x00000008
#define	SPLL_CNTL__SPLL_PVG__SHIFT                         0x0000000b
#define	SPLL_CNTL__SPLL_PDC__SHIFT                         0x0000000e
#define	SPLL_CNTL__SPLL_X1_CLK_SKEW__SHIFT                 0x00000010
#define	SPLL_CNTL__SPLL_X2_CLK_SKEW__SHIFT                 0x00000014
#define	SPLL_CNTL__SPLL_MODE__SHIFT                        0x00000018
#define	SPLL_CNTL__MYCLK_SOURCED_FROM_SPLL_SEL__SHIFT      0x0000001c
#define	SPLL_CNTL__ENABLE_MYCLK_FROM_SPLL__SHIFT           0x0000001e

// SPLL_AUX_CNTL
#define	SPLL_AUX_CNTL__SPLL_PDC_C__SHIFT                   0x00000000
#define	SPLL_AUX_CNTL__SPLL_CKINVA__SHIFT                  0x00000002
#define	SPLL_AUX_CNTL__SPLL_CKINVC__SHIFT                  0x00000003
#define	SPLL_AUX_CNTL__SPLL_X3_CLK_SKEW__SHIFT             0x00000004
#define	SPLL_AUX_CNTL__SPLL_MODEC__SHIFT                   0x00000007
#define	SPLL_AUX_CNTL__ATSPEED_PAD_IN_EN__SHIFT            0x0000000b
#define	SPLL_AUX_CNTL__TRANSIT_DONE_LENGTH__SHIFT          0x0000000c
#define	SPLL_AUX_CNTL__ATSPEED_ENABLE__SHIFT               0x0000000d
#define	SPLL_AUX_CNTL__SPLL_REFCLK_SRC_SEL__SHIFT          0x0000000e
#define	SPLL_AUX_CNTL__ATSPEED_SPLL_CLOCK_COUNT__SHIFT     0x00000010

// SCLK_CNTL
#define	SCLK_CNTL__SCLK_SRC_SEL__SHIFT                     0x00000000
#define	SCLK_CNTL__CP_MAX_DYN_STOP_LAT__SHIFT              0x00000003
#define	SCLK_CNTL__HDP_MAX_DYN_STOP_LAT__SHIFT             0x00000004
#define	SCLK_CNTL__TV_MAX_DYN_STOP_LAT__SHIFT              0x00000005
#define	SCLK_CNTL__E2_MAX_DYN_STOP_LAT__SHIFT              0x00000006
#define	SCLK_CNTL__SE_MAX_DYN_STOP_LAT__SHIFT              0x00000007
#define	SCLK_CNTL__IDCT_MAX_DYN_STOP_LAT__SHIFT            0x00000008
#define	SCLK_CNTL__VIP_MAX_DYN_STOP_LAT__SHIFT             0x00000009
#define	SCLK_CNTL__RE_MAX_DYN_STOP_LAT__SHIFT              0x0000000a
#define	SCLK_CNTL__PB_MAX_DYN_STOP_LAT__SHIFT              0x0000000b
#define	SCLK_CNTL__TAM_MAX_DYN_STOP_LAT__SHIFT             0x0000000c
#define	SCLK_CNTL__TDM_MAX_DYN_STOP_LAT__SHIFT             0x0000000d
#define	SCLK_CNTL__RB_MAX_DYN_STOP_LAT__SHIFT              0x0000000e
#define	SCLK_CNTL__FORCE_DISP2__SHIFT                      0x0000000f
#define	SCLK_CNTL__FORCE_CP__SHIFT                         0x00000010
#define	SCLK_CNTL__FORCE_HDP__SHIFT                        0x00000011
#define	SCLK_CNTL__FORCE_DISP1__SHIFT                      0x00000012
#define	SCLK_CNTL__FORCE_TOP__SHIFT                        0x00000013
#define	SCLK_CNTL__FORCE_E2__SHIFT                         0x00000014
#define	SCLK_CNTL__FORCE_SE__SHIFT                         0x00000015
#define	SCLK_CNTL__FORCE_IDCT__SHIFT                       0x00000016
#define	SCLK_CNTL__FORCE_VIP__SHIFT                        0x00000017
#define	SCLK_CNTL__FORCE_RE__SHIFT                         0x00000018
#define	SCLK_CNTL__FORCE_PB__SHIFT                         0x00000019
#define	SCLK_CNTL__FORCE_TAM__SHIFT                        0x0000001a
#define	SCLK_CNTL__FORCE_TDM__SHIFT                        0x0000001b
#define	SCLK_CNTL__FORCE_RB__SHIFT                         0x0000001c
#define	SCLK_CNTL__FORCE_TV_SCLK__SHIFT                    0x0000001d
#define	SCLK_CNTL__FORCE_SUBPIC__SHIFT                     0x0000001e
#define	SCLK_CNTL__FORCE_OV0__SHIFT                        0x0000001f

// GFX_MPLL_FREQ_CONTROL
#define	GFX_MPLL_FREQ_CONTROL__MPLL_PM_EN__SHIFT           0x00000000
#define	GFX_MPLL_FREQ_CONTROL__MPLL_FREQ_SEL__SHIFT        0x00000001
#define	GFX_MPLL_FREQ_CONTROL__DISP_BLANK_CNTL__SHIFT      0x00000002
#define	GFX_MPLL_FREQ_CONTROL__DISP_BLANK_VAL__SHIFT       0x00000004
#define	GFX_MPLL_FREQ_CONTROL__MEM_SELF_REFRESH_ONLY__SHIFT 0x00000005
#define	GFX_MPLL_FREQ_CONTROL__PM_SWITCHMCLK_BUSY__SHIFT   0x00000006
#define	GFX_MPLL_FREQ_CONTROL__PM_FREQ_CNTL_RESET__SHIFT   0x00000007
#define	GFX_MPLL_FREQ_CONTROL__PM_MPLL_DELTA_FRACTION__SHIFT 0x00000008
#define	GFX_MPLL_FREQ_CONTROL__PM_MPLL_DELTA_INTEGER__SHIFT 0x0000000b
#define	GFX_MPLL_FREQ_CONTROL__PM_MPLL_PVG__SHIFT          0x00000011
#define	GFX_MPLL_FREQ_CONTROL__PM_MPLL_STEP_SIZE__SHIFT    0x00000014
#define	GFX_MPLL_FREQ_CONTROL__PM_MPLL_DELAY__SHIFT        0x00000016
#define	GFX_MPLL_FREQ_CONTROL__CG_SPARE_RW_0__SHIFT        0x0000001c
#define	GFX_MPLL_FREQ_CONTROL__PM_MPLL_SLOWMCLK__SHIFT     0x0000001d
#define	GFX_MPLL_FREQ_CONTROL__CG_SPARE_RW_1__SHIFT        0x0000001e

// GFX_MPLL_SEQ_CONTROL
#define	GFX_MPLL_SEQ_CONTROL__MPLL_RESET_PULSE_WIDTH__SHIFT 0x00000000
#define	GFX_MPLL_SEQ_CONTROL__MDLL_RESET_PULSE_WIDTH__SHIFT 0x00000005
#define	GFX_MPLL_SEQ_CONTROL__MPLL_LOCK_TIME__SHIFT        0x00000008
#define	GFX_MPLL_SEQ_CONTROL__MDLL_LOCK_TIME__SHIFT        0x00000014
#define	GFX_MPLL_SEQ_CONTROL__CG_SPARE_R_0__SHIFT          0x0000001b

// GFX_MPLL_DIV_CONTROL
#define	GFX_MPLL_DIV_CONTROL__PM_MPLL_REF_DIV__SHIFT       0x00000000
#define	GFX_MPLL_DIV_CONTROL__CG_SPARE_RW_2__SHIFT         0x0000000a
#define	GFX_MPLL_DIV_CONTROL__PM_MPLL_FB_DIV_FRACTION__SHIFT 0x0000000c
#define	GFX_MPLL_DIV_CONTROL__CG_SPARE_RW_3__SHIFT         0x0000000f
#define	GFX_MPLL_DIV_CONTROL__PM_MPLL_FB_DIV__SHIFT        0x00000010
#define	GFX_MPLL_DIV_CONTROL__CG_SPARE_R_1__SHIFT          0x0000001b
#define	GFX_MPLL_DIV_CONTROL__PM_MPLL_POST_DIV__SHIFT      0x0000001c
#define	GFX_MPLL_DIV_CONTROL__CG_SPARE_RW_4__SHIFT         0x0000001f

// PWRMAN_MISC
#define	PWRMAN_MISC__EN_MC_IDLE_COND__SHIFT                0x00000000
#define	PWRMAN_MISC__MC_IDLE_LAT__SHIFT                    0x00000001
#define	PWRMAN_MISC__EN_STOP_IMPORT_CLKS_IN_SUSPEND__SHIFT 0x00000003
#define	PWRMAN_MISC__NB_TESTCLK_SEL__SHIFT                 0x00000010
#define	PWRMAN_MISC__CG_NB_TESTCLK_SEL__SHIFT              0x00000013
#define	PWRMAN_MISC__CG_SPARE_B_A5__SHIFT                  0x00000014
#define	PWRMAN_MISC__CG_SPARE_RD_B__SHIFT                  0x0000001a

// CG_PERF_COUNT0
#define	CG_PERF_COUNT0__PERF_COUNT0_L__SHIFT               0x00000000

// CG_PERF_COUNT1
#define	CG_PERF_COUNT1__PERF_COUNT1_L__SHIFT               0x00000000

// CG_PERF_COUNT_H
#define	CG_PERF_COUNT_H__PERF_COUNT0_EVENT_SEL__SHIFT      0x00000000
#define	CG_PERF_COUNT_H__PERF_COUNT1_EVENT_SEL__SHIFT      0x00000008
#define	CG_PERF_COUNT_H__PERF_COUNT0_H__SHIFT              0x00000010
#define	CG_PERF_COUNT_H__PERF_COUNT1_H__SHIFT              0x00000018

// CG_PERF_CNTL
#define	CG_PERF_CNTL__PERF_COUNT_USE_NB_GLOBAL__SHIFT      0x00000000
#define	CG_PERF_CNTL__PERF_COUNT_SHADOW_WR__SHIFT          0x00000001
#define	CG_PERF_CNTL__PERF_COUNT0_EN__SHIFT                0x00000002
#define	CG_PERF_CNTL__PERF_COUNT1_EN__SHIFT                0x00000003
#define	CG_PERF_CNTL__PERF_COUNT0_CLR__SHIFT               0x00000004
#define	CG_PERF_CNTL__PERF_COUNT1_CLR__SHIFT               0x00000005

// TV_PLL_FINE_CNTL
#define	TV_PLL_FINE_CNTL__TV_M1__SHIFT                     0x00000000
#define	TV_PLL_FINE_CNTL__TV_N1__SHIFT                     0x0000000b
#define	TV_PLL_FINE_CNTL__TV_DIVIDER_SEL__SHIFT            0x00000016
#define	TV_PLL_FINE_CNTL__TV_MNFLIP_REQ__SHIFT             0x00000017
#define	TV_PLL_FINE_CNTL__TV_MNFLIP_DONE__SHIFT            0x00000018
#define	TV_PLL_FINE_CNTL__TV_SLIP_REQ__SHIFT               0x00000019
#define	TV_PLL_FINE_CNTL__TV_SLIP_DONE__SHIFT              0x0000001a
#define	TV_PLL_FINE_CNTL__TV_MNFLIP_EN__SHIFT              0x0000001b
#define	TV_PLL_FINE_CNTL__TV_SLIP_COUNT__SHIFT             0x0000001c

// TV_PLL_CNTL
#define	TV_PLL_CNTL__TV_M0_LO__SHIFT                       0x00000000
#define	TV_PLL_CNTL__TV_N0_LO__SHIFT                       0x00000008
#define	TV_PLL_CNTL__TV_M0_HI__SHIFT                       0x00000012
#define	TV_PLL_CNTL__TV_N0_HI__SHIFT                       0x00000015
#define	TV_PLL_CNTL__TV_SLIP_EN__SHIFT                     0x00000017
#define	TV_PLL_CNTL__TV_P__SHIFT                           0x00000018
#define	TV_PLL_CNTL__TV_DTO_EN__SHIFT                      0x0000001c
#define	TV_PLL_CNTL__TV_DTO_TYPE__SHIFT                    0x0000001d
#define	TV_PLL_CNTL__TV_REF_CLK_SEL__SHIFT                 0x0000001e

// TV_PLL_CNTL1
#define	TV_PLL_CNTL1__TVPLL_RESET__SHIFT                   0x00000001
#define	TV_PLL_CNTL1__TVPLL_SLEEP__SHIFT                   0x00000003
#define	TV_PLL_CNTL1__TVPLL_REFCLK_SEL__SHIFT              0x00000004
#define	TV_PLL_CNTL1__TVPLL_FBCLK_SEL__SHIFT               0x00000005
#define	TV_PLL_CNTL1__TVPLL_TCPOFF__SHIFT                  0x00000006
#define	TV_PLL_CNTL1__TVPLL_TVCOMAX__SHIFT                 0x00000007
#define	TV_PLL_CNTL1__TVPCP__SHIFT                         0x00000008
#define	TV_PLL_CNTL1__TVPVG__SHIFT                         0x0000000b
#define	TV_PLL_CNTL1__TVPDC__SHIFT                         0x0000000e
#define	TV_PLL_CNTL1__TVPLL_FB_DIV_FRACTION__SHIFT         0x00000010
#define	TV_PLL_CNTL1__TVPLL_FB_DIV_FRACTION_UPDATE__SHIFT  0x00000013
#define	TV_PLL_CNTL1__TVPLL_FB_DIV_FRACTION_EN__SHIFT      0x00000014
#define	TV_PLL_CNTL1__TVCLK_SRC_SEL__SHIFT                 0x0000001e
#define	TV_PLL_CNTL1__TVPLL_TEST__SHIFT                    0x0000001f

// TV_DTO_INCREMENTS
#define	TV_DTO_INCREMENTS__TV_DTO_INC0__SHIFT              0x00000000
#define	TV_DTO_INCREMENTS__TV_DTO_INC1__SHIFT              0x00000010

// P2PLL_CNTL
#define	P2PLL_CNTL__P2PLL_RESET__SHIFT                     0x00000000
#define	P2PLL_CNTL__P2PLL_SLEEP__SHIFT                     0x00000001
#define	P2PLL_CNTL__P2PLL_TST_EN__SHIFT                    0x00000002
#define	P2PLL_CNTL__P2PLL_REFCLK_SEL__SHIFT                0x00000004
#define	P2PLL_CNTL__P2PLL_FBCLK_SEL__SHIFT                 0x00000005
#define	P2PLL_CNTL__P2PLL_TCPOFF__SHIFT                    0x00000006
#define	P2PLL_CNTL__P2PLL_TVCOMAX__SHIFT                   0x00000007
#define	P2PLL_CNTL__P2PLL_PCP__SHIFT                       0x00000008
#define	P2PLL_CNTL__P2PLL_PVG__SHIFT                       0x0000000b
#define	P2PLL_CNTL__P2PLL_PDC__SHIFT                       0x0000000e
#define	P2PLL_CNTL__P2PLL_ATOMIC_UPDATE_EN__SHIFT          0x00000010
#define	P2PLL_CNTL__P2PLL_ATOMIC_UPDATE_SYNC__SHIFT        0x00000012
#define	P2PLL_CNTL__P2PLL_DISABLE_AUTO_RESET__SHIFT        0x00000013

// P2PLL_REF_DIV
#define	P2PLL_REF_DIV__P2PLL_REF_DIV__SHIFT                0x00000000
#define	P2PLL_REF_DIV__P2PLL_ATOMIC_UPDATE_W__SHIFT        0x0000000f
#define	P2PLL_REF_DIV__P2PLL_ATOMIC_UPDATE_R__SHIFT        0x0000000f
#define	P2PLL_REF_DIV__P2PLL_REF_DIV_SRC__SHIFT            0x00000010

// CG_TEST_MACRO_RW_WRITE_U1
#define	CG_TEST_MACRO_RW_WRITE_U1__TEST_MACRO_RW_WRITE1__SHIFT 0x00000000
#define	CG_TEST_MACRO_RW_WRITE_U1__TEST_MACRO_RW_WRITE2__SHIFT 0x0000000e

// CG_TEST_MACRO_RW_READ_U1
#define	CG_TEST_MACRO_RW_READ_U1__TEST_MACRO_RW_READ1__SHIFT  0x00000000
#define	CG_TEST_MACRO_RW_READ_U1__TEST_MACRO_RW_READ2__SHIFT  0x00000010

// CG_TEST_MACRO_RW_DATA_U1
#define	CG_TEST_MACRO_RW_DATA_U1__TEST_MACRO_RW_DATA__SHIFT   0x00000000

// CG_TEST_MACRO_RW_CNTL_U1
#define	CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_START__SHIFT  0x00000000
#define	CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_OP__SHIFT  0x00000001
#define	CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_MODE__SHIFT   0x00000004
#define	CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_MISMATCH_SEL__SHIFT 0x00000006
#define	CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_MISMATCH__SHIFT 0x0000000f
#define	CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_ENABLE__SHIFT 0x00000010
#define	CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_SCLK_NEG_ENABLE__SHIFT 0x00000011

// TEMPERATURE_CNTL
#define	TEMPERATURE_CNTL__TEMPERATURE_CNTL_EN__SHIFT       0x00000000
#define	TEMPERATURE_CNTL__GFX_CORE_TEMPERATURE_R__SHIFT    0x00000004
#define	TEMPERATURE_CNTL__TEMPERATURE_CNTL_FBDIV_STEP_DELAY__SHIFT 0x00000010

// SSPLL_CNTL
#define	SSPLL_CNTL__SSPLL_RESET__SHIFT                     0x00000000
#define	SSPLL_CNTL__SSPLL_SLEEP__SHIFT                     0x00000001
#define	SSPLL_CNTL__SSPLL_TST_EN__SHIFT                    0x00000002
#define	SSPLL_CNTL__SSPLL_REFCLK_SEL__SHIFT                0x00000004
#define	SSPLL_CNTL__SSPLL_FBCLK_SEL__SHIFT                 0x00000005
#define	SSPLL_CNTL__SSPLL_TCPOFF__SHIFT                    0x00000006
#define	SSPLL_CNTL__SSPLL_TVCOMAX__SHIFT                   0x00000007
#define	SSPLL_CNTL__SSPLL_PCP__SHIFT                       0x00000008
#define	SSPLL_CNTL__SSPLL_PVG__SHIFT                       0x0000000b
#define	SSPLL_CNTL__SSPLL_PDC__SHIFT                       0x0000000e
#define	SSPLL_CNTL__SSPLL_ATOMIC_UPDATE_EN__SHIFT          0x00000010
#define	SSPLL_CNTL__SSPLL_ATOMIC_UPDATE_SYNC__SHIFT        0x00000012

// SSPLL_REF_DIV
#define	SSPLL_REF_DIV__SSPLL_REF_DIV__SHIFT                0x00000000
#define	SSPLL_REF_DIV__SSPLL_ATOMIC_UPDATE_W__SHIFT        0x0000000f
#define	SSPLL_REF_DIV__SSPLL_ATOMIC_UPDATE_R__SHIFT        0x0000000f
#define	SSPLL_REF_DIV__SSPLL_REF_DIV_SRC__SHIFT            0x00000010

// SSPLL_DIV_0
#define	SSPLL_DIV_0__SSPLL_FB_DIV__SHIFT                   0x00000000
#define	SSPLL_DIV_0__SSPLL_FB_DIV_FRACTION__SHIFT          0x0000000c
#define	SSPLL_DIV_0__SSPLL_ATOMIC_UPDATE_W__SHIFT          0x0000000f
#define	SSPLL_DIV_0__SSPLL_ATOMIC_UPDATE_R__SHIFT          0x0000000f
#define	SSPLL_DIV_0__SSPLL_POST_DIV__SHIFT                 0x00000010
#define	SSPLL_DIV_0__SSPLL_FB_DIV_FRACTION_UPDATE__SHIFT   0x0000001c

// SS_INT_CNTL
#define	SS_INT_CNTL__SS_INT_EN__SHIFT                      0x00000000
#define	SS_INT_CNTL__SS_INT_SEL__SHIFT                     0x00000001
#define	SS_INT_CNTL__SS_STEP_SIZE__SHIFT                   0x00000002
#define	SS_INT_CNTL__SS_DELAY__SHIFT                       0x00000004
#define	SS_INT_CNTL__SS_DELTA_FRACTION__SHIFT              0x00000008
#define	SS_INT_CNTL__SS_DELTA_INTEGER__SHIFT               0x0000000c
#define	SS_INT_CNTL__SS_PLL_DISPLAY_SRC__SHIFT             0x00000012
#define	SS_INT_CNTL__SS_PLL_DISPLAY_EN__SHIFT              0x00000013
#define	SS_INT_CNTL__SS_BUF_GENLOCK_EN__SHIFT              0x00000014
#define	SS_INT_CNTL__SS_BUF_GENLOCK_THRESHOLD__SHIFT       0x00000015
#define	SS_INT_CNTL__SS_BUF_GENLOCK_DURATION__SHIFT        0x00000018
#define	SS_INT_CNTL__SS_BUF_GENLOCK_HEIGHT__SHIFT          0x0000001b
#define	SS_INT_CNTL__SS_BUF_GENLOCK_THRESHOLD_1__SHIFT     0x0000001e

// SS_TST_CNTL
#define	SS_TST_CNTL__SS_TST_CNT__SHIFT                     0x00000000
#define	SS_TST_CNTL__SS_TST_CNT_SEL__SHIFT                 0x00000010
#define	SS_TST_CNTL__SS_TST_GE__SHIFT                      0x00000014
#define	SS_TST_CNTL__SS_TST_LE__SHIFT                      0x00000015
#define	SS_TST_CNTL__SS_TST_DEC__SHIFT                     0x00000016
#define	SS_TST_CNTL__ANALOG_MON_SS__SHIFT                  0x00000017
#define	SS_TST_CNTL__EXP_IMPLEMENTATION_EN__SHIFT          0x00000018
#define	SS_TST_CNTL__SS_ANTIGLITCH_EN__SHIFT               0x00000019
#define	SS_TST_CNTL__HDP_BUSY_HALF_SCLK__SHIFT             0x0000001a
#define	SS_TST_CNTL__EN_DIV2_HALF_SCLK__SHIFT              0x0000001b
#define	SS_TST_CNTL__SS_BUF_GENLOCK_HEIGHT_FRACTION__SHIFT 0x0000001c
#define	SS_TST_CNTL__SS_TST_MODE__SHIFT                    0x0000001f

// SCLK_MORE_CNTL
#define	SCLK_MORE_CNTL__DISPREGS_MAX_DYN_STOP_LAT__SHIFT   0x00000000
#define	SCLK_MORE_CNTL__MC_GUI_MAX_DYN_STOP_LAT__SHIFT     0x00000001
#define	SCLK_MORE_CNTL__MC_HOST_MAX_DYN_STOP_LAT__SHIFT    0x00000002
#define	SCLK_MORE_CNTL__SCLK_MULTI_THROTTLE_EN__SHIFT      0x00000003
#define	SCLK_MORE_CNTL__SCLK_ENGINE_IDLE_DIV__SHIFT        0x00000004
#define	SCLK_MORE_CNTL__SCLK_ENGINE_IDLE_VOLTAGE__SHIFT    0x00000006
#define	SCLK_MORE_CNTL__FORCE_DISPREGS__SHIFT              0x00000008
#define	SCLK_MORE_CNTL__FORCE_MC_GUI__SHIFT                0x00000009
#define	SCLK_MORE_CNTL__FORCE_MC_HOST__SHIFT               0x0000000a
#define	SCLK_MORE_CNTL__SOFT_CNTL_THROT_SCLK_VOLT_WAIT_IDLE__SHIFT 0x0000000b
#define	SCLK_MORE_CNTL__STOP_SCLK_EN__SHIFT                0x0000000c
#define	SCLK_MORE_CNTL__STOP_SCLK_A__SHIFT                 0x0000000d
#define	SCLK_MORE_CNTL__STOP_SCLK_B__SHIFT                 0x0000000e
#define	SCLK_MORE_CNTL__STOP_SCLK_C__SHIFT                 0x0000000f
#define	SCLK_MORE_CNTL__EN_SLOW_DOWN_SCLK__SHIFT           0x00000010
#define	SCLK_MORE_CNTL__EN_VOLTAGE_DROP__SHIFT             0x00000011
#define	SCLK_MORE_CNTL__TVFB_SOFT_RESET__SHIFT             0x00000012
#define	SCLK_MORE_CNTL__VOLTAGE_DROP_SYNC__SHIFT           0x00000013
#define	SCLK_MORE_CNTL__VOLTAGE_DELAY_SEL__SHIFT           0x00000014
#define	SCLK_MORE_CNTL__IDLE_DELAY_HALF_SCLK__SHIFT        0x00000016
#define	SCLK_MORE_CNTL__AGP_BUSY_HALF_SCLK__SHIFT          0x00000017
#define	SCLK_MORE_CNTL__EN_CLK27M_FOR_PLL_A5__SHIFT        0x00000018
#define	SCLK_MORE_CNTL__MC_EN_SLOW_DOWN_SCLK__SHIFT        0x00000019
#define	SCLK_MORE_CNTL__TWOD_EN_SLOW_DOWN_SCLK__SHIFT      0x0000001a
#define	SCLK_MORE_CNTL__SOFT_CNTL_THROT_SCLK_VOLT__SHIFT   0x0000001b
#define	SCLK_MORE_CNTL__MC_FULLSPEED_DELAY__SHIFT          0x0000001c

// TEMPERATURE_CNTL_TABLE_ENTRY_0
#define	TEMPERATURE_CNTL_TABLE_ENTRY_0__TEMPERATURE_0_CNTL_SPLL_FBDIV__SHIFT 0x00000000
#define	TEMPERATURE_CNTL_TABLE_ENTRY_0__TEMPERATURE_0_CNTL_SPLL_VCO__SHIFT 0x00000008
#define	TEMPERATURE_CNTL_TABLE_ENTRY_0__TEMPERATURE_0_CNTL_ENG_IDLE_DIV__SHIFT 0x0000000c
#define	TEMPERATURE_CNTL_TABLE_ENTRY_0__TEMPERATURE_0_CNTL_ENG_IDLE_VOLT__SHIFT 0x0000000e
#define	TEMPERATURE_CNTL_TABLE_ENTRY_0__TEMPERATURE_0__SHIFT 0x00000010
#define	TEMPERATURE_CNTL_TABLE_ENTRY_0__TEMPERATURE_UP_HYST__SHIFT 0x00000018
#define	TEMPERATURE_CNTL_TABLE_ENTRY_0__TEMPERATURE_DOWN_HYST__SHIFT 0x0000001c

// TEMPERATURE_CNTL_TABLE_ENTRY_1
#define	TEMPERATURE_CNTL_TABLE_ENTRY_1__TEMPERATURE_1_CNTL_SPLL_FBDIV__SHIFT 0x00000000
#define	TEMPERATURE_CNTL_TABLE_ENTRY_1__TEMPERATURE_1_CNTL_SPLL_VCO__SHIFT 0x00000008
#define	TEMPERATURE_CNTL_TABLE_ENTRY_1__TEMPERATURE_1_CNTL_ENG_IDLE_DIV__SHIFT 0x0000000c
#define	TEMPERATURE_CNTL_TABLE_ENTRY_1__TEMPERATURE_1_CNTL_ENG_IDLE_VOLT__SHIFT 0x0000000e
#define	TEMPERATURE_CNTL_TABLE_ENTRY_1__TEMPERATURE_1__SHIFT 0x00000010
#define	TEMPERATURE_CNTL_TABLE_ENTRY_1__SPLL_FB_DIV_R__SHIFT 0x00000018

// TEMPERATURE_CNTL_TABLE_ENTRY_2
#define	TEMPERATURE_CNTL_TABLE_ENTRY_2__TEMPERATURE_2_CNTL_SPLL_FBDIV__SHIFT 0x00000000
#define	TEMPERATURE_CNTL_TABLE_ENTRY_2__TEMPERATURE_2_CNTL_SPLL_VCO__SHIFT 0x00000008
#define	TEMPERATURE_CNTL_TABLE_ENTRY_2__TEMPERATURE_2_CNTL_ENG_IDLE_DIV__SHIFT 0x0000000c
#define	TEMPERATURE_CNTL_TABLE_ENTRY_2__TEMPERATURE_2_CNTL_ENG_IDLE_VOLT__SHIFT 0x0000000e
#define	TEMPERATURE_CNTL_TABLE_ENTRY_2__TEMPERATURE_2__SHIFT 0x00000010
#define	TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_CPW_FIFO_EXCLUDE__SHIFT 0x00000018
#define	TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_CPR_FIFO_EXCLUDE__SHIFT 0x00000019
#define	TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_SER_FIFO_EXCLUDE__SHIFT 0x0000001a
#define	TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_HDP_FIFO_EXCLUDE__SHIFT 0x0000001b
#define	TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_RB0_FIFO_EXCLUDE__SHIFT 0x0000001c
#define	TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_RB1_FIFO_EXCLUDE__SHIFT 0x0000001d
#define	TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_PPR_FIFO_EXCLUDE__SHIFT 0x0000001e
#define	TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_READ_FIFO_EXCLUDE__SHIFT 0x0000001f

// TEMPERATURE_CNTL_TABLE_ENTRY_3
#define	TEMPERATURE_CNTL_TABLE_ENTRY_3__TEMPERATURE_3_CNTL_SPLL_FBDIV__SHIFT 0x00000000
#define	TEMPERATURE_CNTL_TABLE_ENTRY_3__TEMPERATURE_3_CNTL_SPLL_VCO__SHIFT 0x00000008
#define	TEMPERATURE_CNTL_TABLE_ENTRY_3__TEMPERATURE_3_CNTL_ENG_IDLE_DIV__SHIFT 0x0000000c
#define	TEMPERATURE_CNTL_TABLE_ENTRY_3__TEMPERATURE_3_CNTL_ENG_IDLE_VOLT__SHIFT 0x0000000e
#define	TEMPERATURE_CNTL_TABLE_ENTRY_3__TEMPERATURE_3__SHIFT 0x00000010
#define	TEMPERATURE_CNTL_TABLE_ENTRY_3__ENGINE_DYNCLK_PAIRING_EN__SHIFT 0x00000018
#define	TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_SE_RE__SHIFT 0x00000019
#define	TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_SE_TAM__SHIFT 0x0000001a
#define	TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_SE_TIM__SHIFT 0x0000001b
#define	TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_SE_TDM__SHIFT 0x0000001c
#define	TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_SE_PB__SHIFT 0x0000001d
#define	TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_RE_TAM__SHIFT 0x0000001e
#define	TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_RE_TIM__SHIFT 0x0000001f

// TEMPERATURE_CNTL_TABLE_ENTRY_4
#define	TEMPERATURE_CNTL_TABLE_ENTRY_4__TEMPERATURE_4_CNTL_SPLL_FBDIV__SHIFT 0x00000000
#define	TEMPERATURE_CNTL_TABLE_ENTRY_4__TEMPERATURE_4_CNTL_SPLL_VCO__SHIFT 0x00000008
#define	TEMPERATURE_CNTL_TABLE_ENTRY_4__TEMPERATURE_4_CNTL_ENG_IDLE_DIV__SHIFT 0x0000000c
#define	TEMPERATURE_CNTL_TABLE_ENTRY_4__TEMPERATURE_4_CNTL_ENG_IDLE_VOLT__SHIFT 0x0000000e
#define	TEMPERATURE_CNTL_TABLE_ENTRY_4__TEMPERATURE_4__SHIFT 0x00000010
#define	TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_RE_TDM__SHIFT 0x00000018
#define	TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_RE_PB__SHIFT 0x00000019
#define	TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TAM_TIM__SHIFT 0x0000001a
#define	TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TAM_TDM__SHIFT 0x0000001b
#define	TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TAM_PB__SHIFT 0x0000001c
#define	TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TIM_TDM__SHIFT 0x0000001d
#define	TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TIM_PB__SHIFT 0x0000001e
#define	TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TDM_PB__SHIFT 0x0000001f

// TEMPERATURE_CNTL_TABLE_ENTRY_5
#define	TEMPERATURE_CNTL_TABLE_ENTRY_5__TEMPERATURE_5_CNTL_SPLL_FBDIV__SHIFT 0x00000000
#define	TEMPERATURE_CNTL_TABLE_ENTRY_5__TEMPERATURE_5_CNTL_SPLL_VCO__SHIFT 0x00000008
#define	TEMPERATURE_CNTL_TABLE_ENTRY_5__TEMPERATURE_5_CNTL_ENG_IDLE_DIV__SHIFT 0x0000000c
#define	TEMPERATURE_CNTL_TABLE_ENTRY_5__TEMPERATURE_5_CNTL_ENG_IDLE_VOLT__SHIFT 0x0000000e
#define	TEMPERATURE_CNTL_TABLE_ENTRY_5__TEMPERATURE_5__SHIFT 0x00000010

// TEMPERATURE_CNTL_TABLE_ENTRY_6
#define	TEMPERATURE_CNTL_TABLE_ENTRY_6__TEMPERATURE_6_CNTL_SPLL_FBDIV__SHIFT 0x00000000
#define	TEMPERATURE_CNTL_TABLE_ENTRY_6__TEMPERATURE_6_CNTL_SPLL_VCO__SHIFT 0x00000008
#define	TEMPERATURE_CNTL_TABLE_ENTRY_6__TEMPERATURE_6_CNTL_ENG_IDLE_DIV__SHIFT 0x0000000c
#define	TEMPERATURE_CNTL_TABLE_ENTRY_6__TEMPERATURE_6_CNTL_ENG_IDLE_VOLT__SHIFT 0x0000000e
#define	TEMPERATURE_CNTL_TABLE_ENTRY_6__TEMPERATURE_6__SHIFT 0x00000010

// TEMPERATURE_CNTL_TABLE_ENTRY_7
#define	TEMPERATURE_CNTL_TABLE_ENTRY_7__TEMPERATURE_7_CNTL_SPLL_FBDIV__SHIFT 0x00000000
#define	TEMPERATURE_CNTL_TABLE_ENTRY_7__TEMPERATURE_7_CNTL_SPLL_VCO__SHIFT 0x00000008
#define	TEMPERATURE_CNTL_TABLE_ENTRY_7__TEMPERATURE_7_CNTL_ENG_IDLE_DIV__SHIFT 0x0000000c
#define	TEMPERATURE_CNTL_TABLE_ENTRY_7__TEMPERATURE_7_CNTL_ENG_IDLE_VOLT__SHIFT 0x0000000e
#define	TEMPERATURE_CNTL_TABLE_ENTRY_7__TEMPERATURE_7__SHIFT 0x00000010

// TEMPERATURE_CNTL_TABLE_ENTRY_8
#define	TEMPERATURE_CNTL_TABLE_ENTRY_8__TEMPERATURE_8_CNTL_SPLL_FBDIV__SHIFT 0x00000000
#define	TEMPERATURE_CNTL_TABLE_ENTRY_8__TEMPERATURE_8_CNTL_SPLL_VCO__SHIFT 0x00000008
#define	TEMPERATURE_CNTL_TABLE_ENTRY_8__TEMPERATURE_8_CNTL_ENG_IDLE_DIV__SHIFT 0x0000000c
#define	TEMPERATURE_CNTL_TABLE_ENTRY_8__TEMPERATURE_8_CNTL_ENG_IDLE_VOLT__SHIFT 0x0000000e
#define	TEMPERATURE_CNTL_TABLE_ENTRY_8__TEMPERATURE_8__SHIFT 0x00000010

// TEMPERATURE_CNTL_TABLE_ENTRY_9
#define	TEMPERATURE_CNTL_TABLE_ENTRY_9__TEMPERATURE_9_CNTL_SPLL_FBDIV__SHIFT 0x00000000
#define	TEMPERATURE_CNTL_TABLE_ENTRY_9__TEMPERATURE_9_CNTL_SPLL_VCO__SHIFT 0x00000008
#define	TEMPERATURE_CNTL_TABLE_ENTRY_9__TEMPERATURE_9_CNTL_ENG_IDLE_DIV__SHIFT 0x0000000c
#define	TEMPERATURE_CNTL_TABLE_ENTRY_9__TEMPERATURE_9_CNTL_ENG_IDLE_VOLT__SHIFT 0x0000000e
#define	TEMPERATURE_CNTL_TABLE_ENTRY_9__TEMPERATURE_9__SHIFT 0x00000010

// CLK_PWRMGT_CNTL
#define	CLK_PWRMGT_CNTL__SPLL_PWRMGT_OFF__SHIFT            0x00000001
#define	CLK_PWRMGT_CNTL__PPLL_PWRMGT_OFF__SHIFT            0x00000002
#define	CLK_PWRMGT_CNTL__P2PLL_PWRMGT_OFF__SHIFT           0x00000003
#define	CLK_PWRMGT_CNTL__SCLK_TURNOFF__SHIFT               0x00000005
#define	CLK_PWRMGT_CNTL__PCLK_TURNOFF__SHIFT               0x00000006
#define	CLK_PWRMGT_CNTL__P2CLK_TURNOFF__SHIFT              0x00000007
#define	CLK_PWRMGT_CNTL__TEST_MODE__SHIFT                  0x00000009
#define	CLK_PWRMGT_CNTL__GLOBAL_PMAN_EN__SHIFT             0x0000000a
#define	CLK_PWRMGT_CNTL__ENGINE_DYNCLK_MODE__SHIFT         0x0000000c
#define	CLK_PWRMGT_CNTL__ACTIVE_HILO_LAT__SHIFT            0x0000000d
#define	CLK_PWRMGT_CNTL__DISP_DYN_STOP_LAT__SHIFT          0x0000000f
#define	CLK_PWRMGT_CNTL__DISP_PM__SHIFT                    0x00000014
#define	CLK_PWRMGT_CNTL__DYN_STOP_MODE__SHIFT              0x00000015
#define	CLK_PWRMGT_CNTL__CG_NO1_DEBUG_M6__SHIFT            0x00000018
#define	CLK_PWRMGT_CNTL__TVPLL_PWRMGT_OFF__SHIFT           0x0000001e
#define	CLK_PWRMGT_CNTL__TVCLK_TURNOFF__SHIFT              0x0000001f

// PLL_PWRMGT_CNTL
#define	PLL_PWRMGT_CNTL__SPLL_TURNOFF__SHIFT               0x00000001
#define	PLL_PWRMGT_CNTL__PPLL_TURNOFF__SHIFT               0x00000002
#define	PLL_PWRMGT_CNTL__P2PLL_TURNOFF__SHIFT              0x00000003
#define	PLL_PWRMGT_CNTL__TVPLL_TURNOFF__SHIFT              0x00000004
#define	PLL_PWRMGT_CNTL__AGPCLK_DYN_STOP_LAT__SHIFT        0x00000005
#define	PLL_PWRMGT_CNTL__APM_POWER_STATE__SHIFT            0x00000009
#define	PLL_PWRMGT_CNTL__APM_PWRSTATE_RD__SHIFT            0x0000000b
#define	PLL_PWRMGT_CNTL__PM_MODE_SEL__SHIFT                0x0000000d
#define	PLL_PWRMGT_CNTL__EN_PWRSEQ_DONE_COND__SHIFT        0x0000000e
#define	PLL_PWRMGT_CNTL__EN_DISP_PARKED_COND__SHIFT        0x0000000f
#define	PLL_PWRMGT_CNTL__MOBILE_SU__SHIFT                  0x00000010
#define	PLL_PWRMGT_CNTL__SU_SCLK_USE_BCLK__SHIFT           0x00000011
#define	PLL_PWRMGT_CNTL__SU_MCLK_USE_BCLK__SHIFT           0x00000012
#define	PLL_PWRMGT_CNTL__SU_SUSTAIN_DISABLE__SHIFT         0x00000013
#define	PLL_PWRMGT_CNTL__TCL_BYPASS_DISABLE__SHIFT         0x00000014
#define	PLL_PWRMGT_CNTL__TCL_CLOCK_ACTIVE_RD__SHIFT        0x00000015
#define	PLL_PWRMGT_CNTL__CG_NO2_DEBUG__SHIFT               0x00000018

// M_SPLL_REF_FB_DIV
#define	M_SPLL_REF_FB_DIV__M_SPLL_REF_DIV__SHIFT           0x00000000
#define	M_SPLL_REF_FB_DIV__SPLL_FB_DIV__SHIFT              0x00000010

// IDCT_RUNS
#define	IDCT_RUNS__IDCT_RUNS_3__SHIFT                      0x00000000
#define	IDCT_RUNS__IDCT_RUNS_2__SHIFT                      0x00000008
#define	IDCT_RUNS__IDCT_RUNS_1__SHIFT                      0x00000010
#define	IDCT_RUNS__IDCT_RUNS_0__SHIFT                      0x00000018

// IDCT_LEVELS
#define	IDCT_LEVELS__IDCT_LEVEL_HI__SHIFT                  0x00000000
#define	IDCT_LEVELS__IDCT_LEVEL_LO__SHIFT                  0x00000010

// IDCT_CONTROL
#define	IDCT_CONTROL__IDCT_CTL_LUMA_RD_FORMAT__SHIFT       0x00000000
#define	IDCT_CONTROL__IDCT_CTL_CHROMA_RD_FORMAT__SHIFT     0x00000002
#define	IDCT_CONTROL__IDCT_CTL_SCAN_PATTERN__SHIFT         0x00000004
#define	IDCT_CONTROL__IDCT_CTL_INTRA__SHIFT                0x00000005
#define	IDCT_CONTROL__IDCT_CTL_FLUSH__SHIFT                0x00000006
#define	IDCT_CONTROL__IDCT_CTL_PASSTHRU__SHIFT             0x00000007
#define	IDCT_CONTROL__IDCT_CTL_SW_RESET__SHIFT             0x00000008
#define	IDCT_CONTROL__IDCT_CTL_CONSTREQ__SHIFT             0x00000009
#define	IDCT_CONTROL__IDCT_CTL_SCRAMBLE__SHIFT             0x0000000a

// IDCT_AUTH_CONTROL
#define	IDCT_AUTH_CONTROL__CONTROL_BITS__SHIFT             0x00000000

// IDCT_AUTH
#define	IDCT_AUTH__AUTH__SHIFT                             0x00000000

// NB_VENDOR_ID
#define	NB_VENDOR_ID__VENDOR_ID__SHIFT                     0x00000000

// NB_DEVICE_ID
#define	NB_DEVICE_ID__DEVICE_ID__SHIFT                     0x00000000

// NB_COMMAND
#define	NB_COMMAND__IO_ACCESS_EN__SHIFT                    0x00000000
#define	NB_COMMAND__MEM_ACCESS_EN__SHIFT                   0x00000001
#define	NB_COMMAND__BUS_MASTER_EN__SHIFT                   0x00000002
#define	NB_COMMAND__SPECIAL_CYCLE_EN__SHIFT                0x00000003
#define	NB_COMMAND__MEM_WRITE_INVALIDATE_EN__SHIFT         0x00000004
#define	NB_COMMAND__PAL_SNOOP_EN__SHIFT                    0x00000005
#define	NB_COMMAND__PARITY_ERROR_EN__SHIFT                 0x00000006
#define	NB_COMMAND__Reserved0__SHIFT                       0x00000007
#define	NB_COMMAND__SERR_EN__SHIFT                         0x00000008
#define	NB_COMMAND__FAST_B2B_EN__SHIFT                     0x00000009
#define	NB_COMMAND__Reserved__SHIFT                        0x0000000a

// NB_STATUS
#define	NB_STATUS__CAP_LIST__SHIFT                         0x00000004
#define	NB_STATUS__PCI_66_EN__SHIFT                        0x00000005
#define	NB_STATUS__Reserved__SHIFT                         0x00000006
#define	NB_STATUS__FAST_BACK_CAPABLE__SHIFT                0x00000007
#define	NB_STATUS__DEVSEL_TIMING__SHIFT                    0x00000009
#define	NB_STATUS__SIGNAL_TARGET_ABORT__SHIFT              0x0000000b
#define	NB_STATUS__RECEIVED_TARGET_ABORT__SHIFT            0x0000000c
#define	NB_STATUS__RECEIVED_MASTER_ABORT__SHIFT            0x0000000d
#define	NB_STATUS__SIGNALED_SYSTEM_ERROR__SHIFT            0x0000000e
#define	NB_STATUS__PARITY_ERROR_DETECTED__SHIFT            0x0000000f

// NB_REVISION_ID
#define	NB_REVISION_ID__MINOR_REV_ID__SHIFT                0x00000000
#define	NB_REVISION_ID__MAJOR_REV_ID__SHIFT                0x00000004

// NB_REGPROG_INF
#define	NB_REGPROG_INF__REG_LEVEL_PROG_INF__SHIFT          0x00000000

// NB_SUB_CLASS
#define	NB_SUB_CLASS__SUB_CLASS_INF__SHIFT                 0x00000007

// NB_BASE_CODE
#define	NB_BASE_CODE__BASE_CLASS_CODE__SHIFT               0x00000000

// NB_CACHE_LINE
#define	NB_CACHE_LINE__CACHE_LINE_SIZE__SHIFT              0x00000000

// NB_LATENCY
#define	NB_LATENCY__LATENCY_TIMER__SHIFT                   0x00000000

// NB_HEADER
#define	NB_HEADER__HEADER_TYPE__SHIFT                      0x00000000
#define	NB_HEADER__DEVICE_TYPE__SHIFT                      0x00000007

// NB_BIST
#define	NB_BIST__BIST_COMP__SHIFT                          0x00000000
#define	NB_BIST__BIST_STRT__SHIFT                          0x00000006
#define	NB_BIST__BIST_CAP__SHIFT                           0x00000007

// NB_BAR0_AGP
#define	NB_BAR0_AGP__MEM_IO__SHIFT                         0x00000000
#define	NB_BAR0_AGP__TYPE__SHIFT                           0x00000001
#define	NB_BAR0_AGP__PREFETCH_EN__SHIFT                    0x00000003
#define	NB_BAR0_AGP__MEM_BASE_LOW__SHIFT                   0x00000004
#define	NB_BAR0_AGP__MEM_BASE_HIGH__SHIFT                  0x00000019

// NB_BAR1_GART
#define	NB_BAR1_GART__MEM_IO__SHIFT                        0x00000000
#define	NB_BAR1_GART__TYPE__SHIFT                          0x00000001
#define	NB_BAR1_GART__PREFETCH_EN__SHIFT                   0x00000003
#define	NB_BAR1_GART__MEM_BASE_LOW__SHIFT                  0x00000004
#define	NB_BAR1_GART__MEM_BASE_HIGH__SHIFT                 0x0000000c

// NB_BAR2_PM2
#define	NB_BAR2_PM2__MEM_IO__SHIFT                         0x00000000
#define	NB_BAR2_PM2__PM2_BASE__SHIFT                       0x00000002

// NB_ADAPTER_ID
#define	NB_ADAPTER_ID__SUBSYSTEM_VENDOR_ID__SHIFT          0x00000000
#define	NB_ADAPTER_ID__SUBSYSTEM_ID__SHIFT                 0x00000010

// NB_CAPABILITIES_PTR
#define	NB_CAPABILITIES_PTR__CAP_PTR__SHIFT                0x00000000

// NB_CFG_SLOT1
#define	NB_CFG_SLOT1__DEFER_ENABLE__SHIFT                  0x00000010
#define	NB_CFG_SLOT1__HARD_FAIL_ENABLE__SHIFT              0x00000012
#define	NB_CFG_SLOT1__CPU_BACK_2_BACK_READ__SHIFT          0x00000014
#define	NB_CFG_SLOT1__CFG_OPT_BPRI_OK__SHIFT               0x0000001a
#define	NB_CFG_SLOT1__IOQ1_DIS_DURING_LOCK__SHIFT          0x0000001b
#define	NB_CFG_SLOT1__PCI_DMA_SNOOP_ENB__SHIFT             0x0000001d
#define	NB_CFG_SLOT1__PCI_WRITE_POSTING__SHIFT             0x0000001e
#define	NB_CFG_SLOT1__PCI_IO_WRITE_POST__SHIFT             0x0000001f

// NB_PII_HW_DEBUG
#define	NB_PII_HW_DEBUG__PII_HW_DEBUG__SHIFT               0x00000000
#define	NB_PII_HW_DEBUG__Prefetch__SHIFT                   0x0000001b
#define	NB_PII_HW_DEBUG__BAR2_PM2Enable__SHIFT             0x0000001c
#define	NB_PII_HW_DEBUG__ArbDockingEnable__SHIFT           0x0000001d
#define	NB_PII_HW_DEBUG__P4IntEnable__SHIFT                0x0000001e
#define	NB_PII_HW_DEBUG__CfgPciC_AMDSBDisable__SHIFT       0x0000001f

// NB_EX_BIU_CTRL
#define	NB_EX_BIU_CTRL___2BITPF__SHIFT                     0x00000003
#define	NB_EX_BIU_CTRL__WR_DATA_DELAY__SHIFT               0x00000008
#define	NB_EX_BIU_CTRL__PI_CFG_PERF_DATA_A__SHIFT          0x00000016
#define	NB_EX_BIU_CTRL__PI_CFG_PERF_DATA_B__SHIFT          0x00000017

// NB_ECC_CTRL
#define	NB_ECC_CTRL__NOT_IMPLEMENTED__SHIFT                0x00000000

// NB_PCI_CTRL
#define	NB_PCI_CTRL__FUNCTION_1_ENABLE__SHIFT              0x00000000
#define	NB_PCI_CTRL__PCI_OR_ENABLE__SHIFT                  0x00000001
#define	NB_PCI_CTRL__PCI_DT_ENABLE__SHIFT                  0x00000002
#define	NB_PCI_CTRL__APC_OR_ENABLE__SHIFT                  0x00000003
#define	NB_PCI_CTRL__APC_DT_ENABLE__SHIFT                  0x00000004
#define	NB_PCI_CTRL__APC_FWRITE_ENABLE__SHIFT              0x00000005
#define	NB_PCI_CTRL__PCI_DELAY_READ_RETRY_COUNT__SHIFT     0x00000008
#define	NB_PCI_CTRL__PCI_MULTIREAD_ENABLE__SHIFT           0x0000000c
#define	NB_PCI_CTRL__PCI_MR_DATA_DISCARD_ENABLE__SHIFT     0x0000000d
#define	NB_PCI_CTRL__PCI_MR_BUF_DISCARD_ENABLE__SHIFT      0x0000000e
#define	NB_PCI_CTRL__PCI_MR_AUTO_IVAT__SHIFT               0x0000000f
#define	NB_PCI_CTRL__PCI_MR_PFC_IVAT__SHIFT                0x00000010
#define	NB_PCI_CTRL__APC_APIC_ENABLE__SHIFT                0x00000011
#define	NB_PCI_CTRL__PCI_MR_APCI_ENABLE__SHIFT             0x00000012
#define	NB_PCI_CTRL__PCI_MR_HW_DEBUG__SHIFT                0x00000013

// NB_ADAPTER_ID_W
#define	NB_ADAPTER_ID_W__SUBSYSTEM_VENDOR_ID__SHIFT        0x00000000
#define	NB_ADAPTER_ID_W__SUBSYSTEM_ID__SHIFT               0x00000010

// NB_PAM0
#define	NB_PAM0__READ_ENABLE_F0__SHIFT                     0x00000004
#define	NB_PAM0__WRITE_ENABLE_F0__SHIFT                    0x00000005

// NB_PAM1
#define	NB_PAM1__READ_ENABLE_C0__SHIFT                     0x00000000
#define	NB_PAM1__WRITE_ENABLE_C0__SHIFT                    0x00000001
#define	NB_PAM1__READ_ENABLE_C4__SHIFT                     0x00000004
#define	NB_PAM1__WRITE_ENABLE_C4__SHIFT                    0x00000005

// NB_PAM2
#define	NB_PAM2__READ_ENABLE_C8__SHIFT                     0x00000000
#define	NB_PAM2__WRITE_ENABLE_C8__SHIFT                    0x00000001
#define	NB_PAM2__READ_ENABLE_CC__SHIFT                     0x00000004
#define	NB_PAM2__WRITE_ENABLE_CC__SHIFT                    0x00000005

// NB_PAM3
#define	NB_PAM3__READ_ENABLE_D0__SHIFT                     0x00000000
#define	NB_PAM3__WRITE_ENABLE_D0__SHIFT                    0x00000001
#define	NB_PAM3__READ_ENABLE_D4__SHIFT                     0x00000004
#define	NB_PAM3__WRITE_ENABLE_D4__SHIFT                    0x00000005

// NB_PAM4
#define	NB_PAM4__READ_ENABLE_D8__SHIFT                     0x00000000
#define	NB_PAM4__WRITE_ENABLE_D8__SHIFT                    0x00000001
#define	NB_PAM4__READ_ENABLE_DC__SHIFT                     0x00000004
#define	NB_PAM4__WRITE_ENABLE_DC__SHIFT                    0x00000005

// NB_PAM5
#define	NB_PAM5__READ_ENABLE_E0__SHIFT                     0x00000000
#define	NB_PAM5__WRITE_ENABLE_E0__SHIFT                    0x00000001
#define	NB_PAM5__READ_ENABLE_E4__SHIFT                     0x00000004
#define	NB_PAM5__WRITE_ENABLE_E4__SHIFT                    0x00000005

// NB_PAM6
#define	NB_PAM6__READ_ENABLE_E8__SHIFT                     0x00000000
#define	NB_PAM6__WRITE_ENABLE_E8__SHIFT                    0x00000001
#define	NB_PAM6__READ_ENABLE_EC__SHIFT                     0x00000004
#define	NB_PAM6__WRITE_ENABLE_EC__SHIFT                    0x00000005

// NB_BIU_CTRL
#define	NB_BIU_CTRL__Reserved__SHIFT                       0x00000000

// NB_BIU_SIP
#define	NB_BIU_SIP__Reserved__SHIFT                        0x00000000

// NB_FDHC
#define	NB_FDHC__MEM_HOLE_ENABLE__SHIFT                    0x00000006

// NB_SMRAM
#define	NB_SMRAM__SMM_LOCATION__SHIFT                      0x00000000
#define	NB_SMRAM__GLOBAL_SMRAM_ENABLE__SHIFT               0x00000003
#define	NB_SMRAM__SMM_SPACE_LOCKED__SHIFT                  0x00000004
#define	NB_SMRAM__SMM_SPACE_OPEN__SHIFT                    0x00000005

// NB_EXSMRAM
#define	NB_EXSMRAM__TSEG_ENABLE__SHIFT                     0x00000000
#define	NB_EXSMRAM__TSEG_SIZE__SHIFT                       0x00000001
#define	NB_EXSMRAM__Reserved0__SHIFT                       0x00000005
#define	NB_EXSMRAM__EX_SMRAM_ERROR__SHIFT                  0x00000006
#define	NB_EXSMRAM__HI_SMRAM_ENABLE__SHIFT                 0x00000007

// NB_PMCR
#define	NB_PMCR__ACPI_CTL_REG_EN__SHIFT                    0x00000000

// NB_STRAP_READ_BACK
#define	NB_STRAP_READ_BACK__ChangeID__SHIFT                0x00000000
#define	NB_STRAP_READ_BACK__MobilePart__SHIFT              0x00000002
#define	NB_STRAP_READ_BACK__PAR__SHIFT                     0x00000003
#define	NB_STRAP_READ_BACK__AGP8X_DETb__SHIFT              0x00000004
#define	NB_STRAP_READ_BACK__FSB133EN__SHIFT                0x00000005
#define	NB_STRAP_READ_BACK__IntClk__SHIFT                  0x0000000b
#define	NB_STRAP_READ_BACK__ProdTest__SHIFT                0x00000010
#define	NB_STRAP_READ_BACK__CPU_Voltage0__SHIFT            0x00000011
#define	NB_STRAP_READ_BACK__PhaseCal__SHIFT                0x00000012
#define	NB_STRAP_READ_BACK__MemVMode__SHIFT                0x00000013
#define	NB_STRAP_READ_BACK__CalDefaults__SHIFT             0x00000015
#define	NB_STRAP_READ_BACK__OscClkSel__SHIFT               0x00000016
#define	NB_STRAP_READ_BACK__ClkBypass__SHIFT               0x00000017
#define	NB_STRAP_READ_BACK__MobileCpuSel__SHIFT            0x00000018
#define	NB_STRAP_READ_BACK__CPU_Voltage1__SHIFT            0x00000019
#define	NB_STRAP_READ_BACK__NBStrap_In__SHIFT              0x0000001a
#define	NB_STRAP_READ_BACK__Enable_SS__SHIFT               0x0000001c
#define	NB_STRAP_READ_BACK__Default__SHIFT                 0x0000001d
#define	NB_STRAP_READ_BACK__ClkSpeed__SHIFT                0x0000001e

// NB_MC_CNTL
#define	NB_MC_CNTL__Reserved0__SHIFT                       0x00000000
#define	NB_MC_CNTL__DISABLE_CPU__SHIFT                     0x00000001
#define	NB_MC_CNTL__Reserved1_A5__SHIFT                    0x00000003
#define	NB_MC_CNTL__DISABLE_AGP__SHIFT                     0x00000004
#define	NB_MC_CNTL__DISP_HiPri__SHIFT                      0x00000005
#define	NB_MC_CNTL__DLL_Reset__SHIFT                       0x00000006
#define	NB_MC_CNTL__DLL_PwrDown__SHIFT                     0x00000007
#define	NB_MC_CNTL__DLL_Ready__SHIFT                       0x00000008
#define	NB_MC_CNTL__Reserved2_A5__SHIFT                    0x00000009
#define	NB_MC_CNTL__DISP_HiPri2__SHIFT                     0x0000000b
#define	NB_MC_CNTL__Reserved3__SHIFT                       0x0000000c
#define	NB_MC_CNTL__SELF_RF_DIS__SHIFT                     0x00000012
#define	NB_MC_CNTL__DISABLE_BYPASS__SHIFT                  0x00000013
#define	NB_MC_CNTL__Reserved4__SHIFT                       0x00000014
#define	NB_MC_CNTL__SEQ_ARB_MODE__SHIFT                    0x00000015
#define	NB_MC_CNTL__MC_CLEAN_GC__SHIFT                     0x00000016
#define	NB_MC_CNTL__MEM_DYNAMIC_CKE__SHIFT                 0x00000017
#define	NB_MC_CNTL__MEM_SDRAM_TRI_EN__SHIFT                0x00000018
#define	NB_MC_CNTL__MEM_DYN_REC_CTRL__SHIFT                0x00000019
#define	NB_MC_CNTL__Reserved5__SHIFT                       0x0000001a
#define	NB_MC_CNTL__MC_PDN_MODE__SHIFT                     0x0000001b
#define	NB_MC_CNTL__MC_STARTUP__SHIFT                      0x0000001d
#define	NB_MC_CNTL__MC_PWRDOWN__SHIFT                      0x0000001e
#define	NB_MC_CNTL__MC_RESTART__SHIFT                      0x0000001f

// NB_MC_LIMIT
#define	NB_MC_LIMIT__R6_RD_IDLE_LIMIT__SHIFT               0x00000000
#define	NB_MC_LIMIT__R6_RD_PH_LIMIT__SHIFT                 0x00000005
#define	NB_MC_LIMIT__R6_WR_IDLE_LIMIT__SHIFT               0x00000008
#define	NB_MC_LIMIT__R6_WR_PH_LIMIT__SHIFT                 0x0000000d
#define	NB_MC_LIMIT__NB_RD_IDLE_LIMIT__SHIFT               0x00000010
#define	NB_MC_LIMIT__NB_RD_PH_LIMIT__SHIFT                 0x00000015
#define	NB_MC_LIMIT__NB_WR_IDLE_LIMIT__SHIFT               0x00000018
#define	NB_MC_LIMIT__NB_WR_PH_LIMIT__SHIFT                 0x0000001d

// SCRATCH_NBCFG
#define	SCRATCH_NBCFG__SCRATCH__SHIFT                      0x00000000

// NB_BIU_CFG
#define	NB_BIU_CFG__SnoopCtlEn__SHIFT                      0x00000000
#define	NB_BIU_CFG__BlockMasterWrEn__SHIFT                 0x00000001
#define	NB_BIU_CFG__WrWaitsSnpEn__SHIFT                    0x00000002
#define	NB_BIU_CFG__HiPriRdMode__SHIFT                     0x00000003
#define	NB_BIU_CFG__PCIBIURdPri__SHIFT                     0x00000005
#define	NB_BIU_CFG__EarlyTRDY__SHIFT                       0x00000007
#define	NB_BIU_CFG__Arb_PreemptEn__SHIFT                   0x00000008
#define	NB_BIU_CFG__RedirectEn__SHIFT                      0x00000009
#define	NB_BIU_CFG__HyperThreadEn__SHIFT                   0x0000000a
#define	NB_BIU_CFG__RefvebDCStop__SHIFT                    0x0000000b
#define	NB_BIU_CFG__SMUBufferHalf__SHIFT                   0x0000000c
#define	NB_BIU_CFG__C2ABufferHalf__SHIFT                   0x0000000d
#define	NB_BIU_CFG__M6RefreshDef__SHIFT                    0x0000000e
#define	NB_BIU_CFG__M6TimeoutDef__SHIFT                    0x0000000f
#define	NB_BIU_CFG__M6UrgentDef__SHIFT                     0x00000010
#define	NB_BIU_CFG__M6IdleDefKill__SHIFT                   0x00000011
#define	NB_BIU_CFG__IOQDeep__SHIFT                         0x00000012
#define	NB_BIU_CFG__HiPriWrDef__SHIFT                      0x00000016
#define	NB_BIU_CFG__DBIDisable__SHIFT                      0x00000017
#define	NB_BIU_CFG__HiPriWrMode__SHIFT                     0x00000018
#define	NB_BIU_CFG__IntelDBIModeEn__SHIFT                  0x0000001a
#define	NB_BIU_CFG__BlkWrStreamEn__SHIFT                   0x0000001b
#define	NB_BIU_CFG__DualDeferOff__SHIFT                    0x0000001c
#define	NB_BIU_CFG__OutstandDef__SHIFT                     0x0000001d

// NB_POCO
#define	NB_POCO__POCOArm__SHIFT                            0x00000000
#define	NB_POCO__Reserved__SHIFT                           0x00000001
#define	NB_POCO__POCOLock__SHIFT                           0x00000002
#define	NB_POCO__PowerOnConfig__SHIFT                      0x00000003

// NB_PCI_ARB
#define	NB_PCI_ARB__PARK_PCI__SHIFT                        0x00000000
#define	NB_PCI_ARB__APC_PREFETCH_EN__SHIFT                 0x00000001
#define	NB_PCI_ARB__PCI_PREFETCH_EN__SHIFT                 0x00000002
#define	NB_PCI_ARB__TARGET_LAT_TIMER_DISABLE__SHIFT        0x00000003
#define	NB_PCI_ARB__EV6MODE__SHIFT                         0x00000004
#define	NB_PCI_ARB___14M_HOLE__SHIFT                       0x00000005
#define	NB_PCI_ARB___15M_HOLE__SHIFT                       0x00000006
#define	NB_PCI_ARB__PM_REG_ENABLE__SHIFT                   0x00000007
#define	NB_PCI_ARB__SOUTH_BRIDGE_LOCK_DISABLE__SHIFT       0x00000008
#define	NB_PCI_ARB__AGP_ARBITER_PIPE_DISABLE__SHIFT        0x00000009
#define	NB_PCI_ARB__PCI_EARLY_PROBE_DISABLE__SHIFT         0x0000000a
#define	NB_PCI_ARB__APC_EARLY_PROBE_DISABLE__SHIFT         0x0000000b
#define	NB_PCI_ARB__READ_DATA_ERROR_DISABLE__SHIFT         0x0000000c
#define	NB_PCI_ARB__APC_WRITE_POST_RETRY__SHIFT            0x0000000d
#define	NB_PCI_ARB__PCI_WRITE_POST_RETRY__SHIFT            0x0000000e
#define	NB_PCI_ARB__MDA_DEBUG__SHIFT                       0x0000000f
#define	NB_PCI_ARB__PCI_CHAINING_ENABLE__SHIFT             0x00000010
#define	NB_PCI_ARB__APC_CHAINING_ENABLE__SHIFT             0x00000011
#define	NB_PCI_ARB__OPUS_ENABLE__SHIFT                     0x00000012
#define	NB_PCI_ARB__TARGET_LATENCY__SHIFT                  0x00000017
#define	NB_PCI_ARB__AGP_VGA_BIOS__SHIFT                    0x00000018

// NB_CFG_STAT
#define	NB_CFG_STAT__CPU_DIVIDER__SHIFT                    0x00000000
#define	NB_CFG_STAT__OUT_CLK_DELAY__SHIFT                  0x00000004
#define	NB_CFG_STAT__IN_CLK_DELAY__SHIFT                   0x00000005
#define	NB_CFG_STAT__Reserved0__SHIFT                      0x00000007
#define	NB_CFG_STAT__Reserved1__SHIFT                      0x00000010
#define	NB_CFG_STAT__CLOCK_SPEED__SHIFT                    0x00000014
#define	NB_CFG_STAT__TYPE_DETECTED__SHIFT                  0x00000019
#define	NB_CFG_STAT__SYS_CLK_MUX__SHIFT                    0x0000001a
#define	NB_CFG_STAT__AGP_CLK_MUX__SHIFT                    0x0000001d

// NB_GC_STRAPS
#define	NB_GC_STRAPS__EXTGFX_ENABLE__SHIFT                 0x00000000
#define	NB_GC_STRAPS__INTGFX_ENABLE__SHIFT                 0x00000001
#define	NB_GC_STRAPS__VGA_DISABLE__SHIFT                   0x00000002
#define	NB_GC_STRAPS__ID_DISABLE__SHIFT                    0x00000003
#define	NB_GC_STRAPS__APERTURE_SIZE__SHIFT                 0x00000004
#define	NB_GC_STRAPS__MULTI_FUNC__SHIFT                    0x00000006
#define	NB_GC_STRAPS__BUSCFG__SHIFT                        0x00000008
#define	NB_GC_STRAPS__ENINTb__SHIFT                        0x0000000b
#define	NB_GC_STRAPS__FW_DISABLE__SHIFT                    0x0000000c
#define	NB_GC_STRAPS__EXT_MEM_EN__SHIFT                    0x0000000d
#define	NB_GC_STRAPS__BLANK_ROM__SHIFT                     0x0000000e
#define	NB_GC_STRAPS__ADDIN_CARD__SHIFT                    0x0000000f
#define	NB_GC_STRAPS__POWER_ON_STRAPS__SHIFT               0x00000010
#define	NB_GC_STRAPS__MOBILE__SHIFT                        0x0000001c
#define	NB_GC_STRAPS__VE__SHIFT                            0x0000001d
#define	NB_GC_STRAPS__CHG_ID__SHIFT                        0x0000001e

// NB_TOP_OF_DRAM_SLOT1
#define	NB_TOP_OF_DRAM_SLOT1__TOP_OF_DRAM_A5__SHIFT        0x00000017

// NB_AGP_CAP_ID
#define	NB_AGP_CAP_ID__CAP_ID__SHIFT                       0x00000000
#define	NB_AGP_CAP_ID__NEXT_PTR__SHIFT                     0x00000008
#define	NB_AGP_CAP_ID__AGP_MINOR__SHIFT                    0x00000010
#define	NB_AGP_CAP_ID__AGP_MAJOR__SHIFT                    0x00000014

// NB_AGP_STATUS
#define	NB_AGP_STATUS__RATE1X_4X__SHIFT                    0x00000000
#define	NB_AGP_STATUS__RATE2X_8X__SHIFT                    0x00000001
#define	NB_AGP_STATUS__RATE4X__SHIFT                       0x00000002
#define	NB_AGP_STATUS__MODE_AGP30__SHIFT                   0x00000003
#define	NB_AGP_STATUS__FW__SHIFT                           0x00000004
#define	NB_AGP_STATUS__R4G__SHIFT                          0x00000005
#define	NB_AGP_STATUS__HTRANSb__SHIFT                      0x00000006
#define	NB_AGP_STATUS__GART64B__SHIFT                      0x00000007
#define	NB_AGP_STATUS__ITA_COH__SHIFT                      0x00000008
#define	NB_AGP_STATUS__SBA__SHIFT                          0x00000009
#define	NB_AGP_STATUS__CAL_CYCLE__SHIFT                    0x0000000a
#define	NB_AGP_STATUS__ARQSZ__SHIFT                        0x0000000d
#define	NB_AGP_STATUS__ISOCH_SUPPORT__SHIFT                0x00000011
#define	NB_AGP_STATUS__RQ__SHIFT                           0x00000018

// NB_AGP_COMMAND
#define	NB_AGP_COMMAND__DATA_RATE__SHIFT                   0x00000000
#define	NB_AGP_COMMAND__FW_EN__SHIFT                       0x00000004
#define	NB_AGP_COMMAND__R4G_EN__SHIFT                      0x00000005
#define	NB_AGP_COMMAND__GART64B_EN__SHIFT                  0x00000007
#define	NB_AGP_COMMAND__AGP_EN__SHIFT                      0x00000008
#define	NB_AGP_COMMAND__SBA_EN__SHIFT                      0x00000009
#define	NB_AGP_COMMAND__PCAL_CYCLE__SHIFT                  0x0000000a

// NB_NISTAT
#define	NB_NISTAT__ISOCH_ERRCODE__SHIFT                    0x00000000
#define	NB_NISTAT__ISOCH_L__SHIFT                          0x00000003
#define	NB_NISTAT__ISOCH_Y__SHIFT                          0x00000006
#define	NB_NISTAT__ISOCH_N__SHIFT                          0x00000008
#define	NB_NISTAT__MAXBW__SHIFT                            0x00000010

// NB_AGPCTRL
#define	NB_AGPCTRL__RESERVED1__SHIFT                       0x00000000
#define	NB_AGPCTRL__GTLBEN__SHIFT                          0x00000007
#define	NB_AGPCTRL__APERENB__SHIFT                         0x00000008
#define	NB_AGPCTRL__CAL_CYCLE_DIS__SHIFT                   0x00000009
#define	NB_AGPCTRL__RESERVED2__SHIFT                       0x00000010

// NB_APSIZE
#define	NB_APSIZE__APSIZE__SHIFT                           0x00000000

// NB_NEPG
#define	NB_NEPG__NEPG_N__SHIFT                             0x00000000
#define	NB_NEPG__NEPG_SEL__SHIFT                           0x0000000c

// NB_GARTLO
#define	NB_GARTLO__BASELO__SHIFT                           0x0000000c

// NB_GARTHI
#define	NB_GARTHI__BASEHI__SHIFT                           0x00000000

// NB_NICMD
#define	NB_NICMD__PISOCH_Y__SHIFT                          0x00000006

// NB_PERF_CNT_CTRL
#define	NB_PERF_CNT_CTRL__GLOBE_CNT_EN__SHIFT              0x00000000
#define	NB_PERF_CNT_CTRL__GLOBE_SHADOW_WR__SHIFT           0x00000001

// NB_AGP_ADDRESS_SPACE_SIZE
#define	NB_AGP_ADDRESS_SPACE_SIZE__GART_EN__SHIFT          0x00000000
#define	NB_AGP_ADDRESS_SPACE_SIZE__VA_SIZE__SHIFT          0x00000001
#define	NB_AGP_ADDRESS_SPACE_SIZE__VGA_IA_EN__SHIFT        0x00000010

// NB_AGP_MODE_CONTROL
#define	NB_AGP_MODE_CONTROL__CPU_AGP_RD_WR_SYNC_EN__SHIFT  0x00000007
#define	NB_AGP_MODE_CONTROL__LV1_INDEX__SHIFT              0x00000010
#define	NB_AGP_MODE_CONTROL__PDC_EN__SHIFT                 0x00000011
#define	NB_AGP_MODE_CONTROL__POST_GART_Q_SIZE__SHIFT       0x00000012
#define	NB_AGP_MODE_CONTROL__NONGART_SNOOP__SHIFT          0x00000013
#define	NB_AGP_MODE_CONTROL__AGP_RD_BUF_SIZE__SHIFT        0x00000014

// NB_MEM_IO_CNTL_0
#define	NB_MEM_IO_CNTL_0__MEM_N_CKA__SHIFT                 0x00000000
#define	NB_MEM_IO_CNTL_0__MEM_N_AA__SHIFT                  0x00000005
#define	NB_MEM_IO_CNTL_0__MEM_N_DQMA__SHIFT                0x0000000a
#define	NB_MEM_IO_CNTL_0__MEM_N_DQSA__SHIFT                0x0000000f

// NB_MEM_IO_CNTL_1
#define	NB_MEM_IO_CNTL_1__MEM_P_CKA__SHIFT                 0x00000000
#define	NB_MEM_IO_CNTL_1__MEM_P_AA__SHIFT                  0x00000005
#define	NB_MEM_IO_CNTL_1__MEM_P_DQMA__SHIFT                0x0000000a
#define	NB_MEM_IO_CNTL_1__MEM_P_DQSA__SHIFT                0x0000000f
#define	NB_MEM_IO_CNTL_1__CLKA_ENABLE__SHIFT               0x00000016
#define	NB_MEM_IO_CNTL_1__Reserved__SHIFT                  0x00000017

// NB_MEM_SDRAM_MODE_REG
#define	NB_MEM_SDRAM_MODE_REG__MEM_MODE_REG_A5__SHIFT      0x00000000
#define	NB_MEM_SDRAM_MODE_REG__Reserved0_A5__SHIFT         0x00000010
#define	NB_MEM_SDRAM_MODE_REG__MEM_CAS_LATENCY__SHIFT      0x00000014
#define	NB_MEM_SDRAM_MODE_REG__Reserved1__SHIFT            0x00000017
#define	NB_MEM_SDRAM_MODE_REG__MC_INIT_COMPLETE__SHIFT     0x0000001c
#define	NB_MEM_SDRAM_MODE_REG__Reserved2_A5__SHIFT         0x0000001d
#define	NB_MEM_SDRAM_MODE_REG__MEM_SDRAM_RESET__SHIFT      0x0000001f

// NB_MEM_IO_CNTL_B0
#define	NB_MEM_IO_CNTL_B0__MEM_N_CKB__SHIFT                0x00000000
#define	NB_MEM_IO_CNTL_B0__MEM_N_AB__SHIFT                 0x00000005
#define	NB_MEM_IO_CNTL_B0__MEM_N_DQMB__SHIFT               0x0000000a
#define	NB_MEM_IO_CNTL_B0__MEM_N_DQSB__SHIFT               0x0000000f

// NB_MEM_IO_CNTL_B1
#define	NB_MEM_IO_CNTL_B1__MEM_P_CKB__SHIFT                0x00000000
#define	NB_MEM_IO_CNTL_B1__MEM_P_AB__SHIFT                 0x00000005
#define	NB_MEM_IO_CNTL_B1__MEM_P_DQMB__SHIFT               0x0000000a
#define	NB_MEM_IO_CNTL_B1__MEM_P_DQSB__SHIFT               0x0000000f
#define	NB_MEM_IO_CNTL_B1__CLKB_ENABLE__SHIFT              0x00000016

// NB_MC_INDEX
#define	NB_MC_INDEX__NB_MC_IND_ADDR__SHIFT                 0x00000000
#define	NB_MC_INDEX__NB_MC_IND_WR_EN__SHIFT                0x00000008

// NB_MC_DATA
#define	NB_MC_DATA__NBMC_DATA__SHIFT                       0x00000000

// MC_GENERAL_PURPOSE
#define	MC_GENERAL_PURPOSE__MEM_AIC_CONT_REQ_G1__SHIFT     0x00000000
#define	MC_GENERAL_PURPOSE__MEM_AIC_CONT_REQ_G2__SHIFT     0x00000004
#define	MC_GENERAL_PURPOSE__MEM_GART_SYNCHRO_FIFO__SHIFT   0x00000008
#define	MC_GENERAL_PURPOSE__MEM_GART_2DW__SHIFT            0x00000009
#define	MC_GENERAL_PURPOSE__MEM_CLOCK_MUX__SHIFT           0x0000000a
#define	MC_GENERAL_PURPOSE__MEM_DEBUG_GP_RW__SHIFT         0x0000000b
#define	MC_GENERAL_PURPOSE__MEM_PLL_VCO_MODE_PM__SHIFT     0x00000014
#define	MC_GENERAL_PURPOSE__MEM_PLL_DIV_8_16_PM__SHIFT     0x00000016
#define	MC_GENERAL_PURPOSE__MEM_PLL_DLL_EN__SHIFT          0x00000017
#define	MC_GENERAL_PURPOSE__MEM_PLL_IN_DLYX_DQS_RB__SHIFT  0x00000018
#define	MC_GENERAL_PURPOSE__MEM_PLL_VCO_MODE_RB__SHIFT     0x0000001c
#define	MC_GENERAL_PURPOSE__MEM_PLL_PHD_DN_RB__SHIFT       0x0000001e
#define	MC_GENERAL_PURPOSE__MEM_PLL_PHD_UP_RB__SHIFT       0x0000001f

// MC_IN_TIMING_A
#define	MC_IN_TIMING_A__MEMA_DQS_RESET__SHIFT              0x00000000
#define	MC_IN_TIMING_A__MEMA_DQ_TRANSFER__SHIFT            0x00000004
#define	MC_IN_TIMING_A__MEMA_DQ_RECEIVER_DYNAMIC__SHIFT    0x00000008
#define	MC_IN_TIMING_A__MEMA_DQS_RECEIVER_DYNAMIC__SHIFT   0x00000009
#define	MC_IN_TIMING_A__MEMA_STAGE_BYPASS__SHIFT           0x0000000a
#define	MC_IN_TIMING_A__MEMA_POWERED_UP__SHIFT             0x0000000c
#define	MC_IN_TIMING_A__MEMA_TRISTATE_ALL__SHIFT           0x0000000d
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_LOCK__SHIFT         0x0000000f
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS0__SHIFT     0x00000010
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS1__SHIFT     0x00000011
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS2__SHIFT     0x00000012
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS3__SHIFT     0x00000013
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS4__SHIFT     0x00000014
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS5__SHIFT     0x00000015
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS6__SHIFT     0x00000016
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS7__SHIFT     0x00000017
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS0__SHIFT     0x00000018
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS1__SHIFT     0x00000019
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS2__SHIFT     0x0000001a
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS3__SHIFT     0x0000001b
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS4__SHIFT     0x0000001c
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS5__SHIFT     0x0000001d
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS6__SHIFT     0x0000001e
#define	MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS7__SHIFT     0x0000001f

// MC_OUT_TIMING_A
#define	MC_OUT_TIMING_A__MEMA_CK_SELECTION__SHIFT          0x00000000
#define	MC_OUT_TIMING_A__MEMA_DQS_SELECTION__SHIFT         0x00000008
#define	MC_OUT_TIMING_A__MEMA_OUT_TIMING_CK__SHIFT         0x00000010
#define	MC_OUT_TIMING_A__MEMA_OUT_TIMING_CMD__SHIFT        0x00000014
#define	MC_OUT_TIMING_A__MEMA_OUT_TIMING_DQ__SHIFT         0x00000018
#define	MC_OUT_TIMING_A__MEMA_OUT_TIMING_DQS__SHIFT        0x0000001c

// MC_OUT_DELAY1_A
#define	MC_OUT_DELAY1_A__MEMA_DQ_DQS_OE_START__SHIFT       0x00000000
#define	MC_OUT_DELAY1_A__MEMA_DQ_DQS_OE_STOP__SHIFT        0x00000002
#define	MC_OUT_DELAY1_A__MEMA_VIRT_TERM_DQ__SHIFT          0x00000004
#define	MC_OUT_DELAY1_A__MEMA_VIRT_TERM_DQS__SHIFT         0x00000006
#define	MC_OUT_DELAY1_A__MEMA_BOUNCE_N_CK__SHIFT           0x00000008
#define	MC_OUT_DELAY1_A__MEMA_BOUNCE_P_CK__SHIFT           0x00000009
#define	MC_OUT_DELAY1_A__MEMA_BOUNCE_N_CMD__SHIFT          0x0000000a
#define	MC_OUT_DELAY1_A__MEMA_BOUNCE_P_CMD__SHIFT          0x0000000b
#define	MC_OUT_DELAY1_A__MEMA_BOUNCE_N_DQ__SHIFT           0x0000000c
#define	MC_OUT_DELAY1_A__MEMA_BOUNCE_P_DQ__SHIFT           0x0000000d
#define	MC_OUT_DELAY1_A__MEMA_BOUNCE_N_DQS__SHIFT          0x0000000e
#define	MC_OUT_DELAY1_A__MEMA_BOUNCE_P_DQS__SHIFT          0x0000000f
#define	MC_OUT_DELAY1_A__MEMA_OUT_DELAY_CK0__SHIFT         0x00000010
#define	MC_OUT_DELAY1_A__MEMA_OUT_DELAY_CK1__SHIFT         0x00000012
#define	MC_OUT_DELAY1_A__MEMA_OUT_DELAY_CK2__SHIFT         0x00000014
#define	MC_OUT_DELAY1_A__MEMA_OUT_DELAY_CK3__SHIFT         0x00000016
#define	MC_OUT_DELAY1_A__MEMA_OUT_DELAY_CK4__SHIFT         0x00000018
#define	MC_OUT_DELAY1_A__MEMA_OUT_DELAY_CK5__SHIFT         0x0000001a
#define	MC_OUT_DELAY1_A__MEMA_OUT_DELAY_CMD__SHIFT         0x0000001c

// MC_OUT_DELAY2_A
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE0__SHIFT    0x00000000
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE1__SHIFT    0x00000002
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE2__SHIFT    0x00000004
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE3__SHIFT    0x00000006
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE4__SHIFT    0x00000008
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE5__SHIFT    0x0000000a
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE6__SHIFT    0x0000000c
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE7__SHIFT    0x0000000e
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS0__SHIFT        0x00000010
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS1__SHIFT        0x00000012
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS2__SHIFT        0x00000014
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS3__SHIFT        0x00000016
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS4__SHIFT        0x00000018
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS5__SHIFT        0x0000001a
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS6__SHIFT        0x0000001c
#define	MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS7__SHIFT        0x0000001e

// MC_IN_DELAY1_A
#define	MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE0__SHIFT      0x00000000
#define	MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE1__SHIFT      0x00000004
#define	MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE2__SHIFT      0x00000008
#define	MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE3__SHIFT      0x0000000c
#define	MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE4__SHIFT      0x00000010
#define	MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE5__SHIFT      0x00000014
#define	MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE6__SHIFT      0x00000018
#define	MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE7__SHIFT      0x0000001c

// MC_IN_DELAY2_A
#define	MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS0__SHIFT          0x00000000
#define	MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS1__SHIFT          0x00000004
#define	MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS2__SHIFT          0x00000008
#define	MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS3__SHIFT          0x0000000c
#define	MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS4__SHIFT          0x00000010
#define	MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS5__SHIFT          0x00000014
#define	MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS6__SHIFT          0x00000018
#define	MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS7__SHIFT          0x0000001c

// MC_IN_DELAY3_A
#define	MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS0__SHIFT         0x00000000
#define	MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS1__SHIFT         0x00000004
#define	MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS2__SHIFT         0x00000008
#define	MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS3__SHIFT         0x0000000c
#define	MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS4__SHIFT         0x00000010
#define	MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS5__SHIFT         0x00000014
#define	MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS6__SHIFT         0x00000018
#define	MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS7__SHIFT         0x0000001c

// MC_IN_TIMING_B
#define	MC_IN_TIMING_B__MEMB_DQS_RESET__SHIFT              0x00000000
#define	MC_IN_TIMING_B__MEMB_DQ_TRANSFER__SHIFT            0x00000004
#define	MC_IN_TIMING_B__MEMB_DQ_RECEIVER_DYNAMIC__SHIFT    0x00000008
#define	MC_IN_TIMING_B__MEMB_DQS_RECEIVER_DYNAMIC__SHIFT   0x00000009
#define	MC_IN_TIMING_B__MEMB_STAGE_BYPASS__SHIFT           0x0000000a
#define	MC_IN_TIMING_B__MEMB_POWERED_UP__SHIFT             0x0000000c
#define	MC_IN_TIMING_B__MEMB_TRISTATE_ALL__SHIFT           0x0000000d
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_LOCK__SHIFT         0x0000000f
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS0__SHIFT     0x00000010
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS1__SHIFT     0x00000011
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS2__SHIFT     0x00000012
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS3__SHIFT     0x00000013
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS4__SHIFT     0x00000014
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS5__SHIFT     0x00000015
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS6__SHIFT     0x00000016
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS7__SHIFT     0x00000017
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS0__SHIFT     0x00000018
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS1__SHIFT     0x00000019
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS2__SHIFT     0x0000001a
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS3__SHIFT     0x0000001b
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS4__SHIFT     0x0000001c
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS5__SHIFT     0x0000001d
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS6__SHIFT     0x0000001e
#define	MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS7__SHIFT     0x0000001f

// MC_OUT_TIMING_B
#define	MC_OUT_TIMING_B__MEMB_CK_SELECTION__SHIFT          0x00000000
#define	MC_OUT_TIMING_B__MEMB_DQS_SELECTION__SHIFT         0x00000008
#define	MC_OUT_TIMING_B__MEMB_OUT_TIMING_CK__SHIFT         0x00000010
#define	MC_OUT_TIMING_B__MEMB_OUT_TIMING_CMD__SHIFT        0x00000014
#define	MC_OUT_TIMING_B__MEMB_OUT_TIMING_DQ__SHIFT         0x00000018
#define	MC_OUT_TIMING_B__MEMB_OUT_TIMING_DQS__SHIFT        0x0000001c

// MC_OUT_DELAY1_B
#define	MC_OUT_DELAY1_B__MEMB_DQ_DQS_OE_START__SHIFT       0x00000000
#define	MC_OUT_DELAY1_B__MEMB_DQ_DQS_OE_STOP__SHIFT        0x00000002
#define	MC_OUT_DELAY1_B__MEMB_VIRT_TERM_DQ__SHIFT          0x00000004
#define	MC_OUT_DELAY1_B__MEMB_VIRT_TERM_DQS__SHIFT         0x00000006
#define	MC_OUT_DELAY1_B__MEMB_BOUNCE_N_CK__SHIFT           0x00000008
#define	MC_OUT_DELAY1_B__MEMB_BOUNCE_P_CK__SHIFT           0x00000009
#define	MC_OUT_DELAY1_B__MEMB_BOUNCE_N_CMD__SHIFT          0x0000000a
#define	MC_OUT_DELAY1_B__MEMB_BOUNCE_P_CMD__SHIFT          0x0000000b
#define	MC_OUT_DELAY1_B__MEMB_BOUNCE_N_DQ__SHIFT           0x0000000c
#define	MC_OUT_DELAY1_B__MEMB_BOUNCE_P_DQ__SHIFT           0x0000000d
#define	MC_OUT_DELAY1_B__MEMB_BOUNCE_N_DQS__SHIFT          0x0000000e
#define	MC_OUT_DELAY1_B__MEMB_BOUNCE_P_DQS__SHIFT          0x0000000f
#define	MC_OUT_DELAY1_B__MEMB_OUT_DELAY_CK0__SHIFT         0x00000010
#define	MC_OUT_DELAY1_B__MEMB_OUT_DELAY_CK1__SHIFT         0x00000012
#define	MC_OUT_DELAY1_B__MEMB_OUT_DELAY_CK2__SHIFT         0x00000014
#define	MC_OUT_DELAY1_B__MEMB_OUT_DELAY_CK3__SHIFT         0x00000016
#define	MC_OUT_DELAY1_B__MEMB_OUT_DELAY_CK4__SHIFT         0x00000018
#define	MC_OUT_DELAY1_B__MEMB_OUT_DELAY_CK5__SHIFT         0x0000001a
#define	MC_OUT_DELAY1_B__MEMB_OUT_DELAY_CMD__SHIFT         0x0000001c

// MC_OUT_DELAY2_B
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE0__SHIFT    0x00000000
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE1__SHIFT    0x00000002
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE2__SHIFT    0x00000004
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE3__SHIFT    0x00000006
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE4__SHIFT    0x00000008
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE5__SHIFT    0x0000000a
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE6__SHIFT    0x0000000c
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE7__SHIFT    0x0000000e
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS0__SHIFT        0x00000010
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS1__SHIFT        0x00000012
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS2__SHIFT        0x00000014
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS3__SHIFT        0x00000016
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS4__SHIFT        0x00000018
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS5__SHIFT        0x0000001a
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS6__SHIFT        0x0000001c
#define	MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS7__SHIFT        0x0000001e

// MC_IN_DELAY1_B
#define	MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE0__SHIFT      0x00000000
#define	MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE1__SHIFT      0x00000004
#define	MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE2__SHIFT      0x00000008
#define	MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE3__SHIFT      0x0000000c
#define	MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE4__SHIFT      0x00000010
#define	MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE5__SHIFT      0x00000014
#define	MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE6__SHIFT      0x00000018
#define	MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE7__SHIFT      0x0000001c

// MC_IN_DELAY2_B
#define	MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS0__SHIFT          0x00000000
#define	MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS1__SHIFT          0x00000004
#define	MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS2__SHIFT          0x00000008
#define	MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS3__SHIFT          0x0000000c
#define	MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS4__SHIFT          0x00000010
#define	MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS5__SHIFT          0x00000014
#define	MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS6__SHIFT          0x00000018
#define	MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS7__SHIFT          0x0000001c

// MC_IN_DELAY3_B
#define	MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS0__SHIFT         0x00000000
#define	MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS1__SHIFT         0x00000004
#define	MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS2__SHIFT         0x00000008
#define	MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS3__SHIFT         0x0000000c
#define	MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS4__SHIFT         0x00000010
#define	MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS5__SHIFT         0x00000014
#define	MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS6__SHIFT         0x00000018
#define	MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS7__SHIFT         0x0000001c

// MC_PLL_IO_CNTL
#define	MC_PLL_IO_CNTL__MEM_PLL_PWRDN__SHIFT               0x00000000
#define	MC_PLL_IO_CNTL__MEM_PLL_BYPASS__SHIFT              0x00000001
#define	MC_PLL_IO_CNTL__MEM_PLL_SKEW_1X__SHIFT             0x00000002
#define	MC_PLL_IO_CNTL__MEM_PLL_SKEW_2X__SHIFT             0x00000004
#define	MC_PLL_IO_CNTL__MEM_PLL_SKEW_4X__SHIFT             0x00000006
#define	MC_PLL_IO_CNTL__MEM_PLL_REF_DELAY__SHIFT           0x00000008
#define	MC_PLL_IO_CNTL__MEM_PLL_VCO_DELAY__SHIFT           0x0000000a
#define	MC_PLL_IO_CNTL__MEM_PLL_VCO_VREF__SHIFT            0x0000000c
#define	MC_PLL_IO_CNTL__MEM_PLL_CAL_VREF__SHIFT            0x00000010
#define	MC_PLL_IO_CNTL__MEM_PLL_CHPUMP_CURRENT__SHIFT      0x00000014
#define	MC_PLL_IO_CNTL__MEM_PLL_CHPUMP_BANDWIDTH__SHIFT    0x00000016
#define	MC_PLL_IO_CNTL__MEM_PLL_VCO_BANDWIDTH__SHIFT       0x00000017
#define	MC_PLL_IO_CNTL__MEM_PLL_VCO_MODE__SHIFT            0x00000018
#define	MC_PLL_IO_CNTL__MEM_PLL_DIV_8_16__SHIFT            0x0000001a
#define	MC_PLL_IO_CNTL__MEM_PLL_VREF_REG__SHIFT            0x0000001b
#define	MC_PLL_IO_CNTL__MEM_PLL_CONTROL__SHIFT             0x0000001c

// MC_IMP_CTRL_SETTING
#define	MC_IMP_CTRL_SETTING__MEM_IC_UPDATE_RATE__SHIFT     0x00000000
#define	MC_IMP_CTRL_SETTING__MEM_IC_SAMPLE_RATE__SHIFT     0x00000008
#define	MC_IMP_CTRL_SETTING__MEM_IC_SAMPLE_SETTLE__SHIFT   0x00000010
#define	MC_IMP_CTRL_SETTING__MEM_IC_INC_THRESHOLD__SHIFT   0x00000014
#define	MC_IMP_CTRL_SETTING__MEM_IC_DEC_THRESHOLD__SHIFT   0x00000018
#define	MC_IMP_CTRL_SETTING__MEM_IC_OSC__SHIFT             0x0000001c
#define	MC_IMP_CTRL_SETTING__MEM_IC_ENABLE__SHIFT          0x0000001f

// MC_IMP_CTRL_REF
#define	MC_IMP_CTRL_REF__MEM_STRENGTH_N_REF__SHIFT         0x00000000
#define	MC_IMP_CTRL_REF__MEM_STRENGTH_P_REF__SHIFT         0x00000004
#define	MC_IMP_CTRL_REF__MEM_READ_BACK_N_REF__SHIFT        0x00000008
#define	MC_IMP_CTRL_REF__MEM_READ_BACK_P_REF__SHIFT        0x0000000c
#define	MC_IMP_CTRL_REF__MEM_DEBUG_IC_RW__SHIFT            0x00000010

// MC_IMP_CTRL_STRENGTH_A
#define	MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_N_CK__SHIFT  0x00000000
#define	MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_N_CMD__SHIFT 0x00000004
#define	MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_N_DQ__SHIFT  0x00000008
#define	MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_N_DQS__SHIFT 0x0000000c
#define	MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_P_CK__SHIFT  0x00000010
#define	MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_P_CMD__SHIFT 0x00000014
#define	MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_P_DQ__SHIFT  0x00000018
#define	MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_P_DQS__SHIFT 0x0000001c

// MC_IMP_CTRL_STEP_A
#define	MC_IMP_CTRL_STEP_A__MEMA_STEP_N_CK__SHIFT          0x00000000
#define	MC_IMP_CTRL_STEP_A__MEMA_STEP_N_CMD__SHIFT         0x00000004
#define	MC_IMP_CTRL_STEP_A__MEMA_STEP_N_DQ__SHIFT          0x00000008
#define	MC_IMP_CTRL_STEP_A__MEMA_STEP_N_DQS__SHIFT         0x0000000c
#define	MC_IMP_CTRL_STEP_A__MEMA_STEP_P_CK__SHIFT          0x00000010
#define	MC_IMP_CTRL_STEP_A__MEMA_STEP_P_CMD__SHIFT         0x00000014
#define	MC_IMP_CTRL_STEP_A__MEMA_STEP_P_DQ__SHIFT          0x00000018
#define	MC_IMP_CTRL_STEP_A__MEMA_STEP_P_DQS__SHIFT         0x0000001c

// MC_IMP_CTRL_READ_BACK_A
#define	MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_N_CK__SHIFT 0x00000000
#define	MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_N_CMD__SHIFT 0x00000004
#define	MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_N_DQ__SHIFT 0x00000008
#define	MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_N_DQS__SHIFT 0x0000000c
#define	MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_P_CK__SHIFT 0x00000010
#define	MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_P_CMD__SHIFT 0x00000014
#define	MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_P_DQ__SHIFT 0x00000018
#define	MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_P_DQS__SHIFT 0x0000001c

// MC_IMP_CTRL_STRENGTH_B
#define	MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_N_CK__SHIFT  0x00000000
#define	MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_N_CMD__SHIFT 0x00000004
#define	MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_N_DQ__SHIFT  0x00000008
#define	MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_N_DQS__SHIFT 0x0000000c
#define	MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_P_CK__SHIFT  0x00000010
#define	MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_P_CMD__SHIFT 0x00000014
#define	MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_P_DQ__SHIFT  0x00000018
#define	MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_P_DQS__SHIFT 0x0000001c

// MC_IMP_CTRL_STEP_B
#define	MC_IMP_CTRL_STEP_B__MEMB_STEP_N_CK__SHIFT          0x00000000
#define	MC_IMP_CTRL_STEP_B__MEMB_STEP_N_CMD__SHIFT         0x00000004
#define	MC_IMP_CTRL_STEP_B__MEMB_STEP_N_DQ__SHIFT          0x00000008
#define	MC_IMP_CTRL_STEP_B__MEMB_STEP_N_DQS__SHIFT         0x0000000c
#define	MC_IMP_CTRL_STEP_B__MEMB_STEP_P_CK__SHIFT          0x00000010
#define	MC_IMP_CTRL_STEP_B__MEMB_STEP_P_CMD__SHIFT         0x00000014
#define	MC_IMP_CTRL_STEP_B__MEMB_STEP_P_DQ__SHIFT          0x00000018
#define	MC_IMP_CTRL_STEP_B__MEMB_STEP_P_DQS__SHIFT         0x0000001c

// MC_IMP_CTRL_READ_BACK_B
#define	MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_N_CK__SHIFT 0x00000000
#define	MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_N_CMD__SHIFT 0x00000004
#define	MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_N_DQ__SHIFT 0x00000008
#define	MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_N_DQS__SHIFT 0x0000000c
#define	MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_P_CK__SHIFT 0x00000010
#define	MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_P_CMD__SHIFT 0x00000014
#define	MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_P_DQ__SHIFT 0x00000018
#define	MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_P_DQS__SHIFT 0x0000001c

// MC_MISC_CNTL
#define	MC_MISC_CNTL__MRA_ARB_RATIOONLY__SHIFT             0x00000000
#define	MC_MISC_CNTL__DISABLE_GTW__SHIFT                   0x00000001
#define	MC_MISC_CNTL__MRA_ARB_BIURATIO__SHIFT              0x00000002
#define	MC_MISC_CNTL__MRA_ARB_AGPRATIO__SHIFT              0x00000004
#define	MC_MISC_CNTL__SEQUENTIAL_REFRESH__SHIFT            0x00000006
#define	MC_MISC_CNTL__PM_SEQUENTIAL_REFRESH__SHIFT         0x00000007
#define	MC_MISC_CNTL__SQBYPASS_TIMER__SHIFT                0x00000008
#define	MC_MISC_CNTL__GTW_LAC_EN__SHIFT                    0x0000000c
#define	MC_MISC_CNTL__RBB_MRA_AGPBIU_COHERENCY_DISABLE__SHIFT 0x0000000d
#define	MC_MISC_CNTL__INPUT_AGPHIPRI_MUTE__SHIFT           0x0000000e
#define	MC_MISC_CNTL__EXT_GC_LATENCY_TIMER__SHIFT          0x0000000f
#define	MC_MISC_CNTL__DIS_BYPASS_LOAD__SHIFT               0x00000010
#define	MC_MISC_CNTL__DISP2_HiPri__SHIFT                   0x00000011
#define	MC_MISC_CNTL__DISP2_HiPri2__SHIFT                  0x00000012
#define	MC_MISC_CNTL__Reserved__SHIFT                      0x00000014
#define	MC_MISC_CNTL__SB_BLOCK_AGP_DIS__SHIFT              0x00000018
#define	MC_MISC_CNTL__DISABLE_EXTRA_DECK_STAGES__SHIFT     0x00000019
#define	MC_MISC_CNTL__SQSM_PERF_FIX__SHIFT                 0x0000001a
#define	MC_MISC_CNTL__SEQ_RFSH_RESET_TRC_EN__SHIFT         0x0000001b
#define	MC_MISC_CNTL__BANK_ADDR_REMAP_EN__SHIFT            0x0000001c
#define	MC_MISC_CNTL__BANK_ALIGN_MODE__SHIFT               0x0000001d
#define	MC_MISC_CNTL__DEBUGBUS_CYCLE_EN__SHIFT             0x0000001f

// NB_MC_TEST_DEBUG
#define	NB_MC_TEST_DEBUG__NB_MC_DEBUG_BITS__SHIFT          0x00000000

// NB_MEM_SIZE_A
#define	NB_MEM_SIZE_A__CS0_SIZE__SHIFT                     0x00000000
#define	NB_MEM_SIZE_A__CS0_AP_MAP__SHIFT                   0x00000004
#define	NB_MEM_SIZE_A__CS1_SIZE__SHIFT                     0x00000008
#define	NB_MEM_SIZE_A__CS1_AP_MAP__SHIFT                   0x0000000c
#define	NB_MEM_SIZE_A__CS2_SIZE__SHIFT                     0x00000010
#define	NB_MEM_SIZE_A__CS2_AP_MAP__SHIFT                   0x00000014
#define	NB_MEM_SIZE_A__CS3_SIZE__SHIFT                     0x00000018
#define	NB_MEM_SIZE_A__CS3_AP_MAP__SHIFT                   0x0000001c

// NB_MEM_SIZE_B
#define	NB_MEM_SIZE_B__CS0_SIZE__SHIFT                     0x00000000
#define	NB_MEM_SIZE_B__CS0_AP_MAP__SHIFT                   0x00000004
#define	NB_MEM_SIZE_B__CS1_SIZE__SHIFT                     0x00000008
#define	NB_MEM_SIZE_B__CS1_AP_MAP__SHIFT                   0x0000000c
#define	NB_MEM_SIZE_B__CS2_SIZE__SHIFT                     0x00000010
#define	NB_MEM_SIZE_B__CS2_AP_MAP__SHIFT                   0x00000014
#define	NB_MEM_SIZE_B__CS3_SIZE__SHIFT                     0x00000018
#define	NB_MEM_SIZE_B__CS3_AP_MAP__SHIFT                   0x0000001c

// NB_MEM_CNTL0
#define	NB_MEM_CNTL0__INTERLEAVE_MODE__SHIFT               0x00000000
#define	NB_MEM_CNTL0__PRIMARY_CHANNEL__SHIFT               0x00000002
#define	NB_MEM_CNTL0__NUMBER_CHANNEL__SHIFT                0x00000003
#define	NB_MEM_CNTL0__CHANNEL_MAPPING_NB__SHIFT            0x00000004
#define	NB_MEM_CNTL0__CHANNEL_MAPPING_GFX__SHIFT           0x00000006
#define	NB_MEM_CNTL0__INTERLEAVE_START__SHIFT              0x00000018

// NB_EXT_MEM_CNTL
#define	NB_EXT_MEM_CNTL__MEM_TRP__SHIFT                    0x00000000
#define	NB_EXT_MEM_CNTL__MEM_TRCD__SHIFT                   0x00000002
#define	NB_EXT_MEM_CNTL__MEM_TRAS__SHIFT                   0x00000004
#define	NB_EXT_MEM_CNTL__MEM_TRRD__SHIFT                   0x00000008
#define	NB_EXT_MEM_CNTL__MEM_TR2W__SHIFT                   0x0000000a
#define	NB_EXT_MEM_CNTL__MEM_TWR__SHIFT                    0x0000000c
#define	NB_EXT_MEM_CNTL__MEM_TW2R__SHIFT                   0x0000000e
#define	NB_EXT_MEM_CNTL__MEM_TR2R__SHIFT                   0x00000010
#define	NB_EXT_MEM_CNTL__MEM_TWR_MODE__SHIFT               0x00000012
#define	NB_EXT_MEM_CNTL__MEM_REFRESH_DIS__SHIFT            0x00000014
#define	NB_EXT_MEM_CNTL__MEM_REFRESH_COUNT__SHIFT          0x00000015
#define	NB_EXT_MEM_CNTL__MEM_REFRESH_RATE__SHIFT           0x00000018

// NB_FB_LOCATION
#define	NB_FB_LOCATION__MC_FB_START__SHIFT                 0x00000000
#define	NB_FB_LOCATION__MC_FB_TOP__SHIFT                   0x00000010

// NB_MC_DEBUG
#define	NB_MC_DEBUG__Reserved0__SHIFT                      0x00000000
#define	NB_MC_DEBUG__SEQ_HOLE_DIS__SHIFT                   0x00000001
#define	NB_MC_DEBUG__DISABLE_AP__SHIFT                     0x00000002
#define	NB_MC_DEBUG__RBS_STALL_FIFO__SHIFT                 0x00000003
#define	NB_MC_DEBUG__Reserved1__SHIFT                      0x00000004
#define	NB_MC_DEBUG__DLL_DISABLE_PM__SHIFT                 0x00000005
#define	NB_MC_DEBUG__FB_ACCESS_EN__SHIFT                   0x00000006
#define	NB_MC_DEBUG__ASYN_ONE__SHIFT                       0x00000007
#define	NB_MC_DEBUG__NC_DEBUG_MUX__SHIFT                   0x00000008
#define	NB_MC_DEBUG__MC_DEBUG_EN__SHIFT                    0x0000000f
#define	NB_MC_DEBUG__TESTBUS_INT__SHIFT                    0x00000010

// MC0_PERF_COUNT0
#define	MC0_PERF_COUNT0__COUNTER0__SHIFT                   0x00000000

// MC0_PERF_COUNT1
#define	MC0_PERF_COUNT1__COUNTER1__SHIFT                   0x00000000

// MC0_PERF_CNTL
#define	MC0_PERF_CNTL__EVENT0_SEL__SHIFT                   0x00000000
#define	MC0_PERF_CNTL__EVENT1_SEL__SHIFT                   0x00000008
#define	MC0_PERF_CNTL__COUNTER0_UPPER__SHIFT               0x00000010
#define	MC0_PERF_CNTL__COUNTER1_UPPER__SHIFT               0x00000018

// MC1_PERF_COUNT0
#define	MC1_PERF_COUNT0__COUNTER0__SHIFT                   0x00000000

// MC1_PERF_COUNT1
#define	MC1_PERF_COUNT1__COUNTER1__SHIFT                   0x00000000

// MC1_PERF_CNTL
#define	MC1_PERF_CNTL__EVENT0_SEL__SHIFT                   0x00000000
#define	MC1_PERF_CNTL__EVENT1_SEL__SHIFT                   0x00000008
#define	MC1_PERF_CNTL__COUNTER0_UPPER__SHIFT               0x00000010
#define	MC1_PERF_CNTL__COUNTER1_UPPER__SHIFT               0x00000018

// MC_PM_CNTL
#define	MC_PM_CNTL__AUTO_CLOCK_THROTTLING__SHIFT           0x00000000
#define	MC_PM_CNTL__CLOCK_THROTTLING_EN__SHIFT             0x00000001
#define	MC_PM_CNTL__THROTTLE_STATE_SETTING__SHIFT          0x00000002
#define	MC_PM_CNTL__AUTO_CLOCK_THROTTLING_NB__SHIFT        0x00000004
#define	MC_PM_CNTL__CLOCK_THROTTLING_EN_NB__SHIFT          0x00000005
#define	MC_PM_CNTL__THROTTLE_STATE_SETTING_NB__SHIFT       0x00000006
#define	MC_PM_CNTL__BLACKOUT_NB_DELAY__SHIFT               0x00000008
#define	MC_PM_CNTL__PM_MEM_REFRESH_COUNT__SHIFT            0x0000000c
#define	MC_PM_CNTL__PM_MEM_REFRESH_RATE__SHIFT             0x00000010
#define	MC_PM_CNTL__THROTTLE_READ_EN__SHIFT                0x00000018
#define	MC_PM_CNTL__THROTTLE_WRITE_EN__SHIFT               0x00000019
#define	MC_PM_CNTL__THROTTLE_DISP_EN__SHIFT                0x0000001a
#define	MC_PM_CNTL__MULTIPLE_CKE__SHIFT                    0x0000001b

// BIU_PERF_COUNT0_mc
#define	BIU_PERF_COUNT0_mc__COUNTER0__SHIFT                0x00000000

// BIU_PERF_COUNT1_mc
#define	BIU_PERF_COUNT1_mc__COUNTER1__SHIFT                0x00000000

// BIU_PERF_CNTL_mc
#define	BIU_PERF_CNTL_mc__EVENT0_SEL__SHIFT                0x00000000
#define	BIU_PERF_CNTL_mc__EVENT1_SEL__SHIFT                0x00000008
#define	BIU_PERF_CNTL_mc__COUNTER0_UPPER__SHIFT            0x00000010
#define	BIU_PERF_CNTL_mc__COUNTER1_UPPER__SHIFT            0x00000018

// PM_MEM_SDRAM_EXTENDED_MODE_REG
#define	PM_MEM_SDRAM_EXTENDED_MODE_REG__PM_MEM_EXTENDED_MODE_REG__SHIFT 0x00000000
#define	PM_MEM_SDRAM_EXTENDED_MODE_REG__RESERVE0__SHIFT    0x00000010
#define	PM_MEM_SDRAM_EXTENDED_MODE_REG__PM_EMRS_EN__SHIFT  0x0000001f

// NB_MC_STATUS
#define	NB_MC_STATUS__MEM_PWRUP_COMPL_A__SHIFT             0x00000000
#define	NB_MC_STATUS__MEM_PWRUP_COMPL_B__SHIFT             0x00000001
#define	NB_MC_STATUS__MC_IDLE__SHIFT                       0x00000002
#define	NB_MC_STATUS__NB_IDLE__SHIFT                       0x00000003
#define	NB_MC_STATUS__SYSM_IDLE__SHIFT                     0x00000010
#define	NB_MC_STATUS__SYSM_SHUTDOWN__SHIFT                 0x00000011
#define	NB_MC_STATUS__SYSM_PARKED__SHIFT                   0x00000012
#define	NB_MC_STATUS__DLL_READY__SHIFT                     0x00000013

// NB_CPU_AUTOCAL_VAL
#define	NB_CPU_AUTOCAL_VAL__CPU_AUTOCAL_VAL_P__SHIFT       0x00000000
#define	NB_CPU_AUTOCAL_VAL__CPU_AUTOCAL_VAL_N_A5__SHIFT    0x00000008

// NB_BIU_DBF
#define	NB_BIU_DBF__DBF_EN_BIU__SHIFT                      0x00000000
#define	NB_BIU_DBF__DBF_EN_CALIB__SHIFT                    0x00000001
#define	NB_BIU_DBF__DBF_EN_PCI_SLAVE__SHIFT                0x00000002
#define	NB_BIU_DBF__DBF_EN_GRT__SHIFT                      0x00000003
#define	NB_BIU_DBF__DBF_EN_M2C__SHIFT                      0x00000004
#define	NB_BIU_DBF__DBF_EN_LMU__SHIFT                      0x00000005
#define	NB_BIU_DBF__DBF_EN_SMU__SHIFT                      0x00000006

// NB_BIU_CFG2
#define	NB_BIU_CFG2__DPWRMode__SHIFT                       0x00000000
#define	NB_BIU_CFG2__DPWRWaitOff__SHIFT                    0x00000002
#define	NB_BIU_CFG2__DatDRENOffIdle__SHIFT                 0x00000004
#define	NB_BIU_CFG2__AddrDRENOnBR0__SHIFT                  0x00000005
#define	NB_BIU_CFG2__PciSlvWrtOptEn__SHIFT                 0x00000006
#define	NB_BIU_CFG2__PciSlvRdOptEn__SHIFT                  0x00000007
#define	NB_BIU_CFG2__UpdREGatIdle__SHIFT                   0x00000008
#define	NB_BIU_CFG2__CpuFbAccessEn__SHIFT                  0x00000009
#define	NB_BIU_CFG2__PciMstBnrEn__SHIFT                    0x0000000a
#define	NB_BIU_CFG2__BypassRdDataOff__SHIFT                0x0000000b
#define	NB_BIU_CFG2__DbgCntrMode__SHIFT                    0x0000000c
#define	NB_BIU_CFG2__LaqThreshold__SHIFT                   0x0000000d
#define	NB_BIU_CFG2__SaqThreshold__SHIFT                   0x0000000f
#define	NB_BIU_CFG2__XClkLatency__SHIFT                    0x00000011

// NB_CPU_AUTOCAL_SEL
#define	NB_CPU_AUTOCAL_SEL__CalibIOSel__SHIFT              0x00000000
#define	NB_CPU_AUTOCAL_SEL__CalibSampleSel__SHIFT          0x00000003
#define	NB_CPU_AUTOCAL_SEL__CalibBiuIdleUpdMode__SHIFT     0x00000005
#define	NB_CPU_AUTOCAL_SEL__Reserved__SHIFT                0x00000006

// NB_CPU_STR_MODIFIER
#define	NB_CPU_STR_MODIFIER__ModCalib2xSTR__SHIFT          0x00000000
#define	NB_CPU_STR_MODIFIER__ModCalib2xstbSTR__SHIFT       0x00000003
#define	NB_CPU_STR_MODIFIER__Reserved1__SHIFT              0x00000006
#define	NB_CPU_STR_MODIFIER__ModCalib4xSTR__SHIFT          0x00000008
#define	NB_CPU_STR_MODIFIER__ModCalib4xstbSTR__SHIFT       0x0000000b
#define	NB_CPU_STR_MODIFIER__ModCalibSTRDisable__SHIFT     0x0000000e
#define	NB_CPU_STR_MODIFIER__Reserved2__SHIFT              0x0000000f

// NB_CPU_AUTOCAL_PROGRAM_STR
#define	NB_CPU_AUTOCAL_PROGRAM_STR__CPU_PROGRAM_PSTR__SHIFT 0x00000000
#define	NB_CPU_AUTOCAL_PROGRAM_STR__CPU_PROGRAM_NSTR__SHIFT 0x00000008

// NB_AGP_GRFXIO_CNTL
#define	NB_AGP_GRFXIO_CNTL__AGPPAD_TMDS_EN__SHIFT          0x00000000
#define	NB_AGP_GRFXIO_CNTL__AGPPAD_SS_EN__SHIFT            0x00000001
#define	NB_AGP_GRFXIO_CNTL__AGPPAD_LVDS_EN__SHIFT          0x00000002
#define	NB_AGP_GRFXIO_CNTL__AGPPAD_VID_EN__SHIFT           0x00000003
#define	NB_AGP_GRFXIO_CNTL__AGPPAD_CLK_RUN_EN__SHIFT       0x00000004
#define	NB_AGP_GRFXIO_CNTL__AGPPAD_STP_AGP_EN__SHIFT       0x00000005
#define	NB_AGP_GRFXIO_CNTL__AGPPAD_HPD2_EN__SHIFT          0x00000006
#define	NB_AGP_GRFXIO_CNTL__AGPPAD_GPIO_EN__SHIFT          0x00000007

// NB_CPU_PAD_STR
#define	NB_CPU_PAD_STR__CPU_PAD_PSTR__SHIFT                0x00000000
#define	NB_CPU_PAD_STR__CPU_PAD_NSTR__SHIFT                0x00000008

// OSC_CONTROL
#define	OSC_CONTROL__OSC_EN__SHIFT                         0x00000000
#define	OSC_CONTROL__XTAL_LOW_GAIN__SHIFT                  0x00000001
#define	OSC_CONTROL__Reserved0__SHIFT                      0x00000003
#define	OSC_CONTROL__CPU_STOP_ENABLE__SHIFT                0x00000004
#define	OSC_CONTROL__DC_STOP_ENABLE__SHIFT                 0x00000005
#define	OSC_CONTROL__PCICLK_OE_TOGGLE__SHIFT               0x00000006
#define	OSC_CONTROL__Reserved1__SHIFT                      0x0000000b
#define	OSC_CONTROL__CPUCLK_SE_OE_TOGGLE__SHIFT            0x0000000c
#define	OSC_CONTROL__CPUCLK_DIFF_OE_TOGGLE__SHIFT          0x0000000d
#define	OSC_CONTROL__REF_14M_OE_TOGGLE__SHIFT              0x0000000e
#define	OSC_CONTROL__APIC_CLK_OE_TOGGLE__SHIFT             0x0000000f
#define	OSC_CONTROL__REF_24M_48M_OE_TOGGLE__SHIFT          0x00000011
#define	OSC_CONTROL__ON_CHIP_CLOCK_GENERATOR__SHIFT        0x00000012
#define	OSC_CONTROL__SYSCLK_OE_TOGGLE__SHIFT               0x00000013
#define	OSC_CONTROL__MEMCLK_OE_TOGGLE__SHIFT               0x00000014

// SPLL_CONTROL
#define	SPLL_CONTROL__SPLL_IPSCREF__SHIFT                  0x00000000
#define	SPLL_CONTROL__SPLL_IPSCFB__SHIFT                   0x00000003
#define	SPLL_CONTROL__SPLL_IPSCA__SHIFT                    0x00000006
#define	SPLL_CONTROL__SPLL_IPSCB__SHIFT                    0x00000009
#define	SPLL_CONTROL__SPLL_IPSCC__SHIFT                    0x0000000c
#define	SPLL_CONTROL__SPLL_IPVG__SHIFT                     0x00000010
#define	SPLL_CONTROL__SPLL_IPCP__SHIFT                     0x00000014
#define	SPLL_CONTROL__SPLL_TCPOFF__SHIFT                   0x00000018
#define	SPLL_CONTROL__SPLL_ITVCOMAX__SHIFT                 0x00000019
#define	SPLL_CONTROL__SPLL_BYPASS__SHIFT                   0x0000001c
#define	SPLL_CONTROL__SPLL_POWERDOWN_DLY__SHIFT            0x0000001d
#define	SPLL_CONTROL__SPLL_POWERDOWN__SHIFT                0x0000001f

// MPLL_CONTROL
#define	MPLL_CONTROL__MPLL_DELTA_FRACTION__SHIFT           0x00000000
#define	MPLL_CONTROL__MPLL_DELTA_INTEGER__SHIFT            0x00000003
#define	MPLL_CONTROL__MPLL_TCPOFF__SHIFT                   0x00000009
#define	MPLL_CONTROL__MPLL_TVCOMAX__SHIFT                  0x0000000a
#define	MPLL_CONTROL__MPLL_TMONEN__SHIFT                   0x0000000b
#define	MPLL_CONTROL__MPLL_PCP__SHIFT                      0x0000000c
#define	MPLL_CONTROL__MPLL_PVG__SHIFT                      0x00000010
#define	MPLL_CONTROL__MPLL_PDC__SHIFT                      0x00000013
#define	MPLL_CONTROL__MPLL_STEP_SIZE__SHIFT                0x00000016
#define	MPLL_CONTROL__MPLL_DELAY__SHIFT                    0x00000018
#define	MPLL_CONTROL__MPLL_SS_EN__SHIFT                    0x0000001b
#define	MPLL_CONTROL__MPLL_BYPASS__SHIFT                   0x0000001c
#define	MPLL_CONTROL__MPLL_POWERDOWN_DLY__SHIFT            0x0000001d
#define	MPLL_CONTROL__MPLL_POWERDOWN__SHIFT                0x0000001f

// BPLL_CONTROL
#define	BPLL_CONTROL__BPLL_IPSCREF__SHIFT                  0x00000000
#define	BPLL_CONTROL__BPLL_IPSCFB__SHIFT                   0x00000003
#define	BPLL_CONTROL__BPLL_IPSCA__SHIFT                    0x00000006
#define	BPLL_CONTROL__BPLL_IPSCB__SHIFT                    0x00000009
#define	BPLL_CONTROL__BPLL_IPSCC__SHIFT                    0x0000000c
#define	BPLL_CONTROL__BPLL_IPVG__SHIFT                     0x00000010
#define	BPLL_CONTROL__BPLL_IPCP__SHIFT                     0x00000014
#define	BPLL_CONTROL__BPLL_TCPOFF__SHIFT                   0x00000018
#define	BPLL_CONTROL__BPLL_ITVCOMAX__SHIFT                 0x00000019
#define	BPLL_CONTROL__BPLL_BYPASS__SHIFT                   0x0000001c
#define	BPLL_CONTROL__BPLL_POWERDOWN_DLY__SHIFT            0x0000001d
#define	BPLL_CONTROL__BPLL_POWERDOWN__SHIFT                0x0000001f

// UPLL_CONTROL
#define	UPLL_CONTROL__UPLL_MDIV__SHIFT                     0x00000000
#define	UPLL_CONTROL__UPLL_NDIV__SHIFT                     0x0000000a
#define	UPLL_CONTROL__UPLL_PDIV__SHIFT                     0x00000014
#define	UPLL_CONTROL__UPLL_REF_SEL__SHIFT                  0x00000019
#define	UPLL_CONTROL__UPLL_BYPASS__SHIFT                   0x0000001c
#define	UPLL_CONTROL__UPLL_RST__SHIFT                      0x0000001d
#define	UPLL_CONTROL__Reserved__SHIFT                      0x0000001e
#define	UPLL_CONTROL__UPLL_POWERDOWN_TOGGLE__SHIFT         0x0000001f

// PLL_ANALOG_CONTROL
#define	PLL_ANALOG_CONTROL__UPLL_PCP__SHIFT                0x00000010
#define	PLL_ANALOG_CONTROL__UPLL_PVG__SHIFT                0x00000013
#define	PLL_ANALOG_CONTROL__UPLL_PDC__SHIFT                0x00000016
#define	PLL_ANALOG_CONTROL__SSPLL_TRACK_MODE__SHIFT        0x00000018
#define	PLL_ANALOG_CONTROL__SSPLL_TRACK_SPEED__SHIFT       0x0000001a
#define	PLL_ANALOG_CONTROL__SSPLL_CONTIN_CALIB__SHIFT      0x0000001c

// MC_CLK_CNTRL
#define	MC_CLK_CNTRL__MC_CLKSPEED__SHIFT                   0x00000000
#define	MC_CLK_CNTRL__MC_USE_CLKSPEED__SHIFT               0x00000002
#define	MC_CLK_CNTRL__GEARRATIO_MS__SHIFT                  0x00000003
#define	MC_CLK_CNTRL__GEARRATIO_BS__SHIFT                  0x00000005
#define	MC_CLK_CNTRL__FORCE_GEARRATIO_RECALC__SHIFT        0x00000007

// THERMAL_SENSOR_GEN_CNTL
#define	THERMAL_SENSOR_GEN_CNTL__THERM_SOFT_RESET__SHIFT   0x00000000
#define	THERMAL_SENSOR_GEN_CNTL__THERM_CLKEN__SHIFT        0x00000001
#define	THERMAL_SENSOR_GEN_CNTL__THERM_INV_CLK2__SHIFT     0x00000002
#define	THERMAL_SENSOR_GEN_CNTL__THERM_SENSOR_PWDN__SHIFT  0x00000004
#define	THERMAL_SENSOR_GEN_CNTL__THERM_SENSOR_ENABLE__SHIFT 0x00000005
#define	THERMAL_SENSOR_GEN_CNTL__THERM_SENSOR_DYN_DISABLE__SHIFT 0x00000006
#define	THERMAL_SENSOR_GEN_CNTL__THERM_CLKDIV__SHIFT       0x00000008
#define	THERMAL_SENSOR_GEN_CNTL__THERM_CLKPHASE__SHIFT     0x00000014

// THERMAL_SENSOR_SAMP_CNTL
#define	THERMAL_SENSOR_SAMP_CNTL__THERM_AVGSAMPLE__SHIFT   0x00000000
#define	THERMAL_SENSOR_SAMP_CNTL__THERM_IDLE_PERIOD__SHIFT 0x00000003
#define	THERMAL_SENSOR_SAMP_CNTL__THERM_MANUAL_TERPERATURE__SHIFT 0x00000010
#define	THERMAL_SENSOR_SAMP_CNTL__THERM_MANUAL_VALID__SHIFT 0x00000016
#define	THERMAL_SENSOR_SAMP_CNTL__THERM_MANUAL_TEMP_EN__SHIFT 0x00000017
#define	THERMAL_SENSOR_SAMP_CNTL__THERM_MC_TEMP_THROTTLE__SHIFT 0x00000018
#define	THERMAL_SENSOR_SAMP_CNTL__THERM_MCCNTL_EN__SHIFT   0x0000001e

// THERMAL_SENSOR_DYN_CNTL
#define	THERMAL_SENSOR_DYN_CNTL__THERM_FANCNTL_EN__SHIFT   0x00000000
#define	THERMAL_SENSOR_DYN_CNTL__THERM_SPEED_MIN__SHIFT    0x00000002
#define	THERMAL_SENSOR_DYN_CNTL__THERM_FANCNTL_HYST__SHIFT 0x00000004
#define	THERMAL_SENSOR_DYN_CNTL__THERM_ENGCLKCNTL_EN__SHIFT 0x00000007
#define	THERMAL_SENSOR_DYN_CNTL__THERM_FAN_TEMP_LOW__SHIFT 0x00000008
#define	THERMAL_SENSOR_DYN_CNTL__THERM_SPEED_LOW__SHIFT    0x0000000e
#define	THERMAL_SENSOR_DYN_CNTL__THERM_FAN_TEMP_MED__SHIFT 0x00000010
#define	THERMAL_SENSOR_DYN_CNTL__THERM_SPEED_MED__SHIFT    0x00000016
#define	THERMAL_SENSOR_DYN_CNTL__THERM_FAN_TEMP_HIGH__SHIFT 0x00000018
#define	THERMAL_SENSOR_DYN_CNTL__THERM_SPEED_HIGH__SHIFT   0x0000001e

// THERMAL_SENSOR_INT_CNTL
#define	THERMAL_SENSOR_INT_CNTL__THERM_MC_TEMP_HYST__SHIFT 0x00000000
#define	THERMAL_SENSOR_INT_CNTL__TEMP_READBACK__SHIFT      0x00000004
#define	THERMAL_SENSOR_INT_CNTL__THERM_TEMP_READ_TRIGGER__SHIFT 0x0000000a
#define	THERMAL_SENSOR_INT_CNTL__THERM_INT_STATUS_AK__SHIFT 0x0000000b
#define	THERMAL_SENSOR_INT_CNTL__THERM_INT_TEMP_THRES__SHIFT 0x0000000c
#define	THERMAL_SENSOR_INT_CNTL__THERM_INT_TEMP_PERIOD__SHIFT 0x00000012
#define	THERMAL_SENSOR_INT_CNTL__THERM_INT_EN__SHIFT       0x0000001f

// PLL_VOLTAGE_REG_CNTL
#define	PLL_VOLTAGE_REG_CNTL__NB_RSBEN__SHIFT              0x00000000
#define	PLL_VOLTAGE_REG_CNTL__NB_REG_OVERRIDE__SHIFT       0x00000001
#define	PLL_VOLTAGE_REG_CNTL__NB_RBGADJ__SHIFT             0x00000004

// GPC_CONTROL
#define	GPC_CONTROL__GPC_RESET__SHIFT                      0x00000000
#define	GPC_CONTROL__GPC_EQ_ZERO__SHIFT                    0x00000001
#define	GPC_CONTROL__GPC_CLK_SEL__SHIFT                    0x00000004

// GC_CLK_CNTRL
#define	GC_CLK_CNTRL__CG_AGPCLKSTATE__SHIFT                0x00000000
#define	GC_CLK_CNTRL__ONCHIP_GRAPHICS_STRAP_TOGGLE__SHIFT  0x00000001
#define	GC_CLK_CNTRL__GC_STATE__SHIFT                      0x00000003
#define	GC_CLK_CNTRL__STOP_PCI_REQ__SHIFT                  0x00000005

// OCCG_EXTCLK_DISABLE
#define	OCCG_EXTCLK_DISABLE__DISABLE_CPUCLK__SHIFT         0x00000000
#define	OCCG_EXTCLK_DISABLE__DISABLE_CPUCLKN__SHIFT        0x00000001
#define	OCCG_EXTCLK_DISABLE__DISABLE_CPUCLKP__SHIFT        0x00000002
#define	OCCG_EXTCLK_DISABLE__DISABLE_REF24M48M__SHIFT      0x00000003
#define	OCCG_EXTCLK_DISABLE__DISABLE_APICCLK1__SHIFT       0x00000004
#define	OCCG_EXTCLK_DISABLE__DISABLE_APICCLK2__SHIFT       0x00000005
#define	OCCG_EXTCLK_DISABLE__DISABLE_PLLSYSCLKH__SHIFT     0x00000006
#define	OCCG_EXTCLK_DISABLE__DISABLE_PLLMEMCLKH__SHIFT     0x00000007
#define	OCCG_EXTCLK_DISABLE__DISABLE_PLLAGPCLKH__SHIFT     0x00000008
#define	OCCG_EXTCLK_DISABLE__DISABLE_CPUCLKTUNE__SHIFT     0x00000009

// MPLL_CONTROL2
#define	MPLL_CONTROL2__MPLL_REF_DIV__SHIFT                 0x00000000
#define	MPLL_CONTROL2__MPLL_ATOMIC_UPDATE_EN__SHIFT        0x0000000a
#define	MPLL_CONTROL2__MPLL_ATOMIC_UPDATE_TRIGGER__SHIFT   0x0000000b
#define	MPLL_CONTROL2__MPLL_FB_DIV_FRACTION__SHIFT         0x0000000c
#define	MPLL_CONTROL2__MPLL_FBDIV_FRACTION_UPDATE_TRIGGER__SHIFT 0x0000000f
#define	MPLL_CONTROL2__MPLL_FB_DIV__SHIFT                  0x00000010
#define	MPLL_CONTROL2__MPLL_POST_DIV__SHIFT                0x0000001c

// MPLL_CONTROL3
#define	MPLL_CONTROL3__MPLL_TST_CNT__SHIFT                 0x00000000
#define	MPLL_CONTROL3__MPLL_TST_CNT_SEL__SHIFT             0x00000010
#define	MPLL_CONTROL3__MPLL_TST_DIVIDERS__SHIFT            0x00000012
#define	MPLL_CONTROL3__MPLL_TST_MODE__SHIFT                0x00000013
#define	MPLL_CONTROL3__MPLL_TST_GE__SHIFT                  0x00000014
#define	MPLL_CONTROL3__MPLL_TST_LE__SHIFT                  0x00000015
#define	MPLL_CONTROL3__MPLL_TST_DEC__SHIFT                 0x00000016
#define	MPLL_CONTROL3__MPLL_REFCLK_SEL__SHIFT              0x00000018
#define	MPLL_CONTROL3__MPLL_FBCLK_SEL__SHIFT               0x00000019
#define	MPLL_CONTROL3__MPLL_REFIN_SEL__SHIFT               0x0000001a
#define	MPLL_CONTROL3__MPLL_PD_NOW__SHIFT                  0x0000001c
#define	MPLL_CONTROL3__MPLL_RESET__SHIFT                   0x0000001d
#define	MPLL_CONTROL3__MCIOPLL_LOCKED__SHIFT               0x0000001e
#define	MPLL_CONTROL3__MCIOPLL_CAL_TRIGGER__SHIFT          0x0000001f

// MC_DATA_DLL_CNTRL_A
#define	MC_DATA_DLL_CNTRL_A__DLL_DA_IN_TRIM0__SHIFT        0x00000000
#define	MC_DATA_DLL_CNTRL_A__DLL_DA_OUT_TRIM0__SHIFT       0x00000004
#define	MC_DATA_DLL_CNTRL_A__DLL_DA_IN_TRIM1__SHIFT        0x00000008
#define	MC_DATA_DLL_CNTRL_A__DLL_DA_OUT_TRIM1__SHIFT       0x0000000c
#define	MC_DATA_DLL_CNTRL_A__DLL_DA_IN_TRIM2__SHIFT        0x00000010
#define	MC_DATA_DLL_CNTRL_A__DLL_DA_OUT_TRIM2__SHIFT       0x00000014
#define	MC_DATA_DLL_CNTRL_A__DLL_DA_IN_TRIM3__SHIFT        0x00000018
#define	MC_DATA_DLL_CNTRL_A__DLL_DA_OUT_TRIM3__SHIFT       0x0000001c

// SCRATCH_CLKCFG
#define	SCRATCH_CLKCFG__SCRATCH__SHIFT                     0x00000000
#define	SCRATCH_CLKCFG__CLKCAL_VAL_P__SHIFT                0x00000012
#define	SCRATCH_CLKCFG__CLKCAL_VAL_N__SHIFT                0x00000017
#define	SCRATCH_CLKCFG__CAL_VAL_V__SHIFT                   0x0000001c

// MC_ACMD_DLL_CNTRL_A
#define	MC_ACMD_DLL_CNTRL_A__DLL_CA_IN_TRIM__SHIFT         0x00000000
#define	MC_ACMD_DLL_CNTRL_A__DLL_CA_OUT_TRIM__SHIFT        0x00000004

// MC_ACMD_DLL_CNTRL_B
#define	MC_ACMD_DLL_CNTRL_B__DLL_CB_IN_TRIM__SHIFT         0x00000000
#define	MC_ACMD_DLL_CNTRL_B__DLL_CB_OUT_TRIM__SHIFT        0x00000004

// CLKGATE_DISABLE2
#define	CLKGATE_DISABLE2__CLKGATE_DIS_MCB__SHIFT           0x00000000
#define	CLKGATE_DISABLE2__CLKGATE_DIS_MCGR__SHIFT          0x00000001
#define	CLKGATE_DISABLE2__CLKGATE_DIS_MCSQA__SHIFT         0x00000002
#define	CLKGATE_DISABLE2__CLKGATE_DIS_MCSQB__SHIFT         0x00000003
#define	CLKGATE_DISABLE2__CLKGATE_DIS_MCIOA__SHIFT         0x00000004
#define	CLKGATE_DISABLE2__CLKGATE_DIS_MCIOB__SHIFT         0x00000005
#define	CLKGATE_DISABLE2__CLKGATE_DIS_MCAGP__SHIFT         0x00000006
#define	CLKGATE_DISABLE2__CLKGATE_DIS_MCAGP_PM1__SHIFT     0x00000007
#define	CLKGATE_DISABLE2__CLKGATE_DIS_BIU_NB1ACLK__SHIFT   0x00000008
#define	CLKGATE_DISABLE2__CLKGATE_DIS_BIU_NB1BCLK__SHIFT   0x00000009
#define	CLKGATE_DISABLE2__CLKDATE_DIS_BIU_MEMA__SHIFT      0x0000000a
#define	CLKGATE_DISABLE2__CLKDATE_DIS_BIU_MEMB__SHIFT      0x0000000b
#define	CLKGATE_DISABLE2__CLKGATE_DIS_BIU_PAD__SHIFT       0x0000000c
#define	CLKGATE_DISABLE2__CLKGATE_DIS_PCI4X__SHIFT         0x0000000d
#define	CLKGATE_DISABLE2__CLKGATE_DIS_PCIM__SHIFT          0x0000000e
#define	CLKGATE_DISABLE2__CLKGATE_DIS_PCIT__SHIFT          0x0000000f
#define	CLKGATE_DISABLE2__CLKGATE_DIS_PCICG__SHIFT         0x00000010
#define	CLKGATE_DISABLE2__CLKGATE_DIS_AGP_B1X_PM1__SHIFT   0x00000011
#define	CLKGATE_DISABLE2__CLKGATE_DIS_BIU_IOPLL4X__SHIFT   0x00000012
#define	CLKGATE_DISABLE2__GFX_SCLK_DISABLE__SHIFT          0x00000014
#define	CLKGATE_DISABLE2__GFX_DISPCLK_DISABLE__SHIFT       0x00000015
#define	CLKGATE_DISABLE2__PCI4XCLK_DISABLE__SHIFT          0x0000001a
#define	CLKGATE_DISABLE2__AGP8XCLK_DISABLE__SHIFT          0x0000001b
#define	CLKGATE_DISABLE2__AGPCLK_DISABLE__SHIFT            0x0000001c
#define	CLKGATE_DISABLE2__PCI_B4X_DISABLE__SHIFT           0x0000001d
#define	CLKGATE_DISABLE2__MC_DELAY_TIMER_EXTEND__SHIFT     0x0000001e
#define	CLKGATE_DISABLE2__AGP_DELAY_TIMER_EXTEND__SHIFT    0x0000001f

// EXT_PCICLK_STOP_CNTRL
#define	EXT_PCICLK_STOP_CNTRL__PCICLK0_STOP_MODE__SHIFT    0x00000000
#define	EXT_PCICLK_STOP_CNTRL__PCICLK1_STOP_MODE__SHIFT    0x00000003
#define	EXT_PCICLK_STOP_CNTRL__PCICLK2_STOP_MODE_A5__SHIFT 0x00000006
#define	EXT_PCICLK_STOP_CNTRL__PCICLK3_STOP_MODE_A5__SHIFT 0x00000009
#define	EXT_PCICLK_STOP_CNTRL__PCICLK4_STOP_MODE_A5__SHIFT 0x0000000c

// CLKGATE_DISABLE
#define	CLKGATE_DISABLE__CLKGATE_DIS_MCA__SHIFT            0x00000000
#define	CLKGATE_DISABLE__CPUCLK_STOP_MISC__SHIFT           0x00000001
#define	CLKGATE_DISABLE__CLKGATE_DIS_MC1__SHIFT            0x00000002
#define	CLKGATE_DISABLE__CLKGATE_DIS_MC2__SHIFT            0x00000003
#define	CLKGATE_DISABLE__DIS_CPUCLK_STOP_BIU__SHIFT        0x00000004
#define	CLKGATE_DISABLE__DIS_CPUCLK_STOP_AGP__SHIFT        0x00000005
#define	CLKGATE_DISABLE__DIS_CPUCLK_STOP_PCI__SHIFT        0x00000006
#define	CLKGATE_DISABLE__CLKGATE_DIS_MC6__SHIFT            0x00000007
#define	CLKGATE_DISABLE__ENABLE_ANALOG_DLLs__SHIFT         0x00000008
#define	CLKGATE_DISABLE__CLKGATE_DIS_RAMCLK__SHIFT         0x00000009
#define	CLKGATE_DISABLE__CLKGATE_DIS_BIU_MEM__SHIFT        0x0000000a
#define	CLKGATE_DISABLE__CLKGATE_DIS_BIU_NB1CLK__SHIFT     0x0000000b
#define	CLKGATE_DISABLE__CLKGATE_DIS_BIU_NB2CLK__SHIFT     0x0000000c
#define	CLKGATE_DISABLE__CLKGATE_DIS_AGP_B1X__SHIFT        0x0000000d
#define	CLKGATE_DISABLE__CLKGATE_DIS_AGP_B2X__SHIFT        0x0000000e
#define	CLKGATE_DISABLE__CLKGATE_DIS_AGP_B4X__SHIFT        0x0000000f
#define	CLKGATE_DISABLE__CLKGATE_DIS_AGP_S1X__SHIFT        0x00000010
#define	CLKGATE_DISABLE__CLKGATE_DIS_AGP_B1XSBA__SHIFT     0x00000011
#define	CLKGATE_DISABLE__CLKGATE_DIS_AGP_B2XSBA__SHIFT     0x00000012
#define	CLKGATE_DISABLE__CLKGATE_DIS_AGP_B2XAIO__SHIFT     0x00000013
#define	CLKGATE_DISABLE__CLKGATE_DIS_PCI_B1X__SHIFT        0x00000014
#define	CLKGATE_DISABLE__CLKGATE_DIS_PCI_B2X__SHIFT        0x00000015
#define	CLKGATE_DISABLE__CLKGATE_DIS_PCI_S1X__SHIFT        0x00000016
#define	CLKGATE_DISABLE__PCIM_S1X_DISABLEb__SHIFT          0x00000017
#define	CLKGATE_DISABLE__CLKGATE_DIS_CG_AGP1X__SHIFT       0x00000018
#define	CLKGATE_DISABLE__CLKGATE_DIS_CG_AGPnX__SHIFT       0x00000019
#define	CLKGATE_DISABLE__CLKGATE_DIS_IG2R6_B1X__SHIFT      0x0000001a
#define	CLKGATE_DISABLE__CLKGATE_DIS_IG2R6_S1X__SHIFT      0x0000001b
#define	CLKGATE_DISABLE__CLKGATE_DIS_CFG_S1X__SHIFT        0x0000001c
#define	CLKGATE_DISABLE__CLKGATE_DIS_CFG_B1X__SHIFT        0x0000001d
#define	CLKGATE_DISABLE__DEEP_S1_DISABLE__SHIFT            0x0000001e

// SSPLL_CONFIG0
#define	SSPLL_CONFIG0__SSPLL_SPREAD_ON_TOGGLE__SHIFT       0x00000000
#define	SSPLL_CONFIG0__SSPLL_RST__SHIFT                    0x00000001
#define	SSPLL_CONFIG0__SSPLL_POWERDOWN__SHIFT              0x00000002
#define	SSPLL_CONFIG0__SSPLL_B__SHIFT                      0x00000003
#define	SSPLL_CONFIG0__SSPLL_V__SHIFT                      0x00000009
#define	SSPLL_CONFIG0__SSPLL_S__SHIFT                      0x0000000f
#define	SSPLL_CONFIG0__SSPLL_POWERDOWN_DLY__SHIFT          0x00000017
#define	SSPLL_CONFIG0__SSPLL_REFDIV__SHIFT                 0x00000019

// SSPLL_CONFIG1
#define	SSPLL_CONFIG1__SSPLL_REFCLK_SEL__SHIFT             0x00000000
#define	SSPLL_CONFIG1__SSPLL_FBCLK_SEL__SHIFT              0x00000001
#define	SSPLL_CONFIG1__SSPLL_TCPOFF__SHIFT                 0x00000002
#define	SSPLL_CONFIG1__SSPLL_TVCOMAX__SHIFT                0x00000003
#define	SSPLL_CONFIG1__SSPLL_TMONEN__SHIFT                 0x00000004
#define	SSPLL_CONFIG1__SSPLL_PCP__SHIFT                    0x00000005
#define	SSPLL_CONFIG1__SSPLL_PVG__SHIFT                    0x00000008
#define	SSPLL_CONFIG1__SSPLL_PDC__SHIFT                    0x0000000b
#define	SSPLL_CONFIG1__SSPLL_STEP_SIZE__SHIFT              0x0000000e
#define	SSPLL_CONFIG1__SSPLL_DELAY__SHIFT                  0x00000010
#define	SSPLL_CONFIG1__SSPLL_DELTA_FRACTION__SHIFT         0x00000014
#define	SSPLL_CONFIG1__SSPLL_DELTA_INTEGER__SHIFT          0x00000018
#define	SSPLL_CONFIG1__SSPLL_OVERCLOCK_EN__SHIFT           0x0000001e
#define	SSPLL_CONFIG1__SSPLL_SPARE__SHIFT                  0x0000001f

// SSPLL_CONFIG2
#define	SSPLL_CONFIG2__SSPLL_TST_CNT__SHIFT                0x00000000
#define	SSPLL_CONFIG2__SSPLL_OVERCLOCK_FB_DIV_U__SHIFT     0x0000000e
#define	SSPLL_CONFIG2__SSPLL_TST_CNT_SEL__SHIFT            0x00000010
#define	SSPLL_CONFIG2__SSPLL_TST_DIVIDERS__SHIFT           0x00000012
#define	SSPLL_CONFIG2__SSPLL_TST_MODE__SHIFT               0x00000013
#define	SSPLL_CONFIG2__SSPLL_TST_GE__SHIFT                 0x00000014
#define	SSPLL_CONFIG2__SSPLL_TST_LE__SHIFT                 0x00000015
#define	SSPLL_CONFIG2__SSPLL_TST_DEC__SHIFT                0x00000016
#define	SSPLL_CONFIG2__SSPLL_OVERCLOCK_FB_DIV_L__SHIFT     0x00000017

// CLK_TOP_PERF_COUNT0
#define	CLK_TOP_PERF_COUNT0__CLK_TOP_COUNT_0__SHIFT        0x00000000

// CLK_TOP_PERF_COUNT1
#define	CLK_TOP_PERF_COUNT1__CLK_TOP_COUNT_1__SHIFT        0x00000000

// CLK_TOP_PERF_CNTL
#define	CLK_TOP_PERF_CNTL__CLK_TOP_EVENT_SEL_0__SHIFT      0x00000000
#define	CLK_TOP_PERF_CNTL__CLK_TOP_EVENT_SEL_1__SHIFT      0x00000008
#define	CLK_TOP_PERF_CNTL__CLK_TOP_UPPER_COUNT_0__SHIFT    0x00000010
#define	CLK_TOP_PERF_CNTL__CLK_TOP_UPPER_COUNT_1__SHIFT    0x00000018

// MPLL_FREQ_CONTROL
#define	MPLL_FREQ_CONTROL__MPLL_PM_EN__SHIFT               0x00000000
#define	MPLL_FREQ_CONTROL__MPLL_FREQ_SEL__SHIFT            0x00000001
#define	MPLL_FREQ_CONTROL__DISP_BLANK_CNTL__SHIFT          0x00000002
#define	MPLL_FREQ_CONTROL__DISP_BLANK_VAL__SHIFT           0x00000004
#define	MPLL_FREQ_CONTROL__MEM_SELF_REFRESH_ONLY__SHIFT    0x00000005
#define	MPLL_FREQ_CONTROL__PM_SWITCHMCLK_BUSY__SHIFT       0x00000006
#define	MPLL_FREQ_CONTROL__PM_FREQ_CNTL_RESET__SHIFT       0x00000007
#define	MPLL_FREQ_CONTROL__PM_MPLL_DELTA_FRACTION__SHIFT   0x00000008
#define	MPLL_FREQ_CONTROL__PM_MPLL_DELTA_INTEGER__SHIFT    0x0000000b
#define	MPLL_FREQ_CONTROL__PM_MPLL_PVG__SHIFT              0x00000011
#define	MPLL_FREQ_CONTROL__PM_MPLL_STEP_SIZE__SHIFT        0x00000014
#define	MPLL_FREQ_CONTROL__PM_MPLL_DELAY__SHIFT            0x00000016
#define	MPLL_FREQ_CONTROL__MPLL_SLOWMCLK__SHIFT            0x0000001c
#define	MPLL_FREQ_CONTROL__PM_MPLL_SLOWMCLK__SHIFT         0x0000001d

// MPLL_SEQ_CONTROL
#define	MPLL_SEQ_CONTROL__MPLL_RESET_PULSE_WIDTH__SHIFT    0x00000000
#define	MPLL_SEQ_CONTROL__MDLL_RESET_PULSE_WIDTH__SHIFT    0x00000005
#define	MPLL_SEQ_CONTROL__MPLL_LOCK_TIME__SHIFT            0x00000008
#define	MPLL_SEQ_CONTROL__MDLL_LOCK_TIME__SHIFT            0x00000014

// MPLL_DIV_CONTROL
#define	MPLL_DIV_CONTROL__PM_MPLL_REF_DIV__SHIFT           0x00000000
#define	MPLL_DIV_CONTROL__PM_MPLL_FB_DIV_FRACTION__SHIFT   0x0000000c
#define	MPLL_DIV_CONTROL__PM_MPLL_FB_DIV__SHIFT            0x00000010
#define	MPLL_DIV_CONTROL__PM_MPLL_POST_DIV__SHIFT          0x0000001c

// NBCLK_IO_CONTROL
#define	NBCLK_IO_CONTROL__SYSCLK_SP__SHIFT                 0x00000000
#define	NBCLK_IO_CONTROL__SYSCLK_SPB__SHIFT                0x00000002
#define	NBCLK_IO_CONTROL__SYSCLK_SRP__SHIFT                0x00000004
#define	NBCLK_IO_CONTROL__SYSCLK_SRPB__SHIFT               0x00000006
#define	NBCLK_IO_CONTROL__SYS_FBCLKOUT_SP__SHIFT           0x00000008
#define	NBCLK_IO_CONTROL__SYS_FBCLKOUT_SPB__SHIFT          0x0000000a
#define	NBCLK_IO_CONTROL__SYS_FBCLKOUT_SRP__SHIFT          0x0000000c
#define	NBCLK_IO_CONTROL__SYS_FBCLKOUT_SRPB__SHIFT         0x0000000e
#define	NBCLK_IO_CONTROL__IOSPLL_IPWDN__SHIFT              0x00000010
#define	NBCLK_IO_CONTROL__IOSPLL_IBYPASS__SHIFT            0x00000011
#define	NBCLK_IO_CONTROL__IOSPLL_IREF_DELAY__SHIFT         0x00000012
#define	NBCLK_IO_CONTROL__IOSPLL_IVCO_DELAY__SHIFT         0x00000013
#define	NBCLK_IO_CONTROL__IOSPLL_IICP__SHIFT               0x00000014
#define	NBCLK_IO_CONTROL__IOSPLL_ICPBW__SHIFT              0x00000016
#define	NBCLK_IO_CONTROL__IOSPLL_IVCOBW__SHIFT             0x00000017
#define	NBCLK_IO_CONTROL__IOSPLL_ISKEW_4X__SHIFT           0x00000018
#define	NBCLK_IO_CONTROL__IOSPLL_IPLL_CNTL__SHIFT          0x0000001c

// NBCLK_IO_CONTROL1
#define	NBCLK_IO_CONTROL1__AGPCLKIN_PU__SHIFT              0x00000000
#define	NBCLK_IO_CONTROL1__AGPCLKIN_PD__SHIFT              0x00000001
#define	NBCLK_IO_CONTROL1__EXT_MEMCLK_PU__SHIFT            0x00000008
#define	NBCLK_IO_CONTROL1__EXT_MEMCLK_PD__SHIFT            0x00000009
#define	NBCLK_IO_CONTROL1__EXT_MEMCLK_SRP__SHIFT           0x0000000a
#define	NBCLK_IO_CONTROL1__EXT_MEMCLK_SRN__SHIFT           0x0000000b
#define	NBCLK_IO_CONTROL1__EXT_MEMCLK_SP__SHIFT            0x0000000c
#define	NBCLK_IO_CONTROL1__EXT_MEMCLK_SN__SHIFT            0x00000010
#define	NBCLK_IO_CONTROL1__USBCLK_PU__SHIFT                0x00000014
#define	NBCLK_IO_CONTROL1__USBCLK_PD__SHIFT                0x00000015
#define	NBCLK_IO_CONTROL1__USBCLK_SRP__SHIFT               0x00000016
#define	NBCLK_IO_CONTROL1__USBCLK_SRN__SHIFT               0x00000017
#define	NBCLK_IO_CONTROL1__USBCLK_SP__SHIFT                0x00000018
#define	NBCLK_IO_CONTROL1__USBCLK_SN__SHIFT                0x0000001c

// NBCLK_IO_CONTROL2
#define	NBCLK_IO_CONTROL2__AGPCLKOUT_PU__SHIFT             0x00000000
#define	NBCLK_IO_CONTROL2__AGPCLKOUT_PD__SHIFT             0x00000001
#define	NBCLK_IO_CONTROL2__AGPCLKOUT_SRP__SHIFT            0x00000002
#define	NBCLK_IO_CONTROL2__AGPCLKOUT_SRN__SHIFT            0x00000003
#define	NBCLK_IO_CONTROL2__AGPCLKOUT_SP__SHIFT             0x00000004
#define	NBCLK_IO_CONTROL2__AGPCLKOUT_SN__SHIFT             0x00000008
#define	NBCLK_IO_CONTROL2__ALINK_CLK_PU__SHIFT             0x00000010
#define	NBCLK_IO_CONTROL2__ALINK_CLK_PD__SHIFT             0x00000011
#define	NBCLK_IO_CONTROL2__ALINK_CLK_SRP__SHIFT            0x00000012
#define	NBCLK_IO_CONTROL2__ALINK_CLK_SRN__SHIFT            0x00000013
#define	NBCLK_IO_CONTROL2__ALINK_CLK_SP__SHIFT             0x00000014
#define	NBCLK_IO_CONTROL2__ALINK_CLK_SN__SHIFT             0x00000018

// CLK_TOP_SPARE_A
#define	CLK_TOP_SPARE_A__MCLK_SWITCH_GFX_EN__SHIFT         0x00000000
#define	CLK_TOP_SPARE_A__BIU_MEMAB_CPUSTOP_DIS__SHIFT      0x00000001
#define	CLK_TOP_SPARE_A__BIU_NB1_CPUSTOP_DIS__SHIFT        0x00000002
#define	CLK_TOP_SPARE_A__BIU_NB2_CPUSTOP_DIS__SHIFT        0x00000003
#define	CLK_TOP_SPARE_A__BIU_NB1AB_CPUSTOP_DIS__SHIFT      0x00000004
#define	CLK_TOP_SPARE_A__AGP_B1X_PM1_CPUSTOP_DIS__SHIFT    0x00000005
#define	CLK_TOP_SPARE_A__PCIM_CPUSTOP_DIS__SHIFT           0x00000006
#define	CLK_TOP_SPARE_A__PCIT_CPUSTOP_DIS__SHIFT           0x00000007
#define	CLK_TOP_SPARE_A__CFG_B1X_CPUSTOP_DIS__SHIFT        0x00000008
#define	CLK_TOP_SPARE_A__CFG_S1X_CPUSTOP_DIS__SHIFT        0x00000009
#define	CLK_TOP_SPARE_A__PCIM_S1X_CPUSTOP_DIS__SHIFT       0x0000000a
#define	CLK_TOP_SPARE_A__OSC_PU__SHIFT                     0x00000010
#define	CLK_TOP_SPARE_A__OSC_PD__SHIFT                     0x00000011
#define	CLK_TOP_SPARE_A__OSC_SRP__SHIFT                    0x00000012
#define	CLK_TOP_SPARE_A__OSC_SRN__SHIFT                    0x00000013
#define	CLK_TOP_SPARE_A__OSC_SP__SHIFT                     0x00000014
#define	CLK_TOP_SPARE_A__OSC_SN__SHIFT                     0x00000018
#define	CLK_TOP_SPARE_A__IOSPLL_ISKEW_1X__SHIFT            0x0000001c
#define	CLK_TOP_SPARE_A__IOSPLL_CAL_TRIGGER__SHIFT         0x0000001f

// CLK_TOP_SPARE_B
#define	CLK_TOP_SPARE_B__CLK_TOP_SPAREB__SHIFT             0x00000000

// CLK_TOP_SPARE_C
#define	CLK_TOP_SPARE_C__CLK_TOP_SPAREC__SHIFT             0x00000000

// CLK_TOP_SPARE_D
#define	CLK_TOP_SPARE_D__CLK_TOP_SPARED__SHIFT             0x00000000

// APC_VENDOR_ID
#define	APC_VENDOR_ID__VENDOR_ID__SHIFT                    0x00000000

// APC_DEVICE_ID
#define	APC_DEVICE_ID__DEVICE_ID__SHIFT                    0x00000000

// APC_COMMAND
#define	APC_COMMAND__IO_ACCESS_EN__SHIFT                   0x00000000
#define	APC_COMMAND__MEM_ACCESS_EN__SHIFT                  0x00000001
#define	APC_COMMAND__BUS_MASTER_EN__SHIFT                  0x00000002
#define	APC_COMMAND__SPECIAL_CYCLE_EN__SHIFT               0x00000003
#define	APC_COMMAND__MEM_WRITE_INVALIDATE_EN__SHIFT        0x00000004
#define	APC_COMMAND__PAL_SNOOP_EN__SHIFT                   0x00000005
#define	APC_COMMAND__PARITY_ERROR_EN__SHIFT                0x00000006
#define	APC_COMMAND__Reserved0__SHIFT                      0x00000007
#define	APC_COMMAND__SERR_EN__SHIFT                        0x00000008
#define	APC_COMMAND__FAST_B2B_EN__SHIFT                    0x00000009
#define	APC_COMMAND__Reserved__SHIFT                       0x0000000a

// APC_STATUS
#define	APC_STATUS__CAP_LIST__SHIFT                        0x00000004
#define	APC_STATUS__PCI_66_EN__SHIFT                       0x00000005
#define	APC_STATUS__UDF_EN__SHIFT                          0x00000006
#define	APC_STATUS__FAST_BACK_CAPABLE__SHIFT               0x00000007
#define	APC_STATUS__DEVSEL_TIMING__SHIFT                   0x00000009
#define	APC_STATUS__SIGNAL_TARGET_ABORT__SHIFT             0x0000000b
#define	APC_STATUS__RECEIVED_TARGET_ABORT__SHIFT           0x0000000c
#define	APC_STATUS__RECEIVED_MASTER_ABORT__SHIFT           0x0000000d
#define	APC_STATUS__SIGNALED_SYSTEM_ERROR__SHIFT           0x0000000e
#define	APC_STATUS__PARITY_ERROR_DETECTED__SHIFT           0x0000000f

// APC_REVISION_ID
#define	APC_REVISION_ID__MINOR_REV_ID__SHIFT               0x00000000
#define	APC_REVISION_ID__MAJOR_REV_ID__SHIFT               0x00000004

// APC_REGPROG_INF
#define	APC_REGPROG_INF__REG_LEVEL_PROG_INF__SHIFT         0x00000000

// APC_SUB_CLASS
#define	APC_SUB_CLASS__SUB_CLASS_INF__SHIFT                0x00000000

// APC_BASE_CODE
#define	APC_BASE_CODE__BASE_CLASS_CODE__SHIFT              0x00000000

// APC_CACHE_LINE
#define	APC_CACHE_LINE__CACHE_LINE_SIZE__SHIFT             0x00000000

// APC_LATENCY
#define	APC_LATENCY__LATENCY_TIMER__SHIFT                  0x00000000

// APC_HEADER
#define	APC_HEADER__HEADER_TYPE__SHIFT                     0x00000000

// APC_BIST
#define	APC_BIST__BIST_COMP__SHIFT                         0x00000000
#define	APC_BIST__BIST_STRT__SHIFT                         0x00000006
#define	APC_BIST__BIST_CAP__SHIFT                          0x00000007

// APC_SUB_BUS_NUMBER_LATENCY
#define	APC_SUB_BUS_NUMBER_LATENCY__PRIMARY_BUS__SHIFT     0x00000000
#define	APC_SUB_BUS_NUMBER_LATENCY__SECONDARY_BUS__SHIFT   0x00000008
#define	APC_SUB_BUS_NUMBER_LATENCY__SUB_BUS_NUMBER__SHIFT  0x00000010
#define	APC_SUB_BUS_NUMBER_LATENCY__SECONDARY_LATENCY_TIMER__SHIFT 0x00000018

// APC_AGP_PCI_IOBASE_LIMIT
#define	APC_AGP_PCI_IOBASE_LIMIT__IO_BASE_R__SHIFT         0x00000000
#define	APC_AGP_PCI_IOBASE_LIMIT__IO_BASE__SHIFT           0x00000004
#define	APC_AGP_PCI_IOBASE_LIMIT__IO_LIMIT_R__SHIFT        0x00000008
#define	APC_AGP_PCI_IOBASE_LIMIT__IO_LIMIT__SHIFT          0x0000000c

// APC_AGP_PCI_STATUS
#define	APC_AGP_PCI_STATUS__CAP_LIST__SHIFT                0x00000004
#define	APC_AGP_PCI_STATUS___66M__SHIFT                    0x00000005
#define	APC_AGP_PCI_STATUS__UDF_EN__SHIFT                  0x00000006
#define	APC_AGP_PCI_STATUS__FAST_B2B_CAPABLE__SHIFT        0x00000007
#define	APC_AGP_PCI_STATUS__DATA_PERR__SHIFT               0x00000008
#define	APC_AGP_PCI_STATUS__DEVSEL_TIMING__SHIFT           0x00000009
#define	APC_AGP_PCI_STATUS__SIGNAL_TARGET_ABORT__SHIFT     0x0000000b
#define	APC_AGP_PCI_STATUS__TARGET_ABORT__SHIFT            0x0000000c
#define	APC_AGP_PCI_STATUS__MASTER_ABORT__SHIFT            0x0000000d
#define	APC_AGP_PCI_STATUS__SYSTEM_ERROR__SHIFT            0x0000000e
#define	APC_AGP_PCI_STATUS__PARITY_ERROR__SHIFT            0x0000000f

// APC_AGP_PCI_MEMORY_LIMIT_BASE
#define	APC_AGP_PCI_MEMORY_LIMIT_BASE__MEM_BASE_31_20__SHIFT 0x00000004
#define	APC_AGP_PCI_MEMORY_LIMIT_BASE__MEM_LIMIT_31_20__SHIFT 0x00000014

// APC_AGP_PCI_PREFETCHABLE_LIMIT_BASE
#define	APC_AGP_PCI_PREFETCHABLE_LIMIT_BASE__PREF_MEM_BASE_31_16__SHIFT 0x00000000
#define	APC_AGP_PCI_PREFETCHABLE_LIMIT_BASE__PREF_MEMLIMIT_31_16__SHIFT 0x00000010

// APC_ADAPTER_ID
#define	APC_ADAPTER_ID__SUBSYSTEM_VENDOR_ID__SHIFT         0x00000000
#define	APC_ADAPTER_ID__SUBSYSTEM_ID__SHIFT                0x00000010

// APC_AGP_PCI_IO_LIMIT_BASE_HI
#define	APC_AGP_PCI_IO_LIMIT_BASE_HI__IO_BASE_31_16__SHIFT 0x00000000
#define	APC_AGP_PCI_IO_LIMIT_BASE_HI__IO_LIMIT_31_16__SHIFT 0x00000010

// APC_AGP_PCI_IRQ_BRIDGE_CTRL
#define	APC_AGP_PCI_IRQ_BRIDGE_CTRL__INT_LINE__SHIFT       0x00000000
#define	APC_AGP_PCI_IRQ_BRIDGE_CTRL__INT_PIN__SHIFT        0x00000008
#define	APC_AGP_PCI_IRQ_BRIDGE_CTRL__PARITY_RESPONSE_EN__SHIFT 0x00000010
#define	APC_AGP_PCI_IRQ_BRIDGE_CTRL__SERR_EN__SHIFT        0x00000011
#define	APC_AGP_PCI_IRQ_BRIDGE_CTRL__ISA_EN__SHIFT         0x00000012
#define	APC_AGP_PCI_IRQ_BRIDGE_CTRL__VGA_EN__SHIFT         0x00000013
#define	APC_AGP_PCI_IRQ_BRIDGE_CTRL__MASTER_ABORT_MODE__SHIFT 0x00000015
#define	APC_AGP_PCI_IRQ_BRIDGE_CTRL__SECONDARY_BUS_RESET__SHIFT 0x00000016
#define	APC_AGP_PCI_IRQ_BRIDGE_CTRL__FAST_B2B_CAPABLE__SHIFT 0x00000017

// APC_MISC_DEVICE_CTRL
#define	APC_MISC_DEVICE_CTRL__INT_PIN_CTRL__SHIFT          0x00000000

// APC_ADAPTER_ID_W
#define	APC_ADAPTER_ID_W__SUBSYSTEM_VENDOR_ID__SHIFT       0x00000000
#define	APC_ADAPTER_ID_W__SUBSYSTEM_ID__SHIFT              0x00000010

// NB_AGPS_CTRL
#define	NB_AGPS_CTRL__HOLD_RQ_FIFO__SHIFT                  0x00000000
#define	NB_AGPS_CTRL__HOLD_WR_FIFO__SHIFT                  0x00000001
#define	NB_AGPS_CTRL__HOLD_RD_FIFO__SHIFT                  0x00000002
#define	NB_AGPS_CTRL__HOLD_WREQ_FIFO__SHIFT                0x00000003
#define	NB_AGPS_CTRL__HOLD_RDSIZE_FIFO__SHIFT              0x00000004
#define	NB_AGPS_CTRL__DELAY_RDSIZE_FIFO__SHIFT             0x00000005
#define	NB_AGPS_CTRL__EN_2X_STBB__SHIFT                    0x00000006
#define	NB_AGPS_CTRL__EN_EXTENDED_AD_STB_2X__SHIFT         0x00000007
#define	NB_AGPS_CTRL__REG_CRIPPLE_AGP4X__SHIFT             0x00000008
#define	NB_AGPS_CTRL__REG_CRIPPLE_AGP2X4X__SHIFT           0x00000009
#define	NB_AGPS_CTRL__REG_CRIPPLE_AGP8X__SHIFT             0x0000000a
#define	NB_AGPS_CTRL__REG_CRIPPLE_AGP4X8X__SHIFT           0x0000000b
#define	NB_AGPS_CTRL__SBADEC_SOFT_RESET__SHIFT             0x0000000c
#define	NB_AGPS_CTRL__PCI_DBI_DISABLE__SHIFT               0x0000000d
#define	NB_AGPS_CTRL__AGP_DBI_DISABLE__SHIFT               0x0000000e
#define	NB_AGPS_CTRL__DBI_MINIMIZE_ONES__SHIFT             0x0000000f
#define	NB_AGPS_CTRL__DBL_RSYNC_RRMEM_RPTR__SHIFT          0x00000010
#define	NB_AGPS_CTRL__DBL_RSYNC_RDSZ_RPTR__SHIFT           0x00000011
#define	NB_AGPS_CTRL__DBL_RSYNC_RDSZ_WPTR__SHIFT           0x00000012
#define	NB_AGPS_CTRL__AGPS_HOLD_RDSIZEMEM__SHIFT           0x00000013
#define	NB_AGPS_CTRL__AGPS_HOLD_RDSIZE_FIFO__SHIFT         0x00000014
#define	NB_AGPS_CTRL__MISC__SHIFT                          0x00000015
#define	NB_AGPS_CTRL__DBL_RSYNC_WRFIFO_RPTR__SHIFT         0x00000016
#define	NB_AGPS_CTRL__DBL_RSYNC_WRFIFO_WPTR__SHIFT         0x00000017
#define	NB_AGPS_CTRL__DBL_RSYNC_RDFIFO_RPTR__SHIFT         0x00000018
#define	NB_AGPS_CTRL__DBL_RSYNC_RDFIFO_WPTR__SHIFT         0x00000019
#define	NB_AGPS_CTRL__DBL_RSYNC_RQFIFO_RPTR__SHIFT         0x0000001a
#define	NB_AGPS_CTRL__DBL_RSYNC_RQFIFO_WPTR__SHIFT         0x0000001b
#define	NB_AGPS_CTRL__DBL_RSYNC_WREQ_RPTR__SHIFT           0x0000001c
#define	NB_AGPS_CTRL__DBL_RSYNC_WREQ_WPTR__SHIFT           0x0000001d
#define	NB_AGPS_CTRL__DBL_RSYNC_RDSIZE_RPTR__SHIFT         0x0000001e
#define	NB_AGPS_CTRL__DBL_RSYNC_RDSIZE_WPTR__SHIFT         0x0000001f

// NB_AGP_FIFO_CTRL
#define	NB_AGP_FIFO_CTRL__WREQFIFO_WM_MIN__SHIFT           0x00000000
#define	NB_AGP_FIFO_CTRL__WREQFIFO_WM_MAX__SHIFT           0x00000004

// NB_APC_FIFO_CTRL
#define	NB_APC_FIFO_CTRL__MDF_RDF_DBL_SYNC_RPTR__SHIFT     0x00000000
#define	NB_APC_FIFO_CTRL__MDF_RDF_DBL_SYNC_WPTR__SHIFT     0x00000001
#define	NB_APC_FIFO_CTRL__MDF_WRF_DBL_SYNC_RPTR__SHIFT     0x00000002
#define	NB_APC_FIFO_CTRL__MDF_WRF_DBL_SYNC_WPTR__SHIFT     0x00000003
#define	NB_APC_FIFO_CTRL__TWR_TMF_DBL_SYNC_RPTR__SHIFT     0x00000004
#define	NB_APC_FIFO_CTRL__TWR_TMF_DBL_SYNC_WPTR__SHIFT     0x00000005
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT06__SHIFT       0x00000006
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT07__SHIFT       0x00000007
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT08__SHIFT       0x00000008
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT09__SHIFT       0x00000009
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT10__SHIFT       0x0000000a
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT11__SHIFT       0x0000000b
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT12__SHIFT       0x0000000c
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT13__SHIFT       0x0000000d
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT14__SHIFT       0x0000000e
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT15__SHIFT       0x0000000f
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT16__SHIFT       0x00000010
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT17__SHIFT       0x00000011
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT18__SHIFT       0x00000012
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT19__SHIFT       0x00000013
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT20__SHIFT       0x00000014
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT21__SHIFT       0x00000015
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT22__SHIFT       0x00000016
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT23__SHIFT       0x00000017
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT24__SHIFT       0x00000018
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT25__SHIFT       0x00000019
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT26__SHIFT       0x0000001a
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT27__SHIFT       0x0000001b
#define	NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT28__SHIFT       0x0000001c
#define	NB_APC_FIFO_CTRL__HOLD_FW_FIFO__SHIFT              0x0000001d
#define	NB_APC_FIFO_CTRL__RSYNC_FW_FIFO_RPTR__SHIFT        0x0000001e
#define	NB_APC_FIFO_CTRL__RSYNC_FW_FIFO_WPTR__SHIFT        0x0000001f

// NB_PCI_FIFO_CTRL
#define	NB_PCI_FIFO_CTRL__MDF_RDF_DBL_SYNC_RPTR__SHIFT     0x00000000
#define	NB_PCI_FIFO_CTRL__MDF_RDF_DBL_SYNC_WPTR__SHIFT     0x00000001
#define	NB_PCI_FIFO_CTRL__MDF_WRF_DBL_SYNC_RPTR__SHIFT     0x00000002
#define	NB_PCI_FIFO_CTRL__MDF_WRF_DBL_SYNC_WPTR__SHIFT     0x00000003
#define	NB_PCI_FIFO_CTRL__TWR_TMF_DBL_SYNC_RPTR__SHIFT     0x00000004
#define	NB_PCI_FIFO_CTRL__TWR_TMF_DBL_SYNC_WPTR__SHIFT     0x00000005
#define	NB_PCI_FIFO_CTRL__TWR_PTPF_DBL_SYNC_RPTR__SHIFT    0x00000006
#define	NB_PCI_FIFO_CTRL__TWR_PTPF_DBL_SYNC_WPTR__SHIFT    0x00000007
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT08__SHIFT       0x00000008
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT09__SHIFT       0x00000009
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT10__SHIFT       0x0000000a
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT11__SHIFT       0x0000000b
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT12__SHIFT       0x0000000c
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT13__SHIFT       0x0000000d
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT14__SHIFT       0x0000000e
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT15__SHIFT       0x0000000f
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT16__SHIFT       0x00000010
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT17__SHIFT       0x00000011
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT18__SHIFT       0x00000012
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT19__SHIFT       0x00000013
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT20__SHIFT       0x00000014
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT21__SHIFT       0x00000015
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT22__SHIFT       0x00000016
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT23__SHIFT       0x00000017
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT24__SHIFT       0x00000018
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT25__SHIFT       0x00000019
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT26__SHIFT       0x0000001a
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT27__SHIFT       0x0000001b
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT28__SHIFT       0x0000001c
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT29__SHIFT       0x0000001d
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT30__SHIFT       0x0000001e
#define	NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT31__SHIFT       0x0000001f

// NB_PAD_CTLR_STRENGTH
#define	NB_PAD_CTLR_STRENGTH__PAD_N_STRENGTH_SBA_CNTL__SHIFT 0x00000000
#define	NB_PAD_CTLR_STRENGTH__PAD_P_STRENGTH_SBA_CNTL__SHIFT 0x00000008
#define	NB_PAD_CTLR_STRENGTH__PAD_MANUAL_OVERRIDE_L__SHIFT 0x0000000f
#define	NB_PAD_CTLR_STRENGTH__PAD_N_STRENGTH_ADH_ADL__SHIFT 0x00000010
#define	NB_PAD_CTLR_STRENGTH__PAD_P_STRENGTH_ADH_ADL__SHIFT 0x00000018
#define	NB_PAD_CTLR_STRENGTH__PAD_MANUAL_OVERRIDE_H__SHIFT 0x0000001f

// NB_PAD_CTLR_STRENGTH_READBACK
#define	NB_PAD_CTLR_STRENGTH_READBACK__PAD_N_STRENGTH_SBA_CNTL_RB__SHIFT 0x00000000
#define	NB_PAD_CTLR_STRENGTH_READBACK__PAD_P_STRENGTH_SBA_CNTL_RB__SHIFT 0x00000008
#define	NB_PAD_CTLR_STRENGTH_READBACK__PAD_N_STRENGTH_ADH_ADL_RB__SHIFT 0x00000010
#define	NB_PAD_CTLR_STRENGTH_READBACK__PAD_P_STRENGTH_ADH_ADL_RB__SHIFT 0x00000018

// NB_PAD_CTLR_UPDATE
#define	NB_PAD_CTLR_UPDATE__PAD_UPDATE_RATE__SHIFT         0x00000000
#define	NB_PAD_CTLR_UPDATE__PAD_SAMPLE_DELAY__SHIFT        0x00000008
#define	NB_PAD_CTLR_UPDATE__PAD_INC_THRESHOLD__SHIFT       0x00000010
#define	NB_PAD_CTLR_UPDATE__PAD_DEC_THRESHOLD__SHIFT       0x00000018

// NB_PAD_CTLR_MISC
#define	NB_PAD_CTLR_MISC__DYNAMIC_IMP_EN__SHIFT            0x00000000
#define	NB_PAD_CTLR_MISC__DISABLE_WPTR_RST__SHIFT          0x00000001
#define	NB_PAD_CTLR_MISC__PAD_VREF_INT_EN__SHIFT           0x00000002
#define	NB_PAD_CTLR_MISC__AUTO_AGP_RSYNC_EN__SHIFT         0x00000005
#define	NB_PAD_CTLR_MISC__AGP_RSYNC_AD_DURING_WR_IDLE_EN__SHIFT 0x00000006
#define	NB_PAD_CTLR_MISC__MANUAL_AGP_RSYNC__SHIFT          0x00000007
#define	NB_PAD_CTLR_MISC__PAD_HI_IO_PREAMPH__SHIFT         0x00000008
#define	NB_PAD_CTLR_MISC__PAD_HI_IO_PREAMPH_STB__SHIFT     0x00000009
#define	NB_PAD_CTLR_MISC__PAD_PAR_RB__SHIFT                0x0000000a
#define	NB_PAD_CTLR_MISC__PAD_AGP30_SIG_SBA_UPDATE_CNTL__SHIFT 0x0000000d
#define	NB_PAD_CTLR_MISC__PAD_AGP30_SIG_SBA_CAL_DIS__SHIFT 0x0000000e
#define	NB_PAD_CTLR_MISC__PAD_AGP30_SIG_TRDY_DIS__SHIFT    0x0000000f
#define	NB_PAD_CTLR_MISC__PAD_AGP30SIGNALING_CAL_DIS__SHIFT 0x00000010
#define	NB_PAD_CTLR_MISC__PAD_TEST_OUT__SHIFT              0x00000011
#define	NB_PAD_CTLR_MISC__PAD_DUMMY_OUT__SHIFT             0x00000012
#define	NB_PAD_CTLR_MISC__PAD_HI_IO_DFR__SHIFT             0x00000013
#define	NB_PAD_CTLR_MISC__PAD_HI_IO_SCHMEN__SHIFT          0x00000014
#define	NB_PAD_CTLR_MISC__PAD_HI_IO_DREN__SHIFT            0x00000015
#define	NB_PAD_CTLR_MISC__PAD_HI_IO_VDIFF__SHIFT           0x00000017
#define	NB_PAD_CTLR_MISC__PAD_HI_IO_DFR_OVERRIDE__SHIFT    0x00000018
#define	NB_PAD_CTLR_MISC__PAD_HI_IO_SCHMEN_OVERRIDE__SHIFT 0x00000019
#define	NB_PAD_CTLR_MISC__PAD_HI_IO_DREN_OVERRIDE__SHIFT   0x0000001a
#define	NB_PAD_CTLR_MISC__PAD_HI_IO_VDIFF_OVERRIDE__SHIFT  0x0000001c
#define	NB_PAD_CTLR_MISC__PAD_HI_IO_SLEWN__SHIFT           0x0000001d
#define	NB_PAD_CTLR_MISC__PAD_HI_IO_SLEWP__SHIFT           0x0000001e
#define	NB_PAD_CTLR_MISC__PAD_HI_IO_SLEW_OVERRIDE__SHIFT   0x0000001f

// NB_PAMAC0_DLY_CNTL
#define	NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_DATA_U__SHIFT    0x00000000
#define	NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_DATA_L__SHIFT    0x00000004
#define	NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_STB__SHIFT       0x00000008
#define	NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_DBI__SHIFT       0x0000000c
#define	NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_DATA_U__SHIFT   0x00000010
#define	NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_DATA_L__SHIFT   0x00000012
#define	NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_STB__SHIFT      0x00000014
#define	NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_DBI__SHIFT      0x00000016
#define	NB_PAMAC0_DLY_CNTL__PAMAC0_CLK_INS_DLY__SHIFT      0x00000018
#define	NB_PAMAC0_DLY_CNTL__PAMAC0_SYNC_DLY__SHIFT         0x00000019

// NB_PAMAC1_DLY_CNTL
#define	NB_PAMAC1_DLY_CNTL__PAMAC1_DLY_IN_DATA_U__SHIFT    0x00000000
#define	NB_PAMAC1_DLY_CNTL__PAMAC1_DLY_IN_DATA_L__SHIFT    0x00000004
#define	NB_PAMAC1_DLY_CNTL__PAMAC1_DLY_IN_STB__SHIFT       0x00000008
#define	NB_PAMAC1_DLY_CNTL__PAMAC1_DLY_OUT_DATA_U__SHIFT   0x00000010
#define	NB_PAMAC1_DLY_CNTL__PAMAC1_DLY_OUT_DATA_L__SHIFT   0x00000012
#define	NB_PAMAC1_DLY_CNTL__PAMAC1_DLY_OUT_STB__SHIFT      0x00000014
#define	NB_PAMAC1_DLY_CNTL__PAMAC1_CLK_INS_DLY__SHIFT      0x00000018
#define	NB_PAMAC1_DLY_CNTL__PAMAC1_SYNC_DLY__SHIFT         0x00000019

// NB_PAMAC2_DLY_CNTL
#define	NB_PAMAC2_DLY_CNTL__PAMAC2_DLY_IN_DATA_U__SHIFT    0x00000000
#define	NB_PAMAC2_DLY_CNTL__PAMAC2_DLY_IN_DATA_L__SHIFT    0x00000004
#define	NB_PAMAC2_DLY_CNTL__PAMAC2_DLY_IN_STB__SHIFT       0x00000008
#define	NB_PAMAC2_DLY_CNTL__PAMAC2_DLY_OUT_DATA_U__SHIFT   0x00000010
#define	NB_PAMAC2_DLY_CNTL__PAMAC2_DLY_OUT_DATA_L__SHIFT   0x00000012
#define	NB_PAMAC2_DLY_CNTL__PAMAC2_DLY_OUT_STB__SHIFT      0x00000014
#define	NB_PAMAC2_DLY_CNTL__PAMAC2_CLK_INS_DLY__SHIFT      0x00000018
#define	NB_PAMAC2_DLY_CNTL__PAMAC2_SYNC_DLY__SHIFT         0x00000019

// NB_AGP_DEBUG
#define	NB_AGP_DEBUG__ADL_DfrOverride__SHIFT               0x00000000
#define	NB_AGP_DEBUG__ADL_DrenOverride__SHIFT              0x00000001
#define	NB_AGP_DEBUG__ADL_SchmenOverride__SHIFT            0x00000002
#define	NB_AGP_DEBUG__ADL_Dfr__SHIFT                       0x00000003
#define	NB_AGP_DEBUG__ADL_Dren__SHIFT                      0x00000004
#define	NB_AGP_DEBUG__ADL_Schmen__SHIFT                    0x00000005
#define	NB_AGP_DEBUG__ADH_DfrOverride__SHIFT               0x00000006
#define	NB_AGP_DEBUG__ADH_DrenOverride__SHIFT              0x00000007
#define	NB_AGP_DEBUG__ADH_SchmenOverride__SHIFT            0x00000008
#define	NB_AGP_DEBUG__ADH_Dfr__SHIFT                       0x00000009
#define	NB_AGP_DEBUG__ADH_Dren__SHIFT                      0x0000000a
#define	NB_AGP_DEBUG__ADH_Schmen__SHIFT                    0x0000000b
#define	NB_AGP_DEBUG__PerfCnt0ClkSel__SHIFT                0x0000000c
#define	NB_AGP_DEBUG__PerfCnt1ClkSel__SHIFT                0x0000000d
#define	NB_AGP_DEBUG__AGP_DEBUG_14__SHIFT                  0x0000000e
#define	NB_AGP_DEBUG__AGP_DEBUG_15__SHIFT                  0x0000000f
#define	NB_AGP_DEBUG__AGP_DEBUG_16__SHIFT                  0x00000010
#define	NB_AGP_DEBUG__AGP_DEBUG_17__SHIFT                  0x00000011
#define	NB_AGP_DEBUG__AGP_DEBUG_18__SHIFT                  0x00000012
#define	NB_AGP_DEBUG__AGP_DEBUG_19__SHIFT                  0x00000013
#define	NB_AGP_DEBUG__AGP_DEBUG_20__SHIFT                  0x00000014
#define	NB_AGP_DEBUG__AGP_DEBUG_21__SHIFT                  0x00000015
#define	NB_AGP_DEBUG__AGP_DEBUG_22__SHIFT                  0x00000016
#define	NB_AGP_DEBUG__AGP_DEBUG_23__SHIFT                  0x00000017
#define	NB_AGP_DEBUG__AGP_DEBUG_24__SHIFT                  0x00000018
#define	NB_AGP_DEBUG__AGP_DEBUG_25__SHIFT                  0x00000019
#define	NB_AGP_DEBUG__AGP_DEBUG_26__SHIFT                  0x0000001a
#define	NB_AGP_DEBUG__AGP_DEBUG_27__SHIFT                  0x0000001b
#define	NB_AGP_DEBUG__AGP_DEBUG_28__SHIFT                  0x0000001c
#define	NB_AGP_DEBUG__AGP_DEBUG_29__SHIFT                  0x0000001d
#define	NB_AGP_DEBUG__AGP_DEBUG_30__SHIFT                  0x0000001e
#define	NB_AGP_DEBUG__AGP_DEBUG_31__SHIFT                  0x0000001f

// NB_ALINK_PERF_COUNT0
#define	NB_ALINK_PERF_COUNT0__COUNTER_0__SHIFT             0x00000000

// NB_ALINK_PERF_COUNT1
#define	NB_ALINK_PERF_COUNT1__COUNTER_1__SHIFT             0x00000000

// NB_ALINK_PERF_CNTL
#define	NB_ALINK_PERF_CNTL__EVENT0_SEL__SHIFT              0x00000000
#define	NB_ALINK_PERF_CNTL__EVENT1_SEL__SHIFT              0x00000008
#define	NB_ALINK_PERF_CNTL__COUNTER_0__SHIFT               0x00000010
#define	NB_ALINK_PERF_CNTL__COUNTER_1__SHIFT               0x00000018

// NB_ALINK_CFG2

// NB_ALINK2_CFG_CNTL
#define	NB_ALINK2_CFG_CNTL__ALINK2_ENABLE__SHIFT           0x00000000
#define	NB_ALINK2_CFG_CNTL__PAD_DEC_THRESHOLD__SHIFT       0x00000001
#define	NB_ALINK2_CFG_CNTL__PAD_INC_THRESHOLD__SHIFT       0x00000006
#define	NB_ALINK2_CFG_CNTL__PAD_SAMPLE_DELAY__SHIFT        0x0000000b
#define	NB_ALINK2_CFG_CNTL__PAD_UPDATE_RATE__SHIFT         0x00000010

// NB_ALINK2_TNX_CNTL
#define	NB_ALINK2_TNX_CNTL__AL2_DBIEn__SHIFT               0x00000000
#define	NB_ALINK2_TNX_CNTL__AL2_BurstReadMEn__SHIFT        0x00000001
#define	NB_ALINK2_TNX_CNTL__AL2_WFifoSz__SHIFT             0x00000002
#define	NB_ALINK2_TNX_CNTL__AL2_RFifoSz__SHIFT             0x00000004
#define	NB_ALINK2_TNX_CNTL__AL2_AFifoSz__SHIFT             0x00000006
#define	NB_ALINK2_TNX_CNTL__AL2_CalResetEn__SHIFT          0x00000009
#define	NB_ALINK2_TNX_CNTL__AL2_CalCycleEn__SHIFT          0x0000000a
#define	NB_ALINK2_TNX_CNTL__AL2_BurstReadTEn__SHIFT        0x0000000b
#define	NB_ALINK2_TNX_CNTL__AL2_PostWriteTimeOutEn__SHIFT  0x0000000d
#define	NB_ALINK2_TNX_CNTL__AL2_NonPostWriteTimeOutEn__SHIFT 0x0000000e
#define	NB_ALINK2_TNX_CNTL__AL2_ReadTimeOutEn__SHIFT       0x0000000f
#define	NB_ALINK2_TNX_CNTL__AL2_ArbPriority__SHIFT         0x00000010
#define	NB_ALINK2_TNX_CNTL__AL2_Mode__SHIFT                0x00000012
#define	NB_ALINK2_TNX_CNTL__AL2_DecTiming__SHIFT           0x00000014
#define	NB_ALINK2_TNX_CNTL__AL2_MasterAbortStatus__SHIFT   0x00000016
#define	NB_ALINK2_TNX_CNTL__AL2_ADFifoSzM__SHIFT           0x00000017
#define	NB_ALINK2_TNX_CNTL__AL2_WriteFifoSzM__SHIFT        0x0000001a
#define	NB_ALINK2_TNX_CNTL__AL2_ReadFifoSzM__SHIFT         0x0000001c

// NB_ALINK_PAD_CNTL
#define	NB_ALINK_PAD_CNTL__dly_in_AD7_0__SHIFT             0x00000000
#define	NB_ALINK_PAD_CNTL__dly_in_AD8_15__SHIFT            0x00000004
#define	NB_ALINK_PAD_CNTL__dly_in_CBE1_0__SHIFT            0x00000008
#define	NB_ALINK_PAD_CNTL__dly_in_STB__SHIFT               0x0000000c
#define	NB_ALINK_PAD_CNTL__dly_in_DBI__SHIFT               0x00000010
#define	NB_ALINK_PAD_CNTL__dly_out_AD7_0__SHIFT            0x00000014
#define	NB_ALINK_PAD_CNTL__dly_out_AD8_15__SHIFT           0x00000016
#define	NB_ALINK_PAD_CNTL__dly_out_CBE1_0__SHIFT           0x00000018
#define	NB_ALINK_PAD_CNTL__dly_out_STB__SHIFT              0x0000001a
#define	NB_ALINK_PAD_CNTL__dly_out_DBI__SHIFT              0x0000001c
#define	NB_ALINK_PAD_CNTL__AL2_signalmode__SHIFT           0x0000001e

// NB_ALINK_PAD_CNTL2
#define	NB_ALINK_PAD_CNTL2__AL28xMode__SHIFT               0x00000000
#define	NB_ALINK_PAD_CNTL2__preamph1_5__SHIFT              0x00000001
#define	NB_ALINK_PAD_CNTL2__en5_eightxsig__SHIFT           0x00000002
#define	NB_ALINK_PAD_CNTL2__PAD_MANUAL_OVERRIDE__SHIFT     0x00000003
#define	NB_ALINK_PAD_CNTL2__PAD_P_MANUAL_STRENGTH__SHIFT   0x00000004
#define	NB_ALINK_PAD_CNTL2__PAD_N_MANUAL_STRENGTH__SHIFT   0x00000009
#define	NB_ALINK_PAD_CNTL2__DYNAMIC_IMP_EN__SHIFT          0x0000000e
#define	NB_ALINK_PAD_CNTL2__PAD_P_STRENGTH_READ_BACK__SHIFT 0x0000000f
#define	NB_ALINK_PAD_CNTL2__PAD_N_STRENGTH_READ_BACK__SHIFT 0x00000014
#define	NB_ALINK_PAD_CNTL2__SRN__SHIFT                     0x00000019
#define	NB_ALINK_PAD_CNTL2__SRP__SHIFT                     0x0000001a
#define	NB_ALINK_PAD_CNTL2__PD__SHIFT                      0x0000001b
#define	NB_ALINK_PAD_CNTL2__PU__SHIFT                      0x0000001c
#define	NB_ALINK_PAD_CNTL2__AL264bitCntl__SHIFT            0x0000001d
#define	NB_ALINK_PAD_CNTL2__AGP_INT_ENABLE__SHIFT          0x0000001f

// BIU_PERF_COUNT0_nb
#define	BIU_PERF_COUNT0_nb__COUNTER0__SHIFT                0x00000000

// BIU_PERF_COUNT1_nb
#define	BIU_PERF_COUNT1_nb__COUNTER1__SHIFT                0x00000000

// BIU_PERF_CNTL_nb
#define	BIU_PERF_CNTL_nb__EVENT0_SEL__SHIFT                0x00000000
#define	BIU_PERF_CNTL_nb__EVENT1_SEL__SHIFT                0x00000008
#define	BIU_PERF_CNTL_nb__COUNTER0_UPPER__SHIFT            0x00000010
#define	BIU_PERF_CNTL_nb__COUNTER1_UPPER__SHIFT            0x00000018

// NB_AGP_PERF_COUNT0
#define	NB_AGP_PERF_COUNT0__COUNTER0__SHIFT                0x00000000

// NB_AGP_PERF_COUNT1
#define	NB_AGP_PERF_COUNT1__COUNTER1__SHIFT                0x00000000

// NB_AGP_PERF_CNTL
#define	NB_AGP_PERF_CNTL__EVENT0_SEL__SHIFT                0x00000000
#define	NB_AGP_PERF_CNTL__EVENT1_SEL__SHIFT                0x00000008
#define	NB_AGP_PERF_CNTL__COUNTER0_UPPER__SHIFT            0x00000010
#define	NB_AGP_PERF_CNTL__COUNTER1_UPPER__SHIFT            0x00000018

// PM2_CNTRL
#define	PM2_CNTRL__ARB_DISABLE__SHIFT                      0x00000000

// GART_FEATURE_ID
#define	GART_FEATURE_ID__REV_ID__SHIFT                     0x00000000
#define	GART_FEATURE_ID__VAL_CAP__SHIFT                    0x00000008
#define	GART_FEATURE_ID__LINK_CAP__SHIFT                   0x00000009
#define	GART_FEATURE_ID__P2P_CAP__SHIFT                    0x0000000a
#define	GART_FEATURE_ID__HANG_EN__SHIFT                    0x0000000b
#define	GART_FEATURE_ID__GARV_ERR_EN__SHIFT                0x00000010
#define	GART_FEATURE_ID__SB_STB_TOGGLE_DETECT_DISABLE__SHIFT 0x00000011
#define	GART_FEATURE_ID__TLB_ENABLE__SHIFT                 0x00000012
#define	GART_FEATURE_ID__P2P_ENABLE__SHIFT                 0x00000013
#define	GART_FEATURE_ID__VAL_ERROR__SHIFT                  0x00000018
#define	GART_FEATURE_ID__GART_CACHE_STATUS__SHIFT          0x0000001a
#define	GART_FEATURE_ID__P2P_STATUS__SHIFT                 0x0000001b
#define	GART_FEATURE_ID__VALID_BIT_ERROR_ID__SHIFT         0x0000001c

// GART_BASE
#define	GART_BASE__DIRECTORY_BASE__SHIFT                   0x0000000c

// GART_CACHE_SZBASE
#define	GART_CACHE_SZBASE__GART_CACHE_SIZE__SHIFT          0x00000000

// GART_CACHE_CNTRL
#define	GART_CACHE_CNTRL__GART_CACHE_INVALIDATE__SHIFT     0x00000000

// GART_CACHE_ENTRY_CNTRL
#define	GART_CACHE_ENTRY_CNTRL__TlB_INV_ENT__SHIFT         0x00000000
#define	GART_CACHE_ENTRY_CNTRL__TlB_UPDATE__SHIFT          0x00000001
#define	GART_CACHE_ENTRY_CNTRL__GART_TABLE_ENTRY_ADDRESS__SHIFT 0x0000000c

#endif


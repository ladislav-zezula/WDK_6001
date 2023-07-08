

#if !defined (_superman_MASK_HEADER)
#define _superman_MASK_HEADER
/*
*	superman_mask.h
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
#define GENENB__BLK_IO_BASE_MASK                           0x000000ffL

// MM_INDEX
#define MM_INDEX__MM_ADDR_MASK                             0x7fffffffL
#define MM_INDEX__MM_APER_MASK                             0x80000000L
#define MM_INDEX__MM_APER                                  0x80000000L

// MM_DATA
#define MM_DATA__MM_DATA_MASK                              0xffffffffL

// BUS_CNTL
#define BUS_CNTL__BUS_DBL_RESYNC_MASK                      0x00000001L
#define BUS_CNTL__BUS_DBL_RESYNC                           0x00000001L
#define BUS_CNTL__BUS_MSTR_RESET_MASK                      0x00000002L
#define BUS_CNTL__BUS_MSTR_RESET                           0x00000002L
#define BUS_CNTL__BUS_FLUSH_BUF_MASK                       0x00000004L
#define BUS_CNTL__BUS_FLUSH_BUF                            0x00000004L
#define BUS_CNTL__BUS_STOP_REQ_DIS_MASK                    0x00000008L
#define BUS_CNTL__BUS_STOP_REQ_DIS                         0x00000008L
#define BUS_CNTL__BUS_READ_COMBINE_EN_MASK                 0x00000010L
#define BUS_CNTL__BUS_READ_COMBINE_EN                      0x00000010L
#define BUS_CNTL__BUS_WRT_COMBINE_EN_MASK                  0x00000020L
#define BUS_CNTL__BUS_WRT_COMBINE_EN                       0x00000020L
#define BUS_CNTL__BUS_MASTER_DIS_MASK                      0x00000040L
#define BUS_CNTL__BUS_MASTER_DIS                           0x00000040L
#define BUS_CNTL__BIOS_ROM_WRT_EN_MASK                     0x00000080L
#define BUS_CNTL__BIOS_ROM_WRT_EN                          0x00000080L
#define BUS_CNTL__BUS_PREFETCH_MODE_MASK                   0x00000300L
#define BUS_CNTL__BUS_VGA_PREFETCH_EN_MASK                 0x00000400L
#define BUS_CNTL__BUS_VGA_PREFETCH_EN                      0x00000400L
#define BUS_CNTL__BUS_SGL_READ_DISABLE_MASK                0x00000800L
#define BUS_CNTL__BUS_SGL_READ_DISABLE                     0x00000800L
#define BUS_CNTL__BIOS_DIS_ROM_MASK                        0x00001000L
#define BUS_CNTL__BIOS_DIS_ROM                             0x00001000L
#define BUS_CNTL__BUS_PCI_READ_RETRY_EN_MASK               0x00002000L
#define BUS_CNTL__BUS_PCI_READ_RETRY_EN                    0x00002000L
#define BUS_CNTL__BUS_AGP_AD_STEPPING_EN_MASK              0x00004000L
#define BUS_CNTL__BUS_AGP_AD_STEPPING_EN                   0x00004000L
#define BUS_CNTL__BUS_PCI_WRT_RETRY_EN_MASK                0x00008000L
#define BUS_CNTL__BUS_PCI_WRT_RETRY_EN                     0x00008000L
#define BUS_CNTL__BUS_RETRY_WS_MASK                        0x000f0000L
#define BUS_CNTL__BUS_MSTR_RD_MULT_MASK                    0x00100000L
#define BUS_CNTL__BUS_MSTR_RD_MULT                         0x00100000L
#define BUS_CNTL__BUS_MSTR_RD_LINE_MASK                    0x00200000L
#define BUS_CNTL__BUS_MSTR_RD_LINE                         0x00200000L
#define BUS_CNTL__BUS_SUSPEND_MASK                         0x00400000L
#define BUS_CNTL__BUS_SUSPEND                              0x00400000L
#define BUS_CNTL__LAT_16X_MASK                             0x00800000L
#define BUS_CNTL__LAT_16X                                  0x00800000L
#define BUS_CNTL__BUS_RD_DISCARD_EN_MASK                   0x01000000L
#define BUS_CNTL__BUS_RD_DISCARD_EN                        0x01000000L
#define BUS_CNTL__ENFRCWRDY_MASK                           0x02000000L
#define BUS_CNTL__ENFRCWRDY                                0x02000000L
#define BUS_CNTL__BUS_MSTR_WS_MASK                         0x04000000L
#define BUS_CNTL__BUS_MSTR_WS                              0x04000000L
#define BUS_CNTL__BUS_PARKING_DIS_MASK                     0x08000000L
#define BUS_CNTL__BUS_PARKING_DIS                          0x08000000L
#define BUS_CNTL__BUS_MSTR_DISCONNECT_EN_MASK              0x10000000L
#define BUS_CNTL__BUS_MSTR_DISCONNECT_EN                   0x10000000L
#define BUS_CNTL__SERR_EN_MASK                             0x20000000L
#define BUS_CNTL__SERR_EN                                  0x20000000L
#define BUS_CNTL__BUS_READ_BURST_MASK                      0x40000000L
#define BUS_CNTL__BUS_READ_BURST                           0x40000000L
#define BUS_CNTL__BUS_RDY_READ_DLY_MASK                    0x80000000L
#define BUS_CNTL__BUS_RDY_READ_DLY                         0x80000000L

// HI_STAT
#define HI_STAT__AGP_BUSY_MASK                             0x00000008L
#define HI_STAT__AGP_BUSY                                  0x00000008L

// BUS_CNTL1
#define BUS_CNTL1__PMI_IO_DISABLE_MASK                     0x00000001L
#define BUS_CNTL1__PMI_IO_DISABLE                          0x00000001L
#define BUS_CNTL1__PMI_MEM_DISABLE_MASK                    0x00000002L
#define BUS_CNTL1__PMI_MEM_DISABLE                         0x00000002L
#define BUS_CNTL1__PMI_BM_DISABLE_MASK                     0x00000004L
#define BUS_CNTL1__PMI_BM_DISABLE                          0x00000004L
#define BUS_CNTL1__PMI_INT_DISABLE_MASK                    0x00000008L
#define BUS_CNTL1__PMI_INT_DISABLE                         0x00000008L
#define BUS_CNTL1__BUS2_WBF_DURING_REG_WRT_EN_MASK         0x00000010L
#define BUS_CNTL1__BUS2_WBF_DURING_REG_WRT_EN              0x00000010L
#define BUS_CNTL1__BUS2_IMMEDIATE_PMI_DISABLE_MASK         0x00000020L
#define BUS_CNTL1__BUS2_IMMEDIATE_PMI_DISABLE              0x00000020L
#define BUS_CNTL1__BUS2_VGA_REG_COHERENCY_DIS_MASK         0x00000100L
#define BUS_CNTL1__BUS2_VGA_REG_COHERENCY_DIS              0x00000100L
#define BUS_CNTL1__BUS2_VGA_MEM_COHERENCY_DIS_MASK         0x00000200L
#define BUS_CNTL1__BUS2_VGA_MEM_COHERENCY_DIS              0x00000200L
#define BUS_CNTL1__BUS2_HDP_REG_COHERENCY_DIS_MASK         0x00000400L
#define BUS_CNTL1__BUS2_HDP_REG_COHERENCY_DIS              0x00000400L
#define BUS_CNTL1__BUS2_GUI_INITIATOR_COHERENCY_DIS_MASK   0x00000800L
#define BUS_CNTL1__BUS2_GUI_INITIATOR_COHERENCY_DIS        0x00000800L
#define BUS_CNTL1__BUS2_VGA_FW_COHERENCY_DIS_MASK          0x00001000L
#define BUS_CNTL1__BUS2_VGA_FW_COHERENCY_DIS               0x00001000L
#define BUS_CNTL1__BUS2_ACCEL_FW_COHERENCY_DIS_MASK        0x00002000L
#define BUS_CNTL1__BUS2_ACCEL_FW_COHERENCY_DIS             0x00002000L
#define BUS_CNTL1__BUS2_RD_PANIC_VAL_MASK                  0x000f0000L
#define BUS_CNTL1__BUS2_WRT_PANIC_VAL_MASK                 0x00f00000L
#define BUS_CNTL1__MOBILE_PLATFORM_SEL_MASK                0x0c000000L
#define BUS_CNTL1__SEND_SBA_LATENCY_MASK                   0x70000000L
#define BUS_CNTL1__AGPCLK_VALID_MASK                       0x80000000L
#define BUS_CNTL1__AGPCLK_VALID                            0x80000000L

// CONFIG_CNTL
#define CONFIG_CNTL__APER_REG_ENDIAN_MASK                  0x00000030L
#define CONFIG_CNTL__CFG_VGA_RAM_EN_MASK                   0x00000100L
#define CONFIG_CNTL__CFG_VGA_RAM_EN                        0x00000100L
#define CONFIG_CNTL__CFG_VGA_IO_DIS_MASK                   0x00000200L
#define CONFIG_CNTL__CFG_VGA_IO_DIS                        0x00000200L
#define CONFIG_CNTL__CFG_ATI_REV_ID_MASK                   0x000f0000L

// CONFIG_MEMSIZE
#define CONFIG_MEMSIZE__CONFIG_MEMSIZE_R2_MASK             0x1ff00000L

// CONFIG_APER_0_BASE
#define CONFIG_APER_0_BASE__APER_0_BASE_MASK               0xfe000000L

// CONFIG_APER_1_BASE
#define CONFIG_APER_1_BASE__APER_1_BASE_MASK               0xff000000L

// CONFIG_APER_SIZE
#define CONFIG_APER_SIZE__APER_SIZE_MASK                   0x0f000000L

// CONFIG_REG_1_BASE
#define CONFIG_REG_1_BASE__REG_APER_1_SELECT_MASK          0x00008000L
#define CONFIG_REG_1_BASE__REG_APER_1_SELECT               0x00008000L
#define CONFIG_REG_1_BASE__REG_1_BASE_MASK                 0xffff0000L

// CONFIG_REG_APER_SIZE
#define CONFIG_REG_APER_SIZE__REG_APER_SIZE_MASK           0x0000ffffL

// FW_CNTL
#define FW_CNTL__WBF_WM_MAX_MASK                           0x0000000fL
#define FW_CNTL__WBF_WM_MIN_MASK                           0x000000f0L
#define FW_CNTL__DISCONNECT_W_DATA_STOPTRDY_MIN_MASK       0x00000f00L
#define FW_CNTL__DISCONNECT_WO_DATA_STOPTRDY_MIN_MASK      0x0000f000L
#define FW_CNTL__HOLD_FW_FIFO_MASK                         0x00010000L
#define FW_CNTL__HOLD_FW_FIFO                              0x00010000L
#define FW_CNTL__FORCE_FW_WBF_MASK                         0x00020000L
#define FW_CNTL__FORCE_FW_WBF                              0x00020000L
#define FW_CNTL__DIS_FW_WBF_MASK                           0x00040000L
#define FW_CNTL__DIS_FW_WBF                                0x00040000L
#define FW_CNTL__DISCONNECT_MODE_MASK                      0x00180000L
#define FW_CNTL__DIS_WBF_WAIT_FOR_FRAME_MASK               0x00200000L
#define FW_CNTL__DIS_WBF_WAIT_FOR_FRAME                    0x00200000L
#define FW_CNTL__EN_TRDY_WAIT_FOR_FIFOAVL_MASK             0x00400000L
#define FW_CNTL__EN_TRDY_WAIT_FOR_FIFOAVL                  0x00400000L
#define FW_CNTL__TRDY_WS_COUNT_MASK                        0x07800000L
#define FW_CNTL__DIS_FW_ROTATION_MASK                      0x08000000L
#define FW_CNTL__DIS_FW_ROTATION                           0x08000000L
#define FW_CNTL__FORCE_TRDY_1WS_MASK                       0x10000000L
#define FW_CNTL__FORCE_TRDY_1WS                            0x10000000L
#define FW_CNTL__IGNORE_STRAP_FW_DIS_MASK                  0x20000000L
#define FW_CNTL__IGNORE_STRAP_FW_DIS                       0x20000000L
#define FW_CNTL__FW_MISC_MASK                              0xc0000000L

// FW_STATUS
#define FW_STATUS__FW_IDLE_MASK                            0x00000001L
#define FW_STATUS__FW_IDLE                                 0x00000001L
#define FW_STATUS__STAT_FW_CLEAN_MASK                      0x00000002L
#define FW_STATUS__STAT_FW_CLEAN                           0x00000002L
#define FW_STATUS__FW_WAVL_MASK                            0xf8000000L

// AGP_CNTL
#define AGP_CNTL__MAX_IDLE_CLK_MASK                        0x000000ffL
#define AGP_CNTL__HOLD_RD_FIFO_MASK                        0x00000100L
#define AGP_CNTL__HOLD_RD_FIFO                             0x00000100L
#define AGP_CNTL__HOLD_RQ_FIFO_MASK                        0x00000200L
#define AGP_CNTL__HOLD_RQ_FIFO                             0x00000200L
#define AGP_CNTL__EN_2X_STBB_MASK                          0x00000400L
#define AGP_CNTL__EN_2X_STBB                               0x00000400L
#define AGP_CNTL__FORCE_FULL_SBA_MASK                      0x00000800L
#define AGP_CNTL__FORCE_FULL_SBA                           0x00000800L
#define AGP_CNTL__SBA_DIS_MASK                             0x00001000L
#define AGP_CNTL__SBA_DIS                                  0x00001000L
#define AGP_CNTL__AGP_REV_ID_MASK                          0x00002000L
#define AGP_CNTL__AGP_REV_ID                               0x00002000L
#define AGP_CNTL__REG_CRIPPLE_AGP4X_MASK                   0x00004000L
#define AGP_CNTL__REG_CRIPPLE_AGP4X                        0x00004000L
#define AGP_CNTL__REG_CRIPPLE_AGP2X4X_MASK                 0x00008000L
#define AGP_CNTL__REG_CRIPPLE_AGP2X4X                      0x00008000L
#define AGP_CNTL__FORCE_INT_VREF_MASK                      0x00010000L
#define AGP_CNTL__FORCE_INT_VREF                           0x00010000L
#define AGP_CNTL__PENDING_SLOTS_VAL_MASK                   0x00060000L
#define AGP_CNTL__PENDING_SLOTS_SEL_MASK                   0x00080000L
#define AGP_CNTL__PENDING_SLOTS_SEL                        0x00080000L
#define AGP_CNTL__EN_EXTENDED_AD_STB_2X_MASK               0x00100000L
#define AGP_CNTL__EN_EXTENDED_AD_STB_2X                    0x00100000L
#define AGP_CNTL__DIS_QUEUED_GNT_FIX_MASK                  0x00200000L
#define AGP_CNTL__DIS_QUEUED_GNT_FIX                       0x00200000L
#define AGP_CNTL__EN_RDATA2X4X_MULTIRESET_MASK             0x00400000L
#define AGP_CNTL__EN_RDATA2X4X_MULTIRESET                  0x00400000L
#define AGP_CNTL__EN_RBFCALM_MASK                          0x00800000L
#define AGP_CNTL__EN_RBFCALM                               0x00800000L
#define AGP_CNTL__FORCE_EXT_VREF_MASK                      0x01000000L
#define AGP_CNTL__FORCE_EXT_VREF                           0x01000000L
#define AGP_CNTL__DIS_RBF_MASK                             0x02000000L
#define AGP_CNTL__DIS_RBF                                  0x02000000L
#define AGP_CNTL__DELAY_FIRST_SBA_EN_MASK                  0x04000000L
#define AGP_CNTL__DELAY_FIRST_SBA_EN                       0x04000000L
#define AGP_CNTL__DELAY_FIRST_SBA_VAL_MASK                 0x38000000L
#define AGP_CNTL__AGP_MISC_R2_MASK                         0xc0000000L

// BM_STATUS
#define BM_STATUS__BUS_MASTER_STATUS_MASK                  0xffffffffL

// AIC_CTRL
#define AIC_CTRL__TRANSLATE_EN_MASK                        0x00000001L
#define AIC_CTRL__TRANSLATE_EN                             0x00000001L
#define AIC_CTRL__DIS_OUT_OF_PCI_GART_ACCESS_MASK          0x00000002L
#define AIC_CTRL__DIS_OUT_OF_PCI_GART_ACCESS               0x00000002L
#define AIC_CTRL__HW_1_DEBUG_MASK                          0x00000004L
#define AIC_CTRL__HW_1_DEBUG                               0x00000004L
#define AIC_CTRL__HW_2_DEBUG_MASK                          0x00000008L
#define AIC_CTRL__HW_2_DEBUG                               0x00000008L
#define AIC_CTRL__HW_3_DEBUG_MASK                          0x00000010L
#define AIC_CTRL__HW_3_DEBUG                               0x00000010L
#define AIC_CTRL__HW_4_DEBUG_MASK                          0x00000020L
#define AIC_CTRL__HW_4_DEBUG                               0x00000020L
#define AIC_CTRL__HW_5_DEBUG_MASK                          0x00000040L
#define AIC_CTRL__HW_5_DEBUG                               0x00000040L
#define AIC_CTRL__HW_6_DEBUG_MASK                          0x00000080L
#define AIC_CTRL__HW_6_DEBUG                               0x00000080L
#define AIC_CTRL__HW_7_DEBUG_MASK                          0x00000100L
#define AIC_CTRL__HW_7_DEBUG                               0x00000100L
#define AIC_CTRL__HW_8_DEBUG_MASK                          0x00000200L
#define AIC_CTRL__HW_8_DEBUG                               0x00000200L
#define AIC_CTRL__HW_9_DEBUG_MASK                          0x00000400L
#define AIC_CTRL__HW_9_DEBUG                               0x00000400L
#define AIC_CTRL__HW_A_DEBUG_MASK                          0x00000800L
#define AIC_CTRL__HW_A_DEBUG                               0x00000800L
#define AIC_CTRL__HW_B_DEBUG_MASK                          0x00001000L
#define AIC_CTRL__HW_B_DEBUG                               0x00001000L
#define AIC_CTRL__HW_C_DEBUG_MASK                          0x00002000L
#define AIC_CTRL__HW_C_DEBUG                               0x00002000L
#define AIC_CTRL__HW_D_DEBUG_MASK                          0x00004000L
#define AIC_CTRL__HW_D_DEBUG                               0x00004000L
#define AIC_CTRL__HW_E_DEBUG_MASK                          0x00008000L
#define AIC_CTRL__HW_E_DEBUG                               0x00008000L
#define AIC_CTRL__HW_F_DEBUG_MASK                          0x00010000L
#define AIC_CTRL__HW_F_DEBUG                               0x00010000L
#define AIC_CTRL__HW_10_DEBUG_MASK                         0x00020000L
#define AIC_CTRL__HW_10_DEBUG                              0x00020000L
#define AIC_CTRL__HW_11_DEBUG_MASK                         0x00040000L
#define AIC_CTRL__HW_11_DEBUG                              0x00040000L
#define AIC_CTRL__HW_12_DEBUG_MASK                         0x00080000L
#define AIC_CTRL__HW_12_DEBUG                              0x00080000L
#define AIC_CTRL__HW_13_DEBUG_MASK                         0x00100000L
#define AIC_CTRL__HW_13_DEBUG                              0x00100000L
#define AIC_CTRL__HW_14_DEBUG_MASK                         0x00200000L
#define AIC_CTRL__HW_14_DEBUG                              0x00200000L
#define AIC_CTRL__HW_15_DEBUG_MASK                         0x00400000L
#define AIC_CTRL__HW_15_DEBUG                              0x00400000L
#define AIC_CTRL__HW_16_DEBUG_MASK                         0x00800000L
#define AIC_CTRL__HW_16_DEBUG                              0x00800000L
#define AIC_CTRL__HW_17_DEBUG_MASK                         0x01000000L
#define AIC_CTRL__HW_17_DEBUG                              0x01000000L
#define AIC_CTRL__HW_18_DEBUG_MASK                         0x02000000L
#define AIC_CTRL__HW_18_DEBUG                              0x02000000L
#define AIC_CTRL__HW_19_DEBUG_MASK                         0x04000000L
#define AIC_CTRL__HW_19_DEBUG                              0x04000000L
#define AIC_CTRL__HW_1A_DEBUG_MASK                         0x08000000L
#define AIC_CTRL__HW_1A_DEBUG                              0x08000000L
#define AIC_CTRL__HW_1B_DEBUG_MASK                         0x10000000L
#define AIC_CTRL__HW_1B_DEBUG                              0x10000000L
#define AIC_CTRL__HW_1C_DEBUG_MASK                         0x20000000L
#define AIC_CTRL__HW_1C_DEBUG                              0x20000000L
#define AIC_CTRL__HW_1D_DEBUG_MASK                         0x40000000L
#define AIC_CTRL__HW_1D_DEBUG                              0x40000000L
#define AIC_CTRL__HW_1E_DEBUG_MASK                         0x80000000L
#define AIC_CTRL__HW_1E_DEBUG                              0x80000000L

// AIC_STAT
#define AIC_STAT__AIC_TLB_VLD_MASK                         0x00000001L
#define AIC_STAT__AIC_TLB_VLD                              0x00000001L
#define AIC_STAT__AIC_STAT1_MASK                           0x00000002L
#define AIC_STAT__AIC_STAT1                                0x00000002L
#define AIC_STAT__AIC_STAT0_MASK                           0x00000004L
#define AIC_STAT__AIC_STAT0                                0x00000004L

// AIC_PT_BASE
#define AIC_PT_BASE__AIC_PT_BASE_MASK                      0xfffff000L

// AIC_LO_ADDR
#define AIC_LO_ADDR__AIC_LO_ADDR_MASK                      0xfffff000L

// AIC_HI_ADDR
#define AIC_HI_ADDR__AIC_HI_ADDR_MASK                      0xfffff000L

// AIC_TLB_ADDR
#define AIC_TLB_ADDR__AIC_TLB_ADDR_MASK                    0xfffff000L

// AIC_TLB_DATA
#define AIC_TLB_DATA__AIC_TLB_DATA_MASK                    0xfffff000L

// VENDOR_ID
#define VENDOR_ID__VENDOR_ID_MASK                          0x0000ffffL

// DEVICE_ID
#define DEVICE_ID__DEVICE_ID_MASK                          0x0000ffffL

// COMMAND
#define COMMAND__IO_ACCESS_EN_MASK                         0x00000001L
#define COMMAND__IO_ACCESS_EN                              0x00000001L
#define COMMAND__MEM_ACCESS_EN_MASK                        0x00000002L
#define COMMAND__MEM_ACCESS_EN                             0x00000002L
#define COMMAND__BUS_MASTER_EN_MASK                        0x00000004L
#define COMMAND__BUS_MASTER_EN                             0x00000004L
#define COMMAND__SPECIAL_CYCLE_EN_MASK                     0x00000008L
#define COMMAND__SPECIAL_CYCLE_EN                          0x00000008L
#define COMMAND__MEM_WRITE_INVALIDATE_EN_MASK              0x00000010L
#define COMMAND__MEM_WRITE_INVALIDATE_EN                   0x00000010L
#define COMMAND__PAL_SNOOP_EN_MASK                         0x00000020L
#define COMMAND__PAL_SNOOP_EN                              0x00000020L
#define COMMAND__PARITY_ERROR_EN_MASK                      0x00000040L
#define COMMAND__PARITY_ERROR_EN                           0x00000040L
#define COMMAND__SERR_EN_MASK                              0x00000100L
#define COMMAND__SERR_EN                                   0x00000100L
#define COMMAND__FAST_B2B_EN_MASK                          0x00000200L
#define COMMAND__FAST_B2B_EN                               0x00000200L
#define COMMAND__INT_DISABLE_MASK                          0x00000400L
#define COMMAND__INT_DISABLE                               0x00000400L

// STATUS
#define STATUS__INT_STATUS_MASK                            0x00000008L
#define STATUS__INT_STATUS                                 0x00000008L
#define STATUS__CAP_LIST_MASK                              0x00000010L
#define STATUS__CAP_LIST                                   0x00000010L
#define STATUS__PCI_66_EN_MASK                             0x00000020L
#define STATUS__PCI_66_EN                                  0x00000020L
#define STATUS__UDF_EN_MASK                                0x00000040L
#define STATUS__UDF_EN                                     0x00000040L
#define STATUS__FAST_BACK_CAPABLE_MASK                     0x00000080L
#define STATUS__FAST_BACK_CAPABLE                          0x00000080L
#define STATUS__DEVSEL_TIMING_MASK                         0x00000600L
#define STATUS__SIGNAL_TARGET_ABORT_MASK                   0x00000800L
#define STATUS__SIGNAL_TARGET_ABORT                        0x00000800L
#define STATUS__RECEIVED_TARGET_ABORT_MASK                 0x00001000L
#define STATUS__RECEIVED_TARGET_ABORT                      0x00001000L
#define STATUS__RECEIVED_MASTER_ABORT_MASK                 0x00002000L
#define STATUS__RECEIVED_MASTER_ABORT                      0x00002000L
#define STATUS__SIGNALED_SYSTEM_ERROR_MASK                 0x00004000L
#define STATUS__SIGNALED_SYSTEM_ERROR                      0x00004000L
#define STATUS__PARITY_ERROR_DETECTED_MASK                 0x00008000L
#define STATUS__PARITY_ERROR_DETECTED                      0x00008000L

// REVISION_ID
#define REVISION_ID__MINOR_REV_ID_MASK                     0x0000000fL
#define REVISION_ID__MAJOR_REV_ID_MASK                     0x000000f0L

// REGPROG_INF
#define REGPROG_INF__REG_LEVEL_PROG_INF_MASK               0x000000ffL

// SUB_CLASS
#define SUB_CLASS__SUB_CLASS_INF_MASK                      0x00000080L
#define SUB_CLASS__SUB_CLASS_INF                           0x00000080L

// BASE_CODE
#define BASE_CODE__BASE_CLASS_CODE_MASK                    0x000000ffL

// CACHE_LINE
#define CACHE_LINE__CACHE_LINE_SIZE_MASK                   0x000000ffL

// LATENCY
#define LATENCY__LATENCY_TIMER_MASK                        0x000000ffL

// HEADER
#define HEADER__HEADER_TYPE_MASK                           0x0000007fL
#define HEADER__DEVICE_TYPE_MASK                           0x00000080L
#define HEADER__DEVICE_TYPE                                0x00000080L

// BIST
#define BIST__BIST_COMP_MASK                               0x0000000fL
#define BIST__BIST_STRT_MASK                               0x00000040L
#define BIST__BIST_STRT                                    0x00000040L
#define BIST__BIST_CAP_MASK                                0x00000080L
#define BIST__BIST_CAP                                     0x00000080L

// MEM_BASE
#define MEM_BASE__PREFETCH_EN_MASK                         0x00000008L
#define MEM_BASE__PREFETCH_EN                              0x00000008L
#define MEM_BASE__MEM_BASE_MASK                            0xfe000000L

// IO_BASE
#define IO_BASE__BLOCK_IO_BIT_MASK                         0x000000ffL
#define IO_BASE__IO_BASE_MASK                              0xffffff00L

// REG_BASE
#define REG_BASE__REG_BASE_MASK                            0xffff0000L

// ADAPTER_ID
#define ADAPTER_ID__SUBSYSTEM_VENDOR_ID_MASK               0x0000ffffL
#define ADAPTER_ID__SUBSYSTEM_ID_MASK                      0xffff0000L

// BIOS_ROM
#define BIOS_ROM__BIOS_ROM_EN_MASK                         0x00000001L
#define BIOS_ROM__BIOS_ROM_EN                              0x00000001L
#define BIOS_ROM__BIOS_BASE_ADDR_MASK                      0xfffe0000L

// CAPABILITIES_PTR
#define CAPABILITIES_PTR__CAP_PTR_MASK                     0x000000ffL

// INTERRUPT_LINE
#define INTERRUPT_LINE__INTERRUPT_LINE_MASK                0x000000ffL

// INTERRUPT_PIN
#define INTERRUPT_PIN__INTERRUPT_PIN_MASK                  0x00000001L
#define INTERRUPT_PIN__INTERRUPT_PIN                       0x00000001L

// MIN_GRANT
#define MIN_GRANT__MIN_GNT_MASK                            0x000000ffL

// MAX_LATENCY
#define MAX_LATENCY__MAX_LAT_MASK                          0x000000ffL

// ADAPTER_ID_W
#define ADAPTER_ID_W__SUBSYSTEM_VENDOR_ID_MASK             0x0000ffffL
#define ADAPTER_ID_W__SUBSYSTEM_ID_MASK                    0xffff0000L

// PMI_CAP_ID
#define PMI_CAP_ID__PMI_CAP_ID_MASK                        0x000000ffL

// PMI_NXT_CAP_PTR
#define PMI_NXT_CAP_PTR__PMI_NXT_CAP_PTR_MASK              0x000000ffL

// PMI_PMC_REG
#define PMI_PMC_REG__PMI_VERSION_MASK                      0x00000007L
#define PMI_PMC_REG__PMI_PME_CLOCK_MASK                    0x00000008L
#define PMI_PMC_REG__PMI_PME_CLOCK                         0x00000008L
#define PMI_PMC_REG__PMI_DEV_SPECIFIC_INIT_MASK            0x00000020L
#define PMI_PMC_REG__PMI_DEV_SPECIFIC_INIT                 0x00000020L
#define PMI_PMC_REG__PMI_D1_SUPPORT_MASK                   0x00000200L
#define PMI_PMC_REG__PMI_D1_SUPPORT                        0x00000200L
#define PMI_PMC_REG__PMI_D2_SUPPORT_MASK                   0x00000400L
#define PMI_PMC_REG__PMI_D2_SUPPORT                        0x00000400L
#define PMI_PMC_REG__PMI_PME_SUPPORT_MASK                  0x0000f800L

// PM_STATUS
#define PM_STATUS__PMI_POWER_STATE_MASK                    0x00000003L
#define PM_STATUS__PMI_PME_EN_MASK                         0x00000100L
#define PM_STATUS__PMI_PME_EN                              0x00000100L
#define PM_STATUS__PMI_DATA_SELECT_MASK                    0x00001e00L
#define PM_STATUS__PMI_DATA_SCALE_MASK                     0x00006000L
#define PM_STATUS__PMI_PME_STATUS_MASK                     0x00008000L
#define PM_STATUS__PMI_PME_STATUS                          0x00008000L

// PMI_DATA
#define PMI_DATA__PMI_DATA_MASK                            0x000000ffL

// AGP_CAP_ID
#define AGP_CAP_ID__CAP_ID_MASK                            0x000000ffL
#define AGP_CAP_ID__NEXT_PTR_MASK                          0x0000ff00L
#define AGP_CAP_ID__AGP_MINOR_MASK                         0x000f0000L
#define AGP_CAP_ID__AGP_MAJOR_MASK                         0x00f00000L

// AGP_STATUS
#define AGP_STATUS__RATE1X_4X_MASK                         0x00000001L
#define AGP_STATUS__RATE1X_4X                              0x00000001L
#define AGP_STATUS__RATE2X_8X_MASK                         0x00000002L
#define AGP_STATUS__RATE2X_8X                              0x00000002L
#define AGP_STATUS__RATE4X_MASK                            0x00000004L
#define AGP_STATUS__RATE4X                                 0x00000004L
#define AGP_STATUS__MODE_AGP30_MASK                        0x00000008L
#define AGP_STATUS__MODE_AGP30                             0x00000008L
#define AGP_STATUS__FW_MASK                                0x00000010L
#define AGP_STATUS__FW                                     0x00000010L
#define AGP_STATUS__MODE_4G_MASK                           0x00000020L
#define AGP_STATUS__MODE_4G                                0x00000020L
#define AGP_STATUS__SBA_MASK                               0x00000200L
#define AGP_STATUS__SBA                                    0x00000200L
#define AGP_STATUS__CAL_CYCLE_MASK                         0x00001c00L
#define AGP_STATUS__ISOCH_SUPPORT_MASK                     0x00020000L
#define AGP_STATUS__ISOCH_SUPPORT                          0x00020000L
#define AGP_STATUS__RQ_MASK                                0xff000000L

// AGP_COMMAND
#define AGP_COMMAND__DATA_RATE_MASK                        0x00000007L
#define AGP_COMMAND__FW_EN_MASK                            0x00000010L
#define AGP_COMMAND__FW_EN                                 0x00000010L
#define AGP_COMMAND__MODE_4G_EN_MASK                       0x00000020L
#define AGP_COMMAND__MODE_4G_EN                            0x00000020L
#define AGP_COMMAND__AGP_EN_MASK                           0x00000100L
#define AGP_COMMAND__AGP_EN                                0x00000100L
#define AGP_COMMAND__SBA_EN_MASK                           0x00000200L
#define AGP_COMMAND__SBA_EN                                0x00000200L
#define AGP_COMMAND__PARQSZ_MASK                           0x0000e000L
#define AGP_COMMAND__RQ_DEPTH_MASK                         0xff000000L

// F1_VENDOR_ID
#define F1_VENDOR_ID__F1_VENDOR_ID_MASK                    0x0000ffffL

// F1_DEVICE_ID
#define F1_DEVICE_ID__F1_DEVICE_ID_MASK                    0x0000ffffL

// F1_COMMAND
#define F1_COMMAND__F1_IO_ACCESS_EN_MASK                   0x00000001L
#define F1_COMMAND__F1_IO_ACCESS_EN                        0x00000001L
#define F1_COMMAND__F1_MEM_ACCESS_EN_MASK                  0x00000002L
#define F1_COMMAND__F1_MEM_ACCESS_EN                       0x00000002L
#define F1_COMMAND__F1_BUS_MASTER_EN_MASK                  0x00000004L
#define F1_COMMAND__F1_BUS_MASTER_EN                       0x00000004L
#define F1_COMMAND__F1_FAST_B2B_EN_MASK                    0x00000200L
#define F1_COMMAND__F1_FAST_B2B_EN                         0x00000200L

// F1_STATUS
#define F1_STATUS__F1_CAP_LIST_MASK                        0x00000010L
#define F1_STATUS__F1_CAP_LIST                             0x00000010L
#define F1_STATUS__F1_PCI_66_EN_MASK                       0x00000020L
#define F1_STATUS__F1_PCI_66_EN                            0x00000020L
#define F1_STATUS__F1_UDF_EN_MASK                          0x00000040L
#define F1_STATUS__F1_UDF_EN                               0x00000040L
#define F1_STATUS__F1_FAST_BACK_CAPABLE_MASK               0x00000080L
#define F1_STATUS__F1_FAST_BACK_CAPABLE                    0x00000080L
#define F1_STATUS__F1_DEVSEL_TIMING_MASK                   0x00000600L
#define F1_STATUS__F1_SIGNAL_TARGET_ABORT_MASK             0x00000800L
#define F1_STATUS__F1_SIGNAL_TARGET_ABORT                  0x00000800L
#define F1_STATUS__F1_RECEIVED_TARGET_ABORT_MASK           0x00001000L
#define F1_STATUS__F1_RECEIVED_TARGET_ABORT                0x00001000L
#define F1_STATUS__F1_RECEIVED_MASTER_ABORT_MASK           0x00002000L
#define F1_STATUS__F1_RECEIVED_MASTER_ABORT                0x00002000L
#define F1_STATUS__F1_PARITY_ERROR_DETECTED_MASK           0x00008000L
#define F1_STATUS__F1_PARITY_ERROR_DETECTED                0x00008000L

// F1_REVISION_ID
#define F1_REVISION_ID__F1_MINOR_REV_ID_MASK               0x0000000fL
#define F1_REVISION_ID__F1_MAJOR_REV_ID_MASK               0x000000f0L

// F1_REGPROG_INF
#define F1_REGPROG_INF__F1_REG_LEVEL_PROG_INF_MASK         0x000000ffL

// F1_SUB_CLASS
#define F1_SUB_CLASS__F1_SUB_CLASS_INF_MASK                0x00000080L
#define F1_SUB_CLASS__F1_SUB_CLASS_INF                     0x00000080L

// F1_BASE_CODE
#define F1_BASE_CODE__F1_BASE_CLASS_CODE_MASK              0x000000ffL

// F1_CACHE_LINE
#define F1_CACHE_LINE__F1_CACHE_LINE_SIZE_MASK             0x000000ffL

// F1_LATENCY
#define F1_LATENCY__F1_LATENCY_TIMER_MASK                  0x000000ffL

// F1_HEADER
#define F1_HEADER__F1_HEADER_TYPE_MASK                     0x0000007fL
#define F1_HEADER__F1_DEVICE_TYPE_MASK                     0x00000080L
#define F1_HEADER__F1_DEVICE_TYPE                          0x00000080L

// F1_BIST
#define F1_BIST__F1_BIST_COMP_MASK                         0x0000000fL
#define F1_BIST__F1_BIST_STRT_MASK                         0x00000040L
#define F1_BIST__F1_BIST_STRT                              0x00000040L
#define F1_BIST__F1_BIST_CAP_MASK                          0x00000080L
#define F1_BIST__F1_BIST_CAP                               0x00000080L

// F1_MEM_BASE
#define F1_MEM_BASE__F1_PREFETCH_EN_MASK                   0x00000008L
#define F1_MEM_BASE__F1_PREFETCH_EN                        0x00000008L
#define F1_MEM_BASE__F1_MEM_BASE_MASK                      0xfe000000L

// F1_REG_BASE
#define F1_REG_BASE__F1_REG_BASE_MASK                      0xffff0000L

// F1_ADAPTER_ID
#define F1_ADAPTER_ID__F1_SUBSYSTEM_VENDOR_ID_MASK         0x0000ffffL
#define F1_ADAPTER_ID__F1_SUBSYSTEM_ID_MASK                0xffff0000L

// F1_CAPABILITIES_PTR
#define F1_CAPABILITIES_PTR__F1_CAP_PTR_MASK               0x000000ffL

// F1_INTERRUPT_LINE
#define F1_INTERRUPT_LINE__F1_INTERRUPT_LINE_MASK          0x000000ffL

// F1_INTERRUPT_PIN
#define F1_INTERRUPT_PIN__F1_INTERRUPT_PIN_MASK            0x00000001L
#define F1_INTERRUPT_PIN__F1_INTERRUPT_PIN                 0x00000001L

// F1_MIN_GRANT
#define F1_MIN_GRANT__F1_MIN_GNT_MASK                      0x000000ffL

// F1_MAX_LATENCY
#define F1_MAX_LATENCY__F1_MAX_LAT_MASK                    0x000000ffL

// F1_PMI_CAP_ID
#define F1_PMI_CAP_ID__F1_PMI_CAP_ID_MASK                  0x000000ffL

// F1_PMI_NXT_CAP_PTR
#define F1_PMI_NXT_CAP_PTR__F1_PMI_NXT_CAP_PTR_MASK        0x000000ffL

// F1_PMI_PMC_REG
#define F1_PMI_PMC_REG__F1_PMI_VERSION_MASK                0x00000007L
#define F1_PMI_PMC_REG__F1_PMI_PME_CLOCK_MASK              0x00000008L
#define F1_PMI_PMC_REG__F1_PMI_PME_CLOCK                   0x00000008L
#define F1_PMI_PMC_REG__F1_PMI_DEV_SPECIFIC_INIT_MASK      0x00000020L
#define F1_PMI_PMC_REG__F1_PMI_DEV_SPECIFIC_INIT           0x00000020L
#define F1_PMI_PMC_REG__F1_PMI_D1_SUPPORT_MASK             0x00000200L
#define F1_PMI_PMC_REG__F1_PMI_D1_SUPPORT                  0x00000200L
#define F1_PMI_PMC_REG__F1_PMI_D2_SUPPORT_MASK             0x00000400L
#define F1_PMI_PMC_REG__F1_PMI_D2_SUPPORT                  0x00000400L
#define F1_PMI_PMC_REG__F1_PMI_PME_SUPPORT_MASK            0x0000f800L

// F1_PM_STATUS
#define F1_PM_STATUS__F1_PMI_POWER_STATE_MASK              0x00000003L
#define F1_PM_STATUS__F1_PMI_PME_EN_MASK                   0x00000100L
#define F1_PM_STATUS__F1_PMI_PME_EN                        0x00000100L
#define F1_PM_STATUS__F1_PMI_DATA_SELECT_MASK              0x00001e00L
#define F1_PM_STATUS__F1_PMI_DATA_SCALE_MASK               0x00006000L
#define F1_PM_STATUS__F1_PMI_PME_STATUS_MASK               0x00008000L
#define F1_PM_STATUS__F1_PMI_PME_STATUS                    0x00008000L

// F1_PMI_DATA
#define F1_PMI_DATA__F1_PMI_DATA_MASK                      0x000000ffL

// F1_AGP_CAP_ID
#define F1_AGP_CAP_ID__F1_CAP_ID_MASK                      0x000000ffL
#define F1_AGP_CAP_ID__F1_NEXT_PTR_MASK                    0x0000ff00L
#define F1_AGP_CAP_ID__F1_AGP_MINOR_MASK                   0x000f0000L
#define F1_AGP_CAP_ID__F1_AGP_MAJOR_MASK                   0x00f00000L

// F1_AGP_STATUS
#define F1_AGP_STATUS__F1_RATE1X_4X_MASK                   0x00000001L
#define F1_AGP_STATUS__F1_RATE1X_4X                        0x00000001L
#define F1_AGP_STATUS__F1_RATE2X_8X_MASK                   0x00000002L
#define F1_AGP_STATUS__F1_RATE2X_8X                        0x00000002L
#define F1_AGP_STATUS__F1_RATE4X_MASK                      0x00000004L
#define F1_AGP_STATUS__F1_RATE4X                           0x00000004L
#define F1_AGP_STATUS__F1_MODE_AGP30_MASK                  0x00000008L
#define F1_AGP_STATUS__F1_MODE_AGP30                       0x00000008L
#define F1_AGP_STATUS__F1_FW_MASK                          0x00000010L
#define F1_AGP_STATUS__F1_FW                               0x00000010L
#define F1_AGP_STATUS__F1_MODE_4G_MASK                     0x00000020L
#define F1_AGP_STATUS__F1_MODE_4G                          0x00000020L
#define F1_AGP_STATUS__F1_SBA_MASK                         0x00000200L
#define F1_AGP_STATUS__F1_SBA                              0x00000200L
#define F1_AGP_STATUS__F1_CAL_CYCLE_MASK                   0x00001c00L
#define F1_AGP_STATUS__F1_ISOCH_SUPPORT_MASK               0x00020000L
#define F1_AGP_STATUS__F1_ISOCH_SUPPORT                    0x00020000L
#define F1_AGP_STATUS__F1_RQ_MASK                          0xff000000L

// F1_AGP_COMMAND
#define F1_AGP_COMMAND__F1_DATA_RATE_MASK                  0x00000007L
#define F1_AGP_COMMAND__F1_FW_EN_MASK                      0x00000010L
#define F1_AGP_COMMAND__F1_FW_EN                           0x00000010L
#define F1_AGP_COMMAND__F1_MODE_4G_EN_MASK                 0x00000020L
#define F1_AGP_COMMAND__F1_MODE_4G_EN                      0x00000020L
#define F1_AGP_COMMAND__F1_AGP_EN_MASK                     0x00000100L
#define F1_AGP_COMMAND__F1_AGP_EN                          0x00000100L
#define F1_AGP_COMMAND__F1_SBA_EN_MASK                     0x00000200L
#define F1_AGP_COMMAND__F1_SBA_EN                          0x00000200L
#define F1_AGP_COMMAND__F1_PARQSZ_MASK                     0x0000e000L
#define F1_AGP_COMMAND__F1_RQ_DEPTH_MASK                   0xff000000L

// GENMO_WT
#define GENMO_WT__GENMO_MONO_ADDRESS_B_MASK                0x00000001L
#define GENMO_WT__GENMO_MONO_ADDRESS_B                     0x00000001L
#define GENMO_WT__VGA_RAM_EN_MASK                          0x00000002L
#define GENMO_WT__VGA_RAM_EN                               0x00000002L
#define GENMO_WT__VGA_CKSEL_MASK                           0x0000000cL
#define GENMO_WT__ODD_EVEN_MD_PGSEL_MASK                   0x00000020L
#define GENMO_WT__ODD_EVEN_MD_PGSEL                        0x00000020L
#define GENMO_WT__VGA_HSYNC_POL_MASK                       0x00000040L
#define GENMO_WT__VGA_HSYNC_POL                            0x00000040L
#define GENMO_WT__VGA_VSYNC_POL_MASK                       0x00000080L
#define GENMO_WT__VGA_VSYNC_POL                            0x00000080L

// GENMO_RD
#define GENMO_RD__GENMO_MONO_ADDRESS_B_MASK                0x00000001L
#define GENMO_RD__GENMO_MONO_ADDRESS_B                     0x00000001L
#define GENMO_RD__VGA_RAM_EN_MASK                          0x00000002L
#define GENMO_RD__VGA_RAM_EN                               0x00000002L
#define GENMO_RD__VGA_CKSEL_MASK                           0x0000000cL
#define GENMO_RD__ODD_EVEN_MD_PGSEL_MASK                   0x00000020L
#define GENMO_RD__ODD_EVEN_MD_PGSEL                        0x00000020L
#define GENMO_RD__VGA_HSYNC_POL_MASK                       0x00000040L
#define GENMO_RD__VGA_HSYNC_POL                            0x00000040L
#define GENMO_RD__VGA_VSYNC_POL_MASK                       0x00000080L
#define GENMO_RD__VGA_VSYNC_POL                            0x00000080L

// CRTC_GEN_CNTL
#define CRTC_GEN_CNTL__CRTC_DBL_SCAN_EN_MASK               0x00000001L
#define CRTC_GEN_CNTL__CRTC_DBL_SCAN_EN                    0x00000001L
#define CRTC_GEN_CNTL__CRTC_INTERLACE_EN_MASK              0x00000002L
#define CRTC_GEN_CNTL__CRTC_INTERLACE_EN                   0x00000002L
#define CRTC_GEN_CNTL__CRTC_C_SYNC_EN_MASK                 0x00000010L
#define CRTC_GEN_CNTL__CRTC_C_SYNC_EN                      0x00000010L
#define CRTC_GEN_CNTL__CRTC_PIX_WIDTH_MASK                 0x00000f00L
#define CRTC_GEN_CNTL__CRTC_ICON_EN_MASK                   0x00008000L
#define CRTC_GEN_CNTL__CRTC_ICON_EN                        0x00008000L
#define CRTC_GEN_CNTL__CRTC_CUR_EN_MASK                    0x00010000L
#define CRTC_GEN_CNTL__CRTC_CUR_EN                         0x00010000L
#define CRTC_GEN_CNTL__CRTC_VSTAT_MODE_MASK                0x00060000L
#define CRTC_GEN_CNTL__CRTC_CUR_MODE_MASK                  0x00700000L
#define CRTC_GEN_CNTL__CRTC_EXT_DISP_EN_MASK               0x01000000L
#define CRTC_GEN_CNTL__CRTC_EXT_DISP_EN                    0x01000000L
#define CRTC_GEN_CNTL__CRTC_EN_MASK                        0x02000000L
#define CRTC_GEN_CNTL__CRTC_EN                             0x02000000L
#define CRTC_GEN_CNTL__CRTC_DISP_REQ_EN_B_MASK             0x04000000L
#define CRTC_GEN_CNTL__CRTC_DISP_REQ_EN_B                  0x04000000L

// DAC_CNTL
#define DAC_CNTL__DAC_RANGE_CNTL_MASK                      0x00000003L
#define DAC_CNTL__DAC_BLANKING_MASK                        0x00000004L
#define DAC_CNTL__DAC_BLANKING                             0x00000004L
#define DAC_CNTL__DAC_CMP_EN_MASK                          0x00000008L
#define DAC_CNTL__DAC_CMP_EN                               0x00000008L
#define DAC_CNTL__DAC_CMP_OUT_R_MASK                       0x00000010L
#define DAC_CNTL__DAC_CMP_OUT_R                            0x00000010L
#define DAC_CNTL__DAC_CMP_OUT_G_MASK                       0x00000020L
#define DAC_CNTL__DAC_CMP_OUT_G                            0x00000020L
#define DAC_CNTL__DAC_CMP_OUT_B_MASK                       0x00000040L
#define DAC_CNTL__DAC_CMP_OUT_B                            0x00000040L
#define DAC_CNTL__DAC_CMP_OUTPUT_MASK                      0x00000080L
#define DAC_CNTL__DAC_CMP_OUTPUT                           0x00000080L
#define DAC_CNTL__DAC_8BIT_EN_MASK                         0x00000100L
#define DAC_CNTL__DAC_8BIT_EN                              0x00000100L
#define DAC_CNTL__DAC_4BPP_PIX_ORDER_MASK                  0x00000200L
#define DAC_CNTL__DAC_4BPP_PIX_ORDER                       0x00000200L
#define DAC_CNTL__DAC_VGA_ADR_EN_MASK                      0x00002000L
#define DAC_CNTL__DAC_VGA_ADR_EN                           0x00002000L
#define DAC_CNTL__DAC_EXPAND_MODE_MASK                     0x00004000L
#define DAC_CNTL__DAC_EXPAND_MODE                          0x00004000L
#define DAC_CNTL__DAC_PDWN_MASK                            0x00008000L
#define DAC_CNTL__DAC_PDWN                                 0x00008000L
#define DAC_CNTL__CRT_SENSE_MASK                           0x00010000L
#define DAC_CNTL__CRT_SENSE                                0x00010000L
#define DAC_CNTL__CRT_DETECTION_ON_MASK                    0x00020000L
#define DAC_CNTL__CRT_DETECTION_ON                         0x00020000L
#define DAC_CNTL__DAC_CRC_CONT_EN_MASK                     0x00040000L
#define DAC_CNTL__DAC_CRC_CONT_EN                          0x00040000L
#define DAC_CNTL__DAC_CRC_EN_MASK                          0x00080000L
#define DAC_CNTL__DAC_CRC_EN                               0x00080000L
#define DAC_CNTL__DAC_CRC_FIELD_MASK                       0x00100000L
#define DAC_CNTL__DAC_CRC_FIELD                            0x00100000L
#define DAC_CNTL__DAC_LUT_COUNTER_LIMIT_MASK               0x00600000L
#define DAC_CNTL__DAC_LUT_READ_SEL_MASK                    0x00800000L
#define DAC_CNTL__DAC_LUT_READ_SEL                         0x00800000L
#define DAC_CNTL__DAC_MASK_MASK                            0xff000000L

// MEM_CNTL
#define MEM_CNTL__MEM_NUM_CHANNELS_MASK                    0x00000001L
#define MEM_CNTL__MEM_NUM_CHANNELS                         0x00000001L
#define MEM_CNTL__MC_USE_B_CH_ONLY_MASK                    0x00000002L
#define MEM_CNTL__MC_USE_B_CH_ONLY                         0x00000002L
#define MEM_CNTL__DISABLE_AP_MASK                          0x00000004L
#define MEM_CNTL__DISABLE_AP                               0x00000004L
#define MEM_CNTL__HALF_MODE_MASK                           0x00000008L
#define MEM_CNTL__HALF_MODE                                0x00000008L
#define MEM_CNTL__MEM_BANK_MAPPING_A_MASK                  0x000000f0L
#define MEM_CNTL__MEM_ADDR_MAPPING_A_MASK                  0x0000ff00L
#define MEM_CNTL__MEM_BANK_MAPPING_B_MASK                  0x00f00000L
#define MEM_CNTL__MEM_ADDR_MAPPING_B_MASK                  0xff000000L

// EXT_MEM_CNTL
#define EXT_MEM_CNTL__MEM_TRP_MASK                         0x00000003L
#define EXT_MEM_CNTL__MEM_TRCD_MASK                        0x0000000cL
#define EXT_MEM_CNTL__MEM_TRAS_MASK                        0x00000070L
#define EXT_MEM_CNTL__MEM_TRRD_MASK                        0x00000300L
#define EXT_MEM_CNTL__MEM_TR2W_MASK                        0x00000c00L
#define EXT_MEM_CNTL__MEM_TWR_MASK                         0x00003000L
#define EXT_MEM_CNTL__MEM_TW2R_MASK                        0x0000c000L
#define EXT_MEM_CNTL__MEM_TR2R_MASK                        0x00030000L
#define EXT_MEM_CNTL__MEM_TWR_MODE_MASK                    0x00040000L
#define EXT_MEM_CNTL__MEM_TWR_MODE                         0x00040000L
#define EXT_MEM_CNTL__MEM_REFRESH_DIS_MASK                 0x00100000L
#define EXT_MEM_CNTL__MEM_REFRESH_DIS                      0x00100000L
#define EXT_MEM_CNTL__MEM_REFRESH_COUNT_MASK               0x00e00000L
#define EXT_MEM_CNTL__MEM_REFRESH_RATE_MASK                0xff000000L

// MC_AGP_LOCATION
#define MC_AGP_LOCATION__MC_AGP_START_MASK                 0x0000ffffL
#define MC_AGP_LOCATION__MC_AGP_TOP_MASK                   0xffff0000L

// MC_CNTL_A5
#define MC_CNTL_A5__Reserved0_MASK                         0x00000001L
#define MC_CNTL_A5__Reserved0                              0x00000001L
#define MC_CNTL_A5__DISABLE_CPU_MASK                       0x00000002L
#define MC_CNTL_A5__DISABLE_CPU                            0x00000002L
#define MC_CNTL_A5__Reserved1_MASK                         0x00000008L
#define MC_CNTL_A5__Reserved1                              0x00000008L
#define MC_CNTL_A5__DISABLE_AGP_MASK                       0x00000010L
#define MC_CNTL_A5__DISABLE_AGP                            0x00000010L
#define MC_CNTL_A5__DISP_HiPri_MASK                        0x00000020L
#define MC_CNTL_A5__DISP_HiPri                             0x00000020L
#define MC_CNTL_A5__DLL_Reset_MASK                         0x00000040L
#define MC_CNTL_A5__DLL_Reset                              0x00000040L
#define MC_CNTL_A5__DLL_PwrDown_MASK                       0x00000080L
#define MC_CNTL_A5__DLL_PwrDown                            0x00000080L
#define MC_CNTL_A5__DLL_Ready_MASK                         0x00000100L
#define MC_CNTL_A5__DLL_Ready                              0x00000100L
#define MC_CNTL_A5__Reserved2_MASK                         0x00000600L
#define MC_CNTL_A5__DISP_HiPri2_MASK                       0x00000800L
#define MC_CNTL_A5__DISP_HiPri2                            0x00000800L
#define MC_CNTL_A5__Reserved3_MASK                         0x0003f000L
#define MC_CNTL_A5__SELF_RF_DIS_MASK                       0x00040000L
#define MC_CNTL_A5__SELF_RF_DIS                            0x00040000L
#define MC_CNTL_A5__DISABLE_BYPASS_MASK                    0x00080000L
#define MC_CNTL_A5__DISABLE_BYPASS                         0x00080000L
#define MC_CNTL_A5__Reserved4_MASK                         0x00100000L
#define MC_CNTL_A5__Reserved4                              0x00100000L
#define MC_CNTL_A5__SEQ_ARB_MODE_MASK                      0x00200000L
#define MC_CNTL_A5__SEQ_ARB_MODE                           0x00200000L
#define MC_CNTL_A5__MC_CLEAN_GC_MASK                       0x00400000L
#define MC_CNTL_A5__MC_CLEAN_GC                            0x00400000L
#define MC_CNTL_A5__MEM_DYNAMIC_CKE_MASK                   0x00800000L
#define MC_CNTL_A5__MEM_DYNAMIC_CKE                        0x00800000L
#define MC_CNTL_A5__MEM_SDRAM_TRI_EN_MASK                  0x01000000L
#define MC_CNTL_A5__MEM_SDRAM_TRI_EN                       0x01000000L
#define MC_CNTL_A5__MEM_DYN_REC_CTRL_MASK                  0x02000000L
#define MC_CNTL_A5__MEM_DYN_REC_CTRL                       0x02000000L
#define MC_CNTL_A5__Reserved5_MASK                         0x04000000L
#define MC_CNTL_A5__Reserved5                              0x04000000L
#define MC_CNTL_A5__MC_PDN_MODE_MASK                       0x18000000L
#define MC_CNTL_A5__MC_STARTUP_MASK                        0x20000000L
#define MC_CNTL_A5__MC_STARTUP                             0x20000000L
#define MC_CNTL_A5__MC_PWRDOWN_MASK                        0x40000000L
#define MC_CNTL_A5__MC_PWRDOWN                             0x40000000L
#define MC_CNTL_A5__MC_RESTART_MASK                        0x80000000L
#define MC_CNTL_A5__MC_RESTART                             0x80000000L

// MEM_INIT_LATENCY_TIMER
#define MEM_INIT_LATENCY_TIMER__MEM_RB0R_INIT_LAT_MASK     0x0000000fL
#define MEM_INIT_LATENCY_TIMER__MEM_RB1R_INIT_LAT_MASK     0x000000f0L
#define MEM_INIT_LATENCY_TIMER__MEM_PPR_INIT_LAT_MASK      0x00000f00L
#define MEM_INIT_LATENCY_TIMER__MEM_DISPR_INIT_LAT_MASK    0x0000f000L
#define MEM_INIT_LATENCY_TIMER__MEM_RB0W_INIT_LAT_MASK     0x000f0000L
#define MEM_INIT_LATENCY_TIMER__MEM_RB1W_INIT_LAT_MASK     0x00f00000L
#define MEM_INIT_LATENCY_TIMER__MEM_FIXED_INIT_LAT_MASK    0x0f000000L
#define MEM_INIT_LATENCY_TIMER__SAME_PAGE_PRIO_MASK        0x70000000L

// MEM_SDRAM_MODE_REG
#define MEM_SDRAM_MODE_REG__MEM_MODE_REG_A5_MASK           0x0000ffffL
#define MEM_SDRAM_MODE_REG__Reserved0_A5_MASK              0x000f0000L
#define MEM_SDRAM_MODE_REG__MEM_CAS_LATENCY_MASK           0x00700000L
#define MEM_SDRAM_MODE_REG__Reserved1_MASK                 0x0f800000L
#define MEM_SDRAM_MODE_REG__MC_INIT_COMPLETE_MASK          0x10000000L
#define MEM_SDRAM_MODE_REG__MC_INIT_COMPLETE               0x10000000L
#define MEM_SDRAM_MODE_REG__Reserved2_MASK                 0x20000000L
#define MEM_SDRAM_MODE_REG__Reserved2                      0x20000000L
#define MEM_SDRAM_MODE_REG__MEM_CFG_TYPE_MASK              0x40000000L
#define MEM_SDRAM_MODE_REG__MEM_CFG_TYPE                   0x40000000L
#define MEM_SDRAM_MODE_REG__MEM_SDRAM_RESET_MASK           0x80000000L
#define MEM_SDRAM_MODE_REG__MEM_SDRAM_RESET                0x80000000L

// AGP_BASE
#define AGP_BASE__AGP_BASE_ADDR_MASK                       0xffffffffL

// MC_LIMIT
#define MC_LIMIT__R6_RD_IDLE_LIMIT_MASK                    0x0000001fL
#define MC_LIMIT__R6_RD_PH_LIMIT_MASK                      0x000000e0L
#define MC_LIMIT__R6_WR_IDLE_LIMIT_MASK                    0x00001f00L
#define MC_LIMIT__R6_WR_PH_LIMIT_MASK                      0x0000e000L
#define MC_LIMIT__NB_RD_IDLE_LIMIT_MASK                    0x001f0000L
#define MC_LIMIT__NB_RD_PH_LIMIT_MASK                      0x00e00000L
#define MC_LIMIT__NB_WR_IDLE_LIMIT_MASK                    0x1f000000L
#define MC_LIMIT__NB_WR_PH_LIMIT_MASK                      0xe0000000L

// MEM_IO_CNTL_B0_U1
#define MEM_IO_CNTL_B0_U1__MEM_N_CKB_MASK                  0x0000001fL
#define MEM_IO_CNTL_B0_U1__MEM_N_AB_MASK                   0x000003e0L
#define MEM_IO_CNTL_B0_U1__MEM_N_DQMB_MASK                 0x00007c00L
#define MEM_IO_CNTL_B0_U1__MEM_N_DQSB_MASK                 0x000f8000L

// MEM_IO_CNTL_B1_U1
#define MEM_IO_CNTL_B1_U1__MEM_P_CKB_MASK                  0x0000001fL
#define MEM_IO_CNTL_B1_U1__MEM_P_AB_MASK                   0x000003e0L
#define MEM_IO_CNTL_B1_U1__MEM_P_DQMB_MASK                 0x00007c00L
#define MEM_IO_CNTL_B1_U1__MEM_P_DQSB_MASK                 0x000f8000L
#define MEM_IO_CNTL_B1_U1__CLKB_ENABLE_MASK                0x00400000L
#define MEM_IO_CNTL_B1_U1__CLKB_ENABLE                     0x00400000L

// MC_DEBUG_R2
#define MC_DEBUG_R2__IGNORE_RW_PENALTY_RB0R_MASK           0x00000001L
#define MC_DEBUG_R2__IGNORE_RW_PENALTY_RB0R                0x00000001L
#define MC_DEBUG_R2__IGNORE_RW_PENALTY_RB1R_MASK           0x00000002L
#define MC_DEBUG_R2__IGNORE_RW_PENALTY_RB1R                0x00000002L
#define MC_DEBUG_R2__IGNORE_RW_PENALTY_RB0W_MASK           0x00000004L
#define MC_DEBUG_R2__IGNORE_RW_PENALTY_RB0W                0x00000004L
#define MC_DEBUG_R2__IGNORE_RW_PENALTY_RB1W_MASK           0x00000008L
#define MC_DEBUG_R2__IGNORE_RW_PENALTY_RB1W                0x00000008L
#define MC_DEBUG_R2__IGNORE_RW_PENALTY_DISPR_MASK          0x00000010L
#define MC_DEBUG_R2__IGNORE_RW_PENALTY_DISPR               0x00000010L
#define MC_DEBUG_R2__IGNORE_RW_PENALTY_PPR_MASK            0x00000020L
#define MC_DEBUG_R2__IGNORE_RW_PENALTY_PPR                 0x00000020L
#define MC_DEBUG_R2__IGNORE_RW_PENALTY_FIXED_MASK          0x00000040L
#define MC_DEBUG_R2__IGNORE_RW_PENALTY_FIXED               0x00000040L
#define MC_DEBUG_R2__MEM_VIPW_PRIORITY_MASK                0x00000300L
#define MC_DEBUG_R2__MC_PWRMAN_EN_MASK                     0x00000400L
#define MC_DEBUG_R2__MC_PWRMAN_EN                          0x00000400L
#define MC_DEBUG_R2__CLKA1b_ENABLE_MASK                    0x00000800L
#define MC_DEBUG_R2__CLKA1b_ENABLE                         0x00000800L
#define MC_DEBUG_R2__CLKB0b_ENABLE_MASK                    0x00001000L
#define MC_DEBUG_R2__CLKB0b_ENABLE                         0x00001000L
#define MC_DEBUG_R2__CLKB1b_ENABLE_MASK                    0x00002000L
#define MC_DEBUG_R2__CLKB1b_ENABLE                         0x00002000L
#define MC_DEBUG_R2__DEBUG4_MASK                           0x00004000L
#define MC_DEBUG_R2__DEBUG4                                0x00004000L
#define MC_DEBUG_R2__MC_BIST_EN_MASK                       0x00008000L
#define MC_DEBUG_R2__MC_BIST_EN                            0x00008000L
#define MC_DEBUG_R2__MC_BIST_CTRL_MASK                     0x000f0000L
#define MC_DEBUG_R2__DEBUG0_MASK                           0x00100000L
#define MC_DEBUG_R2__DEBUG0                                0x00100000L
#define MC_DEBUG_R2__DEBUG1_MASK                           0x00200000L
#define MC_DEBUG_R2__DEBUG1                                0x00200000L
#define MC_DEBUG_R2__DEBUG2_MASK                           0x00400000L
#define MC_DEBUG_R2__DEBUG2                                0x00400000L
#define MC_DEBUG_R2__DEBUG3_MASK                           0x00800000L
#define MC_DEBUG_R2__DEBUG3                                0x00800000L
#define MC_DEBUG_R2__MC_DEBUG_MASK                         0x0f000000L
#define MC_DEBUG_R2__PWR_DOWN_MEM_MASK                     0x10000000L
#define MC_DEBUG_R2__PWR_DOWN_MEM                          0x10000000L
#define MC_DEBUG_R2__SWAP_CS_MASK                          0x20000000L
#define MC_DEBUG_R2__SWAP_CS                               0x20000000L
#define MC_DEBUG_R2__BLOCK_CS0_MASK                        0x40000000L
#define MC_DEBUG_R2__BLOCK_CS0                             0x40000000L
#define MC_DEBUG_R2__IKOSE_MASK                            0x80000000L
#define MC_DEBUG_R2__IKOSE                                 0x80000000L

// MC_STATUS
#define MC_STATUS__MEM_PWRUP_COMPL_A_MASK                  0x00000001L
#define MC_STATUS__MEM_PWRUP_COMPL_A                       0x00000001L
#define MC_STATUS__MEM_PWRUP_COMPL_B_MASK                  0x00000002L
#define MC_STATUS__MEM_PWRUP_COMPL_B                       0x00000002L
#define MC_STATUS__MC_IDLE_MASK                            0x00000004L
#define MC_STATUS__MC_IDLE                                 0x00000004L
#define MC_STATUS__SYSM_IDLE_MASK                          0x00010000L
#define MC_STATUS__SYSM_IDLE                               0x00010000L
#define MC_STATUS__SYSM_SHUTDOWN_MASK                      0x00020000L
#define MC_STATUS__SYSM_SHUTDOWN                           0x00020000L
#define MC_STATUS__SYSM_PARKED_MASK                        0x00040000L
#define MC_STATUS__SYSM_PARKED                             0x00040000L
#define MC_STATUS__DLL_READY_MASK                          0x00080000L
#define MC_STATUS__DLL_READY                               0x00080000L

// MEM_IO_OE_CNTL
#define MEM_IO_OE_CNTL__MEM_DQ_OE_EXTEND_A_MASK            0x00000003L
#define MEM_IO_OE_CNTL__MEM_DQ_OE_POSITION_A_MASK          0x0000000cL
#define MEM_IO_OE_CNTL__MEM_QS_OE_EXTEND_A_MASK            0x00000030L
#define MEM_IO_OE_CNTL__MEM_QS_OE_POSITION_A_MASK          0x000000c0L
#define MEM_IO_OE_CNTL__MEM_DQ_OE_EXTEND_B_MASK            0x00000300L
#define MEM_IO_OE_CNTL__MEM_DQ_OE_POSITION_B_MASK          0x00000c00L
#define MEM_IO_OE_CNTL__MEM_QS_OE_EXTEND_B_MASK            0x00003000L
#define MEM_IO_OE_CNTL__MEM_QS_OE_POSITION_B_MASK          0x0000c000L
#define MEM_IO_OE_CNTL__MEM_DYNAMIC_CKE_MASK               0x00010000L
#define MEM_IO_OE_CNTL__MEM_DYNAMIC_CKE                    0x00010000L
#define MEM_IO_OE_CNTL__MEM_SDRAM_TRI_EN_MASK              0x00020000L
#define MEM_IO_OE_CNTL__MEM_SDRAM_TRI_EN                   0x00020000L

// GC_NB_TOM
#define GC_NB_TOM__MC_FB_START_MASK                        0x0000ffffL
#define GC_NB_TOM__MC_FB_TOP_MASK                          0xffff0000L

// AGP_BASE_2_A5
#define AGP_BASE_2_A5__AGP_BASE_ADDR_2_MASK                0x0000000fL

// MC_NB_MC_INDEX
#define MC_NB_MC_INDEX__MC_NB_MC_IND_ADDR_MASK             0x0000003fL
#define MC_NB_MC_INDEX__MC_NB_MC_IND_WR_EN_MASK            0x00000100L
#define MC_NB_MC_INDEX__MC_NB_MC_IND_WR_EN                 0x00000100L

// MC_NB_MC_DATA
#define MC_NB_MC_DATA__MC_NBMC_DATA_MASK                   0xffffffffL

// MC_FB_LOCATION
#define MC_FB_LOCATION__MC_FB_START_MASK                   0x0000ffffL
#define MC_FB_LOCATION__MC_FB_TOP_MASK                     0xffff0000L

// GRA00
#define GRA00__GRPH_SET_RESET0_MASK                        0x00000001L
#define GRA00__GRPH_SET_RESET0                             0x00000001L
#define GRA00__GRPH_SET_RESET1_MASK                        0x00000002L
#define GRA00__GRPH_SET_RESET1                             0x00000002L
#define GRA00__GRPH_SET_RESET2_MASK                        0x00000004L
#define GRA00__GRPH_SET_RESET2                             0x00000004L
#define GRA00__GRPH_SET_RESET3_MASK                        0x00000008L
#define GRA00__GRPH_SET_RESET3                             0x00000008L

// GRA01
#define GRA01__GRPH_SET_RESET_ENA0_MASK                    0x00000001L
#define GRA01__GRPH_SET_RESET_ENA0                         0x00000001L
#define GRA01__GRPH_SET_RESET_ENA1_MASK                    0x00000002L
#define GRA01__GRPH_SET_RESET_ENA1                         0x00000002L
#define GRA01__GRPH_SET_RESET_ENA2_MASK                    0x00000004L
#define GRA01__GRPH_SET_RESET_ENA2                         0x00000004L
#define GRA01__GRPH_SET_RESET_ENA3_MASK                    0x00000008L
#define GRA01__GRPH_SET_RESET_ENA3                         0x00000008L

// GRA02
#define GRA02__GRPH_CCOMP_MASK                             0x0000000fL

// GRA03
#define GRA03__GRPH_ROTATE_MASK                            0x00000007L
#define GRA03__GRPH_FN_SEL_MASK                            0x00000018L

// GRA04
#define GRA04__GRPH_RMAP_MASK                              0x00000003L

// GRA06
#define GRA06__GRPH_GRAPHICS_MASK                          0x00000001L
#define GRA06__GRPH_GRAPHICS                               0x00000001L
#define GRA06__GRPH_ODDEVEN_MASK                           0x00000002L
#define GRA06__GRPH_ODDEVEN                                0x00000002L
#define GRA06__GRPH_ADRSEL_MASK                            0x0000000cL

// GRA07
#define GRA07__GRPH_XCARE0_MASK                            0x00000001L
#define GRA07__GRPH_XCARE0                                 0x00000001L
#define GRA07__GRPH_XCARE1_MASK                            0x00000002L
#define GRA07__GRPH_XCARE1                                 0x00000002L
#define GRA07__GRPH_XCARE2_MASK                            0x00000004L
#define GRA07__GRPH_XCARE2                                 0x00000004L
#define GRA07__GRPH_XCARE3_MASK                            0x00000008L
#define GRA07__GRPH_XCARE3                                 0x00000008L

// GRA08
#define GRA08__GRPH_BMSK_MASK                              0x000000ffL

// SEQ02
#define SEQ02__SEQ_MAP0_EN_MASK                            0x00000001L
#define SEQ02__SEQ_MAP0_EN                                 0x00000001L
#define SEQ02__SEQ_MAP1_EN_MASK                            0x00000002L
#define SEQ02__SEQ_MAP1_EN                                 0x00000002L
#define SEQ02__SEQ_MAP2_EN_MASK                            0x00000004L
#define SEQ02__SEQ_MAP2_EN                                 0x00000004L
#define SEQ02__SEQ_MAP3_EN_MASK                            0x00000008L
#define SEQ02__SEQ_MAP3_EN                                 0x00000008L

// SEQ04
#define SEQ04__SEQ_256K_MASK                               0x00000002L
#define SEQ04__SEQ_256K                                    0x00000002L
#define SEQ04__SEQ_ODDEVEN_MASK                            0x00000004L
#define SEQ04__SEQ_ODDEVEN                                 0x00000004L
#define SEQ04__SEQ_CHAIN_MASK                              0x00000008L
#define SEQ04__SEQ_CHAIN                                   0x00000008L

// CRT1E
#define CRT1E__GRPH_DEC_RD1_MASK                           0x00000002L
#define CRT1E__GRPH_DEC_RD1                                0x00000002L

// CRT1F
#define CRT1F__GRPH_DEC_RD0_MASK                           0x000000ffL

// CRT22
#define CRT22__GRPH_LATCH_DATA_MASK                        0x000000ffL

// CRT1E_S
#define CRT1E_S__GRPH_DEC_RD1_M_MASK                       0x00000002L
#define CRT1E_S__GRPH_DEC_RD1_M                            0x00000002L

// CRT1F_S
#define CRT1F_S__GRPH_DEC_RD0_M_MASK                       0x000000ffL

// CRT22_S
#define CRT22_S__GRPH_LATCH_DATA_M_MASK                    0x000000ffL

// HOST_PATH_CNTL
#define HOST_PATH_CNTL__HDP_WRITE_THROUGH_CACHE_DIS_MASK   0x00400000L
#define HOST_PATH_CNTL__HDP_WRITE_THROUGH_CACHE_DIS        0x00400000L
#define HOST_PATH_CNTL__HDP_APER_CNTL_MASK                 0x00800000L
#define HOST_PATH_CNTL__HDP_APER_CNTL                      0x00800000L
#define HOST_PATH_CNTL__HP_LIN_RD_CACHE_DIS_MASK           0x01000000L
#define HOST_PATH_CNTL__HP_LIN_RD_CACHE_DIS                0x01000000L
#define HOST_PATH_CNTL__HP_RBBM_LOCK_DIS_MASK              0x02000000L
#define HOST_PATH_CNTL__HP_RBBM_LOCK_DIS                   0x02000000L
#define HOST_PATH_CNTL__HDP_SOFT_RESET_MASK                0x04000000L
#define HOST_PATH_CNTL__HDP_SOFT_RESET                     0x04000000L
#define HOST_PATH_CNTL__HDP_READ_BUFFER_INVALIDATE_MASK    0x08000000L
#define HOST_PATH_CNTL__HDP_READ_BUFFER_INVALIDATE         0x08000000L
#define HOST_PATH_CNTL__HDP_WRITE_COMBINER_TIMEOUT_MASK    0x70000000L
#define HOST_PATH_CNTL__HP_TEST_RST_CNTL_MASK              0x80000000L
#define HOST_PATH_CNTL__HP_TEST_RST_CNTL                   0x80000000L

// MEM_VGA_WP_SEL
#define MEM_VGA_WP_SEL__MEM_VGA_WPS0_MASK                  0x00000fffL
#define MEM_VGA_WP_SEL__MEM_VGA_WPS1_MASK                  0x0fff0000L

// MEM_VGA_RP_SEL
#define MEM_VGA_RP_SEL__MEM_VGA_RPS0_MASK                  0x00000fffL
#define MEM_VGA_RP_SEL__MEM_VGA_RPS1_MASK                  0x0fff0000L

// HDP_DEBUG
#define HDP_DEBUG__HDP_0_DEBUG_MASK                        0x00000001L
#define HDP_DEBUG__HDP_0_DEBUG                             0x00000001L
#define HDP_DEBUG__HDP_1_DEBUG_MASK                        0x00000002L
#define HDP_DEBUG__HDP_1_DEBUG                             0x00000002L
#define HDP_DEBUG__HDP_2_DEBUG_MASK                        0x00000004L
#define HDP_DEBUG__HDP_2_DEBUG                             0x00000004L
#define HDP_DEBUG__HDP_3_DEBUG_MASK                        0x00000008L
#define HDP_DEBUG__HDP_3_DEBUG                             0x00000008L
#define HDP_DEBUG__HDP_4_DEBUG_MASK                        0x00000010L
#define HDP_DEBUG__HDP_4_DEBUG                             0x00000010L
#define HDP_DEBUG__HDP_5_DEBUG_MASK                        0x00000020L
#define HDP_DEBUG__HDP_5_DEBUG                             0x00000020L
#define HDP_DEBUG__HDP_6_DEBUG_MASK                        0x00000040L
#define HDP_DEBUG__HDP_6_DEBUG                             0x00000040L
#define HDP_DEBUG__HDP_7_DEBUG_MASK                        0x00000080L
#define HDP_DEBUG__HDP_7_DEBUG                             0x00000080L

// SW_SEMAPHORE
#define SW_SEMAPHORE__SW_SEMAPHORE_MASK                    0x0000ffffL

// SURFACE_CNTL
#define SURFACE_CNTL__SURF_TRANSLATION_DIS_MASK            0x00000100L
#define SURFACE_CNTL__SURF_TRANSLATION_DIS                 0x00000100L
#define SURFACE_CNTL__NONSURF_AP0_SWP_MASK                 0x00300000L
#define SURFACE_CNTL__NONSURF_AP1_SWP_MASK                 0x00c00000L

// SURFACE0_LOWER_BOUND
#define SURFACE0_LOWER_BOUND__SURF_LOWER_MASK              0x0fffffffL

// SURFACE1_LOWER_BOUND
#define SURFACE1_LOWER_BOUND__SURF_LOWER_MASK              0x0fffffffL

// SURFACE2_LOWER_BOUND
#define SURFACE2_LOWER_BOUND__SURF_LOWER_MASK              0x0fffffffL

// SURFACE3_LOWER_BOUND
#define SURFACE3_LOWER_BOUND__SURF_LOWER_MASK              0x0fffffffL

// SURFACE4_LOWER_BOUND
#define SURFACE4_LOWER_BOUND__SURF_LOWER_MASK              0x0fffffffL

// SURFACE5_LOWER_BOUND
#define SURFACE5_LOWER_BOUND__SURF_LOWER_MASK              0x0fffffffL

// SURFACE6_LOWER_BOUND
#define SURFACE6_LOWER_BOUND__SURF_LOWER_MASK              0x0fffffffL

// SURFACE7_LOWER_BOUND
#define SURFACE7_LOWER_BOUND__SURF_LOWER_MASK              0x0fffffffL

// SURFACE0_UPPER_BOUND
#define SURFACE0_UPPER_BOUND__SURF_UPPER_MASK              0x0fffffffL

// SURFACE1_UPPER_BOUND
#define SURFACE1_UPPER_BOUND__SURF_UPPER_MASK              0x0fffffffL

// SURFACE2_UPPER_BOUND
#define SURFACE2_UPPER_BOUND__SURF_UPPER_MASK              0x0fffffffL

// SURFACE3_UPPER_BOUND
#define SURFACE3_UPPER_BOUND__SURF_UPPER_MASK              0x0fffffffL

// SURFACE4_UPPER_BOUND
#define SURFACE4_UPPER_BOUND__SURF_UPPER_MASK              0x0fffffffL

// SURFACE5_UPPER_BOUND
#define SURFACE5_UPPER_BOUND__SURF_UPPER_MASK              0x0fffffffL

// SURFACE6_UPPER_BOUND
#define SURFACE6_UPPER_BOUND__SURF_UPPER_MASK              0x0fffffffL

// SURFACE7_UPPER_BOUND
#define SURFACE7_UPPER_BOUND__SURF_UPPER_MASK              0x0fffffffL

// SURFACE0_INFO
#define SURFACE0_INFO__SURF0_PITCHSEL_MASK                 0x000003ffL
#define SURFACE0_INFO__SURF0_TILE_MODE_R2_MASK             0x00070000L
#define SURFACE0_INFO__SURF0_AP0_SWP_MASK                  0x00300000L
#define SURFACE0_INFO__SURF0_AP1_SWP_MASK                  0x00c00000L
#define SURFACE0_INFO__SURF0_WRITE_FLAG_MASK               0x01000000L
#define SURFACE0_INFO__SURF0_WRITE_FLAG                    0x01000000L
#define SURFACE0_INFO__SURF0_READ_FLAG_MASK                0x02000000L
#define SURFACE0_INFO__SURF0_READ_FLAG                     0x02000000L

// SURFACE1_INFO
#define SURFACE1_INFO__SURF1_PITCHSEL_MASK                 0x000003ffL
#define SURFACE1_INFO__SURF1_TILE_MODE_R2_MASK             0x00070000L
#define SURFACE1_INFO__SURF1_AP0_SWP_MASK                  0x00300000L
#define SURFACE1_INFO__SURF1_AP1_SWP_MASK                  0x00c00000L
#define SURFACE1_INFO__SURF1_WRITE_FLAG_MASK               0x01000000L
#define SURFACE1_INFO__SURF1_WRITE_FLAG                    0x01000000L
#define SURFACE1_INFO__SURF1_READ_FLAG_MASK                0x02000000L
#define SURFACE1_INFO__SURF1_READ_FLAG                     0x02000000L

// SURFACE2_INFO
#define SURFACE2_INFO__SURF2_PITCHSEL_MASK                 0x000003ffL
#define SURFACE2_INFO__SURF2_TILE_MODE_R2_MASK             0x00070000L
#define SURFACE2_INFO__SURF2_AP0_SWP_MASK                  0x00300000L
#define SURFACE2_INFO__SURF2_AP1_SWP_MASK                  0x00c00000L
#define SURFACE2_INFO__SURF2_WRITE_FLAG_MASK               0x01000000L
#define SURFACE2_INFO__SURF2_WRITE_FLAG                    0x01000000L
#define SURFACE2_INFO__SURF2_READ_FLAG_MASK                0x02000000L
#define SURFACE2_INFO__SURF2_READ_FLAG                     0x02000000L

// SURFACE3_INFO
#define SURFACE3_INFO__SURF3_PITCHSEL_MASK                 0x000003ffL
#define SURFACE3_INFO__SURF3_TILE_MODE_R2_MASK             0x00070000L
#define SURFACE3_INFO__SURF3_AP0_SWP_MASK                  0x00300000L
#define SURFACE3_INFO__SURF3_AP1_SWP_MASK                  0x00c00000L
#define SURFACE3_INFO__SURF3_WRITE_FLAG_MASK               0x01000000L
#define SURFACE3_INFO__SURF3_WRITE_FLAG                    0x01000000L
#define SURFACE3_INFO__SURF3_READ_FLAG_MASK                0x02000000L
#define SURFACE3_INFO__SURF3_READ_FLAG                     0x02000000L

// SURFACE4_INFO
#define SURFACE4_INFO__SURF4_PITCHSEL_MASK                 0x000003ffL
#define SURFACE4_INFO__SURF4_TILE_MODE_R2_MASK             0x00070000L
#define SURFACE4_INFO__SURF4_AP0_SWP_MASK                  0x00300000L
#define SURFACE4_INFO__SURF4_AP1_SWP_MASK                  0x00c00000L
#define SURFACE4_INFO__SURF4_WRITE_FLAG_MASK               0x01000000L
#define SURFACE4_INFO__SURF4_WRITE_FLAG                    0x01000000L
#define SURFACE4_INFO__SURF4_READ_FLAG_MASK                0x02000000L
#define SURFACE4_INFO__SURF4_READ_FLAG                     0x02000000L

// SURFACE5_INFO
#define SURFACE5_INFO__SURF5_PITCHSEL_MASK                 0x000003ffL
#define SURFACE5_INFO__SURF5_TILE_MODE_R2_MASK             0x00070000L
#define SURFACE5_INFO__SURF5_AP0_SWP_MASK                  0x00300000L
#define SURFACE5_INFO__SURF5_AP1_SWP_MASK                  0x00c00000L
#define SURFACE5_INFO__SURF5_WRITE_FLAG_MASK               0x01000000L
#define SURFACE5_INFO__SURF5_WRITE_FLAG                    0x01000000L
#define SURFACE5_INFO__SURF5_READ_FLAG_MASK                0x02000000L
#define SURFACE5_INFO__SURF5_READ_FLAG                     0x02000000L

// SURFACE6_INFO
#define SURFACE6_INFO__SURF6_PITCHSEL_MASK                 0x000003ffL
#define SURFACE6_INFO__SURF6_TILE_MODE_R2_MASK             0x00070000L
#define SURFACE6_INFO__SURF6_AP0_SWP_MASK                  0x00300000L
#define SURFACE6_INFO__SURF6_AP1_SWP_MASK                  0x00c00000L
#define SURFACE6_INFO__SURF6_WRITE_FLAG_MASK               0x01000000L
#define SURFACE6_INFO__SURF6_WRITE_FLAG                    0x01000000L
#define SURFACE6_INFO__SURF6_READ_FLAG_MASK                0x02000000L
#define SURFACE6_INFO__SURF6_READ_FLAG                     0x02000000L

// SURFACE7_INFO
#define SURFACE7_INFO__SURF7_PITCHSEL_MASK                 0x000003ffL
#define SURFACE7_INFO__SURF7_TILE_MODE_R2_MASK             0x00070000L
#define SURFACE7_INFO__SURF7_AP0_SWP_MASK                  0x00300000L
#define SURFACE7_INFO__SURF7_AP1_SWP_MASK                  0x00c00000L
#define SURFACE7_INFO__SURF7_WRITE_FLAG_MASK               0x01000000L
#define SURFACE7_INFO__SURF7_WRITE_FLAG                    0x01000000L
#define SURFACE7_INFO__SURF7_READ_FLAG_MASK                0x02000000L
#define SURFACE7_INFO__SURF7_READ_FLAG                     0x02000000L

// SURFACE_ACCESS_FLAGS
#define SURFACE_ACCESS_FLAGS__SURF0_WRITE_FLAG_MASK        0x00000001L
#define SURFACE_ACCESS_FLAGS__SURF0_WRITE_FLAG             0x00000001L
#define SURFACE_ACCESS_FLAGS__SURF1_WRITE_FLAG_MASK        0x00000002L
#define SURFACE_ACCESS_FLAGS__SURF1_WRITE_FLAG             0x00000002L
#define SURFACE_ACCESS_FLAGS__SURF2_WRITE_FLAG_MASK        0x00000004L
#define SURFACE_ACCESS_FLAGS__SURF2_WRITE_FLAG             0x00000004L
#define SURFACE_ACCESS_FLAGS__SURF3_WRITE_FLAG_MASK        0x00000008L
#define SURFACE_ACCESS_FLAGS__SURF3_WRITE_FLAG             0x00000008L
#define SURFACE_ACCESS_FLAGS__SURF4_WRITE_FLAG_MASK        0x00000010L
#define SURFACE_ACCESS_FLAGS__SURF4_WRITE_FLAG             0x00000010L
#define SURFACE_ACCESS_FLAGS__SURF5_WRITE_FLAG_MASK        0x00000020L
#define SURFACE_ACCESS_FLAGS__SURF5_WRITE_FLAG             0x00000020L
#define SURFACE_ACCESS_FLAGS__SURF6_WRITE_FLAG_MASK        0x00000040L
#define SURFACE_ACCESS_FLAGS__SURF6_WRITE_FLAG             0x00000040L
#define SURFACE_ACCESS_FLAGS__SURF7_WRITE_FLAG_MASK        0x00000080L
#define SURFACE_ACCESS_FLAGS__SURF7_WRITE_FLAG             0x00000080L
#define SURFACE_ACCESS_FLAGS__NONSURF_WRITE_FLAG_MASK      0x00000100L
#define SURFACE_ACCESS_FLAGS__NONSURF_WRITE_FLAG           0x00000100L
#define SURFACE_ACCESS_FLAGS__LINEAR_WRITE_FLAG_MASK       0x00000200L
#define SURFACE_ACCESS_FLAGS__LINEAR_WRITE_FLAG            0x00000200L
#define SURFACE_ACCESS_FLAGS__VGA_WRITE_FLAG_MASK          0x00000400L
#define SURFACE_ACCESS_FLAGS__VGA_WRITE_FLAG               0x00000400L
#define SURFACE_ACCESS_FLAGS__SURF0_READ_FLAG_MASK         0x00010000L
#define SURFACE_ACCESS_FLAGS__SURF0_READ_FLAG              0x00010000L
#define SURFACE_ACCESS_FLAGS__SURF1_READ_FLAG_MASK         0x00020000L
#define SURFACE_ACCESS_FLAGS__SURF1_READ_FLAG              0x00020000L
#define SURFACE_ACCESS_FLAGS__SURF2_READ_FLAG_MASK         0x00040000L
#define SURFACE_ACCESS_FLAGS__SURF2_READ_FLAG              0x00040000L
#define SURFACE_ACCESS_FLAGS__SURF3_READ_FLAG_MASK         0x00080000L
#define SURFACE_ACCESS_FLAGS__SURF3_READ_FLAG              0x00080000L
#define SURFACE_ACCESS_FLAGS__SURF4_READ_FLAG_MASK         0x00100000L
#define SURFACE_ACCESS_FLAGS__SURF4_READ_FLAG              0x00100000L
#define SURFACE_ACCESS_FLAGS__SURF5_READ_FLAG_MASK         0x00200000L
#define SURFACE_ACCESS_FLAGS__SURF5_READ_FLAG              0x00200000L
#define SURFACE_ACCESS_FLAGS__SURF6_READ_FLAG_MASK         0x00400000L
#define SURFACE_ACCESS_FLAGS__SURF6_READ_FLAG              0x00400000L
#define SURFACE_ACCESS_FLAGS__SURF7_READ_FLAG_MASK         0x00800000L
#define SURFACE_ACCESS_FLAGS__SURF7_READ_FLAG              0x00800000L
#define SURFACE_ACCESS_FLAGS__NONSURF_READ_FLAG_MASK       0x01000000L
#define SURFACE_ACCESS_FLAGS__NONSURF_READ_FLAG            0x01000000L
#define SURFACE_ACCESS_FLAGS__LINEAR_READ_FLAG_MASK        0x02000000L
#define SURFACE_ACCESS_FLAGS__LINEAR_READ_FLAG             0x02000000L
#define SURFACE_ACCESS_FLAGS__VGA_READ_FLAG_MASK           0x04000000L
#define SURFACE_ACCESS_FLAGS__VGA_READ_FLAG                0x04000000L

// SURFACE_ACCESS_CLR
#define SURFACE_ACCESS_CLR__SURF0_WRITE_FLAG_CLR_MASK      0x00000001L
#define SURFACE_ACCESS_CLR__SURF0_WRITE_FLAG_CLR           0x00000001L
#define SURFACE_ACCESS_CLR__SURF1_WRITE_FLAG_CLR_MASK      0x00000002L
#define SURFACE_ACCESS_CLR__SURF1_WRITE_FLAG_CLR           0x00000002L
#define SURFACE_ACCESS_CLR__SURF2_WRITE_FLAG_CLR_MASK      0x00000004L
#define SURFACE_ACCESS_CLR__SURF2_WRITE_FLAG_CLR           0x00000004L
#define SURFACE_ACCESS_CLR__SURF3_WRITE_FLAG_CLR_MASK      0x00000008L
#define SURFACE_ACCESS_CLR__SURF3_WRITE_FLAG_CLR           0x00000008L
#define SURFACE_ACCESS_CLR__SURF4_WRITE_FLAG_CLR_MASK      0x00000010L
#define SURFACE_ACCESS_CLR__SURF4_WRITE_FLAG_CLR           0x00000010L
#define SURFACE_ACCESS_CLR__SURF5_WRITE_FLAG_CLR_MASK      0x00000020L
#define SURFACE_ACCESS_CLR__SURF5_WRITE_FLAG_CLR           0x00000020L
#define SURFACE_ACCESS_CLR__SURF6_WRITE_FLAG_CLR_MASK      0x00000040L
#define SURFACE_ACCESS_CLR__SURF6_WRITE_FLAG_CLR           0x00000040L
#define SURFACE_ACCESS_CLR__SURF7_WRITE_FLAG_CLR_MASK      0x00000080L
#define SURFACE_ACCESS_CLR__SURF7_WRITE_FLAG_CLR           0x00000080L
#define SURFACE_ACCESS_CLR__NONSURF_WRITE_FLAG_CLR_MASK    0x00000100L
#define SURFACE_ACCESS_CLR__NONSURF_WRITE_FLAG_CLR         0x00000100L
#define SURFACE_ACCESS_CLR__LINEAR_WRITE_FLAG_CLR_MASK     0x00000200L
#define SURFACE_ACCESS_CLR__LINEAR_WRITE_FLAG_CLR          0x00000200L
#define SURFACE_ACCESS_CLR__VGA_WRITE_FLAG_CLR_MASK        0x00000400L
#define SURFACE_ACCESS_CLR__VGA_WRITE_FLAG_CLR             0x00000400L
#define SURFACE_ACCESS_CLR__SURF0_READ_FLAG_CLR_MASK       0x00010000L
#define SURFACE_ACCESS_CLR__SURF0_READ_FLAG_CLR            0x00010000L
#define SURFACE_ACCESS_CLR__SURF1_READ_FLAG_CLR_MASK       0x00020000L
#define SURFACE_ACCESS_CLR__SURF1_READ_FLAG_CLR            0x00020000L
#define SURFACE_ACCESS_CLR__SURF2_READ_FLAG_CLR_MASK       0x00040000L
#define SURFACE_ACCESS_CLR__SURF2_READ_FLAG_CLR            0x00040000L
#define SURFACE_ACCESS_CLR__SURF3_READ_FLAG_CLR_MASK       0x00080000L
#define SURFACE_ACCESS_CLR__SURF3_READ_FLAG_CLR            0x00080000L
#define SURFACE_ACCESS_CLR__SURF4_READ_FLAG_CLR_MASK       0x00100000L
#define SURFACE_ACCESS_CLR__SURF4_READ_FLAG_CLR            0x00100000L
#define SURFACE_ACCESS_CLR__SURF5_READ_FLAG_CLR_MASK       0x00200000L
#define SURFACE_ACCESS_CLR__SURF5_READ_FLAG_CLR            0x00200000L
#define SURFACE_ACCESS_CLR__SURF6_READ_FLAG_CLR_MASK       0x00400000L
#define SURFACE_ACCESS_CLR__SURF6_READ_FLAG_CLR            0x00400000L
#define SURFACE_ACCESS_CLR__SURF7_READ_FLAG_CLR_MASK       0x00800000L
#define SURFACE_ACCESS_CLR__SURF7_READ_FLAG_CLR            0x00800000L
#define SURFACE_ACCESS_CLR__NONSURF_READ_FLAG_CLR_MASK     0x01000000L
#define SURFACE_ACCESS_CLR__NONSURF_READ_FLAG_CLR          0x01000000L
#define SURFACE_ACCESS_CLR__LINEAR_READ_FLAG_CLR_MASK      0x02000000L
#define SURFACE_ACCESS_CLR__LINEAR_READ_FLAG_CLR           0x02000000L
#define SURFACE_ACCESS_CLR__VGA_READ_FLAG_CLR_MASK         0x04000000L
#define SURFACE_ACCESS_CLR__VGA_READ_FLAG_CLR              0x04000000L

// GRPH8_IDX
#define GRPH8_IDX__GRPH_IDX_MASK                           0x0000000fL

// GRPH8_DATA
#define GRPH8_DATA__GRPH_DATA_MASK                         0x000000ffL

// GRA05
#define GRA05__GRPH_WRITE_MODE_MASK                        0x00000003L
#define GRA05__GRPH_READ1_MASK                             0x00000008L
#define GRA05__GRPH_READ1                                  0x00000008L
#define GRA05__CGA_ODDEVEN_MASK                            0x00000010L
#define GRA05__CGA_ODDEVEN                                 0x00000010L
#define GRA05__GRPH_OES_MASK                               0x00000020L
#define GRA05__GRPH_OES                                    0x00000020L
#define GRA05__GRPH_PACK_MASK                              0x00000040L
#define GRA05__GRPH_PACK                                   0x00000040L

// SEQ8_IDX
#define SEQ8_IDX__SEQ_IDX_MASK                             0x00000007L

// SEQ8_DATA
#define SEQ8_DATA__SEQ_DATA_MASK                           0x000000ffL

// CRTC8_IDX
#define CRTC8_IDX__VCRTC_IDX_MASK                          0x0000003fL

// CRTC8_DATA
#define CRTC8_DATA__VCRTC_DATA_MASK                        0x000000ffL

// CRT14
#define CRT14__UNDRLN_LOC_MASK                             0x0000001fL
#define CRT14__ADDR_CNT_BY4_MASK                           0x00000020L
#define CRT14__ADDR_CNT_BY4                                0x00000020L
#define CRT14__DOUBLE_WORD_MASK                            0x00000040L
#define CRT14__DOUBLE_WORD                                 0x00000040L

// CRT17
#define CRT17__RA0_AS_A13B_MASK                            0x00000001L
#define CRT17__RA0_AS_A13B                                 0x00000001L
#define CRT17__RA1_AS_A14B_MASK                            0x00000002L
#define CRT17__RA1_AS_A14B                                 0x00000002L
#define CRT17__VCOUNT_BY2_MASK                             0x00000004L
#define CRT17__VCOUNT_BY2                                  0x00000004L
#define CRT17__ADDR_CNT_BY2_MASK                           0x00000008L
#define CRT17__ADDR_CNT_BY2                                0x00000008L
#define CRT17__WRAP_A15TOA0_MASK                           0x00000020L
#define CRT17__WRAP_A15TOA0                                0x00000020L
#define CRT17__BYTE_MODE_MASK                              0x00000040L
#define CRT17__BYTE_MODE                                   0x00000040L
#define CRT17__CRTC_SYNC_EN_MASK                           0x00000080L
#define CRT17__CRTC_SYNC_EN                                0x00000080L

// CRT14_S
#define CRT14_S__UNDRLN_LOC_S_MASK                         0x0000001fL
#define CRT14_S__ADDR_CNT_BY4_M_MASK                       0x00000020L
#define CRT14_S__ADDR_CNT_BY4_M                            0x00000020L
#define CRT14_S__DOUBLE_WORD_M_MASK                        0x00000040L
#define CRT14_S__DOUBLE_WORD_M                             0x00000040L

// CRT17_S
#define CRT17_S__RA0_AS_A13B_M_MASK                        0x00000001L
#define CRT17_S__RA0_AS_A13B_M                             0x00000001L
#define CRT17_S__RA1_AS_A14B_M_MASK                        0x00000002L
#define CRT17_S__RA1_AS_A14B_M                             0x00000002L
#define CRT17_S__VCOUNT_BY2_S_MASK                         0x00000004L
#define CRT17_S__VCOUNT_BY2_S                              0x00000004L
#define CRT17_S__ADDR_CNT_BY2_M_MASK                       0x00000008L
#define CRT17_S__ADDR_CNT_BY2_M                            0x00000008L
#define CRT17_S__WRAP_A15TOA0_M_MASK                       0x00000020L
#define CRT17_S__WRAP_A15TOA0_M                            0x00000020L
#define CRT17_S__BYTE_MODE_M_MASK                          0x00000040L
#define CRT17_S__BYTE_MODE_M                               0x00000040L
#define CRT17_S__CRTC_SYNC_EN_M_MASK                       0x00000080L
#define CRT17_S__CRTC_SYNC_EN_M                            0x00000080L

// GEN_INT_CNTL
#define GEN_INT_CNTL__CRTC_VBLANK_MASK_MASK                0x00000001L
#define GEN_INT_CNTL__CRTC_VBLANK_MASK                     0x00000001L
#define GEN_INT_CNTL__CRTC_VLINE_MASK_MASK                 0x00000002L
#define GEN_INT_CNTL__CRTC_VLINE_MASK                      0x00000002L
#define GEN_INT_CNTL__CRTC_VSYNC_MASK_MASK                 0x00000004L
#define GEN_INT_CNTL__CRTC_VSYNC_MASK                      0x00000004L
#define GEN_INT_CNTL__SNAPSHOT_MASK_MASK                   0x00000008L
#define GEN_INT_CNTL__SNAPSHOT_MASK                        0x00000008L
#define GEN_INT_CNTL__FP_DETECT_MASK_MASK                  0x00000010L
#define GEN_INT_CNTL__FP_DETECT_MASK                       0x00000010L
#define GEN_INT_CNTL__CRTC2_VLINE_MASK_MASK                0x00000020L
#define GEN_INT_CNTL__CRTC2_VLINE_MASK                     0x00000020L
#define GEN_INT_CNTL__CRTC2_VSYNC_MASK_MASK                0x00000040L
#define GEN_INT_CNTL__CRTC2_VSYNC_MASK                     0x00000040L
#define GEN_INT_CNTL__SNAPSHOT2_MASK_MASK                  0x00000080L
#define GEN_INT_CNTL__SNAPSHOT2_MASK                       0x00000080L
#define GEN_INT_CNTL__CRTC2_VBLANK_MASK_MASK               0x00000200L
#define GEN_INT_CNTL__CRTC2_VBLANK_MASK                    0x00000200L
#define GEN_INT_CNTL__FP2_DETECT_MASK_MASK                 0x00000400L
#define GEN_INT_CNTL__FP2_DETECT_MASK                      0x00000400L
#define GEN_INT_CNTL__VSYNC_DIFF_OVER_LIMIT_MASK_MASK      0x00000800L
#define GEN_INT_CNTL__VSYNC_DIFF_OVER_LIMIT_MASK           0x00000800L
#define GEN_INT_CNTL__GUI_IDLE_MASK_MASK                   0x00080000L
#define GEN_INT_CNTL__GUI_IDLE_MASK                        0x00080000L
#define GEN_INT_CNTL__SW_INT_EN_MASK                       0x02000000L
#define GEN_INT_CNTL__SW_INT_EN                            0x02000000L
#define GEN_INT_CNTL__GEYSERVILLE_MASK_MASK                0x08000000L
#define GEN_INT_CNTL__GEYSERVILLE_MASK                     0x08000000L
#define GEN_INT_CNTL__HDCP_AUTHORIZED_INT_MASK_MASK        0x10000000L
#define GEN_INT_CNTL__HDCP_AUTHORIZED_INT_MASK             0x10000000L
#define GEN_INT_CNTL__DVI_I2C_INT_MASK_MASK                0x20000000L
#define GEN_INT_CNTL__DVI_I2C_INT_MASK                     0x20000000L
#define GEN_INT_CNTL__GUIDMA_MASK_MASK                     0x40000000L
#define GEN_INT_CNTL__GUIDMA_MASK                          0x40000000L
#define GEN_INT_CNTL__VIDDMA_MASK_MASK                     0x80000000L
#define GEN_INT_CNTL__VIDDMA_MASK                          0x80000000L

// GEN_INT_STATUS
#define GEN_INT_STATUS__CRTC_VBLANK_STAT_MASK              0x00000001L
#define GEN_INT_STATUS__CRTC_VBLANK_STAT                   0x00000001L
#define GEN_INT_STATUS__CRTC_VBLANK_STAT_AK_MASK           0x00000001L
#define GEN_INT_STATUS__CRTC_VBLANK_STAT_AK                0x00000001L
#define GEN_INT_STATUS__CRTC_VLINE_STAT_MASK               0x00000002L
#define GEN_INT_STATUS__CRTC_VLINE_STAT                    0x00000002L
#define GEN_INT_STATUS__CRTC_VLINE_STAT_AK_MASK            0x00000002L
#define GEN_INT_STATUS__CRTC_VLINE_STAT_AK                 0x00000002L
#define GEN_INT_STATUS__CRTC_VSYNC_STAT_MASK               0x00000004L
#define GEN_INT_STATUS__CRTC_VSYNC_STAT                    0x00000004L
#define GEN_INT_STATUS__CRTC_VSYNC_STAT_AK_MASK            0x00000004L
#define GEN_INT_STATUS__CRTC_VSYNC_STAT_AK                 0x00000004L
#define GEN_INT_STATUS__SNAPSHOT_STAT_MASK                 0x00000008L
#define GEN_INT_STATUS__SNAPSHOT_STAT                      0x00000008L
#define GEN_INT_STATUS__SNAPSHOT_STAT_AK_MASK              0x00000008L
#define GEN_INT_STATUS__SNAPSHOT_STAT_AK                   0x00000008L
#define GEN_INT_STATUS__FP_DETECT_STAT_MASK                0x00000010L
#define GEN_INT_STATUS__FP_DETECT_STAT                     0x00000010L
#define GEN_INT_STATUS__FP_DETECT_STAT_AK_MASK             0x00000010L
#define GEN_INT_STATUS__FP_DETECT_STAT_AK                  0x00000010L
#define GEN_INT_STATUS__CRTC2_VLINE_STAT_MASK              0x00000020L
#define GEN_INT_STATUS__CRTC2_VLINE_STAT                   0x00000020L
#define GEN_INT_STATUS__CRTC2_VLINE_STAT_AK_MASK           0x00000020L
#define GEN_INT_STATUS__CRTC2_VLINE_STAT_AK                0x00000020L
#define GEN_INT_STATUS__CRTC2_VSYNC_STAT_MASK              0x00000040L
#define GEN_INT_STATUS__CRTC2_VSYNC_STAT                   0x00000040L
#define GEN_INT_STATUS__CRTC2_VSYNC_STAT_AK_MASK           0x00000040L
#define GEN_INT_STATUS__CRTC2_VSYNC_STAT_AK                0x00000040L
#define GEN_INT_STATUS__SNAPSHOT2_STAT_MASK                0x00000080L
#define GEN_INT_STATUS__SNAPSHOT2_STAT                     0x00000080L
#define GEN_INT_STATUS__SNAPSHOT2_STAT_AK_MASK             0x00000080L
#define GEN_INT_STATUS__SNAPSHOT2_STAT_AK                  0x00000080L
#define GEN_INT_STATUS__CAP0_INT_ACTIVE_MASK               0x00000100L
#define GEN_INT_STATUS__CAP0_INT_ACTIVE                    0x00000100L
#define GEN_INT_STATUS__CRTC2_VBLANK_STAT_MASK             0x00000200L
#define GEN_INT_STATUS__CRTC2_VBLANK_STAT                  0x00000200L
#define GEN_INT_STATUS__CRTC2_VBLANK_STAT_AK_MASK          0x00000200L
#define GEN_INT_STATUS__CRTC2_VBLANK_STAT_AK               0x00000200L
#define GEN_INT_STATUS__FP2_DETECT_STAT_MASK               0x00000400L
#define GEN_INT_STATUS__FP2_DETECT_STAT                    0x00000400L
#define GEN_INT_STATUS__FP2_DETECT_STAT_AK_MASK            0x00000400L
#define GEN_INT_STATUS__FP2_DETECT_STAT_AK                 0x00000400L
#define GEN_INT_STATUS__VSYNC_DIFF_OVER_LIMIT_STAT_MASK    0x00000800L
#define GEN_INT_STATUS__VSYNC_DIFF_OVER_LIMIT_STAT         0x00000800L
#define GEN_INT_STATUS__VSYNC_DIFF_OVER_LIMIT_STAT_AK_MASK 0x00000800L
#define GEN_INT_STATUS__VSYNC_DIFF_OVER_LIMIT_STAT_AK      0x00000800L
#define GEN_INT_STATUS__GUI_IDLE_STAT_MASK                 0x00080000L
#define GEN_INT_STATUS__GUI_IDLE_STAT                      0x00080000L
#define GEN_INT_STATUS__GUI_IDLE_STAT_AK_MASK              0x00080000L
#define GEN_INT_STATUS__GUI_IDLE_STAT_AK                   0x00080000L
#define GEN_INT_STATUS__SW_INT_MASK                        0x02000000L
#define GEN_INT_STATUS__SW_INT                             0x02000000L
#define GEN_INT_STATUS__SW_INT_AK_MASK                     0x02000000L
#define GEN_INT_STATUS__SW_INT_AK                          0x02000000L
#define GEN_INT_STATUS__SW_INT_SET_MASK                    0x04000000L
#define GEN_INT_STATUS__SW_INT_SET                         0x04000000L
#define GEN_INT_STATUS__GEYSERVILLE_STAT_MASK              0x08000000L
#define GEN_INT_STATUS__GEYSERVILLE_STAT                   0x08000000L
#define GEN_INT_STATUS__GEYSERVILLE_STAT_AK_MASK           0x08000000L
#define GEN_INT_STATUS__GEYSERVILLE_STAT_AK                0x08000000L
#define GEN_INT_STATUS__HDCP_AUTHORIZED_INT_STAT_MASK      0x10000000L
#define GEN_INT_STATUS__HDCP_AUTHORIZED_INT_STAT           0x10000000L
#define GEN_INT_STATUS__HDCP_AUTHORIZED_INT_AK_MASK        0x10000000L
#define GEN_INT_STATUS__HDCP_AUTHORIZED_INT_AK             0x10000000L
#define GEN_INT_STATUS__DVI_I2C_INT_STAT_MASK              0x20000000L
#define GEN_INT_STATUS__DVI_I2C_INT_STAT                   0x20000000L
#define GEN_INT_STATUS__DVI_I2C_INT_AK_MASK                0x20000000L
#define GEN_INT_STATUS__DVI_I2C_INT_AK                     0x20000000L
#define GEN_INT_STATUS__GUIDMA_STAT_MASK                   0x40000000L
#define GEN_INT_STATUS__GUIDMA_STAT                        0x40000000L
#define GEN_INT_STATUS__GUIDMA_AK_MASK                     0x40000000L
#define GEN_INT_STATUS__GUIDMA_AK                          0x40000000L
#define GEN_INT_STATUS__VIDDMA_STAT_MASK                   0x80000000L
#define GEN_INT_STATUS__VIDDMA_STAT                        0x80000000L
#define GEN_INT_STATUS__VIDDMA_AK_MASK                     0x80000000L
#define GEN_INT_STATUS__VIDDMA_AK                          0x80000000L

// CRTC_EXT_CNTL
#define CRTC_EXT_CNTL__CRTC_VGA_XOVERSCAN_MASK             0x00000001L
#define CRTC_EXT_CNTL__CRTC_VGA_XOVERSCAN                  0x00000001L
#define CRTC_EXT_CNTL__VGA_BLINK_RATE_MASK                 0x00000006L
#define CRTC_EXT_CNTL__VGA_ATI_LINEAR_MASK                 0x00000008L
#define CRTC_EXT_CNTL__VGA_ATI_LINEAR                      0x00000008L
#define CRTC_EXT_CNTL__VGA_128KAP_PAGING_MASK              0x00000010L
#define CRTC_EXT_CNTL__VGA_128KAP_PAGING                   0x00000010L
#define CRTC_EXT_CNTL__VGA_TEXT_132_MASK                   0x00000020L
#define CRTC_EXT_CNTL__VGA_TEXT_132                        0x00000020L
#define CRTC_EXT_CNTL__VGA_XCRT_CNT_EN_MASK                0x00000040L
#define CRTC_EXT_CNTL__VGA_XCRT_CNT_EN                     0x00000040L
#define CRTC_EXT_CNTL__CRTC_HSYNC_DIS_MASK                 0x00000100L
#define CRTC_EXT_CNTL__CRTC_HSYNC_DIS                      0x00000100L
#define CRTC_EXT_CNTL__CRTC_VSYNC_DIS_MASK                 0x00000200L
#define CRTC_EXT_CNTL__CRTC_VSYNC_DIS                      0x00000200L
#define CRTC_EXT_CNTL__CRTC_DISPLAY_DIS_MASK               0x00000400L
#define CRTC_EXT_CNTL__CRTC_DISPLAY_DIS                    0x00000400L
#define CRTC_EXT_CNTL__CRTC_SYNC_TRISTATE_MASK             0x00000800L
#define CRTC_EXT_CNTL__CRTC_SYNC_TRISTATE                  0x00000800L
#define CRTC_EXT_CNTL__CRTC_HSYNC_TRISTATE_MASK            0x00001000L
#define CRTC_EXT_CNTL__CRTC_HSYNC_TRISTATE                 0x00001000L
#define CRTC_EXT_CNTL__CRTC_VSYNC_TRISTATE_MASK            0x00002000L
#define CRTC_EXT_CNTL__CRTC_VSYNC_TRISTATE                 0x00002000L
#define CRTC_EXT_CNTL__CRT_ON_MASK                         0x00008000L
#define CRTC_EXT_CNTL__CRT_ON                              0x00008000L
#define CRTC_EXT_CNTL__VGA_CUR_B_TEST_MASK                 0x00020000L
#define CRTC_EXT_CNTL__VGA_CUR_B_TEST                      0x00020000L
#define CRTC_EXT_CNTL__VGA_PACK_DIS_MASK                   0x00040000L
#define CRTC_EXT_CNTL__VGA_PACK_DIS                        0x00040000L
#define CRTC_EXT_CNTL__VGA_MEM_PS_EN_MASK                  0x00080000L
#define CRTC_EXT_CNTL__VGA_MEM_PS_EN                       0x00080000L
#define CRTC_EXT_CNTL__VCRTC_IDX_MASTER_MASK               0x7f000000L

// WAIT_UNTIL
#define WAIT_UNTIL__WAIT_CRTC_PFLIP_MASK                   0x00000001L
#define WAIT_UNTIL__WAIT_CRTC_PFLIP                        0x00000001L
#define WAIT_UNTIL__WAIT_RE_CRTC_VLINE_MASK                0x00000002L
#define WAIT_UNTIL__WAIT_RE_CRTC_VLINE                     0x00000002L
#define WAIT_UNTIL__WAIT_FE_CRTC_VLINE_MASK                0x00000004L
#define WAIT_UNTIL__WAIT_FE_CRTC_VLINE                     0x00000004L
#define WAIT_UNTIL__WAIT_CRTC_VLINE_MASK                   0x00000008L
#define WAIT_UNTIL__WAIT_CRTC_VLINE                        0x00000008L
#define WAIT_UNTIL__WAIT_DMA_VIPH0_IDLE_MASK               0x00000010L
#define WAIT_UNTIL__WAIT_DMA_VIPH0_IDLE                    0x00000010L
#define WAIT_UNTIL__WAIT_DMA_VIPH1_IDLE_MASK               0x00000020L
#define WAIT_UNTIL__WAIT_DMA_VIPH1_IDLE                    0x00000020L
#define WAIT_UNTIL__WAIT_DMA_VIPH2_IDLE_MASK               0x00000040L
#define WAIT_UNTIL__WAIT_DMA_VIPH2_IDLE                    0x00000040L
#define WAIT_UNTIL__WAIT_DMA_VIPH3_IDLE_MASK               0x00000080L
#define WAIT_UNTIL__WAIT_DMA_VIPH3_IDLE                    0x00000080L
#define WAIT_UNTIL__WAIT_DMA_VID_IDLE_MASK                 0x00000100L
#define WAIT_UNTIL__WAIT_DMA_VID_IDLE                      0x00000100L
#define WAIT_UNTIL__WAIT_DMA_GUI_IDLE_MASK                 0x00000200L
#define WAIT_UNTIL__WAIT_DMA_GUI_IDLE                      0x00000200L
#define WAIT_UNTIL__WAIT_CMDFIFO_MASK                      0x00000400L
#define WAIT_UNTIL__WAIT_CMDFIFO                           0x00000400L
#define WAIT_UNTIL__WAIT_OV0_FLIP_MASK                     0x00000800L
#define WAIT_UNTIL__WAIT_OV0_FLIP                          0x00000800L
#define WAIT_UNTIL__WAIT_OV0_SLICEDONE_MASK                0x00001000L
#define WAIT_UNTIL__WAIT_OV0_SLICEDONE                     0x00001000L
#define WAIT_UNTIL__WAIT_2D_IDLE_MASK                      0x00004000L
#define WAIT_UNTIL__WAIT_2D_IDLE                           0x00004000L
#define WAIT_UNTIL__WAIT_3D_IDLE_MASK                      0x00008000L
#define WAIT_UNTIL__WAIT_3D_IDLE                           0x00008000L
#define WAIT_UNTIL__WAIT_2D_IDLECLEAN_MASK                 0x00010000L
#define WAIT_UNTIL__WAIT_2D_IDLECLEAN                      0x00010000L
#define WAIT_UNTIL__WAIT_3D_IDLECLEAN_MASK                 0x00020000L
#define WAIT_UNTIL__WAIT_3D_IDLECLEAN                      0x00020000L
#define WAIT_UNTIL__WAIT_HOST_IDLECLEAN_MASK               0x00040000L
#define WAIT_UNTIL__WAIT_HOST_IDLECLEAN                    0x00040000L
#define WAIT_UNTIL__WAIT_EXTERN_SIG_MASK                   0x00080000L
#define WAIT_UNTIL__WAIT_EXTERN_SIG                        0x00080000L
#define WAIT_UNTIL__CMDFIFO_ENTRIES_MASK                   0x07f00000L
#define WAIT_UNTIL__WAIT_BOTH_CRTC_PFLIP_MASK              0x40000000L
#define WAIT_UNTIL__WAIT_BOTH_CRTC_PFLIP                   0x40000000L
#define WAIT_UNTIL__ENG_DISPLAY_SELECT_MASK                0x80000000L
#define WAIT_UNTIL__ENG_DISPLAY_SELECT                     0x80000000L

// ISYNC_CNTL
#define ISYNC_CNTL__ISYNC_ANY2D_IDLE3D_MASK                0x00000001L
#define ISYNC_CNTL__ISYNC_ANY2D_IDLE3D                     0x00000001L
#define ISYNC_CNTL__ISYNC_ANY3D_IDLE2D_MASK                0x00000002L
#define ISYNC_CNTL__ISYNC_ANY3D_IDLE2D                     0x00000002L
#define ISYNC_CNTL__ISYNC_TRIG2D_IDLE3D_MASK               0x00000004L
#define ISYNC_CNTL__ISYNC_TRIG2D_IDLE3D                    0x00000004L
#define ISYNC_CNTL__ISYNC_TRIG3D_IDLE2D_MASK               0x00000008L
#define ISYNC_CNTL__ISYNC_TRIG3D_IDLE2D                    0x00000008L
#define ISYNC_CNTL__ISYNC_WAIT_IDLEGUI_MASK                0x00000010L
#define ISYNC_CNTL__ISYNC_WAIT_IDLEGUI                     0x00000010L
#define ISYNC_CNTL__ISYNC_CPSCRATCH_IDLEGUI_MASK           0x00000020L
#define ISYNC_CNTL__ISYNC_CPSCRATCH_IDLEGUI                0x00000020L

// RBBM_GUICNTL
#define RBBM_GUICNTL__HOST_DATA_SWAP_MASK                  0x00000003L

// RBBM_STATUS
#define RBBM_STATUS__CMDFIFO_AVAIL_MASK                    0x0000007fL
#define RBBM_STATUS__HIRQ_ON_RBB_MASK                      0x00000100L
#define RBBM_STATUS__HIRQ_ON_RBB                           0x00000100L
#define RBBM_STATUS__CPRQ_ON_RBB_MASK                      0x00000200L
#define RBBM_STATUS__CPRQ_ON_RBB                           0x00000200L
#define RBBM_STATUS__CFRQ_ON_RBB_MASK                      0x00000400L
#define RBBM_STATUS__CFRQ_ON_RBB                           0x00000400L
#define RBBM_STATUS__HIRQ_IN_RTBUF_MASK                    0x00000800L
#define RBBM_STATUS__HIRQ_IN_RTBUF                         0x00000800L
#define RBBM_STATUS__CPRQ_IN_RTBUF_MASK                    0x00001000L
#define RBBM_STATUS__CPRQ_IN_RTBUF                         0x00001000L
#define RBBM_STATUS__CFRQ_IN_RTBUF_MASK                    0x00002000L
#define RBBM_STATUS__CFRQ_IN_RTBUF                         0x00002000L
#define RBBM_STATUS__CF_PIPE_BUSY_MASK                     0x00004000L
#define RBBM_STATUS__CF_PIPE_BUSY                          0x00004000L
#define RBBM_STATUS__ENG_EV_BUSY_MASK                      0x00008000L
#define RBBM_STATUS__ENG_EV_BUSY                           0x00008000L
#define RBBM_STATUS__CP_CMDSTRM_BUSY_MASK                  0x00010000L
#define RBBM_STATUS__CP_CMDSTRM_BUSY                       0x00010000L
#define RBBM_STATUS__E2_BUSY_MASK                          0x00020000L
#define RBBM_STATUS__E2_BUSY                               0x00020000L
#define RBBM_STATUS__RB2D_BUSY_MASK                        0x00040000L
#define RBBM_STATUS__RB2D_BUSY                             0x00040000L
#define RBBM_STATUS__RB3D_BUSY_MASK                        0x00080000L
#define RBBM_STATUS__RB3D_BUSY                             0x00080000L
#define RBBM_STATUS__VAP_BUSY_MASK                         0x00100000L
#define RBBM_STATUS__VAP_BUSY                              0x00100000L
#define RBBM_STATUS__RE_BUSY_MASK                          0x00200000L
#define RBBM_STATUS__RE_BUSY                               0x00200000L
#define RBBM_STATUS__TAM_BUSY_MASK                         0x00400000L
#define RBBM_STATUS__TAM_BUSY                              0x00400000L
#define RBBM_STATUS__TDM_BUSY_MASK                         0x00800000L
#define RBBM_STATUS__TDM_BUSY                              0x00800000L
#define RBBM_STATUS__PB_BUSY_MASK                          0x01000000L
#define RBBM_STATUS__PB_BUSY                               0x01000000L
#define RBBM_STATUS__TIM_BUSY_MASK                         0x02000000L
#define RBBM_STATUS__TIM_BUSY                              0x02000000L
#define RBBM_STATUS__GUI_ACTIVE_MASK                       0x80000000L
#define RBBM_STATUS__GUI_ACTIVE                            0x80000000L

// RBBM_CNTL
#define RBBM_CNTL__RB_SETTLE_MASK                          0x0000000fL
#define RBBM_CNTL__ABORTCLKS_HI_MASK                       0x00000070L
#define RBBM_CNTL__ABORTCLKS_CP_MASK                       0x00000700L
#define RBBM_CNTL__ABORTCLKS_CFIFO_MASK                    0x00007000L
#define RBBM_CNTL__CPQ_DATA_SWAP_MASK                      0x00020000L
#define RBBM_CNTL__CPQ_DATA_SWAP                           0x00020000L
#define RBBM_CNTL__NO_ABORT_IDCT_MASK                      0x00200000L
#define RBBM_CNTL__NO_ABORT_IDCT                           0x00200000L
#define RBBM_CNTL__NO_ABORT_BIOS_MASK                      0x00400000L
#define RBBM_CNTL__NO_ABORT_BIOS                           0x00400000L
#define RBBM_CNTL__NO_ABORT_TVOUT_MASK                     0x00800000L
#define RBBM_CNTL__NO_ABORT_TVOUT                          0x00800000L
#define RBBM_CNTL__NO_ABORT_CP_MASK                        0x01000000L
#define RBBM_CNTL__NO_ABORT_CP                             0x01000000L
#define RBBM_CNTL__NO_ABORT_HI_MASK                        0x02000000L
#define RBBM_CNTL__NO_ABORT_HI                             0x02000000L
#define RBBM_CNTL__NO_ABORT_HDP_MASK                       0x04000000L
#define RBBM_CNTL__NO_ABORT_HDP                            0x04000000L
#define RBBM_CNTL__NO_ABORT_MC_MASK                        0x08000000L
#define RBBM_CNTL__NO_ABORT_MC                             0x08000000L
#define RBBM_CNTL__NO_ABORT_AIC_MASK                       0x10000000L
#define RBBM_CNTL__NO_ABORT_AIC                            0x10000000L
#define RBBM_CNTL__NO_ABORT_VIP_MASK                       0x20000000L
#define RBBM_CNTL__NO_ABORT_VIP                            0x20000000L
#define RBBM_CNTL__NO_ABORT_DISP_MASK                      0x40000000L
#define RBBM_CNTL__NO_ABORT_DISP                           0x40000000L
#define RBBM_CNTL__NO_ABORT_CG_MASK                        0x80000000L
#define RBBM_CNTL__NO_ABORT_CG                             0x80000000L

// RBBM_SOFT_RESET
#define RBBM_SOFT_RESET__SOFT_RESET_CP_MASK                0x00000001L
#define RBBM_SOFT_RESET__SOFT_RESET_CP                     0x00000001L
#define RBBM_SOFT_RESET__SOFT_RESET_HI_MASK                0x00000002L
#define RBBM_SOFT_RESET__SOFT_RESET_HI                     0x00000002L
#define RBBM_SOFT_RESET__SOFT_RESET_VAP_MASK               0x00000004L
#define RBBM_SOFT_RESET__SOFT_RESET_VAP                    0x00000004L
#define RBBM_SOFT_RESET__SOFT_RESET_RE_MASK                0x00000008L
#define RBBM_SOFT_RESET__SOFT_RESET_RE                     0x00000008L
#define RBBM_SOFT_RESET__SOFT_RESET_PP_MASK                0x00000010L
#define RBBM_SOFT_RESET__SOFT_RESET_PP                     0x00000010L
#define RBBM_SOFT_RESET__SOFT_RESET_E2_MASK                0x00000020L
#define RBBM_SOFT_RESET__SOFT_RESET_E2                     0x00000020L
#define RBBM_SOFT_RESET__SOFT_RESET_RB_MASK                0x00000040L
#define RBBM_SOFT_RESET__SOFT_RESET_RB                     0x00000040L
#define RBBM_SOFT_RESET__SOFT_RESET_HDP_MASK               0x00000080L
#define RBBM_SOFT_RESET__SOFT_RESET_HDP                    0x00000080L
#define RBBM_SOFT_RESET__SOFT_RESET_MC_MASK                0x00000100L
#define RBBM_SOFT_RESET__SOFT_RESET_MC                     0x00000100L
#define RBBM_SOFT_RESET__SOFT_RESET_AIC_MASK               0x00000200L
#define RBBM_SOFT_RESET__SOFT_RESET_AIC                    0x00000200L
#define RBBM_SOFT_RESET__SOFT_RESET_VIP_MASK               0x00000400L
#define RBBM_SOFT_RESET__SOFT_RESET_VIP                    0x00000400L
#define RBBM_SOFT_RESET__SOFT_RESET_DISP_MASK              0x00000800L
#define RBBM_SOFT_RESET__SOFT_RESET_DISP                   0x00000800L
#define RBBM_SOFT_RESET__SOFT_RESET_CG_MASK                0x00001000L
#define RBBM_SOFT_RESET__SOFT_RESET_CG                     0x00001000L

// NQWAIT_UNTIL
#define NQWAIT_UNTIL__WAIT_GUI_IDLE_MASK                   0x00000001L
#define NQWAIT_UNTIL__WAIT_GUI_IDLE                        0x00000001L

// RBBM_DEBUG
#define RBBM_DEBUG__RBBM_DEBUG_R2_MASK                     0xffffffffL

// RBBM_CMDFIFO_ADDR
#define RBBM_CMDFIFO_ADDR__CMDFIFO_ADDR_MASK               0x0000003fL

// RBBM_CMDFIFO_DATAL
#define RBBM_CMDFIFO_DATAL__CMDFIFO_DATAL_MASK             0xffffffffL

// RBBM_CMDFIFO_DATAH
#define RBBM_CMDFIFO_DATAH__CMDFIFO_DATAH_MASK             0x00000fffL

// RBBM_CMDFIFO_STAT
#define RBBM_CMDFIFO_STAT__CMDFIFO_RPTR_MASK               0x0000003fL
#define RBBM_CMDFIFO_STAT__CMDFIFO_WPTR_MASK               0x00003f00L

// RBBM_PERF_CNTL
#define RBBM_PERF_CNTL__PERFSEL1_MASK                      0x0000000fL
#define RBBM_PERF_CNTL__CLR_PERF1_MASK                     0x00000040L
#define RBBM_PERF_CNTL__CLR_PERF1                          0x00000040L
#define RBBM_PERF_CNTL__EN_PERF1_MASK                      0x00000080L
#define RBBM_PERF_CNTL__EN_PERF1                           0x00000080L
#define RBBM_PERF_CNTL__PERFSEL2_MASK                      0x00000f00L
#define RBBM_PERF_CNTL__CLR_PERF2_MASK                     0x00004000L
#define RBBM_PERF_CNTL__CLR_PERF2                          0x00004000L
#define RBBM_PERF_CNTL__EN_PERF2_MASK                      0x00008000L
#define RBBM_PERF_CNTL__EN_PERF2                           0x00008000L
#define RBBM_PERF_CNTL__SYNC_SEL_MASK                      0x80000000L
#define RBBM_PERF_CNTL__SYNC_SEL                           0x80000000L

// RBBM_PERF_COUNT1
#define RBBM_PERF_COUNT1__PERF_COUNT1_MASK                 0xffffffffL

// RBBM_PERF_COUNT2
#define RBBM_PERF_COUNT2__PERF_COUNT2_MASK                 0xffffffffL

// GENFC_RD
#define GENFC_RD__VSYNC_SEL_R_MASK                         0x00000008L
#define GENFC_RD__VSYNC_SEL_R                              0x00000008L

// GENFC_WT
#define GENFC_WT__VSYNC_SEL_W_MASK                         0x00000008L
#define GENFC_WT__VSYNC_SEL_W                              0x00000008L

// GENS0
#define GENS0__SENSE_SWITCH_MASK                           0x00000010L
#define GENS0__SENSE_SWITCH                                0x00000010L
#define GENS0__CRT_INTR_MASK                               0x00000080L
#define GENS0__CRT_INTR                                    0x00000080L

// GENS1
#define GENS1__NO_DIPLAY_MASK                              0x00000001L
#define GENS1__NO_DIPLAY                                   0x00000001L
#define GENS1__VGA_VSTATUS_MASK                            0x00000008L
#define GENS1__VGA_VSTATUS                                 0x00000008L
#define GENS1__PIXEL_READ_BACK_MASK                        0x00000030L

// DAC_DATA
#define DAC_DATA__DAC_DATA_MASK                            0x000000ffL

// DAC_MASK
#define DAC_MASK__DAC_MASK_MASK                            0x000000ffL

// DAC_R_INDEX
#define DAC_R_INDEX__DAC_R_INDEX_MASK                      0x000000ffL

// DAC_W_INDEX
#define DAC_W_INDEX__DAC_W_INDEX_MASK                      0x000000ffL

// SEQ00
#define SEQ00__SEQ_RST0B_MASK                              0x00000001L
#define SEQ00__SEQ_RST0B                                   0x00000001L
#define SEQ00__SEQ_RST1B_MASK                              0x00000002L
#define SEQ00__SEQ_RST1B                                   0x00000002L

// SEQ01
#define SEQ01__SEQ_DOT8_MASK                               0x00000001L
#define SEQ01__SEQ_DOT8                                    0x00000001L
#define SEQ01__SEQ_SHIFT2_MASK                             0x00000004L
#define SEQ01__SEQ_SHIFT2                                  0x00000004L
#define SEQ01__SEQ_PCLKBY2_MASK                            0x00000008L
#define SEQ01__SEQ_PCLKBY2                                 0x00000008L
#define SEQ01__SEQ_SHIFT4_MASK                             0x00000010L
#define SEQ01__SEQ_SHIFT4                                  0x00000010L
#define SEQ01__SEQ_MAXBW_MASK                              0x00000020L
#define SEQ01__SEQ_MAXBW                                   0x00000020L

// SEQ03
#define SEQ03__SEQ_FONT_B1_MASK                            0x00000001L
#define SEQ03__SEQ_FONT_B1                                 0x00000001L
#define SEQ03__SEQ_FONT_B2_MASK                            0x00000002L
#define SEQ03__SEQ_FONT_B2                                 0x00000002L
#define SEQ03__SEQ_FONT_A1_MASK                            0x00000004L
#define SEQ03__SEQ_FONT_A1                                 0x00000004L
#define SEQ03__SEQ_FONT_A2_MASK                            0x00000008L
#define SEQ03__SEQ_FONT_A2                                 0x00000008L
#define SEQ03__SEQ_FONT_B0_MASK                            0x00000010L
#define SEQ03__SEQ_FONT_B0                                 0x00000010L
#define SEQ03__SEQ_FONT_A0_MASK                            0x00000020L
#define SEQ03__SEQ_FONT_A0                                 0x00000020L

// CRT00
#define CRT00__H_TOTAL_MASK                                0x000000ffL

// CRT01
#define CRT01__H_DISP_END_MASK                             0x000000ffL

// CRT02
#define CRT02__H_BLANK_START_MASK                          0x000000ffL

// CRT03
#define CRT03__H_BLANK_END_MASK                            0x0000001fL
#define CRT03__H_DE_SKEW_MASK                              0x00000060L
#define CRT03__CR10CR11_R_DIS_B_MASK                       0x00000080L
#define CRT03__CR10CR11_R_DIS_B                            0x00000080L

// CRT04
#define CRT04__H_SYNC_START_MASK                           0x000000ffL

// CRT05
#define CRT05__H_SYNC_END_MASK                             0x0000001fL
#define CRT05__H_SYNC_SKEW_MASK                            0x00000060L
#define CRT05__H_BLANK_END_B5_MASK                         0x00000080L
#define CRT05__H_BLANK_END_B5                              0x00000080L

// CRT06
#define CRT06__V_TOTAL_MASK                                0x000000ffL

// CRT07
#define CRT07__V_TOTAL_B8_MASK                             0x00000001L
#define CRT07__V_TOTAL_B8                                  0x00000001L
#define CRT07__V_DISP_END_B8_MASK                          0x00000002L
#define CRT07__V_DISP_END_B8                               0x00000002L
#define CRT07__V_SYNC_START_B8_MASK                        0x00000004L
#define CRT07__V_SYNC_START_B8                             0x00000004L
#define CRT07__V_BLANK_START_B8_MASK                       0x00000008L
#define CRT07__V_BLANK_START_B8                            0x00000008L
#define CRT07__LINE_CMP_B8_MASK                            0x00000010L
#define CRT07__LINE_CMP_B8                                 0x00000010L
#define CRT07__V_TOTAL_B9_MASK                             0x00000020L
#define CRT07__V_TOTAL_B9                                  0x00000020L
#define CRT07__V_DISP_END_B9_MASK                          0x00000040L
#define CRT07__V_DISP_END_B9                               0x00000040L
#define CRT07__V_SYNC_START_B9_MASK                        0x00000080L
#define CRT07__V_SYNC_START_B9                             0x00000080L

// CRT08
#define CRT08__ROW_SCAN_START_MASK                         0x0000001fL
#define CRT08__BYTE_PAN_MASK                               0x00000060L

// CRT09
#define CRT09__MAX_ROW_SCAN_MASK                           0x0000001fL
#define CRT09__V_BLANK_START_B9_MASK                       0x00000020L
#define CRT09__V_BLANK_START_B9                            0x00000020L
#define CRT09__LINE_CMP_B9_MASK                            0x00000040L
#define CRT09__LINE_CMP_B9                                 0x00000040L
#define CRT09__DOUBLE_CHAR_HEIGHT_MASK                     0x00000080L
#define CRT09__DOUBLE_CHAR_HEIGHT                          0x00000080L

// CRT0A
#define CRT0A__CURSOR_START_MASK                           0x0000001fL
#define CRT0A__CURSOR_DISABLE_MASK                         0x00000020L
#define CRT0A__CURSOR_DISABLE                              0x00000020L

// CRT0B
#define CRT0B__CURSOR_END_MASK                             0x0000001fL
#define CRT0B__CURSOR_SKEW_MASK                            0x00000060L

// CRT0C
#define CRT0C__DISP_START_MASK                             0x000000ffL

// CRT0D
#define CRT0D__DISP_START_MASK                             0x000000ffL

// CRT0E
#define CRT0E__CURSOR_LOC_HI_MASK                          0x000000ffL

// CRT0F
#define CRT0F__CURSOR_LOC_LO_MASK                          0x000000ffL

// CRT10
#define CRT10__V_SYNC_START_MASK                           0x000000ffL

// CRT11
#define CRT11__V_SYNC_END_MASK                             0x0000000fL
#define CRT11__V_INTR_CLR_MASK                             0x00000010L
#define CRT11__V_INTR_CLR                                  0x00000010L
#define CRT11__V_INTR_EN_MASK                              0x00000020L
#define CRT11__V_INTR_EN                                   0x00000020L
#define CRT11__SEL5_REFRESH_CYC_MASK                       0x00000040L
#define CRT11__SEL5_REFRESH_CYC                            0x00000040L
#define CRT11__C0T7_WR_ONLY_MASK                           0x00000080L
#define CRT11__C0T7_WR_ONLY                                0x00000080L

// CRT12
#define CRT12__V_DISP_END_MASK                             0x000000ffL

// CRT13
#define CRT13__DISP_PITCH_MASK                             0x000000ffL

// CRT15
#define CRT15__V_BLANK_START_MASK                          0x000000ffL

// CRT16
#define CRT16__V_BLANK_END_MASK                            0x000000ffL

// CRT18
#define CRT18__LINE_CMP_MASK                               0x000000ffL

// CRT00_S
#define CRT00_S__H_TOTAL_S_MASK                            0x000000ffL

// CRT01_S
#define CRT01_S__H_DISP_END_S_MASK                         0x000000ffL

// CRT02_S
#define CRT02_S__H_BLANK_START_S_MASK                      0x000000ffL

// CRT03_S
#define CRT03_S__H_BLANK_END_S_MASK                        0x0000001fL
#define CRT03_S__H_DE_SKEW_S_MASK                          0x00000060L
#define CRT03_S__CR10CR11_R_DIS_B_M_MASK                   0x00000080L
#define CRT03_S__CR10CR11_R_DIS_B_M                        0x00000080L

// CRT04_S
#define CRT04_S__H_SYNC_START_S_MASK                       0x000000ffL

// CRT05_S
#define CRT05_S__H_SYNC_END_S_MASK                         0x0000001fL
#define CRT05_S__H_SYNC_SKEW_S_MASK                        0x00000060L
#define CRT05_S__H_BLANK_END_B5_S_MASK                     0x00000080L
#define CRT05_S__H_BLANK_END_B5_S                          0x00000080L

// CRT06_S
#define CRT06_S__V_TOTAL_S_MASK                            0x000000ffL

// CRT07_S
#define CRT07_S__V_TOTAL_B8_S_MASK                         0x00000001L
#define CRT07_S__V_TOTAL_B8_S                              0x00000001L
#define CRT07_S__V_DISP_END_B8_S_MASK                      0x00000002L
#define CRT07_S__V_DISP_END_B8_S                           0x00000002L
#define CRT07_S__V_SYNC_START_B8_S_MASK                    0x00000004L
#define CRT07_S__V_SYNC_START_B8_S                         0x00000004L
#define CRT07_S__V_BLANK_START_B8_S_MASK                   0x00000008L
#define CRT07_S__V_BLANK_START_B8_S                        0x00000008L
#define CRT07_S__LINE_CMP_B8_M_MASK                        0x00000010L
#define CRT07_S__LINE_CMP_B8_M                             0x00000010L
#define CRT07_S__V_TOTAL_B9_S_MASK                         0x00000020L
#define CRT07_S__V_TOTAL_B9_S                              0x00000020L
#define CRT07_S__V_DISP_END_B9_S_MASK                      0x00000040L
#define CRT07_S__V_DISP_END_B9_S                           0x00000040L
#define CRT07_S__V_SYNC_START_B9_S_MASK                    0x00000080L
#define CRT07_S__V_SYNC_START_B9_S                         0x00000080L

// CRT08_S
#define CRT08_S__ROW_SCAN_START_M_MASK                     0x0000001fL
#define CRT08_S__BYTE_PAN_M_MASK                           0x00000060L

// CRT09_S
#define CRT09_S__MAX_ROW_SCAN_S_MASK                       0x0000001fL
#define CRT09_S__V_BLANK_START_B9_S_MASK                   0x00000020L
#define CRT09_S__V_BLANK_START_B9_S                        0x00000020L
#define CRT09_S__LINE_CMP_B9_M_MASK                        0x00000040L
#define CRT09_S__LINE_CMP_B9_M                             0x00000040L
#define CRT09_S__DOUBLE_CHAR_HEIGHT_M_MASK                 0x00000080L
#define CRT09_S__DOUBLE_CHAR_HEIGHT_M                      0x00000080L

// CRT0A_S
#define CRT0A_S__CURSOR_START_S_MASK                       0x0000001fL
#define CRT0A_S__CURSOR_DISABLE_M_MASK                     0x00000020L
#define CRT0A_S__CURSOR_DISABLE_M                          0x00000020L

// CRT0B_S
#define CRT0B_S__CURSOR_END_S_MASK                         0x0000001fL
#define CRT0B_S__CURSOR_SKEW_M_MASK                        0x00000060L

// CRT0C_S
#define CRT0C_S__DISP_START_M_MASK                         0x000000ffL

// CRT0D_S
#define CRT0D_S__DISP_START_M_MASK                         0x000000ffL

// CRT0E_S
#define CRT0E_S__CURSOR_LOC_HI_M_MASK                      0x000000ffL

// CRT0F_S
#define CRT0F_S__CURSOR_LOC_LO_M_MASK                      0x000000ffL

// CRT10_S
#define CRT10_S__V_SYNC_START_S_MASK                       0x000000ffL

// CRT11_S
#define CRT11_S__V_SYNC_END_S_MASK                         0x0000000fL
#define CRT11_S__V_INTR_CLR_M_MASK                         0x00000010L
#define CRT11_S__V_INTR_CLR_M                              0x00000010L
#define CRT11_S__V_INTR_EN_M_MASK                          0x00000020L
#define CRT11_S__V_INTR_EN_M                               0x00000020L
#define CRT11_S__SEL5_REFRESH_CYC_M_MASK                   0x00000040L
#define CRT11_S__SEL5_REFRESH_CYC_M                        0x00000040L
#define CRT11_S__C0T7_WR_ONLY_M_MASK                       0x00000080L
#define CRT11_S__C0T7_WR_ONLY_M                            0x00000080L

// CRT12_S
#define CRT12_S__V_DISP_END_S_MASK                         0x000000ffL

// CRT13_S
#define CRT13_S__DISP_PITCH_M_MASK                         0x000000ffL

// CRT15_S
#define CRT15_S__V_BLANK_START_S_MASK                      0x000000ffL

// CRT16_S
#define CRT16_S__V_BLANK_END_S_MASK                        0x000000ffL

// CRT18_S
#define CRT18_S__LINE_CMP_M_MASK                           0x000000ffL

// ATTRX
#define ATTRX__ATTR_IDX_MASK                               0x0000001fL
#define ATTRX__ATTR_PAL_RW_ENB_MASK                        0x00000020L
#define ATTRX__ATTR_PAL_RW_ENB                             0x00000020L

// ATTRDW
#define ATTRDW__ATTR_DATA_MASK                             0x000000ffL

// ATTRDR
#define ATTRDR__ATTR_DATA_MASK                             0x000000ffL

// ATTR00
#define ATTR00__ATTR_PAL_MASK                              0x0000003fL

// ATTR01
#define ATTR01__ATTR_PAL_MASK                              0x0000003fL

// ATTR02
#define ATTR02__ATTR_PAL_MASK                              0x0000003fL

// ATTR03
#define ATTR03__ATTR_PAL_MASK                              0x0000003fL

// ATTR04
#define ATTR04__ATTR_PAL_MASK                              0x0000003fL

// ATTR05
#define ATTR05__ATTR_PAL_MASK                              0x0000003fL

// ATTR06
#define ATTR06__ATTR_PAL_MASK                              0x0000003fL

// ATTR07
#define ATTR07__ATTR_PAL_MASK                              0x0000003fL

// ATTR08
#define ATTR08__ATTR_PAL_MASK                              0x0000003fL

// ATTR09
#define ATTR09__ATTR_PAL_MASK                              0x0000003fL

// ATTR0A
#define ATTR0A__ATTR_PAL_MASK                              0x0000003fL

// ATTR0B
#define ATTR0B__ATTR_PAL_MASK                              0x0000003fL

// ATTR0C
#define ATTR0C__ATTR_PAL_MASK                              0x0000003fL

// ATTR0D
#define ATTR0D__ATTR_PAL_MASK                              0x0000003fL

// ATTR0E
#define ATTR0E__ATTR_PAL_MASK                              0x0000003fL

// ATTR0F
#define ATTR0F__ATTR_PAL_MASK                              0x0000003fL

// ATTR10
#define ATTR10__ATTR_GRPH_MODE_MASK                        0x00000001L
#define ATTR10__ATTR_GRPH_MODE                             0x00000001L
#define ATTR10__ATTR_MONO_EN_MASK                          0x00000002L
#define ATTR10__ATTR_MONO_EN                               0x00000002L
#define ATTR10__ATTR_LGRPH_EN_MASK                         0x00000004L
#define ATTR10__ATTR_LGRPH_EN                              0x00000004L
#define ATTR10__ATTR_BLINK_EN_MASK                         0x00000008L
#define ATTR10__ATTR_BLINK_EN                              0x00000008L
#define ATTR10__ATTR_PANTOPONLY_MASK                       0x00000020L
#define ATTR10__ATTR_PANTOPONLY                            0x00000020L
#define ATTR10__ATTR_PCLKBY2_MASK                          0x00000040L
#define ATTR10__ATTR_PCLKBY2                               0x00000040L
#define ATTR10__ATTR_CSEL_EN_MASK                          0x00000080L
#define ATTR10__ATTR_CSEL_EN                               0x00000080L

// ATTR11
#define ATTR11__ATTR_OVSC_MASK                             0x000000ffL

// ATTR12
#define ATTR12__ATTR_MAP_EN_MASK                           0x0000000fL
#define ATTR12__ATTR_VSMUX_MASK                            0x00000030L

// ATTR13
#define ATTR13__ATTR_PPAN_MASK                             0x0000000fL

// ATTR14
#define ATTR14__ATTR_CSEL1_MASK                            0x00000003L
#define ATTR14__ATTR_CSEL2_MASK                            0x0000000cL

// VCLK_ECP_CNTL
#define VCLK_ECP_CNTL__VCLK_SRC_SEL_MASK                   0x00000003L
#define VCLK_ECP_CNTL__VCLK_INVERT_MASK                    0x00000010L
#define VCLK_ECP_CNTL__VCLK_INVERT                         0x00000010L
#define VCLK_ECP_CNTL__PIXCLK_SRC_INVERT_MASK              0x00000020L
#define VCLK_ECP_CNTL__PIXCLK_SRC_INVERT                   0x00000020L
#define VCLK_ECP_CNTL__PIXCLK_ALWAYS_ONb_MASK              0x00000040L
#define VCLK_ECP_CNTL__PIXCLK_ALWAYS_ONb                   0x00000040L
#define VCLK_ECP_CNTL__PIXCLK_DAC_ALWAYS_ONb_MASK          0x00000080L
#define VCLK_ECP_CNTL__PIXCLK_DAC_ALWAYS_ONb               0x00000080L
#define VCLK_ECP_CNTL__ECP_DIV_MASK                        0x00000300L
#define VCLK_ECP_CNTL__ECP_FORCE_ON_MASK                   0x00040000L
#define VCLK_ECP_CNTL__ECP_FORCE_ON                        0x00040000L
#define VCLK_ECP_CNTL__SUBCLK_FORCE_ON_MASK                0x00080000L
#define VCLK_ECP_CNTL__SUBCLK_FORCE_ON                     0x00080000L

// DISP_TEST_MACRO_RW_WRITE
#define DISP_TEST_MACRO_RW_WRITE__TEST_MACRO_RW_WRITE1_MASK 0x00003fffL
#define DISP_TEST_MACRO_RW_WRITE__TEST_MACRO_RW_WRITE2_MASK 0x0fffc000L

// DISP_TEST_MACRO_RW_READ
#define DISP_TEST_MACRO_RW_READ__TEST_MACRO_RW_READ1_MASK  0x0000ffffL
#define DISP_TEST_MACRO_RW_READ__TEST_MACRO_RW_READ2_MASK  0xffff0000L

// DISP_TEST_MACRO_RW_DATA
#define DISP_TEST_MACRO_RW_DATA__TEST_MACRO_RW_DATA_MASK   0xffffffffL

// DISP_TEST_MACRO_RW_CNTL
#define DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_START_MASK  0x00000001L
#define DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_START       0x00000001L
#define DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_OP_MASK     0x0000000eL
#define DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_MODE_MASK   0x00000030L
#define DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_MISMATCH_SEL_MASK 0x00007fc0L
#define DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_MISMATCH_MASK 0x00008000L
#define DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_MISMATCH    0x00008000L
#define DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_ENABLE_MASK 0x00010000L
#define DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_ENABLE      0x00010000L
#define DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_SCLK_NEG_ENABLE_MASK 0x00020000L
#define DISP_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_SCLK_NEG_ENABLE 0x00020000L

// PIXCLKS_CNTL
#define PIXCLKS_CNTL__PIX2CLK_SRC_SEL_MASK                 0x00000003L
#define PIXCLKS_CNTL__PIX2CLK_INVERT_MASK                  0x00000010L
#define PIXCLKS_CNTL__PIX2CLK_INVERT                       0x00000010L
#define PIXCLKS_CNTL__PIX2CLK_SRC_INVERT_MASK              0x00000020L
#define PIXCLKS_CNTL__PIX2CLK_SRC_INVERT                   0x00000020L
#define PIXCLKS_CNTL__PIX2CLK_ALWAYS_ONb_MASK              0x00000040L
#define PIXCLKS_CNTL__PIX2CLK_ALWAYS_ONb                   0x00000040L
#define PIXCLKS_CNTL__PIX2CLK_DAC_ALWAYS_ONb_MASK          0x00000080L
#define PIXCLKS_CNTL__PIX2CLK_DAC_ALWAYS_ONb               0x00000080L
#define PIXCLKS_CNTL__PIXCLK_TV_SRC_SEL_MASK               0x00000100L
#define PIXCLKS_CNTL__PIXCLK_TV_SRC_SEL                    0x00000100L
#define PIXCLKS_CNTL__PIXCLK_BLEND_ALWAYS_ONb_MASK         0x00000800L
#define PIXCLKS_CNTL__PIXCLK_BLEND_ALWAYS_ONb              0x00000800L
#define PIXCLKS_CNTL__PIXCLK_GV_ALWAYS_ONb_MASK            0x00001000L
#define PIXCLKS_CNTL__PIXCLK_GV_ALWAYS_ONb                 0x00001000L
#define PIXCLKS_CNTL__PIXCLK_DIG_TMDS_ALWAYS_ONb_MASK      0x00002000L
#define PIXCLKS_CNTL__PIXCLK_DIG_TMDS_ALWAYS_ONb           0x00002000L
#define PIXCLKS_CNTL__PIXCLK_LVDS_ALWAYS_ONb_MASK          0x00004000L
#define PIXCLKS_CNTL__PIXCLK_LVDS_ALWAYS_ONb               0x00004000L
#define PIXCLKS_CNTL__PIXCLK_TMDS_ALWAYS_ONb_MASK          0x00008000L
#define PIXCLKS_CNTL__PIXCLK_TMDS_ALWAYS_ONb               0x00008000L

// CRTC_STATUS
#define CRTC_STATUS__CRTC_VBLANK_CUR_MASK                  0x00000001L
#define CRTC_STATUS__CRTC_VBLANK_CUR                       0x00000001L
#define CRTC_STATUS__CRTC_VBLANK_SAVE_MASK                 0x00000002L
#define CRTC_STATUS__CRTC_VBLANK_SAVE                      0x00000002L
#define CRTC_STATUS__CRTC_VBLANK_SAVE_CLEAR_MASK           0x00000002L
#define CRTC_STATUS__CRTC_VBLANK_SAVE_CLEAR                0x00000002L
#define CRTC_STATUS__CRTC_VLINE_SYNC_MASK                  0x00000004L
#define CRTC_STATUS__CRTC_VLINE_SYNC                       0x00000004L
#define CRTC_STATUS__CRTC_FRAME_MASK                       0x00000008L
#define CRTC_STATUS__CRTC_FRAME                            0x00000008L

// GPIO_VGA_DDC
#define GPIO_VGA_DDC__VGA_DCC_DATA_OUTPUT_MASK             0x00000001L
#define GPIO_VGA_DDC__VGA_DCC_DATA_OUTPUT                  0x00000001L
#define GPIO_VGA_DDC__VGA_DDC_CLK_OUTPUT_MASK              0x00000002L
#define GPIO_VGA_DDC__VGA_DDC_CLK_OUTPUT                   0x00000002L
#define GPIO_VGA_DDC__VGA_DDC_DATA_INPUT_MASK              0x00000100L
#define GPIO_VGA_DDC__VGA_DDC_DATA_INPUT                   0x00000100L
#define GPIO_VGA_DDC__VGA_DDC_CLK_INPUT_MASK               0x00000200L
#define GPIO_VGA_DDC__VGA_DDC_CLK_INPUT                    0x00000200L
#define GPIO_VGA_DDC__VGA_DDC_DATA_OUT_EN_MASK             0x00010000L
#define GPIO_VGA_DDC__VGA_DDC_DATA_OUT_EN                  0x00010000L
#define GPIO_VGA_DDC__VGA_DDC_CLK_OUT_EN_MASK              0x00020000L
#define GPIO_VGA_DDC__VGA_DDC_CLK_OUT_EN                   0x00020000L

// GPIO_DVI_DDC
#define GPIO_DVI_DDC__DVI_DDC_DATA_OUTPUT_MASK             0x00000001L
#define GPIO_DVI_DDC__DVI_DDC_DATA_OUTPUT                  0x00000001L
#define GPIO_DVI_DDC__DVI_DDC_CLK_OUTPUT_MASK              0x00000002L
#define GPIO_DVI_DDC__DVI_DDC_CLK_OUTPUT                   0x00000002L
#define GPIO_DVI_DDC__DVI_DDC_DATA_INPUT_MASK              0x00000100L
#define GPIO_DVI_DDC__DVI_DDC_DATA_INPUT                   0x00000100L
#define GPIO_DVI_DDC__DVI_DDC_CLK_INPUT_MASK               0x00000200L
#define GPIO_DVI_DDC__DVI_DDC_CLK_INPUT                    0x00000200L
#define GPIO_DVI_DDC__DVI_DDC_DATA_OUT_EN_MASK             0x00010000L
#define GPIO_DVI_DDC__DVI_DDC_DATA_OUT_EN                  0x00010000L
#define GPIO_DVI_DDC__DVI_DDC_CLK_OUT_EN_MASK              0x00020000L
#define GPIO_DVI_DDC__DVI_DDC_CLK_OUT_EN                   0x00020000L
#define GPIO_DVI_DDC__SW_WANTS_TO_USE_DVI_I2C_MASK         0x00100000L
#define GPIO_DVI_DDC__SW_WANTS_TO_USE_DVI_I2C              0x00100000L
#define GPIO_DVI_DDC__SW_CAN_USE_DVI_I2C_MASK              0x00100000L
#define GPIO_DVI_DDC__SW_CAN_USE_DVI_I2C                   0x00100000L
#define GPIO_DVI_DDC__SW_DONE_USING_DVI_I2C_MASK           0x00200000L
#define GPIO_DVI_DDC__SW_DONE_USING_DVI_I2C                0x00200000L
#define GPIO_DVI_DDC__HDCP_NEEDS_DVI_I2C_MASK              0x00200000L
#define GPIO_DVI_DDC__HDCP_NEEDS_DVI_I2C                   0x00200000L
#define GPIO_DVI_DDC__ABORT_HDCP_DVI_I2C_MASK              0x00400000L
#define GPIO_DVI_DDC__ABORT_HDCP_DVI_I2C                   0x00400000L
#define GPIO_DVI_DDC__HW_USING_DVI_I2C_MASK                0x00400000L
#define GPIO_DVI_DDC__HW_USING_DVI_I2C                     0x00400000L

// GPIO_MONID
#define GPIO_MONID__GPIO_MONID_0_OUTPUT_MASK               0x00000001L
#define GPIO_MONID__GPIO_MONID_0_OUTPUT                    0x00000001L
#define GPIO_MONID__GPIO_MONID_1_OUTPUT_MASK               0x00000002L
#define GPIO_MONID__GPIO_MONID_1_OUTPUT                    0x00000002L
#define GPIO_MONID__GPIO_MONID_0_INPUT_MASK                0x00000100L
#define GPIO_MONID__GPIO_MONID_0_INPUT                     0x00000100L
#define GPIO_MONID__GPIO_MONID_1_INPUT_MASK                0x00000200L
#define GPIO_MONID__GPIO_MONID_1_INPUT                     0x00000200L
#define GPIO_MONID__GPIO_MONID_0_OUT_EN_MASK               0x00010000L
#define GPIO_MONID__GPIO_MONID_0_OUT_EN                    0x00010000L
#define GPIO_MONID__GPIO_MONID_1_OUT_EN_MASK               0x00020000L
#define GPIO_MONID__GPIO_MONID_1_OUT_EN                    0x00020000L

// GPIO_CRT2_DDC
#define GPIO_CRT2_DDC__CRT2_DDC_DATA_OUTPUT_MASK           0x00000001L
#define GPIO_CRT2_DDC__CRT2_DDC_DATA_OUTPUT                0x00000001L
#define GPIO_CRT2_DDC__CRT2_DDC_CLK_OUTPUT_MASK            0x00000002L
#define GPIO_CRT2_DDC__CRT2_DDC_CLK_OUTPUT                 0x00000002L
#define GPIO_CRT2_DDC__CRT2_DDC_DATA_INPUT_MASK            0x00000100L
#define GPIO_CRT2_DDC__CRT2_DDC_DATA_INPUT                 0x00000100L
#define GPIO_CRT2_DDC__CRT2_DDC_CLK_INPUT_MASK             0x00000200L
#define GPIO_CRT2_DDC__CRT2_DDC_CLK_INPUT                  0x00000200L
#define GPIO_CRT2_DDC__CRT2_DDC_DATA_OUT_EN_MASK           0x00010000L
#define GPIO_CRT2_DDC__CRT2_DDC_DATA_OUT_EN                0x00010000L
#define GPIO_CRT2_DDC__CRT2_DDC_CLK_OUT_EN_MASK            0x00020000L
#define GPIO_CRT2_DDC__CRT2_DDC_CLK_OUT_EN                 0x00020000L

// PALETTE_INDEX
#define PALETTE_INDEX__PALETTE_W_INDEX_MASK                0x000000ffL
#define PALETTE_INDEX__PALETTE_R_INDEX_MASK                0x00ff0000L

// PALETTE_DATA
#define PALETTE_DATA__PALETTE_DATA_B_MASK                  0x000000ffL
#define PALETTE_DATA__PALETTE_DATA_G_MASK                  0x0000ff00L
#define PALETTE_DATA__PALETTE_DATA_R_MASK                  0x00ff0000L

// PALETTE_30_DATA
#define PALETTE_30_DATA__PALETTE_DATA_B_MASK               0x000003ffL
#define PALETTE_30_DATA__PALETTE_DATA_G_MASK               0x000ffc00L
#define PALETTE_30_DATA__PALETTE_DATA_R_MASK               0x3ff00000L

// CRTC_H_TOTAL_DISP
#define CRTC_H_TOTAL_DISP__CRTC_H_TOTAL_MASK               0x000003ffL
#define CRTC_H_TOTAL_DISP__CRTC_H_DISP_MASK                0x01ff0000L

// CRTC_H_SYNC_STRT_WID
#define CRTC_H_SYNC_STRT_WID__CRTC_H_SYNC_STRT_PIX_MASK    0x00000007L
#define CRTC_H_SYNC_STRT_WID__CRTC_H_SYNC_STRT_CHAR_MASK   0x00001ff8L
#define CRTC_H_SYNC_STRT_WID__CRTC_H_SYNC_WID_MASK         0x003f0000L
#define CRTC_H_SYNC_STRT_WID__CRTC_H_SYNC_POL_MASK         0x00800000L
#define CRTC_H_SYNC_STRT_WID__CRTC_H_SYNC_POL              0x00800000L
#define CRTC_H_SYNC_STRT_WID__CRTC_H_SYNC_SKEW_TUNE_MASK   0x07000000L
#define CRTC_H_SYNC_STRT_WID__CRTC_H_SYNC_SKEW_TUNE_MODE_MASK 0x10000000L
#define CRTC_H_SYNC_STRT_WID__CRTC_H_SYNC_SKEW_TUNE_MODE   0x10000000L

// CRTC_V_TOTAL_DISP
#define CRTC_V_TOTAL_DISP__CRTC_V_TOTAL_MASK               0x00000fffL
#define CRTC_V_TOTAL_DISP__CRTC_V_DISP_MASK                0x0fff0000L

// CRTC_V_SYNC_STRT_WID
#define CRTC_V_SYNC_STRT_WID__CRTC_V_SYNC_STRT_MASK        0x00000fffL
#define CRTC_V_SYNC_STRT_WID__CRTC_V_SYNC_WID_MASK         0x001f0000L
#define CRTC_V_SYNC_STRT_WID__CRTC_V_SYNC_POL_MASK         0x00800000L
#define CRTC_V_SYNC_STRT_WID__CRTC_V_SYNC_POL              0x00800000L

// CRTC_VLINE_CRNT_VLINE
#define CRTC_VLINE_CRNT_VLINE__CRTC_VLINE_MASK             0x00000fffL
#define CRTC_VLINE_CRNT_VLINE__CRTC_CRNT_VLINE_MASK        0x0fff0000L

// CRTC_CRNT_FRAME
#define CRTC_CRNT_FRAME__CRTC_CRNT_FRAME_MASK              0x001fffffL

// CRTC_GUI_TRIG_VLINE
#define CRTC_GUI_TRIG_VLINE__CRTC_GUI_TRIG_VLINE_START_MASK 0x00000fffL
#define CRTC_GUI_TRIG_VLINE__CRTC_GUI_TRIG_VLINE_INV_MASK  0x00008000L
#define CRTC_GUI_TRIG_VLINE__CRTC_GUI_TRIG_VLINE_INV       0x00008000L
#define CRTC_GUI_TRIG_VLINE__CRTC_GUI_TRIG_VLINE_END_MASK  0x0fff0000L
#define CRTC_GUI_TRIG_VLINE__CRTC_GUI_TRIG_VLINE_STALL_MASK 0x40000000L
#define CRTC_GUI_TRIG_VLINE__CRTC_GUI_TRIG_VLINE_STALL     0x40000000L
#define CRTC_GUI_TRIG_VLINE__CRTC_GUI_TRIG_VLINE_MASK      0x80000000L
#define CRTC_GUI_TRIG_VLINE__CRTC_GUI_TRIG_VLINE           0x80000000L

// CRTC_DEBUG
#define CRTC_DEBUG__CRTC_GUI_TRIG_BYPASS_EN_MASK           0x00000001L
#define CRTC_DEBUG__CRTC_GUI_TRIG_BYPASS_EN                0x00000001L
#define CRTC_DEBUG__GUI_TRIG_VLINE_BYPASS_MASK             0x00000002L
#define CRTC_DEBUG__GUI_TRIG_VLINE_BYPASS                  0x00000002L
#define CRTC_DEBUG__GUI_TRIG_OFFSET_BYPASS_MASK            0x00000004L
#define CRTC_DEBUG__GUI_TRIG_OFFSET_BYPASS                 0x00000004L
#define CRTC_DEBUG__GUI_TRIG_PITCH_ADD_BYPASS_MASK         0x00000008L
#define CRTC_DEBUG__GUI_TRIG_PITCH_ADD_BYPASS              0x00000008L

// CRTC_OFFSET_RIGHT
#define CRTC_OFFSET_RIGHT__CRTC_OFFSET_RIGHT_MASK          0x07ffffffL
#define CRTC_OFFSET_RIGHT__CRTC_GUI_TRIG_OFFSET_MASK       0x40000000L
#define CRTC_OFFSET_RIGHT__CRTC_GUI_TRIG_OFFSET            0x40000000L
#define CRTC_OFFSET_RIGHT__CRTC_OFFSET_LOCK_MASK           0x80000000L
#define CRTC_OFFSET_RIGHT__CRTC_OFFSET_LOCK                0x80000000L

// CRTC_OFFSET
#define CRTC_OFFSET__CRTC_OFFSET_MASK                      0x07ffffffL
#define CRTC_OFFSET__CRTC_GUI_TRIG_OFFSET_MASK             0x40000000L
#define CRTC_OFFSET__CRTC_GUI_TRIG_OFFSET                  0x40000000L
#define CRTC_OFFSET__CRTC_OFFSET_LOCK_MASK                 0x80000000L
#define CRTC_OFFSET__CRTC_OFFSET_LOCK                      0x80000000L

// CRTC_OFFSET_CNTL
#define CRTC_OFFSET_CNTL__CRTC_TILE_LINE_MASK              0x0000000fL
#define CRTC_OFFSET_CNTL__CRTC_TILE_LINE_RIGHT_MASK        0x000000f0L
#define CRTC_OFFSET_CNTL__CRTC_TILE_EN_RIGHT_MASK          0x00004000L
#define CRTC_OFFSET_CNTL__CRTC_TILE_EN_RIGHT               0x00004000L
#define CRTC_OFFSET_CNTL__CRTC_TILE_EN_MASK                0x00008000L
#define CRTC_OFFSET_CNTL__CRTC_TILE_EN                     0x00008000L
#define CRTC_OFFSET_CNTL__CRTC_OFFSET_FLIP_CNTL_MASK       0x00010000L
#define CRTC_OFFSET_CNTL__CRTC_OFFSET_FLIP_CNTL            0x00010000L
#define CRTC_OFFSET_CNTL__CRTC_STEREO_OFFSET_EN_MASK       0x00020000L
#define CRTC_OFFSET_CNTL__CRTC_STEREO_OFFSET_EN            0x00020000L
#define CRTC_OFFSET_CNTL__CRTC_STEREO_SYNC_EN_MASK         0x000c0000L
#define CRTC_OFFSET_CNTL__CRTC_STEREO_SYNC_OUT_EN_MASK     0x00100000L
#define CRTC_OFFSET_CNTL__CRTC_STEREO_SYNC_OUT_EN          0x00100000L
#define CRTC_OFFSET_CNTL__CRTC_STEREO_SYNC_MASK            0x00200000L
#define CRTC_OFFSET_CNTL__CRTC_STEREO_SYNC                 0x00200000L
#define CRTC_OFFSET_CNTL__CRTC_GUI_TRIG_OFFSET_LEFT_EN_MASK 0x10000000L
#define CRTC_OFFSET_CNTL__CRTC_GUI_TRIG_OFFSET_LEFT_EN     0x10000000L
#define CRTC_OFFSET_CNTL__CRTC_GUI_TRIG_OFFSET_RIGHT_EN_MASK 0x20000000L
#define CRTC_OFFSET_CNTL__CRTC_GUI_TRIG_OFFSET_RIGHT_EN    0x20000000L
#define CRTC_OFFSET_CNTL__CRTC_GUI_TRIG_OFFSET_MASK        0x40000000L
#define CRTC_OFFSET_CNTL__CRTC_GUI_TRIG_OFFSET             0x40000000L
#define CRTC_OFFSET_CNTL__CRTC_OFFSET_LOCK_MASK            0x80000000L
#define CRTC_OFFSET_CNTL__CRTC_OFFSET_LOCK                 0x80000000L

// CRTC_PITCH
#define CRTC_PITCH__CRTC_PITCH_MASK                        0x000007ffL
#define CRTC_PITCH__CRTC_PITCH_RIGHT_MASK                  0x07ff0000L

// OVR_CLR
#define OVR_CLR__OVR_CLR_B_MASK                            0x000000ffL
#define OVR_CLR__OVR_CLR_G_MASK                            0x0000ff00L
#define OVR_CLR__OVR_CLR_R_MASK                            0x00ff0000L

// OVR_WID_LEFT_RIGHT
#define OVR_WID_LEFT_RIGHT__OVR_WID_RIGHT_MASK             0x0000007fL
#define OVR_WID_LEFT_RIGHT__OVR_WID_LEFT_MASK              0x007f0000L

// OVR_WID_TOP_BOTTOM
#define OVR_WID_TOP_BOTTOM__OVR_WID_BOTTOM_MASK            0x000003ffL
#define OVR_WID_TOP_BOTTOM__OVR_WID_TOP_MASK               0x03ff0000L

// DISPLAY_BASE_ADDR
#define DISPLAY_BASE_ADDR__DISPLAY_BASE_ADDR_MASK          0xffffffffL

// SNAPSHOT_VH_COUNTS
#define SNAPSHOT_VH_COUNTS__SNAPSHOT_HCOUNT_MASK           0x000003ffL
#define SNAPSHOT_VH_COUNTS__SNAPSHOT_VCOUNT_MASK           0x0fff0000L

// SNAPSHOT_F_COUNT
#define SNAPSHOT_F_COUNT__SNAPSHOT_F_COUNT_MASK            0x001fffffL

// N_VIF_COUNT
#define N_VIF_COUNT__N_VIF_COUNT_VAL_MASK                  0x000003ffL
#define N_VIF_COUNT__GENLOCK_SOURCE_SEL_MASK               0x80000000L
#define N_VIF_COUNT__GENLOCK_SOURCE_SEL                    0x80000000L

// SNAPSHOT_VIF_COUNT
#define SNAPSHOT_VIF_COUNT__LSNAPSHOT_VIF_COUNT_MASK       0x000003ffL
#define SNAPSHOT_VIF_COUNT__USNAPSHOT_VIF_COUNT_MASK       0x001ffc00L
#define SNAPSHOT_VIF_COUNT__AUTO_SNAPSHOT_TAKEN_RD_MASK    0x01000000L
#define SNAPSHOT_VIF_COUNT__AUTO_SNAPSHOT_TAKEN_RD         0x01000000L
#define SNAPSHOT_VIF_COUNT__AUTO_SNAPSHOT_TAKEN_WR_MASK    0x01000000L
#define SNAPSHOT_VIF_COUNT__AUTO_SNAPSHOT_TAKEN_WR         0x01000000L
#define SNAPSHOT_VIF_COUNT__MANUAL_SNAPSHOT_NOW_MASK       0x02000000L
#define SNAPSHOT_VIF_COUNT__MANUAL_SNAPSHOT_NOW            0x02000000L

// FP_CRTC_H_TOTAL_DISP
#define FP_CRTC_H_TOTAL_DISP__FP_CRTC_H_TOTAL_MASK         0x000003ffL
#define FP_CRTC_H_TOTAL_DISP__FP_CRTC_H_DISP_MASK          0x01ff0000L

// FP_CRTC_V_TOTAL_DISP
#define FP_CRTC_V_TOTAL_DISP__FP_CRTC_V_TOTAL_MASK         0x00000fffL
#define FP_CRTC_V_TOTAL_DISP__FP_CRTC_V_DISP_MASK          0x0fff0000L

// CRT_CRTC_H_SYNC_STRT_WID
#define CRT_CRTC_H_SYNC_STRT_WID__CRT_CRTC_H_SYNC_STRT_CHAR_MASK 0x00001ff8L
#define CRT_CRTC_H_SYNC_STRT_WID__CRT_CRTC_H_SYNC_WID_MASK 0x003f0000L

// CRT_CRTC_V_SYNC_STRT_WID
#define CRT_CRTC_V_SYNC_STRT_WID__CRT_CRTC_V_SYNC_STRT_MASK 0x00000fffL
#define CRT_CRTC_V_SYNC_STRT_WID__CRT_CRTC_V_SYNC_WID_MASK 0x001f0000L

// CUR_OFFSET
#define CUR_OFFSET__CUR_OFFSET_MASK                        0x07ffffffL
#define CUR_OFFSET__CUR_LOCK_MASK                          0x80000000L
#define CUR_OFFSET__CUR_LOCK                               0x80000000L

// CUR_HORZ_VERT_POSN
#define CUR_HORZ_VERT_POSN__CUR_VERT_POSN_MASK             0x00000fffL
#define CUR_HORZ_VERT_POSN__CUR_HORZ_POSN_MASK             0x3fff0000L
#define CUR_HORZ_VERT_POSN__CUR_LOCK_MASK                  0x80000000L
#define CUR_HORZ_VERT_POSN__CUR_LOCK                       0x80000000L

// CUR_HORZ_VERT_OFF
#define CUR_HORZ_VERT_OFF__CUR_VERT_OFF_MASK               0x0000003fL
#define CUR_HORZ_VERT_OFF__CUR_HORZ_OFF_MASK               0x003f0000L
#define CUR_HORZ_VERT_OFF__CUR_LOCK_MASK                   0x80000000L
#define CUR_HORZ_VERT_OFF__CUR_LOCK                        0x80000000L

// CUR_CLR0
#define CUR_CLR0__CUR_CLR0_B_MASK                          0x000000ffL
#define CUR_CLR0__CUR_CLR0_G_MASK                          0x0000ff00L
#define CUR_CLR0__CUR_CLR0_R_MASK                          0x00ff0000L

// CUR_CLR1
#define CUR_CLR1__CUR_CLR1_B_MASK                          0x000000ffL
#define CUR_CLR1__CUR_CLR1_G_MASK                          0x0000ff00L
#define CUR_CLR1__CUR_CLR1_R_MASK                          0x00ff0000L

// FP_HORZ_VERT_ACTIVE
#define FP_HORZ_VERT_ACTIVE__FP_VERT_ACTIVE_SIZE_MASK      0x00000fffL
#define FP_HORZ_VERT_ACTIVE__FP_HORZ_ACTIVE_SIZE_MASK      0x01ff0000L

// CRTC_MORE_CNTL
#define CRTC_MORE_CNTL__CRTC_HORZ_BLANK_MODE_SEL_MASK      0x00000001L
#define CRTC_MORE_CNTL__CRTC_HORZ_BLANK_MODE_SEL           0x00000001L
#define CRTC_MORE_CNTL__CRTC_VERT_BLANK_MODE_SEL_MASK      0x00000002L
#define CRTC_MORE_CNTL__CRTC_VERT_BLANK_MODE_SEL           0x00000002L
#define CRTC_MORE_CNTL__CRTC_AUTO_HORZ_CENTER_EN_MASK      0x00000004L
#define CRTC_MORE_CNTL__CRTC_AUTO_HORZ_CENTER_EN           0x00000004L
#define CRTC_MORE_CNTL__CRTC_AUTO_VERT_CENTER_EN_MASK      0x00000008L
#define CRTC_MORE_CNTL__CRTC_AUTO_VERT_CENTER_EN           0x00000008L
#define CRTC_MORE_CNTL__CRTC_H_CUTOFF_ACTIVE_EN_MASK       0x00000010L
#define CRTC_MORE_CNTL__CRTC_H_CUTOFF_ACTIVE_EN            0x00000010L
#define CRTC_MORE_CNTL__CRTC_V_CUTOFF_ACTIVE_EN_MASK       0x00000020L
#define CRTC_MORE_CNTL__CRTC_V_CUTOFF_ACTIVE_EN            0x00000020L
#define CRTC_MORE_CNTL__FORCE_H_EVEN_PIXEL_COUNT_MASK      0x00000040L
#define CRTC_MORE_CNTL__FORCE_H_EVEN_PIXEL_COUNT           0x00000040L
#define CRTC_MORE_CNTL__RMX_H_FILT_COEFFICIENT_MASK        0x07000000L
#define CRTC_MORE_CNTL__RMX_H_FILTER_EN_MASK               0x08000000L
#define CRTC_MORE_CNTL__RMX_H_FILTER_EN                    0x08000000L
#define CRTC_MORE_CNTL__RMX_V_FILT_COEFFICIENT_MASK        0x70000000L
#define CRTC_MORE_CNTL__RMX_V_FILTER_EN_MASK               0x80000000L
#define CRTC_MORE_CNTL__RMX_V_FILTER_EN                    0x80000000L

// DAC_EXT_CNTL
#define DAC_EXT_CNTL__DAC2_FORCE_BLANK_OFF_EN_MASK         0x00000001L
#define DAC_EXT_CNTL__DAC2_FORCE_BLANK_OFF_EN              0x00000001L
#define DAC_EXT_CNTL__DAC2_FORCE_DATA_EN_MASK              0x00000002L
#define DAC_EXT_CNTL__DAC2_FORCE_DATA_EN                   0x00000002L
#define DAC_EXT_CNTL__DAC_FORCE_BLANK_OFF_EN_MASK          0x00000010L
#define DAC_EXT_CNTL__DAC_FORCE_BLANK_OFF_EN               0x00000010L
#define DAC_EXT_CNTL__DAC_FORCE_DATA_EN_MASK               0x00000020L
#define DAC_EXT_CNTL__DAC_FORCE_DATA_EN                    0x00000020L
#define DAC_EXT_CNTL__DAC_FORCE_DATA_SEL_MASK              0x000000c0L
#define DAC_EXT_CNTL__DAC_FORCE_DATA_MASK                  0x0003ff00L

// FP_GEN_CNTL
#define FP_GEN_CNTL__FP_ON_MASK                            0x00000001L
#define FP_GEN_CNTL__FP_ON                                 0x00000001L
#define FP_GEN_CNTL__FP_BLANK_EN_MASK                      0x00000002L
#define FP_GEN_CNTL__FP_BLANK_EN                           0x00000002L
#define FP_GEN_CNTL__TMDS_EN_MASK                          0x00000004L
#define FP_GEN_CNTL__TMDS_EN                               0x00000004L
#define FP_GEN_CNTL__PANEL_FORMAT_MASK                     0x00000008L
#define FP_GEN_CNTL__PANEL_FORMAT                          0x00000008L
#define FP_GEN_CNTL__NO_OF_GREY_MASK                       0x00000030L
#define FP_GEN_CNTL__FP_RST_FM_MASK                        0x00000040L
#define FP_GEN_CNTL__FP_RST_FM                             0x00000040L
#define FP_GEN_CNTL__FP_EN_TMDS_MASK                       0x00000080L
#define FP_GEN_CNTL__FP_EN_TMDS                            0x00000080L
#define FP_GEN_CNTL__FP_DETECT_SENSE_MASK                  0x00000100L
#define FP_GEN_CNTL__FP_DETECT_SENSE                       0x00000100L
#define FP_GEN_CNTL__FP_DETECT_INT_POL_MASK                0x00000200L
#define FP_GEN_CNTL__FP_DETECT_INT_POL                     0x00000200L
#define FP_GEN_CNTL__FP_DETECT_EN_MASK                     0x00001000L
#define FP_GEN_CNTL__FP_DETECT_EN                          0x00001000L
#define FP_GEN_CNTL__FP_SRC_SEL_MASK                       0x00002000L
#define FP_GEN_CNTL__FP_SRC_SEL                            0x00002000L
#define FP_GEN_CNTL__FP_USE_VGA_HVSYNC_MASK                0x00004000L
#define FP_GEN_CNTL__FP_USE_VGA_HVSYNC                     0x00004000L
#define FP_GEN_CNTL__FP_USE_VGA_SYNC_POLARITY_MASK         0x00008000L
#define FP_GEN_CNTL__FP_USE_VGA_SYNC_POLARITY              0x00008000L
#define FP_GEN_CNTL__CRTC_DONT_SHADOW_VPAR_MASK            0x00010000L
#define FP_GEN_CNTL__CRTC_DONT_SHADOW_VPAR                 0x00010000L
#define FP_GEN_CNTL__CRTC_DONT_SHADOW_HEND_MASK            0x00020000L
#define FP_GEN_CNTL__CRTC_DONT_SHADOW_HEND                 0x00020000L
#define FP_GEN_CNTL__CRTC_USE_SHADOWED_VEND_MASK           0x00040000L
#define FP_GEN_CNTL__CRTC_USE_SHADOWED_VEND                0x00040000L
#define FP_GEN_CNTL__CRTC_USE_SHADOWED_ROWCUR_MASK         0x00080000L
#define FP_GEN_CNTL__CRTC_USE_SHADOWED_ROWCUR              0x00080000L
#define FP_GEN_CNTL__RMX_HVSYNC_CONTROL_EN_MASK            0x00100000L
#define FP_GEN_CNTL__RMX_HVSYNC_CONTROL_EN                 0x00100000L
#define FP_GEN_CNTL__DFP_SYNC_SEL_MASK                     0x00200000L
#define FP_GEN_CNTL__DFP_SYNC_SEL                          0x00200000L
#define FP_GEN_CNTL__CRTC_LOCK_8DOT_MASK                   0x00400000L
#define FP_GEN_CNTL__CRTC_LOCK_8DOT                        0x00400000L
#define FP_GEN_CNTL__CRT_SYNC_SEL_MASK                     0x00800000L
#define FP_GEN_CNTL__CRT_SYNC_SEL                          0x00800000L
#define FP_GEN_CNTL__FP_USE_SHADOW_EN_MASK                 0x01000000L
#define FP_GEN_CNTL__FP_USE_SHADOW_EN                      0x01000000L
#define FP_GEN_CNTL__DONT_RST_CHAREN_MASK                  0x02000000L
#define FP_GEN_CNTL__DONT_RST_CHAREN                       0x02000000L
#define FP_GEN_CNTL__CRT_SYNC_ALT_SEL_MASK                 0x04000000L
#define FP_GEN_CNTL__CRT_SYNC_ALT_SEL                      0x04000000L
#define FP_GEN_CNTL__CRTC_USE_NONSHADOW_HPARAMS_FOR_BLANK_MASK 0x08000000L
#define FP_GEN_CNTL__CRTC_USE_NONSHADOW_HPARAMS_FOR_BLANK  0x08000000L
#define FP_GEN_CNTL__CRTC_USE_NONSHADOW_VPARAMS_FOR_BLANK_MASK 0x10000000L
#define FP_GEN_CNTL__CRTC_USE_NONSHADOW_VPARAMS_FOR_BLANK  0x10000000L
#define FP_GEN_CNTL__CRTC_VGA_XOVERSCAN_COLOR_MASK         0x20000000L
#define FP_GEN_CNTL__CRTC_VGA_XOVERSCAN_COLOR              0x20000000L
#define FP_GEN_CNTL__CRTC_VGA_XOVERSCAN_DIVBY2_EN_MASK     0x40000000L
#define FP_GEN_CNTL__CRTC_VGA_XOVERSCAN_DIVBY2_EN          0x40000000L

// FP2_GEN_CNTL
#define FP2_GEN_CNTL__FP2_BLANK_EN_MASK                    0x00000002L
#define FP2_GEN_CNTL__FP2_BLANK_EN                         0x00000002L
#define FP2_GEN_CNTL__FP2_ON_MASK                          0x00000004L
#define FP2_GEN_CNTL__FP2_ON                               0x00000004L
#define FP2_GEN_CNTL__FP2_PANEL_FORMAT_MASK                0x00000008L
#define FP2_GEN_CNTL__FP2_PANEL_FORMAT                     0x00000008L
#define FP2_GEN_CNTL__FP2_NO_OF_GREY_MASK                  0x00000030L
#define FP2_GEN_CNTL__FP2_RST_FM_MASK                      0x00000040L
#define FP2_GEN_CNTL__FP2_RST_FM                           0x00000040L
#define FP2_GEN_CNTL__FP2_DETECT_SENSE_MASK                0x00000100L
#define FP2_GEN_CNTL__FP2_DETECT_SENSE                     0x00000100L
#define FP2_GEN_CNTL__FP2_DETECT_INT_POL_MASK              0x00000200L
#define FP2_GEN_CNTL__FP2_DETECT_INT_POL                   0x00000200L
#define FP2_GEN_CNTL__FP2_SRC_SEL_MASK                     0x00002000L
#define FP2_GEN_CNTL__FP2_SRC_SEL                          0x00002000L
#define FP2_GEN_CNTL__FP2_FP_POL_MASK                      0x00010000L
#define FP2_GEN_CNTL__FP2_FP_POL                           0x00010000L
#define FP2_GEN_CNTL__FP2_LP_POL_MASK                      0x00020000L
#define FP2_GEN_CNTL__FP2_LP_POL                           0x00020000L
#define FP2_GEN_CNTL__FP2_SCK_POL_MASK                     0x00040000L
#define FP2_GEN_CNTL__FP2_SCK_POL                          0x00040000L
#define FP2_GEN_CNTL__FP2_LCD_CNTL_MASK                    0x00380000L
#define FP2_GEN_CNTL__FP2_PAD_FLOP_EN_MASK                 0x00400000L
#define FP2_GEN_CNTL__FP2_PAD_FLOP_EN                      0x00400000L
#define FP2_GEN_CNTL__FP2_CRC_EN_MASK                      0x00800000L
#define FP2_GEN_CNTL__FP2_CRC_EN                           0x00800000L
#define FP2_GEN_CNTL__FP2_CRC_READ_EN_MASK                 0x01000000L
#define FP2_GEN_CNTL__FP2_CRC_READ_EN                      0x01000000L
#define FP2_GEN_CNTL__FP2_B_ON_MASK                        0x02000000L
#define FP2_GEN_CNTL__FP2_B_ON                             0x02000000L

// FP_HORZ_STRETCH
#define FP_HORZ_STRETCH__FP_HORZ_STRETCH_RATIO_MASK        0x0000ffffL
#define FP_HORZ_STRETCH__FP_HORZ_PANEL_SIZE_MASK           0x01ff0000L
#define FP_HORZ_STRETCH__FP_HORZ_STRETCH_EN_MASK           0x02000000L
#define FP_HORZ_STRETCH__FP_HORZ_STRETCH_EN                0x02000000L
#define FP_HORZ_STRETCH__FP_HORZ_STRETCH_MODE_MASK         0x04000000L
#define FP_HORZ_STRETCH__FP_HORZ_STRETCH_MODE              0x04000000L
#define FP_HORZ_STRETCH__FP_AUTO_HORZ_RATIO_MASK           0x08000000L
#define FP_HORZ_STRETCH__FP_AUTO_HORZ_RATIO                0x08000000L
#define FP_HORZ_STRETCH__FP_LOOP_STRETCH_MASK              0x70000000L
#define FP_HORZ_STRETCH__RMX_AUTO_RATIO_HORZ_INC_MASK      0x80000000L
#define FP_HORZ_STRETCH__RMX_AUTO_RATIO_HORZ_INC           0x80000000L

// FP_VERT_STRETCH
#define FP_VERT_STRETCH__FP_VERT_STRETCH_RATIO_MASK        0x00000fffL
#define FP_VERT_STRETCH__FP_VERT_PANEL_SIZE_MASK           0x00fff000L
#define FP_VERT_STRETCH__FP_VERT_STRETCH_EN_MASK           0x02000000L
#define FP_VERT_STRETCH__FP_VERT_STRETCH_EN                0x02000000L
#define FP_VERT_STRETCH__FP_VERT_STRETCH_MODE_MASK         0x04000000L
#define FP_VERT_STRETCH__FP_VERT_STRETCH_MODE              0x04000000L
#define FP_VERT_STRETCH__FP_AUTO_VERT_RATIO_MASK           0x08000000L
#define FP_VERT_STRETCH__FP_AUTO_VERT_RATIO                0x08000000L
#define FP_VERT_STRETCH__RMX_H_FILTER_INIT_MASK            0x10000000L
#define FP_VERT_STRETCH__RMX_H_FILTER_INIT                 0x10000000L
#define FP_VERT_STRETCH__RMX_V_FILTER_INIT_MASK            0x20000000L
#define FP_VERT_STRETCH__RMX_V_FILTER_INIT                 0x20000000L
#define FP_VERT_STRETCH__RMX_AUTO_RATIO_VERT_INC_MASK      0x80000000L
#define FP_VERT_STRETCH__RMX_AUTO_RATIO_VERT_INC           0x80000000L

// TMDS_CNTL
#define TMDS_CNTL__TMDS_CTL0_MASK                          0x00000001L
#define TMDS_CNTL__TMDS_CTL0                               0x00000001L
#define TMDS_CNTL__TMDS_CTL1_MASK                          0x00000002L
#define TMDS_CNTL__TMDS_CTL1                               0x00000002L
#define TMDS_CNTL__TMDS_CTL2_MASK                          0x00000004L
#define TMDS_CNTL__TMDS_CTL2                               0x00000004L
#define TMDS_CNTL__TMDS_CTL3_MASK                          0x00000008L
#define TMDS_CNTL__TMDS_CTL3                               0x00000008L
#define TMDS_CNTL__TMDS_DEBUG_HSYNC_MASK                   0x00000010L
#define TMDS_CNTL__TMDS_DEBUG_HSYNC                        0x00000010L
#define TMDS_CNTL__TMDS_DEBUG_VSYNC_MASK                   0x00000020L
#define TMDS_CNTL__TMDS_DEBUG_VSYNC                        0x00000020L
#define TMDS_CNTL__TMDS_DEBUG_DE_MASK                      0x00000040L
#define TMDS_CNTL__TMDS_DEBUG_DE                           0x00000040L
#define TMDS_CNTL__TMDS_DEBUG_EN_MASK                      0x00000080L
#define TMDS_CNTL__TMDS_DEBUG_EN                           0x00000080L
#define TMDS_CNTL__TMDS_CTL_FB_SEL_MASK                    0x00000300L
#define TMDS_CNTL__TMDS_CTL_FB_DEL_MASK                    0x00000c00L
#define TMDS_CNTL__TMDS_STEREOSYNC_CTL_SEL_MASK            0x00003000L
#define TMDS_CNTL__TMDS_SYNC_CHAR_EN_MASK                  0x000f0000L
#define TMDS_CNTL__TMDS_SYNC_CONT_MASK                     0x01000000L
#define TMDS_CNTL__TMDS_SYNC_CONT                          0x01000000L
#define TMDS_CNTL__TMDS_DPCUM_TST_MASK                     0x02000000L
#define TMDS_CNTL__TMDS_DPCUM_TST                          0x02000000L
#define TMDS_CNTL__TMDS_DPCUM_IN_MASK                      0x3c000000L
#define TMDS_CNTL__TMDS_CRC_EN_MASK                        0x40000000L
#define TMDS_CNTL__TMDS_CRC_EN                             0x40000000L
#define TMDS_CNTL__TMDS_RB_SWITCH_EN_MASK                  0x80000000L
#define TMDS_CNTL__TMDS_RB_SWITCH_EN                       0x80000000L

// TMDS_SYNC_CHAR_SETA
#define TMDS_SYNC_CHAR_SETA__TMDS_SYNC_CHAR0_MASK          0x000003ffL
#define TMDS_SYNC_CHAR_SETA__TMDS_SYNC_CHAR1_MASK          0x03ff0000L

// TMDS_SYNC_CHAR_SETB
#define TMDS_SYNC_CHAR_SETB__TMDS_SYNC_CHAR2_MASK          0x000003ffL
#define TMDS_SYNC_CHAR_SETB__TMDS_SYNC_CHAR3_MASK          0x03ff0000L

// TMDS_CRC
#define TMDS_CRC__TMDS_CRCRGB_MASK                         0x3fffffffL

// TMDS_TRANSMITTER_CNTL
#define TMDS_TRANSMITTER_CNTL__TMDS_PLLEN_MASK             0x00000001L
#define TMDS_TRANSMITTER_CNTL__TMDS_PLLEN                  0x00000001L
#define TMDS_TRANSMITTER_CNTL__TMDS_PLLRST_MASK            0x00000002L
#define TMDS_TRANSMITTER_CNTL__TMDS_PLLRST                 0x00000002L
#define TMDS_TRANSMITTER_CNTL__TMDS_MODE_SEL_MASK          0x0000000cL
#define TMDS_TRANSMITTER_CNTL__TMDS_REGSEL_MASK            0x00000030L
#define TMDS_TRANSMITTER_CNTL__TMDS_HALF_CLK_RST_MASK      0x00000040L
#define TMDS_TRANSMITTER_CNTL__TMDS_HALF_CLK_RST           0x00000040L
#define TMDS_TRANSMITTER_CNTL__TMDS_RAN_PAT_RST_MASK       0x00000080L
#define TMDS_TRANSMITTER_CNTL__TMDS_RAN_PAT_RST            0x00000080L
#define TMDS_TRANSMITTER_CNTL__TMDS_TSTPIX_MASK            0x0003ff00L
#define TMDS_TRANSMITTER_CNTL__TMDS_REG_MASK               0x0ffc0000L
#define TMDS_TRANSMITTER_CNTL__ICHCSEL_MASK                0x10000000L
#define TMDS_TRANSMITTER_CNTL__ICHCSEL                     0x10000000L
#define TMDS_TRANSMITTER_CNTL__ITCLKSEL_MASK               0x20000000L
#define TMDS_TRANSMITTER_CNTL__ITCLKSEL                    0x20000000L
#define TMDS_TRANSMITTER_CNTL__TMDS_RAN_PAT_SEL_MASK       0x40000000L
#define TMDS_TRANSMITTER_CNTL__TMDS_RAN_PAT_SEL            0x40000000L

// TMDS_PLL_CNTL
#define TMDS_PLL_CNTL__TMDS_PLLPCP_MASK                    0x00000007L
#define TMDS_PLL_CNTL__TMDS_PLLPVG_MASK                    0x00000038L
#define TMDS_PLL_CNTL__TMDS_PLLPDC_MASK                    0x000000c0L
#define TMDS_PLL_CNTL__TMDS_PLLPVS_MASK                    0x00000f00L

// TMDS_PATTERN_GEN_SEED
#define TMDS_PATTERN_GEN_SEED__PATTERN_SEED_MASK           0x00ffffffL

// ICON_OFFSET
#define ICON_OFFSET__ICON_OFFSET_MASK                      0x07ffffffL
#define ICON_OFFSET__BLANK_SCREEN1_MASK                    0x08000000L
#define ICON_OFFSET__BLANK_SCREEN1                         0x08000000L
#define ICON_OFFSET__DONT_DS_ICON_MASK                     0x10000000L
#define ICON_OFFSET__DONT_DS_ICON                          0x10000000L
#define ICON_OFFSET__ICON_LOCK_MASK                        0x80000000L
#define ICON_OFFSET__ICON_LOCK                             0x80000000L

// ICON_HORZ_VERT_POSN
#define ICON_HORZ_VERT_POSN__ICON_VERT_POSN_MASK           0x00000fffL
#define ICON_HORZ_VERT_POSN__ICON_HORZ_POSN_MASK           0x0fff0000L
#define ICON_HORZ_VERT_POSN__ICON_LOCK_MASK                0x80000000L
#define ICON_HORZ_VERT_POSN__ICON_LOCK                     0x80000000L

// ICON_HORZ_VERT_OFF
#define ICON_HORZ_VERT_OFF__ICON_VERT_OFF_MASK             0x0000007fL
#define ICON_HORZ_VERT_OFF__ICON_HORZ_OFF_MASK             0x007f0000L
#define ICON_HORZ_VERT_OFF__ICON_LOCK_MASK                 0x80000000L
#define ICON_HORZ_VERT_OFF__ICON_LOCK                      0x80000000L

// ICON_CLR0
#define ICON_CLR0__ICON_CLR0_B_MASK                        0x000000ffL
#define ICON_CLR0__ICON_CLR0_G_MASK                        0x0000ff00L
#define ICON_CLR0__ICON_CLR0_R_MASK                        0x00ff0000L

// ICON_CLR1
#define ICON_CLR1__ICON_CLR1_B_MASK                        0x000000ffL
#define ICON_CLR1__ICON_CLR1_G_MASK                        0x0000ff00L
#define ICON_CLR1__ICON_CLR1_R_MASK                        0x00ff0000L

// FP_H_SYNC_STRT_WID
#define FP_H_SYNC_STRT_WID__FP_H_SYNC_STRT_PIX_MASK        0x00000007L
#define FP_H_SYNC_STRT_WID__FP_H_SYNC_STRT_CHAR_MASK       0x00001ff8L
#define FP_H_SYNC_STRT_WID__FP_H_SYNC_WID_MASK             0x003f0000L
#define FP_H_SYNC_STRT_WID__FP_H_SYNC_POL_MASK             0x00800000L
#define FP_H_SYNC_STRT_WID__FP_H_SYNC_POL                  0x00800000L

// FP_V_SYNC_STRT_WID
#define FP_V_SYNC_STRT_WID__FP_V_SYNC_STRT_MASK            0x00000fffL
#define FP_V_SYNC_STRT_WID__FP_V_SYNC_WID_MASK             0x001f0000L
#define FP_V_SYNC_STRT_WID__FP_V_SYNC_POL_MASK             0x00800000L
#define FP_V_SYNC_STRT_WID__FP_V_SYNC_POL                  0x00800000L

// LVDS_DIGTMDS_CRC
#define LVDS_DIGTMDS_CRC__LVDS_CRC_SIG_RGB_MASK            0x00ffffffL
#define LVDS_DIGTMDS_CRC__LVDS_CRC_SIG_C_MASK              0x07000000L

// LVDS_GEN_CNTL
#define LVDS_GEN_CNTL__LVDS_ON_MASK                        0x00000001L
#define LVDS_GEN_CNTL__LVDS_ON                             0x00000001L
#define LVDS_GEN_CNTL__LVDS_DISPLAY_DIS_MASK               0x00000002L
#define LVDS_GEN_CNTL__LVDS_DISPLAY_DIS                    0x00000002L
#define LVDS_GEN_CNTL__LVDS_PANEL_TYPE_MASK                0x00000004L
#define LVDS_GEN_CNTL__LVDS_PANEL_TYPE                     0x00000004L
#define LVDS_GEN_CNTL__LVDS_PANEL_FORMAT_MASK              0x00000008L
#define LVDS_GEN_CNTL__LVDS_PANEL_FORMAT                   0x00000008L
#define LVDS_GEN_CNTL__LVDS_NO_OF_GREY_MASK                0x00000030L
#define LVDS_GEN_CNTL__LVDS_RST_FM_MASK                    0x00000040L
#define LVDS_GEN_CNTL__LVDS_RST_FM                         0x00000040L
#define LVDS_GEN_CNTL__LVDS_EN_MASK                        0x00000080L
#define LVDS_GEN_CNTL__LVDS_EN                             0x00000080L
#define LVDS_GEN_CNTL__LVDS_BL_MOD_LEVEL_MASK              0x0000ff00L
#define LVDS_GEN_CNTL__LVDS_BL_MOD_EN_MASK                 0x00010000L
#define LVDS_GEN_CNTL__LVDS_BL_MOD_EN                      0x00010000L
#define LVDS_GEN_CNTL__LVDS_BL_CLK_SEL_MASK                0x00020000L
#define LVDS_GEN_CNTL__LVDS_BL_CLK_SEL                     0x00020000L
#define LVDS_GEN_CNTL__LVDS_DIGON_MASK                     0x00040000L
#define LVDS_GEN_CNTL__LVDS_DIGON                          0x00040000L
#define LVDS_GEN_CNTL__LVDS_BLON_MASK                      0x00080000L
#define LVDS_GEN_CNTL__LVDS_BLON                           0x00080000L
#define LVDS_GEN_CNTL__LVDS_FP_POL_MASK                    0x00100000L
#define LVDS_GEN_CNTL__LVDS_FP_POL                         0x00100000L
#define LVDS_GEN_CNTL__LVDS_LP_POL_MASK                    0x00200000L
#define LVDS_GEN_CNTL__LVDS_LP_POL                         0x00200000L
#define LVDS_GEN_CNTL__LVDS_DTM_POL_MASK                   0x00400000L
#define LVDS_GEN_CNTL__LVDS_DTM_POL                        0x00400000L
#define LVDS_GEN_CNTL__LVDS_SRC_SEL_MASK                   0x00800000L
#define LVDS_GEN_CNTL__LVDS_SRC_SEL                        0x00800000L
#define LVDS_GEN_CNTL__LVDS_RESERVED_BITS_MASK             0x07000000L
#define LVDS_GEN_CNTL__LVDS_FPDI_EN_MASK                   0x08000000L
#define LVDS_GEN_CNTL__LVDS_FPDI_EN                        0x08000000L
#define LVDS_GEN_CNTL__LVDS_HSYNC_DELAY_MASK               0xf0000000L

// LVDS_PLL_CNTL
#define LVDS_PLL_CNTL__LVDS_CRC_DE_ONLY_MASK               0x00000001L
#define LVDS_PLL_CNTL__LVDS_CRC_DE_ONLY                    0x00000001L
#define LVDS_PLL_CNTL__LVDS_LVPVS_MASK                     0x0000001eL
#define LVDS_PLL_CNTL__LVDS_LPPVG_MASK                     0x000000e0L
#define LVDS_PLL_CNTL__LVDS_LPPDC_MASK                     0x00000300L
#define LVDS_PLL_CNTL__LVDS_LPPCP_MASK                     0x00001c00L
#define LVDS_PLL_CNTL__LVDS_SS_DISP_EN_MASK                0x00002000L
#define LVDS_PLL_CNTL__LVDS_SS_DISP_EN                     0x00002000L
#define LVDS_PLL_CNTL__LVDS_PRG_MASK                       0x0000c000L
#define LVDS_PLL_CNTL__LVDS_PLL_EN_MASK                    0x00010000L
#define LVDS_PLL_CNTL__LVDS_PLL_EN                         0x00010000L
#define LVDS_PLL_CNTL__LVDS_PLL_RESET_MASK                 0x00020000L
#define LVDS_PLL_CNTL__LVDS_PLL_RESET                      0x00020000L
#define LVDS_PLL_CNTL__LVDS_CRC_EN_MASK                    0x00100000L
#define LVDS_PLL_CNTL__LVDS_CRC_EN                         0x00100000L
#define LVDS_PLL_CNTL__LVDS_CRC_UP24_MASK                  0x00200000L
#define LVDS_PLL_CNTL__LVDS_CRC_UP24                       0x00200000L
#define LVDS_PLL_CNTL__LVDS_TEST_DATA_OUT_MASK             0x01c00000L
#define LVDS_PLL_CNTL__LVDS_TEST_DATA_SEL_MASK             0x06000000L
#define LVDS_PLL_CNTL__LCDENG_TEST_MODE_MASK               0xf0000000L

// AUX_WINDOW_HORZ_CNTL
#define AUX_WINDOW_HORZ_CNTL__AUX_WIN_HORZ_START_MASK      0x00000fffL
#define AUX_WINDOW_HORZ_CNTL__AUX_WIN_HORZ_END_MASK        0x00fff000L
#define AUX_WINDOW_HORZ_CNTL__AUX_WIN_EN_MASK              0x01000000L
#define AUX_WINDOW_HORZ_CNTL__AUX_WIN_EN                   0x01000000L
#define AUX_WINDOW_HORZ_CNTL__AUX_WIN_OUT_DELAY_MASK       0x1e000000L
#define AUX_WINDOW_HORZ_CNTL__RESERVED_MASK                0x40000000L
#define AUX_WINDOW_HORZ_CNTL__RESERVED                     0x40000000L
#define AUX_WINDOW_HORZ_CNTL__AUX_WIN_LOCK_MASK            0x80000000L
#define AUX_WINDOW_HORZ_CNTL__AUX_WIN_LOCK                 0x80000000L

// AUX_WINDOW_VERT_CNTL
#define AUX_WINDOW_VERT_CNTL__AUX_WIN_VERT_START_MASK      0x00000fffL
#define AUX_WINDOW_VERT_CNTL__AUX_WIN_VERT_END_MASK        0x0fff0000L
#define AUX_WINDOW_VERT_CNTL__AUX_WINDOW_POL_MASK          0x40000000L
#define AUX_WINDOW_VERT_CNTL__AUX_WINDOW_POL               0x40000000L
#define AUX_WINDOW_VERT_CNTL__AUX_WIN_LOCK_MASK            0x80000000L
#define AUX_WINDOW_VERT_CNTL__AUX_WIN_LOCK                 0x80000000L

// DVI_I2C_CNTL_0
#define DVI_I2C_CNTL_0__I2C_DONE_MASK                      0x00000001L
#define DVI_I2C_CNTL_0__I2C_DONE                           0x00000001L
#define DVI_I2C_CNTL_0__I2C_NACK_MASK                      0x00000002L
#define DVI_I2C_CNTL_0__I2C_NACK                           0x00000002L
#define DVI_I2C_CNTL_0__I2C_HALT_MASK                      0x00000004L
#define DVI_I2C_CNTL_0__I2C_HALT                           0x00000004L
#define DVI_I2C_CNTL_0__I2C_SOFT_RST_MASK                  0x00000020L
#define DVI_I2C_CNTL_0__I2C_SOFT_RST                       0x00000020L
#define DVI_I2C_CNTL_0__I2C_DRIVE_EN_MASK                  0x00000040L
#define DVI_I2C_CNTL_0__I2C_DRIVE_EN                       0x00000040L
#define DVI_I2C_CNTL_0__I2C_DRIVE_SEL_MASK                 0x00000080L
#define DVI_I2C_CNTL_0__I2C_DRIVE_SEL                      0x00000080L
#define DVI_I2C_CNTL_0__I2C_START_MASK                     0x00000100L
#define DVI_I2C_CNTL_0__I2C_START                          0x00000100L
#define DVI_I2C_CNTL_0__I2C_STOP_MASK                      0x00000200L
#define DVI_I2C_CNTL_0__I2C_STOP                           0x00000200L
#define DVI_I2C_CNTL_0__I2C_RECEIVE_MASK                   0x00000400L
#define DVI_I2C_CNTL_0__I2C_RECEIVE                        0x00000400L
#define DVI_I2C_CNTL_0__I2C_ABORT_MASK                     0x00000800L
#define DVI_I2C_CNTL_0__I2C_ABORT                          0x00000800L
#define DVI_I2C_CNTL_0__I2C_GO_MASK                        0x00001000L
#define DVI_I2C_CNTL_0__I2C_GO                             0x00001000L
#define DVI_I2C_CNTL_0__SW_WANTS_TO_USE_DVI_I2C_MASK       0x00002000L
#define DVI_I2C_CNTL_0__SW_WANTS_TO_USE_DVI_I2C            0x00002000L
#define DVI_I2C_CNTL_0__SW_CAN_USE_DVI_I2C_MASK            0x00002000L
#define DVI_I2C_CNTL_0__SW_CAN_USE_DVI_I2C                 0x00002000L
#define DVI_I2C_CNTL_0__SW_DONE_USING_DVI_I2C_MASK         0x00004000L
#define DVI_I2C_CNTL_0__SW_DONE_USING_DVI_I2C              0x00004000L
#define DVI_I2C_CNTL_0__HW_NEEDS_DVI_I2C_MASK              0x00004000L
#define DVI_I2C_CNTL_0__HW_NEEDS_DVI_I2C                   0x00004000L
#define DVI_I2C_CNTL_0__ABORT_HW_DVI_I2C_MASK              0x00008000L
#define DVI_I2C_CNTL_0__ABORT_HW_DVI_I2C                   0x00008000L
#define DVI_I2C_CNTL_0__HW_USING_DVI_I2C_MASK              0x00008000L
#define DVI_I2C_CNTL_0__HW_USING_DVI_I2C                   0x00008000L
#define DVI_I2C_CNTL_0__I2C_PRESCALE_MASK                  0xffff0000L

// DVI_I2C_CNTL_1
#define DVI_I2C_CNTL_1__I2C_DATA_COUNT_MASK                0x0000000fL
#define DVI_I2C_CNTL_1__I2C_ADDR_COUNT_MASK                0x00000700L
#define DVI_I2C_CNTL_1__I2C_SEL_MASK                       0x00010000L
#define DVI_I2C_CNTL_1__I2C_SEL                            0x00010000L
#define DVI_I2C_CNTL_1__I2C_EN_MASK                        0x00020000L
#define DVI_I2C_CNTL_1__I2C_EN                             0x00020000L
#define DVI_I2C_CNTL_1__I2C_TIME_LIMIT_MASK                0xff000000L

// DVI_I2C_DATA
#define DVI_I2C_DATA__I2C_DATA_MASK                        0x000000ffL

// LVDS_SS_GEN_CNTL
#define LVDS_SS_GEN_CNTL__SS_EXT_EN_MASK                   0x00000002L
#define LVDS_SS_GEN_CNTL__SS_EXT_EN                        0x00000002L
#define LVDS_SS_GEN_CNTL__SS_EXT_SEL_MASK                  0x00000004L
#define LVDS_SS_GEN_CNTL__SS_EXT_SEL                       0x00000004L
#define LVDS_SS_GEN_CNTL__SS_BUF_EN_MASK                   0x00000008L
#define LVDS_SS_GEN_CNTL__SS_BUF_EN                        0x00000008L
#define LVDS_SS_GEN_CNTL__SS_BUF_OFFSET_MASK               0x000007f0L
#define LVDS_SS_GEN_CNTL__SS_BUF_RESET_EN_MASK             0x00000800L
#define LVDS_SS_GEN_CNTL__SS_BUF_RESET_EN                  0x00000800L
#define LVDS_SS_GEN_CNTL__SS_BUF_STRENGTH_MASK             0x00003000L
#define LVDS_SS_GEN_CNTL__LVDSPWR_STRENGTH_MASK            0x0000c000L
#define LVDS_SS_GEN_CNTL__LVDS_PWRSEQ_DELAY1_MASK          0x000f0000L
#define LVDS_SS_GEN_CNTL__LVDS_PWRSEQ_DELAY2_MASK          0x00f00000L
#define LVDS_SS_GEN_CNTL__LVDS_CLK_PATTERN_MASK            0x7f000000L

// GRPH_BUFFER_CNTL
#define GRPH_BUFFER_CNTL__GRPH_START_REQ_MASK              0x0000007fL
#define GRPH_BUFFER_CNTL__GRPH_STOP_REQ_MASK               0x00007f00L
#define GRPH_BUFFER_CNTL__GRPH_CRITICAL_POINT_MASK         0x007f0000L
#define GRPH_BUFFER_CNTL__GRPH_CRITICAL_CNTL_MASK          0x10000000L
#define GRPH_BUFFER_CNTL__GRPH_CRITICAL_CNTL               0x10000000L
#define GRPH_BUFFER_CNTL__GRPH_BUFFER_SIZE_MASK            0x20000000L
#define GRPH_BUFFER_CNTL__GRPH_BUFFER_SIZE                 0x20000000L
#define GRPH_BUFFER_CNTL__GRPH_CRITICAL_AT_SOF_MASK        0x40000000L
#define GRPH_BUFFER_CNTL__GRPH_CRITICAL_AT_SOF             0x40000000L
#define GRPH_BUFFER_CNTL__GRPH_STOP_CNTL_MASK              0x80000000L
#define GRPH_BUFFER_CNTL__GRPH_STOP_CNTL                   0x80000000L

// VGA_BUFFER_CNTL
#define VGA_BUFFER_CNTL__VGA_START_REQ_MASK                0x0000003fL
#define VGA_BUFFER_CNTL__VGA_STOP_REQ_MASK                 0x00003f00L
#define VGA_BUFFER_CNTL__VGA_CRITICAL_POINT_MASK           0x003f0000L

// LVDS_PWM_CNTL
#define LVDS_PWM_CNTL__PWM_CLK_CONF_A5_MASK                0x00007fffL
#define LVDS_PWM_CNTL__ENA_BL_MASK                         0x00010000L
#define LVDS_PWM_CNTL__ENA_BL                              0x00010000L
#define LVDS_PWM_CNTL__LVDS_SWAP_MASK                      0x00020000L
#define LVDS_PWM_CNTL__LVDS_SWAP                           0x00020000L
#define LVDS_PWM_CNTL__LVDS_MACRO_CLK_SHIFT_MASK           0x00040000L
#define LVDS_PWM_CNTL__LVDS_MACRO_CLK_SHIFT                0x00040000L
#define LVDS_PWM_CNTL__LVDS_2ND_CHAN_VS_MASK               0x00080000L
#define LVDS_PWM_CNTL__LVDS_2ND_CHAN_VS                    0x00080000L
#define LVDS_PWM_CNTL__LVDS_2ND_CHAN_HS_MASK               0x00100000L
#define LVDS_PWM_CNTL__LVDS_2ND_CHAN_HS                    0x00100000L
#define LVDS_PWM_CNTL__LVDS_2ND_CHAN_DE_MASK               0x00200000L
#define LVDS_PWM_CNTL__LVDS_2ND_CHAN_DE                    0x00200000L

// CRTC2_H_TOTAL_DISP
#define CRTC2_H_TOTAL_DISP__CRTC2_H_TOTAL_MASK             0x000003ffL
#define CRTC2_H_TOTAL_DISP__CRTC2_H_DISP_MASK              0x01ff0000L

// CRTC2_H_SYNC_STRT_WID
#define CRTC2_H_SYNC_STRT_WID__CRTC2_H_SYNC_STRT_PIX_MASK  0x00000007L
#define CRTC2_H_SYNC_STRT_WID__CRTC2_H_SYNC_STRT_CHAR_MASK 0x00001ff8L
#define CRTC2_H_SYNC_STRT_WID__CRTC2_H_SYNC_WID_MASK       0x003f0000L
#define CRTC2_H_SYNC_STRT_WID__CRTC2_H_SYNC_POL_MASK       0x00800000L
#define CRTC2_H_SYNC_STRT_WID__CRTC2_H_SYNC_POL            0x00800000L

// CRTC2_V_TOTAL_DISP
#define CRTC2_V_TOTAL_DISP__CRTC2_V_TOTAL_MASK             0x00000fffL
#define CRTC2_V_TOTAL_DISP__CRTC2_V_DISP_MASK              0x0fff0000L

// CRTC2_V_SYNC_STRT_WID
#define CRTC2_V_SYNC_STRT_WID__CRTC2_V_SYNC_STRT_MASK      0x00000fffL
#define CRTC2_V_SYNC_STRT_WID__CRTC2_V_SYNC_WID_MASK       0x001f0000L
#define CRTC2_V_SYNC_STRT_WID__CRTC2_V_SYNC_POL_MASK       0x00800000L
#define CRTC2_V_SYNC_STRT_WID__CRTC2_V_SYNC_POL            0x00800000L

// CRTC2_VLINE_CRNT_VLINE
#define CRTC2_VLINE_CRNT_VLINE__CRTC2_VLINE_MASK           0x00000fffL
#define CRTC2_VLINE_CRNT_VLINE__CRTC2_CRNT_VLINE_MASK      0x0fff0000L

// CRTC2_CRNT_FRAME
#define CRTC2_CRNT_FRAME__CRTC2_CRNT_FRAME_MASK            0x001fffffL

// CRTC2_GUI_TRIG_VLINE
#define CRTC2_GUI_TRIG_VLINE__CRTC2_GUI_TRIG_VLINE_START_MASK 0x00000fffL
#define CRTC2_GUI_TRIG_VLINE__CRTC2_GUI_TRIG_VLINE_INV_MASK 0x00008000L
#define CRTC2_GUI_TRIG_VLINE__CRTC2_GUI_TRIG_VLINE_INV     0x00008000L
#define CRTC2_GUI_TRIG_VLINE__CRTC2_GUI_TRIG_VLINE_END_MASK 0x0fff0000L
#define CRTC2_GUI_TRIG_VLINE__CRTC2_GUI_TRIG_VLINE_STALL_MASK 0x40000000L
#define CRTC2_GUI_TRIG_VLINE__CRTC2_GUI_TRIG_VLINE_STALL   0x40000000L
#define CRTC2_GUI_TRIG_VLINE__CRTC2_GUI_TRIG_VLINE_MASK    0x80000000L
#define CRTC2_GUI_TRIG_VLINE__CRTC2_GUI_TRIG_VLINE         0x80000000L

// CRTC2_DEBUG
#define CRTC2_DEBUG__CRTC2_GUI_TRIG_BYPASS_EN_MASK         0x00000001L
#define CRTC2_DEBUG__CRTC2_GUI_TRIG_BYPASS_EN              0x00000001L
#define CRTC2_DEBUG__CRTC2_GUI_TRIG_VLINE_BYPASS_MASK      0x00000002L
#define CRTC2_DEBUG__CRTC2_GUI_TRIG_VLINE_BYPASS           0x00000002L
#define CRTC2_DEBUG__CRTC2_GUI_TRIG_OFFSET_BYPASS_MASK     0x00000004L
#define CRTC2_DEBUG__CRTC2_GUI_TRIG_OFFSET_BYPASS          0x00000004L
#define CRTC2_DEBUG__CRTC2_GUI_TRIG_PITCH_ADD_BYPASS_MASK  0x00000008L
#define CRTC2_DEBUG__CRTC2_GUI_TRIG_PITCH_ADD_BYPASS       0x00000008L

// CRTC2_OFFSET
#define CRTC2_OFFSET__CRTC2_OFFSET_MASK                    0x07ffffffL
#define CRTC2_OFFSET__CRTC2_GUI_TRIG_OFFSET_MASK           0x40000000L
#define CRTC2_OFFSET__CRTC2_GUI_TRIG_OFFSET                0x40000000L
#define CRTC2_OFFSET__CRTC2_OFFSET_LOCK_MASK               0x80000000L
#define CRTC2_OFFSET__CRTC2_OFFSET_LOCK                    0x80000000L

// CRTC2_OFFSET_CNTL
#define CRTC2_OFFSET_CNTL__CRTC2_TILE_LINE_MASK            0x0000000fL
#define CRTC2_OFFSET_CNTL__CRTC2_TILE_EN_MASK              0x00008000L
#define CRTC2_OFFSET_CNTL__CRTC2_TILE_EN                   0x00008000L
#define CRTC2_OFFSET_CNTL__CRTC2_OFFSET_FLIP_CNTL_MASK     0x00010000L
#define CRTC2_OFFSET_CNTL__CRTC2_OFFSET_FLIP_CNTL          0x00010000L
#define CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET_LEFT_EN_MASK 0x10000000L
#define CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET_LEFT_EN   0x10000000L
#define CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET_MASK      0x40000000L
#define CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET           0x40000000L
#define CRTC2_OFFSET_CNTL__CRTC2_OFFSET_LOCK_MASK          0x80000000L
#define CRTC2_OFFSET_CNTL__CRTC2_OFFSET_LOCK               0x80000000L

// CRTC2_PITCH
#define CRTC2_PITCH__CRTC2_PITCH_MASK                      0x000007ffL

// OVR2_CLR
#define OVR2_CLR__OVR2_CLR_B_MASK                          0x000000ffL
#define OVR2_CLR__OVR2_CLR_G_MASK                          0x0000ff00L
#define OVR2_CLR__OVR2_CLR_R_MASK                          0x00ff0000L

// OVR2_WID_LEFT_RIGHT
#define OVR2_WID_LEFT_RIGHT__OVR2_WID_RIGHT_MASK           0x0000007fL
#define OVR2_WID_LEFT_RIGHT__OVR2_WID_LEFT_MASK            0x007f0000L

// OVR2_WID_TOP_BOTTOM
#define OVR2_WID_TOP_BOTTOM__OVR2_WID_BOTTOM_MASK          0x000003ffL
#define OVR2_WID_TOP_BOTTOM__OVR2_WID_TOP_MASK             0x03ff0000L

// CRTC2_DISPLAY_BASE_ADDR
#define CRTC2_DISPLAY_BASE_ADDR__CRTC2_DISPLAY_BASE_ADDR_MASK 0xffffffffL

// SNAPSHOT2_VH_COUNTS
#define SNAPSHOT2_VH_COUNTS__SNAPSHOT2_HCOUNT_MASK         0x000003ffL
#define SNAPSHOT2_VH_COUNTS__SNAPSHOT2_VCOUNT_MASK         0x0fff0000L

// SNAPSHOT2_F_COUNT
#define SNAPSHOT2_F_COUNT__SNAPSHOT2_F_COUNT_MASK          0x001fffffL

// N_VIF2_COUNT
#define N_VIF2_COUNT__N_VIF2_COUNT_VAL_MASK                0x000003ffL
#define N_VIF2_COUNT__GENLOCK2_SOURCE_SEL_MASK             0x80000000L
#define N_VIF2_COUNT__GENLOCK2_SOURCE_SEL                  0x80000000L

// SNAPSHOT2_VIF_COUNT
#define SNAPSHOT2_VIF_COUNT__LSNAPSHOT2_VIF_COUNT_MASK     0x000003ffL
#define SNAPSHOT2_VIF_COUNT__USNAPSHOT2_VIF_COUNT_MASK     0x001ffc00L
#define SNAPSHOT2_VIF_COUNT__AUTO_SNAPSHOT2_TAKEN_RD_MASK  0x01000000L
#define SNAPSHOT2_VIF_COUNT__AUTO_SNAPSHOT2_TAKEN_RD       0x01000000L
#define SNAPSHOT2_VIF_COUNT__AUTO_SNAPSHOT2_TAKEN_WR_MASK  0x01000000L
#define SNAPSHOT2_VIF_COUNT__AUTO_SNAPSHOT2_TAKEN_WR       0x01000000L
#define SNAPSHOT2_VIF_COUNT__MANUAL_SNAPSHOT2_NOW_MASK     0x02000000L
#define SNAPSHOT2_VIF_COUNT__MANUAL_SNAPSHOT2_NOW          0x02000000L

// LVDS_DSTN_CNTL1
#define LVDS_DSTN_CNTL1__LVDS_PANEL_TYPE_MASK              0x00000003L
#define LVDS_DSTN_CNTL1__LVDS_PANEL_FORMAT_MASK            0x0000000cL
#define LVDS_DSTN_CNTL1__LVDS_NO_OF_GREY_MASK              0x00000070L
#define LVDS_DSTN_CNTL1__SCK_POL_MASK                      0x00000080L
#define LVDS_DSTN_CNTL1__SCK_POL                           0x00000080L
#define LVDS_DSTN_CNTL1__INVERSE_VIDEO_MASK                0x00000100L
#define LVDS_DSTN_CNTL1__INVERSE_VIDEO                     0x00000100L
#define LVDS_DSTN_CNTL1__BIASON_MASK                       0x00000200L
#define LVDS_DSTN_CNTL1__BIASON                            0x00000200L
#define LVDS_DSTN_CNTL1__XBUF_SIZE_MASK                    0x00003c00L
#define LVDS_DSTN_CNTL1__SCLK_DELAY_MASK                   0x0003c000L
#define LVDS_DSTN_CNTL1__HFB_TEST_MODE_MASK                0x00040000L
#define LVDS_DSTN_CNTL1__HFB_TEST_MODE                     0x00040000L
#define LVDS_DSTN_CNTL1__VERT_PANEL_SIZE_MASK              0x7ff80000L
#define LVDS_DSTN_CNTL1__USE_AUTO_FP_POS_MASK              0x80000000L
#define LVDS_DSTN_CNTL1__USE_AUTO_FP_POS                   0x80000000L

// LVDS_DSTN_CNTL2
#define LVDS_DSTN_CNTL2__BIAS_MODE_EN_MASK                 0x00000001L
#define LVDS_DSTN_CNTL2__BIAS_MODE_EN                      0x00000001L
#define LVDS_DSTN_CNTL2__BIAS_MODE_LEVEL_MASK              0x000001feL
#define LVDS_DSTN_CNTL2__LVDS_PWRSEQ_DELAY3_MASK           0x00001e00L
#define LVDS_DSTN_CNTL2__LOWER_PANEL_VPOS_MASK             0x01ffe000L
#define LVDS_DSTN_CNTL2__LH_POS_ADJUST_MASK                0x06000000L
#define LVDS_DSTN_CNTL2__DSTNFIFO_BURST_MASK               0x08000000L
#define LVDS_DSTN_CNTL2__DSTNFIFO_BURST                    0x08000000L

// LVDS_DSTN_CNTL3
#define LVDS_DSTN_CNTL3__XBUF_BASE_MASK                    0x0001ffffL
#define LVDS_DSTN_CNTL3__FP_POS_MASK                       0x1ffe0000L
#define LVDS_DSTN_CNTL3__DEBUG0_MASK                       0x20000000L
#define LVDS_DSTN_CNTL3__DEBUG0                            0x20000000L

// CUR2_OFFSET
#define CUR2_OFFSET__CUR2_OFFSET_MASK                      0x07ffffffL
#define CUR2_OFFSET__CUR2_LOCK_MASK                        0x80000000L
#define CUR2_OFFSET__CUR2_LOCK                             0x80000000L

// CUR2_HORZ_VERT_POSN
#define CUR2_HORZ_VERT_POSN__CUR2_VERT_POSN_MASK           0x00000fffL
#define CUR2_HORZ_VERT_POSN__CUR2_HORZ_POSN_MASK           0x3fff0000L
#define CUR2_HORZ_VERT_POSN__CUR2_LOCK_MASK                0x80000000L
#define CUR2_HORZ_VERT_POSN__CUR2_LOCK                     0x80000000L

// CUR2_HORZ_VERT_OFF
#define CUR2_HORZ_VERT_OFF__CUR2_VERT_OFF_MASK             0x0000003fL
#define CUR2_HORZ_VERT_OFF__CUR2_HORZ_OFF_MASK             0x003f0000L
#define CUR2_HORZ_VERT_OFF__CUR2_LOCK_MASK                 0x80000000L
#define CUR2_HORZ_VERT_OFF__CUR2_LOCK                      0x80000000L

// CUR2_CLR0
#define CUR2_CLR0__CUR2_CLR0_B_MASK                        0x000000ffL
#define CUR2_CLR0__CUR2_CLR0_G_MASK                        0x0000ff00L
#define CUR2_CLR0__CUR2_CLR0_R_MASK                        0x00ff0000L

// CUR2_CLR1
#define CUR2_CLR1__CUR2_CLR1_B_MASK                        0x000000ffL
#define CUR2_CLR1__CUR2_CLR1_G_MASK                        0x0000ff00L
#define CUR2_CLR1__CUR2_CLR1_R_MASK                        0x00ff0000L

// FP_H2_SYNC_STRT_WID
#define FP_H2_SYNC_STRT_WID__FP_H2_SYNC_STRT_PIX_MASK      0x00000007L
#define FP_H2_SYNC_STRT_WID__FP_H2_SYNC_STRT_CHAR_MASK     0x00001ff8L
#define FP_H2_SYNC_STRT_WID__FP_H2_SYNC_WID_MASK           0x003f0000L
#define FP_H2_SYNC_STRT_WID__FP_H2_SYNC_POL_MASK           0x00800000L
#define FP_H2_SYNC_STRT_WID__FP_H2_SYNC_POL                0x00800000L

// FP_V2_SYNC_STRT_WID
#define FP_V2_SYNC_STRT_WID__FP_V2_SYNC_STRT_MASK          0x00000fffL
#define FP_V2_SYNC_STRT_WID__FP_V2_SYNC_WID_MASK           0x001f0000L
#define FP_V2_SYNC_STRT_WID__FP_V2_SYNC_POL_MASK           0x00800000L
#define FP_V2_SYNC_STRT_WID__FP_V2_SYNC_POL                0x00800000L

// ICON2_OFFSET
#define ICON2_OFFSET__ICON2_OFFSET_MASK                    0x07ffffffL
#define ICON2_OFFSET__BLANK_SCREEN2_MASK                   0x08000000L
#define ICON2_OFFSET__BLANK_SCREEN2                        0x08000000L
#define ICON2_OFFSET__DONT_DS_ICON2_MASK                   0x10000000L
#define ICON2_OFFSET__DONT_DS_ICON2                        0x10000000L
#define ICON2_OFFSET__ICON2_LOCK_MASK                      0x80000000L
#define ICON2_OFFSET__ICON2_LOCK                           0x80000000L

// ICON2_HORZ_VERT_POSN
#define ICON2_HORZ_VERT_POSN__ICON2_VERT_POSN_MASK         0x00000fffL
#define ICON2_HORZ_VERT_POSN__ICON2_HORZ_POSN_MASK         0x0fff0000L
#define ICON2_HORZ_VERT_POSN__ICON2_LOCK_MASK              0x80000000L
#define ICON2_HORZ_VERT_POSN__ICON2_LOCK                   0x80000000L

// ICON2_HORZ_VERT_OFF
#define ICON2_HORZ_VERT_OFF__ICON2_VERT_OFF_MASK           0x0000007fL
#define ICON2_HORZ_VERT_OFF__ICON2_HORZ_OFF_MASK           0x007f0000L
#define ICON2_HORZ_VERT_OFF__ICON2_LOCK_MASK               0x80000000L
#define ICON2_HORZ_VERT_OFF__ICON2_LOCK                    0x80000000L

// ICON2_CLR0
#define ICON2_CLR0__ICON2_CLR0_B_MASK                      0x000000ffL
#define ICON2_CLR0__ICON2_CLR0_G_MASK                      0x0000ff00L
#define ICON2_CLR0__ICON2_CLR0_R_MASK                      0x00ff0000L

// ICON2_CLR1
#define ICON2_CLR1__ICON2_CLR1_B_MASK                      0x000000ffL
#define ICON2_CLR1__ICON2_CLR1_G_MASK                      0x0000ff00L
#define ICON2_CLR1__ICON2_CLR1_R_MASK                      0x00ff0000L

// GRPH2_BUFFER_CNTL
#define GRPH2_BUFFER_CNTL__GRPH2_START_REQ_MASK            0x0000007fL
#define GRPH2_BUFFER_CNTL__GRPH2_STOP_REQ_MASK             0x00007f00L
#define GRPH2_BUFFER_CNTL__GRPH2_CRITICAL_POINT_MASK       0x007f0000L
#define GRPH2_BUFFER_CNTL__GRPH2_CRITICAL_CNTL_MASK        0x10000000L
#define GRPH2_BUFFER_CNTL__GRPH2_CRITICAL_CNTL             0x10000000L
#define GRPH2_BUFFER_CNTL__GRPH2_BUFFER_SIZE_MASK          0x20000000L
#define GRPH2_BUFFER_CNTL__GRPH2_BUFFER_SIZE               0x20000000L
#define GRPH2_BUFFER_CNTL__GRPH2_CRITICAL_AT_SOF_MASK      0x40000000L
#define GRPH2_BUFFER_CNTL__GRPH2_CRITICAL_AT_SOF           0x40000000L
#define GRPH2_BUFFER_CNTL__GRPH2_STOP_CNTL_MASK            0x80000000L
#define GRPH2_BUFFER_CNTL__GRPH2_STOP_CNTL                 0x80000000L

// CRTC2_GEN_CNTL
#define CRTC2_GEN_CNTL__CRTC2_DBL_SCAN_EN_MASK             0x00000001L
#define CRTC2_GEN_CNTL__CRTC2_DBL_SCAN_EN                  0x00000001L
#define CRTC2_GEN_CNTL__CRTC2_INTERLACE_EN_MASK            0x00000002L
#define CRTC2_GEN_CNTL__CRTC2_INTERLACE_EN                 0x00000002L
#define CRTC2_GEN_CNTL__CRTC2_SYNC_TRISTATE_MASK           0x00000010L
#define CRTC2_GEN_CNTL__CRTC2_SYNC_TRISTATE                0x00000010L
#define CRTC2_GEN_CNTL__CRTC2_HSYNC_TRISTATE_MASK          0x00000020L
#define CRTC2_GEN_CNTL__CRTC2_HSYNC_TRISTATE               0x00000020L
#define CRTC2_GEN_CNTL__CRTC2_VSYNC_TRISTATE_MASK          0x00000040L
#define CRTC2_GEN_CNTL__CRTC2_VSYNC_TRISTATE               0x00000040L
#define CRTC2_GEN_CNTL__CRT2_ON_MASK                       0x00000080L
#define CRTC2_GEN_CNTL__CRT2_ON                            0x00000080L
#define CRTC2_GEN_CNTL__CRTC2_PIX_WIDTH_MASK               0x00000f00L
#define CRTC2_GEN_CNTL__CRTC2_ICON_EN_MASK                 0x00008000L
#define CRTC2_GEN_CNTL__CRTC2_ICON_EN                      0x00008000L
#define CRTC2_GEN_CNTL__CRTC2_CUR_EN_MASK                  0x00010000L
#define CRTC2_GEN_CNTL__CRTC2_CUR_EN                       0x00010000L
#define CRTC2_GEN_CNTL__CRTC2_CUR_MODE_MASK                0x00700000L
#define CRTC2_GEN_CNTL__CRTC2_DISPLAY_DIS_MASK             0x00800000L
#define CRTC2_GEN_CNTL__CRTC2_DISPLAY_DIS                  0x00800000L
#define CRTC2_GEN_CNTL__CRTC2_EN_MASK                      0x02000000L
#define CRTC2_GEN_CNTL__CRTC2_EN                           0x02000000L
#define CRTC2_GEN_CNTL__CRTC2_DISP_REQ_EN_B_MASK           0x04000000L
#define CRTC2_GEN_CNTL__CRTC2_DISP_REQ_EN_B                0x04000000L
#define CRTC2_GEN_CNTL__CRTC2_C_SYNC_EN_MASK               0x08000000L
#define CRTC2_GEN_CNTL__CRTC2_C_SYNC_EN                    0x08000000L
#define CRTC2_GEN_CNTL__CRTC2_HSYNC_DIS_MASK               0x10000000L
#define CRTC2_GEN_CNTL__CRTC2_HSYNC_DIS                    0x10000000L
#define CRTC2_GEN_CNTL__CRTC2_VSYNC_DIS_MASK               0x20000000L
#define CRTC2_GEN_CNTL__CRTC2_VSYNC_DIS                    0x20000000L

// CRTC2_STATUS
#define CRTC2_STATUS__CRTC2_VBLANK_CUR_MASK                0x00000001L
#define CRTC2_STATUS__CRTC2_VBLANK_CUR                     0x00000001L
#define CRTC2_STATUS__CRTC2_VBLANK_SAVE_MASK               0x00000002L
#define CRTC2_STATUS__CRTC2_VBLANK_SAVE                    0x00000002L
#define CRTC2_STATUS__CRTC2_VBLANK_SAVE_CLEAR_MASK         0x00000002L
#define CRTC2_STATUS__CRTC2_VBLANK_SAVE_CLEAR              0x00000002L
#define CRTC2_STATUS__CRTC2_VLINE_SYNC_MASK                0x00000004L
#define CRTC2_STATUS__CRTC2_VLINE_SYNC                     0x00000004L
#define CRTC2_STATUS__CRTC2_FRAME_MASK                     0x00000008L
#define CRTC2_STATUS__CRTC2_FRAME                          0x00000008L

// OV0_Y_X_START
#define OV0_Y_X_START__OV0_X_START_MASK                    0x00001fffL
#define OV0_Y_X_START__OV0_Y_START_MASK                    0x1fff0000L

// OV0_Y_X_END
#define OV0_Y_X_END__OV0_X_END_MASK                        0x00001fffL
#define OV0_Y_X_END__OV0_Y_END_MASK                        0x1fff0000L

// OV0_PIPELINE_CNTL
#define OV0_PIPELINE_CNTL__OV0_DISP_PIPE_DELAY_MASK        0x0000000fL

// OV0_REG_LOAD_CNTL
#define OV0_REG_LOAD_CNTL__OV0_LOCK_MASK                   0x00000001L
#define OV0_REG_LOAD_CNTL__OV0_LOCK                        0x00000001L
#define OV0_REG_LOAD_CNTL__OV0_VBLANK_DURING_LOCK_MASK     0x00000002L
#define OV0_REG_LOAD_CNTL__OV0_VBLANK_DURING_LOCK          0x00000002L
#define OV0_REG_LOAD_CNTL__OV0_STALL_GUI_UNTIL_FLIP_MASK   0x00000004L
#define OV0_REG_LOAD_CNTL__OV0_STALL_GUI_UNTIL_FLIP        0x00000004L
#define OV0_REG_LOAD_CNTL__OV0_LOCK_READBACK_MASK          0x00000008L
#define OV0_REG_LOAD_CNTL__OV0_LOCK_READBACK               0x00000008L
#define OV0_REG_LOAD_CNTL__OV0_FLIP_READBACK_MASK          0x00000010L
#define OV0_REG_LOAD_CNTL__OV0_FLIP_READBACK               0x00000010L

// OV0_SCALE_CNTL
#define OV0_SCALE_CNTL__OV0_NO_READ_BEHIND_SCAN_MASK       0x00000002L
#define OV0_SCALE_CNTL__OV0_NO_READ_BEHIND_SCAN            0x00000002L
#define OV0_SCALE_CNTL__OV0_HORZ_PICK_NEAREST_MASK         0x00000004L
#define OV0_SCALE_CNTL__OV0_HORZ_PICK_NEAREST              0x00000004L
#define OV0_SCALE_CNTL__OV0_VERT_PICK_NEAREST_MASK         0x00000008L
#define OV0_SCALE_CNTL__OV0_VERT_PICK_NEAREST              0x00000008L
#define OV0_SCALE_CNTL__OV0_SIGNED_UV_MASK                 0x00000010L
#define OV0_SCALE_CNTL__OV0_SIGNED_UV                      0x00000010L
#define OV0_SCALE_CNTL__OV0_GAMMA_SEL_MASK                 0x000000e0L
#define OV0_SCALE_CNTL__OV0_SURFACE_FORMAT_MASK            0x00000f00L
#define OV0_SCALE_CNTL__OV0_ADAPTIVE_DEINT_MASK            0x00001000L
#define OV0_SCALE_CNTL__OV0_ADAPTIVE_DEINT                 0x00001000L
#define OV0_SCALE_CNTL__OV0_CRTC_SEL_MASK                  0x00004000L
#define OV0_SCALE_CNTL__OV0_CRTC_SEL                       0x00004000L
#define OV0_SCALE_CNTL__OV0_BURST_PER_PLANE_MASK           0x007f0000L
#define OV0_SCALE_CNTL__OV0_DOUBLE_BUFFER_REGS_MASK        0x01000000L
#define OV0_SCALE_CNTL__OV0_DOUBLE_BUFFER_REGS             0x01000000L
#define OV0_SCALE_CNTL__OV0_BANDWIDTH_MASK                 0x04000000L
#define OV0_SCALE_CNTL__OV0_BANDWIDTH                      0x04000000L
#define OV0_SCALE_CNTL__OV0_LIN_TRANS_BYPASS_MASK          0x10000000L
#define OV0_SCALE_CNTL__OV0_LIN_TRANS_BYPASS               0x10000000L
#define OV0_SCALE_CNTL__OV0_INT_EMU_MASK                   0x20000000L
#define OV0_SCALE_CNTL__OV0_INT_EMU                        0x20000000L
#define OV0_SCALE_CNTL__OV0_OVERLAY_EN_MASK                0x40000000L
#define OV0_SCALE_CNTL__OV0_OVERLAY_EN                     0x40000000L
#define OV0_SCALE_CNTL__OV0_SOFT_RESET_MASK                0x80000000L
#define OV0_SCALE_CNTL__OV0_SOFT_RESET                     0x80000000L

// OV0_V_INC
#define OV0_V_INC__OV0_V_INC_MASK                          0x03ffff00L

// OV0_P1_V_ACCUM_INIT
#define OV0_P1_V_ACCUM_INIT__OV0_P1_MAX_LN_IN_PER_LN_OUT_MASK 0x00000003L
#define OV0_P1_V_ACCUM_INIT__OV0_P1_V_ACCUM_INIT_MASK      0x03ff8000L

// OV0_P23_V_ACCUM_INIT
#define OV0_P23_V_ACCUM_INIT__OV0_P23_MAX_LN_IN_PER_LN_OUT_MASK 0x00000003L
#define OV0_P23_V_ACCUM_INIT__OV0_P23_V_ACCUM_INIT_MASK    0x01ff8000L

// OV0_P1_BLANK_LINES_AT_TOP
#define OV0_P1_BLANK_LINES_AT_TOP__OV0_P1_BLNK_LN_AT_TOP_M1_MASK 0x00000fffL
#define OV0_P1_BLANK_LINES_AT_TOP__OV0_P1_ACTIVE_LINES_M1_MASK 0x0fff0000L

// OV0_P23_BLANK_LINES_AT_TOP
#define OV0_P23_BLANK_LINES_AT_TOP__OV0_P23_BLNK_LN_AT_TOP_M1_MASK 0x000007ffL
#define OV0_P23_BLANK_LINES_AT_TOP__OV0_P23_ACTIVE_LINES_M1_MASK 0x07ff0000L

// OV0_BASE_ADDR
#define OV0_BASE_ADDR__OV0_BASE_ADDR_MASK                  0xffffffffL

// OV0_VID_BUF0_BASE_ADRS
#define OV0_VID_BUF0_BASE_ADRS__OV0_VID_BUF_PITCH_SEL_MASK 0x00000001L
#define OV0_VID_BUF0_BASE_ADRS__OV0_VID_BUF_PITCH_SEL      0x00000001L
#define OV0_VID_BUF0_BASE_ADRS__RESERVED_BIT1_MASK         0x00000002L
#define OV0_VID_BUF0_BASE_ADRS__RESERVED_BIT1              0x00000002L
#define OV0_VID_BUF0_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_MASK 0x07fffff0L
#define OV0_VID_BUF0_BASE_ADRS__RESERVED_BIT31_28_MASK     0xf0000000L

// OV0_VID_BUF1_BASE_ADRS
#define OV0_VID_BUF1_BASE_ADRS__OV0_VID_BUF_PITCH_SEL_MASK 0x00000001L
#define OV0_VID_BUF1_BASE_ADRS__OV0_VID_BUF_PITCH_SEL      0x00000001L
#define OV0_VID_BUF1_BASE_ADRS__RESERVED_BIT1_MASK         0x00000002L
#define OV0_VID_BUF1_BASE_ADRS__RESERVED_BIT1              0x00000002L
#define OV0_VID_BUF1_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_MASK 0x07fffff0L
#define OV0_VID_BUF1_BASE_ADRS__RESERVED_BIT31_28_MASK     0xf0000000L

// OV0_VID_BUF2_BASE_ADRS
#define OV0_VID_BUF2_BASE_ADRS__OV0_VID_BUF_PITCH_SEL_MASK 0x00000001L
#define OV0_VID_BUF2_BASE_ADRS__OV0_VID_BUF_PITCH_SEL      0x00000001L
#define OV0_VID_BUF2_BASE_ADRS__RESERVED_BIT1_MASK         0x00000002L
#define OV0_VID_BUF2_BASE_ADRS__RESERVED_BIT1              0x00000002L
#define OV0_VID_BUF2_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_MASK 0x07fffff0L
#define OV0_VID_BUF2_BASE_ADRS__RESERVED_BIT31_28_MASK     0xf0000000L

// OV0_VID_BUF3_BASE_ADRS
#define OV0_VID_BUF3_BASE_ADRS__OV0_VID_BUF_PITCH_SEL_MASK 0x00000001L
#define OV0_VID_BUF3_BASE_ADRS__OV0_VID_BUF_PITCH_SEL      0x00000001L
#define OV0_VID_BUF3_BASE_ADRS__RESERVED_BIT1_MASK         0x00000002L
#define OV0_VID_BUF3_BASE_ADRS__RESERVED_BIT1              0x00000002L
#define OV0_VID_BUF3_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_MASK 0x07fffff0L
#define OV0_VID_BUF3_BASE_ADRS__RESERVED_BIT31_28_MASK     0xf0000000L

// OV0_VID_BUF4_BASE_ADRS
#define OV0_VID_BUF4_BASE_ADRS__OV0_VID_BUF_PITCH_SEL_MASK 0x00000001L
#define OV0_VID_BUF4_BASE_ADRS__OV0_VID_BUF_PITCH_SEL      0x00000001L
#define OV0_VID_BUF4_BASE_ADRS__RESERVED_BIT1_MASK         0x00000002L
#define OV0_VID_BUF4_BASE_ADRS__RESERVED_BIT1              0x00000002L
#define OV0_VID_BUF4_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_MASK 0x07fffff0L
#define OV0_VID_BUF4_BASE_ADRS__RESERVED_BIT31_28_MASK     0xf0000000L

// OV0_VID_BUF5_BASE_ADRS
#define OV0_VID_BUF5_BASE_ADRS__OV0_VID_BUF_PITCH_SEL_MASK 0x00000001L
#define OV0_VID_BUF5_BASE_ADRS__OV0_VID_BUF_PITCH_SEL      0x00000001L
#define OV0_VID_BUF5_BASE_ADRS__RESERVED_BIT1_MASK         0x00000002L
#define OV0_VID_BUF5_BASE_ADRS__RESERVED_BIT1              0x00000002L
#define OV0_VID_BUF5_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_MASK 0x07fffff0L
#define OV0_VID_BUF5_BASE_ADRS__RESERVED_BIT31_28_MASK     0xf0000000L

// OV0_VID_BUF_PITCH0_VALUE
#define OV0_VID_BUF_PITCH0_VALUE__OV0_PITCH_VALUE_MASK     0x000ffff0L
#define OV0_VID_BUF_PITCH0_VALUE__OV0_PITCH_SKIP_LINES_MASK 0x0c000000L
#define OV0_VID_BUF_PITCH0_VALUE__OV0_PITCH_IN_TILES_LSBS_MASK 0xf0000000L

// OV0_VID_BUF_PITCH1_VALUE
#define OV0_VID_BUF_PITCH1_VALUE__OV0_PITCH_VALUE_MASK     0x000ffff0L
#define OV0_VID_BUF_PITCH1_VALUE__OV0_PITCH_SKIP_LINES_MASK 0x0c000000L
#define OV0_VID_BUF_PITCH1_VALUE__OV0_PITCH_IN_TILES_LSBS_MASK 0xf0000000L

// OV0_AUTO_FLIP_CNTRL
#define OV0_AUTO_FLIP_CNTRL__OV0_SOFT_BUF_NUM_MASK         0x00000007L
#define OV0_AUTO_FLIP_CNTRL__OV0_SOFT_REPEAT_FIELD_MASK    0x00000008L
#define OV0_AUTO_FLIP_CNTRL__OV0_SOFT_REPEAT_FIELD         0x00000008L
#define OV0_AUTO_FLIP_CNTRL__OV0_SOFT_BUF_ODD_MASK         0x00000010L
#define OV0_AUTO_FLIP_CNTRL__OV0_SOFT_BUF_ODD              0x00000010L
#define OV0_AUTO_FLIP_CNTRL__OV0_IGNORE_REPEAT_FIELD_MASK  0x00000020L
#define OV0_AUTO_FLIP_CNTRL__OV0_IGNORE_REPEAT_FIELD       0x00000020L
#define OV0_AUTO_FLIP_CNTRL__OV0_SOFT_EOF_TOGGLE_MASK      0x00000040L
#define OV0_AUTO_FLIP_CNTRL__OV0_SOFT_EOF_TOGGLE           0x00000040L
#define OV0_AUTO_FLIP_CNTRL__OV0_VID_PORT_SELECT_MASK      0x00000300L
#define OV0_AUTO_FLIP_CNTRL__OV0_P1_FIRST_LINE_EVEN_MASK   0x00010000L
#define OV0_AUTO_FLIP_CNTRL__OV0_P1_FIRST_LINE_EVEN        0x00010000L
#define OV0_AUTO_FLIP_CNTRL__OV0_SHIFT_EVEN_DOWN_MASK      0x00040000L
#define OV0_AUTO_FLIP_CNTRL__OV0_SHIFT_EVEN_DOWN           0x00040000L
#define OV0_AUTO_FLIP_CNTRL__OV0_SHIFT_ODD_DOWN_MASK       0x00080000L
#define OV0_AUTO_FLIP_CNTRL__OV0_SHIFT_ODD_DOWN            0x00080000L
#define OV0_AUTO_FLIP_CNTRL__OV0_FIELD_POL_SOURCE_MASK     0x00800000L
#define OV0_AUTO_FLIP_CNTRL__OV0_FIELD_POL_SOURCE          0x00800000L

// OV0_DEINTERLACE_PATTERN
#define OV0_DEINTERLACE_PATTERN__OV0_DEINT_PAT_MASK        0x000fffffL
#define OV0_DEINTERLACE_PATTERN__OV0_DEINT_PAT_PNTR_MASK   0x0f000000L
#define OV0_DEINTERLACE_PATTERN__OV0_DEINT_PAT_LEN_M1_MASK 0xf0000000L

// OV0_SUBMIT_HISTORY
#define OV0_SUBMIT_HISTORY__OV0_NEXT_BUF_NUM_MASK          0x00000007L
#define OV0_SUBMIT_HISTORY__OV0_NEXT_IS_ODD_MASK           0x00000010L
#define OV0_SUBMIT_HISTORY__OV0_NEXT_IS_ODD                0x00000010L
#define OV0_SUBMIT_HISTORY__OV0_CURR_BUF_NUM_MASK          0x00000700L
#define OV0_SUBMIT_HISTORY__OV0_CURR_IS_ODD_MASK           0x00001000L
#define OV0_SUBMIT_HISTORY__OV0_CURR_IS_ODD                0x00001000L
#define OV0_SUBMIT_HISTORY__OV0_PREV_BUF_NUM_MASK          0x00070000L
#define OV0_SUBMIT_HISTORY__OV0_PREV_IS_ODD_MASK           0x00100000L
#define OV0_SUBMIT_HISTORY__OV0_PREV_IS_ODD                0x00100000L

// OV0_H_INC
#define OV0_H_INC__OV0_P1_H_INC_MASK                       0x00003fffL
#define OV0_H_INC__OV0_P23_H_INC_MASK                      0x3fff0000L

// OV0_STEP_BY
#define OV0_STEP_BY__OV0_P1_H_STEP_BY_MASK                 0x00000007L
#define OV0_STEP_BY__OV0_P1_PREDWNSC_RATIO_MASK            0x00000010L
#define OV0_STEP_BY__OV0_P1_PREDWNSC_RATIO                 0x00000010L
#define OV0_STEP_BY__OV0_P23_H_STEP_BY_MASK                0x00000700L
#define OV0_STEP_BY__OV0_P23_PREDWNSC_RATIO_MASK           0x00001000L
#define OV0_STEP_BY__OV0_P23_PREDWNSC_RATIO                0x00001000L

// OV0_P1_H_ACCUM_INIT
#define OV0_P1_H_ACCUM_INIT__OV0_P1_H_ACCUM_INIT_MASK      0x000f8000L
#define OV0_P1_H_ACCUM_INIT__OV0_PRESHIFT_P1_TO_MASK       0xf0000000L

// OV0_P23_H_ACCUM_INIT
#define OV0_P23_H_ACCUM_INIT__OV0_P23_H_ACCUM_INIT_MASK    0x000f8000L
#define OV0_P23_H_ACCUM_INIT__OV0_PRESHIFT_P23_TO_MASK     0x70000000L

// OV0_P1_X_START_END
#define OV0_P1_X_START_END__OV0_P1_X_END_MASK              0x00000fffL
#define OV0_P1_X_START_END__OV0_P1_X_START_MASK            0x000f0000L

// OV0_P2_X_START_END
#define OV0_P2_X_START_END__OV0_P2_X_END_MASK              0x000007ffL
#define OV0_P2_X_START_END__OV0_P2_X_START_MASK            0x000f0000L

// OV0_P3_X_START_END
#define OV0_P3_X_START_END__OV0_P3_X_END_MASK              0x000007ffL
#define OV0_P3_X_START_END__OV0_P3_X_START_MASK            0x000f0000L

// OV0_FILTER_CNTL
#define OV0_FILTER_CNTL__OV0_HC_COEF_ON_HORZ_Y_MASK        0x00000001L
#define OV0_FILTER_CNTL__OV0_HC_COEF_ON_HORZ_Y             0x00000001L
#define OV0_FILTER_CNTL__OV0_HC_COEF_ON_HORZ_UV_MASK       0x00000002L
#define OV0_FILTER_CNTL__OV0_HC_COEF_ON_HORZ_UV            0x00000002L
#define OV0_FILTER_CNTL__OV0_HC_COEF_ON_VERT_Y_MASK        0x00000004L
#define OV0_FILTER_CNTL__OV0_HC_COEF_ON_VERT_Y             0x00000004L
#define OV0_FILTER_CNTL__OV0_HC_COEF_ON_VERT_UV_MASK       0x00000008L
#define OV0_FILTER_CNTL__OV0_HC_COEF_ON_VERT_UV            0x00000008L

// OV0_FOUR_TAP_COEF_0
#define OV0_FOUR_TAP_COEF_0__OV0_COEF_0TH_TAP_MASK         0x0000000fL
#define OV0_FOUR_TAP_COEF_0__OV0_COEF_1ST_TAP_MASK         0x00007f00L
#define OV0_FOUR_TAP_COEF_0__OV0_COEF_2ND_TAP_MASK         0x007f0000L
#define OV0_FOUR_TAP_COEF_0__OV0_COEF_3RD_TAP_MASK         0x0f000000L

// OV0_FOUR_TAP_COEF_1
#define OV0_FOUR_TAP_COEF_1__OV0_COEF_0TH_TAP_MASK         0x0000000fL
#define OV0_FOUR_TAP_COEF_1__OV0_COEF_1ST_TAP_MASK         0x00007f00L
#define OV0_FOUR_TAP_COEF_1__OV0_COEF_2ND_TAP_MASK         0x007f0000L
#define OV0_FOUR_TAP_COEF_1__OV0_COEF_3RD_TAP_MASK         0x0f000000L

// OV0_FOUR_TAP_COEF_2
#define OV0_FOUR_TAP_COEF_2__OV0_COEF_0TH_TAP_MASK         0x0000000fL
#define OV0_FOUR_TAP_COEF_2__OV0_COEF_1ST_TAP_MASK         0x00007f00L
#define OV0_FOUR_TAP_COEF_2__OV0_COEF_2ND_TAP_MASK         0x007f0000L
#define OV0_FOUR_TAP_COEF_2__OV0_COEF_3RD_TAP_MASK         0x0f000000L

// OV0_FOUR_TAP_COEF_3
#define OV0_FOUR_TAP_COEF_3__OV0_COEF_0TH_TAP_MASK         0x0000000fL
#define OV0_FOUR_TAP_COEF_3__OV0_COEF_1ST_TAP_MASK         0x00007f00L
#define OV0_FOUR_TAP_COEF_3__OV0_COEF_2ND_TAP_MASK         0x007f0000L
#define OV0_FOUR_TAP_COEF_3__OV0_COEF_3RD_TAP_MASK         0x0f000000L

// OV0_FOUR_TAP_COEF_4
#define OV0_FOUR_TAP_COEF_4__OV0_COEF_0TH_TAP_MASK         0x0000000fL
#define OV0_FOUR_TAP_COEF_4__OV0_COEF_1ST_TAP_MASK         0x00007f00L
#define OV0_FOUR_TAP_COEF_4__OV0_COEF_2ND_TAP_MASK         0x007f0000L
#define OV0_FOUR_TAP_COEF_4__OV0_COEF_3RD_TAP_MASK         0x0f000000L

// OV0_FLAG_CNTRL
#define OV0_FLAG_CNTRL__OV0_HI_PRI_MCREQ_MASK              0x0000000fL
#define OV0_FLAG_CNTRL__OV0_HI_PRI_FORCE_MASK              0x00000100L
#define OV0_FLAG_CNTRL__OV0_HI_PRI_FORCE                   0x00000100L
#define OV0_FLAG_CNTRL__OV0_LUMA_10BIT_EN_MASK             0x00001000L
#define OV0_FLAG_CNTRL__OV0_LUMA_10BIT_EN                  0x00001000L
#define OV0_FLAG_CNTRL__OV0_CHROMA_10BIT_EN_MASK           0x00002000L
#define OV0_FLAG_CNTRL__OV0_CHROMA_10BIT_EN                0x00002000L

// OV0_SLICE_CNTL
#define OV0_SLICE_CNTL__OV0_SLICE_LAST_LINE_MASK           0x0000007fL
#define OV0_SLICE_CNTL__OV0_SLICEDONE_STAT_MASK            0x40000000L
#define OV0_SLICE_CNTL__OV0_SLICEDONE_STAT                 0x40000000L
#define OV0_SLICE_CNTL__OV0_MPEG_EOF_TOGGLE_MASK           0x80000000L
#define OV0_SLICE_CNTL__OV0_MPEG_EOF_TOGGLE                0x80000000L

// OV0_VID_KEY_CLR_LOW
#define OV0_VID_KEY_CLR_LOW__OV0_VID_KEY_Cb_BLUE_LOW_MASK  0x000003ffL
#define OV0_VID_KEY_CLR_LOW__OV0_VID_KEY_Y_GREEN_LOW_MASK  0x000ffc00L
#define OV0_VID_KEY_CLR_LOW__OV0_VID_KEY_Cr_RED_LOW_MASK   0x3ff00000L

// OV0_VID_KEY_CLR_HIGH
#define OV0_VID_KEY_CLR_HIGH__OV0_VID_KEY_Cb_BLUE_HIGH_MASK 0x000003ffL
#define OV0_VID_KEY_CLR_HIGH__OV0_VID_KEY_Y_GREEN_HIGH_MASK 0x000ffc00L
#define OV0_VID_KEY_CLR_HIGH__OV0_VID_KEY_Cr_RED_HIGH_MASK 0x3ff00000L

// OV0_GRPH_KEY_CLR_LOW
#define OV0_GRPH_KEY_CLR_LOW__OV0_GRPH_KEY_BLUE_LOW_MASK   0x000000ffL
#define OV0_GRPH_KEY_CLR_LOW__OV0_GRPH_KEY_GREEN_LOW_MASK  0x0000ff00L
#define OV0_GRPH_KEY_CLR_LOW__OV0_GRPH_KEY_RED_LOW_MASK    0x00ff0000L
#define OV0_GRPH_KEY_CLR_LOW__OV0_GRPH_KEY_ALPHA_LOW_MASK  0xff000000L

// OV0_GRPH_KEY_CLR_HIGH
#define OV0_GRPH_KEY_CLR_HIGH__OV0_GRPH_KEY_BLUE_HIGH_MASK 0x000000ffL
#define OV0_GRPH_KEY_CLR_HIGH__OV0_GRPH_KEY_GREEN_HIGH_MASK 0x0000ff00L
#define OV0_GRPH_KEY_CLR_HIGH__OV0_GRPH_KEY_RED_HIGH_MASK  0x00ff0000L
#define OV0_GRPH_KEY_CLR_HIGH__OV0_GRPH_KEY_ALPHA_HIGH_MASK 0xff000000L

// OV0_KEY_CNTL
#define OV0_KEY_CNTL__OV0_VIDEO_KEY_FN_MASK                0x00000003L
#define OV0_KEY_CNTL__OV0_GRAPHICS_KEY_FN_MASK             0x00000030L
#define OV0_KEY_CNTL__OV0_CMP_MIX_MASK                     0x00000100L
#define OV0_KEY_CNTL__OV0_CMP_MIX                          0x00000100L

// OV0_TEST
#define OV0_TEST__OV0_MIN_OFFSET_EN_MASK                   0x00000002L
#define OV0_TEST__OV0_MIN_OFFSET_EN                        0x00000002L
#define OV0_TEST__OV0_SUBPIC_ONLY_MASK                     0x00000008L
#define OV0_TEST__OV0_SUBPIC_ONLY                          0x00000008L
#define OV0_TEST__OV0_SWAP_UV_MASK                         0x00000020L
#define OV0_TEST__OV0_SWAP_UV                              0x00000020L
#define OV0_TEST__OV0_NOROUNDUP_MASK                       0x00000040L
#define OV0_TEST__OV0_NOROUNDUP                            0x00000040L
#define OV0_TEST__OV0_ADAPTIVE_DEINT_ADJ_MASK              0x00003000L
#define OV0_TEST__OV0_READ_BEHIND_SCAN_MARGIN_MASK         0x007f0000L

// OV1_Y_X_START
#define OV1_Y_X_START__OV1_X_START_MASK                    0x00001fffL
#define OV1_Y_X_START__OV1_Y_START_MASK                    0x1fff0000L

// OV1_Y_X_END
#define OV1_Y_X_END__OV1_X_END_MASK                        0x00001fffL
#define OV1_Y_X_END__OV1_Y_END_MASK                        0x1fff0000L

// OV1_PIPELINE_CNTL
#define OV1_PIPELINE_CNTL__OV1_DISP_PIPE_DELAY_MASK        0x0000000fL

// DISP_MISC_CNTL
#define DISP_MISC_CNTL__SOFT_RESET_GRPH_PP_MASK            0x00000001L
#define DISP_MISC_CNTL__SOFT_RESET_GRPH_PP                 0x00000001L
#define DISP_MISC_CNTL__SOFT_RESET_SUBPIC_PP_MASK          0x00000002L
#define DISP_MISC_CNTL__SOFT_RESET_SUBPIC_PP               0x00000002L
#define DISP_MISC_CNTL__SOFT_RESET_OV0_PP_MASK             0x00000004L
#define DISP_MISC_CNTL__SOFT_RESET_OV0_PP                  0x00000004L
#define DISP_MISC_CNTL__SOFT_RESET_GRPH_SCLK_MASK          0x00000010L
#define DISP_MISC_CNTL__SOFT_RESET_GRPH_SCLK               0x00000010L
#define DISP_MISC_CNTL__SOFT_RESET_SUBPIC_SCLK_MASK        0x00000020L
#define DISP_MISC_CNTL__SOFT_RESET_SUBPIC_SCLK             0x00000020L
#define DISP_MISC_CNTL__SOFT_RESET_OV0_SCLK_MASK           0x00000040L
#define DISP_MISC_CNTL__SOFT_RESET_OV0_SCLK                0x00000040L
#define DISP_MISC_CNTL__SYNC_STRENGTH_MASK                 0x00000300L
#define DISP_MISC_CNTL__SYNC_PAD_FLOP_EN_MASK              0x00000400L
#define DISP_MISC_CNTL__SYNC_PAD_FLOP_EN                   0x00000400L
#define DISP_MISC_CNTL__SOFT_RESET_GRPH2_PP_MASK           0x00001000L
#define DISP_MISC_CNTL__SOFT_RESET_GRPH2_PP                0x00001000L
#define DISP_MISC_CNTL__SOFT_RESET_GRPH2_SCLK_MASK         0x00008000L
#define DISP_MISC_CNTL__SOFT_RESET_GRPH2_SCLK              0x00008000L
#define DISP_MISC_CNTL__SOFT_RESET_LVDS_MASK               0x00010000L
#define DISP_MISC_CNTL__SOFT_RESET_LVDS                    0x00010000L
#define DISP_MISC_CNTL__SOFT_RESET_TMDS_MASK               0x00020000L
#define DISP_MISC_CNTL__SOFT_RESET_TMDS                    0x00020000L
#define DISP_MISC_CNTL__SOFT_RESET_DIG_TMDS_MASK           0x00040000L
#define DISP_MISC_CNTL__SOFT_RESET_DIG_TMDS                0x00040000L
#define DISP_MISC_CNTL__SOFT_RESET_TV_MASK                 0x00080000L
#define DISP_MISC_CNTL__SOFT_RESET_TV                      0x00080000L
#define DISP_MISC_CNTL__PALETTE2_MEM_RD_MARGIN_MASK        0x00f00000L
#define DISP_MISC_CNTL__PALETTE_MEM_RD_MARGIN_MASK         0x0f000000L
#define DISP_MISC_CNTL__RMX_BUF_MEM_RD_MARGIN_MASK         0xf0000000L

// DAC_MACRO_CNTL
#define DAC_MACRO_CNTL__DAC_WHITE_CNTL_MASK                0x0000000fL
#define DAC_MACRO_CNTL__DAC_BG_ADJ_MASK                    0x00000f00L
#define DAC_MACRO_CNTL__DAC_PDWN_R_MASK                    0x00010000L
#define DAC_MACRO_CNTL__DAC_PDWN_R                         0x00010000L
#define DAC_MACRO_CNTL__DAC_PDWN_G_MASK                    0x00020000L
#define DAC_MACRO_CNTL__DAC_PDWN_G                         0x00020000L
#define DAC_MACRO_CNTL__DAC_PDWN_B_MASK                    0x00040000L
#define DAC_MACRO_CNTL__DAC_PDWN_B                         0x00040000L

// DISP_PWR_MAN
#define DISP_PWR_MAN__DISP_PWR_MAN_D3_CRTC_EN_MASK         0x00000001L
#define DISP_PWR_MAN__DISP_PWR_MAN_D3_CRTC_EN              0x00000001L
#define DISP_PWR_MAN__DISP2_PWR_MAN_D3_CRTC2_EN_MASK       0x00000010L
#define DISP_PWR_MAN__DISP2_PWR_MAN_D3_CRTC2_EN            0x00000010L
#define DISP_PWR_MAN__DISP_PWR_MAN_DPMS_MASK               0x00000300L
#define DISP_PWR_MAN__DISP_D3_RST_MASK                     0x00010000L
#define DISP_PWR_MAN__DISP_D3_RST                          0x00010000L
#define DISP_PWR_MAN__DISP_D3_REG_RST_MASK                 0x00020000L
#define DISP_PWR_MAN__DISP_D3_REG_RST                      0x00020000L
#define DISP_PWR_MAN__DISP_D3_GRPH_RST_MASK                0x00040000L
#define DISP_PWR_MAN__DISP_D3_GRPH_RST                     0x00040000L
#define DISP_PWR_MAN__DISP_D3_SUBPIC_RST_MASK              0x00080000L
#define DISP_PWR_MAN__DISP_D3_SUBPIC_RST                   0x00080000L
#define DISP_PWR_MAN__DISP_D3_OV0_RST_MASK                 0x00100000L
#define DISP_PWR_MAN__DISP_D3_OV0_RST                      0x00100000L
#define DISP_PWR_MAN__DISP_D1D2_GRPH_RST_MASK              0x00200000L
#define DISP_PWR_MAN__DISP_D1D2_GRPH_RST                   0x00200000L
#define DISP_PWR_MAN__DISP_D1D2_SUBPIC_RST_MASK            0x00400000L
#define DISP_PWR_MAN__DISP_D1D2_SUBPIC_RST                 0x00400000L
#define DISP_PWR_MAN__DISP_D1D2_OV0_RST_MASK               0x00800000L
#define DISP_PWR_MAN__DISP_D1D2_OV0_RST                    0x00800000L
#define DISP_PWR_MAN__DIG_TMDS_ENABLE_RST_MASK             0x01000000L
#define DISP_PWR_MAN__DIG_TMDS_ENABLE_RST                  0x01000000L
#define DISP_PWR_MAN__TV_ENABLE_RST_MASK                   0x02000000L
#define DISP_PWR_MAN__TV_ENABLE_RST                        0x02000000L
#define DISP_PWR_MAN__AUTO_PWRUP_EN_MASK                   0x04000000L
#define DISP_PWR_MAN__AUTO_PWRUP_EN                        0x04000000L

// DISP_TEST_DEBUG_CNTL
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_DISPENG_MASK       0x00000001L
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_DISPENG            0x00000001L
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_PALETTE_MASK       0x00000002L
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_PALETTE            0x00000002L
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_DAC_MASK           0x00000004L
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_DAC                0x00000004L
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_OV0SCALE_MASK      0x00000010L
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_OV0SCALE           0x00000010L
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_CLK_MASK           0x00000020L
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_CLK                0x00000020L
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_DISP2ENG_MASK      0x00000100L
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_DISP2ENG           0x00000100L
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_PALETTE2_MASK      0x00000200L
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_PALETTE2           0x00000200L
#define DISP_TEST_DEBUG_CNTL__DISP_GRPH2_UNDERFLOW_MASK    0x00010000L
#define DISP_TEST_DEBUG_CNTL__DISP_GRPH2_UNDERFLOW         0x00010000L
#define DISP_TEST_DEBUG_CNTL__DISP_GRPH2_UNDERFLOW_CLR_MASK 0x00010000L
#define DISP_TEST_DEBUG_CNTL__DISP_GRPH2_UNDERFLOW_CLR     0x00010000L
#define DISP_TEST_DEBUG_CNTL__DISP_CUR2_UNDERFLOW_MASK     0x00020000L
#define DISP_TEST_DEBUG_CNTL__DISP_CUR2_UNDERFLOW          0x00020000L
#define DISP_TEST_DEBUG_CNTL__DISP_CUR2_UNDERFLOW_CLR_MASK 0x00020000L
#define DISP_TEST_DEBUG_CNTL__DISP_CUR2_UNDERFLOW_CLR      0x00020000L
#define DISP_TEST_DEBUG_CNTL__DISP_GRPH_UNDERFLOW_MASK     0x01000000L
#define DISP_TEST_DEBUG_CNTL__DISP_GRPH_UNDERFLOW          0x01000000L
#define DISP_TEST_DEBUG_CNTL__DISP_GRPH_UNDERFLOW_CLR_MASK 0x01000000L
#define DISP_TEST_DEBUG_CNTL__DISP_GRPH_UNDERFLOW_CLR      0x01000000L
#define DISP_TEST_DEBUG_CNTL__DISP_CUR_UNDERFLOW_MASK      0x02000000L
#define DISP_TEST_DEBUG_CNTL__DISP_CUR_UNDERFLOW           0x02000000L
#define DISP_TEST_DEBUG_CNTL__DISP_CUR_UNDERFLOW_CLR_MASK  0x02000000L
#define DISP_TEST_DEBUG_CNTL__DISP_CUR_UNDERFLOW_CLR       0x02000000L
#define DISP_TEST_DEBUG_CNTL__DISP_OV0_UNDERFLOW_MASK      0x04000000L
#define DISP_TEST_DEBUG_CNTL__DISP_OV0_UNDERFLOW           0x04000000L
#define DISP_TEST_DEBUG_CNTL__DISP_OV0_UNDERFLOW_CLR_MASK  0x04000000L
#define DISP_TEST_DEBUG_CNTL__DISP_OV0_UNDERFLOW_CLR       0x04000000L

// DISP_HW_DEBUG
#define DISP_HW_DEBUG__DISP_HW_0_DEBUG_MASK                0x00000001L
#define DISP_HW_DEBUG__DISP_HW_0_DEBUG                     0x00000001L
#define DISP_HW_DEBUG__DISP_HW_1_DEBUG_MASK                0x00000002L
#define DISP_HW_DEBUG__DISP_HW_1_DEBUG                     0x00000002L
#define DISP_HW_DEBUG__DISP_HW_2_DEBUG_MASK                0x00000004L
#define DISP_HW_DEBUG__DISP_HW_2_DEBUG                     0x00000004L
#define DISP_HW_DEBUG__DISP_HW_3_DEBUG_MASK                0x00000008L
#define DISP_HW_DEBUG__DISP_HW_3_DEBUG                     0x00000008L
#define DISP_HW_DEBUG__DISP_HW_4_DEBUG_MASK                0x00000010L
#define DISP_HW_DEBUG__DISP_HW_4_DEBUG                     0x00000010L
#define DISP_HW_DEBUG__CRT2_DISP1_SEL_MASK                 0x00000020L
#define DISP_HW_DEBUG__CRT2_DISP1_SEL                      0x00000020L
#define DISP_HW_DEBUG__DISP_HW_6_DEBUG_MASK                0x00000040L
#define DISP_HW_DEBUG__DISP_HW_6_DEBUG                     0x00000040L
#define DISP_HW_DEBUG__DISP_HW_7_DEBUG_MASK                0x00000080L
#define DISP_HW_DEBUG__DISP_HW_7_DEBUG                     0x00000080L
#define DISP_HW_DEBUG__DISP_HW_8_DEBUG_MASK                0x00000100L
#define DISP_HW_DEBUG__DISP_HW_8_DEBUG                     0x00000100L
#define DISP_HW_DEBUG__DISP_HW_9_DEBUG_MASK                0x00000200L
#define DISP_HW_DEBUG__DISP_HW_9_DEBUG                     0x00000200L
#define DISP_HW_DEBUG__DISP_HW_A_DEBUG_MASK                0x00000400L
#define DISP_HW_DEBUG__DISP_HW_A_DEBUG                     0x00000400L
#define DISP_HW_DEBUG__DISP_HW_B_DEBUG_MASK                0x00000800L
#define DISP_HW_DEBUG__DISP_HW_B_DEBUG                     0x00000800L
#define DISP_HW_DEBUG__DISP_HW_C_DEBUG_MASK                0x00001000L
#define DISP_HW_DEBUG__DISP_HW_C_DEBUG                     0x00001000L
#define DISP_HW_DEBUG__DISP_HW_D_DEBUG_MASK                0x00002000L
#define DISP_HW_DEBUG__DISP_HW_D_DEBUG                     0x00002000L
#define DISP_HW_DEBUG__DISP_HW_E_DEBUG_MASK                0x00004000L
#define DISP_HW_DEBUG__DISP_HW_E_DEBUG                     0x00004000L
#define DISP_HW_DEBUG__DISP_HW_F_DEBUG_MASK                0x00008000L
#define DISP_HW_DEBUG__DISP_HW_F_DEBUG                     0x00008000L
#define DISP_HW_DEBUG__DISP_HW_10_DEBUG_MASK               0x00010000L
#define DISP_HW_DEBUG__DISP_HW_10_DEBUG                    0x00010000L
#define DISP_HW_DEBUG__DISP_HW_11_DEBUG_MASK               0x00020000L
#define DISP_HW_DEBUG__DISP_HW_11_DEBUG                    0x00020000L

// DAC_CRC_SIG1
#define DAC_CRC_SIG1__DAC_CRC_SIG_B_MASK                   0x000003ffL
#define DAC_CRC_SIG1__DAC_CRC_SIG_G_MASK                   0x03ff0000L

// DAC_CRC_SIG2
#define DAC_CRC_SIG2__DAC_CRC_SIG_R_MASK                   0x000003ffL
#define DAC_CRC_SIG2__DAC_CRC_SIG_C_MASK                   0x003f0000L

// OV0_LIN_TRANS_A
#define OV0_LIN_TRANS_A__OV0_LIN_TRANS_Cb_R_M6_MASK        0x0000fff0L
#define OV0_LIN_TRANS_A__OV0_LIN_TRANS_Y_R_M6_MASK         0xfff00000L

// OV0_LIN_TRANS_B
#define OV0_LIN_TRANS_B__OV0_LIN_TRANS_OFF_R_MASK          0x00001fffL
#define OV0_LIN_TRANS_B__OV0_LIN_TRANS_Cr_R_M6_MASK        0xfff00000L

// OV0_LIN_TRANS_C
#define OV0_LIN_TRANS_C__OV0_LIN_TRANS_Cb_G_M6_MASK        0x0000fff0L
#define OV0_LIN_TRANS_C__OV0_LIN_TRANS_Y_G_M6_MASK         0xfff00000L

// OV0_LIN_TRANS_D
#define OV0_LIN_TRANS_D__OV0_LIN_TRANS_OFF_G_MASK          0x00001fffL
#define OV0_LIN_TRANS_D__OV0_LIN_TRANS_Cr_G_M6_MASK        0xfff00000L

// OV0_LIN_TRANS_E
#define OV0_LIN_TRANS_E__OV0_LIN_TRANS_Cb_B_M6_MASK        0x0000fff0L
#define OV0_LIN_TRANS_E__OV0_LIN_TRANS_Y_B_M6_MASK         0xfff00000L

// OV0_LIN_TRANS_F
#define OV0_LIN_TRANS_F__OV0_LIN_TRANS_OFF_B_MASK          0x00001fffL
#define OV0_LIN_TRANS_F__OV0_LIN_TRANS_Cr_B_M6_MASK        0xfff00000L

// OV0_GAMMA_0_F
#define OV0_GAMMA_0_F__OV0_GAMMA_0_F_OFFSET_MASK           0x000001ffL
#define OV0_GAMMA_0_F__OV0_GAMMA_0_F_SLOPE_MASK            0x07ff0000L

// OV0_GAMMA_10_1F
#define OV0_GAMMA_10_1F__OV0_GAMMA_10_1F_OFFSET_MASK       0x000001ffL
#define OV0_GAMMA_10_1F__OV0_GAMMA_10_1F_SLOPE_MASK        0x07ff0000L

// OV0_GAMMA_20_3F
#define OV0_GAMMA_20_3F__OV0_GAMMA_20_3F_OFFSET_MASK       0x000003ffL
#define OV0_GAMMA_20_3F__OV0_GAMMA_20_3F_SLOPE_MASK        0x03ff0000L

// OV0_GAMMA_40_7F
#define OV0_GAMMA_40_7F__OV0_GAMMA_40_7F_OFFSET_MASK       0x000003ffL
#define OV0_GAMMA_40_7F__OV0_GAMMA_40_7F_SLOPE_MASK        0x01ff0000L

// OV0_GAMMA_380_3BF
#define OV0_GAMMA_380_3BF__OV0_GAMMA_380_3BF_OFFSET_MASK   0x000001ffL
#define OV0_GAMMA_380_3BF__OV0_GAMMA_380_3BF_SLOPE_MASK    0x01ff0000L

// OV0_GAMMA_3C0_3FF
#define OV0_GAMMA_3C0_3FF__OV0_GAMMA_3C0_3FF_OFFSET_MASK   0x000001ffL
#define OV0_GAMMA_3C0_3FF__OV0_GAMMA_3C0_3FF_SLOPE_MASK    0x01ff0000L

// DISP_MERGE_CNTL
#define DISP_MERGE_CNTL__DISP_ALPHA_MODE_MASK              0x00000003L
#define DISP_MERGE_CNTL__DISP_ALPHA_INV_MASK               0x00000004L
#define DISP_MERGE_CNTL__DISP_ALPHA_INV                    0x00000004L
#define DISP_MERGE_CNTL__DISP_ALPHA_PREMULT_MASK           0x00000008L
#define DISP_MERGE_CNTL__DISP_ALPHA_PREMULT                0x00000008L
#define DISP_MERGE_CNTL__DISP_RGB_OFFSET_EN_MASK           0x00000100L
#define DISP_MERGE_CNTL__DISP_RGB_OFFSET_EN                0x00000100L
#define DISP_MERGE_CNTL__DISP_GRPH_ALPHA_MASK              0x00ff0000L
#define DISP_MERGE_CNTL__DISP_OV0_ALPHA_MASK               0xff000000L

// DISP_OUTPUT_CNTL
#define DISP_OUTPUT_CNTL__DISP_DAC_SOURCE_MASK             0x00000003L
#define DISP_OUTPUT_CNTL__DISP_RMX_SOURCE_MASK             0x00000100L
#define DISP_OUTPUT_CNTL__DISP_RMX_SOURCE                  0x00000100L
#define DISP_OUTPUT_CNTL__DISP_RMX_DITH_EN_MASK            0x00000400L
#define DISP_OUTPUT_CNTL__DISP_RMX_DITH_EN                 0x00000400L
#define DISP_OUTPUT_CNTL__DISP_TV_EVEN_FLAG_CNTL_MASK      0x18000000L

// DISP2_MERGE_CNTL
#define DISP2_MERGE_CNTL__DISP2_RGB_OFFSET_EN_MASK         0x00000100L
#define DISP2_MERGE_CNTL__DISP2_RGB_OFFSET_EN              0x00000100L

// DAC_CRC2_SIG1
#define DAC_CRC2_SIG1__DAC_CRC2_SIG_B_MASK                 0x000003ffL
#define DAC_CRC2_SIG1__DAC_CRC2_SIG_G_MASK                 0x03ff0000L

// DAC_CRC2_SIG2
#define DAC_CRC2_SIG2__DAC_CRC2_SIG_R_MASK                 0x000003ffL
#define DAC_CRC2_SIG2__DAC_CRC2_SIG_C_MASK                 0x003f0000L

// RMX_HORZ_PHASE
#define RMX_HORZ_PHASE__RMX_HORZ_START_PHASE_MASK          0x00000fffL
#define RMX_HORZ_PHASE__RMX_H_ACC_INIT_MASK                0x00001000L
#define RMX_HORZ_PHASE__RMX_H_ACC_INIT                     0x00001000L
#define RMX_HORZ_PHASE__RMX_V_ACC_INIT_MASK                0x00002000L
#define RMX_HORZ_PHASE__RMX_V_ACC_INIT                     0x00002000L
#define RMX_HORZ_PHASE__RMX_VERT_START_PHASE_MASK          0x0fff0000L

// HDCP_GEN_CNTL
#define HDCP_GEN_CNTL__HDCP_AUTHORIZED_INT_STAT_MASK       0x00000001L
#define HDCP_GEN_CNTL__HDCP_AUTHORIZED_INT_STAT            0x00000001L
#define HDCP_GEN_CNTL__HDCP_AUTHORIZED_INT_AK_MASK         0x00000001L
#define HDCP_GEN_CNTL__HDCP_AUTHORIZED_INT_AK              0x00000001L
#define HDCP_GEN_CNTL__HDCP_AUTHORIZED_INT_POL_MASK        0x00000002L
#define HDCP_GEN_CNTL__HDCP_AUTHORIZED_INT_POL             0x00000002L
#define HDCP_GEN_CNTL__HDCP_AUTHORIZED_INT_MASK_MASK       0x00000004L
#define HDCP_GEN_CNTL__HDCP_AUTHORIZED_INT_MASK            0x00000004L
#define HDCP_GEN_CNTL__HOT_PLUG_AFFECTS_HDCP_EN_MASK       0x00000008L
#define HDCP_GEN_CNTL__HOT_PLUG_AFFECTS_HDCP_EN            0x00000008L
#define HDCP_GEN_CNTL__HDCP_AUTHORIZED_MASK                0x00000010L
#define HDCP_GEN_CNTL__HDCP_AUTHORIZED                     0x00000010L
#define HDCP_GEN_CNTL__HDCP_RESET_MASK                     0x00000020L
#define HDCP_GEN_CNTL__HDCP_RESET                          0x00000020L
#define HDCP_GEN_CNTL__HDCP_I2C_SCL_DRIVE_EN_MASK          0x00000040L
#define HDCP_GEN_CNTL__HDCP_I2C_SCL_DRIVE_EN               0x00000040L
#define HDCP_GEN_CNTL__HDCP_I2C_SDA_DRIVE_EN_MASK          0x00000080L
#define HDCP_GEN_CNTL__HDCP_I2C_SDA_DRIVE_EN               0x00000080L
#define HDCP_GEN_CNTL__HDCP_I2C_TIME_LIMIT_MASK            0x0000ff00L
#define HDCP_GEN_CNTL__HDCP_I2C_PRESCALE_MASK              0xffff0000L

// HDCP_CONTROL
#define HDCP_CONTROL__HDCP_CONTROL_MASK                    0xffffffffL

// HDCP_DATA_UPPER
#define HDCP_DATA_UPPER__HDCP_DATA_UPPER_MASK              0xffffffffL

// HDCP_DATA_LOWER
#define HDCP_DATA_LOWER__HDCP_DATA_LOWER_MASK              0xffffffffL

// HDCP_DEBUG
#define HDCP_DEBUG__HDCP_DEBUG_EN_MASK                     0x00000001L
#define HDCP_DEBUG__HDCP_DEBUG_EN                          0x00000001L
#define HDCP_DEBUG__I2C_CNTL_REGS_AFFECT_HDCP_I2C_MASK     0x00000002L
#define HDCP_DEBUG__I2C_CNTL_REGS_AFFECT_HDCP_I2C          0x00000002L
#define HDCP_DEBUG__SW_CAN_QUEUE_I2C_GO_MASK               0x00000004L
#define HDCP_DEBUG__SW_CAN_QUEUE_I2C_GO                    0x00000004L
#define HDCP_DEBUG__USE_HDCP_I2C_SHORT_READS_MASK          0x00000008L
#define HDCP_DEBUG__USE_HDCP_I2C_SHORT_READS               0x00000008L
#define HDCP_DEBUG__HDCP_DEBUG_BIT4_MASK                   0x00000010L
#define HDCP_DEBUG__HDCP_DEBUG_BIT4                        0x00000010L
#define HDCP_DEBUG__HDCP_DEBUG_BIT5_MASK                   0x00000020L
#define HDCP_DEBUG__HDCP_DEBUG_BIT5                        0x00000020L
#define HDCP_DEBUG__HDCP_DEBUG_BIT6_MASK                   0x00000040L
#define HDCP_DEBUG__HDCP_DEBUG_BIT6                        0x00000040L
#define HDCP_DEBUG__HDCP_DEBUG_BIT7_MASK                   0x00000080L
#define HDCP_DEBUG__HDCP_DEBUG_BIT7                        0x00000080L
#define HDCP_DEBUG__HDCP_DEBUG_ADDR_MASK                   0x0000ff00L
#define HDCP_DEBUG__HDCP_DEBUG_DATA_MASK                   0xffff0000L

// CLOCK_CNTL_INDEX
#define CLOCK_CNTL_INDEX__PLL_ADDR_M6_MASK                 0x0000003fL
#define CLOCK_CNTL_INDEX__PLL_WR_EN_MASK                   0x00000080L
#define CLOCK_CNTL_INDEX__PLL_WR_EN                        0x00000080L
#define CLOCK_CNTL_INDEX__PPLL_DIV_SEL_MASK                0x00000300L

// CLOCK_CNTL_DATA
#define CLOCK_CNTL_DATA__PLL_DATA_MASK                     0xffffffffL

// PPLL_DIV_0
#define PPLL_DIV_0__PPLL_FB0_DIV_MASK                      0x000007ffL
#define PPLL_DIV_0__PPLL_ATOMIC_UPDATE_W_MASK              0x00008000L
#define PPLL_DIV_0__PPLL_ATOMIC_UPDATE_W                   0x00008000L
#define PPLL_DIV_0__PPLL_ATOMIC_UPDATE_R_MASK              0x00008000L
#define PPLL_DIV_0__PPLL_ATOMIC_UPDATE_R                   0x00008000L
#define PPLL_DIV_0__PPLL_POST0_DIV_MASK                    0x00070000L
#define PPLL_DIV_0__PPLL_FB_DIV_FRACTION_MASK              0x00380000L
#define PPLL_DIV_0__PPLL_FB_DIV_FRACTION_UPDATE_MASK       0x00400000L
#define PPLL_DIV_0__PPLL_FB_DIV_FRACTION_UPDATE            0x00400000L
#define PPLL_DIV_0__PPLL_FB_DIV_FRACTION_EN_MASK           0x00800000L
#define PPLL_DIV_0__PPLL_FB_DIV_FRACTION_EN                0x00800000L

// PPLL_DIV_1
#define PPLL_DIV_1__PPLL_FB1_DIV_MASK                      0x000007ffL
#define PPLL_DIV_1__PPLL_ATOMIC_UPDATE_W_MASK              0x00008000L
#define PPLL_DIV_1__PPLL_ATOMIC_UPDATE_W                   0x00008000L
#define PPLL_DIV_1__PPLL_ATOMIC_UPDATE_R_MASK              0x00008000L
#define PPLL_DIV_1__PPLL_ATOMIC_UPDATE_R                   0x00008000L
#define PPLL_DIV_1__PPLL_POST1_DIV_MASK                    0x00070000L

// PPLL_DIV_2
#define PPLL_DIV_2__PPLL_FB2_DIV_MASK                      0x000007ffL
#define PPLL_DIV_2__PPLL_ATOMIC_UPDATE_W_MASK              0x00008000L
#define PPLL_DIV_2__PPLL_ATOMIC_UPDATE_W                   0x00008000L
#define PPLL_DIV_2__PPLL_ATOMIC_UPDATE_R_MASK              0x00008000L
#define PPLL_DIV_2__PPLL_ATOMIC_UPDATE_R                   0x00008000L
#define PPLL_DIV_2__PPLL_POST2_DIV_MASK                    0x00070000L

// PPLL_DIV_3
#define PPLL_DIV_3__PPLL_FB3_DIV_MASK                      0x000007ffL
#define PPLL_DIV_3__PPLL_ATOMIC_UPDATE_W_MASK              0x00008000L
#define PPLL_DIV_3__PPLL_ATOMIC_UPDATE_W                   0x00008000L
#define PPLL_DIV_3__PPLL_ATOMIC_UPDATE_R_MASK              0x00008000L
#define PPLL_DIV_3__PPLL_ATOMIC_UPDATE_R                   0x00008000L
#define PPLL_DIV_3__PPLL_POST3_DIV_MASK                    0x00070000L

// HTOTAL_CNTL
#define HTOTAL_CNTL__HTOT_PIX_SLIP_MASK                    0x0000000fL
#define HTOTAL_CNTL__HTOT_VCLK_SLIP_MASK                   0x00000f00L
#define HTOTAL_CNTL__HTOT_PPLL_SLIP_MASK                   0x00070000L
#define HTOTAL_CNTL__HTOT_CNTL_EDGE_MASK                   0x01000000L
#define HTOTAL_CNTL__HTOT_CNTL_EDGE                        0x01000000L
#define HTOTAL_CNTL__HTOT_CNTL_VGA_EN_MASK                 0x10000000L
#define HTOTAL_CNTL__HTOT_CNTL_VGA_EN                      0x10000000L

// PLL_TEST_CNTL
#define PLL_TEST_CNTL__TST_SRC_SEL_M6_MASK                 0x0000007fL
#define PLL_TEST_CNTL__TST_SRC_INV_MASK                    0x00000080L
#define PLL_TEST_CNTL__TST_SRC_INV                         0x00000080L
#define PLL_TEST_CNTL__TST_DIVIDERS_MASK                   0x00000100L
#define PLL_TEST_CNTL__TST_DIVIDERS                        0x00000100L
#define PLL_TEST_CNTL__PLL_MASK_READ_B_MASK                0x00000200L
#define PLL_TEST_CNTL__PLL_MASK_READ_B                     0x00000200L
#define PLL_TEST_CNTL__TESTCLK_MUX_SEL_MASK                0x00001000L
#define PLL_TEST_CNTL__TESTCLK_MUX_SEL                     0x00001000L
#define PLL_TEST_CNTL__ANALOG_MON_M6_MASK                  0x00ff8000L
#define PLL_TEST_CNTL__TEST_COUNT_MASK                     0xff000000L

// P2PLL_DIV_0
#define P2PLL_DIV_0__P2PLL_FB_DIV_MASK                     0x000007ffL
#define P2PLL_DIV_0__P2PLL_ATOMIC_UPDATE_W_MASK            0x00008000L
#define P2PLL_DIV_0__P2PLL_ATOMIC_UPDATE_W                 0x00008000L
#define P2PLL_DIV_0__P2PLL_ATOMIC_UPDATE_R_MASK            0x00008000L
#define P2PLL_DIV_0__P2PLL_ATOMIC_UPDATE_R                 0x00008000L
#define P2PLL_DIV_0__P2PLL_POST_DIV_MASK                   0x00070000L
#define P2PLL_DIV_0__P2PLL_FB_DIV_FRACTION_MASK            0x00380000L
#define P2PLL_DIV_0__P2PLL_FB_DIV_FRACTION_UPDATE_MASK     0x00400000L
#define P2PLL_DIV_0__P2PLL_FB_DIV_FRACTION_UPDATE          0x00400000L
#define P2PLL_DIV_0__P2PLL_FB_DIV_FRACTION_EN_MASK         0x00800000L
#define P2PLL_DIV_0__P2PLL_FB_DIV_FRACTION_EN              0x00800000L

// HTOTAL2_CNTL
#define HTOTAL2_CNTL__HTOT2_PIX_SLIP_MASK                  0x0000000fL
#define HTOTAL2_CNTL__HTOT2_PIX2CLK_SLIP_MASK              0x00000f00L
#define HTOTAL2_CNTL__HTOT2_P2PLL_SLIP_MASK                0x00070000L
#define HTOTAL2_CNTL__HTOT2_CNTL_EDGE_MASK                 0x01000000L
#define HTOTAL2_CNTL__HTOT2_CNTL_EDGE                      0x01000000L
#define HTOTAL2_CNTL__HTOT2_CNTL_UPDATE_MASK               0x10000000L
#define HTOTAL2_CNTL__HTOT2_CNTL_UPDATE                    0x10000000L

// DAC_CNTL2
#define DAC_CNTL2__DAC_CLK_SEL_MASK                        0x00000001L
#define DAC_CNTL2__DAC_CLK_SEL                             0x00000001L
#define DAC_CNTL2__DAC2_CLK_SEL_MASK                       0x00000002L
#define DAC_CNTL2__DAC2_CLK_SEL                            0x00000002L
#define DAC_CNTL2__PALETTE_ACCESS_CNTL_MASK                0x00000020L
#define DAC_CNTL2__PALETTE_ACCESS_CNTL                     0x00000020L
#define DAC_CNTL2__DAC2_CMP_EN_MASK                        0x00000080L
#define DAC_CNTL2__DAC2_CMP_EN                             0x00000080L
#define DAC_CNTL2__DAC2_CMP_OUT_R_MASK                     0x00000100L
#define DAC_CNTL2__DAC2_CMP_OUT_R                          0x00000100L
#define DAC_CNTL2__DAC2_CMP_OUT_G_MASK                     0x00000200L
#define DAC_CNTL2__DAC2_CMP_OUT_G                          0x00000200L
#define DAC_CNTL2__DAC2_CMP_OUT_B_MASK                     0x00000400L
#define DAC_CNTL2__DAC2_CMP_OUT_B                          0x00000400L
#define DAC_CNTL2__DAC2_CMP_OUTPUT_MASK                    0x00000800L
#define DAC_CNTL2__DAC2_CMP_OUTPUT                         0x00000800L
#define DAC_CNTL2__DAC2_EXPAND_MODE_MASK                   0x00004000L
#define DAC_CNTL2__DAC2_EXPAND_MODE                        0x00004000L
#define DAC_CNTL2__CRT2_SENSE_MASK                         0x00010000L
#define DAC_CNTL2__CRT2_SENSE                              0x00010000L
#define DAC_CNTL2__CRT2_DETECTION_ON_MASK                  0x00020000L
#define DAC_CNTL2__CRT2_DETECTION_ON                       0x00020000L
#define DAC_CNTL2__DAC_CRC2_CONT_EN_MASK                   0x00040000L
#define DAC_CNTL2__DAC_CRC2_CONT_EN                        0x00040000L
#define DAC_CNTL2__DAC_CRC2_EN_MASK                        0x00080000L
#define DAC_CNTL2__DAC_CRC2_EN                             0x00080000L
#define DAC_CNTL2__DAC_CRC2_FIELD_MASK                     0x00100000L
#define DAC_CNTL2__DAC_CRC2_FIELD                          0x00100000L
#define DAC_CNTL2__DAC2_LUT_COUNTER_LIMIT_MASK             0x00600000L

// TV_MASTER_CNTL
#define TV_MASTER_CNTL__TV_ASYNC_RST_MASK                  0x00000001L
#define TV_MASTER_CNTL__TV_ASYNC_RST                       0x00000001L
#define TV_MASTER_CNTL__CRT_ASYNC_RST_MASK                 0x00000002L
#define TV_MASTER_CNTL__CRT_ASYNC_RST                      0x00000002L
#define TV_MASTER_CNTL__RESTART_PHASE_FIX_MASK             0x00000008L
#define TV_MASTER_CNTL__RESTART_PHASE_FIX                  0x00000008L
#define TV_MASTER_CNTL__TV_FIFO_ASYNC_RST_MASK             0x00000010L
#define TV_MASTER_CNTL__TV_FIFO_ASYNC_RST                  0x00000010L
#define TV_MASTER_CNTL__MV_BP_LEVEL_FIX_EN_MASK            0x00000020L
#define TV_MASTER_CNTL__MV_BP_LEVEL_FIX_EN                 0x00000020L
#define TV_MASTER_CNTL__EXTRA_BIT_ONE_0_MASK               0x00000040L
#define TV_MASTER_CNTL__EXTRA_BIT_ONE_0                    0x00000040L
#define TV_MASTER_CNTL__CRT_FIFO_CE_EN_MASK                0x00000200L
#define TV_MASTER_CNTL__CRT_FIFO_CE_EN                     0x00000200L
#define TV_MASTER_CNTL__TV_FIFO_CE_EN_MASK                 0x00000400L
#define TV_MASTER_CNTL__TV_FIFO_CE_EN                      0x00000400L
#define TV_MASTER_CNTL__RE_SYNC_NOW_SEL_MASK               0x0000c000L
#define TV_MASTER_CNTL__EXTRA_BIT_ZERO_1_MASK              0x00010000L
#define TV_MASTER_CNTL__EXTRA_BIT_ZERO_1                   0x00010000L
#define TV_MASTER_CNTL__EXTRA_BIT_ONE_1_MASK               0x00020000L
#define TV_MASTER_CNTL__EXTRA_BIT_ONE_1                    0x00020000L
#define TV_MASTER_CNTL__EXTRA_BIT_ZERO_2_MASK              0x00040000L
#define TV_MASTER_CNTL__EXTRA_BIT_ZERO_2                   0x00040000L
#define TV_MASTER_CNTL__EXTRA_BIT_ONE_2_MASK               0x00080000L
#define TV_MASTER_CNTL__EXTRA_BIT_ONE_2                    0x00080000L
#define TV_MASTER_CNTL__TVCLK_ALWAYS_ONb_MASK              0x40000000L
#define TV_MASTER_CNTL__TVCLK_ALWAYS_ONb                   0x40000000L
#define TV_MASTER_CNTL__TV_ON_MASK                         0x80000000L
#define TV_MASTER_CNTL__TV_ON                              0x80000000L

// TV_RGB_CNTL
#define TV_RGB_CNTL__UV_DITHER_EN_MASK                     0x0000000cL
#define TV_RGB_CNTL__SWITCH_TO_BLUE_MASK                   0x00000010L
#define TV_RGB_CNTL__SWITCH_TO_BLUE                        0x00000010L
#define TV_RGB_CNTL__RGB_DITHER_EN_MASK                    0x00000020L
#define TV_RGB_CNTL__RGB_DITHER_EN                         0x00000020L
#define TV_RGB_CNTL__RGB_SRC_SEL_MASK                      0x00000300L
#define TV_RGB_CNTL__RGB_CONVERT_BY_PASS_MASK              0x00000400L
#define TV_RGB_CNTL__RGB_CONVERT_BY_PASS                   0x00000400L
#define TV_RGB_CNTL__RE_SYNC_NOW_POS_MASK                  0x00000800L
#define TV_RGB_CNTL__RE_SYNC_NOW_POS                       0x00000800L
#define TV_RGB_CNTL__IGNORE_ODD_LINES_MASK                 0x00002000L
#define TV_RGB_CNTL__IGNORE_ODD_LINES                      0x00002000L
#define TV_RGB_CNTL__DSP_VCOUNT_RST_MASK                   0x00004000L
#define TV_RGB_CNTL__DSP_VCOUNT_RST                        0x00004000L
#define TV_RGB_CNTL__DSP2_VCOUNT_RST_MASK                  0x00008000L
#define TV_RGB_CNTL__DSP2_VCOUNT_RST                       0x00008000L
#define TV_RGB_CNTL__UVRAM_READ_MARGIN_MASK                0x000f0000L
#define TV_RGB_CNTL__FIFORAM_FFMACRO_READ_MARGIN_MASK      0x00f00000L
#define TV_RGB_CNTL__RGB_ATTEN_SEL_MASK                    0x03000000L
#define TV_RGB_CNTL__RGB_ATTEN_VAL_MASK                    0xf0000000L

// TV_SYNC_CNTL
#define TV_SYNC_CNTL__SYNC_OE_MASK                         0x00000001L
#define TV_SYNC_CNTL__SYNC_OE                              0x00000001L
#define TV_SYNC_CNTL__SYNC_OUT_MASK                        0x00000002L
#define TV_SYNC_CNTL__SYNC_OUT                             0x00000002L
#define TV_SYNC_CNTL__SYNC_IN_MASK                         0x00000004L
#define TV_SYNC_CNTL__SYNC_IN                              0x00000004L
#define TV_SYNC_CNTL__SYNC_PUB_MASK                        0x00000008L
#define TV_SYNC_CNTL__SYNC_PUB                             0x00000008L
#define TV_SYNC_CNTL__SYNC_PD_MASK                         0x00000010L
#define TV_SYNC_CNTL__SYNC_PD                              0x00000010L
#define TV_SYNC_CNTL__TV_SYNC_IO_DRIVE_MASK                0x00000020L
#define TV_SYNC_CNTL__TV_SYNC_IO_DRIVE                     0x00000020L
#define TV_SYNC_CNTL__SYNC_MX_MASK                         0x00000f00L

// TV_HTOTAL
#define TV_HTOTAL__D_HTOTAL_MASK                           0x000007ffL

// TV_HDISP
#define TV_HDISP__D_HDISP_MASK                             0x000003ffL

// TV_HSTART
#define TV_HSTART__D_HSTART_MASK                           0x000007ffL

// TV_HCOUNT
#define TV_HCOUNT__D_HCOUNT_MASK                           0x000007ffL

// TV_VTOTAL
#define TV_VTOTAL__D_VTOTAL_MASK                           0x000003ffL

// TV_VDISP
#define TV_VDISP__D_VDISP_MASK                             0x000003ffL

// TV_VCOUNT
#define TV_VCOUNT__D_VCOUNT_MASK                           0x000003ffL

// TV_FTOTAL
#define TV_FTOTAL__D_FTOTAL_MASK                           0x0000000fL

// TV_FCOUNT
#define TV_FCOUNT__D_FCOUNT_MASK                           0x0000000fL

// TV_FRESTART
#define TV_FRESTART__D_FRESTART_MASK                       0x0000000fL

// TV_HRESTART
#define TV_HRESTART__D_HRESTART_MASK                       0x000007ffL

// TV_VRESTART
#define TV_VRESTART__D_VRESTART_MASK                       0x000003ffL

// TV_HOST_READ_DATA
#define TV_HOST_READ_DATA__HOST_RD_DATA_W0_MASK            0x0000ffffL
#define TV_HOST_READ_DATA__HOST_RD_DATA_W1_MASK            0x0fff0000L

// TV_HOST_WRITE_DATA
#define TV_HOST_WRITE_DATA__HOST_WT_DATA_W0_MASK           0x0000ffffL
#define TV_HOST_WRITE_DATA__HOST_WT_DATA_W1_MASK           0x0fff0000L

// TV_HOST_RD_WT_CNTL
#define TV_HOST_RD_WT_CNTL__HOST_ADR_MASK                  0x000001ffL
#define TV_HOST_RD_WT_CNTL__HOST_FIFO_RD_MASK              0x00001000L
#define TV_HOST_RD_WT_CNTL__HOST_FIFO_RD                   0x00001000L
#define TV_HOST_RD_WT_CNTL__HOST_FIFO_RD_ACK_MASK          0x00002000L
#define TV_HOST_RD_WT_CNTL__HOST_FIFO_RD_ACK               0x00002000L
#define TV_HOST_RD_WT_CNTL__HOST_FIFO_WT_MASK              0x00004000L
#define TV_HOST_RD_WT_CNTL__HOST_FIFO_WT                   0x00004000L
#define TV_HOST_RD_WT_CNTL__HOST_FIFO_WT_ACK_MASK          0x00008000L
#define TV_HOST_RD_WT_CNTL__HOST_FIFO_WT_ACK               0x00008000L

// TV_VSCALER_CNTL1
#define TV_VSCALER_CNTL1__UV_INC_MASK                      0x0000ffffL
#define TV_VSCALER_CNTL1__UV_THINNER_MASK                  0x007f0000L
#define TV_VSCALER_CNTL1__Y_W_EN_MASK                      0x01000000L
#define TV_VSCALER_CNTL1__Y_W_EN                           0x01000000L
#define TV_VSCALER_CNTL1__Y_DEL_W_SIG_MASK                 0x1c000000L
#define TV_VSCALER_CNTL1__RESTART_FIELD_MASK               0x20000000L
#define TV_VSCALER_CNTL1__RESTART_FIELD                    0x20000000L

// TV_TIMING_CNTL
#define TV_TIMING_CNTL__H_INC_MASK                         0x00000fffL
#define TV_TIMING_CNTL__REQ_DELAY_MASK                     0x00070000L
#define TV_TIMING_CNTL__REQ_Y_FIRST_MASK                   0x00080000L
#define TV_TIMING_CNTL__REQ_Y_FIRST                        0x00080000L
#define TV_TIMING_CNTL__MV_VBIPULSE_ENB_MASK               0x00100000L
#define TV_TIMING_CNTL__MV_VBIPULSE_ENB                    0x00100000L
#define TV_TIMING_CNTL__FORCE_BURST_ALWAYS_MASK            0x00200000L
#define TV_TIMING_CNTL__FORCE_BURST_ALWAYS                 0x00200000L
#define TV_TIMING_CNTL__UV_POST_SCALE_BYPASS_MASK          0x00800000L
#define TV_TIMING_CNTL__UV_POST_SCALE_BYPASS               0x00800000L
#define TV_TIMING_CNTL__UV_OUTPUT_POST_SCALE_MASK          0xff000000L

// TV_VSCALER_CNTL2
#define TV_VSCALER_CNTL2__DITHER_MODE_MASK                 0x00000001L
#define TV_VSCALER_CNTL2__DITHER_MODE                      0x00000001L
#define TV_VSCALER_CNTL2__Y_OUTPUT_DITHER_EN_MASK          0x00000002L
#define TV_VSCALER_CNTL2__Y_OUTPUT_DITHER_EN               0x00000002L
#define TV_VSCALER_CNTL2__UV_OUTPUT_DITHER_EN_MASK         0x00000004L
#define TV_VSCALER_CNTL2__UV_OUTPUT_DITHER_EN              0x00000004L
#define TV_VSCALER_CNTL2__UV_TO_BUF_DITHER_EN_MASK         0x00000008L
#define TV_VSCALER_CNTL2__UV_TO_BUF_DITHER_EN              0x00000008L
#define TV_VSCALER_CNTL2__UV_ACCUM_INIT_MASK               0xff000000L

// TV_Y_FALL_CNTL
#define TV_Y_FALL_CNTL__Y_FALL_ACCUM_INIT_MASK             0x0000ffffL
#define TV_Y_FALL_CNTL__Y_FALL_PING_PONG_MASK              0x00010000L
#define TV_Y_FALL_CNTL__Y_FALL_PING_PONG                   0x00010000L
#define TV_Y_FALL_CNTL__Y_COEF_EN_MASK                     0x00020000L
#define TV_Y_FALL_CNTL__Y_COEF_EN                          0x00020000L
#define TV_Y_FALL_CNTL__Y_COEF_VALUE_MASK                  0xff000000L

// TV_Y_RISE_CNTL
#define TV_Y_RISE_CNTL__Y_RISE_ACCUM_INIT_MASK             0x0000ffffL
#define TV_Y_RISE_CNTL__Y_RISE_PING_PONG_MASK              0x00010000L
#define TV_Y_RISE_CNTL__Y_RISE_PING_PONG                   0x00010000L
#define TV_Y_RISE_CNTL__MV_STRIPE_ENB_MASK                 0x00020000L
#define TV_Y_RISE_CNTL__MV_STRIPE_ENB                      0x00020000L
#define TV_Y_RISE_CNTL__MV_BPPULSE_ENB_MASK                0x00040000L
#define TV_Y_RISE_CNTL__MV_BPPULSE_ENB                     0x00040000L
#define TV_Y_RISE_CNTL__MV_ZONE_1_PHASE_MASK               0x00100000L
#define TV_Y_RISE_CNTL__MV_ZONE_1_PHASE                    0x00100000L
#define TV_Y_RISE_CNTL__MV_ZONE_2_PHASE_MASK               0x00200000L
#define TV_Y_RISE_CNTL__MV_ZONE_2_PHASE                    0x00200000L
#define TV_Y_RISE_CNTL__MV_ZONE_3_PHASE_MASK               0x00400000L
#define TV_Y_RISE_CNTL__MV_ZONE_3_PHASE                    0x00400000L

// TV_Y_SAW_TOOTH_CNTL
#define TV_Y_SAW_TOOTH_CNTL__Y_SAW_TOOTH_AMP_MASK          0x0000ffffL
#define TV_Y_SAW_TOOTH_CNTL__Y_SAW_TOOTH_SLOPE_MASK        0xffff0000L

// TV_UPSAMP_AND_GAIN_CNTL
#define TV_UPSAMP_AND_GAIN_CNTL__YUPSAMP_EN_MASK           0x00000001L
#define TV_UPSAMP_AND_GAIN_CNTL__YUPSAMP_EN                0x00000001L
#define TV_UPSAMP_AND_GAIN_CNTL__YUPSAMP_FLAT_MASK         0x00000002L
#define TV_UPSAMP_AND_GAIN_CNTL__YUPSAMP_FLAT              0x00000002L
#define TV_UPSAMP_AND_GAIN_CNTL__UVUPSAMP_EN_MASK          0x00000004L
#define TV_UPSAMP_AND_GAIN_CNTL__UVUPSAMP_EN               0x00000004L
#define TV_UPSAMP_AND_GAIN_CNTL__UVUPSAMP_FLAT_MASK        0x00000008L
#define TV_UPSAMP_AND_GAIN_CNTL__UVUPSAMP_FLAT             0x00000008L
#define TV_UPSAMP_AND_GAIN_CNTL__YUPSAMP_WINDOW_CNTL_MASK  0x00000010L
#define TV_UPSAMP_AND_GAIN_CNTL__YUPSAMP_WINDOW_CNTL       0x00000010L
#define TV_UPSAMP_AND_GAIN_CNTL__YUPSAMP_COEF_SEL_MASK     0x00000020L
#define TV_UPSAMP_AND_GAIN_CNTL__YUPSAMP_COEF_SEL          0x00000020L
#define TV_UPSAMP_AND_GAIN_CNTL__Y_BREAK_EN_MASK           0x00000100L
#define TV_UPSAMP_AND_GAIN_CNTL__Y_BREAK_EN                0x00000100L
#define TV_UPSAMP_AND_GAIN_CNTL__UV_BREAK_EN_MASK          0x00000400L
#define TV_UPSAMP_AND_GAIN_CNTL__UV_BREAK_EN               0x00000400L

// TV_GAIN_LIMIT_SETTINGS
#define TV_GAIN_LIMIT_SETTINGS__Y_GAIN_LIMIT_MASK          0x000007ffL
#define TV_GAIN_LIMIT_SETTINGS__UV_GAIN_LIMIT_MASK         0x01ff0000L

// TV_LINEAR_GAIN_SETTINGS
#define TV_LINEAR_GAIN_SETTINGS__Y_GAIN_MASK               0x000001ffL
#define TV_LINEAR_GAIN_SETTINGS__UV_GAIN_MASK              0x01ff0000L

// TV_MODULATOR_CNTL1
#define TV_MODULATOR_CNTL1__YY_FILT_BLEND_MASK             0x00000003L
#define TV_MODULATOR_CNTL1__YFLT_EN_MASK                   0x00000004L
#define TV_MODULATOR_CNTL1__YFLT_EN                        0x00000004L
#define TV_MODULATOR_CNTL1__UVFLT_EN_MASK                  0x00000008L
#define TV_MODULATOR_CNTL1__UVFLT_EN                       0x00000008L
#define TV_MODULATOR_CNTL1__ALT_PHASE_EN_MASK              0x00000040L
#define TV_MODULATOR_CNTL1__ALT_PHASE_EN                   0x00000040L
#define TV_MODULATOR_CNTL1__SYNC_TIP_LEVEL_MASK            0x00000080L
#define TV_MODULATOR_CNTL1__SYNC_TIP_LEVEL                 0x00000080L
#define TV_MODULATOR_CNTL1__SET_UP_LEVEL_MASK              0x00007f00L
#define TV_MODULATOR_CNTL1__BLANK_LEVEL_MASK               0x007f0000L
#define TV_MODULATOR_CNTL1__SLEW_RATE_LIMIT_MASK           0x00800000L
#define TV_MODULATOR_CNTL1__SLEW_RATE_LIMIT                0x00800000L
#define TV_MODULATOR_CNTL1__FORCE_BLACK_WHITE_MASK         0x01000000L
#define TV_MODULATOR_CNTL1__FORCE_BLACK_WHITE              0x01000000L
#define TV_MODULATOR_CNTL1__MV_VSYNC_AMP_MASK              0x04000000L
#define TV_MODULATOR_CNTL1__MV_VSYNC_AMP                   0x04000000L
#define TV_MODULATOR_CNTL1__MV_HSYNC_AMP_MASK              0x08000000L
#define TV_MODULATOR_CNTL1__MV_HSYNC_AMP                   0x08000000L
#define TV_MODULATOR_CNTL1__CY_FILT_BLEND_MASK             0xf0000000L

// TV_MODULATOR_CNTL2
#define TV_MODULATOR_CNTL2__U_BURST_LEVEL_MASK             0x000001ffL
#define TV_MODULATOR_CNTL2__V_BURST_LEVEL_MASK             0x01ff0000L
#define TV_MODULATOR_CNTL2__SETUP_DELAY_MASK               0xfc000000L

// TV_MV_MODE_CNTL
#define TV_MV_MODE_CNTL__MV_AGC_CYC_MODE_MASK              0x00000001L
#define TV_MV_MODE_CNTL__MV_AGC_CYC_MODE                   0x00000001L
#define TV_MV_MODE_CNTL__MV_AGC_CYC_TMODE_EN_MASK          0x00000002L
#define TV_MV_MODE_CNTL__MV_AGC_CYC_TMODE_EN               0x00000002L
#define TV_MV_MODE_CNTL__MV_AGC_AMPL_STEP_MASK             0x0000003cL
#define TV_MV_MODE_CNTL__MV_AGC_CLK_DEVIDE_SEL_MASK        0x00000040L
#define TV_MV_MODE_CNTL__MV_AGC_CLK_DEVIDE_SEL             0x00000040L
#define TV_MV_MODE_CNTL__MV_OVRB_EN_MASK                   0x00000080L
#define TV_MV_MODE_CNTL__MV_OVRB_EN                        0x00000080L
#define TV_MV_MODE_CNTL__MV_OVRB_LEVEL_MASK                0x0000ff00L

// TV_MV_STRIPE_CNTL
#define TV_MV_STRIPE_CNTL__MV_LINE_1_PHASE_MASK            0x00000003L
#define TV_MV_STRIPE_CNTL__MV_LINE_2_PHASE_MASK            0x0000000cL
#define TV_MV_STRIPE_CNTL__MV_LINE_3_PHASE_MASK            0x00000030L
#define TV_MV_STRIPE_CNTL__MV_LINE_4_PHASE_MASK            0x000000c0L
#define TV_MV_STRIPE_CNTL__MV_LINE_5_PHASE_MASK            0x00000300L

// TV_MV_LEVEL_CNTL
#define TV_MV_LEVEL_CNTL__MV_BLANK_LEVEL_MASK              0x0000007fL
#define TV_MV_LEVEL_CNTL__MV_SETUP_LEVEL_MASK              0x00007f00L
#define TV_MV_LEVEL_CNTL__MV_AGC_AMPL_A_MASK               0x00ff0000L
#define TV_MV_LEVEL_CNTL__MV_AGC_AMPL_B_MASK               0x7f000000L

// TV_MV_LEVEL_CNTL2
#define TV_MV_LEVEL_CNTL2__MV_AGC_AMPL_MAX_MASK            0x000000ffL
#define TV_MV_LEVEL_CNTL2__MV_BP_LEVEL_MASK                0x0000ff00L

// TV_PRE_DAC_MUX_CNTL
#define TV_PRE_DAC_MUX_CNTL__Y_RED_EN_MASK                 0x00000001L
#define TV_PRE_DAC_MUX_CNTL__Y_RED_EN                      0x00000001L
#define TV_PRE_DAC_MUX_CNTL__C_GRN_EN_MASK                 0x00000002L
#define TV_PRE_DAC_MUX_CNTL__C_GRN_EN                      0x00000002L
#define TV_PRE_DAC_MUX_CNTL__CMP_BLU_EN_MASK               0x00000004L
#define TV_PRE_DAC_MUX_CNTL__CMP_BLU_EN                    0x00000004L
#define TV_PRE_DAC_MUX_CNTL__DAC_DITHER_EN_MASK            0x00000008L
#define TV_PRE_DAC_MUX_CNTL__DAC_DITHER_EN                 0x00000008L
#define TV_PRE_DAC_MUX_CNTL__RED_MX_MASK                   0x00000070L
#define TV_PRE_DAC_MUX_CNTL__GRN_MX_MASK                   0x00000700L
#define TV_PRE_DAC_MUX_CNTL__BLU_MX_MASK                   0x00007000L
#define TV_PRE_DAC_MUX_CNTL__FORCE_DAC_DATA_MASK           0x03ff0000L

// TV_DAC_CNTL
#define TV_DAC_CNTL__NBLANK_MASK                           0x00000001L
#define TV_DAC_CNTL__NBLANK                                0x00000001L
#define TV_DAC_CNTL__NHOLD_MASK                            0x00000002L
#define TV_DAC_CNTL__NHOLD                                 0x00000002L
#define TV_DAC_CNTL__PEDESTAL_MASK                         0x00000004L
#define TV_DAC_CNTL__PEDESTAL                              0x00000004L
#define TV_DAC_CNTL__DETECT_MASK                           0x00000010L
#define TV_DAC_CNTL__DETECT                                0x00000010L
#define TV_DAC_CNTL__CMPOUT_MASK                           0x00000020L
#define TV_DAC_CNTL__CMPOUT                                0x00000020L
#define TV_DAC_CNTL__BGSLEEP_MASK                          0x00000040L
#define TV_DAC_CNTL__BGSLEEP                               0x00000040L
#define TV_DAC_CNTL__STD_MASK                              0x00000300L
#define TV_DAC_CNTL__MON_MASK                              0x0000f000L
#define TV_DAC_CNTL__BGADJ_MASK                            0x000f0000L
#define TV_DAC_CNTL__DACADJ_MASK                           0x00f00000L
#define TV_DAC_CNTL__RDACPD_MASK                           0x01000000L
#define TV_DAC_CNTL__RDACPD                                0x01000000L
#define TV_DAC_CNTL__GDACPD_MASK                           0x02000000L
#define TV_DAC_CNTL__GDACPD                                0x02000000L
#define TV_DAC_CNTL__BDACPD_MASK                           0x04000000L
#define TV_DAC_CNTL__BDACPD                                0x04000000L
#define TV_DAC_CNTL__RDACDET_MASK                          0x20000000L
#define TV_DAC_CNTL__RDACDET                               0x20000000L
#define TV_DAC_CNTL__GDACDET_MASK                          0x40000000L
#define TV_DAC_CNTL__GDACDET                               0x40000000L
#define TV_DAC_CNTL__BDACDET_MASK                          0x80000000L
#define TV_DAC_CNTL__BDACDET                               0x80000000L

// TV_CRC_CNTL
#define TV_CRC_CNTL__V_COMP_DATA_EN_MASK                   0x00000003L
#define TV_CRC_CNTL__V_COMP_GATE_MASK                      0x00000004L
#define TV_CRC_CNTL__V_COMP_GATE                           0x00000004L
#define TV_CRC_CNTL__V_COMP_EN_MASK                        0x00000008L
#define TV_CRC_CNTL__V_COMP_EN                             0x00000008L
#define TV_CRC_CNTL__RST_SUBC_ONRSTRT_MASK                 0x00000010L
#define TV_CRC_CNTL__RST_SUBC_ONRSTRT                      0x00000010L
#define TV_CRC_CNTL__CRC_TV_RSTRT_SEL_MASK                 0x00000020L
#define TV_CRC_CNTL__CRC_TV_RSTRT_SEL                      0x00000020L

// TV_VIDEO_PORT_SIG
#define TV_VIDEO_PORT_SIG__CRC_SIG_MASK                    0x3fffffffL

// TV_VBI_CC_CNTL
#define TV_VBI_CC_CNTL__VBI_CC_DATA_MASK                   0x0000ffffL
#define TV_VBI_CC_CNTL__VBI_CC_WT_MASK                     0x01000000L
#define TV_VBI_CC_CNTL__VBI_CC_WT                          0x01000000L
#define TV_VBI_CC_CNTL__VBI_CC_WT_ACK_MASK                 0x02000000L
#define TV_VBI_CC_CNTL__VBI_CC_WT_ACK                      0x02000000L
#define TV_VBI_CC_CNTL__VBI_CC_HOLD_MASK                   0x04000000L
#define TV_VBI_CC_CNTL__VBI_CC_HOLD                        0x04000000L
#define TV_VBI_CC_CNTL__VBI_DECODE_EN_MASK                 0x80000000L
#define TV_VBI_CC_CNTL__VBI_DECODE_EN                      0x80000000L

// TV_VBI_EDS_CNTL
#define TV_VBI_EDS_CNTL__VBI_EDS_DATA_MASK                 0x0000ffffL
#define TV_VBI_EDS_CNTL__VBI_EDS_WT_MASK                   0x01000000L
#define TV_VBI_EDS_CNTL__VBI_EDS_WT                        0x01000000L
#define TV_VBI_EDS_CNTL__VBI_EDS_WT_ACK_MASK               0x02000000L
#define TV_VBI_EDS_CNTL__VBI_EDS_WT_ACK                    0x02000000L
#define TV_VBI_EDS_CNTL__VBI_EDS_HOLD_MASK                 0x04000000L
#define TV_VBI_EDS_CNTL__VBI_EDS_HOLD                      0x04000000L

// TV_VBI_20BIT_CNTL
#define TV_VBI_20BIT_CNTL__VBI_20BIT_DATA0_MASK            0x0000ffffL
#define TV_VBI_20BIT_CNTL__VBI_20BIT_DATA1_MASK            0x000f0000L
#define TV_VBI_20BIT_CNTL__VBI_20BIT_WT_MASK               0x01000000L
#define TV_VBI_20BIT_CNTL__VBI_20BIT_WT                    0x01000000L
#define TV_VBI_20BIT_CNTL__VBI_20BIT_WT_ACK_MASK           0x02000000L
#define TV_VBI_20BIT_CNTL__VBI_20BIT_WT_ACK                0x02000000L
#define TV_VBI_20BIT_CNTL__VBI_20BIT_HOLD_MASK             0x04000000L
#define TV_VBI_20BIT_CNTL__VBI_20BIT_HOLD                  0x04000000L

// TV_VBI_DTO_CNTL
#define TV_VBI_DTO_CNTL__VBI_CC_DTO_P_MASK                 0x0000ffffL
#define TV_VBI_DTO_CNTL__VBI_20BIT_DTO_P_MASK              0xffff0000L

// TV_VBI_LEVEL_CNTL
#define TV_VBI_LEVEL_CNTL__VBI_CC_LEVEL_MASK               0x0000007fL
#define TV_VBI_LEVEL_CNTL__VBI_20BIT_LEVEL_MASK            0x00007f00L
#define TV_VBI_LEVEL_CNTL__VBI_CLK_RUNIN_GAIN_MASK         0x01ff0000L

// TV_UV_ADR
#define TV_UV_ADR__MAX_UV_ADR_MASK                         0x000000ffL
#define TV_UV_ADR__TABLE1_BOT_ADR_MASK                     0x0000ff00L
#define TV_UV_ADR__TABLE3_TOP_ADR_MASK                     0x00ff0000L
#define TV_UV_ADR__MV_DECODE_EN_MASK                       0x01000000L
#define TV_UV_ADR__MV_DECODE_EN                            0x01000000L
#define TV_UV_ADR__HCODE_TABLE_SEL_MASK                    0x06000000L
#define TV_UV_ADR__VCODE_TABLE_SEL_MASK                    0x18000000L
#define TV_UV_ADR__MV_LINES_PER_STRIPE_MASK                0x60000000L
#define TV_UV_ADR__SWITCH_TABLE_REQ_MASK                   0x80000000L
#define TV_UV_ADR__SWITCH_TABLE_REQ                        0x80000000L

// TV_VSYNC_DIFF_CNTL
#define TV_VSYNC_DIFF_CNTL__VSYNC_DIFF_MEASURE_EN_MASK     0x00000001L
#define TV_VSYNC_DIFF_CNTL__VSYNC_DIFF_MEASURE_EN          0x00000001L
#define TV_VSYNC_DIFF_CNTL__VSYNC_RESTART_AT_LIMIT_MASK    0x00000002L
#define TV_VSYNC_DIFF_CNTL__VSYNC_RESTART_AT_LIMIT         0x00000002L
#define TV_VSYNC_DIFF_CNTL__VSYNC_HW_LOCK_EN_MASK          0x00000004L
#define TV_VSYNC_DIFF_CNTL__VSYNC_HW_LOCK_EN               0x00000004L
#define TV_VSYNC_DIFF_CNTL__VSYNC_HW_LOCK_TYPE_MASK        0x00000008L
#define TV_VSYNC_DIFF_CNTL__VSYNC_HW_LOCK_TYPE             0x00000008L
#define TV_VSYNC_DIFF_CNTL__VSYNC_SLIP_REQ_EN_MASK         0x00000010L
#define TV_VSYNC_DIFF_CNTL__VSYNC_SLIP_REQ_EN              0x00000010L
#define TV_VSYNC_DIFF_CNTL__INVERT_LOCK_CNTL_MASK          0x00000020L
#define TV_VSYNC_DIFF_CNTL__INVERT_LOCK_CNTL               0x00000020L
#define TV_VSYNC_DIFF_CNTL__SLIP_DURING_HSYNC_ONLY_MASK    0x00000040L
#define TV_VSYNC_DIFF_CNTL__SLIP_DURING_HSYNC_ONLY         0x00000040L
#define TV_VSYNC_DIFF_CNTL__RESTART_TWICE_MASK             0x00000080L
#define TV_VSYNC_DIFF_CNTL__RESTART_TWICE                  0x00000080L
#define TV_VSYNC_DIFF_CNTL__DELAY_RESTART_MASK             0x00000100L
#define TV_VSYNC_DIFF_CNTL__DELAY_RESTART                  0x00000100L

// TV_VSYNC_DIFF_LIMITS
#define TV_VSYNC_DIFF_LIMITS__DIFF_LIMIT_LOW_MASK          0x00000fffL
#define TV_VSYNC_DIFF_LIMITS__DIFF_LIMIT_HIGH_MASK         0x0fff0000L

// TV_VSYNC_DIFF_RD_DATA
#define TV_VSYNC_DIFF_RD_DATA__UPDATE_END_TOGGLE_MASK      0x00000001L
#define TV_VSYNC_DIFF_RD_DATA__UPDATE_END_TOGGLE           0x00000001L
#define TV_VSYNC_DIFF_RD_DATA__VSYNC_DIFF_MASK             0x00001ffeL
#define TV_VSYNC_DIFF_RD_DATA__VSYNC_DIFF_OVERFLOW_MASK    0x00002000L
#define TV_VSYNC_DIFF_RD_DATA__VSYNC_DIFF_OVERFLOW         0x00002000L
#define TV_VSYNC_DIFF_RD_DATA__TV_FIRST_MASK               0x00004000L
#define TV_VSYNC_DIFF_RD_DATA__TV_FIRST                    0x00004000L
#define TV_VSYNC_DIFF_RD_DATA__UPDATE_START_TOGGLE_MASK    0x00008000L
#define TV_VSYNC_DIFF_RD_DATA__UPDATE_START_TOGGLE         0x00008000L

// CP_RB_BASE
#define CP_RB_BASE__RB_BASE_MASK                           0xfffffffcL

// CP_RB_CNTL
#define CP_RB_CNTL__RB_BUFSZ_MASK                          0x0000003fL
#define CP_RB_CNTL__RB_BLKSZ_MASK                          0x00003f00L
#define CP_RB_CNTL__BUF_SWAP_MASK                          0x00030000L
#define CP_RB_CNTL__MAX_FETCH_MASK                         0x000c0000L
#define CP_RB_CNTL__RB_NO_UPDATE_MASK                      0x08000000L
#define CP_RB_CNTL__RB_NO_UPDATE                           0x08000000L
#define CP_RB_CNTL__RB_RPTR_WR_ENA_MASK                    0x80000000L
#define CP_RB_CNTL__RB_RPTR_WR_ENA                         0x80000000L

// CP_RB_RPTR_ADDR
#define CP_RB_RPTR_ADDR__RB_RPTR_SWAP_MASK                 0x00000003L
#define CP_RB_RPTR_ADDR__RB_RPTR_ADDR_MASK                 0xfffffffcL

// CP_RB_RPTR
#define CP_RB_RPTR__RB_RPTR_MASK                           0x007fffffL

// CP_RB_RPTR_WR
#define CP_RB_RPTR_WR__RB_RPTR_WR_MASK                     0x007fffffL

// CP_RB_WPTR
#define CP_RB_WPTR__RB_WPTR_MASK                           0x007fffffL

// CP_RB_WPTR_DELAY
#define CP_RB_WPTR_DELAY__PRE_WRITE_TIMER_MASK             0x0fffffffL
#define CP_RB_WPTR_DELAY__PRE_WRITE_LIMIT_MASK             0xf0000000L

// CP_IB_BASE
#define CP_IB_BASE__IB_BASE_MASK                           0xfffffffcL

// CP_IB_BUFSZ
#define CP_IB_BUFSZ__IB_BUFSZ_MASK                         0x007fffffL

// CP_IB2_BASE
#define CP_IB2_BASE__IB2_BASE_MASK                         0xfffffffcL

// CP_IB2_BUFSZ
#define CP_IB2_BUFSZ__IB2_BUFSZ_MASK                       0x007fffffL

// CP_CSQ_CNTL
#define CP_CSQ_CNTL__CSQ_CNT_PRIMARY_R2_MASK               0x000001ffL
#define CP_CSQ_CNTL__CSQ_CNT_INDIRECT_R2_MASK              0x0003fe00L
#define CP_CSQ_CNTL__CSQ_CNT_INDIRECT2_MASK                0x07fc0000L
#define CP_CSQ_CNTL__CSQ_MODE_MASK                         0xf0000000L

// CP_CSQ_APER_PRIMARY
#define CP_CSQ_APER_PRIMARY__CP_CSQ_APER_PRIMARY_MASK      0xffffffffL

// CP_CSQ_APER_INDIRECT
#define CP_CSQ_APER_INDIRECT__CP_CSQ_APER_INDIRECT_MASK    0xffffffffL

// CP_CSQ_APER_INDIRECT2
#define CP_CSQ_APER_INDIRECT2__CP_CSQ_APER_INDIRECT2_MASK  0xffffffffL

// CP_CSQ_MODE
#define CP_CSQ_MODE__INDIRECT2_START_MASK                  0x0000007fL
#define CP_CSQ_MODE__INDIRECT1_START_MASK                  0x00007f00L
#define CP_CSQ_MODE__CSQ_INDIRECT2_MODE_MASK               0x04000000L
#define CP_CSQ_MODE__CSQ_INDIRECT2_MODE                    0x04000000L
#define CP_CSQ_MODE__CSQ_INDIRECT2_ENABLE_MASK             0x08000000L
#define CP_CSQ_MODE__CSQ_INDIRECT2_ENABLE                  0x08000000L
#define CP_CSQ_MODE__CSQ_INDIRECT1_MODE_MASK               0x10000000L
#define CP_CSQ_MODE__CSQ_INDIRECT1_MODE                    0x10000000L
#define CP_CSQ_MODE__CSQ_INDIRECT1_ENABLE_MASK             0x20000000L
#define CP_CSQ_MODE__CSQ_INDIRECT1_ENABLE                  0x20000000L
#define CP_CSQ_MODE__CSQ_PRIMARY_MODE_MASK                 0x40000000L
#define CP_CSQ_MODE__CSQ_PRIMARY_MODE                      0x40000000L
#define CP_CSQ_MODE__CSQ_PRIMARY_ENABLE_MASK               0x80000000L
#define CP_CSQ_MODE__CSQ_PRIMARY_ENABLE                    0x80000000L

// CP_ME_CNTL
#define CP_ME_CNTL__ME_STAT_MASK                           0x0000ffffL
#define CP_ME_CNTL__ME_STATMUX_MASK                        0x001f0000L
#define CP_ME_CNTL__ME_BUSY_MASK                           0x20000000L
#define CP_ME_CNTL__ME_BUSY                                0x20000000L
#define CP_ME_CNTL__ME_MODE_MASK                           0x40000000L
#define CP_ME_CNTL__ME_MODE                                0x40000000L
#define CP_ME_CNTL__ME_STEP_MASK                           0x80000000L
#define CP_ME_CNTL__ME_STEP                                0x80000000L

// CP_ME_RAM_ADDR
#define CP_ME_RAM_ADDR__ME_RAM_ADDR_MASK                   0x000000ffL

// CP_ME_RAM_RADDR
#define CP_ME_RAM_RADDR__ME_RAM_RADDR_MASK                 0x000000ffL

// CP_ME_RAM_DATAH
#define CP_ME_RAM_DATAH__ME_RAM_DATAH_MASK                 0x0000003fL

// CP_ME_RAM_DATAL
#define CP_ME_RAM_DATAL__ME_RAM_DATAL_MASK                 0xffffffffL

// CP_DEBUG
#define CP_DEBUG__CP_DEBUG_MASK                            0xffffffffL

// SCRATCH_REG0
#define SCRATCH_REG0__SCRATCH_REG0_MASK                    0xffffffffL
#define GUI_SCRATCH_REG0__SCRATCH_REG0_MASK                0xffffffffL

// SCRATCH_REG1
#define SCRATCH_REG1__SCRATCH_REG1_MASK                    0xffffffffL
#define GUI_SCRATCH_REG1__SCRATCH_REG1_MASK                0xffffffffL

// SCRATCH_REG2
#define SCRATCH_REG2__SCRATCH_REG2_MASK                    0xffffffffL
#define GUI_SCRATCH_REG2__SCRATCH_REG2_MASK                0xffffffffL

// SCRATCH_REG3
#define SCRATCH_REG3__SCRATCH_REG3_MASK                    0xffffffffL
#define GUI_SCRATCH_REG3__SCRATCH_REG3_MASK                0xffffffffL

// SCRATCH_REG4
#define SCRATCH_REG4__SCRATCH_REG4_MASK                    0xffffffffL
#define GUI_SCRATCH_REG4__SCRATCH_REG4_MASK                0xffffffffL

// SCRATCH_REG5
#define SCRATCH_REG5__SCRATCH_REG5_MASK                    0xffffffffL
#define GUI_SCRATCH_REG5__SCRATCH_REG5_MASK                0xffffffffL

// SCRATCH_REG6
#define SCRATCH_REG6__SCRATCH_REG6_MASK                    0xffffffffL
#define GUI_SCRATCH_REG6__SCRATCH_REG6_MASK                0xffffffffL

// SCRATCH_REG7
#define SCRATCH_REG7__SCRATCH_REG7_MASK                    0xffffffffL
#define GUI_SCRATCH_REG7__SCRATCH_REG7_MASK                0xffffffffL

// SCRATCH_UMSK
#define SCRATCH_UMSK__SCRATCH_UMSK_R2_MASK                 0x000000ffL
#define SCRATCH_UMSK__SCRATCH_SWAP_MASK                    0x00030000L

// SCRATCH_ADDR
#define SCRATCH_ADDR__SCRATCH_ADDR_MASK                    0xffffffe0L

// DMA_GUI_TABLE_ADDR
#define DMA_GUI_TABLE_ADDR__CP_SYNC_MASK                   0x00000001L
#define DMA_GUI_TABLE_ADDR__CP_SYNC                        0x00000001L
#define DMA_GUI_TABLE_ADDR__TABLE_ADDR_MASK                0xfffffff0L

// DMA_GUI_SRC_ADDR
#define DMA_GUI_SRC_ADDR__SRC_ADDR_MASK                    0xffffffffL

// DMA_GUI_DST_ADDR
#define DMA_GUI_DST_ADDR__DST_ADDR_MASK                    0xffffffffL

// DMA_GUI_COMMAND
#define DMA_GUI_COMMAND__BYTE_COUNT_MASK                   0x001fffffL
#define DMA_GUI_COMMAND__SRC_SWAP_MASK                     0x00c00000L
#define DMA_GUI_COMMAND__DST_SWAP_MASK                     0x03000000L
#define DMA_GUI_COMMAND__SAS_MASK                          0x04000000L
#define DMA_GUI_COMMAND__SAS                               0x04000000L
#define DMA_GUI_COMMAND__DAS_MASK                          0x08000000L
#define DMA_GUI_COMMAND__DAS                               0x08000000L
#define DMA_GUI_COMMAND__SAIC_MASK                         0x10000000L
#define DMA_GUI_COMMAND__SAIC                              0x10000000L
#define DMA_GUI_COMMAND__DAIC_MASK                         0x20000000L
#define DMA_GUI_COMMAND__DAIC                              0x20000000L
#define DMA_GUI_COMMAND__INTDIS_MASK                       0x40000000L
#define DMA_GUI_COMMAND__INTDIS                            0x40000000L
#define DMA_GUI_COMMAND__EOL_MASK                          0x80000000L
#define DMA_GUI_COMMAND__EOL                               0x80000000L

// DMA_GUI_STATUS
#define DMA_GUI_STATUS__DTAQ_AVAIL_MASK                    0x0000001fL
#define DMA_GUI_STATUS__LAST_TABLE_NUM_MASK                0x00000f00L
#define DMA_GUI_STATUS__CURRENT_TABLE_NUM_MASK             0x0000f000L
#define DMA_GUI_STATUS__ABORT_EN_MASK                      0x00100000L
#define DMA_GUI_STATUS__ABORT_EN                           0x00100000L
#define DMA_GUI_STATUS__ACTIVE_MASK                        0x00200000L
#define DMA_GUI_STATUS__ACTIVE                             0x00200000L
#define DMA_GUI_STATUS__SWAP_MASK                          0x00c00000L

// DMA_GUI_ACT_DSCRPTR
#define DMA_GUI_ACT_DSCRPTR__TABLE_ADDR_MASK               0xfffffff0L

// CP_GUI_SRC_ADDR
#define CP_GUI_SRC_ADDR__CP_GUI_SRC_ADDR_MASK              0xffffffffL

// CP_GUI_DST_ADDR
#define CP_GUI_DST_ADDR__CP_GUI_DST_ADDR_MASK              0xffffffffL

// CP_GUI_COMMAND
#define CP_GUI_COMMAND__CP_GUI_COMMAND_MASK                0xffffffffL

// DMA_VID_TABLE_ADDR
#define DMA_VID_TABLE_ADDR__CP_SYNC_MASK                   0x00000001L
#define DMA_VID_TABLE_ADDR__CP_SYNC                        0x00000001L
#define DMA_VID_TABLE_ADDR__TABLE_ADDR_MASK                0xfffffff0L

// DMA_VID_SRC_ADDR
#define DMA_VID_SRC_ADDR__SRC_ADDR_MASK                    0xffffffffL

// DMA_VID_DST_ADDR
#define DMA_VID_DST_ADDR__DST_ADDR_MASK                    0xffffffffL

// DMA_VID_COMMAND
#define DMA_VID_COMMAND__BYTE_COUNT_MASK                   0x001fffffL
#define DMA_VID_COMMAND__SRC_SWAP_MASK                     0x00c00000L
#define DMA_VID_COMMAND__DST_SWAP_MASK                     0x03000000L
#define DMA_VID_COMMAND__SAS_MASK                          0x04000000L
#define DMA_VID_COMMAND__SAS                               0x04000000L
#define DMA_VID_COMMAND__DAS_MASK                          0x08000000L
#define DMA_VID_COMMAND__DAS                               0x08000000L
#define DMA_VID_COMMAND__SAIC_MASK                         0x10000000L
#define DMA_VID_COMMAND__SAIC                              0x10000000L
#define DMA_VID_COMMAND__DAIC_MASK                         0x20000000L
#define DMA_VID_COMMAND__DAIC                              0x20000000L
#define DMA_VID_COMMAND__INTDIS_MASK                       0x40000000L
#define DMA_VID_COMMAND__INTDIS                            0x40000000L
#define DMA_VID_COMMAND__EOL_MASK                          0x80000000L
#define DMA_VID_COMMAND__EOL                               0x80000000L

// DMA_VID_STATUS
#define DMA_VID_STATUS__DTAQ_AVAIL_MASK                    0x0000001fL
#define DMA_VID_STATUS__LAST_TABLE_NUM_MASK                0x00000f00L
#define DMA_VID_STATUS__CURRENT_TABLE_NUM_MASK             0x0000f000L
#define DMA_VID_STATUS__ABORT_EN_MASK                      0x00100000L
#define DMA_VID_STATUS__ABORT_EN                           0x00100000L
#define DMA_VID_STATUS__ACTIVE_MASK                        0x00200000L
#define DMA_VID_STATUS__ACTIVE                             0x00200000L
#define DMA_VID_STATUS__SWAP_MASK                          0x00c00000L

// DMA_VID_ACT_DSCRPTR
#define DMA_VID_ACT_DSCRPTR__TABLE_ADDR_MASK               0xfffffff0L

// CP_VID_SRC_ADDR
#define CP_VID_SRC_ADDR__CP_VID_SRC_ADDR_MASK              0xffffffffL

// CP_VID_DST_ADDR
#define CP_VID_DST_ADDR__CP_VID_DST_ADDR_MASK              0xffffffffL

// CP_VID_COMMAND
#define CP_VID_COMMAND__CP_VID_COMMAND_MASK                0xffffffffL

// CP_CSQ2_STAT
#define CP_CSQ2_STAT__CSQ_WPTR_INDIRECT_MASK               0x000001ffL
#define CP_CSQ2_STAT__CSQ_RPTR_INDIRECT2_MASK              0x0003fe00L
#define CP_CSQ2_STAT__CSQ_WPTR_INDIRECT2_MASK              0x07fc0000L

// CP_CSQ_ADDR
#define CP_CSQ_ADDR__CSQ_ADDR_R2_MASK                      0x000007fcL

// CP_CSQ_DATA
#define CP_CSQ_DATA__CSQ_DATA_MASK                         0xffffffffL

// CP_CSQ_STAT
#define CP_CSQ_STAT__CSQ_RPTR_PRIMARY_R2_MASK              0x000001ffL
#define CP_CSQ_STAT__CSQ_WPTR_PRIMARY_R2_MASK              0x0003fe00L
#define CP_CSQ_STAT__CSQ_RPTR_INDIRECT_R2_MASK             0x07fc0000L

// CP_STAT
#define CP_STAT__MRU_BUSY_MASK                             0x00000001L
#define CP_STAT__MRU_BUSY                                  0x00000001L
#define CP_STAT__MWU_BUSY_MASK                             0x00000002L
#define CP_STAT__MWU_BUSY                                  0x00000002L
#define CP_STAT__RSIU_BUSY_MASK                            0x00000004L
#define CP_STAT__RSIU_BUSY                                 0x00000004L
#define CP_STAT__RCIU_BUSY_MASK                            0x00000008L
#define CP_STAT__RCIU_BUSY                                 0x00000008L
#define CP_STAT__CSF_PRIMARY_BUSY_MASK                     0x00000200L
#define CP_STAT__CSF_PRIMARY_BUSY                          0x00000200L
#define CP_STAT__CSF_INDIRECT_BUSY_MASK                    0x00000400L
#define CP_STAT__CSF_INDIRECT_BUSY                         0x00000400L
#define CP_STAT__CSQ_PRIMARY_BUSY_MASK                     0x00000800L
#define CP_STAT__CSQ_PRIMARY_BUSY                          0x00000800L
#define CP_STAT__CSQ_INDIRECT_BUSY_MASK                    0x00001000L
#define CP_STAT__CSQ_INDIRECT_BUSY                         0x00001000L
#define CP_STAT__CSI_BUSY_MASK                             0x00002000L
#define CP_STAT__CSI_BUSY                                  0x00002000L
#define CP_STAT__CSF_INDIRECT2_BUSY_MASK                   0x00004000L
#define CP_STAT__CSF_INDIRECT2_BUSY                        0x00004000L
#define CP_STAT__CSQ_INDIRECT2_BUSY_MASK                   0x00008000L
#define CP_STAT__CSQ_INDIRECT2_BUSY                        0x00008000L
#define CP_STAT__GUIDMA_BUSY_MASK                          0x10000000L
#define CP_STAT__GUIDMA_BUSY                               0x10000000L
#define CP_STAT__VIDDMA_BUSY_MASK                          0x20000000L
#define CP_STAT__VIDDMA_BUSY                               0x20000000L
#define CP_STAT__CMDSTRM_BUSY_MASK                         0x40000000L
#define CP_STAT__CMDSTRM_BUSY                              0x40000000L
#define CP_STAT__CP_BUSY_MASK                              0x80000000L
#define CP_STAT__CP_BUSY                                   0x80000000L

// SE_PORT_DATA0
#define SE_PORT_DATA0__DATAPORT0_MASK                      0xffffffffL

// SE_PORT_DATA1
#define SE_PORT_DATA1__DATAPORT1_MASK                      0xffffffffL

// SE_PORT_DATA2
#define SE_PORT_DATA2__DATAPORT2_MASK                      0xffffffffL

// SE_PORT_DATA3
#define SE_PORT_DATA3__DATAPORT3_MASK                      0xffffffffL

// SE_PORT_DATA4
#define SE_PORT_DATA4__DATAPORT4_MASK                      0xffffffffL

// SE_PORT_DATA5
#define SE_PORT_DATA5__DATAPORT5_MASK                      0xffffffffL

// SE_PORT_DATA6
#define SE_PORT_DATA6__DATAPORT6_MASK                      0xffffffffL

// SE_PORT_DATA7
#define SE_PORT_DATA7__DATAPORT7_MASK                      0xffffffffL

// SE_PORT_DATA8
#define SE_PORT_DATA8__DATAPORT8_MASK                      0xffffffffL

// SE_PORT_DATA9
#define SE_PORT_DATA9__DATAPORT9_MASK                      0xffffffffL

// SE_PORT_DATA10
#define SE_PORT_DATA10__DATAPORT10_MASK                    0xffffffffL

// SE_PORT_DATA11
#define SE_PORT_DATA11__DATAPORT11_MASK                    0xffffffffL

// SE_PORT_DATA12
#define SE_PORT_DATA12__DATAPORT12_MASK                    0xffffffffL

// SE_PORT_DATA13
#define SE_PORT_DATA13__DATAPORT13_MASK                    0xffffffffL

// SE_PORT_DATA14
#define SE_PORT_DATA14__DATAPORT14_MASK                    0xffffffffL

// SE_PORT_DATA15
#define SE_PORT_DATA15__DATAPORT15_MASK                    0xffffffffL

// SE_PORT_IDX0
#define SE_PORT_IDX0__IDXPORT0_MASK                        0xffffffffL

// SE_PORT_IDX1
#define SE_PORT_IDX1__IDXPORT1_MASK                        0xffffffffL

// SE_PORT_IDX2
#define SE_PORT_IDX2__IDXPORT2_MASK                        0xffffffffL

// SE_PORT_IDX3
#define SE_PORT_IDX3__IDXPORT3_MASK                        0xffffffffL

// SE_PORT_IDX4
#define SE_PORT_IDX4__IDXPORT4_MASK                        0xffffffffL

// SE_PORT_IDX5
#define SE_PORT_IDX5__IDXPORT5_MASK                        0xffffffffL

// SE_PORT_IDX6
#define SE_PORT_IDX6__IDXPORT6_MASK                        0xffffffffL

// SE_PORT_IDX7
#define SE_PORT_IDX7__IDXPORT7_MASK                        0xffffffffL

// SE_PORT_IDX8
#define SE_PORT_IDX8__IDXPORT8_MASK                        0xffffffffL

// SE_PORT_IDX9
#define SE_PORT_IDX9__IDXPORT9_MASK                        0xffffffffL

// SE_PORT_IDX10
#define SE_PORT_IDX10__IDXPORT10_MASK                      0xffffffffL

// SE_PORT_IDX11
#define SE_PORT_IDX11__IDXPORT11_MASK                      0xffffffffL

// SE_PORT_IDX12
#define SE_PORT_IDX12__IDXPORT12_MASK                      0xffffffffL

// SE_PORT_IDX13
#define SE_PORT_IDX13__IDXPORT13_MASK                      0xffffffffL

// SE_PORT_IDX14
#define SE_PORT_IDX14__IDXPORT14_MASK                      0xffffffffL

// SE_PORT_IDX15
#define SE_PORT_IDX15__IDXPORT15_MASK                      0xffffffffL

// SE_VAP_CNTL
#define SE_VAP_CNTL__TCL_ENA_MASK                          0x00000001L
#define SE_VAP_CNTL__TCL_ENA                               0x00000001L
#define SE_VAP_CNTL__PROG_VTX_SHADER_ENA_MASK              0x00000004L
#define SE_VAP_CNTL__PROG_VTX_SHADER_ENA                   0x00000004L
#define SE_VAP_CNTL__PER_VTX_MTX_SEL_ENA_MASK              0x00000008L
#define SE_VAP_CNTL__PER_VTX_MTX_SEL_ENA                   0x00000008L
#define SE_VAP_CNTL__SINGLE_BUF_STATE_ENA_MASK             0x00000010L
#define SE_VAP_CNTL__SINGLE_BUF_STATE_ENA                  0x00000010L
#define SE_VAP_CNTL__FORCE_W_TO_ONE_MASK                   0x00010000L
#define SE_VAP_CNTL__FORCE_W_TO_ONE                        0x00010000L
#define SE_VAP_CNTL__D3D_TEX_DEFAULT_MASK                  0x00020000L
#define SE_VAP_CNTL__D3D_TEX_DEFAULT                       0x00020000L
#define SE_VAP_CNTL__VF_MAX_VTX_NUM_MASK                   0x003c0000L
#define SE_VAP_CNTL__DX_CLIP_SPACE_DEF_MASK                0x00400000L
#define SE_VAP_CNTL__DX_CLIP_SPACE_DEF                     0x00400000L

// SE_VF_CNTL
#define SE_VF_CNTL__PRIM_TYPE_MASK                         0x0000000fL
#define SE_VF_CNTL__PRIM_WALK_MASK                         0x00000030L
#define SE_VF_CNTL__COLOR_ORDER_MASK                       0x00000040L
#define SE_VF_CNTL__COLOR_ORDER                            0x00000040L
#define SE_VF_CNTL__TCL_OUTPUT_CTL_ENA_MASK                0x00000200L
#define SE_VF_CNTL__TCL_OUTPUT_CTL_ENA                     0x00000200L
#define SE_VF_CNTL__PROG_STREAM_ENA_MASK                   0x00000400L
#define SE_VF_CNTL__PROG_STREAM_ENA                        0x00000400L
#define SE_VF_CNTL__INDEX_SIZE_MASK                        0x00000800L
#define SE_VF_CNTL__INDEX_SIZE                             0x00000800L
#define SE_VF_CNTL__NUM_VERTICES_MASK                      0xffff0000L

// SE_VTX_FMT_0
#define SE_VTX_FMT_0__VTX_Z0_PRESENT_MASK                  0x00000001L
#define SE_VTX_FMT_0__VTX_Z0_PRESENT                       0x00000001L
#define SE_VTX_FMT_0__VTX_W0_PRESENT_MASK                  0x00000002L
#define SE_VTX_FMT_0__VTX_W0_PRESENT                       0x00000002L
#define SE_VTX_FMT_0__VTX_BLEND_WEIGHT_CNT_MASK            0x0000001cL
#define SE_VTX_FMT_0__VTX_PV_MTX_SEL_PRESENT_MASK          0x00000020L
#define SE_VTX_FMT_0__VTX_PV_MTX_SEL_PRESENT               0x00000020L
#define SE_VTX_FMT_0__VTX_N0_PRESENT_MASK                  0x00000040L
#define SE_VTX_FMT_0__VTX_N0_PRESENT                       0x00000040L
#define SE_VTX_FMT_0__VTX_PT_SIZE_PRESENT_MASK             0x00000080L
#define SE_VTX_FMT_0__VTX_PT_SIZE_PRESENT                  0x00000080L
#define SE_VTX_FMT_0__VTX_DISCRETE_FOG_PRESENT_MASK        0x00000100L
#define SE_VTX_FMT_0__VTX_DISCRETE_FOG_PRESENT             0x00000100L
#define SE_VTX_FMT_0__VTX_SHININESS_0_PRESENT_MASK         0x00000200L
#define SE_VTX_FMT_0__VTX_SHININESS_0_PRESENT              0x00000200L
#define SE_VTX_FMT_0__VTX_SHININESS_1_PRESENT_MASK         0x00000400L
#define SE_VTX_FMT_0__VTX_SHININESS_1_PRESENT              0x00000400L
#define SE_VTX_FMT_0__VTX_COLOR_0_FMT_MASK                 0x00001800L
#define SE_VTX_FMT_0__VTX_COLOR_1_FMT_MASK                 0x00006000L
#define SE_VTX_FMT_0__VTX_COLOR_2_FMT_MASK                 0x00018000L
#define SE_VTX_FMT_0__VTX_COLOR_3_FMT_MASK                 0x00060000L
#define SE_VTX_FMT_0__VTX_COLOR_4_FMT_MASK                 0x00180000L
#define SE_VTX_FMT_0__VTX_COLOR_5_FMT_MASK                 0x00600000L
#define SE_VTX_FMT_0__VTX_COLOR_6_FMT_MASK                 0x01800000L
#define SE_VTX_FMT_0__VTX_COLOR_7_FMT_MASK                 0x06000000L
#define SE_VTX_FMT_0__VTX_XY1_PRESENT_MASK                 0x10000000L
#define SE_VTX_FMT_0__VTX_XY1_PRESENT                      0x10000000L
#define SE_VTX_FMT_0__VTX_Z1_PRESENT_MASK                  0x20000000L
#define SE_VTX_FMT_0__VTX_Z1_PRESENT                       0x20000000L
#define SE_VTX_FMT_0__VTX_W1_PRESENT_MASK                  0x40000000L
#define SE_VTX_FMT_0__VTX_W1_PRESENT                       0x40000000L
#define SE_VTX_FMT_0__VTX_N1_PRESENT_MASK                  0x80000000L
#define SE_VTX_FMT_0__VTX_N1_PRESENT                       0x80000000L

// SE_VTX_FMT_1
#define SE_VTX_FMT_1__TEX_0_COMP_CNT_MASK                  0x00000007L
#define SE_VTX_FMT_1__TEX_1_COMP_CNT_MASK                  0x00000038L
#define SE_VTX_FMT_1__TEX_2_COMP_CNT_MASK                  0x000001c0L
#define SE_VTX_FMT_1__TEX_3_COMP_CNT_MASK                  0x00000e00L
#define SE_VTX_FMT_1__TEX_4_COMP_CNT_MASK                  0x00007000L
#define SE_VTX_FMT_1__TEX_5_COMP_CNT_MASK                  0x00038000L

// SE_TCL_OUTPUT_VTX_FMT_0
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_Z0_PRESENT_MASK       0x00000001L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_Z0_PRESENT            0x00000001L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_W0_PRESENT_MASK       0x00000002L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_W0_PRESENT            0x00000002L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_BLEND_WEIGHT_CNT_MASK 0x0000001cL
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_PV_MTX_SEL_PRESENT_MASK 0x00000020L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_PV_MTX_SEL_PRESENT    0x00000020L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_N0_PRESENT_MASK       0x00000040L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_N0_PRESENT            0x00000040L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_PT_SIZE_PRESENT_MASK  0x00000080L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_PT_SIZE_PRESENT       0x00000080L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_DISCRETE_FOG_PRESENT_MASK 0x00000100L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_DISCRETE_FOG_PRESENT  0x00000100L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_SHININESS_0_PRESENT_MASK 0x00000200L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_SHININESS_0_PRESENT   0x00000200L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_SHININESS_1_PRESENT_MASK 0x00000400L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_SHININESS_1_PRESENT   0x00000400L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_0_FMT_MASK      0x00001800L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_1_FMT_MASK      0x00006000L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_2_FMT_MASK      0x00018000L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_3_FMT_MASK      0x00060000L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_4_FMT_MASK      0x00180000L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_5_FMT_MASK      0x00600000L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_6_FMT_MASK      0x01800000L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_COLOR_7_FMT_MASK      0x06000000L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_XY1_PRESENT_MASK      0x10000000L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_XY1_PRESENT           0x10000000L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_Z1_PRESENT_MASK       0x20000000L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_Z1_PRESENT            0x20000000L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_W1_PRESENT_MASK       0x40000000L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_W1_PRESENT            0x40000000L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_N1_PRESENT_MASK       0x80000000L
#define SE_TCL_OUTPUT_VTX_FMT_0__VTX_N1_PRESENT            0x80000000L

// SE_TCL_OUTPUT_VTX_FMT_1
#define SE_TCL_OUTPUT_VTX_FMT_1__TEX_0_COMP_CNT_MASK       0x00000007L
#define SE_TCL_OUTPUT_VTX_FMT_1__TEX_1_COMP_CNT_MASK       0x00000038L
#define SE_TCL_OUTPUT_VTX_FMT_1__TEX_2_COMP_CNT_MASK       0x000001c0L
#define SE_TCL_OUTPUT_VTX_FMT_1__TEX_3_COMP_CNT_MASK       0x00000e00L
#define SE_TCL_OUTPUT_VTX_FMT_1__TEX_4_COMP_CNT_MASK       0x00007000L
#define SE_TCL_OUTPUT_VTX_FMT_1__TEX_5_COMP_CNT_MASK       0x00038000L

// SE_VPORT_XSCALE
#define SE_VPORT_XSCALE__VPORT_XSCALE_MASK                 0xffffffffL

// SE_VPORT_XOFFSET
#define SE_VPORT_XOFFSET__VPORT_XOFFSET_MASK               0xffffffffL

// SE_VPORT_YSCALE
#define SE_VPORT_YSCALE__VPORT_YSCALE_MASK                 0xffffffffL

// SE_VPORT_YOFFSET
#define SE_VPORT_YOFFSET__VPORT_YOFFSET_MASK               0xffffffffL

// SE_VPORT_ZSCALE
#define SE_VPORT_ZSCALE__VPORT_ZSCALE_MASK                 0xffffffffL

// SE_VPORT_ZOFFSET
#define SE_VPORT_ZOFFSET__VPORT_ZOFFSET_MASK               0xffffffffL

// SE_VTE_CNTL
#define SE_VTE_CNTL__VPORT_X_SCALE_ENA_MASK                0x00000001L
#define SE_VTE_CNTL__VPORT_X_SCALE_ENA                     0x00000001L
#define SE_VTE_CNTL__VPORT_X_OFFSET_ENA_MASK               0x00000002L
#define SE_VTE_CNTL__VPORT_X_OFFSET_ENA                    0x00000002L
#define SE_VTE_CNTL__VPORT_Y_SCALE_ENA_MASK                0x00000004L
#define SE_VTE_CNTL__VPORT_Y_SCALE_ENA                     0x00000004L
#define SE_VTE_CNTL__VPORT_Y_OFFSET_ENA_MASK               0x00000008L
#define SE_VTE_CNTL__VPORT_Y_OFFSET_ENA                    0x00000008L
#define SE_VTE_CNTL__VPORT_Z_SCALE_ENA_MASK                0x00000010L
#define SE_VTE_CNTL__VPORT_Z_SCALE_ENA                     0x00000010L
#define SE_VTE_CNTL__VPORT_Z_OFFSET_ENA_MASK               0x00000020L
#define SE_VTE_CNTL__VPORT_Z_OFFSET_ENA                    0x00000020L
#define SE_VTE_CNTL__VTX_XY_FMT_MASK                       0x00000100L
#define SE_VTE_CNTL__VTX_XY_FMT                            0x00000100L
#define SE_VTE_CNTL__VTX_Z_FMT_MASK                        0x00000200L
#define SE_VTE_CNTL__VTX_Z_FMT                             0x00000200L
#define SE_VTE_CNTL__VTX_W0_FMT_MASK                       0x00000400L
#define SE_VTE_CNTL__VTX_W0_FMT                            0x00000400L
#define SE_VTE_CNTL__VTX_W0_NORMALIZE_MASK                 0x00000800L
#define SE_VTE_CNTL__VTX_W0_NORMALIZE                      0x00000800L
#define SE_VTE_CNTL__VTX_ST_DENORMALIZED_MASK              0x00001000L
#define SE_VTE_CNTL__VTX_ST_DENORMALIZED                   0x00001000L

// SE_W0_RANGE
#define SE_W0_RANGE__W0_RANGE_MASK                         0xffffffffL

// SE_VTX_NUM_ARRAYS
#define SE_VTX_NUM_ARRAYS__VTX_NUM_ARRAYS_M9_MASK          0x0000000fL
#define SE_VTX_NUM_ARRAYS__VTX_REUSE_DISABLE_MASK          0x00000010L
#define SE_VTX_NUM_ARRAYS__VTX_REUSE_DISABLE               0x00000010L
#define SE_VTX_NUM_ARRAYS__VC_PFETCH_MASK                  0x0000c000L

// SE_VTX_AOS_ATTR01
#define SE_VTX_AOS_ATTR01__VTX_AOS_COUNT0_R2_MASK          0x0000007fL
#define SE_VTX_AOS_ATTR01__VTX_AOS_STRIDE0_R2_MASK         0x00007f00L
#define SE_VTX_AOS_ATTR01__VTX_AOS_COUNT1_R2_MASK          0x007f0000L
#define SE_VTX_AOS_ATTR01__VTX_AOS_STRIDE1_R2_MASK         0x7f000000L

// SE_VTX_AOS_ADDR0
#define SE_VTX_AOS_ADDR0__VTX_AOS_ADDR0_MASK               0xfffffffcL

// SE_VTX_AOS_ADDR1
#define SE_VTX_AOS_ADDR1__VTX_AOS_ADDR1_MASK               0xfffffffcL

// SE_VTX_AOS_ATTR23
#define SE_VTX_AOS_ATTR23__VTX_AOS_COUNT2_R2_MASK          0x0000007fL
#define SE_VTX_AOS_ATTR23__VTX_AOS_STRIDE2_R2_MASK         0x00007f00L
#define SE_VTX_AOS_ATTR23__VTX_AOS_COUNT3_R2_MASK          0x007f0000L
#define SE_VTX_AOS_ATTR23__VTX_AOS_STRIDE3_R2_MASK         0x7f000000L

// SE_VTX_AOS_ADDR2
#define SE_VTX_AOS_ADDR2__VTX_AOS_ADDR2_MASK               0xfffffffcL

// SE_VTX_AOS_ADDR3
#define SE_VTX_AOS_ADDR3__VTX_AOS_ADDR3_MASK               0xfffffffcL

// SE_VTX_AOS_ATTR45
#define SE_VTX_AOS_ATTR45__VTX_AOS_COUNT4_R2_MASK          0x0000007fL
#define SE_VTX_AOS_ATTR45__VTX_AOS_STRIDE4_R2_MASK         0x00007f00L
#define SE_VTX_AOS_ATTR45__VTX_AOS_COUNT5_R2_MASK          0x007f0000L
#define SE_VTX_AOS_ATTR45__VTX_AOS_STRIDE5_R2_MASK         0x7f000000L

// SE_VTX_AOS_ADDR4
#define SE_VTX_AOS_ADDR4__VTX_AOS_ADDR4_MASK               0xfffffffcL

// SE_VTX_AOS_ADDR5
#define SE_VTX_AOS_ADDR5__VTX_AOS_ADDR5_MASK               0xfffffffcL

// SE_VTX_AOS_ATTR67
#define SE_VTX_AOS_ATTR67__VTX_AOS_COUNT6_R2_MASK          0x0000007fL
#define SE_VTX_AOS_ATTR67__VTX_AOS_STRIDE6_R2_MASK         0x00007f00L
#define SE_VTX_AOS_ATTR67__VTX_AOS_COUNT7_R2_MASK          0x007f0000L
#define SE_VTX_AOS_ATTR67__VTX_AOS_STRIDE7_R2_MASK         0x7f000000L

// SE_VTX_AOS_ADDR6
#define SE_VTX_AOS_ADDR6__VTX_AOS_ADDR6_MASK               0xfffffffcL

// SE_VTX_AOS_ADDR7
#define SE_VTX_AOS_ADDR7__VTX_AOS_ADDR7_MASK               0xfffffffcL

// SE_VTX_AOS_ATTR89
#define SE_VTX_AOS_ATTR89__VTX_AOS_COUNT8_R2_MASK          0x0000007fL
#define SE_VTX_AOS_ATTR89__VTX_AOS_STRIDE8_R2_MASK         0x00007f00L
#define SE_VTX_AOS_ATTR89__VTX_AOS_COUNT9_R2_MASK          0x007f0000L
#define SE_VTX_AOS_ATTR89__VTX_AOS_STRIDE9_R2_MASK         0x7f000000L

// SE_VTX_AOS_ADDR8
#define SE_VTX_AOS_ADDR8__VTX_AOS_ADDR8_MASK               0xfffffffcL

// SE_VTX_AOS_ADDR9
#define SE_VTX_AOS_ADDR9__VTX_AOS_ADDR9_MASK               0xfffffffcL

// SE_VTX_AOS_ATTR1011
#define SE_VTX_AOS_ATTR1011__VTX_AOS_COUNT10_R2_MASK       0x0000007fL
#define SE_VTX_AOS_ATTR1011__VTX_AOS_STRIDE10_R2_MASK      0x00007f00L
#define SE_VTX_AOS_ATTR1011__VTX_AOS_COUNT11_R2_MASK       0x007f0000L
#define SE_VTX_AOS_ATTR1011__VTX_AOS_STRIDE11_R2_MASK      0x7f000000L

// SE_VTX_AOS_ADDR10
#define SE_VTX_AOS_ADDR10__VTX_AOS_ADDR10_MASK             0xfffffffcL

// SE_VTX_AOS_ADDR11
#define SE_VTX_AOS_ADDR11__VTX_AOS_ADDR11_MASK             0xfffffffcL

// SE_VF_MAX_VTX_INDX
#define SE_VF_MAX_VTX_INDX__MAX_INDX_MASK                  0x00ffffffL

// SE_VF_MIN_VTX_INDX
#define SE_VF_MIN_VTX_INDX__MIN_INDX_MASK                  0x00ffffffL

// SE_VAP_PERF_CNTL_0
#define SE_VAP_PERF_CNTL_0__PERF_SEL_0_MASK                0x0000000fL
#define SE_VAP_PERF_CNTL_0__CLR_PERF_0_MASK                0x00000010L
#define SE_VAP_PERF_CNTL_0__CLR_PERF_0                     0x00000010L
#define SE_VAP_PERF_CNTL_0__EN_PERF_0_MASK                 0x00000020L
#define SE_VAP_PERF_CNTL_0__EN_PERF_0                      0x00000020L
#define SE_VAP_PERF_CNTL_0__NUM_VERTS_TO_BYPASS_0_MASK     0x0000ff00L
#define SE_VAP_PERF_CNTL_0__NUM_VERTS_TO_COUNT_0_MASK      0xffff0000L

// SE_VAP_PERF_CNTL_1
#define SE_VAP_PERF_CNTL_1__PERF_SEL_1_MASK                0x0000000fL
#define SE_VAP_PERF_CNTL_1__CLR_PERF_1_MASK                0x00000010L
#define SE_VAP_PERF_CNTL_1__CLR_PERF_1                     0x00000010L
#define SE_VAP_PERF_CNTL_1__EN_PERF_1_MASK                 0x00000020L
#define SE_VAP_PERF_CNTL_1__EN_PERF_1                      0x00000020L
#define SE_VAP_PERF_CNTL_1__NUM_VERTS_TO_BYPASS_1_MASK     0x0000ff00L
#define SE_VAP_PERF_CNTL_1__NUM_VERTS_TO_COUNT_1_MASK      0xffff0000L

// SE_VAP_PERF_COUNT_0
#define SE_VAP_PERF_COUNT_0__PERF_COUNT_0_MASK             0xffffffffL

// SE_VAP_PERF_COUNT_1
#define SE_VAP_PERF_COUNT_1__PERF_COUNT_1_MASK             0xffffffffL

// SE_DEBUG
#define SE_DEBUG__SE_DEBUG_MASK                            0xffffffffL

// SE_VAP_CNTL_STATUS
#define SE_VAP_CNTL_STATUS__VC_SWAP_MASK                   0x00000003L
#define SE_VAP_CNTL_STATUS__TCL_BYPASS_MASK                0x00000100L
#define SE_VAP_CNTL_STATUS__TCL_BYPASS                     0x00000100L
#define SE_VAP_CNTL_STATUS__TCL_BUSY_MASK                  0x00000800L
#define SE_VAP_CNTL_STATUS__TCL_BUSY                       0x00000800L
#define SE_VAP_CNTL_STATUS__PERF_BUSY_MASK                 0x00010000L
#define SE_VAP_CNTL_STATUS__PERF_BUSY                      0x00010000L
#define SE_VAP_CNTL_STATUS__PRIMITIVE_BYPASS_BUSY_MASK     0x01000000L
#define SE_VAP_CNTL_STATUS__PRIMITIVE_BYPASS_BUSY          0x01000000L
#define SE_VAP_CNTL_STATUS__RCP_BUSY_MASK                  0x02000000L
#define SE_VAP_CNTL_STATUS__RCP_BUSY                       0x02000000L
#define SE_VAP_CNTL_STATUS__VAPB_RBIU_SLAVE_BUSY_MASK      0x04000000L
#define SE_VAP_CNTL_STATUS__VAPB_RBIU_SLAVE_BUSY           0x04000000L
#define SE_VAP_CNTL_STATUS__MIU_BUSY_MASK                  0x08000000L
#define SE_VAP_CNTL_STATUS__MIU_BUSY                       0x08000000L
#define SE_VAP_CNTL_STATUS__VC_BUSY_MASK                   0x10000000L
#define SE_VAP_CNTL_STATUS__VC_BUSY                        0x10000000L
#define SE_VAP_CNTL_STATUS__VF_BUSY_MASK                   0x20000000L
#define SE_VAP_CNTL_STATUS__VF_BUSY                        0x20000000L
#define SE_VAP_CNTL_STATUS__REGPIPE_BUSY_MASK              0x40000000L
#define SE_VAP_CNTL_STATUS__REGPIPE_BUSY                   0x40000000L
#define SE_VAP_CNTL_STATUS__VAP_BUSY_MASK                  0x80000000L
#define SE_VAP_CNTL_STATUS__VAP_BUSY                       0x80000000L

// SE_PROG_STREAM_CNTL_0
#define SE_PROG_STREAM_CNTL_0__DATA_TYPE_0_MASK            0x0000000fL
#define SE_PROG_STREAM_CNTL_0__SKIP_DWORDS_0_MASK          0x000000f0L
#define SE_PROG_STREAM_CNTL_0__DST_VEC_LOC_0_MASK          0x00001f00L
#define SE_PROG_STREAM_CNTL_0__LAST_VEC_0_MASK             0x00002000L
#define SE_PROG_STREAM_CNTL_0__LAST_VEC_0                  0x00002000L
#define SE_PROG_STREAM_CNTL_0__SIGNED_0_MASK               0x00004000L
#define SE_PROG_STREAM_CNTL_0__SIGNED_0                    0x00004000L
#define SE_PROG_STREAM_CNTL_0__NORMALIZE_0_MASK            0x00008000L
#define SE_PROG_STREAM_CNTL_0__NORMALIZE_0                 0x00008000L
#define SE_PROG_STREAM_CNTL_0__DATA_TYPE_1_MASK            0x000f0000L
#define SE_PROG_STREAM_CNTL_0__SKIP_DWORDS_1_MASK          0x00f00000L
#define SE_PROG_STREAM_CNTL_0__DST_VEC_LOC_1_MASK          0x1f000000L
#define SE_PROG_STREAM_CNTL_0__LAST_VEC_1_MASK             0x20000000L
#define SE_PROG_STREAM_CNTL_0__LAST_VEC_1                  0x20000000L
#define SE_PROG_STREAM_CNTL_0__SIGNED_1_MASK               0x40000000L
#define SE_PROG_STREAM_CNTL_0__SIGNED_1                    0x40000000L
#define SE_PROG_STREAM_CNTL_0__NORMALIZE_1_MASK            0x80000000L
#define SE_PROG_STREAM_CNTL_0__NORMALIZE_1                 0x80000000L

// SE_PROG_STREAM_CNTL_1
#define SE_PROG_STREAM_CNTL_1__DATA_TYPE_2_MASK            0x0000000fL
#define SE_PROG_STREAM_CNTL_1__SKIP_DWORDS_2_MASK          0x000000f0L
#define SE_PROG_STREAM_CNTL_1__DST_VEC_LOC_2_MASK          0x00001f00L
#define SE_PROG_STREAM_CNTL_1__LAST_VEC_2_MASK             0x00002000L
#define SE_PROG_STREAM_CNTL_1__LAST_VEC_2                  0x00002000L
#define SE_PROG_STREAM_CNTL_1__SIGNED_2_MASK               0x00004000L
#define SE_PROG_STREAM_CNTL_1__SIGNED_2                    0x00004000L
#define SE_PROG_STREAM_CNTL_1__NORMALIZE_2_MASK            0x00008000L
#define SE_PROG_STREAM_CNTL_1__NORMALIZE_2                 0x00008000L
#define SE_PROG_STREAM_CNTL_1__DATA_TYPE_3_MASK            0x000f0000L
#define SE_PROG_STREAM_CNTL_1__SKIP_DWORDS_3_MASK          0x00f00000L
#define SE_PROG_STREAM_CNTL_1__DST_VEC_LOC_3_MASK          0x1f000000L
#define SE_PROG_STREAM_CNTL_1__LAST_VEC_3_MASK             0x20000000L
#define SE_PROG_STREAM_CNTL_1__LAST_VEC_3                  0x20000000L
#define SE_PROG_STREAM_CNTL_1__SIGNED_3_MASK               0x40000000L
#define SE_PROG_STREAM_CNTL_1__SIGNED_3                    0x40000000L
#define SE_PROG_STREAM_CNTL_1__NORMALIZE_3_MASK            0x80000000L
#define SE_PROG_STREAM_CNTL_1__NORMALIZE_3                 0x80000000L

// SE_PROG_STREAM_CNTL_2
#define SE_PROG_STREAM_CNTL_2__DATA_TYPE_4_MASK            0x0000000fL
#define SE_PROG_STREAM_CNTL_2__SKIP_DWORDS_4_MASK          0x000000f0L
#define SE_PROG_STREAM_CNTL_2__DST_VEC_LOC_4_MASK          0x00001f00L
#define SE_PROG_STREAM_CNTL_2__LAST_VEC_4_MASK             0x00002000L
#define SE_PROG_STREAM_CNTL_2__LAST_VEC_4                  0x00002000L
#define SE_PROG_STREAM_CNTL_2__SIGNED_4_MASK               0x00004000L
#define SE_PROG_STREAM_CNTL_2__SIGNED_4                    0x00004000L
#define SE_PROG_STREAM_CNTL_2__NORMALIZE_4_MASK            0x00008000L
#define SE_PROG_STREAM_CNTL_2__NORMALIZE_4                 0x00008000L
#define SE_PROG_STREAM_CNTL_2__DATA_TYPE_5_MASK            0x000f0000L
#define SE_PROG_STREAM_CNTL_2__SKIP_DWORDS_5_MASK          0x00f00000L
#define SE_PROG_STREAM_CNTL_2__DST_VEC_LOC_5_MASK          0x1f000000L
#define SE_PROG_STREAM_CNTL_2__LAST_VEC_5_MASK             0x20000000L
#define SE_PROG_STREAM_CNTL_2__LAST_VEC_5                  0x20000000L
#define SE_PROG_STREAM_CNTL_2__SIGNED_5_MASK               0x40000000L
#define SE_PROG_STREAM_CNTL_2__SIGNED_5                    0x40000000L
#define SE_PROG_STREAM_CNTL_2__NORMALIZE_5_MASK            0x80000000L
#define SE_PROG_STREAM_CNTL_2__NORMALIZE_5                 0x80000000L

// SE_PROG_STREAM_CNTL_3
#define SE_PROG_STREAM_CNTL_3__DATA_TYPE_6_MASK            0x0000000fL
#define SE_PROG_STREAM_CNTL_3__SKIP_DWORDS_6_MASK          0x000000f0L
#define SE_PROG_STREAM_CNTL_3__DST_VEC_LOC_6_MASK          0x00001f00L
#define SE_PROG_STREAM_CNTL_3__LAST_VEC_6_MASK             0x00002000L
#define SE_PROG_STREAM_CNTL_3__LAST_VEC_6                  0x00002000L
#define SE_PROG_STREAM_CNTL_3__SIGNED_6_MASK               0x00004000L
#define SE_PROG_STREAM_CNTL_3__SIGNED_6                    0x00004000L
#define SE_PROG_STREAM_CNTL_3__NORMALIZE_6_MASK            0x00008000L
#define SE_PROG_STREAM_CNTL_3__NORMALIZE_6                 0x00008000L
#define SE_PROG_STREAM_CNTL_3__DATA_TYPE_7_MASK            0x000f0000L
#define SE_PROG_STREAM_CNTL_3__SKIP_DWORDS_7_MASK          0x00f00000L
#define SE_PROG_STREAM_CNTL_3__DST_VEC_LOC_7_MASK          0x1f000000L
#define SE_PROG_STREAM_CNTL_3__LAST_VEC_7_MASK             0x20000000L
#define SE_PROG_STREAM_CNTL_3__LAST_VEC_7                  0x20000000L
#define SE_PROG_STREAM_CNTL_3__SIGNED_7_MASK               0x40000000L
#define SE_PROG_STREAM_CNTL_3__SIGNED_7                    0x40000000L
#define SE_PROG_STREAM_CNTL_3__NORMALIZE_7_MASK            0x80000000L
#define SE_PROG_STREAM_CNTL_3__NORMALIZE_7                 0x80000000L

// SE_PROG_STREAM_CNTL_4
#define SE_PROG_STREAM_CNTL_4__DATA_TYPE_8_MASK            0x0000000fL
#define SE_PROG_STREAM_CNTL_4__SKIP_DWORDS_8_MASK          0x000000f0L
#define SE_PROG_STREAM_CNTL_4__DST_VEC_LOC_8_MASK          0x00001f00L
#define SE_PROG_STREAM_CNTL_4__LAST_VEC_8_MASK             0x00002000L
#define SE_PROG_STREAM_CNTL_4__LAST_VEC_8                  0x00002000L
#define SE_PROG_STREAM_CNTL_4__SIGNED_8_MASK               0x00004000L
#define SE_PROG_STREAM_CNTL_4__SIGNED_8                    0x00004000L
#define SE_PROG_STREAM_CNTL_4__NORMALIZE_8_MASK            0x00008000L
#define SE_PROG_STREAM_CNTL_4__NORMALIZE_8                 0x00008000L
#define SE_PROG_STREAM_CNTL_4__DATA_TYPE_9_MASK            0x000f0000L
#define SE_PROG_STREAM_CNTL_4__SKIP_DWORDS_9_MASK          0x00f00000L
#define SE_PROG_STREAM_CNTL_4__DST_VEC_LOC_9_MASK          0x1f000000L
#define SE_PROG_STREAM_CNTL_4__LAST_VEC_9_MASK             0x20000000L
#define SE_PROG_STREAM_CNTL_4__LAST_VEC_9                  0x20000000L
#define SE_PROG_STREAM_CNTL_4__SIGNED_9_MASK               0x40000000L
#define SE_PROG_STREAM_CNTL_4__SIGNED_9                    0x40000000L
#define SE_PROG_STREAM_CNTL_4__NORMALIZE_9_MASK            0x80000000L
#define SE_PROG_STREAM_CNTL_4__NORMALIZE_9                 0x80000000L

// SE_PROG_STREAM_CNTL_5
#define SE_PROG_STREAM_CNTL_5__DATA_TYPE_10_MASK           0x0000000fL
#define SE_PROG_STREAM_CNTL_5__SKIP_DWORDS_10_MASK         0x000000f0L
#define SE_PROG_STREAM_CNTL_5__DST_VEC_LOC_10_MASK         0x00001f00L
#define SE_PROG_STREAM_CNTL_5__LAST_VEC_10_MASK            0x00002000L
#define SE_PROG_STREAM_CNTL_5__LAST_VEC_10                 0x00002000L
#define SE_PROG_STREAM_CNTL_5__SIGNED_10_MASK              0x00004000L
#define SE_PROG_STREAM_CNTL_5__SIGNED_10                   0x00004000L
#define SE_PROG_STREAM_CNTL_5__NORMALIZE_10_MASK           0x00008000L
#define SE_PROG_STREAM_CNTL_5__NORMALIZE_10                0x00008000L
#define SE_PROG_STREAM_CNTL_5__DATA_TYPE_11_MASK           0x000f0000L
#define SE_PROG_STREAM_CNTL_5__SKIP_DWORDS_11_MASK         0x00f00000L
#define SE_PROG_STREAM_CNTL_5__DST_VEC_LOC_11_MASK         0x1f000000L
#define SE_PROG_STREAM_CNTL_5__LAST_VEC_11_MASK            0x20000000L
#define SE_PROG_STREAM_CNTL_5__LAST_VEC_11                 0x20000000L
#define SE_PROG_STREAM_CNTL_5__SIGNED_11_MASK              0x40000000L
#define SE_PROG_STREAM_CNTL_5__SIGNED_11                   0x40000000L
#define SE_PROG_STREAM_CNTL_5__NORMALIZE_11_MASK           0x80000000L
#define SE_PROG_STREAM_CNTL_5__NORMALIZE_11                0x80000000L

// SE_PROG_STREAM_CNTL_6
#define SE_PROG_STREAM_CNTL_6__DATA_TYPE_12_MASK           0x0000000fL
#define SE_PROG_STREAM_CNTL_6__SKIP_DWORDS_12_MASK         0x000000f0L
#define SE_PROG_STREAM_CNTL_6__DST_VEC_LOC_12_MASK         0x00001f00L
#define SE_PROG_STREAM_CNTL_6__LAST_VEC_12_MASK            0x00002000L
#define SE_PROG_STREAM_CNTL_6__LAST_VEC_12                 0x00002000L
#define SE_PROG_STREAM_CNTL_6__SIGNED_12_MASK              0x00004000L
#define SE_PROG_STREAM_CNTL_6__SIGNED_12                   0x00004000L
#define SE_PROG_STREAM_CNTL_6__NORMALIZE_12_MASK           0x00008000L
#define SE_PROG_STREAM_CNTL_6__NORMALIZE_12                0x00008000L
#define SE_PROG_STREAM_CNTL_6__DATA_TYPE_13_MASK           0x000f0000L
#define SE_PROG_STREAM_CNTL_6__SKIP_DWORDS_13_MASK         0x00f00000L
#define SE_PROG_STREAM_CNTL_6__DST_VEC_LOC_13_MASK         0x1f000000L
#define SE_PROG_STREAM_CNTL_6__LAST_VEC_13_MASK            0x20000000L
#define SE_PROG_STREAM_CNTL_6__LAST_VEC_13                 0x20000000L
#define SE_PROG_STREAM_CNTL_6__SIGNED_13_MASK              0x40000000L
#define SE_PROG_STREAM_CNTL_6__SIGNED_13                   0x40000000L
#define SE_PROG_STREAM_CNTL_6__NORMALIZE_13_MASK           0x80000000L
#define SE_PROG_STREAM_CNTL_6__NORMALIZE_13                0x80000000L

// SE_PROG_STREAM_CNTL_7
#define SE_PROG_STREAM_CNTL_7__DATA_TYPE_14_MASK           0x0000000fL
#define SE_PROG_STREAM_CNTL_7__SKIP_DWORDS_14_MASK         0x000000f0L
#define SE_PROG_STREAM_CNTL_7__DST_VEC_LOC_14_MASK         0x00001f00L
#define SE_PROG_STREAM_CNTL_7__LAST_VEC_14_MASK            0x00002000L
#define SE_PROG_STREAM_CNTL_7__LAST_VEC_14                 0x00002000L
#define SE_PROG_STREAM_CNTL_7__SIGNED_14_MASK              0x00004000L
#define SE_PROG_STREAM_CNTL_7__SIGNED_14                   0x00004000L
#define SE_PROG_STREAM_CNTL_7__NORMALIZE_14_MASK           0x00008000L
#define SE_PROG_STREAM_CNTL_7__NORMALIZE_14                0x00008000L
#define SE_PROG_STREAM_CNTL_7__DATA_TYPE_15_MASK           0x000f0000L
#define SE_PROG_STREAM_CNTL_7__SKIP_DWORDS_15_MASK         0x00f00000L
#define SE_PROG_STREAM_CNTL_7__DST_VEC_LOC_15_MASK         0x1f000000L
#define SE_PROG_STREAM_CNTL_7__LAST_VEC_15_MASK            0x20000000L
#define SE_PROG_STREAM_CNTL_7__LAST_VEC_15                 0x20000000L
#define SE_PROG_STREAM_CNTL_7__SIGNED_15_MASK              0x40000000L
#define SE_PROG_STREAM_CNTL_7__SIGNED_15                   0x40000000L
#define SE_PROG_STREAM_CNTL_7__NORMALIZE_15_MASK           0x80000000L
#define SE_PROG_STREAM_CNTL_7__NORMALIZE_15                0x80000000L

// SE_VTX_STATE_CNTL
#define SE_VTX_STATE_CNTL__COLOR_0_ASSEMBLY_CNTL_MASK      0x00000003L
#define SE_VTX_STATE_CNTL__COLOR_1_ASSEMBLY_CNTL_MASK      0x0000000cL
#define SE_VTX_STATE_CNTL__COLOR_2_ASSEMBLY_CNTL_MASK      0x00000030L
#define SE_VTX_STATE_CNTL__COLOR_3_ASSEMBLY_CNTL_MASK      0x000000c0L
#define SE_VTX_STATE_CNTL__COLOR_4_ASSEMBLY_CNTL_MASK      0x00000300L
#define SE_VTX_STATE_CNTL__COLOR_5_ASSEMBLY_CNTL_MASK      0x00000c00L
#define SE_VTX_STATE_CNTL__COLOR_6_ASSEMBLY_CNTL_MASK      0x00003000L
#define SE_VTX_STATE_CNTL__COLOR_7_ASSEMBLY_CNTL_MASK      0x0000c000L
#define SE_VTX_STATE_CNTL__UPDATE_USER_COLOR_0_ENA_MASK    0x00010000L
#define SE_VTX_STATE_CNTL__UPDATE_USER_COLOR_0_ENA         0x00010000L
#define SE_VTX_STATE_CNTL__UPDATE_USER_COLOR_1_ENA_MASK    0x00020000L
#define SE_VTX_STATE_CNTL__UPDATE_USER_COLOR_1_ENA         0x00020000L
#define SE_VTX_STATE_CNTL__USE_ADDR_IND_TBL_MASK           0x00040000L
#define SE_VTX_STATE_CNTL__USE_ADDR_IND_TBL                0x00040000L

// SE_VTX_STATE_IND_REG_0
#define SE_VTX_STATE_IND_REG_0__ADDR_0_MASK                0x0000007fL
#define SE_VTX_STATE_IND_REG_0__ADDR_1_MASK                0x00007f00L
#define SE_VTX_STATE_IND_REG_0__ADDR_2_MASK                0x007f0000L
#define SE_VTX_STATE_IND_REG_0__ADDR_3_MASK                0x7f000000L

// SE_VTX_STATE_IND_REG_1
#define SE_VTX_STATE_IND_REG_1__ADDR_4_MASK                0x0000007fL
#define SE_VTX_STATE_IND_REG_1__ADDR_5_MASK                0x00007f00L
#define SE_VTX_STATE_IND_REG_1__ADDR_6_MASK                0x007f0000L
#define SE_VTX_STATE_IND_REG_1__ADDR_7_MASK                0x7f000000L

// SE_VTX_STATE_IND_REG_2
#define SE_VTX_STATE_IND_REG_2__ADDR_8_MASK                0x0000007fL
#define SE_VTX_STATE_IND_REG_2__ADDR_9_MASK                0x00007f00L
#define SE_VTX_STATE_IND_REG_2__ADDR_10_MASK               0x007f0000L
#define SE_VTX_STATE_IND_REG_2__ADDR_11_MASK               0x7f000000L

// SE_VTX_STATE_IND_REG_3
#define SE_VTX_STATE_IND_REG_3__ADDR_12_MASK               0x0000007fL
#define SE_VTX_STATE_IND_REG_3__ADDR_13_MASK               0x00007f00L
#define SE_VTX_STATE_IND_REG_3__ADDR_14_MASK               0x007f0000L
#define SE_VTX_STATE_IND_REG_3__ADDR_15_MASK               0x7f000000L

// SE_VTX_STATE_IND_REG_4
#define SE_VTX_STATE_IND_REG_4__ADDR_16_MASK               0x0000007fL
#define SE_VTX_STATE_IND_REG_4__ADDR_17_MASK               0x00007f00L
#define SE_VTX_STATE_IND_REG_4__ADDR_18_MASK               0x007f0000L
#define SE_VTX_STATE_IND_REG_4__ADDR_19_MASK               0x7f000000L

// SE_VTX_STATE_IND_REG_5
#define SE_VTX_STATE_IND_REG_5__ADDR_20_MASK               0x0000007fL
#define SE_VTX_STATE_IND_REG_5__ADDR_21_MASK               0x00007f00L
#define SE_VTX_STATE_IND_REG_5__ADDR_22_MASK               0x007f0000L
#define SE_VTX_STATE_IND_REG_5__ADDR_23_MASK               0x7f000000L

// SE_VTX_STATE_IND_REG_6
#define SE_VTX_STATE_IND_REG_6__ADDR_24_MASK               0x0000007fL
#define SE_VTX_STATE_IND_REG_6__ADDR_25_MASK               0x00007f00L
#define SE_VTX_STATE_IND_REG_6__ADDR_26_MASK               0x007f0000L
#define SE_VTX_STATE_IND_REG_6__ADDR_27_MASK               0x7f000000L

// SE_VTX_STATE_IND_REG_7
#define SE_VTX_STATE_IND_REG_7__ADDR_28_MASK               0x0000007fL
#define SE_VTX_STATE_IND_REG_7__ADDR_29_MASK               0x00007f00L
#define SE_VTX_STATE_IND_REG_7__ADDR_30_MASK               0x007f0000L
#define SE_VTX_STATE_IND_REG_7__ADDR_31_MASK               0x7f000000L

// SE_VTX_STATE_IND_REG_8
#define SE_VTX_STATE_IND_REG_8__ADDR_32_MASK               0x0000007fL
#define SE_VTX_STATE_IND_REG_8__ADDR_33_MASK               0x00007f00L
#define SE_VTX_STATE_IND_REG_8__ADDR_34_MASK               0x007f0000L
#define SE_VTX_STATE_IND_REG_8__ADDR_35_MASK               0x7f000000L

// SE_VTX_STATE_IND_REG_9
#define SE_VTX_STATE_IND_REG_9__ADDR_36_MASK               0x0000007fL
#define SE_VTX_STATE_IND_REG_9__ADDR_37_MASK               0x00007f00L
#define SE_VTX_STATE_IND_REG_9__ADDR_38_MASK               0x007f0000L
#define SE_VTX_STATE_IND_REG_9__ADDR_39_MASK               0x7f000000L

// SE_VTX_STATE_IND_REG_10
#define SE_VTX_STATE_IND_REG_10__ADDR_40_MASK              0x0000007fL
#define SE_VTX_STATE_IND_REG_10__ADDR_41_MASK              0x00007f00L
#define SE_VTX_STATE_IND_REG_10__ADDR_42_MASK              0x007f0000L
#define SE_VTX_STATE_IND_REG_10__ADDR_43_MASK              0x7f000000L

// SE_VTX_STATE_IND_REG_11
#define SE_VTX_STATE_IND_REG_11__ADDR_44_MASK              0x0000007fL
#define SE_VTX_STATE_IND_REG_11__ADDR_45_MASK              0x00007f00L
#define SE_VTX_STATE_IND_REG_11__ADDR_46_MASK              0x007f0000L
#define SE_VTX_STATE_IND_REG_11__ADDR_47_MASK              0x7f000000L

// SE_VTX_STATE_IND_REG_12
#define SE_VTX_STATE_IND_REG_12__ADDR_48_MASK              0x0000007fL
#define SE_VTX_STATE_IND_REG_12__ADDR_49_MASK              0x00007f00L
#define SE_VTX_STATE_IND_REG_12__ADDR_50_MASK              0x007f0000L
#define SE_VTX_STATE_IND_REG_12__ADDR_51_MASK              0x7f000000L

// SE_VTX_STATE_IND_REG_13
#define SE_VTX_STATE_IND_REG_13__ADDR_52_MASK              0x0000007fL
#define SE_VTX_STATE_IND_REG_13__ADDR_53_MASK              0x00007f00L
#define SE_VTX_STATE_IND_REG_13__ADDR_54_MASK              0x007f0000L
#define SE_VTX_STATE_IND_REG_13__ADDR_55_MASK              0x7f000000L

// SE_VTX_STATE_IND_REG_14
#define SE_VTX_STATE_IND_REG_14__ADDR_56_MASK              0x0000007fL
#define SE_VTX_STATE_IND_REG_14__ADDR_57_MASK              0x00007f00L
#define SE_VTX_STATE_IND_REG_14__ADDR_58_MASK              0x007f0000L
#define SE_VTX_STATE_IND_REG_14__ADDR_59_MASK              0x7f000000L

// SE_VTX_STATE_IND_REG_15
#define SE_VTX_STATE_IND_REG_15__ADDR_60_MASK              0x0000007fL
#define SE_VTX_STATE_IND_REG_15__ADDR_61_MASK              0x00007f00L
#define SE_VTX_STATE_IND_REG_15__ADDR_62_MASK              0x007f0000L
#define SE_VTX_STATE_IND_REG_15__ADDR_63_MASK              0x7f000000L

// SE_TCL_VECTOR_INDX_REG
#define SE_TCL_VECTOR_INDX_REG__OCTWORD_OFFSET_R2_MASK     0x000003ffL
#define SE_TCL_VECTOR_INDX_REG__OCTWORD_STRIDE_MASK        0x007f0000L
#define SE_TCL_VECTOR_INDX_REG__DWORD_COUNT_MASK           0x30000000L

// SE_TCL_VECTOR_DATA_REG
#define SE_TCL_VECTOR_DATA_REG__DATA_REGISTER_MASK         0xffffffffL

// SE_TCL_SCALAR_INDX_REG
#define SE_TCL_SCALAR_INDX_REG__DWORD_OFFSET_R2_MASK       0x000003ffL
#define SE_TCL_SCALAR_INDX_REG__DWORD_STRIDE_MASK          0x007f0000L

// SE_TCL_SCALAR_DATA_REG
#define SE_TCL_SCALAR_DATA_REG__DATA_REGISTER_MASK         0xffffffffL

// SE_TCL_MATRIX_SEL_0
#define SE_TCL_MATRIX_SEL_0__MODELVIEW_MTX_0_SEL_MASK      0x000000ffL
#define SE_TCL_MATRIX_SEL_0__MODELVIEW_MTX_1_SEL_MASK      0x0000ff00L
#define SE_TCL_MATRIX_SEL_0__MODELVIEW_MTX_2_SEL_MASK      0x00ff0000L
#define SE_TCL_MATRIX_SEL_0__MODELVIEW_MTX_3_SEL_MASK      0xff000000L

// SE_TCL_MATRIX_SEL_1
#define SE_TCL_MATRIX_SEL_1__IT_MODELVIEW_MTX_0_SEL_MASK   0x000000ffL
#define SE_TCL_MATRIX_SEL_1__IT_MODELVIEW_MTX_1_SEL_MASK   0x0000ff00L
#define SE_TCL_MATRIX_SEL_1__IT_MODELVIEW_MTX_2_SEL_MASK   0x00ff0000L
#define SE_TCL_MATRIX_SEL_1__IT_MODELVIEW_MTX_3_SEL_MASK   0xff000000L

// SE_TCL_MATRIX_SEL_2
#define SE_TCL_MATRIX_SEL_2__MODEL2CLIP_MTX_0_SEL_MASK     0x000000ffL
#define SE_TCL_MATRIX_SEL_2__MODEL2CLIP_MTX_1_SEL_MASK     0x0000ff00L
#define SE_TCL_MATRIX_SEL_2__MODEL2CLIP_MTX_2_SEL_MASK     0x00ff0000L
#define SE_TCL_MATRIX_SEL_2__MODEL2CLIP_MTX_3_SEL_MASK     0xff000000L

// SE_TCL_MATRIX_SEL_3
#define SE_TCL_MATRIX_SEL_3__TEX_XFORM_MTX_0_SEL_MASK      0x000000ffL
#define SE_TCL_MATRIX_SEL_3__TEX_XFORM_MTX_1_SEL_MASK      0x0000ff00L
#define SE_TCL_MATRIX_SEL_3__TEX_XFORM_MTX_2_SEL_MASK      0x00ff0000L
#define SE_TCL_MATRIX_SEL_3__TEX_XFORM_MTX_3_SEL_MASK      0xff000000L

// SE_TCL_MATRIX_SEL_4
#define SE_TCL_MATRIX_SEL_4__TEX_XFORM_MTX_4_SEL_MASK      0x000000ffL
#define SE_TCL_MATRIX_SEL_4__TEX_XFORM_MTX_5_SEL_MASK      0x0000ff00L

// SE_TCL_PER_VTX_MTX_CNTL
#define SE_TCL_PER_VTX_MTX_CNTL__MV_MTX_0_INDX_MASK        0x000000ffL
#define SE_TCL_PER_VTX_MTX_CNTL__ITMV_MTX_0_INDX_MASK      0x0000ff00L
#define SE_TCL_PER_VTX_MTX_CNTL__M2C_MTX_0_INDX_MASK       0x00ff0000L

// SE_TCL_OUTPUT_VTX_COMP_SEL
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_XYZW_SEL_MASK      0x00000001L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_XYZW_SEL           0x00000001L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_COLOR_0_SEL_MASK   0x00000100L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_COLOR_0_SEL        0x00000100L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_COLOR_1_SEL_MASK   0x00000200L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_COLOR_1_SEL        0x00000200L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_0_SEL_MASK     0x00010000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_0_SEL          0x00010000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_1_SEL_MASK     0x00020000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_1_SEL          0x00020000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_2_SEL_MASK     0x00040000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_2_SEL          0x00040000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_3_SEL_MASK     0x00080000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_3_SEL          0x00080000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_4_SEL_MASK     0x00100000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_4_SEL          0x00100000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_5_SEL_MASK     0x00200000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_TEX_5_SEL          0x00200000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_DISCRETE_FOG_SEL_MASK 0x01000000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_DISCRETE_FOG_SEL   0x01000000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_PT_SIZE_SEL_MASK   0x02000000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_PT_SIZE_SEL        0x02000000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__FORCE_IN_ORDER_PROC_MASK 0x80000000L
#define SE_TCL_OUTPUT_VTX_COMP_SEL__FORCE_IN_ORDER_PROC    0x80000000L

// SE_TCL_INPUT_VTX_VECTOR_ADDR_0
#define SE_TCL_INPUT_VTX_VECTOR_ADDR_0__VERTEX_POSITION_ADDR_MASK 0x000000ffL

// SE_TCL_INPUT_VTX_VECTOR_ADDR_1
#define SE_TCL_INPUT_VTX_VECTOR_ADDR_1__VTX_COLOR_0_ADDR_MASK 0x000000ffL
#define SE_TCL_INPUT_VTX_VECTOR_ADDR_1__VTX_COLOR_1_ADDR_MASK 0x0000ff00L

// SE_TCL_INPUT_VTX_VECTOR_ADDR_2
#define SE_TCL_INPUT_VTX_VECTOR_ADDR_2__VTX_TEX_0_ADDR_MASK 0x000000ffL
#define SE_TCL_INPUT_VTX_VECTOR_ADDR_2__VTX_TEX_1_ADDR_MASK 0x0000ff00L
#define SE_TCL_INPUT_VTX_VECTOR_ADDR_2__VTX_TEX_2_ADDR_MASK 0x00ff0000L
#define SE_TCL_INPUT_VTX_VECTOR_ADDR_2__VTX_TEX_3_ADDR_MASK 0xff000000L

// SE_TCL_INPUT_VTX_VECTOR_ADDR_3
#define SE_TCL_INPUT_VTX_VECTOR_ADDR_3__VTX_TEX_4_ADDR_MASK 0x000000ffL
#define SE_TCL_INPUT_VTX_VECTOR_ADDR_3__VTX_TEX_5_ADDR_MASK 0x0000ff00L

// SE_TCL_LIGHT_MODEL_CNTL_0
#define SE_TCL_LIGHT_MODEL_CNTL_0__LIGHTING_ENA_MASK       0x00000001L
#define SE_TCL_LIGHT_MODEL_CNTL_0__LIGHTING_ENA            0x00000001L
#define SE_TCL_LIGHT_MODEL_CNTL_0__LIGHTING_IN_MODEL_MASK  0x00000002L
#define SE_TCL_LIGHT_MODEL_CNTL_0__LIGHTING_IN_MODEL       0x00000002L
#define SE_TCL_LIGHT_MODEL_CNTL_0__LOCAL_VIEWER_MASK       0x00000004L
#define SE_TCL_LIGHT_MODEL_CNTL_0__LOCAL_VIEWER            0x00000004L
#define SE_TCL_LIGHT_MODEL_CNTL_0__NORMALIZE_NORMAL_MASK   0x00000008L
#define SE_TCL_LIGHT_MODEL_CNTL_0__NORMALIZE_NORMAL        0x00000008L
#define SE_TCL_LIGHT_MODEL_CNTL_0__RESCALE_NORMAL_MASK     0x00000010L
#define SE_TCL_LIGHT_MODEL_CNTL_0__RESCALE_NORMAL          0x00000010L
#define SE_TCL_LIGHT_MODEL_CNTL_0__SPECULAR_ENA_MASK       0x00000020L
#define SE_TCL_LIGHT_MODEL_CNTL_0__SPECULAR_ENA            0x00000020L
#define SE_TCL_LIGHT_MODEL_CNTL_0__DIFFUSE_SPECULAR_COMBINE_MASK 0x00000040L
#define SE_TCL_LIGHT_MODEL_CNTL_0__DIFFUSE_SPECULAR_COMBINE 0x00000040L
#define SE_TCL_LIGHT_MODEL_CNTL_0__ALPHA_LIGHTING_MASK     0x00000080L
#define SE_TCL_LIGHT_MODEL_CNTL_0__ALPHA_LIGHTING          0x00000080L
#define SE_TCL_LIGHT_MODEL_CNTL_0__LOC_LIGHT_W_SCALE_SUB_MASK 0x00000100L
#define SE_TCL_LIGHT_MODEL_CNTL_0__LOC_LIGHT_W_SCALE_SUB   0x00000100L
#define SE_TCL_LIGHT_MODEL_CNTL_0__NO_NORMAL_DO_AMB_ONLY_MASK 0x00000200L
#define SE_TCL_LIGHT_MODEL_CNTL_0__NO_NORMAL_DO_AMB_ONLY   0x00000200L
#define SE_TCL_LIGHT_MODEL_CNTL_0__TWO_SIDED_LIGHTING_ENA_MASK 0x00000400L
#define SE_TCL_LIGHT_MODEL_CNTL_0__TWO_SIDED_LIGHTING_ENA  0x00000400L
#define SE_TCL_LIGHT_MODEL_CNTL_0__FRONT_SHININESS_SRC_MASK 0x00001800L
#define SE_TCL_LIGHT_MODEL_CNTL_0__BACK_SHININESS_SRC_MASK 0x00006000L
#define SE_TCL_LIGHT_MODEL_CNTL_0__WAIT_ON_CLIP_DIS_MASK   0x00008000L
#define SE_TCL_LIGHT_MODEL_CNTL_0__WAIT_ON_CLIP_DIS        0x00008000L
#define SE_TCL_LIGHT_MODEL_CNTL_0__CLIP_DBL_BUF_ENA_MASK   0x00010000L
#define SE_TCL_LIGHT_MODEL_CNTL_0__CLIP_DBL_BUF_ENA        0x00010000L

// SE_TCL_LIGHT_MODEL_CNTL_1
#define SE_TCL_LIGHT_MODEL_CNTL_1__FRONT_EMISSIVE_SRC_MASK 0x0000000fL
#define SE_TCL_LIGHT_MODEL_CNTL_1__FRONT_AMBIENT_SRC_MASK  0x000000f0L
#define SE_TCL_LIGHT_MODEL_CNTL_1__FRONT_DIFFUSE_SRC_MASK  0x00000f00L
#define SE_TCL_LIGHT_MODEL_CNTL_1__FRONT_SPECULAR_SRC_MASK 0x0000f000L
#define SE_TCL_LIGHT_MODEL_CNTL_1__BACK_EMISSIVE_SRC_MASK  0x000f0000L
#define SE_TCL_LIGHT_MODEL_CNTL_1__BACK_AMBIENT_SRC_MASK   0x00f00000L
#define SE_TCL_LIGHT_MODEL_CNTL_1__BACK_DIFFUSE_SRC_MASK   0x0f000000L
#define SE_TCL_LIGHT_MODEL_CNTL_1__BACK_SPECULAR_SRC_MASK  0xf0000000L

// SE_TCL_PER_LIGHT_CNTL_0
#define SE_TCL_PER_LIGHT_CNTL_0__LIGHT_ENA_0_MASK          0x00000001L
#define SE_TCL_PER_LIGHT_CNTL_0__LIGHT_ENA_0               0x00000001L
#define SE_TCL_PER_LIGHT_CNTL_0__AMBIENT_ENA_0_MASK        0x00000002L
#define SE_TCL_PER_LIGHT_CNTL_0__AMBIENT_ENA_0             0x00000002L
#define SE_TCL_PER_LIGHT_CNTL_0__SPECULAR_ENA_0_MASK       0x00000004L
#define SE_TCL_PER_LIGHT_CNTL_0__SPECULAR_ENA_0            0x00000004L
#define SE_TCL_PER_LIGHT_CNTL_0__LOCAL_LIGHT_0_MASK        0x00000008L
#define SE_TCL_PER_LIGHT_CNTL_0__LOCAL_LIGHT_0             0x00000008L
#define SE_TCL_PER_LIGHT_CNTL_0__SPOT_ENA_0_MASK           0x00000010L
#define SE_TCL_PER_LIGHT_CNTL_0__SPOT_ENA_0                0x00000010L
#define SE_TCL_PER_LIGHT_CNTL_0__SPOT_DUAL_CONE_0_MASK     0x00000020L
#define SE_TCL_PER_LIGHT_CNTL_0__SPOT_DUAL_CONE_0          0x00000020L
#define SE_TCL_PER_LIGHT_CNTL_0__RNG_ATT_ENA_0_MASK        0x00000040L
#define SE_TCL_PER_LIGHT_CNTL_0__RNG_ATT_ENA_0             0x00000040L
#define SE_TCL_PER_LIGHT_CNTL_0__RNG_ATT_CONSTANT_ENA_0_MASK 0x00000080L
#define SE_TCL_PER_LIGHT_CNTL_0__RNG_ATT_CONSTANT_ENA_0    0x00000080L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_1BIT_NUM0_MASK   0x00000100L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_1BIT_NUM0        0x00000100L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_1BIT_NUM1_MASK   0x00000200L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_1BIT_NUM1        0x00000200L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_1BIT_NUM2_MASK   0x00000400L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_1BIT_NUM2        0x00000400L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_1BIT_NUM3_MASK   0x00000800L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_1BIT_NUM3        0x00000800L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_2BIT_NUM0_MASK   0x00003000L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT0_2BIT_NUM1_MASK   0x0000c000L
#define SE_TCL_PER_LIGHT_CNTL_0__LIGHT_ENA_1_MASK          0x00010000L
#define SE_TCL_PER_LIGHT_CNTL_0__LIGHT_ENA_1               0x00010000L
#define SE_TCL_PER_LIGHT_CNTL_0__AMBIENT_ENA_1_MASK        0x00020000L
#define SE_TCL_PER_LIGHT_CNTL_0__AMBIENT_ENA_1             0x00020000L
#define SE_TCL_PER_LIGHT_CNTL_0__SPECULAR_ENA_1_MASK       0x00040000L
#define SE_TCL_PER_LIGHT_CNTL_0__SPECULAR_ENA_1            0x00040000L
#define SE_TCL_PER_LIGHT_CNTL_0__LOCAL_LIGHT_1_MASK        0x00080000L
#define SE_TCL_PER_LIGHT_CNTL_0__LOCAL_LIGHT_1             0x00080000L
#define SE_TCL_PER_LIGHT_CNTL_0__SPOT_ENA_1_MASK           0x00100000L
#define SE_TCL_PER_LIGHT_CNTL_0__SPOT_ENA_1                0x00100000L
#define SE_TCL_PER_LIGHT_CNTL_0__SPOT_DUAL_CONE_1_MASK     0x00200000L
#define SE_TCL_PER_LIGHT_CNTL_0__SPOT_DUAL_CONE_1          0x00200000L
#define SE_TCL_PER_LIGHT_CNTL_0__RNG_ATT_ENA_1_MASK        0x00400000L
#define SE_TCL_PER_LIGHT_CNTL_0__RNG_ATT_ENA_1             0x00400000L
#define SE_TCL_PER_LIGHT_CNTL_0__RNG_ATT_CONSTANT_ENA_1_MASK 0x00800000L
#define SE_TCL_PER_LIGHT_CNTL_0__RNG_ATT_CONSTANT_ENA_1    0x00800000L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_1BIT_NUM0_MASK   0x01000000L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_1BIT_NUM0        0x01000000L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_1BIT_NUM1_MASK   0x02000000L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_1BIT_NUM1        0x02000000L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_1BIT_NUM2_MASK   0x04000000L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_1BIT_NUM2        0x04000000L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_1BIT_NUM3_MASK   0x08000000L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_1BIT_NUM3        0x08000000L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_2BIT_NUM0_MASK   0x30000000L
#define SE_TCL_PER_LIGHT_CNTL_0__RSVD_LT1_2BIT_NUM1_MASK   0xc0000000L

// SE_TCL_PER_LIGHT_CNTL_1
#define SE_TCL_PER_LIGHT_CNTL_1__LIGHT_ENA_2_MASK          0x00000001L
#define SE_TCL_PER_LIGHT_CNTL_1__LIGHT_ENA_2               0x00000001L
#define SE_TCL_PER_LIGHT_CNTL_1__AMBIENT_ENA_2_MASK        0x00000002L
#define SE_TCL_PER_LIGHT_CNTL_1__AMBIENT_ENA_2             0x00000002L
#define SE_TCL_PER_LIGHT_CNTL_1__SPECULAR_ENA_2_MASK       0x00000004L
#define SE_TCL_PER_LIGHT_CNTL_1__SPECULAR_ENA_2            0x00000004L
#define SE_TCL_PER_LIGHT_CNTL_1__LOCAL_LIGHT_2_MASK        0x00000008L
#define SE_TCL_PER_LIGHT_CNTL_1__LOCAL_LIGHT_2             0x00000008L
#define SE_TCL_PER_LIGHT_CNTL_1__SPOT_ENA_2_MASK           0x00000010L
#define SE_TCL_PER_LIGHT_CNTL_1__SPOT_ENA_2                0x00000010L
#define SE_TCL_PER_LIGHT_CNTL_1__SPOT_DUAL_CONE_2_MASK     0x00000020L
#define SE_TCL_PER_LIGHT_CNTL_1__SPOT_DUAL_CONE_2          0x00000020L
#define SE_TCL_PER_LIGHT_CNTL_1__RNG_ATT_ENA_2_MASK        0x00000040L
#define SE_TCL_PER_LIGHT_CNTL_1__RNG_ATT_ENA_2             0x00000040L
#define SE_TCL_PER_LIGHT_CNTL_1__RNG_ATT_CONSTANT_ENA_2_MASK 0x00000080L
#define SE_TCL_PER_LIGHT_CNTL_1__RNG_ATT_CONSTANT_ENA_2    0x00000080L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_1BIT_NUM0_MASK   0x00000100L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_1BIT_NUM0        0x00000100L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_1BIT_NUM1_MASK   0x00000200L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_1BIT_NUM1        0x00000200L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_1BIT_NUM2_MASK   0x00000400L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_1BIT_NUM2        0x00000400L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_1BIT_NUM3_MASK   0x00000800L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_1BIT_NUM3        0x00000800L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_2BIT_NUM0_MASK   0x00003000L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT2_2BIT_NUM1_MASK   0x0000c000L
#define SE_TCL_PER_LIGHT_CNTL_1__LIGHT_ENA_3_MASK          0x00010000L
#define SE_TCL_PER_LIGHT_CNTL_1__LIGHT_ENA_3               0x00010000L
#define SE_TCL_PER_LIGHT_CNTL_1__AMBIENT_ENA_3_MASK        0x00020000L
#define SE_TCL_PER_LIGHT_CNTL_1__AMBIENT_ENA_3             0x00020000L
#define SE_TCL_PER_LIGHT_CNTL_1__SPECULAR_ENA_3_MASK       0x00040000L
#define SE_TCL_PER_LIGHT_CNTL_1__SPECULAR_ENA_3            0x00040000L
#define SE_TCL_PER_LIGHT_CNTL_1__LOCAL_LIGHT_3_MASK        0x00080000L
#define SE_TCL_PER_LIGHT_CNTL_1__LOCAL_LIGHT_3             0x00080000L
#define SE_TCL_PER_LIGHT_CNTL_1__SPOT_ENA_3_MASK           0x00100000L
#define SE_TCL_PER_LIGHT_CNTL_1__SPOT_ENA_3                0x00100000L
#define SE_TCL_PER_LIGHT_CNTL_1__SPOT_DUAL_CONE_3_MASK     0x00200000L
#define SE_TCL_PER_LIGHT_CNTL_1__SPOT_DUAL_CONE_3          0x00200000L
#define SE_TCL_PER_LIGHT_CNTL_1__RNG_ATT_ENA_3_MASK        0x00400000L
#define SE_TCL_PER_LIGHT_CNTL_1__RNG_ATT_ENA_3             0x00400000L
#define SE_TCL_PER_LIGHT_CNTL_1__RNG_ATT_CONSTANT_ENA_3_MASK 0x00800000L
#define SE_TCL_PER_LIGHT_CNTL_1__RNG_ATT_CONSTANT_ENA_3    0x00800000L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_1BIT_NUM0_MASK   0x01000000L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_1BIT_NUM0        0x01000000L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_1BIT_NUM1_MASK   0x02000000L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_1BIT_NUM1        0x02000000L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_1BIT_NUM2_MASK   0x04000000L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_1BIT_NUM2        0x04000000L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_1BIT_NUM3_MASK   0x08000000L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_1BIT_NUM3        0x08000000L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_2BIT_NUM0_MASK   0x30000000L
#define SE_TCL_PER_LIGHT_CNTL_1__RSVD_LT3_2BIT_NUM1_MASK   0xc0000000L

// SE_TCL_PER_LIGHT_CNTL_2
#define SE_TCL_PER_LIGHT_CNTL_2__LIGHT_ENA_4_MASK          0x00000001L
#define SE_TCL_PER_LIGHT_CNTL_2__LIGHT_ENA_4               0x00000001L
#define SE_TCL_PER_LIGHT_CNTL_2__AMBIENT_ENA_4_MASK        0x00000002L
#define SE_TCL_PER_LIGHT_CNTL_2__AMBIENT_ENA_4             0x00000002L
#define SE_TCL_PER_LIGHT_CNTL_2__SPECULAR_ENA_4_MASK       0x00000004L
#define SE_TCL_PER_LIGHT_CNTL_2__SPECULAR_ENA_4            0x00000004L
#define SE_TCL_PER_LIGHT_CNTL_2__LOCAL_LIGHT_4_MASK        0x00000008L
#define SE_TCL_PER_LIGHT_CNTL_2__LOCAL_LIGHT_4             0x00000008L
#define SE_TCL_PER_LIGHT_CNTL_2__SPOT_ENA_4_MASK           0x00000010L
#define SE_TCL_PER_LIGHT_CNTL_2__SPOT_ENA_4                0x00000010L
#define SE_TCL_PER_LIGHT_CNTL_2__SPOT_DUAL_CONE_4_MASK     0x00000020L
#define SE_TCL_PER_LIGHT_CNTL_2__SPOT_DUAL_CONE_4          0x00000020L
#define SE_TCL_PER_LIGHT_CNTL_2__RNG_ATT_ENA_4_MASK        0x00000040L
#define SE_TCL_PER_LIGHT_CNTL_2__RNG_ATT_ENA_4             0x00000040L
#define SE_TCL_PER_LIGHT_CNTL_2__RNG_ATT_CONSTANT_ENA_4_MASK 0x00000080L
#define SE_TCL_PER_LIGHT_CNTL_2__RNG_ATT_CONSTANT_ENA_4    0x00000080L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_1BIT_NUM0_MASK   0x00000100L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_1BIT_NUM0        0x00000100L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_1BIT_NUM1_MASK   0x00000200L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_1BIT_NUM1        0x00000200L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_1BIT_NUM2_MASK   0x00000400L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_1BIT_NUM2        0x00000400L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_1BIT_NUM3_MASK   0x00000800L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_1BIT_NUM3        0x00000800L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_2BIT_NUM0_MASK   0x00003000L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT4_2BIT_NUM1_MASK   0x0000c000L
#define SE_TCL_PER_LIGHT_CNTL_2__LIGHT_ENA_5_MASK          0x00010000L
#define SE_TCL_PER_LIGHT_CNTL_2__LIGHT_ENA_5               0x00010000L
#define SE_TCL_PER_LIGHT_CNTL_2__AMBIENT_ENA_5_MASK        0x00020000L
#define SE_TCL_PER_LIGHT_CNTL_2__AMBIENT_ENA_5             0x00020000L
#define SE_TCL_PER_LIGHT_CNTL_2__SPECULAR_ENA_5_MASK       0x00040000L
#define SE_TCL_PER_LIGHT_CNTL_2__SPECULAR_ENA_5            0x00040000L
#define SE_TCL_PER_LIGHT_CNTL_2__LOCAL_LIGHT_5_MASK        0x00080000L
#define SE_TCL_PER_LIGHT_CNTL_2__LOCAL_LIGHT_5             0x00080000L
#define SE_TCL_PER_LIGHT_CNTL_2__SPOT_ENA_5_MASK           0x00100000L
#define SE_TCL_PER_LIGHT_CNTL_2__SPOT_ENA_5                0x00100000L
#define SE_TCL_PER_LIGHT_CNTL_2__SPOT_DUAL_CONE_5_MASK     0x00200000L
#define SE_TCL_PER_LIGHT_CNTL_2__SPOT_DUAL_CONE_5          0x00200000L
#define SE_TCL_PER_LIGHT_CNTL_2__RNG_ATT_ENA_5_MASK        0x00400000L
#define SE_TCL_PER_LIGHT_CNTL_2__RNG_ATT_ENA_5             0x00400000L
#define SE_TCL_PER_LIGHT_CNTL_2__RNG_ATT_CONSTANT_ENA_5_MASK 0x00800000L
#define SE_TCL_PER_LIGHT_CNTL_2__RNG_ATT_CONSTANT_ENA_5    0x00800000L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_1BIT_NUM0_MASK   0x01000000L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_1BIT_NUM0        0x01000000L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_1BIT_NUM1_MASK   0x02000000L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_1BIT_NUM1        0x02000000L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_1BIT_NUM2_MASK   0x04000000L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_1BIT_NUM2        0x04000000L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_1BIT_NUM3_MASK   0x08000000L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_1BIT_NUM3        0x08000000L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_2BIT_NUM0_MASK   0x30000000L
#define SE_TCL_PER_LIGHT_CNTL_2__RSVD_LT5_2BIT_NUM1_MASK   0xc0000000L

// SE_TCL_PER_LIGHT_CNTL_3
#define SE_TCL_PER_LIGHT_CNTL_3__LIGHT_ENA_6_MASK          0x00000001L
#define SE_TCL_PER_LIGHT_CNTL_3__LIGHT_ENA_6               0x00000001L
#define SE_TCL_PER_LIGHT_CNTL_3__AMBIENT_ENA_6_MASK        0x00000002L
#define SE_TCL_PER_LIGHT_CNTL_3__AMBIENT_ENA_6             0x00000002L
#define SE_TCL_PER_LIGHT_CNTL_3__SPECULAR_ENA_6_MASK       0x00000004L
#define SE_TCL_PER_LIGHT_CNTL_3__SPECULAR_ENA_6            0x00000004L
#define SE_TCL_PER_LIGHT_CNTL_3__LOCAL_LIGHT_6_MASK        0x00000008L
#define SE_TCL_PER_LIGHT_CNTL_3__LOCAL_LIGHT_6             0x00000008L
#define SE_TCL_PER_LIGHT_CNTL_3__SPOT_ENA_6_MASK           0x00000010L
#define SE_TCL_PER_LIGHT_CNTL_3__SPOT_ENA_6                0x00000010L
#define SE_TCL_PER_LIGHT_CNTL_3__SPOT_DUAL_CONE_6_MASK     0x00000020L
#define SE_TCL_PER_LIGHT_CNTL_3__SPOT_DUAL_CONE_6          0x00000020L
#define SE_TCL_PER_LIGHT_CNTL_3__RNG_ATT_ENA_6_MASK        0x00000040L
#define SE_TCL_PER_LIGHT_CNTL_3__RNG_ATT_ENA_6             0x00000040L
#define SE_TCL_PER_LIGHT_CNTL_3__RNG_ATT_CONSTANT_ENA_6_MASK 0x00000080L
#define SE_TCL_PER_LIGHT_CNTL_3__RNG_ATT_CONSTANT_ENA_6    0x00000080L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_1BIT_NUM0_MASK   0x00000100L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_1BIT_NUM0        0x00000100L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_1BIT_NUM1_MASK   0x00000200L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_1BIT_NUM1        0x00000200L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_1BIT_NUM2_MASK   0x00000400L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_1BIT_NUM2        0x00000400L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_1BIT_NUM3_MASK   0x00000800L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_1BIT_NUM3        0x00000800L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_2BIT_NUM0_MASK   0x00003000L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT6_2BIT_NUM1_MASK   0x0000c000L
#define SE_TCL_PER_LIGHT_CNTL_3__LIGHT_ENA_7_MASK          0x00010000L
#define SE_TCL_PER_LIGHT_CNTL_3__LIGHT_ENA_7               0x00010000L
#define SE_TCL_PER_LIGHT_CNTL_3__AMBIENT_ENA_7_MASK        0x00020000L
#define SE_TCL_PER_LIGHT_CNTL_3__AMBIENT_ENA_7             0x00020000L
#define SE_TCL_PER_LIGHT_CNTL_3__SPECULAR_ENA_7_MASK       0x00040000L
#define SE_TCL_PER_LIGHT_CNTL_3__SPECULAR_ENA_7            0x00040000L
#define SE_TCL_PER_LIGHT_CNTL_3__LOCAL_LIGHT_7_MASK        0x00080000L
#define SE_TCL_PER_LIGHT_CNTL_3__LOCAL_LIGHT_7             0x00080000L
#define SE_TCL_PER_LIGHT_CNTL_3__SPOT_ENA_7_MASK           0x00100000L
#define SE_TCL_PER_LIGHT_CNTL_3__SPOT_ENA_7                0x00100000L
#define SE_TCL_PER_LIGHT_CNTL_3__SPOT_DUAL_CONE_7_MASK     0x00200000L
#define SE_TCL_PER_LIGHT_CNTL_3__SPOT_DUAL_CONE_7          0x00200000L
#define SE_TCL_PER_LIGHT_CNTL_3__RNG_ATT_ENA_7_MASK        0x00400000L
#define SE_TCL_PER_LIGHT_CNTL_3__RNG_ATT_ENA_7             0x00400000L
#define SE_TCL_PER_LIGHT_CNTL_3__RNG_ATT_CONSTANT_ENA_7_MASK 0x00800000L
#define SE_TCL_PER_LIGHT_CNTL_3__RNG_ATT_CONSTANT_ENA_7    0x00800000L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_1BIT_NUM0_MASK   0x01000000L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_1BIT_NUM0        0x01000000L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_1BIT_NUM1_MASK   0x02000000L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_1BIT_NUM1        0x02000000L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_1BIT_NUM2_MASK   0x04000000L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_1BIT_NUM2        0x04000000L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_1BIT_NUM3_MASK   0x08000000L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_1BIT_NUM3        0x08000000L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_2BIT_NUM0_MASK   0x30000000L
#define SE_TCL_PER_LIGHT_CNTL_3__RSVD_LT7_2BIT_NUM1_MASK   0xc0000000L

// SE_TCL_DEBUG_0
#define SE_TCL_DEBUG_0__DEBUG_RD_SEL_ENA_MASK              0x00000001L
#define SE_TCL_DEBUG_0__DEBUG_RD_SEL_ENA                   0x00000001L
#define SE_TCL_DEBUG_0__DEBUG_RD_SEL_MASK                  0x00000002L
#define SE_TCL_DEBUG_0__DEBUG_RD_SEL                       0x00000002L
#define SE_TCL_DEBUG_0__DEBUG_IMM_RD_MASK                  0x00000004L
#define SE_TCL_DEBUG_0__DEBUG_IMM_RD                       0x00000004L
#define SE_TCL_DEBUG_0__ST_UPD_FIFO_SZ_MASK                0x00000018L
#define SE_TCL_DEBUG_0__DIS_CLIP_ERR_DETECT_MASK           0x00000020L
#define SE_TCL_DEBUG_0__DIS_CLIP_ERR_DETECT                0x00000020L

// SE_TCL_STATE_FLUSH_REG
#define SE_TCL_STATE_FLUSH_REG__DATA_REGISTER_MASK         0xffffffffL

// SE_TCL_FPU_LATENCY_R2
#define SE_TCL_FPU_LATENCY_R2__VE_ENG_LATENCY_MASK         0x0000001fL
#define SE_TCL_FPU_LATENCY_R2__VE_MULT_LATENCY_MASK        0x000003e0L
#define SE_TCL_FPU_LATENCY_R2__VE_ACCUM_LATENCY_MASK       0x00007c00L
#define SE_TCL_FPU_LATENCY_R2__SC_ENG_LATENCY_MASK         0x000f8000L
#define SE_TCL_FPU_LATENCY_R2__VE_OUT_LATENCY_MASK         0x01f00000L
#define SE_TCL_FPU_LATENCY_R2__SC_MATH_LATENCY_MASK        0x3e000000L
#define SE_TCL_FPU_LATENCY_R2__RSVD_LTNCY_2BIT_MASK        0xc0000000L

// SE_TCL_TEX_PROC_CNTL_2
#define SE_TCL_TEX_PROC_CNTL_2__TCG_COMP_MASK_0_MASK       0x0000000fL
#define SE_TCL_TEX_PROC_CNTL_2__TCG_COMP_MASK_1_MASK       0x000000f0L
#define SE_TCL_TEX_PROC_CNTL_2__TCG_COMP_MASK_2_MASK       0x00000f00L
#define SE_TCL_TEX_PROC_CNTL_2__TCG_COMP_MASK_3_MASK       0x0000f000L
#define SE_TCL_TEX_PROC_CNTL_2__TCG_COMP_MASK_4_MASK       0x000f0000L
#define SE_TCL_TEX_PROC_CNTL_2__TCG_COMP_MASK_5_MASK       0x00f00000L

// SE_TCL_TEX_PROC_CNTL_3
#define SE_TCL_TEX_PROC_CNTL_3__TCG_INPUT_TEX_0_MASK       0x0000000fL
#define SE_TCL_TEX_PROC_CNTL_3__TCG_INPUT_TEX_1_MASK       0x000000f0L
#define SE_TCL_TEX_PROC_CNTL_3__TCG_INPUT_TEX_2_MASK       0x00000f00L
#define SE_TCL_TEX_PROC_CNTL_3__TCG_INPUT_TEX_3_MASK       0x0000f000L
#define SE_TCL_TEX_PROC_CNTL_3__TCG_INPUT_TEX_4_MASK       0x000f0000L
#define SE_TCL_TEX_PROC_CNTL_3__TCG_INPUT_TEX_5_MASK       0x00f00000L

// SE_TCL_TEX_PROC_CNTL_0
#define SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_0_MASK     0x00000001L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_0          0x00000001L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_1_MASK     0x00000002L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_1          0x00000002L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_2_MASK     0x00000004L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_2          0x00000004L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_3_MASK     0x00000008L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_3          0x00000008L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_4_MASK     0x00000010L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_4          0x00000010L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_5_MASK     0x00000020L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_CS_PROC_ENA_5          0x00000020L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_0_MASK       0x00000100L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_0            0x00000100L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_1_MASK       0x00000200L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_1            0x00000200L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_2_MASK       0x00000400L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_2            0x00000400L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_3_MASK       0x00000800L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_3            0x00000800L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_4_MASK       0x00001000L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_4            0x00001000L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_5_MASK       0x00002000L
#define SE_TCL_TEX_PROC_CNTL_0__TEX_XFORM_ENA_5            0x00002000L
#define SE_TCL_TEX_PROC_CNTL_0__TCG_FORCE_W_TO_ONE_MASK    0x00010000L
#define SE_TCL_TEX_PROC_CNTL_0__TCG_FORCE_W_TO_ONE         0x00010000L

// SE_TCL_TEX_PROC_CNTL_1
#define SE_TCL_TEX_PROC_CNTL_1__TEX_CS_PROC_SRC_0_MASK     0x0000000fL
#define SE_TCL_TEX_PROC_CNTL_1__TEX_CS_PROC_SRC_1_MASK     0x000000f0L
#define SE_TCL_TEX_PROC_CNTL_1__TEX_CS_PROC_SRC_2_MASK     0x00000f00L
#define SE_TCL_TEX_PROC_CNTL_1__TEX_CS_PROC_SRC_3_MASK     0x0000f000L
#define SE_TCL_TEX_PROC_CNTL_1__TEX_CS_PROC_SRC_4_MASK     0x000f0000L
#define SE_TCL_TEX_PROC_CNTL_1__TEX_CS_PROC_SRC_5_MASK     0x00f00000L

// SE_TCL_TEX_CYL_WRAP_CNTL
#define SE_TCL_TEX_CYL_WRAP_CNTL__TEX_CYL_WRAP_0_MASK      0x0000000fL
#define SE_TCL_TEX_CYL_WRAP_CNTL__TEX_CYL_WRAP_1_MASK      0x000000f0L
#define SE_TCL_TEX_CYL_WRAP_CNTL__TEX_CYL_WRAP_2_MASK      0x00000f00L
#define SE_TCL_TEX_CYL_WRAP_CNTL__TEX_CYL_WRAP_3_MASK      0x0000f000L
#define SE_TCL_TEX_CYL_WRAP_CNTL__TEX_CYL_WRAP_4_MASK      0x000f0000L
#define SE_TCL_TEX_CYL_WRAP_CNTL__TEX_CYL_WRAP_5_MASK      0x00f00000L

// SE_TCL_UCP_VTX_BLEND_CNTL
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_IN_CLIP_SPACE_MASK  0x00000001L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_IN_CLIP_SPACE       0x00000001L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_IN_MODEL_SPACE_MASK 0x00000002L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_IN_MODEL_SPACE      0x00000002L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_0_MASK          0x00000004L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_0               0x00000004L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_1_MASK          0x00000008L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_1               0x00000008L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_2_MASK          0x00000010L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_2               0x00000010L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_3_MASK          0x00000020L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_3               0x00000020L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_4_MASK          0x00000040L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_4               0x00000040L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_5_MASK          0x00000080L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_5               0x00000080L
#define SE_TCL_UCP_VTX_BLEND_CNTL__FOG_MODE_MASK           0x00000300L
#define SE_TCL_UCP_VTX_BLEND_CNTL__RNG_BASED_FOG_MASK      0x00000400L
#define SE_TCL_UCP_VTX_BLEND_CNTL__RNG_BASED_FOG           0x00000400L
#define SE_TCL_UCP_VTX_BLEND_CNTL__CLIP_DISABLE_MASK       0x00000800L
#define SE_TCL_UCP_VTX_BLEND_CNTL__CLIP_DISABLE            0x00000800L
#define SE_TCL_UCP_VTX_BLEND_CNTL__BLEND_OP_CNT_MASK       0x00007000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__USE_ST_BLEND_OP_CNT_MASK 0x00008000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__USE_ST_BLEND_OP_CNT     0x00008000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__POSITION_BLEND_OPERATION_MASK 0x00010000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__POSITION_BLEND_OPERATION 0x00010000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__NORMAL_BLEND_OPERATION_MASK 0x00020000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__NORMAL_BLEND_OPERATION  0x00020000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_SRC_0_MASK    0x00040000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_SRC_0         0x00040000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_SRC_1_MASK    0x00080000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_SRC_1         0x00080000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_SRC_2_MASK    0x00100000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_SRC_2         0x00100000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_SRC_3_MASK    0x00200000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_SRC_3         0x00200000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__BLEND_WEIGHT_MINUS_ONE_MASK 0x00400000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__BLEND_WEIGHT_MINUS_ONE  0x00400000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_USE_PROJ_MTX_MASK 0x00800000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_USE_PROJ_MTX  0x00800000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_2_OPTIMIZE_MASK 0x01000000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__VTX_BLEND_2_OPTIMIZE    0x01000000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__CULL_EQ_0_ENA_MASK      0x02000000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__CULL_EQ_0_ENA           0x02000000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__CULL_METHOD_MASK        0x0c000000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__CULLING_FF_DIR_MASK     0x10000000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__CULLING_FF_DIR          0x10000000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__CULL_FF_ENA_MASK        0x20000000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__CULL_FF_ENA             0x20000000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__CULL_BF_ENA_MASK        0x40000000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__CULL_BF_ENA             0x40000000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_CULL_ONLY_ENA_MASK  0x80000000L
#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_CULL_ONLY_ENA       0x80000000L

// SE_TCL_POINT_SPRITE_CNTL
#define SE_TCL_POINT_SPRITE_CNTL__PS_MULT_MASK             0x00000007L
#define SE_TCL_POINT_SPRITE_CNTL__PS_LIN_ATT_ZERO_MASK     0x00000008L
#define SE_TCL_POINT_SPRITE_CNTL__PS_LIN_ATT_ZERO          0x00000008L
#define SE_TCL_POINT_SPRITE_CNTL__PS_USE_MODEL_EYE_VEC_MASK 0x00000010L
#define SE_TCL_POINT_SPRITE_CNTL__PS_USE_MODEL_EYE_VEC     0x00000010L
#define SE_TCL_POINT_SPRITE_CNTL__PS_ATT_ALPHA_MASK        0x00000020L
#define SE_TCL_POINT_SPRITE_CNTL__PS_ATT_ALPHA             0x00000020L
#define SE_TCL_POINT_SPRITE_CNTL__PS_UCP_MODE_MASK         0x000000c0L
#define SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_0_MASK        0x00000100L
#define SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_0             0x00000100L
#define SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_1_MASK        0x00000200L
#define SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_1             0x00000200L
#define SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_2_MASK        0x00000400L
#define SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_2             0x00000400L
#define SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_3_MASK        0x00000800L
#define SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_3             0x00000800L
#define SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_4_MASK        0x00001000L
#define SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_4             0x00001000L
#define SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_5_MASK        0x00002000L
#define SE_TCL_POINT_SPRITE_CNTL__PS_GEN_TEX_5             0x00002000L
#define SE_TCL_POINT_SPRITE_CNTL__PS_SE_SEL_STATE_SIZE_MASK 0x00010000L
#define SE_TCL_POINT_SPRITE_CNTL__PS_SE_SEL_STATE_SIZE     0x00010000L
#define SE_TCL_POINT_SPRITE_CNTL__PS_DIS_VV_EARLY_EXIT_MASK 0x00020000L
#define SE_TCL_POINT_SPRITE_CNTL__PS_DIS_VV_EARLY_EXIT     0x00020000L

// SE_PVS_CNTL
#define SE_PVS_CNTL__PVS_FIRST_INST_MASK                   0x000003ffL
#define SE_PVS_CNTL__PVS_XYZW_VALID_INST_MASK              0x000ffc00L
#define SE_PVS_CNTL__PVS_LAST_INST_MASK                    0x3ff00000L

// SE_PVS_CONST_CNTL
#define SE_PVS_CONST_CNTL__PVS_CONST_BASE_OFFSET_MASK      0x000000ffL
#define SE_PVS_CONST_CNTL__PVS_MAX_CONST_ADDR_MASK         0x00ff0000L

// SE_VTX_ST_POS_0_X_4
#define SE_VTX_ST_POS_0_X_4__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_POS_0_Y_4
#define SE_VTX_ST_POS_0_Y_4__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_POS_0_Z_4
#define SE_VTX_ST_POS_0_Z_4__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_POS_0_W_4
#define SE_VTX_ST_POS_0_W_4__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_NORM_0_X
#define SE_VTX_ST_NORM_0_X__DATA_REGISTER_MASK             0xffffffffL

// SE_VTX_ST_NORM_0_Y
#define SE_VTX_ST_NORM_0_Y__DATA_REGISTER_MASK             0xffffffffL

// SE_VTX_ST_NORM_0_Z
#define SE_VTX_ST_NORM_0_Z__DATA_REGISTER_MASK             0xffffffffL

// SE_VTX_ST_PVMS
#define SE_VTX_ST_PVMS__DATA_REGISTER_MASK                 0xffffffffL

// SE_VTX_ST_CLR_0_R
#define SE_VTX_ST_CLR_0_R__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_0_G
#define SE_VTX_ST_CLR_0_G__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_0_B
#define SE_VTX_ST_CLR_0_B__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_0_A
#define SE_VTX_ST_CLR_0_A__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_1_R
#define SE_VTX_ST_CLR_1_R__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_1_G
#define SE_VTX_ST_CLR_1_G__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_1_B
#define SE_VTX_ST_CLR_1_B__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_1_A
#define SE_VTX_ST_CLR_1_A__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_2_R
#define SE_VTX_ST_CLR_2_R__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_2_G
#define SE_VTX_ST_CLR_2_G__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_2_B
#define SE_VTX_ST_CLR_2_B__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_2_A
#define SE_VTX_ST_CLR_2_A__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_3_R
#define SE_VTX_ST_CLR_3_R__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_3_G
#define SE_VTX_ST_CLR_3_G__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_3_B
#define SE_VTX_ST_CLR_3_B__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_3_A
#define SE_VTX_ST_CLR_3_A__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_4_R
#define SE_VTX_ST_CLR_4_R__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_4_G
#define SE_VTX_ST_CLR_4_G__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_4_B
#define SE_VTX_ST_CLR_4_B__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_4_A
#define SE_VTX_ST_CLR_4_A__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_5_R
#define SE_VTX_ST_CLR_5_R__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_5_G
#define SE_VTX_ST_CLR_5_G__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_5_B
#define SE_VTX_ST_CLR_5_B__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_5_A
#define SE_VTX_ST_CLR_5_A__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_6_R
#define SE_VTX_ST_CLR_6_R__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_6_G
#define SE_VTX_ST_CLR_6_G__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_6_B
#define SE_VTX_ST_CLR_6_B__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_6_A
#define SE_VTX_ST_CLR_6_A__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_7_R
#define SE_VTX_ST_CLR_7_R__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_7_G
#define SE_VTX_ST_CLR_7_G__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_7_B
#define SE_VTX_ST_CLR_7_B__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_CLR_7_A
#define SE_VTX_ST_CLR_7_A__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_0_S
#define SE_VTX_ST_TEX_0_S__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_0_T
#define SE_VTX_ST_TEX_0_T__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_0_R
#define SE_VTX_ST_TEX_0_R__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_0_Q
#define SE_VTX_ST_TEX_0_Q__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_1_S
#define SE_VTX_ST_TEX_1_S__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_1_T
#define SE_VTX_ST_TEX_1_T__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_1_R
#define SE_VTX_ST_TEX_1_R__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_1_Q
#define SE_VTX_ST_TEX_1_Q__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_2_S
#define SE_VTX_ST_TEX_2_S__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_2_T
#define SE_VTX_ST_TEX_2_T__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_2_R
#define SE_VTX_ST_TEX_2_R__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_2_Q
#define SE_VTX_ST_TEX_2_Q__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_3_S
#define SE_VTX_ST_TEX_3_S__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_3_T
#define SE_VTX_ST_TEX_3_T__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_3_R
#define SE_VTX_ST_TEX_3_R__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_3_Q
#define SE_VTX_ST_TEX_3_Q__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_4_S
#define SE_VTX_ST_TEX_4_S__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_4_T
#define SE_VTX_ST_TEX_4_T__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_4_R
#define SE_VTX_ST_TEX_4_R__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_4_Q
#define SE_VTX_ST_TEX_4_Q__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_5_S
#define SE_VTX_ST_TEX_5_S__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_5_T
#define SE_VTX_ST_TEX_5_T__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_5_R
#define SE_VTX_ST_TEX_5_R__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_TEX_5_Q
#define SE_VTX_ST_TEX_5_Q__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_PNT_SPRT_SZ
#define SE_VTX_ST_PNT_SPRT_SZ__DATA_REGISTER_MASK          0xffffffffL

// SE_VTX_ST_DISC_FOG
#define SE_VTX_ST_DISC_FOG__DATA_REGISTER_MASK             0xffffffffL

// SE_VTX_ST_SHININESS_0
#define SE_VTX_ST_SHININESS_0__DATA_REGISTER_MASK          0xffffffffL

// SE_VTX_ST_SHININESS_1
#define SE_VTX_ST_SHININESS_1__DATA_REGISTER_MASK          0xffffffffL

// SE_VTX_ST_BLND_WT_0
#define SE_VTX_ST_BLND_WT_0__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_BLND_WT_1
#define SE_VTX_ST_BLND_WT_1__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_BLND_WT_2
#define SE_VTX_ST_BLND_WT_2__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_BLND_WT_3
#define SE_VTX_ST_BLND_WT_3__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_POS_1_X
#define SE_VTX_ST_POS_1_X__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_POS_1_Y
#define SE_VTX_ST_POS_1_Y__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_POS_1_Z
#define SE_VTX_ST_POS_1_Z__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_POS_1_W
#define SE_VTX_ST_POS_1_W__DATA_REGISTER_MASK              0xffffffffL

// SE_VTX_ST_NORM_1_X
#define SE_VTX_ST_NORM_1_X__DATA_REGISTER_MASK             0xffffffffL

// SE_VTX_ST_NORM_1_Y
#define SE_VTX_ST_NORM_1_Y__DATA_REGISTER_MASK             0xffffffffL

// SE_VTX_ST_NORM_1_Z
#define SE_VTX_ST_NORM_1_Z__DATA_REGISTER_MASK             0xffffffffL

// SE_VTX_ST_SPARE_43C
#define SE_VTX_ST_SPARE_43C__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_USR_CLR_0_R
#define SE_VTX_ST_USR_CLR_0_R__DATA_REGISTER_MASK          0xffffffffL

// SE_VTX_ST_USR_CLR_0_G
#define SE_VTX_ST_USR_CLR_0_G__DATA_REGISTER_MASK          0xffffffffL

// SE_VTX_ST_USR_CLR_0_B
#define SE_VTX_ST_USR_CLR_0_B__DATA_REGISTER_MASK          0xffffffffL

// SE_VTX_ST_USR_CLR_0_A
#define SE_VTX_ST_USR_CLR_0_A__DATA_REGISTER_MASK          0xffffffffL

// SE_VTX_ST_USR_CLR_1_R
#define SE_VTX_ST_USR_CLR_1_R__DATA_REGISTER_MASK          0xffffffffL

// SE_VTX_ST_USR_CLR_1_G
#define SE_VTX_ST_USR_CLR_1_G__DATA_REGISTER_MASK          0xffffffffL

// SE_VTX_ST_USR_CLR_1_B
#define SE_VTX_ST_USR_CLR_1_B__DATA_REGISTER_MASK          0xffffffffL

// SE_VTX_ST_USR_CLR_1_A
#define SE_VTX_ST_USR_CLR_1_A__DATA_REGISTER_MASK          0xffffffffL

// SE_VTX_ST_CLR_0_PKD
#define SE_VTX_ST_CLR_0_PKD__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_CLR_1_PKD
#define SE_VTX_ST_CLR_1_PKD__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_CLR_2_PKD
#define SE_VTX_ST_CLR_2_PKD__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_CLR_3_PKD
#define SE_VTX_ST_CLR_3_PKD__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_CLR_4_PKD
#define SE_VTX_ST_CLR_4_PKD__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_CLR_5_PKD
#define SE_VTX_ST_CLR_5_PKD__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_CLR_6_PKD
#define SE_VTX_ST_CLR_6_PKD__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_CLR_7_PKD
#define SE_VTX_ST_CLR_7_PKD__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_POS_0_X_2
#define SE_VTX_ST_POS_0_X_2__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_POS_0_Y_2
#define SE_VTX_ST_POS_0_Y_2__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_PAR_CLR_LD
#define SE_VTX_ST_PAR_CLR_LD__DATA_REGISTER_MASK           0xffffffffL

// SE_VTX_ST_USR_CLR_PKD
#define SE_VTX_ST_USR_CLR_PKD__DATA_REGISTER_MASK          0xffffffffL

// SE_VTX_ST_POS_0_X_3
#define SE_VTX_ST_POS_0_X_3__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_POS_0_Y_3
#define SE_VTX_ST_POS_0_Y_3__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_POS_0_Z_3
#define SE_VTX_ST_POS_0_Z_3__DATA_REGISTER_MASK            0xffffffffL

// SE_VTX_ST_END_OF_PKT
#define SE_VTX_ST_END_OF_PKT__DATA_REGISTER_MASK           0xffffffffL

// RE_SOLID_COLOR
#define RE_SOLID_COLOR__SOLID_COLOR_MASK                   0xffffffffL

// RE_WIDTH_HEIGHT
#define RE_WIDTH_HEIGHT__WIDTH_MASK                        0x000007ffL
#define RE_WIDTH_HEIGHT__HEIGHT_MASK                       0x07ff0000L

// RE_POINTSIZE
#define RE_POINTSIZE__POINTSIZE_MASK                       0x0000ffffL
#define RE_POINTSIZE__MAXPOINTSIZE_MASK                    0xffff0000L

// SE_CNTL
#define SE_CNTL__FFACE_CULL_DIR_MASK                       0x00000001L
#define SE_CNTL__FFACE_CULL_DIR                            0x00000001L
#define SE_CNTL__BFACE_CULL_FCN_MASK                       0x00000006L
#define SE_CNTL__FFACE_CULL_FCN_MASK                       0x00000018L
#define SE_CNTL__FLAT_SHADE_VTX_MASK                       0x000000c0L
#define SE_CNTL__DIFFUSE_SHADE_FCN_MASK                    0x00000300L
#define SE_CNTL__ALPHA_SHADE_FCN_MASK                      0x00000c00L
#define SE_CNTL__SPECULAR_SHADE_FCN_MASK                   0x00003000L
#define SE_CNTL__FOG_SHADE_FCN_MASK                        0x0000c000L
#define SE_CNTL__ZBIAS_EN_POINT_MASK                       0x00010000L
#define SE_CNTL__ZBIAS_EN_POINT                            0x00010000L
#define SE_CNTL__ZBIAS_EN_LINE_MASK                        0x00020000L
#define SE_CNTL__ZBIAS_EN_LINE                             0x00020000L
#define SE_CNTL__ZBIAS_EN_TRI_MASK                         0x00040000L
#define SE_CNTL__ZBIAS_EN_TRI                              0x00040000L
#define SE_CNTL__WIDELINE_EN_MASK                          0x00100000L
#define SE_CNTL__WIDELINE_EN                               0x00100000L
#define SE_CNTL__DISCRETE_FOG_SHADE_FCN_MASK               0x03000000L
#define SE_CNTL__VTX_PIXCENTER_MASK                        0x08000000L
#define SE_CNTL__VTX_PIXCENTER                             0x08000000L
#define SE_CNTL__ROUND_MODE_MASK                           0x30000000L
#define SE_CNTL__ROUND_PRECISION_MASK                      0xc0000000L

// RE_CNTL
#define RE_CNTL__STIPPLE_ENABLE_MASK                       0x00000001L
#define RE_CNTL__STIPPLE_ENABLE                            0x00000001L
#define RE_CNTL__SCISSOR_ENABLE_MASK                       0x00000002L
#define RE_CNTL__SCISSOR_ENABLE                            0x00000002L
#define RE_CNTL__PATTERN_ENABLE_MASK                       0x00000004L
#define RE_CNTL__PATTERN_ENABLE                            0x00000004L
#define RE_CNTL__PERSPECTIVE_ENABLE_MASK                   0x00000008L
#define RE_CNTL__PERSPECTIVE_ENABLE                        0x00000008L
#define RE_CNTL__JITTER_ENABLE_MASK                        0x00000010L
#define RE_CNTL__JITTER_ENABLE                             0x00000010L
#define RE_CNTL__POINT_SMOOTH_MASK                         0x00000020L
#define RE_CNTL__POINT_SMOOTH                              0x00000020L
#define RE_CNTL__VTX_SAVE_T0_N3_MASK                       0x00000100L
#define RE_CNTL__VTX_SAVE_T0_N3                            0x00000100L
#define RE_CNTL__VTX_SAVE_T1_N3_MASK                       0x00000200L
#define RE_CNTL__VTX_SAVE_T1_N3                            0x00000200L
#define RE_CNTL__VTX_SAVE_T2_N3_MASK                       0x00000400L
#define RE_CNTL__VTX_SAVE_T2_N3                            0x00000400L
#define RE_CNTL__VTX_SAVE_T3_N3_MASK                       0x00000800L
#define RE_CNTL__VTX_SAVE_T3_N3                            0x00000800L
#define RE_CNTL__VTX_SAVE_T4_N3_MASK                       0x00001000L
#define RE_CNTL__VTX_SAVE_T4_N3                            0x00001000L
#define RE_CNTL__VTX_STQ0_ROUTE_MASK                       0x00030000L
#define RE_CNTL__VTX_STQ1_ROUTE_MASK                       0x000c0000L
#define RE_CNTL__VTX_STQ2_ROUTE_MASK                       0x00300000L
#define RE_CNTL__VTX_STQ3_ROUTE_MASK                       0x00c00000L
#define RE_CNTL__VTX_STQ4_ROUTE_MASK                       0x03000000L
#define RE_CNTL__VTX_STQ5_ROUTE_MASK                       0x0c000000L

// RE_PERF_CNTL
#define RE_PERF_CNTL__CULL_PRESETUP_MASK                   0x00000004L
#define RE_PERF_CNTL__CULL_PRESETUP                        0x00000004L
#define RE_PERF_CNTL__CULL_POSTSETUP_MASK                  0x00000008L
#define RE_PERF_CNTL__CULL_POSTSETUP                       0x00000008L
#define RE_PERF_CNTL__BLOCK_DISABLE_MASK                   0x00000010L
#define RE_PERF_CNTL__BLOCK_DISABLE                        0x00000010L
#define RE_PERF_CNTL__PERFSEL0_MASK                        0x00001f00L
#define RE_PERF_CNTL__CLR_PERF0_MASK                       0x00002000L
#define RE_PERF_CNTL__CLR_PERF0                            0x00002000L
#define RE_PERF_CNTL__EN_PERF0_MASK                        0x00004000L
#define RE_PERF_CNTL__EN_PERF0                             0x00004000L
#define RE_PERF_CNTL__PERFSEL1_MASK                        0x001f0000L
#define RE_PERF_CNTL__CLR_PERF1_MASK                       0x00200000L
#define RE_PERF_CNTL__CLR_PERF1                            0x00200000L
#define RE_PERF_CNTL__EN_PERF1_MASK                        0x00400000L
#define RE_PERF_CNTL__EN_PERF1                             0x00400000L
#define RE_PERF_CNTL__PERFSEL2_MASK                        0x1f000000L
#define RE_PERF_CNTL__CLR_PERF2_MASK                       0x20000000L
#define RE_PERF_CNTL__CLR_PERF2                            0x20000000L
#define RE_PERF_CNTL__EN_PERF2_MASK                        0x40000000L
#define RE_PERF_CNTL__EN_PERF2                             0x40000000L

// RE_PERF_COUNT_0
#define RE_PERF_COUNT_0__PERF_COUNT_MASK                   0xffffffffL

// RE_PERF_COUNT_1
#define RE_PERF_COUNT_1__PERF_COUNT_MASK                   0xffffffffL

// RE_PERF_COUNT_2
#define RE_PERF_COUNT_2__PERF_COUNT_MASK                   0xffffffffL

// RE_DEBUG0
#define RE_DEBUG0__RE_DWORD_MASK                           0xffffffffL

// RE_DEBUG1
#define RE_DEBUG1__RE_DWORD_MASK                           0xffffffffL

// RE_DEBUG2
#define RE_DEBUG2__RE_DWORD_MASK                           0xffffffffL

// RE_DEBUG3
#define RE_DEBUG3__RE_DWORD_MASK                           0xffffffffL

// RE_DEBUG4
#define RE_DEBUG4__RE_DWORD_MASK                           0xffffffffL

// RE_DEBUG5
#define RE_DEBUG5__RE_DWORD_MASK                           0xffffffffL

// RE_DEBUG6
#define RE_DEBUG6__RE_DWORD_MASK                           0xffffffffL

// RE_DEBUG7
#define RE_DEBUG7__ONE_PRIM_PER_PASS_MASK                  0x00000010L
#define RE_DEBUG7__ONE_PRIM_PER_PASS                       0x00000010L
#define RE_DEBUG7__RE_DBG_DATA_M9_MASK                     0xffffffe0L

// RE_TOP_LEFT
#define RE_TOP_LEFT__X_LEFT_MASK                           0x000007ffL
#define RE_TOP_LEFT__Y_TOP_MASK                            0x07ff0000L

// RE_MISC
#define RE_MISC__STIPPLE_X_OFFSET_MASK                     0x0000001fL
#define RE_MISC__STIPPLE_Y_OFFSET_MASK                     0x00001f00L
#define RE_MISC__STIPPLE_BIT_ORDER_MASK                    0x00010000L
#define RE_MISC__STIPPLE_BIT_ORDER                         0x00010000L

// RE_STIPPLE_ADDR
#define RE_STIPPLE_ADDR__STIPPLE_ADDR_MASK                 0x0000001fL

// RE_STIPPLE_DATA
#define RE_STIPPLE_DATA__STIPPLE_DATA_MASK                 0xffffffffL

// RE_LINE_PATTERN
#define RE_LINE_PATTERN__LINE_PATTERN_MASK                 0x0000ffffL
#define RE_LINE_PATTERN__REPEAT_COUNT_MASK                 0x00ff0000L
#define RE_LINE_PATTERN__PATTERN_START_MASK                0x0f000000L
#define RE_LINE_PATTERN__PATTERN_BIT_ORDER_MASK            0x10000000L
#define RE_LINE_PATTERN__PATTERN_BIT_ORDER                 0x10000000L
#define RE_LINE_PATTERN__AUTO_RESET_ENABLE_MASK            0x20000000L
#define RE_LINE_PATTERN__AUTO_RESET_ENABLE                 0x20000000L

// RE_LINE_STATE
#define RE_LINE_STATE__CURRENT_PTR_MASK                    0x0000000fL
#define RE_LINE_STATE__CURRENT_COUNT_MASK                  0x0000ff00L

// RE_SCISSOR_TL_0
#define RE_SCISSOR_TL_0__X_LEFT_MASK                       0x000007ffL
#define RE_SCISSOR_TL_0__Y_TOP_MASK                        0x07ff0000L

// RE_SCISSOR_BR_0
#define RE_SCISSOR_BR_0__X_RIGHT_MASK                      0x000007ffL
#define RE_SCISSOR_BR_0__Y_BOTTOM_MASK                     0x07ff0000L

// RE_SCISSOR_TL_1
#define RE_SCISSOR_TL_1__X_LEFT_MASK                       0x000007ffL
#define RE_SCISSOR_TL_1__Y_TOP_MASK                        0x07ff0000L

// RE_SCISSOR_BR_1
#define RE_SCISSOR_BR_1__X_RIGHT_MASK                      0x000007ffL
#define RE_SCISSOR_BR_1__Y_BOTTOM_MASK                     0x07ff0000L

// RE_SCISSOR_TL_2
#define RE_SCISSOR_TL_2__X_LEFT_MASK                       0x000007ffL
#define RE_SCISSOR_TL_2__Y_TOP_MASK                        0x07ff0000L

// RE_SCISSOR_BR_2
#define RE_SCISSOR_BR_2__X_RIGHT_MASK                      0x000007ffL
#define RE_SCISSOR_BR_2__Y_BOTTOM_MASK                     0x07ff0000L

// RE_AUX_SCISSOR_CNTL
#define RE_AUX_SCISSOR_CNTL__SCISSOR_UNION_ENABLE_MASK     0x00100000L
#define RE_AUX_SCISSOR_CNTL__SCISSOR_UNION_ENABLE          0x00100000L
#define RE_AUX_SCISSOR_CNTL__EXCLUSIVE_SCISSOR_0_MASK      0x01000000L
#define RE_AUX_SCISSOR_CNTL__EXCLUSIVE_SCISSOR_0           0x01000000L
#define RE_AUX_SCISSOR_CNTL__EXCLUSIVE_SCISSOR_1_MASK      0x02000000L
#define RE_AUX_SCISSOR_CNTL__EXCLUSIVE_SCISSOR_1           0x02000000L
#define RE_AUX_SCISSOR_CNTL__EXCLUSIVE_SCISSOR_2_MASK      0x04000000L
#define RE_AUX_SCISSOR_CNTL__EXCLUSIVE_SCISSOR_2           0x04000000L
#define RE_AUX_SCISSOR_CNTL__SCISSOR_ENABLE_0_MASK         0x10000000L
#define RE_AUX_SCISSOR_CNTL__SCISSOR_ENABLE_0              0x10000000L
#define RE_AUX_SCISSOR_CNTL__SCISSOR_ENABLE_1_MASK         0x20000000L
#define RE_AUX_SCISSOR_CNTL__SCISSOR_ENABLE_1              0x20000000L
#define RE_AUX_SCISSOR_CNTL__SCISSOR_ENABLE_2_MASK         0x40000000L
#define RE_AUX_SCISSOR_CNTL__SCISSOR_ENABLE_2              0x40000000L

// RE_JITTER_TABLE0
#define RE_JITTER_TABLE0__SAMPLE_SEL_00_MASK               0x0000000fL
#define RE_JITTER_TABLE0__SAMPLE_SEL_10_MASK               0x000000f0L
#define RE_JITTER_TABLE0__SAMPLE_SEL_20_MASK               0x00000f00L
#define RE_JITTER_TABLE0__SAMPLE_SEL_30_MASK               0x0000f000L
#define RE_JITTER_TABLE0__SAMPLE_SEL_01_MASK               0x000f0000L
#define RE_JITTER_TABLE0__SAMPLE_SEL_11_MASK               0x00f00000L
#define RE_JITTER_TABLE0__SAMPLE_SEL_21_MASK               0x0f000000L
#define RE_JITTER_TABLE0__SAMPLE_SEL_31_MASK               0xf0000000L

// RE_JITTER_TABLE1
#define RE_JITTER_TABLE1__SAMPLE_SEL_02_MASK               0x0000000fL
#define RE_JITTER_TABLE1__SAMPLE_SEL_12_MASK               0x000000f0L
#define RE_JITTER_TABLE1__SAMPLE_SEL_22_MASK               0x00000f00L
#define RE_JITTER_TABLE1__SAMPLE_SEL_32_MASK               0x0000f000L
#define RE_JITTER_TABLE1__SAMPLE_SEL_03_MASK               0x000f0000L
#define RE_JITTER_TABLE1__SAMPLE_SEL_13_MASK               0x00f00000L
#define RE_JITTER_TABLE1__SAMPLE_SEL_23_MASK               0x0f000000L
#define RE_JITTER_TABLE1__SAMPLE_SEL_33_MASK               0xf0000000L

// PP_FOG_TABLE_INDEX
#define PP_FOG_TABLE_INDEX__FOG_INDEX_MASK                 0x000000ffL

// PP_FOG_TABLE_DATA
#define PP_FOG_TABLE_DATA__FOG_DATA_MASK                   0x000000ffL

// SE_ZBIAS_FACTOR
#define SE_ZBIAS_FACTOR__ZBIAS_FACTOR_MASK                 0xffffffffL

// SE_ZBIAS_CONSTANT
#define SE_ZBIAS_CONSTANT__ZBIAS_CONSTANT_MASK             0xffffffffL

// SE_LINE_WIDTH
#define SE_LINE_WIDTH__LINE_WIDTH_MASK                     0x000003ffL
#define SE_LINE_WIDTH__MINPOINTSIZE_MASK                   0xffff0000L

// RE_W_BIAS
#define RE_W_BIAS__W_BIAS_MASK                             0xffffffffL

// SE_MC_SRC2_CNTL
#define SE_MC_SRC2_CNTL__MC_X2_MASK                        0x00001fffL
#define SE_MC_SRC2_CNTL__MC_Y2_MASK                        0x0fff0000L
#define SE_MC_SRC2_CNTL__MC_SEC_SRC_PITCH_MUL_MASK         0xc0000000L

// SE_MC_SRC1_CNTL
#define SE_MC_SRC1_CNTL__MC_X1_MASK                        0x00001fffL
#define SE_MC_SRC1_CNTL__MC_Y1_MASK                        0x0fff0000L
#define SE_MC_SRC1_CNTL__MC_IDCT_ENB_MASK                  0x10000000L
#define SE_MC_SRC1_CNTL__MC_IDCT_ENB                       0x10000000L
#define SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB_MASK               0x20000000L
#define SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB                    0x20000000L
#define SE_MC_SRC1_CNTL__MC_SRC_PITCH_MUL_MASK             0xc0000000L

// SE_MC_DST_CNTL
#define SE_MC_DST_CNTL__MC_DST_Y_MASK                      0x00003fffL
#define SE_MC_DST_CNTL__MC_DST_X_MASK                      0x3fff0000L
#define SE_MC_DST_CNTL__MC_DST_PITCH_MUL_MASK              0xc0000000L

// SE_MC_CNTL_START
#define SE_MC_CNTL_START__MC_CNTL_SRC_1_INDEX_MASK         0x0000000fL
#define SE_MC_CNTL_START__MC_CNTL_DST_OFFSET_MASK          0x01fffff0L
#define SE_MC_CNTL_START__MC_ALPHA_ENB_MASK                0x02000000L
#define SE_MC_CNTL_START__MC_ALPHA_ENB                     0x02000000L
#define SE_MC_CNTL_START__MC_CNTL_SRC_2_INDEX_MASK         0x1c000000L
#define SE_MC_CNTL_START__MC_CNTL_WIDTH_HEIGHT_SEL_MASK    0xe0000000L

// SE_MC_BUF_BASE
#define SE_MC_BUF_BASE__MC_BUF_BASE_MASK                   0xff000000L

// PP_TXFILTER_0
#define PP_TXFILTER_0__MAG_FILTER_MASK                     0x00000001L
#define PP_TXFILTER_0__MAG_FILTER                          0x00000001L
#define PP_TXFILTER_0__MIN_FILTER_MASK                     0x0000001eL
#define PP_TXFILTER_0__MAX_ANIS_MASK                       0x000000e0L
#define PP_TXFILTER_0__MAX_MIP_LEVEL_MASK                  0x000f0000L
#define PP_TXFILTER_0__YUV_TO_RGB_MASK                     0x00100000L
#define PP_TXFILTER_0__YUV_TO_RGB                          0x00100000L
#define PP_TXFILTER_0__YUV_TEMPERATURE_MASK                0x00200000L
#define PP_TXFILTER_0__YUV_TEMPERATURE                     0x00200000L
#define PP_TXFILTER_0__WRAPEN_S_MASK                       0x00400000L
#define PP_TXFILTER_0__WRAPEN_S                            0x00400000L
#define PP_TXFILTER_0__CLAMP_S_MASK                        0x03800000L
#define PP_TXFILTER_0__WRAPEN_T_MASK                       0x04000000L
#define PP_TXFILTER_0__WRAPEN_T                            0x04000000L
#define PP_TXFILTER_0__CLAMP_T_MASK                        0x38000000L
#define PP_TXFILTER_0__KILL_LT_0_MASK                      0x40000000L
#define PP_TXFILTER_0__KILL_LT_0                           0x40000000L
#define PP_TXFILTER_0__BORDER_MODE_MASK                    0x80000000L
#define PP_TXFILTER_0__BORDER_MODE                         0x80000000L

// PP_TXFILTER_1
#define PP_TXFILTER_1__MAG_FILTER_MASK                     0x00000001L
#define PP_TXFILTER_1__MAG_FILTER                          0x00000001L
#define PP_TXFILTER_1__MIN_FILTER_MASK                     0x0000001eL
#define PP_TXFILTER_1__MAX_ANIS_MASK                       0x000000e0L
#define PP_TXFILTER_1__MAX_MIP_LEVEL_MASK                  0x000f0000L
#define PP_TXFILTER_1__YUV_TO_RGB_MASK                     0x00100000L
#define PP_TXFILTER_1__YUV_TO_RGB                          0x00100000L
#define PP_TXFILTER_1__YUV_TEMPERATURE_MASK                0x00200000L
#define PP_TXFILTER_1__YUV_TEMPERATURE                     0x00200000L
#define PP_TXFILTER_1__WRAPEN_S_MASK                       0x00400000L
#define PP_TXFILTER_1__WRAPEN_S                            0x00400000L
#define PP_TXFILTER_1__CLAMP_S_MASK                        0x03800000L
#define PP_TXFILTER_1__WRAPEN_T_MASK                       0x04000000L
#define PP_TXFILTER_1__WRAPEN_T                            0x04000000L
#define PP_TXFILTER_1__CLAMP_T_MASK                        0x38000000L
#define PP_TXFILTER_1__KILL_LT_0_MASK                      0x40000000L
#define PP_TXFILTER_1__KILL_LT_0                           0x40000000L
#define PP_TXFILTER_1__BORDER_MODE_MASK                    0x80000000L
#define PP_TXFILTER_1__BORDER_MODE                         0x80000000L

// PP_TXFILTER_2
#define PP_TXFILTER_2__MAG_FILTER_MASK                     0x00000001L
#define PP_TXFILTER_2__MAG_FILTER                          0x00000001L
#define PP_TXFILTER_2__MIN_FILTER_MASK                     0x0000001eL
#define PP_TXFILTER_2__MAX_ANIS_MASK                       0x000000e0L
#define PP_TXFILTER_2__MAX_MIP_LEVEL_MASK                  0x000f0000L
#define PP_TXFILTER_2__YUV_TO_RGB_MASK                     0x00100000L
#define PP_TXFILTER_2__YUV_TO_RGB                          0x00100000L
#define PP_TXFILTER_2__YUV_TEMPERATURE_MASK                0x00200000L
#define PP_TXFILTER_2__YUV_TEMPERATURE                     0x00200000L
#define PP_TXFILTER_2__WRAPEN_S_MASK                       0x00400000L
#define PP_TXFILTER_2__WRAPEN_S                            0x00400000L
#define PP_TXFILTER_2__CLAMP_S_MASK                        0x03800000L
#define PP_TXFILTER_2__WRAPEN_T_MASK                       0x04000000L
#define PP_TXFILTER_2__WRAPEN_T                            0x04000000L
#define PP_TXFILTER_2__CLAMP_T_MASK                        0x38000000L
#define PP_TXFILTER_2__KILL_LT_0_MASK                      0x40000000L
#define PP_TXFILTER_2__KILL_LT_0                           0x40000000L
#define PP_TXFILTER_2__BORDER_MODE_MASK                    0x80000000L
#define PP_TXFILTER_2__BORDER_MODE                         0x80000000L

// PP_TXFILTER_3
#define PP_TXFILTER_3__MAG_FILTER_MASK                     0x00000001L
#define PP_TXFILTER_3__MAG_FILTER                          0x00000001L
#define PP_TXFILTER_3__MIN_FILTER_MASK                     0x0000001eL
#define PP_TXFILTER_3__MAX_ANIS_MASK                       0x000000e0L
#define PP_TXFILTER_3__MAX_MIP_LEVEL_MASK                  0x000f0000L
#define PP_TXFILTER_3__YUV_TO_RGB_MASK                     0x00100000L
#define PP_TXFILTER_3__YUV_TO_RGB                          0x00100000L
#define PP_TXFILTER_3__YUV_TEMPERATURE_MASK                0x00200000L
#define PP_TXFILTER_3__YUV_TEMPERATURE                     0x00200000L
#define PP_TXFILTER_3__WRAPEN_S_MASK                       0x00400000L
#define PP_TXFILTER_3__WRAPEN_S                            0x00400000L
#define PP_TXFILTER_3__CLAMP_S_MASK                        0x03800000L
#define PP_TXFILTER_3__WRAPEN_T_MASK                       0x04000000L
#define PP_TXFILTER_3__WRAPEN_T                            0x04000000L
#define PP_TXFILTER_3__CLAMP_T_MASK                        0x38000000L
#define PP_TXFILTER_3__KILL_LT_0_MASK                      0x40000000L
#define PP_TXFILTER_3__KILL_LT_0                           0x40000000L
#define PP_TXFILTER_3__BORDER_MODE_MASK                    0x80000000L
#define PP_TXFILTER_3__BORDER_MODE                         0x80000000L

// PP_TXFILTER_4
#define PP_TXFILTER_4__MAG_FILTER_MASK                     0x00000001L
#define PP_TXFILTER_4__MAG_FILTER                          0x00000001L
#define PP_TXFILTER_4__MIN_FILTER_MASK                     0x0000001eL
#define PP_TXFILTER_4__MAX_ANIS_MASK                       0x000000e0L
#define PP_TXFILTER_4__MAX_MIP_LEVEL_MASK                  0x000f0000L
#define PP_TXFILTER_4__YUV_TO_RGB_MASK                     0x00100000L
#define PP_TXFILTER_4__YUV_TO_RGB                          0x00100000L
#define PP_TXFILTER_4__YUV_TEMPERATURE_MASK                0x00200000L
#define PP_TXFILTER_4__YUV_TEMPERATURE                     0x00200000L
#define PP_TXFILTER_4__WRAPEN_S_MASK                       0x00400000L
#define PP_TXFILTER_4__WRAPEN_S                            0x00400000L
#define PP_TXFILTER_4__CLAMP_S_MASK                        0x03800000L
#define PP_TXFILTER_4__WRAPEN_T_MASK                       0x04000000L
#define PP_TXFILTER_4__WRAPEN_T                            0x04000000L
#define PP_TXFILTER_4__CLAMP_T_MASK                        0x38000000L
#define PP_TXFILTER_4__KILL_LT_0_MASK                      0x40000000L
#define PP_TXFILTER_4__KILL_LT_0                           0x40000000L
#define PP_TXFILTER_4__BORDER_MODE_MASK                    0x80000000L
#define PP_TXFILTER_4__BORDER_MODE                         0x80000000L

// PP_TXFILTER_5
#define PP_TXFILTER_5__MAG_FILTER_MASK                     0x00000001L
#define PP_TXFILTER_5__MAG_FILTER                          0x00000001L
#define PP_TXFILTER_5__MIN_FILTER_MASK                     0x0000001eL
#define PP_TXFILTER_5__MAX_ANIS_MASK                       0x000000e0L
#define PP_TXFILTER_5__MAX_MIP_LEVEL_MASK                  0x000f0000L
#define PP_TXFILTER_5__YUV_TO_RGB_MASK                     0x00100000L
#define PP_TXFILTER_5__YUV_TO_RGB                          0x00100000L
#define PP_TXFILTER_5__YUV_TEMPERATURE_MASK                0x00200000L
#define PP_TXFILTER_5__YUV_TEMPERATURE                     0x00200000L
#define PP_TXFILTER_5__WRAPEN_S_MASK                       0x00400000L
#define PP_TXFILTER_5__WRAPEN_S                            0x00400000L
#define PP_TXFILTER_5__CLAMP_S_MASK                        0x03800000L
#define PP_TXFILTER_5__WRAPEN_T_MASK                       0x04000000L
#define PP_TXFILTER_5__WRAPEN_T                            0x04000000L
#define PP_TXFILTER_5__CLAMP_T_MASK                        0x38000000L
#define PP_TXFILTER_5__KILL_LT_0_MASK                      0x40000000L
#define PP_TXFILTER_5__KILL_LT_0                           0x40000000L
#define PP_TXFILTER_5__BORDER_MODE_MASK                    0x80000000L
#define PP_TXFILTER_5__BORDER_MODE                         0x80000000L

// PP_TXFORMAT_0
#define PP_TXFORMAT_0__TXFORMAT_MASK                       0x0000001fL
#define PP_TXFORMAT_0__APPLE_YUV_MASK                      0x00000020L
#define PP_TXFORMAT_0__APPLE_YUV                           0x00000020L
#define PP_TXFORMAT_0__ALPHA_ENABLE_MASK                   0x00000040L
#define PP_TXFORMAT_0__ALPHA_ENABLE                        0x00000040L
#define PP_TXFORMAT_0__NON_POWER2_MASK                     0x00000080L
#define PP_TXFORMAT_0__NON_POWER2                          0x00000080L
#define PP_TXFORMAT_0__TXWIDTH_MASK                        0x00000f00L
#define PP_TXFORMAT_0__TXHEIGHT_MASK                       0x0000f000L
#define PP_TXFORMAT_0__FACE_WIDTH_5_MASK                   0x000f0000L
#define PP_TXFORMAT_0__FACE_HEIGHT_5_MASK                  0x00f00000L
#define PP_TXFORMAT_0__ST_ROUTE_R2_MASK                    0x07000000L
#define PP_TXFORMAT_0__LOOKUP_DISABLE_MASK                 0x08000000L
#define PP_TXFORMAT_0__LOOKUP_DISABLE                      0x08000000L
#define PP_TXFORMAT_0__ALPHA_MASK_ENABLE_MASK              0x10000000L
#define PP_TXFORMAT_0__ALPHA_MASK_ENABLE                   0x10000000L
#define PP_TXFORMAT_0__CHROMA_KEY_ENABLE_MASK              0x20000000L
#define PP_TXFORMAT_0__CHROMA_KEY_ENABLE                   0x20000000L

// PP_TXFORMAT_1
#define PP_TXFORMAT_1__TXFORMAT_MASK                       0x0000001fL
#define PP_TXFORMAT_1__APPLE_YUV_MASK                      0x00000020L
#define PP_TXFORMAT_1__APPLE_YUV                           0x00000020L
#define PP_TXFORMAT_1__ALPHA_ENABLE_MASK                   0x00000040L
#define PP_TXFORMAT_1__ALPHA_ENABLE                        0x00000040L
#define PP_TXFORMAT_1__NON_POWER2_MASK                     0x00000080L
#define PP_TXFORMAT_1__NON_POWER2                          0x00000080L
#define PP_TXFORMAT_1__TXWIDTH_MASK                        0x00000f00L
#define PP_TXFORMAT_1__TXHEIGHT_MASK                       0x0000f000L
#define PP_TXFORMAT_1__FACE_WIDTH_5_MASK                   0x000f0000L
#define PP_TXFORMAT_1__FACE_HEIGHT_5_MASK                  0x00f00000L
#define PP_TXFORMAT_1__ST_ROUTE_R2_MASK                    0x07000000L
#define PP_TXFORMAT_1__LOOKUP_DISABLE_MASK                 0x08000000L
#define PP_TXFORMAT_1__LOOKUP_DISABLE                      0x08000000L
#define PP_TXFORMAT_1__ALPHA_MASK_ENABLE_MASK              0x10000000L
#define PP_TXFORMAT_1__ALPHA_MASK_ENABLE                   0x10000000L
#define PP_TXFORMAT_1__CHROMA_KEY_ENABLE_MASK              0x20000000L
#define PP_TXFORMAT_1__CHROMA_KEY_ENABLE                   0x20000000L

// PP_TXFORMAT_2
#define PP_TXFORMAT_2__TXFORMAT_MASK                       0x0000001fL
#define PP_TXFORMAT_2__APPLE_YUV_MASK                      0x00000020L
#define PP_TXFORMAT_2__APPLE_YUV                           0x00000020L
#define PP_TXFORMAT_2__ALPHA_ENABLE_MASK                   0x00000040L
#define PP_TXFORMAT_2__ALPHA_ENABLE                        0x00000040L
#define PP_TXFORMAT_2__NON_POWER2_MASK                     0x00000080L
#define PP_TXFORMAT_2__NON_POWER2                          0x00000080L
#define PP_TXFORMAT_2__TXWIDTH_MASK                        0x00000f00L
#define PP_TXFORMAT_2__TXHEIGHT_MASK                       0x0000f000L
#define PP_TXFORMAT_2__FACE_WIDTH_5_MASK                   0x000f0000L
#define PP_TXFORMAT_2__FACE_HEIGHT_5_MASK                  0x00f00000L
#define PP_TXFORMAT_2__ST_ROUTE_R2_MASK                    0x07000000L
#define PP_TXFORMAT_2__LOOKUP_DISABLE_MASK                 0x08000000L
#define PP_TXFORMAT_2__LOOKUP_DISABLE                      0x08000000L
#define PP_TXFORMAT_2__ALPHA_MASK_ENABLE_MASK              0x10000000L
#define PP_TXFORMAT_2__ALPHA_MASK_ENABLE                   0x10000000L
#define PP_TXFORMAT_2__CHROMA_KEY_ENABLE_MASK              0x20000000L
#define PP_TXFORMAT_2__CHROMA_KEY_ENABLE                   0x20000000L

// PP_TXFORMAT_3
#define PP_TXFORMAT_3__TXFORMAT_MASK                       0x0000001fL
#define PP_TXFORMAT_3__APPLE_YUV_MASK                      0x00000020L
#define PP_TXFORMAT_3__APPLE_YUV                           0x00000020L
#define PP_TXFORMAT_3__ALPHA_ENABLE_MASK                   0x00000040L
#define PP_TXFORMAT_3__ALPHA_ENABLE                        0x00000040L
#define PP_TXFORMAT_3__NON_POWER2_MASK                     0x00000080L
#define PP_TXFORMAT_3__NON_POWER2                          0x00000080L
#define PP_TXFORMAT_3__TXWIDTH_MASK                        0x00000f00L
#define PP_TXFORMAT_3__TXHEIGHT_MASK                       0x0000f000L
#define PP_TXFORMAT_3__FACE_WIDTH_5_MASK                   0x000f0000L
#define PP_TXFORMAT_3__FACE_HEIGHT_5_MASK                  0x00f00000L
#define PP_TXFORMAT_3__ST_ROUTE_MASK                       0x07000000L
#define PP_TXFORMAT_3__LOOKUP_DISABLE_MASK                 0x08000000L
#define PP_TXFORMAT_3__LOOKUP_DISABLE                      0x08000000L
#define PP_TXFORMAT_3__ALPHA_MASK_ENABLE_MASK              0x10000000L
#define PP_TXFORMAT_3__ALPHA_MASK_ENABLE                   0x10000000L
#define PP_TXFORMAT_3__CHROMA_KEY_ENABLE_MASK              0x20000000L
#define PP_TXFORMAT_3__CHROMA_KEY_ENABLE                   0x20000000L

// PP_TXFORMAT_4
#define PP_TXFORMAT_4__TXFORMAT_MASK                       0x0000001fL
#define PP_TXFORMAT_4__APPLE_YUV_MASK                      0x00000020L
#define PP_TXFORMAT_4__APPLE_YUV                           0x00000020L
#define PP_TXFORMAT_4__ALPHA_ENABLE_MASK                   0x00000040L
#define PP_TXFORMAT_4__ALPHA_ENABLE                        0x00000040L
#define PP_TXFORMAT_4__NON_POWER2_MASK                     0x00000080L
#define PP_TXFORMAT_4__NON_POWER2                          0x00000080L
#define PP_TXFORMAT_4__TXWIDTH_MASK                        0x00000f00L
#define PP_TXFORMAT_4__TXHEIGHT_MASK                       0x0000f000L
#define PP_TXFORMAT_4__FACE_WIDTH_5_MASK                   0x000f0000L
#define PP_TXFORMAT_4__FACE_HEIGHT_5_MASK                  0x00f00000L
#define PP_TXFORMAT_4__ST_ROUTE_MASK                       0x07000000L
#define PP_TXFORMAT_4__LOOKUP_DISABLE_MASK                 0x08000000L
#define PP_TXFORMAT_4__LOOKUP_DISABLE                      0x08000000L
#define PP_TXFORMAT_4__ALPHA_MASK_ENABLE_MASK              0x10000000L
#define PP_TXFORMAT_4__ALPHA_MASK_ENABLE                   0x10000000L
#define PP_TXFORMAT_4__CHROMA_KEY_ENABLE_MASK              0x20000000L
#define PP_TXFORMAT_4__CHROMA_KEY_ENABLE                   0x20000000L

// PP_TXFORMAT_5
#define PP_TXFORMAT_5__TXFORMAT_MASK                       0x0000001fL
#define PP_TXFORMAT_5__APPLE_YUV_MASK                      0x00000020L
#define PP_TXFORMAT_5__APPLE_YUV                           0x00000020L
#define PP_TXFORMAT_5__ALPHA_ENABLE_MASK                   0x00000040L
#define PP_TXFORMAT_5__ALPHA_ENABLE                        0x00000040L
#define PP_TXFORMAT_5__NON_POWER2_MASK                     0x00000080L
#define PP_TXFORMAT_5__NON_POWER2                          0x00000080L
#define PP_TXFORMAT_5__TXWIDTH_MASK                        0x00000f00L
#define PP_TXFORMAT_5__TXHEIGHT_MASK                       0x0000f000L
#define PP_TXFORMAT_5__FACE_WIDTH_5_MASK                   0x000f0000L
#define PP_TXFORMAT_5__FACE_HEIGHT_5_MASK                  0x00f00000L
#define PP_TXFORMAT_5__ST_ROUTE_MASK                       0x07000000L
#define PP_TXFORMAT_5__LOOKUP_DISABLE_MASK                 0x08000000L
#define PP_TXFORMAT_5__LOOKUP_DISABLE                      0x08000000L
#define PP_TXFORMAT_5__ALPHA_MASK_ENABLE_MASK              0x10000000L
#define PP_TXFORMAT_5__ALPHA_MASK_ENABLE                   0x10000000L
#define PP_TXFORMAT_5__CHROMA_KEY_ENABLE_MASK              0x20000000L
#define PP_TXFORMAT_5__CHROMA_KEY_ENABLE                   0x20000000L

// PP_TXFORMAT_X_0
#define PP_TXFORMAT_X_0__TXDEPTH_MASK                      0x0000000fL
#define PP_TXFORMAT_X_0__VOLUME_FILTER_MASK                0x00000010L
#define PP_TXFORMAT_X_0__VOLUME_FILTER                     0x00000010L
#define PP_TXFORMAT_X_0__CLAMP_MODE_MASK                   0x00000080L
#define PP_TXFORMAT_X_0__CLAMP_MODE                        0x00000080L
#define PP_TXFORMAT_X_0__WRAPEN_Q_MASK                     0x00000100L
#define PP_TXFORMAT_X_0__WRAPEN_Q                          0x00000100L
#define PP_TXFORMAT_X_0__CLAMP_Q_MASK                      0x00000e00L
#define PP_TXFORMAT_X_0__MIN_MIP_LEVEL_MASK                0x0000f000L
#define PP_TXFORMAT_X_0__TEX_COORD_TYPE_MASK               0x00070000L
#define PP_TXFORMAT_X_0__LOD_BIAS_MASK                     0xfff80000L

// PP_TXFORMAT_X_1
#define PP_TXFORMAT_X_1__TXDEPTH_MASK                      0x0000000fL
#define PP_TXFORMAT_X_1__VOLUME_FILTER_MASK                0x00000010L
#define PP_TXFORMAT_X_1__VOLUME_FILTER                     0x00000010L
#define PP_TXFORMAT_X_1__CLAMP_MODE_MASK                   0x00000080L
#define PP_TXFORMAT_X_1__CLAMP_MODE                        0x00000080L
#define PP_TXFORMAT_X_1__WRAPEN_Q_MASK                     0x00000100L
#define PP_TXFORMAT_X_1__WRAPEN_Q                          0x00000100L
#define PP_TXFORMAT_X_1__CLAMP_Q_MASK                      0x00000e00L
#define PP_TXFORMAT_X_1__MIN_MIP_LEVEL_MASK                0x0000f000L
#define PP_TXFORMAT_X_1__TEX_COORD_TYPE_MASK               0x00070000L
#define PP_TXFORMAT_X_1__LOD_BIAS_MASK                     0xfff80000L

// PP_TXFORMAT_X_2
#define PP_TXFORMAT_X_2__TXDEPTH_MASK                      0x0000000fL
#define PP_TXFORMAT_X_2__VOLUME_FILTER_MASK                0x00000010L
#define PP_TXFORMAT_X_2__VOLUME_FILTER                     0x00000010L
#define PP_TXFORMAT_X_2__CLAMP_MODE_MASK                   0x00000080L
#define PP_TXFORMAT_X_2__CLAMP_MODE                        0x00000080L
#define PP_TXFORMAT_X_2__WRAPEN_Q_MASK                     0x00000100L
#define PP_TXFORMAT_X_2__WRAPEN_Q                          0x00000100L
#define PP_TXFORMAT_X_2__CLAMP_Q_MASK                      0x00000e00L
#define PP_TXFORMAT_X_2__MIN_MIP_LEVEL_MASK                0x0000f000L
#define PP_TXFORMAT_X_2__TEX_COORD_TYPE_MASK               0x00070000L
#define PP_TXFORMAT_X_2__LOD_BIAS_MASK                     0xfff80000L

// PP_TXFORMAT_X_3
#define PP_TXFORMAT_X_3__TXDEPTH_MASK                      0x0000000fL
#define PP_TXFORMAT_X_3__VOLUME_FILTER_MASK                0x00000010L
#define PP_TXFORMAT_X_3__VOLUME_FILTER                     0x00000010L
#define PP_TXFORMAT_X_3__CLAMP_MODE_MASK                   0x00000080L
#define PP_TXFORMAT_X_3__CLAMP_MODE                        0x00000080L
#define PP_TXFORMAT_X_3__WRAPEN_Q_MASK                     0x00000100L
#define PP_TXFORMAT_X_3__WRAPEN_Q                          0x00000100L
#define PP_TXFORMAT_X_3__CLAMP_Q_MASK                      0x00000e00L
#define PP_TXFORMAT_X_3__MIN_MIP_LEVEL_MASK                0x0000f000L
#define PP_TXFORMAT_X_3__TEX_COORD_TYPE_MASK               0x00070000L
#define PP_TXFORMAT_X_3__LOD_BIAS_MASK                     0xfff80000L

// PP_TXFORMAT_X_4
#define PP_TXFORMAT_X_4__TXDEPTH_MASK                      0x0000000fL
#define PP_TXFORMAT_X_4__VOLUME_FILTER_MASK                0x00000010L
#define PP_TXFORMAT_X_4__VOLUME_FILTER                     0x00000010L
#define PP_TXFORMAT_X_4__CLAMP_MODE_MASK                   0x00000080L
#define PP_TXFORMAT_X_4__CLAMP_MODE                        0x00000080L
#define PP_TXFORMAT_X_4__WRAPEN_Q_MASK                     0x00000100L
#define PP_TXFORMAT_X_4__WRAPEN_Q                          0x00000100L
#define PP_TXFORMAT_X_4__CLAMP_Q_MASK                      0x00000e00L
#define PP_TXFORMAT_X_4__MIN_MIP_LEVEL_MASK                0x0000f000L
#define PP_TXFORMAT_X_4__TEX_COORD_TYPE_MASK               0x00070000L
#define PP_TXFORMAT_X_4__LOD_BIAS_MASK                     0xfff80000L

// PP_TXFORMAT_X_5
#define PP_TXFORMAT_X_5__TXDEPTH_MASK                      0x0000000fL
#define PP_TXFORMAT_X_5__VOLUME_FILTER_MASK                0x00000010L
#define PP_TXFORMAT_X_5__VOLUME_FILTER                     0x00000010L
#define PP_TXFORMAT_X_5__CLAMP_MODE_MASK                   0x00000080L
#define PP_TXFORMAT_X_5__CLAMP_MODE                        0x00000080L
#define PP_TXFORMAT_X_5__WRAPEN_Q_MASK                     0x00000100L
#define PP_TXFORMAT_X_5__WRAPEN_Q                          0x00000100L
#define PP_TXFORMAT_X_5__CLAMP_Q_MASK                      0x00000e00L
#define PP_TXFORMAT_X_5__MIN_MIP_LEVEL_MASK                0x0000f000L
#define PP_TXFORMAT_X_5__TEX_COORD_TYPE_MASK               0x00070000L
#define PP_TXFORMAT_X_5__LOD_BIAS_MASK                     0xfff80000L

// PP_TEX_SIZE_0
#define PP_TEX_SIZE_0__TEX_USIZE_MASK                      0x000007ffL
#define PP_TEX_SIZE_0__TEX_VSIZE_MASK                      0x07ff0000L
#define PP_TEX_SIZE_0__SIGNED_RGB_MASK                     0x40000000L
#define PP_TEX_SIZE_0__SIGNED_RGB                          0x40000000L
#define PP_TEX_SIZE_0__SIGNED_ALPHA_MASK                   0x80000000L
#define PP_TEX_SIZE_0__SIGNED_ALPHA                        0x80000000L

// PP_TEX_SIZE_1
#define PP_TEX_SIZE_1__TEX_USIZE_MASK                      0x000007ffL
#define PP_TEX_SIZE_1__TEX_VSIZE_MASK                      0x07ff0000L
#define PP_TEX_SIZE_1__SIGNED_RGB_MASK                     0x40000000L
#define PP_TEX_SIZE_1__SIGNED_RGB                          0x40000000L
#define PP_TEX_SIZE_1__SIGNED_ALPHA_MASK                   0x80000000L
#define PP_TEX_SIZE_1__SIGNED_ALPHA                        0x80000000L

// PP_TEX_SIZE_2
#define PP_TEX_SIZE_2__TEX_USIZE_MASK                      0x000007ffL
#define PP_TEX_SIZE_2__TEX_VSIZE_MASK                      0x07ff0000L
#define PP_TEX_SIZE_2__SIGNED_RGB_MASK                     0x40000000L
#define PP_TEX_SIZE_2__SIGNED_RGB                          0x40000000L
#define PP_TEX_SIZE_2__SIGNED_ALPHA_MASK                   0x80000000L
#define PP_TEX_SIZE_2__SIGNED_ALPHA                        0x80000000L

// PP_TEX_SIZE_3
#define PP_TEX_SIZE_3__TEX_USIZE_MASK                      0x000007ffL
#define PP_TEX_SIZE_3__TEX_VSIZE_MASK                      0x07ff0000L
#define PP_TEX_SIZE_3__SIGNED_RGB_MASK                     0x40000000L
#define PP_TEX_SIZE_3__SIGNED_RGB                          0x40000000L
#define PP_TEX_SIZE_3__SIGNED_ALPHA_MASK                   0x80000000L
#define PP_TEX_SIZE_3__SIGNED_ALPHA                        0x80000000L

// PP_TEX_SIZE_4
#define PP_TEX_SIZE_4__TEX_USIZE_MASK                      0x000007ffL
#define PP_TEX_SIZE_4__TEX_VSIZE_MASK                      0x07ff0000L
#define PP_TEX_SIZE_4__SIGNED_RGB_MASK                     0x40000000L
#define PP_TEX_SIZE_4__SIGNED_RGB                          0x40000000L
#define PP_TEX_SIZE_4__SIGNED_ALPHA_MASK                   0x80000000L
#define PP_TEX_SIZE_4__SIGNED_ALPHA                        0x80000000L

// PP_TEX_SIZE_5
#define PP_TEX_SIZE_5__TEX_USIZE_MASK                      0x000007ffL
#define PP_TEX_SIZE_5__TEX_VSIZE_MASK                      0x07ff0000L
#define PP_TEX_SIZE_5__SIGNED_RGB_MASK                     0x40000000L
#define PP_TEX_SIZE_5__SIGNED_RGB                          0x40000000L
#define PP_TEX_SIZE_5__SIGNED_ALPHA_MASK                   0x80000000L
#define PP_TEX_SIZE_5__SIGNED_ALPHA                        0x80000000L

// PP_TXPITCH_0
#define PP_TXPITCH_0__TXPITCH_MASK                         0x00003fe0L
#define PP_TXPITCH_0__TEX_TAG_CNTL_RV_MASK                 0xe0000000L

// PP_TXPITCH_1
#define PP_TXPITCH_1__TXPITCH_MASK                         0x00003fe0L
#define PP_TXPITCH_1__TEX_TAG_CNTL_RV_MASK                 0xe0000000L

// PP_TXPITCH_2
#define PP_TXPITCH_2__TXPITCH_MASK                         0x00003fe0L
#define PP_TXPITCH_2__TEX_TAG_CNTL_RV_MASK                 0xe0000000L

// PP_TXPITCH_3
#define PP_TXPITCH_3__TXPITCH_MASK                         0x00003fe0L
#define PP_TXPITCH_3__TEX_TAG_CNTL_RV_MASK                 0xe0000000L

// PP_TXPITCH_4
#define PP_TXPITCH_4__TXPITCH_MASK                         0x00003fe0L
#define PP_TXPITCH_4__TEX_TAG_CNTL_RV_MASK                 0xe0000000L

// PP_TXPITCH_5
#define PP_TXPITCH_5__TXPITCH_MASK                         0x00003fe0L
#define PP_TXPITCH_5__TEX_TAG_CNTL_RV_MASK                 0xe0000000L

// PP_BORDER_COLOR_0
#define PP_BORDER_COLOR_0__BORD_COLOR_MASK                 0xffffffffL

// PP_BORDER_COLOR_1
#define PP_BORDER_COLOR_1__BORD_COLOR_MASK                 0xffffffffL

// PP_BORDER_COLOR_2
#define PP_BORDER_COLOR_2__BORD_COLOR_MASK                 0xffffffffL

// PP_BORDER_COLOR_3
#define PP_BORDER_COLOR_3__BORD_COLOR_MASK                 0xffffffffL

// PP_BORDER_COLOR_4
#define PP_BORDER_COLOR_4__BORD_COLOR_MASK                 0xffffffffL

// PP_BORDER_COLOR_5
#define PP_BORDER_COLOR_5__BORD_COLOR_MASK                 0xffffffffL

// PP_CUBIC_FACES_0
#define PP_CUBIC_FACES_0__FACE_WIDTH_1_MASK                0x0000000fL
#define PP_CUBIC_FACES_0__FACE_HEIGHT_1_MASK               0x000000f0L
#define PP_CUBIC_FACES_0__FACE_WIDTH_2_MASK                0x00000f00L
#define PP_CUBIC_FACES_0__FACE_HEIGHT_2_MASK               0x0000f000L
#define PP_CUBIC_FACES_0__FACE_WIDTH_3_MASK                0x000f0000L
#define PP_CUBIC_FACES_0__FACE_HEIGHT_3_MASK               0x00f00000L
#define PP_CUBIC_FACES_0__FACE_WIDTH_4_MASK                0x0f000000L
#define PP_CUBIC_FACES_0__FACE_HEIGHT_4_MASK               0xf0000000L

// PP_CUBIC_FACES_1
#define PP_CUBIC_FACES_1__FACE_WIDTH_1_MASK                0x0000000fL
#define PP_CUBIC_FACES_1__FACE_HEIGHT_1_MASK               0x000000f0L
#define PP_CUBIC_FACES_1__FACE_WIDTH_2_MASK                0x00000f00L
#define PP_CUBIC_FACES_1__FACE_HEIGHT_2_MASK               0x0000f000L
#define PP_CUBIC_FACES_1__FACE_WIDTH_3_MASK                0x000f0000L
#define PP_CUBIC_FACES_1__FACE_HEIGHT_3_MASK               0x00f00000L
#define PP_CUBIC_FACES_1__FACE_WIDTH_4_MASK                0x0f000000L
#define PP_CUBIC_FACES_1__FACE_HEIGHT_4_MASK               0xf0000000L

// PP_CUBIC_FACES_2
#define PP_CUBIC_FACES_2__FACE_WIDTH_1_MASK                0x0000000fL
#define PP_CUBIC_FACES_2__FACE_HEIGHT_1_MASK               0x000000f0L
#define PP_CUBIC_FACES_2__FACE_WIDTH_2_MASK                0x00000f00L
#define PP_CUBIC_FACES_2__FACE_HEIGHT_2_MASK               0x0000f000L
#define PP_CUBIC_FACES_2__FACE_WIDTH_3_MASK                0x000f0000L
#define PP_CUBIC_FACES_2__FACE_HEIGHT_3_MASK               0x00f00000L
#define PP_CUBIC_FACES_2__FACE_WIDTH_4_MASK                0x0f000000L
#define PP_CUBIC_FACES_2__FACE_HEIGHT_4_MASK               0xf0000000L

// PP_CUBIC_FACES_3
#define PP_CUBIC_FACES_3__FACE_WIDTH_1_MASK                0x0000000fL
#define PP_CUBIC_FACES_3__FACE_HEIGHT_1_MASK               0x000000f0L
#define PP_CUBIC_FACES_3__FACE_WIDTH_2_MASK                0x00000f00L
#define PP_CUBIC_FACES_3__FACE_HEIGHT_2_MASK               0x0000f000L
#define PP_CUBIC_FACES_3__FACE_WIDTH_3_MASK                0x000f0000L
#define PP_CUBIC_FACES_3__FACE_HEIGHT_3_MASK               0x00f00000L
#define PP_CUBIC_FACES_3__FACE_WIDTH_4_MASK                0x0f000000L
#define PP_CUBIC_FACES_3__FACE_HEIGHT_4_MASK               0xf0000000L

// PP_CUBIC_FACES_4
#define PP_CUBIC_FACES_4__FACE_WIDTH_1_MASK                0x0000000fL
#define PP_CUBIC_FACES_4__FACE_HEIGHT_1_MASK               0x000000f0L
#define PP_CUBIC_FACES_4__FACE_WIDTH_2_MASK                0x00000f00L
#define PP_CUBIC_FACES_4__FACE_HEIGHT_2_MASK               0x0000f000L
#define PP_CUBIC_FACES_4__FACE_WIDTH_3_MASK                0x000f0000L
#define PP_CUBIC_FACES_4__FACE_HEIGHT_3_MASK               0x00f00000L
#define PP_CUBIC_FACES_4__FACE_WIDTH_4_MASK                0x0f000000L
#define PP_CUBIC_FACES_4__FACE_HEIGHT_4_MASK               0xf0000000L

// PP_CUBIC_FACES_5
#define PP_CUBIC_FACES_5__FACE_WIDTH_1_MASK                0x0000000fL
#define PP_CUBIC_FACES_5__FACE_HEIGHT_1_MASK               0x000000f0L
#define PP_CUBIC_FACES_5__FACE_WIDTH_2_MASK                0x00000f00L
#define PP_CUBIC_FACES_5__FACE_HEIGHT_2_MASK               0x0000f000L
#define PP_CUBIC_FACES_5__FACE_WIDTH_3_MASK                0x000f0000L
#define PP_CUBIC_FACES_5__FACE_HEIGHT_3_MASK               0x00f00000L
#define PP_CUBIC_FACES_5__FACE_WIDTH_4_MASK                0x0f000000L
#define PP_CUBIC_FACES_5__FACE_HEIGHT_4_MASK               0xf0000000L

// PP_TXMULTI_CTL_0
#define PP_TXMULTI_CTL_0__LOOKUP_DISABLE_1_MASK            0x00000001L
#define PP_TXMULTI_CTL_0__LOOKUP_DISABLE_1                 0x00000001L
#define PP_TXMULTI_CTL_0__TEX_COORD_TYPE_1_MASK            0x0000000eL
#define PP_TXMULTI_CTL_0__ST_ROUTE_1_MASK                  0x000000f0L
#define PP_TXMULTI_CTL_0__CLAMP_MODE_MASK                  0x00000100L
#define PP_TXMULTI_CTL_0__CLAMP_MODE                       0x00000100L
#define PP_TXMULTI_CTL_0__ST_ROUTE_2_MASK                  0x07000000L

// PP_TXMULTI_CTL_1
#define PP_TXMULTI_CTL_1__LOOKUP_DISABLE_1_MASK            0x00000001L
#define PP_TXMULTI_CTL_1__LOOKUP_DISABLE_1                 0x00000001L
#define PP_TXMULTI_CTL_1__TEX_COORD_TYPE_1_MASK            0x0000000eL
#define PP_TXMULTI_CTL_1__ST_ROUTE_1_MASK                  0x000000f0L
#define PP_TXMULTI_CTL_1__CLAMP_MODE_MASK                  0x00000100L
#define PP_TXMULTI_CTL_1__CLAMP_MODE                       0x00000100L
#define PP_TXMULTI_CTL_1__ST_ROUTE_2_MASK                  0x07000000L

// PP_TXMULTI_CTL_2
#define PP_TXMULTI_CTL_2__LOOKUP_DISABLE_1_MASK            0x00000001L
#define PP_TXMULTI_CTL_2__LOOKUP_DISABLE_1                 0x00000001L
#define PP_TXMULTI_CTL_2__TEX_COORD_TYPE_1_MASK            0x0000000eL
#define PP_TXMULTI_CTL_2__ST_ROUTE_1_MASK                  0x000000f0L
#define PP_TXMULTI_CTL_2__CLAMP_MODE_MASK                  0x00000100L
#define PP_TXMULTI_CTL_2__CLAMP_MODE                       0x00000100L
#define PP_TXMULTI_CTL_2__ST_ROUTE_2_MASK                  0x07000000L

// PP_TXMULTI_CTL_3
#define PP_TXMULTI_CTL_3__LOOKUP_DISABLE_1_MASK            0x00000001L
#define PP_TXMULTI_CTL_3__LOOKUP_DISABLE_1                 0x00000001L
#define PP_TXMULTI_CTL_3__TEX_COORD_TYPE_1_MASK            0x0000000eL
#define PP_TXMULTI_CTL_3__ST_ROUTE_1_MASK                  0x000000f0L
#define PP_TXMULTI_CTL_3__CLAMP_MODE_MASK                  0x00000100L
#define PP_TXMULTI_CTL_3__CLAMP_MODE                       0x00000100L
#define PP_TXMULTI_CTL_3__ST_ROUTE_2_MASK                  0x07000000L

// PP_TXMULTI_CTL_4
#define PP_TXMULTI_CTL_4__LOOKUP_DISABLE_1_MASK            0x00000001L
#define PP_TXMULTI_CTL_4__LOOKUP_DISABLE_1                 0x00000001L
#define PP_TXMULTI_CTL_4__TEX_COORD_TYPE_1_MASK            0x0000000eL
#define PP_TXMULTI_CTL_4__ST_ROUTE_1_MASK                  0x000000f0L
#define PP_TXMULTI_CTL_4__CLAMP_MODE_MASK                  0x00000100L
#define PP_TXMULTI_CTL_4__CLAMP_MODE                       0x00000100L
#define PP_TXMULTI_CTL_4__ST_ROUTE_2_MASK                  0x07000000L

// PP_TXMULTI_CTL_5
#define PP_TXMULTI_CTL_5__LOOKUP_DISABLE_1_MASK            0x00000001L
#define PP_TXMULTI_CTL_5__LOOKUP_DISABLE_1                 0x00000001L
#define PP_TXMULTI_CTL_5__TEX_COORD_TYPE_1_MASK            0x0000000eL
#define PP_TXMULTI_CTL_5__ST_ROUTE_1_MASK                  0x000000f0L
#define PP_TXMULTI_CTL_5__CLAMP_MODE_MASK                  0x00000100L
#define PP_TXMULTI_CTL_5__CLAMP_MODE                       0x00000100L
#define PP_TXMULTI_CTL_5__ST_ROUTE_2_MASK                  0x07000000L

// PP_CNTL
#define PP_CNTL__TEX_0_ENABLE_MASK                         0x00000010L
#define PP_CNTL__TEX_0_ENABLE                              0x00000010L
#define PP_CNTL__TEX_1_ENABLE_MASK                         0x00000020L
#define PP_CNTL__TEX_1_ENABLE                              0x00000020L
#define PP_CNTL__TEX_2_ENABLE_MASK                         0x00000040L
#define PP_CNTL__TEX_2_ENABLE                              0x00000040L
#define PP_CNTL__TEX_3_ENABLE_MASK                         0x00000080L
#define PP_CNTL__TEX_3_ENABLE                              0x00000080L
#define PP_CNTL__TEX_4_ENABLE_MASK                         0x00000100L
#define PP_CNTL__TEX_4_ENABLE                              0x00000100L
#define PP_CNTL__TEX_5_ENABLE_MASK                         0x00000200L
#define PP_CNTL__TEX_5_ENABLE                              0x00000200L
#define PP_CNTL__FILTER_ROUND_MODE_MASK                    0x00000400L
#define PP_CNTL__FILTER_ROUND_MODE                         0x00000400L
#define PP_CNTL__TEX_BLEND_7_ENABLE_MASK                   0x00000800L
#define PP_CNTL__TEX_BLEND_7_ENABLE                        0x00000800L
#define PP_CNTL__TEX_BLEND_0_ENABLE_MASK                   0x00001000L
#define PP_CNTL__TEX_BLEND_0_ENABLE                        0x00001000L
#define PP_CNTL__TEX_BLEND_1_ENABLE_MASK                   0x00002000L
#define PP_CNTL__TEX_BLEND_1_ENABLE                        0x00002000L
#define PP_CNTL__TEX_BLEND_2_ENABLE_MASK                   0x00004000L
#define PP_CNTL__TEX_BLEND_2_ENABLE                        0x00004000L
#define PP_CNTL__TEX_BLEND_3_ENABLE_MASK                   0x00008000L
#define PP_CNTL__TEX_BLEND_3_ENABLE                        0x00008000L
#define PP_CNTL__TEX_BLEND_4_ENABLE_MASK                   0x00010000L
#define PP_CNTL__TEX_BLEND_4_ENABLE                        0x00010000L
#define PP_CNTL__TEX_BLEND_5_ENABLE_MASK                   0x00020000L
#define PP_CNTL__TEX_BLEND_5_ENABLE                        0x00020000L
#define PP_CNTL__TEX_BLEND_6_ENABLE_MASK                   0x00040000L
#define PP_CNTL__TEX_BLEND_6_ENABLE                        0x00040000L
#define PP_CNTL__MULTI_PASS_ENABLE_MASK                    0x00080000L
#define PP_CNTL__MULTI_PASS_ENABLE                         0x00080000L
#define PP_CNTL__SPECULAR_ENABLE_MASK                      0x00200000L
#define PP_CNTL__SPECULAR_ENABLE                           0x00200000L
#define PP_CNTL__FOG_ENABLE_MASK                           0x00400000L
#define PP_CNTL__FOG_ENABLE                                0x00400000L
#define PP_CNTL__ALPHA_TEST_ENABLE_MASK                    0x00800000L
#define PP_CNTL__ALPHA_TEST_ENABLE                         0x00800000L
#define PP_CNTL__ANTI_ALIAS_CTL_MASK                       0x03000000L
#define PP_CNTL__MC_ENABLE_MASK                            0x80000000L
#define PP_CNTL__MC_ENABLE                                 0x80000000L

// PP_CNTL_X
#define PP_CNTL_X__TEX_0_ENABLE_PASS_1_MASK                0x00000001L
#define PP_CNTL_X__TEX_0_ENABLE_PASS_1                     0x00000001L
#define PP_CNTL_X__TEX_1_ENABLE_PASS_1_MASK                0x00000002L
#define PP_CNTL_X__TEX_1_ENABLE_PASS_1                     0x00000002L
#define PP_CNTL_X__TEX_2_ENABLE_PASS_1_MASK                0x00000004L
#define PP_CNTL_X__TEX_2_ENABLE_PASS_1                     0x00000004L
#define PP_CNTL_X__TEX_3_ENABLE_PASS_1_MASK                0x00000008L
#define PP_CNTL_X__TEX_3_ENABLE_PASS_1                     0x00000008L
#define PP_CNTL_X__TEX_4_ENABLE_PASS_1_MASK                0x00000010L
#define PP_CNTL_X__TEX_4_ENABLE_PASS_1                     0x00000010L
#define PP_CNTL_X__TEX_5_ENABLE_PASS_1_MASK                0x00000020L
#define PP_CNTL_X__TEX_5_ENABLE_PASS_1                     0x00000020L
#define PP_CNTL_X__INDIRECT_REGS_MASK                      0x00000fc0L
#define PP_CNTL_X__TEX_BLEND_A0_ENABLE_MASK                0x00001000L
#define PP_CNTL_X__TEX_BLEND_A0_ENABLE                     0x00001000L
#define PP_CNTL_X__TEX_BLEND_A1_ENABLE_MASK                0x00002000L
#define PP_CNTL_X__TEX_BLEND_A1_ENABLE                     0x00002000L
#define PP_CNTL_X__TEX_BLEND_A2_ENABLE_MASK                0x00004000L
#define PP_CNTL_X__TEX_BLEND_A2_ENABLE                     0x00004000L
#define PP_CNTL_X__TEX_BLEND_A3_ENABLE_MASK                0x00008000L
#define PP_CNTL_X__TEX_BLEND_A3_ENABLE                     0x00008000L
#define PP_CNTL_X__TEX_BLEND_A4_ENABLE_MASK                0x00010000L
#define PP_CNTL_X__TEX_BLEND_A4_ENABLE                     0x00010000L
#define PP_CNTL_X__TEX_BLEND_A5_ENABLE_MASK                0x00020000L
#define PP_CNTL_X__TEX_BLEND_A5_ENABLE                     0x00020000L
#define PP_CNTL_X__TEX_BLEND_A6_ENABLE_MASK                0x00040000L
#define PP_CNTL_X__TEX_BLEND_A6_ENABLE                     0x00040000L
#define PP_CNTL_X__TEX_BLEND_A7_ENABLE_MASK                0x00080000L
#define PP_CNTL_X__TEX_BLEND_A7_ENABLE                     0x00080000L
#define PP_CNTL_X__SHADER_OUTPUT_CNTL_MASK                 0x80000000L
#define PP_CNTL_X__SHADER_OUTPUT_CNTL                      0x80000000L

// PP_MISC
#define PP_MISC__REF_ALPHA_MASK                            0x000000ffL
#define PP_MISC__ALPHA_TEST_OP_MASK                        0x00000700L
#define PP_MISC__CHROMA_FUNC_MASK                          0x00030000L
#define PP_MISC__CHROMA_KEY_MODE_MASK                      0x00040000L
#define PP_MISC__CHROMA_KEY_MODE                           0x00040000L
#define PP_MISC__RIGHT_HAND_CUBE_MASK                      0x01000000L
#define PP_MISC__RIGHT_HAND_CUBE                           0x01000000L

// PP_CHROMA_COLOR
#define PP_CHROMA_COLOR__CHROMA_COLOR_MASK                 0xffffffffL

// PP_CHROMA_MASK
#define PP_CHROMA_MASK__CHROMA_MASK_MASK                   0xffffffffL

// PP_FOG_COLOR
#define PP_FOG_COLOR__FOG_COLOR_MASK                       0x00ffffffL
#define PP_FOG_COLOR__FOG_TABLE_MASK                       0x01000000L
#define PP_FOG_COLOR__FOG_TABLE                            0x01000000L
#define PP_FOG_COLOR__FOG_INDEX_SEL_R2_MASK                0x0e000000L

// PP_PERF_COUNT0
#define PP_PERF_COUNT0__PP_CACHE_COUNT_MASK                0xffffffffL

// PP_MC_CONTEXT
#define PP_MC_CONTEXT__MC_BUF_BASE_MASK                    0x000000ffL
#define PP_MC_CONTEXT__SRC1_INDEX_MASK                     0x00000f00L
#define PP_MC_CONTEXT__SRC2_INDEX_MASK                     0x00007000L
#define PP_MC_CONTEXT__MC_FUNC_MASK                        0x00038000L
#define PP_MC_CONTEXT__DST_PITCH_MUL_MASK                  0x000c0000L
#define PP_MC_CONTEXT__SRC_2_PITCH_MUL_MASK                0x00300000L
#define PP_MC_CONTEXT__SRC_1_PITCH_MUL_MASK                0x00c00000L
#define PP_MC_CONTEXT__MC_CNTL_WIDTH_HEIGHT_SEL_MASK       0x07000000L

// PP_LUMI_MATRIX
#define PP_LUMI_MATRIX__LSCALE_MASK                        0x0000ffffL
#define PP_LUMI_MATRIX__LOFFSET_MASK                       0xffff0000L

// PP_ROT_MATRIX0
#define PP_ROT_MATRIX0__M00_MASK                           0x0000ffffL
#define PP_ROT_MATRIX0__M10_MASK                           0xffff0000L

// PP_ROT_MATRIX1
#define PP_ROT_MATRIX1__M01_MASK                           0x0000ffffL
#define PP_ROT_MATRIX1__M11_MASK                           0xffff0000L

// PP_TRI_PERF
#define PP_TRI_PERF__TRI_JUICE_MASK                        0x0000001fL

// PP_PERF_CNTL
#define PP_PERF_CNTL__RR_FIFO_SCALE_MASK                   0x00000003L
#define PP_PERF_CNTL__REQUEST_SCALE_MASK                   0x00000004L
#define PP_PERF_CNTL__REQUEST_SCALE                        0x00000004L
#define PP_PERF_CNTL__PP_COUNT_CTL_MASK                    0x00000030L

// PP_TXOFFSET_0
#define PP_TXOFFSET_0__ENDIAN_SWAP_MASK                    0x00000003L
#define PP_TXOFFSET_0__MACRO_TILE_MASK                     0x00000004L
#define PP_TXOFFSET_0__MACRO_TILE                          0x00000004L
#define PP_TXOFFSET_0__MICRO_TILE_MASK                     0x00000018L
#define PP_TXOFFSET_0__TXOFFSET_MASK                       0xffffffe0L

// PP_TXOFFSET_1
#define PP_TXOFFSET_1__ENDIAN_SWAP_MASK                    0x00000003L
#define PP_TXOFFSET_1__MACRO_TILE_MASK                     0x00000004L
#define PP_TXOFFSET_1__MACRO_TILE                          0x00000004L
#define PP_TXOFFSET_1__MICRO_TILE_MASK                     0x00000018L
#define PP_TXOFFSET_1__TXOFFSET_MASK                       0xffffffe0L

// PP_TXOFFSET_2
#define PP_TXOFFSET_2__ENDIAN_SWAP_MASK                    0x00000003L
#define PP_TXOFFSET_2__MACRO_TILE_MASK                     0x00000004L
#define PP_TXOFFSET_2__MACRO_TILE                          0x00000004L
#define PP_TXOFFSET_2__MICRO_TILE_MASK                     0x00000018L
#define PP_TXOFFSET_2__TXOFFSET_MASK                       0xffffffe0L

// PP_TXOFFSET_3
#define PP_TXOFFSET_3__ENDIAN_SWAP_MASK                    0x00000003L
#define PP_TXOFFSET_3__MACRO_TILE_MASK                     0x00000004L
#define PP_TXOFFSET_3__MACRO_TILE                          0x00000004L
#define PP_TXOFFSET_3__MICRO_TILE_MASK                     0x00000018L
#define PP_TXOFFSET_3__TXOFFSET_MASK                       0xffffffe0L

// PP_TXOFFSET_4
#define PP_TXOFFSET_4__ENDIAN_SWAP_MASK                    0x00000003L
#define PP_TXOFFSET_4__MACRO_TILE_MASK                     0x00000004L
#define PP_TXOFFSET_4__MACRO_TILE                          0x00000004L
#define PP_TXOFFSET_4__MICRO_TILE_MASK                     0x00000018L
#define PP_TXOFFSET_4__TXOFFSET_MASK                       0xffffffe0L

// PP_TXOFFSET_5
#define PP_TXOFFSET_5__ENDIAN_SWAP_MASK                    0x00000003L
#define PP_TXOFFSET_5__MACRO_TILE_MASK                     0x00000004L
#define PP_TXOFFSET_5__MACRO_TILE                          0x00000004L
#define PP_TXOFFSET_5__MICRO_TILE_MASK                     0x00000018L
#define PP_TXOFFSET_5__TXOFFSET_MASK                       0xffffffe0L

// PP_CUBIC_OFFSET_F1_0
#define PP_CUBIC_OFFSET_F1_0__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F1_0__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F1_0__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F1_0__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F1_0__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F1_1
#define PP_CUBIC_OFFSET_F1_1__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F1_1__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F1_1__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F1_1__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F1_1__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F1_2
#define PP_CUBIC_OFFSET_F1_2__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F1_2__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F1_2__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F1_2__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F1_2__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F1_3
#define PP_CUBIC_OFFSET_F1_3__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F1_3__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F1_3__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F1_3__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F1_3__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F1_4
#define PP_CUBIC_OFFSET_F1_4__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F1_4__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F1_4__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F1_4__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F1_4__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F1_5
#define PP_CUBIC_OFFSET_F1_5__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F1_5__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F1_5__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F1_5__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F1_5__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F2_0
#define PP_CUBIC_OFFSET_F2_0__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F2_0__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F2_0__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F2_0__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F2_0__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F2_1
#define PP_CUBIC_OFFSET_F2_1__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F2_1__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F2_1__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F2_1__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F2_1__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F2_2
#define PP_CUBIC_OFFSET_F2_2__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F2_2__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F2_2__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F2_2__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F2_2__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F2_3
#define PP_CUBIC_OFFSET_F2_3__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F2_3__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F2_3__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F2_3__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F2_3__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F2_4
#define PP_CUBIC_OFFSET_F2_4__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F2_4__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F2_4__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F2_4__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F2_4__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F2_5
#define PP_CUBIC_OFFSET_F2_5__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F2_5__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F2_5__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F2_5__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F2_5__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F3_0
#define PP_CUBIC_OFFSET_F3_0__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F3_0__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F3_0__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F3_0__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F3_0__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F3_1
#define PP_CUBIC_OFFSET_F3_1__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F3_1__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F3_1__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F3_1__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F3_1__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F3_2
#define PP_CUBIC_OFFSET_F3_2__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F3_2__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F3_2__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F3_2__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F3_2__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F3_3
#define PP_CUBIC_OFFSET_F3_3__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F3_3__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F3_3__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F3_3__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F3_3__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F3_4
#define PP_CUBIC_OFFSET_F3_4__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F3_4__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F3_4__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F3_4__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F3_4__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F3_5
#define PP_CUBIC_OFFSET_F3_5__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F3_5__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F3_5__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F3_5__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F3_5__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F4_0
#define PP_CUBIC_OFFSET_F4_0__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F4_0__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F4_0__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F4_0__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F4_0__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F4_1
#define PP_CUBIC_OFFSET_F4_1__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F4_1__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F4_1__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F4_1__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F4_1__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F4_2
#define PP_CUBIC_OFFSET_F4_2__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F4_2__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F4_2__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F4_2__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F4_2__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F4_3
#define PP_CUBIC_OFFSET_F4_3__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F4_3__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F4_3__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F4_3__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F4_3__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F4_4
#define PP_CUBIC_OFFSET_F4_4__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F4_4__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F4_4__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F4_4__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F4_4__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F4_5
#define PP_CUBIC_OFFSET_F4_5__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F4_5__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F4_5__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F4_5__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F4_5__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F5_0
#define PP_CUBIC_OFFSET_F5_0__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F5_0__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F5_0__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F5_0__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F5_0__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F5_1
#define PP_CUBIC_OFFSET_F5_1__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F5_1__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F5_1__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F5_1__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F5_1__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F5_2
#define PP_CUBIC_OFFSET_F5_2__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F5_2__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F5_2__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F5_2__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F5_2__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F5_3
#define PP_CUBIC_OFFSET_F5_3__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F5_3__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F5_3__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F5_3__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F5_3__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F5_4
#define PP_CUBIC_OFFSET_F5_4__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F5_4__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F5_4__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F5_4__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F5_4__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_F5_5
#define PP_CUBIC_OFFSET_F5_5__ENDIAN_SWAP_MASK             0x00000003L
#define PP_CUBIC_OFFSET_F5_5__MACRO_TILE_MASK              0x00000004L
#define PP_CUBIC_OFFSET_F5_5__MACRO_TILE                   0x00000004L
#define PP_CUBIC_OFFSET_F5_5__MICRO_TILE_MASK              0x00000018L
#define PP_CUBIC_OFFSET_F5_5__FACE_OFFSET_MASK             0xffffffe0L

// PP_TAM_DEBUG0
#define PP_TAM_DEBUG0__TAM_DWORD_MASK                      0xffffffffL

// PP_TAM_DEBUG1
#define PP_TAM_DEBUG1__TAM_DWORD_MASK                      0xffffffffL

// PP_TAM_DEBUG2
#define PP_TAM_DEBUG2__TAM_DWORD_MASK                      0xffffffffL

// PP_TDM_DEBUG0
#define PP_TDM_DEBUG0__TDM_DWORD_MASK                      0xffffffffL

// PP_TDM_DEBUG1
#define PP_TDM_DEBUG1__TDM_DWORD_MASK                      0xffffffffL

// PP_TDM_DEBUG2
#define PP_TDM_DEBUG2__TDM_DWORD_MASK                      0xffffffffL

// PP_PB_DEBUG0
#define PP_PB_DEBUG0__PB_DWORD_MASK                        0xffffffffL

// PP_PB_DEBUG1
#define PP_PB_DEBUG1__PB_DWORD_MASK                        0xffffffffL

// PP_PB_DEBUG2
#define PP_PB_DEBUG2__PB_DWORD_MASK                        0xffffffffL

// PP_TAM_DEBUG3
#define PP_TAM_DEBUG3__TAM_DWORD_MASK                      0xffffffffL

// PP_TDM_DEBUG3
#define PP_TDM_DEBUG3__TDM_DWORD_MASK                      0xffffffffL

// PP_PB_DEBUG3
#define PP_PB_DEBUG3__PB_DWORD_MASK                        0xffffffffL

// PP_SRC_OFFSET_0
#define PP_SRC_OFFSET_0__MC_OFFSET_MASK                    0x01ffffe0L

// PP_SRC_OFFSET_1
#define PP_SRC_OFFSET_1__MC_OFFSET_MASK                    0x01ffffe0L

// PP_SRC_OFFSET_2
#define PP_SRC_OFFSET_2__MC_OFFSET_MASK                    0x01ffffe0L

// PP_SRC_OFFSET_3
#define PP_SRC_OFFSET_3__MC_OFFSET_MASK                    0x01ffffe0L

// PP_SRC_OFFSET_4
#define PP_SRC_OFFSET_4__MC_OFFSET_MASK                    0x01ffffe0L

// PP_SRC_OFFSET_5
#define PP_SRC_OFFSET_5__MC_OFFSET_MASK                    0x01ffffe0L

// PP_SRC_OFFSET_6
#define PP_SRC_OFFSET_6__MC_OFFSET_MASK                    0x01ffffe0L

// PP_SRC_OFFSET_7
#define PP_SRC_OFFSET_7__MC_OFFSET_MASK                    0x01ffffe0L

// PP_SRC_OFFSET_8
#define PP_SRC_OFFSET_8__MC_OFFSET_MASK                    0x01ffffe0L

// PP_SRC_OFFSET_9
#define PP_SRC_OFFSET_9__MC_OFFSET_MASK                    0x01ffffe0L

// PP_SRC_OFFSET_10
#define PP_SRC_OFFSET_10__MC_OFFSET_MASK                   0x01ffffe0L

// PP_SRC_OFFSET_11
#define PP_SRC_OFFSET_11__MC_OFFSET_MASK                   0x01ffffe0L

// PP_SRC_OFFSET_12
#define PP_SRC_OFFSET_12__MC_OFFSET_MASK                   0x01ffffe0L

// PP_SRC_OFFSET_13
#define PP_SRC_OFFSET_13__MC_OFFSET_MASK                   0x01ffffe0L

// PP_SRC_OFFSET_14
#define PP_SRC_OFFSET_14__MC_OFFSET_MASK                   0x01ffffe0L

// PP_SRC_OFFSET_15
#define PP_SRC_OFFSET_15__MC_OFFSET_MASK                   0x01ffffe0L

// PP_SRC_OFFSET_16
#define PP_SRC_OFFSET_16__MC_OFFSET_MASK                   0x01ffffe0L

// PP_SRC_OFFSET_17
#define PP_SRC_OFFSET_17__MC_OFFSET_MASK                   0x01ffffe0L

// PP_TFACTOR_SIGN
#define PP_TFACTOR_SIGN__SGN_TF0_B_MASK                    0x00000001L
#define PP_TFACTOR_SIGN__SGN_TF0_B                         0x00000001L
#define PP_TFACTOR_SIGN__SGN_TF0_G_MASK                    0x00000002L
#define PP_TFACTOR_SIGN__SGN_TF0_G                         0x00000002L
#define PP_TFACTOR_SIGN__SGN_TF0_R_MASK                    0x00000004L
#define PP_TFACTOR_SIGN__SGN_TF0_R                         0x00000004L
#define PP_TFACTOR_SIGN__SGN_TF0_A_MASK                    0x00000008L
#define PP_TFACTOR_SIGN__SGN_TF0_A                         0x00000008L
#define PP_TFACTOR_SIGN__SGN_TF1_B_MASK                    0x00000010L
#define PP_TFACTOR_SIGN__SGN_TF1_B                         0x00000010L
#define PP_TFACTOR_SIGN__SGN_TF1_G_MASK                    0x00000020L
#define PP_TFACTOR_SIGN__SGN_TF1_G                         0x00000020L
#define PP_TFACTOR_SIGN__SGN_TF1_R_MASK                    0x00000040L
#define PP_TFACTOR_SIGN__SGN_TF1_R                         0x00000040L
#define PP_TFACTOR_SIGN__SGN_TF1_A_MASK                    0x00000080L
#define PP_TFACTOR_SIGN__SGN_TF1_A                         0x00000080L
#define PP_TFACTOR_SIGN__SGN_TF2_B_MASK                    0x00000100L
#define PP_TFACTOR_SIGN__SGN_TF2_B                         0x00000100L
#define PP_TFACTOR_SIGN__SGN_TF2_G_MASK                    0x00000200L
#define PP_TFACTOR_SIGN__SGN_TF2_G                         0x00000200L
#define PP_TFACTOR_SIGN__SGN_TF2_R_MASK                    0x00000400L
#define PP_TFACTOR_SIGN__SGN_TF2_R                         0x00000400L
#define PP_TFACTOR_SIGN__SGN_TF2_A_MASK                    0x00000800L
#define PP_TFACTOR_SIGN__SGN_TF2_A                         0x00000800L
#define PP_TFACTOR_SIGN__SGN_TF3_B_MASK                    0x00001000L
#define PP_TFACTOR_SIGN__SGN_TF3_B                         0x00001000L
#define PP_TFACTOR_SIGN__SGN_TF3_G_MASK                    0x00002000L
#define PP_TFACTOR_SIGN__SGN_TF3_G                         0x00002000L
#define PP_TFACTOR_SIGN__SGN_TF3_R_MASK                    0x00004000L
#define PP_TFACTOR_SIGN__SGN_TF3_R                         0x00004000L
#define PP_TFACTOR_SIGN__SGN_TF3_A_MASK                    0x00008000L
#define PP_TFACTOR_SIGN__SGN_TF3_A                         0x00008000L
#define PP_TFACTOR_SIGN__SGN_TF4_B_MASK                    0x00010000L
#define PP_TFACTOR_SIGN__SGN_TF4_B                         0x00010000L
#define PP_TFACTOR_SIGN__SGN_TF4_G_MASK                    0x00020000L
#define PP_TFACTOR_SIGN__SGN_TF4_G                         0x00020000L
#define PP_TFACTOR_SIGN__SGN_TF4_R_MASK                    0x00040000L
#define PP_TFACTOR_SIGN__SGN_TF4_R                         0x00040000L
#define PP_TFACTOR_SIGN__SGN_TF4_A_MASK                    0x00080000L
#define PP_TFACTOR_SIGN__SGN_TF4_A                         0x00080000L
#define PP_TFACTOR_SIGN__SGN_TF5_B_MASK                    0x00100000L
#define PP_TFACTOR_SIGN__SGN_TF5_B                         0x00100000L
#define PP_TFACTOR_SIGN__SGN_TF5_G_MASK                    0x00200000L
#define PP_TFACTOR_SIGN__SGN_TF5_G                         0x00200000L
#define PP_TFACTOR_SIGN__SGN_TF5_R_MASK                    0x00400000L
#define PP_TFACTOR_SIGN__SGN_TF5_R                         0x00400000L
#define PP_TFACTOR_SIGN__SGN_TF5_A_MASK                    0x00800000L
#define PP_TFACTOR_SIGN__SGN_TF5_A                         0x00800000L
#define PP_TFACTOR_SIGN__SGN_TF6_B_MASK                    0x01000000L
#define PP_TFACTOR_SIGN__SGN_TF6_B                         0x01000000L
#define PP_TFACTOR_SIGN__SGN_TF6_G_MASK                    0x02000000L
#define PP_TFACTOR_SIGN__SGN_TF6_G                         0x02000000L
#define PP_TFACTOR_SIGN__SGN_TF6_R_MASK                    0x04000000L
#define PP_TFACTOR_SIGN__SGN_TF6_R                         0x04000000L
#define PP_TFACTOR_SIGN__SGN_TF6_A_MASK                    0x08000000L
#define PP_TFACTOR_SIGN__SGN_TF6_A                         0x08000000L
#define PP_TFACTOR_SIGN__SGN_TF7_B_MASK                    0x10000000L
#define PP_TFACTOR_SIGN__SGN_TF7_B                         0x10000000L
#define PP_TFACTOR_SIGN__SGN_TF7_G_MASK                    0x20000000L
#define PP_TFACTOR_SIGN__SGN_TF7_G                         0x20000000L
#define PP_TFACTOR_SIGN__SGN_TF7_R_MASK                    0x40000000L
#define PP_TFACTOR_SIGN__SGN_TF7_R                         0x40000000L
#define PP_TFACTOR_SIGN__SGN_TF7_A_MASK                    0x80000000L
#define PP_TFACTOR_SIGN__SGN_TF7_A                         0x80000000L

// PP_TFACTOR_0
#define PP_TFACTOR_0__TFACTOR_MASK                         0xffffffffL

// PP_TFACTOR_1
#define PP_TFACTOR_1__TFACTOR_MASK                         0xffffffffL

// PP_TFACTOR_2
#define PP_TFACTOR_2__TFACTOR_MASK                         0xffffffffL

// PP_TFACTOR_3
#define PP_TFACTOR_3__TFACTOR_MASK                         0xffffffffL

// PP_TFACTOR_4
#define PP_TFACTOR_4__TFACTOR_MASK                         0xffffffffL

// PP_TFACTOR_5
#define PP_TFACTOR_5__TFACTOR_MASK                         0xffffffffL

// PP_TFACTOR_6
#define PP_TFACTOR_6__TFACTOR_MASK                         0xffffffffL

// PP_TFACTOR_7
#define PP_TFACTOR_7__TFACTOR_MASK                         0xffffffffL

// PP_PIXSHADER_I0_C0
#define PP_PIXSHADER_I0_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I0_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I0_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I0_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I0_C0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I0_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I0_C0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I0_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I0_C0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I0_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I0_C0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I0_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I0_C0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I0_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I0_C0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I0_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I0_C0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I0_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I0_C0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I0_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I0_C0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I0_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I0_C0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I0_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I0_C0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I0_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I0_C0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I0_C0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I1_C0
#define PP_PIXSHADER_I1_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I1_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I1_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I1_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I1_C0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I1_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I1_C0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I1_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I1_C0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I1_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I1_C0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I1_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I1_C0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I1_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I1_C0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I1_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I1_C0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I1_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I1_C0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I1_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I1_C0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I1_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I1_C0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I1_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I1_C0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I1_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I1_C0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I1_C0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I2_C0
#define PP_PIXSHADER_I2_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I2_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I2_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I2_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I2_C0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I2_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I2_C0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I2_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I2_C0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I2_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I2_C0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I2_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I2_C0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I2_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I2_C0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I2_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I2_C0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I2_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I2_C0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I2_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I2_C0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I2_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I2_C0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I2_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I2_C0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I2_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I2_C0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I2_C0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I3_C0
#define PP_PIXSHADER_I3_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I3_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I3_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I3_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I3_C0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I3_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I3_C0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I3_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I3_C0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I3_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I3_C0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I3_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I3_C0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I3_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I3_C0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I3_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I3_C0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I3_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I3_C0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I3_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I3_C0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I3_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I3_C0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I3_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I3_C0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I3_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I3_C0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I3_C0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I4_C0
#define PP_PIXSHADER_I4_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I4_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I4_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I4_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I4_C0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I4_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I4_C0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I4_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I4_C0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I4_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I4_C0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I4_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I4_C0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I4_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I4_C0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I4_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I4_C0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I4_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I4_C0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I4_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I4_C0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I4_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I4_C0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I4_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I4_C0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I4_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I4_C0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I4_C0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I5_C0
#define PP_PIXSHADER_I5_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I5_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I5_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I5_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I5_C0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I5_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I5_C0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I5_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I5_C0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I5_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I5_C0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I5_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I5_C0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I5_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I5_C0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I5_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I5_C0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I5_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I5_C0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I5_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I5_C0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I5_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I5_C0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I5_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I5_C0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I5_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I5_C0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I5_C0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I6_C0
#define PP_PIXSHADER_I6_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I6_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I6_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I6_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I6_C0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I6_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I6_C0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I6_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I6_C0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I6_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I6_C0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I6_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I6_C0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I6_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I6_C0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I6_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I6_C0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I6_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I6_C0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I6_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I6_C0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I6_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I6_C0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I6_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I6_C0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I6_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I6_C0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I6_C0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I7_C0
#define PP_PIXSHADER_I7_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I7_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I7_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I7_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I7_C0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I7_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I7_C0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I7_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I7_C0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I7_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I7_C0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I7_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I7_C0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I7_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I7_C0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I7_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I7_C0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I7_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I7_C0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I7_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I7_C0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I7_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I7_C0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I7_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I7_C0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I7_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I7_C0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I7_C0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I0_C1
#define PP_PIXSHADER_I0_C1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I0_C1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I0_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I0_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I0_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I0_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_PIXSHADER_I0_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_PIXSHADER_I0_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I0_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I0_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_PIXSHADER_I1_C1
#define PP_PIXSHADER_I1_C1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I1_C1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I1_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I1_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I1_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I1_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_PIXSHADER_I1_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_PIXSHADER_I1_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I1_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I1_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_PIXSHADER_I2_C1
#define PP_PIXSHADER_I2_C1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I2_C1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I2_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I2_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I2_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I2_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_PIXSHADER_I2_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_PIXSHADER_I2_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I2_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I2_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_PIXSHADER_I3_C1
#define PP_PIXSHADER_I3_C1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I3_C1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I3_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I3_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I3_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I3_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_PIXSHADER_I3_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_PIXSHADER_I3_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I3_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I3_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_PIXSHADER_I4_C1
#define PP_PIXSHADER_I4_C1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I4_C1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I4_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I4_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I4_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I4_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_PIXSHADER_I4_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_PIXSHADER_I4_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I4_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I4_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_PIXSHADER_I5_C1
#define PP_PIXSHADER_I5_C1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I5_C1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I5_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I5_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I5_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I5_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_PIXSHADER_I5_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_PIXSHADER_I5_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I5_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I5_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_PIXSHADER_I6_C1
#define PP_PIXSHADER_I6_C1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I6_C1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I6_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I6_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I6_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I6_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_PIXSHADER_I6_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_PIXSHADER_I6_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I6_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I6_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_PIXSHADER_I7_C1
#define PP_PIXSHADER_I7_C1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I7_C1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I7_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I7_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I7_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I7_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_PIXSHADER_I7_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_PIXSHADER_I7_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I7_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I7_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_PIXSHADER_I0_A0
#define PP_PIXSHADER_I0_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I0_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I0_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I0_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I0_A0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I0_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I0_A0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I0_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I0_A0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I0_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I0_A0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I0_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I0_A0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I0_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I0_A0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I0_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I0_A0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I0_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I0_A0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I0_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I0_A0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I0_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I0_A0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I0_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I0_A0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I0_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I0_A0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I0_A0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I1_A0
#define PP_PIXSHADER_I1_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I1_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I1_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I1_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I1_A0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I1_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I1_A0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I1_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I1_A0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I1_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I1_A0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I1_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I1_A0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I1_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I1_A0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I1_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I1_A0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I1_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I1_A0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I1_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I1_A0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I1_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I1_A0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I1_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I1_A0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I1_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I1_A0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I1_A0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I2_A0
#define PP_PIXSHADER_I2_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I2_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I2_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I2_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I2_A0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I2_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I2_A0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I2_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I2_A0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I2_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I2_A0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I2_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I2_A0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I2_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I2_A0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I2_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I2_A0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I2_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I2_A0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I2_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I2_A0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I2_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I2_A0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I2_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I2_A0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I2_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I2_A0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I2_A0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I3_A0
#define PP_PIXSHADER_I3_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I3_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I3_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I3_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I3_A0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I3_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I3_A0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I3_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I3_A0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I3_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I3_A0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I3_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I3_A0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I3_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I3_A0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I3_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I3_A0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I3_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I3_A0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I3_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I3_A0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I3_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I3_A0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I3_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I3_A0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I3_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I3_A0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I3_A0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I4_A0
#define PP_PIXSHADER_I4_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I4_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I4_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I4_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I4_A0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I4_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I4_A0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I4_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I4_A0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I4_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I4_A0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I4_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I4_A0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I4_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I4_A0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I4_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I4_A0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I4_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I4_A0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I4_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I4_A0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I4_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I4_A0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I4_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I4_A0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I4_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I4_A0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I4_A0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I5_A0
#define PP_PIXSHADER_I5_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I5_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I5_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I5_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I5_A0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I5_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I5_A0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I5_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I5_A0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I5_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I5_A0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I5_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I5_A0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I5_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I5_A0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I5_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I5_A0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I5_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I5_A0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I5_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I5_A0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I5_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I5_A0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I5_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I5_A0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I5_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I5_A0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I5_A0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I6_A0
#define PP_PIXSHADER_I6_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I6_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I6_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I6_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I6_A0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I6_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I6_A0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I6_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I6_A0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I6_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I6_A0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I6_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I6_A0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I6_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I6_A0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I6_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I6_A0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I6_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I6_A0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I6_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I6_A0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I6_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I6_A0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I6_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I6_A0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I6_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I6_A0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I6_A0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I7_A0
#define PP_PIXSHADER_I7_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_PIXSHADER_I7_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_PIXSHADER_I7_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_PIXSHADER_I7_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_PIXSHADER_I7_A0__COMP_ARG_A                     0x00010000L
#define PP_PIXSHADER_I7_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_PIXSHADER_I7_A0__BIAS_ARG_A                     0x00020000L
#define PP_PIXSHADER_I7_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_PIXSHADER_I7_A0__SCALE_ARG_A                    0x00040000L
#define PP_PIXSHADER_I7_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_PIXSHADER_I7_A0__NEG_ARG_A                      0x00080000L
#define PP_PIXSHADER_I7_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_PIXSHADER_I7_A0__COMP_ARG_B                     0x00100000L
#define PP_PIXSHADER_I7_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_PIXSHADER_I7_A0__BIAS_ARG_B                     0x00200000L
#define PP_PIXSHADER_I7_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_PIXSHADER_I7_A0__SCALE_ARG_B                    0x00400000L
#define PP_PIXSHADER_I7_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_PIXSHADER_I7_A0__NEG_ARG_B                      0x00800000L
#define PP_PIXSHADER_I7_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_PIXSHADER_I7_A0__COMP_ARG_C                     0x01000000L
#define PP_PIXSHADER_I7_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_PIXSHADER_I7_A0__BIAS_ARG_C                     0x02000000L
#define PP_PIXSHADER_I7_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_PIXSHADER_I7_A0__SCALE_ARG_C                    0x04000000L
#define PP_PIXSHADER_I7_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_PIXSHADER_I7_A0__NEG_ARG_C                      0x08000000L
#define PP_PIXSHADER_I7_A0__BLEND_CTL_MASK                 0x70000000L

// PP_PIXSHADER_I0_A1
#define PP_PIXSHADER_I0_A1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I0_A1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I0_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I0_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I0_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I0_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_PIXSHADER_I0_A1__DOT_ALPHA                      0x00100000L
#define PP_PIXSHADER_I0_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I0_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I0_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_PIXSHADER_I1_A1
#define PP_PIXSHADER_I1_A1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I1_A1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I1_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I1_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I1_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I1_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_PIXSHADER_I1_A1__DOT_ALPHA                      0x00100000L
#define PP_PIXSHADER_I1_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I1_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I1_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_PIXSHADER_I2_A1
#define PP_PIXSHADER_I2_A1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I2_A1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I2_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I2_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I2_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I2_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_PIXSHADER_I2_A1__DOT_ALPHA                      0x00100000L
#define PP_PIXSHADER_I2_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I2_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I2_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_PIXSHADER_I3_A1
#define PP_PIXSHADER_I3_A1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I3_A1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I3_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I3_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I3_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I3_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_PIXSHADER_I3_A1__DOT_ALPHA                      0x00100000L
#define PP_PIXSHADER_I3_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I3_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I3_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_PIXSHADER_I4_A1
#define PP_PIXSHADER_I4_A1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I4_A1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I4_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I4_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I4_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I4_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_PIXSHADER_I4_A1__DOT_ALPHA                      0x00100000L
#define PP_PIXSHADER_I4_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I4_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I4_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_PIXSHADER_I5_A1
#define PP_PIXSHADER_I5_A1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I5_A1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I5_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I5_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I5_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I5_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_PIXSHADER_I5_A1__DOT_ALPHA                      0x00100000L
#define PP_PIXSHADER_I5_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I5_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I5_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_PIXSHADER_I6_A1
#define PP_PIXSHADER_I6_A1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I6_A1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I6_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I6_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I6_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I6_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_PIXSHADER_I6_A1__DOT_ALPHA                      0x00100000L
#define PP_PIXSHADER_I6_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I6_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I6_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_PIXSHADER_I7_A1
#define PP_PIXSHADER_I7_A1__F0_SEL_MASK                    0x00000007L
#define PP_PIXSHADER_I7_A1__F1_SEL_MASK                    0x00000070L
#define PP_PIXSHADER_I7_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_PIXSHADER_I7_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_PIXSHADER_I7_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_PIXSHADER_I7_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_PIXSHADER_I7_A1__DOT_ALPHA                      0x00100000L
#define PP_PIXSHADER_I7_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_PIXSHADER_I7_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_PIXSHADER_I7_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I0_C0
#define PP_ADRSHADER_I0_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I0_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I0_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I0_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I0_C0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I0_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I0_C0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I0_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I0_C0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I0_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I0_C0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I0_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I0_C0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I0_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I0_C0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I0_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I0_C0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I0_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I0_C0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I0_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I0_C0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I0_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I0_C0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I0_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I0_C0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I0_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I0_C0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I0_C0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I1_C0
#define PP_ADRSHADER_I1_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I1_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I1_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I1_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I1_C0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I1_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I1_C0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I1_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I1_C0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I1_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I1_C0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I1_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I1_C0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I1_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I1_C0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I1_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I1_C0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I1_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I1_C0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I1_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I1_C0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I1_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I1_C0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I1_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I1_C0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I1_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I1_C0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I1_C0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I2_C0
#define PP_ADRSHADER_I2_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I2_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I2_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I2_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I2_C0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I2_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I2_C0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I2_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I2_C0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I2_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I2_C0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I2_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I2_C0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I2_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I2_C0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I2_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I2_C0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I2_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I2_C0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I2_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I2_C0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I2_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I2_C0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I2_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I2_C0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I2_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I2_C0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I2_C0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I3_C0
#define PP_ADRSHADER_I3_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I3_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I3_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I3_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I3_C0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I3_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I3_C0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I3_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I3_C0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I3_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I3_C0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I3_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I3_C0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I3_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I3_C0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I3_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I3_C0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I3_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I3_C0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I3_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I3_C0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I3_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I3_C0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I3_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I3_C0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I3_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I3_C0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I3_C0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I4_C0
#define PP_ADRSHADER_I4_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I4_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I4_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I4_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I4_C0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I4_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I4_C0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I4_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I4_C0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I4_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I4_C0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I4_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I4_C0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I4_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I4_C0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I4_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I4_C0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I4_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I4_C0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I4_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I4_C0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I4_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I4_C0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I4_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I4_C0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I4_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I4_C0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I4_C0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I5_C0
#define PP_ADRSHADER_I5_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I5_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I5_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I5_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I5_C0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I5_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I5_C0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I5_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I5_C0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I5_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I5_C0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I5_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I5_C0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I5_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I5_C0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I5_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I5_C0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I5_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I5_C0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I5_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I5_C0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I5_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I5_C0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I5_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I5_C0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I5_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I5_C0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I5_C0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I6_C0
#define PP_ADRSHADER_I6_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I6_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I6_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I6_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I6_C0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I6_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I6_C0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I6_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I6_C0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I6_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I6_C0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I6_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I6_C0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I6_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I6_C0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I6_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I6_C0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I6_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I6_C0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I6_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I6_C0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I6_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I6_C0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I6_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I6_C0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I6_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I6_C0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I6_C0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I7_C0
#define PP_ADRSHADER_I7_C0__COLOR_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I7_C0__COLOR_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I7_C0__COLOR_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I7_C0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I7_C0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I7_C0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I7_C0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I7_C0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I7_C0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I7_C0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I7_C0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I7_C0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I7_C0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I7_C0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I7_C0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I7_C0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I7_C0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I7_C0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I7_C0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I7_C0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I7_C0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I7_C0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I7_C0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I7_C0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I7_C0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I7_C0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I7_C0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I7_C0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I0_C1
#define PP_ADRSHADER_I0_C1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I0_C1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I0_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I0_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I0_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I0_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_ADRSHADER_I0_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_ADRSHADER_I0_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I0_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I0_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I1_C1
#define PP_ADRSHADER_I1_C1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I1_C1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I1_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I1_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I1_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I1_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_ADRSHADER_I1_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_ADRSHADER_I1_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I1_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I1_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I2_C1
#define PP_ADRSHADER_I2_C1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I2_C1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I2_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I2_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I2_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I2_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_ADRSHADER_I2_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_ADRSHADER_I2_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I2_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I2_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I3_C1
#define PP_ADRSHADER_I3_C1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I3_C1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I3_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I3_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I3_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I3_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_ADRSHADER_I3_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_ADRSHADER_I3_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I3_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I3_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I4_C1
#define PP_ADRSHADER_I4_C1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I4_C1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I4_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I4_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I4_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I4_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_ADRSHADER_I4_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_ADRSHADER_I4_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I4_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I4_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I5_C1
#define PP_ADRSHADER_I5_C1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I5_C1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I5_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I5_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I5_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I5_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_ADRSHADER_I5_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_ADRSHADER_I5_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I5_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I5_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I6_C1
#define PP_ADRSHADER_I6_C1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I6_C1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I6_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I6_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I6_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I6_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_ADRSHADER_I6_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_ADRSHADER_I6_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I6_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I6_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I7_C1
#define PP_ADRSHADER_I7_C1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I7_C1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I7_C1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I7_C1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I7_C1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I7_C1__OUTPUT_MASK_MASK               0x00700000L
#define PP_ADRSHADER_I7_C1__OUTPUT_ROTATE_MASK             0x03000000L
#define PP_ADRSHADER_I7_C1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I7_C1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I7_C1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I0_A0
#define PP_ADRSHADER_I0_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I0_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I0_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I0_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I0_A0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I0_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I0_A0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I0_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I0_A0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I0_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I0_A0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I0_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I0_A0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I0_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I0_A0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I0_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I0_A0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I0_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I0_A0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I0_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I0_A0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I0_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I0_A0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I0_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I0_A0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I0_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I0_A0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I0_A0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I1_A0
#define PP_ADRSHADER_I1_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I1_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I1_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I1_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I1_A0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I1_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I1_A0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I1_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I1_A0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I1_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I1_A0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I1_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I1_A0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I1_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I1_A0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I1_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I1_A0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I1_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I1_A0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I1_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I1_A0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I1_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I1_A0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I1_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I1_A0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I1_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I1_A0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I1_A0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I2_A0
#define PP_ADRSHADER_I2_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I2_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I2_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I2_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I2_A0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I2_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I2_A0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I2_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I2_A0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I2_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I2_A0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I2_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I2_A0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I2_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I2_A0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I2_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I2_A0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I2_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I2_A0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I2_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I2_A0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I2_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I2_A0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I2_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I2_A0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I2_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I2_A0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I2_A0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I3_A0
#define PP_ADRSHADER_I3_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I3_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I3_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I3_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I3_A0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I3_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I3_A0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I3_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I3_A0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I3_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I3_A0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I3_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I3_A0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I3_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I3_A0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I3_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I3_A0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I3_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I3_A0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I3_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I3_A0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I3_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I3_A0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I3_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I3_A0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I3_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I3_A0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I3_A0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I4_A0
#define PP_ADRSHADER_I4_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I4_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I4_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I4_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I4_A0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I4_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I4_A0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I4_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I4_A0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I4_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I4_A0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I4_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I4_A0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I4_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I4_A0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I4_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I4_A0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I4_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I4_A0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I4_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I4_A0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I4_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I4_A0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I4_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I4_A0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I4_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I4_A0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I4_A0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I5_A0
#define PP_ADRSHADER_I5_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I5_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I5_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I5_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I5_A0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I5_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I5_A0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I5_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I5_A0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I5_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I5_A0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I5_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I5_A0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I5_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I5_A0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I5_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I5_A0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I5_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I5_A0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I5_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I5_A0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I5_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I5_A0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I5_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I5_A0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I5_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I5_A0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I5_A0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I6_A0
#define PP_ADRSHADER_I6_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I6_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I6_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I6_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I6_A0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I6_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I6_A0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I6_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I6_A0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I6_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I6_A0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I6_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I6_A0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I6_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I6_A0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I6_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I6_A0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I6_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I6_A0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I6_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I6_A0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I6_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I6_A0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I6_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I6_A0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I6_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I6_A0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I6_A0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I7_A0
#define PP_ADRSHADER_I7_A0__ALPHA_ARG_A_MASK               0x0000001fL
#define PP_ADRSHADER_I7_A0__ALPHA_ARG_B_MASK               0x000003e0L
#define PP_ADRSHADER_I7_A0__ALPHA_ARG_C_MASK               0x00007c00L
#define PP_ADRSHADER_I7_A0__COMP_ARG_A_MASK                0x00010000L
#define PP_ADRSHADER_I7_A0__COMP_ARG_A                     0x00010000L
#define PP_ADRSHADER_I7_A0__BIAS_ARG_A_MASK                0x00020000L
#define PP_ADRSHADER_I7_A0__BIAS_ARG_A                     0x00020000L
#define PP_ADRSHADER_I7_A0__SCALE_ARG_A_MASK               0x00040000L
#define PP_ADRSHADER_I7_A0__SCALE_ARG_A                    0x00040000L
#define PP_ADRSHADER_I7_A0__NEG_ARG_A_MASK                 0x00080000L
#define PP_ADRSHADER_I7_A0__NEG_ARG_A                      0x00080000L
#define PP_ADRSHADER_I7_A0__COMP_ARG_B_MASK                0x00100000L
#define PP_ADRSHADER_I7_A0__COMP_ARG_B                     0x00100000L
#define PP_ADRSHADER_I7_A0__BIAS_ARG_B_MASK                0x00200000L
#define PP_ADRSHADER_I7_A0__BIAS_ARG_B                     0x00200000L
#define PP_ADRSHADER_I7_A0__SCALE_ARG_B_MASK               0x00400000L
#define PP_ADRSHADER_I7_A0__SCALE_ARG_B                    0x00400000L
#define PP_ADRSHADER_I7_A0__NEG_ARG_B_MASK                 0x00800000L
#define PP_ADRSHADER_I7_A0__NEG_ARG_B                      0x00800000L
#define PP_ADRSHADER_I7_A0__COMP_ARG_C_MASK                0x01000000L
#define PP_ADRSHADER_I7_A0__COMP_ARG_C                     0x01000000L
#define PP_ADRSHADER_I7_A0__BIAS_ARG_C_MASK                0x02000000L
#define PP_ADRSHADER_I7_A0__BIAS_ARG_C                     0x02000000L
#define PP_ADRSHADER_I7_A0__SCALE_ARG_C_MASK               0x04000000L
#define PP_ADRSHADER_I7_A0__SCALE_ARG_C                    0x04000000L
#define PP_ADRSHADER_I7_A0__NEG_ARG_C_MASK                 0x08000000L
#define PP_ADRSHADER_I7_A0__NEG_ARG_C                      0x08000000L
#define PP_ADRSHADER_I7_A0__BLEND_CTL_MASK                 0x70000000L

// PP_ADRSHADER_I0_A1
#define PP_ADRSHADER_I0_A1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I0_A1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I0_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I0_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I0_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I0_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_ADRSHADER_I0_A1__DOT_ALPHA                      0x00100000L
#define PP_ADRSHADER_I0_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I0_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I0_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I1_A1
#define PP_ADRSHADER_I1_A1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I1_A1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I1_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I1_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I1_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I1_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_ADRSHADER_I1_A1__DOT_ALPHA                      0x00100000L
#define PP_ADRSHADER_I1_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I1_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I1_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I2_A1
#define PP_ADRSHADER_I2_A1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I2_A1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I2_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I2_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I2_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I2_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_ADRSHADER_I2_A1__DOT_ALPHA                      0x00100000L
#define PP_ADRSHADER_I2_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I2_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I2_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I3_A1
#define PP_ADRSHADER_I3_A1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I3_A1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I3_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I3_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I3_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I3_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_ADRSHADER_I3_A1__DOT_ALPHA                      0x00100000L
#define PP_ADRSHADER_I3_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I3_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I3_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I4_A1
#define PP_ADRSHADER_I4_A1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I4_A1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I4_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I4_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I4_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I4_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_ADRSHADER_I4_A1__DOT_ALPHA                      0x00100000L
#define PP_ADRSHADER_I4_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I4_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I4_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I5_A1
#define PP_ADRSHADER_I5_A1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I5_A1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I5_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I5_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I5_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I5_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_ADRSHADER_I5_A1__DOT_ALPHA                      0x00100000L
#define PP_ADRSHADER_I5_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I5_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I5_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I6_A1
#define PP_ADRSHADER_I6_A1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I6_A1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I6_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I6_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I6_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I6_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_ADRSHADER_I6_A1__DOT_ALPHA                      0x00100000L
#define PP_ADRSHADER_I6_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I6_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I6_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// PP_ADRSHADER_I7_A1
#define PP_ADRSHADER_I7_A1__F0_SEL_MASK                    0x0000000fL
#define PP_ADRSHADER_I7_A1__F1_SEL_MASK                    0x000000f0L
#define PP_ADRSHADER_I7_A1__OUTPUT_SCALE_MASK              0x00000700L
#define PP_ADRSHADER_I7_A1__OUTPUT_CLAMP_MASK              0x00003000L
#define PP_ADRSHADER_I7_A1__OUTPUT_SELECT_MASK             0x00070000L
#define PP_ADRSHADER_I7_A1__DOT_ALPHA_MASK                 0x00100000L
#define PP_ADRSHADER_I7_A1__DOT_ALPHA                      0x00100000L
#define PP_ADRSHADER_I7_A1__REPLICATE_ARG_A_MASK           0x0c000000L
#define PP_ADRSHADER_I7_A1__REPLICATE_ARG_B_MASK           0x30000000L
#define PP_ADRSHADER_I7_A1__REPLICATE_ARG_C_MASK           0xc0000000L

// RB2D_ROP
#define RB2D_ROP__ROP_MASK                                 0x00ff0000L

// RB2D_CLRCMP_SRC
#define RB2D_CLRCMP_SRC__CLRCMP_SRC_MASK                   0xffffffffL

// RB2D_CLRCMP_DST
#define RB2D_CLRCMP_DST__CLRCMP_DST_MASK                   0xffffffffL

// RB2D_CLRCMP_FLIPE
#define RB2D_CLRCMP_FLIPE__CLRCMP_FLIPE_MASK               0xffffffffL

// RB2D_CLRCMP_CNTL
#define RB2D_CLRCMP_CNTL__FCN_SRC_MASK                     0x00000007L
#define RB2D_CLRCMP_CNTL__FCN_DST_MASK                     0x00000700L
#define RB2D_CLRCMP_CNTL__SRC_MASK                         0x03000000L

// RB2D_CLRCMP_MSK
#define RB2D_CLRCMP_MSK__CLRCMP_MSK_MASK                   0xffffffffL

// RB2D_WRITEMASK
#define RB2D_WRITEMASK__WRITEMASK_MASK                     0xffffffffL

// RB2D_DATATYPE
#define RB2D_DATATYPE__DP_DST_DATATYPE_MASK                0x0000000fL
#define RB2D_DATATYPE__DP_BRUSH_DATATYPE_MASK              0x00000f00L

// RB2D_GUI_MASTER_CNTL
#define RB2D_GUI_MASTER_CNTL__GMC_BRUSH_DATATYPE_MASK      0x000000f0L
#define RB2D_GUI_MASTER_CNTL__GMC_DST_DATATYPE_MASK        0x00000f00L
#define RB2D_GUI_MASTER_CNTL__GMC_ROP_MASK                 0x00ff0000L
#define RB2D_GUI_MASTER_CNTL__GMC_CLR_CMP_FCN_DIS_MASK     0x10000000L
#define RB2D_GUI_MASTER_CNTL__GMC_CLR_CMP_FCN_DIS          0x10000000L
#define RB2D_GUI_MASTER_CNTL__GMC_WR_MSK_DIS_MASK          0x40000000L
#define RB2D_GUI_MASTER_CNTL__GMC_WR_MSK_DIS               0x40000000L

// RB2D_BRUSHDATA_0
#define RB2D_BRUSHDATA_0__BRUSHDATA_MASK                   0xffffffffL

// RB2D_BRUSHDATA_1
#define RB2D_BRUSHDATA_1__BRUSHDATA_MASK                   0xffffffffL

// RB2D_BRUSHDATA_2
#define RB2D_BRUSHDATA_2__BRUSHDATA_MASK                   0xffffffffL
#define RB2D_BRUSH_FRGD_CLR__BRUSHDATA_MASK                0xffffffffL

// RB2D_BRUSHDATA_3
#define RB2D_BRUSHDATA_3__BRUSHDATA_MASK                   0xffffffffL
#define RB2D_BRUSH_BKGD_CLR__BRUSHDATA_MASK                0xffffffffL

// RB2D_BRUSHDATA_4
#define RB2D_BRUSHDATA_4__BRUSHDATA_MASK                   0xffffffffL

// RB2D_BRUSHDATA_5
#define RB2D_BRUSHDATA_5__BRUSHDATA_MASK                   0xffffffffL

// RB2D_BRUSHDATA_6
#define RB2D_BRUSHDATA_6__BRUSHDATA_MASK                   0xffffffffL

// RB2D_BRUSHDATA_7
#define RB2D_BRUSHDATA_7__BRUSHDATA_MASK                   0xffffffffL

// RB2D_BRUSHDATA_8
#define RB2D_BRUSHDATA_8__BRUSHDATA_MASK                   0xffffffffL

// RB2D_BRUSHDATA_9
#define RB2D_BRUSHDATA_9__BRUSHDATA_MASK                   0xffffffffL

// RB2D_BRUSHDATA_10
#define RB2D_BRUSHDATA_10__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_11
#define RB2D_BRUSHDATA_11__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_12
#define RB2D_BRUSHDATA_12__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_13
#define RB2D_BRUSHDATA_13__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_14
#define RB2D_BRUSHDATA_14__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_15
#define RB2D_BRUSHDATA_15__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_16
#define RB2D_BRUSHDATA_16__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_17
#define RB2D_BRUSHDATA_17__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_18
#define RB2D_BRUSHDATA_18__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_19
#define RB2D_BRUSHDATA_19__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_20
#define RB2D_BRUSHDATA_20__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_21
#define RB2D_BRUSHDATA_21__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_22
#define RB2D_BRUSHDATA_22__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_23
#define RB2D_BRUSHDATA_23__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_24
#define RB2D_BRUSHDATA_24__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_25
#define RB2D_BRUSHDATA_25__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_26
#define RB2D_BRUSHDATA_26__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_27
#define RB2D_BRUSHDATA_27__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_28
#define RB2D_BRUSHDATA_28__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_29
#define RB2D_BRUSHDATA_29__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_30
#define RB2D_BRUSHDATA_30__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_31
#define RB2D_BRUSHDATA_31__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_32
#define RB2D_BRUSHDATA_32__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_33
#define RB2D_BRUSHDATA_33__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_34
#define RB2D_BRUSHDATA_34__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_35
#define RB2D_BRUSHDATA_35__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_36
#define RB2D_BRUSHDATA_36__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_37
#define RB2D_BRUSHDATA_37__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_38
#define RB2D_BRUSHDATA_38__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_39
#define RB2D_BRUSHDATA_39__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_40
#define RB2D_BRUSHDATA_40__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_41
#define RB2D_BRUSHDATA_41__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_42
#define RB2D_BRUSHDATA_42__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_43
#define RB2D_BRUSHDATA_43__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_44
#define RB2D_BRUSHDATA_44__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_45
#define RB2D_BRUSHDATA_45__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_46
#define RB2D_BRUSHDATA_46__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_47
#define RB2D_BRUSHDATA_47__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_48
#define RB2D_BRUSHDATA_48__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_49
#define RB2D_BRUSHDATA_49__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_50
#define RB2D_BRUSHDATA_50__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_51
#define RB2D_BRUSHDATA_51__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_52
#define RB2D_BRUSHDATA_52__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_53
#define RB2D_BRUSHDATA_53__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_54
#define RB2D_BRUSHDATA_54__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_55
#define RB2D_BRUSHDATA_55__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_56
#define RB2D_BRUSHDATA_56__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_57
#define RB2D_BRUSHDATA_57__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_58
#define RB2D_BRUSHDATA_58__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_59
#define RB2D_BRUSHDATA_59__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_60
#define RB2D_BRUSHDATA_60__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_61
#define RB2D_BRUSHDATA_61__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_62
#define RB2D_BRUSHDATA_62__BRUSHDATA_MASK                  0xffffffffL

// RB2D_BRUSHDATA_63
#define RB2D_BRUSHDATA_63__BRUSHDATA_MASK                  0xffffffffL

// RB2D_DSTCACHE_MODE
#define RB2D_DSTCACHE_MODE__DC_BYPASS_MASK                 0x00000003L
#define RB2D_DSTCACHE_MODE__DC_LINE_SIZE_MASK              0x0000000cL
#define RB2D_DSTCACHE_MODE__DC_AUTOFLUSH_ENABLE_MASK       0x00000300L
#define RB2D_DSTCACHE_MODE__DC_AUTOFREE_ENABLE_MASK        0x00000c00L
#define RB2D_DSTCACHE_MODE__DC_FORCE_RMW_MASK              0x00010000L
#define RB2D_DSTCACHE_MODE__DC_FORCE_RMW                   0x00010000L
#define RB2D_DSTCACHE_MODE__DC_DISABLE_RI_FILL_MASK        0x01000000L
#define RB2D_DSTCACHE_MODE__DC_DISABLE_RI_FILL             0x01000000L
#define RB2D_DSTCACHE_MODE__DC_DISABLE_RI_READ_MASK        0x02000000L
#define RB2D_DSTCACHE_MODE__DC_DISABLE_RI_READ             0x02000000L
#define RB2D_DSTCACHE_MODE__DC_DISABLE_MASK_CHK_MASK       0x04000000L
#define RB2D_DSTCACHE_MODE__DC_DISABLE_MASK_CHK            0x04000000L

// RB2D_DSTCACHE_CTLSTAT
#define RB2D_DSTCACHE_CTLSTAT__DC_FLUSH_MASK               0x00000003L
#define RB2D_DSTCACHE_CTLSTAT__DC_FREE_MASK                0x0000000cL
#define RB2D_DSTCACHE_CTLSTAT__DC_BUSY_MASK                0x80000000L
#define RB2D_DSTCACHE_CTLSTAT__DC_BUSY                     0x80000000L

// RB2D_SRC_ENDIAN
#define RB2D_SRC_ENDIAN__SRC_ENDIAN_MASK                   0x00000003L

// RB2D_DST_ENDIAN
#define RB2D_DST_ENDIAN__DST_ENDIAN_MASK                   0x00000003L

// RB2D_PD1_DATA
#define RB2D_PD1_DATA__PD1_DATA_MASK                       0xffffffffL

// RB2D_PD2_DATA
#define RB2D_PD2_DATA__PD2_DATA_MASK                       0xffffffffL

// RB2D_WRITEBACK_DATA_LO
#define RB2D_WRITEBACK_DATA_LO__WRITEBACK_DATA_LO_MASK     0xffffffffL

// RB2D_WRITEBACK_DATA_HI
#define RB2D_WRITEBACK_DATA_HI__WRITEBACK_DATA_HI_MASK     0xffffffffL

// RB2D_WRITEBACK_ADDR
#define RB2D_WRITEBACK_ADDR__WRITEBACK_ADDR_MASK           0xfffffff8L

// RB3D_BLENDCOLOR
#define RB3D_BLENDCOLOR__ARGB_MASK                         0xffffffffL

// RB3D_ABLENDCNTL
#define RB3D_ABLENDCNTL__COMB_FCN_MASK                     0x00007000L
#define RB3D_ABLENDCNTL__SRCBLEND_MASK                     0x003f0000L
#define RB3D_ABLENDCNTL__DESTBLEND_MASK                    0x3f000000L

// RB3D_BLENDCNTL
#define RB3D_BLENDCNTL__COMB_FCN_R2_MASK                   0x00007000L
#define RB3D_BLENDCNTL__SRCBLEND_MASK                      0x003f0000L
#define RB3D_BLENDCNTL__DESTBLEND_MASK                     0x3f000000L

// RB3D_DEPTHOFFSET
#define RB3D_DEPTHOFFSET__DEPTHOFFSET_R2_MASK              0xfffff000L

// RB3D_DEPTHPITCH
#define RB3D_DEPTHPITCH__DEPTHPITCH_R2_MASK                0x00001fe0L
#define RB3D_DEPTHPITCH__DEPTHENDIAN_MASK                  0x000c0000L

// RB3D_ZSTENCILCNTL
#define RB3D_ZSTENCILCNTL__DEPTHFORMAT_MASK                0x0000000fL
#define RB3D_ZSTENCILCNTL__ZFUNC_MASK                      0x00000070L
#define RB3D_ZSTENCILCNTL__STENCILFUNC_MASK                0x00007000L
#define RB3D_ZSTENCILCNTL__STENCILFAIL_MASK                0x00070000L
#define RB3D_ZSTENCILCNTL__STENCILZPASS_MASK               0x00700000L
#define RB3D_ZSTENCILCNTL__STENCILZFAIL_MASK               0x07000000L
#define RB3D_ZSTENCILCNTL__FORCEZCLEAR_MASK                0x08000000L
#define RB3D_ZSTENCILCNTL__FORCEZCLEAR                     0x08000000L
#define RB3D_ZSTENCILCNTL__ZCOMPRESSION_MASK               0x10000000L
#define RB3D_ZSTENCILCNTL__ZCOMPRESSION                    0x10000000L
#define RB3D_ZSTENCILCNTL__FORCEZDIRTY_MASK                0x20000000L
#define RB3D_ZSTENCILCNTL__FORCEZDIRTY                     0x20000000L
#define RB3D_ZSTENCILCNTL__ZWRITEENABLE_MASK               0x40000000L
#define RB3D_ZSTENCILCNTL__ZWRITEENABLE                    0x40000000L
#define RB3D_ZSTENCILCNTL__ZDECOMPRESSION_MASK             0x80000000L
#define RB3D_ZSTENCILCNTL__ZDECOMPRESSION                  0x80000000L

// RB3D_DEPTHCLEARVALUE
#define RB3D_DEPTHCLEARVALUE__DEPTHCLEARVALUE_MASK         0xffffffffL

// RB3D_ZMASKOFFSET
#define RB3D_ZMASKOFFSET__ZMASKOFFSET_R2_MASK              0x0001fff0L

// RB3D_CNTL
#define RB3D_CNTL__ALPHA_BLEND_ENABLE_MASK                 0x00000001L
#define RB3D_CNTL__ALPHA_BLEND_ENABLE                      0x00000001L
#define RB3D_CNTL__PLANE_MASK_ENABLE_MASK                  0x00000002L
#define RB3D_CNTL__PLANE_MASK_ENABLE                       0x00000002L
#define RB3D_CNTL__DITHER_ENABLE_MASK                      0x00000004L
#define RB3D_CNTL__DITHER_ENABLE                           0x00000004L
#define RB3D_CNTL__ROUND_ENABLE_MASK                       0x00000008L
#define RB3D_CNTL__ROUND_ENABLE                            0x00000008L
#define RB3D_CNTL__SCALE_DITHER_MASK                       0x00000010L
#define RB3D_CNTL__SCALE_DITHER                            0x00000010L
#define RB3D_CNTL__DITHER_INIT_MASK                        0x00000020L
#define RB3D_CNTL__DITHER_INIT                             0x00000020L
#define RB3D_CNTL__ROP_ENABLE_MASK                         0x00000040L
#define RB3D_CNTL__ROP_ENABLE                              0x00000040L
#define RB3D_CNTL__STENCIL_ENABLE_MASK                     0x00000080L
#define RB3D_CNTL__STENCIL_ENABLE                          0x00000080L
#define RB3D_CNTL__Z_ENABLE_MASK                           0x00000100L
#define RB3D_CNTL__Z_ENABLE                                0x00000100L
#define RB3D_CNTL__DEPTHXY_OFFSET_ENABLE_MASK              0x00000200L
#define RB3D_CNTL__DEPTHXY_OFFSET_ENABLE                   0x00000200L
#define RB3D_CNTL__COLORFORMAT_MASK                        0x00003c00L
#define RB3D_CNTL__CLRCMP_FLIPE_ENABLE_MASK                0x00004000L
#define RB3D_CNTL__CLRCMP_FLIPE_ENABLE                     0x00004000L
#define RB3D_CNTL__SEPARATE_ALPHA_ENABLE_MASK              0x00010000L
#define RB3D_CNTL__SEPARATE_ALPHA_ENABLE                   0x00010000L

// RB3D_COLOROFFSET
#define RB3D_COLOROFFSET__COLOROFFSET_MASK                 0xfffffff0L

// RB3D_COLORPITCH
#define RB3D_COLORPITCH__COLORPITCH_MASK                   0x00001ff8L
#define RB3D_COLORPITCH__COLORTILE_MASK                    0x00010000L
#define RB3D_COLORPITCH__COLORTILE                         0x00010000L
#define RB3D_COLORPITCH__COLORMICROTILE_MASK               0x00020000L
#define RB3D_COLORPITCH__COLORMICROTILE                    0x00020000L
#define RB3D_COLORPITCH__COLORENDIAN_MASK                  0x000c0000L

// RB3D_DEPTHXY_OFFSET
#define RB3D_DEPTHXY_OFFSET__DEPTHX_OFFSET_MASK            0x00000fffL
#define RB3D_DEPTHXY_OFFSET__DEPTHY_OFFSET_MASK            0x0fff0000L

// RB3D_CLRCMP_FLIPE
#define RB3D_CLRCMP_FLIPE__CLRCMP_FLIPE_MASK               0xffffffffL

// RB3D_CLRCMP_CLR
#define RB3D_CLRCMP_CLR__CLRCMP_CLR_MASK                   0xffffffffL

// RB3D_CLRCMP_MSK
#define RB3D_CLRCMP_MSK__CLRCMP_MSK_MASK                   0xffffffffL

// RB3D_ZMASK_WRINDEX
#define RB3D_ZMASK_WRINDEX__ZMASK_WRINDEX_R2_MASK          0x0001fff0L

// RB3D_ZMASK_DWORD
#define RB3D_ZMASK_DWORD__ZMASKDWORD_MASK                  0xffffffffL

// RB3D_ZMASK_RDINDEX
#define RB3D_ZMASK_RDINDEX__ZMASK_RDINDEX_R2_MASK          0x0001fff0L

// RB3D_STENCILREFMASK
#define RB3D_STENCILREFMASK__STENCILREF_MASK               0x000000ffL
#define RB3D_STENCILREFMASK__STENCILMASK_MASK              0x00ff0000L
#define RB3D_STENCILREFMASK__STENCILWRITEMASK_MASK         0xff000000L

// RB3D_ROPCNTL
#define RB3D_ROPCNTL__ROP_MASK                             0x00000f00L

// RB3D_PLANEMASK
#define RB3D_PLANEMASK__PLANEMASK_MASK                     0xffffffffL

// RB3D_ZCACHE_MODE
#define RB3D_ZCACHE_MODE__ZMASK_RAM_RM_MASK                0x00000f00L
#define RB3D_ZCACHE_MODE__ZC_DISABLE_RI_FILL_MASK          0x01000000L
#define RB3D_ZCACHE_MODE__ZC_DISABLE_RI_FILL               0x01000000L
#define RB3D_ZCACHE_MODE__ZC_DISABLE_RI_READ_MASK          0x02000000L
#define RB3D_ZCACHE_MODE__ZC_DISABLE_RI_READ               0x02000000L
#define RB3D_ZCACHE_MODE__ZC_DISABLE_RI_FLUSH_MASK         0x08000000L
#define RB3D_ZCACHE_MODE__ZC_DISABLE_RI_FLUSH              0x08000000L

// RB3D_ZCACHE_CTLSTAT
#define RB3D_ZCACHE_CTLSTAT__ZC_FLUSH_MASK                 0x00000001L
#define RB3D_ZCACHE_CTLSTAT__ZC_FLUSH                      0x00000001L
#define RB3D_ZCACHE_CTLSTAT__ZC_FREE_MASK                  0x00000004L
#define RB3D_ZCACHE_CTLSTAT__ZC_FREE                       0x00000004L
#define RB3D_ZCACHE_CTLSTAT__ZC_BUSY_MASK                  0x80000000L
#define RB3D_ZCACHE_CTLSTAT__ZC_BUSY                       0x80000000L

// RB3D_DSTCACHE_MODE
#define RB3D_DSTCACHE_MODE__DC_BYPASS_MASK                 0x00000003L
#define RB3D_DSTCACHE_MODE__DC_LINE_SIZE_MASK              0x0000000cL
#define RB3D_DSTCACHE_MODE__DC_AUTOFLUSH_ENABLE_MASK       0x00000300L
#define RB3D_DSTCACHE_MODE__DC_AUTOFREE_ENABLE_MASK        0x00000c00L
#define RB3D_DSTCACHE_MODE__DC_FORCE_RMW_MASK              0x00010000L
#define RB3D_DSTCACHE_MODE__DC_FORCE_RMW                   0x00010000L
#define RB3D_DSTCACHE_MODE__DC_DISABLE_RI_FILL_MASK        0x01000000L
#define RB3D_DSTCACHE_MODE__DC_DISABLE_RI_FILL             0x01000000L
#define RB3D_DSTCACHE_MODE__DC_DISABLE_RI_READ_MASK        0x02000000L
#define RB3D_DSTCACHE_MODE__DC_DISABLE_RI_READ             0x02000000L
#define RB3D_DSTCACHE_MODE__DC_DISABLE_MASK_CHK_MASK       0x04000000L
#define RB3D_DSTCACHE_MODE__DC_DISABLE_MASK_CHK            0x04000000L

// RB3D_DSTCACHE_CTLSTAT
#define RB3D_DSTCACHE_CTLSTAT__DC_FLUSH_MASK               0x00000003L
#define RB3D_DSTCACHE_CTLSTAT__DC_FREE_MASK                0x0000000cL
#define RB3D_DSTCACHE_CTLSTAT__DC_BUSY_MASK                0x80000000L
#define RB3D_DSTCACHE_CTLSTAT__DC_BUSY                     0x80000000L

// RB3D_PD0_DATA
#define RB3D_PD0_DATA__DISABLE_RB_MASK                     0x00000001L
#define RB3D_PD0_DATA__DISABLE_RB                          0x00000001L

// RB3D_DSTPERF_CNTL
#define RB3D_DSTPERF_CNTL__PERFSEL0_MASK                   0x00000007L
#define RB3D_DSTPERF_CNTL__CLR_PERF0_MASK                  0x00000010L
#define RB3D_DSTPERF_CNTL__CLR_PERF0                       0x00000010L
#define RB3D_DSTPERF_CNTL__EN_PERF0_MASK                   0x00000020L
#define RB3D_DSTPERF_CNTL__EN_PERF0                        0x00000020L
#define RB3D_DSTPERF_CNTL__PERFSEL1_MASK                   0x00000700L
#define RB3D_DSTPERF_CNTL__CLR_PERF1_MASK                  0x00001000L
#define RB3D_DSTPERF_CNTL__CLR_PERF1                       0x00001000L
#define RB3D_DSTPERF_CNTL__EN_PERF1_MASK                   0x00002000L
#define RB3D_DSTPERF_CNTL__EN_PERF1                        0x00002000L

// RB3D_PD1_DATA
#define RB3D_PD1_DATA__RB3D_DBG_DISABLE_ZMASK_L0_MASK      0x00000001L
#define RB3D_PD1_DATA__RB3D_DBG_DISABLE_ZMASK_L0           0x00000001L
#define RB3D_PD1_DATA__PD1_DATA_R2_MASK                    0xfffffffeL

// RB3D_PD1_ADDR
#define RB3D_PD1_ADDR__PD1_ADDR_MASK                       0x00000007L

// RB3D_PD2_DATA
#define RB3D_PD2_DATA__PD2_DATA_MASK                       0xffffffffL

// RB3D_PD3_DATA
#define RB3D_PD3_DATA__PD3_DATA_MASK                       0xffffffffL

// RB3D_WRITEBACK_DATA_LO
#define RB3D_WRITEBACK_DATA_LO__WRITEBACK_DATA_LO_MASK     0xffffffffL

// RB3D_WRITEBACK_DATA_HI
#define RB3D_WRITEBACK_DATA_HI__WRITEBACK_DATA_HI_MASK     0xffffffffL

// RB3D_WRITEBACK_ADDR
#define RB3D_WRITEBACK_ADDR__WRITEBACK_ADDR_MASK           0xfffffff8L

// RB3D_ZPERF_CNTL
#define RB3D_ZPERF_CNTL__PERFSEL0_MASK                     0x0000000fL
#define RB3D_ZPERF_CNTL__CLR_PERF0_MASK                    0x00000010L
#define RB3D_ZPERF_CNTL__CLR_PERF0                         0x00000010L
#define RB3D_ZPERF_CNTL__EN_PERF0_MASK                     0x00000020L
#define RB3D_ZPERF_CNTL__EN_PERF0                          0x00000020L
#define RB3D_ZPERF_CNTL__PERFSEL1_MASK                     0x00000f00L
#define RB3D_ZPERF_CNTL__CLR_PERF1_MASK                    0x00001000L
#define RB3D_ZPERF_CNTL__CLR_PERF1                         0x00001000L
#define RB3D_ZPERF_CNTL__EN_PERF1_MASK                     0x00002000L
#define RB3D_ZPERF_CNTL__EN_PERF1                          0x00002000L

// RB3D_ZPASS_DATA
#define RB3D_ZPASS_DATA__ZPASS_DATA_MASK                   0xffffffffL

// RB3D_ZPASS_ADDR
#define RB3D_ZPASS_ADDR__ZPASS_ADDR_MASK                   0xfffffffcL

// RB3D_ZPERF_COUNT_0
#define RB3D_ZPERF_COUNT_0__PERF_COUNT_MASK                0xffffffffL

// RB3D_ZPERF_COUNT_1
#define RB3D_ZPERF_COUNT_1__PERF_COUNT_MASK                0xffffffffL

// RB3D_CRC_CNTL
#define RB3D_CRC_CNTL__CRC_PP_FB_EN_MASK                   0x00000001L
#define RB3D_CRC_CNTL__CRC_PP_FB_EN                        0x00000001L
#define RB3D_CRC_CNTL__CRC_PP_FB_CLEAR_MASK                0x00000002L
#define RB3D_CRC_CNTL__CRC_PP_FB_CLEAR                     0x00000002L
#define RB3D_CRC_CNTL__CRC_PP_FB_RDSEL_MASK                0x00000070L
#define RB3D_CRC_CNTL__CRC_RB0W_EN_MASK                    0x00000100L
#define RB3D_CRC_CNTL__CRC_RB0W_EN                         0x00000100L
#define RB3D_CRC_CNTL__CRC_RB0W_CLEAR_MASK                 0x00000200L
#define RB3D_CRC_CNTL__CRC_RB0W_CLEAR                      0x00000200L
#define RB3D_CRC_CNTL__CRC_RB0W_RDSEL_MASK                 0x00007000L
#define RB3D_CRC_CNTL__CRC_RB1W_EN_MASK                    0x00010000L
#define RB3D_CRC_CNTL__CRC_RB1W_EN                         0x00010000L
#define RB3D_CRC_CNTL__CRC_RB1W_CLEAR_MASK                 0x00020000L
#define RB3D_CRC_CNTL__CRC_RB1W_CLEAR                      0x00020000L
#define RB3D_CRC_CNTL__CRC_RB1W_RDSEL_MASK                 0x00700000L

// RB3D_CRC_PP_FB
#define RB3D_CRC_PP_FB__CRC_MASK                           0x0000ffffL

// RB3D_CRC_RB0W
#define RB3D_CRC_RB0W__CRC_MASK                            0x0000ffffL

// RB3D_CRC_RB1W
#define RB3D_CRC_RB1W__CRC_MASK                            0x0000ffffL

// DST_OFFSET
#define DST_OFFSET__DST_OFFSET_MASK                        0xffffffffL

// DST_PITCH
#define DST_PITCH__DST_PITCH_MASK                          0x00003fffL

// DST_TILE
#define DST_TILE__DST_TILE_MASK                            0x00000003L

// DST_PITCH_OFFSET
#define DST_PITCH_OFFSET__DST_OFFSET_MASK                  0x003fffffL
#define DST_PITCH_OFFSET__DST_PITCH_MASK                   0x3fc00000L
#define DST_PITCH_OFFSET__DST_TILE_MASK                    0xc0000000L

// DST_X
#define DST_X__DST_X_MASK                                  0x00003fffL

// DST_Y
#define DST_Y__DST_Y_MASK                                  0x00003fffL

// DST_X_Y
#define DST_X_Y__DST_Y_MASK                                0x00003fffL
#define DST_X_Y__DST_X_MASK                                0x3fff0000L

// DST_Y_X
#define DST_Y_X__DST_X_MASK                                0x00003fffL
#define DST_Y_X__DST_Y_MASK                                0x3fff0000L

// DST_WIDTH
#define DST_WIDTH__DST_WIDTH_MASK                          0x00003fffL

// DST_HEIGHT
#define DST_HEIGHT__DST_HEIGHT_MASK                        0x00003fffL

// DST_WIDTH_HEIGHT
#define DST_WIDTH_HEIGHT__DST_HEIGHT_MASK                  0x00003fffL
#define DST_WIDTH_HEIGHT__DST_WIDTH_MASK                   0x3fff0000L

// DST_HEIGHT_WIDTH
#define DST_HEIGHT_WIDTH__DST_WIDTH_MASK                   0x00003fffL
#define DST_HEIGHT_WIDTH__DST_HEIGHT_MASK                  0x3fff0000L

// DST_HEIGHT_WIDTH_8
#define DST_HEIGHT_WIDTH_8__DST_WIDTH_MASK                 0x00ff0000L
#define DST_HEIGHT_WIDTH_8__DST_HEIGHT_MASK                0xff000000L

// DST_HEIGHT_Y
#define DST_HEIGHT_Y__DST_Y_MASK                           0x00003fffL
#define DST_HEIGHT_Y__DST_HEIGHT_MASK                      0x3fff0000L

// DST_WIDTH_X
#define DST_WIDTH_X__DST_X_MASK                            0x00003fffL
#define DST_WIDTH_X__DST_WIDTH_MASK                        0x3fff0000L

// DST_WIDTH_X_INCY
#define DST_WIDTH_X_INCY__DST_X_MASK                       0x00003fffL
#define DST_WIDTH_X_INCY__DST_WIDTH_MASK                   0x3fff0000L

// DST_LINE_START
#define DST_LINE_START__DST_START_X_MASK                   0x00003fffL
#define DST_LINE_START__DST_START_Y_MASK                   0x3fff0000L

// DST_LINE_END
#define DST_LINE_END__DST_END_X_MASK                       0x00003fffL
#define DST_LINE_END__DST_END_Y_MASK                       0x3fff0000L

// DST_LINE_PATCOUNT
#define DST_LINE_PATCOUNT__LINE_PATCOUNT_MASK              0x0000001fL
#define DST_LINE_PATCOUNT__BRES_CNTL_MASK                  0x0000ff00L

// DP_DST_ENDIAN
#define DP_DST_ENDIAN__DST_ENDIAN_MASK                     0x00000003L

// BRUSH_Y_X
#define BRUSH_Y_X__BRUSH_X_MASK                            0x00000007L
#define BRUSH_Y_X__BRUSH_Y_MASK                            0x00000700L

// BRUSH_DATA0
#define BRUSH_DATA0__BRUSH_DATA_MASK                       0xffffffffL

// BRUSH_DATA1
#define BRUSH_DATA1__BRUSH_DATA_MASK                       0xffffffffL

// BRUSH_DATA2
#define BRUSH_DATA2__BRUSH_DATA_MASK                       0xffffffffL

// BRUSH_DATA3
#define BRUSH_DATA3__BRUSH_DATA_MASK                       0xffffffffL

// BRUSH_DATA4
#define BRUSH_DATA4__BRUSH_DATA_MASK                       0xffffffffL

// BRUSH_DATA5
#define BRUSH_DATA5__BRUSH_DATA_MASK                       0xffffffffL

// BRUSH_DATA6
#define BRUSH_DATA6__BRUSH_DATA_MASK                       0xffffffffL

// BRUSH_DATA7
#define BRUSH_DATA7__BRUSH_DATA_MASK                       0xffffffffL

// BRUSH_DATA8
#define BRUSH_DATA8__BRUSH_DATA_MASK                       0xffffffffL

// BRUSH_DATA9
#define BRUSH_DATA9__BRUSH_DATA_MASK                       0xffffffffL

// BRUSH_DATA10
#define BRUSH_DATA10__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA11
#define BRUSH_DATA11__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA12
#define BRUSH_DATA12__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA13
#define BRUSH_DATA13__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA14
#define BRUSH_DATA14__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA15
#define BRUSH_DATA15__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA16
#define BRUSH_DATA16__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA17
#define BRUSH_DATA17__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA18
#define BRUSH_DATA18__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA19
#define BRUSH_DATA19__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA20
#define BRUSH_DATA20__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA21
#define BRUSH_DATA21__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA22
#define BRUSH_DATA22__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA23
#define BRUSH_DATA23__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA24
#define BRUSH_DATA24__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA25
#define BRUSH_DATA25__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA26
#define BRUSH_DATA26__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA27
#define BRUSH_DATA27__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA28
#define BRUSH_DATA28__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA29
#define BRUSH_DATA29__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA30
#define BRUSH_DATA30__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA31
#define BRUSH_DATA31__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA32
#define BRUSH_DATA32__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA33
#define BRUSH_DATA33__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA34
#define BRUSH_DATA34__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA35
#define BRUSH_DATA35__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA36
#define BRUSH_DATA36__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA37
#define BRUSH_DATA37__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA38
#define BRUSH_DATA38__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA39
#define BRUSH_DATA39__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA40
#define BRUSH_DATA40__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA41
#define BRUSH_DATA41__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA42
#define BRUSH_DATA42__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA43
#define BRUSH_DATA43__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA44
#define BRUSH_DATA44__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA45
#define BRUSH_DATA45__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA46
#define BRUSH_DATA46__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA47
#define BRUSH_DATA47__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA48
#define BRUSH_DATA48__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA49
#define BRUSH_DATA49__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA50
#define BRUSH_DATA50__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA51
#define BRUSH_DATA51__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA52
#define BRUSH_DATA52__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA53
#define BRUSH_DATA53__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA54
#define BRUSH_DATA54__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA55
#define BRUSH_DATA55__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA56
#define BRUSH_DATA56__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA57
#define BRUSH_DATA57__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA58
#define BRUSH_DATA58__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA59
#define BRUSH_DATA59__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA60
#define BRUSH_DATA60__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA61
#define BRUSH_DATA61__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA62
#define BRUSH_DATA62__BRUSH_DATA_MASK                      0xffffffffL

// BRUSH_DATA63
#define BRUSH_DATA63__BRUSH_DATA_MASK                      0xffffffffL

// DP_BRUSH_FRGD_CLR
#define DP_BRUSH_FRGD_CLR__DP_BRUSH_FRGD_CLR_MASK          0xffffffffL

// DP_BRUSH_BKGD_CLR
#define DP_BRUSH_BKGD_CLR__DP_BRUSH_BKGD_CLR_MASK          0xffffffffL

// SRC_OFFSET
#define SRC_OFFSET__SRC_OFFSET_MASK                        0xffffffffL

// SRC_PITCH
#define SRC_PITCH__SRC_PITCH_MASK                          0x00003fffL

// SRC_TILE
#define SRC_TILE__SRC_TILE_MASK                            0x00000001L
#define SRC_TILE__SRC_TILE                                 0x00000001L

// SRC_PITCH_OFFSET
#define SRC_PITCH_OFFSET__SRC_OFFSET_MASK                  0x003fffffL
#define SRC_PITCH_OFFSET__SRC_PITCH_MASK                   0x3fc00000L
#define SRC_PITCH_OFFSET__SRC_TILE_MASK                    0x40000000L
#define SRC_PITCH_OFFSET__SRC_TILE                         0x40000000L

// SRC_X
#define SRC_X__SRC_X_MASK                                  0x00003fffL

// SRC_Y
#define SRC_Y__SRC_Y_MASK                                  0x00003fffL

// SRC_X_Y
#define SRC_X_Y__SRC_Y_MASK                                0x00003fffL
#define SRC_X_Y__SRC_X_MASK                                0x3fff0000L

// SRC_Y_X
#define SRC_Y_X__SRC_X_MASK                                0x00003fffL
#define SRC_Y_X__SRC_Y_MASK                                0x3fff0000L

// SRC_CLUT_ADDRESS
#define SRC_CLUT_ADDRESS__SRC_CLUT_ADDRESS_MASK            0x000000ffL

// SRC_CLUT_DATA
#define SRC_CLUT_DATA__SRC_CLUT_DATA_MASK                  0xffffffffL

// SRC_CLUT_DATA_RD
#define SRC_CLUT_DATA_RD__SRC_CLUT_DATA_MASK               0xffffffffL

// HOST_DATA0
#define HOST_DATA0__HOST_DATA_MASK                         0xffffffffL

// HOST_DATA1
#define HOST_DATA1__HOST_DATA_MASK                         0xffffffffL

// HOST_DATA2
#define HOST_DATA2__HOST_DATA_MASK                         0xffffffffL

// HOST_DATA3
#define HOST_DATA3__HOST_DATA_MASK                         0xffffffffL

// HOST_DATA4
#define HOST_DATA4__HOST_DATA_MASK                         0xffffffffL

// HOST_DATA5
#define HOST_DATA5__HOST_DATA_MASK                         0xffffffffL

// HOST_DATA6
#define HOST_DATA6__HOST_DATA_MASK                         0xffffffffL

// HOST_DATA7
#define HOST_DATA7__HOST_DATA_MASK                         0xffffffffL

// HOST_DATA_LAST
#define HOST_DATA_LAST__HOST_DATA_LAST_MASK                0xffffffffL

// DP_SRC_ENDIAN
#define DP_SRC_ENDIAN__SRC_ENDIAN_MASK                     0x00000003L

// DP_SRC_FRGD_CLR
#define DP_SRC_FRGD_CLR__DP_SRC_FRGD_CLR_MASK              0xffffffffL

// DP_SRC_BKGD_CLR
#define DP_SRC_BKGD_CLR__DP_SRC_BKGD_CLR_MASK              0xffffffffL

// SC_LEFT
#define SC_LEFT__SC_LEFT_MASK                              0x00003fffL

// SC_RIGHT
#define SC_RIGHT__SC_RIGHT_MASK                            0x00003fffL

// SC_TOP
#define SC_TOP__SC_TOP_MASK                                0x00003fffL

// SC_BOTTOM
#define SC_BOTTOM__SC_BOTTOM_MASK                          0x00003fffL

// SRC_SC_RIGHT
#define SRC_SC_RIGHT__SC_RIGHT_MASK                        0x00003fffL

// SRC_SC_BOTTOM
#define SRC_SC_BOTTOM__SC_BOTTOM_MASK                      0x00003fffL

// DP_CNTL
#define DP_CNTL__DST_X_DIR_MASK                            0x00000001L
#define DP_CNTL__DST_X_DIR                                 0x00000001L
#define DP_CNTL__DST_Y_DIR_MASK                            0x00000002L
#define DP_CNTL__DST_Y_DIR                                 0x00000002L
#define DP_CNTL__DST_TILE_MASK                             0x00000018L

// DP_CNTL_XDIR_YDIR_YMAJOR
#define DP_CNTL_XDIR_YDIR_YMAJOR__DST_Y_DIR_MASK           0x00008000L
#define DP_CNTL_XDIR_YDIR_YMAJOR__DST_Y_DIR                0x00008000L
#define DP_CNTL_XDIR_YDIR_YMAJOR__DST_X_DIR_MASK           0x80000000L
#define DP_CNTL_XDIR_YDIR_YMAJOR__DST_X_DIR                0x80000000L

// DP_DATATYPE
#define DP_DATATYPE__DP_DST_DATATYPE_MASK                  0x0000000fL
#define DP_DATATYPE__DP_BRUSH_DATATYPE_MASK                0x00000f00L
#define DP_DATATYPE__DP_SRC_DATATYPE_MASK                  0x00070000L
#define DP_DATATYPE__DP_BYTE_PIX_ORDER_MASK                0x40000000L
#define DP_DATATYPE__DP_BYTE_PIX_ORDER                     0x40000000L

// DP_MIX
#define DP_MIX__DP_SRC_SOURCE_MASK                         0x00000700L
#define DP_MIX__DP_ROP3_MASK                               0x00ff0000L

// DP_WRITE_MSK
#define DP_WRITE_MSK__DP_WRITE_MSK_MASK                    0xffffffffL

// DP_XOP
#define DP_XOP__XOP_A_MASK                                 0x000000ffL
#define DP_XOP__XOP_B_MASK                                 0x0000ff00L
#define DP_XOP__XOP_C_MASK                                 0x00ff0000L
#define DP_XOP__XOP_OP_MASK                                0x03000000L

// CLR_CMP_CLR_SRC
#define CLR_CMP_CLR_SRC__CLR_CMP_CLR_SRC_MASK              0xffffffffL

// CLR_CMP_CLR_DST
#define CLR_CMP_CLR_DST__CLR_CMP_CLR_DST_MASK              0xffffffffL

// CLR_CMP_CNTL
#define CLR_CMP_CNTL__CLR_CMP_FCN_SRC_MASK                 0x00000007L
#define CLR_CMP_CNTL__CLR_CMP_FCN_DST_MASK                 0x00000700L
#define CLR_CMP_CNTL__CLR_CMP_SRC_MASK                     0x03000000L

// CLR_CMP_MSK
#define CLR_CMP_MSK__CLR_CMP_MSK_MASK                      0xffffffffL

// DSTCACHE_MODE
#define DSTCACHE_MODE__DSTCACHE_MODE_MASK                  0xffffffffL

// DSTCACHE_CTLSTAT
#define DSTCACHE_CTLSTAT__DSTCACHE_CTLSTAT_MASK            0xffffffffL

// PD2_DATA
#define PD2_DATA__PD2_DATA_MASK                            0xffffffffL

// DEFAULT_PITCH_OFFSET
#define DEFAULT_PITCH_OFFSET__DEFAULT_OFFSET_MASK          0x003fffffL
#define DEFAULT_PITCH_OFFSET__DEFAULT_PITCH_MASK           0x3fc00000L
#define DEFAULT_PITCH_OFFSET__DEFAULT_TILE_MASK            0xc0000000L

// DEFAULT_SC_BOTTOM_RIGHT
#define DEFAULT_SC_BOTTOM_RIGHT__DEFAULT_SC_RIGHT_MASK     0x00003fffL
#define DEFAULT_SC_BOTTOM_RIGHT__DEFAULT_SC_BOTTOM_MASK    0x3fff0000L

// DEFAULT2_PITCH_OFFSET
#define DEFAULT2_PITCH_OFFSET__DEFAULT_OFFSET_MASK         0x003fffffL
#define DEFAULT2_PITCH_OFFSET__DEFAULT_PITCH_MASK          0x3fc00000L
#define DEFAULT2_PITCH_OFFSET__DEFAULT_TILE_MASK           0xc0000000L

// DEFAULT2_SC_BOTTOM_RIGHT
#define DEFAULT2_SC_BOTTOM_RIGHT__DEFAULT_SC_RIGHT_MASK    0x00003fffL
#define DEFAULT2_SC_BOTTOM_RIGHT__DEFAULT_SC_BOTTOM_MASK   0x3fff0000L

// DP_GUI_MASTER_CNTL
#define DP_GUI_MASTER_CNTL__GMC_SRC_PITCH_OFFSET_CNTL_MASK 0x00000001L
#define DP_GUI_MASTER_CNTL__GMC_SRC_PITCH_OFFSET_CNTL      0x00000001L
#define DP_GUI_MASTER_CNTL__GMC_DST_PITCH_OFFSET_CNTL_MASK 0x00000002L
#define DP_GUI_MASTER_CNTL__GMC_DST_PITCH_OFFSET_CNTL      0x00000002L
#define DP_GUI_MASTER_CNTL__GMC_SRC_CLIPPING_MASK          0x00000004L
#define DP_GUI_MASTER_CNTL__GMC_SRC_CLIPPING               0x00000004L
#define DP_GUI_MASTER_CNTL__GMC_DST_CLIPPING_MASK          0x00000008L
#define DP_GUI_MASTER_CNTL__GMC_DST_CLIPPING               0x00000008L
#define DP_GUI_MASTER_CNTL__GMC_BRUSH_DATATYPE_MASK        0x000000f0L
#define DP_GUI_MASTER_CNTL__GMC_DST_DATATYPE_MASK          0x00000f00L
#define DP_GUI_MASTER_CNTL__GMC_SRC_DATATYPE_MASK          0x00003000L
#define DP_GUI_MASTER_CNTL__GMC_BYTE_PIX_ORDER_MASK        0x00004000L
#define DP_GUI_MASTER_CNTL__GMC_BYTE_PIX_ORDER             0x00004000L
#define DP_GUI_MASTER_CNTL__GMC_DEFAULT_SEL_MASK           0x00008000L
#define DP_GUI_MASTER_CNTL__GMC_DEFAULT_SEL                0x00008000L
#define DP_GUI_MASTER_CNTL__GMC_ROP3_MASK                  0x00ff0000L
#define DP_GUI_MASTER_CNTL__GMC_DP_SRC_SOURCE_MASK         0x07000000L
#define DP_GUI_MASTER_CNTL__GMC_SRC_DATATYPE2_MASK         0x08000000L
#define DP_GUI_MASTER_CNTL__GMC_SRC_DATATYPE2              0x08000000L
#define DP_GUI_MASTER_CNTL__GMC_CLR_CMP_FCN_DIS_MASK       0x10000000L
#define DP_GUI_MASTER_CNTL__GMC_CLR_CMP_FCN_DIS            0x10000000L
#define DP_GUI_MASTER_CNTL__GMC_WR_MSK_DIS_MASK            0x40000000L
#define DP_GUI_MASTER_CNTL__GMC_WR_MSK_DIS                 0x40000000L

// SC_TOP_LEFT
#define SC_TOP_LEFT__SC_LEFT_MASK                          0x00003fffL
#define SC_TOP_LEFT__SC_TOP_MASK                           0x3fff0000L

// SC_BOTTOM_RIGHT
#define SC_BOTTOM_RIGHT__SC_RIGHT_MASK                     0x00003fffL
#define SC_BOTTOM_RIGHT__SC_BOTTOM_MASK                    0x3fff0000L

// SRC_SC_BOTTOM_RIGHT
#define SRC_SC_BOTTOM_RIGHT__SC_RIGHT_MASK                 0x00003fffL
#define SRC_SC_BOTTOM_RIGHT__SC_BOTTOM_MASK                0x3fff0000L

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
#define BIOS_0_SCRATCH__BIOS_SCRATCH_MASK                  0xffffffffL

// BIOS_1_SCRATCH
#define BIOS_1_SCRATCH__BIOS_SCRATCH_MASK                  0xffffffffL

// BIOS_2_SCRATCH
#define BIOS_2_SCRATCH__BIOS_SCRATCH_MASK                  0xffffffffL

// BIOS_3_SCRATCH
#define BIOS_3_SCRATCH__BIOS_SCRATCH_MASK                  0xffffffffL

// BIOS_4_SCRATCH
#define BIOS_4_SCRATCH__BIOS_SCRATCH_MASK                  0xffffffffL

// BIOS_5_SCRATCH
#define BIOS_5_SCRATCH__BIOS_SCRATCH_MASK                  0xffffffffL

// BIOS_6_SCRATCH
#define BIOS_6_SCRATCH__BIOS_SCRATCH_MASK                  0xffffffffL

// BIOS_7_SCRATCH
#define BIOS_7_SCRATCH__BIOS_SCRATCH_MASK                  0xffffffffL

// CONFIG_XSTRAP
#define CONFIG_XSTRAP__VGA_DISABLE_MASK                    0x00000001L
#define CONFIG_XSTRAP__VGA_DISABLE                         0x00000001L
#define CONFIG_XSTRAP__ENINTB_MASK                         0x00000008L
#define CONFIG_XSTRAP__ENINTB                              0x00000008L
#define CONFIG_XSTRAP__AGPSKEW_MASK                        0x000000c0L
#define CONFIG_XSTRAP__X1CLK_SKEW_MASK                     0x00000300L
#define CONFIG_XSTRAP__ID_DISABLE_MASK                     0x00004000L
#define CONFIG_XSTRAP__ID_DISABLE                          0x00004000L
#define CONFIG_XSTRAP__AP_SIZE_MASK                        0x00030000L
#define CONFIG_XSTRAP__ROMIDCFG_MASK                       0x00700000L
#define CONFIG_XSTRAP__BUSCFG_MASK                         0x07000000L

// TEST_DEBUG_CNTL
#define TEST_DEBUG_CNTL__TEST_DEBUG_OUT_EN_MASK            0x00000001L
#define TEST_DEBUG_CNTL__TEST_DEBUG_OUT_EN                 0x00000001L
#define TEST_DEBUG_CNTL__TEST_DEBUG_IN_EN_MASK             0x00000002L
#define TEST_DEBUG_CNTL__TEST_DEBUG_IN_EN                  0x00000002L
#define TEST_DEBUG_CNTL__TEST_IDDQ_EN_MASK                 0x00000004L
#define TEST_DEBUG_CNTL__TEST_IDDQ_EN                      0x00000004L
#define TEST_DEBUG_CNTL__TEST_BLOCK_SEL_MASK               0x00003f00L
#define TEST_DEBUG_CNTL__TEST_ENABLE_MASK                  0x00008000L
#define TEST_DEBUG_CNTL__TEST_ENABLE                       0x00008000L
#define TEST_DEBUG_CNTL__TEST_DELAY_IN_MASK                0x00010000L
#define TEST_DEBUG_CNTL__TEST_DELAY_IN                     0x00010000L

// TEST_DEBUG_MUX
#define TEST_DEBUG_MUX__TEST_DEBUG_SEL_MASK                0x0000003fL
#define TEST_DEBUG_MUX__TEST_CLK0_MASK                     0x00001f00L
#define TEST_DEBUG_MUX__TEST_CLK0_INV_MASK                 0x00008000L
#define TEST_DEBUG_MUX__TEST_CLK0_INV                      0x00008000L
#define TEST_DEBUG_MUX__TEST_CLK1_MASK                     0x001f0000L
#define TEST_DEBUG_MUX__TEST_CLK1_INV_MASK                 0x00800000L
#define TEST_DEBUG_MUX__TEST_CLK1_INV                      0x00800000L

// TEST_DEBUG_OUT
#define TEST_DEBUG_OUT__TEST_DEBUG_OUTR_U1_MASK            0x0000ffffL

// VIDEOMUX_CNTL
#define VIDEOMUX_CNTL__ROM_CLK_DIVIDE_MASK                 0x001f0000L
#define VIDEOMUX_CNTL__STR_ROMCLK_MASK                     0x00200000L
#define VIDEOMUX_CNTL__STR_ROMCLK                          0x00200000L
#define VIDEOMUX_CNTL__VIP_INTERNAL_DEBUG_SEL_MASK         0x01c00000L
#define VIDEOMUX_CNTL__GEYSERVILLE_SENSE_MASK              0x02000000L
#define VIDEOMUX_CNTL__GEYSERVILLE_SENSE                   0x02000000L
#define VIDEOMUX_CNTL__GEYSERVILLE_INT_POL_MASK            0x04000000L
#define VIDEOMUX_CNTL__GEYSERVILLE_INT_POL                 0x04000000L

// VIPPAD_STRENGTH
#define VIPPAD_STRENGTH__ZV_LCDDATA_STRENGTH_MASK          0x00000003L
#define VIPPAD_STRENGTH__ZV_LCDCNTL_STRENGTH_MASK          0x00000300L
#define VIPPAD_STRENGTH__GPIO_STRENGTH_MASK                0x00003000L

// GPIOPAD_MASK
#define GPIOPAD_MASK__GPIO_MASK_MASK                       0x00003fffL

// GPIOPAD_A
#define GPIOPAD_A__GPIO_A_MASK                             0x00003fffL

// GPIOPAD_EN
#define GPIOPAD_EN__GPIO_EN_MASK                           0x00003fffL

// GPIOPAD_Y
#define GPIOPAD_Y__GPIO_Y_MASK                             0x00003fffL

// ZV_LCDPAD_MASK
#define ZV_LCDPAD_MASK__ZV_LCDDATA_MASK_U1_MASK            0x00000fffL
#define ZV_LCDPAD_MASK__ZV_LCDCNTL_MASK_MASK               0x0f000000L

// ZV_LCDPAD_A
#define ZV_LCDPAD_A__ZV_LCDDATA_A_U1_MASK                  0x00000fffL
#define ZV_LCDPAD_A__ZV_LCDCNTL_A_MASK                     0x0f000000L

// ZV_LCDPAD_EN
#define ZV_LCDPAD_EN__ZV_LCDDATA_EN_U1_MASK                0x00000fffL
#define ZV_LCDPAD_EN__ZV_LCDCNTL_EN_MASK                   0x0f000000L

// ZV_LCDPAD_Y
#define ZV_LCDPAD_Y__ZV_LCDDATA_Y_U1_MASK                  0x0000ffffL
#define ZV_LCDPAD_Y__ZV_LCDCNTL_Y_MASK                     0x0f000000L

// EXTERN_TRIG_CNTL
#define EXTERN_TRIG_CNTL__EXTERN_TRIG_CLR_MASK             0x00000001L
#define EXTERN_TRIG_CNTL__EXTERN_TRIG_CLR                  0x00000001L
#define EXTERN_TRIG_CNTL__EXTERN_TRIG_READ_MASK            0x00000002L
#define EXTERN_TRIG_CNTL__EXTERN_TRIG_READ                 0x00000002L

// STRAP_CNTL_REG
#define STRAP_CNTL_REG__PANEL_ID_MASK                      0x0000001fL
#define STRAP_CNTL_REG__MULTIMEDIA_MASK                    0x00000020L
#define STRAP_CNTL_REG__MULTIMEDIA                         0x00000020L

// SEPROM_CNTL1
#define SEPROM_CNTL1__WRITE_ENABLE_MASK                    0x00000001L
#define SEPROM_CNTL1__WRITE_ENABLE                         0x00000001L
#define SEPROM_CNTL1__WRITE_DISABLE_MASK                   0x00000002L
#define SEPROM_CNTL1__WRITE_DISABLE                        0x00000002L
#define SEPROM_CNTL1__READ_CONFIG_MASK                     0x00000004L
#define SEPROM_CNTL1__READ_CONFIG                          0x00000004L
#define SEPROM_CNTL1__WRITE_CONFIG_MASK                    0x00000008L
#define SEPROM_CNTL1__WRITE_CONFIG                         0x00000008L
#define SEPROM_CNTL1__READ_STATUS_MASK                     0x00000010L
#define SEPROM_CNTL1__READ_STATUS                          0x00000010L
#define SEPROM_CNTL1__SECT_TO_SRAM_MASK                    0x00000020L
#define SEPROM_CNTL1__SECT_TO_SRAM                         0x00000020L
#define SEPROM_CNTL1__READY_BUSY_MASK                      0x00000080L
#define SEPROM_CNTL1__READY_BUSY                           0x00000080L
#define SEPROM_CNTL1__SEPROM_BUSY_MASK                     0x00000100L
#define SEPROM_CNTL1__SEPROM_BUSY                          0x00000100L
#define SEPROM_CNTL1__BCNT_OVER_WTE_EN_MASK                0x00000200L
#define SEPROM_CNTL1__BCNT_OVER_WTE_EN                     0x00000200L
#define SEPROM_CNTL1__RB_MASKB_MASK                        0x00000400L
#define SEPROM_CNTL1__RB_MASKB                             0x00000400L
#define SEPROM_CNTL1__SOFT_RESET_MASK                      0x00000800L
#define SEPROM_CNTL1__SOFT_RESET                           0x00000800L
#define SEPROM_CNTL1__STATE_IDLEb_MASK                     0x00001000L
#define SEPROM_CNTL1__STATE_IDLEb                          0x00001000L
#define SEPROM_CNTL1__BYTE_CNT_MASK                        0x00ff0000L
#define SEPROM_CNTL1__SCK_PRESCALE_MASK                    0xff000000L

// SEPROM_CNTL2
#define SEPROM_CNTL2__WAIT_CYCLE_MASK                      0x000000ffL
#define SEPROM_CNTL2__AUTO_ADDR_SAMPLE_MASK                0x00000100L
#define SEPROM_CNTL2__AUTO_ADDR_SAMPLE                     0x00000100L
#define SEPROM_CNTL2__SEC_COMMAND_MASK                     0x00ff0000L

// VIP_HW_DEBUG
#define VIP_HW_DEBUG__VIP_HW_6_DEBUG_MASK                  0x00000040L
#define VIP_HW_DEBUG__VIP_HW_6_DEBUG                       0x00000040L
#define VIP_HW_DEBUG__VIP_HW_7_DEBUG_MASK                  0x00000080L
#define VIP_HW_DEBUG__VIP_HW_7_DEBUG                       0x00000080L
#define VIP_HW_DEBUG__VIP_HW_8_DEBUG_MASK                  0x00000100L
#define VIP_HW_DEBUG__VIP_HW_8_DEBUG                       0x00000100L
#define VIP_HW_DEBUG__VIP_HW_C_DEBUG_MASK                  0x00001000L
#define VIP_HW_DEBUG__VIP_HW_C_DEBUG                       0x00001000L
#define VIP_HW_DEBUG__VIP_HW_D_DEBUG_MASK                  0x00002000L
#define VIP_HW_DEBUG__VIP_HW_D_DEBUG                       0x00002000L
#define VIP_HW_DEBUG__VIP_HW_E_DEBUG_MASK                  0x00004000L
#define VIP_HW_DEBUG__VIP_HW_E_DEBUG                       0x00004000L
#define VIP_HW_DEBUG__VIP_HW_F_DEBUG_MASK                  0x00008000L
#define VIP_HW_DEBUG__VIP_HW_F_DEBUG                       0x00008000L

// MEDIA_0_SCRATCH
#define MEDIA_0_SCRATCH__MEDIA_0_SCRATCH_MASK              0xffffffffL

// MEDIA_1_SCRATCH
#define MEDIA_1_SCRATCH__MEDIA_1_SCRACH_MASK               0xffffffffL

// CLK_PIN_CNTL
#define CLK_PIN_CNTL__DONT_USE_XTALIN_MASK                 0x00000010L
#define CLK_PIN_CNTL__DONT_USE_XTALIN                      0x00000010L
#define CLK_PIN_CNTL__SLOW_CLOCK_SOURCE_MASK               0x00000020L
#define CLK_PIN_CNTL__SLOW_CLOCK_SOURCE                    0x00000020L
#define CLK_PIN_CNTL__CG_CLK_TO_OUTPIN_MASK                0x00000800L
#define CLK_PIN_CNTL__CG_CLK_TO_OUTPIN                     0x00000800L
#define CLK_PIN_CNTL__CG_COUNT_UP_TO_OUTPIN_MASK           0x00001000L
#define CLK_PIN_CNTL__CG_COUNT_UP_TO_OUTPIN                0x00001000L
#define CLK_PIN_CNTL__ACCESS_REGS_IN_SUSPEND_MASK          0x00002000L
#define CLK_PIN_CNTL__ACCESS_REGS_IN_SUSPEND               0x00002000L
#define CLK_PIN_CNTL__CG_SPARE_MASK                        0x00004000L
#define CLK_PIN_CNTL__CG_SPARE                             0x00004000L
#define CLK_PIN_CNTL__SCLK_DYN_START_CNTL_MASK             0x00008000L
#define CLK_PIN_CNTL__SCLK_DYN_START_CNTL                  0x00008000L
#define CLK_PIN_CNTL__CP_CLK_RUNNING_MASK                  0x00010000L
#define CLK_PIN_CNTL__CP_CLK_RUNNING                       0x00010000L
#define CLK_PIN_CNTL__CG_SPARE_RD_MASK                     0x00060000L
#define CLK_PIN_CNTL__PWRSEQ_DELAY_MASK                    0xff000000L

// PPLL_CNTL
#define PPLL_CNTL__PPLL_RESET_MASK                         0x00000001L
#define PPLL_CNTL__PPLL_RESET                              0x00000001L
#define PPLL_CNTL__PPLL_SLEEP_MASK                         0x00000002L
#define PPLL_CNTL__PPLL_SLEEP                              0x00000002L
#define PPLL_CNTL__PPLL_TST_EN_MASK                        0x00000004L
#define PPLL_CNTL__PPLL_TST_EN                             0x00000004L
#define PPLL_CNTL__PPLL_REFCLK_SEL_MASK                    0x00000010L
#define PPLL_CNTL__PPLL_REFCLK_SEL                         0x00000010L
#define PPLL_CNTL__PPLL_FBCLK_SEL_MASK                     0x00000020L
#define PPLL_CNTL__PPLL_FBCLK_SEL                          0x00000020L
#define PPLL_CNTL__PPLL_TCPOFF_MASK                        0x00000040L
#define PPLL_CNTL__PPLL_TCPOFF                             0x00000040L
#define PPLL_CNTL__PPLL_TVCOMAX_MASK                       0x00000080L
#define PPLL_CNTL__PPLL_TVCOMAX                            0x00000080L
#define PPLL_CNTL__PPLL_PCP_MASK                           0x00000700L
#define PPLL_CNTL__PPLL_PVG_MASK                           0x00003800L
#define PPLL_CNTL__PPLL_PDC_MASK                           0x0000c000L
#define PPLL_CNTL__PPLL_ATOMIC_UPDATE_EN_MASK              0x00010000L
#define PPLL_CNTL__PPLL_ATOMIC_UPDATE_EN                   0x00010000L
#define PPLL_CNTL__PPLL_VGA_ATOMIC_UPDATE_EN_MASK          0x00020000L
#define PPLL_CNTL__PPLL_VGA_ATOMIC_UPDATE_EN               0x00020000L
#define PPLL_CNTL__PPLL_ATOMIC_UPDATE_SYNC_MASK            0x00040000L
#define PPLL_CNTL__PPLL_ATOMIC_UPDATE_SYNC                 0x00040000L
#define PPLL_CNTL__PPLL_DISABLE_AUTO_RESET_MASK            0x00080000L
#define PPLL_CNTL__PPLL_DISABLE_AUTO_RESET                 0x00080000L

// PPLL_REF_DIV
#define PPLL_REF_DIV__PPLL_REF_DIV_MASK                    0x000003ffL
#define PPLL_REF_DIV__PPLL_ATOMIC_UPDATE_W_MASK            0x00008000L
#define PPLL_REF_DIV__PPLL_ATOMIC_UPDATE_W                 0x00008000L
#define PPLL_REF_DIV__PPLL_ATOMIC_UPDATE_R_MASK            0x00008000L
#define PPLL_REF_DIV__PPLL_ATOMIC_UPDATE_R                 0x00008000L
#define PPLL_REF_DIV__PPLL_REF_DIV_SRC_MASK                0x00030000L
#define PPLL_REF_DIV__PPLL_REF_DIV_ACC_MASK                0x0ffc0000L

// SPLL_CNTL
#define SPLL_CNTL__SPLL_SLEEP_MASK                         0x00000001L
#define SPLL_CNTL__SPLL_SLEEP                              0x00000001L
#define SPLL_CNTL__SPLL_RESET_MASK                         0x00000002L
#define SPLL_CNTL__SPLL_RESET                              0x00000002L
#define SPLL_CNTL__SPLL_TST_EN_MASK                        0x00000004L
#define SPLL_CNTL__SPLL_TST_EN                             0x00000004L
#define SPLL_CNTL__SPLL_REFCLK_SEL_MASK                    0x00000010L
#define SPLL_CNTL__SPLL_REFCLK_SEL                         0x00000010L
#define SPLL_CNTL__SPLL_FBCLK_SEL_MASK                     0x00000020L
#define SPLL_CNTL__SPLL_FBCLK_SEL                          0x00000020L
#define SPLL_CNTL__SPLL_TCPOFF_MASK                        0x00000040L
#define SPLL_CNTL__SPLL_TCPOFF                             0x00000040L
#define SPLL_CNTL__SPLL_TVCOMAX_MASK                       0x00000080L
#define SPLL_CNTL__SPLL_TVCOMAX                            0x00000080L
#define SPLL_CNTL__SPLL_PCP_MASK                           0x00000700L
#define SPLL_CNTL__SPLL_PVG_MASK                           0x00003800L
#define SPLL_CNTL__SPLL_PDC_MASK                           0x0000c000L
#define SPLL_CNTL__SPLL_X1_CLK_SKEW_MASK                   0x00070000L
#define SPLL_CNTL__SPLL_X2_CLK_SKEW_MASK                   0x00700000L
#define SPLL_CNTL__SPLL_MODE_MASK                          0x0f000000L
#define SPLL_CNTL__MYCLK_SOURCED_FROM_SPLL_SEL_MASK        0x30000000L
#define SPLL_CNTL__ENABLE_MYCLK_FROM_SPLL_MASK             0x40000000L
#define SPLL_CNTL__ENABLE_MYCLK_FROM_SPLL                  0x40000000L

// SPLL_AUX_CNTL
#define SPLL_AUX_CNTL__SPLL_PDC_C_MASK                     0x00000003L
#define SPLL_AUX_CNTL__SPLL_CKINVA_MASK                    0x00000004L
#define SPLL_AUX_CNTL__SPLL_CKINVA                         0x00000004L
#define SPLL_AUX_CNTL__SPLL_CKINVC_MASK                    0x00000008L
#define SPLL_AUX_CNTL__SPLL_CKINVC                         0x00000008L
#define SPLL_AUX_CNTL__SPLL_X3_CLK_SKEW_MASK               0x00000070L
#define SPLL_AUX_CNTL__SPLL_MODEC_MASK                     0x00000180L
#define SPLL_AUX_CNTL__ATSPEED_PAD_IN_EN_MASK              0x00000800L
#define SPLL_AUX_CNTL__ATSPEED_PAD_IN_EN                   0x00000800L
#define SPLL_AUX_CNTL__TRANSIT_DONE_LENGTH_MASK            0x00001000L
#define SPLL_AUX_CNTL__TRANSIT_DONE_LENGTH                 0x00001000L
#define SPLL_AUX_CNTL__ATSPEED_ENABLE_MASK                 0x00002000L
#define SPLL_AUX_CNTL__ATSPEED_ENABLE                      0x00002000L
#define SPLL_AUX_CNTL__SPLL_REFCLK_SRC_SEL_MASK            0x0000c000L
#define SPLL_AUX_CNTL__ATSPEED_SPLL_CLOCK_COUNT_MASK       0x00ff0000L

// SCLK_CNTL
#define SCLK_CNTL__SCLK_SRC_SEL_MASK                       0x00000007L
#define SCLK_CNTL__CP_MAX_DYN_STOP_LAT_MASK                0x00000008L
#define SCLK_CNTL__CP_MAX_DYN_STOP_LAT                     0x00000008L
#define SCLK_CNTL__HDP_MAX_DYN_STOP_LAT_MASK               0x00000010L
#define SCLK_CNTL__HDP_MAX_DYN_STOP_LAT                    0x00000010L
#define SCLK_CNTL__TV_MAX_DYN_STOP_LAT_MASK                0x00000020L
#define SCLK_CNTL__TV_MAX_DYN_STOP_LAT                     0x00000020L
#define SCLK_CNTL__E2_MAX_DYN_STOP_LAT_MASK                0x00000040L
#define SCLK_CNTL__E2_MAX_DYN_STOP_LAT                     0x00000040L
#define SCLK_CNTL__SE_MAX_DYN_STOP_LAT_MASK                0x00000080L
#define SCLK_CNTL__SE_MAX_DYN_STOP_LAT                     0x00000080L
#define SCLK_CNTL__IDCT_MAX_DYN_STOP_LAT_MASK              0x00000100L
#define SCLK_CNTL__IDCT_MAX_DYN_STOP_LAT                   0x00000100L
#define SCLK_CNTL__VIP_MAX_DYN_STOP_LAT_MASK               0x00000200L
#define SCLK_CNTL__VIP_MAX_DYN_STOP_LAT                    0x00000200L
#define SCLK_CNTL__RE_MAX_DYN_STOP_LAT_MASK                0x00000400L
#define SCLK_CNTL__RE_MAX_DYN_STOP_LAT                     0x00000400L
#define SCLK_CNTL__PB_MAX_DYN_STOP_LAT_MASK                0x00000800L
#define SCLK_CNTL__PB_MAX_DYN_STOP_LAT                     0x00000800L
#define SCLK_CNTL__TAM_MAX_DYN_STOP_LAT_MASK               0x00001000L
#define SCLK_CNTL__TAM_MAX_DYN_STOP_LAT                    0x00001000L
#define SCLK_CNTL__TDM_MAX_DYN_STOP_LAT_MASK               0x00002000L
#define SCLK_CNTL__TDM_MAX_DYN_STOP_LAT                    0x00002000L
#define SCLK_CNTL__RB_MAX_DYN_STOP_LAT_MASK                0x00004000L
#define SCLK_CNTL__RB_MAX_DYN_STOP_LAT                     0x00004000L
#define SCLK_CNTL__FORCE_DISP2_MASK                        0x00008000L
#define SCLK_CNTL__FORCE_DISP2                             0x00008000L
#define SCLK_CNTL__FORCE_CP_MASK                           0x00010000L
#define SCLK_CNTL__FORCE_CP                                0x00010000L
#define SCLK_CNTL__FORCE_HDP_MASK                          0x00020000L
#define SCLK_CNTL__FORCE_HDP                               0x00020000L
#define SCLK_CNTL__FORCE_DISP1_MASK                        0x00040000L
#define SCLK_CNTL__FORCE_DISP1                             0x00040000L
#define SCLK_CNTL__FORCE_TOP_MASK                          0x00080000L
#define SCLK_CNTL__FORCE_TOP                               0x00080000L
#define SCLK_CNTL__FORCE_E2_MASK                           0x00100000L
#define SCLK_CNTL__FORCE_E2                                0x00100000L
#define SCLK_CNTL__FORCE_SE_MASK                           0x00200000L
#define SCLK_CNTL__FORCE_SE                                0x00200000L
#define SCLK_CNTL__FORCE_IDCT_MASK                         0x00400000L
#define SCLK_CNTL__FORCE_IDCT                              0x00400000L
#define SCLK_CNTL__FORCE_VIP_MASK                          0x00800000L
#define SCLK_CNTL__FORCE_VIP                               0x00800000L
#define SCLK_CNTL__FORCE_RE_MASK                           0x01000000L
#define SCLK_CNTL__FORCE_RE                                0x01000000L
#define SCLK_CNTL__FORCE_PB_MASK                           0x02000000L
#define SCLK_CNTL__FORCE_PB                                0x02000000L
#define SCLK_CNTL__FORCE_TAM_MASK                          0x04000000L
#define SCLK_CNTL__FORCE_TAM                               0x04000000L
#define SCLK_CNTL__FORCE_TDM_MASK                          0x08000000L
#define SCLK_CNTL__FORCE_TDM                               0x08000000L
#define SCLK_CNTL__FORCE_RB_MASK                           0x10000000L
#define SCLK_CNTL__FORCE_RB                                0x10000000L
#define SCLK_CNTL__FORCE_TV_SCLK_MASK                      0x20000000L
#define SCLK_CNTL__FORCE_TV_SCLK                           0x20000000L
#define SCLK_CNTL__FORCE_SUBPIC_MASK                       0x40000000L
#define SCLK_CNTL__FORCE_SUBPIC                            0x40000000L
#define SCLK_CNTL__FORCE_OV0_MASK                          0x80000000L
#define SCLK_CNTL__FORCE_OV0                               0x80000000L

// GFX_MPLL_FREQ_CONTROL
#define GFX_MPLL_FREQ_CONTROL__MPLL_PM_EN_MASK             0x00000001L
#define GFX_MPLL_FREQ_CONTROL__MPLL_PM_EN                  0x00000001L
#define GFX_MPLL_FREQ_CONTROL__MPLL_FREQ_SEL_MASK          0x00000002L
#define GFX_MPLL_FREQ_CONTROL__MPLL_FREQ_SEL               0x00000002L
#define GFX_MPLL_FREQ_CONTROL__DISP_BLANK_CNTL_MASK        0x0000000cL
#define GFX_MPLL_FREQ_CONTROL__DISP_BLANK_VAL_MASK         0x00000010L
#define GFX_MPLL_FREQ_CONTROL__DISP_BLANK_VAL              0x00000010L
#define GFX_MPLL_FREQ_CONTROL__MEM_SELF_REFRESH_ONLY_MASK  0x00000020L
#define GFX_MPLL_FREQ_CONTROL__MEM_SELF_REFRESH_ONLY       0x00000020L
#define GFX_MPLL_FREQ_CONTROL__PM_SWITCHMCLK_BUSY_MASK     0x00000040L
#define GFX_MPLL_FREQ_CONTROL__PM_SWITCHMCLK_BUSY          0x00000040L
#define GFX_MPLL_FREQ_CONTROL__PM_FREQ_CNTL_RESET_MASK     0x00000080L
#define GFX_MPLL_FREQ_CONTROL__PM_FREQ_CNTL_RESET          0x00000080L
#define GFX_MPLL_FREQ_CONTROL__PM_MPLL_DELTA_FRACTION_MASK 0x00000700L
#define GFX_MPLL_FREQ_CONTROL__PM_MPLL_DELTA_INTEGER_MASK  0x0001f800L
#define GFX_MPLL_FREQ_CONTROL__PM_MPLL_PVG_MASK            0x000e0000L
#define GFX_MPLL_FREQ_CONTROL__PM_MPLL_STEP_SIZE_MASK      0x00300000L
#define GFX_MPLL_FREQ_CONTROL__PM_MPLL_DELAY_MASK          0x01c00000L
#define GFX_MPLL_FREQ_CONTROL__CG_SPARE_RW_0_MASK          0x10000000L
#define GFX_MPLL_FREQ_CONTROL__CG_SPARE_RW_0               0x10000000L
#define GFX_MPLL_FREQ_CONTROL__PM_MPLL_SLOWMCLK_MASK       0x20000000L
#define GFX_MPLL_FREQ_CONTROL__PM_MPLL_SLOWMCLK            0x20000000L
#define GFX_MPLL_FREQ_CONTROL__CG_SPARE_RW_1_MASK          0xc0000000L

// GFX_MPLL_SEQ_CONTROL
#define GFX_MPLL_SEQ_CONTROL__MPLL_RESET_PULSE_WIDTH_MASK  0x0000001fL
#define GFX_MPLL_SEQ_CONTROL__MDLL_RESET_PULSE_WIDTH_MASK  0x000000e0L
#define GFX_MPLL_SEQ_CONTROL__MPLL_LOCK_TIME_MASK          0x000fff00L
#define GFX_MPLL_SEQ_CONTROL__MDLL_LOCK_TIME_MASK          0x07f00000L
#define GFX_MPLL_SEQ_CONTROL__CG_SPARE_R_0_MASK            0xf8000000L

// GFX_MPLL_DIV_CONTROL
#define GFX_MPLL_DIV_CONTROL__PM_MPLL_REF_DIV_MASK         0x000003ffL
#define GFX_MPLL_DIV_CONTROL__CG_SPARE_RW_2_MASK           0x00000c00L
#define GFX_MPLL_DIV_CONTROL__PM_MPLL_FB_DIV_FRACTION_MASK 0x00007000L
#define GFX_MPLL_DIV_CONTROL__CG_SPARE_RW_3_MASK           0x00008000L
#define GFX_MPLL_DIV_CONTROL__CG_SPARE_RW_3                0x00008000L
#define GFX_MPLL_DIV_CONTROL__PM_MPLL_FB_DIV_MASK          0x07ff0000L
#define GFX_MPLL_DIV_CONTROL__CG_SPARE_R_1_MASK            0x08000000L
#define GFX_MPLL_DIV_CONTROL__CG_SPARE_R_1                 0x08000000L
#define GFX_MPLL_DIV_CONTROL__PM_MPLL_POST_DIV_MASK        0x70000000L
#define GFX_MPLL_DIV_CONTROL__CG_SPARE_RW_4_MASK           0x80000000L
#define GFX_MPLL_DIV_CONTROL__CG_SPARE_RW_4                0x80000000L

// PWRMAN_MISC
#define PWRMAN_MISC__EN_MC_IDLE_COND_MASK                  0x00000001L
#define PWRMAN_MISC__EN_MC_IDLE_COND                       0x00000001L
#define PWRMAN_MISC__MC_IDLE_LAT_MASK                      0x00000006L
#define PWRMAN_MISC__EN_STOP_IMPORT_CLKS_IN_SUSPEND_MASK   0x00000008L
#define PWRMAN_MISC__EN_STOP_IMPORT_CLKS_IN_SUSPEND        0x00000008L
#define PWRMAN_MISC__NB_TESTCLK_SEL_MASK                   0x00070000L
#define PWRMAN_MISC__CG_NB_TESTCLK_SEL_MASK                0x00080000L
#define PWRMAN_MISC__CG_NB_TESTCLK_SEL                     0x00080000L
#define PWRMAN_MISC__CG_SPARE_B_A5_MASK                    0x03f00000L
#define PWRMAN_MISC__CG_SPARE_RD_B_MASK                    0xfc000000L

// CG_PERF_COUNT0
#define CG_PERF_COUNT0__PERF_COUNT0_L_MASK                 0xffffffffL

// CG_PERF_COUNT1
#define CG_PERF_COUNT1__PERF_COUNT1_L_MASK                 0xffffffffL

// CG_PERF_COUNT_H
#define CG_PERF_COUNT_H__PERF_COUNT0_EVENT_SEL_MASK        0x000000ffL
#define CG_PERF_COUNT_H__PERF_COUNT1_EVENT_SEL_MASK        0x0000ff00L
#define CG_PERF_COUNT_H__PERF_COUNT0_H_MASK                0x00ff0000L
#define CG_PERF_COUNT_H__PERF_COUNT1_H_MASK                0xff000000L

// CG_PERF_CNTL
#define CG_PERF_CNTL__PERF_COUNT_USE_NB_GLOBAL_MASK        0x00000001L
#define CG_PERF_CNTL__PERF_COUNT_USE_NB_GLOBAL             0x00000001L
#define CG_PERF_CNTL__PERF_COUNT_SHADOW_WR_MASK            0x00000002L
#define CG_PERF_CNTL__PERF_COUNT_SHADOW_WR                 0x00000002L
#define CG_PERF_CNTL__PERF_COUNT0_EN_MASK                  0x00000004L
#define CG_PERF_CNTL__PERF_COUNT0_EN                       0x00000004L
#define CG_PERF_CNTL__PERF_COUNT1_EN_MASK                  0x00000008L
#define CG_PERF_CNTL__PERF_COUNT1_EN                       0x00000008L
#define CG_PERF_CNTL__PERF_COUNT0_CLR_MASK                 0x00000010L
#define CG_PERF_CNTL__PERF_COUNT0_CLR                      0x00000010L
#define CG_PERF_CNTL__PERF_COUNT1_CLR_MASK                 0x00000020L
#define CG_PERF_CNTL__PERF_COUNT1_CLR                      0x00000020L

// TV_PLL_FINE_CNTL
#define TV_PLL_FINE_CNTL__TV_M1_MASK                       0x000007ffL
#define TV_PLL_FINE_CNTL__TV_N1_MASK                       0x003ff800L
#define TV_PLL_FINE_CNTL__TV_DIVIDER_SEL_MASK              0x00400000L
#define TV_PLL_FINE_CNTL__TV_DIVIDER_SEL                   0x00400000L
#define TV_PLL_FINE_CNTL__TV_MNFLIP_REQ_MASK               0x00800000L
#define TV_PLL_FINE_CNTL__TV_MNFLIP_REQ                    0x00800000L
#define TV_PLL_FINE_CNTL__TV_MNFLIP_DONE_MASK              0x01000000L
#define TV_PLL_FINE_CNTL__TV_MNFLIP_DONE                   0x01000000L
#define TV_PLL_FINE_CNTL__TV_SLIP_REQ_MASK                 0x02000000L
#define TV_PLL_FINE_CNTL__TV_SLIP_REQ                      0x02000000L
#define TV_PLL_FINE_CNTL__TV_SLIP_DONE_MASK                0x04000000L
#define TV_PLL_FINE_CNTL__TV_SLIP_DONE                     0x04000000L
#define TV_PLL_FINE_CNTL__TV_MNFLIP_EN_MASK                0x08000000L
#define TV_PLL_FINE_CNTL__TV_MNFLIP_EN                     0x08000000L
#define TV_PLL_FINE_CNTL__TV_SLIP_COUNT_MASK               0xf0000000L

// TV_PLL_CNTL
#define TV_PLL_CNTL__TV_M0_LO_MASK                         0x000000ffL
#define TV_PLL_CNTL__TV_N0_LO_MASK                         0x0001ff00L
#define TV_PLL_CNTL__TV_M0_HI_MASK                         0x001c0000L
#define TV_PLL_CNTL__TV_N0_HI_MASK                         0x00600000L
#define TV_PLL_CNTL__TV_SLIP_EN_MASK                       0x00800000L
#define TV_PLL_CNTL__TV_SLIP_EN                            0x00800000L
#define TV_PLL_CNTL__TV_P_MASK                             0x0f000000L
#define TV_PLL_CNTL__TV_DTO_EN_MASK                        0x10000000L
#define TV_PLL_CNTL__TV_DTO_EN                             0x10000000L
#define TV_PLL_CNTL__TV_DTO_TYPE_MASK                      0x20000000L
#define TV_PLL_CNTL__TV_DTO_TYPE                           0x20000000L
#define TV_PLL_CNTL__TV_REF_CLK_SEL_MASK                   0x40000000L
#define TV_PLL_CNTL__TV_REF_CLK_SEL                        0x40000000L

// TV_PLL_CNTL1
#define TV_PLL_CNTL1__TVPLL_RESET_MASK                     0x00000002L
#define TV_PLL_CNTL1__TVPLL_RESET                          0x00000002L
#define TV_PLL_CNTL1__TVPLL_SLEEP_MASK                     0x00000008L
#define TV_PLL_CNTL1__TVPLL_SLEEP                          0x00000008L
#define TV_PLL_CNTL1__TVPLL_REFCLK_SEL_MASK                0x00000010L
#define TV_PLL_CNTL1__TVPLL_REFCLK_SEL                     0x00000010L
#define TV_PLL_CNTL1__TVPLL_FBCLK_SEL_MASK                 0x00000020L
#define TV_PLL_CNTL1__TVPLL_FBCLK_SEL                      0x00000020L
#define TV_PLL_CNTL1__TVPLL_TCPOFF_MASK                    0x00000040L
#define TV_PLL_CNTL1__TVPLL_TCPOFF                         0x00000040L
#define TV_PLL_CNTL1__TVPLL_TVCOMAX_MASK                   0x00000080L
#define TV_PLL_CNTL1__TVPLL_TVCOMAX                        0x00000080L
#define TV_PLL_CNTL1__TVPCP_MASK                           0x00000700L
#define TV_PLL_CNTL1__TVPVG_MASK                           0x00003800L
#define TV_PLL_CNTL1__TVPDC_MASK                           0x0000c000L
#define TV_PLL_CNTL1__TVPLL_FB_DIV_FRACTION_MASK           0x00070000L
#define TV_PLL_CNTL1__TVPLL_FB_DIV_FRACTION_UPDATE_MASK    0x00080000L
#define TV_PLL_CNTL1__TVPLL_FB_DIV_FRACTION_UPDATE         0x00080000L
#define TV_PLL_CNTL1__TVPLL_FB_DIV_FRACTION_EN_MASK        0x00100000L
#define TV_PLL_CNTL1__TVPLL_FB_DIV_FRACTION_EN             0x00100000L
#define TV_PLL_CNTL1__TVCLK_SRC_SEL_MASK                   0x40000000L
#define TV_PLL_CNTL1__TVCLK_SRC_SEL                        0x40000000L
#define TV_PLL_CNTL1__TVPLL_TEST_MASK                      0x80000000L
#define TV_PLL_CNTL1__TVPLL_TEST                           0x80000000L

// TV_DTO_INCREMENTS
#define TV_DTO_INCREMENTS__TV_DTO_INC0_MASK                0x0000ffffL
#define TV_DTO_INCREMENTS__TV_DTO_INC1_MASK                0xffff0000L

// P2PLL_CNTL
#define P2PLL_CNTL__P2PLL_RESET_MASK                       0x00000001L
#define P2PLL_CNTL__P2PLL_RESET                            0x00000001L
#define P2PLL_CNTL__P2PLL_SLEEP_MASK                       0x00000002L
#define P2PLL_CNTL__P2PLL_SLEEP                            0x00000002L
#define P2PLL_CNTL__P2PLL_TST_EN_MASK                      0x00000004L
#define P2PLL_CNTL__P2PLL_TST_EN                           0x00000004L
#define P2PLL_CNTL__P2PLL_REFCLK_SEL_MASK                  0x00000010L
#define P2PLL_CNTL__P2PLL_REFCLK_SEL                       0x00000010L
#define P2PLL_CNTL__P2PLL_FBCLK_SEL_MASK                   0x00000020L
#define P2PLL_CNTL__P2PLL_FBCLK_SEL                        0x00000020L
#define P2PLL_CNTL__P2PLL_TCPOFF_MASK                      0x00000040L
#define P2PLL_CNTL__P2PLL_TCPOFF                           0x00000040L
#define P2PLL_CNTL__P2PLL_TVCOMAX_MASK                     0x00000080L
#define P2PLL_CNTL__P2PLL_TVCOMAX                          0x00000080L
#define P2PLL_CNTL__P2PLL_PCP_MASK                         0x00000700L
#define P2PLL_CNTL__P2PLL_PVG_MASK                         0x00003800L
#define P2PLL_CNTL__P2PLL_PDC_MASK                         0x0000c000L
#define P2PLL_CNTL__P2PLL_ATOMIC_UPDATE_EN_MASK            0x00010000L
#define P2PLL_CNTL__P2PLL_ATOMIC_UPDATE_EN                 0x00010000L
#define P2PLL_CNTL__P2PLL_ATOMIC_UPDATE_SYNC_MASK          0x00040000L
#define P2PLL_CNTL__P2PLL_ATOMIC_UPDATE_SYNC               0x00040000L
#define P2PLL_CNTL__P2PLL_DISABLE_AUTO_RESET_MASK          0x00080000L
#define P2PLL_CNTL__P2PLL_DISABLE_AUTO_RESET               0x00080000L

// P2PLL_REF_DIV
#define P2PLL_REF_DIV__P2PLL_REF_DIV_MASK                  0x000003ffL
#define P2PLL_REF_DIV__P2PLL_ATOMIC_UPDATE_W_MASK          0x00008000L
#define P2PLL_REF_DIV__P2PLL_ATOMIC_UPDATE_W               0x00008000L
#define P2PLL_REF_DIV__P2PLL_ATOMIC_UPDATE_R_MASK          0x00008000L
#define P2PLL_REF_DIV__P2PLL_ATOMIC_UPDATE_R               0x00008000L
#define P2PLL_REF_DIV__P2PLL_REF_DIV_SRC_MASK              0x00030000L

// CG_TEST_MACRO_RW_WRITE_U1
#define CG_TEST_MACRO_RW_WRITE_U1__TEST_MACRO_RW_WRITE1_MASK  0x00003fffL
#define CG_TEST_MACRO_RW_WRITE_U1__TEST_MACRO_RW_WRITE2_MASK  0x0fffc000L

// CG_TEST_MACRO_RW_READ_U1
#define CG_TEST_MACRO_RW_READ_U1__TEST_MACRO_RW_READ1_MASK 0x0000ffffL
#define CG_TEST_MACRO_RW_READ_U1__TEST_MACRO_RW_READ2_MASK 0xffff0000L

// CG_TEST_MACRO_RW_DATA_U1
#define CG_TEST_MACRO_RW_DATA_U1__TEST_MACRO_RW_DATA_MASK  0xffffffffL

// CG_TEST_MACRO_RW_CNTL_U1
#define CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_START_MASK 0x00000001L
#define CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_START      0x00000001L
#define CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_OP_MASK    0x0000000eL
#define CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_MODE_MASK  0x00000030L
#define CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_MISMATCH_SEL_MASK 0x00007fc0L
#define CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_MISMATCH_MASK 0x00008000L
#define CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_MISMATCH   0x00008000L
#define CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_ENABLE_MASK   0x00010000L
#define CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_ENABLE     0x00010000L
#define CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_SCLK_NEG_ENABLE_MASK 0x00020000L
#define CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_SCLK_NEG_ENABLE 0x00020000L

// TEMPERATURE_CNTL
#define TEMPERATURE_CNTL__TEMPERATURE_CNTL_EN_MASK         0x00000001L
#define TEMPERATURE_CNTL__TEMPERATURE_CNTL_EN              0x00000001L
#define TEMPERATURE_CNTL__GFX_CORE_TEMPERATURE_R_MASK      0x000003f0L
#define TEMPERATURE_CNTL__TEMPERATURE_CNTL_FBDIV_STEP_DELAY_MASK 0xffff0000L

// SSPLL_CNTL
#define SSPLL_CNTL__SSPLL_RESET_MASK                       0x00000001L
#define SSPLL_CNTL__SSPLL_RESET                            0x00000001L
#define SSPLL_CNTL__SSPLL_SLEEP_MASK                       0x00000002L
#define SSPLL_CNTL__SSPLL_SLEEP                            0x00000002L
#define SSPLL_CNTL__SSPLL_TST_EN_MASK                      0x00000004L
#define SSPLL_CNTL__SSPLL_TST_EN                           0x00000004L
#define SSPLL_CNTL__SSPLL_REFCLK_SEL_MASK                  0x00000010L
#define SSPLL_CNTL__SSPLL_REFCLK_SEL                       0x00000010L
#define SSPLL_CNTL__SSPLL_FBCLK_SEL_MASK                   0x00000020L
#define SSPLL_CNTL__SSPLL_FBCLK_SEL                        0x00000020L
#define SSPLL_CNTL__SSPLL_TCPOFF_MASK                      0x00000040L
#define SSPLL_CNTL__SSPLL_TCPOFF                           0x00000040L
#define SSPLL_CNTL__SSPLL_TVCOMAX_MASK                     0x00000080L
#define SSPLL_CNTL__SSPLL_TVCOMAX                          0x00000080L
#define SSPLL_CNTL__SSPLL_PCP_MASK                         0x00000700L
#define SSPLL_CNTL__SSPLL_PVG_MASK                         0x00003800L
#define SSPLL_CNTL__SSPLL_PDC_MASK                         0x0000c000L
#define SSPLL_CNTL__SSPLL_ATOMIC_UPDATE_EN_MASK            0x00010000L
#define SSPLL_CNTL__SSPLL_ATOMIC_UPDATE_EN                 0x00010000L
#define SSPLL_CNTL__SSPLL_ATOMIC_UPDATE_SYNC_MASK          0x00040000L
#define SSPLL_CNTL__SSPLL_ATOMIC_UPDATE_SYNC               0x00040000L

// SSPLL_REF_DIV
#define SSPLL_REF_DIV__SSPLL_REF_DIV_MASK                  0x000003ffL
#define SSPLL_REF_DIV__SSPLL_ATOMIC_UPDATE_W_MASK          0x00008000L
#define SSPLL_REF_DIV__SSPLL_ATOMIC_UPDATE_W               0x00008000L
#define SSPLL_REF_DIV__SSPLL_ATOMIC_UPDATE_R_MASK          0x00008000L
#define SSPLL_REF_DIV__SSPLL_ATOMIC_UPDATE_R               0x00008000L
#define SSPLL_REF_DIV__SSPLL_REF_DIV_SRC_MASK              0x00030000L

// SSPLL_DIV_0
#define SSPLL_DIV_0__SSPLL_FB_DIV_MASK                     0x000007ffL
#define SSPLL_DIV_0__SSPLL_FB_DIV_FRACTION_MASK            0x00007000L
#define SSPLL_DIV_0__SSPLL_ATOMIC_UPDATE_W_MASK            0x00008000L
#define SSPLL_DIV_0__SSPLL_ATOMIC_UPDATE_W                 0x00008000L
#define SSPLL_DIV_0__SSPLL_ATOMIC_UPDATE_R_MASK            0x00008000L
#define SSPLL_DIV_0__SSPLL_ATOMIC_UPDATE_R                 0x00008000L
#define SSPLL_DIV_0__SSPLL_POST_DIV_MASK                   0x00070000L
#define SSPLL_DIV_0__SSPLL_FB_DIV_FRACTION_UPDATE_MASK     0x10000000L
#define SSPLL_DIV_0__SSPLL_FB_DIV_FRACTION_UPDATE          0x10000000L

// SS_INT_CNTL
#define SS_INT_CNTL__SS_INT_EN_MASK                        0x00000001L
#define SS_INT_CNTL__SS_INT_EN                             0x00000001L
#define SS_INT_CNTL__SS_INT_SEL_MASK                       0x00000002L
#define SS_INT_CNTL__SS_INT_SEL                            0x00000002L
#define SS_INT_CNTL__SS_STEP_SIZE_MASK                     0x0000000cL
#define SS_INT_CNTL__SS_DELAY_MASK                         0x00000070L
#define SS_INT_CNTL__SS_DELTA_FRACTION_MASK                0x00000700L
#define SS_INT_CNTL__SS_DELTA_INTEGER_MASK                 0x0003f000L
#define SS_INT_CNTL__SS_PLL_DISPLAY_SRC_MASK               0x00040000L
#define SS_INT_CNTL__SS_PLL_DISPLAY_SRC                    0x00040000L
#define SS_INT_CNTL__SS_PLL_DISPLAY_EN_MASK                0x00080000L
#define SS_INT_CNTL__SS_PLL_DISPLAY_EN                     0x00080000L
#define SS_INT_CNTL__SS_BUF_GENLOCK_EN_MASK                0x00100000L
#define SS_INT_CNTL__SS_BUF_GENLOCK_EN                     0x00100000L
#define SS_INT_CNTL__SS_BUF_GENLOCK_THRESHOLD_MASK         0x00e00000L
#define SS_INT_CNTL__SS_BUF_GENLOCK_DURATION_MASK          0x07000000L
#define SS_INT_CNTL__SS_BUF_GENLOCK_HEIGHT_MASK            0x38000000L
#define SS_INT_CNTL__SS_BUF_GENLOCK_THRESHOLD_1_MASK       0xc0000000L

// SS_TST_CNTL
#define SS_TST_CNTL__SS_TST_CNT_MASK                       0x00003fffL
#define SS_TST_CNTL__SS_TST_CNT_SEL_MASK                   0x00030000L
#define SS_TST_CNTL__SS_TST_GE_MASK                        0x00100000L
#define SS_TST_CNTL__SS_TST_GE                             0x00100000L
#define SS_TST_CNTL__SS_TST_LE_MASK                        0x00200000L
#define SS_TST_CNTL__SS_TST_LE                             0x00200000L
#define SS_TST_CNTL__SS_TST_DEC_MASK                       0x00400000L
#define SS_TST_CNTL__SS_TST_DEC                            0x00400000L
#define SS_TST_CNTL__ANALOG_MON_SS_MASK                    0x00800000L
#define SS_TST_CNTL__ANALOG_MON_SS                         0x00800000L
#define SS_TST_CNTL__EXP_IMPLEMENTATION_EN_MASK            0x01000000L
#define SS_TST_CNTL__EXP_IMPLEMENTATION_EN                 0x01000000L
#define SS_TST_CNTL__SS_ANTIGLITCH_EN_MASK                 0x02000000L
#define SS_TST_CNTL__SS_ANTIGLITCH_EN                      0x02000000L
#define SS_TST_CNTL__HDP_BUSY_HALF_SCLK_MASK               0x04000000L
#define SS_TST_CNTL__HDP_BUSY_HALF_SCLK                    0x04000000L
#define SS_TST_CNTL__EN_DIV2_HALF_SCLK_MASK                0x08000000L
#define SS_TST_CNTL__EN_DIV2_HALF_SCLK                     0x08000000L
#define SS_TST_CNTL__SS_BUF_GENLOCK_HEIGHT_FRACTION_MASK   0x70000000L
#define SS_TST_CNTL__SS_TST_MODE_MASK                      0x80000000L
#define SS_TST_CNTL__SS_TST_MODE                           0x80000000L

// SCLK_MORE_CNTL
#define SCLK_MORE_CNTL__DISPREGS_MAX_DYN_STOP_LAT_MASK     0x00000001L
#define SCLK_MORE_CNTL__DISPREGS_MAX_DYN_STOP_LAT          0x00000001L
#define SCLK_MORE_CNTL__MC_GUI_MAX_DYN_STOP_LAT_MASK       0x00000002L
#define SCLK_MORE_CNTL__MC_GUI_MAX_DYN_STOP_LAT            0x00000002L
#define SCLK_MORE_CNTL__MC_HOST_MAX_DYN_STOP_LAT_MASK      0x00000004L
#define SCLK_MORE_CNTL__MC_HOST_MAX_DYN_STOP_LAT           0x00000004L
#define SCLK_MORE_CNTL__SCLK_MULTI_THROTTLE_EN_MASK        0x00000008L
#define SCLK_MORE_CNTL__SCLK_MULTI_THROTTLE_EN             0x00000008L
#define SCLK_MORE_CNTL__SCLK_ENGINE_IDLE_DIV_MASK          0x00000030L
#define SCLK_MORE_CNTL__SCLK_ENGINE_IDLE_VOLTAGE_MASK      0x000000c0L
#define SCLK_MORE_CNTL__FORCE_DISPREGS_MASK                0x00000100L
#define SCLK_MORE_CNTL__FORCE_DISPREGS                     0x00000100L
#define SCLK_MORE_CNTL__FORCE_MC_GUI_MASK                  0x00000200L
#define SCLK_MORE_CNTL__FORCE_MC_GUI                       0x00000200L
#define SCLK_MORE_CNTL__FORCE_MC_HOST_MASK                 0x00000400L
#define SCLK_MORE_CNTL__FORCE_MC_HOST                      0x00000400L
#define SCLK_MORE_CNTL__SOFT_CNTL_THROT_SCLK_VOLT_WAIT_IDLE_MASK 0x00000800L
#define SCLK_MORE_CNTL__SOFT_CNTL_THROT_SCLK_VOLT_WAIT_IDLE 0x00000800L
#define SCLK_MORE_CNTL__STOP_SCLK_EN_MASK                  0x00001000L
#define SCLK_MORE_CNTL__STOP_SCLK_EN                       0x00001000L
#define SCLK_MORE_CNTL__STOP_SCLK_A_MASK                   0x00002000L
#define SCLK_MORE_CNTL__STOP_SCLK_A                        0x00002000L
#define SCLK_MORE_CNTL__STOP_SCLK_B_MASK                   0x00004000L
#define SCLK_MORE_CNTL__STOP_SCLK_B                        0x00004000L
#define SCLK_MORE_CNTL__STOP_SCLK_C_MASK                   0x00008000L
#define SCLK_MORE_CNTL__STOP_SCLK_C                        0x00008000L
#define SCLK_MORE_CNTL__EN_SLOW_DOWN_SCLK_MASK             0x00010000L
#define SCLK_MORE_CNTL__EN_SLOW_DOWN_SCLK                  0x00010000L
#define SCLK_MORE_CNTL__EN_VOLTAGE_DROP_MASK               0x00020000L
#define SCLK_MORE_CNTL__EN_VOLTAGE_DROP                    0x00020000L
#define SCLK_MORE_CNTL__TVFB_SOFT_RESET_MASK               0x00040000L
#define SCLK_MORE_CNTL__TVFB_SOFT_RESET                    0x00040000L
#define SCLK_MORE_CNTL__VOLTAGE_DROP_SYNC_MASK             0x00080000L
#define SCLK_MORE_CNTL__VOLTAGE_DROP_SYNC                  0x00080000L
#define SCLK_MORE_CNTL__VOLTAGE_DELAY_SEL_MASK             0x00300000L
#define SCLK_MORE_CNTL__IDLE_DELAY_HALF_SCLK_MASK          0x00400000L
#define SCLK_MORE_CNTL__IDLE_DELAY_HALF_SCLK               0x00400000L
#define SCLK_MORE_CNTL__AGP_BUSY_HALF_SCLK_MASK            0x00800000L
#define SCLK_MORE_CNTL__AGP_BUSY_HALF_SCLK                 0x00800000L
#define SCLK_MORE_CNTL__EN_CLK27M_FOR_PLL_A5_MASK          0x01000000L
#define SCLK_MORE_CNTL__EN_CLK27M_FOR_PLL_A5               0x01000000L
#define SCLK_MORE_CNTL__MC_EN_SLOW_DOWN_SCLK_MASK          0x02000000L
#define SCLK_MORE_CNTL__MC_EN_SLOW_DOWN_SCLK               0x02000000L
#define SCLK_MORE_CNTL__TWOD_EN_SLOW_DOWN_SCLK_MASK        0x04000000L
#define SCLK_MORE_CNTL__TWOD_EN_SLOW_DOWN_SCLK             0x04000000L
#define SCLK_MORE_CNTL__SOFT_CNTL_THROT_SCLK_VOLT_MASK     0x08000000L
#define SCLK_MORE_CNTL__SOFT_CNTL_THROT_SCLK_VOLT          0x08000000L
#define SCLK_MORE_CNTL__MC_FULLSPEED_DELAY_MASK            0xf0000000L

// TEMPERATURE_CNTL_TABLE_ENTRY_0
#define TEMPERATURE_CNTL_TABLE_ENTRY_0__TEMPERATURE_0_CNTL_SPLL_FBDIV_MASK 0x000000ffL
#define TEMPERATURE_CNTL_TABLE_ENTRY_0__TEMPERATURE_0_CNTL_SPLL_VCO_MASK 0x00000700L
#define TEMPERATURE_CNTL_TABLE_ENTRY_0__TEMPERATURE_0_CNTL_ENG_IDLE_DIV_MASK 0x00003000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_0__TEMPERATURE_0_CNTL_ENG_IDLE_VOLT_MASK 0x0000c000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_0__TEMPERATURE_0_MASK 0x003f0000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_0__TEMPERATURE_UP_HYST_MASK 0x07000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_0__TEMPERATURE_DOWN_HYST_MASK 0x70000000L

// TEMPERATURE_CNTL_TABLE_ENTRY_1
#define TEMPERATURE_CNTL_TABLE_ENTRY_1__TEMPERATURE_1_CNTL_SPLL_FBDIV_MASK 0x000000ffL
#define TEMPERATURE_CNTL_TABLE_ENTRY_1__TEMPERATURE_1_CNTL_SPLL_VCO_MASK 0x00000700L
#define TEMPERATURE_CNTL_TABLE_ENTRY_1__TEMPERATURE_1_CNTL_ENG_IDLE_DIV_MASK 0x00003000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_1__TEMPERATURE_1_CNTL_ENG_IDLE_VOLT_MASK 0x0000c000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_1__TEMPERATURE_1_MASK 0x003f0000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_1__SPLL_FB_DIV_R_MASK 0xff000000L

// TEMPERATURE_CNTL_TABLE_ENTRY_2
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__TEMPERATURE_2_CNTL_SPLL_FBDIV_MASK 0x000000ffL
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__TEMPERATURE_2_CNTL_SPLL_VCO_MASK 0x00000700L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__TEMPERATURE_2_CNTL_ENG_IDLE_DIV_MASK 0x00003000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__TEMPERATURE_2_CNTL_ENG_IDLE_VOLT_MASK 0x0000c000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__TEMPERATURE_2_MASK 0x003f0000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_CPW_FIFO_EXCLUDE_MASK 0x01000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_CPW_FIFO_EXCLUDE 0x01000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_CPR_FIFO_EXCLUDE_MASK 0x02000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_CPR_FIFO_EXCLUDE 0x02000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_SER_FIFO_EXCLUDE_MASK 0x04000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_SER_FIFO_EXCLUDE 0x04000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_HDP_FIFO_EXCLUDE_MASK 0x08000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_HDP_FIFO_EXCLUDE 0x08000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_RB0_FIFO_EXCLUDE_MASK 0x10000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_RB0_FIFO_EXCLUDE 0x10000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_RB1_FIFO_EXCLUDE_MASK 0x20000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_RB1_FIFO_EXCLUDE 0x20000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_PPR_FIFO_EXCLUDE_MASK 0x40000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_PPR_FIFO_EXCLUDE 0x40000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_READ_FIFO_EXCLUDE_MASK 0x80000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_2__CG_MC_SLOWDOWN_READ_FIFO_EXCLUDE 0x80000000L

// TEMPERATURE_CNTL_TABLE_ENTRY_3
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__TEMPERATURE_3_CNTL_SPLL_FBDIV_MASK 0x000000ffL
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__TEMPERATURE_3_CNTL_SPLL_VCO_MASK 0x00000700L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__TEMPERATURE_3_CNTL_ENG_IDLE_DIV_MASK 0x00003000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__TEMPERATURE_3_CNTL_ENG_IDLE_VOLT_MASK 0x0000c000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__TEMPERATURE_3_MASK 0x003f0000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__ENGINE_DYNCLK_PAIRING_EN_MASK 0x01000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__ENGINE_DYNCLK_PAIRING_EN 0x01000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_SE_RE_MASK 0x02000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_SE_RE  0x02000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_SE_TAM_MASK 0x04000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_SE_TAM 0x04000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_SE_TIM_MASK 0x08000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_SE_TIM 0x08000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_SE_TDM_MASK 0x10000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_SE_TDM 0x10000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_SE_PB_MASK 0x20000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_SE_PB  0x20000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_RE_TAM_MASK 0x40000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_RE_TAM 0x40000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_RE_TIM_MASK 0x80000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_3__DYNCLK_PAIR_RE_TIM 0x80000000L

// TEMPERATURE_CNTL_TABLE_ENTRY_4
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__TEMPERATURE_4_CNTL_SPLL_FBDIV_MASK 0x000000ffL
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__TEMPERATURE_4_CNTL_SPLL_VCO_MASK 0x00000700L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__TEMPERATURE_4_CNTL_ENG_IDLE_DIV_MASK 0x00003000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__TEMPERATURE_4_CNTL_ENG_IDLE_VOLT_MASK 0x0000c000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__TEMPERATURE_4_MASK 0x003f0000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_RE_TDM_MASK 0x01000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_RE_TDM 0x01000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_RE_PB_MASK 0x02000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_RE_PB  0x02000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TAM_TIM_MASK 0x04000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TAM_TIM 0x04000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TAM_TDM_MASK 0x08000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TAM_TDM 0x08000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TAM_PB_MASK 0x10000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TAM_PB 0x10000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TIM_TDM_MASK 0x20000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TIM_TDM 0x20000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TIM_PB_MASK 0x40000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TIM_PB 0x40000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TDM_PB_MASK 0x80000000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_4__DYNCLK_PAIR_TDM_PB 0x80000000L

// TEMPERATURE_CNTL_TABLE_ENTRY_5
#define TEMPERATURE_CNTL_TABLE_ENTRY_5__TEMPERATURE_5_CNTL_SPLL_FBDIV_MASK 0x000000ffL
#define TEMPERATURE_CNTL_TABLE_ENTRY_5__TEMPERATURE_5_CNTL_SPLL_VCO_MASK 0x00000700L
#define TEMPERATURE_CNTL_TABLE_ENTRY_5__TEMPERATURE_5_CNTL_ENG_IDLE_DIV_MASK 0x00003000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_5__TEMPERATURE_5_CNTL_ENG_IDLE_VOLT_MASK 0x0000c000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_5__TEMPERATURE_5_MASK 0x003f0000L

// TEMPERATURE_CNTL_TABLE_ENTRY_6
#define TEMPERATURE_CNTL_TABLE_ENTRY_6__TEMPERATURE_6_CNTL_SPLL_FBDIV_MASK 0x000000ffL
#define TEMPERATURE_CNTL_TABLE_ENTRY_6__TEMPERATURE_6_CNTL_SPLL_VCO_MASK 0x00000700L
#define TEMPERATURE_CNTL_TABLE_ENTRY_6__TEMPERATURE_6_CNTL_ENG_IDLE_DIV_MASK 0x00003000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_6__TEMPERATURE_6_CNTL_ENG_IDLE_VOLT_MASK 0x0000c000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_6__TEMPERATURE_6_MASK 0x003f0000L

// TEMPERATURE_CNTL_TABLE_ENTRY_7
#define TEMPERATURE_CNTL_TABLE_ENTRY_7__TEMPERATURE_7_CNTL_SPLL_FBDIV_MASK 0x000000ffL
#define TEMPERATURE_CNTL_TABLE_ENTRY_7__TEMPERATURE_7_CNTL_SPLL_VCO_MASK 0x00000700L
#define TEMPERATURE_CNTL_TABLE_ENTRY_7__TEMPERATURE_7_CNTL_ENG_IDLE_DIV_MASK 0x00003000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_7__TEMPERATURE_7_CNTL_ENG_IDLE_VOLT_MASK 0x0000c000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_7__TEMPERATURE_7_MASK 0x003f0000L

// TEMPERATURE_CNTL_TABLE_ENTRY_8
#define TEMPERATURE_CNTL_TABLE_ENTRY_8__TEMPERATURE_8_CNTL_SPLL_FBDIV_MASK 0x000000ffL
#define TEMPERATURE_CNTL_TABLE_ENTRY_8__TEMPERATURE_8_CNTL_SPLL_VCO_MASK 0x00000700L
#define TEMPERATURE_CNTL_TABLE_ENTRY_8__TEMPERATURE_8_CNTL_ENG_IDLE_DIV_MASK 0x00003000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_8__TEMPERATURE_8_CNTL_ENG_IDLE_VOLT_MASK 0x0000c000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_8__TEMPERATURE_8_MASK 0x003f0000L

// TEMPERATURE_CNTL_TABLE_ENTRY_9
#define TEMPERATURE_CNTL_TABLE_ENTRY_9__TEMPERATURE_9_CNTL_SPLL_FBDIV_MASK 0x000000ffL
#define TEMPERATURE_CNTL_TABLE_ENTRY_9__TEMPERATURE_9_CNTL_SPLL_VCO_MASK 0x00000700L
#define TEMPERATURE_CNTL_TABLE_ENTRY_9__TEMPERATURE_9_CNTL_ENG_IDLE_DIV_MASK 0x00003000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_9__TEMPERATURE_9_CNTL_ENG_IDLE_VOLT_MASK 0x0000c000L
#define TEMPERATURE_CNTL_TABLE_ENTRY_9__TEMPERATURE_9_MASK 0x003f0000L

// CLK_PWRMGT_CNTL
#define CLK_PWRMGT_CNTL__SPLL_PWRMGT_OFF_MASK              0x00000002L
#define CLK_PWRMGT_CNTL__SPLL_PWRMGT_OFF                   0x00000002L
#define CLK_PWRMGT_CNTL__PPLL_PWRMGT_OFF_MASK              0x00000004L
#define CLK_PWRMGT_CNTL__PPLL_PWRMGT_OFF                   0x00000004L
#define CLK_PWRMGT_CNTL__P2PLL_PWRMGT_OFF_MASK             0x00000008L
#define CLK_PWRMGT_CNTL__P2PLL_PWRMGT_OFF                  0x00000008L
#define CLK_PWRMGT_CNTL__SCLK_TURNOFF_MASK                 0x00000020L
#define CLK_PWRMGT_CNTL__SCLK_TURNOFF                      0x00000020L
#define CLK_PWRMGT_CNTL__PCLK_TURNOFF_MASK                 0x00000040L
#define CLK_PWRMGT_CNTL__PCLK_TURNOFF                      0x00000040L
#define CLK_PWRMGT_CNTL__P2CLK_TURNOFF_MASK                0x00000080L
#define CLK_PWRMGT_CNTL__P2CLK_TURNOFF                     0x00000080L
#define CLK_PWRMGT_CNTL__TEST_MODE_MASK                    0x00000200L
#define CLK_PWRMGT_CNTL__TEST_MODE                         0x00000200L
#define CLK_PWRMGT_CNTL__GLOBAL_PMAN_EN_MASK               0x00000400L
#define CLK_PWRMGT_CNTL__GLOBAL_PMAN_EN                    0x00000400L
#define CLK_PWRMGT_CNTL__ENGINE_DYNCLK_MODE_MASK           0x00001000L
#define CLK_PWRMGT_CNTL__ENGINE_DYNCLK_MODE                0x00001000L
#define CLK_PWRMGT_CNTL__ACTIVE_HILO_LAT_MASK              0x00006000L
#define CLK_PWRMGT_CNTL__DISP_DYN_STOP_LAT_MASK            0x00008000L
#define CLK_PWRMGT_CNTL__DISP_DYN_STOP_LAT                 0x00008000L
#define CLK_PWRMGT_CNTL__DISP_PM_MASK                      0x00100000L
#define CLK_PWRMGT_CNTL__DISP_PM                           0x00100000L
#define CLK_PWRMGT_CNTL__DYN_STOP_MODE_MASK                0x00e00000L
#define CLK_PWRMGT_CNTL__CG_NO1_DEBUG_M6_MASK              0x3f000000L
#define CLK_PWRMGT_CNTL__TVPLL_PWRMGT_OFF_MASK             0x40000000L
#define CLK_PWRMGT_CNTL__TVPLL_PWRMGT_OFF                  0x40000000L
#define CLK_PWRMGT_CNTL__TVCLK_TURNOFF_MASK                0x80000000L
#define CLK_PWRMGT_CNTL__TVCLK_TURNOFF                     0x80000000L

// PLL_PWRMGT_CNTL
#define PLL_PWRMGT_CNTL__SPLL_TURNOFF_MASK                 0x00000002L
#define PLL_PWRMGT_CNTL__SPLL_TURNOFF                      0x00000002L
#define PLL_PWRMGT_CNTL__PPLL_TURNOFF_MASK                 0x00000004L
#define PLL_PWRMGT_CNTL__PPLL_TURNOFF                      0x00000004L
#define PLL_PWRMGT_CNTL__P2PLL_TURNOFF_MASK                0x00000008L
#define PLL_PWRMGT_CNTL__P2PLL_TURNOFF                     0x00000008L
#define PLL_PWRMGT_CNTL__TVPLL_TURNOFF_MASK                0x00000010L
#define PLL_PWRMGT_CNTL__TVPLL_TURNOFF                     0x00000010L
#define PLL_PWRMGT_CNTL__AGPCLK_DYN_STOP_LAT_MASK          0x000001e0L
#define PLL_PWRMGT_CNTL__APM_POWER_STATE_MASK              0x00000600L
#define PLL_PWRMGT_CNTL__APM_PWRSTATE_RD_MASK              0x00001800L
#define PLL_PWRMGT_CNTL__PM_MODE_SEL_MASK                  0x00002000L
#define PLL_PWRMGT_CNTL__PM_MODE_SEL                       0x00002000L
#define PLL_PWRMGT_CNTL__EN_PWRSEQ_DONE_COND_MASK          0x00004000L
#define PLL_PWRMGT_CNTL__EN_PWRSEQ_DONE_COND               0x00004000L
#define PLL_PWRMGT_CNTL__EN_DISP_PARKED_COND_MASK          0x00008000L
#define PLL_PWRMGT_CNTL__EN_DISP_PARKED_COND               0x00008000L
#define PLL_PWRMGT_CNTL__MOBILE_SU_MASK                    0x00010000L
#define PLL_PWRMGT_CNTL__MOBILE_SU                         0x00010000L
#define PLL_PWRMGT_CNTL__SU_SCLK_USE_BCLK_MASK             0x00020000L
#define PLL_PWRMGT_CNTL__SU_SCLK_USE_BCLK                  0x00020000L
#define PLL_PWRMGT_CNTL__SU_MCLK_USE_BCLK_MASK             0x00040000L
#define PLL_PWRMGT_CNTL__SU_MCLK_USE_BCLK                  0x00040000L
#define PLL_PWRMGT_CNTL__SU_SUSTAIN_DISABLE_MASK           0x00080000L
#define PLL_PWRMGT_CNTL__SU_SUSTAIN_DISABLE                0x00080000L
#define PLL_PWRMGT_CNTL__TCL_BYPASS_DISABLE_MASK           0x00100000L
#define PLL_PWRMGT_CNTL__TCL_BYPASS_DISABLE                0x00100000L
#define PLL_PWRMGT_CNTL__TCL_CLOCK_ACTIVE_RD_MASK          0x00200000L
#define PLL_PWRMGT_CNTL__TCL_CLOCK_ACTIVE_RD               0x00200000L
#define PLL_PWRMGT_CNTL__CG_NO2_DEBUG_MASK                 0xff000000L

// M_SPLL_REF_FB_DIV
#define M_SPLL_REF_FB_DIV__M_SPLL_REF_DIV_MASK             0x000000ffL
#define M_SPLL_REF_FB_DIV__SPLL_FB_DIV_MASK                0x00ff0000L

// IDCT_RUNS
#define IDCT_RUNS__IDCT_RUNS_3_MASK                        0x000000ffL
#define IDCT_RUNS__IDCT_RUNS_2_MASK                        0x0000ff00L
#define IDCT_RUNS__IDCT_RUNS_1_MASK                        0x00ff0000L
#define IDCT_RUNS__IDCT_RUNS_0_MASK                        0xff000000L

// IDCT_LEVELS
#define IDCT_LEVELS__IDCT_LEVEL_HI_MASK                    0x0000ffffL
#define IDCT_LEVELS__IDCT_LEVEL_LO_MASK                    0xffff0000L

// IDCT_CONTROL
#define IDCT_CONTROL__IDCT_CTL_LUMA_RD_FORMAT_MASK         0x00000003L
#define IDCT_CONTROL__IDCT_CTL_CHROMA_RD_FORMAT_MASK       0x0000000cL
#define IDCT_CONTROL__IDCT_CTL_SCAN_PATTERN_MASK           0x00000010L
#define IDCT_CONTROL__IDCT_CTL_SCAN_PATTERN                0x00000010L
#define IDCT_CONTROL__IDCT_CTL_INTRA_MASK                  0x00000020L
#define IDCT_CONTROL__IDCT_CTL_INTRA                       0x00000020L
#define IDCT_CONTROL__IDCT_CTL_FLUSH_MASK                  0x00000040L
#define IDCT_CONTROL__IDCT_CTL_FLUSH                       0x00000040L
#define IDCT_CONTROL__IDCT_CTL_PASSTHRU_MASK               0x00000080L
#define IDCT_CONTROL__IDCT_CTL_PASSTHRU                    0x00000080L
#define IDCT_CONTROL__IDCT_CTL_SW_RESET_MASK               0x00000100L
#define IDCT_CONTROL__IDCT_CTL_SW_RESET                    0x00000100L
#define IDCT_CONTROL__IDCT_CTL_CONSTREQ_MASK               0x00000200L
#define IDCT_CONTROL__IDCT_CTL_CONSTREQ                    0x00000200L
#define IDCT_CONTROL__IDCT_CTL_SCRAMBLE_MASK               0x00000400L
#define IDCT_CONTROL__IDCT_CTL_SCRAMBLE                    0x00000400L

// IDCT_AUTH_CONTROL
#define IDCT_AUTH_CONTROL__CONTROL_BITS_MASK               0xffffffffL

// IDCT_AUTH
#define IDCT_AUTH__AUTH_MASK                               0xffffffffL

// NB_VENDOR_ID
#define NB_VENDOR_ID__VENDOR_ID_MASK                       0x0000ffffL

// NB_DEVICE_ID
#define NB_DEVICE_ID__DEVICE_ID_MASK                       0x0000ffffL

// NB_COMMAND
#define NB_COMMAND__IO_ACCESS_EN_MASK                      0x00000001L
#define NB_COMMAND__IO_ACCESS_EN                           0x00000001L
#define NB_COMMAND__MEM_ACCESS_EN_MASK                     0x00000002L
#define NB_COMMAND__MEM_ACCESS_EN                          0x00000002L
#define NB_COMMAND__BUS_MASTER_EN_MASK                     0x00000004L
#define NB_COMMAND__BUS_MASTER_EN                          0x00000004L
#define NB_COMMAND__SPECIAL_CYCLE_EN_MASK                  0x00000008L
#define NB_COMMAND__SPECIAL_CYCLE_EN                       0x00000008L
#define NB_COMMAND__MEM_WRITE_INVALIDATE_EN_MASK           0x00000010L
#define NB_COMMAND__MEM_WRITE_INVALIDATE_EN                0x00000010L
#define NB_COMMAND__PAL_SNOOP_EN_MASK                      0x00000020L
#define NB_COMMAND__PAL_SNOOP_EN                           0x00000020L
#define NB_COMMAND__PARITY_ERROR_EN_MASK                   0x00000040L
#define NB_COMMAND__PARITY_ERROR_EN                        0x00000040L
#define NB_COMMAND__Reserved0_MASK                         0x00000080L
#define NB_COMMAND__Reserved0                              0x00000080L
#define NB_COMMAND__SERR_EN_MASK                           0x00000100L
#define NB_COMMAND__SERR_EN                                0x00000100L
#define NB_COMMAND__FAST_B2B_EN_MASK                       0x00000200L
#define NB_COMMAND__FAST_B2B_EN                            0x00000200L
#define NB_COMMAND__Reserved_MASK                          0x0000fc00L

// NB_STATUS
#define NB_STATUS__CAP_LIST_MASK                           0x00000010L
#define NB_STATUS__CAP_LIST                                0x00000010L
#define NB_STATUS__PCI_66_EN_MASK                          0x00000020L
#define NB_STATUS__PCI_66_EN                               0x00000020L
#define NB_STATUS__Reserved_MASK                           0x00000040L
#define NB_STATUS__Reserved                                0x00000040L
#define NB_STATUS__FAST_BACK_CAPABLE_MASK                  0x00000080L
#define NB_STATUS__FAST_BACK_CAPABLE                       0x00000080L
#define NB_STATUS__DEVSEL_TIMING_MASK                      0x00000600L
#define NB_STATUS__SIGNAL_TARGET_ABORT_MASK                0x00000800L
#define NB_STATUS__SIGNAL_TARGET_ABORT                     0x00000800L
#define NB_STATUS__RECEIVED_TARGET_ABORT_MASK              0x00001000L
#define NB_STATUS__RECEIVED_TARGET_ABORT                   0x00001000L
#define NB_STATUS__RECEIVED_MASTER_ABORT_MASK              0x00002000L
#define NB_STATUS__RECEIVED_MASTER_ABORT                   0x00002000L
#define NB_STATUS__SIGNALED_SYSTEM_ERROR_MASK              0x00004000L
#define NB_STATUS__SIGNALED_SYSTEM_ERROR                   0x00004000L
#define NB_STATUS__PARITY_ERROR_DETECTED_MASK              0x00008000L
#define NB_STATUS__PARITY_ERROR_DETECTED                   0x00008000L

// NB_REVISION_ID
#define NB_REVISION_ID__MINOR_REV_ID_MASK                  0x0000000fL
#define NB_REVISION_ID__MAJOR_REV_ID_MASK                  0x000000f0L

// NB_REGPROG_INF
#define NB_REGPROG_INF__REG_LEVEL_PROG_INF_MASK            0x000000ffL

// NB_SUB_CLASS
#define NB_SUB_CLASS__SUB_CLASS_INF_MASK                   0x00000080L
#define NB_SUB_CLASS__SUB_CLASS_INF                        0x00000080L

// NB_BASE_CODE
#define NB_BASE_CODE__BASE_CLASS_CODE_MASK                 0x000000ffL

// NB_CACHE_LINE
#define NB_CACHE_LINE__CACHE_LINE_SIZE_MASK                0x000000ffL

// NB_LATENCY
#define NB_LATENCY__LATENCY_TIMER_MASK                     0x000000ffL

// NB_HEADER
#define NB_HEADER__HEADER_TYPE_MASK                        0x0000007fL
#define NB_HEADER__DEVICE_TYPE_MASK                        0x00000080L
#define NB_HEADER__DEVICE_TYPE                             0x00000080L

// NB_BIST
#define NB_BIST__BIST_COMP_MASK                            0x0000000fL
#define NB_BIST__BIST_STRT_MASK                            0x00000040L
#define NB_BIST__BIST_STRT                                 0x00000040L
#define NB_BIST__BIST_CAP_MASK                             0x00000080L
#define NB_BIST__BIST_CAP                                  0x00000080L

// NB_BAR0_AGP
#define NB_BAR0_AGP__MEM_IO_MASK                           0x00000001L
#define NB_BAR0_AGP__MEM_IO                                0x00000001L
#define NB_BAR0_AGP__TYPE_MASK                             0x00000006L
#define NB_BAR0_AGP__PREFETCH_EN_MASK                      0x00000008L
#define NB_BAR0_AGP__PREFETCH_EN                           0x00000008L
#define NB_BAR0_AGP__MEM_BASE_LOW_MASK                     0x01fffff0L
#define NB_BAR0_AGP__MEM_BASE_HIGH_MASK                    0xfe000000L

// NB_BAR1_GART
#define NB_BAR1_GART__MEM_IO_MASK                          0x00000001L
#define NB_BAR1_GART__MEM_IO                               0x00000001L
#define NB_BAR1_GART__TYPE_MASK                            0x00000006L
#define NB_BAR1_GART__PREFETCH_EN_MASK                     0x00000008L
#define NB_BAR1_GART__PREFETCH_EN                          0x00000008L
#define NB_BAR1_GART__MEM_BASE_LOW_MASK                    0x00000ff0L
#define NB_BAR1_GART__MEM_BASE_HIGH_MASK                   0xfffff000L

// NB_BAR2_PM2
#define NB_BAR2_PM2__MEM_IO_MASK                           0x00000001L
#define NB_BAR2_PM2__MEM_IO                                0x00000001L
#define NB_BAR2_PM2__PM2_BASE_MASK                         0xfffffffcL

// NB_ADAPTER_ID
#define NB_ADAPTER_ID__SUBSYSTEM_VENDOR_ID_MASK            0x0000ffffL
#define NB_ADAPTER_ID__SUBSYSTEM_ID_MASK                   0xffff0000L

// NB_CAPABILITIES_PTR
#define NB_CAPABILITIES_PTR__CAP_PTR_MASK                  0x000000ffL

// NB_CFG_SLOT1
#define NB_CFG_SLOT1__DEFER_ENABLE_MASK                    0x00010000L
#define NB_CFG_SLOT1__DEFER_ENABLE                         0x00010000L
#define NB_CFG_SLOT1__HARD_FAIL_ENABLE_MASK                0x00040000L
#define NB_CFG_SLOT1__HARD_FAIL_ENABLE                     0x00040000L
#define NB_CFG_SLOT1__CPU_BACK_2_BACK_READ_MASK            0x00100000L
#define NB_CFG_SLOT1__CPU_BACK_2_BACK_READ                 0x00100000L
#define NB_CFG_SLOT1__CFG_OPT_BPRI_OK_MASK                 0x04000000L
#define NB_CFG_SLOT1__CFG_OPT_BPRI_OK                      0x04000000L
#define NB_CFG_SLOT1__IOQ1_DIS_DURING_LOCK_MASK            0x08000000L
#define NB_CFG_SLOT1__IOQ1_DIS_DURING_LOCK                 0x08000000L
#define NB_CFG_SLOT1__PCI_DMA_SNOOP_ENB_MASK               0x20000000L
#define NB_CFG_SLOT1__PCI_DMA_SNOOP_ENB                    0x20000000L
#define NB_CFG_SLOT1__PCI_WRITE_POSTING_MASK               0x40000000L
#define NB_CFG_SLOT1__PCI_WRITE_POSTING                    0x40000000L
#define NB_CFG_SLOT1__PCI_IO_WRITE_POST_MASK               0x80000000L
#define NB_CFG_SLOT1__PCI_IO_WRITE_POST                    0x80000000L

// NB_PII_HW_DEBUG
#define NB_PII_HW_DEBUG__PII_HW_DEBUG_MASK                 0x03ffffffL
#define NB_PII_HW_DEBUG__Prefetch_MASK                     0x08000000L
#define NB_PII_HW_DEBUG__Prefetch                          0x08000000L
#define NB_PII_HW_DEBUG__BAR2_PM2Enable_MASK               0x10000000L
#define NB_PII_HW_DEBUG__BAR2_PM2Enable                    0x10000000L
#define NB_PII_HW_DEBUG__ArbDockingEnable_MASK             0x20000000L
#define NB_PII_HW_DEBUG__ArbDockingEnable                  0x20000000L
#define NB_PII_HW_DEBUG__P4IntEnable_MASK                  0x40000000L
#define NB_PII_HW_DEBUG__P4IntEnable                       0x40000000L
#define NB_PII_HW_DEBUG__CfgPciC_AMDSBDisable_MASK         0x80000000L
#define NB_PII_HW_DEBUG__CfgPciC_AMDSBDisable              0x80000000L

// NB_EX_BIU_CTRL
#define NB_EX_BIU_CTRL___2BITPF_MASK                       0x00000008L
#define NB_EX_BIU_CTRL___2BITPF                            0x00000008L
#define NB_EX_BIU_CTRL__WR_DATA_DELAY_MASK                 0x00000700L
#define NB_EX_BIU_CTRL__PI_CFG_PERF_DATA_A_MASK            0x00400000L
#define NB_EX_BIU_CTRL__PI_CFG_PERF_DATA_A                 0x00400000L
#define NB_EX_BIU_CTRL__PI_CFG_PERF_DATA_B_MASK            0x00800000L
#define NB_EX_BIU_CTRL__PI_CFG_PERF_DATA_B                 0x00800000L

// NB_ECC_CTRL
#define NB_ECC_CTRL__NOT_IMPLEMENTED_MASK                  0xffffffffL

// NB_PCI_CTRL
#define NB_PCI_CTRL__FUNCTION_1_ENABLE_MASK                0x00000001L
#define NB_PCI_CTRL__FUNCTION_1_ENABLE                     0x00000001L
#define NB_PCI_CTRL__PCI_OR_ENABLE_MASK                    0x00000002L
#define NB_PCI_CTRL__PCI_OR_ENABLE                         0x00000002L
#define NB_PCI_CTRL__PCI_DT_ENABLE_MASK                    0x00000004L
#define NB_PCI_CTRL__PCI_DT_ENABLE                         0x00000004L
#define NB_PCI_CTRL__APC_OR_ENABLE_MASK                    0x00000008L
#define NB_PCI_CTRL__APC_OR_ENABLE                         0x00000008L
#define NB_PCI_CTRL__APC_DT_ENABLE_MASK                    0x00000010L
#define NB_PCI_CTRL__APC_DT_ENABLE                         0x00000010L
#define NB_PCI_CTRL__APC_FWRITE_ENABLE_MASK                0x00000020L
#define NB_PCI_CTRL__APC_FWRITE_ENABLE                     0x00000020L
#define NB_PCI_CTRL__PCI_DELAY_READ_RETRY_COUNT_MASK       0x00000f00L
#define NB_PCI_CTRL__PCI_MULTIREAD_ENABLE_MASK             0x00001000L
#define NB_PCI_CTRL__PCI_MULTIREAD_ENABLE                  0x00001000L
#define NB_PCI_CTRL__PCI_MR_DATA_DISCARD_ENABLE_MASK       0x00002000L
#define NB_PCI_CTRL__PCI_MR_DATA_DISCARD_ENABLE            0x00002000L
#define NB_PCI_CTRL__PCI_MR_BUF_DISCARD_ENABLE_MASK        0x00004000L
#define NB_PCI_CTRL__PCI_MR_BUF_DISCARD_ENABLE             0x00004000L
#define NB_PCI_CTRL__PCI_MR_AUTO_IVAT_MASK                 0x00008000L
#define NB_PCI_CTRL__PCI_MR_AUTO_IVAT                      0x00008000L
#define NB_PCI_CTRL__PCI_MR_PFC_IVAT_MASK                  0x00010000L
#define NB_PCI_CTRL__PCI_MR_PFC_IVAT                       0x00010000L
#define NB_PCI_CTRL__APC_APIC_ENABLE_MASK                  0x00020000L
#define NB_PCI_CTRL__APC_APIC_ENABLE                       0x00020000L
#define NB_PCI_CTRL__PCI_MR_APCI_ENABLE_MASK               0x00040000L
#define NB_PCI_CTRL__PCI_MR_APCI_ENABLE                    0x00040000L
#define NB_PCI_CTRL__PCI_MR_HW_DEBUG_MASK                  0xfff80000L

// NB_ADAPTER_ID_W
#define NB_ADAPTER_ID_W__SUBSYSTEM_VENDOR_ID_MASK          0x0000ffffL
#define NB_ADAPTER_ID_W__SUBSYSTEM_ID_MASK                 0xffff0000L

// NB_PAM0
#define NB_PAM0__READ_ENABLE_F0_MASK                       0x00000010L
#define NB_PAM0__READ_ENABLE_F0                            0x00000010L
#define NB_PAM0__WRITE_ENABLE_F0_MASK                      0x00000020L
#define NB_PAM0__WRITE_ENABLE_F0                           0x00000020L

// NB_PAM1
#define NB_PAM1__READ_ENABLE_C0_MASK                       0x00000001L
#define NB_PAM1__READ_ENABLE_C0                            0x00000001L
#define NB_PAM1__WRITE_ENABLE_C0_MASK                      0x00000002L
#define NB_PAM1__WRITE_ENABLE_C0                           0x00000002L
#define NB_PAM1__READ_ENABLE_C4_MASK                       0x00000010L
#define NB_PAM1__READ_ENABLE_C4                            0x00000010L
#define NB_PAM1__WRITE_ENABLE_C4_MASK                      0x00000020L
#define NB_PAM1__WRITE_ENABLE_C4                           0x00000020L

// NB_PAM2
#define NB_PAM2__READ_ENABLE_C8_MASK                       0x00000001L
#define NB_PAM2__READ_ENABLE_C8                            0x00000001L
#define NB_PAM2__WRITE_ENABLE_C8_MASK                      0x00000002L
#define NB_PAM2__WRITE_ENABLE_C8                           0x00000002L
#define NB_PAM2__READ_ENABLE_CC_MASK                       0x00000010L
#define NB_PAM2__READ_ENABLE_CC                            0x00000010L
#define NB_PAM2__WRITE_ENABLE_CC_MASK                      0x00000020L
#define NB_PAM2__WRITE_ENABLE_CC                           0x00000020L

// NB_PAM3
#define NB_PAM3__READ_ENABLE_D0_MASK                       0x00000001L
#define NB_PAM3__READ_ENABLE_D0                            0x00000001L
#define NB_PAM3__WRITE_ENABLE_D0_MASK                      0x00000002L
#define NB_PAM3__WRITE_ENABLE_D0                           0x00000002L
#define NB_PAM3__READ_ENABLE_D4_MASK                       0x00000010L
#define NB_PAM3__READ_ENABLE_D4                            0x00000010L
#define NB_PAM3__WRITE_ENABLE_D4_MASK                      0x00000020L
#define NB_PAM3__WRITE_ENABLE_D4                           0x00000020L

// NB_PAM4
#define NB_PAM4__READ_ENABLE_D8_MASK                       0x00000001L
#define NB_PAM4__READ_ENABLE_D8                            0x00000001L
#define NB_PAM4__WRITE_ENABLE_D8_MASK                      0x00000002L
#define NB_PAM4__WRITE_ENABLE_D8                           0x00000002L
#define NB_PAM4__READ_ENABLE_DC_MASK                       0x00000010L
#define NB_PAM4__READ_ENABLE_DC                            0x00000010L
#define NB_PAM4__WRITE_ENABLE_DC_MASK                      0x00000020L
#define NB_PAM4__WRITE_ENABLE_DC                           0x00000020L

// NB_PAM5
#define NB_PAM5__READ_ENABLE_E0_MASK                       0x00000001L
#define NB_PAM5__READ_ENABLE_E0                            0x00000001L
#define NB_PAM5__WRITE_ENABLE_E0_MASK                      0x00000002L
#define NB_PAM5__WRITE_ENABLE_E0                           0x00000002L
#define NB_PAM5__READ_ENABLE_E4_MASK                       0x00000010L
#define NB_PAM5__READ_ENABLE_E4                            0x00000010L
#define NB_PAM5__WRITE_ENABLE_E4_MASK                      0x00000020L
#define NB_PAM5__WRITE_ENABLE_E4                           0x00000020L

// NB_PAM6
#define NB_PAM6__READ_ENABLE_E8_MASK                       0x00000001L
#define NB_PAM6__READ_ENABLE_E8                            0x00000001L
#define NB_PAM6__WRITE_ENABLE_E8_MASK                      0x00000002L
#define NB_PAM6__WRITE_ENABLE_E8                           0x00000002L
#define NB_PAM6__READ_ENABLE_EC_MASK                       0x00000010L
#define NB_PAM6__READ_ENABLE_EC                            0x00000010L
#define NB_PAM6__WRITE_ENABLE_EC_MASK                      0x00000020L
#define NB_PAM6__WRITE_ENABLE_EC                           0x00000020L

// NB_BIU_CTRL
#define NB_BIU_CTRL__Reserved_MASK                         0xffffffffL

// NB_BIU_SIP
#define NB_BIU_SIP__Reserved_MASK                          0xffffffffL

// NB_FDHC
#define NB_FDHC__MEM_HOLE_ENABLE_MASK                      0x000000c0L

// NB_SMRAM
#define NB_SMRAM__SMM_LOCATION_MASK                        0x00000007L
#define NB_SMRAM__GLOBAL_SMRAM_ENABLE_MASK                 0x00000008L
#define NB_SMRAM__GLOBAL_SMRAM_ENABLE                      0x00000008L
#define NB_SMRAM__SMM_SPACE_LOCKED_MASK                    0x00000010L
#define NB_SMRAM__SMM_SPACE_LOCKED                         0x00000010L
#define NB_SMRAM__SMM_SPACE_OPEN_MASK                      0x00000060L

// NB_EXSMRAM
#define NB_EXSMRAM__TSEG_ENABLE_MASK                       0x00000001L
#define NB_EXSMRAM__TSEG_ENABLE                            0x00000001L
#define NB_EXSMRAM__TSEG_SIZE_MASK                         0x00000006L
#define NB_EXSMRAM__Reserved0_MASK                         0x00000020L
#define NB_EXSMRAM__Reserved0                              0x00000020L
#define NB_EXSMRAM__EX_SMRAM_ERROR_MASK                    0x00000040L
#define NB_EXSMRAM__EX_SMRAM_ERROR                         0x00000040L
#define NB_EXSMRAM__HI_SMRAM_ENABLE_MASK                   0x00000080L
#define NB_EXSMRAM__HI_SMRAM_ENABLE                        0x00000080L

// NB_PMCR
#define NB_PMCR__ACPI_CTL_REG_EN_MASK                      0x00000001L
#define NB_PMCR__ACPI_CTL_REG_EN                           0x00000001L

// NB_STRAP_READ_BACK
#define NB_STRAP_READ_BACK__ChangeID_MASK                  0x00000003L
#define NB_STRAP_READ_BACK__MobilePart_MASK                0x00000004L
#define NB_STRAP_READ_BACK__MobilePart                     0x00000004L
#define NB_STRAP_READ_BACK__PAR_MASK                       0x00000008L
#define NB_STRAP_READ_BACK__PAR                            0x00000008L
#define NB_STRAP_READ_BACK__AGP8X_DETb_MASK                0x00000010L
#define NB_STRAP_READ_BACK__AGP8X_DETb                     0x00000010L
#define NB_STRAP_READ_BACK__FSB133EN_MASK                  0x00000020L
#define NB_STRAP_READ_BACK__FSB133EN                       0x00000020L
#define NB_STRAP_READ_BACK__IntClk_MASK                    0x00000800L
#define NB_STRAP_READ_BACK__IntClk                         0x00000800L
#define NB_STRAP_READ_BACK__ProdTest_MASK                  0x00010000L
#define NB_STRAP_READ_BACK__ProdTest                       0x00010000L
#define NB_STRAP_READ_BACK__CPU_Voltage0_MASK              0x00020000L
#define NB_STRAP_READ_BACK__CPU_Voltage0                   0x00020000L
#define NB_STRAP_READ_BACK__PhaseCal_MASK                  0x00040000L
#define NB_STRAP_READ_BACK__PhaseCal                       0x00040000L
#define NB_STRAP_READ_BACK__MemVMode_MASK                  0x00080000L
#define NB_STRAP_READ_BACK__MemVMode                       0x00080000L
#define NB_STRAP_READ_BACK__CalDefaults_MASK               0x00200000L
#define NB_STRAP_READ_BACK__CalDefaults                    0x00200000L
#define NB_STRAP_READ_BACK__OscClkSel_MASK                 0x00400000L
#define NB_STRAP_READ_BACK__OscClkSel                      0x00400000L
#define NB_STRAP_READ_BACK__ClkBypass_MASK                 0x00800000L
#define NB_STRAP_READ_BACK__ClkBypass                      0x00800000L
#define NB_STRAP_READ_BACK__MobileCpuSel_MASK              0x01000000L
#define NB_STRAP_READ_BACK__MobileCpuSel                   0x01000000L
#define NB_STRAP_READ_BACK__CPU_Voltage1_MASK              0x02000000L
#define NB_STRAP_READ_BACK__CPU_Voltage1                   0x02000000L
#define NB_STRAP_READ_BACK__NBStrap_In_MASK                0x0c000000L
#define NB_STRAP_READ_BACK__Enable_SS_MASK                 0x10000000L
#define NB_STRAP_READ_BACK__Enable_SS                      0x10000000L
#define NB_STRAP_READ_BACK__Default_MASK                   0x20000000L
#define NB_STRAP_READ_BACK__Default                        0x20000000L
#define NB_STRAP_READ_BACK__ClkSpeed_MASK                  0xc0000000L

// NB_MC_CNTL
#define NB_MC_CNTL__Reserved0_MASK                         0x00000001L
#define NB_MC_CNTL__Reserved0                              0x00000001L
#define NB_MC_CNTL__DISABLE_CPU_MASK                       0x00000002L
#define NB_MC_CNTL__DISABLE_CPU                            0x00000002L
#define NB_MC_CNTL__Reserved1_A5_MASK                      0x00000008L
#define NB_MC_CNTL__Reserved1_A5                           0x00000008L
#define NB_MC_CNTL__DISABLE_AGP_MASK                       0x00000010L
#define NB_MC_CNTL__DISABLE_AGP                            0x00000010L
#define NB_MC_CNTL__DISP_HiPri_MASK                        0x00000020L
#define NB_MC_CNTL__DISP_HiPri                             0x00000020L
#define NB_MC_CNTL__DLL_Reset_MASK                         0x00000040L
#define NB_MC_CNTL__DLL_Reset                              0x00000040L
#define NB_MC_CNTL__DLL_PwrDown_MASK                       0x00000080L
#define NB_MC_CNTL__DLL_PwrDown                            0x00000080L
#define NB_MC_CNTL__DLL_Ready_MASK                         0x00000100L
#define NB_MC_CNTL__DLL_Ready                              0x00000100L
#define NB_MC_CNTL__Reserved2_A5_MASK                      0x00000600L
#define NB_MC_CNTL__DISP_HiPri2_MASK                       0x00000800L
#define NB_MC_CNTL__DISP_HiPri2                            0x00000800L
#define NB_MC_CNTL__Reserved3_MASK                         0x0003f000L
#define NB_MC_CNTL__SELF_RF_DIS_MASK                       0x00040000L
#define NB_MC_CNTL__SELF_RF_DIS                            0x00040000L
#define NB_MC_CNTL__DISABLE_BYPASS_MASK                    0x00080000L
#define NB_MC_CNTL__DISABLE_BYPASS                         0x00080000L
#define NB_MC_CNTL__Reserved4_MASK                         0x00100000L
#define NB_MC_CNTL__Reserved4                              0x00100000L
#define NB_MC_CNTL__SEQ_ARB_MODE_MASK                      0x00200000L
#define NB_MC_CNTL__SEQ_ARB_MODE                           0x00200000L
#define NB_MC_CNTL__MC_CLEAN_GC_MASK                       0x00400000L
#define NB_MC_CNTL__MC_CLEAN_GC                            0x00400000L
#define NB_MC_CNTL__MEM_DYNAMIC_CKE_MASK                   0x00800000L
#define NB_MC_CNTL__MEM_DYNAMIC_CKE                        0x00800000L
#define NB_MC_CNTL__MEM_SDRAM_TRI_EN_MASK                  0x01000000L
#define NB_MC_CNTL__MEM_SDRAM_TRI_EN                       0x01000000L
#define NB_MC_CNTL__MEM_DYN_REC_CTRL_MASK                  0x02000000L
#define NB_MC_CNTL__MEM_DYN_REC_CTRL                       0x02000000L
#define NB_MC_CNTL__Reserved5_MASK                         0x04000000L
#define NB_MC_CNTL__Reserved5                              0x04000000L
#define NB_MC_CNTL__MC_PDN_MODE_MASK                       0x18000000L
#define NB_MC_CNTL__MC_STARTUP_MASK                        0x20000000L
#define NB_MC_CNTL__MC_STARTUP                             0x20000000L
#define NB_MC_CNTL__MC_PWRDOWN_MASK                        0x40000000L
#define NB_MC_CNTL__MC_PWRDOWN                             0x40000000L
#define NB_MC_CNTL__MC_RESTART_MASK                        0x80000000L
#define NB_MC_CNTL__MC_RESTART                             0x80000000L

// NB_MC_LIMIT
#define NB_MC_LIMIT__R6_RD_IDLE_LIMIT_MASK                 0x0000001fL
#define NB_MC_LIMIT__R6_RD_PH_LIMIT_MASK                   0x000000e0L
#define NB_MC_LIMIT__R6_WR_IDLE_LIMIT_MASK                 0x00001f00L
#define NB_MC_LIMIT__R6_WR_PH_LIMIT_MASK                   0x0000e000L
#define NB_MC_LIMIT__NB_RD_IDLE_LIMIT_MASK                 0x001f0000L
#define NB_MC_LIMIT__NB_RD_PH_LIMIT_MASK                   0x00e00000L
#define NB_MC_LIMIT__NB_WR_IDLE_LIMIT_MASK                 0x1f000000L
#define NB_MC_LIMIT__NB_WR_PH_LIMIT_MASK                   0xe0000000L

// SCRATCH_NBCFG
#define SCRATCH_NBCFG__SCRATCH_MASK                        0xffffffffL

// NB_BIU_CFG
#define NB_BIU_CFG__SnoopCtlEn_MASK                        0x00000001L
#define NB_BIU_CFG__SnoopCtlEn                             0x00000001L
#define NB_BIU_CFG__BlockMasterWrEn_MASK                   0x00000002L
#define NB_BIU_CFG__BlockMasterWrEn                        0x00000002L
#define NB_BIU_CFG__WrWaitsSnpEn_MASK                      0x00000004L
#define NB_BIU_CFG__WrWaitsSnpEn                           0x00000004L
#define NB_BIU_CFG__HiPriRdMode_MASK                       0x00000018L
#define NB_BIU_CFG__PCIBIURdPri_MASK                       0x00000060L
#define NB_BIU_CFG__EarlyTRDY_MASK                         0x00000080L
#define NB_BIU_CFG__EarlyTRDY                              0x00000080L
#define NB_BIU_CFG__Arb_PreemptEn_MASK                     0x00000100L
#define NB_BIU_CFG__Arb_PreemptEn                          0x00000100L
#define NB_BIU_CFG__RedirectEn_MASK                        0x00000200L
#define NB_BIU_CFG__RedirectEn                             0x00000200L
#define NB_BIU_CFG__HyperThreadEn_MASK                     0x00000400L
#define NB_BIU_CFG__HyperThreadEn                          0x00000400L
#define NB_BIU_CFG__RefvebDCStop_MASK                      0x00000800L
#define NB_BIU_CFG__RefvebDCStop                           0x00000800L
#define NB_BIU_CFG__SMUBufferHalf_MASK                     0x00001000L
#define NB_BIU_CFG__SMUBufferHalf                          0x00001000L
#define NB_BIU_CFG__C2ABufferHalf_MASK                     0x00002000L
#define NB_BIU_CFG__C2ABufferHalf                          0x00002000L
#define NB_BIU_CFG__M6RefreshDef_MASK                      0x00004000L
#define NB_BIU_CFG__M6RefreshDef                           0x00004000L
#define NB_BIU_CFG__M6TimeoutDef_MASK                      0x00008000L
#define NB_BIU_CFG__M6TimeoutDef                           0x00008000L
#define NB_BIU_CFG__M6UrgentDef_MASK                       0x00010000L
#define NB_BIU_CFG__M6UrgentDef                            0x00010000L
#define NB_BIU_CFG__M6IdleDefKill_MASK                     0x00020000L
#define NB_BIU_CFG__M6IdleDefKill                          0x00020000L
#define NB_BIU_CFG__IOQDeep_MASK                           0x003c0000L
#define NB_BIU_CFG__HiPriWrDef_MASK                        0x00400000L
#define NB_BIU_CFG__HiPriWrDef                             0x00400000L
#define NB_BIU_CFG__DBIDisable_MASK                        0x00800000L
#define NB_BIU_CFG__DBIDisable                             0x00800000L
#define NB_BIU_CFG__HiPriWrMode_MASK                       0x03000000L
#define NB_BIU_CFG__IntelDBIModeEn_MASK                    0x04000000L
#define NB_BIU_CFG__IntelDBIModeEn                         0x04000000L
#define NB_BIU_CFG__BlkWrStreamEn_MASK                     0x08000000L
#define NB_BIU_CFG__BlkWrStreamEn                          0x08000000L
#define NB_BIU_CFG__DualDeferOff_MASK                      0x10000000L
#define NB_BIU_CFG__DualDeferOff                           0x10000000L
#define NB_BIU_CFG__OutstandDef_MASK                       0xe0000000L

// NB_POCO
#define NB_POCO__POCOArm_MASK                              0x00000001L
#define NB_POCO__POCOArm                                   0x00000001L
#define NB_POCO__Reserved_MASK                             0x00000002L
#define NB_POCO__Reserved                                  0x00000002L
#define NB_POCO__POCOLock_MASK                             0x00000004L
#define NB_POCO__POCOLock                                  0x00000004L
#define NB_POCO__PowerOnConfig_MASK                        0xfffffff8L

// NB_PCI_ARB
#define NB_PCI_ARB__PARK_PCI_MASK                          0x00000001L
#define NB_PCI_ARB__PARK_PCI                               0x00000001L
#define NB_PCI_ARB__APC_PREFETCH_EN_MASK                   0x00000002L
#define NB_PCI_ARB__APC_PREFETCH_EN                        0x00000002L
#define NB_PCI_ARB__PCI_PREFETCH_EN_MASK                   0x00000004L
#define NB_PCI_ARB__PCI_PREFETCH_EN                        0x00000004L
#define NB_PCI_ARB__TARGET_LAT_TIMER_DISABLE_MASK          0x00000008L
#define NB_PCI_ARB__TARGET_LAT_TIMER_DISABLE               0x00000008L
#define NB_PCI_ARB__EV6MODE_MASK                           0x00000010L
#define NB_PCI_ARB__EV6MODE                                0x00000010L
#define NB_PCI_ARB___14M_HOLE_MASK                         0x00000020L
#define NB_PCI_ARB___14M_HOLE                              0x00000020L
#define NB_PCI_ARB___15M_HOLE_MASK                         0x00000040L
#define NB_PCI_ARB___15M_HOLE                              0x00000040L
#define NB_PCI_ARB__PM_REG_ENABLE_MASK                     0x00000080L
#define NB_PCI_ARB__PM_REG_ENABLE                          0x00000080L
#define NB_PCI_ARB__SOUTH_BRIDGE_LOCK_DISABLE_MASK         0x00000100L
#define NB_PCI_ARB__SOUTH_BRIDGE_LOCK_DISABLE              0x00000100L
#define NB_PCI_ARB__AGP_ARBITER_PIPE_DISABLE_MASK          0x00000200L
#define NB_PCI_ARB__AGP_ARBITER_PIPE_DISABLE               0x00000200L
#define NB_PCI_ARB__PCI_EARLY_PROBE_DISABLE_MASK           0x00000400L
#define NB_PCI_ARB__PCI_EARLY_PROBE_DISABLE                0x00000400L
#define NB_PCI_ARB__APC_EARLY_PROBE_DISABLE_MASK           0x00000800L
#define NB_PCI_ARB__APC_EARLY_PROBE_DISABLE                0x00000800L
#define NB_PCI_ARB__READ_DATA_ERROR_DISABLE_MASK           0x00001000L
#define NB_PCI_ARB__READ_DATA_ERROR_DISABLE                0x00001000L
#define NB_PCI_ARB__APC_WRITE_POST_RETRY_MASK              0x00002000L
#define NB_PCI_ARB__APC_WRITE_POST_RETRY                   0x00002000L
#define NB_PCI_ARB__PCI_WRITE_POST_RETRY_MASK              0x00004000L
#define NB_PCI_ARB__PCI_WRITE_POST_RETRY                   0x00004000L
#define NB_PCI_ARB__MDA_DEBUG_MASK                         0x00008000L
#define NB_PCI_ARB__MDA_DEBUG                              0x00008000L
#define NB_PCI_ARB__PCI_CHAINING_ENABLE_MASK               0x00010000L
#define NB_PCI_ARB__PCI_CHAINING_ENABLE                    0x00010000L
#define NB_PCI_ARB__APC_CHAINING_ENABLE_MASK               0x00020000L
#define NB_PCI_ARB__APC_CHAINING_ENABLE                    0x00020000L
#define NB_PCI_ARB__OPUS_ENABLE_MASK                       0x00040000L
#define NB_PCI_ARB__OPUS_ENABLE                            0x00040000L
#define NB_PCI_ARB__TARGET_LATENCY_MASK                    0x00800000L
#define NB_PCI_ARB__TARGET_LATENCY                         0x00800000L
#define NB_PCI_ARB__AGP_VGA_BIOS_MASK                      0xff000000L

// NB_CFG_STAT
#define NB_CFG_STAT__CPU_DIVIDER_MASK                      0x0000000fL
#define NB_CFG_STAT__OUT_CLK_DELAY_MASK                    0x00000010L
#define NB_CFG_STAT__OUT_CLK_DELAY                         0x00000010L
#define NB_CFG_STAT__IN_CLK_DELAY_MASK                     0x00000020L
#define NB_CFG_STAT__IN_CLK_DELAY                          0x00000020L
#define NB_CFG_STAT__Reserved0_MASK                        0x00000080L
#define NB_CFG_STAT__Reserved0                             0x00000080L
#define NB_CFG_STAT__Reserved1_MASK                        0x00030000L
#define NB_CFG_STAT__CLOCK_SPEED_MASK                      0x00300000L
#define NB_CFG_STAT__TYPE_DETECTED_MASK                    0x02000000L
#define NB_CFG_STAT__TYPE_DETECTED                         0x02000000L
#define NB_CFG_STAT__SYS_CLK_MUX_MASK                      0x1c000000L
#define NB_CFG_STAT__AGP_CLK_MUX_MASK                      0xe0000000L

// NB_GC_STRAPS
#define NB_GC_STRAPS__EXTGFX_ENABLE_MASK                   0x00000001L
#define NB_GC_STRAPS__EXTGFX_ENABLE                        0x00000001L
#define NB_GC_STRAPS__INTGFX_ENABLE_MASK                   0x00000002L
#define NB_GC_STRAPS__INTGFX_ENABLE                        0x00000002L
#define NB_GC_STRAPS__VGA_DISABLE_MASK                     0x00000004L
#define NB_GC_STRAPS__VGA_DISABLE                          0x00000004L
#define NB_GC_STRAPS__ID_DISABLE_MASK                      0x00000008L
#define NB_GC_STRAPS__ID_DISABLE                           0x00000008L
#define NB_GC_STRAPS__APERTURE_SIZE_MASK                   0x00000030L
#define NB_GC_STRAPS__MULTI_FUNC_MASK                      0x000000c0L
#define NB_GC_STRAPS__BUSCFG_MASK                          0x00000700L
#define NB_GC_STRAPS__ENINTb_MASK                          0x00000800L
#define NB_GC_STRAPS__ENINTb                               0x00000800L
#define NB_GC_STRAPS__FW_DISABLE_MASK                      0x00001000L
#define NB_GC_STRAPS__FW_DISABLE                           0x00001000L
#define NB_GC_STRAPS__EXT_MEM_EN_MASK                      0x00002000L
#define NB_GC_STRAPS__EXT_MEM_EN                           0x00002000L
#define NB_GC_STRAPS__BLANK_ROM_MASK                       0x00004000L
#define NB_GC_STRAPS__BLANK_ROM                            0x00004000L
#define NB_GC_STRAPS__ADDIN_CARD_MASK                      0x00008000L
#define NB_GC_STRAPS__ADDIN_CARD                           0x00008000L
#define NB_GC_STRAPS__POWER_ON_STRAPS_MASK                 0x0fff0000L
#define NB_GC_STRAPS__MOBILE_MASK                          0x10000000L
#define NB_GC_STRAPS__MOBILE                               0x10000000L
#define NB_GC_STRAPS__VE_MASK                              0x20000000L
#define NB_GC_STRAPS__VE                                   0x20000000L
#define NB_GC_STRAPS__CHG_ID_MASK                          0xc0000000L

// NB_TOP_OF_DRAM_SLOT1
#define NB_TOP_OF_DRAM_SLOT1__TOP_OF_DRAM_A5_MASK          0xff800000L

// NB_AGP_CAP_ID
#define NB_AGP_CAP_ID__CAP_ID_MASK                         0x000000ffL
#define NB_AGP_CAP_ID__NEXT_PTR_MASK                       0x0000ff00L
#define NB_AGP_CAP_ID__AGP_MINOR_MASK                      0x000f0000L
#define NB_AGP_CAP_ID__AGP_MAJOR_MASK                      0x00f00000L

// NB_AGP_STATUS
#define NB_AGP_STATUS__RATE1X_4X_MASK                      0x00000001L
#define NB_AGP_STATUS__RATE1X_4X                           0x00000001L
#define NB_AGP_STATUS__RATE2X_8X_MASK                      0x00000002L
#define NB_AGP_STATUS__RATE2X_8X                           0x00000002L
#define NB_AGP_STATUS__RATE4X_MASK                         0x00000004L
#define NB_AGP_STATUS__RATE4X                              0x00000004L
#define NB_AGP_STATUS__MODE_AGP30_MASK                     0x00000008L
#define NB_AGP_STATUS__MODE_AGP30                          0x00000008L
#define NB_AGP_STATUS__FW_MASK                             0x00000010L
#define NB_AGP_STATUS__FW                                  0x00000010L
#define NB_AGP_STATUS__R4G_MASK                            0x00000020L
#define NB_AGP_STATUS__R4G                                 0x00000020L
#define NB_AGP_STATUS__HTRANSb_MASK                        0x00000040L
#define NB_AGP_STATUS__HTRANSb                             0x00000040L
#define NB_AGP_STATUS__GART64B_MASK                        0x00000080L
#define NB_AGP_STATUS__GART64B                             0x00000080L
#define NB_AGP_STATUS__ITA_COH_MASK                        0x00000100L
#define NB_AGP_STATUS__ITA_COH                             0x00000100L
#define NB_AGP_STATUS__SBA_MASK                            0x00000200L
#define NB_AGP_STATUS__SBA                                 0x00000200L
#define NB_AGP_STATUS__CAL_CYCLE_MASK                      0x00001c00L
#define NB_AGP_STATUS__ARQSZ_MASK                          0x0000e000L
#define NB_AGP_STATUS__ISOCH_SUPPORT_MASK                  0x00020000L
#define NB_AGP_STATUS__ISOCH_SUPPORT                       0x00020000L
#define NB_AGP_STATUS__RQ_MASK                             0xff000000L

// NB_AGP_COMMAND
#define NB_AGP_COMMAND__DATA_RATE_MASK                     0x00000007L
#define NB_AGP_COMMAND__FW_EN_MASK                         0x00000010L
#define NB_AGP_COMMAND__FW_EN                              0x00000010L
#define NB_AGP_COMMAND__R4G_EN_MASK                        0x00000020L
#define NB_AGP_COMMAND__R4G_EN                             0x00000020L
#define NB_AGP_COMMAND__GART64B_EN_MASK                    0x00000080L
#define NB_AGP_COMMAND__GART64B_EN                         0x00000080L
#define NB_AGP_COMMAND__AGP_EN_MASK                        0x00000100L
#define NB_AGP_COMMAND__AGP_EN                             0x00000100L
#define NB_AGP_COMMAND__SBA_EN_MASK                        0x00000200L
#define NB_AGP_COMMAND__SBA_EN                             0x00000200L
#define NB_AGP_COMMAND__PCAL_CYCLE_MASK                    0x00001c00L

// NB_NISTAT
#define NB_NISTAT__ISOCH_ERRCODE_MASK                      0x00000003L
#define NB_NISTAT__ISOCH_L_MASK                            0x00000038L
#define NB_NISTAT__ISOCH_Y_MASK                            0x000000c0L
#define NB_NISTAT__ISOCH_N_MASK                            0x0000ff00L
#define NB_NISTAT__MAXBW_MASK                              0x00ff0000L

// NB_AGPCTRL
#define NB_AGPCTRL__RESERVED1_MASK                         0x0000007fL
#define NB_AGPCTRL__GTLBEN_MASK                            0x00000080L
#define NB_AGPCTRL__GTLBEN                                 0x00000080L
#define NB_AGPCTRL__APERENB_MASK                           0x00000100L
#define NB_AGPCTRL__APERENB                                0x00000100L
#define NB_AGPCTRL__CAL_CYCLE_DIS_MASK                     0x00000200L
#define NB_AGPCTRL__CAL_CYCLE_DIS                          0x00000200L
#define NB_AGPCTRL__RESERVED2_MASK                         0x00ff0000L

// NB_APSIZE
#define NB_APSIZE__APSIZE_MASK                             0x00000fffL

// NB_NEPG
#define NB_NEPG__NEPG_N_MASK                               0x000007ffL
#define NB_NEPG__NEPG_SEL_MASK                             0x0000f000L

// NB_GARTLO
#define NB_GARTLO__BASELO_MASK                             0xfffff000L

// NB_GARTHI
#define NB_GARTHI__BASEHI_MASK                             0xffffffffL

// NB_NICMD
#define NB_NICMD__PISOCH_Y_MASK                            0x000000c0L

// NB_PERF_CNT_CTRL
#define NB_PERF_CNT_CTRL__GLOBE_CNT_EN_MASK                0x00000001L
#define NB_PERF_CNT_CTRL__GLOBE_CNT_EN                     0x00000001L
#define NB_PERF_CNT_CTRL__GLOBE_SHADOW_WR_MASK             0x00000002L
#define NB_PERF_CNT_CTRL__GLOBE_SHADOW_WR                  0x00000002L

// NB_AGP_ADDRESS_SPACE_SIZE
#define NB_AGP_ADDRESS_SPACE_SIZE__GART_EN_MASK            0x00000001L
#define NB_AGP_ADDRESS_SPACE_SIZE__GART_EN                 0x00000001L
#define NB_AGP_ADDRESS_SPACE_SIZE__VA_SIZE_MASK            0x0000000eL
#define NB_AGP_ADDRESS_SPACE_SIZE__VGA_IA_EN_MASK          0x00010000L
#define NB_AGP_ADDRESS_SPACE_SIZE__VGA_IA_EN               0x00010000L

// NB_AGP_MODE_CONTROL
#define NB_AGP_MODE_CONTROL__CPU_AGP_RD_WR_SYNC_EN_MASK    0x00000080L
#define NB_AGP_MODE_CONTROL__CPU_AGP_RD_WR_SYNC_EN         0x00000080L
#define NB_AGP_MODE_CONTROL__LV1_INDEX_MASK                0x00010000L
#define NB_AGP_MODE_CONTROL__LV1_INDEX                     0x00010000L
#define NB_AGP_MODE_CONTROL__PDC_EN_MASK                   0x00020000L
#define NB_AGP_MODE_CONTROL__PDC_EN                        0x00020000L
#define NB_AGP_MODE_CONTROL__POST_GART_Q_SIZE_MASK         0x00040000L
#define NB_AGP_MODE_CONTROL__POST_GART_Q_SIZE              0x00040000L
#define NB_AGP_MODE_CONTROL__NONGART_SNOOP_MASK            0x00080000L
#define NB_AGP_MODE_CONTROL__NONGART_SNOOP                 0x00080000L
#define NB_AGP_MODE_CONTROL__AGP_RD_BUF_SIZE_MASK          0x00100000L
#define NB_AGP_MODE_CONTROL__AGP_RD_BUF_SIZE               0x00100000L

// NB_MEM_IO_CNTL_0
#define NB_MEM_IO_CNTL_0__MEM_N_CKA_MASK                   0x0000001fL
#define NB_MEM_IO_CNTL_0__MEM_N_AA_MASK                    0x000003e0L
#define NB_MEM_IO_CNTL_0__MEM_N_DQMA_MASK                  0x00007c00L
#define NB_MEM_IO_CNTL_0__MEM_N_DQSA_MASK                  0x000f8000L

// NB_MEM_IO_CNTL_1
#define NB_MEM_IO_CNTL_1__MEM_P_CKA_MASK                   0x0000001fL
#define NB_MEM_IO_CNTL_1__MEM_P_AA_MASK                    0x000003e0L
#define NB_MEM_IO_CNTL_1__MEM_P_DQMA_MASK                  0x00007c00L
#define NB_MEM_IO_CNTL_1__MEM_P_DQSA_MASK                  0x000f8000L
#define NB_MEM_IO_CNTL_1__CLKA_ENABLE_MASK                 0x00400000L
#define NB_MEM_IO_CNTL_1__CLKA_ENABLE                      0x00400000L
#define NB_MEM_IO_CNTL_1__Reserved_MASK                    0xff800000L

// NB_MEM_SDRAM_MODE_REG
#define NB_MEM_SDRAM_MODE_REG__MEM_MODE_REG_A5_MASK        0x0000ffffL
#define NB_MEM_SDRAM_MODE_REG__Reserved0_A5_MASK           0x000f0000L
#define NB_MEM_SDRAM_MODE_REG__MEM_CAS_LATENCY_MASK        0x00700000L
#define NB_MEM_SDRAM_MODE_REG__Reserved1_MASK              0x0f800000L
#define NB_MEM_SDRAM_MODE_REG__MC_INIT_COMPLETE_MASK       0x10000000L
#define NB_MEM_SDRAM_MODE_REG__MC_INIT_COMPLETE            0x10000000L
#define NB_MEM_SDRAM_MODE_REG__Reserved2_A5_MASK           0x60000000L
#define NB_MEM_SDRAM_MODE_REG__MEM_SDRAM_RESET_MASK        0x80000000L
#define NB_MEM_SDRAM_MODE_REG__MEM_SDRAM_RESET             0x80000000L

// NB_MEM_IO_CNTL_B0
#define NB_MEM_IO_CNTL_B0__MEM_N_CKB_MASK                  0x0000001fL
#define NB_MEM_IO_CNTL_B0__MEM_N_AB_MASK                   0x000003e0L
#define NB_MEM_IO_CNTL_B0__MEM_N_DQMB_MASK                 0x00007c00L
#define NB_MEM_IO_CNTL_B0__MEM_N_DQSB_MASK                 0x000f8000L

// NB_MEM_IO_CNTL_B1
#define NB_MEM_IO_CNTL_B1__MEM_P_CKB_MASK                  0x0000001fL
#define NB_MEM_IO_CNTL_B1__MEM_P_AB_MASK                   0x000003e0L
#define NB_MEM_IO_CNTL_B1__MEM_P_DQMB_MASK                 0x00007c00L
#define NB_MEM_IO_CNTL_B1__MEM_P_DQSB_MASK                 0x000f8000L
#define NB_MEM_IO_CNTL_B1__CLKB_ENABLE_MASK                0x00400000L
#define NB_MEM_IO_CNTL_B1__CLKB_ENABLE                     0x00400000L

// NB_MC_INDEX
#define NB_MC_INDEX__NB_MC_IND_ADDR_MASK                   0x0000003fL
#define NB_MC_INDEX__NB_MC_IND_WR_EN_MASK                  0x00000100L
#define NB_MC_INDEX__NB_MC_IND_WR_EN                       0x00000100L

// NB_MC_DATA
#define NB_MC_DATA__NBMC_DATA_MASK                         0xffffffffL

// MC_GENERAL_PURPOSE
#define MC_GENERAL_PURPOSE__MEM_AIC_CONT_REQ_G1_MASK       0x0000000fL
#define MC_GENERAL_PURPOSE__MEM_AIC_CONT_REQ_G2_MASK       0x000000f0L
#define MC_GENERAL_PURPOSE__MEM_GART_SYNCHRO_FIFO_MASK     0x00000100L
#define MC_GENERAL_PURPOSE__MEM_GART_SYNCHRO_FIFO          0x00000100L
#define MC_GENERAL_PURPOSE__MEM_GART_2DW_MASK              0x00000200L
#define MC_GENERAL_PURPOSE__MEM_GART_2DW                   0x00000200L
#define MC_GENERAL_PURPOSE__MEM_CLOCK_MUX_MASK             0x00000400L
#define MC_GENERAL_PURPOSE__MEM_CLOCK_MUX                  0x00000400L
#define MC_GENERAL_PURPOSE__MEM_DEBUG_GP_RW_MASK           0x000ff800L
#define MC_GENERAL_PURPOSE__MEM_PLL_VCO_MODE_PM_MASK       0x00300000L
#define MC_GENERAL_PURPOSE__MEM_PLL_DIV_8_16_PM_MASK       0x00400000L
#define MC_GENERAL_PURPOSE__MEM_PLL_DIV_8_16_PM            0x00400000L
#define MC_GENERAL_PURPOSE__MEM_PLL_DLL_EN_MASK            0x00800000L
#define MC_GENERAL_PURPOSE__MEM_PLL_DLL_EN                 0x00800000L
#define MC_GENERAL_PURPOSE__MEM_PLL_IN_DLYX_DQS_RB_MASK    0x0f000000L
#define MC_GENERAL_PURPOSE__MEM_PLL_VCO_MODE_RB_MASK       0x30000000L
#define MC_GENERAL_PURPOSE__MEM_PLL_PHD_DN_RB_MASK         0x40000000L
#define MC_GENERAL_PURPOSE__MEM_PLL_PHD_DN_RB              0x40000000L
#define MC_GENERAL_PURPOSE__MEM_PLL_PHD_UP_RB_MASK         0x80000000L
#define MC_GENERAL_PURPOSE__MEM_PLL_PHD_UP_RB              0x80000000L

// MC_IN_TIMING_A
#define MC_IN_TIMING_A__MEMA_DQS_RESET_MASK                0x00000007L
#define MC_IN_TIMING_A__MEMA_DQ_TRANSFER_MASK              0x00000070L
#define MC_IN_TIMING_A__MEMA_DQ_RECEIVER_DYNAMIC_MASK      0x00000100L
#define MC_IN_TIMING_A__MEMA_DQ_RECEIVER_DYNAMIC           0x00000100L
#define MC_IN_TIMING_A__MEMA_DQS_RECEIVER_DYNAMIC_MASK     0x00000200L
#define MC_IN_TIMING_A__MEMA_DQS_RECEIVER_DYNAMIC          0x00000200L
#define MC_IN_TIMING_A__MEMA_STAGE_BYPASS_MASK             0x00000400L
#define MC_IN_TIMING_A__MEMA_STAGE_BYPASS                  0x00000400L
#define MC_IN_TIMING_A__MEMA_POWERED_UP_MASK               0x00001000L
#define MC_IN_TIMING_A__MEMA_POWERED_UP                    0x00001000L
#define MC_IN_TIMING_A__MEMA_TRISTATE_ALL_MASK             0x00002000L
#define MC_IN_TIMING_A__MEMA_TRISTATE_ALL                  0x00002000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_LOCK_MASK           0x00008000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_LOCK                0x00008000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS0_MASK       0x00010000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS0            0x00010000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS1_MASK       0x00020000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS1            0x00020000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS2_MASK       0x00040000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS2            0x00040000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS3_MASK       0x00080000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS3            0x00080000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS4_MASK       0x00100000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS4            0x00100000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS5_MASK       0x00200000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS5            0x00200000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS6_MASK       0x00400000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS6            0x00400000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS7_MASK       0x00800000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_PLL_DQS7            0x00800000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS0_MASK       0x01000000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS0            0x01000000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS1_MASK       0x02000000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS1            0x02000000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS2_MASK       0x04000000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS2            0x04000000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS3_MASK       0x08000000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS3            0x08000000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS4_MASK       0x10000000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS4            0x10000000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS5_MASK       0x20000000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS5            0x20000000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS6_MASK       0x40000000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS6            0x40000000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS7_MASK       0x80000000L
#define MC_IN_TIMING_A__MEMA_IN_DELAYX_INC_DQS7            0x80000000L

// MC_OUT_TIMING_A
#define MC_OUT_TIMING_A__MEMA_CK_SELECTION_MASK            0x0000003fL
#define MC_OUT_TIMING_A__MEMA_DQS_SELECTION_MASK           0x0000ff00L
#define MC_OUT_TIMING_A__MEMA_OUT_TIMING_CK_MASK           0x00070000L
#define MC_OUT_TIMING_A__MEMA_OUT_TIMING_CMD_MASK          0x00300000L
#define MC_OUT_TIMING_A__MEMA_OUT_TIMING_DQ_MASK           0x03000000L
#define MC_OUT_TIMING_A__MEMA_OUT_TIMING_DQS_MASK          0x70000000L

// MC_OUT_DELAY1_A
#define MC_OUT_DELAY1_A__MEMA_DQ_DQS_OE_START_MASK         0x00000003L
#define MC_OUT_DELAY1_A__MEMA_DQ_DQS_OE_STOP_MASK          0x0000000cL
#define MC_OUT_DELAY1_A__MEMA_VIRT_TERM_DQ_MASK            0x00000030L
#define MC_OUT_DELAY1_A__MEMA_VIRT_TERM_DQS_MASK           0x000000c0L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_N_CK_MASK             0x00000100L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_N_CK                  0x00000100L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_P_CK_MASK             0x00000200L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_P_CK                  0x00000200L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_N_CMD_MASK            0x00000400L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_N_CMD                 0x00000400L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_P_CMD_MASK            0x00000800L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_P_CMD                 0x00000800L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_N_DQ_MASK             0x00001000L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_N_DQ                  0x00001000L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_P_DQ_MASK             0x00002000L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_P_DQ                  0x00002000L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_N_DQS_MASK            0x00004000L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_N_DQS                 0x00004000L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_P_DQS_MASK            0x00008000L
#define MC_OUT_DELAY1_A__MEMA_BOUNCE_P_DQS                 0x00008000L
#define MC_OUT_DELAY1_A__MEMA_OUT_DELAY_CK0_MASK           0x00030000L
#define MC_OUT_DELAY1_A__MEMA_OUT_DELAY_CK1_MASK           0x000c0000L
#define MC_OUT_DELAY1_A__MEMA_OUT_DELAY_CK2_MASK           0x00300000L
#define MC_OUT_DELAY1_A__MEMA_OUT_DELAY_CK3_MASK           0x00c00000L
#define MC_OUT_DELAY1_A__MEMA_OUT_DELAY_CK4_MASK           0x03000000L
#define MC_OUT_DELAY1_A__MEMA_OUT_DELAY_CK5_MASK           0x0c000000L
#define MC_OUT_DELAY1_A__MEMA_OUT_DELAY_CMD_MASK           0x30000000L

// MC_OUT_DELAY2_A
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE0_MASK      0x00000003L
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE1_MASK      0x0000000cL
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE2_MASK      0x00000030L
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE3_MASK      0x000000c0L
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE4_MASK      0x00000300L
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE5_MASK      0x00000c00L
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE6_MASK      0x00003000L
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQ_BYTE7_MASK      0x0000c000L
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS0_MASK          0x00030000L
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS1_MASK          0x000c0000L
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS2_MASK          0x00300000L
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS3_MASK          0x00c00000L
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS4_MASK          0x03000000L
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS5_MASK          0x0c000000L
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS6_MASK          0x30000000L
#define MC_OUT_DELAY2_A__MEMA_OUT_DELAY_DQS7_MASK          0xc0000000L

// MC_IN_DELAY1_A
#define MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE0_MASK        0x00000007L
#define MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE1_MASK        0x00000070L
#define MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE2_MASK        0x00000700L
#define MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE3_MASK        0x00007000L
#define MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE4_MASK        0x00070000L
#define MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE5_MASK        0x00700000L
#define MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE6_MASK        0x07000000L
#define MC_IN_DELAY1_A__MEMA_IN_DELAY_DQ_BYTE7_MASK        0x70000000L

// MC_IN_DELAY2_A
#define MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS0_MASK            0x00000007L
#define MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS1_MASK            0x00000070L
#define MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS2_MASK            0x00000700L
#define MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS3_MASK            0x00007000L
#define MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS4_MASK            0x00070000L
#define MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS5_MASK            0x00700000L
#define MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS6_MASK            0x07000000L
#define MC_IN_DELAY2_A__MEMA_IN_DELAY_DQS7_MASK            0x70000000L

// MC_IN_DELAY3_A
#define MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS0_MASK           0x0000000fL
#define MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS1_MASK           0x000000f0L
#define MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS2_MASK           0x00000f00L
#define MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS3_MASK           0x0000f000L
#define MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS4_MASK           0x000f0000L
#define MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS5_MASK           0x00f00000L
#define MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS6_MASK           0x0f000000L
#define MC_IN_DELAY3_A__MEMA_IN_DELAYX_DQS7_MASK           0xf0000000L

// MC_IN_TIMING_B
#define MC_IN_TIMING_B__MEMB_DQS_RESET_MASK                0x00000007L
#define MC_IN_TIMING_B__MEMB_DQ_TRANSFER_MASK              0x00000070L
#define MC_IN_TIMING_B__MEMB_DQ_RECEIVER_DYNAMIC_MASK      0x00000100L
#define MC_IN_TIMING_B__MEMB_DQ_RECEIVER_DYNAMIC           0x00000100L
#define MC_IN_TIMING_B__MEMB_DQS_RECEIVER_DYNAMIC_MASK     0x00000200L
#define MC_IN_TIMING_B__MEMB_DQS_RECEIVER_DYNAMIC          0x00000200L
#define MC_IN_TIMING_B__MEMB_STAGE_BYPASS_MASK             0x00000400L
#define MC_IN_TIMING_B__MEMB_STAGE_BYPASS                  0x00000400L
#define MC_IN_TIMING_B__MEMB_POWERED_UP_MASK               0x00001000L
#define MC_IN_TIMING_B__MEMB_POWERED_UP                    0x00001000L
#define MC_IN_TIMING_B__MEMB_TRISTATE_ALL_MASK             0x00002000L
#define MC_IN_TIMING_B__MEMB_TRISTATE_ALL                  0x00002000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_LOCK_MASK           0x00008000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_LOCK                0x00008000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS0_MASK       0x00010000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS0            0x00010000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS1_MASK       0x00020000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS1            0x00020000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS2_MASK       0x00040000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS2            0x00040000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS3_MASK       0x00080000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS3            0x00080000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS4_MASK       0x00100000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS4            0x00100000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS5_MASK       0x00200000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS5            0x00200000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS6_MASK       0x00400000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS6            0x00400000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS7_MASK       0x00800000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_PLL_DQS7            0x00800000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS0_MASK       0x01000000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS0            0x01000000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS1_MASK       0x02000000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS1            0x02000000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS2_MASK       0x04000000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS2            0x04000000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS3_MASK       0x08000000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS3            0x08000000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS4_MASK       0x10000000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS4            0x10000000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS5_MASK       0x20000000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS5            0x20000000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS6_MASK       0x40000000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS6            0x40000000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS7_MASK       0x80000000L
#define MC_IN_TIMING_B__MEMB_IN_DELAYX_INC_DQS7            0x80000000L

// MC_OUT_TIMING_B
#define MC_OUT_TIMING_B__MEMB_CK_SELECTION_MASK            0x0000003fL
#define MC_OUT_TIMING_B__MEMB_DQS_SELECTION_MASK           0x0000ff00L
#define MC_OUT_TIMING_B__MEMB_OUT_TIMING_CK_MASK           0x00070000L
#define MC_OUT_TIMING_B__MEMB_OUT_TIMING_CMD_MASK          0x00300000L
#define MC_OUT_TIMING_B__MEMB_OUT_TIMING_DQ_MASK           0x03000000L
#define MC_OUT_TIMING_B__MEMB_OUT_TIMING_DQS_MASK          0x70000000L

// MC_OUT_DELAY1_B
#define MC_OUT_DELAY1_B__MEMB_DQ_DQS_OE_START_MASK         0x00000003L
#define MC_OUT_DELAY1_B__MEMB_DQ_DQS_OE_STOP_MASK          0x0000000cL
#define MC_OUT_DELAY1_B__MEMB_VIRT_TERM_DQ_MASK            0x00000030L
#define MC_OUT_DELAY1_B__MEMB_VIRT_TERM_DQS_MASK           0x000000c0L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_N_CK_MASK             0x00000100L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_N_CK                  0x00000100L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_P_CK_MASK             0x00000200L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_P_CK                  0x00000200L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_N_CMD_MASK            0x00000400L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_N_CMD                 0x00000400L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_P_CMD_MASK            0x00000800L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_P_CMD                 0x00000800L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_N_DQ_MASK             0x00001000L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_N_DQ                  0x00001000L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_P_DQ_MASK             0x00002000L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_P_DQ                  0x00002000L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_N_DQS_MASK            0x00004000L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_N_DQS                 0x00004000L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_P_DQS_MASK            0x00008000L
#define MC_OUT_DELAY1_B__MEMB_BOUNCE_P_DQS                 0x00008000L
#define MC_OUT_DELAY1_B__MEMB_OUT_DELAY_CK0_MASK           0x00030000L
#define MC_OUT_DELAY1_B__MEMB_OUT_DELAY_CK1_MASK           0x000c0000L
#define MC_OUT_DELAY1_B__MEMB_OUT_DELAY_CK2_MASK           0x00300000L
#define MC_OUT_DELAY1_B__MEMB_OUT_DELAY_CK3_MASK           0x00c00000L
#define MC_OUT_DELAY1_B__MEMB_OUT_DELAY_CK4_MASK           0x03000000L
#define MC_OUT_DELAY1_B__MEMB_OUT_DELAY_CK5_MASK           0x0c000000L
#define MC_OUT_DELAY1_B__MEMB_OUT_DELAY_CMD_MASK           0x30000000L

// MC_OUT_DELAY2_B
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE0_MASK      0x00000003L
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE1_MASK      0x0000000cL
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE2_MASK      0x00000030L
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE3_MASK      0x000000c0L
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE4_MASK      0x00000300L
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE5_MASK      0x00000c00L
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE6_MASK      0x00003000L
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQ_BYTE7_MASK      0x0000c000L
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS0_MASK          0x00030000L
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS1_MASK          0x000c0000L
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS2_MASK          0x00300000L
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS3_MASK          0x00c00000L
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS4_MASK          0x03000000L
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS5_MASK          0x0c000000L
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS6_MASK          0x30000000L
#define MC_OUT_DELAY2_B__MEMB_OUT_DELAY_DQS7_MASK          0xc0000000L

// MC_IN_DELAY1_B
#define MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE0_MASK        0x00000007L
#define MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE1_MASK        0x00000070L
#define MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE2_MASK        0x00000700L
#define MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE3_MASK        0x00007000L
#define MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE4_MASK        0x00070000L
#define MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE5_MASK        0x00700000L
#define MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE6_MASK        0x07000000L
#define MC_IN_DELAY1_B__MEMB_IN_DELAY_DQ_BYTE7_MASK        0x70000000L

// MC_IN_DELAY2_B
#define MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS0_MASK            0x00000007L
#define MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS1_MASK            0x00000070L
#define MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS2_MASK            0x00000700L
#define MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS3_MASK            0x00007000L
#define MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS4_MASK            0x00070000L
#define MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS5_MASK            0x00700000L
#define MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS6_MASK            0x07000000L
#define MC_IN_DELAY2_B__MEMB_IN_DELAY_DQS7_MASK            0x70000000L

// MC_IN_DELAY3_B
#define MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS0_MASK           0x0000000fL
#define MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS1_MASK           0x000000f0L
#define MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS2_MASK           0x00000f00L
#define MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS3_MASK           0x0000f000L
#define MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS4_MASK           0x000f0000L
#define MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS5_MASK           0x00f00000L
#define MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS6_MASK           0x0f000000L
#define MC_IN_DELAY3_B__MEMB_IN_DELAYX_DQS7_MASK           0xf0000000L

// MC_PLL_IO_CNTL
#define MC_PLL_IO_CNTL__MEM_PLL_PWRDN_MASK                 0x00000001L
#define MC_PLL_IO_CNTL__MEM_PLL_PWRDN                      0x00000001L
#define MC_PLL_IO_CNTL__MEM_PLL_BYPASS_MASK                0x00000002L
#define MC_PLL_IO_CNTL__MEM_PLL_BYPASS                     0x00000002L
#define MC_PLL_IO_CNTL__MEM_PLL_SKEW_1X_MASK               0x0000000cL
#define MC_PLL_IO_CNTL__MEM_PLL_SKEW_2X_MASK               0x00000030L
#define MC_PLL_IO_CNTL__MEM_PLL_SKEW_4X_MASK               0x000000c0L
#define MC_PLL_IO_CNTL__MEM_PLL_REF_DELAY_MASK             0x00000300L
#define MC_PLL_IO_CNTL__MEM_PLL_VCO_DELAY_MASK             0x00000c00L
#define MC_PLL_IO_CNTL__MEM_PLL_VCO_VREF_MASK              0x0000f000L
#define MC_PLL_IO_CNTL__MEM_PLL_CAL_VREF_MASK              0x000f0000L
#define MC_PLL_IO_CNTL__MEM_PLL_CHPUMP_CURRENT_MASK        0x00300000L
#define MC_PLL_IO_CNTL__MEM_PLL_CHPUMP_BANDWIDTH_MASK      0x00400000L
#define MC_PLL_IO_CNTL__MEM_PLL_CHPUMP_BANDWIDTH           0x00400000L
#define MC_PLL_IO_CNTL__MEM_PLL_VCO_BANDWIDTH_MASK         0x00800000L
#define MC_PLL_IO_CNTL__MEM_PLL_VCO_BANDWIDTH              0x00800000L
#define MC_PLL_IO_CNTL__MEM_PLL_VCO_MODE_MASK              0x03000000L
#define MC_PLL_IO_CNTL__MEM_PLL_DIV_8_16_MASK              0x04000000L
#define MC_PLL_IO_CNTL__MEM_PLL_DIV_8_16                   0x04000000L
#define MC_PLL_IO_CNTL__MEM_PLL_VREF_REG_MASK              0x08000000L
#define MC_PLL_IO_CNTL__MEM_PLL_VREF_REG                   0x08000000L
#define MC_PLL_IO_CNTL__MEM_PLL_CONTROL_MASK               0xf0000000L

// MC_IMP_CTRL_SETTING
#define MC_IMP_CTRL_SETTING__MEM_IC_UPDATE_RATE_MASK       0x0000001fL
#define MC_IMP_CTRL_SETTING__MEM_IC_SAMPLE_RATE_MASK       0x00001f00L
#define MC_IMP_CTRL_SETTING__MEM_IC_SAMPLE_SETTLE_MASK     0x000f0000L
#define MC_IMP_CTRL_SETTING__MEM_IC_INC_THRESHOLD_MASK     0x00f00000L
#define MC_IMP_CTRL_SETTING__MEM_IC_DEC_THRESHOLD_MASK     0x0f000000L
#define MC_IMP_CTRL_SETTING__MEM_IC_OSC_MASK               0x10000000L
#define MC_IMP_CTRL_SETTING__MEM_IC_OSC                    0x10000000L
#define MC_IMP_CTRL_SETTING__MEM_IC_ENABLE_MASK            0x80000000L
#define MC_IMP_CTRL_SETTING__MEM_IC_ENABLE                 0x80000000L

// MC_IMP_CTRL_REF
#define MC_IMP_CTRL_REF__MEM_STRENGTH_N_REF_MASK           0x0000000fL
#define MC_IMP_CTRL_REF__MEM_STRENGTH_P_REF_MASK           0x000000f0L
#define MC_IMP_CTRL_REF__MEM_READ_BACK_N_REF_MASK          0x00000f00L
#define MC_IMP_CTRL_REF__MEM_READ_BACK_P_REF_MASK          0x0000f000L
#define MC_IMP_CTRL_REF__MEM_DEBUG_IC_RW_MASK              0xffff0000L

// MC_IMP_CTRL_STRENGTH_A
#define MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_N_CK_MASK    0x0000000fL
#define MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_N_CMD_MASK   0x000000f0L
#define MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_N_DQ_MASK    0x00000f00L
#define MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_N_DQS_MASK   0x0000f000L
#define MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_P_CK_MASK    0x000f0000L
#define MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_P_CMD_MASK   0x00f00000L
#define MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_P_DQ_MASK    0x0f000000L
#define MC_IMP_CTRL_STRENGTH_A__MEMA_STRENGTH_P_DQS_MASK   0xf0000000L

// MC_IMP_CTRL_STEP_A
#define MC_IMP_CTRL_STEP_A__MEMA_STEP_N_CK_MASK            0x00000003L
#define MC_IMP_CTRL_STEP_A__MEMA_STEP_N_CMD_MASK           0x00000030L
#define MC_IMP_CTRL_STEP_A__MEMA_STEP_N_DQ_MASK            0x00000300L
#define MC_IMP_CTRL_STEP_A__MEMA_STEP_N_DQS_MASK           0x00003000L
#define MC_IMP_CTRL_STEP_A__MEMA_STEP_P_CK_MASK            0x00030000L
#define MC_IMP_CTRL_STEP_A__MEMA_STEP_P_CMD_MASK           0x00300000L
#define MC_IMP_CTRL_STEP_A__MEMA_STEP_P_DQ_MASK            0x03000000L
#define MC_IMP_CTRL_STEP_A__MEMA_STEP_P_DQS_MASK           0x30000000L

// MC_IMP_CTRL_READ_BACK_A
#define MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_N_CK_MASK  0x0000000fL
#define MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_N_CMD_MASK 0x000000f0L
#define MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_N_DQ_MASK  0x00000f00L
#define MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_N_DQS_MASK 0x0000f000L
#define MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_P_CK_MASK  0x000f0000L
#define MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_P_CMD_MASK 0x00f00000L
#define MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_P_DQ_MASK  0x0f000000L
#define MC_IMP_CTRL_READ_BACK_A__MEMA_READ_BACK_P_DQS_MASK 0xf0000000L

// MC_IMP_CTRL_STRENGTH_B
#define MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_N_CK_MASK    0x0000000fL
#define MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_N_CMD_MASK   0x000000f0L
#define MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_N_DQ_MASK    0x00000f00L
#define MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_N_DQS_MASK   0x0000f000L
#define MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_P_CK_MASK    0x000f0000L
#define MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_P_CMD_MASK   0x00f00000L
#define MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_P_DQ_MASK    0x0f000000L
#define MC_IMP_CTRL_STRENGTH_B__MEMB_STRENGTH_P_DQS_MASK   0xf0000000L

// MC_IMP_CTRL_STEP_B
#define MC_IMP_CTRL_STEP_B__MEMB_STEP_N_CK_MASK            0x00000003L
#define MC_IMP_CTRL_STEP_B__MEMB_STEP_N_CMD_MASK           0x00000030L
#define MC_IMP_CTRL_STEP_B__MEMB_STEP_N_DQ_MASK            0x00000300L
#define MC_IMP_CTRL_STEP_B__MEMB_STEP_N_DQS_MASK           0x00003000L
#define MC_IMP_CTRL_STEP_B__MEMB_STEP_P_CK_MASK            0x00030000L
#define MC_IMP_CTRL_STEP_B__MEMB_STEP_P_CMD_MASK           0x00300000L
#define MC_IMP_CTRL_STEP_B__MEMB_STEP_P_DQ_MASK            0x03000000L
#define MC_IMP_CTRL_STEP_B__MEMB_STEP_P_DQS_MASK           0x30000000L

// MC_IMP_CTRL_READ_BACK_B
#define MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_N_CK_MASK  0x0000000fL
#define MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_N_CMD_MASK 0x000000f0L
#define MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_N_DQ_MASK  0x00000f00L
#define MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_N_DQS_MASK 0x0000f000L
#define MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_P_CK_MASK  0x000f0000L
#define MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_P_CMD_MASK 0x00f00000L
#define MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_P_DQ_MASK  0x0f000000L
#define MC_IMP_CTRL_READ_BACK_B__MEMB_READ_BACK_P_DQS_MASK 0xf0000000L

// MC_MISC_CNTL
#define MC_MISC_CNTL__MRA_ARB_RATIOONLY_MASK               0x00000001L
#define MC_MISC_CNTL__MRA_ARB_RATIOONLY                    0x00000001L
#define MC_MISC_CNTL__DISABLE_GTW_MASK                     0x00000002L
#define MC_MISC_CNTL__DISABLE_GTW                          0x00000002L
#define MC_MISC_CNTL__MRA_ARB_BIURATIO_MASK                0x0000000cL
#define MC_MISC_CNTL__MRA_ARB_AGPRATIO_MASK                0x00000030L
#define MC_MISC_CNTL__SEQUENTIAL_REFRESH_MASK              0x00000040L
#define MC_MISC_CNTL__SEQUENTIAL_REFRESH                   0x00000040L
#define MC_MISC_CNTL__PM_SEQUENTIAL_REFRESH_MASK           0x00000080L
#define MC_MISC_CNTL__PM_SEQUENTIAL_REFRESH                0x00000080L
#define MC_MISC_CNTL__SQBYPASS_TIMER_MASK                  0x00000f00L
#define MC_MISC_CNTL__GTW_LAC_EN_MASK                      0x00001000L
#define MC_MISC_CNTL__GTW_LAC_EN                           0x00001000L
#define MC_MISC_CNTL__RBB_MRA_AGPBIU_COHERENCY_DISABLE_MASK 0x00002000L
#define MC_MISC_CNTL__RBB_MRA_AGPBIU_COHERENCY_DISABLE     0x00002000L
#define MC_MISC_CNTL__INPUT_AGPHIPRI_MUTE_MASK             0x00004000L
#define MC_MISC_CNTL__INPUT_AGPHIPRI_MUTE                  0x00004000L
#define MC_MISC_CNTL__EXT_GC_LATENCY_TIMER_MASK            0x00008000L
#define MC_MISC_CNTL__EXT_GC_LATENCY_TIMER                 0x00008000L
#define MC_MISC_CNTL__DIS_BYPASS_LOAD_MASK                 0x00010000L
#define MC_MISC_CNTL__DIS_BYPASS_LOAD                      0x00010000L
#define MC_MISC_CNTL__DISP2_HiPri_MASK                     0x00020000L
#define MC_MISC_CNTL__DISP2_HiPri                          0x00020000L
#define MC_MISC_CNTL__DISP2_HiPri2_MASK                    0x00040000L
#define MC_MISC_CNTL__DISP2_HiPri2                         0x00040000L
#define MC_MISC_CNTL__Reserved_MASK                        0x00f00000L
#define MC_MISC_CNTL__SB_BLOCK_AGP_DIS_MASK                0x01000000L
#define MC_MISC_CNTL__SB_BLOCK_AGP_DIS                     0x01000000L
#define MC_MISC_CNTL__DISABLE_EXTRA_DECK_STAGES_MASK       0x02000000L
#define MC_MISC_CNTL__DISABLE_EXTRA_DECK_STAGES            0x02000000L
#define MC_MISC_CNTL__SQSM_PERF_FIX_MASK                   0x04000000L
#define MC_MISC_CNTL__SQSM_PERF_FIX                        0x04000000L
#define MC_MISC_CNTL__SEQ_RFSH_RESET_TRC_EN_MASK           0x08000000L
#define MC_MISC_CNTL__SEQ_RFSH_RESET_TRC_EN                0x08000000L
#define MC_MISC_CNTL__BANK_ADDR_REMAP_EN_MASK              0x10000000L
#define MC_MISC_CNTL__BANK_ADDR_REMAP_EN                   0x10000000L
#define MC_MISC_CNTL__BANK_ALIGN_MODE_MASK                 0x60000000L
#define MC_MISC_CNTL__DEBUGBUS_CYCLE_EN_MASK               0x80000000L
#define MC_MISC_CNTL__DEBUGBUS_CYCLE_EN                    0x80000000L

// NB_MC_TEST_DEBUG
#define NB_MC_TEST_DEBUG__NB_MC_DEBUG_BITS_MASK            0xffffffffL

// NB_MEM_SIZE_A
#define NB_MEM_SIZE_A__CS0_SIZE_MASK                       0x00000007L
#define NB_MEM_SIZE_A__CS0_AP_MAP_MASK                     0x00000030L
#define NB_MEM_SIZE_A__CS1_SIZE_MASK                       0x00000700L
#define NB_MEM_SIZE_A__CS1_AP_MAP_MASK                     0x00003000L
#define NB_MEM_SIZE_A__CS2_SIZE_MASK                       0x00070000L
#define NB_MEM_SIZE_A__CS2_AP_MAP_MASK                     0x00300000L
#define NB_MEM_SIZE_A__CS3_SIZE_MASK                       0x07000000L
#define NB_MEM_SIZE_A__CS3_AP_MAP_MASK                     0x30000000L

// NB_MEM_SIZE_B
#define NB_MEM_SIZE_B__CS0_SIZE_MASK                       0x00000007L
#define NB_MEM_SIZE_B__CS0_AP_MAP_MASK                     0x00000030L
#define NB_MEM_SIZE_B__CS1_SIZE_MASK                       0x00000700L
#define NB_MEM_SIZE_B__CS1_AP_MAP_MASK                     0x00003000L
#define NB_MEM_SIZE_B__CS2_SIZE_MASK                       0x00070000L
#define NB_MEM_SIZE_B__CS2_AP_MAP_MASK                     0x00300000L
#define NB_MEM_SIZE_B__CS3_SIZE_MASK                       0x07000000L
#define NB_MEM_SIZE_B__CS3_AP_MAP_MASK                     0x30000000L

// NB_MEM_CNTL0
#define NB_MEM_CNTL0__INTERLEAVE_MODE_MASK                 0x00000003L
#define NB_MEM_CNTL0__PRIMARY_CHANNEL_MASK                 0x00000004L
#define NB_MEM_CNTL0__PRIMARY_CHANNEL                      0x00000004L
#define NB_MEM_CNTL0__NUMBER_CHANNEL_MASK                  0x00000008L
#define NB_MEM_CNTL0__NUMBER_CHANNEL                       0x00000008L
#define NB_MEM_CNTL0__CHANNEL_MAPPING_NB_MASK              0x00000030L
#define NB_MEM_CNTL0__CHANNEL_MAPPING_GFX_MASK             0x00000040L
#define NB_MEM_CNTL0__CHANNEL_MAPPING_GFX                  0x00000040L
#define NB_MEM_CNTL0__INTERLEAVE_START_MASK                0xff000000L

// NB_EXT_MEM_CNTL
#define NB_EXT_MEM_CNTL__MEM_TRP_MASK                      0x00000003L
#define NB_EXT_MEM_CNTL__MEM_TRCD_MASK                     0x0000000cL
#define NB_EXT_MEM_CNTL__MEM_TRAS_MASK                     0x00000070L
#define NB_EXT_MEM_CNTL__MEM_TRRD_MASK                     0x00000300L
#define NB_EXT_MEM_CNTL__MEM_TR2W_MASK                     0x00000c00L
#define NB_EXT_MEM_CNTL__MEM_TWR_MASK                      0x00003000L
#define NB_EXT_MEM_CNTL__MEM_TW2R_MASK                     0x0000c000L
#define NB_EXT_MEM_CNTL__MEM_TR2R_MASK                     0x00030000L
#define NB_EXT_MEM_CNTL__MEM_TWR_MODE_MASK                 0x00040000L
#define NB_EXT_MEM_CNTL__MEM_TWR_MODE                      0x00040000L
#define NB_EXT_MEM_CNTL__MEM_REFRESH_DIS_MASK              0x00100000L
#define NB_EXT_MEM_CNTL__MEM_REFRESH_DIS                   0x00100000L
#define NB_EXT_MEM_CNTL__MEM_REFRESH_COUNT_MASK            0x00e00000L
#define NB_EXT_MEM_CNTL__MEM_REFRESH_RATE_MASK             0xff000000L

// NB_FB_LOCATION
#define NB_FB_LOCATION__MC_FB_START_MASK                   0x0000ffffL
#define NB_FB_LOCATION__MC_FB_TOP_MASK                     0xffff0000L

// NB_MC_DEBUG
#define NB_MC_DEBUG__Reserved0_MASK                        0x00000001L
#define NB_MC_DEBUG__Reserved0                             0x00000001L
#define NB_MC_DEBUG__SEQ_HOLE_DIS_MASK                     0x00000002L
#define NB_MC_DEBUG__SEQ_HOLE_DIS                          0x00000002L
#define NB_MC_DEBUG__DISABLE_AP_MASK                       0x00000004L
#define NB_MC_DEBUG__DISABLE_AP                            0x00000004L
#define NB_MC_DEBUG__RBS_STALL_FIFO_MASK                   0x00000008L
#define NB_MC_DEBUG__RBS_STALL_FIFO                        0x00000008L
#define NB_MC_DEBUG__Reserved1_MASK                        0x00000010L
#define NB_MC_DEBUG__Reserved1                             0x00000010L
#define NB_MC_DEBUG__DLL_DISABLE_PM_MASK                   0x00000020L
#define NB_MC_DEBUG__DLL_DISABLE_PM                        0x00000020L
#define NB_MC_DEBUG__FB_ACCESS_EN_MASK                     0x00000040L
#define NB_MC_DEBUG__FB_ACCESS_EN                          0x00000040L
#define NB_MC_DEBUG__ASYN_ONE_MASK                         0x00000080L
#define NB_MC_DEBUG__ASYN_ONE                              0x00000080L
#define NB_MC_DEBUG__NC_DEBUG_MUX_MASK                     0x00007f00L
#define NB_MC_DEBUG__MC_DEBUG_EN_MASK                      0x00008000L
#define NB_MC_DEBUG__MC_DEBUG_EN                           0x00008000L
#define NB_MC_DEBUG__TESTBUS_INT_MASK                      0xffff0000L

// MC0_PERF_COUNT0
#define MC0_PERF_COUNT0__COUNTER0_MASK                     0xffffffffL

// MC0_PERF_COUNT1
#define MC0_PERF_COUNT1__COUNTER1_MASK                     0xffffffffL

// MC0_PERF_CNTL
#define MC0_PERF_CNTL__EVENT0_SEL_MASK                     0x000000ffL
#define MC0_PERF_CNTL__EVENT1_SEL_MASK                     0x0000ff00L
#define MC0_PERF_CNTL__COUNTER0_UPPER_MASK                 0x00ff0000L
#define MC0_PERF_CNTL__COUNTER1_UPPER_MASK                 0xff000000L

// MC1_PERF_COUNT0
#define MC1_PERF_COUNT0__COUNTER0_MASK                     0xffffffffL

// MC1_PERF_COUNT1
#define MC1_PERF_COUNT1__COUNTER1_MASK                     0xffffffffL

// MC1_PERF_CNTL
#define MC1_PERF_CNTL__EVENT0_SEL_MASK                     0x000000ffL
#define MC1_PERF_CNTL__EVENT1_SEL_MASK                     0x0000ff00L
#define MC1_PERF_CNTL__COUNTER0_UPPER_MASK                 0x00ff0000L
#define MC1_PERF_CNTL__COUNTER1_UPPER_MASK                 0xff000000L

// MC_PM_CNTL
#define MC_PM_CNTL__AUTO_CLOCK_THROTTLING_MASK             0x00000001L
#define MC_PM_CNTL__AUTO_CLOCK_THROTTLING                  0x00000001L
#define MC_PM_CNTL__CLOCK_THROTTLING_EN_MASK               0x00000002L
#define MC_PM_CNTL__CLOCK_THROTTLING_EN                    0x00000002L
#define MC_PM_CNTL__THROTTLE_STATE_SETTING_MASK            0x0000000cL
#define MC_PM_CNTL__AUTO_CLOCK_THROTTLING_NB_MASK          0x00000010L
#define MC_PM_CNTL__AUTO_CLOCK_THROTTLING_NB               0x00000010L
#define MC_PM_CNTL__CLOCK_THROTTLING_EN_NB_MASK            0x00000020L
#define MC_PM_CNTL__CLOCK_THROTTLING_EN_NB                 0x00000020L
#define MC_PM_CNTL__THROTTLE_STATE_SETTING_NB_MASK         0x000000c0L
#define MC_PM_CNTL__BLACKOUT_NB_DELAY_MASK                 0x00000100L
#define MC_PM_CNTL__BLACKOUT_NB_DELAY                      0x00000100L
#define MC_PM_CNTL__PM_MEM_REFRESH_COUNT_MASK              0x00007000L
#define MC_PM_CNTL__PM_MEM_REFRESH_RATE_MASK               0x00ff0000L
#define MC_PM_CNTL__THROTTLE_READ_EN_MASK                  0x01000000L
#define MC_PM_CNTL__THROTTLE_READ_EN                       0x01000000L
#define MC_PM_CNTL__THROTTLE_WRITE_EN_MASK                 0x02000000L
#define MC_PM_CNTL__THROTTLE_WRITE_EN                      0x02000000L
#define MC_PM_CNTL__THROTTLE_DISP_EN_MASK                  0x04000000L
#define MC_PM_CNTL__THROTTLE_DISP_EN                       0x04000000L
#define MC_PM_CNTL__MULTIPLE_CKE_MASK                      0x18000000L

// BIU_PERF_COUNT0_mc
#define BIU_PERF_COUNT0_mc__COUNTER0_MASK                  0xffffffffL

// BIU_PERF_COUNT1_mc
#define BIU_PERF_COUNT1_mc__COUNTER1_MASK                  0xffffffffL

// BIU_PERF_CNTL_mc
#define BIU_PERF_CNTL_mc__EVENT0_SEL_MASK                  0x000000ffL
#define BIU_PERF_CNTL_mc__EVENT1_SEL_MASK                  0x0000ff00L
#define BIU_PERF_CNTL_mc__COUNTER0_UPPER_MASK              0x00ff0000L
#define BIU_PERF_CNTL_mc__COUNTER1_UPPER_MASK              0xff000000L

// PM_MEM_SDRAM_EXTENDED_MODE_REG
#define PM_MEM_SDRAM_EXTENDED_MODE_REG__PM_MEM_EXTENDED_MODE_REG_MASK 0x0000ffffL
#define PM_MEM_SDRAM_EXTENDED_MODE_REG__RESERVE0_MASK      0x7fff0000L
#define PM_MEM_SDRAM_EXTENDED_MODE_REG__PM_EMRS_EN_MASK    0x80000000L
#define PM_MEM_SDRAM_EXTENDED_MODE_REG__PM_EMRS_EN         0x80000000L

// NB_MC_STATUS
#define NB_MC_STATUS__MEM_PWRUP_COMPL_A_MASK               0x00000001L
#define NB_MC_STATUS__MEM_PWRUP_COMPL_A                    0x00000001L
#define NB_MC_STATUS__MEM_PWRUP_COMPL_B_MASK               0x00000002L
#define NB_MC_STATUS__MEM_PWRUP_COMPL_B                    0x00000002L
#define NB_MC_STATUS__MC_IDLE_MASK                         0x00000004L
#define NB_MC_STATUS__MC_IDLE                              0x00000004L
#define NB_MC_STATUS__NB_IDLE_MASK                         0x00000008L
#define NB_MC_STATUS__NB_IDLE                              0x00000008L
#define NB_MC_STATUS__SYSM_IDLE_MASK                       0x00010000L
#define NB_MC_STATUS__SYSM_IDLE                            0x00010000L
#define NB_MC_STATUS__SYSM_SHUTDOWN_MASK                   0x00020000L
#define NB_MC_STATUS__SYSM_SHUTDOWN                        0x00020000L
#define NB_MC_STATUS__SYSM_PARKED_MASK                     0x00040000L
#define NB_MC_STATUS__SYSM_PARKED                          0x00040000L
#define NB_MC_STATUS__DLL_READY_MASK                       0x00080000L
#define NB_MC_STATUS__DLL_READY                            0x00080000L

// NB_CPU_AUTOCAL_VAL
#define NB_CPU_AUTOCAL_VAL__CPU_AUTOCAL_VAL_P_MASK         0x0000001fL
#define NB_CPU_AUTOCAL_VAL__CPU_AUTOCAL_VAL_N_A5_MASK      0x00000f00L

// NB_BIU_DBF
#define NB_BIU_DBF__DBF_EN_BIU_MASK                        0x00000001L
#define NB_BIU_DBF__DBF_EN_BIU                             0x00000001L
#define NB_BIU_DBF__DBF_EN_CALIB_MASK                      0x00000002L
#define NB_BIU_DBF__DBF_EN_CALIB                           0x00000002L
#define NB_BIU_DBF__DBF_EN_PCI_SLAVE_MASK                  0x00000004L
#define NB_BIU_DBF__DBF_EN_PCI_SLAVE                       0x00000004L
#define NB_BIU_DBF__DBF_EN_GRT_MASK                        0x00000008L
#define NB_BIU_DBF__DBF_EN_GRT                             0x00000008L
#define NB_BIU_DBF__DBF_EN_M2C_MASK                        0x00000010L
#define NB_BIU_DBF__DBF_EN_M2C                             0x00000010L
#define NB_BIU_DBF__DBF_EN_LMU_MASK                        0x00000020L
#define NB_BIU_DBF__DBF_EN_LMU                             0x00000020L
#define NB_BIU_DBF__DBF_EN_SMU_MASK                        0x00000040L
#define NB_BIU_DBF__DBF_EN_SMU                             0x00000040L

// NB_BIU_CFG2
#define NB_BIU_CFG2__DPWRMode_MASK                         0x00000003L
#define NB_BIU_CFG2__DPWRWaitOff_MASK                      0x0000000cL
#define NB_BIU_CFG2__DatDRENOffIdle_MASK                   0x00000010L
#define NB_BIU_CFG2__DatDRENOffIdle                        0x00000010L
#define NB_BIU_CFG2__AddrDRENOnBR0_MASK                    0x00000020L
#define NB_BIU_CFG2__AddrDRENOnBR0                         0x00000020L
#define NB_BIU_CFG2__PciSlvWrtOptEn_MASK                   0x00000040L
#define NB_BIU_CFG2__PciSlvWrtOptEn                        0x00000040L
#define NB_BIU_CFG2__PciSlvRdOptEn_MASK                    0x00000080L
#define NB_BIU_CFG2__PciSlvRdOptEn                         0x00000080L
#define NB_BIU_CFG2__UpdREGatIdle_MASK                     0x00000100L
#define NB_BIU_CFG2__UpdREGatIdle                          0x00000100L
#define NB_BIU_CFG2__CpuFbAccessEn_MASK                    0x00000200L
#define NB_BIU_CFG2__CpuFbAccessEn                         0x00000200L
#define NB_BIU_CFG2__PciMstBnrEn_MASK                      0x00000400L
#define NB_BIU_CFG2__PciMstBnrEn                           0x00000400L
#define NB_BIU_CFG2__BypassRdDataOff_MASK                  0x00000800L
#define NB_BIU_CFG2__BypassRdDataOff                       0x00000800L
#define NB_BIU_CFG2__DbgCntrMode_MASK                      0x00001000L
#define NB_BIU_CFG2__DbgCntrMode                           0x00001000L
#define NB_BIU_CFG2__LaqThreshold_MASK                     0x00006000L
#define NB_BIU_CFG2__SaqThreshold_MASK                     0x00018000L
#define NB_BIU_CFG2__XClkLatency_MASK                      0x00060000L

// NB_CPU_AUTOCAL_SEL
#define NB_CPU_AUTOCAL_SEL__CalibIOSel_MASK                0x00000007L
#define NB_CPU_AUTOCAL_SEL__CalibSampleSel_MASK            0x00000018L
#define NB_CPU_AUTOCAL_SEL__CalibBiuIdleUpdMode_MASK       0x00000020L
#define NB_CPU_AUTOCAL_SEL__CalibBiuIdleUpdMode            0x00000020L
#define NB_CPU_AUTOCAL_SEL__Reserved_MASK                  0x000000c0L

// NB_CPU_STR_MODIFIER
#define NB_CPU_STR_MODIFIER__ModCalib2xSTR_MASK            0x00000007L
#define NB_CPU_STR_MODIFIER__ModCalib2xstbSTR_MASK         0x00000038L
#define NB_CPU_STR_MODIFIER__Reserved1_MASK                0x000000c0L
#define NB_CPU_STR_MODIFIER__ModCalib4xSTR_MASK            0x00000700L
#define NB_CPU_STR_MODIFIER__ModCalib4xstbSTR_MASK         0x00003800L
#define NB_CPU_STR_MODIFIER__ModCalibSTRDisable_MASK       0x00004000L
#define NB_CPU_STR_MODIFIER__ModCalibSTRDisable            0x00004000L
#define NB_CPU_STR_MODIFIER__Reserved2_MASK                0x00008000L
#define NB_CPU_STR_MODIFIER__Reserved2                     0x00008000L

// NB_CPU_AUTOCAL_PROGRAM_STR
#define NB_CPU_AUTOCAL_PROGRAM_STR__CPU_PROGRAM_PSTR_MASK  0x0000001fL
#define NB_CPU_AUTOCAL_PROGRAM_STR__CPU_PROGRAM_NSTR_MASK  0x00000f00L

// NB_AGP_GRFXIO_CNTL
#define NB_AGP_GRFXIO_CNTL__AGPPAD_TMDS_EN_MASK            0x00000001L
#define NB_AGP_GRFXIO_CNTL__AGPPAD_TMDS_EN                 0x00000001L
#define NB_AGP_GRFXIO_CNTL__AGPPAD_SS_EN_MASK              0x00000002L
#define NB_AGP_GRFXIO_CNTL__AGPPAD_SS_EN                   0x00000002L
#define NB_AGP_GRFXIO_CNTL__AGPPAD_LVDS_EN_MASK            0x00000004L
#define NB_AGP_GRFXIO_CNTL__AGPPAD_LVDS_EN                 0x00000004L
#define NB_AGP_GRFXIO_CNTL__AGPPAD_VID_EN_MASK             0x00000008L
#define NB_AGP_GRFXIO_CNTL__AGPPAD_VID_EN                  0x00000008L
#define NB_AGP_GRFXIO_CNTL__AGPPAD_CLK_RUN_EN_MASK         0x00000010L
#define NB_AGP_GRFXIO_CNTL__AGPPAD_CLK_RUN_EN              0x00000010L
#define NB_AGP_GRFXIO_CNTL__AGPPAD_STP_AGP_EN_MASK         0x00000020L
#define NB_AGP_GRFXIO_CNTL__AGPPAD_STP_AGP_EN              0x00000020L
#define NB_AGP_GRFXIO_CNTL__AGPPAD_HPD2_EN_MASK            0x00000040L
#define NB_AGP_GRFXIO_CNTL__AGPPAD_HPD2_EN                 0x00000040L
#define NB_AGP_GRFXIO_CNTL__AGPPAD_GPIO_EN_MASK            0x00000080L
#define NB_AGP_GRFXIO_CNTL__AGPPAD_GPIO_EN                 0x00000080L

// NB_CPU_PAD_STR
#define NB_CPU_PAD_STR__CPU_PAD_PSTR_MASK                  0x0000001fL
#define NB_CPU_PAD_STR__CPU_PAD_NSTR_MASK                  0x00000f00L

// OSC_CONTROL
#define OSC_CONTROL__OSC_EN_MASK                           0x00000001L
#define OSC_CONTROL__OSC_EN                                0x00000001L
#define OSC_CONTROL__XTAL_LOW_GAIN_MASK                    0x00000002L
#define OSC_CONTROL__XTAL_LOW_GAIN                         0x00000002L
#define OSC_CONTROL__Reserved0_MASK                        0x00000008L
#define OSC_CONTROL__Reserved0                             0x00000008L
#define OSC_CONTROL__CPU_STOP_ENABLE_MASK                  0x00000010L
#define OSC_CONTROL__CPU_STOP_ENABLE                       0x00000010L
#define OSC_CONTROL__DC_STOP_ENABLE_MASK                   0x00000020L
#define OSC_CONTROL__DC_STOP_ENABLE                        0x00000020L
#define OSC_CONTROL__PCICLK_OE_TOGGLE_MASK                 0x000007c0L
#define OSC_CONTROL__Reserved1_MASK                        0x00000800L
#define OSC_CONTROL__Reserved1                             0x00000800L
#define OSC_CONTROL__CPUCLK_SE_OE_TOGGLE_MASK              0x00001000L
#define OSC_CONTROL__CPUCLK_SE_OE_TOGGLE                   0x00001000L
#define OSC_CONTROL__CPUCLK_DIFF_OE_TOGGLE_MASK            0x00002000L
#define OSC_CONTROL__CPUCLK_DIFF_OE_TOGGLE                 0x00002000L
#define OSC_CONTROL__REF_14M_OE_TOGGLE_MASK                0x00004000L
#define OSC_CONTROL__REF_14M_OE_TOGGLE                     0x00004000L
#define OSC_CONTROL__APIC_CLK_OE_TOGGLE_MASK               0x00018000L
#define OSC_CONTROL__REF_24M_48M_OE_TOGGLE_MASK            0x00020000L
#define OSC_CONTROL__REF_24M_48M_OE_TOGGLE                 0x00020000L
#define OSC_CONTROL__ON_CHIP_CLOCK_GENERATOR_MASK          0x00040000L
#define OSC_CONTROL__ON_CHIP_CLOCK_GENERATOR               0x00040000L
#define OSC_CONTROL__SYSCLK_OE_TOGGLE_MASK                 0x00080000L
#define OSC_CONTROL__SYSCLK_OE_TOGGLE                      0x00080000L
#define OSC_CONTROL__MEMCLK_OE_TOGGLE_MASK                 0x00100000L
#define OSC_CONTROL__MEMCLK_OE_TOGGLE                      0x00100000L

// SPLL_CONTROL
#define SPLL_CONTROL__SPLL_IPSCREF_MASK                    0x00000007L
#define SPLL_CONTROL__SPLL_IPSCFB_MASK                     0x00000038L
#define SPLL_CONTROL__SPLL_IPSCA_MASK                      0x000001c0L
#define SPLL_CONTROL__SPLL_IPSCB_MASK                      0x00000e00L
#define SPLL_CONTROL__SPLL_IPSCC_MASK                      0x00007000L
#define SPLL_CONTROL__SPLL_IPVG_MASK                       0x00070000L
#define SPLL_CONTROL__SPLL_IPCP_MASK                       0x00700000L
#define SPLL_CONTROL__SPLL_TCPOFF_MASK                     0x01000000L
#define SPLL_CONTROL__SPLL_TCPOFF                          0x01000000L
#define SPLL_CONTROL__SPLL_ITVCOMAX_MASK                   0x02000000L
#define SPLL_CONTROL__SPLL_ITVCOMAX                        0x02000000L
#define SPLL_CONTROL__SPLL_BYPASS_MASK                     0x10000000L
#define SPLL_CONTROL__SPLL_BYPASS                          0x10000000L
#define SPLL_CONTROL__SPLL_POWERDOWN_DLY_MASK              0x60000000L
#define SPLL_CONTROL__SPLL_POWERDOWN_MASK                  0x80000000L
#define SPLL_CONTROL__SPLL_POWERDOWN                       0x80000000L

// MPLL_CONTROL
#define MPLL_CONTROL__MPLL_DELTA_FRACTION_MASK             0x00000007L
#define MPLL_CONTROL__MPLL_DELTA_INTEGER_MASK              0x000001f8L
#define MPLL_CONTROL__MPLL_TCPOFF_MASK                     0x00000200L
#define MPLL_CONTROL__MPLL_TCPOFF                          0x00000200L
#define MPLL_CONTROL__MPLL_TVCOMAX_MASK                    0x00000400L
#define MPLL_CONTROL__MPLL_TVCOMAX                         0x00000400L
#define MPLL_CONTROL__MPLL_TMONEN_MASK                     0x00000800L
#define MPLL_CONTROL__MPLL_TMONEN                          0x00000800L
#define MPLL_CONTROL__MPLL_PCP_MASK                        0x00007000L
#define MPLL_CONTROL__MPLL_PVG_MASK                        0x00070000L
#define MPLL_CONTROL__MPLL_PDC_MASK                        0x00180000L
#define MPLL_CONTROL__MPLL_STEP_SIZE_MASK                  0x00c00000L
#define MPLL_CONTROL__MPLL_DELAY_MASK                      0x07000000L
#define MPLL_CONTROL__MPLL_SS_EN_MASK                      0x08000000L
#define MPLL_CONTROL__MPLL_SS_EN                           0x08000000L
#define MPLL_CONTROL__MPLL_BYPASS_MASK                     0x10000000L
#define MPLL_CONTROL__MPLL_BYPASS                          0x10000000L
#define MPLL_CONTROL__MPLL_POWERDOWN_DLY_MASK              0x60000000L
#define MPLL_CONTROL__MPLL_POWERDOWN_MASK                  0x80000000L
#define MPLL_CONTROL__MPLL_POWERDOWN                       0x80000000L

// BPLL_CONTROL
#define BPLL_CONTROL__BPLL_IPSCREF_MASK                    0x00000007L
#define BPLL_CONTROL__BPLL_IPSCFB_MASK                     0x00000038L
#define BPLL_CONTROL__BPLL_IPSCA_MASK                      0x000001c0L
#define BPLL_CONTROL__BPLL_IPSCB_MASK                      0x00000e00L
#define BPLL_CONTROL__BPLL_IPSCC_MASK                      0x00007000L
#define BPLL_CONTROL__BPLL_IPVG_MASK                       0x00070000L
#define BPLL_CONTROL__BPLL_IPCP_MASK                       0x00700000L
#define BPLL_CONTROL__BPLL_TCPOFF_MASK                     0x01000000L
#define BPLL_CONTROL__BPLL_TCPOFF                          0x01000000L
#define BPLL_CONTROL__BPLL_ITVCOMAX_MASK                   0x02000000L
#define BPLL_CONTROL__BPLL_ITVCOMAX                        0x02000000L
#define BPLL_CONTROL__BPLL_BYPASS_MASK                     0x10000000L
#define BPLL_CONTROL__BPLL_BYPASS                          0x10000000L
#define BPLL_CONTROL__BPLL_POWERDOWN_DLY_MASK              0x60000000L
#define BPLL_CONTROL__BPLL_POWERDOWN_MASK                  0x80000000L
#define BPLL_CONTROL__BPLL_POWERDOWN                       0x80000000L

// UPLL_CONTROL
#define UPLL_CONTROL__UPLL_MDIV_MASK                       0x000003ffL
#define UPLL_CONTROL__UPLL_NDIV_MASK                       0x000ffc00L
#define UPLL_CONTROL__UPLL_PDIV_MASK                       0x01f00000L
#define UPLL_CONTROL__UPLL_REF_SEL_MASK                    0x0e000000L
#define UPLL_CONTROL__UPLL_BYPASS_MASK                     0x10000000L
#define UPLL_CONTROL__UPLL_BYPASS                          0x10000000L
#define UPLL_CONTROL__UPLL_RST_MASK                        0x20000000L
#define UPLL_CONTROL__UPLL_RST                             0x20000000L
#define UPLL_CONTROL__Reserved_MASK                        0x40000000L
#define UPLL_CONTROL__Reserved                             0x40000000L
#define UPLL_CONTROL__UPLL_POWERDOWN_TOGGLE_MASK           0x80000000L
#define UPLL_CONTROL__UPLL_POWERDOWN_TOGGLE                0x80000000L

// PLL_ANALOG_CONTROL
#define PLL_ANALOG_CONTROL__UPLL_PCP_MASK                  0x00070000L
#define PLL_ANALOG_CONTROL__UPLL_PVG_MASK                  0x00380000L
#define PLL_ANALOG_CONTROL__UPLL_PDC_MASK                  0x00c00000L
#define PLL_ANALOG_CONTROL__SSPLL_TRACK_MODE_MASK          0x03000000L
#define PLL_ANALOG_CONTROL__SSPLL_TRACK_SPEED_MASK         0x0c000000L
#define PLL_ANALOG_CONTROL__SSPLL_CONTIN_CALIB_MASK        0x10000000L
#define PLL_ANALOG_CONTROL__SSPLL_CONTIN_CALIB             0x10000000L

// MC_CLK_CNTRL
#define MC_CLK_CNTRL__MC_CLKSPEED_MASK                     0x00000003L
#define MC_CLK_CNTRL__MC_USE_CLKSPEED_MASK                 0x00000004L
#define MC_CLK_CNTRL__MC_USE_CLKSPEED                      0x00000004L
#define MC_CLK_CNTRL__GEARRATIO_MS_MASK                    0x00000018L
#define MC_CLK_CNTRL__GEARRATIO_BS_MASK                    0x00000060L
#define MC_CLK_CNTRL__FORCE_GEARRATIO_RECALC_MASK          0x00000080L
#define MC_CLK_CNTRL__FORCE_GEARRATIO_RECALC               0x00000080L

// THERMAL_SENSOR_GEN_CNTL
#define THERMAL_SENSOR_GEN_CNTL__THERM_SOFT_RESET_MASK     0x00000001L
#define THERMAL_SENSOR_GEN_CNTL__THERM_SOFT_RESET          0x00000001L
#define THERMAL_SENSOR_GEN_CNTL__THERM_CLKEN_MASK          0x00000002L
#define THERMAL_SENSOR_GEN_CNTL__THERM_CLKEN               0x00000002L
#define THERMAL_SENSOR_GEN_CNTL__THERM_INV_CLK2_MASK       0x00000004L
#define THERMAL_SENSOR_GEN_CNTL__THERM_INV_CLK2            0x00000004L
#define THERMAL_SENSOR_GEN_CNTL__THERM_SENSOR_PWDN_MASK    0x00000010L
#define THERMAL_SENSOR_GEN_CNTL__THERM_SENSOR_PWDN         0x00000010L
#define THERMAL_SENSOR_GEN_CNTL__THERM_SENSOR_ENABLE_MASK  0x00000020L
#define THERMAL_SENSOR_GEN_CNTL__THERM_SENSOR_ENABLE       0x00000020L
#define THERMAL_SENSOR_GEN_CNTL__THERM_SENSOR_DYN_DISABLE_MASK 0x00000040L
#define THERMAL_SENSOR_GEN_CNTL__THERM_SENSOR_DYN_DISABLE  0x00000040L
#define THERMAL_SENSOR_GEN_CNTL__THERM_CLKDIV_MASK         0x000fff00L
#define THERMAL_SENSOR_GEN_CNTL__THERM_CLKPHASE_MASK       0xfff00000L

// THERMAL_SENSOR_SAMP_CNTL
#define THERMAL_SENSOR_SAMP_CNTL__THERM_AVGSAMPLE_MASK     0x00000007L
#define THERMAL_SENSOR_SAMP_CNTL__THERM_IDLE_PERIOD_MASK   0x0000fff8L
#define THERMAL_SENSOR_SAMP_CNTL__THERM_MANUAL_TERPERATURE_MASK 0x003f0000L
#define THERMAL_SENSOR_SAMP_CNTL__THERM_MANUAL_VALID_MASK  0x00400000L
#define THERMAL_SENSOR_SAMP_CNTL__THERM_MANUAL_VALID       0x00400000L
#define THERMAL_SENSOR_SAMP_CNTL__THERM_MANUAL_TEMP_EN_MASK 0x00800000L
#define THERMAL_SENSOR_SAMP_CNTL__THERM_MANUAL_TEMP_EN     0x00800000L
#define THERMAL_SENSOR_SAMP_CNTL__THERM_MC_TEMP_THROTTLE_MASK 0x3f000000L
#define THERMAL_SENSOR_SAMP_CNTL__THERM_MCCNTL_EN_MASK     0x40000000L
#define THERMAL_SENSOR_SAMP_CNTL__THERM_MCCNTL_EN          0x40000000L

// THERMAL_SENSOR_DYN_CNTL
#define THERMAL_SENSOR_DYN_CNTL__THERM_FANCNTL_EN_MASK     0x00000003L
#define THERMAL_SENSOR_DYN_CNTL__THERM_SPEED_MIN_MASK      0x0000000cL
#define THERMAL_SENSOR_DYN_CNTL__THERM_FANCNTL_HYST_MASK   0x00000070L
#define THERMAL_SENSOR_DYN_CNTL__THERM_ENGCLKCNTL_EN_MASK  0x00000080L
#define THERMAL_SENSOR_DYN_CNTL__THERM_ENGCLKCNTL_EN       0x00000080L
#define THERMAL_SENSOR_DYN_CNTL__THERM_FAN_TEMP_LOW_MASK   0x00003f00L
#define THERMAL_SENSOR_DYN_CNTL__THERM_SPEED_LOW_MASK      0x0000c000L
#define THERMAL_SENSOR_DYN_CNTL__THERM_FAN_TEMP_MED_MASK   0x003f0000L
#define THERMAL_SENSOR_DYN_CNTL__THERM_SPEED_MED_MASK      0x00c00000L
#define THERMAL_SENSOR_DYN_CNTL__THERM_FAN_TEMP_HIGH_MASK  0x3f000000L
#define THERMAL_SENSOR_DYN_CNTL__THERM_SPEED_HIGH_MASK     0xc0000000L

// THERMAL_SENSOR_INT_CNTL
#define THERMAL_SENSOR_INT_CNTL__THERM_MC_TEMP_HYST_MASK   0x00000007L
#define THERMAL_SENSOR_INT_CNTL__TEMP_READBACK_MASK        0x000003f0L
#define THERMAL_SENSOR_INT_CNTL__THERM_TEMP_READ_TRIGGER_MASK 0x00000400L
#define THERMAL_SENSOR_INT_CNTL__THERM_TEMP_READ_TRIGGER   0x00000400L
#define THERMAL_SENSOR_INT_CNTL__THERM_INT_STATUS_AK_MASK  0x00000800L
#define THERMAL_SENSOR_INT_CNTL__THERM_INT_STATUS_AK       0x00000800L
#define THERMAL_SENSOR_INT_CNTL__THERM_INT_TEMP_THRES_MASK 0x0003f000L
#define THERMAL_SENSOR_INT_CNTL__THERM_INT_TEMP_PERIOD_MASK 0x7ffc0000L
#define THERMAL_SENSOR_INT_CNTL__THERM_INT_EN_MASK         0x80000000L
#define THERMAL_SENSOR_INT_CNTL__THERM_INT_EN              0x80000000L

// PLL_VOLTAGE_REG_CNTL
#define PLL_VOLTAGE_REG_CNTL__NB_RSBEN_MASK                0x00000001L
#define PLL_VOLTAGE_REG_CNTL__NB_RSBEN                     0x00000001L
#define PLL_VOLTAGE_REG_CNTL__NB_REG_OVERRIDE_MASK         0x00000002L
#define PLL_VOLTAGE_REG_CNTL__NB_REG_OVERRIDE              0x00000002L
#define PLL_VOLTAGE_REG_CNTL__NB_RBGADJ_MASK               0x000000f0L

// GPC_CONTROL
#define GPC_CONTROL__GPC_RESET_MASK                        0x00000001L
#define GPC_CONTROL__GPC_RESET                             0x00000001L
#define GPC_CONTROL__GPC_EQ_ZERO_MASK                      0x00000002L
#define GPC_CONTROL__GPC_EQ_ZERO                           0x00000002L
#define GPC_CONTROL__GPC_CLK_SEL_MASK                      0x000000f0L

// GC_CLK_CNTRL
#define GC_CLK_CNTRL__CG_AGPCLKSTATE_MASK                  0x00000001L
#define GC_CLK_CNTRL__CG_AGPCLKSTATE                       0x00000001L
#define GC_CLK_CNTRL__ONCHIP_GRAPHICS_STRAP_TOGGLE_MASK    0x00000002L
#define GC_CLK_CNTRL__ONCHIP_GRAPHICS_STRAP_TOGGLE         0x00000002L
#define GC_CLK_CNTRL__GC_STATE_MASK                        0x00000018L
#define GC_CLK_CNTRL__STOP_PCI_REQ_MASK                    0x00000020L
#define GC_CLK_CNTRL__STOP_PCI_REQ                         0x00000020L

// OCCG_EXTCLK_DISABLE
#define OCCG_EXTCLK_DISABLE__DISABLE_CPUCLK_MASK           0x00000001L
#define OCCG_EXTCLK_DISABLE__DISABLE_CPUCLK                0x00000001L
#define OCCG_EXTCLK_DISABLE__DISABLE_CPUCLKN_MASK          0x00000002L
#define OCCG_EXTCLK_DISABLE__DISABLE_CPUCLKN               0x00000002L
#define OCCG_EXTCLK_DISABLE__DISABLE_CPUCLKP_MASK          0x00000004L
#define OCCG_EXTCLK_DISABLE__DISABLE_CPUCLKP               0x00000004L
#define OCCG_EXTCLK_DISABLE__DISABLE_REF24M48M_MASK        0x00000008L
#define OCCG_EXTCLK_DISABLE__DISABLE_REF24M48M             0x00000008L
#define OCCG_EXTCLK_DISABLE__DISABLE_APICCLK1_MASK         0x00000010L
#define OCCG_EXTCLK_DISABLE__DISABLE_APICCLK1              0x00000010L
#define OCCG_EXTCLK_DISABLE__DISABLE_APICCLK2_MASK         0x00000020L
#define OCCG_EXTCLK_DISABLE__DISABLE_APICCLK2              0x00000020L
#define OCCG_EXTCLK_DISABLE__DISABLE_PLLSYSCLKH_MASK       0x00000040L
#define OCCG_EXTCLK_DISABLE__DISABLE_PLLSYSCLKH            0x00000040L
#define OCCG_EXTCLK_DISABLE__DISABLE_PLLMEMCLKH_MASK       0x00000080L
#define OCCG_EXTCLK_DISABLE__DISABLE_PLLMEMCLKH            0x00000080L
#define OCCG_EXTCLK_DISABLE__DISABLE_PLLAGPCLKH_MASK       0x00000100L
#define OCCG_EXTCLK_DISABLE__DISABLE_PLLAGPCLKH            0x00000100L
#define OCCG_EXTCLK_DISABLE__DISABLE_CPUCLKTUNE_MASK       0x00000200L
#define OCCG_EXTCLK_DISABLE__DISABLE_CPUCLKTUNE            0x00000200L

// MPLL_CONTROL2
#define MPLL_CONTROL2__MPLL_REF_DIV_MASK                   0x000003ffL
#define MPLL_CONTROL2__MPLL_ATOMIC_UPDATE_EN_MASK          0x00000400L
#define MPLL_CONTROL2__MPLL_ATOMIC_UPDATE_EN               0x00000400L
#define MPLL_CONTROL2__MPLL_ATOMIC_UPDATE_TRIGGER_MASK     0x00000800L
#define MPLL_CONTROL2__MPLL_ATOMIC_UPDATE_TRIGGER          0x00000800L
#define MPLL_CONTROL2__MPLL_FB_DIV_FRACTION_MASK           0x00007000L
#define MPLL_CONTROL2__MPLL_FBDIV_FRACTION_UPDATE_TRIGGER_MASK 0x00008000L
#define MPLL_CONTROL2__MPLL_FBDIV_FRACTION_UPDATE_TRIGGER  0x00008000L
#define MPLL_CONTROL2__MPLL_FB_DIV_MASK                    0x07ff0000L
#define MPLL_CONTROL2__MPLL_POST_DIV_MASK                  0x70000000L

// MPLL_CONTROL3
#define MPLL_CONTROL3__MPLL_TST_CNT_MASK                   0x00003fffL
#define MPLL_CONTROL3__MPLL_TST_CNT_SEL_MASK               0x00030000L
#define MPLL_CONTROL3__MPLL_TST_DIVIDERS_MASK              0x00040000L
#define MPLL_CONTROL3__MPLL_TST_DIVIDERS                   0x00040000L
#define MPLL_CONTROL3__MPLL_TST_MODE_MASK                  0x00080000L
#define MPLL_CONTROL3__MPLL_TST_MODE                       0x00080000L
#define MPLL_CONTROL3__MPLL_TST_GE_MASK                    0x00100000L
#define MPLL_CONTROL3__MPLL_TST_GE                         0x00100000L
#define MPLL_CONTROL3__MPLL_TST_LE_MASK                    0x00200000L
#define MPLL_CONTROL3__MPLL_TST_LE                         0x00200000L
#define MPLL_CONTROL3__MPLL_TST_DEC_MASK                   0x00400000L
#define MPLL_CONTROL3__MPLL_TST_DEC                        0x00400000L
#define MPLL_CONTROL3__MPLL_REFCLK_SEL_MASK                0x01000000L
#define MPLL_CONTROL3__MPLL_REFCLK_SEL                     0x01000000L
#define MPLL_CONTROL3__MPLL_FBCLK_SEL_MASK                 0x02000000L
#define MPLL_CONTROL3__MPLL_FBCLK_SEL                      0x02000000L
#define MPLL_CONTROL3__MPLL_REFIN_SEL_MASK                 0x04000000L
#define MPLL_CONTROL3__MPLL_REFIN_SEL                      0x04000000L
#define MPLL_CONTROL3__MPLL_PD_NOW_MASK                    0x10000000L
#define MPLL_CONTROL3__MPLL_PD_NOW                         0x10000000L
#define MPLL_CONTROL3__MPLL_RESET_MASK                     0x20000000L
#define MPLL_CONTROL3__MPLL_RESET                          0x20000000L
#define MPLL_CONTROL3__MCIOPLL_LOCKED_MASK                 0x40000000L
#define MPLL_CONTROL3__MCIOPLL_LOCKED                      0x40000000L
#define MPLL_CONTROL3__MCIOPLL_CAL_TRIGGER_MASK            0x80000000L
#define MPLL_CONTROL3__MCIOPLL_CAL_TRIGGER                 0x80000000L

// MC_DATA_DLL_CNTRL_A
#define MC_DATA_DLL_CNTRL_A__DLL_DA_IN_TRIM0_MASK          0x0000000fL
#define MC_DATA_DLL_CNTRL_A__DLL_DA_OUT_TRIM0_MASK         0x000000f0L
#define MC_DATA_DLL_CNTRL_A__DLL_DA_IN_TRIM1_MASK          0x00000f00L
#define MC_DATA_DLL_CNTRL_A__DLL_DA_OUT_TRIM1_MASK         0x0000f000L
#define MC_DATA_DLL_CNTRL_A__DLL_DA_IN_TRIM2_MASK          0x000f0000L
#define MC_DATA_DLL_CNTRL_A__DLL_DA_OUT_TRIM2_MASK         0x00f00000L
#define MC_DATA_DLL_CNTRL_A__DLL_DA_IN_TRIM3_MASK          0x0f000000L
#define MC_DATA_DLL_CNTRL_A__DLL_DA_OUT_TRIM3_MASK         0xf0000000L

// SCRATCH_CLKCFG
#define SCRATCH_CLKCFG__SCRATCH_MASK                       0x0003ffffL
#define SCRATCH_CLKCFG__CLKCAL_VAL_P_MASK                  0x007c0000L
#define SCRATCH_CLKCFG__CLKCAL_VAL_N_MASK                  0x0f800000L
#define SCRATCH_CLKCFG__CAL_VAL_V_MASK                     0xf0000000L

// MC_ACMD_DLL_CNTRL_A
#define MC_ACMD_DLL_CNTRL_A__DLL_CA_IN_TRIM_MASK           0x0000000fL
#define MC_ACMD_DLL_CNTRL_A__DLL_CA_OUT_TRIM_MASK          0x000000f0L

// MC_ACMD_DLL_CNTRL_B
#define MC_ACMD_DLL_CNTRL_B__DLL_CB_IN_TRIM_MASK           0x0000000fL
#define MC_ACMD_DLL_CNTRL_B__DLL_CB_OUT_TRIM_MASK          0x000000f0L

// CLKGATE_DISABLE2
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCB_MASK             0x00000001L
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCB                  0x00000001L
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCGR_MASK            0x00000002L
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCGR                 0x00000002L
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCSQA_MASK           0x00000004L
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCSQA                0x00000004L
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCSQB_MASK           0x00000008L
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCSQB                0x00000008L
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCIOA_MASK           0x00000010L
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCIOA                0x00000010L
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCIOB_MASK           0x00000020L
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCIOB                0x00000020L
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCAGP_MASK           0x00000040L
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCAGP                0x00000040L
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCAGP_PM1_MASK       0x00000080L
#define CLKGATE_DISABLE2__CLKGATE_DIS_MCAGP_PM1            0x00000080L
#define CLKGATE_DISABLE2__CLKGATE_DIS_BIU_NB1ACLK_MASK     0x00000100L
#define CLKGATE_DISABLE2__CLKGATE_DIS_BIU_NB1ACLK          0x00000100L
#define CLKGATE_DISABLE2__CLKGATE_DIS_BIU_NB1BCLK_MASK     0x00000200L
#define CLKGATE_DISABLE2__CLKGATE_DIS_BIU_NB1BCLK          0x00000200L
#define CLKGATE_DISABLE2__CLKDATE_DIS_BIU_MEMA_MASK        0x00000400L
#define CLKGATE_DISABLE2__CLKDATE_DIS_BIU_MEMA             0x00000400L
#define CLKGATE_DISABLE2__CLKDATE_DIS_BIU_MEMB_MASK        0x00000800L
#define CLKGATE_DISABLE2__CLKDATE_DIS_BIU_MEMB             0x00000800L
#define CLKGATE_DISABLE2__CLKGATE_DIS_BIU_PAD_MASK         0x00001000L
#define CLKGATE_DISABLE2__CLKGATE_DIS_BIU_PAD              0x00001000L
#define CLKGATE_DISABLE2__CLKGATE_DIS_PCI4X_MASK           0x00002000L
#define CLKGATE_DISABLE2__CLKGATE_DIS_PCI4X                0x00002000L
#define CLKGATE_DISABLE2__CLKGATE_DIS_PCIM_MASK            0x00004000L
#define CLKGATE_DISABLE2__CLKGATE_DIS_PCIM                 0x00004000L
#define CLKGATE_DISABLE2__CLKGATE_DIS_PCIT_MASK            0x00008000L
#define CLKGATE_DISABLE2__CLKGATE_DIS_PCIT                 0x00008000L
#define CLKGATE_DISABLE2__CLKGATE_DIS_PCICG_MASK           0x00010000L
#define CLKGATE_DISABLE2__CLKGATE_DIS_PCICG                0x00010000L
#define CLKGATE_DISABLE2__CLKGATE_DIS_AGP_B1X_PM1_MASK     0x00020000L
#define CLKGATE_DISABLE2__CLKGATE_DIS_AGP_B1X_PM1          0x00020000L
#define CLKGATE_DISABLE2__CLKGATE_DIS_BIU_IOPLL4X_MASK     0x00040000L
#define CLKGATE_DISABLE2__CLKGATE_DIS_BIU_IOPLL4X          0x00040000L
#define CLKGATE_DISABLE2__GFX_SCLK_DISABLE_MASK            0x00100000L
#define CLKGATE_DISABLE2__GFX_SCLK_DISABLE                 0x00100000L
#define CLKGATE_DISABLE2__GFX_DISPCLK_DISABLE_MASK         0x00200000L
#define CLKGATE_DISABLE2__GFX_DISPCLK_DISABLE              0x00200000L
#define CLKGATE_DISABLE2__PCI4XCLK_DISABLE_MASK            0x04000000L
#define CLKGATE_DISABLE2__PCI4XCLK_DISABLE                 0x04000000L
#define CLKGATE_DISABLE2__AGP8XCLK_DISABLE_MASK            0x08000000L
#define CLKGATE_DISABLE2__AGP8XCLK_DISABLE                 0x08000000L
#define CLKGATE_DISABLE2__AGPCLK_DISABLE_MASK              0x10000000L
#define CLKGATE_DISABLE2__AGPCLK_DISABLE                   0x10000000L
#define CLKGATE_DISABLE2__PCI_B4X_DISABLE_MASK             0x20000000L
#define CLKGATE_DISABLE2__PCI_B4X_DISABLE                  0x20000000L
#define CLKGATE_DISABLE2__MC_DELAY_TIMER_EXTEND_MASK       0x40000000L
#define CLKGATE_DISABLE2__MC_DELAY_TIMER_EXTEND            0x40000000L
#define CLKGATE_DISABLE2__AGP_DELAY_TIMER_EXTEND_MASK      0x80000000L
#define CLKGATE_DISABLE2__AGP_DELAY_TIMER_EXTEND           0x80000000L

// EXT_PCICLK_STOP_CNTRL
#define EXT_PCICLK_STOP_CNTRL__PCICLK0_STOP_MODE_MASK      0x00000007L
#define EXT_PCICLK_STOP_CNTRL__PCICLK1_STOP_MODE_MASK      0x00000038L
#define EXT_PCICLK_STOP_CNTRL__PCICLK2_STOP_MODE_A5_MASK   0x000000c0L
#define EXT_PCICLK_STOP_CNTRL__PCICLK3_STOP_MODE_A5_MASK   0x00000600L
#define EXT_PCICLK_STOP_CNTRL__PCICLK4_STOP_MODE_A5_MASK   0x00003000L

// CLKGATE_DISABLE
#define CLKGATE_DISABLE__CLKGATE_DIS_MCA_MASK              0x00000001L
#define CLKGATE_DISABLE__CLKGATE_DIS_MCA                   0x00000001L
#define CLKGATE_DISABLE__CPUCLK_STOP_MISC_MASK             0x00000002L
#define CLKGATE_DISABLE__CPUCLK_STOP_MISC                  0x00000002L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC1_MASK              0x00000004L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC1                   0x00000004L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC2_MASK              0x00000008L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC2                   0x00000008L
#define CLKGATE_DISABLE__DIS_CPUCLK_STOP_BIU_MASK          0x00000010L
#define CLKGATE_DISABLE__DIS_CPUCLK_STOP_BIU               0x00000010L
#define CLKGATE_DISABLE__DIS_CPUCLK_STOP_AGP_MASK          0x00000020L
#define CLKGATE_DISABLE__DIS_CPUCLK_STOP_AGP               0x00000020L
#define CLKGATE_DISABLE__DIS_CPUCLK_STOP_PCI_MASK          0x00000040L
#define CLKGATE_DISABLE__DIS_CPUCLK_STOP_PCI               0x00000040L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC6_MASK              0x00000080L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC6                   0x00000080L
#define CLKGATE_DISABLE__ENABLE_ANALOG_DLLs_MASK           0x00000100L
#define CLKGATE_DISABLE__ENABLE_ANALOG_DLLs                0x00000100L
#define CLKGATE_DISABLE__CLKGATE_DIS_RAMCLK_MASK           0x00000200L
#define CLKGATE_DISABLE__CLKGATE_DIS_RAMCLK                0x00000200L
#define CLKGATE_DISABLE__CLKGATE_DIS_BIU_MEM_MASK          0x00000400L
#define CLKGATE_DISABLE__CLKGATE_DIS_BIU_MEM               0x00000400L
#define CLKGATE_DISABLE__CLKGATE_DIS_BIU_NB1CLK_MASK       0x00000800L
#define CLKGATE_DISABLE__CLKGATE_DIS_BIU_NB1CLK            0x00000800L
#define CLKGATE_DISABLE__CLKGATE_DIS_BIU_NB2CLK_MASK       0x00001000L
#define CLKGATE_DISABLE__CLKGATE_DIS_BIU_NB2CLK            0x00001000L
#define CLKGATE_DISABLE__CLKGATE_DIS_AGP_B1X_MASK          0x00002000L
#define CLKGATE_DISABLE__CLKGATE_DIS_AGP_B1X               0x00002000L
#define CLKGATE_DISABLE__CLKGATE_DIS_AGP_B2X_MASK          0x00004000L
#define CLKGATE_DISABLE__CLKGATE_DIS_AGP_B2X               0x00004000L
#define CLKGATE_DISABLE__CLKGATE_DIS_AGP_B4X_MASK          0x00008000L
#define CLKGATE_DISABLE__CLKGATE_DIS_AGP_B4X               0x00008000L
#define CLKGATE_DISABLE__CLKGATE_DIS_AGP_S1X_MASK          0x00010000L
#define CLKGATE_DISABLE__CLKGATE_DIS_AGP_S1X               0x00010000L
#define CLKGATE_DISABLE__CLKGATE_DIS_AGP_B1XSBA_MASK       0x00020000L
#define CLKGATE_DISABLE__CLKGATE_DIS_AGP_B1XSBA            0x00020000L
#define CLKGATE_DISABLE__CLKGATE_DIS_AGP_B2XSBA_MASK       0x00040000L
#define CLKGATE_DISABLE__CLKGATE_DIS_AGP_B2XSBA            0x00040000L
#define CLKGATE_DISABLE__CLKGATE_DIS_AGP_B2XAIO_MASK       0x00080000L
#define CLKGATE_DISABLE__CLKGATE_DIS_AGP_B2XAIO            0x00080000L
#define CLKGATE_DISABLE__CLKGATE_DIS_PCI_B1X_MASK          0x00100000L
#define CLKGATE_DISABLE__CLKGATE_DIS_PCI_B1X               0x00100000L
#define CLKGATE_DISABLE__CLKGATE_DIS_PCI_B2X_MASK          0x00200000L
#define CLKGATE_DISABLE__CLKGATE_DIS_PCI_B2X               0x00200000L
#define CLKGATE_DISABLE__CLKGATE_DIS_PCI_S1X_MASK          0x00400000L
#define CLKGATE_DISABLE__CLKGATE_DIS_PCI_S1X               0x00400000L
#define CLKGATE_DISABLE__PCIM_S1X_DISABLEb_MASK            0x00800000L
#define CLKGATE_DISABLE__PCIM_S1X_DISABLEb                 0x00800000L
#define CLKGATE_DISABLE__CLKGATE_DIS_CG_AGP1X_MASK         0x01000000L
#define CLKGATE_DISABLE__CLKGATE_DIS_CG_AGP1X              0x01000000L
#define CLKGATE_DISABLE__CLKGATE_DIS_CG_AGPnX_MASK         0x02000000L
#define CLKGATE_DISABLE__CLKGATE_DIS_CG_AGPnX              0x02000000L
#define CLKGATE_DISABLE__CLKGATE_DIS_IG2R6_B1X_MASK        0x04000000L
#define CLKGATE_DISABLE__CLKGATE_DIS_IG2R6_B1X             0x04000000L
#define CLKGATE_DISABLE__CLKGATE_DIS_IG2R6_S1X_MASK        0x08000000L
#define CLKGATE_DISABLE__CLKGATE_DIS_IG2R6_S1X             0x08000000L
#define CLKGATE_DISABLE__CLKGATE_DIS_CFG_S1X_MASK          0x10000000L
#define CLKGATE_DISABLE__CLKGATE_DIS_CFG_S1X               0x10000000L
#define CLKGATE_DISABLE__CLKGATE_DIS_CFG_B1X_MASK          0x20000000L
#define CLKGATE_DISABLE__CLKGATE_DIS_CFG_B1X               0x20000000L
#define CLKGATE_DISABLE__DEEP_S1_DISABLE_MASK              0x40000000L
#define CLKGATE_DISABLE__DEEP_S1_DISABLE                   0x40000000L

// SSPLL_CONFIG0
#define SSPLL_CONFIG0__SSPLL_SPREAD_ON_TOGGLE_MASK         0x00000001L
#define SSPLL_CONFIG0__SSPLL_SPREAD_ON_TOGGLE              0x00000001L
#define SSPLL_CONFIG0__SSPLL_RST_MASK                      0x00000002L
#define SSPLL_CONFIG0__SSPLL_RST                           0x00000002L
#define SSPLL_CONFIG0__SSPLL_POWERDOWN_MASK                0x00000004L
#define SSPLL_CONFIG0__SSPLL_POWERDOWN                     0x00000004L
#define SSPLL_CONFIG0__SSPLL_B_MASK                        0x000001f8L
#define SSPLL_CONFIG0__SSPLL_V_MASK                        0x00007e00L
#define SSPLL_CONFIG0__SSPLL_S_MASK                        0x007f8000L
#define SSPLL_CONFIG0__SSPLL_POWERDOWN_DLY_MASK            0x01800000L
#define SSPLL_CONFIG0__SSPLL_REFDIV_MASK                   0xfe000000L

// SSPLL_CONFIG1
#define SSPLL_CONFIG1__SSPLL_REFCLK_SEL_MASK               0x00000001L
#define SSPLL_CONFIG1__SSPLL_REFCLK_SEL                    0x00000001L
#define SSPLL_CONFIG1__SSPLL_FBCLK_SEL_MASK                0x00000002L
#define SSPLL_CONFIG1__SSPLL_FBCLK_SEL                     0x00000002L
#define SSPLL_CONFIG1__SSPLL_TCPOFF_MASK                   0x00000004L
#define SSPLL_CONFIG1__SSPLL_TCPOFF                        0x00000004L
#define SSPLL_CONFIG1__SSPLL_TVCOMAX_MASK                  0x00000008L
#define SSPLL_CONFIG1__SSPLL_TVCOMAX                       0x00000008L
#define SSPLL_CONFIG1__SSPLL_TMONEN_MASK                   0x00000010L
#define SSPLL_CONFIG1__SSPLL_TMONEN                        0x00000010L
#define SSPLL_CONFIG1__SSPLL_PCP_MASK                      0x000000e0L
#define SSPLL_CONFIG1__SSPLL_PVG_MASK                      0x00000700L
#define SSPLL_CONFIG1__SSPLL_PDC_MASK                      0x00001800L
#define SSPLL_CONFIG1__SSPLL_STEP_SIZE_MASK                0x0000c000L
#define SSPLL_CONFIG1__SSPLL_DELAY_MASK                    0x00070000L
#define SSPLL_CONFIG1__SSPLL_DELTA_FRACTION_MASK           0x00700000L
#define SSPLL_CONFIG1__SSPLL_DELTA_INTEGER_MASK            0x3f000000L
#define SSPLL_CONFIG1__SSPLL_OVERCLOCK_EN_MASK             0x40000000L
#define SSPLL_CONFIG1__SSPLL_OVERCLOCK_EN                  0x40000000L
#define SSPLL_CONFIG1__SSPLL_SPARE_MASK                    0x80000000L
#define SSPLL_CONFIG1__SSPLL_SPARE                         0x80000000L

// SSPLL_CONFIG2
#define SSPLL_CONFIG2__SSPLL_TST_CNT_MASK                  0x00003fffL
#define SSPLL_CONFIG2__SSPLL_OVERCLOCK_FB_DIV_U_MASK       0x0000c000L
#define SSPLL_CONFIG2__SSPLL_TST_CNT_SEL_MASK              0x00030000L
#define SSPLL_CONFIG2__SSPLL_TST_DIVIDERS_MASK             0x00040000L
#define SSPLL_CONFIG2__SSPLL_TST_DIVIDERS                  0x00040000L
#define SSPLL_CONFIG2__SSPLL_TST_MODE_MASK                 0x00080000L
#define SSPLL_CONFIG2__SSPLL_TST_MODE                      0x00080000L
#define SSPLL_CONFIG2__SSPLL_TST_GE_MASK                   0x00100000L
#define SSPLL_CONFIG2__SSPLL_TST_GE                        0x00100000L
#define SSPLL_CONFIG2__SSPLL_TST_LE_MASK                   0x00200000L
#define SSPLL_CONFIG2__SSPLL_TST_LE                        0x00200000L
#define SSPLL_CONFIG2__SSPLL_TST_DEC_MASK                  0x00400000L
#define SSPLL_CONFIG2__SSPLL_TST_DEC                       0x00400000L
#define SSPLL_CONFIG2__SSPLL_OVERCLOCK_FB_DIV_L_MASK       0xff800000L

// CLK_TOP_PERF_COUNT0
#define CLK_TOP_PERF_COUNT0__CLK_TOP_COUNT_0_MASK          0xffffffffL

// CLK_TOP_PERF_COUNT1
#define CLK_TOP_PERF_COUNT1__CLK_TOP_COUNT_1_MASK          0xffffffffL

// CLK_TOP_PERF_CNTL
#define CLK_TOP_PERF_CNTL__CLK_TOP_EVENT_SEL_0_MASK        0x000000ffL
#define CLK_TOP_PERF_CNTL__CLK_TOP_EVENT_SEL_1_MASK        0x0000ff00L
#define CLK_TOP_PERF_CNTL__CLK_TOP_UPPER_COUNT_0_MASK      0x00ff0000L
#define CLK_TOP_PERF_CNTL__CLK_TOP_UPPER_COUNT_1_MASK      0xff000000L

// MPLL_FREQ_CONTROL
#define MPLL_FREQ_CONTROL__MPLL_PM_EN_MASK                 0x00000001L
#define MPLL_FREQ_CONTROL__MPLL_PM_EN                      0x00000001L
#define MPLL_FREQ_CONTROL__MPLL_FREQ_SEL_MASK              0x00000002L
#define MPLL_FREQ_CONTROL__MPLL_FREQ_SEL                   0x00000002L
#define MPLL_FREQ_CONTROL__DISP_BLANK_CNTL_MASK            0x0000000cL
#define MPLL_FREQ_CONTROL__DISP_BLANK_VAL_MASK             0x00000010L
#define MPLL_FREQ_CONTROL__DISP_BLANK_VAL                  0x00000010L
#define MPLL_FREQ_CONTROL__MEM_SELF_REFRESH_ONLY_MASK      0x00000020L
#define MPLL_FREQ_CONTROL__MEM_SELF_REFRESH_ONLY           0x00000020L
#define MPLL_FREQ_CONTROL__PM_SWITCHMCLK_BUSY_MASK         0x00000040L
#define MPLL_FREQ_CONTROL__PM_SWITCHMCLK_BUSY              0x00000040L
#define MPLL_FREQ_CONTROL__PM_FREQ_CNTL_RESET_MASK         0x00000080L
#define MPLL_FREQ_CONTROL__PM_FREQ_CNTL_RESET              0x00000080L
#define MPLL_FREQ_CONTROL__PM_MPLL_DELTA_FRACTION_MASK     0x00000700L
#define MPLL_FREQ_CONTROL__PM_MPLL_DELTA_INTEGER_MASK      0x0001f800L
#define MPLL_FREQ_CONTROL__PM_MPLL_PVG_MASK                0x000e0000L
#define MPLL_FREQ_CONTROL__PM_MPLL_STEP_SIZE_MASK          0x00300000L
#define MPLL_FREQ_CONTROL__PM_MPLL_DELAY_MASK              0x01c00000L
#define MPLL_FREQ_CONTROL__MPLL_SLOWMCLK_MASK              0x10000000L
#define MPLL_FREQ_CONTROL__MPLL_SLOWMCLK                   0x10000000L
#define MPLL_FREQ_CONTROL__PM_MPLL_SLOWMCLK_MASK           0x20000000L
#define MPLL_FREQ_CONTROL__PM_MPLL_SLOWMCLK                0x20000000L

// MPLL_SEQ_CONTROL
#define MPLL_SEQ_CONTROL__MPLL_RESET_PULSE_WIDTH_MASK      0x0000001fL
#define MPLL_SEQ_CONTROL__MDLL_RESET_PULSE_WIDTH_MASK      0x000000e0L
#define MPLL_SEQ_CONTROL__MPLL_LOCK_TIME_MASK              0x000fff00L
#define MPLL_SEQ_CONTROL__MDLL_LOCK_TIME_MASK              0x07f00000L

// MPLL_DIV_CONTROL
#define MPLL_DIV_CONTROL__PM_MPLL_REF_DIV_MASK             0x000003ffL
#define MPLL_DIV_CONTROL__PM_MPLL_FB_DIV_FRACTION_MASK     0x00007000L
#define MPLL_DIV_CONTROL__PM_MPLL_FB_DIV_MASK              0x07ff0000L
#define MPLL_DIV_CONTROL__PM_MPLL_POST_DIV_MASK            0x70000000L

// NBCLK_IO_CONTROL
#define NBCLK_IO_CONTROL__SYSCLK_SP_MASK                   0x00000003L
#define NBCLK_IO_CONTROL__SYSCLK_SPB_MASK                  0x0000000cL
#define NBCLK_IO_CONTROL__SYSCLK_SRP_MASK                  0x00000030L
#define NBCLK_IO_CONTROL__SYSCLK_SRPB_MASK                 0x000000c0L
#define NBCLK_IO_CONTROL__SYS_FBCLKOUT_SP_MASK             0x00000300L
#define NBCLK_IO_CONTROL__SYS_FBCLKOUT_SPB_MASK            0x00000c00L
#define NBCLK_IO_CONTROL__SYS_FBCLKOUT_SRP_MASK            0x00003000L
#define NBCLK_IO_CONTROL__SYS_FBCLKOUT_SRPB_MASK           0x0000c000L
#define NBCLK_IO_CONTROL__IOSPLL_IPWDN_MASK                0x00010000L
#define NBCLK_IO_CONTROL__IOSPLL_IPWDN                     0x00010000L
#define NBCLK_IO_CONTROL__IOSPLL_IBYPASS_MASK              0x00020000L
#define NBCLK_IO_CONTROL__IOSPLL_IBYPASS                   0x00020000L
#define NBCLK_IO_CONTROL__IOSPLL_IREF_DELAY_MASK           0x00040000L
#define NBCLK_IO_CONTROL__IOSPLL_IREF_DELAY                0x00040000L
#define NBCLK_IO_CONTROL__IOSPLL_IVCO_DELAY_MASK           0x00080000L
#define NBCLK_IO_CONTROL__IOSPLL_IVCO_DELAY                0x00080000L
#define NBCLK_IO_CONTROL__IOSPLL_IICP_MASK                 0x00300000L
#define NBCLK_IO_CONTROL__IOSPLL_ICPBW_MASK                0x00400000L
#define NBCLK_IO_CONTROL__IOSPLL_ICPBW                     0x00400000L
#define NBCLK_IO_CONTROL__IOSPLL_IVCOBW_MASK               0x00800000L
#define NBCLK_IO_CONTROL__IOSPLL_IVCOBW                    0x00800000L
#define NBCLK_IO_CONTROL__IOSPLL_ISKEW_4X_MASK             0x01000000L
#define NBCLK_IO_CONTROL__IOSPLL_ISKEW_4X                  0x01000000L
#define NBCLK_IO_CONTROL__IOSPLL_IPLL_CNTL_MASK            0xf0000000L

// NBCLK_IO_CONTROL1
#define NBCLK_IO_CONTROL1__AGPCLKIN_PU_MASK                0x00000001L
#define NBCLK_IO_CONTROL1__AGPCLKIN_PU                     0x00000001L
#define NBCLK_IO_CONTROL1__AGPCLKIN_PD_MASK                0x00000002L
#define NBCLK_IO_CONTROL1__AGPCLKIN_PD                     0x00000002L
#define NBCLK_IO_CONTROL1__EXT_MEMCLK_PU_MASK              0x00000100L
#define NBCLK_IO_CONTROL1__EXT_MEMCLK_PU                   0x00000100L
#define NBCLK_IO_CONTROL1__EXT_MEMCLK_PD_MASK              0x00000200L
#define NBCLK_IO_CONTROL1__EXT_MEMCLK_PD                   0x00000200L
#define NBCLK_IO_CONTROL1__EXT_MEMCLK_SRP_MASK             0x00000400L
#define NBCLK_IO_CONTROL1__EXT_MEMCLK_SRP                  0x00000400L
#define NBCLK_IO_CONTROL1__EXT_MEMCLK_SRN_MASK             0x00000800L
#define NBCLK_IO_CONTROL1__EXT_MEMCLK_SRN                  0x00000800L
#define NBCLK_IO_CONTROL1__EXT_MEMCLK_SP_MASK              0x0000f000L
#define NBCLK_IO_CONTROL1__EXT_MEMCLK_SN_MASK              0x000f0000L
#define NBCLK_IO_CONTROL1__USBCLK_PU_MASK                  0x00100000L
#define NBCLK_IO_CONTROL1__USBCLK_PU                       0x00100000L
#define NBCLK_IO_CONTROL1__USBCLK_PD_MASK                  0x00200000L
#define NBCLK_IO_CONTROL1__USBCLK_PD                       0x00200000L
#define NBCLK_IO_CONTROL1__USBCLK_SRP_MASK                 0x00400000L
#define NBCLK_IO_CONTROL1__USBCLK_SRP                      0x00400000L
#define NBCLK_IO_CONTROL1__USBCLK_SRN_MASK                 0x00800000L
#define NBCLK_IO_CONTROL1__USBCLK_SRN                      0x00800000L
#define NBCLK_IO_CONTROL1__USBCLK_SP_MASK                  0x0f000000L
#define NBCLK_IO_CONTROL1__USBCLK_SN_MASK                  0xf0000000L

// NBCLK_IO_CONTROL2
#define NBCLK_IO_CONTROL2__AGPCLKOUT_PU_MASK               0x00000001L
#define NBCLK_IO_CONTROL2__AGPCLKOUT_PU                    0x00000001L
#define NBCLK_IO_CONTROL2__AGPCLKOUT_PD_MASK               0x00000002L
#define NBCLK_IO_CONTROL2__AGPCLKOUT_PD                    0x00000002L
#define NBCLK_IO_CONTROL2__AGPCLKOUT_SRP_MASK              0x00000004L
#define NBCLK_IO_CONTROL2__AGPCLKOUT_SRP                   0x00000004L
#define NBCLK_IO_CONTROL2__AGPCLKOUT_SRN_MASK              0x00000008L
#define NBCLK_IO_CONTROL2__AGPCLKOUT_SRN                   0x00000008L
#define NBCLK_IO_CONTROL2__AGPCLKOUT_SP_MASK               0x000000f0L
#define NBCLK_IO_CONTROL2__AGPCLKOUT_SN_MASK               0x00000f00L
#define NBCLK_IO_CONTROL2__ALINK_CLK_PU_MASK               0x00010000L
#define NBCLK_IO_CONTROL2__ALINK_CLK_PU                    0x00010000L
#define NBCLK_IO_CONTROL2__ALINK_CLK_PD_MASK               0x00020000L
#define NBCLK_IO_CONTROL2__ALINK_CLK_PD                    0x00020000L
#define NBCLK_IO_CONTROL2__ALINK_CLK_SRP_MASK              0x00040000L
#define NBCLK_IO_CONTROL2__ALINK_CLK_SRP                   0x00040000L
#define NBCLK_IO_CONTROL2__ALINK_CLK_SRN_MASK              0x00080000L
#define NBCLK_IO_CONTROL2__ALINK_CLK_SRN                   0x00080000L
#define NBCLK_IO_CONTROL2__ALINK_CLK_SP_MASK               0x00f00000L
#define NBCLK_IO_CONTROL2__ALINK_CLK_SN_MASK               0x0f000000L

// CLK_TOP_SPARE_A
#define CLK_TOP_SPARE_A__MCLK_SWITCH_GFX_EN_MASK           0x00000001L
#define CLK_TOP_SPARE_A__MCLK_SWITCH_GFX_EN                0x00000001L
#define CLK_TOP_SPARE_A__BIU_MEMAB_CPUSTOP_DIS_MASK        0x00000002L
#define CLK_TOP_SPARE_A__BIU_MEMAB_CPUSTOP_DIS             0x00000002L
#define CLK_TOP_SPARE_A__BIU_NB1_CPUSTOP_DIS_MASK          0x00000004L
#define CLK_TOP_SPARE_A__BIU_NB1_CPUSTOP_DIS               0x00000004L
#define CLK_TOP_SPARE_A__BIU_NB2_CPUSTOP_DIS_MASK          0x00000008L
#define CLK_TOP_SPARE_A__BIU_NB2_CPUSTOP_DIS               0x00000008L
#define CLK_TOP_SPARE_A__BIU_NB1AB_CPUSTOP_DIS_MASK        0x00000010L
#define CLK_TOP_SPARE_A__BIU_NB1AB_CPUSTOP_DIS             0x00000010L
#define CLK_TOP_SPARE_A__AGP_B1X_PM1_CPUSTOP_DIS_MASK      0x00000020L
#define CLK_TOP_SPARE_A__AGP_B1X_PM1_CPUSTOP_DIS           0x00000020L
#define CLK_TOP_SPARE_A__PCIM_CPUSTOP_DIS_MASK             0x00000040L
#define CLK_TOP_SPARE_A__PCIM_CPUSTOP_DIS                  0x00000040L
#define CLK_TOP_SPARE_A__PCIT_CPUSTOP_DIS_MASK             0x00000080L
#define CLK_TOP_SPARE_A__PCIT_CPUSTOP_DIS                  0x00000080L
#define CLK_TOP_SPARE_A__CFG_B1X_CPUSTOP_DIS_MASK          0x00000100L
#define CLK_TOP_SPARE_A__CFG_B1X_CPUSTOP_DIS               0x00000100L
#define CLK_TOP_SPARE_A__CFG_S1X_CPUSTOP_DIS_MASK          0x00000200L
#define CLK_TOP_SPARE_A__CFG_S1X_CPUSTOP_DIS               0x00000200L
#define CLK_TOP_SPARE_A__PCIM_S1X_CPUSTOP_DIS_MASK         0x00000400L
#define CLK_TOP_SPARE_A__PCIM_S1X_CPUSTOP_DIS              0x00000400L
#define CLK_TOP_SPARE_A__OSC_PU_MASK                       0x00010000L
#define CLK_TOP_SPARE_A__OSC_PU                            0x00010000L
#define CLK_TOP_SPARE_A__OSC_PD_MASK                       0x00020000L
#define CLK_TOP_SPARE_A__OSC_PD                            0x00020000L
#define CLK_TOP_SPARE_A__OSC_SRP_MASK                      0x00040000L
#define CLK_TOP_SPARE_A__OSC_SRP                           0x00040000L
#define CLK_TOP_SPARE_A__OSC_SRN_MASK                      0x00080000L
#define CLK_TOP_SPARE_A__OSC_SRN                           0x00080000L
#define CLK_TOP_SPARE_A__OSC_SP_MASK                       0x00f00000L
#define CLK_TOP_SPARE_A__OSC_SN_MASK                       0x0f000000L
#define CLK_TOP_SPARE_A__IOSPLL_ISKEW_1X_MASK              0x10000000L
#define CLK_TOP_SPARE_A__IOSPLL_ISKEW_1X                   0x10000000L
#define CLK_TOP_SPARE_A__IOSPLL_CAL_TRIGGER_MASK           0x80000000L
#define CLK_TOP_SPARE_A__IOSPLL_CAL_TRIGGER                0x80000000L

// CLK_TOP_SPARE_B
#define CLK_TOP_SPARE_B__CLK_TOP_SPAREB_MASK               0xffffffffL

// CLK_TOP_SPARE_C
#define CLK_TOP_SPARE_C__CLK_TOP_SPAREC_MASK               0xffffffffL

// CLK_TOP_SPARE_D
#define CLK_TOP_SPARE_D__CLK_TOP_SPARED_MASK               0xffffffffL

// APC_VENDOR_ID
#define APC_VENDOR_ID__VENDOR_ID_MASK                      0x0000ffffL

// APC_DEVICE_ID
#define APC_DEVICE_ID__DEVICE_ID_MASK                      0x0000ffffL

// APC_COMMAND
#define APC_COMMAND__IO_ACCESS_EN_MASK                     0x00000001L
#define APC_COMMAND__IO_ACCESS_EN                          0x00000001L
#define APC_COMMAND__MEM_ACCESS_EN_MASK                    0x00000002L
#define APC_COMMAND__MEM_ACCESS_EN                         0x00000002L
#define APC_COMMAND__BUS_MASTER_EN_MASK                    0x00000004L
#define APC_COMMAND__BUS_MASTER_EN                         0x00000004L
#define APC_COMMAND__SPECIAL_CYCLE_EN_MASK                 0x00000008L
#define APC_COMMAND__SPECIAL_CYCLE_EN                      0x00000008L
#define APC_COMMAND__MEM_WRITE_INVALIDATE_EN_MASK          0x00000010L
#define APC_COMMAND__MEM_WRITE_INVALIDATE_EN               0x00000010L
#define APC_COMMAND__PAL_SNOOP_EN_MASK                     0x00000020L
#define APC_COMMAND__PAL_SNOOP_EN                          0x00000020L
#define APC_COMMAND__PARITY_ERROR_EN_MASK                  0x00000040L
#define APC_COMMAND__PARITY_ERROR_EN                       0x00000040L
#define APC_COMMAND__Reserved0_MASK                        0x00000080L
#define APC_COMMAND__Reserved0                             0x00000080L
#define APC_COMMAND__SERR_EN_MASK                          0x00000100L
#define APC_COMMAND__SERR_EN                               0x00000100L
#define APC_COMMAND__FAST_B2B_EN_MASK                      0x00000200L
#define APC_COMMAND__FAST_B2B_EN                           0x00000200L
#define APC_COMMAND__Reserved_MASK                         0x0000fc00L

// APC_STATUS
#define APC_STATUS__CAP_LIST_MASK                          0x00000010L
#define APC_STATUS__CAP_LIST                               0x00000010L
#define APC_STATUS__PCI_66_EN_MASK                         0x00000020L
#define APC_STATUS__PCI_66_EN                              0x00000020L
#define APC_STATUS__UDF_EN_MASK                            0x00000040L
#define APC_STATUS__UDF_EN                                 0x00000040L
#define APC_STATUS__FAST_BACK_CAPABLE_MASK                 0x00000080L
#define APC_STATUS__FAST_BACK_CAPABLE                      0x00000080L
#define APC_STATUS__DEVSEL_TIMING_MASK                     0x00000600L
#define APC_STATUS__SIGNAL_TARGET_ABORT_MASK               0x00000800L
#define APC_STATUS__SIGNAL_TARGET_ABORT                    0x00000800L
#define APC_STATUS__RECEIVED_TARGET_ABORT_MASK             0x00001000L
#define APC_STATUS__RECEIVED_TARGET_ABORT                  0x00001000L
#define APC_STATUS__RECEIVED_MASTER_ABORT_MASK             0x00002000L
#define APC_STATUS__RECEIVED_MASTER_ABORT                  0x00002000L
#define APC_STATUS__SIGNALED_SYSTEM_ERROR_MASK             0x00004000L
#define APC_STATUS__SIGNALED_SYSTEM_ERROR                  0x00004000L
#define APC_STATUS__PARITY_ERROR_DETECTED_MASK             0x00008000L
#define APC_STATUS__PARITY_ERROR_DETECTED                  0x00008000L

// APC_REVISION_ID
#define APC_REVISION_ID__MINOR_REV_ID_MASK                 0x0000000fL
#define APC_REVISION_ID__MAJOR_REV_ID_MASK                 0x000000f0L

// APC_REGPROG_INF
#define APC_REGPROG_INF__REG_LEVEL_PROG_INF_MASK           0x000000ffL

// APC_SUB_CLASS
#define APC_SUB_CLASS__SUB_CLASS_INF_MASK                  0x000000ffL

// APC_BASE_CODE
#define APC_BASE_CODE__BASE_CLASS_CODE_MASK                0x000000ffL

// APC_CACHE_LINE
#define APC_CACHE_LINE__CACHE_LINE_SIZE_MASK               0x000000ffL

// APC_LATENCY
#define APC_LATENCY__LATENCY_TIMER_MASK                    0x000000ffL

// APC_HEADER
#define APC_HEADER__HEADER_TYPE_MASK                       0x000000ffL

// APC_BIST
#define APC_BIST__BIST_COMP_MASK                           0x0000000fL
#define APC_BIST__BIST_STRT_MASK                           0x00000040L
#define APC_BIST__BIST_STRT                                0x00000040L
#define APC_BIST__BIST_CAP_MASK                            0x00000080L
#define APC_BIST__BIST_CAP                                 0x00000080L

// APC_SUB_BUS_NUMBER_LATENCY
#define APC_SUB_BUS_NUMBER_LATENCY__PRIMARY_BUS_MASK       0x000000ffL
#define APC_SUB_BUS_NUMBER_LATENCY__SECONDARY_BUS_MASK     0x0000ff00L
#define APC_SUB_BUS_NUMBER_LATENCY__SUB_BUS_NUMBER_MASK    0x00ff0000L
#define APC_SUB_BUS_NUMBER_LATENCY__SECONDARY_LATENCY_TIMER_MASK 0xff000000L

// APC_AGP_PCI_IOBASE_LIMIT
#define APC_AGP_PCI_IOBASE_LIMIT__IO_BASE_R_MASK           0x0000000fL
#define APC_AGP_PCI_IOBASE_LIMIT__IO_BASE_MASK             0x000000f0L
#define APC_AGP_PCI_IOBASE_LIMIT__IO_LIMIT_R_MASK          0x00000f00L
#define APC_AGP_PCI_IOBASE_LIMIT__IO_LIMIT_MASK            0x0000f000L

// APC_AGP_PCI_STATUS
#define APC_AGP_PCI_STATUS__CAP_LIST_MASK                  0x00000010L
#define APC_AGP_PCI_STATUS__CAP_LIST                       0x00000010L
#define APC_AGP_PCI_STATUS___66M_MASK                      0x00000020L
#define APC_AGP_PCI_STATUS___66M                           0x00000020L
#define APC_AGP_PCI_STATUS__UDF_EN_MASK                    0x00000040L
#define APC_AGP_PCI_STATUS__UDF_EN                         0x00000040L
#define APC_AGP_PCI_STATUS__FAST_B2B_CAPABLE_MASK          0x00000080L
#define APC_AGP_PCI_STATUS__FAST_B2B_CAPABLE               0x00000080L
#define APC_AGP_PCI_STATUS__DATA_PERR_MASK                 0x00000100L
#define APC_AGP_PCI_STATUS__DATA_PERR                      0x00000100L
#define APC_AGP_PCI_STATUS__DEVSEL_TIMING_MASK             0x00000600L
#define APC_AGP_PCI_STATUS__SIGNAL_TARGET_ABORT_MASK       0x00000800L
#define APC_AGP_PCI_STATUS__SIGNAL_TARGET_ABORT            0x00000800L
#define APC_AGP_PCI_STATUS__TARGET_ABORT_MASK              0x00001000L
#define APC_AGP_PCI_STATUS__TARGET_ABORT                   0x00001000L
#define APC_AGP_PCI_STATUS__MASTER_ABORT_MASK              0x00002000L
#define APC_AGP_PCI_STATUS__MASTER_ABORT                   0x00002000L
#define APC_AGP_PCI_STATUS__SYSTEM_ERROR_MASK              0x00004000L
#define APC_AGP_PCI_STATUS__SYSTEM_ERROR                   0x00004000L
#define APC_AGP_PCI_STATUS__PARITY_ERROR_MASK              0x00008000L
#define APC_AGP_PCI_STATUS__PARITY_ERROR                   0x00008000L

// APC_AGP_PCI_MEMORY_LIMIT_BASE
#define APC_AGP_PCI_MEMORY_LIMIT_BASE__MEM_BASE_31_20_MASK 0x0000fff0L
#define APC_AGP_PCI_MEMORY_LIMIT_BASE__MEM_LIMIT_31_20_MASK 0xfff00000L

// APC_AGP_PCI_PREFETCHABLE_LIMIT_BASE
#define APC_AGP_PCI_PREFETCHABLE_LIMIT_BASE__PREF_MEM_BASE_31_16_MASK 0x0000ffffL
#define APC_AGP_PCI_PREFETCHABLE_LIMIT_BASE__PREF_MEMLIMIT_31_16_MASK 0xffff0000L

// APC_ADAPTER_ID
#define APC_ADAPTER_ID__SUBSYSTEM_VENDOR_ID_MASK           0x0000ffffL
#define APC_ADAPTER_ID__SUBSYSTEM_ID_MASK                  0xffff0000L

// APC_AGP_PCI_IO_LIMIT_BASE_HI
#define APC_AGP_PCI_IO_LIMIT_BASE_HI__IO_BASE_31_16_MASK   0x0000ffffL
#define APC_AGP_PCI_IO_LIMIT_BASE_HI__IO_LIMIT_31_16_MASK  0xffff0000L

// APC_AGP_PCI_IRQ_BRIDGE_CTRL
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__INT_LINE_MASK         0x000000ffL
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__INT_PIN_MASK          0x0000ff00L
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__PARITY_RESPONSE_EN_MASK 0x00010000L
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__PARITY_RESPONSE_EN    0x00010000L
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__SERR_EN_MASK          0x00020000L
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__SERR_EN               0x00020000L
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__ISA_EN_MASK           0x00040000L
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__ISA_EN                0x00040000L
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__VGA_EN_MASK           0x00080000L
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__VGA_EN                0x00080000L
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__MASTER_ABORT_MODE_MASK 0x00200000L
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__MASTER_ABORT_MODE     0x00200000L
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__SECONDARY_BUS_RESET_MASK 0x00400000L
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__SECONDARY_BUS_RESET   0x00400000L
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__FAST_B2B_CAPABLE_MASK 0x00800000L
#define APC_AGP_PCI_IRQ_BRIDGE_CTRL__FAST_B2B_CAPABLE      0x00800000L

// APC_MISC_DEVICE_CTRL
#define APC_MISC_DEVICE_CTRL__INT_PIN_CTRL_MASK            0x00000001L
#define APC_MISC_DEVICE_CTRL__INT_PIN_CTRL                 0x00000001L

// APC_ADAPTER_ID_W
#define APC_ADAPTER_ID_W__SUBSYSTEM_VENDOR_ID_MASK         0x0000ffffL
#define APC_ADAPTER_ID_W__SUBSYSTEM_ID_MASK                0xffff0000L

// NB_AGPS_CTRL
#define NB_AGPS_CTRL__HOLD_RQ_FIFO_MASK                    0x00000001L
#define NB_AGPS_CTRL__HOLD_RQ_FIFO                         0x00000001L
#define NB_AGPS_CTRL__HOLD_WR_FIFO_MASK                    0x00000002L
#define NB_AGPS_CTRL__HOLD_WR_FIFO                         0x00000002L
#define NB_AGPS_CTRL__HOLD_RD_FIFO_MASK                    0x00000004L
#define NB_AGPS_CTRL__HOLD_RD_FIFO                         0x00000004L
#define NB_AGPS_CTRL__HOLD_WREQ_FIFO_MASK                  0x00000008L
#define NB_AGPS_CTRL__HOLD_WREQ_FIFO                       0x00000008L
#define NB_AGPS_CTRL__HOLD_RDSIZE_FIFO_MASK                0x00000010L
#define NB_AGPS_CTRL__HOLD_RDSIZE_FIFO                     0x00000010L
#define NB_AGPS_CTRL__DELAY_RDSIZE_FIFO_MASK               0x00000020L
#define NB_AGPS_CTRL__DELAY_RDSIZE_FIFO                    0x00000020L
#define NB_AGPS_CTRL__EN_2X_STBB_MASK                      0x00000040L
#define NB_AGPS_CTRL__EN_2X_STBB                           0x00000040L
#define NB_AGPS_CTRL__EN_EXTENDED_AD_STB_2X_MASK           0x00000080L
#define NB_AGPS_CTRL__EN_EXTENDED_AD_STB_2X                0x00000080L
#define NB_AGPS_CTRL__REG_CRIPPLE_AGP4X_MASK               0x00000100L
#define NB_AGPS_CTRL__REG_CRIPPLE_AGP4X                    0x00000100L
#define NB_AGPS_CTRL__REG_CRIPPLE_AGP2X4X_MASK             0x00000200L
#define NB_AGPS_CTRL__REG_CRIPPLE_AGP2X4X                  0x00000200L
#define NB_AGPS_CTRL__REG_CRIPPLE_AGP8X_MASK               0x00000400L
#define NB_AGPS_CTRL__REG_CRIPPLE_AGP8X                    0x00000400L
#define NB_AGPS_CTRL__REG_CRIPPLE_AGP4X8X_MASK             0x00000800L
#define NB_AGPS_CTRL__REG_CRIPPLE_AGP4X8X                  0x00000800L
#define NB_AGPS_CTRL__SBADEC_SOFT_RESET_MASK               0x00001000L
#define NB_AGPS_CTRL__SBADEC_SOFT_RESET                    0x00001000L
#define NB_AGPS_CTRL__PCI_DBI_DISABLE_MASK                 0x00002000L
#define NB_AGPS_CTRL__PCI_DBI_DISABLE                      0x00002000L
#define NB_AGPS_CTRL__AGP_DBI_DISABLE_MASK                 0x00004000L
#define NB_AGPS_CTRL__AGP_DBI_DISABLE                      0x00004000L
#define NB_AGPS_CTRL__DBI_MINIMIZE_ONES_MASK               0x00008000L
#define NB_AGPS_CTRL__DBI_MINIMIZE_ONES                    0x00008000L
#define NB_AGPS_CTRL__DBL_RSYNC_RRMEM_RPTR_MASK            0x00010000L
#define NB_AGPS_CTRL__DBL_RSYNC_RRMEM_RPTR                 0x00010000L
#define NB_AGPS_CTRL__DBL_RSYNC_RDSZ_RPTR_MASK             0x00020000L
#define NB_AGPS_CTRL__DBL_RSYNC_RDSZ_RPTR                  0x00020000L
#define NB_AGPS_CTRL__DBL_RSYNC_RDSZ_WPTR_MASK             0x00040000L
#define NB_AGPS_CTRL__DBL_RSYNC_RDSZ_WPTR                  0x00040000L
#define NB_AGPS_CTRL__AGPS_HOLD_RDSIZEMEM_MASK             0x00080000L
#define NB_AGPS_CTRL__AGPS_HOLD_RDSIZEMEM                  0x00080000L
#define NB_AGPS_CTRL__AGPS_HOLD_RDSIZE_FIFO_MASK           0x00100000L
#define NB_AGPS_CTRL__AGPS_HOLD_RDSIZE_FIFO                0x00100000L
#define NB_AGPS_CTRL__MISC_MASK                            0x00200000L
#define NB_AGPS_CTRL__MISC                                 0x00200000L
#define NB_AGPS_CTRL__DBL_RSYNC_WRFIFO_RPTR_MASK           0x00400000L
#define NB_AGPS_CTRL__DBL_RSYNC_WRFIFO_RPTR                0x00400000L
#define NB_AGPS_CTRL__DBL_RSYNC_WRFIFO_WPTR_MASK           0x00800000L
#define NB_AGPS_CTRL__DBL_RSYNC_WRFIFO_WPTR                0x00800000L
#define NB_AGPS_CTRL__DBL_RSYNC_RDFIFO_RPTR_MASK           0x01000000L
#define NB_AGPS_CTRL__DBL_RSYNC_RDFIFO_RPTR                0x01000000L
#define NB_AGPS_CTRL__DBL_RSYNC_RDFIFO_WPTR_MASK           0x02000000L
#define NB_AGPS_CTRL__DBL_RSYNC_RDFIFO_WPTR                0x02000000L
#define NB_AGPS_CTRL__DBL_RSYNC_RQFIFO_RPTR_MASK           0x04000000L
#define NB_AGPS_CTRL__DBL_RSYNC_RQFIFO_RPTR                0x04000000L
#define NB_AGPS_CTRL__DBL_RSYNC_RQFIFO_WPTR_MASK           0x08000000L
#define NB_AGPS_CTRL__DBL_RSYNC_RQFIFO_WPTR                0x08000000L
#define NB_AGPS_CTRL__DBL_RSYNC_WREQ_RPTR_MASK             0x10000000L
#define NB_AGPS_CTRL__DBL_RSYNC_WREQ_RPTR                  0x10000000L
#define NB_AGPS_CTRL__DBL_RSYNC_WREQ_WPTR_MASK             0x20000000L
#define NB_AGPS_CTRL__DBL_RSYNC_WREQ_WPTR                  0x20000000L
#define NB_AGPS_CTRL__DBL_RSYNC_RDSIZE_RPTR_MASK           0x40000000L
#define NB_AGPS_CTRL__DBL_RSYNC_RDSIZE_RPTR                0x40000000L
#define NB_AGPS_CTRL__DBL_RSYNC_RDSIZE_WPTR_MASK           0x80000000L
#define NB_AGPS_CTRL__DBL_RSYNC_RDSIZE_WPTR                0x80000000L

// NB_AGP_FIFO_CTRL
#define NB_AGP_FIFO_CTRL__WREQFIFO_WM_MIN_MASK             0x0000000fL
#define NB_AGP_FIFO_CTRL__WREQFIFO_WM_MAX_MASK             0x000000f0L

// NB_APC_FIFO_CTRL
#define NB_APC_FIFO_CTRL__MDF_RDF_DBL_SYNC_RPTR_MASK       0x00000001L
#define NB_APC_FIFO_CTRL__MDF_RDF_DBL_SYNC_RPTR            0x00000001L
#define NB_APC_FIFO_CTRL__MDF_RDF_DBL_SYNC_WPTR_MASK       0x00000002L
#define NB_APC_FIFO_CTRL__MDF_RDF_DBL_SYNC_WPTR            0x00000002L
#define NB_APC_FIFO_CTRL__MDF_WRF_DBL_SYNC_RPTR_MASK       0x00000004L
#define NB_APC_FIFO_CTRL__MDF_WRF_DBL_SYNC_RPTR            0x00000004L
#define NB_APC_FIFO_CTRL__MDF_WRF_DBL_SYNC_WPTR_MASK       0x00000008L
#define NB_APC_FIFO_CTRL__MDF_WRF_DBL_SYNC_WPTR            0x00000008L
#define NB_APC_FIFO_CTRL__TWR_TMF_DBL_SYNC_RPTR_MASK       0x00000010L
#define NB_APC_FIFO_CTRL__TWR_TMF_DBL_SYNC_RPTR            0x00000010L
#define NB_APC_FIFO_CTRL__TWR_TMF_DBL_SYNC_WPTR_MASK       0x00000020L
#define NB_APC_FIFO_CTRL__TWR_TMF_DBL_SYNC_WPTR            0x00000020L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT06_MASK         0x00000040L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT06              0x00000040L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT07_MASK         0x00000080L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT07              0x00000080L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT08_MASK         0x00000100L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT08              0x00000100L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT09_MASK         0x00000200L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT09              0x00000200L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT10_MASK         0x00000400L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT10              0x00000400L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT11_MASK         0x00000800L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT11              0x00000800L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT12_MASK         0x00001000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT12              0x00001000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT13_MASK         0x00002000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT13              0x00002000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT14_MASK         0x00004000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT14              0x00004000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT15_MASK         0x00008000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT15              0x00008000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT16_MASK         0x00010000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT16              0x00010000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT17_MASK         0x00020000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT17              0x00020000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT18_MASK         0x00040000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT18              0x00040000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT19_MASK         0x00080000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT19              0x00080000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT20_MASK         0x00100000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT20              0x00100000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT21_MASK         0x00200000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT21              0x00200000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT22_MASK         0x00400000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT22              0x00400000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT23_MASK         0x00800000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT23              0x00800000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT24_MASK         0x01000000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT24              0x01000000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT25_MASK         0x02000000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT25              0x02000000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT26_MASK         0x04000000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT26              0x04000000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT27_MASK         0x08000000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT27              0x08000000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT28_MASK         0x10000000L
#define NB_APC_FIFO_CTRL__APC_FIFO_CTRL_BIT28              0x10000000L
#define NB_APC_FIFO_CTRL__HOLD_FW_FIFO_MASK                0x20000000L
#define NB_APC_FIFO_CTRL__HOLD_FW_FIFO                     0x20000000L
#define NB_APC_FIFO_CTRL__RSYNC_FW_FIFO_RPTR_MASK          0x40000000L
#define NB_APC_FIFO_CTRL__RSYNC_FW_FIFO_RPTR               0x40000000L
#define NB_APC_FIFO_CTRL__RSYNC_FW_FIFO_WPTR_MASK          0x80000000L
#define NB_APC_FIFO_CTRL__RSYNC_FW_FIFO_WPTR               0x80000000L

// NB_PCI_FIFO_CTRL
#define NB_PCI_FIFO_CTRL__MDF_RDF_DBL_SYNC_RPTR_MASK       0x00000001L
#define NB_PCI_FIFO_CTRL__MDF_RDF_DBL_SYNC_RPTR            0x00000001L
#define NB_PCI_FIFO_CTRL__MDF_RDF_DBL_SYNC_WPTR_MASK       0x00000002L
#define NB_PCI_FIFO_CTRL__MDF_RDF_DBL_SYNC_WPTR            0x00000002L
#define NB_PCI_FIFO_CTRL__MDF_WRF_DBL_SYNC_RPTR_MASK       0x00000004L
#define NB_PCI_FIFO_CTRL__MDF_WRF_DBL_SYNC_RPTR            0x00000004L
#define NB_PCI_FIFO_CTRL__MDF_WRF_DBL_SYNC_WPTR_MASK       0x00000008L
#define NB_PCI_FIFO_CTRL__MDF_WRF_DBL_SYNC_WPTR            0x00000008L
#define NB_PCI_FIFO_CTRL__TWR_TMF_DBL_SYNC_RPTR_MASK       0x00000010L
#define NB_PCI_FIFO_CTRL__TWR_TMF_DBL_SYNC_RPTR            0x00000010L
#define NB_PCI_FIFO_CTRL__TWR_TMF_DBL_SYNC_WPTR_MASK       0x00000020L
#define NB_PCI_FIFO_CTRL__TWR_TMF_DBL_SYNC_WPTR            0x00000020L
#define NB_PCI_FIFO_CTRL__TWR_PTPF_DBL_SYNC_RPTR_MASK      0x00000040L
#define NB_PCI_FIFO_CTRL__TWR_PTPF_DBL_SYNC_RPTR           0x00000040L
#define NB_PCI_FIFO_CTRL__TWR_PTPF_DBL_SYNC_WPTR_MASK      0x00000080L
#define NB_PCI_FIFO_CTRL__TWR_PTPF_DBL_SYNC_WPTR           0x00000080L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT08_MASK         0x00000100L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT08              0x00000100L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT09_MASK         0x00000200L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT09              0x00000200L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT10_MASK         0x00000400L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT10              0x00000400L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT11_MASK         0x00000800L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT11              0x00000800L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT12_MASK         0x00001000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT12              0x00001000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT13_MASK         0x00002000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT13              0x00002000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT14_MASK         0x00004000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT14              0x00004000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT15_MASK         0x00008000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT15              0x00008000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT16_MASK         0x00010000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT16              0x00010000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT17_MASK         0x00020000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT17              0x00020000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT18_MASK         0x00040000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT18              0x00040000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT19_MASK         0x00080000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT19              0x00080000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT20_MASK         0x00100000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT20              0x00100000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT21_MASK         0x00200000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT21              0x00200000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT22_MASK         0x00400000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT22              0x00400000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT23_MASK         0x00800000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT23              0x00800000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT24_MASK         0x01000000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT24              0x01000000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT25_MASK         0x02000000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT25              0x02000000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT26_MASK         0x04000000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT26              0x04000000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT27_MASK         0x08000000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT27              0x08000000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT28_MASK         0x10000000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT28              0x10000000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT29_MASK         0x20000000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT29              0x20000000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT30_MASK         0x40000000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT30              0x40000000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT31_MASK         0x80000000L
#define NB_PCI_FIFO_CTRL__PCI_FIFO_CTRL_BIT31              0x80000000L

// NB_PAD_CTLR_STRENGTH
#define NB_PAD_CTLR_STRENGTH__PAD_N_STRENGTH_SBA_CNTL_MASK 0x0000001fL
#define NB_PAD_CTLR_STRENGTH__PAD_P_STRENGTH_SBA_CNTL_MASK 0x00001f00L
#define NB_PAD_CTLR_STRENGTH__PAD_MANUAL_OVERRIDE_L_MASK   0x00008000L
#define NB_PAD_CTLR_STRENGTH__PAD_MANUAL_OVERRIDE_L        0x00008000L
#define NB_PAD_CTLR_STRENGTH__PAD_N_STRENGTH_ADH_ADL_MASK  0x001f0000L
#define NB_PAD_CTLR_STRENGTH__PAD_P_STRENGTH_ADH_ADL_MASK  0x1f000000L
#define NB_PAD_CTLR_STRENGTH__PAD_MANUAL_OVERRIDE_H_MASK   0x80000000L
#define NB_PAD_CTLR_STRENGTH__PAD_MANUAL_OVERRIDE_H        0x80000000L

// NB_PAD_CTLR_STRENGTH_READBACK
#define NB_PAD_CTLR_STRENGTH_READBACK__PAD_N_STRENGTH_SBA_CNTL_RB_MASK 0x0000001fL
#define NB_PAD_CTLR_STRENGTH_READBACK__PAD_P_STRENGTH_SBA_CNTL_RB_MASK 0x00001f00L
#define NB_PAD_CTLR_STRENGTH_READBACK__PAD_N_STRENGTH_ADH_ADL_RB_MASK 0x001f0000L
#define NB_PAD_CTLR_STRENGTH_READBACK__PAD_P_STRENGTH_ADH_ADL_RB_MASK 0x1f000000L

// NB_PAD_CTLR_UPDATE
#define NB_PAD_CTLR_UPDATE__PAD_UPDATE_RATE_MASK           0x0000001fL
#define NB_PAD_CTLR_UPDATE__PAD_SAMPLE_DELAY_MASK          0x00001f00L
#define NB_PAD_CTLR_UPDATE__PAD_INC_THRESHOLD_MASK         0x001f0000L
#define NB_PAD_CTLR_UPDATE__PAD_DEC_THRESHOLD_MASK         0x1f000000L

// NB_PAD_CTLR_MISC
#define NB_PAD_CTLR_MISC__DYNAMIC_IMP_EN_MASK              0x00000001L
#define NB_PAD_CTLR_MISC__DYNAMIC_IMP_EN                   0x00000001L
#define NB_PAD_CTLR_MISC__DISABLE_WPTR_RST_MASK            0x00000002L
#define NB_PAD_CTLR_MISC__DISABLE_WPTR_RST                 0x00000002L
#define NB_PAD_CTLR_MISC__PAD_VREF_INT_EN_MASK             0x0000001cL
#define NB_PAD_CTLR_MISC__AUTO_AGP_RSYNC_EN_MASK           0x00000020L
#define NB_PAD_CTLR_MISC__AUTO_AGP_RSYNC_EN                0x00000020L
#define NB_PAD_CTLR_MISC__AGP_RSYNC_AD_DURING_WR_IDLE_EN_MASK 0x00000040L
#define NB_PAD_CTLR_MISC__AGP_RSYNC_AD_DURING_WR_IDLE_EN   0x00000040L
#define NB_PAD_CTLR_MISC__MANUAL_AGP_RSYNC_MASK            0x00000080L
#define NB_PAD_CTLR_MISC__MANUAL_AGP_RSYNC                 0x00000080L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_PREAMPH_MASK           0x00000100L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_PREAMPH                0x00000100L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_PREAMPH_STB_MASK       0x00000200L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_PREAMPH_STB            0x00000200L
#define NB_PAD_CTLR_MISC__PAD_PAR_RB_MASK                  0x00000400L
#define NB_PAD_CTLR_MISC__PAD_PAR_RB                       0x00000400L
#define NB_PAD_CTLR_MISC__PAD_AGP30_SIG_SBA_UPDATE_CNTL_MASK 0x00002000L
#define NB_PAD_CTLR_MISC__PAD_AGP30_SIG_SBA_UPDATE_CNTL    0x00002000L
#define NB_PAD_CTLR_MISC__PAD_AGP30_SIG_SBA_CAL_DIS_MASK   0x00004000L
#define NB_PAD_CTLR_MISC__PAD_AGP30_SIG_SBA_CAL_DIS        0x00004000L
#define NB_PAD_CTLR_MISC__PAD_AGP30_SIG_TRDY_DIS_MASK      0x00008000L
#define NB_PAD_CTLR_MISC__PAD_AGP30_SIG_TRDY_DIS           0x00008000L
#define NB_PAD_CTLR_MISC__PAD_AGP30SIGNALING_CAL_DIS_MASK  0x00010000L
#define NB_PAD_CTLR_MISC__PAD_AGP30SIGNALING_CAL_DIS       0x00010000L
#define NB_PAD_CTLR_MISC__PAD_TEST_OUT_MASK                0x00020000L
#define NB_PAD_CTLR_MISC__PAD_TEST_OUT                     0x00020000L
#define NB_PAD_CTLR_MISC__PAD_DUMMY_OUT_MASK               0x00040000L
#define NB_PAD_CTLR_MISC__PAD_DUMMY_OUT                    0x00040000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_DFR_MASK               0x00080000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_DFR                    0x00080000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_SCHMEN_MASK            0x00100000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_SCHMEN                 0x00100000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_DREN_MASK              0x00200000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_DREN                   0x00200000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_VDIFF_MASK             0x00800000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_VDIFF                  0x00800000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_DFR_OVERRIDE_MASK      0x01000000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_DFR_OVERRIDE           0x01000000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_SCHMEN_OVERRIDE_MASK   0x02000000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_SCHMEN_OVERRIDE        0x02000000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_DREN_OVERRIDE_MASK     0x04000000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_DREN_OVERRIDE          0x04000000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_VDIFF_OVERRIDE_MASK    0x10000000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_VDIFF_OVERRIDE         0x10000000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_SLEWN_MASK             0x20000000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_SLEWN                  0x20000000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_SLEWP_MASK             0x40000000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_SLEWP                  0x40000000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_SLEW_OVERRIDE_MASK     0x80000000L
#define NB_PAD_CTLR_MISC__PAD_HI_IO_SLEW_OVERRIDE          0x80000000L

// NB_PAMAC0_DLY_CNTL
#define NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_DATA_U_MASK      0x0000000fL
#define NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_DATA_L_MASK      0x000000f0L
#define NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_STB_MASK         0x00000f00L
#define NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_DBI_MASK         0x0000f000L
#define NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_DATA_U_MASK     0x00030000L
#define NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_DATA_L_MASK     0x000c0000L
#define NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_STB_MASK        0x00300000L
#define NB_PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_DBI_MASK        0x00c00000L
#define NB_PAMAC0_DLY_CNTL__PAMAC0_CLK_INS_DLY_MASK        0x01000000L
#define NB_PAMAC0_DLY_CNTL__PAMAC0_CLK_INS_DLY             0x01000000L
#define NB_PAMAC0_DLY_CNTL__PAMAC0_SYNC_DLY_MASK           0x0e000000L

// NB_PAMAC1_DLY_CNTL
#define NB_PAMAC1_DLY_CNTL__PAMAC1_DLY_IN_DATA_U_MASK      0x0000000fL
#define NB_PAMAC1_DLY_CNTL__PAMAC1_DLY_IN_DATA_L_MASK      0x000000f0L
#define NB_PAMAC1_DLY_CNTL__PAMAC1_DLY_IN_STB_MASK         0x00000f00L
#define NB_PAMAC1_DLY_CNTL__PAMAC1_DLY_OUT_DATA_U_MASK     0x00030000L
#define NB_PAMAC1_DLY_CNTL__PAMAC1_DLY_OUT_DATA_L_MASK     0x000c0000L
#define NB_PAMAC1_DLY_CNTL__PAMAC1_DLY_OUT_STB_MASK        0x00300000L
#define NB_PAMAC1_DLY_CNTL__PAMAC1_CLK_INS_DLY_MASK        0x01000000L
#define NB_PAMAC1_DLY_CNTL__PAMAC1_CLK_INS_DLY             0x01000000L
#define NB_PAMAC1_DLY_CNTL__PAMAC1_SYNC_DLY_MASK           0x0e000000L

// NB_PAMAC2_DLY_CNTL
#define NB_PAMAC2_DLY_CNTL__PAMAC2_DLY_IN_DATA_U_MASK      0x0000000fL
#define NB_PAMAC2_DLY_CNTL__PAMAC2_DLY_IN_DATA_L_MASK      0x000000f0L
#define NB_PAMAC2_DLY_CNTL__PAMAC2_DLY_IN_STB_MASK         0x00000f00L
#define NB_PAMAC2_DLY_CNTL__PAMAC2_DLY_OUT_DATA_U_MASK     0x00030000L
#define NB_PAMAC2_DLY_CNTL__PAMAC2_DLY_OUT_DATA_L_MASK     0x000c0000L
#define NB_PAMAC2_DLY_CNTL__PAMAC2_DLY_OUT_STB_MASK        0x00300000L
#define NB_PAMAC2_DLY_CNTL__PAMAC2_CLK_INS_DLY_MASK        0x01000000L
#define NB_PAMAC2_DLY_CNTL__PAMAC2_CLK_INS_DLY             0x01000000L
#define NB_PAMAC2_DLY_CNTL__PAMAC2_SYNC_DLY_MASK           0x0e000000L

// NB_AGP_DEBUG
#define NB_AGP_DEBUG__ADL_DfrOverride_MASK                 0x00000001L
#define NB_AGP_DEBUG__ADL_DfrOverride                      0x00000001L
#define NB_AGP_DEBUG__ADL_DrenOverride_MASK                0x00000002L
#define NB_AGP_DEBUG__ADL_DrenOverride                     0x00000002L
#define NB_AGP_DEBUG__ADL_SchmenOverride_MASK              0x00000004L
#define NB_AGP_DEBUG__ADL_SchmenOverride                   0x00000004L
#define NB_AGP_DEBUG__ADL_Dfr_MASK                         0x00000008L
#define NB_AGP_DEBUG__ADL_Dfr                              0x00000008L
#define NB_AGP_DEBUG__ADL_Dren_MASK                        0x00000010L
#define NB_AGP_DEBUG__ADL_Dren                             0x00000010L
#define NB_AGP_DEBUG__ADL_Schmen_MASK                      0x00000020L
#define NB_AGP_DEBUG__ADL_Schmen                           0x00000020L
#define NB_AGP_DEBUG__ADH_DfrOverride_MASK                 0x00000040L
#define NB_AGP_DEBUG__ADH_DfrOverride                      0x00000040L
#define NB_AGP_DEBUG__ADH_DrenOverride_MASK                0x00000080L
#define NB_AGP_DEBUG__ADH_DrenOverride                     0x00000080L
#define NB_AGP_DEBUG__ADH_SchmenOverride_MASK              0x00000100L
#define NB_AGP_DEBUG__ADH_SchmenOverride                   0x00000100L
#define NB_AGP_DEBUG__ADH_Dfr_MASK                         0x00000200L
#define NB_AGP_DEBUG__ADH_Dfr                              0x00000200L
#define NB_AGP_DEBUG__ADH_Dren_MASK                        0x00000400L
#define NB_AGP_DEBUG__ADH_Dren                             0x00000400L
#define NB_AGP_DEBUG__ADH_Schmen_MASK                      0x00000800L
#define NB_AGP_DEBUG__ADH_Schmen                           0x00000800L
#define NB_AGP_DEBUG__PerfCnt0ClkSel_MASK                  0x00001000L
#define NB_AGP_DEBUG__PerfCnt0ClkSel                       0x00001000L
#define NB_AGP_DEBUG__PerfCnt1ClkSel_MASK                  0x00002000L
#define NB_AGP_DEBUG__PerfCnt1ClkSel                       0x00002000L
#define NB_AGP_DEBUG__AGP_DEBUG_14_MASK                    0x00004000L
#define NB_AGP_DEBUG__AGP_DEBUG_14                         0x00004000L
#define NB_AGP_DEBUG__AGP_DEBUG_15_MASK                    0x00008000L
#define NB_AGP_DEBUG__AGP_DEBUG_15                         0x00008000L
#define NB_AGP_DEBUG__AGP_DEBUG_16_MASK                    0x00010000L
#define NB_AGP_DEBUG__AGP_DEBUG_16                         0x00010000L
#define NB_AGP_DEBUG__AGP_DEBUG_17_MASK                    0x00020000L
#define NB_AGP_DEBUG__AGP_DEBUG_17                         0x00020000L
#define NB_AGP_DEBUG__AGP_DEBUG_18_MASK                    0x00040000L
#define NB_AGP_DEBUG__AGP_DEBUG_18                         0x00040000L
#define NB_AGP_DEBUG__AGP_DEBUG_19_MASK                    0x00080000L
#define NB_AGP_DEBUG__AGP_DEBUG_19                         0x00080000L
#define NB_AGP_DEBUG__AGP_DEBUG_20_MASK                    0x00100000L
#define NB_AGP_DEBUG__AGP_DEBUG_20                         0x00100000L
#define NB_AGP_DEBUG__AGP_DEBUG_21_MASK                    0x00200000L
#define NB_AGP_DEBUG__AGP_DEBUG_21                         0x00200000L
#define NB_AGP_DEBUG__AGP_DEBUG_22_MASK                    0x00400000L
#define NB_AGP_DEBUG__AGP_DEBUG_22                         0x00400000L
#define NB_AGP_DEBUG__AGP_DEBUG_23_MASK                    0x00800000L
#define NB_AGP_DEBUG__AGP_DEBUG_23                         0x00800000L
#define NB_AGP_DEBUG__AGP_DEBUG_24_MASK                    0x01000000L
#define NB_AGP_DEBUG__AGP_DEBUG_24                         0x01000000L
#define NB_AGP_DEBUG__AGP_DEBUG_25_MASK                    0x02000000L
#define NB_AGP_DEBUG__AGP_DEBUG_25                         0x02000000L
#define NB_AGP_DEBUG__AGP_DEBUG_26_MASK                    0x04000000L
#define NB_AGP_DEBUG__AGP_DEBUG_26                         0x04000000L
#define NB_AGP_DEBUG__AGP_DEBUG_27_MASK                    0x08000000L
#define NB_AGP_DEBUG__AGP_DEBUG_27                         0x08000000L
#define NB_AGP_DEBUG__AGP_DEBUG_28_MASK                    0x10000000L
#define NB_AGP_DEBUG__AGP_DEBUG_28                         0x10000000L
#define NB_AGP_DEBUG__AGP_DEBUG_29_MASK                    0x20000000L
#define NB_AGP_DEBUG__AGP_DEBUG_29                         0x20000000L
#define NB_AGP_DEBUG__AGP_DEBUG_30_MASK                    0x40000000L
#define NB_AGP_DEBUG__AGP_DEBUG_30                         0x40000000L
#define NB_AGP_DEBUG__AGP_DEBUG_31_MASK                    0x80000000L
#define NB_AGP_DEBUG__AGP_DEBUG_31                         0x80000000L

// NB_ALINK_PERF_COUNT0
#define NB_ALINK_PERF_COUNT0__COUNTER_0_MASK               0xffffffffL

// NB_ALINK_PERF_COUNT1
#define NB_ALINK_PERF_COUNT1__COUNTER_1_MASK               0xffffffffL

// NB_ALINK_PERF_CNTL
#define NB_ALINK_PERF_CNTL__EVENT0_SEL_MASK                0x000000ffL
#define NB_ALINK_PERF_CNTL__EVENT1_SEL_MASK                0x0000ff00L
#define NB_ALINK_PERF_CNTL__COUNTER_0_MASK                 0x00ff0000L
#define NB_ALINK_PERF_CNTL__COUNTER_1_MASK                 0xff000000L

// NB_ALINK_CFG2

// NB_ALINK2_CFG_CNTL
#define NB_ALINK2_CFG_CNTL__ALINK2_ENABLE_MASK             0x00000001L
#define NB_ALINK2_CFG_CNTL__ALINK2_ENABLE                  0x00000001L
#define NB_ALINK2_CFG_CNTL__PAD_DEC_THRESHOLD_MASK         0x0000003eL
#define NB_ALINK2_CFG_CNTL__PAD_INC_THRESHOLD_MASK         0x000007c0L
#define NB_ALINK2_CFG_CNTL__PAD_SAMPLE_DELAY_MASK          0x0000f800L
#define NB_ALINK2_CFG_CNTL__PAD_UPDATE_RATE_MASK           0x001f0000L

// NB_ALINK2_TNX_CNTL
#define NB_ALINK2_TNX_CNTL__AL2_DBIEn_MASK                 0x00000001L
#define NB_ALINK2_TNX_CNTL__AL2_DBIEn                      0x00000001L
#define NB_ALINK2_TNX_CNTL__AL2_BurstReadMEn_MASK          0x00000002L
#define NB_ALINK2_TNX_CNTL__AL2_BurstReadMEn               0x00000002L
#define NB_ALINK2_TNX_CNTL__AL2_WFifoSz_MASK               0x0000000cL
#define NB_ALINK2_TNX_CNTL__AL2_RFifoSz_MASK               0x00000030L
#define NB_ALINK2_TNX_CNTL__AL2_AFifoSz_MASK               0x000001c0L
#define NB_ALINK2_TNX_CNTL__AL2_CalResetEn_MASK            0x00000200L
#define NB_ALINK2_TNX_CNTL__AL2_CalResetEn                 0x00000200L
#define NB_ALINK2_TNX_CNTL__AL2_CalCycleEn_MASK            0x00000400L
#define NB_ALINK2_TNX_CNTL__AL2_CalCycleEn                 0x00000400L
#define NB_ALINK2_TNX_CNTL__AL2_BurstReadTEn_MASK          0x00000800L
#define NB_ALINK2_TNX_CNTL__AL2_BurstReadTEn               0x00000800L
#define NB_ALINK2_TNX_CNTL__AL2_PostWriteTimeOutEn_MASK    0x00002000L
#define NB_ALINK2_TNX_CNTL__AL2_PostWriteTimeOutEn         0x00002000L
#define NB_ALINK2_TNX_CNTL__AL2_NonPostWriteTimeOutEn_MASK 0x00004000L
#define NB_ALINK2_TNX_CNTL__AL2_NonPostWriteTimeOutEn      0x00004000L
#define NB_ALINK2_TNX_CNTL__AL2_ReadTimeOutEn_MASK         0x00008000L
#define NB_ALINK2_TNX_CNTL__AL2_ReadTimeOutEn              0x00008000L
#define NB_ALINK2_TNX_CNTL__AL2_ArbPriority_MASK           0x00030000L
#define NB_ALINK2_TNX_CNTL__AL2_Mode_MASK                  0x000c0000L
#define NB_ALINK2_TNX_CNTL__AL2_DecTiming_MASK             0x00300000L
#define NB_ALINK2_TNX_CNTL__AL2_MasterAbortStatus_MASK     0x00400000L
#define NB_ALINK2_TNX_CNTL__AL2_MasterAbortStatus          0x00400000L
#define NB_ALINK2_TNX_CNTL__AL2_ADFifoSzM_MASK             0x03800000L
#define NB_ALINK2_TNX_CNTL__AL2_WriteFifoSzM_MASK          0x0c000000L
#define NB_ALINK2_TNX_CNTL__AL2_ReadFifoSzM_MASK           0x30000000L

// NB_ALINK_PAD_CNTL
#define NB_ALINK_PAD_CNTL__dly_in_AD7_0_MASK               0x0000000fL
#define NB_ALINK_PAD_CNTL__dly_in_AD8_15_MASK              0x000000f0L
#define NB_ALINK_PAD_CNTL__dly_in_CBE1_0_MASK              0x00000f00L
#define NB_ALINK_PAD_CNTL__dly_in_STB_MASK                 0x0000f000L
#define NB_ALINK_PAD_CNTL__dly_in_DBI_MASK                 0x000f0000L
#define NB_ALINK_PAD_CNTL__dly_out_AD7_0_MASK              0x00300000L
#define NB_ALINK_PAD_CNTL__dly_out_AD8_15_MASK             0x00c00000L
#define NB_ALINK_PAD_CNTL__dly_out_CBE1_0_MASK             0x03000000L
#define NB_ALINK_PAD_CNTL__dly_out_STB_MASK                0x0c000000L
#define NB_ALINK_PAD_CNTL__dly_out_DBI_MASK                0x30000000L
#define NB_ALINK_PAD_CNTL__AL2_signalmode_MASK             0xc0000000L

// NB_ALINK_PAD_CNTL2
#define NB_ALINK_PAD_CNTL2__AL28xMode_MASK                 0x00000001L
#define NB_ALINK_PAD_CNTL2__AL28xMode                      0x00000001L
#define NB_ALINK_PAD_CNTL2__preamph1_5_MASK                0x00000002L
#define NB_ALINK_PAD_CNTL2__preamph1_5                     0x00000002L
#define NB_ALINK_PAD_CNTL2__en5_eightxsig_MASK             0x00000004L
#define NB_ALINK_PAD_CNTL2__en5_eightxsig                  0x00000004L
#define NB_ALINK_PAD_CNTL2__PAD_MANUAL_OVERRIDE_MASK       0x00000008L
#define NB_ALINK_PAD_CNTL2__PAD_MANUAL_OVERRIDE            0x00000008L
#define NB_ALINK_PAD_CNTL2__PAD_P_MANUAL_STRENGTH_MASK     0x000001f0L
#define NB_ALINK_PAD_CNTL2__PAD_N_MANUAL_STRENGTH_MASK     0x00003e00L
#define NB_ALINK_PAD_CNTL2__DYNAMIC_IMP_EN_MASK            0x00004000L
#define NB_ALINK_PAD_CNTL2__DYNAMIC_IMP_EN                 0x00004000L
#define NB_ALINK_PAD_CNTL2__PAD_P_STRENGTH_READ_BACK_MASK  0x000f8000L
#define NB_ALINK_PAD_CNTL2__PAD_N_STRENGTH_READ_BACK_MASK  0x01f00000L
#define NB_ALINK_PAD_CNTL2__SRN_MASK                       0x02000000L
#define NB_ALINK_PAD_CNTL2__SRN                            0x02000000L
#define NB_ALINK_PAD_CNTL2__SRP_MASK                       0x04000000L
#define NB_ALINK_PAD_CNTL2__SRP                            0x04000000L
#define NB_ALINK_PAD_CNTL2__PD_MASK                        0x08000000L
#define NB_ALINK_PAD_CNTL2__PD                             0x08000000L
#define NB_ALINK_PAD_CNTL2__PU_MASK                        0x10000000L
#define NB_ALINK_PAD_CNTL2__PU                             0x10000000L
#define NB_ALINK_PAD_CNTL2__AL264bitCntl_MASK              0x60000000L
#define NB_ALINK_PAD_CNTL2__AGP_INT_ENABLE_MASK            0x80000000L
#define NB_ALINK_PAD_CNTL2__AGP_INT_ENABLE                 0x80000000L

// BIU_PERF_COUNT0_nb
#define BIU_PERF_COUNT0_nb__COUNTER0_MASK                  0xffffffffL

// BIU_PERF_COUNT1_nb
#define BIU_PERF_COUNT1_nb__COUNTER1_MASK                  0xffffffffL

// BIU_PERF_CNTL_nb
#define BIU_PERF_CNTL_nb__EVENT0_SEL_MASK                  0x000000ffL
#define BIU_PERF_CNTL_nb__EVENT1_SEL_MASK                  0x0000ff00L
#define BIU_PERF_CNTL_nb__COUNTER0_UPPER_MASK              0x00ff0000L
#define BIU_PERF_CNTL_nb__COUNTER1_UPPER_MASK              0xff000000L

// NB_AGP_PERF_COUNT0
#define NB_AGP_PERF_COUNT0__COUNTER0_MASK                  0xffffffffL

// NB_AGP_PERF_COUNT1
#define NB_AGP_PERF_COUNT1__COUNTER1_MASK                  0xffffffffL

// NB_AGP_PERF_CNTL
#define NB_AGP_PERF_CNTL__EVENT0_SEL_MASK                  0x000000ffL
#define NB_AGP_PERF_CNTL__EVENT1_SEL_MASK                  0x0000ff00L
#define NB_AGP_PERF_CNTL__COUNTER0_UPPER_MASK              0x00ff0000L
#define NB_AGP_PERF_CNTL__COUNTER1_UPPER_MASK              0xff000000L

// PM2_CNTRL
#define PM2_CNTRL__ARB_DISABLE_MASK                        0x00000001L
#define PM2_CNTRL__ARB_DISABLE                             0x00000001L

// GART_FEATURE_ID
#define GART_FEATURE_ID__REV_ID_MASK                       0x000000ffL
#define GART_FEATURE_ID__VAL_CAP_MASK                      0x00000100L
#define GART_FEATURE_ID__VAL_CAP                           0x00000100L
#define GART_FEATURE_ID__LINK_CAP_MASK                     0x00000200L
#define GART_FEATURE_ID__LINK_CAP                          0x00000200L
#define GART_FEATURE_ID__P2P_CAP_MASK                      0x00000400L
#define GART_FEATURE_ID__P2P_CAP                           0x00000400L
#define GART_FEATURE_ID__HANG_EN_MASK                      0x00000800L
#define GART_FEATURE_ID__HANG_EN                           0x00000800L
#define GART_FEATURE_ID__GARV_ERR_EN_MASK                  0x00010000L
#define GART_FEATURE_ID__GARV_ERR_EN                       0x00010000L
#define GART_FEATURE_ID__SB_STB_TOGGLE_DETECT_DISABLE_MASK 0x00020000L
#define GART_FEATURE_ID__SB_STB_TOGGLE_DETECT_DISABLE      0x00020000L
#define GART_FEATURE_ID__TLB_ENABLE_MASK                   0x00040000L
#define GART_FEATURE_ID__TLB_ENABLE                        0x00040000L
#define GART_FEATURE_ID__P2P_ENABLE_MASK                   0x00080000L
#define GART_FEATURE_ID__P2P_ENABLE                        0x00080000L
#define GART_FEATURE_ID__VAL_ERROR_MASK                    0x01000000L
#define GART_FEATURE_ID__VAL_ERROR                         0x01000000L
#define GART_FEATURE_ID__GART_CACHE_STATUS_MASK            0x04000000L
#define GART_FEATURE_ID__GART_CACHE_STATUS                 0x04000000L
#define GART_FEATURE_ID__P2P_STATUS_MASK                   0x08000000L
#define GART_FEATURE_ID__P2P_STATUS                        0x08000000L
#define GART_FEATURE_ID__VALID_BIT_ERROR_ID_MASK           0x30000000L

// GART_BASE
#define GART_BASE__DIRECTORY_BASE_MASK                     0xfffff000L

// GART_CACHE_SZBASE
#define GART_CACHE_SZBASE__GART_CACHE_SIZE_MASK            0xffffffffL

// GART_CACHE_CNTRL
#define GART_CACHE_CNTRL__GART_CACHE_INVALIDATE_MASK       0x00000001L
#define GART_CACHE_CNTRL__GART_CACHE_INVALIDATE            0x00000001L

// GART_CACHE_ENTRY_CNTRL
#define GART_CACHE_ENTRY_CNTRL__TlB_INV_ENT_MASK           0x00000001L
#define GART_CACHE_ENTRY_CNTRL__TlB_INV_ENT                0x00000001L
#define GART_CACHE_ENTRY_CNTRL__TlB_UPDATE_MASK            0x00000002L
#define GART_CACHE_ENTRY_CNTRL__TlB_UPDATE                 0x00000002L
#define GART_CACHE_ENTRY_CNTRL__GART_TABLE_ENTRY_ADDRESS_MASK 0xfffff000L

#endif




#if !defined (_cabo_MASK_HEADER)
#define _cabo_MASK_HEADER
/*
*        cabo_mask.h
*
*	Register Spec Release:  Chip Spec 2.36
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
#define HI_STAT__HI_STAT_MASK                              0x00000007L
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
#define BUS_CNTL1__BUS2_STALE_DATA_TIMER_MASK              0x000000f0L
#define BUS_CNTL1__BUS2_VGA_REG_COHERENCY_DIS_MASK         0x00000100L
#define BUS_CNTL1__BUS2_VGA_REG_COHERENCY_DIS              0x00000100L
#define BUS_CNTL1__BUS2_VGA_MEM_COHERENCY_DIS_MASK         0x00000200L
#define BUS_CNTL1__BUS2_VGA_MEM_COHERENCY_DIS              0x00000200L
#define BUS_CNTL1__BUS2_HDP_REG_COHERENCY_DIS_MASK         0x00000400L
#define BUS_CNTL1__BUS2_HDP_REG_COHERENCY_DIS              0x00000400L
#define BUS_CNTL1__BUS2_GUI_INITIATOR_COHERENCY_DIS_MASK   0x00000800L
#define BUS_CNTL1__BUS2_GUI_INITIATOR_COHERENCY_DIS        0x00000800L
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
#define CONFIG_MEMSIZE__CONFIG_MEMSIZE_MASK                0x1f000000L

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
#define AGP_CNTL__AGP_MISC_MASK                            0xfc000000L

// BM_STATUS
#define BM_STATUS__BUS_MASTER_STATUS_MASK                  0xffffffffL

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
#define COMMAND__AD_STEPPING_MASK                          0x00000080L
#define COMMAND__AD_STEPPING                               0x00000080L
#define COMMAND__SERR_EN_MASK                              0x00000100L
#define COMMAND__SERR_EN                                   0x00000100L
#define COMMAND__FAST_B2B_EN_MASK                          0x00000200L
#define COMMAND__FAST_B2B_EN                               0x00000200L

// STATUS
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
#define AGP_STATUS__RATE1X_MASK                            0x00000001L
#define AGP_STATUS__RATE1X                                 0x00000001L
#define AGP_STATUS__RATE2X_MASK                            0x00000002L
#define AGP_STATUS__RATE2X                                 0x00000002L
#define AGP_STATUS__RATE4X_MASK                            0x00000004L
#define AGP_STATUS__RATE4X                                 0x00000004L
#define AGP_STATUS__SBA_MASK                               0x00000200L
#define AGP_STATUS__SBA                                    0x00000200L
#define AGP_STATUS__RQ_MASK                                0xff000000L

// AGP_COMMAND
#define AGP_COMMAND__DATA_RATE_MASK                        0x00000007L
#define AGP_COMMAND__AGP_EN_MASK                           0x00000100L
#define AGP_COMMAND__AGP_EN                                0x00000100L
#define AGP_COMMAND__SBA_EN_MASK                           0x00000200L
#define AGP_COMMAND__SBA_EN                                0x00000200L
#define AGP_COMMAND__RQ_DEPTH_MASK                         0xff000000L

// AIC_CTRL
#define AIC_CTRL__TRANSLATE_EN_MASK                        0x00000001L
#define AIC_CTRL__TRANSLATE_EN                             0x00000001L
#define AIC_CTRL__HW_0_DEBUG_MASK                          0x00000002L
#define AIC_CTRL__HW_0_DEBUG                               0x00000002L
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

// MEM_IO_CNTL_A0_U1
#define MEM_IO_CNTL_A0_U1__MEM_N_CKA_MASK                  0x0000001fL
#define MEM_IO_CNTL_A0_U1__MEM_N_AA_MASK                   0x000003e0L
#define MEM_IO_CNTL_A0_U1__MEM_N_DQMA_MASK                 0x00007c00L
#define MEM_IO_CNTL_A0_U1__MEM_N_DQSA_MASK                 0x000f8000L

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
#define MEM_SDRAM_MODE_REG__MEM_MODE_REG_MASK              0x00007fffL
#define MEM_SDRAM_MODE_REG__Reserved0_MASK                 0x000f8000L
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

// MEM_IO_CNTL_A1_U1
#define MEM_IO_CNTL_A1_U1__MEM_P_CKA_MASK                  0x0000001fL
#define MEM_IO_CNTL_A1_U1__MEM_P_AA_MASK                   0x000003e0L
#define MEM_IO_CNTL_A1_U1__MEM_P_DQMA_MASK                 0x00007c00L
#define MEM_IO_CNTL_A1_U1__MEM_P_DQSA_MASK                 0x000f8000L
#define MEM_IO_CNTL_A1_U1__CLKA_ENABLE_MASK                0x00400000L
#define MEM_IO_CNTL_A1_U1__CLKA_ENABLE                     0x00400000L
#define MEM_IO_CNTL_A1_U1__Reserved_MASK                   0xff800000L

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

// MC_DEBUG_M6
#define MC_DEBUG_M6__IGNORE_RW_PENALTY_RB0R_MASK           0x00000001L
#define MC_DEBUG_M6__IGNORE_RW_PENALTY_RB0R                0x00000001L
#define MC_DEBUG_M6__IGNORE_RW_PENALTY_RB1R_MASK           0x00000002L
#define MC_DEBUG_M6__IGNORE_RW_PENALTY_RB1R                0x00000002L
#define MC_DEBUG_M6__IGNORE_RW_PENALTY_RB0W_MASK           0x00000004L
#define MC_DEBUG_M6__IGNORE_RW_PENALTY_RB0W                0x00000004L
#define MC_DEBUG_M6__IGNORE_RW_PENALTY_RB1W_MASK           0x00000008L
#define MC_DEBUG_M6__IGNORE_RW_PENALTY_RB1W                0x00000008L
#define MC_DEBUG_M6__IGNORE_RW_PENALTY_DISPR_MASK          0x00000010L
#define MC_DEBUG_M6__IGNORE_RW_PENALTY_DISPR               0x00000010L
#define MC_DEBUG_M6__IGNORE_RW_PENALTY_PPR_MASK            0x00000020L
#define MC_DEBUG_M6__IGNORE_RW_PENALTY_PPR                 0x00000020L
#define MC_DEBUG_M6__IGNORE_RW_PENALTY_FIXED_MASK          0x00000040L
#define MC_DEBUG_M6__IGNORE_RW_PENALTY_FIXED               0x00000040L
#define MC_DEBUG_M6__MEM_VIPW_PRIORITY_MASK                0x00000300L
#define MC_DEBUG_M6__CLKA0b_ENABLE_MASK                    0x00000400L
#define MC_DEBUG_M6__CLKA0b_ENABLE                         0x00000400L
#define MC_DEBUG_M6__CLKA1b_ENABLE_MASK                    0x00000800L
#define MC_DEBUG_M6__CLKA1b_ENABLE                         0x00000800L
#define MC_DEBUG_M6__CLKB0b_ENABLE_MASK                    0x00001000L
#define MC_DEBUG_M6__CLKB0b_ENABLE                         0x00001000L
#define MC_DEBUG_M6__CLKB1b_ENABLE_MASK                    0x00002000L
#define MC_DEBUG_M6__CLKB1b_ENABLE                         0x00002000L
#define MC_DEBUG_M6__DEBUG4_MASK                           0x00004000L
#define MC_DEBUG_M6__DEBUG4                                0x00004000L
#define MC_DEBUG_M6__MC_BIST_EN_MASK                       0x00008000L
#define MC_DEBUG_M6__MC_BIST_EN                            0x00008000L
#define MC_DEBUG_M6__MC_BIST_CTRL_MASK                     0x000f0000L
#define MC_DEBUG_M6__DEBUG0_MASK                           0x00100000L
#define MC_DEBUG_M6__DEBUG0                                0x00100000L
#define MC_DEBUG_M6__DEBUG1_MASK                           0x00200000L
#define MC_DEBUG_M6__DEBUG1                                0x00200000L
#define MC_DEBUG_M6__DEBUG2_MASK                           0x00400000L
#define MC_DEBUG_M6__DEBUG2                                0x00400000L
#define MC_DEBUG_M6__DEBUG3_MASK                           0x00800000L
#define MC_DEBUG_M6__DEBUG3                                0x00800000L
#define MC_DEBUG_M6__MC_DEBUG_MASK                         0x0f000000L
#define MC_DEBUG_M6__PWR_DOWN_MEM_MASK                     0x10000000L
#define MC_DEBUG_M6__PWR_DOWN_MEM                          0x10000000L
#define MC_DEBUG_M6__SWAP_CS_MASK                          0x20000000L
#define MC_DEBUG_M6__SWAP_CS                               0x20000000L
#define MC_DEBUG_M6__BLOCK_CS0_MASK                        0x40000000L
#define MC_DEBUG_M6__BLOCK_CS0                             0x40000000L
#define MC_DEBUG_M6__IKOSE_MASK                            0x80000000L
#define MC_DEBUG_M6__IKOSE                                 0x80000000L

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
#define HOST_PATH_CNTL__HDP_APER_CNTL_MASK                 0x00800000L
#define HOST_PATH_CNTL__HDP_APER_CNTL                      0x00800000L
#define HOST_PATH_CNTL__HP_LIN_RD_CACHE_DIS_MASK           0x01000000L
#define HOST_PATH_CNTL__HP_LIN_RD_CACHE_DIS                0x01000000L
#define HOST_PATH_CNTL__HP_RBBM_LOCK_DIS_MASK              0x02000000L
#define HOST_PATH_CNTL__HP_RBBM_LOCK_DIS                   0x02000000L
#define HOST_PATH_CNTL__HDP_SOFT_RESET_MASK                0x04000000L
#define HOST_PATH_CNTL__HDP_SOFT_RESET                     0x04000000L
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
#define SURFACE0_INFO__SURF0_TILE_MODE_MASK                0x00030000L
#define SURFACE0_INFO__SURF0_AP0_SWP_MASK                  0x00300000L
#define SURFACE0_INFO__SURF0_AP1_SWP_MASK                  0x00c00000L
#define SURFACE0_INFO__SURF0_WRITE_FLAG_MASK               0x01000000L
#define SURFACE0_INFO__SURF0_WRITE_FLAG                    0x01000000L
#define SURFACE0_INFO__SURF0_READ_FLAG_MASK                0x02000000L
#define SURFACE0_INFO__SURF0_READ_FLAG                     0x02000000L

// SURFACE1_INFO
#define SURFACE1_INFO__SURF1_PITCHSEL_MASK                 0x000003ffL
#define SURFACE1_INFO__SURF1_TILE_MODE_MASK                0x00030000L
#define SURFACE1_INFO__SURF1_AP0_SWP_MASK                  0x00300000L
#define SURFACE1_INFO__SURF1_AP1_SWP_MASK                  0x00c00000L
#define SURFACE1_INFO__SURF1_WRITE_FLAG_MASK               0x01000000L
#define SURFACE1_INFO__SURF1_WRITE_FLAG                    0x01000000L
#define SURFACE1_INFO__SURF1_READ_FLAG_MASK                0x02000000L
#define SURFACE1_INFO__SURF1_READ_FLAG                     0x02000000L

// SURFACE2_INFO
#define SURFACE2_INFO__SURF2_PITCHSEL_MASK                 0x000003ffL
#define SURFACE2_INFO__SURF2_TILE_MODE_MASK                0x00030000L
#define SURFACE2_INFO__SURF2_AP0_SWP_MASK                  0x00300000L
#define SURFACE2_INFO__SURF2_AP1_SWP_MASK                  0x00c00000L
#define SURFACE2_INFO__SURF2_WRITE_FLAG_MASK               0x01000000L
#define SURFACE2_INFO__SURF2_WRITE_FLAG                    0x01000000L
#define SURFACE2_INFO__SURF2_READ_FLAG_MASK                0x02000000L
#define SURFACE2_INFO__SURF2_READ_FLAG                     0x02000000L

// SURFACE3_INFO
#define SURFACE3_INFO__SURF3_PITCHSEL_MASK                 0x000003ffL
#define SURFACE3_INFO__SURF3_TILE_MODE_MASK                0x00030000L
#define SURFACE3_INFO__SURF3_AP0_SWP_MASK                  0x00300000L
#define SURFACE3_INFO__SURF3_AP1_SWP_MASK                  0x00c00000L
#define SURFACE3_INFO__SURF3_WRITE_FLAG_MASK               0x01000000L
#define SURFACE3_INFO__SURF3_WRITE_FLAG                    0x01000000L
#define SURFACE3_INFO__SURF3_READ_FLAG_MASK                0x02000000L
#define SURFACE3_INFO__SURF3_READ_FLAG                     0x02000000L

// SURFACE4_INFO
#define SURFACE4_INFO__SURF4_PITCHSEL_MASK                 0x000003ffL
#define SURFACE4_INFO__SURF4_TILE_MODE_MASK                0x00030000L
#define SURFACE4_INFO__SURF4_AP0_SWP_MASK                  0x00300000L
#define SURFACE4_INFO__SURF4_AP1_SWP_MASK                  0x00c00000L
#define SURFACE4_INFO__SURF4_WRITE_FLAG_MASK               0x01000000L
#define SURFACE4_INFO__SURF4_WRITE_FLAG                    0x01000000L
#define SURFACE4_INFO__SURF4_READ_FLAG_MASK                0x02000000L
#define SURFACE4_INFO__SURF4_READ_FLAG                     0x02000000L

// SURFACE5_INFO
#define SURFACE5_INFO__SURF5_PITCHSEL_MASK                 0x000003ffL
#define SURFACE5_INFO__SURF5_TILE_MODE_MASK                0x00030000L
#define SURFACE5_INFO__SURF5_AP0_SWP_MASK                  0x00300000L
#define SURFACE5_INFO__SURF5_AP1_SWP_MASK                  0x00c00000L
#define SURFACE5_INFO__SURF5_WRITE_FLAG_MASK               0x01000000L
#define SURFACE5_INFO__SURF5_WRITE_FLAG                    0x01000000L
#define SURFACE5_INFO__SURF5_READ_FLAG_MASK                0x02000000L
#define SURFACE5_INFO__SURF5_READ_FLAG                     0x02000000L

// SURFACE6_INFO
#define SURFACE6_INFO__SURF6_PITCHSEL_MASK                 0x000003ffL
#define SURFACE6_INFO__SURF6_TILE_MODE_MASK                0x00030000L
#define SURFACE6_INFO__SURF6_AP0_SWP_MASK                  0x00300000L
#define SURFACE6_INFO__SURF6_AP1_SWP_MASK                  0x00c00000L
#define SURFACE6_INFO__SURF6_WRITE_FLAG_MASK               0x01000000L
#define SURFACE6_INFO__SURF6_WRITE_FLAG                    0x01000000L
#define SURFACE6_INFO__SURF6_READ_FLAG_MASK                0x02000000L
#define SURFACE6_INFO__SURF6_READ_FLAG                     0x02000000L

// SURFACE7_INFO
#define SURFACE7_INFO__SURF7_PITCHSEL_MASK                 0x000003ffL
#define SURFACE7_INFO__SURF7_TILE_MODE_MASK                0x00030000L
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
#define RBBM_STATUS__SE_BUSY_MASK                          0x00100000L
#define RBBM_STATUS__SE_BUSY                               0x00100000L
#define RBBM_STATUS__RE_BUSY_MASK                          0x00200000L
#define RBBM_STATUS__RE_BUSY                               0x00200000L
#define RBBM_STATUS__TAM_BUSY_MASK                         0x00400000L
#define RBBM_STATUS__TAM_BUSY                              0x00400000L
#define RBBM_STATUS__TDM_BUSY_MASK                         0x00800000L
#define RBBM_STATUS__TDM_BUSY                              0x00800000L
#define RBBM_STATUS__PB_BUSY_MASK                          0x01000000L
#define RBBM_STATUS__PB_BUSY                               0x01000000L
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
#define RBBM_CNTL__NO_ABORT_FB_MASK                        0x00800000L
#define RBBM_CNTL__NO_ABORT_FB                             0x00800000L
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
#define RBBM_SOFT_RESET__SOFT_RESET_SE_MASK                0x00000004L
#define RBBM_SOFT_RESET__SOFT_RESET_SE                     0x00000004L
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

// RBBM_DEBUG_M6
#define RBBM_DEBUG_M6__RBBM_DEBUG_MASK                     0xffffffffL

// RBBM_CMDFIFO_ADDR
#define RBBM_CMDFIFO_ADDR__CMDFIFO_ADDR_MASK               0x0000003fL

// RBBM_CMDFIFO_DATAL
#define RBBM_CMDFIFO_DATAL__CMDFIFO_DATAL_MASK             0xffffffffL

// RBBM_CMDFIFO_DATAH
#define RBBM_CMDFIFO_DATAH__CMDFIFO_DATAH_MASK             0x00000fffL

// RBBM_CMDFIFO_STAT
#define RBBM_CMDFIFO_STAT__CMDFIFO_RPTR_MASK               0x0000003fL
#define RBBM_CMDFIFO_STAT__CMDFIFO_WPTR_MASK               0x00003f00L

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
#define LVDS_DSTN_CNTL3__DEBUG_MASK                        0x20000000L
#define LVDS_DSTN_CNTL3__DEBUG                             0x20000000L

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

// SUBPIC_CNTL
#define SUBPIC_CNTL__SUBPIC_ON_MASK                        0x00000001L
#define SUBPIC_CNTL__SUBPIC_ON                             0x00000001L
#define SUBPIC_CNTL__BTN_HLI_ON_MASK                       0x00000002L
#define SUBPIC_CNTL__BTN_HLI_ON                            0x00000002L
#define SUBPIC_CNTL__SP_HORZ_MODE_MASK                     0x00000010L
#define SUBPIC_CNTL__SP_HORZ_MODE                          0x00000010L
#define SUBPIC_CNTL__SP_VERT_MODE_MASK                     0x00000020L
#define SUBPIC_CNTL__SP_VERT_MODE                          0x00000020L
#define SUBPIC_CNTL__SP_ODD_FIELD_MASK                     0x00000100L
#define SUBPIC_CNTL__SP_ODD_FIELD                          0x00000100L
#define SUBPIC_CNTL__SP_BUF_SELECT_MASK                    0x00000200L
#define SUBPIC_CNTL__SP_BUF_SELECT                         0x00000200L
#define SUBPIC_CNTL__SP_NO_R_EDGE_BLEND_MASK               0x00000400L
#define SUBPIC_CNTL__SP_NO_R_EDGE_BLEND                    0x00000400L

// SUBPIC_DEFCOLCON
#define SUBPIC_DEFCOLCON__BKGD_PIX_CON_MASK                0x0000000fL
#define SUBPIC_DEFCOLCON__PATT_PIX_CON_MASK                0x000000f0L
#define SUBPIC_DEFCOLCON__EMPH_PIX1_CON_MASK               0x00000f00L
#define SUBPIC_DEFCOLCON__EMPH_PIX2_CON_MASK               0x0000f000L
#define SUBPIC_DEFCOLCON__BKGD_PIX_CLR_MASK                0x000f0000L
#define SUBPIC_DEFCOLCON__PATT_PIX_CLR_MASK                0x00f00000L
#define SUBPIC_DEFCOLCON__EMPH_PIX1_CLR_MASK               0x0f000000L
#define SUBPIC_DEFCOLCON__EMPH_PIX2_CLR_MASK               0xf0000000L

// SUBPIC_Y_X_START
#define SUBPIC_Y_X_START__SP_START_X_MASK                  0x000003ffL
#define SUBPIC_Y_X_START__SP_START_Y_MASK                  0x03ff0000L

// SUBPIC_Y_X_END
#define SUBPIC_Y_X_END__SP_END_X_MASK                      0x000003ffL
#define SUBPIC_Y_X_END__SP_END_Y_MASK                      0x03ff0000L

// SUBPIC_V_INC
#define SUBPIC_V_INC__SP_V_INC_FRAC_MASK                   0x0000fff0L
#define SUBPIC_V_INC__SP_V_INC_INT_MASK                    0x000f0000L

// SUBPIC_H_INC
#define SUBPIC_H_INC__SP_H_INC_FRAC_MASK                   0x0000fff0L
#define SUBPIC_H_INC__SP_H_INC_INT_MASK                    0x000f0000L

// SUBPIC_BUF0_OFFSET
#define SUBPIC_BUF0_OFFSET__SUBPIC_OFFSET0_MASK            0xffffffffL

// SUBPIC_BUF1_OFFSET
#define SUBPIC_BUF1_OFFSET__SUBPIC_OFFSET1_MASK            0xffffffffL

// SUBPIC_LC0_OFFSET
#define SUBPIC_LC0_OFFSET__SUBPIC_LC0_OFFSET_MASK          0xffffffffL

// SUBPIC_LC1_OFFSET
#define SUBPIC_LC1_OFFSET__SUBPIC_LC1_OFFSET_MASK          0xffffffffL

// SUBPIC_PITCH
#define SUBPIC_PITCH__SUBPIC_BUF_PITCH_MASK                0x00000fffL
#define SUBPIC_PITCH__SUBPIC_LC_PITCH_MASK                 0x0fff0000L

// SUBPIC_BTN_HLI_COLCON
#define SUBPIC_BTN_HLI_COLCON__BTN_HLI_BKGD_PIX_CON_MASK   0x0000000fL
#define SUBPIC_BTN_HLI_COLCON__BTN_HLI_PATT_PIX_CON_MASK   0x000000f0L
#define SUBPIC_BTN_HLI_COLCON__BTN_HLI_EMPH_PIX1_CON_MASK  0x00000f00L
#define SUBPIC_BTN_HLI_COLCON__BTN_HLI_EMPH_PIX2_CON_MASK  0x0000f000L
#define SUBPIC_BTN_HLI_COLCON__BTN_HLI_BKGD_PIX_CLR_MASK   0x000f0000L
#define SUBPIC_BTN_HLI_COLCON__BTN_HLI_PATT_PIX_CLR_MASK   0x00f00000L
#define SUBPIC_BTN_HLI_COLCON__BTN_HLI_EMPH_PIX1_CLR_MASK  0x0f000000L
#define SUBPIC_BTN_HLI_COLCON__BTN_HLI_EMPH_PIX2_CLR_MASK  0xf0000000L

// SUBPIC_BTN_HLI_Y_X_START
#define SUBPIC_BTN_HLI_Y_X_START__BTN_HLI_START_X_MASK     0x000003ffL
#define SUBPIC_BTN_HLI_Y_X_START__BTN_HLI_START_Y_MASK     0x03ff0000L

// SUBPIC_BTN_HLI_Y_X_END
#define SUBPIC_BTN_HLI_Y_X_END__BTN_HLI_END_X_MASK         0x000003ffL
#define SUBPIC_BTN_HLI_Y_X_END__BTN_HLI_END_Y_MASK         0x03ff0000L

// SUBPIC_PALETTE_INDEX
#define SUBPIC_PALETTE_INDEX__SP_PAL_ADDR_MASK             0x0000000fL

// SUBPIC_PALETTE_DATA
#define SUBPIC_PALETTE_DATA__SP_DATA_MASK                  0x00ffffffL

// SUBPIC_0_PAL
#define SUBPIC_0_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_0_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_0_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_1_PAL
#define SUBPIC_1_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_1_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_1_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_2_PAL
#define SUBPIC_2_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_2_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_2_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_3_PAL
#define SUBPIC_3_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_3_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_3_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_4_PAL
#define SUBPIC_4_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_4_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_4_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_5_PAL
#define SUBPIC_5_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_5_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_5_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_6_PAL
#define SUBPIC_6_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_6_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_6_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_7_PAL
#define SUBPIC_7_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_7_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_7_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_8_PAL
#define SUBPIC_8_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_8_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_8_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_9_PAL
#define SUBPIC_9_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_9_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_9_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_A_PAL
#define SUBPIC_A_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_A_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_A_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_B_PAL
#define SUBPIC_B_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_B_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_B_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_C_PAL
#define SUBPIC_C_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_C_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_C_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_D_PAL
#define SUBPIC_D_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_D_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_D_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_E_PAL
#define SUBPIC_E_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_E_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_E_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_F_PAL
#define SUBPIC_F_PAL__SP_CB_MASK                           0x000000ffL
#define SUBPIC_F_PAL__SP_CR_MASK                           0x0000ff00L
#define SUBPIC_F_PAL__SP_Y_MASK                            0x00ff0000L

// SUBPIC_H_ACCUM_INIT
#define SUBPIC_H_ACCUM_INIT__SP_H_ACC_INIT_FRAC_MASK       0x0000fff0L
#define SUBPIC_H_ACCUM_INIT__SP_H_ACC_INIT_INT_MASK        0x07ff0000L

// SUBPIC_V_ACCUM_INIT
#define SUBPIC_V_ACCUM_INIT__SP_V_ACC_INIT_FRAC_MASK       0x0000fff0L
#define SUBPIC_V_ACCUM_INIT__SP_V_ACC_INIT_INT_MASK        0x07ff0000L

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
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_SUBPIC_MASK        0x00000008L
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_SUBPIC             0x00000008L
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
#define DISP_TEST_DEBUG_CNTL__DISP_SUBPIC_UNDERFLOW_MASK   0x08000000L
#define DISP_TEST_DEBUG_CNTL__DISP_SUBPIC_UNDERFLOW        0x08000000L
#define DISP_TEST_DEBUG_CNTL__DISP_SUBPIC_UNDERFLOW_CLR_MASK 0x08000000L
#define DISP_TEST_DEBUG_CNTL__DISP_SUBPIC_UNDERFLOW_CLR    0x08000000L
#define DISP_TEST_DEBUG_CNTL__DISP_SUBPIC_FORCE_HI_PRI_MASK 0x10000000L
#define DISP_TEST_DEBUG_CNTL__DISP_SUBPIC_FORCE_HI_PRI     0x10000000L

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
#define DISP_HW_DEBUG__DISP_HW_12_DEBUG_MASK               0x00040000L
#define DISP_HW_DEBUG__DISP_HW_12_DEBUG                    0x00040000L
#define DISP_HW_DEBUG__DISP_HW_13_DEBUG_MASK               0x00080000L
#define DISP_HW_DEBUG__DISP_HW_13_DEBUG                    0x00080000L
#define DISP_HW_DEBUG__DISP_HW_14_DEBUG_MASK               0x00100000L
#define DISP_HW_DEBUG__DISP_HW_14_DEBUG                    0x00100000L
#define DISP_HW_DEBUG__DISP_HW_15_DEBUG_MASK               0x00200000L
#define DISP_HW_DEBUG__DISP_HW_15_DEBUG                    0x00200000L
#define DISP_HW_DEBUG__DISP_HW_16_DEBUG_MASK               0x00400000L
#define DISP_HW_DEBUG__DISP_HW_16_DEBUG                    0x00400000L
#define DISP_HW_DEBUG__DISP_HW_17_DEBUG_MASK               0x00800000L
#define DISP_HW_DEBUG__DISP_HW_17_DEBUG                    0x00800000L
#define DISP_HW_DEBUG__DISP_HW_18_DEBUG_MASK               0x01000000L
#define DISP_HW_DEBUG__DISP_HW_18_DEBUG                    0x01000000L
#define DISP_HW_DEBUG__DISP_HW_19_DEBUG_MASK               0x02000000L
#define DISP_HW_DEBUG__DISP_HW_19_DEBUG                    0x02000000L
#define DISP_HW_DEBUG__DISP_HW_1A_DEBUG_MASK               0x04000000L
#define DISP_HW_DEBUG__DISP_HW_1A_DEBUG                    0x04000000L
#define DISP_HW_DEBUG__DISP_HW_1B_DEBUG_MASK               0x08000000L
#define DISP_HW_DEBUG__DISP_HW_1B_DEBUG                    0x08000000L
#define DISP_HW_DEBUG__DISP_HW_1C_DEBUG_MASK               0x10000000L
#define DISP_HW_DEBUG__DISP_HW_1C_DEBUG                    0x10000000L
#define DISP_HW_DEBUG__DISP_HW_1D_DEBUG_MASK               0x20000000L
#define DISP_HW_DEBUG__DISP_HW_1D_DEBUG                    0x20000000L
#define DISP_HW_DEBUG__DISP_HW_1E_DEBUG_MASK               0x40000000L
#define DISP_HW_DEBUG__DISP_HW_1E_DEBUG                    0x40000000L
#define DISP_HW_DEBUG__DISP_HW_1F_DEBUG_MASK               0x80000000L
#define DISP_HW_DEBUG__DISP_HW_1F_DEBUG                    0x80000000L

// DAC_CRC_SIG1
#define DAC_CRC_SIG1__DAC_CRC_SIG_B_MASK                   0x000003ffL
#define DAC_CRC_SIG1__DAC_CRC_SIG_G_MASK                   0x03ff0000L

// DAC_CRC_SIG2
#define DAC_CRC_SIG2__DAC_CRC_SIG_R_MASK                   0x000003ffL
#define DAC_CRC_SIG2__DAC_CRC_SIG_C_MASK                   0x003f0000L

// OV0_LIN_TRANS_A_M6
#define OV0_LIN_TRANS_A_M6__OV0_LIN_TRANS_Cb_R_MASK        0x0000fff0L
#define OV0_LIN_TRANS_A_M6__OV0_LIN_TRANS_Y_R_MASK         0xfff00000L

// OV0_LIN_TRANS_B_M6
#define OV0_LIN_TRANS_B_M6__OV0_LIN_TRANS_OFF_R_MASK       0x00001fffL
#define OV0_LIN_TRANS_B_M6__OV0_LIN_TRANS_Cr_R_MASK        0xfff00000L

// OV0_LIN_TRANS_C_M6
#define OV0_LIN_TRANS_C_M6__OV0_LIN_TRANS_Cb_G_MASK        0x0000fff0L
#define OV0_LIN_TRANS_C_M6__OV0_LIN_TRANS_Y_G_MASK         0xfff00000L

// OV0_LIN_TRANS_D_M6
#define OV0_LIN_TRANS_D_M6__OV0_LIN_TRANS_OFF_G_MASK       0x00001fffL
#define OV0_LIN_TRANS_D_M6__OV0_LIN_TRANS_Cr_G_MASK        0xfff00000L

// OV0_LIN_TRANS_E_M6
#define OV0_LIN_TRANS_E_M6__OV0_LIN_TRANS_Cb_B_MASK        0x0000fff0L
#define OV0_LIN_TRANS_E_M6__OV0_LIN_TRANS_Y_B_MASK         0xfff00000L

// OV0_LIN_TRANS_F_M6
#define OV0_LIN_TRANS_F_M6__OV0_LIN_TRANS_OFF_B_MASK       0x00001fffL
#define OV0_LIN_TRANS_F_M6__OV0_LIN_TRANS_Cr_B_MASK        0xfff00000L

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

// CLOCK_CNTL_INDEX_M6
#define CLOCK_CNTL_INDEX_M6__PLL_ADDR_MASK                 0x0000003fL
#define CLOCK_CNTL_INDEX_M6__PLL_WR_EN_MASK                0x00000080L
#define CLOCK_CNTL_INDEX_M6__PLL_WR_EN                     0x00000080L
#define CLOCK_CNTL_INDEX_M6__PPLL_DIV_SEL_MASK             0x00000300L

// CLOCK_CNTL_DATA
#define CLOCK_CNTL_DATA__PLL_DATA_MASK                     0xffffffffL

// PPLL_DIV_0
#define PPLL_DIV_0__PPLL_FB0_DIV_MASK                      0x000007ffL
#define PPLL_DIV_0__PPLL_ATOMIC_UPDATE_W_MASK              0x00008000L
#define PPLL_DIV_0__PPLL_ATOMIC_UPDATE_W                   0x00008000L
#define PPLL_DIV_0__PPLL_ATOMIC_UPDATE_R_MASK              0x00008000L
#define PPLL_DIV_0__PPLL_ATOMIC_UPDATE_R                   0x00008000L
#define PPLL_DIV_0__PPLL_POST0_DIV_MASK                    0x00070000L

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

// PLL_TEST_CNTL_M6
#define PLL_TEST_CNTL_M6__TST_SRC_SEL_MASK                 0x0000007fL
#define PLL_TEST_CNTL_M6__TST_SRC_INV_MASK                 0x00000080L
#define PLL_TEST_CNTL_M6__TST_SRC_INV                      0x00000080L
#define PLL_TEST_CNTL_M6__TST_DIVIDERS_MASK                0x00000100L
#define PLL_TEST_CNTL_M6__TST_DIVIDERS                     0x00000100L
#define PLL_TEST_CNTL_M6__PLL_MASK_READ_B_MASK             0x00000200L
#define PLL_TEST_CNTL_M6__PLL_MASK_READ_B                  0x00000200L
#define PLL_TEST_CNTL_M6__TESTCLK_MUX_SEL_MASK             0x00001000L
#define PLL_TEST_CNTL_M6__TESTCLK_MUX_SEL                  0x00001000L
#define PLL_TEST_CNTL_M6__ANALOG_MON_MASK                  0x00ff8000L
#define PLL_TEST_CNTL_M6__TEST_COUNT_MASK                  0xff000000L

// P2PLL_DIV_0
#define P2PLL_DIV_0__P2PLL_FB_DIV_MASK                     0x000007ffL
#define P2PLL_DIV_0__P2PLL_ATOMIC_UPDATE_W_MASK            0x00008000L
#define P2PLL_DIV_0__P2PLL_ATOMIC_UPDATE_W                 0x00008000L
#define P2PLL_DIV_0__P2PLL_ATOMIC_UPDATE_R_MASK            0x00008000L
#define P2PLL_DIV_0__P2PLL_ATOMIC_UPDATE_R                 0x00008000L
#define P2PLL_DIV_0__P2PLL_POST_DIV_MASK                   0x00070000L

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

// CP_RB_CNTL
#define CP_RB_CNTL__RB_BUFSZ_MASK                          0x0000003fL
#define CP_RB_CNTL__RB_BLKSZ_MASK                          0x00003f00L
#define CP_RB_CNTL__BUF_SWAP_MASK                          0x00030000L
#define CP_RB_CNTL__MAX_FETCH_MASK                         0x000c0000L
#define CP_RB_CNTL__RB_NO_UPDATE_MASK                      0x08000000L
#define CP_RB_CNTL__RB_NO_UPDATE                           0x08000000L
#define CP_RB_CNTL__RB_RPTR_WR_ENA_MASK                    0x80000000L
#define CP_RB_CNTL__RB_RPTR_WR_ENA                         0x80000000L

// CP_RB_BASE
#define CP_RB_BASE__RB_BASE_MASK                           0xfffffffcL

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

// CP_CSQ_CNTL
#define CP_CSQ_CNTL__CSQ_CNT_PRIMARY_MASK                  0x000000ffL
#define CP_CSQ_CNTL__CSQ_CNT_INDIRECT_MASK                 0x0000ff00L
#define CP_CSQ_CNTL__CSQ_MODE_MASK                         0xf0000000L

// CP_CSQ_APER_PRIMARY
#define CP_CSQ_APER_PRIMARY__CP_CSQ_APER_PRIMARY_MASK      0xffffffffL

// CP_CSQ_APER_INDIRECT
#define CP_CSQ_APER_INDIRECT__CP_CSQ_APER_INDIRECT_MASK    0xffffffffL

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

// SCRATCH_REG1
#define SCRATCH_REG1__SCRATCH_REG1_MASK                    0xffffffffL

// SCRATCH_REG2
#define SCRATCH_REG2__SCRATCH_REG2_MASK                    0xffffffffL

// SCRATCH_REG3
#define SCRATCH_REG3__SCRATCH_REG3_MASK                    0xffffffffL

// SCRATCH_REG4
#define SCRATCH_REG4__SCRATCH_REG4_MASK                    0xffffffffL

// SCRATCH_REG5
#define SCRATCH_REG5__SCRATCH_REG5_MASK                    0xffffffffL

// SCRATCH_UMSK
#define SCRATCH_UMSK__SCRATCH_UMSK_MASK                    0x0000003fL
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

// CP_CSQ_ADDR
#define CP_CSQ_ADDR__CSQ_ADDR_MASK                         0x000003fcL

// CP_CSQ_DATA
#define CP_CSQ_DATA__CSQ_DATA_MASK                         0xffffffffL

// CP_CSQ_STAT
#define CP_CSQ_STAT__CSQ_RPTR_PRIMARY_MASK                 0x000000ffL
#define CP_CSQ_STAT__CSQ_WPTR_PRIMARY_MASK                 0x0000ff00L
#define CP_CSQ_STAT__CSQ_RPTR_INDIRECT_MASK                0x00ff0000L
#define CP_CSQ_STAT__CSQ_WPTR_INDIRECT_MASK                0xff000000L

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

// SE_VTX_FMT
#define SE_VTX_FMT__VTX_W0_PRESENT_MASK                    0x00000001L
#define SE_VTX_FMT__VTX_W0_PRESENT                         0x00000001L
#define SE_VTX_FMT__VTX_FPCOLOR_PRESENT_MASK               0x00000002L
#define SE_VTX_FMT__VTX_FPCOLOR_PRESENT                    0x00000002L
#define SE_VTX_FMT__VTX_FPALPHA_PRESENT_MASK               0x00000004L
#define SE_VTX_FMT__VTX_FPALPHA_PRESENT                    0x00000004L
#define SE_VTX_FMT__VTX_PKCOLOR_PRESENT_MASK               0x00000008L
#define SE_VTX_FMT__VTX_PKCOLOR_PRESENT                    0x00000008L
#define SE_VTX_FMT__VTX_FPSPEC_PRESENT_MASK                0x00000010L
#define SE_VTX_FMT__VTX_FPSPEC_PRESENT                     0x00000010L
#define SE_VTX_FMT__VTX_FPFOG_PRESENT_MASK                 0x00000020L
#define SE_VTX_FMT__VTX_FPFOG_PRESENT                      0x00000020L
#define SE_VTX_FMT__VTX_PKSPEC_PRESENT_MASK                0x00000040L
#define SE_VTX_FMT__VTX_PKSPEC_PRESENT                     0x00000040L
#define SE_VTX_FMT__VTX_ST0_PRESENT_MASK                   0x00000080L
#define SE_VTX_FMT__VTX_ST0_PRESENT                        0x00000080L
#define SE_VTX_FMT__VTX_ST1_PRESENT_MASK                   0x00000100L
#define SE_VTX_FMT__VTX_ST1_PRESENT                        0x00000100L
#define SE_VTX_FMT__VTX_Q1_PRESENT_MASK                    0x00000200L
#define SE_VTX_FMT__VTX_Q1_PRESENT                         0x00000200L
#define SE_VTX_FMT__VTX_ST2_PRESENT_MASK                   0x00000400L
#define SE_VTX_FMT__VTX_ST2_PRESENT                        0x00000400L
#define SE_VTX_FMT__VTX_Q2_PRESENT_MASK                    0x00000800L
#define SE_VTX_FMT__VTX_Q2_PRESENT                         0x00000800L
#define SE_VTX_FMT__VTX_ST3_PRESENT_MASK                   0x00001000L
#define SE_VTX_FMT__VTX_ST3_PRESENT                        0x00001000L
#define SE_VTX_FMT__VTX_Q3_PRESENT_MASK                    0x00002000L
#define SE_VTX_FMT__VTX_Q3_PRESENT                         0x00002000L
#define SE_VTX_FMT__VTX_Q0_PRESENT_MASK                    0x00004000L
#define SE_VTX_FMT__VTX_Q0_PRESENT                         0x00004000L
#define SE_VTX_FMT__VTX_BLND_WEIGHT_CNT_MASK               0x00038000L
#define SE_VTX_FMT__VTX_N0_PRESENT_MASK                    0x00040000L
#define SE_VTX_FMT__VTX_N0_PRESENT                         0x00040000L
#define SE_VTX_FMT__VTX_XY1_PRESENT_MASK                   0x08000000L
#define SE_VTX_FMT__VTX_XY1_PRESENT                        0x08000000L
#define SE_VTX_FMT__VTX_Z1_PRESENT_MASK                    0x10000000L
#define SE_VTX_FMT__VTX_Z1_PRESENT                         0x10000000L
#define SE_VTX_FMT__VTX_W1_PRESENT_MASK                    0x20000000L
#define SE_VTX_FMT__VTX_W1_PRESENT                         0x20000000L
#define SE_VTX_FMT__VTX_N1_PRESENT_MASK                    0x40000000L
#define SE_VTX_FMT__VTX_N1_PRESENT                         0x40000000L
#define SE_VTX_FMT__VTX_Z_PRESENT_MASK                     0x80000000L
#define SE_VTX_FMT__VTX_Z_PRESENT                          0x80000000L

// SE_VF_CNTL
#define SE_VF_CNTL__PRIM_TYPE_MASK                         0x0000000fL
#define SE_VF_CNTL__PRIM_WALK_MASK                         0x00000030L
#define SE_VF_CNTL__COLOR_ORDER_MASK                       0x00000040L
#define SE_VF_CNTL__COLOR_ORDER                            0x00000040L
#define SE_VF_CNTL__EN_MAOS_MASK                           0x00000080L
#define SE_VF_CNTL__EN_MAOS                                0x00000080L
#define SE_VF_CNTL__VTX_FMT_MODE_MASK                      0x00000100L
#define SE_VF_CNTL__VTX_FMT_MODE                           0x00000100L
#define SE_VF_CNTL__TCL_ENABLE_MASK                        0x00000200L
#define SE_VF_CNTL__TCL_ENABLE                             0x00000200L
#define SE_VF_CNTL__NUM_VERTICES_MASK                      0xffff0000L

// SE_CNTL
#define SE_CNTL__FFACE_CULL_DIR_MASK                       0x00000001L
#define SE_CNTL__FFACE_CULL_DIR                            0x00000001L
#define SE_CNTL__BFACE_CULL_FCN_MASK                       0x00000006L
#define SE_CNTL__FFACE_CULL_FCN_MASK                       0x00000018L
#define SE_CNTL__BADVTX_CULL_DISABLE_MASK                  0x00000020L
#define SE_CNTL__BADVTX_CULL_DISABLE                       0x00000020L
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
#define SE_CNTL__VPORT_XY_XFEN_MASK                        0x01000000L
#define SE_CNTL__VPORT_XY_XFEN                             0x01000000L
#define SE_CNTL__VPORT_Z_XFEN_MASK                         0x02000000L
#define SE_CNTL__VPORT_Z_XFEN                              0x02000000L
#define SE_CNTL__VTX_PIXCENTER_MASK                        0x08000000L
#define SE_CNTL__VTX_PIXCENTER                             0x08000000L
#define SE_CNTL__ROUND_MODE_MASK                           0x30000000L
#define SE_CNTL__ROUND_PRECISION_MASK                      0xc0000000L

// SE_COORD_FMT
#define SE_COORD_FMT__VTX_XY_FMT_MASK                      0x00000001L
#define SE_COORD_FMT__VTX_XY_FMT                           0x00000001L
#define SE_COORD_FMT__VTX_Z_FMT_MASK                       0x00000002L
#define SE_COORD_FMT__VTX_Z_FMT                            0x00000002L
#define SE_COORD_FMT__VTX_ST0_NONPARAMETRIC_MASK           0x00000100L
#define SE_COORD_FMT__VTX_ST0_NONPARAMETRIC                0x00000100L
#define SE_COORD_FMT__VTX_ST1_NONPARAMETRIC_MASK           0x00000200L
#define SE_COORD_FMT__VTX_ST1_NONPARAMETRIC                0x00000200L
#define SE_COORD_FMT__VTX_ST2_NONPARAMETRIC_MASK           0x00000400L
#define SE_COORD_FMT__VTX_ST2_NONPARAMETRIC                0x00000400L
#define SE_COORD_FMT__VTX_ST3_NONPARAMETRIC_MASK           0x00000800L
#define SE_COORD_FMT__VTX_ST3_NONPARAMETRIC                0x00000800L
#define SE_COORD_FMT__VTX_W0_NORMALIZE_MASK                0x00001000L
#define SE_COORD_FMT__VTX_W0_NORMALIZE                     0x00001000L
#define SE_COORD_FMT__VTX_W0_FMT_MASK                      0x00010000L
#define SE_COORD_FMT__VTX_W0_FMT                           0x00010000L
#define SE_COORD_FMT__VTX_ST0_FMT_MASK                     0x00020000L
#define SE_COORD_FMT__VTX_ST0_FMT                          0x00020000L
#define SE_COORD_FMT__VTX_ST1_FMT_MASK                     0x00080000L
#define SE_COORD_FMT__VTX_ST1_FMT                          0x00080000L
#define SE_COORD_FMT__VTX_ST2_FMT_MASK                     0x00200000L
#define SE_COORD_FMT__VTX_ST2_FMT                          0x00200000L
#define SE_COORD_FMT__VTX_ST3_FMT_MASK                     0x00800000L
#define SE_COORD_FMT__VTX_ST3_FMT                          0x00800000L
#define SE_COORD_FMT__TEX1_W_ROUTING_MASK                  0x04000000L
#define SE_COORD_FMT__TEX1_W_ROUTING                       0x04000000L

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

// SE_ZBIAS_FACTOR
#define SE_ZBIAS_FACTOR__ZBIAS_FACTOR_MASK                 0xffffffffL

// SE_ZBIAS_CONSTANT
#define SE_ZBIAS_CONSTANT__ZBIAS_CONSTANT_MASK             0xffffffffL

// SE_LINE_WIDTH
#define SE_LINE_WIDTH__LINE_WIDTH_MASK                     0x000003ffL

// SE_W0_RANGE
#define SE_W0_RANGE__W0_RANGE_MASK                         0xffffffffL

// SE_VTX_NUM_ARRAYS
#define SE_VTX_NUM_ARRAYS__VTX_NUM_ARRAYS_MASK             0x0000001fL
#define SE_VTX_NUM_ARRAYS__VC_PFETCH_MASK                  0x0000c000L

// SE_VTX_AOS_ATTR01
#define SE_VTX_AOS_ATTR01__VTX_AOS_COUNT0_MASK             0x0000003fL
#define SE_VTX_AOS_ATTR01__VTX_AOS_STRIDE0_MASK            0x00003f00L
#define SE_VTX_AOS_ATTR01__VTX_AOS_COUNT1_MASK             0x003f0000L
#define SE_VTX_AOS_ATTR01__VTX_AOS_STRIDE1_MASK            0x3f000000L

// SE_VTX_AOS_ADDR0
#define SE_VTX_AOS_ADDR0__VTX_AOS_ADDR0_MASK               0xfffffffcL

// SE_VTX_AOS_ADDR1
#define SE_VTX_AOS_ADDR1__VTX_AOS_ADDR1_MASK               0xfffffffcL

// SE_VTX_AOS_ATTR23
#define SE_VTX_AOS_ATTR23__VTX_AOS_COUNT2_MASK             0x0000003fL
#define SE_VTX_AOS_ATTR23__VTX_AOS_STRIDE2_MASK            0x00003f00L
#define SE_VTX_AOS_ATTR23__VTX_AOS_COUNT3_MASK             0x003f0000L
#define SE_VTX_AOS_ATTR23__VTX_AOS_STRIDE3_MASK            0x3f000000L

// SE_VTX_AOS_ADDR2
#define SE_VTX_AOS_ADDR2__VTX_AOS_ADDR2_MASK               0xfffffffcL

// SE_VTX_AOS_ADDR3
#define SE_VTX_AOS_ADDR3__VTX_AOS_ADDR3_MASK               0xfffffffcL

// SE_VTX_AOS_ATTR45
#define SE_VTX_AOS_ATTR45__VTX_AOS_COUNT4_MASK             0x0000003fL
#define SE_VTX_AOS_ATTR45__VTX_AOS_STRIDE4_MASK            0x00003f00L
#define SE_VTX_AOS_ATTR45__VTX_AOS_COUNT5_MASK             0x003f0000L
#define SE_VTX_AOS_ATTR45__VTX_AOS_STRIDE5_MASK            0x3f000000L

// SE_VTX_AOS_ADDR4
#define SE_VTX_AOS_ADDR4__VTX_AOS_ADDR4_MASK               0xfffffffcL

// SE_VTX_AOS_ADDR5
#define SE_VTX_AOS_ADDR5__VTX_AOS_ADDR5_MASK               0xfffffffcL

// SE_VTX_AOS_ATTR67
#define SE_VTX_AOS_ATTR67__VTX_AOS_COUNT6_MASK             0x0000003fL
#define SE_VTX_AOS_ATTR67__VTX_AOS_STRIDE6_MASK            0x00003f00L
#define SE_VTX_AOS_ATTR67__VTX_AOS_COUNT7_MASK             0x003f0000L
#define SE_VTX_AOS_ATTR67__VTX_AOS_STRIDE7_MASK            0x3f000000L

// SE_VTX_AOS_ADDR6
#define SE_VTX_AOS_ADDR6__VTX_AOS_ADDR6_MASK               0xfffffffcL

// SE_VTX_AOS_ADDR7
#define SE_VTX_AOS_ADDR7__VTX_AOS_ADDR7_MASK               0xfffffffcL

// SE_VTX_AOS_ATTR89
#define SE_VTX_AOS_ATTR89__VTX_AOS_COUNT8_MASK             0x0000003fL
#define SE_VTX_AOS_ATTR89__VTX_AOS_STRIDE8_MASK            0x00003f00L
#define SE_VTX_AOS_ATTR89__VTX_AOS_COUNT9_MASK             0x003f0000L
#define SE_VTX_AOS_ATTR89__VTX_AOS_STRIDE9_MASK            0x3f000000L

// SE_VTX_AOS_ADDR8
#define SE_VTX_AOS_ADDR8__VTX_AOS_ADDR8_MASK               0xfffffffcL

// SE_VTX_AOS_ADDR9
#define SE_VTX_AOS_ADDR9__VTX_AOS_ADDR9_MASK               0xfffffffcL

// SE_VTX_AOS_ATTR1011
#define SE_VTX_AOS_ATTR1011__VTX_AOS_COUNT10_MASK          0x0000003fL
#define SE_VTX_AOS_ATTR1011__VTX_AOS_STRIDE10_MASK         0x00003f00L
#define SE_VTX_AOS_ATTR1011__VTX_AOS_COUNT11_MASK          0x003f0000L
#define SE_VTX_AOS_ATTR1011__VTX_AOS_STRIDE11_MASK         0x3f000000L

// SE_VTX_AOS_ADDR10
#define SE_VTX_AOS_ADDR10__VTX_AOS_ADDR10_MASK             0xfffffffcL

// SE_VTX_AOS_ADDR11
#define SE_VTX_AOS_ADDR11__VTX_AOS_ADDR11_MASK             0xfffffffcL

// SE_PERF_CNTL
#define SE_PERF_CNTL__PERFSEL1_MASK                        0x0000000fL
#define SE_PERF_CNTL__CLR_PERF1_MASK                       0x00000040L
#define SE_PERF_CNTL__CLR_PERF1                            0x00000040L
#define SE_PERF_CNTL__EN_PERF1_MASK                        0x00000080L
#define SE_PERF_CNTL__EN_PERF1                             0x00000080L
#define SE_PERF_CNTL__PERFSEL2_MASK                        0x00000f00L
#define SE_PERF_CNTL__CLR_PERF2_MASK                       0x00004000L
#define SE_PERF_CNTL__CLR_PERF2                            0x00004000L
#define SE_PERF_CNTL__EN_PERF2_MASK                        0x00008000L
#define SE_PERF_CNTL__EN_PERF2                             0x00008000L

// SE_PERF_COUNT1
#define SE_PERF_COUNT1__PERF_COUNT1_MASK                   0xffffffffL

// SE_PERF_COUNT2
#define SE_PERF_COUNT2__PERF_COUNT2_MASK                   0xffffffffL

// SE_DEBUG
#define SE_DEBUG__SE_DEBUG_MASK                            0xffffffffL

// SE_CNTL_STATUS
#define SE_CNTL_STATUS__VC_SWAP_MASK                       0x00000003L
#define SE_CNTL_STATUS__SINGLESTEP_MASK                    0x00000040L
#define SE_CNTL_STATUS__SINGLESTEP                         0x00000040L
#define SE_CNTL_STATUS__EN_SINGLESTEP_MASK                 0x00000080L
#define SE_CNTL_STATUS__EN_SINGLESTEP                      0x00000080L
#define SE_CNTL_STATUS__TCL_BYPASS_MASK                    0x00000100L
#define SE_CNTL_STATUS__TCL_BYPASS                         0x00000100L
#define SE_CNTL_STATUS__TCL_BUSY_MASK                      0x00000800L
#define SE_CNTL_STATUS__TCL_BUSY                           0x00000800L
#define SE_CNTL_STATUS__BADVTX_DETECTED_MASK               0x00008000L
#define SE_CNTL_STATUS__BADVTX_DETECTED                    0x00008000L
#define SE_CNTL_STATUS__PERF_BUSY_MASK                     0x00010000L
#define SE_CNTL_STATUS__PERF_BUSY                          0x00010000L
#define SE_CNTL_STATUS__MCSE_BUSY_MASK                     0x00020000L
#define SE_CNTL_STATUS__MCSE_BUSY                          0x00020000L
#define SE_CNTL_STATUS__REIU_BUSY_MASK                     0x00040000L
#define SE_CNTL_STATUS__REIU_BUSY                          0x00040000L
#define SE_CNTL_STATUS__LSUB_BUSY_MASK                     0x00080000L
#define SE_CNTL_STATUS__LSUB_BUSY                          0x00080000L
#define SE_CNTL_STATUS__PSUB_BUSY_MASK                     0x00100000L
#define SE_CNTL_STATUS__PSUB_BUSY                          0x00100000L
#define SE_CNTL_STATUS__LE_BUSY_MASK                       0x00200000L
#define SE_CNTL_STATUS__LE_BUSY                            0x00200000L
#define SE_CNTL_STATUS__PE_BUSY_MASK                       0x00400000L
#define SE_CNTL_STATUS__PE_BUSY                            0x00400000L
#define SE_CNTL_STATUS__EE_BUSY_MASK                       0x00800000L
#define SE_CNTL_STATUS__EE_BUSY                            0x00800000L
#define SE_CNTL_STATUS__VS_BUSY_MASK                       0x01000000L
#define SE_CNTL_STATUS__VS_BUSY                            0x01000000L
#define SE_CNTL_STATUS__RE_BUSY_MASK                       0x02000000L
#define SE_CNTL_STATUS__RE_BUSY                            0x02000000L
#define SE_CNTL_STATUS__XE_BUSY_MASK                       0x04000000L
#define SE_CNTL_STATUS__XE_BUSY                            0x04000000L
#define SE_CNTL_STATUS__MIU_BUSY_MASK                      0x08000000L
#define SE_CNTL_STATUS__MIU_BUSY                           0x08000000L
#define SE_CNTL_STATUS__VC_BUSY_MASK                       0x10000000L
#define SE_CNTL_STATUS__VC_BUSY                            0x10000000L
#define SE_CNTL_STATUS__VF_BUSY_MASK                       0x20000000L
#define SE_CNTL_STATUS__VF_BUSY                            0x20000000L
#define SE_CNTL_STATUS__REGPIPE_BUSY_MASK                  0x40000000L
#define SE_CNTL_STATUS__REGPIPE_BUSY                       0x40000000L
#define SE_CNTL_STATUS__SE_BUSY_MASK                       0x80000000L
#define SE_CNTL_STATUS__SE_BUSY                            0x80000000L

// SE_SERE_WCNTL
#define SE_SERE_WCNTL__SERE_WA0_MASK                       0x000003fcL
#define SE_SERE_WCNTL__SERE_BLKID0_MASK                    0x00003000L
#define SE_SERE_WCNTL__SERE_VALID0_MASK                    0x00004000L
#define SE_SERE_WCNTL__SERE_VALID0                         0x00004000L
#define SE_SERE_WCNTL__SERE_WA1_MASK                       0x03fc0000L
#define SE_SERE_WCNTL__SERE_VALID1_MASK                    0x40000000L
#define SE_SERE_WCNTL__SERE_VALID1                         0x40000000L
#define SE_SERE_WCNTL__SERE_RTS_MASK                       0x80000000L
#define SE_SERE_WCNTL__SERE_RTS                            0x80000000L

// SE_SERE_WD0_0
#define SE_SERE_WD0_0__SERE_WD0_0_MASK                     0xffffffffL

// SE_SERE_WD0_1
#define SE_SERE_WD0_1__SERE_WD0_1_MASK                     0xffffffffL

// SE_SERE_WD0_2
#define SE_SERE_WD0_2__SERE_WD0_2_MASK                     0xffffffffL

// SE_SERE_WD0_3
#define SE_SERE_WD0_3__SERE_WD0_3_MASK                     0xffffffffL

// SE_SERE_WD1_0
#define SE_SERE_WD1_0__SERE_WD1_0_MASK                     0xffffffffL

// SE_SERE_WD1_1
#define SE_SERE_WD1_1__SERE_WD1_1_MASK                     0xffffffffL

// SE_SERE_WD1_2
#define SE_SERE_WD1_2__SERE_WD1_2_MASK                     0xffffffffL

// SE_SERE_WD1_3
#define SE_SERE_WD1_3__SERE_WD1_3_MASK                     0xffffffffL

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

// RE_STIPPLE_ADDR
#define RE_STIPPLE_ADDR__STIPPLE_ADDR_MASK                 0x0000001fL

// RE_STIPPLE_DATA
#define RE_STIPPLE_DATA__STIPPLE_DATA_MASK                 0xffffffffL

// RE_MISC
#define RE_MISC__STIPPLE_X_OFFSET_MASK                     0x0000001fL
#define RE_MISC__STIPPLE_Y_OFFSET_MASK                     0x00001f00L
#define RE_MISC__STIPPLE_BIT_ORDER_MASK                    0x00010000L
#define RE_MISC__STIPPLE_BIT_ORDER                         0x00010000L

// RE_SOLID_COLOR
#define RE_SOLID_COLOR__SOLID_COLOR_MASK                   0xffffffffL

// RE_WIDTH_HEIGHT
#define RE_WIDTH_HEIGHT__WIDTH_MASK                        0x000007ffL
#define RE_WIDTH_HEIGHT__HEIGHT_MASK                       0x07ff0000L

// RE_TOP_LEFT
#define RE_TOP_LEFT__X_LEFT_MASK                           0x000007ffL
#define RE_TOP_LEFT__Y_TOP_MASK                            0x07ff0000L

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

// RE_PIX_COUNT
#define RE_PIX_COUNT__RE_PIX_COUNT_MASK                    0xffffffffL

// RE_PAIR_COUNT
#define RE_PAIR_COUNT__RE_PAIR_COUNT_MASK                  0xffffffffL

// RE_CYC_COUNT
#define RE_CYC_COUNT__RE_CYC_COUNT_MASK                    0xffffffffL

// RE_OUTSIDE
#define RE_OUTSIDE__RE_OUTSIDE_MASK                        0xffffffffL

// RE_STALLED
#define RE_STALLED__RE_STALLED_MASK                        0xffffffffL

// RE_PERF
#define RE_PERF__BLOCK_DISABLE_MASK                        0x00000010L
#define RE_PERF__BLOCK_DISABLE                             0x00000010L
#define RE_PERF__DUAL_PIXEL_DISABLE_MASK                   0x00000020L
#define RE_PERF__DUAL_PIXEL_DISABLE                        0x00000020L
#define RE_PERF__HIEARCHICAL_Z_OVERRIDE_MASK               0x00000040L
#define RE_PERF__HIEARCHICAL_Z_OVERRIDE                    0x00000040L

// RE_DEBUG_0
#define RE_DEBUG_0__RE_DWORD_MASK                          0xffffffffL

// RE_DEBUG_1
#define RE_DEBUG_1__RE_DWORD_MASK                          0xffffffffL

// RE_DEBUG_2
#define RE_DEBUG_2__RE_DWORD_MASK                          0xffffffffL

// RE_DEBUG_3
#define RE_DEBUG_3__RE_DWORD_MASK                          0xffffffffL

// RE_DEBUG_4
#define RE_DEBUG_4__RE_DWORD_MASK                          0xffffffffL

// RE_DEBUG_5
#define RE_DEBUG_5__RE_DWORD_MASK                          0xffffffffL

// RE_DEBUG_6
#define RE_DEBUG_6__RE_DWORD_MASK                          0xffffffffL

// RE_DEBUG_7
#define RE_DEBUG_7__RE_DWORD_MASK                          0xffffffffL

// RE_E2_0
#define RE_E2_0__XSTART_MASK                               0x00000fffL
#define RE_E2_0__YSTART_MASK                               0x00fff000L
#define RE_E2_0__XEND_LO_MASK                              0xff000000L

// RE_E2_1
#define RE_E2_1__XEND_HI_MASK                              0x0000000fL
#define RE_E2_1__YEND_MASK                                 0x0000fff0L
#define RE_E2_1__XDIR_MASK                                 0x00010000L
#define RE_E2_1__XDIR                                      0x00010000L
#define RE_E2_1__YDIR_MASK                                 0x00020000L
#define RE_E2_1__YDIR                                      0x00020000L
#define RE_E2_1__XMAJ_MASK                                 0x00040000L
#define RE_E2_1__XMAJ                                      0x00040000L
#define RE_E2_1__XOFFSET_MASK                              0x00f80000L
#define RE_E2_1__OPCODE_MASK                               0x03000000L
#define RE_E2_1__SUB_PRIM_MASK                             0x08000000L
#define RE_E2_1__SUB_PRIM                                  0x08000000L
#define RE_E2_1__END_PATTERN_MASK                          0x10000000L
#define RE_E2_1__END_PATTERN                               0x10000000L
#define RE_E2_1__DYE2_LO_MASK                              0xe0000000L

// RE_E2_2
#define RE_E2_2__DYE2_HI_MASK                              0x00003fffL
#define RE_E2_2__DXE2_MASK                                 0x7fffc000L
#define RE_E2_2__E2_LO_MASK                                0x80000000L
#define RE_E2_2__E2_LO                                     0x80000000L

// RE_E2_3
#define RE_E2_3__E2_HI_MASK                                0xffffffffL

// RE_E0E1_0
#define RE_E0E1_0__DYE1_MASK                               0x0001ffffL
#define RE_E0E1_0__DXE1_LO_MASK                            0xfffe0000L

// RE_E0E1_1
#define RE_E0E1_1__DXE1_HI_MASK                            0x00000003L
#define RE_E0E1_1__E1_MASK                                 0xfffffffcL

// RE_E0E1_2
#define RE_E0E1_2__DYE0_MASK                               0x0001ffffL
#define RE_E0E1_2__DXE0_LO_MASK                            0xfffe0000L

// RE_E0E1_3
#define RE_E0E1_3__DXE0_HI_MASK                            0x00000003L
#define RE_E0E1_3__E0_MASK                                 0xfffffffcL

// RE_NULL_PRIM

// RE_Z_MINMAX_0
#define RE_Z_MINMAX_0__Z_MINMAX_LO_MASK                    0xffffffffL

// RE_Z_MINMAX_1
#define RE_Z_MINMAX_1__Z_MINMAX_HI_MASK                    0x000001ffL

// RE_Z_MINMAX_3
#define RE_Z_MINMAX_3__ZEXPO_MASK                          0xff000000L

// RE_DDA_Z_0
#define RE_DDA_Z_0__ZSTART_LO_MASK                         0xffffffffL

// RE_DDA_Z_1
#define RE_DDA_Z_1__ZSTART_H_MASK                          0x000001ffL
#define RE_DDA_Z_1__DZDX_L_MASK                            0xfffffe00L

// RE_DDA_Z_2
#define RE_DDA_Z_2__DZDX_H_MASK                            0x0000ffffL
#define RE_DDA_Z_2__DZDY_L_MASK                            0xffff0000L

// RE_DDA_Z_3
#define RE_DDA_Z_3__DZDY_H_MASK                            0x007fffffL
#define RE_DDA_Z_3__ZEXPO_MASK                             0xff000000L

// RE_DDA_RHW_0
#define RE_DDA_RHW_0__RHWSTART_LO_MASK                     0xffffffffL

// RE_DDA_RHW_1
#define RE_DDA_RHW_1__RHWSTART_H_MASK                      0x000001ffL
#define RE_DDA_RHW_1__DRHWDX_L_MASK                        0xfffffe00L

// RE_DDA_RHW_2
#define RE_DDA_RHW_2__DRHWDX_H_MASK                        0x0000ffffL
#define RE_DDA_RHW_2__DRHWDY_L_MASK                        0xffff0000L

// RE_DDA_RHW_3
#define RE_DDA_RHW_3__DRHWDY_H_MASK                        0x007fffffL
#define RE_DDA_RHW_3__RHWEXPO_MASK                         0xff000000L

// RE_DDA_A_0
#define RE_DDA_A_0__ASTART_MASK                            0x01ffffffL

// RE_DDA_A_1
#define RE_DDA_A_1__DADX_MASK                              0x01ffffffL

// RE_DDA_A_2
#define RE_DDA_A_2__DADY_MASK                              0x01ffffffL

// RE_DDA_R_0
#define RE_DDA_R_0__RSTART_MASK                            0x01ffffffL

// RE_DDA_R_1
#define RE_DDA_R_1__DRDX_MASK                              0x01ffffffL

// RE_DDA_R_2
#define RE_DDA_R_2__DRDY_MASK                              0x01ffffffL

// RE_DDA_G_0
#define RE_DDA_G_0__GSTART_MASK                            0x01ffffffL

// RE_DDA_G_1
#define RE_DDA_G_1__DGDX_MASK                              0x01ffffffL

// RE_DDA_G_2
#define RE_DDA_G_2__DGDY_MASK                              0x01ffffffL

// RE_DDA_B_0
#define RE_DDA_B_0__BSTART_MASK                            0x01ffffffL

// RE_DDA_B_1
#define RE_DDA_B_1__DBDX_MASK                              0x01ffffffL

// RE_DDA_B_2
#define RE_DDA_B_2__DBDY_MASK                              0x01ffffffL

// RE_DDA_SA_0
#define RE_DDA_SA_0__SASTART_MASK                          0x01ffffffL

// RE_DDA_SA_1
#define RE_DDA_SA_1__DSADX_MASK                            0x01ffffffL

// RE_DDA_SA_2
#define RE_DDA_SA_2__DSADY_MASK                            0x01ffffffL

// RE_DDA_SR_0
#define RE_DDA_SR_0__SRSTART_MASK                          0x01ffffffL

// RE_DDA_SR_1
#define RE_DDA_SR_1__DSRDX_MASK                            0x01ffffffL

// RE_DDA_SR_2
#define RE_DDA_SR_2__DSRDY_MASK                            0x01ffffffL

// RE_DDA_SG_0
#define RE_DDA_SG_0__SGSTART_MASK                          0x01ffffffL

// RE_DDA_SG_1
#define RE_DDA_SG_1__DSGDX_MASK                            0x01ffffffL

// RE_DDA_SG_2
#define RE_DDA_SG_2__DSGDY_MASK                            0x01ffffffL

// RE_DDA_SB_0
#define RE_DDA_SB_0__SBSTART_MASK                          0x01ffffffL

// RE_DDA_SB_1
#define RE_DDA_SB_1__DSBDX_MASK                            0x01ffffffL

// RE_DDA_SB_2
#define RE_DDA_SB_2__DSBDY_MASK                            0x01ffffffL

// RE_DDA_S0_0
#define RE_DDA_S0_0__S0START_L_MASK                        0xffffffffL

// RE_DDA_S0_1
#define RE_DDA_S0_1__S0START_H_MASK                        0x000001ffL
#define RE_DDA_S0_1__DS0DX_L_MASK                          0xfffffe00L

// RE_DDA_S0_2
#define RE_DDA_S0_2__DS0DX_H_MASK                          0x0000ffffL
#define RE_DDA_S0_2__DS0DY_L_MASK                          0xffff0000L

// RE_DDA_S0_3
#define RE_DDA_S0_3__DS0DY_H_MASK                          0x007fffffL
#define RE_DDA_S0_3__NON_PARAMETRIC_MASK                   0x00800000L
#define RE_DDA_S0_3__NON_PARAMETRIC                        0x00800000L
#define RE_DDA_S0_3__S0EXPO_MASK                           0xff000000L

// RE_DDA_T0_0
#define RE_DDA_T0_0__T0START_L_MASK                        0xffffffffL

// RE_DDA_T0_1
#define RE_DDA_T0_1__T0START_H_MASK                        0x000001ffL
#define RE_DDA_T0_1__DT0DX_L_MASK                          0xfffffe00L

// RE_DDA_T0_2
#define RE_DDA_T0_2__DT0DX_H_MASK                          0x0000ffffL
#define RE_DDA_T0_2__DT0DY_L_MASK                          0xffff0000L

// RE_DDA_T0_3
#define RE_DDA_T0_3__DT0DY_H_MASK                          0x007fffffL
#define RE_DDA_T0_3__T0EXPO_MASK                           0xff000000L

// RE_DDA_Q0_0
#define RE_DDA_Q0_0__Q0START_L_MASK                        0xffffffffL

// RE_DDA_Q0_1
#define RE_DDA_Q0_1__Q0START_H_MASK                        0x000001ffL
#define RE_DDA_Q0_1__DQ0DX_L_MASK                          0xfffffe00L

// RE_DDA_Q0_2
#define RE_DDA_Q0_2__DQ0DX_H_MASK                          0x0000ffffL
#define RE_DDA_Q0_2__DQ0DY_L_MASK                          0xffff0000L

// RE_DDA_Q0_3
#define RE_DDA_Q0_3__DQ0DY_H_MASK                          0x007fffffL
#define RE_DDA_Q0_3__Q0EXPO_MASK                           0xff000000L

// RE_DDA_S1_0
#define RE_DDA_S1_0__S1START_L_MASK                        0xffffffffL

// RE_DDA_S1_1
#define RE_DDA_S1_1__S1START_H_MASK                        0x000001ffL
#define RE_DDA_S1_1__DS1DX_L_MASK                          0xfffffe00L

// RE_DDA_S1_2
#define RE_DDA_S1_2__DS1DX_H_MASK                          0x0000ffffL
#define RE_DDA_S1_2__DS1DY_L_MASK                          0xffff0000L

// RE_DDA_S1_3
#define RE_DDA_S1_3__DS1DY_H_MASK                          0x007fffffL
#define RE_DDA_S1_3__NON_PARAMETRIC_MASK                   0x00800000L
#define RE_DDA_S1_3__NON_PARAMETRIC                        0x00800000L
#define RE_DDA_S1_3__S1EXPO_MASK                           0xff000000L

// RE_DDA_T1_0
#define RE_DDA_T1_0__T1START_L_MASK                        0xffffffffL

// RE_DDA_T1_1
#define RE_DDA_T1_1__T1START_H_MASK                        0x000001ffL
#define RE_DDA_T1_1__DT1DX_L_MASK                          0xfffffe00L

// RE_DDA_T1_2
#define RE_DDA_T1_2__DT1DX_H_MASK                          0x0000ffffL
#define RE_DDA_T1_2__DT1DY_L_MASK                          0xffff0000L

// RE_DDA_T1_3
#define RE_DDA_T1_3__DT1DY_H_MASK                          0x007fffffL
#define RE_DDA_T1_3__T1EXPO_MASK                           0xff000000L

// RE_DDA_Q1_0
#define RE_DDA_Q1_0__Q1START_L_MASK                        0xffffffffL

// RE_DDA_Q1_1
#define RE_DDA_Q1_1__Q1START_H_MASK                        0x000001ffL
#define RE_DDA_Q1_1__DQ1DX_L_MASK                          0xfffffe00L

// RE_DDA_Q1_2
#define RE_DDA_Q1_2__DQ1DX_H_MASK                          0x0000ffffL
#define RE_DDA_Q1_2__DQ1DY_L_MASK                          0xffff0000L

// RE_DDA_Q1_3
#define RE_DDA_Q1_3__DQ1DY_H_MASK                          0x007fffffL
#define RE_DDA_Q1_3__Q1EXPO_MASK                           0xff000000L

// RE_DDA_S2_0
#define RE_DDA_S2_0__S2START_L_MASK                        0xffffffffL

// RE_DDA_S2_1
#define RE_DDA_S2_1__S2START_H_MASK                        0x000001ffL
#define RE_DDA_S2_1__DS2DX_L_MASK                          0xfffffe00L

// RE_DDA_S2_2
#define RE_DDA_S2_2__DS2DX_H_MASK                          0x0000ffffL
#define RE_DDA_S2_2__DS2DY_L_MASK                          0xffff0000L

// RE_DDA_S2_3
#define RE_DDA_S2_3__DS2DY_H_MASK                          0x007fffffL
#define RE_DDA_S2_3__NON_PARAMETRIC_MASK                   0x00800000L
#define RE_DDA_S2_3__NON_PARAMETRIC                        0x00800000L
#define RE_DDA_S2_3__S2EXPO_MASK                           0xff000000L

// RE_DDA_T2_0
#define RE_DDA_T2_0__T2START_L_MASK                        0xffffffffL

// RE_DDA_T2_1
#define RE_DDA_T2_1__T2START_H_MASK                        0x000001ffL
#define RE_DDA_T2_1__DT2DX_L_MASK                          0xfffffe00L

// RE_DDA_T2_2
#define RE_DDA_T2_2__DT2DX_H_MASK                          0x0000ffffL
#define RE_DDA_T2_2__DT2DY_L_MASK                          0xffff0000L

// RE_DDA_T2_3
#define RE_DDA_T2_3__DT2DY_H_MASK                          0x007fffffL
#define RE_DDA_T2_3__T2EXPO_MASK                           0xff000000L

// RE_DDA_Q2_0
#define RE_DDA_Q2_0__Q2START_L_MASK                        0xffffffffL

// RE_DDA_Q2_1
#define RE_DDA_Q2_1__Q2START_H_MASK                        0x000001ffL
#define RE_DDA_Q2_1__DQ2DX_L_MASK                          0xfffffe00L

// RE_DDA_Q2_2
#define RE_DDA_Q2_2__DQ2DX_H_MASK                          0x0000ffffL
#define RE_DDA_Q2_2__DQ2DY_L_MASK                          0xffff0000L

// RE_DDA_Q2_3
#define RE_DDA_Q2_3__DQ2DY_H_MASK                          0x007fffffL
#define RE_DDA_Q2_3__Q2EXPO_MASK                           0xff000000L

// RE_DDA_S3_0
#define RE_DDA_S3_0__S3START_L_MASK                        0xffffffffL

// RE_DDA_S3_1
#define RE_DDA_S3_1__S3START_H_MASK                        0x000001ffL
#define RE_DDA_S3_1__DS3DX_L_MASK                          0xfffffe00L

// RE_DDA_S3_2
#define RE_DDA_S3_2__DS3DX_H_MASK                          0x0000ffffL
#define RE_DDA_S3_2__DS3DY_L_MASK                          0xffff0000L

// RE_DDA_S3_3
#define RE_DDA_S3_3__DS3DY_H_MASK                          0x007fffffL
#define RE_DDA_S3_3__NON_PARAMETRIC_MASK                   0x00800000L
#define RE_DDA_S3_3__NON_PARAMETRIC                        0x00800000L
#define RE_DDA_S3_3__S3EXPO_MASK                           0xff000000L

// RE_DDA_T3_0
#define RE_DDA_T3_0__T3START_L_MASK                        0xffffffffL

// RE_DDA_T3_1
#define RE_DDA_T3_1__T3START_H_MASK                        0x000001ffL
#define RE_DDA_T3_1__DT3DX_L_MASK                          0xfffffe00L

// RE_DDA_T3_2
#define RE_DDA_T3_2__DT3DX_H_MASK                          0x0000ffffL
#define RE_DDA_T3_2__DT3DY_L_MASK                          0xffff0000L

// RE_DDA_T3_3
#define RE_DDA_T3_3__DT3DY_H_MASK                          0x007fffffL
#define RE_DDA_T3_3__T3EXPO_MASK                           0xff000000L

// RE_DDA_Q3_0
#define RE_DDA_Q3_0__Q3START_L_MASK                        0xffffffffL

// RE_DDA_Q3_1
#define RE_DDA_Q3_1__Q3START_H_MASK                        0x000001ffL
#define RE_DDA_Q3_1__DQ3DX_L_MASK                          0xfffffe00L

// RE_DDA_Q3_2
#define RE_DDA_Q3_2__DQ3DX_H_MASK                          0x0000ffffL
#define RE_DDA_Q3_2__DQ3DY_L_MASK                          0xffff0000L

// RE_DDA_Q3_3
#define RE_DDA_Q3_3__DQ3DY_H_MASK                          0x007fffffL
#define RE_DDA_Q3_3__Q3EXPO_MASK                           0xff000000L

// RE_DDA_DS0_0
#define RE_DDA_DS0_0__DS0XSTART_MASK                       0xffffffffL

// RE_DDA_DS0_1
#define RE_DDA_DS0_1__DS0YSTART_MASK                       0xffffffffL

// RE_DDA_DS0_2
#define RE_DDA_DS0_2__DS0INC_MASK                          0xffffffffL

// RE_DDA_DS0_3
#define RE_DDA_DS0_3__DS0EXPO_MASK                         0xff000000L

// RE_DDA_DT0_0
#define RE_DDA_DT0_0__DT0XSTART_MASK                       0xffffffffL

// RE_DDA_DT0_1
#define RE_DDA_DT0_1__DT0YSTART_MASK                       0xffffffffL

// RE_DDA_DT0_2
#define RE_DDA_DT0_2__DT0INC_MASK                          0xffffffffL

// RE_DDA_DT0_3
#define RE_DDA_DT0_3__DT0EXPO_MASK                         0xff000000L

// RE_DDA_DS1_0
#define RE_DDA_DS1_0__DS1XSTART_MASK                       0xffffffffL

// RE_DDA_DS1_1
#define RE_DDA_DS1_1__DS1YSTART_MASK                       0xffffffffL

// RE_DDA_DS1_2
#define RE_DDA_DS1_2__DS1INC_MASK                          0xffffffffL

// RE_DDA_DS1_3
#define RE_DDA_DS1_3__DS1EXPO_MASK                         0xff000000L

// RE_DDA_DT1_0
#define RE_DDA_DT1_0__DT1XSTART_MASK                       0xffffffffL

// RE_DDA_DT1_1
#define RE_DDA_DT1_1__DT1YSTART_MASK                       0xffffffffL

// RE_DDA_DT1_2
#define RE_DDA_DT1_2__DT1INC_MASK                          0xffffffffL

// RE_DDA_DT1_3
#define RE_DDA_DT1_3__DT1EXPO_MASK                         0xff000000L

// RE_DDA_DS2_0
#define RE_DDA_DS2_0__DS2XSTART_MASK                       0xffffffffL

// RE_DDA_DS2_1
#define RE_DDA_DS2_1__DS2YSTART_MASK                       0xffffffffL

// RE_DDA_DS2_2
#define RE_DDA_DS2_2__DS2INC_MASK                          0xffffffffL

// RE_DDA_DS2_3
#define RE_DDA_DS2_3__DS2EXPO_MASK                         0xff000000L

// RE_DDA_DT2_0
#define RE_DDA_DT2_0__DT2XSTART_MASK                       0xffffffffL

// RE_DDA_DT2_1
#define RE_DDA_DT2_1__DT2YSTART_MASK                       0xffffffffL

// RE_DDA_DT2_2
#define RE_DDA_DT2_2__DT2INC_MASK                          0xffffffffL

// RE_DDA_DT2_3
#define RE_DDA_DT2_3__DT2EXPO_MASK                         0xff000000L

// RE_DDA_DS3_0
#define RE_DDA_DS3_0__DS3XSTART_MASK                       0xffffffffL

// RE_DDA_DS3_1
#define RE_DDA_DS3_1__DS3YSTART_MASK                       0xffffffffL

// RE_DDA_DS3_2
#define RE_DDA_DS3_2__DS3INC_MASK                          0xffffffffL

// RE_DDA_DS3_3
#define RE_DDA_DS3_3__DS3EXPO_MASK                         0xff000000L

// RE_DDA_DT3_0
#define RE_DDA_DT3_0__DT3XSTART_MASK                       0xffffffffL

// RE_DDA_DT3_1
#define RE_DDA_DT3_1__DT3YSTART_MASK                       0xffffffffL

// RE_DDA_DT3_2
#define RE_DDA_DT3_2__DT3INC_MASK                          0xffffffffL

// RE_DDA_DT3_3
#define RE_DDA_DT3_3__DT3EXPO_MASK                         0xff000000L

// PP_MC_CONTEXT
#define PP_MC_CONTEXT__MC_BUF_BASE_MASK                    0x000000ffL
#define PP_MC_CONTEXT__SRC1_INDEX_MASK                     0x00000f00L
#define PP_MC_CONTEXT__SRC2_INDEX_MASK                     0x00007000L
#define PP_MC_CONTEXT__MC_FUNC_MASK                        0x00038000L
#define PP_MC_CONTEXT__DST_PITCH_MUL_MASK                  0x000c0000L
#define PP_MC_CONTEXT__SRC_2_PITCH_MUL_MASK                0x00300000L
#define PP_MC_CONTEXT__SRC_1_PITCH_MUL_MASK                0x00c00000L

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

// PP_CNTL
#define PP_CNTL__STIPPLE_ENABLE_MASK                       0x00000001L
#define PP_CNTL__STIPPLE_ENABLE                            0x00000001L
#define PP_CNTL__SCISSOR_ENABLE_MASK                       0x00000002L
#define PP_CNTL__SCISSOR_ENABLE                            0x00000002L
#define PP_CNTL__PATTERN_ENABLE_MASK                       0x00000004L
#define PP_CNTL__PATTERN_ENABLE                            0x00000004L
#define PP_CNTL__SHADOW_ENABLE_MASK                        0x00000008L
#define PP_CNTL__SHADOW_ENABLE                             0x00000008L
#define PP_CNTL__TEX_0_ENABLE_MASK                         0x00000010L
#define PP_CNTL__TEX_0_ENABLE                              0x00000010L
#define PP_CNTL__TEX_1_ENABLE_MASK                         0x00000020L
#define PP_CNTL__TEX_1_ENABLE                              0x00000020L
#define PP_CNTL__TEX_2_ENABLE_MASK                         0x00000040L
#define PP_CNTL__TEX_2_ENABLE                              0x00000040L
#define PP_CNTL__TEX_BLEND_0_ENABLE_MASK                   0x00001000L
#define PP_CNTL__TEX_BLEND_0_ENABLE                        0x00001000L
#define PP_CNTL__TEX_BLEND_1_ENABLE_MASK                   0x00002000L
#define PP_CNTL__TEX_BLEND_1_ENABLE                        0x00002000L
#define PP_CNTL__TEX_BLEND_2_ENABLE_MASK                   0x00004000L
#define PP_CNTL__TEX_BLEND_2_ENABLE                        0x00004000L
#define PP_CNTL__PLANAR_YUV_ENABLE_MASK                    0x00100000L
#define PP_CNTL__PLANAR_YUV_ENABLE                         0x00100000L
#define PP_CNTL__SPECULAR_ENABLE_MASK                      0x00200000L
#define PP_CNTL__SPECULAR_ENABLE                           0x00200000L
#define PP_CNTL__FOG_ENABLE_MASK                           0x00400000L
#define PP_CNTL__FOG_ENABLE                                0x00400000L
#define PP_CNTL__ALPHA_TEST_ENABLE_MASK                    0x00800000L
#define PP_CNTL__ALPHA_TEST_ENABLE                         0x00800000L
#define PP_CNTL__ANTI_ALIAS_CTL_MASK                       0x03000000L
#define PP_CNTL__BUMP_MAP_ENABLE_MASK                      0x04000000L
#define PP_CNTL__BUMP_MAP_ENABLE                           0x04000000L
#define PP_CNTL__BUMPED_MAP_MASK                           0x18000000L
#define PP_CNTL__TEX_3D_ENABLE_0_MASK                      0x20000000L
#define PP_CNTL__TEX_3D_ENABLE_0                           0x20000000L
#define PP_CNTL__TEX_3D_ENABLE_1_MASK                      0x40000000L
#define PP_CNTL__TEX_3D_ENABLE_1                           0x40000000L
#define PP_CNTL__MC_ENABLE_MASK                            0x80000000L
#define PP_CNTL__MC_ENABLE                                 0x80000000L

// PP_TXFILTER_0
#define PP_TXFILTER_0__MAG_FILTER_MASK                     0x00000001L
#define PP_TXFILTER_0__MAG_FILTER                          0x00000001L
#define PP_TXFILTER_0__MIN_FILTER_MASK                     0x0000001eL
#define PP_TXFILTER_0__MAX_ANIS_MASK                       0x000000e0L
#define PP_TXFILTER_0__LOD_BIAS_MASK                       0x0000ff00L
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
#define PP_TXFILTER_0__BORDER_MODE_MASK                    0x80000000L
#define PP_TXFILTER_0__BORDER_MODE                         0x80000000L

// PP_TXFILTER_1
#define PP_TXFILTER_1__MAG_FILTER_MASK                     0x00000001L
#define PP_TXFILTER_1__MAG_FILTER                          0x00000001L
#define PP_TXFILTER_1__MIN_FILTER_MASK                     0x0000001eL
#define PP_TXFILTER_1__LOD_BIAS_MASK                       0x0000ff00L
#define PP_TXFILTER_1__MAX_MIP_LEVEL_MASK                  0x000f0000L
#define PP_TXFILTER_1__WRAPEN_S_MASK                       0x00400000L
#define PP_TXFILTER_1__WRAPEN_S                            0x00400000L
#define PP_TXFILTER_1__CLAMP_S_MASK                        0x03800000L
#define PP_TXFILTER_1__WRAPEN_T_MASK                       0x04000000L
#define PP_TXFILTER_1__WRAPEN_T                            0x04000000L
#define PP_TXFILTER_1__CLAMP_T_MASK                        0x38000000L
#define PP_TXFILTER_1__BORDER_MODE_MASK                    0x80000000L
#define PP_TXFILTER_1__BORDER_MODE                         0x80000000L

// PP_TXFILTER_2
#define PP_TXFILTER_2__MAG_FILTER_MASK                     0x00000001L
#define PP_TXFILTER_2__MAG_FILTER                          0x00000001L
#define PP_TXFILTER_2__MIN_FILTER_MASK                     0x0000001eL
#define PP_TXFILTER_2__LOD_BIAS_MASK                       0x0000ff00L
#define PP_TXFILTER_2__MAX_MIP_LEVEL_MASK                  0x000f0000L
#define PP_TXFILTER_2__WRAPEN_S_MASK                       0x00400000L
#define PP_TXFILTER_2__WRAPEN_S                            0x00400000L
#define PP_TXFILTER_2__CLAMP_S_MASK                        0x03800000L
#define PP_TXFILTER_2__WRAPEN_T_MASK                       0x04000000L
#define PP_TXFILTER_2__WRAPEN_T                            0x04000000L
#define PP_TXFILTER_2__CLAMP_T_MASK                        0x38000000L
#define PP_TXFILTER_2__BORDER_MODE_MASK                    0x80000000L
#define PP_TXFILTER_2__BORDER_MODE                         0x80000000L

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
#define PP_TXFORMAT_0__ST_ROUTE_MASK                       0x03000000L
#define PP_TXFORMAT_0__ALPHA_MASK_ENABLE_MASK              0x10000000L
#define PP_TXFORMAT_0__ALPHA_MASK_ENABLE                   0x10000000L
#define PP_TXFORMAT_0__CHROMA_KEY_ENABLE_MASK              0x20000000L
#define PP_TXFORMAT_0__CHROMA_KEY_ENABLE                   0x20000000L
#define PP_TXFORMAT_0__CUBIC_MAP_ENABLE_MASK               0x40000000L
#define PP_TXFORMAT_0__CUBIC_MAP_ENABLE                    0x40000000L
#define PP_TXFORMAT_0__PERSPECTIVE_ENABLE_MASK             0x80000000L
#define PP_TXFORMAT_0__PERSPECTIVE_ENABLE                  0x80000000L

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
#define PP_TXFORMAT_1__ST_ROUTE_MASK                       0x03000000L
#define PP_TXFORMAT_1__ALPHA_MASK_ENABLE_MASK              0x10000000L
#define PP_TXFORMAT_1__ALPHA_MASK_ENABLE                   0x10000000L
#define PP_TXFORMAT_1__CHROMA_KEY_ENABLE_MASK              0x20000000L
#define PP_TXFORMAT_1__CHROMA_KEY_ENABLE                   0x20000000L
#define PP_TXFORMAT_1__CUBIC_MAP_ENABLE_MASK               0x40000000L
#define PP_TXFORMAT_1__CUBIC_MAP_ENABLE                    0x40000000L
#define PP_TXFORMAT_1__PERSPECTIVE_ENABLE_MASK             0x80000000L
#define PP_TXFORMAT_1__PERSPECTIVE_ENABLE                  0x80000000L

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
#define PP_TXFORMAT_2__ST_ROUTE_MASK                       0x03000000L
#define PP_TXFORMAT_2__ALPHA_MASK_ENABLE_MASK              0x10000000L
#define PP_TXFORMAT_2__ALPHA_MASK_ENABLE                   0x10000000L
#define PP_TXFORMAT_2__CHROMA_KEY_ENABLE_MASK              0x20000000L
#define PP_TXFORMAT_2__CHROMA_KEY_ENABLE                   0x20000000L
#define PP_TXFORMAT_2__CUBIC_MAP_ENABLE_MASK               0x40000000L
#define PP_TXFORMAT_2__CUBIC_MAP_ENABLE                    0x40000000L
#define PP_TXFORMAT_2__PERSPECTIVE_ENABLE_MASK             0x80000000L
#define PP_TXFORMAT_2__PERSPECTIVE_ENABLE                  0x80000000L

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

// PP_TEX_SIZE_0
#define PP_TEX_SIZE_0__TEX_USIZE_MASK                      0x000007ffL
#define PP_TEX_SIZE_0__TEX_VSIZE_MASK                      0x07ff0000L

// PP_TEX_SIZE_1
#define PP_TEX_SIZE_1__TEX_USIZE_MASK                      0x000007ffL
#define PP_TEX_SIZE_1__TEX_VSIZE_MASK                      0x07ff0000L

// PP_TEX_SIZE_2
#define PP_TEX_SIZE_2__TEX_USIZE_MASK                      0x000007ffL
#define PP_TEX_SIZE_2__TEX_VSIZE_MASK                      0x07ff0000L

// PP_TXPITCH_0
#define PP_TXPITCH_0__TXPITCH_MASK                         0x00003fe0L

// PP_TXPITCH_1
#define PP_TXPITCH_1__TXPITCH_MASK                         0x00003fe0L

// PP_TXPITCH_2
#define PP_TXPITCH_2__TXPITCH_MASK                         0x00003fe0L

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

// PP_CUBIC_OFFSET_T0_0
#define PP_CUBIC_OFFSET_T0_0__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_T0_1
#define PP_CUBIC_OFFSET_T0_1__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_T0_2
#define PP_CUBIC_OFFSET_T0_2__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_T0_3
#define PP_CUBIC_OFFSET_T0_3__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_T0_4
#define PP_CUBIC_OFFSET_T0_4__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_T1_0
#define PP_CUBIC_OFFSET_T1_0__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_T1_1
#define PP_CUBIC_OFFSET_T1_1__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_T1_2
#define PP_CUBIC_OFFSET_T1_2__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_T1_3
#define PP_CUBIC_OFFSET_T1_3__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_T1_4
#define PP_CUBIC_OFFSET_T1_4__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_T2_0
#define PP_CUBIC_OFFSET_T2_0__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_T2_1
#define PP_CUBIC_OFFSET_T2_1__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_T2_2
#define PP_CUBIC_OFFSET_T2_2__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_T2_3
#define PP_CUBIC_OFFSET_T2_3__FACE_OFFSET_MASK             0xffffffe0L

// PP_CUBIC_OFFSET_T2_4
#define PP_CUBIC_OFFSET_T2_4__FACE_OFFSET_MASK             0xffffffe0L

// PP_SHADOW_ID
#define PP_SHADOW_ID__SHADOW_ID_MASK                       0x00ffffffL

// PP_CHROMA_COLOR
#define PP_CHROMA_COLOR__CHROMA_COLOR_MASK                 0xffffffffL

// PP_CHROMA_MASK
#define PP_CHROMA_MASK__CHROMA_MASK_MASK                   0xffffffffL

// PP_BORDER_COLOR_0
#define PP_BORDER_COLOR_0__BORD_COLOR_MASK                 0xffffffffL

// PP_BORDER_COLOR_1
#define PP_BORDER_COLOR_1__BORD_COLOR_MASK                 0xffffffffL

// PP_BORDER_COLOR_2
#define PP_BORDER_COLOR_2__BORD_COLOR_MASK                 0xffffffffL

// PP_MISC
#define PP_MISC__REF_ALPHA_MASK                            0x000000ffL
#define PP_MISC__ALPHA_TEST_OP_MASK                        0x00000700L
#define PP_MISC__CHROMA_FUNC_MASK                          0x00030000L
#define PP_MISC__CHROMA_KEY_MODE_MASK                      0x00040000L
#define PP_MISC__CHROMA_KEY_MODE                           0x00040000L
#define PP_MISC__SHADOW_AUTO_INC_MASK                      0x00100000L
#define PP_MISC__SHADOW_AUTO_INC                           0x00100000L
#define PP_MISC__SHADOW_FUNC_MASK                          0x00200000L
#define PP_MISC__SHADOW_FUNC                               0x00200000L
#define PP_MISC__SHADOW_PASS_MASK                          0x00400000L
#define PP_MISC__SHADOW_PASS                               0x00400000L
#define PP_MISC__RIGHT_HAND_CUBE_MASK                      0x01000000L
#define PP_MISC__RIGHT_HAND_CUBE                           0x01000000L

// PP_TXCBLEND_0
#define PP_TXCBLEND_0__COLOR_ARG_A_MASK                    0x0000001fL
#define PP_TXCBLEND_0__COLOR_ARG_B_MASK                    0x000003e0L
#define PP_TXCBLEND_0__COLOR_ARG_C_MASK                    0x00007c00L
#define PP_TXCBLEND_0__COMP_ARG_A_MASK                     0x00008000L
#define PP_TXCBLEND_0__COMP_ARG_A                          0x00008000L
#define PP_TXCBLEND_0__COMP_ARG_B_MASK                     0x00010000L
#define PP_TXCBLEND_0__COMP_ARG_B                          0x00010000L
#define PP_TXCBLEND_0__COMP_ARG_C_MASK                     0x00020000L
#define PP_TXCBLEND_0__COMP_ARG_C                          0x00020000L
#define PP_TXCBLEND_0__BLEND_CTL_MASK                      0x001c0000L
#define PP_TXCBLEND_0__SCALE_TX_MASK                       0x00600000L
#define PP_TXCBLEND_0__CLAMP_TX_MASK                       0x00800000L
#define PP_TXCBLEND_0__CLAMP_TX                            0x00800000L
#define PP_TXCBLEND_0__T0_EQ_TCUR_MASK                     0x01000000L
#define PP_TXCBLEND_0__T0_EQ_TCUR                          0x01000000L
#define PP_TXCBLEND_0__T1_EQ_TCUR_MASK                     0x02000000L
#define PP_TXCBLEND_0__T1_EQ_TCUR                          0x02000000L
#define PP_TXCBLEND_0__T2_EQ_TCUR_MASK                     0x04000000L
#define PP_TXCBLEND_0__T2_EQ_TCUR                          0x04000000L

// PP_TXCBLEND_1
#define PP_TXCBLEND_1__COLOR_ARG_A_MASK                    0x0000001fL
#define PP_TXCBLEND_1__COLOR_ARG_B_MASK                    0x000003e0L
#define PP_TXCBLEND_1__COLOR_ARG_C_MASK                    0x00007c00L
#define PP_TXCBLEND_1__COMP_ARG_A_MASK                     0x00008000L
#define PP_TXCBLEND_1__COMP_ARG_A                          0x00008000L
#define PP_TXCBLEND_1__COMP_ARG_B_MASK                     0x00010000L
#define PP_TXCBLEND_1__COMP_ARG_B                          0x00010000L
#define PP_TXCBLEND_1__COMP_ARG_C_MASK                     0x00020000L
#define PP_TXCBLEND_1__COMP_ARG_C                          0x00020000L
#define PP_TXCBLEND_1__BLEND_CTL_MASK                      0x001c0000L
#define PP_TXCBLEND_1__SCALE_TX_MASK                       0x00600000L
#define PP_TXCBLEND_1__CLAMP_TX_MASK                       0x00800000L
#define PP_TXCBLEND_1__CLAMP_TX                            0x00800000L
#define PP_TXCBLEND_1__T0_EQ_TCUR_MASK                     0x01000000L
#define PP_TXCBLEND_1__T0_EQ_TCUR                          0x01000000L
#define PP_TXCBLEND_1__T1_EQ_TCUR_MASK                     0x02000000L
#define PP_TXCBLEND_1__T1_EQ_TCUR                          0x02000000L
#define PP_TXCBLEND_1__T2_EQ_TCUR_MASK                     0x04000000L
#define PP_TXCBLEND_1__T2_EQ_TCUR                          0x04000000L

// PP_TXCBLEND_2
#define PP_TXCBLEND_2__COLOR_ARG_A_MASK                    0x0000001fL
#define PP_TXCBLEND_2__COLOR_ARG_B_MASK                    0x000003e0L
#define PP_TXCBLEND_2__COLOR_ARG_C_MASK                    0x00007c00L
#define PP_TXCBLEND_2__COMP_ARG_A_MASK                     0x00008000L
#define PP_TXCBLEND_2__COMP_ARG_A                          0x00008000L
#define PP_TXCBLEND_2__COMP_ARG_B_MASK                     0x00010000L
#define PP_TXCBLEND_2__COMP_ARG_B                          0x00010000L
#define PP_TXCBLEND_2__COMP_ARG_C_MASK                     0x00020000L
#define PP_TXCBLEND_2__COMP_ARG_C                          0x00020000L
#define PP_TXCBLEND_2__BLEND_CTL_MASK                      0x001c0000L
#define PP_TXCBLEND_2__SCALE_TX_MASK                       0x00600000L
#define PP_TXCBLEND_2__CLAMP_TX_MASK                       0x00800000L
#define PP_TXCBLEND_2__CLAMP_TX                            0x00800000L
#define PP_TXCBLEND_2__T0_EQ_TCUR_MASK                     0x01000000L
#define PP_TXCBLEND_2__T0_EQ_TCUR                          0x01000000L
#define PP_TXCBLEND_2__T1_EQ_TCUR_MASK                     0x02000000L
#define PP_TXCBLEND_2__T1_EQ_TCUR                          0x02000000L
#define PP_TXCBLEND_2__T2_EQ_TCUR_MASK                     0x04000000L
#define PP_TXCBLEND_2__T2_EQ_TCUR                          0x04000000L

// PP_TXABLEND_0
#define PP_TXABLEND_0__ALPHA_ARG_A_MASK                    0x0000000fL
#define PP_TXABLEND_0__ALPHA_ARG_B_MASK                    0x000000f0L
#define PP_TXABLEND_0__ALPHA_ARG_C_MASK                    0x00000f00L
#define PP_TXABLEND_0__DOT_ALPHA_MASK                      0x00001000L
#define PP_TXABLEND_0__DOT_ALPHA                           0x00001000L
#define PP_TXABLEND_0__COMP_ARG_A_MASK                     0x00008000L
#define PP_TXABLEND_0__COMP_ARG_A                          0x00008000L
#define PP_TXABLEND_0__COMP_ARG_B_MASK                     0x00010000L
#define PP_TXABLEND_0__COMP_ARG_B                          0x00010000L
#define PP_TXABLEND_0__COMP_ARG_C_MASK                     0x00020000L
#define PP_TXABLEND_0__COMP_ARG_C                          0x00020000L
#define PP_TXABLEND_0__BLEND_CTL_MASK                      0x001c0000L
#define PP_TXABLEND_0__SCALE_TX_MASK                       0x00600000L
#define PP_TXABLEND_0__CLAMP_TX_MASK                       0x00800000L
#define PP_TXABLEND_0__CLAMP_TX                            0x00800000L
#define PP_TXABLEND_0__T0_EQ_TCUR_MASK                     0x01000000L
#define PP_TXABLEND_0__T0_EQ_TCUR                          0x01000000L
#define PP_TXABLEND_0__T1_EQ_TCUR_MASK                     0x02000000L
#define PP_TXABLEND_0__T1_EQ_TCUR                          0x02000000L
#define PP_TXABLEND_0__T2_EQ_TCUR_MASK                     0x04000000L
#define PP_TXABLEND_0__T2_EQ_TCUR                          0x04000000L

// PP_TXABLEND_1
#define PP_TXABLEND_1__ALPHA_ARG_A_MASK                    0x0000000fL
#define PP_TXABLEND_1__ALPHA_ARG_B_MASK                    0x000000f0L
#define PP_TXABLEND_1__ALPHA_ARG_C_MASK                    0x00000f00L
#define PP_TXABLEND_1__DOT_ALPHA_MASK                      0x00001000L
#define PP_TXABLEND_1__DOT_ALPHA                           0x00001000L
#define PP_TXABLEND_1__COMP_ARG_A_MASK                     0x00008000L
#define PP_TXABLEND_1__COMP_ARG_A                          0x00008000L
#define PP_TXABLEND_1__COMP_ARG_B_MASK                     0x00010000L
#define PP_TXABLEND_1__COMP_ARG_B                          0x00010000L
#define PP_TXABLEND_1__COMP_ARG_C_MASK                     0x00020000L
#define PP_TXABLEND_1__COMP_ARG_C                          0x00020000L
#define PP_TXABLEND_1__BLEND_CTL_MASK                      0x001c0000L
#define PP_TXABLEND_1__SCALE_TX_MASK                       0x00600000L
#define PP_TXABLEND_1__CLAMP_TX_MASK                       0x00800000L
#define PP_TXABLEND_1__CLAMP_TX                            0x00800000L
#define PP_TXABLEND_1__T0_EQ_TCUR_MASK                     0x01000000L
#define PP_TXABLEND_1__T0_EQ_TCUR                          0x01000000L
#define PP_TXABLEND_1__T1_EQ_TCUR_MASK                     0x02000000L
#define PP_TXABLEND_1__T1_EQ_TCUR                          0x02000000L
#define PP_TXABLEND_1__T2_EQ_TCUR_MASK                     0x04000000L
#define PP_TXABLEND_1__T2_EQ_TCUR                          0x04000000L

// PP_TXABLEND_2
#define PP_TXABLEND_2__ALPHA_ARG_A_MASK                    0x0000000fL
#define PP_TXABLEND_2__ALPHA_ARG_B_MASK                    0x000000f0L
#define PP_TXABLEND_2__ALPHA_ARG_C_MASK                    0x00000f00L
#define PP_TXABLEND_2__DOT_ALPHA_MASK                      0x00001000L
#define PP_TXABLEND_2__DOT_ALPHA                           0x00001000L
#define PP_TXABLEND_2__COMP_ARG_A_MASK                     0x00008000L
#define PP_TXABLEND_2__COMP_ARG_A                          0x00008000L
#define PP_TXABLEND_2__COMP_ARG_B_MASK                     0x00010000L
#define PP_TXABLEND_2__COMP_ARG_B                          0x00010000L
#define PP_TXABLEND_2__COMP_ARG_C_MASK                     0x00020000L
#define PP_TXABLEND_2__COMP_ARG_C                          0x00020000L
#define PP_TXABLEND_2__BLEND_CTL_MASK                      0x001c0000L
#define PP_TXABLEND_2__SCALE_TX_MASK                       0x00600000L
#define PP_TXABLEND_2__CLAMP_TX_MASK                       0x00800000L
#define PP_TXABLEND_2__CLAMP_TX                            0x00800000L
#define PP_TXABLEND_2__T0_EQ_TCUR_MASK                     0x01000000L
#define PP_TXABLEND_2__T0_EQ_TCUR                          0x01000000L
#define PP_TXABLEND_2__T1_EQ_TCUR_MASK                     0x02000000L
#define PP_TXABLEND_2__T1_EQ_TCUR                          0x02000000L
#define PP_TXABLEND_2__T2_EQ_TCUR_MASK                     0x04000000L
#define PP_TXABLEND_2__T2_EQ_TCUR                          0x04000000L

// PP_TFACTOR_0
#define PP_TFACTOR_0__TFACTOR_MASK                         0xffffffffL

// PP_TFACTOR_1
#define PP_TFACTOR_1__TFACTOR_MASK                         0xffffffffL

// PP_TFACTOR_2
#define PP_TFACTOR_2__TFACTOR_MASK                         0xffffffffL

// PP_ROT_MATRIX_0
#define PP_ROT_MATRIX_0__M00_MAN_MASK                      0x000007ffL
#define PP_ROT_MATRIX_0__M10_MAN_MASK                      0x07ff0000L
#define PP_ROT_MATRIX_0__Mx0_EXPO_MASK                     0x78000000L

// PP_ROT_MATRIX_1
#define PP_ROT_MATRIX_1__M01_MAN_MASK                      0x000007ffL
#define PP_ROT_MATRIX_1__M11_MAN_MASK                      0x07ff0000L
#define PP_ROT_MATRIX_1__Mx1_EXPO_MASK                     0x78000000L

// PP_LUM_MATRIX
#define PP_LUM_MATRIX__LSCALE_MASK                         0x000000ffL
#define PP_LUM_MATRIX__LOFFSET_MASK                        0x0000ff00L

// PP_FOG_COLOR
#define PP_FOG_COLOR__FOG_COLOR_MASK                       0x00ffffffL
#define PP_FOG_COLOR__FOG_TABLE_MASK                       0x01000000L
#define PP_FOG_COLOR__FOG_TABLE                            0x01000000L
#define PP_FOG_COLOR__FOG_INDEX_SEL_MASK                   0x06000000L

// PP_FOG_TABLE_INDEX
#define PP_FOG_TABLE_INDEX__FOG_INDEX_MASK                 0x000000ffL

// PP_FOG_TABLE_DATA
#define PP_FOG_TABLE_DATA__FOG_DATA_MASK                   0x000000ffL

// PP_PERF
#define PP_PERF__RR_FIFO_SCALE_MASK                        0x00000003L
#define PP_PERF__REQUEST_SCALE_MASK                        0x00000004L
#define PP_PERF__REQUEST_SCALE                             0x00000004L
#define PP_PERF__PP_COUNT_CTL_MASK                         0x00000030L

// PP_TRI_JUICE
#define PP_TRI_JUICE__TRI_JUICE_MASK                       0x0000001fL

// PP_PERF_COUNT_0
#define PP_PERF_COUNT_0__PP_CACHE_COUNT_MASK               0xffffffffL

// PP_PERF_COUNT_1
#define PP_PERF_COUNT_1__PP_CACHE_COUNT_MASK               0xffffffffL

// PP_PERF_COUNT_2
#define PP_PERF_COUNT_2__PP_CACHE_COUNT_MASK               0xffffffffL

// PP_PERF_COUNT_3
#define PP_PERF_COUNT_3__PP_CACHE_COUNT_MASK               0xffffffffL

// PP_TAM_DEBUG_0
#define PP_TAM_DEBUG_0__TAM_DWORD_MASK                     0xffffffffL

// PP_TAM_DEBUG_1
#define PP_TAM_DEBUG_1__TAM_DWORD_MASK                     0xffffffffL

// PP_TAM_DEBUG_2
#define PP_TAM_DEBUG_2__TAM_DWORD_MASK                     0xffffffffL

// PP_TAM_DEBUG_3
#define PP_TAM_DEBUG_3__TAM_DWORD_MASK                     0xffffffffL

// PP_TDM_DEBUG_0
#define PP_TDM_DEBUG_0__TDM_DWORD_MASK                     0xffffffffL

// PP_TDM_DEBUG_1
#define PP_TDM_DEBUG_1__TDM_DWORD_MASK                     0xffffffffL

// PP_TDM_DEBUG_2
#define PP_TDM_DEBUG_2__TDM_DWORD_MASK                     0xffffffffL

// PP_TDM_DEBUG_3
#define PP_TDM_DEBUG_3__TDM_DWORD_MASK                     0xffffffffL

// PP_PB_DEBUG_0
#define PP_PB_DEBUG_0__PB_DWORD_MASK                       0xffffffffL

// PP_PB_DEBUG_1
#define PP_PB_DEBUG_1__PB_DWORD_MASK                       0xffffffffL

// PP_PB_DEBUG_2
#define PP_PB_DEBUG_2__PB_DWORD_MASK                       0xffffffffL

// PP_PB_DEBUG_3
#define PP_PB_DEBUG_3__PB_DWORD_MASK                       0xffffffffL

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
#define RB2D_DSTCACHE_MODE__DC_FORCE_RMW_MASK              0x00010000L
#define RB2D_DSTCACHE_MODE__DC_FORCE_RMW                   0x00010000L
#define RB2D_DSTCACHE_MODE__DC_DISABLE_RI_FILL_MASK        0x01000000L
#define RB2D_DSTCACHE_MODE__DC_DISABLE_RI_FILL             0x01000000L
#define RB2D_DSTCACHE_MODE__DC_DISABLE_RI_READ_MASK        0x02000000L
#define RB2D_DSTCACHE_MODE__DC_DISABLE_RI_READ             0x02000000L

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

// RB2D_PD1_ADDR
#define RB2D_PD1_ADDR__PD1_ADDR_MASK                       0x00000007L

// RB2D_PD2_DATA
#define RB2D_PD2_DATA__PD2_DATA_MASK                       0xffffffffL

// RB2D_WRITEBACK_DATA_LO
#define RB2D_WRITEBACK_DATA_LO__WRITEBACK_DATA_LO_MASK     0xffffffffL

// RB2D_WRITEBACK_DATA_HI
#define RB2D_WRITEBACK_DATA_HI__WRITEBACK_DATA_HI_MASK     0xffffffffL

// RB2D_WRITEBACK_ADDR
#define RB2D_WRITEBACK_ADDR__WRITEBACK_ADDR_MASK           0xfffffff8L

// RB3D_BLENDCNTL
#define RB3D_BLENDCNTL__COMB_FCN_MASK                      0x00003000L
#define RB3D_BLENDCNTL__SRCBLEND_MASK                      0x003f0000L
#define RB3D_BLENDCNTL__DESTBLEND_MASK                     0x3f000000L

// RB3D_DEPTHOFFSET
#define RB3D_DEPTHOFFSET__DEPTHOFFSET_MASK                 0xfffffff0L

// RB3D_DEPTHPITCH
#define RB3D_DEPTHPITCH__DEPTHPITCH_MASK                   0x00001ff8L
#define RB3D_DEPTHPITCH__DEPTHTILE_MASK                    0x00010000L
#define RB3D_DEPTHPITCH__DEPTHTILE                         0x00010000L
#define RB3D_DEPTHPITCH__DEPTHMICROTILE_MASK               0x00020000L
#define RB3D_DEPTHPITCH__DEPTHMICROTILE                    0x00020000L
#define RB3D_DEPTHPITCH__DEPTHENDIAN_MASK                  0x000c0000L

// RB3D_ZSTENCILCNTL
#define RB3D_ZSTENCILCNTL__DEPTHFORMAT_MASK                0x0000000fL
#define RB3D_ZSTENCILCNTL__ZFUNC_MASK                      0x00000070L
#define RB3D_ZSTENCILCNTL__STENCILFUNC_MASK                0x00007000L
#define RB3D_ZSTENCILCNTL__STENCILFAIL_MASK                0x00070000L
#define RB3D_ZSTENCILCNTL__STENCILZPASS_MASK               0x00700000L
#define RB3D_ZSTENCILCNTL__STENCILZFAIL_MASK               0x07000000L
#define RB3D_ZSTENCILCNTL__FORCEZDIRTY_MASK                0x20000000L
#define RB3D_ZSTENCILCNTL__FORCEZDIRTY                     0x20000000L
#define RB3D_ZSTENCILCNTL__ZWRITEENABLE_MASK               0x40000000L
#define RB3D_ZSTENCILCNTL__ZWRITEENABLE                    0x40000000L
#define RB3D_ZSTENCILCNTL__ZDECOMPRESSION_MASK             0x80000000L
#define RB3D_ZSTENCILCNTL__ZDECOMPRESSION                  0x80000000L

// RB3D_DEPTHCLEARVALUE_M6
#define RB3D_DEPTHCLEARVALUE_M6__DEPTHCLEARVALUE_MASK      0xffffffffL

// RB3D_ZMASKOFFSET_M6
#define RB3D_ZMASKOFFSET_M6__ZMASKOFFSET_MASK              0x0003ffe0L

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
#define RB3D_CNTL__ZBLOCK16_MASK                           0x00008000L
#define RB3D_CNTL__ZBLOCK16                                0x00008000L

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

// RB3D_ZMASK_WRINDEX_M6
#define RB3D_ZMASK_WRINDEX_M6__ZMASK_WRINDEX_MASK          0x0003ffe0L

// RB3D_ZMASK_DWORD
#define RB3D_ZMASK_DWORD__ZMASKDWORD_MASK                  0xffffffffL

// RB3D_ZMASK_RDINDEX_M6
#define RB3D_ZMASK_RDINDEX_M6__ZMASK_RDINDEX_MASK          0x0003ffe0L

// RB3D_STENCILREFMASK
#define RB3D_STENCILREFMASK__STENCILREF_MASK               0x000000ffL
#define RB3D_STENCILREFMASK__STENCILMASK_MASK              0x00ff0000L
#define RB3D_STENCILREFMASK__STENCILWRITEMASK_MASK         0xff000000L

// RB3D_ROPCNTL
#define RB3D_ROPCNTL__ROP_MASK                             0x00000f00L

// RB3D_PLANEMASK
#define RB3D_PLANEMASK__PLANEMASK_MASK                     0xffffffffL

// RB3D_ZCACHE_MODE
#define RB3D_ZCACHE_MODE__ZC_BYPASS_MASK                   0x00000001L
#define RB3D_ZCACHE_MODE__ZC_BYPASS                        0x00000001L
#define RB3D_ZCACHE_MODE__ZC_LINE_SIZE_MASK                0x00000004L
#define RB3D_ZCACHE_MODE__ZC_LINE_SIZE                     0x00000004L
#define RB3D_ZCACHE_MODE__Z_IDLE_ENABLE_MASK               0x00000010L
#define RB3D_ZCACHE_MODE__Z_IDLE_ENABLE                    0x00000010L
#define RB3D_ZCACHE_MODE__Z_CLEAN_ENABLE_MASK              0x00000020L
#define RB3D_ZCACHE_MODE__Z_CLEAN_ENABLE                   0x00000020L
#define RB3D_ZCACHE_MODE__ZMASK_RAM_RM_MASK                0x00000f00L
#define RB3D_ZCACHE_MODE__ZC_DISABLE_RI_FILL_MASK          0x01000000L
#define RB3D_ZCACHE_MODE__ZC_DISABLE_RI_FILL               0x01000000L
#define RB3D_ZCACHE_MODE__ZC_DISABLE_RI_READ_MASK          0x02000000L
#define RB3D_ZCACHE_MODE__ZC_DISABLE_RI_READ               0x02000000L
#define RB3D_ZCACHE_MODE__DISABLE_DR_L0_RD_MASK            0x04000000L
#define RB3D_ZCACHE_MODE__DISABLE_DR_L0_RD                 0x04000000L
#define RB3D_ZCACHE_MODE__DISABLE_DR_L0_WR_MASK            0x08000000L
#define RB3D_ZCACHE_MODE__DISABLE_DR_L0_WR                 0x08000000L

// RB3D_ZCACHE_CTLSTAT
#define RB3D_ZCACHE_CTLSTAT__ZC_FLUSH_MASK                 0x00000001L
#define RB3D_ZCACHE_CTLSTAT__ZC_FLUSH                      0x00000001L
#define RB3D_ZCACHE_CTLSTAT__ZC_FREE_MASK                  0x00000004L
#define RB3D_ZCACHE_CTLSTAT__ZC_FREE                       0x00000004L
#define RB3D_ZCACHE_CTLSTAT__ZC_DIRTY_MASK                 0x40000000L
#define RB3D_ZCACHE_CTLSTAT__ZC_DIRTY                      0x40000000L
#define RB3D_ZCACHE_CTLSTAT__ZC_BUSY_MASK                  0x80000000L
#define RB3D_ZCACHE_CTLSTAT__ZC_BUSY                       0x80000000L

// RB3D_DSTCACHE_MODE
#define RB3D_DSTCACHE_MODE__DC_BYPASS_MASK                 0x00000003L
#define RB3D_DSTCACHE_MODE__DC_LINE_SIZE_MASK              0x0000000cL
#define RB3D_DSTCACHE_MODE__DC_AUTOFLUSH_ENABLE_MASK       0x00000300L
#define RB3D_DSTCACHE_MODE__DC_FORCE_RMW_MASK              0x00010000L
#define RB3D_DSTCACHE_MODE__DC_FORCE_RMW                   0x00010000L
#define RB3D_DSTCACHE_MODE__DC_DISABLE_RI_FILL_MASK        0x01000000L
#define RB3D_DSTCACHE_MODE__DC_DISABLE_RI_FILL             0x01000000L
#define RB3D_DSTCACHE_MODE__DC_DISABLE_RI_READ_MASK        0x02000000L
#define RB3D_DSTCACHE_MODE__DC_DISABLE_RI_READ             0x02000000L
#define RB3D_DSTCACHE_MODE__DC_DISABLE_L0_RD_MASK          0x04000000L
#define RB3D_DSTCACHE_MODE__DC_DISABLE_L0_RD               0x04000000L
#define RB3D_DSTCACHE_MODE__DC_DISABLE_L0_WR_MASK          0x08000000L
#define RB3D_DSTCACHE_MODE__DC_DISABLE_L0_WR               0x08000000L

// RB3D_DSTCACHE_CTLSTAT
#define RB3D_DSTCACHE_CTLSTAT__DC_FLUSH_MASK               0x00000003L
#define RB3D_DSTCACHE_CTLSTAT__DC_FREE_MASK                0x0000000cL
#define RB3D_DSTCACHE_CTLSTAT__DC_BUSY_MASK                0x80000000L
#define RB3D_DSTCACHE_CTLSTAT__DC_BUSY                     0x80000000L

// RB3D_PD0_DATA
#define RB3D_PD0_DATA__DISABLE_RB_MASK                     0x00000001L
#define RB3D_PD0_DATA__DISABLE_RB                          0x00000001L
#define RB3D_PD0_DATA__RB3D_PD3_DATA_CNTL_MASK             0x00000070L

// RB3D_PD1_DATA
#define RB3D_PD1_DATA__PD1_DATA_MASK                       0xffffffffL

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

// RB3D_ZPASS_DATA
#define RB3D_ZPASS_DATA__ZPASS_DATA_MASK                   0xffffffffL

// RB3D_ZPASS_ADDR
#define RB3D_ZPASS_ADDR__ZPASS_ADDR_MASK                   0xfffffffcL

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

// TEST_DEBUG_OUT_U1
#define TEST_DEBUG_OUT_U1__TEST_DEBUG_OUTR_MASK            0x0000ffffL

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

// GPIOPAD_MASK_U1
#define GPIOPAD_MASK_U1__GPIO_MASK_MASK                    0x00003fffL

// GPIOPAD_A_U1
#define GPIOPAD_A_U1__GPIO_A_MASK                          0x00003fffL

// GPIOPAD_EN_U1
#define GPIOPAD_EN_U1__GPIO_EN_MASK                        0x00003fffL

// GPIOPAD_Y
#define GPIOPAD_Y__GPIO_Y_MASK                             0x00003fffL

// ZV_LCDPAD_MASK_U1
#define ZV_LCDPAD_MASK_U1__ZV_LCDDATA_MASK_MASK            0x00000fffL
#define ZV_LCDPAD_MASK_U1__ZV_LCDCNTL_MASK_MASK            0x0f000000L

// ZV_LCDPAD_A_U1
#define ZV_LCDPAD_A_U1__ZV_LCDDATA_A_MASK                  0x00000fffL
#define ZV_LCDPAD_A_U1__ZV_LCDCNTL_A_MASK                  0x0f000000L

// ZV_LCDPAD_EN_U1
#define ZV_LCDPAD_EN_U1__ZV_LCDDATA_EN_MASK                0x00000fffL
#define ZV_LCDPAD_EN_U1__ZV_LCDCNTL_EN_MASK                0x0f000000L

// ZV_LCDPAD_Y_U1
#define ZV_LCDPAD_Y_U1__ZV_LCDDATA_Y_MASK                  0x0000ffffL
#define ZV_LCDPAD_Y_U1__ZV_LCDCNTL_Y_MASK                  0x0f000000L

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

// VID_BUFFER_CONTROL_M6
#define VID_BUFFER_CONTROL_M6__CAP0_BUFFER_WATER_MARK_MASK 0x0000003fL
#define VID_BUFFER_CONTROL_M6__VID_BUFFER_RESET_MASK       0x00100000L
#define VID_BUFFER_CONTROL_M6__VID_BUFFER_RESET            0x00100000L
#define VID_BUFFER_CONTROL_M6__CAP_SWAP_MASK               0x00600000L
#define VID_BUFFER_CONTROL_M6__CAP0_BUFFER_EMPTY_MASK      0x01000000L
#define VID_BUFFER_CONTROL_M6__CAP0_BUFFER_EMPTY           0x01000000L

// CAP_INT_CNTL
#define CAP_INT_CNTL__CAP0_BUF0_INT_EN_MASK                0x00000001L
#define CAP_INT_CNTL__CAP0_BUF0_INT_EN                     0x00000001L
#define CAP_INT_CNTL__CAP0_BUF0_EVEN_INT_EN_MASK           0x00000002L
#define CAP_INT_CNTL__CAP0_BUF0_EVEN_INT_EN                0x00000002L
#define CAP_INT_CNTL__CAP0_BUF1_INT_EN_MASK                0x00000004L
#define CAP_INT_CNTL__CAP0_BUF1_INT_EN                     0x00000004L
#define CAP_INT_CNTL__CAP0_BUF1_EVEN_INT_EN_MASK           0x00000008L
#define CAP_INT_CNTL__CAP0_BUF1_EVEN_INT_EN                0x00000008L
#define CAP_INT_CNTL__CAP0_VBI0_INT_EN_MASK                0x00000010L
#define CAP_INT_CNTL__CAP0_VBI0_INT_EN                     0x00000010L
#define CAP_INT_CNTL__CAP0_VBI1_INT_EN_MASK                0x00000020L
#define CAP_INT_CNTL__CAP0_VBI1_INT_EN                     0x00000020L
#define CAP_INT_CNTL__CAP0_ONESHOT_INT_EN_MASK             0x00000040L
#define CAP_INT_CNTL__CAP0_ONESHOT_INT_EN                  0x00000040L

// CAP_INT_STATUS
#define CAP_INT_STATUS__CAP0_BUF0_INT_MASK                 0x00000001L
#define CAP_INT_STATUS__CAP0_BUF0_INT                      0x00000001L
#define CAP_INT_STATUS__CAP0_BUF0_INT_AK_MASK              0x00000001L
#define CAP_INT_STATUS__CAP0_BUF0_INT_AK                   0x00000001L
#define CAP_INT_STATUS__CAP0_BUF0_EVEN_INT_MASK            0x00000002L
#define CAP_INT_STATUS__CAP0_BUF0_EVEN_INT                 0x00000002L
#define CAP_INT_STATUS__CAP0_BUF0_EVEN_INT_AK_MASK         0x00000002L
#define CAP_INT_STATUS__CAP0_BUF0_EVEN_INT_AK              0x00000002L
#define CAP_INT_STATUS__CAP0_BUF1_INT_MASK                 0x00000004L
#define CAP_INT_STATUS__CAP0_BUF1_INT                      0x00000004L
#define CAP_INT_STATUS__CAP0_BUF1_INT_AK_MASK              0x00000004L
#define CAP_INT_STATUS__CAP0_BUF1_INT_AK                   0x00000004L
#define CAP_INT_STATUS__CAP0_BUF1_EVEN_INT_MASK            0x00000008L
#define CAP_INT_STATUS__CAP0_BUF1_EVEN_INT                 0x00000008L
#define CAP_INT_STATUS__CAP0_BUF1_EVEN_INT_AK_MASK         0x00000008L
#define CAP_INT_STATUS__CAP0_BUF1_EVEN_INT_AK              0x00000008L
#define CAP_INT_STATUS__CAP0_VBI0_INT_MASK                 0x00000010L
#define CAP_INT_STATUS__CAP0_VBI0_INT                      0x00000010L
#define CAP_INT_STATUS__CAP0_VBI0_INT_AK_MASK              0x00000010L
#define CAP_INT_STATUS__CAP0_VBI0_INT_AK                   0x00000010L
#define CAP_INT_STATUS__CAP0_VBI1_INT_MASK                 0x00000020L
#define CAP_INT_STATUS__CAP0_VBI1_INT                      0x00000020L
#define CAP_INT_STATUS__CAP0_VBI1_INT_AK_MASK              0x00000020L
#define CAP_INT_STATUS__CAP0_VBI1_INT_AK                   0x00000020L
#define CAP_INT_STATUS__CAP0_ONESHOT_INT_MASK              0x00000040L
#define CAP_INT_STATUS__CAP0_ONESHOT_INT                   0x00000040L
#define CAP_INT_STATUS__CAP0_ONESHOT_INT_AK_MASK           0x00000040L
#define CAP_INT_STATUS__CAP0_ONESHOT_INT_AK                0x00000040L

// FCP_CNTL
#define FCP_CNTL__FCP0_SRC_SEL_MASK                        0x00000007L

// CAP0_BUF0_OFFSET
#define CAP0_BUF0_OFFSET__CAP_BUF0_OFFSET_MASK             0xffffffffL

// CAP0_BUF1_OFFSET
#define CAP0_BUF1_OFFSET__CAP_BUF1_OFFSET_MASK             0xffffffffL

// CAP0_BUF0_EVEN_OFFSET
#define CAP0_BUF0_EVEN_OFFSET__CAP_BUF0_EVEN_OFFSET_MASK   0xffffffffL

// CAP0_BUF1_EVEN_OFFSET
#define CAP0_BUF1_EVEN_OFFSET__CAP_BUF1_EVEN_OFFSET_MASK   0xffffffffL

// CAP0_BUF_PITCH
#define CAP0_BUF_PITCH__CAP_BUF_PITCH_MASK                 0x00000fffL

// CAP0_V_WINDOW
#define CAP0_V_WINDOW__CAP_V_START_MASK                    0x00000fffL
#define CAP0_V_WINDOW__CAP_V_END_MASK                      0x0fff0000L

// CAP0_H_WINDOW
#define CAP0_H_WINDOW__CAP_H_START_MASK                    0x00000fffL
#define CAP0_H_WINDOW__CAP_H_WIDTH_MASK                    0x0fff0000L

// CAP0_VBI0_OFFSET
#define CAP0_VBI0_OFFSET__CAP_VBI0_OFFSET_MASK             0xffffffffL

// CAP0_VBI1_OFFSET
#define CAP0_VBI1_OFFSET__CAP_VBI1_OFFSET_MASK             0xffffffffL

// CAP0_VBI_V_WINDOW
#define CAP0_VBI_V_WINDOW__CAP_VBI_V_START_MASK            0x00000fffL
#define CAP0_VBI_V_WINDOW__CAP_VBI_V_END_MASK              0x0fff0000L

// CAP0_VBI_H_WINDOW
#define CAP0_VBI_H_WINDOW__CAP_VBI_H_START_MASK            0x00000fffL
#define CAP0_VBI_H_WINDOW__CAP_VBI_H_WIDTH_MASK            0x0fff0000L

// CAP0_PORT_MODE_CNTL
#define CAP0_PORT_MODE_CNTL__CAP_PORT_WIDTH_MASK           0x00000002L
#define CAP0_PORT_MODE_CNTL__CAP_PORT_WIDTH                0x00000002L
#define CAP0_PORT_MODE_CNTL__CAP_PORT_BYTE_USED_MASK       0x00000004L
#define CAP0_PORT_MODE_CNTL__CAP_PORT_BYTE_USED            0x00000004L

// CAP0_TRIG_CNTL
#define CAP0_TRIG_CNTL__CAP_TRIGGER_R_MASK                 0x00000003L
#define CAP0_TRIG_CNTL__CAP_TRIGGER_W_MASK                 0x00000001L
#define CAP0_TRIG_CNTL__CAP_TRIGGER_W                      0x00000001L
#define CAP0_TRIG_CNTL__CAP_EN_MASK                        0x00000010L
#define CAP0_TRIG_CNTL__CAP_EN                             0x00000010L
#define CAP0_TRIG_CNTL__CAP_VSYNC_CNT_MASK                 0x0000ff00L
#define CAP0_TRIG_CNTL__CAP_VSYNC_CLR_MASK                 0x00010000L
#define CAP0_TRIG_CNTL__CAP_VSYNC_CLR                      0x00010000L

// CAP0_DEBUG
#define CAP0_DEBUG__CAP_H_STATUS_MASK                      0x00000fffL
#define CAP0_DEBUG__CAP_V_STATUS_MASK                      0x0fff0000L
#define CAP0_DEBUG__CAP_V_SYNC_MASK                        0x10000000L
#define CAP0_DEBUG__CAP_V_SYNC                             0x10000000L
#define CAP0_DEBUG__CAP_BUF_OVERFLOW_STATUS_MASK           0x20000000L
#define CAP0_DEBUG__CAP_BUF_OVERFLOW_STATUS                0x20000000L
#define CAP0_DEBUG__CAP_BUF_OVERFLOW_CLR_MASK              0x40000000L
#define CAP0_DEBUG__CAP_BUF_OVERFLOW_CLR                   0x40000000L

// CAP0_CONFIG
#define CAP0_CONFIG__CAP_INPUT_MODE_MASK                   0x00000001L
#define CAP0_CONFIG__CAP_INPUT_MODE                        0x00000001L
#define CAP0_CONFIG__CAP_START_FIELD_MASK                  0x00000002L
#define CAP0_CONFIG__CAP_START_FIELD                       0x00000002L
#define CAP0_CONFIG__CAP_START_BUF_R_MASK                  0x00000004L
#define CAP0_CONFIG__CAP_START_BUF_R                       0x00000004L
#define CAP0_CONFIG__CAP_START_BUF_W_MASK                  0x00000008L
#define CAP0_CONFIG__CAP_START_BUF_W                       0x00000008L
#define CAP0_CONFIG__CAP_BUF_TYPE_MASK                     0x00000030L
#define CAP0_CONFIG__CAP_ONESHOT_MODE_MASK                 0x00000040L
#define CAP0_CONFIG__CAP_ONESHOT_MODE                      0x00000040L
#define CAP0_CONFIG__CAP_BUF_MODE_MASK                     0x00000180L
#define CAP0_CONFIG__CAP_MIRROR_EN_MASK                    0x00000200L
#define CAP0_CONFIG__CAP_MIRROR_EN                         0x00000200L
#define CAP0_CONFIG__CAP_ONESHOT_MIRROR_EN_MASK            0x00000400L
#define CAP0_CONFIG__CAP_ONESHOT_MIRROR_EN                 0x00000400L
#define CAP0_CONFIG__CAP_VIDEO_SIGNED_UV_MASK              0x00000800L
#define CAP0_CONFIG__CAP_VIDEO_SIGNED_UV                   0x00000800L
#define CAP0_CONFIG__CAP_VBI_EN_MASK                       0x00002000L
#define CAP0_CONFIG__CAP_VBI_EN                            0x00002000L
#define CAP0_CONFIG__CAP_SOFT_PULL_DOWN_EN_MASK            0x00004000L
#define CAP0_CONFIG__CAP_SOFT_PULL_DOWN_EN                 0x00004000L
#define CAP0_CONFIG__CAP_VIP_EXTEND_FLAG_EN_MASK           0x00008000L
#define CAP0_CONFIG__CAP_VIP_EXTEND_FLAG_EN                0x00008000L
#define CAP0_CONFIG__CAP_FAKE_FIELD_EN_MASK                0x00010000L
#define CAP0_CONFIG__CAP_FAKE_FIELD_EN                     0x00010000L
#define CAP0_CONFIG__CAP_FIELD_START_LINE_DIFF_MASK        0x00060000L
#define CAP0_CONFIG__CAP_HORZ_DOWN_MASK                    0x00180000L
#define CAP0_CONFIG__CAP_VERT_DOWN_MASK                    0x00600000L
#define CAP0_CONFIG__CAP_STREAM_FORMAT_MASK                0x03800000L
#define CAP0_CONFIG__CAP_HDWNS_DEC_MASK                    0x04000000L
#define CAP0_CONFIG__CAP_HDWNS_DEC                         0x04000000L
#define CAP0_CONFIG__CAP_VIDEO_IN_FORMAT_MASK              0x20000000L
#define CAP0_CONFIG__CAP_VIDEO_IN_FORMAT                   0x20000000L
#define CAP0_CONFIG__VBI_HORZ_DOWN_MASK                    0xc0000000L

// CAP0_VIDEO_SYNC_TEST
#define CAP0_VIDEO_SYNC_TEST__CAP_TEST_VID_SOF_MASK        0x00000001L
#define CAP0_VIDEO_SYNC_TEST__CAP_TEST_VID_SOF             0x00000001L
#define CAP0_VIDEO_SYNC_TEST__CAP_TEST_VID_EOF_MASK        0x00000002L
#define CAP0_VIDEO_SYNC_TEST__CAP_TEST_VID_EOF             0x00000002L
#define CAP0_VIDEO_SYNC_TEST__CAP_TEST_VID_EOL_MASK        0x00000004L
#define CAP0_VIDEO_SYNC_TEST__CAP_TEST_VID_EOL             0x00000004L
#define CAP0_VIDEO_SYNC_TEST__CAP_TEST_VID_FIELD_MASK      0x00000008L
#define CAP0_VIDEO_SYNC_TEST__CAP_TEST_VID_FIELD           0x00000008L
#define CAP0_VIDEO_SYNC_TEST__CAP_TEST_SYNC_EN_MASK        0x00000020L
#define CAP0_VIDEO_SYNC_TEST__CAP_TEST_SYNC_EN             0x00000020L

// CAP0_ONESHOT_BUF_OFFSET
#define CAP0_ONESHOT_BUF_OFFSET__CAP_ONESHOT_BUF_OFFSET_MASK 0xffffffffL

// CAP0_BUF_STATUS
#define CAP0_BUF_STATUS__CAP_PRE_VID_BUF_MASK              0x00000003L
#define CAP0_BUF_STATUS__CAP_CUR_VID_BUF_MASK              0x0000000cL
#define CAP0_BUF_STATUS__CAP_PRE_FIELD_MASK                0x00000010L
#define CAP0_BUF_STATUS__CAP_PRE_FIELD                     0x00000010L
#define CAP0_BUF_STATUS__CAP_CUR_FIELD_MASK                0x00000020L
#define CAP0_BUF_STATUS__CAP_CUR_FIELD                     0x00000020L
#define CAP0_BUF_STATUS__CAP_PRE_VBI_BUF_MASK              0x000000c0L
#define CAP0_BUF_STATUS__CAP_CUR_VBI_BUF_MASK              0x00000300L
#define CAP0_BUF_STATUS__CAP_VBI_BUF_STATUS_MASK           0x00000400L
#define CAP0_BUF_STATUS__CAP_VBI_BUF_STATUS                0x00000400L
#define CAP0_BUF_STATUS__CAP_VIP_INC_MASK                  0x10000000L
#define CAP0_BUF_STATUS__CAP_VIP_INC                       0x10000000L
#define CAP0_BUF_STATUS__CAP_VIP_PRE_REPEAT_FIELD_MASK     0x20000000L
#define CAP0_BUF_STATUS__CAP_VIP_PRE_REPEAT_FIELD          0x20000000L
#define CAP0_BUF_STATUS__CAP_CAP_BUF_STATUS_MASK           0x40000000L
#define CAP0_BUF_STATUS__CAP_CAP_BUF_STATUS                0x40000000L

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

// PPLL_REF_DIV
#define PPLL_REF_DIV__PPLL_REF_DIV_MASK                    0x000003ffL
#define PPLL_REF_DIV__PPLL_ATOMIC_UPDATE_W_MASK            0x00008000L
#define PPLL_REF_DIV__PPLL_ATOMIC_UPDATE_W                 0x00008000L
#define PPLL_REF_DIV__PPLL_ATOMIC_UPDATE_R_MASK            0x00008000L
#define PPLL_REF_DIV__PPLL_ATOMIC_UPDATE_R                 0x00008000L
#define PPLL_REF_DIV__PPLL_REF_DIV_SRC_MASK                0x00030000L

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

// PWRMAN_MISC
#define PWRMAN_MISC__EN_MC_IDLE_COND_MASK                  0x00000001L
#define PWRMAN_MISC__EN_MC_IDLE_COND                       0x00000001L
#define PWRMAN_MISC__MC_IDLE_LAT_MASK                      0x00000006L
#define PWRMAN_MISC__EN_STOP_IMPORT_CLKS_IN_SUSPEND_MASK   0x00000008L
#define PWRMAN_MISC__EN_STOP_IMPORT_CLKS_IN_SUSPEND        0x00000008L
#define PWRMAN_MISC__CG_SPARE_B_MASK                       0x03ff0000L
#define PWRMAN_MISC__CG_SPARE_RD_B_MASK                    0xfc000000L

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

// P2PLL_REF_DIV
#define P2PLL_REF_DIV__P2PLL_REF_DIV_MASK                  0x000003ffL
#define P2PLL_REF_DIV__P2PLL_ATOMIC_UPDATE_W_MASK          0x00008000L
#define P2PLL_REF_DIV__P2PLL_ATOMIC_UPDATE_W               0x00008000L
#define P2PLL_REF_DIV__P2PLL_ATOMIC_UPDATE_R_MASK          0x00008000L
#define P2PLL_REF_DIV__P2PLL_ATOMIC_UPDATE_R               0x00008000L
#define P2PLL_REF_DIV__P2PLL_REF_DIV_SRC_MASK              0x00030000L

// CG_TEST_MACRO_RW_WRITE_U1
#define CG_TEST_MACRO_RW_WRITE_U1__TEST_MACRO_RW_WRITE1_MASK 0x00003fffL
#define CG_TEST_MACRO_RW_WRITE_U1__TEST_MACRO_RW_WRITE2_MASK 0x0fffc000L

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
#define CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_ENABLE_MASK 0x00010000L
#define CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_ENABLE     0x00010000L
#define CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_SCLK_NEG_ENABLE_MASK 0x00020000L
#define CG_TEST_MACRO_RW_CNTL_U1__TEST_MACRO_RW_SCLK_NEG_ENABLE 0x00020000L

// SCLK_MORE_CNTL
#define SCLK_MORE_CNTL__DISPREGS_MAX_DYN_STOP_LAT_MASK     0x00000001L
#define SCLK_MORE_CNTL__DISPREGS_MAX_DYN_STOP_LAT          0x00000001L
#define SCLK_MORE_CNTL__FORCE_DISPREGS_MASK                0x00000100L
#define SCLK_MORE_CNTL__FORCE_DISPREGS                     0x00000100L
#define SCLK_MORE_CNTL__EN_SLOW_DOWN_SCLK_MASK             0x00010000L
#define SCLK_MORE_CNTL__EN_SLOW_DOWN_SCLK                  0x00010000L
#define SCLK_MORE_CNTL__EN_VOLTAGE_DROP_MASK               0x00020000L
#define SCLK_MORE_CNTL__EN_VOLTAGE_DROP                    0x00020000L
#define SCLK_MORE_CNTL__IO_CG_VOLTAGE_DROP_OE_MASK         0x00040000L
#define SCLK_MORE_CNTL__IO_CG_VOLTAGE_DROP_OE              0x00040000L
#define SCLK_MORE_CNTL__EN_CLK27M_FOR_PLL_MASK             0x00080000L
#define SCLK_MORE_CNTL__EN_CLK27M_FOR_PLL                  0x00080000L
#define SCLK_MORE_CNTL__CG_SPARE_C_MASK                    0x00f00000L
#define SCLK_MORE_CNTL__CG_SPARE_RD_C_MASK                 0xff000000L

// CLK_PWRMGT_CNTL_M6
#define CLK_PWRMGT_CNTL_M6__SPLL_PWRMGT_OFF_MASK           0x00000002L
#define CLK_PWRMGT_CNTL_M6__SPLL_PWRMGT_OFF                0x00000002L
#define CLK_PWRMGT_CNTL_M6__PPLL_PWRMGT_OFF_MASK           0x00000004L
#define CLK_PWRMGT_CNTL_M6__PPLL_PWRMGT_OFF                0x00000004L
#define CLK_PWRMGT_CNTL_M6__P2PLL_PWRMGT_OFF_MASK          0x00000008L
#define CLK_PWRMGT_CNTL_M6__P2PLL_PWRMGT_OFF               0x00000008L
#define CLK_PWRMGT_CNTL_M6__SCLK_TURNOFF_MASK              0x00000020L
#define CLK_PWRMGT_CNTL_M6__SCLK_TURNOFF                   0x00000020L
#define CLK_PWRMGT_CNTL_M6__PCLK_TURNOFF_MASK              0x00000040L
#define CLK_PWRMGT_CNTL_M6__PCLK_TURNOFF                   0x00000040L
#define CLK_PWRMGT_CNTL_M6__P2CLK_TURNOFF_MASK             0x00000080L
#define CLK_PWRMGT_CNTL_M6__P2CLK_TURNOFF                  0x00000080L
#define CLK_PWRMGT_CNTL_M6__TEST_MODE_MASK                 0x00000200L
#define CLK_PWRMGT_CNTL_M6__TEST_MODE                      0x00000200L
#define CLK_PWRMGT_CNTL_M6__GLOBAL_PMAN_EN_MASK            0x00000400L
#define CLK_PWRMGT_CNTL_M6__GLOBAL_PMAN_EN                 0x00000400L
#define CLK_PWRMGT_CNTL_M6__ENGINE_DYNCLK_MODE_MASK        0x00001000L
#define CLK_PWRMGT_CNTL_M6__ENGINE_DYNCLK_MODE             0x00001000L
#define CLK_PWRMGT_CNTL_M6__ACTIVE_HILO_LAT_MASK           0x00006000L
#define CLK_PWRMGT_CNTL_M6__DISP_DYN_STOP_LAT_MASK         0x00008000L
#define CLK_PWRMGT_CNTL_M6__DISP_DYN_STOP_LAT              0x00008000L
#define CLK_PWRMGT_CNTL_M6__DISP_PM_MASK                   0x00100000L
#define CLK_PWRMGT_CNTL_M6__DISP_PM                        0x00100000L
#define CLK_PWRMGT_CNTL_M6__DYN_STOP_MODE_MASK             0x00e00000L
#define CLK_PWRMGT_CNTL_M6__CG_NO1_DEBUG_MASK              0x3f000000L
#define CLK_PWRMGT_CNTL_M6__TVPLL_PWRMGT_OFF_MASK          0x40000000L
#define CLK_PWRMGT_CNTL_M6__TVPLL_PWRMGT_OFF               0x40000000L
#define CLK_PWRMGT_CNTL_M6__TVCLK_TURNOFF_MASK             0x80000000L
#define CLK_PWRMGT_CNTL_M6__TVCLK_TURNOFF                  0x80000000L

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
#define NB_COMMAND__AD_STEPPING_MASK                       0x00000080L
#define NB_COMMAND__AD_STEPPING                            0x00000080L
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

// NB_CAPABILITIES_PTR
#define NB_CAPABILITIES_PTR__CAP_PTR_MASK                  0x000000ffL

// NB_CFG_SLOT1
#define NB_CFG_SLOT1__IOQ2_DEEP_ENABLE_MASK                0x00000800L
#define NB_CFG_SLOT1__IOQ2_DEEP_ENABLE                     0x00000800L
#define NB_CFG_SLOT1__IOQ3_DEEP_ENABLE_MASK                0x00001000L
#define NB_CFG_SLOT1__IOQ3_DEEP_ENABLE                     0x00001000L
#define NB_CFG_SLOT1__IOQ4_OR_MORE_DEEP_ENABLE_MASK        0x00002000L
#define NB_CFG_SLOT1__IOQ4_OR_MORE_DEEP_ENABLE             0x00002000L
#define NB_CFG_SLOT1__DEFER_ENABLE_MASK                    0x00010000L
#define NB_CFG_SLOT1__DEFER_ENABLE                         0x00010000L
#define NB_CFG_SLOT1__IOQ1_DEEP_ENABLE_MASK                0x00020000L
#define NB_CFG_SLOT1__IOQ1_DEEP_ENABLE                     0x00020000L
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

// NB_CFG_S2K

// NB_PII_HW_DEBUG
#define NB_PII_HW_DEBUG__PENTIUM_INTERFACE_DEBUG_MASK      0xffffffffL

// NB_EX_BIU_CTRL
#define NB_EX_BIU_CTRL__FID_EN_MASK                        0x00000001L
#define NB_EX_BIU_CTRL__FID_EN                             0x00000001L
#define NB_EX_BIU_CTRL__FID_4_MASK                         0x00000002L
#define NB_EX_BIU_CTRL__FID_4                              0x00000002L
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

// NB_S2K_COMP
#define NB_S2K_COMP__BYPASS_ENABLE_MASK                    0x00000010L
#define NB_S2K_COMP__BYPASS_ENABLE                         0x00000010L
#define NB_S2K_COMP__SLEW_CNTL_MASK                        0x000000e0L
#define NB_S2K_COMP__BYP_N_MASK                            0x00000f00L
#define NB_S2K_COMP__BYP_P_MASK                            0x0000f000L

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
#define NB_BIU_CTRL__RD_2_WR_MASK                          0x00000003L
#define NB_BIU_CTRL__WR_2_RD_MASK                          0x00000004L
#define NB_BIU_CTRL__WR_2_RD                               0x00000004L
#define NB_BIU_CTRL__SYS_DC_IN_DLY_MASK                    0x00000078L
#define NB_BIU_CTRL__SYS_DC_OUT_DLY_MASK                   0x00000180L
#define NB_BIU_CTRL__BYPASS_ENABLE_MASK                    0x00000200L
#define NB_BIU_CTRL__BYPASS_ENABLE                         0x00000200L
#define NB_BIU_CTRL__ACK_LIMIT_MASK                        0x00003c00L
#define NB_BIU_CTRL__PRB_LIMIT_MASK                        0x0001c000L
#define NB_BIU_CTRL__STP_GRANT_DISCON_EN_MASK              0x00020000L
#define NB_BIU_CTRL__STP_GRANT_DISCON_EN                   0x00020000L
#define NB_BIU_CTRL__HALT_DISCON_EN_MASK                   0x00040000L
#define NB_BIU_CTRL__HALT_DISCON_EN                        0x00040000L
#define NB_BIU_CTRL__XCA_WRITE_CNT_MASK                    0x00380000L
#define NB_BIU_CTRL__XCA_READ_CNT_MASK                     0x01c00000L
#define NB_BIU_CTRL__XCA_PROBE_CNT_MASK                    0x0e000000L
#define NB_BIU_CTRL__LOCK_HALF_PRB_MASK                    0x10000000L
#define NB_BIU_CTRL__LOCK_HALF_PRB                         0x10000000L
#define NB_BIU_CTRL__LOCK_HALF_M2C_MASK                    0x20000000L
#define NB_BIU_CTRL__LOCK_HALF_M2C                         0x20000000L
#define NB_BIU_CTRL__LOCK_HALF_C2M_MASK                    0x40000000L
#define NB_BIU_CTRL__LOCK_HALF_C2M                         0x40000000L
#define NB_BIU_CTRL__PROBE_EN_MASK                         0x80000000L
#define NB_BIU_CTRL__PROBE_EN                              0x80000000L

// NB_BIU_SIP
#define NB_BIU_SIP__SYS_ADDR_REC_MUX_PRE_LD_MASK           0x00000007L
#define NB_BIU_SIP__SYS_DATA_REC_MUX_PRE_LD_MASK           0x00000038L
#define NB_BIU_SIP__SYS_RST_CLOCK_OFFSET_MASK              0x000000c0L
#define NB_BIU_SIP__SYS_ADDR_CLOCK_DELAY_MASK              0x00000700L
#define NB_BIU_SIP__SYS_DC_DELAY_MASK                      0x00007800L
#define NB_BIU_SIP__SYS_ADDRESS_DELAY_MASK                 0x00018000L
#define NB_BIU_SIP__SYS_DATA_ODD_DELAY_MASK                0x00060000L
#define NB_BIU_SIP__SYS_DATA_EVEN_DELAY_MASK               0x00180000L
#define NB_BIU_SIP__SYS_DATA_ODD_CLK_DELAY_MASK            0x00e00000L
#define NB_BIU_SIP__SYS_DATA_EVEN_CLK_DELAY_MASK           0x07000000L
#define NB_BIU_SIP__ADDR_INIT_COUNT_MASK                   0x18000000L
#define NB_BIU_SIP__DATA_INIT_COUNT_MASK                   0x60000000L
#define NB_BIU_SIP__CLOCK_FWD_OFFSET_MASK                  0x80000000L
#define NB_BIU_SIP__CLOCK_FWD_OFFSET                       0x80000000L

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
#define NB_EXSMRAM__EXTSMM_CACHE_EN_MASK                   0x00000020L
#define NB_EXSMRAM__EXTSMM_CACHE_EN                        0x00000020L
#define NB_EXSMRAM__EX_SMRAM_ERROR_MASK                    0x00000040L
#define NB_EXSMRAM__EX_SMRAM_ERROR                         0x00000040L
#define NB_EXSMRAM__HI_SMRAM_ENABLE_MASK                   0x00000080L
#define NB_EXSMRAM__HI_SMRAM_ENABLE                        0x00000080L

// NB_PMCR
#define NB_PMCR__ACPI_CTL_REG_EN_MASK                      0x00000001L
#define NB_PMCR__ACPI_CTL_REG_EN                           0x00000001L

// NB_STRAP_READ_BACK_S2K
#define NB_STRAP_READ_BACK_S2K__AGP_enable_MASK            0x00000001L
#define NB_STRAP_READ_BACK_S2K__AGP_enable                 0x00000001L
#define NB_STRAP_READ_BACK_S2K__NBStrap_MASK               0x00000002L
#define NB_STRAP_READ_BACK_S2K__NBStrap                    0x00000002L
#define NB_STRAP_READ_BACK_S2K__CalDefaults_MASK           0x00000004L
#define NB_STRAP_READ_BACK_S2K__CalDefaults                0x00000004L
#define NB_STRAP_READ_BACK_S2K__PCI66Mode_MASK             0x00000008L
#define NB_STRAP_READ_BACK_S2K__PCI66Mode                  0x00000008L
#define NB_STRAP_READ_BACK_S2K__FP_ID_3_0_MASK             0x000000f0L
#define NB_STRAP_READ_BACK_S2K__OutclkDelay_Enable_MASK    0x00000100L
#define NB_STRAP_READ_BACK_S2K__OutclkDelay_Enable         0x00000100L
#define NB_STRAP_READ_BACK_S2K__Reserved5_MASK             0x00000600L
#define NB_STRAP_READ_BACK_S2K__On_Chip_Clock_Generator_MASK 0x00000800L
#define NB_STRAP_READ_BACK_S2K__On_Chip_Clock_Generator    0x00000800L
#define NB_STRAP_READ_BACK_S2K__FP_ID_4_MASK               0x00001000L
#define NB_STRAP_READ_BACK_S2K__FP_ID_4                    0x00001000L
#define NB_STRAP_READ_BACK_S2K__Reserved4_MASK             0x00002000L
#define NB_STRAP_READ_BACK_S2K__Reserved4                  0x00002000L
#define NB_STRAP_READ_BACK_S2K__Slot1_S2K_MASK             0x0000c000L
#define NB_STRAP_READ_BACK_S2K__FID_MASK                   0x000f0000L
#define NB_STRAP_READ_BACK_S2K__PCICLKExp_MASK             0x00100000L
#define NB_STRAP_READ_BACK_S2K__PCICLKExp                  0x00100000L
#define NB_STRAP_READ_BACK_S2K__SkewAdjust_MASK            0x00e00000L
#define NB_STRAP_READ_BACK_S2K__Inclk_Delay_Enable_MASK    0x01000000L
#define NB_STRAP_READ_BACK_S2K__Inclk_Delay_Enable         0x01000000L
#define NB_STRAP_READ_BACK_S2K__Reserved1_MASK             0x02000000L
#define NB_STRAP_READ_BACK_S2K__Reserved1                  0x02000000L
#define NB_STRAP_READ_BACK_S2K__Len_MASK                   0x0c000000L
#define NB_STRAP_READ_BACK_S2K__Enable_SS_MASK             0x10000000L
#define NB_STRAP_READ_BACK_S2K__Enable_SS                  0x10000000L
#define NB_STRAP_READ_BACK_S2K__Reserved0_MASK             0x20000000L
#define NB_STRAP_READ_BACK_S2K__Reserved0                  0x20000000L
#define NB_STRAP_READ_BACK_S2K__ClkSpeed_MASK              0xc0000000L

// NB_STRAP_READ_BACK_SLOT1
#define NB_STRAP_READ_BACK_SLOT1__AGP_enable_MASK          0x00000001L
#define NB_STRAP_READ_BACK_SLOT1__AGP_enable               0x00000001L
#define NB_STRAP_READ_BACK_SLOT1__NBStrap_MASK             0x00000002L
#define NB_STRAP_READ_BACK_SLOT1__NBStrap                  0x00000002L
#define NB_STRAP_READ_BACK_SLOT1__CalDefaults_MASK         0x00000004L
#define NB_STRAP_READ_BACK_SLOT1__CalDefaults              0x00000004L
#define NB_STRAP_READ_BACK_SLOT1__PCI66Mode_MASK           0x00000008L
#define NB_STRAP_READ_BACK_SLOT1__PCI66Mode                0x00000008L
#define NB_STRAP_READ_BACK_SLOT1__FP_ID_3_0_MASK           0x000000f0L
#define NB_STRAP_READ_BACK_SLOT1__OutclkDelay_Enable_MASK  0x00000100L
#define NB_STRAP_READ_BACK_SLOT1__OutclkDelay_Enable       0x00000100L
#define NB_STRAP_READ_BACK_SLOT1__Reserved5_MASK           0x00000600L
#define NB_STRAP_READ_BACK_SLOT1__On_Chip_Clock_Generator_MASK 0x00000800L
#define NB_STRAP_READ_BACK_SLOT1__On_Chip_Clock_Generator  0x00000800L
#define NB_STRAP_READ_BACK_SLOT1__FP_ID_4_MASK             0x00001000L
#define NB_STRAP_READ_BACK_SLOT1__FP_ID_4                  0x00001000L
#define NB_STRAP_READ_BACK_SLOT1__Reserved4_MASK           0x00002000L
#define NB_STRAP_READ_BACK_SLOT1__Reserved4                0x00002000L
#define NB_STRAP_READ_BACK_SLOT1__Slot1_S2K_MASK           0x0000c000L
#define NB_STRAP_READ_BACK_SLOT1__FID_MASK                 0x000f0000L
#define NB_STRAP_READ_BACK_SLOT1__PCICLKExp_MASK           0x00100000L
#define NB_STRAP_READ_BACK_SLOT1__PCICLKExp                0x00100000L
#define NB_STRAP_READ_BACK_SLOT1__SkewAdjust_MASK          0x00e00000L
#define NB_STRAP_READ_BACK_SLOT1__NBStrap_In_MASK          0x07000000L
#define NB_STRAP_READ_BACK_SLOT1__Reserved2_MASK           0x08000000L
#define NB_STRAP_READ_BACK_SLOT1__Reserved2                0x08000000L
#define NB_STRAP_READ_BACK_SLOT1__Enable_SS_MASK           0x10000000L
#define NB_STRAP_READ_BACK_SLOT1__Enable_SS                0x10000000L
#define NB_STRAP_READ_BACK_SLOT1__Reserved0_MASK           0x20000000L
#define NB_STRAP_READ_BACK_SLOT1__Reserved0                0x20000000L
#define NB_STRAP_READ_BACK_SLOT1__ClkSpeed_MASK            0xc0000000L

// NB_MC_CNTL
#define NB_MC_CNTL__Reserved0_MASK                         0x00000001L
#define NB_MC_CNTL__Reserved0                              0x00000001L
#define NB_MC_CNTL__DISABLE_CPU_MASK                       0x00000002L
#define NB_MC_CNTL__DISABLE_CPU                            0x00000002L
#define NB_MC_CNTL__DISABLE_PCI_MASK                       0x00000008L
#define NB_MC_CNTL__DISABLE_PCI                            0x00000008L
#define NB_MC_CNTL__DISABLE_AGP_MASK                       0x00000010L
#define NB_MC_CNTL__DISABLE_AGP                            0x00000010L
#define NB_MC_CNTL__Reserved1_MASK                         0x000001e0L
#define NB_MC_CNTL__PCI_BLK_WR_EN_MASK                     0x00000200L
#define NB_MC_CNTL__PCI_BLK_WR_EN                          0x00000200L
#define NB_MC_CNTL__PCI_PIPE_EN_MASK                       0x00000400L
#define NB_MC_CNTL__PCI_PIPE_EN                            0x00000400L
#define NB_MC_CNTL__MWQ_REQ_DISABLE_MASK                   0x00002000L
#define NB_MC_CNTL__MWQ_REQ_DISABLE                        0x00002000L
#define NB_MC_CNTL__MRQ_0_REQ_DISABLE_MASK                 0x00004000L
#define NB_MC_CNTL__MRQ_0_REQ_DISABLE                      0x00004000L
#define NB_MC_CNTL__MRQ_1_REQ_DISABLE_MASK                 0x00008000L
#define NB_MC_CNTL__MRQ_1_REQ_DISABLE                      0x00008000L
#define NB_MC_CNTL__MRQ_2_REQ_DISABLE_MASK                 0x00010000L
#define NB_MC_CNTL__MRQ_2_REQ_DISABLE                      0x00010000L
#define NB_MC_CNTL__MRQ_3_REQ_DISABLE_MASK                 0x00020000L
#define NB_MC_CNTL__MRQ_3_REQ_DISABLE                      0x00020000L
#define NB_MC_CNTL__SELF_RF_DIS_MASK                       0x00040000L
#define NB_MC_CNTL__SELF_RF_DIS                            0x00040000L
#define NB_MC_CNTL__DISABLE_BYPASS_MASK                    0x00080000L
#define NB_MC_CNTL__DISABLE_BYPASS                         0x00080000L
#define NB_MC_CNTL__REJECT_BYPASS_MASK                     0x00100000L
#define NB_MC_CNTL__REJECT_BYPASS                          0x00100000L
#define NB_MC_CNTL__SEQ_ARB_MODE_MASK                      0x00200000L
#define NB_MC_CNTL__SEQ_ARB_MODE                           0x00200000L
#define NB_MC_CNTL__Reserved2_MASK                         0x00400000L
#define NB_MC_CNTL__Reserved2                              0x00400000L
#define NB_MC_CNTL__MEM_DYNAMIC_CKE_MASK                   0x00800000L
#define NB_MC_CNTL__MEM_DYNAMIC_CKE                        0x00800000L
#define NB_MC_CNTL__MEM_SDRAM_TRI_EN_MASK                  0x01000000L
#define NB_MC_CNTL__MEM_SDRAM_TRI_EN                       0x01000000L
#define NB_MC_CNTL__MEM_DYN_REC_CTRL_MASK                  0x02000000L
#define NB_MC_CNTL__MEM_DYN_REC_CTRL                       0x02000000L
#define NB_MC_CNTL__MC_FAST_FSB_MASK                       0x04000000L
#define NB_MC_CNTL__MC_FAST_FSB                            0x04000000L
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

// NB_SCRATCH
#define NB_SCRATCH__NB_SCRATCH_BITS_MASK                   0xffffffffL

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
#define NB_CFG_STAT__SIP_ROM_ENABLED_MASK                  0x00000080L
#define NB_CFG_STAT__SIP_ROM_ENABLED                       0x00000080L
#define NB_CFG_STAT__S2K0_BUS_LENGTH_MASK                  0x00030000L
#define NB_CFG_STAT__CLOCK_SPEED_MASK                      0x00300000L
#define NB_CFG_STAT__TYPE_DETECTED_MASK                    0x02000000L
#define NB_CFG_STAT__TYPE_DETECTED                         0x02000000L
#define NB_CFG_STAT__SYS_CLK_MUX_MASK                      0x1c000000L
#define NB_CFG_STAT__AGP_CLK_MUX_MASK                      0xe0000000L

// NB_GC_STRAPS
#define NB_GC_STRAPS__AGP_ENABLE_MASK                      0x00000001L
#define NB_GC_STRAPS__AGP_ENABLE                           0x00000001L
#define NB_GC_STRAPS__GC_ENABLE_MASK                       0x00000002L
#define NB_GC_STRAPS__GC_ENABLE                            0x00000002L
#define NB_GC_STRAPS__POWER_ON_STRAPS_VGA_DISABLE_MASK     0x00000004L
#define NB_GC_STRAPS__POWER_ON_STRAPS_VGA_DISABLE          0x00000004L
#define NB_GC_STRAPS__POWER_ON_STRAPS_ID_DISABLE_MASK      0x00000008L
#define NB_GC_STRAPS__POWER_ON_STRAPS_ID_DISABLE           0x00000008L
#define NB_GC_STRAPS__POWER_ON_STRAPS_APERATURE_SIZE_MASK  0x00000030L
#define NB_GC_STRAPS__POWER_ON_STRAPS_4_29_MASK            0xffffffc0L

// NB_TOP_OF_DRAM_SLOT1
#define NB_TOP_OF_DRAM_SLOT1__TOP_OF_DRAM_MASK             0x7f800000L

// NB_TOP_OF_DRAM_S2K

// NB_AGP_CAP_ID
#define NB_AGP_CAP_ID__CAP_ID_MASK                         0x000000ffL
#define NB_AGP_CAP_ID__NEXT_PTR_MASK                       0x0000ff00L
#define NB_AGP_CAP_ID__AGP_MINOR_MASK                      0x000f0000L
#define NB_AGP_CAP_ID__AGP_MAJOR_MASK                      0x00f00000L

// NB_AGP_STATUS
#define NB_AGP_STATUS__RATE1X_MASK                         0x00000001L
#define NB_AGP_STATUS__RATE1X                              0x00000001L
#define NB_AGP_STATUS__RATE2X_MASK                         0x00000002L
#define NB_AGP_STATUS__RATE2X                              0x00000002L
#define NB_AGP_STATUS__RATE4X_MASK                         0x00000004L
#define NB_AGP_STATUS__RATE4X                              0x00000004L
#define NB_AGP_STATUS__FW_MASK                             0x00000010L
#define NB_AGP_STATUS__FW                                  0x00000010L
#define NB_AGP_STATUS__R4G_MASK                            0x00000020L
#define NB_AGP_STATUS__R4G                                 0x00000020L
#define NB_AGP_STATUS__SBA_MASK                            0x00000200L
#define NB_AGP_STATUS__SBA                                 0x00000200L
#define NB_AGP_STATUS__RQ_MASK                             0xff000000L

// NB_AGP_COMMAND
#define NB_AGP_COMMAND__DATA_RATE_MASK                     0x00000007L
#define NB_AGP_COMMAND__FW_EN_MASK                         0x00000010L
#define NB_AGP_COMMAND__FW_EN                              0x00000010L
#define NB_AGP_COMMAND__R4G_EN_MASK                        0x00000020L
#define NB_AGP_COMMAND__R4G_EN                             0x00000020L
#define NB_AGP_COMMAND__AGP_EN_MASK                        0x00000100L
#define NB_AGP_COMMAND__AGP_EN                             0x00000100L
#define NB_AGP_COMMAND__SBA_EN_MASK                        0x00000200L
#define NB_AGP_COMMAND__SBA_EN                             0x00000200L

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

// NB_MEM_SIZE
#define NB_MEM_SIZE__CS0_SIZE_MASK                         0x00000007L
#define NB_MEM_SIZE__CS0_AP_MAP_MASK                       0x00000030L
#define NB_MEM_SIZE__CS1_SIZE_MASK                         0x00000700L
#define NB_MEM_SIZE__CS1_AP_MAP_MASK                       0x00003000L
#define NB_MEM_SIZE__CS2_SIZE_MASK                         0x00070000L
#define NB_MEM_SIZE__CS2_AP_MAP_MASK                       0x00300000L
#define NB_MEM_SIZE__CS3_SIZE_MASK                         0x07000000L
#define NB_MEM_SIZE__CS3_AP_MAP_MASK                       0x30000000L

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
#define NB_MEM_CNTL0__Reserved_MASK                        0xff000000L

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
#define NB_MC_DEBUG__SEQ_HOLE_DISABLE_MASK                 0x00000001L
#define NB_MC_DEBUG__SEQ_HOLE_DISABLE                      0x00000001L
#define NB_MC_DEBUG__DISABLE_AP_MASK                       0x00000004L
#define NB_MC_DEBUG__DISABLE_AP                            0x00000004L
#define NB_MC_DEBUG__RBS_STALL_FIFO_MASK                   0x00000008L
#define NB_MC_DEBUG__RBS_STALL_FIFO                        0x00000008L
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
#define NB_MEM_SDRAM_MODE_REG__MEM_MODE_REG_MASK           0x00007fffL
#define NB_MEM_SDRAM_MODE_REG__Reserved0_MASK              0x000f8000L
#define NB_MEM_SDRAM_MODE_REG__MEM_CAS_LATENCY_MASK        0x00700000L
#define NB_MEM_SDRAM_MODE_REG__Reserved1_MASK              0x0f800000L
#define NB_MEM_SDRAM_MODE_REG__MC_INIT_COMPLETE_MASK       0x10000000L
#define NB_MEM_SDRAM_MODE_REG__MC_INIT_COMPLETE            0x10000000L
#define NB_MEM_SDRAM_MODE_REG__Reserved2_MASK              0x20000000L
#define NB_MEM_SDRAM_MODE_REG__Reserved2                   0x20000000L
#define NB_MEM_SDRAM_MODE_REG__MEM_CFG_TYPE_MASK           0x40000000L
#define NB_MEM_SDRAM_MODE_REG__MEM_CFG_TYPE                0x40000000L
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

// NB_MC_STATUS
#define NB_MC_STATUS__MEM_PWRUP_COMPL_A_MASK               0x00000001L
#define NB_MC_STATUS__MEM_PWRUP_COMPL_A                    0x00000001L
#define NB_MC_STATUS__MEM_PWRUP_COMPL_B_MASK               0x00000002L
#define NB_MC_STATUS__MEM_PWRUP_COMPL_B                    0x00000002L
#define NB_MC_STATUS__MC_IDLE_MASK                         0x00000004L
#define NB_MC_STATUS__MC_IDLE                              0x00000004L
#define NB_MC_STATUS__SYSM_IDLE_MASK                       0x00010000L
#define NB_MC_STATUS__SYSM_IDLE                            0x00010000L
#define NB_MC_STATUS__SYSM_SHUTDOWN_MASK                   0x00020000L
#define NB_MC_STATUS__SYSM_SHUTDOWN                        0x00020000L
#define NB_MC_STATUS__SYSM_PARKED_MASK                     0x00040000L
#define NB_MC_STATUS__SYSM_PARKED                          0x00040000L
#define NB_MC_STATUS__DLL_READY_MASK                       0x00080000L
#define NB_MC_STATUS__DLL_READY                            0x00080000L

// NB_MEM_START
#define NB_MEM_START__CS0_START_MASK                       0x000000ffL
#define NB_MEM_START__CS1_START_MASK                       0x0000ff00L
#define NB_MEM_START__CS2_START_MASK                       0x00ff0000L
#define NB_MEM_START__CS3_START_MASK                       0xff000000L

// NB_MEM_CSB_START
#define NB_MEM_CSB_START__CHB_CS0_START_MASK               0x000000ffL
#define NB_MEM_CSB_START__CHB_CS1_START_MASK               0x0000ff00L
#define NB_MEM_CSB_START__CHB_CS2_START_MASK               0x00ff0000L
#define NB_MEM_CSB_START__CHB_CS3_START_MASK               0xff000000L

// NB_CFG_PI_PERF_CTL_A
#define NB_CFG_PI_PERF_CTL_A__CFG_PI_PERF_CTL_A_MASK       0x0000001fL

// NB_CFG_PI_PERF_CTL_B
#define NB_CFG_PI_PERF_CTL_B__CFG_PI_PERF_CTL_B_MASK       0x0000001fL

// NB_PI_CFG_PERF_DATA_A
#define NB_PI_CFG_PERF_DATA_A__PI_CFG_PERF_DATA_A_MASK     0xffffffffL

// NB_PI_CFG_PERF_DATA_B
#define NB_PI_CFG_PERF_DATA_B__PI_CFG_PERF_DATA_B_MASK     0xffffffffL

// NB_CPU_AUTOCAL_VAL
#define NB_CPU_AUTOCAL_VAL__CPU_AUTOCAL_VAL_P_MASK         0x0000001fL
#define NB_CPU_AUTOCAL_VAL__CPU_AUTOCAL_VAL_N_MASK         0x00001f00L

// NB_CPU_AUTOCAL_CTL
#define NB_CPU_AUTOCAL_CTL__CPU_AUTOCAL_P_OE_MASK          0x00000001L
#define NB_CPU_AUTOCAL_CTL__CPU_AUTOCAL_P_OE               0x00000001L
#define NB_CPU_AUTOCAL_CTL__CPU_AUTOCAL_P_PD_MASK          0x00000002L
#define NB_CPU_AUTOCAL_CTL__CPU_AUTOCAL_P_PD               0x00000002L
#define NB_CPU_AUTOCAL_CTL__CPU_AUTOCAL_N_OE_MASK          0x00000004L
#define NB_CPU_AUTOCAL_CTL__CPU_AUTOCAL_N_OE               0x00000004L
#define NB_CPU_AUTOCAL_CTL__CPU_AUTOCAL_N_PD_MASK          0x00000008L
#define NB_CPU_AUTOCAL_CTL__CPU_AUTOCAL_N_PD               0x00000008L

// NB_AGP_CAL_DEFAULT
#define NB_AGP_CAL_DEFAULT__AGP_LO_DEFAULT_VAL_P_MASK      0x0000000fL
#define NB_AGP_CAL_DEFAULT__AGP_LO_DEFAULT_VAL_N_MASK      0x000000f0L
#define NB_AGP_CAL_DEFAULT__AGP_HI_DEFAULT_VAL_P_MASK      0x00000f00L
#define NB_AGP_CAL_DEFAULT__AGP_HI_DEFAULT_VAL_N_MASK      0x0000f000L

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
#define SPLL_CONTROL__SPLL_BYPASS_MASK                     0x10000000L
#define SPLL_CONTROL__SPLL_BYPASS                          0x10000000L
#define SPLL_CONTROL__SPLL_POWERDOWN_DLY_MASK              0x60000000L
#define SPLL_CONTROL__SPLL_POWERDOWN_MASK                  0x80000000L
#define SPLL_CONTROL__SPLL_POWERDOWN                       0x80000000L

// MPLL_CONTROL
#define MPLL_CONTROL__MPLL_BYPASS_MASK                     0x10000000L
#define MPLL_CONTROL__MPLL_BYPASS                          0x10000000L
#define MPLL_CONTROL__MPLL_POWERDOWN_DLY_MASK              0x60000000L
#define MPLL_CONTROL__MPLL_POWERDOWN_MASK                  0x80000000L
#define MPLL_CONTROL__MPLL_POWERDOWN                       0x80000000L

// BPLL_CONTROL
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

// MC_CLK_CNTRL
#define MC_CLK_CNTRL__MC_CLKSPEED_MASK                     0x00000003L
#define MC_CLK_CNTRL__MC_USE_CLKSPEED_MASK                 0x00000004L
#define MC_CLK_CNTRL__MC_USE_CLKSPEED                      0x00000004L
#define MC_CLK_CNTRL__GEARRATIO_MS_MASK                    0x00000018L
#define MC_CLK_CNTRL__GEARRATIO_BS_MASK                    0x00000060L
#define MC_CLK_CNTRL__FORCE_GEARRATIO_RECALC_MASK          0x00000080L
#define MC_CLK_CNTRL__FORCE_GEARRATIO_RECALC               0x00000080L

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

// MC_DATA_DLL_CNTRL_A
#define MC_DATA_DLL_CNTRL_A__DLL_DA_IN_TRIM0_MASK          0x0000000fL
#define MC_DATA_DLL_CNTRL_A__DLL_DA_OUT_TRIM0_MASK         0x000000f0L
#define MC_DATA_DLL_CNTRL_A__DLL_DA_IN_TRIM1_MASK          0x00000f00L
#define MC_DATA_DLL_CNTRL_A__DLL_DA_OUT_TRIM1_MASK         0x0000f000L
#define MC_DATA_DLL_CNTRL_A__DLL_DA_IN_TRIM2_MASK          0x000f0000L
#define MC_DATA_DLL_CNTRL_A__DLL_DA_OUT_TRIM2_MASK         0x00f00000L
#define MC_DATA_DLL_CNTRL_A__DLL_DA_IN_TRIM3_MASK          0x0f000000L
#define MC_DATA_DLL_CNTRL_A__DLL_DA_OUT_TRIM3_MASK         0xf0000000L

// MC_DATA_DLL_CNTRL_B
#define MC_DATA_DLL_CNTRL_B__DLL_DB_IN_TRIM0_MASK          0x0000000fL
#define MC_DATA_DLL_CNTRL_B__DLL_DB_OUT_TRIM0_MASK         0x000000f0L
#define MC_DATA_DLL_CNTRL_B__DLL_DB_IN_TRIM1_MASK          0x00000f00L
#define MC_DATA_DLL_CNTRL_B__DLL_DB_OUT_TRIM1_MASK         0x0000f000L
#define MC_DATA_DLL_CNTRL_B__DLL_DB_IN_TRIM2_MASK          0x000f0000L
#define MC_DATA_DLL_CNTRL_B__DLL_DB_OUT_TRIM2_MASK         0x00f00000L
#define MC_DATA_DLL_CNTRL_B__DLL_DB_IN_TRIM3_MASK          0x0f000000L
#define MC_DATA_DLL_CNTRL_B__DLL_DB_OUT_TRIM3_MASK         0xf0000000L

// MC_ACMD_DLL_CNTRL_A
#define MC_ACMD_DLL_CNTRL_A__DLL_CA_IN_TRIM_MASK           0x0000000fL
#define MC_ACMD_DLL_CNTRL_A__DLL_CA_OUT_TRIM_MASK          0x000000f0L

// MC_ACMD_DLL_CNTRL_B
#define MC_ACMD_DLL_CNTRL_B__DLL_CB_IN_TRIM_MASK           0x0000000fL
#define MC_ACMD_DLL_CNTRL_B__DLL_CB_OUT_TRIM_MASK          0x000000f0L

// EXT_PCICLK_STOP_CNTRL
#define EXT_PCICLK_STOP_CNTRL__PCICLK0_STOP_MODE_MASK      0x00000007L
#define EXT_PCICLK_STOP_CNTRL__PCICLK1_STOP_MODE_MASK      0x00000038L
#define EXT_PCICLK_STOP_CNTRL__PCICLK2_STOP_MODE_MASK      0x000001c0L
#define EXT_PCICLK_STOP_CNTRL__PCICLK3_STOP_MODE_MASK      0x00000e00L
#define EXT_PCICLK_STOP_CNTRL__PCICLK4_STOP_MODE_MASK      0x00007000L

// CLKGATE_DISABLE
#define CLKGATE_DISABLE__CLKGATE_DIS_MCA_MASK              0x00000001L
#define CLKGATE_DISABLE__CLKGATE_DIS_MCA                   0x00000001L
#define CLKGATE_DISABLE__CLKGATE_DIS_MCB_MASK              0x00000002L
#define CLKGATE_DISABLE__CLKGATE_DIS_MCB                   0x00000002L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC1_MASK              0x00000004L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC1                   0x00000004L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC2_MASK              0x00000008L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC2                   0x00000008L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC3_MASK              0x00000010L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC3                   0x00000010L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC4_MASK              0x00000020L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC4                   0x00000020L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC5_MASK              0x00000040L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC5                   0x00000040L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC6_MASK              0x00000080L
#define CLKGATE_DISABLE__CLKGATE_DIS_MC6                   0x00000080L
#define CLKGATE_DISABLE__CLKGATE_DIS_MCG_MASK              0x00000100L
#define CLKGATE_DISABLE__CLKGATE_DIS_MCG                   0x00000100L
#define CLKGATE_DISABLE__CLKGATE_DIS_RAMCLK_MASK           0x00000200L
#define CLKGATE_DISABLE__CLKGATE_DIS_RAMCLK                0x00000200L
#define CLKGATE_DISABLE__CLKGATE_DIS_BIU_MEM_MASK          0x00000400L
#define CLKGATE_DISABLE__CLKGATE_DIS_BIU_MEM               0x00000400L
#define CLKGATE_DISABLE__CLKGATE_DIS_BIU_S2K_MASK          0x00000800L
#define CLKGATE_DISABLE__CLKGATE_DIS_BIU_S2K               0x00000800L
#define CLKGATE_DISABLE__CLKGATE_DIS_BIU_PII_MASK          0x00001000L
#define CLKGATE_DISABLE__CLKGATE_DIS_BIU_PII               0x00001000L
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
#define CLKGATE_DISABLE__CLKGATE_DIS_PCI_P1X_MASK          0x00800000L
#define CLKGATE_DISABLE__CLKGATE_DIS_PCI_P1X               0x00800000L
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

// SSPLL_CONFIG1
#define SSPLL_CONFIG1__SSPLL_F_MASK                        0x0000ffffL

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
#define APC_COMMAND__AD_STEPPING_MASK                      0x00000080L
#define APC_COMMAND__AD_STEPPING                           0x00000080L
#define APC_COMMAND__SERR_EN_MASK                          0x00000100L
#define APC_COMMAND__SERR_EN                               0x00000100L
#define APC_COMMAND__FAST_B2B_EN_MASK                      0x00000200L
#define APC_COMMAND__FAST_B2B_EN                           0x00000200L

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


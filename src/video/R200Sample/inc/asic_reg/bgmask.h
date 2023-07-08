

#if !defined (_bridget_MASK_HEADER)
#define _bridget_MASK_HEADER
/*
*	bridget_mask.h
*
*	Register Spec Release:  Chip Spec 1.15
*
*
*	 (c) 2000 ATI Technologies Inc.  (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
*/

// VENDOR_ID
#define VENDOR_ID__VENDOR_ID_MASK                          0x0000ffffL

// DEVICE_ID
#define DEVICE_ID__DEVICE_ID_MASK                          0x0000ffffL

// DEVICE_ID_Y
#define DEVICE_ID_Y__DEVICE_ID_MASK                        0x0000ffffL

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

// P2PB_COMMAND_Y
#define P2PB_COMMAND_Y__IO_ACCESS_EN_MASK                  0x00000001L
#define P2PB_COMMAND_Y__IO_ACCESS_EN                       0x00000001L
#define P2PB_COMMAND_Y__MEM_ACCESS_EN_MASK                 0x00000002L
#define P2PB_COMMAND_Y__MEM_ACCESS_EN                      0x00000002L
#define P2PB_COMMAND_Y__BUS_MASTER_EN_MASK                 0x00000004L
#define P2PB_COMMAND_Y__BUS_MASTER_EN                      0x00000004L
#define P2PB_COMMAND_Y__SPECIAL_CYCLE_EN_MASK              0x00000008L
#define P2PB_COMMAND_Y__SPECIAL_CYCLE_EN                   0x00000008L
#define P2PB_COMMAND_Y__MEM_WRITE_INVALIDATE_EN_MASK       0x00000010L
#define P2PB_COMMAND_Y__MEM_WRITE_INVALIDATE_EN            0x00000010L
#define P2PB_COMMAND_Y__PAL_SNOOP_EN_MASK                  0x00000020L
#define P2PB_COMMAND_Y__PAL_SNOOP_EN                       0x00000020L
#define P2PB_COMMAND_Y__PARITY_ERROR_EN_MASK               0x00000040L
#define P2PB_COMMAND_Y__PARITY_ERROR_EN                    0x00000040L
#define P2PB_COMMAND_Y__AD_STEPPING_MASK                   0x00000080L
#define P2PB_COMMAND_Y__AD_STEPPING                        0x00000080L
#define P2PB_COMMAND_Y__SERR_EN_MASK                       0x00000100L
#define P2PB_COMMAND_Y__SERR_EN                            0x00000100L
#define P2PB_COMMAND_Y__FAST_B2B_EN_MASK                   0x00000200L
#define P2PB_COMMAND_Y__FAST_B2B_EN                        0x00000200L

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

// P2PB_STATUS_Y
#define P2PB_STATUS_Y__CAP_LIST_MASK                       0x00000010L
#define P2PB_STATUS_Y__CAP_LIST                            0x00000010L
#define P2PB_STATUS_Y__PCI_66_EN_MASK                      0x00000020L
#define P2PB_STATUS_Y__PCI_66_EN                           0x00000020L
#define P2PB_STATUS_Y__UDF_EN_MASK                         0x00000040L
#define P2PB_STATUS_Y__UDF_EN                              0x00000040L
#define P2PB_STATUS_Y__FAST_BACK_CAPABLE_MASK              0x00000080L
#define P2PB_STATUS_Y__FAST_BACK_CAPABLE                   0x00000080L
#define P2PB_STATUS_Y__DEVSEL_TIMING_MASK                  0x00000600L
#define P2PB_STATUS_Y__SIGNAL_TARGET_ABORT_MASK            0x00000800L
#define P2PB_STATUS_Y__SIGNAL_TARGET_ABORT                 0x00000800L
#define P2PB_STATUS_Y__RECEIVED_TARGET_ABORT_MASK          0x00001000L
#define P2PB_STATUS_Y__RECEIVED_TARGET_ABORT               0x00001000L
#define P2PB_STATUS_Y__RECEIVED_MASTER_ABORT_MASK          0x00002000L
#define P2PB_STATUS_Y__RECEIVED_MASTER_ABORT               0x00002000L
#define P2PB_STATUS_Y__SIGNALED_SYSTEM_ERROR_MASK          0x00004000L
#define P2PB_STATUS_Y__SIGNALED_SYSTEM_ERROR               0x00004000L
#define P2PB_STATUS_Y__PARITY_ERROR_DETECTED_MASK          0x00008000L
#define P2PB_STATUS_Y__PARITY_ERROR_DETECTED               0x00008000L

// REVISION_ID
#define REVISION_ID__MINOR_REV_ID_MASK                     0x0000000fL
#define REVISION_ID__MAJOR_REV_ID_MASK                     0x000000f0L

// REGPROG_INF
#define REGPROG_INF__REG_LEVEL_PROG_INF_MASK               0x000000ffL

// SUB_CLASS_BG
#define SUB_CLASS_BG__SUB_CLASS_INF_MASK                   0x000000ffL

// BASE_CODE
#define BASE_CODE__BASE_CLASS_CODE_MASK                    0x000000ffL

// CACHE_LINE
#define CACHE_LINE__CACHE_LINE_SIZE_MASK                   0x000000ffL

// P2PB_CACHE_LINE_Y
#define P2PB_CACHE_LINE_Y__CACHE_LINE_SIZE_MASK            0x000000ffL

// LATENCY
#define LATENCY__LATENCY_TIMER_MASK                        0x000000ffL

// P2PB_LATENCY_Y
#define P2PB_LATENCY_Y__LATENCY_TIMER_MASK                 0x000000ffL

// HEADER_BG
#define HEADER_BG__P2PB_MODE_MASK                          0x00000001L
#define HEADER_BG__P2PB_MODE                               0x00000001L
#define HEADER_BG__HEADER_TYPE_MASK                        0x0000007eL
#define HEADER_BG__DEVICE_TYPE_MASK                        0x00000080L
#define HEADER_BG__DEVICE_TYPE                             0x00000080L

// HEADER_Y
#define HEADER_Y__P2PB_MODE_MASK                           0x00000001L
#define HEADER_Y__P2PB_MODE                                0x00000001L
#define HEADER_Y__HEADER_TYPE_MASK                         0x0000007eL
#define HEADER_Y__DEVICE_TYPE_MASK                         0x00000080L
#define HEADER_Y__DEVICE_TYPE                              0x00000080L

// BIST
#define BIST__BIST_COMP_MASK                               0x0000000fL
#define BIST__BIST_STRT_MASK                               0x00000040L
#define BIST__BIST_STRT                                    0x00000040L
#define BIST__BIST_CAP_MASK                                0x00000080L
#define BIST__BIST_CAP                                     0x00000080L

// BAR10REG
#define BAR10REG__BAR10REG_MASK                            0xffffffffL

// BAR14REG
#define BAR14REG__BAR14REG_MASK                            0xffffffffL

// BAR18REG
#define BAR18REG__BAR18REG_MASK                            0xffffffffL

// P2PB_BUSNUM_Y
#define P2PB_BUSNUM_Y__PRI_BUSNUM_MASK                     0x000000ffL
#define P2PB_BUSNUM_Y__SEC_BUSNUM_MASK                     0x0000ff00L
#define P2PB_BUSNUM_Y__SUB_BUSNUM_MASK                     0x00ff0000L
#define P2PB_BUSNUM_Y__SEC_LAT_TIMER_MASK                  0xff000000L

// BAR1CREG
#define BAR1CREG__BAR1CREG_MASK                            0xffffffffL

// P2PB_IO_BASE_Y
#define P2PB_IO_BASE_Y__IO_BASE_CAP_MASK                   0x00000001L
#define P2PB_IO_BASE_Y__IO_BASE_CAP                        0x00000001L
#define P2PB_IO_BASE_Y__IO_BASE_ADDR_MASK                  0x000000f0L
#define P2PB_IO_BASE_Y__IO_LIMT_CAP_MASK                   0x00000100L
#define P2PB_IO_BASE_Y__IO_LIMT_CAP                        0x00000100L
#define P2PB_IO_BASE_Y__IO_LIMT_ADDR_MASK                  0x0000f000L
#define P2PB_IO_BASE_Y__PCI_66_EN_MASK                     0x00200000L
#define P2PB_IO_BASE_Y__PCI_66_EN                          0x00200000L
#define P2PB_IO_BASE_Y__FAST_BACK_CAPABLE_MASK             0x00800000L
#define P2PB_IO_BASE_Y__FAST_BACK_CAPABLE                  0x00800000L
#define P2PB_IO_BASE_Y__MASTER_DATA_PARITY_ERROR_MASK      0x01000000L
#define P2PB_IO_BASE_Y__MASTER_DATA_PARITY_ERROR           0x01000000L
#define P2PB_IO_BASE_Y__DEVSEL_TIMING_MASK                 0x06000000L
#define P2PB_IO_BASE_Y__SIGNAL_TARGET_ABORT_MASK           0x08000000L
#define P2PB_IO_BASE_Y__SIGNAL_TARGET_ABORT                0x08000000L
#define P2PB_IO_BASE_Y__RECEIVED_TARGET_ABORT_MASK         0x10000000L
#define P2PB_IO_BASE_Y__RECEIVED_TARGET_ABORT              0x10000000L
#define P2PB_IO_BASE_Y__RECEIVED_MASTER_ABORT_MASK         0x20000000L
#define P2PB_IO_BASE_Y__RECEIVED_MASTER_ABORT              0x20000000L
#define P2PB_IO_BASE_Y__RECEIVED_SYSTEM_ERROR_MASK         0x40000000L
#define P2PB_IO_BASE_Y__RECEIVED_SYSTEM_ERROR              0x40000000L
#define P2PB_IO_BASE_Y__PARITY_ERROR_DETECTED_MASK         0x80000000L
#define P2PB_IO_BASE_Y__PARITY_ERROR_DETECTED              0x80000000L

// BAR20REG
#define BAR20REG__BAR20REG_MASK                            0xffffffffL

// P2PB_MEM_BASE_Y
#define P2PB_MEM_BASE_Y__MEM_BASE_MASK                     0x0000fff0L
#define P2PB_MEM_BASE_Y__MEM_LIMIT_MASK                    0xfff00000L

// BAR24REG
#define BAR24REG__BAR24REG_MASK                            0xffffffffL

// P2PB_PREFETCH_MEM_BASE_Y
#define P2PB_PREFETCH_MEM_BASE_Y__PREFETCH_MEM_BASE_MASK   0x0000fff0L
#define P2PB_PREFETCH_MEM_BASE_Y__PREFETCH_MEM_LIMIT_MASK  0xfff00000L

// BAR30REG
#define BAR30REG__BAR30REG_MASK                            0xffffffffL

// IO_BASE_UPPER_16BITS_Y
#define IO_BASE_UPPER_16BITS_Y__IO_BASE_UPPER_16BITS_MASK  0x0000ffffL

// IO_LIMIT_UPPER_16BITS_Y
#define IO_LIMIT_UPPER_16BITS_Y__IO_LIMIT_UPPER_16BITS_MASK 0x0000ffffL

// BAR38REG
#define BAR38REG__BAR38REG_MASK                            0xffffffffL

// CAPABILITIES_PTR
#define CAPABILITIES_PTR__CAP_PTR_MASK                     0x000000ffL

// CAPABILITIES_PTR_Y
#define CAPABILITIES_PTR_Y__CAP_PTR_MASK                   0x000000ffL

// INTERRUPT_LINE
#define INTERRUPT_LINE__INTERRUPT_LINE_MASK                0x000000ffL

// P2PB_INTERRUPT_LINE_Y
#define P2PB_INTERRUPT_LINE_Y__INTERRUPT_LINE_MASK         0x000000ffL

// INTERRUPT_PIN
#define INTERRUPT_PIN__INTERRUPT_PIN_MASK                  0x00000001L
#define INTERRUPT_PIN__INTERRUPT_PIN                       0x00000001L

// BRIDGE_CONTROL_X
#define BRIDGE_CONTROL_X__BAR3EREG_MASK                    0x0000ffffL

// BRIDGE_CONTROL_Y
#define BRIDGE_CONTROL_Y__PERR_EN_Y_MASK                   0x00000001L
#define BRIDGE_CONTROL_Y__PERR_EN_Y                        0x00000001L
#define BRIDGE_CONTROL_Y__SERR_EN_Y_MASK                   0x00000002L
#define BRIDGE_CONTROL_Y__SERR_EN_Y                        0x00000002L
#define BRIDGE_CONTROL_Y__ISA_EN_Y_MASK                    0x00000004L
#define BRIDGE_CONTROL_Y__ISA_EN_Y                         0x00000004L
#define BRIDGE_CONTROL_Y__VGA_EN_Y_MASK                    0x00000008L
#define BRIDGE_CONTROL_Y__VGA_EN_Y                         0x00000008L
#define BRIDGE_CONTROL_Y__MASTER_ABORT_MODE_Y_MASK         0x00000020L
#define BRIDGE_CONTROL_Y__MASTER_ABORT_MODE_Y              0x00000020L
#define BRIDGE_CONTROL_Y__SEC_BUS_RESET_Y_MASK             0x00000040L
#define BRIDGE_CONTROL_Y__SEC_BUS_RESET_Y                  0x00000040L
#define BRIDGE_CONTROL_Y__FAST_B2B_EN_Y_MASK               0x00000080L
#define BRIDGE_CONTROL_Y__FAST_B2B_EN_Y                    0x00000080L
#define BRIDGE_CONTROL_Y__PRIM_DISCARD_TIMER_Y_MASK        0x00000100L
#define BRIDGE_CONTROL_Y__PRIM_DISCARD_TIMER_Y             0x00000100L
#define BRIDGE_CONTROL_Y__SEC_DISCARD_TIMER_Y_MASK         0x00000200L
#define BRIDGE_CONTROL_Y__SEC_DISCARD_TIMER_Y              0x00000200L
#define BRIDGE_CONTROL_Y__DISCARD_TIMER_STATUS_Y_MASK      0x00000400L
#define BRIDGE_CONTROL_Y__DISCARD_TIMER_STATUS_Y           0x00000400L
#define BRIDGE_CONTROL_Y__DISCARD_TIMER_SERR_EN_Y_MASK     0x00000800L
#define BRIDGE_CONTROL_Y__DISCARD_TIMER_SERR_EN_Y          0x00000800L

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

// PM_STATUS_Y
#define PM_STATUS_Y__PMI_POWER_STATE_MASK                  0x00000003L
#define PM_STATUS_Y__PMI_PME_EN_MASK                       0x00000100L
#define PM_STATUS_Y__PMI_PME_EN                            0x00000100L
#define PM_STATUS_Y__PMI_DATA_SELECT_MASK                  0x00001e00L
#define PM_STATUS_Y__PMI_DATA_SCALE_MASK                   0x00006000L
#define PM_STATUS_Y__PMI_PME_STATUS_MASK                   0x00008000L
#define PM_STATUS_Y__PMI_PME_STATUS                        0x00008000L

// PMCSR_BSE
#define PMCSR_BSE__B2_B3b_MASK                             0x00000040L
#define PMCSR_BSE__B2_B3b                                  0x00000040L
#define PMCSR_BSE__BPCC_EN_MASK                            0x00000080L
#define PMCSR_BSE__BPCC_EN                                 0x00000080L

// PMCSR_BSE_Y
#define PMCSR_BSE_Y__B2_B3b_MASK                           0x00000040L
#define PMCSR_BSE_Y__B2_B3b                                0x00000040L
#define PMCSR_BSE_Y__BPCC_EN_MASK                          0x00000080L
#define PMCSR_BSE_Y__BPCC_EN                               0x00000080L

// PMI_DATA
#define PMI_DATA__PMI_DATA_MASK                            0x000000ffL

// AGP_CAP_ID
#define AGP_CAP_ID__CAP_ID_MASK                            0x000000ffL
#define AGP_CAP_ID__NEXT_PTR_MASK                          0x0000ff00L
#define AGP_CAP_ID__AGP_MINOR_MASK                         0x000f0000L
#define AGP_CAP_ID__AGP_MAJOR_MASK                         0x00f00000L

// AGP_CAP_ID_Y
#define AGP_CAP_ID_Y__CAP_ID_MASK                          0x000000ffL
#define AGP_CAP_ID_Y__NEXT_PTR_MASK                        0x0000ff00L
#define AGP_CAP_ID_Y__AGP_MINOR_MASK                       0x000f0000L
#define AGP_CAP_ID_Y__AGP_MAJOR_MASK                       0x00f00000L

// AGP_STATUS
#define AGP_STATUS__RATE1X_MASK                            0x00000001L
#define AGP_STATUS__RATE1X                                 0x00000001L
#define AGP_STATUS__RATE2X_MASK                            0x00000002L
#define AGP_STATUS__RATE2X                                 0x00000002L
#define AGP_STATUS__RATE4X_MASK                            0x00000004L
#define AGP_STATUS__RATE4X                                 0x00000004L
#define AGP_STATUS__FW_MASK                                0x00000010L
#define AGP_STATUS__FW                                     0x00000010L
#define AGP_STATUS__MODE_4G_MASK                           0x00000020L
#define AGP_STATUS__MODE_4G                                0x00000020L
#define AGP_STATUS__SBA_MASK                               0x00000200L
#define AGP_STATUS__SBA                                    0x00000200L
#define AGP_STATUS__RQ_MASK                                0xff000000L

// AGP_STATUS_Y
#define AGP_STATUS_Y__RATE1X_MASK                          0x00000001L
#define AGP_STATUS_Y__RATE1X                               0x00000001L
#define AGP_STATUS_Y__RATE2X_MASK                          0x00000002L
#define AGP_STATUS_Y__RATE2X                               0x00000002L
#define AGP_STATUS_Y__RATE4X_MASK                          0x00000004L
#define AGP_STATUS_Y__RATE4X                               0x00000004L
#define AGP_STATUS_Y__FW_MASK                              0x00000010L
#define AGP_STATUS_Y__FW                                   0x00000010L
#define AGP_STATUS_Y__MODE_4G_MASK                         0x00000020L
#define AGP_STATUS_Y__MODE_4G                              0x00000020L
#define AGP_STATUS_Y__SBA_MASK                             0x00000200L
#define AGP_STATUS_Y__SBA                                  0x00000200L
#define AGP_STATUS_Y__RQ_MASK                              0xff000000L

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
#define AGP_COMMAND__RQ_DEPTH_MASK                         0xff000000L

// TYPE1_P2PB_AGP_COMMAND_X
#define TYPE1_P2PB_AGP_COMMAND_X__DATA_RATE_MASK           0x00000007L
#define TYPE1_P2PB_AGP_COMMAND_X__FW_EN_MASK               0x00000010L
#define TYPE1_P2PB_AGP_COMMAND_X__FW_EN                    0x00000010L
#define TYPE1_P2PB_AGP_COMMAND_X__MODE_4G_EN_MASK          0x00000020L
#define TYPE1_P2PB_AGP_COMMAND_X__MODE_4G_EN               0x00000020L
#define TYPE1_P2PB_AGP_COMMAND_X__AGP_EN_MASK              0x00000100L
#define TYPE1_P2PB_AGP_COMMAND_X__AGP_EN                   0x00000100L
#define TYPE1_P2PB_AGP_COMMAND_X__SBA_EN_MASK              0x00000200L
#define TYPE1_P2PB_AGP_COMMAND_X__SBA_EN                   0x00000200L
#define TYPE1_P2PB_AGP_COMMAND_X__RQ_DEPTH_MASK            0xff000000L

// P2PB_AGP_COMMAND_Y
#define P2PB_AGP_COMMAND_Y__DATA_RATE_MASK                 0x00000007L
#define P2PB_AGP_COMMAND_Y__FW_EN_MASK                     0x00000010L
#define P2PB_AGP_COMMAND_Y__FW_EN                          0x00000010L
#define P2PB_AGP_COMMAND_Y__MODE_4G_EN_MASK                0x00000020L
#define P2PB_AGP_COMMAND_Y__MODE_4G_EN                     0x00000020L
#define P2PB_AGP_COMMAND_Y__AGP_EN_MASK                    0x00000100L
#define P2PB_AGP_COMMAND_Y__AGP_EN                         0x00000100L
#define P2PB_AGP_COMMAND_Y__SBA_EN_MASK                    0x00000200L
#define P2PB_AGP_COMMAND_Y__SBA_EN                         0x00000200L
#define P2PB_AGP_COMMAND_Y__RQ_DEPTH_MASK                  0xff000000L

// TYPE1_P2PB_AGP_COMMAND_Y
#define TYPE1_P2PB_AGP_COMMAND_Y__DATA_RATE_MASK           0x00000007L
#define TYPE1_P2PB_AGP_COMMAND_Y__FW_EN_MASK               0x00000010L
#define TYPE1_P2PB_AGP_COMMAND_Y__FW_EN                    0x00000010L
#define TYPE1_P2PB_AGP_COMMAND_Y__MODE_4G_EN_MASK          0x00000020L
#define TYPE1_P2PB_AGP_COMMAND_Y__MODE_4G_EN               0x00000020L
#define TYPE1_P2PB_AGP_COMMAND_Y__AGP_EN_MASK              0x00000100L
#define TYPE1_P2PB_AGP_COMMAND_Y__AGP_EN                   0x00000100L
#define TYPE1_P2PB_AGP_COMMAND_Y__SBA_EN_MASK              0x00000200L
#define TYPE1_P2PB_AGP_COMMAND_Y__SBA_EN                   0x00000200L
#define TYPE1_P2PB_AGP_COMMAND_Y__RQ_DEPTH_MASK            0xff000000L

// BAR10WMASK
#define BAR10WMASK__BAR10WMASK_MASK                        0xffffffffL

// BAR14WMASK
#define BAR14WMASK__BAR14WMASK_MASK                        0xffffffffL

// BAR18WMASK
#define BAR18WMASK__BAR18WMASK_MASK                        0xffffffffL

// BAR1CWMASK
#define BAR1CWMASK__BAR1CWMASK_MASK                        0xffffffffL

// BAR20WMASK
#define BAR20WMASK__BAR20WMASK_MASK                        0xffffffffL

// BAR24WMASK
#define BAR24WMASK__BAR24WMASK_MASK                        0xffffffffL

// BAR30WMASK
#define BAR30WMASK__BAR30WMASK_MASK                        0xffffffffL

// BAR38WMASK
#define BAR38WMASK__BAR38WMASK_MASK                        0xffffffffL

// BAR3EWMASK
#define BAR3EWMASK__BAR3EWMASK_MASK                        0x0000ffffL

// BUS_P_CNTL
#define BUS_P_CNTL__BUS_DBL_RESYNC_MASK                    0x00000001L
#define BUS_P_CNTL__BUS_DBL_RESYNC                         0x00000001L
#define BUS_P_CNTL__BUS_MSTR_RESET_MASK                    0x00000002L
#define BUS_P_CNTL__BUS_MSTR_RESET                         0x00000002L
#define BUS_P_CNTL__BUS_FLUSH_BUF_MASK                     0x00000004L
#define BUS_P_CNTL__BUS_FLUSH_BUF                          0x00000004L
#define BUS_P_CNTL__BUS_STOP_REQ_DIS_MASK                  0x00000008L
#define BUS_P_CNTL__BUS_STOP_REQ_DIS                       0x00000008L
#define BUS_P_CNTL__BUS_READ_COMBINE_EN_MASK               0x00000010L
#define BUS_P_CNTL__BUS_READ_COMBINE_EN                    0x00000010L
#define BUS_P_CNTL__BUS_WRT_COMBINE_EN_MASK                0x00000020L
#define BUS_P_CNTL__BUS_WRT_COMBINE_EN                     0x00000020L
#define BUS_P_CNTL__BUS_MASTER_DIS_MASK                    0x00000040L
#define BUS_P_CNTL__BUS_MASTER_DIS                         0x00000040L
#define BUS_P_CNTL__BIOS_ROM_WRT_EN_MASK                   0x00000080L
#define BUS_P_CNTL__BIOS_ROM_WRT_EN                        0x00000080L
#define BUS_P_CNTL__BUS_PREFETCH_MODE_MASK                 0x00000300L
#define BUS_P_CNTL__BUS_VGA_PREFETCH_EN_MASK               0x00000400L
#define BUS_P_CNTL__BUS_VGA_PREFETCH_EN                    0x00000400L
#define BUS_P_CNTL__BUS_SGL_READ_DISABLE_MASK              0x00000800L
#define BUS_P_CNTL__BUS_SGL_READ_DISABLE                   0x00000800L
#define BUS_P_CNTL__BIOS_DIS_ROM_MASK                      0x00001000L
#define BUS_P_CNTL__BIOS_DIS_ROM                           0x00001000L
#define BUS_P_CNTL__BUS_PCI_READ_RETRY_EN_MASK             0x00002000L
#define BUS_P_CNTL__BUS_PCI_READ_RETRY_EN                  0x00002000L
#define BUS_P_CNTL__BUS_AGP_AD_STEPPING_EN_MASK            0x00004000L
#define BUS_P_CNTL__BUS_AGP_AD_STEPPING_EN                 0x00004000L
#define BUS_P_CNTL__BUS_PCI_WRT_RETRY_EN_MASK              0x00008000L
#define BUS_P_CNTL__BUS_PCI_WRT_RETRY_EN                   0x00008000L
#define BUS_P_CNTL__BUS_RETRY_WS_MASK                      0x000f0000L
#define BUS_P_CNTL__BUS_MSTR_RD_MULT_MASK                  0x00100000L
#define BUS_P_CNTL__BUS_MSTR_RD_MULT                       0x00100000L
#define BUS_P_CNTL__BUS_MSTR_RD_LINE_MASK                  0x00200000L
#define BUS_P_CNTL__BUS_MSTR_RD_LINE                       0x00200000L
#define BUS_P_CNTL__BUS_SUSPEND_MASK                       0x00400000L
#define BUS_P_CNTL__BUS_SUSPEND                            0x00400000L
#define BUS_P_CNTL__LAT_16X_MASK                           0x00800000L
#define BUS_P_CNTL__LAT_16X                                0x00800000L
#define BUS_P_CNTL__BUS_RD_DISCARD_EN_MASK                 0x01000000L
#define BUS_P_CNTL__BUS_RD_DISCARD_EN                      0x01000000L
#define BUS_P_CNTL__ENFRCWRDY_MASK                         0x02000000L
#define BUS_P_CNTL__ENFRCWRDY                              0x02000000L
#define BUS_P_CNTL__BUS_MSTR_WS_MASK                       0x04000000L
#define BUS_P_CNTL__BUS_MSTR_WS                            0x04000000L
#define BUS_P_CNTL__BUS_PARKING_DIS_MASK                   0x08000000L
#define BUS_P_CNTL__BUS_PARKING_DIS                        0x08000000L
#define BUS_P_CNTL__BUS_MSTR_DISCONNECT_EN_MASK            0x10000000L
#define BUS_P_CNTL__BUS_MSTR_DISCONNECT_EN                 0x10000000L
#define BUS_P_CNTL__SERR_EN_MASK                           0x20000000L
#define BUS_P_CNTL__SERR_EN                                0x20000000L
#define BUS_P_CNTL__BUS_READ_BURST_MASK                    0x40000000L
#define BUS_P_CNTL__BUS_READ_BURST                         0x40000000L
#define BUS_P_CNTL__BUS_RDY_READ_DLY_MASK                  0x80000000L
#define BUS_P_CNTL__BUS_RDY_READ_DLY                       0x80000000L

// BUS_X_CNTL
#define BUS_X_CNTL__BUS_DBL_RESYNC_MASK                    0x00000001L
#define BUS_X_CNTL__BUS_DBL_RESYNC                         0x00000001L
#define BUS_X_CNTL__BUS_MSTR_RESET_MASK                    0x00000002L
#define BUS_X_CNTL__BUS_MSTR_RESET                         0x00000002L
#define BUS_X_CNTL__BUS_FLUSH_BUF_MASK                     0x00000004L
#define BUS_X_CNTL__BUS_FLUSH_BUF                          0x00000004L
#define BUS_X_CNTL__BUS_STOP_REQ_DIS_MASK                  0x00000008L
#define BUS_X_CNTL__BUS_STOP_REQ_DIS                       0x00000008L
#define BUS_X_CNTL__BUS_READ_COMBINE_EN_MASK               0x00000010L
#define BUS_X_CNTL__BUS_READ_COMBINE_EN                    0x00000010L
#define BUS_X_CNTL__BUS_WRT_COMBINE_EN_MASK                0x00000020L
#define BUS_X_CNTL__BUS_WRT_COMBINE_EN                     0x00000020L
#define BUS_X_CNTL__BUS_MASTER_DIS_MASK                    0x00000040L
#define BUS_X_CNTL__BUS_MASTER_DIS                         0x00000040L
#define BUS_X_CNTL__BIOS_ROM_WRT_EN_MASK                   0x00000080L
#define BUS_X_CNTL__BIOS_ROM_WRT_EN                        0x00000080L
#define BUS_X_CNTL__BUS_PREFETCH_MODE_MASK                 0x00000300L
#define BUS_X_CNTL__BUS_VGA_PREFETCH_EN_MASK               0x00000400L
#define BUS_X_CNTL__BUS_VGA_PREFETCH_EN                    0x00000400L
#define BUS_X_CNTL__BUS_SGL_READ_DISABLE_MASK              0x00000800L
#define BUS_X_CNTL__BUS_SGL_READ_DISABLE                   0x00000800L
#define BUS_X_CNTL__BIOS_DIS_ROM_MASK                      0x00001000L
#define BUS_X_CNTL__BIOS_DIS_ROM                           0x00001000L
#define BUS_X_CNTL__BUS_PCI_READ_RETRY_EN_MASK             0x00002000L
#define BUS_X_CNTL__BUS_PCI_READ_RETRY_EN                  0x00002000L
#define BUS_X_CNTL__BUS_AGP_AD_STEPPING_EN_MASK            0x00004000L
#define BUS_X_CNTL__BUS_AGP_AD_STEPPING_EN                 0x00004000L
#define BUS_X_CNTL__BUS_PCI_WRT_RETRY_EN_MASK              0x00008000L
#define BUS_X_CNTL__BUS_PCI_WRT_RETRY_EN                   0x00008000L
#define BUS_X_CNTL__BUS_RETRY_WS_MASK                      0x000f0000L
#define BUS_X_CNTL__BUS_MSTR_RD_MULT_MASK                  0x00100000L
#define BUS_X_CNTL__BUS_MSTR_RD_MULT                       0x00100000L
#define BUS_X_CNTL__BUS_MSTR_RD_LINE_MASK                  0x00200000L
#define BUS_X_CNTL__BUS_MSTR_RD_LINE                       0x00200000L
#define BUS_X_CNTL__BUS_SUSPEND_MASK                       0x00400000L
#define BUS_X_CNTL__BUS_SUSPEND                            0x00400000L
#define BUS_X_CNTL__LAT_16X_MASK                           0x00800000L
#define BUS_X_CNTL__LAT_16X                                0x00800000L
#define BUS_X_CNTL__BUS_RD_DISCARD_EN_MASK                 0x01000000L
#define BUS_X_CNTL__BUS_RD_DISCARD_EN                      0x01000000L
#define BUS_X_CNTL__ENFRCWRDY_MASK                         0x02000000L
#define BUS_X_CNTL__ENFRCWRDY                              0x02000000L
#define BUS_X_CNTL__BUS_MSTR_WS_MASK                       0x04000000L
#define BUS_X_CNTL__BUS_MSTR_WS                            0x04000000L
#define BUS_X_CNTL__BUS_PARKING_DIS_MASK                   0x08000000L
#define BUS_X_CNTL__BUS_PARKING_DIS                        0x08000000L
#define BUS_X_CNTL__BUS_MSTR_DISCONNECT_EN_MASK            0x10000000L
#define BUS_X_CNTL__BUS_MSTR_DISCONNECT_EN                 0x10000000L
#define BUS_X_CNTL__SERR_EN_MASK                           0x20000000L
#define BUS_X_CNTL__SERR_EN                                0x20000000L
#define BUS_X_CNTL__BUS_READ_BURST_MASK                    0x40000000L
#define BUS_X_CNTL__BUS_READ_BURST                         0x40000000L
#define BUS_X_CNTL__BUS_RDY_READ_DLY_MASK                  0x80000000L
#define BUS_X_CNTL__BUS_RDY_READ_DLY                       0x80000000L

// BUS_Y_CNTL
#define BUS_Y_CNTL__BUS_DBL_RESYNC_MASK                    0x00000001L
#define BUS_Y_CNTL__BUS_DBL_RESYNC                         0x00000001L
#define BUS_Y_CNTL__BUS_MSTR_RESET_MASK                    0x00000002L
#define BUS_Y_CNTL__BUS_MSTR_RESET                         0x00000002L
#define BUS_Y_CNTL__BUS_FLUSH_BUF_MASK                     0x00000004L
#define BUS_Y_CNTL__BUS_FLUSH_BUF                          0x00000004L
#define BUS_Y_CNTL__BUS_STOP_REQ_DIS_MASK                  0x00000008L
#define BUS_Y_CNTL__BUS_STOP_REQ_DIS                       0x00000008L
#define BUS_Y_CNTL__BUS_READ_COMBINE_EN_MASK               0x00000010L
#define BUS_Y_CNTL__BUS_READ_COMBINE_EN                    0x00000010L
#define BUS_Y_CNTL__BUS_WRT_COMBINE_EN_MASK                0x00000020L
#define BUS_Y_CNTL__BUS_WRT_COMBINE_EN                     0x00000020L
#define BUS_Y_CNTL__BUS_MASTER_DIS_MASK                    0x00000040L
#define BUS_Y_CNTL__BUS_MASTER_DIS                         0x00000040L
#define BUS_Y_CNTL__BIOS_ROM_WRT_EN_MASK                   0x00000080L
#define BUS_Y_CNTL__BIOS_ROM_WRT_EN                        0x00000080L
#define BUS_Y_CNTL__BUS_PREFETCH_MODE_MASK                 0x00000300L
#define BUS_Y_CNTL__BUS_VGA_PREFETCH_EN_MASK               0x00000400L
#define BUS_Y_CNTL__BUS_VGA_PREFETCH_EN                    0x00000400L
#define BUS_Y_CNTL__BUS_SGL_READ_DISABLE_MASK              0x00000800L
#define BUS_Y_CNTL__BUS_SGL_READ_DISABLE                   0x00000800L
#define BUS_Y_CNTL__BIOS_DIS_ROM_MASK                      0x00001000L
#define BUS_Y_CNTL__BIOS_DIS_ROM                           0x00001000L
#define BUS_Y_CNTL__BUS_PCI_READ_RETRY_EN_MASK             0x00002000L
#define BUS_Y_CNTL__BUS_PCI_READ_RETRY_EN                  0x00002000L
#define BUS_Y_CNTL__BUS_AGP_AD_STEPPING_EN_MASK            0x00004000L
#define BUS_Y_CNTL__BUS_AGP_AD_STEPPING_EN                 0x00004000L
#define BUS_Y_CNTL__BUS_PCI_WRT_RETRY_EN_MASK              0x00008000L
#define BUS_Y_CNTL__BUS_PCI_WRT_RETRY_EN                   0x00008000L
#define BUS_Y_CNTL__BUS_RETRY_WS_MASK                      0x000f0000L
#define BUS_Y_CNTL__BUS_MSTR_RD_MULT_MASK                  0x00100000L
#define BUS_Y_CNTL__BUS_MSTR_RD_MULT                       0x00100000L
#define BUS_Y_CNTL__BUS_MSTR_RD_LINE_MASK                  0x00200000L
#define BUS_Y_CNTL__BUS_MSTR_RD_LINE                       0x00200000L
#define BUS_Y_CNTL__BUS_SUSPEND_MASK                       0x00400000L
#define BUS_Y_CNTL__BUS_SUSPEND                            0x00400000L
#define BUS_Y_CNTL__LAT_16X_MASK                           0x00800000L
#define BUS_Y_CNTL__LAT_16X                                0x00800000L
#define BUS_Y_CNTL__BUS_RD_DISCARD_EN_MASK                 0x01000000L
#define BUS_Y_CNTL__BUS_RD_DISCARD_EN                      0x01000000L
#define BUS_Y_CNTL__ENFRCWRDY_MASK                         0x02000000L
#define BUS_Y_CNTL__ENFRCWRDY                              0x02000000L
#define BUS_Y_CNTL__BUS_MSTR_WS_MASK                       0x04000000L
#define BUS_Y_CNTL__BUS_MSTR_WS                            0x04000000L
#define BUS_Y_CNTL__BUS_PARKING_DIS_MASK                   0x08000000L
#define BUS_Y_CNTL__BUS_PARKING_DIS                        0x08000000L
#define BUS_Y_CNTL__BUS_MSTR_DISCONNECT_EN_MASK            0x10000000L
#define BUS_Y_CNTL__BUS_MSTR_DISCONNECT_EN                 0x10000000L
#define BUS_Y_CNTL__SERR_EN_MASK                           0x20000000L
#define BUS_Y_CNTL__SERR_EN                                0x20000000L
#define BUS_Y_CNTL__BUS_READ_BURST_MASK                    0x40000000L
#define BUS_Y_CNTL__BUS_READ_BURST                         0x40000000L
#define BUS_Y_CNTL__BUS_RDY_READ_DLY_MASK                  0x80000000L
#define BUS_Y_CNTL__BUS_RDY_READ_DLY                       0x80000000L

// BUS_P_PAD_CTLR_STRENGTH
#define BUS_P_PAD_CTLR_STRENGTH__PAD_N_STRENGTH_READ_BACK_MASK 0x0000000fL
#define BUS_P_PAD_CTLR_STRENGTH__PAD_P_STRENGTH_READ_BACK_MASK 0x000000f0L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_N_MANUAL_STRENGTH_MASK 0x00000f00L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_P_MANUAL_STRENGTH_MASK 0x0000f000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_MANUAL_OVERRIDE_MASK  0x00010000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_MANUAL_OVERRIDE       0x00010000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_TEST_OUT_MASK         0x00020000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_TEST_OUT              0x00020000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_DUMMY_OUT_MASK        0x00040000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_DUMMY_OUT             0x00040000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_DFR_MASK        0x00080000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_DFR             0x00080000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_SCHMEN_MASK     0x00100000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_SCHMEN          0x00100000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_DREN_MASK       0x00200000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_DREN            0x00200000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_SLEW_MASK       0x00400000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_SLEW            0x00400000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_VDIFF_MASK      0x00800000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_VDIFF           0x00800000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_DFR_OVERRIDE_MASK 0x01000000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_DFR_OVERRIDE    0x01000000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_SCHMEN_OVERRIDE_MASK 0x02000000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_SCHMEN_OVERRIDE 0x02000000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_DREN_OVERRIDE_MASK 0x04000000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_DREN_OVERRIDE   0x04000000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_SLEW_OVERRIDE_MASK 0x08000000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_SLEW_OVERRIDE   0x08000000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_VDIFF_OVERRIDE_MASK 0x10000000L
#define BUS_P_PAD_CTLR_STRENGTH__PAD_HI_IO_VDIFF_OVERRIDE  0x10000000L

// BUS_P_PAD_CTLR_UPDATE
#define BUS_P_PAD_CTLR_UPDATE__PAD_UPDATE_RATE_MASK        0x0000001fL
#define BUS_P_PAD_CTLR_UPDATE__PAD_SAMPLE_DELAY_MASK       0x00001f00L
#define BUS_P_PAD_CTLR_UPDATE__PAD_INC_THRESHOLD_MASK      0x001f0000L
#define BUS_P_PAD_CTLR_UPDATE__PAD_DEC_THRESHOLD_MASK      0x1f000000L

// BUS_X_PAD_CTLR_STRENGTH
#define BUS_X_PAD_CTLR_STRENGTH__PAD_N_STRENGTH_READ_BACK_MASK 0x0000000fL
#define BUS_X_PAD_CTLR_STRENGTH__PAD_P_STRENGTH_READ_BACK_MASK 0x000000f0L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_N_MANUAL_STRENGTH_MASK 0x00000f00L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_P_MANUAL_STRENGTH_MASK 0x0000f000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_MANUAL_OVERRIDE_MASK  0x00010000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_MANUAL_OVERRIDE       0x00010000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_TEST_OUT_MASK         0x00020000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_TEST_OUT              0x00020000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_DUMMY_OUT_MASK        0x00040000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_DUMMY_OUT             0x00040000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_DFR_MASK        0x00080000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_DFR             0x00080000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_SCHMEN_MASK     0x00100000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_SCHMEN          0x00100000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_DREN_MASK       0x00200000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_DREN            0x00200000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_SLEW_MASK       0x00400000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_SLEW            0x00400000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_VDIFF_MASK      0x00800000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_VDIFF           0x00800000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_DFR_OVERRIDE_MASK 0x01000000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_DFR_OVERRIDE    0x01000000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_SCHMEN_OVERRIDE_MASK 0x02000000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_SCHMEN_OVERRIDE 0x02000000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_DREN_OVERRIDE_MASK 0x04000000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_DREN_OVERRIDE   0x04000000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_SLEW_OVERRIDE_MASK 0x08000000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_SLEW_OVERRIDE   0x08000000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_VDIFF_OVERRIDE_MASK 0x10000000L
#define BUS_X_PAD_CTLR_STRENGTH__PAD_HI_IO_VDIFF_OVERRIDE  0x10000000L

// BUS_X_PAD_CTLR_UPDATE
#define BUS_X_PAD_CTLR_UPDATE__PAD_UPDATE_RATE_MASK        0x0000001fL
#define BUS_X_PAD_CTLR_UPDATE__PAD_SAMPLE_DELAY_MASK       0x00001f00L
#define BUS_X_PAD_CTLR_UPDATE__PAD_INC_THRESHOLD_MASK      0x001f0000L
#define BUS_X_PAD_CTLR_UPDATE__PAD_DEC_THRESHOLD_MASK      0x1f000000L

// BUS_Y_PAD_CTLR_STRENGTH
#define BUS_Y_PAD_CTLR_STRENGTH__READBACK_N_VALUE_MASK     0x0000000fL
#define BUS_Y_PAD_CTLR_STRENGTH__READBACK_P_VALUE_MASK     0x000000f0L
#define BUS_Y_PAD_CTLR_STRENGTH__N_MANUAL_STRENGTH_MASK    0x00000f00L
#define BUS_Y_PAD_CTLR_STRENGTH__P_MANUAL_STRENGTH_MASK    0x0000f000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_MANUAL_OVERRIDE_MASK  0x00010000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_MANUAL_OVERRIDE       0x00010000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_DFR_MASK        0x00080000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_DFR             0x00080000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_SCHMEN_MASK     0x00100000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_SCHMEN          0x00100000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_DREN_MASK       0x00200000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_DREN            0x00200000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_SLEW_MASK       0x00400000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_SLEW            0x00400000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_VDIFF_MASK      0x00800000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_VDIFF           0x00800000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_DFR_OVERRIDE_MASK 0x01000000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_DFR_OVERRIDE    0x01000000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_SCHMEN_OVERRIDE_MASK 0x02000000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_SCHMEN_OVERRIDE 0x02000000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_DREN_OVERRIDE_MASK 0x04000000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_DREN_OVERRIDE   0x04000000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_SLEW_OVERRIDE_MASK 0x08000000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_SLEW_OVERRIDE   0x08000000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_VDIFF_OVERRIDE_MASK 0x10000000L
#define BUS_Y_PAD_CTLR_STRENGTH__PAD_HI_IO_VDIFF_OVERRIDE  0x10000000L

// FW_CNTL_BG
#define FW_CNTL_BG__WBF_WM_MAX_MASK                        0x0000000fL
#define FW_CNTL_BG__WBF_WM_MIN_MASK                        0x000000f0L
#define FW_CNTL_BG__DISCONNECT_W_DATA_STOPTRDY_MIN_MASK    0x00000f00L
#define FW_CNTL_BG__DISCONNECT_WO_DATA_STOPTRDY_MIN_MASK   0x0000f000L
#define FW_CNTL_BG__HOLD_FW_FIFO_MASK                      0x00010000L
#define FW_CNTL_BG__HOLD_FW_FIFO                           0x00010000L
#define FW_CNTL_BG__FORCE_FW_WBF_MASK                      0x00020000L
#define FW_CNTL_BG__FORCE_FW_WBF                           0x00020000L
#define FW_CNTL_BG__DIS_FW_WBF_MASK                        0x00040000L
#define FW_CNTL_BG__DIS_FW_WBF                             0x00040000L
#define FW_CNTL_BG__DISCONNECT_MODE_MASK                   0x00180000L
#define FW_CNTL_BG__DIS_WBF_WAIT_FOR_FRAME_MASK            0x00200000L
#define FW_CNTL_BG__DIS_WBF_WAIT_FOR_FRAME                 0x00200000L
#define FW_CNTL_BG__EN_TRDY_WAIT_FOR_FIFOAVL_MASK          0x00400000L
#define FW_CNTL_BG__EN_TRDY_WAIT_FOR_FIFOAVL               0x00400000L
#define FW_CNTL_BG__TRDY_WS_COUNT_MASK                     0x03800000L
#define FW_CNTL_BG__DIS_FW_ROTATION_MASK                   0x04000000L
#define FW_CNTL_BG__DIS_FW_ROTATION                        0x04000000L
#define FW_CNTL_BG__FORCE_TRDY_1WS_MASK                    0x08000000L
#define FW_CNTL_BG__FORCE_TRDY_1WS                         0x08000000L
#define FW_CNTL_BG__IGNORE_STRAP_FW_DIS_MASK               0x10000000L
#define FW_CNTL_BG__IGNORE_STRAP_FW_DIS                    0x10000000L
#define FW_CNTL_BG__FW_MISC_MASK                           0xe0000000L

// FW_STATUS_BG
#define FW_STATUS_BG__FW_IDLE_MASK                         0x00000001L
#define FW_STATUS_BG__FW_IDLE                              0x00000001L
#define FW_STATUS_BG__STAT_FW_CLEAN_MASK                   0x00000002L
#define FW_STATUS_BG__STAT_FW_CLEAN                        0x00000002L
#define FW_STATUS_BG__FW_WAVL_MASK                         0xf8000000L

// AGP_CNTL_BG
#define AGP_CNTL_BG__MAX_IDLE_CLK_MASK                     0x000000ffL
#define AGP_CNTL_BG__HOLD_RD_FIFO_MASK                     0x00000100L
#define AGP_CNTL_BG__HOLD_RD_FIFO                          0x00000100L
#define AGP_CNTL_BG__HOLD_RQ_FIFO_MASK                     0x00000200L
#define AGP_CNTL_BG__HOLD_RQ_FIFO                          0x00000200L
#define AGP_CNTL_BG__EN_2X_STBB_MASK                       0x00000400L
#define AGP_CNTL_BG__EN_2X_STBB                            0x00000400L
#define AGP_CNTL_BG__FORCE_FULL_SBA_MASK                   0x00000800L
#define AGP_CNTL_BG__FORCE_FULL_SBA                        0x00000800L
#define AGP_CNTL_BG__SBA_DIS_MASK                          0x00001000L
#define AGP_CNTL_BG__SBA_DIS                               0x00001000L
#define AGP_CNTL_BG__AGP_REV_ID_MASK                       0x00002000L
#define AGP_CNTL_BG__AGP_REV_ID                            0x00002000L
#define AGP_CNTL_BG__REG_CRIPPLE_AGP4X_MASK                0x00004000L
#define AGP_CNTL_BG__REG_CRIPPLE_AGP4X                     0x00004000L
#define AGP_CNTL_BG__REG_CRIPPLE_AGP2X4X_MASK              0x00008000L
#define AGP_CNTL_BG__REG_CRIPPLE_AGP2X4X                   0x00008000L
#define AGP_CNTL_BG__FORCE_INT_VREF_MASK                   0x00010000L
#define AGP_CNTL_BG__FORCE_INT_VREF                        0x00010000L
#define AGP_CNTL_BG__PENDING_SLOTS_VAL_MASK                0x00060000L
#define AGP_CNTL_BG__PENDING_SLOTS_SEL_MASK                0x00080000L
#define AGP_CNTL_BG__PENDING_SLOTS_SEL                     0x00080000L
#define AGP_CNTL_BG__EN_EXTENDED_AD_STB_2X_MASK            0x00100000L
#define AGP_CNTL_BG__EN_EXTENDED_AD_STB_2X                 0x00100000L
#define AGP_CNTL_BG__DIS_QUEUED_GNT_FIX_MASK               0x00200000L
#define AGP_CNTL_BG__DIS_QUEUED_GNT_FIX                    0x00200000L
#define AGP_CNTL_BG__EN_RDATA2X4X_MULTIRESET_MASK          0x00400000L
#define AGP_CNTL_BG__EN_RDATA2X4X_MULTIRESET               0x00400000L
#define AGP_CNTL_BG__EN_RBFCALM_MASK                       0x00800000L
#define AGP_CNTL_BG__EN_RBFCALM                            0x00800000L
#define AGP_CNTL_BG__FORCE_EXT_VREF_MASK                   0x01000000L
#define AGP_CNTL_BG__FORCE_EXT_VREF                        0x01000000L
#define AGP_CNTL_BG__DIS_RBF_MASK                          0x02000000L
#define AGP_CNTL_BG__DIS_RBF                               0x02000000L
#define AGP_CNTL_BG__DELAY_FIRST_SBA_EN_MASK               0x04000000L
#define AGP_CNTL_BG__DELAY_FIRST_SBA_EN                    0x04000000L
#define AGP_CNTL_BG__DELAY_FIRST_SBA_VAL_MASK              0x38000000L
#define AGP_CNTL_BG__AGP_MISC_MASK                         0xc0000000L

// BROADCAST_INDEX
#define BROADCAST_INDEX__BROADCAST_INDEX_MASK              0x000000ffL

// BROADCAST_DATA
#define BROADCAST_DATA__BROADCAST_DATA_MASK                0xffffffffL

// BROADCAST_OFFSET_X
#define BROADCAST_OFFSET_X__BROADCAST_OFFSET_X_MASK        0xfffc0000L

// BROADCAST_OFFSET_Y
#define BROADCAST_OFFSET_Y__BROADCAST_OFFSET_Y_MASK        0xfffc0000L

// BROADCAST_REMAP_XY
#define BROADCAST_REMAP_XY__BROADCAST_REMAP_XY_MASK        0xffffffffL

// AGPS_CTRL
#define AGPS_CTRL__HOLD_RQ_FIFO_MASK                       0x00000001L
#define AGPS_CTRL__HOLD_RQ_FIFO                            0x00000001L
#define AGPS_CTRL__HOLD_WR_FIFO_MASK                       0x00000002L
#define AGPS_CTRL__HOLD_WR_FIFO                            0x00000002L
#define AGPS_CTRL__HOLD_RD_FIFO_MASK                       0x00000004L
#define AGPS_CTRL__HOLD_RD_FIFO                            0x00000004L
#define AGPS_CTRL__HOLD_WREQ_FIFO_MASK                     0x00000008L
#define AGPS_CTRL__HOLD_WREQ_FIFO                          0x00000008L
#define AGPS_CTRL__HOLD_RDSIZE_FIFO_MASK                   0x00000010L
#define AGPS_CTRL__HOLD_RDSIZE_FIFO                        0x00000010L
#define AGPS_CTRL__DELAY_RDSIZE_FIFO_MASK                  0x00000020L
#define AGPS_CTRL__DELAY_RDSIZE_FIFO                       0x00000020L
#define AGPS_CTRL__EN_2X_STBB_MASK                         0x00000040L
#define AGPS_CTRL__EN_2X_STBB                              0x00000040L
#define AGPS_CTRL__EN_EXTENDED_AD_STB_2X_MASK              0x00000080L
#define AGPS_CTRL__EN_EXTENDED_AD_STB_2X                   0x00000080L
#define AGPS_CTRL__MISC_MASK                               0x00003c00L
#define AGPS_CTRL__REG_CRIPPLE_AGP4X_MASK                  0x00004000L
#define AGPS_CTRL__REG_CRIPPLE_AGP4X                       0x00004000L
#define AGPS_CTRL__REG_CRIPPLE_AGP2X4X_MASK                0x00008000L
#define AGPS_CTRL__REG_CRIPPLE_AGP2X4X                     0x00008000L
#define AGPS_CTRL__SBADEC_SOFT_RESET_MASK                  0x00010000L
#define AGPS_CTRL__SBADEC_SOFT_RESET                       0x00010000L

// MARB_RESPONSE_WINDOW
#define MARB_RESPONSE_WINDOW__WINDOW_START_MASK            0x0000fffcL
#define MARB_RESPONSE_WINDOW__WINDOW_END_MASK              0xfffc0000L

// MARB_CTRL
#define MARB_CTRL__MARB_BURST_LENGTH_MASK                  0x000000ffL

// AGP2PCI_REMAPPING_OFFSET
#define AGP2PCI_REMAPPING_OFFSET__AGP2PCI_X_REMAPPING_OFFSET_MASK 0x0000ffffL
#define AGP2PCI_REMAPPING_OFFSET__AGP2PCI_Y_REMAPPING_OFFSET_MASK 0xffff0000L

// BUS_X_SARB_CNTL_A
#define BUS_X_SARB_CNTL_A__CFG_ARB_DIS_MASK                0x00000001L
#define BUS_X_SARB_CNTL_A__CFG_ARB_DIS                     0x00000001L
#define BUS_X_SARB_CNTL_A__CFG_ST_PIPE_MASK                0x00000002L
#define BUS_X_SARB_CNTL_A__CFG_ST_PIPE                     0x00000002L
#define BUS_X_SARB_CNTL_A__CFG_RBFb_NOBLOCK_AGP_RDREQ_MASK 0x00000004L
#define BUS_X_SARB_CNTL_A__CFG_RBFb_NOBLOCK_AGP_RDREQ      0x00000004L
#define BUS_X_SARB_CNTL_A__CFG_PCI_RR_FAIR_MASK            0x00000008L
#define BUS_X_SARB_CNTL_A__CFG_PCI_RR_FAIR                 0x00000008L
#define BUS_X_SARB_CNTL_A__CFG_MAX_OS_AGP_WR_MASK          0x000000f0L
#define BUS_X_SARB_CNTL_A__CFG_PCI_GNT_COUNT_MASK          0x0000f000L
#define BUS_X_SARB_CNTL_A__CFG_PCI_GNT_MAX_MASK            0x003f0000L
#define BUS_X_SARB_CNTL_A__CFG_PCI_GNT_MIN_MASK            0x07000000L
#define BUS_X_SARB_CNTL_A__CFG_ALWAYS_PARK_ON_BRIDGE_MASK  0x10000000L
#define BUS_X_SARB_CNTL_A__CFG_ALWAYS_PARK_ON_BRIDGE       0x10000000L

// BUS_X_SARB_CNTL_B
#define BUS_X_SARB_CNTL_B__CFG_PCI_BURST_MAX_MASK          0x000000ffL
#define BUS_X_SARB_CNTL_B__CFG_AGP_BURST_MAX_MASK          0x0000ff00L

// BUS_Y_SARB_CNTL_A
#define BUS_Y_SARB_CNTL_A__CFG_ARB_DIS_MASK                0x00000001L
#define BUS_Y_SARB_CNTL_A__CFG_ARB_DIS                     0x00000001L
#define BUS_Y_SARB_CNTL_A__CFG_ST_PIPE_MASK                0x00000002L
#define BUS_Y_SARB_CNTL_A__CFG_ST_PIPE                     0x00000002L
#define BUS_Y_SARB_CNTL_A__CFG_RBFb_NOBLOCK_AGP_RDREQ_MASK 0x00000004L
#define BUS_Y_SARB_CNTL_A__CFG_RBFb_NOBLOCK_AGP_RDREQ      0x00000004L
#define BUS_Y_SARB_CNTL_A__CFG_PCI_RR_FAIR_MASK            0x00000008L
#define BUS_Y_SARB_CNTL_A__CFG_PCI_RR_FAIR                 0x00000008L
#define BUS_Y_SARB_CNTL_A__CFG_MAX_OS_AGP_WR_MASK          0x000000f0L
#define BUS_Y_SARB_CNTL_A__CFG_PCI_GNT_COUNT_MASK          0x0000f000L
#define BUS_Y_SARB_CNTL_A__CFG_PCI_GNT_MAX_MASK            0x003f0000L
#define BUS_Y_SARB_CNTL_A__CFG_PCI_GNT_MIN_MASK            0x07000000L
#define BUS_Y_SARB_CNTL_A__CFG_ALWAYS_PARK_ON_BRIDGE_MASK  0x10000000L
#define BUS_Y_SARB_CNTL_A__CFG_ALWAYS_PARK_ON_BRIDGE       0x10000000L

// BUS_Y_SARB_CNTL_B
#define BUS_Y_SARB_CNTL_B__CFG_PCI_BURST_MAX_MASK          0x000000ffL
#define BUS_Y_SARB_CNTL_B__CFG_AGP_BURST_MAX_MASK          0x0000ff00L

// MST_PRERD_CNTL
#define MST_PRERD_CNTL__RD_PREFETCH_P_PORT_SZ_MASK         0x00000003L
#define MST_PRERD_CNTL__RD_PREFETCH_X_PORT_SZ_MASK         0x00000030L
#define MST_PRERD_CNTL__RD_PREFETCH_Y_PORT_SZ_MASK         0x000000c0L
#define MST_PRERD_CNTL__RD_PREFETCH_P_PORT_US_X_EN_MASK    0x00000100L
#define MST_PRERD_CNTL__RD_PREFETCH_P_PORT_US_X_EN         0x00000100L
#define MST_PRERD_CNTL__RD_PREFETCH_P_PORT_US_Y_EN_MASK    0x00000200L
#define MST_PRERD_CNTL__RD_PREFETCH_P_PORT_US_Y_EN         0x00000200L
#define MST_PRERD_CNTL__RD_PREFETCH_X_PORT_DS_EN_MASK      0x00001000L
#define MST_PRERD_CNTL__RD_PREFETCH_X_PORT_DS_EN           0x00001000L
#define MST_PRERD_CNTL__RD_PREFETCH_X_PORT_SS_EN_MASK      0x00002000L
#define MST_PRERD_CNTL__RD_PREFETCH_X_PORT_SS_EN           0x00002000L
#define MST_PRERD_CNTL__RD_PREFETCH_Y_PORT_DS_EN_MASK      0x00010000L
#define MST_PRERD_CNTL__RD_PREFETCH_Y_PORT_DS_EN           0x00010000L
#define MST_PRERD_CNTL__RD_PREFETCH_Y_PORT_SS_EN_MASK      0x00020000L
#define MST_PRERD_CNTL__RD_PREFETCH_Y_PORT_SS_EN           0x00020000L
#define MST_PRERD_CNTL__RD_PREFETCH_P_PORT_US_XY_SGLRD_EN_MASK 0x00100000L
#define MST_PRERD_CNTL__RD_PREFETCH_P_PORT_US_XY_SGLRD_EN  0x00100000L
#define MST_PRERD_CNTL__RD_PREFETCH_X_PORT_SS_SGLRD_EN_MASK 0x00200000L
#define MST_PRERD_CNTL__RD_PREFETCH_X_PORT_SS_SGLRD_EN     0x00200000L
#define MST_PRERD_CNTL__RD_PREFETCH_Y_PORT_SS_SGLRD_EN_MASK 0x00400000L
#define MST_PRERD_CNTL__RD_PREFETCH_Y_PORT_SS_SGLRD_EN     0x00400000L
#define MST_PRERD_CNTL__RD_PREFETCH_P_FORCE_PURGE_MASK     0x01000000L
#define MST_PRERD_CNTL__RD_PREFETCH_P_FORCE_PURGE          0x01000000L
#define MST_PRERD_CNTL__RD_PREFETCH_X_FORCE_PURGE_MASK     0x02000000L
#define MST_PRERD_CNTL__RD_PREFETCH_X_FORCE_PURGE          0x02000000L
#define MST_PRERD_CNTL__RD_PREFETCH_Y_FORCE_PURGE_MASK     0x04000000L
#define MST_PRERD_CNTL__RD_PREFETCH_Y_FORCE_PURGE          0x04000000L

// BIF_MISC
#define BIF_MISC__REG_AD_PHASE_WS_MASK                     0x00000003L
#define BIF_MISC__REG_RD_PHASE_WS_MASK                     0x00000030L
#define BIF_MISC__EN_SGD_ROM_X_Y_OR_INT_MASK               0x00000300L
#define BIF_MISC__EN_REQb_WCWIN_PRI_MASK                   0x00001000L
#define BIF_MISC__EN_REQb_WCWIN_PRI                        0x00001000L
#define BIF_MISC__EN_REQb_WCWIN_SEC_MASK                   0x00002000L
#define BIF_MISC__EN_REQb_WCWIN_SEC                        0x00002000L
#define BIF_MISC__MM_REG_UNPROTECT_MASK                    0x000f0000L
#define BIF_MISC__PMI_IO_DISABLE_MASK                      0x00100000L
#define BIF_MISC__PMI_IO_DISABLE                           0x00100000L
#define BIF_MISC__PMI_MEM_DISABLE_MASK                     0x00200000L
#define BIF_MISC__PMI_MEM_DISABLE                          0x00200000L
#define BIF_MISC__PMI_BM_DISABLE_MASK                      0x00400000L
#define BIF_MISC__PMI_BM_DISABLE                           0x00400000L
#define BIF_MISC__PMI_INT_DISABLE_MASK                     0x00800000L
#define BIF_MISC__PMI_INT_DISABLE                          0x00800000L

// PARB_ARBITOR_CNTL
#define PARB_ARBITOR_CNTL__PARB_X_MAN_EN_MASK              0x00000001L
#define PARB_ARBITOR_CNTL__PARB_X_MAN_EN                   0x00000001L
#define PARB_ARBITOR_CNTL__PARB_X_SS_BUS_TYPE_SEL_MASK     0x00000002L
#define PARB_ARBITOR_CNTL__PARB_X_SS_BUS_TYPE_SEL          0x00000002L
#define PARB_ARBITOR_CNTL__PARB_X_MAN_SEL_MASK             0x00000030L
#define PARB_ARBITOR_CNTL__PARB_Y_MAN_EN_MASK              0x00000100L
#define PARB_ARBITOR_CNTL__PARB_Y_MAN_EN                   0x00000100L
#define PARB_ARBITOR_CNTL__PARB_Y_SS_BUS_TYPE_SEL_MASK     0x00000200L
#define PARB_ARBITOR_CNTL__PARB_Y_SS_BUS_TYPE_SEL          0x00000200L
#define PARB_ARBITOR_CNTL__PARB_Y_MAN_SEL_MASK             0x00003000L
#define PARB_ARBITOR_CNTL__BOARDCAST_MODE_MASK             0x000f0000L
#define PARB_ARBITOR_CNTL__PCI_OP_MASK                     0x00700000L

// PARB_TIMEOUT_CNTL
#define PARB_TIMEOUT_CNTL__BUS_P_TIMEOUT_MASK              0x0000003fL
#define PARB_TIMEOUT_CNTL__BUS_X_TIMEOUT_MASK              0x00003f00L
#define PARB_TIMEOUT_CNTL__BUS_Y_TIMEOUT_MASK              0x003f0000L

// ARBITRATION_STATUS
#define ARBITRATION_STATUS__PARBX_MS_BUS_SEL_MASK          0x00000001L
#define ARBITRATION_STATUS__PARBX_MS_BUS_SEL               0x00000001L
#define ARBITRATION_STATUS__PARBX_SS_AGP_PCI_SEL_MASK      0x00000002L
#define ARBITRATION_STATUS__PARBX_SS_AGP_PCI_SEL           0x00000002L
#define ARBITRATION_STATUS__PARBY_MS_BUS_SEL_MASK          0x00000010L
#define ARBITRATION_STATUS__PARBY_MS_BUS_SEL               0x00000010L
#define ARBITRATION_STATUS__PARBY_SS_AGP_PCI_SEL_MASK      0x00000020L
#define ARBITRATION_STATUS__PARBY_SS_AGP_PCI_SEL           0x00000020L
#define ARBITRATION_STATUS__ARBITOR_XY2P_BUS_SEL_MASK      0x00000100L
#define ARBITRATION_STATUS__ARBITOR_XY2P_BUS_SEL           0x00000100L

// BYTE_SWAP_CNTL
#define BYTE_SWAP_CNTL__BYTE_SWAP_MODE_MASK                0x00000003L
#define BYTE_SWAP_CNTL__BYTE_SWAP_CFG_MON_DISABLEb_MASK    0x00000010L
#define BYTE_SWAP_CNTL__BYTE_SWAP_CFG_MON_DISABLEb         0x00000010L

// BUS_X_PULL_UPDN_CNTL
#define BUS_X_PULL_UPDN_CNTL__GLOBAL_PUPD_DIS_X_MASK       0x00000001L
#define BUS_X_PULL_UPDN_CNTL__GLOBAL_PUPD_DIS_X            0x00000001L
#define BUS_X_PULL_UPDN_CNTL__PU_REQb_X_MASK               0x00000010L
#define BUS_X_PULL_UPDN_CNTL__PU_REQb_X                    0x00000010L
#define BUS_X_PULL_UPDN_CNTL__PU_GNTb_X_MASK               0x00000020L
#define BUS_X_PULL_UPDN_CNTL__PU_GNTb_X                    0x00000020L
#define BUS_X_PULL_UPDN_CNTL__PU_RBFb_X_MASK               0x00000040L
#define BUS_X_PULL_UPDN_CNTL__PU_RBFb_X                    0x00000040L
#define BUS_X_PULL_UPDN_CNTL__PU_WBFb_X_MASK               0x00000080L
#define BUS_X_PULL_UPDN_CNTL__PU_WBFb_X                    0x00000080L
#define BUS_X_PULL_UPDN_CNTL__PU_FRAMEb_X_MASK             0x00000100L
#define BUS_X_PULL_UPDN_CNTL__PU_FRAMEb_X                  0x00000100L
#define BUS_X_PULL_UPDN_CNTL__PU_IRDYb_X_MASK              0x00000200L
#define BUS_X_PULL_UPDN_CNTL__PU_IRDYb_X                   0x00000200L
#define BUS_X_PULL_UPDN_CNTL__PU_TRDYb_X_MASK              0x00000400L
#define BUS_X_PULL_UPDN_CNTL__PU_TRDYb_X                   0x00000400L
#define BUS_X_PULL_UPDN_CNTL__PU_DEVSELb_X_MASK            0x00000800L
#define BUS_X_PULL_UPDN_CNTL__PU_DEVSELb_X                 0x00000800L
#define BUS_X_PULL_UPDN_CNTL__PU_STOPb_X_MASK              0x00001000L
#define BUS_X_PULL_UPDN_CNTL__PU_STOPb_X                   0x00001000L
#define BUS_X_PULL_UPDN_CNTL__PU_PAR_X_MASK                0x00002000L
#define BUS_X_PULL_UPDN_CNTL__PU_PAR_X                     0x00002000L
#define BUS_X_PULL_UPDN_CNTL__PU_AD_X_MASK                 0x00004000L
#define BUS_X_PULL_UPDN_CNTL__PU_AD_X                      0x00004000L
#define BUS_X_PULL_UPDN_CNTL__PU_CBEB_X_MASK               0x00008000L
#define BUS_X_PULL_UPDN_CNTL__PU_CBEB_X                    0x00008000L
#define BUS_X_PULL_UPDN_CNTL__PU_AGP_SBA_X_MASK            0x00010000L
#define BUS_X_PULL_UPDN_CNTL__PU_AGP_SBA_X                 0x00010000L
#define BUS_X_PULL_UPDN_CNTL__PU_AGP_ADSTB_X_MASK          0x00020000L
#define BUS_X_PULL_UPDN_CNTL__PU_AGP_ADSTB_X               0x00020000L
#define BUS_X_PULL_UPDN_CNTL__PU_AGP_SBSTB_X_MASK          0x00040000L
#define BUS_X_PULL_UPDN_CNTL__PU_AGP_SBSTB_X               0x00040000L
#define BUS_X_PULL_UPDN_CNTL__PD_AGP_ADSTBB_X_MASK         0x00080000L
#define BUS_X_PULL_UPDN_CNTL__PD_AGP_ADSTBB_X              0x00080000L
#define BUS_X_PULL_UPDN_CNTL__PD_AGP_SBSTBB_X_MASK         0x00100000L
#define BUS_X_PULL_UPDN_CNTL__PD_AGP_SBSTBB_X              0x00100000L

// BUS_Y_PULL_UPDN_CNTL
#define BUS_Y_PULL_UPDN_CNTL__GLOBAL_PUPD_DIS_Y_MASK       0x00000001L
#define BUS_Y_PULL_UPDN_CNTL__GLOBAL_PUPD_DIS_Y            0x00000001L
#define BUS_Y_PULL_UPDN_CNTL__PU_REQb_Y_MASK               0x00000010L
#define BUS_Y_PULL_UPDN_CNTL__PU_REQb_Y                    0x00000010L
#define BUS_Y_PULL_UPDN_CNTL__PU_GNTb_Y_MASK               0x00000020L
#define BUS_Y_PULL_UPDN_CNTL__PU_GNTb_Y                    0x00000020L
#define BUS_Y_PULL_UPDN_CNTL__PU_RBFb_Y_MASK               0x00000040L
#define BUS_Y_PULL_UPDN_CNTL__PU_RBFb_Y                    0x00000040L
#define BUS_Y_PULL_UPDN_CNTL__PU_WBFb_Y_MASK               0x00000080L
#define BUS_Y_PULL_UPDN_CNTL__PU_WBFb_Y                    0x00000080L
#define BUS_Y_PULL_UPDN_CNTL__PU_FRAMEb_Y_MASK             0x00000100L
#define BUS_Y_PULL_UPDN_CNTL__PU_FRAMEb_Y                  0x00000100L
#define BUS_Y_PULL_UPDN_CNTL__PU_IRDYb_Y_MASK              0x00000200L
#define BUS_Y_PULL_UPDN_CNTL__PU_IRDYb_Y                   0x00000200L
#define BUS_Y_PULL_UPDN_CNTL__PU_TRDYb_Y_MASK              0x00000400L
#define BUS_Y_PULL_UPDN_CNTL__PU_TRDYb_Y                   0x00000400L
#define BUS_Y_PULL_UPDN_CNTL__PU_DEVSELb_Y_MASK            0x00000800L
#define BUS_Y_PULL_UPDN_CNTL__PU_DEVSELb_Y                 0x00000800L
#define BUS_Y_PULL_UPDN_CNTL__PU_STOPb_Y_MASK              0x00001000L
#define BUS_Y_PULL_UPDN_CNTL__PU_STOPb_Y                   0x00001000L
#define BUS_Y_PULL_UPDN_CNTL__PU_PAR_Y_MASK                0x00002000L
#define BUS_Y_PULL_UPDN_CNTL__PU_PAR_Y                     0x00002000L
#define BUS_Y_PULL_UPDN_CNTL__PU_AD_Y_MASK                 0x00004000L
#define BUS_Y_PULL_UPDN_CNTL__PU_AD_Y                      0x00004000L
#define BUS_Y_PULL_UPDN_CNTL__PU_CBEB_Y_MASK               0x00008000L
#define BUS_Y_PULL_UPDN_CNTL__PU_CBEB_Y                    0x00008000L
#define BUS_Y_PULL_UPDN_CNTL__PU_AGP_SBA_Y_MASK            0x00010000L
#define BUS_Y_PULL_UPDN_CNTL__PU_AGP_SBA_Y                 0x00010000L
#define BUS_Y_PULL_UPDN_CNTL__PU_AGP_ADSTB_Y_MASK          0x00020000L
#define BUS_Y_PULL_UPDN_CNTL__PU_AGP_ADSTB_Y               0x00020000L
#define BUS_Y_PULL_UPDN_CNTL__PU_AGP_SBSTB_Y_MASK          0x00040000L
#define BUS_Y_PULL_UPDN_CNTL__PU_AGP_SBSTB_Y               0x00040000L
#define BUS_Y_PULL_UPDN_CNTL__PD_AGP_ADSTBB_Y_MASK         0x00080000L
#define BUS_Y_PULL_UPDN_CNTL__PD_AGP_ADSTBB_Y              0x00080000L
#define BUS_Y_PULL_UPDN_CNTL__PD_AGP_SBSTBB_Y_MASK         0x00100000L
#define BUS_Y_PULL_UPDN_CNTL__PD_AGP_SBSTBB_Y              0x00100000L

// HW_DEBUG
#define HW_DEBUG__HW_DEBUG_0_MASK                          0x00000001L
#define HW_DEBUG__HW_DEBUG_0                               0x00000001L
#define HW_DEBUG__HW_DEBUG_1_MASK                          0x00000002L
#define HW_DEBUG__HW_DEBUG_1                               0x00000002L
#define HW_DEBUG__HW_DEBUG_2_MASK                          0x00000004L
#define HW_DEBUG__HW_DEBUG_2                               0x00000004L
#define HW_DEBUG__HW_DEBUG_3_MASK                          0x00000008L
#define HW_DEBUG__HW_DEBUG_3                               0x00000008L
#define HW_DEBUG__HW_DEBUG_4_MASK                          0x00000010L
#define HW_DEBUG__HW_DEBUG_4                               0x00000010L
#define HW_DEBUG__HW_DEBUG_5_MASK                          0x00000020L
#define HW_DEBUG__HW_DEBUG_5                               0x00000020L
#define HW_DEBUG__HW_DEBUG_6_MASK                          0x00000040L
#define HW_DEBUG__HW_DEBUG_6                               0x00000040L
#define HW_DEBUG__HW_DEBUG_7_MASK                          0x00000080L
#define HW_DEBUG__HW_DEBUG_7                               0x00000080L
#define HW_DEBUG__HW_DEBUG_8_MASK                          0x00000100L
#define HW_DEBUG__HW_DEBUG_8                               0x00000100L
#define HW_DEBUG__HW_DEBUG_9_MASK                          0x00000200L
#define HW_DEBUG__HW_DEBUG_9                               0x00000200L
#define HW_DEBUG__HW_DEBUG_A_MASK                          0x00000400L
#define HW_DEBUG__HW_DEBUG_A                               0x00000400L
#define HW_DEBUG__HW_DEBUG_B_MASK                          0x00000800L
#define HW_DEBUG__HW_DEBUG_B                               0x00000800L
#define HW_DEBUG__HW_DEBUG_C_MASK                          0x00001000L
#define HW_DEBUG__HW_DEBUG_C                               0x00001000L
#define HW_DEBUG__HW_DEBUG_D_MASK                          0x00002000L
#define HW_DEBUG__HW_DEBUG_D                               0x00002000L
#define HW_DEBUG__HW_DEBUG_E_MASK                          0x00004000L
#define HW_DEBUG__HW_DEBUG_E                               0x00004000L
#define HW_DEBUG__HW_DEBUG_F_MASK                          0x00008000L
#define HW_DEBUG__HW_DEBUG_F                               0x00008000L
#define HW_DEBUG__HW_DEBUG_10_MASK                         0x00010000L
#define HW_DEBUG__HW_DEBUG_10                              0x00010000L
#define HW_DEBUG__HW_DEBUG_11_MASK                         0x00020000L
#define HW_DEBUG__HW_DEBUG_11                              0x00020000L
#define HW_DEBUG__HW_DEBUG_12_MASK                         0x00040000L
#define HW_DEBUG__HW_DEBUG_12                              0x00040000L
#define HW_DEBUG__HW_DEBUG_13_MASK                         0x00080000L
#define HW_DEBUG__HW_DEBUG_13                              0x00080000L
#define HW_DEBUG__HW_DEBUG_14_MASK                         0x00100000L
#define HW_DEBUG__HW_DEBUG_14                              0x00100000L
#define HW_DEBUG__HW_DEBUG_15_MASK                         0x00200000L
#define HW_DEBUG__HW_DEBUG_15                              0x00200000L
#define HW_DEBUG__HW_DEBUG_16_MASK                         0x00400000L
#define HW_DEBUG__HW_DEBUG_16                              0x00400000L
#define HW_DEBUG__HW_DEBUG_17_MASK                         0x00800000L
#define HW_DEBUG__HW_DEBUG_17                              0x00800000L
#define HW_DEBUG__HW_DEBUG_18_MASK                         0x01000000L
#define HW_DEBUG__HW_DEBUG_18                              0x01000000L
#define HW_DEBUG__HW_DEBUG_19_MASK                         0x02000000L
#define HW_DEBUG__HW_DEBUG_19                              0x02000000L
#define HW_DEBUG__HW_DEBUG_1A_MASK                         0x04000000L
#define HW_DEBUG__HW_DEBUG_1A                              0x04000000L
#define HW_DEBUG__HW_DEBUG_1B_MASK                         0x08000000L
#define HW_DEBUG__HW_DEBUG_1B                              0x08000000L
#define HW_DEBUG__HW_DEBUG_1C_MASK                         0x10000000L
#define HW_DEBUG__HW_DEBUG_1C                              0x10000000L
#define HW_DEBUG__HW_DEBUG_1D_MASK                         0x20000000L
#define HW_DEBUG__HW_DEBUG_1D                              0x20000000L
#define HW_DEBUG__HW_DEBUG_1E_MASK                         0x40000000L
#define HW_DEBUG__HW_DEBUG_1E                              0x40000000L
#define HW_DEBUG__HW_DEBUG_1F_MASK                         0x80000000L
#define HW_DEBUG__HW_DEBUG_1F                              0x80000000L

// RESYNC_CNTL
#define RESYNC_CNTL__DBL_RSYNC_P_MST_RPTR_MASK             0x00000001L
#define RESYNC_CNTL__DBL_RSYNC_P_MST_RPTR                  0x00000001L
#define RESYNC_CNTL__DBL_RSYNC_P_MST_WPTR_MASK             0x00000002L
#define RESYNC_CNTL__DBL_RSYNC_P_MST_WPTR                  0x00000002L
#define RESYNC_CNTL__DBL_RSYNC_P_MWB_RPTR_MASK             0x00000004L
#define RESYNC_CNTL__DBL_RSYNC_P_MWB_RPTR                  0x00000004L
#define RESYNC_CNTL__DBL_RSYNC_P_MWB_WPTR_MASK             0x00000008L
#define RESYNC_CNTL__DBL_RSYNC_P_MWB_WPTR                  0x00000008L
#define RESYNC_CNTL__DBL_RSYNC_P_MRB_RPTR_MASK             0x00000010L
#define RESYNC_CNTL__DBL_RSYNC_P_MRB_RPTR                  0x00000010L
#define RESYNC_CNTL__DBL_RSYNC_P_MRB_WPTR_MASK             0x00000020L
#define RESYNC_CNTL__DBL_RSYNC_P_MRB_WPTR                  0x00000020L
#define RESYNC_CNTL__DBL_RSYNC_P_SRB_RPTR_MASK             0x00000040L
#define RESYNC_CNTL__DBL_RSYNC_P_SRB_RPTR                  0x00000040L
#define RESYNC_CNTL__DBL_RSYNC_P_SRB_WPTR_MASK             0x00000080L
#define RESYNC_CNTL__DBL_RSYNC_P_SRB_WPTR                  0x00000080L
#define RESYNC_CNTL__DBL_RSYNC_P_SWB_RPTR_MASK             0x00000100L
#define RESYNC_CNTL__DBL_RSYNC_P_SWB_RPTR                  0x00000100L
#define RESYNC_CNTL__DBL_RSYNC_P_SWB_WPTR_MASK             0x00000200L
#define RESYNC_CNTL__DBL_RSYNC_P_SWB_WPTR                  0x00000200L
#define RESYNC_CNTL__DBL_RSYNC_X_MST_RPTR_MASK             0x00000400L
#define RESYNC_CNTL__DBL_RSYNC_X_MST_RPTR                  0x00000400L
#define RESYNC_CNTL__DBL_RSYNC_X_MST_WPTR_MASK             0x00000800L
#define RESYNC_CNTL__DBL_RSYNC_X_MST_WPTR                  0x00000800L
#define RESYNC_CNTL__DBL_RSYNC_X_MWB_RPTR_MASK             0x00001000L
#define RESYNC_CNTL__DBL_RSYNC_X_MWB_RPTR                  0x00001000L
#define RESYNC_CNTL__DBL_RSYNC_X_MWB_WPTR_MASK             0x00002000L
#define RESYNC_CNTL__DBL_RSYNC_X_MWB_WPTR                  0x00002000L
#define RESYNC_CNTL__DBL_RSYNC_X_MRB_RPTR_MASK             0x00004000L
#define RESYNC_CNTL__DBL_RSYNC_X_MRB_RPTR                  0x00004000L
#define RESYNC_CNTL__DBL_RSYNC_X_MRB_WPTR_MASK             0x00008000L
#define RESYNC_CNTL__DBL_RSYNC_X_MRB_WPTR                  0x00008000L
#define RESYNC_CNTL__DBL_RSYNC_X_SRB_RPTR_MASK             0x00010000L
#define RESYNC_CNTL__DBL_RSYNC_X_SRB_RPTR                  0x00010000L
#define RESYNC_CNTL__DBL_RSYNC_X_SRB_WPTR_MASK             0x00020000L
#define RESYNC_CNTL__DBL_RSYNC_X_SRB_WPTR                  0x00020000L
#define RESYNC_CNTL__DBL_RSYNC_X_SWB_RPTR_MASK             0x00040000L
#define RESYNC_CNTL__DBL_RSYNC_X_SWB_RPTR                  0x00040000L
#define RESYNC_CNTL__DBL_RSYNC_X_SWB_WPTR_MASK             0x00080000L
#define RESYNC_CNTL__DBL_RSYNC_X_SWB_WPTR                  0x00080000L
#define RESYNC_CNTL__DBL_RSYNC_Y_MST_RPTR_MASK             0x00100000L
#define RESYNC_CNTL__DBL_RSYNC_Y_MST_RPTR                  0x00100000L
#define RESYNC_CNTL__DBL_RSYNC_Y_MST_WPTR_MASK             0x00200000L
#define RESYNC_CNTL__DBL_RSYNC_Y_MST_WPTR                  0x00200000L
#define RESYNC_CNTL__DBL_RSYNC_Y_MWB_RPTR_MASK             0x00400000L
#define RESYNC_CNTL__DBL_RSYNC_Y_MWB_RPTR                  0x00400000L
#define RESYNC_CNTL__DBL_RSYNC_Y_MWB_WPTR_MASK             0x00800000L
#define RESYNC_CNTL__DBL_RSYNC_Y_MWB_WPTR                  0x00800000L
#define RESYNC_CNTL__DBL_RSYNC_Y_MRB_RPTR_MASK             0x01000000L
#define RESYNC_CNTL__DBL_RSYNC_Y_MRB_RPTR                  0x01000000L
#define RESYNC_CNTL__DBL_RSYNC_Y_MRB_WPTR_MASK             0x02000000L
#define RESYNC_CNTL__DBL_RSYNC_Y_MRB_WPTR                  0x02000000L
#define RESYNC_CNTL__DBL_RSYNC_Y_SRB_RPTR_MASK             0x04000000L
#define RESYNC_CNTL__DBL_RSYNC_Y_SRB_RPTR                  0x04000000L
#define RESYNC_CNTL__DBL_RSYNC_Y_SRB_WPTR_MASK             0x08000000L
#define RESYNC_CNTL__DBL_RSYNC_Y_SRB_WPTR                  0x08000000L
#define RESYNC_CNTL__DBL_RSYNC_Y_SWB_RPTR_MASK             0x10000000L
#define RESYNC_CNTL__DBL_RSYNC_Y_SWB_RPTR                  0x10000000L
#define RESYNC_CNTL__DBL_RSYNC_Y_SWB_WPTR_MASK             0x20000000L
#define RESYNC_CNTL__DBL_RSYNC_Y_SWB_WPTR                  0x20000000L

// AGP_RESYNC_CNTL
#define AGP_RESYNC_CNTL__DBL_RSYNC_P_WRFIFO_RPTR_MASK      0x00000001L
#define AGP_RESYNC_CNTL__DBL_RSYNC_P_WRFIFO_RPTR           0x00000001L
#define AGP_RESYNC_CNTL__DBL_RSYNC_P_WRFIFO_WPTR_MASK      0x00000002L
#define AGP_RESYNC_CNTL__DBL_RSYNC_P_WRFIFO_WPTR           0x00000002L
#define AGP_RESYNC_CNTL__DBL_RSYNC_P_RDFIFO_RPTR_MASK      0x00000004L
#define AGP_RESYNC_CNTL__DBL_RSYNC_P_RDFIFO_RPTR           0x00000004L
#define AGP_RESYNC_CNTL__DBL_RSYNC_P_RDFIFO_WPTR_MASK      0x00000008L
#define AGP_RESYNC_CNTL__DBL_RSYNC_P_RDFIFO_WPTR           0x00000008L
#define AGP_RESYNC_CNTL__DBL_RSYNC_P_RQFIFO_RPTR_MASK      0x00000010L
#define AGP_RESYNC_CNTL__DBL_RSYNC_P_RQFIFO_RPTR           0x00000010L
#define AGP_RESYNC_CNTL__DBL_RSYNC_P_RQFIFO_WPTR_MASK      0x00000020L
#define AGP_RESYNC_CNTL__DBL_RSYNC_P_RQFIFO_WPTR           0x00000020L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_WRFIFO_RPTR_MASK      0x00000040L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_WRFIFO_RPTR           0x00000040L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_WRFIFO_WPTR_MASK      0x00000080L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_WRFIFO_WPTR           0x00000080L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_RDFIFO_RPTR_MASK      0x00000100L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_RDFIFO_RPTR           0x00000100L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_RDFIFO_WPTR_MASK      0x00000200L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_RDFIFO_WPTR           0x00000200L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_RQFIFO_RPTR_MASK      0x00000400L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_RQFIFO_RPTR           0x00000400L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_RQFIFO_WPTR_MASK      0x00000800L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_RQFIFO_WPTR           0x00000800L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_WREQ_RPTR_MASK        0x00001000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_WREQ_RPTR             0x00001000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_WREQ_WPTR_MASK        0x00002000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_WREQ_WPTR             0x00002000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_RDSIZE_RPTR_MASK      0x00004000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_RDSIZE_RPTR           0x00004000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_RDSIZE_WPTR_MASK      0x00008000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_X_RDSIZE_WPTR           0x00008000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_WRFIFO_RPTR_MASK      0x00010000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_WRFIFO_RPTR           0x00010000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_WRFIFO_WPTR_MASK      0x00020000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_WRFIFO_WPTR           0x00020000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_RDFIFO_RPTR_MASK      0x00040000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_RDFIFO_RPTR           0x00040000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_RDFIFO_WPTR_MASK      0x00080000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_RDFIFO_WPTR           0x00080000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_RQFIFO_RPTR_MASK      0x00100000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_RQFIFO_RPTR           0x00100000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_RQFIFO_WPTR_MASK      0x00200000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_RQFIFO_WPTR           0x00200000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_WREQ_RPTR_MASK        0x00400000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_WREQ_RPTR             0x00400000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_WREQ_WPTR_MASK        0x00800000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_WREQ_WPTR             0x00800000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_RDSIZE_RPTR_MASK      0x01000000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_RDSIZE_RPTR           0x01000000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_RDSIZE_WPTR_MASK      0x02000000L
#define AGP_RESYNC_CNTL__DBL_RSYNC_Y_RDSIZE_WPTR           0x02000000L

// ALT_SECSTATUS_AND_BUSCONTROL_X
#define ALT_SECSTATUS_AND_BUSCONTROL_X__SEC_SERR_EN_X_MASK 0x00000001L
#define ALT_SECSTATUS_AND_BUSCONTROL_X__SEC_SERR_EN_X      0x00000001L
#define ALT_SECSTATUS_AND_BUSCONTROL_X__MST_ABORT_MODE_X_MASK 0x00000002L
#define ALT_SECSTATUS_AND_BUSCONTROL_X__MST_ABORT_MODE_X   0x00000002L
#define ALT_SECSTATUS_AND_BUSCONTROL_X__SEC_BUS_RESET_X_MASK 0x00000004L
#define ALT_SECSTATUS_AND_BUSCONTROL_X__SEC_BUS_RESET_X    0x00000004L
#define ALT_SECSTATUS_AND_BUSCONTROL_X__DISCARD_TIMER_SERRb_EN_X_MASK 0x00000008L
#define ALT_SECSTATUS_AND_BUSCONTROL_X__DISCARD_TIMER_SERRb_EN_X 0x00000008L
#define ALT_SECSTATUS_AND_BUSCONTROL_X__DISCARD_TIMER_STATUS_X_MASK 0x04000000L
#define ALT_SECSTATUS_AND_BUSCONTROL_X__DISCARD_TIMER_STATUS_X 0x04000000L
#define ALT_SECSTATUS_AND_BUSCONTROL_X__RECEIVED_SEC_TARGET_ABORT_X_MASK 0x10000000L
#define ALT_SECSTATUS_AND_BUSCONTROL_X__RECEIVED_SEC_TARGET_ABORT_X 0x10000000L
#define ALT_SECSTATUS_AND_BUSCONTROL_X__RECEIVED_SEC_MASTER_ABORT_X_MASK 0x20000000L
#define ALT_SECSTATUS_AND_BUSCONTROL_X__RECEIVED_SEC_MASTER_ABORT_X 0x20000000L
#define ALT_SECSTATUS_AND_BUSCONTROL_X__RECEIVED_SEC_SYSTEM_ERROR_X_MASK 0x40000000L
#define ALT_SECSTATUS_AND_BUSCONTROL_X__RECEIVED_SEC_SYSTEM_ERROR_X 0x40000000L

// ALT_SECSTATUS_AND_BUSCONTROL_Y
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__SEC_SERR_EN_Y_MASK 0x00000001L
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__SEC_SERR_EN_Y      0x00000001L
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__MST_ABORT_MODE_Y_MASK 0x00000002L
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__MST_ABORT_MODE_Y   0x00000002L
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__SEC_BUS_RESET_Y_MASK 0x00000004L
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__SEC_BUS_RESET_Y    0x00000004L
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__DISCARD_TIMER_SERRb_EN_Y_MASK 0x00000008L
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__DISCARD_TIMER_SERRb_EN_Y 0x00000008L
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__DISCARD_TIMER_STATUS_Y_MASK 0x04000000L
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__DISCARD_TIMER_STATUS_Y 0x04000000L
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__RECEIVED_SEC_TARGET_ABORT_Y_MASK 0x10000000L
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__RECEIVED_SEC_TARGET_ABORT_Y 0x10000000L
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__RECEIVED_SEC_MASTER_ABORT_Y_MASK 0x20000000L
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__RECEIVED_SEC_MASTER_ABORT_Y 0x20000000L
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__RECEIVED_SEC_SYSTEM_ERROR_Y_MASK 0x40000000L
#define ALT_SECSTATUS_AND_BUSCONTROL_Y__RECEIVED_SEC_SYSTEM_ERROR_Y 0x40000000L

// SGD_SEC_LAT_TIMER
#define SGD_SEC_LAT_TIMER__SGD_SEC_LAT_TIMER_X_MASK        0x000000ffL
#define SGD_SEC_LAT_TIMER__SGD_SEC_LAT_TIMER_Y_MASK        0x0000ff00L
#define SGD_SEC_LAT_TIMER__SGD_SEC_LAT_TIMER_X_EN_MASK     0x00010000L
#define SGD_SEC_LAT_TIMER__SGD_SEC_LAT_TIMER_X_EN          0x00010000L
#define SGD_SEC_LAT_TIMER__SGD_SEC_LAT_TIMER_Y_EN_MASK     0x00020000L
#define SGD_SEC_LAT_TIMER__SGD_SEC_LAT_TIMER_Y_EN          0x00020000L

// CONFIG_XSTRAP1
#define CONFIG_XSTRAP1__ROMCFG_MASK                        0x00000003L
#define CONFIG_XSTRAP1__BUSCFG_MASK                        0x0000000cL
#define CONFIG_XSTRAP1__HWE_MODE_MASK                      0x00000010L
#define CONFIG_XSTRAP1__HWE_MODE                           0x00000010L
#define CONFIG_XSTRAP1__S_FW_DIS_MASK                      0x00000020L
#define CONFIG_XSTRAP1__S_FW_DIS                           0x00000020L
#define CONFIG_XSTRAP1__P2PB_MODE_MASK                     0x00000040L
#define CONFIG_XSTRAP1__P2PB_MODE                          0x00000040L
#define CONFIG_XSTRAP1__IDSEL_AD17_MASK                    0x00000080L
#define CONFIG_XSTRAP1__IDSEL_AD17                         0x00000080L
#define CONFIG_XSTRAP1__VGA_DISABLE_MASK                   0x00000100L
#define CONFIG_XSTRAP1__VGA_DISABLE                        0x00000100L
#define CONFIG_XSTRAP1__ENINTb_MASK                        0x00000200L
#define CONFIG_XSTRAP1__ENINTb                             0x00000200L
#define CONFIG_XSTRAP1__AGP_MODE_MASK                      0x00001c00L
#define CONFIG_XSTRAP1__CAP_LIST_MASK                      0x00006000L
#define CONFIG_XSTRAP1__PORTB_DIS_MASK                     0x00008000L
#define CONFIG_XSTRAP1__PORTB_DIS                          0x00008000L
#define CONFIG_XSTRAP1__P_AGPFBSKEW_MASK                   0x00070000L
#define CONFIG_XSTRAP1__P_X1CLK_SKEW_MASK                  0x00380000L
#define CONFIG_XSTRAP1__X_AGPFBSKEW_MASK                   0x01c00000L
#define CONFIG_XSTRAP1__X_X1CLK_SKEW_MASK                  0x0e000000L
#define CONFIG_XSTRAP1__Y_AGPFBSKEW_MASK                   0x70000000L
#define CONFIG_XSTRAP1__KS_MODE_MASK                       0x80000000L
#define CONFIG_XSTRAP1__KS_MODE                            0x80000000L

// TEST_DEBUG_CNTL_BG
#define TEST_DEBUG_CNTL_BG__TEST_DEBUG_OUT_EN_MASK         0x00000001L
#define TEST_DEBUG_CNTL_BG__TEST_DEBUG_OUT_EN              0x00000001L
#define TEST_DEBUG_CNTL_BG__TEST_DEBUG_IN_EN_MASK          0x00000002L
#define TEST_DEBUG_CNTL_BG__TEST_DEBUG_IN_EN               0x00000002L
#define TEST_DEBUG_CNTL_BG__TEST_IDDQ_EN_MASK              0x00000004L
#define TEST_DEBUG_CNTL_BG__TEST_IDDQ_EN                   0x00000004L
#define TEST_DEBUG_CNTL_BG__TEST_BLOCK_SEL_MASK            0x00003f00L
#define TEST_DEBUG_CNTL_BG__TEST_ENABLE_MASK               0x00008000L
#define TEST_DEBUG_CNTL_BG__TEST_ENABLE                    0x00008000L
#define TEST_DEBUG_CNTL_BG__TEST_DELAY_IN_MASK             0x00010000L
#define TEST_DEBUG_CNTL_BG__TEST_DELAY_IN                  0x00010000L
#define TEST_DEBUG_CNTL_BG__CLK_OUT_EN_MASK                0x04000000L
#define TEST_DEBUG_CNTL_BG__CLK_OUT_EN                     0x04000000L
#define TEST_DEBUG_CNTL_BG__CLKMUX_OUT_SEL_MASK            0x38000000L

// TEST_DEBUG_MUX_BG
#define TEST_DEBUG_MUX_BG__TEST_DEBUG_SEL_MASK             0x0000003fL
#define TEST_DEBUG_MUX_BG__TEST_CLK0_MASK                  0x00001f00L
#define TEST_DEBUG_MUX_BG__TEST_CLK0_INV_MASK              0x00008000L
#define TEST_DEBUG_MUX_BG__TEST_CLK0_INV                   0x00008000L
#define TEST_DEBUG_MUX_BG__TEST_CLK1_MASK                  0x001f0000L
#define TEST_DEBUG_MUX_BG__TEST_CLK1_INV_MASK              0x00800000L
#define TEST_DEBUG_MUX_BG__TEST_CLK1_INV                   0x00800000L
#define TEST_DEBUG_MUX_BG__DEBUG_SEL_MASK                  0x0f000000L

// TEST_DEBUG_OUT_BG
#define TEST_DEBUG_OUT_BG__DBUG_OUT_PREMUX_MASK            0x00000fffL
#define TEST_DEBUG_OUT_BG__DBUG_OUT_POSTMUX_MASK           0x07ff0000L

// ROMMUX_CNTL
#define ROMMUX_CNTL__ROM_CLK_DIVIDE_MASK                   0x0000001fL
#define ROMMUX_CNTL__STR_ROMCLK_MASK                       0x00000020L
#define ROMMUX_CNTL__STR_ROMCLK                            0x00000020L
#define ROMMUX_CNTL__GPIOPAD_MASK_MASK                     0xffff0000L

// TEST_GPIOPAD_MASK_BG
#define TEST_GPIOPAD_MASK_BG__GPIOPAD_A_MASK               0x0000ffffL
#define TEST_GPIOPAD_MASK_BG__GPIOPAD_EN_MASK              0xffff0000L

// SEPROM_CNTL1_BG
#define SEPROM_CNTL1_BG__WRITE_ENABLE_MASK                 0x00000001L
#define SEPROM_CNTL1_BG__WRITE_ENABLE                      0x00000001L
#define SEPROM_CNTL1_BG__WRITE_DISABLE_MASK                0x00000002L
#define SEPROM_CNTL1_BG__WRITE_DISABLE                     0x00000002L
#define SEPROM_CNTL1_BG__READ_CONFIG_MASK                  0x00000004L
#define SEPROM_CNTL1_BG__READ_CONFIG                       0x00000004L
#define SEPROM_CNTL1_BG__WRITE_CONFIG_MASK                 0x00000008L
#define SEPROM_CNTL1_BG__WRITE_CONFIG                      0x00000008L
#define SEPROM_CNTL1_BG__READ_STATUS_MASK                  0x00000010L
#define SEPROM_CNTL1_BG__READ_STATUS                       0x00000010L
#define SEPROM_CNTL1_BG__SECT_TO_SRAM_MASK                 0x00000020L
#define SEPROM_CNTL1_BG__SECT_TO_SRAM                      0x00000020L
#define SEPROM_CNTL1_BG__READY_BUSY_MASK                   0x00000080L
#define SEPROM_CNTL1_BG__READY_BUSY                        0x00000080L
#define SEPROM_CNTL1_BG__SEPROM_BUSY_MASK                  0x00000100L
#define SEPROM_CNTL1_BG__SEPROM_BUSY                       0x00000100L
#define SEPROM_CNTL1_BG__BCNT_OVER_WTE_EN_MASK             0x00000200L
#define SEPROM_CNTL1_BG__BCNT_OVER_WTE_EN                  0x00000200L
#define SEPROM_CNTL1_BG__RB_MASKB_MASK                     0x00000400L
#define SEPROM_CNTL1_BG__RB_MASKB                          0x00000400L
#define SEPROM_CNTL1_BG__SOFT_RESET_MASK                   0x00000800L
#define SEPROM_CNTL1_BG__SOFT_RESET                        0x00000800L
#define SEPROM_CNTL1_BG__STATE_IDLEb_MASK                  0x00001000L
#define SEPROM_CNTL1_BG__STATE_IDLEb                       0x00001000L
#define SEPROM_CNTL1_BG__BULK_ERASE_MASK                   0x00002000L
#define SEPROM_CNTL1_BG__BULK_ERASE                        0x00002000L
#define SEPROM_CNTL1_BG__BYTE_CNT_MASK                     0x00ff0000L
#define SEPROM_CNTL1_BG__SCK_PRESCALE_MASK                 0xff000000L

// SEPROM_CNTL2_BG
#define SEPROM_CNTL2_BG__WAIT_CYCLE_MASK                   0x000000ffL
#define SEPROM_CNTL2_BG__AUTO_ADDR_SAMPLE_MASK             0x00000100L
#define SEPROM_CNTL2_BG__AUTO_ADDR_SAMPLE                  0x00000100L
#define SEPROM_CNTL2_BG__SEC_COMMAND_MASK                  0x00ff0000L

// AGP_PLL_CNTL_P
#define AGP_PLL_CNTL_P__APLL_SLEEP_MASK                    0x00000001L
#define AGP_PLL_CNTL_P__APLL_SLEEP                         0x00000001L
#define AGP_PLL_CNTL_P__APLL_RESET_MASK                    0x00000002L
#define AGP_PLL_CNTL_P__APLL_RESET                         0x00000002L
#define AGP_PLL_CNTL_P__APLL_XSEL_MASK                     0x0000000cL
#define AGP_PLL_CNTL_P__APLL_TST_EN_MASK                   0x00000010L
#define AGP_PLL_CNTL_P__APLL_TST_EN                        0x00000010L
#define AGP_PLL_CNTL_P__APLL_TCPOFF_MASK                   0x00000020L
#define AGP_PLL_CNTL_P__APLL_TCPOFF                        0x00000020L
#define AGP_PLL_CNTL_P__APLL_TVCOMAX_MASK                  0x00000040L
#define AGP_PLL_CNTL_P__APLL_TVCOMAX                       0x00000040L
#define AGP_PLL_CNTL_P__APLL_REF_SKEW_MASK                 0x00000380L
#define AGP_PLL_CNTL_P__APLL_FB_SKEW_MASK                  0x00001c00L
#define AGP_PLL_CNTL_P__APLL_X0_CLK_SKEW_MASK              0x0000e000L
#define AGP_PLL_CNTL_P__APLL_X1_CLK_SKEW_MASK              0x00070000L
#define AGP_PLL_CNTL_P__APLL_X2_CLK_SKEW_MASK              0x00380000L
#define AGP_PLL_CNTL_P__APLL_X4_CLK_SKEW_MASK              0x01c00000L
#define AGP_PLL_CNTL_P__APLL_PUMP_GAIN_MASK                0x0e000000L
#define AGP_PLL_CNTL_P__APLL_VCO_GAIN_MASK                 0x70000000L

// AGP_PLL_CNTL_X
#define AGP_PLL_CNTL_X__APLL_SLEEP_MASK                    0x00000001L
#define AGP_PLL_CNTL_X__APLL_SLEEP                         0x00000001L
#define AGP_PLL_CNTL_X__APLL_RESET_MASK                    0x00000002L
#define AGP_PLL_CNTL_X__APLL_RESET                         0x00000002L
#define AGP_PLL_CNTL_X__APLL_XSEL_MASK                     0x0000000cL
#define AGP_PLL_CNTL_X__APLL_TST_EN_MASK                   0x00000010L
#define AGP_PLL_CNTL_X__APLL_TST_EN                        0x00000010L
#define AGP_PLL_CNTL_X__APLL_TCPOFF_MASK                   0x00000020L
#define AGP_PLL_CNTL_X__APLL_TCPOFF                        0x00000020L
#define AGP_PLL_CNTL_X__APLL_TVCOMAX_MASK                  0x00000040L
#define AGP_PLL_CNTL_X__APLL_TVCOMAX                       0x00000040L
#define AGP_PLL_CNTL_X__APLL_REF_SKEW_MASK                 0x00000380L
#define AGP_PLL_CNTL_X__APLL_FB_SKEW_MASK                  0x00001c00L
#define AGP_PLL_CNTL_X__APLL_X0_CLK_SKEW_MASK              0x0000e000L
#define AGP_PLL_CNTL_X__APLL_X1_CLK_SKEW_MASK              0x00070000L
#define AGP_PLL_CNTL_X__APLL_X2_CLK_SKEW_MASK              0x00380000L
#define AGP_PLL_CNTL_X__APLL_X4_CLK_SKEW_MASK              0x01c00000L
#define AGP_PLL_CNTL_X__APLL_PUMP_GAIN_MASK                0x0e000000L
#define AGP_PLL_CNTL_X__APLL_VCO_GAIN_MASK                 0x70000000L

// AGP_PLL_CNTL_Y
#define AGP_PLL_CNTL_Y__APLL_SLEEP_MASK                    0x00000001L
#define AGP_PLL_CNTL_Y__APLL_SLEEP                         0x00000001L
#define AGP_PLL_CNTL_Y__APLL_RESET_MASK                    0x00000002L
#define AGP_PLL_CNTL_Y__APLL_RESET                         0x00000002L
#define AGP_PLL_CNTL_Y__APLL_XSEL_MASK                     0x0000000cL
#define AGP_PLL_CNTL_Y__APLL_TST_EN_MASK                   0x00000010L
#define AGP_PLL_CNTL_Y__APLL_TST_EN                        0x00000010L
#define AGP_PLL_CNTL_Y__APLL_TCPOFF_MASK                   0x00000020L
#define AGP_PLL_CNTL_Y__APLL_TCPOFF                        0x00000020L
#define AGP_PLL_CNTL_Y__APLL_TVCOMAX_MASK                  0x00000040L
#define AGP_PLL_CNTL_Y__APLL_TVCOMAX                       0x00000040L
#define AGP_PLL_CNTL_Y__APLL_REF_SKEW_MASK                 0x00000380L
#define AGP_PLL_CNTL_Y__APLL_FB_SKEW_MASK                  0x00001c00L
#define AGP_PLL_CNTL_Y__APLL_X0_CLK_SKEW_MASK              0x0000e000L
#define AGP_PLL_CNTL_Y__APLL_X1_CLK_SKEW_MASK              0x00070000L
#define AGP_PLL_CNTL_Y__APLL_X2_CLK_SKEW_MASK              0x00380000L
#define AGP_PLL_CNTL_Y__APLL_X4_CLK_SKEW_MASK              0x01c00000L
#define AGP_PLL_CNTL_Y__APLL_PUMP_GAIN_MASK                0x0e000000L
#define AGP_PLL_CNTL_Y__APLL_VCO_GAIN_MASK                 0x70000000L

// PLL_TEST_CNTL_BG
#define PLL_TEST_CNTL_BG__TST_SRC_SEL_MASK                 0x0000001fL
#define PLL_TEST_CNTL_BG__TST_SRC_INV_MASK                 0x00000080L
#define PLL_TEST_CNTL_BG__TST_SRC_INV                      0x00000080L
#define PLL_TEST_CNTL_BG__PLL_MASK_READ_B_MASK             0x00000200L
#define PLL_TEST_CNTL_BG__PLL_MASK_READ_B                  0x00000200L
#define PLL_TEST_CNTL_BG__TEST_COUNT_MASK                  0xff000000L

// CONFIG_XSTRAP2
#define CONFIG_XSTRAP2__NOROM_FB_SKEW_MASK                 0x0000000fL
#define CONFIG_XSTRAP2__AGPVCOGAIN_MASK                    0x00000070L
#define CONFIG_XSTRAP2__AGPCPGAIN_MASK                     0x00000380L
#define CONFIG_XSTRAP2__Y_X1CLK_SKEW_MASK                  0x00001c00L
#define CONFIG_XSTRAP2__SGD_MODE_MASK                      0x00002000L
#define CONFIG_XSTRAP2__SGD_MODE                           0x00002000L
#define CONFIG_XSTRAP2__Y_3RD_PARTY_MASK                   0x00004000L
#define CONFIG_XSTRAP2__Y_3RD_PARTY                        0x00004000L
#define CONFIG_XSTRAP2__CAP_MODE_INT_X_MASK                0x00018000L
#define CONFIG_XSTRAP2__CAP_MODE_INT_Y_MASK                0x00060000L
#define CONFIG_XSTRAP2__CAP_MODE_EXT_XY_MASK               0x00180000L
#define CONFIG_XSTRAP2__BLANK_ROM_MASK                     0x00200000L
#define CONFIG_XSTRAP2__BLANK_ROM                          0x00200000L
#define CONFIG_XSTRAP2__S_RQ_DEPTH_MASK                    0x0fc00000L
#define CONFIG_XSTRAP2__AGPVCOGAIN_Y_MASK                  0x70000000L
#define CONFIG_XSTRAP2__PCI66_MODE_MASK                    0x80000000L
#define CONFIG_XSTRAP2__PCI66_MODE                         0x80000000L

// STRAP_SCRATCH_REG
#define STRAP_SCRATCH_REG__SPARE_ROM_BYTE_MASK             0x000000ffL

#endif


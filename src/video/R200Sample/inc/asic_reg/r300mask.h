

#if !defined (_khan_MASK_HEADER)
#define _khan_MASK_HEADER
/*
*	khan_mask.h
*
*	Register Spec Release:  Chip Spec 1.37
*
*
*	 (c) 2000 ATI Technologies Inc.  (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
*/

// GB_VAP_RASTER_VTX_FMT_0
#define GB_VAP_RASTER_VTX_FMT_0__VTX_POS_PRESENT_MASK      0x00000001L
#define GB_VAP_RASTER_VTX_FMT_0__VTX_POS_PRESENT           0x00000001L
#define GB_VAP_RASTER_VTX_FMT_0__VTX_COLOR_0_PRESENT_MASK  0x00000002L
#define GB_VAP_RASTER_VTX_FMT_0__VTX_COLOR_0_PRESENT       0x00000002L
#define GB_VAP_RASTER_VTX_FMT_0__VTX_COLOR_1_PRESENT_MASK  0x00000004L
#define GB_VAP_RASTER_VTX_FMT_0__VTX_COLOR_1_PRESENT       0x00000004L
#define GB_VAP_RASTER_VTX_FMT_0__VTX_COLOR_2_PRESENT_MASK  0x00000008L
#define GB_VAP_RASTER_VTX_FMT_0__VTX_COLOR_2_PRESENT       0x00000008L
#define GB_VAP_RASTER_VTX_FMT_0__VTX_COLOR_3_PRESENT_MASK  0x00000010L
#define GB_VAP_RASTER_VTX_FMT_0__VTX_COLOR_3_PRESENT       0x00000010L
#define GB_VAP_RASTER_VTX_FMT_0__VTX_COLOR_SPARE_MASK      0x000001e0L
#define GB_VAP_RASTER_VTX_FMT_0__VTX_PT_SIZE_PRESENT_MASK  0x00010000L
#define GB_VAP_RASTER_VTX_FMT_0__VTX_PT_SIZE_PRESENT       0x00010000L
#define GB_VAP_RASTER_VTX_FMT_0__VTX_UNUSED_MASK           0xfffe0000L

// GB_VAP_RASTER_VTX_FMT_1
#define GB_VAP_RASTER_VTX_FMT_1__TEX_0_COMP_CNT_MASK       0x00000007L
#define GB_VAP_RASTER_VTX_FMT_1__TEX_1_COMP_CNT_MASK       0x00000038L
#define GB_VAP_RASTER_VTX_FMT_1__TEX_2_COMP_CNT_MASK       0x000001c0L
#define GB_VAP_RASTER_VTX_FMT_1__TEX_3_COMP_CNT_MASK       0x00000e00L
#define GB_VAP_RASTER_VTX_FMT_1__TEX_4_COMP_CNT_MASK       0x00007000L
#define GB_VAP_RASTER_VTX_FMT_1__TEX_5_COMP_CNT_MASK       0x00038000L
#define GB_VAP_RASTER_VTX_FMT_1__TEX_6_COMP_CNT_MASK       0x001c0000L
#define GB_VAP_RASTER_VTX_FMT_1__TEX_7_COMP_CNT_MASK       0x00e00000L

// SIM_RAS_FINISH_TOKEN
#define SIM_RAS_FINISH_TOKEN__RAS_FINISH_TOKEN_MASK        0xffffffffL

// SIM_END_TOKEN
#define SIM_END_TOKEN__END_TOKEN_MASK                      0xffffffffL

// GB_ENABLE
#define GB_ENABLE__POINT_STUFF_ENABLE_MASK                 0x00000001L
#define GB_ENABLE__POINT_STUFF_ENABLE                      0x00000001L
#define GB_ENABLE__LINE_STUFF_ENABLE_MASK                  0x00000002L
#define GB_ENABLE__LINE_STUFF_ENABLE                       0x00000002L
#define GB_ENABLE__TRIANGLE_STUFF_ENABLE_MASK              0x00000004L
#define GB_ENABLE__TRIANGLE_STUFF_ENABLE                   0x00000004L
#define GB_ENABLE__STENCIL_AUTO_MASK                       0x00000030L
#define GB_ENABLE__TEX0_SOURCE_MASK                        0x00030000L
#define GB_ENABLE__TEX1_SOURCE_MASK                        0x000c0000L
#define GB_ENABLE__TEX2_SOURCE_MASK                        0x00300000L
#define GB_ENABLE__TEX3_SOURCE_MASK                        0x00c00000L
#define GB_ENABLE__TEX4_SOURCE_MASK                        0x03000000L
#define GB_ENABLE__TEX5_SOURCE_MASK                        0x0c000000L
#define GB_ENABLE__TEX6_SOURCE_MASK                        0x30000000L
#define GB_ENABLE__TEX7_SOURCE_MASK                        0xc0000000L

// GB_VAP_REMAP
#define GB_VAP_REMAP__UNUSED_MASK                          0xffffffffL

// GB_MSPOS0
#define GB_MSPOS0__MS_X0_MASK                              0x0000000fL
#define GB_MSPOS0__MS_Y0_MASK                              0x000000f0L
#define GB_MSPOS0__MS_X1_MASK                              0x00000f00L
#define GB_MSPOS0__MS_Y1_MASK                              0x0000f000L
#define GB_MSPOS0__MS_X2_MASK                              0x000f0000L
#define GB_MSPOS0__MS_Y2_MASK                              0x00f00000L
#define GB_MSPOS0__MSBD0_Y_MASK                            0x0f000000L
#define GB_MSPOS0__MSBD0_X_MASK                            0xf0000000L

// GB_MSPOS1
#define GB_MSPOS1__MS_X3_MASK                              0x0000000fL
#define GB_MSPOS1__MS_Y3_MASK                              0x000000f0L
#define GB_MSPOS1__MS_X4_MASK                              0x00000f00L
#define GB_MSPOS1__MS_Y4_MASK                              0x0000f000L
#define GB_MSPOS1__MS_X5_MASK                              0x000f0000L
#define GB_MSPOS1__MS_Y5_MASK                              0x00f00000L
#define GB_MSPOS1__MSBD1_MASK                              0x0f000000L

// GB_TILE_CONFIG
#define GB_TILE_CONFIG__ENABLE_MASK                        0x00000001L
#define GB_TILE_CONFIG__ENABLE                             0x00000001L
#define GB_TILE_CONFIG__PIPE_COUNT_MASK                    0x0000000eL
#define GB_TILE_CONFIG__TILE_SIZE_MASK                     0x00000030L
#define GB_TILE_CONFIG__SUPER_SIZE_MASK                    0x000001c0L
#define GB_TILE_CONFIG__SUPER_X_MASK                       0x00000e00L
#define GB_TILE_CONFIG__SUPER_Y_MASK                       0x00007000L
#define GB_TILE_CONFIG__SUPER_TILE_MASK                    0x00008000L
#define GB_TILE_CONFIG__SUPER_TILE                         0x00008000L
#define GB_TILE_CONFIG__SUBPIXEL_MASK                      0x00010000L
#define GB_TILE_CONFIG__SUBPIXEL                           0x00010000L
#define GB_TILE_CONFIG__QUADS_PER_RAS_MASK                 0x00060000L
#define GB_TILE_CONFIG__BB_SCAN_MASK                       0x00080000L
#define GB_TILE_CONFIG__BB_SCAN                            0x00080000L

// GB_FIFO_SIZE
#define GB_FIFO_SIZE__SC_IFIFO_SIZE_MASK                   0x00000003L
#define GB_FIFO_SIZE__SC_TZFIFO_SIZE_MASK                  0x0000000cL
#define GB_FIFO_SIZE__SC_BFIFO_SIZE_MASK                   0x00000030L
#define GB_FIFO_SIZE__RS_TFIFO_SIZE_MASK                   0x000000c0L
#define GB_FIFO_SIZE__RS_CFIFO_SIZE_MASK                   0x00000300L
#define GB_FIFO_SIZE__US_RAM_SIZE_MASK                     0x00000c00L
#define GB_FIFO_SIZE__US_OFIFO_SIZE_MASK                   0x00003000L
#define GB_FIFO_SIZE__US_WFIFO_SIZE_MASK                   0x0000c000L
#define GB_FIFO_SIZE__RS_HIGHWATER_COL_MASK                0x00070000L
#define GB_FIFO_SIZE__RS_HIGHWATER_TEX_MASK                0x00380000L
#define GB_FIFO_SIZE__US_OFIFO_HIGHWATER_MASK              0x00c00000L
#define GB_FIFO_SIZE__US_CUBE_FIFO_HIGHWATER_MASK          0x0f000000L

// GB_SELECT
#define GB_SELECT__FOG_SELECT_MASK                         0x00000007L
#define GB_SELECT__DEPTH_SELECT_MASK                       0x00000008L
#define GB_SELECT__DEPTH_SELECT                            0x00000008L
#define GB_SELECT__W_SELECT_MASK                           0x00000010L
#define GB_SELECT__W_SELECT                                0x00000010L

// GB_AA_CONFIG
#define GB_AA_CONFIG__AA_ENABLE_MASK                       0x00000001L
#define GB_AA_CONFIG__AA_ENABLE                            0x00000001L
#define GB_AA_CONFIG__NUM_AA_SUBSAMPLES_MASK               0x00000006L

// GA_VAP_VF_CNTL
#define GA_VAP_VF_CNTL__PRIM_TYPE_MASK                     0x0000000fL
#define GA_VAP_VF_CNTL__VF_UNUSED_MASK                     0xfffffff0L

// GA_POINT_S0
#define GA_POINT_S0__S0_MASK                               0xffffffffL

// GA_POINT_T0
#define GA_POINT_T0__T0_MASK                               0xffffffffL

// GA_POINT_S1
#define GA_POINT_S1__S1_MASK                               0xffffffffL

// GA_POINT_T1
#define GA_POINT_T1__T1_MASK                               0xffffffffL

// GA_TRIANGLE_STIPPLE
#define GA_TRIANGLE_STIPPLE__X_SHIFT_MASK                  0x0000000fL
#define GA_TRIANGLE_STIPPLE__Y_SHIFT_MASK                  0x000f0000L

// GA_POINT_SIZE
#define GA_POINT_SIZE__HEIGHT_MASK                         0x0000ffffL
#define GA_POINT_SIZE__WIDTH_MASK                          0xffff0000L

// GA_POINT_MINMAX
#define GA_POINT_MINMAX__MIN_SIZE_MASK                     0x0000ffffL
#define GA_POINT_MINMAX__MAX_SIZE_MASK                     0xffff0000L

// GA_LINE_CNTL
#define GA_LINE_CNTL__WIDTH_MASK                           0x0000ffffL
#define GA_LINE_CNTL__END_TYPE_MASK                        0x00030000L

// GA_LINE_STIPPLE_CONFIG
#define GA_LINE_STIPPLE_CONFIG__LINE_RESET_MASK            0x00000003L
#define GA_LINE_STIPPLE_CONFIG__STIPPLE_SCALE_MASK         0xfffffffcL

// GA_LINE_STIPPLE_VALUE
#define GA_LINE_STIPPLE_VALUE__STIPPLE_VALUE_MASK          0xffffffffL

// GA_LINE_S0
#define GA_LINE_S0__S0_MASK                                0xffffffffL

// GA_LINE_S1
#define GA_LINE_S1__S1_MASK                                0xffffffffL

// GA_PERF
#define GA_PERF__PERF0_SEL_MASK                            0x000000ffL
#define GA_PERF__PERF1_SEL_MASK                            0x0000ff00L
#define GA_PERF__PERF2_SEL_MASK                            0x00ff0000L
#define GA_PERF__PERF3_SEL_MASK                            0xff000000L

// GA_PERF_READ0
#define GA_PERF_READ0__PERF_MASK                           0xffffffffL

// GA_PERF_READ1
#define GA_PERF_READ1__PERF_MASK                           0xffffffffL

// GA_PERF_READ2
#define GA_PERF_READ2__PERF_MASK                           0xffffffffL

// GA_PERF_READ3
#define GA_PERF_READ3__PERF_MASK                           0xffffffffL

// GA_ENHANCE
#define GA_ENHANCE__DEADLOCK_CNTL_MASK                     0x00000001L
#define GA_ENHANCE__DEADLOCK_CNTL                          0x00000001L
#define GA_ENHANCE__FASTSYNC_CNTL_MASK                     0x00000002L
#define GA_ENHANCE__FASTSYNC_CNTL                          0x00000002L

// GA_COLOR_CONTROL
#define GA_COLOR_CONTROL__RGB0_SHADING_MASK                0x00000003L
#define GA_COLOR_CONTROL__ALPHA0_SHADING_MASK              0x0000000cL
#define GA_COLOR_CONTROL__RGB1_SHADING_MASK                0x00000030L
#define GA_COLOR_CONTROL__ALPHA1_SHADING_MASK              0x000000c0L
#define GA_COLOR_CONTROL__RGB2_SHADING_MASK                0x00000300L
#define GA_COLOR_CONTROL__ALPHA2_SHADING_MASK              0x00000c00L
#define GA_COLOR_CONTROL__RGB3_SHADING_MASK                0x00003000L
#define GA_COLOR_CONTROL__ALPHA3_SHADING_MASK              0x0000c000L
#define GA_COLOR_CONTROL__PROVOKING_VERTEX_MASK            0x00030000L

// GA_SOLID_RG
#define GA_SOLID_RG__COLOR_GREEN_MASK                      0x0000ffffL
#define GA_SOLID_RG__COLOR_RED_MASK                        0xffff0000L

// GA_SOLID_BA
#define GA_SOLID_BA__COLOR_ALPHA_MASK                      0x0000ffffL
#define GA_SOLID_BA__COLOR_BLUE_MASK                       0xffff0000L

// GA_POLY_MODE
#define GA_POLY_MODE__POLY_MODE_MASK                       0x00000003L
#define GA_POLY_MODE__FRONT_PTYPE_MASK                     0x00000070L
#define GA_POLY_MODE__BACK_PTYPE_MASK                      0x00000380L

// GA_ROUND_MODE
#define GA_ROUND_MODE__GEOMETRY_ROUND_MASK                 0x00000003L
#define GA_ROUND_MODE__COLOR_ROUND_MASK                    0x0000000cL
#define GA_ROUND_MODE__RGB_CLAMP_MASK                      0x00000010L
#define GA_ROUND_MODE__RGB_CLAMP                           0x00000010L
#define GA_ROUND_MODE__ALPHA_CLAMP_MASK                    0x00000020L
#define GA_ROUND_MODE__ALPHA_CLAMP                         0x00000020L

// GA_OFFSET
#define GA_OFFSET__X_OFFSET_MASK                           0x0000ffffL
#define GA_OFFSET__Y_OFFSET_MASK                           0xffff0000L

// GA_FOG_SCALE
#define GA_FOG_SCALE__VALUE_MASK                           0xffffffffL

// GA_FOG_OFFSET
#define GA_FOG_OFFSET__VALUE_MASK                          0xffffffffL

// GA_SOFT_RESET
#define GA_SOFT_RESET__SOFT_RESET_COUNT_MASK               0x0000ffffL

// SU_TEX_WRAP
#define SU_TEX_WRAP__T0C0_MASK                             0x00000001L
#define SU_TEX_WRAP__T0C0                                  0x00000001L
#define SU_TEX_WRAP__T0C1_MASK                             0x00000002L
#define SU_TEX_WRAP__T0C1                                  0x00000002L
#define SU_TEX_WRAP__T0C2_MASK                             0x00000004L
#define SU_TEX_WRAP__T0C2                                  0x00000004L
#define SU_TEX_WRAP__T0C3_MASK                             0x00000008L
#define SU_TEX_WRAP__T0C3                                  0x00000008L
#define SU_TEX_WRAP__T1C0_MASK                             0x00000010L
#define SU_TEX_WRAP__T1C0                                  0x00000010L
#define SU_TEX_WRAP__T1C1_MASK                             0x00000020L
#define SU_TEX_WRAP__T1C1                                  0x00000020L
#define SU_TEX_WRAP__T1C2_MASK                             0x00000040L
#define SU_TEX_WRAP__T1C2                                  0x00000040L
#define SU_TEX_WRAP__T1C3_MASK                             0x00000080L
#define SU_TEX_WRAP__T1C3                                  0x00000080L
#define SU_TEX_WRAP__T2C0_MASK                             0x00000100L
#define SU_TEX_WRAP__T2C0                                  0x00000100L
#define SU_TEX_WRAP__T2C1_MASK                             0x00000200L
#define SU_TEX_WRAP__T2C1                                  0x00000200L
#define SU_TEX_WRAP__T2C2_MASK                             0x00000400L
#define SU_TEX_WRAP__T2C2                                  0x00000400L
#define SU_TEX_WRAP__T2C3_MASK                             0x00000800L
#define SU_TEX_WRAP__T2C3                                  0x00000800L
#define SU_TEX_WRAP__T3C0_MASK                             0x00001000L
#define SU_TEX_WRAP__T3C0                                  0x00001000L
#define SU_TEX_WRAP__T3C1_MASK                             0x00002000L
#define SU_TEX_WRAP__T3C1                                  0x00002000L
#define SU_TEX_WRAP__T3C2_MASK                             0x00004000L
#define SU_TEX_WRAP__T3C2                                  0x00004000L
#define SU_TEX_WRAP__T3C3_MASK                             0x00008000L
#define SU_TEX_WRAP__T3C3                                  0x00008000L
#define SU_TEX_WRAP__T4C0_MASK                             0x00010000L
#define SU_TEX_WRAP__T4C0                                  0x00010000L
#define SU_TEX_WRAP__T4C1_MASK                             0x00020000L
#define SU_TEX_WRAP__T4C1                                  0x00020000L
#define SU_TEX_WRAP__T4C2_MASK                             0x00040000L
#define SU_TEX_WRAP__T4C2                                  0x00040000L
#define SU_TEX_WRAP__T4C3_MASK                             0x00080000L
#define SU_TEX_WRAP__T4C3                                  0x00080000L
#define SU_TEX_WRAP__T5C0_MASK                             0x00100000L
#define SU_TEX_WRAP__T5C0                                  0x00100000L
#define SU_TEX_WRAP__T5C1_MASK                             0x00200000L
#define SU_TEX_WRAP__T5C1                                  0x00200000L
#define SU_TEX_WRAP__T5C2_MASK                             0x00400000L
#define SU_TEX_WRAP__T5C2                                  0x00400000L
#define SU_TEX_WRAP__T5C3_MASK                             0x00800000L
#define SU_TEX_WRAP__T5C3                                  0x00800000L
#define SU_TEX_WRAP__T6C0_MASK                             0x01000000L
#define SU_TEX_WRAP__T6C0                                  0x01000000L
#define SU_TEX_WRAP__T6C1_MASK                             0x02000000L
#define SU_TEX_WRAP__T6C1                                  0x02000000L
#define SU_TEX_WRAP__T6C2_MASK                             0x04000000L
#define SU_TEX_WRAP__T6C2                                  0x04000000L
#define SU_TEX_WRAP__T6C3_MASK                             0x08000000L
#define SU_TEX_WRAP__T6C3                                  0x08000000L
#define SU_TEX_WRAP__T7C0_MASK                             0x10000000L
#define SU_TEX_WRAP__T7C0                                  0x10000000L
#define SU_TEX_WRAP__T7C1_MASK                             0x20000000L
#define SU_TEX_WRAP__T7C1                                  0x20000000L
#define SU_TEX_WRAP__T7C2_MASK                             0x40000000L
#define SU_TEX_WRAP__T7C2                                  0x40000000L
#define SU_TEX_WRAP__T7C3_MASK                             0x80000000L
#define SU_TEX_WRAP__T7C3                                  0x80000000L

// SU_POLY_OFFSET_FRONT_SCALE
#define SU_POLY_OFFSET_FRONT_SCALE__SCALE_MASK             0xffffffffL

// SU_POLY_OFFSET_FRONT_OFFSET
#define SU_POLY_OFFSET_FRONT_OFFSET__OFFSET_MASK           0xffffffffL

// SU_POLY_OFFSET_BACK_SCALE
#define SU_POLY_OFFSET_BACK_SCALE__SCALE_MASK              0xffffffffL

// SU_POLY_OFFSET_BACK_OFFSET
#define SU_POLY_OFFSET_BACK_OFFSET__OFFSET_MASK            0xffffffffL

// SU_POLY_OFFSET_ENABLE
#define SU_POLY_OFFSET_ENABLE__FRONT_ENABLE_MASK           0x00000001L
#define SU_POLY_OFFSET_ENABLE__FRONT_ENABLE                0x00000001L
#define SU_POLY_OFFSET_ENABLE__BACK_ENABLE_MASK            0x00000002L
#define SU_POLY_OFFSET_ENABLE__BACK_ENABLE                 0x00000002L
#define SU_POLY_OFFSET_ENABLE__PARA_ENABLE_MASK            0x00000004L
#define SU_POLY_OFFSET_ENABLE__PARA_ENABLE                 0x00000004L

// SU_CULL_MODE
#define SU_CULL_MODE__CULL_FRONT_MASK                      0x00000001L
#define SU_CULL_MODE__CULL_FRONT                           0x00000001L
#define SU_CULL_MODE__CULL_BACK_MASK                       0x00000002L
#define SU_CULL_MODE__CULL_BACK                            0x00000002L
#define SU_CULL_MODE__FACE_MASK                            0x00000004L
#define SU_CULL_MODE__FACE                                 0x00000004L

// SU_ENHANCE
#define SU_ENHANCE__ADJ_SHIFT_MASK                         0x00000003L

// SU_DEPTH_SCALE
#define SU_DEPTH_SCALE__SCALE_MASK                         0xffffffffL

// SU_DEPTH_OFFSET
#define SU_DEPTH_OFFSET__OFFSET_MASK                       0xffffffffL

// SU_REG_DEST
#define SU_REG_DEST__SELECT_MASK                           0x0000000fL

// SU_PERF
#define SU_PERF__PERF0_SEL_MASK                            0x000000ffL
#define SU_PERF__PERF1_SEL_MASK                            0x0000ff00L
#define SU_PERF__PERF2_SEL_MASK                            0x00ff0000L
#define SU_PERF__PERF3_SEL_MASK                            0xff000000L

// SU_PERF_READ0
#define SU_PERF_READ0__PERF_READ_MASK                      0xffffffffL

// SU_PERF_READ1
#define SU_PERF_READ1__PERF_READ_MASK                      0xffffffffL

// SU_PERF_READ2
#define SU_PERF_READ2__PERF_READ_MASK                      0xffffffffL

// SU_PERF_READ3
#define SU_PERF_READ3__PERF_READ_MASK                      0xffffffffL

// SU_SRU_PERF0_0
#define SU_SRU_PERF0_0__PERF_READ_MASK                     0xffffffffL

// SU_SRU_PERF0_1
#define SU_SRU_PERF0_1__PERF_READ_MASK                     0xffffffffL

// SU_SRU_PERF0_2
#define SU_SRU_PERF0_2__PERF_READ_MASK                     0xffffffffL

// SU_SRU_PERF0_3
#define SU_SRU_PERF0_3__PERF_READ_MASK                     0xffffffffL

// SU_SRU_PERF1_0
#define SU_SRU_PERF1_0__PERF_READ_MASK                     0xffffffffL

// SU_SRU_PERF1_1
#define SU_SRU_PERF1_1__PERF_READ_MASK                     0xffffffffL

// SU_SRU_PERF1_2
#define SU_SRU_PERF1_2__PERF_READ_MASK                     0xffffffffL

// SU_SRU_PERF1_3
#define SU_SRU_PERF1_3__PERF_READ_MASK                     0xffffffffL

// RS_COUNT
#define RS_COUNT__IT_COUNT_MASK                            0x0000007fL
#define RS_COUNT__IC_COUNT_MASK                            0x00000780L
#define RS_COUNT__W_COUNT_MASK                             0x00000800L
#define RS_COUNT__W_COUNT                                  0x00000800L
#define RS_COUNT__W_ADDR_MASK                              0x0003f000L
#define RS_COUNT__HIRES_EN_MASK                            0x00040000L
#define RS_COUNT__HIRES_EN                                 0x00040000L

// RS_IP_0
#define RS_IP_0__TEX_PTR_MASK                              0x0000003fL
#define RS_IP_0__COL_PTR_MASK                              0x000001c0L
#define RS_IP_0__COL_FMT_MASK                              0x00001e00L
#define RS_IP_0__SEL_S_MASK                                0x0000e000L
#define RS_IP_0__SEL_T_MASK                                0x00070000L
#define RS_IP_0__SEL_R_MASK                                0x00380000L
#define RS_IP_0__SEL_Q_MASK                                0x01c00000L

// RS_IP_1
#define RS_IP_1__TEX_PTR_MASK                              0x0000003fL
#define RS_IP_1__COL_PTR_MASK                              0x000001c0L
#define RS_IP_1__COL_FMT_MASK                              0x00001e00L
#define RS_IP_1__SEL_S_MASK                                0x0000e000L
#define RS_IP_1__SEL_T_MASK                                0x00070000L
#define RS_IP_1__SEL_R_MASK                                0x00380000L
#define RS_IP_1__SEL_Q_MASK                                0x01c00000L

// RS_IP_2
#define RS_IP_2__TEX_PTR_MASK                              0x0000003fL
#define RS_IP_2__COL_PTR_MASK                              0x000001c0L
#define RS_IP_2__COL_FMT_MASK                              0x00001e00L
#define RS_IP_2__SEL_S_MASK                                0x0000e000L
#define RS_IP_2__SEL_T_MASK                                0x00070000L
#define RS_IP_2__SEL_R_MASK                                0x00380000L
#define RS_IP_2__SEL_Q_MASK                                0x01c00000L

// RS_IP_3
#define RS_IP_3__TEX_PTR_MASK                              0x0000003fL
#define RS_IP_3__COL_PTR_MASK                              0x000001c0L
#define RS_IP_3__COL_FMT_MASK                              0x00001e00L
#define RS_IP_3__SEL_S_MASK                                0x0000e000L
#define RS_IP_3__SEL_T_MASK                                0x00070000L
#define RS_IP_3__SEL_R_MASK                                0x00380000L
#define RS_IP_3__SEL_Q_MASK                                0x01c00000L

// RS_IP_4
#define RS_IP_4__TEX_PTR_MASK                              0x0000003fL
#define RS_IP_4__COL_PTR_MASK                              0x000001c0L
#define RS_IP_4__COL_FMT_MASK                              0x00001e00L
#define RS_IP_4__SEL_S_MASK                                0x0000e000L
#define RS_IP_4__SEL_T_MASK                                0x00070000L
#define RS_IP_4__SEL_R_MASK                                0x00380000L
#define RS_IP_4__SEL_Q_MASK                                0x01c00000L

// RS_IP_5
#define RS_IP_5__TEX_PTR_MASK                              0x0000003fL
#define RS_IP_5__COL_PTR_MASK                              0x000001c0L
#define RS_IP_5__COL_FMT_MASK                              0x00001e00L
#define RS_IP_5__SEL_S_MASK                                0x0000e000L
#define RS_IP_5__SEL_T_MASK                                0x00070000L
#define RS_IP_5__SEL_R_MASK                                0x00380000L
#define RS_IP_5__SEL_Q_MASK                                0x01c00000L

// RS_IP_6
#define RS_IP_6__TEX_PTR_MASK                              0x0000003fL
#define RS_IP_6__COL_PTR_MASK                              0x000001c0L
#define RS_IP_6__COL_FMT_MASK                              0x00001e00L
#define RS_IP_6__SEL_S_MASK                                0x0000e000L
#define RS_IP_6__SEL_T_MASK                                0x00070000L
#define RS_IP_6__SEL_R_MASK                                0x00380000L
#define RS_IP_6__SEL_Q_MASK                                0x01c00000L

// RS_IP_7
#define RS_IP_7__TEX_PTR_MASK                              0x0000003fL
#define RS_IP_7__COL_PTR_MASK                              0x000001c0L
#define RS_IP_7__COL_FMT_MASK                              0x00001e00L
#define RS_IP_7__SEL_S_MASK                                0x0000e000L
#define RS_IP_7__SEL_T_MASK                                0x00070000L
#define RS_IP_7__SEL_R_MASK                                0x00380000L
#define RS_IP_7__SEL_Q_MASK                                0x01c00000L

// RS_INST_COUNT
#define RS_INST_COUNT__INST_COUNT_MASK                     0x0000000fL
#define RS_INST_COUNT__W_EN_MASK                           0x00000010L
#define RS_INST_COUNT__W_EN                                0x00000010L
#define RS_INST_COUNT__TX_OFFSET_MASK                      0x000000e0L

// RS_PERF
#define RS_PERF__PERF0_MASK                                0x0000000fL
#define RS_PERF__PERF1_MASK                                0x000000f0L
#define RS_PERF__PERF2_MASK                                0x00000f00L
#define RS_PERF__PERF3_MASK                                0x0000f000L
#define RS_PERF__RS_US_BREAK_MASK                          0x00030000L

// RS_INST_0
#define RS_INST_0__TEX_ID_MASK                             0x00000007L
#define RS_INST_0__TEX_CN_MASK                             0x00000038L
#define RS_INST_0__TEX_ADDR_MASK                           0x000007c0L
#define RS_INST_0__COL_ID_MASK                             0x00003800L
#define RS_INST_0__COL_CN_MASK                             0x0001c000L
#define RS_INST_0__COL_ADDR_MASK                           0x003e0000L
#define RS_INST_0__TEX_ADJ_MASK                            0x00400000L
#define RS_INST_0__TEX_ADJ                                 0x00400000L
#define RS_INST_0__COL_BIAS_MASK                           0x01800000L

// RS_INST_1
#define RS_INST_1__TEX_ID_MASK                             0x00000007L
#define RS_INST_1__TEX_CN_MASK                             0x00000038L
#define RS_INST_1__TEX_ADDR_MASK                           0x000007c0L
#define RS_INST_1__COL_ID_MASK                             0x00003800L
#define RS_INST_1__COL_CN_MASK                             0x0001c000L
#define RS_INST_1__COL_ADDR_MASK                           0x003e0000L
#define RS_INST_1__TEX_ADJ_MASK                            0x00400000L
#define RS_INST_1__TEX_ADJ                                 0x00400000L
#define RS_INST_1__COL_BIAS_MASK                           0x01800000L

// RS_INST_2
#define RS_INST_2__TEX_ID_MASK                             0x00000007L
#define RS_INST_2__TEX_CN_MASK                             0x00000038L
#define RS_INST_2__TEX_ADDR_MASK                           0x000007c0L
#define RS_INST_2__COL_ID_MASK                             0x00003800L
#define RS_INST_2__COL_CN_MASK                             0x0001c000L
#define RS_INST_2__COL_ADDR_MASK                           0x003e0000L
#define RS_INST_2__TEX_ADJ_MASK                            0x00400000L
#define RS_INST_2__TEX_ADJ                                 0x00400000L
#define RS_INST_2__COL_BIAS_MASK                           0x01800000L

// RS_INST_3
#define RS_INST_3__TEX_ID_MASK                             0x00000007L
#define RS_INST_3__TEX_CN_MASK                             0x00000038L
#define RS_INST_3__TEX_ADDR_MASK                           0x000007c0L
#define RS_INST_3__COL_ID_MASK                             0x00003800L
#define RS_INST_3__COL_CN_MASK                             0x0001c000L
#define RS_INST_3__COL_ADDR_MASK                           0x003e0000L
#define RS_INST_3__TEX_ADJ_MASK                            0x00400000L
#define RS_INST_3__TEX_ADJ                                 0x00400000L
#define RS_INST_3__COL_BIAS_MASK                           0x01800000L

// RS_INST_4
#define RS_INST_4__TEX_ID_MASK                             0x00000007L
#define RS_INST_4__TEX_CN_MASK                             0x00000038L
#define RS_INST_4__TEX_ADDR_MASK                           0x000007c0L
#define RS_INST_4__COL_ID_MASK                             0x00003800L
#define RS_INST_4__COL_CN_MASK                             0x0001c000L
#define RS_INST_4__COL_ADDR_MASK                           0x003e0000L
#define RS_INST_4__TEX_ADJ_MASK                            0x00400000L
#define RS_INST_4__TEX_ADJ                                 0x00400000L
#define RS_INST_4__COL_BIAS_MASK                           0x01800000L

// RS_INST_5
#define RS_INST_5__TEX_ID_MASK                             0x00000007L
#define RS_INST_5__TEX_CN_MASK                             0x00000038L
#define RS_INST_5__TEX_ADDR_MASK                           0x000007c0L
#define RS_INST_5__COL_ID_MASK                             0x00003800L
#define RS_INST_5__COL_CN_MASK                             0x0001c000L
#define RS_INST_5__COL_ADDR_MASK                           0x003e0000L
#define RS_INST_5__TEX_ADJ_MASK                            0x00400000L
#define RS_INST_5__TEX_ADJ                                 0x00400000L
#define RS_INST_5__COL_BIAS_MASK                           0x01800000L

// RS_INST_6
#define RS_INST_6__TEX_ID_MASK                             0x00000007L
#define RS_INST_6__TEX_CN_MASK                             0x00000038L
#define RS_INST_6__TEX_ADDR_MASK                           0x000007c0L
#define RS_INST_6__COL_ID_MASK                             0x00003800L
#define RS_INST_6__COL_CN_MASK                             0x0001c000L
#define RS_INST_6__COL_ADDR_MASK                           0x003e0000L
#define RS_INST_6__TEX_ADJ_MASK                            0x00400000L
#define RS_INST_6__TEX_ADJ                                 0x00400000L
#define RS_INST_6__COL_BIAS_MASK                           0x01800000L

// RS_INST_7
#define RS_INST_7__TEX_ID_MASK                             0x00000007L
#define RS_INST_7__TEX_CN_MASK                             0x00000038L
#define RS_INST_7__TEX_ADDR_MASK                           0x000007c0L
#define RS_INST_7__COL_ID_MASK                             0x00003800L
#define RS_INST_7__COL_CN_MASK                             0x0001c000L
#define RS_INST_7__COL_ADDR_MASK                           0x003e0000L
#define RS_INST_7__TEX_ADJ_MASK                            0x00400000L
#define RS_INST_7__TEX_ADJ                                 0x00400000L
#define RS_INST_7__COL_BIAS_MASK                           0x01800000L

// RS_INST_8
#define RS_INST_8__TEX_ID_MASK                             0x00000007L
#define RS_INST_8__TEX_CN_MASK                             0x00000038L
#define RS_INST_8__TEX_ADDR_MASK                           0x000007c0L
#define RS_INST_8__COL_ID_MASK                             0x00003800L
#define RS_INST_8__COL_CN_MASK                             0x0001c000L
#define RS_INST_8__COL_ADDR_MASK                           0x003e0000L
#define RS_INST_8__TEX_ADJ_MASK                            0x00400000L
#define RS_INST_8__TEX_ADJ                                 0x00400000L
#define RS_INST_8__COL_BIAS_MASK                           0x01800000L

// RS_INST_9
#define RS_INST_9__TEX_ID_MASK                             0x00000007L
#define RS_INST_9__TEX_CN_MASK                             0x00000038L
#define RS_INST_9__TEX_ADDR_MASK                           0x000007c0L
#define RS_INST_9__COL_ID_MASK                             0x00003800L
#define RS_INST_9__COL_CN_MASK                             0x0001c000L
#define RS_INST_9__COL_ADDR_MASK                           0x003e0000L
#define RS_INST_9__TEX_ADJ_MASK                            0x00400000L
#define RS_INST_9__TEX_ADJ                                 0x00400000L
#define RS_INST_9__COL_BIAS_MASK                           0x01800000L

// RS_INST_10
#define RS_INST_10__TEX_ID_MASK                            0x00000007L
#define RS_INST_10__TEX_CN_MASK                            0x00000038L
#define RS_INST_10__TEX_ADDR_MASK                          0x000007c0L
#define RS_INST_10__COL_ID_MASK                            0x00003800L
#define RS_INST_10__COL_CN_MASK                            0x0001c000L
#define RS_INST_10__COL_ADDR_MASK                          0x003e0000L
#define RS_INST_10__TEX_ADJ_MASK                           0x00400000L
#define RS_INST_10__TEX_ADJ                                0x00400000L
#define RS_INST_10__COL_BIAS_MASK                          0x01800000L

// RS_INST_11
#define RS_INST_11__TEX_ID_MASK                            0x00000007L
#define RS_INST_11__TEX_CN_MASK                            0x00000038L
#define RS_INST_11__TEX_ADDR_MASK                          0x000007c0L
#define RS_INST_11__COL_ID_MASK                            0x00003800L
#define RS_INST_11__COL_CN_MASK                            0x0001c000L
#define RS_INST_11__COL_ADDR_MASK                          0x003e0000L
#define RS_INST_11__TEX_ADJ_MASK                           0x00400000L
#define RS_INST_11__TEX_ADJ                                0x00400000L
#define RS_INST_11__COL_BIAS_MASK                          0x01800000L

// RS_INST_12
#define RS_INST_12__TEX_ID_MASK                            0x00000007L
#define RS_INST_12__TEX_CN_MASK                            0x00000038L
#define RS_INST_12__TEX_ADDR_MASK                          0x000007c0L
#define RS_INST_12__COL_ID_MASK                            0x00003800L
#define RS_INST_12__COL_CN_MASK                            0x0001c000L
#define RS_INST_12__COL_ADDR_MASK                          0x003e0000L
#define RS_INST_12__TEX_ADJ_MASK                           0x00400000L
#define RS_INST_12__TEX_ADJ                                0x00400000L
#define RS_INST_12__COL_BIAS_MASK                          0x01800000L

// RS_INST_13
#define RS_INST_13__TEX_ID_MASK                            0x00000007L
#define RS_INST_13__TEX_CN_MASK                            0x00000038L
#define RS_INST_13__TEX_ADDR_MASK                          0x000007c0L
#define RS_INST_13__COL_ID_MASK                            0x00003800L
#define RS_INST_13__COL_CN_MASK                            0x0001c000L
#define RS_INST_13__COL_ADDR_MASK                          0x003e0000L
#define RS_INST_13__TEX_ADJ_MASK                           0x00400000L
#define RS_INST_13__TEX_ADJ                                0x00400000L
#define RS_INST_13__COL_BIAS_MASK                          0x01800000L

// RS_INST_14
#define RS_INST_14__TEX_ID_MASK                            0x00000007L
#define RS_INST_14__TEX_CN_MASK                            0x00000038L
#define RS_INST_14__TEX_ADDR_MASK                          0x000007c0L
#define RS_INST_14__COL_ID_MASK                            0x00003800L
#define RS_INST_14__COL_CN_MASK                            0x0001c000L
#define RS_INST_14__COL_ADDR_MASK                          0x003e0000L
#define RS_INST_14__TEX_ADJ_MASK                           0x00400000L
#define RS_INST_14__TEX_ADJ                                0x00400000L
#define RS_INST_14__COL_BIAS_MASK                          0x01800000L

// RS_INST_15
#define RS_INST_15__TEX_ID_MASK                            0x00000007L
#define RS_INST_15__TEX_CN_MASK                            0x00000038L
#define RS_INST_15__TEX_ADDR_MASK                          0x000007c0L
#define RS_INST_15__COL_ID_MASK                            0x00003800L
#define RS_INST_15__COL_CN_MASK                            0x0001c000L
#define RS_INST_15__COL_ADDR_MASK                          0x003e0000L
#define RS_INST_15__TEX_ADJ_MASK                           0x00400000L
#define RS_INST_15__TEX_ADJ                                0x00400000L
#define RS_INST_15__COL_BIAS_MASK                          0x01800000L

// SC_HYPERZ_EN
#define SC_HYPERZ_EN__HZ_EN_MASK                           0x00000001L
#define SC_HYPERZ_EN__HZ_EN                                0x00000001L
#define SC_HYPERZ_EN__HZ_MAX_MASK                          0x00000002L
#define SC_HYPERZ_EN__HZ_MAX                               0x00000002L
#define SC_HYPERZ_EN__HZ_ADJ_MASK                          0x0000001cL
#define SC_HYPERZ_EN__HZ_Z0MIN_MASK                        0x00000020L
#define SC_HYPERZ_EN__HZ_Z0MIN                             0x00000020L
#define SC_HYPERZ_EN__HZ_Z0MAX_MASK                        0x00000040L
#define SC_HYPERZ_EN__HZ_Z0MAX                             0x00000040L

// SC_EDGERULE
#define SC_EDGERULE__ER_TRI_MASK                           0x0000001fL
#define SC_EDGERULE__ER_POINT_MASK                         0x000003e0L
#define SC_EDGERULE__ER_LINE_LR_MASK                       0x00007c00L
#define SC_EDGERULE__ER_LINE_RL_MASK                       0x000f8000L
#define SC_EDGERULE__ER_LINE_TB_MASK                       0x01f00000L
#define SC_EDGERULE__ER_LINE_BT_MASK                       0x3e000000L

// SC_PERF
#define SC_PERF__MOD0_MASK                                 0x00000003L
#define SC_PERF__MOD1_MASK                                 0x0000000cL
#define SC_PERF__MOD2_MASK                                 0x00000030L
#define SC_PERF__MOD3_MASK                                 0x000000c0L
#define SC_PERF__PERF0_MASK                                0x00003f00L
#define SC_PERF__PERF1_MASK                                0x000fc000L
#define SC_PERF__PERF2_MASK                                0x03f00000L
#define SC_PERF__PERF3_MASK                                0xfc000000L

// SC_CLIP_0_A
#define SC_CLIP_0_A__XS0_MASK                              0x00001fffL
#define SC_CLIP_0_A__YS0_MASK                              0x03ffe000L

// SC_CLIP_1_A
#define SC_CLIP_1_A__XS0_MASK                              0x00001fffL
#define SC_CLIP_1_A__YS0_MASK                              0x03ffe000L

// SC_CLIP_2_A
#define SC_CLIP_2_A__XS0_MASK                              0x00001fffL
#define SC_CLIP_2_A__YS0_MASK                              0x03ffe000L

// SC_CLIP_3_A
#define SC_CLIP_3_A__XS0_MASK                              0x00001fffL
#define SC_CLIP_3_A__YS0_MASK                              0x03ffe000L

// SC_CLIP_0_B
#define SC_CLIP_0_B__XS1_MASK                              0x00001fffL
#define SC_CLIP_0_B__YS1_MASK                              0x03ffe000L

// SC_CLIP_1_B
#define SC_CLIP_1_B__XS1_MASK                              0x00001fffL
#define SC_CLIP_1_B__YS1_MASK                              0x03ffe000L

// SC_CLIP_2_B
#define SC_CLIP_2_B__XS1_MASK                              0x00001fffL
#define SC_CLIP_2_B__YS1_MASK                              0x03ffe000L

// SC_CLIP_3_B
#define SC_CLIP_3_B__XS1_MASK                              0x00001fffL
#define SC_CLIP_3_B__YS1_MASK                              0x03ffe000L

// SC_CLIP_RULE
#define SC_CLIP_RULE__CLIP_RULE_MASK                       0x0000ffffL

// SC_SCISSOR0
#define SC_SCISSOR0__XS0_MASK                              0x00001fffL
#define SC_SCISSOR0__YS0_MASK                              0x03ffe000L

// SC_SCISSOR1
#define SC_SCISSOR1__XS1_MASK                              0x00001fffL
#define SC_SCISSOR1__YS1_MASK                              0x03ffe000L

// SC_SCREENDOOR
#define SC_SCREENDOOR__SCREENDOOR_MASK                     0x00ffffffL

// TX_FILTER0_0
#define TX_FILTER0_0__CLAMP_S_MASK                         0x00000007L
#define TX_FILTER0_0__CLAMP_T_MASK                         0x00000038L
#define TX_FILTER0_0__CLAMP_R_MASK                         0x000001c0L
#define TX_FILTER0_0__MAG_FILTER_MASK                      0x00000600L
#define TX_FILTER0_0__MIN_FILTER_MASK                      0x00001800L
#define TX_FILTER0_0__MIP_FILTER_MASK                      0x00006000L
#define TX_FILTER0_0__VOL_FILTER_MASK                      0x00018000L
#define TX_FILTER0_0__MAX_MIP_LEVEL_MASK                   0x001e0000L
#define TX_FILTER0_0__MAX_ANIS_MASK                        0x00e00000L
#define TX_FILTER0_0__ID_MASK                              0xf0000000L

// TX_FILTER0_1
#define TX_FILTER0_1__CLAMP_S_MASK                         0x00000007L
#define TX_FILTER0_1__CLAMP_T_MASK                         0x00000038L
#define TX_FILTER0_1__CLAMP_R_MASK                         0x000001c0L
#define TX_FILTER0_1__MAG_FILTER_MASK                      0x00000600L
#define TX_FILTER0_1__MIN_FILTER_MASK                      0x00001800L
#define TX_FILTER0_1__MIP_FILTER_MASK                      0x00006000L
#define TX_FILTER0_1__VOL_FILTER_MASK                      0x00018000L
#define TX_FILTER0_1__MAX_MIP_LEVEL_MASK                   0x001e0000L
#define TX_FILTER0_1__MAX_ANIS_MASK                        0x00e00000L
#define TX_FILTER0_1__ID_MASK                              0xf0000000L

// TX_FILTER0_2
#define TX_FILTER0_2__CLAMP_S_MASK                         0x00000007L
#define TX_FILTER0_2__CLAMP_T_MASK                         0x00000038L
#define TX_FILTER0_2__CLAMP_R_MASK                         0x000001c0L
#define TX_FILTER0_2__MAG_FILTER_MASK                      0x00000600L
#define TX_FILTER0_2__MIN_FILTER_MASK                      0x00001800L
#define TX_FILTER0_2__MIP_FILTER_MASK                      0x00006000L
#define TX_FILTER0_2__VOL_FILTER_MASK                      0x00018000L
#define TX_FILTER0_2__MAX_MIP_LEVEL_MASK                   0x001e0000L
#define TX_FILTER0_2__MAX_ANIS_MASK                        0x00e00000L
#define TX_FILTER0_2__ID_MASK                              0xf0000000L

// TX_FILTER0_3
#define TX_FILTER0_3__CLAMP_S_MASK                         0x00000007L
#define TX_FILTER0_3__CLAMP_T_MASK                         0x00000038L
#define TX_FILTER0_3__CLAMP_R_MASK                         0x000001c0L
#define TX_FILTER0_3__MAG_FILTER_MASK                      0x00000600L
#define TX_FILTER0_3__MIN_FILTER_MASK                      0x00001800L
#define TX_FILTER0_3__MIP_FILTER_MASK                      0x00006000L
#define TX_FILTER0_3__VOL_FILTER_MASK                      0x00018000L
#define TX_FILTER0_3__MAX_MIP_LEVEL_MASK                   0x001e0000L
#define TX_FILTER0_3__MAX_ANIS_MASK                        0x00e00000L
#define TX_FILTER0_3__ID_MASK                              0xf0000000L

// TX_FILTER0_4
#define TX_FILTER0_4__CLAMP_S_MASK                         0x00000007L
#define TX_FILTER0_4__CLAMP_T_MASK                         0x00000038L
#define TX_FILTER0_4__CLAMP_R_MASK                         0x000001c0L
#define TX_FILTER0_4__MAG_FILTER_MASK                      0x00000600L
#define TX_FILTER0_4__MIN_FILTER_MASK                      0x00001800L
#define TX_FILTER0_4__MIP_FILTER_MASK                      0x00006000L
#define TX_FILTER0_4__VOL_FILTER_MASK                      0x00018000L
#define TX_FILTER0_4__MAX_MIP_LEVEL_MASK                   0x001e0000L
#define TX_FILTER0_4__MAX_ANIS_MASK                        0x00e00000L
#define TX_FILTER0_4__ID_MASK                              0xf0000000L

// TX_FILTER0_5
#define TX_FILTER0_5__CLAMP_S_MASK                         0x00000007L
#define TX_FILTER0_5__CLAMP_T_MASK                         0x00000038L
#define TX_FILTER0_5__CLAMP_R_MASK                         0x000001c0L
#define TX_FILTER0_5__MAG_FILTER_MASK                      0x00000600L
#define TX_FILTER0_5__MIN_FILTER_MASK                      0x00001800L
#define TX_FILTER0_5__MIP_FILTER_MASK                      0x00006000L
#define TX_FILTER0_5__VOL_FILTER_MASK                      0x00018000L
#define TX_FILTER0_5__MAX_MIP_LEVEL_MASK                   0x001e0000L
#define TX_FILTER0_5__MAX_ANIS_MASK                        0x00e00000L
#define TX_FILTER0_5__ID_MASK                              0xf0000000L

// TX_FILTER0_6
#define TX_FILTER0_6__CLAMP_S_MASK                         0x00000007L
#define TX_FILTER0_6__CLAMP_T_MASK                         0x00000038L
#define TX_FILTER0_6__CLAMP_R_MASK                         0x000001c0L
#define TX_FILTER0_6__MAG_FILTER_MASK                      0x00000600L
#define TX_FILTER0_6__MIN_FILTER_MASK                      0x00001800L
#define TX_FILTER0_6__MIP_FILTER_MASK                      0x00006000L
#define TX_FILTER0_6__VOL_FILTER_MASK                      0x00018000L
#define TX_FILTER0_6__MAX_MIP_LEVEL_MASK                   0x001e0000L
#define TX_FILTER0_6__MAX_ANIS_MASK                        0x00e00000L
#define TX_FILTER0_6__ID_MASK                              0xf0000000L

// TX_FILTER0_7
#define TX_FILTER0_7__CLAMP_S_MASK                         0x00000007L
#define TX_FILTER0_7__CLAMP_T_MASK                         0x00000038L
#define TX_FILTER0_7__CLAMP_R_MASK                         0x000001c0L
#define TX_FILTER0_7__MAG_FILTER_MASK                      0x00000600L
#define TX_FILTER0_7__MIN_FILTER_MASK                      0x00001800L
#define TX_FILTER0_7__MIP_FILTER_MASK                      0x00006000L
#define TX_FILTER0_7__VOL_FILTER_MASK                      0x00018000L
#define TX_FILTER0_7__MAX_MIP_LEVEL_MASK                   0x001e0000L
#define TX_FILTER0_7__MAX_ANIS_MASK                        0x00e00000L
#define TX_FILTER0_7__ID_MASK                              0xf0000000L

// TX_FILTER0_8
#define TX_FILTER0_8__CLAMP_S_MASK                         0x00000007L
#define TX_FILTER0_8__CLAMP_T_MASK                         0x00000038L
#define TX_FILTER0_8__CLAMP_R_MASK                         0x000001c0L
#define TX_FILTER0_8__MAG_FILTER_MASK                      0x00000600L
#define TX_FILTER0_8__MIN_FILTER_MASK                      0x00001800L
#define TX_FILTER0_8__MIP_FILTER_MASK                      0x00006000L
#define TX_FILTER0_8__VOL_FILTER_MASK                      0x00018000L
#define TX_FILTER0_8__MAX_MIP_LEVEL_MASK                   0x001e0000L
#define TX_FILTER0_8__MAX_ANIS_MASK                        0x00e00000L
#define TX_FILTER0_8__ID_MASK                              0xf0000000L

// TX_FILTER0_9
#define TX_FILTER0_9__CLAMP_S_MASK                         0x00000007L
#define TX_FILTER0_9__CLAMP_T_MASK                         0x00000038L
#define TX_FILTER0_9__CLAMP_R_MASK                         0x000001c0L
#define TX_FILTER0_9__MAG_FILTER_MASK                      0x00000600L
#define TX_FILTER0_9__MIN_FILTER_MASK                      0x00001800L
#define TX_FILTER0_9__MIP_FILTER_MASK                      0x00006000L
#define TX_FILTER0_9__VOL_FILTER_MASK                      0x00018000L
#define TX_FILTER0_9__MAX_MIP_LEVEL_MASK                   0x001e0000L
#define TX_FILTER0_9__MAX_ANIS_MASK                        0x00e00000L
#define TX_FILTER0_9__ID_MASK                              0xf0000000L

// TX_FILTER0_10
#define TX_FILTER0_10__CLAMP_S_MASK                        0x00000007L
#define TX_FILTER0_10__CLAMP_T_MASK                        0x00000038L
#define TX_FILTER0_10__CLAMP_R_MASK                        0x000001c0L
#define TX_FILTER0_10__MAG_FILTER_MASK                     0x00000600L
#define TX_FILTER0_10__MIN_FILTER_MASK                     0x00001800L
#define TX_FILTER0_10__MIP_FILTER_MASK                     0x00006000L
#define TX_FILTER0_10__VOL_FILTER_MASK                     0x00018000L
#define TX_FILTER0_10__MAX_MIP_LEVEL_MASK                  0x001e0000L
#define TX_FILTER0_10__MAX_ANIS_MASK                       0x00e00000L
#define TX_FILTER0_10__ID_MASK                             0xf0000000L

// TX_FILTER0_11
#define TX_FILTER0_11__CLAMP_S_MASK                        0x00000007L
#define TX_FILTER0_11__CLAMP_T_MASK                        0x00000038L
#define TX_FILTER0_11__CLAMP_R_MASK                        0x000001c0L
#define TX_FILTER0_11__MAG_FILTER_MASK                     0x00000600L
#define TX_FILTER0_11__MIN_FILTER_MASK                     0x00001800L
#define TX_FILTER0_11__MIP_FILTER_MASK                     0x00006000L
#define TX_FILTER0_11__VOL_FILTER_MASK                     0x00018000L
#define TX_FILTER0_11__MAX_MIP_LEVEL_MASK                  0x001e0000L
#define TX_FILTER0_11__MAX_ANIS_MASK                       0x00e00000L
#define TX_FILTER0_11__ID_MASK                             0xf0000000L

// TX_FILTER0_12
#define TX_FILTER0_12__CLAMP_S_MASK                        0x00000007L
#define TX_FILTER0_12__CLAMP_T_MASK                        0x00000038L
#define TX_FILTER0_12__CLAMP_R_MASK                        0x000001c0L
#define TX_FILTER0_12__MAG_FILTER_MASK                     0x00000600L
#define TX_FILTER0_12__MIN_FILTER_MASK                     0x00001800L
#define TX_FILTER0_12__MIP_FILTER_MASK                     0x00006000L
#define TX_FILTER0_12__VOL_FILTER_MASK                     0x00018000L
#define TX_FILTER0_12__MAX_MIP_LEVEL_MASK                  0x001e0000L
#define TX_FILTER0_12__MAX_ANIS_MASK                       0x00e00000L
#define TX_FILTER0_12__ID_MASK                             0xf0000000L

// TX_FILTER0_13
#define TX_FILTER0_13__CLAMP_S_MASK                        0x00000007L
#define TX_FILTER0_13__CLAMP_T_MASK                        0x00000038L
#define TX_FILTER0_13__CLAMP_R_MASK                        0x000001c0L
#define TX_FILTER0_13__MAG_FILTER_MASK                     0x00000600L
#define TX_FILTER0_13__MIN_FILTER_MASK                     0x00001800L
#define TX_FILTER0_13__MIP_FILTER_MASK                     0x00006000L
#define TX_FILTER0_13__VOL_FILTER_MASK                     0x00018000L
#define TX_FILTER0_13__MAX_MIP_LEVEL_MASK                  0x001e0000L
#define TX_FILTER0_13__MAX_ANIS_MASK                       0x00e00000L
#define TX_FILTER0_13__ID_MASK                             0xf0000000L

// TX_FILTER0_14
#define TX_FILTER0_14__CLAMP_S_MASK                        0x00000007L
#define TX_FILTER0_14__CLAMP_T_MASK                        0x00000038L
#define TX_FILTER0_14__CLAMP_R_MASK                        0x000001c0L
#define TX_FILTER0_14__MAG_FILTER_MASK                     0x00000600L
#define TX_FILTER0_14__MIN_FILTER_MASK                     0x00001800L
#define TX_FILTER0_14__MIP_FILTER_MASK                     0x00006000L
#define TX_FILTER0_14__VOL_FILTER_MASK                     0x00018000L
#define TX_FILTER0_14__MAX_MIP_LEVEL_MASK                  0x001e0000L
#define TX_FILTER0_14__MAX_ANIS_MASK                       0x00e00000L
#define TX_FILTER0_14__ID_MASK                             0xf0000000L

// TX_FILTER0_15
#define TX_FILTER0_15__CLAMP_S_MASK                        0x00000007L
#define TX_FILTER0_15__CLAMP_T_MASK                        0x00000038L
#define TX_FILTER0_15__CLAMP_R_MASK                        0x000001c0L
#define TX_FILTER0_15__MAG_FILTER_MASK                     0x00000600L
#define TX_FILTER0_15__MIN_FILTER_MASK                     0x00001800L
#define TX_FILTER0_15__MIP_FILTER_MASK                     0x00006000L
#define TX_FILTER0_15__VOL_FILTER_MASK                     0x00018000L
#define TX_FILTER0_15__MAX_MIP_LEVEL_MASK                  0x001e0000L
#define TX_FILTER0_15__MAX_ANIS_MASK                       0x00e00000L
#define TX_FILTER0_15__ID_MASK                             0xf0000000L

// TX_FILTER1_0
#define TX_FILTER1_0__CHROMA_KEY_MODE_MASK                 0x00000003L
#define TX_FILTER1_0__MC_ROUND_MASK                        0x00000004L
#define TX_FILTER1_0__MC_ROUND                             0x00000004L
#define TX_FILTER1_0__LOD_BIAS_MASK                        0x00001ff8L
#define TX_FILTER1_0__EDGE_ANIS_MASK                       0x00002000L
#define TX_FILTER1_0__EDGE_ANIS                            0x00002000L
#define TX_FILTER1_0__MC_COORD_TRUNCATE_MASK               0x00004000L
#define TX_FILTER1_0__MC_COORD_TRUNCATE                    0x00004000L

// TX_FILTER1_1
#define TX_FILTER1_1__CHROMA_KEY_MODE_MASK                 0x00000003L
#define TX_FILTER1_1__MC_ROUND_MASK                        0x00000004L
#define TX_FILTER1_1__MC_ROUND                             0x00000004L
#define TX_FILTER1_1__LOD_BIAS_MASK                        0x00001ff8L
#define TX_FILTER1_1__EDGE_ANIS_MASK                       0x00002000L
#define TX_FILTER1_1__EDGE_ANIS                            0x00002000L
#define TX_FILTER1_1__MC_COORD_TRUNCATE_MASK               0x00004000L
#define TX_FILTER1_1__MC_COORD_TRUNCATE                    0x00004000L

// TX_FILTER1_2
#define TX_FILTER1_2__CHROMA_KEY_MODE_MASK                 0x00000003L
#define TX_FILTER1_2__MC_ROUND_MASK                        0x00000004L
#define TX_FILTER1_2__MC_ROUND                             0x00000004L
#define TX_FILTER1_2__LOD_BIAS_MASK                        0x00001ff8L
#define TX_FILTER1_2__EDGE_ANIS_MASK                       0x00002000L
#define TX_FILTER1_2__EDGE_ANIS                            0x00002000L
#define TX_FILTER1_2__MC_COORD_TRUNCATE_MASK               0x00004000L
#define TX_FILTER1_2__MC_COORD_TRUNCATE                    0x00004000L

// TX_FILTER1_3
#define TX_FILTER1_3__CHROMA_KEY_MODE_MASK                 0x00000003L
#define TX_FILTER1_3__MC_ROUND_MASK                        0x00000004L
#define TX_FILTER1_3__MC_ROUND                             0x00000004L
#define TX_FILTER1_3__LOD_BIAS_MASK                        0x00001ff8L
#define TX_FILTER1_3__EDGE_ANIS_MASK                       0x00002000L
#define TX_FILTER1_3__EDGE_ANIS                            0x00002000L
#define TX_FILTER1_3__MC_COORD_TRUNCATE_MASK               0x00004000L
#define TX_FILTER1_3__MC_COORD_TRUNCATE                    0x00004000L

// TX_FILTER1_4
#define TX_FILTER1_4__CHROMA_KEY_MODE_MASK                 0x00000003L
#define TX_FILTER1_4__MC_ROUND_MASK                        0x00000004L
#define TX_FILTER1_4__MC_ROUND                             0x00000004L
#define TX_FILTER1_4__LOD_BIAS_MASK                        0x00001ff8L
#define TX_FILTER1_4__EDGE_ANIS_MASK                       0x00002000L
#define TX_FILTER1_4__EDGE_ANIS                            0x00002000L
#define TX_FILTER1_4__MC_COORD_TRUNCATE_MASK               0x00004000L
#define TX_FILTER1_4__MC_COORD_TRUNCATE                    0x00004000L

// TX_FILTER1_5
#define TX_FILTER1_5__CHROMA_KEY_MODE_MASK                 0x00000003L
#define TX_FILTER1_5__MC_ROUND_MASK                        0x00000004L
#define TX_FILTER1_5__MC_ROUND                             0x00000004L
#define TX_FILTER1_5__LOD_BIAS_MASK                        0x00001ff8L
#define TX_FILTER1_5__EDGE_ANIS_MASK                       0x00002000L
#define TX_FILTER1_5__EDGE_ANIS                            0x00002000L
#define TX_FILTER1_5__MC_COORD_TRUNCATE_MASK               0x00004000L
#define TX_FILTER1_5__MC_COORD_TRUNCATE                    0x00004000L

// TX_FILTER1_6
#define TX_FILTER1_6__CHROMA_KEY_MODE_MASK                 0x00000003L
#define TX_FILTER1_6__MC_ROUND_MASK                        0x00000004L
#define TX_FILTER1_6__MC_ROUND                             0x00000004L
#define TX_FILTER1_6__LOD_BIAS_MASK                        0x00001ff8L
#define TX_FILTER1_6__EDGE_ANIS_MASK                       0x00002000L
#define TX_FILTER1_6__EDGE_ANIS                            0x00002000L
#define TX_FILTER1_6__MC_COORD_TRUNCATE_MASK               0x00004000L
#define TX_FILTER1_6__MC_COORD_TRUNCATE                    0x00004000L

// TX_FILTER1_7
#define TX_FILTER1_7__CHROMA_KEY_MODE_MASK                 0x00000003L
#define TX_FILTER1_7__MC_ROUND_MASK                        0x00000004L
#define TX_FILTER1_7__MC_ROUND                             0x00000004L
#define TX_FILTER1_7__LOD_BIAS_MASK                        0x00001ff8L
#define TX_FILTER1_7__EDGE_ANIS_MASK                       0x00002000L
#define TX_FILTER1_7__EDGE_ANIS                            0x00002000L
#define TX_FILTER1_7__MC_COORD_TRUNCATE_MASK               0x00004000L
#define TX_FILTER1_7__MC_COORD_TRUNCATE                    0x00004000L

// TX_FILTER1_8
#define TX_FILTER1_8__CHROMA_KEY_MODE_MASK                 0x00000003L
#define TX_FILTER1_8__MC_ROUND_MASK                        0x00000004L
#define TX_FILTER1_8__MC_ROUND                             0x00000004L
#define TX_FILTER1_8__LOD_BIAS_MASK                        0x00001ff8L
#define TX_FILTER1_8__EDGE_ANIS_MASK                       0x00002000L
#define TX_FILTER1_8__EDGE_ANIS                            0x00002000L
#define TX_FILTER1_8__MC_COORD_TRUNCATE_MASK               0x00004000L
#define TX_FILTER1_8__MC_COORD_TRUNCATE                    0x00004000L

// TX_FILTER1_9
#define TX_FILTER1_9__CHROMA_KEY_MODE_MASK                 0x00000003L
#define TX_FILTER1_9__MC_ROUND_MASK                        0x00000004L
#define TX_FILTER1_9__MC_ROUND                             0x00000004L
#define TX_FILTER1_9__LOD_BIAS_MASK                        0x00001ff8L
#define TX_FILTER1_9__EDGE_ANIS_MASK                       0x00002000L
#define TX_FILTER1_9__EDGE_ANIS                            0x00002000L
#define TX_FILTER1_9__MC_COORD_TRUNCATE_MASK               0x00004000L
#define TX_FILTER1_9__MC_COORD_TRUNCATE                    0x00004000L

// TX_FILTER1_10
#define TX_FILTER1_10__CHROMA_KEY_MODE_MASK                0x00000003L
#define TX_FILTER1_10__MC_ROUND_MASK                       0x00000004L
#define TX_FILTER1_10__MC_ROUND                            0x00000004L
#define TX_FILTER1_10__LOD_BIAS_MASK                       0x00001ff8L
#define TX_FILTER1_10__EDGE_ANIS_MASK                      0x00002000L
#define TX_FILTER1_10__EDGE_ANIS                           0x00002000L
#define TX_FILTER1_10__MC_COORD_TRUNCATE_MASK              0x00004000L
#define TX_FILTER1_10__MC_COORD_TRUNCATE                   0x00004000L

// TX_FILTER1_11
#define TX_FILTER1_11__CHROMA_KEY_MODE_MASK                0x00000003L
#define TX_FILTER1_11__MC_ROUND_MASK                       0x00000004L
#define TX_FILTER1_11__MC_ROUND                            0x00000004L
#define TX_FILTER1_11__LOD_BIAS_MASK                       0x00001ff8L
#define TX_FILTER1_11__EDGE_ANIS_MASK                      0x00002000L
#define TX_FILTER1_11__EDGE_ANIS                           0x00002000L
#define TX_FILTER1_11__MC_COORD_TRUNCATE_MASK              0x00004000L
#define TX_FILTER1_11__MC_COORD_TRUNCATE                   0x00004000L

// TX_FILTER1_12
#define TX_FILTER1_12__CHROMA_KEY_MODE_MASK                0x00000003L
#define TX_FILTER1_12__MC_ROUND_MASK                       0x00000004L
#define TX_FILTER1_12__MC_ROUND                            0x00000004L
#define TX_FILTER1_12__LOD_BIAS_MASK                       0x00001ff8L
#define TX_FILTER1_12__EDGE_ANIS_MASK                      0x00002000L
#define TX_FILTER1_12__EDGE_ANIS                           0x00002000L
#define TX_FILTER1_12__MC_COORD_TRUNCATE_MASK              0x00004000L
#define TX_FILTER1_12__MC_COORD_TRUNCATE                   0x00004000L

// TX_FILTER1_13
#define TX_FILTER1_13__CHROMA_KEY_MODE_MASK                0x00000003L
#define TX_FILTER1_13__MC_ROUND_MASK                       0x00000004L
#define TX_FILTER1_13__MC_ROUND                            0x00000004L
#define TX_FILTER1_13__LOD_BIAS_MASK                       0x00001ff8L
#define TX_FILTER1_13__EDGE_ANIS_MASK                      0x00002000L
#define TX_FILTER1_13__EDGE_ANIS                           0x00002000L
#define TX_FILTER1_13__MC_COORD_TRUNCATE_MASK              0x00004000L
#define TX_FILTER1_13__MC_COORD_TRUNCATE                   0x00004000L

// TX_FILTER1_14
#define TX_FILTER1_14__CHROMA_KEY_MODE_MASK                0x00000003L
#define TX_FILTER1_14__MC_ROUND_MASK                       0x00000004L
#define TX_FILTER1_14__MC_ROUND                            0x00000004L
#define TX_FILTER1_14__LOD_BIAS_MASK                       0x00001ff8L
#define TX_FILTER1_14__EDGE_ANIS_MASK                      0x00002000L
#define TX_FILTER1_14__EDGE_ANIS                           0x00002000L
#define TX_FILTER1_14__MC_COORD_TRUNCATE_MASK              0x00004000L
#define TX_FILTER1_14__MC_COORD_TRUNCATE                   0x00004000L

// TX_FILTER1_15
#define TX_FILTER1_15__CHROMA_KEY_MODE_MASK                0x00000003L
#define TX_FILTER1_15__MC_ROUND_MASK                       0x00000004L
#define TX_FILTER1_15__MC_ROUND                            0x00000004L
#define TX_FILTER1_15__LOD_BIAS_MASK                       0x00001ff8L
#define TX_FILTER1_15__EDGE_ANIS_MASK                      0x00002000L
#define TX_FILTER1_15__EDGE_ANIS                           0x00002000L
#define TX_FILTER1_15__MC_COORD_TRUNCATE_MASK              0x00004000L
#define TX_FILTER1_15__MC_COORD_TRUNCATE                   0x00004000L

// TX_FORMAT0_0
#define TX_FORMAT0_0__TXWIDTH_MASK                         0x000007ffL
#define TX_FORMAT0_0__TXHEIGHT_MASK                        0x003ff800L
#define TX_FORMAT0_0__TXDEPTH_MASK                         0x03c00000L
#define TX_FORMAT0_0__NUM_LEVELS_MASK                      0x3c000000L
#define TX_FORMAT0_0__PROJECTED_MASK                       0x40000000L
#define TX_FORMAT0_0__PROJECTED                            0x40000000L
#define TX_FORMAT0_0__TXPITCH_EN_MASK                      0x80000000L
#define TX_FORMAT0_0__TXPITCH_EN                           0x80000000L

// TX_FORMAT0_1
#define TX_FORMAT0_1__TXWIDTH_MASK                         0x000007ffL
#define TX_FORMAT0_1__TXHEIGHT_MASK                        0x003ff800L
#define TX_FORMAT0_1__TXDEPTH_MASK                         0x03c00000L
#define TX_FORMAT0_1__NUM_LEVELS_MASK                      0x3c000000L
#define TX_FORMAT0_1__PROJECTED_MASK                       0x40000000L
#define TX_FORMAT0_1__PROJECTED                            0x40000000L
#define TX_FORMAT0_1__TXPITCH_EN_MASK                      0x80000000L
#define TX_FORMAT0_1__TXPITCH_EN                           0x80000000L

// TX_FORMAT0_2
#define TX_FORMAT0_2__TXWIDTH_MASK                         0x000007ffL
#define TX_FORMAT0_2__TXHEIGHT_MASK                        0x003ff800L
#define TX_FORMAT0_2__TXDEPTH_MASK                         0x03c00000L
#define TX_FORMAT0_2__NUM_LEVELS_MASK                      0x3c000000L
#define TX_FORMAT0_2__PROJECTED_MASK                       0x40000000L
#define TX_FORMAT0_2__PROJECTED                            0x40000000L
#define TX_FORMAT0_2__TXPITCH_EN_MASK                      0x80000000L
#define TX_FORMAT0_2__TXPITCH_EN                           0x80000000L

// TX_FORMAT0_3
#define TX_FORMAT0_3__TXWIDTH_MASK                         0x000007ffL
#define TX_FORMAT0_3__TXHEIGHT_MASK                        0x003ff800L
#define TX_FORMAT0_3__TXDEPTH_MASK                         0x03c00000L
#define TX_FORMAT0_3__NUM_LEVELS_MASK                      0x3c000000L
#define TX_FORMAT0_3__PROJECTED_MASK                       0x40000000L
#define TX_FORMAT0_3__PROJECTED                            0x40000000L
#define TX_FORMAT0_3__TXPITCH_EN_MASK                      0x80000000L
#define TX_FORMAT0_3__TXPITCH_EN                           0x80000000L

// TX_FORMAT0_4
#define TX_FORMAT0_4__TXWIDTH_MASK                         0x000007ffL
#define TX_FORMAT0_4__TXHEIGHT_MASK                        0x003ff800L
#define TX_FORMAT0_4__TXDEPTH_MASK                         0x03c00000L
#define TX_FORMAT0_4__NUM_LEVELS_MASK                      0x3c000000L
#define TX_FORMAT0_4__PROJECTED_MASK                       0x40000000L
#define TX_FORMAT0_4__PROJECTED                            0x40000000L
#define TX_FORMAT0_4__TXPITCH_EN_MASK                      0x80000000L
#define TX_FORMAT0_4__TXPITCH_EN                           0x80000000L

// TX_FORMAT0_5
#define TX_FORMAT0_5__TXWIDTH_MASK                         0x000007ffL
#define TX_FORMAT0_5__TXHEIGHT_MASK                        0x003ff800L
#define TX_FORMAT0_5__TXDEPTH_MASK                         0x03c00000L
#define TX_FORMAT0_5__NUM_LEVELS_MASK                      0x3c000000L
#define TX_FORMAT0_5__PROJECTED_MASK                       0x40000000L
#define TX_FORMAT0_5__PROJECTED                            0x40000000L
#define TX_FORMAT0_5__TXPITCH_EN_MASK                      0x80000000L
#define TX_FORMAT0_5__TXPITCH_EN                           0x80000000L

// TX_FORMAT0_6
#define TX_FORMAT0_6__TXWIDTH_MASK                         0x000007ffL
#define TX_FORMAT0_6__TXHEIGHT_MASK                        0x003ff800L
#define TX_FORMAT0_6__TXDEPTH_MASK                         0x03c00000L
#define TX_FORMAT0_6__NUM_LEVELS_MASK                      0x3c000000L
#define TX_FORMAT0_6__PROJECTED_MASK                       0x40000000L
#define TX_FORMAT0_6__PROJECTED                            0x40000000L
#define TX_FORMAT0_6__TXPITCH_EN_MASK                      0x80000000L
#define TX_FORMAT0_6__TXPITCH_EN                           0x80000000L

// TX_FORMAT0_7
#define TX_FORMAT0_7__TXWIDTH_MASK                         0x000007ffL
#define TX_FORMAT0_7__TXHEIGHT_MASK                        0x003ff800L
#define TX_FORMAT0_7__TXDEPTH_MASK                         0x03c00000L
#define TX_FORMAT0_7__NUM_LEVELS_MASK                      0x3c000000L
#define TX_FORMAT0_7__PROJECTED_MASK                       0x40000000L
#define TX_FORMAT0_7__PROJECTED                            0x40000000L
#define TX_FORMAT0_7__TXPITCH_EN_MASK                      0x80000000L
#define TX_FORMAT0_7__TXPITCH_EN                           0x80000000L

// TX_FORMAT0_8
#define TX_FORMAT0_8__TXWIDTH_MASK                         0x000007ffL
#define TX_FORMAT0_8__TXHEIGHT_MASK                        0x003ff800L
#define TX_FORMAT0_8__TXDEPTH_MASK                         0x03c00000L
#define TX_FORMAT0_8__NUM_LEVELS_MASK                      0x3c000000L
#define TX_FORMAT0_8__PROJECTED_MASK                       0x40000000L
#define TX_FORMAT0_8__PROJECTED                            0x40000000L
#define TX_FORMAT0_8__TXPITCH_EN_MASK                      0x80000000L
#define TX_FORMAT0_8__TXPITCH_EN                           0x80000000L

// TX_FORMAT0_9
#define TX_FORMAT0_9__TXWIDTH_MASK                         0x000007ffL
#define TX_FORMAT0_9__TXHEIGHT_MASK                        0x003ff800L
#define TX_FORMAT0_9__TXDEPTH_MASK                         0x03c00000L
#define TX_FORMAT0_9__NUM_LEVELS_MASK                      0x3c000000L
#define TX_FORMAT0_9__PROJECTED_MASK                       0x40000000L
#define TX_FORMAT0_9__PROJECTED                            0x40000000L
#define TX_FORMAT0_9__TXPITCH_EN_MASK                      0x80000000L
#define TX_FORMAT0_9__TXPITCH_EN                           0x80000000L

// TX_FORMAT0_10
#define TX_FORMAT0_10__TXWIDTH_MASK                        0x000007ffL
#define TX_FORMAT0_10__TXHEIGHT_MASK                       0x003ff800L
#define TX_FORMAT0_10__TXDEPTH_MASK                        0x03c00000L
#define TX_FORMAT0_10__NUM_LEVELS_MASK                     0x3c000000L
#define TX_FORMAT0_10__PROJECTED_MASK                      0x40000000L
#define TX_FORMAT0_10__PROJECTED                           0x40000000L
#define TX_FORMAT0_10__TXPITCH_EN_MASK                     0x80000000L
#define TX_FORMAT0_10__TXPITCH_EN                          0x80000000L

// TX_FORMAT0_11
#define TX_FORMAT0_11__TXWIDTH_MASK                        0x000007ffL
#define TX_FORMAT0_11__TXHEIGHT_MASK                       0x003ff800L
#define TX_FORMAT0_11__TXDEPTH_MASK                        0x03c00000L
#define TX_FORMAT0_11__NUM_LEVELS_MASK                     0x3c000000L
#define TX_FORMAT0_11__PROJECTED_MASK                      0x40000000L
#define TX_FORMAT0_11__PROJECTED                           0x40000000L
#define TX_FORMAT0_11__TXPITCH_EN_MASK                     0x80000000L
#define TX_FORMAT0_11__TXPITCH_EN                          0x80000000L

// TX_FORMAT0_12
#define TX_FORMAT0_12__TXWIDTH_MASK                        0x000007ffL
#define TX_FORMAT0_12__TXHEIGHT_MASK                       0x003ff800L
#define TX_FORMAT0_12__TXDEPTH_MASK                        0x03c00000L
#define TX_FORMAT0_12__NUM_LEVELS_MASK                     0x3c000000L
#define TX_FORMAT0_12__PROJECTED_MASK                      0x40000000L
#define TX_FORMAT0_12__PROJECTED                           0x40000000L
#define TX_FORMAT0_12__TXPITCH_EN_MASK                     0x80000000L
#define TX_FORMAT0_12__TXPITCH_EN                          0x80000000L

// TX_FORMAT0_13
#define TX_FORMAT0_13__TXWIDTH_MASK                        0x000007ffL
#define TX_FORMAT0_13__TXHEIGHT_MASK                       0x003ff800L
#define TX_FORMAT0_13__TXDEPTH_MASK                        0x03c00000L
#define TX_FORMAT0_13__NUM_LEVELS_MASK                     0x3c000000L
#define TX_FORMAT0_13__PROJECTED_MASK                      0x40000000L
#define TX_FORMAT0_13__PROJECTED                           0x40000000L
#define TX_FORMAT0_13__TXPITCH_EN_MASK                     0x80000000L
#define TX_FORMAT0_13__TXPITCH_EN                          0x80000000L

// TX_FORMAT0_14
#define TX_FORMAT0_14__TXWIDTH_MASK                        0x000007ffL
#define TX_FORMAT0_14__TXHEIGHT_MASK                       0x003ff800L
#define TX_FORMAT0_14__TXDEPTH_MASK                        0x03c00000L
#define TX_FORMAT0_14__NUM_LEVELS_MASK                     0x3c000000L
#define TX_FORMAT0_14__PROJECTED_MASK                      0x40000000L
#define TX_FORMAT0_14__PROJECTED                           0x40000000L
#define TX_FORMAT0_14__TXPITCH_EN_MASK                     0x80000000L
#define TX_FORMAT0_14__TXPITCH_EN                          0x80000000L

// TX_FORMAT0_15
#define TX_FORMAT0_15__TXWIDTH_MASK                        0x000007ffL
#define TX_FORMAT0_15__TXHEIGHT_MASK                       0x003ff800L
#define TX_FORMAT0_15__TXDEPTH_MASK                        0x03c00000L
#define TX_FORMAT0_15__NUM_LEVELS_MASK                     0x3c000000L
#define TX_FORMAT0_15__PROJECTED_MASK                      0x40000000L
#define TX_FORMAT0_15__PROJECTED                           0x40000000L
#define TX_FORMAT0_15__TXPITCH_EN_MASK                     0x80000000L
#define TX_FORMAT0_15__TXPITCH_EN                          0x80000000L

// TX_FORMAT1_0
#define TX_FORMAT1_0__TXFORMAT_MASK                        0x0000001fL
#define TX_FORMAT1_0__SIGNED_COMP0_MASK                    0x00000020L
#define TX_FORMAT1_0__SIGNED_COMP0                         0x00000020L
#define TX_FORMAT1_0__SIGNED_COMP1_MASK                    0x00000040L
#define TX_FORMAT1_0__SIGNED_COMP1                         0x00000040L
#define TX_FORMAT1_0__SIGNED_COMP2_MASK                    0x00000080L
#define TX_FORMAT1_0__SIGNED_COMP2                         0x00000080L
#define TX_FORMAT1_0__SIGNED_COMP3_MASK                    0x00000100L
#define TX_FORMAT1_0__SIGNED_COMP3                         0x00000100L
#define TX_FORMAT1_0__SEL_ALPHA_MASK                       0x00000e00L
#define TX_FORMAT1_0__SEL_RED_MASK                         0x00007000L
#define TX_FORMAT1_0__SEL_GREEN_MASK                       0x00038000L
#define TX_FORMAT1_0__SEL_BLUE_MASK                        0x001c0000L
#define TX_FORMAT1_0__GAMMA_MASK                           0x00200000L
#define TX_FORMAT1_0__GAMMA                                0x00200000L
#define TX_FORMAT1_0__YUV_TO_RGB_MASK                      0x00c00000L
#define TX_FORMAT1_0__APPLE_YUV_MASK                       0x01000000L
#define TX_FORMAT1_0__APPLE_YUV                            0x01000000L
#define TX_FORMAT1_0__TEX_COORD_TYPE_MASK                  0x06000000L
#define TX_FORMAT1_0__CACHE_MASK                           0xf8000000L

// TX_FORMAT1_1
#define TX_FORMAT1_1__TXFORMAT_MASK                        0x0000001fL
#define TX_FORMAT1_1__SIGNED_COMP0_MASK                    0x00000020L
#define TX_FORMAT1_1__SIGNED_COMP0                         0x00000020L
#define TX_FORMAT1_1__SIGNED_COMP1_MASK                    0x00000040L
#define TX_FORMAT1_1__SIGNED_COMP1                         0x00000040L
#define TX_FORMAT1_1__SIGNED_COMP2_MASK                    0x00000080L
#define TX_FORMAT1_1__SIGNED_COMP2                         0x00000080L
#define TX_FORMAT1_1__SIGNED_COMP3_MASK                    0x00000100L
#define TX_FORMAT1_1__SIGNED_COMP3                         0x00000100L
#define TX_FORMAT1_1__SEL_ALPHA_MASK                       0x00000e00L
#define TX_FORMAT1_1__SEL_RED_MASK                         0x00007000L
#define TX_FORMAT1_1__SEL_GREEN_MASK                       0x00038000L
#define TX_FORMAT1_1__SEL_BLUE_MASK                        0x001c0000L
#define TX_FORMAT1_1__GAMMA_MASK                           0x00200000L
#define TX_FORMAT1_1__GAMMA                                0x00200000L
#define TX_FORMAT1_1__YUV_TO_RGB_MASK                      0x00c00000L
#define TX_FORMAT1_1__APPLE_YUV_MASK                       0x01000000L
#define TX_FORMAT1_1__APPLE_YUV                            0x01000000L
#define TX_FORMAT1_1__TEX_COORD_TYPE_MASK                  0x06000000L
#define TX_FORMAT1_1__CACHE_MASK                           0xf8000000L

// TX_FORMAT1_2
#define TX_FORMAT1_2__TXFORMAT_MASK                        0x0000001fL
#define TX_FORMAT1_2__SIGNED_COMP0_MASK                    0x00000020L
#define TX_FORMAT1_2__SIGNED_COMP0                         0x00000020L
#define TX_FORMAT1_2__SIGNED_COMP1_MASK                    0x00000040L
#define TX_FORMAT1_2__SIGNED_COMP1                         0x00000040L
#define TX_FORMAT1_2__SIGNED_COMP2_MASK                    0x00000080L
#define TX_FORMAT1_2__SIGNED_COMP2                         0x00000080L
#define TX_FORMAT1_2__SIGNED_COMP3_MASK                    0x00000100L
#define TX_FORMAT1_2__SIGNED_COMP3                         0x00000100L
#define TX_FORMAT1_2__SEL_ALPHA_MASK                       0x00000e00L
#define TX_FORMAT1_2__SEL_RED_MASK                         0x00007000L
#define TX_FORMAT1_2__SEL_GREEN_MASK                       0x00038000L
#define TX_FORMAT1_2__SEL_BLUE_MASK                        0x001c0000L
#define TX_FORMAT1_2__GAMMA_MASK                           0x00200000L
#define TX_FORMAT1_2__GAMMA                                0x00200000L
#define TX_FORMAT1_2__YUV_TO_RGB_MASK                      0x00c00000L
#define TX_FORMAT1_2__APPLE_YUV_MASK                       0x01000000L
#define TX_FORMAT1_2__APPLE_YUV                            0x01000000L
#define TX_FORMAT1_2__TEX_COORD_TYPE_MASK                  0x06000000L
#define TX_FORMAT1_2__CACHE_MASK                           0xf8000000L

// TX_FORMAT1_3
#define TX_FORMAT1_3__TXFORMAT_MASK                        0x0000001fL
#define TX_FORMAT1_3__SIGNED_COMP0_MASK                    0x00000020L
#define TX_FORMAT1_3__SIGNED_COMP0                         0x00000020L
#define TX_FORMAT1_3__SIGNED_COMP1_MASK                    0x00000040L
#define TX_FORMAT1_3__SIGNED_COMP1                         0x00000040L
#define TX_FORMAT1_3__SIGNED_COMP2_MASK                    0x00000080L
#define TX_FORMAT1_3__SIGNED_COMP2                         0x00000080L
#define TX_FORMAT1_3__SIGNED_COMP3_MASK                    0x00000100L
#define TX_FORMAT1_3__SIGNED_COMP3                         0x00000100L
#define TX_FORMAT1_3__SEL_ALPHA_MASK                       0x00000e00L
#define TX_FORMAT1_3__SEL_RED_MASK                         0x00007000L
#define TX_FORMAT1_3__SEL_GREEN_MASK                       0x00038000L
#define TX_FORMAT1_3__SEL_BLUE_MASK                        0x001c0000L
#define TX_FORMAT1_3__GAMMA_MASK                           0x00200000L
#define TX_FORMAT1_3__GAMMA                                0x00200000L
#define TX_FORMAT1_3__YUV_TO_RGB_MASK                      0x00c00000L
#define TX_FORMAT1_3__APPLE_YUV_MASK                       0x01000000L
#define TX_FORMAT1_3__APPLE_YUV                            0x01000000L
#define TX_FORMAT1_3__TEX_COORD_TYPE_MASK                  0x06000000L
#define TX_FORMAT1_3__CACHE_MASK                           0xf8000000L

// TX_FORMAT1_4
#define TX_FORMAT1_4__TXFORMAT_MASK                        0x0000001fL
#define TX_FORMAT1_4__SIGNED_COMP0_MASK                    0x00000020L
#define TX_FORMAT1_4__SIGNED_COMP0                         0x00000020L
#define TX_FORMAT1_4__SIGNED_COMP1_MASK                    0x00000040L
#define TX_FORMAT1_4__SIGNED_COMP1                         0x00000040L
#define TX_FORMAT1_4__SIGNED_COMP2_MASK                    0x00000080L
#define TX_FORMAT1_4__SIGNED_COMP2                         0x00000080L
#define TX_FORMAT1_4__SIGNED_COMP3_MASK                    0x00000100L
#define TX_FORMAT1_4__SIGNED_COMP3                         0x00000100L
#define TX_FORMAT1_4__SEL_ALPHA_MASK                       0x00000e00L
#define TX_FORMAT1_4__SEL_RED_MASK                         0x00007000L
#define TX_FORMAT1_4__SEL_GREEN_MASK                       0x00038000L
#define TX_FORMAT1_4__SEL_BLUE_MASK                        0x001c0000L
#define TX_FORMAT1_4__GAMMA_MASK                           0x00200000L
#define TX_FORMAT1_4__GAMMA                                0x00200000L
#define TX_FORMAT1_4__YUV_TO_RGB_MASK                      0x00c00000L
#define TX_FORMAT1_4__APPLE_YUV_MASK                       0x01000000L
#define TX_FORMAT1_4__APPLE_YUV                            0x01000000L
#define TX_FORMAT1_4__TEX_COORD_TYPE_MASK                  0x06000000L
#define TX_FORMAT1_4__CACHE_MASK                           0xf8000000L

// TX_FORMAT1_5
#define TX_FORMAT1_5__TXFORMAT_MASK                        0x0000001fL
#define TX_FORMAT1_5__SIGNED_COMP0_MASK                    0x00000020L
#define TX_FORMAT1_5__SIGNED_COMP0                         0x00000020L
#define TX_FORMAT1_5__SIGNED_COMP1_MASK                    0x00000040L
#define TX_FORMAT1_5__SIGNED_COMP1                         0x00000040L
#define TX_FORMAT1_5__SIGNED_COMP2_MASK                    0x00000080L
#define TX_FORMAT1_5__SIGNED_COMP2                         0x00000080L
#define TX_FORMAT1_5__SIGNED_COMP3_MASK                    0x00000100L
#define TX_FORMAT1_5__SIGNED_COMP3                         0x00000100L
#define TX_FORMAT1_5__SEL_ALPHA_MASK                       0x00000e00L
#define TX_FORMAT1_5__SEL_RED_MASK                         0x00007000L
#define TX_FORMAT1_5__SEL_GREEN_MASK                       0x00038000L
#define TX_FORMAT1_5__SEL_BLUE_MASK                        0x001c0000L
#define TX_FORMAT1_5__GAMMA_MASK                           0x00200000L
#define TX_FORMAT1_5__GAMMA                                0x00200000L
#define TX_FORMAT1_5__YUV_TO_RGB_MASK                      0x00c00000L
#define TX_FORMAT1_5__APPLE_YUV_MASK                       0x01000000L
#define TX_FORMAT1_5__APPLE_YUV                            0x01000000L
#define TX_FORMAT1_5__TEX_COORD_TYPE_MASK                  0x06000000L
#define TX_FORMAT1_5__CACHE_MASK                           0xf8000000L

// TX_FORMAT1_6
#define TX_FORMAT1_6__TXFORMAT_MASK                        0x0000001fL
#define TX_FORMAT1_6__SIGNED_COMP0_MASK                    0x00000020L
#define TX_FORMAT1_6__SIGNED_COMP0                         0x00000020L
#define TX_FORMAT1_6__SIGNED_COMP1_MASK                    0x00000040L
#define TX_FORMAT1_6__SIGNED_COMP1                         0x00000040L
#define TX_FORMAT1_6__SIGNED_COMP2_MASK                    0x00000080L
#define TX_FORMAT1_6__SIGNED_COMP2                         0x00000080L
#define TX_FORMAT1_6__SIGNED_COMP3_MASK                    0x00000100L
#define TX_FORMAT1_6__SIGNED_COMP3                         0x00000100L
#define TX_FORMAT1_6__SEL_ALPHA_MASK                       0x00000e00L
#define TX_FORMAT1_6__SEL_RED_MASK                         0x00007000L
#define TX_FORMAT1_6__SEL_GREEN_MASK                       0x00038000L
#define TX_FORMAT1_6__SEL_BLUE_MASK                        0x001c0000L
#define TX_FORMAT1_6__GAMMA_MASK                           0x00200000L
#define TX_FORMAT1_6__GAMMA                                0x00200000L
#define TX_FORMAT1_6__YUV_TO_RGB_MASK                      0x00c00000L
#define TX_FORMAT1_6__APPLE_YUV_MASK                       0x01000000L
#define TX_FORMAT1_6__APPLE_YUV                            0x01000000L
#define TX_FORMAT1_6__TEX_COORD_TYPE_MASK                  0x06000000L
#define TX_FORMAT1_6__CACHE_MASK                           0xf8000000L

// TX_FORMAT1_7
#define TX_FORMAT1_7__TXFORMAT_MASK                        0x0000001fL
#define TX_FORMAT1_7__SIGNED_COMP0_MASK                    0x00000020L
#define TX_FORMAT1_7__SIGNED_COMP0                         0x00000020L
#define TX_FORMAT1_7__SIGNED_COMP1_MASK                    0x00000040L
#define TX_FORMAT1_7__SIGNED_COMP1                         0x00000040L
#define TX_FORMAT1_7__SIGNED_COMP2_MASK                    0x00000080L
#define TX_FORMAT1_7__SIGNED_COMP2                         0x00000080L
#define TX_FORMAT1_7__SIGNED_COMP3_MASK                    0x00000100L
#define TX_FORMAT1_7__SIGNED_COMP3                         0x00000100L
#define TX_FORMAT1_7__SEL_ALPHA_MASK                       0x00000e00L
#define TX_FORMAT1_7__SEL_RED_MASK                         0x00007000L
#define TX_FORMAT1_7__SEL_GREEN_MASK                       0x00038000L
#define TX_FORMAT1_7__SEL_BLUE_MASK                        0x001c0000L
#define TX_FORMAT1_7__GAMMA_MASK                           0x00200000L
#define TX_FORMAT1_7__GAMMA                                0x00200000L
#define TX_FORMAT1_7__YUV_TO_RGB_MASK                      0x00c00000L
#define TX_FORMAT1_7__APPLE_YUV_MASK                       0x01000000L
#define TX_FORMAT1_7__APPLE_YUV                            0x01000000L
#define TX_FORMAT1_7__TEX_COORD_TYPE_MASK                  0x06000000L
#define TX_FORMAT1_7__CACHE_MASK                           0xf8000000L

// TX_FORMAT1_8
#define TX_FORMAT1_8__TXFORMAT_MASK                        0x0000001fL
#define TX_FORMAT1_8__SIGNED_COMP0_MASK                    0x00000020L
#define TX_FORMAT1_8__SIGNED_COMP0                         0x00000020L
#define TX_FORMAT1_8__SIGNED_COMP1_MASK                    0x00000040L
#define TX_FORMAT1_8__SIGNED_COMP1                         0x00000040L
#define TX_FORMAT1_8__SIGNED_COMP2_MASK                    0x00000080L
#define TX_FORMAT1_8__SIGNED_COMP2                         0x00000080L
#define TX_FORMAT1_8__SIGNED_COMP3_MASK                    0x00000100L
#define TX_FORMAT1_8__SIGNED_COMP3                         0x00000100L
#define TX_FORMAT1_8__SEL_ALPHA_MASK                       0x00000e00L
#define TX_FORMAT1_8__SEL_RED_MASK                         0x00007000L
#define TX_FORMAT1_8__SEL_GREEN_MASK                       0x00038000L
#define TX_FORMAT1_8__SEL_BLUE_MASK                        0x001c0000L
#define TX_FORMAT1_8__GAMMA_MASK                           0x00200000L
#define TX_FORMAT1_8__GAMMA                                0x00200000L
#define TX_FORMAT1_8__YUV_TO_RGB_MASK                      0x00c00000L
#define TX_FORMAT1_8__APPLE_YUV_MASK                       0x01000000L
#define TX_FORMAT1_8__APPLE_YUV                            0x01000000L
#define TX_FORMAT1_8__TEX_COORD_TYPE_MASK                  0x06000000L
#define TX_FORMAT1_8__CACHE_MASK                           0xf8000000L

// TX_FORMAT1_9
#define TX_FORMAT1_9__TXFORMAT_MASK                        0x0000001fL
#define TX_FORMAT1_9__SIGNED_COMP0_MASK                    0x00000020L
#define TX_FORMAT1_9__SIGNED_COMP0                         0x00000020L
#define TX_FORMAT1_9__SIGNED_COMP1_MASK                    0x00000040L
#define TX_FORMAT1_9__SIGNED_COMP1                         0x00000040L
#define TX_FORMAT1_9__SIGNED_COMP2_MASK                    0x00000080L
#define TX_FORMAT1_9__SIGNED_COMP2                         0x00000080L
#define TX_FORMAT1_9__SIGNED_COMP3_MASK                    0x00000100L
#define TX_FORMAT1_9__SIGNED_COMP3                         0x00000100L
#define TX_FORMAT1_9__SEL_ALPHA_MASK                       0x00000e00L
#define TX_FORMAT1_9__SEL_RED_MASK                         0x00007000L
#define TX_FORMAT1_9__SEL_GREEN_MASK                       0x00038000L
#define TX_FORMAT1_9__SEL_BLUE_MASK                        0x001c0000L
#define TX_FORMAT1_9__GAMMA_MASK                           0x00200000L
#define TX_FORMAT1_9__GAMMA                                0x00200000L
#define TX_FORMAT1_9__YUV_TO_RGB_MASK                      0x00c00000L
#define TX_FORMAT1_9__APPLE_YUV_MASK                       0x01000000L
#define TX_FORMAT1_9__APPLE_YUV                            0x01000000L
#define TX_FORMAT1_9__TEX_COORD_TYPE_MASK                  0x06000000L
#define TX_FORMAT1_9__CACHE_MASK                           0xf8000000L

// TX_FORMAT1_10
#define TX_FORMAT1_10__TXFORMAT_MASK                       0x0000001fL
#define TX_FORMAT1_10__SIGNED_COMP0_MASK                   0x00000020L
#define TX_FORMAT1_10__SIGNED_COMP0                        0x00000020L
#define TX_FORMAT1_10__SIGNED_COMP1_MASK                   0x00000040L
#define TX_FORMAT1_10__SIGNED_COMP1                        0x00000040L
#define TX_FORMAT1_10__SIGNED_COMP2_MASK                   0x00000080L
#define TX_FORMAT1_10__SIGNED_COMP2                        0x00000080L
#define TX_FORMAT1_10__SIGNED_COMP3_MASK                   0x00000100L
#define TX_FORMAT1_10__SIGNED_COMP3                        0x00000100L
#define TX_FORMAT1_10__SEL_ALPHA_MASK                      0x00000e00L
#define TX_FORMAT1_10__SEL_RED_MASK                        0x00007000L
#define TX_FORMAT1_10__SEL_GREEN_MASK                      0x00038000L
#define TX_FORMAT1_10__SEL_BLUE_MASK                       0x001c0000L
#define TX_FORMAT1_10__GAMMA_MASK                          0x00200000L
#define TX_FORMAT1_10__GAMMA                               0x00200000L
#define TX_FORMAT1_10__YUV_TO_RGB_MASK                     0x00c00000L
#define TX_FORMAT1_10__APPLE_YUV_MASK                      0x01000000L
#define TX_FORMAT1_10__APPLE_YUV                           0x01000000L
#define TX_FORMAT1_10__TEX_COORD_TYPE_MASK                 0x06000000L
#define TX_FORMAT1_10__CACHE_MASK                          0xf8000000L

// TX_FORMAT1_11
#define TX_FORMAT1_11__TXFORMAT_MASK                       0x0000001fL
#define TX_FORMAT1_11__SIGNED_COMP0_MASK                   0x00000020L
#define TX_FORMAT1_11__SIGNED_COMP0                        0x00000020L
#define TX_FORMAT1_11__SIGNED_COMP1_MASK                   0x00000040L
#define TX_FORMAT1_11__SIGNED_COMP1                        0x00000040L
#define TX_FORMAT1_11__SIGNED_COMP2_MASK                   0x00000080L
#define TX_FORMAT1_11__SIGNED_COMP2                        0x00000080L
#define TX_FORMAT1_11__SIGNED_COMP3_MASK                   0x00000100L
#define TX_FORMAT1_11__SIGNED_COMP3                        0x00000100L
#define TX_FORMAT1_11__SEL_ALPHA_MASK                      0x00000e00L
#define TX_FORMAT1_11__SEL_RED_MASK                        0x00007000L
#define TX_FORMAT1_11__SEL_GREEN_MASK                      0x00038000L
#define TX_FORMAT1_11__SEL_BLUE_MASK                       0x001c0000L
#define TX_FORMAT1_11__GAMMA_MASK                          0x00200000L
#define TX_FORMAT1_11__GAMMA                               0x00200000L
#define TX_FORMAT1_11__YUV_TO_RGB_MASK                     0x00c00000L
#define TX_FORMAT1_11__APPLE_YUV_MASK                      0x01000000L
#define TX_FORMAT1_11__APPLE_YUV                           0x01000000L
#define TX_FORMAT1_11__TEX_COORD_TYPE_MASK                 0x06000000L
#define TX_FORMAT1_11__CACHE_MASK                          0xf8000000L

// TX_FORMAT1_12
#define TX_FORMAT1_12__TXFORMAT_MASK                       0x0000001fL
#define TX_FORMAT1_12__SIGNED_COMP0_MASK                   0x00000020L
#define TX_FORMAT1_12__SIGNED_COMP0                        0x00000020L
#define TX_FORMAT1_12__SIGNED_COMP1_MASK                   0x00000040L
#define TX_FORMAT1_12__SIGNED_COMP1                        0x00000040L
#define TX_FORMAT1_12__SIGNED_COMP2_MASK                   0x00000080L
#define TX_FORMAT1_12__SIGNED_COMP2                        0x00000080L
#define TX_FORMAT1_12__SIGNED_COMP3_MASK                   0x00000100L
#define TX_FORMAT1_12__SIGNED_COMP3                        0x00000100L
#define TX_FORMAT1_12__SEL_ALPHA_MASK                      0x00000e00L
#define TX_FORMAT1_12__SEL_RED_MASK                        0x00007000L
#define TX_FORMAT1_12__SEL_GREEN_MASK                      0x00038000L
#define TX_FORMAT1_12__SEL_BLUE_MASK                       0x001c0000L
#define TX_FORMAT1_12__GAMMA_MASK                          0x00200000L
#define TX_FORMAT1_12__GAMMA                               0x00200000L
#define TX_FORMAT1_12__YUV_TO_RGB_MASK                     0x00c00000L
#define TX_FORMAT1_12__APPLE_YUV_MASK                      0x01000000L
#define TX_FORMAT1_12__APPLE_YUV                           0x01000000L
#define TX_FORMAT1_12__TEX_COORD_TYPE_MASK                 0x06000000L
#define TX_FORMAT1_12__CACHE_MASK                          0xf8000000L

// TX_FORMAT1_13
#define TX_FORMAT1_13__TXFORMAT_MASK                       0x0000001fL
#define TX_FORMAT1_13__SIGNED_COMP0_MASK                   0x00000020L
#define TX_FORMAT1_13__SIGNED_COMP0                        0x00000020L
#define TX_FORMAT1_13__SIGNED_COMP1_MASK                   0x00000040L
#define TX_FORMAT1_13__SIGNED_COMP1                        0x00000040L
#define TX_FORMAT1_13__SIGNED_COMP2_MASK                   0x00000080L
#define TX_FORMAT1_13__SIGNED_COMP2                        0x00000080L
#define TX_FORMAT1_13__SIGNED_COMP3_MASK                   0x00000100L
#define TX_FORMAT1_13__SIGNED_COMP3                        0x00000100L
#define TX_FORMAT1_13__SEL_ALPHA_MASK                      0x00000e00L
#define TX_FORMAT1_13__SEL_RED_MASK                        0x00007000L
#define TX_FORMAT1_13__SEL_GREEN_MASK                      0x00038000L
#define TX_FORMAT1_13__SEL_BLUE_MASK                       0x001c0000L
#define TX_FORMAT1_13__GAMMA_MASK                          0x00200000L
#define TX_FORMAT1_13__GAMMA                               0x00200000L
#define TX_FORMAT1_13__YUV_TO_RGB_MASK                     0x00c00000L
#define TX_FORMAT1_13__APPLE_YUV_MASK                      0x01000000L
#define TX_FORMAT1_13__APPLE_YUV                           0x01000000L
#define TX_FORMAT1_13__TEX_COORD_TYPE_MASK                 0x06000000L
#define TX_FORMAT1_13__CACHE_MASK                          0xf8000000L

// TX_FORMAT1_14
#define TX_FORMAT1_14__TXFORMAT_MASK                       0x0000001fL
#define TX_FORMAT1_14__SIGNED_COMP0_MASK                   0x00000020L
#define TX_FORMAT1_14__SIGNED_COMP0                        0x00000020L
#define TX_FORMAT1_14__SIGNED_COMP1_MASK                   0x00000040L
#define TX_FORMAT1_14__SIGNED_COMP1                        0x00000040L
#define TX_FORMAT1_14__SIGNED_COMP2_MASK                   0x00000080L
#define TX_FORMAT1_14__SIGNED_COMP2                        0x00000080L
#define TX_FORMAT1_14__SIGNED_COMP3_MASK                   0x00000100L
#define TX_FORMAT1_14__SIGNED_COMP3                        0x00000100L
#define TX_FORMAT1_14__SEL_ALPHA_MASK                      0x00000e00L
#define TX_FORMAT1_14__SEL_RED_MASK                        0x00007000L
#define TX_FORMAT1_14__SEL_GREEN_MASK                      0x00038000L
#define TX_FORMAT1_14__SEL_BLUE_MASK                       0x001c0000L
#define TX_FORMAT1_14__GAMMA_MASK                          0x00200000L
#define TX_FORMAT1_14__GAMMA                               0x00200000L
#define TX_FORMAT1_14__YUV_TO_RGB_MASK                     0x00c00000L
#define TX_FORMAT1_14__APPLE_YUV_MASK                      0x01000000L
#define TX_FORMAT1_14__APPLE_YUV                           0x01000000L
#define TX_FORMAT1_14__TEX_COORD_TYPE_MASK                 0x06000000L
#define TX_FORMAT1_14__CACHE_MASK                          0xf8000000L

// TX_FORMAT1_15
#define TX_FORMAT1_15__TXFORMAT_MASK                       0x0000001fL
#define TX_FORMAT1_15__SIGNED_COMP0_MASK                   0x00000020L
#define TX_FORMAT1_15__SIGNED_COMP0                        0x00000020L
#define TX_FORMAT1_15__SIGNED_COMP1_MASK                   0x00000040L
#define TX_FORMAT1_15__SIGNED_COMP1                        0x00000040L
#define TX_FORMAT1_15__SIGNED_COMP2_MASK                   0x00000080L
#define TX_FORMAT1_15__SIGNED_COMP2                        0x00000080L
#define TX_FORMAT1_15__SIGNED_COMP3_MASK                   0x00000100L
#define TX_FORMAT1_15__SIGNED_COMP3                        0x00000100L
#define TX_FORMAT1_15__SEL_ALPHA_MASK                      0x00000e00L
#define TX_FORMAT1_15__SEL_RED_MASK                        0x00007000L
#define TX_FORMAT1_15__SEL_GREEN_MASK                      0x00038000L
#define TX_FORMAT1_15__SEL_BLUE_MASK                       0x001c0000L
#define TX_FORMAT1_15__GAMMA_MASK                          0x00200000L
#define TX_FORMAT1_15__GAMMA                               0x00200000L
#define TX_FORMAT1_15__YUV_TO_RGB_MASK                     0x00c00000L
#define TX_FORMAT1_15__APPLE_YUV_MASK                      0x01000000L
#define TX_FORMAT1_15__APPLE_YUV                           0x01000000L
#define TX_FORMAT1_15__TEX_COORD_TYPE_MASK                 0x06000000L
#define TX_FORMAT1_15__CACHE_MASK                          0xf8000000L

// TX_FORMAT2_0
#define TX_FORMAT2_0__TXPITCH_MASK                         0x00003fffL

// TX_FORMAT2_1
#define TX_FORMAT2_1__TXPITCH_MASK                         0x00003fffL

// TX_FORMAT2_2
#define TX_FORMAT2_2__TXPITCH_MASK                         0x00003fffL

// TX_FORMAT2_3
#define TX_FORMAT2_3__TXPITCH_MASK                         0x00003fffL

// TX_FORMAT2_4
#define TX_FORMAT2_4__TXPITCH_MASK                         0x00003fffL

// TX_FORMAT2_5
#define TX_FORMAT2_5__TXPITCH_MASK                         0x00003fffL

// TX_FORMAT2_6
#define TX_FORMAT2_6__TXPITCH_MASK                         0x00003fffL

// TX_FORMAT2_7
#define TX_FORMAT2_7__TXPITCH_MASK                         0x00003fffL

// TX_FORMAT2_8
#define TX_FORMAT2_8__TXPITCH_MASK                         0x00003fffL

// TX_FORMAT2_9
#define TX_FORMAT2_9__TXPITCH_MASK                         0x00003fffL

// TX_FORMAT2_10
#define TX_FORMAT2_10__TXPITCH_MASK                        0x00003fffL

// TX_FORMAT2_11
#define TX_FORMAT2_11__TXPITCH_MASK                        0x00003fffL

// TX_FORMAT2_12
#define TX_FORMAT2_12__TXPITCH_MASK                        0x00003fffL

// TX_FORMAT2_13
#define TX_FORMAT2_13__TXPITCH_MASK                        0x00003fffL

// TX_FORMAT2_14
#define TX_FORMAT2_14__TXPITCH_MASK                        0x00003fffL

// TX_FORMAT2_15
#define TX_FORMAT2_15__TXPITCH_MASK                        0x00003fffL

// TX_OFFSET_0
#define TX_OFFSET_0__ENDIAN_SWAP_MASK                      0x00000003L
#define TX_OFFSET_0__MACRO_TILE_MASK                       0x00000004L
#define TX_OFFSET_0__MACRO_TILE                            0x00000004L
#define TX_OFFSET_0__MICRO_TILE_MASK                       0x00000018L
#define TX_OFFSET_0__TXOFFSET_MASK                         0xffffffe0L

// TX_OFFSET_1
#define TX_OFFSET_1__ENDIAN_SWAP_MASK                      0x00000003L
#define TX_OFFSET_1__MACRO_TILE_MASK                       0x00000004L
#define TX_OFFSET_1__MACRO_TILE                            0x00000004L
#define TX_OFFSET_1__MICRO_TILE_MASK                       0x00000018L
#define TX_OFFSET_1__TXOFFSET_MASK                         0xffffffe0L

// TX_OFFSET_2
#define TX_OFFSET_2__ENDIAN_SWAP_MASK                      0x00000003L
#define TX_OFFSET_2__MACRO_TILE_MASK                       0x00000004L
#define TX_OFFSET_2__MACRO_TILE                            0x00000004L
#define TX_OFFSET_2__MICRO_TILE_MASK                       0x00000018L
#define TX_OFFSET_2__TXOFFSET_MASK                         0xffffffe0L

// TX_OFFSET_3
#define TX_OFFSET_3__ENDIAN_SWAP_MASK                      0x00000003L
#define TX_OFFSET_3__MACRO_TILE_MASK                       0x00000004L
#define TX_OFFSET_3__MACRO_TILE                            0x00000004L
#define TX_OFFSET_3__MICRO_TILE_MASK                       0x00000018L
#define TX_OFFSET_3__TXOFFSET_MASK                         0xffffffe0L

// TX_OFFSET_4
#define TX_OFFSET_4__ENDIAN_SWAP_MASK                      0x00000003L
#define TX_OFFSET_4__MACRO_TILE_MASK                       0x00000004L
#define TX_OFFSET_4__MACRO_TILE                            0x00000004L
#define TX_OFFSET_4__MICRO_TILE_MASK                       0x00000018L
#define TX_OFFSET_4__TXOFFSET_MASK                         0xffffffe0L

// TX_OFFSET_5
#define TX_OFFSET_5__ENDIAN_SWAP_MASK                      0x00000003L
#define TX_OFFSET_5__MACRO_TILE_MASK                       0x00000004L
#define TX_OFFSET_5__MACRO_TILE                            0x00000004L
#define TX_OFFSET_5__MICRO_TILE_MASK                       0x00000018L
#define TX_OFFSET_5__TXOFFSET_MASK                         0xffffffe0L

// TX_OFFSET_6
#define TX_OFFSET_6__ENDIAN_SWAP_MASK                      0x00000003L
#define TX_OFFSET_6__MACRO_TILE_MASK                       0x00000004L
#define TX_OFFSET_6__MACRO_TILE                            0x00000004L
#define TX_OFFSET_6__MICRO_TILE_MASK                       0x00000018L
#define TX_OFFSET_6__TXOFFSET_MASK                         0xffffffe0L

// TX_OFFSET_7
#define TX_OFFSET_7__ENDIAN_SWAP_MASK                      0x00000003L
#define TX_OFFSET_7__MACRO_TILE_MASK                       0x00000004L
#define TX_OFFSET_7__MACRO_TILE                            0x00000004L
#define TX_OFFSET_7__MICRO_TILE_MASK                       0x00000018L
#define TX_OFFSET_7__TXOFFSET_MASK                         0xffffffe0L

// TX_OFFSET_8
#define TX_OFFSET_8__ENDIAN_SWAP_MASK                      0x00000003L
#define TX_OFFSET_8__MACRO_TILE_MASK                       0x00000004L
#define TX_OFFSET_8__MACRO_TILE                            0x00000004L
#define TX_OFFSET_8__MICRO_TILE_MASK                       0x00000018L
#define TX_OFFSET_8__TXOFFSET_MASK                         0xffffffe0L

// TX_OFFSET_9
#define TX_OFFSET_9__ENDIAN_SWAP_MASK                      0x00000003L
#define TX_OFFSET_9__MACRO_TILE_MASK                       0x00000004L
#define TX_OFFSET_9__MACRO_TILE                            0x00000004L
#define TX_OFFSET_9__MICRO_TILE_MASK                       0x00000018L
#define TX_OFFSET_9__TXOFFSET_MASK                         0xffffffe0L

// TX_OFFSET_10
#define TX_OFFSET_10__ENDIAN_SWAP_MASK                     0x00000003L
#define TX_OFFSET_10__MACRO_TILE_MASK                      0x00000004L
#define TX_OFFSET_10__MACRO_TILE                           0x00000004L
#define TX_OFFSET_10__MICRO_TILE_MASK                      0x00000018L
#define TX_OFFSET_10__TXOFFSET_MASK                        0xffffffe0L

// TX_OFFSET_11
#define TX_OFFSET_11__ENDIAN_SWAP_MASK                     0x00000003L
#define TX_OFFSET_11__MACRO_TILE_MASK                      0x00000004L
#define TX_OFFSET_11__MACRO_TILE                           0x00000004L
#define TX_OFFSET_11__MICRO_TILE_MASK                      0x00000018L
#define TX_OFFSET_11__TXOFFSET_MASK                        0xffffffe0L

// TX_OFFSET_12
#define TX_OFFSET_12__ENDIAN_SWAP_MASK                     0x00000003L
#define TX_OFFSET_12__MACRO_TILE_MASK                      0x00000004L
#define TX_OFFSET_12__MACRO_TILE                           0x00000004L
#define TX_OFFSET_12__MICRO_TILE_MASK                      0x00000018L
#define TX_OFFSET_12__TXOFFSET_MASK                        0xffffffe0L

// TX_OFFSET_13
#define TX_OFFSET_13__ENDIAN_SWAP_MASK                     0x00000003L
#define TX_OFFSET_13__MACRO_TILE_MASK                      0x00000004L
#define TX_OFFSET_13__MACRO_TILE                           0x00000004L
#define TX_OFFSET_13__MICRO_TILE_MASK                      0x00000018L
#define TX_OFFSET_13__TXOFFSET_MASK                        0xffffffe0L

// TX_OFFSET_14
#define TX_OFFSET_14__ENDIAN_SWAP_MASK                     0x00000003L
#define TX_OFFSET_14__MACRO_TILE_MASK                      0x00000004L
#define TX_OFFSET_14__MACRO_TILE                           0x00000004L
#define TX_OFFSET_14__MICRO_TILE_MASK                      0x00000018L
#define TX_OFFSET_14__TXOFFSET_MASK                        0xffffffe0L

// TX_OFFSET_15
#define TX_OFFSET_15__ENDIAN_SWAP_MASK                     0x00000003L
#define TX_OFFSET_15__MACRO_TILE_MASK                      0x00000004L
#define TX_OFFSET_15__MACRO_TILE                           0x00000004L
#define TX_OFFSET_15__MICRO_TILE_MASK                      0x00000018L
#define TX_OFFSET_15__TXOFFSET_MASK                        0xffffffe0L

// TX_CHROMA_KEY_0
#define TX_CHROMA_KEY_0__CHROMA_KEY_MASK                   0xffffffffL

// TX_CHROMA_KEY_1
#define TX_CHROMA_KEY_1__CHROMA_KEY_MASK                   0xffffffffL

// TX_CHROMA_KEY_2
#define TX_CHROMA_KEY_2__CHROMA_KEY_MASK                   0xffffffffL

// TX_CHROMA_KEY_3
#define TX_CHROMA_KEY_3__CHROMA_KEY_MASK                   0xffffffffL

// TX_CHROMA_KEY_4
#define TX_CHROMA_KEY_4__CHROMA_KEY_MASK                   0xffffffffL

// TX_CHROMA_KEY_5
#define TX_CHROMA_KEY_5__CHROMA_KEY_MASK                   0xffffffffL

// TX_CHROMA_KEY_6
#define TX_CHROMA_KEY_6__CHROMA_KEY_MASK                   0xffffffffL

// TX_CHROMA_KEY_7
#define TX_CHROMA_KEY_7__CHROMA_KEY_MASK                   0xffffffffL

// TX_CHROMA_KEY_8
#define TX_CHROMA_KEY_8__CHROMA_KEY_MASK                   0xffffffffL

// TX_CHROMA_KEY_9
#define TX_CHROMA_KEY_9__CHROMA_KEY_MASK                   0xffffffffL

// TX_CHROMA_KEY_10
#define TX_CHROMA_KEY_10__CHROMA_KEY_MASK                  0xffffffffL

// TX_CHROMA_KEY_11
#define TX_CHROMA_KEY_11__CHROMA_KEY_MASK                  0xffffffffL

// TX_CHROMA_KEY_12
#define TX_CHROMA_KEY_12__CHROMA_KEY_MASK                  0xffffffffL

// TX_CHROMA_KEY_13
#define TX_CHROMA_KEY_13__CHROMA_KEY_MASK                  0xffffffffL

// TX_CHROMA_KEY_14
#define TX_CHROMA_KEY_14__CHROMA_KEY_MASK                  0xffffffffL

// TX_CHROMA_KEY_15
#define TX_CHROMA_KEY_15__CHROMA_KEY_MASK                  0xffffffffL

// TX_BORDER_COLOR_0
#define TX_BORDER_COLOR_0__BORDER_COLOR_MASK               0xffffffffL

// TX_BORDER_COLOR_1
#define TX_BORDER_COLOR_1__BORDER_COLOR_MASK               0xffffffffL

// TX_BORDER_COLOR_2
#define TX_BORDER_COLOR_2__BORDER_COLOR_MASK               0xffffffffL

// TX_BORDER_COLOR_3
#define TX_BORDER_COLOR_3__BORDER_COLOR_MASK               0xffffffffL

// TX_BORDER_COLOR_4
#define TX_BORDER_COLOR_4__BORDER_COLOR_MASK               0xffffffffL

// TX_BORDER_COLOR_5
#define TX_BORDER_COLOR_5__BORDER_COLOR_MASK               0xffffffffL

// TX_BORDER_COLOR_6
#define TX_BORDER_COLOR_6__BORDER_COLOR_MASK               0xffffffffL

// TX_BORDER_COLOR_7
#define TX_BORDER_COLOR_7__BORDER_COLOR_MASK               0xffffffffL

// TX_BORDER_COLOR_8
#define TX_BORDER_COLOR_8__BORDER_COLOR_MASK               0xffffffffL

// TX_BORDER_COLOR_9
#define TX_BORDER_COLOR_9__BORDER_COLOR_MASK               0xffffffffL

// TX_BORDER_COLOR_10
#define TX_BORDER_COLOR_10__BORDER_COLOR_MASK              0xffffffffL

// TX_BORDER_COLOR_11
#define TX_BORDER_COLOR_11__BORDER_COLOR_MASK              0xffffffffL

// TX_BORDER_COLOR_12
#define TX_BORDER_COLOR_12__BORDER_COLOR_MASK              0xffffffffL

// TX_BORDER_COLOR_13
#define TX_BORDER_COLOR_13__BORDER_COLOR_MASK              0xffffffffL

// TX_BORDER_COLOR_14
#define TX_BORDER_COLOR_14__BORDER_COLOR_MASK              0xffffffffL

// TX_BORDER_COLOR_15
#define TX_BORDER_COLOR_15__BORDER_COLOR_MASK              0xffffffffL

// TX_ENABLE
#define TX_ENABLE__TEX_0_ENABLE_MASK                       0x00000001L
#define TX_ENABLE__TEX_0_ENABLE                            0x00000001L
#define TX_ENABLE__TEX_1_ENABLE_MASK                       0x00000002L
#define TX_ENABLE__TEX_1_ENABLE                            0x00000002L
#define TX_ENABLE__TEX_2_ENABLE_MASK                       0x00000004L
#define TX_ENABLE__TEX_2_ENABLE                            0x00000004L
#define TX_ENABLE__TEX_3_ENABLE_MASK                       0x00000008L
#define TX_ENABLE__TEX_3_ENABLE                            0x00000008L
#define TX_ENABLE__TEX_4_ENABLE_MASK                       0x00000010L
#define TX_ENABLE__TEX_4_ENABLE                            0x00000010L
#define TX_ENABLE__TEX_5_ENABLE_MASK                       0x00000020L
#define TX_ENABLE__TEX_5_ENABLE                            0x00000020L
#define TX_ENABLE__TEX_6_ENABLE_MASK                       0x00000040L
#define TX_ENABLE__TEX_6_ENABLE                            0x00000040L
#define TX_ENABLE__TEX_7_ENABLE_MASK                       0x00000080L
#define TX_ENABLE__TEX_7_ENABLE                            0x00000080L
#define TX_ENABLE__TEX_8_ENABLE_MASK                       0x00000100L
#define TX_ENABLE__TEX_8_ENABLE                            0x00000100L
#define TX_ENABLE__TEX_9_ENABLE_MASK                       0x00000200L
#define TX_ENABLE__TEX_9_ENABLE                            0x00000200L
#define TX_ENABLE__TEX_10_ENABLE_MASK                      0x00000400L
#define TX_ENABLE__TEX_10_ENABLE                           0x00000400L
#define TX_ENABLE__TEX_11_ENABLE_MASK                      0x00000800L
#define TX_ENABLE__TEX_11_ENABLE                           0x00000800L
#define TX_ENABLE__TEX_12_ENABLE_MASK                      0x00001000L
#define TX_ENABLE__TEX_12_ENABLE                           0x00001000L
#define TX_ENABLE__TEX_13_ENABLE_MASK                      0x00002000L
#define TX_ENABLE__TEX_13_ENABLE                           0x00002000L
#define TX_ENABLE__TEX_14_ENABLE_MASK                      0x00004000L
#define TX_ENABLE__TEX_14_ENABLE                           0x00004000L
#define TX_ENABLE__TEX_15_ENABLE_MASK                      0x00008000L
#define TX_ENABLE__TEX_15_ENABLE                           0x00008000L

// TX_INVALTAGS
#define TX_INVALTAGS__RESERVED_MASK                        0xffffffffL

// TX_PERF
#define TX_PERF__PERF0_MASK                                0x0000001fL
#define TX_PERF__PERF1_MASK                                0x000003e0L
#define TX_PERF__PERF2_MASK                                0x00007c00L
#define TX_PERF__PERF3_MASK                                0x000f8000L
#define TX_PERF__DISABLE_MASK                              0xc0000000L

// US_CONFIG
#define US_CONFIG__NLEVEL_MASK                             0x00000007L
#define US_CONFIG__FIRST_TEX_MASK                          0x00000008L
#define US_CONFIG__FIRST_TEX                               0x00000008L
#define US_CONFIG__PERF0_MASK                              0x000001f0L
#define US_CONFIG__PERF1_MASK                              0x00003e00L
#define US_CONFIG__PERF2_MASK                              0x0007c000L
#define US_CONFIG__PERF3_MASK                              0x00f80000L

// US_PIXSIZE
#define US_PIXSIZE__PIX_SIZE_MASK                          0x0000001fL

// US_CODE_OFFSET
#define US_CODE_OFFSET__ALU_OFFSET_MASK                    0x0000003fL
#define US_CODE_OFFSET__ALU_SIZE_MASK                      0x00001fc0L
#define US_CODE_OFFSET__TEX_OFFSET_MASK                    0x0003e000L
#define US_CODE_OFFSET__TEX_SIZE_MASK                      0x00fc0000L

// US_RESET

// US_CODE_ADDR_0
#define US_CODE_ADDR_0__ALU_START_MASK                     0x0000003fL
#define US_CODE_ADDR_0__ALU_SIZE_MASK                      0x00000fc0L
#define US_CODE_ADDR_0__TEX_START_MASK                     0x0001f000L
#define US_CODE_ADDR_0__TEX_SIZE_MASK                      0x003e0000L
#define US_CODE_ADDR_0__RGBA_OUT_MASK                      0x00400000L
#define US_CODE_ADDR_0__RGBA_OUT                           0x00400000L
#define US_CODE_ADDR_0__W_OUT_MASK                         0x00800000L
#define US_CODE_ADDR_0__W_OUT                              0x00800000L

// US_CODE_ADDR_1
#define US_CODE_ADDR_1__ALU_START_MASK                     0x0000003fL
#define US_CODE_ADDR_1__ALU_SIZE_MASK                      0x00000fc0L
#define US_CODE_ADDR_1__TEX_START_MASK                     0x0001f000L
#define US_CODE_ADDR_1__TEX_SIZE_MASK                      0x003e0000L
#define US_CODE_ADDR_1__RGBA_OUT_MASK                      0x00400000L
#define US_CODE_ADDR_1__RGBA_OUT                           0x00400000L
#define US_CODE_ADDR_1__W_OUT_MASK                         0x00800000L
#define US_CODE_ADDR_1__W_OUT                              0x00800000L

// US_CODE_ADDR_2
#define US_CODE_ADDR_2__ALU_START_MASK                     0x0000003fL
#define US_CODE_ADDR_2__ALU_SIZE_MASK                      0x00000fc0L
#define US_CODE_ADDR_2__TEX_START_MASK                     0x0001f000L
#define US_CODE_ADDR_2__TEX_SIZE_MASK                      0x003e0000L
#define US_CODE_ADDR_2__RGBA_OUT_MASK                      0x00400000L
#define US_CODE_ADDR_2__RGBA_OUT                           0x00400000L
#define US_CODE_ADDR_2__W_OUT_MASK                         0x00800000L
#define US_CODE_ADDR_2__W_OUT                              0x00800000L

// US_CODE_ADDR_3
#define US_CODE_ADDR_3__ALU_START_MASK                     0x0000003fL
#define US_CODE_ADDR_3__ALU_SIZE_MASK                      0x00000fc0L
#define US_CODE_ADDR_3__TEX_START_MASK                     0x0001f000L
#define US_CODE_ADDR_3__TEX_SIZE_MASK                      0x003e0000L
#define US_CODE_ADDR_3__RGBA_OUT_MASK                      0x00400000L
#define US_CODE_ADDR_3__RGBA_OUT                           0x00400000L
#define US_CODE_ADDR_3__W_OUT_MASK                         0x00800000L
#define US_CODE_ADDR_3__W_OUT                              0x00800000L

// US_TEX_INST_0
#define US_TEX_INST_0__SRC_ADDR_MASK                       0x0000001fL
#define US_TEX_INST_0__DST_ADDR_MASK                       0x000007c0L
#define US_TEX_INST_0__TEX_ID_MASK                         0x00007800L
#define US_TEX_INST_0__INST_MASK                           0x00038000L
#define US_TEX_INST_0__OMOD_MASK                           0x00040000L
#define US_TEX_INST_0__OMOD                                0x00040000L

// US_TEX_INST_1
#define US_TEX_INST_1__SRC_ADDR_MASK                       0x0000001fL
#define US_TEX_INST_1__DST_ADDR_MASK                       0x000007c0L
#define US_TEX_INST_1__TEX_ID_MASK                         0x00007800L
#define US_TEX_INST_1__INST_MASK                           0x00038000L
#define US_TEX_INST_1__OMOD_MASK                           0x00040000L
#define US_TEX_INST_1__OMOD                                0x00040000L

// US_TEX_INST_2
#define US_TEX_INST_2__SRC_ADDR_MASK                       0x0000001fL
#define US_TEX_INST_2__DST_ADDR_MASK                       0x000007c0L
#define US_TEX_INST_2__TEX_ID_MASK                         0x00007800L
#define US_TEX_INST_2__INST_MASK                           0x00038000L
#define US_TEX_INST_2__OMOD_MASK                           0x00040000L
#define US_TEX_INST_2__OMOD                                0x00040000L

// US_TEX_INST_3
#define US_TEX_INST_3__SRC_ADDR_MASK                       0x0000001fL
#define US_TEX_INST_3__DST_ADDR_MASK                       0x000007c0L
#define US_TEX_INST_3__TEX_ID_MASK                         0x00007800L
#define US_TEX_INST_3__INST_MASK                           0x00038000L
#define US_TEX_INST_3__OMOD_MASK                           0x00040000L
#define US_TEX_INST_3__OMOD                                0x00040000L

// US_TEX_INST_4
#define US_TEX_INST_4__SRC_ADDR_MASK                       0x0000001fL
#define US_TEX_INST_4__DST_ADDR_MASK                       0x000007c0L
#define US_TEX_INST_4__TEX_ID_MASK                         0x00007800L
#define US_TEX_INST_4__INST_MASK                           0x00038000L
#define US_TEX_INST_4__OMOD_MASK                           0x00040000L
#define US_TEX_INST_4__OMOD                                0x00040000L

// US_TEX_INST_5
#define US_TEX_INST_5__SRC_ADDR_MASK                       0x0000001fL
#define US_TEX_INST_5__DST_ADDR_MASK                       0x000007c0L
#define US_TEX_INST_5__TEX_ID_MASK                         0x00007800L
#define US_TEX_INST_5__INST_MASK                           0x00038000L
#define US_TEX_INST_5__OMOD_MASK                           0x00040000L
#define US_TEX_INST_5__OMOD                                0x00040000L

// US_TEX_INST_6
#define US_TEX_INST_6__SRC_ADDR_MASK                       0x0000001fL
#define US_TEX_INST_6__DST_ADDR_MASK                       0x000007c0L
#define US_TEX_INST_6__TEX_ID_MASK                         0x00007800L
#define US_TEX_INST_6__INST_MASK                           0x00038000L
#define US_TEX_INST_6__OMOD_MASK                           0x00040000L
#define US_TEX_INST_6__OMOD                                0x00040000L

// US_TEX_INST_7
#define US_TEX_INST_7__SRC_ADDR_MASK                       0x0000001fL
#define US_TEX_INST_7__DST_ADDR_MASK                       0x000007c0L
#define US_TEX_INST_7__TEX_ID_MASK                         0x00007800L
#define US_TEX_INST_7__INST_MASK                           0x00038000L
#define US_TEX_INST_7__OMOD_MASK                           0x00040000L
#define US_TEX_INST_7__OMOD                                0x00040000L

// US_TEX_INST_8
#define US_TEX_INST_8__SRC_ADDR_MASK                       0x0000001fL
#define US_TEX_INST_8__DST_ADDR_MASK                       0x000007c0L
#define US_TEX_INST_8__TEX_ID_MASK                         0x00007800L
#define US_TEX_INST_8__INST_MASK                           0x00038000L
#define US_TEX_INST_8__OMOD_MASK                           0x00040000L
#define US_TEX_INST_8__OMOD                                0x00040000L

// US_TEX_INST_9
#define US_TEX_INST_9__SRC_ADDR_MASK                       0x0000001fL
#define US_TEX_INST_9__DST_ADDR_MASK                       0x000007c0L
#define US_TEX_INST_9__TEX_ID_MASK                         0x00007800L
#define US_TEX_INST_9__INST_MASK                           0x00038000L
#define US_TEX_INST_9__OMOD_MASK                           0x00040000L
#define US_TEX_INST_9__OMOD                                0x00040000L

// US_TEX_INST_10
#define US_TEX_INST_10__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_10__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_10__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_10__INST_MASK                          0x00038000L
#define US_TEX_INST_10__OMOD_MASK                          0x00040000L
#define US_TEX_INST_10__OMOD                               0x00040000L

// US_TEX_INST_11
#define US_TEX_INST_11__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_11__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_11__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_11__INST_MASK                          0x00038000L
#define US_TEX_INST_11__OMOD_MASK                          0x00040000L
#define US_TEX_INST_11__OMOD                               0x00040000L

// US_TEX_INST_12
#define US_TEX_INST_12__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_12__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_12__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_12__INST_MASK                          0x00038000L
#define US_TEX_INST_12__OMOD_MASK                          0x00040000L
#define US_TEX_INST_12__OMOD                               0x00040000L

// US_TEX_INST_13
#define US_TEX_INST_13__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_13__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_13__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_13__INST_MASK                          0x00038000L
#define US_TEX_INST_13__OMOD_MASK                          0x00040000L
#define US_TEX_INST_13__OMOD                               0x00040000L

// US_TEX_INST_14
#define US_TEX_INST_14__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_14__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_14__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_14__INST_MASK                          0x00038000L
#define US_TEX_INST_14__OMOD_MASK                          0x00040000L
#define US_TEX_INST_14__OMOD                               0x00040000L

// US_TEX_INST_15
#define US_TEX_INST_15__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_15__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_15__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_15__INST_MASK                          0x00038000L
#define US_TEX_INST_15__OMOD_MASK                          0x00040000L
#define US_TEX_INST_15__OMOD                               0x00040000L

// US_TEX_INST_16
#define US_TEX_INST_16__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_16__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_16__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_16__INST_MASK                          0x00038000L
#define US_TEX_INST_16__OMOD_MASK                          0x00040000L
#define US_TEX_INST_16__OMOD                               0x00040000L

// US_TEX_INST_17
#define US_TEX_INST_17__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_17__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_17__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_17__INST_MASK                          0x00038000L
#define US_TEX_INST_17__OMOD_MASK                          0x00040000L
#define US_TEX_INST_17__OMOD                               0x00040000L

// US_TEX_INST_18
#define US_TEX_INST_18__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_18__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_18__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_18__INST_MASK                          0x00038000L
#define US_TEX_INST_18__OMOD_MASK                          0x00040000L
#define US_TEX_INST_18__OMOD                               0x00040000L

// US_TEX_INST_19
#define US_TEX_INST_19__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_19__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_19__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_19__INST_MASK                          0x00038000L
#define US_TEX_INST_19__OMOD_MASK                          0x00040000L
#define US_TEX_INST_19__OMOD                               0x00040000L

// US_TEX_INST_20
#define US_TEX_INST_20__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_20__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_20__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_20__INST_MASK                          0x00038000L
#define US_TEX_INST_20__OMOD_MASK                          0x00040000L
#define US_TEX_INST_20__OMOD                               0x00040000L

// US_TEX_INST_21
#define US_TEX_INST_21__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_21__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_21__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_21__INST_MASK                          0x00038000L
#define US_TEX_INST_21__OMOD_MASK                          0x00040000L
#define US_TEX_INST_21__OMOD                               0x00040000L

// US_TEX_INST_22
#define US_TEX_INST_22__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_22__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_22__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_22__INST_MASK                          0x00038000L
#define US_TEX_INST_22__OMOD_MASK                          0x00040000L
#define US_TEX_INST_22__OMOD                               0x00040000L

// US_TEX_INST_23
#define US_TEX_INST_23__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_23__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_23__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_23__INST_MASK                          0x00038000L
#define US_TEX_INST_23__OMOD_MASK                          0x00040000L
#define US_TEX_INST_23__OMOD                               0x00040000L

// US_TEX_INST_24
#define US_TEX_INST_24__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_24__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_24__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_24__INST_MASK                          0x00038000L
#define US_TEX_INST_24__OMOD_MASK                          0x00040000L
#define US_TEX_INST_24__OMOD                               0x00040000L

// US_TEX_INST_25
#define US_TEX_INST_25__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_25__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_25__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_25__INST_MASK                          0x00038000L
#define US_TEX_INST_25__OMOD_MASK                          0x00040000L
#define US_TEX_INST_25__OMOD                               0x00040000L

// US_TEX_INST_26
#define US_TEX_INST_26__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_26__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_26__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_26__INST_MASK                          0x00038000L
#define US_TEX_INST_26__OMOD_MASK                          0x00040000L
#define US_TEX_INST_26__OMOD                               0x00040000L

// US_TEX_INST_27
#define US_TEX_INST_27__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_27__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_27__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_27__INST_MASK                          0x00038000L
#define US_TEX_INST_27__OMOD_MASK                          0x00040000L
#define US_TEX_INST_27__OMOD                               0x00040000L

// US_TEX_INST_28
#define US_TEX_INST_28__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_28__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_28__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_28__INST_MASK                          0x00038000L
#define US_TEX_INST_28__OMOD_MASK                          0x00040000L
#define US_TEX_INST_28__OMOD                               0x00040000L

// US_TEX_INST_29
#define US_TEX_INST_29__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_29__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_29__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_29__INST_MASK                          0x00038000L
#define US_TEX_INST_29__OMOD_MASK                          0x00040000L
#define US_TEX_INST_29__OMOD                               0x00040000L

// US_TEX_INST_30
#define US_TEX_INST_30__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_30__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_30__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_30__INST_MASK                          0x00038000L
#define US_TEX_INST_30__OMOD_MASK                          0x00040000L
#define US_TEX_INST_30__OMOD                               0x00040000L

// US_TEX_INST_31
#define US_TEX_INST_31__SRC_ADDR_MASK                      0x0000001fL
#define US_TEX_INST_31__DST_ADDR_MASK                      0x000007c0L
#define US_TEX_INST_31__TEX_ID_MASK                        0x00007800L
#define US_TEX_INST_31__INST_MASK                          0x00038000L
#define US_TEX_INST_31__OMOD_MASK                          0x00040000L
#define US_TEX_INST_31__OMOD                               0x00040000L

// US_OUT_FMT_0
#define US_OUT_FMT_0__OUT_FMT_MASK                         0x0000001fL
#define US_OUT_FMT_0__C0_SEL_MASK                          0x00000300L
#define US_OUT_FMT_0__C1_SEL_MASK                          0x00000c00L
#define US_OUT_FMT_0__C2_SEL_MASK                          0x00003000L
#define US_OUT_FMT_0__C3_SEL_MASK                          0x0000c000L
#define US_OUT_FMT_0__OUT_SIGN_MASK                        0x000f0000L

// US_OUT_FMT_1
#define US_OUT_FMT_1__OUT_FMT_MASK                         0x0000001fL
#define US_OUT_FMT_1__C0_SEL_MASK                          0x00000300L
#define US_OUT_FMT_1__C1_SEL_MASK                          0x00000c00L
#define US_OUT_FMT_1__C2_SEL_MASK                          0x00003000L
#define US_OUT_FMT_1__C3_SEL_MASK                          0x0000c000L
#define US_OUT_FMT_1__OUT_SIGN_MASK                        0x000f0000L

// US_OUT_FMT_2
#define US_OUT_FMT_2__OUT_FMT_MASK                         0x0000001fL
#define US_OUT_FMT_2__C0_SEL_MASK                          0x00000300L
#define US_OUT_FMT_2__C1_SEL_MASK                          0x00000c00L
#define US_OUT_FMT_2__C2_SEL_MASK                          0x00003000L
#define US_OUT_FMT_2__C3_SEL_MASK                          0x0000c000L
#define US_OUT_FMT_2__OUT_SIGN_MASK                        0x000f0000L

// US_OUT_FMT_3
#define US_OUT_FMT_3__OUT_FMT_MASK                         0x0000001fL
#define US_OUT_FMT_3__C0_SEL_MASK                          0x00000300L
#define US_OUT_FMT_3__C1_SEL_MASK                          0x00000c00L
#define US_OUT_FMT_3__C2_SEL_MASK                          0x00003000L
#define US_OUT_FMT_3__C3_SEL_MASK                          0x0000c000L
#define US_OUT_FMT_3__OUT_SIGN_MASK                        0x000f0000L

// US_W_FMT
#define US_W_FMT__W_FMT_MASK                               0x00000003L
#define US_W_FMT__W_SRC_MASK                               0x00000004L
#define US_W_FMT__W_SRC                                    0x00000004L

// US_ALU_RGB_ADDR_0
#define US_ALU_RGB_ADDR_0__ADDR0_MASK                      0x0000003fL
#define US_ALU_RGB_ADDR_0__ADDR1_MASK                      0x00000fc0L
#define US_ALU_RGB_ADDR_0__ADDR2_MASK                      0x0003f000L
#define US_ALU_RGB_ADDR_0__ADDRD_MASK                      0x007c0000L
#define US_ALU_RGB_ADDR_0__WMASK_MASK                      0x03800000L
#define US_ALU_RGB_ADDR_0__OMASK_MASK                      0x1c000000L
#define US_ALU_RGB_ADDR_0__TARGET_MASK                     0x60000000L

// US_ALU_RGB_ADDR_1
#define US_ALU_RGB_ADDR_1__ADDR0_MASK                      0x0000003fL
#define US_ALU_RGB_ADDR_1__ADDR1_MASK                      0x00000fc0L
#define US_ALU_RGB_ADDR_1__ADDR2_MASK                      0x0003f000L
#define US_ALU_RGB_ADDR_1__ADDRD_MASK                      0x007c0000L
#define US_ALU_RGB_ADDR_1__WMASK_MASK                      0x03800000L
#define US_ALU_RGB_ADDR_1__OMASK_MASK                      0x1c000000L
#define US_ALU_RGB_ADDR_1__TARGET_MASK                     0x60000000L

// US_ALU_RGB_ADDR_2
#define US_ALU_RGB_ADDR_2__ADDR0_MASK                      0x0000003fL
#define US_ALU_RGB_ADDR_2__ADDR1_MASK                      0x00000fc0L
#define US_ALU_RGB_ADDR_2__ADDR2_MASK                      0x0003f000L
#define US_ALU_RGB_ADDR_2__ADDRD_MASK                      0x007c0000L
#define US_ALU_RGB_ADDR_2__WMASK_MASK                      0x03800000L
#define US_ALU_RGB_ADDR_2__OMASK_MASK                      0x1c000000L
#define US_ALU_RGB_ADDR_2__TARGET_MASK                     0x60000000L

// US_ALU_RGB_ADDR_3
#define US_ALU_RGB_ADDR_3__ADDR0_MASK                      0x0000003fL
#define US_ALU_RGB_ADDR_3__ADDR1_MASK                      0x00000fc0L
#define US_ALU_RGB_ADDR_3__ADDR2_MASK                      0x0003f000L
#define US_ALU_RGB_ADDR_3__ADDRD_MASK                      0x007c0000L
#define US_ALU_RGB_ADDR_3__WMASK_MASK                      0x03800000L
#define US_ALU_RGB_ADDR_3__OMASK_MASK                      0x1c000000L
#define US_ALU_RGB_ADDR_3__TARGET_MASK                     0x60000000L

// US_ALU_RGB_ADDR_4
#define US_ALU_RGB_ADDR_4__ADDR0_MASK                      0x0000003fL
#define US_ALU_RGB_ADDR_4__ADDR1_MASK                      0x00000fc0L
#define US_ALU_RGB_ADDR_4__ADDR2_MASK                      0x0003f000L
#define US_ALU_RGB_ADDR_4__ADDRD_MASK                      0x007c0000L
#define US_ALU_RGB_ADDR_4__WMASK_MASK                      0x03800000L
#define US_ALU_RGB_ADDR_4__OMASK_MASK                      0x1c000000L
#define US_ALU_RGB_ADDR_4__TARGET_MASK                     0x60000000L

// US_ALU_RGB_ADDR_5
#define US_ALU_RGB_ADDR_5__ADDR0_MASK                      0x0000003fL
#define US_ALU_RGB_ADDR_5__ADDR1_MASK                      0x00000fc0L
#define US_ALU_RGB_ADDR_5__ADDR2_MASK                      0x0003f000L
#define US_ALU_RGB_ADDR_5__ADDRD_MASK                      0x007c0000L
#define US_ALU_RGB_ADDR_5__WMASK_MASK                      0x03800000L
#define US_ALU_RGB_ADDR_5__OMASK_MASK                      0x1c000000L
#define US_ALU_RGB_ADDR_5__TARGET_MASK                     0x60000000L

// US_ALU_RGB_ADDR_6
#define US_ALU_RGB_ADDR_6__ADDR0_MASK                      0x0000003fL
#define US_ALU_RGB_ADDR_6__ADDR1_MASK                      0x00000fc0L
#define US_ALU_RGB_ADDR_6__ADDR2_MASK                      0x0003f000L
#define US_ALU_RGB_ADDR_6__ADDRD_MASK                      0x007c0000L
#define US_ALU_RGB_ADDR_6__WMASK_MASK                      0x03800000L
#define US_ALU_RGB_ADDR_6__OMASK_MASK                      0x1c000000L
#define US_ALU_RGB_ADDR_6__TARGET_MASK                     0x60000000L

// US_ALU_RGB_ADDR_7
#define US_ALU_RGB_ADDR_7__ADDR0_MASK                      0x0000003fL
#define US_ALU_RGB_ADDR_7__ADDR1_MASK                      0x00000fc0L
#define US_ALU_RGB_ADDR_7__ADDR2_MASK                      0x0003f000L
#define US_ALU_RGB_ADDR_7__ADDRD_MASK                      0x007c0000L
#define US_ALU_RGB_ADDR_7__WMASK_MASK                      0x03800000L
#define US_ALU_RGB_ADDR_7__OMASK_MASK                      0x1c000000L
#define US_ALU_RGB_ADDR_7__TARGET_MASK                     0x60000000L

// US_ALU_RGB_ADDR_8
#define US_ALU_RGB_ADDR_8__ADDR0_MASK                      0x0000003fL
#define US_ALU_RGB_ADDR_8__ADDR1_MASK                      0x00000fc0L
#define US_ALU_RGB_ADDR_8__ADDR2_MASK                      0x0003f000L
#define US_ALU_RGB_ADDR_8__ADDRD_MASK                      0x007c0000L
#define US_ALU_RGB_ADDR_8__WMASK_MASK                      0x03800000L
#define US_ALU_RGB_ADDR_8__OMASK_MASK                      0x1c000000L
#define US_ALU_RGB_ADDR_8__TARGET_MASK                     0x60000000L

// US_ALU_RGB_ADDR_9
#define US_ALU_RGB_ADDR_9__ADDR0_MASK                      0x0000003fL
#define US_ALU_RGB_ADDR_9__ADDR1_MASK                      0x00000fc0L
#define US_ALU_RGB_ADDR_9__ADDR2_MASK                      0x0003f000L
#define US_ALU_RGB_ADDR_9__ADDRD_MASK                      0x007c0000L
#define US_ALU_RGB_ADDR_9__WMASK_MASK                      0x03800000L
#define US_ALU_RGB_ADDR_9__OMASK_MASK                      0x1c000000L
#define US_ALU_RGB_ADDR_9__TARGET_MASK                     0x60000000L

// US_ALU_RGB_ADDR_10
#define US_ALU_RGB_ADDR_10__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_10__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_10__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_10__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_10__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_10__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_10__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_11
#define US_ALU_RGB_ADDR_11__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_11__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_11__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_11__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_11__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_11__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_11__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_12
#define US_ALU_RGB_ADDR_12__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_12__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_12__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_12__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_12__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_12__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_12__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_13
#define US_ALU_RGB_ADDR_13__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_13__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_13__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_13__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_13__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_13__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_13__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_14
#define US_ALU_RGB_ADDR_14__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_14__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_14__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_14__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_14__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_14__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_14__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_15
#define US_ALU_RGB_ADDR_15__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_15__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_15__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_15__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_15__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_15__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_15__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_16
#define US_ALU_RGB_ADDR_16__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_16__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_16__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_16__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_16__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_16__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_16__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_17
#define US_ALU_RGB_ADDR_17__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_17__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_17__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_17__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_17__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_17__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_17__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_18
#define US_ALU_RGB_ADDR_18__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_18__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_18__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_18__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_18__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_18__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_18__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_19
#define US_ALU_RGB_ADDR_19__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_19__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_19__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_19__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_19__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_19__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_19__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_20
#define US_ALU_RGB_ADDR_20__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_20__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_20__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_20__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_20__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_20__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_20__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_21
#define US_ALU_RGB_ADDR_21__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_21__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_21__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_21__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_21__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_21__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_21__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_22
#define US_ALU_RGB_ADDR_22__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_22__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_22__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_22__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_22__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_22__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_22__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_23
#define US_ALU_RGB_ADDR_23__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_23__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_23__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_23__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_23__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_23__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_23__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_24
#define US_ALU_RGB_ADDR_24__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_24__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_24__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_24__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_24__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_24__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_24__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_25
#define US_ALU_RGB_ADDR_25__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_25__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_25__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_25__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_25__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_25__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_25__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_26
#define US_ALU_RGB_ADDR_26__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_26__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_26__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_26__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_26__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_26__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_26__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_27
#define US_ALU_RGB_ADDR_27__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_27__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_27__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_27__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_27__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_27__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_27__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_28
#define US_ALU_RGB_ADDR_28__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_28__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_28__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_28__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_28__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_28__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_28__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_29
#define US_ALU_RGB_ADDR_29__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_29__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_29__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_29__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_29__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_29__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_29__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_30
#define US_ALU_RGB_ADDR_30__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_30__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_30__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_30__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_30__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_30__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_30__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_31
#define US_ALU_RGB_ADDR_31__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_31__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_31__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_31__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_31__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_31__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_31__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_32
#define US_ALU_RGB_ADDR_32__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_32__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_32__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_32__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_32__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_32__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_32__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_33
#define US_ALU_RGB_ADDR_33__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_33__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_33__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_33__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_33__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_33__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_33__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_34
#define US_ALU_RGB_ADDR_34__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_34__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_34__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_34__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_34__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_34__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_34__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_35
#define US_ALU_RGB_ADDR_35__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_35__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_35__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_35__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_35__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_35__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_35__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_36
#define US_ALU_RGB_ADDR_36__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_36__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_36__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_36__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_36__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_36__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_36__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_37
#define US_ALU_RGB_ADDR_37__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_37__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_37__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_37__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_37__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_37__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_37__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_38
#define US_ALU_RGB_ADDR_38__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_38__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_38__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_38__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_38__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_38__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_38__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_39
#define US_ALU_RGB_ADDR_39__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_39__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_39__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_39__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_39__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_39__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_39__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_40
#define US_ALU_RGB_ADDR_40__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_40__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_40__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_40__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_40__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_40__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_40__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_41
#define US_ALU_RGB_ADDR_41__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_41__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_41__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_41__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_41__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_41__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_41__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_42
#define US_ALU_RGB_ADDR_42__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_42__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_42__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_42__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_42__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_42__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_42__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_43
#define US_ALU_RGB_ADDR_43__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_43__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_43__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_43__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_43__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_43__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_43__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_44
#define US_ALU_RGB_ADDR_44__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_44__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_44__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_44__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_44__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_44__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_44__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_45
#define US_ALU_RGB_ADDR_45__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_45__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_45__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_45__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_45__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_45__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_45__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_46
#define US_ALU_RGB_ADDR_46__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_46__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_46__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_46__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_46__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_46__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_46__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_47
#define US_ALU_RGB_ADDR_47__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_47__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_47__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_47__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_47__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_47__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_47__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_48
#define US_ALU_RGB_ADDR_48__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_48__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_48__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_48__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_48__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_48__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_48__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_49
#define US_ALU_RGB_ADDR_49__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_49__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_49__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_49__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_49__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_49__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_49__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_50
#define US_ALU_RGB_ADDR_50__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_50__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_50__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_50__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_50__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_50__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_50__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_51
#define US_ALU_RGB_ADDR_51__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_51__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_51__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_51__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_51__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_51__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_51__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_52
#define US_ALU_RGB_ADDR_52__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_52__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_52__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_52__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_52__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_52__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_52__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_53
#define US_ALU_RGB_ADDR_53__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_53__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_53__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_53__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_53__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_53__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_53__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_54
#define US_ALU_RGB_ADDR_54__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_54__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_54__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_54__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_54__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_54__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_54__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_55
#define US_ALU_RGB_ADDR_55__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_55__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_55__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_55__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_55__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_55__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_55__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_56
#define US_ALU_RGB_ADDR_56__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_56__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_56__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_56__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_56__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_56__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_56__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_57
#define US_ALU_RGB_ADDR_57__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_57__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_57__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_57__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_57__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_57__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_57__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_58
#define US_ALU_RGB_ADDR_58__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_58__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_58__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_58__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_58__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_58__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_58__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_59
#define US_ALU_RGB_ADDR_59__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_59__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_59__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_59__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_59__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_59__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_59__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_60
#define US_ALU_RGB_ADDR_60__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_60__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_60__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_60__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_60__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_60__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_60__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_61
#define US_ALU_RGB_ADDR_61__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_61__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_61__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_61__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_61__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_61__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_61__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_62
#define US_ALU_RGB_ADDR_62__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_62__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_62__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_62__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_62__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_62__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_62__TARGET_MASK                    0x60000000L

// US_ALU_RGB_ADDR_63
#define US_ALU_RGB_ADDR_63__ADDR0_MASK                     0x0000003fL
#define US_ALU_RGB_ADDR_63__ADDR1_MASK                     0x00000fc0L
#define US_ALU_RGB_ADDR_63__ADDR2_MASK                     0x0003f000L
#define US_ALU_RGB_ADDR_63__ADDRD_MASK                     0x007c0000L
#define US_ALU_RGB_ADDR_63__WMASK_MASK                     0x03800000L
#define US_ALU_RGB_ADDR_63__OMASK_MASK                     0x1c000000L
#define US_ALU_RGB_ADDR_63__TARGET_MASK                    0x60000000L

// US_ALU_ALPHA_ADDR_0
#define US_ALU_ALPHA_ADDR_0__ADDR0_MASK                    0x0000003fL
#define US_ALU_ALPHA_ADDR_0__ADDR1_MASK                    0x00000fc0L
#define US_ALU_ALPHA_ADDR_0__ADDR2_MASK                    0x0003f000L
#define US_ALU_ALPHA_ADDR_0__ADDRD_MASK                    0x007c0000L
#define US_ALU_ALPHA_ADDR_0__WMASK_MASK                    0x00800000L
#define US_ALU_ALPHA_ADDR_0__WMASK                         0x00800000L
#define US_ALU_ALPHA_ADDR_0__OMASK_MASK                    0x01000000L
#define US_ALU_ALPHA_ADDR_0__OMASK                         0x01000000L
#define US_ALU_ALPHA_ADDR_0__TARGET_MASK                   0x06000000L
#define US_ALU_ALPHA_ADDR_0__OMASK_W_MASK                  0x08000000L
#define US_ALU_ALPHA_ADDR_0__OMASK_W                       0x08000000L
#define US_ALU_ALPHA_ADDR_0__STAT_WE_MASK                  0xf0000000L

// US_ALU_ALPHA_ADDR_1
#define US_ALU_ALPHA_ADDR_1__ADDR0_MASK                    0x0000003fL
#define US_ALU_ALPHA_ADDR_1__ADDR1_MASK                    0x00000fc0L
#define US_ALU_ALPHA_ADDR_1__ADDR2_MASK                    0x0003f000L
#define US_ALU_ALPHA_ADDR_1__ADDRD_MASK                    0x007c0000L
#define US_ALU_ALPHA_ADDR_1__WMASK_MASK                    0x00800000L
#define US_ALU_ALPHA_ADDR_1__WMASK                         0x00800000L
#define US_ALU_ALPHA_ADDR_1__OMASK_MASK                    0x01000000L
#define US_ALU_ALPHA_ADDR_1__OMASK                         0x01000000L
#define US_ALU_ALPHA_ADDR_1__TARGET_MASK                   0x06000000L
#define US_ALU_ALPHA_ADDR_1__OMASK_W_MASK                  0x08000000L
#define US_ALU_ALPHA_ADDR_1__OMASK_W                       0x08000000L
#define US_ALU_ALPHA_ADDR_1__STAT_WE_MASK                  0xf0000000L

// US_ALU_ALPHA_ADDR_2
#define US_ALU_ALPHA_ADDR_2__ADDR0_MASK                    0x0000003fL
#define US_ALU_ALPHA_ADDR_2__ADDR1_MASK                    0x00000fc0L
#define US_ALU_ALPHA_ADDR_2__ADDR2_MASK                    0x0003f000L
#define US_ALU_ALPHA_ADDR_2__ADDRD_MASK                    0x007c0000L
#define US_ALU_ALPHA_ADDR_2__WMASK_MASK                    0x00800000L
#define US_ALU_ALPHA_ADDR_2__WMASK                         0x00800000L
#define US_ALU_ALPHA_ADDR_2__OMASK_MASK                    0x01000000L
#define US_ALU_ALPHA_ADDR_2__OMASK                         0x01000000L
#define US_ALU_ALPHA_ADDR_2__TARGET_MASK                   0x06000000L
#define US_ALU_ALPHA_ADDR_2__OMASK_W_MASK                  0x08000000L
#define US_ALU_ALPHA_ADDR_2__OMASK_W                       0x08000000L
#define US_ALU_ALPHA_ADDR_2__STAT_WE_MASK                  0xf0000000L

// US_ALU_ALPHA_ADDR_3
#define US_ALU_ALPHA_ADDR_3__ADDR0_MASK                    0x0000003fL
#define US_ALU_ALPHA_ADDR_3__ADDR1_MASK                    0x00000fc0L
#define US_ALU_ALPHA_ADDR_3__ADDR2_MASK                    0x0003f000L
#define US_ALU_ALPHA_ADDR_3__ADDRD_MASK                    0x007c0000L
#define US_ALU_ALPHA_ADDR_3__WMASK_MASK                    0x00800000L
#define US_ALU_ALPHA_ADDR_3__WMASK                         0x00800000L
#define US_ALU_ALPHA_ADDR_3__OMASK_MASK                    0x01000000L
#define US_ALU_ALPHA_ADDR_3__OMASK                         0x01000000L
#define US_ALU_ALPHA_ADDR_3__TARGET_MASK                   0x06000000L
#define US_ALU_ALPHA_ADDR_3__OMASK_W_MASK                  0x08000000L
#define US_ALU_ALPHA_ADDR_3__OMASK_W                       0x08000000L
#define US_ALU_ALPHA_ADDR_3__STAT_WE_MASK                  0xf0000000L

// US_ALU_ALPHA_ADDR_4
#define US_ALU_ALPHA_ADDR_4__ADDR0_MASK                    0x0000003fL
#define US_ALU_ALPHA_ADDR_4__ADDR1_MASK                    0x00000fc0L
#define US_ALU_ALPHA_ADDR_4__ADDR2_MASK                    0x0003f000L
#define US_ALU_ALPHA_ADDR_4__ADDRD_MASK                    0x007c0000L
#define US_ALU_ALPHA_ADDR_4__WMASK_MASK                    0x00800000L
#define US_ALU_ALPHA_ADDR_4__WMASK                         0x00800000L
#define US_ALU_ALPHA_ADDR_4__OMASK_MASK                    0x01000000L
#define US_ALU_ALPHA_ADDR_4__OMASK                         0x01000000L
#define US_ALU_ALPHA_ADDR_4__TARGET_MASK                   0x06000000L
#define US_ALU_ALPHA_ADDR_4__OMASK_W_MASK                  0x08000000L
#define US_ALU_ALPHA_ADDR_4__OMASK_W                       0x08000000L
#define US_ALU_ALPHA_ADDR_4__STAT_WE_MASK                  0xf0000000L

// US_ALU_ALPHA_ADDR_5
#define US_ALU_ALPHA_ADDR_5__ADDR0_MASK                    0x0000003fL
#define US_ALU_ALPHA_ADDR_5__ADDR1_MASK                    0x00000fc0L
#define US_ALU_ALPHA_ADDR_5__ADDR2_MASK                    0x0003f000L
#define US_ALU_ALPHA_ADDR_5__ADDRD_MASK                    0x007c0000L
#define US_ALU_ALPHA_ADDR_5__WMASK_MASK                    0x00800000L
#define US_ALU_ALPHA_ADDR_5__WMASK                         0x00800000L
#define US_ALU_ALPHA_ADDR_5__OMASK_MASK                    0x01000000L
#define US_ALU_ALPHA_ADDR_5__OMASK                         0x01000000L
#define US_ALU_ALPHA_ADDR_5__TARGET_MASK                   0x06000000L
#define US_ALU_ALPHA_ADDR_5__OMASK_W_MASK                  0x08000000L
#define US_ALU_ALPHA_ADDR_5__OMASK_W                       0x08000000L
#define US_ALU_ALPHA_ADDR_5__STAT_WE_MASK                  0xf0000000L

// US_ALU_ALPHA_ADDR_6
#define US_ALU_ALPHA_ADDR_6__ADDR0_MASK                    0x0000003fL
#define US_ALU_ALPHA_ADDR_6__ADDR1_MASK                    0x00000fc0L
#define US_ALU_ALPHA_ADDR_6__ADDR2_MASK                    0x0003f000L
#define US_ALU_ALPHA_ADDR_6__ADDRD_MASK                    0x007c0000L
#define US_ALU_ALPHA_ADDR_6__WMASK_MASK                    0x00800000L
#define US_ALU_ALPHA_ADDR_6__WMASK                         0x00800000L
#define US_ALU_ALPHA_ADDR_6__OMASK_MASK                    0x01000000L
#define US_ALU_ALPHA_ADDR_6__OMASK                         0x01000000L
#define US_ALU_ALPHA_ADDR_6__TARGET_MASK                   0x06000000L
#define US_ALU_ALPHA_ADDR_6__OMASK_W_MASK                  0x08000000L
#define US_ALU_ALPHA_ADDR_6__OMASK_W                       0x08000000L
#define US_ALU_ALPHA_ADDR_6__STAT_WE_MASK                  0xf0000000L

// US_ALU_ALPHA_ADDR_7
#define US_ALU_ALPHA_ADDR_7__ADDR0_MASK                    0x0000003fL
#define US_ALU_ALPHA_ADDR_7__ADDR1_MASK                    0x00000fc0L
#define US_ALU_ALPHA_ADDR_7__ADDR2_MASK                    0x0003f000L
#define US_ALU_ALPHA_ADDR_7__ADDRD_MASK                    0x007c0000L
#define US_ALU_ALPHA_ADDR_7__WMASK_MASK                    0x00800000L
#define US_ALU_ALPHA_ADDR_7__WMASK                         0x00800000L
#define US_ALU_ALPHA_ADDR_7__OMASK_MASK                    0x01000000L
#define US_ALU_ALPHA_ADDR_7__OMASK                         0x01000000L
#define US_ALU_ALPHA_ADDR_7__TARGET_MASK                   0x06000000L
#define US_ALU_ALPHA_ADDR_7__OMASK_W_MASK                  0x08000000L
#define US_ALU_ALPHA_ADDR_7__OMASK_W                       0x08000000L
#define US_ALU_ALPHA_ADDR_7__STAT_WE_MASK                  0xf0000000L

// US_ALU_ALPHA_ADDR_8
#define US_ALU_ALPHA_ADDR_8__ADDR0_MASK                    0x0000003fL
#define US_ALU_ALPHA_ADDR_8__ADDR1_MASK                    0x00000fc0L
#define US_ALU_ALPHA_ADDR_8__ADDR2_MASK                    0x0003f000L
#define US_ALU_ALPHA_ADDR_8__ADDRD_MASK                    0x007c0000L
#define US_ALU_ALPHA_ADDR_8__WMASK_MASK                    0x00800000L
#define US_ALU_ALPHA_ADDR_8__WMASK                         0x00800000L
#define US_ALU_ALPHA_ADDR_8__OMASK_MASK                    0x01000000L
#define US_ALU_ALPHA_ADDR_8__OMASK                         0x01000000L
#define US_ALU_ALPHA_ADDR_8__TARGET_MASK                   0x06000000L
#define US_ALU_ALPHA_ADDR_8__OMASK_W_MASK                  0x08000000L
#define US_ALU_ALPHA_ADDR_8__OMASK_W                       0x08000000L
#define US_ALU_ALPHA_ADDR_8__STAT_WE_MASK                  0xf0000000L

// US_ALU_ALPHA_ADDR_9
#define US_ALU_ALPHA_ADDR_9__ADDR0_MASK                    0x0000003fL
#define US_ALU_ALPHA_ADDR_9__ADDR1_MASK                    0x00000fc0L
#define US_ALU_ALPHA_ADDR_9__ADDR2_MASK                    0x0003f000L
#define US_ALU_ALPHA_ADDR_9__ADDRD_MASK                    0x007c0000L
#define US_ALU_ALPHA_ADDR_9__WMASK_MASK                    0x00800000L
#define US_ALU_ALPHA_ADDR_9__WMASK                         0x00800000L
#define US_ALU_ALPHA_ADDR_9__OMASK_MASK                    0x01000000L
#define US_ALU_ALPHA_ADDR_9__OMASK                         0x01000000L
#define US_ALU_ALPHA_ADDR_9__TARGET_MASK                   0x06000000L
#define US_ALU_ALPHA_ADDR_9__OMASK_W_MASK                  0x08000000L
#define US_ALU_ALPHA_ADDR_9__OMASK_W                       0x08000000L
#define US_ALU_ALPHA_ADDR_9__STAT_WE_MASK                  0xf0000000L

// US_ALU_ALPHA_ADDR_10
#define US_ALU_ALPHA_ADDR_10__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_10__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_10__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_10__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_10__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_10__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_10__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_10__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_10__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_10__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_10__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_10__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_11
#define US_ALU_ALPHA_ADDR_11__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_11__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_11__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_11__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_11__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_11__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_11__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_11__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_11__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_11__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_11__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_11__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_12
#define US_ALU_ALPHA_ADDR_12__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_12__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_12__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_12__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_12__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_12__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_12__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_12__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_12__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_12__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_12__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_12__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_13
#define US_ALU_ALPHA_ADDR_13__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_13__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_13__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_13__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_13__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_13__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_13__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_13__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_13__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_13__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_13__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_13__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_14
#define US_ALU_ALPHA_ADDR_14__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_14__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_14__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_14__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_14__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_14__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_14__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_14__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_14__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_14__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_14__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_14__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_15
#define US_ALU_ALPHA_ADDR_15__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_15__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_15__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_15__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_15__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_15__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_15__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_15__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_15__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_15__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_15__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_15__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_16
#define US_ALU_ALPHA_ADDR_16__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_16__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_16__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_16__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_16__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_16__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_16__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_16__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_16__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_16__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_16__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_16__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_17
#define US_ALU_ALPHA_ADDR_17__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_17__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_17__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_17__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_17__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_17__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_17__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_17__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_17__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_17__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_17__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_17__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_18
#define US_ALU_ALPHA_ADDR_18__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_18__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_18__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_18__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_18__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_18__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_18__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_18__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_18__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_18__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_18__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_18__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_19
#define US_ALU_ALPHA_ADDR_19__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_19__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_19__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_19__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_19__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_19__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_19__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_19__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_19__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_19__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_19__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_19__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_20
#define US_ALU_ALPHA_ADDR_20__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_20__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_20__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_20__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_20__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_20__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_20__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_20__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_20__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_20__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_20__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_20__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_21
#define US_ALU_ALPHA_ADDR_21__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_21__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_21__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_21__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_21__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_21__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_21__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_21__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_21__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_21__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_21__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_21__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_22
#define US_ALU_ALPHA_ADDR_22__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_22__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_22__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_22__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_22__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_22__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_22__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_22__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_22__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_22__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_22__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_22__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_23
#define US_ALU_ALPHA_ADDR_23__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_23__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_23__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_23__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_23__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_23__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_23__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_23__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_23__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_23__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_23__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_23__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_24
#define US_ALU_ALPHA_ADDR_24__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_24__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_24__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_24__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_24__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_24__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_24__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_24__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_24__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_24__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_24__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_24__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_25
#define US_ALU_ALPHA_ADDR_25__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_25__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_25__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_25__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_25__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_25__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_25__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_25__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_25__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_25__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_25__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_25__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_26
#define US_ALU_ALPHA_ADDR_26__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_26__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_26__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_26__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_26__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_26__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_26__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_26__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_26__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_26__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_26__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_26__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_27
#define US_ALU_ALPHA_ADDR_27__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_27__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_27__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_27__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_27__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_27__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_27__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_27__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_27__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_27__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_27__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_27__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_28
#define US_ALU_ALPHA_ADDR_28__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_28__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_28__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_28__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_28__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_28__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_28__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_28__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_28__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_28__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_28__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_28__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_29
#define US_ALU_ALPHA_ADDR_29__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_29__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_29__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_29__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_29__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_29__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_29__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_29__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_29__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_29__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_29__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_29__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_30
#define US_ALU_ALPHA_ADDR_30__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_30__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_30__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_30__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_30__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_30__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_30__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_30__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_30__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_30__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_30__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_30__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_31
#define US_ALU_ALPHA_ADDR_31__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_31__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_31__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_31__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_31__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_31__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_31__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_31__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_31__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_31__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_31__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_31__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_32
#define US_ALU_ALPHA_ADDR_32__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_32__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_32__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_32__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_32__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_32__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_32__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_32__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_32__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_32__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_32__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_32__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_33
#define US_ALU_ALPHA_ADDR_33__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_33__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_33__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_33__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_33__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_33__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_33__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_33__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_33__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_33__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_33__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_33__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_34
#define US_ALU_ALPHA_ADDR_34__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_34__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_34__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_34__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_34__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_34__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_34__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_34__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_34__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_34__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_34__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_34__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_35
#define US_ALU_ALPHA_ADDR_35__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_35__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_35__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_35__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_35__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_35__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_35__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_35__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_35__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_35__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_35__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_35__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_36
#define US_ALU_ALPHA_ADDR_36__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_36__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_36__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_36__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_36__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_36__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_36__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_36__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_36__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_36__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_36__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_36__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_37
#define US_ALU_ALPHA_ADDR_37__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_37__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_37__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_37__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_37__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_37__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_37__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_37__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_37__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_37__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_37__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_37__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_38
#define US_ALU_ALPHA_ADDR_38__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_38__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_38__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_38__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_38__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_38__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_38__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_38__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_38__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_38__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_38__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_38__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_39
#define US_ALU_ALPHA_ADDR_39__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_39__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_39__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_39__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_39__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_39__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_39__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_39__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_39__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_39__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_39__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_39__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_40
#define US_ALU_ALPHA_ADDR_40__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_40__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_40__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_40__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_40__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_40__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_40__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_40__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_40__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_40__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_40__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_40__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_41
#define US_ALU_ALPHA_ADDR_41__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_41__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_41__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_41__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_41__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_41__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_41__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_41__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_41__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_41__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_41__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_41__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_42
#define US_ALU_ALPHA_ADDR_42__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_42__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_42__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_42__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_42__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_42__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_42__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_42__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_42__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_42__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_42__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_42__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_43
#define US_ALU_ALPHA_ADDR_43__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_43__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_43__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_43__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_43__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_43__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_43__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_43__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_43__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_43__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_43__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_43__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_44
#define US_ALU_ALPHA_ADDR_44__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_44__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_44__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_44__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_44__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_44__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_44__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_44__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_44__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_44__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_44__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_44__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_45
#define US_ALU_ALPHA_ADDR_45__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_45__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_45__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_45__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_45__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_45__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_45__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_45__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_45__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_45__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_45__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_45__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_46
#define US_ALU_ALPHA_ADDR_46__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_46__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_46__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_46__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_46__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_46__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_46__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_46__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_46__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_46__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_46__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_46__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_47
#define US_ALU_ALPHA_ADDR_47__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_47__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_47__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_47__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_47__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_47__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_47__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_47__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_47__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_47__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_47__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_47__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_48
#define US_ALU_ALPHA_ADDR_48__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_48__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_48__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_48__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_48__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_48__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_48__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_48__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_48__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_48__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_48__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_48__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_49
#define US_ALU_ALPHA_ADDR_49__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_49__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_49__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_49__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_49__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_49__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_49__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_49__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_49__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_49__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_49__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_49__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_50
#define US_ALU_ALPHA_ADDR_50__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_50__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_50__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_50__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_50__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_50__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_50__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_50__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_50__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_50__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_50__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_50__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_51
#define US_ALU_ALPHA_ADDR_51__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_51__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_51__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_51__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_51__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_51__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_51__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_51__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_51__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_51__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_51__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_51__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_52
#define US_ALU_ALPHA_ADDR_52__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_52__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_52__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_52__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_52__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_52__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_52__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_52__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_52__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_52__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_52__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_52__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_53
#define US_ALU_ALPHA_ADDR_53__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_53__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_53__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_53__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_53__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_53__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_53__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_53__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_53__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_53__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_53__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_53__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_54
#define US_ALU_ALPHA_ADDR_54__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_54__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_54__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_54__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_54__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_54__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_54__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_54__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_54__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_54__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_54__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_54__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_55
#define US_ALU_ALPHA_ADDR_55__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_55__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_55__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_55__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_55__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_55__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_55__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_55__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_55__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_55__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_55__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_55__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_56
#define US_ALU_ALPHA_ADDR_56__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_56__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_56__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_56__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_56__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_56__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_56__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_56__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_56__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_56__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_56__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_56__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_57
#define US_ALU_ALPHA_ADDR_57__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_57__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_57__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_57__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_57__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_57__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_57__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_57__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_57__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_57__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_57__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_57__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_58
#define US_ALU_ALPHA_ADDR_58__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_58__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_58__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_58__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_58__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_58__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_58__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_58__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_58__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_58__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_58__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_58__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_59
#define US_ALU_ALPHA_ADDR_59__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_59__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_59__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_59__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_59__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_59__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_59__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_59__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_59__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_59__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_59__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_59__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_60
#define US_ALU_ALPHA_ADDR_60__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_60__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_60__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_60__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_60__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_60__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_60__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_60__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_60__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_60__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_60__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_60__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_61
#define US_ALU_ALPHA_ADDR_61__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_61__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_61__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_61__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_61__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_61__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_61__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_61__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_61__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_61__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_61__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_61__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_62
#define US_ALU_ALPHA_ADDR_62__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_62__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_62__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_62__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_62__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_62__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_62__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_62__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_62__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_62__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_62__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_62__STAT_WE_MASK                 0xf0000000L

// US_ALU_ALPHA_ADDR_63
#define US_ALU_ALPHA_ADDR_63__ADDR0_MASK                   0x0000003fL
#define US_ALU_ALPHA_ADDR_63__ADDR1_MASK                   0x00000fc0L
#define US_ALU_ALPHA_ADDR_63__ADDR2_MASK                   0x0003f000L
#define US_ALU_ALPHA_ADDR_63__ADDRD_MASK                   0x007c0000L
#define US_ALU_ALPHA_ADDR_63__WMASK_MASK                   0x00800000L
#define US_ALU_ALPHA_ADDR_63__WMASK                        0x00800000L
#define US_ALU_ALPHA_ADDR_63__OMASK_MASK                   0x01000000L
#define US_ALU_ALPHA_ADDR_63__OMASK                        0x01000000L
#define US_ALU_ALPHA_ADDR_63__TARGET_MASK                  0x06000000L
#define US_ALU_ALPHA_ADDR_63__OMASK_W_MASK                 0x08000000L
#define US_ALU_ALPHA_ADDR_63__OMASK_W                      0x08000000L
#define US_ALU_ALPHA_ADDR_63__STAT_WE_MASK                 0xf0000000L

// US_ALU_RGB_INST_0
#define US_ALU_RGB_INST_0__SEL_A_MASK                      0x0000001fL
#define US_ALU_RGB_INST_0__MOD_A_MASK                      0x00000060L
#define US_ALU_RGB_INST_0__SEL_B_MASK                      0x00000f80L
#define US_ALU_RGB_INST_0__MOD_B_MASK                      0x00003000L
#define US_ALU_RGB_INST_0__SEL_C_MASK                      0x0007c000L
#define US_ALU_RGB_INST_0__MOD_C_MASK                      0x00180000L
#define US_ALU_RGB_INST_0__SRCP_OP_MASK                    0x00600000L
#define US_ALU_RGB_INST_0__OP_MASK                         0x07800000L
#define US_ALU_RGB_INST_0__OMOD_MASK                       0x38000000L
#define US_ALU_RGB_INST_0__CLAMP_MASK                      0x40000000L
#define US_ALU_RGB_INST_0__CLAMP                           0x40000000L
#define US_ALU_RGB_INST_0__NOP_MASK                        0x80000000L
#define US_ALU_RGB_INST_0__NOP                             0x80000000L

// US_ALU_RGB_INST_1
#define US_ALU_RGB_INST_1__SEL_A_MASK                      0x0000001fL
#define US_ALU_RGB_INST_1__MOD_A_MASK                      0x00000060L
#define US_ALU_RGB_INST_1__SEL_B_MASK                      0x00000f80L
#define US_ALU_RGB_INST_1__MOD_B_MASK                      0x00003000L
#define US_ALU_RGB_INST_1__SEL_C_MASK                      0x0007c000L
#define US_ALU_RGB_INST_1__MOD_C_MASK                      0x00180000L
#define US_ALU_RGB_INST_1__SRCP_OP_MASK                    0x00600000L
#define US_ALU_RGB_INST_1__OP_MASK                         0x07800000L
#define US_ALU_RGB_INST_1__OMOD_MASK                       0x38000000L
#define US_ALU_RGB_INST_1__CLAMP_MASK                      0x40000000L
#define US_ALU_RGB_INST_1__CLAMP                           0x40000000L
#define US_ALU_RGB_INST_1__NOP_MASK                        0x80000000L
#define US_ALU_RGB_INST_1__NOP                             0x80000000L

// US_ALU_RGB_INST_2
#define US_ALU_RGB_INST_2__SEL_A_MASK                      0x0000001fL
#define US_ALU_RGB_INST_2__MOD_A_MASK                      0x00000060L
#define US_ALU_RGB_INST_2__SEL_B_MASK                      0x00000f80L
#define US_ALU_RGB_INST_2__MOD_B_MASK                      0x00003000L
#define US_ALU_RGB_INST_2__SEL_C_MASK                      0x0007c000L
#define US_ALU_RGB_INST_2__MOD_C_MASK                      0x00180000L
#define US_ALU_RGB_INST_2__SRCP_OP_MASK                    0x00600000L
#define US_ALU_RGB_INST_2__OP_MASK                         0x07800000L
#define US_ALU_RGB_INST_2__OMOD_MASK                       0x38000000L
#define US_ALU_RGB_INST_2__CLAMP_MASK                      0x40000000L
#define US_ALU_RGB_INST_2__CLAMP                           0x40000000L
#define US_ALU_RGB_INST_2__NOP_MASK                        0x80000000L
#define US_ALU_RGB_INST_2__NOP                             0x80000000L

// US_ALU_RGB_INST_3
#define US_ALU_RGB_INST_3__SEL_A_MASK                      0x0000001fL
#define US_ALU_RGB_INST_3__MOD_A_MASK                      0x00000060L
#define US_ALU_RGB_INST_3__SEL_B_MASK                      0x00000f80L
#define US_ALU_RGB_INST_3__MOD_B_MASK                      0x00003000L
#define US_ALU_RGB_INST_3__SEL_C_MASK                      0x0007c000L
#define US_ALU_RGB_INST_3__MOD_C_MASK                      0x00180000L
#define US_ALU_RGB_INST_3__SRCP_OP_MASK                    0x00600000L
#define US_ALU_RGB_INST_3__OP_MASK                         0x07800000L
#define US_ALU_RGB_INST_3__OMOD_MASK                       0x38000000L
#define US_ALU_RGB_INST_3__CLAMP_MASK                      0x40000000L
#define US_ALU_RGB_INST_3__CLAMP                           0x40000000L
#define US_ALU_RGB_INST_3__NOP_MASK                        0x80000000L
#define US_ALU_RGB_INST_3__NOP                             0x80000000L

// US_ALU_RGB_INST_4
#define US_ALU_RGB_INST_4__SEL_A_MASK                      0x0000001fL
#define US_ALU_RGB_INST_4__MOD_A_MASK                      0x00000060L
#define US_ALU_RGB_INST_4__SEL_B_MASK                      0x00000f80L
#define US_ALU_RGB_INST_4__MOD_B_MASK                      0x00003000L
#define US_ALU_RGB_INST_4__SEL_C_MASK                      0x0007c000L
#define US_ALU_RGB_INST_4__MOD_C_MASK                      0x00180000L
#define US_ALU_RGB_INST_4__SRCP_OP_MASK                    0x00600000L
#define US_ALU_RGB_INST_4__OP_MASK                         0x07800000L
#define US_ALU_RGB_INST_4__OMOD_MASK                       0x38000000L
#define US_ALU_RGB_INST_4__CLAMP_MASK                      0x40000000L
#define US_ALU_RGB_INST_4__CLAMP                           0x40000000L
#define US_ALU_RGB_INST_4__NOP_MASK                        0x80000000L
#define US_ALU_RGB_INST_4__NOP                             0x80000000L

// US_ALU_RGB_INST_5
#define US_ALU_RGB_INST_5__SEL_A_MASK                      0x0000001fL
#define US_ALU_RGB_INST_5__MOD_A_MASK                      0x00000060L
#define US_ALU_RGB_INST_5__SEL_B_MASK                      0x00000f80L
#define US_ALU_RGB_INST_5__MOD_B_MASK                      0x00003000L
#define US_ALU_RGB_INST_5__SEL_C_MASK                      0x0007c000L
#define US_ALU_RGB_INST_5__MOD_C_MASK                      0x00180000L
#define US_ALU_RGB_INST_5__SRCP_OP_MASK                    0x00600000L
#define US_ALU_RGB_INST_5__OP_MASK                         0x07800000L
#define US_ALU_RGB_INST_5__OMOD_MASK                       0x38000000L
#define US_ALU_RGB_INST_5__CLAMP_MASK                      0x40000000L
#define US_ALU_RGB_INST_5__CLAMP                           0x40000000L
#define US_ALU_RGB_INST_5__NOP_MASK                        0x80000000L
#define US_ALU_RGB_INST_5__NOP                             0x80000000L

// US_ALU_RGB_INST_6
#define US_ALU_RGB_INST_6__SEL_A_MASK                      0x0000001fL
#define US_ALU_RGB_INST_6__MOD_A_MASK                      0x00000060L
#define US_ALU_RGB_INST_6__SEL_B_MASK                      0x00000f80L
#define US_ALU_RGB_INST_6__MOD_B_MASK                      0x00003000L
#define US_ALU_RGB_INST_6__SEL_C_MASK                      0x0007c000L
#define US_ALU_RGB_INST_6__MOD_C_MASK                      0x00180000L
#define US_ALU_RGB_INST_6__SRCP_OP_MASK                    0x00600000L
#define US_ALU_RGB_INST_6__OP_MASK                         0x07800000L
#define US_ALU_RGB_INST_6__OMOD_MASK                       0x38000000L
#define US_ALU_RGB_INST_6__CLAMP_MASK                      0x40000000L
#define US_ALU_RGB_INST_6__CLAMP                           0x40000000L
#define US_ALU_RGB_INST_6__NOP_MASK                        0x80000000L
#define US_ALU_RGB_INST_6__NOP                             0x80000000L

// US_ALU_RGB_INST_7
#define US_ALU_RGB_INST_7__SEL_A_MASK                      0x0000001fL
#define US_ALU_RGB_INST_7__MOD_A_MASK                      0x00000060L
#define US_ALU_RGB_INST_7__SEL_B_MASK                      0x00000f80L
#define US_ALU_RGB_INST_7__MOD_B_MASK                      0x00003000L
#define US_ALU_RGB_INST_7__SEL_C_MASK                      0x0007c000L
#define US_ALU_RGB_INST_7__MOD_C_MASK                      0x00180000L
#define US_ALU_RGB_INST_7__SRCP_OP_MASK                    0x00600000L
#define US_ALU_RGB_INST_7__OP_MASK                         0x07800000L
#define US_ALU_RGB_INST_7__OMOD_MASK                       0x38000000L
#define US_ALU_RGB_INST_7__CLAMP_MASK                      0x40000000L
#define US_ALU_RGB_INST_7__CLAMP                           0x40000000L
#define US_ALU_RGB_INST_7__NOP_MASK                        0x80000000L
#define US_ALU_RGB_INST_7__NOP                             0x80000000L

// US_ALU_RGB_INST_8
#define US_ALU_RGB_INST_8__SEL_A_MASK                      0x0000001fL
#define US_ALU_RGB_INST_8__MOD_A_MASK                      0x00000060L
#define US_ALU_RGB_INST_8__SEL_B_MASK                      0x00000f80L
#define US_ALU_RGB_INST_8__MOD_B_MASK                      0x00003000L
#define US_ALU_RGB_INST_8__SEL_C_MASK                      0x0007c000L
#define US_ALU_RGB_INST_8__MOD_C_MASK                      0x00180000L
#define US_ALU_RGB_INST_8__SRCP_OP_MASK                    0x00600000L
#define US_ALU_RGB_INST_8__OP_MASK                         0x07800000L
#define US_ALU_RGB_INST_8__OMOD_MASK                       0x38000000L
#define US_ALU_RGB_INST_8__CLAMP_MASK                      0x40000000L
#define US_ALU_RGB_INST_8__CLAMP                           0x40000000L
#define US_ALU_RGB_INST_8__NOP_MASK                        0x80000000L
#define US_ALU_RGB_INST_8__NOP                             0x80000000L

// US_ALU_RGB_INST_9
#define US_ALU_RGB_INST_9__SEL_A_MASK                      0x0000001fL
#define US_ALU_RGB_INST_9__MOD_A_MASK                      0x00000060L
#define US_ALU_RGB_INST_9__SEL_B_MASK                      0x00000f80L
#define US_ALU_RGB_INST_9__MOD_B_MASK                      0x00003000L
#define US_ALU_RGB_INST_9__SEL_C_MASK                      0x0007c000L
#define US_ALU_RGB_INST_9__MOD_C_MASK                      0x00180000L
#define US_ALU_RGB_INST_9__SRCP_OP_MASK                    0x00600000L
#define US_ALU_RGB_INST_9__OP_MASK                         0x07800000L
#define US_ALU_RGB_INST_9__OMOD_MASK                       0x38000000L
#define US_ALU_RGB_INST_9__CLAMP_MASK                      0x40000000L
#define US_ALU_RGB_INST_9__CLAMP                           0x40000000L
#define US_ALU_RGB_INST_9__NOP_MASK                        0x80000000L
#define US_ALU_RGB_INST_9__NOP                             0x80000000L

// US_ALU_RGB_INST_10
#define US_ALU_RGB_INST_10__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_10__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_10__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_10__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_10__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_10__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_10__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_10__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_10__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_10__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_10__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_10__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_10__NOP                            0x80000000L

// US_ALU_RGB_INST_11
#define US_ALU_RGB_INST_11__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_11__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_11__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_11__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_11__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_11__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_11__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_11__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_11__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_11__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_11__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_11__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_11__NOP                            0x80000000L

// US_ALU_RGB_INST_12
#define US_ALU_RGB_INST_12__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_12__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_12__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_12__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_12__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_12__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_12__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_12__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_12__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_12__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_12__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_12__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_12__NOP                            0x80000000L

// US_ALU_RGB_INST_13
#define US_ALU_RGB_INST_13__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_13__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_13__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_13__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_13__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_13__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_13__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_13__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_13__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_13__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_13__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_13__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_13__NOP                            0x80000000L

// US_ALU_RGB_INST_14
#define US_ALU_RGB_INST_14__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_14__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_14__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_14__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_14__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_14__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_14__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_14__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_14__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_14__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_14__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_14__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_14__NOP                            0x80000000L

// US_ALU_RGB_INST_15
#define US_ALU_RGB_INST_15__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_15__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_15__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_15__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_15__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_15__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_15__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_15__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_15__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_15__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_15__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_15__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_15__NOP                            0x80000000L

// US_ALU_RGB_INST_16
#define US_ALU_RGB_INST_16__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_16__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_16__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_16__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_16__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_16__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_16__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_16__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_16__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_16__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_16__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_16__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_16__NOP                            0x80000000L

// US_ALU_RGB_INST_17
#define US_ALU_RGB_INST_17__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_17__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_17__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_17__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_17__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_17__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_17__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_17__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_17__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_17__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_17__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_17__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_17__NOP                            0x80000000L

// US_ALU_RGB_INST_18
#define US_ALU_RGB_INST_18__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_18__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_18__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_18__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_18__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_18__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_18__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_18__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_18__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_18__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_18__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_18__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_18__NOP                            0x80000000L

// US_ALU_RGB_INST_19
#define US_ALU_RGB_INST_19__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_19__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_19__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_19__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_19__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_19__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_19__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_19__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_19__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_19__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_19__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_19__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_19__NOP                            0x80000000L

// US_ALU_RGB_INST_20
#define US_ALU_RGB_INST_20__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_20__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_20__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_20__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_20__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_20__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_20__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_20__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_20__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_20__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_20__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_20__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_20__NOP                            0x80000000L

// US_ALU_RGB_INST_21
#define US_ALU_RGB_INST_21__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_21__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_21__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_21__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_21__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_21__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_21__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_21__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_21__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_21__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_21__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_21__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_21__NOP                            0x80000000L

// US_ALU_RGB_INST_22
#define US_ALU_RGB_INST_22__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_22__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_22__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_22__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_22__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_22__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_22__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_22__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_22__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_22__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_22__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_22__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_22__NOP                            0x80000000L

// US_ALU_RGB_INST_23
#define US_ALU_RGB_INST_23__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_23__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_23__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_23__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_23__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_23__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_23__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_23__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_23__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_23__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_23__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_23__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_23__NOP                            0x80000000L

// US_ALU_RGB_INST_24
#define US_ALU_RGB_INST_24__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_24__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_24__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_24__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_24__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_24__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_24__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_24__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_24__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_24__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_24__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_24__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_24__NOP                            0x80000000L

// US_ALU_RGB_INST_25
#define US_ALU_RGB_INST_25__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_25__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_25__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_25__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_25__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_25__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_25__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_25__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_25__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_25__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_25__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_25__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_25__NOP                            0x80000000L

// US_ALU_RGB_INST_26
#define US_ALU_RGB_INST_26__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_26__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_26__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_26__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_26__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_26__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_26__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_26__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_26__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_26__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_26__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_26__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_26__NOP                            0x80000000L

// US_ALU_RGB_INST_27
#define US_ALU_RGB_INST_27__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_27__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_27__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_27__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_27__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_27__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_27__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_27__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_27__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_27__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_27__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_27__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_27__NOP                            0x80000000L

// US_ALU_RGB_INST_28
#define US_ALU_RGB_INST_28__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_28__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_28__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_28__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_28__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_28__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_28__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_28__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_28__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_28__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_28__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_28__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_28__NOP                            0x80000000L

// US_ALU_RGB_INST_29
#define US_ALU_RGB_INST_29__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_29__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_29__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_29__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_29__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_29__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_29__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_29__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_29__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_29__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_29__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_29__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_29__NOP                            0x80000000L

// US_ALU_RGB_INST_30
#define US_ALU_RGB_INST_30__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_30__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_30__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_30__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_30__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_30__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_30__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_30__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_30__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_30__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_30__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_30__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_30__NOP                            0x80000000L

// US_ALU_RGB_INST_31
#define US_ALU_RGB_INST_31__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_31__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_31__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_31__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_31__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_31__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_31__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_31__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_31__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_31__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_31__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_31__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_31__NOP                            0x80000000L

// US_ALU_RGB_INST_32
#define US_ALU_RGB_INST_32__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_32__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_32__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_32__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_32__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_32__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_32__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_32__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_32__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_32__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_32__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_32__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_32__NOP                            0x80000000L

// US_ALU_RGB_INST_33
#define US_ALU_RGB_INST_33__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_33__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_33__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_33__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_33__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_33__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_33__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_33__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_33__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_33__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_33__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_33__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_33__NOP                            0x80000000L

// US_ALU_RGB_INST_34
#define US_ALU_RGB_INST_34__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_34__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_34__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_34__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_34__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_34__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_34__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_34__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_34__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_34__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_34__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_34__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_34__NOP                            0x80000000L

// US_ALU_RGB_INST_35
#define US_ALU_RGB_INST_35__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_35__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_35__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_35__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_35__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_35__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_35__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_35__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_35__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_35__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_35__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_35__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_35__NOP                            0x80000000L

// US_ALU_RGB_INST_36
#define US_ALU_RGB_INST_36__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_36__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_36__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_36__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_36__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_36__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_36__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_36__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_36__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_36__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_36__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_36__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_36__NOP                            0x80000000L

// US_ALU_RGB_INST_37
#define US_ALU_RGB_INST_37__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_37__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_37__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_37__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_37__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_37__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_37__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_37__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_37__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_37__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_37__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_37__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_37__NOP                            0x80000000L

// US_ALU_RGB_INST_38
#define US_ALU_RGB_INST_38__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_38__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_38__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_38__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_38__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_38__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_38__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_38__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_38__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_38__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_38__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_38__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_38__NOP                            0x80000000L

// US_ALU_RGB_INST_39
#define US_ALU_RGB_INST_39__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_39__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_39__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_39__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_39__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_39__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_39__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_39__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_39__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_39__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_39__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_39__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_39__NOP                            0x80000000L

// US_ALU_RGB_INST_40
#define US_ALU_RGB_INST_40__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_40__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_40__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_40__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_40__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_40__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_40__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_40__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_40__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_40__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_40__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_40__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_40__NOP                            0x80000000L

// US_ALU_RGB_INST_41
#define US_ALU_RGB_INST_41__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_41__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_41__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_41__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_41__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_41__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_41__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_41__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_41__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_41__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_41__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_41__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_41__NOP                            0x80000000L

// US_ALU_RGB_INST_42
#define US_ALU_RGB_INST_42__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_42__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_42__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_42__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_42__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_42__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_42__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_42__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_42__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_42__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_42__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_42__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_42__NOP                            0x80000000L

// US_ALU_RGB_INST_43
#define US_ALU_RGB_INST_43__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_43__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_43__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_43__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_43__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_43__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_43__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_43__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_43__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_43__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_43__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_43__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_43__NOP                            0x80000000L

// US_ALU_RGB_INST_44
#define US_ALU_RGB_INST_44__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_44__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_44__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_44__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_44__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_44__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_44__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_44__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_44__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_44__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_44__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_44__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_44__NOP                            0x80000000L

// US_ALU_RGB_INST_45
#define US_ALU_RGB_INST_45__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_45__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_45__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_45__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_45__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_45__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_45__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_45__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_45__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_45__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_45__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_45__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_45__NOP                            0x80000000L

// US_ALU_RGB_INST_46
#define US_ALU_RGB_INST_46__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_46__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_46__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_46__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_46__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_46__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_46__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_46__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_46__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_46__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_46__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_46__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_46__NOP                            0x80000000L

// US_ALU_RGB_INST_47
#define US_ALU_RGB_INST_47__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_47__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_47__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_47__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_47__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_47__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_47__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_47__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_47__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_47__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_47__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_47__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_47__NOP                            0x80000000L

// US_ALU_RGB_INST_48
#define US_ALU_RGB_INST_48__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_48__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_48__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_48__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_48__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_48__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_48__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_48__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_48__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_48__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_48__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_48__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_48__NOP                            0x80000000L

// US_ALU_RGB_INST_49
#define US_ALU_RGB_INST_49__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_49__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_49__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_49__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_49__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_49__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_49__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_49__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_49__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_49__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_49__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_49__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_49__NOP                            0x80000000L

// US_ALU_RGB_INST_50
#define US_ALU_RGB_INST_50__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_50__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_50__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_50__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_50__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_50__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_50__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_50__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_50__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_50__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_50__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_50__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_50__NOP                            0x80000000L

// US_ALU_RGB_INST_51
#define US_ALU_RGB_INST_51__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_51__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_51__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_51__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_51__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_51__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_51__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_51__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_51__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_51__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_51__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_51__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_51__NOP                            0x80000000L

// US_ALU_RGB_INST_52
#define US_ALU_RGB_INST_52__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_52__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_52__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_52__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_52__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_52__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_52__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_52__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_52__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_52__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_52__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_52__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_52__NOP                            0x80000000L

// US_ALU_RGB_INST_53
#define US_ALU_RGB_INST_53__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_53__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_53__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_53__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_53__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_53__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_53__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_53__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_53__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_53__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_53__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_53__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_53__NOP                            0x80000000L

// US_ALU_RGB_INST_54
#define US_ALU_RGB_INST_54__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_54__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_54__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_54__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_54__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_54__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_54__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_54__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_54__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_54__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_54__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_54__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_54__NOP                            0x80000000L

// US_ALU_RGB_INST_55
#define US_ALU_RGB_INST_55__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_55__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_55__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_55__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_55__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_55__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_55__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_55__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_55__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_55__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_55__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_55__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_55__NOP                            0x80000000L

// US_ALU_RGB_INST_56
#define US_ALU_RGB_INST_56__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_56__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_56__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_56__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_56__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_56__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_56__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_56__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_56__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_56__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_56__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_56__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_56__NOP                            0x80000000L

// US_ALU_RGB_INST_57
#define US_ALU_RGB_INST_57__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_57__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_57__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_57__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_57__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_57__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_57__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_57__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_57__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_57__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_57__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_57__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_57__NOP                            0x80000000L

// US_ALU_RGB_INST_58
#define US_ALU_RGB_INST_58__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_58__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_58__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_58__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_58__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_58__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_58__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_58__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_58__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_58__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_58__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_58__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_58__NOP                            0x80000000L

// US_ALU_RGB_INST_59
#define US_ALU_RGB_INST_59__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_59__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_59__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_59__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_59__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_59__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_59__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_59__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_59__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_59__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_59__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_59__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_59__NOP                            0x80000000L

// US_ALU_RGB_INST_60
#define US_ALU_RGB_INST_60__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_60__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_60__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_60__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_60__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_60__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_60__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_60__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_60__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_60__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_60__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_60__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_60__NOP                            0x80000000L

// US_ALU_RGB_INST_61
#define US_ALU_RGB_INST_61__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_61__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_61__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_61__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_61__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_61__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_61__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_61__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_61__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_61__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_61__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_61__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_61__NOP                            0x80000000L

// US_ALU_RGB_INST_62
#define US_ALU_RGB_INST_62__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_62__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_62__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_62__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_62__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_62__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_62__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_62__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_62__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_62__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_62__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_62__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_62__NOP                            0x80000000L

// US_ALU_RGB_INST_63
#define US_ALU_RGB_INST_63__SEL_A_MASK                     0x0000001fL
#define US_ALU_RGB_INST_63__MOD_A_MASK                     0x00000060L
#define US_ALU_RGB_INST_63__SEL_B_MASK                     0x00000f80L
#define US_ALU_RGB_INST_63__MOD_B_MASK                     0x00003000L
#define US_ALU_RGB_INST_63__SEL_C_MASK                     0x0007c000L
#define US_ALU_RGB_INST_63__MOD_C_MASK                     0x00180000L
#define US_ALU_RGB_INST_63__SRCP_OP_MASK                   0x00600000L
#define US_ALU_RGB_INST_63__OP_MASK                        0x07800000L
#define US_ALU_RGB_INST_63__OMOD_MASK                      0x38000000L
#define US_ALU_RGB_INST_63__CLAMP_MASK                     0x40000000L
#define US_ALU_RGB_INST_63__CLAMP                          0x40000000L
#define US_ALU_RGB_INST_63__NOP_MASK                       0x80000000L
#define US_ALU_RGB_INST_63__NOP                            0x80000000L

// US_ALU_ALPHA_INST_0
#define US_ALU_ALPHA_INST_0__SEL_A_MASK                    0x0000001fL
#define US_ALU_ALPHA_INST_0__MOD_A_MASK                    0x00000060L
#define US_ALU_ALPHA_INST_0__SEL_B_MASK                    0x00000f80L
#define US_ALU_ALPHA_INST_0__MOD_B_MASK                    0x00003000L
#define US_ALU_ALPHA_INST_0__SEL_C_MASK                    0x0007c000L
#define US_ALU_ALPHA_INST_0__MOD_C_MASK                    0x00180000L
#define US_ALU_ALPHA_INST_0__SRCP_OP_MASK                  0x00600000L
#define US_ALU_ALPHA_INST_0__OP_MASK                       0x07800000L
#define US_ALU_ALPHA_INST_0__OMOD_MASK                     0x38000000L
#define US_ALU_ALPHA_INST_0__CLAMP_MASK                    0x40000000L
#define US_ALU_ALPHA_INST_0__CLAMP                         0x40000000L

// US_ALU_ALPHA_INST_1
#define US_ALU_ALPHA_INST_1__SEL_A_MASK                    0x0000001fL
#define US_ALU_ALPHA_INST_1__MOD_A_MASK                    0x00000060L
#define US_ALU_ALPHA_INST_1__SEL_B_MASK                    0x00000f80L
#define US_ALU_ALPHA_INST_1__MOD_B_MASK                    0x00003000L
#define US_ALU_ALPHA_INST_1__SEL_C_MASK                    0x0007c000L
#define US_ALU_ALPHA_INST_1__MOD_C_MASK                    0x00180000L
#define US_ALU_ALPHA_INST_1__SRCP_OP_MASK                  0x00600000L
#define US_ALU_ALPHA_INST_1__OP_MASK                       0x07800000L
#define US_ALU_ALPHA_INST_1__OMOD_MASK                     0x38000000L
#define US_ALU_ALPHA_INST_1__CLAMP_MASK                    0x40000000L
#define US_ALU_ALPHA_INST_1__CLAMP                         0x40000000L

// US_ALU_ALPHA_INST_2
#define US_ALU_ALPHA_INST_2__SEL_A_MASK                    0x0000001fL
#define US_ALU_ALPHA_INST_2__MOD_A_MASK                    0x00000060L
#define US_ALU_ALPHA_INST_2__SEL_B_MASK                    0x00000f80L
#define US_ALU_ALPHA_INST_2__MOD_B_MASK                    0x00003000L
#define US_ALU_ALPHA_INST_2__SEL_C_MASK                    0x0007c000L
#define US_ALU_ALPHA_INST_2__MOD_C_MASK                    0x00180000L
#define US_ALU_ALPHA_INST_2__SRCP_OP_MASK                  0x00600000L
#define US_ALU_ALPHA_INST_2__OP_MASK                       0x07800000L
#define US_ALU_ALPHA_INST_2__OMOD_MASK                     0x38000000L
#define US_ALU_ALPHA_INST_2__CLAMP_MASK                    0x40000000L
#define US_ALU_ALPHA_INST_2__CLAMP                         0x40000000L

// US_ALU_ALPHA_INST_3
#define US_ALU_ALPHA_INST_3__SEL_A_MASK                    0x0000001fL
#define US_ALU_ALPHA_INST_3__MOD_A_MASK                    0x00000060L
#define US_ALU_ALPHA_INST_3__SEL_B_MASK                    0x00000f80L
#define US_ALU_ALPHA_INST_3__MOD_B_MASK                    0x00003000L
#define US_ALU_ALPHA_INST_3__SEL_C_MASK                    0x0007c000L
#define US_ALU_ALPHA_INST_3__MOD_C_MASK                    0x00180000L
#define US_ALU_ALPHA_INST_3__SRCP_OP_MASK                  0x00600000L
#define US_ALU_ALPHA_INST_3__OP_MASK                       0x07800000L
#define US_ALU_ALPHA_INST_3__OMOD_MASK                     0x38000000L
#define US_ALU_ALPHA_INST_3__CLAMP_MASK                    0x40000000L
#define US_ALU_ALPHA_INST_3__CLAMP                         0x40000000L

// US_ALU_ALPHA_INST_4
#define US_ALU_ALPHA_INST_4__SEL_A_MASK                    0x0000001fL
#define US_ALU_ALPHA_INST_4__MOD_A_MASK                    0x00000060L
#define US_ALU_ALPHA_INST_4__SEL_B_MASK                    0x00000f80L
#define US_ALU_ALPHA_INST_4__MOD_B_MASK                    0x00003000L
#define US_ALU_ALPHA_INST_4__SEL_C_MASK                    0x0007c000L
#define US_ALU_ALPHA_INST_4__MOD_C_MASK                    0x00180000L
#define US_ALU_ALPHA_INST_4__SRCP_OP_MASK                  0x00600000L
#define US_ALU_ALPHA_INST_4__OP_MASK                       0x07800000L
#define US_ALU_ALPHA_INST_4__OMOD_MASK                     0x38000000L
#define US_ALU_ALPHA_INST_4__CLAMP_MASK                    0x40000000L
#define US_ALU_ALPHA_INST_4__CLAMP                         0x40000000L

// US_ALU_ALPHA_INST_5
#define US_ALU_ALPHA_INST_5__SEL_A_MASK                    0x0000001fL
#define US_ALU_ALPHA_INST_5__MOD_A_MASK                    0x00000060L
#define US_ALU_ALPHA_INST_5__SEL_B_MASK                    0x00000f80L
#define US_ALU_ALPHA_INST_5__MOD_B_MASK                    0x00003000L
#define US_ALU_ALPHA_INST_5__SEL_C_MASK                    0x0007c000L
#define US_ALU_ALPHA_INST_5__MOD_C_MASK                    0x00180000L
#define US_ALU_ALPHA_INST_5__SRCP_OP_MASK                  0x00600000L
#define US_ALU_ALPHA_INST_5__OP_MASK                       0x07800000L
#define US_ALU_ALPHA_INST_5__OMOD_MASK                     0x38000000L
#define US_ALU_ALPHA_INST_5__CLAMP_MASK                    0x40000000L
#define US_ALU_ALPHA_INST_5__CLAMP                         0x40000000L

// US_ALU_ALPHA_INST_6
#define US_ALU_ALPHA_INST_6__SEL_A_MASK                    0x0000001fL
#define US_ALU_ALPHA_INST_6__MOD_A_MASK                    0x00000060L
#define US_ALU_ALPHA_INST_6__SEL_B_MASK                    0x00000f80L
#define US_ALU_ALPHA_INST_6__MOD_B_MASK                    0x00003000L
#define US_ALU_ALPHA_INST_6__SEL_C_MASK                    0x0007c000L
#define US_ALU_ALPHA_INST_6__MOD_C_MASK                    0x00180000L
#define US_ALU_ALPHA_INST_6__SRCP_OP_MASK                  0x00600000L
#define US_ALU_ALPHA_INST_6__OP_MASK                       0x07800000L
#define US_ALU_ALPHA_INST_6__OMOD_MASK                     0x38000000L
#define US_ALU_ALPHA_INST_6__CLAMP_MASK                    0x40000000L
#define US_ALU_ALPHA_INST_6__CLAMP                         0x40000000L

// US_ALU_ALPHA_INST_7
#define US_ALU_ALPHA_INST_7__SEL_A_MASK                    0x0000001fL
#define US_ALU_ALPHA_INST_7__MOD_A_MASK                    0x00000060L
#define US_ALU_ALPHA_INST_7__SEL_B_MASK                    0x00000f80L
#define US_ALU_ALPHA_INST_7__MOD_B_MASK                    0x00003000L
#define US_ALU_ALPHA_INST_7__SEL_C_MASK                    0x0007c000L
#define US_ALU_ALPHA_INST_7__MOD_C_MASK                    0x00180000L
#define US_ALU_ALPHA_INST_7__SRCP_OP_MASK                  0x00600000L
#define US_ALU_ALPHA_INST_7__OP_MASK                       0x07800000L
#define US_ALU_ALPHA_INST_7__OMOD_MASK                     0x38000000L
#define US_ALU_ALPHA_INST_7__CLAMP_MASK                    0x40000000L
#define US_ALU_ALPHA_INST_7__CLAMP                         0x40000000L

// US_ALU_ALPHA_INST_8
#define US_ALU_ALPHA_INST_8__SEL_A_MASK                    0x0000001fL
#define US_ALU_ALPHA_INST_8__MOD_A_MASK                    0x00000060L
#define US_ALU_ALPHA_INST_8__SEL_B_MASK                    0x00000f80L
#define US_ALU_ALPHA_INST_8__MOD_B_MASK                    0x00003000L
#define US_ALU_ALPHA_INST_8__SEL_C_MASK                    0x0007c000L
#define US_ALU_ALPHA_INST_8__MOD_C_MASK                    0x00180000L
#define US_ALU_ALPHA_INST_8__SRCP_OP_MASK                  0x00600000L
#define US_ALU_ALPHA_INST_8__OP_MASK                       0x07800000L
#define US_ALU_ALPHA_INST_8__OMOD_MASK                     0x38000000L
#define US_ALU_ALPHA_INST_8__CLAMP_MASK                    0x40000000L
#define US_ALU_ALPHA_INST_8__CLAMP                         0x40000000L

// US_ALU_ALPHA_INST_9
#define US_ALU_ALPHA_INST_9__SEL_A_MASK                    0x0000001fL
#define US_ALU_ALPHA_INST_9__MOD_A_MASK                    0x00000060L
#define US_ALU_ALPHA_INST_9__SEL_B_MASK                    0x00000f80L
#define US_ALU_ALPHA_INST_9__MOD_B_MASK                    0x00003000L
#define US_ALU_ALPHA_INST_9__SEL_C_MASK                    0x0007c000L
#define US_ALU_ALPHA_INST_9__MOD_C_MASK                    0x00180000L
#define US_ALU_ALPHA_INST_9__SRCP_OP_MASK                  0x00600000L
#define US_ALU_ALPHA_INST_9__OP_MASK                       0x07800000L
#define US_ALU_ALPHA_INST_9__OMOD_MASK                     0x38000000L
#define US_ALU_ALPHA_INST_9__CLAMP_MASK                    0x40000000L
#define US_ALU_ALPHA_INST_9__CLAMP                         0x40000000L

// US_ALU_ALPHA_INST_10
#define US_ALU_ALPHA_INST_10__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_10__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_10__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_10__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_10__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_10__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_10__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_10__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_10__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_10__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_10__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_11
#define US_ALU_ALPHA_INST_11__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_11__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_11__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_11__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_11__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_11__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_11__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_11__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_11__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_11__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_11__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_12
#define US_ALU_ALPHA_INST_12__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_12__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_12__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_12__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_12__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_12__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_12__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_12__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_12__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_12__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_12__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_13
#define US_ALU_ALPHA_INST_13__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_13__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_13__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_13__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_13__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_13__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_13__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_13__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_13__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_13__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_13__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_14
#define US_ALU_ALPHA_INST_14__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_14__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_14__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_14__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_14__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_14__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_14__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_14__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_14__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_14__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_14__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_15
#define US_ALU_ALPHA_INST_15__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_15__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_15__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_15__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_15__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_15__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_15__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_15__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_15__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_15__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_15__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_16
#define US_ALU_ALPHA_INST_16__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_16__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_16__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_16__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_16__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_16__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_16__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_16__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_16__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_16__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_16__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_17
#define US_ALU_ALPHA_INST_17__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_17__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_17__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_17__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_17__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_17__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_17__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_17__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_17__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_17__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_17__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_18
#define US_ALU_ALPHA_INST_18__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_18__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_18__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_18__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_18__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_18__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_18__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_18__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_18__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_18__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_18__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_19
#define US_ALU_ALPHA_INST_19__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_19__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_19__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_19__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_19__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_19__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_19__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_19__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_19__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_19__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_19__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_20
#define US_ALU_ALPHA_INST_20__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_20__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_20__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_20__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_20__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_20__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_20__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_20__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_20__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_20__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_20__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_21
#define US_ALU_ALPHA_INST_21__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_21__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_21__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_21__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_21__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_21__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_21__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_21__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_21__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_21__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_21__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_22
#define US_ALU_ALPHA_INST_22__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_22__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_22__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_22__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_22__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_22__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_22__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_22__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_22__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_22__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_22__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_23
#define US_ALU_ALPHA_INST_23__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_23__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_23__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_23__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_23__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_23__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_23__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_23__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_23__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_23__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_23__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_24
#define US_ALU_ALPHA_INST_24__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_24__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_24__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_24__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_24__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_24__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_24__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_24__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_24__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_24__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_24__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_25
#define US_ALU_ALPHA_INST_25__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_25__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_25__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_25__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_25__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_25__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_25__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_25__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_25__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_25__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_25__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_26
#define US_ALU_ALPHA_INST_26__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_26__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_26__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_26__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_26__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_26__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_26__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_26__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_26__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_26__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_26__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_27
#define US_ALU_ALPHA_INST_27__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_27__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_27__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_27__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_27__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_27__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_27__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_27__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_27__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_27__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_27__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_28
#define US_ALU_ALPHA_INST_28__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_28__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_28__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_28__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_28__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_28__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_28__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_28__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_28__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_28__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_28__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_29
#define US_ALU_ALPHA_INST_29__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_29__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_29__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_29__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_29__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_29__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_29__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_29__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_29__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_29__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_29__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_30
#define US_ALU_ALPHA_INST_30__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_30__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_30__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_30__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_30__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_30__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_30__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_30__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_30__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_30__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_30__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_31
#define US_ALU_ALPHA_INST_31__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_31__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_31__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_31__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_31__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_31__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_31__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_31__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_31__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_31__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_31__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_32
#define US_ALU_ALPHA_INST_32__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_32__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_32__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_32__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_32__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_32__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_32__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_32__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_32__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_32__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_32__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_33
#define US_ALU_ALPHA_INST_33__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_33__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_33__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_33__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_33__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_33__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_33__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_33__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_33__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_33__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_33__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_34
#define US_ALU_ALPHA_INST_34__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_34__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_34__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_34__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_34__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_34__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_34__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_34__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_34__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_34__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_34__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_35
#define US_ALU_ALPHA_INST_35__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_35__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_35__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_35__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_35__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_35__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_35__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_35__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_35__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_35__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_35__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_36
#define US_ALU_ALPHA_INST_36__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_36__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_36__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_36__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_36__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_36__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_36__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_36__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_36__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_36__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_36__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_37
#define US_ALU_ALPHA_INST_37__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_37__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_37__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_37__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_37__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_37__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_37__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_37__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_37__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_37__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_37__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_38
#define US_ALU_ALPHA_INST_38__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_38__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_38__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_38__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_38__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_38__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_38__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_38__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_38__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_38__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_38__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_39
#define US_ALU_ALPHA_INST_39__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_39__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_39__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_39__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_39__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_39__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_39__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_39__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_39__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_39__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_39__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_40
#define US_ALU_ALPHA_INST_40__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_40__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_40__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_40__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_40__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_40__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_40__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_40__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_40__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_40__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_40__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_41
#define US_ALU_ALPHA_INST_41__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_41__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_41__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_41__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_41__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_41__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_41__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_41__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_41__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_41__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_41__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_42
#define US_ALU_ALPHA_INST_42__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_42__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_42__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_42__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_42__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_42__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_42__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_42__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_42__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_42__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_42__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_43
#define US_ALU_ALPHA_INST_43__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_43__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_43__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_43__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_43__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_43__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_43__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_43__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_43__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_43__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_43__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_44
#define US_ALU_ALPHA_INST_44__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_44__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_44__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_44__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_44__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_44__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_44__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_44__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_44__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_44__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_44__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_45
#define US_ALU_ALPHA_INST_45__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_45__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_45__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_45__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_45__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_45__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_45__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_45__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_45__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_45__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_45__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_46
#define US_ALU_ALPHA_INST_46__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_46__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_46__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_46__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_46__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_46__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_46__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_46__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_46__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_46__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_46__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_47
#define US_ALU_ALPHA_INST_47__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_47__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_47__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_47__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_47__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_47__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_47__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_47__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_47__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_47__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_47__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_48
#define US_ALU_ALPHA_INST_48__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_48__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_48__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_48__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_48__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_48__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_48__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_48__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_48__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_48__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_48__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_49
#define US_ALU_ALPHA_INST_49__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_49__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_49__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_49__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_49__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_49__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_49__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_49__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_49__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_49__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_49__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_50
#define US_ALU_ALPHA_INST_50__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_50__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_50__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_50__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_50__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_50__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_50__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_50__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_50__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_50__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_50__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_51
#define US_ALU_ALPHA_INST_51__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_51__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_51__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_51__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_51__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_51__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_51__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_51__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_51__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_51__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_51__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_52
#define US_ALU_ALPHA_INST_52__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_52__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_52__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_52__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_52__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_52__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_52__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_52__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_52__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_52__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_52__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_53
#define US_ALU_ALPHA_INST_53__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_53__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_53__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_53__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_53__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_53__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_53__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_53__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_53__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_53__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_53__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_54
#define US_ALU_ALPHA_INST_54__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_54__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_54__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_54__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_54__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_54__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_54__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_54__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_54__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_54__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_54__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_55
#define US_ALU_ALPHA_INST_55__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_55__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_55__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_55__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_55__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_55__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_55__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_55__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_55__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_55__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_55__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_56
#define US_ALU_ALPHA_INST_56__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_56__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_56__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_56__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_56__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_56__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_56__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_56__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_56__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_56__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_56__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_57
#define US_ALU_ALPHA_INST_57__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_57__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_57__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_57__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_57__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_57__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_57__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_57__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_57__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_57__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_57__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_58
#define US_ALU_ALPHA_INST_58__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_58__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_58__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_58__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_58__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_58__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_58__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_58__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_58__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_58__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_58__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_59
#define US_ALU_ALPHA_INST_59__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_59__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_59__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_59__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_59__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_59__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_59__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_59__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_59__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_59__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_59__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_60
#define US_ALU_ALPHA_INST_60__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_60__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_60__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_60__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_60__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_60__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_60__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_60__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_60__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_60__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_60__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_61
#define US_ALU_ALPHA_INST_61__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_61__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_61__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_61__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_61__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_61__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_61__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_61__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_61__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_61__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_61__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_62
#define US_ALU_ALPHA_INST_62__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_62__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_62__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_62__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_62__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_62__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_62__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_62__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_62__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_62__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_62__CLAMP                        0x40000000L

// US_ALU_ALPHA_INST_63
#define US_ALU_ALPHA_INST_63__SEL_A_MASK                   0x0000001fL
#define US_ALU_ALPHA_INST_63__MOD_A_MASK                   0x00000060L
#define US_ALU_ALPHA_INST_63__SEL_B_MASK                   0x00000f80L
#define US_ALU_ALPHA_INST_63__MOD_B_MASK                   0x00003000L
#define US_ALU_ALPHA_INST_63__SEL_C_MASK                   0x0007c000L
#define US_ALU_ALPHA_INST_63__MOD_C_MASK                   0x00180000L
#define US_ALU_ALPHA_INST_63__SRCP_OP_MASK                 0x00600000L
#define US_ALU_ALPHA_INST_63__OP_MASK                      0x07800000L
#define US_ALU_ALPHA_INST_63__OMOD_MASK                    0x38000000L
#define US_ALU_ALPHA_INST_63__CLAMP_MASK                   0x40000000L
#define US_ALU_ALPHA_INST_63__CLAMP                        0x40000000L

// US_ALU_CONST_R_0
#define US_ALU_CONST_R_0__KR_MASK                          0x00ffffffL

// US_ALU_CONST_R_1
#define US_ALU_CONST_R_1__KR_MASK                          0x00ffffffL

// US_ALU_CONST_R_2
#define US_ALU_CONST_R_2__KR_MASK                          0x00ffffffL

// US_ALU_CONST_R_3
#define US_ALU_CONST_R_3__KR_MASK                          0x00ffffffL

// US_ALU_CONST_R_4
#define US_ALU_CONST_R_4__KR_MASK                          0x00ffffffL

// US_ALU_CONST_R_5
#define US_ALU_CONST_R_5__KR_MASK                          0x00ffffffL

// US_ALU_CONST_R_6
#define US_ALU_CONST_R_6__KR_MASK                          0x00ffffffL

// US_ALU_CONST_R_7
#define US_ALU_CONST_R_7__KR_MASK                          0x00ffffffL

// US_ALU_CONST_R_8
#define US_ALU_CONST_R_8__KR_MASK                          0x00ffffffL

// US_ALU_CONST_R_9
#define US_ALU_CONST_R_9__KR_MASK                          0x00ffffffL

// US_ALU_CONST_R_10
#define US_ALU_CONST_R_10__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_11
#define US_ALU_CONST_R_11__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_12
#define US_ALU_CONST_R_12__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_13
#define US_ALU_CONST_R_13__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_14
#define US_ALU_CONST_R_14__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_15
#define US_ALU_CONST_R_15__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_16
#define US_ALU_CONST_R_16__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_17
#define US_ALU_CONST_R_17__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_18
#define US_ALU_CONST_R_18__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_19
#define US_ALU_CONST_R_19__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_20
#define US_ALU_CONST_R_20__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_21
#define US_ALU_CONST_R_21__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_22
#define US_ALU_CONST_R_22__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_23
#define US_ALU_CONST_R_23__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_24
#define US_ALU_CONST_R_24__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_25
#define US_ALU_CONST_R_25__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_26
#define US_ALU_CONST_R_26__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_27
#define US_ALU_CONST_R_27__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_28
#define US_ALU_CONST_R_28__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_29
#define US_ALU_CONST_R_29__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_30
#define US_ALU_CONST_R_30__KR_MASK                         0x00ffffffL

// US_ALU_CONST_R_31
#define US_ALU_CONST_R_31__KR_MASK                         0x00ffffffL

// US_ALU_CONST_G_0
#define US_ALU_CONST_G_0__KG_MASK                          0x00ffffffL

// US_ALU_CONST_G_1
#define US_ALU_CONST_G_1__KG_MASK                          0x00ffffffL

// US_ALU_CONST_G_2
#define US_ALU_CONST_G_2__KG_MASK                          0x00ffffffL

// US_ALU_CONST_G_3
#define US_ALU_CONST_G_3__KG_MASK                          0x00ffffffL

// US_ALU_CONST_G_4
#define US_ALU_CONST_G_4__KG_MASK                          0x00ffffffL

// US_ALU_CONST_G_5
#define US_ALU_CONST_G_5__KG_MASK                          0x00ffffffL

// US_ALU_CONST_G_6
#define US_ALU_CONST_G_6__KG_MASK                          0x00ffffffL

// US_ALU_CONST_G_7
#define US_ALU_CONST_G_7__KG_MASK                          0x00ffffffL

// US_ALU_CONST_G_8
#define US_ALU_CONST_G_8__KG_MASK                          0x00ffffffL

// US_ALU_CONST_G_9
#define US_ALU_CONST_G_9__KG_MASK                          0x00ffffffL

// US_ALU_CONST_G_10
#define US_ALU_CONST_G_10__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_11
#define US_ALU_CONST_G_11__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_12
#define US_ALU_CONST_G_12__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_13
#define US_ALU_CONST_G_13__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_14
#define US_ALU_CONST_G_14__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_15
#define US_ALU_CONST_G_15__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_16
#define US_ALU_CONST_G_16__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_17
#define US_ALU_CONST_G_17__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_18
#define US_ALU_CONST_G_18__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_19
#define US_ALU_CONST_G_19__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_20
#define US_ALU_CONST_G_20__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_21
#define US_ALU_CONST_G_21__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_22
#define US_ALU_CONST_G_22__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_23
#define US_ALU_CONST_G_23__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_24
#define US_ALU_CONST_G_24__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_25
#define US_ALU_CONST_G_25__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_26
#define US_ALU_CONST_G_26__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_27
#define US_ALU_CONST_G_27__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_28
#define US_ALU_CONST_G_28__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_29
#define US_ALU_CONST_G_29__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_30
#define US_ALU_CONST_G_30__KG_MASK                         0x00ffffffL

// US_ALU_CONST_G_31
#define US_ALU_CONST_G_31__KG_MASK                         0x00ffffffL

// US_ALU_CONST_B_0
#define US_ALU_CONST_B_0__KB_MASK                          0x00ffffffL

// US_ALU_CONST_B_1
#define US_ALU_CONST_B_1__KB_MASK                          0x00ffffffL

// US_ALU_CONST_B_2
#define US_ALU_CONST_B_2__KB_MASK                          0x00ffffffL

// US_ALU_CONST_B_3
#define US_ALU_CONST_B_3__KB_MASK                          0x00ffffffL

// US_ALU_CONST_B_4
#define US_ALU_CONST_B_4__KB_MASK                          0x00ffffffL

// US_ALU_CONST_B_5
#define US_ALU_CONST_B_5__KB_MASK                          0x00ffffffL

// US_ALU_CONST_B_6
#define US_ALU_CONST_B_6__KB_MASK                          0x00ffffffL

// US_ALU_CONST_B_7
#define US_ALU_CONST_B_7__KB_MASK                          0x00ffffffL

// US_ALU_CONST_B_8
#define US_ALU_CONST_B_8__KB_MASK                          0x00ffffffL

// US_ALU_CONST_B_9
#define US_ALU_CONST_B_9__KB_MASK                          0x00ffffffL

// US_ALU_CONST_B_10
#define US_ALU_CONST_B_10__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_11
#define US_ALU_CONST_B_11__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_12
#define US_ALU_CONST_B_12__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_13
#define US_ALU_CONST_B_13__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_14
#define US_ALU_CONST_B_14__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_15
#define US_ALU_CONST_B_15__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_16
#define US_ALU_CONST_B_16__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_17
#define US_ALU_CONST_B_17__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_18
#define US_ALU_CONST_B_18__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_19
#define US_ALU_CONST_B_19__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_20
#define US_ALU_CONST_B_20__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_21
#define US_ALU_CONST_B_21__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_22
#define US_ALU_CONST_B_22__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_23
#define US_ALU_CONST_B_23__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_24
#define US_ALU_CONST_B_24__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_25
#define US_ALU_CONST_B_25__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_26
#define US_ALU_CONST_B_26__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_27
#define US_ALU_CONST_B_27__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_28
#define US_ALU_CONST_B_28__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_29
#define US_ALU_CONST_B_29__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_30
#define US_ALU_CONST_B_30__KB_MASK                         0x00ffffffL

// US_ALU_CONST_B_31
#define US_ALU_CONST_B_31__KB_MASK                         0x00ffffffL

// US_ALU_CONST_A_0
#define US_ALU_CONST_A_0__KA_MASK                          0x00ffffffL

// US_ALU_CONST_A_1
#define US_ALU_CONST_A_1__KA_MASK                          0x00ffffffL

// US_ALU_CONST_A_2
#define US_ALU_CONST_A_2__KA_MASK                          0x00ffffffL

// US_ALU_CONST_A_3
#define US_ALU_CONST_A_3__KA_MASK                          0x00ffffffL

// US_ALU_CONST_A_4
#define US_ALU_CONST_A_4__KA_MASK                          0x00ffffffL

// US_ALU_CONST_A_5
#define US_ALU_CONST_A_5__KA_MASK                          0x00ffffffL

// US_ALU_CONST_A_6
#define US_ALU_CONST_A_6__KA_MASK                          0x00ffffffL

// US_ALU_CONST_A_7
#define US_ALU_CONST_A_7__KA_MASK                          0x00ffffffL

// US_ALU_CONST_A_8
#define US_ALU_CONST_A_8__KA_MASK                          0x00ffffffL

// US_ALU_CONST_A_9
#define US_ALU_CONST_A_9__KA_MASK                          0x00ffffffL

// US_ALU_CONST_A_10
#define US_ALU_CONST_A_10__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_11
#define US_ALU_CONST_A_11__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_12
#define US_ALU_CONST_A_12__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_13
#define US_ALU_CONST_A_13__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_14
#define US_ALU_CONST_A_14__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_15
#define US_ALU_CONST_A_15__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_16
#define US_ALU_CONST_A_16__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_17
#define US_ALU_CONST_A_17__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_18
#define US_ALU_CONST_A_18__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_19
#define US_ALU_CONST_A_19__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_20
#define US_ALU_CONST_A_20__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_21
#define US_ALU_CONST_A_21__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_22
#define US_ALU_CONST_A_22__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_23
#define US_ALU_CONST_A_23__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_24
#define US_ALU_CONST_A_24__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_25
#define US_ALU_CONST_A_25__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_26
#define US_ALU_CONST_A_26__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_27
#define US_ALU_CONST_A_27__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_28
#define US_ALU_CONST_A_28__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_29
#define US_ALU_CONST_A_29__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_30
#define US_ALU_CONST_A_30__KA_MASK                         0x00ffffffL

// US_ALU_CONST_A_31
#define US_ALU_CONST_A_31__KA_MASK                         0x00ffffffL

// FG_FOG_BLEND
#define FG_FOG_BLEND__ENABLE_MASK                          0x00000001L
#define FG_FOG_BLEND__ENABLE                               0x00000001L
#define FG_FOG_BLEND__FN_MASK                              0x00000006L

// FG_FOG_FACTOR
#define FG_FOG_FACTOR__FACTOR_MASK                         0x000003ffL

// FG_FOG_COLOR_R
#define FG_FOG_COLOR_R__RED_MASK                           0x000003ffL

// FG_FOG_COLOR_G
#define FG_FOG_COLOR_G__GREEN_MASK                         0x000003ffL

// FG_FOG_COLOR_B
#define FG_FOG_COLOR_B__BLUE_MASK                          0x000003ffL

// FG_ALPHA_FUNC
#define FG_ALPHA_FUNC__AF_VAL_MASK                         0x000000ffL
#define FG_ALPHA_FUNC__AF_FUNC_MASK                        0x00000700L
#define FG_ALPHA_FUNC__AF_EN_MASK                          0x00000800L
#define FG_ALPHA_FUNC__AF_EN                               0x00000800L
#define FG_ALPHA_FUNC__AM_EN_MASK                          0x00010000L
#define FG_ALPHA_FUNC__AM_EN                               0x00010000L
#define FG_ALPHA_FUNC__AM_CFG_MASK                         0x00020000L
#define FG_ALPHA_FUNC__AM_CFG                              0x00020000L
#define FG_ALPHA_FUNC__DITH_EN_MASK                        0x00100000L
#define FG_ALPHA_FUNC__DITH_EN                             0x00100000L

// FG_DEPTH_SRC
#define FG_DEPTH_SRC__DEPTH_SRC_MASK                       0x00000001L
#define FG_DEPTH_SRC__DEPTH_SRC                            0x00000001L

// FG_PERF
#define FG_PERF__PERF0_MASK                                0x0000001fL
#define FG_PERF__PERF1_MASK                                0x000003e0L
#define FG_PERF__PERF2_MASK                                0x00007c00L
#define FG_PERF__PERF3_MASK                                0x000f8000L

// RB3D_CCTL
#define RB3D_CCTL__NUM_MULTIWRITES_MASK                    0x00000060L
#define RB3D_CCTL__CLRCMP_FLIPE_ENABLE_MASK                0x00000080L
#define RB3D_CCTL__CLRCMP_FLIPE_ENABLE                     0x00000080L
#define RB3D_CCTL__AA_COMPRESSION_ENABLE_MASK              0x00000200L
#define RB3D_CCTL__AA_COMPRESSION_ENABLE                   0x00000200L
#define RB3D_CCTL__CMASK_ENABLE_MASK                       0x00000400L
#define RB3D_CCTL__CMASK_ENABLE                            0x00000400L

// RB3D_BLENDCNTL_R3
#define RB3D_BLENDCNTL_R3__ALPHA_BLEND_ENABLE_MASK         0x00000001L
#define RB3D_BLENDCNTL_R3__ALPHA_BLEND_ENABLE              0x00000001L
#define RB3D_BLENDCNTL_R3__SEPARATE_ALPHA_ENABLE_MASK      0x00000002L
#define RB3D_BLENDCNTL_R3__SEPARATE_ALPHA_ENABLE           0x00000002L
#define RB3D_BLENDCNTL_R3__READ_ENABLE_MASK                0x00000004L
#define RB3D_BLENDCNTL_R3__READ_ENABLE                     0x00000004L
#define RB3D_BLENDCNTL_R3__DISCARD_SRC_PIXELS_MASK         0x00000038L
#define RB3D_BLENDCNTL_R3__COMB_FCN_MASK                   0x00007000L
#define RB3D_BLENDCNTL_R3__SRCBLEND_MASK                   0x003f0000L
#define RB3D_BLENDCNTL_R3__DESTBLEND_MASK                  0x3f000000L

// RB3D_ABLENDCNTL_R3
#define RB3D_ABLENDCNTL_R3__COMB_FCN_MASK                  0x00007000L
#define RB3D_ABLENDCNTL_R3__SRCBLEND_MASK                  0x003f0000L
#define RB3D_ABLENDCNTL_R3__DESTBLEND_MASK                 0x3f000000L

// RB3D_COLOR_CHANNEL_MASK
#define RB3D_COLOR_CHANNEL_MASK__BLUE_MASK_MASK            0x00000001L
#define RB3D_COLOR_CHANNEL_MASK__BLUE_MASK                 0x00000001L
#define RB3D_COLOR_CHANNEL_MASK__GREEN_MASK_MASK           0x00000002L
#define RB3D_COLOR_CHANNEL_MASK__GREEN_MASK                0x00000002L
#define RB3D_COLOR_CHANNEL_MASK__RED_MASK_MASK             0x00000004L
#define RB3D_COLOR_CHANNEL_MASK__RED_MASK                  0x00000004L
#define RB3D_COLOR_CHANNEL_MASK__ALPHA_MASK_MASK           0x00000008L
#define RB3D_COLOR_CHANNEL_MASK__ALPHA_MASK                0x00000008L

// RB3D_CONSTANT_COLOR
#define RB3D_CONSTANT_COLOR__BLUE_MASK                     0x000000ffL
#define RB3D_CONSTANT_COLOR__GREEN_MASK                    0x0000ff00L
#define RB3D_CONSTANT_COLOR__RED_MASK                      0x00ff0000L
#define RB3D_CONSTANT_COLOR__ALPHA_MASK                    0xff000000L

// RB3D_COLOR_CLEAR_VALUE
#define RB3D_COLOR_CLEAR_VALUE__BLUE_MASK                  0x000000ffL
#define RB3D_COLOR_CLEAR_VALUE__GREEN_MASK                 0x0000ff00L
#define RB3D_COLOR_CLEAR_VALUE__RED_MASK                   0x00ff0000L
#define RB3D_COLOR_CLEAR_VALUE__ALPHA_MASK                 0xff000000L

// RB3D_ROPCNTL_R3
#define RB3D_ROPCNTL_R3__ROP_ENABLE_MASK                   0x00000004L
#define RB3D_ROPCNTL_R3__ROP_ENABLE                        0x00000004L
#define RB3D_ROPCNTL_R3__ROP_MASK                          0x00000f00L

// RB3D_CLRCMP_FLIPE_R3
#define RB3D_CLRCMP_FLIPE_R3__CLRCMP_FLIPE_MASK            0xffffffffL

// RB3D_CLRCMP_CLR_R3
#define RB3D_CLRCMP_CLR_R3__CLRCMP_CLR_MASK                0xffffffffL

// RB3D_CLRCMP_MSK_R3
#define RB3D_CLRCMP_MSK_R3__CLRCMP_MSK_MASK                0xffffffffL

// RB3D_COLOROFFSET0
#define RB3D_COLOROFFSET0__COLOROFFSET_MASK                0xffffffe0L

// RB3D_COLOROFFSET1
#define RB3D_COLOROFFSET1__COLOROFFSET_MASK                0xffffffe0L

// RB3D_COLOROFFSET2
#define RB3D_COLOROFFSET2__COLOROFFSET_MASK                0xffffffe0L

// RB3D_COLOROFFSET3
#define RB3D_COLOROFFSET3__COLOROFFSET_MASK                0xffffffe0L

// RB3D_COLORPITCH0
#define RB3D_COLORPITCH0__COLORPITCH_MASK                  0x00003ffeL
#define RB3D_COLORPITCH0__COLORTILE_MASK                   0x00010000L
#define RB3D_COLORPITCH0__COLORTILE                        0x00010000L
#define RB3D_COLORPITCH0__COLORMICROTILE_MASK              0x00060000L
#define RB3D_COLORPITCH0__COLORENDIAN_MASK                 0x00180000L
#define RB3D_COLORPITCH0__COLORFORMAT_MASK                 0x01e00000L

// RB3D_COLORPITCH1
#define RB3D_COLORPITCH1__COLORPITCH_MASK                  0x00003ffeL

// RB3D_COLORPITCH2
#define RB3D_COLORPITCH2__COLORPITCH_MASK                  0x00003ffeL

// RB3D_COLORPITCH3
#define RB3D_COLORPITCH3__COLORPITCH_MASK                  0x00003ffeL

// RB3D_DEBUG_CTL
#define RB3D_DEBUG_CTL__DISCARD_ZERO_MASKED_WRITES_MASK    0x00000100L
#define RB3D_DEBUG_CTL__DISCARD_ZERO_MASKED_WRITES         0x00000100L
#define RB3D_DEBUG_CTL__AUTOFLUSH_ENABLE_MASK              0x00000200L
#define RB3D_DEBUG_CTL__AUTOFLUSH_ENABLE                   0x00000200L
#define RB3D_DEBUG_CTL__FORCE_RMW_MASK                     0x00010000L
#define RB3D_DEBUG_CTL__FORCE_RMW                          0x00010000L
#define RB3D_DEBUG_CTL__FORCE_NO_REORDER_MASK              0x00100000L
#define RB3D_DEBUG_CTL__FORCE_NO_REORDER                   0x00100000L
#define RB3D_DEBUG_CTL__FORCE_NO_CYCLE_SWAP_MASK           0x00200000L
#define RB3D_DEBUG_CTL__FORCE_NO_CYCLE_SWAP                0x00200000L
#define RB3D_DEBUG_CTL__FORCE_NO_OP_PREFETCH_MASK          0x00400000L
#define RB3D_DEBUG_CTL__FORCE_NO_OP_PREFETCH               0x00400000L
#define RB3D_DEBUG_CTL__FORCE_NO_CC_PREFETCH_MASK          0x00800000L
#define RB3D_DEBUG_CTL__FORCE_NO_CC_PREFETCH               0x00800000L

// RB3D_DSTCACHE_CTLSTAT_R3
#define RB3D_DSTCACHE_CTLSTAT_R3__DC_FLUSH_MASK            0x00000003L
#define RB3D_DSTCACHE_CTLSTAT_R3__DC_FREE_MASK             0x0000000cL
#define RB3D_DSTCACHE_CTLSTAT_R3__DC_FINISH_MASK           0x00000010L
#define RB3D_DSTCACHE_CTLSTAT_R3__DC_FINISH                0x00000010L

// RB3D_DITHER_CTL
#define RB3D_DITHER_CTL__DITHER_MODE_MASK                  0x00000003L
#define RB3D_DITHER_CTL__ALPHA_DITHER_MODE_MASK            0x0000000cL

// RB3D_CMASK_OFFSET0
#define RB3D_CMASK_OFFSET0__CMASK_OFFSET_MASK              0x0003fff0L

// RB3D_CMASK_OFFSET1
#define RB3D_CMASK_OFFSET1__CMASK_OFFSET_MASK              0x0003fff0L

// RB3D_CMASK_OFFSET2
#define RB3D_CMASK_OFFSET2__CMASK_OFFSET_MASK              0x0003fff0L

// RB3D_CMASK_OFFSET3
#define RB3D_CMASK_OFFSET3__CMASK_OFFSET_MASK              0x0003fff0L

// RB3D_CMASK_PITCH0
#define RB3D_CMASK_PITCH0__CMASK_PITCH_MASK                0x00001ff0L

// RB3D_CMASK_PITCH1
#define RB3D_CMASK_PITCH1__CMASK_PITCH_MASK                0x00001ff0L

// RB3D_CMASK_PITCH2
#define RB3D_CMASK_PITCH2__CMASK_PITCH_MASK                0x00001ff0L

// RB3D_CMASK_PITCH3
#define RB3D_CMASK_PITCH3__CMASK_PITCH_MASK                0x00001ff0L

// RB3D_CMASK_WRINDEX
#define RB3D_CMASK_WRINDEX__CMASK_WRINDEX_MASK             0x0001fff0L

// RB3D_CMASK_DWORD
#define RB3D_CMASK_DWORD__CMASK_DWORD_MASK                 0xffffffffL

// RB3D_CMASK_RDINDEX
#define RB3D_CMASK_RDINDEX__CMASK_RDINDEX_MASK             0x0001fff0L

// RB3D_AARESOLVE_OFFSET
#define RB3D_AARESOLVE_OFFSET__AARESOLVE_OFFSET_MASK       0xffffffe0L

// RB3D_AARESOLVE_PITCH
#define RB3D_AARESOLVE_PITCH__AARESOLVE_PITCH_MASK         0x00003ffeL

// RB3D_AARESOLVE_CTL
#define RB3D_AARESOLVE_CTL__AARESOLVE_MODE_MASK            0x00000001L
#define RB3D_AARESOLVE_CTL__AARESOLVE_MODE                 0x00000001L
#define RB3D_AARESOLVE_CTL__AARESOLVE_GAMMA_MASK           0x00000002L
#define RB3D_AARESOLVE_CTL__AARESOLVE_GAMMA                0x00000002L

// RB3D_PERF_CNTL
#define RB3D_PERF_CNTL__SEL_PERF0_MASK                     0x0000003fL
#define RB3D_PERF_CNTL__CLR_PERF0_MASK                     0x00000040L
#define RB3D_PERF_CNTL__CLR_PERF0                          0x00000040L
#define RB3D_PERF_CNTL__EN_PERF0_MASK                      0x00000080L
#define RB3D_PERF_CNTL__EN_PERF0                           0x00000080L
#define RB3D_PERF_CNTL__SEL_PERF1_MASK                     0x00003f00L
#define RB3D_PERF_CNTL__CLR_PERF1_MASK                     0x00004000L
#define RB3D_PERF_CNTL__CLR_PERF1                          0x00004000L
#define RB3D_PERF_CNTL__EN_PERF1_MASK                      0x00008000L
#define RB3D_PERF_CNTL__EN_PERF1                           0x00008000L
#define RB3D_PERF_CNTL__SEL_PERF2_MASK                     0x003f0000L
#define RB3D_PERF_CNTL__CLR_PERF2_MASK                     0x00400000L
#define RB3D_PERF_CNTL__CLR_PERF2                          0x00400000L
#define RB3D_PERF_CNTL__EN_PERF2_MASK                      0x00800000L
#define RB3D_PERF_CNTL__EN_PERF2                           0x00800000L
#define RB3D_PERF_CNTL__SEL_PERF3_MASK                     0x3f000000L
#define RB3D_PERF_CNTL__CLR_PERF3_MASK                     0x40000000L
#define RB3D_PERF_CNTL__CLR_PERF3                          0x40000000L
#define RB3D_PERF_CNTL__EN_PERF3_MASK                      0x80000000L
#define RB3D_PERF_CNTL__EN_PERF3                           0x80000000L

// RB3D_PERF_COUNT0
#define RB3D_PERF_COUNT0__PERF_COUNT_MASK                  0xffffffffL

// RB3D_PERF_COUNT1
#define RB3D_PERF_COUNT1__PERF_COUNT_MASK                  0xffffffffL

// RB3D_PERF_COUNT2
#define RB3D_PERF_COUNT2__PERF_COUNT_MASK                  0xffffffffL

// RB3D_PERF_COUNT3
#define RB3D_PERF_COUNT3__PERF_COUNT_MASK                  0xffffffffL

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

// RB2D_BRUSHSTAGE_0
#define RB2D_BRUSHSTAGE_0__BRUSHDATA_MASK                  0xffffffffL
#define RB2D_BRUSH_MONO_0_READ__BRUSHDATA_MASK             0xffffffffL

// RB2D_BRUSHSTAGE_1
#define RB2D_BRUSHSTAGE_1__BRUSHDATA_MASK                  0xffffffffL
#define RB2D_BRUSH_MONO_1_READ__BRUSHDATA_MASK             0xffffffffL

// RB2D_BRUSHSTAGE_2
#define RB2D_BRUSHSTAGE_2__BRUSHDATA_MASK                  0xffffffffL
#define RB2D_BRUSH_FRGD_CLR_READ__BRUSHDATA_MASK           0xffffffffL

// RB2D_BRUSHSTAGE_3
#define RB2D_BRUSHSTAGE_3__BRUSHDATA_MASK                  0xffffffffL
#define RB2D_BRUSH_BKGD_CLR_READ__BRUSHDATA_MASK           0xffffffffL

// RB2D_SRC_ENDIAN
#define RB2D_SRC_ENDIAN__SRC_ENDIAN_MASK                   0x00000003L

// RB2D_DST_ENDIAN
#define RB2D_DST_ENDIAN__DST_ENDIAN_MASK                   0x00000003L

// RB2D_DSTCACHE_MODE
#define RB2D_DSTCACHE_MODE__DC_AUTOFLUSH_ENABLE_MASK       0x00000300L
#define RB2D_DSTCACHE_MODE__DC_FORCE_RMW_MASK              0x00010000L
#define RB2D_DSTCACHE_MODE__DC_FORCE_RMW                   0x00010000L
#define RB2D_DSTCACHE_MODE__DC_DISABLE_IGNORE_PE_MASK      0x00020000L
#define RB2D_DSTCACHE_MODE__DC_DISABLE_IGNORE_PE           0x00020000L

// RB2D_DSTCACHE_CTLSTAT
#define RB2D_DSTCACHE_CTLSTAT__DC_FLUSH_MASK               0x00000003L
#define RB2D_DSTCACHE_CTLSTAT__DC_FREE_MASK                0x0000000cL
#define RB2D_DSTCACHE_CTLSTAT__DC_BUSY_MASK                0x80000000L
#define RB2D_DSTCACHE_CTLSTAT__DC_BUSY                     0x80000000L

// RB2D_PERF_CNTL
#define RB2D_PERF_CNTL__SEL_PERF0_MASK                     0x0000001fL
#define RB2D_PERF_CNTL__CLR_PERF0_MASK                     0x00000040L
#define RB2D_PERF_CNTL__CLR_PERF0                          0x00000040L
#define RB2D_PERF_CNTL__EN_PERF0_MASK                      0x00000080L
#define RB2D_PERF_CNTL__EN_PERF0                           0x00000080L
#define RB2D_PERF_CNTL__SEL_PERF1_MASK                     0x00001f00L
#define RB2D_PERF_CNTL__CLR_PERF1_MASK                     0x00004000L
#define RB2D_PERF_CNTL__CLR_PERF1                          0x00004000L
#define RB2D_PERF_CNTL__EN_PERF1_MASK                      0x00008000L
#define RB2D_PERF_CNTL__EN_PERF1                           0x00008000L
#define RB2D_PERF_CNTL__SEL_PERF2_MASK                     0x001f0000L
#define RB2D_PERF_CNTL__CLR_PERF2_MASK                     0x00400000L
#define RB2D_PERF_CNTL__CLR_PERF2                          0x00400000L
#define RB2D_PERF_CNTL__EN_PERF2_MASK                      0x00800000L
#define RB2D_PERF_CNTL__EN_PERF2                           0x00800000L
#define RB2D_PERF_CNTL__SEL_PERF3_MASK                     0x1f000000L
#define RB2D_PERF_CNTL__CLR_PERF3_MASK                     0x40000000L
#define RB2D_PERF_CNTL__CLR_PERF3                          0x40000000L
#define RB2D_PERF_CNTL__EN_PERF3_MASK                      0x80000000L
#define RB2D_PERF_CNTL__EN_PERF3                           0x80000000L

// RB2D_PERF_COUNT0
#define RB2D_PERF_COUNT0__PERF_CNT_MASK                    0xffffffffL

// RB2D_PERF_COUNT1
#define RB2D_PERF_COUNT1__PERF_CNT_MASK                    0xffffffffL

// RB2D_PERF_COUNT2
#define RB2D_PERF_COUNT2__PERF_CNT_MASK                    0xffffffffL

// RB2D_PERF_COUNT3
#define RB2D_PERF_COUNT3__PERF_CNT_MASK                    0xffffffffL

// ZB_CNTL
#define ZB_CNTL__STENCIL_ENABLE_MASK                       0x00000001L
#define RB3D_ZCNTL__STENCIL_ENABLE_MASK                    0x00000001L
#define ZB_CNTL__STENCIL_ENABLE                            0x00000001L
#define RB3D_ZCNTL__STENCIL_ENABLE                         0x00000001L
#define ZB_CNTL__Z_ENABLE_MASK                             0x00000002L
#define RB3D_ZCNTL__Z_ENABLE_MASK                          0x00000002L
#define ZB_CNTL__Z_ENABLE                                  0x00000002L
#define RB3D_ZCNTL__Z_ENABLE                               0x00000002L
#define ZB_CNTL__ZWRITEENABLE_MASK                         0x00000004L
#define RB3D_ZCNTL__ZWRITEENABLE_MASK                      0x00000004L
#define ZB_CNTL__ZWRITEENABLE                              0x00000004L
#define RB3D_ZCNTL__ZWRITEENABLE                           0x00000004L
#define ZB_CNTL__ZSIGNED_COMPARE_MASK                      0x00000008L
#define RB3D_ZCNTL__ZSIGNED_COMPARE_MASK                   0x00000008L
#define ZB_CNTL__ZSIGNED_COMPARE                           0x00000008L
#define RB3D_ZCNTL__ZSIGNED_COMPARE                        0x00000008L
#define ZB_CNTL__STENCIL_FRONT_BACK_MASK                   0x00000010L
#define RB3D_ZCNTL__STENCIL_FRONT_BACK_MASK                0x00000010L
#define ZB_CNTL__STENCIL_FRONT_BACK                        0x00000010L
#define RB3D_ZCNTL__STENCIL_FRONT_BACK                     0x00000010L

// ZB_ZSTENCILCNTL
#define ZB_ZSTENCILCNTL__ZFUNC_MASK                        0x00000007L
#define RB3D_ZSTENCILCNTL_R3__ZFUNC_MASK                   0x00000007L
#define ZB_ZSTENCILCNTL__STENCILFUNC_MASK                  0x00000038L
#define RB3D_ZSTENCILCNTL_R3__STENCILFUNC_MASK             0x00000038L
#define ZB_ZSTENCILCNTL__STENCILFAIL_MASK                  0x000001c0L
#define RB3D_ZSTENCILCNTL_R3__STENCILFAIL_MASK             0x000001c0L
#define ZB_ZSTENCILCNTL__STENCILZPASS_MASK                 0x00000e00L
#define RB3D_ZSTENCILCNTL_R3__STENCILZPASS_MASK            0x00000e00L
#define ZB_ZSTENCILCNTL__STENCILZFAIL_MASK                 0x00007000L
#define RB3D_ZSTENCILCNTL_R3__STENCILZFAIL_MASK            0x00007000L
#define ZB_ZSTENCILCNTL__STENCILFUNC_BF_MASK               0x00038000L
#define RB3D_ZSTENCILCNTL_R3__STENCILFUNC_BF_MASK          0x00038000L
#define ZB_ZSTENCILCNTL__STENCILFAIL_BF_MASK               0x001c0000L
#define RB3D_ZSTENCILCNTL_R3__STENCILFAIL_BF_MASK          0x001c0000L
#define ZB_ZSTENCILCNTL__STENCILZPASS_BF_MASK              0x00e00000L
#define RB3D_ZSTENCILCNTL_R3__STENCILZPASS_BF_MASK         0x00e00000L
#define ZB_ZSTENCILCNTL__STENCILZFAIL_BF_MASK              0x07000000L
#define RB3D_ZSTENCILCNTL_R3__STENCILZFAIL_BF_MASK         0x07000000L

// ZB_STENCILREFMASK
#define ZB_STENCILREFMASK__STENCILREF_MASK                 0x000000ffL
#define RB3D_STENCILREFMASK_R3__STENCILREF_MASK            0x000000ffL
#define ZB_STENCILREFMASK__STENCILMASK_MASK                0x0000ff00L
#define RB3D_STENCILREFMASK_R3__STENCILMASK_MASK           0x0000ff00L
#define ZB_STENCILREFMASK__STENCILWRITEMASK_MASK           0x00ff0000L
#define RB3D_STENCILREFMASK_R3__STENCILWRITEMASK_MASK      0x00ff0000L

// ZB_FORMAT
#define ZB_FORMAT__DEPTHFORMAT_MASK                        0x0000000fL
#define RB3D_FORMAT__DEPTHFORMAT_MASK                      0x0000000fL
#define ZB_FORMAT__INVERT_MASK                             0x00000010L
#define RB3D_FORMAT__INVERT_MASK                           0x00000010L
#define ZB_FORMAT__INVERT                                  0x00000010L
#define RB3D_FORMAT__INVERT                                0x00000010L
#define ZB_FORMAT__PEQ8_MASK                               0x00000020L
#define RB3D_FORMAT__PEQ8_MASK                             0x00000020L
#define ZB_FORMAT__PEQ8                                    0x00000020L
#define RB3D_FORMAT__PEQ8                                  0x00000020L

// ZB_ZTOP
#define ZB_ZTOP__ZTOP_MASK                                 0x00000001L
#define RB3D_ZTOP__ZTOP_MASK                               0x00000001L
#define ZB_ZTOP__ZTOP                                      0x00000001L
#define RB3D_ZTOP__ZTOP                                    0x00000001L

// ZB_ZCACHE_CTLSTAT
#define ZB_ZCACHE_CTLSTAT__ZC_FLUSH_MASK                   0x00000001L
#define RB3D_ZCACHE_CTLSTAT_R3__ZC_FLUSH_MASK              0x00000001L
#define ZB_ZCACHE_CTLSTAT__ZC_FLUSH                        0x00000001L
#define RB3D_ZCACHE_CTLSTAT_R3__ZC_FLUSH                   0x00000001L
#define ZB_ZCACHE_CTLSTAT__ZC_FREE_MASK                    0x00000002L
#define RB3D_ZCACHE_CTLSTAT_R3__ZC_FREE_MASK               0x00000002L
#define ZB_ZCACHE_CTLSTAT__ZC_FREE                         0x00000002L
#define RB3D_ZCACHE_CTLSTAT_R3__ZC_FREE                    0x00000002L
#define ZB_ZCACHE_CTLSTAT__ZC_BUSY_MASK                    0x80000000L
#define RB3D_ZCACHE_CTLSTAT_R3__ZC_BUSY_MASK               0x80000000L
#define ZB_ZCACHE_CTLSTAT__ZC_BUSY                         0x80000000L
#define RB3D_ZCACHE_CTLSTAT_R3__ZC_BUSY                    0x80000000L

// ZB_BW_CNTL
#define ZB_BW_CNTL__HIZ_ENABLE_MASK                        0x00000001L
#define RB3D_BW_CNTL__HIZ_ENABLE_MASK                      0x00000001L
#define ZB_BW_CNTL__HIZ_ENABLE                             0x00000001L
#define RB3D_BW_CNTL__HIZ_ENABLE                           0x00000001L
#define ZB_BW_CNTL__HIZ_MIN_MASK                           0x00000002L
#define RB3D_BW_CNTL__HIZ_MIN_MASK                         0x00000002L
#define ZB_BW_CNTL__HIZ_MIN                                0x00000002L
#define RB3D_BW_CNTL__HIZ_MIN                              0x00000002L
#define ZB_BW_CNTL__FAST_FILL_MASK                         0x00000004L
#define RB3D_BW_CNTL__FAST_FILL_MASK                       0x00000004L
#define ZB_BW_CNTL__FAST_FILL                              0x00000004L
#define RB3D_BW_CNTL__FAST_FILL                            0x00000004L
#define ZB_BW_CNTL__RD_COMP_ENABLE_MASK                    0x00000008L
#define RB3D_BW_CNTL__RD_COMP_ENABLE_MASK                  0x00000008L
#define ZB_BW_CNTL__RD_COMP_ENABLE                         0x00000008L
#define RB3D_BW_CNTL__RD_COMP_ENABLE                       0x00000008L
#define ZB_BW_CNTL__WR_COMP_ENABLE_MASK                    0x00000010L
#define RB3D_BW_CNTL__WR_COMP_ENABLE_MASK                  0x00000010L
#define ZB_BW_CNTL__WR_COMP_ENABLE                         0x00000010L
#define RB3D_BW_CNTL__WR_COMP_ENABLE                       0x00000010L
#define ZB_BW_CNTL__ZB_CB_CLEAR_MASK                       0x00000020L
#define RB3D_BW_CNTL__ZB_CB_CLEAR_MASK                     0x00000020L
#define ZB_BW_CNTL__ZB_CB_CLEAR                            0x00000020L
#define RB3D_BW_CNTL__ZB_CB_CLEAR                          0x00000020L

// ZB_DEPTHOFFSET
#define ZB_DEPTHOFFSET__DEPTHOFFSET_MASK                   0xffffffe0L
#define RB3D_DEPTHOFFSET_R3__DEPTHOFFSET_MASK              0xffffffe0L

// ZB_DEPTHPITCH
#define ZB_DEPTHPITCH__DEPTHPITCH_MASK                     0x00003ffcL
#define RB3D_DEPTHPITCH_R3__DEPTHPITCH_MASK                0x00003ffcL
#define ZB_DEPTHPITCH__DEPTHMACROTILE_MASK                 0x00010000L
#define RB3D_DEPTHPITCH_R3__DEPTHMACROTILE_MASK            0x00010000L
#define ZB_DEPTHPITCH__DEPTHMACROTILE                      0x00010000L
#define RB3D_DEPTHPITCH_R3__DEPTHMACROTILE                 0x00010000L
#define ZB_DEPTHPITCH__DEPTHMICROTILE_MASK                 0x00060000L
#define RB3D_DEPTHPITCH_R3__DEPTHMICROTILE_MASK            0x00060000L
#define ZB_DEPTHPITCH__DEPTHENDIAN_MASK                    0x00180000L
#define RB3D_DEPTHPITCH_R3__DEPTHENDIAN_MASK               0x00180000L

// ZB_DEPTHCLEARVALUE
#define ZB_DEPTHCLEARVALUE__DEPTHCLEARVALUE_MASK           0xffffffffL
#define RB3D_DEPTHCLEARVALUE_R3__DEPTHCLEARVALUE_MASK      0xffffffffL

// ZB_ZMASK_OFFSET
#define ZB_ZMASK_OFFSET__ZMASK_OFFSET_MASK                 0x0001fff0L
#define RB3D_ZMASK_OFFSET__ZMASK_OFFSET_MASK               0x0001fff0L

// ZB_ZMASK_PITCH
#define ZB_ZMASK_PITCH__ZMASK_PITCH_MASK                   0x00003ff0L
#define RB3D_ZMASK_PITCH__ZMASK_PITCH_MASK                 0x00003ff0L

// ZB_ZMASK_WRINDEX
#define ZB_ZMASK_WRINDEX__ZMASK_WRINDEX_MASK               0x0001fff0L
#define RB3D_ZMASK_WRINDEX_R3__ZMASK_WRINDEX_MASK          0x0001fff0L

// ZB_ZMASK_DWORD
#define ZB_ZMASK_DWORD__ZMASK_DWORD_MASK                   0xffffffffL
#define RB3D_ZMASK_DWORD_R3__ZMASK_DWORD_MASK              0xffffffffL

// ZB_ZMASK_RDINDEX
#define ZB_ZMASK_RDINDEX__ZMASK_RDINDEX_MASK               0x0001fff0L
#define RB3D_ZMASK_RDINDEX_R3__ZMASK_RDINDEX_MASK          0x0001fff0L

// ZB_HIZ_OFFSET
#define ZB_HIZ_OFFSET__HIZ_OFFSET_MASK                     0x0001fffcL
#define RE_HIZ_OFFSET__HIZ_OFFSET_MASK                     0x0001fffcL

// ZB_HIZ_WRINDEX
#define ZB_HIZ_WRINDEX__HIZ_WRINDEX_MASK                   0x0001fffcL
#define RE_HIZ_WRINDEX_R3__HIZ_WRINDEX_MASK                0x0001fffcL

// ZB_HIZ_DWORD
#define ZB_HIZ_DWORD__HIZ_DWORD_MASK                       0xffffffffL
#define RE_HIZ_DWORD_R3__HIZ_DWORD_MASK                    0xffffffffL

// ZB_HIZ_RDINDEX
#define ZB_HIZ_RDINDEX__HIZ_RDINDEX_MASK                   0x0001fffcL
#define RE_HIZ_RDINDEX_R3__HIZ_RDINDEX_MASK                0x0001fffcL

// ZB_HIZ_PITCH
#define ZB_HIZ_PITCH__HIZ_PITCH_MASK                       0x00003ff0L
#define RB3D_HIZ_PITCH__HIZ_PITCH_MASK                     0x00003ff0L

// ZB_ZPASS_DATA
#define ZB_ZPASS_DATA__ZPASS_DATA_MASK                     0xffffffffL
#define RB3D_ZPASS_DATA_R3__ZPASS_DATA_MASK                0xffffffffL

// ZB_ZPASS_ADDR
#define ZB_ZPASS_ADDR__ZPASS_ADDR_MASK                     0xfffffffcL
#define RB3D_ZPASS_ADDR_R3__ZPASS_ADDR_MASK                0xfffffffcL

// ZB_DEPTHXY_OFFSET
#define ZB_DEPTHXY_OFFSET__DEPTHX_OFFSET_MASK              0x00000ffeL
#define RB3D_DEPTHXY_OFFSET_R3__DEPTHX_OFFSET_MASK         0x00000ffeL
#define ZB_DEPTHXY_OFFSET__DEPTHY_OFFSET_MASK              0x0ffe0000L
#define RB3D_DEPTHXY_OFFSET_R3__DEPTHY_OFFSET_MASK         0x0ffe0000L

// ZB_PERF_CNTL
#define ZB_PERF_CNTL__SEL_PERF0_MASK                       0x0000000fL
#define RB3D_ZPERF_CNTL_R3__SEL_PERF0_MASK                 0x0000000fL
#define ZB_PERF_CNTL__CLR_PERF0_MASK                       0x00000010L
#define RB3D_ZPERF_CNTL_R3__CLR_PERF0_MASK                 0x00000010L
#define ZB_PERF_CNTL__CLR_PERF0                            0x00000010L
#define RB3D_ZPERF_CNTL_R3__CLR_PERF0                      0x00000010L
#define ZB_PERF_CNTL__EN_PERF0_MASK                        0x00000020L
#define RB3D_ZPERF_CNTL_R3__EN_PERF0_MASK                  0x00000020L
#define ZB_PERF_CNTL__EN_PERF0                             0x00000020L
#define RB3D_ZPERF_CNTL_R3__EN_PERF0                       0x00000020L
#define ZB_PERF_CNTL__SEL_PERF1_MASK                       0x00000f00L
#define RB3D_ZPERF_CNTL_R3__SEL_PERF1_MASK                 0x00000f00L
#define ZB_PERF_CNTL__CLR_PERF1_MASK                       0x00001000L
#define RB3D_ZPERF_CNTL_R3__CLR_PERF1_MASK                 0x00001000L
#define ZB_PERF_CNTL__CLR_PERF1                            0x00001000L
#define RB3D_ZPERF_CNTL_R3__CLR_PERF1                      0x00001000L
#define ZB_PERF_CNTL__EN_PERF1_MASK                        0x00002000L
#define RB3D_ZPERF_CNTL_R3__EN_PERF1_MASK                  0x00002000L
#define ZB_PERF_CNTL__EN_PERF1                             0x00002000L
#define RB3D_ZPERF_CNTL_R3__EN_PERF1                       0x00002000L
#define ZB_PERF_CNTL__SEL_PERF2_MASK                       0x000f0000L
#define RB3D_ZPERF_CNTL_R3__SEL_PERF2_MASK                 0x000f0000L
#define ZB_PERF_CNTL__CLR_PERF2_MASK                       0x00100000L
#define RB3D_ZPERF_CNTL_R3__CLR_PERF2_MASK                 0x00100000L
#define ZB_PERF_CNTL__CLR_PERF2                            0x00100000L
#define RB3D_ZPERF_CNTL_R3__CLR_PERF2                      0x00100000L
#define ZB_PERF_CNTL__EN_PERF2_MASK                        0x00200000L
#define RB3D_ZPERF_CNTL_R3__EN_PERF2_MASK                  0x00200000L
#define ZB_PERF_CNTL__EN_PERF2                             0x00200000L
#define RB3D_ZPERF_CNTL_R3__EN_PERF2                       0x00200000L
#define ZB_PERF_CNTL__SEL_PERF3_MASK                       0x0f000000L
#define RB3D_ZPERF_CNTL_R3__SEL_PERF3_MASK                 0x0f000000L
#define ZB_PERF_CNTL__CLR_PERF3_MASK                       0x10000000L
#define RB3D_ZPERF_CNTL_R3__CLR_PERF3_MASK                 0x10000000L
#define ZB_PERF_CNTL__CLR_PERF3                            0x10000000L
#define RB3D_ZPERF_CNTL_R3__CLR_PERF3                      0x10000000L
#define ZB_PERF_CNTL__EN_PERF3_MASK                        0x20000000L
#define RB3D_ZPERF_CNTL_R3__EN_PERF3_MASK                  0x20000000L
#define ZB_PERF_CNTL__EN_PERF3                             0x20000000L
#define RB3D_ZPERF_CNTL_R3__EN_PERF3                       0x20000000L

// ZB_PERF_COUNT0
#define ZB_PERF_COUNT0__PERF_COUNT_MASK                    0xffffffffL
#define RB3D_ZPERF_COUNT0__PERF_COUNT_MASK                 0xffffffffL

// ZB_PERF_COUNT1
#define ZB_PERF_COUNT1__PERF_COUNT_MASK                    0xffffffffL
#define RB3D_ZPERF_COUNT1__PERF_COUNT_MASK                 0xffffffffL

// ZB_PERF_COUNT2
#define ZB_PERF_COUNT2__PERF_COUNT_MASK                    0xffffffffL
#define RB3D_ZPERF_COUNT2__PERF_COUNT_MASK                 0xffffffffL

// ZB_PERF_COUNT3
#define ZB_PERF_COUNT3__PERF_COUNT_MASK                    0xffffffffL
#define RB3D_ZPERF_COUNT3__PERF_COUNT_MASK                 0xffffffffL

// DST_OFFSET
#define DST_OFFSET__DST_OFFSET_MASK                        0xffffffffL

// DST_PITCH
#define DST_PITCH__DST_PITCH_MASK                          0x00003fffL

// DST_TILE
#define DST_TILE__DST_TILE_MASK                            0x00000003L
#define DST_TILE__DST_TILE2_MASK                           0x00000004L
#define DST_TILE__DST_TILE2                                0x00000004L

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

// HOST_DATA_128
#define HOST_DATA_128__HOST_DATA_128_MASK                  0xffffffffL

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
#define DP_CNTL__DST_TILE2_MASK                            0x00000020L
#define DP_CNTL__DST_TILE2                                 0x00000020L

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

// VAP_PORT_DATA0
#define VAP_PORT_DATA0__DATAPORT0_MASK                     0xffffffffL

// VAP_PORT_DATA1
#define VAP_PORT_DATA1__DATAPORT1_MASK                     0xffffffffL

// VAP_PORT_DATA2
#define VAP_PORT_DATA2__DATAPORT2_MASK                     0xffffffffL

// VAP_PORT_DATA3
#define VAP_PORT_DATA3__DATAPORT3_MASK                     0xffffffffL

// VAP_PORT_DATA4
#define VAP_PORT_DATA4__DATAPORT4_MASK                     0xffffffffL

// VAP_PORT_DATA5
#define VAP_PORT_DATA5__DATAPORT5_MASK                     0xffffffffL

// VAP_PORT_DATA6
#define VAP_PORT_DATA6__DATAPORT6_MASK                     0xffffffffL

// VAP_PORT_DATA7
#define VAP_PORT_DATA7__DATAPORT7_MASK                     0xffffffffL

// VAP_PORT_DATA8
#define VAP_PORT_DATA8__DATAPORT8_MASK                     0xffffffffL

// VAP_PORT_DATA9
#define VAP_PORT_DATA9__DATAPORT9_MASK                     0xffffffffL

// VAP_PORT_DATA10
#define VAP_PORT_DATA10__DATAPORT10_MASK                   0xffffffffL

// VAP_PORT_DATA11
#define VAP_PORT_DATA11__DATAPORT11_MASK                   0xffffffffL

// VAP_PORT_DATA12
#define VAP_PORT_DATA12__DATAPORT12_MASK                   0xffffffffL

// VAP_PORT_DATA13
#define VAP_PORT_DATA13__DATAPORT13_MASK                   0xffffffffL

// VAP_PORT_DATA14
#define VAP_PORT_DATA14__DATAPORT14_MASK                   0xffffffffL

// VAP_PORT_DATA15
#define VAP_PORT_DATA15__DATAPORT15_MASK                   0xffffffffL

// VAP_PORT_IDX0
#define VAP_PORT_IDX0__IDXPORT0_MASK                       0xffffffffL

// VAP_PORT_IDX1
#define VAP_PORT_IDX1__IDXPORT1_MASK                       0xffffffffL

// VAP_PORT_IDX2
#define VAP_PORT_IDX2__IDXPORT2_MASK                       0xffffffffL

// VAP_PORT_IDX3
#define VAP_PORT_IDX3__IDXPORT3_MASK                       0xffffffffL

// VAP_PORT_IDX4
#define VAP_PORT_IDX4__IDXPORT4_MASK                       0xffffffffL

// VAP_PORT_IDX5
#define VAP_PORT_IDX5__IDXPORT5_MASK                       0xffffffffL

// VAP_PORT_IDX6
#define VAP_PORT_IDX6__IDXPORT6_MASK                       0xffffffffL

// VAP_PORT_IDX7
#define VAP_PORT_IDX7__IDXPORT7_MASK                       0xffffffffL

// VAP_PORT_IDX8
#define VAP_PORT_IDX8__IDXPORT8_MASK                       0xffffffffL

// VAP_PORT_IDX9
#define VAP_PORT_IDX9__IDXPORT9_MASK                       0xffffffffL

// VAP_PORT_IDX10
#define VAP_PORT_IDX10__IDXPORT10_MASK                     0xffffffffL

// VAP_PORT_IDX11
#define VAP_PORT_IDX11__IDXPORT11_MASK                     0xffffffffL

// VAP_PORT_IDX12
#define VAP_PORT_IDX12__IDXPORT12_MASK                     0xffffffffL

// VAP_PORT_IDX13
#define VAP_PORT_IDX13__IDXPORT13_MASK                     0xffffffffL

// VAP_PORT_IDX14
#define VAP_PORT_IDX14__IDXPORT14_MASK                     0xffffffffL

// VAP_PORT_IDX15
#define VAP_PORT_IDX15__IDXPORT15_MASK                     0xffffffffL

// VAP_CNTL
#define VAP_CNTL__PVS_NUM_SLOTS_MASK                       0x0000000fL
#define VAP_CNTL__PVS_NUM_CNTLRS_MASK                      0x000000f0L
#define VAP_CNTL__PVS_NUM_FPUS_MASK                        0x00000f00L
#define VAP_CNTL__VF_MAX_VTX_NUM_MASK                      0x003c0000L
#define VAP_CNTL__DX_CLIP_SPACE_DEF_MASK                   0x00400000L
#define VAP_CNTL__DX_CLIP_SPACE_DEF                        0x00400000L

// VAP_VF_CNTL
#define VAP_VF_CNTL__PRIM_TYPE_MASK                        0x0000000fL
#define VAP_VF_CNTL__PRIM_WALK_MASK                        0x00000030L
#define VAP_VF_CNTL__RSVD_PREV_USED_MASK                   0x000007c0L
#define VAP_VF_CNTL__INDEX_SIZE_MASK                       0x00000800L
#define VAP_VF_CNTL__INDEX_SIZE                            0x00000800L
#define VAP_VF_CNTL__VTX_REUSE_DIS_MASK                    0x00001000L
#define VAP_VF_CNTL__VTX_REUSE_DIS                         0x00001000L
#define VAP_VF_CNTL__DUAL_INDEX_MODE_MASK                  0x00002000L
#define VAP_VF_CNTL__DUAL_INDEX_MODE                       0x00002000L
#define VAP_VF_CNTL__NUM_VERTICES_MASK                     0xffff0000L

// VAP_OUT_VTX_FMT_0
#define VAP_OUT_VTX_FMT_0__VTX_POS_PRESENT_MASK            0x00000001L
#define VAP_OUT_VTX_FMT_0__VTX_POS_PRESENT                 0x00000001L
#define VAP_OUT_VTX_FMT_0__VTX_COLOR_0_PRESENT_MASK        0x00000002L
#define VAP_OUT_VTX_FMT_0__VTX_COLOR_0_PRESENT             0x00000002L
#define VAP_OUT_VTX_FMT_0__VTX_COLOR_1_PRESENT_MASK        0x00000004L
#define VAP_OUT_VTX_FMT_0__VTX_COLOR_1_PRESENT             0x00000004L
#define VAP_OUT_VTX_FMT_0__VTX_COLOR_2_PRESENT_MASK        0x00000008L
#define VAP_OUT_VTX_FMT_0__VTX_COLOR_2_PRESENT             0x00000008L
#define VAP_OUT_VTX_FMT_0__VTX_COLOR_3_PRESENT_MASK        0x00000010L
#define VAP_OUT_VTX_FMT_0__VTX_COLOR_3_PRESENT             0x00000010L
#define VAP_OUT_VTX_FMT_0__VTX_PT_SIZE_PRESENT_MASK        0x00010000L
#define VAP_OUT_VTX_FMT_0__VTX_PT_SIZE_PRESENT             0x00010000L

// VAP_OUT_VTX_FMT_1
#define VAP_OUT_VTX_FMT_1__TEX_0_COMP_CNT_MASK             0x00000007L
#define VAP_OUT_VTX_FMT_1__TEX_1_COMP_CNT_MASK             0x00000038L
#define VAP_OUT_VTX_FMT_1__TEX_2_COMP_CNT_MASK             0x000001c0L
#define VAP_OUT_VTX_FMT_1__TEX_3_COMP_CNT_MASK             0x00000e00L
#define VAP_OUT_VTX_FMT_1__TEX_4_COMP_CNT_MASK             0x00007000L
#define VAP_OUT_VTX_FMT_1__TEX_5_COMP_CNT_MASK             0x00038000L
#define VAP_OUT_VTX_FMT_1__TEX_6_COMP_CNT_MASK             0x001c0000L
#define VAP_OUT_VTX_FMT_1__TEX_7_COMP_CNT_MASK             0x00e00000L

// VAP_VPORT_XSCALE
#define VAP_VPORT_XSCALE__VPORT_XSCALE_MASK                0xffffffffL

// VAP_VPORT_XOFFSET
#define VAP_VPORT_XOFFSET__VPORT_XOFFSET_MASK              0xffffffffL

// VAP_VPORT_YSCALE
#define VAP_VPORT_YSCALE__VPORT_YSCALE_MASK                0xffffffffL

// VAP_VPORT_YOFFSET
#define VAP_VPORT_YOFFSET__VPORT_YOFFSET_MASK              0xffffffffL

// VAP_VPORT_ZSCALE
#define VAP_VPORT_ZSCALE__VPORT_ZSCALE_MASK                0xffffffffL

// VAP_VPORT_ZOFFSET
#define VAP_VPORT_ZOFFSET__VPORT_ZOFFSET_MASK              0xffffffffL

// VAP_VTE_CNTL
#define VAP_VTE_CNTL__VPORT_X_SCALE_ENA_MASK               0x00000001L
#define VAP_VTE_CNTL__VPORT_X_SCALE_ENA                    0x00000001L
#define VAP_VTE_CNTL__VPORT_X_OFFSET_ENA_MASK              0x00000002L
#define VAP_VTE_CNTL__VPORT_X_OFFSET_ENA                   0x00000002L
#define VAP_VTE_CNTL__VPORT_Y_SCALE_ENA_MASK               0x00000004L
#define VAP_VTE_CNTL__VPORT_Y_SCALE_ENA                    0x00000004L
#define VAP_VTE_CNTL__VPORT_Y_OFFSET_ENA_MASK              0x00000008L
#define VAP_VTE_CNTL__VPORT_Y_OFFSET_ENA                   0x00000008L
#define VAP_VTE_CNTL__VPORT_Z_SCALE_ENA_MASK               0x00000010L
#define VAP_VTE_CNTL__VPORT_Z_SCALE_ENA                    0x00000010L
#define VAP_VTE_CNTL__VPORT_Z_OFFSET_ENA_MASK              0x00000020L
#define VAP_VTE_CNTL__VPORT_Z_OFFSET_ENA                   0x00000020L
#define VAP_VTE_CNTL__VTX_XY_FMT_MASK                      0x00000100L
#define VAP_VTE_CNTL__VTX_XY_FMT                           0x00000100L
#define VAP_VTE_CNTL__VTX_Z_FMT_MASK                       0x00000200L
#define VAP_VTE_CNTL__VTX_Z_FMT                            0x00000200L
#define VAP_VTE_CNTL__VTX_W0_FMT_MASK                      0x00000400L
#define VAP_VTE_CNTL__VTX_W0_FMT                           0x00000400L
#define VAP_VTE_CNTL__SERIAL_PROC_ENA_MASK                 0x00000800L
#define VAP_VTE_CNTL__SERIAL_PROC_ENA                      0x00000800L

// VAP_VTX_SIZE
#define VAP_VTX_SIZE__DWORDS_PER_VTX_MASK                  0x0000007fL

// VAP_PORT_DATA_IDX_128
#define VAP_PORT_DATA_IDX_128__DATA_IDX_PORT_128_MASK      0xffffffffL

// VAP_VTX_NUM_ARRAYS
#define VAP_VTX_NUM_ARRAYS__VTX_NUM_ARRAYS_MASK            0x0000001fL
#define VAP_VTX_NUM_ARRAYS__VC_FORCE_PREFETCH_MASK         0x00000020L
#define VAP_VTX_NUM_ARRAYS__VC_FORCE_PREFETCH              0x00000020L
#define VAP_VTX_NUM_ARRAYS__VC_DIS_CACHE_INVLD_MASK        0x00000040L
#define VAP_VTX_NUM_ARRAYS__VC_DIS_CACHE_INVLD             0x00000040L
#define VAP_VTX_NUM_ARRAYS__AOS_0_FETCH_SIZE_MASK          0x00010000L
#define VAP_VTX_NUM_ARRAYS__AOS_0_FETCH_SIZE               0x00010000L
#define VAP_VTX_NUM_ARRAYS__AOS_1_FETCH_SIZE_MASK          0x00020000L
#define VAP_VTX_NUM_ARRAYS__AOS_1_FETCH_SIZE               0x00020000L
#define VAP_VTX_NUM_ARRAYS__AOS_2_FETCH_SIZE_MASK          0x00040000L
#define VAP_VTX_NUM_ARRAYS__AOS_2_FETCH_SIZE               0x00040000L
#define VAP_VTX_NUM_ARRAYS__AOS_3_FETCH_SIZE_MASK          0x00080000L
#define VAP_VTX_NUM_ARRAYS__AOS_3_FETCH_SIZE               0x00080000L
#define VAP_VTX_NUM_ARRAYS__AOS_4_FETCH_SIZE_MASK          0x00100000L
#define VAP_VTX_NUM_ARRAYS__AOS_4_FETCH_SIZE               0x00100000L
#define VAP_VTX_NUM_ARRAYS__AOS_5_FETCH_SIZE_MASK          0x00200000L
#define VAP_VTX_NUM_ARRAYS__AOS_5_FETCH_SIZE               0x00200000L
#define VAP_VTX_NUM_ARRAYS__AOS_6_FETCH_SIZE_MASK          0x00400000L
#define VAP_VTX_NUM_ARRAYS__AOS_6_FETCH_SIZE               0x00400000L
#define VAP_VTX_NUM_ARRAYS__AOS_7_FETCH_SIZE_MASK          0x00800000L
#define VAP_VTX_NUM_ARRAYS__AOS_7_FETCH_SIZE               0x00800000L
#define VAP_VTX_NUM_ARRAYS__AOS_8_FETCH_SIZE_MASK          0x01000000L
#define VAP_VTX_NUM_ARRAYS__AOS_8_FETCH_SIZE               0x01000000L
#define VAP_VTX_NUM_ARRAYS__AOS_9_FETCH_SIZE_MASK          0x02000000L
#define VAP_VTX_NUM_ARRAYS__AOS_9_FETCH_SIZE               0x02000000L
#define VAP_VTX_NUM_ARRAYS__AOS_10_FETCH_SIZE_MASK         0x04000000L
#define VAP_VTX_NUM_ARRAYS__AOS_10_FETCH_SIZE              0x04000000L
#define VAP_VTX_NUM_ARRAYS__AOS_11_FETCH_SIZE_MASK         0x08000000L
#define VAP_VTX_NUM_ARRAYS__AOS_11_FETCH_SIZE              0x08000000L
#define VAP_VTX_NUM_ARRAYS__AOS_12_FETCH_SIZE_MASK         0x10000000L
#define VAP_VTX_NUM_ARRAYS__AOS_12_FETCH_SIZE              0x10000000L
#define VAP_VTX_NUM_ARRAYS__AOS_13_FETCH_SIZE_MASK         0x20000000L
#define VAP_VTX_NUM_ARRAYS__AOS_13_FETCH_SIZE              0x20000000L
#define VAP_VTX_NUM_ARRAYS__AOS_14_FETCH_SIZE_MASK         0x40000000L
#define VAP_VTX_NUM_ARRAYS__AOS_14_FETCH_SIZE              0x40000000L
#define VAP_VTX_NUM_ARRAYS__AOS_15_FETCH_SIZE_MASK         0x80000000L
#define VAP_VTX_NUM_ARRAYS__AOS_15_FETCH_SIZE              0x80000000L

// VAP_VTX_AOS_ATTR01
#define VAP_VTX_AOS_ATTR01__VTX_AOS_COUNT0_MASK            0x0000007fL
#define VAP_VTX_AOS_ATTR01__VTX_AOS_STRIDE0_MASK           0x00007f00L
#define VAP_VTX_AOS_ATTR01__VTX_AOS_COUNT1_MASK            0x007f0000L
#define VAP_VTX_AOS_ATTR01__VTX_AOS_STRIDE1_MASK           0x7f000000L

// VAP_VTX_AOS_ADDR0
#define VAP_VTX_AOS_ADDR0__VTX_AOS_ADDR0_MASK              0xfffffffcL

// VAP_VTX_AOS_ADDR1
#define VAP_VTX_AOS_ADDR1__VTX_AOS_ADDR1_MASK              0xfffffffcL

// VAP_VTX_AOS_ATTR23
#define VAP_VTX_AOS_ATTR23__VTX_AOS_COUNT2_MASK            0x0000007fL
#define VAP_VTX_AOS_ATTR23__VTX_AOS_STRIDE2_MASK           0x00007f00L
#define VAP_VTX_AOS_ATTR23__VTX_AOS_COUNT3_MASK            0x007f0000L
#define VAP_VTX_AOS_ATTR23__VTX_AOS_STRIDE3_MASK           0x7f000000L

// VAP_VTX_AOS_ADDR2
#define VAP_VTX_AOS_ADDR2__VTX_AOS_ADDR2_MASK              0xfffffffcL

// VAP_VTX_AOS_ADDR3
#define VAP_VTX_AOS_ADDR3__VTX_AOS_ADDR3_MASK              0xfffffffcL

// VAP_VTX_AOS_ATTR45
#define VAP_VTX_AOS_ATTR45__VTX_AOS_COUNT4_MASK            0x0000007fL
#define VAP_VTX_AOS_ATTR45__VTX_AOS_STRIDE4_MASK           0x00007f00L
#define VAP_VTX_AOS_ATTR45__VTX_AOS_COUNT5_MASK            0x007f0000L
#define VAP_VTX_AOS_ATTR45__VTX_AOS_STRIDE5_MASK           0x7f000000L

// VAP_VTX_AOS_ADDR4
#define VAP_VTX_AOS_ADDR4__VTX_AOS_ADDR4_MASK              0xfffffffcL

// VAP_VTX_AOS_ADDR5
#define VAP_VTX_AOS_ADDR5__VTX_AOS_ADDR5_MASK              0xfffffffcL

// VAP_VTX_AOS_ATTR67
#define VAP_VTX_AOS_ATTR67__VTX_AOS_COUNT6_MASK            0x0000007fL
#define VAP_VTX_AOS_ATTR67__VTX_AOS_STRIDE6_MASK           0x00007f00L
#define VAP_VTX_AOS_ATTR67__VTX_AOS_COUNT7_MASK            0x007f0000L
#define VAP_VTX_AOS_ATTR67__VTX_AOS_STRIDE7_MASK           0x7f000000L

// VAP_VTX_AOS_ADDR6
#define VAP_VTX_AOS_ADDR6__VTX_AOS_ADDR6_MASK              0xfffffffcL

// VAP_VTX_AOS_ADDR7
#define VAP_VTX_AOS_ADDR7__VTX_AOS_ADDR7_MASK              0xfffffffcL

// VAP_VTX_AOS_ATTR89
#define VAP_VTX_AOS_ATTR89__VTX_AOS_COUNT8_MASK            0x0000007fL
#define VAP_VTX_AOS_ATTR89__VTX_AOS_STRIDE8_MASK           0x00007f00L
#define VAP_VTX_AOS_ATTR89__VTX_AOS_COUNT9_MASK            0x007f0000L
#define VAP_VTX_AOS_ATTR89__VTX_AOS_STRIDE9_MASK           0x7f000000L

// VAP_VTX_AOS_ADDR8
#define VAP_VTX_AOS_ADDR8__VTX_AOS_ADDR8_MASK              0xfffffffcL

// VAP_VTX_AOS_ADDR9
#define VAP_VTX_AOS_ADDR9__VTX_AOS_ADDR9_MASK              0xfffffffcL

// VAP_VTX_AOS_ATTR1011
#define VAP_VTX_AOS_ATTR1011__VTX_AOS_COUNT10_MASK         0x0000007fL
#define VAP_VTX_AOS_ATTR1011__VTX_AOS_STRIDE10_MASK        0x00007f00L
#define VAP_VTX_AOS_ATTR1011__VTX_AOS_COUNT11_MASK         0x007f0000L
#define VAP_VTX_AOS_ATTR1011__VTX_AOS_STRIDE11_MASK        0x7f000000L

// VAP_VTX_AOS_ADDR10
#define VAP_VTX_AOS_ADDR10__VTX_AOS_ADDR10_MASK            0xfffffffcL

// VAP_VTX_AOS_ADDR11
#define VAP_VTX_AOS_ADDR11__VTX_AOS_ADDR11_MASK            0xfffffffcL

// VAP_VTX_AOS_ATTR1213
#define VAP_VTX_AOS_ATTR1213__VTX_AOS_COUNT12_MASK         0x0000007fL
#define VAP_VTX_AOS_ATTR1213__VTX_AOS_STRIDE12_MASK        0x00007f00L
#define VAP_VTX_AOS_ATTR1213__VTX_AOS_COUNT13_MASK         0x007f0000L
#define VAP_VTX_AOS_ATTR1213__VTX_AOS_STRIDE13_MASK        0x7f000000L

// VAP_VTX_AOS_ADDR12
#define VAP_VTX_AOS_ADDR12__VTX_AOS_ADDR12_MASK            0xfffffffcL

// VAP_VTX_AOS_ADDR13
#define VAP_VTX_AOS_ADDR13__VTX_AOS_ADDR13_MASK            0xfffffffcL

// VAP_VTX_AOS_ATTR1415
#define VAP_VTX_AOS_ATTR1415__VTX_AOS_COUNT14_MASK         0x0000007fL
#define VAP_VTX_AOS_ATTR1415__VTX_AOS_STRIDE14_MASK        0x00007f00L
#define VAP_VTX_AOS_ATTR1415__VTX_AOS_COUNT15_MASK         0x007f0000L
#define VAP_VTX_AOS_ATTR1415__VTX_AOS_STRIDE15_MASK        0x7f000000L

// VAP_VTX_AOS_ADDR14
#define VAP_VTX_AOS_ADDR14__VTX_AOS_ADDR14_MASK            0xfffffffcL

// VAP_VTX_AOS_ADDR15
#define VAP_VTX_AOS_ADDR15__VTX_AOS_ADDR15_MASK            0xfffffffcL

// VAP_PERF_CNTL_0
#define VAP_PERF_CNTL_0__PERF_SEL_0_MASK                   0x0000000fL
#define VAP_PERF_CNTL_0__CLR_PERF_0_MASK                   0x00000010L
#define VAP_PERF_CNTL_0__CLR_PERF_0                        0x00000010L
#define VAP_PERF_CNTL_0__EN_PERF_0_MASK                    0x00000020L
#define VAP_PERF_CNTL_0__EN_PERF_0                         0x00000020L
#define VAP_PERF_CNTL_0__NUM_VERTS_TO_BYPASS_0_MASK        0x0000ff00L
#define VAP_PERF_CNTL_0__NUM_VERTS_TO_COUNT_0_MASK         0xffff0000L

// VAP_PERF_CNTL_1
#define VAP_PERF_CNTL_1__PERF_SEL_1_MASK                   0x0000000fL
#define VAP_PERF_CNTL_1__CLR_PERF_1_MASK                   0x00000010L
#define VAP_PERF_CNTL_1__CLR_PERF_1                        0x00000010L
#define VAP_PERF_CNTL_1__EN_PERF_1_MASK                    0x00000020L
#define VAP_PERF_CNTL_1__EN_PERF_1                         0x00000020L
#define VAP_PERF_CNTL_1__NUM_VERTS_TO_BYPASS_1_MASK        0x0000ff00L
#define VAP_PERF_CNTL_1__NUM_VERTS_TO_COUNT_1_MASK         0xffff0000L

// VAP_PERF_COUNT_0
#define VAP_PERF_COUNT_0__PERF_COUNT_0_MASK                0xffffffffL

// VAP_PERF_COUNT_1
#define VAP_PERF_COUNT_1__PERF_COUNT_1_MASK                0xffffffffL

// VAP_VF_MAX_VTX_INDX
#define VAP_VF_MAX_VTX_INDX__MAX_INDX_MASK                 0x00ffffffL

// VAP_VF_MIN_VTX_INDX
#define VAP_VF_MIN_VTX_INDX__MIN_INDX_MASK                 0x00ffffffL

// VAP_DEBUG
#define VAP_DEBUG__VC_DIS_2OW_PERF_MASK                    0x00000001L
#define VAP_DEBUG__VC_DIS_2OW_PERF                         0x00000001L
#define VAP_DEBUG__DEBUG_BITS_MASK                         0xfffffffeL

// VAP_CNTL_STATUS
#define VAP_CNTL_STATUS__VC_SWAP_MASK                      0x00000003L
#define VAP_CNTL_STATUS__PVS_BYPASS_MASK                   0x00000100L
#define VAP_CNTL_STATUS__PVS_BYPASS                        0x00000100L
#define VAP_CNTL_STATUS__PVS_BUSY_MASK                     0x00000800L
#define VAP_CNTL_STATUS__PVS_BUSY                          0x00000800L
#define VAP_CNTL_STATUS__VS_BUSY_MASK                      0x01000000L
#define VAP_CNTL_STATUS__VS_BUSY                           0x01000000L
#define VAP_CNTL_STATUS__RCP_BUSY_MASK                     0x02000000L
#define VAP_CNTL_STATUS__RCP_BUSY                          0x02000000L
#define VAP_CNTL_STATUS__VTE_BUSY_MASK                     0x04000000L
#define VAP_CNTL_STATUS__VTE_BUSY                          0x04000000L
#define VAP_CNTL_STATUS__MIU_BUSY_MASK                     0x08000000L
#define VAP_CNTL_STATUS__MIU_BUSY                          0x08000000L
#define VAP_CNTL_STATUS__VC_BUSY_MASK                      0x10000000L
#define VAP_CNTL_STATUS__VC_BUSY                           0x10000000L
#define VAP_CNTL_STATUS__VF_BUSY_MASK                      0x20000000L
#define VAP_CNTL_STATUS__VF_BUSY                           0x20000000L
#define VAP_CNTL_STATUS__REGPIPE_BUSY_MASK                 0x40000000L
#define VAP_CNTL_STATUS__REGPIPE_BUSY                      0x40000000L
#define VAP_CNTL_STATUS__VAP_BUSY_MASK                     0x80000000L
#define VAP_CNTL_STATUS__VAP_BUSY                          0x80000000L

// VAP_PERF_CNTL_2
#define VAP_PERF_CNTL_2__PERF_SEL_2_MASK                   0x0000000fL
#define VAP_PERF_CNTL_2__CLR_PERF_2_MASK                   0x00000010L
#define VAP_PERF_CNTL_2__CLR_PERF_2                        0x00000010L
#define VAP_PERF_CNTL_2__EN_PERF_2_MASK                    0x00000020L
#define VAP_PERF_CNTL_2__EN_PERF_2                         0x00000020L
#define VAP_PERF_CNTL_2__NUM_VERTS_TO_BYPASS_2_MASK        0x0000ff00L
#define VAP_PERF_CNTL_2__NUM_VERTS_TO_COUNT_2_MASK         0xffff0000L

// VAP_PERF_COUNT_2
#define VAP_PERF_COUNT_2__PERF_COUNT_2_MASK                0xffffffffL

// VAP_PROG_STREAM_CNTL_0
#define VAP_PROG_STREAM_CNTL_0__DATA_TYPE_0_MASK           0x0000000fL
#define VAP_PROG_STREAM_CNTL_0__SKIP_DWORDS_0_MASK         0x000000f0L
#define VAP_PROG_STREAM_CNTL_0__DST_VEC_LOC_0_MASK         0x00001f00L
#define VAP_PROG_STREAM_CNTL_0__LAST_VEC_0_MASK            0x00002000L
#define VAP_PROG_STREAM_CNTL_0__LAST_VEC_0                 0x00002000L
#define VAP_PROG_STREAM_CNTL_0__SIGNED_0_MASK              0x00004000L
#define VAP_PROG_STREAM_CNTL_0__SIGNED_0                   0x00004000L
#define VAP_PROG_STREAM_CNTL_0__NORMALIZE_0_MASK           0x00008000L
#define VAP_PROG_STREAM_CNTL_0__NORMALIZE_0                0x00008000L
#define VAP_PROG_STREAM_CNTL_0__DATA_TYPE_1_MASK           0x000f0000L
#define VAP_PROG_STREAM_CNTL_0__SKIP_DWORDS_1_MASK         0x00f00000L
#define VAP_PROG_STREAM_CNTL_0__DST_VEC_LOC_1_MASK         0x1f000000L
#define VAP_PROG_STREAM_CNTL_0__LAST_VEC_1_MASK            0x20000000L
#define VAP_PROG_STREAM_CNTL_0__LAST_VEC_1                 0x20000000L
#define VAP_PROG_STREAM_CNTL_0__SIGNED_1_MASK              0x40000000L
#define VAP_PROG_STREAM_CNTL_0__SIGNED_1                   0x40000000L
#define VAP_PROG_STREAM_CNTL_0__NORMALIZE_1_MASK           0x80000000L
#define VAP_PROG_STREAM_CNTL_0__NORMALIZE_1                0x80000000L

// VAP_PROG_STREAM_CNTL_1
#define VAP_PROG_STREAM_CNTL_1__DATA_TYPE_2_MASK           0x0000000fL
#define VAP_PROG_STREAM_CNTL_1__SKIP_DWORDS_2_MASK         0x000000f0L
#define VAP_PROG_STREAM_CNTL_1__DST_VEC_LOC_2_MASK         0x00001f00L
#define VAP_PROG_STREAM_CNTL_1__LAST_VEC_2_MASK            0x00002000L
#define VAP_PROG_STREAM_CNTL_1__LAST_VEC_2                 0x00002000L
#define VAP_PROG_STREAM_CNTL_1__SIGNED_2_MASK              0x00004000L
#define VAP_PROG_STREAM_CNTL_1__SIGNED_2                   0x00004000L
#define VAP_PROG_STREAM_CNTL_1__NORMALIZE_2_MASK           0x00008000L
#define VAP_PROG_STREAM_CNTL_1__NORMALIZE_2                0x00008000L
#define VAP_PROG_STREAM_CNTL_1__DATA_TYPE_3_MASK           0x000f0000L
#define VAP_PROG_STREAM_CNTL_1__SKIP_DWORDS_3_MASK         0x00f00000L
#define VAP_PROG_STREAM_CNTL_1__DST_VEC_LOC_3_MASK         0x1f000000L
#define VAP_PROG_STREAM_CNTL_1__LAST_VEC_3_MASK            0x20000000L
#define VAP_PROG_STREAM_CNTL_1__LAST_VEC_3                 0x20000000L
#define VAP_PROG_STREAM_CNTL_1__SIGNED_3_MASK              0x40000000L
#define VAP_PROG_STREAM_CNTL_1__SIGNED_3                   0x40000000L
#define VAP_PROG_STREAM_CNTL_1__NORMALIZE_3_MASK           0x80000000L
#define VAP_PROG_STREAM_CNTL_1__NORMALIZE_3                0x80000000L

// VAP_PROG_STREAM_CNTL_2
#define VAP_PROG_STREAM_CNTL_2__DATA_TYPE_4_MASK           0x0000000fL
#define VAP_PROG_STREAM_CNTL_2__SKIP_DWORDS_4_MASK         0x000000f0L
#define VAP_PROG_STREAM_CNTL_2__DST_VEC_LOC_4_MASK         0x00001f00L
#define VAP_PROG_STREAM_CNTL_2__LAST_VEC_4_MASK            0x00002000L
#define VAP_PROG_STREAM_CNTL_2__LAST_VEC_4                 0x00002000L
#define VAP_PROG_STREAM_CNTL_2__SIGNED_4_MASK              0x00004000L
#define VAP_PROG_STREAM_CNTL_2__SIGNED_4                   0x00004000L
#define VAP_PROG_STREAM_CNTL_2__NORMALIZE_4_MASK           0x00008000L
#define VAP_PROG_STREAM_CNTL_2__NORMALIZE_4                0x00008000L
#define VAP_PROG_STREAM_CNTL_2__DATA_TYPE_5_MASK           0x000f0000L
#define VAP_PROG_STREAM_CNTL_2__SKIP_DWORDS_5_MASK         0x00f00000L
#define VAP_PROG_STREAM_CNTL_2__DST_VEC_LOC_5_MASK         0x1f000000L
#define VAP_PROG_STREAM_CNTL_2__LAST_VEC_5_MASK            0x20000000L
#define VAP_PROG_STREAM_CNTL_2__LAST_VEC_5                 0x20000000L
#define VAP_PROG_STREAM_CNTL_2__SIGNED_5_MASK              0x40000000L
#define VAP_PROG_STREAM_CNTL_2__SIGNED_5                   0x40000000L
#define VAP_PROG_STREAM_CNTL_2__NORMALIZE_5_MASK           0x80000000L
#define VAP_PROG_STREAM_CNTL_2__NORMALIZE_5                0x80000000L

// VAP_PROG_STREAM_CNTL_3
#define VAP_PROG_STREAM_CNTL_3__DATA_TYPE_6_MASK           0x0000000fL
#define VAP_PROG_STREAM_CNTL_3__SKIP_DWORDS_6_MASK         0x000000f0L
#define VAP_PROG_STREAM_CNTL_3__DST_VEC_LOC_6_MASK         0x00001f00L
#define VAP_PROG_STREAM_CNTL_3__LAST_VEC_6_MASK            0x00002000L
#define VAP_PROG_STREAM_CNTL_3__LAST_VEC_6                 0x00002000L
#define VAP_PROG_STREAM_CNTL_3__SIGNED_6_MASK              0x00004000L
#define VAP_PROG_STREAM_CNTL_3__SIGNED_6                   0x00004000L
#define VAP_PROG_STREAM_CNTL_3__NORMALIZE_6_MASK           0x00008000L
#define VAP_PROG_STREAM_CNTL_3__NORMALIZE_6                0x00008000L
#define VAP_PROG_STREAM_CNTL_3__DATA_TYPE_7_MASK           0x000f0000L
#define VAP_PROG_STREAM_CNTL_3__SKIP_DWORDS_7_MASK         0x00f00000L
#define VAP_PROG_STREAM_CNTL_3__DST_VEC_LOC_7_MASK         0x1f000000L
#define VAP_PROG_STREAM_CNTL_3__LAST_VEC_7_MASK            0x20000000L
#define VAP_PROG_STREAM_CNTL_3__LAST_VEC_7                 0x20000000L
#define VAP_PROG_STREAM_CNTL_3__SIGNED_7_MASK              0x40000000L
#define VAP_PROG_STREAM_CNTL_3__SIGNED_7                   0x40000000L
#define VAP_PROG_STREAM_CNTL_3__NORMALIZE_7_MASK           0x80000000L
#define VAP_PROG_STREAM_CNTL_3__NORMALIZE_7                0x80000000L

// VAP_PROG_STREAM_CNTL_4
#define VAP_PROG_STREAM_CNTL_4__DATA_TYPE_8_MASK           0x0000000fL
#define VAP_PROG_STREAM_CNTL_4__SKIP_DWORDS_8_MASK         0x000000f0L
#define VAP_PROG_STREAM_CNTL_4__DST_VEC_LOC_8_MASK         0x00001f00L
#define VAP_PROG_STREAM_CNTL_4__LAST_VEC_8_MASK            0x00002000L
#define VAP_PROG_STREAM_CNTL_4__LAST_VEC_8                 0x00002000L
#define VAP_PROG_STREAM_CNTL_4__SIGNED_8_MASK              0x00004000L
#define VAP_PROG_STREAM_CNTL_4__SIGNED_8                   0x00004000L
#define VAP_PROG_STREAM_CNTL_4__NORMALIZE_8_MASK           0x00008000L
#define VAP_PROG_STREAM_CNTL_4__NORMALIZE_8                0x00008000L
#define VAP_PROG_STREAM_CNTL_4__DATA_TYPE_9_MASK           0x000f0000L
#define VAP_PROG_STREAM_CNTL_4__SKIP_DWORDS_9_MASK         0x00f00000L
#define VAP_PROG_STREAM_CNTL_4__DST_VEC_LOC_9_MASK         0x1f000000L
#define VAP_PROG_STREAM_CNTL_4__LAST_VEC_9_MASK            0x20000000L
#define VAP_PROG_STREAM_CNTL_4__LAST_VEC_9                 0x20000000L
#define VAP_PROG_STREAM_CNTL_4__SIGNED_9_MASK              0x40000000L
#define VAP_PROG_STREAM_CNTL_4__SIGNED_9                   0x40000000L
#define VAP_PROG_STREAM_CNTL_4__NORMALIZE_9_MASK           0x80000000L
#define VAP_PROG_STREAM_CNTL_4__NORMALIZE_9                0x80000000L

// VAP_PROG_STREAM_CNTL_5
#define VAP_PROG_STREAM_CNTL_5__DATA_TYPE_10_MASK          0x0000000fL
#define VAP_PROG_STREAM_CNTL_5__SKIP_DWORDS_10_MASK        0x000000f0L
#define VAP_PROG_STREAM_CNTL_5__DST_VEC_LOC_10_MASK        0x00001f00L
#define VAP_PROG_STREAM_CNTL_5__LAST_VEC_10_MASK           0x00002000L
#define VAP_PROG_STREAM_CNTL_5__LAST_VEC_10                0x00002000L
#define VAP_PROG_STREAM_CNTL_5__SIGNED_10_MASK             0x00004000L
#define VAP_PROG_STREAM_CNTL_5__SIGNED_10                  0x00004000L
#define VAP_PROG_STREAM_CNTL_5__NORMALIZE_10_MASK          0x00008000L
#define VAP_PROG_STREAM_CNTL_5__NORMALIZE_10               0x00008000L
#define VAP_PROG_STREAM_CNTL_5__DATA_TYPE_11_MASK          0x000f0000L
#define VAP_PROG_STREAM_CNTL_5__SKIP_DWORDS_11_MASK        0x00f00000L
#define VAP_PROG_STREAM_CNTL_5__DST_VEC_LOC_11_MASK        0x1f000000L
#define VAP_PROG_STREAM_CNTL_5__LAST_VEC_11_MASK           0x20000000L
#define VAP_PROG_STREAM_CNTL_5__LAST_VEC_11                0x20000000L
#define VAP_PROG_STREAM_CNTL_5__SIGNED_11_MASK             0x40000000L
#define VAP_PROG_STREAM_CNTL_5__SIGNED_11                  0x40000000L
#define VAP_PROG_STREAM_CNTL_5__NORMALIZE_11_MASK          0x80000000L
#define VAP_PROG_STREAM_CNTL_5__NORMALIZE_11               0x80000000L

// VAP_PROG_STREAM_CNTL_6
#define VAP_PROG_STREAM_CNTL_6__DATA_TYPE_12_MASK          0x0000000fL
#define VAP_PROG_STREAM_CNTL_6__SKIP_DWORDS_12_MASK        0x000000f0L
#define VAP_PROG_STREAM_CNTL_6__DST_VEC_LOC_12_MASK        0x00001f00L
#define VAP_PROG_STREAM_CNTL_6__LAST_VEC_12_MASK           0x00002000L
#define VAP_PROG_STREAM_CNTL_6__LAST_VEC_12                0x00002000L
#define VAP_PROG_STREAM_CNTL_6__SIGNED_12_MASK             0x00004000L
#define VAP_PROG_STREAM_CNTL_6__SIGNED_12                  0x00004000L
#define VAP_PROG_STREAM_CNTL_6__NORMALIZE_12_MASK          0x00008000L
#define VAP_PROG_STREAM_CNTL_6__NORMALIZE_12               0x00008000L
#define VAP_PROG_STREAM_CNTL_6__DATA_TYPE_13_MASK          0x000f0000L
#define VAP_PROG_STREAM_CNTL_6__SKIP_DWORDS_13_MASK        0x00f00000L
#define VAP_PROG_STREAM_CNTL_6__DST_VEC_LOC_13_MASK        0x1f000000L
#define VAP_PROG_STREAM_CNTL_6__LAST_VEC_13_MASK           0x20000000L
#define VAP_PROG_STREAM_CNTL_6__LAST_VEC_13                0x20000000L
#define VAP_PROG_STREAM_CNTL_6__SIGNED_13_MASK             0x40000000L
#define VAP_PROG_STREAM_CNTL_6__SIGNED_13                  0x40000000L
#define VAP_PROG_STREAM_CNTL_6__NORMALIZE_13_MASK          0x80000000L
#define VAP_PROG_STREAM_CNTL_6__NORMALIZE_13               0x80000000L

// VAP_PROG_STREAM_CNTL_7
#define VAP_PROG_STREAM_CNTL_7__DATA_TYPE_14_MASK          0x0000000fL
#define VAP_PROG_STREAM_CNTL_7__SKIP_DWORDS_14_MASK        0x000000f0L
#define VAP_PROG_STREAM_CNTL_7__DST_VEC_LOC_14_MASK        0x00001f00L
#define VAP_PROG_STREAM_CNTL_7__LAST_VEC_14_MASK           0x00002000L
#define VAP_PROG_STREAM_CNTL_7__LAST_VEC_14                0x00002000L
#define VAP_PROG_STREAM_CNTL_7__SIGNED_14_MASK             0x00004000L
#define VAP_PROG_STREAM_CNTL_7__SIGNED_14                  0x00004000L
#define VAP_PROG_STREAM_CNTL_7__NORMALIZE_14_MASK          0x00008000L
#define VAP_PROG_STREAM_CNTL_7__NORMALIZE_14               0x00008000L
#define VAP_PROG_STREAM_CNTL_7__DATA_TYPE_15_MASK          0x000f0000L
#define VAP_PROG_STREAM_CNTL_7__SKIP_DWORDS_15_MASK        0x00f00000L
#define VAP_PROG_STREAM_CNTL_7__DST_VEC_LOC_15_MASK        0x1f000000L
#define VAP_PROG_STREAM_CNTL_7__LAST_VEC_15_MASK           0x20000000L
#define VAP_PROG_STREAM_CNTL_7__LAST_VEC_15                0x20000000L
#define VAP_PROG_STREAM_CNTL_7__SIGNED_15_MASK             0x40000000L
#define VAP_PROG_STREAM_CNTL_7__SIGNED_15                  0x40000000L
#define VAP_PROG_STREAM_CNTL_7__NORMALIZE_15_MASK          0x80000000L
#define VAP_PROG_STREAM_CNTL_7__NORMALIZE_15               0x80000000L

// VAP_VTX_STATE_CNTL
#define VAP_VTX_STATE_CNTL__COLOR_0_ASSEMBLY_CNTL_MASK     0x00000003L
#define VAP_VTX_STATE_CNTL__COLOR_1_ASSEMBLY_CNTL_MASK     0x0000000cL
#define VAP_VTX_STATE_CNTL__COLOR_2_ASSEMBLY_CNTL_MASK     0x00000030L
#define VAP_VTX_STATE_CNTL__COLOR_3_ASSEMBLY_CNTL_MASK     0x000000c0L
#define VAP_VTX_STATE_CNTL__COLOR_4_ASSEMBLY_CNTL_MASK     0x00000300L
#define VAP_VTX_STATE_CNTL__COLOR_5_ASSEMBLY_CNTL_MASK     0x00000c00L
#define VAP_VTX_STATE_CNTL__COLOR_6_ASSEMBLY_CNTL_MASK     0x00003000L
#define VAP_VTX_STATE_CNTL__COLOR_7_ASSEMBLY_CNTL_MASK     0x0000c000L
#define VAP_VTX_STATE_CNTL__UPDATE_USER_COLOR_0_ENA_MASK   0x00010000L
#define VAP_VTX_STATE_CNTL__UPDATE_USER_COLOR_0_ENA        0x00010000L
#define VAP_VTX_STATE_CNTL__USE_ADDR_IND_TBL_MASK          0x00040000L
#define VAP_VTX_STATE_CNTL__USE_ADDR_IND_TBL               0x00040000L

// VAP_VSM_VTX_ASSM
#define VAP_VSM_VTX_ASSM__OUTPUT_VEC_CNTL_MASK             0x003fffffL

// VAP_VTX_STATE_IND_REG_0
#define VAP_VTX_STATE_IND_REG_0__ADDR_0_MASK               0x0000007fL
#define VAP_VTX_STATE_IND_REG_0__ADDR_1_MASK               0x00007f00L
#define VAP_VTX_STATE_IND_REG_0__ADDR_2_MASK               0x007f0000L
#define VAP_VTX_STATE_IND_REG_0__ADDR_3_MASK               0x7f000000L

// VAP_VTX_STATE_IND_REG_1
#define VAP_VTX_STATE_IND_REG_1__ADDR_4_MASK               0x0000007fL
#define VAP_VTX_STATE_IND_REG_1__ADDR_5_MASK               0x00007f00L
#define VAP_VTX_STATE_IND_REG_1__ADDR_6_MASK               0x007f0000L
#define VAP_VTX_STATE_IND_REG_1__ADDR_7_MASK               0x7f000000L

// VAP_VTX_STATE_IND_REG_2
#define VAP_VTX_STATE_IND_REG_2__ADDR_8_MASK               0x0000007fL
#define VAP_VTX_STATE_IND_REG_2__ADDR_9_MASK               0x00007f00L
#define VAP_VTX_STATE_IND_REG_2__ADDR_10_MASK              0x007f0000L
#define VAP_VTX_STATE_IND_REG_2__ADDR_11_MASK              0x7f000000L

// VAP_VTX_STATE_IND_REG_3
#define VAP_VTX_STATE_IND_REG_3__ADDR_12_MASK              0x0000007fL
#define VAP_VTX_STATE_IND_REG_3__ADDR_13_MASK              0x00007f00L
#define VAP_VTX_STATE_IND_REG_3__ADDR_14_MASK              0x007f0000L
#define VAP_VTX_STATE_IND_REG_3__ADDR_15_MASK              0x7f000000L

// VAP_VTX_STATE_IND_REG_4
#define VAP_VTX_STATE_IND_REG_4__ADDR_16_MASK              0x0000007fL
#define VAP_VTX_STATE_IND_REG_4__ADDR_17_MASK              0x00007f00L
#define VAP_VTX_STATE_IND_REG_4__ADDR_18_MASK              0x007f0000L
#define VAP_VTX_STATE_IND_REG_4__ADDR_19_MASK              0x7f000000L

// VAP_VTX_STATE_IND_REG_5
#define VAP_VTX_STATE_IND_REG_5__ADDR_20_MASK              0x0000007fL
#define VAP_VTX_STATE_IND_REG_5__ADDR_21_MASK              0x00007f00L
#define VAP_VTX_STATE_IND_REG_5__ADDR_22_MASK              0x007f0000L
#define VAP_VTX_STATE_IND_REG_5__ADDR_23_MASK              0x7f000000L

// VAP_VTX_STATE_IND_REG_6
#define VAP_VTX_STATE_IND_REG_6__ADDR_24_MASK              0x0000007fL
#define VAP_VTX_STATE_IND_REG_6__ADDR_25_MASK              0x00007f00L
#define VAP_VTX_STATE_IND_REG_6__ADDR_26_MASK              0x007f0000L
#define VAP_VTX_STATE_IND_REG_6__ADDR_27_MASK              0x7f000000L

// VAP_VTX_STATE_IND_REG_7
#define VAP_VTX_STATE_IND_REG_7__ADDR_28_MASK              0x0000007fL
#define VAP_VTX_STATE_IND_REG_7__ADDR_29_MASK              0x00007f00L
#define VAP_VTX_STATE_IND_REG_7__ADDR_30_MASK              0x007f0000L
#define VAP_VTX_STATE_IND_REG_7__ADDR_31_MASK              0x7f000000L

// VAP_VTX_STATE_IND_REG_8
#define VAP_VTX_STATE_IND_REG_8__ADDR_32_MASK              0x0000007fL
#define VAP_VTX_STATE_IND_REG_8__ADDR_33_MASK              0x00007f00L
#define VAP_VTX_STATE_IND_REG_8__ADDR_34_MASK              0x007f0000L
#define VAP_VTX_STATE_IND_REG_8__ADDR_35_MASK              0x7f000000L

// VAP_VTX_STATE_IND_REG_9
#define VAP_VTX_STATE_IND_REG_9__ADDR_36_MASK              0x0000007fL
#define VAP_VTX_STATE_IND_REG_9__ADDR_37_MASK              0x00007f00L
#define VAP_VTX_STATE_IND_REG_9__ADDR_38_MASK              0x007f0000L
#define VAP_VTX_STATE_IND_REG_9__ADDR_39_MASK              0x7f000000L

// VAP_VTX_STATE_IND_REG_10
#define VAP_VTX_STATE_IND_REG_10__ADDR_40_MASK             0x0000007fL
#define VAP_VTX_STATE_IND_REG_10__ADDR_41_MASK             0x00007f00L
#define VAP_VTX_STATE_IND_REG_10__ADDR_42_MASK             0x007f0000L
#define VAP_VTX_STATE_IND_REG_10__ADDR_43_MASK             0x7f000000L

// VAP_VTX_STATE_IND_REG_11
#define VAP_VTX_STATE_IND_REG_11__ADDR_44_MASK             0x0000007fL
#define VAP_VTX_STATE_IND_REG_11__ADDR_45_MASK             0x00007f00L
#define VAP_VTX_STATE_IND_REG_11__ADDR_46_MASK             0x007f0000L
#define VAP_VTX_STATE_IND_REG_11__ADDR_47_MASK             0x7f000000L

// VAP_VTX_STATE_IND_REG_12
#define VAP_VTX_STATE_IND_REG_12__ADDR_48_MASK             0x0000007fL
#define VAP_VTX_STATE_IND_REG_12__ADDR_49_MASK             0x00007f00L
#define VAP_VTX_STATE_IND_REG_12__ADDR_50_MASK             0x007f0000L
#define VAP_VTX_STATE_IND_REG_12__ADDR_51_MASK             0x7f000000L

// VAP_VTX_STATE_IND_REG_13
#define VAP_VTX_STATE_IND_REG_13__ADDR_52_MASK             0x0000007fL
#define VAP_VTX_STATE_IND_REG_13__ADDR_53_MASK             0x00007f00L
#define VAP_VTX_STATE_IND_REG_13__ADDR_54_MASK             0x007f0000L
#define VAP_VTX_STATE_IND_REG_13__ADDR_55_MASK             0x7f000000L

// VAP_VTX_STATE_IND_REG_14
#define VAP_VTX_STATE_IND_REG_14__ADDR_56_MASK             0x0000007fL
#define VAP_VTX_STATE_IND_REG_14__ADDR_57_MASK             0x00007f00L
#define VAP_VTX_STATE_IND_REG_14__ADDR_58_MASK             0x007f0000L
#define VAP_VTX_STATE_IND_REG_14__ADDR_59_MASK             0x7f000000L

// VAP_VTX_STATE_IND_REG_15
#define VAP_VTX_STATE_IND_REG_15__ADDR_60_MASK             0x0000007fL
#define VAP_VTX_STATE_IND_REG_15__ADDR_61_MASK             0x00007f00L
#define VAP_VTX_STATE_IND_REG_15__ADDR_62_MASK             0x007f0000L
#define VAP_VTX_STATE_IND_REG_15__ADDR_63_MASK             0x7f000000L

// VAP_PSC_SGN_NORM_CNTL
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_0_MASK      0x00000003L
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_1_MASK      0x0000000cL
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_2_MASK      0x00000030L
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_3_MASK      0x000000c0L
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_4_MASK      0x00000300L
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_5_MASK      0x00000c00L
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_6_MASK      0x00003000L
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_7_MASK      0x0000c000L
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_8_MASK      0x00030000L
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_9_MASK      0x000c0000L
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_10_MASK     0x00300000L
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_11_MASK     0x00c00000L
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_12_MASK     0x03000000L
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_13_MASK     0x0c000000L
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_14_MASK     0x30000000L
#define VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_15_MASK     0xc0000000L

// VAP_PROG_STREAM_CNTL_EXT_0
#define VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_X_0_MASK 0x00000007L
#define VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_Y_0_MASK 0x00000038L
#define VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_Z_0_MASK 0x000001c0L
#define VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_W_0_MASK 0x00000e00L
#define VAP_PROG_STREAM_CNTL_EXT_0__WRITE_ENA_0_MASK       0x0000f000L
#define VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_X_1_MASK 0x00070000L
#define VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_Y_1_MASK 0x00380000L
#define VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_Z_1_MASK 0x01c00000L
#define VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_W_1_MASK 0x0e000000L
#define VAP_PROG_STREAM_CNTL_EXT_0__WRITE_ENA_1_MASK       0xf0000000L

// VAP_PROG_STREAM_CNTL_EXT_1
#define VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_X_2_MASK 0x00000007L
#define VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_Y_2_MASK 0x00000038L
#define VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_Z_2_MASK 0x000001c0L
#define VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_W_2_MASK 0x00000e00L
#define VAP_PROG_STREAM_CNTL_EXT_1__WRITE_ENA_2_MASK       0x0000f000L
#define VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_X_3_MASK 0x00070000L
#define VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_Y_3_MASK 0x00380000L
#define VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_Z_3_MASK 0x01c00000L
#define VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_W_3_MASK 0x0e000000L
#define VAP_PROG_STREAM_CNTL_EXT_1__WRITE_ENA_3_MASK       0xf0000000L

// VAP_PROG_STREAM_CNTL_EXT_2
#define VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_X_4_MASK 0x00000007L
#define VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_Y_4_MASK 0x00000038L
#define VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_Z_4_MASK 0x000001c0L
#define VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_W_4_MASK 0x00000e00L
#define VAP_PROG_STREAM_CNTL_EXT_2__WRITE_ENA_4_MASK       0x0000f000L
#define VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_X_5_MASK 0x00070000L
#define VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_Y_5_MASK 0x00380000L
#define VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_Z_5_MASK 0x01c00000L
#define VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_W_5_MASK 0x0e000000L
#define VAP_PROG_STREAM_CNTL_EXT_2__WRITE_ENA_5_MASK       0xf0000000L

// VAP_PROG_STREAM_CNTL_EXT_3
#define VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_X_6_MASK 0x00000007L
#define VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_Y_6_MASK 0x00000038L
#define VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_Z_6_MASK 0x000001c0L
#define VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_W_6_MASK 0x00000e00L
#define VAP_PROG_STREAM_CNTL_EXT_3__WRITE_ENA_6_MASK       0x0000f000L
#define VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_X_7_MASK 0x00070000L
#define VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_Y_7_MASK 0x00380000L
#define VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_Z_7_MASK 0x01c00000L
#define VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_W_7_MASK 0x0e000000L
#define VAP_PROG_STREAM_CNTL_EXT_3__WRITE_ENA_7_MASK       0xf0000000L

// VAP_PROG_STREAM_CNTL_EXT_4
#define VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_X_8_MASK 0x00000007L
#define VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_Y_8_MASK 0x00000038L
#define VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_Z_8_MASK 0x000001c0L
#define VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_W_8_MASK 0x00000e00L
#define VAP_PROG_STREAM_CNTL_EXT_4__WRITE_ENA_8_MASK       0x0000f000L
#define VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_X_9_MASK 0x00070000L
#define VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_Y_9_MASK 0x00380000L
#define VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_Z_9_MASK 0x01c00000L
#define VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_W_9_MASK 0x0e000000L
#define VAP_PROG_STREAM_CNTL_EXT_4__WRITE_ENA_9_MASK       0xf0000000L

// VAP_PROG_STREAM_CNTL_EXT_5
#define VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_X_10_MASK 0x00000007L
#define VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_Y_10_MASK 0x00000038L
#define VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_Z_10_MASK 0x000001c0L
#define VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_W_10_MASK 0x00000e00L
#define VAP_PROG_STREAM_CNTL_EXT_5__WRITE_ENA_10_MASK      0x0000f000L
#define VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_X_11_MASK 0x00070000L
#define VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_Y_11_MASK 0x00380000L
#define VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_Z_11_MASK 0x01c00000L
#define VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_W_11_MASK 0x0e000000L
#define VAP_PROG_STREAM_CNTL_EXT_5__WRITE_ENA_11_MASK      0xf0000000L

// VAP_PROG_STREAM_CNTL_EXT_6
#define VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_X_12_MASK 0x00000007L
#define VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_Y_12_MASK 0x00000038L
#define VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_Z_12_MASK 0x000001c0L
#define VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_W_12_MASK 0x00000e00L
#define VAP_PROG_STREAM_CNTL_EXT_6__WRITE_ENA_12_MASK      0x0000f000L
#define VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_X_13_MASK 0x00070000L
#define VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_Y_13_MASK 0x00380000L
#define VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_Z_13_MASK 0x01c00000L
#define VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_W_13_MASK 0x0e000000L
#define VAP_PROG_STREAM_CNTL_EXT_6__WRITE_ENA_13_MASK      0xf0000000L

// VAP_PROG_STREAM_CNTL_EXT_7
#define VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_X_14_MASK 0x00000007L
#define VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_Y_14_MASK 0x00000038L
#define VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_Z_14_MASK 0x000001c0L
#define VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_W_14_MASK 0x00000e00L
#define VAP_PROG_STREAM_CNTL_EXT_7__WRITE_ENA_14_MASK      0x0000f000L
#define VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_X_15_MASK 0x00070000L
#define VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_Y_15_MASK 0x00380000L
#define VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_Z_15_MASK 0x01c00000L
#define VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_W_15_MASK 0x0e000000L
#define VAP_PROG_STREAM_CNTL_EXT_7__WRITE_ENA_15_MASK      0xf0000000L

// VAP_PVS_VECTOR_INDX_REG
#define VAP_PVS_VECTOR_INDX_REG__OCTWORD_OFFSET_MASK       0x000007ffL

// VAP_PVS_VECTOR_DATA_REG
#define VAP_PVS_VECTOR_DATA_REG__DATA_REGISTER_MASK        0xffffffffL

// VAP_PVS_VECTOR_DATA_REG_128
#define VAP_PVS_VECTOR_DATA_REG_128__DATA_REGISTER_MASK    0xffffffffL

// VAP_CLIP_CNTL
#define VAP_CLIP_CNTL__UCP_ENA_0_MASK                      0x00000001L
#define VAP_CLIP_CNTL__UCP_ENA_0                           0x00000001L
#define VAP_CLIP_CNTL__UCP_ENA_1_MASK                      0x00000002L
#define VAP_CLIP_CNTL__UCP_ENA_1                           0x00000002L
#define VAP_CLIP_CNTL__UCP_ENA_2_MASK                      0x00000004L
#define VAP_CLIP_CNTL__UCP_ENA_2                           0x00000004L
#define VAP_CLIP_CNTL__UCP_ENA_3_MASK                      0x00000008L
#define VAP_CLIP_CNTL__UCP_ENA_3                           0x00000008L
#define VAP_CLIP_CNTL__UCP_ENA_4_MASK                      0x00000010L
#define VAP_CLIP_CNTL__UCP_ENA_4                           0x00000010L
#define VAP_CLIP_CNTL__UCP_ENA_5_MASK                      0x00000020L
#define VAP_CLIP_CNTL__UCP_ENA_5                           0x00000020L
#define VAP_CLIP_CNTL__PS_UCP_MODE_MASK                    0x0000c000L
#define VAP_CLIP_CNTL__CLIP_DISABLE_MASK                   0x00010000L
#define VAP_CLIP_CNTL__CLIP_DISABLE                        0x00010000L
#define VAP_CLIP_CNTL__UCP_CULL_ONLY_ENA_MASK              0x00020000L
#define VAP_CLIP_CNTL__UCP_CULL_ONLY_ENA                   0x00020000L
#define VAP_CLIP_CNTL__BOUNDARY_EDGE_FLAG_ENA_MASK         0x00040000L
#define VAP_CLIP_CNTL__BOUNDARY_EDGE_FLAG_ENA              0x00040000L

// VAP_GB_VERT_CLIP_ADJ
#define VAP_GB_VERT_CLIP_ADJ__DATA_REGISTER_MASK           0xffffffffL

// VAP_GB_VERT_DISC_ADJ
#define VAP_GB_VERT_DISC_ADJ__DATA_REGISTER_MASK           0xffffffffL

// VAP_GB_HORZ_CLIP_ADJ
#define VAP_GB_HORZ_CLIP_ADJ__DATA_REGISTER_MASK           0xffffffffL

// VAP_GB_HORZ_DISC_ADJ
#define VAP_GB_HORZ_DISC_ADJ__DATA_REGISTER_MASK           0xffffffffL

// VAP_PVS_FLOW_CNTL_ADDRS_0
#define VAP_PVS_FLOW_CNTL_ADDRS_0__PVS_FC_ACT_ADRS_0_MASK  0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_0__PVS_FC_LOOP_CNT_JMP_INST_0_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_0__PVS_FC_LAST_INST_0_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_0__PVS_FC_RTN_INST_0_MASK  0xff000000L

// VAP_PVS_FLOW_CNTL_ADDRS_1
#define VAP_PVS_FLOW_CNTL_ADDRS_1__PVS_FC_ACT_ADRS_1_MASK  0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_1__PVS_FC_LOOP_CNT_JMP_INST_1_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_1__PVS_FC_LAST_INST_1_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_1__PVS_FC_RTN_INST_1_MASK  0xff000000L

// VAP_PVS_FLOW_CNTL_ADDRS_2
#define VAP_PVS_FLOW_CNTL_ADDRS_2__PVS_FC_ACT_ADRS_2_MASK  0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_2__PVS_FC_LOOP_CNT_JMP_INST_2_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_2__PVS_FC_LAST_INST_2_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_2__PVS_FC_RTN_INST_2_MASK  0xff000000L

// VAP_PVS_FLOW_CNTL_ADDRS_3
#define VAP_PVS_FLOW_CNTL_ADDRS_3__PVS_FC_ACT_ADRS_3_MASK  0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_3__PVS_FC_LOOP_CNT_JMP_INST_3_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_3__PVS_FC_LAST_INST_3_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_3__PVS_FC_RTN_INST_3_MASK  0xff000000L

// VAP_PVS_FLOW_CNTL_ADDRS_4
#define VAP_PVS_FLOW_CNTL_ADDRS_4__PVS_FC_ACT_ADRS_4_MASK  0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_4__PVS_FC_LOOP_CNT_JMP_INST_4_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_4__PVS_FC_LAST_INST_4_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_4__PVS_FC_RTN_INST_4_MASK  0xff000000L

// VAP_PVS_FLOW_CNTL_ADDRS_5
#define VAP_PVS_FLOW_CNTL_ADDRS_5__PVS_FC_ACT_ADRS_5_MASK  0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_5__PVS_FC_LOOP_CNT_JMP_INST_5_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_5__PVS_FC_LAST_INST_5_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_5__PVS_FC_RTN_INST_5_MASK  0xff000000L

// VAP_PVS_FLOW_CNTL_ADDRS_6
#define VAP_PVS_FLOW_CNTL_ADDRS_6__PVS_FC_ACT_ADRS_6_MASK  0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_6__PVS_FC_LOOP_CNT_JMP_INST_6_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_6__PVS_FC_LAST_INST_6_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_6__PVS_FC_RTN_INST_6_MASK  0xff000000L

// VAP_PVS_FLOW_CNTL_ADDRS_7
#define VAP_PVS_FLOW_CNTL_ADDRS_7__PVS_FC_ACT_ADRS_7_MASK  0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_7__PVS_FC_LOOP_CNT_JMP_INST_7_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_7__PVS_FC_LAST_INST_7_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_7__PVS_FC_RTN_INST_7_MASK  0xff000000L

// VAP_PVS_FLOW_CNTL_ADDRS_8
#define VAP_PVS_FLOW_CNTL_ADDRS_8__PVS_FC_ACT_ADRS_8_MASK  0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_8__PVS_FC_LOOP_CNT_JMP_INST_8_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_8__PVS_FC_LAST_INST_8_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_8__PVS_FC_RTN_INST_8_MASK  0xff000000L

// VAP_PVS_FLOW_CNTL_ADDRS_9
#define VAP_PVS_FLOW_CNTL_ADDRS_9__PVS_FC_ACT_ADRS_9_MASK  0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_9__PVS_FC_LOOP_CNT_JMP_INST_9_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_9__PVS_FC_LAST_INST_9_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_9__PVS_FC_RTN_INST_9_MASK  0xff000000L

// VAP_PVS_FLOW_CNTL_ADDRS_10
#define VAP_PVS_FLOW_CNTL_ADDRS_10__PVS_FC_ACT_ADRS_10_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_10__PVS_FC_LOOP_CNT_JMP_INST_10_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_10__PVS_FC_LAST_INST_10_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_10__PVS_FC_RTN_INST_10_MASK 0xff000000L

// VAP_PVS_FLOW_CNTL_ADDRS_11
#define VAP_PVS_FLOW_CNTL_ADDRS_11__PVS_FC_ACT_ADRS_11_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_11__PVS_FC_LOOP_CNT_JMP_INST_11_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_11__PVS_FC_LAST_INST_11_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_11__PVS_FC_RTN_INST_11_MASK 0xff000000L

// VAP_PVS_FLOW_CNTL_ADDRS_12
#define VAP_PVS_FLOW_CNTL_ADDRS_12__PVS_FC_ACT_ADRS_12_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_12__PVS_FC_LOOP_CNT_JMP_INST_12_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_12__PVS_FC_LAST_INST_12_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_12__PVS_FC_RTN_INST_12_MASK 0xff000000L

// VAP_PVS_FLOW_CNTL_ADDRS_13
#define VAP_PVS_FLOW_CNTL_ADDRS_13__PVS_FC_ACT_ADRS_13_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_13__PVS_FC_LOOP_CNT_JMP_INST_13_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_13__PVS_FC_LAST_INST_13_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_13__PVS_FC_RTN_INST_13_MASK 0xff000000L

// VAP_PVS_FLOW_CNTL_ADDRS_14
#define VAP_PVS_FLOW_CNTL_ADDRS_14__PVS_FC_ACT_ADRS_14_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_14__PVS_FC_LOOP_CNT_JMP_INST_14_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_14__PVS_FC_LAST_INST_14_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_14__PVS_FC_RTN_INST_14_MASK 0xff000000L

// VAP_PVS_FLOW_CNTL_ADDRS_15
#define VAP_PVS_FLOW_CNTL_ADDRS_15__PVS_FC_ACT_ADRS_15_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_ADDRS_15__PVS_FC_LOOP_CNT_JMP_INST_15_MASK 0x0000ff00L
#define VAP_PVS_FLOW_CNTL_ADDRS_15__PVS_FC_LAST_INST_15_MASK 0x00ff0000L
#define VAP_PVS_FLOW_CNTL_ADDRS_15__PVS_FC_RTN_INST_15_MASK 0xff000000L

// VAP_PVS_DEBUG_0
#define VAP_PVS_DEBUG_0__SPARE_MASK                        0x0000001fL
#define VAP_PVS_DEBUG_0__DIS_CLIP_ERR_DETECT_MASK          0x00000020L
#define VAP_PVS_DEBUG_0__DIS_CLIP_ERR_DETECT               0x00000020L

// VAP_PVS_STATE_FLUSH_REG
#define VAP_PVS_STATE_FLUSH_REG__DATA_REGISTER_MASK        0xffffffffL

// VAP_PVS_VTX_TIMEOUT_REG
#define VAP_PVS_VTX_TIMEOUT_REG__CLK_COUNT_MASK            0xffffffffL

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_0
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_0__PVS_FC_LOOP_INIT_VAL_0_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_0__PVS_FC_LOOP_STEP_VAL_0_MASK 0x0000ff00L

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_1
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_1__PVS_FC_LOOP_INIT_VAL_1_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_1__PVS_FC_LOOP_STEP_VAL_1_MASK 0x0000ff00L

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_2
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_2__PVS_FC_LOOP_INIT_VAL_2_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_2__PVS_FC_LOOP_STEP_VAL_2_MASK 0x0000ff00L

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_3
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_3__PVS_FC_LOOP_INIT_VAL_3_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_3__PVS_FC_LOOP_STEP_VAL_3_MASK 0x0000ff00L

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_4
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_4__PVS_FC_LOOP_INIT_VAL_4_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_4__PVS_FC_LOOP_STEP_VAL_4_MASK 0x0000ff00L

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_5
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_5__PVS_FC_LOOP_INIT_VAL_5_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_5__PVS_FC_LOOP_STEP_VAL_5_MASK 0x0000ff00L

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_6
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_6__PVS_FC_LOOP_INIT_VAL_6_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_6__PVS_FC_LOOP_STEP_VAL_6_MASK 0x0000ff00L

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_7
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_7__PVS_FC_LOOP_INIT_VAL_7_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_7__PVS_FC_LOOP_STEP_VAL_7_MASK 0x0000ff00L

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_8
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_8__PVS_FC_LOOP_INIT_VAL_8_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_8__PVS_FC_LOOP_STEP_VAL_8_MASK 0x0000ff00L

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_9
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_9__PVS_FC_LOOP_INIT_VAL_9_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_9__PVS_FC_LOOP_STEP_VAL_9_MASK 0x0000ff00L

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_10
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_10__PVS_FC_LOOP_INIT_VAL_10_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_10__PVS_FC_LOOP_STEP_VAL_10_MASK 0x0000ff00L

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_11
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_11__PVS_FC_LOOP_INIT_VAL_11_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_11__PVS_FC_LOOP_STEP_VAL_11_MASK 0x0000ff00L

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_12
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_12__PVS_FC_LOOP_INIT_VAL_12_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_12__PVS_FC_LOOP_STEP_VAL_12_MASK 0x0000ff00L

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_13
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_13__PVS_FC_LOOP_INIT_VAL_13_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_13__PVS_FC_LOOP_STEP_VAL_13_MASK 0x0000ff00L

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_14
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_14__PVS_FC_LOOP_INIT_VAL_14_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_14__PVS_FC_LOOP_STEP_VAL_14_MASK 0x0000ff00L

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_15
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_15__PVS_FC_LOOP_INIT_VAL_15_MASK 0x000000ffL
#define VAP_PVS_FLOW_CNTL_LOOP_INDEX_15__PVS_FC_LOOP_STEP_VAL_15_MASK 0x0000ff00L

// VAP_PVS_CODE_CNTL_0
#define VAP_PVS_CODE_CNTL_0__PVS_FIRST_INST_MASK           0x000003ffL
#define VAP_PVS_CODE_CNTL_0__PVS_XYZW_VALID_INST_MASK      0x000ffc00L
#define VAP_PVS_CODE_CNTL_0__PVS_LAST_INST_MASK            0x3ff00000L

// VAP_PVS_CONST_CNTL
#define VAP_PVS_CONST_CNTL__PVS_CONST_BASE_OFFSET_MASK     0x000000ffL
#define VAP_PVS_CONST_CNTL__PVS_MAX_CONST_ADDR_MASK        0x00ff0000L

// VAP_PVS_CODE_CNTL_1
#define VAP_PVS_CODE_CNTL_1__PVS_LAST_VTX_SRC_INST_MASK    0x000003ffL

// VAP_PVS_FLOW_CNTL_OPC
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_0_MASK           0x00000003L
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_1_MASK           0x0000000cL
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_2_MASK           0x00000030L
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_3_MASK           0x000000c0L
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_4_MASK           0x00000300L
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_5_MASK           0x00000c00L
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_6_MASK           0x00003000L
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_7_MASK           0x0000c000L
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_8_MASK           0x00030000L
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_9_MASK           0x000c0000L
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_10_MASK          0x00300000L
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_11_MASK          0x00c00000L
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_12_MASK          0x03000000L
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_13_MASK          0x0c000000L
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_14_MASK          0x30000000L
#define VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_15_MASK          0xc0000000L

// VAP_VTX_ST_POS_0_X_4
#define VAP_VTX_ST_POS_0_X_4__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_POS_0_Y_4
#define VAP_VTX_ST_POS_0_Y_4__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_POS_0_Z_4
#define VAP_VTX_ST_POS_0_Z_4__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_POS_0_W_4
#define VAP_VTX_ST_POS_0_W_4__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_NORM_0_X
#define VAP_VTX_ST_NORM_0_X__DATA_REGISTER_MASK            0xffffffffL

// VAP_VTX_ST_NORM_0_Y
#define VAP_VTX_ST_NORM_0_Y__DATA_REGISTER_MASK            0xffffffffL

// VAP_VTX_ST_NORM_0_Z
#define VAP_VTX_ST_NORM_0_Z__DATA_REGISTER_MASK            0xffffffffL

// VAP_VTX_ST_PVMS
#define VAP_VTX_ST_PVMS__DATA_REGISTER_MASK                0xffffffffL

// VAP_VTX_ST_CLR_0_R
#define VAP_VTX_ST_CLR_0_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_0_G
#define VAP_VTX_ST_CLR_0_G__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_0_B
#define VAP_VTX_ST_CLR_0_B__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_0_A
#define VAP_VTX_ST_CLR_0_A__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_1_R
#define VAP_VTX_ST_CLR_1_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_1_G
#define VAP_VTX_ST_CLR_1_G__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_1_B
#define VAP_VTX_ST_CLR_1_B__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_1_A
#define VAP_VTX_ST_CLR_1_A__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_2_R
#define VAP_VTX_ST_CLR_2_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_2_G
#define VAP_VTX_ST_CLR_2_G__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_2_B
#define VAP_VTX_ST_CLR_2_B__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_2_A
#define VAP_VTX_ST_CLR_2_A__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_3_R
#define VAP_VTX_ST_CLR_3_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_3_G
#define VAP_VTX_ST_CLR_3_G__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_3_B
#define VAP_VTX_ST_CLR_3_B__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_3_A
#define VAP_VTX_ST_CLR_3_A__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_4_R
#define VAP_VTX_ST_CLR_4_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_4_G
#define VAP_VTX_ST_CLR_4_G__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_4_B
#define VAP_VTX_ST_CLR_4_B__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_4_A
#define VAP_VTX_ST_CLR_4_A__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_5_R
#define VAP_VTX_ST_CLR_5_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_5_G
#define VAP_VTX_ST_CLR_5_G__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_5_B
#define VAP_VTX_ST_CLR_5_B__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_5_A
#define VAP_VTX_ST_CLR_5_A__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_6_R
#define VAP_VTX_ST_CLR_6_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_6_G
#define VAP_VTX_ST_CLR_6_G__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_6_B
#define VAP_VTX_ST_CLR_6_B__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_6_A
#define VAP_VTX_ST_CLR_6_A__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_7_R
#define VAP_VTX_ST_CLR_7_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_7_G
#define VAP_VTX_ST_CLR_7_G__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_7_B
#define VAP_VTX_ST_CLR_7_B__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_CLR_7_A
#define VAP_VTX_ST_CLR_7_A__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_0_S
#define VAP_VTX_ST_TEX_0_S__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_0_T
#define VAP_VTX_ST_TEX_0_T__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_0_R
#define VAP_VTX_ST_TEX_0_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_0_Q
#define VAP_VTX_ST_TEX_0_Q__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_1_S
#define VAP_VTX_ST_TEX_1_S__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_1_T
#define VAP_VTX_ST_TEX_1_T__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_1_R
#define VAP_VTX_ST_TEX_1_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_1_Q
#define VAP_VTX_ST_TEX_1_Q__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_2_S
#define VAP_VTX_ST_TEX_2_S__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_2_T
#define VAP_VTX_ST_TEX_2_T__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_2_R
#define VAP_VTX_ST_TEX_2_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_2_Q
#define VAP_VTX_ST_TEX_2_Q__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_3_S
#define VAP_VTX_ST_TEX_3_S__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_3_T
#define VAP_VTX_ST_TEX_3_T__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_3_R
#define VAP_VTX_ST_TEX_3_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_3_Q
#define VAP_VTX_ST_TEX_3_Q__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_4_S
#define VAP_VTX_ST_TEX_4_S__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_4_T
#define VAP_VTX_ST_TEX_4_T__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_4_R
#define VAP_VTX_ST_TEX_4_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_4_Q
#define VAP_VTX_ST_TEX_4_Q__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_5_S
#define VAP_VTX_ST_TEX_5_S__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_5_T
#define VAP_VTX_ST_TEX_5_T__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_5_R
#define VAP_VTX_ST_TEX_5_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_5_Q
#define VAP_VTX_ST_TEX_5_Q__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_6_S
#define VAP_VTX_ST_TEX_6_S__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_6_T
#define VAP_VTX_ST_TEX_6_T__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_6_R
#define VAP_VTX_ST_TEX_6_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_6_Q
#define VAP_VTX_ST_TEX_6_Q__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_7_S
#define VAP_VTX_ST_TEX_7_S__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_7_T
#define VAP_VTX_ST_TEX_7_T__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_7_R
#define VAP_VTX_ST_TEX_7_R__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_TEX_7_Q
#define VAP_VTX_ST_TEX_7_Q__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_PNT_SPRT_SZ
#define VAP_VTX_ST_PNT_SPRT_SZ__DATA_REGISTER_MASK         0xffffffffL

// VAP_VTX_ST_DISC_FOG
#define VAP_VTX_ST_DISC_FOG__DATA_REGISTER_MASK            0xffffffffL

// VAP_VTX_ST_SHININESS_0
#define VAP_VTX_ST_SHININESS_0__DATA_REGISTER_MASK         0xffffffffL

// VAP_VTX_ST_SHININESS_1
#define VAP_VTX_ST_SHININESS_1__DATA_REGISTER_MASK         0xffffffffL

// VAP_VTX_ST_BLND_WT_0
#define VAP_VTX_ST_BLND_WT_0__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_BLND_WT_1
#define VAP_VTX_ST_BLND_WT_1__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_BLND_WT_2
#define VAP_VTX_ST_BLND_WT_2__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_BLND_WT_3
#define VAP_VTX_ST_BLND_WT_3__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_POS_1_X
#define VAP_VTX_ST_POS_1_X__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_POS_1_Y
#define VAP_VTX_ST_POS_1_Y__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_POS_1_Z
#define VAP_VTX_ST_POS_1_Z__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_POS_1_W
#define VAP_VTX_ST_POS_1_W__DATA_REGISTER_MASK             0xffffffffL

// VAP_VTX_ST_NORM_1_X
#define VAP_VTX_ST_NORM_1_X__DATA_REGISTER_MASK            0xffffffffL

// VAP_VTX_ST_NORM_1_Y
#define VAP_VTX_ST_NORM_1_Y__DATA_REGISTER_MASK            0xffffffffL

// VAP_VTX_ST_NORM_1_Z
#define VAP_VTX_ST_NORM_1_Z__DATA_REGISTER_MASK            0xffffffffL

// VAP_VTX_ST_EDGE_FLAGS
#define VAP_VTX_ST_EDGE_FLAGS__DATA_REGISTER_MASK          0x00000001L
#define VAP_VTX_ST_EDGE_FLAGS__DATA_REGISTER               0x00000001L

// VAP_VTX_ST_USR_CLR_R
#define VAP_VTX_ST_USR_CLR_R__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_USR_CLR_G
#define VAP_VTX_ST_USR_CLR_G__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_USR_CLR_B
#define VAP_VTX_ST_USR_CLR_B__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_USR_CLR_A
#define VAP_VTX_ST_USR_CLR_A__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_CLR_0_PKD
#define VAP_VTX_ST_CLR_0_PKD__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_CLR_1_PKD
#define VAP_VTX_ST_CLR_1_PKD__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_CLR_2_PKD
#define VAP_VTX_ST_CLR_2_PKD__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_CLR_3_PKD
#define VAP_VTX_ST_CLR_3_PKD__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_CLR_4_PKD
#define VAP_VTX_ST_CLR_4_PKD__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_CLR_5_PKD
#define VAP_VTX_ST_CLR_5_PKD__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_CLR_6_PKD
#define VAP_VTX_ST_CLR_6_PKD__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_CLR_7_PKD
#define VAP_VTX_ST_CLR_7_PKD__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_POS_0_X_2
#define VAP_VTX_ST_POS_0_X_2__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_POS_0_Y_2
#define VAP_VTX_ST_POS_0_Y_2__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_NORM_0_PKD
#define VAP_VTX_ST_NORM_0_PKD__DATA_REGISTER_MASK          0xffffffffL

// VAP_VTX_ST_USR_CLR_PKD
#define VAP_VTX_ST_USR_CLR_PKD__DATA_REGISTER_MASK         0xffffffffL

// VAP_VTX_ST_POS_0_X_3
#define VAP_VTX_ST_POS_0_X_3__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_POS_0_Y_3
#define VAP_VTX_ST_POS_0_Y_3__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_POS_0_Z_3
#define VAP_VTX_ST_POS_0_Z_3__DATA_REGISTER_MASK           0xffffffffL

// VAP_VTX_ST_END_OF_PKT
#define VAP_VTX_ST_END_OF_PKT__DATA_REGISTER_MASK          0xffffffffL

// MC_CNTL
#define MC_CNTL__MEM_NUM_CHANNELS_MASK                     0x00000003L
#define MC_CNTL__MEM_USE_CD_CH_ONLY_MASK                   0x00000004L
#define MC_CNTL__MEM_USE_CD_CH_ONLY                        0x00000004L
#define MC_CNTL__MEM_ADDR_MAP_RANK_MASK                    0x00000008L
#define MC_CNTL__MEM_ADDR_MAP_RANK                         0x00000008L
#define MC_CNTL__MEM_ADDR_MAP_ROWS_MASK                    0x00000030L
#define MC_CNTL__MEM_ADDR_MAP_COLS_MASK                    0x00000040L
#define MC_CNTL__MEM_ADDR_MAP_COLS                         0x00000040L

// MC_TIMING_CNTL
#define MC_TIMING_CNTL__MEM_TRCDRD_MASK                    0x00000007L
#define MC_TIMING_CNTL__MEM_TRCDWR_MASK                    0x00000070L
#define MC_TIMING_CNTL__MEM_TRP_MASK                       0x00000700L
#define MC_TIMING_CNTL__MEM_TRAS_MASK                      0x00007800L
#define MC_TIMING_CNTL__MEM_TRRD_MASK                      0x00038000L
#define MC_TIMING_CNTL__MEM_TR2W_MASK                      0x000c0000L
#define MC_TIMING_CNTL__MEM_TWR_MASK                       0x00700000L
#define MC_TIMING_CNTL__MEM_TW2R_MASK                      0x07000000L
#define MC_TIMING_CNTL__MEM_TW2R_SAME_BANK_MASK            0x08000000L
#define MC_TIMING_CNTL__MEM_TW2R_SAME_BANK                 0x08000000L
#define MC_TIMING_CNTL__MEM_TR2R_MASK                      0x30000000L

// MC_AGP_LOCATION
#define MC_AGP_LOCATION__MC_AGP_START_MASK                 0x0000ffffL
#define MC_AGP_LOCATION__MC_AGP_TOP_MASK                   0xffff0000L

// MC_REFRESH_CNTL
#define MC_REFRESH_CNTL__MEM_REFRESH_RATE_MASK             0x000000ffL
#define MC_REFRESH_CNTL__MEM_REFRESH_DIS_MASK              0x00000100L
#define MC_REFRESH_CNTL__MEM_REFRESH_DIS                   0x00000100L
#define MC_REFRESH_CNTL__MEM_DYNAMIC_CKE_MASK              0x00000200L
#define MC_REFRESH_CNTL__MEM_DYNAMIC_CKE                   0x00000200L
#define MC_REFRESH_CNTL__MEM_TRFC_MASK                     0x0000f000L

// MC_IOPAD_CNTL
#define MC_IOPAD_CNTL__MEM_CLKA0_ENABLE_MASK               0x00000001L
#define MC_IOPAD_CNTL__MEM_CLKA0_ENABLE                    0x00000001L
#define MC_IOPAD_CNTL__MEM_CLKA0b_ENABLE_MASK              0x00000002L
#define MC_IOPAD_CNTL__MEM_CLKA0b_ENABLE                   0x00000002L
#define MC_IOPAD_CNTL__MEM_CLKA1_ENABLE_MASK               0x00000004L
#define MC_IOPAD_CNTL__MEM_CLKA1_ENABLE                    0x00000004L
#define MC_IOPAD_CNTL__MEM_CLKA1b_ENABLE_MASK              0x00000008L
#define MC_IOPAD_CNTL__MEM_CLKA1b_ENABLE                   0x00000008L
#define MC_IOPAD_CNTL__MEM_CLKAFB_ENABLE_MASK              0x00000010L
#define MC_IOPAD_CNTL__MEM_CLKAFB_ENABLE                   0x00000010L
#define MC_IOPAD_CNTL__DLL_FB_SLCT_CKA_MASK                0x00000060L
#define MC_IOPAD_CNTL__MEM_CLKB0_ENABLE_MASK               0x00000080L
#define MC_IOPAD_CNTL__MEM_CLKB0_ENABLE                    0x00000080L
#define MC_IOPAD_CNTL__MEM_CLKB0b_ENABLE_MASK              0x00000100L
#define MC_IOPAD_CNTL__MEM_CLKB0b_ENABLE                   0x00000100L
#define MC_IOPAD_CNTL__MEM_CLKB1_ENABLE_MASK               0x00000200L
#define MC_IOPAD_CNTL__MEM_CLKB1_ENABLE                    0x00000200L
#define MC_IOPAD_CNTL__MEM_CLKB1b_ENABLE_MASK              0x00000400L
#define MC_IOPAD_CNTL__MEM_CLKB1b_ENABLE                   0x00000400L
#define MC_IOPAD_CNTL__MEM_CLKBFB_ENABLE_MASK              0x00000800L
#define MC_IOPAD_CNTL__MEM_CLKBFB_ENABLE                   0x00000800L
#define MC_IOPAD_CNTL__DLL_FB_SLCT_CKB_MASK                0x00003000L
#define MC_IOPAD_CNTL__MEM_CLKC0_ENABLE_MASK               0x00004000L
#define MC_IOPAD_CNTL__MEM_CLKC0_ENABLE                    0x00004000L
#define MC_IOPAD_CNTL__MEM_CLKC0b_ENABLE_MASK              0x00008000L
#define MC_IOPAD_CNTL__MEM_CLKC0b_ENABLE                   0x00008000L
#define MC_IOPAD_CNTL__MEM_CLKC1_ENABLE_MASK               0x00010000L
#define MC_IOPAD_CNTL__MEM_CLKC1_ENABLE                    0x00010000L
#define MC_IOPAD_CNTL__MEM_CLKC1b_ENABLE_MASK              0x00020000L
#define MC_IOPAD_CNTL__MEM_CLKC1b_ENABLE                   0x00020000L
#define MC_IOPAD_CNTL__MEM_CLKCFB_ENABLE_MASK              0x00040000L
#define MC_IOPAD_CNTL__MEM_CLKCFB_ENABLE                   0x00040000L
#define MC_IOPAD_CNTL__DLL_FB_SLCT_CKC_MASK                0x00180000L
#define MC_IOPAD_CNTL__MEM_CLKD0_ENABLE_MASK               0x00200000L
#define MC_IOPAD_CNTL__MEM_CLKD0_ENABLE                    0x00200000L
#define MC_IOPAD_CNTL__MEM_CLKD0b_ENABLE_MASK              0x00400000L
#define MC_IOPAD_CNTL__MEM_CLKD0b_ENABLE                   0x00400000L
#define MC_IOPAD_CNTL__MEM_CLKD1_ENABLE_MASK               0x00800000L
#define MC_IOPAD_CNTL__MEM_CLKD1_ENABLE                    0x00800000L
#define MC_IOPAD_CNTL__MEM_CLKD1b_ENABLE_MASK              0x01000000L
#define MC_IOPAD_CNTL__MEM_CLKD1b_ENABLE                   0x01000000L
#define MC_IOPAD_CNTL__MEM_CLKDFB_ENABLE_MASK              0x02000000L
#define MC_IOPAD_CNTL__MEM_CLKDFB_ENABLE                   0x02000000L
#define MC_IOPAD_CNTL__DLL_FB_SLCT_CKD_MASK                0x0c000000L

// MC_INIT_MISC_LAT_TIMER
#define MC_INIT_MISC_LAT_TIMER__MC_CPR_INIT_LAT_MASK       0x0000000fL
#define MC_INIT_MISC_LAT_TIMER__MC_VF_INIT_LAT_MASK        0x000000f0L
#define MC_INIT_MISC_LAT_TIMER__MC_DISP0R_INIT_LAT_MASK    0x00000f00L
#define MC_INIT_MISC_LAT_TIMER__MC_DISP1R_INIT_LAT_MASK    0x0000f000L
#define MC_INIT_MISC_LAT_TIMER__MC_FIXED_INIT_LAT_MASK     0x000f0000L
#define MC_INIT_MISC_LAT_TIMER__MC_E2R_INIT_LAT_MASK       0x00f00000L
#define MC_INIT_MISC_LAT_TIMER__SAME_PAGE_PRIO_MASK        0x0f000000L
#define MC_INIT_MISC_LAT_TIMER__MC_GLOBW_INIT_LAT_MASK     0xf0000000L

// MC_INIT_GFX_LAT_TIMER
#define MC_INIT_GFX_LAT_TIMER__MC_G3D0R_INIT_LAT_MASK      0x0000000fL
#define MC_INIT_GFX_LAT_TIMER__MC_G3D1R_INIT_LAT_MASK      0x000000f0L
#define MC_INIT_GFX_LAT_TIMER__MC_G3D2R_INIT_LAT_MASK      0x00000f00L
#define MC_INIT_GFX_LAT_TIMER__MC_G3D3R_INIT_LAT_MASK      0x0000f000L
#define MC_INIT_GFX_LAT_TIMER__MC_TX0R_INIT_LAT_MASK       0x000f0000L
#define MC_INIT_GFX_LAT_TIMER__MC_TX1R_INIT_LAT_MASK       0x00f00000L
#define MC_INIT_GFX_LAT_TIMER__MC_GLOBR_INIT_LAT_MASK      0x0f000000L
#define MC_INIT_GFX_LAT_TIMER__MC_GLOBW_FULL_LAT_MASK      0xf0000000L

// MC_SDRAM_MODE_REG
#define MC_SDRAM_MODE_REG__MEM_MODE_REG_MASK               0x00007fffL
#define MC_SDRAM_MODE_REG__MEM_WR_LATENCY_MASK             0x000f0000L
#define MC_SDRAM_MODE_REG__MEM_CAS_LATENCY_MASK            0x00700000L
#define MC_SDRAM_MODE_REG__MEM_CMD_LATENCY_MASK            0x00800000L
#define MC_SDRAM_MODE_REG__MEM_CMD_LATENCY                 0x00800000L
#define MC_SDRAM_MODE_REG__MEM_STR_LATENCY_MASK            0x01000000L
#define MC_SDRAM_MODE_REG__MEM_STR_LATENCY                 0x01000000L
#define MC_SDRAM_MODE_REG__MC_INIT_COMPLETE_MASK           0x10000000L
#define MC_SDRAM_MODE_REG__MC_INIT_COMPLETE                0x10000000L
#define MC_SDRAM_MODE_REG__MEM_DDR_DLL_MASK                0x20000000L
#define MC_SDRAM_MODE_REG__MEM_DDR_DLL                     0x20000000L
#define MC_SDRAM_MODE_REG__MEM_ELPIDA_TYPE_MASK            0x40000000L
#define MC_SDRAM_MODE_REG__MEM_ELPIDA_TYPE                 0x40000000L
#define MC_SDRAM_MODE_REG__MEM_SDRAM_RESET_MASK            0x80000000L
#define MC_SDRAM_MODE_REG__MEM_SDRAM_RESET                 0x80000000L

// AGP_BASE
#define AGP_BASE__AGP_BASE_ADDR_MASK                       0xffffffffL

// MC_READ_CNTL_AB
#define MC_READ_CNTL_AB__MEM_RBS_POSITION_A_MASK           0x00000007L
#define MC_READ_CNTL_AB__MEM_STR_SEL_A_MASK                0x00000008L
#define MC_READ_CNTL_AB__MEM_STR_SEL_A                     0x00000008L
#define MC_READ_CNTL_AB__MEM_ERST_POSITION_A_MASK          0x00000070L
#define MC_READ_CNTL_AB__MEM_ERST_EXTEND_A_MASK            0x00000080L
#define MC_READ_CNTL_AB__MEM_ERST_EXTEND_A                 0x00000080L
#define MC_READ_CNTL_AB__MEM_QSREC_POSITION_A_MASK         0x00000700L
#define MC_READ_CNTL_AB__MEM_QSREC_EXTEND_A_MASK           0x00000800L
#define MC_READ_CNTL_AB__MEM_QSREC_EXTEND_A                0x00000800L
#define MC_READ_CNTL_AB__MEM_ERST_SYNC_A_MASK              0x00001000L
#define MC_READ_CNTL_AB__MEM_ERST_SYNC_A                   0x00001000L
#define MC_READ_CNTL_AB__MEM_QSREC_SYNC_A_MASK             0x00002000L
#define MC_READ_CNTL_AB__MEM_QSREC_SYNC_A                  0x00002000L
#define MC_READ_CNTL_AB__MEM_RBS_POSITION_B_MASK           0x00070000L
#define MC_READ_CNTL_AB__MEM_STR_SEL_B_MASK                0x00080000L
#define MC_READ_CNTL_AB__MEM_STR_SEL_B                     0x00080000L
#define MC_READ_CNTL_AB__MEM_ERST_POSITION_B_MASK          0x00700000L
#define MC_READ_CNTL_AB__MEM_ERST_EXTEND_B_MASK            0x00800000L
#define MC_READ_CNTL_AB__MEM_ERST_EXTEND_B                 0x00800000L
#define MC_READ_CNTL_AB__MEM_QSREC_POSITION_B_MASK         0x07000000L
#define MC_READ_CNTL_AB__MEM_QSREC_EXTEND_B_MASK           0x08000000L
#define MC_READ_CNTL_AB__MEM_QSREC_EXTEND_B                0x08000000L
#define MC_READ_CNTL_AB__MEM_ERST_SYNC_B_MASK              0x10000000L
#define MC_READ_CNTL_AB__MEM_ERST_SYNC_B                   0x10000000L
#define MC_READ_CNTL_AB__MEM_QSREC_SYNC_B_MASK             0x20000000L
#define MC_READ_CNTL_AB__MEM_QSREC_SYNC_B                  0x20000000L

// MC_DEBUG
#define MC_DEBUG__RB_WATER_GFX_MASK                        0x0000001fL
#define MC_DEBUG__RB_WATER_CP_MASK                         0x000003e0L
#define MC_DEBUG__RB_WATER_GLB_MASK                        0x00007c00L
#define MC_DEBUG__EN_AIC_IDLE_DET_R3_MASK                  0x00008000L
#define MC_DEBUG__EN_AIC_IDLE_DET_R3                       0x00008000L
#define MC_DEBUG__MEM_MC_BLACKOUT_R3_MASK                  0x00010000L
#define MC_DEBUG__MEM_MC_BLACKOUT_R3                       0x00010000L
#define MC_DEBUG__MEM_TRD_MASK                             0x00060000L
#define MC_DEBUG__CH_WATER_TAG_MASK                        0x00f00000L
#define MC_DEBUG__MEM_ERST_DIS_A_MASK                      0x03000000L
#define MC_DEBUG__MEM_ERST_DIS_B_MASK                      0x0c000000L
#define MC_DEBUG__MEM_ERST_DIS_C_MASK                      0x30000000L
#define MC_DEBUG__MEM_ERST_DIS_D_MASK                      0xc0000000L

// MC_STATUS
#define MC_STATUS__MEM_PWRUP_COMPL_A_MASK                  0x00000001L
#define MC_STATUS__MEM_PWRUP_COMPL_A                       0x00000001L
#define MC_STATUS__MEM_PWRUP_COMPL_B_MASK                  0x00000002L
#define MC_STATUS__MEM_PWRUP_COMPL_B                       0x00000002L
#define MC_STATUS__MEM_PWRUP_COMPL_C_MASK                  0x00000004L
#define MC_STATUS__MEM_PWRUP_COMPL_C                       0x00000004L
#define MC_STATUS__MEM_PWRUP_COMPL_D_MASK                  0x00000008L
#define MC_STATUS__MEM_PWRUP_COMPL_D                       0x00000008L
#define MC_STATUS__MC_IDLE_R3_MASK                         0x00000010L
#define MC_STATUS__MC_IDLE_R3                              0x00000010L
#define MC_STATUS__IMP_CAL_COUNT_MASK                      0x0000f000L

// MC_IMP_STATUS
#define MC_IMP_STATUS__IMP_N_VALUE_R_BACK_MASK             0x0000000fL
#define MC_IMP_STATUS__IMP_P_VALUE_R_BACK_MASK             0x000000f0L
#define MC_IMP_STATUS__IMP_N_VALUE_A_R_BACK_MASK           0x00000f00L
#define MC_IMP_STATUS__IMP_P_VALUE_A_R_BACK_MASK           0x0000f000L
#define MC_IMP_STATUS__IMP_N_VALUE_CK_R_BACK_MASK          0x000f0000L
#define MC_IMP_STATUS__IMP_P_VALUE_CK_R_BACK_MASK          0x00f00000L
#define MC_IMP_STATUS__IMP_N_VALUE_DQS_R_BACK_MASK         0x0f000000L
#define MC_IMP_STATUS__IMP_P_VALUE_DQS_R_BACK_MASK         0xf0000000L

// MC_CHP_IO_OE_CNTL_AB
#define MC_CHP_IO_OE_CNTL_AB__DQ_OE_POSITION_A_MASK        0x00000003L
#define MC_CHP_IO_OE_CNTL_AB__QS_OE_POSITION_A_MASK        0x0000000cL
#define MC_CHP_IO_OE_CNTL_AB__DQ_OE_EXTEND_A_MASK          0x00000010L
#define MC_CHP_IO_OE_CNTL_AB__DQ_OE_EXTEND_A               0x00000010L
#define MC_CHP_IO_OE_CNTL_AB__QS_OE_EXTEND_A_MASK          0x00000020L
#define MC_CHP_IO_OE_CNTL_AB__QS_OE_EXTEND_A               0x00000020L
#define MC_CHP_IO_OE_CNTL_AB__DQ_OE_ADVANCE_A_MASK         0x00000040L
#define MC_CHP_IO_OE_CNTL_AB__DQ_OE_ADVANCE_A              0x00000040L
#define MC_CHP_IO_OE_CNTL_AB__QS_OE_ADVANCE_A_MASK         0x00000080L
#define MC_CHP_IO_OE_CNTL_AB__QS_OE_ADVANCE_A              0x00000080L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_A0_MASK      0x00000100L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_A0           0x00000100L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_A1_MASK      0x00000200L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_A1           0x00000200L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_A2_MASK      0x00000400L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_A2           0x00000400L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_A3_MASK      0x00000800L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_A3           0x00000800L
#define MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_CMD_A_MASK      0x00001000L
#define MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_CMD_A           0x00001000L
#define MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_DATA_A_MASK     0x00002000L
#define MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_DATA_A          0x00002000L
#define MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_STR_A_MASK      0x00004000L
#define MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_STR_A           0x00004000L
#define MC_CHP_IO_OE_CNTL_AB__MEM_PM_SDRAM_TRI_EN_MASK     0x00008000L
#define MC_CHP_IO_OE_CNTL_AB__MEM_PM_SDRAM_TRI_EN          0x00008000L
#define MC_CHP_IO_OE_CNTL_AB__DQ_OE_POSITION_B_MASK        0x00030000L
#define MC_CHP_IO_OE_CNTL_AB__QS_OE_POSITION_B_MASK        0x000c0000L
#define MC_CHP_IO_OE_CNTL_AB__DQ_OE_EXTEND_B_MASK          0x00100000L
#define MC_CHP_IO_OE_CNTL_AB__DQ_OE_EXTEND_B               0x00100000L
#define MC_CHP_IO_OE_CNTL_AB__QS_OE_EXTEND_B_MASK          0x00200000L
#define MC_CHP_IO_OE_CNTL_AB__QS_OE_EXTEND_B               0x00200000L
#define MC_CHP_IO_OE_CNTL_AB__DQ_OE_ADVANCE_B_MASK         0x00400000L
#define MC_CHP_IO_OE_CNTL_AB__DQ_OE_ADVANCE_B              0x00400000L
#define MC_CHP_IO_OE_CNTL_AB__QS_OE_ADVANCE_B_MASK         0x00800000L
#define MC_CHP_IO_OE_CNTL_AB__QS_OE_ADVANCE_B              0x00800000L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_B0_MASK      0x01000000L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_B0           0x01000000L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_B1_MASK      0x02000000L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_B1           0x02000000L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_B2_MASK      0x04000000L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_B2           0x04000000L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_B3_MASK      0x08000000L
#define MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_B3           0x08000000L
#define MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_CMD_B_MASK      0x10000000L
#define MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_CMD_B           0x10000000L
#define MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_DATA_B_MASK     0x20000000L
#define MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_DATA_B          0x20000000L
#define MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_STR_B_MASK      0x40000000L
#define MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_STR_B           0x40000000L
#define MC_CHP_IO_OE_CNTL_AB__MEM_IO_TRISTATE_MASK         0x80000000L
#define MC_CHP_IO_OE_CNTL_AB__MEM_IO_TRISTATE              0x80000000L

// AGP_BASE_2
#define AGP_BASE_2__AGP_BASE_ADDR_2_MASK                   0x0000000fL

// MC_IND_INDEX
#define MC_IND_INDEX__MC_IND_ADDR_R3_MASK                  0x0000003fL
#define MC_IND_INDEX__MC_IND_WR_EN_MASK                    0x00000100L
#define MC_IND_INDEX__MC_IND_WR_EN                         0x00000100L

// MC_IND_DATA
#define MC_IND_DATA__MC_IND_DATA_MASK                      0xffffffffL

// MC_PERF_CNTL
#define MC_PERF_CNTL__MONITOR_PERIOD_MASK                  0x0000ffffL
#define MC_PERF_CNTL__CH_A_CLK_CNT_EN_MASK                 0x20000000L
#define MC_PERF_CNTL__CH_A_CLK_CNT_EN                      0x20000000L
#define MC_PERF_CNTL__CLR_PERF_MASK                        0x40000000L
#define MC_PERF_CNTL__CLR_PERF                             0x40000000L
#define MC_PERF_CNTL__EN_PERF_MASK                         0x80000000L
#define MC_PERF_CNTL__EN_PERF                              0x80000000L

// MC_PERF_CNT0_SEL
#define MC_PERF_CNT0_SEL__G3D0_READ_MASK                   0x00000001L
#define MC_PERF_CNT0_SEL__G3D0_READ                        0x00000001L
#define MC_PERF_CNT0_SEL__G3D1_READ_MASK                   0x00000002L
#define MC_PERF_CNT0_SEL__G3D1_READ                        0x00000002L
#define MC_PERF_CNT0_SEL__G3D2_READ_MASK                   0x00000004L
#define MC_PERF_CNT0_SEL__G3D2_READ                        0x00000004L
#define MC_PERF_CNT0_SEL__G3D3_READ_MASK                   0x00000008L
#define MC_PERF_CNT0_SEL__G3D3_READ                        0x00000008L
#define MC_PERF_CNT0_SEL__TX0_READ_MASK                    0x00000010L
#define MC_PERF_CNT0_SEL__TX0_READ                         0x00000010L
#define MC_PERF_CNT0_SEL__TX1_READ_MASK                    0x00000020L
#define MC_PERF_CNT0_SEL__TX1_READ                         0x00000020L
#define MC_PERF_CNT0_SEL__G3D0_WRITE_MASK                  0x00000100L
#define MC_PERF_CNT0_SEL__G3D0_WRITE                       0x00000100L
#define MC_PERF_CNT0_SEL__G3D1_WRITE_MASK                  0x00000200L
#define MC_PERF_CNT0_SEL__G3D1_WRITE                       0x00000200L
#define MC_PERF_CNT0_SEL__G3D2_WRITE_MASK                  0x00000400L
#define MC_PERF_CNT0_SEL__G3D2_WRITE                       0x00000400L
#define MC_PERF_CNT0_SEL__G3D3_WRITE_MASK                  0x00000800L
#define MC_PERF_CNT0_SEL__G3D3_WRITE                       0x00000800L
#define MC_PERF_CNT0_SEL__DISP0_READ_MASK                  0x00001000L
#define MC_PERF_CNT0_SEL__DISP0_READ                       0x00001000L
#define MC_PERF_CNT0_SEL__DISP1_READ_MASK                  0x00002000L
#define MC_PERF_CNT0_SEL__DISP1_READ                       0x00002000L
#define MC_PERF_CNT0_SEL__OV0_READ_MASK                    0x00004000L
#define MC_PERF_CNT0_SEL__OV0_READ                         0x00004000L
#define MC_PERF_CNT0_SEL__E2_READ_MASK                     0x00008000L
#define MC_PERF_CNT0_SEL__E2_READ                          0x00008000L
#define MC_PERF_CNT0_SEL__VF_READ_MASK                     0x00010000L
#define MC_PERF_CNT0_SEL__VF_READ                          0x00010000L
#define MC_PERF_CNT0_SEL__CP_READ_MASK                     0x00020000L
#define MC_PERF_CNT0_SEL__CP_READ                          0x00020000L
#define MC_PERF_CNT0_SEL__CP_WRITE_MASK                    0x00040000L
#define MC_PERF_CNT0_SEL__CP_WRITE                         0x00040000L
#define MC_PERF_CNT0_SEL__VIP_READ_MASK                    0x00080000L
#define MC_PERF_CNT0_SEL__VIP_READ                         0x00080000L
#define MC_PERF_CNT0_SEL__VIP_WRITE_MASK                   0x00100000L
#define MC_PERF_CNT0_SEL__VIP_WRITE                        0x00100000L
#define MC_PERF_CNT0_SEL__IDCT_READ_MASK                   0x00200000L
#define MC_PERF_CNT0_SEL__IDCT_READ                        0x00200000L
#define MC_PERF_CNT0_SEL__IDCT_WRITE_MASK                  0x00400000L
#define MC_PERF_CNT0_SEL__IDCT_WRITE                       0x00400000L
#define MC_PERF_CNT0_SEL__HDP_READ_MASK                    0x00800000L
#define MC_PERF_CNT0_SEL__HDP_READ                         0x00800000L
#define MC_PERF_CNT0_SEL__HDP_WRITE_MASK                   0x01000000L
#define MC_PERF_CNT0_SEL__HDP_WRITE                        0x01000000L
#define MC_PERF_CNT0_SEL__REGION_AGPPCI_MASK               0x02000000L
#define MC_PERF_CNT0_SEL__REGION_AGPPCI                    0x02000000L
#define MC_PERF_CNT0_SEL__REGION_CHA_MASK                  0x04000000L
#define MC_PERF_CNT0_SEL__REGION_CHA                       0x04000000L
#define MC_PERF_CNT0_SEL__REGION_CHB_MASK                  0x08000000L
#define MC_PERF_CNT0_SEL__REGION_CHB                       0x08000000L
#define MC_PERF_CNT0_SEL__REGION_CHC_MASK                  0x10000000L
#define MC_PERF_CNT0_SEL__REGION_CHC                       0x10000000L
#define MC_PERF_CNT0_SEL__REGION_CHD_MASK                  0x20000000L
#define MC_PERF_CNT0_SEL__REGION_CHD                       0x20000000L
#define MC_PERF_CNT0_SEL__REGION_0_MASK                    0x40000000L
#define MC_PERF_CNT0_SEL__REGION_0                         0x40000000L
#define MC_PERF_CNT0_SEL__REGION_1_MASK                    0x80000000L
#define MC_PERF_CNT0_SEL__REGION_1                         0x80000000L

// MC_PERF_CNT1_SEL
#define MC_PERF_CNT1_SEL__G3D0_READ_MASK                   0x00000001L
#define MC_PERF_CNT1_SEL__G3D0_READ                        0x00000001L
#define MC_PERF_CNT1_SEL__G3D1_READ_MASK                   0x00000002L
#define MC_PERF_CNT1_SEL__G3D1_READ                        0x00000002L
#define MC_PERF_CNT1_SEL__G3D2_READ_MASK                   0x00000004L
#define MC_PERF_CNT1_SEL__G3D2_READ                        0x00000004L
#define MC_PERF_CNT1_SEL__G3D3_READ_MASK                   0x00000008L
#define MC_PERF_CNT1_SEL__G3D3_READ                        0x00000008L
#define MC_PERF_CNT1_SEL__TX0_READ_MASK                    0x00000010L
#define MC_PERF_CNT1_SEL__TX0_READ                         0x00000010L
#define MC_PERF_CNT1_SEL__TX1_READ_MASK                    0x00000020L
#define MC_PERF_CNT1_SEL__TX1_READ                         0x00000020L
#define MC_PERF_CNT1_SEL__G3D0_WRITE_MASK                  0x00000100L
#define MC_PERF_CNT1_SEL__G3D0_WRITE                       0x00000100L
#define MC_PERF_CNT1_SEL__G3D1_WRITE_MASK                  0x00000200L
#define MC_PERF_CNT1_SEL__G3D1_WRITE                       0x00000200L
#define MC_PERF_CNT1_SEL__G3D2_WRITE_MASK                  0x00000400L
#define MC_PERF_CNT1_SEL__G3D2_WRITE                       0x00000400L
#define MC_PERF_CNT1_SEL__G3D3_WRITE_MASK                  0x00000800L
#define MC_PERF_CNT1_SEL__G3D3_WRITE                       0x00000800L
#define MC_PERF_CNT1_SEL__DISP0_READ_MASK                  0x00001000L
#define MC_PERF_CNT1_SEL__DISP0_READ                       0x00001000L
#define MC_PERF_CNT1_SEL__DISP1_READ_MASK                  0x00002000L
#define MC_PERF_CNT1_SEL__DISP1_READ                       0x00002000L
#define MC_PERF_CNT1_SEL__OV0_READ_MASK                    0x00004000L
#define MC_PERF_CNT1_SEL__OV0_READ                         0x00004000L
#define MC_PERF_CNT1_SEL__E2_READ_MASK                     0x00008000L
#define MC_PERF_CNT1_SEL__E2_READ                          0x00008000L
#define MC_PERF_CNT1_SEL__VF_READ_MASK                     0x00010000L
#define MC_PERF_CNT1_SEL__VF_READ                          0x00010000L
#define MC_PERF_CNT1_SEL__CP_READ_MASK                     0x00020000L
#define MC_PERF_CNT1_SEL__CP_READ                          0x00020000L
#define MC_PERF_CNT1_SEL__CP_WRITE_MASK                    0x00040000L
#define MC_PERF_CNT1_SEL__CP_WRITE                         0x00040000L
#define MC_PERF_CNT1_SEL__VIP_READ_MASK                    0x00080000L
#define MC_PERF_CNT1_SEL__VIP_READ                         0x00080000L
#define MC_PERF_CNT1_SEL__VIP_WRITE_MASK                   0x00100000L
#define MC_PERF_CNT1_SEL__VIP_WRITE                        0x00100000L
#define MC_PERF_CNT1_SEL__IDCT_READ_MASK                   0x00200000L
#define MC_PERF_CNT1_SEL__IDCT_READ                        0x00200000L
#define MC_PERF_CNT1_SEL__IDCT_WRITE_MASK                  0x00400000L
#define MC_PERF_CNT1_SEL__IDCT_WRITE                       0x00400000L
#define MC_PERF_CNT1_SEL__HDP_READ_MASK                    0x00800000L
#define MC_PERF_CNT1_SEL__HDP_READ                         0x00800000L
#define MC_PERF_CNT1_SEL__HDP_WRITE_MASK                   0x01000000L
#define MC_PERF_CNT1_SEL__HDP_WRITE                        0x01000000L
#define MC_PERF_CNT1_SEL__REGION_AGPPCI_MASK               0x02000000L
#define MC_PERF_CNT1_SEL__REGION_AGPPCI                    0x02000000L
#define MC_PERF_CNT1_SEL__REGION_CHA_MASK                  0x04000000L
#define MC_PERF_CNT1_SEL__REGION_CHA                       0x04000000L
#define MC_PERF_CNT1_SEL__REGION_CHB_MASK                  0x08000000L
#define MC_PERF_CNT1_SEL__REGION_CHB                       0x08000000L
#define MC_PERF_CNT1_SEL__REGION_CHC_MASK                  0x10000000L
#define MC_PERF_CNT1_SEL__REGION_CHC                       0x10000000L
#define MC_PERF_CNT1_SEL__REGION_CHD_MASK                  0x20000000L
#define MC_PERF_CNT1_SEL__REGION_CHD                       0x20000000L
#define MC_PERF_CNT1_SEL__REGION_0_MASK                    0x40000000L
#define MC_PERF_CNT1_SEL__REGION_0                         0x40000000L
#define MC_PERF_CNT1_SEL__REGION_1_MASK                    0x80000000L
#define MC_PERF_CNT1_SEL__REGION_1                         0x80000000L

// MC_PERF_CNT2_SEL
#define MC_PERF_CNT2_SEL__G3D0_READ_MASK                   0x00000001L
#define MC_PERF_CNT2_SEL__G3D0_READ                        0x00000001L
#define MC_PERF_CNT2_SEL__G3D1_READ_MASK                   0x00000002L
#define MC_PERF_CNT2_SEL__G3D1_READ                        0x00000002L
#define MC_PERF_CNT2_SEL__G3D2_READ_MASK                   0x00000004L
#define MC_PERF_CNT2_SEL__G3D2_READ                        0x00000004L
#define MC_PERF_CNT2_SEL__G3D3_READ_MASK                   0x00000008L
#define MC_PERF_CNT2_SEL__G3D3_READ                        0x00000008L
#define MC_PERF_CNT2_SEL__TX0_READ_MASK                    0x00000010L
#define MC_PERF_CNT2_SEL__TX0_READ                         0x00000010L
#define MC_PERF_CNT2_SEL__TX1_READ_MASK                    0x00000020L
#define MC_PERF_CNT2_SEL__TX1_READ                         0x00000020L
#define MC_PERF_CNT2_SEL__G3D0_WRITE_MASK                  0x00000100L
#define MC_PERF_CNT2_SEL__G3D0_WRITE                       0x00000100L
#define MC_PERF_CNT2_SEL__G3D1_WRITE_MASK                  0x00000200L
#define MC_PERF_CNT2_SEL__G3D1_WRITE                       0x00000200L
#define MC_PERF_CNT2_SEL__G3D2_WRITE_MASK                  0x00000400L
#define MC_PERF_CNT2_SEL__G3D2_WRITE                       0x00000400L
#define MC_PERF_CNT2_SEL__G3D3_WRITE_MASK                  0x00000800L
#define MC_PERF_CNT2_SEL__G3D3_WRITE                       0x00000800L
#define MC_PERF_CNT2_SEL__DISP0_READ_MASK                  0x00001000L
#define MC_PERF_CNT2_SEL__DISP0_READ                       0x00001000L
#define MC_PERF_CNT2_SEL__DISP1_READ_MASK                  0x00002000L
#define MC_PERF_CNT2_SEL__DISP1_READ                       0x00002000L
#define MC_PERF_CNT2_SEL__OV0_READ_MASK                    0x00004000L
#define MC_PERF_CNT2_SEL__OV0_READ                         0x00004000L
#define MC_PERF_CNT2_SEL__E2_READ_MASK                     0x00008000L
#define MC_PERF_CNT2_SEL__E2_READ                          0x00008000L
#define MC_PERF_CNT2_SEL__VF_READ_MASK                     0x00010000L
#define MC_PERF_CNT2_SEL__VF_READ                          0x00010000L
#define MC_PERF_CNT2_SEL__CP_READ_MASK                     0x00020000L
#define MC_PERF_CNT2_SEL__CP_READ                          0x00020000L
#define MC_PERF_CNT2_SEL__CP_WRITE_MASK                    0x00040000L
#define MC_PERF_CNT2_SEL__CP_WRITE                         0x00040000L
#define MC_PERF_CNT2_SEL__VIP_READ_MASK                    0x00080000L
#define MC_PERF_CNT2_SEL__VIP_READ                         0x00080000L
#define MC_PERF_CNT2_SEL__VIP_WRITE_MASK                   0x00100000L
#define MC_PERF_CNT2_SEL__VIP_WRITE                        0x00100000L
#define MC_PERF_CNT2_SEL__IDCT_READ_MASK                   0x00200000L
#define MC_PERF_CNT2_SEL__IDCT_READ                        0x00200000L
#define MC_PERF_CNT2_SEL__IDCT_WRITE_MASK                  0x00400000L
#define MC_PERF_CNT2_SEL__IDCT_WRITE                       0x00400000L
#define MC_PERF_CNT2_SEL__HDP_READ_MASK                    0x00800000L
#define MC_PERF_CNT2_SEL__HDP_READ                         0x00800000L
#define MC_PERF_CNT2_SEL__HDP_WRITE_MASK                   0x01000000L
#define MC_PERF_CNT2_SEL__HDP_WRITE                        0x01000000L
#define MC_PERF_CNT2_SEL__REGION_AGPPCI_MASK               0x02000000L
#define MC_PERF_CNT2_SEL__REGION_AGPPCI                    0x02000000L
#define MC_PERF_CNT2_SEL__REGION_CHA_MASK                  0x04000000L
#define MC_PERF_CNT2_SEL__REGION_CHA                       0x04000000L
#define MC_PERF_CNT2_SEL__REGION_CHB_MASK                  0x08000000L
#define MC_PERF_CNT2_SEL__REGION_CHB                       0x08000000L
#define MC_PERF_CNT2_SEL__REGION_CHC_MASK                  0x10000000L
#define MC_PERF_CNT2_SEL__REGION_CHC                       0x10000000L
#define MC_PERF_CNT2_SEL__REGION_CHD_MASK                  0x20000000L
#define MC_PERF_CNT2_SEL__REGION_CHD                       0x20000000L
#define MC_PERF_CNT2_SEL__REGION_0_MASK                    0x40000000L
#define MC_PERF_CNT2_SEL__REGION_0                         0x40000000L
#define MC_PERF_CNT2_SEL__REGION_1_MASK                    0x80000000L
#define MC_PERF_CNT2_SEL__REGION_1                         0x80000000L

// MC_PERF_CNT3_SEL
#define MC_PERF_CNT3_SEL__G3D0_READ_MASK                   0x00000001L
#define MC_PERF_CNT3_SEL__G3D0_READ                        0x00000001L
#define MC_PERF_CNT3_SEL__G3D1_READ_MASK                   0x00000002L
#define MC_PERF_CNT3_SEL__G3D1_READ                        0x00000002L
#define MC_PERF_CNT3_SEL__G3D2_READ_MASK                   0x00000004L
#define MC_PERF_CNT3_SEL__G3D2_READ                        0x00000004L
#define MC_PERF_CNT3_SEL__G3D3_READ_MASK                   0x00000008L
#define MC_PERF_CNT3_SEL__G3D3_READ                        0x00000008L
#define MC_PERF_CNT3_SEL__TX0_READ_MASK                    0x00000010L
#define MC_PERF_CNT3_SEL__TX0_READ                         0x00000010L
#define MC_PERF_CNT3_SEL__TX1_READ_MASK                    0x00000020L
#define MC_PERF_CNT3_SEL__TX1_READ                         0x00000020L
#define MC_PERF_CNT3_SEL__G3D0_WRITE_MASK                  0x00000100L
#define MC_PERF_CNT3_SEL__G3D0_WRITE                       0x00000100L
#define MC_PERF_CNT3_SEL__G3D1_WRITE_MASK                  0x00000200L
#define MC_PERF_CNT3_SEL__G3D1_WRITE                       0x00000200L
#define MC_PERF_CNT3_SEL__G3D2_WRITE_MASK                  0x00000400L
#define MC_PERF_CNT3_SEL__G3D2_WRITE                       0x00000400L
#define MC_PERF_CNT3_SEL__G3D3_WRITE_MASK                  0x00000800L
#define MC_PERF_CNT3_SEL__G3D3_WRITE                       0x00000800L
#define MC_PERF_CNT3_SEL__DISP0_READ_MASK                  0x00001000L
#define MC_PERF_CNT3_SEL__DISP0_READ                       0x00001000L
#define MC_PERF_CNT3_SEL__DISP1_READ_MASK                  0x00002000L
#define MC_PERF_CNT3_SEL__DISP1_READ                       0x00002000L
#define MC_PERF_CNT3_SEL__OV0_READ_MASK                    0x00004000L
#define MC_PERF_CNT3_SEL__OV0_READ                         0x00004000L
#define MC_PERF_CNT3_SEL__E2_READ_MASK                     0x00008000L
#define MC_PERF_CNT3_SEL__E2_READ                          0x00008000L
#define MC_PERF_CNT3_SEL__VF_READ_MASK                     0x00010000L
#define MC_PERF_CNT3_SEL__VF_READ                          0x00010000L
#define MC_PERF_CNT3_SEL__CP_READ_MASK                     0x00020000L
#define MC_PERF_CNT3_SEL__CP_READ                          0x00020000L
#define MC_PERF_CNT3_SEL__CP_WRITE_MASK                    0x00040000L
#define MC_PERF_CNT3_SEL__CP_WRITE                         0x00040000L
#define MC_PERF_CNT3_SEL__VIP_READ_MASK                    0x00080000L
#define MC_PERF_CNT3_SEL__VIP_READ                         0x00080000L
#define MC_PERF_CNT3_SEL__VIP_WRITE_MASK                   0x00100000L
#define MC_PERF_CNT3_SEL__VIP_WRITE                        0x00100000L
#define MC_PERF_CNT3_SEL__IDCT_READ_MASK                   0x00200000L
#define MC_PERF_CNT3_SEL__IDCT_READ                        0x00200000L
#define MC_PERF_CNT3_SEL__IDCT_WRITE_MASK                  0x00400000L
#define MC_PERF_CNT3_SEL__IDCT_WRITE                       0x00400000L
#define MC_PERF_CNT3_SEL__HDP_READ_MASK                    0x00800000L
#define MC_PERF_CNT3_SEL__HDP_READ                         0x00800000L
#define MC_PERF_CNT3_SEL__HDP_WRITE_MASK                   0x01000000L
#define MC_PERF_CNT3_SEL__HDP_WRITE                        0x01000000L
#define MC_PERF_CNT3_SEL__REGION_AGPPCI_MASK               0x02000000L
#define MC_PERF_CNT3_SEL__REGION_AGPPCI                    0x02000000L
#define MC_PERF_CNT3_SEL__REGION_CHA_MASK                  0x04000000L
#define MC_PERF_CNT3_SEL__REGION_CHA                       0x04000000L
#define MC_PERF_CNT3_SEL__REGION_CHB_MASK                  0x08000000L
#define MC_PERF_CNT3_SEL__REGION_CHB                       0x08000000L
#define MC_PERF_CNT3_SEL__REGION_CHC_MASK                  0x10000000L
#define MC_PERF_CNT3_SEL__REGION_CHC                       0x10000000L
#define MC_PERF_CNT3_SEL__REGION_CHD_MASK                  0x20000000L
#define MC_PERF_CNT3_SEL__REGION_CHD                       0x20000000L
#define MC_PERF_CNT3_SEL__REGION_0_MASK                    0x40000000L
#define MC_PERF_CNT3_SEL__REGION_0                         0x40000000L
#define MC_PERF_CNT3_SEL__REGION_1_MASK                    0x80000000L
#define MC_PERF_CNT3_SEL__REGION_1                         0x80000000L

// MC_PERF_CNT4_SEL
#define MC_PERF_CNT4_SEL__G3D0_READ_MASK                   0x00000001L
#define MC_PERF_CNT4_SEL__G3D0_READ                        0x00000001L
#define MC_PERF_CNT4_SEL__G3D1_READ_MASK                   0x00000002L
#define MC_PERF_CNT4_SEL__G3D1_READ                        0x00000002L
#define MC_PERF_CNT4_SEL__G3D2_READ_MASK                   0x00000004L
#define MC_PERF_CNT4_SEL__G3D2_READ                        0x00000004L
#define MC_PERF_CNT4_SEL__G3D3_READ_MASK                   0x00000008L
#define MC_PERF_CNT4_SEL__G3D3_READ                        0x00000008L
#define MC_PERF_CNT4_SEL__TX0_READ_MASK                    0x00000010L
#define MC_PERF_CNT4_SEL__TX0_READ                         0x00000010L
#define MC_PERF_CNT4_SEL__TX1_READ_MASK                    0x00000020L
#define MC_PERF_CNT4_SEL__TX1_READ                         0x00000020L
#define MC_PERF_CNT4_SEL__G3D0_WRITE_MASK                  0x00000100L
#define MC_PERF_CNT4_SEL__G3D0_WRITE                       0x00000100L
#define MC_PERF_CNT4_SEL__G3D1_WRITE_MASK                  0x00000200L
#define MC_PERF_CNT4_SEL__G3D1_WRITE                       0x00000200L
#define MC_PERF_CNT4_SEL__G3D2_WRITE_MASK                  0x00000400L
#define MC_PERF_CNT4_SEL__G3D2_WRITE                       0x00000400L
#define MC_PERF_CNT4_SEL__G3D3_WRITE_MASK                  0x00000800L
#define MC_PERF_CNT4_SEL__G3D3_WRITE                       0x00000800L
#define MC_PERF_CNT4_SEL__DISP0_READ_MASK                  0x00001000L
#define MC_PERF_CNT4_SEL__DISP0_READ                       0x00001000L
#define MC_PERF_CNT4_SEL__DISP1_READ_MASK                  0x00002000L
#define MC_PERF_CNT4_SEL__DISP1_READ                       0x00002000L
#define MC_PERF_CNT4_SEL__OV0_READ_MASK                    0x00004000L
#define MC_PERF_CNT4_SEL__OV0_READ                         0x00004000L
#define MC_PERF_CNT4_SEL__E2_READ_MASK                     0x00008000L
#define MC_PERF_CNT4_SEL__E2_READ                          0x00008000L
#define MC_PERF_CNT4_SEL__VF_READ_MASK                     0x00010000L
#define MC_PERF_CNT4_SEL__VF_READ                          0x00010000L
#define MC_PERF_CNT4_SEL__CP_READ_MASK                     0x00020000L
#define MC_PERF_CNT4_SEL__CP_READ                          0x00020000L
#define MC_PERF_CNT4_SEL__CP_WRITE_MASK                    0x00040000L
#define MC_PERF_CNT4_SEL__CP_WRITE                         0x00040000L
#define MC_PERF_CNT4_SEL__VIP_READ_MASK                    0x00080000L
#define MC_PERF_CNT4_SEL__VIP_READ                         0x00080000L
#define MC_PERF_CNT4_SEL__VIP_WRITE_MASK                   0x00100000L
#define MC_PERF_CNT4_SEL__VIP_WRITE                        0x00100000L
#define MC_PERF_CNT4_SEL__IDCT_READ_MASK                   0x00200000L
#define MC_PERF_CNT4_SEL__IDCT_READ                        0x00200000L
#define MC_PERF_CNT4_SEL__IDCT_WRITE_MASK                  0x00400000L
#define MC_PERF_CNT4_SEL__IDCT_WRITE                       0x00400000L
#define MC_PERF_CNT4_SEL__HDP_READ_MASK                    0x00800000L
#define MC_PERF_CNT4_SEL__HDP_READ                         0x00800000L
#define MC_PERF_CNT4_SEL__HDP_WRITE_MASK                   0x01000000L
#define MC_PERF_CNT4_SEL__HDP_WRITE                        0x01000000L
#define MC_PERF_CNT4_SEL__REGION_AGPPCI_MASK               0x02000000L
#define MC_PERF_CNT4_SEL__REGION_AGPPCI                    0x02000000L
#define MC_PERF_CNT4_SEL__REGION_CHA_MASK                  0x04000000L
#define MC_PERF_CNT4_SEL__REGION_CHA                       0x04000000L
#define MC_PERF_CNT4_SEL__REGION_CHB_MASK                  0x08000000L
#define MC_PERF_CNT4_SEL__REGION_CHB                       0x08000000L
#define MC_PERF_CNT4_SEL__REGION_CHC_MASK                  0x10000000L
#define MC_PERF_CNT4_SEL__REGION_CHC                       0x10000000L
#define MC_PERF_CNT4_SEL__REGION_CHD_MASK                  0x20000000L
#define MC_PERF_CNT4_SEL__REGION_CHD                       0x20000000L
#define MC_PERF_CNT4_SEL__REGION_0_MASK                    0x40000000L
#define MC_PERF_CNT4_SEL__REGION_0                         0x40000000L
#define MC_PERF_CNT4_SEL__REGION_1_MASK                    0x80000000L
#define MC_PERF_CNT4_SEL__REGION_1                         0x80000000L

// MC_PERF_CNT5_SEL
#define MC_PERF_CNT5_SEL__G3D0_READ_MASK                   0x00000001L
#define MC_PERF_CNT5_SEL__G3D0_READ                        0x00000001L
#define MC_PERF_CNT5_SEL__G3D1_READ_MASK                   0x00000002L
#define MC_PERF_CNT5_SEL__G3D1_READ                        0x00000002L
#define MC_PERF_CNT5_SEL__G3D2_READ_MASK                   0x00000004L
#define MC_PERF_CNT5_SEL__G3D2_READ                        0x00000004L
#define MC_PERF_CNT5_SEL__G3D3_READ_MASK                   0x00000008L
#define MC_PERF_CNT5_SEL__G3D3_READ                        0x00000008L
#define MC_PERF_CNT5_SEL__TX0_READ_MASK                    0x00000010L
#define MC_PERF_CNT5_SEL__TX0_READ                         0x00000010L
#define MC_PERF_CNT5_SEL__TX1_READ_MASK                    0x00000020L
#define MC_PERF_CNT5_SEL__TX1_READ                         0x00000020L
#define MC_PERF_CNT5_SEL__G3D0_WRITE_MASK                  0x00000100L
#define MC_PERF_CNT5_SEL__G3D0_WRITE                       0x00000100L
#define MC_PERF_CNT5_SEL__G3D1_WRITE_MASK                  0x00000200L
#define MC_PERF_CNT5_SEL__G3D1_WRITE                       0x00000200L
#define MC_PERF_CNT5_SEL__G3D2_WRITE_MASK                  0x00000400L
#define MC_PERF_CNT5_SEL__G3D2_WRITE                       0x00000400L
#define MC_PERF_CNT5_SEL__G3D3_WRITE_MASK                  0x00000800L
#define MC_PERF_CNT5_SEL__G3D3_WRITE                       0x00000800L
#define MC_PERF_CNT5_SEL__DISP0_READ_MASK                  0x00001000L
#define MC_PERF_CNT5_SEL__DISP0_READ                       0x00001000L
#define MC_PERF_CNT5_SEL__DISP1_READ_MASK                  0x00002000L
#define MC_PERF_CNT5_SEL__DISP1_READ                       0x00002000L
#define MC_PERF_CNT5_SEL__OV0_READ_MASK                    0x00004000L
#define MC_PERF_CNT5_SEL__OV0_READ                         0x00004000L
#define MC_PERF_CNT5_SEL__E2_READ_MASK                     0x00008000L
#define MC_PERF_CNT5_SEL__E2_READ                          0x00008000L
#define MC_PERF_CNT5_SEL__VF_READ_MASK                     0x00010000L
#define MC_PERF_CNT5_SEL__VF_READ                          0x00010000L
#define MC_PERF_CNT5_SEL__CP_READ_MASK                     0x00020000L
#define MC_PERF_CNT5_SEL__CP_READ                          0x00020000L
#define MC_PERF_CNT5_SEL__CP_WRITE_MASK                    0x00040000L
#define MC_PERF_CNT5_SEL__CP_WRITE                         0x00040000L
#define MC_PERF_CNT5_SEL__VIP_READ_MASK                    0x00080000L
#define MC_PERF_CNT5_SEL__VIP_READ                         0x00080000L
#define MC_PERF_CNT5_SEL__VIP_WRITE_MASK                   0x00100000L
#define MC_PERF_CNT5_SEL__VIP_WRITE                        0x00100000L
#define MC_PERF_CNT5_SEL__IDCT_READ_MASK                   0x00200000L
#define MC_PERF_CNT5_SEL__IDCT_READ                        0x00200000L
#define MC_PERF_CNT5_SEL__IDCT_WRITE_MASK                  0x00400000L
#define MC_PERF_CNT5_SEL__IDCT_WRITE                       0x00400000L
#define MC_PERF_CNT5_SEL__HDP_READ_MASK                    0x00800000L
#define MC_PERF_CNT5_SEL__HDP_READ                         0x00800000L
#define MC_PERF_CNT5_SEL__HDP_WRITE_MASK                   0x01000000L
#define MC_PERF_CNT5_SEL__HDP_WRITE                        0x01000000L
#define MC_PERF_CNT5_SEL__REGION_AGPPCI_MASK               0x02000000L
#define MC_PERF_CNT5_SEL__REGION_AGPPCI                    0x02000000L
#define MC_PERF_CNT5_SEL__REGION_CHA_MASK                  0x04000000L
#define MC_PERF_CNT5_SEL__REGION_CHA                       0x04000000L
#define MC_PERF_CNT5_SEL__REGION_CHB_MASK                  0x08000000L
#define MC_PERF_CNT5_SEL__REGION_CHB                       0x08000000L
#define MC_PERF_CNT5_SEL__REGION_CHC_MASK                  0x10000000L
#define MC_PERF_CNT5_SEL__REGION_CHC                       0x10000000L
#define MC_PERF_CNT5_SEL__REGION_CHD_MASK                  0x20000000L
#define MC_PERF_CNT5_SEL__REGION_CHD                       0x20000000L
#define MC_PERF_CNT5_SEL__REGION_0_MASK                    0x40000000L
#define MC_PERF_CNT5_SEL__REGION_0                         0x40000000L
#define MC_PERF_CNT5_SEL__REGION_1_MASK                    0x80000000L
#define MC_PERF_CNT5_SEL__REGION_1                         0x80000000L

// MC_PERF_CNT6_SEL
#define MC_PERF_CNT6_SEL__G3D0_READ_MASK                   0x00000001L
#define MC_PERF_CNT6_SEL__G3D0_READ                        0x00000001L
#define MC_PERF_CNT6_SEL__G3D1_READ_MASK                   0x00000002L
#define MC_PERF_CNT6_SEL__G3D1_READ                        0x00000002L
#define MC_PERF_CNT6_SEL__G3D2_READ_MASK                   0x00000004L
#define MC_PERF_CNT6_SEL__G3D2_READ                        0x00000004L
#define MC_PERF_CNT6_SEL__G3D3_READ_MASK                   0x00000008L
#define MC_PERF_CNT6_SEL__G3D3_READ                        0x00000008L
#define MC_PERF_CNT6_SEL__TX0_READ_MASK                    0x00000010L
#define MC_PERF_CNT6_SEL__TX0_READ                         0x00000010L
#define MC_PERF_CNT6_SEL__TX1_READ_MASK                    0x00000020L
#define MC_PERF_CNT6_SEL__TX1_READ                         0x00000020L
#define MC_PERF_CNT6_SEL__G3D0_WRITE_MASK                  0x00000100L
#define MC_PERF_CNT6_SEL__G3D0_WRITE                       0x00000100L
#define MC_PERF_CNT6_SEL__G3D1_WRITE_MASK                  0x00000200L
#define MC_PERF_CNT6_SEL__G3D1_WRITE                       0x00000200L
#define MC_PERF_CNT6_SEL__G3D2_WRITE_MASK                  0x00000400L
#define MC_PERF_CNT6_SEL__G3D2_WRITE                       0x00000400L
#define MC_PERF_CNT6_SEL__G3D3_WRITE_MASK                  0x00000800L
#define MC_PERF_CNT6_SEL__G3D3_WRITE                       0x00000800L
#define MC_PERF_CNT6_SEL__DISP0_READ_MASK                  0x00001000L
#define MC_PERF_CNT6_SEL__DISP0_READ                       0x00001000L
#define MC_PERF_CNT6_SEL__DISP1_READ_MASK                  0x00002000L
#define MC_PERF_CNT6_SEL__DISP1_READ                       0x00002000L
#define MC_PERF_CNT6_SEL__OV0_READ_MASK                    0x00004000L
#define MC_PERF_CNT6_SEL__OV0_READ                         0x00004000L
#define MC_PERF_CNT6_SEL__E2_READ_MASK                     0x00008000L
#define MC_PERF_CNT6_SEL__E2_READ                          0x00008000L
#define MC_PERF_CNT6_SEL__VF_READ_MASK                     0x00010000L
#define MC_PERF_CNT6_SEL__VF_READ                          0x00010000L
#define MC_PERF_CNT6_SEL__CP_READ_MASK                     0x00020000L
#define MC_PERF_CNT6_SEL__CP_READ                          0x00020000L
#define MC_PERF_CNT6_SEL__CP_WRITE_MASK                    0x00040000L
#define MC_PERF_CNT6_SEL__CP_WRITE                         0x00040000L
#define MC_PERF_CNT6_SEL__VIP_READ_MASK                    0x00080000L
#define MC_PERF_CNT6_SEL__VIP_READ                         0x00080000L
#define MC_PERF_CNT6_SEL__VIP_WRITE_MASK                   0x00100000L
#define MC_PERF_CNT6_SEL__VIP_WRITE                        0x00100000L
#define MC_PERF_CNT6_SEL__IDCT_READ_MASK                   0x00200000L
#define MC_PERF_CNT6_SEL__IDCT_READ                        0x00200000L
#define MC_PERF_CNT6_SEL__IDCT_WRITE_MASK                  0x00400000L
#define MC_PERF_CNT6_SEL__IDCT_WRITE                       0x00400000L
#define MC_PERF_CNT6_SEL__HDP_READ_MASK                    0x00800000L
#define MC_PERF_CNT6_SEL__HDP_READ                         0x00800000L
#define MC_PERF_CNT6_SEL__HDP_WRITE_MASK                   0x01000000L
#define MC_PERF_CNT6_SEL__HDP_WRITE                        0x01000000L
#define MC_PERF_CNT6_SEL__REGION_AGPPCI_MASK               0x02000000L
#define MC_PERF_CNT6_SEL__REGION_AGPPCI                    0x02000000L
#define MC_PERF_CNT6_SEL__REGION_CHA_MASK                  0x04000000L
#define MC_PERF_CNT6_SEL__REGION_CHA                       0x04000000L
#define MC_PERF_CNT6_SEL__REGION_CHB_MASK                  0x08000000L
#define MC_PERF_CNT6_SEL__REGION_CHB                       0x08000000L
#define MC_PERF_CNT6_SEL__REGION_CHC_MASK                  0x10000000L
#define MC_PERF_CNT6_SEL__REGION_CHC                       0x10000000L
#define MC_PERF_CNT6_SEL__REGION_CHD_MASK                  0x20000000L
#define MC_PERF_CNT6_SEL__REGION_CHD                       0x20000000L
#define MC_PERF_CNT6_SEL__REGION_0_MASK                    0x40000000L
#define MC_PERF_CNT6_SEL__REGION_0                         0x40000000L
#define MC_PERF_CNT6_SEL__REGION_1_MASK                    0x80000000L
#define MC_PERF_CNT6_SEL__REGION_1                         0x80000000L

// MC_PERF_CNT7_SEL
#define MC_PERF_CNT7_SEL__G3D0_READ_MASK                   0x00000001L
#define MC_PERF_CNT7_SEL__G3D0_READ                        0x00000001L
#define MC_PERF_CNT7_SEL__G3D1_READ_MASK                   0x00000002L
#define MC_PERF_CNT7_SEL__G3D1_READ                        0x00000002L
#define MC_PERF_CNT7_SEL__G3D2_READ_MASK                   0x00000004L
#define MC_PERF_CNT7_SEL__G3D2_READ                        0x00000004L
#define MC_PERF_CNT7_SEL__G3D3_READ_MASK                   0x00000008L
#define MC_PERF_CNT7_SEL__G3D3_READ                        0x00000008L
#define MC_PERF_CNT7_SEL__TX0_READ_MASK                    0x00000010L
#define MC_PERF_CNT7_SEL__TX0_READ                         0x00000010L
#define MC_PERF_CNT7_SEL__TX1_READ_MASK                    0x00000020L
#define MC_PERF_CNT7_SEL__TX1_READ                         0x00000020L
#define MC_PERF_CNT7_SEL__G3D0_WRITE_MASK                  0x00000100L
#define MC_PERF_CNT7_SEL__G3D0_WRITE                       0x00000100L
#define MC_PERF_CNT7_SEL__G3D1_WRITE_MASK                  0x00000200L
#define MC_PERF_CNT7_SEL__G3D1_WRITE                       0x00000200L
#define MC_PERF_CNT7_SEL__G3D2_WRITE_MASK                  0x00000400L
#define MC_PERF_CNT7_SEL__G3D2_WRITE                       0x00000400L
#define MC_PERF_CNT7_SEL__G3D3_WRITE_MASK                  0x00000800L
#define MC_PERF_CNT7_SEL__G3D3_WRITE                       0x00000800L
#define MC_PERF_CNT7_SEL__DISP0_READ_MASK                  0x00001000L
#define MC_PERF_CNT7_SEL__DISP0_READ                       0x00001000L
#define MC_PERF_CNT7_SEL__DISP1_READ_MASK                  0x00002000L
#define MC_PERF_CNT7_SEL__DISP1_READ                       0x00002000L
#define MC_PERF_CNT7_SEL__OV0_READ_MASK                    0x00004000L
#define MC_PERF_CNT7_SEL__OV0_READ                         0x00004000L
#define MC_PERF_CNT7_SEL__E2_READ_MASK                     0x00008000L
#define MC_PERF_CNT7_SEL__E2_READ                          0x00008000L
#define MC_PERF_CNT7_SEL__VF_READ_MASK                     0x00010000L
#define MC_PERF_CNT7_SEL__VF_READ                          0x00010000L
#define MC_PERF_CNT7_SEL__CP_READ_MASK                     0x00020000L
#define MC_PERF_CNT7_SEL__CP_READ                          0x00020000L
#define MC_PERF_CNT7_SEL__CP_WRITE_MASK                    0x00040000L
#define MC_PERF_CNT7_SEL__CP_WRITE                         0x00040000L
#define MC_PERF_CNT7_SEL__VIP_READ_MASK                    0x00080000L
#define MC_PERF_CNT7_SEL__VIP_READ                         0x00080000L
#define MC_PERF_CNT7_SEL__VIP_WRITE_MASK                   0x00100000L
#define MC_PERF_CNT7_SEL__VIP_WRITE                        0x00100000L
#define MC_PERF_CNT7_SEL__IDCT_READ_MASK                   0x00200000L
#define MC_PERF_CNT7_SEL__IDCT_READ                        0x00200000L
#define MC_PERF_CNT7_SEL__IDCT_WRITE_MASK                  0x00400000L
#define MC_PERF_CNT7_SEL__IDCT_WRITE                       0x00400000L
#define MC_PERF_CNT7_SEL__HDP_READ_MASK                    0x00800000L
#define MC_PERF_CNT7_SEL__HDP_READ                         0x00800000L
#define MC_PERF_CNT7_SEL__HDP_WRITE_MASK                   0x01000000L
#define MC_PERF_CNT7_SEL__HDP_WRITE                        0x01000000L
#define MC_PERF_CNT7_SEL__REGION_AGPPCI_MASK               0x02000000L
#define MC_PERF_CNT7_SEL__REGION_AGPPCI                    0x02000000L
#define MC_PERF_CNT7_SEL__REGION_CHA_MASK                  0x04000000L
#define MC_PERF_CNT7_SEL__REGION_CHA                       0x04000000L
#define MC_PERF_CNT7_SEL__REGION_CHB_MASK                  0x08000000L
#define MC_PERF_CNT7_SEL__REGION_CHB                       0x08000000L
#define MC_PERF_CNT7_SEL__REGION_CHC_MASK                  0x10000000L
#define MC_PERF_CNT7_SEL__REGION_CHC                       0x10000000L
#define MC_PERF_CNT7_SEL__REGION_CHD_MASK                  0x20000000L
#define MC_PERF_CNT7_SEL__REGION_CHD                       0x20000000L
#define MC_PERF_CNT7_SEL__REGION_0_MASK                    0x40000000L
#define MC_PERF_CNT7_SEL__REGION_0                         0x40000000L
#define MC_PERF_CNT7_SEL__REGION_1_MASK                    0x80000000L
#define MC_PERF_CNT7_SEL__REGION_1                         0x80000000L

// MC_PERF_MEMCH_SEL
#define MC_PERF_MEMCH_SEL__CH_A_SEQBUSY_MASK               0x00000001L
#define MC_PERF_MEMCH_SEL__CH_A_SEQBUSY                    0x00000001L
#define MC_PERF_MEMCH_SEL__CH_A_DATATFR_MASK               0x00000002L
#define MC_PERF_MEMCH_SEL__CH_A_DATATFR                    0x00000002L
#define MC_PERF_MEMCH_SEL__CH_A_PAGEOPEN_MASK              0x00000004L
#define MC_PERF_MEMCH_SEL__CH_A_PAGEOPEN                   0x00000004L
#define MC_PERF_MEMCH_SEL__CH_A_PAGECLOSE_MASK             0x00000008L
#define MC_PERF_MEMCH_SEL__CH_A_PAGECLOSE                  0x00000008L
#define MC_PERF_MEMCH_SEL__CH_A_R2W_MASK                   0x00000010L
#define MC_PERF_MEMCH_SEL__CH_A_R2W                        0x00000010L
#define MC_PERF_MEMCH_SEL__CH_A_W2R_MASK                   0x00000020L
#define MC_PERF_MEMCH_SEL__CH_A_W2R                        0x00000020L
#define MC_PERF_MEMCH_SEL__CH_A_REFRESH_MASK               0x00000040L
#define MC_PERF_MEMCH_SEL__CH_A_REFRESH                    0x00000040L
#define MC_PERF_MEMCH_SEL__CH_A_NOP_MASK                   0x00000080L
#define MC_PERF_MEMCH_SEL__CH_A_NOP                        0x00000080L
#define MC_PERF_MEMCH_SEL__CH_B_SEQBUSY_MASK               0x00000100L
#define MC_PERF_MEMCH_SEL__CH_B_SEQBUSY                    0x00000100L
#define MC_PERF_MEMCH_SEL__CH_B_DATATFR_MASK               0x00000200L
#define MC_PERF_MEMCH_SEL__CH_B_DATATFR                    0x00000200L
#define MC_PERF_MEMCH_SEL__CH_B_PAGEOPEN_MASK              0x00000400L
#define MC_PERF_MEMCH_SEL__CH_B_PAGEOPEN                   0x00000400L
#define MC_PERF_MEMCH_SEL__CH_B_PAGECLOSE_MASK             0x00000800L
#define MC_PERF_MEMCH_SEL__CH_B_PAGECLOSE                  0x00000800L
#define MC_PERF_MEMCH_SEL__CH_B_R2W_MASK                   0x00001000L
#define MC_PERF_MEMCH_SEL__CH_B_R2W                        0x00001000L
#define MC_PERF_MEMCH_SEL__CH_B_W2R_MASK                   0x00002000L
#define MC_PERF_MEMCH_SEL__CH_B_W2R                        0x00002000L
#define MC_PERF_MEMCH_SEL__CH_B_REFRESH_MASK               0x00004000L
#define MC_PERF_MEMCH_SEL__CH_B_REFRESH                    0x00004000L
#define MC_PERF_MEMCH_SEL__CH_B_NOP_MASK                   0x00008000L
#define MC_PERF_MEMCH_SEL__CH_B_NOP                        0x00008000L
#define MC_PERF_MEMCH_SEL__CH_C_SEQBUSY_MASK               0x00010000L
#define MC_PERF_MEMCH_SEL__CH_C_SEQBUSY                    0x00010000L
#define MC_PERF_MEMCH_SEL__CH_C_DATATFR_MASK               0x00020000L
#define MC_PERF_MEMCH_SEL__CH_C_DATATFR                    0x00020000L
#define MC_PERF_MEMCH_SEL__CH_C_PAGEOPEN_MASK              0x00040000L
#define MC_PERF_MEMCH_SEL__CH_C_PAGEOPEN                   0x00040000L
#define MC_PERF_MEMCH_SEL__CH_C_PAGECLOSE_MASK             0x00080000L
#define MC_PERF_MEMCH_SEL__CH_C_PAGECLOSE                  0x00080000L
#define MC_PERF_MEMCH_SEL__CH_C_R2W_MASK                   0x00100000L
#define MC_PERF_MEMCH_SEL__CH_C_R2W                        0x00100000L
#define MC_PERF_MEMCH_SEL__CH_C_W2R_MASK                   0x00200000L
#define MC_PERF_MEMCH_SEL__CH_C_W2R                        0x00200000L
#define MC_PERF_MEMCH_SEL__CH_C_REFRESH_MASK               0x00400000L
#define MC_PERF_MEMCH_SEL__CH_C_REFRESH                    0x00400000L
#define MC_PERF_MEMCH_SEL__CH_C_NOP_MASK                   0x00800000L
#define MC_PERF_MEMCH_SEL__CH_C_NOP                        0x00800000L
#define MC_PERF_MEMCH_SEL__CH_D_SEQBUSY_MASK               0x01000000L
#define MC_PERF_MEMCH_SEL__CH_D_SEQBUSY                    0x01000000L
#define MC_PERF_MEMCH_SEL__CH_D_DATATFR_MASK               0x02000000L
#define MC_PERF_MEMCH_SEL__CH_D_DATATFR                    0x02000000L
#define MC_PERF_MEMCH_SEL__CH_D_PAGEOPEN_MASK              0x04000000L
#define MC_PERF_MEMCH_SEL__CH_D_PAGEOPEN                   0x04000000L
#define MC_PERF_MEMCH_SEL__CH_D_PAGECLOSE_MASK             0x08000000L
#define MC_PERF_MEMCH_SEL__CH_D_PAGECLOSE                  0x08000000L
#define MC_PERF_MEMCH_SEL__CH_D_R2W_MASK                   0x10000000L
#define MC_PERF_MEMCH_SEL__CH_D_R2W                        0x10000000L
#define MC_PERF_MEMCH_SEL__CH_D_W2R_MASK                   0x20000000L
#define MC_PERF_MEMCH_SEL__CH_D_W2R                        0x20000000L
#define MC_PERF_MEMCH_SEL__CH_D_REFRESH_MASK               0x40000000L
#define MC_PERF_MEMCH_SEL__CH_D_REFRESH                    0x40000000L
#define MC_PERF_MEMCH_SEL__CH_D_NOP_MASK                   0x80000000L
#define MC_PERF_MEMCH_SEL__CH_D_NOP                        0x80000000L

// MC_PERF_REGION_0_R3
#define MC_PERF_REGION_0_R3__SIZE_MASK                     0x00000fffL
#define MC_PERF_REGION_0_R3__ADDRESS_MASK                  0xfffff000L

// MC_PERF_REGION_1_R3
#define MC_PERF_REGION_1_R3__SIZE_MASK                     0x00000fffL
#define MC_PERF_REGION_1_R3__ADDRESS_MASK                  0xfffff000L

// MC_PERF_COUNT_0_R3
#define MC_PERF_COUNT_0_R3__PERF_COUNT_MASK                0xffffffffL

// MC_PERF_COUNT_1_R3
#define MC_PERF_COUNT_1_R3__PERF_COUNT_MASK                0xffffffffL

// MC_PERF_COUNT_2_R3
#define MC_PERF_COUNT_2_R3__PERF_COUNT_MASK                0xffffffffL

// MC_PERF_COUNT_3_R3
#define MC_PERF_COUNT_3_R3__PERF_COUNT_MASK                0xffffffffL

// MC_PERF_COUNT_4
#define MC_PERF_COUNT_4__PERF_COUNT_MASK                   0xffffffffL

// MC_PERF_COUNT_5
#define MC_PERF_COUNT_5__PERF_COUNT_MASK                   0xffffffffL

// MC_PERF_COUNT_6
#define MC_PERF_COUNT_6__PERF_COUNT_MASK                   0xffffffffL

// MC_PERF_COUNT_7
#define MC_PERF_COUNT_7__PERF_COUNT_MASK                   0xffffffffL

// MC_PERF_COUNT_MEMCH_A_R3
#define MC_PERF_COUNT_MEMCH_A_R3__PERF_COUNT_MEM_CH_A_MASK 0xffffffffL

// MC_PERF_COUNT_MEMCH_B_R3
#define MC_PERF_COUNT_MEMCH_B_R3__PERF_COUNT_MEM_CH_B_MASK 0xffffffffL

// MC_PERF_COUNT_MEMCH_C
#define MC_PERF_COUNT_MEMCH_C__PERF_COUNT_MEM_CH_C_MASK    0xffffffffL

// MC_PERF_COUNT_MEMCH_D
#define MC_PERF_COUNT_MEMCH_D__PERF_COUNT_MEM_CH_D_MASK    0xffffffffL

// MC_IMP_CNTL_R3
#define MC_IMP_CNTL_R3__MEM_IO_UPDATE_RATE_MASK            0x0000001fL
#define MC_IMP_CNTL_R3__MEM_IO_SAMPLE_DELAY_MASK           0x000003e0L
#define MC_IMP_CNTL_R3__MEM_IO_INC_THRESHOLD_MASK          0x00007c00L
#define MC_IMP_CNTL_R3__MEM_IO_DEC_THRESHOLD_MASK          0x000f8000L
#define MC_IMP_CNTL_R3__MEM_IO_MANUAL_OVERRIDE_CK_MASK     0x00100000L
#define MC_IMP_CNTL_R3__MEM_IO_MANUAL_OVERRIDE_CK          0x00100000L
#define MC_IMP_CNTL_R3__MEM_IO_MANUAL_OVERRIDE_A_MASK      0x00200000L
#define MC_IMP_CNTL_R3__MEM_IO_MANUAL_OVERRIDE_A           0x00200000L
#define MC_IMP_CNTL_R3__MEM_IO_MANUAL_OVERRIDE_DQM_MASK    0x00400000L
#define MC_IMP_CNTL_R3__MEM_IO_MANUAL_OVERRIDE_DQM         0x00400000L
#define MC_IMP_CNTL_R3__MEM_IO_MANUAL_OVERRIDE_DQS_MASK    0x00800000L
#define MC_IMP_CNTL_R3__MEM_IO_MANUAL_OVERRIDE_DQS         0x00800000L
#define MC_IMP_CNTL_R3__MEM_IO_SLEWN_MASK                  0x01000000L
#define MC_IMP_CNTL_R3__MEM_IO_SLEWN                       0x01000000L
#define MC_IMP_CNTL_R3__MEM_IO_SLEWP_MASK                  0x02000000L
#define MC_IMP_CNTL_R3__MEM_IO_SLEWP                       0x02000000L
#define MC_IMP_CNTL_R3__MEM_IO_IMP_SAMPLE_IDLE_MASK        0x04000000L
#define MC_IMP_CNTL_R3__MEM_IO_IMP_SAMPLE_IDLE             0x04000000L
#define MC_IMP_CNTL_R3__MEM_IO_IMP_DEBUG_EN_MASK           0x08000000L
#define MC_IMP_CNTL_R3__MEM_IO_IMP_DEBUG_EN                0x08000000L
#define MC_IMP_CNTL_R3__TEST_OUT_R_BACK_MASK               0x10000000L
#define MC_IMP_CNTL_R3__TEST_OUT_R_BACK                    0x10000000L
#define MC_IMP_CNTL_R3__DUMMY_OUT_R_BACK_MASK              0x20000000L
#define MC_IMP_CNTL_R3__DUMMY_OUT_R_BACK                   0x20000000L

// MC_CHP_IO_CNTL_A0_R3
#define MC_CHP_IO_CNTL_A0_R3__MEM_N_CKA_MASK               0x0000000fL
#define MC_CHP_IO_CNTL_A0_R3__MEM_N_AA_MASK                0x000000f0L
#define MC_CHP_IO_CNTL_A0_R3__MEM_N_DQMA_MASK              0x00000f00L
#define MC_CHP_IO_CNTL_A0_R3__MEM_N_DQSA_MASK              0x0000f000L
#define MC_CHP_IO_CNTL_A0_R3__MEM_P_CKA_MASK               0x000f0000L
#define MC_CHP_IO_CNTL_A0_R3__MEM_P_AA_MASK                0x00f00000L
#define MC_CHP_IO_CNTL_A0_R3__MEM_P_DQMA_MASK              0x0f000000L
#define MC_CHP_IO_CNTL_A0_R3__MEM_P_DQSA_MASK              0xf0000000L

// MC_CHP_IO_CNTL_A1_R3
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWN_CKA_MASK           0x00000001L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWN_CKA                0x00000001L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWN_AA_MASK            0x00000002L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWN_AA                 0x00000002L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWN_DQMA_MASK          0x00000004L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWN_DQMA               0x00000004L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWN_DQSA_MASK          0x00000008L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWN_DQSA               0x00000008L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWP_CKA_MASK           0x00000010L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWP_CKA                0x00000010L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWP_AA_MASK            0x00000020L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWP_AA                 0x00000020L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWP_DQMA_MASK          0x00000040L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWP_DQMA               0x00000040L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWP_DQSA_MASK          0x00000080L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SLEWP_DQSA               0x00000080L
#define MC_CHP_IO_CNTL_A1_R3__MEM_PREAMP_AA_MASK           0x00000100L
#define MC_CHP_IO_CNTL_A1_R3__MEM_PREAMP_AA                0x00000100L
#define MC_CHP_IO_CNTL_A1_R3__MEM_PREAMP_DQMA_MASK         0x00000200L
#define MC_CHP_IO_CNTL_A1_R3__MEM_PREAMP_DQMA              0x00000200L
#define MC_CHP_IO_CNTL_A1_R3__MEM_PREAMP_DQSA_MASK         0x00000400L
#define MC_CHP_IO_CNTL_A1_R3__MEM_PREAMP_DQSA              0x00000400L
#define MC_CHP_IO_CNTL_A1_R3__MEM_IO_QS_PDA_MASK           0x00000800L
#define MC_CHP_IO_CNTL_A1_R3__MEM_IO_QS_PDA                0x00000800L
#define MC_CHP_IO_CNTL_A1_R3__MEM_IO_MODEA_MASK            0x00003000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_REC_CKA_MASK             0x0000c000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_REC_AA_MASK              0x00030000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_REC_DQMA_MASK            0x000c0000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_REC_DQSA_MASK            0x00300000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SYNC_PHASEA_MASK         0x00400000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SYNC_PHASEA              0x00400000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SYNC_CENTERA_MASK        0x00800000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SYNC_CENTERA             0x00800000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_SYNC_ENA_MASK            0x03000000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_CLK_SELA_MASK            0x0c000000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_CLK_INVA_MASK            0x10000000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_CLK_INVA                 0x10000000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_DATA_ENIMP_A_MASK        0x40000000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_DATA_ENIMP_A             0x40000000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_CNTL_ENIMP_A_MASK        0x80000000L
#define MC_CHP_IO_CNTL_A1_R3__MEM_CNTL_ENIMP_A             0x80000000L

// MC_CHP_IO_CNTL_B0_R3
#define MC_CHP_IO_CNTL_B0_R3__MEM_N_CKB_MASK               0x0000000fL
#define MC_CHP_IO_CNTL_B0_R3__MEM_N_AB_MASK                0x000000f0L
#define MC_CHP_IO_CNTL_B0_R3__MEM_N_DQMB_MASK              0x00000f00L
#define MC_CHP_IO_CNTL_B0_R3__MEM_N_DQSB_MASK              0x0000f000L
#define MC_CHP_IO_CNTL_B0_R3__MEM_P_CKB_MASK               0x000f0000L
#define MC_CHP_IO_CNTL_B0_R3__MEM_P_AB_MASK                0x00f00000L
#define MC_CHP_IO_CNTL_B0_R3__MEM_P_DQMB_MASK              0x0f000000L
#define MC_CHP_IO_CNTL_B0_R3__MEM_P_DQSB_MASK              0xf0000000L

// MC_CHP_IO_CNTL_B1_R3
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWN_CKB_MASK           0x00000001L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWN_CKB                0x00000001L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWN_AB_MASK            0x00000002L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWN_AB                 0x00000002L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWN_DQMB_MASK          0x00000004L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWN_DQMB               0x00000004L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWN_DQSB_MASK          0x00000008L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWN_DQSB               0x00000008L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWP_CKB_MASK           0x00000010L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWP_CKB                0x00000010L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWP_AB_MASK            0x00000020L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWP_AB                 0x00000020L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWP_DQMB_MASK          0x00000040L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWP_DQMB               0x00000040L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWP_DQSB_MASK          0x00000080L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SLEWP_DQSB               0x00000080L
#define MC_CHP_IO_CNTL_B1_R3__MEM_PREAMP_AB_MASK           0x00000100L
#define MC_CHP_IO_CNTL_B1_R3__MEM_PREAMP_AB                0x00000100L
#define MC_CHP_IO_CNTL_B1_R3__MEM_PREAMP_DQMB_MASK         0x00000200L
#define MC_CHP_IO_CNTL_B1_R3__MEM_PREAMP_DQMB              0x00000200L
#define MC_CHP_IO_CNTL_B1_R3__MEM_PREAMP_DQSB_MASK         0x00000400L
#define MC_CHP_IO_CNTL_B1_R3__MEM_PREAMP_DQSB              0x00000400L
#define MC_CHP_IO_CNTL_B1_R3__MEM_IO_QS_PDB_MASK           0x00000800L
#define MC_CHP_IO_CNTL_B1_R3__MEM_IO_QS_PDB                0x00000800L
#define MC_CHP_IO_CNTL_B1_R3__MEM_IO_MODEB_MASK            0x00003000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_REC_CKB_MASK             0x0000c000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_REC_AB_MASK              0x00030000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_REC_DQMB_MASK            0x000c0000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_REC_DQSB_MASK            0x00300000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SYNC_PHASEB_MASK         0x00400000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SYNC_PHASEB              0x00400000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SYNC_CENTERB_MASK        0x00800000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SYNC_CENTERB             0x00800000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_SYNC_ENB_MASK            0x03000000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_CLK_SELB_MASK            0x0c000000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_CLK_INVB_MASK            0x10000000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_CLK_INVB                 0x10000000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_DATA_ENIMP_B_MASK        0x40000000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_DATA_ENIMP_B             0x40000000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_CNTL_ENIMP_B_MASK        0x80000000L
#define MC_CHP_IO_CNTL_B1_R3__MEM_CNTL_ENIMP_B             0x80000000L

// MC_CHP_IO_CNTL_C0
#define MC_CHP_IO_CNTL_C0__MEM_N_CKC_MASK                  0x0000000fL
#define MC_CHP_IO_CNTL_C0__MEM_N_AC_MASK                   0x000000f0L
#define MC_CHP_IO_CNTL_C0__MEM_N_DQMC_MASK                 0x00000f00L
#define MC_CHP_IO_CNTL_C0__MEM_N_DQSC_MASK                 0x0000f000L
#define MC_CHP_IO_CNTL_C0__MEM_P_CKC_MASK                  0x000f0000L
#define MC_CHP_IO_CNTL_C0__MEM_P_AC_MASK                   0x00f00000L
#define MC_CHP_IO_CNTL_C0__MEM_P_DQMC_MASK                 0x0f000000L
#define MC_CHP_IO_CNTL_C0__MEM_P_DQSC_MASK                 0xf0000000L

// MC_CHP_IO_CNTL_C1
#define MC_CHP_IO_CNTL_C1__MEM_SLEWN_CKC_MASK              0x00000001L
#define MC_CHP_IO_CNTL_C1__MEM_SLEWN_CKC                   0x00000001L
#define MC_CHP_IO_CNTL_C1__MEM_SLEWN_AC_MASK               0x00000002L
#define MC_CHP_IO_CNTL_C1__MEM_SLEWN_AC                    0x00000002L
#define MC_CHP_IO_CNTL_C1__MEM_SLEWN_DQMC_MASK             0x00000004L
#define MC_CHP_IO_CNTL_C1__MEM_SLEWN_DQMC                  0x00000004L
#define MC_CHP_IO_CNTL_C1__MEM_SLEWN_DQSC_MASK             0x00000008L
#define MC_CHP_IO_CNTL_C1__MEM_SLEWN_DQSC                  0x00000008L
#define MC_CHP_IO_CNTL_C1__MEM_SLEWP_CKC_MASK              0x00000010L
#define MC_CHP_IO_CNTL_C1__MEM_SLEWP_CKC                   0x00000010L
#define MC_CHP_IO_CNTL_C1__MEM_SLEWP_AC_MASK               0x00000020L
#define MC_CHP_IO_CNTL_C1__MEM_SLEWP_AC                    0x00000020L
#define MC_CHP_IO_CNTL_C1__MEM_SLEWP_DQMC_MASK             0x00000040L
#define MC_CHP_IO_CNTL_C1__MEM_SLEWP_DQMC                  0x00000040L
#define MC_CHP_IO_CNTL_C1__MEM_SLEWP_DQSC_MASK             0x00000080L
#define MC_CHP_IO_CNTL_C1__MEM_SLEWP_DQSC                  0x00000080L
#define MC_CHP_IO_CNTL_C1__MEM_PREAMP_AC_MASK              0x00000100L
#define MC_CHP_IO_CNTL_C1__MEM_PREAMP_AC                   0x00000100L
#define MC_CHP_IO_CNTL_C1__MEM_PREAMP_DQMC_MASK            0x00000200L
#define MC_CHP_IO_CNTL_C1__MEM_PREAMP_DQMC                 0x00000200L
#define MC_CHP_IO_CNTL_C1__MEM_PREAMP_DQSC_MASK            0x00000400L
#define MC_CHP_IO_CNTL_C1__MEM_PREAMP_DQSC                 0x00000400L
#define MC_CHP_IO_CNTL_C1__MEM_IO_QS_PDC_MASK              0x00000800L
#define MC_CHP_IO_CNTL_C1__MEM_IO_QS_PDC                   0x00000800L
#define MC_CHP_IO_CNTL_C1__MEM_IO_MODEC_MASK               0x00003000L
#define MC_CHP_IO_CNTL_C1__MEM_REC_CKC_MASK                0x0000c000L
#define MC_CHP_IO_CNTL_C1__MEM_REC_AC_MASK                 0x00030000L
#define MC_CHP_IO_CNTL_C1__MEM_REC_DQMC_MASK               0x000c0000L
#define MC_CHP_IO_CNTL_C1__MEM_REC_DQSC_MASK               0x00300000L
#define MC_CHP_IO_CNTL_C1__MEM_SYNC_PHASEC_MASK            0x00400000L
#define MC_CHP_IO_CNTL_C1__MEM_SYNC_PHASEC                 0x00400000L
#define MC_CHP_IO_CNTL_C1__MEM_SYNC_CENTERC_MASK           0x00800000L
#define MC_CHP_IO_CNTL_C1__MEM_SYNC_CENTERC                0x00800000L
#define MC_CHP_IO_CNTL_C1__MEM_SYNC_ENC_MASK               0x03000000L
#define MC_CHP_IO_CNTL_C1__MEM_CLK_SELC_MASK               0x0c000000L
#define MC_CHP_IO_CNTL_C1__MEM_CLK_INVC_MASK               0x10000000L
#define MC_CHP_IO_CNTL_C1__MEM_CLK_INVC                    0x10000000L
#define MC_CHP_IO_CNTL_C1__MEM_DATA_ENIMP_C_MASK           0x40000000L
#define MC_CHP_IO_CNTL_C1__MEM_DATA_ENIMP_C                0x40000000L
#define MC_CHP_IO_CNTL_C1__MEM_CNTL_ENIMP_C_MASK           0x80000000L
#define MC_CHP_IO_CNTL_C1__MEM_CNTL_ENIMP_C                0x80000000L

// MC_CHP_IO_CNTL_D0
#define MC_CHP_IO_CNTL_D0__MEM_N_CKD_MASK                  0x0000000fL
#define MC_CHP_IO_CNTL_D0__MEM_N_AD_MASK                   0x000000f0L
#define MC_CHP_IO_CNTL_D0__MEM_N_DQMD_MASK                 0x00000f00L
#define MC_CHP_IO_CNTL_D0__MEM_N_DQSD_MASK                 0x0000f000L
#define MC_CHP_IO_CNTL_D0__MEM_P_CKD_MASK                  0x000f0000L
#define MC_CHP_IO_CNTL_D0__MEM_P_AD_MASK                   0x00f00000L
#define MC_CHP_IO_CNTL_D0__MEM_P_DQMD_MASK                 0x0f000000L
#define MC_CHP_IO_CNTL_D0__MEM_P_DQSD_MASK                 0xf0000000L

// MC_CHP_IO_CNTL_D1
#define MC_CHP_IO_CNTL_D1__MEM_SLEWN_CKD_MASK              0x00000001L
#define MC_CHP_IO_CNTL_D1__MEM_SLEWN_CKD                   0x00000001L
#define MC_CHP_IO_CNTL_D1__MEM_SLEWN_AD_MASK               0x00000002L
#define MC_CHP_IO_CNTL_D1__MEM_SLEWN_AD                    0x00000002L
#define MC_CHP_IO_CNTL_D1__MEM_SLEWN_DQMD_MASK             0x00000004L
#define MC_CHP_IO_CNTL_D1__MEM_SLEWN_DQMD                  0x00000004L
#define MC_CHP_IO_CNTL_D1__MEM_SLEWN_DQSD_MASK             0x00000008L
#define MC_CHP_IO_CNTL_D1__MEM_SLEWN_DQSD                  0x00000008L
#define MC_CHP_IO_CNTL_D1__MEM_SLEWP_CKD_MASK              0x00000010L
#define MC_CHP_IO_CNTL_D1__MEM_SLEWP_CKD                   0x00000010L
#define MC_CHP_IO_CNTL_D1__MEM_SLEWP_AD_MASK               0x00000020L
#define MC_CHP_IO_CNTL_D1__MEM_SLEWP_AD                    0x00000020L
#define MC_CHP_IO_CNTL_D1__MEM_SLEWP_DQMD_MASK             0x00000040L
#define MC_CHP_IO_CNTL_D1__MEM_SLEWP_DQMD                  0x00000040L
#define MC_CHP_IO_CNTL_D1__MEM_SLEWP_DQSD_MASK             0x00000080L
#define MC_CHP_IO_CNTL_D1__MEM_SLEWP_DQSD                  0x00000080L
#define MC_CHP_IO_CNTL_D1__MEM_PREAMP_AD_MASK              0x00000100L
#define MC_CHP_IO_CNTL_D1__MEM_PREAMP_AD                   0x00000100L
#define MC_CHP_IO_CNTL_D1__MEM_PREAMP_DQMD_MASK            0x00000200L
#define MC_CHP_IO_CNTL_D1__MEM_PREAMP_DQMD                 0x00000200L
#define MC_CHP_IO_CNTL_D1__MEM_PREAMP_DQSD_MASK            0x00000400L
#define MC_CHP_IO_CNTL_D1__MEM_PREAMP_DQSD                 0x00000400L
#define MC_CHP_IO_CNTL_D1__MEM_IO_QS_PDD_MASK              0x00000800L
#define MC_CHP_IO_CNTL_D1__MEM_IO_QS_PDD                   0x00000800L
#define MC_CHP_IO_CNTL_D1__MEM_IO_MODED_MASK               0x00003000L
#define MC_CHP_IO_CNTL_D1__MEM_REC_CKD_MASK                0x0000c000L
#define MC_CHP_IO_CNTL_D1__MEM_REC_AD_MASK                 0x00030000L
#define MC_CHP_IO_CNTL_D1__MEM_REC_DQMD_MASK               0x000c0000L
#define MC_CHP_IO_CNTL_D1__MEM_REC_DQSD_MASK               0x00300000L
#define MC_CHP_IO_CNTL_D1__MEM_SYNC_PHASED_MASK            0x00400000L
#define MC_CHP_IO_CNTL_D1__MEM_SYNC_PHASED                 0x00400000L
#define MC_CHP_IO_CNTL_D1__MEM_SYNC_CENTERD_MASK           0x00800000L
#define MC_CHP_IO_CNTL_D1__MEM_SYNC_CENTERD                0x00800000L
#define MC_CHP_IO_CNTL_D1__MEM_SYNC_END_MASK               0x03000000L
#define MC_CHP_IO_CNTL_D1__MEM_CLK_SELD_MASK               0x0c000000L
#define MC_CHP_IO_CNTL_D1__MEM_CLK_INVD_MASK               0x10000000L
#define MC_CHP_IO_CNTL_D1__MEM_CLK_INVD                    0x10000000L
#define MC_CHP_IO_CNTL_D1__MEM_DATA_ENIMP_D_MASK           0x40000000L
#define MC_CHP_IO_CNTL_D1__MEM_DATA_ENIMP_D                0x40000000L
#define MC_CHP_IO_CNTL_D1__MEM_CNTL_ENIMP_D_MASK           0x80000000L
#define MC_CHP_IO_CNTL_D1__MEM_CNTL_ENIMP_D                0x80000000L

// MC_IMP_CNTL_0_R3
#define MC_IMP_CNTL_0_R3__MEM_STEP_N_A_MASK                0x00000003L
#define MC_IMP_CNTL_0_R3__MEM_STEP_N_DQM_MASK              0x0000000cL
#define MC_IMP_CNTL_0_R3__MEM_STEP_N_CK_MASK               0x00000030L
#define MC_IMP_CNTL_0_R3__MEM_STEP_N_DQS_MASK              0x000000c0L
#define MC_IMP_CNTL_0_R3__MEM_STEP_P_A_MASK                0x00000300L
#define MC_IMP_CNTL_0_R3__MEM_STEP_P_DQM_MASK              0x00000c00L
#define MC_IMP_CNTL_0_R3__MEM_STEP_P_CK_MASK               0x00003000L
#define MC_IMP_CNTL_0_R3__MEM_STEP_P_DQS_MASK              0x0000c000L
#define MC_IMP_CNTL_0_R3__MEM_IMP_DEBUG_P_MASK             0x000f0000L
#define MC_IMP_CNTL_0_R3__MEM_IMP_DEBUG_N_MASK             0x00f00000L
#define MC_IMP_CNTL_0_R3__MEM_IMP_IDLE_CNT_MASK            0xff000000L

// MC_ELPIDA_CNTL
#define MC_ELPIDA_CNTL__MEM_INV_WD_MASK                    0x00000001L
#define MC_ELPIDA_CNTL__MEM_INV_WD                         0x00000001L
#define MC_ELPIDA_CNTL__MEM_INV_RD_MASK                    0x00000002L
#define MC_ELPIDA_CNTL__MEM_INV_RD                         0x00000002L
#define MC_ELPIDA_CNTL__MEM_R2R_ADDR_MASK                  0x00000004L
#define MC_ELPIDA_CNTL__MEM_R2R_ADDR                       0x00000004L
#define MC_ELPIDA_CNTL__MEM_W2R_BNKPAIR_MASK               0x00000008L
#define MC_ELPIDA_CNTL__MEM_W2R_BNKPAIR                    0x00000008L
#define MC_ELPIDA_CNTL__MEM_AUTOPRECHG_MASK                0x00000010L
#define MC_ELPIDA_CNTL__MEM_AUTOPRECHG                     0x00000010L
#define MC_ELPIDA_CNTL__MEM_DLL_MASK                       0x00000020L
#define MC_ELPIDA_CNTL__MEM_DLL                            0x00000020L
#define MC_ELPIDA_CNTL__MEM_REFRSHRATE_MASK                0x00000040L
#define MC_ELPIDA_CNTL__MEM_REFRSHRATE                     0x00000040L
#define MC_ELPIDA_CNTL__MEM_NEC_A_MASK                     0x00000300L
#define MC_ELPIDA_CNTL__MEM_NEC_B_MASK                     0x00000c00L
#define MC_ELPIDA_CNTL__MEM_NEC_C_MASK                     0x00003000L
#define MC_ELPIDA_CNTL__MEM_NEC_D_MASK                     0x0000c000L

// MC_CHP_IO_OE_CNTL_CD
#define MC_CHP_IO_OE_CNTL_CD__DQ_OE_POSITION_C_MASK        0x00000003L
#define MC_CHP_IO_OE_CNTL_CD__QS_OE_POSITION_C_MASK        0x0000000cL
#define MC_CHP_IO_OE_CNTL_CD__DQ_OE_EXTEND_C_MASK          0x00000010L
#define MC_CHP_IO_OE_CNTL_CD__DQ_OE_EXTEND_C               0x00000010L
#define MC_CHP_IO_OE_CNTL_CD__QS_OE_EXTEND_C_MASK          0x00000020L
#define MC_CHP_IO_OE_CNTL_CD__QS_OE_EXTEND_C               0x00000020L
#define MC_CHP_IO_OE_CNTL_CD__DQ_OE_ADVANCE_C_MASK         0x00000040L
#define MC_CHP_IO_OE_CNTL_CD__DQ_OE_ADVANCE_C              0x00000040L
#define MC_CHP_IO_OE_CNTL_CD__QS_OE_ADVANCE_C_MASK         0x00000080L
#define MC_CHP_IO_OE_CNTL_CD__QS_OE_ADVANCE_C              0x00000080L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_C0_MASK      0x00000100L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_C0           0x00000100L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_C1_MASK      0x00000200L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_C1           0x00000200L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_C2_MASK      0x00000400L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_C2           0x00000400L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_C3_MASK      0x00000800L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_C3           0x00000800L
#define MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_CMD_C_MASK      0x00001000L
#define MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_CMD_C           0x00001000L
#define MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_DATA_C_MASK     0x00002000L
#define MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_DATA_C          0x00002000L
#define MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_STR_C_MASK      0x00004000L
#define MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_STR_C           0x00004000L
#define MC_CHP_IO_OE_CNTL_CD__DQ_OE_POSITION_D_MASK        0x00030000L
#define MC_CHP_IO_OE_CNTL_CD__QS_OE_POSITION_D_MASK        0x000c0000L
#define MC_CHP_IO_OE_CNTL_CD__DQ_OE_EXTEND_D_MASK          0x00100000L
#define MC_CHP_IO_OE_CNTL_CD__DQ_OE_EXTEND_D               0x00100000L
#define MC_CHP_IO_OE_CNTL_CD__QS_OE_EXTEND_D_MASK          0x00200000L
#define MC_CHP_IO_OE_CNTL_CD__QS_OE_EXTEND_D               0x00200000L
#define MC_CHP_IO_OE_CNTL_CD__DQ_OE_ADVANCE_D_MASK         0x00400000L
#define MC_CHP_IO_OE_CNTL_CD__DQ_OE_ADVANCE_D              0x00400000L
#define MC_CHP_IO_OE_CNTL_CD__QS_OE_ADVANCE_D_MASK         0x00800000L
#define MC_CHP_IO_OE_CNTL_CD__QS_OE_ADVANCE_D              0x00800000L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_D0_MASK      0x01000000L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_D0           0x01000000L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_D1_MASK      0x02000000L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_D1           0x02000000L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_D2_MASK      0x04000000L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_D2           0x04000000L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_D3_MASK      0x08000000L
#define MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_D3           0x08000000L
#define MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_CMD_D_MASK      0x10000000L
#define MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_CMD_D           0x10000000L
#define MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_DATA_D_MASK     0x20000000L
#define MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_DATA_D          0x20000000L
#define MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_STR_D_MASK      0x40000000L
#define MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_STR_D           0x40000000L

// MC_READ_CNTL_CD
#define MC_READ_CNTL_CD__MEM_RBS_POSITION_C_MASK           0x00000007L
#define MC_READ_CNTL_CD__MEM_STR_SEL_C_MASK                0x00000008L
#define MC_READ_CNTL_CD__MEM_STR_SEL_C                     0x00000008L
#define MC_READ_CNTL_CD__MEM_ERST_POSITION_C_MASK          0x00000070L
#define MC_READ_CNTL_CD__MEM_ERST_EXTEND_C_MASK            0x00000080L
#define MC_READ_CNTL_CD__MEM_ERST_EXTEND_C                 0x00000080L
#define MC_READ_CNTL_CD__MEM_QSREC_POSITION_C_MASK         0x00000700L
#define MC_READ_CNTL_CD__MEM_QSREC_EXTEND_C_MASK           0x00000800L
#define MC_READ_CNTL_CD__MEM_QSREC_EXTEND_C                0x00000800L
#define MC_READ_CNTL_CD__MEM_ERST_SYNC_C_MASK              0x00001000L
#define MC_READ_CNTL_CD__MEM_ERST_SYNC_C                   0x00001000L
#define MC_READ_CNTL_CD__MEM_QSREC_SYNC_C_MASK             0x00002000L
#define MC_READ_CNTL_CD__MEM_QSREC_SYNC_C                  0x00002000L
#define MC_READ_CNTL_CD__MEM_RBS_POSITION_D_MASK           0x00070000L
#define MC_READ_CNTL_CD__MEM_STR_SEL_D_MASK                0x00080000L
#define MC_READ_CNTL_CD__MEM_STR_SEL_D                     0x00080000L
#define MC_READ_CNTL_CD__MEM_ERST_POSITION_D_MASK          0x00700000L
#define MC_READ_CNTL_CD__MEM_ERST_EXTEND_D_MASK            0x00800000L
#define MC_READ_CNTL_CD__MEM_ERST_EXTEND_D                 0x00800000L
#define MC_READ_CNTL_CD__MEM_QSREC_POSITION_D_MASK         0x07000000L
#define MC_READ_CNTL_CD__MEM_QSREC_EXTEND_D_MASK           0x08000000L
#define MC_READ_CNTL_CD__MEM_QSREC_EXTEND_D                0x08000000L
#define MC_READ_CNTL_CD__MEM_ERST_SYNC_D_MASK              0x10000000L
#define MC_READ_CNTL_CD__MEM_ERST_SYNC_D                   0x10000000L
#define MC_READ_CNTL_CD__MEM_QSREC_SYNC_D_MASK             0x20000000L
#define MC_READ_CNTL_CD__MEM_QSREC_SYNC_D                  0x20000000L

// MC_INIT_WR_LAT_TIMER
#define MC_INIT_WR_LAT_TIMER__MC_G3D0W_INIT_LAT_MASK       0x0000000fL
#define MC_INIT_WR_LAT_TIMER__MC_G3D1W_INIT_LAT_MASK       0x000000f0L
#define MC_INIT_WR_LAT_TIMER__MC_G3D2W_INIT_LAT_MASK       0x00000f00L
#define MC_INIT_WR_LAT_TIMER__MC_G3D3W_INIT_LAT_MASK       0x0000f000L
#define MC_INIT_WR_LAT_TIMER__MC_IDCTW_INIT_LAT_MASK       0x000f0000L
#define MC_INIT_WR_LAT_TIMER__MC_HDPW_INIT_LAT_MASK        0x00f00000L
#define MC_INIT_WR_LAT_TIMER__MC_VIPW_INIT_LAT_MASK        0x0f000000L
#define MC_INIT_WR_LAT_TIMER__MC_CPW_INIT_LAT_MASK         0xf0000000L

// MC_DEBUG_CNTL
#define MC_DEBUG_CNTL__MC_DELAY_EMPTY_MASK                 0x00000001L
#define MC_DEBUG_CNTL__MC_DELAY_EMPTY                      0x00000001L
#define MC_DEBUG_CNTL__MC_DELAY_NOT_FULL_MASK              0x00000002L
#define MC_DEBUG_CNTL__MC_DELAY_NOT_FULL                   0x00000002L
#define MC_DEBUG_CNTL__MC_DEBUG_3_2_MASK                   0x0000000cL
#define MC_DEBUG_CNTL__MC_DEBUG_7_4_MASK                   0x000000f0L
#define MC_DEBUG_CNTL__MC_DEBUG_11_8_MASK                  0x00000f00L
#define MC_DEBUG_CNTL__MC_DEBUG_15_12_MASK                 0x0000f000L
#define MC_DEBUG_CNTL__MC_DEBUG_19_16_MASK                 0x000f0000L
#define MC_DEBUG_CNTL__MC_DEBUG_23_20_MASK                 0x00f00000L
#define MC_DEBUG_CNTL__MC_DEBUG_27_24_MASK                 0x0f000000L
#define MC_DEBUG_CNTL__MC_DEBUG_31_28_MASK                 0xf0000000L

// MC_BIST_CNTL_0
#define MC_BIST_CNTL_0__MC_BIST_CNTL_MASK                  0xffffffffL

// MC_BIST_CNTL_1
#define MC_BIST_CNTL_1__MC_BIST_COLLAR_WRITE_MASK          0xffffffffL

// MC_BIST_CNTL_2
#define MC_BIST_CNTL_2__MC_BIST_COLLAR_READ_MASK           0xffffffffL

// MC_BIST_CNTL_3
#define MC_BIST_CNTL_3__RUN_MC_BIST_MASK                   0x00000001L
#define MC_BIST_CNTL_3__RUN_MC_BIST                        0x00000001L
#define MC_BIST_CNTL_3__EBIST_MODE_MASK                    0x00000002L
#define MC_BIST_CNTL_3__EBIST_MODE                         0x00000002L
#define MC_BIST_CNTL_3__MC_TEMP_MASK                       0xffffff00L

// MC_BIST_CNTL_4
#define MC_BIST_CNTL_4__MC_PARALLEL_MISMATCH_L_MASK        0xffffffffL

// MC_BIST_CNTL_5
#define MC_BIST_CNTL_5__MC_PARALLEL_MISMATCH_H_MASK        0xffffffffL

// MC_DLL_CNTL
#define MC_DLL_CNTL__MC_DLL_RANGE_A0_MASK                  0x00000007L
#define MC_DLL_CNTL__MC_DLL_RANGE_A1_MASK                  0x00000038L
#define MC_DLL_CNTL__MC_DLL_RANGE_B0_MASK                  0x000001c0L
#define MC_DLL_CNTL__MC_DLL_RANGE_B1_MASK                  0x00000e00L
#define MC_DLL_CNTL__MC_DLL_RANGE_C0_MASK                  0x00007000L
#define MC_DLL_CNTL__MC_DLL_RANGE_C1_MASK                  0x00038000L
#define MC_DLL_CNTL__MC_DLL_RANGE_D0_MASK                  0x001c0000L
#define MC_DLL_CNTL__MC_DLL_RANGE_D1_MASK                  0x00e00000L
#define MC_DLL_CNTL__MC_DLL_TSTOUT_SEL_MASK                0x1f000000L
#define MC_DLL_CNTL__MC_DLL_TSTOUT_EN_MASK                 0x20000000L
#define MC_DLL_CNTL__MC_DLL_TSTOUT_EN                      0x20000000L

// MC_FB_LOCATION
#define MC_FB_LOCATION__MC_FB_START_MASK                   0x0000ffffL
#define MC_FB_LOCATION__MC_FB_TOP_MASK                     0xffff0000L

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
#define WAIT_UNTIL__WAIT_AGP_FLUSH_MASK                    0x00002000L
#define WAIT_UNTIL__WAIT_AGP_FLUSH                         0x00002000L
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
#define WAIT_UNTIL__WAIT_IDCT_SEMAPHORE_MASK               0x08000000L
#define WAIT_UNTIL__WAIT_IDCT_SEMAPHORE                    0x08000000L
#define WAIT_UNTIL__WAIT_VAP_IDLE_MASK                     0x10000000L
#define WAIT_UNTIL__WAIT_VAP_IDLE                          0x10000000L
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
#define RBBM_STATUS__GA_BUSY_MASK                          0x04000000L
#define RBBM_STATUS__GA_BUSY                               0x04000000L
#define RBBM_STATUS__CBA2D_BUSY_MASK                       0x08000000L
#define RBBM_STATUS__CBA2D_BUSY                            0x08000000L
#define RBBM_STATUS__GUI_ACTIVE_MASK                       0x80000000L
#define RBBM_STATUS__GUI_ACTIVE                            0x80000000L

// RBBM_CNTL
#define RBBM_CNTL__RB_SETTLE_MASK                          0x0000000fL
#define RBBM_CNTL__ABORTCLKS_HI_MASK                       0x00000070L
#define RBBM_CNTL__ABORTCLKS_CP_MASK                       0x00000700L
#define RBBM_CNTL__ABORTCLKS_CFIFO_MASK                    0x00007000L
#define RBBM_CNTL__CPQ_DATA_SWAP_MASK                      0x00020000L
#define RBBM_CNTL__CPQ_DATA_SWAP                           0x00020000L
#define RBBM_CNTL__NO_ABORT_VAP_MASK                       0x00080000L
#define RBBM_CNTL__NO_ABORT_VAP                            0x00080000L
#define RBBM_CNTL__NO_ABORT_GA_MASK                        0x00100000L
#define RBBM_CNTL__NO_ABORT_GA                             0x00100000L
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
#define RBBM_SOFT_RESET__SOFT_RESET_GA_MASK                0x00002000L
#define RBBM_SOFT_RESET__SOFT_RESET_GA                     0x00002000L
#define RBBM_SOFT_RESET__SOFT_RESET_IDCT_MASK              0x00004000L
#define RBBM_SOFT_RESET__SOFT_RESET_IDCT                   0x00004000L

// NQWAIT_UNTIL
#define NQWAIT_UNTIL__WAIT_GUI_IDLE_MASK                   0x00000001L
#define NQWAIT_UNTIL__WAIT_GUI_IDLE                        0x00000001L

// RBBM_DEBUG
#define RBBM_DEBUG__RBBM_DEBUG_R2_MASK                     0xffffffffL

// RBBM_CMDFIFO_ADDR
#define RBBM_CMDFIFO_ADDR__CMDFIFO_ADDR_R3_MASK            0x000001ffL

// RBBM_CMDFIFO_DATA
#define RBBM_CMDFIFO_DATA__CMDFIFO_DATA_MASK               0xffffffffL

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
#define GEN_INT_CNTL__DMA_VIPH0_INT_EN_MASK                0x00001000L
#define GEN_INT_CNTL__DMA_VIPH0_INT_EN                     0x00001000L
#define GEN_INT_CNTL__DMA_VIPH1_INT_EN_MASK                0x00002000L
#define GEN_INT_CNTL__DMA_VIPH1_INT_EN                     0x00002000L
#define GEN_INT_CNTL__DMA_VIPH2_INT_EN_MASK                0x00004000L
#define GEN_INT_CNTL__DMA_VIPH2_INT_EN                     0x00004000L
#define GEN_INT_CNTL__DMA_VIPH3_INT_EN_MASK                0x00008000L
#define GEN_INT_CNTL__DMA_VIPH3_INT_EN                     0x00008000L
#define GEN_INT_CNTL__TIMER_INT_MASK_MASK                  0x00010000L
#define GEN_INT_CNTL__TIMER_INT_MASK                       0x00010000L
#define GEN_INT_CNTL__I2C_INT_EN_MASK                      0x00020000L
#define GEN_INT_CNTL__I2C_INT_EN                           0x00020000L
#define GEN_INT_CNTL__GUI_IDLE_MASK_MASK                   0x00080000L
#define GEN_INT_CNTL__GUI_IDLE_MASK                        0x00080000L
#define GEN_INT_CNTL__VIPH_INT_EN_MASK                     0x01000000L
#define GEN_INT_CNTL__VIPH_INT_EN                          0x01000000L
#define GEN_INT_CNTL__SW_INT_EN_MASK                       0x02000000L
#define GEN_INT_CNTL__SW_INT_EN                            0x02000000L
#define GEN_INT_CNTL__IDCT_INT_EN_MASK                     0x08000000L
#define GEN_INT_CNTL__IDCT_INT_EN                          0x08000000L
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
#define GEN_INT_STATUS__DMA_VIPH0_INT_MASK                 0x00001000L
#define GEN_INT_STATUS__DMA_VIPH0_INT                      0x00001000L
#define GEN_INT_STATUS__DMA_VIPH0_INT_AK_MASK              0x00001000L
#define GEN_INT_STATUS__DMA_VIPH0_INT_AK                   0x00001000L
#define GEN_INT_STATUS__DMA_VIPH1_INT_MASK                 0x00002000L
#define GEN_INT_STATUS__DMA_VIPH1_INT                      0x00002000L
#define GEN_INT_STATUS__DMA_VIPH1_INT_AK_MASK              0x00002000L
#define GEN_INT_STATUS__DMA_VIPH1_INT_AK                   0x00002000L
#define GEN_INT_STATUS__DMA_VIPH2_INT_MASK                 0x00004000L
#define GEN_INT_STATUS__DMA_VIPH2_INT                      0x00004000L
#define GEN_INT_STATUS__DMA_VIPH2_INT_AK_MASK              0x00004000L
#define GEN_INT_STATUS__DMA_VIPH2_INT_AK                   0x00004000L
#define GEN_INT_STATUS__DMA_VIPH3_INT_MASK                 0x00008000L
#define GEN_INT_STATUS__DMA_VIPH3_INT                      0x00008000L
#define GEN_INT_STATUS__DMA_VIPH3_INT_AK_MASK              0x00008000L
#define GEN_INT_STATUS__DMA_VIPH3_INT_AK                   0x00008000L
#define GEN_INT_STATUS__TIMER_INT_STAT_MASK                0x00010000L
#define GEN_INT_STATUS__TIMER_INT_STAT                     0x00010000L
#define GEN_INT_STATUS__TIMER_INT_STAT_AK_MASK             0x00010000L
#define GEN_INT_STATUS__TIMER_INT_STAT_AK                  0x00010000L
#define GEN_INT_STATUS__I2C_INT_MASK                       0x00020000L
#define GEN_INT_STATUS__I2C_INT                            0x00020000L
#define GEN_INT_STATUS__I2C_INT_AK_MASK                    0x00020000L
#define GEN_INT_STATUS__I2C_INT_AK                         0x00020000L
#define GEN_INT_STATUS__GUI_IDLE_STAT_MASK                 0x00080000L
#define GEN_INT_STATUS__GUI_IDLE_STAT                      0x00080000L
#define GEN_INT_STATUS__GUI_IDLE_STAT_AK_MASK              0x00080000L
#define GEN_INT_STATUS__GUI_IDLE_STAT_AK                   0x00080000L
#define GEN_INT_STATUS__VIPH_INT_MASK                      0x01000000L
#define GEN_INT_STATUS__VIPH_INT                           0x01000000L
#define GEN_INT_STATUS__SW_INT_MASK                        0x02000000L
#define GEN_INT_STATUS__SW_INT                             0x02000000L
#define GEN_INT_STATUS__SW_INT_AK_MASK                     0x02000000L
#define GEN_INT_STATUS__SW_INT_AK                          0x02000000L
#define GEN_INT_STATUS__SW_INT_SET_MASK                    0x04000000L
#define GEN_INT_STATUS__SW_INT_SET                         0x04000000L
#define GEN_INT_STATUS__IDCT_INT_STAT_MASK                 0x08000000L
#define GEN_INT_STATUS__IDCT_INT_STAT                      0x08000000L
#define GEN_INT_STATUS__IDCT_INT_STAT_AK_MASK              0x08000000L
#define GEN_INT_STATUS__IDCT_INT_STAT_AK                   0x08000000L
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
#define BUS_CNTL__BUS_PM4_READ_COMBINE_EN_MASK             0x00000010L
#define BUS_CNTL__BUS_PM4_READ_COMBINE_EN                  0x00000010L
#define BUS_CNTL__BUS_WRT_COMBINE_EN_MASK                  0x00000020L
#define BUS_CNTL__BUS_WRT_COMBINE_EN                       0x00000020L
#define BUS_CNTL__BUS_MASTER_DIS_MASK                      0x00000040L
#define BUS_CNTL__BUS_MASTER_DIS                           0x00000040L
#define BUS_CNTL__BIOS_ROM_WRT_EN_MASK                     0x00000080L
#define BUS_CNTL__BIOS_ROM_WRT_EN                          0x00000080L
#define BUS_CNTL__BM_DAC_CRIPPLE_MASK                      0x00000100L
#define BUS_CNTL__BM_DAC_CRIPPLE                           0x00000100L
#define BUS_CNTL__BUS_NON_PM4_READ_COMBINE_EN_MASK         0x00000200L
#define BUS_CNTL__BUS_NON_PM4_READ_COMBINE_EN              0x00000200L
#define BUS_CNTL__BUS_XFERD_DISCARD_EN_MASK                0x00000400L
#define BUS_CNTL__BUS_XFERD_DISCARD_EN                     0x00000400L
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
#define BUS_CNTL1__BUS_CNTL1_BIT6_MASK                     0x00000040L
#define BUS_CNTL1__BUS_CNTL1_BIT6                          0x00000040L
#define BUS_CNTL1__AGPCLK_VALID_R3_MASK                    0x00000080L
#define BUS_CNTL1__AGPCLK_VALID_R3                         0x00000080L
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
#define BUS_CNTL1__MOBILE_PLATFORM_SEL_R3_MASK             0x0000c000L
#define BUS_CNTL1__BUS2_RD_PANIC_VAL_MASK                  0x000f0000L
#define BUS_CNTL1__BUS2_WRT_PANIC_VAL_MASK                 0x00f00000L
#define BUS_CNTL1__BUS2_REQ_DELAY_MASK                     0x0f000000L
#define BUS_CNTL1__BUS2_EARLY_REQ_DROP_MASK                0x10000000L
#define BUS_CNTL1__BUS2_EARLY_REQ_DROP                     0x10000000L
#define BUS_CNTL1__SEND_SBA_LATENCY_R3_MASK                0xe0000000L

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

// PAD_AGPINPUT_DELAY
#define PAD_AGPINPUT_DELAY__PAD_AGPINPUT_DELAY_MASK        0xffffffffL

// PAD_CTLR_STRENGTH
#define PAD_CTLR_STRENGTH__PAD_N_STRENGTH_READ_BACK_R3_MASK   0x0000001fL
#define PAD_CTLR_STRENGTH__PAD_P_STRENGTH_READ_BACK_R3_MASK   0x00001f00L
#define PAD_CTLR_STRENGTH__PAD_N_MANUAL_STRENGTH_R3_MASK   0x001f0000L
#define PAD_CTLR_STRENGTH__PAD_P_MANUAL_STRENGTH_R3_MASK   0x1f000000L
#define PAD_CTLR_STRENGTH__PAD_MANUAL_OVERRIDE_R3_MASK     0x80000000L
#define PAD_CTLR_STRENGTH__PAD_MANUAL_OVERRIDE_R3          0x80000000L

// PAD_CTLR_MISC
#define PAD_CTLR_MISC__DYNAMIC_IMP_EN_MASK                 0x00000001L
#define PAD_CTLR_MISC__DYNAMIC_IMP_EN                      0x00000001L
#define PAD_CTLR_MISC__DISABLE_WPTR_RST_MASK               0x00000002L
#define PAD_CTLR_MISC__DISABLE_WPTR_RST                    0x00000002L
#define PAD_CTLR_MISC__PAD_VREF_INT_EN_MASK                0x0000001cL
#define PAD_CTLR_MISC__AUTO_AGP_RSYNC_EN_MASK              0x00000020L
#define PAD_CTLR_MISC__AUTO_AGP_RSYNC_EN                   0x00000020L
#define PAD_CTLR_MISC__AGP_RSYNC_AD_DURING_WR_IDLE_EN_MASK 0x00000040L
#define PAD_CTLR_MISC__AGP_RSYNC_AD_DURING_WR_IDLE_EN      0x00000040L
#define PAD_CTLR_MISC__MANUAL_AGP_RSYNC_MASK               0x00000080L
#define PAD_CTLR_MISC__MANUAL_AGP_RSYNC                    0x00000080L
#define PAD_CTLR_MISC__PAD_HI_IO_PREAMPH_MASK              0x00000100L
#define PAD_CTLR_MISC__PAD_HI_IO_PREAMPH                   0x00000100L
#define PAD_CTLR_MISC__PAD_HI_IO_PREAMPH_STB_MASK          0x00000200L
#define PAD_CTLR_MISC__PAD_HI_IO_PREAMPH_STB               0x00000200L
#define PAD_CTLR_MISC__PAD_AGP30_SIG_SBA_UPDATE_CNTL_MASK  0x00002000L
#define PAD_CTLR_MISC__PAD_AGP30_SIG_SBA_UPDATE_CNTL       0x00002000L
#define PAD_CTLR_MISC__PAD_AGP30_SIG_SBA_CAL_DIS_MASK      0x00004000L
#define PAD_CTLR_MISC__PAD_AGP30_SIG_SBA_CAL_DIS           0x00004000L
#define PAD_CTLR_MISC__PAD_AGP30_SIG_TRDY_DIS_MASK         0x00008000L
#define PAD_CTLR_MISC__PAD_AGP30_SIG_TRDY_DIS              0x00008000L
#define PAD_CTLR_MISC__PAD_AGP30SIGNALING_CAL_DIS_MASK     0x00010000L
#define PAD_CTLR_MISC__PAD_AGP30SIGNALING_CAL_DIS          0x00010000L
#define PAD_CTLR_MISC__PAD_TEST_OUT_MASK                   0x00020000L
#define PAD_CTLR_MISC__PAD_TEST_OUT                        0x00020000L
#define PAD_CTLR_MISC__PAD_DUMMY_OUT_MASK                  0x00040000L
#define PAD_CTLR_MISC__PAD_DUMMY_OUT                       0x00040000L
#define PAD_CTLR_MISC__PAD_HI_IO_DFR_MASK                  0x00080000L
#define PAD_CTLR_MISC__PAD_HI_IO_DFR                       0x00080000L
#define PAD_CTLR_MISC__PAD_HI_IO_SCHMEN_MASK               0x00100000L
#define PAD_CTLR_MISC__PAD_HI_IO_SCHMEN                    0x00100000L
#define PAD_CTLR_MISC__PAD_HI_IO_DREN_MASK                 0x00200000L
#define PAD_CTLR_MISC__PAD_HI_IO_DREN                      0x00200000L
#define PAD_CTLR_MISC__PAD_HI_IO_VDIFF_MASK                0x00800000L
#define PAD_CTLR_MISC__PAD_HI_IO_VDIFF                     0x00800000L
#define PAD_CTLR_MISC__PAD_HI_IO_DFR_OVERRIDE_MASK         0x01000000L
#define PAD_CTLR_MISC__PAD_HI_IO_DFR_OVERRIDE              0x01000000L
#define PAD_CTLR_MISC__PAD_HI_IO_SCHMEN_OVERRIDE_MASK      0x02000000L
#define PAD_CTLR_MISC__PAD_HI_IO_SCHMEN_OVERRIDE           0x02000000L
#define PAD_CTLR_MISC__PAD_HI_IO_DREN_OVERRIDE_MASK        0x04000000L
#define PAD_CTLR_MISC__PAD_HI_IO_DREN_OVERRIDE             0x04000000L
#define PAD_CTLR_MISC__PAD_HI_IO_VDIFF_OVERRIDE_MASK       0x10000000L
#define PAD_CTLR_MISC__PAD_HI_IO_VDIFF_OVERRIDE            0x10000000L
#define PAD_CTLR_MISC__PAD_HI_IO_SLEWN_MASK                0x20000000L
#define PAD_CTLR_MISC__PAD_HI_IO_SLEWN                     0x20000000L
#define PAD_CTLR_MISC__PAD_HI_IO_SLEWP_MASK                0x40000000L
#define PAD_CTLR_MISC__PAD_HI_IO_SLEWP                     0x40000000L
#define PAD_CTLR_MISC__PAD_HI_IO_SLEW_OVERRIDE_MASK        0x80000000L
#define PAD_CTLR_MISC__PAD_HI_IO_SLEW_OVERRIDE             0x80000000L

// PAD_CTLR_UPDATE
#define PAD_CTLR_UPDATE__PAD_UPDATE_RATE_MASK              0x0000001fL
#define PAD_CTLR_UPDATE__PAD_SAMPLE_DELAY_MASK             0x00001f00L
#define PAD_CTLR_UPDATE__PAD_INC_THRESHOLD_MASK            0x001f0000L
#define PAD_CTLR_UPDATE__PAD_DEC_THRESHOLD_MASK            0x1f000000L

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
#define AGP_CNTL__PCI_DBI_DISABLE_MASK                     0x00100000L
#define AGP_CNTL__PCI_DBI_DISABLE                          0x00100000L
#define AGP_CNTL__AGP_DBI_DISABLE_MASK                     0x00200000L
#define AGP_CNTL__AGP_DBI_DISABLE                          0x00200000L
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
#define AGP_CNTL__CRIPPLE_AGP8X_MASK                       0x40000000L
#define AGP_CNTL__CRIPPLE_AGP8X                            0x40000000L
#define AGP_CNTL__AGP_MISC_R3_MASK                         0x80000000L
#define AGP_CNTL__AGP_MISC_R3                              0x80000000L

// BM_STATUS
#define BM_STATUS__BUS_MASTER_STATUS_MASK                  0xffffffffL

// PAD_CTLR_STRENGTH2
#define PAD_CTLR_STRENGTH2__PAD_SBA_N_STRENGTH_READ_BACK_MASK 0x0000001fL
#define PAD_CTLR_STRENGTH2__PAD_SBA_P_STRENGTH_READ_BACK_MASK 0x00001f00L

// PAMAC0_DLY_CNTL
#define PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_DATA_U_MASK         0x0000000fL
#define PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_DATA_L_MASK         0x000000f0L
#define PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_STB_MASK            0x00000f00L
#define PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_DBI_MASK            0x0000f000L
#define PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_DATA_U_MASK        0x00030000L
#define PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_DATA_L_MASK        0x000c0000L
#define PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_STB_MASK           0x00300000L
#define PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_DBI_MASK           0x00c00000L
#define PAMAC0_DLY_CNTL__PAMAC0_CLK_INS_DLY_MASK           0x01000000L
#define PAMAC0_DLY_CNTL__PAMAC0_CLK_INS_DLY                0x01000000L
#define PAMAC0_DLY_CNTL__PAMAC0_SYNC_DLY_MASK              0x0e000000L

// PAMAC1_DLY_CNTL
#define PAMAC1_DLY_CNTL__PAMAC1_DLY_IN_DATA_U_MASK         0x0000000fL
#define PAMAC1_DLY_CNTL__PAMAC1_DLY_IN_DATA_L_MASK         0x000000f0L
#define PAMAC1_DLY_CNTL__PAMAC1_DLY_IN_STB_MASK            0x00000f00L
#define PAMAC1_DLY_CNTL__PAMAC1_DLY_OUT_DATA_U_MASK        0x00030000L
#define PAMAC1_DLY_CNTL__PAMAC1_DLY_OUT_DATA_L_MASK        0x000c0000L
#define PAMAC1_DLY_CNTL__PAMAC1_DLY_OUT_STB_MASK           0x00300000L
#define PAMAC1_DLY_CNTL__PAMAC1_CLK_INS_DLY_MASK           0x01000000L
#define PAMAC1_DLY_CNTL__PAMAC1_CLK_INS_DLY                0x01000000L
#define PAMAC1_DLY_CNTL__PAMAC1_SYNC_DLY_MASK              0x0e000000L

// PAMAC2_DLY_CNTL
#define PAMAC2_DLY_CNTL__PAMAC2_DLY_IN_DATA_U_MASK         0x0000000fL
#define PAMAC2_DLY_CNTL__PAMAC2_DLY_IN_DATA_L_MASK         0x000000f0L
#define PAMAC2_DLY_CNTL__PAMAC2_DLY_IN_STB_MASK            0x00000f00L
#define PAMAC2_DLY_CNTL__PAMAC2_DLY_OUT_DATA_U_MASK        0x00030000L
#define PAMAC2_DLY_CNTL__PAMAC2_DLY_OUT_DATA_L_MASK        0x000c0000L
#define PAMAC2_DLY_CNTL__PAMAC2_DLY_OUT_STB_MASK           0x00300000L
#define PAMAC2_DLY_CNTL__PAMAC2_CLK_INS_DLY_MASK           0x01000000L
#define PAMAC2_DLY_CNTL__PAMAC2_CLK_INS_DLY                0x01000000L
#define PAMAC2_DLY_CNTL__PAMAC2_SYNC_DLY_MASK              0x0e000000L

// AIC_CTRL
#define AIC_CTRL__TRANSLATE_EN_MASK                        0x00000001L
#define AIC_CTRL__TRANSLATE_EN                             0x00000001L
#define AIC_CTRL__DIS_OUT_OF_PCI_GART_ACCESS_MASK          0x00000002L
#define AIC_CTRL__DIS_OUT_OF_PCI_GART_ACCESS               0x00000002L
#define AIC_CTRL__HW_02_DEBUG_MASK                         0x00000004L
#define AIC_CTRL__HW_02_DEBUG                              0x00000004L
#define AIC_CTRL__HW_03_DEBUG_MASK                         0x00000008L
#define AIC_CTRL__HW_03_DEBUG                              0x00000008L
#define AIC_CTRL__TEST_RBF_DIV_VAL_MASK                    0x00000070L
#define AIC_CTRL__TEST_RBF_EN_MASK                         0x00000080L
#define AIC_CTRL__TEST_RBF_EN                              0x00000080L
#define AIC_CTRL__HW_08_DEBUG_MASK                         0x00000100L
#define AIC_CTRL__HW_08_DEBUG                              0x00000100L
#define AIC_CTRL__HW_09_DEBUG_MASK                         0x00000200L
#define AIC_CTRL__HW_09_DEBUG                              0x00000200L
#define AIC_CTRL__HW_10_DEBUG_R3_MASK                      0x00000400L
#define AIC_CTRL__HW_10_DEBUG_R3                           0x00000400L
#define AIC_CTRL__HW_11_DEBUG_R3_MASK                      0x00000800L
#define AIC_CTRL__HW_11_DEBUG_R3                           0x00000800L
#define AIC_CTRL__HW_12_DEBUG_R3_MASK                      0x00001000L
#define AIC_CTRL__HW_12_DEBUG_R3                           0x00001000L
#define AIC_CTRL__HW_13_DEBUG_R3_MASK                      0x00002000L
#define AIC_CTRL__HW_13_DEBUG_R3                           0x00002000L
#define AIC_CTRL__HW_14_DEBUG_R3_MASK                      0x00004000L
#define AIC_CTRL__HW_14_DEBUG_R3                           0x00004000L
#define AIC_CTRL__HW_15_DEBUG_R3_MASK                      0x00008000L
#define AIC_CTRL__HW_15_DEBUG_R3                           0x00008000L
#define AIC_CTRL__HW_16_DEBUG_R3_MASK                      0x00010000L
#define AIC_CTRL__HW_16_DEBUG_R3                           0x00010000L
#define AIC_CTRL__HW_17_DEBUG_R3_MASK                      0x00020000L
#define AIC_CTRL__HW_17_DEBUG_R3                           0x00020000L
#define AIC_CTRL__HW_18_DEBUG_R3_MASK                      0x00040000L
#define AIC_CTRL__HW_18_DEBUG_R3                           0x00040000L
#define AIC_CTRL__HW_19_DEBUG_R3_MASK                      0x00080000L
#define AIC_CTRL__HW_19_DEBUG_R3                           0x00080000L
#define AIC_CTRL__HW_20_DEBUG_MASK                         0x00100000L
#define AIC_CTRL__HW_20_DEBUG                              0x00100000L
#define AIC_CTRL__HW_21_DEBUG_MASK                         0x00200000L
#define AIC_CTRL__HW_21_DEBUG                              0x00200000L
#define AIC_CTRL__HW_22_DEBUG_MASK                         0x00400000L
#define AIC_CTRL__HW_22_DEBUG                              0x00400000L
#define AIC_CTRL__HW_23_DEBUG_MASK                         0x00800000L
#define AIC_CTRL__HW_23_DEBUG                              0x00800000L
#define AIC_CTRL__HW_24_DEBUG_MASK                         0x01000000L
#define AIC_CTRL__HW_24_DEBUG                              0x01000000L
#define AIC_CTRL__HW_25_DEBUG_MASK                         0x02000000L
#define AIC_CTRL__HW_25_DEBUG                              0x02000000L
#define AIC_CTRL__HW_26_DEBUG_MASK                         0x04000000L
#define AIC_CTRL__HW_26_DEBUG                              0x04000000L
#define AIC_CTRL__HW_27_DEBUG_MASK                         0x08000000L
#define AIC_CTRL__HW_27_DEBUG                              0x08000000L
#define AIC_CTRL__HW_28_DEBUG_MASK                         0x10000000L
#define AIC_CTRL__HW_28_DEBUG                              0x10000000L
#define AIC_CTRL__HW_29_DEBUG_MASK                         0x20000000L
#define AIC_CTRL__HW_29_DEBUG                              0x20000000L
#define AIC_CTRL__HW_30_DEBUG_MASK                         0x40000000L
#define AIC_CTRL__HW_30_DEBUG                              0x40000000L
#define AIC_CTRL__HW_31_DEBUG_MASK                         0x80000000L
#define AIC_CTRL__HW_31_DEBUG                              0x80000000L

// AIC_STAT
#define AIC_STAT__AIC_TLB_VLD_MASK                         0x00000001L
#define AIC_STAT__AIC_TLB_VLD                              0x00000001L
#define AIC_STAT__AIC_STAT1_MASK                           0x00000002L
#define AIC_STAT__AIC_STAT1                                0x00000002L
#define AIC_STAT__AIC_STAT0_MASK                           0x00000004L
#define AIC_STAT__AIC_STAT0                                0x00000004L

// AIC_PT_BASE_LO
#define AIC_PT_BASE_LO__AIC_PT_BASE_LO_MASK                0xfffff000L

// AIC_PT_BASE_HI
#define AIC_PT_BASE_HI__AIC_PT_BASE_HI_MASK                0xffffffffL

// AIC_LO_ADDR
#define AIC_LO_ADDR__AIC_LO_ADDR_MASK                      0xfffff000L

// AIC_HI_ADDR
#define AIC_HI_ADDR__AIC_HI_ADDR_MASK                      0xfffff000L

// AIC_TLB_ADDR
#define AIC_TLB_ADDR__AIC_TLB_ADDR_MASK                    0xfffff000L

// AIC_TLB_DATA_LO
#define AIC_TLB_DATA_LO__AIC_TLB_DATA_LO_MASK              0xfffff000L

// AIC_TLB_DATA_HI
#define AIC_TLB_DATA_HI__AIC_TLB_DATA_HI_MASK              0xffffffffL

// AIC_RESYNC_CNTL
#define AIC_RESYNC_CNTL__DBL_RSYNC_AGP_RDFIFO_RPTR_MASK    0x00000001L
#define AIC_RESYNC_CNTL__DBL_RSYNC_AGP_RDFIFO_RPTR         0x00000001L
#define AIC_RESYNC_CNTL__DBL_RSYNC_PCI_RDFIFO_RPTR_MASK    0x00000002L
#define AIC_RESYNC_CNTL__DBL_RSYNC_PCI_RDFIFO_RPTR         0x00000002L
#define AIC_RESYNC_CNTL__DBL_RSYNC_AGP_RDFIFO_WPTR_MASK    0x00000004L
#define AIC_RESYNC_CNTL__DBL_RSYNC_AGP_RDFIFO_WPTR         0x00000004L
#define AIC_RESYNC_CNTL__DBL_RSYNC_PCI_RDFIFO_WPTR_MASK    0x00000008L
#define AIC_RESYNC_CNTL__DBL_RSYNC_PCI_RDFIFO_WPTR         0x00000008L
#define AIC_RESYNC_CNTL__DBL_RSYNC_AGP_RQFIFO_RPTR_MASK    0x00000010L
#define AIC_RESYNC_CNTL__DBL_RSYNC_AGP_RQFIFO_RPTR         0x00000010L
#define AIC_RESYNC_CNTL__DBL_RSYNC_PCI_RQFIFO_RPTR_MASK    0x00000020L
#define AIC_RESYNC_CNTL__DBL_RSYNC_PCI_RQFIFO_RPTR         0x00000020L
#define AIC_RESYNC_CNTL__DBL_RSYNC_AGP_RQFIFO_WPTR_MASK    0x00000040L
#define AIC_RESYNC_CNTL__DBL_RSYNC_AGP_RQFIFO_WPTR         0x00000040L
#define AIC_RESYNC_CNTL__DBL_RSYNC_PCI_RQFIFO_WPTR_MASK    0x00000080L
#define AIC_RESYNC_CNTL__DBL_RSYNC_PCI_RQFIFO_WPTR         0x00000080L
#define AIC_RESYNC_CNTL__DBL_RSYNC_AGP_WRFIFO_RPTR_MASK    0x00000100L
#define AIC_RESYNC_CNTL__DBL_RSYNC_AGP_WRFIFO_RPTR         0x00000100L
#define AIC_RESYNC_CNTL__DBL_RSYNC_PCI_WRFIFO_RPTR_MASK    0x00000200L
#define AIC_RESYNC_CNTL__DBL_RSYNC_PCI_WRFIFO_RPTR         0x00000200L
#define AIC_RESYNC_CNTL__DBL_RSYNC_AGP_WRFIFO_WPTR_MASK    0x00000400L
#define AIC_RESYNC_CNTL__DBL_RSYNC_AGP_WRFIFO_WPTR         0x00000400L
#define AIC_RESYNC_CNTL__DBL_RSYNC_PCI_WRFIFO_WPTR_MASK    0x00000800L
#define AIC_RESYNC_CNTL__DBL_RSYNC_PCI_WRFIFO_WPTR         0x00000800L

// AGP_FENCE_CNTL
#define AGP_FENCE_CNTL__FENCE_EN_MASK                      0x00000001L
#define AGP_FENCE_CNTL__FENCE_EN                           0x00000001L
#define AGP_FENCE_CNTL__ADDR_MASK                          0xfffffff8L

// AGP_FLUSH_CNTL
#define AGP_FLUSH_CNTL__FLUSH_EN_MASK                      0x00000001L
#define AGP_FLUSH_CNTL__FLUSH_EN                           0x00000001L
#define AGP_FLUSH_CNTL__FLUSH_ACK_MASK                     0x00000002L
#define AGP_FLUSH_CNTL__FLUSH_ACK                          0x00000002L
#define AGP_FLUSH_CNTL__ADDR_MASK                          0xfffffff8L

// AIC_PT_BASE
#define AIC_PT_BASE__AIC_PT_BASE_LO_MASK                   0xfffff000L

// AIC_TLB_DATA
#define AIC_TLB_DATA__AIC_TLB_DATA_LO_MASK                 0xfffff000L

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

// MEM_BASE_LO
#define MEM_BASE_LO__BLOCK_MEM_BIT_MASK                    0x00000001L
#define MEM_BASE_LO__BLOCK_MEM_BIT                         0x00000001L
#define MEM_BASE_LO__BLOCK_MEM_TYPE_MASK                   0x00000006L
#define MEM_BASE_LO__PFTCH_MEM_EN_MASK                     0x00000008L
#define MEM_BASE_LO__PFTCH_MEM_EN                          0x00000008L
#define MEM_BASE_LO__MEM_BASE_LO_MASK                      0xfe000000L

// MEM_BASE_HI
#define MEM_BASE_HI__MEM_BASE_HI_MASK                      0xffffffffL

// REG_BASE_LO
#define REG_BASE_LO__BLOCK_REG_BIT_MASK                    0x00000001L
#define REG_BASE_LO__BLOCK_REG_BIT                         0x00000001L
#define REG_BASE_LO__BLOCK_REG_TYPE_MASK                   0x00000006L
#define REG_BASE_LO__PFTCH_REG_EN_MASK                     0x00000008L
#define REG_BASE_LO__PFTCH_REG_EN                          0x00000008L
#define REG_BASE_LO__REG_BASE_LO_MASK                      0xffff0000L

// REG_BASE_HI
#define REG_BASE_HI__REG_BASE_HI_MASK                      0xffffffffL

// IO_BASE_WS
#define IO_BASE_WS__BLOCK_IO_BIT_MASK                      0x00000001L
#define IO_BASE_WS__BLOCK_IO_BIT                           0x00000001L
#define IO_BASE_WS__IO_BASE_MASK                           0xffffff00L

// MEM_BASE
#define MEM_BASE__BLOCK_MEM_BIT_MASK                       0x00000001L
#define MEM_BASE__BLOCK_MEM_BIT                            0x00000001L
#define MEM_BASE__BLOCK_MEM_TYPE_MASK                      0x00000006L
#define MEM_BASE__PFTCH_MEM_EN_MASK                        0x00000008L
#define MEM_BASE__PFTCH_MEM_EN                             0x00000008L
#define MEM_BASE__MEM_BASE_MASK                            0xfe000000L

// IO_BASE
#define IO_BASE__BLOCK_IO_BIT_R3_MASK                      0x00000001L
#define IO_BASE__BLOCK_IO_BIT_R3                           0x00000001L
#define IO_BASE__IO_BASE_MASK                              0xffffff00L

// REG_BASE
#define REG_BASE__BLOCK_REG_BIT_MASK                       0x00000001L
#define REG_BASE__BLOCK_REG_BIT                            0x00000001L
#define REG_BASE__BLOCK_REG_TYPE_MASK                      0x00000006L
#define REG_BASE__PFTCH_REG_EN_MASK                        0x00000008L
#define REG_BASE__PFTCH_REG_EN                             0x00000008L
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

// MSI_CAP_ID
#define MSI_CAP_ID__MSI_CAP_ID_MASK                        0x000000ffL

// MSI_NXT_CAP_PTR
#define MSI_NXT_CAP_PTR__MSI_NXT_CAP_PTR_MASK              0x000000ffL

// MSI_MSG_CNTL
#define MSI_MSG_CNTL__MSI_ENABLE_MASK                      0x00000001L
#define MSI_MSG_CNTL__MSI_ENABLE                           0x00000001L
#define MSI_MSG_CNTL__MSI_MULTMSG_CAP_MASK                 0x0000000eL
#define MSI_MSG_CNTL__MSI_MULTMSG_EN_MASK                  0x00000070L
#define MSI_MSG_CNTL__MSI_64BIT_MASK                       0x00000080L
#define MSI_MSG_CNTL__MSI_64BIT                            0x00000080L

// MSI_MSG_ADDR_LO
#define MSI_MSG_ADDR_LO__MSI_MSG_ADDR_LO_MASK              0xfffffffcL

// MSI_MSG_ADDR_HI
#define MSI_MSG_ADDR_HI__MSI_MSG_ADDR_HI_MASK              0xffffffffL

// MSI_MSG_DATA_64
#define MSI_MSG_DATA_64__MSI_DATA_MASK                     0x0000ffffL

// MSI_MSG_ADDR
#define MSI_MSG_ADDR__MSI_MSG_ADDR_MASK                    0xfffffffcL

// MSI_MSG_DATA
#define MSI_MSG_DATA__MSI_DATA_MASK                        0x0000ffffL

// F1_VENDOR_ID_R3
#define F1_VENDOR_ID_R3__F1_VENDOR_ID_MASK                 0x0000ffffL

// F1_DEVICE_ID_R3
#define F1_DEVICE_ID_R3__F1_DEVICE_ID_MASK                 0x0000ffffL

// F1_COMMAND_R3
#define F1_COMMAND_R3__F1_IO_ACCESS_EN_MASK                0x00000001L
#define F1_COMMAND_R3__F1_IO_ACCESS_EN                     0x00000001L
#define F1_COMMAND_R3__F1_MEM_ACCESS_EN_MASK               0x00000002L
#define F1_COMMAND_R3__F1_MEM_ACCESS_EN                    0x00000002L
#define F1_COMMAND_R3__F1_BUS_MASTER_EN_MASK               0x00000004L
#define F1_COMMAND_R3__F1_BUS_MASTER_EN                    0x00000004L
#define F1_COMMAND_R3__F1_AD_STEPPING_MASK                 0x00000080L
#define F1_COMMAND_R3__F1_AD_STEPPING                      0x00000080L
#define F1_COMMAND_R3__F1_FAST_B2B_EN_MASK                 0x00000200L
#define F1_COMMAND_R3__F1_FAST_B2B_EN                      0x00000200L

// F1_STATUS_R3
#define F1_STATUS_R3__F1_CAP_LIST_MASK                     0x00000010L
#define F1_STATUS_R3__F1_CAP_LIST                          0x00000010L
#define F1_STATUS_R3__F1_PCI_66_EN_MASK                    0x00000020L
#define F1_STATUS_R3__F1_PCI_66_EN                         0x00000020L
#define F1_STATUS_R3__F1_UDF_EN_MASK                       0x00000040L
#define F1_STATUS_R3__F1_UDF_EN                            0x00000040L
#define F1_STATUS_R3__F1_FAST_BACK_CAPABLE_MASK            0x00000080L
#define F1_STATUS_R3__F1_FAST_BACK_CAPABLE                 0x00000080L
#define F1_STATUS_R3__F1_DEVSEL_TIMING_MASK                0x00000600L
#define F1_STATUS_R3__F1_SIGNAL_TARGET_ABORT_MASK          0x00000800L
#define F1_STATUS_R3__F1_SIGNAL_TARGET_ABORT               0x00000800L
#define F1_STATUS_R3__F1_RECEIVED_TARGET_ABORT_MASK        0x00001000L
#define F1_STATUS_R3__F1_RECEIVED_TARGET_ABORT             0x00001000L
#define F1_STATUS_R3__F1_RECEIVED_MASTER_ABORT_MASK        0x00002000L
#define F1_STATUS_R3__F1_RECEIVED_MASTER_ABORT             0x00002000L
#define F1_STATUS_R3__F1_PARITY_ERROR_DETECTED_MASK        0x00008000L
#define F1_STATUS_R3__F1_PARITY_ERROR_DETECTED             0x00008000L

// F1_REVISION_ID_R3
#define F1_REVISION_ID_R3__F1_MINOR_REV_ID_MASK            0x0000000fL
#define F1_REVISION_ID_R3__F1_MAJOR_REV_ID_MASK            0x000000f0L

// F1_REGPROG_INF_R3
#define F1_REGPROG_INF_R3__F1_REG_LEVEL_PROG_INF_MASK      0x000000ffL

// F1_SUB_CLASS_R3
#define F1_SUB_CLASS_R3__F1_SUB_CLASS_INF_MASK             0x00000080L
#define F1_SUB_CLASS_R3__F1_SUB_CLASS_INF                  0x00000080L

// F1_BASE_CODE_R3
#define F1_BASE_CODE_R3__F1_BASE_CLASS_CODE_MASK           0x000000ffL

// F1_CACHE_LINE_R3
#define F1_CACHE_LINE_R3__F1_CACHE_LINE_SIZE_MASK          0x000000ffL

// F1_LATENCY_R3
#define F1_LATENCY_R3__F1_LATENCY_TIMER_MASK               0x000000ffL

// F1_HEADER_R3
#define F1_HEADER_R3__F1_HEADER_TYPE_MASK                  0x0000007fL
#define F1_HEADER_R3__F1_DEVICE_TYPE_MASK                  0x00000080L
#define F1_HEADER_R3__F1_DEVICE_TYPE                       0x00000080L

// F1_BIST_R3
#define F1_BIST_R3__F1_BIST_COMP_MASK                      0x0000000fL
#define F1_BIST_R3__F1_BIST_STRT_MASK                      0x00000040L
#define F1_BIST_R3__F1_BIST_STRT                           0x00000040L
#define F1_BIST_R3__F1_BIST_CAP_MASK                       0x00000080L
#define F1_BIST_R3__F1_BIST_CAP                            0x00000080L

// F1_MEM_BASE_LO
#define F1_MEM_BASE_LO__F1_BLOCK_MEM_BIT_MASK              0x00000001L
#define F1_MEM_BASE_LO__F1_BLOCK_MEM_BIT                   0x00000001L
#define F1_MEM_BASE_LO__F1_BLOCK_MEM_TYPE_MASK             0x00000006L
#define F1_MEM_BASE_LO__F1_PFTCH_MEM_EN_MASK               0x00000008L
#define F1_MEM_BASE_LO__F1_PFTCH_MEM_EN                    0x00000008L
#define F1_MEM_BASE_LO__F1_MEM_BASE_LO_MASK                0xfe000000L

// F1_MEM_BASE_HI
#define F1_MEM_BASE_HI__F1_MEM_BASE_HI_MASK                0xffffffffL

// F1_REG_BASE_LO
#define F1_REG_BASE_LO__F1_BLOCK_REG_BIT_MASK              0x00000001L
#define F1_REG_BASE_LO__F1_BLOCK_REG_BIT                   0x00000001L
#define F1_REG_BASE_LO__F1_BLOCK_REG_TYPE_MASK             0x00000006L
#define F1_REG_BASE_LO__F1_PFTCH_REG_EN_MASK               0x00000008L
#define F1_REG_BASE_LO__F1_PFTCH_REG_EN                    0x00000008L
#define F1_REG_BASE_LO__F1_REG_BASE_LO_MASK                0xffff0000L

// F1_REG_BASE_HI
#define F1_REG_BASE_HI__F1_REG_BASE_HI_MASK                0xffffffffL

// F1_MEM_BASE_R3
#define F1_MEM_BASE_R3__F1_BLOCK_MEM_BIT_MASK              0x00000001L
#define F1_MEM_BASE_R3__F1_BLOCK_MEM_BIT                   0x00000001L
#define F1_MEM_BASE_R3__F1_BLOCK_MEM_TYPE_MASK             0x00000006L
#define F1_MEM_BASE_R3__F1_PFTCH_MEM_EN_MASK               0x00000008L
#define F1_MEM_BASE_R3__F1_PFTCH_MEM_EN                    0x00000008L
#define F1_MEM_BASE_R3__F1_MEM_BASE_MASK                   0xfe000000L

// F1_REG_BASE_R3
#define F1_REG_BASE_R3__F1_BLOCK_REG_BIT_MASK              0x00000001L
#define F1_REG_BASE_R3__F1_BLOCK_REG_BIT                   0x00000001L
#define F1_REG_BASE_R3__F1_BLOCK_REG_TYPE_MASK             0x00000006L
#define F1_REG_BASE_R3__F1_PFTCH_REG_EN_MASK               0x00000008L
#define F1_REG_BASE_R3__F1_PFTCH_REG_EN                    0x00000008L
#define F1_REG_BASE_R3__F1_REG_BASE_MASK                   0xffff0000L

// F1_ADAPTER_ID_R3
#define F1_ADAPTER_ID_R3__F1_SUBSYSTEM_VENDOR_ID_MASK      0x0000ffffL
#define F1_ADAPTER_ID_R3__F1_SUBSYSTEM_ID_MASK             0xffff0000L

// F1_CAPABILITIES_PTR_R3
#define F1_CAPABILITIES_PTR_R3__F1_CAP_PTR_MASK            0x000000ffL

// F1_INTERRUPT_LINE_R3
#define F1_INTERRUPT_LINE_R3__F1_INTERRUPT_LINE_MASK       0x000000ffL

// F1_INTERRUPT_PIN_R3
#define F1_INTERRUPT_PIN_R3__F1_INTERRUPT_PIN_MASK         0x00000001L
#define F1_INTERRUPT_PIN_R3__F1_INTERRUPT_PIN              0x00000001L

// F1_MIN_GRANT_R3
#define F1_MIN_GRANT_R3__F1_MIN_GNT_MASK                   0x000000ffL

// F1_MAX_LATENCY_R3
#define F1_MAX_LATENCY_R3__F1_MAX_LAT_MASK                 0x000000ffL

// F1_PMI_CAP_ID_R3
#define F1_PMI_CAP_ID_R3__F1_PMI_CAP_ID_MASK               0x000000ffL

// F1_PMI_NXT_CAP_PTR_R3
#define F1_PMI_NXT_CAP_PTR_R3__F1_PMI_NXT_CAP_PTR_MASK     0x000000ffL

// F1_PMI_PMC_REG_R3
#define F1_PMI_PMC_REG_R3__F1_PMI_VERSION_MASK             0x00000007L
#define F1_PMI_PMC_REG_R3__F1_PMI_PME_CLOCK_MASK           0x00000008L
#define F1_PMI_PMC_REG_R3__F1_PMI_PME_CLOCK                0x00000008L
#define F1_PMI_PMC_REG_R3__F1_PMI_DEV_SPECIFIC_INIT_MASK   0x00000020L
#define F1_PMI_PMC_REG_R3__F1_PMI_DEV_SPECIFIC_INIT        0x00000020L
#define F1_PMI_PMC_REG_R3__F1_PMI_D1_SUPPORT_MASK          0x00000200L
#define F1_PMI_PMC_REG_R3__F1_PMI_D1_SUPPORT               0x00000200L
#define F1_PMI_PMC_REG_R3__F1_PMI_D2_SUPPORT_MASK          0x00000400L
#define F1_PMI_PMC_REG_R3__F1_PMI_D2_SUPPORT               0x00000400L
#define F1_PMI_PMC_REG_R3__F1_PMI_PME_SUPPORT_MASK         0x0000f800L

// F1_PM_STATUS_R3
#define F1_PM_STATUS_R3__F1_PMI_POWER_STATE_MASK           0x00000003L
#define F1_PM_STATUS_R3__F1_PMI_PME_EN_MASK                0x00000100L
#define F1_PM_STATUS_R3__F1_PMI_PME_EN                     0x00000100L
#define F1_PM_STATUS_R3__F1_PMI_DATA_SELECT_MASK           0x00001e00L
#define F1_PM_STATUS_R3__F1_PMI_DATA_SCALE_MASK            0x00006000L
#define F1_PM_STATUS_R3__F1_PMI_PME_STATUS_MASK            0x00008000L
#define F1_PM_STATUS_R3__F1_PMI_PME_STATUS                 0x00008000L

// F1_PMI_DATA_R3
#define F1_PMI_DATA_R3__F1_PMI_DATA_MASK                   0x000000ffL

// F1_AGP_CAP_ID_R3
#define F1_AGP_CAP_ID_R3__F1_CAP_ID_MASK                   0x000000ffL
#define F1_AGP_CAP_ID_R3__F1_NEXT_PTR_MASK                 0x0000ff00L
#define F1_AGP_CAP_ID_R3__F1_AGP_MINOR_MASK                0x000f0000L
#define F1_AGP_CAP_ID_R3__F1_AGP_MAJOR_MASK                0x00f00000L

// F1_AGP_STATUS_R3
#define F1_AGP_STATUS_R3__F1_RATE1X_4X_MASK                0x00000001L
#define F1_AGP_STATUS_R3__F1_RATE1X_4X                     0x00000001L
#define F1_AGP_STATUS_R3__F1_RATE2X_8X_MASK                0x00000002L
#define F1_AGP_STATUS_R3__F1_RATE2X_8X                     0x00000002L
#define F1_AGP_STATUS_R3__F1_RATE4X_MASK                   0x00000004L
#define F1_AGP_STATUS_R3__F1_RATE4X                        0x00000004L
#define F1_AGP_STATUS_R3__F1_MODE_AGP30_MASK               0x00000008L
#define F1_AGP_STATUS_R3__F1_MODE_AGP30                    0x00000008L
#define F1_AGP_STATUS_R3__F1_FW_MASK                       0x00000010L
#define F1_AGP_STATUS_R3__F1_FW                            0x00000010L
#define F1_AGP_STATUS_R3__F1_MODE_4G_MASK                  0x00000020L
#define F1_AGP_STATUS_R3__F1_MODE_4G                       0x00000020L
#define F1_AGP_STATUS_R3__F1_SBA_MASK                      0x00000200L
#define F1_AGP_STATUS_R3__F1_SBA                           0x00000200L
#define F1_AGP_STATUS_R3__F1_CAL_CYCLE_MASK                0x00001c00L
#define F1_AGP_STATUS_R3__F1_ISOCH_SUPPORT_MASK            0x00020000L
#define F1_AGP_STATUS_R3__F1_ISOCH_SUPPORT                 0x00020000L
#define F1_AGP_STATUS_R3__F1_RQ_MASK                       0xff000000L

// F1_AGP_COMMAND_R3
#define F1_AGP_COMMAND_R3__F1_DATA_RATE_MASK               0x00000007L
#define F1_AGP_COMMAND_R3__F1_FW_EN_MASK                   0x00000010L
#define F1_AGP_COMMAND_R3__F1_FW_EN                        0x00000010L
#define F1_AGP_COMMAND_R3__F1_MODE_4G_EN_MASK              0x00000020L
#define F1_AGP_COMMAND_R3__F1_MODE_4G_EN                   0x00000020L
#define F1_AGP_COMMAND_R3__F1_AGP_EN_MASK                  0x00000100L
#define F1_AGP_COMMAND_R3__F1_AGP_EN                       0x00000100L
#define F1_AGP_COMMAND_R3__F1_SBA_EN_MASK                  0x00000200L
#define F1_AGP_COMMAND_R3__F1_SBA_EN                       0x00000200L
#define F1_AGP_COMMAND_R3__F1_PARQSZ_MASK                  0x0000e000L
#define F1_AGP_COMMAND_R3__F1_RQ_DEPTH_MASK                0xff000000L

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
#define CRTC_GEN_CNTL__CRTC_MODE9_COLOR_ORDER_MASK         0x00001000L
#define CRTC_GEN_CNTL__CRTC_MODE9_COLOR_ORDER              0x00001000L
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
#define DAC_CNTL__DAC_TVO_EN_MASK                          0x00000400L
#define DAC_CNTL__DAC_TVO_EN                               0x00000400L
#define DAC_CNTL__DAC_CRC_BLANKb_ONLY_MASK                 0x00000800L
#define DAC_CNTL__DAC_CRC_BLANKb_ONLY                      0x00000800L
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
#define SURFACE0_INFO__SURF0_PITCHSEL_R3_MASK              0x00001fffL
#define SURFACE0_INFO__SURF0_TILE_MODE_R2_MASK             0x00070000L
#define SURFACE0_INFO__SURF0_AP0_SWP_MASK                  0x00300000L
#define SURFACE0_INFO__SURF0_AP1_SWP_MASK                  0x00c00000L
#define SURFACE0_INFO__SURF0_WRITE_FLAG_MASK               0x01000000L
#define SURFACE0_INFO__SURF0_WRITE_FLAG                    0x01000000L
#define SURFACE0_INFO__SURF0_READ_FLAG_MASK                0x02000000L
#define SURFACE0_INFO__SURF0_READ_FLAG                     0x02000000L

// SURFACE1_INFO
#define SURFACE1_INFO__SURF1_PITCHSEL_R3_MASK              0x00001fffL
#define SURFACE1_INFO__SURF1_TILE_MODE_R2_MASK             0x00070000L
#define SURFACE1_INFO__SURF1_AP0_SWP_MASK                  0x00300000L
#define SURFACE1_INFO__SURF1_AP1_SWP_MASK                  0x00c00000L
#define SURFACE1_INFO__SURF1_WRITE_FLAG_MASK               0x01000000L
#define SURFACE1_INFO__SURF1_WRITE_FLAG                    0x01000000L
#define SURFACE1_INFO__SURF1_READ_FLAG_MASK                0x02000000L
#define SURFACE1_INFO__SURF1_READ_FLAG                     0x02000000L

// SURFACE2_INFO
#define SURFACE2_INFO__SURF2_PITCHSEL_R3_MASK              0x00001fffL
#define SURFACE2_INFO__SURF2_TILE_MODE_R2_MASK             0x00070000L
#define SURFACE2_INFO__SURF2_AP0_SWP_MASK                  0x00300000L
#define SURFACE2_INFO__SURF2_AP1_SWP_MASK                  0x00c00000L
#define SURFACE2_INFO__SURF2_WRITE_FLAG_MASK               0x01000000L
#define SURFACE2_INFO__SURF2_WRITE_FLAG                    0x01000000L
#define SURFACE2_INFO__SURF2_READ_FLAG_MASK                0x02000000L
#define SURFACE2_INFO__SURF2_READ_FLAG                     0x02000000L

// SURFACE3_INFO
#define SURFACE3_INFO__SURF3_PITCHSEL_R3_MASK              0x00001fffL
#define SURFACE3_INFO__SURF3_TILE_MODE_R2_MASK             0x00070000L
#define SURFACE3_INFO__SURF3_AP0_SWP_MASK                  0x00300000L
#define SURFACE3_INFO__SURF3_AP1_SWP_MASK                  0x00c00000L
#define SURFACE3_INFO__SURF3_WRITE_FLAG_MASK               0x01000000L
#define SURFACE3_INFO__SURF3_WRITE_FLAG                    0x01000000L
#define SURFACE3_INFO__SURF3_READ_FLAG_MASK                0x02000000L
#define SURFACE3_INFO__SURF3_READ_FLAG                     0x02000000L

// SURFACE4_INFO
#define SURFACE4_INFO__SURF4_PITCHSEL_R3_MASK              0x00001fffL
#define SURFACE4_INFO__SURF4_TILE_MODE_R2_MASK             0x00070000L
#define SURFACE4_INFO__SURF4_AP0_SWP_MASK                  0x00300000L
#define SURFACE4_INFO__SURF4_AP1_SWP_MASK                  0x00c00000L
#define SURFACE4_INFO__SURF4_WRITE_FLAG_MASK               0x01000000L
#define SURFACE4_INFO__SURF4_WRITE_FLAG                    0x01000000L
#define SURFACE4_INFO__SURF4_READ_FLAG_MASK                0x02000000L
#define SURFACE4_INFO__SURF4_READ_FLAG                     0x02000000L

// SURFACE5_INFO
#define SURFACE5_INFO__SURF5_PITCHSEL_R3_MASK              0x00001fffL
#define SURFACE5_INFO__SURF5_TILE_MODE_R2_MASK             0x00070000L
#define SURFACE5_INFO__SURF5_AP0_SWP_MASK                  0x00300000L
#define SURFACE5_INFO__SURF5_AP1_SWP_MASK                  0x00c00000L
#define SURFACE5_INFO__SURF5_WRITE_FLAG_MASK               0x01000000L
#define SURFACE5_INFO__SURF5_WRITE_FLAG                    0x01000000L
#define SURFACE5_INFO__SURF5_READ_FLAG_MASK                0x02000000L
#define SURFACE5_INFO__SURF5_READ_FLAG                     0x02000000L

// SURFACE6_INFO
#define SURFACE6_INFO__SURF6_PITCHSEL_R3_MASK              0x00001fffL
#define SURFACE6_INFO__SURF6_TILE_MODE_R2_MASK             0x00070000L
#define SURFACE6_INFO__SURF6_AP0_SWP_MASK                  0x00300000L
#define SURFACE6_INFO__SURF6_AP1_SWP_MASK                  0x00c00000L
#define SURFACE6_INFO__SURF6_WRITE_FLAG_MASK               0x01000000L
#define SURFACE6_INFO__SURF6_WRITE_FLAG                    0x01000000L
#define SURFACE6_INFO__SURF6_READ_FLAG_MASK                0x02000000L
#define SURFACE6_INFO__SURF6_READ_FLAG                     0x02000000L

// SURFACE7_INFO
#define SURFACE7_INFO__SURF7_PITCHSEL_R3_MASK              0x00001fffL
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
#define VCLK_ECP_CNTL__PCICLK_INVERT_MASK                  0x00000020L
#define VCLK_ECP_CNTL__PCICLK_INVERT                       0x00000020L
#define VCLK_ECP_CNTL__PIXCLK_ALWAYS_ONb_MASK              0x00000040L
#define VCLK_ECP_CNTL__PIXCLK_ALWAYS_ONb                   0x00000040L
#define VCLK_ECP_CNTL__PIXCLK_DAC_ALWAYS_ONb_MASK          0x00000080L
#define VCLK_ECP_CNTL__PIXCLK_DAC_ALWAYS_ONb               0x00000080L
#define VCLK_ECP_CNTL__ECP_DIV_MASK                        0x00000300L
#define VCLK_ECP_CNTL__BYTE_CLK_POST_DIV_MASK              0x00030000L
#define VCLK_ECP_CNTL__ECP_FORCE_ON_MASK                   0x00040000L
#define VCLK_ECP_CNTL__ECP_FORCE_ON                        0x00040000L
#define VCLK_ECP_CNTL__SUBCLK_FORCE_ON_MASK                0x00080000L
#define VCLK_ECP_CNTL__SUBCLK_FORCE_ON                     0x00080000L
#define VCLK_ECP_CNTL__BYTE_CLK_OUT_EN_MASK                0x00100000L
#define VCLK_ECP_CNTL__BYTE_CLK_OUT_EN                     0x00100000L
#define VCLK_ECP_CNTL__BYTE_CLK_SKEW_MASK                  0x07000000L
#define VCLK_ECP_CNTL__PIXCLK_SRC_INVERT_R3_MASK           0x08000000L
#define VCLK_ECP_CNTL__PIXCLK_SRC_INVERT_R3                0x08000000L

// BYTE_CLK_AUX_CNTL
#define BYTE_CLK_AUX_CNTL__IO_BYTCLK_SRC_SEL_MASK          0x00000003L
#define BYTE_CLK_AUX_CNTL__TV_BYTCLK_SRC_SEL_MASK          0x0000000cL
#define BYTE_CLK_AUX_CNTL__IO_BYTCLK_SKW_CTL_MASK          0x00000070L
#define BYTE_CLK_AUX_CNTL__TV_BYTCLK_SKW_CTL_MASK          0x00000700L

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
#define DISP_TEST_MACRO_RW_CNTL__TEST_ALTCLK_ENABLE_MASK   0x00040000L
#define DISP_TEST_MACRO_RW_CNTL__TEST_ALTCLK_ENABLE        0x00040000L
#define DISP_TEST_MACRO_RW_CNTL__DISPCLKBLK_CLK_TO_OUTPIN_MASK 0x00080000L
#define DISP_TEST_MACRO_RW_CNTL__DISPCLKBLK_CLK_TO_OUTPIN  0x00080000L

// PIXCLKS_CNTL
#define PIXCLKS_CNTL__PIX2CLK_SRC_SEL_MASK                 0x00000003L
#define PIXCLKS_CNTL__PIX2CLK_INVERT_MASK                  0x00000010L
#define PIXCLKS_CNTL__PIX2CLK_INVERT                       0x00000010L
#define PIXCLKS_CNTL__PCICLK_INVERT_MASK                   0x00000020L
#define PIXCLKS_CNTL__PCICLK_INVERT                        0x00000020L
#define PIXCLKS_CNTL__PIX2CLK_ALWAYS_ONb_MASK              0x00000040L
#define PIXCLKS_CNTL__PIX2CLK_ALWAYS_ONb                   0x00000040L
#define PIXCLKS_CNTL__PIX2CLK_DAC_ALWAYS_ONb_MASK          0x00000080L
#define PIXCLKS_CNTL__PIX2CLK_DAC_ALWAYS_ONb               0x00000080L
#define PIXCLKS_CNTL__PIXCLK_TV_SRC_SEL_MASK               0x00000100L
#define PIXCLKS_CNTL__PIXCLK_TV_SRC_SEL                    0x00000100L
#define PIXCLKS_CNTL__DISP_TVOUT_PIXCLK_TV_ALWAYS_ONb_MASK 0x00000200L
#define PIXCLKS_CNTL__DISP_TVOUT_PIXCLK_TV_ALWAYS_ONb      0x00000200L
#define PIXCLKS_CNTL__DVOCLK_ALWAYS_ONb_MASK               0x00000400L
#define PIXCLKS_CNTL__DVOCLK_ALWAYS_ONb                    0x00000400L
#define PIXCLKS_CNTL__PIXCLK_BLEND_ALWAYS_ONb_MASK         0x00000800L
#define PIXCLKS_CNTL__PIXCLK_BLEND_ALWAYS_ONb              0x00000800L
#define PIXCLKS_CNTL__PIXCLK_GV_ALWAYS_ONb_MASK            0x00001000L
#define PIXCLKS_CNTL__PIXCLK_GV_ALWAYS_ONb                 0x00001000L
#define PIXCLKS_CNTL__PIXCLK_DVO_ALWAYS_ONb_MASK           0x00002000L
#define PIXCLKS_CNTL__PIXCLK_DVO_ALWAYS_ONb                0x00002000L
#define PIXCLKS_CNTL__PIXCLK_LVDS_ALWAYS_ONb_MASK          0x00004000L
#define PIXCLKS_CNTL__PIXCLK_LVDS_ALWAYS_ONb               0x00004000L
#define PIXCLKS_CNTL__PIXCLK_TMDS_ALWAYS_ONb_MASK          0x00008000L
#define PIXCLKS_CNTL__PIXCLK_TMDS_ALWAYS_ONb               0x00008000L
#define PIXCLKS_CNTL__PIXCLK_TRANS_ALWAYS_ONb_MASK         0x00010000L
#define PIXCLKS_CNTL__PIXCLK_TRANS_ALWAYS_ONb              0x00010000L
#define PIXCLKS_CNTL__PIXCLK_TVO_ALWAYS_ONb_MASK           0x00020000L
#define PIXCLKS_CNTL__PIXCLK_TVO_ALWAYS_ONb                0x00020000L
#define PIXCLKS_CNTL__P2GCLK_ALWAYS_ONb_MASK               0x00040000L
#define PIXCLKS_CNTL__P2GCLK_ALWAYS_ONb                    0x00040000L
#define PIXCLKS_CNTL__P2G2CLK_ALWAYS_ONb_MASK              0x00080000L
#define PIXCLKS_CNTL__P2G2CLK_ALWAYS_ONb                   0x00080000L
#define PIXCLKS_CNTL__DVOCLKC_IN_PHASE_MASK                0x00100000L
#define PIXCLKS_CNTL__DVOCLKC_IN_PHASE                     0x00100000L
#define PIXCLKS_CNTL__DVOCLKD_IN_PHASE_MASK                0x00400000L
#define PIXCLKS_CNTL__DVOCLKD_IN_PHASE                     0x00400000L
#define PIXCLKS_CNTL__DVOCLKC_SKW_CTL_MASK                 0x07000000L
#define PIXCLKS_CNTL__DVOCLKD_SKW_CTL_MASK                 0x70000000L
#define PIXCLKS_CNTL__PIX2CLK_SRC_INVERT_R3_MASK           0x80000000L
#define PIXCLKS_CNTL__PIX2CLK_SRC_INVERT_R3                0x80000000L

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

// GPIO_DDC1
#define GPIO_DDC1__DDC1_DATA_OUTPUT_MASK                   0x00000001L
#define GPIO_DDC1__DDC1_DATA_OUTPUT                        0x00000001L
#define GPIO_DDC1__DDC1_CLK_OUTPUT_MASK                    0x00000002L
#define GPIO_DDC1__DDC1_CLK_OUTPUT                         0x00000002L
#define GPIO_DDC1__DDC1_DATA_INPUT_MASK                    0x00000100L
#define GPIO_DDC1__DDC1_DATA_INPUT                         0x00000100L
#define GPIO_DDC1__DDC1_CLK_INPUT_MASK                     0x00000200L
#define GPIO_DDC1__DDC1_CLK_INPUT                          0x00000200L
#define GPIO_DDC1__DDC1_DATA_OUT_EN_MASK                   0x00010000L
#define GPIO_DDC1__DDC1_DATA_OUT_EN                        0x00010000L
#define GPIO_DDC1__DDC1_CLK_OUT_EN_MASK                    0x00020000L
#define GPIO_DDC1__DDC1_CLK_OUT_EN                         0x00020000L
#define GPIO_DDC1__SW_WANTS_TO_USE_DVI_I2C_MASK            0x00100000L
#define GPIO_DDC1__SW_WANTS_TO_USE_DVI_I2C                 0x00100000L
#define GPIO_DDC1__SW_CAN_USE_DVI_I2C_MASK                 0x00100000L
#define GPIO_DDC1__SW_CAN_USE_DVI_I2C                      0x00100000L
#define GPIO_DDC1__SW_DONE_USING_DVI_I2C_MASK              0x00200000L
#define GPIO_DDC1__SW_DONE_USING_DVI_I2C                   0x00200000L
#define GPIO_DDC1__HDCP_NEEDS_DVI_I2C_MASK                 0x00200000L
#define GPIO_DDC1__HDCP_NEEDS_DVI_I2C                      0x00200000L
#define GPIO_DDC1__ABORT_HDCP_DVI_I2C_MASK                 0x00400000L
#define GPIO_DDC1__ABORT_HDCP_DVI_I2C                      0x00400000L
#define GPIO_DDC1__HW_USING_DVI_I2C_MASK                   0x00400000L
#define GPIO_DDC1__HW_USING_DVI_I2C                        0x00400000L

// GPIO_DDC2
#define GPIO_DDC2__DDC2_DATA_OUTPUT_MASK                   0x00000001L
#define GPIO_DDC2__DDC2_DATA_OUTPUT                        0x00000001L
#define GPIO_DDC2__DDC2_CLK_OUTPUT_MASK                    0x00000002L
#define GPIO_DDC2__DDC2_CLK_OUTPUT                         0x00000002L
#define GPIO_DDC2__DDC2_DATA_INPUT_MASK                    0x00000100L
#define GPIO_DDC2__DDC2_DATA_INPUT                         0x00000100L
#define GPIO_DDC2__DDC2_CLK_INPUT_MASK                     0x00000200L
#define GPIO_DDC2__DDC2_CLK_INPUT                          0x00000200L
#define GPIO_DDC2__DDC2_DATA_OUT_EN_MASK                   0x00010000L
#define GPIO_DDC2__DDC2_DATA_OUT_EN                        0x00010000L
#define GPIO_DDC2__DDC2_CLK_OUT_EN_MASK                    0x00020000L
#define GPIO_DDC2__DDC2_CLK_OUT_EN                         0x00020000L
#define GPIO_DDC2__SW_WANTS_TO_USE_DVI_I2C_MASK            0x00100000L
#define GPIO_DDC2__SW_WANTS_TO_USE_DVI_I2C                 0x00100000L
#define GPIO_DDC2__SW_CAN_USE_DVI_I2C_MASK                 0x00100000L
#define GPIO_DDC2__SW_CAN_USE_DVI_I2C                      0x00100000L
#define GPIO_DDC2__SW_DONE_USING_DVI_I2C_MASK              0x00200000L
#define GPIO_DDC2__SW_DONE_USING_DVI_I2C                   0x00200000L
#define GPIO_DDC2__HDCP_NEEDS_DVI_I2C_MASK                 0x00200000L
#define GPIO_DDC2__HDCP_NEEDS_DVI_I2C                      0x00200000L
#define GPIO_DDC2__ABORT_HDCP_DVI_I2C_MASK                 0x00400000L
#define GPIO_DDC2__ABORT_HDCP_DVI_I2C                      0x00400000L
#define GPIO_DDC2__HW_USING_DVI_I2C_MASK                   0x00400000L
#define GPIO_DDC2__HW_USING_DVI_I2C                        0x00400000L

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

// TIMER_INT_CNTL
#define TIMER_INT_CNTL__TIMER_INT_CNT_MASK                 0x00ffffffL
#define TIMER_INT_CNTL__TIMER_INT_EN_MASK                  0x40000000L
#define TIMER_INT_CNTL__TIMER_INT_EN                       0x40000000L
#define TIMER_INT_CNTL__TIMER_INT_RUNNING_MASK             0x80000000L
#define TIMER_INT_CNTL__TIMER_INT_RUNNING                  0x80000000L

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
#define CRTC_OFFSET_RIGHT__CRTC_OFFSET_RIGHT_R3_MASK       0x0fffffffL
#define CRTC_OFFSET_RIGHT__CRTC_GUI_TRIG_OFFSET_MASK       0x40000000L
#define CRTC_OFFSET_RIGHT__CRTC_GUI_TRIG_OFFSET            0x40000000L
#define CRTC_OFFSET_RIGHT__CRTC_OFFSET_LOCK_MASK           0x80000000L
#define CRTC_OFFSET_RIGHT__CRTC_OFFSET_LOCK                0x80000000L

// CRTC_OFFSET
#define CRTC_OFFSET__CRTC_OFFSET_R3_MASK                   0x0fffffffL
#define CRTC_OFFSET__CRTC_GUI_TRIG_OFFSET_MASK             0x40000000L
#define CRTC_OFFSET__CRTC_GUI_TRIG_OFFSET                  0x40000000L
#define CRTC_OFFSET__CRTC_OFFSET_LOCK_MASK                 0x80000000L
#define CRTC_OFFSET__CRTC_OFFSET_LOCK                      0x80000000L

// CRTC_OFFSET_CNTL
#define CRTC_OFFSET_CNTL__CRTC_X_Y_MODE_EN_RIGHT_MASK      0x00000040L
#define CRTC_OFFSET_CNTL__CRTC_X_Y_MODE_EN_RIGHT           0x00000040L
#define CRTC_OFFSET_CNTL__CRTC_MICRO_TILE_BUFFER_MODE_RIGHT_MASK 0x00000180L
#define CRTC_OFFSET_CNTL__CRTC_X_Y_MODE_EN_MASK            0x00000200L
#define CRTC_OFFSET_CNTL__CRTC_X_Y_MODE_EN                 0x00000200L
#define CRTC_OFFSET_CNTL__CRTC_MICRO_TILE_BUFFER_MODE_MASK 0x00000c00L
#define CRTC_OFFSET_CNTL__CRTC_MICRO_TILE_EN_RIGHT_MASK    0x00001000L
#define CRTC_OFFSET_CNTL__CRTC_MICRO_TILE_EN_RIGHT         0x00001000L
#define CRTC_OFFSET_CNTL__CRTC_MICRO_TILE_EN_MASK          0x00002000L
#define CRTC_OFFSET_CNTL__CRTC_MICRO_TILE_EN               0x00002000L
#define CRTC_OFFSET_CNTL__CRTC_MACRO_TILE_EN_RIGHT_MASK    0x00004000L
#define CRTC_OFFSET_CNTL__CRTC_MACRO_TILE_EN_RIGHT         0x00004000L
#define CRTC_OFFSET_CNTL__CRTC_MACRO_TILE_EN_MASK          0x00008000L
#define CRTC_OFFSET_CNTL__CRTC_MACRO_TILE_EN               0x00008000L
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

// GRPH_BUFFER_STATUS
#define GRPH_BUFFER_STATUS__GRPH_LOWEST_BUFFER_LEVEL_MASK  0x0000007fL
#define GRPH_BUFFER_STATUS__GRPH_LOWEST_BUFFER_LEVEL_RESET_MASK 0x00000080L
#define GRPH_BUFFER_STATUS__GRPH_LOWEST_BUFFER_LEVEL_RESET 0x00000080L
#define GRPH_BUFFER_STATUS__GRPH2_LOWEST_BUFFER_LEVEL_MASK 0x00007f00L
#define GRPH_BUFFER_STATUS__GRPH2_LOWEST_BUFFER_LEVEL_RESET_MASK 0x00008000L
#define GRPH_BUFFER_STATUS__GRPH2_LOWEST_BUFFER_LEVEL_RESET 0x00008000L

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
#define CRTC_MORE_CNTL__DSP_RST_HCOUNT_MASK                0x00000100L
#define CRTC_MORE_CNTL__DSP_RST_HCOUNT                     0x00000100L
#define CRTC_MORE_CNTL__DSP_RST_VCOUNT_MASK                0x00000200L
#define CRTC_MORE_CNTL__DSP_RST_VCOUNT                     0x00000200L
#define CRTC_MORE_CNTL__HCOUNT_RST_POS_MASK                0x00000400L
#define CRTC_MORE_CNTL__HCOUNT_RST_POS                     0x00000400L
#define CRTC_MORE_CNTL__VCOUNT_RST_POS_MASK                0x00000800L
#define CRTC_MORE_CNTL__VCOUNT_RST_POS                     0x00000800L
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
#define FP_GEN_CNTL__FP_SOURCE_SEL_MASK                    0x00000c00L
#define FP_GEN_CNTL__FP_DETECT_EN_MASK                     0x00001000L
#define FP_GEN_CNTL__FP_DETECT_EN                          0x00001000L
#define FP_GEN_CNTL__HPD_SEL_MASK                          0x00002000L
#define FP_GEN_CNTL__HPD_SEL                               0x00002000L
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
#define FP2_GEN_CNTL__FP2_SOURCE_SEL_MASK                  0x00000c00L
#define FP2_GEN_CNTL__FP2_CRC_EN_MASK                      0x00800000L
#define FP2_GEN_CNTL__FP2_CRC_EN                           0x00800000L
#define FP2_GEN_CNTL__FP2_CRC_READ_EN_MASK                 0x01000000L
#define FP2_GEN_CNTL__FP2_CRC_READ_EN                      0x01000000L
#define FP2_GEN_CNTL__DVO_EN_MASK                          0x02000000L
#define FP2_GEN_CNTL__DVO_EN                               0x02000000L
#define FP2_GEN_CNTL__DVO_TMDS_CTL3_MASK                   0x04000000L
#define FP2_GEN_CNTL__DVO_TMDS_CTL3                        0x04000000L
#define FP2_GEN_CNTL__DVO_RATE_SEL_MASK                    0x08000000L
#define FP2_GEN_CNTL__DVO_RATE_SEL                         0x08000000L
#define FP2_GEN_CNTL__DVO_CLOCK_MODE_MASK                  0x10000000L
#define FP2_GEN_CNTL__DVO_CLOCK_MODE                       0x10000000L
#define FP2_GEN_CNTL__DVO_DUAL_CHANNEL_EN_MASK             0x20000000L
#define FP2_GEN_CNTL__DVO_DUAL_CHANNEL_EN                  0x20000000L
#define FP2_GEN_CNTL__DVO_TMDS_CTL3_SEL_MASK               0xc0000000L

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
#define TMDS_PLL_CNTL__TMDS_PLLPCP_R3_MASK                 0x0000003fL
#define TMDS_PLL_CNTL__TMDS_PLLPVG_R3_MASK                 0x00000fc0L
#define TMDS_PLL_CNTL__TMDS_PLLPDC_R3_MASK                 0x0000f000L
#define TMDS_PLL_CNTL__TMDS_PLLPVS_R3_MASK                 0x000f0000L
#define TMDS_PLL_CNTL__PLSEL_MASK                          0x40000000L
#define TMDS_PLL_CNTL__PLSEL                               0x40000000L
#define TMDS_PLL_CNTL__PLDIVSEL_MASK                       0x80000000L
#define TMDS_PLL_CNTL__PLDIVSEL                            0x80000000L

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

// LVDS_DVO_CRC
#define LVDS_DVO_CRC__LVDS_DVO_CRC_SIG_RGB_MASK            0x00ffffffL
#define LVDS_DVO_CRC__LVDS_DVO_CRC_SIG_RGB_MASK_MASK       0x00ffffffL
#define LVDS_DVO_CRC__LVDS_DVO_CRC_SIG_C_MASK              0x07000000L
#define LVDS_DVO_CRC__LVDS_DVO_CRC_SIG_C_MASK_MASK         0x07000000L

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
#define LVDS_PLL_CNTL__LVDS_SRC_SEL_MASK                   0x000c0000L
#define LVDS_PLL_CNTL__LVDS_CRC_EN_MASK                    0x00100000L
#define LVDS_PLL_CNTL__LVDS_CRC_EN                         0x00100000L
#define LVDS_PLL_CNTL__LVDS_CRC_UP24_MASK                  0x00200000L
#define LVDS_PLL_CNTL__LVDS_CRC_UP24                       0x00200000L
#define LVDS_PLL_CNTL__LVDS_TEST_DATA_OUT_MASK             0x01c00000L
#define LVDS_PLL_CNTL__LVDS_TEST_DATA_SEL_MASK             0x06000000L
#define LVDS_PLL_CNTL__LVDS_PREAMPH_EN_R3_MASK             0x08000000L
#define LVDS_PLL_CNTL__LVDS_PREAMPH_EN_R3                  0x08000000L
#define LVDS_PLL_CNTL__LCDENG_TEST_MODE_MASK               0xf0000000L

// AUX_WINDOW_HORZ_CNTL
#define AUX_WINDOW_HORZ_CNTL__AUX_WIN_HORZ_START_MASK      0x00000fffL
#define AUX_WINDOW_HORZ_CNTL__AUX_WIN_HORZ_END_MASK        0x00fff000L
#define AUX_WINDOW_HORZ_CNTL__AUX_WIN_EN_MASK              0x01000000L
#define AUX_WINDOW_HORZ_CNTL__AUX_WIN_EN                   0x01000000L
#define AUX_WINDOW_HORZ_CNTL__AUX_WIN_OUT_DELAY_R2_MASK    0x0e000000L
#define AUX_WINDOW_HORZ_CNTL__AUX_WIN_LOCK_MASK            0x80000000L
#define AUX_WINDOW_HORZ_CNTL__AUX_WIN_LOCK                 0x80000000L

// AUX_WINDOW_VERT_CNTL
#define AUX_WINDOW_VERT_CNTL__AUX_WIN_VERT_START_MASK      0x00000fffL
#define AUX_WINDOW_VERT_CNTL__AUX_WIN_VERT_END_MASK        0x0fff0000L
#define AUX_WINDOW_VERT_CNTL__AUX_WIN_INPUT_MASK           0x20000000L
#define AUX_WINDOW_VERT_CNTL__AUX_WIN_INPUT                0x20000000L
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
#define DVI_I2C_CNTL_0__DVI_I2C_PIN_SEL_MASK               0x00000010L
#define DVI_I2C_CNTL_0__DVI_I2C_PIN_SEL                    0x00000010L
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
#define DVI_I2C_CNTL_1__I2C_ADDR_COUNT_R2_MASK             0x00000070L
#define DVI_I2C_CNTL_1__I2C_INTRA_BYTE_DELAY_MASK          0x0000ff00L
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
#define GRPH_BUFFER_CNTL__GRPH_CRITICAL_MODE_MASK          0x08000000L
#define GRPH_BUFFER_CNTL__GRPH_CRITICAL_MODE               0x08000000L
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

// CRTC2_OFFSET_RIGHT
#define CRTC2_OFFSET_RIGHT__CRTC2_OFFSET_RIGHT_R3_MASK     0x0fffffffL
#define CRTC2_OFFSET_RIGHT__CRTC2_GUI_TRIG_OFFSET_MASK     0x40000000L
#define CRTC2_OFFSET_RIGHT__CRTC2_GUI_TRIG_OFFSET          0x40000000L
#define CRTC2_OFFSET_RIGHT__CRTC2_OFFSET_LOCK_MASK         0x80000000L
#define CRTC2_OFFSET_RIGHT__CRTC2_OFFSET_LOCK              0x80000000L

// CRTC2_OFFSET
#define CRTC2_OFFSET__CRTC2_OFFSET_R3_MASK                 0x0fffffffL
#define CRTC2_OFFSET__CRTC2_GUI_TRIG_OFFSET_MASK           0x40000000L
#define CRTC2_OFFSET__CRTC2_GUI_TRIG_OFFSET                0x40000000L
#define CRTC2_OFFSET__CRTC2_OFFSET_LOCK_MASK               0x80000000L
#define CRTC2_OFFSET__CRTC2_OFFSET_LOCK                    0x80000000L

// CRTC2_OFFSET_CNTL
#define CRTC2_OFFSET_CNTL__CRTC2_X_Y_MODE_EN_RIGHT_MASK    0x00000100L
#define CRTC2_OFFSET_CNTL__CRTC2_X_Y_MODE_EN_RIGHT         0x00000100L
#define CRTC2_OFFSET_CNTL__CRTC2_X_Y_MODE_EN_MASK          0x00000200L
#define CRTC2_OFFSET_CNTL__CRTC2_X_Y_MODE_EN               0x00000200L
#define CRTC2_OFFSET_CNTL__CRTC2_MICRO_TILE_EN_RIGHT_MASK  0x00001000L
#define CRTC2_OFFSET_CNTL__CRTC2_MICRO_TILE_EN_RIGHT       0x00001000L
#define CRTC2_OFFSET_CNTL__CRTC2_MICRO_TILE_EN_MASK        0x00002000L
#define CRTC2_OFFSET_CNTL__CRTC2_MICRO_TILE_EN             0x00002000L
#define CRTC2_OFFSET_CNTL__CRTC2_MACRO_TILE_EN_RIGHT_MASK  0x00004000L
#define CRTC2_OFFSET_CNTL__CRTC2_MACRO_TILE_EN_RIGHT       0x00004000L
#define CRTC2_OFFSET_CNTL__CRTC2_MACRO_TILE_EN_MASK        0x00008000L
#define CRTC2_OFFSET_CNTL__CRTC2_MACRO_TILE_EN             0x00008000L
#define CRTC2_OFFSET_CNTL__CRTC2_OFFSET_FLIP_CNTL_MASK     0x00010000L
#define CRTC2_OFFSET_CNTL__CRTC2_OFFSET_FLIP_CNTL          0x00010000L
#define CRTC2_OFFSET_CNTL__CRTC2_STEREO_OFFSET_EN_MASK     0x00020000L
#define CRTC2_OFFSET_CNTL__CRTC2_STEREO_OFFSET_EN          0x00020000L
#define CRTC2_OFFSET_CNTL__CRTC2_STEREO_SYNC_EN_MASK       0x000c0000L
#define CRTC2_OFFSET_CNTL__CRTC2_STEREO_SYNC_MASK          0x00200000L
#define CRTC2_OFFSET_CNTL__CRTC2_STEREO_SYNC               0x00200000L
#define CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET_LEFT_EN_MASK 0x10000000L
#define CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET_LEFT_EN   0x10000000L
#define CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET_RIGHT_EN_MASK 0x20000000L
#define CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET_RIGHT_EN  0x20000000L
#define CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET_MASK      0x40000000L
#define CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET           0x40000000L
#define CRTC2_OFFSET_CNTL__CRTC2_OFFSET_LOCK_MASK          0x80000000L
#define CRTC2_OFFSET_CNTL__CRTC2_OFFSET_LOCK               0x80000000L

// CRTC2_PITCH
#define CRTC2_PITCH__CRTC2_PITCH_MASK                      0x000007ffL
#define CRTC2_PITCH__CRTC2_PITCH_RIGHT_MASK                0x07ff0000L

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

// CRTC_TILE_X0_Y0
#define CRTC_TILE_X0_Y0__CRTC_TILE_X0_MASK                 0x00000fffL
#define CRTC_TILE_X0_Y0__CRTC_TILE_Y0_MASK                 0x0fff0000L
#define CRTC_TILE_X0_Y0__CRTC_GUI_TRIG_OFFSET_MASK         0x40000000L
#define CRTC_TILE_X0_Y0__CRTC_GUI_TRIG_OFFSET              0x40000000L
#define CRTC_TILE_X0_Y0__CRTC_OFFSET_LOCK_MASK             0x80000000L
#define CRTC_TILE_X0_Y0__CRTC_OFFSET_LOCK                  0x80000000L

// CRTC_TILE_X0_Y0_RIGHT
#define CRTC_TILE_X0_Y0_RIGHT__CRTC_TILE_X0_RIGHT_MASK     0x00000fffL
#define CRTC_TILE_X0_Y0_RIGHT__CRTC_TILE_Y0_RIGHT_MASK     0x0fff0000L
#define CRTC_TILE_X0_Y0_RIGHT__CRTC_GUI_TRIG_OFFSET_MASK   0x40000000L
#define CRTC_TILE_X0_Y0_RIGHT__CRTC_GUI_TRIG_OFFSET        0x40000000L
#define CRTC_TILE_X0_Y0_RIGHT__CRTC_OFFSET_LOCK_MASK       0x80000000L
#define CRTC_TILE_X0_Y0_RIGHT__CRTC_OFFSET_LOCK            0x80000000L

// CRTC2_TILE_X0_Y0
#define CRTC2_TILE_X0_Y0__CRTC2_TILE_X0_MASK               0x00000fffL
#define CRTC2_TILE_X0_Y0__CRTC2_TILE_Y0_MASK               0x0fff0000L
#define CRTC2_TILE_X0_Y0__CRTC2_GUI_TRIG_OFFSET_MASK       0x40000000L
#define CRTC2_TILE_X0_Y0__CRTC2_GUI_TRIG_OFFSET            0x40000000L
#define CRTC2_TILE_X0_Y0__CRTC2_OFFSET_LOCK_MASK           0x80000000L
#define CRTC2_TILE_X0_Y0__CRTC2_OFFSET_LOCK                0x80000000L

// CRTC2_TILE_X0_Y0_RIGHT
#define CRTC2_TILE_X0_Y0_RIGHT__CRTC2_TILE_X0_RIGHT_MASK   0x00000fffL
#define CRTC2_TILE_X0_Y0_RIGHT__CRTC2_TILE_Y0_RIGHT_MASK   0x0fff0000L
#define CRTC2_TILE_X0_Y0_RIGHT__CRTC2_GUI_TRIG_OFFSET_MASK 0x40000000L
#define CRTC2_TILE_X0_Y0_RIGHT__CRTC2_GUI_TRIG_OFFSET      0x40000000L
#define CRTC2_TILE_X0_Y0_RIGHT__CRTC2_OFFSET_LOCK_MASK     0x80000000L
#define CRTC2_TILE_X0_Y0_RIGHT__CRTC2_OFFSET_LOCK          0x80000000L

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

// DVO_STRENGTH_CNTL
#define DVO_STRENGTH_CNTL__DVO_SP_MASK                     0x0000000fL
#define DVO_STRENGTH_CNTL__DVO_SN_MASK                     0x000000f0L
#define DVO_STRENGTH_CNTL__DVOCLK_SP_MASK                  0x00000f00L
#define DVO_STRENGTH_CNTL__DVOCLK_SN_MASK                  0x0000f000L
#define DVO_STRENGTH_CNTL__DVO_SRP_MASK                    0x00010000L
#define DVO_STRENGTH_CNTL__DVO_SRP                         0x00010000L
#define DVO_STRENGTH_CNTL__DVO_SRN_MASK                    0x00020000L
#define DVO_STRENGTH_CNTL__DVO_SRN                         0x00020000L
#define DVO_STRENGTH_CNTL__DVOCLK_SRP_MASK                 0x00040000L
#define DVO_STRENGTH_CNTL__DVOCLK_SRP                      0x00040000L
#define DVO_STRENGTH_CNTL__DVOCLK_SRN_MASK                 0x00080000L
#define DVO_STRENGTH_CNTL__DVOCLK_SRN                      0x00080000L

// TVO_STRENGTH_CNTL
#define TVO_STRENGTH_CNTL__TVO_SP_MASK                     0x0000000fL
#define TVO_STRENGTH_CNTL__TVO_SN_MASK                     0x000000f0L
#define TVO_STRENGTH_CNTL__TVOCLK_SP_MASK                  0x00000f00L
#define TVO_STRENGTH_CNTL__TVOCLK_SN_MASK                  0x0000f000L
#define TVO_STRENGTH_CNTL__TVO_SRP_MASK                    0x00010000L
#define TVO_STRENGTH_CNTL__TVO_SRP                         0x00010000L
#define TVO_STRENGTH_CNTL__TVO_SRN_MASK                    0x00020000L
#define TVO_STRENGTH_CNTL__TVO_SRN                         0x00020000L
#define TVO_STRENGTH_CNTL__TVOCLK_SRP_MASK                 0x00040000L
#define TVO_STRENGTH_CNTL__TVOCLK_SRP                      0x00040000L
#define TVO_STRENGTH_CNTL__TVOCLK_SRN_MASK                 0x00080000L
#define TVO_STRENGTH_CNTL__TVOCLK_SRN                      0x00080000L

// GRPH2_BUFFER_CNTL
#define GRPH2_BUFFER_CNTL__GRPH2_START_REQ_MASK            0x0000007fL
#define GRPH2_BUFFER_CNTL__GRPH2_STOP_REQ_MASK             0x00007f00L
#define GRPH2_BUFFER_CNTL__GRPH2_CRITICAL_POINT_MASK       0x007f0000L
#define GRPH2_BUFFER_CNTL__GRPH2_CRITICAL_MODE_MASK        0x08000000L
#define GRPH2_BUFFER_CNTL__GRPH2_CRITICAL_MODE             0x08000000L
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
#define CRTC2_GEN_CNTL__CRTC2_MODE9_COLOR_ORDER_MASK       0x00001000L
#define CRTC2_GEN_CNTL__CRTC2_MODE9_COLOR_ORDER            0x00001000L
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
#define OV0_SCALE_CNTL__OV0_FULL_BYPASS_MASK               0x00000020L
#define OV0_SCALE_CNTL__OV0_FULL_BYPASS                    0x00000020L
#define OV0_SCALE_CNTL__OV0_DYNAMIC_EXT_MASK               0x00000040L
#define OV0_SCALE_CNTL__OV0_DYNAMIC_EXT                    0x00000040L
#define OV0_SCALE_CNTL__OV0_RGB30_ON_MASK                  0x00000080L
#define OV0_SCALE_CNTL__OV0_RGB30_ON                       0x00000080L
#define OV0_SCALE_CNTL__OV0_SURFACE_FORMAT_MASK            0x00000f00L
#define OV0_SCALE_CNTL__OV0_ADAPTIVE_DEINT_MASK            0x00001000L
#define OV0_SCALE_CNTL__OV0_ADAPTIVE_DEINT                 0x00001000L
#define OV0_SCALE_CNTL__OV0_TEMPORAL_DEINT_MASK            0x00002000L
#define OV0_SCALE_CNTL__OV0_TEMPORAL_DEINT                 0x00002000L
#define OV0_SCALE_CNTL__OV0_CRTC_SEL_MASK                  0x00004000L
#define OV0_SCALE_CNTL__OV0_CRTC_SEL                       0x00004000L
#define OV0_SCALE_CNTL__OV0_PULLDOWN_ON_P1_ONLY_MASK       0x00008000L
#define OV0_SCALE_CNTL__OV0_PULLDOWN_ON_P1_ONLY            0x00008000L
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
#define OV0_VID_BUF0_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_R3_MASK 0x0ffffff0L
#define OV0_VID_BUF0_BASE_ADRS__RESERVED_BIT31_28_MASK     0xf0000000L

// OV0_VID_BUF1_BASE_ADRS
#define OV0_VID_BUF1_BASE_ADRS__OV0_VID_BUF_PITCH_SEL_MASK 0x00000001L
#define OV0_VID_BUF1_BASE_ADRS__OV0_VID_BUF_PITCH_SEL      0x00000001L
#define OV0_VID_BUF1_BASE_ADRS__RESERVED_BIT1_MASK         0x00000002L
#define OV0_VID_BUF1_BASE_ADRS__RESERVED_BIT1              0x00000002L
#define OV0_VID_BUF1_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_R3_MASK 0x0ffffff0L
#define OV0_VID_BUF1_BASE_ADRS__RESERVED_BIT31_28_MASK     0xf0000000L

// OV0_VID_BUF2_BASE_ADRS
#define OV0_VID_BUF2_BASE_ADRS__OV0_VID_BUF_PITCH_SEL_MASK 0x00000001L
#define OV0_VID_BUF2_BASE_ADRS__OV0_VID_BUF_PITCH_SEL      0x00000001L
#define OV0_VID_BUF2_BASE_ADRS__RESERVED_BIT1_MASK         0x00000002L
#define OV0_VID_BUF2_BASE_ADRS__RESERVED_BIT1              0x00000002L
#define OV0_VID_BUF2_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_R3_MASK 0x0ffffff0L
#define OV0_VID_BUF2_BASE_ADRS__RESERVED_BIT31_28_MASK     0xf0000000L

// OV0_VID_BUF3_BASE_ADRS
#define OV0_VID_BUF3_BASE_ADRS__OV0_VID_BUF_PITCH_SEL_MASK 0x00000001L
#define OV0_VID_BUF3_BASE_ADRS__OV0_VID_BUF_PITCH_SEL      0x00000001L
#define OV0_VID_BUF3_BASE_ADRS__RESERVED_BIT1_MASK         0x00000002L
#define OV0_VID_BUF3_BASE_ADRS__RESERVED_BIT1              0x00000002L
#define OV0_VID_BUF3_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_R3_MASK 0x0ffffff0L
#define OV0_VID_BUF3_BASE_ADRS__RESERVED_BIT31_28_MASK     0xf0000000L

// OV0_VID_BUF4_BASE_ADRS
#define OV0_VID_BUF4_BASE_ADRS__OV0_VID_BUF_PITCH_SEL_MASK 0x00000001L
#define OV0_VID_BUF4_BASE_ADRS__OV0_VID_BUF_PITCH_SEL      0x00000001L
#define OV0_VID_BUF4_BASE_ADRS__RESERVED_BIT1_MASK         0x00000002L
#define OV0_VID_BUF4_BASE_ADRS__RESERVED_BIT1              0x00000002L
#define OV0_VID_BUF4_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_R3_MASK 0x0ffffff0L
#define OV0_VID_BUF4_BASE_ADRS__RESERVED_BIT31_28_MASK     0xf0000000L

// OV0_VID_BUF5_BASE_ADRS
#define OV0_VID_BUF5_BASE_ADRS__OV0_VID_BUF_PITCH_SEL_MASK 0x00000001L
#define OV0_VID_BUF5_BASE_ADRS__OV0_VID_BUF_PITCH_SEL      0x00000001L
#define OV0_VID_BUF5_BASE_ADRS__RESERVED_BIT1_MASK         0x00000002L
#define OV0_VID_BUF5_BASE_ADRS__RESERVED_BIT1              0x00000002L
#define OV0_VID_BUF5_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_R3_MASK 0x0ffffff0L
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
#define OV0_DEINTERLACE_PATTERN__OV0_DEINT_PAT_R2_MASK     0x000003ffL
#define OV0_DEINTERLACE_PATTERN__OV0_DEINT_PAT_PNTR_R2_MASK   0x07000000L
#define OV0_DEINTERLACE_PATTERN__OV0_DEINT_PAT_LEN_M1_R2_MASK 0x70000000L

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
#define OV0_TEST__OV0_SUBPIC_ONLY_MASK                     0x00000008L
#define OV0_TEST__OV0_SUBPIC_ONLY                          0x00000008L
#define OV0_TEST__OV0_SWAP_UV_MASK                         0x00000020L
#define OV0_TEST__OV0_SWAP_UV                              0x00000020L
#define OV0_TEST__OV0_NOROUNDUP_MASK                       0x00000040L
#define OV0_TEST__OV0_NOROUNDUP                            0x00000040L
#define OV0_TEST__OV0_4TH_LINE_RULE_EN_MASK                0x00000100L
#define OV0_TEST__OV0_4TH_LINE_RULE_EN                     0x00000100L
#define OV0_TEST__OV0_DEINT_PAT_POST_INC_EN_MASK           0x00000200L
#define OV0_TEST__OV0_DEINT_PAT_POST_INC_EN                0x00000200L
#define OV0_TEST__OV0_READ_BEHIND_SCAN_MARGIN_MASK         0x007f0000L

// OV0_32PULLDOWN_ACCUM
#define OV0_32PULLDOWN_ACCUM__OV0_32PULLDOWN_ACCUM_MASK    0x3fffffffL
#define OV0_32PULLDOWN_ACCUM__OV0_32PULLDOWN_ACCUM_VALID_MASK 0x40000000L
#define OV0_32PULLDOWN_ACCUM__OV0_32PULLDOWN_ACCUM_VALID   0x40000000L
#define OV0_32PULLDOWN_ACCUM__OV0_32PULLDOWN_ACCUM_SKIPPED_MASK 0x80000000L
#define OV0_32PULLDOWN_ACCUM__OV0_32PULLDOWN_ACCUM_SKIPPED 0x80000000L

// OV0_TEMPORAL_DEINT_CNTL
#define OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_EN_MASK           0x00000001L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_EN                0x00000001L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_CLEAR_FIFO_MASK       0x00000002L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_CLEAR_FIFO            0x00000002L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_ACCUM_FORCE_MASK  0x00000004L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_ACCUM_FORCE       0x00000004L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_DEINT_LATEST_SUBMITS_MASK 0x00000008L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_DEINT_LATEST_SUBMITS  0x00000008L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_UNDERFLOW_RECOVERY_MODE_MASK 0x00000030L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_NO_DTO_RESET_ON_OVERFLOW_MASK 0x00000040L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_NO_DTO_RESET_ON_OVERFLOW 0x00000040L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_ACCUM_OVERFLOW_EN_MASK 0x00000080L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_ACCUM_OVERFLOW_EN 0x00000080L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_FORCE_ON_POL_PAIR_MASK 0x00000300L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_LOCK_MASK         0x00000400L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_LOCK              0x00000400L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_HDE_DIVIDE_BY_MASK    0x00003000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_AUTO_DTO_LOOP_EN_MASK 0x00004000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_AUTO_DTO_LOOP_EN      0x00004000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_USE_SOFT_DEINT_ALPHA_MASK 0x00008000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_USE_SOFT_DEINT_ALPHA  0x00008000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_SOFT_DEINT_ALPHA_MASK 0x001f0000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_INVERT_ALPHA_MASK     0x00200000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_INVERT_ALPHA          0x00200000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_SOURCE_CHANGED_MASK   0x00800000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_SOURCE_CHANGED        0x00800000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_FILLED_MASK      0x01000000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_FILLED           0x01000000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_READ_PNTR_MASK   0x0e000000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_ACCUM_LOADED_MASK 0x10000000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_ACCUM_LOADED      0x10000000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_UNDERFLOW_MASK   0x40000000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_UNDERFLOW        0x40000000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_UNDERFLOW_CLR_MASK 0x40000000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_UNDERFLOW_CLR    0x40000000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_OVERFLOW_MASK    0x80000000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_OVERFLOW         0x80000000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_OVERFLOW_CLR_MASK 0x80000000L
#define OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_OVERFLOW_CLR     0x80000000L

// OV0_DTO_ACCUM_0
#define OV0_DTO_ACCUM_0__OV0_DTO_ACCUM_INIT_MASK           0x000fffffL

// OV0_DTO_ACCUM_1
#define OV0_DTO_ACCUM_1__OV0_ACCUM_POL_PAIR_VAL_MASK       0x000fffffL

// OV0_DTO_ACCUM_2
#define OV0_DTO_ACCUM_2__OV0_DTO_ACCUM_MASK                0x000fffffL

// OV0_DTO_INC
#define OV0_DTO_INC__OV0_DTO_INC_MASK                      0x00001fffL
#define OV0_DTO_INC__OV0_DTO_INC_ADJ_MASK                  0x1fff0000L

// OV0_ADAPTIVE_DEINT_OFFSET
#define OV0_ADAPTIVE_DEINT_OFFSET__OV0_BP_OFFSET_MASK      0x00000007L
#define OV0_ADAPTIVE_DEINT_OFFSET__OV0_4TH_LINE_RULE_OFFSET_MASK 0x00000070L

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
#define DISP_MISC_CNTL__SOFT_RESET_TV_R2_MASK              0x00000800L
#define DISP_MISC_CNTL__SOFT_RESET_TV_R2                   0x00000800L
#define DISP_MISC_CNTL__SOFT_RESET_GRPH2_PP_MASK           0x00001000L
#define DISP_MISC_CNTL__SOFT_RESET_GRPH2_PP                0x00001000L
#define DISP_MISC_CNTL__SOFT_RESET_GRPH2_SCLK_MASK         0x00008000L
#define DISP_MISC_CNTL__SOFT_RESET_GRPH2_SCLK              0x00008000L
#define DISP_MISC_CNTL__SOFT_RESET_LVDS_MASK               0x00010000L
#define DISP_MISC_CNTL__SOFT_RESET_LVDS                    0x00010000L
#define DISP_MISC_CNTL__SOFT_RESET_TMDS_MASK               0x00020000L
#define DISP_MISC_CNTL__SOFT_RESET_TMDS                    0x00020000L
#define DISP_MISC_CNTL__SOFT_RESET_DVO_MASK                0x00040000L
#define DISP_MISC_CNTL__SOFT_RESET_DVO                     0x00040000L
#define DISP_MISC_CNTL__SOFT_RESET_HDCP_MASK               0x00080000L
#define DISP_MISC_CNTL__SOFT_RESET_HDCP                    0x00080000L
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
#define DISP_PWR_MAN__DISP_DVO_ENABLE_RST_MASK             0x01000000L
#define DISP_PWR_MAN__DISP_DVO_ENABLE_RST                  0x01000000L
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
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_DAC2_MASK          0x00000400L
#define DISP_TEST_DEBUG_CNTL__DISP_TEST_DAC2               0x00000400L
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
#define DISP_HW_DEBUG__DISP_HW_5_DEBUG_MASK                0x00000020L
#define DISP_HW_DEBUG__DISP_HW_5_DEBUG                     0x00000020L
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
#define DAC_CRC_SIG1__DAC_CRC_SIG_B_MASK_MASK              0x000003ffL
#define DAC_CRC_SIG1__DAC_CRC_SIG_G_MASK                   0x03ff0000L
#define DAC_CRC_SIG1__DAC_CRC_SIG_G_MASK_MASK              0x03ff0000L

// DAC_CRC_SIG2
#define DAC_CRC_SIG2__DAC_CRC_SIG_R_MASK                   0x000003ffL
#define DAC_CRC_SIG2__DAC_CRC_SIG_R_MASK_MASK              0x000003ffL
#define DAC_CRC_SIG2__DAC_CRC_SIG_C_MASK                   0x003f0000L
#define DAC_CRC_SIG2__DAC_CRC_SIG_C_MASK_MASK              0x003f0000L

// OV0_LIN_TRANS_A
#define OV0_LIN_TRANS_A__OV0_LIN_TRANS_Cb_R_MASK           0x0000fffeL
#define OV0_LIN_TRANS_A__OV0_LIN_TRANS_Y_R_MASK            0xfffe0000L

// OV0_LIN_TRANS_B
#define OV0_LIN_TRANS_B__OV0_LIN_TRANS_OFF_R_MASK          0x00001fffL
#define OV0_LIN_TRANS_B__OV0_LIN_TRANS_Cr_R_MASK           0xfffe0000L

// OV0_LIN_TRANS_C
#define OV0_LIN_TRANS_C__OV0_LIN_TRANS_Cb_G_MASK           0x0000fffeL
#define OV0_LIN_TRANS_C__OV0_LIN_TRANS_Y_G_MASK            0xfffe0000L

// OV0_LIN_TRANS_D
#define OV0_LIN_TRANS_D__OV0_LIN_TRANS_OFF_G_MASK          0x00001fffL
#define OV0_LIN_TRANS_D__OV0_LIN_TRANS_Cr_G_MASK           0xfffe0000L

// OV0_LIN_TRANS_E
#define OV0_LIN_TRANS_E__OV0_LIN_TRANS_Cb_B_MASK           0x0000fffeL
#define OV0_LIN_TRANS_E__OV0_LIN_TRANS_Y_B_MASK            0xfffe0000L

// OV0_LIN_TRANS_F
#define OV0_LIN_TRANS_F__OV0_LIN_TRANS_OFF_B_MASK          0x00001fffL
#define OV0_LIN_TRANS_F__OV0_LIN_TRANS_Cr_B_MASK           0xfffe0000L

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
#define OV0_GAMMA_380_3BF__OV0_GAMMA_380_3BF_OFFSET_R2_MASK   0x000007ffL
#define OV0_GAMMA_380_3BF__OV0_GAMMA_380_3BF_SLOPE_MASK    0x01ff0000L

// OV0_GAMMA_3C0_3FF
#define OV0_GAMMA_3C0_3FF__OV0_GAMMA_3C0_3FF_OFFSET_R2_MASK   0x000007ffL
#define OV0_GAMMA_3C0_3FF__OV0_GAMMA_3C0_3FF_SLOPE_MASK    0x01ff0000L

// DAC_CRC2_SIG1
#define DAC_CRC2_SIG1__DAC_CRC2_SIG_B_MASK                 0x000003ffL
#define DAC_CRC2_SIG1__DAC_CRC2_SIG_B_MASK_MASK            0x000003ffL
#define DAC_CRC2_SIG1__DAC_CRC2_SIG_G_MASK                 0x03ff0000L
#define DAC_CRC2_SIG1__DAC_CRC2_SIG_G_MASK_MASK            0x03ff0000L

// DAC_CRC2_SIG2
#define DAC_CRC2_SIG2__DAC_CRC2_SIG_R_MASK                 0x000003ffL
#define DAC_CRC2_SIG2__DAC_CRC2_SIG_R_MASK_MASK            0x000003ffL
#define DAC_CRC2_SIG2__DAC_CRC2_SIG_C_MASK                 0x003f0000L
#define DAC_CRC2_SIG2__DAC_CRC2_SIG_C_MASK_MASK            0x003f0000L

// OV0_GAMMA_80_BF
#define OV0_GAMMA_80_BF__OV0_GAMMA_80_BF_OFFSET_MASK       0x000007ffL
#define OV0_GAMMA_80_BF__OV0_GAMMA_80_BF_SLOPE_MASK        0x01ff0000L

// OV0_GAMMA_C0_FF
#define OV0_GAMMA_C0_FF__OV0_GAMMA_C0_FF_OFFSET_MASK       0x000007ffL
#define OV0_GAMMA_C0_FF__OV0_GAMMA_C0_FF_SLOPE_MASK        0x01ff0000L

// OV0_GAMMA_100_13F
#define OV0_GAMMA_100_13F__OV0_GAMMA_100_13F_OFFSET_MASK   0x000007ffL
#define OV0_GAMMA_100_13F__OV0_GAMMA_100_13F_SLOPE_MASK    0x01ff0000L

// OV0_GAMMA_140_17F
#define OV0_GAMMA_140_17F__OV0_GAMMA_140_17F_OFFSET_MASK   0x000007ffL
#define OV0_GAMMA_140_17F__OV0_GAMMA_140_17F_SLOPE_MASK    0x01ff0000L

// OV0_GAMMA_180_1BF
#define OV0_GAMMA_180_1BF__OV0_GAMMA_180_1BF_OFFSET_MASK   0x000007ffL
#define OV0_GAMMA_180_1BF__OV0_GAMMA_180_1BF_SLOPE_MASK    0x01ff0000L

// OV0_GAMMA_1C0_1FF
#define OV0_GAMMA_1C0_1FF__OV0_GAMMA_1C0_1FF_OFFSET_MASK   0x000007ffL
#define OV0_GAMMA_1C0_1FF__OV0_GAMMA_1C0_1FF_SLOPE_MASK    0x01ff0000L

// OV0_GAMMA_200_23F
#define OV0_GAMMA_200_23F__OV0_GAMMA_200_23F_OFFSET_MASK   0x000007ffL
#define OV0_GAMMA_200_23F__OV0_GAMMA_200_23F_SLOPE_MASK    0x01ff0000L

// OV0_GAMMA_240_27F
#define OV0_GAMMA_240_27F__OV0_GAMMA_240_27F_OFFSET_MASK   0x000007ffL
#define OV0_GAMMA_240_27F__OV0_GAMMA_240_27F_SLOPE_MASK    0x01ff0000L

// OV0_GAMMA_280_2BF
#define OV0_GAMMA_280_2BF__OV0_GAMMA_280_2BF_OFFSET_MASK   0x000007ffL
#define OV0_GAMMA_280_2BF__OV0_GAMMA_280_2BF_SLOPE_MASK    0x01ff0000L

// OV0_GAMMA_2C0_2FF
#define OV0_GAMMA_2C0_2FF__OV0_GAMMA_2C0_2FF_OFFSET_MASK   0x000007ffL
#define OV0_GAMMA_2C0_2FF__OV0_GAMMA_2C0_2FF_SLOPE_MASK    0x01ff0000L

// OV0_GAMMA_300_33F
#define OV0_GAMMA_300_33F__OV0_GAMMA_300_33F_OFFSET_MASK   0x000007ffL
#define OV0_GAMMA_300_33F__OV0_GAMMA_300_33F_SLOPE_MASK    0x01ff0000L

// OV0_GAMMA_340_37F
#define OV0_GAMMA_340_37F__OV0_GAMMA_340_37F_OFFSET_MASK   0x000007ffL
#define OV0_GAMMA_340_37F__OV0_GAMMA_340_37F_SLOPE_MASK    0x01ff0000L

// DISP_MERGE_CNTL
#define DISP_MERGE_CNTL__DISP_ALPHA_MODE_MASK              0x00000003L
#define DISP_MERGE_CNTL__DISP_ALPHA_INV_MASK               0x00000004L
#define DISP_MERGE_CNTL__DISP_ALPHA_INV                    0x00000004L
#define DISP_MERGE_CNTL__DISP_ALPHA_PREMULT_MASK           0x00000008L
#define DISP_MERGE_CNTL__DISP_ALPHA_PREMULT                0x00000008L
#define DISP_MERGE_CNTL__DISP_RGB_OFFSET_EN_MASK           0x00000100L
#define DISP_MERGE_CNTL__DISP_RGB_OFFSET_EN                0x00000100L
#define DISP_MERGE_CNTL__DISP_LIN_TRANS_BYPASS_MASK        0x00000200L
#define DISP_MERGE_CNTL__DISP_LIN_TRANS_BYPASS             0x00000200L
#define DISP_MERGE_CNTL__DISP_GRPH_ALPHA_MASK              0x00ff0000L
#define DISP_MERGE_CNTL__DISP_OV0_ALPHA_MASK               0xff000000L

// DISP_OUTPUT_CNTL
#define DISP_OUTPUT_CNTL__DISP_DAC_SOURCE_MASK             0x00000003L
#define DISP_OUTPUT_CNTL__DISP_TVDAC_SOURCE_MASK           0x0000000cL
#define DISP_OUTPUT_CNTL__DISP_TRANS_MATRIX_SEL_MASK       0x00000030L
#define DISP_OUTPUT_CNTL__DISP_RMX_DITH_EN_MASK            0x00000400L
#define DISP_OUTPUT_CNTL__DISP_RMX_DITH_EN                 0x00000400L
#define DISP_OUTPUT_CNTL__DISP_TRANS_SOURCE_MASK           0x00003000L
#define DISP_OUTPUT_CNTL__DISP_TV_SOURCE_MASK              0x00010000L
#define DISP_OUTPUT_CNTL__DISP_TV_SOURCE                   0x00010000L
#define DISP_OUTPUT_CNTL__DISP_TV_MODE_MASK                0x00060000L
#define DISP_OUTPUT_CNTL__DISP_TV_YG_DITH_EN_MASK          0x00080000L
#define DISP_OUTPUT_CNTL__DISP_TV_YG_DITH_EN               0x00080000L
#define DISP_OUTPUT_CNTL__DISP_TV_CbB_CrR_DITH_EN_MASK     0x00100000L
#define DISP_OUTPUT_CNTL__DISP_TV_CbB_CrR_DITH_EN          0x00100000L
#define DISP_OUTPUT_CNTL__DISP_TV_BIT_WIDTH_MASK           0x00200000L
#define DISP_OUTPUT_CNTL__DISP_TV_BIT_WIDTH                0x00200000L
#define DISP_OUTPUT_CNTL__DISP_TV_SYNC_MODE_MASK           0x00c00000L
#define DISP_OUTPUT_CNTL__DISP_TV_SYNC_FORCE_MASK          0x01000000L
#define DISP_OUTPUT_CNTL__DISP_TV_SYNC_FORCE               0x01000000L
#define DISP_OUTPUT_CNTL__DISP_TV_SYNC_COLOR_MASK          0x06000000L
#define DISP_OUTPUT_CNTL__DISP_TV_EVEN_FLAG_CNTL_MASK      0x18000000L
#define DISP_OUTPUT_CNTL__DISP_TV_SYNC_STATUS_MASK         0x20000000L
#define DISP_OUTPUT_CNTL__DISP_TV_SYNC_STATUS              0x20000000L

// DISP2_MERGE_CNTL
#define DISP2_MERGE_CNTL__DISP2_RGB_OFFSET_EN_MASK         0x00000100L
#define DISP2_MERGE_CNTL__DISP2_RGB_OFFSET_EN              0x00000100L

// DISP_TV_OUT_CNTL
#define DISP_TV_OUT_CNTL__DISP_TV_OUT_YG_FILTER_MASK       0x00000003L
#define DISP_TV_OUT_CNTL__DISP_TV_OUT_YG_SAMPLE_MASK       0x00000004L
#define DISP_TV_OUT_CNTL__DISP_TV_OUT_YG_SAMPLE            0x00000004L
#define DISP_TV_OUT_CNTL__DISP_TV_OUT_CrR_FILTER_MASK      0x00000030L
#define DISP_TV_OUT_CNTL__DISP_TV_OUT_CrR_SAMPLE_MASK      0x00000040L
#define DISP_TV_OUT_CNTL__DISP_TV_OUT_CrR_SAMPLE           0x00000040L
#define DISP_TV_OUT_CNTL__DISP_TV_OUT_CbB_FILTER_MASK      0x00000300L
#define DISP_TV_OUT_CNTL__DISP_TV_OUT_CbB_SAMPLE_MASK      0x00000400L
#define DISP_TV_OUT_CNTL__DISP_TV_OUT_CbB_SAMPLE           0x00000400L
#define DISP_TV_OUT_CNTL__DISP_TV_SUBSAMPLE_CNTL_MASK      0x00003000L
#define DISP_TV_OUT_CNTL__DISP_TV_H_DOWNSCALE_MASK         0x00008000L
#define DISP_TV_OUT_CNTL__DISP_TV_H_DOWNSCALE              0x00008000L
#define DISP_TV_OUT_CNTL__DISP_TV_PATH_SRC_MASK            0x00010000L
#define DISP_TV_OUT_CNTL__DISP_TV_PATH_SRC                 0x00010000L
#define DISP_TV_OUT_CNTL__DISP_TV_COLOR_SPACE_MASK         0x00020000L
#define DISP_TV_OUT_CNTL__DISP_TV_COLOR_SPACE              0x00020000L
#define DISP_TV_OUT_CNTL__DISP_TV_DITH_MODE_MASK           0x00040000L
#define DISP_TV_OUT_CNTL__DISP_TV_DITH_MODE                0x00040000L
#define DISP_TV_OUT_CNTL__DISP_TV_DATA_ZERO_SEL_MASK       0x00080000L
#define DISP_TV_OUT_CNTL__DISP_TV_DATA_ZERO_SEL            0x00080000L
#define DISP_TV_OUT_CNTL__DISP_TV_CLKO_SEL_MASK            0x00100000L
#define DISP_TV_OUT_CNTL__DISP_TV_CLKO_SEL                 0x00100000L
#define DISP_TV_OUT_CNTL__DISP_TV_CLKO_OUT_EN_MASK         0x00200000L
#define DISP_TV_OUT_CNTL__DISP_TV_CLKO_OUT_EN              0x00200000L
#define DISP_TV_OUT_CNTL__DISP_TV_H_DOWNSCALE_SECOND_DISP_MASK 0x00400000L
#define DISP_TV_OUT_CNTL__DISP_TV_H_DOWNSCALE_SECOND_DISP  0x00400000L
#define DISP_TV_OUT_CNTL__DISP_TV_DOWNSCALE_CNTL_MASK      0x03000000L

// DISP_LIN_TRANS_GRPH_A
#define DISP_LIN_TRANS_GRPH_A__DISP_LIN_TRANS_GRPH_C2_MASK 0x00007ff8L
#define DISP_LIN_TRANS_GRPH_A__DISP_LIN_TRANS_GRPH_C1_MASK 0xfff80000L

// DISP_LIN_TRANS_GRPH_B
#define DISP_LIN_TRANS_GRPH_B__DISP_LIN_TRANS_GRPH_C4_MASK 0x00001fffL
#define DISP_LIN_TRANS_GRPH_B__DISP_LIN_TRANS_GRPH_C3_MASK 0x7ff80000L

// DISP_LIN_TRANS_GRPH_C
#define DISP_LIN_TRANS_GRPH_C__DISP_LIN_TRANS_GRPH_C6_MASK 0x0000fff8L
#define DISP_LIN_TRANS_GRPH_C__DISP_LIN_TRANS_GRPH_C5_MASK 0x7ff80000L

// DISP_LIN_TRANS_GRPH_D
#define DISP_LIN_TRANS_GRPH_D__DISP_LIN_TRANS_GRPH_C8_MASK 0x00001fffL
#define DISP_LIN_TRANS_GRPH_D__DISP_LIN_TRANS_GRPH_C7_MASK 0x7ff80000L

// DISP_LIN_TRANS_GRPH_E
#define DISP_LIN_TRANS_GRPH_E__DISP_LIN_TRANS_GRPH_C10_MASK 0x00007ff8L
#define DISP_LIN_TRANS_GRPH_E__DISP_LIN_TRANS_GRPH_C9_MASK 0x7ff80000L

// DISP_LIN_TRANS_GRPH_F
#define DISP_LIN_TRANS_GRPH_F__DISP_LIN_TRANS_GRPH_C12_MASK 0x00001fffL
#define DISP_LIN_TRANS_GRPH_F__DISP_LIN_TRANS_GRPH_C11_MASK 0xfff80000L

// DISP_LIN_TRANS_VID_A
#define DISP_LIN_TRANS_VID_A__DISP_LIN_TRANS_VID_C2_MASK   0x00007ff8L
#define DISP_LIN_TRANS_VID_A__DISP_LIN_TRANS_VID_C1_MASK   0xfff80000L

// DISP_LIN_TRANS_VID_B
#define DISP_LIN_TRANS_VID_B__DISP_LIN_TRANS_VID_C4_MASK   0x00001fffL
#define DISP_LIN_TRANS_VID_B__DISP_LIN_TRANS_VID_C3_MASK   0x7ff80000L

// DISP_LIN_TRANS_VID_C
#define DISP_LIN_TRANS_VID_C__DISP_LIN_TRANS_VID_C6_MASK   0x0000fff8L
#define DISP_LIN_TRANS_VID_C__DISP_LIN_TRANS_VID_C5_MASK   0x7ff80000L

// DISP_LIN_TRANS_VID_D
#define DISP_LIN_TRANS_VID_D__DISP_LIN_TRANS_VID_C8_MASK   0x00001fffL
#define DISP_LIN_TRANS_VID_D__DISP_LIN_TRANS_VID_C7_MASK   0x7ff80000L

// DISP_LIN_TRANS_VID_E
#define DISP_LIN_TRANS_VID_E__DISP_LIN_TRANS_VID_C10_MASK  0x00007ff8L
#define DISP_LIN_TRANS_VID_E__DISP_LIN_TRANS_VID_C9_MASK   0x7ff80000L

// DISP_LIN_TRANS_VID_F
#define DISP_LIN_TRANS_VID_F__DISP_LIN_TRANS_VID_C12_MASK  0x00001fffL
#define DISP_LIN_TRANS_VID_F__DISP_LIN_TRANS_VID_C11_MASK  0xfff80000L

// RMX_HORZ_PHASE
#define RMX_HORZ_PHASE__RMX_HORZ_START_PHASE_MASK          0x00000fffL
#define RMX_HORZ_PHASE__RMX_H_ACC_INIT_MASK                0x00001000L
#define RMX_HORZ_PHASE__RMX_H_ACC_INIT                     0x00001000L
#define RMX_HORZ_PHASE__RMX_V_ACC_INIT_MASK                0x00002000L
#define RMX_HORZ_PHASE__RMX_V_ACC_INIT                     0x00002000L
#define RMX_HORZ_PHASE__RMX_VERT_START_PHASE_MASK          0x0fff0000L
#define RMX_HORZ_PHASE__RMX_VERT_HALF_START_PHASE_EN_MASK  0x10000000L
#define RMX_HORZ_PHASE__RMX_VERT_HALF_START_PHASE_EN       0x10000000L
#define RMX_HORZ_PHASE__RMX_VERT_START_PHASE_OVERFLOW_EN_MASK 0x20000000L
#define RMX_HORZ_PHASE__RMX_VERT_START_PHASE_OVERFLOW_EN   0x20000000L
#define RMX_HORZ_PHASE__RMX_HORZ_HALF_START_PHASE_EN_MASK  0x40000000L
#define RMX_HORZ_PHASE__RMX_HORZ_HALF_START_PHASE_EN       0x40000000L
#define RMX_HORZ_PHASE__RMX_HORZ_START_PHASE_OVERFLOW_EN_MASK 0x80000000L
#define RMX_HORZ_PHASE__RMX_HORZ_START_PHASE_OVERFLOW_EN   0x80000000L

// DAC_EMBEDDED_SYNC_CNTL
#define DAC_EMBEDDED_SYNC_CNTL__DAC_EMBED_SYNC_EN_Y_G_MASK 0x00000001L
#define DAC_EMBEDDED_SYNC_CNTL__DAC_EMBED_SYNC_EN_Y_G      0x00000001L
#define DAC_EMBEDDED_SYNC_CNTL__DAC_EMBED_SYNC_EN_Cb_B_MASK 0x00000002L
#define DAC_EMBEDDED_SYNC_CNTL__DAC_EMBED_SYNC_EN_Cb_B     0x00000002L
#define DAC_EMBEDDED_SYNC_CNTL__DAC_EMBED_SYNC_EN_Cr_R_MASK 0x00000004L
#define DAC_EMBEDDED_SYNC_CNTL__DAC_EMBED_SYNC_EN_Cr_R     0x00000004L
#define DAC_EMBEDDED_SYNC_CNTL__DAC_TRILEVEL_SYNC_EN_MASK  0x00000008L
#define DAC_EMBEDDED_SYNC_CNTL__DAC_TRILEVEL_SYNC_EN       0x00000008L
#define DAC_EMBEDDED_SYNC_CNTL__DAC_EMBED_VSYNC_EN_Y_G_MASK 0x00000010L
#define DAC_EMBEDDED_SYNC_CNTL__DAC_EMBED_VSYNC_EN_Y_G     0x00000010L
#define DAC_EMBEDDED_SYNC_CNTL__DAC_EMBED_VSYNC_EN_CbCr_BR_MASK 0x00000020L
#define DAC_EMBEDDED_SYNC_CNTL__DAC_EMBED_VSYNC_EN_CbCr_BR 0x00000020L
#define DAC_EMBEDDED_SYNC_CNTL__DAC_HSYNC_WID_LSB_MASK     0x00070000L

// DAC_BROAD_PULSE
#define DAC_BROAD_PULSE__DAC_BROAD_PULSE_START_R2_MASK     0x00000fffL
#define DAC_BROAD_PULSE__DAC_BROAD_PULSE_END_R2_MASK       0x0fff0000L

// DAC_INCR
#define DAC_INCR__DAC_INCR_Y_G_MASK                        0x000003ffL
#define DAC_INCR__DAC_INCR_CrCb_RB_MASK                    0x03ff0000L

// DAC_NEG_SYNC_LEVEL
#define DAC_NEG_SYNC_LEVEL__DAC_NEG_SYNC_LEVEL_Y_G_MASK    0x000003ffL
#define DAC_NEG_SYNC_LEVEL__DAC_NEG_SYNC_LEVEL_CrCb_RB_MASK 0x03ff0000L

// DAC_POS_SYNC_LEVEL
#define DAC_POS_SYNC_LEVEL__DAC_POS_SYNC_LEVEL_Y_G_MASK    0x000003ffL
#define DAC_POS_SYNC_LEVEL__DAC_POS_SYNC_LEVEL_CrCb_RB_MASK 0x03ff0000L

// DAC_BLANK_LEVEL
#define DAC_BLANK_LEVEL__DAC_BLANK_LEVEL_Y_G_MASK          0x000003ffL
#define DAC_BLANK_LEVEL__DAC_BLANK_LEVEL_CrCb_RB_MASK      0x03ff0000L

// DAC_SYNC_EQUALIZATION
#define DAC_SYNC_EQUALIZATION__DAC_SYNC_EQ_START_MASK      0x000007ffL
#define DAC_SYNC_EQUALIZATION__DAC_SYNC_EQ_END_MASK        0x07ff0000L

// DAC_MV_CNTL
#define DAC_MV_CNTL__DAC_MV_AGC_PULSE_EN_MASK              0x00000001L
#define DAC_MV_CNTL__DAC_MV_AGC_PULSE_EN                   0x00000001L
#define DAC_MV_CNTL__DAC_MV_BLANK_EN_MASK                  0x00000002L
#define DAC_MV_CNTL__DAC_MV_BLANK_EN                       0x00000002L
#define DAC_MV_CNTL__DAC_MV_BP_PULSE_EN_MASK               0x00000004L
#define DAC_MV_CNTL__DAC_MV_BP_PULSE_EN                    0x00000004L
#define DAC_MV_CNTL__DAC_MV_AGC_PULSE_COUNT_MASK           0x00000f00L
#define DAC_MV_CNTL__DAC_MV_WRITE_EN_MASK                  0x80000000L
#define DAC_MV_CNTL__DAC_MV_WRITE_EN                       0x80000000L

// DAC_MV_AGC_PULSE_LINES
#define DAC_MV_AGC_PULSE_LINES__DAC_MV_AGC_VSTART_MASK     0x000007ffL
#define DAC_MV_AGC_PULSE_LINES__DAC_MV_AGC_VEND_MASK       0x07ff0000L

// DAC_MV_AGC_PULSE_POS
#define DAC_MV_AGC_PULSE_POS__DAC_MV_PSEUDO_START_MASK     0x000003ffL
#define DAC_MV_AGC_PULSE_POS__DAC_MV_PSEUDO_SPACE_MASK     0x03ff0000L

// DAC_MV_AGC_PULSE_WIDTH
#define DAC_MV_AGC_PULSE_WIDTH__DAC_MV_AGC_WIDTH_MASK      0x000003ffL
#define DAC_MV_AGC_PULSE_WIDTH__DAC_MV_PSEUDO_WIDTH_MASK   0x03ff0000L

// DAC_MV_AGC_PULSE_LEVELS
#define DAC_MV_AGC_PULSE_LEVELS__DAC_MV_AGC_LEVEL_MAX_MASK 0x000003ffL
#define DAC_MV_AGC_PULSE_LEVELS__DAC_MV_AGC_LEVEL_INCR_MASK 0x03ff0000L

// DAC_MV_AGC_CYCLE
#define DAC_MV_AGC_CYCLE__DAC_MV_AGC_MAX_FIELDS_MASK       0x000003ffL
#define DAC_MV_AGC_CYCLE__DAC_MV_AGC_MIN_FIELDS_MASK       0x00ff0000L
#define DAC_MV_AGC_CYCLE__DAC_MV_AGC_SKEW_FIELDS_MASK      0xff000000L

// DAC_MV_BLANK_LINES
#define DAC_MV_BLANK_LINES__DAC_MV_BLANK_VSTART_MASK       0x000007ffL
#define DAC_MV_BLANK_LINES__DAC_MV_BLANK_VEND_MASK         0x07ff0000L

// DAC_MV_BLANK_LEVEL
#define DAC_MV_BLANK_LEVEL__DAC_MV_BLANK_LEVEL_MASK        0x000003ffL

// DAC_MV_BP_PULSE_LINES
#define DAC_MV_BP_PULSE_LINES__DAC_MV_BP_PULSE_VSTART_MASK 0x000007ffL
#define DAC_MV_BP_PULSE_LINES__DAC_MV_BP_PULSE_VEND_MASK   0x07ff0000L

// DAC_MV_BP_PULSE
#define DAC_MV_BP_PULSE__DAC_MV_BP_PULSE_NOM_LEVEL_MASK    0x000003ffL
#define DAC_MV_BP_PULSE__DAC_MV_BP_PULSE_MOD_LEVEL_MASK    0x003ff000L
#define DAC_MV_BP_PULSE__DAC_MV_BP_PULSE_WIDTH_MASK        0xff000000L

// DAC_CGMS_LINES
#define DAC_CGMS_LINES__DAC_CGMS_VSTART_MASK               0x000007ffL
#define DAC_CGMS_LINES__DAC_CGMS_VEND_MASK                 0x07ff0000L
#define DAC_CGMS_LINES__DAC_CGMS_RB_EN_MASK                0x40000000L
#define DAC_CGMS_LINES__DAC_CGMS_RB_EN                     0x40000000L
#define DAC_CGMS_LINES__DAC_CGMS_YG_EN_MASK                0x80000000L
#define DAC_CGMS_LINES__DAC_CGMS_YG_EN                     0x80000000L

// DAC_CGMS_TIMING
#define DAC_CGMS_TIMING__DAC_CGMS_WIDTH_MASK               0x000000ffL
#define DAC_CGMS_TIMING__DAC_CGMS_HSTART_MASK              0x0003ff00L
#define DAC_CGMS_TIMING__DAC_CGMS_1_LEVEL_MASK             0x3ff00000L

// DAC_CGMS_DATA
#define DAC_CGMS_DATA__DAC_CGMS_DATA_MASK                  0x00ffffffL
#define DAC_CGMS_DATA__DAC_CGMS_BITS_MASK                  0x1f000000L
#define DAC_CGMS_DATA__DAC_CGMS_DATA_PENDING_MASK          0x80000000L
#define DAC_CGMS_DATA__DAC_CGMS_DATA_PENDING               0x80000000L

// HDCP_CONTROL
#define HDCP_CONTROL__HDCP_UPSTREAM_ADDRESS_MASK           0x000000ffL

// HDCP_DATA
#define HDCP_DATA__HDCP_UPSTREAM_DATA_MASK                 0xffffffffL

// HDCP_DEBUG_R2
#define HDCP_DEBUG_R2__HDCP_DEBUG_EN_MASK                  0x00000001L
#define HDCP_DEBUG_R2__HDCP_DEBUG_EN                       0x00000001L
#define HDCP_DEBUG_R2__I2C_CNTL_REGS_AFFECT_HDCP_I2C_MASK  0x00000002L
#define HDCP_DEBUG_R2__I2C_CNTL_REGS_AFFECT_HDCP_I2C       0x00000002L
#define HDCP_DEBUG_R2__SW_CAN_QUEUE_I2C_GO_MASK            0x00000004L
#define HDCP_DEBUG_R2__SW_CAN_QUEUE_I2C_GO                 0x00000004L
#define HDCP_DEBUG_R2__USE_HDCP_I2C_SHORT_READS_MASK       0x00000008L
#define HDCP_DEBUG_R2__USE_HDCP_I2C_SHORT_READS            0x00000008L
#define HDCP_DEBUG_R2__HDCP_MODE_MASK                      0x00000010L
#define HDCP_DEBUG_R2__HDCP_MODE                           0x00000010L
#define HDCP_DEBUG_R2__HDCP_HOTPLUG_SEL_BYPASS_EN_MASK     0x00000020L
#define HDCP_DEBUG_R2__HDCP_HOTPLUG_SEL_BYPASS_EN          0x00000020L
#define HDCP_DEBUG_R2__HDCP_HOTPLUG_SELECT_MASK            0x00000040L
#define HDCP_DEBUG_R2__HDCP_HOTPLUG_SELECT                 0x00000040L
#define HDCP_DEBUG_R2__HDCP_DEBUG_BIT7_MASK                0x00000080L
#define HDCP_DEBUG_R2__HDCP_DEBUG_BIT7                     0x00000080L
#define HDCP_DEBUG_R2__HDCP_DEBUG_ADDR_MASK                0x0000ff00L
#define HDCP_DEBUG_R2__HDCP_DEBUG_DATA_MASK                0xffff0000L

// CLOCK_CNTL_INDEX
#define CLOCK_CNTL_INDEX__PLL_ADDR_R2_MASK                 0x0000003fL
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
#define PLL_TEST_CNTL__TST_SRC_SEL_R2_MASK                 0x0000007fL
#define PLL_TEST_CNTL__TST_SRC_INV_MASK                    0x00000080L
#define PLL_TEST_CNTL__TST_SRC_INV                         0x00000080L
#define PLL_TEST_CNTL__TST_DIVIDERS_MASK                   0x00000100L
#define PLL_TEST_CNTL__TST_DIVIDERS                        0x00000100L
#define PLL_TEST_CNTL__PLL_MASK_READ_B_MASK                0x00000200L
#define PLL_TEST_CNTL__PLL_MASK_READ_B                     0x00000200L
#define PLL_TEST_CNTL__TESTCLK_MUX_SEL_MASK                0x00001000L
#define PLL_TEST_CNTL__TESTCLK_MUX_SEL                     0x00001000L
#define PLL_TEST_CNTL__ANALOG_MON_R2_MASK                  0x00ff0000L
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
#define DAC_CNTL2__DAC2_CLK_SEL_MASK                       0x00000002L
#define DAC_CNTL2__DAC2_CLK_SEL                            0x00000002L
#define DAC_CNTL2__PALETTE_ACCESS_CNTL_MASK                0x00000020L
#define DAC_CNTL2__PALETTE_ACCESS_CNTL                     0x00000020L
#define DAC_CNTL2__DAC2_CMP_EN_R3_MASK                     0x00000040L
#define DAC_CNTL2__DAC2_CMP_EN_R3                          0x00000040L
#define DAC_CNTL2__DAC2_CMP_OUT_R_R3_MASK                  0x00000080L
#define DAC_CNTL2__DAC2_CMP_OUT_R_R3                       0x00000080L
#define DAC_CNTL2__DAC2_CMP_OUT_G_R3_MASK                  0x00000100L
#define DAC_CNTL2__DAC2_CMP_OUT_G_R3                       0x00000100L
#define DAC_CNTL2__DAC2_CMP_OUT_B_R3_MASK                  0x00000200L
#define DAC_CNTL2__DAC2_CMP_OUT_B_R3                       0x00000200L
#define DAC_CNTL2__DAC2_CMP_OUTPUT_R3_MASK                 0x00000400L
#define DAC_CNTL2__DAC2_CMP_OUTPUT_R3                      0x00000400L
#define DAC_CNTL2__PALETTE_AUTOFILL_PRIMARY_W_MASK         0x00000800L
#define DAC_CNTL2__PALETTE_AUTOFILL_PRIMARY_W              0x00000800L
#define DAC_CNTL2__PALETTE_AUTOFILL_PRIMARY_R_MASK         0x00000800L
#define DAC_CNTL2__PALETTE_AUTOFILL_PRIMARY_R              0x00000800L
#define DAC_CNTL2__PALETTE_AUTOFILL_SECONDARY_W_MASK       0x00001000L
#define DAC_CNTL2__PALETTE_AUTOFILL_SECONDARY_W            0x00001000L
#define DAC_CNTL2__PALETTE_AUTOFILL_SECONDARY_R_MASK       0x00001000L
#define DAC_CNTL2__PALETTE_AUTOFILL_SECONDARY_R            0x00001000L
#define DAC_CNTL2__DAC2_EXPAND_MODE_MASK                   0x00004000L
#define DAC_CNTL2__DAC2_EXPAND_MODE                        0x00004000L
#define DAC_CNTL2__DAC_CRC2_BLANKb_ONLY_MASK               0x00020000L
#define DAC_CNTL2__DAC_CRC2_BLANKb_ONLY                    0x00020000L
#define DAC_CNTL2__DAC_CRC2_CONT_EN_MASK                   0x00040000L
#define DAC_CNTL2__DAC_CRC2_CONT_EN                        0x00040000L
#define DAC_CNTL2__DAC_CRC2_EN_MASK                        0x00080000L
#define DAC_CNTL2__DAC_CRC2_EN                             0x00080000L
#define DAC_CNTL2__DAC_CRC2_FIELD_MASK                     0x00100000L
#define DAC_CNTL2__DAC_CRC2_FIELD                          0x00100000L
#define DAC_CNTL2__DAC2_LUT_COUNTER_LIMIT_MASK             0x00600000L

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

// CP_RESYNC_ADDR
#define CP_RESYNC_ADDR__RESYNC_ADDR_MASK                   0x00000007L

// CP_RESYNC_DATA
#define CP_RESYNC_DATA__RESYNC_DATA_MASK                   0xffffffffL

// CP_CSQ_CNTL
#define CP_CSQ_CNTL__CSQ_MODE_MASK                         0xf0000000L

// CP_CSQ_AVAIL
#define CP_CSQ_AVAIL__CSQ_CNT_PRIMARY_MASK                 0x000003ffL
#define CP_CSQ_AVAIL__CSQ_CNT_INDIRECT_MASK                0x000ffc00L
#define CP_CSQ_AVAIL__CSQ_CNT_INDIRECT2_MASK               0x3ff00000L

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
#define CP_ME_RAM_DATAH__ME_RAM_DATAH_R3_MASK              0x000000ffL

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
#define CP_CSQ2_STAT__CSQ_WPTR_INDIRECT_R3_MASK            0x000003ffL
#define CP_CSQ2_STAT__CSQ_RPTR_INDIRECT2_R3_MASK           0x000ffc00L
#define CP_CSQ2_STAT__CSQ_WPTR_INDIRECT2_R3_MASK           0x3ff00000L

// CP_CSQ_ADDR
#define CP_CSQ_ADDR__CSQ_ADDR_R3_MASK                      0x00000ffcL

// CP_CSQ_DATA
#define CP_CSQ_DATA__CSQ_DATA_MASK                         0xffffffffL

// CP_CSQ_STAT
#define CP_CSQ_STAT__CSQ_RPTR_PRIMARY_R3_MASK              0x000003ffL
#define CP_CSQ_STAT__CSQ_WPTR_PRIMARY_R3_MASK              0x000ffc00L
#define CP_CSQ_STAT__CSQ_RPTR_INDIRECT_R3_MASK             0x3ff00000L

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

// TVOUT_0_SCRATCH
#define TVOUT_0_SCRATCH__TVOUT_0_SCRATCH_MASK              0xffffffffL

// TVOUT_1_SCRATCH
#define TVOUT_1_SCRATCH__TVOUT_1_SCRATCH_MASK              0xffffffffL

// I2C_CNTL_0
#define I2C_CNTL_0__I2C_DONE_MASK                          0x00000001L
#define I2C_CNTL_0__I2C_DONE                               0x00000001L
#define I2C_CNTL_0__I2C_NACK_MASK                          0x00000002L
#define I2C_CNTL_0__I2C_NACK                               0x00000002L
#define I2C_CNTL_0__I2C_HALT_MASK                          0x00000004L
#define I2C_CNTL_0__I2C_HALT                               0x00000004L
#define I2C_CNTL_0__I2C_SOFT_RST_MASK                      0x00000020L
#define I2C_CNTL_0__I2C_SOFT_RST                           0x00000020L
#define I2C_CNTL_0__I2C_DRIVE_EN_MASK                      0x00000040L
#define I2C_CNTL_0__I2C_DRIVE_EN                           0x00000040L
#define I2C_CNTL_0__I2C_DRIVE_SEL_MASK                     0x00000080L
#define I2C_CNTL_0__I2C_DRIVE_SEL                          0x00000080L
#define I2C_CNTL_0__I2C_START_MASK                         0x00000100L
#define I2C_CNTL_0__I2C_START                              0x00000100L
#define I2C_CNTL_0__I2C_STOP_MASK                          0x00000200L
#define I2C_CNTL_0__I2C_STOP                               0x00000200L
#define I2C_CNTL_0__I2C_RECEIVE_MASK                       0x00000400L
#define I2C_CNTL_0__I2C_RECEIVE                            0x00000400L
#define I2C_CNTL_0__I2C_ABORT_MASK                         0x00000800L
#define I2C_CNTL_0__I2C_ABORT                              0x00000800L
#define I2C_CNTL_0__I2C_GO_MASK                            0x00001000L
#define I2C_CNTL_0__I2C_GO                                 0x00001000L
#define I2C_CNTL_0__I2C_PRESCALE_MASK                      0xffff0000L

// I2C_CNTL_1
#define I2C_CNTL_1__I2C_DATA_COUNT_MASK                    0x0000000fL
#define I2C_CNTL_1__I2C_ADDR_COUNT_R2_MASK                 0x00000070L
#define I2C_CNTL_1__I2C_INTRA_BYTE_DELAY_MASK              0x0000ff00L
#define I2C_CNTL_1__I2C_SEL_MASK                           0x00010000L
#define I2C_CNTL_1__I2C_SEL                                0x00010000L
#define I2C_CNTL_1__I2C_EN_MASK                            0x00020000L
#define I2C_CNTL_1__I2C_EN                                 0x00020000L
#define I2C_CNTL_1__I2C_TIME_LIMIT_MASK                    0xff000000L

// I2C_DATA
#define I2C_DATA__I2C_DATA_MASK                            0x000000ffL

// CONFIG_XSTRAP
#define CONFIG_XSTRAP__VGA_DISABLE_MASK                    0x00000001L
#define CONFIG_XSTRAP__VGA_DISABLE                         0x00000001L
#define CONFIG_XSTRAP__MOBILE_DIS_MASK                     0x00000002L
#define CONFIG_XSTRAP__MOBILE_DIS                          0x00000002L
#define CONFIG_XSTRAP__BLANK_ROM_MASK                      0x00000004L
#define CONFIG_XSTRAP__BLANK_ROM                           0x00000004L
#define CONFIG_XSTRAP__ENINTB_MASK                         0x00000008L
#define CONFIG_XSTRAP__ENINTB                              0x00000008L
#define CONFIG_XSTRAP__MULTI_FUNC_MASK                     0x00000030L
#define CONFIG_XSTRAP__AGPSKEW_MASK                        0x000000c0L
#define CONFIG_XSTRAP__X0CLK_SKEW_MASK                     0x00000300L
#define CONFIG_XSTRAP__VIP_DEVICE_MASK                     0x00002000L
#define CONFIG_XSTRAP__VIP_DEVICE                          0x00002000L
#define CONFIG_XSTRAP__EMU_DESKTOP_MASK                    0x00004000L
#define CONFIG_XSTRAP__EMU_DESKTOP                         0x00004000L
#define CONFIG_XSTRAP__EXT_MEM_EN_R3_MASK                  0x00008000L
#define CONFIG_XSTRAP__EXT_MEM_EN_R3                       0x00008000L
#define CONFIG_XSTRAP__AP_SIZE_MASK                        0x00030000L
#define CONFIG_XSTRAP__CHG_ID_MASK                         0x000c0000L
#define CONFIG_XSTRAP__ROMIDCFG_R2_MASK                    0x00f00000L
#define CONFIG_XSTRAP__BUSCFG_MASK                         0x07000000L
#define CONFIG_XSTRAP__WSEN_MASK                           0x08000000L
#define CONFIG_XSTRAP__WSEN                                0x08000000L
#define CONFIG_XSTRAP__WSDEGRADE_MASK                      0x10000000L
#define CONFIG_XSTRAP__WSDEGRADE                           0x10000000L
#define CONFIG_XSTRAP__HDCP_DISABLE_MASK                   0x20000000L
#define CONFIG_XSTRAP__HDCP_DISABLE                        0x20000000L
#define CONFIG_XSTRAP__FAST_WT_DISABLE_MASK                0x40000000L
#define CONFIG_XSTRAP__FAST_WT_DISABLE                     0x40000000L
#define CONFIG_XSTRAP__MV_DISABLE_MASK                     0x80000000L
#define CONFIG_XSTRAP__MV_DISABLE                          0x80000000L

// CONFIG_XSTRAP2_R3
#define CONFIG_XSTRAP2_R3__BM_DAC_EN_MASK                  0x00000001L
#define CONFIG_XSTRAP2_R3__BM_DAC_EN                       0x00000001L
#define CONFIG_XSTRAP2_R3__AGP8X_DETb_MASK                 0x00000002L
#define CONFIG_XSTRAP2_R3__AGP8X_DETb                      0x00000002L
#define CONFIG_XSTRAP2_R3__SLAVE_DAC_DECODE_MASK           0x00000004L
#define CONFIG_XSTRAP2_R3__SLAVE_DAC_DECODE                0x00000004L
#define CONFIG_XSTRAP2_R3__MSI_ENABLE_MASK                 0x00000008L
#define CONFIG_XSTRAP2_R3__MSI_ENABLE                      0x00000008L

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
#define TEST_DEBUG_OUT__TEST_DEBUG_OUTR_MASK               0x00000fffL

// VIDEOMUX_CNTL
#define VIDEOMUX_CNTL__VIPH_INT_SEL_MASK                   0x00000001L
#define VIDEOMUX_CNTL__VIPH_INT_SEL                        0x00000001L
#define VIDEOMUX_CNTL__ROM_CLK_DIVIDE_MASK                 0x001f0000L
#define VIDEOMUX_CNTL__STR_ROMCLK_MASK                     0x00200000L
#define VIDEOMUX_CNTL__STR_ROMCLK                          0x00200000L
#define VIDEOMUX_CNTL__VIP_INTERNAL_DEBUG_SEL_MASK         0x01c00000L

// VIPPAD_STRENGTH
#define VIPPAD_STRENGTH__I2C_STRENGTH_MASK                 0x00000003L
#define VIPPAD_STRENGTH__VIPHDAT_STRENGTH_MASK             0x00030000L
#define VIPPAD_STRENGTH__VIPHCLK_STRENGTH_MASK             0x00300000L

// VIPPAD_MASK
#define VIPPAD_MASK__VIPPAD_MASK_TVODATA_MASK              0x000003ffL
#define VIPPAD_MASK__VIPPAD_MASK_TVOCLKO_MASK              0x00000400L
#define VIPPAD_MASK__VIPPAD_MASK_TVOCLKO                   0x00000400L
#define VIPPAD_MASK__VIPPAD_MASK_ROMCSb_MASK               0x00000800L
#define VIPPAD_MASK__VIPPAD_MASK_ROMCSb                    0x00000800L
#define VIPPAD_MASK__VIPPAD_MASK_VHAD_MASK                 0x00003000L
#define VIPPAD_MASK__VIPPAD_MASK_VPHCTL_MASK               0x00010000L
#define VIPPAD_MASK__VIPPAD_MASK_VPHCTL                    0x00010000L
#define VIPPAD_MASK__VIPPAD_MASK_VIPCLK_MASK               0x00020000L
#define VIPPAD_MASK__VIPPAD_MASK_VIPCLK                    0x00020000L
#define VIPPAD_MASK__VIPPAD_MASK_SI_MASK                   0x00080000L
#define VIPPAD_MASK__VIPPAD_MASK_SI                        0x00080000L
#define VIPPAD_MASK__VIPPAD_MASK_SO_MASK                   0x00100000L
#define VIPPAD_MASK__VIPPAD_MASK_SO                        0x00100000L
#define VIPPAD_MASK__VIPPAD_MASK_SCK_MASK                  0x00200000L
#define VIPPAD_MASK__VIPPAD_MASK_SCK                       0x00200000L

// VIPPAD_A
#define VIPPAD_A__VIPPAD_A_TVODATA_MASK                    0x000003ffL
#define VIPPAD_A__VIPPAD_A_TVOCLKO_MASK                    0x00000400L
#define VIPPAD_A__VIPPAD_A_TVOCLKO                         0x00000400L
#define VIPPAD_A__VIPPAD_A_ROMCSb_MASK                     0x00000800L
#define VIPPAD_A__VIPPAD_A_ROMCSb                          0x00000800L
#define VIPPAD_A__VIPPAD_A_VHAD_MASK                       0x00003000L
#define VIPPAD_A__VIPPAD_A_VPHCTL_MASK                     0x00010000L
#define VIPPAD_A__VIPPAD_A_VPHCTL                          0x00010000L
#define VIPPAD_A__VIPPAD_A_VIPCLK_MASK                     0x00020000L
#define VIPPAD_A__VIPPAD_A_VIPCLK                          0x00020000L
#define VIPPAD_A__VIPPAD_A_SI_MASK                         0x00080000L
#define VIPPAD_A__VIPPAD_A_SI                              0x00080000L
#define VIPPAD_A__VIPPAD_A_SO_MASK                         0x00100000L
#define VIPPAD_A__VIPPAD_A_SO                              0x00100000L
#define VIPPAD_A__VIPPAD_A_SCK_MASK                        0x00200000L
#define VIPPAD_A__VIPPAD_A_SCK                             0x00200000L

// VIPPAD_EN
#define VIPPAD_EN__VIPPAD_EN_TVODATA_MASK                  0x000003ffL
#define VIPPAD_EN__VIPPAD_EN_TVOCLKO_MASK                  0x00000400L
#define VIPPAD_EN__VIPPAD_EN_TVOCLKO                       0x00000400L
#define VIPPAD_EN__VIPPAD_EN_ROMCSb_MASK                   0x00000800L
#define VIPPAD_EN__VIPPAD_EN_ROMCSb                        0x00000800L
#define VIPPAD_EN__VIPPAD_EN_VHAD_MASK                     0x00003000L
#define VIPPAD_EN__VIPPAD_EN_VPHCTL_MASK                   0x00010000L
#define VIPPAD_EN__VIPPAD_EN_VPHCTL                        0x00010000L
#define VIPPAD_EN__VIPPAD_EN_VIPCLK_MASK                   0x00020000L
#define VIPPAD_EN__VIPPAD_EN_VIPCLK                        0x00020000L
#define VIPPAD_EN__VIPPAD_EN_SI_MASK                       0x00080000L
#define VIPPAD_EN__VIPPAD_EN_SI                            0x00080000L
#define VIPPAD_EN__VIPPAD_EN_SO_MASK                       0x00100000L
#define VIPPAD_EN__VIPPAD_EN_SO                            0x00100000L
#define VIPPAD_EN__VIPPAD_EN_SCK_MASK                      0x00200000L
#define VIPPAD_EN__VIPPAD_EN_SCK                           0x00200000L

// VIPPAD_Y
#define VIPPAD_Y__VIPPAD_Y_TVODATA_MASK                    0x000003ffL
#define VIPPAD_Y__VIPPAD_Y_TVOCLKO_MASK                    0x00000400L
#define VIPPAD_Y__VIPPAD_Y_TVOCLKO                         0x00000400L
#define VIPPAD_Y__VIPPAD_Y_ROMCSb_MASK                     0x00000800L
#define VIPPAD_Y__VIPPAD_Y_ROMCSb                          0x00000800L
#define VIPPAD_Y__VIPPAD_Y_VHAD_MASK                       0x00003000L
#define VIPPAD_Y__VIPPAD_Y_VPHCTL_MASK                     0x00010000L
#define VIPPAD_Y__VIPPAD_Y_VPHCTL                          0x00010000L
#define VIPPAD_Y__VIPPAD_Y_VIPCLK_MASK                     0x00020000L
#define VIPPAD_Y__VIPPAD_Y_VIPCLK                          0x00020000L
#define VIPPAD_Y__VIPPAD_Y_SI_MASK                         0x00080000L
#define VIPPAD_Y__VIPPAD_Y_SI                              0x00080000L
#define VIPPAD_Y__VIPPAD_Y_SO_MASK                         0x00100000L
#define VIPPAD_Y__VIPPAD_Y_SO                              0x00100000L
#define VIPPAD_Y__VIPPAD_Y_SCK_MASK                        0x00200000L
#define VIPPAD_Y__VIPPAD_Y_SCK                             0x00200000L

// VIPPAD1_MASK
#define VIPPAD1_MASK__VIPPAD_MASK_VID_MASK                 0x000000ffL
#define VIPPAD1_MASK__VIPPAD_MASK_VPCLK0_MASK              0x00000100L
#define VIPPAD1_MASK__VIPPAD_MASK_VPCLK0                   0x00000100L
#define VIPPAD1_MASK__VIPPAD_MASK_DVALID_MASK              0x00000200L
#define VIPPAD1_MASK__VIPPAD_MASK_DVALID                   0x00000200L
#define VIPPAD1_MASK__VIPPAD_MASK_PSYNC_MASK               0x00000400L
#define VIPPAD1_MASK__VIPPAD_MASK_PSYNC                    0x00000400L
#define VIPPAD1_MASK__GPIO_SYNC_OUTPUT_EN_MASK             0x80000000L
#define VIPPAD1_MASK__GPIO_SYNC_OUTPUT_EN                  0x80000000L

// VIPPAD1_A
#define VIPPAD1_A__VIPPAD_A_VID_MASK                       0x000000ffL
#define VIPPAD1_A__VIPPAD_A_VPCLK0_MASK                    0x00000100L
#define VIPPAD1_A__VIPPAD_A_VPCLK0                         0x00000100L
#define VIPPAD1_A__VIPPAD_A_DVALID_MASK                    0x00000200L
#define VIPPAD1_A__VIPPAD_A_DVALID                         0x00000200L
#define VIPPAD1_A__VIPPAD_A_PSYNC_MASK                     0x00000400L
#define VIPPAD1_A__VIPPAD_A_PSYNC                          0x00000400L
#define VIPPAD1_A__VIPPAD_A_DVODATA_MASK                   0x0fff0000L
#define VIPPAD1_A__VIPPAD_A_DVOCNTL_MASK                   0x70000000L

// VIPPAD1_EN
#define VIPPAD1_EN__VIPPAD_EN_VID_MASK                     0x000000ffL
#define VIPPAD1_EN__VIPPAD_EN_VPCLK0_MASK                  0x00000100L
#define VIPPAD1_EN__VIPPAD_EN_VPCLK0                       0x00000100L
#define VIPPAD1_EN__VIPPAD_EN_DVALID_MASK                  0x00000200L
#define VIPPAD1_EN__VIPPAD_EN_DVALID                       0x00000200L
#define VIPPAD1_EN__VIPPAD_EN_PSYNC_MASK                   0x00000400L
#define VIPPAD1_EN__VIPPAD_EN_PSYNC                        0x00000400L
#define VIPPAD1_EN__VIPPAD_EN_DVODATA_MASK                 0x0fff0000L
#define VIPPAD1_EN__VIPPAD_EN_DVOCNTL_MASK                 0x70000000L

// VIPPAD1_Y
#define VIPPAD1_Y__VIPPAD_Y_VID_MASK                       0x000000ffL
#define VIPPAD1_Y__VIPPAD_Y_VPCLK0_MASK                    0x00000100L
#define VIPPAD1_Y__VIPPAD_Y_VPCLK0                         0x00000100L
#define VIPPAD1_Y__VIPPAD_Y_DVALID_MASK                    0x00000200L
#define VIPPAD1_Y__VIPPAD_Y_DVALID                         0x00000200L
#define VIPPAD1_Y__VIPPAD_Y_PSYNC_MASK                     0x00000400L
#define VIPPAD1_Y__VIPPAD_Y_PSYNC                          0x00000400L
#define VIPPAD1_Y__VIPPAD_Y_DVODATA_MASK                   0x0fff0000L
#define VIPPAD1_Y__VIPPAD_Y_DVOCNTL_MASK                   0x70000000L

// MAXX_PWM
#define MAXX_PWM__PWM_INC_MASK                             0x000000ffL
#define MAXX_PWM__PWM_CLK_DIV_MASK                         0x00000f00L
#define MAXX_PWM__PWM_OUT_EN_MASK                          0x00010000L
#define MAXX_PWM__PWM_OUT_EN                               0x00010000L

// EXTERN_TRIG_CNTL
#define EXTERN_TRIG_CNTL__EXTERN_TRIG_CLR_MASK             0x00000001L
#define EXTERN_TRIG_CNTL__EXTERN_TRIG_CLR                  0x00000001L
#define EXTERN_TRIG_CNTL__EXTERN_TRIG_READ_MASK            0x00000002L
#define EXTERN_TRIG_CNTL__EXTERN_TRIG_READ                 0x00000002L

// ROM_INDEX
#define ROM_INDEX__ROM_INDEX_MASK                          0x0001ffffL

// ROM_DATA
#define ROM_DATA__ROM_DATA_MASK                            0x000000ffL

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
#define SEPROM_CNTL1__SECTOR_ERASE_MASK                    0x00002000L
#define SEPROM_CNTL1__SECTOR_ERASE                         0x00002000L
#define SEPROM_CNTL1__SECTOR_TO_ERASE_MASK                 0x0000c000L
#define SEPROM_CNTL1__BYTE_CNT_MASK                        0x00ff0000L
#define SEPROM_CNTL1__SCK_PRESCALE_MASK                    0xff000000L

// SEPROM_CNTL2
#define SEPROM_CNTL2__WAIT_CYCLE_MASK                      0x000000ffL
#define SEPROM_CNTL2__AUTO_ADDR_SAMPLE_MASK                0x00000100L
#define SEPROM_CNTL2__AUTO_ADDR_SAMPLE                     0x00000100L
#define SEPROM_CNTL2__SEC_COMMAND_MASK                     0x00ff0000L

// VIP_HW_DEBUG
#define VIP_HW_DEBUG__VIP_HW_0_DEBUG_MASK                  0x00000001L
#define VIP_HW_DEBUG__VIP_HW_0_DEBUG                       0x00000001L
#define VIP_HW_DEBUG__VIP_HW_1_DEBUG_MASK                  0x00000002L
#define VIP_HW_DEBUG__VIP_HW_1_DEBUG                       0x00000002L
#define VIP_HW_DEBUG__VIP_HW_2_DEBUG_MASK                  0x00000004L
#define VIP_HW_DEBUG__VIP_HW_2_DEBUG                       0x00000004L
#define VIP_HW_DEBUG__VIP_HW_3_DEBUG_MASK                  0x00000008L
#define VIP_HW_DEBUG__VIP_HW_3_DEBUG                       0x00000008L
#define VIP_HW_DEBUG__VIP_HW_4_DEBUG_MASK                  0x00000010L
#define VIP_HW_DEBUG__VIP_HW_4_DEBUG                       0x00000010L
#define VIP_HW_DEBUG__VIP_HW_5_DEBUG_MASK                  0x00000020L
#define VIP_HW_DEBUG__VIP_HW_5_DEBUG                       0x00000020L
#define VIP_HW_DEBUG__VIP_HW_6_DEBUG_MASK                  0x00000040L
#define VIP_HW_DEBUG__VIP_HW_6_DEBUG                       0x00000040L
#define VIP_HW_DEBUG__VIP_HW_7_DEBUG_MASK                  0x00000080L
#define VIP_HW_DEBUG__VIP_HW_7_DEBUG                       0x00000080L
#define VIP_HW_DEBUG__VIP_HW_8_DEBUG_MASK                  0x00000100L
#define VIP_HW_DEBUG__VIP_HW_8_DEBUG                       0x00000100L
#define VIP_HW_DEBUG__VIP_HW_9_DEBUG_MASK                  0x00000200L
#define VIP_HW_DEBUG__VIP_HW_9_DEBUG                       0x00000200L
#define VIP_HW_DEBUG__VIP_HW_A_DEBUG_MASK                  0x00000400L
#define VIP_HW_DEBUG__VIP_HW_A_DEBUG                       0x00000400L
#define VIP_HW_DEBUG__VIP_HW_B_DEBUG_MASK                  0x00000800L
#define VIP_HW_DEBUG__VIP_HW_B_DEBUG                       0x00000800L
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

// VID_BUFFER_CONTROL
#define VID_BUFFER_CONTROL__CAP0_BUFFER_WATER_MARK_R2_MASK 0x0000003fL
#define VID_BUFFER_CONTROL__FULL_BUFFER_EN_MASK            0x00010000L
#define VID_BUFFER_CONTROL__FULL_BUFFER_EN                 0x00010000L
#define VID_BUFFER_CONTROL__CAP0_ANC_VBI_QUAD_BUF_MASK     0x00020000L
#define VID_BUFFER_CONTROL__CAP0_ANC_VBI_QUAD_BUF          0x00020000L
#define VID_BUFFER_CONTROL__VID_BUFFER_RESET_MASK          0x00100000L
#define VID_BUFFER_CONTROL__VID_BUFFER_RESET               0x00100000L
#define VID_BUFFER_CONTROL__CAP_SWAP_MASK                  0x00600000L
#define VID_BUFFER_CONTROL__CAP0_BUFFER_EMPTY_MASK         0x01000000L
#define VID_BUFFER_CONTROL__CAP0_BUFFER_EMPTY              0x01000000L

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
#define CAP_INT_CNTL__CAP0_ANC0_INT_EN_MASK                0x00000080L
#define CAP_INT_CNTL__CAP0_ANC0_INT_EN                     0x00000080L
#define CAP_INT_CNTL__CAP0_ANC1_INT_EN_MASK                0x00000100L
#define CAP_INT_CNTL__CAP0_ANC1_INT_EN                     0x00000100L
#define CAP_INT_CNTL__CAP0_VBI2_INT_EN_MASK                0x00000200L
#define CAP_INT_CNTL__CAP0_VBI2_INT_EN                     0x00000200L
#define CAP_INT_CNTL__CAP0_VBI3_INT_EN_MASK                0x00000400L
#define CAP_INT_CNTL__CAP0_VBI3_INT_EN                     0x00000400L
#define CAP_INT_CNTL__CAP0_ANC2_INT_EN_MASK                0x00000800L
#define CAP_INT_CNTL__CAP0_ANC2_INT_EN                     0x00000800L
#define CAP_INT_CNTL__CAP0_ANC3_INT_EN_MASK                0x00001000L
#define CAP_INT_CNTL__CAP0_ANC3_INT_EN                     0x00001000L

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
#define CAP_INT_STATUS__CAP0_ANC0_INT_MASK                 0x00000080L
#define CAP_INT_STATUS__CAP0_ANC0_INT                      0x00000080L
#define CAP_INT_STATUS__CAP0_ANC0_INT_AK_MASK              0x00000080L
#define CAP_INT_STATUS__CAP0_ANC0_INT_AK                   0x00000080L
#define CAP_INT_STATUS__CAP0_ANC1_INT_MASK                 0x00000100L
#define CAP_INT_STATUS__CAP0_ANC1_INT                      0x00000100L
#define CAP_INT_STATUS__CAP0_ANC1_INT_AK_MASK              0x00000100L
#define CAP_INT_STATUS__CAP0_ANC1_INT_AK                   0x00000100L
#define CAP_INT_STATUS__CAP0_VBI2_INT_MASK                 0x00000200L
#define CAP_INT_STATUS__CAP0_VBI2_INT                      0x00000200L
#define CAP_INT_STATUS__CAP0_VBI2_INT_AK_MASK              0x00000200L
#define CAP_INT_STATUS__CAP0_VBI2_INT_AK                   0x00000200L
#define CAP_INT_STATUS__CAP0_VBI3_INT_MASK                 0x00000400L
#define CAP_INT_STATUS__CAP0_VBI3_INT                      0x00000400L
#define CAP_INT_STATUS__CAP0_VBI3_INT_AK_MASK              0x00000400L
#define CAP_INT_STATUS__CAP0_VBI3_INT_AK                   0x00000400L
#define CAP_INT_STATUS__CAP0_ANC2_INT_MASK                 0x00000800L
#define CAP_INT_STATUS__CAP0_ANC2_INT                      0x00000800L
#define CAP_INT_STATUS__CAP0_ANC2_INT_AK_MASK              0x00000800L
#define CAP_INT_STATUS__CAP0_ANC2_INT_AK                   0x00000800L
#define CAP_INT_STATUS__CAP0_ANC3_INT_MASK                 0x00001000L
#define CAP_INT_STATUS__CAP0_ANC3_INT                      0x00001000L
#define CAP_INT_STATUS__CAP0_ANC3_INT_AK_MASK              0x00001000L
#define CAP_INT_STATUS__CAP0_ANC3_INT_AK                   0x00001000L

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
#define CAP0_CONFIG__CAP_ANC_DECODE_EN_MASK                0x00001000L
#define CAP0_CONFIG__CAP_ANC_DECODE_EN                     0x00001000L
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
#define CAP0_CONFIG__CAP_IMAGE_FLIP_EN_MASK                0x08000000L
#define CAP0_CONFIG__CAP_IMAGE_FLIP_EN                     0x08000000L
#define CAP0_CONFIG__CAP_ONESHOT_IMAGE_FLIP_EN_MASK        0x10000000L
#define CAP0_CONFIG__CAP_ONESHOT_IMAGE_FLIP_EN             0x10000000L
#define CAP0_CONFIG__CAP_VIDEO_IN_FORMAT_MASK              0x20000000L
#define CAP0_CONFIG__CAP_VIDEO_IN_FORMAT                   0x20000000L
#define CAP0_CONFIG__VBI_HORZ_DOWN_MASK                    0xc0000000L

// CAP0_ANC0_OFFSET
#define CAP0_ANC0_OFFSET__CAP_ANC0_OFFSET_MASK             0xffffffffL

// CAP0_ANC1_OFFSET
#define CAP0_ANC1_OFFSET__CAP_ANC1_OFFSET_MASK             0xffffffffL

// CAP0_ANC_H_WINDOW
#define CAP0_ANC_H_WINDOW__CAP_ANC_WIDTH_MASK              0x00000fffL

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
#define CAP0_BUF_STATUS__CAP_PRE_ANC_BUF_MASK              0x00001800L
#define CAP0_BUF_STATUS__CAP_CUR_ANC_BUF_MASK              0x00006000L
#define CAP0_BUF_STATUS__CAP_ANC_BUF_STATUS_MASK           0x00008000L
#define CAP0_BUF_STATUS__CAP_ANC_BUF_STATUS                0x00008000L
#define CAP0_BUF_STATUS__CAP_ANC_PRE_BUF_CNT_MASK          0x0fff0000L
#define CAP0_BUF_STATUS__CAP_VIP_INC_MASK                  0x10000000L
#define CAP0_BUF_STATUS__CAP_VIP_INC                       0x10000000L
#define CAP0_BUF_STATUS__CAP_VIP_PRE_REPEAT_FIELD_MASK     0x20000000L
#define CAP0_BUF_STATUS__CAP_VIP_PRE_REPEAT_FIELD          0x20000000L
#define CAP0_BUF_STATUS__CAP_CAP_BUF_STATUS_MASK           0x40000000L
#define CAP0_BUF_STATUS__CAP_CAP_BUF_STATUS                0x40000000L

// CAP0_ANC_BUF01_BLOCK_CNT
#define CAP0_ANC_BUF01_BLOCK_CNT__CAP0_ANC_BUF0_BLOCK_CNT_MASK 0x00000fffL
#define CAP0_ANC_BUF01_BLOCK_CNT__CAP0_ANC_BUF1_BLOCK_CNT_MASK 0x0fff0000L

// CAP0_ANC_BUF23_BLOCK_CNT
#define CAP0_ANC_BUF23_BLOCK_CNT__CAP0_ANC_BUF2_BLOCK_CNT_MASK 0x00000fffL
#define CAP0_ANC_BUF23_BLOCK_CNT__CAP0_ANC_BUF3_BLOCK_CNT_MASK 0x0fff0000L

// CAP0_VBI2_OFFSET
#define CAP0_VBI2_OFFSET__CAP_VBI2_OFFSET_MASK             0xffffffffL

// CAP0_VBI3_OFFSET
#define CAP0_VBI3_OFFSET__CAP_VBI3_OFFSET_MASK             0xffffffffL

// CAP0_ANC2_OFFSET
#define CAP0_ANC2_OFFSET__CAP_ANC2_OFFSET_MASK             0xffffffffL

// CAP0_ANC3_OFFSET
#define CAP0_ANC3_OFFSET__CAP_ANC3_OFFSET_MASK             0xffffffffL

// DMA_VIPH0_COMMAND
#define DMA_VIPH0_COMMAND__BYTE_COUNT_MASK                 0x001fffffL
#define DMA_VIPH0_COMMAND__SWAP_CONTROL_MASK               0x03000000L
#define DMA_VIPH0_COMMAND__TRANSFER_SOURCE_MASK            0x04000000L
#define DMA_VIPH0_COMMAND__TRANSFER_SOURCE                 0x04000000L
#define DMA_VIPH0_COMMAND__TRANSFER_DEST_MASK              0x08000000L
#define DMA_VIPH0_COMMAND__TRANSFER_DEST                   0x08000000L
#define DMA_VIPH0_COMMAND__SOURCE_OFFSET_HOLD_MASK         0x10000000L
#define DMA_VIPH0_COMMAND__SOURCE_OFFSET_HOLD              0x10000000L
#define DMA_VIPH0_COMMAND__DEST_OFFSET_HOLD_MASK           0x20000000L
#define DMA_VIPH0_COMMAND__DEST_OFFSET_HOLD                0x20000000L
#define DMA_VIPH0_COMMAND__INTERRUPT_DIS_MASK              0x40000000L
#define DMA_VIPH0_COMMAND__INTERRUPT_DIS                   0x40000000L
#define DMA_VIPH0_COMMAND__END_OF_LIST_STATUS_MASK         0x80000000L
#define DMA_VIPH0_COMMAND__END_OF_LIST_STATUS              0x80000000L

// DMA_VIPH1_COMMAND
#define DMA_VIPH1_COMMAND__BYTE_COUNT_MASK                 0x001fffffL
#define DMA_VIPH1_COMMAND__SWAP_CONTROL_MASK               0x03000000L
#define DMA_VIPH1_COMMAND__TRANSFER_SOURCE_MASK            0x04000000L
#define DMA_VIPH1_COMMAND__TRANSFER_SOURCE                 0x04000000L
#define DMA_VIPH1_COMMAND__TRANSFER_DEST_MASK              0x08000000L
#define DMA_VIPH1_COMMAND__TRANSFER_DEST                   0x08000000L
#define DMA_VIPH1_COMMAND__SOURCE_OFFSET_HOLD_MASK         0x10000000L
#define DMA_VIPH1_COMMAND__SOURCE_OFFSET_HOLD              0x10000000L
#define DMA_VIPH1_COMMAND__DEST_OFFSET_HOLD_MASK           0x20000000L
#define DMA_VIPH1_COMMAND__DEST_OFFSET_HOLD                0x20000000L
#define DMA_VIPH1_COMMAND__INTERRUPT_DIS_MASK              0x40000000L
#define DMA_VIPH1_COMMAND__INTERRUPT_DIS                   0x40000000L
#define DMA_VIPH1_COMMAND__END_OF_LIST_STATUS_MASK         0x80000000L
#define DMA_VIPH1_COMMAND__END_OF_LIST_STATUS              0x80000000L

// DMA_VIPH2_COMMAND
#define DMA_VIPH2_COMMAND__BYTE_COUNT_MASK                 0x001fffffL
#define DMA_VIPH2_COMMAND__SWAP_CONTROL_MASK               0x03000000L
#define DMA_VIPH2_COMMAND__TRANSFER_SOURCE_MASK            0x04000000L
#define DMA_VIPH2_COMMAND__TRANSFER_SOURCE                 0x04000000L
#define DMA_VIPH2_COMMAND__TRANSFER_DEST_MASK              0x08000000L
#define DMA_VIPH2_COMMAND__TRANSFER_DEST                   0x08000000L
#define DMA_VIPH2_COMMAND__SOURCE_OFFSET_HOLD_MASK         0x10000000L
#define DMA_VIPH2_COMMAND__SOURCE_OFFSET_HOLD              0x10000000L
#define DMA_VIPH2_COMMAND__DEST_OFFSET_HOLD_MASK           0x20000000L
#define DMA_VIPH2_COMMAND__DEST_OFFSET_HOLD                0x20000000L
#define DMA_VIPH2_COMMAND__INTERRUPT_DIS_MASK              0x40000000L
#define DMA_VIPH2_COMMAND__INTERRUPT_DIS                   0x40000000L
#define DMA_VIPH2_COMMAND__END_OF_LIST_STATUS_MASK         0x80000000L
#define DMA_VIPH2_COMMAND__END_OF_LIST_STATUS              0x80000000L

// DMA_VIPH3_COMMAND
#define DMA_VIPH3_COMMAND__BYTE_COUNT_MASK                 0x001fffffL
#define DMA_VIPH3_COMMAND__SWAP_CONTROL_MASK               0x03000000L
#define DMA_VIPH3_COMMAND__TRANSFER_SOURCE_MASK            0x04000000L
#define DMA_VIPH3_COMMAND__TRANSFER_SOURCE                 0x04000000L
#define DMA_VIPH3_COMMAND__TRANSFER_DEST_MASK              0x08000000L
#define DMA_VIPH3_COMMAND__TRANSFER_DEST                   0x08000000L
#define DMA_VIPH3_COMMAND__SOURCE_OFFSET_HOLD_MASK         0x10000000L
#define DMA_VIPH3_COMMAND__SOURCE_OFFSET_HOLD              0x10000000L
#define DMA_VIPH3_COMMAND__DEST_OFFSET_HOLD_MASK           0x20000000L
#define DMA_VIPH3_COMMAND__DEST_OFFSET_HOLD                0x20000000L
#define DMA_VIPH3_COMMAND__INTERRUPT_DIS_MASK              0x40000000L
#define DMA_VIPH3_COMMAND__INTERRUPT_DIS                   0x40000000L
#define DMA_VIPH3_COMMAND__END_OF_LIST_STATUS_MASK         0x80000000L
#define DMA_VIPH3_COMMAND__END_OF_LIST_STATUS              0x80000000L

// DMA_VIPH_STATUS
#define DMA_VIPH_STATUS__DMA_VIPH0_AVAIL_MASK              0x0000000fL
#define DMA_VIPH_STATUS__DMA_VIPH1_AVAIL_MASK              0x000000f0L
#define DMA_VIPH_STATUS__DMA_VIPH2_AVAIL_MASK              0x00000f00L
#define DMA_VIPH_STATUS__DMA_VIPH3_AVAIL_MASK              0x0000f000L
#define DMA_VIPH_STATUS__DMA_VIPH0_CURRENT_MASK            0x00030000L
#define DMA_VIPH_STATUS__DMA_VIPH1_CURRENT_MASK            0x000c0000L
#define DMA_VIPH_STATUS__DMA_VIPH2_CURRENT_MASK            0x00300000L
#define DMA_VIPH_STATUS__DMA_VIPH3_CURRENT_MASK            0x00c00000L
#define DMA_VIPH_STATUS__DMA_VIPH0_ACTIVE_MASK             0x01000000L
#define DMA_VIPH_STATUS__DMA_VIPH0_ACTIVE                  0x01000000L
#define DMA_VIPH_STATUS__DMA_VIPH1_ACTIVE_MASK             0x02000000L
#define DMA_VIPH_STATUS__DMA_VIPH1_ACTIVE                  0x02000000L
#define DMA_VIPH_STATUS__DMA_VIPH2_ACTIVE_MASK             0x04000000L
#define DMA_VIPH_STATUS__DMA_VIPH2_ACTIVE                  0x04000000L
#define DMA_VIPH_STATUS__DMA_VIPH3_ACTIVE_MASK             0x08000000L
#define DMA_VIPH_STATUS__DMA_VIPH3_ACTIVE                  0x08000000L

// DMA_VIPH_MISC_CNTL
#define DMA_VIPH_MISC_CNTL__DMA_VIPH_READ_TIMER_MASK       0x0000000fL
#define DMA_VIPH_MISC_CNTL__DMA_VIPH_READ_TIMEOUT_TO_PIORITY_EN_MASK 0x00000080L
#define DMA_VIPH_MISC_CNTL__DMA_VIPH_READ_TIMEOUT_TO_PIORITY_EN 0x00000080L
#define DMA_VIPH_MISC_CNTL__DMA_VIPH_READ_TIMEOUT_STATUS_MASK 0x00000100L
#define DMA_VIPH_MISC_CNTL__DMA_VIPH_READ_TIMEOUT_STATUS   0x00000100L

// DMA_VIPH_CHUNK_0
#define DMA_VIPH_CHUNK_0__DMA_VIPH3_TABLE_SWAP_MASK        0x00000003L
#define DMA_VIPH_CHUNK_0__DMA_VIPH2_TABLE_SWAP_MASK        0x0000000cL
#define DMA_VIPH_CHUNK_0__DMA_VIPH1_TABLE_SWAP_MASK        0x00000030L
#define DMA_VIPH_CHUNK_0__DMA_VIPH0_TABLE_SWAP_MASK        0x000000c0L
#define DMA_VIPH_CHUNK_0__DMA_VIPH3_NOCHUNK_MASK           0x10000000L
#define DMA_VIPH_CHUNK_0__DMA_VIPH3_NOCHUNK                0x10000000L
#define DMA_VIPH_CHUNK_0__DMA_VIPH2_NOCHUNK_MASK           0x20000000L
#define DMA_VIPH_CHUNK_0__DMA_VIPH2_NOCHUNK                0x20000000L
#define DMA_VIPH_CHUNK_0__DMA_VIPH1_NOCHUNK_MASK           0x40000000L
#define DMA_VIPH_CHUNK_0__DMA_VIPH1_NOCHUNK                0x40000000L
#define DMA_VIPH_CHUNK_0__DMA_VIPH0_NOCHUNK_MASK           0x80000000L
#define DMA_VIPH_CHUNK_0__DMA_VIPH0_NOCHUNK                0x80000000L

// DMA_VIPH_CHUNK_1_VAL
#define DMA_VIPH_CHUNK_1_VAL__DMA_VIP0_CHUNK_MASK          0x000000ffL
#define DMA_VIPH_CHUNK_1_VAL__DMA_VIP1_CHUNK_MASK          0x0000ff00L
#define DMA_VIPH_CHUNK_1_VAL__DMA_VIP2_CHUNK_MASK          0x00ff0000L
#define DMA_VIPH_CHUNK_1_VAL__DMA_VIP3_CHUNK_MASK          0xff000000L

// DMA_VIP0_TABLE_ADDR
#define DMA_VIP0_TABLE_ADDR__DMA_VIPH_TABLE_ADDR_MASK      0xffffffffL

// DMA_VIP1_TABLE_ADDR
#define DMA_VIP1_TABLE_ADDR__DMA_VIPH_TABLE_ADDR_MASK      0xffffffffL

// DMA_VIP2_TABLE_ADDR
#define DMA_VIP2_TABLE_ADDR__DMA_VIPH_TABLE_ADDR_MASK      0xffffffffL

// DMA_VIP3_TABLE_ADDR
#define DMA_VIP3_TABLE_ADDR__DMA_VIPH_TABLE_ADDR_MASK      0xffffffffL

// DMA_VIPH0_ACTIVE
#define DMA_VIPH0_ACTIVE__DMA_VIPH_TABLE_ADDR_ACT_MASK     0xffffffffL

// DMA_VIPH1_ACTIVE
#define DMA_VIPH1_ACTIVE__DMA_VIPH_TABLE_ADDR_ACT_MASK     0xffffffffL

// DMA_VIPH2_ACTIVE
#define DMA_VIPH2_ACTIVE__DMA_VIPH_TABLE_ADDR_ACT_MASK     0xffffffffL

// DMA_VIPH3_ACTIVE
#define DMA_VIPH3_ACTIVE__DMA_VIPH_TABLE_ADDR_ACT_MASK     0xffffffffL

// DMA_VIPH_ABORT
#define DMA_VIPH_ABORT__DMA_VIPH0_ABORT_EN_MASK            0x00000008L
#define DMA_VIPH_ABORT__DMA_VIPH0_ABORT_EN                 0x00000008L
#define DMA_VIPH_ABORT__DMA_VIPH1_ABORT_EN_MASK            0x00000080L
#define DMA_VIPH_ABORT__DMA_VIPH1_ABORT_EN                 0x00000080L
#define DMA_VIPH_ABORT__DMA_VIPH2_ABORT_EN_MASK            0x00000800L
#define DMA_VIPH_ABORT__DMA_VIPH2_ABORT_EN                 0x00000800L
#define DMA_VIPH_ABORT__DMA_VIPH3_ABORT_EN_MASK            0x00008000L
#define DMA_VIPH_ABORT__DMA_VIPH3_ABORT_EN                 0x00008000L
#define DMA_VIPH_ABORT__DMA_VIPH0_RESET_MASK               0x00100000L
#define DMA_VIPH_ABORT__DMA_VIPH0_RESET                    0x00100000L
#define DMA_VIPH_ABORT__DMA_VIPH1_RESET_MASK               0x00200000L
#define DMA_VIPH_ABORT__DMA_VIPH1_RESET                    0x00200000L
#define DMA_VIPH_ABORT__DMA_VIPH2_RESET_MASK               0x00400000L
#define DMA_VIPH_ABORT__DMA_VIPH2_RESET                    0x00400000L
#define DMA_VIPH_ABORT__DMA_VIPH3_RESET_MASK               0x00800000L
#define DMA_VIPH_ABORT__DMA_VIPH3_RESET                    0x00800000L

// VIPH_REG_ADDR
#define VIPH_REG_ADDR__VIPH_REG_AD_MASK                    0x0000ffffL

// VIPH_REG_DATA
#define VIPH_REG_DATA__VIPH_REG_DT_R_MASK                  0xffffffffL
#define VIPH_REG_DATA__VIPH_REG_DT_W_MASK                  0xffffffffL

// VIPH_CH0_DATA
#define VIPH_CH0_DATA__VIPH_CH0_DT_MASK                    0xffffffffL

// VIPH_CH1_DATA
#define VIPH_CH1_DATA__VIPH_CH1_DT_MASK                    0xffffffffL

// VIPH_CH2_DATA
#define VIPH_CH2_DATA__VIPH_CH2_DT_MASK                    0xffffffffL

// VIPH_CH3_DATA
#define VIPH_CH3_DATA__VIPH_CH3_DT_MASK                    0xffffffffL

// VIPH_CH0_ADDR
#define VIPH_CH0_ADDR__VIPH_CH0_AD_MASK                    0x000000ffL

// VIPH_CH1_ADDR
#define VIPH_CH1_ADDR__VIPH_CH1_AD_MASK                    0x000000ffL

// VIPH_CH2_ADDR
#define VIPH_CH2_ADDR__VIPH_CH2_AD_MASK                    0x000000ffL

// VIPH_CH3_ADDR
#define VIPH_CH3_ADDR__VIPH_CH3_AD_MASK                    0x000000ffL

// VIPH_CH0_SBCNT
#define VIPH_CH0_SBCNT__VIPH_CH0_SCNT_MASK                 0x000fffffL

// VIPH_CH1_SBCNT
#define VIPH_CH1_SBCNT__VIPH_CH1_SCNT_MASK                 0x000fffffL

// VIPH_CH2_SBCNT
#define VIPH_CH2_SBCNT__VIPH_CH2_SCNT_MASK                 0x000fffffL

// VIPH_CH3_SBCNT
#define VIPH_CH3_SBCNT__VIPH_CH3_SCNT_MASK                 0x000fffffL

// VIPH_CH0_ABCNT
#define VIPH_CH0_ABCNT__VIPH_CH0_ACNT_MASK                 0x000fffffL

// VIPH_CH1_ABCNT
#define VIPH_CH1_ABCNT__VIPH_CH1_ACNT_MASK                 0x000fffffL

// VIPH_CH2_ABCNT
#define VIPH_CH2_ABCNT__VIPH_CH2_ACNT_MASK                 0x000fffffL

// VIPH_CH3_ABCNT
#define VIPH_CH3_ABCNT__VIPH_CH3_ACNT_MASK                 0x000fffffL

// VIPH_CONTROL
#define VIPH_CONTROL__VIPH_CLK_SEL_MASK                    0x000000ffL
#define VIPH_CONTROL__VIPH_REG_RDY_MASK                    0x00002000L
#define VIPH_CONTROL__VIPH_REG_RDY                         0x00002000L
#define VIPH_CONTROL__VIPH_MAX_WAIT_MASK                   0x000f0000L
#define VIPH_CONTROL__VIPH_DMA_MODE_MASK                   0x00100000L
#define VIPH_CONTROL__VIPH_DMA_MODE                        0x00100000L
#define VIPH_CONTROL__VIPH_EN_MASK                         0x00200000L
#define VIPH_CONTROL__VIPH_EN                              0x00200000L
#define VIPH_CONTROL__VIPH_DV0_WID_MASK                    0x01000000L
#define VIPH_CONTROL__VIPH_DV0_WID                         0x01000000L
#define VIPH_CONTROL__VIPH_DV1_WID_MASK                    0x02000000L
#define VIPH_CONTROL__VIPH_DV1_WID                         0x02000000L
#define VIPH_CONTROL__VIPH_DV2_WID_MASK                    0x04000000L
#define VIPH_CONTROL__VIPH_DV2_WID                         0x04000000L
#define VIPH_CONTROL__VIPH_DV3_WID_MASK                    0x08000000L
#define VIPH_CONTROL__VIPH_DV3_WID                         0x08000000L
#define VIPH_CONTROL__VIPH_PWR_DOWN_MASK                   0x10000000L
#define VIPH_CONTROL__VIPH_PWR_DOWN                        0x10000000L
#define VIPH_CONTROL__VIPH_PWR_DOWN_AK_MASK                0x10000000L
#define VIPH_CONTROL__VIPH_PWR_DOWN_AK                     0x10000000L
#define VIPH_CONTROL__VIPH_VIPCLK_DIS_MASK                 0x20000000L
#define VIPH_CONTROL__VIPH_VIPCLK_DIS                      0x20000000L

// VIPH_DV_LAT
#define VIPH_DV_LAT__VIPH_TIME_UNIT_MASK                   0x00000fffL
#define VIPH_DV_LAT__VIPH_DV0_LAT_MASK                     0x000f0000L
#define VIPH_DV_LAT__VIPH_DV1_LAT_MASK                     0x00f00000L
#define VIPH_DV_LAT__VIPH_DV2_LAT_MASK                     0x0f000000L
#define VIPH_DV_LAT__VIPH_DV3_LAT_MASK                     0xf0000000L

// VIPH_DMA_CHUNK
#define VIPH_DMA_CHUNK__VIPH_CH0_CHUNK_MASK                0x0000000fL
#define VIPH_DMA_CHUNK__VIPH_CH1_CHUNK_MASK                0x00000030L
#define VIPH_DMA_CHUNK__VIPH_CH2_CHUNK_MASK                0x000000c0L
#define VIPH_DMA_CHUNK__VIPH_CH3_CHUNK_MASK                0x00000300L
#define VIPH_DMA_CHUNK__VIPH_CH0_ABORT_MASK                0x00010000L
#define VIPH_DMA_CHUNK__VIPH_CH0_ABORT                     0x00010000L
#define VIPH_DMA_CHUNK__VIPH_CH1_ABORT_MASK                0x00020000L
#define VIPH_DMA_CHUNK__VIPH_CH1_ABORT                     0x00020000L
#define VIPH_DMA_CHUNK__VIPH_CH2_ABORT_MASK                0x00040000L
#define VIPH_DMA_CHUNK__VIPH_CH2_ABORT                     0x00040000L
#define VIPH_DMA_CHUNK__VIPH_CH3_ABORT_MASK                0x00080000L
#define VIPH_DMA_CHUNK__VIPH_CH3_ABORT                     0x00080000L

// VIPH_DV_INT
#define VIPH_DV_INT__VIPH_DV0_INT_EN_MASK                  0x00000001L
#define VIPH_DV_INT__VIPH_DV0_INT_EN                       0x00000001L
#define VIPH_DV_INT__VIPH_DV1_INT_EN_MASK                  0x00000002L
#define VIPH_DV_INT__VIPH_DV1_INT_EN                       0x00000002L
#define VIPH_DV_INT__VIPH_DV2_INT_EN_MASK                  0x00000004L
#define VIPH_DV_INT__VIPH_DV2_INT_EN                       0x00000004L
#define VIPH_DV_INT__VIPH_DV3_INT_EN_MASK                  0x00000008L
#define VIPH_DV_INT__VIPH_DV3_INT_EN                       0x00000008L
#define VIPH_DV_INT__VIPH_DV0_INT_MASK                     0x00000010L
#define VIPH_DV_INT__VIPH_DV0_INT                          0x00000010L
#define VIPH_DV_INT__VIPH_DV0_AK_MASK                      0x00000010L
#define VIPH_DV_INT__VIPH_DV0_AK                           0x00000010L
#define VIPH_DV_INT__VIPH_DV1_INT_MASK                     0x00000020L
#define VIPH_DV_INT__VIPH_DV1_INT                          0x00000020L
#define VIPH_DV_INT__VIPH_DV1_AK_MASK                      0x00000020L
#define VIPH_DV_INT__VIPH_DV1_AK                           0x00000020L
#define VIPH_DV_INT__VIPH_DV2_INT_MASK                     0x00000040L
#define VIPH_DV_INT__VIPH_DV2_INT                          0x00000040L
#define VIPH_DV_INT__VIPH_DV2_AK_MASK                      0x00000040L
#define VIPH_DV_INT__VIPH_DV2_AK                           0x00000040L
#define VIPH_DV_INT__VIPH_DV3_INT_MASK                     0x00000080L
#define VIPH_DV_INT__VIPH_DV3_INT                          0x00000080L
#define VIPH_DV_INT__VIPH_DV3_AK_MASK                      0x00000080L
#define VIPH_DV_INT__VIPH_DV3_AK                           0x00000080L

// VIPH_TIMEOUT_STAT
#define VIPH_TIMEOUT_STAT__VIPH_FIFO0_STAT_MASK            0x00000001L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO0_STAT                 0x00000001L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO0_AK_MASK              0x00000001L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO0_AK                   0x00000001L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO1_STAT_MASK            0x00000002L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO1_STAT                 0x00000002L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO1_AK_MASK              0x00000002L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO1_AK                   0x00000002L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO2_STAT_MASK            0x00000004L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO2_STAT                 0x00000004L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO2_AK_MASK              0x00000004L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO2_AK                   0x00000004L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO3_STAT_MASK            0x00000008L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO3_STAT                 0x00000008L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO3_AK_MASK              0x00000008L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO3_AK                   0x00000008L
#define VIPH_TIMEOUT_STAT__VIPH_REG_STAT_MASK              0x00000010L
#define VIPH_TIMEOUT_STAT__VIPH_REG_STAT                   0x00000010L
#define VIPH_TIMEOUT_STAT__VIPH_REG_AK_MASK                0x00000010L
#define VIPH_TIMEOUT_STAT__VIPH_REG_AK                     0x00000010L
#define VIPH_TIMEOUT_STAT__VIPH_AUTO_INT_STAT_MASK         0x00000020L
#define VIPH_TIMEOUT_STAT__VIPH_AUTO_INT_STAT              0x00000020L
#define VIPH_TIMEOUT_STAT__VIPH_AUTO_INT_AK_MASK           0x00000020L
#define VIPH_TIMEOUT_STAT__VIPH_AUTO_INT_AK                0x00000020L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO0_MASK_MASK            0x00000100L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO0_MASK                 0x00000100L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO1_MASK_MASK            0x00000200L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO1_MASK                 0x00000200L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO2_MASK_MASK            0x00000400L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO2_MASK                 0x00000400L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO3_MASK_MASK            0x00000800L
#define VIPH_TIMEOUT_STAT__VIPH_FIFO3_MASK                 0x00000800L
#define VIPH_TIMEOUT_STAT__VIPH_REG_MASK_MASK              0x00001000L
#define VIPH_TIMEOUT_STAT__VIPH_REG_MASK                   0x00001000L
#define VIPH_TIMEOUT_STAT__VIPH_AUTO_INT_MASK_MASK         0x00002000L
#define VIPH_TIMEOUT_STAT__VIPH_AUTO_INT_MASK              0x00002000L
#define VIPH_TIMEOUT_STAT__VIPH_DV0_INT_MASK_MASK          0x00010000L
#define VIPH_TIMEOUT_STAT__VIPH_DV0_INT_MASK               0x00010000L
#define VIPH_TIMEOUT_STAT__VIPH_DV1_INT_MASK_MASK          0x00020000L
#define VIPH_TIMEOUT_STAT__VIPH_DV1_INT_MASK               0x00020000L
#define VIPH_TIMEOUT_STAT__VIPH_DV2_INT_MASK_MASK          0x00040000L
#define VIPH_TIMEOUT_STAT__VIPH_DV2_INT_MASK               0x00040000L
#define VIPH_TIMEOUT_STAT__VIPH_DV3_INT_MASK_MASK          0x00080000L
#define VIPH_TIMEOUT_STAT__VIPH_DV3_INT_MASK               0x00080000L
#define VIPH_TIMEOUT_STAT__VIPH_INTPIN_EN_MASK             0x00100000L
#define VIPH_TIMEOUT_STAT__VIPH_INTPIN_EN                  0x00100000L
#define VIPH_TIMEOUT_STAT__VIPH_INTPIN_INT_MASK            0x00200000L
#define VIPH_TIMEOUT_STAT__VIPH_INTPIN_INT                 0x00200000L
#define VIPH_TIMEOUT_STAT__VIPH_REGR_DIS_MASK              0x01000000L
#define VIPH_TIMEOUT_STAT__VIPH_REGR_DIS                   0x01000000L

// CLK_PIN_CNTL
#define CLK_PIN_CNTL__OSC_EN_MASK                          0x00000001L
#define CLK_PIN_CNTL__OSC_EN                               0x00000001L
#define CLK_PIN_CNTL__XTL_LOW_GAIN_MASK                    0x00000004L
#define CLK_PIN_CNTL__XTL_LOW_GAIN                         0x00000004L
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
#define CLK_PIN_CNTL__XTALIN_ALWAYS_ONb_MASK               0x00080000L
#define CLK_PIN_CNTL__XTALIN_ALWAYS_ONb                    0x00080000L
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
#define SPLL_AUX_CNTL__TRANSIT_DONE_LENGTH_MASK            0x00001000L
#define SPLL_AUX_CNTL__TRANSIT_DONE_LENGTH                 0x00001000L

// SCLK_CNTL2
#define SCLK_CNTL2__GA_PROG_DELAY_VALUE_MASK               0x0000001fL
#define SCLK_CNTL2__TCL_PROG_DELAY_VALUE_MASK              0x000003e0L
#define SCLK_CNTL2__TCL_MAX_DYN_STOP_LAT_MASK              0x00000400L
#define SCLK_CNTL2__TCL_MAX_DYN_STOP_LAT                   0x00000400L
#define SCLK_CNTL2__GA_MAX_DYN_STOP_LAT_MASK               0x00000800L
#define SCLK_CNTL2__GA_MAX_DYN_STOP_LAT                    0x00000800L
#define SCLK_CNTL2__CBA_MAX_DYN_STOP_LAT_MASK              0x00001000L
#define SCLK_CNTL2__CBA_MAX_DYN_STOP_LAT                   0x00001000L
#define SCLK_CNTL2__FORCE_TCL_MASK                         0x00002000L
#define SCLK_CNTL2__FORCE_TCL                              0x00002000L
#define SCLK_CNTL2__FORCE_CBA_MASK                         0x00004000L
#define SCLK_CNTL2__FORCE_CBA                              0x00004000L
#define SCLK_CNTL2__FORCE_GA_MASK                          0x00008000L
#define SCLK_CNTL2__FORCE_GA                               0x00008000L

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

// AGP_PLL_CNTL
#define AGP_PLL_CNTL__APLL_SLEEP_MASK                      0x00000001L
#define AGP_PLL_CNTL__APLL_SLEEP                           0x00000001L
#define AGP_PLL_CNTL__APLL_RESET_MASK                      0x00000002L
#define AGP_PLL_CNTL__APLL_RESET                           0x00000002L
#define AGP_PLL_CNTL__APLL_XSEL_MASK                       0x0000000cL
#define AGP_PLL_CNTL__APLL_TST_EN_MASK                     0x00000010L
#define AGP_PLL_CNTL__APLL_TST_EN                          0x00000010L
#define AGP_PLL_CNTL__APLL_TCPOFF_MASK                     0x00000020L
#define AGP_PLL_CNTL__APLL_TCPOFF                          0x00000020L
#define AGP_PLL_CNTL__APLL_TVCOMAX_MASK                    0x00000040L
#define AGP_PLL_CNTL__APLL_TVCOMAX                         0x00000040L
#define AGP_PLL_CNTL__APLL_REF_SKEW_MASK                   0x00000380L
#define AGP_PLL_CNTL__APLL_FB_SKEW_MASK                    0x00001c00L
#define AGP_PLL_CNTL__APLL_X0_CLK_SKEW_MASK                0x0000e000L
#define AGP_PLL_CNTL__APLL_X1_CLK_SKEW_MASK                0x00070000L
#define AGP_PLL_CNTL__APLL_PUMP_GAIN_MASK                  0x0e000000L
#define AGP_PLL_CNTL__APLL_VCO_GAIN_MASK                   0x70000000L
#define AGP_PLL_CNTL__APLL_SEL_SKWADJ_PCICLK_MASK          0x80000000L
#define AGP_PLL_CNTL__APLL_SEL_SKWADJ_PCICLK               0x80000000L

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
#define P2PLL_CNTL__P2PLL_DISABLE_AUTO_RESET_MASK          0x00080000L
#define P2PLL_CNTL__P2PLL_DISABLE_AUTO_RESET               0x00080000L

// P2PLL_REF_DIV
#define P2PLL_REF_DIV__P2PLL_REF_DIV_MASK                  0x000003ffL
#define P2PLL_REF_DIV__P2PLL_ATOMIC_UPDATE_W_MASK          0x00008000L
#define P2PLL_REF_DIV__P2PLL_ATOMIC_UPDATE_W               0x00008000L
#define P2PLL_REF_DIV__P2PLL_ATOMIC_UPDATE_R_MASK          0x00008000L
#define P2PLL_REF_DIV__P2PLL_ATOMIC_UPDATE_R               0x00008000L
#define P2PLL_REF_DIV__P2PLL_REF_DIV_SRC_MASK              0x00030000L

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
#define SS_TST_CNTL__SS_SPARE_MASK                         0x0f000000L
#define SS_TST_CNTL__SS_TST_MODE_MASK                      0x80000000L
#define SS_TST_CNTL__SS_TST_MODE                           0x80000000L

// SCLK_MORE_CNTL
#define SCLK_MORE_CNTL__DISPREGS_MAX_DYN_STOP_LAT_MASK     0x00000001L
#define SCLK_MORE_CNTL__DISPREGS_MAX_DYN_STOP_LAT          0x00000001L
#define SCLK_MORE_CNTL__MC_GUI_MAX_DYN_STOP_LAT_MASK       0x00000002L
#define SCLK_MORE_CNTL__MC_GUI_MAX_DYN_STOP_LAT            0x00000002L
#define SCLK_MORE_CNTL__MC_HOST_MAX_DYN_STOP_LAT_MASK      0x00000004L
#define SCLK_MORE_CNTL__MC_HOST_MAX_DYN_STOP_LAT           0x00000004L
#define SCLK_MORE_CNTL__FORCE_DISPREGS_MASK                0x00000100L
#define SCLK_MORE_CNTL__FORCE_DISPREGS                     0x00000100L
#define SCLK_MORE_CNTL__FORCE_MC_GUI_MASK                  0x00000200L
#define SCLK_MORE_CNTL__FORCE_MC_GUI                       0x00000200L
#define SCLK_MORE_CNTL__FORCE_MC_HOST_MASK                 0x00000400L
#define SCLK_MORE_CNTL__FORCE_MC_HOST                      0x00000400L
#define SCLK_MORE_CNTL__STOP_SCLK_EN_MASK                  0x00001000L
#define SCLK_MORE_CNTL__STOP_SCLK_EN                       0x00001000L
#define SCLK_MORE_CNTL__STOP_SCLK_A_MASK                   0x00002000L
#define SCLK_MORE_CNTL__STOP_SCLK_A                        0x00002000L
#define SCLK_MORE_CNTL__STOP_SCLK_B_MASK                   0x00004000L
#define SCLK_MORE_CNTL__STOP_SCLK_B                        0x00004000L
#define SCLK_MORE_CNTL__STOP_SCLK_C_MASK                   0x00008000L
#define SCLK_MORE_CNTL__STOP_SCLK_C                        0x00008000L
#define SCLK_MORE_CNTL__CG_SPARE_C_R3_MASK                 0x00ff0000L
#define SCLK_MORE_CNTL__CG_SPARE_RD_C_MASK                 0xff000000L

// CLK_PWRMGT_CNTL
#define CLK_PWRMGT_CNTL__MPLL_PWRMGT_OFF_MASK              0x00000001L
#define CLK_PWRMGT_CNTL__MPLL_PWRMGT_OFF                   0x00000001L
#define CLK_PWRMGT_CNTL__SPLL_PWRMGT_OFF_MASK              0x00000002L
#define CLK_PWRMGT_CNTL__SPLL_PWRMGT_OFF                   0x00000002L
#define CLK_PWRMGT_CNTL__PPLL_PWRMGT_OFF_MASK              0x00000004L
#define CLK_PWRMGT_CNTL__PPLL_PWRMGT_OFF                   0x00000004L
#define CLK_PWRMGT_CNTL__P2PLL_PWRMGT_OFF_MASK             0x00000008L
#define CLK_PWRMGT_CNTL__P2PLL_PWRMGT_OFF                  0x00000008L
#define CLK_PWRMGT_CNTL__MCLK_TURNOFF_MASK                 0x00000010L
#define CLK_PWRMGT_CNTL__MCLK_TURNOFF                      0x00000010L
#define CLK_PWRMGT_CNTL__SCLK_TURNOFF_MASK                 0x00000020L
#define CLK_PWRMGT_CNTL__SCLK_TURNOFF                      0x00000020L
#define CLK_PWRMGT_CNTL__PCLK_TURNOFF_MASK                 0x00000040L
#define CLK_PWRMGT_CNTL__PCLK_TURNOFF                      0x00000040L
#define CLK_PWRMGT_CNTL__P2CLK_TURNOFF_MASK                0x00000080L
#define CLK_PWRMGT_CNTL__P2CLK_TURNOFF                     0x00000080L
#define CLK_PWRMGT_CNTL__MC_CH_MODE_MASK                   0x00000100L
#define CLK_PWRMGT_CNTL__MC_CH_MODE                        0x00000100L
#define CLK_PWRMGT_CNTL__TEST_MODE_MASK                    0x00000200L
#define CLK_PWRMGT_CNTL__TEST_MODE                         0x00000200L
#define CLK_PWRMGT_CNTL__GLOBAL_PMAN_EN_MASK               0x00000400L
#define CLK_PWRMGT_CNTL__GLOBAL_PMAN_EN                    0x00000400L
#define CLK_PWRMGT_CNTL__ENGINE_DYNCLK_MODE_MASK           0x00001000L
#define CLK_PWRMGT_CNTL__ENGINE_DYNCLK_MODE                0x00001000L
#define CLK_PWRMGT_CNTL__ACTIVE_HILO_LAT_MASK              0x00006000L
#define CLK_PWRMGT_CNTL__DISP_DYN_STOP_LAT_MASK            0x00008000L
#define CLK_PWRMGT_CNTL__DISP_DYN_STOP_LAT                 0x00008000L
#define CLK_PWRMGT_CNTL__MC_BUSY_MASK                      0x00010000L
#define CLK_PWRMGT_CNTL__MC_BUSY                           0x00010000L
#define CLK_PWRMGT_CNTL__MC_INT_CNTL_MASK                  0x00020000L
#define CLK_PWRMGT_CNTL__MC_INT_CNTL                       0x00020000L
#define CLK_PWRMGT_CNTL__MC_SWITCH_MASK                    0x00040000L
#define CLK_PWRMGT_CNTL__MC_SWITCH                         0x00040000L
#define CLK_PWRMGT_CNTL__DLL_READY_MASK                    0x00080000L
#define CLK_PWRMGT_CNTL__DLL_READY                         0x00080000L
#define CLK_PWRMGT_CNTL__DISP_PM_MASK                      0x00100000L
#define CLK_PWRMGT_CNTL__DISP_PM                           0x00100000L
#define CLK_PWRMGT_CNTL__DYN_STOP_MODE_MASK                0x00e00000L
#define CLK_PWRMGT_CNTL__CG_NO1_DEBUG_R3_MASK              0x3f000000L
#define CLK_PWRMGT_CNTL__TVPLL_PWRMGT_OFF_MASK             0x40000000L
#define CLK_PWRMGT_CNTL__TVPLL_PWRMGT_OFF                  0x40000000L
#define CLK_PWRMGT_CNTL__TVCLK_TURNOFF_MASK                0x80000000L
#define CLK_PWRMGT_CNTL__TVCLK_TURNOFF                     0x80000000L

// PLL_PWRMGT_CNTL
#define PLL_PWRMGT_CNTL__MPLL_TURNOFF_MASK                 0x00000001L
#define PLL_PWRMGT_CNTL__MPLL_TURNOFF                      0x00000001L
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
#define M_SPLL_REF_FB_DIV__MPLL_FB_DIV_MASK                0x0000ff00L
#define M_SPLL_REF_FB_DIV__SPLL_FB_DIV_MASK                0x00ff0000L
#define M_SPLL_REF_FB_DIV__MPLL_REF_SRC_SEL_MASK           0x01000000L
#define M_SPLL_REF_FB_DIV__MPLL_REF_SRC_SEL                0x01000000L

// MPLL_CNTL
#define MPLL_CNTL__MPLL_RESET_MASK                         0x00000001L
#define MPLL_CNTL__MPLL_RESET                              0x00000001L
#define MPLL_CNTL__MPLL_SLEEP_MASK                         0x00000002L
#define MPLL_CNTL__MPLL_SLEEP                              0x00000002L
#define MPLL_CNTL__MPLL_TST_EN_MASK                        0x00000004L
#define MPLL_CNTL__MPLL_TST_EN                             0x00000004L
#define MPLL_CNTL__MPLL_REFCLK_SEL_MASK                    0x00000010L
#define MPLL_CNTL__MPLL_REFCLK_SEL                         0x00000010L
#define MPLL_CNTL__MPLL_FBCLK_SEL_MASK                     0x00000020L
#define MPLL_CNTL__MPLL_FBCLK_SEL                          0x00000020L
#define MPLL_CNTL__MPLL_TCPOFF_MASK                        0x00000040L
#define MPLL_CNTL__MPLL_TCPOFF                             0x00000040L
#define MPLL_CNTL__MPLL_TVCOMAX_MASK                       0x00000080L
#define MPLL_CNTL__MPLL_TVCOMAX                            0x00000080L
#define MPLL_CNTL__MPLL_PCP_MASK                           0x00000700L
#define MPLL_CNTL__MPLL_PVG_MASK                           0x00003800L
#define MPLL_CNTL__MPLL_PDC_MASK                           0x0000c000L
#define MPLL_CNTL__MPLL_X1_CLK_SKEW_MASK                   0x00070000L
#define MPLL_CNTL__MPLL_X2_CLK_SKEW_MASK                   0x00700000L
#define MPLL_CNTL__MPLL_MODE_MASK                          0x0f000000L

// MPLL_AUX_CNTL
#define MPLL_AUX_CNTL__MPLL_PDC_C_MASK                     0x00000003L
#define MPLL_AUX_CNTL__MPLL_CKINVA_MASK                    0x00000004L
#define MPLL_AUX_CNTL__MPLL_CKINVA                         0x00000004L
#define MPLL_AUX_CNTL__MPLL_CKINVC_MASK                    0x00000008L
#define MPLL_AUX_CNTL__MPLL_CKINVC                         0x00000008L
#define MPLL_AUX_CNTL__MPLL_X3_CLK_SKEW_MASK               0x00000070L
#define MPLL_AUX_CNTL__MPLL_MODEC_MASK                     0x00000180L
#define MPLL_AUX_CNTL__MPLL_TEST_COUNT_MASK                0xff000000L

// MDLL_RDCK
#define MDLL_RDCK__MRDCKA_SLEEP_MASK                       0x00000001L
#define MDLL_RDCK__MRDCKA_SLEEP                            0x00000001L
#define MDLL_RDCK__MRDCKA_RESET_MASK                       0x00000002L
#define MDLL_RDCK__MRDCKA_RESET                            0x00000002L
#define MDLL_RDCK__MRDCKB_SLEEP_MASK                       0x00000004L
#define MDLL_RDCK__MRDCKB_SLEEP                            0x00000004L
#define MDLL_RDCK__MRDCKB_RESET_MASK                       0x00000008L
#define MDLL_RDCK__MRDCKB_RESET                            0x00000008L
#define MDLL_RDCK__MRDCKC_SLEEP_MASK                       0x00000010L
#define MDLL_RDCK__MRDCKC_SLEEP                            0x00000010L
#define MDLL_RDCK__MRDCKC_RESET_MASK                       0x00000020L
#define MDLL_RDCK__MRDCKC_RESET                            0x00000020L
#define MDLL_RDCK__MRDCKD_SLEEP_MASK                       0x00000040L
#define MDLL_RDCK__MRDCKD_SLEEP                            0x00000040L
#define MDLL_RDCK__MRDCKD_RESET_MASK                       0x00000080L
#define MDLL_RDCK__MRDCKD_RESET                            0x00000080L

// MCLK_CNTL
#define MCLK_CNTL__MCLKA_SRC_SEL_MASK                      0x00000007L
#define MCLK_CNTL__YCLKA_SRC_SEL_MASK                      0x00000070L
#define MCLK_CNTL__MCLKB_SRC_SEL_MASK                      0x00000700L
#define MCLK_CNTL__YCLKB_SRC_SEL_MASK                      0x00007000L
#define MCLK_CNTL__FORCE_MCLKA_MASK                        0x00010000L
#define MCLK_CNTL__FORCE_MCLKA                             0x00010000L
#define MCLK_CNTL__FORCE_MCLKB_MASK                        0x00020000L
#define MCLK_CNTL__FORCE_MCLKB                             0x00020000L
#define MCLK_CNTL__FORCE_YCLKA_MASK                        0x00040000L
#define MCLK_CNTL__FORCE_YCLKA                             0x00040000L
#define MCLK_CNTL__FORCE_YCLKB_MASK                        0x00080000L
#define MCLK_CNTL__FORCE_YCLKB                             0x00080000L
#define MCLK_CNTL__FORCE_MC_MASK                           0x00100000L
#define MCLK_CNTL__FORCE_MC                                0x00100000L
#define MCLK_CNTL__FORCE_AIC_MASK                          0x00200000L
#define MCLK_CNTL__FORCE_AIC                               0x00200000L
#define MCLK_CNTL__MRDCKA0_SOUTSEL_MASK                    0x03000000L
#define MCLK_CNTL__MRDCKA1_SOUTSEL_MASK                    0x0c000000L
#define MCLK_CNTL__MRDCKB0_SOUTSEL_MASK                    0x30000000L
#define MCLK_CNTL__MRDCKB1_SOUTSEL_MASK                    0xc0000000L

// MCLK_MISC
#define MCLK_MISC__SCLK_SOURCED_FROM_MPLL_SEL_MASK         0x00000003L
#define MCLK_MISC__MCLK_FROM_SPLL_DIV_SEL_MASK             0x00000004L
#define MCLK_MISC__MCLK_FROM_SPLL_DIV_SEL                  0x00000004L
#define MCLK_MISC__ENABLE_SCLK_FROM_MPLL_MASK              0x00000008L
#define MCLK_MISC__ENABLE_SCLK_FROM_MPLL                   0x00000008L
#define MCLK_MISC__MPLL_MODEA_MODEC_HW_SEL_EN_MASK         0x00000010L
#define MCLK_MISC__MPLL_MODEA_MODEC_HW_SEL_EN              0x00000010L
#define MCLK_MISC__DLL_READY_LAT_MASK                      0x00000100L
#define MCLK_MISC__DLL_READY_LAT                           0x00000100L
#define MCLK_MISC__MC_MCLK_MAX_DYN_STOP_LAT_MASK           0x00001000L
#define MCLK_MISC__MC_MCLK_MAX_DYN_STOP_LAT                0x00001000L
#define MCLK_MISC__IO_MCLK_MAX_DYN_STOP_LAT_MASK           0x00002000L
#define MCLK_MISC__IO_MCLK_MAX_DYN_STOP_LAT                0x00002000L
#define MCLK_MISC__MC_MCLK_DYN_ENABLE_MASK                 0x00004000L
#define MCLK_MISC__MC_MCLK_DYN_ENABLE                      0x00004000L
#define MCLK_MISC__IO_MCLK_DYN_ENABLE_MASK                 0x00008000L
#define MCLK_MISC__IO_MCLK_DYN_ENABLE                      0x00008000L
#define MCLK_MISC__CGM_CLK_TO_OUTPIN_MASK                  0x00010000L
#define MCLK_MISC__CGM_CLK_TO_OUTPIN                       0x00010000L
#define MCLK_MISC__CLK_OR_COUNT_SEL_MASK                   0x00020000L
#define MCLK_MISC__CLK_OR_COUNT_SEL                        0x00020000L
#define MCLK_MISC__EN_MCLK_TRISTATE_IN_SUSPEND_MASK        0x00040000L
#define MCLK_MISC__EN_MCLK_TRISTATE_IN_SUSPEND             0x00040000L
#define MCLK_MISC__CGM_SPARE_RD_MASK                       0x00300000L
#define MCLK_MISC__CGM_SPARE_A_RD_MASK                     0x00c00000L
#define MCLK_MISC__CGM_SPARE_A_R3_MASK                     0x0f000000L

// CG_TEST_MACRO_RW_WRITE
#define CG_TEST_MACRO_RW_WRITE__TEST_MACRO_RW_WRITE1_MASK  0x00003fffL
#define CG_TEST_MACRO_RW_WRITE__TEST_MACRO_RW_WRITE2_MASK  0x0fffc000L

// CG_TEST_MACRO_RW_READ
#define CG_TEST_MACRO_RW_READ__TEST_MACRO_RW_READ1_MASK    0x0000ffffL
#define CG_TEST_MACRO_RW_READ__TEST_MACRO_RW_READ2_MASK    0xffff0000L

// CG_TEST_MACRO_RW_DATA
#define CG_TEST_MACRO_RW_DATA__TEST_MACRO_RW_DATA_MASK     0xffffffffL

// CG_TEST_MACRO_RW_CNTL
#define CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_START_MASK    0x00000001L
#define CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_START         0x00000001L
#define CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_OP_MASK       0x0000000eL
#define CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_MODE_MASK     0x00000030L
#define CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_MISMATCH_SEL_MASK 0x00007fc0L
#define CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_MISMATCH_MASK 0x00008000L
#define CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_MISMATCH      0x00008000L
#define CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_ENABLE_MASK   0x00010000L
#define CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_ENABLE        0x00010000L
#define CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_SCLK_NEG_ENABLE_MASK 0x00020000L
#define CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_SCLK_NEG_ENABLE 0x00020000L

// IDCT_CSQ_CONTROL
#define IDCT_CSQ_CONTROL__PRE_WRITE_TIMER_MASK             0x00007fffL
#define IDCT_CSQ_CONTROL__SEMAPHORE_TIMER_MASK             0x3fff8000L
#define IDCT_CSQ_CONTROL__CSQ_MODE_MASK                    0xc0000000L

// IDCT_SCRATCH
#define IDCT_SCRATCH__IDCT_SCRATCH_MASK                    0xffffffffL

// IDCT_SPAN
#define IDCT_SPAN__IDCT_SPAN_MASK                          0x00ffffffL

// IDCT_RB_BASE
#define IDCT_RB_BASE__RB_BASE_MASK                         0xffffffffL

// IDCT_RB_CONTROL
#define IDCT_RB_CONTROL__RB_BUFSZ_MASK                     0x0000003fL
#define IDCT_RB_CONTROL__RB_BLKSZ_MASK                     0x00003f00L
#define IDCT_RB_CONTROL__BUF_SWAP_MASK                     0x00030000L
#define IDCT_RB_CONTROL__RB_NO_UPDATE_MASK                 0x08000000L
#define IDCT_RB_CONTROL__RB_NO_UPDATE                      0x08000000L
#define IDCT_RB_CONTROL__RB_INTERRUPT_ENABLE_MASK          0x10000000L
#define IDCT_RB_CONTROL__RB_INTERRUPT_ENABLE               0x10000000L
#define IDCT_RB_CONTROL__RB_SEMAPHORE_ENABLE_MASK          0x20000000L
#define IDCT_RB_CONTROL__RB_SEMAPHORE_ENABLE               0x20000000L
#define IDCT_RB_CONTROL__RB_RPTR_WR_ENA_MASK               0x80000000L
#define IDCT_RB_CONTROL__RB_RPTR_WR_ENA                    0x80000000L

// IDCT_RB_RPTR_ADDR
#define IDCT_RB_RPTR_ADDR__RB_RPTR_SWAP_MASK               0x00000003L
#define IDCT_RB_RPTR_ADDR__RB_RPTR_ADDR_MASK               0xfffffffcL

// IDCT_RB_RPTR
#define IDCT_RB_RPTR__RB_RPTR_MASK                         0x007fffffL

// IDCT_RB_WPTR
#define IDCT_RB_WPTR__RB_WPTR_MASK                         0x007fffffL

// IDCT_RB_TIMESTAMP
#define IDCT_RB_TIMESTAMP__RB_TIMESTAMP_MASK               0xffffffffL

// IDCT_RB_SEMAPHORE
#define IDCT_RB_SEMAPHORE__IDCT_SEMAPHORE_MASK             0x00000fffL
#define IDCT_RB_SEMAPHORE__INC_SEMAPHORE_WAIT_CLEAN_MASK   0x00002000L
#define IDCT_RB_SEMAPHORE__INC_SEMAPHORE_WAIT_CLEAN        0x00002000L
#define IDCT_RB_SEMAPHORE__DEC_IDCT_SEMAPHORE_MASK         0x00004000L
#define IDCT_RB_SEMAPHORE__DEC_IDCT_SEMAPHORE              0x00004000L
#define IDCT_RB_SEMAPHORE__INC_IDCT_SEMAPHORE_MASK         0x00008000L
#define IDCT_RB_SEMAPHORE__INC_IDCT_SEMAPHORE              0x00008000L
#define IDCT_RB_SEMAPHORE__FDCT_SEMAPHORE_MASK             0x0fff0000L
#define IDCT_RB_SEMAPHORE__FORCE_READER_PROCEED_MASK       0x20000000L
#define IDCT_RB_SEMAPHORE__FORCE_READER_PROCEED            0x20000000L
#define IDCT_RB_SEMAPHORE__DEC_FDCT_SEMAPHORE_MASK         0x40000000L
#define IDCT_RB_SEMAPHORE__DEC_FDCT_SEMAPHORE              0x40000000L
#define IDCT_RB_SEMAPHORE__INC_FDCT_SEMAPHORE_MASK         0x80000000L
#define IDCT_RB_SEMAPHORE__INC_FDCT_SEMAPHORE              0x80000000L

// IDCT_COEF_DATA
#define IDCT_COEF_DATA__IDCT_COEF_DATA_MASK                0xffffffffL

// IDCT_STATUS
#define IDCT_STATUS__IDCT_ERROR_00_MASK                    0x00000001L
#define IDCT_STATUS__IDCT_ERROR_00                         0x00000001L
#define IDCT_STATUS__IDCT_ERROR_01_MASK                    0x00000002L
#define IDCT_STATUS__IDCT_ERROR_01                         0x00000002L
#define IDCT_STATUS__IDCT_ERROR_02_MASK                    0x00000004L
#define IDCT_STATUS__IDCT_ERROR_02                         0x00000004L
#define IDCT_STATUS__IDCT_ERROR_03_MASK                    0x00000008L
#define IDCT_STATUS__IDCT_ERROR_03                         0x00000008L
#define IDCT_STATUS__IDCT_ERROR_04_MASK                    0x00000010L
#define IDCT_STATUS__IDCT_ERROR_04                         0x00000010L
#define IDCT_STATUS__IDCT_ERROR_05_MASK                    0x00000020L
#define IDCT_STATUS__IDCT_ERROR_05                         0x00000020L
#define IDCT_STATUS__IDCT_ERROR_06_MASK                    0x00000040L
#define IDCT_STATUS__IDCT_ERROR_06                         0x00000040L
#define IDCT_STATUS__IDCT_ERROR_07_MASK                    0x00000080L
#define IDCT_STATUS__IDCT_ERROR_07                         0x00000080L
#define IDCT_STATUS__IDCT_ERROR_08_MASK                    0x00000100L
#define IDCT_STATUS__IDCT_ERROR_08                         0x00000100L
#define IDCT_STATUS__IDCT_ERROR_09_MASK                    0x00000200L
#define IDCT_STATUS__IDCT_ERROR_09                         0x00000200L
#define IDCT_STATUS__IDCT_ERROR_10_MASK                    0x00000400L
#define IDCT_STATUS__IDCT_ERROR_10                         0x00000400L
#define IDCT_STATUS__IDCT_ERROR_11_MASK                    0x00000800L
#define IDCT_STATUS__IDCT_ERROR_11                         0x00000800L
#define IDCT_STATUS__IDCT_ERROR_12_MASK                    0x00001000L
#define IDCT_STATUS__IDCT_ERROR_12                         0x00001000L
#define IDCT_STATUS__IDCT_ERROR_13_MASK                    0x00002000L
#define IDCT_STATUS__IDCT_ERROR_13                         0x00002000L
#define IDCT_STATUS__IDCT_ERROR_14_MASK                    0x00004000L
#define IDCT_STATUS__IDCT_ERROR_14                         0x00004000L
#define IDCT_STATUS__IDCT_ERROR_15_MASK                    0x00008000L
#define IDCT_STATUS__IDCT_ERROR_15                         0x00008000L
#define IDCT_STATUS__WAIT_FDCT_SEMAPHORE_MASK              0x20000000L
#define IDCT_STATUS__WAIT_FDCT_SEMAPHORE                   0x20000000L
#define IDCT_STATUS__IDCT_PIO_READY_MASK                   0x40000000L
#define IDCT_STATUS__IDCT_PIO_READY                        0x40000000L
#define IDCT_STATUS__IDCT_IDLE_MASK                        0x80000000L
#define IDCT_STATUS__IDCT_IDLE                             0x80000000L

// IDCT_COEF_BASE
#define IDCT_COEF_BASE__IDCT_STREAM_ID_MASK                0x0000000fL
#define IDCT_COEF_BASE__IDCT_MEM_LOCATION_MASK             0xffffffe0L

// IDCT_CONTROL
#define IDCT_CONTROL__IDCT_SCRAMBLE_SELECT_MASK            0x00000003L
#define IDCT_CONTROL__IDCT_CTL_SCAN_PATTERN_R3_MASK        0x00000018L
#define IDCT_CONTROL__IDCT_CTL_INTRA_MASK                  0x00000020L
#define IDCT_CONTROL__IDCT_CTL_INTRA                       0x00000020L
#define IDCT_CONTROL__FDCT_WAIT_MASK                       0x00000040L
#define IDCT_CONTROL__FDCT_WAIT                            0x00000040L
#define IDCT_CONTROL__IDCT_CTL_CODED_RUN_MASK              0x00000080L
#define IDCT_CONTROL__IDCT_CTL_CODED_RUN                   0x00000080L
#define IDCT_CONTROL__IDCT_CTL_SW_RESET_MASK               0x00000100L
#define IDCT_CONTROL__IDCT_CTL_SW_RESET                    0x00000100L
#define IDCT_CONTROL__IDCT_INTRA_YMODE_MASK                0x00000200L
#define IDCT_CONTROL__IDCT_INTRA_YMODE                     0x00000200L
#define IDCT_CONTROL__IDCT_SCRAMBLE_MASK                   0x00000400L
#define IDCT_CONTROL__IDCT_SCRAMBLE                        0x00000400L
#define IDCT_CONTROL__IDCT_FIELD_ENCODING_MASK             0x00000800L
#define IDCT_CONTROL__IDCT_FIELD_ENCODING                  0x00000800L
#define IDCT_CONTROL__IDCT_ZERO_ON_ERROR_MASK              0x00001000L
#define IDCT_CONTROL__IDCT_ZERO_ON_ERROR                   0x00001000L
#define IDCT_CONTROL__IDCT_248_MODE_MASK                   0x00002000L
#define IDCT_CONTROL__IDCT_248_MODE                        0x00002000L
#define IDCT_CONTROL__IDCT_USE_VPLANE_MASK                 0x00004000L
#define IDCT_CONTROL__IDCT_USE_VPLANE                      0x00004000L
#define IDCT_CONTROL__IDCT_DIRECTION_MASK                  0x00008000L
#define IDCT_CONTROL__IDCT_DIRECTION                       0x00008000L
#define IDCT_CONTROL__IDCT_MISMATCH_CONTROL_MASK           0x00010000L
#define IDCT_CONTROL__IDCT_MISMATCH_CONTROL                0x00010000L

// IDCT_AUTH_CONTROL0
#define IDCT_AUTH_CONTROL0__CONTROL_BITS_MASK              0xffffffffL

// IDCT_AUTH0
#define IDCT_AUTH0__AUTH_MASK                              0xffffffffL

// IDCT_AUTH_CONTROL1
#define IDCT_AUTH_CONTROL1__CONTROL_BITS_MASK              0xffffffffL

// IDCT_AUTH1
#define IDCT_AUTH1__AUTH_MASK                              0xffffffffL

// IDCT_AUTH_CONTROL2
#define IDCT_AUTH_CONTROL2__CONTROL_BITS_MASK              0xffffffffL

// IDCT_AUTH2
#define IDCT_AUTH2__AUTH_MASK                              0xffffffffL

// IDCT_AUTH_CONTROL3
#define IDCT_AUTH_CONTROL3__CONTROL_BITS_MASK              0xffffffffL

// IDCT_AUTH3
#define IDCT_AUTH3__AUTH_MASK                              0xffffffffL

// IDCT_MEM_ADDR_YPLANE
#define IDCT_MEM_ADDR_YPLANE__IDCT_MEM_LOCATION_MASK       0xffffffffL

// IDCT_MEM_ADDR_UPLANE
#define IDCT_MEM_ADDR_UPLANE__IDCT_MEM_LOCATION_MASK       0xffffffffL

// IDCT_MEM_ADDR_VPLANE
#define IDCT_MEM_ADDR_VPLANE__IDCT_MEM_LOCATION_MASK       0xffffffffL

// IDCT_YSIZE
#define IDCT_YSIZE__IDCT_MEM_SIZE_MASK                     0x00ffffffL

// IDCT_USIZE
#define IDCT_USIZE__IDCT_MEM_SIZE_MASK                     0x00ffffffL

// IDCT_INITIAL_XY
#define IDCT_INITIAL_XY__IDCT_SCREEN_X_MASK                0x00000fffL
#define IDCT_INITIAL_XY__IDCT_SCREEN_Y_MASK                0x07ff0000L

// IDCT_SURFACE_PITCH
#define IDCT_SURFACE_PITCH__IDCT_Y_PITCH_MASK              0x00001fffL
#define IDCT_SURFACE_PITCH__IDCT_UV_PITCH_MASK             0x1fff0000L

// IDCT_SURFACE_WIDTH
#define IDCT_SURFACE_WIDTH__IDCT_Y_WIDTH_MASK              0x00001fffL
#define IDCT_SURFACE_WIDTH__IDCT_Y_HEIGHT_MASK             0x1fff0000L

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
#define TV_RGB_CNTL__TVOUT_SCALE_EN_MASK                   0x04000000L
#define TV_RGB_CNTL__TVOUT_SCALE_EN                        0x04000000L
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

#endif


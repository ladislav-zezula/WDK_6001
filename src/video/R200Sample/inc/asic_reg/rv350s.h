

#if !defined (_shivah_SHIFT_HEADER)
#define _shivah_SHIFT_HEADER
/*
*	shivah_shift.h
*
*	Register Spec Release:  Chip Spec 1.45
*
*
*	 (c) 2000 ATI Technologies Inc.  (unpublished)
*
*	 All rights reserved.
*	 The year included in the foregoing notice is the year of creation of the work.
*
*/

// GB_VAP_RASTER_VTX_FMT_0
#define	GB_VAP_RASTER_VTX_FMT_0__VTX_POS_PRESENT__SHIFT    0x00000000
#define	GB_VAP_RASTER_VTX_FMT_0__VTX_COLOR_0_PRESENT__SHIFT 0x00000001
#define	GB_VAP_RASTER_VTX_FMT_0__VTX_COLOR_1_PRESENT__SHIFT 0x00000002
#define	GB_VAP_RASTER_VTX_FMT_0__VTX_COLOR_2_PRESENT__SHIFT 0x00000003
#define	GB_VAP_RASTER_VTX_FMT_0__VTX_COLOR_3_PRESENT__SHIFT 0x00000004
#define	GB_VAP_RASTER_VTX_FMT_0__VTX_COLOR_SPARE__SHIFT    0x00000005
#define	GB_VAP_RASTER_VTX_FMT_0__VTX_PT_SIZE_PRESENT__SHIFT 0x00000010
#define	GB_VAP_RASTER_VTX_FMT_0__VTX_UNUSED__SHIFT         0x00000011

// GB_VAP_RASTER_VTX_FMT_1
#define	GB_VAP_RASTER_VTX_FMT_1__TEX_0_COMP_CNT__SHIFT     0x00000000
#define	GB_VAP_RASTER_VTX_FMT_1__TEX_1_COMP_CNT__SHIFT     0x00000003
#define	GB_VAP_RASTER_VTX_FMT_1__TEX_2_COMP_CNT__SHIFT     0x00000006
#define	GB_VAP_RASTER_VTX_FMT_1__TEX_3_COMP_CNT__SHIFT     0x00000009
#define	GB_VAP_RASTER_VTX_FMT_1__TEX_4_COMP_CNT__SHIFT     0x0000000c
#define	GB_VAP_RASTER_VTX_FMT_1__TEX_5_COMP_CNT__SHIFT     0x0000000f
#define	GB_VAP_RASTER_VTX_FMT_1__TEX_6_COMP_CNT__SHIFT     0x00000012
#define	GB_VAP_RASTER_VTX_FMT_1__TEX_7_COMP_CNT__SHIFT     0x00000015

// SIM_RAS_FINISH_TOKEN
#define	SIM_RAS_FINISH_TOKEN__RAS_FINISH_TOKEN__SHIFT      0x00000000

// SIM_END_TOKEN
#define	SIM_END_TOKEN__END_TOKEN__SHIFT                    0x00000000

// GB_ENABLE
#define	GB_ENABLE__POINT_STUFF_ENABLE__SHIFT               0x00000000
#define	GB_ENABLE__LINE_STUFF_ENABLE__SHIFT                0x00000001
#define	GB_ENABLE__TRIANGLE_STUFF_ENABLE__SHIFT            0x00000002
#define	GB_ENABLE__STENCIL_AUTO__SHIFT                     0x00000004
#define	GB_ENABLE__TEX0_SOURCE__SHIFT                      0x00000010
#define	GB_ENABLE__TEX1_SOURCE__SHIFT                      0x00000012
#define	GB_ENABLE__TEX2_SOURCE__SHIFT                      0x00000014
#define	GB_ENABLE__TEX3_SOURCE__SHIFT                      0x00000016
#define	GB_ENABLE__TEX4_SOURCE__SHIFT                      0x00000018
#define	GB_ENABLE__TEX5_SOURCE__SHIFT                      0x0000001a
#define	GB_ENABLE__TEX6_SOURCE__SHIFT                      0x0000001c
#define	GB_ENABLE__TEX7_SOURCE__SHIFT                      0x0000001e

// GB_VAP_REMAP
#define	GB_VAP_REMAP__UNUSED__SHIFT                        0x00000000

// GB_MSPOS0
#define	GB_MSPOS0__MS_X0__SHIFT                            0x00000000
#define	GB_MSPOS0__MS_Y0__SHIFT                            0x00000004
#define	GB_MSPOS0__MS_X1__SHIFT                            0x00000008
#define	GB_MSPOS0__MS_Y1__SHIFT                            0x0000000c
#define	GB_MSPOS0__MS_X2__SHIFT                            0x00000010
#define	GB_MSPOS0__MS_Y2__SHIFT                            0x00000014
#define	GB_MSPOS0__MSBD0_Y__SHIFT                          0x00000018
#define	GB_MSPOS0__MSBD0_X__SHIFT                          0x0000001c

// GB_MSPOS1
#define	GB_MSPOS1__MS_X3__SHIFT                            0x00000000
#define	GB_MSPOS1__MS_Y3__SHIFT                            0x00000004
#define	GB_MSPOS1__MS_X4__SHIFT                            0x00000008
#define	GB_MSPOS1__MS_Y4__SHIFT                            0x0000000c
#define	GB_MSPOS1__MS_X5__SHIFT                            0x00000010
#define	GB_MSPOS1__MS_Y5__SHIFT                            0x00000014
#define	GB_MSPOS1__MSBD1__SHIFT                            0x00000018

// GB_TILE_CONFIG
#define	GB_TILE_CONFIG__ENABLE__SHIFT                      0x00000000
#define	GB_TILE_CONFIG__PIPE_COUNT__SHIFT                  0x00000001
#define	GB_TILE_CONFIG__TILE_SIZE__SHIFT                   0x00000004
#define	GB_TILE_CONFIG__SUPER_SIZE__SHIFT                  0x00000006
#define	GB_TILE_CONFIG__SUPER_X__SHIFT                     0x00000009
#define	GB_TILE_CONFIG__SUPER_Y__SHIFT                     0x0000000c
#define	GB_TILE_CONFIG__SUPER_TILE__SHIFT                  0x0000000f
#define	GB_TILE_CONFIG__SUBPIXEL__SHIFT                    0x00000010
#define	GB_TILE_CONFIG__QUADS_PER_RAS__SHIFT               0x00000011
#define	GB_TILE_CONFIG__BB_SCAN__SHIFT                     0x00000013
#define	GB_TILE_CONFIG__ALT_SCAN_EN__SHIFT                 0x00000014

// GB_FIFO_SIZE
#define	GB_FIFO_SIZE__SC_IFIFO_SIZE__SHIFT                 0x00000000
#define	GB_FIFO_SIZE__SC_TZFIFO_SIZE__SHIFT                0x00000002
#define	GB_FIFO_SIZE__SC_BFIFO_SIZE__SHIFT                 0x00000004
#define	GB_FIFO_SIZE__RS_TFIFO_SIZE__SHIFT                 0x00000006
#define	GB_FIFO_SIZE__RS_CFIFO_SIZE__SHIFT                 0x00000008
#define	GB_FIFO_SIZE__US_RAM_SIZE__SHIFT                   0x0000000a
#define	GB_FIFO_SIZE__US_OFIFO_SIZE__SHIFT                 0x0000000c
#define	GB_FIFO_SIZE__US_WFIFO_SIZE__SHIFT                 0x0000000e
#define	GB_FIFO_SIZE__RS_HIGHWATER_COL__SHIFT              0x00000010
#define	GB_FIFO_SIZE__RS_HIGHWATER_TEX__SHIFT              0x00000013
#define	GB_FIFO_SIZE__US_OFIFO_HIGHWATER__SHIFT            0x00000016
#define	GB_FIFO_SIZE__US_CUBE_FIFO_HIGHWATER__SHIFT        0x00000018

// GB_SELECT
#define	GB_SELECT__FOG_SELECT__SHIFT                       0x00000000
#define	GB_SELECT__DEPTH_SELECT__SHIFT                     0x00000003
#define	GB_SELECT__W_SELECT__SHIFT                         0x00000004

// GB_AA_CONFIG
#define	GB_AA_CONFIG__AA_ENABLE__SHIFT                     0x00000000
#define	GB_AA_CONFIG__NUM_AA_SUBSAMPLES__SHIFT             0x00000001

// GB_Z_PEQ_CONFIG
#define	GB_Z_PEQ_CONFIG__Z_PEQ_SIZE__SHIFT                 0x00000000

// GA_VAP_VF_CNTL
#define	GA_VAP_VF_CNTL__PRIM_TYPE__SHIFT                   0x00000000
#define	GA_VAP_VF_CNTL__VF_UNUSED__SHIFT                   0x00000004

// GA_POINT_S0
#define	GA_POINT_S0__S0__SHIFT                             0x00000000

// GA_POINT_T0
#define	GA_POINT_T0__T0__SHIFT                             0x00000000

// GA_POINT_S1
#define	GA_POINT_S1__S1__SHIFT                             0x00000000

// GA_POINT_T1
#define	GA_POINT_T1__T1__SHIFT                             0x00000000

// GA_TRIANGLE_STIPPLE
#define	GA_TRIANGLE_STIPPLE__X_SHIFT__SHIFT                0x00000000
#define	GA_TRIANGLE_STIPPLE__Y_SHIFT__SHIFT                0x00000010

// GA_POINT_SIZE
#define	GA_POINT_SIZE__HEIGHT__SHIFT                       0x00000000
#define	GA_POINT_SIZE__WIDTH__SHIFT                        0x00000010

// GA_POINT_MINMAX
#define	GA_POINT_MINMAX__MIN_SIZE__SHIFT                   0x00000000
#define	GA_POINT_MINMAX__MAX_SIZE__SHIFT                   0x00000010

// GA_LINE_CNTL
#define	GA_LINE_CNTL__WIDTH__SHIFT                         0x00000000
#define	GA_LINE_CNTL__END_TYPE__SHIFT                      0x00000010

// GA_LINE_STIPPLE_CONFIG
#define	GA_LINE_STIPPLE_CONFIG__LINE_RESET__SHIFT          0x00000000
#define	GA_LINE_STIPPLE_CONFIG__STIPPLE_SCALE__SHIFT       0x00000002

// GA_LINE_STIPPLE_VALUE
#define	GA_LINE_STIPPLE_VALUE__STIPPLE_VALUE__SHIFT        0x00000000

// GA_LINE_S0
#define	GA_LINE_S0__S0__SHIFT                              0x00000000

// GA_LINE_S1
#define	GA_LINE_S1__S1__SHIFT                              0x00000000

// GA_PERF
#define	GA_PERF__PERF0_SEL__SHIFT                          0x00000000
#define	GA_PERF__PERF1_SEL__SHIFT                          0x00000008
#define	GA_PERF__PERF2_SEL__SHIFT                          0x00000010
#define	GA_PERF__PERF3_SEL__SHIFT                          0x00000018

// GA_PERF_READ0
#define	GA_PERF_READ0__PERF__SHIFT                         0x00000000

// GA_PERF_READ1
#define	GA_PERF_READ1__PERF__SHIFT                         0x00000000

// GA_PERF_READ2
#define	GA_PERF_READ2__PERF__SHIFT                         0x00000000

// GA_PERF_READ3
#define	GA_PERF_READ3__PERF__SHIFT                         0x00000000

// GA_ENHANCE
#define	GA_ENHANCE__DEADLOCK_CNTL__SHIFT                   0x00000000
#define	GA_ENHANCE__FASTSYNC_CNTL__SHIFT                   0x00000001

// GA_COLOR_CONTROL
#define	GA_COLOR_CONTROL__RGB0_SHADING__SHIFT              0x00000000
#define	GA_COLOR_CONTROL__ALPHA0_SHADING__SHIFT            0x00000002
#define	GA_COLOR_CONTROL__RGB1_SHADING__SHIFT              0x00000004
#define	GA_COLOR_CONTROL__ALPHA1_SHADING__SHIFT            0x00000006
#define	GA_COLOR_CONTROL__RGB2_SHADING__SHIFT              0x00000008
#define	GA_COLOR_CONTROL__ALPHA2_SHADING__SHIFT            0x0000000a
#define	GA_COLOR_CONTROL__RGB3_SHADING__SHIFT              0x0000000c
#define	GA_COLOR_CONTROL__ALPHA3_SHADING__SHIFT            0x0000000e
#define	GA_COLOR_CONTROL__PROVOKING_VERTEX__SHIFT          0x00000010

// GA_SOLID_RG
#define	GA_SOLID_RG__COLOR_GREEN__SHIFT                    0x00000000
#define	GA_SOLID_RG__COLOR_RED__SHIFT                      0x00000010

// GA_SOLID_BA
#define	GA_SOLID_BA__COLOR_ALPHA__SHIFT                    0x00000000
#define	GA_SOLID_BA__COLOR_BLUE__SHIFT                     0x00000010

// GA_POLY_MODE
#define	GA_POLY_MODE__POLY_MODE__SHIFT                     0x00000000
#define	GA_POLY_MODE__FRONT_PTYPE__SHIFT                   0x00000004
#define	GA_POLY_MODE__BACK_PTYPE__SHIFT                    0x00000007

// GA_ROUND_MODE
#define	GA_ROUND_MODE__GEOMETRY_ROUND__SHIFT               0x00000000
#define	GA_ROUND_MODE__COLOR_ROUND__SHIFT                  0x00000002
#define	GA_ROUND_MODE__RGB_CLAMP__SHIFT                    0x00000004
#define	GA_ROUND_MODE__ALPHA_CLAMP__SHIFT                  0x00000005

// GA_OFFSET
#define	GA_OFFSET__X_OFFSET__SHIFT                         0x00000000
#define	GA_OFFSET__Y_OFFSET__SHIFT                         0x00000010

// GA_FOG_SCALE
#define	GA_FOG_SCALE__VALUE__SHIFT                         0x00000000

// GA_FOG_OFFSET
#define	GA_FOG_OFFSET__VALUE__SHIFT                        0x00000000

// GA_SOFT_RESET
#define	GA_SOFT_RESET__SOFT_RESET_COUNT__SHIFT             0x00000000

// SU_TEX_WRAP
#define	SU_TEX_WRAP__T0C0__SHIFT                           0x00000000
#define	SU_TEX_WRAP__T0C1__SHIFT                           0x00000001
#define	SU_TEX_WRAP__T0C2__SHIFT                           0x00000002
#define	SU_TEX_WRAP__T0C3__SHIFT                           0x00000003
#define	SU_TEX_WRAP__T1C0__SHIFT                           0x00000004
#define	SU_TEX_WRAP__T1C1__SHIFT                           0x00000005
#define	SU_TEX_WRAP__T1C2__SHIFT                           0x00000006
#define	SU_TEX_WRAP__T1C3__SHIFT                           0x00000007
#define	SU_TEX_WRAP__T2C0__SHIFT                           0x00000008
#define	SU_TEX_WRAP__T2C1__SHIFT                           0x00000009
#define	SU_TEX_WRAP__T2C2__SHIFT                           0x0000000a
#define	SU_TEX_WRAP__T2C3__SHIFT                           0x0000000b
#define	SU_TEX_WRAP__T3C0__SHIFT                           0x0000000c
#define	SU_TEX_WRAP__T3C1__SHIFT                           0x0000000d
#define	SU_TEX_WRAP__T3C2__SHIFT                           0x0000000e
#define	SU_TEX_WRAP__T3C3__SHIFT                           0x0000000f
#define	SU_TEX_WRAP__T4C0__SHIFT                           0x00000010
#define	SU_TEX_WRAP__T4C1__SHIFT                           0x00000011
#define	SU_TEX_WRAP__T4C2__SHIFT                           0x00000012
#define	SU_TEX_WRAP__T4C3__SHIFT                           0x00000013
#define	SU_TEX_WRAP__T5C0__SHIFT                           0x00000014
#define	SU_TEX_WRAP__T5C1__SHIFT                           0x00000015
#define	SU_TEX_WRAP__T5C2__SHIFT                           0x00000016
#define	SU_TEX_WRAP__T5C3__SHIFT                           0x00000017
#define	SU_TEX_WRAP__T6C0__SHIFT                           0x00000018
#define	SU_TEX_WRAP__T6C1__SHIFT                           0x00000019
#define	SU_TEX_WRAP__T6C2__SHIFT                           0x0000001a
#define	SU_TEX_WRAP__T6C3__SHIFT                           0x0000001b
#define	SU_TEX_WRAP__T7C0__SHIFT                           0x0000001c
#define	SU_TEX_WRAP__T7C1__SHIFT                           0x0000001d
#define	SU_TEX_WRAP__T7C2__SHIFT                           0x0000001e
#define	SU_TEX_WRAP__T7C3__SHIFT                           0x0000001f

// SU_POLY_OFFSET_FRONT_SCALE
#define	SU_POLY_OFFSET_FRONT_SCALE__SCALE__SHIFT           0x00000000

// SU_POLY_OFFSET_FRONT_OFFSET
#define	SU_POLY_OFFSET_FRONT_OFFSET__OFFSET__SHIFT         0x00000000

// SU_POLY_OFFSET_BACK_SCALE
#define	SU_POLY_OFFSET_BACK_SCALE__SCALE__SHIFT            0x00000000

// SU_POLY_OFFSET_BACK_OFFSET
#define	SU_POLY_OFFSET_BACK_OFFSET__OFFSET__SHIFT          0x00000000

// SU_POLY_OFFSET_ENABLE
#define	SU_POLY_OFFSET_ENABLE__FRONT_ENABLE__SHIFT         0x00000000
#define	SU_POLY_OFFSET_ENABLE__BACK_ENABLE__SHIFT          0x00000001
#define	SU_POLY_OFFSET_ENABLE__PARA_ENABLE__SHIFT          0x00000002

// SU_CULL_MODE
#define	SU_CULL_MODE__CULL_FRONT__SHIFT                    0x00000000
#define	SU_CULL_MODE__CULL_BACK__SHIFT                     0x00000001
#define	SU_CULL_MODE__FACE__SHIFT                          0x00000002

// SU_ENHANCE
#define	SU_ENHANCE__ADJ_SHIFT__SHIFT                       0x00000000

// SU_DEPTH_SCALE
#define	SU_DEPTH_SCALE__SCALE__SHIFT                       0x00000000

// SU_DEPTH_OFFSET
#define	SU_DEPTH_OFFSET__OFFSET__SHIFT                     0x00000000

// SU_REG_DEST
#define	SU_REG_DEST__SELECT__SHIFT                         0x00000000

// SU_PERF
#define	SU_PERF__PERF0_SEL__SHIFT                          0x00000000
#define	SU_PERF__PERF1_SEL__SHIFT                          0x00000008
#define	SU_PERF__PERF2_SEL__SHIFT                          0x00000010
#define	SU_PERF__PERF3_SEL__SHIFT                          0x00000018

// SU_PERF_READ0
#define	SU_PERF_READ0__PERF_READ__SHIFT                    0x00000000

// SU_PERF_READ1
#define	SU_PERF_READ1__PERF_READ__SHIFT                    0x00000000

// SU_PERF_READ2
#define	SU_PERF_READ2__PERF_READ__SHIFT                    0x00000000

// SU_PERF_READ3
#define	SU_PERF_READ3__PERF_READ__SHIFT                    0x00000000

// SU_SRU_PERF0_0
#define	SU_SRU_PERF0_0__PERF_READ__SHIFT                   0x00000000

// SU_SRU_PERF0_1
#define	SU_SRU_PERF0_1__PERF_READ__SHIFT                   0x00000000

// SU_SRU_PERF0_2
#define	SU_SRU_PERF0_2__PERF_READ__SHIFT                   0x00000000

// SU_SRU_PERF0_3
#define	SU_SRU_PERF0_3__PERF_READ__SHIFT                   0x00000000

// SU_SRU_PERF1_0
#define	SU_SRU_PERF1_0__PERF_READ__SHIFT                   0x00000000

// SU_SRU_PERF1_1
#define	SU_SRU_PERF1_1__PERF_READ__SHIFT                   0x00000000

// SU_SRU_PERF1_2
#define	SU_SRU_PERF1_2__PERF_READ__SHIFT                   0x00000000

// SU_SRU_PERF1_3
#define	SU_SRU_PERF1_3__PERF_READ__SHIFT                   0x00000000

// RS_COUNT
#define	RS_COUNT__IT_COUNT__SHIFT                          0x00000000
#define	RS_COUNT__IC_COUNT__SHIFT                          0x00000007
#define	RS_COUNT__W_COUNT__SHIFT                           0x0000000b
#define	RS_COUNT__W_ADDR__SHIFT                            0x0000000c
#define	RS_COUNT__HIRES_EN__SHIFT                          0x00000012

// RS_IP_0
#define	RS_IP_0__TEX_PTR__SHIFT                            0x00000000
#define	RS_IP_0__COL_PTR__SHIFT                            0x00000006
#define	RS_IP_0__COL_FMT__SHIFT                            0x00000009
#define	RS_IP_0__SEL_S__SHIFT                              0x0000000d
#define	RS_IP_0__SEL_T__SHIFT                              0x00000010
#define	RS_IP_0__SEL_R__SHIFT                              0x00000013
#define	RS_IP_0__SEL_Q__SHIFT                              0x00000016

// RS_IP_1
#define	RS_IP_1__TEX_PTR__SHIFT                            0x00000000
#define	RS_IP_1__COL_PTR__SHIFT                            0x00000006
#define	RS_IP_1__COL_FMT__SHIFT                            0x00000009
#define	RS_IP_1__SEL_S__SHIFT                              0x0000000d
#define	RS_IP_1__SEL_T__SHIFT                              0x00000010
#define	RS_IP_1__SEL_R__SHIFT                              0x00000013
#define	RS_IP_1__SEL_Q__SHIFT                              0x00000016

// RS_IP_2
#define	RS_IP_2__TEX_PTR__SHIFT                            0x00000000
#define	RS_IP_2__COL_PTR__SHIFT                            0x00000006
#define	RS_IP_2__COL_FMT__SHIFT                            0x00000009
#define	RS_IP_2__SEL_S__SHIFT                              0x0000000d
#define	RS_IP_2__SEL_T__SHIFT                              0x00000010
#define	RS_IP_2__SEL_R__SHIFT                              0x00000013
#define	RS_IP_2__SEL_Q__SHIFT                              0x00000016

// RS_IP_3
#define	RS_IP_3__TEX_PTR__SHIFT                            0x00000000
#define	RS_IP_3__COL_PTR__SHIFT                            0x00000006
#define	RS_IP_3__COL_FMT__SHIFT                            0x00000009
#define	RS_IP_3__SEL_S__SHIFT                              0x0000000d
#define	RS_IP_3__SEL_T__SHIFT                              0x00000010
#define	RS_IP_3__SEL_R__SHIFT                              0x00000013
#define	RS_IP_3__SEL_Q__SHIFT                              0x00000016

// RS_IP_4
#define	RS_IP_4__TEX_PTR__SHIFT                            0x00000000
#define	RS_IP_4__COL_PTR__SHIFT                            0x00000006
#define	RS_IP_4__COL_FMT__SHIFT                            0x00000009
#define	RS_IP_4__SEL_S__SHIFT                              0x0000000d
#define	RS_IP_4__SEL_T__SHIFT                              0x00000010
#define	RS_IP_4__SEL_R__SHIFT                              0x00000013
#define	RS_IP_4__SEL_Q__SHIFT                              0x00000016

// RS_IP_5
#define	RS_IP_5__TEX_PTR__SHIFT                            0x00000000
#define	RS_IP_5__COL_PTR__SHIFT                            0x00000006
#define	RS_IP_5__COL_FMT__SHIFT                            0x00000009
#define	RS_IP_5__SEL_S__SHIFT                              0x0000000d
#define	RS_IP_5__SEL_T__SHIFT                              0x00000010
#define	RS_IP_5__SEL_R__SHIFT                              0x00000013
#define	RS_IP_5__SEL_Q__SHIFT                              0x00000016

// RS_IP_6
#define	RS_IP_6__TEX_PTR__SHIFT                            0x00000000
#define	RS_IP_6__COL_PTR__SHIFT                            0x00000006
#define	RS_IP_6__COL_FMT__SHIFT                            0x00000009
#define	RS_IP_6__SEL_S__SHIFT                              0x0000000d
#define	RS_IP_6__SEL_T__SHIFT                              0x00000010
#define	RS_IP_6__SEL_R__SHIFT                              0x00000013
#define	RS_IP_6__SEL_Q__SHIFT                              0x00000016

// RS_IP_7
#define	RS_IP_7__TEX_PTR__SHIFT                            0x00000000
#define	RS_IP_7__COL_PTR__SHIFT                            0x00000006
#define	RS_IP_7__COL_FMT__SHIFT                            0x00000009
#define	RS_IP_7__SEL_S__SHIFT                              0x0000000d
#define	RS_IP_7__SEL_T__SHIFT                              0x00000010
#define	RS_IP_7__SEL_R__SHIFT                              0x00000013
#define	RS_IP_7__SEL_Q__SHIFT                              0x00000016

// RS_INST_COUNT
#define	RS_INST_COUNT__INST_COUNT__SHIFT                   0x00000000
#define	RS_INST_COUNT__W_EN__SHIFT                         0x00000004
#define	RS_INST_COUNT__TX_OFFSET__SHIFT                    0x00000005

// RS_PERF
#define	RS_PERF__PERF0__SHIFT                              0x00000000
#define	RS_PERF__PERF1__SHIFT                              0x00000004
#define	RS_PERF__PERF2__SHIFT                              0x00000008
#define	RS_PERF__PERF3__SHIFT                              0x0000000c
#define	RS_PERF__RS_US_BREAK__SHIFT                        0x00000010

// RS_INST_0
#define	RS_INST_0__TEX_ID__SHIFT                           0x00000000
#define	RS_INST_0__TEX_CN__SHIFT                           0x00000003
#define	RS_INST_0__TEX_ADDR__SHIFT                         0x00000006
#define	RS_INST_0__COL_ID__SHIFT                           0x0000000b
#define	RS_INST_0__COL_CN__SHIFT                           0x0000000e
#define	RS_INST_0__COL_ADDR__SHIFT                         0x00000011
#define	RS_INST_0__TEX_ADJ__SHIFT                          0x00000016
#define	RS_INST_0__COL_BIAS__SHIFT                         0x00000017

// RS_INST_1
#define	RS_INST_1__TEX_ID__SHIFT                           0x00000000
#define	RS_INST_1__TEX_CN__SHIFT                           0x00000003
#define	RS_INST_1__TEX_ADDR__SHIFT                         0x00000006
#define	RS_INST_1__COL_ID__SHIFT                           0x0000000b
#define	RS_INST_1__COL_CN__SHIFT                           0x0000000e
#define	RS_INST_1__COL_ADDR__SHIFT                         0x00000011
#define	RS_INST_1__TEX_ADJ__SHIFT                          0x00000016
#define	RS_INST_1__COL_BIAS__SHIFT                         0x00000017

// RS_INST_2
#define	RS_INST_2__TEX_ID__SHIFT                           0x00000000
#define	RS_INST_2__TEX_CN__SHIFT                           0x00000003
#define	RS_INST_2__TEX_ADDR__SHIFT                         0x00000006
#define	RS_INST_2__COL_ID__SHIFT                           0x0000000b
#define	RS_INST_2__COL_CN__SHIFT                           0x0000000e
#define	RS_INST_2__COL_ADDR__SHIFT                         0x00000011
#define	RS_INST_2__TEX_ADJ__SHIFT                          0x00000016
#define	RS_INST_2__COL_BIAS__SHIFT                         0x00000017

// RS_INST_3
#define	RS_INST_3__TEX_ID__SHIFT                           0x00000000
#define	RS_INST_3__TEX_CN__SHIFT                           0x00000003
#define	RS_INST_3__TEX_ADDR__SHIFT                         0x00000006
#define	RS_INST_3__COL_ID__SHIFT                           0x0000000b
#define	RS_INST_3__COL_CN__SHIFT                           0x0000000e
#define	RS_INST_3__COL_ADDR__SHIFT                         0x00000011
#define	RS_INST_3__TEX_ADJ__SHIFT                          0x00000016
#define	RS_INST_3__COL_BIAS__SHIFT                         0x00000017

// RS_INST_4
#define	RS_INST_4__TEX_ID__SHIFT                           0x00000000
#define	RS_INST_4__TEX_CN__SHIFT                           0x00000003
#define	RS_INST_4__TEX_ADDR__SHIFT                         0x00000006
#define	RS_INST_4__COL_ID__SHIFT                           0x0000000b
#define	RS_INST_4__COL_CN__SHIFT                           0x0000000e
#define	RS_INST_4__COL_ADDR__SHIFT                         0x00000011
#define	RS_INST_4__TEX_ADJ__SHIFT                          0x00000016
#define	RS_INST_4__COL_BIAS__SHIFT                         0x00000017

// RS_INST_5
#define	RS_INST_5__TEX_ID__SHIFT                           0x00000000
#define	RS_INST_5__TEX_CN__SHIFT                           0x00000003
#define	RS_INST_5__TEX_ADDR__SHIFT                         0x00000006
#define	RS_INST_5__COL_ID__SHIFT                           0x0000000b
#define	RS_INST_5__COL_CN__SHIFT                           0x0000000e
#define	RS_INST_5__COL_ADDR__SHIFT                         0x00000011
#define	RS_INST_5__TEX_ADJ__SHIFT                          0x00000016
#define	RS_INST_5__COL_BIAS__SHIFT                         0x00000017

// RS_INST_6
#define	RS_INST_6__TEX_ID__SHIFT                           0x00000000
#define	RS_INST_6__TEX_CN__SHIFT                           0x00000003
#define	RS_INST_6__TEX_ADDR__SHIFT                         0x00000006
#define	RS_INST_6__COL_ID__SHIFT                           0x0000000b
#define	RS_INST_6__COL_CN__SHIFT                           0x0000000e
#define	RS_INST_6__COL_ADDR__SHIFT                         0x00000011
#define	RS_INST_6__TEX_ADJ__SHIFT                          0x00000016
#define	RS_INST_6__COL_BIAS__SHIFT                         0x00000017

// RS_INST_7
#define	RS_INST_7__TEX_ID__SHIFT                           0x00000000
#define	RS_INST_7__TEX_CN__SHIFT                           0x00000003
#define	RS_INST_7__TEX_ADDR__SHIFT                         0x00000006
#define	RS_INST_7__COL_ID__SHIFT                           0x0000000b
#define	RS_INST_7__COL_CN__SHIFT                           0x0000000e
#define	RS_INST_7__COL_ADDR__SHIFT                         0x00000011
#define	RS_INST_7__TEX_ADJ__SHIFT                          0x00000016
#define	RS_INST_7__COL_BIAS__SHIFT                         0x00000017

// RS_INST_8
#define	RS_INST_8__TEX_ID__SHIFT                           0x00000000
#define	RS_INST_8__TEX_CN__SHIFT                           0x00000003
#define	RS_INST_8__TEX_ADDR__SHIFT                         0x00000006
#define	RS_INST_8__COL_ID__SHIFT                           0x0000000b
#define	RS_INST_8__COL_CN__SHIFT                           0x0000000e
#define	RS_INST_8__COL_ADDR__SHIFT                         0x00000011
#define	RS_INST_8__TEX_ADJ__SHIFT                          0x00000016
#define	RS_INST_8__COL_BIAS__SHIFT                         0x00000017

// RS_INST_9
#define	RS_INST_9__TEX_ID__SHIFT                           0x00000000
#define	RS_INST_9__TEX_CN__SHIFT                           0x00000003
#define	RS_INST_9__TEX_ADDR__SHIFT                         0x00000006
#define	RS_INST_9__COL_ID__SHIFT                           0x0000000b
#define	RS_INST_9__COL_CN__SHIFT                           0x0000000e
#define	RS_INST_9__COL_ADDR__SHIFT                         0x00000011
#define	RS_INST_9__TEX_ADJ__SHIFT                          0x00000016
#define	RS_INST_9__COL_BIAS__SHIFT                         0x00000017

// RS_INST_10
#define	RS_INST_10__TEX_ID__SHIFT                          0x00000000
#define	RS_INST_10__TEX_CN__SHIFT                          0x00000003
#define	RS_INST_10__TEX_ADDR__SHIFT                        0x00000006
#define	RS_INST_10__COL_ID__SHIFT                          0x0000000b
#define	RS_INST_10__COL_CN__SHIFT                          0x0000000e
#define	RS_INST_10__COL_ADDR__SHIFT                        0x00000011
#define	RS_INST_10__TEX_ADJ__SHIFT                         0x00000016
#define	RS_INST_10__COL_BIAS__SHIFT                        0x00000017

// RS_INST_11
#define	RS_INST_11__TEX_ID__SHIFT                          0x00000000
#define	RS_INST_11__TEX_CN__SHIFT                          0x00000003
#define	RS_INST_11__TEX_ADDR__SHIFT                        0x00000006
#define	RS_INST_11__COL_ID__SHIFT                          0x0000000b
#define	RS_INST_11__COL_CN__SHIFT                          0x0000000e
#define	RS_INST_11__COL_ADDR__SHIFT                        0x00000011
#define	RS_INST_11__TEX_ADJ__SHIFT                         0x00000016
#define	RS_INST_11__COL_BIAS__SHIFT                        0x00000017

// RS_INST_12
#define	RS_INST_12__TEX_ID__SHIFT                          0x00000000
#define	RS_INST_12__TEX_CN__SHIFT                          0x00000003
#define	RS_INST_12__TEX_ADDR__SHIFT                        0x00000006
#define	RS_INST_12__COL_ID__SHIFT                          0x0000000b
#define	RS_INST_12__COL_CN__SHIFT                          0x0000000e
#define	RS_INST_12__COL_ADDR__SHIFT                        0x00000011
#define	RS_INST_12__TEX_ADJ__SHIFT                         0x00000016
#define	RS_INST_12__COL_BIAS__SHIFT                        0x00000017

// RS_INST_13
#define	RS_INST_13__TEX_ID__SHIFT                          0x00000000
#define	RS_INST_13__TEX_CN__SHIFT                          0x00000003
#define	RS_INST_13__TEX_ADDR__SHIFT                        0x00000006
#define	RS_INST_13__COL_ID__SHIFT                          0x0000000b
#define	RS_INST_13__COL_CN__SHIFT                          0x0000000e
#define	RS_INST_13__COL_ADDR__SHIFT                        0x00000011
#define	RS_INST_13__TEX_ADJ__SHIFT                         0x00000016
#define	RS_INST_13__COL_BIAS__SHIFT                        0x00000017

// RS_INST_14
#define	RS_INST_14__TEX_ID__SHIFT                          0x00000000
#define	RS_INST_14__TEX_CN__SHIFT                          0x00000003
#define	RS_INST_14__TEX_ADDR__SHIFT                        0x00000006
#define	RS_INST_14__COL_ID__SHIFT                          0x0000000b
#define	RS_INST_14__COL_CN__SHIFT                          0x0000000e
#define	RS_INST_14__COL_ADDR__SHIFT                        0x00000011
#define	RS_INST_14__TEX_ADJ__SHIFT                         0x00000016
#define	RS_INST_14__COL_BIAS__SHIFT                        0x00000017

// RS_INST_15
#define	RS_INST_15__TEX_ID__SHIFT                          0x00000000
#define	RS_INST_15__TEX_CN__SHIFT                          0x00000003
#define	RS_INST_15__TEX_ADDR__SHIFT                        0x00000006
#define	RS_INST_15__COL_ID__SHIFT                          0x0000000b
#define	RS_INST_15__COL_CN__SHIFT                          0x0000000e
#define	RS_INST_15__COL_ADDR__SHIFT                        0x00000011
#define	RS_INST_15__TEX_ADJ__SHIFT                         0x00000016
#define	RS_INST_15__COL_BIAS__SHIFT                        0x00000017

// SC_HYPERZ_EN
#define	SC_HYPERZ_EN__HZ_EN__SHIFT                         0x00000000
#define	SC_HYPERZ_EN__HZ_MAX__SHIFT                        0x00000001
#define	SC_HYPERZ_EN__HZ_ADJ__SHIFT                        0x00000002
#define	SC_HYPERZ_EN__HZ_Z0MIN__SHIFT                      0x00000005
#define	SC_HYPERZ_EN__HZ_Z0MAX__SHIFT                      0x00000006

// SC_EDGERULE
#define	SC_EDGERULE__ER_TRI__SHIFT                         0x00000000
#define	SC_EDGERULE__ER_POINT__SHIFT                       0x00000005
#define	SC_EDGERULE__ER_LINE_LR__SHIFT                     0x0000000a
#define	SC_EDGERULE__ER_LINE_RL__SHIFT                     0x0000000f
#define	SC_EDGERULE__ER_LINE_TB__SHIFT                     0x00000014
#define	SC_EDGERULE__ER_LINE_BT__SHIFT                     0x00000019

// SC_PERF
#define	SC_PERF__MOD0__SHIFT                               0x00000000
#define	SC_PERF__MOD1__SHIFT                               0x00000002
#define	SC_PERF__MOD2__SHIFT                               0x00000004
#define	SC_PERF__MOD3__SHIFT                               0x00000006
#define	SC_PERF__PERF0__SHIFT                              0x00000008
#define	SC_PERF__PERF1__SHIFT                              0x0000000e
#define	SC_PERF__PERF2__SHIFT                              0x00000014
#define	SC_PERF__PERF3__SHIFT                              0x0000001a

// SC_CLIP_0_A
#define	SC_CLIP_0_A__XS0__SHIFT                            0x00000000
#define	SC_CLIP_0_A__YS0__SHIFT                            0x0000000d

// SC_CLIP_1_A
#define	SC_CLIP_1_A__XS0__SHIFT                            0x00000000
#define	SC_CLIP_1_A__YS0__SHIFT                            0x0000000d

// SC_CLIP_2_A
#define	SC_CLIP_2_A__XS0__SHIFT                            0x00000000
#define	SC_CLIP_2_A__YS0__SHIFT                            0x0000000d

// SC_CLIP_3_A
#define	SC_CLIP_3_A__XS0__SHIFT                            0x00000000
#define	SC_CLIP_3_A__YS0__SHIFT                            0x0000000d

// SC_CLIP_0_B
#define	SC_CLIP_0_B__XS1__SHIFT                            0x00000000
#define	SC_CLIP_0_B__YS1__SHIFT                            0x0000000d

// SC_CLIP_1_B
#define	SC_CLIP_1_B__XS1__SHIFT                            0x00000000
#define	SC_CLIP_1_B__YS1__SHIFT                            0x0000000d

// SC_CLIP_2_B
#define	SC_CLIP_2_B__XS1__SHIFT                            0x00000000
#define	SC_CLIP_2_B__YS1__SHIFT                            0x0000000d

// SC_CLIP_3_B
#define	SC_CLIP_3_B__XS1__SHIFT                            0x00000000
#define	SC_CLIP_3_B__YS1__SHIFT                            0x0000000d

// SC_CLIP_RULE
#define	SC_CLIP_RULE__CLIP_RULE__SHIFT                     0x00000000

// SC_SCISSOR0
#define	SC_SCISSOR0__XS0__SHIFT                            0x00000000
#define	SC_SCISSOR0__YS0__SHIFT                            0x0000000d

// SC_SCISSOR1
#define	SC_SCISSOR1__XS1__SHIFT                            0x00000000
#define	SC_SCISSOR1__YS1__SHIFT                            0x0000000d

// SC_SCREENDOOR
#define	SC_SCREENDOOR__SCREENDOOR__SHIFT                   0x00000000

// TX_FILTER0_0
#define	TX_FILTER0_0__CLAMP_S__SHIFT                       0x00000000
#define	TX_FILTER0_0__CLAMP_T__SHIFT                       0x00000003
#define	TX_FILTER0_0__CLAMP_R__SHIFT                       0x00000006
#define	TX_FILTER0_0__MAG_FILTER__SHIFT                    0x00000009
#define	TX_FILTER0_0__MIN_FILTER__SHIFT                    0x0000000b
#define	TX_FILTER0_0__MIP_FILTER__SHIFT                    0x0000000d
#define	TX_FILTER0_0__VOL_FILTER__SHIFT                    0x0000000f
#define	TX_FILTER0_0__MAX_MIP_LEVEL__SHIFT                 0x00000011
#define	TX_FILTER0_0__MAX_ANIS__SHIFT                      0x00000015
#define	TX_FILTER0_0__ID__SHIFT                            0x0000001c

// TX_FILTER0_1
#define	TX_FILTER0_1__CLAMP_S__SHIFT                       0x00000000
#define	TX_FILTER0_1__CLAMP_T__SHIFT                       0x00000003
#define	TX_FILTER0_1__CLAMP_R__SHIFT                       0x00000006
#define	TX_FILTER0_1__MAG_FILTER__SHIFT                    0x00000009
#define	TX_FILTER0_1__MIN_FILTER__SHIFT                    0x0000000b
#define	TX_FILTER0_1__MIP_FILTER__SHIFT                    0x0000000d
#define	TX_FILTER0_1__VOL_FILTER__SHIFT                    0x0000000f
#define	TX_FILTER0_1__MAX_MIP_LEVEL__SHIFT                 0x00000011
#define	TX_FILTER0_1__MAX_ANIS__SHIFT                      0x00000015
#define	TX_FILTER0_1__ID__SHIFT                            0x0000001c

// TX_FILTER0_2
#define	TX_FILTER0_2__CLAMP_S__SHIFT                       0x00000000
#define	TX_FILTER0_2__CLAMP_T__SHIFT                       0x00000003
#define	TX_FILTER0_2__CLAMP_R__SHIFT                       0x00000006
#define	TX_FILTER0_2__MAG_FILTER__SHIFT                    0x00000009
#define	TX_FILTER0_2__MIN_FILTER__SHIFT                    0x0000000b
#define	TX_FILTER0_2__MIP_FILTER__SHIFT                    0x0000000d
#define	TX_FILTER0_2__VOL_FILTER__SHIFT                    0x0000000f
#define	TX_FILTER0_2__MAX_MIP_LEVEL__SHIFT                 0x00000011
#define	TX_FILTER0_2__MAX_ANIS__SHIFT                      0x00000015
#define	TX_FILTER0_2__ID__SHIFT                            0x0000001c

// TX_FILTER0_3
#define	TX_FILTER0_3__CLAMP_S__SHIFT                       0x00000000
#define	TX_FILTER0_3__CLAMP_T__SHIFT                       0x00000003
#define	TX_FILTER0_3__CLAMP_R__SHIFT                       0x00000006
#define	TX_FILTER0_3__MAG_FILTER__SHIFT                    0x00000009
#define	TX_FILTER0_3__MIN_FILTER__SHIFT                    0x0000000b
#define	TX_FILTER0_3__MIP_FILTER__SHIFT                    0x0000000d
#define	TX_FILTER0_3__VOL_FILTER__SHIFT                    0x0000000f
#define	TX_FILTER0_3__MAX_MIP_LEVEL__SHIFT                 0x00000011
#define	TX_FILTER0_3__MAX_ANIS__SHIFT                      0x00000015
#define	TX_FILTER0_3__ID__SHIFT                            0x0000001c

// TX_FILTER0_4
#define	TX_FILTER0_4__CLAMP_S__SHIFT                       0x00000000
#define	TX_FILTER0_4__CLAMP_T__SHIFT                       0x00000003
#define	TX_FILTER0_4__CLAMP_R__SHIFT                       0x00000006
#define	TX_FILTER0_4__MAG_FILTER__SHIFT                    0x00000009
#define	TX_FILTER0_4__MIN_FILTER__SHIFT                    0x0000000b
#define	TX_FILTER0_4__MIP_FILTER__SHIFT                    0x0000000d
#define	TX_FILTER0_4__VOL_FILTER__SHIFT                    0x0000000f
#define	TX_FILTER0_4__MAX_MIP_LEVEL__SHIFT                 0x00000011
#define	TX_FILTER0_4__MAX_ANIS__SHIFT                      0x00000015
#define	TX_FILTER0_4__ID__SHIFT                            0x0000001c

// TX_FILTER0_5
#define	TX_FILTER0_5__CLAMP_S__SHIFT                       0x00000000
#define	TX_FILTER0_5__CLAMP_T__SHIFT                       0x00000003
#define	TX_FILTER0_5__CLAMP_R__SHIFT                       0x00000006
#define	TX_FILTER0_5__MAG_FILTER__SHIFT                    0x00000009
#define	TX_FILTER0_5__MIN_FILTER__SHIFT                    0x0000000b
#define	TX_FILTER0_5__MIP_FILTER__SHIFT                    0x0000000d
#define	TX_FILTER0_5__VOL_FILTER__SHIFT                    0x0000000f
#define	TX_FILTER0_5__MAX_MIP_LEVEL__SHIFT                 0x00000011
#define	TX_FILTER0_5__MAX_ANIS__SHIFT                      0x00000015
#define	TX_FILTER0_5__ID__SHIFT                            0x0000001c

// TX_FILTER0_6
#define	TX_FILTER0_6__CLAMP_S__SHIFT                       0x00000000
#define	TX_FILTER0_6__CLAMP_T__SHIFT                       0x00000003
#define	TX_FILTER0_6__CLAMP_R__SHIFT                       0x00000006
#define	TX_FILTER0_6__MAG_FILTER__SHIFT                    0x00000009
#define	TX_FILTER0_6__MIN_FILTER__SHIFT                    0x0000000b
#define	TX_FILTER0_6__MIP_FILTER__SHIFT                    0x0000000d
#define	TX_FILTER0_6__VOL_FILTER__SHIFT                    0x0000000f
#define	TX_FILTER0_6__MAX_MIP_LEVEL__SHIFT                 0x00000011
#define	TX_FILTER0_6__MAX_ANIS__SHIFT                      0x00000015
#define	TX_FILTER0_6__ID__SHIFT                            0x0000001c

// TX_FILTER0_7
#define	TX_FILTER0_7__CLAMP_S__SHIFT                       0x00000000
#define	TX_FILTER0_7__CLAMP_T__SHIFT                       0x00000003
#define	TX_FILTER0_7__CLAMP_R__SHIFT                       0x00000006
#define	TX_FILTER0_7__MAG_FILTER__SHIFT                    0x00000009
#define	TX_FILTER0_7__MIN_FILTER__SHIFT                    0x0000000b
#define	TX_FILTER0_7__MIP_FILTER__SHIFT                    0x0000000d
#define	TX_FILTER0_7__VOL_FILTER__SHIFT                    0x0000000f
#define	TX_FILTER0_7__MAX_MIP_LEVEL__SHIFT                 0x00000011
#define	TX_FILTER0_7__MAX_ANIS__SHIFT                      0x00000015
#define	TX_FILTER0_7__ID__SHIFT                            0x0000001c

// TX_FILTER0_8
#define	TX_FILTER0_8__CLAMP_S__SHIFT                       0x00000000
#define	TX_FILTER0_8__CLAMP_T__SHIFT                       0x00000003
#define	TX_FILTER0_8__CLAMP_R__SHIFT                       0x00000006
#define	TX_FILTER0_8__MAG_FILTER__SHIFT                    0x00000009
#define	TX_FILTER0_8__MIN_FILTER__SHIFT                    0x0000000b
#define	TX_FILTER0_8__MIP_FILTER__SHIFT                    0x0000000d
#define	TX_FILTER0_8__VOL_FILTER__SHIFT                    0x0000000f
#define	TX_FILTER0_8__MAX_MIP_LEVEL__SHIFT                 0x00000011
#define	TX_FILTER0_8__MAX_ANIS__SHIFT                      0x00000015
#define	TX_FILTER0_8__ID__SHIFT                            0x0000001c

// TX_FILTER0_9
#define	TX_FILTER0_9__CLAMP_S__SHIFT                       0x00000000
#define	TX_FILTER0_9__CLAMP_T__SHIFT                       0x00000003
#define	TX_FILTER0_9__CLAMP_R__SHIFT                       0x00000006
#define	TX_FILTER0_9__MAG_FILTER__SHIFT                    0x00000009
#define	TX_FILTER0_9__MIN_FILTER__SHIFT                    0x0000000b
#define	TX_FILTER0_9__MIP_FILTER__SHIFT                    0x0000000d
#define	TX_FILTER0_9__VOL_FILTER__SHIFT                    0x0000000f
#define	TX_FILTER0_9__MAX_MIP_LEVEL__SHIFT                 0x00000011
#define	TX_FILTER0_9__MAX_ANIS__SHIFT                      0x00000015
#define	TX_FILTER0_9__ID__SHIFT                            0x0000001c

// TX_FILTER0_10
#define	TX_FILTER0_10__CLAMP_S__SHIFT                      0x00000000
#define	TX_FILTER0_10__CLAMP_T__SHIFT                      0x00000003
#define	TX_FILTER0_10__CLAMP_R__SHIFT                      0x00000006
#define	TX_FILTER0_10__MAG_FILTER__SHIFT                   0x00000009
#define	TX_FILTER0_10__MIN_FILTER__SHIFT                   0x0000000b
#define	TX_FILTER0_10__MIP_FILTER__SHIFT                   0x0000000d
#define	TX_FILTER0_10__VOL_FILTER__SHIFT                   0x0000000f
#define	TX_FILTER0_10__MAX_MIP_LEVEL__SHIFT                0x00000011
#define	TX_FILTER0_10__MAX_ANIS__SHIFT                     0x00000015
#define	TX_FILTER0_10__ID__SHIFT                           0x0000001c

// TX_FILTER0_11
#define	TX_FILTER0_11__CLAMP_S__SHIFT                      0x00000000
#define	TX_FILTER0_11__CLAMP_T__SHIFT                      0x00000003
#define	TX_FILTER0_11__CLAMP_R__SHIFT                      0x00000006
#define	TX_FILTER0_11__MAG_FILTER__SHIFT                   0x00000009
#define	TX_FILTER0_11__MIN_FILTER__SHIFT                   0x0000000b
#define	TX_FILTER0_11__MIP_FILTER__SHIFT                   0x0000000d
#define	TX_FILTER0_11__VOL_FILTER__SHIFT                   0x0000000f
#define	TX_FILTER0_11__MAX_MIP_LEVEL__SHIFT                0x00000011
#define	TX_FILTER0_11__MAX_ANIS__SHIFT                     0x00000015
#define	TX_FILTER0_11__ID__SHIFT                           0x0000001c

// TX_FILTER0_12
#define	TX_FILTER0_12__CLAMP_S__SHIFT                      0x00000000
#define	TX_FILTER0_12__CLAMP_T__SHIFT                      0x00000003
#define	TX_FILTER0_12__CLAMP_R__SHIFT                      0x00000006
#define	TX_FILTER0_12__MAG_FILTER__SHIFT                   0x00000009
#define	TX_FILTER0_12__MIN_FILTER__SHIFT                   0x0000000b
#define	TX_FILTER0_12__MIP_FILTER__SHIFT                   0x0000000d
#define	TX_FILTER0_12__VOL_FILTER__SHIFT                   0x0000000f
#define	TX_FILTER0_12__MAX_MIP_LEVEL__SHIFT                0x00000011
#define	TX_FILTER0_12__MAX_ANIS__SHIFT                     0x00000015
#define	TX_FILTER0_12__ID__SHIFT                           0x0000001c

// TX_FILTER0_13
#define	TX_FILTER0_13__CLAMP_S__SHIFT                      0x00000000
#define	TX_FILTER0_13__CLAMP_T__SHIFT                      0x00000003
#define	TX_FILTER0_13__CLAMP_R__SHIFT                      0x00000006
#define	TX_FILTER0_13__MAG_FILTER__SHIFT                   0x00000009
#define	TX_FILTER0_13__MIN_FILTER__SHIFT                   0x0000000b
#define	TX_FILTER0_13__MIP_FILTER__SHIFT                   0x0000000d
#define	TX_FILTER0_13__VOL_FILTER__SHIFT                   0x0000000f
#define	TX_FILTER0_13__MAX_MIP_LEVEL__SHIFT                0x00000011
#define	TX_FILTER0_13__MAX_ANIS__SHIFT                     0x00000015
#define	TX_FILTER0_13__ID__SHIFT                           0x0000001c

// TX_FILTER0_14
#define	TX_FILTER0_14__CLAMP_S__SHIFT                      0x00000000
#define	TX_FILTER0_14__CLAMP_T__SHIFT                      0x00000003
#define	TX_FILTER0_14__CLAMP_R__SHIFT                      0x00000006
#define	TX_FILTER0_14__MAG_FILTER__SHIFT                   0x00000009
#define	TX_FILTER0_14__MIN_FILTER__SHIFT                   0x0000000b
#define	TX_FILTER0_14__MIP_FILTER__SHIFT                   0x0000000d
#define	TX_FILTER0_14__VOL_FILTER__SHIFT                   0x0000000f
#define	TX_FILTER0_14__MAX_MIP_LEVEL__SHIFT                0x00000011
#define	TX_FILTER0_14__MAX_ANIS__SHIFT                     0x00000015
#define	TX_FILTER0_14__ID__SHIFT                           0x0000001c

// TX_FILTER0_15
#define	TX_FILTER0_15__CLAMP_S__SHIFT                      0x00000000
#define	TX_FILTER0_15__CLAMP_T__SHIFT                      0x00000003
#define	TX_FILTER0_15__CLAMP_R__SHIFT                      0x00000006
#define	TX_FILTER0_15__MAG_FILTER__SHIFT                   0x00000009
#define	TX_FILTER0_15__MIN_FILTER__SHIFT                   0x0000000b
#define	TX_FILTER0_15__MIP_FILTER__SHIFT                   0x0000000d
#define	TX_FILTER0_15__VOL_FILTER__SHIFT                   0x0000000f
#define	TX_FILTER0_15__MAX_MIP_LEVEL__SHIFT                0x00000011
#define	TX_FILTER0_15__MAX_ANIS__SHIFT                     0x00000015
#define	TX_FILTER0_15__ID__SHIFT                           0x0000001c

// TX_FILTER1_0
#define	TX_FILTER1_0__CHROMA_KEY_MODE__SHIFT               0x00000000
#define	TX_FILTER1_0__MC_ROUND__SHIFT                      0x00000002
#define	TX_FILTER1_0__LOD_BIAS__SHIFT                      0x00000003
#define	TX_FILTER1_0__EDGE_ANIS__SHIFT                     0x0000000d
#define	TX_FILTER1_0__MC_COORD_TRUNCATE__SHIFT             0x0000000e
#define	TX_FILTER1_0__TRI_PERF__SHIFT                      0x0000000f
#define	TX_FILTER1_0__ANISO_THRESHOLD__SHIFT               0x00000011

// TX_FILTER1_1
#define	TX_FILTER1_1__CHROMA_KEY_MODE__SHIFT               0x00000000
#define	TX_FILTER1_1__MC_ROUND__SHIFT                      0x00000002
#define	TX_FILTER1_1__LOD_BIAS__SHIFT                      0x00000003
#define	TX_FILTER1_1__EDGE_ANIS__SHIFT                     0x0000000d
#define	TX_FILTER1_1__MC_COORD_TRUNCATE__SHIFT             0x0000000e
#define	TX_FILTER1_1__TRI_PERF__SHIFT                      0x0000000f
#define	TX_FILTER1_1__ANISO_THRESHOLD__SHIFT               0x00000011

// TX_FILTER1_2
#define	TX_FILTER1_2__CHROMA_KEY_MODE__SHIFT               0x00000000
#define	TX_FILTER1_2__MC_ROUND__SHIFT                      0x00000002
#define	TX_FILTER1_2__LOD_BIAS__SHIFT                      0x00000003
#define	TX_FILTER1_2__EDGE_ANIS__SHIFT                     0x0000000d
#define	TX_FILTER1_2__MC_COORD_TRUNCATE__SHIFT             0x0000000e
#define	TX_FILTER1_2__TRI_PERF__SHIFT                      0x0000000f
#define	TX_FILTER1_2__ANISO_THRESHOLD__SHIFT               0x00000011

// TX_FILTER1_3
#define	TX_FILTER1_3__CHROMA_KEY_MODE__SHIFT               0x00000000
#define	TX_FILTER1_3__MC_ROUND__SHIFT                      0x00000002
#define	TX_FILTER1_3__LOD_BIAS__SHIFT                      0x00000003
#define	TX_FILTER1_3__EDGE_ANIS__SHIFT                     0x0000000d
#define	TX_FILTER1_3__MC_COORD_TRUNCATE__SHIFT             0x0000000e
#define	TX_FILTER1_3__TRI_PERF__SHIFT                      0x0000000f
#define	TX_FILTER1_3__ANISO_THRESHOLD__SHIFT               0x00000011

// TX_FILTER1_4
#define	TX_FILTER1_4__CHROMA_KEY_MODE__SHIFT               0x00000000
#define	TX_FILTER1_4__MC_ROUND__SHIFT                      0x00000002
#define	TX_FILTER1_4__LOD_BIAS__SHIFT                      0x00000003
#define	TX_FILTER1_4__EDGE_ANIS__SHIFT                     0x0000000d
#define	TX_FILTER1_4__MC_COORD_TRUNCATE__SHIFT             0x0000000e
#define	TX_FILTER1_4__TRI_PERF__SHIFT                      0x0000000f
#define	TX_FILTER1_4__ANISO_THRESHOLD__SHIFT               0x00000011

// TX_FILTER1_5
#define	TX_FILTER1_5__CHROMA_KEY_MODE__SHIFT               0x00000000
#define	TX_FILTER1_5__MC_ROUND__SHIFT                      0x00000002
#define	TX_FILTER1_5__LOD_BIAS__SHIFT                      0x00000003
#define	TX_FILTER1_5__EDGE_ANIS__SHIFT                     0x0000000d
#define	TX_FILTER1_5__MC_COORD_TRUNCATE__SHIFT             0x0000000e
#define	TX_FILTER1_5__TRI_PERF__SHIFT                      0x0000000f
#define	TX_FILTER1_5__ANISO_THRESHOLD__SHIFT               0x00000011

// TX_FILTER1_6
#define	TX_FILTER1_6__CHROMA_KEY_MODE__SHIFT               0x00000000
#define	TX_FILTER1_6__MC_ROUND__SHIFT                      0x00000002
#define	TX_FILTER1_6__LOD_BIAS__SHIFT                      0x00000003
#define	TX_FILTER1_6__EDGE_ANIS__SHIFT                     0x0000000d
#define	TX_FILTER1_6__MC_COORD_TRUNCATE__SHIFT             0x0000000e
#define	TX_FILTER1_6__TRI_PERF__SHIFT                      0x0000000f
#define	TX_FILTER1_6__ANISO_THRESHOLD__SHIFT               0x00000011

// TX_FILTER1_7
#define	TX_FILTER1_7__CHROMA_KEY_MODE__SHIFT               0x00000000
#define	TX_FILTER1_7__MC_ROUND__SHIFT                      0x00000002
#define	TX_FILTER1_7__LOD_BIAS__SHIFT                      0x00000003
#define	TX_FILTER1_7__EDGE_ANIS__SHIFT                     0x0000000d
#define	TX_FILTER1_7__MC_COORD_TRUNCATE__SHIFT             0x0000000e
#define	TX_FILTER1_7__TRI_PERF__SHIFT                      0x0000000f
#define	TX_FILTER1_7__ANISO_THRESHOLD__SHIFT               0x00000011

// TX_FILTER1_8
#define	TX_FILTER1_8__CHROMA_KEY_MODE__SHIFT               0x00000000
#define	TX_FILTER1_8__MC_ROUND__SHIFT                      0x00000002
#define	TX_FILTER1_8__LOD_BIAS__SHIFT                      0x00000003
#define	TX_FILTER1_8__EDGE_ANIS__SHIFT                     0x0000000d
#define	TX_FILTER1_8__MC_COORD_TRUNCATE__SHIFT             0x0000000e
#define	TX_FILTER1_8__TRI_PERF__SHIFT                      0x0000000f
#define	TX_FILTER1_8__ANISO_THRESHOLD__SHIFT               0x00000011

// TX_FILTER1_9
#define	TX_FILTER1_9__CHROMA_KEY_MODE__SHIFT               0x00000000
#define	TX_FILTER1_9__MC_ROUND__SHIFT                      0x00000002
#define	TX_FILTER1_9__LOD_BIAS__SHIFT                      0x00000003
#define	TX_FILTER1_9__EDGE_ANIS__SHIFT                     0x0000000d
#define	TX_FILTER1_9__MC_COORD_TRUNCATE__SHIFT             0x0000000e
#define	TX_FILTER1_9__TRI_PERF__SHIFT                      0x0000000f
#define	TX_FILTER1_9__ANISO_THRESHOLD__SHIFT               0x00000011

// TX_FILTER1_10
#define	TX_FILTER1_10__CHROMA_KEY_MODE__SHIFT              0x00000000
#define	TX_FILTER1_10__MC_ROUND__SHIFT                     0x00000002
#define	TX_FILTER1_10__LOD_BIAS__SHIFT                     0x00000003
#define	TX_FILTER1_10__EDGE_ANIS__SHIFT                    0x0000000d
#define	TX_FILTER1_10__MC_COORD_TRUNCATE__SHIFT            0x0000000e
#define	TX_FILTER1_10__TRI_PERF__SHIFT                     0x0000000f
#define	TX_FILTER1_10__ANISO_THRESHOLD__SHIFT              0x00000011

// TX_FILTER1_11
#define	TX_FILTER1_11__CHROMA_KEY_MODE__SHIFT              0x00000000
#define	TX_FILTER1_11__MC_ROUND__SHIFT                     0x00000002
#define	TX_FILTER1_11__LOD_BIAS__SHIFT                     0x00000003
#define	TX_FILTER1_11__EDGE_ANIS__SHIFT                    0x0000000d
#define	TX_FILTER1_11__MC_COORD_TRUNCATE__SHIFT            0x0000000e
#define	TX_FILTER1_11__TRI_PERF__SHIFT                     0x0000000f
#define	TX_FILTER1_11__ANISO_THRESHOLD__SHIFT              0x00000011

// TX_FILTER1_12
#define	TX_FILTER1_12__CHROMA_KEY_MODE__SHIFT              0x00000000
#define	TX_FILTER1_12__MC_ROUND__SHIFT                     0x00000002
#define	TX_FILTER1_12__LOD_BIAS__SHIFT                     0x00000003
#define	TX_FILTER1_12__EDGE_ANIS__SHIFT                    0x0000000d
#define	TX_FILTER1_12__MC_COORD_TRUNCATE__SHIFT            0x0000000e
#define	TX_FILTER1_12__TRI_PERF__SHIFT                     0x0000000f
#define	TX_FILTER1_12__ANISO_THRESHOLD__SHIFT              0x00000011

// TX_FILTER1_13
#define	TX_FILTER1_13__CHROMA_KEY_MODE__SHIFT              0x00000000
#define	TX_FILTER1_13__MC_ROUND__SHIFT                     0x00000002
#define	TX_FILTER1_13__LOD_BIAS__SHIFT                     0x00000003
#define	TX_FILTER1_13__EDGE_ANIS__SHIFT                    0x0000000d
#define	TX_FILTER1_13__MC_COORD_TRUNCATE__SHIFT            0x0000000e
#define	TX_FILTER1_13__TRI_PERF__SHIFT                     0x0000000f
#define	TX_FILTER1_13__ANISO_THRESHOLD__SHIFT              0x00000011

// TX_FILTER1_14
#define	TX_FILTER1_14__CHROMA_KEY_MODE__SHIFT              0x00000000
#define	TX_FILTER1_14__MC_ROUND__SHIFT                     0x00000002
#define	TX_FILTER1_14__LOD_BIAS__SHIFT                     0x00000003
#define	TX_FILTER1_14__EDGE_ANIS__SHIFT                    0x0000000d
#define	TX_FILTER1_14__MC_COORD_TRUNCATE__SHIFT            0x0000000e
#define	TX_FILTER1_14__TRI_PERF__SHIFT                     0x0000000f
#define	TX_FILTER1_14__ANISO_THRESHOLD__SHIFT              0x00000011

// TX_FILTER1_15
#define	TX_FILTER1_15__CHROMA_KEY_MODE__SHIFT              0x00000000
#define	TX_FILTER1_15__MC_ROUND__SHIFT                     0x00000002
#define	TX_FILTER1_15__LOD_BIAS__SHIFT                     0x00000003
#define	TX_FILTER1_15__EDGE_ANIS__SHIFT                    0x0000000d
#define	TX_FILTER1_15__MC_COORD_TRUNCATE__SHIFT            0x0000000e
#define	TX_FILTER1_15__TRI_PERF__SHIFT                     0x0000000f
#define	TX_FILTER1_15__ANISO_THRESHOLD__SHIFT              0x00000011

// TX_FORMAT0_0
#define	TX_FORMAT0_0__TXWIDTH__SHIFT                       0x00000000
#define	TX_FORMAT0_0__TXHEIGHT__SHIFT                      0x0000000b
#define	TX_FORMAT0_0__TXDEPTH__SHIFT                       0x00000016
#define	TX_FORMAT0_0__NUM_LEVELS__SHIFT                    0x0000001a
#define	TX_FORMAT0_0__PROJECTED__SHIFT                     0x0000001e
#define	TX_FORMAT0_0__TXPITCH_EN__SHIFT                    0x0000001f

// TX_FORMAT0_1
#define	TX_FORMAT0_1__TXWIDTH__SHIFT                       0x00000000
#define	TX_FORMAT0_1__TXHEIGHT__SHIFT                      0x0000000b
#define	TX_FORMAT0_1__TXDEPTH__SHIFT                       0x00000016
#define	TX_FORMAT0_1__NUM_LEVELS__SHIFT                    0x0000001a
#define	TX_FORMAT0_1__PROJECTED__SHIFT                     0x0000001e
#define	TX_FORMAT0_1__TXPITCH_EN__SHIFT                    0x0000001f

// TX_FORMAT0_2
#define	TX_FORMAT0_2__TXWIDTH__SHIFT                       0x00000000
#define	TX_FORMAT0_2__TXHEIGHT__SHIFT                      0x0000000b
#define	TX_FORMAT0_2__TXDEPTH__SHIFT                       0x00000016
#define	TX_FORMAT0_2__NUM_LEVELS__SHIFT                    0x0000001a
#define	TX_FORMAT0_2__PROJECTED__SHIFT                     0x0000001e
#define	TX_FORMAT0_2__TXPITCH_EN__SHIFT                    0x0000001f

// TX_FORMAT0_3
#define	TX_FORMAT0_3__TXWIDTH__SHIFT                       0x00000000
#define	TX_FORMAT0_3__TXHEIGHT__SHIFT                      0x0000000b
#define	TX_FORMAT0_3__TXDEPTH__SHIFT                       0x00000016
#define	TX_FORMAT0_3__NUM_LEVELS__SHIFT                    0x0000001a
#define	TX_FORMAT0_3__PROJECTED__SHIFT                     0x0000001e
#define	TX_FORMAT0_3__TXPITCH_EN__SHIFT                    0x0000001f

// TX_FORMAT0_4
#define	TX_FORMAT0_4__TXWIDTH__SHIFT                       0x00000000
#define	TX_FORMAT0_4__TXHEIGHT__SHIFT                      0x0000000b
#define	TX_FORMAT0_4__TXDEPTH__SHIFT                       0x00000016
#define	TX_FORMAT0_4__NUM_LEVELS__SHIFT                    0x0000001a
#define	TX_FORMAT0_4__PROJECTED__SHIFT                     0x0000001e
#define	TX_FORMAT0_4__TXPITCH_EN__SHIFT                    0x0000001f

// TX_FORMAT0_5
#define	TX_FORMAT0_5__TXWIDTH__SHIFT                       0x00000000
#define	TX_FORMAT0_5__TXHEIGHT__SHIFT                      0x0000000b
#define	TX_FORMAT0_5__TXDEPTH__SHIFT                       0x00000016
#define	TX_FORMAT0_5__NUM_LEVELS__SHIFT                    0x0000001a
#define	TX_FORMAT0_5__PROJECTED__SHIFT                     0x0000001e
#define	TX_FORMAT0_5__TXPITCH_EN__SHIFT                    0x0000001f

// TX_FORMAT0_6
#define	TX_FORMAT0_6__TXWIDTH__SHIFT                       0x00000000
#define	TX_FORMAT0_6__TXHEIGHT__SHIFT                      0x0000000b
#define	TX_FORMAT0_6__TXDEPTH__SHIFT                       0x00000016
#define	TX_FORMAT0_6__NUM_LEVELS__SHIFT                    0x0000001a
#define	TX_FORMAT0_6__PROJECTED__SHIFT                     0x0000001e
#define	TX_FORMAT0_6__TXPITCH_EN__SHIFT                    0x0000001f

// TX_FORMAT0_7
#define	TX_FORMAT0_7__TXWIDTH__SHIFT                       0x00000000
#define	TX_FORMAT0_7__TXHEIGHT__SHIFT                      0x0000000b
#define	TX_FORMAT0_7__TXDEPTH__SHIFT                       0x00000016
#define	TX_FORMAT0_7__NUM_LEVELS__SHIFT                    0x0000001a
#define	TX_FORMAT0_7__PROJECTED__SHIFT                     0x0000001e
#define	TX_FORMAT0_7__TXPITCH_EN__SHIFT                    0x0000001f

// TX_FORMAT0_8
#define	TX_FORMAT0_8__TXWIDTH__SHIFT                       0x00000000
#define	TX_FORMAT0_8__TXHEIGHT__SHIFT                      0x0000000b
#define	TX_FORMAT0_8__TXDEPTH__SHIFT                       0x00000016
#define	TX_FORMAT0_8__NUM_LEVELS__SHIFT                    0x0000001a
#define	TX_FORMAT0_8__PROJECTED__SHIFT                     0x0000001e
#define	TX_FORMAT0_8__TXPITCH_EN__SHIFT                    0x0000001f

// TX_FORMAT0_9
#define	TX_FORMAT0_9__TXWIDTH__SHIFT                       0x00000000
#define	TX_FORMAT0_9__TXHEIGHT__SHIFT                      0x0000000b
#define	TX_FORMAT0_9__TXDEPTH__SHIFT                       0x00000016
#define	TX_FORMAT0_9__NUM_LEVELS__SHIFT                    0x0000001a
#define	TX_FORMAT0_9__PROJECTED__SHIFT                     0x0000001e
#define	TX_FORMAT0_9__TXPITCH_EN__SHIFT                    0x0000001f

// TX_FORMAT0_10
#define	TX_FORMAT0_10__TXWIDTH__SHIFT                      0x00000000
#define	TX_FORMAT0_10__TXHEIGHT__SHIFT                     0x0000000b
#define	TX_FORMAT0_10__TXDEPTH__SHIFT                      0x00000016
#define	TX_FORMAT0_10__NUM_LEVELS__SHIFT                   0x0000001a
#define	TX_FORMAT0_10__PROJECTED__SHIFT                    0x0000001e
#define	TX_FORMAT0_10__TXPITCH_EN__SHIFT                   0x0000001f

// TX_FORMAT0_11
#define	TX_FORMAT0_11__TXWIDTH__SHIFT                      0x00000000
#define	TX_FORMAT0_11__TXHEIGHT__SHIFT                     0x0000000b
#define	TX_FORMAT0_11__TXDEPTH__SHIFT                      0x00000016
#define	TX_FORMAT0_11__NUM_LEVELS__SHIFT                   0x0000001a
#define	TX_FORMAT0_11__PROJECTED__SHIFT                    0x0000001e
#define	TX_FORMAT0_11__TXPITCH_EN__SHIFT                   0x0000001f

// TX_FORMAT0_12
#define	TX_FORMAT0_12__TXWIDTH__SHIFT                      0x00000000
#define	TX_FORMAT0_12__TXHEIGHT__SHIFT                     0x0000000b
#define	TX_FORMAT0_12__TXDEPTH__SHIFT                      0x00000016
#define	TX_FORMAT0_12__NUM_LEVELS__SHIFT                   0x0000001a
#define	TX_FORMAT0_12__PROJECTED__SHIFT                    0x0000001e
#define	TX_FORMAT0_12__TXPITCH_EN__SHIFT                   0x0000001f

// TX_FORMAT0_13
#define	TX_FORMAT0_13__TXWIDTH__SHIFT                      0x00000000
#define	TX_FORMAT0_13__TXHEIGHT__SHIFT                     0x0000000b
#define	TX_FORMAT0_13__TXDEPTH__SHIFT                      0x00000016
#define	TX_FORMAT0_13__NUM_LEVELS__SHIFT                   0x0000001a
#define	TX_FORMAT0_13__PROJECTED__SHIFT                    0x0000001e
#define	TX_FORMAT0_13__TXPITCH_EN__SHIFT                   0x0000001f

// TX_FORMAT0_14
#define	TX_FORMAT0_14__TXWIDTH__SHIFT                      0x00000000
#define	TX_FORMAT0_14__TXHEIGHT__SHIFT                     0x0000000b
#define	TX_FORMAT0_14__TXDEPTH__SHIFT                      0x00000016
#define	TX_FORMAT0_14__NUM_LEVELS__SHIFT                   0x0000001a
#define	TX_FORMAT0_14__PROJECTED__SHIFT                    0x0000001e
#define	TX_FORMAT0_14__TXPITCH_EN__SHIFT                   0x0000001f

// TX_FORMAT0_15
#define	TX_FORMAT0_15__TXWIDTH__SHIFT                      0x00000000
#define	TX_FORMAT0_15__TXHEIGHT__SHIFT                     0x0000000b
#define	TX_FORMAT0_15__TXDEPTH__SHIFT                      0x00000016
#define	TX_FORMAT0_15__NUM_LEVELS__SHIFT                   0x0000001a
#define	TX_FORMAT0_15__PROJECTED__SHIFT                    0x0000001e
#define	TX_FORMAT0_15__TXPITCH_EN__SHIFT                   0x0000001f

// TX_FORMAT1_0
#define	TX_FORMAT1_0__TXFORMAT__SHIFT                      0x00000000
#define	TX_FORMAT1_0__SIGNED_COMP0__SHIFT                  0x00000005
#define	TX_FORMAT1_0__SIGNED_COMP1__SHIFT                  0x00000006
#define	TX_FORMAT1_0__SIGNED_COMP2__SHIFT                  0x00000007
#define	TX_FORMAT1_0__SIGNED_COMP3__SHIFT                  0x00000008
#define	TX_FORMAT1_0__SEL_ALPHA__SHIFT                     0x00000009
#define	TX_FORMAT1_0__SEL_RED__SHIFT                       0x0000000c
#define	TX_FORMAT1_0__SEL_GREEN__SHIFT                     0x0000000f
#define	TX_FORMAT1_0__SEL_BLUE__SHIFT                      0x00000012
#define	TX_FORMAT1_0__GAMMA__SHIFT                         0x00000015
#define	TX_FORMAT1_0__YUV_TO_RGB__SHIFT                    0x00000016
#define	TX_FORMAT1_0__APPLE_YUV__SHIFT                     0x00000018
#define	TX_FORMAT1_0__TEX_COORD_TYPE__SHIFT                0x00000019
#define	TX_FORMAT1_0__CACHE__SHIFT                         0x0000001b

// TX_FORMAT1_1
#define	TX_FORMAT1_1__TXFORMAT__SHIFT                      0x00000000
#define	TX_FORMAT1_1__SIGNED_COMP0__SHIFT                  0x00000005
#define	TX_FORMAT1_1__SIGNED_COMP1__SHIFT                  0x00000006
#define	TX_FORMAT1_1__SIGNED_COMP2__SHIFT                  0x00000007
#define	TX_FORMAT1_1__SIGNED_COMP3__SHIFT                  0x00000008
#define	TX_FORMAT1_1__SEL_ALPHA__SHIFT                     0x00000009
#define	TX_FORMAT1_1__SEL_RED__SHIFT                       0x0000000c
#define	TX_FORMAT1_1__SEL_GREEN__SHIFT                     0x0000000f
#define	TX_FORMAT1_1__SEL_BLUE__SHIFT                      0x00000012
#define	TX_FORMAT1_1__GAMMA__SHIFT                         0x00000015
#define	TX_FORMAT1_1__YUV_TO_RGB__SHIFT                    0x00000016
#define	TX_FORMAT1_1__APPLE_YUV__SHIFT                     0x00000018
#define	TX_FORMAT1_1__TEX_COORD_TYPE__SHIFT                0x00000019
#define	TX_FORMAT1_1__CACHE__SHIFT                         0x0000001b

// TX_FORMAT1_2
#define	TX_FORMAT1_2__TXFORMAT__SHIFT                      0x00000000
#define	TX_FORMAT1_2__SIGNED_COMP0__SHIFT                  0x00000005
#define	TX_FORMAT1_2__SIGNED_COMP1__SHIFT                  0x00000006
#define	TX_FORMAT1_2__SIGNED_COMP2__SHIFT                  0x00000007
#define	TX_FORMAT1_2__SIGNED_COMP3__SHIFT                  0x00000008
#define	TX_FORMAT1_2__SEL_ALPHA__SHIFT                     0x00000009
#define	TX_FORMAT1_2__SEL_RED__SHIFT                       0x0000000c
#define	TX_FORMAT1_2__SEL_GREEN__SHIFT                     0x0000000f
#define	TX_FORMAT1_2__SEL_BLUE__SHIFT                      0x00000012
#define	TX_FORMAT1_2__GAMMA__SHIFT                         0x00000015
#define	TX_FORMAT1_2__YUV_TO_RGB__SHIFT                    0x00000016
#define	TX_FORMAT1_2__APPLE_YUV__SHIFT                     0x00000018
#define	TX_FORMAT1_2__TEX_COORD_TYPE__SHIFT                0x00000019
#define	TX_FORMAT1_2__CACHE__SHIFT                         0x0000001b

// TX_FORMAT1_3
#define	TX_FORMAT1_3__TXFORMAT__SHIFT                      0x00000000
#define	TX_FORMAT1_3__SIGNED_COMP0__SHIFT                  0x00000005
#define	TX_FORMAT1_3__SIGNED_COMP1__SHIFT                  0x00000006
#define	TX_FORMAT1_3__SIGNED_COMP2__SHIFT                  0x00000007
#define	TX_FORMAT1_3__SIGNED_COMP3__SHIFT                  0x00000008
#define	TX_FORMAT1_3__SEL_ALPHA__SHIFT                     0x00000009
#define	TX_FORMAT1_3__SEL_RED__SHIFT                       0x0000000c
#define	TX_FORMAT1_3__SEL_GREEN__SHIFT                     0x0000000f
#define	TX_FORMAT1_3__SEL_BLUE__SHIFT                      0x00000012
#define	TX_FORMAT1_3__GAMMA__SHIFT                         0x00000015
#define	TX_FORMAT1_3__YUV_TO_RGB__SHIFT                    0x00000016
#define	TX_FORMAT1_3__APPLE_YUV__SHIFT                     0x00000018
#define	TX_FORMAT1_3__TEX_COORD_TYPE__SHIFT                0x00000019
#define	TX_FORMAT1_3__CACHE__SHIFT                         0x0000001b

// TX_FORMAT1_4
#define	TX_FORMAT1_4__TXFORMAT__SHIFT                      0x00000000
#define	TX_FORMAT1_4__SIGNED_COMP0__SHIFT                  0x00000005
#define	TX_FORMAT1_4__SIGNED_COMP1__SHIFT                  0x00000006
#define	TX_FORMAT1_4__SIGNED_COMP2__SHIFT                  0x00000007
#define	TX_FORMAT1_4__SIGNED_COMP3__SHIFT                  0x00000008
#define	TX_FORMAT1_4__SEL_ALPHA__SHIFT                     0x00000009
#define	TX_FORMAT1_4__SEL_RED__SHIFT                       0x0000000c
#define	TX_FORMAT1_4__SEL_GREEN__SHIFT                     0x0000000f
#define	TX_FORMAT1_4__SEL_BLUE__SHIFT                      0x00000012
#define	TX_FORMAT1_4__GAMMA__SHIFT                         0x00000015
#define	TX_FORMAT1_4__YUV_TO_RGB__SHIFT                    0x00000016
#define	TX_FORMAT1_4__APPLE_YUV__SHIFT                     0x00000018
#define	TX_FORMAT1_4__TEX_COORD_TYPE__SHIFT                0x00000019
#define	TX_FORMAT1_4__CACHE__SHIFT                         0x0000001b

// TX_FORMAT1_5
#define	TX_FORMAT1_5__TXFORMAT__SHIFT                      0x00000000
#define	TX_FORMAT1_5__SIGNED_COMP0__SHIFT                  0x00000005
#define	TX_FORMAT1_5__SIGNED_COMP1__SHIFT                  0x00000006
#define	TX_FORMAT1_5__SIGNED_COMP2__SHIFT                  0x00000007
#define	TX_FORMAT1_5__SIGNED_COMP3__SHIFT                  0x00000008
#define	TX_FORMAT1_5__SEL_ALPHA__SHIFT                     0x00000009
#define	TX_FORMAT1_5__SEL_RED__SHIFT                       0x0000000c
#define	TX_FORMAT1_5__SEL_GREEN__SHIFT                     0x0000000f
#define	TX_FORMAT1_5__SEL_BLUE__SHIFT                      0x00000012
#define	TX_FORMAT1_5__GAMMA__SHIFT                         0x00000015
#define	TX_FORMAT1_5__YUV_TO_RGB__SHIFT                    0x00000016
#define	TX_FORMAT1_5__APPLE_YUV__SHIFT                     0x00000018
#define	TX_FORMAT1_5__TEX_COORD_TYPE__SHIFT                0x00000019
#define	TX_FORMAT1_5__CACHE__SHIFT                         0x0000001b

// TX_FORMAT1_6
#define	TX_FORMAT1_6__TXFORMAT__SHIFT                      0x00000000
#define	TX_FORMAT1_6__SIGNED_COMP0__SHIFT                  0x00000005
#define	TX_FORMAT1_6__SIGNED_COMP1__SHIFT                  0x00000006
#define	TX_FORMAT1_6__SIGNED_COMP2__SHIFT                  0x00000007
#define	TX_FORMAT1_6__SIGNED_COMP3__SHIFT                  0x00000008
#define	TX_FORMAT1_6__SEL_ALPHA__SHIFT                     0x00000009
#define	TX_FORMAT1_6__SEL_RED__SHIFT                       0x0000000c
#define	TX_FORMAT1_6__SEL_GREEN__SHIFT                     0x0000000f
#define	TX_FORMAT1_6__SEL_BLUE__SHIFT                      0x00000012
#define	TX_FORMAT1_6__GAMMA__SHIFT                         0x00000015
#define	TX_FORMAT1_6__YUV_TO_RGB__SHIFT                    0x00000016
#define	TX_FORMAT1_6__APPLE_YUV__SHIFT                     0x00000018
#define	TX_FORMAT1_6__TEX_COORD_TYPE__SHIFT                0x00000019
#define	TX_FORMAT1_6__CACHE__SHIFT                         0x0000001b

// TX_FORMAT1_7
#define	TX_FORMAT1_7__TXFORMAT__SHIFT                      0x00000000
#define	TX_FORMAT1_7__SIGNED_COMP0__SHIFT                  0x00000005
#define	TX_FORMAT1_7__SIGNED_COMP1__SHIFT                  0x00000006
#define	TX_FORMAT1_7__SIGNED_COMP2__SHIFT                  0x00000007
#define	TX_FORMAT1_7__SIGNED_COMP3__SHIFT                  0x00000008
#define	TX_FORMAT1_7__SEL_ALPHA__SHIFT                     0x00000009
#define	TX_FORMAT1_7__SEL_RED__SHIFT                       0x0000000c
#define	TX_FORMAT1_7__SEL_GREEN__SHIFT                     0x0000000f
#define	TX_FORMAT1_7__SEL_BLUE__SHIFT                      0x00000012
#define	TX_FORMAT1_7__GAMMA__SHIFT                         0x00000015
#define	TX_FORMAT1_7__YUV_TO_RGB__SHIFT                    0x00000016
#define	TX_FORMAT1_7__APPLE_YUV__SHIFT                     0x00000018
#define	TX_FORMAT1_7__TEX_COORD_TYPE__SHIFT                0x00000019
#define	TX_FORMAT1_7__CACHE__SHIFT                         0x0000001b

// TX_FORMAT1_8
#define	TX_FORMAT1_8__TXFORMAT__SHIFT                      0x00000000
#define	TX_FORMAT1_8__SIGNED_COMP0__SHIFT                  0x00000005
#define	TX_FORMAT1_8__SIGNED_COMP1__SHIFT                  0x00000006
#define	TX_FORMAT1_8__SIGNED_COMP2__SHIFT                  0x00000007
#define	TX_FORMAT1_8__SIGNED_COMP3__SHIFT                  0x00000008
#define	TX_FORMAT1_8__SEL_ALPHA__SHIFT                     0x00000009
#define	TX_FORMAT1_8__SEL_RED__SHIFT                       0x0000000c
#define	TX_FORMAT1_8__SEL_GREEN__SHIFT                     0x0000000f
#define	TX_FORMAT1_8__SEL_BLUE__SHIFT                      0x00000012
#define	TX_FORMAT1_8__GAMMA__SHIFT                         0x00000015
#define	TX_FORMAT1_8__YUV_TO_RGB__SHIFT                    0x00000016
#define	TX_FORMAT1_8__APPLE_YUV__SHIFT                     0x00000018
#define	TX_FORMAT1_8__TEX_COORD_TYPE__SHIFT                0x00000019
#define	TX_FORMAT1_8__CACHE__SHIFT                         0x0000001b

// TX_FORMAT1_9
#define	TX_FORMAT1_9__TXFORMAT__SHIFT                      0x00000000
#define	TX_FORMAT1_9__SIGNED_COMP0__SHIFT                  0x00000005
#define	TX_FORMAT1_9__SIGNED_COMP1__SHIFT                  0x00000006
#define	TX_FORMAT1_9__SIGNED_COMP2__SHIFT                  0x00000007
#define	TX_FORMAT1_9__SIGNED_COMP3__SHIFT                  0x00000008
#define	TX_FORMAT1_9__SEL_ALPHA__SHIFT                     0x00000009
#define	TX_FORMAT1_9__SEL_RED__SHIFT                       0x0000000c
#define	TX_FORMAT1_9__SEL_GREEN__SHIFT                     0x0000000f
#define	TX_FORMAT1_9__SEL_BLUE__SHIFT                      0x00000012
#define	TX_FORMAT1_9__GAMMA__SHIFT                         0x00000015
#define	TX_FORMAT1_9__YUV_TO_RGB__SHIFT                    0x00000016
#define	TX_FORMAT1_9__APPLE_YUV__SHIFT                     0x00000018
#define	TX_FORMAT1_9__TEX_COORD_TYPE__SHIFT                0x00000019
#define	TX_FORMAT1_9__CACHE__SHIFT                         0x0000001b

// TX_FORMAT1_10
#define	TX_FORMAT1_10__TXFORMAT__SHIFT                     0x00000000
#define	TX_FORMAT1_10__SIGNED_COMP0__SHIFT                 0x00000005
#define	TX_FORMAT1_10__SIGNED_COMP1__SHIFT                 0x00000006
#define	TX_FORMAT1_10__SIGNED_COMP2__SHIFT                 0x00000007
#define	TX_FORMAT1_10__SIGNED_COMP3__SHIFT                 0x00000008
#define	TX_FORMAT1_10__SEL_ALPHA__SHIFT                    0x00000009
#define	TX_FORMAT1_10__SEL_RED__SHIFT                      0x0000000c
#define	TX_FORMAT1_10__SEL_GREEN__SHIFT                    0x0000000f
#define	TX_FORMAT1_10__SEL_BLUE__SHIFT                     0x00000012
#define	TX_FORMAT1_10__GAMMA__SHIFT                        0x00000015
#define	TX_FORMAT1_10__YUV_TO_RGB__SHIFT                   0x00000016
#define	TX_FORMAT1_10__APPLE_YUV__SHIFT                    0x00000018
#define	TX_FORMAT1_10__TEX_COORD_TYPE__SHIFT               0x00000019
#define	TX_FORMAT1_10__CACHE__SHIFT                        0x0000001b

// TX_FORMAT1_11
#define	TX_FORMAT1_11__TXFORMAT__SHIFT                     0x00000000
#define	TX_FORMAT1_11__SIGNED_COMP0__SHIFT                 0x00000005
#define	TX_FORMAT1_11__SIGNED_COMP1__SHIFT                 0x00000006
#define	TX_FORMAT1_11__SIGNED_COMP2__SHIFT                 0x00000007
#define	TX_FORMAT1_11__SIGNED_COMP3__SHIFT                 0x00000008
#define	TX_FORMAT1_11__SEL_ALPHA__SHIFT                    0x00000009
#define	TX_FORMAT1_11__SEL_RED__SHIFT                      0x0000000c
#define	TX_FORMAT1_11__SEL_GREEN__SHIFT                    0x0000000f
#define	TX_FORMAT1_11__SEL_BLUE__SHIFT                     0x00000012
#define	TX_FORMAT1_11__GAMMA__SHIFT                        0x00000015
#define	TX_FORMAT1_11__YUV_TO_RGB__SHIFT                   0x00000016
#define	TX_FORMAT1_11__APPLE_YUV__SHIFT                    0x00000018
#define	TX_FORMAT1_11__TEX_COORD_TYPE__SHIFT               0x00000019
#define	TX_FORMAT1_11__CACHE__SHIFT                        0x0000001b

// TX_FORMAT1_12
#define	TX_FORMAT1_12__TXFORMAT__SHIFT                     0x00000000
#define	TX_FORMAT1_12__SIGNED_COMP0__SHIFT                 0x00000005
#define	TX_FORMAT1_12__SIGNED_COMP1__SHIFT                 0x00000006
#define	TX_FORMAT1_12__SIGNED_COMP2__SHIFT                 0x00000007
#define	TX_FORMAT1_12__SIGNED_COMP3__SHIFT                 0x00000008
#define	TX_FORMAT1_12__SEL_ALPHA__SHIFT                    0x00000009
#define	TX_FORMAT1_12__SEL_RED__SHIFT                      0x0000000c
#define	TX_FORMAT1_12__SEL_GREEN__SHIFT                    0x0000000f
#define	TX_FORMAT1_12__SEL_BLUE__SHIFT                     0x00000012
#define	TX_FORMAT1_12__GAMMA__SHIFT                        0x00000015
#define	TX_FORMAT1_12__YUV_TO_RGB__SHIFT                   0x00000016
#define	TX_FORMAT1_12__APPLE_YUV__SHIFT                    0x00000018
#define	TX_FORMAT1_12__TEX_COORD_TYPE__SHIFT               0x00000019
#define	TX_FORMAT1_12__CACHE__SHIFT                        0x0000001b

// TX_FORMAT1_13
#define	TX_FORMAT1_13__TXFORMAT__SHIFT                     0x00000000
#define	TX_FORMAT1_13__SIGNED_COMP0__SHIFT                 0x00000005
#define	TX_FORMAT1_13__SIGNED_COMP1__SHIFT                 0x00000006
#define	TX_FORMAT1_13__SIGNED_COMP2__SHIFT                 0x00000007
#define	TX_FORMAT1_13__SIGNED_COMP3__SHIFT                 0x00000008
#define	TX_FORMAT1_13__SEL_ALPHA__SHIFT                    0x00000009
#define	TX_FORMAT1_13__SEL_RED__SHIFT                      0x0000000c
#define	TX_FORMAT1_13__SEL_GREEN__SHIFT                    0x0000000f
#define	TX_FORMAT1_13__SEL_BLUE__SHIFT                     0x00000012
#define	TX_FORMAT1_13__GAMMA__SHIFT                        0x00000015
#define	TX_FORMAT1_13__YUV_TO_RGB__SHIFT                   0x00000016
#define	TX_FORMAT1_13__APPLE_YUV__SHIFT                    0x00000018
#define	TX_FORMAT1_13__TEX_COORD_TYPE__SHIFT               0x00000019
#define	TX_FORMAT1_13__CACHE__SHIFT                        0x0000001b

// TX_FORMAT1_14
#define	TX_FORMAT1_14__TXFORMAT__SHIFT                     0x00000000
#define	TX_FORMAT1_14__SIGNED_COMP0__SHIFT                 0x00000005
#define	TX_FORMAT1_14__SIGNED_COMP1__SHIFT                 0x00000006
#define	TX_FORMAT1_14__SIGNED_COMP2__SHIFT                 0x00000007
#define	TX_FORMAT1_14__SIGNED_COMP3__SHIFT                 0x00000008
#define	TX_FORMAT1_14__SEL_ALPHA__SHIFT                    0x00000009
#define	TX_FORMAT1_14__SEL_RED__SHIFT                      0x0000000c
#define	TX_FORMAT1_14__SEL_GREEN__SHIFT                    0x0000000f
#define	TX_FORMAT1_14__SEL_BLUE__SHIFT                     0x00000012
#define	TX_FORMAT1_14__GAMMA__SHIFT                        0x00000015
#define	TX_FORMAT1_14__YUV_TO_RGB__SHIFT                   0x00000016
#define	TX_FORMAT1_14__APPLE_YUV__SHIFT                    0x00000018
#define	TX_FORMAT1_14__TEX_COORD_TYPE__SHIFT               0x00000019
#define	TX_FORMAT1_14__CACHE__SHIFT                        0x0000001b

// TX_FORMAT1_15
#define	TX_FORMAT1_15__TXFORMAT__SHIFT                     0x00000000
#define	TX_FORMAT1_15__SIGNED_COMP0__SHIFT                 0x00000005
#define	TX_FORMAT1_15__SIGNED_COMP1__SHIFT                 0x00000006
#define	TX_FORMAT1_15__SIGNED_COMP2__SHIFT                 0x00000007
#define	TX_FORMAT1_15__SIGNED_COMP3__SHIFT                 0x00000008
#define	TX_FORMAT1_15__SEL_ALPHA__SHIFT                    0x00000009
#define	TX_FORMAT1_15__SEL_RED__SHIFT                      0x0000000c
#define	TX_FORMAT1_15__SEL_GREEN__SHIFT                    0x0000000f
#define	TX_FORMAT1_15__SEL_BLUE__SHIFT                     0x00000012
#define	TX_FORMAT1_15__GAMMA__SHIFT                        0x00000015
#define	TX_FORMAT1_15__YUV_TO_RGB__SHIFT                   0x00000016
#define	TX_FORMAT1_15__APPLE_YUV__SHIFT                    0x00000018
#define	TX_FORMAT1_15__TEX_COORD_TYPE__SHIFT               0x00000019
#define	TX_FORMAT1_15__CACHE__SHIFT                        0x0000001b

// TX_FORMAT2_0
#define	TX_FORMAT2_0__TXPITCH__SHIFT                       0x00000000

// TX_FORMAT2_1
#define	TX_FORMAT2_1__TXPITCH__SHIFT                       0x00000000

// TX_FORMAT2_2
#define	TX_FORMAT2_2__TXPITCH__SHIFT                       0x00000000

// TX_FORMAT2_3
#define	TX_FORMAT2_3__TXPITCH__SHIFT                       0x00000000

// TX_FORMAT2_4
#define	TX_FORMAT2_4__TXPITCH__SHIFT                       0x00000000

// TX_FORMAT2_5
#define	TX_FORMAT2_5__TXPITCH__SHIFT                       0x00000000

// TX_FORMAT2_6
#define	TX_FORMAT2_6__TXPITCH__SHIFT                       0x00000000

// TX_FORMAT2_7
#define	TX_FORMAT2_7__TXPITCH__SHIFT                       0x00000000

// TX_FORMAT2_8
#define	TX_FORMAT2_8__TXPITCH__SHIFT                       0x00000000

// TX_FORMAT2_9
#define	TX_FORMAT2_9__TXPITCH__SHIFT                       0x00000000

// TX_FORMAT2_10
#define	TX_FORMAT2_10__TXPITCH__SHIFT                      0x00000000

// TX_FORMAT2_11
#define	TX_FORMAT2_11__TXPITCH__SHIFT                      0x00000000

// TX_FORMAT2_12
#define	TX_FORMAT2_12__TXPITCH__SHIFT                      0x00000000

// TX_FORMAT2_13
#define	TX_FORMAT2_13__TXPITCH__SHIFT                      0x00000000

// TX_FORMAT2_14
#define	TX_FORMAT2_14__TXPITCH__SHIFT                      0x00000000

// TX_FORMAT2_15
#define	TX_FORMAT2_15__TXPITCH__SHIFT                      0x00000000

// TX_OFFSET_0
#define	TX_OFFSET_0__ENDIAN_SWAP__SHIFT                    0x00000000
#define	TX_OFFSET_0__MACRO_TILE__SHIFT                     0x00000002
#define	TX_OFFSET_0__MICRO_TILE__SHIFT                     0x00000003
#define	TX_OFFSET_0__TXOFFSET__SHIFT                       0x00000005

// TX_OFFSET_1
#define	TX_OFFSET_1__ENDIAN_SWAP__SHIFT                    0x00000000
#define	TX_OFFSET_1__MACRO_TILE__SHIFT                     0x00000002
#define	TX_OFFSET_1__MICRO_TILE__SHIFT                     0x00000003
#define	TX_OFFSET_1__TXOFFSET__SHIFT                       0x00000005

// TX_OFFSET_2
#define	TX_OFFSET_2__ENDIAN_SWAP__SHIFT                    0x00000000
#define	TX_OFFSET_2__MACRO_TILE__SHIFT                     0x00000002
#define	TX_OFFSET_2__MICRO_TILE__SHIFT                     0x00000003
#define	TX_OFFSET_2__TXOFFSET__SHIFT                       0x00000005

// TX_OFFSET_3
#define	TX_OFFSET_3__ENDIAN_SWAP__SHIFT                    0x00000000
#define	TX_OFFSET_3__MACRO_TILE__SHIFT                     0x00000002
#define	TX_OFFSET_3__MICRO_TILE__SHIFT                     0x00000003
#define	TX_OFFSET_3__TXOFFSET__SHIFT                       0x00000005

// TX_OFFSET_4
#define	TX_OFFSET_4__ENDIAN_SWAP__SHIFT                    0x00000000
#define	TX_OFFSET_4__MACRO_TILE__SHIFT                     0x00000002
#define	TX_OFFSET_4__MICRO_TILE__SHIFT                     0x00000003
#define	TX_OFFSET_4__TXOFFSET__SHIFT                       0x00000005

// TX_OFFSET_5
#define	TX_OFFSET_5__ENDIAN_SWAP__SHIFT                    0x00000000
#define	TX_OFFSET_5__MACRO_TILE__SHIFT                     0x00000002
#define	TX_OFFSET_5__MICRO_TILE__SHIFT                     0x00000003
#define	TX_OFFSET_5__TXOFFSET__SHIFT                       0x00000005

// TX_OFFSET_6
#define	TX_OFFSET_6__ENDIAN_SWAP__SHIFT                    0x00000000
#define	TX_OFFSET_6__MACRO_TILE__SHIFT                     0x00000002
#define	TX_OFFSET_6__MICRO_TILE__SHIFT                     0x00000003
#define	TX_OFFSET_6__TXOFFSET__SHIFT                       0x00000005

// TX_OFFSET_7
#define	TX_OFFSET_7__ENDIAN_SWAP__SHIFT                    0x00000000
#define	TX_OFFSET_7__MACRO_TILE__SHIFT                     0x00000002
#define	TX_OFFSET_7__MICRO_TILE__SHIFT                     0x00000003
#define	TX_OFFSET_7__TXOFFSET__SHIFT                       0x00000005

// TX_OFFSET_8
#define	TX_OFFSET_8__ENDIAN_SWAP__SHIFT                    0x00000000
#define	TX_OFFSET_8__MACRO_TILE__SHIFT                     0x00000002
#define	TX_OFFSET_8__MICRO_TILE__SHIFT                     0x00000003
#define	TX_OFFSET_8__TXOFFSET__SHIFT                       0x00000005

// TX_OFFSET_9
#define	TX_OFFSET_9__ENDIAN_SWAP__SHIFT                    0x00000000
#define	TX_OFFSET_9__MACRO_TILE__SHIFT                     0x00000002
#define	TX_OFFSET_9__MICRO_TILE__SHIFT                     0x00000003
#define	TX_OFFSET_9__TXOFFSET__SHIFT                       0x00000005

// TX_OFFSET_10
#define	TX_OFFSET_10__ENDIAN_SWAP__SHIFT                   0x00000000
#define	TX_OFFSET_10__MACRO_TILE__SHIFT                    0x00000002
#define	TX_OFFSET_10__MICRO_TILE__SHIFT                    0x00000003
#define	TX_OFFSET_10__TXOFFSET__SHIFT                      0x00000005

// TX_OFFSET_11
#define	TX_OFFSET_11__ENDIAN_SWAP__SHIFT                   0x00000000
#define	TX_OFFSET_11__MACRO_TILE__SHIFT                    0x00000002
#define	TX_OFFSET_11__MICRO_TILE__SHIFT                    0x00000003
#define	TX_OFFSET_11__TXOFFSET__SHIFT                      0x00000005

// TX_OFFSET_12
#define	TX_OFFSET_12__ENDIAN_SWAP__SHIFT                   0x00000000
#define	TX_OFFSET_12__MACRO_TILE__SHIFT                    0x00000002
#define	TX_OFFSET_12__MICRO_TILE__SHIFT                    0x00000003
#define	TX_OFFSET_12__TXOFFSET__SHIFT                      0x00000005

// TX_OFFSET_13
#define	TX_OFFSET_13__ENDIAN_SWAP__SHIFT                   0x00000000
#define	TX_OFFSET_13__MACRO_TILE__SHIFT                    0x00000002
#define	TX_OFFSET_13__MICRO_TILE__SHIFT                    0x00000003
#define	TX_OFFSET_13__TXOFFSET__SHIFT                      0x00000005

// TX_OFFSET_14
#define	TX_OFFSET_14__ENDIAN_SWAP__SHIFT                   0x00000000
#define	TX_OFFSET_14__MACRO_TILE__SHIFT                    0x00000002
#define	TX_OFFSET_14__MICRO_TILE__SHIFT                    0x00000003
#define	TX_OFFSET_14__TXOFFSET__SHIFT                      0x00000005

// TX_OFFSET_15
#define	TX_OFFSET_15__ENDIAN_SWAP__SHIFT                   0x00000000
#define	TX_OFFSET_15__MACRO_TILE__SHIFT                    0x00000002
#define	TX_OFFSET_15__MICRO_TILE__SHIFT                    0x00000003
#define	TX_OFFSET_15__TXOFFSET__SHIFT                      0x00000005

// TX_CHROMA_KEY_0
#define	TX_CHROMA_KEY_0__CHROMA_KEY__SHIFT                 0x00000000

// TX_CHROMA_KEY_1
#define	TX_CHROMA_KEY_1__CHROMA_KEY__SHIFT                 0x00000000

// TX_CHROMA_KEY_2
#define	TX_CHROMA_KEY_2__CHROMA_KEY__SHIFT                 0x00000000

// TX_CHROMA_KEY_3
#define	TX_CHROMA_KEY_3__CHROMA_KEY__SHIFT                 0x00000000

// TX_CHROMA_KEY_4
#define	TX_CHROMA_KEY_4__CHROMA_KEY__SHIFT                 0x00000000

// TX_CHROMA_KEY_5
#define	TX_CHROMA_KEY_5__CHROMA_KEY__SHIFT                 0x00000000

// TX_CHROMA_KEY_6
#define	TX_CHROMA_KEY_6__CHROMA_KEY__SHIFT                 0x00000000

// TX_CHROMA_KEY_7
#define	TX_CHROMA_KEY_7__CHROMA_KEY__SHIFT                 0x00000000

// TX_CHROMA_KEY_8
#define	TX_CHROMA_KEY_8__CHROMA_KEY__SHIFT                 0x00000000

// TX_CHROMA_KEY_9
#define	TX_CHROMA_KEY_9__CHROMA_KEY__SHIFT                 0x00000000

// TX_CHROMA_KEY_10
#define	TX_CHROMA_KEY_10__CHROMA_KEY__SHIFT                0x00000000

// TX_CHROMA_KEY_11
#define	TX_CHROMA_KEY_11__CHROMA_KEY__SHIFT                0x00000000

// TX_CHROMA_KEY_12
#define	TX_CHROMA_KEY_12__CHROMA_KEY__SHIFT                0x00000000

// TX_CHROMA_KEY_13
#define	TX_CHROMA_KEY_13__CHROMA_KEY__SHIFT                0x00000000

// TX_CHROMA_KEY_14
#define	TX_CHROMA_KEY_14__CHROMA_KEY__SHIFT                0x00000000

// TX_CHROMA_KEY_15
#define	TX_CHROMA_KEY_15__CHROMA_KEY__SHIFT                0x00000000

// TX_BORDER_COLOR_0
#define	TX_BORDER_COLOR_0__BORDER_COLOR__SHIFT             0x00000000

// TX_BORDER_COLOR_1
#define	TX_BORDER_COLOR_1__BORDER_COLOR__SHIFT             0x00000000

// TX_BORDER_COLOR_2
#define	TX_BORDER_COLOR_2__BORDER_COLOR__SHIFT             0x00000000

// TX_BORDER_COLOR_3
#define	TX_BORDER_COLOR_3__BORDER_COLOR__SHIFT             0x00000000

// TX_BORDER_COLOR_4
#define	TX_BORDER_COLOR_4__BORDER_COLOR__SHIFT             0x00000000

// TX_BORDER_COLOR_5
#define	TX_BORDER_COLOR_5__BORDER_COLOR__SHIFT             0x00000000

// TX_BORDER_COLOR_6
#define	TX_BORDER_COLOR_6__BORDER_COLOR__SHIFT             0x00000000

// TX_BORDER_COLOR_7
#define	TX_BORDER_COLOR_7__BORDER_COLOR__SHIFT             0x00000000

// TX_BORDER_COLOR_8
#define	TX_BORDER_COLOR_8__BORDER_COLOR__SHIFT             0x00000000

// TX_BORDER_COLOR_9
#define	TX_BORDER_COLOR_9__BORDER_COLOR__SHIFT             0x00000000

// TX_BORDER_COLOR_10
#define	TX_BORDER_COLOR_10__BORDER_COLOR__SHIFT            0x00000000

// TX_BORDER_COLOR_11
#define	TX_BORDER_COLOR_11__BORDER_COLOR__SHIFT            0x00000000

// TX_BORDER_COLOR_12
#define	TX_BORDER_COLOR_12__BORDER_COLOR__SHIFT            0x00000000

// TX_BORDER_COLOR_13
#define	TX_BORDER_COLOR_13__BORDER_COLOR__SHIFT            0x00000000

// TX_BORDER_COLOR_14
#define	TX_BORDER_COLOR_14__BORDER_COLOR__SHIFT            0x00000000

// TX_BORDER_COLOR_15
#define	TX_BORDER_COLOR_15__BORDER_COLOR__SHIFT            0x00000000

// TX_ENABLE
#define	TX_ENABLE__TEX_0_ENABLE__SHIFT                     0x00000000
#define	TX_ENABLE__TEX_1_ENABLE__SHIFT                     0x00000001
#define	TX_ENABLE__TEX_2_ENABLE__SHIFT                     0x00000002
#define	TX_ENABLE__TEX_3_ENABLE__SHIFT                     0x00000003
#define	TX_ENABLE__TEX_4_ENABLE__SHIFT                     0x00000004
#define	TX_ENABLE__TEX_5_ENABLE__SHIFT                     0x00000005
#define	TX_ENABLE__TEX_6_ENABLE__SHIFT                     0x00000006
#define	TX_ENABLE__TEX_7_ENABLE__SHIFT                     0x00000007
#define	TX_ENABLE__TEX_8_ENABLE__SHIFT                     0x00000008
#define	TX_ENABLE__TEX_9_ENABLE__SHIFT                     0x00000009
#define	TX_ENABLE__TEX_10_ENABLE__SHIFT                    0x0000000a
#define	TX_ENABLE__TEX_11_ENABLE__SHIFT                    0x0000000b
#define	TX_ENABLE__TEX_12_ENABLE__SHIFT                    0x0000000c
#define	TX_ENABLE__TEX_13_ENABLE__SHIFT                    0x0000000d
#define	TX_ENABLE__TEX_14_ENABLE__SHIFT                    0x0000000e
#define	TX_ENABLE__TEX_15_ENABLE__SHIFT                    0x0000000f

// TX_INVALTAGS
#define	TX_INVALTAGS__RESERVED__SHIFT                      0x00000000

// TX_PERF
#define	TX_PERF__PERF0__SHIFT                              0x00000000
#define	TX_PERF__PERF1__SHIFT                              0x00000005
#define	TX_PERF__PERF2__SHIFT                              0x0000000a
#define	TX_PERF__PERF3__SHIFT                              0x0000000f
#define	TX_PERF__DISABLE__SHIFT                            0x0000001e

// US_CONFIG
#define	US_CONFIG__NLEVEL__SHIFT                           0x00000000
#define	US_CONFIG__FIRST_TEX__SHIFT                        0x00000003
#define	US_CONFIG__PERF0__SHIFT                            0x00000004
#define	US_CONFIG__PERF1__SHIFT                            0x00000009
#define	US_CONFIG__PERF2__SHIFT                            0x0000000e
#define	US_CONFIG__PERF3__SHIFT                            0x00000013

// US_PIXSIZE
#define	US_PIXSIZE__PIX_SIZE__SHIFT                        0x00000000

// US_CODE_OFFSET
#define	US_CODE_OFFSET__ALU_OFFSET__SHIFT                  0x00000000
#define	US_CODE_OFFSET__ALU_SIZE__SHIFT                    0x00000006
#define	US_CODE_OFFSET__TEX_OFFSET__SHIFT                  0x0000000d
#define	US_CODE_OFFSET__TEX_SIZE__SHIFT                    0x00000012

// US_RESET

// US_CODE_ADDR_0
#define	US_CODE_ADDR_0__ALU_START__SHIFT                   0x00000000
#define	US_CODE_ADDR_0__ALU_SIZE__SHIFT                    0x00000006
#define	US_CODE_ADDR_0__TEX_START__SHIFT                   0x0000000c
#define	US_CODE_ADDR_0__TEX_SIZE__SHIFT                    0x00000011
#define	US_CODE_ADDR_0__RGBA_OUT__SHIFT                    0x00000016
#define	US_CODE_ADDR_0__W_OUT__SHIFT                       0x00000017

// US_CODE_ADDR_1
#define	US_CODE_ADDR_1__ALU_START__SHIFT                   0x00000000
#define	US_CODE_ADDR_1__ALU_SIZE__SHIFT                    0x00000006
#define	US_CODE_ADDR_1__TEX_START__SHIFT                   0x0000000c
#define	US_CODE_ADDR_1__TEX_SIZE__SHIFT                    0x00000011
#define	US_CODE_ADDR_1__RGBA_OUT__SHIFT                    0x00000016
#define	US_CODE_ADDR_1__W_OUT__SHIFT                       0x00000017

// US_CODE_ADDR_2
#define	US_CODE_ADDR_2__ALU_START__SHIFT                   0x00000000
#define	US_CODE_ADDR_2__ALU_SIZE__SHIFT                    0x00000006
#define	US_CODE_ADDR_2__TEX_START__SHIFT                   0x0000000c
#define	US_CODE_ADDR_2__TEX_SIZE__SHIFT                    0x00000011
#define	US_CODE_ADDR_2__RGBA_OUT__SHIFT                    0x00000016
#define	US_CODE_ADDR_2__W_OUT__SHIFT                       0x00000017

// US_CODE_ADDR_3
#define	US_CODE_ADDR_3__ALU_START__SHIFT                   0x00000000
#define	US_CODE_ADDR_3__ALU_SIZE__SHIFT                    0x00000006
#define	US_CODE_ADDR_3__TEX_START__SHIFT                   0x0000000c
#define	US_CODE_ADDR_3__TEX_SIZE__SHIFT                    0x00000011
#define	US_CODE_ADDR_3__RGBA_OUT__SHIFT                    0x00000016
#define	US_CODE_ADDR_3__W_OUT__SHIFT                       0x00000017

// US_TEX_INST_0
#define	US_TEX_INST_0__SRC_ADDR__SHIFT                     0x00000000
#define	US_TEX_INST_0__DST_ADDR__SHIFT                     0x00000006
#define	US_TEX_INST_0__TEX_ID__SHIFT                       0x0000000b
#define	US_TEX_INST_0__INST__SHIFT                         0x0000000f
#define	US_TEX_INST_0__OMOD__SHIFT                         0x00000012

// US_TEX_INST_1
#define	US_TEX_INST_1__SRC_ADDR__SHIFT                     0x00000000
#define	US_TEX_INST_1__DST_ADDR__SHIFT                     0x00000006
#define	US_TEX_INST_1__TEX_ID__SHIFT                       0x0000000b
#define	US_TEX_INST_1__INST__SHIFT                         0x0000000f
#define	US_TEX_INST_1__OMOD__SHIFT                         0x00000012

// US_TEX_INST_2
#define	US_TEX_INST_2__SRC_ADDR__SHIFT                     0x00000000
#define	US_TEX_INST_2__DST_ADDR__SHIFT                     0x00000006
#define	US_TEX_INST_2__TEX_ID__SHIFT                       0x0000000b
#define	US_TEX_INST_2__INST__SHIFT                         0x0000000f
#define	US_TEX_INST_2__OMOD__SHIFT                         0x00000012

// US_TEX_INST_3
#define	US_TEX_INST_3__SRC_ADDR__SHIFT                     0x00000000
#define	US_TEX_INST_3__DST_ADDR__SHIFT                     0x00000006
#define	US_TEX_INST_3__TEX_ID__SHIFT                       0x0000000b
#define	US_TEX_INST_3__INST__SHIFT                         0x0000000f
#define	US_TEX_INST_3__OMOD__SHIFT                         0x00000012

// US_TEX_INST_4
#define	US_TEX_INST_4__SRC_ADDR__SHIFT                     0x00000000
#define	US_TEX_INST_4__DST_ADDR__SHIFT                     0x00000006
#define	US_TEX_INST_4__TEX_ID__SHIFT                       0x0000000b
#define	US_TEX_INST_4__INST__SHIFT                         0x0000000f
#define	US_TEX_INST_4__OMOD__SHIFT                         0x00000012

// US_TEX_INST_5
#define	US_TEX_INST_5__SRC_ADDR__SHIFT                     0x00000000
#define	US_TEX_INST_5__DST_ADDR__SHIFT                     0x00000006
#define	US_TEX_INST_5__TEX_ID__SHIFT                       0x0000000b
#define	US_TEX_INST_5__INST__SHIFT                         0x0000000f
#define	US_TEX_INST_5__OMOD__SHIFT                         0x00000012

// US_TEX_INST_6
#define	US_TEX_INST_6__SRC_ADDR__SHIFT                     0x00000000
#define	US_TEX_INST_6__DST_ADDR__SHIFT                     0x00000006
#define	US_TEX_INST_6__TEX_ID__SHIFT                       0x0000000b
#define	US_TEX_INST_6__INST__SHIFT                         0x0000000f
#define	US_TEX_INST_6__OMOD__SHIFT                         0x00000012

// US_TEX_INST_7
#define	US_TEX_INST_7__SRC_ADDR__SHIFT                     0x00000000
#define	US_TEX_INST_7__DST_ADDR__SHIFT                     0x00000006
#define	US_TEX_INST_7__TEX_ID__SHIFT                       0x0000000b
#define	US_TEX_INST_7__INST__SHIFT                         0x0000000f
#define	US_TEX_INST_7__OMOD__SHIFT                         0x00000012

// US_TEX_INST_8
#define	US_TEX_INST_8__SRC_ADDR__SHIFT                     0x00000000
#define	US_TEX_INST_8__DST_ADDR__SHIFT                     0x00000006
#define	US_TEX_INST_8__TEX_ID__SHIFT                       0x0000000b
#define	US_TEX_INST_8__INST__SHIFT                         0x0000000f
#define	US_TEX_INST_8__OMOD__SHIFT                         0x00000012

// US_TEX_INST_9
#define	US_TEX_INST_9__SRC_ADDR__SHIFT                     0x00000000
#define	US_TEX_INST_9__DST_ADDR__SHIFT                     0x00000006
#define	US_TEX_INST_9__TEX_ID__SHIFT                       0x0000000b
#define	US_TEX_INST_9__INST__SHIFT                         0x0000000f
#define	US_TEX_INST_9__OMOD__SHIFT                         0x00000012

// US_TEX_INST_10
#define	US_TEX_INST_10__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_10__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_10__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_10__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_10__OMOD__SHIFT                        0x00000012

// US_TEX_INST_11
#define	US_TEX_INST_11__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_11__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_11__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_11__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_11__OMOD__SHIFT                        0x00000012

// US_TEX_INST_12
#define	US_TEX_INST_12__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_12__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_12__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_12__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_12__OMOD__SHIFT                        0x00000012

// US_TEX_INST_13
#define	US_TEX_INST_13__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_13__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_13__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_13__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_13__OMOD__SHIFT                        0x00000012

// US_TEX_INST_14
#define	US_TEX_INST_14__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_14__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_14__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_14__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_14__OMOD__SHIFT                        0x00000012

// US_TEX_INST_15
#define	US_TEX_INST_15__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_15__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_15__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_15__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_15__OMOD__SHIFT                        0x00000012

// US_TEX_INST_16
#define	US_TEX_INST_16__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_16__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_16__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_16__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_16__OMOD__SHIFT                        0x00000012

// US_TEX_INST_17
#define	US_TEX_INST_17__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_17__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_17__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_17__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_17__OMOD__SHIFT                        0x00000012

// US_TEX_INST_18
#define	US_TEX_INST_18__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_18__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_18__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_18__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_18__OMOD__SHIFT                        0x00000012

// US_TEX_INST_19
#define	US_TEX_INST_19__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_19__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_19__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_19__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_19__OMOD__SHIFT                        0x00000012

// US_TEX_INST_20
#define	US_TEX_INST_20__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_20__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_20__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_20__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_20__OMOD__SHIFT                        0x00000012

// US_TEX_INST_21
#define	US_TEX_INST_21__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_21__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_21__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_21__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_21__OMOD__SHIFT                        0x00000012

// US_TEX_INST_22
#define	US_TEX_INST_22__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_22__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_22__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_22__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_22__OMOD__SHIFT                        0x00000012

// US_TEX_INST_23
#define	US_TEX_INST_23__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_23__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_23__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_23__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_23__OMOD__SHIFT                        0x00000012

// US_TEX_INST_24
#define	US_TEX_INST_24__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_24__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_24__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_24__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_24__OMOD__SHIFT                        0x00000012

// US_TEX_INST_25
#define	US_TEX_INST_25__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_25__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_25__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_25__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_25__OMOD__SHIFT                        0x00000012

// US_TEX_INST_26
#define	US_TEX_INST_26__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_26__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_26__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_26__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_26__OMOD__SHIFT                        0x00000012

// US_TEX_INST_27
#define	US_TEX_INST_27__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_27__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_27__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_27__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_27__OMOD__SHIFT                        0x00000012

// US_TEX_INST_28
#define	US_TEX_INST_28__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_28__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_28__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_28__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_28__OMOD__SHIFT                        0x00000012

// US_TEX_INST_29
#define	US_TEX_INST_29__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_29__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_29__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_29__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_29__OMOD__SHIFT                        0x00000012

// US_TEX_INST_30
#define	US_TEX_INST_30__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_30__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_30__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_30__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_30__OMOD__SHIFT                        0x00000012

// US_TEX_INST_31
#define	US_TEX_INST_31__SRC_ADDR__SHIFT                    0x00000000
#define	US_TEX_INST_31__DST_ADDR__SHIFT                    0x00000006
#define	US_TEX_INST_31__TEX_ID__SHIFT                      0x0000000b
#define	US_TEX_INST_31__INST__SHIFT                        0x0000000f
#define	US_TEX_INST_31__OMOD__SHIFT                        0x00000012

// US_OUT_FMT_0
#define	US_OUT_FMT_0__OUT_FMT__SHIFT                       0x00000000
#define	US_OUT_FMT_0__C0_SEL__SHIFT                        0x00000008
#define	US_OUT_FMT_0__C1_SEL__SHIFT                        0x0000000a
#define	US_OUT_FMT_0__C2_SEL__SHIFT                        0x0000000c
#define	US_OUT_FMT_0__C3_SEL__SHIFT                        0x0000000e
#define	US_OUT_FMT_0__OUT_SIGN__SHIFT                      0x00000010

// US_OUT_FMT_1
#define	US_OUT_FMT_1__OUT_FMT__SHIFT                       0x00000000
#define	US_OUT_FMT_1__C0_SEL__SHIFT                        0x00000008
#define	US_OUT_FMT_1__C1_SEL__SHIFT                        0x0000000a
#define	US_OUT_FMT_1__C2_SEL__SHIFT                        0x0000000c
#define	US_OUT_FMT_1__C3_SEL__SHIFT                        0x0000000e
#define	US_OUT_FMT_1__OUT_SIGN__SHIFT                      0x00000010

// US_OUT_FMT_2
#define	US_OUT_FMT_2__OUT_FMT__SHIFT                       0x00000000
#define	US_OUT_FMT_2__C0_SEL__SHIFT                        0x00000008
#define	US_OUT_FMT_2__C1_SEL__SHIFT                        0x0000000a
#define	US_OUT_FMT_2__C2_SEL__SHIFT                        0x0000000c
#define	US_OUT_FMT_2__C3_SEL__SHIFT                        0x0000000e
#define	US_OUT_FMT_2__OUT_SIGN__SHIFT                      0x00000010

// US_OUT_FMT_3
#define	US_OUT_FMT_3__OUT_FMT__SHIFT                       0x00000000
#define	US_OUT_FMT_3__C0_SEL__SHIFT                        0x00000008
#define	US_OUT_FMT_3__C1_SEL__SHIFT                        0x0000000a
#define	US_OUT_FMT_3__C2_SEL__SHIFT                        0x0000000c
#define	US_OUT_FMT_3__C3_SEL__SHIFT                        0x0000000e
#define	US_OUT_FMT_3__OUT_SIGN__SHIFT                      0x00000010

// US_W_FMT
#define	US_W_FMT__W_FMT__SHIFT                             0x00000000
#define	US_W_FMT__W_SRC__SHIFT                             0x00000002

// US_ALU_RGB_ADDR_0
#define	US_ALU_RGB_ADDR_0__ADDR0__SHIFT                    0x00000000
#define	US_ALU_RGB_ADDR_0__ADDR1__SHIFT                    0x00000006
#define	US_ALU_RGB_ADDR_0__ADDR2__SHIFT                    0x0000000c
#define	US_ALU_RGB_ADDR_0__ADDRD__SHIFT                    0x00000012
#define	US_ALU_RGB_ADDR_0__WMASK__SHIFT                    0x00000017
#define	US_ALU_RGB_ADDR_0__OMASK__SHIFT                    0x0000001a
#define	US_ALU_RGB_ADDR_0__TARGET__SHIFT                   0x0000001d

// US_ALU_RGB_ADDR_1
#define	US_ALU_RGB_ADDR_1__ADDR0__SHIFT                    0x00000000
#define	US_ALU_RGB_ADDR_1__ADDR1__SHIFT                    0x00000006
#define	US_ALU_RGB_ADDR_1__ADDR2__SHIFT                    0x0000000c
#define	US_ALU_RGB_ADDR_1__ADDRD__SHIFT                    0x00000012
#define	US_ALU_RGB_ADDR_1__WMASK__SHIFT                    0x00000017
#define	US_ALU_RGB_ADDR_1__OMASK__SHIFT                    0x0000001a
#define	US_ALU_RGB_ADDR_1__TARGET__SHIFT                   0x0000001d

// US_ALU_RGB_ADDR_2
#define	US_ALU_RGB_ADDR_2__ADDR0__SHIFT                    0x00000000
#define	US_ALU_RGB_ADDR_2__ADDR1__SHIFT                    0x00000006
#define	US_ALU_RGB_ADDR_2__ADDR2__SHIFT                    0x0000000c
#define	US_ALU_RGB_ADDR_2__ADDRD__SHIFT                    0x00000012
#define	US_ALU_RGB_ADDR_2__WMASK__SHIFT                    0x00000017
#define	US_ALU_RGB_ADDR_2__OMASK__SHIFT                    0x0000001a
#define	US_ALU_RGB_ADDR_2__TARGET__SHIFT                   0x0000001d

// US_ALU_RGB_ADDR_3
#define	US_ALU_RGB_ADDR_3__ADDR0__SHIFT                    0x00000000
#define	US_ALU_RGB_ADDR_3__ADDR1__SHIFT                    0x00000006
#define	US_ALU_RGB_ADDR_3__ADDR2__SHIFT                    0x0000000c
#define	US_ALU_RGB_ADDR_3__ADDRD__SHIFT                    0x00000012
#define	US_ALU_RGB_ADDR_3__WMASK__SHIFT                    0x00000017
#define	US_ALU_RGB_ADDR_3__OMASK__SHIFT                    0x0000001a
#define	US_ALU_RGB_ADDR_3__TARGET__SHIFT                   0x0000001d

// US_ALU_RGB_ADDR_4
#define	US_ALU_RGB_ADDR_4__ADDR0__SHIFT                    0x00000000
#define	US_ALU_RGB_ADDR_4__ADDR1__SHIFT                    0x00000006
#define	US_ALU_RGB_ADDR_4__ADDR2__SHIFT                    0x0000000c
#define	US_ALU_RGB_ADDR_4__ADDRD__SHIFT                    0x00000012
#define	US_ALU_RGB_ADDR_4__WMASK__SHIFT                    0x00000017
#define	US_ALU_RGB_ADDR_4__OMASK__SHIFT                    0x0000001a
#define	US_ALU_RGB_ADDR_4__TARGET__SHIFT                   0x0000001d

// US_ALU_RGB_ADDR_5
#define	US_ALU_RGB_ADDR_5__ADDR0__SHIFT                    0x00000000
#define	US_ALU_RGB_ADDR_5__ADDR1__SHIFT                    0x00000006
#define	US_ALU_RGB_ADDR_5__ADDR2__SHIFT                    0x0000000c
#define	US_ALU_RGB_ADDR_5__ADDRD__SHIFT                    0x00000012
#define	US_ALU_RGB_ADDR_5__WMASK__SHIFT                    0x00000017
#define	US_ALU_RGB_ADDR_5__OMASK__SHIFT                    0x0000001a
#define	US_ALU_RGB_ADDR_5__TARGET__SHIFT                   0x0000001d

// US_ALU_RGB_ADDR_6
#define	US_ALU_RGB_ADDR_6__ADDR0__SHIFT                    0x00000000
#define	US_ALU_RGB_ADDR_6__ADDR1__SHIFT                    0x00000006
#define	US_ALU_RGB_ADDR_6__ADDR2__SHIFT                    0x0000000c
#define	US_ALU_RGB_ADDR_6__ADDRD__SHIFT                    0x00000012
#define	US_ALU_RGB_ADDR_6__WMASK__SHIFT                    0x00000017
#define	US_ALU_RGB_ADDR_6__OMASK__SHIFT                    0x0000001a
#define	US_ALU_RGB_ADDR_6__TARGET__SHIFT                   0x0000001d

// US_ALU_RGB_ADDR_7
#define	US_ALU_RGB_ADDR_7__ADDR0__SHIFT                    0x00000000
#define	US_ALU_RGB_ADDR_7__ADDR1__SHIFT                    0x00000006
#define	US_ALU_RGB_ADDR_7__ADDR2__SHIFT                    0x0000000c
#define	US_ALU_RGB_ADDR_7__ADDRD__SHIFT                    0x00000012
#define	US_ALU_RGB_ADDR_7__WMASK__SHIFT                    0x00000017
#define	US_ALU_RGB_ADDR_7__OMASK__SHIFT                    0x0000001a
#define	US_ALU_RGB_ADDR_7__TARGET__SHIFT                   0x0000001d

// US_ALU_RGB_ADDR_8
#define	US_ALU_RGB_ADDR_8__ADDR0__SHIFT                    0x00000000
#define	US_ALU_RGB_ADDR_8__ADDR1__SHIFT                    0x00000006
#define	US_ALU_RGB_ADDR_8__ADDR2__SHIFT                    0x0000000c
#define	US_ALU_RGB_ADDR_8__ADDRD__SHIFT                    0x00000012
#define	US_ALU_RGB_ADDR_8__WMASK__SHIFT                    0x00000017
#define	US_ALU_RGB_ADDR_8__OMASK__SHIFT                    0x0000001a
#define	US_ALU_RGB_ADDR_8__TARGET__SHIFT                   0x0000001d

// US_ALU_RGB_ADDR_9
#define	US_ALU_RGB_ADDR_9__ADDR0__SHIFT                    0x00000000
#define	US_ALU_RGB_ADDR_9__ADDR1__SHIFT                    0x00000006
#define	US_ALU_RGB_ADDR_9__ADDR2__SHIFT                    0x0000000c
#define	US_ALU_RGB_ADDR_9__ADDRD__SHIFT                    0x00000012
#define	US_ALU_RGB_ADDR_9__WMASK__SHIFT                    0x00000017
#define	US_ALU_RGB_ADDR_9__OMASK__SHIFT                    0x0000001a
#define	US_ALU_RGB_ADDR_9__TARGET__SHIFT                   0x0000001d

// US_ALU_RGB_ADDR_10
#define	US_ALU_RGB_ADDR_10__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_10__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_10__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_10__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_10__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_10__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_10__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_11
#define	US_ALU_RGB_ADDR_11__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_11__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_11__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_11__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_11__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_11__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_11__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_12
#define	US_ALU_RGB_ADDR_12__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_12__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_12__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_12__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_12__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_12__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_12__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_13
#define	US_ALU_RGB_ADDR_13__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_13__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_13__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_13__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_13__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_13__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_13__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_14
#define	US_ALU_RGB_ADDR_14__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_14__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_14__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_14__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_14__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_14__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_14__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_15
#define	US_ALU_RGB_ADDR_15__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_15__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_15__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_15__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_15__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_15__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_15__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_16
#define	US_ALU_RGB_ADDR_16__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_16__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_16__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_16__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_16__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_16__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_16__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_17
#define	US_ALU_RGB_ADDR_17__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_17__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_17__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_17__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_17__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_17__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_17__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_18
#define	US_ALU_RGB_ADDR_18__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_18__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_18__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_18__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_18__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_18__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_18__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_19
#define	US_ALU_RGB_ADDR_19__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_19__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_19__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_19__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_19__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_19__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_19__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_20
#define	US_ALU_RGB_ADDR_20__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_20__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_20__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_20__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_20__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_20__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_20__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_21
#define	US_ALU_RGB_ADDR_21__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_21__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_21__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_21__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_21__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_21__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_21__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_22
#define	US_ALU_RGB_ADDR_22__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_22__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_22__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_22__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_22__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_22__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_22__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_23
#define	US_ALU_RGB_ADDR_23__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_23__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_23__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_23__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_23__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_23__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_23__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_24
#define	US_ALU_RGB_ADDR_24__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_24__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_24__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_24__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_24__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_24__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_24__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_25
#define	US_ALU_RGB_ADDR_25__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_25__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_25__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_25__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_25__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_25__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_25__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_26
#define	US_ALU_RGB_ADDR_26__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_26__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_26__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_26__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_26__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_26__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_26__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_27
#define	US_ALU_RGB_ADDR_27__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_27__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_27__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_27__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_27__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_27__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_27__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_28
#define	US_ALU_RGB_ADDR_28__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_28__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_28__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_28__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_28__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_28__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_28__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_29
#define	US_ALU_RGB_ADDR_29__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_29__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_29__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_29__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_29__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_29__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_29__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_30
#define	US_ALU_RGB_ADDR_30__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_30__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_30__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_30__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_30__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_30__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_30__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_31
#define	US_ALU_RGB_ADDR_31__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_31__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_31__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_31__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_31__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_31__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_31__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_32
#define	US_ALU_RGB_ADDR_32__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_32__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_32__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_32__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_32__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_32__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_32__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_33
#define	US_ALU_RGB_ADDR_33__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_33__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_33__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_33__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_33__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_33__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_33__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_34
#define	US_ALU_RGB_ADDR_34__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_34__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_34__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_34__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_34__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_34__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_34__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_35
#define	US_ALU_RGB_ADDR_35__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_35__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_35__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_35__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_35__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_35__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_35__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_36
#define	US_ALU_RGB_ADDR_36__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_36__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_36__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_36__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_36__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_36__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_36__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_37
#define	US_ALU_RGB_ADDR_37__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_37__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_37__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_37__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_37__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_37__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_37__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_38
#define	US_ALU_RGB_ADDR_38__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_38__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_38__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_38__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_38__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_38__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_38__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_39
#define	US_ALU_RGB_ADDR_39__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_39__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_39__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_39__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_39__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_39__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_39__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_40
#define	US_ALU_RGB_ADDR_40__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_40__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_40__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_40__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_40__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_40__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_40__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_41
#define	US_ALU_RGB_ADDR_41__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_41__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_41__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_41__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_41__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_41__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_41__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_42
#define	US_ALU_RGB_ADDR_42__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_42__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_42__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_42__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_42__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_42__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_42__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_43
#define	US_ALU_RGB_ADDR_43__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_43__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_43__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_43__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_43__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_43__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_43__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_44
#define	US_ALU_RGB_ADDR_44__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_44__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_44__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_44__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_44__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_44__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_44__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_45
#define	US_ALU_RGB_ADDR_45__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_45__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_45__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_45__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_45__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_45__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_45__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_46
#define	US_ALU_RGB_ADDR_46__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_46__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_46__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_46__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_46__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_46__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_46__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_47
#define	US_ALU_RGB_ADDR_47__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_47__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_47__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_47__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_47__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_47__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_47__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_48
#define	US_ALU_RGB_ADDR_48__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_48__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_48__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_48__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_48__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_48__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_48__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_49
#define	US_ALU_RGB_ADDR_49__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_49__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_49__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_49__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_49__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_49__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_49__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_50
#define	US_ALU_RGB_ADDR_50__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_50__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_50__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_50__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_50__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_50__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_50__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_51
#define	US_ALU_RGB_ADDR_51__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_51__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_51__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_51__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_51__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_51__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_51__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_52
#define	US_ALU_RGB_ADDR_52__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_52__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_52__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_52__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_52__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_52__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_52__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_53
#define	US_ALU_RGB_ADDR_53__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_53__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_53__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_53__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_53__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_53__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_53__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_54
#define	US_ALU_RGB_ADDR_54__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_54__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_54__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_54__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_54__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_54__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_54__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_55
#define	US_ALU_RGB_ADDR_55__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_55__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_55__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_55__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_55__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_55__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_55__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_56
#define	US_ALU_RGB_ADDR_56__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_56__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_56__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_56__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_56__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_56__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_56__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_57
#define	US_ALU_RGB_ADDR_57__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_57__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_57__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_57__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_57__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_57__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_57__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_58
#define	US_ALU_RGB_ADDR_58__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_58__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_58__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_58__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_58__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_58__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_58__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_59
#define	US_ALU_RGB_ADDR_59__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_59__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_59__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_59__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_59__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_59__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_59__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_60
#define	US_ALU_RGB_ADDR_60__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_60__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_60__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_60__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_60__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_60__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_60__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_61
#define	US_ALU_RGB_ADDR_61__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_61__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_61__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_61__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_61__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_61__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_61__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_62
#define	US_ALU_RGB_ADDR_62__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_62__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_62__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_62__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_62__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_62__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_62__TARGET__SHIFT                  0x0000001d

// US_ALU_RGB_ADDR_63
#define	US_ALU_RGB_ADDR_63__ADDR0__SHIFT                   0x00000000
#define	US_ALU_RGB_ADDR_63__ADDR1__SHIFT                   0x00000006
#define	US_ALU_RGB_ADDR_63__ADDR2__SHIFT                   0x0000000c
#define	US_ALU_RGB_ADDR_63__ADDRD__SHIFT                   0x00000012
#define	US_ALU_RGB_ADDR_63__WMASK__SHIFT                   0x00000017
#define	US_ALU_RGB_ADDR_63__OMASK__SHIFT                   0x0000001a
#define	US_ALU_RGB_ADDR_63__TARGET__SHIFT                  0x0000001d

// US_ALU_ALPHA_ADDR_0
#define	US_ALU_ALPHA_ADDR_0__ADDR0__SHIFT                  0x00000000
#define	US_ALU_ALPHA_ADDR_0__ADDR1__SHIFT                  0x00000006
#define	US_ALU_ALPHA_ADDR_0__ADDR2__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_ADDR_0__ADDRD__SHIFT                  0x00000012
#define	US_ALU_ALPHA_ADDR_0__WMASK__SHIFT                  0x00000017
#define	US_ALU_ALPHA_ADDR_0__OMASK__SHIFT                  0x00000018
#define	US_ALU_ALPHA_ADDR_0__TARGET__SHIFT                 0x00000019
#define	US_ALU_ALPHA_ADDR_0__OMASK_W__SHIFT                0x0000001b
#define	US_ALU_ALPHA_ADDR_0__STAT_WE__SHIFT                0x0000001c

// US_ALU_ALPHA_ADDR_1
#define	US_ALU_ALPHA_ADDR_1__ADDR0__SHIFT                  0x00000000
#define	US_ALU_ALPHA_ADDR_1__ADDR1__SHIFT                  0x00000006
#define	US_ALU_ALPHA_ADDR_1__ADDR2__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_ADDR_1__ADDRD__SHIFT                  0x00000012
#define	US_ALU_ALPHA_ADDR_1__WMASK__SHIFT                  0x00000017
#define	US_ALU_ALPHA_ADDR_1__OMASK__SHIFT                  0x00000018
#define	US_ALU_ALPHA_ADDR_1__TARGET__SHIFT                 0x00000019
#define	US_ALU_ALPHA_ADDR_1__OMASK_W__SHIFT                0x0000001b
#define	US_ALU_ALPHA_ADDR_1__STAT_WE__SHIFT                0x0000001c

// US_ALU_ALPHA_ADDR_2
#define	US_ALU_ALPHA_ADDR_2__ADDR0__SHIFT                  0x00000000
#define	US_ALU_ALPHA_ADDR_2__ADDR1__SHIFT                  0x00000006
#define	US_ALU_ALPHA_ADDR_2__ADDR2__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_ADDR_2__ADDRD__SHIFT                  0x00000012
#define	US_ALU_ALPHA_ADDR_2__WMASK__SHIFT                  0x00000017
#define	US_ALU_ALPHA_ADDR_2__OMASK__SHIFT                  0x00000018
#define	US_ALU_ALPHA_ADDR_2__TARGET__SHIFT                 0x00000019
#define	US_ALU_ALPHA_ADDR_2__OMASK_W__SHIFT                0x0000001b
#define	US_ALU_ALPHA_ADDR_2__STAT_WE__SHIFT                0x0000001c

// US_ALU_ALPHA_ADDR_3
#define	US_ALU_ALPHA_ADDR_3__ADDR0__SHIFT                  0x00000000
#define	US_ALU_ALPHA_ADDR_3__ADDR1__SHIFT                  0x00000006
#define	US_ALU_ALPHA_ADDR_3__ADDR2__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_ADDR_3__ADDRD__SHIFT                  0x00000012
#define	US_ALU_ALPHA_ADDR_3__WMASK__SHIFT                  0x00000017
#define	US_ALU_ALPHA_ADDR_3__OMASK__SHIFT                  0x00000018
#define	US_ALU_ALPHA_ADDR_3__TARGET__SHIFT                 0x00000019
#define	US_ALU_ALPHA_ADDR_3__OMASK_W__SHIFT                0x0000001b
#define	US_ALU_ALPHA_ADDR_3__STAT_WE__SHIFT                0x0000001c

// US_ALU_ALPHA_ADDR_4
#define	US_ALU_ALPHA_ADDR_4__ADDR0__SHIFT                  0x00000000
#define	US_ALU_ALPHA_ADDR_4__ADDR1__SHIFT                  0x00000006
#define	US_ALU_ALPHA_ADDR_4__ADDR2__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_ADDR_4__ADDRD__SHIFT                  0x00000012
#define	US_ALU_ALPHA_ADDR_4__WMASK__SHIFT                  0x00000017
#define	US_ALU_ALPHA_ADDR_4__OMASK__SHIFT                  0x00000018
#define	US_ALU_ALPHA_ADDR_4__TARGET__SHIFT                 0x00000019
#define	US_ALU_ALPHA_ADDR_4__OMASK_W__SHIFT                0x0000001b
#define	US_ALU_ALPHA_ADDR_4__STAT_WE__SHIFT                0x0000001c

// US_ALU_ALPHA_ADDR_5
#define	US_ALU_ALPHA_ADDR_5__ADDR0__SHIFT                  0x00000000
#define	US_ALU_ALPHA_ADDR_5__ADDR1__SHIFT                  0x00000006
#define	US_ALU_ALPHA_ADDR_5__ADDR2__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_ADDR_5__ADDRD__SHIFT                  0x00000012
#define	US_ALU_ALPHA_ADDR_5__WMASK__SHIFT                  0x00000017
#define	US_ALU_ALPHA_ADDR_5__OMASK__SHIFT                  0x00000018
#define	US_ALU_ALPHA_ADDR_5__TARGET__SHIFT                 0x00000019
#define	US_ALU_ALPHA_ADDR_5__OMASK_W__SHIFT                0x0000001b
#define	US_ALU_ALPHA_ADDR_5__STAT_WE__SHIFT                0x0000001c

// US_ALU_ALPHA_ADDR_6
#define	US_ALU_ALPHA_ADDR_6__ADDR0__SHIFT                  0x00000000
#define	US_ALU_ALPHA_ADDR_6__ADDR1__SHIFT                  0x00000006
#define	US_ALU_ALPHA_ADDR_6__ADDR2__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_ADDR_6__ADDRD__SHIFT                  0x00000012
#define	US_ALU_ALPHA_ADDR_6__WMASK__SHIFT                  0x00000017
#define	US_ALU_ALPHA_ADDR_6__OMASK__SHIFT                  0x00000018
#define	US_ALU_ALPHA_ADDR_6__TARGET__SHIFT                 0x00000019
#define	US_ALU_ALPHA_ADDR_6__OMASK_W__SHIFT                0x0000001b
#define	US_ALU_ALPHA_ADDR_6__STAT_WE__SHIFT                0x0000001c

// US_ALU_ALPHA_ADDR_7
#define	US_ALU_ALPHA_ADDR_7__ADDR0__SHIFT                  0x00000000
#define	US_ALU_ALPHA_ADDR_7__ADDR1__SHIFT                  0x00000006
#define	US_ALU_ALPHA_ADDR_7__ADDR2__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_ADDR_7__ADDRD__SHIFT                  0x00000012
#define	US_ALU_ALPHA_ADDR_7__WMASK__SHIFT                  0x00000017
#define	US_ALU_ALPHA_ADDR_7__OMASK__SHIFT                  0x00000018
#define	US_ALU_ALPHA_ADDR_7__TARGET__SHIFT                 0x00000019
#define	US_ALU_ALPHA_ADDR_7__OMASK_W__SHIFT                0x0000001b
#define	US_ALU_ALPHA_ADDR_7__STAT_WE__SHIFT                0x0000001c

// US_ALU_ALPHA_ADDR_8
#define	US_ALU_ALPHA_ADDR_8__ADDR0__SHIFT                  0x00000000
#define	US_ALU_ALPHA_ADDR_8__ADDR1__SHIFT                  0x00000006
#define	US_ALU_ALPHA_ADDR_8__ADDR2__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_ADDR_8__ADDRD__SHIFT                  0x00000012
#define	US_ALU_ALPHA_ADDR_8__WMASK__SHIFT                  0x00000017
#define	US_ALU_ALPHA_ADDR_8__OMASK__SHIFT                  0x00000018
#define	US_ALU_ALPHA_ADDR_8__TARGET__SHIFT                 0x00000019
#define	US_ALU_ALPHA_ADDR_8__OMASK_W__SHIFT                0x0000001b
#define	US_ALU_ALPHA_ADDR_8__STAT_WE__SHIFT                0x0000001c

// US_ALU_ALPHA_ADDR_9
#define	US_ALU_ALPHA_ADDR_9__ADDR0__SHIFT                  0x00000000
#define	US_ALU_ALPHA_ADDR_9__ADDR1__SHIFT                  0x00000006
#define	US_ALU_ALPHA_ADDR_9__ADDR2__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_ADDR_9__ADDRD__SHIFT                  0x00000012
#define	US_ALU_ALPHA_ADDR_9__WMASK__SHIFT                  0x00000017
#define	US_ALU_ALPHA_ADDR_9__OMASK__SHIFT                  0x00000018
#define	US_ALU_ALPHA_ADDR_9__TARGET__SHIFT                 0x00000019
#define	US_ALU_ALPHA_ADDR_9__OMASK_W__SHIFT                0x0000001b
#define	US_ALU_ALPHA_ADDR_9__STAT_WE__SHIFT                0x0000001c

// US_ALU_ALPHA_ADDR_10
#define	US_ALU_ALPHA_ADDR_10__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_10__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_10__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_10__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_10__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_10__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_10__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_10__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_10__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_11
#define	US_ALU_ALPHA_ADDR_11__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_11__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_11__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_11__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_11__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_11__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_11__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_11__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_11__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_12
#define	US_ALU_ALPHA_ADDR_12__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_12__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_12__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_12__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_12__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_12__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_12__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_12__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_12__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_13
#define	US_ALU_ALPHA_ADDR_13__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_13__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_13__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_13__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_13__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_13__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_13__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_13__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_13__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_14
#define	US_ALU_ALPHA_ADDR_14__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_14__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_14__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_14__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_14__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_14__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_14__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_14__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_14__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_15
#define	US_ALU_ALPHA_ADDR_15__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_15__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_15__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_15__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_15__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_15__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_15__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_15__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_15__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_16
#define	US_ALU_ALPHA_ADDR_16__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_16__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_16__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_16__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_16__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_16__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_16__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_16__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_16__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_17
#define	US_ALU_ALPHA_ADDR_17__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_17__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_17__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_17__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_17__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_17__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_17__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_17__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_17__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_18
#define	US_ALU_ALPHA_ADDR_18__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_18__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_18__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_18__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_18__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_18__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_18__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_18__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_18__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_19
#define	US_ALU_ALPHA_ADDR_19__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_19__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_19__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_19__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_19__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_19__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_19__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_19__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_19__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_20
#define	US_ALU_ALPHA_ADDR_20__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_20__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_20__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_20__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_20__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_20__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_20__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_20__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_20__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_21
#define	US_ALU_ALPHA_ADDR_21__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_21__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_21__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_21__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_21__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_21__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_21__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_21__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_21__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_22
#define	US_ALU_ALPHA_ADDR_22__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_22__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_22__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_22__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_22__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_22__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_22__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_22__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_22__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_23
#define	US_ALU_ALPHA_ADDR_23__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_23__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_23__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_23__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_23__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_23__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_23__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_23__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_23__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_24
#define	US_ALU_ALPHA_ADDR_24__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_24__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_24__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_24__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_24__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_24__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_24__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_24__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_24__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_25
#define	US_ALU_ALPHA_ADDR_25__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_25__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_25__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_25__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_25__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_25__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_25__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_25__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_25__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_26
#define	US_ALU_ALPHA_ADDR_26__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_26__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_26__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_26__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_26__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_26__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_26__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_26__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_26__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_27
#define	US_ALU_ALPHA_ADDR_27__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_27__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_27__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_27__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_27__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_27__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_27__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_27__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_27__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_28
#define	US_ALU_ALPHA_ADDR_28__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_28__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_28__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_28__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_28__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_28__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_28__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_28__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_28__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_29
#define	US_ALU_ALPHA_ADDR_29__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_29__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_29__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_29__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_29__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_29__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_29__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_29__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_29__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_30
#define	US_ALU_ALPHA_ADDR_30__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_30__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_30__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_30__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_30__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_30__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_30__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_30__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_30__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_31
#define	US_ALU_ALPHA_ADDR_31__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_31__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_31__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_31__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_31__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_31__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_31__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_31__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_31__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_32
#define	US_ALU_ALPHA_ADDR_32__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_32__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_32__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_32__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_32__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_32__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_32__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_32__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_32__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_33
#define	US_ALU_ALPHA_ADDR_33__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_33__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_33__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_33__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_33__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_33__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_33__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_33__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_33__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_34
#define	US_ALU_ALPHA_ADDR_34__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_34__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_34__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_34__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_34__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_34__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_34__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_34__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_34__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_35
#define	US_ALU_ALPHA_ADDR_35__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_35__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_35__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_35__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_35__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_35__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_35__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_35__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_35__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_36
#define	US_ALU_ALPHA_ADDR_36__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_36__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_36__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_36__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_36__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_36__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_36__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_36__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_36__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_37
#define	US_ALU_ALPHA_ADDR_37__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_37__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_37__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_37__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_37__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_37__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_37__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_37__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_37__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_38
#define	US_ALU_ALPHA_ADDR_38__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_38__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_38__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_38__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_38__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_38__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_38__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_38__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_38__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_39
#define	US_ALU_ALPHA_ADDR_39__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_39__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_39__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_39__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_39__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_39__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_39__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_39__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_39__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_40
#define	US_ALU_ALPHA_ADDR_40__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_40__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_40__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_40__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_40__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_40__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_40__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_40__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_40__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_41
#define	US_ALU_ALPHA_ADDR_41__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_41__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_41__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_41__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_41__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_41__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_41__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_41__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_41__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_42
#define	US_ALU_ALPHA_ADDR_42__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_42__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_42__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_42__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_42__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_42__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_42__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_42__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_42__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_43
#define	US_ALU_ALPHA_ADDR_43__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_43__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_43__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_43__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_43__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_43__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_43__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_43__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_43__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_44
#define	US_ALU_ALPHA_ADDR_44__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_44__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_44__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_44__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_44__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_44__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_44__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_44__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_44__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_45
#define	US_ALU_ALPHA_ADDR_45__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_45__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_45__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_45__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_45__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_45__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_45__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_45__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_45__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_46
#define	US_ALU_ALPHA_ADDR_46__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_46__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_46__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_46__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_46__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_46__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_46__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_46__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_46__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_47
#define	US_ALU_ALPHA_ADDR_47__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_47__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_47__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_47__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_47__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_47__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_47__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_47__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_47__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_48
#define	US_ALU_ALPHA_ADDR_48__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_48__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_48__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_48__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_48__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_48__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_48__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_48__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_48__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_49
#define	US_ALU_ALPHA_ADDR_49__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_49__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_49__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_49__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_49__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_49__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_49__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_49__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_49__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_50
#define	US_ALU_ALPHA_ADDR_50__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_50__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_50__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_50__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_50__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_50__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_50__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_50__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_50__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_51
#define	US_ALU_ALPHA_ADDR_51__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_51__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_51__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_51__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_51__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_51__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_51__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_51__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_51__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_52
#define	US_ALU_ALPHA_ADDR_52__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_52__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_52__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_52__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_52__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_52__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_52__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_52__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_52__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_53
#define	US_ALU_ALPHA_ADDR_53__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_53__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_53__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_53__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_53__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_53__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_53__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_53__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_53__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_54
#define	US_ALU_ALPHA_ADDR_54__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_54__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_54__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_54__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_54__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_54__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_54__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_54__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_54__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_55
#define	US_ALU_ALPHA_ADDR_55__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_55__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_55__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_55__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_55__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_55__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_55__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_55__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_55__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_56
#define	US_ALU_ALPHA_ADDR_56__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_56__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_56__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_56__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_56__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_56__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_56__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_56__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_56__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_57
#define	US_ALU_ALPHA_ADDR_57__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_57__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_57__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_57__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_57__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_57__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_57__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_57__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_57__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_58
#define	US_ALU_ALPHA_ADDR_58__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_58__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_58__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_58__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_58__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_58__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_58__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_58__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_58__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_59
#define	US_ALU_ALPHA_ADDR_59__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_59__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_59__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_59__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_59__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_59__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_59__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_59__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_59__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_60
#define	US_ALU_ALPHA_ADDR_60__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_60__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_60__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_60__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_60__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_60__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_60__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_60__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_60__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_61
#define	US_ALU_ALPHA_ADDR_61__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_61__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_61__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_61__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_61__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_61__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_61__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_61__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_61__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_62
#define	US_ALU_ALPHA_ADDR_62__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_62__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_62__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_62__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_62__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_62__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_62__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_62__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_62__STAT_WE__SHIFT               0x0000001c

// US_ALU_ALPHA_ADDR_63
#define	US_ALU_ALPHA_ADDR_63__ADDR0__SHIFT                 0x00000000
#define	US_ALU_ALPHA_ADDR_63__ADDR1__SHIFT                 0x00000006
#define	US_ALU_ALPHA_ADDR_63__ADDR2__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_ADDR_63__ADDRD__SHIFT                 0x00000012
#define	US_ALU_ALPHA_ADDR_63__WMASK__SHIFT                 0x00000017
#define	US_ALU_ALPHA_ADDR_63__OMASK__SHIFT                 0x00000018
#define	US_ALU_ALPHA_ADDR_63__TARGET__SHIFT                0x00000019
#define	US_ALU_ALPHA_ADDR_63__OMASK_W__SHIFT               0x0000001b
#define	US_ALU_ALPHA_ADDR_63__STAT_WE__SHIFT               0x0000001c

// US_ALU_RGB_INST_0
#define	US_ALU_RGB_INST_0__SEL_A__SHIFT                    0x00000000
#define	US_ALU_RGB_INST_0__MOD_A__SHIFT                    0x00000005
#define	US_ALU_RGB_INST_0__SEL_B__SHIFT                    0x00000007
#define	US_ALU_RGB_INST_0__MOD_B__SHIFT                    0x0000000c
#define	US_ALU_RGB_INST_0__SEL_C__SHIFT                    0x0000000e
#define	US_ALU_RGB_INST_0__MOD_C__SHIFT                    0x00000013
#define	US_ALU_RGB_INST_0__SRCP_OP__SHIFT                  0x00000015
#define	US_ALU_RGB_INST_0__OP__SHIFT                       0x00000017
#define	US_ALU_RGB_INST_0__OMOD__SHIFT                     0x0000001b
#define	US_ALU_RGB_INST_0__CLAMP__SHIFT                    0x0000001e
#define	US_ALU_RGB_INST_0__NOP__SHIFT                      0x0000001f

// US_ALU_RGB_INST_1
#define	US_ALU_RGB_INST_1__SEL_A__SHIFT                    0x00000000
#define	US_ALU_RGB_INST_1__MOD_A__SHIFT                    0x00000005
#define	US_ALU_RGB_INST_1__SEL_B__SHIFT                    0x00000007
#define	US_ALU_RGB_INST_1__MOD_B__SHIFT                    0x0000000c
#define	US_ALU_RGB_INST_1__SEL_C__SHIFT                    0x0000000e
#define	US_ALU_RGB_INST_1__MOD_C__SHIFT                    0x00000013
#define	US_ALU_RGB_INST_1__SRCP_OP__SHIFT                  0x00000015
#define	US_ALU_RGB_INST_1__OP__SHIFT                       0x00000017
#define	US_ALU_RGB_INST_1__OMOD__SHIFT                     0x0000001b
#define	US_ALU_RGB_INST_1__CLAMP__SHIFT                    0x0000001e
#define	US_ALU_RGB_INST_1__NOP__SHIFT                      0x0000001f

// US_ALU_RGB_INST_2
#define	US_ALU_RGB_INST_2__SEL_A__SHIFT                    0x00000000
#define	US_ALU_RGB_INST_2__MOD_A__SHIFT                    0x00000005
#define	US_ALU_RGB_INST_2__SEL_B__SHIFT                    0x00000007
#define	US_ALU_RGB_INST_2__MOD_B__SHIFT                    0x0000000c
#define	US_ALU_RGB_INST_2__SEL_C__SHIFT                    0x0000000e
#define	US_ALU_RGB_INST_2__MOD_C__SHIFT                    0x00000013
#define	US_ALU_RGB_INST_2__SRCP_OP__SHIFT                  0x00000015
#define	US_ALU_RGB_INST_2__OP__SHIFT                       0x00000017
#define	US_ALU_RGB_INST_2__OMOD__SHIFT                     0x0000001b
#define	US_ALU_RGB_INST_2__CLAMP__SHIFT                    0x0000001e
#define	US_ALU_RGB_INST_2__NOP__SHIFT                      0x0000001f

// US_ALU_RGB_INST_3
#define	US_ALU_RGB_INST_3__SEL_A__SHIFT                    0x00000000
#define	US_ALU_RGB_INST_3__MOD_A__SHIFT                    0x00000005
#define	US_ALU_RGB_INST_3__SEL_B__SHIFT                    0x00000007
#define	US_ALU_RGB_INST_3__MOD_B__SHIFT                    0x0000000c
#define	US_ALU_RGB_INST_3__SEL_C__SHIFT                    0x0000000e
#define	US_ALU_RGB_INST_3__MOD_C__SHIFT                    0x00000013
#define	US_ALU_RGB_INST_3__SRCP_OP__SHIFT                  0x00000015
#define	US_ALU_RGB_INST_3__OP__SHIFT                       0x00000017
#define	US_ALU_RGB_INST_3__OMOD__SHIFT                     0x0000001b
#define	US_ALU_RGB_INST_3__CLAMP__SHIFT                    0x0000001e
#define	US_ALU_RGB_INST_3__NOP__SHIFT                      0x0000001f

// US_ALU_RGB_INST_4
#define	US_ALU_RGB_INST_4__SEL_A__SHIFT                    0x00000000
#define	US_ALU_RGB_INST_4__MOD_A__SHIFT                    0x00000005
#define	US_ALU_RGB_INST_4__SEL_B__SHIFT                    0x00000007
#define	US_ALU_RGB_INST_4__MOD_B__SHIFT                    0x0000000c
#define	US_ALU_RGB_INST_4__SEL_C__SHIFT                    0x0000000e
#define	US_ALU_RGB_INST_4__MOD_C__SHIFT                    0x00000013
#define	US_ALU_RGB_INST_4__SRCP_OP__SHIFT                  0x00000015
#define	US_ALU_RGB_INST_4__OP__SHIFT                       0x00000017
#define	US_ALU_RGB_INST_4__OMOD__SHIFT                     0x0000001b
#define	US_ALU_RGB_INST_4__CLAMP__SHIFT                    0x0000001e
#define	US_ALU_RGB_INST_4__NOP__SHIFT                      0x0000001f

// US_ALU_RGB_INST_5
#define	US_ALU_RGB_INST_5__SEL_A__SHIFT                    0x00000000
#define	US_ALU_RGB_INST_5__MOD_A__SHIFT                    0x00000005
#define	US_ALU_RGB_INST_5__SEL_B__SHIFT                    0x00000007
#define	US_ALU_RGB_INST_5__MOD_B__SHIFT                    0x0000000c
#define	US_ALU_RGB_INST_5__SEL_C__SHIFT                    0x0000000e
#define	US_ALU_RGB_INST_5__MOD_C__SHIFT                    0x00000013
#define	US_ALU_RGB_INST_5__SRCP_OP__SHIFT                  0x00000015
#define	US_ALU_RGB_INST_5__OP__SHIFT                       0x00000017
#define	US_ALU_RGB_INST_5__OMOD__SHIFT                     0x0000001b
#define	US_ALU_RGB_INST_5__CLAMP__SHIFT                    0x0000001e
#define	US_ALU_RGB_INST_5__NOP__SHIFT                      0x0000001f

// US_ALU_RGB_INST_6
#define	US_ALU_RGB_INST_6__SEL_A__SHIFT                    0x00000000
#define	US_ALU_RGB_INST_6__MOD_A__SHIFT                    0x00000005
#define	US_ALU_RGB_INST_6__SEL_B__SHIFT                    0x00000007
#define	US_ALU_RGB_INST_6__MOD_B__SHIFT                    0x0000000c
#define	US_ALU_RGB_INST_6__SEL_C__SHIFT                    0x0000000e
#define	US_ALU_RGB_INST_6__MOD_C__SHIFT                    0x00000013
#define	US_ALU_RGB_INST_6__SRCP_OP__SHIFT                  0x00000015
#define	US_ALU_RGB_INST_6__OP__SHIFT                       0x00000017
#define	US_ALU_RGB_INST_6__OMOD__SHIFT                     0x0000001b
#define	US_ALU_RGB_INST_6__CLAMP__SHIFT                    0x0000001e
#define	US_ALU_RGB_INST_6__NOP__SHIFT                      0x0000001f

// US_ALU_RGB_INST_7
#define	US_ALU_RGB_INST_7__SEL_A__SHIFT                    0x00000000
#define	US_ALU_RGB_INST_7__MOD_A__SHIFT                    0x00000005
#define	US_ALU_RGB_INST_7__SEL_B__SHIFT                    0x00000007
#define	US_ALU_RGB_INST_7__MOD_B__SHIFT                    0x0000000c
#define	US_ALU_RGB_INST_7__SEL_C__SHIFT                    0x0000000e
#define	US_ALU_RGB_INST_7__MOD_C__SHIFT                    0x00000013
#define	US_ALU_RGB_INST_7__SRCP_OP__SHIFT                  0x00000015
#define	US_ALU_RGB_INST_7__OP__SHIFT                       0x00000017
#define	US_ALU_RGB_INST_7__OMOD__SHIFT                     0x0000001b
#define	US_ALU_RGB_INST_7__CLAMP__SHIFT                    0x0000001e
#define	US_ALU_RGB_INST_7__NOP__SHIFT                      0x0000001f

// US_ALU_RGB_INST_8
#define	US_ALU_RGB_INST_8__SEL_A__SHIFT                    0x00000000
#define	US_ALU_RGB_INST_8__MOD_A__SHIFT                    0x00000005
#define	US_ALU_RGB_INST_8__SEL_B__SHIFT                    0x00000007
#define	US_ALU_RGB_INST_8__MOD_B__SHIFT                    0x0000000c
#define	US_ALU_RGB_INST_8__SEL_C__SHIFT                    0x0000000e
#define	US_ALU_RGB_INST_8__MOD_C__SHIFT                    0x00000013
#define	US_ALU_RGB_INST_8__SRCP_OP__SHIFT                  0x00000015
#define	US_ALU_RGB_INST_8__OP__SHIFT                       0x00000017
#define	US_ALU_RGB_INST_8__OMOD__SHIFT                     0x0000001b
#define	US_ALU_RGB_INST_8__CLAMP__SHIFT                    0x0000001e
#define	US_ALU_RGB_INST_8__NOP__SHIFT                      0x0000001f

// US_ALU_RGB_INST_9
#define	US_ALU_RGB_INST_9__SEL_A__SHIFT                    0x00000000
#define	US_ALU_RGB_INST_9__MOD_A__SHIFT                    0x00000005
#define	US_ALU_RGB_INST_9__SEL_B__SHIFT                    0x00000007
#define	US_ALU_RGB_INST_9__MOD_B__SHIFT                    0x0000000c
#define	US_ALU_RGB_INST_9__SEL_C__SHIFT                    0x0000000e
#define	US_ALU_RGB_INST_9__MOD_C__SHIFT                    0x00000013
#define	US_ALU_RGB_INST_9__SRCP_OP__SHIFT                  0x00000015
#define	US_ALU_RGB_INST_9__OP__SHIFT                       0x00000017
#define	US_ALU_RGB_INST_9__OMOD__SHIFT                     0x0000001b
#define	US_ALU_RGB_INST_9__CLAMP__SHIFT                    0x0000001e
#define	US_ALU_RGB_INST_9__NOP__SHIFT                      0x0000001f

// US_ALU_RGB_INST_10
#define	US_ALU_RGB_INST_10__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_10__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_10__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_10__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_10__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_10__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_10__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_10__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_10__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_10__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_10__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_11
#define	US_ALU_RGB_INST_11__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_11__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_11__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_11__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_11__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_11__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_11__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_11__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_11__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_11__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_11__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_12
#define	US_ALU_RGB_INST_12__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_12__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_12__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_12__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_12__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_12__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_12__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_12__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_12__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_12__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_12__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_13
#define	US_ALU_RGB_INST_13__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_13__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_13__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_13__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_13__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_13__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_13__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_13__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_13__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_13__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_13__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_14
#define	US_ALU_RGB_INST_14__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_14__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_14__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_14__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_14__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_14__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_14__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_14__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_14__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_14__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_14__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_15
#define	US_ALU_RGB_INST_15__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_15__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_15__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_15__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_15__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_15__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_15__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_15__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_15__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_15__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_15__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_16
#define	US_ALU_RGB_INST_16__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_16__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_16__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_16__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_16__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_16__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_16__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_16__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_16__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_16__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_16__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_17
#define	US_ALU_RGB_INST_17__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_17__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_17__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_17__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_17__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_17__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_17__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_17__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_17__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_17__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_17__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_18
#define	US_ALU_RGB_INST_18__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_18__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_18__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_18__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_18__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_18__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_18__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_18__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_18__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_18__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_18__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_19
#define	US_ALU_RGB_INST_19__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_19__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_19__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_19__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_19__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_19__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_19__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_19__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_19__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_19__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_19__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_20
#define	US_ALU_RGB_INST_20__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_20__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_20__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_20__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_20__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_20__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_20__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_20__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_20__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_20__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_20__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_21
#define	US_ALU_RGB_INST_21__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_21__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_21__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_21__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_21__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_21__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_21__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_21__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_21__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_21__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_21__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_22
#define	US_ALU_RGB_INST_22__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_22__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_22__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_22__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_22__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_22__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_22__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_22__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_22__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_22__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_22__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_23
#define	US_ALU_RGB_INST_23__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_23__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_23__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_23__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_23__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_23__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_23__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_23__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_23__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_23__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_23__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_24
#define	US_ALU_RGB_INST_24__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_24__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_24__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_24__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_24__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_24__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_24__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_24__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_24__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_24__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_24__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_25
#define	US_ALU_RGB_INST_25__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_25__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_25__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_25__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_25__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_25__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_25__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_25__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_25__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_25__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_25__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_26
#define	US_ALU_RGB_INST_26__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_26__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_26__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_26__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_26__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_26__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_26__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_26__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_26__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_26__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_26__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_27
#define	US_ALU_RGB_INST_27__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_27__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_27__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_27__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_27__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_27__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_27__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_27__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_27__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_27__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_27__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_28
#define	US_ALU_RGB_INST_28__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_28__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_28__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_28__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_28__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_28__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_28__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_28__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_28__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_28__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_28__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_29
#define	US_ALU_RGB_INST_29__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_29__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_29__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_29__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_29__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_29__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_29__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_29__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_29__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_29__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_29__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_30
#define	US_ALU_RGB_INST_30__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_30__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_30__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_30__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_30__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_30__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_30__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_30__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_30__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_30__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_30__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_31
#define	US_ALU_RGB_INST_31__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_31__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_31__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_31__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_31__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_31__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_31__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_31__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_31__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_31__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_31__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_32
#define	US_ALU_RGB_INST_32__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_32__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_32__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_32__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_32__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_32__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_32__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_32__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_32__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_32__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_32__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_33
#define	US_ALU_RGB_INST_33__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_33__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_33__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_33__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_33__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_33__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_33__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_33__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_33__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_33__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_33__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_34
#define	US_ALU_RGB_INST_34__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_34__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_34__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_34__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_34__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_34__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_34__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_34__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_34__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_34__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_34__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_35
#define	US_ALU_RGB_INST_35__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_35__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_35__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_35__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_35__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_35__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_35__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_35__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_35__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_35__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_35__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_36
#define	US_ALU_RGB_INST_36__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_36__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_36__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_36__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_36__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_36__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_36__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_36__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_36__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_36__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_36__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_37
#define	US_ALU_RGB_INST_37__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_37__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_37__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_37__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_37__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_37__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_37__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_37__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_37__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_37__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_37__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_38
#define	US_ALU_RGB_INST_38__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_38__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_38__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_38__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_38__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_38__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_38__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_38__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_38__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_38__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_38__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_39
#define	US_ALU_RGB_INST_39__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_39__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_39__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_39__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_39__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_39__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_39__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_39__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_39__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_39__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_39__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_40
#define	US_ALU_RGB_INST_40__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_40__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_40__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_40__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_40__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_40__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_40__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_40__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_40__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_40__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_40__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_41
#define	US_ALU_RGB_INST_41__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_41__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_41__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_41__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_41__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_41__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_41__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_41__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_41__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_41__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_41__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_42
#define	US_ALU_RGB_INST_42__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_42__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_42__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_42__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_42__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_42__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_42__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_42__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_42__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_42__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_42__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_43
#define	US_ALU_RGB_INST_43__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_43__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_43__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_43__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_43__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_43__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_43__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_43__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_43__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_43__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_43__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_44
#define	US_ALU_RGB_INST_44__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_44__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_44__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_44__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_44__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_44__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_44__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_44__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_44__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_44__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_44__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_45
#define	US_ALU_RGB_INST_45__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_45__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_45__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_45__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_45__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_45__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_45__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_45__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_45__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_45__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_45__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_46
#define	US_ALU_RGB_INST_46__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_46__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_46__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_46__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_46__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_46__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_46__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_46__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_46__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_46__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_46__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_47
#define	US_ALU_RGB_INST_47__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_47__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_47__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_47__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_47__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_47__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_47__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_47__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_47__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_47__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_47__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_48
#define	US_ALU_RGB_INST_48__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_48__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_48__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_48__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_48__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_48__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_48__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_48__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_48__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_48__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_48__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_49
#define	US_ALU_RGB_INST_49__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_49__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_49__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_49__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_49__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_49__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_49__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_49__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_49__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_49__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_49__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_50
#define	US_ALU_RGB_INST_50__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_50__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_50__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_50__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_50__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_50__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_50__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_50__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_50__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_50__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_50__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_51
#define	US_ALU_RGB_INST_51__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_51__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_51__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_51__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_51__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_51__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_51__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_51__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_51__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_51__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_51__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_52
#define	US_ALU_RGB_INST_52__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_52__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_52__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_52__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_52__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_52__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_52__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_52__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_52__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_52__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_52__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_53
#define	US_ALU_RGB_INST_53__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_53__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_53__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_53__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_53__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_53__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_53__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_53__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_53__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_53__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_53__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_54
#define	US_ALU_RGB_INST_54__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_54__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_54__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_54__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_54__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_54__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_54__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_54__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_54__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_54__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_54__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_55
#define	US_ALU_RGB_INST_55__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_55__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_55__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_55__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_55__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_55__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_55__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_55__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_55__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_55__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_55__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_56
#define	US_ALU_RGB_INST_56__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_56__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_56__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_56__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_56__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_56__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_56__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_56__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_56__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_56__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_56__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_57
#define	US_ALU_RGB_INST_57__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_57__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_57__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_57__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_57__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_57__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_57__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_57__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_57__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_57__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_57__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_58
#define	US_ALU_RGB_INST_58__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_58__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_58__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_58__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_58__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_58__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_58__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_58__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_58__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_58__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_58__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_59
#define	US_ALU_RGB_INST_59__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_59__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_59__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_59__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_59__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_59__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_59__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_59__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_59__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_59__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_59__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_60
#define	US_ALU_RGB_INST_60__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_60__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_60__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_60__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_60__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_60__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_60__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_60__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_60__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_60__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_60__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_61
#define	US_ALU_RGB_INST_61__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_61__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_61__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_61__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_61__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_61__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_61__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_61__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_61__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_61__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_61__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_62
#define	US_ALU_RGB_INST_62__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_62__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_62__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_62__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_62__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_62__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_62__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_62__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_62__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_62__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_62__NOP__SHIFT                     0x0000001f

// US_ALU_RGB_INST_63
#define	US_ALU_RGB_INST_63__SEL_A__SHIFT                   0x00000000
#define	US_ALU_RGB_INST_63__MOD_A__SHIFT                   0x00000005
#define	US_ALU_RGB_INST_63__SEL_B__SHIFT                   0x00000007
#define	US_ALU_RGB_INST_63__MOD_B__SHIFT                   0x0000000c
#define	US_ALU_RGB_INST_63__SEL_C__SHIFT                   0x0000000e
#define	US_ALU_RGB_INST_63__MOD_C__SHIFT                   0x00000013
#define	US_ALU_RGB_INST_63__SRCP_OP__SHIFT                 0x00000015
#define	US_ALU_RGB_INST_63__OP__SHIFT                      0x00000017
#define	US_ALU_RGB_INST_63__OMOD__SHIFT                    0x0000001b
#define	US_ALU_RGB_INST_63__CLAMP__SHIFT                   0x0000001e
#define	US_ALU_RGB_INST_63__NOP__SHIFT                     0x0000001f

// US_ALU_ALPHA_INST_0
#define	US_ALU_ALPHA_INST_0__SEL_A__SHIFT                  0x00000000
#define	US_ALU_ALPHA_INST_0__MOD_A__SHIFT                  0x00000005
#define	US_ALU_ALPHA_INST_0__SEL_B__SHIFT                  0x00000007
#define	US_ALU_ALPHA_INST_0__MOD_B__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_INST_0__SEL_C__SHIFT                  0x0000000e
#define	US_ALU_ALPHA_INST_0__MOD_C__SHIFT                  0x00000013
#define	US_ALU_ALPHA_INST_0__SRCP_OP__SHIFT                0x00000015
#define	US_ALU_ALPHA_INST_0__OP__SHIFT                     0x00000017
#define	US_ALU_ALPHA_INST_0__OMOD__SHIFT                   0x0000001b
#define	US_ALU_ALPHA_INST_0__CLAMP__SHIFT                  0x0000001e

// US_ALU_ALPHA_INST_1
#define	US_ALU_ALPHA_INST_1__SEL_A__SHIFT                  0x00000000
#define	US_ALU_ALPHA_INST_1__MOD_A__SHIFT                  0x00000005
#define	US_ALU_ALPHA_INST_1__SEL_B__SHIFT                  0x00000007
#define	US_ALU_ALPHA_INST_1__MOD_B__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_INST_1__SEL_C__SHIFT                  0x0000000e
#define	US_ALU_ALPHA_INST_1__MOD_C__SHIFT                  0x00000013
#define	US_ALU_ALPHA_INST_1__SRCP_OP__SHIFT                0x00000015
#define	US_ALU_ALPHA_INST_1__OP__SHIFT                     0x00000017
#define	US_ALU_ALPHA_INST_1__OMOD__SHIFT                   0x0000001b
#define	US_ALU_ALPHA_INST_1__CLAMP__SHIFT                  0x0000001e

// US_ALU_ALPHA_INST_2
#define	US_ALU_ALPHA_INST_2__SEL_A__SHIFT                  0x00000000
#define	US_ALU_ALPHA_INST_2__MOD_A__SHIFT                  0x00000005
#define	US_ALU_ALPHA_INST_2__SEL_B__SHIFT                  0x00000007
#define	US_ALU_ALPHA_INST_2__MOD_B__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_INST_2__SEL_C__SHIFT                  0x0000000e
#define	US_ALU_ALPHA_INST_2__MOD_C__SHIFT                  0x00000013
#define	US_ALU_ALPHA_INST_2__SRCP_OP__SHIFT                0x00000015
#define	US_ALU_ALPHA_INST_2__OP__SHIFT                     0x00000017
#define	US_ALU_ALPHA_INST_2__OMOD__SHIFT                   0x0000001b
#define	US_ALU_ALPHA_INST_2__CLAMP__SHIFT                  0x0000001e

// US_ALU_ALPHA_INST_3
#define	US_ALU_ALPHA_INST_3__SEL_A__SHIFT                  0x00000000
#define	US_ALU_ALPHA_INST_3__MOD_A__SHIFT                  0x00000005
#define	US_ALU_ALPHA_INST_3__SEL_B__SHIFT                  0x00000007
#define	US_ALU_ALPHA_INST_3__MOD_B__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_INST_3__SEL_C__SHIFT                  0x0000000e
#define	US_ALU_ALPHA_INST_3__MOD_C__SHIFT                  0x00000013
#define	US_ALU_ALPHA_INST_3__SRCP_OP__SHIFT                0x00000015
#define	US_ALU_ALPHA_INST_3__OP__SHIFT                     0x00000017
#define	US_ALU_ALPHA_INST_3__OMOD__SHIFT                   0x0000001b
#define	US_ALU_ALPHA_INST_3__CLAMP__SHIFT                  0x0000001e

// US_ALU_ALPHA_INST_4
#define	US_ALU_ALPHA_INST_4__SEL_A__SHIFT                  0x00000000
#define	US_ALU_ALPHA_INST_4__MOD_A__SHIFT                  0x00000005
#define	US_ALU_ALPHA_INST_4__SEL_B__SHIFT                  0x00000007
#define	US_ALU_ALPHA_INST_4__MOD_B__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_INST_4__SEL_C__SHIFT                  0x0000000e
#define	US_ALU_ALPHA_INST_4__MOD_C__SHIFT                  0x00000013
#define	US_ALU_ALPHA_INST_4__SRCP_OP__SHIFT                0x00000015
#define	US_ALU_ALPHA_INST_4__OP__SHIFT                     0x00000017
#define	US_ALU_ALPHA_INST_4__OMOD__SHIFT                   0x0000001b
#define	US_ALU_ALPHA_INST_4__CLAMP__SHIFT                  0x0000001e

// US_ALU_ALPHA_INST_5
#define	US_ALU_ALPHA_INST_5__SEL_A__SHIFT                  0x00000000
#define	US_ALU_ALPHA_INST_5__MOD_A__SHIFT                  0x00000005
#define	US_ALU_ALPHA_INST_5__SEL_B__SHIFT                  0x00000007
#define	US_ALU_ALPHA_INST_5__MOD_B__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_INST_5__SEL_C__SHIFT                  0x0000000e
#define	US_ALU_ALPHA_INST_5__MOD_C__SHIFT                  0x00000013
#define	US_ALU_ALPHA_INST_5__SRCP_OP__SHIFT                0x00000015
#define	US_ALU_ALPHA_INST_5__OP__SHIFT                     0x00000017
#define	US_ALU_ALPHA_INST_5__OMOD__SHIFT                   0x0000001b
#define	US_ALU_ALPHA_INST_5__CLAMP__SHIFT                  0x0000001e

// US_ALU_ALPHA_INST_6
#define	US_ALU_ALPHA_INST_6__SEL_A__SHIFT                  0x00000000
#define	US_ALU_ALPHA_INST_6__MOD_A__SHIFT                  0x00000005
#define	US_ALU_ALPHA_INST_6__SEL_B__SHIFT                  0x00000007
#define	US_ALU_ALPHA_INST_6__MOD_B__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_INST_6__SEL_C__SHIFT                  0x0000000e
#define	US_ALU_ALPHA_INST_6__MOD_C__SHIFT                  0x00000013
#define	US_ALU_ALPHA_INST_6__SRCP_OP__SHIFT                0x00000015
#define	US_ALU_ALPHA_INST_6__OP__SHIFT                     0x00000017
#define	US_ALU_ALPHA_INST_6__OMOD__SHIFT                   0x0000001b
#define	US_ALU_ALPHA_INST_6__CLAMP__SHIFT                  0x0000001e

// US_ALU_ALPHA_INST_7
#define	US_ALU_ALPHA_INST_7__SEL_A__SHIFT                  0x00000000
#define	US_ALU_ALPHA_INST_7__MOD_A__SHIFT                  0x00000005
#define	US_ALU_ALPHA_INST_7__SEL_B__SHIFT                  0x00000007
#define	US_ALU_ALPHA_INST_7__MOD_B__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_INST_7__SEL_C__SHIFT                  0x0000000e
#define	US_ALU_ALPHA_INST_7__MOD_C__SHIFT                  0x00000013
#define	US_ALU_ALPHA_INST_7__SRCP_OP__SHIFT                0x00000015
#define	US_ALU_ALPHA_INST_7__OP__SHIFT                     0x00000017
#define	US_ALU_ALPHA_INST_7__OMOD__SHIFT                   0x0000001b
#define	US_ALU_ALPHA_INST_7__CLAMP__SHIFT                  0x0000001e

// US_ALU_ALPHA_INST_8
#define	US_ALU_ALPHA_INST_8__SEL_A__SHIFT                  0x00000000
#define	US_ALU_ALPHA_INST_8__MOD_A__SHIFT                  0x00000005
#define	US_ALU_ALPHA_INST_8__SEL_B__SHIFT                  0x00000007
#define	US_ALU_ALPHA_INST_8__MOD_B__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_INST_8__SEL_C__SHIFT                  0x0000000e
#define	US_ALU_ALPHA_INST_8__MOD_C__SHIFT                  0x00000013
#define	US_ALU_ALPHA_INST_8__SRCP_OP__SHIFT                0x00000015
#define	US_ALU_ALPHA_INST_8__OP__SHIFT                     0x00000017
#define	US_ALU_ALPHA_INST_8__OMOD__SHIFT                   0x0000001b
#define	US_ALU_ALPHA_INST_8__CLAMP__SHIFT                  0x0000001e

// US_ALU_ALPHA_INST_9
#define	US_ALU_ALPHA_INST_9__SEL_A__SHIFT                  0x00000000
#define	US_ALU_ALPHA_INST_9__MOD_A__SHIFT                  0x00000005
#define	US_ALU_ALPHA_INST_9__SEL_B__SHIFT                  0x00000007
#define	US_ALU_ALPHA_INST_9__MOD_B__SHIFT                  0x0000000c
#define	US_ALU_ALPHA_INST_9__SEL_C__SHIFT                  0x0000000e
#define	US_ALU_ALPHA_INST_9__MOD_C__SHIFT                  0x00000013
#define	US_ALU_ALPHA_INST_9__SRCP_OP__SHIFT                0x00000015
#define	US_ALU_ALPHA_INST_9__OP__SHIFT                     0x00000017
#define	US_ALU_ALPHA_INST_9__OMOD__SHIFT                   0x0000001b
#define	US_ALU_ALPHA_INST_9__CLAMP__SHIFT                  0x0000001e

// US_ALU_ALPHA_INST_10
#define	US_ALU_ALPHA_INST_10__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_10__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_10__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_10__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_10__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_10__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_10__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_10__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_10__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_10__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_11
#define	US_ALU_ALPHA_INST_11__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_11__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_11__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_11__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_11__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_11__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_11__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_11__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_11__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_11__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_12
#define	US_ALU_ALPHA_INST_12__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_12__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_12__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_12__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_12__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_12__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_12__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_12__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_12__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_12__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_13
#define	US_ALU_ALPHA_INST_13__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_13__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_13__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_13__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_13__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_13__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_13__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_13__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_13__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_13__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_14
#define	US_ALU_ALPHA_INST_14__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_14__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_14__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_14__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_14__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_14__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_14__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_14__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_14__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_14__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_15
#define	US_ALU_ALPHA_INST_15__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_15__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_15__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_15__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_15__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_15__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_15__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_15__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_15__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_15__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_16
#define	US_ALU_ALPHA_INST_16__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_16__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_16__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_16__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_16__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_16__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_16__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_16__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_16__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_16__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_17
#define	US_ALU_ALPHA_INST_17__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_17__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_17__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_17__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_17__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_17__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_17__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_17__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_17__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_17__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_18
#define	US_ALU_ALPHA_INST_18__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_18__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_18__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_18__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_18__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_18__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_18__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_18__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_18__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_18__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_19
#define	US_ALU_ALPHA_INST_19__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_19__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_19__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_19__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_19__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_19__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_19__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_19__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_19__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_19__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_20
#define	US_ALU_ALPHA_INST_20__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_20__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_20__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_20__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_20__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_20__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_20__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_20__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_20__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_20__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_21
#define	US_ALU_ALPHA_INST_21__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_21__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_21__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_21__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_21__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_21__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_21__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_21__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_21__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_21__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_22
#define	US_ALU_ALPHA_INST_22__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_22__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_22__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_22__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_22__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_22__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_22__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_22__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_22__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_22__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_23
#define	US_ALU_ALPHA_INST_23__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_23__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_23__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_23__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_23__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_23__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_23__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_23__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_23__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_23__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_24
#define	US_ALU_ALPHA_INST_24__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_24__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_24__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_24__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_24__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_24__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_24__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_24__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_24__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_24__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_25
#define	US_ALU_ALPHA_INST_25__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_25__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_25__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_25__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_25__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_25__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_25__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_25__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_25__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_25__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_26
#define	US_ALU_ALPHA_INST_26__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_26__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_26__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_26__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_26__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_26__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_26__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_26__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_26__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_26__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_27
#define	US_ALU_ALPHA_INST_27__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_27__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_27__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_27__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_27__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_27__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_27__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_27__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_27__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_27__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_28
#define	US_ALU_ALPHA_INST_28__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_28__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_28__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_28__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_28__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_28__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_28__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_28__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_28__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_28__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_29
#define	US_ALU_ALPHA_INST_29__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_29__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_29__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_29__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_29__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_29__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_29__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_29__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_29__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_29__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_30
#define	US_ALU_ALPHA_INST_30__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_30__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_30__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_30__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_30__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_30__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_30__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_30__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_30__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_30__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_31
#define	US_ALU_ALPHA_INST_31__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_31__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_31__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_31__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_31__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_31__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_31__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_31__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_31__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_31__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_32
#define	US_ALU_ALPHA_INST_32__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_32__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_32__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_32__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_32__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_32__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_32__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_32__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_32__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_32__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_33
#define	US_ALU_ALPHA_INST_33__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_33__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_33__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_33__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_33__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_33__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_33__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_33__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_33__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_33__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_34
#define	US_ALU_ALPHA_INST_34__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_34__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_34__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_34__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_34__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_34__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_34__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_34__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_34__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_34__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_35
#define	US_ALU_ALPHA_INST_35__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_35__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_35__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_35__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_35__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_35__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_35__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_35__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_35__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_35__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_36
#define	US_ALU_ALPHA_INST_36__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_36__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_36__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_36__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_36__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_36__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_36__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_36__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_36__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_36__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_37
#define	US_ALU_ALPHA_INST_37__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_37__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_37__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_37__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_37__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_37__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_37__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_37__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_37__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_37__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_38
#define	US_ALU_ALPHA_INST_38__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_38__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_38__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_38__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_38__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_38__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_38__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_38__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_38__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_38__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_39
#define	US_ALU_ALPHA_INST_39__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_39__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_39__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_39__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_39__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_39__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_39__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_39__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_39__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_39__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_40
#define	US_ALU_ALPHA_INST_40__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_40__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_40__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_40__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_40__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_40__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_40__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_40__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_40__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_40__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_41
#define	US_ALU_ALPHA_INST_41__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_41__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_41__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_41__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_41__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_41__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_41__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_41__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_41__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_41__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_42
#define	US_ALU_ALPHA_INST_42__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_42__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_42__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_42__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_42__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_42__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_42__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_42__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_42__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_42__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_43
#define	US_ALU_ALPHA_INST_43__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_43__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_43__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_43__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_43__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_43__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_43__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_43__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_43__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_43__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_44
#define	US_ALU_ALPHA_INST_44__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_44__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_44__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_44__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_44__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_44__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_44__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_44__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_44__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_44__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_45
#define	US_ALU_ALPHA_INST_45__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_45__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_45__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_45__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_45__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_45__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_45__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_45__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_45__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_45__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_46
#define	US_ALU_ALPHA_INST_46__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_46__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_46__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_46__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_46__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_46__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_46__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_46__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_46__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_46__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_47
#define	US_ALU_ALPHA_INST_47__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_47__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_47__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_47__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_47__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_47__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_47__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_47__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_47__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_47__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_48
#define	US_ALU_ALPHA_INST_48__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_48__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_48__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_48__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_48__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_48__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_48__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_48__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_48__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_48__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_49
#define	US_ALU_ALPHA_INST_49__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_49__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_49__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_49__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_49__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_49__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_49__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_49__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_49__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_49__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_50
#define	US_ALU_ALPHA_INST_50__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_50__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_50__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_50__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_50__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_50__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_50__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_50__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_50__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_50__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_51
#define	US_ALU_ALPHA_INST_51__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_51__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_51__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_51__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_51__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_51__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_51__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_51__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_51__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_51__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_52
#define	US_ALU_ALPHA_INST_52__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_52__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_52__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_52__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_52__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_52__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_52__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_52__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_52__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_52__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_53
#define	US_ALU_ALPHA_INST_53__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_53__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_53__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_53__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_53__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_53__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_53__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_53__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_53__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_53__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_54
#define	US_ALU_ALPHA_INST_54__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_54__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_54__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_54__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_54__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_54__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_54__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_54__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_54__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_54__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_55
#define	US_ALU_ALPHA_INST_55__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_55__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_55__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_55__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_55__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_55__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_55__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_55__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_55__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_55__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_56
#define	US_ALU_ALPHA_INST_56__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_56__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_56__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_56__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_56__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_56__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_56__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_56__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_56__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_56__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_57
#define	US_ALU_ALPHA_INST_57__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_57__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_57__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_57__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_57__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_57__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_57__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_57__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_57__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_57__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_58
#define	US_ALU_ALPHA_INST_58__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_58__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_58__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_58__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_58__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_58__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_58__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_58__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_58__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_58__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_59
#define	US_ALU_ALPHA_INST_59__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_59__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_59__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_59__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_59__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_59__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_59__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_59__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_59__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_59__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_60
#define	US_ALU_ALPHA_INST_60__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_60__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_60__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_60__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_60__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_60__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_60__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_60__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_60__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_60__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_61
#define	US_ALU_ALPHA_INST_61__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_61__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_61__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_61__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_61__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_61__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_61__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_61__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_61__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_61__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_62
#define	US_ALU_ALPHA_INST_62__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_62__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_62__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_62__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_62__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_62__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_62__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_62__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_62__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_62__CLAMP__SHIFT                 0x0000001e

// US_ALU_ALPHA_INST_63
#define	US_ALU_ALPHA_INST_63__SEL_A__SHIFT                 0x00000000
#define	US_ALU_ALPHA_INST_63__MOD_A__SHIFT                 0x00000005
#define	US_ALU_ALPHA_INST_63__SEL_B__SHIFT                 0x00000007
#define	US_ALU_ALPHA_INST_63__MOD_B__SHIFT                 0x0000000c
#define	US_ALU_ALPHA_INST_63__SEL_C__SHIFT                 0x0000000e
#define	US_ALU_ALPHA_INST_63__MOD_C__SHIFT                 0x00000013
#define	US_ALU_ALPHA_INST_63__SRCP_OP__SHIFT               0x00000015
#define	US_ALU_ALPHA_INST_63__OP__SHIFT                    0x00000017
#define	US_ALU_ALPHA_INST_63__OMOD__SHIFT                  0x0000001b
#define	US_ALU_ALPHA_INST_63__CLAMP__SHIFT                 0x0000001e

// US_ALU_CONST_R_0
#define	US_ALU_CONST_R_0__KR__SHIFT                        0x00000000

// US_ALU_CONST_R_1
#define	US_ALU_CONST_R_1__KR__SHIFT                        0x00000000

// US_ALU_CONST_R_2
#define	US_ALU_CONST_R_2__KR__SHIFT                        0x00000000

// US_ALU_CONST_R_3
#define	US_ALU_CONST_R_3__KR__SHIFT                        0x00000000

// US_ALU_CONST_R_4
#define	US_ALU_CONST_R_4__KR__SHIFT                        0x00000000

// US_ALU_CONST_R_5
#define	US_ALU_CONST_R_5__KR__SHIFT                        0x00000000

// US_ALU_CONST_R_6
#define	US_ALU_CONST_R_6__KR__SHIFT                        0x00000000

// US_ALU_CONST_R_7
#define	US_ALU_CONST_R_7__KR__SHIFT                        0x00000000

// US_ALU_CONST_R_8
#define	US_ALU_CONST_R_8__KR__SHIFT                        0x00000000

// US_ALU_CONST_R_9
#define	US_ALU_CONST_R_9__KR__SHIFT                        0x00000000

// US_ALU_CONST_R_10
#define	US_ALU_CONST_R_10__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_11
#define	US_ALU_CONST_R_11__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_12
#define	US_ALU_CONST_R_12__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_13
#define	US_ALU_CONST_R_13__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_14
#define	US_ALU_CONST_R_14__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_15
#define	US_ALU_CONST_R_15__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_16
#define	US_ALU_CONST_R_16__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_17
#define	US_ALU_CONST_R_17__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_18
#define	US_ALU_CONST_R_18__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_19
#define	US_ALU_CONST_R_19__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_20
#define	US_ALU_CONST_R_20__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_21
#define	US_ALU_CONST_R_21__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_22
#define	US_ALU_CONST_R_22__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_23
#define	US_ALU_CONST_R_23__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_24
#define	US_ALU_CONST_R_24__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_25
#define	US_ALU_CONST_R_25__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_26
#define	US_ALU_CONST_R_26__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_27
#define	US_ALU_CONST_R_27__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_28
#define	US_ALU_CONST_R_28__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_29
#define	US_ALU_CONST_R_29__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_30
#define	US_ALU_CONST_R_30__KR__SHIFT                       0x00000000

// US_ALU_CONST_R_31
#define	US_ALU_CONST_R_31__KR__SHIFT                       0x00000000

// US_ALU_CONST_G_0
#define	US_ALU_CONST_G_0__KG__SHIFT                        0x00000000

// US_ALU_CONST_G_1
#define	US_ALU_CONST_G_1__KG__SHIFT                        0x00000000

// US_ALU_CONST_G_2
#define	US_ALU_CONST_G_2__KG__SHIFT                        0x00000000

// US_ALU_CONST_G_3
#define	US_ALU_CONST_G_3__KG__SHIFT                        0x00000000

// US_ALU_CONST_G_4
#define	US_ALU_CONST_G_4__KG__SHIFT                        0x00000000

// US_ALU_CONST_G_5
#define	US_ALU_CONST_G_5__KG__SHIFT                        0x00000000

// US_ALU_CONST_G_6
#define	US_ALU_CONST_G_6__KG__SHIFT                        0x00000000

// US_ALU_CONST_G_7
#define	US_ALU_CONST_G_7__KG__SHIFT                        0x00000000

// US_ALU_CONST_G_8
#define	US_ALU_CONST_G_8__KG__SHIFT                        0x00000000

// US_ALU_CONST_G_9
#define	US_ALU_CONST_G_9__KG__SHIFT                        0x00000000

// US_ALU_CONST_G_10
#define	US_ALU_CONST_G_10__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_11
#define	US_ALU_CONST_G_11__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_12
#define	US_ALU_CONST_G_12__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_13
#define	US_ALU_CONST_G_13__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_14
#define	US_ALU_CONST_G_14__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_15
#define	US_ALU_CONST_G_15__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_16
#define	US_ALU_CONST_G_16__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_17
#define	US_ALU_CONST_G_17__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_18
#define	US_ALU_CONST_G_18__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_19
#define	US_ALU_CONST_G_19__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_20
#define	US_ALU_CONST_G_20__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_21
#define	US_ALU_CONST_G_21__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_22
#define	US_ALU_CONST_G_22__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_23
#define	US_ALU_CONST_G_23__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_24
#define	US_ALU_CONST_G_24__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_25
#define	US_ALU_CONST_G_25__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_26
#define	US_ALU_CONST_G_26__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_27
#define	US_ALU_CONST_G_27__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_28
#define	US_ALU_CONST_G_28__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_29
#define	US_ALU_CONST_G_29__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_30
#define	US_ALU_CONST_G_30__KG__SHIFT                       0x00000000

// US_ALU_CONST_G_31
#define	US_ALU_CONST_G_31__KG__SHIFT                       0x00000000

// US_ALU_CONST_B_0
#define	US_ALU_CONST_B_0__KB__SHIFT                        0x00000000

// US_ALU_CONST_B_1
#define	US_ALU_CONST_B_1__KB__SHIFT                        0x00000000

// US_ALU_CONST_B_2
#define	US_ALU_CONST_B_2__KB__SHIFT                        0x00000000

// US_ALU_CONST_B_3
#define	US_ALU_CONST_B_3__KB__SHIFT                        0x00000000

// US_ALU_CONST_B_4
#define	US_ALU_CONST_B_4__KB__SHIFT                        0x00000000

// US_ALU_CONST_B_5
#define	US_ALU_CONST_B_5__KB__SHIFT                        0x00000000

// US_ALU_CONST_B_6
#define	US_ALU_CONST_B_6__KB__SHIFT                        0x00000000

// US_ALU_CONST_B_7
#define	US_ALU_CONST_B_7__KB__SHIFT                        0x00000000

// US_ALU_CONST_B_8
#define	US_ALU_CONST_B_8__KB__SHIFT                        0x00000000

// US_ALU_CONST_B_9
#define	US_ALU_CONST_B_9__KB__SHIFT                        0x00000000

// US_ALU_CONST_B_10
#define	US_ALU_CONST_B_10__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_11
#define	US_ALU_CONST_B_11__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_12
#define	US_ALU_CONST_B_12__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_13
#define	US_ALU_CONST_B_13__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_14
#define	US_ALU_CONST_B_14__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_15
#define	US_ALU_CONST_B_15__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_16
#define	US_ALU_CONST_B_16__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_17
#define	US_ALU_CONST_B_17__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_18
#define	US_ALU_CONST_B_18__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_19
#define	US_ALU_CONST_B_19__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_20
#define	US_ALU_CONST_B_20__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_21
#define	US_ALU_CONST_B_21__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_22
#define	US_ALU_CONST_B_22__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_23
#define	US_ALU_CONST_B_23__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_24
#define	US_ALU_CONST_B_24__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_25
#define	US_ALU_CONST_B_25__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_26
#define	US_ALU_CONST_B_26__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_27
#define	US_ALU_CONST_B_27__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_28
#define	US_ALU_CONST_B_28__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_29
#define	US_ALU_CONST_B_29__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_30
#define	US_ALU_CONST_B_30__KB__SHIFT                       0x00000000

// US_ALU_CONST_B_31
#define	US_ALU_CONST_B_31__KB__SHIFT                       0x00000000

// US_ALU_CONST_A_0
#define	US_ALU_CONST_A_0__KA__SHIFT                        0x00000000

// US_ALU_CONST_A_1
#define	US_ALU_CONST_A_1__KA__SHIFT                        0x00000000

// US_ALU_CONST_A_2
#define	US_ALU_CONST_A_2__KA__SHIFT                        0x00000000

// US_ALU_CONST_A_3
#define	US_ALU_CONST_A_3__KA__SHIFT                        0x00000000

// US_ALU_CONST_A_4
#define	US_ALU_CONST_A_4__KA__SHIFT                        0x00000000

// US_ALU_CONST_A_5
#define	US_ALU_CONST_A_5__KA__SHIFT                        0x00000000

// US_ALU_CONST_A_6
#define	US_ALU_CONST_A_6__KA__SHIFT                        0x00000000

// US_ALU_CONST_A_7
#define	US_ALU_CONST_A_7__KA__SHIFT                        0x00000000

// US_ALU_CONST_A_8
#define	US_ALU_CONST_A_8__KA__SHIFT                        0x00000000

// US_ALU_CONST_A_9
#define	US_ALU_CONST_A_9__KA__SHIFT                        0x00000000

// US_ALU_CONST_A_10
#define	US_ALU_CONST_A_10__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_11
#define	US_ALU_CONST_A_11__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_12
#define	US_ALU_CONST_A_12__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_13
#define	US_ALU_CONST_A_13__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_14
#define	US_ALU_CONST_A_14__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_15
#define	US_ALU_CONST_A_15__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_16
#define	US_ALU_CONST_A_16__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_17
#define	US_ALU_CONST_A_17__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_18
#define	US_ALU_CONST_A_18__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_19
#define	US_ALU_CONST_A_19__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_20
#define	US_ALU_CONST_A_20__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_21
#define	US_ALU_CONST_A_21__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_22
#define	US_ALU_CONST_A_22__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_23
#define	US_ALU_CONST_A_23__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_24
#define	US_ALU_CONST_A_24__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_25
#define	US_ALU_CONST_A_25__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_26
#define	US_ALU_CONST_A_26__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_27
#define	US_ALU_CONST_A_27__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_28
#define	US_ALU_CONST_A_28__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_29
#define	US_ALU_CONST_A_29__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_30
#define	US_ALU_CONST_A_30__KA__SHIFT                       0x00000000

// US_ALU_CONST_A_31
#define	US_ALU_CONST_A_31__KA__SHIFT                       0x00000000

// FG_FOG_BLEND
#define	FG_FOG_BLEND__ENABLE__SHIFT                        0x00000000
#define	FG_FOG_BLEND__FN__SHIFT                            0x00000001

// FG_FOG_FACTOR
#define	FG_FOG_FACTOR__FACTOR__SHIFT                       0x00000000

// FG_FOG_COLOR_R
#define	FG_FOG_COLOR_R__RED__SHIFT                         0x00000000

// FG_FOG_COLOR_G
#define	FG_FOG_COLOR_G__GREEN__SHIFT                       0x00000000

// FG_FOG_COLOR_B
#define	FG_FOG_COLOR_B__BLUE__SHIFT                        0x00000000

// FG_ALPHA_FUNC
#define	FG_ALPHA_FUNC__AF_VAL__SHIFT                       0x00000000
#define	FG_ALPHA_FUNC__AF_FUNC__SHIFT                      0x00000008
#define	FG_ALPHA_FUNC__AF_EN__SHIFT                        0x0000000b
#define	FG_ALPHA_FUNC__AM_EN__SHIFT                        0x00000010
#define	FG_ALPHA_FUNC__AM_CFG__SHIFT                       0x00000011
#define	FG_ALPHA_FUNC__DITH_EN__SHIFT                      0x00000014

// FG_DEPTH_SRC
#define	FG_DEPTH_SRC__DEPTH_SRC__SHIFT                     0x00000000

// FG_PERF
#define	FG_PERF__PERF0__SHIFT                              0x00000000
#define	FG_PERF__PERF1__SHIFT                              0x00000005
#define	FG_PERF__PERF2__SHIFT                              0x0000000a
#define	FG_PERF__PERF3__SHIFT                              0x0000000f

// RB3D_CCTL
#define	RB3D_CCTL__NUM_MULTIWRITES__SHIFT                  0x00000005
#define	RB3D_CCTL__CLRCMP_FLIPE_ENABLE__SHIFT              0x00000007
#define	RB3D_CCTL__AA_COMPRESSION_ENABLE__SHIFT            0x00000009
#define	RB3D_CCTL__CMASK_ENABLE__SHIFT                     0x0000000a

// RB3D_BLENDCNTL
#define	RB3D_BLENDCNTL_R3__ALPHA_BLEND_ENABLE__SHIFT       0x00000000
#define	RB3D_BLENDCNTL_R3__SEPARATE_ALPHA_ENABLE__SHIFT    0x00000001
#define	RB3D_BLENDCNTL_R3__READ_ENABLE__SHIFT              0x00000002
#define	RB3D_BLENDCNTL_R3__DISCARD_SRC_PIXELS__SHIFT       0x00000003
#define	RB3D_BLENDCNTL_R3__COMB_FCN__SHIFT                 0x0000000c
#define	RB3D_BLENDCNTL_R3__SRCBLEND__SHIFT                 0x00000010
#define	RB3D_BLENDCNTL_R3__DESTBLEND__SHIFT                0x00000018
#define	RB3D_BLENDCNTL__SRC_ALPHA_0_NO_READ__SHIFT         0x0000001e
#define	RB3D_BLENDCNTL__SRC_ALPHA_1_NO_READ__SHIFT         0x0000001f

// RB3D_ABLENDCNTL
#define	RB3D_ABLENDCNTL_R3__COMB_FCN__SHIFT                0x0000000c
#define	RB3D_ABLENDCNTL_R3__SRCBLEND__SHIFT                0x00000010
#define	RB3D_ABLENDCNTL_R3__DESTBLEND__SHIFT               0x00000018

// RB3D_COLOR_CHANNEL_MASK
#define	RB3D_COLOR_CHANNEL_MASK__BLUE_MASK__SHIFT          0x00000000
#define	RB3D_COLOR_CHANNEL_MASK__GREEN_MASK__SHIFT         0x00000001
#define	RB3D_COLOR_CHANNEL_MASK__RED_MASK__SHIFT           0x00000002
#define	RB3D_COLOR_CHANNEL_MASK__ALPHA_MASK__SHIFT         0x00000003

// RB3D_CONSTANT_COLOR
#define	RB3D_CONSTANT_COLOR__BLUE__SHIFT                   0x00000000
#define	RB3D_CONSTANT_COLOR__GREEN__SHIFT                  0x00000008
#define	RB3D_CONSTANT_COLOR__RED__SHIFT                    0x00000010
#define	RB3D_CONSTANT_COLOR__ALPHA__SHIFT                  0x00000018

// RB3D_COLOR_CLEAR_VALUE
#define	RB3D_COLOR_CLEAR_VALUE__BLUE__SHIFT                0x00000000
#define	RB3D_COLOR_CLEAR_VALUE__GREEN__SHIFT               0x00000008
#define	RB3D_COLOR_CLEAR_VALUE__RED__SHIFT                 0x00000010
#define	RB3D_COLOR_CLEAR_VALUE__ALPHA__SHIFT               0x00000018

// RB3D_ROPCNTL
#define	RB3D_ROPCNTL_R3__ROP_ENABLE__SHIFT                 0x00000002
#define	RB3D_ROPCNTL_R3__ROP__SHIFT                        0x00000008

// RB3D_CLRCMP_FLIPE
#define	RB3D_CLRCMP_FLIPE_R3__CLRCMP_FLIPE__SHIFT          0x00000000

// RB3D_CLRCMP_CLR
#define	RB3D_CLRCMP_CLR_R3__CLRCMP_CLR__SHIFT              0x00000000

// RB3D_CLRCMP_MSK
#define	RB3D_CLRCMP_MSK_R3__CLRCMP_MSK__SHIFT              0x00000000

// RB3D_COLOROFFSET0
#define	RB3D_COLOROFFSET0__COLOROFFSET__SHIFT              0x00000005

// RB3D_COLOROFFSET1
#define	RB3D_COLOROFFSET1__COLOROFFSET__SHIFT              0x00000005

// RB3D_COLOROFFSET2
#define	RB3D_COLOROFFSET2__COLOROFFSET__SHIFT              0x00000005

// RB3D_COLOROFFSET3
#define	RB3D_COLOROFFSET3__COLOROFFSET__SHIFT              0x00000005

// RB3D_COLORPITCH0
#define	RB3D_COLORPITCH0__COLORPITCH__SHIFT                0x00000001
#define	RB3D_COLORPITCH0__COLORTILE__SHIFT                 0x00000010
#define	RB3D_COLORPITCH0__COLORMICROTILE__SHIFT            0x00000011
#define	RB3D_COLORPITCH0__COLORENDIAN__SHIFT               0x00000013
#define	RB3D_COLORPITCH0__COLORFORMAT__SHIFT               0x00000015

// RB3D_COLORPITCH1
#define	RB3D_COLORPITCH1__COLORPITCH__SHIFT                0x00000001

// RB3D_COLORPITCH2
#define	RB3D_COLORPITCH2__COLORPITCH__SHIFT                0x00000001

// RB3D_COLORPITCH3
#define	RB3D_COLORPITCH3__COLORPITCH__SHIFT                0x00000001

// RB3D_DEBUG_CTL
#define	RB3D_DEBUG_CTL__DISCARD_ZERO_MASKED_WRITES__SHIFT  0x00000008
#define	RB3D_DEBUG_CTL__AUTOFLUSH_ENABLE__SHIFT            0x00000009
#define	RB3D_DEBUG_CTL__FORCE_RMW__SHIFT                   0x00000010
#define	RB3D_DEBUG_CTL__FORCE_NO_REORDER__SHIFT            0x00000014
#define	RB3D_DEBUG_CTL__FORCE_NO_CYCLE_SWAP__SHIFT         0x00000015
#define	RB3D_DEBUG_CTL__FORCE_NO_OP_PREFETCH__SHIFT        0x00000016
#define	RB3D_DEBUG_CTL__FORCE_NO_CC_PREFETCH__SHIFT        0x00000017
#define	RB3D_DEBUG_CTL__FORCE_DISABLE_NO_READ__SHIFT       0x00000018

// RB3D_DSTCACHE_CTLSTAT
#define	RB3D_DSTCACHE_CTLSTAT_R3__DC_FLUSH__SHIFT          0x00000000
#define	RB3D_DSTCACHE_CTLSTAT_R3__DC_FREE__SHIFT           0x00000002
#define	RB3D_DSTCACHE_CTLSTAT_R3__DC_FINISH__SHIFT         0x00000004

// RB3D_DITHER_CTL
#define	RB3D_DITHER_CTL__DITHER_MODE__SHIFT                0x00000000
#define	RB3D_DITHER_CTL__ALPHA_DITHER_MODE__SHIFT          0x00000002

// RB3D_CMASK_OFFSET0
#define	RB3D_CMASK_OFFSET0__CMASK_OFFSET__SHIFT            0x00000004

// RB3D_CMASK_OFFSET1
#define	RB3D_CMASK_OFFSET1__CMASK_OFFSET__SHIFT            0x00000004

// RB3D_CMASK_OFFSET2
#define	RB3D_CMASK_OFFSET2__CMASK_OFFSET__SHIFT            0x00000004

// RB3D_CMASK_OFFSET3
#define	RB3D_CMASK_OFFSET3__CMASK_OFFSET__SHIFT            0x00000004

// RB3D_CMASK_PITCH0
#define	RB3D_CMASK_PITCH0__CMASK_PITCH__SHIFT              0x00000004

// RB3D_CMASK_PITCH1
#define	RB3D_CMASK_PITCH1__CMASK_PITCH__SHIFT              0x00000004

// RB3D_CMASK_PITCH2
#define	RB3D_CMASK_PITCH2__CMASK_PITCH__SHIFT              0x00000004

// RB3D_CMASK_PITCH3
#define	RB3D_CMASK_PITCH3__CMASK_PITCH__SHIFT              0x00000004

// RB3D_CMASK_WRINDEX
#define	RB3D_CMASK_WRINDEX__CMASK_WRINDEX__SHIFT           0x00000004

// RB3D_CMASK_DWORD
#define	RB3D_CMASK_DWORD__CMASK_DWORD__SHIFT               0x00000000

// RB3D_CMASK_RDINDEX
#define	RB3D_CMASK_RDINDEX__CMASK_RDINDEX__SHIFT           0x00000004

// RB3D_AARESOLVE_OFFSET
#define	RB3D_AARESOLVE_OFFSET__AARESOLVE_OFFSET__SHIFT     0x00000005

// RB3D_AARESOLVE_PITCH
#define	RB3D_AARESOLVE_PITCH__AARESOLVE_PITCH__SHIFT       0x00000001

// RB3D_AARESOLVE_CTL
#define	RB3D_AARESOLVE_CTL__AARESOLVE_MODE__SHIFT          0x00000000
#define	RB3D_AARESOLVE_CTL__AARESOLVE_GAMMA__SHIFT         0x00000001

// RB3D_PERF_CNTL
#define	RB3D_PERF_CNTL__SEL_PERF0__SHIFT                   0x00000000
#define	RB3D_PERF_CNTL__CLR_PERF0__SHIFT                   0x00000006
#define	RB3D_PERF_CNTL__EN_PERF0__SHIFT                    0x00000007
#define	RB3D_PERF_CNTL__SEL_PERF1__SHIFT                   0x00000008
#define	RB3D_PERF_CNTL__CLR_PERF1__SHIFT                   0x0000000e
#define	RB3D_PERF_CNTL__EN_PERF1__SHIFT                    0x0000000f
#define	RB3D_PERF_CNTL__SEL_PERF2__SHIFT                   0x00000010
#define	RB3D_PERF_CNTL__CLR_PERF2__SHIFT                   0x00000016
#define	RB3D_PERF_CNTL__EN_PERF2__SHIFT                    0x00000017
#define	RB3D_PERF_CNTL__SEL_PERF3__SHIFT                   0x00000018
#define	RB3D_PERF_CNTL__CLR_PERF3__SHIFT                   0x0000001e
#define	RB3D_PERF_CNTL__EN_PERF3__SHIFT                    0x0000001f

// RB3D_PERF_COUNT0
#define	RB3D_PERF_COUNT0__PERF_COUNT__SHIFT                0x00000000

// RB3D_PERF_COUNT1
#define	RB3D_PERF_COUNT1__PERF_COUNT__SHIFT                0x00000000

// RB3D_PERF_COUNT2
#define	RB3D_PERF_COUNT2__PERF_COUNT__SHIFT                0x00000000

// RB3D_PERF_COUNT3
#define	RB3D_PERF_COUNT3__PERF_COUNT__SHIFT                0x00000000

// RB3D_DISCARD_SRC_PIXEL_LTE_THRESHOLD
#define	RB3D_DISCARD_SRC_PIXEL_LTE_THRESHOLD__BLUE__SHIFT  0x00000000
#define	RB3D_DISCARD_SRC_PIXEL_LTE_THRESHOLD__GREEN__SHIFT 0x00000008
#define	RB3D_DISCARD_SRC_PIXEL_LTE_THRESHOLD__RED__SHIFT   0x00000010
#define	RB3D_DISCARD_SRC_PIXEL_LTE_THRESHOLD__ALPHA__SHIFT 0x00000018

// RB3D_DISCARD_SRC_PIXEL_GTE_THRESHOLD
#define	RB3D_DISCARD_SRC_PIXEL_GTE_THRESHOLD__BLUE__SHIFT  0x00000000
#define	RB3D_DISCARD_SRC_PIXEL_GTE_THRESHOLD__GREEN__SHIFT 0x00000008
#define	RB3D_DISCARD_SRC_PIXEL_GTE_THRESHOLD__RED__SHIFT   0x00000010
#define	RB3D_DISCARD_SRC_PIXEL_GTE_THRESHOLD__ALPHA__SHIFT 0x00000018

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

// RB2D_BRUSHSTAGE_0
#define	RB2D_BRUSHSTAGE_0__BRUSHDATA__SHIFT                0x00000000
#define	RB2D_BRUSH_MONO_0_READ__BRUSHDATA__SHIFT           0x00000000

// RB2D_BRUSHSTAGE_1
#define	RB2D_BRUSHSTAGE_1__BRUSHDATA__SHIFT                0x00000000
#define	RB2D_BRUSH_MONO_1_READ__BRUSHDATA__SHIFT           0x00000000

// RB2D_BRUSHSTAGE_2
#define	RB2D_BRUSHSTAGE_2__BRUSHDATA__SHIFT                0x00000000
#define	RB2D_BRUSH_FRGD_CLR_READ__BRUSHDATA__SHIFT         0x00000000

// RB2D_BRUSHSTAGE_3
#define	RB2D_BRUSHSTAGE_3__BRUSHDATA__SHIFT                0x00000000
#define	RB2D_BRUSH_BKGD_CLR_READ__BRUSHDATA__SHIFT         0x00000000

// RB2D_DST_ENDIAN
#define	RB2D_DST_ENDIAN__DST_ENDIAN__SHIFT                 0x00000000

// RB2D_DSTCACHE_MODE
#define	RB2D_DSTCACHE_MODE__DC_AUTOFLUSH_ENABLE__SHIFT     0x00000008
#define	RB2D_DSTCACHE_MODE__DC_FORCE_RMW__SHIFT            0x00000010
#define	RB2D_DSTCACHE_MODE__DC_DISABLE_IGNORE_PE__SHIFT    0x00000011

// RB2D_DSTCACHE_CTLSTAT
#define	RB2D_DSTCACHE_CTLSTAT__DC_FLUSH__SHIFT             0x00000000
#define	RB2D_DSTCACHE_CTLSTAT__DC_FREE__SHIFT              0x00000002
#define	RB2D_DSTCACHE_CTLSTAT__DC_BUSY__SHIFT              0x0000001f

// RB2D_PERF_CNTL
#define	RB2D_PERF_CNTL__SEL_PERF0__SHIFT                   0x00000000
#define	RB2D_PERF_CNTL__CLR_PERF0__SHIFT                   0x00000006
#define	RB2D_PERF_CNTL__EN_PERF0__SHIFT                    0x00000007
#define	RB2D_PERF_CNTL__SEL_PERF1__SHIFT                   0x00000008
#define	RB2D_PERF_CNTL__CLR_PERF1__SHIFT                   0x0000000e
#define	RB2D_PERF_CNTL__EN_PERF1__SHIFT                    0x0000000f
#define	RB2D_PERF_CNTL__SEL_PERF2__SHIFT                   0x00000010
#define	RB2D_PERF_CNTL__CLR_PERF2__SHIFT                   0x00000016
#define	RB2D_PERF_CNTL__EN_PERF2__SHIFT                    0x00000017
#define	RB2D_PERF_CNTL__SEL_PERF3__SHIFT                   0x00000018
#define	RB2D_PERF_CNTL__CLR_PERF3__SHIFT                   0x0000001e
#define	RB2D_PERF_CNTL__EN_PERF3__SHIFT                    0x0000001f

// RB2D_PERF_COUNT0
#define	RB2D_PERF_COUNT0__PERF_CNT__SHIFT                  0x00000000

// RB2D_PERF_COUNT1
#define	RB2D_PERF_COUNT1__PERF_CNT__SHIFT                  0x00000000

// RB2D_PERF_COUNT2
#define	RB2D_PERF_COUNT2__PERF_CNT__SHIFT                  0x00000000

// RB2D_PERF_COUNT3
#define	RB2D_PERF_COUNT3__PERF_CNT__SHIFT                  0x00000000

// ZB_CNTL
#define	ZB_CNTL__STENCIL_ENABLE__SHIFT                     0x00000000
#define	RB3D_ZCNTL__STENCIL_ENABLE__SHIFT                  0x00000000
#define	ZB_CNTL__Z_ENABLE__SHIFT                           0x00000001
#define	RB3D_ZCNTL__Z_ENABLE__SHIFT                        0x00000001
#define	ZB_CNTL__ZWRITEENABLE__SHIFT                       0x00000002
#define	RB3D_ZCNTL__ZWRITEENABLE__SHIFT                    0x00000002
#define	ZB_CNTL__ZSIGNED_COMPARE__SHIFT                    0x00000003
#define	RB3D_ZCNTL__ZSIGNED_COMPARE__SHIFT                 0x00000003
#define	ZB_CNTL__STENCIL_FRONT_BACK__SHIFT                 0x00000004
#define	RB3D_ZCNTL__STENCIL_FRONT_BACK__SHIFT              0x00000004
#define	ZB_CNTL__ZSIGNED_MAGNITUDE__SHIFT                  0x00000005
#define	RB3D_ZCNTL__ZSIGNED_MAGNITUDE__SHIFT               0x00000005

// ZB_ZSTENCILCNTL
#define	ZB_ZSTENCILCNTL__ZFUNC__SHIFT                      0x00000000
#define	RB3D_ZSTENCILCNTL_R3__ZFUNC__SHIFT                 0x00000000
#define	ZB_ZSTENCILCNTL__STENCILFUNC__SHIFT                0x00000003
#define	RB3D_ZSTENCILCNTL_R3__STENCILFUNC__SHIFT           0x00000003
#define	ZB_ZSTENCILCNTL__STENCILFAIL__SHIFT                0x00000006
#define	RB3D_ZSTENCILCNTL_R3__STENCILFAIL__SHIFT           0x00000006
#define	ZB_ZSTENCILCNTL__STENCILZPASS__SHIFT               0x00000009
#define	RB3D_ZSTENCILCNTL_R3__STENCILZPASS__SHIFT          0x00000009
#define	ZB_ZSTENCILCNTL__STENCILZFAIL__SHIFT               0x0000000c
#define	RB3D_ZSTENCILCNTL_R3__STENCILZFAIL__SHIFT          0x0000000c
#define	ZB_ZSTENCILCNTL__STENCILFUNC_BF__SHIFT             0x0000000f
#define	RB3D_ZSTENCILCNTL_R3__STENCILFUNC_BF__SHIFT        0x0000000f
#define	ZB_ZSTENCILCNTL__STENCILFAIL_BF__SHIFT             0x00000012
#define	RB3D_ZSTENCILCNTL_R3__STENCILFAIL_BF__SHIFT        0x00000012
#define	ZB_ZSTENCILCNTL__STENCILZPASS_BF__SHIFT            0x00000015
#define	RB3D_ZSTENCILCNTL_R3__STENCILZPASS_BF__SHIFT       0x00000015
#define	ZB_ZSTENCILCNTL__STENCILZFAIL_BF__SHIFT            0x00000018
#define	RB3D_ZSTENCILCNTL_R3__STENCILZFAIL_BF__SHIFT       0x00000018

// ZB_STENCILREFMASK
#define	ZB_STENCILREFMASK__STENCILREF__SHIFT               0x00000000
#define	RB3D_STENCILREFMASK_R3__STENCILREF__SHIFT          0x00000000
#define	ZB_STENCILREFMASK__STENCILMASK__SHIFT              0x00000008
#define	RB3D_STENCILREFMASK_R3__STENCILMASK__SHIFT         0x00000008
#define	ZB_STENCILREFMASK__STENCILWRITEMASK__SHIFT         0x00000010
#define	RB3D_STENCILREFMASK_R3__STENCILWRITEMASK__SHIFT    0x00000010

// ZB_FORMAT
#define	ZB_FORMAT__DEPTHFORMAT__SHIFT                      0x00000000
#define	RB3D_FORMAT__DEPTHFORMAT__SHIFT                    0x00000000
#define	ZB_FORMAT__INVERT__SHIFT                           0x00000004
#define	RB3D_FORMAT__INVERT__SHIFT                         0x00000004
#define	ZB_FORMAT__PEQ8__SHIFT                             0x00000005
#define	RB3D_FORMAT__PEQ8__SHIFT                           0x00000005

// ZB_ZTOP
#define	ZB_ZTOP__ZTOP__SHIFT                               0x00000000
#define	RB3D_ZTOP__ZTOP__SHIFT                             0x00000000

// ZB_ZCACHE_CTLSTAT
#define	ZB_ZCACHE_CTLSTAT__ZC_FLUSH__SHIFT                 0x00000000
#define	RB3D_ZCACHE_CTLSTAT_R3__ZC_FLUSH__SHIFT            0x00000000
#define	ZB_ZCACHE_CTLSTAT__ZC_FREE__SHIFT                  0x00000001
#define	RB3D_ZCACHE_CTLSTAT_R3__ZC_FREE__SHIFT             0x00000001
#define	ZB_ZCACHE_CTLSTAT__ZC_BUSY__SHIFT                  0x0000001f
#define	RB3D_ZCACHE_CTLSTAT_R3__ZC_BUSY__SHIFT             0x0000001f

// ZB_BW_CNTL
#define	ZB_BW_CNTL__HIZ_ENABLE__SHIFT                      0x00000000
#define	RB3D_BW_CNTL__HIZ_ENABLE__SHIFT                    0x00000000
#define	ZB_BW_CNTL__HIZ_MIN__SHIFT                         0x00000001
#define	RB3D_BW_CNTL__HIZ_MIN__SHIFT                       0x00000001
#define	ZB_BW_CNTL__FAST_FILL__SHIFT                       0x00000002
#define	RB3D_BW_CNTL__FAST_FILL__SHIFT                     0x00000002
#define	ZB_BW_CNTL__RD_COMP_ENABLE__SHIFT                  0x00000003
#define	RB3D_BW_CNTL__RD_COMP_ENABLE__SHIFT                0x00000003
#define	ZB_BW_CNTL__WR_COMP_ENABLE__SHIFT                  0x00000004
#define	RB3D_BW_CNTL__WR_COMP_ENABLE__SHIFT                0x00000004
#define	ZB_BW_CNTL__ZB_CB_CLEAR__SHIFT                     0x00000005
#define	RB3D_BW_CNTL__ZB_CB_CLEAR__SHIFT                   0x00000005
#define	ZB_BW_CNTL__FORCE_COMPRESSED_STENCIL_VALUE__SHIFT  0x00000006
#define	RB3D_BW_CNTL__FORCE_COMPRESSED_STENCIL_VALUE__SHIFT 0x00000006
#define	ZB_BW_CNTL__ZEQUAL_OPTIMIZE_DISABLE__SHIFT         0x00000007
#define	RB3D_BW_CNTL__ZEQUAL_OPTIMIZE_DISABLE__SHIFT       0x00000007
#define	ZB_BW_CNTL__SEQUAL_OPTIMIZE_DISABLE__SHIFT         0x00000008
#define	RB3D_BW_CNTL__SEQUAL_OPTIMIZE_DISABLE__SHIFT       0x00000008

// ZB_DEPTHOFFSET
#define	ZB_DEPTHOFFSET__DEPTHOFFSET__SHIFT                 0x00000005
#define	RB3D_DEPTHOFFSET_R3__DEPTHOFFSET__SHIFT            0x00000005

// ZB_DEPTHPITCH
#define	ZB_DEPTHPITCH__DEPTHPITCH__SHIFT                   0x00000002
#define	RB3D_DEPTHPITCH_R3__DEPTHPITCH__SHIFT              0x00000002
#define	ZB_DEPTHPITCH__DEPTHMACROTILE__SHIFT               0x00000010
#define	RB3D_DEPTHPITCH_R3__DEPTHMACROTILE__SHIFT          0x00000010
#define	ZB_DEPTHPITCH__DEPTHMICROTILE__SHIFT               0x00000011
#define	RB3D_DEPTHPITCH_R3__DEPTHMICROTILE__SHIFT          0x00000011
#define	ZB_DEPTHPITCH__DEPTHENDIAN__SHIFT                  0x00000013
#define	RB3D_DEPTHPITCH_R3__DEPTHENDIAN__SHIFT             0x00000013

// ZB_DEPTHCLEARVALUE
#define	ZB_DEPTHCLEARVALUE__DEPTHCLEARVALUE__SHIFT         0x00000000
#define	RB3D_DEPTHCLEARVALUE_R3__DEPTHCLEARVALUE__SHIFT    0x00000000

// ZB_ZMASK_OFFSET
#define	ZB_ZMASK_OFFSET__ZMASK_OFFSET__SHIFT               0x00000004
#define	RB3D_ZMASK_OFFSET__ZMASK_OFFSET__SHIFT             0x00000004

// ZB_ZMASK_PITCH
#define	ZB_ZMASK_PITCH__ZMASK_PITCH__SHIFT                 0x00000004
#define	RB3D_ZMASK_PITCH__ZMASK_PITCH__SHIFT               0x00000004

// ZB_ZMASK_WRINDEX
#define	ZB_ZMASK_WRINDEX__ZMASK_WRINDEX__SHIFT             0x00000004
#define	RB3D_ZMASK_WRINDEX_R3__ZMASK_WRINDEX__SHIFT        0x00000004

// ZB_ZMASK_DWORD
#define	ZB_ZMASK_DWORD__ZMASK_DWORD__SHIFT                 0x00000000
#define	RB3D_ZMASK_DWORD_R3__ZMASK_DWORD__SHIFT            0x00000000

// ZB_ZMASK_RDINDEX
#define	ZB_ZMASK_RDINDEX__ZMASK_RDINDEX__SHIFT             0x00000004
#define	RB3D_ZMASK_RDINDEX_R3__ZMASK_RDINDEX__SHIFT        0x00000004

// ZB_HIZ_OFFSET
#define	ZB_HIZ_OFFSET__HIZ_OFFSET__SHIFT                   0x00000002
#define	RE_HIZ_OFFSET__HIZ_OFFSET__SHIFT                   0x00000002

// ZB_HIZ_WRINDEX
#define	ZB_HIZ_WRINDEX__HIZ_WRINDEX__SHIFT                 0x00000002
#define	RE_HIZ_WRINDEX_R3__HIZ_WRINDEX__SHIFT              0x00000002

// ZB_HIZ_DWORD
#define	ZB_HIZ_DWORD__HIZ_DWORD__SHIFT                     0x00000000
#define	RE_HIZ_DWORD_R3__HIZ_DWORD__SHIFT                  0x00000000

// ZB_HIZ_RDINDEX
#define	ZB_HIZ_RDINDEX__HIZ_RDINDEX__SHIFT                 0x00000002
#define	RE_HIZ_RDINDEX_R3__HIZ_RDINDEX__SHIFT              0x00000002

// ZB_HIZ_PITCH
#define	ZB_HIZ_PITCH__HIZ_PITCH__SHIFT                     0x00000004
#define	RB3D_HIZ_PITCH__HIZ_PITCH__SHIFT                   0x00000004

// ZB_ZPASS_DATA
#define	ZB_ZPASS_DATA__ZPASS_DATA__SHIFT                   0x00000000
#define	RB3D_ZPASS_DATA_R3__ZPASS_DATA__SHIFT              0x00000000

// ZB_ZPASS_ADDR
#define	ZB_ZPASS_ADDR__ZPASS_ADDR__SHIFT                   0x00000002
#define	RB3D_ZPASS_ADDR_R3__ZPASS_ADDR__SHIFT              0x00000002

// ZB_DEPTHXY_OFFSET
#define	ZB_DEPTHXY_OFFSET__DEPTHX_OFFSET__SHIFT            0x00000001
#define	RB3D_DEPTHXY_OFFSET_R3__DEPTHX_OFFSET__SHIFT       0x00000001
#define	ZB_DEPTHXY_OFFSET__DEPTHY_OFFSET__SHIFT            0x00000011
#define	RB3D_DEPTHXY_OFFSET_R3__DEPTHY_OFFSET__SHIFT       0x00000011

// ZB_PERF_CNTL
#define	ZB_PERF_CNTL__SEL_PERF0__SHIFT                     0x00000000
#define	RB3D_ZPERF_CNTL_R3__SEL_PERF0__SHIFT               0x00000000
#define	ZB_PERF_CNTL__CLR_PERF0__SHIFT                     0x00000004
#define	RB3D_ZPERF_CNTL_R3__CLR_PERF0__SHIFT               0x00000004
#define	ZB_PERF_CNTL__EN_PERF0__SHIFT                      0x00000005
#define	RB3D_ZPERF_CNTL_R3__EN_PERF0__SHIFT                0x00000005
#define	ZB_PERF_CNTL__SEL_PERF1__SHIFT                     0x00000008
#define	RB3D_ZPERF_CNTL_R3__SEL_PERF1__SHIFT               0x00000008
#define	ZB_PERF_CNTL__CLR_PERF1__SHIFT                     0x0000000c
#define	RB3D_ZPERF_CNTL_R3__CLR_PERF1__SHIFT               0x0000000c
#define	ZB_PERF_CNTL__EN_PERF1__SHIFT                      0x0000000d
#define	RB3D_ZPERF_CNTL_R3__EN_PERF1__SHIFT                0x0000000d
#define	ZB_PERF_CNTL__SEL_PERF2__SHIFT                     0x00000010
#define	RB3D_ZPERF_CNTL_R3__SEL_PERF2__SHIFT               0x00000010
#define	ZB_PERF_CNTL__CLR_PERF2__SHIFT                     0x00000014
#define	RB3D_ZPERF_CNTL_R3__CLR_PERF2__SHIFT               0x00000014
#define	ZB_PERF_CNTL__EN_PERF2__SHIFT                      0x00000015
#define	RB3D_ZPERF_CNTL_R3__EN_PERF2__SHIFT                0x00000015
#define	ZB_PERF_CNTL__SEL_PERF3__SHIFT                     0x00000018
#define	RB3D_ZPERF_CNTL_R3__SEL_PERF3__SHIFT               0x00000018
#define	ZB_PERF_CNTL__CLR_PERF3__SHIFT                     0x0000001c
#define	RB3D_ZPERF_CNTL_R3__CLR_PERF3__SHIFT               0x0000001c
#define	ZB_PERF_CNTL__EN_PERF3__SHIFT                      0x0000001d
#define	RB3D_ZPERF_CNTL_R3__EN_PERF3__SHIFT                0x0000001d

// ZB_PERF_COUNT0
#define	ZB_PERF_COUNT0__PERF_COUNT__SHIFT                  0x00000000
#define	RB3D_ZPERF_COUNT0__PERF_COUNT__SHIFT               0x00000000

// ZB_PERF_COUNT1
#define	ZB_PERF_COUNT1__PERF_COUNT__SHIFT                  0x00000000
#define	RB3D_ZPERF_COUNT1__PERF_COUNT__SHIFT               0x00000000

// ZB_PERF_COUNT2
#define	ZB_PERF_COUNT2__PERF_COUNT__SHIFT                  0x00000000
#define	RB3D_ZPERF_COUNT2__PERF_COUNT__SHIFT               0x00000000

// ZB_PERF_COUNT3
#define	ZB_PERF_COUNT3__PERF_COUNT__SHIFT                  0x00000000
#define	RB3D_ZPERF_COUNT3__PERF_COUNT__SHIFT               0x00000000

// ZB_CACHE_INDEX_CNTL
#define	ZB_CACHE_INDEX_CNTL__PROGRAMMABLE_INDEX_ENABLE__SHIFT 0x00000000
#define	ZB_CACHE_INDEX_CNTL__FUNC_A__SHIFT                 0x00000008
#define	ZB_CACHE_INDEX_CNTL__FUNC_B__SHIFT                 0x0000000c
#define	ZB_CACHE_INDEX_CNTL__FUNC_SELECT__SHIFT            0x00000010

// ZB_CACHE_INDEX_FUNC_A_ARG_X
#define	ZB_CACHE_INDEX_FUNC_A_ARG_X__SEL0__SHIFT           0x00000000
#define	ZB_CACHE_INDEX_FUNC_A_ARG_X__SEL1__SHIFT           0x00000004
#define	ZB_CACHE_INDEX_FUNC_A_ARG_X__SEL2__SHIFT           0x00000008
#define	ZB_CACHE_INDEX_FUNC_A_ARG_X__SEL3__SHIFT           0x0000000c
#define	ZB_CACHE_INDEX_FUNC_A_ARG_X__SEL4__SHIFT           0x00000010
#define	ZB_CACHE_INDEX_FUNC_A_ARG_X__SEL5__SHIFT           0x00000014
#define	ZB_CACHE_INDEX_FUNC_A_ARG_X__SEL6__SHIFT           0x00000018

// ZB_CACHE_INDEX_FUNC_A_ARG_Y
#define	ZB_CACHE_INDEX_FUNC_A_ARG_Y__SEL0__SHIFT           0x00000000
#define	ZB_CACHE_INDEX_FUNC_A_ARG_Y__SEL1__SHIFT           0x00000004
#define	ZB_CACHE_INDEX_FUNC_A_ARG_Y__SEL2__SHIFT           0x00000008
#define	ZB_CACHE_INDEX_FUNC_A_ARG_Y__SEL3__SHIFT           0x0000000c
#define	ZB_CACHE_INDEX_FUNC_A_ARG_Y__SEL4__SHIFT           0x00000010
#define	ZB_CACHE_INDEX_FUNC_A_ARG_Y__SEL5__SHIFT           0x00000014
#define	ZB_CACHE_INDEX_FUNC_A_ARG_Y__SEL6__SHIFT           0x00000018

// ZB_CACHE_INDEX_FUNC_B_ARG_X
#define	ZB_CACHE_INDEX_FUNC_B_ARG_X__SEL0__SHIFT           0x00000000
#define	ZB_CACHE_INDEX_FUNC_B_ARG_X__SEL1__SHIFT           0x00000004
#define	ZB_CACHE_INDEX_FUNC_B_ARG_X__SEL2__SHIFT           0x00000008
#define	ZB_CACHE_INDEX_FUNC_B_ARG_X__SEL3__SHIFT           0x0000000c
#define	ZB_CACHE_INDEX_FUNC_B_ARG_X__SEL4__SHIFT           0x00000010
#define	ZB_CACHE_INDEX_FUNC_B_ARG_X__SEL5__SHIFT           0x00000014
#define	ZB_CACHE_INDEX_FUNC_B_ARG_X__SEL6__SHIFT           0x00000018

// ZB_CACHE_INDEX_FUNC_B_ARG_Y
#define	ZB_CACHE_INDEX_FUNC_B_ARG_Y__SEL0__SHIFT           0x00000000
#define	ZB_CACHE_INDEX_FUNC_B_ARG_Y__SEL1__SHIFT           0x00000004
#define	ZB_CACHE_INDEX_FUNC_B_ARG_Y__SEL2__SHIFT           0x00000008
#define	ZB_CACHE_INDEX_FUNC_B_ARG_Y__SEL3__SHIFT           0x0000000c
#define	ZB_CACHE_INDEX_FUNC_B_ARG_Y__SEL4__SHIFT           0x00000010
#define	ZB_CACHE_INDEX_FUNC_B_ARG_Y__SEL5__SHIFT           0x00000014
#define	ZB_CACHE_INDEX_FUNC_B_ARG_Y__SEL6__SHIFT           0x00000018

// DST_OFFSET
#define	DST_OFFSET__DST_OFFSET__SHIFT                      0x00000000

// DST_PITCH
#define	DST_PITCH__DST_PITCH__SHIFT                        0x00000000

// DST_TILE
#define	DST_TILE__DST_TILE__SHIFT                          0x00000000
#define	DST_TILE__DST_TILE2__SHIFT                         0x00000002

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

// HOST_DATA_128
#define	HOST_DATA_128__HOST_DATA_128__SHIFT                0x00000000

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
#define	DP_CNTL__DST_TILE2__SHIFT                          0x00000005

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

// VAP_PORT_DATA0
#define	VAP_PORT_DATA0__DATAPORT0__SHIFT                   0x00000000

// VAP_PORT_DATA1
#define	VAP_PORT_DATA1__DATAPORT1__SHIFT                   0x00000000

// VAP_PORT_DATA2
#define	VAP_PORT_DATA2__DATAPORT2__SHIFT                   0x00000000

// VAP_PORT_DATA3
#define	VAP_PORT_DATA3__DATAPORT3__SHIFT                   0x00000000

// VAP_PORT_DATA4
#define	VAP_PORT_DATA4__DATAPORT4__SHIFT                   0x00000000

// VAP_PORT_DATA5
#define	VAP_PORT_DATA5__DATAPORT5__SHIFT                   0x00000000

// VAP_PORT_DATA6
#define	VAP_PORT_DATA6__DATAPORT6__SHIFT                   0x00000000

// VAP_PORT_DATA7
#define	VAP_PORT_DATA7__DATAPORT7__SHIFT                   0x00000000

// VAP_PORT_DATA8
#define	VAP_PORT_DATA8__DATAPORT8__SHIFT                   0x00000000

// VAP_PORT_DATA9
#define	VAP_PORT_DATA9__DATAPORT9__SHIFT                   0x00000000

// VAP_PORT_DATA10
#define	VAP_PORT_DATA10__DATAPORT10__SHIFT                 0x00000000

// VAP_PORT_DATA11
#define	VAP_PORT_DATA11__DATAPORT11__SHIFT                 0x00000000

// VAP_PORT_DATA12
#define	VAP_PORT_DATA12__DATAPORT12__SHIFT                 0x00000000

// VAP_PORT_DATA13
#define	VAP_PORT_DATA13__DATAPORT13__SHIFT                 0x00000000

// VAP_PORT_DATA14
#define	VAP_PORT_DATA14__DATAPORT14__SHIFT                 0x00000000

// VAP_PORT_DATA15
#define	VAP_PORT_DATA15__DATAPORT15__SHIFT                 0x00000000

// VAP_PORT_IDX0
#define	VAP_PORT_IDX0__IDXPORT0__SHIFT                     0x00000000

// VAP_PORT_IDX1
#define	VAP_PORT_IDX1__IDXPORT1__SHIFT                     0x00000000

// VAP_PORT_IDX2
#define	VAP_PORT_IDX2__IDXPORT2__SHIFT                     0x00000000

// VAP_PORT_IDX3
#define	VAP_PORT_IDX3__IDXPORT3__SHIFT                     0x00000000

// VAP_PORT_IDX4
#define	VAP_PORT_IDX4__IDXPORT4__SHIFT                     0x00000000

// VAP_PORT_IDX5
#define	VAP_PORT_IDX5__IDXPORT5__SHIFT                     0x00000000

// VAP_PORT_IDX6
#define	VAP_PORT_IDX6__IDXPORT6__SHIFT                     0x00000000

// VAP_PORT_IDX7
#define	VAP_PORT_IDX7__IDXPORT7__SHIFT                     0x00000000

// VAP_PORT_IDX8
#define	VAP_PORT_IDX8__IDXPORT8__SHIFT                     0x00000000

// VAP_PORT_IDX9
#define	VAP_PORT_IDX9__IDXPORT9__SHIFT                     0x00000000

// VAP_PORT_IDX10
#define	VAP_PORT_IDX10__IDXPORT10__SHIFT                   0x00000000

// VAP_PORT_IDX11
#define	VAP_PORT_IDX11__IDXPORT11__SHIFT                   0x00000000

// VAP_PORT_IDX12
#define	VAP_PORT_IDX12__IDXPORT12__SHIFT                   0x00000000

// VAP_PORT_IDX13
#define	VAP_PORT_IDX13__IDXPORT13__SHIFT                   0x00000000

// VAP_PORT_IDX14
#define	VAP_PORT_IDX14__IDXPORT14__SHIFT                   0x00000000

// VAP_PORT_IDX15
#define	VAP_PORT_IDX15__IDXPORT15__SHIFT                   0x00000000

// VAP_CNTL
#define	VAP_CNTL__PVS_NUM_SLOTS__SHIFT                     0x00000000
#define	VAP_CNTL__PVS_NUM_CNTLRS__SHIFT                    0x00000004
#define	VAP_CNTL__PVS_NUM_FPUS__SHIFT                      0x00000008
#define	VAP_CNTL__VF_MAX_VTX_NUM__SHIFT                    0x00000012
#define	VAP_CNTL__DX_CLIP_SPACE_DEF__SHIFT                 0x00000016

// VAP_VF_CNTL
#define	VAP_VF_CNTL__PRIM_TYPE__SHIFT                      0x00000000
#define	VAP_VF_CNTL__PRIM_WALK__SHIFT                      0x00000004
#define	VAP_VF_CNTL__RSVD_PREV_USED__SHIFT                 0x00000006
#define	VAP_VF_CNTL__INDEX_SIZE__SHIFT                     0x0000000b
#define	VAP_VF_CNTL__VTX_REUSE_DIS__SHIFT                  0x0000000c
#define	VAP_VF_CNTL__DUAL_INDEX_MODE__SHIFT                0x0000000d
#define	VAP_VF_CNTL__NUM_VERTICES__SHIFT                   0x00000010

// VAP_OUT_VTX_FMT_0
#define	VAP_OUT_VTX_FMT_0__VTX_POS_PRESENT__SHIFT          0x00000000
#define	VAP_OUT_VTX_FMT_0__VTX_COLOR_0_PRESENT__SHIFT      0x00000001
#define	VAP_OUT_VTX_FMT_0__VTX_COLOR_1_PRESENT__SHIFT      0x00000002
#define	VAP_OUT_VTX_FMT_0__VTX_COLOR_2_PRESENT__SHIFT      0x00000003
#define	VAP_OUT_VTX_FMT_0__VTX_COLOR_3_PRESENT__SHIFT      0x00000004
#define	VAP_OUT_VTX_FMT_0__VTX_PT_SIZE_PRESENT__SHIFT      0x00000010

// VAP_OUT_VTX_FMT_1
#define	VAP_OUT_VTX_FMT_1__TEX_0_COMP_CNT__SHIFT           0x00000000
#define	VAP_OUT_VTX_FMT_1__TEX_1_COMP_CNT__SHIFT           0x00000003
#define	VAP_OUT_VTX_FMT_1__TEX_2_COMP_CNT__SHIFT           0x00000006
#define	VAP_OUT_VTX_FMT_1__TEX_3_COMP_CNT__SHIFT           0x00000009
#define	VAP_OUT_VTX_FMT_1__TEX_4_COMP_CNT__SHIFT           0x0000000c
#define	VAP_OUT_VTX_FMT_1__TEX_5_COMP_CNT__SHIFT           0x0000000f
#define	VAP_OUT_VTX_FMT_1__TEX_6_COMP_CNT__SHIFT           0x00000012
#define	VAP_OUT_VTX_FMT_1__TEX_7_COMP_CNT__SHIFT           0x00000015

// VAP_VPORT_XSCALE
#define	VAP_VPORT_XSCALE__VPORT_XSCALE__SHIFT              0x00000000

// VAP_VPORT_XOFFSET
#define	VAP_VPORT_XOFFSET__VPORT_XOFFSET__SHIFT            0x00000000

// VAP_VPORT_YSCALE
#define	VAP_VPORT_YSCALE__VPORT_YSCALE__SHIFT              0x00000000

// VAP_VPORT_YOFFSET
#define	VAP_VPORT_YOFFSET__VPORT_YOFFSET__SHIFT            0x00000000

// VAP_VPORT_ZSCALE
#define	VAP_VPORT_ZSCALE__VPORT_ZSCALE__SHIFT              0x00000000

// VAP_VPORT_ZOFFSET
#define	VAP_VPORT_ZOFFSET__VPORT_ZOFFSET__SHIFT            0x00000000

// VAP_VTE_CNTL
#define	VAP_VTE_CNTL__VPORT_X_SCALE_ENA__SHIFT             0x00000000
#define	VAP_VTE_CNTL__VPORT_X_OFFSET_ENA__SHIFT            0x00000001
#define	VAP_VTE_CNTL__VPORT_Y_SCALE_ENA__SHIFT             0x00000002
#define	VAP_VTE_CNTL__VPORT_Y_OFFSET_ENA__SHIFT            0x00000003
#define	VAP_VTE_CNTL__VPORT_Z_SCALE_ENA__SHIFT             0x00000004
#define	VAP_VTE_CNTL__VPORT_Z_OFFSET_ENA__SHIFT            0x00000005
#define	VAP_VTE_CNTL__VTX_XY_FMT__SHIFT                    0x00000008
#define	VAP_VTE_CNTL__VTX_Z_FMT__SHIFT                     0x00000009
#define	VAP_VTE_CNTL__VTX_W0_FMT__SHIFT                    0x0000000a
#define	VAP_VTE_CNTL__SERIAL_PROC_ENA__SHIFT               0x0000000b

// VAP_VTX_SIZE
#define	VAP_VTX_SIZE__DWORDS_PER_VTX__SHIFT                0x00000000

// VAP_PORT_DATA_IDX_128
#define	VAP_PORT_DATA_IDX_128__DATA_IDX_PORT_128__SHIFT    0x00000000

// VAP_VTX_NUM_ARRAYS
#define	VAP_VTX_NUM_ARRAYS__VTX_NUM_ARRAYS__SHIFT          0x00000000
#define	VAP_VTX_NUM_ARRAYS__VC_FORCE_PREFETCH__SHIFT       0x00000005
#define	VAP_VTX_NUM_ARRAYS__VC_DIS_CACHE_INVLD__SHIFT      0x00000006
#define	VAP_VTX_NUM_ARRAYS__AOS_0_FETCH_SIZE__SHIFT        0x00000010
#define	VAP_VTX_NUM_ARRAYS__AOS_1_FETCH_SIZE__SHIFT        0x00000011
#define	VAP_VTX_NUM_ARRAYS__AOS_2_FETCH_SIZE__SHIFT        0x00000012
#define	VAP_VTX_NUM_ARRAYS__AOS_3_FETCH_SIZE__SHIFT        0x00000013
#define	VAP_VTX_NUM_ARRAYS__AOS_4_FETCH_SIZE__SHIFT        0x00000014
#define	VAP_VTX_NUM_ARRAYS__AOS_5_FETCH_SIZE__SHIFT        0x00000015
#define	VAP_VTX_NUM_ARRAYS__AOS_6_FETCH_SIZE__SHIFT        0x00000016
#define	VAP_VTX_NUM_ARRAYS__AOS_7_FETCH_SIZE__SHIFT        0x00000017
#define	VAP_VTX_NUM_ARRAYS__AOS_8_FETCH_SIZE__SHIFT        0x00000018
#define	VAP_VTX_NUM_ARRAYS__AOS_9_FETCH_SIZE__SHIFT        0x00000019
#define	VAP_VTX_NUM_ARRAYS__AOS_10_FETCH_SIZE__SHIFT       0x0000001a
#define	VAP_VTX_NUM_ARRAYS__AOS_11_FETCH_SIZE__SHIFT       0x0000001b
#define	VAP_VTX_NUM_ARRAYS__AOS_12_FETCH_SIZE__SHIFT       0x0000001c
#define	VAP_VTX_NUM_ARRAYS__AOS_13_FETCH_SIZE__SHIFT       0x0000001d
#define	VAP_VTX_NUM_ARRAYS__AOS_14_FETCH_SIZE__SHIFT       0x0000001e
#define	VAP_VTX_NUM_ARRAYS__AOS_15_FETCH_SIZE__SHIFT       0x0000001f

// VAP_VTX_AOS_ATTR01
#define	VAP_VTX_AOS_ATTR01__VTX_AOS_COUNT0__SHIFT          0x00000000
#define	VAP_VTX_AOS_ATTR01__VTX_AOS_STRIDE0__SHIFT         0x00000008
#define	VAP_VTX_AOS_ATTR01__VTX_AOS_COUNT1__SHIFT          0x00000010
#define	VAP_VTX_AOS_ATTR01__VTX_AOS_STRIDE1__SHIFT         0x00000018

// VAP_VTX_AOS_ADDR0
#define	VAP_VTX_AOS_ADDR0__VTX_AOS_ADDR0__SHIFT            0x00000002

// VAP_VTX_AOS_ADDR1
#define	VAP_VTX_AOS_ADDR1__VTX_AOS_ADDR1__SHIFT            0x00000002

// VAP_VTX_AOS_ATTR23
#define	VAP_VTX_AOS_ATTR23__VTX_AOS_COUNT2__SHIFT          0x00000000
#define	VAP_VTX_AOS_ATTR23__VTX_AOS_STRIDE2__SHIFT         0x00000008
#define	VAP_VTX_AOS_ATTR23__VTX_AOS_COUNT3__SHIFT          0x00000010
#define	VAP_VTX_AOS_ATTR23__VTX_AOS_STRIDE3__SHIFT         0x00000018

// VAP_VTX_AOS_ADDR2
#define	VAP_VTX_AOS_ADDR2__VTX_AOS_ADDR2__SHIFT            0x00000002

// VAP_VTX_AOS_ADDR3
#define	VAP_VTX_AOS_ADDR3__VTX_AOS_ADDR3__SHIFT            0x00000002

// VAP_VTX_AOS_ATTR45
#define	VAP_VTX_AOS_ATTR45__VTX_AOS_COUNT4__SHIFT          0x00000000
#define	VAP_VTX_AOS_ATTR45__VTX_AOS_STRIDE4__SHIFT         0x00000008
#define	VAP_VTX_AOS_ATTR45__VTX_AOS_COUNT5__SHIFT          0x00000010
#define	VAP_VTX_AOS_ATTR45__VTX_AOS_STRIDE5__SHIFT         0x00000018

// VAP_VTX_AOS_ADDR4
#define	VAP_VTX_AOS_ADDR4__VTX_AOS_ADDR4__SHIFT            0x00000002

// VAP_VTX_AOS_ADDR5
#define	VAP_VTX_AOS_ADDR5__VTX_AOS_ADDR5__SHIFT            0x00000002

// VAP_VTX_AOS_ATTR67
#define	VAP_VTX_AOS_ATTR67__VTX_AOS_COUNT6__SHIFT          0x00000000
#define	VAP_VTX_AOS_ATTR67__VTX_AOS_STRIDE6__SHIFT         0x00000008
#define	VAP_VTX_AOS_ATTR67__VTX_AOS_COUNT7__SHIFT          0x00000010
#define	VAP_VTX_AOS_ATTR67__VTX_AOS_STRIDE7__SHIFT         0x00000018

// VAP_VTX_AOS_ADDR6
#define	VAP_VTX_AOS_ADDR6__VTX_AOS_ADDR6__SHIFT            0x00000002

// VAP_VTX_AOS_ADDR7
#define	VAP_VTX_AOS_ADDR7__VTX_AOS_ADDR7__SHIFT            0x00000002

// VAP_VTX_AOS_ATTR89
#define	VAP_VTX_AOS_ATTR89__VTX_AOS_COUNT8__SHIFT          0x00000000
#define	VAP_VTX_AOS_ATTR89__VTX_AOS_STRIDE8__SHIFT         0x00000008
#define	VAP_VTX_AOS_ATTR89__VTX_AOS_COUNT9__SHIFT          0x00000010
#define	VAP_VTX_AOS_ATTR89__VTX_AOS_STRIDE9__SHIFT         0x00000018

// VAP_VTX_AOS_ADDR8
#define	VAP_VTX_AOS_ADDR8__VTX_AOS_ADDR8__SHIFT            0x00000002

// VAP_VTX_AOS_ADDR9
#define	VAP_VTX_AOS_ADDR9__VTX_AOS_ADDR9__SHIFT            0x00000002

// VAP_VTX_AOS_ATTR1011
#define	VAP_VTX_AOS_ATTR1011__VTX_AOS_COUNT10__SHIFT       0x00000000
#define	VAP_VTX_AOS_ATTR1011__VTX_AOS_STRIDE10__SHIFT      0x00000008
#define	VAP_VTX_AOS_ATTR1011__VTX_AOS_COUNT11__SHIFT       0x00000010
#define	VAP_VTX_AOS_ATTR1011__VTX_AOS_STRIDE11__SHIFT      0x00000018

// VAP_VTX_AOS_ADDR10
#define	VAP_VTX_AOS_ADDR10__VTX_AOS_ADDR10__SHIFT          0x00000002

// VAP_VTX_AOS_ADDR11
#define	VAP_VTX_AOS_ADDR11__VTX_AOS_ADDR11__SHIFT          0x00000002

// VAP_VTX_AOS_ATTR1213
#define	VAP_VTX_AOS_ATTR1213__VTX_AOS_COUNT12__SHIFT       0x00000000
#define	VAP_VTX_AOS_ATTR1213__VTX_AOS_STRIDE12__SHIFT      0x00000008
#define	VAP_VTX_AOS_ATTR1213__VTX_AOS_COUNT13__SHIFT       0x00000010
#define	VAP_VTX_AOS_ATTR1213__VTX_AOS_STRIDE13__SHIFT      0x00000018

// VAP_VTX_AOS_ADDR12
#define	VAP_VTX_AOS_ADDR12__VTX_AOS_ADDR12__SHIFT          0x00000002

// VAP_VTX_AOS_ADDR13
#define	VAP_VTX_AOS_ADDR13__VTX_AOS_ADDR13__SHIFT          0x00000002

// VAP_VTX_AOS_ATTR1415
#define	VAP_VTX_AOS_ATTR1415__VTX_AOS_COUNT14__SHIFT       0x00000000
#define	VAP_VTX_AOS_ATTR1415__VTX_AOS_STRIDE14__SHIFT      0x00000008
#define	VAP_VTX_AOS_ATTR1415__VTX_AOS_COUNT15__SHIFT       0x00000010
#define	VAP_VTX_AOS_ATTR1415__VTX_AOS_STRIDE15__SHIFT      0x00000018

// VAP_VTX_AOS_ADDR14
#define	VAP_VTX_AOS_ADDR14__VTX_AOS_ADDR14__SHIFT          0x00000002

// VAP_VTX_AOS_ADDR15
#define	VAP_VTX_AOS_ADDR15__VTX_AOS_ADDR15__SHIFT          0x00000002

// VAP_PERF_CNTL_0
#define	VAP_PERF_CNTL_0__PERF_SEL_0__SHIFT                 0x00000000
#define	VAP_PERF_CNTL_0__CLR_PERF_0__SHIFT                 0x00000004
#define	VAP_PERF_CNTL_0__EN_PERF_0__SHIFT                  0x00000005
#define	VAP_PERF_CNTL_0__NUM_VERTS_TO_BYPASS_0__SHIFT      0x00000008
#define	VAP_PERF_CNTL_0__NUM_VERTS_TO_COUNT_0__SHIFT       0x00000010

// VAP_PERF_CNTL_1
#define	VAP_PERF_CNTL_1__PERF_SEL_1__SHIFT                 0x00000000
#define	VAP_PERF_CNTL_1__CLR_PERF_1__SHIFT                 0x00000004
#define	VAP_PERF_CNTL_1__EN_PERF_1__SHIFT                  0x00000005
#define	VAP_PERF_CNTL_1__NUM_VERTS_TO_BYPASS_1__SHIFT      0x00000008
#define	VAP_PERF_CNTL_1__NUM_VERTS_TO_COUNT_1__SHIFT       0x00000010

// VAP_PERF_COUNT_0
#define	VAP_PERF_COUNT_0__PERF_COUNT_0__SHIFT              0x00000000

// VAP_PERF_COUNT_1
#define	VAP_PERF_COUNT_1__PERF_COUNT_1__SHIFT              0x00000000

// VAP_VF_MAX_VTX_INDX
#define	VAP_VF_MAX_VTX_INDX__MAX_INDX__SHIFT               0x00000000

// VAP_VF_MIN_VTX_INDX
#define	VAP_VF_MIN_VTX_INDX__MIN_INDX__SHIFT               0x00000000

// VAP_DEBUG
#define	VAP_DEBUG__VC_DIS_2OW_PERF__SHIFT                  0x00000000
#define	VAP_DEBUG__DEBUG_BITS__SHIFT                       0x00000001

// VAP_CNTL_STATUS
#define	VAP_CNTL_STATUS__VC_SWAP__SHIFT                    0x00000000
#define	VAP_CNTL_STATUS__PVS_BYPASS__SHIFT                 0x00000008
#define	VAP_CNTL_STATUS__PVS_BUSY__SHIFT                   0x0000000b
#define	VAP_CNTL_STATUS__VS_BUSY__SHIFT                    0x00000018
#define	VAP_CNTL_STATUS__RCP_BUSY__SHIFT                   0x00000019
#define	VAP_CNTL_STATUS__VTE_BUSY__SHIFT                   0x0000001a
#define	VAP_CNTL_STATUS__MIU_BUSY__SHIFT                   0x0000001b
#define	VAP_CNTL_STATUS__VC_BUSY__SHIFT                    0x0000001c
#define	VAP_CNTL_STATUS__VF_BUSY__SHIFT                    0x0000001d
#define	VAP_CNTL_STATUS__REGPIPE_BUSY__SHIFT               0x0000001e
#define	VAP_CNTL_STATUS__VAP_BUSY__SHIFT                   0x0000001f

// VAP_PERF_CNTL_2
#define	VAP_PERF_CNTL_2__PERF_SEL_2__SHIFT                 0x00000000
#define	VAP_PERF_CNTL_2__CLR_PERF_2__SHIFT                 0x00000004
#define	VAP_PERF_CNTL_2__EN_PERF_2__SHIFT                  0x00000005
#define	VAP_PERF_CNTL_2__NUM_VERTS_TO_BYPASS_2__SHIFT      0x00000008
#define	VAP_PERF_CNTL_2__NUM_VERTS_TO_COUNT_2__SHIFT       0x00000010

// VAP_PERF_COUNT_2
#define	VAP_PERF_COUNT_2__PERF_COUNT_2__SHIFT              0x00000000

// VAP_PROG_STREAM_CNTL_0
#define	VAP_PROG_STREAM_CNTL_0__DATA_TYPE_0__SHIFT         0x00000000
#define	VAP_PROG_STREAM_CNTL_0__SKIP_DWORDS_0__SHIFT       0x00000004
#define	VAP_PROG_STREAM_CNTL_0__DST_VEC_LOC_0__SHIFT       0x00000008
#define	VAP_PROG_STREAM_CNTL_0__LAST_VEC_0__SHIFT          0x0000000d
#define	VAP_PROG_STREAM_CNTL_0__SIGNED_0__SHIFT            0x0000000e
#define	VAP_PROG_STREAM_CNTL_0__NORMALIZE_0__SHIFT         0x0000000f
#define	VAP_PROG_STREAM_CNTL_0__DATA_TYPE_1__SHIFT         0x00000010
#define	VAP_PROG_STREAM_CNTL_0__SKIP_DWORDS_1__SHIFT       0x00000014
#define	VAP_PROG_STREAM_CNTL_0__DST_VEC_LOC_1__SHIFT       0x00000018
#define	VAP_PROG_STREAM_CNTL_0__LAST_VEC_1__SHIFT          0x0000001d
#define	VAP_PROG_STREAM_CNTL_0__SIGNED_1__SHIFT            0x0000001e
#define	VAP_PROG_STREAM_CNTL_0__NORMALIZE_1__SHIFT         0x0000001f

// VAP_PROG_STREAM_CNTL_1
#define	VAP_PROG_STREAM_CNTL_1__DATA_TYPE_2__SHIFT         0x00000000
#define	VAP_PROG_STREAM_CNTL_1__SKIP_DWORDS_2__SHIFT       0x00000004
#define	VAP_PROG_STREAM_CNTL_1__DST_VEC_LOC_2__SHIFT       0x00000008
#define	VAP_PROG_STREAM_CNTL_1__LAST_VEC_2__SHIFT          0x0000000d
#define	VAP_PROG_STREAM_CNTL_1__SIGNED_2__SHIFT            0x0000000e
#define	VAP_PROG_STREAM_CNTL_1__NORMALIZE_2__SHIFT         0x0000000f
#define	VAP_PROG_STREAM_CNTL_1__DATA_TYPE_3__SHIFT         0x00000010
#define	VAP_PROG_STREAM_CNTL_1__SKIP_DWORDS_3__SHIFT       0x00000014
#define	VAP_PROG_STREAM_CNTL_1__DST_VEC_LOC_3__SHIFT       0x00000018
#define	VAP_PROG_STREAM_CNTL_1__LAST_VEC_3__SHIFT          0x0000001d
#define	VAP_PROG_STREAM_CNTL_1__SIGNED_3__SHIFT            0x0000001e
#define	VAP_PROG_STREAM_CNTL_1__NORMALIZE_3__SHIFT         0x0000001f

// VAP_PROG_STREAM_CNTL_2
#define	VAP_PROG_STREAM_CNTL_2__DATA_TYPE_4__SHIFT         0x00000000
#define	VAP_PROG_STREAM_CNTL_2__SKIP_DWORDS_4__SHIFT       0x00000004
#define	VAP_PROG_STREAM_CNTL_2__DST_VEC_LOC_4__SHIFT       0x00000008
#define	VAP_PROG_STREAM_CNTL_2__LAST_VEC_4__SHIFT          0x0000000d
#define	VAP_PROG_STREAM_CNTL_2__SIGNED_4__SHIFT            0x0000000e
#define	VAP_PROG_STREAM_CNTL_2__NORMALIZE_4__SHIFT         0x0000000f
#define	VAP_PROG_STREAM_CNTL_2__DATA_TYPE_5__SHIFT         0x00000010
#define	VAP_PROG_STREAM_CNTL_2__SKIP_DWORDS_5__SHIFT       0x00000014
#define	VAP_PROG_STREAM_CNTL_2__DST_VEC_LOC_5__SHIFT       0x00000018
#define	VAP_PROG_STREAM_CNTL_2__LAST_VEC_5__SHIFT          0x0000001d
#define	VAP_PROG_STREAM_CNTL_2__SIGNED_5__SHIFT            0x0000001e
#define	VAP_PROG_STREAM_CNTL_2__NORMALIZE_5__SHIFT         0x0000001f

// VAP_PROG_STREAM_CNTL_3
#define	VAP_PROG_STREAM_CNTL_3__DATA_TYPE_6__SHIFT         0x00000000
#define	VAP_PROG_STREAM_CNTL_3__SKIP_DWORDS_6__SHIFT       0x00000004
#define	VAP_PROG_STREAM_CNTL_3__DST_VEC_LOC_6__SHIFT       0x00000008
#define	VAP_PROG_STREAM_CNTL_3__LAST_VEC_6__SHIFT          0x0000000d
#define	VAP_PROG_STREAM_CNTL_3__SIGNED_6__SHIFT            0x0000000e
#define	VAP_PROG_STREAM_CNTL_3__NORMALIZE_6__SHIFT         0x0000000f
#define	VAP_PROG_STREAM_CNTL_3__DATA_TYPE_7__SHIFT         0x00000010
#define	VAP_PROG_STREAM_CNTL_3__SKIP_DWORDS_7__SHIFT       0x00000014
#define	VAP_PROG_STREAM_CNTL_3__DST_VEC_LOC_7__SHIFT       0x00000018
#define	VAP_PROG_STREAM_CNTL_3__LAST_VEC_7__SHIFT          0x0000001d
#define	VAP_PROG_STREAM_CNTL_3__SIGNED_7__SHIFT            0x0000001e
#define	VAP_PROG_STREAM_CNTL_3__NORMALIZE_7__SHIFT         0x0000001f

// VAP_PROG_STREAM_CNTL_4
#define	VAP_PROG_STREAM_CNTL_4__DATA_TYPE_8__SHIFT         0x00000000
#define	VAP_PROG_STREAM_CNTL_4__SKIP_DWORDS_8__SHIFT       0x00000004
#define	VAP_PROG_STREAM_CNTL_4__DST_VEC_LOC_8__SHIFT       0x00000008
#define	VAP_PROG_STREAM_CNTL_4__LAST_VEC_8__SHIFT          0x0000000d
#define	VAP_PROG_STREAM_CNTL_4__SIGNED_8__SHIFT            0x0000000e
#define	VAP_PROG_STREAM_CNTL_4__NORMALIZE_8__SHIFT         0x0000000f
#define	VAP_PROG_STREAM_CNTL_4__DATA_TYPE_9__SHIFT         0x00000010
#define	VAP_PROG_STREAM_CNTL_4__SKIP_DWORDS_9__SHIFT       0x00000014
#define	VAP_PROG_STREAM_CNTL_4__DST_VEC_LOC_9__SHIFT       0x00000018
#define	VAP_PROG_STREAM_CNTL_4__LAST_VEC_9__SHIFT          0x0000001d
#define	VAP_PROG_STREAM_CNTL_4__SIGNED_9__SHIFT            0x0000001e
#define	VAP_PROG_STREAM_CNTL_4__NORMALIZE_9__SHIFT         0x0000001f

// VAP_PROG_STREAM_CNTL_5
#define	VAP_PROG_STREAM_CNTL_5__DATA_TYPE_10__SHIFT        0x00000000
#define	VAP_PROG_STREAM_CNTL_5__SKIP_DWORDS_10__SHIFT      0x00000004
#define	VAP_PROG_STREAM_CNTL_5__DST_VEC_LOC_10__SHIFT      0x00000008
#define	VAP_PROG_STREAM_CNTL_5__LAST_VEC_10__SHIFT         0x0000000d
#define	VAP_PROG_STREAM_CNTL_5__SIGNED_10__SHIFT           0x0000000e
#define	VAP_PROG_STREAM_CNTL_5__NORMALIZE_10__SHIFT        0x0000000f
#define	VAP_PROG_STREAM_CNTL_5__DATA_TYPE_11__SHIFT        0x00000010
#define	VAP_PROG_STREAM_CNTL_5__SKIP_DWORDS_11__SHIFT      0x00000014
#define	VAP_PROG_STREAM_CNTL_5__DST_VEC_LOC_11__SHIFT      0x00000018
#define	VAP_PROG_STREAM_CNTL_5__LAST_VEC_11__SHIFT         0x0000001d
#define	VAP_PROG_STREAM_CNTL_5__SIGNED_11__SHIFT           0x0000001e
#define	VAP_PROG_STREAM_CNTL_5__NORMALIZE_11__SHIFT        0x0000001f

// VAP_PROG_STREAM_CNTL_6
#define	VAP_PROG_STREAM_CNTL_6__DATA_TYPE_12__SHIFT        0x00000000
#define	VAP_PROG_STREAM_CNTL_6__SKIP_DWORDS_12__SHIFT      0x00000004
#define	VAP_PROG_STREAM_CNTL_6__DST_VEC_LOC_12__SHIFT      0x00000008
#define	VAP_PROG_STREAM_CNTL_6__LAST_VEC_12__SHIFT         0x0000000d
#define	VAP_PROG_STREAM_CNTL_6__SIGNED_12__SHIFT           0x0000000e
#define	VAP_PROG_STREAM_CNTL_6__NORMALIZE_12__SHIFT        0x0000000f
#define	VAP_PROG_STREAM_CNTL_6__DATA_TYPE_13__SHIFT        0x00000010
#define	VAP_PROG_STREAM_CNTL_6__SKIP_DWORDS_13__SHIFT      0x00000014
#define	VAP_PROG_STREAM_CNTL_6__DST_VEC_LOC_13__SHIFT      0x00000018
#define	VAP_PROG_STREAM_CNTL_6__LAST_VEC_13__SHIFT         0x0000001d
#define	VAP_PROG_STREAM_CNTL_6__SIGNED_13__SHIFT           0x0000001e
#define	VAP_PROG_STREAM_CNTL_6__NORMALIZE_13__SHIFT        0x0000001f

// VAP_PROG_STREAM_CNTL_7
#define	VAP_PROG_STREAM_CNTL_7__DATA_TYPE_14__SHIFT        0x00000000
#define	VAP_PROG_STREAM_CNTL_7__SKIP_DWORDS_14__SHIFT      0x00000004
#define	VAP_PROG_STREAM_CNTL_7__DST_VEC_LOC_14__SHIFT      0x00000008
#define	VAP_PROG_STREAM_CNTL_7__LAST_VEC_14__SHIFT         0x0000000d
#define	VAP_PROG_STREAM_CNTL_7__SIGNED_14__SHIFT           0x0000000e
#define	VAP_PROG_STREAM_CNTL_7__NORMALIZE_14__SHIFT        0x0000000f
#define	VAP_PROG_STREAM_CNTL_7__DATA_TYPE_15__SHIFT        0x00000010
#define	VAP_PROG_STREAM_CNTL_7__SKIP_DWORDS_15__SHIFT      0x00000014
#define	VAP_PROG_STREAM_CNTL_7__DST_VEC_LOC_15__SHIFT      0x00000018
#define	VAP_PROG_STREAM_CNTL_7__LAST_VEC_15__SHIFT         0x0000001d
#define	VAP_PROG_STREAM_CNTL_7__SIGNED_15__SHIFT           0x0000001e
#define	VAP_PROG_STREAM_CNTL_7__NORMALIZE_15__SHIFT        0x0000001f

// VAP_VTX_STATE_CNTL
#define	VAP_VTX_STATE_CNTL__COLOR_0_ASSEMBLY_CNTL__SHIFT   0x00000000
#define	VAP_VTX_STATE_CNTL__COLOR_1_ASSEMBLY_CNTL__SHIFT   0x00000002
#define	VAP_VTX_STATE_CNTL__COLOR_2_ASSEMBLY_CNTL__SHIFT   0x00000004
#define	VAP_VTX_STATE_CNTL__COLOR_3_ASSEMBLY_CNTL__SHIFT   0x00000006
#define	VAP_VTX_STATE_CNTL__COLOR_4_ASSEMBLY_CNTL__SHIFT   0x00000008
#define	VAP_VTX_STATE_CNTL__COLOR_5_ASSEMBLY_CNTL__SHIFT   0x0000000a
#define	VAP_VTX_STATE_CNTL__COLOR_6_ASSEMBLY_CNTL__SHIFT   0x0000000c
#define	VAP_VTX_STATE_CNTL__COLOR_7_ASSEMBLY_CNTL__SHIFT   0x0000000e
#define	VAP_VTX_STATE_CNTL__UPDATE_USER_COLOR_0_ENA__SHIFT 0x00000010
#define	VAP_VTX_STATE_CNTL__USE_ADDR_IND_TBL__SHIFT        0x00000012

// VAP_VSM_VTX_ASSM
#define	VAP_VSM_VTX_ASSM__OUTPUT_VEC_CNTL__SHIFT           0x00000000

// VAP_VTX_STATE_IND_REG_0
#define	VAP_VTX_STATE_IND_REG_0__ADDR_0__SHIFT             0x00000000
#define	VAP_VTX_STATE_IND_REG_0__ADDR_1__SHIFT             0x00000008
#define	VAP_VTX_STATE_IND_REG_0__ADDR_2__SHIFT             0x00000010
#define	VAP_VTX_STATE_IND_REG_0__ADDR_3__SHIFT             0x00000018

// VAP_VTX_STATE_IND_REG_1
#define	VAP_VTX_STATE_IND_REG_1__ADDR_4__SHIFT             0x00000000
#define	VAP_VTX_STATE_IND_REG_1__ADDR_5__SHIFT             0x00000008
#define	VAP_VTX_STATE_IND_REG_1__ADDR_6__SHIFT             0x00000010
#define	VAP_VTX_STATE_IND_REG_1__ADDR_7__SHIFT             0x00000018

// VAP_VTX_STATE_IND_REG_2
#define	VAP_VTX_STATE_IND_REG_2__ADDR_8__SHIFT             0x00000000
#define	VAP_VTX_STATE_IND_REG_2__ADDR_9__SHIFT             0x00000008
#define	VAP_VTX_STATE_IND_REG_2__ADDR_10__SHIFT            0x00000010
#define	VAP_VTX_STATE_IND_REG_2__ADDR_11__SHIFT            0x00000018

// VAP_VTX_STATE_IND_REG_3
#define	VAP_VTX_STATE_IND_REG_3__ADDR_12__SHIFT            0x00000000
#define	VAP_VTX_STATE_IND_REG_3__ADDR_13__SHIFT            0x00000008
#define	VAP_VTX_STATE_IND_REG_3__ADDR_14__SHIFT            0x00000010
#define	VAP_VTX_STATE_IND_REG_3__ADDR_15__SHIFT            0x00000018

// VAP_VTX_STATE_IND_REG_4
#define	VAP_VTX_STATE_IND_REG_4__ADDR_16__SHIFT            0x00000000
#define	VAP_VTX_STATE_IND_REG_4__ADDR_17__SHIFT            0x00000008
#define	VAP_VTX_STATE_IND_REG_4__ADDR_18__SHIFT            0x00000010
#define	VAP_VTX_STATE_IND_REG_4__ADDR_19__SHIFT            0x00000018

// VAP_VTX_STATE_IND_REG_5
#define	VAP_VTX_STATE_IND_REG_5__ADDR_20__SHIFT            0x00000000
#define	VAP_VTX_STATE_IND_REG_5__ADDR_21__SHIFT            0x00000008
#define	VAP_VTX_STATE_IND_REG_5__ADDR_22__SHIFT            0x00000010
#define	VAP_VTX_STATE_IND_REG_5__ADDR_23__SHIFT            0x00000018

// VAP_VTX_STATE_IND_REG_6
#define	VAP_VTX_STATE_IND_REG_6__ADDR_24__SHIFT            0x00000000
#define	VAP_VTX_STATE_IND_REG_6__ADDR_25__SHIFT            0x00000008
#define	VAP_VTX_STATE_IND_REG_6__ADDR_26__SHIFT            0x00000010
#define	VAP_VTX_STATE_IND_REG_6__ADDR_27__SHIFT            0x00000018

// VAP_VTX_STATE_IND_REG_7
#define	VAP_VTX_STATE_IND_REG_7__ADDR_28__SHIFT            0x00000000
#define	VAP_VTX_STATE_IND_REG_7__ADDR_29__SHIFT            0x00000008
#define	VAP_VTX_STATE_IND_REG_7__ADDR_30__SHIFT            0x00000010
#define	VAP_VTX_STATE_IND_REG_7__ADDR_31__SHIFT            0x00000018

// VAP_VTX_STATE_IND_REG_8
#define	VAP_VTX_STATE_IND_REG_8__ADDR_32__SHIFT            0x00000000
#define	VAP_VTX_STATE_IND_REG_8__ADDR_33__SHIFT            0x00000008
#define	VAP_VTX_STATE_IND_REG_8__ADDR_34__SHIFT            0x00000010
#define	VAP_VTX_STATE_IND_REG_8__ADDR_35__SHIFT            0x00000018

// VAP_VTX_STATE_IND_REG_9
#define	VAP_VTX_STATE_IND_REG_9__ADDR_36__SHIFT            0x00000000
#define	VAP_VTX_STATE_IND_REG_9__ADDR_37__SHIFT            0x00000008
#define	VAP_VTX_STATE_IND_REG_9__ADDR_38__SHIFT            0x00000010
#define	VAP_VTX_STATE_IND_REG_9__ADDR_39__SHIFT            0x00000018

// VAP_VTX_STATE_IND_REG_10
#define	VAP_VTX_STATE_IND_REG_10__ADDR_40__SHIFT           0x00000000
#define	VAP_VTX_STATE_IND_REG_10__ADDR_41__SHIFT           0x00000008
#define	VAP_VTX_STATE_IND_REG_10__ADDR_42__SHIFT           0x00000010
#define	VAP_VTX_STATE_IND_REG_10__ADDR_43__SHIFT           0x00000018

// VAP_VTX_STATE_IND_REG_11
#define	VAP_VTX_STATE_IND_REG_11__ADDR_44__SHIFT           0x00000000
#define	VAP_VTX_STATE_IND_REG_11__ADDR_45__SHIFT           0x00000008
#define	VAP_VTX_STATE_IND_REG_11__ADDR_46__SHIFT           0x00000010
#define	VAP_VTX_STATE_IND_REG_11__ADDR_47__SHIFT           0x00000018

// VAP_VTX_STATE_IND_REG_12
#define	VAP_VTX_STATE_IND_REG_12__ADDR_48__SHIFT           0x00000000
#define	VAP_VTX_STATE_IND_REG_12__ADDR_49__SHIFT           0x00000008
#define	VAP_VTX_STATE_IND_REG_12__ADDR_50__SHIFT           0x00000010
#define	VAP_VTX_STATE_IND_REG_12__ADDR_51__SHIFT           0x00000018

// VAP_VTX_STATE_IND_REG_13
#define	VAP_VTX_STATE_IND_REG_13__ADDR_52__SHIFT           0x00000000
#define	VAP_VTX_STATE_IND_REG_13__ADDR_53__SHIFT           0x00000008
#define	VAP_VTX_STATE_IND_REG_13__ADDR_54__SHIFT           0x00000010
#define	VAP_VTX_STATE_IND_REG_13__ADDR_55__SHIFT           0x00000018

// VAP_VTX_STATE_IND_REG_14
#define	VAP_VTX_STATE_IND_REG_14__ADDR_56__SHIFT           0x00000000
#define	VAP_VTX_STATE_IND_REG_14__ADDR_57__SHIFT           0x00000008
#define	VAP_VTX_STATE_IND_REG_14__ADDR_58__SHIFT           0x00000010
#define	VAP_VTX_STATE_IND_REG_14__ADDR_59__SHIFT           0x00000018

// VAP_VTX_STATE_IND_REG_15
#define	VAP_VTX_STATE_IND_REG_15__ADDR_60__SHIFT           0x00000000
#define	VAP_VTX_STATE_IND_REG_15__ADDR_61__SHIFT           0x00000008
#define	VAP_VTX_STATE_IND_REG_15__ADDR_62__SHIFT           0x00000010
#define	VAP_VTX_STATE_IND_REG_15__ADDR_63__SHIFT           0x00000018

// VAP_PSC_SGN_NORM_CNTL
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_0__SHIFT    0x00000000
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_1__SHIFT    0x00000002
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_2__SHIFT    0x00000004
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_3__SHIFT    0x00000006
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_4__SHIFT    0x00000008
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_5__SHIFT    0x0000000a
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_6__SHIFT    0x0000000c
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_7__SHIFT    0x0000000e
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_8__SHIFT    0x00000010
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_9__SHIFT    0x00000012
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_10__SHIFT   0x00000014
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_11__SHIFT   0x00000016
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_12__SHIFT   0x00000018
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_13__SHIFT   0x0000001a
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_14__SHIFT   0x0000001c
#define	VAP_PSC_SGN_NORM_CNTL__SGN_NORM_METHOD_15__SHIFT   0x0000001e

// VAP_PROG_STREAM_CNTL_EXT_0
#define	VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_X_0__SHIFT 0x00000000
#define	VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_Y_0__SHIFT 0x00000003
#define	VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_Z_0__SHIFT 0x00000006
#define	VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_W_0__SHIFT 0x00000009
#define	VAP_PROG_STREAM_CNTL_EXT_0__WRITE_ENA_0__SHIFT     0x0000000c
#define	VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_X_1__SHIFT 0x00000010
#define	VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_Y_1__SHIFT 0x00000013
#define	VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_Z_1__SHIFT 0x00000016
#define	VAP_PROG_STREAM_CNTL_EXT_0__SWIZZLE_SELECT_W_1__SHIFT 0x00000019
#define	VAP_PROG_STREAM_CNTL_EXT_0__WRITE_ENA_1__SHIFT     0x0000001c

// VAP_PROG_STREAM_CNTL_EXT_1
#define	VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_X_2__SHIFT 0x00000000
#define	VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_Y_2__SHIFT 0x00000003
#define	VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_Z_2__SHIFT 0x00000006
#define	VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_W_2__SHIFT 0x00000009
#define	VAP_PROG_STREAM_CNTL_EXT_1__WRITE_ENA_2__SHIFT     0x0000000c
#define	VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_X_3__SHIFT 0x00000010
#define	VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_Y_3__SHIFT 0x00000013
#define	VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_Z_3__SHIFT 0x00000016
#define	VAP_PROG_STREAM_CNTL_EXT_1__SWIZZLE_SELECT_W_3__SHIFT 0x00000019
#define	VAP_PROG_STREAM_CNTL_EXT_1__WRITE_ENA_3__SHIFT     0x0000001c

// VAP_PROG_STREAM_CNTL_EXT_2
#define	VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_X_4__SHIFT 0x00000000
#define	VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_Y_4__SHIFT 0x00000003
#define	VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_Z_4__SHIFT 0x00000006
#define	VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_W_4__SHIFT 0x00000009
#define	VAP_PROG_STREAM_CNTL_EXT_2__WRITE_ENA_4__SHIFT     0x0000000c
#define	VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_X_5__SHIFT 0x00000010
#define	VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_Y_5__SHIFT 0x00000013
#define	VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_Z_5__SHIFT 0x00000016
#define	VAP_PROG_STREAM_CNTL_EXT_2__SWIZZLE_SELECT_W_5__SHIFT 0x00000019
#define	VAP_PROG_STREAM_CNTL_EXT_2__WRITE_ENA_5__SHIFT     0x0000001c

// VAP_PROG_STREAM_CNTL_EXT_3
#define	VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_X_6__SHIFT 0x00000000
#define	VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_Y_6__SHIFT 0x00000003
#define	VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_Z_6__SHIFT 0x00000006
#define	VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_W_6__SHIFT 0x00000009
#define	VAP_PROG_STREAM_CNTL_EXT_3__WRITE_ENA_6__SHIFT     0x0000000c
#define	VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_X_7__SHIFT 0x00000010
#define	VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_Y_7__SHIFT 0x00000013
#define	VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_Z_7__SHIFT 0x00000016
#define	VAP_PROG_STREAM_CNTL_EXT_3__SWIZZLE_SELECT_W_7__SHIFT 0x00000019
#define	VAP_PROG_STREAM_CNTL_EXT_3__WRITE_ENA_7__SHIFT     0x0000001c

// VAP_PROG_STREAM_CNTL_EXT_4
#define	VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_X_8__SHIFT 0x00000000
#define	VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_Y_8__SHIFT 0x00000003
#define	VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_Z_8__SHIFT 0x00000006
#define	VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_W_8__SHIFT 0x00000009
#define	VAP_PROG_STREAM_CNTL_EXT_4__WRITE_ENA_8__SHIFT     0x0000000c
#define	VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_X_9__SHIFT 0x00000010
#define	VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_Y_9__SHIFT 0x00000013
#define	VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_Z_9__SHIFT 0x00000016
#define	VAP_PROG_STREAM_CNTL_EXT_4__SWIZZLE_SELECT_W_9__SHIFT 0x00000019
#define	VAP_PROG_STREAM_CNTL_EXT_4__WRITE_ENA_9__SHIFT     0x0000001c

// VAP_PROG_STREAM_CNTL_EXT_5
#define	VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_X_10__SHIFT 0x00000000
#define	VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_Y_10__SHIFT 0x00000003
#define	VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_Z_10__SHIFT 0x00000006
#define	VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_W_10__SHIFT 0x00000009
#define	VAP_PROG_STREAM_CNTL_EXT_5__WRITE_ENA_10__SHIFT    0x0000000c
#define	VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_X_11__SHIFT 0x00000010
#define	VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_Y_11__SHIFT 0x00000013
#define	VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_Z_11__SHIFT 0x00000016
#define	VAP_PROG_STREAM_CNTL_EXT_5__SWIZZLE_SELECT_W_11__SHIFT 0x00000019
#define	VAP_PROG_STREAM_CNTL_EXT_5__WRITE_ENA_11__SHIFT    0x0000001c

// VAP_PROG_STREAM_CNTL_EXT_6
#define	VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_X_12__SHIFT 0x00000000
#define	VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_Y_12__SHIFT 0x00000003
#define	VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_Z_12__SHIFT 0x00000006
#define	VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_W_12__SHIFT 0x00000009
#define	VAP_PROG_STREAM_CNTL_EXT_6__WRITE_ENA_12__SHIFT    0x0000000c
#define	VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_X_13__SHIFT 0x00000010
#define	VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_Y_13__SHIFT 0x00000013
#define	VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_Z_13__SHIFT 0x00000016
#define	VAP_PROG_STREAM_CNTL_EXT_6__SWIZZLE_SELECT_W_13__SHIFT 0x00000019
#define	VAP_PROG_STREAM_CNTL_EXT_6__WRITE_ENA_13__SHIFT    0x0000001c

// VAP_PROG_STREAM_CNTL_EXT_7
#define	VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_X_14__SHIFT 0x00000000
#define	VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_Y_14__SHIFT 0x00000003
#define	VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_Z_14__SHIFT 0x00000006
#define	VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_W_14__SHIFT 0x00000009
#define	VAP_PROG_STREAM_CNTL_EXT_7__WRITE_ENA_14__SHIFT    0x0000000c
#define	VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_X_15__SHIFT 0x00000010
#define	VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_Y_15__SHIFT 0x00000013
#define	VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_Z_15__SHIFT 0x00000016
#define	VAP_PROG_STREAM_CNTL_EXT_7__SWIZZLE_SELECT_W_15__SHIFT 0x00000019
#define	VAP_PROG_STREAM_CNTL_EXT_7__WRITE_ENA_15__SHIFT    0x0000001c

// VAP_PVS_VECTOR_INDX_REG
#define	VAP_PVS_VECTOR_INDX_REG__OCTWORD_OFFSET__SHIFT     0x00000000

// VAP_PVS_VECTOR_DATA_REG
#define	VAP_PVS_VECTOR_DATA_REG__DATA_REGISTER__SHIFT      0x00000000

// VAP_PVS_VECTOR_DATA_REG_128
#define	VAP_PVS_VECTOR_DATA_REG_128__DATA_REGISTER__SHIFT  0x00000000

// VAP_CLIP_CNTL
#define	VAP_CLIP_CNTL__UCP_ENA_0__SHIFT                    0x00000000
#define	VAP_CLIP_CNTL__UCP_ENA_1__SHIFT                    0x00000001
#define	VAP_CLIP_CNTL__UCP_ENA_2__SHIFT                    0x00000002
#define	VAP_CLIP_CNTL__UCP_ENA_3__SHIFT                    0x00000003
#define	VAP_CLIP_CNTL__UCP_ENA_4__SHIFT                    0x00000004
#define	VAP_CLIP_CNTL__UCP_ENA_5__SHIFT                    0x00000005
#define	VAP_CLIP_CNTL__PS_UCP_MODE__SHIFT                  0x0000000e
#define	VAP_CLIP_CNTL__CLIP_DISABLE__SHIFT                 0x00000010
#define	VAP_CLIP_CNTL__UCP_CULL_ONLY_ENA__SHIFT            0x00000011
#define	VAP_CLIP_CNTL__BOUNDARY_EDGE_FLAG_ENA__SHIFT       0x00000012

// VAP_GB_VERT_CLIP_ADJ
#define	VAP_GB_VERT_CLIP_ADJ__DATA_REGISTER__SHIFT         0x00000000

// VAP_GB_VERT_DISC_ADJ
#define	VAP_GB_VERT_DISC_ADJ__DATA_REGISTER__SHIFT         0x00000000

// VAP_GB_HORZ_CLIP_ADJ
#define	VAP_GB_HORZ_CLIP_ADJ__DATA_REGISTER__SHIFT         0x00000000

// VAP_GB_HORZ_DISC_ADJ
#define	VAP_GB_HORZ_DISC_ADJ__DATA_REGISTER__SHIFT         0x00000000

// VAP_PVS_FLOW_CNTL_ADDRS_0
#define	VAP_PVS_FLOW_CNTL_ADDRS_0__PVS_FC_ACT_ADRS_0__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_0__PVS_FC_LOOP_CNT_JMP_INST_0__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_0__PVS_FC_LAST_INST_0__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_0__PVS_FC_RTN_INST_0__SHIFT 0x00000018

// VAP_PVS_FLOW_CNTL_ADDRS_1
#define	VAP_PVS_FLOW_CNTL_ADDRS_1__PVS_FC_ACT_ADRS_1__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_1__PVS_FC_LOOP_CNT_JMP_INST_1__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_1__PVS_FC_LAST_INST_1__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_1__PVS_FC_RTN_INST_1__SHIFT 0x00000018

// VAP_PVS_FLOW_CNTL_ADDRS_2
#define	VAP_PVS_FLOW_CNTL_ADDRS_2__PVS_FC_ACT_ADRS_2__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_2__PVS_FC_LOOP_CNT_JMP_INST_2__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_2__PVS_FC_LAST_INST_2__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_2__PVS_FC_RTN_INST_2__SHIFT 0x00000018

// VAP_PVS_FLOW_CNTL_ADDRS_3
#define	VAP_PVS_FLOW_CNTL_ADDRS_3__PVS_FC_ACT_ADRS_3__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_3__PVS_FC_LOOP_CNT_JMP_INST_3__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_3__PVS_FC_LAST_INST_3__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_3__PVS_FC_RTN_INST_3__SHIFT 0x00000018

// VAP_PVS_FLOW_CNTL_ADDRS_4
#define	VAP_PVS_FLOW_CNTL_ADDRS_4__PVS_FC_ACT_ADRS_4__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_4__PVS_FC_LOOP_CNT_JMP_INST_4__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_4__PVS_FC_LAST_INST_4__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_4__PVS_FC_RTN_INST_4__SHIFT 0x00000018

// VAP_PVS_FLOW_CNTL_ADDRS_5
#define	VAP_PVS_FLOW_CNTL_ADDRS_5__PVS_FC_ACT_ADRS_5__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_5__PVS_FC_LOOP_CNT_JMP_INST_5__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_5__PVS_FC_LAST_INST_5__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_5__PVS_FC_RTN_INST_5__SHIFT 0x00000018

// VAP_PVS_FLOW_CNTL_ADDRS_6
#define	VAP_PVS_FLOW_CNTL_ADDRS_6__PVS_FC_ACT_ADRS_6__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_6__PVS_FC_LOOP_CNT_JMP_INST_6__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_6__PVS_FC_LAST_INST_6__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_6__PVS_FC_RTN_INST_6__SHIFT 0x00000018

// VAP_PVS_FLOW_CNTL_ADDRS_7
#define	VAP_PVS_FLOW_CNTL_ADDRS_7__PVS_FC_ACT_ADRS_7__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_7__PVS_FC_LOOP_CNT_JMP_INST_7__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_7__PVS_FC_LAST_INST_7__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_7__PVS_FC_RTN_INST_7__SHIFT 0x00000018

// VAP_PVS_FLOW_CNTL_ADDRS_8
#define	VAP_PVS_FLOW_CNTL_ADDRS_8__PVS_FC_ACT_ADRS_8__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_8__PVS_FC_LOOP_CNT_JMP_INST_8__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_8__PVS_FC_LAST_INST_8__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_8__PVS_FC_RTN_INST_8__SHIFT 0x00000018

// VAP_PVS_FLOW_CNTL_ADDRS_9
#define	VAP_PVS_FLOW_CNTL_ADDRS_9__PVS_FC_ACT_ADRS_9__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_9__PVS_FC_LOOP_CNT_JMP_INST_9__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_9__PVS_FC_LAST_INST_9__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_9__PVS_FC_RTN_INST_9__SHIFT 0x00000018

// VAP_PVS_FLOW_CNTL_ADDRS_10
#define	VAP_PVS_FLOW_CNTL_ADDRS_10__PVS_FC_ACT_ADRS_10__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_10__PVS_FC_LOOP_CNT_JMP_INST_10__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_10__PVS_FC_LAST_INST_10__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_10__PVS_FC_RTN_INST_10__SHIFT 0x00000018

// VAP_PVS_FLOW_CNTL_ADDRS_11
#define	VAP_PVS_FLOW_CNTL_ADDRS_11__PVS_FC_ACT_ADRS_11__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_11__PVS_FC_LOOP_CNT_JMP_INST_11__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_11__PVS_FC_LAST_INST_11__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_11__PVS_FC_RTN_INST_11__SHIFT 0x00000018

// VAP_PVS_FLOW_CNTL_ADDRS_12
#define	VAP_PVS_FLOW_CNTL_ADDRS_12__PVS_FC_ACT_ADRS_12__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_12__PVS_FC_LOOP_CNT_JMP_INST_12__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_12__PVS_FC_LAST_INST_12__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_12__PVS_FC_RTN_INST_12__SHIFT 0x00000018

// VAP_PVS_FLOW_CNTL_ADDRS_13
#define	VAP_PVS_FLOW_CNTL_ADDRS_13__PVS_FC_ACT_ADRS_13__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_13__PVS_FC_LOOP_CNT_JMP_INST_13__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_13__PVS_FC_LAST_INST_13__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_13__PVS_FC_RTN_INST_13__SHIFT 0x00000018

// VAP_PVS_FLOW_CNTL_ADDRS_14
#define	VAP_PVS_FLOW_CNTL_ADDRS_14__PVS_FC_ACT_ADRS_14__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_14__PVS_FC_LOOP_CNT_JMP_INST_14__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_14__PVS_FC_LAST_INST_14__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_14__PVS_FC_RTN_INST_14__SHIFT 0x00000018

// VAP_PVS_FLOW_CNTL_ADDRS_15
#define	VAP_PVS_FLOW_CNTL_ADDRS_15__PVS_FC_ACT_ADRS_15__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_ADDRS_15__PVS_FC_LOOP_CNT_JMP_INST_15__SHIFT 0x00000008
#define	VAP_PVS_FLOW_CNTL_ADDRS_15__PVS_FC_LAST_INST_15__SHIFT 0x00000010
#define	VAP_PVS_FLOW_CNTL_ADDRS_15__PVS_FC_RTN_INST_15__SHIFT 0x00000018

// VAP_PVS_DEBUG_0
#define	VAP_PVS_DEBUG_0__SPARE__SHIFT                      0x00000000
#define	VAP_PVS_DEBUG_0__DIS_CLIP_ERR_DETECT__SHIFT        0x00000005

// VAP_PVS_STATE_FLUSH_REG
#define	VAP_PVS_STATE_FLUSH_REG__DATA_REGISTER__SHIFT      0x00000000

// VAP_PVS_VTX_TIMEOUT_REG
#define	VAP_PVS_VTX_TIMEOUT_REG__CLK_COUNT__SHIFT          0x00000000

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_0
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_0__PVS_FC_LOOP_INIT_VAL_0__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_0__PVS_FC_LOOP_STEP_VAL_0__SHIFT 0x00000008

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_1
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_1__PVS_FC_LOOP_INIT_VAL_1__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_1__PVS_FC_LOOP_STEP_VAL_1__SHIFT 0x00000008

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_2
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_2__PVS_FC_LOOP_INIT_VAL_2__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_2__PVS_FC_LOOP_STEP_VAL_2__SHIFT 0x00000008

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_3
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_3__PVS_FC_LOOP_INIT_VAL_3__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_3__PVS_FC_LOOP_STEP_VAL_3__SHIFT 0x00000008

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_4
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_4__PVS_FC_LOOP_INIT_VAL_4__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_4__PVS_FC_LOOP_STEP_VAL_4__SHIFT 0x00000008

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_5
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_5__PVS_FC_LOOP_INIT_VAL_5__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_5__PVS_FC_LOOP_STEP_VAL_5__SHIFT 0x00000008

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_6
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_6__PVS_FC_LOOP_INIT_VAL_6__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_6__PVS_FC_LOOP_STEP_VAL_6__SHIFT 0x00000008

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_7
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_7__PVS_FC_LOOP_INIT_VAL_7__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_7__PVS_FC_LOOP_STEP_VAL_7__SHIFT 0x00000008

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_8
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_8__PVS_FC_LOOP_INIT_VAL_8__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_8__PVS_FC_LOOP_STEP_VAL_8__SHIFT 0x00000008

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_9
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_9__PVS_FC_LOOP_INIT_VAL_9__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_9__PVS_FC_LOOP_STEP_VAL_9__SHIFT 0x00000008

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_10
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_10__PVS_FC_LOOP_INIT_VAL_10__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_10__PVS_FC_LOOP_STEP_VAL_10__SHIFT 0x00000008

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_11
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_11__PVS_FC_LOOP_INIT_VAL_11__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_11__PVS_FC_LOOP_STEP_VAL_11__SHIFT 0x00000008

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_12
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_12__PVS_FC_LOOP_INIT_VAL_12__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_12__PVS_FC_LOOP_STEP_VAL_12__SHIFT 0x00000008

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_13
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_13__PVS_FC_LOOP_INIT_VAL_13__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_13__PVS_FC_LOOP_STEP_VAL_13__SHIFT 0x00000008

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_14
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_14__PVS_FC_LOOP_INIT_VAL_14__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_14__PVS_FC_LOOP_STEP_VAL_14__SHIFT 0x00000008

// VAP_PVS_FLOW_CNTL_LOOP_INDEX_15
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_15__PVS_FC_LOOP_INIT_VAL_15__SHIFT 0x00000000
#define	VAP_PVS_FLOW_CNTL_LOOP_INDEX_15__PVS_FC_LOOP_STEP_VAL_15__SHIFT 0x00000008

// VAP_PVS_CODE_CNTL_0
#define	VAP_PVS_CODE_CNTL_0__PVS_FIRST_INST__SHIFT         0x00000000
#define	VAP_PVS_CODE_CNTL_0__PVS_XYZW_VALID_INST__SHIFT    0x0000000a
#define	VAP_PVS_CODE_CNTL_0__PVS_LAST_INST__SHIFT          0x00000014

// VAP_PVS_CONST_CNTL
#define	VAP_PVS_CONST_CNTL__PVS_CONST_BASE_OFFSET__SHIFT   0x00000000
#define	VAP_PVS_CONST_CNTL__PVS_MAX_CONST_ADDR__SHIFT      0x00000010

// VAP_PVS_CODE_CNTL_1
#define	VAP_PVS_CODE_CNTL_1__PVS_LAST_VTX_SRC_INST__SHIFT  0x00000000

// VAP_PVS_FLOW_CNTL_OPC
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_0__SHIFT         0x00000000
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_1__SHIFT         0x00000002
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_2__SHIFT         0x00000004
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_3__SHIFT         0x00000006
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_4__SHIFT         0x00000008
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_5__SHIFT         0x0000000a
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_6__SHIFT         0x0000000c
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_7__SHIFT         0x0000000e
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_8__SHIFT         0x00000010
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_9__SHIFT         0x00000012
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_10__SHIFT        0x00000014
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_11__SHIFT        0x00000016
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_12__SHIFT        0x00000018
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_13__SHIFT        0x0000001a
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_14__SHIFT        0x0000001c
#define	VAP_PVS_FLOW_CNTL_OPC__PVS_FC_OPC_15__SHIFT        0x0000001e

// VAP_VTX_ST_POS_0_X_4
#define	VAP_VTX_ST_POS_0_X_4__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_POS_0_Y_4
#define	VAP_VTX_ST_POS_0_Y_4__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_POS_0_Z_4
#define	VAP_VTX_ST_POS_0_Z_4__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_POS_0_W_4
#define	VAP_VTX_ST_POS_0_W_4__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_NORM_0_X
#define	VAP_VTX_ST_NORM_0_X__DATA_REGISTER__SHIFT          0x00000000

// VAP_VTX_ST_NORM_0_Y
#define	VAP_VTX_ST_NORM_0_Y__DATA_REGISTER__SHIFT          0x00000000

// VAP_VTX_ST_NORM_0_Z
#define	VAP_VTX_ST_NORM_0_Z__DATA_REGISTER__SHIFT          0x00000000

// VAP_VTX_ST_PVMS
#define	VAP_VTX_ST_PVMS__DATA_REGISTER__SHIFT              0x00000000

// VAP_VTX_ST_CLR_0_R
#define	VAP_VTX_ST_CLR_0_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_0_G
#define	VAP_VTX_ST_CLR_0_G__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_0_B
#define	VAP_VTX_ST_CLR_0_B__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_0_A
#define	VAP_VTX_ST_CLR_0_A__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_1_R
#define	VAP_VTX_ST_CLR_1_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_1_G
#define	VAP_VTX_ST_CLR_1_G__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_1_B
#define	VAP_VTX_ST_CLR_1_B__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_1_A
#define	VAP_VTX_ST_CLR_1_A__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_2_R
#define	VAP_VTX_ST_CLR_2_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_2_G
#define	VAP_VTX_ST_CLR_2_G__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_2_B
#define	VAP_VTX_ST_CLR_2_B__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_2_A
#define	VAP_VTX_ST_CLR_2_A__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_3_R
#define	VAP_VTX_ST_CLR_3_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_3_G
#define	VAP_VTX_ST_CLR_3_G__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_3_B
#define	VAP_VTX_ST_CLR_3_B__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_3_A
#define	VAP_VTX_ST_CLR_3_A__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_4_R
#define	VAP_VTX_ST_CLR_4_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_4_G
#define	VAP_VTX_ST_CLR_4_G__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_4_B
#define	VAP_VTX_ST_CLR_4_B__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_4_A
#define	VAP_VTX_ST_CLR_4_A__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_5_R
#define	VAP_VTX_ST_CLR_5_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_5_G
#define	VAP_VTX_ST_CLR_5_G__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_5_B
#define	VAP_VTX_ST_CLR_5_B__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_5_A
#define	VAP_VTX_ST_CLR_5_A__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_6_R
#define	VAP_VTX_ST_CLR_6_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_6_G
#define	VAP_VTX_ST_CLR_6_G__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_6_B
#define	VAP_VTX_ST_CLR_6_B__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_6_A
#define	VAP_VTX_ST_CLR_6_A__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_7_R
#define	VAP_VTX_ST_CLR_7_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_7_G
#define	VAP_VTX_ST_CLR_7_G__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_7_B
#define	VAP_VTX_ST_CLR_7_B__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_CLR_7_A
#define	VAP_VTX_ST_CLR_7_A__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_0_S
#define	VAP_VTX_ST_TEX_0_S__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_0_T
#define	VAP_VTX_ST_TEX_0_T__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_0_R
#define	VAP_VTX_ST_TEX_0_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_0_Q
#define	VAP_VTX_ST_TEX_0_Q__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_1_S
#define	VAP_VTX_ST_TEX_1_S__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_1_T
#define	VAP_VTX_ST_TEX_1_T__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_1_R
#define	VAP_VTX_ST_TEX_1_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_1_Q
#define	VAP_VTX_ST_TEX_1_Q__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_2_S
#define	VAP_VTX_ST_TEX_2_S__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_2_T
#define	VAP_VTX_ST_TEX_2_T__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_2_R
#define	VAP_VTX_ST_TEX_2_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_2_Q
#define	VAP_VTX_ST_TEX_2_Q__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_3_S
#define	VAP_VTX_ST_TEX_3_S__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_3_T
#define	VAP_VTX_ST_TEX_3_T__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_3_R
#define	VAP_VTX_ST_TEX_3_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_3_Q
#define	VAP_VTX_ST_TEX_3_Q__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_4_S
#define	VAP_VTX_ST_TEX_4_S__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_4_T
#define	VAP_VTX_ST_TEX_4_T__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_4_R
#define	VAP_VTX_ST_TEX_4_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_4_Q
#define	VAP_VTX_ST_TEX_4_Q__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_5_S
#define	VAP_VTX_ST_TEX_5_S__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_5_T
#define	VAP_VTX_ST_TEX_5_T__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_5_R
#define	VAP_VTX_ST_TEX_5_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_5_Q
#define	VAP_VTX_ST_TEX_5_Q__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_6_S
#define	VAP_VTX_ST_TEX_6_S__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_6_T
#define	VAP_VTX_ST_TEX_6_T__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_6_R
#define	VAP_VTX_ST_TEX_6_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_6_Q
#define	VAP_VTX_ST_TEX_6_Q__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_7_S
#define	VAP_VTX_ST_TEX_7_S__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_7_T
#define	VAP_VTX_ST_TEX_7_T__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_7_R
#define	VAP_VTX_ST_TEX_7_R__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_TEX_7_Q
#define	VAP_VTX_ST_TEX_7_Q__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_PNT_SPRT_SZ
#define	VAP_VTX_ST_PNT_SPRT_SZ__DATA_REGISTER__SHIFT       0x00000000

// VAP_VTX_ST_DISC_FOG
#define	VAP_VTX_ST_DISC_FOG__DATA_REGISTER__SHIFT          0x00000000

// VAP_VTX_ST_SHININESS_0
#define	VAP_VTX_ST_SHININESS_0__DATA_REGISTER__SHIFT       0x00000000

// VAP_VTX_ST_SHININESS_1
#define	VAP_VTX_ST_SHININESS_1__DATA_REGISTER__SHIFT       0x00000000

// VAP_VTX_ST_BLND_WT_0
#define	VAP_VTX_ST_BLND_WT_0__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_BLND_WT_1
#define	VAP_VTX_ST_BLND_WT_1__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_BLND_WT_2
#define	VAP_VTX_ST_BLND_WT_2__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_BLND_WT_3
#define	VAP_VTX_ST_BLND_WT_3__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_POS_1_X
#define	VAP_VTX_ST_POS_1_X__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_POS_1_Y
#define	VAP_VTX_ST_POS_1_Y__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_POS_1_Z
#define	VAP_VTX_ST_POS_1_Z__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_POS_1_W
#define	VAP_VTX_ST_POS_1_W__DATA_REGISTER__SHIFT           0x00000000

// VAP_VTX_ST_NORM_1_X
#define	VAP_VTX_ST_NORM_1_X__DATA_REGISTER__SHIFT          0x00000000

// VAP_VTX_ST_NORM_1_Y
#define	VAP_VTX_ST_NORM_1_Y__DATA_REGISTER__SHIFT          0x00000000

// VAP_VTX_ST_NORM_1_Z
#define	VAP_VTX_ST_NORM_1_Z__DATA_REGISTER__SHIFT          0x00000000

// VAP_VTX_ST_EDGE_FLAGS
#define	VAP_VTX_ST_EDGE_FLAGS__DATA_REGISTER__SHIFT        0x00000000

// VAP_VTX_ST_USR_CLR_R
#define	VAP_VTX_ST_USR_CLR_R__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_USR_CLR_G
#define	VAP_VTX_ST_USR_CLR_G__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_USR_CLR_B
#define	VAP_VTX_ST_USR_CLR_B__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_USR_CLR_A
#define	VAP_VTX_ST_USR_CLR_A__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_CLR_0_PKD
#define	VAP_VTX_ST_CLR_0_PKD__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_CLR_1_PKD
#define	VAP_VTX_ST_CLR_1_PKD__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_CLR_2_PKD
#define	VAP_VTX_ST_CLR_2_PKD__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_CLR_3_PKD
#define	VAP_VTX_ST_CLR_3_PKD__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_CLR_4_PKD
#define	VAP_VTX_ST_CLR_4_PKD__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_CLR_5_PKD
#define	VAP_VTX_ST_CLR_5_PKD__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_CLR_6_PKD
#define	VAP_VTX_ST_CLR_6_PKD__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_CLR_7_PKD
#define	VAP_VTX_ST_CLR_7_PKD__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_POS_0_X_2
#define	VAP_VTX_ST_POS_0_X_2__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_POS_0_Y_2
#define	VAP_VTX_ST_POS_0_Y_2__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_NORM_0_PKD
#define	VAP_VTX_ST_NORM_0_PKD__DATA_REGISTER__SHIFT        0x00000000

// VAP_VTX_ST_USR_CLR_PKD
#define	VAP_VTX_ST_USR_CLR_PKD__DATA_REGISTER__SHIFT       0x00000000

// VAP_VTX_ST_POS_0_X_3
#define	VAP_VTX_ST_POS_0_X_3__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_POS_0_Y_3
#define	VAP_VTX_ST_POS_0_Y_3__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_POS_0_Z_3
#define	VAP_VTX_ST_POS_0_Z_3__DATA_REGISTER__SHIFT         0x00000000

// VAP_VTX_ST_END_OF_PKT
#define	VAP_VTX_ST_END_OF_PKT__DATA_REGISTER__SHIFT        0x00000000

// MC_CNTL
#define	MC_CNTL__MEM_NUM_CHANNELS__SHIFT                   0x00000000
#define	MC_CNTL__MEM_USE_CD_CH_ONLY__SHIFT                 0x00000002
#define	MC_CNTL__MEM_ADDR_MAP_RANK__SHIFT                  0x00000003
#define	MC_CNTL__MEM_ADDR_MAP_ROWS__SHIFT                  0x00000004
#define	MC_CNTL__MEM_ADDR_MAP_COLS__SHIFT                  0x00000006

// MC_TIMING_CNTL
#define	MC_TIMING_CNTL__MEM_TRCDRD__SHIFT                  0x00000000
#define	MC_TIMING_CNTL__MEM_TRCDWR__SHIFT                  0x00000004
#define	MC_TIMING_CNTL__MEM_TRP__SHIFT                     0x00000008
#define	MC_TIMING_CNTL__MEM_TRAS__SHIFT                    0x0000000b
#define	MC_TIMING_CNTL__MEM_TRRD__SHIFT                    0x0000000f
#define	MC_TIMING_CNTL__MEM_TR2W__SHIFT                    0x00000012
#define	MC_TIMING_CNTL__MEM_TWR__SHIFT                     0x00000014
#define	MC_TIMING_CNTL__MEM_TW2R__SHIFT                    0x00000018
#define	MC_TIMING_CNTL__MEM_TW2R_SAME_BANK__SHIFT          0x0000001b
#define	MC_TIMING_CNTL__MEM_TR2R__SHIFT                    0x0000001c

// MC_AGP_LOCATION
#define	MC_AGP_LOCATION__MC_AGP_START__SHIFT               0x00000000
#define	MC_AGP_LOCATION__MC_AGP_TOP__SHIFT                 0x00000010

// MC_REFRESH_CNTL
#define	MC_REFRESH_CNTL__MEM_REFRESH_RATE__SHIFT           0x00000000
#define	MC_REFRESH_CNTL__MEM_REFRESH_DIS__SHIFT            0x00000008
#define	MC_REFRESH_CNTL__MEM_DYNAMIC_CKE__SHIFT            0x00000009
#define	MC_REFRESH_CNTL__MEM_TRFC__SHIFT                   0x0000000c

// MC_IOPAD_CNTL
#define	MC_IOPAD_CNTL__MEM_CLKA0_ENABLE__SHIFT             0x00000000
#define	MC_IOPAD_CNTL__MEM_CLKA0b_ENABLE__SHIFT            0x00000001
#define	MC_IOPAD_CNTL__MEM_CLKA1_ENABLE__SHIFT             0x00000002
#define	MC_IOPAD_CNTL__MEM_CLKA1b_ENABLE__SHIFT            0x00000003
#define	MC_IOPAD_CNTL__MEM_CLKAFB_ENABLE__SHIFT            0x00000004
#define	MC_IOPAD_CNTL__DLL_FB_SLCT_CKA__SHIFT              0x00000005
#define	MC_IOPAD_CNTL__MEM_CLKB0_ENABLE__SHIFT             0x00000007
#define	MC_IOPAD_CNTL__MEM_CLKB0b_ENABLE__SHIFT            0x00000008
#define	MC_IOPAD_CNTL__MEM_CLKB1_ENABLE__SHIFT             0x00000009
#define	MC_IOPAD_CNTL__MEM_CLKB1b_ENABLE__SHIFT            0x0000000a
#define	MC_IOPAD_CNTL__MEM_CLKBFB_ENABLE__SHIFT            0x0000000b
#define	MC_IOPAD_CNTL__DLL_FB_SLCT_CKB__SHIFT              0x0000000c
#define	MC_IOPAD_CNTL__MEM_CLKC0_ENABLE__SHIFT             0x0000000e
#define	MC_IOPAD_CNTL__MEM_CLKC0b_ENABLE__SHIFT            0x0000000f
#define	MC_IOPAD_CNTL__MEM_CLKC1_ENABLE__SHIFT             0x00000010
#define	MC_IOPAD_CNTL__MEM_CLKC1b_ENABLE__SHIFT            0x00000011
#define	MC_IOPAD_CNTL__MEM_CLKCFB_ENABLE__SHIFT            0x00000012
#define	MC_IOPAD_CNTL__DLL_FB_SLCT_CKC__SHIFT              0x00000013
#define	MC_IOPAD_CNTL__MEM_CLKD0_ENABLE__SHIFT             0x00000015
#define	MC_IOPAD_CNTL__MEM_CLKD0b_ENABLE__SHIFT            0x00000016
#define	MC_IOPAD_CNTL__MEM_CLKD1_ENABLE__SHIFT             0x00000017
#define	MC_IOPAD_CNTL__MEM_CLKD1b_ENABLE__SHIFT            0x00000018
#define	MC_IOPAD_CNTL__MEM_CLKDFB_ENABLE__SHIFT            0x00000019
#define	MC_IOPAD_CNTL__DLL_FB_SLCT_CKD__SHIFT              0x0000001a

// MC_INIT_MISC_LAT_TIMER
#define	MC_INIT_MISC_LAT_TIMER__MC_CPR_INIT_LAT__SHIFT     0x00000000
#define	MC_INIT_MISC_LAT_TIMER__MC_VF_INIT_LAT__SHIFT      0x00000004
#define	MC_INIT_MISC_LAT_TIMER__MC_DISP0R_INIT_LAT__SHIFT  0x00000008
#define	MC_INIT_MISC_LAT_TIMER__MC_DISP1R_INIT_LAT__SHIFT  0x0000000c
#define	MC_INIT_MISC_LAT_TIMER__MC_FIXED_INIT_LAT__SHIFT   0x00000010
#define	MC_INIT_MISC_LAT_TIMER__MC_E2R_INIT_LAT__SHIFT     0x00000014
#define	MC_INIT_MISC_LAT_TIMER__SAME_PAGE_PRIO__SHIFT      0x00000018
#define	MC_INIT_MISC_LAT_TIMER__MC_GLOBW_INIT_LAT__SHIFT   0x0000001c

// MC_INIT_GFX_LAT_TIMER
#define	MC_INIT_GFX_LAT_TIMER__MC_G3D0R_INIT_LAT__SHIFT    0x00000000
#define	MC_INIT_GFX_LAT_TIMER__MC_G3D1R_INIT_LAT__SHIFT    0x00000004
#define	MC_INIT_GFX_LAT_TIMER__MC_G3D2R_INIT_LAT__SHIFT    0x00000008
#define	MC_INIT_GFX_LAT_TIMER__MC_G3D3R_INIT_LAT__SHIFT    0x0000000c
#define	MC_INIT_GFX_LAT_TIMER__MC_TX0R_INIT_LAT__SHIFT     0x00000010
#define	MC_INIT_GFX_LAT_TIMER__MC_TX1R_INIT_LAT__SHIFT     0x00000014
#define	MC_INIT_GFX_LAT_TIMER__MC_GLOBR_INIT_LAT__SHIFT    0x00000018
#define	MC_INIT_GFX_LAT_TIMER__MC_GLOBW_FULL_LAT__SHIFT    0x0000001c

// MC_SDRAM_MODE_REG
#define	MC_SDRAM_MODE_REG__MEM_MODE_REG__SHIFT             0x00000000
#define	MC_SDRAM_MODE_REG__MEM_WR_LATENCY__SHIFT           0x00000010
#define	MC_SDRAM_MODE_REG__MEM_CAS_LATENCY__SHIFT          0x00000014
#define	MC_SDRAM_MODE_REG__MEM_CMD_LATENCY__SHIFT          0x00000017
#define	MC_SDRAM_MODE_REG__MEM_STR_LATENCY__SHIFT          0x00000018
#define	MC_SDRAM_MODE_REG__MC_INIT_COMPLETE__SHIFT         0x0000001c
#define	MC_SDRAM_MODE_REG__MEM_DDR_DLL__SHIFT              0x0000001d
#define	MC_SDRAM_MODE_REG__MEM_ELPIDA_TYPE__SHIFT          0x0000001e
#define	MC_SDRAM_MODE_REG__MEM_SDRAM_RESET__SHIFT          0x0000001f

// AGP_BASE
#define	AGP_BASE__AGP_BASE_ADDR__SHIFT                     0x00000000

// MC_READ_CNTL_AB
#define	MC_READ_CNTL_AB__MEM_RBS_POSITION_A__SHIFT         0x00000000
#define	MC_READ_CNTL_AB__MEM_STR_SEL_A__SHIFT              0x00000003
#define	MC_READ_CNTL_AB__MEM_ERST_POSITION_A__SHIFT        0x00000004
#define	MC_READ_CNTL_AB__MEM_ERST_EXTEND_A__SHIFT          0x00000007
#define	MC_READ_CNTL_AB__MEM_QSREC_POSITION_A__SHIFT       0x00000008
#define	MC_READ_CNTL_AB__MEM_QSREC_EXTEND_A__SHIFT         0x0000000b
#define	MC_READ_CNTL_AB__MEM_ERST_SYNC_A__SHIFT            0x0000000c
#define	MC_READ_CNTL_AB__MEM_QSREC_SYNC_A__SHIFT           0x0000000d
#define	MC_READ_CNTL_AB__MEM_RBS_POSITION_B__SHIFT         0x00000010
#define	MC_READ_CNTL_AB__MEM_STR_SEL_B__SHIFT              0x00000013
#define	MC_READ_CNTL_AB__MEM_ERST_POSITION_B__SHIFT        0x00000014
#define	MC_READ_CNTL_AB__MEM_ERST_EXTEND_B__SHIFT          0x00000017
#define	MC_READ_CNTL_AB__MEM_QSREC_POSITION_B__SHIFT       0x00000018
#define	MC_READ_CNTL_AB__MEM_QSREC_EXTEND_B__SHIFT         0x0000001b
#define	MC_READ_CNTL_AB__MEM_ERST_SYNC_B__SHIFT            0x0000001c
#define	MC_READ_CNTL_AB__MEM_QSREC_SYNC_B__SHIFT           0x0000001d

// MC_DEBUG
#define	MC_DEBUG__RB_WATER_GFX__SHIFT                      0x00000000
#define	MC_DEBUG__RB_WATER_CP__SHIFT                       0x00000005
#define	MC_DEBUG__RB_WATER_GLB__SHIFT                      0x0000000a
#define	MC_DEBUG__EN_AIC_IDLE_DET_R3__SHIFT                0x0000000f
#define	MC_DEBUG__MEM_MC_BLACKOUT_R3__SHIFT                0x00000010
#define	MC_DEBUG__MEM_TRD__SHIFT                           0x00000011
#define	MC_DEBUG__CH_WATER_TAG__SHIFT                      0x00000014
#define	MC_DEBUG__MEM_ERST_DIS_A__SHIFT                    0x00000018
#define	MC_DEBUG__MEM_ERST_DIS_B__SHIFT                    0x0000001a
#define	MC_DEBUG__MEM_ERST_DIS_C__SHIFT                    0x0000001c
#define	MC_DEBUG__MEM_ERST_DIS_D__SHIFT                    0x0000001e

// MC_STATUS
#define	MC_STATUS__MEM_PWRUP_COMPL_A__SHIFT                0x00000000
#define	MC_STATUS__MEM_PWRUP_COMPL_B__SHIFT                0x00000001
#define	MC_STATUS__MEM_PWRUP_COMPL_C__SHIFT                0x00000002
#define	MC_STATUS__MEM_PWRUP_COMPL_D__SHIFT                0x00000003
#define	MC_STATUS__MC_IDLE_R3__SHIFT                       0x00000004
#define	MC_STATUS__IMP_CAL_COUNT__SHIFT                    0x0000000c

// MC_IMP_STATUS
#define	MC_IMP_STATUS__IMP_N_VALUE_R_BACK__SHIFT           0x00000000
#define	MC_IMP_STATUS__IMP_P_VALUE_R_BACK__SHIFT           0x00000004
#define	MC_IMP_STATUS__IMP_N_VALUE_A_R_BACK__SHIFT         0x00000008
#define	MC_IMP_STATUS__IMP_P_VALUE_A_R_BACK__SHIFT         0x0000000c
#define	MC_IMP_STATUS__IMP_N_VALUE_CK_R_BACK__SHIFT        0x00000010
#define	MC_IMP_STATUS__IMP_P_VALUE_CK_R_BACK__SHIFT        0x00000014
#define	MC_IMP_STATUS__IMP_N_VALUE_DQS_R_BACK__SHIFT       0x00000018
#define	MC_IMP_STATUS__IMP_P_VALUE_DQS_R_BACK__SHIFT       0x0000001c

// MC_CHP_IO_OE_CNTL_AB
#define	MC_CHP_IO_OE_CNTL_AB__DQ_OE_POSITION_A__SHIFT      0x00000000
#define	MC_CHP_IO_OE_CNTL_AB__QS_OE_POSITION_A__SHIFT      0x00000002
#define	MC_CHP_IO_OE_CNTL_AB__DQ_OE_EXTEND_A__SHIFT        0x00000004
#define	MC_CHP_IO_OE_CNTL_AB__QS_OE_EXTEND_A__SHIFT        0x00000005
#define	MC_CHP_IO_OE_CNTL_AB__DQ_OE_ADVANCE_A__SHIFT       0x00000006
#define	MC_CHP_IO_OE_CNTL_AB__QS_OE_ADVANCE_A__SHIFT       0x00000007
#define	MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_A0__SHIFT    0x00000008
#define	MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_A1__SHIFT    0x00000009
#define	MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_A2__SHIFT    0x0000000a
#define	MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_A3__SHIFT    0x0000000b
#define	MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_CMD_A__SHIFT    0x0000000c
#define	MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_DATA_A__SHIFT   0x0000000d
#define	MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_STR_A__SHIFT    0x0000000e
#define	MC_CHP_IO_OE_CNTL_AB__MEM_PM_SDRAM_TRI_EN__SHIFT   0x0000000f
#define	MC_CHP_IO_OE_CNTL_AB__DQ_OE_POSITION_B__SHIFT      0x00000010
#define	MC_CHP_IO_OE_CNTL_AB__QS_OE_POSITION_B__SHIFT      0x00000012
#define	MC_CHP_IO_OE_CNTL_AB__DQ_OE_EXTEND_B__SHIFT        0x00000014
#define	MC_CHP_IO_OE_CNTL_AB__QS_OE_EXTEND_B__SHIFT        0x00000015
#define	MC_CHP_IO_OE_CNTL_AB__DQ_OE_ADVANCE_B__SHIFT       0x00000016
#define	MC_CHP_IO_OE_CNTL_AB__QS_OE_ADVANCE_B__SHIFT       0x00000017
#define	MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_B0__SHIFT    0x00000018
#define	MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_B1__SHIFT    0x00000019
#define	MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_B2__SHIFT    0x0000001a
#define	MC_CHP_IO_OE_CNTL_AB__DQS_DRIVER_SLCT_B3__SHIFT    0x0000001b
#define	MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_CMD_B__SHIFT    0x0000001c
#define	MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_DATA_B__SHIFT   0x0000001d
#define	MC_CHP_IO_OE_CNTL_AB__MEM_FALL_OUT_STR_B__SHIFT    0x0000001e
#define	MC_CHP_IO_OE_CNTL_AB__MEM_IO_TRISTATE__SHIFT       0x0000001f

// AGP_BASE_2
#define	AGP_BASE_2__AGP_BASE_ADDR_2__SHIFT                 0x00000000

// MC_IND_INDEX
#define	MC_IND_INDEX__MC_IND_ADDR_R3__SHIFT                0x00000000
#define	MC_IND_INDEX__MC_IND_WR_EN__SHIFT                  0x00000008

// MC_IND_DATA
#define	MC_IND_DATA__MC_IND_DATA__SHIFT                    0x00000000

// MC_PERF_CNTL
#define	MC_PERF_CNTL__MONITOR_PERIOD__SHIFT                0x00000000
#define	MC_PERF_CNTL__CH_A_CLK_CNT_EN__SHIFT               0x0000001d
#define	MC_PERF_CNTL__CLR_PERF__SHIFT                      0x0000001e
#define	MC_PERF_CNTL__EN_PERF__SHIFT                       0x0000001f

// MC_PERF_CNT0_SEL
#define	MC_PERF_CNT0_SEL__G3D0_READ__SHIFT                 0x00000000
#define	MC_PERF_CNT0_SEL__G3D1_READ__SHIFT                 0x00000001
#define	MC_PERF_CNT0_SEL__G3D2_READ__SHIFT                 0x00000002
#define	MC_PERF_CNT0_SEL__G3D3_READ__SHIFT                 0x00000003
#define	MC_PERF_CNT0_SEL__TX0_READ__SHIFT                  0x00000004
#define	MC_PERF_CNT0_SEL__TX1_READ__SHIFT                  0x00000005
#define	MC_PERF_CNT0_SEL__G3D0_WRITE__SHIFT                0x00000008
#define	MC_PERF_CNT0_SEL__G3D1_WRITE__SHIFT                0x00000009
#define	MC_PERF_CNT0_SEL__G3D2_WRITE__SHIFT                0x0000000a
#define	MC_PERF_CNT0_SEL__G3D3_WRITE__SHIFT                0x0000000b
#define	MC_PERF_CNT0_SEL__DISP0_READ__SHIFT                0x0000000c
#define	MC_PERF_CNT0_SEL__DISP1_READ__SHIFT                0x0000000d
#define	MC_PERF_CNT0_SEL__OV0_READ__SHIFT                  0x0000000e
#define	MC_PERF_CNT0_SEL__E2_READ__SHIFT                   0x0000000f
#define	MC_PERF_CNT0_SEL__VF_READ__SHIFT                   0x00000010
#define	MC_PERF_CNT0_SEL__CP_READ__SHIFT                   0x00000011
#define	MC_PERF_CNT0_SEL__CP_WRITE__SHIFT                  0x00000012
#define	MC_PERF_CNT0_SEL__VIP_READ__SHIFT                  0x00000013
#define	MC_PERF_CNT0_SEL__VIP_WRITE__SHIFT                 0x00000014
#define	MC_PERF_CNT0_SEL__IDCT_READ__SHIFT                 0x00000015
#define	MC_PERF_CNT0_SEL__IDCT_WRITE__SHIFT                0x00000016
#define	MC_PERF_CNT0_SEL__HDP_READ__SHIFT                  0x00000017
#define	MC_PERF_CNT0_SEL__HDP_WRITE__SHIFT                 0x00000018
#define	MC_PERF_CNT0_SEL__REGION_AGPPCI__SHIFT             0x00000019
#define	MC_PERF_CNT0_SEL__REGION_CHA__SHIFT                0x0000001a
#define	MC_PERF_CNT0_SEL__REGION_CHB__SHIFT                0x0000001b
#define	MC_PERF_CNT0_SEL__REGION_CHC__SHIFT                0x0000001c
#define	MC_PERF_CNT0_SEL__REGION_CHD__SHIFT                0x0000001d
#define	MC_PERF_CNT0_SEL__REGION_0__SHIFT                  0x0000001e
#define	MC_PERF_CNT0_SEL__REGION_1__SHIFT                  0x0000001f

// MC_PERF_CNT1_SEL
#define	MC_PERF_CNT1_SEL__G3D0_READ__SHIFT                 0x00000000
#define	MC_PERF_CNT1_SEL__G3D1_READ__SHIFT                 0x00000001
#define	MC_PERF_CNT1_SEL__G3D2_READ__SHIFT                 0x00000002
#define	MC_PERF_CNT1_SEL__G3D3_READ__SHIFT                 0x00000003
#define	MC_PERF_CNT1_SEL__TX0_READ__SHIFT                  0x00000004
#define	MC_PERF_CNT1_SEL__TX1_READ__SHIFT                  0x00000005
#define	MC_PERF_CNT1_SEL__G3D0_WRITE__SHIFT                0x00000008
#define	MC_PERF_CNT1_SEL__G3D1_WRITE__SHIFT                0x00000009
#define	MC_PERF_CNT1_SEL__G3D2_WRITE__SHIFT                0x0000000a
#define	MC_PERF_CNT1_SEL__G3D3_WRITE__SHIFT                0x0000000b
#define	MC_PERF_CNT1_SEL__DISP0_READ__SHIFT                0x0000000c
#define	MC_PERF_CNT1_SEL__DISP1_READ__SHIFT                0x0000000d
#define	MC_PERF_CNT1_SEL__OV0_READ__SHIFT                  0x0000000e
#define	MC_PERF_CNT1_SEL__E2_READ__SHIFT                   0x0000000f
#define	MC_PERF_CNT1_SEL__VF_READ__SHIFT                   0x00000010
#define	MC_PERF_CNT1_SEL__CP_READ__SHIFT                   0x00000011
#define	MC_PERF_CNT1_SEL__CP_WRITE__SHIFT                  0x00000012
#define	MC_PERF_CNT1_SEL__VIP_READ__SHIFT                  0x00000013
#define	MC_PERF_CNT1_SEL__VIP_WRITE__SHIFT                 0x00000014
#define	MC_PERF_CNT1_SEL__IDCT_READ__SHIFT                 0x00000015
#define	MC_PERF_CNT1_SEL__IDCT_WRITE__SHIFT                0x00000016
#define	MC_PERF_CNT1_SEL__HDP_READ__SHIFT                  0x00000017
#define	MC_PERF_CNT1_SEL__HDP_WRITE__SHIFT                 0x00000018
#define	MC_PERF_CNT1_SEL__REGION_AGPPCI__SHIFT             0x00000019
#define	MC_PERF_CNT1_SEL__REGION_CHA__SHIFT                0x0000001a
#define	MC_PERF_CNT1_SEL__REGION_CHB__SHIFT                0x0000001b
#define	MC_PERF_CNT1_SEL__REGION_CHC__SHIFT                0x0000001c
#define	MC_PERF_CNT1_SEL__REGION_CHD__SHIFT                0x0000001d
#define	MC_PERF_CNT1_SEL__REGION_0__SHIFT                  0x0000001e
#define	MC_PERF_CNT1_SEL__REGION_1__SHIFT                  0x0000001f

// MC_PERF_CNT2_SEL
#define	MC_PERF_CNT2_SEL__G3D0_READ__SHIFT                 0x00000000
#define	MC_PERF_CNT2_SEL__G3D1_READ__SHIFT                 0x00000001
#define	MC_PERF_CNT2_SEL__G3D2_READ__SHIFT                 0x00000002
#define	MC_PERF_CNT2_SEL__G3D3_READ__SHIFT                 0x00000003
#define	MC_PERF_CNT2_SEL__TX0_READ__SHIFT                  0x00000004
#define	MC_PERF_CNT2_SEL__TX1_READ__SHIFT                  0x00000005
#define	MC_PERF_CNT2_SEL__G3D0_WRITE__SHIFT                0x00000008
#define	MC_PERF_CNT2_SEL__G3D1_WRITE__SHIFT                0x00000009
#define	MC_PERF_CNT2_SEL__G3D2_WRITE__SHIFT                0x0000000a
#define	MC_PERF_CNT2_SEL__G3D3_WRITE__SHIFT                0x0000000b
#define	MC_PERF_CNT2_SEL__DISP0_READ__SHIFT                0x0000000c
#define	MC_PERF_CNT2_SEL__DISP1_READ__SHIFT                0x0000000d
#define	MC_PERF_CNT2_SEL__OV0_READ__SHIFT                  0x0000000e
#define	MC_PERF_CNT2_SEL__E2_READ__SHIFT                   0x0000000f
#define	MC_PERF_CNT2_SEL__VF_READ__SHIFT                   0x00000010
#define	MC_PERF_CNT2_SEL__CP_READ__SHIFT                   0x00000011
#define	MC_PERF_CNT2_SEL__CP_WRITE__SHIFT                  0x00000012
#define	MC_PERF_CNT2_SEL__VIP_READ__SHIFT                  0x00000013
#define	MC_PERF_CNT2_SEL__VIP_WRITE__SHIFT                 0x00000014
#define	MC_PERF_CNT2_SEL__IDCT_READ__SHIFT                 0x00000015
#define	MC_PERF_CNT2_SEL__IDCT_WRITE__SHIFT                0x00000016
#define	MC_PERF_CNT2_SEL__HDP_READ__SHIFT                  0x00000017
#define	MC_PERF_CNT2_SEL__HDP_WRITE__SHIFT                 0x00000018
#define	MC_PERF_CNT2_SEL__REGION_AGPPCI__SHIFT             0x00000019
#define	MC_PERF_CNT2_SEL__REGION_CHA__SHIFT                0x0000001a
#define	MC_PERF_CNT2_SEL__REGION_CHB__SHIFT                0x0000001b
#define	MC_PERF_CNT2_SEL__REGION_CHC__SHIFT                0x0000001c
#define	MC_PERF_CNT2_SEL__REGION_CHD__SHIFT                0x0000001d
#define	MC_PERF_CNT2_SEL__REGION_0__SHIFT                  0x0000001e
#define	MC_PERF_CNT2_SEL__REGION_1__SHIFT                  0x0000001f

// MC_PERF_CNT3_SEL
#define	MC_PERF_CNT3_SEL__G3D0_READ__SHIFT                 0x00000000
#define	MC_PERF_CNT3_SEL__G3D1_READ__SHIFT                 0x00000001
#define	MC_PERF_CNT3_SEL__G3D2_READ__SHIFT                 0x00000002
#define	MC_PERF_CNT3_SEL__G3D3_READ__SHIFT                 0x00000003
#define	MC_PERF_CNT3_SEL__TX0_READ__SHIFT                  0x00000004
#define	MC_PERF_CNT3_SEL__TX1_READ__SHIFT                  0x00000005
#define	MC_PERF_CNT3_SEL__G3D0_WRITE__SHIFT                0x00000008
#define	MC_PERF_CNT3_SEL__G3D1_WRITE__SHIFT                0x00000009
#define	MC_PERF_CNT3_SEL__G3D2_WRITE__SHIFT                0x0000000a
#define	MC_PERF_CNT3_SEL__G3D3_WRITE__SHIFT                0x0000000b
#define	MC_PERF_CNT3_SEL__DISP0_READ__SHIFT                0x0000000c
#define	MC_PERF_CNT3_SEL__DISP1_READ__SHIFT                0x0000000d
#define	MC_PERF_CNT3_SEL__OV0_READ__SHIFT                  0x0000000e
#define	MC_PERF_CNT3_SEL__E2_READ__SHIFT                   0x0000000f
#define	MC_PERF_CNT3_SEL__VF_READ__SHIFT                   0x00000010
#define	MC_PERF_CNT3_SEL__CP_READ__SHIFT                   0x00000011
#define	MC_PERF_CNT3_SEL__CP_WRITE__SHIFT                  0x00000012
#define	MC_PERF_CNT3_SEL__VIP_READ__SHIFT                  0x00000013
#define	MC_PERF_CNT3_SEL__VIP_WRITE__SHIFT                 0x00000014
#define	MC_PERF_CNT3_SEL__IDCT_READ__SHIFT                 0x00000015
#define	MC_PERF_CNT3_SEL__IDCT_WRITE__SHIFT                0x00000016
#define	MC_PERF_CNT3_SEL__HDP_READ__SHIFT                  0x00000017
#define	MC_PERF_CNT3_SEL__HDP_WRITE__SHIFT                 0x00000018
#define	MC_PERF_CNT3_SEL__REGION_AGPPCI__SHIFT             0x00000019
#define	MC_PERF_CNT3_SEL__REGION_CHA__SHIFT                0x0000001a
#define	MC_PERF_CNT3_SEL__REGION_CHB__SHIFT                0x0000001b
#define	MC_PERF_CNT3_SEL__REGION_CHC__SHIFT                0x0000001c
#define	MC_PERF_CNT3_SEL__REGION_CHD__SHIFT                0x0000001d
#define	MC_PERF_CNT3_SEL__REGION_0__SHIFT                  0x0000001e
#define	MC_PERF_CNT3_SEL__REGION_1__SHIFT                  0x0000001f

// MC_PERF_CNT4_SEL
#define	MC_PERF_CNT4_SEL__G3D0_READ__SHIFT                 0x00000000
#define	MC_PERF_CNT4_SEL__G3D1_READ__SHIFT                 0x00000001
#define	MC_PERF_CNT4_SEL__G3D2_READ__SHIFT                 0x00000002
#define	MC_PERF_CNT4_SEL__G3D3_READ__SHIFT                 0x00000003
#define	MC_PERF_CNT4_SEL__TX0_READ__SHIFT                  0x00000004
#define	MC_PERF_CNT4_SEL__TX1_READ__SHIFT                  0x00000005
#define	MC_PERF_CNT4_SEL__G3D0_WRITE__SHIFT                0x00000008
#define	MC_PERF_CNT4_SEL__G3D1_WRITE__SHIFT                0x00000009
#define	MC_PERF_CNT4_SEL__G3D2_WRITE__SHIFT                0x0000000a
#define	MC_PERF_CNT4_SEL__G3D3_WRITE__SHIFT                0x0000000b
#define	MC_PERF_CNT4_SEL__DISP0_READ__SHIFT                0x0000000c
#define	MC_PERF_CNT4_SEL__DISP1_READ__SHIFT                0x0000000d
#define	MC_PERF_CNT4_SEL__OV0_READ__SHIFT                  0x0000000e
#define	MC_PERF_CNT4_SEL__E2_READ__SHIFT                   0x0000000f
#define	MC_PERF_CNT4_SEL__VF_READ__SHIFT                   0x00000010
#define	MC_PERF_CNT4_SEL__CP_READ__SHIFT                   0x00000011
#define	MC_PERF_CNT4_SEL__CP_WRITE__SHIFT                  0x00000012
#define	MC_PERF_CNT4_SEL__VIP_READ__SHIFT                  0x00000013
#define	MC_PERF_CNT4_SEL__VIP_WRITE__SHIFT                 0x00000014
#define	MC_PERF_CNT4_SEL__IDCT_READ__SHIFT                 0x00000015
#define	MC_PERF_CNT4_SEL__IDCT_WRITE__SHIFT                0x00000016
#define	MC_PERF_CNT4_SEL__HDP_READ__SHIFT                  0x00000017
#define	MC_PERF_CNT4_SEL__HDP_WRITE__SHIFT                 0x00000018
#define	MC_PERF_CNT4_SEL__REGION_AGPPCI__SHIFT             0x00000019
#define	MC_PERF_CNT4_SEL__REGION_CHA__SHIFT                0x0000001a
#define	MC_PERF_CNT4_SEL__REGION_CHB__SHIFT                0x0000001b
#define	MC_PERF_CNT4_SEL__REGION_CHC__SHIFT                0x0000001c
#define	MC_PERF_CNT4_SEL__REGION_CHD__SHIFT                0x0000001d
#define	MC_PERF_CNT4_SEL__REGION_0__SHIFT                  0x0000001e
#define	MC_PERF_CNT4_SEL__REGION_1__SHIFT                  0x0000001f

// MC_PERF_CNT5_SEL
#define	MC_PERF_CNT5_SEL__G3D0_READ__SHIFT                 0x00000000
#define	MC_PERF_CNT5_SEL__G3D1_READ__SHIFT                 0x00000001
#define	MC_PERF_CNT5_SEL__G3D2_READ__SHIFT                 0x00000002
#define	MC_PERF_CNT5_SEL__G3D3_READ__SHIFT                 0x00000003
#define	MC_PERF_CNT5_SEL__TX0_READ__SHIFT                  0x00000004
#define	MC_PERF_CNT5_SEL__TX1_READ__SHIFT                  0x00000005
#define	MC_PERF_CNT5_SEL__G3D0_WRITE__SHIFT                0x00000008
#define	MC_PERF_CNT5_SEL__G3D1_WRITE__SHIFT                0x00000009
#define	MC_PERF_CNT5_SEL__G3D2_WRITE__SHIFT                0x0000000a
#define	MC_PERF_CNT5_SEL__G3D3_WRITE__SHIFT                0x0000000b
#define	MC_PERF_CNT5_SEL__DISP0_READ__SHIFT                0x0000000c
#define	MC_PERF_CNT5_SEL__DISP1_READ__SHIFT                0x0000000d
#define	MC_PERF_CNT5_SEL__OV0_READ__SHIFT                  0x0000000e
#define	MC_PERF_CNT5_SEL__E2_READ__SHIFT                   0x0000000f
#define	MC_PERF_CNT5_SEL__VF_READ__SHIFT                   0x00000010
#define	MC_PERF_CNT5_SEL__CP_READ__SHIFT                   0x00000011
#define	MC_PERF_CNT5_SEL__CP_WRITE__SHIFT                  0x00000012
#define	MC_PERF_CNT5_SEL__VIP_READ__SHIFT                  0x00000013
#define	MC_PERF_CNT5_SEL__VIP_WRITE__SHIFT                 0x00000014
#define	MC_PERF_CNT5_SEL__IDCT_READ__SHIFT                 0x00000015
#define	MC_PERF_CNT5_SEL__IDCT_WRITE__SHIFT                0x00000016
#define	MC_PERF_CNT5_SEL__HDP_READ__SHIFT                  0x00000017
#define	MC_PERF_CNT5_SEL__HDP_WRITE__SHIFT                 0x00000018
#define	MC_PERF_CNT5_SEL__REGION_AGPPCI__SHIFT             0x00000019
#define	MC_PERF_CNT5_SEL__REGION_CHA__SHIFT                0x0000001a
#define	MC_PERF_CNT5_SEL__REGION_CHB__SHIFT                0x0000001b
#define	MC_PERF_CNT5_SEL__REGION_CHC__SHIFT                0x0000001c
#define	MC_PERF_CNT5_SEL__REGION_CHD__SHIFT                0x0000001d
#define	MC_PERF_CNT5_SEL__REGION_0__SHIFT                  0x0000001e
#define	MC_PERF_CNT5_SEL__REGION_1__SHIFT                  0x0000001f

// MC_PERF_CNT6_SEL
#define	MC_PERF_CNT6_SEL__G3D0_READ__SHIFT                 0x00000000
#define	MC_PERF_CNT6_SEL__G3D1_READ__SHIFT                 0x00000001
#define	MC_PERF_CNT6_SEL__G3D2_READ__SHIFT                 0x00000002
#define	MC_PERF_CNT6_SEL__G3D3_READ__SHIFT                 0x00000003
#define	MC_PERF_CNT6_SEL__TX0_READ__SHIFT                  0x00000004
#define	MC_PERF_CNT6_SEL__TX1_READ__SHIFT                  0x00000005
#define	MC_PERF_CNT6_SEL__G3D0_WRITE__SHIFT                0x00000008
#define	MC_PERF_CNT6_SEL__G3D1_WRITE__SHIFT                0x00000009
#define	MC_PERF_CNT6_SEL__G3D2_WRITE__SHIFT                0x0000000a
#define	MC_PERF_CNT6_SEL__G3D3_WRITE__SHIFT                0x0000000b
#define	MC_PERF_CNT6_SEL__DISP0_READ__SHIFT                0x0000000c
#define	MC_PERF_CNT6_SEL__DISP1_READ__SHIFT                0x0000000d
#define	MC_PERF_CNT6_SEL__OV0_READ__SHIFT                  0x0000000e
#define	MC_PERF_CNT6_SEL__E2_READ__SHIFT                   0x0000000f
#define	MC_PERF_CNT6_SEL__VF_READ__SHIFT                   0x00000010
#define	MC_PERF_CNT6_SEL__CP_READ__SHIFT                   0x00000011
#define	MC_PERF_CNT6_SEL__CP_WRITE__SHIFT                  0x00000012
#define	MC_PERF_CNT6_SEL__VIP_READ__SHIFT                  0x00000013
#define	MC_PERF_CNT6_SEL__VIP_WRITE__SHIFT                 0x00000014
#define	MC_PERF_CNT6_SEL__IDCT_READ__SHIFT                 0x00000015
#define	MC_PERF_CNT6_SEL__IDCT_WRITE__SHIFT                0x00000016
#define	MC_PERF_CNT6_SEL__HDP_READ__SHIFT                  0x00000017
#define	MC_PERF_CNT6_SEL__HDP_WRITE__SHIFT                 0x00000018
#define	MC_PERF_CNT6_SEL__REGION_AGPPCI__SHIFT             0x00000019
#define	MC_PERF_CNT6_SEL__REGION_CHA__SHIFT                0x0000001a
#define	MC_PERF_CNT6_SEL__REGION_CHB__SHIFT                0x0000001b
#define	MC_PERF_CNT6_SEL__REGION_CHC__SHIFT                0x0000001c
#define	MC_PERF_CNT6_SEL__REGION_CHD__SHIFT                0x0000001d
#define	MC_PERF_CNT6_SEL__REGION_0__SHIFT                  0x0000001e
#define	MC_PERF_CNT6_SEL__REGION_1__SHIFT                  0x0000001f

// MC_PERF_CNT7_SEL
#define	MC_PERF_CNT7_SEL__G3D0_READ__SHIFT                 0x00000000
#define	MC_PERF_CNT7_SEL__G3D1_READ__SHIFT                 0x00000001
#define	MC_PERF_CNT7_SEL__G3D2_READ__SHIFT                 0x00000002
#define	MC_PERF_CNT7_SEL__G3D3_READ__SHIFT                 0x00000003
#define	MC_PERF_CNT7_SEL__TX0_READ__SHIFT                  0x00000004
#define	MC_PERF_CNT7_SEL__TX1_READ__SHIFT                  0x00000005
#define	MC_PERF_CNT7_SEL__G3D0_WRITE__SHIFT                0x00000008
#define	MC_PERF_CNT7_SEL__G3D1_WRITE__SHIFT                0x00000009
#define	MC_PERF_CNT7_SEL__G3D2_WRITE__SHIFT                0x0000000a
#define	MC_PERF_CNT7_SEL__G3D3_WRITE__SHIFT                0x0000000b
#define	MC_PERF_CNT7_SEL__DISP0_READ__SHIFT                0x0000000c
#define	MC_PERF_CNT7_SEL__DISP1_READ__SHIFT                0x0000000d
#define	MC_PERF_CNT7_SEL__OV0_READ__SHIFT                  0x0000000e
#define	MC_PERF_CNT7_SEL__E2_READ__SHIFT                   0x0000000f
#define	MC_PERF_CNT7_SEL__VF_READ__SHIFT                   0x00000010
#define	MC_PERF_CNT7_SEL__CP_READ__SHIFT                   0x00000011
#define	MC_PERF_CNT7_SEL__CP_WRITE__SHIFT                  0x00000012
#define	MC_PERF_CNT7_SEL__VIP_READ__SHIFT                  0x00000013
#define	MC_PERF_CNT7_SEL__VIP_WRITE__SHIFT                 0x00000014
#define	MC_PERF_CNT7_SEL__IDCT_READ__SHIFT                 0x00000015
#define	MC_PERF_CNT7_SEL__IDCT_WRITE__SHIFT                0x00000016
#define	MC_PERF_CNT7_SEL__HDP_READ__SHIFT                  0x00000017
#define	MC_PERF_CNT7_SEL__HDP_WRITE__SHIFT                 0x00000018
#define	MC_PERF_CNT7_SEL__REGION_AGPPCI__SHIFT             0x00000019
#define	MC_PERF_CNT7_SEL__REGION_CHA__SHIFT                0x0000001a
#define	MC_PERF_CNT7_SEL__REGION_CHB__SHIFT                0x0000001b
#define	MC_PERF_CNT7_SEL__REGION_CHC__SHIFT                0x0000001c
#define	MC_PERF_CNT7_SEL__REGION_CHD__SHIFT                0x0000001d
#define	MC_PERF_CNT7_SEL__REGION_0__SHIFT                  0x0000001e
#define	MC_PERF_CNT7_SEL__REGION_1__SHIFT                  0x0000001f

// MC_PERF_MEMCH_SEL
#define	MC_PERF_MEMCH_SEL__CH_A_SEQBUSY__SHIFT             0x00000000
#define	MC_PERF_MEMCH_SEL__CH_A_DATATFR__SHIFT             0x00000001
#define	MC_PERF_MEMCH_SEL__CH_A_PAGEOPEN__SHIFT            0x00000002
#define	MC_PERF_MEMCH_SEL__CH_A_PAGECLOSE__SHIFT           0x00000003
#define	MC_PERF_MEMCH_SEL__CH_A_R2W__SHIFT                 0x00000004
#define	MC_PERF_MEMCH_SEL__CH_A_W2R__SHIFT                 0x00000005
#define	MC_PERF_MEMCH_SEL__CH_A_REFRESH__SHIFT             0x00000006
#define	MC_PERF_MEMCH_SEL__CH_A_NOP__SHIFT                 0x00000007
#define	MC_PERF_MEMCH_SEL__CH_B_SEQBUSY__SHIFT             0x00000008
#define	MC_PERF_MEMCH_SEL__CH_B_DATATFR__SHIFT             0x00000009
#define	MC_PERF_MEMCH_SEL__CH_B_PAGEOPEN__SHIFT            0x0000000a
#define	MC_PERF_MEMCH_SEL__CH_B_PAGECLOSE__SHIFT           0x0000000b
#define	MC_PERF_MEMCH_SEL__CH_B_R2W__SHIFT                 0x0000000c
#define	MC_PERF_MEMCH_SEL__CH_B_W2R__SHIFT                 0x0000000d
#define	MC_PERF_MEMCH_SEL__CH_B_REFRESH__SHIFT             0x0000000e
#define	MC_PERF_MEMCH_SEL__CH_B_NOP__SHIFT                 0x0000000f
#define	MC_PERF_MEMCH_SEL__CH_A_S2ASTALL__SHIFT            0x00000010
#define	MC_PERF_MEMCH_SEL__CH_A_R2SWSTALL__SHIFT           0x00000011
#define	MC_PERF_MEMCH_SEL__CH_A_R2SRSTALL__SHIFT           0x00000012
#define	MC_PERF_MEMCH_SEL__CH_A_FIFOFULL__SHIFT            0x00000013
#define	MC_PERF_MEMCH_SEL__CH_B_S2ASTALL__SHIFT            0x00000018
#define	MC_PERF_MEMCH_SEL__CH_B_R2SWSTALL__SHIFT           0x00000019
#define	MC_PERF_MEMCH_SEL__CH_B_R2SRSTALL__SHIFT           0x0000001a
#define	MC_PERF_MEMCH_SEL__CH_B_FIFOFULL__SHIFT            0x0000001b

// MC_PERF_REGION_0
#define	MC_PERF_REGION_0_R3__SIZE__SHIFT                   0x00000000
#define	MC_PERF_REGION_0_R3__ADDRESS__SHIFT                0x0000000c

// MC_PERF_REGION_1
#define	MC_PERF_REGION_1_R3__SIZE__SHIFT                   0x00000000
#define	MC_PERF_REGION_1_R3__ADDRESS__SHIFT                0x0000000c

// MC_PERF_COUNT_0
#define	MC_PERF_COUNT_0_R3__PERF_COUNT__SHIFT              0x00000000

// MC_PERF_COUNT_1
#define	MC_PERF_COUNT_1_R3__PERF_COUNT__SHIFT              0x00000000

// MC_PERF_COUNT_2
#define	MC_PERF_COUNT_2_R3__PERF_COUNT__SHIFT              0x00000000

// MC_PERF_COUNT_3
#define	MC_PERF_COUNT_3_R3__PERF_COUNT__SHIFT              0x00000000

// MC_PERF_COUNT_4
#define	MC_PERF_COUNT_4__PERF_COUNT__SHIFT                 0x00000000

// MC_PERF_COUNT_5
#define	MC_PERF_COUNT_5__PERF_COUNT__SHIFT                 0x00000000

// MC_PERF_COUNT_6
#define	MC_PERF_COUNT_6__PERF_COUNT__SHIFT                 0x00000000

// MC_PERF_COUNT_7
#define	MC_PERF_COUNT_7__PERF_COUNT__SHIFT                 0x00000000

// MC_PERF_COUNT_MEMCH_A
#define	MC_PERF_COUNT_MEMCH_A_R3__PERF_COUNT_MEM_CH_A__SHIFT  0x00000000

// MC_PERF_COUNT_MEMCH_B
#define	MC_PERF_COUNT_MEMCH_B_R3__PERF_COUNT_MEM_CH_B__SHIFT  0x00000000

// MC_PERF_COUNT_MEMCH_C
#define	MC_PERF_COUNT_MEMCH_C__PERF_COUNT_MEM_CH_C__SHIFT  0x00000000

// MC_PERF_COUNT_MEMCH_D
#define	MC_PERF_COUNT_MEMCH_D__PERF_COUNT_MEM_CH_D__SHIFT  0x00000000

// MC_IMP_CNTL
#define	MC_IMP_CNTL_R3__MEM_IO_UPDATE_RATE__SHIFT          0x00000000
#define	MC_IMP_CNTL_R3__MEM_IO_SAMPLE_DELAY__SHIFT         0x00000005
#define	MC_IMP_CNTL_R3__MEM_IO_INC_THRESHOLD__SHIFT        0x0000000a
#define	MC_IMP_CNTL_R3__MEM_IO_DEC_THRESHOLD__SHIFT        0x0000000f
#define	MC_IMP_CNTL_R3__MEM_IO_MANUAL_OVERRIDE_CK__SHIFT   0x00000014
#define	MC_IMP_CNTL_R3__MEM_IO_MANUAL_OVERRIDE_A__SHIFT    0x00000015
#define	MC_IMP_CNTL_R3__MEM_IO_MANUAL_OVERRIDE_DQM__SHIFT  0x00000016
#define	MC_IMP_CNTL_R3__MEM_IO_MANUAL_OVERRIDE_DQS__SHIFT  0x00000017
#define	MC_IMP_CNTL_R3__MEM_IO_SLEWN__SHIFT                0x00000018
#define	MC_IMP_CNTL_R3__MEM_IO_SLEWP__SHIFT                0x00000019
#define	MC_IMP_CNTL_R3__MEM_IO_IMP_SAMPLE_IDLE__SHIFT      0x0000001a
#define	MC_IMP_CNTL_R3__MEM_IO_IMP_DEBUG_EN__SHIFT         0x0000001b
#define	MC_IMP_CNTL_R3__TEST_OUT_R_BACK__SHIFT             0x0000001c
#define	MC_IMP_CNTL_R3__DUMMY_OUT_R_BACK__SHIFT            0x0000001d

// MC_CHP_IO_CNTL_A0
#define	MC_CHP_IO_CNTL_A0_R3__MEM_N_CKA__SHIFT             0x00000000
#define	MC_CHP_IO_CNTL_A0_R3__MEM_N_AA__SHIFT              0x00000004
#define	MC_CHP_IO_CNTL_A0_R3__MEM_N_DQMA__SHIFT            0x00000008
#define	MC_CHP_IO_CNTL_A0_R3__MEM_N_DQSA__SHIFT            0x0000000c
#define	MC_CHP_IO_CNTL_A0_R3__MEM_P_CKA__SHIFT             0x00000010
#define	MC_CHP_IO_CNTL_A0_R3__MEM_P_AA__SHIFT              0x00000014
#define	MC_CHP_IO_CNTL_A0_R3__MEM_P_DQMA__SHIFT            0x00000018
#define	MC_CHP_IO_CNTL_A0_R3__MEM_P_DQSA__SHIFT            0x0000001c

// MC_CHP_IO_CNTL_A1
#define	MC_CHP_IO_CNTL_A1_R3__MEM_SLEWN_CKA__SHIFT         0x00000000
#define	MC_CHP_IO_CNTL_A1_R3__MEM_SLEWN_AA__SHIFT          0x00000001
#define	MC_CHP_IO_CNTL_A1_R3__MEM_SLEWN_DQMA__SHIFT        0x00000002
#define	MC_CHP_IO_CNTL_A1_R3__MEM_SLEWN_DQSA__SHIFT        0x00000003
#define	MC_CHP_IO_CNTL_A1_R3__MEM_SLEWP_CKA__SHIFT         0x00000004
#define	MC_CHP_IO_CNTL_A1_R3__MEM_SLEWP_AA__SHIFT          0x00000005
#define	MC_CHP_IO_CNTL_A1_R3__MEM_SLEWP_DQMA__SHIFT        0x00000006
#define	MC_CHP_IO_CNTL_A1_R3__MEM_SLEWP_DQSA__SHIFT        0x00000007
#define	MC_CHP_IO_CNTL_A1_R3__MEM_PREAMP_AA__SHIFT         0x00000008
#define	MC_CHP_IO_CNTL_A1_R3__MEM_PREAMP_DQMA__SHIFT       0x00000009
#define	MC_CHP_IO_CNTL_A1_R3__MEM_PREAMP_DQSA__SHIFT       0x0000000a
#define	MC_CHP_IO_CNTL_A1_R3__MEM_IO_QS_PDA__SHIFT         0x0000000b
#define	MC_CHP_IO_CNTL_A1_R3__MEM_IO_MODEA__SHIFT          0x0000000c
#define	MC_CHP_IO_CNTL_A1_R3__MEM_REC_CKA__SHIFT           0x0000000e
#define	MC_CHP_IO_CNTL_A1_R3__MEM_REC_AA__SHIFT            0x00000010
#define	MC_CHP_IO_CNTL_A1_R3__MEM_REC_DQMA__SHIFT          0x00000012
#define	MC_CHP_IO_CNTL_A1_R3__MEM_REC_DQSA__SHIFT          0x00000014
#define	MC_CHP_IO_CNTL_A1_R3__MEM_SYNC_PHASEA__SHIFT       0x00000016
#define	MC_CHP_IO_CNTL_A1_R3__MEM_SYNC_CENTERA__SHIFT      0x00000017
#define	MC_CHP_IO_CNTL_A1_R3__MEM_SYNC_ENA__SHIFT          0x00000018
#define	MC_CHP_IO_CNTL_A1_R3__MEM_CLK_SELA__SHIFT          0x0000001a
#define	MC_CHP_IO_CNTL_A1_R3__MEM_CLK_INVA__SHIFT          0x0000001c
#define	MC_CHP_IO_CNTL_A1_R3__MEM_DATA_ENIMP_A__SHIFT      0x0000001e
#define	MC_CHP_IO_CNTL_A1_R3__MEM_CNTL_ENIMP_A__SHIFT      0x0000001f

// MC_CHP_IO_CNTL_B0
#define	MC_CHP_IO_CNTL_B0_R3__MEM_N_CKB__SHIFT             0x00000000
#define	MC_CHP_IO_CNTL_B0_R3__MEM_N_AB__SHIFT              0x00000004
#define	MC_CHP_IO_CNTL_B0_R3__MEM_N_DQMB__SHIFT            0x00000008
#define	MC_CHP_IO_CNTL_B0_R3__MEM_N_DQSB__SHIFT            0x0000000c
#define	MC_CHP_IO_CNTL_B0_R3__MEM_P_CKB__SHIFT             0x00000010
#define	MC_CHP_IO_CNTL_B0_R3__MEM_P_AB__SHIFT              0x00000014
#define	MC_CHP_IO_CNTL_B0_R3__MEM_P_DQMB__SHIFT            0x00000018
#define	MC_CHP_IO_CNTL_B0_R3__MEM_P_DQSB__SHIFT            0x0000001c

// MC_CHP_IO_CNTL_B1
#define	MC_CHP_IO_CNTL_B1_R3__MEM_SLEWN_CKB__SHIFT         0x00000000
#define	MC_CHP_IO_CNTL_B1_R3__MEM_SLEWN_AB__SHIFT          0x00000001
#define	MC_CHP_IO_CNTL_B1_R3__MEM_SLEWN_DQMB__SHIFT        0x00000002
#define	MC_CHP_IO_CNTL_B1_R3__MEM_SLEWN_DQSB__SHIFT        0x00000003
#define	MC_CHP_IO_CNTL_B1_R3__MEM_SLEWP_CKB__SHIFT         0x00000004
#define	MC_CHP_IO_CNTL_B1_R3__MEM_SLEWP_AB__SHIFT          0x00000005
#define	MC_CHP_IO_CNTL_B1_R3__MEM_SLEWP_DQMB__SHIFT        0x00000006
#define	MC_CHP_IO_CNTL_B1_R3__MEM_SLEWP_DQSB__SHIFT        0x00000007
#define	MC_CHP_IO_CNTL_B1_R3__MEM_PREAMP_AB__SHIFT         0x00000008
#define	MC_CHP_IO_CNTL_B1_R3__MEM_PREAMP_DQMB__SHIFT       0x00000009
#define	MC_CHP_IO_CNTL_B1_R3__MEM_PREAMP_DQSB__SHIFT       0x0000000a
#define	MC_CHP_IO_CNTL_B1_R3__MEM_IO_QS_PDB__SHIFT         0x0000000b
#define	MC_CHP_IO_CNTL_B1_R3__MEM_IO_MODEB__SHIFT          0x0000000c
#define	MC_CHP_IO_CNTL_B1_R3__MEM_REC_CKB__SHIFT           0x0000000e
#define	MC_CHP_IO_CNTL_B1_R3__MEM_REC_AB__SHIFT            0x00000010
#define	MC_CHP_IO_CNTL_B1_R3__MEM_REC_DQMB__SHIFT          0x00000012
#define	MC_CHP_IO_CNTL_B1_R3__MEM_REC_DQSB__SHIFT          0x00000014
#define	MC_CHP_IO_CNTL_B1_R3__MEM_SYNC_PHASEB__SHIFT       0x00000016
#define	MC_CHP_IO_CNTL_B1_R3__MEM_SYNC_CENTERB__SHIFT      0x00000017
#define	MC_CHP_IO_CNTL_B1_R3__MEM_SYNC_ENB__SHIFT          0x00000018
#define	MC_CHP_IO_CNTL_B1_R3__MEM_CLK_SELB__SHIFT          0x0000001a
#define	MC_CHP_IO_CNTL_B1_R3__MEM_CLK_INVB__SHIFT          0x0000001c
#define	MC_CHP_IO_CNTL_B1_R3__MEM_DATA_ENIMP_B__SHIFT      0x0000001e
#define	MC_CHP_IO_CNTL_B1_R3__MEM_CNTL_ENIMP_B__SHIFT      0x0000001f

// MC_QS_CNTL_A0
#define	MC_QS_CNTL_A0__MEM_STR_DLY_SEL_A0__SHIFT           0x00000000
#define	MC_QS_CNTL_A0__MEM_DQ_DLY_SEL_A0__SHIFT            0x00000005
#define	MC_QS_CNTL_A0__MEM_STR_DLY_SEL_A1__SHIFT           0x00000008
#define	MC_QS_CNTL_A0__MEM_DQ_DLY_SEL_A1__SHIFT            0x0000000d
#define	MC_QS_CNTL_A0__MEM_STR_DLY_SEL_A2__SHIFT           0x00000010
#define	MC_QS_CNTL_A0__MEM_DQ_DLY_SEL_A2__SHIFT            0x00000015
#define	MC_QS_CNTL_A0__MEM_STR_DLY_SEL_A3__SHIFT           0x00000018
#define	MC_QS_CNTL_A0__MEM_DQ_DLY_SEL_A3__SHIFT            0x0000001d

// MC_QS_CNTL_A1
#define	MC_QS_CNTL_A1__MEM_STR_DLY_SEL_A4__SHIFT           0x00000000
#define	MC_QS_CNTL_A1__MEM_DQ_DLY_SEL_A4__SHIFT            0x00000005
#define	MC_QS_CNTL_A1__MEM_STR_DLY_SEL_A5__SHIFT           0x00000008
#define	MC_QS_CNTL_A1__MEM_DQ_DLY_SEL_A5__SHIFT            0x0000000d
#define	MC_QS_CNTL_A1__MEM_STR_DLY_SEL_A6__SHIFT           0x00000010
#define	MC_QS_CNTL_A1__MEM_DQ_DLY_SEL_A6__SHIFT            0x00000015
#define	MC_QS_CNTL_A1__MEM_STR_DLY_SEL_A7__SHIFT           0x00000018
#define	MC_QS_CNTL_A1__MEM_DQ_DLY_SEL_A7__SHIFT            0x0000001d

// MC_QS_CNTL_B0
#define	MC_QS_CNTL_B0__MEM_STR_DLY_SEL_B0__SHIFT           0x00000000
#define	MC_QS_CNTL_B0__MEM_DQ_DLY_SEL_B0__SHIFT            0x00000005
#define	MC_QS_CNTL_B0__MEM_STR_DLY_SEL_B1__SHIFT           0x00000008
#define	MC_QS_CNTL_B0__MEM_DQ_DLY_SEL_B1__SHIFT            0x0000000d
#define	MC_QS_CNTL_B0__MEM_STR_DLY_SEL_B2__SHIFT           0x00000010
#define	MC_QS_CNTL_B0__MEM_DQ_DLY_SEL_B2__SHIFT            0x00000015
#define	MC_QS_CNTL_B0__MEM_STR_DLY_SEL_B3__SHIFT           0x00000018
#define	MC_QS_CNTL_B0__MEM_DQ_DLY_SEL_B3__SHIFT            0x0000001d

// MC_QS_CNTL_B1
#define	MC_QS_CNTL_B1__MEM_STR_DLY_SEL_B4__SHIFT           0x00000000
#define	MC_QS_CNTL_B1__MEM_DQ_DLY_SEL_B4__SHIFT            0x00000005
#define	MC_QS_CNTL_B1__MEM_STR_DLY_SEL_B5__SHIFT           0x00000008
#define	MC_QS_CNTL_B1__MEM_DQ_DLY_SEL_B5__SHIFT            0x0000000d
#define	MC_QS_CNTL_B1__MEM_STR_DLY_SEL_B6__SHIFT           0x00000010
#define	MC_QS_CNTL_B1__MEM_DQ_DLY_SEL_B6__SHIFT            0x00000015
#define	MC_QS_CNTL_B1__MEM_STR_DLY_SEL_B7__SHIFT           0x00000018
#define	MC_QS_CNTL_B1__MEM_DQ_DLY_SEL_B7__SHIFT            0x0000001d

// MC_IMP_CNTL_0
#define	MC_IMP_CNTL_0_R3__MEM_STEP_N_A__SHIFT              0x00000000
#define	MC_IMP_CNTL_0_R3__MEM_STEP_N_DQM__SHIFT            0x00000002
#define	MC_IMP_CNTL_0_R3__MEM_STEP_N_CK__SHIFT             0x00000004
#define	MC_IMP_CNTL_0_R3__MEM_STEP_N_DQS__SHIFT            0x00000006
#define	MC_IMP_CNTL_0_R3__MEM_STEP_P_A__SHIFT              0x00000008
#define	MC_IMP_CNTL_0_R3__MEM_STEP_P_DQM__SHIFT            0x0000000a
#define	MC_IMP_CNTL_0_R3__MEM_STEP_P_CK__SHIFT             0x0000000c
#define	MC_IMP_CNTL_0_R3__MEM_STEP_P_DQS__SHIFT            0x0000000e
#define	MC_IMP_CNTL_0_R3__MEM_IMP_DEBUG_P__SHIFT           0x00000010
#define	MC_IMP_CNTL_0_R3__MEM_IMP_DEBUG_N__SHIFT           0x00000014
#define	MC_IMP_CNTL_0_R3__MEM_IMP_IDLE_CNT__SHIFT          0x00000018

// MC_ELPIDA_CNTL
#define	MC_ELPIDA_CNTL__MEM_INV_WD__SHIFT                  0x00000000
#define	MC_ELPIDA_CNTL__MEM_INV_RD__SHIFT                  0x00000001
#define	MC_ELPIDA_CNTL__MEM_R2R_ADDR__SHIFT                0x00000002
#define	MC_ELPIDA_CNTL__MEM_W2R_BNKPAIR__SHIFT             0x00000003
#define	MC_ELPIDA_CNTL__MEM_AUTOPRECHG__SHIFT              0x00000004
#define	MC_ELPIDA_CNTL__MEM_DLL__SHIFT                     0x00000005
#define	MC_ELPIDA_CNTL__MEM_REFRSHRATE__SHIFT              0x00000006
#define	MC_ELPIDA_CNTL__MEM_NEC_A__SHIFT                   0x00000008
#define	MC_ELPIDA_CNTL__MEM_NEC_B__SHIFT                   0x0000000a
#define	MC_ELPIDA_CNTL__MEM_NEC_C__SHIFT                   0x0000000c
#define	MC_ELPIDA_CNTL__MEM_NEC_D__SHIFT                   0x0000000e

// MC_CHP_IO_OE_CNTL_CD
#define	MC_CHP_IO_OE_CNTL_CD__DQ_OE_POSITION_C__SHIFT      0x00000000
#define	MC_CHP_IO_OE_CNTL_CD__QS_OE_POSITION_C__SHIFT      0x00000002
#define	MC_CHP_IO_OE_CNTL_CD__DQ_OE_EXTEND_C__SHIFT        0x00000004
#define	MC_CHP_IO_OE_CNTL_CD__QS_OE_EXTEND_C__SHIFT        0x00000005
#define	MC_CHP_IO_OE_CNTL_CD__DQ_OE_ADVANCE_C__SHIFT       0x00000006
#define	MC_CHP_IO_OE_CNTL_CD__QS_OE_ADVANCE_C__SHIFT       0x00000007
#define	MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_C0__SHIFT    0x00000008
#define	MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_C1__SHIFT    0x00000009
#define	MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_C2__SHIFT    0x0000000a
#define	MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_C3__SHIFT    0x0000000b
#define	MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_CMD_C__SHIFT    0x0000000c
#define	MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_DATA_C__SHIFT   0x0000000d
#define	MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_STR_C__SHIFT    0x0000000e
#define	MC_CHP_IO_OE_CNTL_CD__DQ_OE_POSITION_D__SHIFT      0x00000010
#define	MC_CHP_IO_OE_CNTL_CD__QS_OE_POSITION_D__SHIFT      0x00000012
#define	MC_CHP_IO_OE_CNTL_CD__DQ_OE_EXTEND_D__SHIFT        0x00000014
#define	MC_CHP_IO_OE_CNTL_CD__QS_OE_EXTEND_D__SHIFT        0x00000015
#define	MC_CHP_IO_OE_CNTL_CD__DQ_OE_ADVANCE_D__SHIFT       0x00000016
#define	MC_CHP_IO_OE_CNTL_CD__QS_OE_ADVANCE_D__SHIFT       0x00000017
#define	MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_D0__SHIFT    0x00000018
#define	MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_D1__SHIFT    0x00000019
#define	MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_D2__SHIFT    0x0000001a
#define	MC_CHP_IO_OE_CNTL_CD__DQS_DRIVER_SLCT_D3__SHIFT    0x0000001b
#define	MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_CMD_D__SHIFT    0x0000001c
#define	MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_DATA_D__SHIFT   0x0000001d
#define	MC_CHP_IO_OE_CNTL_CD__MEM_FALL_OUT_STR_D__SHIFT    0x0000001e

// MC_READ_CNTL_CD
#define	MC_READ_CNTL_CD__MEM_RBS_POSITION_C__SHIFT         0x00000000
#define	MC_READ_CNTL_CD__MEM_STR_SEL_C__SHIFT              0x00000003
#define	MC_READ_CNTL_CD__MEM_ERST_POSITION_C__SHIFT        0x00000004
#define	MC_READ_CNTL_CD__MEM_ERST_EXTEND_C__SHIFT          0x00000007
#define	MC_READ_CNTL_CD__MEM_QSREC_POSITION_C__SHIFT       0x00000008
#define	MC_READ_CNTL_CD__MEM_QSREC_EXTEND_C__SHIFT         0x0000000b
#define	MC_READ_CNTL_CD__MEM_ERST_SYNC_C__SHIFT            0x0000000c
#define	MC_READ_CNTL_CD__MEM_QSREC_SYNC_C__SHIFT           0x0000000d
#define	MC_READ_CNTL_CD__MEM_RBS_POSITION_D__SHIFT         0x00000010
#define	MC_READ_CNTL_CD__MEM_STR_SEL_D__SHIFT              0x00000013
#define	MC_READ_CNTL_CD__MEM_ERST_POSITION_D__SHIFT        0x00000014
#define	MC_READ_CNTL_CD__MEM_ERST_EXTEND_D__SHIFT          0x00000017
#define	MC_READ_CNTL_CD__MEM_QSREC_POSITION_D__SHIFT       0x00000018
#define	MC_READ_CNTL_CD__MEM_QSREC_EXTEND_D__SHIFT         0x0000001b
#define	MC_READ_CNTL_CD__MEM_ERST_SYNC_D__SHIFT            0x0000001c
#define	MC_READ_CNTL_CD__MEM_QSREC_SYNC_D__SHIFT           0x0000001d

// MC_INIT_WR_LAT_TIMER
#define	MC_INIT_WR_LAT_TIMER__MC_G3D0W_INIT_LAT__SHIFT     0x00000000
#define	MC_INIT_WR_LAT_TIMER__MC_G3D1W_INIT_LAT__SHIFT     0x00000004
#define	MC_INIT_WR_LAT_TIMER__MC_G3D2W_INIT_LAT__SHIFT     0x00000008
#define	MC_INIT_WR_LAT_TIMER__MC_G3D3W_INIT_LAT__SHIFT     0x0000000c
#define	MC_INIT_WR_LAT_TIMER__MC_IDCTW_INIT_LAT__SHIFT     0x00000010
#define	MC_INIT_WR_LAT_TIMER__MC_HDPW_INIT_LAT__SHIFT      0x00000014
#define	MC_INIT_WR_LAT_TIMER__MC_VIPW_INIT_LAT__SHIFT      0x00000018
#define	MC_INIT_WR_LAT_TIMER__MC_CPW_INIT_LAT__SHIFT       0x0000001c

// MC_DEBUG_CNTL
#define	MC_DEBUG_CNTL__MC_DELAY_EMPTY__SHIFT               0x00000000
#define	MC_DEBUG_CNTL__MC_DELAY_NOT_FULL__SHIFT            0x00000001
#define	MC_DEBUG_CNTL__MC_DEBUG_3_2__SHIFT                 0x00000002
#define	MC_DEBUG_CNTL__MC_DEBUG_7_4__SHIFT                 0x00000004
#define	MC_DEBUG_CNTL__MC_DEBUG_11_8__SHIFT                0x00000008
#define	MC_DEBUG_CNTL__MC_DEBUG_15_12__SHIFT               0x0000000c
#define	MC_DEBUG_CNTL__MC_DEBUG_19_16__SHIFT               0x00000010
#define	MC_DEBUG_CNTL__MC_DEBUG_23_20__SHIFT               0x00000014
#define	MC_DEBUG_CNTL__MC_DEBUG_27_24__SHIFT               0x00000018
#define	MC_DEBUG_CNTL__MC_DEBUG_31_28__SHIFT               0x0000001c

// MC_BIST_CNTL_0
#define	MC_BIST_CNTL_0__MC_BIST_CNTL__SHIFT                0x00000000

// MC_BIST_CNTL_1
#define	MC_BIST_CNTL_1__MC_BIST_COLLAR_WRITE__SHIFT        0x00000000

// MC_BIST_CNTL_2
#define	MC_BIST_CNTL_2__MC_BIST_COLLAR_READ__SHIFT         0x00000000

// MC_BIST_CNTL_3
#define	MC_BIST_CNTL_3__RUN_MC_BIST__SHIFT                 0x00000000
#define	MC_BIST_CNTL_3__EBIST_MODE__SHIFT                  0x00000001
#define	MC_BIST_CNTL_3__MC_CHANNEL_MAP__SHIFT              0x00000008
#define	MC_BIST_CNTL_3__MC_BANK_0_MAP__SHIFT               0x0000000c
#define	MC_BIST_CNTL_3__MC_BANK_1_MAP__SHIFT               0x00000010
#define	MC_BIST_CNTL_3__ONE_PAGE__SHIFT                    0x00000014
#define	MC_BIST_CNTL_3__DIS_DISPACK__SHIFT                 0x00000015
#define	MC_BIST_CNTL_3__MEM_SYNC_MODE__SHIFT               0x00000016
#define	MC_BIST_CNTL_3__PP_SELF_REFRESH__SHIFT             0x00000017
#define	MC_BIST_CNTL_3__DISP0R_FIFO_LEVEL__SHIFT           0x00000019
#define	MC_BIST_CNTL_3__DISP1R_FIFO_LEVEL__SHIFT           0x0000001a
#define	MC_BIST_CNTL_3__OV0R_FIFO_LEVEL__SHIFT             0x0000001b
#define	MC_BIST_CNTL_3__CPR_FIFO_LEVEL__SHIFT              0x0000001c
#define	MC_BIST_CNTL_3__VFR_FIFO_LEVEL__SHIFT              0x0000001d
#define	MC_BIST_CNTL_3__E2R_FIFO_LEVEL__SHIFT              0x0000001e
#define	MC_BIST_CNTL_3__IDCTR_FIFO_LEVEL__SHIFT            0x0000001f

// MC_BIST_CNTL_4
#define	MC_BIST_CNTL_4__MC_PARALLEL_MISMATCH_L__SHIFT      0x00000000

// MC_BIST_CNTL_5
#define	MC_BIST_CNTL_5__MC_PARALLEL_MISMATCH_H__SHIFT      0x00000000

// MC_DLL_CNTL
#define	MC_DLL_CNTL__MC_DLL_RANGE_A0__SHIFT                0x00000000
#define	MC_DLL_CNTL__MC_DLL_RANGE_A1__SHIFT                0x00000003
#define	MC_DLL_CNTL__MC_DLL_RANGE_B0__SHIFT                0x00000006
#define	MC_DLL_CNTL__MC_DLL_RANGE_B1__SHIFT                0x00000009
#define	MC_DLL_CNTL__MC_DLL_RANGE_C0__SHIFT                0x0000000c
#define	MC_DLL_CNTL__MC_DLL_RANGE_C1__SHIFT                0x0000000f
#define	MC_DLL_CNTL__MC_DLL_RANGE_D0__SHIFT                0x00000012
#define	MC_DLL_CNTL__MC_DLL_RANGE_D1__SHIFT                0x00000015
#define	MC_DLL_CNTL__MC_DLL_TSTOUT_SEL__SHIFT              0x00000018
#define	MC_DLL_CNTL__MC_DLL_TSTOUT_EN__SHIFT               0x0000001d

// MC_FB_LOCATION
#define	MC_FB_LOCATION__MC_FB_START__SHIFT                 0x00000000
#define	MC_FB_LOCATION__MC_FB_TOP__SHIFT                   0x00000010

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
#define	WAIT_UNTIL__WAIT_AGP_FLUSH__SHIFT                  0x0000000d
#define	WAIT_UNTIL__WAIT_2D_IDLE__SHIFT                    0x0000000e
#define	WAIT_UNTIL__WAIT_3D_IDLE__SHIFT                    0x0000000f
#define	WAIT_UNTIL__WAIT_2D_IDLECLEAN__SHIFT               0x00000010
#define	WAIT_UNTIL__WAIT_3D_IDLECLEAN__SHIFT               0x00000011
#define	WAIT_UNTIL__WAIT_HOST_IDLECLEAN__SHIFT             0x00000012
#define	WAIT_UNTIL__WAIT_EXTERN_SIG__SHIFT                 0x00000013
#define	WAIT_UNTIL__CMDFIFO_ENTRIES__SHIFT                 0x00000014
#define	WAIT_UNTIL__WAIT_IDCT_SEMAPHORE__SHIFT             0x0000001b
#define	WAIT_UNTIL__WAIT_VAP_IDLE__SHIFT                   0x0000001c
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
#define	RBBM_STATUS__GA_BUSY__SHIFT                        0x0000001a
#define	RBBM_STATUS__CBA2D_BUSY__SHIFT                     0x0000001b
#define	RBBM_STATUS__GUI_ACTIVE__SHIFT                     0x0000001f

// RBBM_CNTL
#define	RBBM_CNTL__RB_SETTLE__SHIFT                        0x00000000
#define	RBBM_CNTL__ABORTCLKS_HI__SHIFT                     0x00000004
#define	RBBM_CNTL__ABORTCLKS_CP__SHIFT                     0x00000008
#define	RBBM_CNTL__ABORTCLKS_CFIFO__SHIFT                  0x0000000c
#define	RBBM_CNTL__CPQ_DATA_SWAP__SHIFT                    0x00000011
#define	RBBM_CNTL__NO_ABORT_VAP__SHIFT                     0x00000013
#define	RBBM_CNTL__NO_ABORT_GA__SHIFT                      0x00000014
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
#define	RBBM_SOFT_RESET__SOFT_RESET_GA__SHIFT              0x0000000d
#define	RBBM_SOFT_RESET__SOFT_RESET_IDCT__SHIFT            0x0000000e

// NQWAIT_UNTIL
#define	NQWAIT_UNTIL__WAIT_GUI_IDLE__SHIFT                 0x00000000

// RBBM_DEBUG
#define	RBBM_DEBUG__RBBM_DEBUG_R2__SHIFT                   0x00000000

// RBBM_CMDFIFO_ADDR
#define	RBBM_CMDFIFO_ADDR__CMDFIFO_ADDR_R3__SHIFT          0x00000000

// RBBM_CMDFIFO_DATA
#define	RBBM_CMDFIFO_DATA__CMDFIFO_DATA__SHIFT             0x00000000

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
#define	GEN_INT_CNTL__DMA_VIPH0_INT_EN__SHIFT              0x0000000c
#define	GEN_INT_CNTL__DMA_VIPH1_INT_EN__SHIFT              0x0000000d
#define	GEN_INT_CNTL__DMA_VIPH2_INT_EN__SHIFT              0x0000000e
#define	GEN_INT_CNTL__DMA_VIPH3_INT_EN__SHIFT              0x0000000f
#define	GEN_INT_CNTL__TIMER_INT_MASK__SHIFT                0x00000010
#define	GEN_INT_CNTL__I2C_INT_EN__SHIFT                    0x00000011
#define	GEN_INT_CNTL__GUI_IDLE_MASK__SHIFT                 0x00000013
#define	GEN_INT_CNTL__VIPH_INT_EN__SHIFT                   0x00000018
#define	GEN_INT_CNTL__SW_INT_EN__SHIFT                     0x00000019
#define	GEN_INT_CNTL__IDCT_INT_EN__SHIFT                   0x0000001b
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
#define	GEN_INT_STATUS__DMA_VIPH0_INT__SHIFT               0x0000000c
#define	GEN_INT_STATUS__DMA_VIPH0_INT_AK__SHIFT            0x0000000c
#define	GEN_INT_STATUS__DMA_VIPH1_INT__SHIFT               0x0000000d
#define	GEN_INT_STATUS__DMA_VIPH1_INT_AK__SHIFT            0x0000000d
#define	GEN_INT_STATUS__DMA_VIPH2_INT__SHIFT               0x0000000e
#define	GEN_INT_STATUS__DMA_VIPH2_INT_AK__SHIFT            0x0000000e
#define	GEN_INT_STATUS__DMA_VIPH3_INT__SHIFT               0x0000000f
#define	GEN_INT_STATUS__DMA_VIPH3_INT_AK__SHIFT            0x0000000f
#define	GEN_INT_STATUS__TIMER_INT_STAT__SHIFT              0x00000010
#define	GEN_INT_STATUS__TIMER_INT_STAT_AK__SHIFT           0x00000010
#define	GEN_INT_STATUS__I2C_INT__SHIFT                     0x00000011
#define	GEN_INT_STATUS__I2C_INT_AK__SHIFT                  0x00000011
#define	GEN_INT_STATUS__GUI_IDLE_STAT__SHIFT               0x00000013
#define	GEN_INT_STATUS__GUI_IDLE_STAT_AK__SHIFT            0x00000013
#define	GEN_INT_STATUS__VIPH_INT__SHIFT                    0x00000018
#define	GEN_INT_STATUS__SW_INT__SHIFT                      0x00000019
#define	GEN_INT_STATUS__SW_INT_AK__SHIFT                   0x00000019
#define	GEN_INT_STATUS__SW_INT_SET__SHIFT                  0x0000001a
#define	GEN_INT_STATUS__IDCT_INT_STAT__SHIFT               0x0000001b
#define	GEN_INT_STATUS__IDCT_INT_STAT_AK__SHIFT            0x0000001b
#define	GEN_INT_STATUS__HDCP_AUTHORIZED_INT_STAT__SHIFT    0x0000001c
#define	GEN_INT_STATUS__HDCP_AUTHORIZED_INT_AK__SHIFT      0x0000001c
#define	GEN_INT_STATUS__DVI_I2C_INT_STAT__SHIFT            0x0000001d
#define	GEN_INT_STATUS__DVI_I2C_INT_AK__SHIFT              0x0000001d
#define	GEN_INT_STATUS__GUIDMA_STAT__SHIFT                 0x0000001e
#define	GEN_INT_STATUS__GUIDMA_AK__SHIFT                   0x0000001e
#define	GEN_INT_STATUS__VIDDMA_STAT__SHIFT                 0x0000001f
#define	GEN_INT_STATUS__VIDDMA_AK__SHIFT                   0x0000001f

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
#define	BUS_CNTL__BUS_PM4_READ_COMBINE_EN__SHIFT           0x00000004
#define	BUS_CNTL__BUS_WRT_COMBINE_EN__SHIFT                0x00000005
#define	BUS_CNTL__BUS_MASTER_DIS__SHIFT                    0x00000006
#define	BUS_CNTL__BIOS_ROM_WRT_EN__SHIFT                   0x00000007
#define	BUS_CNTL__BM_DAC_CRIPPLE__SHIFT                    0x00000008
#define	BUS_CNTL__BUS_NON_PM4_READ_COMBINE_EN__SHIFT       0x00000009
#define	BUS_CNTL__BUS_XFERD_DISCARD_EN__SHIFT              0x0000000a
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
#define	BUS_CNTL1__BUS_CNTL1_BIT6__SHIFT                   0x00000006
#define	BUS_CNTL1__AGPCLK_VALID_R3__SHIFT                  0x00000007
#define	BUS_CNTL1__BUS2_VGA_REG_COHERENCY_DIS__SHIFT       0x00000008
#define	BUS_CNTL1__BUS2_VGA_MEM_COHERENCY_DIS__SHIFT       0x00000009
#define	BUS_CNTL1__BUS2_HDP_REG_COHERENCY_DIS__SHIFT       0x0000000a
#define	BUS_CNTL1__BUS2_GUI_INITIATOR_COHERENCY_DIS__SHIFT 0x0000000b
#define	BUS_CNTL1__BUS2_VGA_FW_COHERENCY_DIS__SHIFT        0x0000000c
#define	BUS_CNTL1__BUS2_ACCEL_FW_COHERENCY_DIS__SHIFT      0x0000000d
#define	BUS_CNTL1__MOBILE_PLATFORM_SEL_R3__SHIFT           0x0000000e
#define	BUS_CNTL1__BUS2_RD_PANIC_VAL__SHIFT                0x00000010
#define	BUS_CNTL1__BUS2_WRT_PANIC_VAL__SHIFT               0x00000014
#define	BUS_CNTL1__BUS2_REQ_DELAY__SHIFT                   0x00000018
#define	BUS_CNTL1__BUS2_EARLY_REQ_DROP__SHIFT              0x0000001c
#define	BUS_CNTL1__SEND_SBA_LATENCY_R3__SHIFT              0x0000001d

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

// PAD_AGPINPUT_DELAY
#define	PAD_AGPINPUT_DELAY__PAD_AGPINPUT_DELAY__SHIFT      0x00000000

// PAD_CTLR_STRENGTH
#define	PAD_CTLR_STRENGTH__PAD_N_STRENGTH_READ_BACK_R3__SHIFT 0x00000000
#define	PAD_CTLR_STRENGTH__PAD_P_STRENGTH_READ_BACK_R3__SHIFT 0x00000008
#define	PAD_CTLR_STRENGTH__PAD_N_MANUAL_STRENGTH_R3__SHIFT 0x00000010
#define	PAD_CTLR_STRENGTH__PAD_P_MANUAL_STRENGTH_R3__SHIFT 0x00000018
#define	PAD_CTLR_STRENGTH__PAD_MANUAL_OVERRIDE_R3__SHIFT   0x0000001f

// PAD_CTLR_MISC
#define	PAD_CTLR_MISC__DYNAMIC_IMP_EN__SHIFT               0x00000000
#define	PAD_CTLR_MISC__DISABLE_WPTR_RST__SHIFT             0x00000001
#define	PAD_CTLR_MISC__PAD_VREF_INT_EN__SHIFT              0x00000002
#define	PAD_CTLR_MISC__AUTO_AGP_RSYNC_EN__SHIFT            0x00000005
#define	PAD_CTLR_MISC__AGP_RSYNC_AD_DURING_WR_IDLE_EN__SHIFT 0x00000006
#define	PAD_CTLR_MISC__MANUAL_AGP_RSYNC__SHIFT             0x00000007
#define	PAD_CTLR_MISC__PAD_HI_IO_PREAMPH__SHIFT            0x00000008
#define	PAD_CTLR_MISC__PAD_HI_IO_PREAMPH_STB__SHIFT        0x00000009
#define	PAD_CTLR_MISC__TRISTATE_AGP_PADS__SHIFT            0x0000000a
#define	PAD_CTLR_MISC__PAD_AGP30_SIG_SBA_UPDATE_CNTL__SHIFT 0x0000000d
#define	PAD_CTLR_MISC__PAD_AGP30_SIG_SBA_CAL_DIS__SHIFT    0x0000000e
#define	PAD_CTLR_MISC__PAD_AGP30_SIG_TRDY_DIS__SHIFT       0x0000000f
#define	PAD_CTLR_MISC__PAD_AGP30SIGNALING_CAL_DIS__SHIFT   0x00000010
#define	PAD_CTLR_MISC__PAD_TEST_OUT__SHIFT                 0x00000011
#define	PAD_CTLR_MISC__PAD_DUMMY_OUT__SHIFT                0x00000012
#define	PAD_CTLR_MISC__PAD_HI_IO_DFR__SHIFT                0x00000013
#define	PAD_CTLR_MISC__PAD_HI_IO_SCHMEN__SHIFT             0x00000014
#define	PAD_CTLR_MISC__PAD_HI_IO_DREN__SHIFT               0x00000015
#define	PAD_CTLR_MISC__PAD_HI_IO_VDIFF__SHIFT              0x00000017
#define	PAD_CTLR_MISC__PAD_HI_IO_DFR_OVERRIDE__SHIFT       0x00000018
#define	PAD_CTLR_MISC__PAD_HI_IO_SCHMEN_OVERRIDE__SHIFT    0x00000019
#define	PAD_CTLR_MISC__PAD_HI_IO_DREN_OVERRIDE__SHIFT      0x0000001a
#define	PAD_CTLR_MISC__PAD_HI_IO_VDIFF_OVERRIDE__SHIFT     0x0000001c
#define	PAD_CTLR_MISC__PAD_HI_IO_SLEWN__SHIFT              0x0000001d
#define	PAD_CTLR_MISC__PAD_HI_IO_SLEWP__SHIFT              0x0000001e
#define	PAD_CTLR_MISC__PAD_HI_IO_SLEW_OVERRIDE__SHIFT      0x0000001f

// PAD_CTLR_UPDATE
#define	PAD_CTLR_UPDATE__PAD_UPDATE_RATE__SHIFT            0x00000000
#define	PAD_CTLR_UPDATE__PAD_SAMPLE_DELAY__SHIFT           0x00000008
#define	PAD_CTLR_UPDATE__PAD_INC_THRESHOLD__SHIFT          0x00000010
#define	PAD_CTLR_UPDATE__PAD_DEC_THRESHOLD__SHIFT          0x00000018

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
#define	AGP_CNTL__PCI_DBI_DISABLE__SHIFT                   0x00000014
#define	AGP_CNTL__AGP_DBI_DISABLE__SHIFT                   0x00000015
#define	AGP_CNTL__EN_RDATA2X4X_MULTIRESET__SHIFT           0x00000016
#define	AGP_CNTL__EN_RBFCALM__SHIFT                        0x00000017
#define	AGP_CNTL__FORCE_EXT_VREF__SHIFT                    0x00000018
#define	AGP_CNTL__DIS_RBF__SHIFT                           0x00000019
#define	AGP_CNTL__DELAY_FIRST_SBA_EN__SHIFT                0x0000001a
#define	AGP_CNTL__DELAY_FIRST_SBA_VAL__SHIFT               0x0000001b
#define	AGP_CNTL__CRIPPLE_AGP8X__SHIFT                     0x0000001e
#define	AGP_CNTL__AGP_MISC_R3__SHIFT                       0x0000001f

// BM_STATUS
#define	BM_STATUS__BUS_MASTER_STATUS__SHIFT                0x00000000

// PAD_CTLR_STRENGTH2
#define	PAD_CTLR_STRENGTH2__PAD_SBA_N_STRENGTH_READ_BACK__SHIFT 0x00000000
#define	PAD_CTLR_STRENGTH2__PAD_SBA_P_STRENGTH_READ_BACK__SHIFT 0x00000008
#define	PAD_CTLR_STRENGTH2__NAGPIO_N_STRENGTH_VALUE__SHIFT 0x00000010
#define	PAD_CTLR_STRENGTH2__NAGPIO_P_STRENGTH_VALUE__SHIFT 0x00000014

// PAMAC0_DLY_CNTL
#define	PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_DATA_U__SHIFT       0x00000000
#define	PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_DATA_L__SHIFT       0x00000004
#define	PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_STB__SHIFT          0x00000008
#define	PAMAC0_DLY_CNTL__PAMAC0_DLY_IN_DBI__SHIFT          0x0000000c
#define	PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_DATA_U__SHIFT      0x00000010
#define	PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_DATA_L__SHIFT      0x00000012
#define	PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_STB__SHIFT         0x00000014
#define	PAMAC0_DLY_CNTL__PAMAC0_DLY_OUT_DBI__SHIFT         0x00000016
#define	PAMAC0_DLY_CNTL__PAMAC0_CLK_INS_DLY__SHIFT         0x00000018
#define	PAMAC0_DLY_CNTL__PAMAC0_SYNC_DLY__SHIFT            0x00000019

// PAMAC1_DLY_CNTL
#define	PAMAC1_DLY_CNTL__PAMAC1_DLY_IN_DATA_U__SHIFT       0x00000000
#define	PAMAC1_DLY_CNTL__PAMAC1_DLY_IN_DATA_L__SHIFT       0x00000004
#define	PAMAC1_DLY_CNTL__PAMAC1_DLY_IN_STB__SHIFT          0x00000008
#define	PAMAC1_DLY_CNTL__PAMAC1_DLY_OUT_DATA_U__SHIFT      0x00000010
#define	PAMAC1_DLY_CNTL__PAMAC1_DLY_OUT_DATA_L__SHIFT      0x00000012
#define	PAMAC1_DLY_CNTL__PAMAC1_DLY_OUT_STB__SHIFT         0x00000014
#define	PAMAC1_DLY_CNTL__PAMAC1_CLK_INS_DLY__SHIFT         0x00000018
#define	PAMAC1_DLY_CNTL__PAMAC1_SYNC_DLY__SHIFT            0x00000019

// PAMAC2_DLY_CNTL
#define	PAMAC2_DLY_CNTL__PAMAC2_DLY_IN_DATA_U__SHIFT       0x00000000
#define	PAMAC2_DLY_CNTL__PAMAC2_DLY_IN_DATA_L__SHIFT       0x00000004
#define	PAMAC2_DLY_CNTL__PAMAC2_DLY_IN_STB__SHIFT          0x00000008
#define	PAMAC2_DLY_CNTL__PAMAC2_DLY_OUT_DATA_U__SHIFT      0x00000010
#define	PAMAC2_DLY_CNTL__PAMAC2_DLY_OUT_DATA_L__SHIFT      0x00000012
#define	PAMAC2_DLY_CNTL__PAMAC2_DLY_OUT_STB__SHIFT         0x00000014
#define	PAMAC2_DLY_CNTL__PAMAC2_CLK_INS_DLY__SHIFT         0x00000018
#define	PAMAC2_DLY_CNTL__PAMAC2_SYNC_DLY__SHIFT            0x00000019

// AIC_CTRL
#define	AIC_CTRL__TRANSLATE_EN__SHIFT                      0x00000000
#define	AIC_CTRL__DIS_OUT_OF_PCI_GART_ACCESS__SHIFT        0x00000001
#define	AIC_CTRL__HW_02_DEBUG__SHIFT                       0x00000002
#define	AIC_CTRL__HW_03_DEBUG__SHIFT                       0x00000003
#define	AIC_CTRL__TEST_RBF_DIV_VAL__SHIFT                  0x00000004
#define	AIC_CTRL__TEST_RBF_EN__SHIFT                       0x00000007
#define	AIC_CTRL__HW_08_DEBUG__SHIFT                       0x00000008
#define	AIC_CTRL__HW_09_DEBUG__SHIFT                       0x00000009
#define	AIC_CTRL__HW_10_DEBUG_R3__SHIFT                    0x0000000a
#define	AIC_CTRL__HW_11_DEBUG_R3__SHIFT                    0x0000000b
#define	AIC_CTRL__HW_12_DEBUG_R3__SHIFT                    0x0000000c
#define	AIC_CTRL__HW_13_DEBUG_R3__SHIFT                    0x0000000d
#define	AIC_CTRL__HW_14_DEBUG_R3__SHIFT                    0x0000000e
#define	AIC_CTRL__HW_15_DEBUG_R3__SHIFT                    0x0000000f
#define	AIC_CTRL__HW_16_DEBUG_R3__SHIFT                    0x00000010
#define	AIC_CTRL__HW_17_DEBUG_R3__SHIFT                    0x00000011
#define	AIC_CTRL__HW_18_DEBUG_R3__SHIFT                    0x00000012
#define	AIC_CTRL__HW_19_DEBUG_R3__SHIFT                    0x00000013
#define	AIC_CTRL__HW_20_DEBUG__SHIFT                       0x00000014
#define	AIC_CTRL__HW_21_DEBUG__SHIFT                       0x00000015
#define	AIC_CTRL__HW_22_DEBUG__SHIFT                       0x00000016
#define	AIC_CTRL__HW_23_DEBUG__SHIFT                       0x00000017
#define	AIC_CTRL__HW_24_DEBUG__SHIFT                       0x00000018
#define	AIC_CTRL__HW_25_DEBUG__SHIFT                       0x00000019
#define	AIC_CTRL__HW_26_DEBUG__SHIFT                       0x0000001a
#define	AIC_CTRL__HW_27_DEBUG__SHIFT                       0x0000001b
#define	AIC_CTRL__HW_28_DEBUG__SHIFT                       0x0000001c
#define	AIC_CTRL__HW_29_DEBUG__SHIFT                       0x0000001d
#define	AIC_CTRL__HW_30_DEBUG__SHIFT                       0x0000001e
#define	AIC_CTRL__HW_31_DEBUG__SHIFT                       0x0000001f

// AIC_STAT
#define	AIC_STAT__AIC_TLB_VLD__SHIFT                       0x00000000
#define	AIC_STAT__AIC_STAT1__SHIFT                         0x00000001
#define	AIC_STAT__AIC_STAT0__SHIFT                         0x00000002

// AIC_PT_BASE_LO
#define	AIC_PT_BASE_LO__AIC_PT_BASE_LO__SHIFT              0x0000000c

// AIC_PT_BASE_HI
#define	AIC_PT_BASE_HI__AIC_PT_BASE_HI__SHIFT              0x00000000

// AIC_LO_ADDR
#define	AIC_LO_ADDR__AIC_LO_ADDR__SHIFT                    0x0000000c

// AIC_HI_ADDR
#define	AIC_HI_ADDR__AIC_HI_ADDR__SHIFT                    0x0000000c

// AIC_TLB_ADDR
#define	AIC_TLB_ADDR__AIC_TLB_ADDR__SHIFT                  0x0000000c

// AIC_TLB_DATA_LO
#define	AIC_TLB_DATA_LO__AIC_TLB_DATA_LO__SHIFT            0x0000000c

// AIC_TLB_DATA_HI
#define	AIC_TLB_DATA_HI__AIC_TLB_DATA_HI__SHIFT            0x00000000

// AIC_RESYNC_CNTL
#define	AIC_RESYNC_CNTL__DBL_RSYNC_AGP_RDFIFO_RPTR__SHIFT  0x00000000
#define	AIC_RESYNC_CNTL__DBL_RSYNC_PCI_RDFIFO_RPTR__SHIFT  0x00000001
#define	AIC_RESYNC_CNTL__DBL_RSYNC_AGP_RDFIFO_WPTR__SHIFT  0x00000002
#define	AIC_RESYNC_CNTL__DBL_RSYNC_PCI_RDFIFO_WPTR__SHIFT  0x00000003
#define	AIC_RESYNC_CNTL__DBL_RSYNC_AGP_RQFIFO_RPTR__SHIFT  0x00000004
#define	AIC_RESYNC_CNTL__DBL_RSYNC_PCI_RQFIFO_RPTR__SHIFT  0x00000005
#define	AIC_RESYNC_CNTL__DBL_RSYNC_AGP_RQFIFO_WPTR__SHIFT  0x00000006
#define	AIC_RESYNC_CNTL__DBL_RSYNC_PCI_RQFIFO_WPTR__SHIFT  0x00000007
#define	AIC_RESYNC_CNTL__DBL_RSYNC_AGP_WRFIFO_RPTR__SHIFT  0x00000008
#define	AIC_RESYNC_CNTL__DBL_RSYNC_PCI_WRFIFO_RPTR__SHIFT  0x00000009
#define	AIC_RESYNC_CNTL__DBL_RSYNC_AGP_WRFIFO_WPTR__SHIFT  0x0000000a
#define	AIC_RESYNC_CNTL__DBL_RSYNC_PCI_WRFIFO_WPTR__SHIFT  0x0000000b

// AGP_FENCE_CNTL
#define	AGP_FENCE_CNTL__FENCE_EN__SHIFT                    0x00000000
#define	AGP_FENCE_CNTL__ADDR__SHIFT                        0x00000003

// AGP_FLUSH_CNTL
#define	AGP_FLUSH_CNTL__FLUSH_EN__SHIFT                    0x00000000
#define	AGP_FLUSH_CNTL__FLUSH_ACK__SHIFT                   0x00000001
#define	AGP_FLUSH_CNTL__ADDR__SHIFT                        0x00000003

// AIC_PT_BASE
#define	AIC_PT_BASE__AIC_PT_BASE_LO__SHIFT                 0x0000000c

// AIC_TLB_DATA
#define	AIC_TLB_DATA__AIC_TLB_DATA_LO__SHIFT               0x0000000c

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

// MEM_BASE_LO
#define	MEM_BASE_LO__BLOCK_MEM_BIT__SHIFT                  0x00000000
#define	MEM_BASE_LO__BLOCK_MEM_TYPE__SHIFT                 0x00000001
#define	MEM_BASE_LO__PFTCH_MEM_EN__SHIFT                   0x00000003
#define	MEM_BASE_LO__MEM_BASE_LO__SHIFT                    0x00000019

// MEM_BASE_HI
#define	MEM_BASE_HI__MEM_BASE_HI__SHIFT                    0x00000000

// REG_BASE_LO
#define	REG_BASE_LO__BLOCK_REG_BIT__SHIFT                  0x00000000
#define	REG_BASE_LO__BLOCK_REG_TYPE__SHIFT                 0x00000001
#define	REG_BASE_LO__PFTCH_REG_EN__SHIFT                   0x00000003
#define	REG_BASE_LO__REG_BASE_LO__SHIFT                    0x00000010

// REG_BASE_HI
#define	REG_BASE_HI__REG_BASE_HI__SHIFT                    0x00000000

// IO_BASE_WS
#define	IO_BASE_WS__BLOCK_IO_BIT__SHIFT                    0x00000000
#define	IO_BASE_WS__IO_BASE__SHIFT                         0x00000008

// MEM_BASE
#define	MEM_BASE__BLOCK_MEM_BIT__SHIFT                     0x00000000
#define	MEM_BASE__BLOCK_MEM_TYPE__SHIFT                    0x00000001
#define	MEM_BASE__PFTCH_MEM_EN__SHIFT                      0x00000003
#define	MEM_BASE__MEM_BASE__SHIFT                          0x00000019

// IO_BASE
#define	IO_BASE__BLOCK_IO_BIT_R3__SHIFT                    0x00000000
#define	IO_BASE__IO_BASE__SHIFT                            0x00000008

// REG_BASE
#define	REG_BASE__BLOCK_REG_BIT__SHIFT                     0x00000000
#define	REG_BASE__BLOCK_REG_TYPE__SHIFT                    0x00000001
#define	REG_BASE__PFTCH_REG_EN__SHIFT                      0x00000003
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

// MSI_CAP_ID
#define	MSI_CAP_ID__MSI_CAP_ID__SHIFT                      0x00000000

// MSI_NXT_CAP_PTR
#define	MSI_NXT_CAP_PTR__MSI_NXT_CAP_PTR__SHIFT            0x00000000

// MSI_MSG_CNTL
#define	MSI_MSG_CNTL__MSI_ENABLE__SHIFT                    0x00000000
#define	MSI_MSG_CNTL__MSI_MULTMSG_CAP__SHIFT               0x00000001
#define	MSI_MSG_CNTL__MSI_MULTMSG_EN__SHIFT                0x00000004
#define	MSI_MSG_CNTL__MSI_64BIT__SHIFT                     0x00000007

// MSI_MSG_ADDR_LO
#define	MSI_MSG_ADDR_LO__MSI_MSG_ADDR_LO__SHIFT            0x00000002

// MSI_MSG_ADDR_HI
#define	MSI_MSG_ADDR_HI__MSI_MSG_ADDR_HI__SHIFT            0x00000000

// MSI_MSG_DATA_64
#define	MSI_MSG_DATA_64__MSI_DATA__SHIFT                   0x00000000

// MSI_MSG_ADDR
#define	MSI_MSG_ADDR__MSI_MSG_ADDR__SHIFT                  0x00000002

// MSI_MSG_DATA
#define	MSI_MSG_DATA__MSI_DATA__SHIFT                      0x00000000

// F1_VENDOR_ID
#define	F1_VENDOR_ID_R3__F1_VENDOR_ID__SHIFT               0x00000000

// F1_DEVICE_ID
#define	F1_DEVICE_ID_R3__F1_DEVICE_ID__SHIFT               0x00000000

// F1_COMMAND
#define	F1_COMMAND_R3__F1_IO_ACCESS_EN__SHIFT              0x00000000
#define	F1_COMMAND_R3__F1_MEM_ACCESS_EN__SHIFT             0x00000001
#define	F1_COMMAND_R3__F1_BUS_MASTER_EN__SHIFT             0x00000002
#define	F1_COMMAND_R3__F1_FAST_B2B_EN__SHIFT               0x00000009

// F1_STATUS
#define	F1_STATUS_R3__F1_CAP_LIST__SHIFT                   0x00000004
#define	F1_STATUS_R3__F1_PCI_66_EN__SHIFT                  0x00000005
#define	F1_STATUS_R3__F1_UDF_EN__SHIFT                     0x00000006
#define	F1_STATUS_R3__F1_FAST_BACK_CAPABLE__SHIFT          0x00000007
#define	F1_STATUS_R3__F1_DEVSEL_TIMING__SHIFT              0x00000009
#define	F1_STATUS_R3__F1_SIGNAL_TARGET_ABORT__SHIFT        0x0000000b
#define	F1_STATUS_R3__F1_RECEIVED_TARGET_ABORT__SHIFT      0x0000000c
#define	F1_STATUS_R3__F1_RECEIVED_MASTER_ABORT__SHIFT      0x0000000d
#define	F1_STATUS_R3__F1_PARITY_ERROR_DETECTED__SHIFT      0x0000000f

// F1_REVISION_ID
#define	F1_REVISION_ID_R3__F1_MINOR_REV_ID__SHIFT          0x00000000
#define	F1_REVISION_ID_R3__F1_MAJOR_REV_ID__SHIFT          0x00000004

// F1_REGPROG_INF
#define	F1_REGPROG_INF_R3__F1_REG_LEVEL_PROG_INF__SHIFT    0x00000000

// F1_SUB_CLASS
#define	F1_SUB_CLASS_R3__F1_SUB_CLASS_INF__SHIFT           0x00000007

// F1_BASE_CODE
#define	F1_BASE_CODE_R3__F1_BASE_CLASS_CODE__SHIFT         0x00000000

// F1_CACHE_LINE
#define	F1_CACHE_LINE_R3__F1_CACHE_LINE_SIZE__SHIFT        0x00000000

// F1_LATENCY
#define	F1_LATENCY_R3__F1_LATENCY_TIMER__SHIFT             0x00000000

// F1_HEADER
#define	F1_HEADER_R3__F1_HEADER_TYPE__SHIFT                0x00000000
#define	F1_HEADER_R3__F1_DEVICE_TYPE__SHIFT                0x00000007

// F1_BIST
#define	F1_BIST_R3__F1_BIST_COMP__SHIFT                    0x00000000
#define	F1_BIST_R3__F1_BIST_STRT__SHIFT                    0x00000006
#define	F1_BIST_R3__F1_BIST_CAP__SHIFT                     0x00000007

// F1_MEM_BASE_LO
#define	F1_MEM_BASE_LO__F1_BLOCK_MEM_BIT__SHIFT            0x00000000
#define	F1_MEM_BASE_LO__F1_BLOCK_MEM_TYPE__SHIFT           0x00000001
#define	F1_MEM_BASE_LO__F1_PFTCH_MEM_EN__SHIFT             0x00000003
#define	F1_MEM_BASE_LO__F1_MEM_BASE_LO__SHIFT              0x00000019

// F1_MEM_BASE_HI
#define	F1_MEM_BASE_HI__F1_MEM_BASE_HI__SHIFT              0x00000000

// F1_REG_BASE_LO
#define	F1_REG_BASE_LO__F1_BLOCK_REG_BIT__SHIFT            0x00000000
#define	F1_REG_BASE_LO__F1_BLOCK_REG_TYPE__SHIFT           0x00000001
#define	F1_REG_BASE_LO__F1_PFTCH_REG_EN__SHIFT             0x00000003
#define	F1_REG_BASE_LO__F1_REG_BASE_LO__SHIFT              0x00000010

// F1_REG_BASE_HI
#define	F1_REG_BASE_HI__F1_REG_BASE_HI__SHIFT              0x00000000

// F1_MEM_BASE
#define	F1_MEM_BASE_R3__F1_BLOCK_MEM_BIT__SHIFT            0x00000000
#define	F1_MEM_BASE_R3__F1_BLOCK_MEM_TYPE__SHIFT           0x00000001
#define	F1_MEM_BASE_R3__F1_PFTCH_MEM_EN__SHIFT             0x00000003
#define	F1_MEM_BASE_R3__F1_MEM_BASE__SHIFT                 0x00000019

// F1_REG_BASE
#define	F1_REG_BASE_R3__F1_BLOCK_REG_BIT__SHIFT            0x00000000
#define	F1_REG_BASE_R3__F1_BLOCK_REG_TYPE__SHIFT           0x00000001
#define	F1_REG_BASE_R3__F1_PFTCH_REG_EN__SHIFT             0x00000003
#define	F1_REG_BASE_R3__F1_REG_BASE__SHIFT                 0x00000010

// F1_ADAPTER_ID
#define	F1_ADAPTER_ID_R3__F1_SUBSYSTEM_VENDOR_ID__SHIFT    0x00000000
#define	F1_ADAPTER_ID_R3__F1_SUBSYSTEM_ID__SHIFT           0x00000010

// F1_CAPABILITIES_PTR
#define	F1_CAPABILITIES_PTR_R3__F1_CAP_PTR__SHIFT          0x00000000

// F1_INTERRUPT_LINE
#define	F1_INTERRUPT_LINE_R3__F1_INTERRUPT_LINE__SHIFT     0x00000000

// F1_INTERRUPT_PIN
#define	F1_INTERRUPT_PIN_R3__F1_INTERRUPT_PIN__SHIFT       0x00000000

// F1_MIN_GRANT
#define	F1_MIN_GRANT_R3__F1_MIN_GNT__SHIFT                 0x00000000

// F1_MAX_LATENCY
#define	F1_MAX_LATENCY_R3__F1_MAX_LAT__SHIFT               0x00000000

// F1_PMI_CAP_ID
#define	F1_PMI_CAP_ID_R3__F1_PMI_CAP_ID__SHIFT             0x00000000

// F1_PMI_NXT_CAP_PTR
#define	F1_PMI_NXT_CAP_PTR_R3__F1_PMI_NXT_CAP_PTR__SHIFT   0x00000000

// F1_PMI_PMC_REG
#define	F1_PMI_PMC_REG_R3__F1_PMI_VERSION__SHIFT           0x00000000
#define	F1_PMI_PMC_REG_R3__F1_PMI_PME_CLOCK__SHIFT         0x00000003
#define	F1_PMI_PMC_REG_R3__F1_PMI_DEV_SPECIFIC_INIT__SHIFT 0x00000005
#define	F1_PMI_PMC_REG_R3__F1_PMI_D1_SUPPORT__SHIFT        0x00000009
#define	F1_PMI_PMC_REG_R3__F1_PMI_D2_SUPPORT__SHIFT        0x0000000a
#define	F1_PMI_PMC_REG_R3__F1_PMI_PME_SUPPORT__SHIFT       0x0000000b

// F1_PM_STATUS
#define	F1_PM_STATUS_R3__F1_PMI_POWER_STATE__SHIFT         0x00000000
#define	F1_PM_STATUS_R3__F1_PMI_PME_EN__SHIFT              0x00000008
#define	F1_PM_STATUS_R3__F1_PMI_DATA_SELECT__SHIFT         0x00000009
#define	F1_PM_STATUS_R3__F1_PMI_DATA_SCALE__SHIFT          0x0000000d
#define	F1_PM_STATUS_R3__F1_PMI_PME_STATUS__SHIFT          0x0000000f

// F1_PMI_DATA
#define	F1_PMI_DATA_R3__F1_PMI_DATA__SHIFT                 0x00000000

// F1_AGP_CAP_ID
#define	F1_AGP_CAP_ID_R3__F1_CAP_ID__SHIFT                 0x00000000
#define	F1_AGP_CAP_ID_R3__F1_NEXT_PTR__SHIFT               0x00000008
#define	F1_AGP_CAP_ID_R3__F1_AGP_MINOR__SHIFT              0x00000010
#define	F1_AGP_CAP_ID_R3__F1_AGP_MAJOR__SHIFT              0x00000014

// F1_AGP_STATUS
#define	F1_AGP_STATUS_R3__F1_RATE1X_4X__SHIFT              0x00000000
#define	F1_AGP_STATUS_R3__F1_RATE2X_8X__SHIFT              0x00000001
#define	F1_AGP_STATUS_R3__F1_RATE4X__SHIFT                 0x00000002
#define	F1_AGP_STATUS_R3__F1_MODE_AGP30__SHIFT             0x00000003
#define	F1_AGP_STATUS_R3__F1_FW__SHIFT                     0x00000004
#define	F1_AGP_STATUS_R3__F1_MODE_4G__SHIFT                0x00000005
#define	F1_AGP_STATUS_R3__F1_SBA__SHIFT                    0x00000009
#define	F1_AGP_STATUS_R3__F1_CAL_CYCLE__SHIFT              0x0000000a
#define	F1_AGP_STATUS_R3__F1_ISOCH_SUPPORT__SHIFT          0x00000011
#define	F1_AGP_STATUS_R3__F1_RQ__SHIFT                     0x00000018

// F1_AGP_COMMAND
#define	F1_AGP_COMMAND_R3__F1_DATA_RATE__SHIFT             0x00000000
#define	F1_AGP_COMMAND_R3__F1_FW_EN__SHIFT                 0x00000004
#define	F1_AGP_COMMAND_R3__F1_MODE_4G_EN__SHIFT            0x00000005
#define	F1_AGP_COMMAND_R3__F1_AGP_EN__SHIFT                0x00000008
#define	F1_AGP_COMMAND_R3__F1_SBA_EN__SHIFT                0x00000009
#define	F1_AGP_COMMAND_R3__F1_PARQSZ__SHIFT                0x0000000d
#define	F1_AGP_COMMAND_R3__F1_RQ_DEPTH__SHIFT              0x00000018

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
#define	CRTC_GEN_CNTL__CRTC_MODE9_COLOR_ORDER__SHIFT       0x0000000c
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
#define	DAC_CNTL__DAC_TVO_EN__SHIFT                        0x0000000a
#define	DAC_CNTL__DAC_CRC_BLANKb_ONLY__SHIFT               0x0000000b
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
#define	SURFACE0_INFO__SURF0_PITCHSEL_R3__SHIFT            0x00000000
#define	SURFACE0_INFO__SURF0_TILE_MODE_R2__SHIFT           0x00000010
#define	SURFACE0_INFO__SURF0_AP0_SWP__SHIFT                0x00000014
#define	SURFACE0_INFO__SURF0_AP1_SWP__SHIFT                0x00000016
#define	SURFACE0_INFO__SURF0_WRITE_FLAG__SHIFT             0x00000018
#define	SURFACE0_INFO__SURF0_READ_FLAG__SHIFT              0x00000019

// SURFACE1_INFO
#define	SURFACE1_INFO__SURF1_PITCHSEL_R3__SHIFT            0x00000000
#define	SURFACE1_INFO__SURF1_TILE_MODE_R2__SHIFT           0x00000010
#define	SURFACE1_INFO__SURF1_AP0_SWP__SHIFT                0x00000014
#define	SURFACE1_INFO__SURF1_AP1_SWP__SHIFT                0x00000016
#define	SURFACE1_INFO__SURF1_WRITE_FLAG__SHIFT             0x00000018
#define	SURFACE1_INFO__SURF1_READ_FLAG__SHIFT              0x00000019

// SURFACE2_INFO
#define	SURFACE2_INFO__SURF2_PITCHSEL_R3__SHIFT            0x00000000
#define	SURFACE2_INFO__SURF2_TILE_MODE_R2__SHIFT           0x00000010
#define	SURFACE2_INFO__SURF2_AP0_SWP__SHIFT                0x00000014
#define	SURFACE2_INFO__SURF2_AP1_SWP__SHIFT                0x00000016
#define	SURFACE2_INFO__SURF2_WRITE_FLAG__SHIFT             0x00000018
#define	SURFACE2_INFO__SURF2_READ_FLAG__SHIFT              0x00000019

// SURFACE3_INFO
#define	SURFACE3_INFO__SURF3_PITCHSEL_R3__SHIFT            0x00000000
#define	SURFACE3_INFO__SURF3_TILE_MODE_R2__SHIFT           0x00000010
#define	SURFACE3_INFO__SURF3_AP0_SWP__SHIFT                0x00000014
#define	SURFACE3_INFO__SURF3_AP1_SWP__SHIFT                0x00000016
#define	SURFACE3_INFO__SURF3_WRITE_FLAG__SHIFT             0x00000018
#define	SURFACE3_INFO__SURF3_READ_FLAG__SHIFT              0x00000019

// SURFACE4_INFO
#define	SURFACE4_INFO__SURF4_PITCHSEL_R3__SHIFT            0x00000000
#define	SURFACE4_INFO__SURF4_TILE_MODE_R2__SHIFT           0x00000010
#define	SURFACE4_INFO__SURF4_AP0_SWP__SHIFT                0x00000014
#define	SURFACE4_INFO__SURF4_AP1_SWP__SHIFT                0x00000016
#define	SURFACE4_INFO__SURF4_WRITE_FLAG__SHIFT             0x00000018
#define	SURFACE4_INFO__SURF4_READ_FLAG__SHIFT              0x00000019

// SURFACE5_INFO
#define	SURFACE5_INFO__SURF5_PITCHSEL_R3__SHIFT            0x00000000
#define	SURFACE5_INFO__SURF5_TILE_MODE_R2__SHIFT           0x00000010
#define	SURFACE5_INFO__SURF5_AP0_SWP__SHIFT                0x00000014
#define	SURFACE5_INFO__SURF5_AP1_SWP__SHIFT                0x00000016
#define	SURFACE5_INFO__SURF5_WRITE_FLAG__SHIFT             0x00000018
#define	SURFACE5_INFO__SURF5_READ_FLAG__SHIFT              0x00000019

// SURFACE6_INFO
#define	SURFACE6_INFO__SURF6_PITCHSEL_R3__SHIFT            0x00000000
#define	SURFACE6_INFO__SURF6_TILE_MODE_R2__SHIFT           0x00000010
#define	SURFACE6_INFO__SURF6_AP0_SWP__SHIFT                0x00000014
#define	SURFACE6_INFO__SURF6_AP1_SWP__SHIFT                0x00000016
#define	SURFACE6_INFO__SURF6_WRITE_FLAG__SHIFT             0x00000018
#define	SURFACE6_INFO__SURF6_READ_FLAG__SHIFT              0x00000019

// SURFACE7_INFO
#define	SURFACE7_INFO__SURF7_PITCHSEL_R3__SHIFT            0x00000000
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
#define	VCLK_ECP_CNTL__PCICLK_INVERT__SHIFT                0x00000005
#define	VCLK_ECP_CNTL__PIXCLK_ALWAYS_ONb__SHIFT            0x00000006
#define	VCLK_ECP_CNTL__PIXCLK_DAC_ALWAYS_ONb__SHIFT        0x00000007
#define	VCLK_ECP_CNTL__ECP_DIV__SHIFT                      0x00000008
#define	VCLK_ECP_CNTL__BYTE_CLK_POST_DIV__SHIFT            0x00000010
#define	VCLK_ECP_CNTL__ECP_FORCE_ON__SHIFT                 0x00000012
#define	VCLK_ECP_CNTL__SUBCLK_FORCE_ON__SHIFT              0x00000013
#define	VCLK_ECP_CNTL__BYTE_CLK_OUT_EN__SHIFT              0x00000014
#define	VCLK_ECP_CNTL__DISP_DAC_PIXCLK_DAC_BLANK_OFF__SHIFT 0x00000017
#define	VCLK_ECP_CNTL__BYTE_CLK_SKEW__SHIFT                0x00000018
#define	VCLK_ECP_CNTL__PIXCLK_SRC_INVERT_R3__SHIFT         0x0000001b

// BYTE_CLK_AUX_CNTL
#define	BYTE_CLK_AUX_CNTL__IO_BYTCLK_SRC_SEL__SHIFT        0x00000000
#define	BYTE_CLK_AUX_CNTL__TV_BYTCLK_SRC_SEL__SHIFT        0x00000002
#define	BYTE_CLK_AUX_CNTL__IO_BYTCLK_SKW_CTL__SHIFT        0x00000004
#define	BYTE_CLK_AUX_CNTL__TV_BYTCLK_SKW_CTL__SHIFT        0x00000008

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
#define	DISP_TEST_MACRO_RW_CNTL__TEST_ALTCLK_ENABLE__SHIFT 0x00000012
#define	DISP_TEST_MACRO_RW_CNTL__DISPCLKBLK_CLK_TO_OUTPIN__SHIFT 0x00000013

// PIXCLKS_CNTL
#define	PIXCLKS_CNTL__PIX2CLK_SRC_SEL__SHIFT               0x00000000
#define	PIXCLKS_CNTL__PIX2CLK_INVERT__SHIFT                0x00000004
#define	PIXCLKS_CNTL__PCICLK_INVERT__SHIFT                 0x00000005
#define	PIXCLKS_CNTL__PIX2CLK_ALWAYS_ONb__SHIFT            0x00000006
#define	PIXCLKS_CNTL__PIX2CLK_DAC_ALWAYS_ONb__SHIFT        0x00000007
#define	PIXCLKS_CNTL__PIXCLK_TV_SRC_SEL__SHIFT             0x00000008
#define	PIXCLKS_CNTL__DISP_TVOUT_PIXCLK_TV_ALWAYS_ONb__SHIFT 0x00000009
#define	PIXCLKS_CNTL__DVOCLK_ALWAYS_ONb__SHIFT             0x0000000a
#define	PIXCLKS_CNTL__PIXCLK_BLEND_ALWAYS_ONb__SHIFT       0x0000000b
#define	PIXCLKS_CNTL__PIXCLK_GV_ALWAYS_ONb__SHIFT          0x0000000c
#define	PIXCLKS_CNTL__PIXCLK_DVO_ALWAYS_ONb__SHIFT         0x0000000d
#define	PIXCLKS_CNTL__PIXCLK_LVDS_ALWAYS_ONb__SHIFT        0x0000000e
#define	PIXCLKS_CNTL__PIXCLK_TMDS_ALWAYS_ONb__SHIFT        0x0000000f
#define	PIXCLKS_CNTL__PIXCLK_TRANS_ALWAYS_ONb__SHIFT       0x00000010
#define	PIXCLKS_CNTL__PIXCLK_TVO_ALWAYS_ONb__SHIFT         0x00000011
#define	PIXCLKS_CNTL__P2GCLK_ALWAYS_ONb__SHIFT             0x00000012
#define	PIXCLKS_CNTL__P2G2CLK_ALWAYS_ONb__SHIFT            0x00000013
#define	PIXCLKS_CNTL__DVOCLKC_IN_PHASE__SHIFT              0x00000014
#define	PIXCLKS_CNTL__DVOCLKD_IN_PHASE__SHIFT              0x00000016
#define	PIXCLKS_CNTL__DISP_DAC_PIXCLK_DAC2_BLANK_OFF__SHIFT 0x00000017
#define	PIXCLKS_CNTL__DVOCLKC_SKW_CTL__SHIFT               0x00000018
#define	PIXCLKS_CNTL__DVOCLKD_SKW_CTL__SHIFT               0x0000001c
#define	PIXCLKS_CNTL__PIX2CLK_SRC_INVERT_R3__SHIFT         0x0000001f

// CRTC_STATUS
#define	CRTC_STATUS__CRTC_VBLANK_CUR__SHIFT                0x00000000
#define	CRTC_STATUS__CRTC_VBLANK_SAVE__SHIFT               0x00000001
#define	CRTC_STATUS__CRTC_VBLANK_SAVE_CLEAR__SHIFT         0x00000001
#define	CRTC_STATUS__CRTC_VLINE_SYNC__SHIFT                0x00000002
#define	CRTC_STATUS__CRTC_FRAME__SHIFT                     0x00000003

// GPIO_DDC1
#define	GPIO_DDC1__DDC1_DATA_OUTPUT__SHIFT                 0x00000000
#define	GPIO_DDC1__DDC1_CLK_OUTPUT__SHIFT                  0x00000001
#define	GPIO_DDC1__DDC1_DATA_INPUT__SHIFT                  0x00000008
#define	GPIO_DDC1__DDC1_CLK_INPUT__SHIFT                   0x00000009
#define	GPIO_DDC1__DDC1_DATA_OUT_EN__SHIFT                 0x00000010
#define	GPIO_DDC1__DDC1_CLK_OUT_EN__SHIFT                  0x00000011
#define	GPIO_DDC1__SW_WANTS_TO_USE_DVI_I2C__SHIFT          0x00000014
#define	GPIO_DDC1__SW_CAN_USE_DVI_I2C__SHIFT               0x00000014
#define	GPIO_DDC1__SW_DONE_USING_DVI_I2C__SHIFT            0x00000015
#define	GPIO_DDC1__HDCP_NEEDS_DVI_I2C__SHIFT               0x00000015
#define	GPIO_DDC1__ABORT_HDCP_DVI_I2C__SHIFT               0x00000016
#define	GPIO_DDC1__HW_USING_DVI_I2C__SHIFT                 0x00000016

// GPIO_DDC2
#define	GPIO_DDC2__DDC2_DATA_OUTPUT__SHIFT                 0x00000000
#define	GPIO_DDC2__DDC2_CLK_OUTPUT__SHIFT                  0x00000001
#define	GPIO_DDC2__DDC2_DATA_INPUT__SHIFT                  0x00000008
#define	GPIO_DDC2__DDC2_CLK_INPUT__SHIFT                   0x00000009
#define	GPIO_DDC2__DDC2_DATA_OUT_EN__SHIFT                 0x00000010
#define	GPIO_DDC2__DDC2_CLK_OUT_EN__SHIFT                  0x00000011
#define	GPIO_DDC2__SW_WANTS_TO_USE_DVI_I2C__SHIFT          0x00000014
#define	GPIO_DDC2__SW_CAN_USE_DVI_I2C__SHIFT               0x00000014
#define	GPIO_DDC2__SW_DONE_USING_DVI_I2C__SHIFT            0x00000015
#define	GPIO_DDC2__HDCP_NEEDS_DVI_I2C__SHIFT               0x00000015
#define	GPIO_DDC2__ABORT_HDCP_DVI_I2C__SHIFT               0x00000016
#define	GPIO_DDC2__HW_USING_DVI_I2C__SHIFT                 0x00000016

// GPIO_DDC3
#define	GPIO_DDC3__DDC3_DATA_OUTPUT__SHIFT                 0x00000000
#define	GPIO_DDC3__DDC3_CLK_OUTPUT__SHIFT                  0x00000001
#define	GPIO_DDC3__DDC3_DATA_INPUT__SHIFT                  0x00000008
#define	GPIO_DDC3__DDC3_CLK_INPUT__SHIFT                   0x00000009
#define	GPIO_DDC3__DDC3_DATA_OUT_EN__SHIFT                 0x00000010
#define	GPIO_DDC3__DDC3_CLK_OUT_EN__SHIFT                  0x00000011
#define	GPIO_DDC3__SW_WANTS_TO_USE_DVI_I2C__SHIFT          0x00000014
#define	GPIO_DDC3__SW_CAN_USE_DVI_I2C__SHIFT               0x00000014
#define	GPIO_DDC3__SW_DONE_USING_DVI_I2C__SHIFT            0x00000015
#define	GPIO_DDC3__HDCP_NEEDS_DVI_I2C__SHIFT               0x00000015
#define	GPIO_DDC3__ABORT_HDCP_DVI_I2C__SHIFT               0x00000016
#define	GPIO_DDC3__HW_USING_DVI_I2C__SHIFT                 0x00000016

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

// TIMER_INT_CNTL
#define	TIMER_INT_CNTL__TIMER_INT_CNT__SHIFT               0x00000000
#define	TIMER_INT_CNTL__TIMER_INT_EN__SHIFT                0x0000001e
#define	TIMER_INT_CNTL__TIMER_INT_RUNNING__SHIFT           0x0000001f

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
#define	CRTC_OFFSET_RIGHT__CRTC_OFFSET_RIGHT_R3__SHIFT     0x00000000
#define	CRTC_OFFSET_RIGHT__CRTC_GUI_TRIG_OFFSET__SHIFT     0x0000001e
#define	CRTC_OFFSET_RIGHT__CRTC_OFFSET_LOCK__SHIFT         0x0000001f

// CRTC_OFFSET
#define	CRTC_OFFSET__CRTC_OFFSET_R3__SHIFT                 0x00000000
#define	CRTC_OFFSET__CRTC_GUI_TRIG_OFFSET__SHIFT           0x0000001e
#define	CRTC_OFFSET__CRTC_OFFSET_LOCK__SHIFT               0x0000001f

// CRTC_OFFSET_CNTL
#define	CRTC_OFFSET_CNTL__CRTC_X_Y_MODE_EN_RIGHT__SHIFT    0x00000006
#define	CRTC_OFFSET_CNTL__CRTC_MICRO_TILE_BUFFER_MODE_RIGHT__SHIFT 0x00000007
#define	CRTC_OFFSET_CNTL__CRTC_X_Y_MODE_EN__SHIFT          0x00000009
#define	CRTC_OFFSET_CNTL__CRTC_MICRO_TILE_BUFFER_MODE__SHIFT 0x0000000a
#define	CRTC_OFFSET_CNTL__CRTC_MICRO_TILE_EN_RIGHT__SHIFT  0x0000000c
#define	CRTC_OFFSET_CNTL__CRTC_MICRO_TILE_EN__SHIFT        0x0000000d
#define	CRTC_OFFSET_CNTL__CRTC_MACRO_TILE_EN_RIGHT__SHIFT  0x0000000e
#define	CRTC_OFFSET_CNTL__CRTC_MACRO_TILE_EN__SHIFT        0x0000000f
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

// GRPH_BUFFER_STATUS
#define	GRPH_BUFFER_STATUS__GRPH_LOWEST_BUFFER_LEVEL__SHIFT 0x00000000
#define	GRPH_BUFFER_STATUS__GRPH_LOWEST_BUFFER_LEVEL_RESET__SHIFT 0x00000007
#define	GRPH_BUFFER_STATUS__GRPH2_LOWEST_BUFFER_LEVEL__SHIFT 0x00000008
#define	GRPH_BUFFER_STATUS__GRPH2_LOWEST_BUFFER_LEVEL_RESET__SHIFT 0x0000000f

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
#define	CRTC_MORE_CNTL__DSP_RST_HCOUNT__SHIFT              0x00000008
#define	CRTC_MORE_CNTL__DSP_RST_VCOUNT__SHIFT              0x00000009
#define	CRTC_MORE_CNTL__HCOUNT_RST_POS__SHIFT              0x0000000a
#define	CRTC_MORE_CNTL__VCOUNT_RST_POS__SHIFT              0x0000000b
#define	CRTC_MORE_CNTL__CRTC_FIX_VSYNC_EDGE_POSITION_EN__SHIFT 0x0000000c
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
#define	FP_GEN_CNTL__FP_SOURCE_SEL__SHIFT                  0x0000000a
#define	FP_GEN_CNTL__FP_DETECT_EN__SHIFT                   0x0000000c
#define	FP_GEN_CNTL__HPD_SEL__SHIFT                        0x0000000d
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
#define	FP2_GEN_CNTL__FP2_SOURCE_SEL__SHIFT                0x0000000a
#define	FP2_GEN_CNTL__FP2_LCD_CNTL__SHIFT                  0x00000013
#define	FP2_GEN_CNTL__FP2_PAD_FLOP_EN__SHIFT               0x00000016
#define	FP2_GEN_CNTL__FP2_CRC_EN__SHIFT                    0x00000017
#define	FP2_GEN_CNTL__FP2_CRC_READ_EN__SHIFT               0x00000018
#define	FP2_GEN_CNTL__DVO_EN__SHIFT                        0x00000019
#define	FP2_GEN_CNTL__DVO_TMDS_CTL3__SHIFT                 0x0000001a
#define	FP2_GEN_CNTL__DVO_RATE_SEL__SHIFT                  0x0000001b
#define	FP2_GEN_CNTL__DVO_CLOCK_MODE__SHIFT                0x0000001c
#define	FP2_GEN_CNTL__DVO_DUAL_CHANNEL_EN__SHIFT           0x0000001d
#define	FP2_GEN_CNTL__DVO_TMDS_CTL3_SEL__SHIFT             0x0000001e

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
#define	TMDS_CNTL__TMDS_DC_BALANCING_DISABLE__SHIFT        0x0000000e
#define	TMDS_CNTL__TMDS_DC_BALANCE_FORCE__SHIFT            0x0000000f
#define	TMDS_CNTL__TMDS_SYNC_CHAR_EN__SHIFT                0x00000010
#define	TMDS_CNTL__TMDS_DEBUG_HSYNC_EN__SHIFT              0x00000014
#define	TMDS_CNTL__TMDS_DEBUG_VSYNC_EN__SHIFT              0x00000015
#define	TMDS_CNTL__TMDS_DEBUG_DE_EN__SHIFT                 0x00000016
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
#define	TMDS_TRANSMITTER_CNTL__TMDS_PFREQ_CHANGE__SHIFT    0x0000001f

// TMDS_PLL_CNTL
#define	TMDS_PLL_CNTL__TMDS_PLLPCP_R3__SHIFT               0x00000000
#define	TMDS_PLL_CNTL__TMDS_PLLPVG_R3__SHIFT               0x00000006
#define	TMDS_PLL_CNTL__TMDS_PLLPDC_R3__SHIFT               0x0000000c
#define	TMDS_PLL_CNTL__TMDS_PLLPVS_R3__SHIFT               0x00000010
#define	TMDS_PLL_CNTL__TMDS_LNKCEN__SHIFT                  0x00000014
#define	TMDS_PLL_CNTL__TMDS_LNKDEN__SHIFT                  0x00000015
#define	TMDS_PLL_CNTL__TMDS_DSYNSEL__SHIFT                 0x00000016
#define	TMDS_PLL_CNTL__TMDS_ICLKSEL__SHIFT                 0x00000017
#define	TMDS_PLL_CNTL__TMDS_TPL__SHIFT                     0x00000018
#define	TMDS_PLL_CNTL__TMDS_TXREG_RV3__SHIFT               0x0000001a
#define	TMDS_PLL_CNTL__PLSEL__SHIFT                        0x0000001e
#define	TMDS_PLL_CNTL__PLDIVSEL__SHIFT                     0x0000001f

// TMDS_PATTERN_GEN_SEED
#define	TMDS_PATTERN_GEN_SEED__PATTERN_SEED__SHIFT         0x00000000
#define	TMDS_PATTERN_GEN_SEED__TMDS_RAN_PAT_DURING_DE_ONLY__SHIFT 0x00000018

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

// LVDS_DVO_CRC
#define	LVDS_DVO_CRC__LVDS_DVO_CRC_SIG_RGB__SHIFT          0x00000000
#define	LVDS_DVO_CRC__LVDS_DVO_CRC_SIG_RGB_MASK__SHIFT     0x00000000
#define	LVDS_DVO_CRC__LVDS_DVO_CRC_SIG_C__SHIFT            0x00000018
#define	LVDS_DVO_CRC__LVDS_DVO_CRC_SIG_C_MASK__SHIFT       0x00000018

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
#define	LVDS_GEN_CNTL__LVDS_DIGON__SHIFT                   0x00000012
#define	LVDS_GEN_CNTL__LVDS_BLON__SHIFT                    0x00000013
#define	LVDS_GEN_CNTL__LVDS_FP_POL__SHIFT                  0x00000014
#define	LVDS_GEN_CNTL__LVDS_LP_POL__SHIFT                  0x00000015
#define	LVDS_GEN_CNTL__LVDS_DTM_POL__SHIFT                 0x00000016
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
#define	LVDS_PLL_CNTL__LVDS_SRC_SEL__SHIFT                 0x00000012
#define	LVDS_PLL_CNTL__LVDS_CRC_EN__SHIFT                  0x00000014
#define	LVDS_PLL_CNTL__LVDS_CRC_UP24__SHIFT                0x00000015
#define	LVDS_PLL_CNTL__LVDS_TEST_DATA_OUT__SHIFT           0x00000016
#define	LVDS_PLL_CNTL__LVDS_TEST_DATA_SEL__SHIFT           0x00000019
#define	LVDS_PLL_CNTL__LVDS_PREAMPH_EN_R3__SHIFT           0x0000001b
#define	LVDS_PLL_CNTL__LCDENG_TEST_MODE__SHIFT             0x0000001c

// AUX_WINDOW_HORZ_CNTL
#define	AUX_WINDOW_HORZ_CNTL__AUX_WIN_HORZ_START__SHIFT    0x00000000
#define	AUX_WINDOW_HORZ_CNTL__AUX_WIN_HORZ_END__SHIFT      0x0000000c
#define	AUX_WINDOW_HORZ_CNTL__AUX_WIN_EN__SHIFT            0x00000018
#define	AUX_WINDOW_HORZ_CNTL__AUX_WIN_OUT_DELAY_R2__SHIFT  0x00000019
#define	AUX_WINDOW_HORZ_CNTL__AUX_WIN_LOCK__SHIFT          0x0000001f

// AUX_WINDOW_VERT_CNTL
#define	AUX_WINDOW_VERT_CNTL__AUX_WIN_VERT_START__SHIFT    0x00000000
#define	AUX_WINDOW_VERT_CNTL__GPIO_AUX_WIN_OUT__SHIFT      0x0000000c
#define	AUX_WINDOW_VERT_CNTL__GPIO_AUX_WIN_OUT_EN_RV3__SHIFT   0x0000000d
#define	AUX_WINDOW_VERT_CNTL__GPIO_AUX_WIN_MASK_RV3__SHIFT     0x0000000e
#define	AUX_WINDOW_VERT_CNTL__AUX_WIN_VERT_END__SHIFT      0x00000010
#define	AUX_WINDOW_VERT_CNTL__AUX_WIN_INPUT__SHIFT         0x0000001d
#define	AUX_WINDOW_VERT_CNTL__AUX_WINDOW_POL__SHIFT        0x0000001e
#define	AUX_WINDOW_VERT_CNTL__AUX_WIN_LOCK__SHIFT          0x0000001f

// DVI_I2C_CNTL_0
#define	DVI_I2C_CNTL_0__I2C_DONE__SHIFT                    0x00000000
#define	DVI_I2C_CNTL_0__I2C_NACK__SHIFT                    0x00000001
#define	DVI_I2C_CNTL_0__I2C_HALT__SHIFT                    0x00000002
#define	DVI_I2C_CNTL_0_RV3__DVI_I2C_PIN_SEL__SHIFT         0x00000003
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
#define	DVI_I2C_CNTL_1__I2C_ADDR_COUNT_R2__SHIFT           0x00000004
#define	DVI_I2C_CNTL_1__I2C_INTRA_BYTE_DELAY__SHIFT        0x00000008
#define	DVI_I2C_CNTL_1__I2C_SEL__SHIFT                     0x00000010
#define	DVI_I2C_CNTL_1__I2C_EN__SHIFT                      0x00000011
#define	DVI_I2C_CNTL_1__I2C_TIME_LIMIT__SHIFT              0x00000018

// DVI_I2C_DATA
#define	DVI_I2C_DATA__I2C_DATA__SHIFT                      0x00000000

// LVDS_SS_GEN_CNTL
#define	LVDS_SS_GEN_CNTL__SS_BUF_VERT_SYNC_START_RESET__SHIFT 0x00000000
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
#define	GRPH_BUFFER_CNTL__GRPH_CRITICAL_MODE__SHIFT        0x0000001b
#define	GRPH_BUFFER_CNTL__GRPH_CRITICAL_CNTL__SHIFT        0x0000001c
#define	GRPH_BUFFER_CNTL__GRPH_BUFFER_SIZE__SHIFT          0x0000001d
#define	GRPH_BUFFER_CNTL__GRPH_CRITICAL_AT_SOF__SHIFT      0x0000001e
#define	GRPH_BUFFER_CNTL__GRPH_STOP_CNTL__SHIFT            0x0000001f

// VGA_BUFFER_CNTL
#define	VGA_BUFFER_CNTL__VGA_START_REQ__SHIFT              0x00000000
#define	VGA_BUFFER_CNTL__VGA_STOP_REQ__SHIFT               0x00000008
#define	VGA_BUFFER_CNTL__VGA_CRITICAL_POINT__SHIFT         0x00000010

// LVDS_PWM_CNTL
#define	LVDS_PWM_CNTL__PWM_CLK_CONF__SHIFT                 0x00000000
#define	LVDS_PWM_CNTL__ENA_BL__SHIFT                       0x00000010
#define	LVDS_PWM_CNTL__LVDS_SWAP__SHIFT                    0x00000011
#define	LVDS_PWM_CNTL__LVDS_MACRO_CLK_SHIFT__SHIFT         0x00000012
#define	LVDS_PWM_CNTL__LVDS_2ND_CHAN_VS__SHIFT             0x00000013
#define	LVDS_PWM_CNTL__LVDS_2ND_CHAN_HS__SHIFT             0x00000014
#define	LVDS_PWM_CNTL__LVDS_2ND_CHAN_DE__SHIFT             0x00000015

// LVDS_SYNC_RGEN_CNTL
#define	LVDS_SYNC_RGEN_CNTL__LVDS_SYNC_RGEN_EN__SHIFT      0x00000000
#define	LVDS_SYNC_RGEN_CNTL__LVDS_SYNCRG_FRAME_LOCK__SHIFT 0x00000001
#define	LVDS_SYNC_RGEN_CNTL__LVDS_SYNCRG_RESERVED__SHIFT   0x00000002

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

// CRTC2_OFFSET_RIGHT
#define	CRTC2_OFFSET_RIGHT__CRTC2_OFFSET_RIGHT_R3__SHIFT   0x00000000
#define	CRTC2_OFFSET_RIGHT__CRTC2_GUI_TRIG_OFFSET__SHIFT   0x0000001e
#define	CRTC2_OFFSET_RIGHT__CRTC2_OFFSET_LOCK__SHIFT       0x0000001f

// CRTC2_OFFSET
#define	CRTC2_OFFSET__CRTC2_OFFSET_R3__SHIFT               0x00000000
#define	CRTC2_OFFSET__CRTC2_GUI_TRIG_OFFSET__SHIFT         0x0000001e
#define	CRTC2_OFFSET__CRTC2_OFFSET_LOCK__SHIFT             0x0000001f

// CRTC2_OFFSET_CNTL
#define	CRTC2_OFFSET_CNTL__CRTC2_X_Y_MODE_EN_RIGHT__SHIFT  0x00000008
#define	CRTC2_OFFSET_CNTL__CRTC2_X_Y_MODE_EN__SHIFT        0x00000009
#define	CRTC2_OFFSET_CNTL__CRTC2_MICRO_TILE_EN_RIGHT__SHIFT 0x0000000c
#define	CRTC2_OFFSET_CNTL__CRTC2_MICRO_TILE_EN__SHIFT      0x0000000d
#define	CRTC2_OFFSET_CNTL__CRTC2_MACRO_TILE_EN_RIGHT__SHIFT 0x0000000e
#define	CRTC2_OFFSET_CNTL__CRTC2_MACRO_TILE_EN__SHIFT      0x0000000f
#define	CRTC2_OFFSET_CNTL__CRTC2_OFFSET_FLIP_CNTL__SHIFT   0x00000010
#define	CRTC2_OFFSET_CNTL__CRTC2_STEREO_OFFSET_EN__SHIFT   0x00000011
#define	CRTC2_OFFSET_CNTL__CRTC2_STEREO_SYNC_EN__SHIFT     0x00000012
#define	CRTC2_OFFSET_CNTL__CRTC2_STEREO_SYNC__SHIFT        0x00000015
#define	CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET_LEFT_EN__SHIFT 0x0000001c
#define	CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET_RIGHT_EN__SHIFT 0x0000001d
#define	CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET__SHIFT    0x0000001e
#define	CRTC2_OFFSET_CNTL__CRTC2_OFFSET_LOCK__SHIFT        0x0000001f

// CRTC2_PITCH
#define	CRTC2_PITCH__CRTC2_PITCH__SHIFT                    0x00000000
#define	CRTC2_PITCH__CRTC2_PITCH_RIGHT__SHIFT              0x00000010

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

// CRTC_TILE_X0_Y0
#define	CRTC_TILE_X0_Y0__CRTC_TILE_X0__SHIFT               0x00000000
#define	CRTC_TILE_X0_Y0__CRTC_TILE_Y0__SHIFT               0x00000010
#define	CRTC_TILE_X0_Y0__CRTC_GUI_TRIG_OFFSET__SHIFT       0x0000001e
#define	CRTC_TILE_X0_Y0__CRTC_OFFSET_LOCK__SHIFT           0x0000001f

// CRTC_TILE_X0_Y0_RIGHT
#define	CRTC_TILE_X0_Y0_RIGHT__CRTC_TILE_X0_RIGHT__SHIFT   0x00000000
#define	CRTC_TILE_X0_Y0_RIGHT__CRTC_TILE_Y0_RIGHT__SHIFT   0x00000010
#define	CRTC_TILE_X0_Y0_RIGHT__CRTC_GUI_TRIG_OFFSET__SHIFT 0x0000001e
#define	CRTC_TILE_X0_Y0_RIGHT__CRTC_OFFSET_LOCK__SHIFT     0x0000001f

// CRTC2_TILE_X0_Y0
#define	CRTC2_TILE_X0_Y0__CRTC2_TILE_X0__SHIFT             0x00000000
#define	CRTC2_TILE_X0_Y0__CRTC2_TILE_Y0__SHIFT             0x00000010
#define	CRTC2_TILE_X0_Y0__CRTC2_GUI_TRIG_OFFSET__SHIFT     0x0000001e
#define	CRTC2_TILE_X0_Y0__CRTC2_OFFSET_LOCK__SHIFT         0x0000001f

// CRTC2_TILE_X0_Y0_RIGHT
#define	CRTC2_TILE_X0_Y0_RIGHT__CRTC2_TILE_X0_RIGHT__SHIFT 0x00000000
#define	CRTC2_TILE_X0_Y0_RIGHT__CRTC2_TILE_Y0_RIGHT__SHIFT 0x00000010
#define	CRTC2_TILE_X0_Y0_RIGHT__CRTC2_GUI_TRIG_OFFSET__SHIFT 0x0000001e
#define	CRTC2_TILE_X0_Y0_RIGHT__CRTC2_OFFSET_LOCK__SHIFT   0x0000001f

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

// TMDS_SS_GEN_CNTL
#define	TMDS_SS_GEN_CNTL__TMDS_SS_BUF_EN__SHIFT            0x00000000
#define	TMDS_SS_GEN_CNTL__TMDS_SS_BUF_OFFSET__SHIFT        0x00000001
#define	TMDS_SS_GEN_CNTL__TMDS_SS_BUF_RESET_EN__SHIFT      0x00000008
#define	TMDS_SS_GEN_CNTL__TMDS_SS_BUF_VERT_SYNC_START_RESET__SHIFT 0x00000009

// TMDS_CTL0_1_GEN_CNTL
#define	TMDS_CTL0_1_GEN_CNTL__TMDS_CTL0_DATA_SEL__SHIFT    0x00000000
#define	TMDS_CTL0_1_GEN_CNTL__TMDS_CTL0_DATA_DELAY__SHIFT  0x00000004
#define	TMDS_CTL0_1_GEN_CNTL__TMDS_CTL0_DATA_INVERT__SHIFT 0x00000007
#define	TMDS_CTL0_1_GEN_CNTL__TMDS_CTL0_DATA_MODULATION__SHIFT 0x00000008
#define	TMDS_CTL0_1_GEN_CNTL__TMDS_CTL0_USE_FEEDBACK_PATH__SHIFT 0x0000000a
#define	TMDS_CTL0_1_GEN_CNTL__TMDS_CTL0_FB_SYNC_CONT__SHIFT 0x0000000b
#define	TMDS_CTL0_1_GEN_CNTL__TMDS_CTL0_PATTERN_OUT_EN__SHIFT 0x0000000c
#define	TMDS_CTL0_1_GEN_CNTL__TMDS_CTL1_DATA_SEL__SHIFT    0x00000010
#define	TMDS_CTL0_1_GEN_CNTL__TMDS_CTL1_DATA_DELAY__SHIFT  0x00000014
#define	TMDS_CTL0_1_GEN_CNTL__TMDS_CTL1_DATA_INVERT__SHIFT 0x00000017
#define	TMDS_CTL0_1_GEN_CNTL__TMDS_CTL1_DATA_MODULATION__SHIFT 0x00000018
#define	TMDS_CTL0_1_GEN_CNTL__TMDS_CTL1_USE_FEEDBACK_PATH__SHIFT 0x0000001a
#define	TMDS_CTL0_1_GEN_CNTL__TMDS_CTL1_FB_SYNC_CONT__SHIFT 0x0000001b
#define	TMDS_CTL0_1_GEN_CNTL__TMDS_CTL1_PATTERN_OUT_EN__SHIFT 0x0000001c
#define	TMDS_CTL0_1_GEN_CNTL__TMDS_2BIT_COUNTER_EN__SHIFT  0x0000001f

// TMDS_CTL2_3_GEN_CNTL
#define	TMDS_CTL2_3_GEN_CNTL__TMDS_CTL2_DATA_SEL__SHIFT    0x00000000
#define	TMDS_CTL2_3_GEN_CNTL__TMDS_CTL2_DATA_DELAY__SHIFT  0x00000004
#define	TMDS_CTL2_3_GEN_CNTL__TMDS_CTL2_DATA_INVERT__SHIFT 0x00000007
#define	TMDS_CTL2_3_GEN_CNTL__TMDS_CTL2_DATA_MODULATION__SHIFT 0x00000008
#define	TMDS_CTL2_3_GEN_CNTL__TMDS_CTL2_USE_FEEDBACK_PATH__SHIFT 0x0000000a
#define	TMDS_CTL2_3_GEN_CNTL__TMDS_CTL2_FB_SYNC_CONT__SHIFT 0x0000000b
#define	TMDS_CTL2_3_GEN_CNTL__TMDS_CTL2_PATTERN_OUT_EN__SHIFT 0x0000000c
#define	TMDS_CTL2_3_GEN_CNTL__TMDS_CTL3_DATA_SEL__SHIFT    0x00000010
#define	TMDS_CTL2_3_GEN_CNTL__TMDS_CTL3_DATA_DELAY__SHIFT  0x00000014
#define	TMDS_CTL2_3_GEN_CNTL__TMDS_CTL3_DATA_INVERT__SHIFT 0x00000017
#define	TMDS_CTL2_3_GEN_CNTL__TMDS_CTL3_DATA_MODULATION__SHIFT 0x00000018
#define	TMDS_CTL2_3_GEN_CNTL__TMDS_CTL3_USE_FEEDBACK_PATH__SHIFT 0x0000001a
#define	TMDS_CTL2_3_GEN_CNTL__TMDS_CTL3_FB_SYNC_CONT__SHIFT 0x0000001b
#define	TMDS_CTL2_3_GEN_CNTL__TMDS_CTL3_PATTERN_OUT_EN__SHIFT 0x0000001c

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

// FP_H2_SYNC_STRT_WID
#define	FP_H2_SYNC_STRT_WID__FP_H2_SYNC_STRT_PIX__SHIFT    0x00000000
#define	FP_H2_SYNC_STRT_WID__FP_H2_SYNC_STRT_CHAR__SHIFT   0x00000003
#define	FP_H2_SYNC_STRT_WID__FP_H2_SYNC_WID__SHIFT         0x00000010
#define	FP_H2_SYNC_STRT_WID__FP_H2_SYNC_POL__SHIFT         0x00000017

// FP_V2_SYNC_STRT_WID
#define	FP_V2_SYNC_STRT_WID__FP_V2_SYNC_STRT__SHIFT        0x00000000
#define	FP_V2_SYNC_STRT_WID__FP_V2_SYNC_WID__SHIFT         0x00000010
#define	FP_V2_SYNC_STRT_WID__FP_V2_SYNC_POL__SHIFT         0x00000017

// GRPH2_BUFFER_CNTL
#define	GRPH2_BUFFER_CNTL__GRPH2_START_REQ__SHIFT          0x00000000
#define	GRPH2_BUFFER_CNTL__GRPH2_STOP_REQ__SHIFT           0x00000008
#define	GRPH2_BUFFER_CNTL__GRPH2_CRITICAL_POINT__SHIFT     0x00000010
#define	GRPH2_BUFFER_CNTL__GRPH2_CRITICAL_MODE__SHIFT      0x0000001b
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
#define	CRTC2_GEN_CNTL__CRTC2_MODE9_COLOR_ORDER__SHIFT     0x0000000c
#define	CRTC2_GEN_CNTL__CRTC2_ICON_EN__SHIFT               0x0000000f
#define	CRTC2_GEN_CNTL__CRTC2_CUR_EN__SHIFT                0x00000010
#define	CRTC2_GEN_CNTL__CRTC2_CUR_MODE__SHIFT              0x00000014
#define	CRTC2_GEN_CNTL__CRTC2_DISPLAY_DIS__SHIFT           0x00000017
#define	CRTC2_GEN_CNTL__CRTC2_EN__SHIFT                    0x00000019
#define	CRTC2_GEN_CNTL__CRTC2_DISP_REQ_EN_B__SHIFT         0x0000001a
#define	CRTC2_GEN_CNTL__CRTC2_C_SYNC_EN__SHIFT             0x0000001b
#define	CRTC2_GEN_CNTL__CRTC2_HSYNC_DIS__SHIFT             0x0000001c
#define	CRTC2_GEN_CNTL__CRTC2_VSYNC_DIS__SHIFT             0x0000001d
#define	CRTC2_GEN_CNTL__CRTC2_FIX_VSYNC_EDGE_POSITION_EN__SHIFT 0x0000001e

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
#define	OV0_SCALE_CNTL__OV0_FULL_BYPASS__SHIFT             0x00000005
#define	OV0_SCALE_CNTL__OV0_DYNAMIC_EXT__SHIFT             0x00000006
#define	OV0_SCALE_CNTL__OV0_RGB30_ON__SHIFT                0x00000007
#define	OV0_SCALE_CNTL__OV0_SURFACE_FORMAT__SHIFT          0x00000008
#define	OV0_SCALE_CNTL__OV0_ADAPTIVE_DEINT__SHIFT          0x0000000c
#define	OV0_SCALE_CNTL__OV0_TEMPORAL_DEINT__SHIFT          0x0000000d
#define	OV0_SCALE_CNTL__OV0_CRTC_SEL__SHIFT                0x0000000e
#define	OV0_SCALE_CNTL__OV0_PULLDOWN_ON_P1_ONLY__SHIFT     0x0000000f
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
#define	OV0_VID_BUF0_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_R3__SHIFT 0x00000004
#define	OV0_VID_BUF0_BASE_ADRS__RESERVED_BIT31_28__SHIFT   0x0000001c

// OV0_VID_BUF1_BASE_ADRS
#define	OV0_VID_BUF1_BASE_ADRS__OV0_VID_BUF_PITCH_SEL__SHIFT 0x00000000
#define	OV0_VID_BUF1_BASE_ADRS__RESERVED_BIT1__SHIFT       0x00000001
#define	OV0_VID_BUF1_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_R3__SHIFT 0x00000004
#define	OV0_VID_BUF1_BASE_ADRS__RESERVED_BIT31_28__SHIFT   0x0000001c

// OV0_VID_BUF2_BASE_ADRS
#define	OV0_VID_BUF2_BASE_ADRS__OV0_VID_BUF_PITCH_SEL__SHIFT 0x00000000
#define	OV0_VID_BUF2_BASE_ADRS__RESERVED_BIT1__SHIFT       0x00000001
#define	OV0_VID_BUF2_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_R3__SHIFT 0x00000004
#define	OV0_VID_BUF2_BASE_ADRS__RESERVED_BIT31_28__SHIFT   0x0000001c

// OV0_VID_BUF3_BASE_ADRS
#define	OV0_VID_BUF3_BASE_ADRS__OV0_VID_BUF_PITCH_SEL__SHIFT 0x00000000
#define	OV0_VID_BUF3_BASE_ADRS__RESERVED_BIT1__SHIFT       0x00000001
#define	OV0_VID_BUF3_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_R3__SHIFT 0x00000004
#define	OV0_VID_BUF3_BASE_ADRS__RESERVED_BIT31_28__SHIFT   0x0000001c

// OV0_VID_BUF4_BASE_ADRS
#define	OV0_VID_BUF4_BASE_ADRS__OV0_VID_BUF_PITCH_SEL__SHIFT 0x00000000
#define	OV0_VID_BUF4_BASE_ADRS__RESERVED_BIT1__SHIFT       0x00000001
#define	OV0_VID_BUF4_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_R3__SHIFT 0x00000004
#define	OV0_VID_BUF4_BASE_ADRS__RESERVED_BIT31_28__SHIFT   0x0000001c

// OV0_VID_BUF5_BASE_ADRS
#define	OV0_VID_BUF5_BASE_ADRS__OV0_VID_BUF_PITCH_SEL__SHIFT 0x00000000
#define	OV0_VID_BUF5_BASE_ADRS__RESERVED_BIT1__SHIFT       0x00000001
#define	OV0_VID_BUF5_BASE_ADRS__OV0_VID_BUF_BASE_ADRS_R3__SHIFT 0x00000004
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
#define	OV0_DEINTERLACE_PATTERN__OV0_DEINT_PAT_R2__SHIFT   0x00000000
#define	OV0_DEINTERLACE_PATTERN__OV0_DEINT_PAT_PNTR_R2__SHIFT 0x00000018
#define	OV0_DEINTERLACE_PATTERN__OV0_DEINT_PAT_LEN_M1_R2__SHIFT 0x0000001c

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
#define	OV0_TEST__OV0_SUBPIC_ONLY__SHIFT                   0x00000003
#define	OV0_TEST__OV0_SWAP_UV__SHIFT                       0x00000005
#define	OV0_TEST__OV0_NOROUNDUP__SHIFT                     0x00000006
#define	OV0_TEST__OV0_4TH_LINE_RULE_EN__SHIFT              0x00000008
#define	OV0_TEST__OV0_DEINT_PAT_POST_INC_EN__SHIFT         0x00000009
#define	OV0_TEST__OV0_READ_BEHIND_SCAN_MARGIN__SHIFT       0x00000010

// OV0_32PULLDOWN_ACCUM
#define	OV0_32PULLDOWN_ACCUM__OV0_32PULLDOWN_ACCUM__SHIFT  0x00000000
#define	OV0_32PULLDOWN_ACCUM__OV0_32PULLDOWN_ACCUM_VALID__SHIFT 0x0000001e
#define	OV0_32PULLDOWN_ACCUM__OV0_32PULLDOWN_ACCUM_SKIPPED__SHIFT 0x0000001f

// OV0_TEMPORAL_DEINT_CNTL
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_EN__SHIFT         0x00000000
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_CLEAR_FIFO__SHIFT     0x00000001
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_ACCUM_FORCE__SHIFT 0x00000002
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_DEINT_LATEST_SUBMITS__SHIFT 0x00000003
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_UNDERFLOW_RECOVERY_MODE__SHIFT 0x00000004
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_NO_DTO_RESET_ON_OVERFLOW__SHIFT 0x00000006
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_ACCUM_OVERFLOW_EN__SHIFT 0x00000007
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_FORCE_ON_POL_PAIR__SHIFT 0x00000008
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_LOCK__SHIFT       0x0000000a
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_HDE_DIVIDE_BY__SHIFT  0x0000000c
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_AUTO_DTO_LOOP_EN__SHIFT 0x0000000e
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_USE_SOFT_DEINT_ALPHA__SHIFT 0x0000000f
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_SOFT_DEINT_ALPHA__SHIFT 0x00000010
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_INVERT_ALPHA__SHIFT   0x00000015
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_SOURCE_CHANGED__SHIFT 0x00000017
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_FILLED__SHIFT    0x00000018
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_READ_PNTR__SHIFT 0x00000019
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_DTO_ACCUM_LOADED__SHIFT 0x0000001c
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_UNDERFLOW__SHIFT 0x0000001e
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_UNDERFLOW_CLR__SHIFT 0x0000001e
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_OVERFLOW__SHIFT  0x0000001f
#define	OV0_TEMPORAL_DEINT_CNTL__OV0_FIFO_OVERFLOW_CLR__SHIFT 0x0000001f

// OV0_DTO_ACCUM_0
#define	OV0_DTO_ACCUM_0__OV0_DTO_ACCUM_INIT__SHIFT         0x00000000

// OV0_DTO_ACCUM_1
#define	OV0_DTO_ACCUM_1__OV0_ACCUM_POL_PAIR_VAL__SHIFT     0x00000000

// OV0_DTO_ACCUM_2
#define	OV0_DTO_ACCUM_2__OV0_DTO_ACCUM__SHIFT              0x00000000

// OV0_DTO_INC
#define	OV0_DTO_INC__OV0_DTO_INC__SHIFT                    0x00000000
#define	OV0_DTO_INC__OV0_DTO_INC_ADJ__SHIFT                0x00000010

// OV0_ADAPTIVE_DEINT_OFFSET
#define	OV0_ADAPTIVE_DEINT_OFFSET__OV0_BP_OFFSET__SHIFT    0x00000000
#define	OV0_ADAPTIVE_DEINT_OFFSET__OV0_4TH_LINE_RULE_OFFSET__SHIFT 0x00000004

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
#define	DISP_MISC_CNTL__SOFT_RESET_TV_R2__SHIFT            0x0000000b
#define	DISP_MISC_CNTL__SOFT_RESET_GRPH2_PP__SHIFT         0x0000000c
#define	DISP_MISC_CNTL__SOFT_RESET_GRPH2_SCLK__SHIFT       0x0000000f
#define	DISP_MISC_CNTL__SOFT_RESET_LVDS__SHIFT             0x00000010
#define	DISP_MISC_CNTL__SOFT_RESET_TMDS__SHIFT             0x00000011
#define	DISP_MISC_CNTL__SOFT_RESET_DVO__SHIFT              0x00000012
#define	DISP_MISC_CNTL__SOFT_RESET_HDCP__SHIFT             0x00000013
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
#define	DISP_PWR_MAN__DISP_DVO_ENABLE_RST__SHIFT           0x00000018
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
#define	DISP_TEST_DEBUG_CNTL__DISP_TEST_DAC2__SHIFT        0x0000000a
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
#define	DISP_HW_DEBUG__DISP_HW_5_DEBUG__SHIFT              0x00000005
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
#define	DISP_HW_DEBUG__DISP_HW_12_DEBUG__SHIFT             0x00000012
#define	DISP_HW_DEBUG__DISP_HW_13_DEBUG__SHIFT             0x00000013
#define	DISP_HW_DEBUG__DISP_HW_19_DEBUG__SHIFT             0x00000019
#define	DISP_HW_DEBUG__DISP_HW_1A_DEBUG__SHIFT             0x0000001a
#define	DISP_HW_DEBUG__DISP_HW_1B_DEBUG__SHIFT             0x0000001b
#define	DISP_HW_DEBUG__DISP_HW_1C_DEBUG__SHIFT             0x0000001c
#define	DISP_HW_DEBUG__DISP_HW_1D_DEBUG__SHIFT             0x0000001d
#define	DISP_HW_DEBUG__DISP_HW_1E_DEBUG__SHIFT             0x0000001e
#define	DISP_HW_DEBUG__DISP_HW_1F_DEBUG__SHIFT             0x0000001f

// DAC_CRC_SIG1
#define	DAC_CRC_SIG1__DAC_CRC_SIG_B__SHIFT                 0x00000000
#define	DAC_CRC_SIG1__DAC_CRC_SIG_B_MASK__SHIFT            0x00000000
#define	DAC_CRC_SIG1__DAC_CRC_SIG_G__SHIFT                 0x00000010
#define	DAC_CRC_SIG1__DAC_CRC_SIG_G_MASK__SHIFT            0x00000010

// DAC_CRC_SIG2
#define	DAC_CRC_SIG2__DAC_CRC_SIG_R__SHIFT                 0x00000000
#define	DAC_CRC_SIG2__DAC_CRC_SIG_R_MASK__SHIFT            0x00000000
#define	DAC_CRC_SIG2__DAC_CRC_SIG_C__SHIFT                 0x00000010
#define	DAC_CRC_SIG2__DAC_CRC_SIG_C_MASK__SHIFT            0x00000010

// OV0_LIN_TRANS_A
#define	OV0_LIN_TRANS_A__OV0_LIN_TRANS_Cb_R__SHIFT         0x00000001
#define	OV0_LIN_TRANS_A__OV0_LIN_TRANS_Y_R__SHIFT          0x00000011

// OV0_LIN_TRANS_B
#define	OV0_LIN_TRANS_B__OV0_LIN_TRANS_OFF_R__SHIFT        0x00000000
#define	OV0_LIN_TRANS_B__OV0_LIN_TRANS_Cr_R__SHIFT         0x00000011

// OV0_LIN_TRANS_C
#define	OV0_LIN_TRANS_C__OV0_LIN_TRANS_Cb_G__SHIFT         0x00000001
#define	OV0_LIN_TRANS_C__OV0_LIN_TRANS_Y_G__SHIFT          0x00000011

// OV0_LIN_TRANS_D
#define	OV0_LIN_TRANS_D__OV0_LIN_TRANS_OFF_G__SHIFT        0x00000000
#define	OV0_LIN_TRANS_D__OV0_LIN_TRANS_Cr_G__SHIFT         0x00000011

// OV0_LIN_TRANS_E
#define	OV0_LIN_TRANS_E__OV0_LIN_TRANS_Cb_B__SHIFT         0x00000001
#define	OV0_LIN_TRANS_E__OV0_LIN_TRANS_Y_B__SHIFT          0x00000011

// OV0_LIN_TRANS_F
#define	OV0_LIN_TRANS_F__OV0_LIN_TRANS_OFF_B__SHIFT        0x00000000
#define	OV0_LIN_TRANS_F__OV0_LIN_TRANS_Cr_B__SHIFT         0x00000011

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
#define	OV0_GAMMA_380_3BF__OV0_GAMMA_380_3BF_OFFSET_R2__SHIFT 0x00000000
#define	OV0_GAMMA_380_3BF__OV0_GAMMA_380_3BF_SLOPE__SHIFT  0x00000010

// OV0_GAMMA_3C0_3FF
#define	OV0_GAMMA_3C0_3FF__OV0_GAMMA_3C0_3FF_OFFSET_R2__SHIFT 0x00000000
#define	OV0_GAMMA_3C0_3FF__OV0_GAMMA_3C0_3FF_SLOPE__SHIFT  0x00000010

// DAC_CRC2_SIG1
#define	DAC_CRC2_SIG1__DAC_CRC2_SIG_B__SHIFT               0x00000000
#define	DAC_CRC2_SIG1__DAC_CRC2_SIG_B_MASK__SHIFT          0x00000000
#define	DAC_CRC2_SIG1__DAC_CRC2_SIG_G__SHIFT               0x00000010
#define	DAC_CRC2_SIG1__DAC_CRC2_SIG_G_MASK__SHIFT          0x00000010

// DAC_CRC2_SIG2
#define	DAC_CRC2_SIG2__DAC_CRC2_SIG_R__SHIFT               0x00000000
#define	DAC_CRC2_SIG2__DAC_CRC2_SIG_R_MASK__SHIFT          0x00000000
#define	DAC_CRC2_SIG2__DAC_CRC2_SIG_C__SHIFT               0x00000010
#define	DAC_CRC2_SIG2__DAC_CRC2_SIG_C_MASK__SHIFT          0x00000010

// OV0_GAMMA_80_BF
#define	OV0_GAMMA_80_BF__OV0_GAMMA_80_BF_OFFSET__SHIFT     0x00000000
#define	OV0_GAMMA_80_BF__OV0_GAMMA_80_BF_SLOPE__SHIFT      0x00000010

// OV0_GAMMA_C0_FF
#define	OV0_GAMMA_C0_FF__OV0_GAMMA_C0_FF_OFFSET__SHIFT     0x00000000
#define	OV0_GAMMA_C0_FF__OV0_GAMMA_C0_FF_SLOPE__SHIFT      0x00000010

// OV0_GAMMA_100_13F
#define	OV0_GAMMA_100_13F__OV0_GAMMA_100_13F_OFFSET__SHIFT 0x00000000
#define	OV0_GAMMA_100_13F__OV0_GAMMA_100_13F_SLOPE__SHIFT  0x00000010

// OV0_GAMMA_140_17F
#define	OV0_GAMMA_140_17F__OV0_GAMMA_140_17F_OFFSET__SHIFT 0x00000000
#define	OV0_GAMMA_140_17F__OV0_GAMMA_140_17F_SLOPE__SHIFT  0x00000010

// OV0_GAMMA_180_1BF
#define	OV0_GAMMA_180_1BF__OV0_GAMMA_180_1BF_OFFSET__SHIFT 0x00000000
#define	OV0_GAMMA_180_1BF__OV0_GAMMA_180_1BF_SLOPE__SHIFT  0x00000010

// OV0_GAMMA_1C0_1FF
#define	OV0_GAMMA_1C0_1FF__OV0_GAMMA_1C0_1FF_OFFSET__SHIFT 0x00000000
#define	OV0_GAMMA_1C0_1FF__OV0_GAMMA_1C0_1FF_SLOPE__SHIFT  0x00000010

// OV0_GAMMA_200_23F
#define	OV0_GAMMA_200_23F__OV0_GAMMA_200_23F_OFFSET__SHIFT 0x00000000
#define	OV0_GAMMA_200_23F__OV0_GAMMA_200_23F_SLOPE__SHIFT  0x00000010

// OV0_GAMMA_240_27F
#define	OV0_GAMMA_240_27F__OV0_GAMMA_240_27F_OFFSET__SHIFT 0x00000000
#define	OV0_GAMMA_240_27F__OV0_GAMMA_240_27F_SLOPE__SHIFT  0x00000010

// OV0_GAMMA_280_2BF
#define	OV0_GAMMA_280_2BF__OV0_GAMMA_280_2BF_OFFSET__SHIFT 0x00000000
#define	OV0_GAMMA_280_2BF__OV0_GAMMA_280_2BF_SLOPE__SHIFT  0x00000010

// OV0_GAMMA_2C0_2FF
#define	OV0_GAMMA_2C0_2FF__OV0_GAMMA_2C0_2FF_OFFSET__SHIFT 0x00000000
#define	OV0_GAMMA_2C0_2FF__OV0_GAMMA_2C0_2FF_SLOPE__SHIFT  0x00000010

// OV0_GAMMA_300_33F
#define	OV0_GAMMA_300_33F__OV0_GAMMA_300_33F_OFFSET__SHIFT 0x00000000
#define	OV0_GAMMA_300_33F__OV0_GAMMA_300_33F_SLOPE__SHIFT  0x00000010

// OV0_GAMMA_340_37F
#define	OV0_GAMMA_340_37F__OV0_GAMMA_340_37F_OFFSET__SHIFT 0x00000000
#define	OV0_GAMMA_340_37F__OV0_GAMMA_340_37F_SLOPE__SHIFT  0x00000010

// DISP_MERGE_CNTL
#define	DISP_MERGE_CNTL__DISP_ALPHA_MODE__SHIFT            0x00000000
#define	DISP_MERGE_CNTL__DISP_ALPHA_INV__SHIFT             0x00000002
#define	DISP_MERGE_CNTL__DISP_ALPHA_PREMULT__SHIFT         0x00000003
#define	DISP_MERGE_CNTL__DISP_RGB_OFFSET_EN__SHIFT         0x00000008
#define	DISP_MERGE_CNTL__DISP_LIN_TRANS_BYPASS__SHIFT      0x00000009
#define	DISP_MERGE_CNTL__DISP_GRPH_ALPHA__SHIFT            0x00000010
#define	DISP_MERGE_CNTL__DISP_OV0_ALPHA__SHIFT             0x00000018

// DISP_OUTPUT_CNTL
#define	DISP_OUTPUT_CNTL__DISP_DAC_SOURCE__SHIFT           0x00000000
#define	DISP_OUTPUT_CNTL__DISP_TVDAC_SOURCE__SHIFT         0x00000002
#define	DISP_OUTPUT_CNTL__DISP_TRANS_MATRIX_SEL__SHIFT     0x00000004
#define	DISP_OUTPUT_CNTL__DISP_RMX_DITH_EN__SHIFT          0x0000000a
#define	DISP_OUTPUT_CNTL__DISP_TRANS_SOURCE__SHIFT         0x0000000c
#define	DISP_OUTPUT_CNTL__DISP_TV_SOURCE__SHIFT            0x00000010
#define	DISP_OUTPUT_CNTL__DISP_TV_MODE__SHIFT              0x00000011
#define	DISP_OUTPUT_CNTL__DISP_TV_YG_DITH_EN__SHIFT        0x00000013
#define	DISP_OUTPUT_CNTL__DISP_TV_CbB_CrR_DITH_EN__SHIFT   0x00000014
#define	DISP_OUTPUT_CNTL__DISP_TV_BIT_WIDTH__SHIFT         0x00000015
#define	DISP_OUTPUT_CNTL__DISP_TV_SYNC_MODE__SHIFT         0x00000016
#define	DISP_OUTPUT_CNTL__DISP_TV_SYNC_FORCE__SHIFT        0x00000018
#define	DISP_OUTPUT_CNTL__DISP_TV_SYNC_COLOR__SHIFT        0x00000019
#define	DISP_OUTPUT_CNTL__DISP_TV_EVEN_FLAG_CNTL__SHIFT    0x0000001b
#define	DISP_OUTPUT_CNTL__DISP_TV_SYNC_STATUS__SHIFT       0x0000001d

// DISP2_MERGE_CNTL
#define	DISP2_MERGE_CNTL__DISP2_RGB_OFFSET_EN__SHIFT       0x00000008

// DISP_TV_OUT_CNTL
#define	DISP_TV_OUT_CNTL__DISP_TV_OUT_YG_FILTER__SHIFT     0x00000000
#define	DISP_TV_OUT_CNTL__DISP_TV_OUT_YG_SAMPLE__SHIFT     0x00000002
#define	DISP_TV_OUT_CNTL__DISP_TV_OUT_CrR_FILTER__SHIFT    0x00000004
#define	DISP_TV_OUT_CNTL__DISP_TV_OUT_CrR_SAMPLE__SHIFT    0x00000006
#define	DISP_TV_OUT_CNTL__DISP_TV_OUT_CbB_FILTER__SHIFT    0x00000008
#define	DISP_TV_OUT_CNTL__DISP_TV_OUT_CbB_SAMPLE__SHIFT    0x0000000a
#define	DISP_TV_OUT_CNTL__DISP_TV_SUBSAMPLE_CNTL__SHIFT    0x0000000c
#define	DISP_TV_OUT_CNTL__DISP_TV_H_DOWNSCALE__SHIFT       0x0000000f
#define	DISP_TV_OUT_CNTL__DISP_TV_PATH_SRC__SHIFT          0x00000010
#define	DISP_TV_OUT_CNTL__DISP_TV_COLOR_SPACE__SHIFT       0x00000011
#define	DISP_TV_OUT_CNTL__DISP_TV_DITH_MODE__SHIFT         0x00000012
#define	DISP_TV_OUT_CNTL__DISP_TV_DATA_ZERO_SEL__SHIFT     0x00000013
#define	DISP_TV_OUT_CNTL__DISP_TV_CLKO_SEL__SHIFT          0x00000014
#define	DISP_TV_OUT_CNTL__DISP_TV_CLKO_OUT_EN__SHIFT       0x00000015
#define	DISP_TV_OUT_CNTL__DISP_TV_H_DOWNSCALE_SECOND_DISP__SHIFT 0x00000016
#define	DISP_TV_OUT_CNTL__DISP_TV_DOWNSCALE_CNTL__SHIFT    0x00000018

// DISP_LIN_TRANS_GRPH_A
#define	DISP_LIN_TRANS_GRPH_A__DISP_LIN_TRANS_GRPH_C2__SHIFT 0x00000003
#define	DISP_LIN_TRANS_GRPH_A__DISP_LIN_TRANS_GRPH_C1__SHIFT 0x00000013

// DISP_LIN_TRANS_GRPH_B
#define	DISP_LIN_TRANS_GRPH_B__DISP_LIN_TRANS_GRPH_C4__SHIFT 0x00000000
#define	DISP_LIN_TRANS_GRPH_B__DISP_LIN_TRANS_GRPH_C3__SHIFT 0x00000013

// DISP_LIN_TRANS_GRPH_C
#define	DISP_LIN_TRANS_GRPH_C__DISP_LIN_TRANS_GRPH_C6__SHIFT 0x00000003
#define	DISP_LIN_TRANS_GRPH_C__DISP_LIN_TRANS_GRPH_C5__SHIFT 0x00000013

// DISP_LIN_TRANS_GRPH_D
#define	DISP_LIN_TRANS_GRPH_D__DISP_LIN_TRANS_GRPH_C8__SHIFT 0x00000000
#define	DISP_LIN_TRANS_GRPH_D__DISP_LIN_TRANS_GRPH_C7__SHIFT 0x00000013

// DISP_LIN_TRANS_GRPH_E
#define	DISP_LIN_TRANS_GRPH_E__DISP_LIN_TRANS_GRPH_C10__SHIFT 0x00000003
#define	DISP_LIN_TRANS_GRPH_E__DISP_LIN_TRANS_GRPH_C9__SHIFT 0x00000013

// DISP_LIN_TRANS_GRPH_F
#define	DISP_LIN_TRANS_GRPH_F__DISP_LIN_TRANS_GRPH_C12__SHIFT 0x00000000
#define	DISP_LIN_TRANS_GRPH_F__DISP_LIN_TRANS_GRPH_C11__SHIFT 0x00000013

// DISP_LIN_TRANS_VID_A
#define	DISP_LIN_TRANS_VID_A__DISP_LIN_TRANS_VID_C2__SHIFT 0x00000003
#define	DISP_LIN_TRANS_VID_A__DISP_LIN_TRANS_VID_C1__SHIFT 0x00000013

// DISP_LIN_TRANS_VID_B
#define	DISP_LIN_TRANS_VID_B__DISP_LIN_TRANS_VID_C4__SHIFT 0x00000000
#define	DISP_LIN_TRANS_VID_B__DISP_LIN_TRANS_VID_C3__SHIFT 0x00000013

// DISP_LIN_TRANS_VID_C
#define	DISP_LIN_TRANS_VID_C__DISP_LIN_TRANS_VID_C6__SHIFT 0x00000003
#define	DISP_LIN_TRANS_VID_C__DISP_LIN_TRANS_VID_C5__SHIFT 0x00000013

// DISP_LIN_TRANS_VID_D
#define	DISP_LIN_TRANS_VID_D__DISP_LIN_TRANS_VID_C8__SHIFT 0x00000000
#define	DISP_LIN_TRANS_VID_D__DISP_LIN_TRANS_VID_C7__SHIFT 0x00000013

// DISP_LIN_TRANS_VID_E
#define	DISP_LIN_TRANS_VID_E__DISP_LIN_TRANS_VID_C10__SHIFT 0x00000003
#define	DISP_LIN_TRANS_VID_E__DISP_LIN_TRANS_VID_C9__SHIFT 0x00000013

// DISP_LIN_TRANS_VID_F
#define	DISP_LIN_TRANS_VID_F__DISP_LIN_TRANS_VID_C12__SHIFT 0x00000000
#define	DISP_LIN_TRANS_VID_F__DISP_LIN_TRANS_VID_C11__SHIFT 0x00000013

// RMX_HORZ_PHASE
#define	RMX_HORZ_PHASE__RMX_HORZ_START_PHASE__SHIFT        0x00000000
#define	RMX_HORZ_PHASE__RMX_H_ACC_INIT__SHIFT              0x0000000c
#define	RMX_HORZ_PHASE__RMX_V_ACC_INIT__SHIFT              0x0000000d
#define	RMX_HORZ_PHASE__RMX_VERT_START_PHASE__SHIFT        0x00000010
#define	RMX_HORZ_PHASE__RMX_VERT_HALF_START_PHASE_EN__SHIFT 0x0000001c
#define	RMX_HORZ_PHASE__RMX_VERT_START_PHASE_OVERFLOW_EN__SHIFT 0x0000001d
#define	RMX_HORZ_PHASE__RMX_HORZ_HALF_START_PHASE_EN__SHIFT 0x0000001e
#define	RMX_HORZ_PHASE__RMX_HORZ_START_PHASE_OVERFLOW_EN__SHIFT 0x0000001f

// DAC_EMBEDDED_SYNC_CNTL
#define	DAC_EMBEDDED_SYNC_CNTL__DAC_EMBED_SYNC_EN_Y_G__SHIFT 0x00000000
#define	DAC_EMBEDDED_SYNC_CNTL__DAC_EMBED_SYNC_EN_Cb_B__SHIFT 0x00000001
#define	DAC_EMBEDDED_SYNC_CNTL__DAC_EMBED_SYNC_EN_Cr_R__SHIFT 0x00000002
#define	DAC_EMBEDDED_SYNC_CNTL__DAC_TRILEVEL_SYNC_EN__SHIFT 0x00000003
#define	DAC_EMBEDDED_SYNC_CNTL__DAC_EMBED_VSYNC_EN_Y_G__SHIFT 0x00000004
#define	DAC_EMBEDDED_SYNC_CNTL__DAC_EMBED_VSYNC_EN_CbCr_BR__SHIFT 0x00000005
#define	DAC_EMBEDDED_SYNC_CNTL__DAC_HSYNC_WID_LSB__SHIFT   0x00000010

// DAC_BROAD_PULSE
#define	DAC_BROAD_PULSE__DAC_BROAD_PULSE_START_R2__SHIFT   0x00000000
#define	DAC_BROAD_PULSE__DAC_BROAD_PULSE_END_R2__SHIFT     0x00000010

// DAC_INCR
#define	DAC_INCR__DAC_INCR_Y_G__SHIFT                      0x00000000
#define	DAC_INCR__DAC_INCR_CrCb_RB__SHIFT                  0x00000010

// DAC_NEG_SYNC_LEVEL
#define	DAC_NEG_SYNC_LEVEL__DAC_NEG_SYNC_LEVEL_Y_G__SHIFT  0x00000000
#define	DAC_NEG_SYNC_LEVEL__DAC_NEG_SYNC_LEVEL_CrCb_RB__SHIFT 0x00000010

// DAC_POS_SYNC_LEVEL
#define	DAC_POS_SYNC_LEVEL__DAC_POS_SYNC_LEVEL_Y_G__SHIFT  0x00000000
#define	DAC_POS_SYNC_LEVEL__DAC_POS_SYNC_LEVEL_CrCb_RB__SHIFT 0x00000010

// DAC_BLANK_LEVEL
#define	DAC_BLANK_LEVEL__DAC_BLANK_LEVEL_Y_G__SHIFT        0x00000000
#define	DAC_BLANK_LEVEL__DAC_BLANK_LEVEL_CrCb_RB__SHIFT    0x00000010

// DAC_SYNC_EQUALIZATION
#define	DAC_SYNC_EQUALIZATION__DAC_SYNC_EQ_START__SHIFT    0x00000000
#define	DAC_SYNC_EQUALIZATION__DAC_SYNC_EQ_END__SHIFT      0x00000010

// DAC_MV_CNTL
#define	DAC_MV_CNTL__DAC_MV_AGC_PULSE_EN__SHIFT            0x00000000
#define	DAC_MV_CNTL__DAC_MV_BLANK_EN__SHIFT                0x00000001
#define	DAC_MV_CNTL__DAC_MV_BP_PULSE_EN__SHIFT             0x00000002
#define	DAC_MV_CNTL__DAC_MV_AGC_PULSE_COUNT__SHIFT         0x00000008
#define	DAC_MV_CNTL__DAC_MV_WRITE_EN__SHIFT                0x0000001f

// DAC_MV_AGC_PULSE_LINES
#define	DAC_MV_AGC_PULSE_LINES__DAC_MV_AGC_VSTART__SHIFT   0x00000000
#define	DAC_MV_AGC_PULSE_LINES__DAC_MV_AGC_VEND__SHIFT     0x00000010

// DAC_MV_AGC_PULSE_POS
#define	DAC_MV_AGC_PULSE_POS__DAC_MV_PSEUDO_START__SHIFT   0x00000000
#define	DAC_MV_AGC_PULSE_POS__DAC_MV_PSEUDO_SPACE__SHIFT   0x00000010

// DAC_MV_AGC_PULSE_WIDTH
#define	DAC_MV_AGC_PULSE_WIDTH__DAC_MV_AGC_WIDTH__SHIFT    0x00000000
#define	DAC_MV_AGC_PULSE_WIDTH__DAC_MV_PSEUDO_WIDTH__SHIFT 0x00000010

// DAC_MV_AGC_PULSE_LEVELS
#define	DAC_MV_AGC_PULSE_LEVELS__DAC_MV_AGC_LEVEL_MAX__SHIFT 0x00000000
#define	DAC_MV_AGC_PULSE_LEVELS__DAC_MV_AGC_LEVEL_INCR__SHIFT 0x00000010

// DAC_MV_AGC_CYCLE
#define	DAC_MV_AGC_CYCLE__DAC_MV_AGC_MAX_FIELDS__SHIFT     0x00000000
#define	DAC_MV_AGC_CYCLE__DAC_MV_AGC_MIN_FIELDS__SHIFT     0x00000010
#define	DAC_MV_AGC_CYCLE__DAC_MV_AGC_SKEW_FIELDS__SHIFT    0x00000018

// DAC_MV_BLANK_LINES
#define	DAC_MV_BLANK_LINES__DAC_MV_BLANK_VSTART__SHIFT     0x00000000
#define	DAC_MV_BLANK_LINES__DAC_MV_BLANK_VEND__SHIFT       0x00000010

// DAC_MV_BLANK_LEVEL
#define	DAC_MV_BLANK_LEVEL__DAC_MV_BLANK_LEVEL__SHIFT      0x00000000

// DAC_MV_BP_PULSE_LINES
#define	DAC_MV_BP_PULSE_LINES__DAC_MV_BP_PULSE_VSTART__SHIFT 0x00000000
#define	DAC_MV_BP_PULSE_LINES__DAC_MV_BP_PULSE_VEND__SHIFT 0x00000010

// DAC_MV_BP_PULSE
#define	DAC_MV_BP_PULSE__DAC_MV_BP_PULSE_NOM_LEVEL__SHIFT  0x00000000
#define	DAC_MV_BP_PULSE__DAC_MV_BP_PULSE_MOD_LEVEL__SHIFT  0x0000000c
#define	DAC_MV_BP_PULSE__DAC_MV_BP_PULSE_WIDTH__SHIFT      0x00000018

// DAC_CGMS_LINES
#define	DAC_CGMS_LINES__DAC_CGMS_VSTART__SHIFT             0x00000000
#define	DAC_CGMS_LINES__DAC_CGMS_VEND__SHIFT               0x00000010
#define	DAC_CGMS_LINES__DAC_CGMS_RB_EN__SHIFT              0x0000001e
#define	DAC_CGMS_LINES__DAC_CGMS_YG_EN__SHIFT              0x0000001f

// DAC_CGMS_TIMING
#define	DAC_CGMS_TIMING__DAC_CGMS_WIDTH__SHIFT             0x00000000
#define	DAC_CGMS_TIMING__DAC_CGMS_HSTART__SHIFT            0x00000008
#define	DAC_CGMS_TIMING__DAC_CGMS_1_LEVEL__SHIFT           0x00000014

// DAC_CGMS_DATA
#define	DAC_CGMS_DATA__DAC_CGMS_DATA__SHIFT                0x00000000
#define	DAC_CGMS_DATA__DAC_CGMS_BITS__SHIFT                0x00000018
#define	DAC_CGMS_DATA__DAC_CGMS_DATA_PENDING__SHIFT        0x0000001f

// HDCP_CONTROL
#define	HDCP_CONTROL__HDCP_UPSTREAM_ADDRESS__SHIFT         0x00000000

// HDCP_DATA
#define	HDCP_DATA__HDCP_UPSTREAM_DATA__SHIFT               0x00000000

// HDCP_DEBUG
#define	HDCP_DEBUG_R2__HDCP_DEBUG_EN__SHIFT                0x00000000
#define	HDCP_DEBUG_R2__I2C_CNTL_REGS_AFFECT_HDCP_I2C__SHIFT   0x00000001
#define	HDCP_DEBUG_R2__SW_CAN_QUEUE_I2C_GO__SHIFT          0x00000002
#define	HDCP_DEBUG_R2__USE_HDCP_I2C_SHORT_READS__SHIFT     0x00000003
#define	HDCP_DEBUG_R2__HDCP_MODE__SHIFT                    0x00000004
#define	HDCP_DEBUG_R2__HDCP_HOTPLUG_SEL_BYPASS_EN__SHIFT   0x00000005
#define	HDCP_DEBUG_R2__HDCP_HOTPLUG_SELECT__SHIFT          0x00000006
#define	HDCP_DEBUG_R2__HDCP_DEBUG_BIT7__SHIFT              0x00000007
#define	HDCP_DEBUG_R2__HDCP_DEBUG_ADDR__SHIFT              0x00000008
#define	HDCP_DEBUG_R2__HDCP_DEBUG_DATA__SHIFT              0x00000010

// CLOCK_CNTL_INDEX
#define	CLOCK_CNTL_INDEX__PLL_ADDR_R2__SHIFT               0x00000000
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
#define	PLL_TEST_CNTL__TST_SRC_SEL_R2__SHIFT               0x00000000
#define	PLL_TEST_CNTL__TST_SRC_INV__SHIFT                  0x00000007
#define	PLL_TEST_CNTL__TST_DIVIDERS__SHIFT                 0x00000008
#define	PLL_TEST_CNTL__PLL_MASK_READ_B__SHIFT              0x00000009
#define	PLL_TEST_CNTL__TESTCLK_MUX_SEL__SHIFT              0x0000000c
#define	PLL_TEST_CNTL__ANALOG_MON_R2__SHIFT                0x00000010
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
#define	DAC_CNTL2__DAC2_CLK_SEL__SHIFT                     0x00000001
#define	DAC_CNTL2__PALETTE_ACCESS_CNTL__SHIFT              0x00000005
#define	DAC_CNTL2__DAC2_CMP_EN_R3__SHIFT                   0x00000006
#define	DAC_CNTL2__DAC2_CMP_OUT_R_R3__SHIFT                0x00000007
#define	DAC_CNTL2__DAC2_CMP_OUT_G_R3__SHIFT                0x00000008
#define	DAC_CNTL2__DAC2_CMP_OUT_B_R3__SHIFT                0x00000009
#define	DAC_CNTL2__DAC2_CMP_OUTPUT_R3__SHIFT               0x0000000a
#define	DAC_CNTL2__PALETTE_AUTOFILL_PRIMARY_W__SHIFT       0x0000000b
#define	DAC_CNTL2__PALETTE_AUTOFILL_PRIMARY_R__SHIFT       0x0000000b
#define	DAC_CNTL2__PALETTE_AUTOFILL_SECONDARY_W__SHIFT     0x0000000c
#define	DAC_CNTL2__PALETTE_AUTOFILL_SECONDARY_R__SHIFT     0x0000000c
#define	DAC_CNTL2__DAC2_EXPAND_MODE__SHIFT                 0x0000000e
#define	DAC_CNTL2__CRT2_SENSE__SHIFT                       0x00000010
#define	DAC_CNTL2__DAC_CRC2_BLANKb_ONLY__SHIFT             0x00000011
#define	DAC_CNTL2__DAC_CRC2_CONT_EN__SHIFT                 0x00000012
#define	DAC_CNTL2__DAC_CRC2_EN__SHIFT                      0x00000013
#define	DAC_CNTL2__DAC_CRC2_FIELD__SHIFT                   0x00000014
#define	DAC_CNTL2__DAC2_LUT_COUNTER_LIMIT__SHIFT           0x00000015

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

// CP_RESYNC_ADDR
#define	CP_RESYNC_ADDR__RESYNC_ADDR__SHIFT                 0x00000000

// CP_RESYNC_DATA
#define	CP_RESYNC_DATA__RESYNC_DATA__SHIFT                 0x00000000

// CP_CSQ_CNTL
#define	CP_CSQ_CNTL__CSQ_MODE__SHIFT                       0x0000001c

// CP_CSQ_AVAIL
#define	CP_CSQ_AVAIL__CSQ_CNT_PRIMARY__SHIFT               0x00000000
#define	CP_CSQ_AVAIL__CSQ_CNT_INDIRECT__SHIFT              0x0000000a
#define	CP_CSQ_AVAIL__CSQ_CNT_INDIRECT2__SHIFT             0x00000014

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
#define	CP_ME_RAM_DATAH__ME_RAM_DATAH_R3__SHIFT            0x00000000

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
#define	CP_CSQ2_STAT__CSQ_WPTR_INDIRECT_R3__SHIFT          0x00000000
#define	CP_CSQ2_STAT__CSQ_RPTR_INDIRECT2_R3__SHIFT         0x0000000a
#define	CP_CSQ2_STAT__CSQ_WPTR_INDIRECT2_R3__SHIFT         0x00000014

// CP_CSQ_ADDR
#define	CP_CSQ_ADDR__CSQ_ADDR_R3__SHIFT                    0x00000002

// CP_CSQ_DATA
#define	CP_CSQ_DATA__CSQ_DATA__SHIFT                       0x00000000

// CP_CSQ_STAT
#define	CP_CSQ_STAT__CSQ_RPTR_PRIMARY_R3__SHIFT            0x00000000
#define	CP_CSQ_STAT__CSQ_WPTR_PRIMARY_R3__SHIFT            0x0000000a
#define	CP_CSQ_STAT__CSQ_RPTR_INDIRECT_R3__SHIFT           0x00000014

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

// TVOUT_0_SCRATCH
#define	TVOUT_0_SCRATCH__TVOUT_0_SCRATCH__SHIFT            0x00000000

// TVOUT_1_SCRATCH
#define	TVOUT_1_SCRATCH__TVOUT_1_SCRATCH__SHIFT            0x00000000

// I2C_CNTL_0
#define	I2C_CNTL_0__I2C_DONE__SHIFT                        0x00000000
#define	I2C_CNTL_0__I2C_NACK__SHIFT                        0x00000001
#define	I2C_CNTL_0__I2C_HALT__SHIFT                        0x00000002
#define	I2C_CNTL_0__I2C_SOFT_RST__SHIFT                    0x00000005
#define	I2C_CNTL_0__I2C_DRIVE_EN__SHIFT                    0x00000006
#define	I2C_CNTL_0__I2C_DRIVE_SEL__SHIFT                   0x00000007
#define	I2C_CNTL_0__I2C_START__SHIFT                       0x00000008
#define	I2C_CNTL_0__I2C_STOP__SHIFT                        0x00000009
#define	I2C_CNTL_0__I2C_RECEIVE__SHIFT                     0x0000000a
#define	I2C_CNTL_0__I2C_ABORT__SHIFT                       0x0000000b
#define	I2C_CNTL_0__I2C_GO__SHIFT                          0x0000000c
#define	I2C_CNTL_0__I2C_PRESCALE__SHIFT                    0x00000010

// I2C_CNTL_1
#define	I2C_CNTL_1__I2C_DATA_COUNT__SHIFT                  0x00000000
#define	I2C_CNTL_1__I2C_ADDR_COUNT_R2__SHIFT               0x00000004
#define	I2C_CNTL_1__I2C_INTRA_BYTE_DELAY__SHIFT            0x00000008
#define	I2C_CNTL_1__I2C_SEL__SHIFT                         0x00000010
#define	I2C_CNTL_1__I2C_EN__SHIFT                          0x00000011
#define	I2C_CNTL_1__I2C_TIME_LIMIT__SHIFT                  0x00000018

// I2C_DATA
#define	I2C_DATA__I2C_DATA__SHIFT                          0x00000000

// CONFIG_XSTRAP
#define	CONFIG_XSTRAP__VGA_DISABLE__SHIFT                  0x00000000
#define	CONFIG_XSTRAP__MOBILE_DIS__SHIFT                   0x00000001
#define	CONFIG_XSTRAP__BLANK_ROM__SHIFT                    0x00000002
#define	CONFIG_XSTRAP__ENINTB__SHIFT                       0x00000003
#define	CONFIG_XSTRAP__MULTI_FUNC__SHIFT                   0x00000004
#define	CONFIG_XSTRAP__AGPSKEW__SHIFT                      0x00000006
#define	CONFIG_XSTRAP__X0CLK_SKEW__SHIFT                   0x00000008
#define	CONFIG_XSTRAP__VIP_DEVICE__SHIFT                   0x0000000d
#define	CONFIG_XSTRAP__EMU_DESKTOP__SHIFT                  0x0000000e
#define	CONFIG_XSTRAP__EXT_MEM_EN_R3__SHIFT                0x0000000f
#define	CONFIG_XSTRAP__AP_SIZE__SHIFT                      0x00000010
#define	CONFIG_XSTRAP__CHG_ID__SHIFT                       0x00000012
#define	CONFIG_XSTRAP__ROMIDCFG_R2__SHIFT                  0x00000014
#define	CONFIG_XSTRAP__BUSCFG__SHIFT                       0x00000018
#define	CONFIG_XSTRAP__WSEN__SHIFT                         0x0000001b
#define	CONFIG_XSTRAP__WSDEGRADE__SHIFT                    0x0000001c
#define	CONFIG_XSTRAP__HDCP_DISABLE__SHIFT                 0x0000001d
#define	CONFIG_XSTRAP__FAST_WT_DISABLE__SHIFT              0x0000001e
#define	CONFIG_XSTRAP__MV_DISABLE__SHIFT                   0x0000001f

// CONFIG_XSTRAP2
#define	CONFIG_XSTRAP2_R3__BM_DAC_EN__SHIFT                0x00000000
#define	CONFIG_XSTRAP2_R3__AGP8X_DETb__SHIFT               0x00000001
#define	CONFIG_XSTRAP2_R3__SLAVE_DAC_DECODE__SHIFT         0x00000002
#define	CONFIG_XSTRAP2_R3__MSI_ENABLE__SHIFT               0x00000003
#define	CONFIG_XSTRAP2__PKGTYPE__SHIFT                     0x00000004
#define	CONFIG_XSTRAP2__SPDGRD__SHIFT                      0x00000009
#define	CONFIG_XSTRAP2__ALT_ID__SHIFT                      0x0000000c

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
#define	TEST_DEBUG_OUT__TEST_DEBUG_OUTR__SHIFT             0x00000000

// VIDEOMUX_CNTL
#define	VIDEOMUX_CNTL__VIPH_INT_SEL__SHIFT                 0x00000000
#define	VIDEOMUX_CNTL__ROM_CLK_DIVIDE__SHIFT               0x00000010
#define	VIDEOMUX_CNTL__STR_ROMCLK__SHIFT                   0x00000015
#define	VIDEOMUX_CNTL__VIP_INTERNAL_DEBUG_SEL__SHIFT       0x00000016

// VIPPAD_STRENGTH
#define	VIPPAD_STRENGTH__ZV_LCDDATA_STRENGTH_SN__SHIFT     0x00000000
#define	VIPPAD_STRENGTH__ZV_LCDDATA_STRENGTH_SP__SHIFT     0x00000004
#define	VIPPAD_STRENGTH__ZV_LCDCNTL_STRENGTH_SN__SHIFT     0x00000008
#define	VIPPAD_STRENGTH__ZV_LCDCNTL_STRENGTH_SP__SHIFT     0x0000000c
#define	VIPPAD_STRENGTH__GPIO_STRENGTH_SN__SHIFT           0x00000010
#define	VIPPAD_STRENGTH__GPIO_STRENGTH_SP__SHIFT           0x00000014

// GPIOPAD_MASK
#define	GPIOPAD_MASK__GPIO_MASK__SHIFT                     0x00000000

// GPIOPAD_A
#define	GPIOPAD_A__GPIO_A__SHIFT                           0x00000000

// GPIOPAD_EN
#define	GPIOPAD_EN__GPIO_EN__SHIFT                         0x00000000

// GPIOPAD_Y
#define	GPIOPAD_Y__GPIO_Y__SHIFT                           0x00000000

// ZV_LCDPAD_MASK
#define	ZV_LCDPAD_MASK__ZV_LCDDATA_MASK__SHIFT             0x00000000
#define	ZV_LCDPAD_MASK__ZV_LCDCNTL_MASK__SHIFT             0x00000018

// ZV_LCDPAD_A
#define	ZV_LCDPAD_A__ZV_LCDDATA_A__SHIFT                   0x00000000
#define	ZV_LCDPAD_A__ZV_LCDCNTL_A__SHIFT                   0x00000018

// ZV_LCDPAD_EN
#define	ZV_LCDPAD_EN__ZV_LCDDATA_EN__SHIFT                 0x00000000
#define	ZV_LCDPAD_EN__ZV_LCDCNTL_EN__SHIFT                 0x00000018

// ZV_LCDPAD_Y
#define	ZV_LCDPAD_Y__ZV_LCDDATA_Y__SHIFT                   0x00000000
#define	ZV_LCDPAD_Y__ZV_LCDCNTL_Y__SHIFT                   0x00000018

// EXTERN_TRIG_CNTL
#define	EXTERN_TRIG_CNTL__EXTERN_TRIG_CLR__SHIFT           0x00000000
#define	EXTERN_TRIG_CNTL__EXTERN_TRIG_READ__SHIFT          0x00000001

// ROM_INDEX
#define	ROM_INDEX__ROM_INDEX__SHIFT                        0x00000000

// ROM_DATA
#define	ROM_DATA__ROM_DATA__SHIFT                          0x00000000

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
#define	SEPROM_CNTL1__SECTOR_ERASE__SHIFT                  0x0000000d
#define	SEPROM_CNTL1__BYTE_CNT__SHIFT                      0x00000010
#define	SEPROM_CNTL1__SCK_PRESCALE__SHIFT                  0x00000018

// SEPROM_CNTL2
#define	SEPROM_CNTL2__WAIT_CYCLE__SHIFT                    0x00000000
#define	SEPROM_CNTL2__AUTO_ADDR_SAMPLE__SHIFT              0x00000008
#define	SEPROM_CNTL2__SEC_COMMAND__SHIFT                   0x00000010
#define	SEPROM_CNTL2__SECTOR_TO_ERASE__SHIFT               0x00000018

// VIP_HW_DEBUG
#define	VIP_HW_DEBUG__VIP_HW_0_DEBUG__SHIFT                0x00000000
#define	VIP_HW_DEBUG__VIP_HW_1_DEBUG__SHIFT                0x00000001
#define	VIP_HW_DEBUG__VIP_HW_2_DEBUG__SHIFT                0x00000002
#define	VIP_HW_DEBUG__VIP_HW_3_DEBUG__SHIFT                0x00000003
#define	VIP_HW_DEBUG__VIP_HW_4_DEBUG__SHIFT                0x00000004
#define	VIP_HW_DEBUG__VIP_HW_5_DEBUG__SHIFT                0x00000005
#define	VIP_HW_DEBUG__VIP_HW_6_DEBUG__SHIFT                0x00000006
#define	VIP_HW_DEBUG__VIP_HW_7_DEBUG__SHIFT                0x00000007
#define	VIP_HW_DEBUG__VIP_HW_8_DEBUG__SHIFT                0x00000008
#define	VIP_HW_DEBUG__VIP_HW_9_DEBUG__SHIFT                0x00000009
#define	VIP_HW_DEBUG__VIP_HW_A_DEBUG__SHIFT                0x0000000a
#define	VIP_HW_DEBUG__VIP_HW_B_DEBUG__SHIFT                0x0000000b
#define	VIP_HW_DEBUG__VIP_HW_C_DEBUG__SHIFT                0x0000000c
#define	VIP_HW_DEBUG__VIP_HW_D_DEBUG__SHIFT                0x0000000d
#define	VIP_HW_DEBUG__VIP_HW_E_DEBUG__SHIFT                0x0000000e
#define	VIP_HW_DEBUG__VIP_HW_F_DEBUG__SHIFT                0x0000000f

// MEDIA_0_SCRATCH
#define	MEDIA_0_SCRATCH__MEDIA_0_SCRATCH__SHIFT            0x00000000

// MEDIA_1_SCRATCH
#define	MEDIA_1_SCRATCH__MEDIA_1_SCRACH__SHIFT             0x00000000

// VID_BUFFER_CONTROL
#define	VID_BUFFER_CONTROL__CAP0_BUFFER_WATER_MARK_R2__SHIFT  0x00000000
#define	VID_BUFFER_CONTROL__FULL_BUFFER_EN__SHIFT          0x00000010
#define	VID_BUFFER_CONTROL__CAP0_ANC_VBI_QUAD_BUF__SHIFT   0x00000011
#define	VID_BUFFER_CONTROL__VID_BUFFER_RESET__SHIFT        0x00000014
#define	VID_BUFFER_CONTROL__CAP_SWAP__SHIFT                0x00000015
#define	VID_BUFFER_CONTROL__CAP0_BUFFER_EMPTY__SHIFT       0x00000018

// CAP_INT_CNTL
#define	CAP_INT_CNTL__CAP0_BUF0_INT_EN__SHIFT              0x00000000
#define	CAP_INT_CNTL__CAP0_BUF0_EVEN_INT_EN__SHIFT         0x00000001
#define	CAP_INT_CNTL__CAP0_BUF1_INT_EN__SHIFT              0x00000002
#define	CAP_INT_CNTL__CAP0_BUF1_EVEN_INT_EN__SHIFT         0x00000003
#define	CAP_INT_CNTL__CAP0_VBI0_INT_EN__SHIFT              0x00000004
#define	CAP_INT_CNTL__CAP0_VBI1_INT_EN__SHIFT              0x00000005
#define	CAP_INT_CNTL__CAP0_ONESHOT_INT_EN__SHIFT           0x00000006
#define	CAP_INT_CNTL__CAP0_ANC0_INT_EN__SHIFT              0x00000007
#define	CAP_INT_CNTL__CAP0_ANC1_INT_EN__SHIFT              0x00000008
#define	CAP_INT_CNTL__CAP0_VBI2_INT_EN__SHIFT              0x00000009
#define	CAP_INT_CNTL__CAP0_VBI3_INT_EN__SHIFT              0x0000000a
#define	CAP_INT_CNTL__CAP0_ANC2_INT_EN__SHIFT              0x0000000b
#define	CAP_INT_CNTL__CAP0_ANC3_INT_EN__SHIFT              0x0000000c

// CAP_INT_STATUS
#define	CAP_INT_STATUS__CAP0_BUF0_INT__SHIFT               0x00000000
#define	CAP_INT_STATUS__CAP0_BUF0_INT_AK__SHIFT            0x00000000
#define	CAP_INT_STATUS__CAP0_BUF0_EVEN_INT__SHIFT          0x00000001
#define	CAP_INT_STATUS__CAP0_BUF0_EVEN_INT_AK__SHIFT       0x00000001
#define	CAP_INT_STATUS__CAP0_BUF1_INT__SHIFT               0x00000002
#define	CAP_INT_STATUS__CAP0_BUF1_INT_AK__SHIFT            0x00000002
#define	CAP_INT_STATUS__CAP0_BUF1_EVEN_INT__SHIFT          0x00000003
#define	CAP_INT_STATUS__CAP0_BUF1_EVEN_INT_AK__SHIFT       0x00000003
#define	CAP_INT_STATUS__CAP0_VBI0_INT__SHIFT               0x00000004
#define	CAP_INT_STATUS__CAP0_VBI0_INT_AK__SHIFT            0x00000004
#define	CAP_INT_STATUS__CAP0_VBI1_INT__SHIFT               0x00000005
#define	CAP_INT_STATUS__CAP0_VBI1_INT_AK__SHIFT            0x00000005
#define	CAP_INT_STATUS__CAP0_ONESHOT_INT__SHIFT            0x00000006
#define	CAP_INT_STATUS__CAP0_ONESHOT_INT_AK__SHIFT         0x00000006
#define	CAP_INT_STATUS__CAP0_ANC0_INT__SHIFT               0x00000007
#define	CAP_INT_STATUS__CAP0_ANC0_INT_AK__SHIFT            0x00000007
#define	CAP_INT_STATUS__CAP0_ANC1_INT__SHIFT               0x00000008
#define	CAP_INT_STATUS__CAP0_ANC1_INT_AK__SHIFT            0x00000008
#define	CAP_INT_STATUS__CAP0_VBI2_INT__SHIFT               0x00000009
#define	CAP_INT_STATUS__CAP0_VBI2_INT_AK__SHIFT            0x00000009
#define	CAP_INT_STATUS__CAP0_VBI3_INT__SHIFT               0x0000000a
#define	CAP_INT_STATUS__CAP0_VBI3_INT_AK__SHIFT            0x0000000a
#define	CAP_INT_STATUS__CAP0_ANC2_INT__SHIFT               0x0000000b
#define	CAP_INT_STATUS__CAP0_ANC2_INT_AK__SHIFT            0x0000000b
#define	CAP_INT_STATUS__CAP0_ANC3_INT__SHIFT               0x0000000c
#define	CAP_INT_STATUS__CAP0_ANC3_INT_AK__SHIFT            0x0000000c

// FCP_CNTL
#define	FCP_CNTL__FCP0_SRC_SEL__SHIFT                      0x00000000

// CAP0_BUF0_OFFSET
#define	CAP0_BUF0_OFFSET__CAP_BUF0_OFFSET__SHIFT           0x00000000

// CAP0_BUF1_OFFSET
#define	CAP0_BUF1_OFFSET__CAP_BUF1_OFFSET__SHIFT           0x00000000

// CAP0_BUF0_EVEN_OFFSET
#define	CAP0_BUF0_EVEN_OFFSET__CAP_BUF0_EVEN_OFFSET__SHIFT 0x00000000

// CAP0_BUF1_EVEN_OFFSET
#define	CAP0_BUF1_EVEN_OFFSET__CAP_BUF1_EVEN_OFFSET__SHIFT 0x00000000

// CAP0_BUF_PITCH
#define	CAP0_BUF_PITCH__CAP_BUF_PITCH__SHIFT               0x00000000

// CAP0_V_WINDOW
#define	CAP0_V_WINDOW__CAP_V_START__SHIFT                  0x00000000
#define	CAP0_V_WINDOW__CAP_V_END__SHIFT                    0x00000010

// CAP0_H_WINDOW
#define	CAP0_H_WINDOW__CAP_H_START__SHIFT                  0x00000000
#define	CAP0_H_WINDOW__CAP_H_WIDTH__SHIFT                  0x00000010

// CAP0_VBI0_OFFSET
#define	CAP0_VBI0_OFFSET__CAP_VBI0_OFFSET__SHIFT           0x00000000

// CAP0_VBI1_OFFSET
#define	CAP0_VBI1_OFFSET__CAP_VBI1_OFFSET__SHIFT           0x00000000

// CAP0_VBI_V_WINDOW
#define	CAP0_VBI_V_WINDOW__CAP_VBI_V_START__SHIFT          0x00000000
#define	CAP0_VBI_V_WINDOW__CAP_VBI_V_END__SHIFT            0x00000010

// CAP0_VBI_H_WINDOW
#define	CAP0_VBI_H_WINDOW__CAP_VBI_H_START__SHIFT          0x00000000
#define	CAP0_VBI_H_WINDOW__CAP_VBI_H_WIDTH__SHIFT          0x00000010

// CAP0_PORT_MODE_CNTL
#define	CAP0_PORT_MODE_CNTL__CAP_PORT_WIDTH__SHIFT         0x00000001
#define	CAP0_PORT_MODE_CNTL__CAP_PORT_BYTE_USED__SHIFT     0x00000002

// CAP0_TRIG_CNTL
#define	CAP0_TRIG_CNTL__CAP_TRIGGER_R__SHIFT               0x00000000
#define	CAP0_TRIG_CNTL__CAP_TRIGGER_W__SHIFT               0x00000000
#define	CAP0_TRIG_CNTL__CAP_EN__SHIFT                      0x00000004
#define	CAP0_TRIG_CNTL__CAP_VSYNC_CNT__SHIFT               0x00000008
#define	CAP0_TRIG_CNTL__CAP_VSYNC_CLR__SHIFT               0x00000010

// CAP0_DEBUG
#define	CAP0_DEBUG__CAP_H_STATUS__SHIFT                    0x00000000
#define	CAP0_DEBUG__CAP_V_STATUS__SHIFT                    0x00000010
#define	CAP0_DEBUG__CAP_V_SYNC__SHIFT                      0x0000001c

// CAP0_CONFIG
#define	CAP0_CONFIG__CAP_INPUT_MODE__SHIFT                 0x00000000
#define	CAP0_CONFIG__CAP_START_FIELD__SHIFT                0x00000001
#define	CAP0_CONFIG__CAP_START_BUF_R__SHIFT                0x00000002
#define	CAP0_CONFIG__CAP_START_BUF_W__SHIFT                0x00000003
#define	CAP0_CONFIG__CAP_BUF_TYPE__SHIFT                   0x00000004
#define	CAP0_CONFIG__CAP_ONESHOT_MODE__SHIFT               0x00000006
#define	CAP0_CONFIG__CAP_BUF_MODE__SHIFT                   0x00000007
#define	CAP0_CONFIG__CAP_MIRROR_EN__SHIFT                  0x00000009
#define	CAP0_CONFIG__CAP_ONESHOT_MIRROR_EN__SHIFT          0x0000000a
#define	CAP0_CONFIG__CAP_VIDEO_SIGNED_UV__SHIFT            0x0000000b
#define	CAP0_CONFIG__CAP_ANC_DECODE_EN__SHIFT              0x0000000c
#define	CAP0_CONFIG__CAP_VBI_EN__SHIFT                     0x0000000d
#define	CAP0_CONFIG__CAP_SOFT_PULL_DOWN_EN__SHIFT          0x0000000e
#define	CAP0_CONFIG__CAP_VIP_EXTEND_FLAG_EN__SHIFT         0x0000000f
#define	CAP0_CONFIG__CAP_FAKE_FIELD_EN__SHIFT              0x00000010
#define	CAP0_CONFIG__CAP_FIELD_START_LINE_DIFF__SHIFT      0x00000011
#define	CAP0_CONFIG__CAP_HORZ_DOWN__SHIFT                  0x00000013
#define	CAP0_CONFIG__CAP_VERT_DOWN__SHIFT                  0x00000015
#define	CAP0_CONFIG__CAP_STREAM_FORMAT__SHIFT              0x00000017
#define	CAP0_CONFIG__CAP_HDWNS_DEC__SHIFT                  0x0000001a
#define	CAP0_CONFIG__CAP_IMAGE_FLIP_EN__SHIFT              0x0000001b
#define	CAP0_CONFIG__CAP_ONESHOT_IMAGE_FLIP_EN__SHIFT      0x0000001c
#define	CAP0_CONFIG__CAP_VIDEO_IN_FORMAT__SHIFT            0x0000001d
#define	CAP0_CONFIG__VBI_HORZ_DOWN__SHIFT                  0x0000001e

// CAP0_ANC0_OFFSET
#define	CAP0_ANC0_OFFSET__CAP_ANC0_OFFSET__SHIFT           0x00000000

// CAP0_ANC1_OFFSET
#define	CAP0_ANC1_OFFSET__CAP_ANC1_OFFSET__SHIFT           0x00000000

// CAP0_ANC_H_WINDOW
#define	CAP0_ANC_H_WINDOW__CAP_ANC_WIDTH__SHIFT            0x00000000

// CAP0_VIDEO_SYNC_TEST
#define	CAP0_VIDEO_SYNC_TEST__CAP_TEST_VID_SOF__SHIFT      0x00000000
#define	CAP0_VIDEO_SYNC_TEST__CAP_TEST_VID_EOF__SHIFT      0x00000001
#define	CAP0_VIDEO_SYNC_TEST__CAP_TEST_VID_EOL__SHIFT      0x00000002
#define	CAP0_VIDEO_SYNC_TEST__CAP_TEST_VID_FIELD__SHIFT    0x00000003
#define	CAP0_VIDEO_SYNC_TEST__CAP_TEST_SYNC_EN__SHIFT      0x00000005

// CAP0_ONESHOT_BUF_OFFSET
#define	CAP0_ONESHOT_BUF_OFFSET__CAP_ONESHOT_BUF_OFFSET__SHIFT 0x00000000

// CAP0_BUF_STATUS
#define	CAP0_BUF_STATUS__CAP_PRE_VID_BUF__SHIFT            0x00000000
#define	CAP0_BUF_STATUS__CAP_CUR_VID_BUF__SHIFT            0x00000002
#define	CAP0_BUF_STATUS__CAP_PRE_FIELD__SHIFT              0x00000004
#define	CAP0_BUF_STATUS__CAP_CUR_FIELD__SHIFT              0x00000005
#define	CAP0_BUF_STATUS__CAP_PRE_VBI_BUF__SHIFT            0x00000006
#define	CAP0_BUF_STATUS__CAP_CUR_VBI_BUF__SHIFT            0x00000008
#define	CAP0_BUF_STATUS__CAP_VBI_BUF_STATUS__SHIFT         0x0000000a
#define	CAP0_BUF_STATUS__CAP_PRE_ANC_BUF__SHIFT            0x0000000b
#define	CAP0_BUF_STATUS__CAP_CUR_ANC_BUF__SHIFT            0x0000000d
#define	CAP0_BUF_STATUS__CAP_ANC_BUF_STATUS__SHIFT         0x0000000f
#define	CAP0_BUF_STATUS__CAP_ANC_PRE_BUF_CNT__SHIFT        0x00000010
#define	CAP0_BUF_STATUS__CAP_VIP_INC__SHIFT                0x0000001c
#define	CAP0_BUF_STATUS__CAP_VIP_PRE_REPEAT_FIELD__SHIFT   0x0000001d
#define	CAP0_BUF_STATUS__CAP_CAP_BUF_STATUS__SHIFT         0x0000001e

// CAP0_ANC_BUF01_BLOCK_CNT
#define	CAP0_ANC_BUF01_BLOCK_CNT__CAP0_ANC_BUF0_BLOCK_CNT__SHIFT 0x00000000
#define	CAP0_ANC_BUF01_BLOCK_CNT__CAP0_ANC_BUF1_BLOCK_CNT__SHIFT 0x00000010

// CAP0_ANC_BUF23_BLOCK_CNT
#define	CAP0_ANC_BUF23_BLOCK_CNT__CAP0_ANC_BUF2_BLOCK_CNT__SHIFT 0x00000000
#define	CAP0_ANC_BUF23_BLOCK_CNT__CAP0_ANC_BUF3_BLOCK_CNT__SHIFT 0x00000010

// CAP0_VBI2_OFFSET
#define	CAP0_VBI2_OFFSET__CAP_VBI2_OFFSET__SHIFT           0x00000000

// CAP0_VBI3_OFFSET
#define	CAP0_VBI3_OFFSET__CAP_VBI3_OFFSET__SHIFT           0x00000000

// CAP0_ANC2_OFFSET
#define	CAP0_ANC2_OFFSET__CAP_ANC2_OFFSET__SHIFT           0x00000000

// CAP0_ANC3_OFFSET
#define	CAP0_ANC3_OFFSET__CAP_ANC3_OFFSET__SHIFT           0x00000000

// DMA_VIPH0_COMMAND
#define	DMA_VIPH0_COMMAND__BYTE_COUNT__SHIFT               0x00000000
#define	DMA_VIPH0_COMMAND__SWAP_CONTROL__SHIFT             0x00000018
#define	DMA_VIPH0_COMMAND__TRANSFER_SOURCE__SHIFT          0x0000001a
#define	DMA_VIPH0_COMMAND__TRANSFER_DEST__SHIFT            0x0000001b
#define	DMA_VIPH0_COMMAND__SOURCE_OFFSET_HOLD__SHIFT       0x0000001c
#define	DMA_VIPH0_COMMAND__DEST_OFFSET_HOLD__SHIFT         0x0000001d
#define	DMA_VIPH0_COMMAND__INTERRUPT_DIS__SHIFT            0x0000001e
#define	DMA_VIPH0_COMMAND__END_OF_LIST_STATUS__SHIFT       0x0000001f

// DMA_VIPH1_COMMAND
#define	DMA_VIPH1_COMMAND__BYTE_COUNT__SHIFT               0x00000000
#define	DMA_VIPH1_COMMAND__SWAP_CONTROL__SHIFT             0x00000018
#define	DMA_VIPH1_COMMAND__TRANSFER_SOURCE__SHIFT          0x0000001a
#define	DMA_VIPH1_COMMAND__TRANSFER_DEST__SHIFT            0x0000001b
#define	DMA_VIPH1_COMMAND__SOURCE_OFFSET_HOLD__SHIFT       0x0000001c
#define	DMA_VIPH1_COMMAND__DEST_OFFSET_HOLD__SHIFT         0x0000001d
#define	DMA_VIPH1_COMMAND__INTERRUPT_DIS__SHIFT            0x0000001e
#define	DMA_VIPH1_COMMAND__END_OF_LIST_STATUS__SHIFT       0x0000001f

// DMA_VIPH2_COMMAND
#define	DMA_VIPH2_COMMAND__BYTE_COUNT__SHIFT               0x00000000
#define	DMA_VIPH2_COMMAND__SWAP_CONTROL__SHIFT             0x00000018
#define	DMA_VIPH2_COMMAND__TRANSFER_SOURCE__SHIFT          0x0000001a
#define	DMA_VIPH2_COMMAND__TRANSFER_DEST__SHIFT            0x0000001b
#define	DMA_VIPH2_COMMAND__SOURCE_OFFSET_HOLD__SHIFT       0x0000001c
#define	DMA_VIPH2_COMMAND__DEST_OFFSET_HOLD__SHIFT         0x0000001d
#define	DMA_VIPH2_COMMAND__INTERRUPT_DIS__SHIFT            0x0000001e
#define	DMA_VIPH2_COMMAND__END_OF_LIST_STATUS__SHIFT       0x0000001f

// DMA_VIPH3_COMMAND
#define	DMA_VIPH3_COMMAND__BYTE_COUNT__SHIFT               0x00000000
#define	DMA_VIPH3_COMMAND__SWAP_CONTROL__SHIFT             0x00000018
#define	DMA_VIPH3_COMMAND__TRANSFER_SOURCE__SHIFT          0x0000001a
#define	DMA_VIPH3_COMMAND__TRANSFER_DEST__SHIFT            0x0000001b
#define	DMA_VIPH3_COMMAND__SOURCE_OFFSET_HOLD__SHIFT       0x0000001c
#define	DMA_VIPH3_COMMAND__DEST_OFFSET_HOLD__SHIFT         0x0000001d
#define	DMA_VIPH3_COMMAND__INTERRUPT_DIS__SHIFT            0x0000001e
#define	DMA_VIPH3_COMMAND__END_OF_LIST_STATUS__SHIFT       0x0000001f

// DMA_VIPH_STATUS
#define	DMA_VIPH_STATUS__DMA_VIPH0_AVAIL__SHIFT            0x00000000
#define	DMA_VIPH_STATUS__DMA_VIPH1_AVAIL__SHIFT            0x00000004
#define	DMA_VIPH_STATUS__DMA_VIPH2_AVAIL__SHIFT            0x00000008
#define	DMA_VIPH_STATUS__DMA_VIPH3_AVAIL__SHIFT            0x0000000c
#define	DMA_VIPH_STATUS__DMA_VIPH0_CURRENT__SHIFT          0x00000010
#define	DMA_VIPH_STATUS__DMA_VIPH1_CURRENT__SHIFT          0x00000012
#define	DMA_VIPH_STATUS__DMA_VIPH2_CURRENT__SHIFT          0x00000014
#define	DMA_VIPH_STATUS__DMA_VIPH3_CURRENT__SHIFT          0x00000016
#define	DMA_VIPH_STATUS__DMA_VIPH0_ACTIVE__SHIFT           0x00000018
#define	DMA_VIPH_STATUS__DMA_VIPH1_ACTIVE__SHIFT           0x00000019
#define	DMA_VIPH_STATUS__DMA_VIPH2_ACTIVE__SHIFT           0x0000001a
#define	DMA_VIPH_STATUS__DMA_VIPH3_ACTIVE__SHIFT           0x0000001b

// DMA_VIPH_MISC_CNTL
#define	DMA_VIPH_MISC_CNTL__DMA_VIPH_READ_TIMER__SHIFT     0x00000000
#define	DMA_VIPH_MISC_CNTL__DMA_VIPH_READ_TIMEOUT_TO_PIORITY_EN__SHIFT 0x00000007
#define	DMA_VIPH_MISC_CNTL__DMA_VIPH_READ_TIMEOUT_STATUS__SHIFT 0x00000008

// DMA_VIPH_CHUNK_0
#define	DMA_VIPH_CHUNK_0__DMA_VIPH3_TABLE_SWAP__SHIFT      0x00000000
#define	DMA_VIPH_CHUNK_0__DMA_VIPH2_TABLE_SWAP__SHIFT      0x00000002
#define	DMA_VIPH_CHUNK_0__DMA_VIPH1_TABLE_SWAP__SHIFT      0x00000004
#define	DMA_VIPH_CHUNK_0__DMA_VIPH0_TABLE_SWAP__SHIFT      0x00000006
#define	DMA_VIPH_CHUNK_0__DMA_VIPH3_NOCHUNK__SHIFT         0x0000001c
#define	DMA_VIPH_CHUNK_0__DMA_VIPH2_NOCHUNK__SHIFT         0x0000001d
#define	DMA_VIPH_CHUNK_0__DMA_VIPH1_NOCHUNK__SHIFT         0x0000001e
#define	DMA_VIPH_CHUNK_0__DMA_VIPH0_NOCHUNK__SHIFT         0x0000001f

// DMA_VIPH_CHUNK_1_VAL
#define	DMA_VIPH_CHUNK_1_VAL__DMA_VIP0_CHUNK__SHIFT        0x00000000
#define	DMA_VIPH_CHUNK_1_VAL__DMA_VIP1_CHUNK__SHIFT        0x00000008
#define	DMA_VIPH_CHUNK_1_VAL__DMA_VIP2_CHUNK__SHIFT        0x00000010
#define	DMA_VIPH_CHUNK_1_VAL__DMA_VIP3_CHUNK__SHIFT        0x00000018

// DMA_VIP0_TABLE_ADDR
#define	DMA_VIP0_TABLE_ADDR__DMA_VIPH_TABLE_ADDR__SHIFT    0x00000000

// DMA_VIP1_TABLE_ADDR
#define	DMA_VIP1_TABLE_ADDR__DMA_VIPH_TABLE_ADDR__SHIFT    0x00000000

// DMA_VIP2_TABLE_ADDR
#define	DMA_VIP2_TABLE_ADDR__DMA_VIPH_TABLE_ADDR__SHIFT    0x00000000

// DMA_VIP3_TABLE_ADDR
#define	DMA_VIP3_TABLE_ADDR__DMA_VIPH_TABLE_ADDR__SHIFT    0x00000000

// DMA_VIPH0_ACTIVE
#define	DMA_VIPH0_ACTIVE__DMA_VIPH_TABLE_ADDR_ACT__SHIFT   0x00000000

// DMA_VIPH1_ACTIVE
#define	DMA_VIPH1_ACTIVE__DMA_VIPH_TABLE_ADDR_ACT__SHIFT   0x00000000

// DMA_VIPH2_ACTIVE
#define	DMA_VIPH2_ACTIVE__DMA_VIPH_TABLE_ADDR_ACT__SHIFT   0x00000000

// DMA_VIPH3_ACTIVE
#define	DMA_VIPH3_ACTIVE__DMA_VIPH_TABLE_ADDR_ACT__SHIFT   0x00000000

// DMA_VIPH_ABORT
#define	DMA_VIPH_ABORT__DMA_VIPH0_ABORT_EN__SHIFT          0x00000003
#define	DMA_VIPH_ABORT__DMA_VIPH1_ABORT_EN__SHIFT          0x00000007
#define	DMA_VIPH_ABORT__DMA_VIPH2_ABORT_EN__SHIFT          0x0000000b
#define	DMA_VIPH_ABORT__DMA_VIPH3_ABORT_EN__SHIFT          0x0000000f
#define	DMA_VIPH_ABORT__DMA_VIPH0_RESET__SHIFT             0x00000014
#define	DMA_VIPH_ABORT__DMA_VIPH1_RESET__SHIFT             0x00000015
#define	DMA_VIPH_ABORT__DMA_VIPH2_RESET__SHIFT             0x00000016
#define	DMA_VIPH_ABORT__DMA_VIPH3_RESET__SHIFT             0x00000017

// VIPH_REG_ADDR
#define	VIPH_REG_ADDR__VIPH_REG_AD__SHIFT                  0x00000000

// VIPH_REG_DATA
#define	VIPH_REG_DATA__VIPH_REG_DT_R__SHIFT                0x00000000
#define	VIPH_REG_DATA__VIPH_REG_DT_W__SHIFT                0x00000000

// VIPH_CH0_DATA
#define	VIPH_CH0_DATA__VIPH_CH0_DT__SHIFT                  0x00000000

// VIPH_CH1_DATA
#define	VIPH_CH1_DATA__VIPH_CH1_DT__SHIFT                  0x00000000

// VIPH_CH2_DATA
#define	VIPH_CH2_DATA__VIPH_CH2_DT__SHIFT                  0x00000000

// VIPH_CH3_DATA
#define	VIPH_CH3_DATA__VIPH_CH3_DT__SHIFT                  0x00000000

// VIPH_CH0_ADDR
#define	VIPH_CH0_ADDR__VIPH_CH0_AD__SHIFT                  0x00000000

// VIPH_CH1_ADDR
#define	VIPH_CH1_ADDR__VIPH_CH1_AD__SHIFT                  0x00000000

// VIPH_CH2_ADDR
#define	VIPH_CH2_ADDR__VIPH_CH2_AD__SHIFT                  0x00000000

// VIPH_CH3_ADDR
#define	VIPH_CH3_ADDR__VIPH_CH3_AD__SHIFT                  0x00000000

// VIPH_CH0_SBCNT
#define	VIPH_CH0_SBCNT__VIPH_CH0_SCNT__SHIFT               0x00000000

// VIPH_CH1_SBCNT
#define	VIPH_CH1_SBCNT__VIPH_CH1_SCNT__SHIFT               0x00000000

// VIPH_CH2_SBCNT
#define	VIPH_CH2_SBCNT__VIPH_CH2_SCNT__SHIFT               0x00000000

// VIPH_CH3_SBCNT
#define	VIPH_CH3_SBCNT__VIPH_CH3_SCNT__SHIFT               0x00000000

// VIPH_CH0_ABCNT
#define	VIPH_CH0_ABCNT__VIPH_CH0_ACNT__SHIFT               0x00000000

// VIPH_CH1_ABCNT
#define	VIPH_CH1_ABCNT__VIPH_CH1_ACNT__SHIFT               0x00000000

// VIPH_CH2_ABCNT
#define	VIPH_CH2_ABCNT__VIPH_CH2_ACNT__SHIFT               0x00000000

// VIPH_CH3_ABCNT
#define	VIPH_CH3_ABCNT__VIPH_CH3_ACNT__SHIFT               0x00000000

// VIPH_CONTROL
#define	VIPH_CONTROL__VIPH_CLK_SEL__SHIFT                  0x00000000
#define	VIPH_CONTROL__VIPH_REG_RDY__SHIFT                  0x0000000d
#define	VIPH_CONTROL__VIPH_MAX_WAIT__SHIFT                 0x00000010
#define	VIPH_CONTROL__VIPH_DMA_MODE__SHIFT                 0x00000014
#define	VIPH_CONTROL__VIPH_EN__SHIFT                       0x00000015
#define	VIPH_CONTROL__VIPH_DV0_WID__SHIFT                  0x00000018
#define	VIPH_CONTROL__VIPH_DV1_WID__SHIFT                  0x00000019
#define	VIPH_CONTROL__VIPH_DV2_WID__SHIFT                  0x0000001a
#define	VIPH_CONTROL__VIPH_DV3_WID__SHIFT                  0x0000001b
#define	VIPH_CONTROL__VIPH_PWR_DOWN__SHIFT                 0x0000001c
#define	VIPH_CONTROL__VIPH_PWR_DOWN_AK__SHIFT              0x0000001c
#define	VIPH_CONTROL__VIPH_VIPCLK_DIS__SHIFT               0x0000001d

// VIPH_DV_LAT
#define	VIPH_DV_LAT__VIPH_TIME_UNIT__SHIFT                 0x00000000
#define	VIPH_DV_LAT__VIPH_DV0_LAT__SHIFT                   0x00000010
#define	VIPH_DV_LAT__VIPH_DV1_LAT__SHIFT                   0x00000014
#define	VIPH_DV_LAT__VIPH_DV2_LAT__SHIFT                   0x00000018
#define	VIPH_DV_LAT__VIPH_DV3_LAT__SHIFT                   0x0000001c

// VIPH_DMA_CHUNK
#define	VIPH_DMA_CHUNK__VIPH_CH0_CHUNK__SHIFT              0x00000000
#define	VIPH_DMA_CHUNK__VIPH_CH1_CHUNK__SHIFT              0x00000004
#define	VIPH_DMA_CHUNK__VIPH_CH2_CHUNK__SHIFT              0x00000006
#define	VIPH_DMA_CHUNK__VIPH_CH3_CHUNK__SHIFT              0x00000008
#define	VIPH_DMA_CHUNK__VIPH_CH0_ABORT__SHIFT              0x00000010
#define	VIPH_DMA_CHUNK__VIPH_CH1_ABORT__SHIFT              0x00000011
#define	VIPH_DMA_CHUNK__VIPH_CH2_ABORT__SHIFT              0x00000012
#define	VIPH_DMA_CHUNK__VIPH_CH3_ABORT__SHIFT              0x00000013

// VIPH_DV_INT
#define	VIPH_DV_INT__VIPH_DV0_INT_EN__SHIFT                0x00000000
#define	VIPH_DV_INT__VIPH_DV1_INT_EN__SHIFT                0x00000001
#define	VIPH_DV_INT__VIPH_DV2_INT_EN__SHIFT                0x00000002
#define	VIPH_DV_INT__VIPH_DV3_INT_EN__SHIFT                0x00000003
#define	VIPH_DV_INT__VIPH_DV0_INT__SHIFT                   0x00000004
#define	VIPH_DV_INT__VIPH_DV0_AK__SHIFT                    0x00000004
#define	VIPH_DV_INT__VIPH_DV1_INT__SHIFT                   0x00000005
#define	VIPH_DV_INT__VIPH_DV1_AK__SHIFT                    0x00000005
#define	VIPH_DV_INT__VIPH_DV2_INT__SHIFT                   0x00000006
#define	VIPH_DV_INT__VIPH_DV2_AK__SHIFT                    0x00000006
#define	VIPH_DV_INT__VIPH_DV3_INT__SHIFT                   0x00000007
#define	VIPH_DV_INT__VIPH_DV3_AK__SHIFT                    0x00000007

// VIPH_TIMEOUT_STAT
#define	VIPH_TIMEOUT_STAT__VIPH_FIFO0_STAT__SHIFT          0x00000000
#define	VIPH_TIMEOUT_STAT__VIPH_FIFO0_AK__SHIFT            0x00000000
#define	VIPH_TIMEOUT_STAT__VIPH_FIFO1_STAT__SHIFT          0x00000001
#define	VIPH_TIMEOUT_STAT__VIPH_FIFO1_AK__SHIFT            0x00000001
#define	VIPH_TIMEOUT_STAT__VIPH_FIFO2_STAT__SHIFT          0x00000002
#define	VIPH_TIMEOUT_STAT__VIPH_FIFO2_AK__SHIFT            0x00000002
#define	VIPH_TIMEOUT_STAT__VIPH_FIFO3_STAT__SHIFT          0x00000003
#define	VIPH_TIMEOUT_STAT__VIPH_FIFO3_AK__SHIFT            0x00000003
#define	VIPH_TIMEOUT_STAT__VIPH_REG_STAT__SHIFT            0x00000004
#define	VIPH_TIMEOUT_STAT__VIPH_REG_AK__SHIFT              0x00000004
#define	VIPH_TIMEOUT_STAT__VIPH_AUTO_INT_STAT__SHIFT       0x00000005
#define	VIPH_TIMEOUT_STAT__VIPH_AUTO_INT_AK__SHIFT         0x00000005
#define	VIPH_TIMEOUT_STAT__VIPH_FIFO0_MASK__SHIFT          0x00000008
#define	VIPH_TIMEOUT_STAT__VIPH_FIFO1_MASK__SHIFT          0x00000009
#define	VIPH_TIMEOUT_STAT__VIPH_FIFO2_MASK__SHIFT          0x0000000a
#define	VIPH_TIMEOUT_STAT__VIPH_FIFO3_MASK__SHIFT          0x0000000b
#define	VIPH_TIMEOUT_STAT__VIPH_REG_MASK__SHIFT            0x0000000c
#define	VIPH_TIMEOUT_STAT__VIPH_AUTO_INT_MASK__SHIFT       0x0000000d
#define	VIPH_TIMEOUT_STAT__VIPH_DV0_INT_MASK__SHIFT        0x00000010
#define	VIPH_TIMEOUT_STAT__VIPH_DV1_INT_MASK__SHIFT        0x00000011
#define	VIPH_TIMEOUT_STAT__VIPH_DV2_INT_MASK__SHIFT        0x00000012
#define	VIPH_TIMEOUT_STAT__VIPH_DV3_INT_MASK__SHIFT        0x00000013
#define	VIPH_TIMEOUT_STAT__VIPH_INTPIN_EN__SHIFT           0x00000014
#define	VIPH_TIMEOUT_STAT__VIPH_INTPIN_INT__SHIFT          0x00000015
#define	VIPH_TIMEOUT_STAT__VIPH_REGR_DIS__SHIFT            0x00000018

// CLK_PIN_CNTL
#define	CLK_PIN_CNTL__OSC_EN__SHIFT                        0x00000000
#define	CLK_PIN_CNTL__XTL_LOW_GAIN__SHIFT                  0x00000002
#define	CLK_PIN_CNTL__DONT_USE_XTALIN__SHIFT               0x00000004
#define	CLK_PIN_CNTL__SLOW_CLOCK_SOURCE__SHIFT             0x00000005
#define	CLK_PIN_CNTL__CG_CLK_TO_OUTPIN__SHIFT              0x0000000b
#define	CLK_PIN_CNTL__CG_COUNT_UP_TO_OUTPIN__SHIFT         0x0000000c
#define	CLK_PIN_CNTL__ACCESS_REGS_IN_SUSPEND__SHIFT        0x0000000d
#define	CLK_PIN_CNTL__CG_SPARE__SHIFT                      0x0000000e
#define	CLK_PIN_CNTL__SCLK_DYN_START_CNTL__SHIFT           0x0000000f
#define	CLK_PIN_CNTL__CP_CLK_RUNNING__SHIFT                0x00000010
#define	CLK_PIN_CNTL__CG_SPARE_RD__SHIFT                   0x00000011
#define	CLK_PIN_CNTL__XTALIN_ALWAYS_ONb__SHIFT             0x00000013
#define	CLK_PIN_CNTL__PWRSEQ_DELAY__SHIFT                  0x00000018

// PPLL_CNTL
#define	PPLL_CNTL__PPLL_RESET__SHIFT                       0x00000000
#define	PPLL_CNTL__PPLL_SLEEP__SHIFT                       0x00000001
#define	PPLL_CNTL__PPLL_TST_EN__SHIFT                      0x00000002
#define	PPLL_CNTL__PPLL_DIV_RESET__SHIFT                   0x00000003
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
#define	SPLL_CNTL__SPLL_DIV_RESET__SHIFT                   0x00000003
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
#define	SPLL_AUX_CNTL__TRANSIT_DONE_LENGTH__SHIFT          0x0000000c
#define	SPLL_AUX_CNTL__SPLL_REFCLK_SRC_SEL__SHIFT          0x0000000e
#define	SPLL_AUX_CNTL__SU_PROG_DELAY_VALUE__SHIFT          0x00000016
#define	SPLL_AUX_CNTL__TX_PROG_DELAY_VALUE__SHIFT          0x00000019
#define	SPLL_AUX_CNTL__US_PROG_DELAY_VALUE__SHIFT          0x0000001c

// SCLK_CNTL2
#define	SCLK_CNTL2__GA_PROG_DELAY_VALUE__SHIFT             0x00000000
#define	SCLK_CNTL2_RV3__TCL_PROG_DELAY_VALUE__SHIFT        0x00000003
#define	SCLK_CNTL2__VAP_PROG_DELAY_VALUE__SHIFT            0x00000006
#define	SCLK_CNTL2__TCL_MAX_DYN_STOP_LAT__SHIFT            0x0000000a
#define	SCLK_CNTL2__GA_MAX_DYN_STOP_LAT__SHIFT             0x0000000b
#define	SCLK_CNTL2__CBA_MAX_DYN_STOP_LAT__SHIFT            0x0000000c
#define	SCLK_CNTL2__FORCE_TCL__SHIFT                       0x0000000d
#define	SCLK_CNTL2__FORCE_CBA__SHIFT                       0x0000000e
#define	SCLK_CNTL2__FORCE_GA__SHIFT                        0x0000000f
#define	SCLK_CNTL2__REDUCED_SPEED_SCLK_MODE__SHIFT         0x00000010
#define	SCLK_CNTL2__REDUCED_SPEED_SCLK_SEL__SHIFT          0x00000011
#define	SCLK_CNTL2__ACPI_SCLK_DIVIDER__SHIFT               0x00000013
#define	SCLK_CNTL2__CBA_PROG_DELAY_VALUE__SHIFT            0x00000015
#define	SCLK_CNTL2__SR_PROG_DELAY_VALUE__SHIFT             0x00000018
#define	SCLK_CNTL2__PX_PROG_DELAY_VALUE__SHIFT             0x0000001b

// SCLK_CNTL
#define	SCLK_CNTL__SCLK_SRC_SEL__SHIFT                     0x00000000
#define	SCLK_CNTL__CP_MAX_DYN_STOP_LAT__SHIFT              0x00000003
#define	SCLK_CNTL__HDP_MAX_DYN_STOP_LAT__SHIFT             0x00000004
#define	SCLK_CNTL__TV_MAX_DYN_STOP_LAT__SHIFT              0x00000005
#define	SCLK_CNTL__E2_MAX_DYN_STOP_LAT__SHIFT              0x00000006
#define	SCLK_CNTL__VAP_MAX_DYN_STOP_LAT__SHIFT             0x00000007
#define	SCLK_CNTL__IDCT_MAX_DYN_STOP_LAT__SHIFT            0x00000008
#define	SCLK_CNTL__VIP_MAX_DYN_STOP_LAT__SHIFT             0x00000009
#define	SCLK_CNTL__SR_MAX_DYN_STOP_LAT__SHIFT              0x0000000a
#define	SCLK_CNTL__PX_MAX_DYN_STOP_LAT__SHIFT              0x0000000b
#define	SCLK_CNTL__TX_MAX_DYN_STOP_LAT__SHIFT              0x0000000c
#define	SCLK_CNTL__US_MAX_DYN_STOP_LAT__SHIFT              0x0000000d
#define	SCLK_CNTL__SU_MAX_DYN_STOP_LAT__SHIFT              0x0000000e
#define	SCLK_CNTL__FORCE_DISP2__SHIFT                      0x0000000f
#define	SCLK_CNTL__FORCE_CP__SHIFT                         0x00000010
#define	SCLK_CNTL__FORCE_HDP__SHIFT                        0x00000011
#define	SCLK_CNTL__FORCE_DISP1__SHIFT                      0x00000012
#define	SCLK_CNTL__FORCE_TOP__SHIFT                        0x00000013
#define	SCLK_CNTL__FORCE_E2__SHIFT                         0x00000014
#define	SCLK_CNTL__FORCE_VAP__SHIFT                        0x00000015
#define	SCLK_CNTL__FORCE_IDCT__SHIFT                       0x00000016
#define	SCLK_CNTL__FORCE_VIP__SHIFT                        0x00000017
#define	SCLK_CNTL__FORCE_SR__SHIFT                         0x00000019
#define	SCLK_CNTL__FORCE_PX__SHIFT                         0x0000001a
#define	SCLK_CNTL__FORCE_TX__SHIFT                         0x0000001b
#define	SCLK_CNTL__FORCE_US__SHIFT                         0x0000001c
#define	SCLK_CNTL__FORCE_TV_SCLK__SHIFT                    0x0000001d
#define	SCLK_CNTL__FORCE_SU__SHIFT                         0x0000001e
#define	SCLK_CNTL__FORCE_OV0__SHIFT                        0x0000001f

// AGP_PLL_CNTL
#define	AGP_PLL_CNTL__APLL_SLEEP__SHIFT                    0x00000000
#define	AGP_PLL_CNTL__APLL_RESET__SHIFT                    0x00000001
#define	AGP_PLL_CNTL__APLL_XSEL__SHIFT                     0x00000002
#define	AGP_PLL_CNTL__APLL_TST_EN__SHIFT                   0x00000004
#define	AGP_PLL_CNTL__APLL_TCPOFF__SHIFT                   0x00000005
#define	AGP_PLL_CNTL__APLL_TVCOMAX__SHIFT                  0x00000006
#define	AGP_PLL_CNTL__APLL_REF_SKEW__SHIFT                 0x00000007
#define	AGP_PLL_CNTL__APLL_FB_SKEW__SHIFT                  0x0000000a
#define	AGP_PLL_CNTL__APLL_X0_CLK_SKEW__SHIFT              0x0000000d
#define	AGP_PLL_CNTL__APLL_X1_CLK_SKEW__SHIFT              0x00000010
#define	AGP_PLL_CNTL__APLL_PUMP_GAIN__SHIFT                0x00000019
#define	AGP_PLL_CNTL__APLL_VCO_GAIN__SHIFT                 0x0000001c
#define	AGP_PLL_CNTL__APLL_SEL_SKWADJ_PCICLK__SHIFT        0x0000001f

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
#define	TV_PLL_CNTL1__TVPLL_DIV_RESET__SHIFT               0x00000000
#define	TV_PLL_CNTL1__TVPLL_RESET__SHIFT                   0x00000001
#define	TV_PLL_CNTL1__TVPLL_SLEEP__SHIFT                   0x00000003
#define	TV_PLL_CNTL1__TVPLL_REFCLK_SEL__SHIFT              0x00000004
#define	TV_PLL_CNTL1__TVPLL_FBCLK_SEL__SHIFT               0x00000005
#define	TV_PLL_CNTL1__TVPLL_TCPOFF__SHIFT                  0x00000006
#define	TV_PLL_CNTL1__TVPLL_TVCOMAX__SHIFT                 0x00000007
#define	TV_PLL_CNTL1__TVPCP__SHIFT                         0x00000008
#define	TV_PLL_CNTL1__TVPVG__SHIFT                         0x0000000b
#define	TV_PLL_CNTL1__TVPDC__SHIFT                         0x0000000e
#define	TV_PLL_CNTL1__TVCLK_SRC_SEL__SHIFT                 0x0000001e
#define	TV_PLL_CNTL1__TVPLL_TEST__SHIFT                    0x0000001f

// TV_DTO_INCREMENTS
#define	TV_DTO_INCREMENTS__TV_DTO_INC0__SHIFT              0x00000000
#define	TV_DTO_INCREMENTS__TV_DTO_INC1__SHIFT              0x00000010

// P2PLL_CNTL
#define	P2PLL_CNTL__P2PLL_RESET__SHIFT                     0x00000000
#define	P2PLL_CNTL__P2PLL_SLEEP__SHIFT                     0x00000001
#define	P2PLL_CNTL__P2PLL_TST_EN__SHIFT                    0x00000002
#define	P2PLL_CNTL__P2PLL_DIV_RESET__SHIFT                 0x00000003
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

// SSPLL_CNTL
#define	SSPLL_CNTL__SSPLL_RESET__SHIFT                     0x00000000
#define	SSPLL_CNTL__SSPLL_SLEEP__SHIFT                     0x00000001
#define	SSPLL_CNTL__SSPLL_TST_EN__SHIFT                    0x00000002
#define	SSPLL_CNTL__SSPLL_DIV_RESET__SHIFT                 0x00000003
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
#define	SS_INT_CNTL_RV3__SS_BUF_GENLOCK_DURATION__SHIFT    0x0000001a
#define	SS_INT_CNTL_RV3__SS_BUF_GENLOCK_HEIGHT__SHIFT      0x0000001d

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
#define	SS_TST_CNTL__EN_PULSE_SKIP_SCLK__SHIFT             0x0000001b
#define	SS_TST_CNTL__SS_TST_MODE__SHIFT                    0x0000001f

// SCLK_MORE_CNTL
#define	SCLK_MORE_CNTL__DISPREGS_MAX_DYN_STOP_LAT__SHIFT   0x00000000
#define	SCLK_MORE_CNTL__MC_GUI_MAX_DYN_STOP_LAT__SHIFT     0x00000001
#define	SCLK_MORE_CNTL__MC_HOST_MAX_DYN_STOP_LAT__SHIFT    0x00000002
#define	SCLK_MORE_CNTL__FORCE_DISPREGS__SHIFT              0x00000008
#define	SCLK_MORE_CNTL__FORCE_MC_GUI__SHIFT                0x00000009
#define	SCLK_MORE_CNTL__FORCE_MC_HOST__SHIFT               0x0000000a
#define	SCLK_MORE_CNTL__STOP_SCLK_EN__SHIFT                0x0000000c
#define	SCLK_MORE_CNTL__STOP_SCLK_A__SHIFT                 0x0000000d
#define	SCLK_MORE_CNTL__STOP_SCLK_B__SHIFT                 0x0000000e
#define	SCLK_MORE_CNTL__STOP_SCLK_C__SHIFT                 0x0000000f
#define	SCLK_MORE_CNTL__REDUCED_SPEED_SCLK_EN__SHIFT       0x00000010
#define	SCLK_MORE_CNTL__IO_CG_VOLTAGE_DROP__SHIFT          0x00000011
#define	SCLK_MORE_CNTL__TVFB_SOFT_RESET__SHIFT             0x00000012
#define	SCLK_MORE_CNTL__VOLTAGE_DROP_SYNC__SHIFT           0x00000013
#define	SCLK_MORE_CNTL__VOLTAGE_DELAY_SEL__SHIFT           0x00000014
#define	SCLK_MORE_CNTL__IDLE_DELAY_HALF_SCLK__SHIFT        0x00000016
#define	SCLK_MORE_CNTL__AGP_BUSY_HALF_SCLK__SHIFT          0x00000017
#define	SCLK_MORE_CNTL__CG_SPARE_RD_C__SHIFT               0x00000018

// CLK_PWRMGT_CNTL
#define	CLK_PWRMGT_CNTL__MPLL_PWRMGT_OFF__SHIFT            0x00000000
#define	CLK_PWRMGT_CNTL__SPLL_PWRMGT_OFF__SHIFT            0x00000001
#define	CLK_PWRMGT_CNTL__PPLL_PWRMGT_OFF__SHIFT            0x00000002
#define	CLK_PWRMGT_CNTL__P2PLL_PWRMGT_OFF__SHIFT           0x00000003
#define	CLK_PWRMGT_CNTL__MCLK_TURNOFF__SHIFT               0x00000004
#define	CLK_PWRMGT_CNTL__SCLK_TURNOFF__SHIFT               0x00000005
#define	CLK_PWRMGT_CNTL__PCLK_TURNOFF__SHIFT               0x00000006
#define	CLK_PWRMGT_CNTL__P2CLK_TURNOFF__SHIFT              0x00000007
#define	CLK_PWRMGT_CNTL__MC_CH_MODE__SHIFT                 0x00000008
#define	CLK_PWRMGT_CNTL__TEST_MODE__SHIFT                  0x00000009
#define	CLK_PWRMGT_CNTL__GLOBAL_PMAN_EN__SHIFT             0x0000000a
#define	CLK_PWRMGT_CNTL__ENGINE_DYNCLK_MODE__SHIFT         0x0000000c
#define	CLK_PWRMGT_CNTL__ACTIVE_HILO_LAT__SHIFT            0x0000000d
#define	CLK_PWRMGT_CNTL__DISP_DYN_STOP_LAT__SHIFT          0x0000000f
#define	CLK_PWRMGT_CNTL__MC_BUSY__SHIFT                    0x00000010
#define	CLK_PWRMGT_CNTL__MC_INT_CNTL__SHIFT                0x00000011
#define	CLK_PWRMGT_CNTL__MC_SWITCH__SHIFT                  0x00000012
#define	CLK_PWRMGT_CNTL__DLL_READY__SHIFT                  0x00000013
#define	CLK_PWRMGT_CNTL__DISP_PM__SHIFT                    0x00000014
#define	CLK_PWRMGT_CNTL__DYN_STOP_MODE__SHIFT              0x00000015
#define	CLK_PWRMGT_CNTL__CG_NO1_DEBUG_R3__SHIFT            0x00000018
#define	CLK_PWRMGT_CNTL__TVPLL_PWRMGT_OFF__SHIFT           0x0000001e
#define	CLK_PWRMGT_CNTL__TVCLK_TURNOFF__SHIFT              0x0000001f

// PLL_PWRMGT_CNTL
#define	PLL_PWRMGT_CNTL__MPLL_TURNOFF__SHIFT               0x00000000
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
#define	M_SPLL_REF_FB_DIV__MPLL_FB_DIV__SHIFT              0x00000008
#define	M_SPLL_REF_FB_DIV__SPLL_FB_DIV__SHIFT              0x00000010
#define	M_SPLL_REF_FB_DIV__MPLL_REF_SRC_SEL__SHIFT         0x00000018

// MPLL_CNTL
#define	MPLL_CNTL__MPLL_RESET__SHIFT                       0x00000000
#define	MPLL_CNTL__MPLL_SLEEP__SHIFT                       0x00000001
#define	MPLL_CNTL__MPLL_TST_EN__SHIFT                      0x00000002
#define	MPLL_CNTL__MPLL_DIV_RESET__SHIFT                   0x00000003
#define	MPLL_CNTL__MPLL_REFCLK_SEL__SHIFT                  0x00000004
#define	MPLL_CNTL__MPLL_FBCLK_SEL__SHIFT                   0x00000005
#define	MPLL_CNTL__MPLL_TCPOFF__SHIFT                      0x00000006
#define	MPLL_CNTL__MPLL_TVCOMAX__SHIFT                     0x00000007
#define	MPLL_CNTL__MPLL_PCP__SHIFT                         0x00000008
#define	MPLL_CNTL__MPLL_PVG__SHIFT                         0x0000000b
#define	MPLL_CNTL__MPLL_PDC__SHIFT                         0x0000000e
#define	MPLL_CNTL__MPLL_X1_CLK_SKEW__SHIFT                 0x00000010
#define	MPLL_CNTL__MPLL_X2_CLK_SKEW__SHIFT                 0x00000014
#define	MPLL_CNTL__MPLL_MODE__SHIFT                        0x00000018

// MPLL_AUX_CNTL
#define	MPLL_AUX_CNTL__MPLL_PDC_C__SHIFT                   0x00000000
#define	MPLL_AUX_CNTL__MPLL_CKINVA__SHIFT                  0x00000002
#define	MPLL_AUX_CNTL__MPLL_CKINVC__SHIFT                  0x00000003
#define	MPLL_AUX_CNTL__MPLL_X3_CLK_SKEW__SHIFT             0x00000004
#define	MPLL_AUX_CNTL__MPLL_MODEC__SHIFT                   0x00000007
#define	MPLL_AUX_CNTL__MPLL_TEST_COUNT__SHIFT              0x00000018

// MDLL_RDCK
#define	MDLL_RDCK__MRDCKA_SLEEP__SHIFT                     0x00000000
#define	MDLL_RDCK__MRDCKA_RESET__SHIFT                     0x00000001
#define	MDLL_RDCK__MRDCKB_SLEEP__SHIFT                     0x00000002
#define	MDLL_RDCK__MRDCKB_RESET__SHIFT                     0x00000003
#define	MDLL_RDCK__MRDCKC_SLEEP__SHIFT                     0x00000004
#define	MDLL_RDCK__MRDCKC_RESET__SHIFT                     0x00000005
#define	MDLL_RDCK__MRDCKD_SLEEP__SHIFT                     0x00000006
#define	MDLL_RDCK__MRDCKD_RESET__SHIFT                     0x00000007

// MCLK_CNTL
#define	MCLK_CNTL__MCLKA_SRC_SEL__SHIFT                    0x00000000
#define	MCLK_CNTL__YCLKA_SRC_SEL__SHIFT                    0x00000004
#define	MCLK_CNTL__MCLKB_SRC_SEL__SHIFT                    0x00000008
#define	MCLK_CNTL__YCLKB_SRC_SEL__SHIFT                    0x0000000c
#define	MCLK_CNTL__FORCE_MC_MCLKA__SHIFT                   0x00000010
#define	MCLK_CNTL__FORCE_MC_MCLKB__SHIFT                   0x00000011
#define	MCLK_CNTL__FORCE_YCLKA__SHIFT                      0x00000012
#define	MCLK_CNTL__FORCE_YCLKB__SHIFT                      0x00000013
#define	MCLK_CNTL__FORCE_MC_MCLK__SHIFT                    0x00000014
#define	MCLK_CNTL__DISABLE_MC_MCLKA__SHIFT                 0x00000015
#define	MCLK_CNTL__DISABLE_MC_MCLKB__SHIFT                 0x00000016
#define	MCLK_CNTL__MRDCKA0_SOUTSEL__SHIFT                  0x00000018
#define	MCLK_CNTL__MRDCKA1_SOUTSEL__SHIFT                  0x0000001a
#define	MCLK_CNTL__MRDCKB0_SOUTSEL__SHIFT                  0x0000001c
#define	MCLK_CNTL__MRDCKB1_SOUTSEL__SHIFT                  0x0000001e

// MCLK_MISC
#define	MCLK_MISC__SCLK_SOURCED_FROM_MPLL_SEL__SHIFT       0x00000000
#define	MCLK_MISC__MCLK_FROM_SPLL_DIV_SEL__SHIFT           0x00000002
#define	MCLK_MISC__ENABLE_SCLK_FROM_MPLL__SHIFT            0x00000003
#define	MCLK_MISC__MPLL_MODEA_MODEC_HW_SEL_EN__SHIFT       0x00000004
#define	MCLK_MISC__DLL_READY_LAT__SHIFT                    0x00000008
#define	MCLK_MISC__MC_MCLK_MAX_DYN_STOP_LAT__SHIFT         0x0000000c
#define	MCLK_MISC__IO_MCLK_MAX_DYN_STOP_LAT__SHIFT         0x0000000d
#define	MCLK_MISC__MC_MCLK_DYN_ENABLE__SHIFT               0x0000000e
#define	MCLK_MISC__IO_MCLK_DYN_ENABLE__SHIFT               0x0000000f
#define	MCLK_MISC__CGM_CLK_TO_OUTPIN__SHIFT                0x00000010
#define	MCLK_MISC__CLK_OR_COUNT_SEL__SHIFT                 0x00000011
#define	MCLK_MISC__EN_MCLK_TRISTATE_IN_SUSPEND__SHIFT      0x00000012
#define	MCLK_MISC__CGM_SPARE_RD__SHIFT                     0x00000014
#define	MCLK_MISC__CGM_SPARE_A_RD__SHIFT                   0x00000016
#define	MCLK_MISC__CGM_SPARE_A_R3__SHIFT                   0x00000018

// CG_TEST_MACRO_RW_WRITE
#define	CG_TEST_MACRO_RW_WRITE__TEST_MACRO_RW_WRITE1__SHIFT 0x00000000
#define	CG_TEST_MACRO_RW_WRITE__TEST_MACRO_RW_WRITE2__SHIFT 0x0000000e

// CG_TEST_MACRO_RW_READ
#define	CG_TEST_MACRO_RW_READ__TEST_MACRO_RW_READ1__SHIFT  0x00000000
#define	CG_TEST_MACRO_RW_READ__TEST_MACRO_RW_READ2__SHIFT  0x00000010

// CG_TEST_MACRO_RW_DATA
#define	CG_TEST_MACRO_RW_DATA__TEST_MACRO_RW_DATA__SHIFT   0x00000000

// CG_TEST_MACRO_RW_CNTL
#define	CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_START__SHIFT  0x00000000
#define	CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_OP__SHIFT     0x00000001
#define	CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_MODE__SHIFT   0x00000004
#define	CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_MISMATCH_SEL__SHIFT 0x00000006
#define	CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_MISMATCH__SHIFT 0x0000000f
#define	CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_ENABLE__SHIFT 0x00000010
#define	CG_TEST_MACRO_RW_CNTL__TEST_MACRO_RW_SCLK_NEG_ENABLE__SHIFT 0x00000011

// IDCT_CSQ_CONTROL
#define	IDCT_CSQ_CONTROL__PRE_WRITE_TIMER__SHIFT           0x00000000
#define	IDCT_CSQ_CONTROL__SEMAPHORE_TIMER__SHIFT           0x0000000f
#define	IDCT_CSQ_CONTROL__CSQ_MODE__SHIFT                  0x0000001e

// IDCT_SCRATCH
#define	IDCT_SCRATCH__IDCT_SCRATCH__SHIFT                  0x00000000

// IDCT_SPAN
#define	IDCT_SPAN__IDCT_SPAN__SHIFT                        0x00000000

// IDCT_RB_BASE
#define	IDCT_RB_BASE__RB_BASE__SHIFT                       0x00000000

// IDCT_RB_CONTROL
#define	IDCT_RB_CONTROL__RB_BUFSZ__SHIFT                   0x00000000
#define	IDCT_RB_CONTROL__RB_BLKSZ__SHIFT                   0x00000008
#define	IDCT_RB_CONTROL__BUF_SWAP__SHIFT                   0x00000010
#define	IDCT_RB_CONTROL__RB_NO_UPDATE__SHIFT               0x0000001b
#define	IDCT_RB_CONTROL__RB_INTERRUPT_ENABLE__SHIFT        0x0000001c
#define	IDCT_RB_CONTROL__RB_SEMAPHORE_ENABLE__SHIFT        0x0000001d
#define	IDCT_RB_CONTROL__RB_RPTR_WR_ENA__SHIFT             0x0000001f

// IDCT_RB_RPTR_ADDR
#define	IDCT_RB_RPTR_ADDR__RB_RPTR_SWAP__SHIFT             0x00000000
#define	IDCT_RB_RPTR_ADDR__RB_RPTR_ADDR__SHIFT             0x00000002

// IDCT_RB_RPTR
#define	IDCT_RB_RPTR__RB_RPTR__SHIFT                       0x00000000

// IDCT_RB_WPTR
#define	IDCT_RB_WPTR__RB_WPTR__SHIFT                       0x00000000

// IDCT_RB_TIMESTAMP
#define	IDCT_RB_TIMESTAMP__RB_TIMESTAMP__SHIFT             0x00000000

// IDCT_RB_SEMAPHORE
#define	IDCT_RB_SEMAPHORE__IDCT_SEMAPHORE__SHIFT           0x00000000
#define	IDCT_RB_SEMAPHORE__INC_SEMAPHORE_WAIT_CLEAN__SHIFT 0x0000000d
#define	IDCT_RB_SEMAPHORE__DEC_IDCT_SEMAPHORE__SHIFT       0x0000000e
#define	IDCT_RB_SEMAPHORE__INC_IDCT_SEMAPHORE__SHIFT       0x0000000f
#define	IDCT_RB_SEMAPHORE__FDCT_SEMAPHORE__SHIFT           0x00000010
#define	IDCT_RB_SEMAPHORE__FORCE_READER_PROCEED__SHIFT     0x0000001d
#define	IDCT_RB_SEMAPHORE__DEC_FDCT_SEMAPHORE__SHIFT       0x0000001e
#define	IDCT_RB_SEMAPHORE__INC_FDCT_SEMAPHORE__SHIFT       0x0000001f

// IDCT_COEF_DATA
#define	IDCT_COEF_DATA__IDCT_COEF_DATA__SHIFT              0x00000000

// IDCT_STATUS
#define	IDCT_STATUS__IDCT_ERROR_00__SHIFT                  0x00000000
#define	IDCT_STATUS__IDCT_ERROR_01__SHIFT                  0x00000001
#define	IDCT_STATUS__IDCT_ERROR_02__SHIFT                  0x00000002
#define	IDCT_STATUS__IDCT_ERROR_03__SHIFT                  0x00000003
#define	IDCT_STATUS__IDCT_ERROR_04__SHIFT                  0x00000004
#define	IDCT_STATUS__IDCT_ERROR_05__SHIFT                  0x00000005
#define	IDCT_STATUS__IDCT_ERROR_06__SHIFT                  0x00000006
#define	IDCT_STATUS__IDCT_ERROR_07__SHIFT                  0x00000007
#define	IDCT_STATUS__IDCT_ERROR_08__SHIFT                  0x00000008
#define	IDCT_STATUS__IDCT_ERROR_09__SHIFT                  0x00000009
#define	IDCT_STATUS__IDCT_ERROR_10__SHIFT                  0x0000000a
#define	IDCT_STATUS__IDCT_ERROR_11__SHIFT                  0x0000000b
#define	IDCT_STATUS__IDCT_ERROR_12__SHIFT                  0x0000000c
#define	IDCT_STATUS__IDCT_ERROR_13__SHIFT                  0x0000000d
#define	IDCT_STATUS__IDCT_ERROR_14__SHIFT                  0x0000000e
#define	IDCT_STATUS__IDCT_ERROR_15__SHIFT                  0x0000000f
#define	IDCT_STATUS__WAIT_FDCT_SEMAPHORE__SHIFT            0x0000001d
#define	IDCT_STATUS__IDCT_PIO_READY__SHIFT                 0x0000001e
#define	IDCT_STATUS__IDCT_IDLE__SHIFT                      0x0000001f

// IDCT_COEF_BASE
#define	IDCT_COEF_BASE__IDCT_STREAM_ID__SHIFT              0x00000000
#define	IDCT_COEF_BASE__IDCT_MEM_LOCATION__SHIFT           0x00000005

// IDCT_CONTROL
#define	IDCT_CONTROL__IDCT_SCRAMBLE_SELECT__SHIFT          0x00000000
#define	IDCT_CONTROL__IDCT_CTL_SCAN_PATTERN_R3__SHIFT      0x00000003
#define	IDCT_CONTROL__IDCT_CTL_INTRA__SHIFT                0x00000005
#define	IDCT_CONTROL__FDCT_WAIT__SHIFT                     0x00000006
#define	IDCT_CONTROL__IDCT_CTL_CODED_RUN__SHIFT            0x00000007
#define	IDCT_CONTROL__IDCT_CTL_SW_RESET__SHIFT             0x00000008
#define	IDCT_CONTROL__IDCT_INTRA_YMODE__SHIFT              0x00000009
#define	IDCT_CONTROL__IDCT_SCRAMBLE__SHIFT                 0x0000000a
#define	IDCT_CONTROL__IDCT_FIELD_ENCODING__SHIFT           0x0000000b
#define	IDCT_CONTROL__IDCT_ZERO_ON_ERROR__SHIFT            0x0000000c
#define	IDCT_CONTROL__IDCT_248_MODE__SHIFT                 0x0000000d
#define	IDCT_CONTROL__IDCT_USE_VPLANE__SHIFT               0x0000000e
#define	IDCT_CONTROL__IDCT_DIRECTION__SHIFT                0x0000000f
#define	IDCT_CONTROL__IDCT_MISMATCH_CONTROL__SHIFT         0x00000010

// IDCT_AUTH_CONTROL0
#define	IDCT_AUTH_CONTROL0__CONTROL_BITS__SHIFT            0x00000000

// IDCT_AUTH0
#define	IDCT_AUTH0__AUTH__SHIFT                            0x00000000

// IDCT_AUTH_CONTROL1
#define	IDCT_AUTH_CONTROL1__CONTROL_BITS__SHIFT            0x00000000

// IDCT_AUTH1
#define	IDCT_AUTH1__AUTH__SHIFT                            0x00000000

// IDCT_AUTH_CONTROL2
#define	IDCT_AUTH_CONTROL2__CONTROL_BITS__SHIFT            0x00000000

// IDCT_AUTH2
#define	IDCT_AUTH2__AUTH__SHIFT                            0x00000000

// IDCT_AUTH_CONTROL3
#define	IDCT_AUTH_CONTROL3__CONTROL_BITS__SHIFT            0x00000000

// IDCT_AUTH3
#define	IDCT_AUTH3__AUTH__SHIFT                            0x00000000

// IDCT_MEM_ADDR_YPLANE
#define	IDCT_MEM_ADDR_YPLANE__IDCT_MEM_LOCATION__SHIFT     0x00000000

// IDCT_MEM_ADDR_UPLANE
#define	IDCT_MEM_ADDR_UPLANE__IDCT_MEM_LOCATION__SHIFT     0x00000000

// IDCT_MEM_ADDR_VPLANE
#define	IDCT_MEM_ADDR_VPLANE__IDCT_MEM_LOCATION__SHIFT     0x00000000

// IDCT_YSIZE
#define	IDCT_YSIZE__IDCT_MEM_SIZE__SHIFT                   0x00000000

// IDCT_USIZE
#define	IDCT_USIZE__IDCT_MEM_SIZE__SHIFT                   0x00000000

// IDCT_INITIAL_XY
#define	IDCT_INITIAL_XY__IDCT_SCREEN_X__SHIFT              0x00000000
#define	IDCT_INITIAL_XY__IDCT_SCREEN_Y__SHIFT              0x00000010

// IDCT_SURFACE_PITCH
#define	IDCT_SURFACE_PITCH__IDCT_Y_PITCH__SHIFT            0x00000000
#define	IDCT_SURFACE_PITCH__IDCT_UV_PITCH__SHIFT           0x00000010

// IDCT_SURFACE_WIDTH
#define	IDCT_SURFACE_WIDTH__IDCT_Y_WIDTH__SHIFT            0x00000000
#define	IDCT_SURFACE_WIDTH__IDCT_Y_HEIGHT__SHIFT           0x00000010

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
#define	TV_RGB_CNTL__TVOUT_SCALE_EN__SHIFT                 0x0000001a
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

#endif


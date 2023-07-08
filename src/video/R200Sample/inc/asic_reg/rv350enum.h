

#if !defined (_shivah_ENUM_HEADER)
#define _shivah_ENUM_HEADER
/*
*	shivah_enum.h
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

/*******************************************************
 * GB Enums
 *******************************************************/

/*
 * PIPE_COUNT_CONFIG enum
 */

#define GB_PIPE_COUNT_RL300                         0x00000000
#define GB_PIPE_COUNT_RV300A                        0x00000001
#define GB_PIPE_COUNT_RV300B                        0x00000002
#define GB_PIPE_COUNT_RX300                         0x00000003
#define GB_PIPE_COUNT_R300A                         0x00000004
#define GB_PIPE_COUNT_R300B                         0x00000005

/*
 * VIP_FUNC_LEVEL enum
 */

#define GB_NA_LEVEL                                 0x00000000
#define GB_RL300_LEVEL                              0x00000001
#define GB_RV300_LEVEL                              0x00000002
#define GB_R300_LEVEL                               0x00000003

/*
 * LINE_END_TYPE enum
 */

#define GB_LINE_END_HORIZONTAL                   0x00000000
#define GB_LINE_END_VERTICAL                     0x00000001
#define GB_LINE_END_SQUARE                       0x00000002
#define GB_LINE_END_COMPUTED                     0x00000003

/*
 * TILE_SUBPIXEL enum
 */

#define GB_SUBPIXEL_1_12                         0x00000000
#define GB_SUBPIXEL_1_16                         0x00000001

/*
 * TILE_SIZE enum
 */

#define GB_TILE_SIZE_8                           0x00000000
#define GB_TILE_SIZE_16                          0x00000001
#define GB_TILE_SIZE_32                          0x00000002

/*
 * SUPER_TILE_SIZE enum
 */

#define GB_ST_SIZE_1                             0x00000000
#define GB_ST_SIZE_2                             0x00000001
#define GB_ST_SIZE_4                             0x00000002
#define GB_ST_SIZE_8                             0x00000003
#define GB_ST_SIZE_16                            0x00000004
#define GB_ST_SIZE_32                            0x00000005
#define GB_ST_SIZE_64                            0x00000006
#define GB_ST_SIZE_128                           0x00000007

/*
 * FOG_SELECT enum
 */

#define GB_FOGSEL_C0A                            0x00000000
#define GB_FOGSEL_C1A                            0x00000001
#define GB_FOGSEL_C2A                            0x00000002
#define GB_FOGSEL_C3A                            0x00000003
#define GB_FOGSEL_W                              0x00000004
#define GB_FOGSEL_Z                              0x00000005

/*
 * DEPTH_SELECT enum
 */

#define GB_DEPTHSEL_Z                            0x00000000
#define GB_DEPTHSEL_W                            0x00000001

/*
 * W_SELECT enum
 */

#define GB_WSEL_W                                0x00000000
#define GB_WSEL_1                                0x00000001

/*
 * TEX_SRC enum
 */

#define GB_TEX_SRC_VAP                           0x00000000
#define GB_TEX_SRC_STUFF_ST                      0x00000001
#define GB_TEX_SRC_STUFF_STR                     0x00000002

/*
 * NUM_AA_SUBSAMPLES enum
 */

#define GB_NUM_AA_SUBSAMPLES_2                   0x00000000
#define GB_NUM_AA_SUBSAMPLES_3                   0x00000001
#define GB_NUM_AA_SUBSAMPLES_4                   0x00000002
#define GB_NUM_AA_SUBSAMPLES_6                   0x00000003

/*
 * STENCIL_AUTO enum
 */

#define GB_STENCIL_AUTO_OFF                      0x00000000
#define GB_STENCIL_AUTO_ON                       0x00000001
#define GB_STENCIL_AUTO_ZERO                     0x00000002

/*
 * Z_PEQ_SIZE enum
 */

#define GB_Z_PEQ_SIZE_4x4                        0x00000000
#define GB_Z_PEQ_SIZE_8x8                        0x00000001

/*
 * PIXEL_OFFSET value
 */

#define GB_PIXEL_OFFSET                0x000005a0
#define GB_PIXEL_OFFSET2               0x00000440
#define GB_PIXEL_OFFSET_D12            0x00004380
#define GB_PIXEL_OFFSET_D16            0x00004400

/*******************************************************
 * GA Enums
 *******************************************************/

/*
 * POLY_MODE enum
 */

#define GA_POLY_MODE_DISABLE                     0x00000000
#define GA_POLY_MODE_DUAL                        0x00000001

/*
 * PMODE_BUS enum
 */

#define GA_PMODE_REGULAR                         0x00000000
#define GA_PMODE_FACING                          0x00000004
#define GA_PMODE_BACK                            0x00000005
#define GA_PMODE_FRONT                           0x00000006
#define GA_PMODE_PRIM                            0x00000007

/*
 * POLY_TYPE enum
 */

#define GA_POLY_TYPE_POINT                       0x00000000
#define GA_POLY_TYPE_LINE                        0x00000001
#define GA_POLY_TYPE_TRIANGLE                    0x00000002

/*
 * LINE_END_TYPE enum
 */

#define GA_LINE_END_HORIZONTAL                   0x00000000
#define GA_LINE_END_VERTICAL                     0x00000001
#define GA_LINE_END_SQUARE                       0x00000002
#define GA_LINE_END_COMPUTED                     0x00000003

/*
 * LINE_STIP_RESET enum
 */

#define GA_LINE_STIP_RESET_NONE                  0x00000000
#define GA_LINE_STIP_RESET_EOL                   0x00000001
#define GA_LINE_STIP_RESET_EOP                   0x00000002

/*
 * COLOR_SHADING enum
 */

#define GA_SOLID_FILL                            0x00000000
#define GA_FLAT_SHADING                          0x00000001
#define GA_GOURAUD_SHADING                       0x00000002

/*
 * COLOR_PROVOKING enum
 */

#define GA_PROVOKE_FIRST                         0x00000000
#define GA_PROVOKE_SECOND                        0x00000001
#define GA_PROVOKE_THIRD                         0x00000002
#define GA_PROVOKE_LAST                          0x00000003

/*
 * ROUND_MODE enum
 */

#define GA_ROUND_TRUNCATE                        0x00000000
#define GA_ROUND_NEAREST                         0x00000001

/*
 * CLAMP_MODE enum
 */

#define GA_CLAMP_ZERO_TO_ONE                     0x00000000
#define GA_CLAMP_MINUS_EIGHT_TO_EIGHT            0x00000001

/*
 * GA_SU_PTYPE enum
 */

#define GA_SU_PTYPE_NOTWORD0                     0x00000000
#define GA_SU_PTYPE_TRIANGLE                     0x00000001
#define GA_SU_PTYPE_POINT                        0x00000002
#define GA_SU_PTYPE_LINE                         0x00000003
#define GA_SU_PTYPE_REGISTER                     0x00000007

/*
 * GA_PERF_SEL enum
 */

#define GA_PERF_OFF                              0x00000000
#define GA_PERF_ON                               0x00000001
#define GA_PERF_VERTEX_CNT                       0x00000002
#define GA_PERF_PRIM_CNT                         0x00000003
#define GA_PERF_REG_CNT                          0x00000004
#define GA_PERF_POINT_CNT                        0x00000005
#define GA_PERF_LINE_CNT                         0x00000006
#define GA_PERF_TRI_CNT                          0x00000007
#define GA_PERF_NULLV_CNT                        0x00000008
#define GA_PERF_NULLP_CNT                        0x00000009
#define GA_PERF_EMPTY_IN_VFIFO_CYCLES            0x0000000a
#define GA_PERF_EMPTY_IN_PFIFO_CYCLES            0x0000000b
#define GA_PERF_EMPTY_IN_RFIFO_CYCLES            0x0000000c
#define GA_PERF_FULL_IN_VFIFO_CYCLES             0x0000000d
#define GA_PERF_FULL_IN_PFIFO_CYCLES             0x0000000e
#define GA_PERF_FULL_IN_RFIFO_CYCLES             0x0000000f
#define GA_PERF_OUT_STALL_CYCLES                 0x00000010
#define GA_PERF_SU_READY_CYCLES                  0x00000011
#define GA_PERF_IDLE_CYCLES                      0x00000012
#define GA_PERF_RBBM_SYNC_CNT                    0x00000013
#define GA_PERF_INDEX_SYNC_CNT                   0x00000014
#define GA_PERF_VALLOC_FULL_CNT                  0x00000015
#define GA_PERF_VALLOC_MISSING_CNT               0x00000016
#define GA_PERF_BUBBLE_CNT                       0x00000017
#define GA_PERF_PIPE_BUSY                        0x00000018

/*******************************************************
 * SU Enums
 *******************************************************/

/*
 * CULL_ENABLE enum
 */

#define SU_CULL_DIS                              0x00000000
#define SU_CULL_EN                               0x00000001

/*
 * FACE_DIR enum
 */

#define SU_FACE_POS                              0x00000000
#define SU_FACE_NEG                              0x00000001

/*
 * SU_RS_DEST enum
 */

#define SU_RS_DEST_A0                            0x00000001
#define SU_RS_DEST_B0                            0x00000002
#define SU_RS_DEST_A1                            0x00000004
#define SU_RS_DEST_B1                            0x00000008
#define SU_RS_DEST_ALL                           0x0000000f

/*
 * SU_RS_CMD enum
 */

#define SU_RS_CMD_TRIANGLE                       0x00000000
#define SU_RS_CMD_PARALLELOGRAM_0                0x00000001
#define SU_RS_CMD_REGISTER                       0x00000002
#define SU_RS_CMD_PARALLELOGRAM_1                0x00000003

/*
 * SU_RS_PARA enum
 */

#define SU_RS_PARA_POINT                         0x00000000
#define SU_RS_PARA_TRIANGLE_FRONT                0x00000001
#define SU_RS_PARA_TRIANGLE_BACK                 0x00000003
#define SU_RS_PARA_LINE_HLR                      0x00000004
#define SU_RS_PARA_LINE_HRL                      0x00000005
#define SU_RS_PARA_LINE_VSL                      0x00000006
#define SU_RS_PARA_LINE_VLS                      0x00000007

/*
 * SU_PERF_SEL enum
 */

#define SU_PERF_OFF                              0x00000000
#define SU_PERF_ON                               0x00000001
#define SU_PERF_PRIM_CNT                         0x00000002
#define SU_PERF_REG_CNT                          0x00000003
#define SU_PERF_POINT_CNT                        0x00000004
#define SU_PERF_LINE_CNT                         0x00000005
#define SU_PERF_TRI_CNT                          0x00000006
#define SU_PERF_CULL_CNT                         0x00000007
#define SU_PERF_REGION_ABORT_CNT                 0x00000008
#define SU_PERF_IN_FIFO_FULL                     0x00000009
#define SU_PERF_IN_FIFO_EMPTY                    0x0000000a
#define SU_PERF_OUT_FIFO_FULL                    0x0000000b
#define SU_PERF_OUT_FIFO_EMPTY                   0x0000000c
#define SU_PERF_SU_IDLE                          0x0000000d

/*******************************************************
 * RS Enums
 *******************************************************/

/*
 * RS_TEX_SEL enum
 */

#define RS_TEX_SEL_C0                            0x00000000
#define RS_TEX_SEL_C1                            0x00000001
#define RS_TEX_SEL_C2                            0x00000002
#define RS_TEX_SEL_C3                            0x00000003
#define RS_TEX_SEL_K0                            0x00000004
#define RS_TEX_SEL_K1                            0x00000005

/*
 * RS_COL_FMT enum
 */

#define RS_COL_FMT_RGBA                          0x00000000
#define RS_COL_FMT_RGB0                          0x00000001
#define RS_COL_FMT_RGB1                          0x00000002
#define RS_COL_FMT_000A                          0x00000004
#define RS_COL_FMT_0000                          0x00000005
#define RS_COL_FMT_0001                          0x00000006
#define RS_COL_FMT_111A                          0x00000008
#define RS_COL_FMT_1110                          0x00000009
#define RS_COL_FMT_1111                          0x0000000a

/*
 * RS_TEX_CN enum
 */

#define RS_TEX_CN_NO_WRITE                       0x00000000
#define RS_TEX_CN_WRITE                          0x00000001

/*
 * RS_COL_CN enum
 */

#define RS_COL_CN_NO_WRITE                       0x00000000
#define RS_COL_CN_WRITE                          0x00000001

/*
 * RS_US_CMD_TYPE enum
 */

#define RS_US_CMD_STRQ_LO                        0x00000000
#define RS_US_CMD_STR_HI                         0x00000001
#define RS_US_CMD_STQ_HI                         0x00000002
#define RS_US_CMD_REG                            0x00000003

/*******************************************************
 * SC Enums
 *******************************************************/

/*
 * SC_RS_CMD enum
 */

#define SC_RS_CMD_QUAD                           0x00000000
#define SC_RS_CMD_REGISTER                       0x00000001

/*
 * SC_RS_DEST enum
 */

#define SC_RS_DEST_NONE                          0x00000000
#define SC_RS_DEST_A                             0x00000001
#define SC_RS_DEST_B                             0x00000002
#define SC_RS_DEST_AB                            0x00000003

/*
 * SC_RS_INC enum
 */

#define SC_RS_INC_NONE                           0x00000000
#define SC_RS_INC_A                              0x00000001
#define SC_RS_INC_B                              0x00000002
#define SC_RS_INC_AB                             0x00000003

/*
 * SC_ZB_CMD enum
 */

#define SC_ZB_CMD_QUAD0                          0x00000000
#define SC_ZB_CMD_QUAD1                          0x00000001
#define SC_ZB_CMD_REGISTER                       0x00000002

/*
 * SC_CLIP_SCISSOR_LIMITS value
 */

#define SC_CLIP_SCISSOR_MIN            0x00000000
#define SC_CLIP_SCISSOR_MAX            0x00001fff

/*******************************************************
 * TX Enums
 *******************************************************/

/*
 * TX_US_CMD enum
 */

#define TX_US_CMD_COLOR16                        0x00000000
#define TX_US_CMD_COLOR8                         0x00000001
#define TX_US_CMD_COLOR_GAMMA8                   0x00000002
#define TX_US_CMD_COLOR_FLT                      0x00000003

/*
 * TX_US_FLT enum
 */

#define TX_US_F16                                0x00000000
#define TX_US_F32                                0x00000001

/*
 * CLAMP_FUNC enum
 */

#define TX_CLAMP_WRAP                            0x00000000
#define TX_CLAMP_MIRROR                          0x00000001
#define TX_CLAMP_CLAMP                           0x00000002
#define TX_CLAMP_MIRROR_ONCE                     0x00000003
#define TX_CLAMP_CLAMP_HALF                      0x00000004
#define TX_CLAMP_MIRROR_ONCE_HALF                0x00000005
#define TX_CLAMP_CLAMP_BORDER                    0x00000006
#define TX_CLAMP_MIRROR_ONCE_BORDER              0x00000007

/*
 * MAG_FILTER enum
 */

#define TX_MAG_RESERVED                          0x00000000
#define TX_MAG_POINT                             0x00000001
#define TX_MAG_LINEAR                            0x00000002
#define TX_MAG_ANISOTROPIC                       0x00000003

/*
 * MIN_FILTER enum
 */

#define TX_MIN_RESERVED                          0x00000000
#define TX_MIN_POINT                             0x00000001
#define TX_MIN_LINEAR                            0x00000002
#define TX_MIN_ANISOTROPIC                       0x00000003

/*
 * MIP_FILTER enum
 */

#define TX_MIP_NONE                              0x00000000
#define TX_MIP_POINT                             0x00000001
#define TX_MIP_LINEAR                            0x00000002
#define TX_MIP_RESERVED                          0x00000003

/*
 * VOL_FILTER enum
 */

#define TX_VOL_NONE                              0x00000000
#define TX_VOL_POINT                             0x00000001
#define TX_VOL_LINEAR                            0x00000002
#define TX_VOL_RESERVED                          0x00000003

/*
 * MAX_ANIS enum
 */

#define TX_MAX_ANIS_1_TO_1                       0x00000000
#define TX_MAX_ANIS_2_TO_1                       0x00000001
#define TX_MAX_ANIS_4_TO_1                       0x00000002
#define TX_MAX_ANIS_8_TO_1                       0x00000003
#define TX_MAX_ANIS_16_TO_1                      0x00000004

/*
 * CHROMA_KEY_MODE enum
 */

#define TX_CHROMA_KEY_DISABLE                    0x00000000
#define TX_CHROMA_KEY_CULL                       0x00000001
#define TX_CHROMA_KEY_BLEND                      0x00000002

/*
 * YUV_TO_RGB_MODE enum
 */

#define TX_YUV_TO_RGB_DISABLE                    0x00000000
#define TX_YUV_TO_RGB_CLAMP                      0x00000001
#define TX_YUV_TO_RGB_NOCLAMP                    0x00000002

/*
 * TX_FMT enum
 */

#define TX_FMT_8                                 0x00000000
#define TX_FMT_16                                0x00000001
#define TX_FMT_4_4                               0x00000002
#define TX_FMT_8_8                               0x00000003
#define TX_FMT_16_16                             0x00000004
#define TX_FMT_3_3_2                             0x00000005
#define TX_FMT_5_6_5                             0x00000006
#define TX_FMT_6_5_5                             0x00000007
#define TX_FMT_11_11_10                          0x00000008
#define TX_FMT_10_11_11                          0x00000009
#define TX_FMT_4_4_4_4                           0x0000000a
#define TX_FMT_1_5_5_5                           0x0000000b
#define TX_FMT_8_8_8_8                           0x0000000c
#define TX_FMT_2_10_10_10                        0x0000000d
#define TX_FMT_16_16_16_16                       0x0000000e
#define TX_FMT_DXT1                              0x0000000f
#define TX_FMT_DXT2_3                            0x00000010
#define TX_FMT_DXT4_5                            0x00000011
#define TX_FMT_Y8                                0x00000012
#define TX_FMT_AVYU444                           0x00000013
#define TX_FMT_VYUY422                           0x00000014
#define TX_FMT_YVYU422                           0x00000015
#define TX_FMT_16_MPEG                           0x00000016
#define TX_FMT_16_16_MPEG                        0x00000017
#define TX_FMT_16f                               0x00000018
#define TX_FMT_16f_16f                           0x00000019
#define TX_FMT_16f_16f_16f_16f                   0x0000001a
#define TX_FMT_32f                               0x0000001b
#define TX_FMT_32f_32f                           0x0000001c
#define TX_FMT_32f_32f_32f_32f                   0x0000001d
#define TX_FMT_W24_FP                            0x0000001e

/*
 * TX_CACHE enum
 */

#define TX_CACHE_WHOLE                           0x00000000
#define TX_CACHE_RESERVED                        0x00000001
#define TX_CACHE_HALF_REGION_0                   0x00000002
#define TX_CACHE_HALF_REGION_1                   0x00000003
#define TX_CACHE_FOURTH_REGION_0                 0x00000004
#define TX_CACHE_FOURTH_REGION_1                 0x00000005
#define TX_CACHE_FOURTH_REGION_2                 0x00000006
#define TX_CACHE_FOURTH_REGION_3                 0x00000007
#define TX_CACHE_EIGHTH_REGION_0                 0x00000008
#define TX_CACHE_EIGHTH_REGION_1                 0x00000009
#define TX_CACHE_EIGHTH_REGION_2                 0x0000000a
#define TX_CACHE_EIGHTH_REGION_3                 0x0000000b
#define TX_CACHE_EIGHTH_REGION_4                 0x0000000c
#define TX_CACHE_EIGHTH_REGION_5                 0x0000000d
#define TX_CACHE_EIGHTH_REGION_6                 0x0000000e
#define TX_CACHE_EIGHTH_REGION_7                 0x0000000f
#define TX_CACHE_SIXTEENTH_REGION_0              0x00000010
#define TX_CACHE_SIXTEENTH_REGION_1              0x00000011
#define TX_CACHE_SIXTEENTH_REGION_2              0x00000012
#define TX_CACHE_SIXTEENTH_REGION_3              0x00000013
#define TX_CACHE_SIXTEENTH_REGION_4              0x00000014
#define TX_CACHE_SIXTEENTH_REGION_5              0x00000015
#define TX_CACHE_SIXTEENTH_REGION_6              0x00000016
#define TX_CACHE_SIXTEENTH_REGION_7              0x00000017
#define TX_CACHE_SIXTEENTH_REGION_8              0x00000018
#define TX_CACHE_SIXTEENTH_REGION_9              0x00000019
#define TX_CACHE_SIXTEENTH_REGION_A              0x0000001a
#define TX_CACHE_SIXTEENTH_REGION_B              0x0000001b
#define TX_CACHE_SIXTEENTH_REGION_C              0x0000001c
#define TX_CACHE_SIXTEENTH_REGION_D              0x0000001d
#define TX_CACHE_SIXTEENTH_REGION_E              0x0000001e
#define TX_CACHE_SIXTEENTH_REGION_F              0x0000001f

/*
 * TX_FMT_SEL enum
 */

#define TX_FMT_SEL_C0                            0x00000000
#define TX_FMT_SEL_C1                            0x00000001
#define TX_FMT_SEL_C2                            0x00000002
#define TX_FMT_SEL_C3                            0x00000003
#define TX_FMT_SEL_0                             0x00000004
#define TX_FMT_SEL_1                             0x00000005

/*
 * ENDIAN_SWAP enum
 */

#define TX_SWAP_NONE                             0x00000000
#define TX_SWAP_16                               0x00000001
#define TX_SWAP_32                               0x00000002
#define TX_SWAP_HALF_DWORD                       0x00000003

/*
 * MACRO_TILE enum
 */

#define TX_MACRO_TILE_LINEAR                     0x00000000
#define TX_MACRO_TILE_TILED                      0x00000001

/*
 * MICRO_TILE enum
 */

#define TX_MICRO_TILE_LINEAR                     0x00000000
#define TX_MICRO_TILE_TILED                      0x00000001
#define TX_MICRO_TILE_TILED_SQUARE               0x00000002

/*
 * TEX_COORD_TYPE enum
 */

#define TX_TEX_COORD_2D                             0x00000000
#define TX_TEX_COORD_3D                             0x00000001
#define TX_TEX_COORD_CUBE                           0x00000002

/*
 * TX_PERF_SEL enum
 */

#define TX_PERF_OFF                              0x00000000
#define TX_PERF_ON                               0x00000001
#define TX_PERF_QUADS                            0x00000002
#define TX_PERF_REGS                             0x00000003
#define TX_PERF_LINE4                            0x00000004
#define TX_PERF_MISS                             0x00000005
#define TX_PERF_ACK                              0x00000006
#define TX_PERF_LAT64                            0x00000007
#define TX_PERF_TX_IDLE                          0x00000008
#define TX_PERF_TX_STALL                         0x00000009
#define TX_PERF_TX_FMT_STALL                     0x0000000a
#define TX_PERF_TX_ANISO_STALL                   0x0000000b
#define TX_PERF_TX_LOD_STALL                     0x0000000c
#define TX_PERF_TX_VOL_STALL                     0x0000000d
#define TX_PERF_TX_TCOL_STALL                    0x0000000e
#define TX_PERF_TX_INVAL_STALL                   0x0000000f
#define TX_PERF_TX_ALIAS_STALL                   0x00000010
#define TX_PERF_TX_AQFULL_STALL                  0x00000011
#define TX_PERF_TX_QFULL_STALL                   0x00000012
#define TX_PERF_TX_MREQ_STALL                    0x00000013
#define TX_PERF_MC_STALL                         0x00000014
#define TX_PERF_TX_ACOL_STALL                    0x00000015
#define TX_PERF_US_STALL                         0x00000016

/*
 * TX_TRI_PERF enum
 */

#define TX_TRI_PERF_ZERO                         0x00000000
#define TX_TRI_PERF_ONE_EIGHTH                   0x00000001
#define TX_TRI_PERF_ONE_FOURTH                   0x00000002
#define TX_TRI_PERF_THREE_EIGHTHS                0x00000003

/*******************************************************
 * US Enums
 *******************************************************/

/*
 * US_FG_CMD enum
 */

#define US_FG_CMD_W24                            0x00000000
#define US_FG_CMD_C32                            0x00000001
#define US_FG_CMD_C64                            0x00000002
#define US_FG_CMD_C128                           0x00000003

/*
 * US_LEVEL enum
 */

#define US_NLEVEL_1                              0x00000000
#define US_NLEVEL_2                              0x00000001
#define US_NLEVEL_3                              0x00000002
#define US_NLEVEL_4                              0x00000003

/*
 * US_TEX_INST enum
 */

#define US_TEX_INST_NOP                          0x00000000
#define US_TEX_INST_LOOKUP                       0x00000001
#define US_TEX_INST_KILL_LT_0                    0x00000002
#define US_TEX_INST_LOOKUP_PROJ                  0x00000003
#define US_TEX_INST_LOOKUP_LODBIAS               0x00000004

/*
 * US_OUT_FMT enum
 */

#define US_OUT_FMT_C4_8                          0x00000000
#define US_OUT_FMT_C4_10                         0x00000001
#define US_OUT_FMT_C4_G10                        0x00000002
#define US_OUT_FMT_C1_16                         0x00000003
#define US_OUT_FMT_C2_16                         0x00000004
#define US_OUT_FMT_C4_16                         0x00000005
#define US_OUT_FMT_C1_16_MPEG                    0x00000006
#define US_OUT_FMT_C2_16_MPEG                    0x00000007
#define US_OUT_FMT_C2_4                          0x00000008
#define US_OUT_FMT_C3_3_3_2                      0x00000009
#define US_OUT_FMT_C3_6_5_5                      0x0000000a
#define US_OUT_FMT_C3_11_11_10                   0x0000000b
#define US_OUT_FMT_C3_10_11_11                   0x0000000c
#define US_OUT_FMT_C4_2_10_10_10                 0x0000000d
#define US_OUT_FMT_C0                            0x0000000f
#define US_OUT_FMT_C1_F16                        0x00000010
#define US_OUT_FMT_C2_F16                        0x00000011
#define US_OUT_FMT_C4_F16                        0x00000012
#define US_OUT_FMT_C1_F32                        0x00000013
#define US_OUT_FMT_C2_F32                        0x00000014
#define US_OUT_FMT_C4_F32                        0x00000015

/*
 * US_OUT_FMT_SEL enum
 */

#define US_OUT_FMT_SEL_A                         0x00000000
#define US_OUT_FMT_SEL_R                         0x00000001
#define US_OUT_FMT_SEL_G                         0x00000002
#define US_OUT_FMT_SEL_B                         0x00000003

/*
 * US_W_FMT_FMT enum
 */

#define US_W_FMT_ZERO                            0x00000000
#define US_W_FMT_W24                             0x00000001
#define US_W_FMT_W24_FP                          0x00000002

/*
 * US_W_FMT_SRC enum
 */

#define US_W_FMT_SRC_US                          0x00000000
#define US_W_FMT_SRC_RS                          0x00000001

/*
 * US_RGB_MASK enum
 */

#define US_MASK_NONE                             0x00000000
#define US_MASK_R                                0x00000001
#define US_MASK_G                                0x00000002
#define US_MASK_RG                               0x00000003
#define US_MASK_B                                0x00000004
#define US_MASK_RB                               0x00000005
#define US_MASK_GB                               0x00000006
#define US_MASK_RGB                              0x00000007

/*
 * US_RNDR_TGT_SEL enum
 */

#define US_RNDR_TGT_A                            0x00000000
#define US_RNDR_TGT_B                            0x00000001
#define US_RNDR_TGT_C                            0x00000002
#define US_RNDR_TGT_D                            0x00000003

/*
 * US_SEL_RGB enum
 */

#define US_SEL_RGB_RGBA0                         0x00000000
#define US_SEL_RGB_RRRR0                         0x00000001
#define US_SEL_RGB_GGGG0                         0x00000002
#define US_SEL_RGB_BBBB0                         0x00000003
#define US_SEL_RGB_RGBA1                         0x00000004
#define US_SEL_RGB_RRRR1                         0x00000005
#define US_SEL_RGB_GGGG1                         0x00000006
#define US_SEL_RGB_BBBB1                         0x00000007
#define US_SEL_RGB_RGBA2                         0x00000008
#define US_SEL_RGB_RRRR2                         0x00000009
#define US_SEL_RGB_GGGG2                         0x0000000a
#define US_SEL_RGB_BBBB2                         0x0000000b
#define US_SEL_RGB_AAAA0                         0x0000000c
#define US_SEL_RGB_AAAA1                         0x0000000d
#define US_SEL_RGB_AAAA2                         0x0000000e
#define US_SEL_RGB_RGBAP                         0x0000000f
#define US_SEL_RGB_RRRRP                         0x00000010
#define US_SEL_RGB_GGGGP                         0x00000011
#define US_SEL_RGB_BBBBP                         0x00000012
#define US_SEL_RGB_AAAAP                         0x00000013
#define US_SEL_RGB_ZERO                          0x00000014
#define US_SEL_RGB_ONE                           0x00000015
#define US_SEL_RGB_HALF                          0x00000016
#define US_SEL_RGB_GBR0                          0x00000017
#define US_SEL_RGB_GBR1                          0x00000018
#define US_SEL_RGB_GBR2                          0x00000019
#define US_SEL_RGB_BRG0                          0x0000001a
#define US_SEL_RGB_BRG1                          0x0000001b
#define US_SEL_RGB_BRG2                          0x0000001c
#define US_SEL_RGB_ABG0                          0x0000001d
#define US_SEL_RGB_ABG1                          0x0000001e
#define US_SEL_RGB_ABG2                          0x0000001f

/*
 * US_IMOD enum
 */

#define US_IMOD_OFF                              0x00000000
#define US_IMOD_NEG                              0x00000001
#define US_IMOD_ABS                              0x00000002
#define US_IMOD_NAB                              0x00000003

/*
 * US_SRCP_OP enum
 */

#define US_SRCP_OP_BIAS                          0x00000000
#define US_SRCP_OP_SUB                           0x00000001
#define US_SRCP_OP_ADD                           0x00000002
#define US_SRCP_OP_INV                           0x00000003

/*
 * US_OP_RGB enum
 */

#define US_OP_RGB_MAD                            0x00000000
#define US_OP_RGB_DP3                            0x00000001
#define US_OP_RGB_DP4                            0x00000002
#define US_OP_RGB_D2A                            0x00000003
#define US_OP_RGB_MIN                            0x00000004
#define US_OP_RGB_MAX                            0x00000005
#define US_OP_RGB_CND                            0x00000007
#define US_OP_RGB_CMP                            0x00000008
#define US_OP_RGB_FRC                            0x00000009
#define US_OP_RGB_SOP                            0x0000000a

/*
 * US_OMOD enum
 */

#define US_OMOD_OFF                              0x00000000
#define US_OMOD_U2                               0x00000001
#define US_OMOD_U4                               0x00000002
#define US_OMOD_U8                               0x00000003
#define US_OMOD_D2                               0x00000004
#define US_OMOD_D4                               0x00000005
#define US_OMOD_D8                               0x00000006

/*
 * US_SEL_ALPHA enum
 */

#define US_SEL_ALPHA_R0                          0x00000000
#define US_SEL_ALPHA_G0                          0x00000001
#define US_SEL_ALPHA_B0                          0x00000002
#define US_SEL_ALPHA_R1                          0x00000003
#define US_SEL_ALPHA_G1                          0x00000004
#define US_SEL_ALPHA_B1                          0x00000005
#define US_SEL_ALPHA_R2                          0x00000006
#define US_SEL_ALPHA_G2                          0x00000007
#define US_SEL_ALPHA_B2                          0x00000008
#define US_SEL_ALPHA_A0                          0x00000009
#define US_SEL_ALPHA_A1                          0x0000000a
#define US_SEL_ALPHA_A2                          0x0000000b
#define US_SEL_ALPHA_RP                          0x0000000c
#define US_SEL_ALPHA_GP                          0x0000000d
#define US_SEL_ALPHA_BP                          0x0000000e
#define US_SEL_ALPHA_AP                          0x0000000f
#define US_SEL_ALPHA_ZERO                        0x00000010
#define US_SEL_ALPHA_ONE                         0x00000011
#define US_SEL_ALPHA_HALF                        0x00000012

/*
 * US_OP_ALPHA enum
 */

#define US_OP_ALPHA_MAD                          0x00000000
#define US_OP_ALPHA_DP                           0x00000001
#define US_OP_ALPHA_MIN                          0x00000002
#define US_OP_ALPHA_MAX                          0x00000003
#define US_OP_ALPHA_CND                          0x00000005
#define US_OP_ALPHA_CMP                          0x00000006
#define US_OP_ALPHA_FRC                          0x00000007
#define US_OP_ALPHA_EX2                          0x00000008
#define US_OP_ALPHA_LN2                          0x00000009
#define US_OP_ALPHA_RCP                          0x0000000a
#define US_OP_ALPHA_RSQ                          0x0000000b

/*******************************************************
 * FG Enums
 *******************************************************/

/*
 * FOG_FUNCTION enum
 */

#define FG_LINEAR                                0x00000000
#define FG_EXP                                   0x00000001
#define FG_EXP2                                  0x00000002
#define FG_FACTOR                                0x00000003

/*
 * ALPHA_FUNCTION enum
 */

#define FG_AF_NEVER                                 0x00000000
#define FG_AF_LESS                                  0x00000001
#define FG_AF_EQUAL                                 0x00000002
#define FG_AF_LE                                    0x00000003
#define FG_AF_GREATER                               0x00000004
#define FG_AF_NOTEQUAL                              0x00000005
#define FG_AF_GE                                    0x00000006
#define FG_AF_ALWAYS                                0x00000007

/*
 * DEPTH_SRC enum
 */

#define FG_DEPTH_SRC_PEQ                         0x00000000
#define FG_DEPTH_SRC_DISCRETE                    0x00000001

/*
 * FG_ZB_COMMAND enum
 */

#define FG_ZB_CMD_Q0_PEQ                         0x00000000
#define FG_ZB_CMD_Q1_PEQ                         0x00000001
#define FG_ZB_CMD_Q0_DIR                         0x00000002
#define FG_ZB_CMD_Q1_DIR                         0x00000003
#define FG_ZB_CMD_REG_CTX0                       0x00000004
#define FG_ZB_CMD_REG_CTX1                       0x00000005

/*
 * FG_PERF_SEL enum
 */

#define FG_PERF_OFF                              0x00000000
#define FG_PERF_ON                               0x00000001
#define FG_PERF_USFF_STALL                       0x00000002
#define FG_PERF_USFF_FULL                        0x00000003
#define FG_PERF_USFF_EMPTY                       0x00000004
#define FG_PERF_US_VALID                         0x00000005
#define FG_PERF_USFF_VLD                         0x00000006
#define FG_PERF_USFF_WAIT                        0x00000007
#define FG_PERF_USFF_DONE                        0x00000008
#define FG_PERF_RDY_FOR_USFF                     0x00000009
#define FG_PERF_SCFF_STALL                       0x0000000a
#define FG_PERF_SCFF_FULL                        0x0000000b
#define FG_PERF_SCFF_EMPTY                       0x0000000c
#define FG_PERF_SC_VALID                         0x0000000d
#define FG_PERF_SCFF_VLD                         0x0000000e
#define FG_PERF_RDY_FOR_SCFF                     0x0000000f
#define FG_PERF_ZBFF_STALL                       0x00000010
#define FG_PERF_ZBFF_FULL                        0x00000011
#define FG_PERF_ZBFF_EMPTY                       0x00000012
#define FG_PERF_ZBFF_RDY                         0x00000013
#define FG_PERF_ZB_STALL                         0x00000014
#define FG_PERF_FG_STALL                         0x00000015
#define FG_PERF_FG_IDLE                          0x00000016
#define FG_PERF_FG_VALID                         0x00000017
#define FG_PERF_FU2SC_RDY                        0x00000018
#define FG_PERF_FU2US_RDY                        0x00000019

/*******************************************************
 * CB Enums
 *******************************************************/

/*
 * CB_COMB_FCN enum
 */

#define CB_COMB_ADD_CLAMP                        0x00000000
#define CB_COMB_ADD                              0x00000001
#define CB_COMB_S_MINUS_D_CLAMP                  0x00000002
#define CB_COMB_S_MINUS_D                        0x00000003
#define CB_COMB_MIN                              0x00000004
#define CB_COMB_MAX                              0x00000005
#define CB_COMB_D_MINUS_S_CLAMP                  0x00000006
#define CB_COMB_D_MINUS_S                        0x00000007

/*
 * CB_BLEND enum
 */

#define CB_BLEND_D3D_ZERO                        0x00000001
#define CB_BLEND_D3D_ONE                         0x00000002
#define CB_BLEND_D3D_SRCCOLOR                    0x00000003
#define CB_BLEND_D3D_INVSRCCOLOR                 0x00000004
#define CB_BLEND_D3D_SRCALPHA                    0x00000005
#define CB_BLEND_D3D_INVSRCALPHA                 0x00000006
#define CB_BLEND_D3D_DESTALPHA                   0x00000007
#define CB_BLEND_D3D_INVDESTALPHA                0x00000008
#define CB_BLEND_D3D_DESTCOLOR                   0x00000009
#define CB_BLEND_D3D_INVDESTCOLOR                0x0000000a
#define CB_BLEND_D3D_SRCALPHASAT                 0x0000000b
#define CB_BLEND_D3D_BOTHSRCALPHA                0x0000000c
#define CB_BLEND_D3D_BOTHINVSRCALPHA             0x0000000d
#define CB_BLEND_GL_ZERO                         0x00000020
#define CB_BLEND_GL_ONE                          0x00000021
#define CB_BLEND_GL_SRC_COLOR                    0x00000022
#define CB_BLEND_GL_ONE_MINUS_SRC_COLOR          0x00000023
#define CB_BLEND_GL_DST_COLOR                    0x00000024
#define CB_BLEND_GL_ONE_MINUS_DST_COLOR          0x00000025
#define CB_BLEND_GL_SRC_ALPHA                    0x00000026
#define CB_BLEND_GL_ONE_MINUS_SRC_ALPHA          0x00000027
#define CB_BLEND_GL_DST_ALPHA                    0x00000028
#define CB_BLEND_GL_ONE_MINUS_DST_ALPHA          0x00000029
#define CB_BLEND_GL_SRC_ALPHA_SATURATE           0x0000002a
#define CB_BLEND_GL_CONSTANT_COLOR               0x0000002b
#define CB_BLEND_GL_ONE_MINUS_CONSTANT_COLOR     0x0000002c
#define CB_BLEND_GL_CONSTANT_ALPHA               0x0000002d
#define CB_BLEND_GL_ONE_MINUS_CONSTANT_ALPHA     0x0000002e

/*
 * CB_COLOR_ENDIAN enum
 */

#define CB_ENDIAN_NO_SWAP                        0x00000000
#define CB_ENDIAN_WORD_SWAP                      0x00000001
#define CB_ENDIAN_DWORD_SWAP                     0x00000002
#define CB_ENDIAN_HDWORD_SWAP                    0x00000003

/*
 * CB_CACHE_ENABLE enum
 */

#define CB_CACHE_EN_ALL                          0x00000000
#define CB_CACHE_EN_3D                           0x00000001
#define CB_CACHE_EN_2D                           0x00000002
#define CB_CACHE_EN_NONE                         0x00000003

/*
 * CB_CACHE_LINE_SIZE enum
 */

#define CB_CACHE_LINE_256_256                    0x00000000
#define CB_CACHE_LINE_256_128                    0x00000001
#define CB_CACHE_LINE_128_256                    0x00000002
#define CB_CACHE_LINE_128_128                    0x00000003

/*
 * CB_CACHE_AUTOFLUSH enum
 */

#define CB_CACHE_AUTOFLUSH_NONE                  0x00000000
#define CB_CACHE_AUTOFLUSH_2D                    0x00000001
#define CB_CACHE_AUTOFLUSH_3D                    0x00000002
#define CB_CACHE_AUTOFLUSH_ALL                   0x00000003

/*
 * CB_CACHE_AUTOFREE enum
 */

#define CB_CACHE_AUTOFREE_NONE                   0x00000000
#define CB_CACHE_AUTOFREE_2D                     0x00000001
#define CB_CACHE_AUTOFREE_3D                     0x00000002
#define CB_CACHE_AUTOFREE_ALL                    0x00000003

/*
 * CB_CACHE_FLUSH enum
 */

#define CB_FLUSH_NONE                            0x00000000
#define CB_FLUSH_2D                              0x00000001
#define CB_FLUSH_3D                              0x00000002
#define CB_FLUSH_ALL                             0x00000003

/*
 * CB_CACHE_FREE enum
 */

#define CB_FREE_NONE                             0x00000000
#define CB_FREE_2D                               0x00000001
#define CB_FREE_3D                               0x00000002
#define CB_FREE_ALL                              0x00000003

/*
 * CB_RESOLVE_FMT enum
 */

#define CB_RESOLVE_ARGB_1555                     0x00000000
#define CB_RESOLVE_RGB_565                       0x00000001
#define CB_RESOLVE_RGBA_8888                     0x00000002

/*
 * CB_COLOR_FMT enum
 */

#define CB_COLOR_ARGB1555                        0x00000003
#define CB_COLOR_RGB565                          0x00000004
#define CB_COLOR_ARGB8888                        0x00000006
#define CB_COLOR_ARGB32323232                    0x00000007
#define CB_COLOR_I8                              0x00000009
#define CB_COLOR_ARGB16161616                    0x0000000a
#define CB_COLOR_YUV422_VYUY                     0x0000000b
#define CB_COLOR_YUV422_YVYU                     0x0000000c
#define CB_COLOR_UV88                            0x0000000d
#define CB_COLOR_ARGB4444                        0x0000000f

/*
 * CB_AA_NUM_SUBSAMPLES enum
 */

#define CB_AA_1_SUBSAMPLES                       0x00000000
#define CB_AA_3_SUBSAMPLES                       0x00000001
#define CB_AA_4_SUBSAMPLES                       0x00000002
#define CB_AA_6_SUBSAMPLES                       0x00000003

/*
 * CB_DITHER_MODE enum
 */

#define CB_DITHER_TRUNCATE                       0x00000000
#define CB_DITHER_ROUND                          0x00000001
#define CB_DITHER_LUT                            0x00000002

/*
 * CB_AARESOLVE_GAMMA enum
 */

#define CB_AARESOLVE_GAMMA_1_0                   0x00000000
#define CB_AARESOLVE_GAMMA_2_2                   0x00000001

/*
 * CB_MICRO_TILE enum
 */

#define CB_MICRO_TILE_LINEAR                     0x00000000
#define CB_MICRO_TILE_TILED                      0x00000001
#define CB_MICRO_TILE_TILED_SQUARE               0x00000002

/*
 * CB_PERF_SEL enum
 */

#define CB_CYCLE_COUNT                           0x00000000
#define CB_CACHE_MISS_COUNT                      0x00000001
#define CB_CACHE_FLUSH_COUNT                     0x00000002
#define CB_CACHE_EVICT_COUNT                     0x00000003
#define CB_CACHE_WRITE_ALLOCATE_COUNT            0x00000004
#define CB_BLENDER_STALLED_ON_MEMORY_CYCLE_COUNT 0x00000005
#define CB_TOTAL_QUAD_COUNT                      0x00000006
#define CB_NONZERO_COVERAGE_MASK_QUAD_COUNT      0x00000007
#define CB_DRAWN_QUAD_COUNT                      0x00000008
#define CB_MEM_RD_COUNT                          0x00000009
#define CB_STALLED_MEM_RD_CYCLE_COUNT            0x0000000a
#define CB_MEM_WR_COUNT                          0x0000000b
#define CB_STALLED_MEM_WR_CYCLE_COUNT            0x0000000c
#define CB_ZERO_MASK_MEM_WR_COUNT                0x0000000d
#define CB_UNPIPELINED_REGISTER_WRITE_STALL_CYCLE_COUNT 0x0000000e
#define CB_DF_EM_STALL_CYCLE_COUNT               0x0000000f
#define CB_AF_EM_STALL_CYCLE_COUNT               0x00000010
#define CB_OF_CC_STALL_CYCLE_COUNT               0x00000011
#define CB_RD_CC_STALL_CYCLE_COUNT               0x00000012
#define CB_WR_CC_STALL_CYCLE_COUNT               0x00000013
#define CB_OC_OF_STALL_CYCLE_COUNT               0x00000014
#define CB_CC_AF_STALL_CYCLE_COUNT               0x00000015
#define CB_WRITTEN_FULLY_COMPRESSED_TILE_COUNT   0x00000016
#define CB_WRITTEN_PARTIALLY_COMPRESSED_TILE_COUNT 0x00000017
#define CB_WRITTEN_UNCOMPRESSED_TILE_COUNT       0x00000018
#define CB_READ_FAST_CLEARED_TILE_COUNT          0x00000019
#define CB_READ_FULLY_COMPRESSED_TILE_COUNT      0x0000001a
#define CB_READ_PARTIALLY_COMPRESSED_TILE_COUNT  0x0000001b
#define CB_READ_UNCOMPRESSED_TILE_COUNT          0x0000001c
#define CB_FULLY_COMPRESSED_QUAD_TO_PARTIALLY_COMPRESSED_TILE_DIV_4_COUNT 0x0000001d
#define CB_FULLY_COMPRESSED_QUAD_TO_UNCOMPRESSED_TILE_DIV_4_COUNT 0x0000001e
#define CB_PARTIALLY_COMPRESSED_QUAD_TO_UNCOMPRESSED_TILE_DIV_4_COUNT 0x0000001f
#define CB_PARTIALLY_PIPELINED_REGISTER_WIRE_COUNT 0x00000020
#define CB_BUFFER_0_DRAW_QUAD_COUNT              0x00000021
#define CB_BUFFER_1_DRAW_QUAD_COUNT              0x00000022
#define CB_BUFFER_2_DRAW_QUAD_COUNT              0x00000023
#define CB_BUFFER_3_DRAW_QUAD_COUNT              0x00000024
#define CB_STARVED_CYCLE_COUNT                   0x00000025
#define CB_UNPIPELINED_REGISTER_WRITE_COUNT      0x00000026
#define CB_BLENDED_QUAD_COUNT                    0x00000027
#define CB_WR_DATA_FIFO_ALMOST_FULL_STALL_COUNT  0x00000028
#define CB_CACHE_MAX_MISS_COUNT_STALL_CYCLE_COUNT 0x00000029
#define CB_CACHE_MISS_ON_MISS_HIT_STALL_CYCLE_COUNT 0x0000002a
#define CB_CACHE_MISS_ON_MISS_STALL_CYCLE_COUNT  0x0000002b
#define CB_CACHE_DEWRITEALLOC_STALL_CYCLE_COUNT  0x0000002c
#define CB_WR_ALLOC_OPT_COUNT                    0x0000002d
#define CB_ZB_CB_STALL_CYCLE_COUNT               0x0000002e
#define CB_FG_PERF_COUNTER                       0x0000003f

/*
 * CB_2D_PERF_SEL enum
 */

#define CB_2D_PERF_CYCLES                        0x00000000
#define CB_2D_PERF_CC_FLUSH                      0x00000001
#define CB_2D_PERF_CC_EVICT                      0x00000002
#define CB_2D_PERF_CC_MISS                       0x00000003
#define CB_2D_PERF_E2_CB_DATA                    0x00000004
#define CB_2D_PERF_E2_CB_REG                     0x00000005
#define CB_2D_PERF_E2_CB_REQ                     0x00000006
#define CB_2D_PERF_WR_MC_REQ                     0x00000007
#define CB_2D_PERF_RD_MC_REQ                     0x00000008
#define CB_2D_PERF_E2_CB_STALL                   0x00000009
#define CB_2D_PERF_WR_MC_STALL                   0x0000000a
#define CB_2D_PERF_RD_MC_STALL                   0x0000000b
#define CB_2D_PERF_EI_DF_STALL                   0x0000000c
#define CB_2D_PERF_EI_AF_STALL                   0x0000000d
#define CB_2D_PERF_OF_OC_STALL                   0x0000000e
#define CB_2D_PERF_OF_OC_STARVE                  0x0000000f
#define CB_2D_PERF_AF_CC_STALL                   0x00000010
#define CB_2D_PERF_CC_CB_STALL                   0x00000011
#define CB_2D_PERF_CC_OF_STALL                   0x00000012
#define CB_2D_PERF_CC_WR_STALL                   0x00000013
#define CB_2D_PERF_CC_RD_STALL                   0x00000014
#define CB_2D_PERF_WR_SKIP_ZERO_MASK             0x00000015
#define CB_2D_PERF_CC_RD_WRITE_ALLOCATE          0x00000016
#define CB_2D_PERF_EI_CC_WRITE_ALLOCATE          0x00000017
#define CB_2D_PERF_IGNORE_PE_MODE_STALL          0x00000018

/*
 * CB_ROP enum
 */

#define CB_ROP_BLACKNESS                         0x00000000
#define CB_ROP_NOTSRCERASE                       0x00000001
#define CB_ROP_ROP3                              0x00000002
#define CB_ROP_NOTSRCCOPY                        0x00000003
#define CB_ROP_SRCERASE                          0x00000004
#define CB_ROP_DSTINVERT                         0x00000005
#define CB_ROP_SRCINVERT                         0x00000006
#define CB_ROP_ROP7                              0x00000007
#define CB_ROP_SRCAND                            0x00000008
#define CB_ROP_ROP9                              0x00000009
#define CB_ROP_ROPA                              0x0000000a
#define CB_ROP_MERGEPAINT                        0x0000000b
#define CB_ROP_SRCCOPY                           0x0000000c
#define CB_ROP_ROPD                              0x0000000d
#define CB_ROP_SRCPAINT                          0x0000000e
#define CB_ROP_WHITENESS                         0x0000000f

/*
 * CB_NUM_MULTIWRITES enum
 */

#define CB_NUM_MULTIWRITES_1                     0x00000000
#define CB_NUM_MULTIWRITES_2                     0x00000001
#define CB_NUM_MULTIWRITES_3                     0x00000002
#define CB_NUM_MULTIWRITES_4                     0x00000003

/*
 * CB_DISCARD_SRC_PIXELS enum
 */

#define CB_DISCARD_SRC_DISABLE                   0x00000000
#define CB_DISCARD_ZERO_SRC_A                    0x00000001
#define CB_DISCARD_ZERO_SRC_RGB                  0x00000002
#define CB_DISCARD_ZERO_SRC_ARGB                 0x00000003
#define CB_DISCARD_ONE_SRC_A                     0x00000004
#define CB_DISCARD_ONE_SRC_RGB                   0x00000005
#define CB_DISCARD_ONE_SRC_ARGB                  0x00000006

/*
 * CB_DISCARD_SRC_PIXELS_THRESHOLD enum
 */

#define CB_DISCARD_SRC_A_LTE_THRESHOLD           0x00000001
#define CB_DISCARD_SRC_RGB_LTE_THRESHOLD         0x00000002
#define CB_DISCARD_SRC_ARGB_LTE_THRESHOLD        0x00000003
#define CB_DISCARD_SRC_A_GTE_THRESHOLD           0x00000004
#define CB_DISCARD_SRC_RGB_GTE_THRESHOLD         0x00000005
#define CB_DISCARD_SRC_ARGB_GTE_THRESHOLD        0x00000006

/*******************************************************
 * ZB Enums
 *******************************************************/

/*
 * ZB_DEPTH_ENDIAN enum
 */

#define ZB_ENDIAN_NO_SWAP                        0x00000000
#define ZB_ENDIAN_WORD_SWAP                      0x00000001
#define ZB_ENDIAN_DWORD_SWAP                     0x00000002
#define ZB_ENDIAN_HDWORD_SWAP                    0x00000003

/*
 * MICRO_TILE enum
 */

#define ZB_MICRO_TILE_LINEAR                     0x00000000
#define ZB_MICRO_TILE_TILED                      0x00000001
#define ZB_MICRO_TILE_TILED_SQUARE               0x00000002

/*
 * MACRO_TILE enum
 */

#define ZB_MACRO_TILE_LINEAR                     0x00000000
#define ZB_MACRO_TILE_TILED                      0x00000001

/*
 * ZB_DEPTH_FORMAT enum
 */

#define ZB_DEPTH_FORMAT_16I_Z                    0x00000000
#define ZB_DEPTH_FORMAT_16F_Z                    0x00000001
#define ZB_DEPTH_FORMAT_24I_Z                    0x00000002

/*
 * ZB_ZFUNC enum
 */

#define ZB_ZFUNC_NEVER                           0x00000000
#define ZB_ZFUNC_LESS                            0x00000001
#define ZB_ZFUNC_LESS_EQUAL                      0x00000002
#define ZB_ZFUNC_EQUAL                           0x00000003
#define ZB_ZFUNC_GREATER_EQUAL                   0x00000004
#define ZB_ZFUNC_GREATER                         0x00000005
#define ZB_ZFUNC_NOT_EQUAL                       0x00000006
#define ZB_ZFUNC_ALWAYS                          0x00000007

/*
 * ZB_STENCILFUNC enum
 */

#define ZB_STENCILFUNC_NEVER                     0x00000000
#define ZB_STENCILFUNC_LESS                      0x00000001
#define ZB_STENCILFUNC_LESS_EQUAL                0x00000002
#define ZB_STENCILFUNC_EQUAL                     0x00000003
#define ZB_STENCILFUNC_GREATER_EQUAL             0x00000004
#define ZB_STENCILFUNC_GREATER                   0x00000005
#define ZB_STENCILFUNC_NOT_EQUAL                 0x00000006
#define ZB_STENCILFUNC_ALWAYS                    0x00000007

/*
 * ZB_STENCILOP enum
 */

#define ZB_STENCILOP_KEEP                        0x00000000
#define ZB_STENCILOP_ZERO                        0x00000001
#define ZB_STENCILOP_REPLACE                     0x00000002
#define ZB_STENCILOP_INC                         0x00000003
#define ZB_STENCILOP_DEC                         0x00000004
#define ZB_STENCILOP_INVERT                      0x00000005
#define ZB_STENCILOP_INC_WRAP                    0x00000006
#define ZB_STENCILOP_DEC_WRAP                    0x00000007

/*
 * ZB_PERF_SEL enum
 */

#define ZB_CACHE_MISS_COUNT_RV3                  0x00000000
#define ZB_CACHE_EVICT_COUNT                     0x00000001
#define ZB_CACHE_FLUSH_COUNT_RV3                 0x00000002
#define ZB_MEM_RD_COUNT_RV3                      0x00000003
#define ZB_MEM_WR_COUNT_RV3                      0x00000004
#define ZB_CACHE_FAST_FILL_ZCLEAR_COUNT_RV3      0x00000005
#define ZB_PIXEL_PASS_COUNT_RV3                  0x00000006
#define ZB_PIXEL_FAIL_COUNT                      0x00000007
#define ZB_PIXEL_MEMSTALL_COUNT                  0x00000008
#define ZB_SC2TZ_STALL_COUNT                     0x00000009
#define ZB_TZ2SC_STALL_COUNT                     0x0000000a
#define ZB_STALLED_MEMORY_READ_COUNT             0x0000000b
#define ZB_STALLED_MEMORY_WRITE_COUNT            0x0000000c
#define ZB_CACHE_ALIASING_STALL_COUNT            0x0000000d
#define ZB_STENCIL_PIXEL_COUNT                   0x0000000e

/*
 * ZB_FG_CMD enum
 */

#define ZB_FG_CMD_QUAD_Z                         0x00000000
#define ZB_FG_CMD_QUAD_W                         0x00000001
#define ZB_FG_CMD_REG                            0x00000002

/*
 * ZB_CB_CMD enum
 */

#define ZB_CB_CMD_QUAD0                          0x00000000
#define ZB_CB_CMD_QUAD1                          0x00000001
#define ZB_CB_CMD_REGISTER                       0x00000002
#define ZB_CB_CMD_REGISTER1                      0x00000003

/*
 * ZB_CB_CMD_REVISED enum
 */

#define ZB_CB_CMD_QUAD                           0x00000000
#define ZB_CB_CMD_QUAD_EOP                       0x00000001
#define ZB_CB_CMD_REGISTER                       0x00000002

/*
 * ZB_RS_CMD enum
 */

#define ZB_RS_CMD_QUAD                           0x00000000
#define ZB_RS_CMD_REGISTER                       0x00000001

/*
 * ZB_CACHE_INDEX_ARG_SEL enum
 */

#define ZB_CACHE_INDEX_ARG_SEL_CONSTANT_0        0x00000000
#define ZB_CACHE_INDEX_ARG_SEL_BIT_1             0x00000001
#define ZB_CACHE_INDEX_ARG_SEL_BIT_2             0x00000002
#define ZB_CACHE_INDEX_ARG_SEL_BIT_3             0x00000003
#define ZB_CACHE_INDEX_ARG_SEL_BIT_4             0x00000004
#define ZB_CACHE_INDEX_ARG_SEL_BIT_5             0x00000005
#define ZB_CACHE_INDEX_ARG_SEL_BIT_6             0x00000006
#define ZB_CACHE_INDEX_ARG_SEL_BIT_7             0x00000007
#define ZB_CACHE_INDEX_ARG_SEL_BIT_8             0x00000008
#define ZB_CACHE_INDEX_ARG_SEL_BIT_9             0x00000009
#define ZB_CACHE_INDEX_ARG_SEL_BIT_10            0x0000000a
#define ZB_CACHE_INDEX_ARG_SEL_BIT_11            0x0000000b
#define ZB_CACHE_INDEX_ARG_SEL_CONSTANT_1        0x0000000f

/*******************************************************
 * E2 Enums
 *******************************************************/

/*
 * E2_DST_TILE enum
 */

#define E2_DST_TILE_LINEAR                       0x00000000
#define E2_DST_TILE_MACRO                        0x00000001
#define E2_DST_TILE_MICRO                        0x00000002
#define E2_DST_TILE_MACRO_MICRO                  0x00000003

/*
 * E2_DST_TILE2 enum
 */

#define E2_DST_TILE2_16BPP_2X8                   0x00000000
#define E2_DST_TILE2_16BPP_4X4                   0x00000001

/*
 * E2_DST_DATATYPE enum
 */

#define E2_DST_DATATYPE_CI8                      0x00000002
#define E2_DST_DATATYPE_ARGB1555                 0x00000003
#define E2_DST_DATATYPE_RGB565                   0x00000004
#define E2_DST_DATATYPE_ARGB8888                 0x00000006

/*
 * E2_SRC_DATATYPE enum
 */

#define E2_SRC_DATATYPE_MONO_OPAQUE              0x00000000
#define E2_SRC_DATATYPE_MONO_TRANSPARENT         0x00000001
#define E2_SRC_DATATYPE_DST                      0x00000003
#define E2_SRC_DATATYPE_CI4                      0x00000004
#define E2_SRC_DATATYPE_CI8                      0x00000005
#define E2_SRC_DATATYPE_CI32                     0x00000006

/*
 * E2_SOURCE enum
 */

#define E2_SOURCE_MEM_RECT                       0x00000002
#define E2_SOURCE_HOST_LINEAR                    0x00000003
#define E2_SOURCE_HOST_LINEAR_ALIGNED            0x00000004

/*
 * E2_PIX_ORDER enum
 */

#define E2_PIX_ORDER_BIGENDIAN                   0x00000000
#define E2_PIX_ORDER_LITTLEENDIAN                0x00000001

/*
 * E2_ENDIAN enum
 */

#define E2_ENDIAN_NO_SWAP                        0x00000000
#define E2_ENDIAN_16BIT_SWAP                     0x00000001
#define E2_ENDIAN_32BIT_SWAP                     0x00000002
#define E2_ENDIAN_HALF_DWORD_SWAP                0x00000003

/*
 * E2_SRC_TILE enum
 */

#define E2_SRC_TILE_LINEAR                       0x00000000
#define E2_SRC_TILE_MACRO                        0x00000001

/*
 * E2_CNTL_DIRECTION enum
 */

#define E2_CNTL_DIRECTION_RLBT                   0x00000000
#define E2_CNTL_DIRECTION_RLTB                   0x00000001
#define E2_CNTL_DIRECTION_LRBT                   0x00000002
#define E2_CNTL_DIRECTION_LRTB                   0x00000003

/*
 * E2_X_DIR enum
 */

#define E2_X_DIR_RL                              0x00000000
#define E2_X_DIR_LR                              0x00000001

/*
 * E2_Y_DIR enum
 */

#define E2_Y_DIR_BT                              0x00000000
#define E2_Y_DIR_TB                              0x00000001

/*
 * E2_BRUSH_DATATYPE enum
 */

#define E2_BRUSH_DATATYPE_8X8_MONO_OPAQUE        0x00000000
#define E2_BRUSH_DATATYPE_8X8_MONO_TRANSPARENT   0x00000001
#define E2_BRUSH_DATATYPE_32X1_MONO_OPAQUE       0x00000006
#define E2_BRUSH_DATATYPE_32X1_MONO_TRANSPARENT  0x00000007
#define E2_BRUSH_DATATYPE_8X8_DST                0x0000000a
#define E2_BRUSH_DATATYPE_SOLID_FOREGROUND_BLIT  0x0000000d
#define E2_BRUSH_DATATYPE_SOLID_FOREGROUND_LINE  0x0000000e
#define E2_BRUSH_DATATYPE_SOLID_FOREGROUND_BLIT_ALIAS 0x0000000f

/*
 * E2_CLR_CMP_FCN_SRC enum
 */

#define E2_CLR_CMP_FCN_SRC_FALSE                 0x00000000
#define E2_CLR_CMP_FCN_SRC_TRUE                  0x00000001
#define E2_CLR_CMP_FCN_SRC_EQ_COLOR              0x00000004
#define E2_CLR_CMP_FCN_SRC_NEQ_COLOR             0x00000005
#define E2_CLR_CMP_FCN_SRC_EQ_FLIP               0x00000006

/*
 * E2_CLR_CMP_FCN_DST enum
 */

#define E2_CLR_CMP_FCN_DST_FALSE                 0x00000000
#define E2_CLR_CMP_FCN_DST_TRUE                  0x00000001
#define E2_CLR_CMP_FCN_DST_EQ_COLOR              0x00000004
#define E2_CLR_CMP_FCN_DST_NEQ_COLOR             0x00000005

/*
 * E2_CLR_CMP_SOURCE enum
 */

#define E2_CLR_CMP_SOURCE_DST                    0x00000000
#define E2_CLR_CMP_SOURCE_SRC                    0x00000001
#define E2_CLR_CMP_SOURCE_SRC_DST                0x00000002

/*******************************************************
 * VAP Enums
 *******************************************************/

/*
 * VAP_GA_VEC_ID enum
 */

#define VAP_VEC_POS                              0x00000000
#define VAP_VEC_RSVD1                            0x00000001
#define VAP_VEC_COLOR_0                          0x00000002
#define VAP_VEC_COLOR_1                          0x00000003
#define VAP_VEC_COLOR_2                          0x00000004
#define VAP_VEC_COLOR_3                          0x00000005
#define VAP_VEC_TEXTURE_0                        0x00000006
#define VAP_VEC_TEXTURE_1                        0x00000007
#define VAP_VEC_TEXTURE_2                        0x00000008
#define VAP_VEC_TEXTURE_3                        0x00000009
#define VAP_VEC_TEXTURE_4                        0x0000000a
#define VAP_VEC_TEXTURE_5                        0x0000000b
#define VAP_VEC_TEXTURE_6                        0x0000000c
#define VAP_VEC_TEXTURE_7                        0x0000000d
#define VAP_VEC_RSVD14                           0x0000000e
#define VAP_VEC_PNT_SIZE                         0x0000000f
#define VAP_VEC_RSVD16                           0x00000010
#define VAP_VEC_RSVD17                           0x00000011
#define VAP_VEC_RSVD18                           0x00000012
#define VAP_VEC_RSVD19                           0x00000013
#define VAP_VEC_RSVD20                           0x00000014
#define VAP_VEC_RSVD21                           0x00000015
#define VAP_VEC_RSVD22                           0x00000016
#define VAP_VEC_RSVD23                           0x00000017
#define VAP_VEC_RSVD24                           0x00000018
#define VAP_VEC_RSVD25                           0x00000019
#define VAP_VEC_RSVD26                           0x0000001a
#define VAP_VEC_RSVD27                           0x0000001b
#define VAP_VEC_RSVD28                           0x0000001c
#define VAP_VEC_POS_PKDRGBA                      0x0000001d
#define VAP_VEC_POS_PNT_SIZE                     0x0000001e
#define VAP_VEC_NULL                             0x0000001f

/*
 * VAP_GA_PRIM_TYPE enum
 */

#define VAP_GA_PRIM_TYPE_POINT                   0x00000000
#define VAP_GA_PRIM_TYPE_LINE                    0x00000001
#define VAP_GA_PRIM_TYPE_TRIANGLE                0x00000002

/*
 * VAP_DX_CLIP_SPACE_DEF enum
 */

#define VAP_CLIP_SPACE_OPEN_GL                   0x00000000
#define VAP_CLIP_SPACE_DIRECT_X                  0x00000001

/*
 * VF_PRIM_TYPE enum
 */

#define VAP_VF_PRIM_TYPE_NONE                        0x00000000
#define VAP_VF_PRIM_TYPE_POINTLIST                   0x00000001
#define VAP_VF_PRIM_TYPE_LINELIST                    0x00000002
#define VAP_VF_PRIM_TYPE_LINESTRIP                   0x00000003
#define VAP_VF_PRIM_TYPE_TRILIST                     0x00000004
#define VAP_VF_PRIM_TYPE_TRIFAN                      0x00000005
#define VAP_VF_PRIM_TYPE_TRISTRIP                    0x00000006
#define VAP_VF_PRIM_TYPE_TRI_WITH_WFLAGS             0x00000007
#define VAP_VF_PRIM_TYPE_RSVD_8                      0x00000008
#define VAP_VF_PRIM_TYPE_RSVD_9                      0x00000009
#define VAP_VF_PRIM_TYPE_RSVD_10                     0x0000000a
#define VAP_VF_PRIM_TYPE_RSVD_11                     0x0000000b
#define VAP_VF_PRIM_TYPE_LINELOOP                    0x0000000c
#define VAP_VF_PRIM_TYPE_QUADLIST                    0x0000000d
#define VAP_VF_PRIM_TYPE_QUADSTRIP                   0x0000000e
#define VAP_VF_PRIM_TYPE_POLYGON                     0x0000000f

/*
 * VF_PRIM_WALK enum
 */

#define VAP_VF_PRIM_WALK_STATE_BASED                 0x00000000
#define VAP_VF_PRIM_WALK_INDEXES                     0x00000001
#define VAP_VF_PRIM_WALK_VERTEX_LIST                 0x00000002
#define VAP_VF_PRIM_WALK_VERTEX_DATA                 0x00000003

/*
 * VAP_PSC_SGN_NORM_METHOD enum
 */

#define VAP_PSC_SGN_NORM_METHOD_ZERO             0x00000000
#define VAP_PSC_SGN_NORM_METHOD_ZERO_CLAMP_MINUS_ONE 0x00000001
#define VAP_PSC_SGN_NORM_METHOD_NO_ZERO          0x00000002

/*
 * VAP_AOS_FETCH_SIZE enum
 */

#define VAP_AOS_FETCH_SIZE_128_BIT               0x00000000
#define VAP_AOS_FETCH_SIZE_256_BIT               0x00000001

/*
 * VAP_VC_SWAP enum
 */

#define VAP_VC_NO_SWAP                           0x00000000
#define VAP_VC_SWAP_16_BIT                       0x00000001
#define VAP_VC_SWAP_32_BIT                       0x00000002
#define VAP_VC_SWAP_HALF_WORD                    0x00000003

/*
 * VAP_PSC_DATA_TYPE enum
 */

#define VAP_PSC_FLOAT_1                          0x00000000
#define VAP_PSC_FLOAT_2                          0x00000001
#define VAP_PSC_FLOAT_3                          0x00000002
#define VAP_PSC_FLOAT_4                          0x00000003
#define VAP_PSC_BYTE                             0x00000004
#define VAP_PSC_D3DCOLOR                         0x00000005
#define VAP_PSC_SHORT_2                          0x00000006
#define VAP_PSC_SHORT_4                          0x00000007
#define VAP_PSC_VECTOR_3_TTT                     0x00000008
#define VAP_PSC_VECTOR_3_EET                     0x00000009

/*
 * VAP_VTX_STATE_COLOR_ASSEMBLY enum
 */

#define VAP_VTX_STATE_SELECT_COLOR_0             0x00000000
#define VAP_VTX_STATE_SELECT_USER_COLOR_0        0x00000001
#define VAP_VTX_STATE_SELECT_USER_COLOR_1        0x00000002

/*
 * VAP_PSC_SGN_NORM_METHOD enum
 */

#define VAP_PSC_SGN_NORM_ZERO                    0x00000000
#define VAP_PSC_SGN_NORM_ZERO_CLAMP_MINUS_ONE    0x00000001
#define VAP_PSC_SGN_NORM_NO_ZERO                 0x00000002

/*
 * VAP_PVS_SWIZZLE_SEL enum
 */

#define VAP_PVS_SELECT_X                         0x00000000
#define VAP_PVS_SELECT_Y                         0x00000001
#define VAP_PVS_SELECT_Z                         0x00000002
#define VAP_PVS_SELECT_W                         0x00000003
#define VAP_PVS_SELECT_FP_ZERO                   0x00000004
#define VAP_PVS_SELECT_FP_ONE                    0x00000005

/*
 * VAP_PVS_ST_UPD_FIFO_SZ enum
 */

#define VAP_PVS_ST_UPD_FIFO_SZ_128               0x00000000
#define VAP_PVS_ST_UPD_FIFO_SZ_64                0x00000001
#define VAP_PVS_ST_UPD_FIFO_SZ_32                0x00000002
#define VAP_PVS_ST_UPD_FIFO_SZ_16                0x00000003

/*
 * VAP_PS_UCP_MODE enum
 */

#define VAP_PS_UCP_CULL_CNTR_NOBIAS              0x00000000
#define VAP_PS_UCP_CULL_CNTR_RDBIAS              0x00000001
#define VAP_PS_UCP_CLIP_RDBIAS_EXPD              0x00000002
#define VAP_PS_UCP_CLIP_ALWS_EXPAND              0x00000003

/*
 * VAP_PVS_SRC_REGISTER_TYPE enum
 */

#define VAP_PVS_SRC_REG_TEMPORARY                0x00000000
#define VAP_PVS_SRC_REG_INPUT                    0x00000001
#define VAP_PVS_SRC_REG_CONSTANT                 0x00000002
#define VAP_PVS_SRC_REG_ALT_TEMPORARY            0x00000003

/*
 * VAP_PVS_DST_REGISTER_TYPE enum
 */

#define VAP_PVS_DST_REG_TEMPORARY                0x00000000
#define VAP_PVS_DST_REG_A0                       0x00000001
#define VAP_PVS_DST_REG_OUT                      0x00000002
#define VAP_PVS_DST_REG_OUT_X_REPL               0x00000003
#define VAP_PVS_DST_REG_ALT_TEMPORARY            0x00000004
#define VAP_PVS_DST_REG_INPUT                    0x00000005

/*
 * VAP_PVS_SRC_MODIFIER enum
 */

#define VAP_PVS_NO_MODIFIER                      0x00000000
#define VAP_PVS_MODIFIER_SRCNEG                  0x00000001
#define VAP_PVS_NUMBER_OF_MODIFIERS              0x00000002

/*
 * VAP_PVS_ADDRESS_MODE enum
 */

#define VAP_PVS_ADDR_ABSOLUTE                    0x00000000
#define VAP_PVS_ADDR_RELATIVE_A0                 0x00000001
#define VAP_PVS_NUMBER_OF_ADDR_MOD               0x00000002

/*
 * VAP_PVS_REG_SEL enum
 */

#define VAP_PVS_X_SEL                            0x00000000
#define VAP_PVS_Y_SEL                            0x00000001
#define VAP_PVS_Z_SEL                            0x00000002
#define VAP_PVS_W_SEL                            0x00000003

/*
 * VAP_VECTOR_EN_OPCODE enum
 */

#define VAP_VE_NO_OP                             0x00000000
#define VAP_VE_DOT_PRODUCT                       0x00000001
#define VAP_VE_MULTIPLY                          0x00000002
#define VAP_VE_ADD                               0x00000003
#define VAP_VE_MULTIPLY_ADD                      0x00000004
#define VAP_VE_DISTANCE_VECTOR                   0x00000005
#define VAP_VE_FRACTION                          0x00000006
#define VAP_VE_MAXIMUM                           0x00000007
#define VAP_VE_MINIMUM                           0x00000008
#define VAP_VE_SET_GREATER_THAN_EQUAL            0x00000009
#define VAP_VE_SET_LESS_THAN                     0x0000000a
#define VAP_VE_MULTIPLYX2_ADD                    0x0000000b
#define VAP_VE_MULTIPLY_CLAMP                    0x0000000c
#define VAP_VE_FLT2FIX_DX                        0x0000000d
#define VAP_VE_FLT2FIX_DX_RND                    0x0000000e

/*
 * VAP_MATH_EN_OPCODE enum
 */

#define VAP_ME_NO_OP                             0x00000000
#define VAP_ME_EXP_BASE2_DX                      0x00000001
#define VAP_ME_LOG_BASE2_DX                      0x00000002
#define VAP_ME_EXP_BASEE_FF                      0x00000003
#define VAP_ME_LIGHT_COEFF_DX                    0x00000004
#define VAP_ME_POWER_FUNC_FF                     0x00000005
#define VAP_ME_RECIP_DX                          0x00000006
#define VAP_ME_RECIP_FF                          0x00000007
#define VAP_ME_RECIP_SQRT_DX                     0x00000008
#define VAP_ME_RECIP_SQRT_FF                     0x00000009
#define VAP_ME_MULTIPLY                          0x0000000a
#define VAP_ME_EXP_BASE2_FULL_DX                 0x0000000b
#define VAP_ME_LOG_BASE2_FULL_DX                 0x0000000c
#define VAP_ME_POWER_FUNC_FF_CLAMP_B             0x0000000d
#define VAP_ME_POWER_FUNC_FF_CLAMP_B1            0x0000000e
#define VAP_ME_POWER_FUNC_FF_CLAMP_01            0x0000000f

/*******************************************************
 * MC Enums
 *******************************************************/

/*
 * NUM_CHANNELS enum
 */

#define MC_ONE_CHANNEL                              0x00000000
#define MC_TWO_CHANNELS                             0x00000001
#define MC_FOUR_CHANNELS                            0x00000002

/*******************************************************
 * RBBM Enums
 *******************************************************/

/*******************************************************
 * BIF Enums
 *******************************************************/

/*******************************************************
 * HDP Enums
 *******************************************************/

/*******************************************************
 * DISPLAY Enums
 *******************************************************/

/*******************************************************
 * CP Enums
 *******************************************************/

/*******************************************************
 * VIP Enums
 *******************************************************/

/*******************************************************
 * CG Enums
 *******************************************************/

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


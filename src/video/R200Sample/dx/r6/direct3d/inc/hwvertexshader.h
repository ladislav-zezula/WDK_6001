

//    
//  Workfile: hwVertexShader.h
//
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 2000, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//
//  This file contains hardware-dependent code for vertex shaders. This
//  code presently compiles for both Radeon 100 and Radeon 200 with some
//  #if (RADEON_ASIC ...) check in some of the inline routines. This file
//  accompanies hwVertexShader.c. hwVertexShader.c does not contain any
//  references to the preprocessor define RADEON_ASIC.
//  
//  All device independent vertex shader code is in VertexShader.c and 
//  VertexShader.h.

#ifndef _HWVERTEXSHADER_H_
#define _HWVERTEXSHADER_H_

#include "VertexShader.h"
#include "writerendstate.h"
#include "tcl_state.h"

///////////////////////////////////////////////////////////////////////////////
// Defines
///////////////////////////////////////////////////////////////////////////////

//
// Radeon 200-specific defines for the PVS code store and constant store
//
#define ATI_R200_PVS_CODE_START_LOW         128
#define ATI_R200_PVS_CODE_START_HIGH        384
#define ATI_R200_PVS_CODE_SIZE_SEG          64
#define ATI_R200_PVS_CODE_SIZE              (2 * ATI_R200_PVS_CODE_SIZE_SEG)
#define ATI_R200_PVS_CODE_STRIDE            1

#define ATI_R200_PVS_STATE_START_LOW        0
#define ATI_R200_PVS_STATE_START_HIGH       256
#define ATI_R200_PVS_STATE_SIZE_SEG         96
#define ATI_R200_PVS_STATE_SIZE             (2 * ATI_R200_PVS_STATE_SIZE_SEG)
#define ATI_R200_PVS_STATE_STRIDE           1


#define ATI_PVS_CODE_SEG    1
#define ATI_PVS_STATE_SEG   2

//
// PVS opcode and operand defines (hopefully not Radeon 200-specific)
//

// Registers
#define ATI_PVS_REG_TEMP                    0x0
#define ATI_PVS_REG_IN                      0x1
#define ATI_PVS_REG_CONST                   0x2
#define ATI_PVS_REG_A0                      0x3
#define ATI_PVS_REG_OUT_POS                 0x4
#define ATI_PVS_REG_OUT_CLR                 0x5
#define ATI_PVS_REG_OUT_TEX                 0x6
#define ATI_PVS_REG_OUT_FOG                 0x7
#define ATI_PVS_REG_OUT_PNT_SIZE            0x8
#define ATI_PVS_REG_GARBAGE                 0x9

// Destination defines
#define ATI_PVS_OP_VE_NO_OP                 0x00
#define ATI_PVS_OP_VE_DP4                   0x01
#define ATI_PVS_OP_VE_MUL                   0x02
#define ATI_PVS_OP_VE_ADD                   0x03
#define ATI_PVS_OP_VE_MAD                   0x04
#define ATI_PVS_OP_VE_DST                   0x05
#define ATI_PVS_OP_VE_FRC                   0x06
#define ATI_PVS_OP_VE_MAX                   0x07
#define ATI_PVS_OP_VE_MIN                   0x08
#define ATI_PVS_OP_VE_SGE                   0x09
#define ATI_PVS_OP_VE_SLT                   0x0a
#define ATI_PVS_OP_VE_MUL_X2_ADD            0x0b
#define ATI_PVS_OP_VE_MUL_CLAMP             0x0c
#define ATI_PVS_OP_VE_FLT2FIX_FLR           0x0d
#define ATI_PVS_OP_VE_FLT2FIX_RND           0x0e
#define ATI_PVS_OP_VE_MAD_MACRO             0x80

#define ATI_PVS_OP_ME_NO_OP                 0x40
#define ATI_PVS_OP_ME_EXP_BASE_2_DX         0x41
#define ATI_PVS_OP_ME_LOG_BASE_2_DX         0x42
#define ATI_PVS_OP_ME_EXP_BASE_E_FF         0x43
#define ATI_PVS_OP_ME_LIT_DX                0x44
#define ATI_PVS_OP_ME_POW_FF                0x45
#define ATI_PVS_OP_ME_RCP_DX                0x46
#define ATI_PVS_OP_ME_RCP_FF                0x47
#define ATI_PVS_OP_ME_RSQ_DX                0x48
#define ATI_PVS_OP_ME_RSQ_FF                0x49
#define ATI_PVS_OP_ME_MUL                   0x4a
#define ATI_PVS_OP_ME_EXP_BASE_2_FULL_DX    0x4b
#define ATI_PVS_OP_ME_LOG_BASE_2_FULL_DX    0x4c

#define ATI_PVS_OP_MACRO_MODE               (1 << 7)

#define ATI_PVS_OP_MASK                     0x000000ff

// DirectX macros
#define ATI_PVS_MAC_OP_M44                  0x0100
#define ATI_PVS_MAC_OP_M43                  0x0200
#define ATI_PVS_MAC_OP_M34                  0x0400
#define ATI_PVS_MAC_OP_M33                  0x0800
#define ATI_PVS_MAC_OP_M32                  0x1000

#define ATI_PVS_DST_REG_TYPE_SHIFT          8
#define ATI_PVS_DST_REG_TYPE_MASK           (0xf<<ATI_PVS_DST_REG_TYPE_SHIFT)
#define ATI_PVS_DST_REG_OFFSET_SHIFT        13
#define ATI_PVS_DST_REG_OFFSET_MASK         (0xff<<ATI_PVS_DST_REG_OFFSET_SHIFT)

#define ATI_PVS_DST_WRITE_ENA_X             (1   << 20)
#define ATI_PVS_DST_WRITE_ENA_Y             (1   << 21)
#define ATI_PVS_DST_WRITE_ENA_Z             (1   << 22)
#define ATI_PVS_DST_WRITE_ENA_W             (1   << 23)
#define ATI_PVS_DST_WRITE_ENA_ALL           ((ATI_PVS_DST_WRITE_ENA_X) | \
                                             (ATI_PVS_DST_WRITE_ENA_Y) | \
                                             (ATI_PVS_DST_WRITE_ENA_Z) | \
                                             (ATI_PVS_DST_WRITE_ENA_W))
#define ATI_PVS_DST_WRITE_ENA_XY            ((ATI_PVS_DST_WRITE_ENA_X) | \
                                             (ATI_PVS_DST_WRITE_ENA_Y))          
#define ATI_PVS_DST_WRITE_ENA_XYZ           ((ATI_PVS_DST_WRITE_ENA_X) | \
                                             (ATI_PVS_DST_WRITE_ENA_Y) | \
                                             (ATI_PVS_DST_WRITE_ENA_Z))
 

#define ATI_PVS_MAKE_DST_OP(dwOp, dwRegType, dwRegOffset, dwWriteEna)  \
          ((dwOp)                                          |           \
           ((dwRegType)   << ATI_PVS_DST_REG_TYPE_SHIFT)   |           \
           ((dwRegOffset) << ATI_PVS_DST_REG_OFFSET_SHIFT) |           \
           (dwWriteEna))

// Source defines

// Used by the dwFlags parameter of VS_HwAssembleSrcOp()
#define ATI_PVS_FLAG_SRC_X_FORCE_ZERO       0x00000001
#define ATI_PVS_FLAG_SRC_Y_FORCE_ZERO       0x00000002
#define ATI_PVS_FLAG_SRC_Z_FORCE_ZERO       0x00000004
#define ATI_PVS_FLAG_SRC_W_FORCE_ZERO       0x00000008
#define ATI_PVS_FLAG_SRC_X_FORCE_ONE        0x00000010
#define ATI_PVS_FLAG_SRC_Y_FORCE_ONE        0x00000020
#define ATI_PVS_FLAG_SRC_Z_FORCE_ONE        0x00000040
#define ATI_PVS_FLAG_SRC_W_FORCE_ONE        0x00000080

#define ATI_PVS_FLAG_SRC_ALL_FORCE_ZERO     (ATI_PVS_FLAG_SRC_X_FORCE_ZERO) | \
                                            (ATI_PVS_FLAG_SRC_Y_FORCE_ZERO) | \
                                            (ATI_PVS_FLAG_SRC_Z_FORCE_ZERO) | \
                                            (ATI_PVS_FLAG_SRC_W_FORCE_ZERO)

#define ATI_PVS_FLAG_SRC_ALL_FORCE_ONE      (ATI_PVS_FLAG_SRC_X_FORCE_ONE) | \
                                            (ATI_PVS_FLAG_SRC_Y_FORCE_ONE) | \
                                            (ATI_PVS_FLAG_SRC_Z_FORCE_ONE) | \
                                            (ATI_PVS_FLAG_SRC_W_FORCE_ONE)

#define ATI_PVS_SRC_ADDR_MODE               (1 << 4)

#define ATI_PVS_SRC_REG_TYPE_SHIFT          0
#define ATI_PVS_SRC_REG_TYPE_MASK           (0xf<<ATI_PVS_SRC_REG_TYPE_SHIFT)
#define ATI_PVS_SRC_REG_OFFSET_SHIFT        5
#define ATI_PVS_SRC_REG_OFFSET_MASK         (0xff<<ATI_PVS_SRC_REG_OFFSET_SHIFT)
#define ATI_PVS_SRC_ADDR_SEL_SHIFT          29


#define ATI_PVS_SRC_SEL_X                   0x0
#define ATI_PVS_SRC_SEL_Y                   0x1
#define ATI_PVS_SRC_SEL_Z                   0x2
#define ATI_PVS_SRC_SEL_W                   0x3
#define ATI_PVS_SRC_SEL_FORCE_0             0x4
#define ATI_PVS_SRC_SEL_FORCE_1             0x5
#define ATI_PVS_SRC_SEL_FIELD               0x7

#define ATI_PVS_SRC_SELECT_X                0x0
#define ATI_PVS_SRC_SELECT_Y                0x1
#define ATI_PVS_SRC_SELECT_Z                0x2
#define ATI_PVS_SRC_SELECT_W                0x3
#define ATI_PVS_SRC_SELECT_FORCE_ZERO       0x4
#define ATI_PVS_SRC_SELECT_FORCE_ONE        0x5


#define ATI_PVS_SRC_SWIZZLE_SHIFT           13
#define ATI_PVS_SRC_SWIZZLE_SIZE             3
#define ATI_PVS_SRC_SWIZZLE_X_SHIFT         ((ATI_PVS_SRC_SWIZZLE_SHIFT) + (0*ATI_PVS_SRC_SWIZZLE_SIZE))
#define ATI_PVS_SRC_SWIZZLE_Y_SHIFT         ((ATI_PVS_SRC_SWIZZLE_SHIFT) + (1*ATI_PVS_SRC_SWIZZLE_SIZE))
#define ATI_PVS_SRC_SWIZZLE_Z_SHIFT         ((ATI_PVS_SRC_SWIZZLE_SHIFT) + (2*ATI_PVS_SRC_SWIZZLE_SIZE))
#define ATI_PVS_SRC_SWIZZLE_W_SHIFT         ((ATI_PVS_SRC_SWIZZLE_SHIFT) + (3*ATI_PVS_SRC_SWIZZLE_SIZE))

#define ATI_PVS_SRC_SEL_MASK                ((0x7 << ATI_PVS_SRC_SWIZZLE_X_SHIFT) | \
                                             (0x7 << ATI_PVS_SRC_SWIZZLE_Y_SHIFT) | \
                                             (0x7 << ATI_PVS_SRC_SWIZZLE_Z_SHIFT) | \
                                             (0x7 << ATI_PVS_SRC_SWIZZLE_W_SHIFT))

#define ATI_PVS_SRC_SWIZZLE_X(dwSel)        ((dwSel) << (ATI_PVS_SRC_SWIZZLE_X_SHIFT))
#define ATI_PVS_SRC_SWIZZLE_Y(dwSel)        ((dwSel) << (ATI_PVS_SRC_SWIZZLE_Y_SHIFT))
#define ATI_PVS_SRC_SWIZZLE_Z(dwSel)        ((dwSel) << (ATI_PVS_SRC_SWIZZLE_Z_SHIFT))
#define ATI_PVS_SRC_SWIZZLE_W(dwSel)        ((dwSel) << (ATI_PVS_SRC_SWIZZLE_W_SHIFT))

#define ATI_PVS_SRC_NO_SWIZZLE              ((ATI_PVS_SRC_SWIZZLE_X(ATI_PVS_SRC_SEL_X)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Y(ATI_PVS_SRC_SEL_Y)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Z(ATI_PVS_SRC_SEL_Z)) | \
                                             (ATI_PVS_SRC_SWIZZLE_W(ATI_PVS_SRC_SEL_W)))

#define ATI_PVS_SRC_FORCE_0000              ((ATI_PVS_SRC_SWIZZLE_X(ATI_PVS_SRC_SEL_FORCE_0)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Y(ATI_PVS_SRC_SEL_FORCE_0)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Z(ATI_PVS_SRC_SEL_FORCE_0)) | \
                                             (ATI_PVS_SRC_SWIZZLE_W(ATI_PVS_SRC_SEL_FORCE_0)))

#define ATI_PVS_SRC_FORCE_1111              ((ATI_PVS_SRC_SWIZZLE_X(ATI_PVS_SRC_SEL_FORCE_1)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Y(ATI_PVS_SRC_SEL_FORCE_1)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Z(ATI_PVS_SRC_SEL_FORCE_1)) | \
                                             (ATI_PVS_SRC_SWIZZLE_W(ATI_PVS_SRC_SEL_FORCE_1)))

#define ATI_PVS_SRC_FORCE_0001              ((ATI_PVS_SRC_SWIZZLE_X(ATI_PVS_SRC_SEL_FORCE_0)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Y(ATI_PVS_SRC_SEL_FORCE_0)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Z(ATI_PVS_SRC_SEL_FORCE_0)) | \
                                             (ATI_PVS_SRC_SWIZZLE_W(ATI_PVS_SRC_SEL_FORCE_1)))

#define ATI_PVS_SRC_FORCE_1001              ((ATI_PVS_SRC_SWIZZLE_X(ATI_PVS_SRC_SEL_FORCE_1)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Y(ATI_PVS_SRC_SEL_FORCE_0)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Z(ATI_PVS_SRC_SEL_FORCE_0)) | \
                                             (ATI_PVS_SRC_SWIZZLE_W(ATI_PVS_SRC_SEL_FORCE_1)))

#define ATI_PVS_SRC_FORCE_0101              ((ATI_PVS_SRC_SWIZZLE_X(ATI_PVS_SRC_SEL_FORCE_0)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Y(ATI_PVS_SRC_SEL_FORCE_1)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Z(ATI_PVS_SRC_SEL_FORCE_0)) | \
                                             (ATI_PVS_SRC_SWIZZLE_W(ATI_PVS_SRC_SEL_FORCE_1)))

#define ATI_PVS_SRC_FORCE_0011              ((ATI_PVS_SRC_SWIZZLE_X(ATI_PVS_SRC_SEL_FORCE_0)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Y(ATI_PVS_SRC_SEL_FORCE_0)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Z(ATI_PVS_SRC_SEL_FORCE_1)) | \
                                             (ATI_PVS_SRC_SWIZZLE_W(ATI_PVS_SRC_SEL_FORCE_1)))

#define ATI_PVS_SRC_FORCE_1011              ((ATI_PVS_SRC_SWIZZLE_X(ATI_PVS_SRC_SEL_FORCE_1)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Y(ATI_PVS_SRC_SEL_FORCE_0)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Z(ATI_PVS_SRC_SEL_FORCE_1)) | \
                                             (ATI_PVS_SRC_SWIZZLE_W(ATI_PVS_SRC_SEL_FORCE_1)))

#define ATI_PVS_SRC_FORCE_1101              ((ATI_PVS_SRC_SWIZZLE_X(ATI_PVS_SRC_SEL_FORCE_1)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Y(ATI_PVS_SRC_SEL_FORCE_1)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Z(ATI_PVS_SRC_SEL_FORCE_0)) | \
                                             (ATI_PVS_SRC_SWIZZLE_W(ATI_PVS_SRC_SEL_FORCE_1)))

#define ATI_PVS_SRC_FORCE_0111              ((ATI_PVS_SRC_SWIZZLE_X(ATI_PVS_SRC_SEL_FORCE_0)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Y(ATI_PVS_SRC_SEL_FORCE_1)) | \
                                             (ATI_PVS_SRC_SWIZZLE_Z(ATI_PVS_SRC_SEL_FORCE_1)) | \
                                             (ATI_PVS_SRC_SWIZZLE_W(ATI_PVS_SRC_SEL_FORCE_1)))


#define ATI_PVS_SRC_NEG_X                   (1 << 25)
#define ATI_PVS_SRC_NEG_Y                   (1 << 26)
#define ATI_PVS_SRC_NEG_Z                   (1 << 27)
#define ATI_PVS_SRC_NEG_W                   (1 << 28)
#define ATI_PVS_SRC_NEG_ALL                 (ATI_PVS_SRC_NEG_X | ATI_PVS_SRC_NEG_Y | \
                                             ATI_PVS_SRC_NEG_Z | ATI_PVS_SRC_NEG_W)

#define ATI_PVS_MAKE_SRC(dwRegType, dwRegOffset, dwSwizzle, dwNeg, dwAddrMode, dwSrcAddrSel)  \
          (((dwRegType)   << ATI_PVS_SRC_REG_TYPE_SHIFT)   |                    \
           ((dwRegOffset) << ATI_PVS_SRC_REG_OFFSET_SHIFT) |                    \
           (dwSwizzle)                                     |                    \
           (dwNeg)                                         |                    \
           (dwAddrMode)                                    |                    \
           (dwSrcAddrSel) << ATI_PVS_SRC_ADDR_SEL_SHIFT)

#define ATI_PVS_MAKE_SRC_FORCE_ZERO(dwSrcOp)                                    \
          (((dwSrcOp) &~ ATI_PVS_SRC_SEL_MASK) |                                \
           (ATI_PVS_SRC_FORCE_ZERO_ALL))

#define ATI_PVS_MAKE_SRC_FORCE_ONE(dwSrcOp)                                     \
          (((dwSrcOp) &~ ATI_PVS_SRC_SEL_MASK) |                                \
           (ATI_PVS_SRC_FORCE_ONE_ALL))


//
// dwFlags field of ATIPVSMGMT structure
//
#define ATI_PVSMGMT_FLAG_PVS  0x00000001  // Supports PVS

//
// defines for Chaplin PSC registers
//
#define ATI_PSC_DT_FLOAT_1         0x0
#define ATI_PSC_DT_FLOAT_2         0x1
#define ATI_PSC_DT_FLOAT_3         0x2
#define ATI_PSC_DT_FLOAT_4         0x3
#define ATI_PSC_DT_BYTE            0x4
#define ATI_PSC_DT_D3DCOLOR        0x5
#define ATI_PSC_DT_SHORT_2         0x6
#define ATI_PSC_DT_SHORT_4         0x7
#define ATI_PSC_DT_VECTOR_3_TTT    0x8
#define ATI_PSC_DT_VECTOR_3_EET    0x9

#define ATI_PSC_SKIP_DWORD_SHIFT   4
#define ATI_PSC_DST_VEC_SHIFT      8
#define ATI_PSC_LAST_VEC_SHIFT     13
#define ATI_PSC_SIGNED_SHIFT       14
#define ATI_PSC_NORMALIZE_SHIFT    15

// Some PSC defines
#define PSC_LAST_VEC              0x2000
#define PSC_SIGNED_BIT            0x4000
#define PSC_NORMALIZE_BIT         0x8000

// Programmable Shader Output Components
#define ATI_PVS_OUT_POS           0x00000001
#define ATI_PVS_OUT_DISCRETE_FOG  0x00000002
#define ATI_PVS_OUT_POINT_SIZE    0x00000004
// Place holder only              0x00000008
#define ATI_PVS_OUT_COLOR_0       0x00000010
#define ATI_PVS_OUT_COLOR_1       0x00000020
#define ATI_PVS_OUT_COLOR_2       0x00000040 // Presently unused by DirectX
#define ATI_PVS_OUT_COLOR_3       0x00000080 // Presently unused by DirectX
#define ATI_PVS_OUT_COLOR_4       0x00000100 // Presently unused by DirectX
#define ATI_PVS_OUT_COLOR_5       0x00000200 // Presently unused by DirectX
#define ATI_PVS_OUT_COLOR_6       0x00000400 // Presently unused by DirectX
#define ATI_PVS_OUT_COLOR_7       0x00000800 // Presently unused by DirectX
#define ATI_PVS_OUT_TEX_COORD_0   0x00001000
#define ATI_PVS_OUT_TEX_COORD_1   0x00002000
#define ATI_PVS_OUT_TEX_COORD_2   0x00004000
#define ATI_PVS_OUT_TEX_COORD_3   0x00008000
#define ATI_PVS_OUT_TEX_COORD_4   0x00010000
#define ATI_PVS_OUT_TEX_COORD_5   0x00020000
#define ATI_PVS_OUT_TEX_COORD_6   0x00040000 // Not supported on Chaplin
#define ATI_PVS_OUT_TEX_COORD_7   0x00080000 // Not supported on Chaplin


// Some PVS optimization defines

#define IsSingleComponent(dwValue) ((dwValue & (dwValue-1)) == 0)

// PVS registry flags
#define ATI_PVS_OPT_ENABLE_ALL           0x00000001  // Enables all optimizations
#define ATI_PVS_OPT_ENABLE_MOV           0x00000002  // Enables only the MOV optimization
#define ATI_PVS_OPT_ENABLE_ADDRESS       0x00000004  // Enables only the address optimization
#define ATI_PVS_OPT_ENABLE_DEPEND_GRAPH  0x00000008  // Enables only the dependency graph analysis
#define ATI_PVS_OPT_ENABLE_KILL_NEGATION 0x00000010  // Enables only the elimination of negation instructions
#define ATI_PVS_OPT_ENABLE_COMB_NEGATION 0x00000020  // Enables only the combining of negation instructions

// PVS code optimization flags
#define ATI_PVS_OPT_CAN_KILL_MOV    0x00000001   // Set if the MOV instruction into this output register
                                                 // can be eliminated
#define ATI_PVS_OPT_ADDRESS         0x00000002   // Set if the address register is to be optimized.
#define ATI_PVS_OPT_COMB_NEG        0x00000004   // Set if the moves can be combnined
#define ATI_PVS_OPT_KILL_NEG        0x00000008   // Set if the instruction is negating itself

#define ATI_PVS_OPT_MAD_TEMP_REG    0x00008000   // used to break up MAD instructions(not an optimization)

#define ATI_PVS_OPT_INPUT_SRC_MASK  0xf0000000   // Mask for the input register.

// Store relavant data for optimizing an instruction
#define ATI_PVS_OPT_DATA0_SHIFT     16
#define ATI_PVS_OPT_DATA0_MASK      0x000F0000
#define ATI_PVS_OPT_DATA1_SHIFT     20
#define ATI_PVS_OPT_DATA1_MASK      0x00F00000
#define ATI_PVS_OPT_DATA2_SHIFT     24
#define ATI_PVS_OPT_DATA2_MASK      0x0F000000
#define ATI_PVS_OPT_DATA3_SHIFT     28
#define ATI_PVS_OPT_DATA3_MASK      0xF0000000

// Readable #defines for each optimization
//mov
#define ATI_PVS_OPT_MOV_SRC_SHIFT          ATI_PVS_OPT_DATA0_SHIFT
#define ATI_PVS_OPT_MOV_SRC_MASK           ATI_PVS_OPT_DATA0_MASK

//address
#define ATI_PVS_OPT_ADDR_WRITEMASK_SHIFT   ATI_PVS_OPT_DATA0_SHIFT
#define ATI_PVS_OPT_ADDR_WRITEMASK_MASK    ATI_PVS_OPT_DATA0_MASK
#define ATI_PVS_OPT_ADDR_KEEP_INST_SHIFT   ATI_PVS_OPT_DATA1_SHIFT
#define ATI_PVS_OPT_ADDR_KEEP_INST_MASK    ATI_PVS_OPT_DATA1_MASK

//comb neg
#define ATI_PVS_OPT_COMB_NEG_WE_SHIFT      ATI_PVS_OPT_DATA0_SHIFT
#define ATI_PVS_OPT_COMB_NEG_WE_MASK       ATI_PVS_OPT_DATA0_MASK
#define ATI_PVS_OPT_COMB_NEG_MOD_SHIFT     ATI_PVS_OPT_DATA1_SHIFT
#define ATI_PVS_OPT_COMB_NEG_MOD_MASK      ATI_PVS_OPT_DATA1_MASK
#define ATI_PVS_OPT_COMB_NEG_SWIZ_SHIFT    ATI_PVS_OPT_DATA2_SHIFT  // this takes up slots 2 & 3
#define ATI_PVS_OPT_COMB_NEG_SWIZ_MASK    (ATI_PVS_OPT_DATA2_MASK | \
                                           ATI_PVS_OPT_DATA3_MASK)

//kill neg
#define ATI_PVS_OPT_KILL_NEG_MOD_SHIFT     ATI_PVS_OPT_DATA0_SHIFT
#define ATI_PVS_OPT_KILL_NEG_MOD_MASK      ATI_PVS_OPT_DATA0_MASK
#define ATI_PVS_OPT_KILL_NEG_REG_SHIFT     ATI_PVS_OPT_DATA1_SHIFT
#define ATI_PVS_OPT_KILL_NEG_REG_MASK      ATI_PVS_OPT_DATA1_MASK
#define ATI_PVS_OPT_KILL_NEG_KILL_SHIFT    ATI_PVS_OPT_DATA2_SHIFT
#define ATI_PVS_OPT_KILL_NEG_KILL_MASK     ATI_PVS_OPT_DATA2_MASK

//mad
#define ATI_PVS_OPT_MAD_TEMP_REG_SHIFT     ATI_PVS_OPT_DATA0_SHIFT
#define ATI_PVS_OPT_MAD_TEMP_REG_MASK      ATI_PVS_OPT_DATA0_MASK


// PVS Debug registry flags contained in dwPvsDebug
#define ATI_PVS_DEBUG_HIGHLIGHT            0x00000001 // Highlight shaders
#define ATI_PVS_DEBUG_OPT_STRONG_CHECK     0x00000002 // Force strong checking for the optimization
                                                      // controlled by ATI_PVS_OPT_ENABLE_DEPEND_GRAPH
#define ATI_PVS_DEBUG_USE_FLT2FIX_RND      0x00000004 // Use ATI_PVS_OP_VE_FLT2FIX_RND instead of
                                                      // ATI_PVS_OP_VE_FLT2FIX_FLR to write to ADDR registers
#define ATI_PVS_DEBUG_SET_DEFAULTS         0x00000008 // Force in default values for output registers
#define ATI_PVS_DEBUG_DONT_FIX_EXPP        0x00000010 
#define ATI_PVS_DEBUG_PRE_OPT_HEX_DUMP     0x00000020 // Interleave Hex dump with normal E_SHADER_DUMP


///////////////////////////////////////////////////////////////////////////////
// Function Prototypes
///////////////////////////////////////////////////////////////////////////////
extern VOID VS_HwInit(LPATID3DCNTX pCtxt);
extern LPDWORD VS_HwUpdatePSCShader(LPATID3DCNTX pCtxt, LPDWORD pdwOut);
extern LPDWORD VS_HwUpdateNonPSCShader(LPATID3DCNTX pCtxt, LPDWORD pdwOut);
extern VOID VS_HwAssemble(LPATID3DCNTX pCtxt, LPATIVTXSHADER pVtxShader);

extern VOID VS_HwOptimizeReorderPass(LPATIVTXSHADER pVtxShader);

HRESULT VS_HwParseDeclBodyNonPSC(LPATID3DCNTX pCtxt, 
                                 LPATIVTXSHADER  pAtiVertexShader, 
                                 LPVOID lpDeclBody, DWORD dwDeclSizeDW,
                                 LPDWORD pdwFVFType,
                                 DWORD dwShaderFlags);

HRESULT VS_HwParseDeclBodyPSC(LPATID3DCNTX pCtxt, 
                              LPATIVTXSHADER  pAtiVertexShader, 
                              LPVOID lpDeclBody, DWORD dwDeclSizeDW,
                              LPDWORD pdwFVFType,
                              DWORD dwShaderFlags);

#if (DIRECT3D_VERSION >= 0x0900)
HRESULT VS_HwVtxDeclPSCInit(LPATID3DCNTX pCtxt, 
                             LPATIVSDECL  pAtiVSDecl, 
                             LPD3DVERTEXELEMENT9 pDecl,
                             DWORD dwNumElements);
HRESULT VS_HwVtxDeclNonPSCInit(LPATID3DCNTX pCtxt, 
                             LPATIVSDECL  pAtiVSDecl, 
                             LPD3DVERTEXELEMENT9 pDecl,
                             DWORD dwNumElements);

HRESULT VS_HwVtxDeclPSCforNonFunc(LPATID3DCNTX pCtxt, 
                             LPATIVSDECL  pAtiVSDecl, 
                             LPD3DVERTEXELEMENT9 pDecl,
                             DWORD dwNumElements);
HRESULT VS_HwVtxDeclPSCforFunc(LPATID3DCNTX pCtxt, 
                             LPATIVSFUNC  pAtiVSDecl, 
                             LPD3DVERTEXELEMENT9 pDecl,
                             DWORD dwNumElements);

HRESULT AtiMakeVtxElementArrayFromFVF(LPD3DVERTEXELEMENT9 pAtiVtxElement, 
                                      LPDWORD pNumElement,DWORD dwFVF);


#endif // (DIRECT3D_VERSION >= 0x0900)

extern WORD VS_HwSetPSCReg(DWORD dwDataType, DWORD dwSkip, DWORD dwDestVec, BOOL bPVS);
extern VOID VS_DumpDxVertexShader(LPDWORD pdwToken);
extern DWORD CreateFakeFvfForPsc(LPATIVTXSHADER pVS, DWORD dwSize);
/******************************************************************************
* VOID VS_HwSetPvsCntl()
*
* Args:
*   pCtxt          pointer to current context
*   dwFirstInst    first instruction vector to execute for this shader
*   dwPosValidInst instruction where vertex position is valid
*   dwLastInst     last instruction to execute for this shader
*  
* Returns: N/A
*
* Description:
*   This routine sets up the SE_PVS_CNTL register
*
* Notes:
*   This routine does not write the register to the command buffer
*   
******************************************************************************/
__inline VOID VS_HwSetPvsCntl(struct _ATID3DCNTX *pCtxt, DWORD dwFirstInst,
                              DWORD dwPosValidInst, DWORD dwLastInst)
{
  set_SE_PVS_CNTL_pvs_first_inst(&pCtxt->SePvsCntl_reg, dwFirstInst);
  set_SE_PVS_CNTL_pvs_xyzw_valid_inst(&pCtxt->SePvsCntl_reg, dwPosValidInst);
  set_SE_PVS_CNTL_pvs_last_inst(&pCtxt->SePvsCntl_reg, dwLastInst);
}

/******************************************************************************
* VOID VS_HwSetPvsConstCntl()
*
* Args:
*   pCtxt          pointer to current context
*   dwConstBase    Constant store vector that is the base constant vector
*   dwMaxConstAddr Maximum constant vector address that this shader uses
*  
* Returns: N/A
*
* Description:
*   This routine sets up the SE_PVS_CONST_CNTL register
*
* Notes:
*   This routine does not write the register to the command buffer
*   
******************************************************************************/
__inline VOID VS_HwSetPvsConstCntl(LPATID3DCNTX pCtxt, 
                                   DWORD dwConstBase, DWORD dwMaxConstAddr)
{
  set_SE_PVS_CONST_CNTL_pvs_const_base_offset(&pCtxt->SePvsConstCntl_reg, dwConstBase);
  set_SE_PVS_CONST_CNTL_pvs_max_const_addr(&pCtxt->SePvsConstCntl_reg, dwMaxConstAddr);
}


/******************************************************************************
* VOID VS_HwWriteOutVtxFmt()
*
* Args:
*   pdwOut           pointer location in command buffer to write the command(s)
*   pCtxt            pointer to current context
*   dwOutVtxEncoding encoding of output vertex format
*  
* Returns: updated pointer location for next command buffer write
*
* Description:
*   This routine sets up the output vertex format(s) and selects for
*   a programmable vertex shader
*
* Notes:
*   
******************************************************************************/
__inline LPDWORD VS_HwWriteOutVtxFmt(LPDWORD pdwOut, LPATID3DCNTX pCtxt, DWORD dwOutVtxEncoding, 
                                     LPATIPVSOPTIMIZATION pPvsOptData)
{
    regSE_TCL_OUTPUT_VTX_FMT_0    regSeTclOutVtxFmt0;
    regSE_TCL_OUTPUT_VTX_FMT_1    regSeTclOutVtxFmt1;
    regSE_TCL_OUTPUT_VTX_COMP_SEL regSeTclOutVtxCompSel;
    regSE_TCL_LIGHT_MODEL_CNTL_0  regSeTclLightModelCntl0;
    regSE_TCL_UCP_VTX_BLEND_CNTL  regSeTclUcpVtxBlendCntl;
    LPD3DDEVICE                   lpD3DDev                = (LPD3DDEVICE)GetD3DDevice(pCtxt);
    LPDWORD                       pdwUpdatedOut           = pdwOut;
    
    regSeTclOutVtxFmt0.u32All      = 0;
    regSeTclOutVtxFmt1.u32All      = 0;
    regSeTclOutVtxCompSel.u32All   = 0;
    regSeTclLightModelCntl0.u32All = 0;
    regSeTclUcpVtxBlendCntl.u32All = 0;

    if (dwOutVtxEncoding & ATI_PVS_OUT_POS)
    {
        set_SE_TCL_OUTPUT_VTX_FMT_0_vtx_z0_present(&regSeTclOutVtxFmt0, 1);
        set_SE_TCL_OUTPUT_VTX_FMT_0_vtx_w0_present(&regSeTclOutVtxFmt0, 1);
        set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_xyzw_sel(&regSeTclOutVtxCompSel, 1);
    }
    else
    {
        HSLDPF(E_ERROR_MESSAGE, "VS_HwWriteOutVtxFmt: Error: No position on output!");
    }

    if (dwOutVtxEncoding & ATI_PVS_OUT_DISCRETE_FOG)
    {
        if (pCtxt->pD3DDevice->AtiD3dRegistry.bDiscreteFogEnable == TRUE)
        {
            set_SE_TCL_OUTPUT_VTX_FMT_0_vtx_discrete_fog_present(&regSeTclOutVtxFmt0, 1);
            set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_discrete_fog_sel(&regSeTclOutVtxCompSel, 1);

            dwOutVtxEncoding |= ATI_PVS_OUT_COLOR_1;

            // If the PVS outputs to discrete fog, we must set fog to use 'vertex fog' as the 
            // fog coeffecient
            set_PP_FOG_COLOR_fog_index_sel_r2(&(pCtxt->PpFogColor_reg), 4); // fog select vertex fog
        }
        else
        {
            set_PP_CNTL_fog_enable(&pCtxt->PpCntl_reg, 0);  // disable fog
            pdwUpdatedOut = SetOneRegPM4(pdwUpdatedOut, 
                                         mmPP_CNTL, pCtxt->PpCntl_reg.u32All);
        }
    }
    else
    {
        // Only change fog state if table fog is disabled.
        if (pCtxt->ATIStateList[ D3DRS_FOGTABLEMODE ] == D3DFOG_NONE)
        {
            set_PP_FOG_COLOR_fog_index_sel_r2(&(pCtxt->PpFogColor_reg), 3); // fog select specular alpha

            dwOutVtxEncoding |= ATI_PVS_OUT_COLOR_1;
        }
    }

    if ((dwOutVtxEncoding & ATI_PVS_OUT_POINT_SIZE) ||
        (pCtxt->fPointSize != 1.0f && pCtxt->ATIStateList[D3DRS_FILLMODE]==D3DFILL_POINT) ||
        (pCtxt->ATIStateList[D3DRS_POINTSPRITEENABLE]))
    {
        set_SE_TCL_OUTPUT_VTX_FMT_0_vtx_pt_size_present(&regSeTclOutVtxFmt0, 1);
        set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_pt_size_sel(&regSeTclOutVtxCompSel, 1);
    }

    // Colors
    if (dwOutVtxEncoding & ATI_PVS_OUT_COLOR_0)
    {
        set_SE_TCL_OUTPUT_VTX_FMT_0_vtx_color_0_fmt(&regSeTclOutVtxFmt0, 3);
        set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_color_0_sel(&regSeTclOutVtxCompSel, 1);
    }
    if (dwOutVtxEncoding & ATI_PVS_OUT_COLOR_1)
    {
        set_SE_TCL_OUTPUT_VTX_FMT_0_vtx_color_1_fmt(&regSeTclOutVtxFmt0, 3);
        set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_color_1_sel(&regSeTclOutVtxCompSel, 1);
    }

    // Texture coordinates
    if (dwOutVtxEncoding & ATI_PVS_OUT_TEX_COORD_0 || 
        pCtxt->dwPointSpriteFlags & ATI_TCL_PTSPR_ENABLED)
    {
        set_SE_TCL_OUTPUT_VTX_FMT_1_tex_0_comp_cnt(&regSeTclOutVtxFmt1, 4);
        set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_tex_0_sel(&regSeTclOutVtxCompSel, 1);
    }
    if (dwOutVtxEncoding & ATI_PVS_OUT_TEX_COORD_1)
    {
        set_SE_TCL_OUTPUT_VTX_FMT_1_tex_1_comp_cnt(&regSeTclOutVtxFmt1, 4);
        set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_tex_1_sel(&regSeTclOutVtxCompSel, 1);
    }
    if (dwOutVtxEncoding & ATI_PVS_OUT_TEX_COORD_2)
    {
        set_SE_TCL_OUTPUT_VTX_FMT_1_tex_2_comp_cnt(&regSeTclOutVtxFmt1, 4);
        set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_tex_2_sel(&regSeTclOutVtxCompSel, 1);
    }
    if (dwOutVtxEncoding & ATI_PVS_OUT_TEX_COORD_3)
    {
        set_SE_TCL_OUTPUT_VTX_FMT_1_tex_3_comp_cnt(&regSeTclOutVtxFmt1, 4);
        set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_tex_3_sel(&regSeTclOutVtxCompSel, 1);
    }
    if (dwOutVtxEncoding & ATI_PVS_OUT_TEX_COORD_4)
    {
        set_SE_TCL_OUTPUT_VTX_FMT_1_tex_4_comp_cnt(&regSeTclOutVtxFmt1, 4);
        set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_tex_4_sel(&regSeTclOutVtxCompSel, 1);
    }
    if (dwOutVtxEncoding & ATI_PVS_OUT_TEX_COORD_5)
    {
        set_SE_TCL_OUTPUT_VTX_FMT_1_tex_5_comp_cnt(&regSeTclOutVtxFmt1, 4);
        set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_tex_5_sel(&regSeTclOutVtxCompSel, 1);
    }

    // Modify the regs based on any optimizations we have made
    regSeTclOutVtxCompSel.u32All &= pPvsOptData->pvsRegSeTclOutVtxCompSel.u32All;

    VTEBackpressureHangAround(pCtxt, &regSeTclOutVtxFmt0, &regSeTclOutVtxFmt1);

    // Update the D3D Context since this data member is used at the top of
    // WriteRendStateToHW and there is no guarantee that the vertex shader
    // will be dirty evertime SE_TCL_OUTPUT is written.
    pCtxt->tclR2OutputVtxControlCmd.OutVtxFmt0    = regSeTclOutVtxFmt0;
    pCtxt->tclR2OutputVtxControlCmd.OutVtxFmt1    = regSeTclOutVtxFmt1;
    pCtxt->tclR2OutputVtxControlCmd.OutVtxCompSel = regSeTclOutVtxCompSel;
    
    pdwUpdatedOut = SetOneRegPM4(pdwUpdatedOut, 
                                 mmSE_TCL_OUTPUT_VTX_FMT_0, regSeTclOutVtxFmt0.u32All);
    pdwUpdatedOut = SetOneRegPM4(pdwUpdatedOut, 
                                 mmSE_TCL_OUTPUT_VTX_FMT_1, regSeTclOutVtxFmt1.u32All);
    pdwUpdatedOut = SetOneRegPM4(pdwUpdatedOut,
                                 mmSE_TCL_OUTPUT_VTX_COMP_SEL, regSeTclOutVtxCompSel.u32All);
    pdwUpdatedOut = SetOneRegPM4(pdwUpdatedOut,
                                 mmPP_FOG_COLOR, pCtxt->PpFogColor_reg.u32All);
  
    if (lpD3DDev->AtiD3dRegistry.dwClipOptimizations > 1)
    {
        regSeTclLightModelCntl0.bitfields.WAIT_ON_CLIP_DIS = 1;
        regSeTclLightModelCntl0.bitfields.CLIP_DBL_BUF_ENA = 1;
        pdwUpdatedOut = SetOneRegPM4(pdwUpdatedOut,
                                     mmSE_TCL_LIGHT_MODEL_CNTL_0, regSeTclLightModelCntl0.u32All);
    }
    else if (pCtxt->dwTclFlags & ATI_TCLFLAG_TCLCULLING_ENABLED)
    {
        // Process TCL culling state
        pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl.u32All |= pCtxt->dwTclCullFlags;

        pdwUpdatedOut = SetOneRegPM4(pdwUpdatedOut,
                                     mmSE_TCL_UCP_VTX_BLEND_CNTL, regSeTclUcpVtxBlendCntl.u32All);
    }
  
    return pdwUpdatedOut;
}

/******************************************************************************
* VOID VS_HwWriteVecIndRegs()
*
* Args:
*   pdwOut           pointer location in command buffer to write the command(s)
*   pCtxt            pointer to current context
*   dwOutVtxEncoding encoding of output vertex format
*  
* Returns: updated pointer location for next command buffer write
*
* Description:
*   This routine sets up the output vertex format(s) and selects for
*   a programmable vertex shader
*
* Notes:
*   
******************************************************************************/
__inline LPDWORD VS_HwWriteVecIndRegs(LPDWORD pdwOut, LPATID3DCNTX pCtxt)
{
    BOOL bUseHWPVS = FALSE;

    if (pCtxt->eVtxProcMode == E_VTXPROCMODE_HW_PVS)
    {
        LPATIVTXSHADER pAtiVtxShader = VS_GetShader(pCtxt);

        if (pAtiVtxShader)
        {
#if (DIRECT3D_VERSION >= 0x0900)
            if (pAtiVtxShader->dwFlags & VS_PVS_SHADER)
#endif
            {
                bUseHWPVS = TRUE;
                pCtxt->tclR2InputVtxVectorAddrCmd = pAtiVtxShader->pvsOptimizeData.pvsInputVecAddr;
            }
        }
        else
        {
            return pdwOut;
        }
    }

    if (!bUseHWPVS)
    {
        // Reset the vector indirection regs to the defaults
        regSE_TCL_INPUT_VTX_VECTOR_ADDR_0 *pAddr0 = &pCtxt->tclR2InputVtxVectorAddrCmd.inputVtxVectorAddr0;
        regSE_TCL_INPUT_VTX_VECTOR_ADDR_1 *pAddr1 = &pCtxt->tclR2InputVtxVectorAddrCmd.inputVtxVectorAddr1;
        regSE_TCL_INPUT_VTX_VECTOR_ADDR_2 *pAddr2 = &pCtxt->tclR2InputVtxVectorAddrCmd.inputVtxVectorAddr2;
        regSE_TCL_INPUT_VTX_VECTOR_ADDR_3 *pAddr3 = &pCtxt->tclR2InputVtxVectorAddrCmd.inputVtxVectorAddr3;

        set_SE_TCL_INPUT_VTX_VECTOR_ADDR_1_vtx_color_0_addr(pAddr1, ATI_VEC_LOC_COLOR0);
        set_SE_TCL_INPUT_VTX_VECTOR_ADDR_1_vtx_color_1_addr(pAddr1, ATI_VEC_LOC_COLOR1);

        set_SE_TCL_INPUT_VTX_VECTOR_ADDR_2_vtx_tex_0_addr(pAddr2, ATI_VEC_LOC_TEXTURE0);
        set_SE_TCL_INPUT_VTX_VECTOR_ADDR_2_vtx_tex_1_addr(pAddr2, ATI_VEC_LOC_TEXTURE1);
        set_SE_TCL_INPUT_VTX_VECTOR_ADDR_2_vtx_tex_2_addr(pAddr2, ATI_VEC_LOC_TEXTURE2);
        set_SE_TCL_INPUT_VTX_VECTOR_ADDR_2_vtx_tex_3_addr(pAddr2, ATI_VEC_LOC_TEXTURE3);

        set_SE_TCL_INPUT_VTX_VECTOR_ADDR_3_vtx_tex_4_addr(pAddr3, ATI_VEC_LOC_TEXTURE4);
        set_SE_TCL_INPUT_VTX_VECTOR_ADDR_3_vtx_tex_5_addr(pAddr3, ATI_VEC_LOC_TEXTURE5);
    }

    pdwOut = SetOneRegPM4(pdwOut, 
        mmSE_TCL_INPUT_VTX_VECTOR_ADDR_0, pCtxt->tclR2InputVtxVectorAddrCmd.inputVtxVectorAddr0.u32All);
    pdwOut = SetOneRegPM4(pdwOut, 
        mmSE_TCL_INPUT_VTX_VECTOR_ADDR_1, pCtxt->tclR2InputVtxVectorAddrCmd.inputVtxVectorAddr1.u32All);
    pdwOut = SetOneRegPM4(pdwOut, 
        mmSE_TCL_INPUT_VTX_VECTOR_ADDR_2, pCtxt->tclR2InputVtxVectorAddrCmd.inputVtxVectorAddr2.u32All);
    pdwOut = SetOneRegPM4(pdwOut, 
        mmSE_TCL_INPUT_VTX_VECTOR_ADDR_3, pCtxt->tclR2InputVtxVectorAddrCmd.inputVtxVectorAddr3.u32All);

    return pdwOut;
}

/******************************************************************************
* __inline DWORD VS_GetComponentSizeFromATIDef()
*
* Args:
*   dwDataType
*  
* Returns: Component size in dwords of dwDataType
*
* Description:
*   This will get the component size from the ATI PSC definiton
*
* Notes:
*
******************************************************************************/
__inline DWORD VS_GetComponentSizeFromATIDef(DWORD dwDataType)
{
    switch(dwDataType)
    {
    case ATI_PSC_DT_FLOAT_1:  // 1D float expanded to (value, 0., 0., 1.)
        return 1;
    case ATI_PSC_DT_FLOAT_2:  // 2D float expanded to (value, value, 0., 1.)
        return 2;
    case ATI_PSC_DT_FLOAT_3:  // 3D float expanded to (value, value, value, 1.)
    default:
        return 3;
    case ATI_PSC_DT_FLOAT_4:  // 4D float
        return 4;
    case ATI_PSC_DT_D3DCOLOR: // 1D packed unsigned bytes mapped to 0. to 1. range
        return 1;
    case ATI_PSC_DT_BYTE:     // 1D unsigned byte
        return 1;
    case ATI_PSC_DT_SHORT_2: // 1D signed short expanded to (value, value, 0., 1.)
        return 1;
    case ATI_PSC_DT_SHORT_4: // 2D signed short expanded to (value, value, value, value)
        return 2;
    case ATI_PSC_DT_VECTOR_3_TTT:
    case ATI_PSC_DT_VECTOR_3_EET:
        HSLASSERT(dwDataType != D3DVSDT_SHORT2);
        HSLASSERT(dwDataType != D3DVSDT_SHORT4);
        HSLASSERT(dwDataType != ATI_PSC_DT_VECTOR_3_TTT);
        HSLASSERT(dwDataType != ATI_PSC_DT_VECTOR_3_EET);
        return 0;
    }
}

/******************************************************************************
* LPDWORD VS_HwWritePSCState()
*
* Args:
*   pdwOut         pointer location in command buffer to write the command
*   pCtxt          pointer to current context
*   pVtxShader     pointer to the vertex shader structure with PSC info
*  
* Returns: updated pointer location for next command buffer write
*
* Description:
*   This routine writes PSC state info into the command buffer
*
* Notes:
*   
******************************************************************************/
__inline LPDWORD VS_HwWritePSCState(LPDWORD pdwOut, LPATID3DCNTX pCtxt, 
                                    LPATIVTXSHADER pVtxShader, LPDWORD dwBlendWeightFirst)
{
    WORD  wTempPSCRegs[VS_NUM_PSC_ENTRIES] = {0};
    DWORD i, j = 0;

    *dwBlendWeightFirst = 0;

    // We need to eliminate blend weights if the app is using fixed-function tweening
    if ((pCtxt->dwTweeningFlags & ATI_TCL_TWEENING_ENABLED) &&
        (pCtxt->eVtxProcMode == E_VTXPROCMODE_HW_FF))
    {
        for (i = 0; i < VS_NUM_PSC_ENTRIES; i++)
        {
            if (((pVtxShader->wPSCRegs[i] & SE_PROG_STREAM_CNTL_0__DST_VEC_LOC_0_MASK)
                  >> SE_PROG_STREAM_CNTL_0__DST_VEC_LOC_0__SHIFT) == ATI_VEC_LOC_BLENDWEIGHT)
            {
                // blend weights in fixed-function mode must be 1-4 floats
                DWORD dwNumBlendWeights = (pVtxShader->wPSCRegs[i] & 
                                                SE_PROG_STREAM_CNTL_0__DATA_TYPE_0_MASK) + 1;
                if (i == 0)
                {
                    *dwBlendWeightFirst = dwNumBlendWeights;
                }
                else
                {
                    // Add the number of blend weights to the number of dwords to skip of the previous element
                    DWORD dwNumToSkip = (((wTempPSCRegs[i-1] & SE_PROG_STREAM_CNTL_0__SKIP_DWORDS_0_MASK) 
                                            >> SE_PROG_STREAM_CNTL_0__SKIP_DWORDS_0__SHIFT) + dwNumBlendWeights);
                    wTempPSCRegs[i-1] &= ~SE_PROG_STREAM_CNTL_0__SKIP_DWORDS_0_MASK;
                    wTempPSCRegs[i-1] |= dwNumToSkip << SE_PROG_STREAM_CNTL_0__SKIP_DWORDS_0__SHIFT;
                }
            }
            else
            {
                wTempPSCRegs[j++] = pVtxShader->wPSCRegs[i];
            }
            if (pVtxShader->wPSCRegs[i] & SE_PROG_STREAM_CNTL_0__LAST_VEC_0_MASK)
            {
                break;
            }
        }

        // Write the programmable stream control registers to the HW
        return SetRegSeqPM4(pdwOut, mmSE_PROG_STREAM_CNTL_0, 
                            (LPDWORD)wTempPSCRegs, 
                            sizeof(wTempPSCRegs) >> 2);
    }
    else
    {
        if ((pVtxShader->wPSCRegs[0] & SE_PROG_STREAM_CNTL_0__LAST_VEC_0_MASK) &&
            (pCtxt->eVtxProcMode == E_VTXPROCMODE_HW_PVS))
        {
            DWORD   dwSize;
            pVtxShader->wPSCRegs[1] = pVtxShader->wPSCRegs[0];

            pVtxShader->wPSCRegs[0] &= ~SE_PROG_STREAM_CNTL_0__LAST_VEC_0_MASK;
#if (DIRECT3D_VERSION >= 0x0900)
            if (pVtxShader->dwNumArrays==1)
#endif//DIRECT3D_VERSION >= 0x0900
            {
               HSLASSERT(pVtxShader->dwNumArrays == 1);
               pVtxShader->dwNumArrays++;
               pVtxShader->pdwStreamIndex[1] = pVtxShader->pdwStreamIndex[0];
               pVtxShader->pdwOffset[1] = pVtxShader->pdwOffset[0];
               pVtxShader->pdwCount[1] = pVtxShader->pdwCount[0]; 
            }     

            dwSize =
                2 * VS_GetComponentSizeFromATIDef(pVtxShader->wPSCRegs[0] & SE_PROG_STREAM_CNTL_0__DATA_TYPE_0_MASK);

            CreateFakeFvfForPsc(pVtxShader, dwSize);
        }

        return SetRegSeqPM4(pdwOut, mmSE_PROG_STREAM_CNTL_0, 
                            (LPDWORD)&pVtxShader->wPSCRegs, 
                            sizeof(pVtxShader->wPSCRegs) >> 2);
    }
}


/******************************************************************************
* LPDWORD VS_HwWriteTclFlush()
*
* Args:
*   pdwOut         pointer location in command buffer to write the flush command
*   pCtxt          pointer to current context
*  
* Returns: updated pointer location for next command buffer write
*
* Description:
*   This routine writes an SE_TCL_STATE_FLUSH_REG to the command buffer
*
* Notes:
*   
******************************************************************************/
__inline LPDWORD VS_HwWriteTclFlush(LPDWORD pdwOut, LPATID3DCNTX pCtxt)
{
    return SetOneRegPM4(pdwOut, mmSE_TCL_STATE_FLUSH_REG, 0);
}




/******************************************************************************
* __inline DWORD VS_GetTexFvf()
*
* Args:
*   dwIndex          Slot the texture is being placed in
*   dwComponentSize  Number of components for this texture
*  
* Returns: Proper FVF code
*
* Description:
*   Returns the D3D FVF code for this texture/# of components combo
*
* Notes:
*   
******************************************************************************/
__inline DWORD VS_HwGetTexFvf(DWORD dwFVF, DWORD dwIndex, DWORD dwComponentSize)
{
    // Get the texture slot
    DWORD dwNewFVF;
    if (((dwFVF & D3DFVF_TEXCOUNT_MASK) >> D3DFVF_TEXCOUNT_SHIFT) < (dwIndex+1))
    {
        dwNewFVF = ((dwIndex+1) << D3DFVF_TEXCOUNT_SHIFT);
    }
    else
    {
        dwNewFVF = (dwFVF & D3DFVF_TEXCOUNT_MASK);
    }

    // Set the number of texture components for this slot
    // NOTE: MS definition for this is...
    // D3DFVF_TEXTUREFORMAT1 3         // One floating point value
    // D3DFVF_TEXTUREFORMAT2 0         // Two floating point values
    // D3DFVF_TEXTUREFORMAT3 1         // Three floating point values
    // D3DFVF_TEXTUREFORMAT4 2         // Four floating point values
    // So if we subtract 2 from the number of components (unsigned numbers), 
    // we get the correct format.
    // Then plug it into this MS formula...
    // D3DFVF_TEXCOORDSIZEx(dwIndex) = (D3DFVF_TEXTUREFORMATx << (dwIndex*2 + 16))
    // ...and we get the MS FVF value 
    return ( dwNewFVF |= (((dwComponentSize - 2) & 0x00000003) << ((dwIndex*2) + 16)) );
}

/******************************************************************************
* __inline VOID VS_HwAddSkipToPSCReg()
*
* Args:
*   dwSkip    Number of DWORDS to skip
*  
* Returns: nothing
*
* Description:
*   Adds the number of dwords to skip to the PSC register 
*
* Notes:
*   
******************************************************************************/
__inline VOID VS_HwAddSkipToPSCReg(LPWORD pwPSCReg, DWORD dwSkip)
{
    HSLASSERT(dwSkip < VS_NUM_PSC_ENTRIES);
    *pwPSCReg |= (dwSkip << ATI_PSC_SKIP_DWORD_SHIFT);
}

/******************************************************************************
* __inline DWORD VS_HwEndOfSegment()
*
* Args:
*    dwCurrentOffset   Offset of the code or state memory
*  
* Returns: Size left in the current memory segment
*
* Description:
*   Returns (offset - end of current segment)
*
* Notes:
*   This routine assumes that the offset is in the range:
*       for code:  [128,191] | [384,447]   
*       for state: [0,95]    | [256,351]   
*
******************************************************************************/
__inline DWORD VS_HwEndOfSegment(DWORD dwCurrentOffset)
{
    if (dwCurrentOffset > (ATI_R200_PVS_CODE_START_HIGH+ATI_R200_PVS_CODE_SIZE_SEG))
    {
        HSLDPF(E_ERROR_MESSAGE, "VS_HwEndOfSegment: Invalid offset: %08x", dwCurrentOffset);
        return 0;
    }
    if (dwCurrentOffset < (ATI_R200_PVS_STATE_START_LOW+ATI_R200_PVS_STATE_SIZE_SEG))
    {
        return ((ATI_R200_PVS_STATE_START_LOW+ATI_R200_PVS_STATE_SIZE_SEG)-dwCurrentOffset);
    }
    else if (dwCurrentOffset < (ATI_R200_PVS_CODE_START_LOW+ATI_R200_PVS_CODE_SIZE_SEG))
    {
        return ((ATI_R200_PVS_CODE_START_LOW+ATI_R200_PVS_CODE_SIZE_SEG)-dwCurrentOffset);
    }
    else if (dwCurrentOffset < (ATI_R200_PVS_STATE_START_HIGH+ATI_R200_PVS_STATE_SIZE_SEG))
    {
        return ((ATI_R200_PVS_STATE_START_HIGH+ATI_R200_PVS_STATE_SIZE_SEG)-dwCurrentOffset);
    }
    else
    {
        return ((ATI_R200_PVS_CODE_START_HIGH+ATI_R200_PVS_CODE_SIZE_SEG)-dwCurrentOffset);
    }
}

/******************************************************************************
* __inline DWORD VS_HwNextSegStart()
*
* Args:
*    dwBase            The current offset
*    dwOffset          Linear offset for the next code or state memory seg
*    dwDataType        State or Code
*
* Returns: offset of the next segment
*
* Description:
*   See VS_HwUpdatePVS for the reason why this is necessary
*
* Notes:
*   
******************************************************************************/
__inline DWORD VS_HwGetNextOffset(LPDWORD pdwBase, DWORD dwOffset, DWORD dwDataType)
{
    DWORD dwReturnVal;
    if (dwDataType & ATI_PVS_CODE_SEG)
    {
        if ((*pdwBase+dwOffset) >= (2*ATI_R200_PVS_CODE_SIZE_SEG))
        {
            *pdwBase = 0;
            dwReturnVal = ATI_R200_PVS_CODE_START_LOW;
        }
        else if ((*pdwBase+dwOffset) >= ATI_R200_PVS_CODE_SIZE_SEG)
        {
            dwReturnVal = (ATI_R200_PVS_CODE_START_HIGH + ((*pdwBase+dwOffset)-ATI_R200_PVS_CODE_SIZE_SEG));
            *pdwBase = (*pdwBase+dwOffset);
        }
        else
        {
            dwReturnVal = (ATI_R200_PVS_CODE_START_LOW + (*pdwBase+dwOffset));
            *pdwBase = (*pdwBase+dwOffset);
        }
    }
    else
    {
        if ((*pdwBase+dwOffset) >= (2*ATI_R200_PVS_STATE_SIZE_SEG))
        {
            *pdwBase = 0;
            dwReturnVal =  ATI_R200_PVS_STATE_START_LOW;
        }
        else if ((*pdwBase+dwOffset) >= ATI_R200_PVS_STATE_SIZE_SEG) 
        {
            dwReturnVal = (ATI_R200_PVS_STATE_START_HIGH + ((*pdwBase+dwOffset)-ATI_R200_PVS_STATE_SIZE_SEG));
            *pdwBase = (*pdwBase+dwOffset);
        }
        else
        {
            dwReturnVal = (ATI_R200_PVS_STATE_START_LOW + (*pdwBase+dwOffset));
            *pdwBase = (*pdwBase+dwOffset);
        }
    }
    return dwReturnVal;
}

/******************************************************************************
* __inline DWORD VS_HwGetOptimizationTableIndex()
*
* Args:
*   dwDxDstRegType    D3D register type
*   dwDxDstRegOffset  D3D register offset
*  
* Returns: an index
*
* Description:
*   Returns the index into our PVS optimization table 
*
* Notes:
*       The table is filled in as follows:
*       ------------
*       |   oPos   |----> D3DSPR_RASTOUT + offset 0
*       ------------
*       |   oD0    |----> D3DSPR_ATTROUT + offset 0
*       ------------
*       |   oD1    |
*       ------------
*       |   oT0    |----> D3DSPR_TEXCRDOUT + offset 0
*       ------------
*       |   oT1    |
*       ------------
*       |   oT2    |
*       ------------
*       |   oT3    |
*       ------------
*       |   oT4    |
*       ------------
*       |   oT5    |
*       ------------       
*   
******************************************************************************/
__inline DWORD VS_HwGetOptimizationTableIndex(DWORD dwDxDstRegType, DWORD dwDxDstRegOffset)
{
    DWORD dwIndex = 0;
    switch(dwDxDstRegType)
    {
    case D3DSPR_RASTOUT:
      {
        if (dwDxDstRegOffset > 0)
          dwIndex = ATI_PVS_OPT_LIMIT;
        else
          dwIndex = 0;
        break;
      }
    case D3DSPR_ATTROUT:
        dwIndex = 1;
        break;
    case D3DSPR_TEXCRDOUT:
        dwIndex = 3;
        break;
    default:
        dwIndex = ATI_PVS_OPT_LIMIT;
        break;
    }
    return (dwIndex + dwDxDstRegOffset);
}

/******************************************************************************
* __inline VOID VS_HwSetTclOutputCompReg()
*
* Args:
*   dwDxDstRegType    D3D register type
*   dwDxDstRegOffset  D3D register offset
*   dwDxSrcRegOffset  D3D input vector offset
*  
* Returns: nada
*
* Description:
*   Sets up the tcl regs to eliminate the mov instruction.  They are written 
*   in VS_HwUpdatePVS
*
* Notes:
*   This routine assumes that we will only eliminate MOV instructions where the 
*   source is an input vector.  Since it is an input vector, we only need to 
*   know which one (i.e. the source offset)
*   
******************************************************************************/
__inline VOID VS_HwSetTclOutputCompReg(DWORD dwDxDstRegType, DWORD dwDxDstRegOffset, 
                              DWORD dwDxSrcRegOffset, LPATIPVSOPTIMIZATION pPvsOptData)
{
    switch(dwDxDstRegType)
    {
    case D3DSPR_RASTOUT:
        set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_xyzw_sel(&pPvsOptData->pvsRegSeTclOutVtxCompSel, 0);
        set_SE_TCL_INPUT_VTX_VECTOR_ADDR_0_vertex_position_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr0, 
                                                                dwDxSrcRegOffset);
        break;
    case D3DSPR_ATTROUT:
        switch(dwDxDstRegOffset)
        {
        case 0:
            set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_color_0_sel(&pPvsOptData->pvsRegSeTclOutVtxCompSel, 0);
            set_SE_TCL_INPUT_VTX_VECTOR_ADDR_1_vtx_color_0_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr1, 
                                                                    dwDxSrcRegOffset);
            break;
        case 1:
            set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_color_1_sel(&pPvsOptData->pvsRegSeTclOutVtxCompSel, 0);
            set_SE_TCL_INPUT_VTX_VECTOR_ADDR_1_vtx_color_1_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr1, 
                                                                    dwDxSrcRegOffset);
            break;
        default:
            break;
        }
        break;
    case D3DSPR_TEXCRDOUT:
        switch(dwDxDstRegOffset)
        {
        case 0:
            set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_tex_0_sel(&pPvsOptData->pvsRegSeTclOutVtxCompSel, 0);
            set_SE_TCL_INPUT_VTX_VECTOR_ADDR_2_vtx_tex_0_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr2, 
                                                                    dwDxSrcRegOffset);
            break;
        case 1:
            set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_tex_1_sel(&pPvsOptData->pvsRegSeTclOutVtxCompSel, 0);
            set_SE_TCL_INPUT_VTX_VECTOR_ADDR_2_vtx_tex_1_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr2, 
                                                                    dwDxSrcRegOffset);
            break;
        case 2:
            set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_tex_2_sel(&pPvsOptData->pvsRegSeTclOutVtxCompSel, 0);
            set_SE_TCL_INPUT_VTX_VECTOR_ADDR_2_vtx_tex_2_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr2, 
                                                                    dwDxSrcRegOffset);
            break;
        case 3:
            set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_tex_3_sel(&pPvsOptData->pvsRegSeTclOutVtxCompSel, 0);
            set_SE_TCL_INPUT_VTX_VECTOR_ADDR_2_vtx_tex_3_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr2, 
                                                                    dwDxSrcRegOffset);
            break;
        case 4:
            set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_tex_4_sel(&pPvsOptData->pvsRegSeTclOutVtxCompSel, 0);
            set_SE_TCL_INPUT_VTX_VECTOR_ADDR_3_vtx_tex_4_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr3, 
                                                                    dwDxSrcRegOffset);
            break;
        case 5:
            set_SE_TCL_OUTPUT_VTX_COMP_SEL_vtx_tex_5_sel(&pPvsOptData->pvsRegSeTclOutVtxCompSel, 0);
            set_SE_TCL_INPUT_VTX_VECTOR_ADDR_3_vtx_tex_5_addr(&pPvsOptData->pvsInputVecAddr.inputVtxVectorAddr3, 
                                                                    dwDxSrcRegOffset);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

/******************************************************************************
* __inline DWORD VS_HwGenerateDxToken()
*
* Args:
*   dwDxRegType          D3D register type
*   dwDxRegOffset        D3D register offset
*   dwDxWriteSwizzleMask D3D write mask, or swizzle...depends if its a 
*                        dest or src register
*   dwDxAddrMode         src address mode
*  
* Returns: a DWORD
*
* Description: This function generates a DX token...it is used for expanding 
*              the DX macros into the proper instructions
*
* Notes:
*   
******************************************************************************/
__inline DWORD VS_HwGenerateDxToken(DWORD dwDxDstRegType, DWORD dwDxDstRegOffset, 
                                    DWORD dwDxWriteSwizzleMask, DWORD dwDxAddrMode,
                                    DWORD dwDxSrcMod)
{
    return (0x80000000|dwDxDstRegType | dwDxDstRegOffset | dwDxWriteSwizzleMask | dwDxAddrMode| dwDxSrcMod);
}

/******************************************************************************
* __inline DWORD VS_GetFVFForVirtualElement()
*
* Args:
*  
* Returns: 
*
* Description: 
*
* Notes:
*   
******************************************************************************/
__inline VOID VS_GetFVFForVirtualElement(LPATIVTXSHADER pAtiVertexShader, LPDWORD pdwFVFType, DWORD dwRegType)
{
    switch(dwRegType)
    {
        case D3DVSDE_POSITION:
          *pdwFVFType |= D3DFVF_XYZ;
          break;

        case D3DVSDE_POSITION2:
          pAtiVertexShader->dwFlags |= VS_TWEENING_ENABLED;
          break;

        case D3DVSDE_NORMAL:
          *pdwFVFType |=  D3DFVF_NORMAL;
          pAtiVertexShader->dwFlags |= VS_NORMAL0_ENABLED;
          break;

        case D3DVSDE_NORMAL2:
          pAtiVertexShader->dwFlags |= VS_NORMAL1_ENABLED;
          break;

        case D3DVSDE_BLENDWEIGHT:
          // This shouldn't work when using HOS
          //dwBWCount += VS_CalcBlendWt(dwDataType);
          break;

        case D3DVSDE_BLENDINDICES:
          // this shouldn't work either in HOS
          //*pdwFVFType |= D3DFVF_LASTBETA_UBYTE4;
          break;

        case D3DVSDE_DIFFUSE:
          *pdwFVFType |= D3DFVF_DIFFUSE;
          break;

        case D3DVSDE_SPECULAR:
          *pdwFVFType |= D3DFVF_SPECULAR;
          break;

        case D3DVSDE_TEXCOORD0:
        case D3DVSDE_TEXCOORD1:
        case D3DVSDE_TEXCOORD2:
        case D3DVSDE_TEXCOORD3:
        case D3DVSDE_TEXCOORD4:
        case D3DVSDE_TEXCOORD5:
          {
            DWORD dwIndex = (dwRegType - D3DVSDE_TEXCOORD0);
            DWORD dwTexFVF = VS_HwGetTexFvf(*pdwFVFType, dwIndex, 2);
            *pdwFVFType &= ~D3DFVF_TEXCOUNT_MASK;
            *pdwFVFType |= dwTexFVF;
          }
          break;

        case D3DVSDE_PSIZE:
          *pdwFVFType |= D3DFVF_PSIZE;
          break;

        case D3DVSDE_TEXCOORD6:
        case D3DVSDE_TEXCOORD7:
          HSLDPF(E_ERROR_MESSAGE,
            "VS_GetFVFForVirtualElement: We support only 6 tex coord sets in fixed function mode");
          break;

        default:
          HSLDPF(E_ERROR_MESSAGE, "VS_GetFVFForVirtualElement: Invalid vector");
          break;
    }
}

/******************************************************************************
* __inline VOID VS_SetGeneratedDataInfo()
*
* Args:
*  
* Returns: 
*
* Description: 
*
* Notes:
*   
******************************************************************************/
__inline VOID VS_SetGeneratedDataInfo(LPATIVTXSHADER pAtiVertexShader, DWORD dwElementType, 
                                      DWORD dwElementGeneratedFrom, DWORD dwInterpType, BOOL bPVS)
{
    // Since we have to do PSC in software for our RTPatch implementation, we want
    // to have this array match up with the array we'd have in the hardware

    // Set DST_VEC_LOC
    if (bPVS)
    {
        // Just set the destination vector to whatever is passed in
    }
    else
    {
        // We need to map the MS vector locations to our HW fixed function locations
        switch(dwElementType)
        {
        case D3DVSDE_POSITION:
            dwElementType = ATI_VEC_LOC_POSITION0;
            break;
        case D3DVSDE_BLENDWEIGHT:
            dwElementType = ATI_VEC_LOC_BLENDWEIGHT;
            break;
        case D3DVSDE_BLENDINDICES:
            dwElementType = ATI_VEC_LOC_BLENDINDICES;
            break;
        case D3DVSDE_NORMAL:
            dwElementType = ATI_VEC_LOC_NORMAL0;
            break;
        case D3DVSDE_PSIZE:
            dwElementType = ATI_VEC_LOC_PSIZE;
            break;
        case D3DVSDE_DIFFUSE:
            dwElementType = ATI_VEC_LOC_COLOR0;
            break;
        case D3DVSDE_SPECULAR:
            dwElementType = ATI_VEC_LOC_COLOR1;
            break;
        case D3DVSDE_TEXCOORD0:
            dwElementType = ATI_VEC_LOC_TEXTURE0;
            break;
        case D3DVSDE_TEXCOORD1:
            dwElementType = ATI_VEC_LOC_TEXTURE1;
            break;
        case D3DVSDE_TEXCOORD2:
            dwElementType = ATI_VEC_LOC_TEXTURE2;
            break;
        case D3DVSDE_TEXCOORD3:
            dwElementType = ATI_VEC_LOC_TEXTURE3;
            break;
        case D3DVSDE_TEXCOORD4:
            dwElementType = ATI_VEC_LOC_TEXTURE4;
            break;
        case D3DVSDE_TEXCOORD5:
            dwElementType = ATI_VEC_LOC_TEXTURE5;
            break;
        case D3DVSDE_POSITION2:
            dwElementType = ATI_VEC_LOC_POSITION1;
            break;
        case D3DVSDE_NORMAL2:
            dwElementType = ATI_VEC_LOC_NORMAL1;
            break;
        default:
            HSLDPF(E_ERROR_MESSAGE, "VS_SetGeneratedDataInfo: Invalid destination vector");
            dwElementType = ATI_VEC_LOC_NORMAL0;    // Prevent buffer overrun
        }
    }

    pAtiVertexShader->wGenerateDataInfo[dwElementType] = ((LOWORD(dwInterpType) << 14) | 
                                                            LOWORD(dwElementGeneratedFrom));
}

/******************************************************************************
* __inline VOID VS_HwSetPPFogColorIndSel()
*
* Args: reg             pointer to fog color register
*       fog_index_sel   value for reg.FOG_INDEX_SEL bitfield
*  
* Returns: VOID
*
* Description: This routes to the correct asic dependent 
*              set_PP_FOG_COLOR_fog_index_sel call
*
* Notes:
*   
******************************************************************************/
__inline VOID VS_HwSetPPFogColorIndSel(regPP_FOG_COLOR *reg, unsigned int fog_index_sel)
{
    set_PP_FOG_COLOR_fog_index_sel_r2(reg, fog_index_sel); // fog select specular alpha
}

/******************************************************************************
* LPDWORD VS_HwUpdatePVSRegs()
*
* Args:
*   pdwOut         pointer location in command buffer
*   pCtxt          pointer to the current context
*  
* Returns: updated pointer location for next command buffer write
*
* Description:
*   This routine updates the PVS control registers 
*   (mm_SE_PVS_CNTL & mm_SE_PVS_CONST_CNTL). Basically, calls SetOneRegPM4.
*
* Notes:
*   
******************************************************************************/

__inline LPDWORD VS_HwUpdatePVSRegs(LPDWORD pdwOut, LPATID3DCNTX pCtxt)
{
    pdwOut = SetOneRegPM4(pdwOut, mmSE_PVS_CNTL, pCtxt->SePvsCntl_reg.u32All);
    pdwOut = SetOneRegPM4(pdwOut, mmSE_PVS_CONST_CNTL, pCtxt->SePvsConstCntl_reg.u32All);
    return pdwOut;
}

/******************************************************************************
* VOID VS_DumpHexShader()
*
* Args:
*   pdwOrigCode         - Original microcode
*   dwCodeCount         - Length (in instructions) of original microcode
*  
* Description:
*   This routine dumps out an input shader in Hex
*
* Notes:
*   
******************************************************************************/
__inline VOID VS_DumpHexShader(LPDWORD pdwOrigCode, DWORD dwCodeCount)
{
    DWORD i;

    HSLDPF(E_SHADER_DUMP, "-----START OF SHADER-----");
    // output code length twice for PVSOptimize testbench
    HSLDPF(E_SHADER_DUMP, "%d", dwCodeCount);
    HSLDPF(E_SHADER_DUMP, "%d", dwCodeCount); 
    
    for(i = 0; i < dwCodeCount*4; i++)
    {
      HSLDPF(E_SHADER_DUMP, "0x%08x", pdwOrigCode[i]);
    }
}
#endif // _HWVERTEXSHADER_H_


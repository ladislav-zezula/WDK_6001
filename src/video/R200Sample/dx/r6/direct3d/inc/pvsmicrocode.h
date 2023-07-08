

//    
//  Workfile: PvsMicrocode.h
//
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 2000-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//
#ifndef _PVSMICROCODE_H
#define _PVSMICROCODE_H

// R200 PVS Hardware parameters
#define PVS_MAX_CODE_LINES  128
#define PVS_MAX_CONST       192
#define PVS_MAX_INPUT       16
#define MAX_OUT_COLORS      2
#define MAX_OUT_TEXTURES    6
#define MAX_PVS_TEMP        12

//---------------------------------------------------------------------
// The following enum types and structures are used to maniulate
// PVS microcode in a more readable form.
//---------------------------------------------------------------------
#define PVS_MACRO_EN      0x80
#define PVS_MATH_EN       0x40
#define PVS_MACRO_OP      0x7f
#define PVS_MICRO_OP      0x3f

#define PVSC_OUTPUT_STREAM_POS      0
#define PVSC_OUTPUT_STREAM_COLOR0   1
#define PVSC_OUTPUT_STREAM_COLOR1   2
#define PVSC_OUTPUT_STREAM_TEXTURE0 3
#define PVSC_OUTPUT_STREAM_TEXTURE1 4
#define PVSC_OUTPUT_STREAM_TEXTURE2 5
#define PVSC_OUTPUT_STREAM_TEXTURE3 6
#define PVSC_OUTPUT_STREAM_TEXTURE4 7
#define PVSC_OUTPUT_STREAM_TEXTURE5 8
#define PVSC_OUTPUT_STREAM_POINTSZ  9
#define PVSC_OUTPUT_STREAM_FOG      10
#define PVSC_OUTPUT_STREAM_NUM      11

enum VectorEn_Opcode { VECTOR_NO_OP                   =  0,
                       VE_DOT_PRODUCT                 =  1,
                       VE_MULTIPLY                    =  2,
                       VE_ADD                         =  3,
                       VE_MULTIPLY_ADD                =  4,
                       VE_DISTANCE_VECTOR             =  5,
                       VE_FRACTION                    =  6,
                       VE_MAXIMUM                     =  7,
                       VE_MINIMUM                     =  8,
                       VE_SET_GREATER_THAN_EQUAL      =  9,
                       VE_SET_LESS_THAN               = 10,
                       VE_MULTIPLYX2_ADD              = 11,
                       VE_MULTIPLY_CLAMP              = 12,
                       VE_FLT2FIX_DX                  = 13,
                       VE_FLT2FIX_DX_RND              = 14,
                       NUMBER_OF_VE_OPCODE            = 15
};

#define HW_PASS_THRU_OPC    0xff


enum PVS_MACRO_ID         { PVS_MACRO_OP_2CLK_MADD    = 0,
                            PVS_MACRO_OP_2CLK_M2X_ADD = 1, 
                            PVS_MACRO_OP_NEXT         = 2 };

enum MathEn_Opcode { MATH_NO_OP                =  0,
                     ME_EXP_BASE2_DX           =  1,
                     ME_LOG_BASE2_DX           =  2,
                     ME_EXP_BASEE_FF           =  3,
                     ME_LIGHT_COEFF_DX         =  4,
                     ME_POWER_FUNC_FF          =  5,
                     ME_RECIP_DX               =  6,
                     ME_RECIP_FF               =  7,
                     ME_RECIP_SQRT_DX          =  8,
                     ME_RECIP_SQRT_FF          =  9,
                     ME_MULTIPLY               = 10,
                     ME_EXP_BASE2_FULL_DX      = 11,
                     ME_LOG_BASE2_FULL_DX      = 12,
                     ME_POWER_FUNC_FF_CLAMP_B  = 13,      
                     ME_POWER_FUNC_FF_CLAMP_B1 = 14,      
                     ME_POWER_FUNC_FF_CLAMP_01 = 15,
                     NUMBER_OF_ME_OPCODE       = 16
};

// r200 pvs register types
enum PvsRegisterType { PVS_REG_TEMPORARY      = 0,
                       PVS_REG_INPUT          = 1,
                       PVS_REG_CONSTANT       = 2,
                       PVS_REG_A0             = 3,
                       PVS_REG_OUT_POSITION   = 4,
                       PVS_REG_OUT_COLOR      = 5,
                       PVS_REG_OUT_TEXTURE    = 6,
                       PVS_REG_OUT_FOG        = 7,
                       PVS_REG_OUT_POINT_SIZE = 8,
                       PVS_REG_UNUSED0        = 9,
                       PVS_REG_UNUSED1        = 10,
                       PVS_REG_UNUSED2        = 11,
                       PVS_REG_UNUSED3        = 12,
                       PVS_REG_UNUSED4        = 13,
                       PVS_REG_UNUSED5        = 14,
                       PVS_REG_UNUSED6        = 15,
                       NUMBER_OF_PVS_REG_TYPE = 16
};

#define PVS_REG_ALT_TEMPORARY 17

enum PvsSrcRegisterType { PVS_SRC_REG_TEMPORARY      = 0,
                          PVS_SRC_REG_INPUT          = 1,
                          PVS_SRC_REG_CONSTANT       = 2,
                          PVS_SRC_REG_ALT_TEMPORARY  = 3,
                          PVS_SRC_REG_UNUSED0        = 9,
                          NUMBER_OF_PVS_SRC_REG_TYPE = 16
};

enum PvsDstRegisterType { PVS_DST_REG_TEMPORARY      = 0,
                          PVS_DST_REG_A0             = 1,
                          PVS_DST_REG_OUT            = 2,
                          PVS_DST_REG_OUT_X_REPL     = 3,
                          PVS_DST_REG_ALT_TEMPORARY  = 4,
                          PVS_DST_REG_INPUT          = 5,
                          NUMBER_OF_PVS_DST_REG_TYPE = 16
};



enum PvsSrcModifier  { NO_MODIFIER            = 0,
                       MODIFIER_SRCNEG        = 1,
                       NUMBER_OF_MODIFIERS    = 2
};

enum PvsAddressMode  { ADDR_ABSOLUTE          = 0,
                       ADDR_RELATIVE_A0       = 1,
                       ADDR_RELATIVE_FLI_0    = 2,
                       NUMBER_OF_ADDR_MOD     = 3
};

enum PvsRegSel       { X_SEL     = 0,
                       Y_SEL     = 1,
                       Z_SEL     = 2,
                       W_SEL     = 3
};

enum SrcSwizzleSelect { SRC_SELECT_X         = 0,
                        SRC_SELECT_Y         = 1,
                        SRC_SELECT_Z         = 2,
                        SRC_SELECT_W         = 3,
                        SRC_SELECT_FORCE_0   = 4,
                        SRC_SELECT_FORCE_1   = 5,
                        NUMBER_OF_SRC_SELECT = 6
};

typedef struct {
    unsigned long
        op                :  8,    
        reg_type          :  4,
        spare1            :  1,
        offset            :  7,    
        we_x              :  1,
        we_y              :  1,
        we_z              :  1,
        we_w              :  1,
        spare             :  8;
} PvsOpDstOperand;

typedef struct {
    unsigned long
        reg_type          :  4,
        addr_mode_0       :  1,
        offset            :  8,    
        swizzle_x         :  3,
        swizzle_y         :  3,
        swizzle_z         :  3,
        swizzle_w         :  3,
        modifier_x        :  1,
        modifier_y        :  1,
        modifier_z        :  1,
        modifier_w        :  1,
        addr_reg_sel      :  2,
        addr_mode_1       :  1;
} PvsSrcOperand;

typedef struct {
    PvsOpDstOperand    op_dst;
    PvsSrcOperand      src1;
    PvsSrcOperand      src2;
    PvsSrcOperand      src3;
} PvsInstruction;

#endif // _PVSMICROCODE_H


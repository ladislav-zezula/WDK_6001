

//  Workfile: pixelshader.h
//
//  Description: DX8 PixelShader Support
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 2000, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _PIXELSHADER_H__
#define _PIXELSHADER_H__

//*****************************************************************************
// Defines
//*****************************************************************************

#include "atidxinc.h"
#include "radeonBFFunc.h"  // uses regPP_PIXSHADER_XX_XX types
#include "chaplin_enum.h"
#include "atid3ddefs.h"    // uses ATI_RAD2_ defines
#include "d3d_hw_enum.h"   // uses E_TEXCOORD_TYPE

// Define the common Pixel Shader Versions
#define PS_1_0 D3DPS_VERSION(1,0)
#define PS_1_1 D3DPS_VERSION(1,1)
#define PS_1_2 D3DPS_VERSION(1,2)
#define PS_1_3 D3DPS_VERSION(1,3)
#define PS_1_4 D3DPS_VERSION(1,4)
#define PS_LEGACY_LEGACY D3DPS_VERSION(254,254)
#define PS_255_255 D3DPS_VERSION(255,255)

// min and max values for scalars that are loaded into const registers

#define ATI_RAD2_PSHADER_MIN_SCALAR             -1.0f
#define ATI_RAD2_PSHADER_MAX_SCALAR              1.0f

// maximum number of pixelshader instructions in a texm3x3___ sequence

#define PS_MAX_TEXSEQ 3
#define PS_NUM_EYEVEC_COMPS 3

// Number of pixel shader phases (i.e. Number of passes supported by the HW
#define PS_MAX_NUM_PHASES 2

// legacy-specific pixel shader 'instructions' to match legacy pixel processing
#define D3DSIO_TEXBEM_LEGACY    (0xC001)
#define D3DSIO_TEXBEML_LEGACY   (0xC002)

// define an ATI R200-specific destination modifier.  D3D allocates 4 bits for this
// but only defines one valid value (0x1, for _sat).  We add a new modifier to expose
// Chaplin HW wraping mode for destination registers.
#define ATI_D3DSPDM_WRAP 0x2<<D3DSP_DSTMOD_SHIFT

// Used by the HW mapping tables to indicate a Texture Unit is not in use
#define PS_TEX_NOT_USED         0xFFFFFFFF 

// C8 is reserved for "Radeon Black" = ARGB = (1.0, 0.0, 0.0, 0.0)
#define ATI_PS_BLACK_REGNUM     8

// C9 is reserved for use as Zero = ARGB = (0.0, 0.0, 0.0, 0.0).  The primary
// use of this register will be to support an uninitialized TSS D3DTA_TEMP 
// register which according to the SDK documentation defaults to zero.
#define ATI_PS_ZERO_REGNUM      9

// C10 is reserved for use as Rotation Matrix0/LUMSCALE for address passes
#define ATI_PS_ROTMAT0_REGNUM   10
#define ATI_PS_LUMSCALE_REGNUM  10

// C11 is reserved for use as Rotation Matrix1/LUMOFFSET for address passes
#define ATI_PS_ROTMAT1_REGNUM   11
#define ATI_PS_LUMOFFSET_REGNUM 11

// C12 is reserved for Minus One = ARGB = (-1.0, -1.0, -1.0, -1.0)
#define ATI_PS_MINUSONE_REGNUM  12

// macro to safely create a D3D Register Type for both DX8 and DX9
#if (DIRECT3D_VERSION >= 0x0900)

#define MAKE_REGTYPE(_RegFile) \
 ((((_RegFile)&(D3DSP_REGTYPE_MASK>>D3DSP_REGTYPE_SHIFT))<<D3DSP_REGTYPE_SHIFT)|\
  (((_RegFile)&(D3DSP_REGTYPE_MASK2>>D3DSP_REGTYPE_SHIFT2))<<D3DSP_REGTYPE_SHIFT2))

#else

#define MAKE_REGTYPE(_RegFile) (_RegFile)

#endif

// macro to convert a source register token of one type into a source register
// of a different type while preserving all source modifiers. (DX8 and DX9)
#if (DIRECT3D_VERSION >= 0x0900)

#define D3DSPRCONVERT( _RegFile, _Source) (\
    (_Source & (~D3DSP_REGTYPE_MASK & ~D3DSP_REGTYPE_MASK2) ) | \
    MAKE_REGTYPE(D3DSPR_##_RegFile))

#else	// (DIRECT3D_VERSION >= 0x0900)

#define D3DSPRCONVERT( _RegFile, _Source) (\
    (_Source & (~D3DSP_REGTYPE_MASK) ) | \
    MAKE_REGTYPE(D3DSPR_##_RegFile))

#endif	// (DIRECT3D_VERSION >= 0x0900)


// macro to convert a DX9 SPR TYPE to DX8  SPRTYPE
#if (DIRECT3D_VERSION >= 0x0900)

#define D3DSPRTODX8(_DX9SPRTYPE) (_DX9SPRTYPE << D3DSP_REGTYPE_SHIFT) 

#else	// (DIRECT3D_VERSION >= 0x0900)

#define D3DSPRTODX8(_DX8SPRTYPE) (_DX8SPRTYPE) 

#endif	// (DIRECT3D_VERSION >= 0x0900)

// macro to convert a destination register token of one type and number into
// a destination register token of a different type and different number,
// preserving all destination modifiers and write masks.
#define D3DSPDCONVERT( _RegFile, _Num, _Source) (\
    _Source | (MAKE_REGTYPE(D3DSPR_##_RegFile)) | ( (_Num) & D3DSP_REGNUM_MASK) )

// macro to convert a source register token of one type into a source register
// of a different type while preserving all source modifiers.
//#define D3DSPRCONVERT( _RegFile, _Source) (\
//    (_Source & ~(D3DSP_REGTYPE_MASK)) | (D3DSPR_##_RegFile) )

// Note: we have to keep using MAKE_REGTYPE and D3DSI_GETREGTYPE because there are some
// difference between DX8 and Dx9
// macro to generate PixelShader destination register tokens
#define D3DSPD( _RegFile, _Num ) (\
    (1L<<31) | MAKE_REGTYPE(D3DSPR_##_RegFile) | ( (_Num) & D3DSP_REGNUM_MASK)  )

// macro to generate PixelShader source register tokens
#define D3DPSPS( _RegFile, _Num ) (\
    (1L<<31) | ((_Num)&D3DSP_REGNUM_MASK) | D3DSP_NOSWIZZLE | MAKE_REGTYPE(D3DSPR_##_RegFile) )

// macro to generate a Pixel Shader source register token with the specified
// source modifiers and Swizzle
#define D3DPSCREATESRC( _RegFile, _Num, _Mods, _Swizzle ) (\
    (1L<<31) | ((_Num)&D3DSP_REGNUM_MASK) | _Mods | _Swizzle | MAKE_REGTYPE(D3DSPR_##_RegFile) )

// macro to generate a PixelShader source reg token from a destination reg token
#define D3DPDTOS( t ) (\
    (1L<<31) | (t & D3DSP_REGNUM_MASK) | MAKE_REGTYPE(D3DSI_GETREGTYPE(t)) | D3DSP_NOSWIZZLE ) 

// macro to generate a PixelShader destination reg token from a source reg token
#define D3DPSTOD( t ) (\
    (1L<<31) | (t & D3DSP_REGNUM_MASK) | MAKE_REGTYPE(D3DSI_GETREGTYPE(t)) ) 

// macro to convert a destination register's output clamp modifier from one 
// type to another
#define D3DCONVERT_DESTCLAMP(_Source, _NewClamp)(\
    (_Source & (~D3DSP_DSTMOD_MASK)) | _NewClamp)

// 'writemask' masks and macros for D3D desination register tokens
#define PS_WRITEMASK_R    ( D3DSP_WRITEMASK_0 )
#define PS_WRITEMASK_G    ( D3DSP_WRITEMASK_1 )
#define PS_WRITEMASK_B    ( D3DSP_WRITEMASK_2 )
#define PS_WRITEMASK_A    ( D3DSP_WRITEMASK_3 )
#define PS_WRITEMASK_RGBA ( D3DSP_WRITEMASK_0 | D3DSP_WRITEMASK_1 | D3DSP_WRITEMASK_2 | D3DSP_WRITEMASK_3 )
#define PS_WRITEMASK_RGB  ( D3DSP_WRITEMASK_0 | D3DSP_WRITEMASK_1 | D3DSP_WRITEMASK_2 )

#define PS_MOD_WRITEMASK_R( s )  ( s & ~PS_WRITEMASK_RGBA | PS_WRITEMASK_R )
#define PS_MOD_WRITEMASK_G( s )  ( s & ~PS_WRITEMASK_RGBA | PS_WRITEMASK_G )
#define PS_MOD_WRITEMASK_GB( s )  ( s & ~PS_WRITEMASK_RGBA | PS_WRITEMASK_G | PS_WRITEMASK_B )
#define PS_MOD_WRITEMASK_RG( s )  ( s & ~PS_WRITEMASK_RGBA | PS_WRITEMASK_R | PS_WRITEMASK_G )
#define PS_MOD_WRITEMASK_B( s )  ( s & ~PS_WRITEMASK_RGBA | PS_WRITEMASK_B )
#define PS_MOD_WRITEMASK_A( s )  ( s & ~PS_WRITEMASK_RGBA | PS_WRITEMASK_A )
#define PS_MOD_WRITEMASK_RGB( s )  ( s & ~PS_WRITEMASK_RGBA | PS_WRITEMASK_RGB )
#define PS_MOD_WRITEMASK_NONE( s )  ( s & ~PS_WRITEMASK_RGBA )

#define PS_MOD_X2( s )  ( ( s & ~D3DSP_DSTSHIFT_MASK) | ( 0x1 << D3DSP_DSTSHIFT_SHIFT ) )
 
// common swizzle masks for D3D source register tokens.  Note that the D3D
// headers already define D3DSP_REPLICATEALPHA and D3DSP_NOSWIZZLE.  The other source modifier
// swizzles (RRR, GGG, BBB) are supported by Chaplin HW, but not by D3D 1.0 PixelShaders.

#ifndef D3DSP_REPLICATERED
// Define Replicate Red for Non DX8.1 compilations
#define D3DSP_REPLICATERED \
    ( (0 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
      (0 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
      (0 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
      (0 << (D3DSP_SWIZZLE_SHIFT + 6)) )
#endif

#ifndef D3DSP_REPLICATEGREEN
// Define Replicate Green for Non DX8.1 compilations
#define D3DSP_REPLICATEGREEN \
    ( (1 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
      (1 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
      (1 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
      (1 << (D3DSP_SWIZZLE_SHIFT + 6)) )
#endif

#ifndef D3DSPREPLICATEBLUE
// Define Replicate Blue for Non DX8.1 compilations
#define D3DSP_REPLICATEBLUE \
    ( (2 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
      (2 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
      (2 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
      (2 << (D3DSP_SWIZZLE_SHIFT + 6)) )

#endif

// swizzles for D3D destinstion register tokens.  These are supported by  
// Chaplin HW only on color pipe, but not by D3D 1.0 PixelShaders.
                                        // A->A, A->R, R->G, G->B
#define PS_SWIZZLE_AARG \
    ( (3 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
      (3 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
      (2 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
      (1 << (D3DSP_SWIZZLE_SHIFT + 6)) )
                                        // A->A, G->R, B->G, A->B
#define PS_SWIZZLE_AGBA \
    ( (3 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
      (1 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
      (0 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
      (3 << (D3DSP_SWIZZLE_SHIFT + 6)) )
                                        // A->A, R->R, G->G, A->B
#define PS_SWIZZLE_ARGA \
    ( (3 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
      (2 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
      (1 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
      (3 << (D3DSP_SWIZZLE_SHIFT + 6)) )


// macros for applying swizzle to tokens.

#define PS_MOD_SWIZZLE_RRRR( s )  ( s & ~D3DSP_SWIZZLE_MASK | D3DSP_REPLICATERED )
#define PS_MOD_SWIZZLE_GGGG( s )  ( s & ~D3DSP_SWIZZLE_MASK | D3DSP_REPLICATEGREEN )
#define PS_MOD_SWIZZLE_BBBB( s )  ( s & ~D3DSP_SWIZZLE_MASK | D3DSP_REPLICATEBLUE )
#define PS_MOD_SWIZZLE_AAAA( s )  ( s & ~D3DSP_SWIZZLE_MASK | D3DSP_REPLICATEALPHA )
#define PS_MOD_SWIZZLE_AARG( s )  ( s & ~D3DSP_SWIZZLE_MASK | PS_SWIZZLE_AARG )
#define PS_MOD_SWIZZLE_AGBA( s )  ( s & ~D3DSP_SWIZZLE_MASK | PS_SWIZZLE_AGBA )
#define PS_MOD_SWIZZLE_ARGA( s )  ( s & ~D3DSP_SWIZZLE_MASK | PS_SWIZZLE_ARGA )
#define PS_MOD_NOSWIZZLE( s )     ( s & ~D3DSP_SWIZZLE_MASK | D3DSP_NOSWIZZLE )

// PixelShader Flags:  Used to record which resources a compiled pixel shader
// actually uses.  Also used to determine which HW registers need to be written
// to when the active pixel shader is switched.

#define ATI_PS_CONST00_USED  0x00000001L     // Shader pre-loads const register C0
#define ATI_PS_CONST01_USED  0x00000002L     // Shader pre-loads const register C1
#define ATI_PS_CONST02_USED  0x00000004L     // Shader pre-loads const register C2
#define ATI_PS_CONST03_USED  0x00000008L     // Shader pre-loads const register C3
#define ATI_PS_CONST04_USED  0x00000010L     // Shader pre-loads const register C4
#define ATI_PS_CONST05_USED  0x00000020L     // Shader pre-loads const register C5
#define ATI_PS_CONST06_USED  0x00000040L     // Shader pre-loads const register C6
#define ATI_PS_CONST07_USED  0x00000080L     // Shader pre-loads const register C7

#define ATI_PS_INSTB00_USED  0x00000100L     // Shader uses BS instruction 0
#define ATI_PS_INSTB01_USED  0x00000200L     // Shader uses BS instruction 1
#define ATI_PS_INSTB02_USED  0x00000400L     // Shader uses BS instruction 2
#define ATI_PS_INSTB03_USED  0x00000800L     // Shader uses BS instruction 3
#define ATI_PS_INSTB04_USED  0x00001000L     // Shader uses BS instruction 4
#define ATI_PS_INSTB05_USED  0x00002000L     // Shader uses BS instruction 5
#define ATI_PS_INSTB06_USED  0x00004000L     // Shader uses BS instruction 6
#define ATI_PS_INSTB07_USED  0x00008000L     // Shader uses BS instruction 7

#define ATI_PS_INSTA00_USED  0x00010000L     // Shader uses AS instruction 0
#define ATI_PS_INSTA01_USED  0x00020000L     // Shader uses AS instruction 1
#define ATI_PS_INSTA02_USED  0x00040000L     // Shader uses AS instruction 2
#define ATI_PS_INSTA03_USED  0x00080000L     // Shader uses AS instruction 3
#define ATI_PS_INSTA04_USED  0x00100000L     // Shader uses AS instruction 4
#define ATI_PS_INSTA05_USED  0x00200000L     // Shader uses AS instruction 5
#define ATI_PS_INSTA06_USED  0x00400000L     // Shader uses AS instruction 6
#define ATI_PS_INSTA07_USED  0x00800000L     // Shader uses AS instruction 7

#define ATI_PS_ANY_CONST_USED  0x000000FFL     // Shader pre-loads any const register
#define ATI_PS_ANY_INSTB_USED  0x0000FF00L     // Shader uses any BS instruction
#define ATI_PS_ANY_INSTA_USED  0x00FF0000L     // Shader uses any AS instruction

#define ATI_PS_FN_SEL_AVAILABLE 0xFFFFFFFFul    // indicates F0_sel or F1_sel free

// Flags for TextureUnit TxModes.  For R200, each texture unit can be programmed
// to operare in several different modes.  For multipass shaders, the texture units
// are programmed differently between the 1st (AS) pass the the second (BS) pass.

#define ATI_PS_TXMODE_DISABLE             0x00000000L     // unit is disabled (default)
#define ATI_PS_TXMODE_ENABLE              0x00000001L     // unit is enabled
#define ATI_PS_TXMODE_BYPASS              0x00000002L     // unit in bypass mode
#define ATI_PS_TXMODE_TEXKILL             0x00000004L     // unit in texkill mode
#define ATI_PS_TXMODE_ROUTE_EYE           0x00000008L     // unit gets routed the Eye vector
#define ATI_PS_TXMODE_COORDTYPE_FVF       0x00000010L     // dynamic TEX_COORD_TYPE based on FVF
#define ATI_PS_TXMODE_COORDTYPE_FORCE     0x00000020L     // unit has forced TEX_COORD_TYPE
#define ATI_PS_TXMODE_COORDTYPE_LOOPBACK  0x00000040L     // unit expects 3D texture coordinates because of phase loopback.
#define ATI_PS_TXMODE_COORDTYPE_MASK      0x00000F00L     // bits for selecting forced TEX_COORD_TYPE
#define ATI_PS_TXMODE_COORDTYPE_SHIFT     8
#define ATI_PS_TXMODE_COORDTYPE_1D        (E_TEXCOORD_1D << ATI_PS_TXMODE_COORDTYPE_SHIFT)
#define ATI_PS_TXMODE_COORDTYPE_2D        (E_TEXCOORD_2D << ATI_PS_TXMODE_COORDTYPE_SHIFT)
#define ATI_PS_TXMODE_COORDTYPE_3D        (E_TEXCOORD_VOLUME << ATI_PS_TXMODE_COORDTYPE_SHIFT)
#define ATI_PS_TXMODE_COORDTYPE_DEPTH     (E_TEXCOORD_DEPTH << ATI_PS_TXMODE_COORDTYPE_SHIFT)
#define ATI_PS_TXMODE_USE_W               0x00001000L
#define ATI_PS_TXMODE_USE_Z               0x00002000L
#define ATI_PS_TXMODE_TEX_PROJ            0x00004000L

// These flags indicate special features, or considerations, that need to be handled whenever
// a pixel shader is activated.  Flags are stored in the dwUsageFlags member of the
// _RAD2PIXELSHADER structure.

#define ATI_PS_USE_NONE              0x00000000L      // No special considerations
#define ATI_PS_USE_FVF               0x00000001L      // Pixel shader depends upon application's FVF
#define ATI_PS_USE_VSPEC_EYE         0x00000002L      // Pixel shader needs texture coord routing for EYE coord.
#define ATI_PS_USE_LUMINANCE         0x00000004L      // Pixel shader needs a texture unit enabled to pass 
                                                      // luminance between phases
#define ATI_PS_USE_CMP_INSTRUCTION   0x00000008L      // shader uses PS1.4 cmp instruction.  This triggres
                                                      // 
#define ATI_PS_USE_TEXDEPTH          0x00000010L      // Pixel shader is using the TEXDEPTH instruction  
#define ATI_PS_USE_DP4_INSTRUCTION   0x00000020L      // shader uses PS1.4 DP4 instruction.  This triggres
                                                      // 

// These flags are used to identify which instructions on which channel 
// (color or alpha) use Diffuse and/or Specular in their blending operations

#define ATI_PS_DIFFUSE_USE_MASK            0xFF
#define ATI_PS_SPECULAR_USE_MASK           0xFF
#define ATI_PS_COLOR_DIFFUSE_USE_SHIFT     0
#define ATI_PS_ALPHA_DIFFUSE_USE_SHIFT     8
#define ATI_PS_COLOR_SPECULAR_USE_SHIFT    16
#define ATI_PS_ALPHA_SPECULAR_USE_SHIFT    24

#define ATI_PS_ALL_ARGA_MASKS              PP_PIXSHADER_I0_C0__COMP_ARG_A_MASK  | \
                                           PP_PIXSHADER_I0_C0__BIAS_ARG_A_MASK  | \
                                           PP_PIXSHADER_I0_C0__SCALE_ARG_A_MASK | \
                                           PP_PIXSHADER_I0_C0__NEG_ARG_A_MASK   | \
                                           PP_PIXSHADER_I0_C0__COLOR_ARG_A_MASK

#define ATI_PS_ALL_ARGB_MASKS              PP_PIXSHADER_I0_C0__COMP_ARG_B_MASK  | \
                                           PP_PIXSHADER_I0_C0__BIAS_ARG_B_MASK  | \
                                           PP_PIXSHADER_I0_C0__SCALE_ARG_B_MASK | \
                                           PP_PIXSHADER_I0_C0__NEG_ARG_B_MASK   | \
                                           PP_PIXSHADER_I0_C0__COLOR_ARG_B_MASK 

#define ATI_PS_ALL_ARGC_MASKS              PP_PIXSHADER_I0_C0__COMP_ARG_C_MASK  | \
                                           PP_PIXSHADER_I0_C0__BIAS_ARG_C_MASK  | \
                                           PP_PIXSHADER_I0_C0__SCALE_ARG_C_MASK | \
                                           PP_PIXSHADER_I0_C0__NEG_ARG_C_MASK   | \
                                           PP_PIXSHADER_I0_C0__COLOR_ARG_C_MASK 

// PS_MAX_INSTR must be >= the max number of co-issued or RGBA instructions.
// It is used by PS_OptimizePixelShader.
#define PS_MAX_INSTR                  16

// Simple macros - one for finding out if a token is a PS arg,
// one for finding out if two tokens contain references to the same register.
#define PS_IS_ARG( _TOKEN ) ( _TOKEN & ( 1L << 31 ) )

// one for finding out if two tokens contain references to the same register.
#if (DIRECT3D_VERSION >= 0x0900)
#define PS_EQUAL_REG( _REG0, _REG1 ) ( ( _REG0 & ( D3DSP_REGNUM_MASK | D3DSP_REGTYPE_MASK | D3DSP_REGTYPE_MASK2 ) ) == \
				                       ( _REG1 & ( D3DSP_REGNUM_MASK | D3DSP_REGTYPE_MASK | D3DSP_REGTYPE_MASK2 ) ) )
#else
#define PS_EQUAL_REG( _REG0, _REG1 ) ( ( _REG0 & ( D3DSP_REGNUM_MASK | D3DSP_REGTYPE_MASK ) ) == \
				                       ( _REG1 & ( D3DSP_REGNUM_MASK | D3DSP_REGTYPE_MASK ) ) )
#endif


//*****************************************************************************
// Enumerations
//*****************************************************************************

typedef enum _PS_COMPILE_RESULT     // possible results of compiling a
{                                   // single shader instruction
    PS_RESULT_NONE                 = 0,
    PS_ALPHA_INSTRUCTION           = 1,
    PS_RBG_INSTRUCTION             = 2,
    PS_RGBA_INSTRUCTION            = 3,
    PS_ADDRESS_ALPHA_INSTRUCTION   = 4,
    PS_ADDRESS_RBG_INSTRUCTION     = 8,
    PS_ADDRESS_RGBA_INSTRUCTION    = 12,
    PS_OK                          = 16,
    PS_FAIL                        = 32
} PS_RESULT;

typedef enum _PS_SHADER_PASS        // the R200 shader supports 2 passes
{
    PS_ADDRESS_PASS = 0,
    PS_BLENDING_PASS = 1
} E_PS_SHADER_PASS;

typedef enum _PS_OP_MODIFIER        // possible shader instruction 
{                                   // modifiers  (R100 only)
    PS_MODIFIER_NONE = 0,
    PS_2X            = 1,
    PS_4X            = 2,
    PS_8X            = 4,
    PS_D2            = 8,
    PS_D4            = 16,
    PS_D8            = 32,
    PS_SAT           = 64,
    PS_WRAP          = 128,         // R200-specific.  Not supported by D3D.
} PS_OP_MODIFIER;

typedef enum _PS_ARG_SELECT
{
    PS_ARG_A = 0,
    PS_ARG_B = 1,
    PS_ARG_C = 2,
    NUM_PS_ARG = 3
} PS_ARG_SELECT;

typedef enum _PS14_CONST_USAGE_RESULT // Signed Constant Modifier Workaround.
{                                     // Indicate status of Register search
    PS14_CONSTUSAGE_NONE  = 0,          // No Writeable register available
    PS14_CONSTUSAGE_READY = 1,          // Register available and already constains const value
    PS14_CONSTUSAGE_NEW   = 2           // Register available and ready to be written with const value
} PS14_CONST_USAGE_RESULT;

typedef enum _PS_CONST_USAGE_RESULT   // Signed Constant Modifier Workaround for PS.1.0-3 shaders
{
    PS_CONSTUSAGE_NONE      = 0,      // No Writeable register available
    PS_CONSTUSAGE_TEXREADY  = 1,      // Texture register available and already contains const value
    PS_CONSTUSAGE_TEMPREADY = 2,      // Temp register available and already constains const value
    PS_CONSTUSAGE_TEXNEW    = 3,      // Texture Register available and ready to be writen with const value
    PS_CONSTUSAGE_TEMPNEW   = 4      // Temp Register available and ready to be writen with const value
} PS_CONST_USAGE_RESULT;


//*****************************************************************************
// Structures Common to Both R100 and R200
//*****************************************************************************

// The maximum "raw" pixel shader program size.  This is used to allocate
// enough space with each compiled pixel shader to maintain its uncompiled
// "raw" form incase it needs to be recompiled.
//
//   Begin and End Tokens    (2 Tokens)
//   8 Constant Declarations (18 tokens each)
//   6 Texure Declarations   (3 Tokens each)     
//   8 RGB instructions      (5 Tokens each)
//   8 Alpha Instructions    (5 Tokens Each)

#define MAXIMUM_PIXELSHADER_PROGRAM_SIZE 244

/*
    Texture Characteristics are special features about the textures bound to
    a collection of Texture Stage States that have an effect on the Compliation
    and Execution of Pixel Shaders.

    Currently the only feature we are really interested in is whether the
    texture is has a YUV pixel format or not.  This parameter will help to
    determine the proper assignment of D3D Pixel Shader Texture Registers to
    Physical HW Texture Units.

*/
#define TEXCHAR_NOTEXBOUND    0x00000000   // No Texture associated with a stage
#define TEXCHAR_TEXBOUND      0x00000001   // A Texture is associated with a stage
#define TEXCHAR_TEXISYUV      0x00000002   // The texture associated with a stage is YUV

typedef struct _TEXTURE_CHARACTERISTICS
{
    DWORD dwTexChars[MAX_TEXSTAGE];    // Maintain Texture Characteristics for
                                       // each Texture Stage.

    DWORD dwNumYUV;                    // Maintain a count of the number of YUV
                                       // textures currently used in the
                                       // context.

    DWORD dwNumNonYUV;                 // Maintain a count of the number of
                                       // NON-YUV textures currently used in
                                       // the context.

}TEXTURE_CHARACTERISTICS, *LPTEXTURE_CHARACTERISTICS;

typedef struct _PSRGBACONSTANT      // PixelShader Constant Value
{
    DWORD registerValue;            // RGBA 8888 packed format

    union{
	    struct {
	    	unsigned int   SGN_TF_B : 1;
	    	unsigned int   SGN_TF_G : 1;
		    unsigned int   SGN_TF_R : 1;
		    unsigned int   SGN_TF_A : 1;
        }bitfields;
        unsigned int	u32All;
    }ARGBSignBits;

}PSRGBACONSTANT, *LPPSRGBACONSTANT;

//*****************************************************************************
// Radeon 100 Structures
//*****************************************************************************

typedef struct _PSBUMPINFO          // Info necessary to process the texbem 
{                                     // instruction
    DWORD dwRegBump;     //Register specifying the bump map
    DWORD dwRegBumpped;  //Register specifying the texture being bumped.
    DWORD dwBumpOp;      //The specific bump map color op.

    BOOL  bBumpEnabled; //Flag indicating if texbem has been encountered.
} PSBUMPINFO, *LPPSBUMPINFO;

//*****************************************************************************
// Radeon 200 Structures
//*****************************************************************************


typedef enum _PS_BLEND_CNTL
{
    PSBLEND_ADD      = (0 << PP_PIXSHADER_I0_C0__BLEND_CTL__SHIFT),
    PSBLEND_CND0     = (2 << PP_PIXSHADER_I0_C0__BLEND_CTL__SHIFT),
    PSBLEND_LERP     = (3 << PP_PIXSHADER_I0_C0__BLEND_CTL__SHIFT),
    PSBLEND_DOT3     = (4 << PP_PIXSHADER_I0_C0__BLEND_CTL__SHIFT),
    PSBLEND_DOT4     = (5 << PP_PIXSHADER_I0_C0__BLEND_CTL__SHIFT),
    PSBLEND_CND      = (6 << PP_PIXSHADER_I0_C0__BLEND_CTL__SHIFT),
    PSBLEND_DOT2ADD  = (7 << PP_PIXSHADER_I0_C0__BLEND_CTL__SHIFT),
}PS_BLEND_CNTL;


// Macros to define common Constant Values
#define PS_ZERO       ( D3DPSPS(CONST, ATI_PS_ZERO_REGNUM) )
#define PS_ONE        ( D3DPSPS(CONST, ATI_PS_ZERO_REGNUM) | D3DSPSM_COMP )
#define PS_MINUS_ONE  ( D3DPSPS(CONST, ATI_PS_MINUSONE_REGNUM) )
#define PS_NONE       0

// Structure to track register usage for PS.1.4 Signed Constant Modifier
// Workaround.
// This structure makes up a single row of a very simple table used to
// track the availability of Pixel Shader 1.4 tempory registers.  It
// indicates if the tempory register is currently available to store
// a signed constant, and also if it is already storing a modified
// constant.  A check of the current value will indicate if the register's
// already represents the requested signed value, and therefore an additional
// pixel shader instruction is not needed to calculate it.
//
// This structure is separate from the PS.1.0-PS.1.3 table since PS.1.4 only
// contains a single type of writable register (R0-R5).
typedef struct _PS14_CONST_USAGE
{
    BOOL  bAvail;       // Is this register available.
    DWORD dwCurrValue;  // Does this register already contain a modified 
                        // constant, and if so what its value is.
} PS14_CONST_USAGE, *LPPS14_CONST_USAGE;

// This is the PS.1.0-PS.1.3 version of the Signed Constant Modifier
// Workaround table.  It tracks the usage of the temporary registers as well
// as the texture registers (since the hardware can treat each type equally).
typedef struct _PS_CONST_USAGE
{
    BOOL  bTempAvail[2];      // Status of Temporary Registers (r0 and r1)
    DWORD dwTempCurrValue[2]; // Value currently stored in temporary registers

    BOOL  bTexAvail[4];       // Status of Texture Registers
    DWORD dwTexCurrValue[4];  // Value currently stored in the texture registers
} PS_CONST_USAGE, *LPPS_CONST_USAGE;


typedef unsigned int PSINSTRUCTION, *LPPSINSTRUCTION;

// An abstract representation of a Pixel Shader Instruction, either
// Blend or Address.  These represent the actual registers that will
// be written to the hardware at Write Render State Time.  Therefore
// this structure should not contain any other data members, that are
// not pixel shader related registers.
typedef struct _PSINSTRUCTIONGROUP
{
    PSINSTRUCTION   C0;
    PSINSTRUCTION   C1;
    PSINSTRUCTION   A0;
    PSINSTRUCTION   A1;
} PSINSTRUCTIONGROUP, *LPPSINSTRUCTIONGROUP;

typedef struct _PSINSTRUCTIONSTATE       // compiler state for single instruction
{
    int        intRGBTerminalIns;
    int        intAlphaTerminalIns;
    E_PS_SHADER_PASS    eCurrPhase;     // indicates which phase for 1st instruction

    // for each 2nd phase register, this array indicates which 1st pass register
    // will be used to initialize it.  Any time a register flows from 1st to 2nd 
    // phase (either as value or texture coordinate) there will be a corresponding
    // entry in this table.  For those 2nd phase registers that dont need to be initialized
    // from the 1st pass, the value will be PS_TEX_NOT_USED.
    DWORD               BSRegSrc[ATI_RAD2_NUM_TEX_UNITS];

}PSINSTRUCTIONSTATE, *LPPSINSTRUCTIONSTATE;

typedef struct _PSTEXSEQSTATE       // compiler state for texmpad sequence, which
{                                   // will contain two or three instructions.
    BOOL bIsTexm3x3diff;            // seq contains a texm3x3diff instruction
    DWORD dwSrc0[PS_MAX_TEXSEQ];    // Src0 arg for each instruction
    DWORD dwDest[PS_MAX_TEXSEQ];    // Dest arg for each instruction
    DWORD dwNumInst;                // num instructions in sequence
}PSTEXSEQSTATE, *LPPSTEXSEQSTATE;

typedef struct _TXMODES             // A Texture Unit's mode settings
{
    DWORD modes;                    // Texture Unit Modes
    
    DWORD dwTexCoordSet;            // Texture Coord Set to use
}TXMODES, *LPTXMODES;

typedef	struct _RAD2PIXELSHADER             // Chaplin PixelShader (PS) Program
{
    // R200 HW PShader register state for this shader

    // NOTE:  It is assumed that the Number of Blend instructions is equal to
    //        the number of address instructions.
    PSINSTRUCTIONGROUP psInstructions[PS_MAX_NUM_PHASES][ATI_RAD2_NUM_BLEND_INST];
    DWORD              dwInstrCount[PS_MAX_NUM_PHASES];

    // R200 HW Texture Unit State.
    TXMODES            TxModes[PS_MAX_NUM_PHASES][ATI_RAD2_NUM_TEX_UNITS];

    PSRGBACONSTANT     constant[ATI_RAD2_NUM_PS_CONSTS];// PS DEF'ed constants

    regPP_CNTL             PpCntl_reg;
    regPP_CNTL_X           PpCntlx_reg;

    regPP_TXMULTI_CTL_0    PpTxMultiCntl0_reg;          // Multipass tex unit settings  
    regPP_TXMULTI_CTL_1    PpTxMultiCntl1_reg;    
    regPP_TXMULTI_CTL_2    PpTxMultiCntl2_reg;    
    regPP_TXMULTI_CTL_3    PpTxMultiCntl3_reg;    
    regPP_TXMULTI_CTL_4    PpTxMultiCntl4_reg;    
    regPP_TXMULTI_CTL_5    PpTxMultiCntl5_reg;
    
    // PS Compiler State.  These data members are active only during compilation.

    PSINSTRUCTIONSTATE iState;                          // per-instruction compiler state
    PSTEXSEQSTATE seqState;                             // texm___ instruction sequence state

    BOOL bPSSetsTexCoordDepthMode;                        // Pixel Shader determines use of Z or W
    DWORD dwTexCoordDepthMode[ATI_RAD2_NUM_TEX_UNITS];    // The Depth Settings dictated by the pixel shader        
    
    BOOL bPSSetsTexSampleMode;                          // Pixel Shader determines Texture Coord Routing and
                                                        //   projected texture.

    DWORD dwHWRegToTSSMap[ATI_RAD2_NUM_TEX_UNITS];                           // Map TexUnit to D3DStage

    // Other PixelShader State

    DWORD bumpping_d3dstage;                            // TSS Stage for RotMatrix
    DWORD dwPSDirtyFlags;                               // Dirty Flags for PS context
    BOOL  bPixelShaderIsValid;
    BOOL  bPixelShaderIsLegacy;
    DWORD dwPixelShaderVersion;

    BOOL bReuseTexRegs[ATI_RAD2_NUM_TEX_UNITS];

    DWORD dwUseFlags;           // Flags specifying special features used by this shader.
    DWORD dwEyeTexUnit;         // The texture unit containing the "eye" texture coords 
                                // used by tex3x3mvspec.
    DWORD dwEyeInTexCoordSet;   // The Texture Coordinante Set that contains the Eye 
                                // vector used by Texm3x3vspec instructions.

    // Specify the texture unit containing the luminance value from a TEXBEML
    // instruction
    DWORD dwLuminanceTexUnit;

    // Store the Texture Coord Indices where the X, Y, Z components of the Eye
    // vector can be found.  (The source of the Eye vector for a VSPEC 
    // instruction is stored in the 4th components of three Texture Coord Sets 
    // pased in through the FVF.
    DWORD dwEyeComponentLocations[PS_NUM_EYEVEC_COMPS]; 

    // The characteristics of the textures bound at at the time this shader was
    // compiled.  This info is  needed in order to determine if a recompile is
    // necessary due to YUV textures being bound or unbound.
    TEXTURE_CHARACTERISTICS textureChars; 

    // The raw Pixel Shader source code, stored incase a recompile is needed.
    // For PS.1.0 shaders and up this array contains the "Precompiled" shader
    // that is generated during the first pass of the pixel shader compiler.
    DWORD dwUncompiledShader[MAXIMUM_PIXELSHADER_PROGRAM_SIZE];
    DWORD dwActualUncompiledShaderSize;

    // The Diffuse and Specular characteristics of this shader.  This 
    // information will be used at Draw Time to determine if this shader will
    // need to use the default color values for Diffuse and Specular because
    // the application is not providing them with the vertex data.
    BOOL bPSModifiedForMissingDiffuse;
    BOOL bPSModifiedForMissingSpecular;
 
    // This variable stores the bit fields representing the Diffuse and
    // Specular usage (Color and Alpha) of each instruction.
    // The byte format of this variable is as follows:
    //
    //    ---------------------------------
    //    | Alpha | Color | Alpha | Color |
    //    | Spec  | Spec  | Diff  | Diff  |
    //    ---------------------------------
    //
    // Note that each instruction's characteristic (Diffuse used, or Specular
    // used, Color or Alpha) is represented by 1 bit.
    DWORD dwDiffSpecUsage;

    // The Mask values are used to properly strip, then set the override
    // values so that only the necessary arguments are adjusted.
    
    DWORD dwColorInstrDiffuseOverride[ATI_RAD2_NUM_BLEND_INST];
    DWORD dwColorInstrDiffuseMask[ATI_RAD2_NUM_BLEND_INST];
    DWORD dwAlphaInstrDiffuseOverride[ATI_RAD2_NUM_BLEND_INST];
    DWORD dwAlphaInstrDiffuseMask[ATI_RAD2_NUM_BLEND_INST];

    DWORD dwColorInstrSpecularOverride[ATI_RAD2_NUM_BLEND_INST];
    DWORD dwColorInstrSpecularMask[ATI_RAD2_NUM_BLEND_INST];
    DWORD dwAlphaInstrSpecularOverride[ATI_RAD2_NUM_BLEND_INST];
    DWORD dwAlphaInstrSpecularMask[ATI_RAD2_NUM_BLEND_INST];

    BOOL  bPatchedForDp3AlphaOpt;

}RAD2PIXELSHADER, *LPRAD2PIXELSHADER;

// This structure maintains a mapping from D3D Texture and Temporary 
// Registers to physical R200 texture units.  A flexiable mapping is
// required because only certin Texture Units support YUV -> RGB 
// conversions.
typedef struct _D3DPSREGISTERS
{
    //DWORD dwTexRegs[ATI_RAD2_NUM_TEX_UNITS]; // Mapping for D3D Texture Registers T0-T5
    DWORD dwTexRegs[6]; // Mapping for D3D Texture Registers T0-T5
    DWORD dwTempRegs[2];                     // Mapping for D3D Tempory Registers R0-R1
    
    // Store the Texture Unit currently assigned to HW Texture Unit 0.
    // The purpose of this value is to make it easy to locate Texture
    // Unit 0 when outputting a pixel shader's final value.
    DWORD dwTexRegUsingTU0;                     
                                             

} D3DPSREGISTERS, *LPD3DPSREGISTERS;


#define OPOFFSET_EMPTY    0xFFFFFFFE
#define OPOFFSET_END      0xFFFFFFFF

// This structure holds offsets for RGB and A instructions within
// a pixel shader array. It is filled and used by PS_OptimizePixelShader
// and the functions called by it.
struct _OPOFFSET_TABLE_ENTRY
{
    DWORD RGB;
    DWORD A;
};
typedef struct _OPOFFSET_TABLE_ENTRY OPOFFSET_TABLE_ENTRY;

//*****************************************************************************
// Prototypes for Chaplin (R200)
//*****************************************************************************
// DP2 OP handlers for Chaplin (R200)

HRESULT Rad2Dp2CreatePixelShader(struct _ATID3DCNTX *pCtxt,
                                 LPD3DHAL_DP2CREATEPIXELSHADER pCPS, 
                                 LPDWORD pCode);
HRESULT Rad2Dp2DeletePixelShader(struct _ATID3DCNTX *pCtxt, LPD3DHAL_DP2COMMAND pCmd);
HRESULT Rad2Dp2SetPixelShader(struct _ATID3DCNTX *pCtxt, LPD3DHAL_DP2COMMAND pCmd);
HRESULT Rad2Dp2SetPixelShaderConsts(struct _ATID3DCNTX *pCtxt, DWORD StartReg, 
                                    DWORD dwCount, LPDWORD pData);

// PixelShader management for Radeon (R200) (internal use only)

LPRAD2PIXELSHADER Rad2AllocatePixelShader( struct _ATID3DCNTX *pCtxt, DWORD *pdwHandle );
LPRAD2PIXELSHADER Rad2GetPixelShader( struct _ATID3DCNTX *pCtxt, DWORD handle );
void Rad2InitPixelShader( LPRAD2PIXELSHADER lpPShader );
HRESULT Rad2CompilePixelShader( struct _ATID3DCNTX *pCtxt, LPRAD2PIXELSHADER lpPShader,
                                DWORD* pCode, DWORD ByteCodeSize, DWORD lpPSRegAssign[] );
HRESULT Rad2PreProcessPixShader( struct _ATID3DCNTX *pCtxt, DWORD *pCode, DWORD ByteCodeSize, LPRAD2PIXELSHADER lpPS );
HRESULT Rad2PreProcess14PixShader( struct _ATID3DCNTX *pCtxt, DWORD *pCode, DWORD ByteCodeSize, LPRAD2PIXELSHADER lpPS );
PS_RESULT Rad2CompilePixShaderInst( struct _ATID3DCNTX *pCtxt, DWORD *pToken, 
                                    LPRAD2PIXELSHADER lpPS, 
                                    PS_RESULT psLastResult,
                                    LPD3DPSREGISTERS lpD3DPSRegs );
PS_RESULT Rad2CompileBumpmapInst( struct _ATID3DCNTX *pCtxt, 
                                  LPRAD2PIXELSHADER lpPS, 
                                  LPD3DPSREGISTERS  lpD3DPSRegs,
                                  DWORD dwInst, DWORD dwDest, 
                                  DWORD dwSrc0 );
PS_RESULT Rad2CompileTexm3x2Inst( struct _ATID3DCNTX *pCtxt, 
                                  LPRAD2PIXELSHADER lpPS, 
                                  LPD3DPSREGISTERS  lpD3DPSRegs,
                                  DWORD dwInst, DWORD dwDest, 
                                  DWORD dwSrc0, DWORD dwSrc1,
                                  DWORD dwSrc0Row1, 
                                  DWORD dwSrc0Row2);
PS_RESULT Rad2CompileTexm3x3texInst( struct _ATID3DCNTX *pCtxt, 
                                     LPRAD2PIXELSHADER lpPS, 
                                     LPD3DPSREGISTERS  lpD3DPSRegs,
                                     DWORD dwInst, DWORD dwDest, 
                                     DWORD dwSrc0, DWORD dwSrc1,
                                     DWORD dwSrc2, DWORD dwSrc0Row1,
                                     DWORD dwSrc0Row2, DWORD dwSrc0Row3);
PS_RESULT Rad2CompileTexm3x3specInst( struct _ATID3DCNTX *pCtxt, 
                                      LPRAD2PIXELSHADER lpPS, 
                                      LPD3DPSREGISTERS lpD3DPSRegs,
                                      DWORD dwInst, DWORD dwDest, 
                                      DWORD dwSrc0, DWORD dwSrc1,
                                      DWORD dwSrc2, DWORD dwSrc3, 
                                      DWORD dwSrc0Row1, DWORD dwSrc0Row2,
                                      DWORD dwSrc0Row3);
void Rad2RestorePixelShaderConstants(struct _ATID3DCNTX *pCtxt,
                                     DWORD dwShaderHandle);
void Rad2RestorePixelShader(struct _ATID3DCNTX *pCtxt, DWORD dwShaderHandle);
HRESULT Rad2SetLegacyShader(struct _ATID3DCNTX *pCtxt, DWORD *pCode, DWORD dwCodeSize,
                            DWORD dwPSRegAssign[] );
void set_PS_enable( LPRAD2PIXELSHADER lpPS, PS_RESULT type, DWORD dwInstrIndx, BOOL value );
void PS_SetPP_CNTL(struct _ATID3DCNTX *pContext, LPRAD2PIXELSHADER lpPS);
unsigned int getRegFcnIndex( unsigned int arg );
DWORD PS_MapD3DTexRegisterToHW( LPRAD2PIXELSHADER lpPS, LPD3DPSREGISTERS lpD3DPSRegisters, DWORD input );
LPDWORD PS_GetNextInstruction( DWORD* pCode, DWORD ByteCodeSize, DWORD* pCurr );
__inline void ASTexBypassEnable( LPRAD2PIXELSHADER lpPS, DWORD unit );
void LoopbackAddress( LPRAD2PIXELSHADER lpPS, DWORD AS_Unit, DWORD BS_Unit );
void LoopbackValue( LPRAD2PIXELSHADER lpPS, DWORD AS_Unit, DWORD BS_Unit );
void ConvertPSRegAssign(LPRAD2PIXELSHADER lpPS, LPD3DPSREGISTERS lpD3DPSRegs, DWORD dwTexStageToTexReg[]);
void CreateD3DTexRegToHWTexUnitMappingTable( struct _ATID3DCNTX *pCtxt, 
                                             DWORD lpStageToTexRegMap[],
                                             LPD3DPSREGISTERS lpD3DPSregs );
_inline DWORD Rad2FindFreeHWTextureUnit( struct _ATID3DCNTX *pCtxt,
                                         BOOL bTexUnitsAvail[] );

void Rad2ConvertRGBAToR200HW(float* pfData, DWORD dwScale,LPPSRGBACONSTANT lpHWConst);
void Rad2ConvertRGBAToRV250HW(float* pfData, DWORD dwScale,LPPSRGBACONSTANT lpHWConst);

BOOL Rad2RecompilePixelShader( struct _ATID3DCNTX * pCtxt, DWORD dwShaderHandle,
                               LPRAD2PIXELSHADER lpPS);

void set_PS_LastRGBInstruction( LPPSINSTRUCTIONGROUP lpPSInstrGrp );
void set_PS_LastAlphaInstruction( LPPSINSTRUCTIONGROUP lpPSInstrGrp );


void set_PS_Instruction( struct _ATID3DCNTX * pCtxt, 
                         LPRAD2PIXELSHADER lpPS, 
                         LPPSINSTRUCTIONGROUP lpPSInstrGrp, DWORD opType, 
                         PS_BLEND_CNTL psBlendCntl, DWORD dwDestReg, 
                         DWORD dwDestRotate, DWORD dwArgA, DWORD dwArgB,
                         DWORD dwArgC, LPD3DPSREGISTERS lpD3DPSRegs,
                         BOOL bIsLegacyShader );

BOOL PS_OptimizePixelShader( DWORD *pCode,
                             BOOL   bIsLegacyShader );

BOOL PS_OPT_SelectArg( OPOFFSET_TABLE_ENTRY OpOffsetTable[],
                       DWORD *pCode,
                       DWORD  LastValidIndex,
                       BOOL   bIsLegacyShader );

void PS_InitConstUsage(LPPS_CONST_USAGE lppsConstUsage);
void PS_UpdateConstUsage(LPPS_CONST_USAGE lppsConstUsage, DWORD dwRegNum, BOOL bAvail);
PS_CONST_USAGE_RESULT PS_FindConst(LPPS_CONST_USAGE psConstUsage, DWORD dwSrcConst, 
                                   LPDWORD lpRetRegNum);

void PS14_InitConstUsage(PS14_CONST_USAGE ps14ConstUsage[]);
void PS14_UpdateConstUsage(PS14_CONST_USAGE ps14ConstUsage[], DWORD dwRegNum, BOOL bAvail);
PS14_CONST_USAGE_RESULT PS14_FindConst(PS14_CONST_USAGE ps14ConstUsage[], DWORD dwSrcConst, 
                                     LPDWORD lpRetRegNum);

PS_RESULT Rad2CompileTexDP3Inst( struct _ATID3DCNTX * pCtxt, 
                                 LPRAD2PIXELSHADER lpPS, 
                                 LPD3DPSREGISTERS  lpD3DPSRegs,
                                 DWORD dwInst, DWORD dwDest, 
                                 DWORD dwSrc0);

PS_RESULT Rad2CompileTexReg2Lookup( struct _ATID3DCNTX * pCtxt, 
                                    LPRAD2PIXELSHADER lpPS, 
                                    LPD3DPSREGISTERS  lpD3DPSRegs, 
                                    DWORD dwInst, DWORD dwDest, DWORD dwSrc0, 
                                    DWORD dwOutputRotate );

void PS_DisableTxUnit( struct _ATID3DCNTX *  pContext, DWORD unit );

//*****************************************************************************
// Prototypes for Common Utilities (R100 and R200)  (internal use only)
//*****************************************************************************

// Common Utilities (R100 and R200) (internal use only)

HRESULT AtiSetPixelShader(struct _ATID3DCNTX *pContext, LPD3DHAL_DP2COMMAND *lppCmd);
HRESULT AtiSetPixelShaderConst(struct _ATID3DCNTX *pContext, LPD3DHAL_DP2COMMAND *lppCmd);
BOOL PS_isTerminalInstruction( DWORD* pCode, DWORD ByteCodeSize, DWORD* pCurr );
BOOL PS_InitPixelShaderInfoArray( struct _ATID3DCNTX * pCtxt );
BOOL PS_AreTextureCharsEqual( LPTEXTURE_CHARACTERISTICS lpTexChars1, 
                              LPTEXTURE_CHARACTERISTICS lpTexChars2 );

//*****************************************************************************
// typedefs for function pointer tables
//*****************************************************************************

typedef VOID (*BS_COLOR_ARGFUNC) (regPP_PIXSHADER_I0_C0 *reg, unsigned int color_arg_a);
typedef VOID (*BS_COLOR_ARGFUNC2)(regPP_PIXSHADER_I0_C1 *reg, unsigned int color_arg_a);
typedef VOID (*BS_ALPHA_ARGFUNC) (regPP_PIXSHADER_I0_A0 *reg, unsigned int alpha_arg_a);
typedef VOID (*BS_ALPHA_ARGFUNC2)(regPP_PIXSHADER_I0_A1 *reg, unsigned int color_arg_a);
typedef VOID (*AS_COLOR_ARGFUNC) (regPP_ADRSHADER_I0_C0 *reg, unsigned int color_arg_a);
typedef VOID (*AS_COLOR_ARGFUNC2)(regPP_ADRSHADER_I0_C1 *reg, unsigned int color_arg_a);
typedef VOID (*AS_ALPHA_ARGFUNC) (regPP_ADRSHADER_I0_A0 *reg, unsigned int alpha_arg_a);
typedef VOID (*AS_ALPHA_ARGFUNC2)(regPP_ADRSHADER_I0_A1 *reg, unsigned int color_arg_a);


//*****************************************************************************
// inlines
//*****************************************************************************


__inline void set_TxModes( LPRAD2PIXELSHADER lpPS, DWORD unit, E_PS_SHADER_PASS pass, DWORD modes )
{
    HSLASSERT( lpPS != NULL );
    HSLASSERT ( unit < ATI_RAD2_NUM_TEX_UNITS );

    lpPS->TxModes[pass][unit].modes = modes;
    HSLDPF( E_PIXELSHADER_DATA, "set_TxModes: unit:%d  pass:%d  BS_Mode=0x%08lx", 
            unit, pass, modes );

    if ( (pass == PS_ADDRESS_PASS) && (modes & ATI_PS_TXMODE_BYPASS) )
    {
        ASTexBypassEnable( lpPS, unit );     // enable Dest AS unit bypass mode
    }
}

__inline BOOL PS_isTxUnitUsed( LPRAD2PIXELSHADER lpPS, DWORD unit, E_PS_SHADER_PASS pass )
{
    HSLASSERT( lpPS != NULL );
    HSLASSERT ( unit < ATI_RAD2_NUM_TEX_UNITS );

    return (lpPS->TxModes[pass][unit].modes & ATI_PS_TXMODE_ENABLE) == ATI_PS_TXMODE_ENABLE;    
}

__inline BOOL PS_isTxUnitBypass( LPRAD2PIXELSHADER lpPS, DWORD unit, E_PS_SHADER_PASS pass  )
{
    HSLASSERT( lpPS != NULL );
    HSLASSERT ( unit < ATI_RAD2_NUM_TEX_UNITS );

    return (lpPS->TxModes[pass][unit].modes & ATI_PS_TXMODE_BYPASS) == ATI_PS_TXMODE_BYPASS;
}

__inline BOOL PS_isTxUnitTexKillBS( LPRAD2PIXELSHADER lpPS, DWORD unit )
{
    HSLASSERT( lpPS != NULL );
    HSLASSERT ( unit < ATI_RAD2_NUM_TEX_UNITS );
    
    return (lpPS->TxModes[PS_BLENDING_PASS][unit].modes & ATI_PS_TXMODE_TEXKILL) == ATI_PS_TXMODE_TEXKILL;
}

__inline BOOL PS_isTxUnitTexCoordTypeFVF( LPRAD2PIXELSHADER lpPS, DWORD unit, E_PS_SHADER_PASS pass )
{
    HSLASSERT( lpPS != NULL );
    HSLASSERT ( unit < ATI_RAD2_NUM_TEX_UNITS );

    return (lpPS->TxModes[pass][unit].modes & ATI_PS_TXMODE_COORDTYPE_FVF) == ATI_PS_TXMODE_COORDTYPE_FVF;
}

__inline E_TEXCOORD_TYPE PS_getForcedTexCoordtype( LPRAD2PIXELSHADER lpPS, DWORD unit, E_PS_SHADER_PASS pass )
{
    HSLASSERT( lpPS != NULL );
    HSLASSERT ( unit < ATI_RAD2_NUM_TEX_UNITS );

    HSLASSERT( lpPS->TxModes[pass][unit].modes & ATI_PS_TXMODE_COORDTYPE_FORCE );

    return (lpPS->TxModes[pass][unit].modes & ATI_PS_TXMODE_COORDTYPE_MASK) >> ATI_PS_TXMODE_COORDTYPE_SHIFT;
}

__inline BOOL PS_isForcedTexCoordtype( LPRAD2PIXELSHADER lpPS, DWORD unit, E_PS_SHADER_PASS pass )
{
    HSLASSERT( lpPS != NULL );
    HSLASSERT ( unit < ATI_RAD2_NUM_TEX_UNITS );

    return ( lpPS->TxModes[pass][unit].modes & ATI_PS_TXMODE_COORDTYPE_FORCE ) == ATI_PS_TXMODE_COORDTYPE_FORCE;
}

__inline BOOL PS_isTxUnitTexCoordTypeLoopBack( LPRAD2PIXELSHADER lpPS, DWORD unit, E_PS_SHADER_PASS pass )
{
    HSLASSERT( lpPS != NULL );
    HSLASSERT( unit < ATI_RAD2_NUM_TEX_UNITS );

    return ( pass == PS_BLENDING_PASS && (lpPS->TxModes[pass][unit].modes & ATI_PS_TXMODE_COORDTYPE_LOOPBACK) );
}

__inline BOOL PS_isTextureMapSampled( LPRAD2PIXELSHADER lpPS, DWORD unit )
{
    // for both the AS and BS, a texture unit will sample the texture map if it is not
    // in BYPASS or TEXKILL modes.  We return true if the the unit is sampling the texture
    // map in either the AS or BS.

    // To determine if the unit is sampling a texture, we determine that the unit is not in BYPASS,
    // TEXKILL, or EYE modes, AND that the texture unit is ENABLED.
    BOOL bSampleAS = ( (lpPS->TxModes[PS_ADDRESS_PASS][unit].modes & ( ATI_PS_TXMODE_TEXKILL | ATI_PS_TXMODE_BYPASS )) == 0) &&
                     ( PS_isTxUnitUsed(lpPS, unit, PS_ADDRESS_PASS ) );
    BOOL bSampleBS = ( (lpPS->TxModes[PS_BLENDING_PASS][unit].modes & ( ATI_PS_TXMODE_TEXKILL | ATI_PS_TXMODE_BYPASS )) == 0 ) &&
                     ( PS_isTxUnitUsed(lpPS, unit, PS_BLENDING_PASS ) );

    HSLASSERT( lpPS != NULL );
    HSLASSERT ( unit < ATI_RAD2_NUM_TEX_UNITS );
    return (bSampleAS || bSampleBS);
}

__inline PS_RESULT PS_GetOpType( DWORD dwInst, DWORD dwDest )
{
    DWORD dwOpCode = D3DSI_GETOPCODE(dwInst);
    PS_RESULT psResult = PS_RESULT_NONE;
    
    // Determine if the instruction has any output at all...
#if ( DIRECT3D_VERSION >= 0x0810 )
    if ( dwOpCode == D3DSIO_PHASE || dwOpCode == D3DSIO_NOP )
#else
    if ( dwOpCode == D3DSIO_NOP )
#endif
    {
        return PS_RESULT_NONE;
    }

    // Now Determine what its color channel output is...
    if ( dwOpCode == D3DSIO_DP3 || dwOpCode == D3DSIO_DP4 )
    {
        // DP3/4's always require the RGB Channel
        psResult = PS_RBG_INSTRUCTION;
    }
    else if ( D3DSI_GETWRITEMASK(dwDest) & ( D3DSP_WRITEMASK_0 | D3DSP_WRITEMASK_1 | D3DSP_WRITEMASK_2 ) )
    {
        psResult = PS_RBG_INSTRUCTION;
    }

    // Finally determine if it is outputing on the alpha channel....
    if ( D3DSI_GETWRITEMASK(dwDest) & (D3DSP_WRITEMASK_3) )
    {
        psResult |= PS_ALPHA_INSTRUCTION;
    }
    
    // By the time we get here, we should have some kind of an output 
    // (RGB, A, or RGBA).  If we don't then something is wrong
    HSLASSERT(psResult != PS_RESULT_NONE);

    return psResult;
}

__inline BOOL PS_SupportedConstMod( DWORD dwConstMods )
{
    if ( (dwConstMods == D3DSPSM_BIAS) || (dwConstMods == D3DSPSM_BIASNEG) ||
         (dwConstMods == D3DSPSM_SIGN) || (dwConstMods == D3DSPSM_SIGNNEG) ||
         (dwConstMods == D3DSPSM_X2)   || (dwConstMods == D3DSPSM_X2NEG) )
    {
        return FALSE;
    }

    return TRUE;
}

__inline BOOL PS_IsProgramableConst(DWORD dwSrc)
{
    DWORD dwRegNum = dwSrc & D3DSP_REGNUM_MASK;

    HSLASSERT( ATI_PS_LUMSCALE_REGNUM  == ATI_PS_ROTMAT0_REGNUM );
    HSLASSERT( ATI_PS_LUMOFFSET_REGNUM == ATI_PS_ROTMAT1_REGNUM );

    if ( (D3DSI_GETREGTYPE(dwSrc)) == D3DSPR_CONST &&
         dwRegNum != ATI_PS_BLACK_REGNUM &&
         dwRegNum != ATI_PS_ZERO_REGNUM &&
         dwRegNum != ATI_PS_ROTMAT0_REGNUM &&
         dwRegNum != ATI_PS_ROTMAT1_REGNUM &&
         dwRegNum != ATI_PS_MINUSONE_REGNUM )
    {
        return TRUE;
    }
    
    return FALSE;
}

__inline void PS_initSeqState( LPRAD2PIXELSHADER lpPS )
{
   ZeroMemory( &lpPS->seqState, sizeof(PSTEXSEQSTATE) );
}

__inline DWORD PS_GetBlendInstr_Count( LPRAD2PIXELSHADER lpPS )
{
    return lpPS->dwInstrCount[PS_BLENDING_PASS];
}

__inline void PS_SetBlendInstr_Count( LPRAD2PIXELSHADER lpPS, DWORD value )
{
    lpPS->dwInstrCount[PS_BLENDING_PASS] = value;
}

__inline DWORD PS_GetAddrInstr_Count( LPRAD2PIXELSHADER lpPS )
{
    return lpPS->dwInstrCount[PS_ADDRESS_PASS];
}

__inline void PS_SetAddrInstr_Count( LPRAD2PIXELSHADER lpPS, DWORD value )
{
    lpPS->dwInstrCount[PS_ADDRESS_PASS] = value;
}

__inline DWORD PS_GetCurrentInstr_Count( LPRAD2PIXELSHADER lpPS )
{
    return lpPS->dwInstrCount[lpPS->iState.eCurrPhase];
}

__inline LPPSINSTRUCTIONGROUP PS_GetBlendInstr( LPRAD2PIXELSHADER lpPS, DWORD index )
{
    return &lpPS->psInstructions[PS_BLENDING_PASS][index];
}

__inline LPPSINSTRUCTIONGROUP PS_GetAddrInstr( LPRAD2PIXELSHADER lpPS, DWORD index )
{
    return &lpPS->psInstructions[PS_ADDRESS_PASS][index];
}

// Instruction Compilation Macros...

__inline void PS_Compile_MOV( struct _ATID3DCNTX * pCtxt, 
                              LPRAD2PIXELSHADER lpPS, E_PS_SHADER_PASS ePass, 
                              PS_RESULT opType, DWORD dwDest, 
                              DWORD dwDestRotate, DWORD dwSrc, 
                              LPD3DPSREGISTERS lpD3DPSRegs )
{
    set_PS_enable   ( lpPS, ePass, lpPS->dwInstrCount[ePass], TRUE );                   
    set_PS_Instruction(pCtxt, lpPS, &(lpPS->psInstructions[ePass][lpPS->dwInstrCount[ePass]]),
                        opType, PSBLEND_ADD,
                        dwDest, dwDestRotate,               // Dest Reg
                        PS_ONE,                             // ArgA = 1.0
                        dwSrc,                              // ArgB = src0
                        PS_ZERO,                            // ArgC = 0.0
                        lpD3DPSRegs,
                        lpPS->bPixelShaderIsLegacy); 

    lpPS->dwInstrCount[ePass]++;                          // consume the slot
}

__inline void PS_Compile_ADD(struct _ATID3DCNTX * pCtxt, 
                              LPRAD2PIXELSHADER lpPS, E_PS_SHADER_PASS ePass, 
                              PS_RESULT opType, DWORD dwDest, 
                              DWORD dwDestRotate, DWORD dwSrc0, DWORD dwSrc1, 
                              LPD3DPSREGISTERS lpD3DPSRegs )
{
    set_PS_enable   ( lpPS, ePass, lpPS->dwInstrCount[ePass], TRUE );
    set_PS_Instruction( pCtxt,lpPS, &(lpPS->psInstructions[ePass][lpPS->dwInstrCount[ePass]]),
                        opType, PSBLEND_ADD,
                        dwDest, dwDestRotate,               // Dest Reg
                        PS_ONE,                             // ArgA = 1.0
                        dwSrc1,                             // ArgB = src1
                        dwSrc0,                             // ArgC = src0
                        lpD3DPSRegs,
                        lpPS->bPixelShaderIsLegacy ); 

    lpPS->dwInstrCount[ePass]++;                          // consume the slot
}

__inline void PS_Compile_SUB( struct _ATID3DCNTX * pCtxt, 
                              LPRAD2PIXELSHADER lpPS, E_PS_SHADER_PASS ePass, 
                              PS_RESULT opType, DWORD dwDest, 
                              DWORD dwDestRotate, DWORD dwSrc0, DWORD dwSrc1, 
                              LPD3DPSREGISTERS lpD3DPSRegs )
{
    set_PS_enable   ( lpPS, ePass, lpPS->dwInstrCount[ePass], TRUE );
    set_PS_Instruction( pCtxt, lpPS, &(lpPS->psInstructions[ePass][lpPS->dwInstrCount[ePass]]),
                        opType, PSBLEND_ADD,
                        dwDest, dwDestRotate,               // Dest Reg
                        PS_MINUS_ONE,                       // ArgA = -1.0
                        dwSrc1,                             // ArgB = src1
                        dwSrc0,                             // ArgC = src0
                        lpD3DPSRegs,
                        lpPS->bPixelShaderIsLegacy ); 

    lpPS->dwInstrCount[ePass]++;                                        // consume the slot
}

__inline void PS_Compile_MUL( struct _ATID3DCNTX * pCtxt, 
                              LPRAD2PIXELSHADER lpPS, E_PS_SHADER_PASS ePass, 
                              PS_RESULT opType, DWORD dwDest, 
                              DWORD dwDestRotate, DWORD dwSrc0, DWORD dwSrc1, 
                              LPD3DPSREGISTERS lpD3DPSRegs )
{
    set_PS_enable   ( lpPS, ePass, lpPS->dwInstrCount[ePass], TRUE );
    set_PS_Instruction( pCtxt, lpPS, &(lpPS->psInstructions[ePass][lpPS->dwInstrCount[ePass]]),
                        opType, PSBLEND_ADD,
                        dwDest, dwDestRotate,            // Dest Reg
                        dwSrc0,                             // ArgA = src0
                        dwSrc1,                             // ArgB = src1
                        PS_ZERO,                            // ArgC = 0.0
                        lpD3DPSRegs,
                        lpPS->bPixelShaderIsLegacy ); 

    lpPS->dwInstrCount[ePass]++;                                        // consume the slot
}

__inline void PS_Compile_MAD( struct _ATID3DCNTX * pCtxt, 
                              LPRAD2PIXELSHADER lpPS, E_PS_SHADER_PASS ePass, 
                              PS_RESULT opType, DWORD dwDest,
                              DWORD dwDestRotate, DWORD dwSrc0, DWORD dwSrc1,
                              DWORD dwSrc2, LPD3DPSREGISTERS lpD3DPSRegs )
{
    set_PS_enable   ( lpPS, ePass, lpPS->dwInstrCount[ePass], TRUE );
    set_PS_Instruction( pCtxt, lpPS, &(lpPS->psInstructions[ePass][lpPS->dwInstrCount[ePass]]),
                        opType, PSBLEND_ADD,
                        dwDest, dwDestRotate,               // Dest Reg
                        dwSrc0,                             // ArgA = src0
                        dwSrc1,                             // ArgB = src1
                        dwSrc2,                             // ArgC = src2
                        lpD3DPSRegs,
                        lpPS->bPixelShaderIsLegacy ); 

    lpPS->dwInstrCount[ePass]++;                                        // consume the slot
}

__inline void PS_Compile_LRP( struct _ATID3DCNTX * pCtxt, 
                              LPRAD2PIXELSHADER lpPS, E_PS_SHADER_PASS ePass, 
                              PS_RESULT opType, DWORD dwDest,
                              DWORD dwDestRotate, DWORD dwSrc0, DWORD dwSrc1,
                              DWORD dwSrc2, LPD3DPSREGISTERS lpD3DPSRegs )
{
    set_PS_enable   ( lpPS, ePass, lpPS->dwInstrCount[ePass], TRUE );
    set_PS_Instruction( pCtxt, lpPS, &(lpPS->psInstructions[ePass][lpPS->dwInstrCount[ePass]]),
                        opType, PSBLEND_LERP,
                        dwDest, dwDestRotate,               // Dest Reg 
                        dwSrc2,                             // ArgA = src2
                        dwSrc1,                             // ArgB = src1
                        dwSrc0,                             // ArgC = src0
                        lpD3DPSRegs,
                        lpPS->bPixelShaderIsLegacy ); 

    lpPS->dwInstrCount[ePass]++;                                        // consume the slot
}

__inline void PS_Compile_DOT2ADD( struct _ATID3DCNTX * pCtxt, 
                                  LPRAD2PIXELSHADER lpPS, E_PS_SHADER_PASS ePass, 
                                  PS_RESULT opType, DWORD dwDest,
                                  DWORD dwDestRotate, DWORD dwSrc0, DWORD dwSrc1,
                                  DWORD dwSrc2, LPD3DPSREGISTERS lpD3DPSRegs)
{
    set_PS_enable  ( lpPS, ePass, lpPS->dwInstrCount[ePass], TRUE );              // enable instruction
    set_PS_Instruction( pCtxt, lpPS, &(lpPS->psInstructions[ePass][lpPS->dwInstrCount[ePass]]),
                        opType, PSBLEND_DOT2ADD,
                        dwDest, dwDestRotate,                   // DestReg
                        dwSrc0,                                 // ArgA = src0
                        dwSrc1,                                 // ArgB = src1
                        dwSrc2,                                 // ArgC = src2
                        lpD3DPSRegs,
                        lpPS->bPixelShaderIsLegacy );

    lpPS->dwInstrCount[ePass]++;                                        // consume the slot
}

__inline void PS_Compile_DP3( struct _ATID3DCNTX * pCtxt, 
                              LPRAD2PIXELSHADER lpPS, E_PS_SHADER_PASS ePass, 
                              PS_RESULT opType, DWORD dwDest,
                              DWORD dwDestRotate, DWORD dwSrc0, DWORD dwSrc1,
                              LPD3DPSREGISTERS lpD3DPSRegs )
{
    set_PS_enable   ( lpPS, ePass, lpPS->dwInstrCount[ePass], TRUE );               // enable instruction
    set_PS_Instruction( pCtxt, lpPS, &(lpPS->psInstructions[ePass][lpPS->dwInstrCount[ePass]]),
                        opType, PSBLEND_DOT3,
                        dwDest, dwDestRotate,               // Dest Reg and No Swizzle
                        dwSrc0,                             // ArgA = src0
                        dwSrc1,                             // ArgB = src1
                        PS_NONE,                            // ArgC = none
                        lpD3DPSRegs,
                        lpPS->bPixelShaderIsLegacy ); 

    lpPS->dwInstrCount[ePass]++;                                        // consume the BS slot
}

__inline void PS_Compile_DP4( struct _ATID3DCNTX * pCtxt, 
                              LPRAD2PIXELSHADER lpPS, E_PS_SHADER_PASS ePass, 
                              PS_RESULT opType, DWORD dwDest,
                              DWORD dwDestRotate, DWORD dwSrc0, DWORD dwSrc1,
                              LPD3DPSREGISTERS lpD3DPSRegs )
{
    set_PS_enable   ( lpPS, ePass, lpPS->dwInstrCount[ePass], TRUE );               // enable instruction
    set_PS_Instruction( pCtxt, lpPS, &(lpPS->psInstructions[ePass][lpPS->dwInstrCount[ePass]]),
                        opType, PSBLEND_DOT4,
                        dwDest, dwDestRotate,               // Dest Reg and No Swizzle
                        dwSrc0,                             // ArgA = src0
                        dwSrc1,                             // ArgB = src1
                        PS_NONE,                            // ArgC = none
                        lpD3DPSRegs,
                        lpPS->bPixelShaderIsLegacy ); 

    lpPS->dwInstrCount[ePass]++;                                        // consume the BS slot
}

__inline void PS_Compile_CND( struct _ATID3DCNTX * pCtxt, 
                              LPRAD2PIXELSHADER lpPS, E_PS_SHADER_PASS ePass, 
                              PS_RESULT opType, DWORD dwDest,
                              DWORD dwDestRotate, DWORD dwSrc0, DWORD dwSrc1,
                              DWORD dwSrc2, LPD3DPSREGISTERS lpD3DPSRegs )
{
    set_PS_enable   ( lpPS, ePass, lpPS->dwInstrCount[ePass], TRUE );
    set_PS_Instruction( pCtxt, lpPS, &(lpPS->psInstructions[ePass][lpPS->dwInstrCount[ePass]]),
                        opType, PSBLEND_CND,
                        dwDest, dwDestRotate,               // Dest Reg and No Swizzle
                        dwSrc1,                             // ArgA = src1
                        dwSrc2,                             // ArgB = src2
                        dwSrc0,                             // ArgC = src0
                        lpD3DPSRegs,
                        lpPS->bPixelShaderIsLegacy );
    lpPS->dwInstrCount[ePass]++;                                        // consume the BS slot
}

__inline void PS_Compile_CMP( struct _ATID3DCNTX * pCtxt, 
                              LPRAD2PIXELSHADER lpPS, E_PS_SHADER_PASS ePass, 
                              PS_RESULT opType, DWORD dwDest,
                              DWORD dwDestRotate, DWORD dwSrc0, DWORD dwSrc1,
                              DWORD dwSrc2, LPD3DPSREGISTERS lpD3DPSRegs )
{
    set_PS_enable   ( lpPS, ePass, lpPS->dwInstrCount[ePass], TRUE );
    set_PS_Instruction( pCtxt, lpPS, &(lpPS->psInstructions[ePass][lpPS->dwInstrCount[ePass]]),
                        opType, PSBLEND_CND0,
                        dwDest, dwDestRotate,               // Dest Reg and No Swizzle
                        dwSrc1,                             // ArgA = src1
                        dwSrc2,                             // ArgB = src2
                        dwSrc0,                             // ArgC = src0
                        lpD3DPSRegs,
                        lpPS->bPixelShaderIsLegacy );
    lpPS->dwInstrCount[ePass]++;                                        // consume the BS slot
}

__inline BOOL PS_IsDiffuseUsed( LPRAD2PIXELSHADER lpPS )
{
    return ( (lpPS->dwDiffSpecUsage & 0xFFFF) != 0 );
}

__inline BOOL PS_IsSpecularUsed( LPRAD2PIXELSHADER lpPS )
{
    return ( (lpPS->dwDiffSpecUsage & 0xFFFF0000) != 0 );
}

__inline void PS_SetColorInstrDiffuseUse( LPRAD2PIXELSHADER lpPS, DWORD dwInstr )
{
    lpPS->dwDiffSpecUsage |= 1 << ( ATI_PS_COLOR_DIFFUSE_USE_SHIFT + dwInstr );
}

__inline void PS_SetColorInstrSpecularUse( LPRAD2PIXELSHADER lpPS, DWORD dwInstr )
{
    lpPS->dwDiffSpecUsage |= 1 << ( ATI_PS_COLOR_SPECULAR_USE_SHIFT + dwInstr );
}

__inline void PS_SetAlphaInstrDiffuseUse( LPRAD2PIXELSHADER lpPS, DWORD dwInstr )
{
    lpPS->dwDiffSpecUsage |= 1 << ( ATI_PS_ALPHA_DIFFUSE_USE_SHIFT + dwInstr );
}

__inline void PS_SetAlphaInstrSpecularUse( LPRAD2PIXELSHADER lpPS, DWORD dwInstr )
{
    lpPS->dwDiffSpecUsage |= 1 << ( ATI_PS_ALPHA_SPECULAR_USE_SHIFT + dwInstr );
}

__inline BOOL PS_IsColorInstrDiffuseUsed( LPRAD2PIXELSHADER lpPS, DWORD dwInstr )
{
    return ((lpPS->dwDiffSpecUsage & (1 << ( ATI_PS_COLOR_DIFFUSE_USE_SHIFT + dwInstr ))) != 0);
}

__inline BOOL PS_IsColorInstrSpecularUsed( LPRAD2PIXELSHADER lpPS, DWORD dwInstr )
{
    return ((lpPS->dwDiffSpecUsage & (1 << ( ATI_PS_COLOR_SPECULAR_USE_SHIFT + dwInstr ))) != 0);
}

__inline BOOL PS_IsAlphaInstrDiffuseUsed( LPRAD2PIXELSHADER lpPS, DWORD dwInstr )
{
    return ((lpPS->dwDiffSpecUsage & (1 << ( ATI_PS_ALPHA_DIFFUSE_USE_SHIFT + dwInstr ))) != 0);
}

__inline BOOL PS_IsAlphaInstrSpecularUsed( LPRAD2PIXELSHADER lpPS, DWORD dwInstr )
{
    return ((lpPS->dwDiffSpecUsage & (1 << ( ATI_PS_ALPHA_SPECULAR_USE_SHIFT + dwInstr ))) != 0);
}

__inline void PS_SetColorArgumentOverride( LPRAD2PIXELSHADER lpPS, DWORD dwInstr, 
                                           DWORD dwInput, DWORD dwDiffOverride,
                                           DWORD dwArgMask )
{
    switch (dwInput)
    {
        case E_PS_INPUT_COLOR_DIFFUSE_COLOR:
        case E_PS_INPUT_COLOR_DIFFUSE_ALPHA:
            lpPS->dwColorInstrDiffuseOverride[dwInstr] |= dwDiffOverride;
            lpPS->dwColorInstrDiffuseMask[dwInstr] |= dwArgMask;
            PS_SetColorInstrDiffuseUse(lpPS, dwInstr);
            break;

        case E_PS_INPUT_COLOR_SPECULAR_COLOR:
        case E_PS_INPUT_COLOR_SPECULAR_ALPHA:
            lpPS->dwColorInstrSpecularMask[dwInstr] |= dwArgMask;
            PS_SetColorInstrSpecularUse(lpPS, dwInstr);
            break;
    }
}

__inline void PS_SetAlphaArgumentOverride( LPRAD2PIXELSHADER lpPS, DWORD dwInstr, 
                                           DWORD dwInput, DWORD dwDiffOverride, 
                                           DWORD dwArgMask )
{
    switch (dwInput)
    {
        case E_PS_INPUT_ALPHA_DIFFUSE_ALPHA:
        case E_PS_INPUT_ALPHA_DIFFUSE_BLUE:
            lpPS->dwAlphaInstrDiffuseOverride[dwInstr] |= dwDiffOverride;
            lpPS->dwAlphaInstrDiffuseMask[dwInstr] |= dwArgMask;
            PS_SetAlphaInstrDiffuseUse(lpPS, dwInstr);
            break;

        case E_PS_INPUT_ALPHA_SPECULAR_ALPHA:
        case E_PS_INPUT_ALPHA_SPECULAR_BLUE:
            lpPS->dwAlphaInstrSpecularMask[dwInstr] |= dwArgMask;
            PS_SetAlphaInstrSpecularUse(lpPS, dwInstr);
            break;
    }
}

__inline void PS_ChangeDiffuseUse( LPRAD2PIXELSHADER lpPS )
{
    DWORD dwInstr;
    DWORD dwTempDiff = 0;

    LPPSINSTRUCTIONGROUP lpPSInstrGrp = NULL;

    BOOL bModifiedDiff = FALSE;

    // Loop through all the instructions used by this Pixel Shader and
    // change any use of Diffuse (on the color or alpha channels) to white
    for (dwInstr=0; dwInstr < PS_GetBlendInstr_Count(lpPS); dwInstr++)
    {
        lpPSInstrGrp = &lpPS->psInstructions[PS_BLENDING_PASS][dwInstr];

        if ( PS_IsColorInstrDiffuseUsed(lpPS, dwInstr) )
        {
            // Grab the orriginal values that we are going to overwrite.
            dwTempDiff = lpPSInstrGrp->C0 & lpPS->dwColorInstrDiffuseMask[dwInstr];

            // Clear the orriginal values to make room for the new values.
            lpPSInstrGrp->C0 &= ~(lpPS->dwColorInstrDiffuseMask[dwInstr]);

            // Store the new values in the register
            lpPSInstrGrp->C0 |= lpPS->dwColorInstrDiffuseOverride[dwInstr];

            // Save the orriginal value in case we need to restore it if 
            // Diffuse becomes available in the vertex data
            lpPS->dwColorInstrDiffuseOverride[dwInstr] = dwTempDiff;

            bModifiedDiff = TRUE;
        }

        if ( PS_IsAlphaInstrDiffuseUsed(lpPS, dwInstr ) )
        {
            // Grab the orriginal values that we are going to overwrite
            dwTempDiff = lpPSInstrGrp->A0 & lpPS->dwAlphaInstrDiffuseMask[dwInstr];

            // Clear the orriginal values to make room for the new values.
            lpPSInstrGrp->A0 &= ~(lpPS->dwAlphaInstrDiffuseMask[dwInstr]);

            // Store the new values in the register.
            lpPSInstrGrp->A0 |= lpPS->dwAlphaInstrDiffuseOverride[dwInstr];

            // Save the orriginal value in case we need to restore it if
            // Diffuse becomes available in the vertex data
            lpPS->dwAlphaInstrDiffuseOverride[dwInstr] = dwTempDiff;

            bModifiedDiff = TRUE;
        }
    }

    if( bModifiedDiff )
    {
        lpPS->bPSModifiedForMissingDiffuse = !(lpPS->bPSModifiedForMissingDiffuse);
    }
}

__inline void PS_ChangeSpecularUse( LPRAD2PIXELSHADER lpPS )
{
    DWORD dwInstr;
    DWORD dwTempSpec = 0;

    LPPSINSTRUCTIONGROUP lpPSInstrGrp = NULL;

    BOOL bModifiedSpec = FALSE;

    // Loop through all the instructions used by this Pixel Shader and
    // change any use of Specular (on the color or alpha channels) to black
    for (dwInstr=0; dwInstr < PS_GetBlendInstr_Count(lpPS); dwInstr++)
    {
        lpPSInstrGrp = &lpPS->psInstructions[PS_BLENDING_PASS][dwInstr];

        if ( PS_IsColorInstrSpecularUsed(lpPS, dwInstr) )
        {
            // Grab the orriginal values that we are going to overwrite.
            dwTempSpec = lpPSInstrGrp->C0 & lpPS->dwColorInstrSpecularMask[dwInstr];

            // Clear the orriginal values to make room for the new values.
            lpPSInstrGrp->C0 &= ~(lpPS->dwColorInstrSpecularMask[dwInstr]);

            // Store the new values in the register
            lpPSInstrGrp->C0 |= lpPS->dwColorInstrSpecularOverride[dwInstr];

            // Save the orriginal value in case we need to restore it if 
            // Specular becomes available in the vertex data
            lpPS->dwColorInstrSpecularOverride[dwInstr] = dwTempSpec;

            bModifiedSpec = TRUE;
        }

        if ( PS_IsAlphaInstrSpecularUsed(lpPS, dwInstr ) )
        {
            // Grab the orriginal values that we are going to overwrite
            dwTempSpec = lpPSInstrGrp->A0 & lpPS->dwAlphaInstrSpecularMask[dwInstr];

            // Clear the orriginal values to make room for the new values.
            lpPSInstrGrp->A0 &= ~(lpPS->dwAlphaInstrSpecularMask[dwInstr]);

            // Store the new values in the register.
            lpPSInstrGrp->A0 |= lpPS->dwAlphaInstrSpecularOverride[dwInstr];

            // Save the orriginal value in case we need to restore it if
            // Specular becomes available in the vertex data
            lpPS->dwAlphaInstrSpecularOverride[dwInstr] = dwTempSpec;

            bModifiedSpec = TRUE;
        }
    }

    if( bModifiedSpec )
    {
        lpPS->bPSModifiedForMissingSpecular = !(lpPS->bPSModifiedForMissingSpecular);
    }
}

#endif // _PIXELSHADER_H__



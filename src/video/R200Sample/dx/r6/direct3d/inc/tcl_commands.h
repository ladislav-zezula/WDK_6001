

//    
//  $Workfile: tcl_commands.h $
//  $Revision: $
//
//  Description:
//
//  Last modification: 
//     $Author: $ 
//     $Date: $
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _TCL_COMMANDS_H__
#define _TCL_COMMANDS_H__

#include "radeon.h"
#include "d3d_hw_enum.h"
#include "tplates.h"
#include "tcl_math.h"
#include "tclTypes.h"

// CHAPLIN_TODO: Resolve Rage 6 and Chaplin TCL command differences

////////////////////////////////////////////////////////////////////////
// Extern Globals
////////////////////////////////////////////////////////////////////////
// CHAPLIN_TODO: Is there a better way that will eliminate the (constant) global
extern TclVecScaStrOff g_Rad2TclStrideOffset;

/////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////
// Note the ATIMATRIX struct has a dwFlags member at the end that we don't want to
// send to the hardware. As a result we have a definition for the "correct" length.
// The length is in DWORDS.
#define ATIMATRIX_CMD_LENGTH (sizeof(ATIMATRIX_cmd) >> 2) - 1  // length in DWORDS

// Back face culling defines.
// These defines are used whether or not TCL is on.
#define ATI_TCL_CULL_MASK ( SE_TCL_UCP_VTX_BLEND_CNTL__CULLING_FF_DIR | \
                            SE_TCL_UCP_VTX_BLEND_CNTL__CULL_FF_ENA    | \
                            SE_TCL_UCP_VTX_BLEND_CNTL__CULL_BF_ENA      )

#define ATI_TCL_CULLNONE  (0ul)

#define ATI_TCL_CULLCW    ( SE_TCL_UCP_VTX_BLEND_CNTL__CULLING_FF_DIR | \
                            SE_TCL_UCP_VTX_BLEND_CNTL__CULL_BF_ENA      )

#define ATI_TCL_CULLCCW   ( SE_TCL_UCP_VTX_BLEND_CNTL__CULL_BF_ENA      )



#define ATI_RAS_CULL_MASK ( SE_CNTL__FFACE_CULL_DIR__CCW  | \
                            SE_CNTL__BFACE_CULL_FCN__DRAW | \
                            SE_CNTL__FFACE_CULL_FCN__DRAW   )

#define ATI_RAS_CULLNONE  ( SE_CNTL__BFACE_CULL_FCN__DRAW | \
                            SE_CNTL__FFACE_CULL_FCN__DRAW   )

#define ATI_RAS_CULLCW    ( SE_CNTL__FFACE_CULL_DIR__CCW  | \
                            SE_CNTL__FFACE_CULL_FCN__DRAW   )

#define ATI_RAS_CULLCCW   ( SE_CNTL__FFACE_CULL_FCN__DRAW   )


/////////////////////////////////////////////////////////////////////////////
// Radeon 2 (Chaplin) offsets and strides
/////////////////////////////////////////////////////////////////////////////
// Vector Offsets, Strides are in OCTWORDS
#define RAD2_TCL_VEC_MATRIX00_OFFSET             0x0080
#define RAD2_TCL_VEC_MATRIX01_OFFSET             0x0084
#define RAD2_TCL_VEC_MATRIX02_OFFSET             0x0088
#define RAD2_TCL_VEC_MATRIX03_OFFSET             0x008C
#define RAD2_TCL_VEC_MATRIX04_OFFSET             0x0090
#define RAD2_TCL_VEC_MATRIX05_OFFSET             0x0094
#define RAD2_TCL_VEC_MATRIX06_OFFSET             0x0098
#define RAD2_TCL_VEC_MATRIX07_OFFSET             0x009C
#define RAD2_TCL_VEC_MATRIX08_OFFSET             0x00A0
#define RAD2_TCL_VEC_MATRIX09_OFFSET             0x00A4
#define RAD2_TCL_VEC_MATRIX10_OFFSET             0x00A8
#define RAD2_TCL_VEC_MATRIX11_OFFSET             0x00AC
#define RAD2_TCL_VEC_MATRIX12_OFFSET             0x0000
#define RAD2_TCL_VEC_MATRIX13_OFFSET             0x0004
#define RAD2_TCL_VEC_MATRIX14_OFFSET             0x0008
#define RAD2_TCL_VEC_MATRIX15_OFFSET             0x000C
#define RAD2_TCL_VEC_MATRIX16_OFFSET             0x0010
#define RAD2_TCL_VEC_MATRIX17_OFFSET             0x0014
#define RAD2_TCL_VEC_MATRIX18_OFFSET             0x0018
#define RAD2_TCL_VEC_MATRIX19_OFFSET             0x001C
#define RAD2_TCL_VEC_MATRIX20_OFFSET             0x0020
#define RAD2_TCL_VEC_MATRIX21_OFFSET             0x0024

#define RAD2_TCL_VEC_LIGHT0_COLOR_OFFSET         0x0028
#define RAD2_TCL_VEC_LIGHT1_COLOR_OFFSET         0x0029
#define RAD2_TCL_VEC_LIGHT2_COLOR_OFFSET         0x002A
#define RAD2_TCL_VEC_LIGHT3_COLOR_OFFSET         0x002B
#define RAD2_TCL_VEC_LIGHT4_COLOR_OFFSET         0x002C
#define RAD2_TCL_VEC_LIGHT5_COLOR_OFFSET         0x002D
#define RAD2_TCL_VEC_LIGHT6_COLOR_OFFSET         0x002E
#define RAD2_TCL_VEC_LIGHT7_COLOR_OFFSET         0x002F

#define RAD2_TCL_VEC_LIGHT0_POSITION_OFFSET      0x0040
#define RAD2_TCL_VEC_LIGHT1_POSITION_OFFSET      0x0041
#define RAD2_TCL_VEC_LIGHT2_POSITION_OFFSET      0x0042
#define RAD2_TCL_VEC_LIGHT3_POSITION_OFFSET      0x0043
#define RAD2_TCL_VEC_LIGHT4_POSITION_OFFSET      0x0044
#define RAD2_TCL_VEC_LIGHT5_POSITION_OFFSET      0x0045
#define RAD2_TCL_VEC_LIGHT6_POSITION_OFFSET      0x0046
#define RAD2_TCL_VEC_LIGHT7_POSITION_OFFSET      0x0047

#define RAD2_TCL_VEC_PROJ_MATRIX_OFFSET          0x00B8

#define RAD2_TCL_VEC_GLOBAL_AMBIENT_OFFSET       0x005C
#define RAD2_TCL_VEC_FOG_PARAMETERS_OFFSET       0x005D
#define RAD2_TCL_VEC_EYE_OFFSET                  0x005E

#define RAD2_TCL_VEC_UCP0_OFFSET                 0x0060
#define RAD2_TCL_VEC_UCP1_OFFSET                 0x0061
#define RAD2_TCL_VEC_UCP2_OFFSET                 0x0062
#define RAD2_TCL_VEC_UCP3_OFFSET                 0x0063
#define RAD2_TCL_VEC_UCP4_OFFSET                 0x0064
#define RAD2_TCL_VEC_UCP5_OFFSET                 0x0065

#define RAD2_TCL_VEC_MATERIAL0_EMI_OFFSET        0x00B0
#define RAD2_TCL_VEC_MATERIAL0_AMB_OFFSET        0x00B1
#define RAD2_TCL_VEC_MATERIAL0_DIFF_OFFSET       0x00B2
#define RAD2_TCL_VEC_MATERIAL0_SPEC_OFFSET       0x00B3

#define RAD2_TCL_VEC_MATERIAL1_EMI_OFFSET        0x00B4
#define RAD2_TCL_VEC_MATERIAL1_AMB_OFFSET        0x00B5
#define RAD2_TCL_VEC_MATERIAL1_DIFF_OFFSET       0x00B6
#define RAD2_TCL_VEC_MATERIAL1_SPEC_OFFSET       0x00B7

#define RAD2_TCL_VEC_HOS_CNTL_PNT_CONST_OFFSET   0x0066
#define RAD2_TCL_VEC_DISPLACE_MAP_SCALE_OFFSET   0x0067
#define RAD2_TCL_VEC_PNT_SPR_VP_SCALE_OFFSET     0x0068
#define RAD2_TCL_VEC_PNT_SPR_ATTEN_CONST_OFFSET  0x00BC
#define RAD2_TCL_VEC_PNT_SPR_EYE_IN_MODEL_OFFSET 0x00BD
#define RAD2_TCL_VEC_PNT_SPR_CLAMP_OFFSET        0x00BE

#define RAD2_TCL_VEC_MATRIX22_OFFSET             0x0100
#define RAD2_TCL_VEC_MATRIX29_OFFSET             0x011C
#define RAD2_TCL_VEC_MATRIX38_OFFSET             0x0140
#define RAD2_TCL_VEC_MATRIX48_OFFSET             0x0180
#define RAD2_TCL_VEC_MATRIX58_OFFSET             0x01A8

#define RAD2_TCL_VEC_DEFAULT_STRIDE              0x0001
#define RAD2_TCL_VEC_LIGHT_STRIDE                0x0008

// Scalar Offsets, Strides, and Nexts are in DWORDS
// CHAPLIN_TODO: The light scalar data offsets are wrong
#define RAD2_TCL_SCA_LIGHT0_SDC_DELTA_OFFSET     0x0000
#define RAD2_TCL_SCA_LIGHT1_SDC_DELTA_OFFSET     0x0001
#define RAD2_TCL_SCA_LIGHT2_SDC_DELTA_OFFSET     0x0002
#define RAD2_TCL_SCA_LIGHT3_SDC_DELTA_OFFSET     0x0003
#define RAD2_TCL_SCA_LIGHT4_SDC_DELTA_OFFSET     0x0004
#define RAD2_TCL_SCA_LIGHT5_SDC_DELTA_OFFSET     0x0005
#define RAD2_TCL_SCA_LIGHT6_SDC_DELTA_OFFSET     0x0006
#define RAD2_TCL_SCA_LIGHT7_SDC_DELTA_OFFSET     0x0007

#define RAD2_TCL_SCA_LIGHT0_SDC_MULT_OFFSET      0x0008
#define RAD2_TCL_SCA_LIGHT1_SDC_MULT_OFFSET      0x0009
#define RAD2_TCL_SCA_LIGHT2_SDC_MULT_OFFSET      0x000A
#define RAD2_TCL_SCA_LIGHT3_SDC_MULT_OFFSET      0x000B
#define RAD2_TCL_SCA_LIGHT4_SDC_MULT_OFFSET      0x000C
#define RAD2_TCL_SCA_LIGHT5_SDC_MULT_OFFSET      0x000D
#define RAD2_TCL_SCA_LIGHT6_SDC_MULT_OFFSET      0x000E
#define RAD2_TCL_SCA_LIGHT7_SDC_MULT_OFFSET      0x000F

#define RAD2_TCL_SCA_LIGHT0_SPOT_EXP_OFFSET      0x0010
#define RAD2_TCL_SCA_LIGHT1_SPOT_EXP_OFFSET      0x0011
#define RAD2_TCL_SCA_LIGHT2_SPOT_EXP_OFFSET      0x0012
#define RAD2_TCL_SCA_LIGHT3_SPOT_EXP_OFFSET      0x0013
#define RAD2_TCL_SCA_LIGHT4_SPOT_EXP_OFFSET      0x0014
#define RAD2_TCL_SCA_LIGHT5_SPOT_EXP_OFFSET      0x0015
#define RAD2_TCL_SCA_LIGHT6_SPOT_EXP_OFFSET      0x0016
#define RAD2_TCL_SCA_LIGHT7_SPOT_EXP_OFFSET      0x0017

#define RAD2_TCL_SCA_LIGHT0_OTHER_OFFSET         0x0020
#define RAD2_TCL_SCA_LIGHT1_OTHER_OFFSET         0x0021
#define RAD2_TCL_SCA_LIGHT2_OTHER_OFFSET         0x0022
#define RAD2_TCL_SCA_LIGHT3_OTHER_OFFSET         0x0023
#define RAD2_TCL_SCA_LIGHT4_OTHER_OFFSET         0x0024
#define RAD2_TCL_SCA_LIGHT5_OTHER_OFFSET         0x0025
#define RAD2_TCL_SCA_LIGHT6_OTHER_OFFSET         0x0026
#define RAD2_TCL_SCA_LIGHT7_OTHER_OFFSET         0x0027

#define RAD2_TCL_SCA_MATERIAL0_SHININESS_OFFSET  0x0100
#define RAD2_TCL_SCA_MATERIAL1_SHININESS_OFFSET  0x0101

#define RAD2_TCL_SCA_GUARD_BAND_OFFSET           0x0080

#define RAD2_TCL_SCA_DEFAULT_STRIDE              0x0001
#define RAD2_TCL_SCA_LIGHT_STRIDE                0x0008


/////////////////////////////////////////////////////////////////////////////
// Macros
/////////////////////////////////////////////////////////////////////////////
#define TCL_PACKET_SIZE(regType)   ((sizeof(regType) >> 2) - 2)


////////////////////////////////////////////////////////////////////////
// Typedefed commands
////////////////////////////////////////////////////////////////////////








////////////////////////////////////////////////////////////////////////
// ATIMATRIX_cmd
////////////////////////////////////////////////////////////////////////
// Note the ATIMATRIX struct has a dwFlags member at the end that we don't want to
// send to the hardware. As a result, the definition ATIMATRIX_CMD_LENGTH 
// has the "correct: length
typedef struct _ATIMATRIX_cmd
{
  DWORD dwCmdHeader[3];
  ATIMATRIX mat;
} ATIMATRIX_cmd, *LPATIMATRIX_cmd;


////////////////////////////////////////////////////////////////////////
// ATILIGHT_VECDATA_COLOR_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATILIGHT_VECDATA_COLOR_cmd
{
  DWORD dwCmdHeader[3];
  ATIFLOATCOLOR   cfAmbient;           // Ambient color of light 
  ATIFLOATCOLOR   cfDiffuse;           // Diffuse color of light 
  ATIFLOATCOLOR   cfSpecular;          // Specular color of light 
} ATILIGHT_VECDATA_COLOR_cmd, *LPATILIGHT_VECDATA_COLOR_cmd;


////////////////////////////////////////////////////////////////////////
// ATILIGHT_VECDATA_POSITION_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATILIGHT_VECDATA_POSITION_cmd
{
  DWORD dwCmdHeader[3];
  union
  {
    ATIVECTOR       vecLclPosition;    // Position in camera space 
    ATIVECTOR       vecInfDirection;   // Direction in world space 
  } vec0;
  
  union
  {
    ATIVECTOR       vecLclDirection;   // Direction in camera space 
    ATIVECTOR       vecInfHalfway;     // Halfway vector in world space 
  } vec1;
  
  float        fAttenuation2;          // Quadratic attenuation a.k.a Kq 
  float        fAttenuation1;          // Linear attenuation a.k.a. Kl 
  float        fAttenuation0;          // Constant attenuation a.k.a Kc
                                       // Note: there is storage for a 4th
                                       // constant but that space is not
                                       // used by the hardware.
} ATILIGHT_VECDATA_POSITION_cmd, *LPATILIGHT_VECDATA_POSITION_cmd;


////////////////////////////////////////////////////////////////////////
// ATILIGHT_SCADATA_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATILIGHT_SCADATA_cmd
{
  DWORD dwCmdHeader0[3];
  float fDualConeDelta;        // cos(dvPhi) / ( cos(dvTheta) - cos(dvPhi) )
                               // dvPhi   = Dx light member = outer cone angle
                               // dvTheta = Dx light member = inner cone angle
  DWORD dwCmdHeader1[3];
  float fSpotlightExponent;    // Spotlight exponent
  DWORD dwCmdHeader2[3];
  float fDualConeMultiplier;   // 1 / ( cos(dvTheta) - cos(dvPhi) )
                               // dvPhi   = Dx light member = outer cone angle
                               // dvTheta = Dx light member = inner cone angle
  DWORD dwCmdHeader3[3];
  float fSpecThreshold;        // Specular threshold
                               // if s*n >= dvSpecThreshold then spec
                               // contribution is 0, else spec contribution
                               // is s*n^shininess
  float fRangeSquared;         // Cutoff range squared
  float fAttenConstant;        // Should make dvAttenConstant=1/Kc if Kl=Kq=0.f
                               // Also set the range att const enable bit or
                               // this does nothing.
} ATILIGHT_SCADATA_cmd, *LPATILIGHT_SCADATA_cmd;


////////////////////////////////////////////////////////////////////////
// ATILIGHT_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATILIGHT_cmd
{
  ATILIGHT_VECDATA_COLOR_cmd vecDataColorCmd;
  ATILIGHT_VECDATA_POSITION_cmd vecDataPositionCmd;
  ATILIGHT_SCADATA_cmd scaDataCmd;
} ATILIGHT_cmd, *LPATILIGHT_cmd;


////////////////////////////////////////////////////////////////////////
// ATIGBLAMBIENT_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATIGBLAMBIENT_cmd
{
  DWORD dwCmdHeader[3];
  ATIFLOATCOLOR ambient;
} ATIGBLAMBIENT_cmd, *LPATIGBLAMBIENT_cmd;


//////////////////////////////////////////////////////////////////////// 
// ATITCLGRDBND_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATITCLGRDBND_cmd
{
  DWORD dwCmdHeader[3];
  float fYClipAdjust;
  float fYDiscardAdjust;
  float fXClipAdjust;
  float fXDiscardAdjust;
} ATITCLGRDBND_cmd, *LPATITCLGRDBND_cmd;


////////////////////////////////////////////////////////////////////////
// ATITCLFOGEYESCALNRML_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATITCLFOGEYESCALENRML_cmd
{
  DWORD dwCmdHeader[3];
  float fRTerm;     // Even though there is space for 4 floats, only 3 (r,c and d) get used
  float fCTerm;
  float fDTerm;
  float fXTerm; 
  ATIVECTOR vecEye;  // only x,y,z is eye, w is rescale normal constant
} ATITCLFOGEYESCALENRML_cmd, *LPATITCLFOGEYESCALENRML_cmd;


////////////////////////////////////////////////////////////////////////
// ATIUSERCLIPPLANE_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATIUSERCLIPPLANE_cmd
{
  DWORD dwCmdHeader[3];
  ATIVECTOR vecPlaneEquation;
} ATIUSERCLIPPLANE_cmd, *LPATIUSERCLIPPLANE_cmd;



////////////////////////////////////////////////////////////////////////
// ATIEMISSIVE_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATIEMISSIVE_cmd
{
  // MM register in Rage6
  // VECTOR data in Chaplin
  DWORD dwCmdHeader[3];
  ATIFLOATCOLOR emissive;
} ATIEMISSIVE_cmd, *LPATIEMISSIVE_cmd;


////////////////////////////////////////////////////////////////////////
// ATIAMBIENT_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATIAMBIENT_cmd
{
  // MM register in Rage6
  // VECTOR data in Chaplin
  DWORD dwCmdHeader[3];
  ATIFLOATCOLOR ambient;
} ATIAMBIENT_cmd, *LPATIAMBIENT_cmd;


////////////////////////////////////////////////////////////////////////
// ATIDIFFUSE_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATIDIFFUSE_cmd
{
  // MM register in Rage6
  // VECTOR data in Chaplin
  DWORD dwCmdHeader[3];
  ATIFLOATCOLOR diffuse;
} ATIDIFFUSE_cmd, *LPATIDIFFUSE_cmd;


////////////////////////////////////////////////////////////////////////
// ATISPECULAR_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATISPECULAR_cmd
{
  // MM register in Rage6
  // VECTOR data in Chaplin
  DWORD dwCmdHeader[3];
  ATIFLOATCOLOR specular;
} ATISPECULAR_cmd, *LPATISPECULAR_cmd;


////////////////////////////////////////////////////////////////////////
// ATISHININESS_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATISHININESS_cmd
{
  DWORD dwCmdHeader[3];
  float shininess;
} ATISHININESS_cmd, *LPATISHININESS_cmd;


////////////////////////////////////////////////////////////////////////
// ATIMATERIAL_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATIMATERIAL_cmd
{
  ATIEMISSIVE_cmd emissiveCmd;
  ATIAMBIENT_cmd ambientCmd;
  ATIDIFFUSE_cmd diffuseCmd;
  ATISPECULAR_cmd specularCmd;
  ATISHININESS_cmd shininessCmd;
} ATIMATERIAL_cmd, *LPATIMATERIAL_cmd;



////////////////////////////////////////////////////////////////////////
// ATITCLFLUSH_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATITCLFLUSH_cmd
{
  DWORD dwCmdHeader;
  DWORD dwUnused;
} ATITCLFLUSH_cmd, *LPATITCLFLUSH_cmd;


// CHAPLIN_TODO: The following are commands that aren't currently being
// CHAPLIN_TODO: shared between Rage 6 and Chaplin
// Chaplin-specifc commands

////////////////////////////////////////////////////////////////////////
// ATITCLRAD2GLOBALSTATE_cmd
////////////////////////////////////////////////////////////////////////

//
// ATITCLRAD2GLOBALSTATE_cmd
typedef struct _ATITCLRAD2GLOBALSTATE_cmd
{
  DWORD                       dwCmdHeader;
  regSE_TCL_MATRIX_SEL_0      matrixSel0;
  regSE_TCL_MATRIX_SEL_1      matrixSel1;
  regSE_TCL_MATRIX_SEL_2      matrixSel2;
  regSE_TCL_MATRIX_SEL_3      matrixSel3;
  regSE_TCL_MATRIX_SEL_4      matrixSel4;
  regSE_TCL_PER_VTX_MTX_CNTL  perVtxMtxCntl;
} ATITCLRAD2GLOBALSTATE_cmd, *LPATITCLRAD2GLOBALSTATE_cmd;

__inline void
SetTclGlobalStateCmdHeaders( LPATITCLRAD2GLOBALSTATE_cmd pCmd, LPTclVecScaStrOff pStrOff)
{
  pCmd->dwCmdHeader = ( TCL_PACKET_SIZE(ATITCLRAD2GLOBALSTATE_cmd) << 16) | mmSE_TCL_MATRIX_SEL_0;
}

////////////////////////////////////////////////////////////////////////
// ATITCLRAD2MISCCONTROL_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATITCLRAD2MISCCONTROL_cmd
{
  DWORD                        dwCmdHeader;
  regSE_TCL_UCP_VTX_BLEND_CNTL ucpSkinCullCntl;
} ATITCLRAD2MISCCONTROL_cmd, *LPATITCLRAD2MISCCONTROL_cmd;

#define SET_TCL_RAD2_MISCCONTROL_CMD_HEADERS( atiTclRad2MiscControlCmd )           \
{ \
  (atiTclRad2MiscControlCmd).dwCmdHeader =                                         \
    (TCL_PACKET_SIZE(atiTclRad2MiscControlCmd)<<16) | mmSE_TCL_UCP_VTX_BLEND_CNTL; \
}

////////////////////////////////////////////////////////////////////////
// ATITCLRAD2OUTPUTVTXCONTROL_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATITCLRAD2OUTPUTVTXCONTROL_cmd
{
  DWORD                          dwCmdHeader0;
  regSE_TCL_OUTPUT_VTX_FMT_0     OutVtxFmt0;
  regSE_TCL_OUTPUT_VTX_FMT_1     OutVtxFmt1;
  DWORD                          dwCmdHeader1;
  regSE_TCL_OUTPUT_VTX_COMP_SEL  OutVtxCompSel;
} ATITCLRAD2OUTPUTVTXCONTROL_cmd, *LPATITCLRAD2OUTPUTVTXCONTROL_cmd;

#define SET_TCL_RAD2_OUTPUTVTXCONTROL_CMD_HEADERS( atiTclRad2OutputVtxControlCmd )           \
{                                                                                            \
  (atiTclRad2OutputVtxControlCmd).dwCmdHeader0  = ((2-1)<<16)| mmSE_TCL_OUTPUT_VTX_FMT_0;    \
  (atiTclRad2OutputVtxControlCmd).dwCmdHeader1  = ((1-1)<<16)| mmSE_TCL_OUTPUT_VTX_COMP_SEL; \
}

////////////////////////////////////////////////////////////////////////
// ATITCLRAD2INPUTVTXVECTORADDR_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATITCLRAD2INPUTVTXVECTORADDR_cmd
{
  DWORD                              dwCmdHeader;
  regSE_TCL_INPUT_VTX_VECTOR_ADDR_0  inputVtxVectorAddr0;
  regSE_TCL_INPUT_VTX_VECTOR_ADDR_1  inputVtxVectorAddr1;
  regSE_TCL_INPUT_VTX_VECTOR_ADDR_2  inputVtxVectorAddr2;
  regSE_TCL_INPUT_VTX_VECTOR_ADDR_3  inputVtxVectorAddr3;
} ATITCLRAD2INPUTVTXVECTORADDR_cmd, *LPATITCLRAD2INPUTVTXVECTORADDR_cmd;

__inline void
SetTclRad2InputVertexAddrCmdHeaders( LPATITCLRAD2INPUTVTXVECTORADDR_cmd pCmd)
{
  pCmd->dwCmdHeader  = 
    (TCL_PACKET_SIZE(ATITCLRAD2INPUTVTXVECTORADDR_cmd)<<16)| mmSE_TCL_INPUT_VTX_VECTOR_ADDR_0;
}


////////////////////////////////////////////////////////////////////////
// ATITCLRAD2TEXTURECONTROL_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATITCLRAD2TEXTURECONTROL_cmd
{
  DWORD                         dwCmdHeader;
  regSE_TCL_TEX_PROC_CNTL_0     texProcCntl0;
  regSE_TCL_TEX_PROC_CNTL_1     texProcCntl1;
  regSE_TCL_TEX_CYL_WRAP_CNTL   texCylWrapCntl;
} ATITCLRAD2TEXTURECONTROL_cmd, *LPATITCLRAD2TEXTURECONTROL_cmd;

#define SET_TCL_RAD2_TEXTURECONTROL_CMD_HEADERS( atiTclRad2TextureControlCmd )       \
{ \
  (atiTclRad2TextureControlCmd).dwCmdHeader =                                        \
    (TCL_PACKET_SIZE(atiTclRad2TextureControlCmd)<<16) | mmSE_TCL_TEX_PROC_CNTL_0;   \
}

////////////////////////////////////////////////////////////////////////
// ATITCLRAD2LIGHTCONTROL_cmd
////////////////////////////////////////////////////////////////////////
#pragma pack( push, 2 )
typedef struct _ATITCLRAD2LIGHTCONTROL_cmd
{
  DWORD                        dwCmdHeader;
  regSE_TCL_LIGHT_MODEL_CNTL_0 lightModelCntl0;
  regSE_TCL_LIGHT_MODEL_CNTL_1 lightModelCntl1;
  SeTclPerLightCntl            perLightCntl[8];   // Note each entry is a WORD
} ATITCLRAD2LIGHTCONTROL_cmd, *LPATITCLRAD2LIGHTCONTROL_cmd;
#pragma pack( pop )

#define SET_TCL_RAD2_LIGHTCONTROL_CMD_HEADERS( atiTclRad2LightControlCmd )            \
{                                                                                     \
  (atiTclRad2LightControlCmd).dwCmdHeader =                                           \
    (TCL_PACKET_SIZE(atiTclRad2LightControlCmd)<<16) | mmSE_TCL_LIGHT_MODEL_CNTL_0;   \
}

////////////////////////////////////////////////////////////////////////
// ATITCLRAD2POINTSPRITECNTL_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATITCLRAD2POINTSPRITECNTL_cmd
{
  DWORD                         dwCmdHeader;
  regSE_TCL_POINT_SPRITE_CNTL   pointSpriteCntl;
} ATITCLRAD2POINTSPRITECNTL_cmd, *LPATITCLRAD2POINTSPRITECNTL_cmd;

#define SET_TCL_RAD2_POINTSPRITECNTL_CMD_HEADERS( atiTclRad2PointSpriteCntlCmd )       \
{                                                                                      \
  (atiTclRad2PointSpriteCntlCmd).dwCmdHeader =                                         \
    (TCL_PACKET_SIZE(atiTclRad2PointSpriteCntlCmd)<<16) | mmSE_TCL_POINT_SPRITE_CNTL;  \
}

////////////////////////////////////////////////////////////////////////
// ATITCLRAD2INDXLIMIT_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATITCLRAD2INDXLIMIT_cmd
{
  DWORD                         dwCmdHeader;
  regSE_VF_MAX_VTX_INDX         MaxIndx;
  regSE_VF_MIN_VTX_INDX         MinIndx;
} ATITCLRAD2INDXLIMIT_cmd, *LPATITCLRAD2INDXLIMIT_cmd;

#define SET_TCL_RAD2_INDXLIMIT_CMD_HEADERS( atiTclRad2IndxLimitCmd )      \
{                                                                         \
  (atiTclRad2IndxLimitCmd).dwCmdHeader =                                  \
    (TCL_PACKET_SIZE(atiTclRad2IndxLimitCmd)<<16) | mmSE_VF_MAX_VTX_INDX; \
}


////////////////////////////////////////////////////////////////////////
// ATITCLRAD2HOSCNTL_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATITCLRAD2HOSCNTL_cmd
{
  DWORD                         dwCmdHeader;
  regSE_HOS_CNTL_0              HosCntl0;
  regSE_HOS_CNTL_1              HosCntl1;
} ATITCLRAD2HOSCNTL_cmd, *LPATITCLRAD2HOSCNTL_cmd;

#define SET_TCL_RAD2_HOSCNTL_CMD_HEADERS( atiTclRad2HosCntlCmd )       \
{                                                                      \
  (atiTclRad2HosCntlCmd).dwCmdHeader =                                 \
    (TCL_PACKET_SIZE(atiTclRad2HosCntlCmd)<<16) | mmSE_HOS_CNTL_0; \
}

////////////////////////////////////////////////////////////////////////
// ATITCLRAD2HOSVECINTERP_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATITCLRAD2HOSVECINTERP_cmd
{
  DWORD                         dwCmdHeader;
  regSE_HOS_VEC_INTERP_0        HosVecInterp0;
  regSE_HOS_VEC_INTERP_1        HosVecInterp1;
} ATITCLRAD2HOSVECINTERP_cmd, *LPATITCLRAD2HOSVECINTERP_cmd;

#define SET_TCL_RAD2_HOSVECINTERP_CMD_HEADERS( atiTclRad2HosVecInterpCmd )    \
{                                                                             \
  (atiTclRad2HosVecInterpCmd).dwCmdHeader =                                   \
    (TCL_PACKET_SIZE(atiTclRad2HosVecInterpCmd)<<16) | mmSE_HOS_VEC_INTERP_0; \
}

////////////////////////////////////////////////////////////////////////
// ATIHOSCONSTANT_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATIHOSCONSTANT_cmd
{
  DWORD dwCmdHeader[3];
  float Pn_Pos_Cp_Edge_Wt;
  float Pn_Pos_Mp_Wt_Orig;
  float Pn_Pos_Mp_Wt_Cp;
  float Pn_Norm_Cp_Edge_Wt;
} ATIHOSCONSTANT_cmd, *LPATIHOSCONSTANT_cmd;


////////////////////////////////////////////////////////////////////////
// ATITCLRAD2PROGSTREAMCNTL_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATITCLRAD2PROGSTREAMCNTL_cmd
{
  DWORD                         dwCmdHeader;
  regSE_PROG_STREAM_CNTL_0      ProgStreamCntl0;
  regSE_PROG_STREAM_CNTL_1      ProgStreamCntl1;
  regSE_PROG_STREAM_CNTL_2      ProgStreamCntl2;
  regSE_PROG_STREAM_CNTL_3      ProgStreamCntl3;
  regSE_PROG_STREAM_CNTL_4      ProgStreamCntl4;
  regSE_PROG_STREAM_CNTL_5      ProgStreamCntl5;
  regSE_PROG_STREAM_CNTL_6      ProgStreamCntl6;
  regSE_PROG_STREAM_CNTL_7      ProgStreamCntl7;
} ATITCLRAD2PROGSTREAMCNTL_cmd, *LPATITCLRAD2PROGSTREAMCNTL_cmd;

#define SET_TCL_RAD2_PROGSTREAMCNTL_CMD_HEADERS( atiTclRad2ProgStreamCntlCmd )    \
{                                                                                 \
  (atiTclRad2ProgStreamCntlCmd).dwCmdHeader =                                     \
    (TCL_PACKET_SIZE(atiTclRad2ProgStreamCntlCmd)<<16) | mmSE_PROG_STREAM_CNTL_0; \
}


////////////////////////////////////////////////////////////////////////
// ATIPNTSPRVPSCALE_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATIPNTSPRVPSCALE_cmd
{
  DWORD dwCmdHeader[3];
  float X_Rad_Exp;                    // viewport x scale           
  float Y_Rad_Exp;                    // viewport y scale     
  float St_Multiply_Const;            // state multiply constant
  float Cull_Rad_Exp;                 // sqrt(x_scale^2+y_scale^2)         
} ATIPNTSPRVPSCALE_cmd, *LPATIPNTSPRVPSCALE_cmd;


////////////////////////////////////////////////////////////////////////
// ATIPNTSPRATTCONST_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATIPNTSPRATTCONST_cmd
{
  DWORD dwCmdHeader[3];
  float Kq;                           // Quadratic attenuation  
  float Kl;                           // Linear attenuation  
  float Kc;                           // Constant attenuation     
  float Unused; 
} ATIPNTSPRATTCONST_cmd, *LPATIPNTSPRATTCONST_cmd;


////////////////////////////////////////////////////////////////////////
// ATIPNTSPREYEVECINMODEL_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATIPNTSPREYEVECINMODEL_cmd
{
  DWORD dwCmdHeader[3];
  float X;                          
  float Y;                        
  float Z;   
  float W;       
} ATIPNTSPREYEVECINMODEL_cmd, *LPATIPNTSPREYEVECINMODEL_cmd;


////////////////////////////////////////////////////////////////////////
// ATIPNTSPRCLAMP_cmd
////////////////////////////////////////////////////////////////////////
typedef struct _ATIPNTSPRCLAMP_cmd
{
  DWORD dwCmdHeader[3]; 
  float Min_Size;               
  float Max_Size;   
  float Unused1;                
  float Unused2;
} ATIPNTSPRCLAMP_cmd, *LPATIPNTSPRCLAMP_cmd;


/////////////////////////////////////////////////////////////////////////////
// Inline functions
/////////////////////////////////////////////////////////////////////////////

// CHAPLIN_TODO: Eliminate the literals


/////////////////////////////////////////////////////////////////////////////
// SetMatrixCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetMatrixCmdHeaders( LPATIMATRIX_cmd pMtxCmd, DWORD dwMtxNum, LPTclVecScaStrOff pStrOff)
{
  pMtxCmd->dwCmdHeader[0] = ((1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pMtxCmd->dwCmdHeader[1] = (pStrOff->VecMtxStride << 16) | pStrOff->VecMtxOffset[dwMtxNum];
  pMtxCmd->dwCmdHeader[2] = ((16-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;
}


/////////////////////////////////////////////////////////////////////////////
// R200SetMatrixCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
R200SetMatrixCmdHeaders( LPATIMATRIX_cmd pMtxCmd, WORD wVectorOffset)
{
  pMtxCmd->dwCmdHeader[0] = ((1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pMtxCmd->dwCmdHeader[1] = (RAD2_TCL_VEC_DEFAULT_STRIDE << 16) | wVectorOffset;
  pMtxCmd->dwCmdHeader[2] = ((16-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;
}


/////////////////////////////////////////////////////////////////////////////
// SetProjMatrixCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetProjMatrixCmdHeaders( LPATIMATRIX_cmd pMtxCmd, LPTclVecScaStrOff pStrOff)
{
  pMtxCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pMtxCmd->dwCmdHeader[1] = (pStrOff->VecMtxStride << 16) | pStrOff->VecProjMtxOffset;
  pMtxCmd->dwCmdHeader[2] = ((16-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;
}


/////////////////////////////////////////////////////////////////////////////
// SetUserClipPlaneCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetUserClipPlaneCmdHeaders( LPATIUSERCLIPPLANE_cmd pUcpCmd, DWORD dwNumUcp, 
                            LPTclVecScaStrOff pStrOff)
{
  pUcpCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pUcpCmd->dwCmdHeader[1] = (pStrOff->VecUCPStride << 16) | ( pStrOff->VecUCPOffset[dwNumUcp] );
  pUcpCmd->dwCmdHeader[2] = (( 4-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;
}


/////////////////////////////////////////////////////////////////////////////
// SetLightVecDataColorCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetLightVecDataColorCmdHeaders( LPATILIGHT_VECDATA_COLOR_cmd pLightVecColorCmd, 
                                LPTclVecScaStrOff pStrOff)
{
  pLightVecColorCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pLightVecColorCmd->dwCmdHeader[1] = 0; // Set in TclLightCmdSetIndex()
  pLightVecColorCmd->dwCmdHeader[2] = ((12-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;
}


/////////////////////////////////////////////////////////////////////////////
// SetLightVecDataPositionCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetLightVecDataPositionCmdHeaders( LPATILIGHT_VECDATA_POSITION_cmd pLightVecPosCmd,
                                   LPTclVecScaStrOff pStrOff)
{
  pLightVecPosCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pLightVecPosCmd->dwCmdHeader[1] = 0; // Set in TclLightCmdSetIndex()
  pLightVecPosCmd->dwCmdHeader[2] = ((11-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;
}  


/////////////////////////////////////////////////////////////////////////////
// SetLightScaDataCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetLightScaDataCmdHeaders( LPATILIGHT_SCADATA_cmd pLightScaCmd,
                           LPTclVecScaStrOff pStrOff)
{
  // Spot Dual Cone Delta
  pLightScaCmd->dwCmdHeader0[0] = (( 1-1)<<16) | mmSE_TCL_SCALAR_INDX_REG;
  pLightScaCmd->dwCmdHeader0[1] = 0; // Set in TclLightCmdSetIndex()
  pLightScaCmd->dwCmdHeader0[2] = (( 1-1)<<16) | mmSE_TCL_SCALAR_DATA_REG | AutoIncOffTag;
  // Spot Dual Cone Mult
  pLightScaCmd->dwCmdHeader1[0] = (( 1-1)<<16) | mmSE_TCL_SCALAR_INDX_REG;
  pLightScaCmd->dwCmdHeader1[1] = 0; // Set in TclLightCmdSetIndex()
  pLightScaCmd->dwCmdHeader1[2] = (( 1-1)<<16) | mmSE_TCL_SCALAR_DATA_REG | AutoIncOffTag;
  // Spot exponent
  pLightScaCmd->dwCmdHeader2[0] = (( 1-1)<<16) | mmSE_TCL_SCALAR_INDX_REG;
  pLightScaCmd->dwCmdHeader2[1] = 0; // Set in TclLightCmdSetIndex()
  pLightScaCmd->dwCmdHeader2[2] = (( 1-1)<<16) | mmSE_TCL_SCALAR_DATA_REG | AutoIncOffTag;
  // Other light scalar data
  pLightScaCmd->dwCmdHeader3[0] = (( 1-1)<<16) | mmSE_TCL_SCALAR_INDX_REG;
  pLightScaCmd->dwCmdHeader3[1] = 0; // Set in TclLightCmdSetIndex()
  pLightScaCmd->dwCmdHeader3[2] = (( 3-1)<<16) | mmSE_TCL_SCALAR_DATA_REG | AutoIncOffTag;
}

/////////////////////////////////////////////////////////////////////////////
// SetLightCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetLightCmdHeaders( LPATILIGHT_cmd pLightCmd, LPTclVecScaStrOff pStrOff)
{
  SetLightVecDataPositionCmdHeaders( &pLightCmd->vecDataPositionCmd, pStrOff );
  SetLightVecDataColorCmdHeaders( &pLightCmd->vecDataColorCmd, pStrOff );
  SetLightScaDataCmdHeaders( &pLightCmd->scaDataCmd, pStrOff );
}

/////////////////////////////////////////////////////////////////////////////
// TcllLightCmdGetIndex
/////////////////////////////////////////////////////////////////////////////
__inline DWORD TclLightCmdGetIndex( LPATILIGHT_cmd pCmd )
{ return pCmd->scaDataCmd.dwCmdHeader0[1] & 0x0000ffff; }

/////////////////////////////////////////////////////////////////////////////
// TclLightCmdSetIndex
/////////////////////////////////////////////////////////////////////////////
__inline void TclLightCmdSetIndex( LPATILIGHT_cmd pCmd, DWORD dwLightNum,
                                  LPTclVecScaStrOff pStrOff)
{

  if (dwLightNum < ATI_NUM_LIGHTS)
  {
    // Spot dual cone delta
    pCmd->scaDataCmd.dwCmdHeader0[1] =   (pStrOff->ScaLightStride << 16) 
                                      | pStrOff->ScaLightSDCDeltaOffset[dwLightNum];
    // Spot exponent
    pCmd->scaDataCmd.dwCmdHeader1[1] =   (pStrOff->ScaLightStride << 16) 
                                      | pStrOff->ScaLightSpotExpOffset[dwLightNum];
    // Spot dual cone mult
    pCmd->scaDataCmd.dwCmdHeader2[1] =   (pStrOff->ScaLightStride << 16) 
                                      | pStrOff->ScaLightSDCMultOffset[dwLightNum];
    // Other scalar data
    pCmd->scaDataCmd.dwCmdHeader3[1] =   (pStrOff->ScaLightStride << 16) 
                                      | pStrOff->ScaLightOtherOffset[dwLightNum];

    // Vector color
    pCmd->vecDataColorCmd.dwCmdHeader[1] =   (pStrOff->VecLightStride << 16) 
                                           | pStrOff->VecLightColorOffset[dwLightNum];

    // Vector position
    pCmd->vecDataPositionCmd.dwCmdHeader[1] =   (pStrOff->VecLightStride << 16) 
                                              | pStrOff->VecLightPosOffset[dwLightNum];
  }
  else
  {
    pCmd->scaDataCmd.dwCmdHeader0[1] = ATI_NUM_LIGHTS;
  }
}

/////////////////////////////////////////////////////////////////////////////
// SetGblAmbientCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetGblAmbientCmdHeaders( LPATIGBLAMBIENT_cmd pGblAmbCmd, LPTclVecScaStrOff pStrOff)
{
  pGblAmbCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pGblAmbCmd->dwCmdHeader[1] =   ( pStrOff->VecGlobalAmbientStride << 16) 
                               | pStrOff->VecGlobalAmbientOffset;
  pGblAmbCmd->dwCmdHeader[2] = (( 4-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;
}  

/////////////////////////////////////////////////////////////////////////////
// SetGuardBandCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetGuardBandCmdHeaders( LPATITCLGRDBND_cmd pGuardBandCmd, LPTclVecScaStrOff pStrOff)
{
  pGuardBandCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_SCALAR_INDX_REG;
  pGuardBandCmd->dwCmdHeader[1] =  (pStrOff->ScaGuardBandStride << 16) 
                                  | pStrOff->ScaGuardBandOffset;
  pGuardBandCmd->dwCmdHeader[2] = (( 4-1)<<16) | mmSE_TCL_SCALAR_DATA_REG | AutoIncOffTag;
}

/////////////////////////////////////////////////////////////////////////////
// SetFogEyeScaleNrmlCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetFogEyeScaleNrmlCmdHeaders( LPATITCLFOGEYESCALENRML_cmd pFogEyeScaleNrmlCmd,
                              LPTclVecScaStrOff pStrOff)
{
  pFogEyeScaleNrmlCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pFogEyeScaleNrmlCmd->dwCmdHeader[1] =   (pStrOff->VecFogParametersStride << 16) 
                                        | pStrOff->VecFogParametersOffset;
  pFogEyeScaleNrmlCmd->dwCmdHeader[2] = (( 8-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;
}


/////////////////////////////////////////////////////////////////////////////
// SetRad2MaterialEmissiveCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetRad2MaterialEmissiveCmdHeaders( LPATIEMISSIVE_cmd pColorCmd, LPTclVecScaStrOff pStrOff)
{
  pColorCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pColorCmd->dwCmdHeader[1] =  (pStrOff->VecMaterialStride << 16) 
                              | pStrOff->VecMaterialEmissiveOffset;
  pColorCmd->dwCmdHeader[2] = (( 4-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;
}

/////////////////////////////////////////////////////////////////////////////
// SetRad2MaterialAmbientCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetRad2MaterialAmbientCmdHeaders( LPATIAMBIENT_cmd pColorCmd, LPTclVecScaStrOff pStrOff)
{
  pColorCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pColorCmd->dwCmdHeader[1] =   (pStrOff->VecMaterialStride << 16) 
                              | pStrOff->VecMaterialAmbientOffset;
  pColorCmd->dwCmdHeader[2] = (( 4-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;  
}

/////////////////////////////////////////////////////////////////////////////
// SetRad2MaterialDiffuseCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetRad2MaterialDiffuseCmdHeaders( LPATIDIFFUSE_cmd pColorCmd, LPTclVecScaStrOff pStrOff)
{
  pColorCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pColorCmd->dwCmdHeader[1] =   (pStrOff->VecMaterialStride << 16) 
                              | pStrOff->VecMaterialDiffuseOffset;
  pColorCmd->dwCmdHeader[2] = (( 4-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;  
}

/////////////////////////////////////////////////////////////////////////////
// SetRad2MaterialSpecularCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetRad2MaterialSpecularCmdHeaders( LPATISPECULAR_cmd pColorCmd, LPTclVecScaStrOff pStrOff)
{
  pColorCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pColorCmd->dwCmdHeader[1] =   (pStrOff->VecMaterialStride << 16) 
                              | pStrOff->VecMaterialSpecularOffset;
  pColorCmd->dwCmdHeader[2] = (( 4-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;  
}

/////////////////////////////////////////////////////////////////////////////
// SetMaterialShininessCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetMaterialShininessCmdHeaders( LPATISHININESS_cmd pShininessCmd, LPTclVecScaStrOff pStrOff)
{
  pShininessCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_SCALAR_INDX_REG;
  pShininessCmd->dwCmdHeader[1] =   (pStrOff->ScaMaterialShininessStride << 16) 
                                  | pStrOff->ScaMaterialShininessOffset;
  pShininessCmd->dwCmdHeader[2] = (( 1-1)<<16) | mmSE_TCL_SCALAR_DATA_REG | AutoIncOffTag;
}


/////////////////////////////////////////////////////////////////////////////
// SetMaterialCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetMaterialCmdHeaders( LPATIMATERIAL_cmd pMatCmd, LPTclVecScaStrOff pStrOff, BOOL bIsR200)
{
  SetRad2MaterialEmissiveCmdHeaders( &pMatCmd->emissiveCmd, pStrOff);
  SetRad2MaterialAmbientCmdHeaders ( &pMatCmd->ambientCmd, pStrOff);
  SetRad2MaterialDiffuseCmdHeaders ( &pMatCmd->diffuseCmd, pStrOff);
  SetRad2MaterialSpecularCmdHeaders( &pMatCmd->specularCmd, pStrOff);

  SetMaterialShininessCmdHeaders( &pMatCmd->shininessCmd, pStrOff);
}

/////////////////////////////////////////////////////////////////////////////
// SetHosConstantCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetHosConstantCmdHeaders( LPATIHOSCONSTANT_cmd pHosConstantCmd, LPTclVecScaStrOff pStrOff)
{
  pHosConstantCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pHosConstantCmd->dwCmdHeader[1] =   (pStrOff->VecHosConstantStride << 16) 
                                  | pStrOff->VecHosConstantOffset;
  pHosConstantCmd->dwCmdHeader[2] = (( 4-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;
}

/////////////////////////////////////////////////////////////////////////////
// SetPntSprVpScaleCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetPntSprVpScaleCmdHeaders( LPATIPNTSPRVPSCALE_cmd pPntSprVpScaleCmd, LPTclVecScaStrOff pStrOff)
{
  pPntSprVpScaleCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pPntSprVpScaleCmd->dwCmdHeader[1] =   (pStrOff->VecPntSprVpScaleStride << 16) 
                                       | pStrOff->VecPntSprVpScaleOffset;
  pPntSprVpScaleCmd->dwCmdHeader[2] = (( 4-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;
}

/////////////////////////////////////////////////////////////////////////////
// SetPntSprAttConstCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetPntSprAttConstCmdHeaders( LPATIPNTSPRATTCONST_cmd pPntSprAttConstCmd, LPTclVecScaStrOff pStrOff)
{
  pPntSprAttConstCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pPntSprAttConstCmd->dwCmdHeader[1] =  (pStrOff->VecPntSprAttConstStride << 16) 
                                       | pStrOff->VecPntSprAttConstOffset;
  pPntSprAttConstCmd->dwCmdHeader[2] = (( 4-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;
}

/////////////////////////////////////////////////////////////////////////////
// SetPntSprEyeInModelCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetPntSprEyeInModelCmdHeaders( LPATIPNTSPREYEVECINMODEL_cmd pPntSprEyeInModelCmd, LPTclVecScaStrOff pStrOff)
{
  pPntSprEyeInModelCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pPntSprEyeInModelCmd->dwCmdHeader[1] = (pStrOff->VecPntSprEyeInModelStride << 16) 
                                        | pStrOff->VecPntSprEyeInModelOffset;
  pPntSprEyeInModelCmd->dwCmdHeader[2] = (( 4-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;
}

/////////////////////////////////////////////////////////////////////////////
// SetPntSprClampCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetPntSprClampCmdHeaders( LPATIPNTSPRCLAMP_cmd pPntSprClampCmd, LPTclVecScaStrOff pStrOff)
{
  pPntSprClampCmd->dwCmdHeader[0] = (( 1-1)<<16) | mmSE_TCL_VECTOR_INDX_REG;
  pPntSprClampCmd->dwCmdHeader[1] = (pStrOff->VecPntSprClampStride << 16) 
                                   | pStrOff->VecPntSprClampOffset;
  pPntSprClampCmd->dwCmdHeader[2] = (( 4-1)<<16) | mmSE_TCL_VECTOR_DATA_REG | AutoIncOffTag;
}

/////////////////////////////////////////////////////////////////////////////
// SetTclFlushCmdHeaders
/////////////////////////////////////////////////////////////////////////////
__inline void
SetTclFlushCmdHeadersR100(LPATITCLFLUSH_cmd pFlushCmd, LPTclVecScaStrOff pStrOff)
{
    pFlushCmd->dwCmdHeader = PM4_PACKET2_NOP;
    pFlushCmd->dwUnused    = PM4_PACKET2_NOP;
}

__inline void
SetTclFlushCmdHeadersR200(LPATITCLFLUSH_cmd pFlushCmd, LPTclVecScaStrOff pStrOff)
{
    pFlushCmd->dwCmdHeader = (( 1-1)<<16) | mmSE_TCL_STATE_FLUSH_REG;
    pFlushCmd->dwUnused    = 0;
}

#endif  // _TCL_COMMANDS_H__


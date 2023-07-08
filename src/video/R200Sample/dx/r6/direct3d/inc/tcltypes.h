

//    
//  Workfile: tclTypes.h
//
//  Description:
//
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, 2000 ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _TCLTYPES_H_
#define _TCLTYPES_H_


/////////////////////////////////////////////////////////////////////////////
// Enumerations
/////////////////////////////////////////////////////////////////////////////

// These enumerations more appropriately belong elsewhere with other register
// setting enumerations. In an ideal world, these would be auto-generated, but
// that ain't likely to happen this go round.

/////////////////////////////////////////////////////////////////////////////
// E_TCL_MAT_SRC
//   These are used directly by TclMaterialSrc structures and copied into
//   the appropriate hardware register when needed
//   Rage 6  SE_TCL_LIGHT_MODEL_CTL    Material Source
//   Chaplin SE_TCL_LIGHT_MODEL_CNTL_1 Material Source
/////////////////////////////////////////////////////////////////////////////
typedef enum 
{
  TCL_MAT_SRC_MATERIAL_PREMULT    = 0,
  TCL_MAT_SRC_MATERIAL            = 1,
  TCL_MAT_SRC_DIFFUSE             = 2, // Chaplin Color 0
  TCL_MAT_SRC_SPECULAR            = 3, // Chaplin Color 1
  TCL_MAT_SRC_COLOR_2_NOT_USED    = 4, // Not valid on Rage 6
  TCL_MAT_SRC_COLOR_3_NOT_USED    = 5, // Not valid on Rage 6
  TCL_MAT_SRC_COLOR_4_NOT_USED    = 6, // Not valid on Rage 6
  TCL_MAT_SRC_COLOR_5_NOT_USED    = 7, // Not valid on Rage 6
  TCL_MAT_SRC_COLOR_6_NOT_USED    = 8, // Not valid on Rage 6
  TCL_MAT_SRC_COLOR_7_NOT_USED    = 9, // Not valid on Rage 6
  TCL_MAT_SRC_MATERIAL_1_NOT_USED = 15 // Not valid on Rage 6
} E_TCL_MAT_SRC;


/////////////////////////////////////////////////////////////////////////////
// Typedef structures
/////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
// SeTclPerLightCntl
////////////////////////////////////////////////////////////////////////
// Note that this structure must match the definition of the upper
// and lower WORDs of the SE_TCL_PER_LIGHT_CNTL_x register definitions
typedef struct _SeTclPerLightCntl
{
  WORD  light_enable          :  1,
        ambient_enable        :  1,
        specular_enable       :  1,
        local_light           :  1,
        spot_enable           :  1,
        spot_dual_cone        :  1,
        rng_atten_enable      :  1,
        rng_atten_const_ena   :  1,
        spare                 :  8;
} SeTclPerLightCntl, *LPSeTclPerLightCntl;


////////////////////////////////////////////////////////////////////////
// TclVecScaStrOff - TCL Vector and Scalar Strides and Offsets
////////////////////////////////////////////////////////////////////////
typedef struct _TclVecScaStrOff
{
  // Fields prefixed with Vec are vector memory strides
  // or offsets. All values are in OCTWORDS

  // CHAPLIN_TODO: Determine ASIC version some better way
  BOOL bRad1;

  // Vector offsets
  DWORD VecMtxOffset[ATI_MAX_NUM_MATRICES];
  DWORD VecProjMtxOffset;
  DWORD VecLightColorOffset[ATI_NUM_LIGHTS];
  DWORD VecLightPosOffset[ATI_NUM_LIGHTS];
  DWORD VecUCPOffset[ATI_NUM_CLIP_PLANES];
  DWORD VecGlobalAmbientOffset;
  DWORD VecFogParametersOffset;
  DWORD VecEyeOffset;
  DWORD VecMaterialEmissiveOffset;
  DWORD VecMaterialAmbientOffset;
  DWORD VecMaterialDiffuseOffset;
  DWORD VecMaterialSpecularOffset;
  DWORD VecHosConstantOffset;
  DWORD VecPntSprVpScaleOffset; 
	DWORD VecPntSprAttConstOffset;
	DWORD VecPntSprEyeInModelOffset;
	DWORD VecPntSprClampOffset;

  // Vector strides
  DWORD VecMtxStride;
  DWORD VecLightStride;
  DWORD VecUCPStride;
  DWORD VecGlobalAmbientStride;
  DWORD VecFogParametersStride;
  DWORD VecEyeStride;
  DWORD VecMaterialStride;
  DWORD VecHosConstantStride;
  DWORD VecPntSprVpScaleStride;
	DWORD VecPntSprAttConstStride;
	DWORD VecPntSprEyeInModelStride;
	DWORD VecPntSprClampStride;


  // Fields prefixed with Sca are scalar memory strides
  // or offsets. All values are in DWORDS

  // Scalar offsets
  DWORD ScaLightSDCDeltaOffset[ATI_NUM_LIGHTS];     // Spot dual cone delta
  DWORD ScaLightSDCMultOffset[ATI_NUM_LIGHTS];      // Spot dual cone mult
  DWORD ScaLightSpotExpOffset[ATI_NUM_LIGHTS];
  DWORD ScaLightOtherOffset[ATI_NUM_LIGHTS];
  DWORD ScaGuardBandOffset;
  DWORD ScaMaterialShininessOffset;

  // Scalar strides
  DWORD ScaLightStride;
  DWORD ScaGuardBandStride;
  DWORD ScaMaterialShininessStride;

} TclVecScaStrOff, *LPTclVecScaStrOff;



////////////////////////////////////////////////////////////////////////
// TclMaterialSrc
////////////////////////////////////////////////////////////////////////
typedef union _TclMaterialSrc
{
  struct
  {
    DWORD emiSrc      : 4,
          ambSrc      : 4,
          diffSrc     : 4,
          specSrc     : 4,
          emiSrcBack  : 4,
          ambSrcBack  : 4,
          diffSrcBack : 4,
          specSrcBack : 4;
  };
  DWORD u32All;
}TclMaterialSrc, *LPTclMaterialSrc;


////////////////////////////////////////////////////////////////////////
// ATIPVSMGMT
////////////////////////////////////////////////////////////////////////
typedef struct _ATIPVSMGMT
{
  DWORD dwCurrHandle;
  DWORD dwCurrCodeStart;
  DWORD dwCurrCodeLength;
  DWORD dwCurrStateStart;
  DWORD dwCurrStateLength;

  // Hardware-specific settings
  DWORD dwFlags;
  DWORD dwCodeStartLow;
  DWORD dwCodeStartHigh;
  DWORD dwCodeSizeSeg;
  DWORD dwCodeSize;
  DWORD dwCodeStride;
  DWORD dwStateStartLow;
  DWORD dwStateStartHigh;
  DWORD dwStateSizeSeg;
  DWORD dwStateSize;
  DWORD dwStateStride;
} ATIPVSMGMT, *LPATIPVSMGMT;


#endif // _TCLTYPES_H_


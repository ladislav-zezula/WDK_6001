

//
//  $Workfile: tcl_state.h $
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

#ifndef _TCL_STATE_H__
#define _TCL_STATE_H__

#include "radeon.h"

#include "d3ddevice.h"

#include <tcl_commands.h>

#include "atidrawprim.h"

#include "vertexshader.h"

#define ATI_TCL_PREMULTIPLY_LIGHT_MATERIAL

#define ATI_TCL_GB_CLIP_ACCEPT_X_DEFAULT   8
#define ATI_TCL_GB_CLIP_ACCEPT_Y_DEFAULT   8
#define ATI_TCL_GB_DISCARD_X_DEFAULT       0
#define ATI_TCL_GB_DISCARD_Y_DEFAULT       0


// Model lighting is faster, but if we want to turn it off,
// just uncomment the line below
//#define ATI_TCL_FORCE_EYE_LIGHTING

/////////////////////////////////////////////////////////
//
// These defines are used with dwTclFlags
//
/////////////////////////////////////////////////////////
// Is TCL culling enabled?
#define ATI_TCLFLAG_TCLCULLING_ENABLED 0x00000001
#define ATI_TCLFLAG_TCLCULLING_FORCED  0x00000002
#define ATI_TCLFLAG_TCLCULLING         0x00000004

#define ATI_TCLFLAG_OPSINEYE           0x00000008
#define ATI_TCLFLAG_WORLDINVTRANS      0x00000010


#define TCL_RANGE_ATTEN_ACCURACY_BITS   8
#define TCL_SPEC_ACCURACY_BITS          9.f


#define ATI_TCL_DIRTY_CONTROL       0x00000001
#define ATI_TCL_DIRTY_MISC          0x00000002
#define ATI_TCL_DIRTY_UCP           0x00000004

#define ATI_TCL_DIRTY_MATERIAL      0x00000010
#define ATI_TCL_DIRTY_AMBIENT       0x00000020
#define ATI_TCL_DIRTY_VIEWPORT      0x00000040
#define ATI_TCL_DIRTY_PROJECTION    0x00000080

#define ATI_TCL_DIRTY_LIGHT0        0x00000100
#define ATI_TCL_DIRTY_LIGHT1        0x00000200
#define ATI_TCL_DIRTY_LIGHT2        0x00000400
#define ATI_TCL_DIRTY_LIGHT3        0x00000800
#define ATI_TCL_DIRTY_LIGHT4        0x00001000
#define ATI_TCL_DIRTY_LIGHT5        0x00002000
#define ATI_TCL_DIRTY_LIGHT6        0x00004000
#define ATI_TCL_DIRTY_LIGHT7        0x00008000
#define ATI_TCL_DIRTY_LIGHT_ALL     0x0000FF00

#define ATI_TCL_DIRTY_TEXMAT0       0x00010000
#define ATI_TCL_DIRTY_TEXMAT1       0x00020000
#define ATI_TCL_DIRTY_TEXMAT2       0x00040000
#define ATI_TCL_DIRTY_TEXMAT3       0x00080000
#define ATI_TCL_DIRTY_TEXMAT4       0x00100000
#define ATI_TCL_DIRTY_TEXMAT5       0x00200000
#define ATI_TCL_DIRTY_TEXMAT_ALL    0x003F0000

#define ATI_TCL_DIRTY_TEX_CONTROL   0x00400000
#define ATI_TCL_DIRTY_LIGHT_CONTROL 0x00800000

#define ATI_TCL_DIRTY_WVP0          0x01000000
#define ATI_TCL_DIRTY_WVP1          0x02000000
#define ATI_TCL_DIRTY_WVP2          0x04000000
#define ATI_TCL_DIRTY_WVP3          0x08000000
#define ATI_TCL_DIRTY_WVP_ALL       0x0F000000

#define ATI_TCL_DIRTY_WV_INVWV0     0x10000000
#define ATI_TCL_DIRTY_WV_INVWV1     0x20000000
#define ATI_TCL_DIRTY_WV_INVWV2     0x40000000
#define ATI_TCL_DIRTY_WV_INVWV3     0x80000000
#define ATI_TCL_DIRTY_WV_INVWV_ALL  0xF0000000

#define ATI_TCL_DIRTY_ALL      ( ATI_TCL_DIRTY_CONTROL       |     \
                                 ATI_TCL_DIRTY_MISC          |     \
                                 ATI_TCL_DIRTY_UCP           |     \
                                 ATI_TCL_DIRTY_MATERIAL      |     \
                                 ATI_TCL_DIRTY_AMBIENT       |     \
                                 ATI_TCL_DIRTY_LIGHT_ALL     |     \
                                 ATI_TCL_DIRTY_PROJECTION    |     \
                                 ATI_TCL_DIRTY_WVP_ALL       |     \
                                 ATI_TCL_DIRTY_WV_INVWV_ALL  |     \
                                 ATI_TCL_DIRTY_TEXMAT_ALL    |     \
                                 ATI_TCL_DIRTY_TEX_CONTROL   |     \
                                 ATI_TCL_DIRTY_LIGHT_CONTROL |     \
                                 ATI_TCL_DIRTY_VIEWPORT      )

#define ATI_TCL_DIRTY_W0            0x00000001
#define ATI_TCL_DIRTY_W32           0x00000001

#define ATI_TCL_NOT_READY_UCP0         0x00000004
#define ATI_TCL_NOT_READY_UCP1         0x00000008
#define ATI_TCL_NOT_READY_UCP2         0x00000010
#define ATI_TCL_NOT_READY_UCP3         0x00000020
#define ATI_TCL_NOT_READY_UCP4         0x00000040
#define ATI_TCL_NOT_READY_UCP5         0x00000080
#define ATI_TCL_NOT_READY_UCP_ALL      0x000000FC

#define ATI_TCL_NOT_READY_VP           0x00400000
#define ATI_TCL_NOT_READY_INVVP        0x00800000

#define ATI_TCL_NOT_READY_WVP0         ATI_TCL_DIRTY_WVP0
#define ATI_TCL_NOT_READY_WVP1         ATI_TCL_DIRTY_WVP1
#define ATI_TCL_NOT_READY_WVP2         ATI_TCL_DIRTY_WVP2
#define ATI_TCL_NOT_READY_WVP3         ATI_TCL_DIRTY_WVP3
#define ATI_TCL_NOT_READY_WVP_ALL      ATI_TCL_DIRTY_WVP_ALL

#define ATI_TCL_NOT_READY_WV_INVWV0    ATI_TCL_DIRTY_WV_INVWV0
#define ATI_TCL_NOT_READY_WV_INVWV1    ATI_TCL_DIRTY_WV_INVWV1
#define ATI_TCL_NOT_READY_WV_INVWV2    ATI_TCL_DIRTY_WV_INVWV2
#define ATI_TCL_NOT_READY_WV_INVWV3    ATI_TCL_DIRTY_WV_INVWV3
#define ATI_TCL_NOT_READY_WV_INVWV_ALL ATI_TCL_DIRTY_WV_INVWV_ALL

#define ATI_TCL_NOT_READY_ALL        ( ATI_TCL_NOT_READY_VP           |   \
                                       ATI_TCL_NOT_READY_INVVP        |   \
                                       ATI_TCL_NOT_READY_UCP_ALL      |   \
                                       ATI_TCL_DIRTY_LIGHT_ALL        |   \
                                       ATI_TCL_NOT_READY_WVP_ALL      |   \
                                       ATI_TCL_NOT_READY_WV_INVWV_ALL )


#define ATI_TCL_LIGHT_SCA_NOT_READY_0     ATI_TCL_DIRTY_LIGHT0
#define ATI_TCL_LIGHT_SCA_NOT_READY_1     ATI_TCL_DIRTY_LIGHT1
#define ATI_TCL_LIGHT_SCA_NOT_READY_2     ATI_TCL_DIRTY_LIGHT2
#define ATI_TCL_LIGHT_SCA_NOT_READY_3     ATI_TCL_DIRTY_LIGHT3
#define ATI_TCL_LIGHT_SCA_NOT_READY_4     ATI_TCL_DIRTY_LIGHT4
#define ATI_TCL_LIGHT_SCA_NOT_READY_5     ATI_TCL_DIRTY_LIGHT5
#define ATI_TCL_LIGHT_SCA_NOT_READY_6     ATI_TCL_DIRTY_LIGHT6
#define ATI_TCL_LIGHT_SCA_NOT_READY_7     ATI_TCL_DIRTY_LIGHT7
#define ATI_TCL_LIGHT_SCA_NOT_READY_ALL   ATI_TCL_DIRTY_LIGHT_ALL


#define ATI_TCL_LIGHT_COLOR_DIRTY_0     ATI_TCL_DIRTY_LIGHT0
#define ATI_TCL_LIGHT_COLOR_DIRTY_1     ATI_TCL_DIRTY_LIGHT1
#define ATI_TCL_LIGHT_COLOR_DIRTY_2     ATI_TCL_DIRTY_LIGHT2
#define ATI_TCL_LIGHT_COLOR_DIRTY_3     ATI_TCL_DIRTY_LIGHT3
#define ATI_TCL_LIGHT_COLOR_DIRTY_4     ATI_TCL_DIRTY_LIGHT4
#define ATI_TCL_LIGHT_COLOR_DIRTY_5     ATI_TCL_DIRTY_LIGHT5
#define ATI_TCL_LIGHT_COLOR_DIRTY_6     ATI_TCL_DIRTY_LIGHT6
#define ATI_TCL_LIGHT_COLOR_DIRTY_7     ATI_TCL_DIRTY_LIGHT7
#define ATI_TCL_LIGHT_COLOR_DIRTY_ALL   ATI_TCL_DIRTY_LIGHT_ALL


#define ATI_TCL_ENABLED_LIGHT0         ATI_TCL_DIRTY_LIGHT0
#define ATI_TCL_ENABLED_LIGHT1         ATI_TCL_DIRTY_LIGHT1
#define ATI_TCL_ENABLED_LIGHT2         ATI_TCL_DIRTY_LIGHT2
#define ATI_TCL_ENABLED_LIGHT3         ATI_TCL_DIRTY_LIGHT3
#define ATI_TCL_ENABLED_LIGHT4         ATI_TCL_DIRTY_LIGHT4
#define ATI_TCL_ENABLED_LIGHT5         ATI_TCL_DIRTY_LIGHT5
#define ATI_TCL_ENABLED_LIGHT6         ATI_TCL_DIRTY_LIGHT6
#define ATI_TCL_ENABLED_LIGHT7         ATI_TCL_DIRTY_LIGHT7
#define ATI_TCL_ENABLED_LIGHT_ALL      ATI_TCL_DIRTY_LIGHT_ALL


#define ATI_TCL_ENABLED_UCP0           ATI_TCL_NOT_READY_UCP0
#define ATI_TCL_ENABLED_UCP1           ATI_TCL_NOT_READY_UCP1
#define ATI_TCL_ENABLED_UCP2           ATI_TCL_NOT_READY_UCP2
#define ATI_TCL_ENABLED_UCP3           ATI_TCL_NOT_READY_UCP3
#define ATI_TCL_ENABLED_UCP4           ATI_TCL_NOT_READY_UCP4
#define ATI_TCL_ENABLED_UCP5           ATI_TCL_NOT_READY_UCP5
#define ATI_TCL_ENABLED_UCP_ALL        ATI_TCL_NOT_READY_UCP_ALL


#define ATID3DCLIPPLANES_SUPPORTED ( D3DCLIPPLANE0 | \
                                     D3DCLIPPLANE1 | \
                                     D3DCLIPPLANE2 | \
                                     D3DCLIPPLANE3 | \
                                     D3DCLIPPLANE4 | \
                                     D3DCLIPPLANE5 )

#define SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_ALL ( SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_0 | \
                                                 SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_1 | \
                                                 SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_2 | \
                                                 SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_3 | \
                                                 SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_4 | \
                                                 SE_TCL_UCP_VTX_BLEND_CNTL__UCP_ENA_5 )

#define ATI_TCL_OUTFVF_DEPTH                   0x80000000
#define ATI_TCL_OUTFVF_W                       0x00000001
#define ATI_TCL_OUTFVF_DIFFUSE                 0x00000008
#define ATI_TCL_OUTFVF_SPECULAR                0x00000040
#define ATI_TCL_OUTFVF_TEX_ST0                 0x00000080
#define ATI_TCL_OUTFVF_TEX_Q0                  0x00004000
#define ATI_TCL_OUTFVF_TEX_ST1                 0x00000100
#define ATI_TCL_OUTFVF_TEX_Q1                  0x00000200
#define ATI_TCL_OUTFVF_TEX_ST2                 0x00000400
#define ATI_TCL_OUTFVF_TEX_Q2                  0x00000800
// See Note above
#define ATI_TCL_OUTFVF_USES_COLORARG_DIFFUSE   0
#define ATI_TCL_OUTFVF_USES_COLORARG_SPECULAR  0
#define ATI_TCL_OUTFVF_USES_ALPHAARG_DIFFUSE   0
#define ATI_TCL_OUTFVF_USES_ALPHAARG_SPECULAR  0
#define ATI_TCL_OUTFVF_USES_FOG                0
#define ATI_TCL_OUTFVF_USES_SPECULAR           0


#define ATI_TCL_OUTFVF_TEX_ALL                (ATI_TCL_OUTFVF_TEX_ST0 | \
                                               ATI_TCL_OUTFVF_TEX_Q0  | \
                                               ATI_TCL_OUTFVF_TEX_ST1 | \
                                               ATI_TCL_OUTFVF_TEX_Q1  | \
                                               ATI_TCL_OUTFVF_TEX_ST2 | \
                                               ATI_TCL_OUTFVF_TEX_Q2      )

#define ATI_TCL_OUTFVF_USES_TEX_ARGS_DIFFUSE  (ATI_TCL_OUTFVF_USES_COLORARG_DIFFUSE  | \
                                               ATI_TCL_OUTFVF_USES_ALPHAARG_DIFFUSE      )

#define ATI_TCL_OUTFVF_USES_TEX_ARGS_SPECULAR (ATI_TCL_OUTFVF_USES_COLORARG_SPECULAR  | \
                                               ATI_TCL_OUTFVF_USES_ALPHAARG_SPECULAR     )

#define ATI_TCL_OUTFVF_USES_TEX_ARGS          (ATI_TCL_OUTFVF_USES_TEX_ARGS_DIFFUSE  | \
                                               ATI_TCL_OUTFVF_USES_TEX_ARGS_SPECULAR      )


#define ATI_PVS_DIRTY_BITS_MASK                (ATI_TCL_DIRTY_CONTROL       | \
                                                ATI_TCL_DIRTY_UCP           | \
                                                ATI_TCL_DIRTY_LIGHT_CONTROL | \
                                                ATI_TCL_DIRTY_VIEWPORT )


#define ATI_TCL_LMC_LIGHTING_ENA                0x00000001
#define ATI_TCL_LMC_LIGHTING_IN_MODEL           0x00000002
#define ATI_TCL_LMC_LOCAL_VIEWER                0x00000004
#define ATI_TCL_LMC_NORMALIZE_NORMAL            0x00000008
#define ATI_TCL_LMC_RESCALE_NORMAL              0x00000010
#define ATI_TCL_LMC_SPECULAR_ENA                0x00000020
#define ATI_TCL_LMC_DIFFUSE_SPECULAR_COMBINE    0x00000040
#define ATI_TCL_LMC_ALPHA_LIGHTING              0x00000080
#define ATI_TCL_LMC_LOC_LIGHT_W_SCALE_SUB       0x00000100
#define ATI_TCL_LMC_NO_NORMAL_DO_AMB_ONLY       0x00000200
#define ATI_TCL_LMC_WAIT_ON_CLIP_DIS            0x00008000
#define ATI_TCL_LMC_CLIP_DBL_BUF_ENA            0x00010000
#define ATI_TCL_LMC_CLIP_DISABLE                0x00000000   // this doesn't exist in R200

#define ATI_TCL_LMC_ALL_FLAGS                  (ATI_TCL_LMC_LIGHTING_ENA | \
                                                ATI_TCL_LMC_LIGHTING_IN_MODEL | \
                                                ATI_TCL_LMC_LOCAL_VIEWER | \
                                                ATI_TCL_LMC_NORMALIZE_NORMAL | \
                                                ATI_TCL_LMC_RESCALE_NORMAL | \
                                                ATI_TCL_LMC_SPECULAR_ENA | \
                                                ATI_TCL_LMC_DIFFUSE_SPECULAR_COMBINE | \
                                                ATI_TCL_LMC_ALPHA_LIGHTING | \
                                                ATI_TCL_LMC_LOC_LIGHT_W_SCALE_SUB | \
                                                ATI_TCL_LMC_NO_NORMAL_DO_AMB_ONLY | \
                                                ATI_TCL_LMC_CLIP_DBL_BUF_ENA | \
                                                ATI_TCL_LMC_CLIP_DISABLE | \
                                                ATI_TCL_LMC_WAIT_ON_CLIP_DIS )

////////////////////////////////////////////////////////////////////////
// Tweening Flags
////////////////////////////////////////////////////////////////////////
#define ATI_TCL_TWEENING_ENABLED 0x00000001
#define ATI_TCL_TWEENING_FVF     0x00000002
#define ATI_TCL_TWEENING_RHW1    0x00000004
#define ATI_TCL_TWEENING_NORMAL1 0x00000008


////////////////////////////////////////////////////////////////////////
// Per Vertex Matrix Select Flags
////////////////////////////////////////////////////////////////////////
#define ATI_TCL_PVMS_ENABLED            0x00000001
#define ATI_TCL_PVMS_USE_PROJ_MTX       0x00000010
#define ATI_TCL_PVMS_ZERO_WEIGHTS       0x00000100
#define ATI_TCL_PVMS_ITWV_NEED          0x00001000
#define ATI_TCL_DIRTY_PVMS              0x10000000

#define ATI_TCL_PMVS_MAX_VTX_BLND_MTX_IDX   57 // single buf, 64-6=58, no normal
#define ATI_TCL_PVMS_SBSE_MAX_MTX_IDX       28 // single buf, 64-6=58, normal, mv+itmv,29 per set
#define ATI_TCL_PVMS_MAX_MTX_IDX            7  // double buf, 22-6=16, normal, mv+itmv, 8 per set

#define ATI_TCL_PVMS_SBSE_MAX_MTX_IDX_M2C   18 // single buf, 64-6=58, normal, mv+itmv+m2c,19 per set
#define ATI_TCL_PVMS_MAX_MTX_IDX_M2C        4  // double buf, 22-6=16, normal, mv+itmv+m2c, 5 per set


////////////////////////////////////////////////////////////////////////
// Point Sprite Flags
////////////////////////////////////////////////////////////////////////
#define ATI_TCL_PTSPR_ENABLED                 0x00000001
#define ATI_TCL_PTSPR_PER_VTX_PSIZE           0x00000010
#define ATI_TCL_PTSPR_COMPUTE_PSIZE           0x00000100
#define ATI_TCL_PTSPR_TEX_NO_FVF              0x00000200

#define ATI_TCL_PTSPR_DIRTY_VP_SCALE          0x00001000
#define ATI_TCL_PTSPR_DIRTY_ST_SZ_MUL_CONST   0x00010000
#define ATI_TCL_PTSPR_DIRTY_ATT_CONST         0x00100000
#define ATI_TCL_PTSPR_DIRTY_CLAMP             0x01000000

#define ATI_TCL_DIRTY_PTSPR                   0x10000000


#define ATI_TCL_TCI_CAMERASPACENORMAL           10
#define ATI_TCL_TCI_CAMERASPACEPOSITION         9
#define ATI_TCL_TCI_CAMERASPACEREFLECTIONVECTOR 11

#define ATI_REEVALUTE_FVF 0x00000001

#define ATI_PI   3.141592654f
#define ATI_LIGHT_CONE_EPSILON (0.001f * ATI_PI / 180.f)

#define ATI_LIGHT_INDEX_MASK 0x000003FF


// AtiProcessDirtyTclState is called from writerenderstate
extern void AtiProcessDirtyTclState( LPATID3DCNTX pCtxt );


extern void InitTclState( LPATID3DCNTX pCtxt );
extern void AtiSetMatrixCmdHeaders( LPATID3DCNTX pCtxt );
extern void AtiSetWVMatrixCmdHeaders( LPATID3DCNTX pCtxt,
                                 LPATIMATRIX_cmd pMvMatrixCmd,
                                 LPATIMATRIX_cmd pItMvMatrixCmd, DWORD dwMatrixIndex );
extern void AtiSetWVPMatrixCmdHeaders( LPATID3DCNTX pCtxt, LPATIMATRIX_cmd pM2cMatrixCmd,
                                 DWORD dwMatrixIndex );
extern void TclComputeWVMatrix( LPATID3DCNTX pCtxt, DWORD dwMatrixIndex );
extern void TclComputeWVPMatrix( LPATID3DCNTX pCtxt, DWORD dwMatrixIndex );
extern void TclComputeWVMatrix_NO_ITWV( LPATID3DCNTX pCtxt, DWORD dwMatrixIndex );
extern HRESULT AtiSetTransform( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *ppCmd );

extern HRESULT AtiMultiplyTransform( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *ppCmd );

extern HRESULT AtiSetViewport( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *ppCmd );
extern HRESULT AtiSetZrange( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *ppCmd );
extern HRESULT AtiSetMaterial( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *ppCmd );
extern HRESULT AtiSetLight( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *ppCmd );
extern HRESULT AtiSetUserClipPlane( LPATID3DCNTX pCtxt, LPD3DHAL_DP2COMMAND *ppCmd );

extern void AtiComputeViewportRegisters( LPATID3DCNTX pCtxt );


extern VOID R200TclSetVtxProcMode(LPATID3DCNTX pCtxt);


__inline void AtiSetTclCullFlag( LPATID3DCNTX pCtxt )
{
    LPD3DDEVICE lpD3DDev = (LPD3DDEVICE)GetD3DDevice(pCtxt);
    DWORD dwOldTclFlags = pCtxt->dwTclFlags;

    pCtxt->dwTclFlags &= ~ATI_TCLFLAG_TCLCULLING;

    // If TCL culling is enabled, and we have an untransformed FVF type...
    if (pCtxt->dwTclFlags & ATI_TCLFLAG_TCLCULLING_ENABLED)
    {
        if ((pCtxt->eVtxProcMode == E_VTXPROCMODE_HW_FF) &&
            (lpD3DDev->AtiD3dRegistry.bClipDisable == FALSE) &&
            (lpD3DDev->AtiD3dRegistry.dwClipOptimizations == 0))
        {
            if( pCtxt->dwTclFlags & ATI_TCLFLAG_TCLCULLING_FORCED )
            { // TCL culling is forced on whenever possible
                pCtxt->dwTclFlags |= ATI_TCLFLAG_TCLCULLING;
            }
            else if( pCtxt->ATIStateList[D3DRENDERSTATE_LIGHTING] && pCtxt->dwTclLightStatus )
            {
                D3DHAL_DP2OPERATION dpOp = pCtxt->dpLastPrimitiveType;

                if( pCtxt->dwNumLights > 3ul || ( pCtxt->dwNumLocalLights ) )
                {
                    pCtxt->dwTclFlags |= ATI_TCLFLAG_TCLCULLING;
                }
                else if( ( dpOp == D3DDP2OP_TRIANGLELIST ) &&
                    ( pCtxt->dwTclFlags & ATI_TCLFLAG_OPSINEYE ) )
                {
                    pCtxt->dwTclFlags |= ATI_TCLFLAG_TCLCULLING;
                }
            }
        }
    }


    if( dwOldTclFlags != pCtxt->dwTclFlags )
    {
        pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_CONTROL;
        pCtxt->dwCntxDirtyMask |= SE_CNTL_DIRTY;
    }
}


//
// AtiEnableTcl enables hardware fixed function TCL vertex processing
__inline void AtiEnableTcl( LPATID3DCNTX pCtxt )
{

  if (pCtxt->eVtxProcMode != E_VTXPROCMODE_HW_FF)
  {

    // Set the vertex processing mode to hardware fixed function TCL
    pCtxt->eVtxProcMode = E_VTXPROCMODE_HW_FF;
    pCtxt->dwCntxDirtyMask |= VTX_PROC_MODE_DIRTY;

    // Dirty the TCL state since TCL is now enabled
    pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_CONTROL;

  }

  if ((!ISCurrVSDeclHandleZero(pCtxt)) && (!IsPureFVFandNoPVS(pCtxt)))
  {
    LPATIVTXSHADER pVtxShader = VS_GetShader(pCtxt);
    if (pVtxShader && pVtxShader->dwCodeLength > 0)
    {
      pCtxt->eVtxProcMode = E_VTXPROCMODE_HW_PVS;
      pCtxt->dwCntxDirtyMask |= VTX_PROC_MODE_DIRTY;
    }
  }

  // Enable TCL PointSprite Routine
  pCtxt->RenderOnePointSprite = RenderOnePointSpriteFromVertexTCL;
}

//
// AtiDisableTcl sets the vertex processing mode to software (a.k.a. non-TCL)
__inline void AtiDisableTcl( LPATID3DCNTX pCtxt )
{
  if (pCtxt->eVtxProcMode != E_VTXPROCMODE_SW)
  {
    // Set the vertex processing mode to hardware fixed function TCL
    pCtxt->eVtxProcMode = E_VTXPROCMODE_SW;
    pCtxt->dwCntxDirtyMask |= VTX_PROC_MODE_DIRTY;
  }

  // Enable SW PointSprite Routine
  pCtxt->RenderOnePointSprite = RenderOnePointSpriteFromVertexSW;
}

__inline void AtiCheckOperationsInEye( LPATID3DCNTX pCtxt )
{
  //This if tests all the things that would force model lighting.
#ifdef ATI_TCL_FORCE_EYE_LIGHTING

  // If lighting is on or if tex coord gen is on, we have ops in eye.
  if( pCtxt->ATIStateList[D3DRENDERSTATE_LIGHTING]   ||  // is lighting on?
      pCtxt->dwTCLTexCoordGenSpace                   ||  // txt coord gen?
      (pCtxt->dwPointSpriteFlags & ATI_TCL_PTSPR_ENABLED))   // using hw pointsprites?
  { pCtxt->dwTclFlags |= ATI_TCLFLAG_OPSINEYE; }
  else
  { pCtxt->dwTclFlags &= ~ATI_TCLFLAG_OPSINEYE; }

  pCtxt->tclControl.lightingCtrl.bitfields.LIGHTING_IN_MODEL = 0;
  if( pCtxt->dwTclNotReadyFlags & ATI_TCL_NOT_READY_WV_INVWV_ALL )
  {
    pCtxt->dwTclDirtyFlags |= pCtxt->dwTclLightStatus;
    pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_WV_INVWV_ALL; // send the recalc'ed values to the card
    pCtxt->llLightNotReadyCount++;
  }

  AtiSetTclCullFlag( pCtxt );
#else
  LPD3DDEVICE lpD3DDev = (LPD3DDEVICE)GetD3DDevice(pCtxt);

  if( pCtxt->ATIStateList[D3DRENDERSTATE_LIGHTING] )
  {
    if( pCtxt->dwVertexBlendWeightCnt                               ||  // is vertex blending on?
        ( (pCtxt->dwIdxVtxBlndFlags & ATI_TCL_PVMS_ENABLED) &&
          (pCtxt->dwIdxVtxBlndFlags & ATI_TCL_PVMS_ZERO_WEIGHTS) )  ||
        pCtxt->dwTCLTexCoordGenSpace                                ||  // txt coord gen?
        pCtxt->dwNumLocalLights                                     ||  // any local lights?
        (pCtxt->dwTclLMCFlags & ATI_TCL_LMC_LOCAL_VIEWER)           ||  // local viewer
        ( pCtxt->ATIStateList[D3DRENDERSTATE_FOGENABLE] &&              // fog enabled
          pCtxt->ATIStateList[ D3DRENDERSTATE_FOGVERTEXMODE ] )     ||  // vertex fog on
        (pCtxt->dwPointSpriteFlags & ATI_TCL_PTSPR_ENABLED)         ||  // using hw pointsprites?
        ((pCtxt->dwTclLMCFlags & ATI_TCL_LMC_NORMALIZE_NORMAL) == 0)
      )
    {
      pCtxt->dwTclFlags |= ATI_TCLFLAG_OPSINEYE;

      if(lpD3DDev->AtiD3dRegistry.dwIsTclVertexBlendUseProjMtxEnabled)
      {
          set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_use_proj_mtx(  &pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl, 1);
      }

      if( pCtxt->dwTclLMCFlags & ATI_TCL_LMC_LIGHTING_IN_MODEL )
      {
        pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_LIGHT_CONTROL | pCtxt->dwTclLightStatus;
        pCtxt->llLightNotReadyCount++;
        pCtxt->dwTclLMCFlags &= ~ATI_TCL_LMC_LIGHTING_IN_MODEL;
        pCtxt->dwTclLMCFlags &= ~ATI_TCL_LMC_RESCALE_NORMAL;
        AtiSetTclCullFlag( pCtxt );
      }
      else if( pCtxt->dwTclNotReadyFlags & ATI_TCL_NOT_READY_WV_INVWV_ALL )
      {
        pCtxt->dwTclDirtyFlags |= pCtxt->dwTclLightStatus;    // this is taken care of in AtiSetXfrm
        pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_WV_INVWV_ALL; // send the recalc'ed values to the card
        pCtxt->llLightNotReadyCount++;

        if( pCtxt->dwTclLMCFlags & ATI_TCL_LMC_RESCALE_NORMAL )
        {
          pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_LIGHT_CONTROL | ATI_TCL_DIRTY_MISC;
          pCtxt->dwTclLMCFlags &= ~ATI_TCL_LMC_RESCALE_NORMAL;
        }
      }
    }
    else
    {
      pCtxt->dwTclFlags &= ~ATI_TCLFLAG_OPSINEYE;

      set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_use_proj_mtx(  &pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl, 0);

      if( (pCtxt->dwTclLMCFlags & ATI_TCL_LMC_LIGHTING_IN_MODEL) == 0 )
      {
        pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_LIGHT_CONTROL | pCtxt->dwTclLightStatus;
        pCtxt->llLightNotReadyCount++;
        pCtxt->dwTclLMCFlags |= ATI_TCL_LMC_LIGHTING_IN_MODEL;
        if( (pCtxt->mWorld[0].dwFlags & ATIMATRIX_SCALING) ||  // is the world matrix strange?
            (pCtxt->mView.dwFlags & ATIMATRIX_SCALING) )       // is the view matrix strange?
        {
          pCtxt->dwTclLMCFlags |= ATI_TCL_LMC_RESCALE_NORMAL;
          pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_MISC;
        }
        AtiSetTclCullFlag( pCtxt );
      }
      else if( pCtxt->dwTclNotReadyFlags & ATI_TCL_NOT_READY_WVP0 )
      { 
        pCtxt->dwTclDirtyFlags |= pCtxt->dwTclLightStatus;  // this is taken care of in AtiSetXfrm
        pCtxt->llLightNotReadyCount++;
        if( (pCtxt->mWorld[0].dwFlags & ATIMATRIX_SCALING) ||  // is the world matrix strange?
            (pCtxt->mView.dwFlags & ATIMATRIX_SCALING) )       // is the view matrix strange?
        {
          pCtxt->dwTclLMCFlags |= ATI_TCL_LMC_RESCALE_NORMAL;
          pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_LIGHT_CONTROL | ATI_TCL_DIRTY_MISC;
        }
      }
    }
  }
  else
  {
    if( pCtxt->dwTCLTexCoordGenSpace                          || // txt coord gen?
        pCtxt->ATIStateList[ D3DRENDERSTATE_FOGVERTEXMODE ]   || // vertex fog
       (pCtxt->dwPointSpriteFlags & ATI_TCL_PTSPR_ENABLED))         // using hw pointsprites?
    {
      pCtxt->dwTclFlags |= ATI_TCLFLAG_OPSINEYE;
      if(lpD3DDev->AtiD3dRegistry.dwIsTclVertexBlendUseProjMtxEnabled)
      {
          set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_use_proj_mtx(  &pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl, 1);
      }
    }
    else
    {
      set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_use_proj_mtx(  &pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl, 0);
      pCtxt->dwTclFlags &= ~ATI_TCLFLAG_OPSINEYE;
    }

    AtiSetTclCullFlag( pCtxt );
  }

#endif
}

/////////////////////////////////////////////////////////////////////////////
// TclSetupVertexWorldMatrix
/////////////////////////////////////////////////////////////////////////////
__inline VOID TclSetupVertexWorldMatrix( LPATID3DCNTX pCtxt, DWORD dwMatrixIndex, D3DMATRIX *pMat)
{
  LPD3DDEVICE     lpD3DDev=GetD3DDevice(pCtxt);
  LPVOID          lpATIDXObj = GetATIDeviceInfo(lpD3DDev);
  LPATIMATRIX     pWMatrix;

  pWMatrix = AL_GetEntry( &pCtxt->alWorld_MatrixList, dwMatrixIndex );

  if (pWMatrix == NULL)
  {
    if (!(pWMatrix = AL_GetNewEntry( lpATIDXObj, &pCtxt->alWorld_MatrixList, dwMatrixIndex )))
      return;
  }

  CopyD3dToAtiMatrix(pWMatrix, pMat);
  if (dwMatrixIndex == 0)
  SetScalingAttibutes( pWMatrix );

  pCtxt->dwPvmsMtxDirtyFlagsLo |= (ATI_TCL_DIRTY_W0 << dwMatrixIndex);

  if (dwMatrixIndex > pCtxt->dwMaxWorldMatrixIndex)
  { pCtxt->dwMaxWorldMatrixIndex = dwMatrixIndex; }
}


/////////////////////////////////////////////////////////////////////////////
// TclMultiplyVertexWorldMatrix
/////////////////////////////////////////////////////////////////////////////
__inline VOID TclMultiplyVertexWorldMatrix( LPATID3DCNTX pCtxt, DWORD dwMatrixIndex, D3DMATRIX *pMat)
{
  LPD3DDEVICE     lpD3DDev=GetD3DDevice(pCtxt);
  LPVOID          lpATIDXObj = GetATIDeviceInfo(lpD3DDev);
  LPATIMATRIX     pWMatrix;
  ATIMATRIX       mNewMatrix;

  pWMatrix = AL_GetEntry( &pCtxt->alWorld_MatrixList, dwMatrixIndex );
  if (pWMatrix == NULL)
  {
    if (!(pWMatrix = AL_GetNewEntry( lpATIDXObj, &pCtxt->alWorld_MatrixList, dwMatrixIndex )))
      return;

    AtiMatrixIdentity( pWMatrix );
  }

  CopyD3dToAtiMatrix(&(mNewMatrix), pMat);
  MatrixProductSafe( pWMatrix, &mNewMatrix, pWMatrix );

  if (dwMatrixIndex == 0)
  SetScalingAttibutes( pWMatrix );

  pCtxt->dwPvmsMtxDirtyFlagsLo |= (ATI_TCL_DIRTY_W0 << dwMatrixIndex);

  if (dwMatrixIndex > pCtxt->dwMaxWorldMatrixIndex)
  { pCtxt->dwMaxWorldMatrixIndex = dwMatrixIndex; }
}

_inline void AtiDeriveNearFarFromProjXfrm( LPATID3DCNTX pCtxt,
                                           D3DMATRIX *pMat )
{
    float q = pMat->_33;  // q = far / ( far - near )
    float r = pMat->_43;  // r = -q * near
    float s = pMat->_34;  // s = 1 for W-friendly proj matrix
    float fOldWNear = pCtxt->fWNear;
    float fOldWFar = pCtxt->fWFar;

    if ( s != 0.0f )
    {
        q = q / s;
        r = r / s;

        if ( q != 0.0f )
            pCtxt->fWNear = ( -r / q ) * s;

        if ( ( 1 - q ) != 0.0f )
            pCtxt->fWFar = ( r / ( 1 - q ) ) * s;
    }
}


/////////////////////////////////////////////////////////////////////////////
// AtiSetXfrm
/////////////////////////////////////////////////////////////////////////////
__inline void AtiSetXfrm( LPATID3DCNTX pCtxt, D3DTRANSFORMSTATETYPE xfrmType, D3DMATRIX *pMat)
{

  LPD3DDEVICE         lpD3DDev=GetD3DDevice(pCtxt);
  LPVOID              lpATIDXObj = GetATIDeviceInfo(lpD3DDev);

  BOOL bSetIdentity = (xfrmType & 0x80000000) != 0;
  DWORD dwxfrmType = (DWORD)xfrmType & (~0x80000000);
  switch (dwxfrmType)
  {
  case D3DTRANSFORMSTATE_WORLD_DX7:
  case D3DTS_WORLD:
    if( CopyAndClassifyD3dToAtiMatrix(&(pCtxt->mWorld[0]), pMat) )
    { // If the new matrix was not equal to the old...
      SetScalingAttibutes( &pCtxt->mWorld[0] );
      pCtxt->dwTclDirtyFlags    |= ATI_TCL_DIRTY_WVP0     | ATI_TCL_DIRTY_WV_INVWV0;
      pCtxt->dwTclNotReadyFlags |= ATI_TCL_NOT_READY_WVP0 | ATI_TCL_NOT_READY_WV_INVWV0;
      // Must check AtiCheckOperationsInEye
      AtiCheckOperationsInEye( pCtxt );
    }
    if( dwxfrmType == D3DTS_WORLD )
    {
      TclSetupVertexWorldMatrix( pCtxt, 0, pMat );
    }
    break;
  case D3DTRANSFORMSTATE_VIEW:
    if( CopyAndClassifyD3dToAtiMatrix(&pCtxt->mView, pMat) )
    { // If the new matrix was not equal to the old...
      SetScalingAttibutes( &pCtxt->mView );
      pCtxt->dwTclDirtyFlags    |= ATI_TCL_DIRTY_WVP_ALL     | ATI_TCL_DIRTY_WV_INVWV_ALL;
      if( pCtxt->dwTclUcpStatus )
      {
          pCtxt->dwTclDirtyFlags    |= ATI_TCL_DIRTY_WVP_ALL;
          pCtxt->dwTclNotReadyFlags |= pCtxt->dwTclUcpStatus;
      }
      pCtxt->dwTclNotReadyFlags |= ATI_TCL_NOT_READY_WVP_ALL | ATI_TCL_NOT_READY_WV_INVWV_ALL |
                                   ATI_TCL_NOT_READY_VP | ATI_TCL_NOT_READY_INVVP |
                                   ATI_TCL_NOT_READY_UCP_ALL;
      pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_UCP;

      // Must check AtiCheckOperationsInEye
      AtiCheckOperationsInEye( pCtxt );
    }
    break;
  case D3DTRANSFORMSTATE_PROJECTION:
    {

      CopyAndClassifyD3dToAtiMatrix(&pCtxt->mProjCmd.mat, pMat);

    // If W-buffering in use, calculate W parameters from this projectiong matrix
    if ( GetZEnable(pCtxt) == D3DZB_USEW )
        AtiDeriveNearFarFromProjXfrm(pCtxt, pMat);

      // We don't want (or really need) to worry about it's type, so let's just
      // be conservative at this point (at least we know it's not identity).
      pCtxt->mProjCmd.mat.dwFlags = ATIMATRIX_SCALING | ATIMATRIX_NONUNIFORM_SCALING;

    }

    if (lpD3DDev->AtiD3dRegistry.bTclVpScaleInProj)
    {
      // Bury the viewport scale in the projection matrix
      LPATIMATRIX pmProj = &pCtxt->mProjCmd.mat;
      ATIMATRIX mOldProj = *pmProj;
      float fXS =  0.5f * (D3DVALUE)pCtxt->atiViewport.dwWidth;
      float fYS = -0.5f * (D3DVALUE)pCtxt->atiViewport.dwHeight;
      ATIMATRIX mViewScale =  { fXS, 0.f, 0.f, 0.f,
                                0.f, fYS, 0.f, 0.f,
                                0.f, 0.f, 1.f, 0.f,
                                0.f, 0.f, 0.f, 1.f };
      MatrixProduct( pmProj, &mOldProj, &mViewScale );
    }

    // Save off a copy of the D3D version of the matrix for capture
    SaveD3dMatrix(&pCtxt->mD3dProjMatrix, pMat);


    pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_PROJECTION | ATI_TCL_DIRTY_WVP_ALL;
    if( pCtxt->dwTclUcpStatus )
    {
        pCtxt->dwTclDirtyFlags    |= ATI_TCL_DIRTY_WVP_ALL;
        pCtxt->dwTclNotReadyFlags |= pCtxt->dwTclUcpStatus;
    }
    pCtxt->dwTclNotReadyFlags |= ATI_TCL_NOT_READY_WVP_ALL |
                                 ATI_TCL_NOT_READY_VP | ATI_TCL_NOT_READY_INVVP |
                                 ATI_TCL_NOT_READY_UCP_ALL;
    pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_UCP;
    break;
  case D3DTRANSFORMSTATE_WORLD1_DX7:
  case D3DTS_WORLD1:

    if( CopyAndClassifyD3dToAtiMatrix(&(pCtxt->mWorld[1]), pMat) )
    { // If the new matrix was not equal to the old...
      pCtxt->dwTclDirtyFlags    |= ATI_TCL_DIRTY_WVP1     | ATI_TCL_DIRTY_WV_INVWV1;
      pCtxt->dwTclNotReadyFlags |= ATI_TCL_NOT_READY_WVP1 | ATI_TCL_NOT_READY_WV_INVWV1;
    }
    if( dwxfrmType == D3DTS_WORLD1 )
    {
      TclSetupVertexWorldMatrix( pCtxt, 1, pMat );
    }
    break;
  case D3DTRANSFORMSTATE_WORLD2_DX7:
  case D3DTS_WORLD2:
    if( CopyAndClassifyD3dToAtiMatrix(&(pCtxt->mWorld[2]), pMat) )
    { // If the new matrix was not equal to the old...
      pCtxt->dwTclDirtyFlags    |= ATI_TCL_DIRTY_WVP2     | ATI_TCL_DIRTY_WV_INVWV2;
      pCtxt->dwTclNotReadyFlags |= ATI_TCL_NOT_READY_WVP2 | ATI_TCL_NOT_READY_WV_INVWV2;
    }
    if( dwxfrmType == D3DTS_WORLD2 )
    {
      TclSetupVertexWorldMatrix( pCtxt, 2, pMat );
    }
    break;
  case D3DTRANSFORMSTATE_WORLD3_DX7:
  case D3DTS_WORLD3:
    if( CopyAndClassifyD3dToAtiMatrix(&(pCtxt->mWorld[3]), pMat) )
    { // If the new matrix was not equal to the old...
      pCtxt->dwTclDirtyFlags    |= ATI_TCL_DIRTY_WVP3     | ATI_TCL_DIRTY_WV_INVWV3;
      pCtxt->dwTclNotReadyFlags |= ATI_TCL_NOT_READY_WVP3 | ATI_TCL_NOT_READY_WV_INVWV3;
    }
    if( dwxfrmType == D3DTS_WORLD3 )
    {
      TclSetupVertexWorldMatrix( pCtxt, 3, pMat );
    }
    break;
  case D3DTRANSFORMSTATE_TEXTURE0:
  case D3DTRANSFORMSTATE_TEXTURE1:
  case D3DTRANSFORMSTATE_TEXTURE2:
  case D3DTRANSFORMSTATE_TEXTURE3:
  case D3DTRANSFORMSTATE_TEXTURE4:
  case D3DTRANSFORMSTATE_TEXTURE5:
  case D3DTRANSFORMSTATE_TEXTURE6:
  case D3DTRANSFORMSTATE_TEXTURE7:
    {
      DWORD dwStage = xfrmType - D3DTRANSFORMSTATE_TEXTURE0;
      if (bSetIdentity)
      {
        D3dMatrixIdentity( &pCtxt->d3dTxMatrix[dwStage]);
      }
      else
      {
        SaveD3dMatrix(&pCtxt->d3dTxMatrix[dwStage], pMat);
      }

      if (dwStage < ATI_RAD2_NUM_TEX_UNITS)
      {
        CopyD3dToAtiMatrix(&pCtxt->mTextureCmd[dwStage].mat, pMat);
        if (dwStage < 3)
          pCtxt->dwTclDirtyFlags |= (ATI_TCL_DIRTY_TEXMAT0 << dwStage);
        else
          pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_TEXMAT_ALL;
        pCtxt->dwDxFvfDirtyFlags = ATI_REEVALUTE_FVF;
      }
    }
    break;
  default:
    {
      DWORD dwMatrixIndex = dwxfrmType - D3DTS_WORLD;

      if (dwxfrmType > D3DTS_WORLD3)
      {
        LPATIMATRIX pAtiMatrix;

        pAtiMatrix = AL_GetEntry( &pCtxt->alWorld_MatrixList, dwMatrixIndex );

        if (pAtiMatrix == NULL)
        {
          pAtiMatrix = AL_GetNewEntry( lpATIDXObj, &pCtxt->alWorld_MatrixList, dwMatrixIndex );
        }

        if( pAtiMatrix &&
            CopyAndClassifyD3dToAtiMatrix(pAtiMatrix, pMat) )
        {
          if (dwMatrixIndex < 32)
            pCtxt->dwPvmsMtxDirtyFlagsLo |= (ATI_TCL_DIRTY_W0 << dwMatrixIndex );
          else
            pCtxt->dwPvmsMtxDirtyFlagsHi |= (ATI_TCL_DIRTY_W32 << (dwMatrixIndex-32) );

          if (dwMatrixIndex > pCtxt->dwMaxWorldMatrixIndex)
          {
            pCtxt->dwMaxWorldMatrixIndex = dwMatrixIndex;
          }
        }
      }
    }
  }
}


/////////////////////////////////////////////////////////////////////////////
// AtiMultiplyXfrm
/////////////////////////////////////////////////////////////////////////////
__inline void AtiMultiplyXfrm( LPATID3DCNTX pCtxt, D3DTRANSFORMSTATETYPE xfrmType, D3DMATRIX *pMat)
{

  LPD3DDEVICE         lpD3DDev=GetD3DDevice(pCtxt);
  LPVOID              lpATIDXObj = GetATIDeviceInfo(lpD3DDev);

  DWORD dwxfrmType = (DWORD)xfrmType & (~0x80000000);
  switch (dwxfrmType)
  {
  case D3DTRANSFORMSTATE_WORLD_DX7:
  case D3DTS_WORLD:
    {
      ATIMATRIX mNewMatrix;

      CopyD3dToAtiMatrix(&(mNewMatrix), pMat);

      MatrixProductSafe( &(pCtxt->mWorld[0]), &mNewMatrix, &(pCtxt->mWorld[0]) );

      SetScalingAttibutes( &pCtxt->mWorld[0] );
      pCtxt->dwTclDirtyFlags    |= ATI_TCL_DIRTY_WVP0     | ATI_TCL_DIRTY_WV_INVWV0;
      pCtxt->dwTclNotReadyFlags |= ATI_TCL_NOT_READY_WVP0 | ATI_TCL_NOT_READY_WV_INVWV0;
      // Must check AtiCheckOperationsInEye
      AtiCheckOperationsInEye( pCtxt );

      if( dwxfrmType == D3DTS_WORLD )
      {
        TclMultiplyVertexWorldMatrix( pCtxt, 0, pMat );
      }
    }
    break;

  case D3DTRANSFORMSTATE_VIEW:
    {
      ATIMATRIX mNewMatrix;

      CopyD3dToAtiMatrix(&(mNewMatrix), pMat);

      MatrixProductSafe( &(pCtxt->mView), &mNewMatrix, &(pCtxt->mView) );

      SetScalingAttibutes( &pCtxt->mView );
      pCtxt->dwTclDirtyFlags    |= ATI_TCL_DIRTY_WVP_ALL     | ATI_TCL_DIRTY_WV_INVWV_ALL;
      if( pCtxt->dwTclUcpStatus )
      {
          pCtxt->dwTclDirtyFlags    |= ATI_TCL_DIRTY_WVP_ALL;
          pCtxt->dwTclNotReadyFlags |= pCtxt->dwTclUcpStatus;
      }
      pCtxt->dwTclNotReadyFlags |= ATI_TCL_NOT_READY_WVP_ALL | ATI_TCL_NOT_READY_WV_INVWV_ALL |
                                   ATI_TCL_NOT_READY_VP | ATI_TCL_NOT_READY_INVVP |
                                   ATI_TCL_NOT_READY_UCP_ALL;
      pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_UCP;

      // Must check AtiCheckOperationsInEye
      AtiCheckOperationsInEye( pCtxt );
    }
    break;

  case D3DTRANSFORMSTATE_PROJECTION:
    {
      ATIMATRIX mNewMatrix;

      CopyD3dToAtiMatrix(&(mNewMatrix), pMat);

      MatrixProductSafe( &pCtxt->mProjCmd.mat, &mNewMatrix, &pCtxt->mProjCmd.mat );

      // Save off a copy of the D3D version of the matrix for capture
      CopyAtiToD3dMatrix(&pCtxt->mD3dProjMatrix, &pCtxt->mProjCmd.mat);

      // If W-buffering in use, calculate W parameters from this projectiong matrix
      if ( GetZEnable(pCtxt) == D3DZB_USEW )
        AtiDeriveNearFarFromProjXfrm(pCtxt, &pCtxt->mD3dProjMatrix);

      pCtxt->mProjCmd.mat.dwFlags = ATIMATRIX_SCALING | ATIMATRIX_NONUNIFORM_SCALING;

      if (lpD3DDev->AtiD3dRegistry.bTclVpScaleInProj)
      {
        // Bury the viewport scale in the projection matrix
        LPATIMATRIX pmProj = &pCtxt->mProjCmd.mat;
        ATIMATRIX mOldProj = *pmProj;
        float fXS =  0.5f * (D3DVALUE)pCtxt->atiViewport.dwWidth;
        float fYS = -0.5f * (D3DVALUE)pCtxt->atiViewport.dwHeight;
        ATIMATRIX mViewScale =  { fXS, 0.f, 0.f, 0.f,
                                  0.f, fYS, 0.f, 0.f,
                                  0.f, 0.f, 1.f, 0.f,
                                  0.f, 0.f, 0.f, 1.f };
        MatrixProduct( pmProj, &mOldProj, &mViewScale );
      }

      pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_PROJECTION | ATI_TCL_DIRTY_WVP_ALL;
      if( pCtxt->dwTclUcpStatus )
      {
          pCtxt->dwTclDirtyFlags    |= ATI_TCL_DIRTY_WVP_ALL;
          pCtxt->dwTclNotReadyFlags |= pCtxt->dwTclUcpStatus;
      }
      pCtxt->dwTclNotReadyFlags |= ATI_TCL_NOT_READY_WVP_ALL |
                                   ATI_TCL_NOT_READY_VP | ATI_TCL_NOT_READY_INVVP |
                                   ATI_TCL_NOT_READY_UCP_ALL;
      pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_UCP;
    }
    break;

  case D3DTRANSFORMSTATE_WORLD1_DX7:
  case D3DTS_WORLD1:
    {
      ATIMATRIX mNewMatrix;

      CopyD3dToAtiMatrix(&(mNewMatrix), pMat);

      MatrixProductSafe( &(pCtxt->mWorld[1]), &mNewMatrix, &(pCtxt->mWorld[1]) );

      pCtxt->dwTclDirtyFlags    |= ATI_TCL_DIRTY_WVP1     | ATI_TCL_DIRTY_WV_INVWV1;
      pCtxt->dwTclNotReadyFlags |= ATI_TCL_NOT_READY_WVP1 | ATI_TCL_NOT_READY_WV_INVWV1;

      if( dwxfrmType == D3DTS_WORLD1 )
      {
        TclMultiplyVertexWorldMatrix( pCtxt, 1, pMat );
      }
    }
    break;

  case D3DTRANSFORMSTATE_WORLD2_DX7:
  case D3DTS_WORLD2:
    {
      ATIMATRIX mNewMatrix;

      CopyD3dToAtiMatrix(&(mNewMatrix), pMat);

      MatrixProductSafe( &(pCtxt->mWorld[2]),&mNewMatrix, &(pCtxt->mWorld[2]) );

      pCtxt->dwTclDirtyFlags    |= ATI_TCL_DIRTY_WVP2     | ATI_TCL_DIRTY_WV_INVWV2;
      pCtxt->dwTclNotReadyFlags |= ATI_TCL_NOT_READY_WVP2 | ATI_TCL_NOT_READY_WV_INVWV2;

      if( dwxfrmType == D3DTS_WORLD2 )
      {
        TclMultiplyVertexWorldMatrix( pCtxt, 2, pMat );
      }
    }
    break;

  case D3DTRANSFORMSTATE_WORLD3_DX7:
  case D3DTS_WORLD3:
    {
      ATIMATRIX mNewMatrix;

      CopyD3dToAtiMatrix(&(mNewMatrix), pMat);

      MatrixProductSafe( &(pCtxt->mWorld[3]),&mNewMatrix , &(pCtxt->mWorld[3]) );

      pCtxt->dwTclDirtyFlags    |= ATI_TCL_DIRTY_WVP3     | ATI_TCL_DIRTY_WV_INVWV3;
      pCtxt->dwTclNotReadyFlags |= ATI_TCL_NOT_READY_WVP3 | ATI_TCL_NOT_READY_WV_INVWV3;

      if( dwxfrmType == D3DTS_WORLD3 )
      {
        TclMultiplyVertexWorldMatrix( pCtxt, 3, pMat );
      }
    }
    break;

  case D3DTRANSFORMSTATE_TEXTURE0:
  case D3DTRANSFORMSTATE_TEXTURE1:
  case D3DTRANSFORMSTATE_TEXTURE2:
  case D3DTRANSFORMSTATE_TEXTURE3:
  case D3DTRANSFORMSTATE_TEXTURE4:
  case D3DTRANSFORMSTATE_TEXTURE5:
  case D3DTRANSFORMSTATE_TEXTURE6:
  case D3DTRANSFORMSTATE_TEXTURE7:
    {
      ATIMATRIX mNewMatrix;
      DWORD dwStage = xfrmType - D3DTRANSFORMSTATE_TEXTURE0;

      CopyD3dToAtiMatrix(&(mNewMatrix), pMat);

      if (dwStage < ATI_RAD2_NUM_TEX_UNITS)
      {
        MatrixProductSafe( &pCtxt->mTextureCmd[dwStage].mat, &mNewMatrix , &pCtxt->mTextureCmd[dwStage].mat );
        CopyAtiToD3dMatrix(&pCtxt->d3dTxMatrix[dwStage], &pCtxt->mTextureCmd[dwStage].mat );
        if (dwStage < 3)
          pCtxt->dwTclDirtyFlags |= (ATI_TCL_DIRTY_TEXMAT0 << dwStage);
        else
          pCtxt->dwTclDirtyFlags |= ATI_TCL_DIRTY_TEXMAT_ALL;
        pCtxt->dwDxFvfDirtyFlags = ATI_REEVALUTE_FVF;
      }
    }
    break;

  default:
    {
      DWORD dwMatrixIndex = dwxfrmType - D3DTS_WORLD;

      if (dwxfrmType > D3DTS_WORLD3)
      {
        LPATIMATRIX pAtiMatrix;
        ATIMATRIX mNewMatrix;

        pAtiMatrix = AL_GetEntry( &pCtxt->alWorld_MatrixList, dwMatrixIndex );
        if (pAtiMatrix == NULL)
        {
          if (!(pAtiMatrix = AL_GetNewEntry( lpATIDXObj, &pCtxt->alWorld_MatrixList, dwMatrixIndex )))
            return;

          AtiMatrixIdentity( pAtiMatrix );
        }

        CopyD3dToAtiMatrix(&(mNewMatrix), pMat);
        MatrixProductSafe( pAtiMatrix, &mNewMatrix, pAtiMatrix );

        if (dwMatrixIndex < 32)
          pCtxt->dwPvmsMtxDirtyFlagsLo |= (ATI_TCL_DIRTY_W0 << dwMatrixIndex );
        else
          pCtxt->dwPvmsMtxDirtyFlagsHi |= (ATI_TCL_DIRTY_W32 << (dwMatrixIndex-32) );

        if (dwMatrixIndex > pCtxt->dwMaxWorldMatrixIndex)
        {
          pCtxt->dwMaxWorldMatrixIndex = dwMatrixIndex;
        }
      }
    }
  }
}

__inline void SetTclHwCaps( LPD3DDEVICE lpD3DDev, D3DDEVICEDESC_V1 *pHwCaps )
{

  if( ! (lpD3DDev->AtiD3dRegistry.bIsTclEnabled) )
  {
    return;
  }

  pHwCaps->dwFlags   |= 0
                     |  D3DDD_TRANSFORMCAPS
                     |  D3DDD_LIGHTINGCAPS
                     |  D3DDD_BCLIPPING
                        ;
  pHwCaps->dwDevCaps |= D3DDEVCAPS_HWTRANSFORMANDLIGHT;

  pHwCaps->dtcTransformCaps.dwSize = sizeof(D3DTRANSFORMCAPS);
  pHwCaps->dtcTransformCaps.dwCaps = D3DTRANSFORMCAPS_CLIP;

  pHwCaps->bClipping = TRUE;

  pHwCaps->dlcLightingCaps.dwSize = sizeof(D3DLIGHTINGCAPS);
  pHwCaps->dlcLightingCaps.dwLightingModel = 0ul
                                           | D3DLIGHTINGMODEL_RGB
                                             ;
  pHwCaps->dlcLightingCaps.dwNumLights = 0;
  pHwCaps->dlcLightingCaps.dwCaps = 0
                                  | D3DLIGHTCAPS_POINT
                                  | D3DLIGHTCAPS_SPOT
                                  | D3DLIGHTCAPS_DIRECTIONAL
                                    ;
  pHwCaps->dpcLineCaps.dwRasterCaps |= D3DPRASTERCAPS_FOGRANGE;
  pHwCaps->dpcTriCaps.dwRasterCaps  |= D3DPRASTERCAPS_FOGRANGE;
}

__inline void SetTclExtendedCaps( D3DHAL_D3DEXTENDEDCAPS *pExtendedHwCaps, LPD3DDEVICE lpD3DDev )
{

  if( !(lpD3DDev->AtiD3dRegistry.bIsTclEnabled) )
  {
    return;
  }

  pExtendedHwCaps->dwMaxActiveLights = ATI_NUM_LIGHTS;
  //pExtendedHwCaps->dwMaxActiveLights = 0xffffffff;
  {
    pExtendedHwCaps->wMaxUserClipPlanes = ATI_NUM_CLIP_PLANES;
  }
  pExtendedHwCaps->wMaxVertexBlendMatrices =
      (WORD)lpD3DDev->AtiD3dRegistry.dwMaxMatrixBlend;

  pExtendedHwCaps->dwVertexProcessingCaps = 0 |
                D3DVTXPCAPS_TEXGEN            |
                D3DVTXPCAPS_MATERIALSOURCE7   |
                D3DVTXPCAPS_DIRECTIONALLIGHTS |
                D3DVTXPCAPS_POSITIONALLIGHTS  |
                D3DVTXPCAPS_LOCALVIEWER       |
                D3DVTXPCAPS_VERTEXFOG;
}


//////////////////////////////////////////////////////////////////////////////////
//
//   AtiComputeVertexSize - Compute the size of vertex given it's FVF
//
//////////////////////////////////////////////////////////////////////////////////
__inline DWORD AtiComputeVertexSize( DWORD dwDxFvfType )
{ // Has the vertex format changed from last time?
    DWORD dwDxVtxSize; // xyz
    DWORD dwVertexType = dwDxFvfType & D3DFVF_POSITION_MASK;

    DWORD dwTexCnt = 0;
    DWORD dwTexCoordSets, dwCoordSize;
    DWORD i;

    // Check for bogus reserved bits
    BOOL b0 = dwDxFvfType & (D3DFVF_RESERVED0 | D3DFVF_RESERVED2);
    // Normals are not allowed with untransformed vertices.
    BOOL b1 = (dwVertexType == D3DFVF_XYZRHW) &&
        ((dwDxFvfType & D3DFVF_NORMAL) || (dwDxFvfType & D3DFVF_RESERVED1));

    if ( b0 | b1 )
    { return 0; }

    switch( dwVertexType )
    {
    case D3DFVF_XYZ:
      dwDxVtxSize = 3 * sizeof(D3DVALUE);
      break;
    case D3DFVF_XYZRHW:
      dwDxVtxSize = 4 * sizeof(D3DVALUE);
      break;
    case D3DFVF_XYZB1:
      dwDxVtxSize = 4 * sizeof(D3DVALUE);
      break;
    case D3DFVF_XYZB2:
      dwDxVtxSize = 5 * sizeof(D3DVALUE);
      break;
    case D3DFVF_XYZB3:
      dwDxVtxSize = 6 * sizeof(D3DVALUE);
      break;
    case D3DFVF_XYZB4:
    case D3DFVF_XYZB5:
    default:
      return 0;
      break;
    }

    if( dwDxFvfType & D3DFVF_RESERVED1 )
    { // Lit, untransformed verticies may reserve space for RHW
      dwDxVtxSize += sizeof(D3DVALUE);
    }

    if( dwDxFvfType & D3DFVF_NORMAL )
    {
      dwDxVtxSize += 3 * sizeof(D3DVALUE);
    }

    if (dwDxFvfType & D3DFVF_DIFFUSE)
    {
      dwDxVtxSize += sizeof(D3DCOLOR);
    }
    if (dwDxFvfType & D3DFVF_SPECULAR)
    {
      dwDxVtxSize  += sizeof(D3DCOLOR);
    }

    //
    // Determine how much components per texture coord set
    // and tack this on to dwSysVertexSize

    // Determine how many texture coordinate sets there are
    dwTexCoordSets = (dwDxFvfType & D3DFVF_TEXCOUNT_MASK) >> D3DFVF_TEXCOUNT_SHIFT;

    dwCoordSize = dwDxFvfType & 0xffff0000;
    for (i=0; i < dwTexCoordSets; i++)
    {
      // D3DFVF_TEXCOORDSIZE1(i) masks the appropriate two bits of
      // the coord set in question
      DWORD dwCoordSizeTest = dwCoordSize & (DWORD)D3DFVF_TEXCOORDSIZE1(i);

      if (dwCoordSizeTest == (DWORD)D3DFVF_TEXCOORDSIZE1(i))
      { dwTexCnt += sizeof(D3DVALUE); }
      else if (dwCoordSizeTest == (DWORD)D3DFVF_TEXCOORDSIZE2(i))
      { dwTexCnt += (2*sizeof(D3DVALUE)); }
      else if (dwCoordSizeTest == (DWORD)D3DFVF_TEXCOORDSIZE3(i))
      { dwTexCnt += (3*sizeof(D3DVALUE)); }
      else // D3DFVF_TEXCOORDSIZE4(i)
      { dwTexCnt += (4* sizeof(D3DVALUE)); }
    }

    dwDxVtxSize += dwTexCnt;

  return dwDxVtxSize;
}

//////////////////////////////////////////////////////////////////////////////////
//
//   pdwSetTweenFactor - Send down 2 degenerate triangles with the tween factor
//                       in the blend weight field
//
//////////////////////////////////////////////////////////////////////////////////
__inline LPDWORD pdwSetTweenFactor(LPATID3DCNTX pCtxt, LPDWORD pdwPm4)
{
    // x,y and 1 blend weight are present
    DWORD dwTweenFVFType = FLEXIBLE_B1;
    DWORD dwNumVertices = 12;
    regSE_VAP_CNTL         SeVapCntl_reg;

    DWORD dwTempSize = SIZE_OF_PRIM_HEADER + dwNumVertices * 3;  // 3 dwords per vert, 18 total
    DWORD pdwDegenerateTriangles[] = {
                                      0x3f800000, 0x3f800000, pCtxt->dwTweenFactor,
                                      0x3f800000, 0x3f800000, pCtxt->dwTweenFactor,
                                      0x3f800000, 0x3f800000, pCtxt->dwTweenFactor,
                                      0x3f800000, 0x3f800000, pCtxt->dwTweenFactor,
                                      0x3f800000, 0x3f800000, pCtxt->dwTweenFactor,
                                      0x3f800000, 0x3f800000, pCtxt->dwTweenFactor,
                                      0x3f800000, 0x3f800000, pCtxt->dwTweenFactor,
                                      0x3f800000, 0x3f800000, pCtxt->dwTweenFactor,
                                      0x3f800000, 0x3f800000, pCtxt->dwTweenFactor,
                                      0x3f800000, 0x3f800000, pCtxt->dwTweenFactor,
                                      0x3f800000, 0x3f800000, pCtxt->dwTweenFactor,
                                      0x3f800000, 0x3f800000, pCtxt->dwTweenFactor
                                     };
    regSE_TCL_UCP_VTX_BLEND_CNTL *pReg = &pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl;

    // we need to change SE_VTX_FMT_X in Chaplin because the SE_VTX_FMT in the PM4 packets
    // are not valid for Chaplin
    *pdwPm4++ = mmSE_VTX_FMT_0;
    *pdwPm4++ = 0x00000004;     // just send X,Y,B0
    *pdwPm4++ = mmSE_VTX_FMT_1;
    *pdwPm4++ = 0x00000000;

    *pdwPm4++ = mmSE_TCL_STATE_FLUSH_REG;
    *pdwPm4++ = 0;

    SeVapCntl_reg = pCtxt->SeVapCntl_reg;
    set_SE_VAP_CNTL_tcl_ena(&SeVapCntl_reg, 1);
    *pdwPm4++ = mmSE_VAP_CNTL;
    *pdwPm4++ = SeVapCntl_reg.u32All;

    // Turn off blending
    set_SE_TCL_UCP_VTX_BLEND_CNTL_use_st_blend_op_cnt(pReg, 0);
    set_SE_TCL_UCP_VTX_BLEND_CNTL_blend_op_cnt(pReg, 0);
    set_SE_TCL_UCP_VTX_BLEND_CNTL_position_blend_operation(pReg, 0);
    set_SE_TCL_UCP_VTX_BLEND_CNTL_normal_blend_operation(pReg, 0);
    set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_0(pReg, 0);
    set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_1(pReg, 0);
    memcpy(pdwPm4, &pCtxt->tclR2MiscControlCmd, sizeof(ATITCLRAD2MISCCONTROL_cmd) );
    pdwPm4 += sizeof(ATITCLRAD2MISCCONTROL_cmd)>>2;

    // Send the degenerate triangles
    *pdwPm4++ = OpRender3DDrawIMMD(dwTempSize);
    *pdwPm4++ = dwTweenFVFType;                                              // PM4_VC_FORMAT
    *pdwPm4++ = D3D_VF_CNTL_COMMON       | VF_CNTL_PRIM_TYPE_TRIANGLE_LIST | // SE_VF_CNTL
                    VF_CNTL_PRIM_WALK_VERTEX_DATA | (dwNumVertices << 16) |
                    SE_VF_CNTL__TCL_OUTPUT_CTL_ENA;

    memcpy(pdwPm4, pdwDegenerateTriangles, (dwNumVertices*3) << 2);
    pdwPm4 += dwNumVertices*3;


    // Reset the blending state
    if (pCtxt->ATIStateList[D3DRENDERSTATE_VERTEXBLEND] == D3DVBF_TWEENING)
    {
        // Vertex tweening
        set_SE_TCL_UCP_VTX_BLEND_CNTL_use_st_blend_op_cnt(pReg, 1);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_blend_op_cnt(pReg, 1);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_position_blend_operation(pReg, 1);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_normal_blend_operation(pReg, 1);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_0(pReg, 1);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_1(pReg, 0);
    }
    else
    {
        if (pCtxt->dwVertexBlendWeightCnt > 0)
        {
          // Vertex Skinning
          set_SE_TCL_UCP_VTX_BLEND_CNTL_blend_op_cnt(pReg, pCtxt->dwVertexBlendWeightCnt);
          set_SE_TCL_UCP_VTX_BLEND_CNTL_position_blend_operation(pReg, 1);
          set_SE_TCL_UCP_VTX_BLEND_CNTL_normal_blend_operation(pReg, 1);
          set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_0(pReg, 0);
          set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_1(pReg, 0);
        }
        else
        {
          // No skinning or tweening
          set_SE_TCL_UCP_VTX_BLEND_CNTL_blend_op_cnt(pReg, 0);
          set_SE_TCL_UCP_VTX_BLEND_CNTL_position_blend_operation(pReg, 0);
          set_SE_TCL_UCP_VTX_BLEND_CNTL_normal_blend_operation(pReg, 0);
          set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_0(pReg, 0);
          set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_1(pReg, 0);
        }
    }
    // Reset the FVF
    *pdwPm4++ = mmSE_VTX_FMT_0;
    *pdwPm4++ = pCtxt->SeVtxFmt0_reg.u32All;
    *pdwPm4++ = mmSE_VTX_FMT_1;
    *pdwPm4++ = pCtxt->SeVtxFmt1_reg.u32All;

    *pdwPm4++ = mmSE_TCL_STATE_FLUSH_REG;
    *pdwPm4++ = 0;
    *pdwPm4++ = mmSE_VAP_CNTL;
    *pdwPm4++ = pCtxt->SeVapCntl_reg.u32All;

    memcpy(pdwPm4, &pCtxt->tclR2MiscControlCmd, sizeof(ATITCLRAD2MISCCONTROL_cmd) );
    pdwPm4 += sizeof(ATITCLRAD2MISCCONTROL_cmd)>>2;


    return pdwPm4;
}

//////////////////////////////////////////////////////////////////////////////////
//
//   CheckTweeningForFF - Set-up per context flags, dirty mask via
//   PVS stream tweening flags for handling FF vertex tweening.
//
//////////////////////////////////////////////////////////////////////////////////
__inline VOID CheckTweeningForFF(LPATID3DCNTX pCtxt, LPATIVTXSHADER pAtiVertexShader)
{
  if(pAtiVertexShader->dwFlags & VS_TWEENING_ENABLED)
  {
    pCtxt->dwTweeningFlags &= ~(ATI_TCL_TWEENING_FVF|ATI_TCL_TWEENING_RHW1|ATI_TCL_TWEENING_NORMAL1);
    // Let ProcesFVF know we have a tweening vert
    pCtxt->dwTweeningFlags |= ATI_TCL_TWEENING_FVF;
    // use transformed verts if provided
    if(pAtiVertexShader->dwFlags & VS_RHW1_ENABLED)
    {
      pCtxt->dwTweeningFlags |= ATI_TCL_TWEENING_RHW1;
    }
    // Use 2nd normal if it is provided
    if(pAtiVertexShader->dwFlags & VS_NORMAL1_ENABLED)
    {
      pCtxt->dwTweeningFlags |= ATI_TCL_TWEENING_NORMAL1;
    }
    // This will seed the HW with the proper tween factor
    pCtxt->dwCntxDirtyMask |= VBPNTR_DIRTY;
    pCtxt->dwDxFvfDirtyFlags = ATI_REEVALUTE_FVF;
  }
  else
  {
    pCtxt->dwTweeningFlags &= ~(ATI_TCL_TWEENING_FVF|ATI_TCL_TWEENING_RHW1|ATI_TCL_TWEENING_NORMAL1);
    pCtxt->dwDxFvfDirtyFlags = ATI_REEVALUTE_FVF;
  }
}

//////////////////////////////////////////////////////////////////////////////////
//
//   pdwSeedZeroBlendWeight - Send down 2 degenerate triangles with the 1
//                       in the blend weight field
//
//////////////////////////////////////////////////////////////////////////////////
__inline LPDWORD pdwSeedZeroBlendWeight(LPATID3DCNTX pCtxt, LPDWORD pdwPm4)
{
    // x,y and 1 blend weight are present
    DWORD dwPvms0WtFVFType = FLEXIBLE_B1;

    DWORD dwNumVertices = 12;
    regSE_VAP_CNTL         SeVapCntl_reg;

    DWORD dwTempSize = SIZE_OF_PRIM_HEADER + dwNumVertices * 3;  // 3 dwords per vert
    DWORD pdwDegenerateTriangles[] = {
                                      0x3f800000, 0x3f800000, 0x3f800000,
                                      0x3f800000, 0x3f800000, 0x3f800000,
                                      0x3f800000, 0x3f800000, 0x3f800000,
                                      0x3f800000, 0x3f800000, 0x3f800000,
                                      0x3f800000, 0x3f800000, 0x3f800000,
                                      0x3f800000, 0x3f800000, 0x3f800000,
                                      0x3f800000, 0x3f800000, 0x3f800000,
                                      0x3f800000, 0x3f800000, 0x3f800000,
                                      0x3f800000, 0x3f800000, 0x3f800000,
                                      0x3f800000, 0x3f800000, 0x3f800000,
                                      0x3f800000, 0x3f800000, 0x3f800000,
                                      0x3f800000, 0x3f800000, 0x3f800000,
                                     };

    regSE_TCL_UCP_VTX_BLEND_CNTL *pReg = &pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl;

    *pdwPm4++ = mmSE_VTX_FMT_0;
    *pdwPm4++ = 0x00000004;     // send X,Y,B0
    *pdwPm4++ = mmSE_VTX_FMT_1;
    *pdwPm4++ = 0x00000000;

    *pdwPm4++ = mmSE_TCL_STATE_FLUSH_REG;
    *pdwPm4++ = 0;

    SeVapCntl_reg = pCtxt->SeVapCntl_reg;
    set_SE_VAP_CNTL_tcl_ena(&SeVapCntl_reg, 1);
    *pdwPm4++ = mmSE_VAP_CNTL;
    *pdwPm4++ = SeVapCntl_reg.u32All;

    // Turn off blending
    set_SE_TCL_UCP_VTX_BLEND_CNTL_use_st_blend_op_cnt(pReg, 0);
    set_SE_TCL_UCP_VTX_BLEND_CNTL_blend_op_cnt(pReg, 0);
    set_SE_TCL_UCP_VTX_BLEND_CNTL_position_blend_operation(pReg, 0);
    set_SE_TCL_UCP_VTX_BLEND_CNTL_normal_blend_operation(pReg, 0);
    set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_0(pReg, 0);
    set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_1(pReg, 0);
    memcpy(pdwPm4, &pCtxt->tclR2MiscControlCmd, sizeof(ATITCLRAD2MISCCONTROL_cmd) );
    pdwPm4 += sizeof(ATITCLRAD2MISCCONTROL_cmd)>>2;

    // Send the degenerate triangles
    *pdwPm4++ = OpRender3DDrawIMMD(dwTempSize);
    *pdwPm4++ = dwPvms0WtFVFType;                                              // PM4_VC_FORMAT
    *pdwPm4++ = D3D_VF_CNTL_COMMON       | VF_CNTL_PRIM_TYPE_TRIANGLE_LIST | // SE_VF_CNTL
                VF_CNTL_PRIM_WALK_VERTEX_DATA | (dwNumVertices << 16) |
                SE_VF_CNTL__TCL_OUTPUT_CTL_ENA;

    memcpy(pdwPm4, pdwDegenerateTriangles, (dwNumVertices*3) << 2);
    pdwPm4 += dwNumVertices*3;

    // Reset the blending state
    if (pCtxt->dwVertexBlendWeightCnt > 0)
    {
        // Vertex Skinning
        set_SE_TCL_UCP_VTX_BLEND_CNTL_blend_op_cnt(pReg, pCtxt->dwVertexBlendWeightCnt);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_position_blend_operation(pReg, 1);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_normal_blend_operation(pReg, 1);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_0(pReg, 0);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_1(pReg, 0);
    }
    else
    {
        // No skinning or tweening
        if( (pCtxt->dwIdxVtxBlndFlags & ATI_TCL_PVMS_ENABLED) &&
            (pCtxt->dwIdxVtxBlndFlags & ATI_TCL_PVMS_ZERO_WEIGHTS) )
        {
            // PVMS with zero weight
            set_SE_TCL_UCP_VTX_BLEND_CNTL_blend_op_cnt(pReg, 1);
            set_SE_TCL_UCP_VTX_BLEND_CNTL_use_st_blend_op_cnt(pReg, 1);

            set_SE_TCL_UCP_VTX_BLEND_CNTL_position_blend_operation(pReg, 1);
            set_SE_TCL_UCP_VTX_BLEND_CNTL_normal_blend_operation(pReg, 1);
            set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_0(pReg, 0);
            set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_1(pReg, 0);
        }
        else
        {
            set_SE_TCL_UCP_VTX_BLEND_CNTL_blend_op_cnt(pReg, 0);
            set_SE_TCL_UCP_VTX_BLEND_CNTL_position_blend_operation(pReg, 0);
            set_SE_TCL_UCP_VTX_BLEND_CNTL_normal_blend_operation(pReg, 0);
            set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_0(pReg, 0);
            set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_1(pReg, 0);
        }
    }

    // Reset the FVF
    *pdwPm4++ = mmSE_VTX_FMT_0;
    *pdwPm4++ = pCtxt->SeVtxFmt0_reg.u32All;
    *pdwPm4++ = mmSE_VTX_FMT_1;
    *pdwPm4++ = pCtxt->SeVtxFmt1_reg.u32All;

    *pdwPm4++ = mmSE_TCL_STATE_FLUSH_REG;
    *pdwPm4++ = 0;
    *pdwPm4++ = mmSE_VAP_CNTL;
    *pdwPm4++ = pCtxt->SeVapCntl_reg.u32All;

    memcpy(pdwPm4, &pCtxt->tclR2MiscControlCmd, sizeof(ATITCLRAD2MISCCONTROL_cmd) );
    pdwPm4 += sizeof(ATITCLRAD2MISCCONTROL_cmd)>>2;

    return pdwPm4;
}

/////////////////////////////////////////////////////////////////////////////
// TclGetPerLightControl
/////////////////////////////////////////////////////////////////////////////
__inline LPSeTclPerLightCntl TclGetPerLightCntl(LPATID3DCNTX pCtxt)
{
  LPD3DDEVICE lpD3DDev = (LPD3DDEVICE)GetD3DDevice(pCtxt);

  return pCtxt->tclR2LightControlCmd.perLightCntl;
}

/////////////////////////////////////////////////////////////////////////////
// TclSetClipDisable
/////////////////////////////////////////////////////////////////////////////
__inline VOID TclSetClipDisable(LPATID3DCNTX pCtxt)
{
    if(!((LPD3DDEVICE)GetD3DDevice(pCtxt))->AtiD3dRegistry.bClipDisable && pCtxt->ATIStateList[D3DRENDERSTATE_CLIPPING])
    {
        pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl.bitfields.CLIP_DISABLE = 0;
    }
    else
    {
        pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl.bitfields.CLIP_DISABLE = 1;
    }
}


_inline void VTEBackpressureHangAround( LPATID3DCNTX pCtxt,
                                        regSE_TCL_OUTPUT_VTX_FMT_0*  pregTclOutFmt0,
                                        regSE_TCL_OUTPUT_VTX_FMT_1*  pregTclOutFmt1
                                    )
{
    LPD3DDEVICE lpD3DDev = (LPD3DDEVICE)GetD3DDevice(pCtxt);

    if ( lpD3DDev->AtiD3dRegistry.bR200VTEBackpressureWorkAround )
    {
        DWORD dwTclOutFmt0=pregTclOutFmt0->u32All;
        DWORD dwTclOutFmt1=pregTclOutFmt1->u32All;
        DWORD dwTclOutPosMsk=SE_TCL_OUTPUT_VTX_FMT_0__VTX_Z0_PRESENT|SE_TCL_OUTPUT_VTX_FMT_0__VTX_W0_PRESENT;
        if( ((dwTclOutFmt0&~dwTclOutPosMsk)==0x0) && (dwTclOutFmt1==0) )
        {
            // less than 2 vec per vert so add color0
            set_SE_TCL_OUTPUT_VTX_FMT_0_vtx_color_0_fmt(pregTclOutFmt0,1);
        }
    }
}


/*****************************************************************************
* void DiscreteFogHangAround()
*
* Args:
*       LPATID3DCNTX                    pCtxt                context pointer
*       regSE_TCL_OUTPUT_VTX_FMT_0*     regTclOutFmt0        pointer to tcl output reg 0
*       regSE_TCL_OUTPUT_VTX_COMP_SEL*  regTclOutVtxCompSel  pointer to tcl output sel reg
*
* Returns: none
*
* Description:
*
******************************************************************************/
_inline void DiscreteFogHangAround( LPATID3DCNTX    pCtxt,
                    regSE_TCL_OUTPUT_VTX_FMT_0*     pregTclOutFmt0,
                    regSE_TCL_OUTPUT_VTX_COMP_SEL*  pregTclOutVtxCompSel
                                    )
{
  LPD3DDEVICE lpD3DDev = (LPD3DDEVICE)GetD3DDevice(pCtxt);

  if( lpD3DDev->AtiD3dRegistry.bDiscreteFogEnable == TRUE )
  {
    DWORD dwTclOutFmt0=pregTclOutFmt0->u32All;
    DWORD dwTclOutCompSel=pregTclOutVtxCompSel->u32All;

    if ( pCtxt->PpFogColor_reg.bitfields.FOG_INDEX_SEL_R2 == 4 ) // fog select vertex fog
    {
      if( ((dwTclOutFmt0&SE_TCL_OUTPUT_VTX_FMT_0__VTX_DISCRETE_FOG_PRESENT)==0x0) &&
          ((dwTclOutCompSel&SE_TCL_OUTPUT_VTX_COMP_SEL__VTX_DISCRETE_FOG_SEL)==0x0) )
      {
        pCtxt->dwCntxDirtyMask |= FOGCOLOR_DIRTY;
        set_PP_FOG_COLOR_fog_index_sel_r2( &( pCtxt->PpFogColor_reg ), 3); // fog select specular alpha
      }
    }
  }
}

_inline void Check_ITWV_Need(LPATID3DCNTX pCtxt)
{
   if( !pCtxt->ATIStateList[D3DRENDERSTATE_LIGHTING])
   {
     pCtxt->dwIdxVtxBlndFlags &= ~ATI_TCL_PVMS_ITWV_NEED;
   }
   if ( ISCurrVSDeclHandleZero(pCtxt) || IsPureFVFandNoPVS(pCtxt))
   {
     if ( pCtxt->dwDxFvfType & D3DFVF_NORMAL)
     {
        pCtxt->dwIdxVtxBlndFlags |= ATI_TCL_PVMS_ITWV_NEED;
     }
     else
     {
        pCtxt->dwIdxVtxBlndFlags &= ~ATI_TCL_PVMS_ITWV_NEED;
     }
   }
   else
   {
      if ( (VS_GetShader(pCtxt)->dwFlags) & VS_NORMAL0_ENABLED )
      {
        pCtxt->dwIdxVtxBlndFlags |= ATI_TCL_PVMS_ITWV_NEED;
      }
      else
      {
        pCtxt->dwIdxVtxBlndFlags &= ~ATI_TCL_PVMS_ITWV_NEED;
      }
   }
}
#endif  // _TCL_STATE_H__


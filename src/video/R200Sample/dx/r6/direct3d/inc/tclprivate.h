

//    
//  Workfile: tclPrivate.h
//
//  Description: Tcl private inlines, macros, and defines 
//
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 2000 ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

// WARNING:
// This file is only to be included by TCL-related source files. If this
// file gets included elsewhere, something is wrong!

#ifndef _TCLPRIVATE_H_
#define _TCLPRIVATE_H_

__inline int FloatToFixed( float val, DWORD int_bits, DWORD frac_bits );

////////////////////////////////////////////////////////////////////////
//
// void WriteCmd
//
// This function sends a command to the indirect buffer.
//
////////////////////////////////////////////////////////////////////////
#define WriteCmd( pCtxt, pCmdIn, dwLengthInDwords )                          \
{                                                                            \
  LPDWORD pCmd = pCmdIn;                                                     \
  LPDWORD pdwEntry = GetPM4Entries(dwLengthInDwords, &pCtxt->CmdBuff);       \
  HSLASSERT (pdwEntry);                                                      \
  AtiDwordCopy( pdwEntry, pCmd, dwLengthInDwords );                          \
  SubmitPM4EntriesToHw(dwLengthInDwords, 0, &pCtxt->CmdBuff);                \
}

////////////////////////////////////////////////////////////////////////
// TclProcessVertexBlendingState
////////////////////////////////////////////////////////////////////////
__inline VOID TclProcessVertexBlendingState(LPATID3DCNTX pCtxt)
{
  // CHAPLIN_TODO: Need runtime selection instead of compile time
  regSE_TCL_UCP_VTX_BLEND_CNTL *pReg = &pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl;

  if (pCtxt->ATIStateList[D3DRENDERSTATE_VERTEXBLEND] == D3DVBF_TWEENING)
  {
    // Vertex tweening
    set_SE_TCL_UCP_VTX_BLEND_CNTL_blend_op_cnt(pReg, 1);
    set_SE_TCL_UCP_VTX_BLEND_CNTL_position_blend_operation(pReg, 1);
    set_SE_TCL_UCP_VTX_BLEND_CNTL_normal_blend_operation(pReg, 1);
    set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_0(pReg, 1);
    set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_1(pReg, 0);

    set_SE_TCL_UCP_VTX_BLEND_CNTL_use_st_blend_op_cnt(pReg, 1);
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

      if (pCtxt->ATIStateList[D3DRENDERSTATE_LIGHTING]) 
      { set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_use_proj_mtx(pReg, 1); }
      else
      { set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_use_proj_mtx(pReg, 0); }      

      set_SE_TCL_UCP_VTX_BLEND_CNTL_use_st_blend_op_cnt(pReg, 1);
    }
    else
    {
      // No skinning or tweening
      if( (pCtxt->dwIdxVtxBlndFlags & ATI_TCL_PVMS_ENABLED) &&
          (pCtxt->dwIdxVtxBlndFlags & ATI_TCL_PVMS_ZERO_WEIGHTS) )
      { 
        // PVMS with zero weight
        set_SE_TCL_UCP_VTX_BLEND_CNTL_blend_op_cnt(pReg, 1);
        
        set_SE_TCL_UCP_VTX_BLEND_CNTL_position_blend_operation(pReg, 1);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_normal_blend_operation(pReg, 1);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_0(pReg, 0);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_1(pReg, 0);    
        
        set_SE_TCL_UCP_VTX_BLEND_CNTL_use_st_blend_op_cnt(pReg, 1);
      }
      else
      {
        set_SE_TCL_UCP_VTX_BLEND_CNTL_blend_op_cnt(pReg, 0);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_position_blend_operation(pReg, 0);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_normal_blend_operation(pReg, 0);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_0(pReg, 0);
        set_SE_TCL_UCP_VTX_BLEND_CNTL_vtx_blend_src_1(pReg, 0);

        set_SE_TCL_UCP_VTX_BLEND_CNTL_use_st_blend_op_cnt(pReg, 0);
      }
    }
  }
}

////////////////////////////////////////////////////////////////////////
// TclProcessMatrixSelects
////////////////////////////////////////////////////////////////////////
__inline VOID TclProcessMatrixSelects(LPATID3DCNTX pCtxt)
{
  // CHAPLIN_TODO: Need runtime selection instead of compile time
  BOOL bTweening        = FALSE;

  regSE_TCL_MATRIX_SEL_0     *pMatrixSel0 = &pCtxt->tclR2GlobalStateCmd.matrixSel0;
  regSE_TCL_MATRIX_SEL_1     *pMatrixSel1 = &pCtxt->tclR2GlobalStateCmd.matrixSel1;
  regSE_TCL_MATRIX_SEL_2     *pMatrixSel2 = &pCtxt->tclR2GlobalStateCmd.matrixSel2;
  regSE_TCL_PER_VTX_MTX_CNTL *pPerVtxMtxCntl = &pCtxt->tclR2GlobalStateCmd.perVtxMtxCntl;  

  bTweening = (pCtxt->ATIStateList[D3DRENDERSTATE_VERTEXBLEND] == D3DVBF_TWEENING);


  if (bTweening == TRUE)
  {
    // Vertex Tweening
    set_SE_TCL_MATRIX_SEL_0_modelview_mtx_1_sel(    pMatrixSel0,  ATI_NUM_TEX_MATRICES );
    set_SE_TCL_MATRIX_SEL_1_it_modelview_mtx_1_sel( pMatrixSel1,  ATI_NUM_TEX_MATRICES + ATI_NUM_BLEND_MATRICES );
    set_SE_TCL_MATRIX_SEL_2_model2clip_mtx_1_sel(   pMatrixSel2,  ATI_NUM_TEX_MATRICES + (ATI_NUM_BLEND_MATRICES<<1) );
  }
  else
  {
    // No vertex tweening; normal operation
    set_SE_TCL_MATRIX_SEL_0_modelview_mtx_1_sel(    pMatrixSel0,  ATI_NUM_TEX_MATRICES + 1 );
    set_SE_TCL_MATRIX_SEL_1_it_modelview_mtx_1_sel( pMatrixSel1,  ATI_NUM_TEX_MATRICES + ATI_NUM_BLEND_MATRICES + 1 );
    set_SE_TCL_MATRIX_SEL_2_model2clip_mtx_1_sel(   pMatrixSel2,  ATI_NUM_TEX_MATRICES + (ATI_NUM_BLEND_MATRICES<<1) + 1 );
  }

  // Per Vertex Matrix Select
  if (pCtxt->dwIdxVtxBlndFlags & (ATI_TCL_DIRTY_PVMS|ATI_TCL_PVMS_ENABLED)) 
  {  
    if( pCtxt->dwIdxVtxBlndFlags & ATI_TCL_PVMS_USE_PROJ_MTX )
    { // use the projection path ( 2 matrices per matrix set ) 
      if (pCtxt->dwMaxWorldMatrixIndex <= ATI_TCL_PVMS_MAX_MTX_IDX)
      { // double buffer      
        set_SE_TCL_PER_VTX_MTX_CNTL_itmv_mtx_0_indx( pPerVtxMtxCntl, ATI_NUM_TEX_MATRICES+ATI_TCL_PVMS_MAX_MTX_IDX+1 ); 
      }
      else
      { // single buffer
        set_SE_TCL_PER_VTX_MTX_CNTL_itmv_mtx_0_indx( pPerVtxMtxCntl, ATI_NUM_TEX_MATRICES+ATI_TCL_PVMS_SBSE_MAX_MTX_IDX+1 );
      }
      set_SE_TCL_PER_VTX_MTX_CNTL_mv_mtx_0_indx(   pPerVtxMtxCntl, ATI_NUM_TEX_MATRICES );
      set_SE_TCL_PER_VTX_MTX_CNTL_m2c_mtx_0_indx(  pPerVtxMtxCntl, ATI_NUM_TEX_MATRICES );  
    }
    else
    { // use the Model2Clip path ( 3 matrices per matrix set ) 
      set_SE_TCL_PER_VTX_MTX_CNTL_mv_mtx_0_indx(   pPerVtxMtxCntl, ATI_NUM_TEX_MATRICES );
      if (pCtxt->dwMaxWorldMatrixIndex <= ATI_TCL_PVMS_MAX_MTX_IDX)
      { // double buffer  
        set_SE_TCL_PER_VTX_MTX_CNTL_itmv_mtx_0_indx( pPerVtxMtxCntl, ATI_NUM_TEX_MATRICES+ATI_TCL_PVMS_MAX_MTX_IDX_M2C+1 );
        set_SE_TCL_PER_VTX_MTX_CNTL_m2c_mtx_0_indx(  pPerVtxMtxCntl, ATI_NUM_TEX_MATRICES+((ATI_TCL_PVMS_MAX_MTX_IDX_M2C+1)<<1) );    
      }
      else
      { // single buffer      
        set_SE_TCL_PER_VTX_MTX_CNTL_itmv_mtx_0_indx( pPerVtxMtxCntl, ATI_NUM_TEX_MATRICES+ATI_TCL_PVMS_SBSE_MAX_MTX_IDX_M2C+1 );
        set_SE_TCL_PER_VTX_MTX_CNTL_m2c_mtx_0_indx(  pPerVtxMtxCntl, ATI_NUM_TEX_MATRICES+((ATI_TCL_PVMS_SBSE_MAX_MTX_IDX_M2C+1)<<1) );  
      }
    }
  }  

}


////////////////////////////////////////////////////////////////////////
// TclProcessCullingState
////////////////////////////////////////////////////////////////////////
__inline VOID TclProcessCullingState(LPATID3DCNTX pCtxt)
{
  // CHAPLIN_TODO: Need runtime selection instead of compile time
  DWORD dwTclCullFlags;

  if( (pCtxt->dwTclFlags & ATI_TCLFLAG_TCLCULLING) )
  { dwTclCullFlags = pCtxt->dwTclCullFlags; }
  else
  { dwTclCullFlags = ATI_TCL_CULLNONE; }

  // Process TCL culling state
  pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl.u32All &= ~ATI_TCL_CULL_MASK;
  pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl.u32All |= dwTclCullFlags;
}


////////////////////////////////////////////////////////////////////////
// TclProcessUCPState
////////////////////////////////////////////////////////////////////////
__inline VOID TclProcessUCPState(LPATID3DCNTX pCtxt)
{
    DWORD dwUcp = pCtxt->ATIStateList[D3DRENDERSTATE_CLIPPLANEENABLE] & ATID3DCLIPPLANES_SUPPORTED;

    // Is clipping enable
    if( pCtxt->ATIStateList[D3DRENDERSTATE_CLIPPING] && dwUcp )
    {
        // Only turn a UCP if clipping is enabled AND a UCP is enabled
        pCtxt->dwTclUcpStatus = (dwUcp << 2);
        pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl.u32All = 
            (pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl.u32All & ~ATI_TCL_ENABLED_UCP_ALL) | pCtxt->dwTclUcpStatus;
    }
    else
    {
        // If clipping is not enabled, turn off all the UCPs
        pCtxt->dwTclUcpStatus = 0ul;
        pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl.u32All &= ~ATI_TCL_ENABLED_UCP_ALL;
    }
}


////////////////////////////////////////////////////////////////////////
// TclProcessPointSpriteState
////////////////////////////////////////////////////////////////////////
__inline VOID TclProcessPointSpriteState(LPATID3DCNTX pCtxt)
{
    DWORD dwPntSprFlags = pCtxt->dwPointSpriteFlags;

    if ((dwPntSprFlags & ATI_TCL_DIRTY_PTSPR) &&
        (dwPntSprFlags & ATI_TCL_PTSPR_ENABLED))
    {  
        // hw point sprite  
        // setup state vector-state data commands
        
        if (dwPntSprFlags & ATI_TCL_PTSPR_DIRTY_VP_SCALE)
        {
            float fX_RadiusExp = 1/(2*(pCtxt->SeVportXScale_reg.f32All));
            float fY_RadiusExp = 1/(2*(pCtxt->SeVportYScale_reg.f32All));
            float fCullingExp  = ATI_TCL_SQRT( fX_RadiusExp*fX_RadiusExp +
                                             fY_RadiusExp*fY_RadiusExp );
 
            // In order to get the proper orientation of the texture on the pointsprite
            // The Y_Rad_Exp must be negated relative to the SE_VPORT_Y_SCALE
            pCtxt->atiPntSprVpScaleCmd.X_Rad_Exp    = fX_RadiusExp;
            pCtxt->atiPntSprVpScaleCmd.Y_Rad_Exp    = -fY_RadiusExp;
            pCtxt->atiPntSprVpScaleCmd.Cull_Rad_Exp = fCullingExp;

            if (dwPntSprFlags & ATI_TCL_PTSPR_DIRTY_ST_SZ_MUL_CONST)
            { 
                // global point size * viewport height          
                
                if (dwPntSprFlags & ATI_TCL_PTSPR_COMPUTE_PSIZE) 
                { 
                    // global point size in world space
                    
                    if (dwPntSprFlags & ATI_TCL_PTSPR_PER_VTX_PSIZE) 
                    { 
                        pCtxt->atiPntSprVpScaleCmd.St_Multiply_Const = (float)(pCtxt->d3dViewport.dwHeight);
                    } 
                    else 
                    {
                        pCtxt->atiPntSprVpScaleCmd.St_Multiply_Const = (float)(pCtxt->d3dViewport.dwHeight)*pCtxt->fPointSize;
                    }
                }
                else
                { 
                    // global point size in screen space
                    pCtxt->atiPntSprVpScaleCmd.St_Multiply_Const = pCtxt->fPointSize;
                }
                dwPntSprFlags &= ~ATI_TCL_PTSPR_DIRTY_ST_SZ_MUL_CONST;
            }       
            WriteCmd( pCtxt, (LPDWORD)&pCtxt->atiPntSprVpScaleCmd, sizeof( ATIPNTSPRVPSCALE_cmd ) >> 2 );
            dwPntSprFlags &= ~ATI_TCL_PTSPR_DIRTY_VP_SCALE; 
        }
  
        if (dwPntSprFlags & ATI_TCL_PTSPR_DIRTY_ATT_CONST)
        {
            *(DWORD*)(&(pCtxt->atiPntSprAttConstCmd.Kc)) = pCtxt->ATIStateList[D3DRS_POINTSCALE_A];
            *(DWORD*)(&(pCtxt->atiPntSprAttConstCmd.Kl)) = pCtxt->ATIStateList[D3DRS_POINTSCALE_B];
            *(DWORD*)(&(pCtxt->atiPntSprAttConstCmd.Kq)) = pCtxt->ATIStateList[D3DRS_POINTSCALE_C];
            
            if (pCtxt->bPointScaleEnable)
                WriteCmd( pCtxt, (LPDWORD)&pCtxt->atiPntSprAttConstCmd, sizeof( ATIPNTSPRATTCONST_cmd ) >> 2 );
            dwPntSprFlags &= ~ATI_TCL_PTSPR_DIRTY_ATT_CONST; 
        }

        if (dwPntSprFlags & ATI_TCL_PTSPR_DIRTY_CLAMP)
        {                                               
            set_RE_POINTSIZE_maxpointsize( &pCtxt->RePointSize_reg, pCtxt->dwFlt2FixPointSizeMax);
            set_SE_LINE_WIDTH_minpointsize( &pCtxt->SeLineWidth_reg,pCtxt->dwFlt2FixPointSizeMin);

            pCtxt->atiPntSprClampCmd.Max_Size = pCtxt->fPointSizeMax;
            pCtxt->atiPntSprClampCmd.Min_Size = pCtxt->fPointSizeMin;
            WriteCmd( pCtxt, (LPDWORD)&pCtxt->atiPntSprClampCmd, sizeof( ATIPNTSPRCLAMP_cmd ) >> 2 );
            dwPntSprFlags &= ~ATI_TCL_PTSPR_DIRTY_CLAMP;
        }
        
        pCtxt->dwPointSpriteFlags = dwPntSprFlags;
    }   
}


////////////////////////////////////////////////////////////////////////
// TclWriteGlobalStateCmd
////////////////////////////////////////////////////////////////////////
__inline VOID TclWriteGlobalStateCmd(LPATID3DCNTX pCtxt)
{
  // CHAPLIN_TODO: Need runtime selection instead of compile time
  WriteCmd( pCtxt, (LPDWORD)&pCtxt->tclR2GlobalStateCmd, sizeof( ATITCLRAD2GLOBALSTATE_cmd ) >> 2);
}


////////////////////////////////////////////////////////////////////////
// TclWriteTextureControlCmd
////////////////////////////////////////////////////////////////////////
__inline VOID TclWriteTextureControlCmd(LPATID3DCNTX pCtxt)
{
  WriteCmd( pCtxt, (LPDWORD)&pCtxt->tclR2TextureControlCmd, sizeof(ATITCLRAD2TEXTURECONTROL_cmd) >> 2);
}


////////////////////////////////////////////////////////////////////////
// TclWriteVertexControlCmds
////////////////////////////////////////////////////////////////////////
__inline VOID TclWriteVertexControlCmds(LPATID3DCNTX pCtxt)
{
  WriteCmd( pCtxt, (LPDWORD)&pCtxt->tclR2MiscControlCmd,    sizeof(ATITCLRAD2MISCCONTROL_cmd)    >> 2);
  WriteCmd( pCtxt, (LPDWORD)&pCtxt->tclR2OutputVtxControlCmd, sizeof(ATITCLRAD2OUTPUTVTXCONTROL_cmd) >> 2);
  WriteCmd( pCtxt, (LPDWORD)&pCtxt->tclR2InputVtxVectorAddrCmd, sizeof(ATITCLRAD2INPUTVTXVECTORADDR_cmd) >> 2);
}

////////////////////////////////////////////////////////////////////////
// TclWriteLightControlCmd
////////////////////////////////////////////////////////////////////////
__inline VOID TclWriteLightControlCmd(LPATID3DCNTX pCtxt)
{ 
  LPD3DDEVICE lpD3DDev = (LPD3DDEVICE)GetD3DDevice(pCtxt);

  if(pCtxt->bTclFlush == 1)
  {
    WriteCmd(pCtxt,(LPDWORD)&pCtxt->tclFlushCmd,sizeof(ATITCLFLUSH_cmd)>>2);
    pCtxt->bTclFlush = 0;
  }
  WriteCmd( pCtxt, (LPDWORD)&pCtxt->tclR2LightControlCmd, sizeof(ATITCLRAD2LIGHTCONTROL_cmd) >> 2);
}


////////////////////////////////////////////////////////////////////////
// TclClearTextureControlCmd
////////////////////////////////////////////////////////////////////////
__inline VOID TclClearTextureControlCmd(LPATID3DCNTX pCtxt)
{
  pCtxt->tclR2TextureControlCmd.texProcCntl0.u32All   = 0;
  pCtxt->tclR2TextureControlCmd.texProcCntl1.u32All   = 0;
  pCtxt->tclR2TextureControlCmd.texCylWrapCntl.u32All = 0;
}


////////////////////////////////////////////////////////////////////////
// TclSetFogMode
////////////////////////////////////////////////////////////////////////
__inline VOID TclSetFogMode(LPATID3DCNTX pCtxt, DWORD dwFogMode, BOOL bRangeFog)
{
  // Set the fog mode
  pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl.bitfields.FOG_MODE = dwFogMode;
  pCtxt->tclR2MiscControlCmd.ucpSkinCullCntl.bitfields.RNG_BASED_FOG = bRangeFog;
}

////////////////////////////////////////////////////////////////////////
// TclSetLightControlCmd
////////////////////////////////////////////////////////////////////////
__inline VOID TclSetLightControlCmd(LPATID3DCNTX pCtxt)
{ 
  LPD3DDEVICE lpD3DDev = (LPD3DDEVICE)GetD3DDevice(pCtxt);

  if(lpD3DDev->AtiD3dRegistry.dwClipOptimizations)
  {   
    DWORD dwTclLMCFlags = pCtxt->dwTclLMCFlags;
    
    pCtxt->dwTclLMCFlags &= ~(ATI_TCL_LMC_CLIP_DBL_BUF_ENA | ATI_TCL_LMC_WAIT_ON_CLIP_DIS);
    
    //Check if Vertex Blending is on
    if(!(pCtxt->dwVertexBlendWeightCnt                                        | 
         (pCtxt->ATIStateList[D3DRENDERSTATE_VERTEXBLEND] == D3DVBF_TWEENING) | 
         (pCtxt->eVtxProcMode == E_VTXPROCMODE_HW_PVS) ) )
    {
      pCtxt->dwTclLMCFlags |= ATI_TCL_LMC_WAIT_ON_CLIP_DIS;
      
      if( ! ((pCtxt->dwPointSpriteFlags & ATI_TCL_PTSPR_ENABLED) || 
             (pCtxt->ATIStateList[D3DRENDERSTATE_CLIPPLANEENABLE])) )
      {
          if(lpD3DDev->AtiD3dRegistry.dwClipOptimizations > 1)
          {
              pCtxt->dwTclLMCFlags |= ATI_TCL_LMC_CLIP_DBL_BUF_ENA;
          }
      }
    }

    //Check if the clip bits have changed. Need to flush TCL engine if the settings have changed.
    if(dwTclLMCFlags != pCtxt->dwTclLMCFlags)
    {
      pCtxt->bTclFlush = 1;
    }
    else 
    {
      pCtxt->bTclFlush = 0;
    }
  }

  // Update various flags
  pCtxt->tclR2LightControlCmd.lightModelCntl0.u32All &= ~ATI_TCL_LMC_ALL_FLAGS;
  pCtxt->tclR2LightControlCmd.lightModelCntl0.u32All |= pCtxt->dwTclLMCFlags;

  // Update the material source
  pCtxt->tclR2LightControlCmd.lightModelCntl1.bitfields.FRONT_EMISSIVE_SRC = pCtxt->tclMaterialSrc.emiSrc;
  pCtxt->tclR2LightControlCmd.lightModelCntl1.bitfields.FRONT_AMBIENT_SRC  = pCtxt->tclMaterialSrc.ambSrc;
  pCtxt->tclR2LightControlCmd.lightModelCntl1.bitfields.FRONT_DIFFUSE_SRC  = pCtxt->tclMaterialSrc.diffSrc;
  pCtxt->tclR2LightControlCmd.lightModelCntl1.bitfields.FRONT_SPECULAR_SRC = pCtxt->tclMaterialSrc.specSrc;
}

/////////////////////////////////////////////////////////////////////////////
// TclGetStrideOffset
/////////////////////////////////////////////////////////////////////////////
__inline LPTclVecScaStrOff TclGetStrideOffset(VOID)
{
  return &g_Rad2TclStrideOffset;
}


#endif // _TCLPRIVATE_H_


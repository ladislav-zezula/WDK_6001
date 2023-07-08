#ifndef _RADEON_LEGACYDEFS_H_
#define _RADEON_LEGACYDEFS_H_


// Macros
// CHAPLIN_TODO: Eventually, we need a non-compile time replacement for these

// ATI_SET_VTX_W0_NORMALIZE
#define ATI_SET_VTX_W0_NORMALIZE(pCtxt, dwSetting)                                  \
  set_SE_VTE_CNTL_vtx_w0_normalize(&((pCtxt)->SeVteCntl_reg), (dwSetting));

// ATI_SET_VTX_XY_FMT
#define ATI_SET_VTX_XY_FMT(pCtxt, dwSetting)                                        \
    set_SE_VTE_CNTL_vtx_xy_fmt(&((pCtxt)->SeVteCntl_reg), (dwSetting));

// ATI_SET_VTX_Z_FMT
#define ATI_SET_VTX_Z_FMT(pCtxt, dwSetting)                                         \
    set_SE_VTE_CNTL_vtx_z_fmt(&((pCtxt)->SeVteCntl_reg), (dwSetting));


// ATI_SET_PATTERN_ENABLE
#define ATI_SET_PATTERN_ENABLE(pCtxt, dwSetting)                                    \
  set_RE_CNTL_pattern_enable(&((pCtxt)->ReCntl_reg), (dwSetting));


// ATI_SET_STIPPLE_ENABLE
#define ATI_SET_STIPPLE_ENABLE(pCtxt, dwSetting)                                    \
    set_RE_CNTL_stipple_enable(&((pCtxt)->ReCntl_reg), (dwSetting));


// ATI_SET_PERSPECTIVE_ENABLE
    // CHAPLIN_TODO: Need separate controls for color and texture perspective correct
#define ATI_SET_PERSPECTIVE_ENABLE(pCtxt, dwSetting)                                \
    set_RE_CNTL_perspective_enable(&((pCtxt)->ReCntl_reg), (dwSetting));

// ATI_SET_SCISSOR_ENABLE
#define ATI_SET_SCISSOR_ENABLE(pCtxt, dwSetting)                                    \
        set_RE_CNTL_scissor_enable(&((pCtxt)->ReCntl_reg), (dwSetting));


// ATI_SET_VPORT_XY_SCALE_OFFSET
#define ATI_SET_VPORT_XY_SCALE_OFFSET(pCtxt, dwSetting)                              \
    set_SE_VTE_CNTL_vport_x_scale_ena(  &(pCtxt)->SeVteCntl_reg, (dwSetting));       \
    set_SE_VTE_CNTL_vport_x_offset_ena( &(pCtxt)->SeVteCntl_reg, (dwSetting));       \
    set_SE_VTE_CNTL_vport_y_scale_ena(  &(pCtxt)->SeVteCntl_reg, (dwSetting));       \
    set_SE_VTE_CNTL_vport_y_offset_ena( &(pCtxt)->SeVteCntl_reg, (dwSetting));


// ATI_SET_VPORT_Z_SCALE_OFFSET
#define ATI_SET_VPORT_Z_SCALE_OFFSET(pCtxt, dwSetting)                               \
    set_SE_VTE_CNTL_vport_z_scale_ena(  &(pCtxt)->SeVteCntl_reg, (dwSetting));       \
    set_SE_VTE_CNTL_vport_z_offset_ena( &(pCtxt)->SeVteCntl_reg, (dwSetting));

#define VF_CNTL_COMMON 0x00000000
         

#endif // _RADEON_LEGACYDEFS_H_


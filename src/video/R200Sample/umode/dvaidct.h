/**************************************************************************************\
*                                                                                      *
* Module Name:     DVAIDCT.H                                                           *
* Project:         ATI DirectX-VA Driver for R200                                      *
* Description:     Contains macro source code to make r128IDCT fucnctions              *
*                                                                                      *
* Copyringt (c) 2004 ATI Technologies Inc.                                             *
*                                                                                      *
* All rights reserved.                                                                 *
* The year included in the forgoing notice is the year of creation of work.            *
*                                                                                      *
* Log of Changes                                                                       *
* --------------                                                                       *
* Version    Date        Author        Description                                     *
* 1.0     04/14/2000    Henry Law      Initial revision                                *
*                                                                                      *
\**************************************************************************************/

#ifndef _DVAIDCT_H_
#define _DVAIDCT_H_


#define DVA_MC_XSRC_MASK        0x1fff
#define DVA_MC_YSRC_MASK        0x0fff

DWORD FRAMEMC_YPITCHx     = MC_PITCHx2;
DWORD FRAMEMC_UVPITCHx    = MC_PITCHx1;
DWORD FIELDMC_YPITCHx     = MC_PITCHx4;
DWORD FIELDMC_UVPITCHx    = MC_PITCHx2;


static __inline int DIV2(int a)
{
    return (a - (a>>31)) >> 1;
}

static __inline void R128IDCT_PackDCTBlock( LPDWORD *pEngineCodeBuffer,
                                            LPDXVA_TCoef4Group pTCoef,
                                            BYTE *pbNumCoef)
{
#ifndef _WIN64
        _asm{
            xor ebx,ebx
            xor dx,dx
            mov ecx, 3
            mov esi, pTCoef
            mov eax,DWORD PTR [pEngineCodeBuffer]
            mov edi,DWORD PTR [eax]
packIntraDCT_1:
            mov eax, pbNumCoef
            mov dl, BYTE PTR [eax+ebx]
            or  dl,dl
            jz  packIntraDCT_3
packIntraDCT_2:
            mov DWORD PTR [edi],PM4F_RUN_AND_LEVEL
            add edi,4
            mov cl,3
            rep movsd
            sub dl,4
            jg  packIntraDCT_2
packIntraDCT_3:
            mov DWORD PTR [edi],0
            add edi,4
            inc bx
            cmp bx,6
            jl  packIntraDCT_1
            mov eax,DWORD PTR [pEngineCodeBuffer]
            mov [eax], edi
            }
#endif
        return;
}



static __inline void R128IDCT_PackNonIntraDCTBlock( LPDWORD *pEngineCodeBuffer,
                                                    LPDXVA_TCoef4Group pTCoef,
                                                    BYTE *pbNumCoef)
{
#ifndef _WIN64
        _asm{
            xor ebx,ebx
            xor dx,dx
            mov ecx, 3
            mov esi, pTCoef
            mov eax,DWORD PTR [pEngineCodeBuffer]
            mov edi,DWORD PTR [eax]
packNonIntraDCT_1:
            mov eax, pbNumCoef
            mov dl, BYTE PTR [eax+ebx]
            or  dl,dl
            jz  packNonIntraDCT_3
packNonIntraDCT_2:
            mov DWORD PTR [edi],PM4F_RUN_AND_LEVEL
            add edi,4
            mov cl,3
            rep movsd
            sub dl,4
            jg  packNonIntraDCT_2
packNonIntraDCT_3:
            mov DWORD PTR [edi],0
            add edi,4
            inc bx
            cmp bx,6
            jl  packNonIntraDCT_1
            mov eax,DWORD PTR [pEngineCodeBuffer]
            mov [eax], edi
            }
#endif
        return;
}

static __inline void R128IDCT_PackMC_FramePicFrameMCtypeFwdBack(LPDWORD *pEngineCodeBuffer,
                                                                DWORD *pDestBuffer,
                                                                DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                                int mx, int my)
{
    // frame pic, frame MC 16x16, fwd, back
    int sx1, sy1, sx2, sy2;
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;

    // Y plane
    sx1 = ((mx<<1) + pMBctrl_P->MVector[0].horz) & DVA_MC_XSRC_MASK;
    sy1 = ((my<<1) + pMBctrl_P->MVector[0].vert) & DVA_MC_YSRC_MASK;
    sx2 = ((mx<<1) + pMBctrl_P->MVector[1].horz) & DVA_MC_XSRC_MASK;
    sy2 = ((my<<1) + pMBctrl_P->MVector[1].vert) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[0]  = PM4F_2D_2VECTOR;
    engineCodeBuffer[1]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FRAMEMC_YPITCHx;
    engineCodeBuffer[2]  = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FRAMEMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[3]  = my | (mx << MC_DST_X_SHIFT) | FRAMEMC_YPITCHx;
    engineCodeBuffer[4]  = 6 | pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | (1 << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_16x16;

    // U plane
    sx1 = (mx + DIV2(pMBctrl_P->MVector[0].horz)) & DVA_MC_XSRC_MASK;
    sy1 = (my + DIV2(pMBctrl_P->MVector[0].vert)) & DVA_MC_YSRC_MASK;
    sx2 = (mx + DIV2(pMBctrl_P->MVector[1].horz)) & DVA_MC_XSRC_MASK;
    sy2 = (my + DIV2(pMBctrl_P->MVector[1].vert)) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[5]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FRAMEMC_UVPITCHx;
    engineCodeBuffer[6]  = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FRAMEMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[7]  = (my>>1) | ((mx>>1) << MC_DST_X_SHIFT) | FRAMEMC_UVPITCHx;
    engineCodeBuffer[8]  = 8 | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | (3 << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x8;
    // V Plane
    engineCodeBuffer[9]  = PM4F_V_PLANE;
    engineCodeBuffer[10] = 10 | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | (5 << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x8;
    *pEngineCodeBuffer = engineCodeBuffer+11;

}


static __inline void R128IDCT_PackMC_FramePicFrameMCtypeBack(LPDWORD *pEngineCodeBuffer,
                                                             DWORD *pDestBuffer,
                                                             DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                             int mx, int my)
{
    // frame pic, frame MC 16x16, back only
    int sx1, sy1;
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;

    sx1 = ((mx<<1) + pMBctrl_P->MVector[1].horz) & DVA_MC_XSRC_MASK;
    sy1 = ((my<<1) + pMBctrl_P->MVector[1].vert) & DVA_MC_YSRC_MASK;
    // Y plane
    engineCodeBuffer[0]  = PM4F_1D_2VECTOR;
    engineCodeBuffer[1]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FRAMEMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[2]  = my | (mx << MC_DST_X_SHIFT) | FRAMEMC_YPITCHx;
    engineCodeBuffer[3]  = 6 | pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_16x16;
    
    sx1 = (mx + DIV2(pMBctrl_P->MVector[1].horz)) & DVA_MC_XSRC_MASK;
    sy1 = (my + DIV2(pMBctrl_P->MVector[1].vert)) & DVA_MC_YSRC_MASK;
    // U plane
    engineCodeBuffer[4]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FRAMEMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB ;
    engineCodeBuffer[5]  = (my>>1) | ((mx>>1) << MC_DST_X_SHIFT) | FRAMEMC_UVPITCHx;
    engineCodeBuffer[6]  = 8 | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x8;
    // V Plane
    engineCodeBuffer[7]  = PM4F_V_PLANE;
    engineCodeBuffer[8]  = 10 | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x8;
    *pEngineCodeBuffer = engineCodeBuffer+9;
 
}


static __inline void R128IDCT_PackMC_FramePicFrameMCtypeFwd(LPDWORD *pEngineCodeBuffer,
                                                            DWORD *pDestBuffer,
                                                            DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                            int mx, int my)
{
    // frame pic, frame MC 16x16, forward only
    int sx1, sy1;
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;

    sx1 = ((mx<<1) + pMBctrl_P->MVector[0].horz) & DVA_MC_XSRC_MASK;
    sy1 = ((my<<1) + pMBctrl_P->MVector[0].vert) & DVA_MC_YSRC_MASK;
    // Y plane
    engineCodeBuffer[0]  = PM4F_1D_2VECTOR;
    engineCodeBuffer[1]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FRAMEMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[2]  = my | (mx << MC_DST_X_SHIFT) | FRAMEMC_YPITCHx;
    engineCodeBuffer[3]  = 0 | pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_16x16;

    sx1 = (mx + DIV2(pMBctrl_P->MVector[0].horz)) & DVA_MC_XSRC_MASK;
    sy1 = (my + DIV2(pMBctrl_P->MVector[0].vert)) & DVA_MC_YSRC_MASK;
    // U plane
    engineCodeBuffer[4]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FRAMEMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB ;
    engineCodeBuffer[5]  = (my>>1) | ((mx>>1) << MC_DST_X_SHIFT) | FRAMEMC_UVPITCHx;
    engineCodeBuffer[6]  = 2 | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x8;
    // V Plane
    engineCodeBuffer[7]  = PM4F_V_PLANE;
    engineCodeBuffer[8]  = 4 | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x8;
    *pEngineCodeBuffer = engineCodeBuffer+9;
}

static __inline void R128IDCT_PackMC_FramePicFrameMCtypeFwdNoMotion(LPDWORD *pEngineCodeBuffer,
                                                            DWORD *pDestBuffer,
                                                            DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                            int mx, int my)
{
    // frame pic, frame MC 16x16, forward only

    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;
    int sx = (mx*2) & DVA_MC_XSRC_MASK;
    int sy = (my*2) & DVA_MC_YSRC_MASK;

    // Y plane
    engineCodeBuffer[0]  = PM4F_1D_2VECTOR;
    engineCodeBuffer[1]  = (sx ) |(sy << MC_SRC_Y_SHIFT) | FRAMEMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[2]  = my | (mx << MC_DST_X_SHIFT) | FRAMEMC_YPITCHx;
    engineCodeBuffer[3]  = 0 | pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_16x16;

    // U plane
    engineCodeBuffer[4]  = (mx ) |(my << MC_SRC_Y_SHIFT) | FRAMEMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB ;
    engineCodeBuffer[5]  = (my>>1) | ((mx>>1) << MC_DST_X_SHIFT) | FRAMEMC_UVPITCHx;
    engineCodeBuffer[6]  = 2 | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x8;
    // V Plane
    engineCodeBuffer[7]  = PM4F_V_PLANE;
    engineCodeBuffer[8]  = 4 | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x8;
    *pEngineCodeBuffer = engineCodeBuffer+9;
}

static __inline void R128IDCT_PackMC_FramePicFieldMCtypeFwdBack(LPDWORD *pEngineCodeBuffer,
                                                                DWORD *pDestBuffer,
                                                                DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                                int mx, int my)
{
    // frame pic, field MC, fwd, back
    int sx1, sy1, sx2, sy2;
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;


    // Y plane - top
    sx1 = ((mx<<1) + pMBctrl_P->MVector[0].horz) & DVA_MC_XSRC_MASK;
    sy1 =  (my     + DIV2(pMBctrl_P->MVector[0].vert)) & DVA_MC_YSRC_MASK;
    sx2 = ((mx<<1) + pMBctrl_P->MVector[1].horz) & DVA_MC_XSRC_MASK;
    sy2 =  (my     + DIV2(pMBctrl_P->MVector[1].vert)) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[0]  = PM4F_2D_2VECTOR;
    engineCodeBuffer[1]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[2]  = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[3]  = (my >> 1) | (mx << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[4]  = (6+readDXVA_MvertFieldSel_1(pMBctrl_P)) | pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB |
                       ((1+readDXVA_MvertFieldSel_0(pMBctrl_P)) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_16x8;

    // Y plane - bottom
    sx1 = ((mx<<1) + pMBctrl_P->MVector[2].horz) & DVA_MC_XSRC_MASK;
    sy1 =  (my     + DIV2(pMBctrl_P->MVector[2].vert)) & DVA_MC_YSRC_MASK;
    sx2 = ((mx<<1) + pMBctrl_P->MVector[3].horz) & DVA_MC_XSRC_MASK;
    sy2 =  (my     + DIV2(pMBctrl_P->MVector[3].vert)) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[5]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[6]  = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[7]  = (my >> 1) | (mx << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[8]  = (6+readDXVA_MvertFieldSel_3(pMBctrl_P)) | pDestBuffer[1] | SE_MC_CNTL_START__MC_ALPHA_ENB |
                       ((1+readDXVA_MvertFieldSel_2(pMBctrl_P)) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_16x8;

    // U plane - top
    sx1 =  (mx     + DIV2(pMBctrl_P->MVector[0].horz)) & DVA_MC_XSRC_MASK;
    sy1 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[0].vert))) & DVA_MC_YSRC_MASK;
    sx2 =  (mx     + DIV2(pMBctrl_P->MVector[1].horz)) & DVA_MC_XSRC_MASK;
    sy2 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[1].vert))) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[9]  = PM4F_2D_2VECTOR;
    engineCodeBuffer[10] = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[11] = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[12] = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[13] = (8 + readDXVA_MvertFieldSel_1(pMBctrl_P))| pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB |
                       ((3+readDXVA_MvertFieldSel_0(pMBctrl_P)) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x4;

    // V Plane - top
    engineCodeBuffer[18] = PM4F_2D_2VECTOR;
    engineCodeBuffer[19] = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[20] = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[21] = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[22] = (10 + readDXVA_MvertFieldSel_1(pMBctrl_P))| pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB |
                                        ((5+readDXVA_MvertFieldSel_0(pMBctrl_P)) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x4;
    // U plane - bottom
    sx1 =  (mx     + DIV2(pMBctrl_P->MVector[2].horz)) & DVA_MC_XSRC_MASK;
    sy1 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[2].vert))) & DVA_MC_YSRC_MASK;
    sx2 =  (mx     + DIV2(pMBctrl_P->MVector[3].horz)) & DVA_MC_XSRC_MASK;
    sy2 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[3].vert))) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[14] = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[15] = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[16] = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[17] = (8 + readDXVA_MvertFieldSel_3(pMBctrl_P))| pDestBuffer[3] | SE_MC_CNTL_START__MC_ALPHA_ENB |
                       ((3+readDXVA_MvertFieldSel_2(pMBctrl_P)) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x4;

    // V plane - bottom
    engineCodeBuffer[23] = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[24] = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[25] = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[26] = (10 + readDXVA_MvertFieldSel_3(pMBctrl_P))| pDestBuffer[5] | SE_MC_CNTL_START__MC_ALPHA_ENB |
                       ((5+readDXVA_MvertFieldSel_2(pMBctrl_P)) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x4;
    *pEngineCodeBuffer = engineCodeBuffer+27;
}

static __inline void R128IDCT_PackMC_FramePicFieldMCtypeBack(LPDWORD *pEngineCodeBuffer,
                                                             DWORD *pDestBuffer,
                                                             DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                             int mx, int my)
{
    // frame pic, field MC, back

    int sx1, sy1, sx2, sy2;
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;
    

    // Y plane
    sx1 = ((mx<<1) + pMBctrl_P->MVector[1].horz) & DVA_MC_XSRC_MASK;
    sy1 =  (my     + DIV2(pMBctrl_P->MVector[1].vert)) & DVA_MC_YSRC_MASK;
    sx2 = ((mx<<1) + pMBctrl_P->MVector[3].horz) & DVA_MC_XSRC_MASK;
    sy2 =  (my     + DIV2(pMBctrl_P->MVector[3].vert)) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[0]  = PM4F_1D_2VECTOR;
    engineCodeBuffer[1]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[2]  = (my >>1) | (mx << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[3]  = (6 + readDXVA_MvertFieldSel_1(pMBctrl_P))| pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_16x8;
    engineCodeBuffer[4]  = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[5]  = (my >>1) | (mx << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[6]  = (6 + readDXVA_MvertFieldSel_3(pMBctrl_P))| pDestBuffer[1] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_16x8;

    // U plane
    sx1 =  (mx     + DIV2(pMBctrl_P->MVector[1].horz)) & DVA_MC_XSRC_MASK;
    sy1 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[1].vert))) & DVA_MC_YSRC_MASK;
    sx2 =  (mx     + DIV2(pMBctrl_P->MVector[3].horz)) & DVA_MC_XSRC_MASK;
    sy2 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[3].vert))) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[7]  = PM4F_1D_2VECTOR;
    engineCodeBuffer[8]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[9]  = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[10] = (8 + readDXVA_MvertFieldSel_1(pMBctrl_P)) | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;
    engineCodeBuffer[11] = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[12] = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[13] = (8 + readDXVA_MvertFieldSel_3(pMBctrl_P)) | pDestBuffer[3] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;

    // V Plane
    engineCodeBuffer[14] = PM4F_1D_2VECTOR;
    engineCodeBuffer[15] = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[16] = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[17] = (10 + readDXVA_MvertFieldSel_1(pMBctrl_P)) | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;
    engineCodeBuffer[18] = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[19] = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[20] = (10 + readDXVA_MvertFieldSel_3(pMBctrl_P)) | pDestBuffer[5] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;
    *pEngineCodeBuffer = engineCodeBuffer+21;
}

static __inline void R128IDCT_PackMC_FramePicFieldMCtypeFwd(LPDWORD *pEngineCodeBuffer,
                                                            DWORD *pDestBuffer,
                                                            DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                            int mx, int my)
{
    // frame pic, field MC, forward only
    int sx1, sy1, sx2, sy2;
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;


    // Y plane
    sx1 = ((mx<<1) + pMBctrl_P->MVector[0].horz) & DVA_MC_XSRC_MASK;
    sy1 =  (my     + DIV2(pMBctrl_P->MVector[0].vert)) & DVA_MC_YSRC_MASK;
    sx2 = ((mx<<1) + pMBctrl_P->MVector[2].horz) & DVA_MC_XSRC_MASK;
    sy2 =  (my     + DIV2(pMBctrl_P->MVector[2].vert)) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[0]  = PM4F_1D_2VECTOR;
    engineCodeBuffer[1]  = sx1| (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[2]  = (my >>1) | (mx << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[3]  = (0 + readDXVA_MvertFieldSel_0(pMBctrl_P))| pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_16x8;
    engineCodeBuffer[4]  = sx2| (sy2 << MC_SRC_Y_SHIFT) |FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[5]  = (my >>1) | (mx << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[6]  = (0 + readDXVA_MvertFieldSel_2(pMBctrl_P))| pDestBuffer[1] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_16x8;

    
    // U plane
    sx1 =  (mx     + DIV2(pMBctrl_P->MVector[0].horz)) & DVA_MC_XSRC_MASK;
    sy1 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[0].vert))) & DVA_MC_YSRC_MASK;
    sx2 =  (mx     + DIV2(pMBctrl_P->MVector[2].horz)) & DVA_MC_XSRC_MASK;
    sy2 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[2].vert))) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[7]  = PM4F_1D_2VECTOR;
    engineCodeBuffer[8]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[9]  = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[10] = (2 + readDXVA_MvertFieldSel_0(pMBctrl_P)) | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;
    engineCodeBuffer[11] = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[12] = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[13] = (2 + readDXVA_MvertFieldSel_2(pMBctrl_P)) | pDestBuffer[3] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;
    
    // V Plane
    engineCodeBuffer[14] = PM4F_1D_2VECTOR;
    engineCodeBuffer[15] = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[16] = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[17] = (4 + readDXVA_MvertFieldSel_0(pMBctrl_P)) | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;
    engineCodeBuffer[18] = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[19] = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[20] = (4 + readDXVA_MvertFieldSel_2(pMBctrl_P)) | pDestBuffer[5] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;
    *pEngineCodeBuffer = engineCodeBuffer+21;

}


static __inline void R128IDCT_PackMC_FramePicDualPrime(LPDWORD *pEngineCodeBuffer,
                                                       DWORD *pDestBuffer,
                                                       DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                       int mx, int my)
{
    // frame pic, Dual Prime, forward only

    int sx1, sy1, sx2, sy2;
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;

    // Y plane - top
    sx1 = ((mx<<1) + pMBctrl_P->MVector[0].horz) & DVA_MC_XSRC_MASK;
    sy1 =  (my     + DIV2(pMBctrl_P->MVector[0].vert)) & DVA_MC_YSRC_MASK;
    sx2 = ((mx<<1) + pMBctrl_P->MVector[1].horz) & DVA_MC_XSRC_MASK;
    sy2 =  (my     + DIV2(pMBctrl_P->MVector[1].vert)) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[0]  = PM4F_2D_2VECTOR;
    engineCodeBuffer[1]  = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[2]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[3]  = (my >> 1) | (mx << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[4]  = (0+ 0) | pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB |
                       ((1+ 1) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_16x8;
    // Y plane - bottom
    sx1 = ((mx<<1) + pMBctrl_P->MVector[2].horz) & DVA_MC_XSRC_MASK;
    sy1 =  (my     + DIV2(pMBctrl_P->MVector[2].vert)) & DVA_MC_YSRC_MASK;
    sx2 = ((mx<<1) + pMBctrl_P->MVector[3].horz) & DVA_MC_XSRC_MASK;
    sy2 =  (my     + DIV2(pMBctrl_P->MVector[3].vert)) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[5]  = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[6]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[7]  = (my >> 1) | (mx << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[8]  = (0+1) | pDestBuffer[1] | SE_MC_CNTL_START__MC_ALPHA_ENB |
                       ((1+0) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_16x8;

    // U plane - top
    sx1 =  (mx     + DIV2(pMBctrl_P->MVector[0].horz)) & DVA_MC_XSRC_MASK;
    sy1 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[0].vert))) & DVA_MC_YSRC_MASK;
    sx2 =  (mx     + DIV2(pMBctrl_P->MVector[1].horz)) & DVA_MC_XSRC_MASK;
    sy2 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[1].vert))) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[9]  = PM4F_2D_2VECTOR;
    engineCodeBuffer[10] = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[11] = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[12] = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[13] = (0+2)| pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB |
                       ((1+3) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x4;
    // U plane - bottom
    sx1 =  (mx     + DIV2(pMBctrl_P->MVector[2].horz)) & DVA_MC_XSRC_MASK;
    sy1 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[2].vert))) & DVA_MC_YSRC_MASK;
    sx2 =  (mx     + DIV2(pMBctrl_P->MVector[3].horz)) & DVA_MC_XSRC_MASK;
    sy2 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[3].vert))) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[14] = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[15] = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[16] = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[17] = (0 + 3)| pDestBuffer[3] | SE_MC_CNTL_START__MC_ALPHA_ENB |
                       ((1 + 2) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x4;

    // V Plane - top
    sx1 =  (mx     + DIV2(pMBctrl_P->MVector[0].horz)) & DVA_MC_XSRC_MASK;
    sy1 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[0].vert))) & DVA_MC_YSRC_MASK;
    sx2 =  (mx     + DIV2(pMBctrl_P->MVector[1].horz)) & DVA_MC_XSRC_MASK;
    sy2 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[1].vert))) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[18] = PM4F_2D_2VECTOR;
    engineCodeBuffer[19] = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[20] = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[21] = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[22] = (0+4)| pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB |
                       ((1+5) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x4;
  
  // V plane - bottom
    sx1 =  (mx     + DIV2(pMBctrl_P->MVector[2].horz)) & DVA_MC_XSRC_MASK;
    sy1 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[2].vert))) & DVA_MC_YSRC_MASK;
    sx2 =  (mx     + DIV2(pMBctrl_P->MVector[3].horz)) & DVA_MC_XSRC_MASK;
    sy2 = ((my>>1) + DIV2(DIV2(pMBctrl_P->MVector[3].vert))) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[23] = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[24] = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[25] = (my>>2) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[26] = (0 + 5)| pDestBuffer[5] | SE_MC_CNTL_START__MC_ALPHA_ENB |
                       ((1 +  4) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x4;
    *pEngineCodeBuffer = engineCodeBuffer+27;
}



static __inline void R128IDCT_PackMC_FieldPicFieldMCtypeFwdBack(LPDWORD *pEngineCodeBuffer,
                                                                DWORD *pDestBuffer,
                                                                DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                                int mx, int my,
                                                                BYTE bPictureStructure)
{

    // field pic, field MC, backward and forward
    int sx1, sy1, sx2, sy2;
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;
    DXVA_MVvalue *pMVector0, *pMVector1;    
    WORD MVSel[2];

    pMVector0 = &pMBctrl_P->MVector[0];
    pMVector1 = &pMBctrl_P->MVector[1];
    MVSel[0] = readDXVA_MvertFieldSel_0(pMBctrl_P);
    MVSel[1] = readDXVA_MvertFieldSel_1(pMBctrl_P);


    // Field picture, field prediction (16x16), backward and forward
    sx1 = ((mx <<1) + pMVector0->horz) & DVA_MC_XSRC_MASK;
    sy1 = ((my <<1) + pMVector0->vert) & DVA_MC_YSRC_MASK;
    sx2 = ((mx <<1) + pMVector1->horz) & DVA_MC_XSRC_MASK;
    sy2 = ((my <<1) + pMVector1->vert) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[0]  = PM4F_2D_2VECTOR;
    engineCodeBuffer[1]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[2]  = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[3]  = my | (mx << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[4]  = (6 +  MVSel[1])| pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | ((1+ MVSel[0]) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_16x16;

    // U plane
    sx1 =  (mx      + DIV2(pMVector0->horz)) & DVA_MC_XSRC_MASK;
    sy1 =  (my      + DIV2(pMVector0->vert)) & DVA_MC_YSRC_MASK;
    sx2 =  (mx      + DIV2(pMVector1->horz)) & DVA_MC_XSRC_MASK;
    sy2 =  (my      + DIV2(pMVector1->vert)) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[5]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[6]  = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[7]  = (my>>1) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[8]  = (8 + MVSel[1]) | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | ((3+ MVSel[0]) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x8;

    // V Plane
    engineCodeBuffer[9]  = PM4F_V_PLANE;
    engineCodeBuffer[10] = (10 + MVSel[1]) | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | ((5+ MVSel[0]) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x8;
    *pEngineCodeBuffer = engineCodeBuffer+11;
}


static __inline void R128IDCT_PackMC_FieldPicFieldMCtypeBack(LPDWORD *pEngineCodeBuffer,
                                                             DWORD *pDestBuffer,
                                                             DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                             int mx, int my,
                                                             BYTE bPictureStructure)
{
    // field pic, field MC, backward
    int sx1, sy1;
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;
    DXVA_MVvalue *pMVector1;    
    WORD MVSel[2];

    pMVector1 = &pMBctrl_P->MVector[1];
    MVSel[1] = readDXVA_MvertFieldSel_1(pMBctrl_P);

    // Field picture, field prediction (16x16), backward
    sx1 = ((mx<<1) + pMVector1->horz) & DVA_MC_XSRC_MASK;
    sy1 = ((my<<1) + pMVector1->vert) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[0]  = PM4F_1D_2VECTOR;
    engineCodeBuffer[1]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx| SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[2]  = my | (mx << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[3]  = (6 +  MVSel[1])| pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_16x16;

    // U plane
    sx1 = (mx + DIV2(pMVector1->horz)) & DVA_MC_XSRC_MASK;
    sy1 = (my + DIV2(pMVector1->vert)) & DVA_MC_YSRC_MASK;
    
    engineCodeBuffer[4]  = sx1 |  (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx| SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[5]  = (my>>1) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[6]  = (8 + MVSel[1]) | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x8;

    // V Plane
    engineCodeBuffer[7]  = PM4F_V_PLANE;
    engineCodeBuffer[8]  = (10 + MVSel[1]) | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x8;
    *pEngineCodeBuffer = engineCodeBuffer+9;
}

static __inline void R128IDCT_PackMC_FieldPicFieldMCtypeFwd(LPDWORD *pEngineCodeBuffer,
                                                            DWORD *pDestBuffer,
                                                            DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                            int mx, int my,
                                                            BYTE bPictureStructure)
{
    // field pic, field MC, forward
    int sx1, sy1;
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;
    DXVA_MVvalue *pMVector0;
    WORD MVSel[2];

    pMVector0 = &pMBctrl_P->MVector[0];
    MVSel[0] = readDXVA_MvertFieldSel_0(pMBctrl_P);


    // Field picture, field prediction (16x16), backward
    sx1 = ((mx<<1) + pMVector0->horz) & DVA_MC_XSRC_MASK;
    sy1 = ((my<<1) + pMVector0->vert) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[0]  = PM4F_1D_2VECTOR;
    engineCodeBuffer[1]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx| SE_MC_SRC1_CNTL__MC_IDCT_ENB ;
    engineCodeBuffer[2]  = my | (mx << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[3]  = (0 +  MVSel[0])| pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_16x16;

    // U plane
    sx1 = (mx  + DIV2(pMVector0->horz)) & DVA_MC_XSRC_MASK;
    sy1 = (my  + DIV2(pMVector0->vert)) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[4]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx| SE_MC_SRC1_CNTL__MC_IDCT_ENB ;
    engineCodeBuffer[5]  = (my>>1) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[6]  = (2 + MVSel[0]) | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x8;

    // V Plane
    engineCodeBuffer[7]  = PM4F_V_PLANE;
    engineCodeBuffer[8]  = (4 + MVSel[0]) | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x8;
    *pEngineCodeBuffer = engineCodeBuffer+9;
}

static __inline void R128IDCT_PackMC_FieldPicFieldMCtypeFwdNoMotion(LPDWORD *pEngineCodeBuffer,
                                                            DWORD *pDestBuffer,
                                                            DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                            int mx, int my,
                                                            BYTE bPictureStructure)
{
    // field pic, field MC, forward
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;
    int sx = (mx*2) & DVA_MC_XSRC_MASK;
    int sy = (my*2) & DVA_MC_YSRC_MASK;
    WORD MVSel[2];

    if (bPictureStructure == 0x1)
    {
        MVSel[0] = 0;
    }
    else
    {
        MVSel[0] = 1;
    }

    // Field picture, field prediction (16x16), backward
    engineCodeBuffer[0]  = PM4F_1D_2VECTOR;
    engineCodeBuffer[1]  = sx | ((sy ) << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx| SE_MC_SRC1_CNTL__MC_IDCT_ENB ;
    engineCodeBuffer[2]  = my | (mx << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[3]  = (0 +  MVSel[0])| pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_16x16;

    // U plane
    engineCodeBuffer[4]  = (mx ) |  ((my ) << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx| SE_MC_SRC1_CNTL__MC_IDCT_ENB ;
    engineCodeBuffer[5]  = (my>>1) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[6]  = (2 + MVSel[0]) | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x8;

    // V Plane
    engineCodeBuffer[7]  = PM4F_V_PLANE;
    engineCodeBuffer[8]  = (4 + MVSel[0]) | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x8;
    *pEngineCodeBuffer = engineCodeBuffer+9;
}

static __inline void R128IDCT_PackMC_FieldPic16x8MCtypeBackFwd(LPDWORD *pEngineCodeBuffer,
                                                               DWORD *pDestBuffer,
                                                               DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                               int mx, int my,
                                                               BYTE bPictureStructure)
{
    // field pic, field MC, backward
    int sx1t, sy1t, sx2t, sy2t, sx1b, sy1b, sx2b, sy2b, mxt, myt, mxb, myb;
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;


    mxt = mxb = mx;
    myt = my;
    myb = my + 8;

    // Field picture, field prediction (16x8 MC), backward
    // Y plane
    sx1t = ((mxt<<1) + pMBctrl_P->MVector[0].horz) & DVA_MC_XSRC_MASK;
    sy1t = ((myt<<1) + pMBctrl_P->MVector[0].vert) & DVA_MC_YSRC_MASK;
    sx2t = ((mxt<<1) + pMBctrl_P->MVector[1].horz) & DVA_MC_XSRC_MASK;
    sy2t = ((myt<<1) + pMBctrl_P->MVector[1].vert) & DVA_MC_YSRC_MASK;

    sx1b = ((mxb<<1) + pMBctrl_P->MVector[2].horz) & DVA_MC_XSRC_MASK;
    sy1b = ((myb<<1) + pMBctrl_P->MVector[2].vert) & DVA_MC_YSRC_MASK;
    sx2b = ((mxb<<1) + pMBctrl_P->MVector[3].horz) & DVA_MC_XSRC_MASK;
    sy2b = ((myb<<1) + pMBctrl_P->MVector[3].vert) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[0]  = PM4F_2D_2VECTOR;
    engineCodeBuffer[1]  = sx1t |(sy1t << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[2]  = sx2t |(sy2t << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[3]  = myt | (mxt << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[4]  = (6 + readDXVA_MvertFieldSel_1(pMBctrl_P)) | pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | ((1+readDXVA_MvertFieldSel_0(pMBctrl_P)) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_16x8;

    engineCodeBuffer[5]  = sx1b | (sy1b<< MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[6]  = sx2b | (sy2b<< MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[7]  = myb | (mxb << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[8]  = (6 + readDXVA_MvertFieldSel_3(pMBctrl_P)) | pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | ((1+readDXVA_MvertFieldSel_2(pMBctrl_P)) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_16x8;


    // U,V plane
    sx1t =  DIV2(sx1t);
    sy1t =  DIV2(sy1t);
    sx2t =  DIV2(sx2t);
    sy2t =  DIV2(sy2t);

    sx1b =  DIV2(sx1b);
    sy1b =  DIV2(sy1b);
    sx2b =  DIV2(sx2b);
    sy2b =  DIV2(sy2b);

    engineCodeBuffer[9]  = PM4F_2D_2VECTOR;
    engineCodeBuffer[10] = sx1t | (sy1t << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[11] = sx2t | (sy2t << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[12] = (myt>>1) | ((mxt>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[13] = (8+ readDXVA_MvertFieldSel_1(pMBctrl_P)) | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | ((3+readDXVA_MvertFieldSel_0(pMBctrl_P)) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x4;
    engineCodeBuffer[14] = sx1b | (sy1b<< MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[15] = sx2b | (sy2b<< MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[16] = (myb>>1) | ((mxb>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[17] = (8+ readDXVA_MvertFieldSel_3(pMBctrl_P)) | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | ((3+readDXVA_MvertFieldSel_2(pMBctrl_P)) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x4;

    // V Plane
    engineCodeBuffer[18] = PM4F_2D_2VECTOR;
    engineCodeBuffer[19] = sx1t | (sy1t << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[20] = sx2t | (sy2t << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[21] = (myt>>1) | ((mxt>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[22] = (10+ readDXVA_MvertFieldSel_1(pMBctrl_P)) | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | ((5+ readDXVA_MvertFieldSel_0(pMBctrl_P)) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x4;
    engineCodeBuffer[23] = sx1b | (sy1b<< MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[24] = sx2b | (sy2b<< MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[25] = (myb>>1) | ((mxb>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[26] = (10+ readDXVA_MvertFieldSel_3(pMBctrl_P)) | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | ((5+ readDXVA_MvertFieldSel_2(pMBctrl_P)) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x4;
    *pEngineCodeBuffer = engineCodeBuffer + 27;    //

}

static __inline void R128IDCT_PackMC_FieldPic16x8MCtypeBack(LPDWORD *pEngineCodeBuffer,
                                                   DWORD *pDestBuffer,
                                                   DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                   int mx, int my,
                                                   BYTE bPictureStructure)
{

    int sx1t, sy1t, sx1b, sy1b, mxt, myt, mxb, myb;
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;

    mxt = mxb = mx;
    myt = my;
    myb = my + 8;
    // field pic, field MC, backward
    // Y plane
    sx1t = ((mxt<<1) + pMBctrl_P->MVector[1].horz) & DVA_MC_XSRC_MASK;
    sy1t = ((myt<<1) + pMBctrl_P->MVector[1].vert) & DVA_MC_YSRC_MASK;

    sx1b = ((mxb<<1) + pMBctrl_P->MVector[3].horz) & DVA_MC_XSRC_MASK;
    sy1b = ((myb<<1) + pMBctrl_P->MVector[3].vert) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[0]  = PM4F_1D_2VECTOR;
    engineCodeBuffer[1]  = sx1t | (sy1t << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[2]  = myt  | (mxt << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[3]  = (6 + readDXVA_MvertFieldSel_1(pMBctrl_P)) | pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_16x8;
    //
    engineCodeBuffer[4]  = sx1b | (sy1b << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[5]  = myb | (mxb << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[6]  = (6 + readDXVA_MvertFieldSel_3(pMBctrl_P)) | pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_16x8;

    // U,V plane
    sx1t = DIV2(sx1t);
    sy1t = DIV2(sy1t);
    sx1b = DIV2(sx1b);
    sy1b = DIV2(sy1b);

    engineCodeBuffer[7]  = PM4F_1D_2VECTOR;
    engineCodeBuffer[8]  = sx1t | (sy1t << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[9]  = (myt>>1) | ((mxt>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[10] = (8+ readDXVA_MvertFieldSel_1(pMBctrl_P)) | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;
    //
    engineCodeBuffer[11] = sx1b | (sy1b << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[12] = (myb>>1) | ((mxb>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[13] = (8+ readDXVA_MvertFieldSel_3(pMBctrl_P)) | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;
    // V Plane
    engineCodeBuffer[14] = PM4F_1D_2VECTOR;
    engineCodeBuffer[15] = sx1t | (sy1t << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[16] = (myt>>1) | ((mxt>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[17] = (10+ readDXVA_MvertFieldSel_1(pMBctrl_P)) | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;
    //
    engineCodeBuffer[18] = sx1b | (sy1b << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[19] = (myb>>1) | ((mxb>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[20] = (10+ readDXVA_MvertFieldSel_3(pMBctrl_P)) | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;
    //
    *pEngineCodeBuffer = engineCodeBuffer + 21;
}

static __inline void R128IDCT_PackMC_FieldPic16x8MCtypeFwd(LPDWORD *pEngineCodeBuffer,
                                                  DWORD *pDestBuffer,
                                                  DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                  int mx, int my,
                                                  BYTE bPictureStructure)
{
    int sx1t, sy1t, sx1b, sy1b, mxt, myt, mxb, myb;
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;

    mxt = mxb = mx;
    myt = my;
    myb = my + 8;
    // field pic, field MC, backward
    // Y plane
    sx1t = ((mxt<<1) + pMBctrl_P->MVector[0].horz) & DVA_MC_XSRC_MASK;
    sy1t = ((myt<<1) + pMBctrl_P->MVector[0].vert) & DVA_MC_YSRC_MASK;

    sx1b = ((mxb<<1) + pMBctrl_P->MVector[2].horz) & DVA_MC_XSRC_MASK;
    sy1b = ((myb<<1) + pMBctrl_P->MVector[2].vert) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[0]  = PM4F_1D_2VECTOR;
    engineCodeBuffer[1]  = sx1t | (sy1t << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[2]  = myt  | (mxt << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[3]  = (0 + readDXVA_MvertFieldSel_0(pMBctrl_P)) | pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_16x8;
    //
    engineCodeBuffer[4]  = sx1b | (sy1b << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[5]  = myb | (mxb << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[6]  = (0 + readDXVA_MvertFieldSel_2(pMBctrl_P)) | pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_16x8;

    // U,V plane
    sx1t = DIV2(sx1t);
    sy1t = DIV2(sy1t);
    sx1b = DIV2(sx1b);
    sy1b = DIV2(sy1b);

    engineCodeBuffer[7]  = PM4F_1D_2VECTOR;
    engineCodeBuffer[8]  = sx1t | (sy1t << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[9]  = (myt>>1) | ((mxt>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[10] = (2+ readDXVA_MvertFieldSel_0(pMBctrl_P)) | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;
    //
    engineCodeBuffer[11] = sx1b | (sy1b << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[12] = (myb>>1) | ((mxb>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[13] = (2+ readDXVA_MvertFieldSel_2(pMBctrl_P)) | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;
    // V Plane
    engineCodeBuffer[14] = PM4F_1D_2VECTOR;
    engineCodeBuffer[15] = sx1t | (sy1t << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[16] = (myt>>1) | ((mxt>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[17] = (4+ readDXVA_MvertFieldSel_0(pMBctrl_P)) | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;
    //
    engineCodeBuffer[18] = sx1b | (sy1b << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB;
    engineCodeBuffer[19] = (myb>>1) | ((mxb>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[20] = (4+ readDXVA_MvertFieldSel_2(pMBctrl_P)) | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | (0) | MC_CNTL_WH_8x4;
    //
    *pEngineCodeBuffer = engineCodeBuffer + 21;}

static __inline void R128IDCT_PackMC_FieldPicDualPrime(LPDWORD *pEngineCodeBuffer,
                                                       DWORD *pDestBuffer,
                                                       DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                       int mx, int my,
                                                       BYTE bPictureStructure)
{
    // field pic, field MC, Dual Prime
    int sx1, sy1, sx2, sy2;
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;
    // Y plane
    sx1 = ((mx<<1) + pMBctrl_P->MVector[0].horz) & DVA_MC_XSRC_MASK;
    sy1 = ((my<<1) + pMBctrl_P->MVector[0].vert) & DVA_MC_YSRC_MASK;
    sx2 = ((mx<<1) + pMBctrl_P->MVector[1].horz) & DVA_MC_XSRC_MASK;
    sy2 = ((my<<1) + pMBctrl_P->MVector[1].vert) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[0]  = PM4F_2D_2VECTOR;
    engineCodeBuffer[1]  = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[2]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_YPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[3]  = my | (mx << MC_DST_X_SHIFT) | FIELDMC_YPITCHx;
    engineCodeBuffer[4]  = (0 + readDXVA_MvertFieldSel_0(pMBctrl_P)) | pDestBuffer[0] | SE_MC_CNTL_START__MC_ALPHA_ENB | ((1+readDXVA_MvertFieldSel_1(pMBctrl_P)) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_16x16;

    // U plane
    sx1 = (mx + DIV2(pMBctrl_P->MVector[0].horz)) & DVA_MC_XSRC_MASK;
    sy1 = (my + DIV2(pMBctrl_P->MVector[0].vert)) & DVA_MC_YSRC_MASK;
    sx2 = (mx + DIV2(pMBctrl_P->MVector[1].horz)) & DVA_MC_XSRC_MASK;
    sy2 = (my + DIV2(pMBctrl_P->MVector[1].vert)) & DVA_MC_YSRC_MASK;

    engineCodeBuffer[5]  = sx2 | (sy2 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[6]  = sx1 | (sy1 << MC_SRC_Y_SHIFT) | FIELDMC_UVPITCHx | SE_MC_SRC1_CNTL__MC_IDCT_ENB | SE_MC_SRC1_CNTL__MC_SEC_TEX_ENB;
    engineCodeBuffer[7]  = (my>>1) | ((mx>>1) << MC_DST_X_SHIFT) | FIELDMC_UVPITCHx;
    engineCodeBuffer[8]  = (2+ readDXVA_MvertFieldSel_0(pMBctrl_P)) | pDestBuffer[2] | SE_MC_CNTL_START__MC_ALPHA_ENB | ((3+readDXVA_MvertFieldSel_1(pMBctrl_P)) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x8;

    // V Plane
    engineCodeBuffer[9]  = PM4F_V_PLANE;
    engineCodeBuffer[10] = (4+ readDXVA_MvertFieldSel_0(pMBctrl_P)) | pDestBuffer[4] | SE_MC_CNTL_START__MC_ALPHA_ENB | ((5+ readDXVA_MvertFieldSel_1(pMBctrl_P)) << MC_SRCINDEX2_SHIFT) | MC_CNTL_WH_8x8;
    *pEngineCodeBuffer = engineCodeBuffer + 11;
}

static __inline BOOL R128IDCT_PackMotionCompensation( LPDWORD *pEngineCodeBuffer,
                                                      DWORD *pDestBuffer,
                                                      DXVA_PictureParameters *pPictureParameters,
                                                      DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P,
                                                      int mx, int my)
{
    LPDWORD engineCodeBuffer = *pEngineCodeBuffer;
    BOOL bResult=TRUE;

    if (pPictureParameters->bPicStructure == DXVA_PICTURE_STRUCTURE_FRAME)
    {
        if (readDXVA_MotionType(pMBctrl_P) == PT_FRAME_BASED)
        {
            if (readDXVA_MotionBackward(pMBctrl_P))
            {
                if (readDXVA_MotionForward(pMBctrl_P))
                {
                    // frame pic, frame MC, fwd, back

                    R128IDCT_PackMC_FramePicFrameMCtypeFwdBack(pEngineCodeBuffer, pDestBuffer, pMBctrl_P, mx, my);

                }
                else
                {
                    // frame pic, frame MC, back
                    R128IDCT_PackMC_FramePicFrameMCtypeBack(pEngineCodeBuffer, pDestBuffer, pMBctrl_P, mx, my);
                }
            }
            else
            {
                if (readDXVA_MotionForward(pMBctrl_P))
                {
                    // frame pic, frame MC, forward
                    R128IDCT_PackMC_FramePicFrameMCtypeFwd(pEngineCodeBuffer, pDestBuffer, pMBctrl_P, mx, my);
                }
                else
                {
                    // frame pic, frame MC, forward
                    R128IDCT_PackMC_FramePicFrameMCtypeFwdNoMotion(pEngineCodeBuffer, pDestBuffer, pMBctrl_P, mx, my);

                }
            }

        }

        else if (readDXVA_MotionType(pMBctrl_P) == PT_FIELD_BASED)
        {
            if (readDXVA_MotionBackward(pMBctrl_P))
            {
                if (readDXVA_MotionForward(pMBctrl_P))
                {
                    // frame pic, field MC (16x8), fwd, back
                    R128IDCT_PackMC_FramePicFieldMCtypeFwdBack(pEngineCodeBuffer, pDestBuffer, pMBctrl_P, mx, my);
                }
                else
                {
                    // frame pic, field MC (16x8), backward
                    R128IDCT_PackMC_FramePicFieldMCtypeBack(pEngineCodeBuffer, pDestBuffer, pMBctrl_P, mx, my);
                }
            }
            else
            {
                // frame pic, field MC (16x8), forward only
                R128IDCT_PackMC_FramePicFieldMCtypeFwd(pEngineCodeBuffer, pDestBuffer, pMBctrl_P, mx, my);
            }
        }
        else // Dual Prime - only motion forward
        {
            R128IDCT_PackMC_FramePicDualPrime(pEngineCodeBuffer, pDestBuffer, pMBctrl_P, mx, my);
        }

    }
    else 
    {

        if (readDXVA_MotionType(pMBctrl_P) == PT_FIELD_BASED)
        {
            if (readDXVA_MotionBackward(pMBctrl_P))
            {
                if (readDXVA_MotionForward(pMBctrl_P))
                {
                    // top field pic, field MC, backward and forward
                    R128IDCT_PackMC_FieldPicFieldMCtypeFwdBack(pEngineCodeBuffer, pDestBuffer, pMBctrl_P, mx, my, pPictureParameters->bPicStructure);
                }
                else
                {
                    // top field pic, field MC, backward only
                    R128IDCT_PackMC_FieldPicFieldMCtypeBack(pEngineCodeBuffer,
                                                            pDestBuffer,
                                                            pMBctrl_P,
                                                            mx, my,
                                                            pPictureParameters->bPicStructure);

                }
            }
            else
            {
                if (readDXVA_MotionForward(pMBctrl_P))
                {

                    // top field pic, field MC, forward only
                    R128IDCT_PackMC_FieldPicFieldMCtypeFwd(pEngineCodeBuffer,
                                                           pDestBuffer,
                                                           pMBctrl_P,
                                                           mx, my,
                                                           pPictureParameters->bPicStructure);
                }
                else
                {
                    // top field pic, field MC, forward only
                    R128IDCT_PackMC_FieldPicFieldMCtypeFwdNoMotion(pEngineCodeBuffer,
                                                                   pDestBuffer,
                                                                   pMBctrl_P,
                                                                   mx, my,
                                                                   pPictureParameters->bPicStructure);

                }
            }

        }
        else if (readDXVA_MotionType(pMBctrl_P) == PT_16x8_MC)
        {
            if (readDXVA_MotionBackward(pMBctrl_P))
            {
                if (readDXVA_MotionForward(pMBctrl_P))
                {
                    // top field pic, field MC, backward and forward
                    R128IDCT_PackMC_FieldPic16x8MCtypeBackFwd(pEngineCodeBuffer, pDestBuffer, pMBctrl_P, mx, my, pPictureParameters->bPicStructure);
                }
                else
                {
                    // top field pic, field MC, backward
                    R128IDCT_PackMC_FieldPic16x8MCtypeBack(pEngineCodeBuffer, pDestBuffer, pMBctrl_P, mx, my, pPictureParameters->bPicStructure);
                }
            }
            else
            {
                // top field pic, field MC, forward only
                R128IDCT_PackMC_FieldPic16x8MCtypeFwd(pEngineCodeBuffer, pDestBuffer, pMBctrl_P, mx, my, pPictureParameters->bPicStructure);

            }

        }
        else // Dual Prime - only motion forward
        {
            R128IDCT_PackMC_FieldPicDualPrime(pEngineCodeBuffer, pDestBuffer, pMBctrl_P, mx, my, pPictureParameters->bPicStructure);
        }

    }
    return bResult;
}

__inline DWORD R128IDCT_ParseIntraMacroBlock(DWORD *pEngineCodeBuffer,
                                             DWORD *pDestBuffer,
                                             DXVA_PictureParameters *pPictureParameters,
                                             DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P, 
                                             LPDXVA_TCoef4Group pTCoef,
                                             BOOL isEncrypt)
{
    int mx, my;
    WORD  wMBaddress;
    DWORD dwIDCTorder;
    DWORD* pTempBuffer;
    DWORD Size;

    wMBaddress = pMBctrl_P->wMBaddress;
    mx = ( wMBaddress % (pPictureParameters->wPicWidthInMBminus1 + 1)) * 16;
    my = ( wMBaddress / (pPictureParameters->wPicWidthInMBminus1 + 1)) * 16;

    if (pPictureParameters->bPicStructure == DXVA_PICTURE_STRUCTURE_FRAME) // Frame Pictre
    {
        pEngineCodeBuffer[2] = PM4F_INTRA_MBLOCK;        // Y
        pEngineCodeBuffer[3] = FRAMEMC_YPITCHx | (mx << MC_DST_X_SHIFT) | my;
        pEngineCodeBuffer[4] = pDestBuffer[0] | MC_CNTL_WH_16x16;
        pEngineCodeBuffer[5] = PM4F_INTRA_MBLOCK;         // U
        pEngineCodeBuffer[6] = FRAMEMC_UVPITCHx | ((mx >> 1) << MC_DST_X_SHIFT) | (my >> 1);
        pEngineCodeBuffer[7] = pDestBuffer[2] | MC_CNTL_WH_8x8;
        pEngineCodeBuffer[8] = PM4F_V_PLANE;             // V
        pEngineCodeBuffer[9] = pDestBuffer[4] | MC_CNTL_WH_8x8;
    }
    else
    {
        pEngineCodeBuffer[2] = PM4F_INTRA_MBLOCK;        // Y
        pEngineCodeBuffer[3] = FIELDMC_YPITCHx | (mx << MC_DST_X_SHIFT) | my;
        pEngineCodeBuffer[4] = pDestBuffer[0] | MC_CNTL_WH_16x16;
        pEngineCodeBuffer[5] = PM4F_INTRA_MBLOCK;         // U
        pEngineCodeBuffer[6] = FIELDMC_UVPITCHx | ((mx >> 1) << MC_DST_X_SHIFT) | (my >> 1);
        pEngineCodeBuffer[7] = pDestBuffer[2] | MC_CNTL_WH_8x8;
        pEngineCodeBuffer[8] = PM4F_V_PLANE;             // V
        pEngineCodeBuffer[9] = pDestBuffer[4] | MC_CNTL_WH_8x8;
    }

    pTempBuffer = pEngineCodeBuffer + 10;

    pTCoef = (LPDXVA_TCoef4Group)((DWORD *)pTCoef + readDXVA_MBdataLocation(pMBctrl_P)); // get to the dct start area for the MB
    //
    //
    R128IDCT_PackDCTBlock( &pTempBuffer, pTCoef, (BYTE *) pMBctrl_P->bNumCoef);
    // Add the macroblock header
#ifndef _WIN64
    pEngineCodeBuffer[0] = IDCT_PKT_HDR | ((pTempBuffer - pEngineCodeBuffer - 2) << 16);
#endif
    dwIDCTorder = 0;
    if (pPictureParameters->bPicStructure == DXVA_PICTURE_STRUCTURE_FRAME)
    {
        if (readDXVA_FieldResidual(pMBctrl_P))
        {
            dwIDCTorder |= IDCT_LUMA_081 | IDCT_CHROMA_012;
        }
        else
        {
            dwIDCTorder |= IDCT_LUMA_012 | IDCT_CHROMA_012;
        }
    }
    else
    {
        dwIDCTorder |= IDCT_LUMA_012 | IDCT_CHROMA_012;
    }

    pEngineCodeBuffer[1] = IDCT_CONTROL__IDCT_CTL_INTRA |
                              (readDXVA_MBscanMethod(pMBctrl_P)? IDCT_ALT_SCAN:0) | dwIDCTorder;
#ifdef _WIN64
    return 0;
#else
    Size = pTempBuffer - pEngineCodeBuffer;

    return Size;
#endif
}

__inline DWORD R128IDCT_ParseNonIntraMacroBlock(DWORD *pEngineCodeBuffer,
                                                DWORD *pDestBuffer,
                                                DXVA_PictureParameters *pPictureParameters,
                                                DXVA_MBctrl_P_OffHostIDCT_1 *pMBctrl_P, 
                                                LPDXVA_TCoef4Group pTCoef )
{
    int mx, my;
    WORD  wMBaddress;
    DWORD dwIDCTorder;
    DWORD* pTempBuffer;


    wMBaddress = pMBctrl_P->wMBaddress;
    mx = ( wMBaddress % (pPictureParameters->wPicWidthInMBminus1 + 1)) * 16;
    my = ( wMBaddress / (pPictureParameters->wPicWidthInMBminus1 + 1)) * 16;
    if(mx > (pPictureParameters->wPicWidthInMBminus1 + 1) * 16)
    {
        mx = pPictureParameters->wPicWidthInMBminus1 * 16;
    }
    if(my > (pPictureParameters->wPicHeightInMBminus1 + 1) * 16) 
    {
        my = pPictureParameters->wPicHeightInMBminus1 * 16;
    }
    pTempBuffer = pEngineCodeBuffer + 2;
    R128IDCT_PackMotionCompensation(&pTempBuffer, pDestBuffer, pPictureParameters, pMBctrl_P, mx, my);
    pTCoef = (LPDXVA_TCoef4Group)((DWORD *)pTCoef + readDXVA_MBdataLocation(pMBctrl_P)); // get to the dct start area for the MB

    R128IDCT_PackNonIntraDCTBlock( &pTempBuffer, pTCoef, (BYTE *) pMBctrl_P->bNumCoef);

    // Add the macroblock header
#ifndef _WIN64
    pEngineCodeBuffer[0] = IDCT_PKT_HDR | ((pTempBuffer - pEngineCodeBuffer - 2) << 16);
#endif
    dwIDCTorder = 0;
    if (pPictureParameters->bPicStructure == DXVA_PICTURE_STRUCTURE_FRAME)
    {
        if ((readDXVA_MotionType(pMBctrl_P) == PT_FIELD_BASED) ||
            (readDXVA_MotionType(pMBctrl_P) == PT_DUAL_PRIME))
        {
            if (readDXVA_FieldResidual(pMBctrl_P))
            {
                dwIDCTorder |= IDCT_LUMA_012 | IDCT_CHROMA_024;
            }
            else
            {
                dwIDCTorder |= IDCT_LUMA_024 | IDCT_CHROMA_024;
            }
        }
        else
        {
            if (readDXVA_FieldResidual(pMBctrl_P))
            {
                dwIDCTorder |= IDCT_LUMA_081 | IDCT_CHROMA_012;
            }
            else
            {
                dwIDCTorder |= IDCT_LUMA_012 | IDCT_CHROMA_012;
            }
        }
    }
    else
    {
        dwIDCTorder |= IDCT_LUMA_012 | IDCT_CHROMA_012;
    }
    pEngineCodeBuffer[1] = (readDXVA_MBscanMethod(pMBctrl_P)? IDCT_ALT_SCAN:0) | dwIDCTorder;

#ifdef _WIN64
    return 0;
#else
    return pTempBuffer - pEngineCodeBuffer;
#endif
}

__inline DWORD R128IDCT_WriteBufferEnd( DWORD *pEngineCodeBuffer )
{
    int i;

    pEngineCodeBuffer[ 0] = IDCT_PKT_HDR;
    pEngineCodeBuffer[ 1] = IDCT_CONTROL__IDCT_CTL_FLUSH;

    pEngineCodeBuffer[ 2] = 0x004585b3;
    for(i=3; i<73; i++)
    {
        pEngineCodeBuffer[ i] = 0xffffffff;
    }

    pEngineCodeBuffer[73] = 0xc0003100;
    pEngineCodeBuffer[74] = 0x00000100;
    pEngineCodeBuffer[75] = 0xc0003100;
    pEngineCodeBuffer[76] = 0x00000000;

    return 77;
}


#endif /* _DVAIDCT_H_ */


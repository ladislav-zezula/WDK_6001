

//
//  $Workfile: rage.h $
//
//  Description:
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _RAGE_H
#define _RAGE_H

/** include files **/

#include "atidxinc.h"
#include "atidxobj.h"
#include "atidxhsl.h"

#include "radeon.h"
#include "radeonBFFunc.h"


/** definitions **/
#define DEFAULT_PITCH__DEFAULT_TILE              0x00010000

//Used inside the CRTC_OFFSET_CNTL
#define CRTC_ALIGN_16K 0x400

//r128 pxiel format
#define DP_4BPP    0x100   // 1 bytes/pixel
#define DP_8BPP    0x200   // 1 bytes/pixel
#define DP_15BPP   0x300   // 2 bytes/pixel
#define DP_16BPP   0x400   // 2 bytes/pixel
#define DP_24BPP   0x500   // 4 bytes/pixel
#define DP_32BPP   0x600   // 4 bytes/pixel
#define DP_YUV9    0x900   // 1 byte/pixel for each map
#define DP_YUV12   0xA00  // 1 byte/pixel for each map
#define DP_VYUY    0xB00  // 2 bytes/pixel (YUV422 format 1)
#define DP_YVYU    0xC00  // 2 bytes/pixel (YUV422 format 2)


#define DP_TEX_4BPP   ((DP_4BPP) >> 8)
#define DP_TEX_8BPP   ((DP_8BPP) >> 8)
#define DP_TEX_15BPP  ((DP_15BPP) >> 8)
#define DP_TEX_16BPP  ((DP_16BPP) >> 8)
#define DP_TEX_24BPP  ((DP_24BPP) >> 8)
#define DP_TEX_32BPP  ((DP_32BPP) >> 8)
#define DP_TEX_VYUY   ((DP_VYUY) >> 8)
#define DP_TEX_YVYU   ((DP_YVYU) >> 8)





/*
 * This value must be "OR"ed with the texture offset if it's tiled
*/
#define     TEXTURE_TILE_FLAG       0xc0000000
#define     AGP_SURFACE_FLAG        0x02000000
#define     MAX_TEXTURE_SIZE        2048

#if defined(RADEON_EMULATOR)
extern DWORD EmuReadMMReg(LPVOID pDeviceInfo, DWORD dwOffset);
extern void EmuWriteMMReg(LPVOID pDeviceInfo, DWORD dwOffset, DWORD dwData);
#define MMRReadD(p, x)             (EmuReadMMReg(p, x))
#define MMRWriteD(p, x, y)         (EmuWriteMMReg(p, x, y))
#else
#define MMRReadD(p, x)             ((GetATIMemReg(p))[x])
#define MMRWriteD(p, x, y)         ((GetATIMemReg(p))[x]=(y))
#endif

#define MMRWriteD_IFHOverride(p, x, y)  ((GetATIMemReg(p))[x]=(y))

// The IN_VBLANK macro is modified to support dual CRTC for Piglet
_inline BOOL CRTC1_IN_VBLANK(LPATIDXOBJECT lpATIDXObj)
{
    DWORD dwScanLine=(MMRReadD(lpATIDXObj, mmCRTC_VLINE_CRNT_VLINE) & CRTC_VLINE_CRNT_VLINE__CRTC_CRNT_VLINE_MASK) >> CRTC_VLINE_CRNT_VLINE__CRTC_CRNT_VLINE__SHIFT;
    DWORD dwVDISP= (MMRReadD(lpATIDXObj,mmCRTC_V_TOTAL_DISP)&CRTC_V_TOTAL_DISP__CRTC_V_DISP_MASK)>>CRTC_V_TOTAL_DISP__CRTC_V_DISP__SHIFT;
    if(dwVDISP<=300)
        dwScanLine/=2;
    return dwScanLine>dwVDISP;
}
_inline BOOL CRTC2_IN_VBLANK(LPATIDXOBJECT lpATIDXObj)
{
    DWORD dwScanLine=(MMRReadD(lpATIDXObj, mmCRTC2_VLINE_CRNT_VLINE) & CRTC2_VLINE_CRNT_VLINE__CRTC2_CRNT_VLINE_MASK) >> CRTC2_VLINE_CRNT_VLINE__CRTC2_CRNT_VLINE__SHIFT;
    DWORD dwVDISP= (MMRReadD(lpATIDXObj,mmCRTC2_V_TOTAL_DISP)&CRTC2_V_TOTAL_DISP__CRTC2_V_DISP_MASK)>>CRTC2_V_TOTAL_DISP__CRTC2_V_DISP__SHIFT;
    if(dwVDISP<=300)
        dwScanLine/=2;
    return dwScanLine>dwVDISP;
}

#define IN_VBLANK(p)               (( GetConnectedCRTC(p) & 0x1 ) ? CRTC1_IN_VBLANK(p) : CRTC2_IN_VBLANK(p) )
#define IN_DISPLAY(p)              (!(IN_VBLANK(p)))

#define CURRENT_SCANLINE(p)        ((MMRReadD(p, (GetConnectedCRTC(p)&0x1)?mmCRTC_VLINE_CRNT_VLINE:mmCRTC2_VLINE_CRNT_VLINE) & CRTC_VLINE_CRNT_VLINE__CRTC_CRNT_VLINE_MASK) >> CRTC_VLINE_CRNT_VLINE__CRTC_CRNT_VLINE__SHIFT)


//Loop until the start of vertical blank
#define WAIT_FOR_VBLANK(p)         while(IN_DISPLAY(p));

//Loop until the end of vertical blank
#define WAIT_FOR_DISPLAY(p)        while(IN_VBLANK(p));

/**************** PIGLET INLINE MACROS BEGIN ****************************/
/*
 * GetConnectedCRTC
 */
_inline DWORD GetConnectedCRTC(LPATIDXOBJECT lpATIDXObj)
{
    return ( lpATIDXObj->lpCIDCIData->ulCBConnectedCRTCs );
}

/*
 * GetOverlayActiveCRTC
 */

_inline DWORD GetOverlayActiveCRTC(LPATIDXOBJECT lpATIDXObj)
{
    return ( lpATIDXObj->lpCIDCIData->ulCBOverlayActiveCRTC );
}



#ifdef _IA64_
_inline void VBLANK_ACKNOWLEDGE(LPATIDXOBJECT lpATIDXObj)
{
    MMRWriteD(lpATIDXObj, mmCRTC_STATUS,
            MMRReadD(lpATIDXObj, mmCRTC_STATUS) | CRTC_STATUS__CRTC_VBLANK_SAVE_CLEAR);

    if (GetConnectedCRTC(lpATIDXObj) & 0x2)
        MMRWriteD(lpATIDXObj, mmCRTC2_STATUS,
            MMRReadD(lpATIDXObj, mmCRTC2_STATUS) | CRTC2_STATUS__CRTC2_VBLANK_SAVE_CLEAR);

}

_inline BOOL CRTC1_VBLANK_HAPPENED (LPATIDXOBJECT lpATIDXObj )
{
    return (MMRReadD(lpATIDXObj, mmCRTC_STATUS) & CRTC_STATUS__CRTC_VBLANK_SAVE);
}

_inline BOOL CRTC2_VBLANK_HAPPENED (LPATIDXOBJECT lpATIDXObj )
{
    return (MMRReadD(lpATIDXObj, mmCRTC2_STATUS) & CRTC2_STATUS__CRTC2_VBLANK_SAVE  );
}

_inline BOOL VBLANK_HAPPENED(LPATIDXOBJECT lpATIDXObj)
{
     return (CRTC1_VBLANK_HAPPENED(lpATIDXObj) && ((GetConnectedCRTC(lpATIDXObj) & 0x2) ? CRTC2_VBLANK_HAPPENED(lpATIDXObj) : 1) );
}
#endif //_IA64_




/**************** PIGLET INLINE MACROS END ****************************/

/*
 * The DisableVSYNC macro does just what it says, it disables
 * the VSYNC :). What this means is page flipping will be tied
 * to the horizontal SYNC rather than vertical SYNC.
 * Note that we also update the CACHED value of lpATIDXObj->dwCrtcOffsetCntl
*/
__inline VOID DisableVSYNC(LPATIDXOBJECT lpATIDXObj)
{
    // Added support for secondary CRTC for Piglet
    if(GetConnectedCRTC(lpATIDXObj) & 1)
    {
        lpATIDXObj->dwCrtcOffsetCntl = MMRReadD(lpATIDXObj,mmCRTC_OFFSET_CNTL);
        lpATIDXObj->dwCrtcOffsetCntl |= CRTC_OFFSET_CNTL__CRTC_OFFSET_FLIP_CNTL;

        //  This bit must always be set for WAIT_UNTIL to work in non-stereo mode
        lpATIDXObj->dwCrtcOffsetCntl |= CRTC_OFFSET_CNTL__CRTC_GUI_TRIG_OFFSET_LEFT_EN;

        while(!CRTC1_IN_VBLANK(lpATIDXObj));
        MMRWriteD_IFHOverride(lpATIDXObj, mmCRTC_OFFSET_CNTL, lpATIDXObj->dwCrtcOffsetCntl);
        lpATIDXObj->dwVSYNCEnabled &= ~1;
    }
    if(GetConnectedCRTC(lpATIDXObj) & 2)
    {
        lpATIDXObj->dwCrtc2OffsetCntl = MMRReadD(lpATIDXObj,mmCRTC2_OFFSET_CNTL);
        lpATIDXObj->dwCrtc2OffsetCntl |= CRTC2_OFFSET_CNTL__CRTC2_OFFSET_FLIP_CNTL;

        // This bit must always be set for WAIT_UNTIL to work in non-stereo mode
        lpATIDXObj->dwCrtc2OffsetCntl |= CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET_LEFT_EN;

        while(!CRTC2_IN_VBLANK(lpATIDXObj));
        MMRWriteD_IFHOverride(lpATIDXObj, mmCRTC2_OFFSET_CNTL, lpATIDXObj->dwCrtc2OffsetCntl);
        lpATIDXObj->dwVSYNCEnabled &= ~2;
    }
}

/*
 * The EnableVSYNC enables normal page flipping (i.e. tied to vertical blank)
 * Note that we also update the CACHED value of lpATIDXObj->dwCrtcOffsetCntl
*/
__inline VOID EnableVSYNC(LPATIDXOBJECT lpATIDXObj)
{
    // Added support for secondary CRTC for Piglet
    // This bit must always be set for WAIT_UNTIL to work in non-stereo mode
    if(GetConnectedCRTC(lpATIDXObj) & 1)
    {
        lpATIDXObj->dwCrtcOffsetCntl = MMRReadD(lpATIDXObj,mmCRTC_OFFSET_CNTL);
        lpATIDXObj->dwCrtcOffsetCntl &= ~CRTC_OFFSET_CNTL__CRTC_OFFSET_FLIP_CNTL;

        lpATIDXObj->dwCrtcOffsetCntl |= CRTC_OFFSET_CNTL__CRTC_GUI_TRIG_OFFSET_LEFT_EN;

        while(!CRTC1_IN_VBLANK(lpATIDXObj));
        MMRWriteD_IFHOverride(lpATIDXObj, mmCRTC_OFFSET_CNTL, lpATIDXObj->dwCrtcOffsetCntl);
        lpATIDXObj->dwVSYNCEnabled |= 1;
    }
    if(GetConnectedCRTC(lpATIDXObj) & 2)
    {
        lpATIDXObj->dwCrtc2OffsetCntl = MMRReadD(lpATIDXObj,mmCRTC2_OFFSET_CNTL);
        lpATIDXObj->dwCrtc2OffsetCntl &= ~CRTC2_OFFSET_CNTL__CRTC2_OFFSET_FLIP_CNTL;

        // This bit must always be set for WAIT_UNTIL to work in non-stereo mode
        lpATIDXObj->dwCrtc2OffsetCntl |= CRTC2_OFFSET_CNTL__CRTC2_GUI_TRIG_OFFSET_LEFT_EN;

        while(!CRTC2_IN_VBLANK(lpATIDXObj));
        MMRWriteD_IFHOverride(lpATIDXObj, mmCRTC2_OFFSET_CNTL, lpATIDXObj->dwCrtc2OffsetCntl);
        lpATIDXObj->dwVSYNCEnabled |= 2;
    }
}


/*
 * EnablePrimaryTiling:
 * This macro enables tiling for the primary surface
 * Note that we also update the CACHED value of lpATIDXObj->dwCrtcOffsetCntl
*/
__inline VOID EnablePrimaryTiling(LPVOID pDeviceInfo)
{
    LPATIDXOBJECT lpATIDXObj = (LPATIDXOBJECT) pDeviceInfo;

    // Added support for secondary CRTC for Piglet
    if(GetConnectedCRTC(lpATIDXObj) & 1)
    {
        lpATIDXObj->dwCrtcOffsetCntl = MMRReadD(lpATIDXObj,mmCRTC_OFFSET_CNTL);

        //Enable primary TILING (bit 15 in CRTC_OFFSET_CNTL)
        lpATIDXObj->dwCrtcOffsetCntl |= CRTC_OFFSET_CNTL__CRTC_TILE_EN;

        MMRWriteD(lpATIDXObj, mmCRTC_OFFSET_CNTL, lpATIDXObj->dwCrtcOffsetCntl);
    }
    if(GetConnectedCRTC(lpATIDXObj) & 2)
    {
        lpATIDXObj->dwCrtc2OffsetCntl = MMRReadD(lpATIDXObj,mmCRTC2_OFFSET_CNTL);

        //Enable primary TILING (bit 15 in CRTC_OFFSET_CNTL)
        lpATIDXObj->dwCrtc2OffsetCntl |= CRTC2_OFFSET_CNTL__CRTC2_TILE_EN;

        MMRWriteD(lpATIDXObj, mmCRTC2_OFFSET_CNTL, lpATIDXObj->dwCrtc2OffsetCntl);
    }
}

/*
 * DisablePrimaryTiling:
 * This macro enables tiling for the primary surface
 * Note that we also update the CACHED value of lpATIDXObj->dwCrtcOffsetCntl
*/
__inline VOID DisablePrimaryTiling(LPVOID pDeviceInfo)
{
    LPATIDXOBJECT lpATIDXObj = (LPATIDXOBJECT) pDeviceInfo;

    // Added support for secondary CRTC for Piglet
    if(GetConnectedCRTC(lpATIDXObj) & 1)
    {
        lpATIDXObj->dwCrtcOffsetCntl = MMRReadD(lpATIDXObj,mmCRTC_OFFSET_CNTL);
        lpATIDXObj->dwCrtcOffsetCntl &= ~CRTC_OFFSET_CNTL__CRTC_TILE_EN;

        MMRWriteD(lpATIDXObj, mmCRTC_OFFSET_CNTL, lpATIDXObj->dwCrtcOffsetCntl);
    }
    if(GetConnectedCRTC(lpATIDXObj) & 2)
    {
        lpATIDXObj->dwCrtc2OffsetCntl = MMRReadD(lpATIDXObj,mmCRTC2_OFFSET_CNTL);
        lpATIDXObj->dwCrtc2OffsetCntl &= ~CRTC2_OFFSET_CNTL__CRTC2_TILE_EN;

        MMRWriteD(lpATIDXObj, mmCRTC2_OFFSET_CNTL, lpATIDXObj->dwCrtc2OffsetCntl);
    }
}

/*
 * IsPrimaryTiled:
 * This macro checks if the primary surface is tiled
 * Note that we also update the CACHED value of lpATIDXObj->dwCrtcOffsetCntl
*/
__inline DWORD IsPrimaryTiled(LPVOID pDeviceInfo)
{
    LPATIDXOBJECT lpATIDXObj = (LPATIDXOBJECT) pDeviceInfo;

    // TODO: may not need to read the register here ...

    // Added support for secondary CRTC for Piglet
    if(GetConnectedCRTC(lpATIDXObj) & 1)
    {
      lpATIDXObj->dwCrtcOffsetCntl = MMRReadD(lpATIDXObj,mmCRTC_OFFSET_CNTL);
      return (lpATIDXObj->dwCrtcOffsetCntl & CRTC_OFFSET_CNTL__CRTC_TILE_EN);
    }
    if(GetConnectedCRTC(lpATIDXObj) & 2)
    {
      lpATIDXObj->dwCrtc2OffsetCntl = MMRReadD(lpATIDXObj,mmCRTC2_OFFSET_CNTL);
      return (lpATIDXObj->dwCrtc2OffsetCntl & CRTC2_OFFSET_CNTL__CRTC2_TILE_EN);
    }

    // Here, no CRTC is connected. Return information on primary CRTC.
    // Should not get to this point!
    lpATIDXObj->dwCrtcOffsetCntl = MMRReadD(lpATIDXObj,mmCRTC_OFFSET_CNTL);
    return (lpATIDXObj->dwCrtcOffsetCntl & CRTC_OFFSET_CNTL__CRTC_TILE_EN);
}

/*
 * EnableMemoryTranslation:
 * This macro enables the tiling apertures
*/
__inline VOID EnableMemoryTranslation(LPATIDXOBJECT lpATIDXObj)
{
  //Enable memory translation
  MMRWriteD(lpATIDXObj, mmSURFACE_CNTL, (MMRReadD(lpATIDXObj, mmSURFACE_CNTL)) & (~(SURFACE_CNTL__SURF_TRANSLATION_DIS)) );
}

/*
 * DisableMemoryTranslation:
 * This macro enables the tiling apertures
*/
__inline VOID DisableMemoryTranslation(LPATIDXOBJECT lpATIDXObj)
{
  //Enable memory translation
  MMRWriteD(lpATIDXObj, mmSURFACE_CNTL, (MMRReadD(lpATIDXObj, mmSURFACE_CNTL)) | (SURFACE_CNTL__SURF_TRANSLATION_DIS) );
}

__inline DWORD IsPM4InAGP(LPATIDXOBJECT lpATIDXObj)
{
//   return ( !MMRReadD(lpATIDXObj, mmAIC_CTRL) & AIC_CTRL__TRANSLATE_EN );
  return (lpATIDXObj->QSCaps.dwCaps & QS_CAPS_AGP);
}

__inline VOID SetAGPBase(LPATIDXOBJECT lpATIDXObj, FLATPTR fpPhysAddr)
{
    //set the AGP aperture address and size in ATI memory
    MMRWriteD(lpATIDXObj, mmMC_AGP_LOCATION, (DWORD) ((fpPhysAddr << MC_AGP_LOCATION__MC_AGP_START__SHIFT) | (fpPhysAddr+0x2000000-1) << MC_AGP_LOCATION__MC_AGP_TOP__SHIFT));
}

/* EnableStereoMode
 * This function enables stereo auto-flipping
*/
VOID __inline EnableStereoMode(LPATIDXOBJECT lpATIDXObj, DWORD dwValue)
{
    // Used cached value of register ... no need to read it.
    lpATIDXObj->dwCrtcOffsetCntl |= CRTC_OFFSET_CNTL__CRTC_STEREO_OFFSET_EN;
    lpATIDXObj->dwCrtcOffsetCntl |= CRTC_OFFSET_CNTL__CRTC_STEREO_SYNC_OUT_EN_MASK;
    lpATIDXObj->dwCrtcOffsetCntl |= (dwValue << CRTC_OFFSET_CNTL__CRTC_STEREO_SYNC_EN__SHIFT);

    MMRWriteD(lpATIDXObj, mmCRTC_OFFSET_CNTL, lpATIDXObj->dwCrtcOffsetCntl);

    SetStereoMode(lpATIDXObj, TRUE);
}

/* DisableStereoMode
 * This function disables stereo auto-flipping
*/
VOID __inline DisableStereoMode(LPATIDXOBJECT lpATIDXObj)
{
    lpATIDXObj->dwCrtcOffsetCntl &= ~CRTC_OFFSET_CNTL__CRTC_STEREO_OFFSET_EN;
    lpATIDXObj->dwCrtcOffsetCntl &= ~CRTC_OFFSET_CNTL__CRTC_STEREO_SYNC_OUT_EN_MASK;
    lpATIDXObj->dwCrtcOffsetCntl &= ~CRTC_OFFSET_CNTL__CRTC_STEREO_SYNC_EN_MASK;

    MMRWriteD(lpATIDXObj, mmCRTC_OFFSET_CNTL, lpATIDXObj->dwCrtcOffsetCntl);

    SetStereoMode(lpATIDXObj, FALSE);
}

// Useful finegrained delay counter which avoids context switch inherent in Sleep
void waitUsingAPIPerformanceCounter( double wait );

#endif // _RAGE_H



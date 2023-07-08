

//    
//  $Workfile: dxcaps.h $
//  $Revision: 6 $
//
//  Description:
//
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _dxcaps_h
#define _dxcaps_h

//
//This header file holds all the DirectX caps for the BORG chip.
//

/****************************************************
**                                                 **
**         DDCAPS    HARDWARE CAPABILITIES         **
**                                                 **
*****************************************************/

#define BORG_HDWR_CAPS       ( DDCAPS_3D | DDCAPS_BLT | DDCAPS_BLTQUEUE \
                             | DDCAPS_COLORKEY \
                             | DDCAPS_BLTDEPTHFILL | DDCAPS_BLTSTRETCH \
                             | DDCAPS_BLTFOURCC \
                             | DDCAPS_READSCANLINE \
                             | DDCAPS_CANBLTSYSMEM | DDCAPS_ZBLTS )

#define BORG_HDWR_CAPS_8     ( DDCAPS_3D | DDCAPS_BLT | DDCAPS_BLTQUEUE \
                             | DDCAPS_COLORKEY \
                             | DDCAPS_BLTDEPTHFILL \
                             | DDCAPS_BLTFOURCC \
                             | DDCAPS_READSCANLINE \
                             | DDCAPS_CANBLTSYSMEM | DDCAPS_ZBLTS )

/*
 * Please note that we have different caps for 24BPP,
 * there is no scaling BLT's
*/

#define BORG_HDWR_CAPS_24    ( DDCAPS_3D | DDCAPS_BLT | DDCAPS_BLTQUEUE \
                             | DDCAPS_COLORKEY \
                             | DDCAPS_BLTDEPTHFILL \
                             | DDCAPS_READSCANLINE \
                             | DDCAPS_CANBLTSYSMEM | DDCAPS_ZBLTS )

/****************************************************
**                                                 **
**                    DDCAPS2                      **
**                                                 **
*****************************************************/

#define BORG_DDCAPS2      ( DDCAPS2_NONLOCALVIDMEM | DDCAPS2_COPYFOURCC | \
                            DDCAPS2_WIDESURFACES | DDCAPS2_NOPAGELOCKREQUIRED | \
                            DDCAPS2_NONLOCALVIDMEMCAPS | DDCAPS2_WIDESURFACES | \
                            DDCAPS2_COLORCONTROLOVERLAY | DDCAPS2_CANBOBINTERLEAVED | \
                            DDCAPS2_CANBOBNONINTERLEAVED | DDCAPS2_CANFLIPODDEVEN |\
                            DDCAPS2_FLIPNOVSYNC | DDCAPS2_CANBOBHARDWARE )


#define BORG_DDCAPS2_24   ( DDCAPS2_NONLOCALVIDMEM | DDCAPS2_NONLOCALVIDMEMCAPS | \
                            DDCAPS2_NOPAGELOCKREQUIRED | DDCAPS2_WIDESURFACES )

/****************************************************
**                                                 **
**                ZBUFFER CAPABILITIES             **
**                                                 **
*****************************************************/

#define BORG_HDWR_ZBBD (DDBD_16 | DDBD_24 | DDBD_32)

/****************************************************
**                                                 **
**                SURFACE CAPABILITIES             **
**                                                 **
*****************************************************/

#define BORG_SURF        ( DDSCAPS_FLIP | DDSCAPS_OFFSCREENPLAIN | \
                           DDSCAPS_PRIMARYSURFACE | DDSCAPS_ZBUFFER | \
                           DDSCAPS_TEXTURE | DDSCAPS_MIPMAP | \
                           DDSCAPS_VIDEOMEMORY | DDSCAPS_LOCALVIDMEM | \
                           DDSCAPS_NONLOCALVIDMEM | DDSCAPS_BACKBUFFER | \
                           DDSCAPS_COMPLEX | DDSCAPS_FRONTBUFFER | \
                           DDSCAPS_3DDEVICE )

//Removed DDFXCAPS_BLTARITHSTRETCHY, DDFXCAPS_OVERLAYDEINTERLACE

#define BORG_FXCAPS    ( DDFXCAPS_BLTSTRETCHX | DDFXCAPS_BLTSTRETCHY | \
                         DDFXCAPS_BLTSHRINKX | DDFXCAPS_BLTSHRINKY | \
                         DDFXCAPS_BLTARITHSTRETCHY )

#define BORG_FXCAPS_24  0

#define BORG_FXCAPS_8   BORG_FXCAPS

#define BORG_HDWR_SYSMEMCAPS (DDCAPS_BLT | DDCAPS_BLTQUEUE)


/****************************************************
**                                                 **
**                  COLOUR KEY CAPABILITIES        **
**                                                 **
*****************************************************/

#define BORG_CKCAPS   (DDCKEYCAPS_SRCBLT | DDCKEYCAPS_DESTBLT | \
                       DDCKEYCAPS_SRCOVERLAY | DDCKEYCAPS_DESTOVERLAY | \
                       DDCKEYCAPS_SRCOVERLAYYUV |DDCKEYCAPS_SRCOVERLAYCLRSPACEYUV| \
                       DDCKEYCAPS_SRCOVERLAYONEACTIVE |DDCKEYCAPS_DESTOVERLAYYUV)
                       
/*
 * Please note that we have different caps for 24BPP,
 * there is no transparent BLT's or.
*/
                       
#define BORG_CKCAPS_24   ( DDCKEYCAPS_SRCOVERLAY | DDCKEYCAPS_DESTOVERLAY )
        
/****************************************************
**                                                 **
**           HAL CALLBACK OVERRIDES                **
**                                                 **
*****************************************************/

#define BORG_HALCBS   (DDHAL_CB32_WAITFORVERTICALBLANK | DDHAL_CB32_GETSCANLINE | \
                       DDHAL_CB32_CREATESURFACE | DDHAL_CB32_CANCREATESURFACE | \
                       DDHAL_CB32_SETCOLORKEY)

//Misc. callbacks (DX5.0 and above)
                       
#define BORG_DDMISCCBS   DDHAL_MISCCB32_GETAVAILDRIVERMEMORY
        
/****************************************************
**                                                 **
**       SURFACE    CALLBACK OVERRIDES             **
**                                                 **
*****************************************************/

#define BORG_SURFCBS     (DDHAL_SURFCB32_BLT | DDHAL_SURFCB32_FLIP | \
                          DDHAL_SURFCB32_LOCK | DDHAL_SURFCB32_UNLOCK| \
                          DDHAL_SURFCB32_GETBLTSTATUS  | \
                          DDHAL_SURFCB32_GETFLIPSTATUS | \
                          DDHAL_SURFCB32_DESTROYSURFACE | \
                          DDHAL_SURFCB32_SETCOLORKEY | \
                          DDHAL_SURFCB32_UPDATEOVERLAY | \
                          DDHAL_SURFCB32_SETOVERLAYPOSITION)
                      
/****************************************************
**                                                 **
**                  BORG EXECUTEBUFFER CAPS        **
**                                                 **
*****************************************************/

#define BORG_EXEBUFFER_CAPS     ( DDHAL_EXEBUFCB32_CANCREATEEXEBUF | \
                                  DDHAL_EXEBUFCB32_CREATEEXEBUF    | \
                                  DDHAL_EXEBUFCB32_DESTROYEXEBUF   | \
                                  DDHAL_EXEBUFCB32_LOCKEXEBUF      | \
                                  DDHAL_EXEBUFCB32_UNLOCKEXEBUF )
                                           
/****************************************************
**                                                 **
**               BORG COLOR CONTROL CAPS           **
**                                                 **
*****************************************************/

#define BORG_CCONTROL_CAPS      ( DDHAL_COLOR_COLORCONTROL )


#endif   // _dxcaps_h

//
// $Archive: /3D/D3D/d3drage5/Rage5Direct3D/inc/common/dxcaps.h $
// $Author: Merwin $
// $Revision: 6 $
// $Date: 5/12/99 5:17p $
// $Modtime: 5/12/99 4:40p $
// $History: dxcaps.h $
// 
// *****************  Version 6  *****************
// User: Merwin       Date: 5/12/99    Time: 5:17p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// clean-up
// 
// *****************  Version 5  *****************
// User: Merwin       Date: 3/23/99    Time: 4:17p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// another problem with the sysmem blt check in
// 
// *****************  Version 4  *****************
// User: Merwin       Date: 3/23/99    Time: 3:49p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// Fixed problems with sysmem blt check-in
// 
// *****************  Version 3  *****************
// User: Merwin       Date: 3/22/99    Time: 5:18p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// 
// *****************  Version 2  *****************
// User: Jweyman      Date: 2/16/99    Time: 5:17p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// added header/footer
//




//
//  $Workfile: rageddraw.h $
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//
#ifndef _ATIDDRAW_H__
#define _ATIDDRAW_H__

#include "atidxobj.h"

// In drvinit.c.
extern void InitATIDXObject(LPATIDXOBJECT lpATIDXObj);
extern void CheckIniSettings(LPATIDXOBJECT lpATIDXObj);
//extern BOOL GetHWInfo(LPATIDXOBJECT lpATIDXObj);
extern BOOL GetASICInfo(LPATIDXOBJECT lpATIDXObj);
extern void GetFourCCFmts(LPDWORD pdwNumFourCC, LPDWORD pdwFourCC);
extern void SetDDHalInfo(LPVOID lpDXObjPtr, LPDDHALINFO lpDDHALInfo);
extern DWORD SetUpDDrawCB(LPATIDXOBJECT lpATIDXObj);
extern void InitDstZCache(LPATIDXOBJECT lpATIDXObj);
extern void FreeDDrawCB(LPATIDXOBJECT lpATIDXObj);
extern DWORD InitQServer(LPATIDXOBJECT lpATIDXObj);

// In drvinit9x.c
extern void SetDDCapsOnModeSwitch( LPATIDXOBJECT lpATIDXObj );

// In dcicallback.c
extern void __stdcall DCICallback32(DWORD DCICallback32Data, DWORD Event);

// In surface.c
extern DWORD __stdcall CanCreateSurface32( LPDDHAL_CANCREATESURFACEDATA
                                            CanCreateSurfaceData);
extern DWORD __stdcall CreateSurface32( LPDDHAL_CREATESURFACEDATA
                                            CanCreateSurfaceData);
extern DWORD __stdcall DestroySurface32 (LPDDHAL_DESTROYSURFACEDATA
                                            DestroySurfaceData );

// In lock.c
extern DWORD __stdcall Lock32 ( LPDDHAL_LOCKDATA lpLockData );
extern DWORD __stdcall UnLock32 ( LPDDHAL_UNLOCKDATA lpUnLockData );

// In blt.c
extern DWORD __stdcall Blt32 ( LPDDHAL_BLTDATA lpBlt );
extern DWORD __stdcall GetBltStatus32 ( LPDDHAL_GETBLTSTATUSDATA lpGetBltStatus );

// In crtc.c
extern DWORD __stdcall Flip32 ( LPDDHAL_FLIPDATA lpFlipData );
extern DWORD __stdcall WaitForVerticalBlank32 (LPDDHAL_WAITFORVERTICALBLANKDATA
                                                    lpWaitForVerticalBlank );
extern DWORD __stdcall GetScanLine32( LPDDHAL_GETSCANLINEDATA lpGetScanLine );
extern DWORD __stdcall GetFlipStatus32 ( LPDDHAL_GETFLIPSTATUSDATA lpGetFlipStatus );

// In ddsetcaps.c
extern DWORD __stdcall GetDriverInfo32 ( LPDDHAL_GETDRIVERINFODATA );

// In ddmisc.c
extern DWORD __stdcall UpdateOverlay32 (LPDDHAL_UPDATEOVERLAYDATA lpUOData);
extern DWORD __stdcall SetOverlayPosition32 (LPDDHAL_SETOVERLAYPOSITIONDATA lpSOPData);

extern DWORD __stdcall ColorControl32( LPDDHAL_COLORCONTROLDATA lpCCData);
extern DWORD _stdcall GetATISurfAlignment32(LPDDHAL_GETHEAPALIGNMENTDATA lpHAlignData);
extern DWORD _stdcall GetAvailDriverMemory32( LPDDHAL_GETAVAILDRIVERMEMORYDATA lpGADDData );
extern DWORD _stdcall UpdateNONLocalVidmemHeap32(LPDDHAL_UPDATENONLOCALHEAPDATA lpNonLocalData);

extern DWORD __stdcall SetColorKey32( LPDDHAL_SETCOLORKEYDATA lpSetColorKey );

#endif // _ATIDDRAW_H__


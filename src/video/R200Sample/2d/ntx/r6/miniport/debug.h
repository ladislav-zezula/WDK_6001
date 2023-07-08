

/****************************************************************************\
*
*  Module Name    debug.h
*  Project        Longhorn
*  Device         R200
*
*
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
*
\****************************************************************************/

#ifndef _DEBUG_H_
#define _DEBUG_H_

#define DBG_ERROR           0x00000001
#define DBG_RESOURCE_LIST   0x00000002
#define DBG_DMABUF_SUBMIT   0x00000004
#define DBG_CMDBUF_STATS    0x00000008
#define DBG_RES_HANDLES     0x00000010
#define DBG_DRAWCMD         0x00000020

extern BOOLEAN BreakOnAssert;

void R200DebugPrint(DWORD dwLevel, PUCHAR pszString, ...);
void R200SetDebugPrintLevel(DWORD dwLevel);

#if DBG
#define DPF R200DebugPrint
#define DBG_BREAK if (BreakOnAssert) {DbgBreakPoint();}
#else
#define DPF / ## /
#define DBG_BREAK / ## /
#endif 

#define DEBUG_ERROR         0   // Statements with this level should never happen
#define DEBUG_NORMAL        1   // Entry/exit points of major functions and other important information
#define DEBUG_DETAIL	    2	// Detailed debug information

#define ASSERTMP_SOFT(x, y) if (!(x)) DlDebugPrintEx((DEBUG_ERROR, y))

#endif  // _DEBUG_H_


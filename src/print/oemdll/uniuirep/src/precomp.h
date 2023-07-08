//+--------------------------------------------------------------------------
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//  ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//  PARTICULAR PURPOSE.
//
//  Copyright  1997 - 2005  Microsoft Corporation.  All Rights Reserved.
//
//  FILE:	precomp.h
//
//  PURPOSE:	Header files that should be in the precompiled header.
//
//  PLATFORMS:    Windows 2000, Windows XP, Windows Server 2003, Windows Vista
//
//--------------------------------------------------------------------------

#ifndef _PRECOMP_H
#define _PRECOMP_H


// Necessary for compiling under VC.
#if(!defined(WINVER) || (WINVER < 0x0500))
	#undef WINVER
	#define WINVER          0x0500
#endif
#if(!defined(_WIN32_WINNT) || (_WIN32_WINNT < 0x0500))
	#undef _WIN32_WINNT
	#define _WIN32_WINNT    0x0500
#endif


// Required header files that shouldn't change often.


#include <STDDEF.H>
#include <STDLIB.H>
#include <OBJBASE.H>
#include <STDARG.H>
#include <STDIO.H>
#include <INITGUID.H>
#include <WINDOWS.H>

#include <WINDEF.H>
#include <WINERROR.H>
#include <WINBASE.H>
#include <WINGDI.H>
#include <commctrl.h>
#include <WINDDI.H>
#include <WINSPOOL.H>
#include <TCHAR.H>
#include <EXCPT.H>
#include <ASSERT.H>
#include <PRSHT.H>
#include <COMPSTUI.H>
#include <WINDDIUI.H>
#include <PRINTOEM.H>
#include <prcomoem.h>

#include "resource.h"
#include "devmode.h"
#include "Features.h"
#include "uniuirep.h"
#include "debug.h"
#include "intrface.h"

#include <STRSAFE.H>
#include <intsafe.h>

#define COUNTOF(p)  (sizeof(p)/sizeof(*(p)))

#endif




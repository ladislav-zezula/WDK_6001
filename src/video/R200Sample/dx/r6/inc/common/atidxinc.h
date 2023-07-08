

//    
//  $Workfile: atidxinc.h $
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
#ifndef _ATIDXINC_H
#define _ATIDXINC_H


#include <DriverSpecs.h>

__user_code                                                     


// default case is DX8 for everything

#ifndef DIRECT3D_VERSION
#define DIRECT3D_VERSION     0x0800
#endif

#ifndef DIRECTDRAW_VERSION
#define DIRECTDRAW_VERSION   0x0800
#endif


#ifdef WIN2K

#ifndef WHISTLER_DDK
#define WIN32_LEAN_AND_MEAN
#define NT_BUILD_ENVIRONMENT
#define WINNT

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x500
#endif // _WIN32_WINNT

#else
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x501
#endif
#endif // !WHISTLER_DDK


#include <stddef.h>
#include <stdarg.h>
#include <limits.h>

#ifndef D3DLOADER
#include <windef.h>
#include <wingdi.h>
#endif //D3DLOADER

#include <intsafe.h>

#if (DIRECT3D_VERSION >= 0x0900)

#include <d3d9.h>
#include <d3d9types.h>

#ifdef WINNT
#include <d3d8caps.h>
#endif

#else	// DIRECT3D_VERSION >= 0x0900

#include <d3d8.h>
#include <d3d8types.h>

#endif	// DIRECT3D_VERSION >= 0x0900

#include "dx7todx8_2.h"
#define  DX8DDK_DX7HAL_DEFINES   1

#include <winddi.h>
#include <winerror.h>
#include <devioctl.h>

#include "d3dnthal.h"
#include "dmemmgr.h"     
#include "dx95type.h"   
#include "dx95type2.h"

#endif //WIN2K

#ifndef _WIN64
#ifndef DWORD_PTR
// All pointers are 64bit entity in 64bit version of Whistler.
// In order to share source code between 32 and 64 bit version
// MS come up with several new datatypes which automatically
// adjusts its size according to OS.
// i.e. DWORD_PTR  in 32bit-OS is treated as a regular DWORD (32 bit unsigned int)
//                 in 64bit-OS is treated as a DWORD64.(64 bit unsigned int) 
//
// MS failed to define DWORD_PTR for W9x. Since are sharing code between
// W9x and W2K, we have to define DWORD_PTR as DWORD for non 64-bit OS.
//
typedef DWORD DWORD_PTR;
#endif // DWORD_PTR
#endif // _WIN64

//************************************************************************
// Macros to abstract out OS differences -- for some reason, Microsoft 
// insists on renaming structure fields, etc, betwee Win9x and Win2000. 
// Hide these inconsistencies here
//************************************************************************

// Macro: DP2SETLIGHTDATATYPE(pSetLight)
#if (!defined(WHISTLER_DDK) )

#define DP2SETLIGHTDATATYPE(pSetLight) ((LPD3DHAL_DP2SETLIGHT)(pSetLight))->dwDataType

#else

#ifdef WIN2K
#define DP2SETLIGHTDATATYPE(pSetLight) ((LPD3DHAL_DP2SETLIGHT)(pSetLight))->lightData
#endif

#endif

#endif //_ATIDXINC_H



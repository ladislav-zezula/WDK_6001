//    
//
//  PURPOSE:    Header files that should be in the precompiled header.

//
//  PLATFORMS:
//
//    Windows XP, Windows Server 2003
//
//

#ifndef _PRECOMP_H
#define _PRECOMP_H


// Required header files that shouldn't change often.


#include <STDDEF.H>
#include <STDLIB.H>
#include <OBJBASE.H>
#include <STDARG.H>
#include <STDIO.H>
#include <INITGUID.H>
#include <WINDEF.H>
#include <WINERROR.H>
#include <WINBASE.H>
#include <WINGDI.H>
#ifdef __cplusplus
extern "C" 
{
#endif // cplusplus
    #include <WINDDI.H>
#ifdef __cplusplus
}
#endif // cplusplus
#include <TCHAR.H>
#include <EXCPT.H>
#include <ASSERT.H>

#include <PRINTOEM.H>
#include <PRCOMOEM.H>

#include "resource.h"
#include "devmode.h"
#include "debug.h"
#include "oemuni.h"
#include "intrface.h"
#include "ddihook.h"

#include <STRSAFE.H>

#define COUNTOF(p)  (sizeof(p)/sizeof(*(p)))


#endif





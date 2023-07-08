/*****************************************************************************\
* 
*  Module Name    DEBUG.C
*  Project        Longhorn
*  Device         R200
*
*  Description    Contains special debug functions
*
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES
*
\*****************************************************************************/

#if DBG

#include <StrSafe.h>
#include "common.h"
#include "rage.h"
#include "asic.h"

#include "debug.h"
#include "proto.h"
#include "rageio.h"
#include "stdarg.h"


DWORD gdwDbgLevel = DBG_ERROR;

void R200SetDebugPrintLevel(DWORD dwLevel)
{
    gdwDbgLevel=dwLevel;
}


void R200DebugPrint(DWORD dwLevel, PUCHAR pszString, ...)
{
    if ((dwLevel & gdwDbgLevel) != 0)
    {
        HRESULT     hr = S_OK;
        CHAR        szBuf[256] = "R200KMD : ";
        va_list     arglist;
        UINT        uLen = strlen(szBuf);

        va_start(arglist, pszString);        

        if ( SUCCEEDED(hr = StringCbVPrintfA( szBuf + uLen, sizeof(szBuf) - uLen, pszString, arglist ) ) )
        {
#pragma prefast( disable: __WARNING_GRATUITOUS_CALL_TO_FORMAT_FUNCTION, "DbgPrintEx has no good substitute" )
            DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, szBuf);
#pragma prefast( enable: 69 )
        }
    }
    
    return;
}

VOID
DebugAssert(
    BOOL bCondition,
    PUCHAR szFileName,
    ULONG ulLine
    )
//
// DESCRIPTION:
//  Displays assertion message and does INT 3.
//
// PARAMETERS:
//  nCondition          Assertion condition.
//  szFileName          Source file name.
//  ulLine              Line number where assertion happened.
//
{
    if (FALSE == bCondition)
    {
        if (NULL != szFileName)
        {
            DlDebugPrintEx((DEBUG_ERROR, ATI_MINIPORT_STR " Assertion failed: %s, line %lu\n", szFileName, ulLine));
        }

        __debugbreak();      // inline INT 3 on x86 and DebugBreak() on other HW. 
    }
}

#if _PREFAST_ 
/******************************Private*Routine*****************************\
*
* void  die( char* pDbgMsg )
*
* This is a noreturn function for use in PREfast builds by ASSERTs.
* It is used to make ASSERTs non-continuable.  
*
* PARAMETERS:
* pDbgMsg                debug msg from the ASSERT.
*
* RETURN:
* none.
* 
\**************************************************************************/
__declspec(noreturn) void  die(__in  char* pDbgMsg)
{
    // omit code
}
#endif

#endif  // DBG


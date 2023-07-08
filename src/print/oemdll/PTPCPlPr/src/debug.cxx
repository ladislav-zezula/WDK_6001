//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//  ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//  PARTICULAR PURPOSE.
//
//  Copyright  1996 - 2005  Microsoft Corporation.  All Rights Reserved.
//
//  FILE:    debug.cxx
//

#include "precomp.hxx"
#include "debug.hxx"

////////////////////////////////////////////////////////
//      PRIVATE DEFINES
////////////////////////////////////////////////////////

#define PATH_SEPARATOR          '\\'
#define MAX_LOOP                10

// Determine what level of debugging messages to eject. 
#ifdef VERBOSE_MSG
    #define DEBUG_LEVEL     DBG_VERBOSE
#elif TERSE_MSG
    #define DEBUG_LEVEL     DBG_TERSE
#elif WARNING_MSG
    #define DEBUG_LEVEL     DBG_WARNING
#elif ERROR_MSG
    #define DEBUG_LEVEL     DBG_ERROR
#elif RIP_MSG
    #define DEBUG_LEVEL     DBG_RIP
#elif NO_DBG_MSG
    #define DEBUG_LEVEL     DBG_NONE
#else
    #define DEBUG_LEVEL     DBG_WARNING
#endif

////////////////////////////////////////////////////////
//      PUBLIC GLOBALS
////////////////////////////////////////////////////////

INT giDebugLevel = DEBUG_LEVEL;

//////////////////////////////////////////////////////////////////////////
//  Function:	DebugMessageV
//
//  Description:  Outputs variable argument debug string.
//    
//
//  Parameters:	
//
//      dwSize          Size of temp buffer to hold formated string.
//
//      lpszMessage     Format string.
//
//      arglist         Variable argument list..
//    
//
//  Returns:
//    
//
//  Comments:
//     
//
//
//////////////////////////////////////////////////////////////////////////

static BOOL DebugMessageV(DWORD dwSize, LPCSTR lpszMessage, va_list arglist)
{
    DWORD   dwLoop      = 0;
    LPSTR   lpszMsgBuf  = NULL;
    HRESULT hr;

    if( (NULL == lpszMessage)
        ||
        (0 == dwSize)
      )
    {
      return FALSE;
    }

    do
    {
        // Note that deleting NULL's are OK
        delete[] lpszMsgBuf;

        // Allocate memory for message buffer.
        lpszMsgBuf = new CHAR[dwSize + 1];
        if (NULL == lpszMsgBuf)
        {
            return FALSE;
        }

        hr = StringCbVPrintfA(lpszMsgBuf, (dwSize + 1) * sizeof(CHAR), lpszMessage, arglist);

        // Pass the variable parameters to wvsprintf to be formated.

        dwSize *= 2;

    } while (FAILED(hr) && (STRSAFE_E_INSUFFICIENT_BUFFER == hr) && (++dwLoop < MAX_LOOP) );

    // Dump string to Debug output.
    OutputDebugStringA(lpszMsgBuf);

    // Cleanup.
    delete[] lpszMsgBuf;

    return SUCCEEDED(hr);
}


//////////////////////////////////////////////////////////////////////////
//  Function:	DebugMessageV
//
//  Description:  Outputs variable argument debug string.
//    
//
//  Parameters:	
//
//      dwSize          Size of temp buffer to hold formated string.
//
//      lpszMessage     Format string.
//
//      arglist         Variable argument list..
//    
//
//  Returns:
//    
//
//  Comments:
//     
//
//////////////////////////////////////////////////////////////////////////

static BOOL DebugMessageV(DWORD dwSize, LPCWSTR lpszMessage, va_list arglist)
{
    LPWSTR      lpszMsgBuf;
    HRESULT     hResult;


    // Parameter checking.
    if( (NULL == lpszMessage)
        ||
        (0 == dwSize)
      )
    {
      return FALSE;
    }

    // Allocate memory for message buffer.
    lpszMsgBuf = new WCHAR[dwSize + 1];    
    if(NULL == lpszMsgBuf)
        return FALSE;

    // Pass the variable parameters to wvsprintf to be formated.
    hResult = StringCbVPrintfW(lpszMsgBuf, (dwSize + 1) * sizeof(WCHAR), lpszMessage, arglist);

    // Dump string to debug output.
    OutputDebugStringW(lpszMsgBuf);

    // Clean up.
    delete[] lpszMsgBuf;

    return SUCCEEDED(hResult);
}


//////////////////////////////////////////////////////////////////////////
//  Function:	DebugMessage
//
//  Description:  Outputs variable argument debug string.
//    
//
//  Parameters:	
//
//      lpszMessage     Format string.
//
//
//  Returns:
//    
//
//  Comments:
//     
//
//
//////////////////////////////////////////////////////////////////////////

BOOL DebugMessage(LPCSTR lpszMessage, ...)
{
    BOOL    bResult;
    va_list VAList;


    // Pass the variable parameters to DebugMessageV for processing.
    va_start(VAList, lpszMessage);
    bResult = DebugMessageV(MAX_PATH, lpszMessage, VAList);
    va_end(VAList);

    return bResult;
}


//////////////////////////////////////////////////////////////////////////
//  Function:	DebugMessage
//
//  Description:  Outputs variable argument debug string.
//    
//
//  Parameters:	
//
//      lpszMessage     Format string.
//
//
//  Returns:
//    
//
//  Comments:
//     
//
//////////////////////////////////////////////////////////////////////////

BOOL DebugMessage(LPCWSTR lpszMessage, ...)
{
    BOOL    bResult;
    va_list VAList;


    // Pass the variable parameters to DebugMessageV to be processed.
    va_start(VAList, lpszMessage);
    bResult = DebugMessageV(MAX_PATH, lpszMessage, VAList);
    va_end(VAList);

    return bResult;
}

PCSTR
StripDirPrefixA(
    PCSTR    pstrFilename
    )

/*++

Routine Description:

    Strip the directory prefix off a filename (ANSI version)

Arguments:

    pstrFilename - Pointer to filename string

Return Value:

    Pointer to the last component of a filename (without directory prefix)

--*/

{
    PCSTR pstr = strrchr(pstrFilename, PATH_SEPARATOR);
    if (pstr)
        return pstr + 1;

    return pstrFilename;
}


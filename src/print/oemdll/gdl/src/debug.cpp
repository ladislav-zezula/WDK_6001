//+--------------------------------------------------------------------------
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//  ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//  PARTICULAR PURPOSE.
//
//  Copyright  1997 - 2006  Microsoft Corporation.  All Rights Reserved.
//
//  FILE:   debug.cpp
//
//  PURPOSE: Implementation of the COemUIDbg debug class and 
//           its associated debug functions.
//
//  PLATFORMS:    Windows 2000, 
//                Windows XP, 
//                Windows Server 2003, 
//                Windows Vista
//
//--------------------------------------------------------------------------

#include "precomp.h"

//
// Only generate debug output in checked builds.
//
#if DBG

////////////////////////////////////////////////////////
//      INTERNAL DEFINES
////////////////////////////////////////////////////////

#define DEBUG_BUFFER_SIZE       1024
#define PATH_SEPARATOR          '\\'
#define MAX_LOOP                10

//
// This global is controls the verbosity of debug messages.  Although its 
// usually set at compilre time, it can also be controlled from the debugger
// which is useful.
//
INT giDebugLevel = DEBUG_LEVEL;


//+---------------------------------------------------------------------------
//
//  Member:
//      COemUIDbg::COemUIDbg
//
//  Synopsis:
//      Initialize a new debug logging object
//
//
//----------------------------------------------------------------------------
__stdcall 
COemUIDbg::COemUIDbg(
    INT     iDebugLevel,
        // Debug verbosity level for logging creation of this object,
        // usually a message indicating function entry.
    PCWSTR  pszInTag,
        // Name of the function or block currently being debugged.
    __in PCSTR pszFile, 
        // The file the debug object was created in
    DWORD dwLine
        // The source line where the debug object was created.
    ) : 
        m_pcszFile(pszFile),
        m_dwLine(dwLine),
        m_dwStartTime(GetTickCount())
{
    // Check if the debug level is appropriate to output the tag
    if (iDebugLevel >= giDebugLevel)
    {
        PCWSTR pszTag = EnsureLabel(pszInTag, L"??? function entry.");
        OEMDebugMessage(DLLTEXT("%s\r\n"), pszTag);
    }
}

//+---------------------------------------------------------------------------
//
//  Member:
//      COemUIDbg::~COemUIDbg
//
//  Synopsis:
//      virtual destructor.
//
//
//----------------------------------------------------------------------------
__stdcall 
COemUIDbg::~COemUIDbg(
    VOID
    )
{
    //
    // If doing verbose logging, record method times as well.
    //
    if ( DBG_VERBOSE >= giDebugLevel)
        OEMDebugMessage(L"Method Time: %d ms\n", GetTickCount() - m_dwStartTime);

}


//+---------------------------------------------------------------------------
//
//  Member:
//      COemUIDbg::SetMsgLocation
//
//  Synopsis:
//      Set the file & line numbers to display on debug spew.
//
//
//----------------------------------------------------------------------------
VOID 
COemUIDbg::SetMsgLocation(
    __in PCSTR pcszFile,
        // Source file name containing the error message
    DWORD dwLine
        // Line number that generated the message within that file.
    )
{
    m_pcszFile = pcszFile;
    m_dwLine = dwLine;
}


//+---------------------------------------------------------------------------
//
//  Member:
//      COemUIDbg::OEMDebugMessage
//
//  Synopsis:
//      Write a debug message to the appropriate output target,
//      typically the debugger.
//
//  Returns:
//      TRUE if successful, FALSE if there is an error
//
//
//----------------------------------------------------------------------------
BOOL __stdcall
COemUIDbg::OEMDebugMessage(
    LPCWSTR lpszMessage,
        // Format string
    ...
        // Other arguments indicated by format string.
    )
{
    BOOL    bResult;
        // return value indiicating status of the function.

    va_list VAList;
        // varargs list for processing the '...' parameter.

    // Pass the variable parameters to OEMRealDebugMessage to be processed.
    va_start(VAList, lpszMessage);
    bResult = OEMRealDebugMessage(lpszMessage, VAList);
    va_end(VAList);

    return bResult;
}


//+---------------------------------------------------------------------------
//
//  Member:
//      COemUIDbg::OEMRealDebugMessage
//
//  Synopsis:
//      Outputs variable argument debug string.
//
//  Returns:
//      True on success, else FALSE.
//
//
//----------------------------------------------------------------------------
BOOL __stdcall
COemUIDbg::OEMRealDebugMessage(
    LPCWSTR     pszMessage, 
        // Format string for the error message
    va_list     arglist
        // args specified in the format string.
    )
{
    WCHAR szMsgBuf[MAX_PATH] = {0};
        // Use a stack error buffer so that we don't need to 
        // allocate in the failure path.
    
    WCHAR szFinalBuf[MAX_PATH] = {0};
        // After we format the caller's message, we need to 
        // add file & line info.

    HRESULT     hResult;
        // Result from formatting the string.

    // Parameter checking.
    if (NULL == pszMessage)
    {
        return FALSE;
    }

    // Pass the variable parameters to wvsprintf to be formated.
    hResult = StringCbVPrintfW(szMsgBuf, MAX_PATH*sizeof(szMsgBuf[0]), pszMessage, arglist);

    // Add the file & line numbers
    hResult = StringCchPrintfW(szFinalBuf, 
                              MAX_PATH, 
                              L"(%S, %d): %s", 
                              StripDirPrefixA(m_pcszFile), 
                              m_dwLine, 
                              szMsgBuf);


    // Dump string to debug output.
    OutputDebugStringW(szFinalBuf);

    return SUCCEEDED(hResult);
}

//+---------------------------------------------------------------------------
//
//  Member:
//      COemUIDbg::StripDirPrefixA
//
//  Synopsis:
//      Utility function to strip the path from a filename, returning
//      only the name of the file, not it's location.
//
//  Returns:
//      The name of the file without path information.
//
//
//----------------------------------------------------------------------------
PCSTR __stdcall
COemUIDbg::StripDirPrefixA(
    IN PCSTR    pstrFilename
        // Full or relative path name of to file.
    )
{
    PCSTR   pstr = strrchr(pstrFilename, PATH_SEPARATOR);

    if (pstr)
        return pstr + 1;

    return pstrFilename;
}


//+---------------------------------------------------------------------------
//
//  Member:
//      COemUIDbg::EnsureLabel
//
//  Synopsis:
//      Check that the provided method label is not NULL.  If
//      it is NULL or an empty string, return the specified 
//      placeholder label instead.
//
//
//----------------------------------------------------------------------------
PCWSTR __stdcall
COemUIDbg::EnsureLabel(
    PCWSTR      pszInLabel, 
        //  The specified label for the function.
    PCWSTR      pszDefLabel
        // The placeholder label to use if the specified label is not 
        // a valid label string.
    )
{
    //
    // By design, pszDefLabel is assumed to be a valid, non-empty
    // string (since it is supplied internally).
    //
    if (!pszInLabel || !*pszInLabel)
    {
        //
        // The caller supplied a NULL string or empty string;
        // supply the internal default.
        //
        return pszDefLabel;
    }

    return pszInLabel;
}


//+---------------------------------------------------------------------------
//
//  Member:
//      COemUIDbg::vDumpOemDevMode
//
//  Synopsis:
//      Dumps the members of a private OEM devmode (OEMDEV) structure.
//
//
//----------------------------------------------------------------------------
VOID __stdcall
COemUIDbg::vDumpOemDevMode(
    INT             iDebugLevel,
        // desired output debug level
    PCWSTR          pszInLabel,
        // output label string
    __in PCOEMDEV   pOemDevmode
        // pointer to the OEMDEV strct to be dumped
    )
{
    // Check if the debug level is appropriate
    if (iDebugLevel >= giDebugLevel)
    {
        PCWSTR pszLabel = EnsureLabel(pszInLabel, L"pOemDevMode");
            // Prepare the label string
        
        // Return if strct to be dumped is invalid
        if (!pOemDevmode)
        {
            OEMDebugMessage(TEXT("\npOemDevmode [%s]: NULL\r\n"), pszLabel);

            // Nothing else to output
            return;
        }

        // Format the data
        OEMDebugMessage(TEXT("\npOemDevmode [%s]: %#x\r\n"), pszLabel, pOemDevmode);

        if ((pOemDevmode->dmOEMExtra.dwSize >= sizeof(OEMDEV))
            &&
            (OEM_SIGNATURE == pOemDevmode->dmOEMExtra.dwSignature))
        {
            OEMDebugMessage(TEXT("\tdmOEMExtra.dwSize: %d\r\n"), pOemDevmode->dmOEMExtra.dwSize);
            OEMDebugMessage(TEXT("\tdmOEMExtra.dwSignature: %#x\r\n"), pOemDevmode->dmOEMExtra.dwSignature);
            OEMDebugMessage(TEXT("\tdmOEMExtra.dwVersion: %#x\r\n"), pOemDevmode->dmOEMExtra.dwVersion);
        }
        else
        {
            OEMDebugMessage(TEXT("\tUnknown private OEM DEVMODE.\r\n"));
        }

        OEMDebugMessage(TEXT("\n"));
    }
}


//+---------------------------------------------------------------------------
//
//  Member:
//      COemUIDbg::vDumpOemDMParam
//
//  Synopsis:
//      Dumps the members of a OEMDMPARAM structure.
//
//
//----------------------------------------------------------------------------
VOID __stdcall
COemUIDbg::vDumpOemDMParam(
    INT                 iDebugLevel,
        // desired output debug level
    PCWSTR              pszInLabel,
        // output label string
    __in POEMDMPARAM    pOemDMParam
        // pointer to the OEMDMPARAM strct to be dumped
    )
{
    // Check if the debug level is appropriate
    if (iDebugLevel >= giDebugLevel)
    {
        PCWSTR pszLabel = EnsureLabel(pszInLabel, L"pOemDMParam");
            // Prepare the label string
        
        // Return if strct to be dumped is invalid
        if (!pOemDMParam)
        {
            OEMDebugMessage(TEXT("\npOemDMParam [%s]: NULL\r\n"), pszLabel);
        }
        else
        {
            // Format the data
            OEMDebugMessage(TEXT("\npOemDMParam [%s]: %#x\r\n"), pszLabel, pOemDMParam);
            OEMDebugMessage(TEXT("\tcbSize = %d\r\n"), pOemDMParam->cbSize);
            OEMDebugMessage(TEXT("\tpdriverobj = %#x\r\n"), pOemDMParam->pdriverobj);
            OEMDebugMessage(TEXT("\thPrinter = %#x\r\n"), pOemDMParam->hPrinter);
            OEMDebugMessage(TEXT("\thModule = %#x\r\n"), pOemDMParam->hModule);
            OEMDebugMessage(TEXT("\tpPublicDMIn = %#x\r\n"), pOemDMParam->pPublicDMIn);
            OEMDebugMessage(TEXT("\tpPublicDMOut = %#x\r\n"), pOemDMParam->pPublicDMOut);
            OEMDebugMessage(TEXT("\tpOEMDMIn = %#x\r\n"), pOemDMParam->pOEMDMIn);
            OEMDebugMessage(TEXT("\tpOEMDMOut = %#x\r\n"), pOemDMParam->pOEMDMOut);
            OEMDebugMessage(TEXT("\tcbBufSize = %d\r\n"), pOemDMParam->cbBufSize);
            OEMDebugMessage(TEXT("\n"));
        }
    }
}

#endif // DBG build.

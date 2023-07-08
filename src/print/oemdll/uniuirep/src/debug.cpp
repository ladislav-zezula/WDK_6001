//+--------------------------------------------------------------------------
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//  ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//  PARTICULAR PURPOSE.
//
//  Copyright  1997 - 2005  Microsoft Corporation.  All Rights Reserved.
//
//  FILE:   debug.cpp
//
//  PURPOSE: Implementation of the COemUIDbg debug class and 
//           its associated debug functions.
//
//  PLATFORMS:    Windows 2000, Windows XP, Windows Server 2003, Windows Vista
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
// Determine what level of debugging messages to eject. 
//
#ifdef VERBOSE_MSG
#   define DEBUG_LEVEL     DBG_VERBOSE
#elif TERSE_MSG
#   define DEBUG_LEVEL     DBG_TERSE
#elif WARNING_MSG
#   define DEBUG_LEVEL     DBG_WARNING
#elif XVERBOSE_MSG
#   define DEBUG_LEVEL     DBG_XVERBOSE
#elif ERROR_MSG
#   define DEBUG_LEVEL     DBG_ERROR
#elif RIP_MSG
#   define DEBUG_LEVEL     DBG_RIP
#elif NO_DBG_MSG
#   define DEBUG_LEVEL     DBG_NONE
#else
#   define DEBUG_LEVEL     DBG_WARNING
#endif

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
    hResult = StringCchPrintfW(szMsgBuf, MAX_PATH, pszMessage, arglist);

    // Add the file & line numbers
    hResult = StringCbPrintfW(szFinalBuf, 
                              MAX_PATH*sizeof(szFinalBuf[0]), 
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


//+---------------------------------------------------------------------------
//
//  Member:
//      COemUIDbg::vDumpPSUIInfo
//
//  Synopsis:
//      Dumps the members of a PROPSHEETUI_INFO structure.
//
//
//----------------------------------------------------------------------------
VOID __stdcall
COemUIDbg::vDumpPSUIInfo(
    INT                     iDebugLevel,
        // desired output debug level
    PCWSTR                  pszInLabel,
        // output label string
    __in PPROPSHEETUI_INFO  pPSUIInfo
        // pointer to the PROPSHEETUI_INFO strct to be dumped
    )
{
    // Check if the debug level is appropriate
    if (iDebugLevel >= giDebugLevel)
    {
        PCWSTR pszLabel = EnsureLabel(pszInLabel, L"pPSUIInfo");
            // Prepare the label string

        // Return if strct to be dumped is invalid
        if (!pPSUIInfo)
        {
            OEMDebugMessage(TEXT("\npPSUIInfo [%s]: NULL\r\n"), pszLabel);
        }
        else
        {
            // Format the data
            OEMDebugMessage(TEXT("\npPSUIInfo [%s]: %#x\r\n"), pszLabel, pPSUIInfo);
            OEMDebugMessage(TEXT("\tcbSize = %d\r\n"), pPSUIInfo->cbSize);
            OEMDebugMessage(TEXT("\tVersion = %#x\r\n"), pPSUIInfo->Version);
            OEMDebugMessage(TEXT("\tFlags = %#x\r\n"), pPSUIInfo->Flags);
            OEMDebugMessage(TEXT("\tReason = %d\r\n"), pPSUIInfo->Reason);
            OEMDebugMessage(TEXT("\thComPropSheet = %#x\r\n"), pPSUIInfo->hComPropSheet);
            OEMDebugMessage(TEXT("\tpfnComPropSheet = %#x\r\n"), pPSUIInfo->pfnComPropSheet);
            OEMDebugMessage(TEXT("\tlParamInit = %#x\r\n"), pPSUIInfo->lParamInit);
            OEMDebugMessage(TEXT("\tUserData = %#x\r\n"), pPSUIInfo->UserData);
            OEMDebugMessage(TEXT("\tResult = %#x\r\n"), pPSUIInfo->Result);
            OEMDebugMessage(TEXT("\n"));
        }
    }
}


//+---------------------------------------------------------------------------
//
//  Member:
//      COemUIDbg::vDumpOptItem
//
//  Synopsis:
//      Dumps the members of a OPTITEM structure.
//
//
//----------------------------------------------------------------------------
VOID __stdcall
COemUIDbg::vDumpOptItem(
    INT             iDebugLevel,
    PCWSTR          pszInLabel,
    __in POPTITEM   pOptItem
    )
{
    // Check if the debug level is appropriate
    if (iDebugLevel >= giDebugLevel)
    {
        PCWSTR pszLabel = EnsureLabel(pszInLabel, L"pOptItem");
            // Prepare the label string
        
        // Return if strct to be dumped is invalid
        if (!pOptItem)
        {
            OEMDebugMessage(TEXT("\npOptItem [%s]: NULL\r\n"), pszLabel);
        }
        else
        {
            // Format the data
            OEMDebugMessage(TEXT("\npOptItem [%s]: %#x\r\n"), pszLabel, pOptItem);
            OEMDebugMessage(TEXT("\tcbSize = %d\r\n"), pOptItem->cbSize);
            OEMDebugMessage(TEXT("\tLevel = %d\r\n"), pOptItem->Level);
            OEMDebugMessage(TEXT("\tDlgPageIdx = %d\r\n"), pOptItem->DlgPageIdx);
            OEMDebugMessage(TEXT("\tFlags = %#x\r\n"), pOptItem->Flags);
            OEMDebugMessage(TEXT("\tUserData = %#x\r\n"), pOptItem->UserData);
            OEMDebugMessage(TEXT("\tpName = %s\r\n"), pOptItem->pName ? pOptItem->pName : TEXT("NULL"));
            OEMDebugMessage(TEXT("\tpSel = %#x\r\n"), pOptItem->pSel);
            OEMDebugMessage(TEXT("\tpExtChkBox = %#x\r\n"), pOptItem->pExtChkBox);
            OEMDebugMessage(TEXT("\tpExtChkBox = %#x\r\n"), pOptItem->pExtChkBox);
            OEMDebugMessage(TEXT("\tHelpIndex = %#x\r\n"), pOptItem->HelpIndex);
            OEMDebugMessage(TEXT("\tDMPubID = %#x\r\n"), pOptItem->DMPubID);
            OEMDebugMessage(TEXT("\tUserItemID = %#x\r\n"), pOptItem->UserItemID);
            OEMDebugMessage(TEXT("\twReserved = %#x\r\n"), pOptItem->wReserved);
            OEMDebugMessage(TEXT("\tpOIExt = %#x\r\n"), pOptItem->pOIExt);
            vDumpOptType(iDebugLevel, L"pOptType", pOptItem->pOptType);
            OEMDebugMessage(TEXT("\n"));
        }
    }
}


//+---------------------------------------------------------------------------
//
//  Member:
//      COemUIDbg::vDumpOptType
//
//  Synopsis:
//      Dumps the members of a OPTTYPE structure.
//
//
//----------------------------------------------------------------------------
VOID __stdcall
COemUIDbg::vDumpOptType(
    INT             iDebugLevel,
        // desired output debug level
    PCWSTR          pszInLabel,
        // output label string
    __in POPTTYPE   pOptType
        // pointer to the OPTTYPE strct to be dumped
    )
{
    // Check if the debug level is appropriate
    if (iDebugLevel >= giDebugLevel)
    {
        PCWSTR pszLabel = EnsureLabel(pszInLabel, L"pOptType");
            // Prepare the label string

        // Return if strct to be dumped is invalid
        if (!pOptType)
        {
            OEMDebugMessage(TEXT("\tpOptType [%s]: NULL\r\n"), pszLabel);
        }
        else
        {
            // Format the data
            OEMDebugMessage(TEXT("\tpOptType [%s]: %#x\r\n"), pszLabel, pOptType);
            OEMDebugMessage(TEXT("\t\tcbSize = %d\r\n"), pOptType->cbSize);
            OEMDebugMessage(TEXT("\t\tType = %#x\r\n"), pOptType->Type);
            OEMDebugMessage(TEXT("\t\tFlags = %#x\r\n"), pOptType->Flags);
            OEMDebugMessage(TEXT("\t\tCount = %d\r\n"), pOptType->Count);
            OEMDebugMessage(TEXT("\t\tCount = %#x\r\n"), pOptType->BegCtrlID);
            OEMDebugMessage(TEXT("\t\tStyle = %#x\r\n"), pOptType->Style);
            vDumpOptParam(iDebugLevel, L"pOptParam", pOptType->pOptParam, pOptType->Count);
        }
    }
}


//+---------------------------------------------------------------------------
//
//  Member:
//      COemUIDbg::vDumpOptParam
//
//  Synopsis:
//      Dumps the members of a OPTPARAM structure.
//
//
//----------------------------------------------------------------------------
VOID __stdcall
COemUIDbg::vDumpOptParam(
    INT             iDebugLevel,
        // desired output debug level
    PCWSTR          pszInLabel,
        // output label string
    __in_ecount(wCount) POPTPARAM  pOptParam,
        // pointer to the OPTPARAM strct to be dumped
    WORD         wCount
        // number of OPTPARAM structures
    )
{
    // Check if the debug level is appropriate
    if (iDebugLevel >= giDebugLevel)
    {
        PCWSTR pszLabel = EnsureLabel(pszInLabel, L"pOptParam");
            // Prepare the label string
       
        // Return if strct to be dumped is invalid
        if (!pOptParam)
        {
            OEMDebugMessage(TEXT("\t\tpOptParam [%s]: NULL\r\n"), pszLabel);
        }
        else
        {
            // Format the data
            for (WORD wIndex = 0; wIndex < wCount; ++wIndex)
            {
                OEMDebugMessage(TEXT("\t\t%s[%d]: %#x\r\n"), pszLabel, wIndex, pOptParam[wIndex]);
                OEMDebugMessage(TEXT("\t\t\tcbSize = %d\r\n"), pOptParam[wIndex].cbSize);
                OEMDebugMessage(TEXT("\t\t\tFlags = %#x\r\n"), pOptParam[wIndex].Flags);
                OEMDebugMessage(TEXT("\t\t\tStyle = %#x\r\n"), pOptParam[wIndex].Style);
                OEMDebugMessage(TEXT("\t\t\tpData = %#x\r\n"), pOptParam[wIndex].pData);
                OEMDebugMessage(TEXT("\t\t\tIconID = %#x\r\n"), pOptParam[wIndex].IconID);
                OEMDebugMessage(TEXT("\t\t\tlParam = %#x\r\n"), pOptParam[wIndex].lParam);
            }
        }
    }
}

#endif // DBG build.


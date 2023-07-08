//+--------------------------------------------------------------------------
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//  ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//  PARTICULAR PURPOSE.
//
//  Copyright  1997 - 2006  Microsoft Corporation.  All Rights Reserved.
//
//  FILE:   debug.h
//    
//  PURPOSE:    Define common data types, and external function prototypes
//          for debugging functions. Also defines the various debug macros.
//
//  PLATFORMS:    Windows 2000, 
//                Windows XP, 
//                Windows Server 2003, 
//                Windows Vista
//
//--------------------------------------------------------------------------

#pragma once

//
// VC and Build use different debug defines.
// The following makes it so either will
// cause the inclusion of debugging code.
//
#if !defined(_DEBUG) && defined(DBG)
    #define _DEBUG      DBG
#elif defined(_DEBUG) && !defined(DBG)
    #define DBG         _DEBUG
#endif



/////////////////////////////////////////////////////////
//        Macros
/////////////////////////////////////////////////////////

//
// These macros are used for debugging purposes. They expand
// to white spaces on a free build. Here is a brief description
// of what they do and how they are used:
//
// giDebugLevel
//  Global variable which set the current debug level to control
//  the amount of debug messages emitted.
//
// VERBOSE(msg)
//  Display a message if the current debug level is <= DBG_VERBOSE.
//
// WARNING(msg)
//  Display a message if the current debug level is <= DBG_WARNING.
//  The message format is: WRN filename (linenumber): message
//
// ERR(msg)
//  Similiar to WARNING macro above - displays a message
//  if the current debug level is <= DBG_ERROR.
//

#define DBG_VERBOSE 1
#define DBG_WARNING 2
#define DBG_ERROR   3
#define DBG_NONE    4


//
// Determine what level of debugging messages to eject.
// Change this & recompile to change the default level of 
// warning messages generated in checked builds.
//
#define DEBUG_LEVEL     DBG_ERROR

#define DLLTEXT(s)      TEXT("[GDLSMPL]  ") TEXT(s)
#define FUNCTEXT(s)     _T(__FUNCTION__) TEXT(s)
#define ERRORTEXT(s)    TEXT("ERROR ") DLLTEXT(s)

extern INT giDebugLevel;

#if !DBG 
    #define OEMDBG(iDbgLvl, szTag)
    #define DebugMsg    NOP_FUNCTION
    #define VERBOSE     NOP_FUNCTION
    #define WARNING     NOP_FUNCTION
    #define ERR         NOP_FUNCTION

    #define DBG_OEMDEVMODE(iDbgLvl, szLabel, pobj)             NOP_FUNCTION
    #define DBG_OEMDMPARAM(iDbgLvl, szLabel, pobj)             NOP_FUNCTION
#else 

    #define OEMDBG(iDbgLvl, szTag)      COemUIDbg OEMDbg(iDbgLvl, szTag, __FILE__, __LINE__)
    #define DebugMsg    OEMDbg.SetMsgLocation(__FILE__, __LINE__); OEMDbg.OEMDebugMessage
    #define VERBOSE     OEMDbg.SetMsgLocation(__FILE__, __LINE__); if(giDebugLevel <= DBG_VERBOSE) OEMDbg.OEMDebugMessage
    #define WARNING     OEMDbg.SetMsgLocation(__FILE__, __LINE__); if(giDebugLevel <= DBG_WARNING) OEMDbg.OEMDebugMessage
    #define ERR         OEMDbg.SetMsgLocation(__FILE__, __LINE__); if(giDebugLevel <= DBG_ERROR) OEMDbg.OEMDebugMessage

    #define DBG_OEMDEVMODE(iDbgLvl, szLabel, pobj)              {OEMDbg.vDumpOemDevMode(iDbgLvl, szLabel, pobj);}
    #define DBG_OEMDMPARAM(iDbgLvl, szLabel, pobj)              {OEMDbg.vDumpOemDMParam(iDbgLvl, szLabel, pobj);}

    class COemUIDbg
    {
    public:

        COemUIDbg(
            INT iDebugLevel, 
            PCWSTR pszTag, 
            __in PCSTR pszFile, 
            DWORD dwLine
            );

        ~COemUIDbg();

        BOOL __stdcall 
        OEMDebugMessage(
            LPCWSTR, 
            ...
            );

        VOID __stdcall 
        vDumpOemDevMode(
            INT iDebugLevel, 
            PCWSTR pszInLabel, 
            __in PCOEMDEV pOemDevmode
            );

        VOID __stdcall 
        vDumpOemDMParam(
            INT iDebugLevel, 
            PCWSTR pszInLabel, 
            __in POEMDMPARAM pOemDMParam
            );

        VOID 
        SetMsgLocation(
            __in PCSTR pcszFile,
            DWORD dwLine
            );

    private:

        BOOL __stdcall 
        OEMRealDebugMessage(
            LPCWSTR lpszMessage, 
            va_list arglist
            );

        PCSTR __stdcall 
        StripDirPrefixA(
            IN PCSTR    pstrFilename
            );

        PCWSTR __stdcall 
        EnsureLabel(
            PCWSTR pszInLabel, 
            PCWSTR pszDefLabel
            );

        PCSTR m_pcszFile;
            // File name of last error. Points to data section string, 
            // don't release in destructor.

        DWORD m_dwLine;
            // line number of last error.

        DWORD m_dwStartTime;

    };

#endif
     
     


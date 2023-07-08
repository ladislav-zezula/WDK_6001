

//
//  $Workfile: pm4.c $
//
//  Description:
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2000, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

#ifndef _PM4_H_
#define _PM4_H_

#include "qs.h"

/*
 * ATICmndBuffer structure contains all the ATi specific data
 * needed for a command buffer.
 * NOTE: We have problems with the timestamping inside the
 * QS right now, so we are implementing our own.
*/

typedef struct _CMDBUFF
{
    DWORD_PTR        hCB;                            // QS Handle given to this buffer
    DWORD_PTR        lpCBOffset;                     // pointer to free entry in CURRENT CB
    DWORD            dwCBLeftDW;                     // DWORDS left in current CB

    void            *pList;                          // original indirect buffer poitner
    DWORD_PTR        hOutList; 
    DWORD_PTR        dwCBOwner;                      // Context that houses this CB

    // # of DWORD always stored at the begining of each CB. If a CB only contains these DWORD, 
    // no need to do submit.
    DWORD            dwPreambleSize;                 

    // QS info.
    QS_FUNC2   *pQS_APIFunc;
    QS_CAPS    *pQSCaps;
    QS_PARAM   *pQSParam;
    QS_HCLIENT QSHClient;
    QS_HDEVICE QSHDevice;

    LPVOID  pDevObj;

} CMDBUFF, *LPCMDBUFF;
 
void GetNewCB(LPCMDBUFF lpATiCB);
void SubmitCB(LPCMDBUFF lpATiCB, DWORD dwFlags);
void FlushCB(LPCMDBUFF lpATiCB);
void FreeCB(LPCMDBUFF lpATiCB);

LPDWORD WaitPM4Entries(DWORD DriverID, DWORD NumEntriesNeeded, LPCMDBUFF lpCmdB);
void SubmitPM4Entries (DWORD DriverID, DWORD NumEntriesUsed,
                       DWORD dwNumSurfacesUsed, LPCMDBUFF lpCmdB);

BOOL DDSurfTimeStampRetired(LPATISURFINFO lpATISurfInfo, DWORD dwFlags);
BOOL DDSurfFlipTimeStamp (LPATISURFINFO lpATISurfInfo, DWORD dwFlags);

#endif //_PM4_H_

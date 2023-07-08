

/*****************************************************************************\
* 
*  Module Name    ring.h
*  Project        Rage WindowsNT
*  Device         Rage
*
*  Description    header file for Rage driver
*  
*
*  Copyright (C) 1997-2002 ATI Technologies Inc. (unpublished)
*
*  This file contains all the prototypes, constants, structures, etc. that
*  both the display driver and the CMM library need access to.  This header
*  file is shared between 9x and NT.
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
\*****************************************************************************/

#ifndef _RING_H
#define _RING_H

#ifdef __cplusplus
extern "C" {
#endif

/** Return codes from QS API funcitons. */
typedef ULONG QS_RETURNCODE;
/** Handle of the Client driver using the Queue Server. */
typedef ULONG_PTR QS_HCLIENT;

/** Handle uniquely identifying a command list. */
typedef ULONG_PTR QS_HLIST;

typedef struct _QS_PRIVATE_INFO_ *PQS_PRIVATE_INFO;

// FIXME
//**********************************************************
//**********************************************************
//**********************************************************
// Below are the only QS definitions (which are grossly 
// redundant as well) used by the code that is left from the 
// original QS implementation. Unfortunately, cannot redefine 
// them here and get rid of the original QS.H header because 
// QS and CMM definitions are embedded in UMD/KMD interface. 
// CMMQS SHOULD BE REMOVED OUT OF UMD/KMD INTERFACE FIRST 
// BEFORE ANYTHING CAN BE CLEANED UP HERE ANY FURTHER
//**********************************************************
//**********************************************************
//**********************************************************
#include "qs.h"
#if 0
#if !defined(DONT_USE_CMMQS)

typedef struct _QS_PARAM_
{
  DWORD           dwSize;   /**< Size of the structure in bytes. */
  DWORD           dwFlags;  /**< Bit flags specifying how the list is to be submitted. See definitions of QS_FLAG_*. */
  QS_HCLIENT      hClient;  /**< handle of the client */

  QS_HLIST        hInList;  /**< Handle of the list on which the actions will be performed on. */
  QS_HLIST        hOutList; /**< Return value of the handle to the list. */
  DWORD           dwListSize;   /**< Size of the list. */
  LARGE_INTEGER   lTimeStamp;   /**< Last read timestamp from the HW. This field must be aligned on 8-byte (its length) boundary */
  void*           pList;        /**< Pointer to the list on return if successful. */
  DWORD           dwListOffset; /**< Return value is the Memory controller address to the start of the list (for bus mastering access from ASIC). */
  
  // The following two are to be removed because these are no longer needed to submit lists [CB]
  DWORD           dwWindowXOffset;  /**< unused */ 
  DWORD           dwWindowYOffset;  /**< unused */

  DWORD           dwReserved9xLib;
  DWORD           dwDisplayOffset;
  DWORD           padding[2];       /**< add DWORDs to become 16-byte aligned */

} QS_PARAM;

/** Timestamp returned can be used to track when all commands in the list are retired. */
#define QS_FLAG_TIMESTAMP_RETIRED           0x00001000
/** Timestamp returned can be used to track when all commands in the list are consumed. */
#define QS_FLAG_TIMESTAMP_CONSUMED          0x00000800

/** Function was successful, no errors occurred. */
#define QS_OK                          0x00000000
/** Error occurred in the processing of the function, no details on the error are provided.*/
#define QS_ERROR                       0x00000001
/** Error occurred because one of the parameters in function call was bad, or erroneous. */
#define QS_BADPARAMETER                0x00001000

#endif
#endif
//**********************************************************
//**********************************************************
//**********************************************************


///////////////////////////////////////////////////////////
// Prototypes
///////////////////////////////////////////////////////////


PVOID  QS_Initialize (
                     DWORD                   dwAsicFamily,
                     DWORD                   dwAsicID,
                     DWORD                   dwAsicRev,
                     PVOID                   pHwDeviceExtension,
                     PVOID                   pPrivateBuffers
                     );

    // These are the "real" QS functions.  Clients should never
    // call these directly; instead, they should call QSInit()
    // (part of the display driver) and use the function pointers that
    // it returns instead.  Only the display driver's wrappers on these
    // functions should be making these calls directly.

QS_RETURNCODE uQSSubmitList (   PVOID       *pQs,
                                QS_PARAM    *pparam,
                                DWORD       dwEngineID);

QS_RETURNCODE QsSubmitPreemptCmd(PVOID pQs, QS_PARAM *pParam, DWORD dwEngineID);
QS_RETURNCODE QsGetRBInfo(PVOID pQs, PDWORD *ppdwRBBase, PDWORD pdwRBSizeInDWords, PDWORD pdwCurRbWOff);
void QsInsertDummyRingBufCmd(PVOID pQs);
DWORD QsGetCurRBWOffset(PQS_PRIVATE_INFO    pQSprivateInfo);
QS_RETURNCODE uQSSynchronize (PVOID pQs);

BOOL QS_RegisterBuffers(PQS_PRIVATE_INFO pQSprivateInfo);

void qs_ResetAndInitializeGUIAndAssertPM4(PVOID pQs, DWORD dwResetFlags);


// used to define reset and init flags for call to 
// qs_ResetAndInitializeGUIAndAssertPM4
#define RESETGUI_RESET_AND_INIT         0x00000001
#define RESETGUI_ASSERTPM4_ON           0x00000004
#define RESETGUI_ASSERTPM4_OFF          0x00000008


#define PORT_IO_FLAG_READ       0x00000001
#define PORT_IO_FLAG_WRITE      0x00000002
#define PORT_IO_FLAG_RMW        0x00000004

typedef struct _PORT_IO_INPUT {
    DWORD   dwPortFlags;
    DWORD   dwRegOffset;
    union
    {
        DWORD   dwWriteData;
        DWORD   dwRMWData_on;
    };
    DWORD   dwRMWData_off;
} PORT_IO_INPUT, *PPORT_IO_INPUT;


#ifdef __cplusplus
}
#endif

#endif // _RING_H


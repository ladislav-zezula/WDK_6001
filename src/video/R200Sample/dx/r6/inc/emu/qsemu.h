

/****************************************************************************\
* 
*  Module Name    qsemu.h
*  Project        RadeonXXX Queue Server Emulator
*  Device         RadeonXXX (Win95/98 & WinNT 4.0/5.0)
*
*  Description    header file for Emulator
*  
*
*  (c) 1999/2000 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*
*
*  LOG OF CHANGES
*
\****************************************************************************/
#ifdef QS_EMU

#ifndef _QSEMU_H
#define _QSEMU_H

#ifdef __cplusplus
extern "C" {
#endif

/************************************Defines*********************************\
* 
\****************************************************************************/
#define     QSEMU_SLEEP_COUNT             50
#define     QSEMU_SMALL_TIMEOUT_COUNT     0x100
#define     QSEMU_DEFAULT_TIMEOUT_COUNT   0x1000
#define     QSEMU_LONG_TIMEOUT_COUNT      0xFFFF

#define     QSEMU_SHAREDMEM_TOTAL_BYTES       4096
#define     QSEMU_SHAREDMEM_RING_COUNT        16
#define     QSEMU_SHAREDMEM_RING_COUNT_LOG2   4
#define     QSEMU_SHAREDMEM_RING_BYTES        64

#define     QSEMU_SHAREDMEM_ENTRY_BYTES       (QSEMU_SHAREDMEM_TOTAL_BYTES-QSEMU_SHAREDMEM_RING_BYTES)
// This value is in entries (1 entry = 4 bytes...)
#define     QSEMU_SHAREDMEM_ENTRY_SIZE        3
#define     QSEMU_SHAREDMEM_ENTRY_COUNT       (((QSEMU_SHAREDMEM_ENTRY_BYTES/4)-1)/QSEMU_SHAREDMEM_ENTRY_SIZE)
#define     QSEMU_SHAREDMEM_ENTRY_START       0

/* Emulation Codes */
#define     QSEMU_EMUFIFO_FREE             0x00000000
#define     QSEMU_EMUFIFO_LOCK             0xFFFFFFFF
#define     QSEMU_EMUFIFO_UPDATED          0xF0000000

#define     QSEMU_RING_FREE                0x80000000
#define     QSEMU_RING_LOCK                0x80000001

// These are implemented in QS_EMU!
#define     QSEMU_EMUCOMMAND_INDSUBMIT     0x00000001
#define     QSEMU_EMUCOMMAND_MMREAD        0x00000002
#define     QSEMU_EMUCOMMAND_MMWRITE       0x00000004
#define     QSEMU_EMUCOMMAND_IDLE          0x00000008
#define     QSEMU_EMUCOMMAND_SET_CLIP      0x00000010
#define     QSEMU_EMUCOMMAND_STAMP         0x00000020

/* Entry Point Parameter Flags */

// The flag values may be set for calls to QSDebug...
#define     QSEMU_FLAG_QS_WAIT_OK          0x00000001
#define     QSEMU_FLAG_QS_FIFO_OK          0x00000002
#define     QSEMU_FLAG_ENABLE              0x00000004
#define     QSEMU_FLAG_DISABLE             0x00000008
#define     QSEMU_FLAG_REGISTER_CLIENT     0x00000010
#define     QSEMU_FLAG_READ_REG            0x00000020
#define     QSEMU_FLAG_WRITE_REG           0x00000040


/************************************Macros**********************************\
* 
\****************************************************************************/

/* The following routines call the "Sleep" function for performance boost, but if
   the desired driver component does not support sleep, simply build with the 
   preprocessor _NO_SLEEP to build.... (that is, Sleep is not REQUIRED for functionality
   but the emulator may run VERY SLOW). */
#ifdef _NO_SLEEP
#define QSEMU_Sleep(pGlb, dwMilliSec) ;
#else  //_NO_SLEEP is not defined....

#ifdef _DEFAULT_SLEEP
#define QSEMU_Sleep(pGlb, dwMilliSec) Sleep(dwMilliSec);
#else
//extern void QSEMU_Sleep(void *pGlb, DWORD dwMilliSec);
#endif //_DEFAULT_SLEEP

#endif //_NO_SLEEP

/* 
   It is possible for threads to call these functions while in a critical sections!!!!
   Thus, we have to have a timeout period to avoid deadlock scenerios.  Each client must
   handle return values of FALSE in their own way.  Pretty much, a return of false means 
   we were unable to perform the MMIO requested.... 
*/
#define QSEMU_WAIT(pGlb, Condition, pFlags, pTimeout, pTemp)                                    \
{                                                                                               \
    (*(DWORD *)pTemp) = (*(DWORD *)pTimeout);                                                   \
    while ((Condition) && (*(DWORD *)pTemp != 0))                                               \
    {                                                                                           \
        --(*(DWORD *)pTemp);                                                                    \
        QSEMU_Sleep(pGlb, QSEMU_SLEEP_COUNT);                                                   \
    }                                                                                           \
    if (*(DWORD *)pTemp == 0)   (*(DWORD *)pFlags) &= ~QSEMU_FLAG_QS_WAIT_OK;                   \
    else                        (*(DWORD *)pFlags) |= QSEMU_FLAG_QS_WAIT_OK;                    \
}                
/* 
   This macro is used to find the next available slot in the SharedMemory.
   If no space is available, we return the MAX_COUNT but do NOT set the FIFO_OK flag!
*/
#define QSEMU_GET_NEXT_INDEX(pGlb, pEmuSharedMem, pCount, pFlags, pTimeout, pTemp)                          \
{                                                                                                           \
    QSEMU_WAIT(pGlb, (!( (((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START] == QSEMU_EMUFIFO_FREE) ||   \
                       (((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START] == QSEMU_EMUFIFO_UPDATED) )), \
                       pFlags, pTimeout, pTemp);                                                            \
    if (((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START] == QSEMU_EMUFIFO_UPDATED)                     \
    {                                                                                                       \
        ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START] = QSEMU_EMUFIFO_FREE;                         \
    }                                                                                                       \
    (*(DWORD *)pCount) = ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START];                             \
    if ((*(DWORD *)pCount) < QSEMU_SHAREDMEM_ENTRY_COUNT)                                                   \
    {                                                                                                       \
        (*(DWORD *)pFlags) |= QSEMU_FLAG_QS_FIFO_OK;                                                        \
    }                                                                                                       \
}
/* 
   This macro is used submit an EMU command to the next available slot in the SharedMemory.
*/
#define QSEMU_SUBMIT_INDEX(pGlb, pEmuSharedMem, pCount, pFlags, pTimeout, pTemp, dwCommand, dwData0, dwData1)                               \
    {                                                                                                                                       \
    (*(DWORD *)pFlags) &= ~QSEMU_FLAG_QS_WAIT_OK;                                                                                           \
    if (pEmuSharedMem)                                                                                                                      \
    {                                                                                                                                       \
        /*Write to the emulator!*/                                                                                                          \
        QSEMU_GET_NEXT_INDEX(pGlb, pEmuSharedMem, pCount, pFlags, pTimeout, pTemp);                                                         \
        if ((*(DWORD *)pFlags) & QSEMU_FLAG_QS_FIFO_OK)                                                                                     \
        {                                                                                                                                   \
            (*(DWORD *)pCount) = ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START];                                                     \
            ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START] = QSEMU_EMUFIFO_LOCK;                                                     \
            ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START+((*(DWORD *)pCount)*QSEMU_SHAREDMEM_ENTRY_SIZE)+1] = (DWORD)(dwCommand);   \
            ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START+((*(DWORD *)pCount)*QSEMU_SHAREDMEM_ENTRY_SIZE)+2] = (DWORD)(dwData0);     \
            ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START+((*(DWORD *)pCount)*QSEMU_SHAREDMEM_ENTRY_SIZE)+3] = (DWORD)(dwData1);     \
            ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START] = (*(DWORD *)pCount)+1;                                                   \
            if ((*(DWORD *)pFlags) & QSEMU_FLAG_QS_WAIT_OK)                                                                                 \
            {                                                                                                                               \
                QSEMU_WAIT(pGlb, (((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START] != QSEMU_EMUFIFO_UPDATED), pFlags, pTimeout, pTemp);\
            }                                                                                                                               \
        }                                                                                                                                   \
    }                                                                                                                                       \
}


/*******************************Functions************************************\
* 
\****************************************************************************/

/**************************************************************************\
*   QSEMU_IND_SUBMIT
*
*       This macro allows for indirect submit of a buffer to the emulator.
*       Note, if the Emulator is currently not active, 
*       this routine will loop forever...
*
*   Parameters
*
*   pGlb          A pointer to some structure required for the call to QSEMU_Sleep.  
*                 Can be void (depends on how you implement QSEMU_Sleep).
*   pEmuSharedMem This is a pointer to the beginning of the EMU fifo.
*                 Clients can obtain this value from making a call to QSDebug.
*   dwIndOffset   The desired MC address for the i-buffer to submit.
*   dwEntries     The number of entries in the i-buffer.
*   pCount        Local storage used to determine Fifo space used (DWORD *).
*   pFlags        Reflects status of MMIO operation (DWORD *)(see QSEMU_FLAG_???? above).
*   pTimeout      How many tries in waiting before we abort (DWORD *).  Note, this value
*                 is required to avoid deadlocks from threads in critical regions.
*   pTemp         Local storage variable (DWORD *) used for macros...
\****************************************************************************/

#define QSEMU_IND_SUBMIT(pGlb, pEmuSharedMem, dwIndOffset, dwEntries, pCount, pFlags, pTimeout, pTemp)                              \
{                                                                                                                                   \
    QSEMU_SUBMIT_INDEX(pGlb, pEmuSharedMem, pCount, pFlags, pTimeout, pTemp, QSEMU_EMUCOMMAND_INDSUBMIT, dwIndOffset, dwEntries);   \
    /* Now, just tell everone else we are done (if wait successful)!*/                                                              \
    if ((*(DWORD *)pFlags) & QSEMU_FLAG_QS_WAIT_OK)                                                                                 \
    {                                                                                                                               \
        ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START] = QSEMU_EMUFIFO_FREE;                                                 \
    }                                                                                                                               \
}

/**************************************************************************\
*   QSEMU_STAMP
*
*       This macro performs a TimeStamp update to the emulator.
*       Note, if the Emulator is currently not active, 
*       this routine will loop forever...
*
*   Parameters
*
*   pGlb          A pointer to some structure required for the call to QSEMU_Sleep.  
*                 Can be void (depends on how you implement QSEMU_Sleep).
*   pEmuSharedMem This is a pointer to the beginning of the EMU fifo.
*                 Clients can obtain this value from making a call to QSDebug.
*   dwTSLow       The Low DWORD of the TS.
*   dwTSHigh      The High DWORD of the TS.
*   pCount        Local storage used to determine Fifo space used (DWORD *).
*   pFlags        Reflects status of MMIO operation (DWORD *)(see QSEMU_FLAG_???? above).
*   pTimeout      How many tries in waiting before we abort (DWORD *).  Note, this value
*                 is required to avoid deadlocks from threads in critical regions.
*   pTemp         Local storage variable (DWORD *) used for macros...
\****************************************************************************/

#define QSEMU_STAMP(pGlb, pEmuSharedMem, dwTSLow, dwTSHigh, pCount, pFlags, pTimeout, pTemp)                                        \
{                                                                                                                                   \
    QSEMU_SUBMIT_INDEX(pGlb, pEmuSharedMem, pCount, pFlags, pTimeout, pTemp, QSEMU_EMUCOMMAND_STAMP, dwTSLow, dwTSHigh);            \
    /* Now, just tell everone else we are done (if wait successful)!*/                                                              \
    if ((*(DWORD *)pFlags) & QSEMU_FLAG_QS_WAIT_OK)                                                                                 \
    {                                                                                                                               \
        ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START] = QSEMU_EMUFIFO_FREE;                                                 \
    }                                                                                                                               \
}

/**************************************************************************\
*   QSEMU_READ_MM_REG
*
*       This macro allows for the reading of an ASIC register from the
*       running emulator.  
*       Note, if the Emulator is currently not active, 
*       this routine will loop forever...
*
*   Parameters
*
*   pGlb          A pointer to some structure required for the call to QSEMU_Sleep.  
*                 Can be void (depends on how you implement QSEMU_Sleep).
*   pEmuSharedMem This is a pointer to the beginning of the EMU fifo.
*                 Clients can obtain this value from making a call to QSDebug.
*   dwMMOffset    The desired register offset (byte offset and not dword index).
*   pData         Pointer to address to be filled with DWORD data read.
*   pCount        Local storage used to determine Fifo space used (DWORD *).
*   pFlags        Reflects status of MMIO operation (DWORD *)(see QSEMU_FLAG_???? above).
*   pTimeout      How many tries in waiting before we abort (DWORD *).  Note, this value
*                 is required to avoid deadlocks from threads in critical regions.
*   pTemp         Local storage variable (DWORD *) used for macros...
\****************************************************************************/

#define QSEMU_READ_MM_REG(pGlb, pEmuSharedMem, dwMMOffset, pData, pCount, pFlags, pTimeout, pTemp)                              \
{                                                                                                                               \
    QSEMU_SUBMIT_INDEX(pGlb, pEmuSharedMem, pCount, pFlags, pTimeout, pTemp, QSEMU_EMUCOMMAND_MMREAD, (dwMMOffset<<2), 0);      \
    /* Update pData with the value we read!*/                                                                                   \
    *(DWORD *)pData = ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START+((*(DWORD *)pCount)*QSEMU_SHAREDMEM_ENTRY_SIZE)+3];  \
    /* Now, tell everone else we are done if wait was successfull*/                                                             \
    if ((*(DWORD *)pFlags) & QSEMU_FLAG_QS_WAIT_OK)                                                                             \
    {                                                                                                                           \
        ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START] = QSEMU_EMUFIFO_FREE;                                             \
    }                                                                                                                           \
}

/**************************************************************************\
*   QSEMU_WRITE_MM_REG
*
*       This macro allows for the writing of an ASIC register from the
*       running emulator.  
*       Note, if the Emulator is currently not active, 
*       this routine will loop forever...
*
*   Parameters
*
*   pGlb          A pointer to some structure required for the call to QSEMU_Sleep.  
*                 Can be void (depends on how you implement QSEMU_Sleep).
*   pEmuSharedMem This is a pointer to the beginning of the EMU fifo.
*                 Clients can obtain this value from making a call to QSDebug.
*   dwMMOffset    The desired register offset (byte offset and not dword index).
*   dwData        DWORD value to be written into the register write.
*   pCount        Local storage used to determine Fifo space used (DWORD *).
*   pFlags        Reflects status of MMIO operation (DWORD *)(see QSEMU_FLAG_???? above).
*   pTimeout      How many tries in waiting before we abort (DWORD *).  Note, this value
*                 is required to avoid deadlocks from threads in critical regions.
*   pTemp         Local storage variable (DWORD *) used for macros...
\****************************************************************************/
#define QSEMU_WRITE_MM_REG(pGlb, pEmuSharedMem, dwMMOffset, dwData, pCount, pFlags, pTimeout, pTemp)                            \
{                                                                                                                               \
    QSEMU_SUBMIT_INDEX(pGlb, pEmuSharedMem, pCount, pFlags, pTimeout, pTemp, QSEMU_EMUCOMMAND_MMWRITE, (dwMMOffset<<2), dwData);\
    /* Now, tell everone else we are done if wait was successfull*/                                                             \
    if ((*(DWORD *)pFlags) & QSEMU_FLAG_QS_WAIT_OK)                                                                             \
    {                                                                                                                           \
        ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START] = QSEMU_EMUFIFO_FREE;                                             \
    }                                                                                                                           \
}

/**************************************************************************\
*   QSEMU_SET_CLIP
*
*       This macro is used to set the active clip region of the 
*       emulator.
*       Note, if the Emulator is currently not active, 
*       this routine will loop forever...
*
*   Parameters
*
*   pGlb          A pointer to some structure required for the call to QSEMU_Sleep.  
*                 Can be void (depends on how you implement QSEMU_Sleep).
*   pEmuSharedMem This is a pointer to the beginning of the EMU fifo.
*                 Clients can obtain this value from making a call to QSDebug.
*   dwTopLeft     Upper 16 bits is a signed value for top, lower 16 is signed for left.
*   dwBotRight    Upper 16 bits is a signed value for bottom, lower 16 is signed for right.
*   pCount        Local storage used to determine Fifo space used (DWORD *).
*   pFlags        Reflects status of MMIO operation (DWORD *)(see QSEMU_FLAG_???? above).
*   pTimeout      How many tries in waiting before we abort (DWORD *).  Note, this value
*                 is required to avoid deadlocks from threads in critical regions.
*   pTemp         Local storage variable (DWORD *) used for macros...
\****************************************************************************/

#define QSEMU_SET_CLIP(pGlb, pEmuSharedMem, dwTopLeft, dwBotRight, pCount, pFlags, pTimeout, pTemp)                                 \
{                                                                                                                                   \
    QSEMU_SUBMIT_INDEX(pGlb, pEmuSharedMem, pCount, pFlags, pTimeout, pTemp, QSEMU_EMUCOMMAND_SET_CLIP, dwTopLeft, dwBotRight);     \
    /* Now, tell everone else we are done if wait was successfull*/                                                                 \
    if ((*(DWORD *)pFlags) & QSEMU_FLAG_QS_WAIT_OK)                                                                                 \
    {                                                                                                                               \
        ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START] = QSEMU_EMUFIFO_FREE;                                                 \
    }                                                                                                                               \
}

/**************************************************************************\
*   QSEMU_IDLE
*
*       This macro allows for checking if a given running emulator 
*       is currently idle.  
*       Note, if the Emulator is currently not active, 
*       this routine will loop forever...
*
*   Parameters
*
*   pGlb          A pointer to some structure required for the call to QSEMU_Sleep.  
*                 Can be void (depends on how you implement QSEMU_Sleep).
*   pEmuSharedMem This is a pointer to the beginning of the EMU fifo.
*                 Clients can obtain this value from making a call to QSDebug.
*   pData         Pointer to address to be filled with the status (0=no, 1=yes).
*   pCount        Local storage used to determine Fifo space used (DWORD *).
*   pFlags        Reflects status of MMIO operation (DWORD *)(see QSEMU_FLAG_???? above).
*   pTimeout      How many tries in waiting before we abort (DWORD *).  Note, this value
*                 is required to avoid deadlocks from threads in critical regions.
*   pTemp         Local storage variable (DWORD *) used for macros...
\****************************************************************************/

#define QSEMU_IDLE(pGlb, pEmuSharedMem, pData, pCount, pFlags, pTimeout, pTemp)                                                 \
{                                                                                                                               \
    QSEMU_SUBMIT_INDEX(pGlb, pEmuSharedMem, pCount, pFlags, pTimeout, pTemp, QSEMU_EMUCOMMAND_IDLE, 0, 0);                      \
    /* Update pData with the value we read!*/                                                                                   \
    *(DWORD *)pData = ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START+((*(DWORD *)pCount)*QSEMU_SHAREDMEM_ENTRY_SIZE)+3];  \
    /* Now, tell everone else we are done if wait was successfull*/                                                             \
    if ((*(DWORD *)pFlags) & QSEMU_FLAG_QS_WAIT_OK)                                                                             \
    {                                                                                                                           \
        ((DWORD *)pEmuSharedMem)[QSEMU_SHAREDMEM_ENTRY_START] = QSEMU_EMUFIFO_FREE;                                             \
    }                                                                                                                           \
}
/*------------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /*_QSEMU_H*/

#endif QS_EMU


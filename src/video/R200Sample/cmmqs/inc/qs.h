

/** \file qs.h
*   \brief Header file for Queue Server 1.10.9
* 
*  Module Name    qs.h
*  Project        Rage Queue Server
*  Device         Rage (Win95/98 & WinNT4/W2K)
*
*  Description    header file for Queue Server 1.10.9
*  
*
*  CopyRight (c) 1997-2000 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*
*  The Queue Server is a low-level DMA command buffer server that enables
*  its Clients (drivers) to access the Hardware Queue in a uniform, efficient
*  and safe fashion.  Queue Server, denoted QS, permits easy and efficient
*  management of command buffers including underlying memory management.
*
*  The QS serves the following primary purposes:
* 
*  - It provides drivers exclusive, high performance access to Rage/Radeon HW
*    without dealing with the difficulties of resource and semaphore management.
*  - It provides a mechanism to share limited resources within the system between
*    multiple drivers without impactin functionality of the system.
*  - It provides a common* programming interface between Win9x, WinNT4, W2K and 
*    WinXP.
*  - It provides extendibility and transparency of the implementation.
*  - It provides an interface to the Centralized Memory Manager (CMM).
*
*  By abstracting the management of command buffers, and providing exclusive access
*  to Rage/Radeon HW resources, through a series of C-callable API's, QS enables
*  faster development of driers and lower probability of bugs.
*
*  All QS functions begin with the QS prefix.  Qs functions may not communicate
*  directly with the QS.  Differences between WinNT and Win9x are limited, but
*  documented where necessary.
*  
*  The QS Appendix can be found here \ref QSAppendix or in file group__qsapi.html
*/
/** \addtogroup qsapi */
//@{

#ifndef _QS_H
#define _QS_H

#ifdef __cplusplus
extern "C" {
#endif

#define QS_REVISION_MAJOR 0x00000001
#define QS_REVISION_MINOR 0x00001001

#define QS_REVISION (QS_REVISION_MAJOR << 16 | QS_REVISION_MINOR)


/*******************************Type*Definitions*****************************\
* 
\****************************************************************************/

#ifdef _H2INC

#ifndef ULONG
#define ULONG unsigned long
#endif //ULONG

#ifndef LONG
#define LONG long
#endif //LONG

#ifndef DWORD
#define DWORD unsigned long
#endif //DWORD

#ifndef CHAR
#define CHAR char
#endif //CHAR

#ifndef HWND
#define HWND unsigned long
#endif //HWND

#ifndef LARGE_INTEGER
#define LARGE_INTEGER struct\
                      {\
                        unsigned long LowPart;\
                        long HighPart;\
                      }
#endif //LARGE_INTEGER

#endif //_H2INC

#ifndef _WIN64

#ifndef ULONG_PTR
typedef ULONG ULONG_PTR;
#endif // ULONG_PTR
 
#endif // _WIN64

/** Bit pattern of flags used for QS_HLIST management. */
typedef ULONG QS_FLAGS;

/** Return codes from QS API funcitons. */
typedef ULONG QS_RETURNCODE;

/** Handle to the physical device to be managed by the Queue Server. */
typedef ULONG_PTR QS_HDEVICE;

/** Handle of the Client driver using the Queue Server. */
typedef ULONG_PTR QS_HCLIENT;

/** Handle uniquely identifying a command list. */
typedef ULONG_PTR QS_HLIST;

typedef QS_RETURNCODE (__stdcall *QS_EP)();

// We do this because the return code of ExtEscape() for failure is zero and
// we use a return code of zero to indicate success.  The QSNT.LIB XORs this
// value back to zero, so the client is happy.  The end result essentially is
// this -- if the ExtEscape() fails, the client will see a return
// value of 0x7FFFFFFF
#define QS_XOR_MASK 0x7FFFFFFF
#define CONV_TO_QSRETURNCODE(RetVal) (DWORD) RetVal ^ QS_XOR_MASK

// **************************************IMPORTANT***************************
// **************************************Comment Start **********************
// No field in the structures below can be aligned on the boundary smaller 
// than its type length !! Padding size must always provide 16-byte alignment!

/** Define QS_TIMESTAMP to be identical to the Windows definition of a large
 *  integer.  Note that this requires that whoever is including this header file
 *  has previously included the appropriate Windows header files.
 */
typedef LARGE_INTEGER QS_TIMESTAMP;

/** \brief QS Capabilities
 *
 * Structure of capabilities of the Queue Server for a target device.
 */
typedef struct _QS_CAPS_
{
  DWORD           dwSize;                    /**< Size of the structure in bytes */  
  DWORD           dwCaps;                    /**< Bit flags specifying the device capabilities. */  
  union
  {
      DWORD           dwTotalDMAMemory;
      DWORD           dwTotalNonLocalMemory; /**< Total amount of non-local indirect buffer reserved for QS use. */
  }; 
  DWORD           dwListGranularity;         /**< Smallest list granularity in bytes (as managed by the QS). */
  DWORD           dwAsicID;                  /**< ASIC ID code of the target device. */
  DWORD           dwAsicRev;                 /**< ASIC Rev code of the target device. */
  DWORD           dwVideoMemorySize;         /**< Amount of video RAM on the target device. */
  
  /** Total amount of local indirect buffer reserved.  Note, if no local memory is reserved,
   *  local allocations may still be possible (and come out of the surface pool). 
   */
  DWORD           dwTotalLocalMemory;
  DWORD           dwCaps2;      /**< Bit flags specifying the device capabilities. */
#ifdef FGL
  DWORD           dwFireGL_ID;  // Fire GL board identification id -> see defines
  DWORD           padding[2];   // add 1 DWORD to become 16-byte aligned
#else
  DWORD           padding[3];   // add DWORDs to become 16-byte aligned
#endif // FGL

} QS_CAPS;

#ifdef FGL
// Fire GL QS board identification IDs
#define QS_ID_FIREGL_M1_128MB          0x98000128
#define QS_ID_FIREGL_X1_256MB          0x98000256
#endif // FGL

/** \brief QS Parameters to functions.
 *
 * Structure of QS parameters to functions.
 */
typedef struct _QS_PARAM_
{
  DWORD           dwSize;   /**< Size of the structure in bytes. */
  DWORD           dwFlags;  /**< Bit flags specifying how the list is to be submitted. See definitions of QS_FLAG_*. */
  QS_HCLIENT      hClient;  /**< handle of the client */
  QS_HLIST        hInList;  /**< Handle of the list on which the actions will be performed on. */
  QS_HLIST        hOutList; /**< Return value of the handle to the list. */
  DWORD           dwListSize;   /**< Size of the list, this is size of the cmd buf used in bytes */
  DWORD           dwCmdBufSizeInDWORDs; /* Size in DWORDS of current cmd buf */
  QS_TIMESTAMP    lTimeStamp;   /**< Last read timestamp from the HW. This field must be aligned on 8-byte (its length) boundary */
  void*           pList;        /**< Pointer to the list on return if successful. */
  DWORD           dwListOffset; /**< Return value is the Memory controller address to the start of the list (for bus mastering access from ASIC). */
  
  // The following two are to be removed because these are no longer needed to submit lists [CB]
  DWORD           dwWindowXOffset;  /**< unused */ 
  DWORD           dwWindowYOffset;  /**< unused */

  DWORD           dwReserved9xLib;
  DWORD           dwDisplayOffset;
  DWORD           padding[2];       /**< add DWORDs to become 16-byte aligned */

} QS_PARAM;

/** Window handle structure. */
typedef struct _QS_HWND_
{
  DWORD           dwSize;
  DWORD           dwFlags;
  QS_HCLIENT      hClient;      /**< handle of the client for which the window will be tracked. */
  HWND            hWnd;         /**< handle of the window tracked for the client. */
  DWORD           dwPixelFormat;
  DWORD           padding[3];   /**< add DWORDs to become 16-byte aligned */

} QS_HWND;

// Valid versions of the QSEmu emulator 
// Note, the low order word is reserved for minor
// revision communication... (in case different
// releases of the C-model require different 
// initialization from the QS.
//

// Must not grow for this structure is strictly 
// used for "union" into _QS_DEBUG_ struct below...
/** Structure used to communicate register reads/writes. */
typedef struct _QSDEBUG_REGIO_
{
    DWORD dwRegIndex;
    DWORD dwRegValue;
} QSDEBUG_REGIO;

typedef struct _QS_DEBUG_
{
  
  DWORD           dwSize;   /**< Size of the structure in bytes */
  DWORD           dwDebug;  /**< Bit flags settin gdebug states.  See definitions of QS_DEBUG_*. */
  QS_HCLIENT      hClient;  /**< Handle of the client */
  
  union
  {
    /** Maximum amount of data captured to a single file, before opening a new file 
     *  for remaining capture data. 
     */
    DWORD           dwFileSize;
    DWORD           dwQSEMU_Version; // A valid rev defined above
    DWORD           dwQSEMU_Flags;
  };
  
  union
  {
    /** 8 chars, 0 terminated name prefix for the capture file.  QS will append 
     *  a four digits suffix to the end of the nae, starting with 0000.  The file
     *  type will be denoted binary with a file extnsion of type '.bin'
     */
    CHAR            sFileName[8];
    DWORD           QSEMU_Reserved[2];
    QSDEBUG_REGIO   sQSEMU_RegIO;
    QS_TIMESTAMP    lTimedSubmits;
  };
  
  HWND            hRegisteredHwnd;
  
  /** add BYTEs to become 16-byte aligned. */
  DWORD           padding[1]; 

} QS_DEBUG;


typedef struct _QS_SUBMIT_IDCT_
{
    
    DWORD           dwSize;             /**< sizeof(struct _QS_SUBMIT_IDCT_).*/               
    DWORD           dwPM4QSFlags;       /**< QS_FLAG_*.*/            
    DWORD           dwDCTFlags;         /**< QS_FLAG_*.*/        
    DWORD           dwDCTRing1Bytes;    /**< number of bytes to copy to idct ring.*/       
    DWORD           dwDCTRing2Bytes;    /**< number of bytes to copy to idct ring.*/      
    DWORD           dwPM4List1Bytes;    /**< number of bytes in PM4 list */         
    DWORD           dwPM4List2Bytes;    /**< number of bytes in PM4 list */        
    DWORD           dwDCTList1Bytes;    /**< number of bytes used in DCT list */        
    DWORD           dwDCTList2Bytes;    /**< number of bytes used in DCT list */         
    QS_TIMESTAMP    liPM4TimeStamp;     /**< TS returned by queue server */    
    QS_TIMESTAMP    liDCTTimeStamp;     /**< TS returned by queue server */ 
    QS_HCLIENT      hClient;            /**< from QSRegisterClient */         
    QS_HLIST        hDCTList1;          /**< from QSAllocList */         
    QS_HLIST        hDCTList2;          /**< from QSAllocList */                
    QS_HLIST        hPM4List1;          /**< from QSAllocList */               
    QS_HLIST        hPM4List2;          /**< from QSAllocList */               
    DWORD          *pDCTRingList1;      /**< copy this data to the idct ring */    
    DWORD          *pDCTRingList2;      /**< copy this data to the idct ring */
//  DWORD           padding[x];         // 16 byte align

} QS_SUBMIT_IDCT;

//No field in the structures above can be aligned on the boundary smaller
//than its type length!!!!
//Padding size must always provide 16-byte alignment!
//********************* Comment End *************************************

/** dwDCTFlags */
#define QS_IDCT_SUBMIT_PM4_FIRST	1

/** QSIdctControl2 opcodes */
#define QS_IDCT_SUBMIT_LISTS            0

#define QS_IDCT_SYNCHRONIZE             1

#define QS_IDCT_TIMESTAMP_RETIRED       2

// QSIdctControl2 'protoypes' :

// submit lists to idct and/or pm4 engines
// QSIdctControl2 (QS_HDEVICE hDevice, QS_IDCT_SUBMIT_LISTS, QS_SUBMIT_IDCT *p)

// wait for the idct engine to idle - analogous to QSSynchronize2
// QSIdctControl2 (QS_HDEVICE hDevice, QS_IDCT_SYNCHRONIZE, PVOID NULL)

// query/wait the idct timestamp - analogous to QSTimeStampRetired,
// but uses a QS_PARAM to pass the client handle, flags, and timestamp.
// set pParam->dwSize, pParam->hClient, pParam->dwFlags = 0 or QS_FLAG_WAIT,
// pParam->lTimeStamp = value to query or wait for.
// QSIdctControl2 (QS_HDEVICE hDevice, QS_IDCT_QUERY_TIMESTAMP, QS_PARAM *p)



/** The scratch register pointer that gets passed to the user on a
 *  scratch register access request.
 */
typedef struct QS_SCRATCH_REGISTERS
{
    
    QS_TIMESTAMP const volatile tsLastReadRetired;      /** [GUI_]SCRATCH_REG0 and 1 */   
    QS_TIMESTAMP const volatile tsLastReadConsumed;     /** [GUI_]SCRATCH_REG2 and 3 */    
    DWORD const volatile        dwBitBltCommandThrottle;/** [GUI_]SCRATCH_REG4 */   
    DWORD const volatile        dwPixelCachePurge;      /** [GUI_]SCRATCH_REG5 */    
    DWORD const volatile        dw3dScratchRegister0;   /**  SCRATCH_REG6 */    
    DWORD const volatile        dw3dScratchRegister1;   /**  SCRATCH_REG7 */

    /**  Names reflect the r300 idct registers that are written here,
     *   currently we use these for a 64 bit timestamp.
     */
    DWORD const volatile        dwDCTScratchRegister0;
    DWORD const volatile        dwDCTTimeStamp;

} QS_SCRATCH_REGISTERS, *PQS_SCRATCH_REGISTERS;


/** Parameter structure for the call to get the scratch registers */
typedef struct QS_SCRATCH_REGISTER_PARAMETERS
{
    /** Handle to the registered client. */
    QS_HCLIENT              hClient;
   
    /**  Flags that indicate which ASIC (in multi-ASIC boards) to query
     *   and which scratch registers to read. See QS_SCRATCH_xxx below.
     */
    DWORD                   dwReadSelector;
  
    /** Bit(s) will be set in this field if the corresponding scratch
     *  register is being DMAed back. See QS_SCRATCH_xxx below.
     */
    DWORD                   dwDmaStatus;
    
    /** Pointer to the scratch registers. */
    PQS_SCRATCH_REGISTERS   pRegisters;

} QS_SCRATCH_REGISTER_PARAMETERS, *PQS_SCRATCH_REGISTER_PARAMETERS;


#define QS_STATE_PARAM_SET_READ_ONLY_PM4_TS     0x00000001
#define QS_STATE_PARAM_SET_PM4_TS_INTERRUPT     0x00000002

#define QS_STATE_PARAM_SET_MASK                 ( QS_STATE_PARAM_SET_READ_ONLY_PM4_TS       \
                                                | QS_STATE_PARAM_SET_PM4_TS_INTERRUPT       \
                                                  )
#define QS_STATE_PARAM_SET_MASK_IN              (QS_STATE_PARAM_SET_MASK & ~(               \
                                                    QS_STATE_PARAM_SET_READ_ONLY_PM4_TS     \
                                                  ))

/** State info for querying retired TS (Out).
 */
typedef struct QS_STATE_PM4_TS
{
    QS_TIMESTAMP    lTSLastSubmitted;   /**< TS last submitted */
    DWORD           dwTSDeltaRetired;   /**< difference between last submitted TS and retired TS */

} QS_STATE_PM4_TS, *PQS_STATE_PM4_TS;


/** State info for PM4 TS Interrupt (In and Out).
 *  Note, this structure may be susceptible to changes and as such has to reserve some space
 */
#define QS_STATE_PM4_TS_INTERRUPT_FLAG_DISABLE_INTERRUPTS    0x00000001

typedef struct QS_STATE_PM4_TS_INTERRUPT
{
    DWORD           dwFlags;           /**< QS_STATE_PM4_TS_INTERRUPT_FLAG_XXX flags. */
    DWORD           dwPollingCount;    /**< Times to poll for TS before blocking wait */
    DWORD           dwWaitRetryCount;  /**< Times to retry blocking wait before querying for time is 'safe' */
    DWORD           dwPollAheadCount;  /**< The difference between the desired TS and the TS to start polling instead of blocking */
    DWORD           dwPriorityBoost;   /**< Dynamic priority boost to apply to the TS waiting thread when the wait condition is satisfied */
    DWORD           dwReserved1;       /**< Reserved. Must be set to zero by the client. */
    DWORD           dwReserved2;       /**< Reserved. Must be set to zero by the client. */
    DWORD           dwReserved3;       /**< Reserved. Must be set to zero by the client. */

} QS_STATE_PM4_TS_INTERRUPT, *PQS_STATE_PM4_TS_INTERRUPT;


/** Out parameter structure for the call to query and set misc state.
 *  Note, should not change places of the existing fields. New fields should 
 *  be added at the end. If the size field is less than the total structure size 
 *  then we can still support the older clients.
 */
typedef struct QS_STATE_OUT
{
    DWORD                       dwSize;       /**< Total size of the output structure in bytes returned by QS */

    QS_STATE_PM4_TS             TimeStamp;    /**< Last updated time stamp information. This parameter set is read-only */
    QS_STATE_PM4_TS_INTERRUPT   PM4Interrupt; /**< Current parameter set for tuning the TS waiting loop */

    DWORD                       padding[2];   // reserved + 16 byte align for 32-bit platform

} QS_STATE_OUT, *PQS_STATE_OUT;


/** In parameter structure for the call to query and set misc state 
 *  Note, should not change places of the existing fields. New fields should 
 *  be added at the end. If the size field is less than the total structure size 
 *  then we can still support the older clients.
 */
typedef struct QS_STATE_IN
{
    DWORD                       dwSize;         /**< Total size of the input structure (this structure) in bytes */
    QS_HCLIENT                  hClient;        /**< Handle of the client */
    DWORD                       dwParamSets;    /**< Flags that indicate which optional parameter sets to set */

    DWORD                       dwSizeOut;      /**< Total size of the output structure in bytes */
    DWORD                       dwParamSetsOut; /**< Flags that indicate which optional parameter sets to query */

    QS_STATE_PM4_TS_INTERRUPT   PM4Interrupt;   /**< New parameter set for tuning the TS waiting loop */

    DWORD                       padding[3];     // reserved + 16 byte align for 32-bit platform

} QS_STATE_IN, *PQS_STATE_IN;

/************************************Defines*********************************\
* 
\****************************************************************************/

/* Return Codes */

/** Function was successful, no errors occurred. */
#define QS_OK                          0x00000000

/** Error occurred in the processing of the function, no details on the error are provided.*/
#define QS_ERROR                       0x00000001

/** Unknown generic error occurred. */
#define QS_UNKNOWNERROR                0x00000002

/** If a QS client calls QSSubmitList with the flag "QS_FLAG_MODE_SET_CHANGE_NOTIFY", 
*   QS will return this error if a mode set has occurred (and continues
*   to return this error code until the mode set is acknowledged with the flag
*   "QS_FLAG_MODE_SET_ACKNOWLEDGED").
*/
#define QS_MODE_SET_OCCURRED           0x00000003

/** Function not supported by QS */
#define QS_NOTSUPPORTED                0x00000004

/** If a QS client calls QSSubmitList with the flag "QS_FLAG_MODE_SET_CHANGE_NOTIFY", 
*   QS will return this error if a mode set has occurred AND the new mode
*   is not a supported HW acceleration mode for 3D (and continues
*   to return this error code until the mode set is acknowledged with the flag
*   "QS_FLAG_MODE_SET_ACKNOWLEDGED").
*/
#define QS_MODE_SET_OCCURRED_TO_NO_3D  0x00000005

/** If a QS client calls QSSubmitList with the flag "QS_FLAG_SURFACE_EVICT_NOTIFY"
*   QS will return this error if any surface evictions have occurred since the
*   last time this client submitted to the QS. 
*   Clients should simply check all of their surfaces (and respond accordingly)
*   before calling QsSubmitList again.
*   Note, no acknowledgement is required (rather - it is assumed).
*/
#define QS_SURFACES_EVICTED            0x00000006


/** DMA is not available. */
#define QS_DMAUNAVAILABLE              0x00000010

/** Error occurred because the QS failed to initialize. */
#define QS_CANNOTINIT                  0x00000020

/** Error occurred because the version of the QS specified by the caller is not supported. */
#define QS_VERSIONNOTSUPPORTED         0x00000030

/** Error occurred because the version of the QS does not match the version used by the caller. */
#define QS_VERSIONMISMATCH             0x00000040

/** Error occurred registering a new client because too many clients are active. */
#define QS_TOOMANYCLIENTS              0x00000050

/** Error occurred because a client cannot be registered. */
#define QS_CANNOTREGISTERCLIENT        0x00000060

/** Error occurred because the client handle is not registered. */
#define QS_CLIENTNOTREGISTERED         0x00000070

/** Error occurred because QS was passed an invalid client handle. */
#define QS_INVALIDCLIENT               0x00000080

#define QS_CLIENTLOST                  0x00000081

/** Error occurred trying to query the capabilities of the QS. */
#define QS_CANNOTQUERYCAPABILITIES     0x00000090

#define QS_TOOMANY_LISTS_HELD          0x000000A0


/** Error occurred because no free list memory is available to service the memory request. */
#define QS_NOMEMORY                    0x00000100

/** Error occurred because the requested allocation size exceeds the total amount of DMA memory. */
#define QS_SIZEEXCEEDSTOTALMEMORY      0x00000200

/** Error occurred because QS is managing too many lists. */
#define QS_TOOMANYLISTS                0x00000300

/** Error occurred because an invalid list handle was passed to the QS. */
#define QS_INVALIDLIST                 0x00000400


/** Error occurred because the size of a structure did not match. */
#define QS_PARAMETERSIZEMISMATCH       0x00000800

/** Error occurred because one of the parameters in function call was bad, or erroneous. */
#define QS_BADPARAMETER                0x00001000

#define QS_FAILEDTOMAPMEMORY           0x00002000

/** Error occurred because the QS failed to allocate the required user memory to manage the client. */
#define QS_FAILEDTOALLOCATEUSERMEM     0x00004000


/** Error occurred because the time stamp has not elapsed on the hardware. */
#define QS_HASNOTELAPSED               0x00010000

/** Error occurred because the size of the list is not aligned on a boundary as required by the hardware. */
#define QS_SIZENOTALIGNED              0x00020000

/** Error occurred because the hardware is not in an accelerator mode, and cannot process the list at this time. */
#define QS_HARDWARENOTACTIVE           0x00040000


#define QS_9X_SYNCH_CHECKSUM           0x00100000
#define QS_9X_SYNCH_WPTR               0x00200000

#define QS_MUST_CREATE_WNDOBJ          0x00400000
#define QS_PRIMARY_LOCK_REQUIRED       0x00800000

/** Error occurred because the QSSubmitList call requested a flip to occur, but the device is not ready.
 *  The requested flip did not occur.  If a list was submitted during the call, it will be processed.
 */
#define QS_FLIP_NOT_READY              0x01000000

/** Obsolete - Error occurred because client specified the QS_SECONDARY flag, but there is no secondary device. */
#define QS_NO_SECONDARY_DEVICE         0x02000000

/** Error occurred because the timeout limit was reached by QS while waiting for the operation to complete;
 *  the client may want to retry the same operation repeatedly until success or failure (indicated by
 *  anothererror code). 
 */
#define QS_TIMED_OUT                   0x04000000

/** A return value greater then or equal to the following
 * error code indicates that the call was not processed by 
 * the QS (and most likely... the Device is no longer valid). [RA]
 */
#define QS_INVALID_DEVICE              0x70000000


/* Capabilties Flags */

#define QS_CAPS_PCIDMA                      0x00000001
#define QS_CAPS_AGP                         0x00000002
#define QS_CAPS_USWC                        0x00000004
#define QS_CAPS_USESRDTSC                   0x00000008
#define QS_CAPS_AGP1X                       0x00000010
#define QS_CAPS_AGP2X                       0x00000020
#define QS_CAPS_AGP4X                       0x00000040
#define QS_CAPS_HWNDTRACKING                0x00000080
#define QS_CAPS_FREES_UNUSEDMEM             0x00000100
#define QS_CAPS_FLIP                        0x00000200
#define QS_CAPS_AURORA                      0x00000400 // Obsolete
#define QS_CAPS_LISTSLOCAL                  0x00000800
#define QS_CAPS_LISTSNONLOCAL               0x00001000
#define QS_CAPS_CONTEXT                     0x00002000
#define QS_CAPS_MULTITIMESTAMP              0x00004000
#define QS_CAPS_DEBUG                       0x00008000
#define QS_CAPS_QSEMU                       0x00010000
#define QS_CAPS_WSBOARD                     0x00020000
#define QS_CAPS_TIMEDSUBMITS                0x00040000

/** Indicates that the QS will return an error message on QSSubmitList if the primary must be locked
 *  to avoid corruption due to window occlusion (if asked to do so).
 */
#define QS_CAPS_PRIMARYLOCK_REPORT          0x00080000
#define QS_CAPS_MC_REDEFINE                 0x00100000
#define QS_CAPS_CENTRAL_MEM_MGR             0x00200000
#define QS_CAPS_RING_CAPTURE                0x00400000
#define QS_CAPS_HWND_MODECHANGE_NOTIFY      0x00800000

/** When set, The QS will return an error on QSSubmitList IFF a mode set has occurred since the last submit
 *  (if asked to do so).
 */
#define QS_CAPS_NOTIFY_ON_MODE_SET          0x01000000
#define QS_CAPS_MULTI_CLIP                  0x02000000
#define QS_CAPS_GET_SCRATCH_REGISTERS       0x04000000
#define QS_CAPS_SUBTRACTIVE_CLIPPING        0x08000000
#define QS_CAPS_TEAR_FREE                   0x10000000

/** Set if the CMM is capable of locking pageable memory (for access by ASIC via PCI gart or AGP bus mastering. */
#define QS_CAPS_LOCK_MEMORY                 0x20000000
#define QS_CAPS_IDCT                        0x40000000

/** Set if the QS supports timeouts in QSTimeStampConsumed / QSTimeStampComsumed2, QSAllocList / QSAllocList2, and
 *  QSTimeStampRetired / QSTimeStampRetired2, by returning QS_TIMED_OUT (or QS_NOMEMORY in the latter case). 
 *  The timeout is only enabled if the client specifies QS_FLAG_WAIT in the QS functions listed above.
 */
#define QS_CAPS_TIMEOUT_ENABLED             0x80000000

/** Set if the QS employs PM4 interrupts to relinquish CPU when ASIC is busy. This is completely transparent 
 *  to the client from the API side, it is solely provided as a hint for possible optimizations on the client 
 *  side.
 */
#define QS_CAPS2_INTERRUPT_ENABLED          0x00000001

/** QSQueryAndSetState is supported.
 */
#define QS_CAPS2_QUERY_AND_SET_STATE        0x00000002

/** QS supports notification of evicted surfaces
 *  during call to QSSubmitList.
 */
#define QS_CAPS2_SURF_EVICT_NOTIFY          0x00000004

/** QS supports saving/restoring client state
 *  during call to QSSubmitList.
 */
#define QS_CAPS2_CONTEXT_SWITCH             0x00000008

/* Entry Point Parameter Flags */

/** Mark the list as free immediately. */
#define QS_FLAG_FREE_NOW                    0x00000000

/** List is to remain allocated to the client. */
#define QS_FLAG_REUSE                       0x00000001

#define QS_FLAG_ALLOC                       0x00000002

/** Post a current time stamp to the HW Queue and timestamp the list.
 *  List will be freed only after all submitted lists are retired.
 */
#define QS_FLAG_FREE_ONALLDONE              0x00000004

/** Mark the list with the timestamp provided and free when the timestamp is retired. (all instructions executed).
 *  When set, the QS will synchronize the list against the timestamp specified.  If it is larger than the newest
 *  timestamp the QS has uploaded to the device, the QS will NOT upload a new timestamp to ensure the timestamp
 *  specified to free agaist will elapse avoiding a potential deadlock. 
 */
#define QS_FLAG_FREE_ONTIMESTAMP            0x00000008


/** Hint to allocate a smaller list than requested if the function cannot allocate a list of the size requested. */
#define QS_FLAG_ALLOC_SMALLER               0x00000010

/** Frees unused pages immediately (in the case QS_FLAG_FREE_ONALLDONE or the QS_FLAG_FREE_ONTIMESTAMP are set. 
 *  This should ONLY be set if the current QS is capable of freeing unused memory. (QSQueryCaps set the bit
 *  QS_CAPS_FREE_UNUSEDMEM in pCaps->dwCaps).
 */
#define QS_FLAG_FREE_UNUSEDMEM              0x00000020

/** Buffer flip queued for a vertical flip to offset specified in dwDisplayOffset in the QS_PARAM structure. */
#define QS_FLAG_FLIP_VERTICAL               0x00000040

/** Buffer flip queued for a horizontal flip to offset specified in dwDisplayOffset in the QS_PARAM structure. */
#define QS_FLAG_FLIP_HORIZONTAL             0x00000080


/** Used in combination with flip flags, specifying a WAIT_UNTIL command to be queued to the target device
 *  to stall the rendering until th eflip has completed. 
 */
#define QS_FLAG_FLIP_QUEUE_WAIT             0x00000100

/** Obsolete - Specifying the primary device. */ 
#define QS_FLAG_PRIMARY                     0x00000200

/** Obsolete - Specifying the secondary device. */
#define QS_FLAG_SECONDARY                   0x00000400

/** Timestamp returned can be used to track when all commands in the list are consumed. */
#define QS_FLAG_TIMESTAMP_CONSUMED          0x00000800

/** Timestamp returned can be used to track when all commands in the list are retired. */
#define QS_FLAG_TIMESTAMP_RETIRED           0x00001000

/** Forces allocation to come from local(frame buffer) pool */
#define QS_FLAG_ALLOC_LOCAL                 0x00002000

/** Forces allocation to come from nonlocal(AGP or PCI Gart) pool. */
#define QS_FLAG_ALLOC_NONLOCAL              0x00004000


/** Specifies the QS should attempt adjust the starting of the command list by dwListOffset bytes when
 *  the last client was the last client in the system. 
 */
#define QS_FLAG_CONTEXT                     0x00008000

/** Causes the QS to wait until the time stamp has been retired, or timeout occurs, whichever is first. */
#define QS_FLAG_WAIT                        0x00010000

/** mark the list with the timestamp provided and free when the timestamp is consumed (all instructions fetched). 
 *  When specified, the QS will synchronize the list against the timestamp specified.  If it is larger than the newest
 *  timestamp the QS has uploaded to the device, the QS will NOT upload a new timestamp to ensure the timestamp
 *  specified to free agaist will elapse avoiding a potential deadlock.  
 */
#define QS_FLAG_FREE_CONSUMED               0x00020000

/** This is also a flag to QSSumbitList that forces a fail
    of the submit if there is any competing rendering to the
    "drawing context" of the client, such as software cursor.
    Upon failure, the client needs to wait for idle, lock the primary,
    call QSSubmitList again with this flag cleared, wait for idle,
    and then unlock the primary.

	Starting with W2K, the DDK added support for tearing down and
    redrawing these "sprites". Thus, this support is needed for NT4
    and all 9x versions.
*/ 
#define QS_FLAG_CHECK_PRIMARYLOCK           0x00040000

#define QS_FLAG_MC_REDEFINE                 0x00080000 
#define QS_FLAG_HWND_MODECHANGE_NOTIFY      0x00100000 
#define QS_FLAG_ALLOC_EXPIREONRESET         0x00200000 
#define QS_FLAG_MODE_SET_CHANGE_NOTIFY      0x00200000 
#define QS_FLAG_MODE_SET_ACKNOWLEDGED       0x00400000 
#define QS_FLAG_IS_RING3_CLIENT             0x00800000 
#define QS_FLAG_USE_MULTI_CLIP              0x01000000
#define QS_FLAG_USE_SUBTRACTIVE_CLIPPING    0x02000000

/** This is a flag to QSSumbitList that forces the submit
    to wait for the next VSYNCH of the monitor. 
    Thus, front buffer rendering does not produce any tearing
    (no updates to FB compete with fetches from DAC to CRTC).
  */
#define QS_FLAG_TEAR_FREE                   0x04000000

#define QS_FLAG_HWND_OVERLAY                0x08000000
#define QS_FLAG_SURFACE_EVICT_NOTIFY        0x10000000

/** QS sets this to indicate to a client that the client is currently
*   the only (active) QS client (see QS_DEBUG_CONTEXT_SWITCH_LITE).
*   This flag is only meaningful if context switching is supported
*   (QS_CAPS2_CONTEXT_SWITCH).
*/
#define QS_FLAG_SOLE_CLIENT                 0x20000000

/** Indicates to QS that a submitted list will not alter any
*   context-switchable state in the ASIC, and therefore the submit
*   is a nop with respect to context switching.
*   This flag is only meaningful if context switching is supported
*   (QS_CAPS2_CONTEXT_SWITCH).
*/
#define QS_FLAG_NO_SWITCHABLE_STATE         0x40000000

#if defined (LHVIDMM)
//
// Flag bit runs out !!! 
//     When QS_PARAM::pList is NULL, the current central TS is returned,
//     Otherwise commands are submitted through the ring buffer directly
//
#define QS_FLAG_GET_CUR_TIMESTAMP           0x80000000
#define QS_FLAG_SUBMIT_RING_COMMAND         0x80000000
#endif // LHVIDMM

/* QSInit flags */

/** NT4, W2K clients. */
#define QS_INITFLAG_NT_CLIENT               0x00000001 

/** 9X clients */
#define QS_INITFLAG_9X_CLIENT               0x00000002 

/** D3D & Direct Draw */
#define QS_INITFLAG_RING0_CLIENT            0x00000004

/** OGL, DVD, and User mode clients */ 
#define QS_INITFLAG_RING3_CLIENT            0x00000008

/** For win9x, bypasses ExtEscape for QSSubmitList, QSAllocList, QSTimestampRetired, and QSTimestampConsumed. */ 
#define QS_INITFLAG_RING3_FAST_CLIENT       0x00000010


/* Debug Entry Point Parameter Flags */

/** Enables infinitely fast hardware mode.  
 *  Causes the QS to stop submitting of the data into the ring buffer.  This simulates infinitely fast
 *  hardware while continuing to execute most of the software stack.
 *  QS_DEBUG_IFHDISABLE turns off infinitely fast HW mode.
 */
#define QS_DEBUG_IFHENABLE                  0x00000001

/** Disabled infinitely fast hardware mode. */
#define QS_DEBUG_IFHDISABLE                 0x00000002

/** Enables capture of QS submits to disk. 
 *
 *  When set, the QS uses the dwFileSize parameter to specify the maximum size for capture files.
 *  If this value is less than 1MB the QS will default to a value of 1MB.  If the size of the capture file
 *  exceeds the dwFileSize, the current capture file will be closed, and a new capture file with an 
 *  incremented numerical suffix will be opened.  i.e. if sFileName is "WB99" the QS will capture
 *  to "WB990000.bin" until the size of the file exceeds dwFileSize.  The QS will then close the capture file,
 *  and open a second capture file "WB990001.bin".
 *
 *  If capture is already enabled, the QS will close the current capture session and open a new capture session into
 *  the file specified in sFileName.  If the file already exists, the QS destroys the existing file and create a new one.
 *  Uses the same files and criteria for dumps (file size, dump format) as QS_DEBUG_RING_CAPENABLE, and the data 
 *  appears in the same order as it was received by the HW.
 */
#define QS_DEBUG_CAPENABLE                  0x00000004

/** Disabled capture of QS submits to disk. This is specified to close a capture session.  If capture is not
 *  enabled, the QS does nothing.
 */
#define QS_DEBUG_CAPDISABLE                 0x00000008

/** Enables the QS to idle the hardware after every QSSubmit call.
 *  Causes the QS to wait for idle after every QSSubmit.
 */
#define QS_DEBUG_IDLEENABLE                 0x00000010

/** Disabled the QS hardware idle after QSSubmit calls. */
#define QS_DEBUG_IDLEDISABLE                0x00000020

/** Registers this client for QSEMU submits (see QS_EMU.doc for more details). */
#define QS_DEBUG_QSEMU_REGISTER_CLIENT      0x00000040

/** Reads the given register offset value from the active c-model emulator. */
#define QS_DEBUG_QSEMU_READ_REG_OFFSET      0x00000080

/** Writes the given register offset value from the active c-model emulator. */
#define QS_DEBUG_QSEMU_WRITE_REG_OFFSET     0x00000100

/** Used to communicate information between QS_EMU executable/dll and QS. */
#define QS_DEBUG_QSEMU_COMMUNICATION        0x00000200

/** Starts the timing (in CPU ticks) of all QSSubmits (accumulative time of all submits - just time from 
 *  actual submit to idle starting each submit as idle. 
 *  Causes the QS to wait for for idle before and after the submit, and accumulates the CPU ticks it takes
 *  for the submit to complete rendering.
 */
#define QS_DEBUG_TIMEDSUBMITS_BEGIN         0x00000400

/** Ends timed submits from QS_DEBUG_TIMEDSUBMITS_BEGIN. 
 *  Causes the QS to stop timing submits and returns the total ticks of all submits in the parameter lTimedSubmits.
 */
#define QS_DEBUG_TIMEDSUBMITS_END           0x00000800

#define QS_DEBUG_CAP_WAIT_FOR_IDLE          0x00001000

/** Enables capture of ring to disk. Uses the same files and criteria for dumps (file size, dump format) as
 *  QS_DEBUG_CAPENABLE. 
 */
#define QS_DEBUG_RING_CAPENABLE             0x00002000

/** Disabled capture of ring to disk. */
#define QS_DEBUG_RING_CAPDISABLE            0x00004000
#define QS_DEBUG_GETHWND                    0x00008000

/** Set the per-client context switching method.  
 *
 *  Context switching (saving a clients ASIC state after a submit
 *  and restoring before its next submit) is enabled to reduce or
 *  eliminate the need for a client to set all the desired ASIC state
 *  ('preamble') in every list, it can assume that state set by previous
 *  submits will be present on the next submit, even if some other client
 *  list was executed in the interim.  A (possible) context switch is
 *  triggered when QS client X calls QSSubmitList, and X was not the
 *  previous QSSubmitList caller.
 *
 *  At most one of the following two options can be chosen,
 *  and only once per client :
 *
 *  QS_DEBUG_CONTEXT_SWITCH_FULL - QS saves and restores clients ASIC state
 *  as needed in QSSubmitList, prior to executing the list.  Saving and
 *  restoring state is expensive on R[123]00 as it requires idling the ASIC
 *  (due to a Radeon bug).  It will be less expensive on RV350 (assuming the
 *  hw bug is fixed), but still not free.  Thus the next method.
 *
 *  QS_DEBUG_CONTEXT_SWITCH_LITE - this method is a hybrid of no context
 *  switching and full context switching.  The client wants the benefit
 *  of not having to include the preamble in every list, unless it would
 *  result in frequent context switching.  The basic idea is that
 *  while there is only one QS client, that client can omit the preamble.
 *  On returning from QSSubmitList, QS sets or clears QS_FLAG_SOLE_CLIENT
 *  in the dwFlags field of the passed in QS_PARAM to indicate to the
 *  client whether or not it needs to include the preamble in the next
 *  list submitted.  So in general while there is only one client, the
 *  client will omit preamble and there will be no context switching.  If
 *  a second client submits, the state of the first client will be saved,
 *  QS will clear QS_FLAG_SOLE_CLIENT on this and subsequent submits; on
 *  the next submit by the first client, that clients saved state will be
 *  restored (making up for the omitted preamble); subsequent submits
 *  by either client will include the preamble, there will be no more context
 *  switching.  If one of the clients unregisters, the remaining client
 *  will see QS_FLAG_SOLE_CLIENT set after its next and subsequent submits,
 *  and can resume omitting the preamble.
 *
 *  Note that QS_FLAG_SOLE_CLIENT does not imply that there is only one
 *  QS client in the system, it means rather that QS expects most submits
 *  in the near future to come from a single client, based on recent 
 *  client activity.
 */
#define QS_DEBUG_CONTEXT_SWITCH_FULL         0x00010000
#define QS_DEBUG_CONTEXT_SWITCH_LITE         0x00020000



/** Flag that indicates which ASIC (in multi-ASIC boards) to query.
 *  If not specified the query defaults to the primary.
 */
#define QS_SCRATCH_QUERY_PRIMARY        (0x80000000)
/** Obsolete */
#define QS_SCRATCH_QUERY_SECONDARY      (0x40000000)


/** Flags that indicate which scratch registers to read and
 *  which registers are being read back through DMA.
 */
#define QS_SCRATCH_LAST_READ_RETIRED    (0x00000001 | 0x00000002) // 0x00000003
#define QS_SCRATCH_LAST_READ_CONSUMED   (0x00000004 | 0x00000008) // 0x0000000C
#define QS_SCRATCH_BITBLT_THROTTLE      (0x00000010)
#define QS_SCRATCH_PIXEL_CACHE_PURGE    (0x00000020)
#define QS_SCRATCH_3D_REGISTER_0        (0x00000040)
#define QS_SCRATCH_3D_REGISTER_1        (0x00000080)
#define QS_SCRATCH_DCT_TIMESTAMP        (0x00000100)

/***********************************Functions********************************\
*  Legacy version (version 1) 
\****************************************************************************/

// The following are the prototypes for the functions passed back by 
// QSInit functions below.  Note, we still use the QS_FUNC declarations
// of QS_EP for compatibility...

/** \brief Allocates a command list (WinNT / Win9x)
 *  
 *  Allocates linearly contiguous memory of the size requested if successful.  A handle to the allocated list,
 *  a pointer to the list itself, a Memory controller address for the start of the list and the size of 
 *  the list in byes are returned in the hOutList, pList, dwListOffset and dwListSize parameters repectively
 *  on success.  
 *  See \ref QS_ALLOC2 for more detailed description.
 *
 *  \param pParam bit flags specifying how the list is to be submitted.  See definitions of QS_FLAG_ALLOC_*.
 *  \return QS_OK return upon success and an error condiiton otherwise.
 *  \sa QS_SUBMITLIST (QSSubmitList), QS_TS_CONSUMED (QSTimeStampConsumed), and QS_TS_RETIRED (QSTimeStampRetired).
 *                            
 */
typedef QS_RETURNCODE (__stdcall *QS_ALLOC)(QS_PARAM *pParam);


/** \brief Frees a command list without submitting it (WinNT / Win9x)
 *  
 *  Provides a way for the Client to free a list (i.e. a memory block) witout submitting it.
 *  
 *  \param pParam pointer to function parameter structure, cannot be NULL.
 *                See descriptions on QS_FLAG_FREE_*.
 *  \return QS_OK on success and an error otherwise.
 *  \sa QS_ALLOC (QSAllocList), QS_QUERYCAPS (QSQueryCaps), and QS_SUBMITLIST (QSSubmitList).          
 */
typedef QS_RETURNCODE (__stdcall *QS_FREELIST)(QS_PARAM *pParam);


/** \brief Exit and close the QS API (WinNT / Win9x)
 *
 *  Closes the QS API.  Must be called to ensure resources allocated during QSInit are freed.
 *
 *  \return QS_OK is always returned, as long as the hDevice is valid.
 *  \sa QSInit
 */
typedef QS_RETURNCODE (__stdcall *QS_EXIT)(void);


/** \brief Queries the capabilities of thetarget hardware device (WinNT/Win9x)
 *
 *  Provides the capabilities and some general info for a given device.
 *  QSQueryCaps (QS_QUERYCAPS) can be called at any time, after the API is initialized.
 *
 *  See \ref QS_QUERYCAPS2 for more info.
 *
 *  \param hDevice handle of the target hardware device.
 *  \param pCaps pointer to caps structure returned with device capabilities, cannot be NULL.
 *               See descriptions of structure QS_CAPS
 *  \return QS_OK if successful, and an error condition otherwise.
 *  \sa QSInit
 */
typedef QS_RETURNCODE (__stdcall *QS_QUERYCAPS)(QS_HDEVICE hDevice, QS_CAPS *pCaps);


/** \brief Registers the client on a target device with the QS (WinNT / Win9x)
 *  
 *  QS registers a new client within the server.
 *  All clients must call QSRegisterClient before QS operations can be executed.
 *  WinNT maps command lists into the user space of the client when the client is registered.
 *
 *  \param hDevice handle of the target hardware device.
 *  \param phClient pointer to a client handle created.
 *  \return QS_OK if successful, and an error condition otherwise.
 *          Error values include QS_TOOMANYCLIENTS if the queue server has exceeded the number
 *          clients it can manage.  Note, this should not happen in NT variants.
 *  \sa QS_UNREG_CLIENT (QSUnRegisterClient)
 */
typedef QS_RETURNCODE (__stdcall *QS_REG_CLIENT)(QS_HDEVICE hDevice, QS_HCLIENT *phClient);


/** \brief Registers a window handle tracked for the client in the QS (WinNT/Win9x)
 *  
 *  QS registers the window handle and tracks clipping objects against the window.
 *  List submitted to through QSSubmitList are applied against the clipping list for the
 *  window.  Using auxiliary hardware scissors to clip the list, the list is submitted
 *  against one or more clipping rectangles for the window.  The operation is considered atomic.
 *
 *  See \ref QS_REG_HWND2 for more info.
 *
 *  \param hDevice handle of the target hardware device.
 *  \param pWnd pointer to function parameter structure, cannot be NULL
 *              See description of QS_HWND.
 *  \sa QS_UNREG_HWND (QSUnregisterHWND), QS_QUERYCAPS (QSQueryCaps).
 */
typedef QS_RETURNCODE (__stdcall *QS_REG_HWND)(QS_HWND *pWnd);


/** \brief Submits a list of commands to the HW queue for execution.
 *
 *  QS posts the command list to the HW Queue of the device associated with the client.
 *  QS_FLAGS determine the state of the command list after submission.
 *
 *  See \ref QS_SUBMITLIST2 for more description.
 *
 *  \param pParam pointer to function parameter structure, cannot be NULL.
 *  \return QS_OK if successful, otherwise an error condition is returned.
 *          Possible error codes are:
 *          - QS_BADPARAMETER: on a bad parameter or size mismatch in the structure.
 *          - QS_ERRORUNKNOWN: when the device is unavailable.
 *  \sa 
 *      - QS_ALLOC (QSAllocList)
 *      - QS_TS_CONSUMED (QSTimeStampConsumed)
 *      - QS_TS_RETIRED (QSTimeStampRetired).
 *
 */
typedef QS_RETURNCODE (__stdcall *QS_SUBMITLIST)(QS_PARAM *pParam);


/** \brief Synchronized the CPU with the graphics accelerator (WinNT/Win9x)
 *
 *  QS posts a signal to the HW that synchronization with the CPU is requested.  AGP devices
 *  flushes write buffers to ensure system memory is updated.  QS returns when the ASIC is idle.
 *  Note that the client is responsible to ensure that no other processes queue commands to the
 *  graphics accelerator before their synchronizing event has completed.
 *
 *  \param hDevice handle of the target HW device.
 *  \sa QS_TS_CONSUMED (QSTimeStampConsumed), QS_TS_RETIRED (QSTimeStampRetired).
 */
typedef QS_RETURNCODE (__stdcall *QS_SYNCH)(QS_HDEVICE hDevice);


/** \brief Tests if a time stamp has elapsed / retired on the target hardware. (WinNT/Win9x)
 *         (Legacy function, use QSTimeStampRetired).
 *
 *  To determine if a command list has been retired, query QSTimeStampElapsed with the time
 *  stamp returned from QSSubmitList.
 *
 *  This is a legacy function provided for backward compatibility with clients written to 
 *  the QS version 1.10.7.  Clients are encouraged to use QSTimeStampRetired.
 *
 *  \param handle of the client.
 *  \param ts time stamp used to determine if event/command list has ben retired.
 *  \return QS_OK if the object (e.g. a list) associated witha  time stamp has elapsed,
 *                hence completed execution by the ASIC (all instructions in front of the 
 *                time stamp have been retired), and an error condition otherwise.
 *  \sa QS_ALLOC (QSAllocList), QS_TS_CONSUMED (QSTimeStampConsumed), 
 *      QS_TS_RETIRED (QSTimeStampRetired), QS_SUBMITLIST (QSSubmitList).
 */
typedef QS_RETURNCODE (__stdcall *QS_TS_ELAPSED)(QS_HCLIENT hClient, QS_TIMESTAMP ts);


/** \brief Unregisters the client with the QS. (WinNT/Win9x)
 *  
 *  QS unregisters the client and frees resources associated with the client.
 *  The functionality of server operations after unregistering the client is undefined.
 *  Clients are responsible to release allocated lists created by QSAllocList, but not yet
 *  submitted.
 *  
 *  See \ref QS_UNREG_CLIENT2 for more info.
 *
 *  \param hClient client handle to be unregistered.
 *  \return QS_OK if successful, and an error condition otherwise.
 *  \sa QS_REG_CLIENT (QSRegisterClient), QS_ALLOC (QSAllocList), 
 *      QS_SUBMITLIST (QSSubmitList).
 *
 */
typedef QS_RETURNCODE (__stdcall *QS_UNREG_CLIENT)(QS_HCLIENT hClient);


/** \brief Unregisters the window handle for client with the QS (WinNT/Win9x)
 *  
 *  QS unregisters the client's window handle and stops tracking the delta regions for the window.
 *  This function should ONLY be called if the current QS/QSLIB is capable of tracking windows
 *  and support front buffer clipping.  (QSQueryCaps set the bit QS_CAPS_HWNDTRACKING in
 *  pCaps->dwCpas).
 *
 *  \param hClient client handle for which the window handle is to be unregistered.
 *  \sa QS_REG_HWND (QSRegisterHWND), QS_QUERYCAPS (QSQueryCaps).
 */
typedef QS_RETURNCODE (__stdcall *QS_UNREG_HWND)(QS_HCLIENT hClient);


/** \brief Tests if a time stamp has been consumed on the target hardware.
 *  
 *  To determine if a command list has been consumed, query QS_TimestampConsumed with the 
 *  time stamp returned from QSSubmit list.
 *  
 *  See \ref QS_TS_CONSUMED2 for more detailed description.
 *
 *  \param hClient handle of the client.
 *  \param dwFlags bit flags specifying which devices to track list consumption on.
 *                 - QS_FLAG_WAIT:  causes the QS to wait until the time stamp has been consumed
 *                                  or timeout occurs whichever is first.
 *  \param ts time stamp used to determine if event / command list has been consumed.
 *  \return QS_OK if the object (e.g. a list) associated with a time stamp has been read 
 *                completely by the micro-code engine (e.g. all commands have entered the ASIC),
 *                and an error condition otherwise.
 *  \sa QS_ALLOC (QSAllocList), QS_TS_RETIRED (QSTimeStampRetired), QS_SUBMITLIST (QSSubmitList)
 */
typedef QS_RETURNCODE (__stdcall *QS_TS_CONSUMED)(QS_HCLIENT hClient, DWORD dwFlags, QS_TIMESTAMP ts);


/** \brief Tests if the object (e.g. a list) associated with a time stamp has been retired on
 *         the target hardware.
 *
 *  See \ref QS_TS_RETIRED2 for more info.
 *
 *  \param hDevice handle of the target hardware device.
 *  \param hClient handle of the client.
 *  \param dwFlags bit flags specifying which devices to track list consumption on.
 *                 - QS_FLAG_WAIT:  causes the QS to wait until the time stamp has been consumed
 *                                  or timeout occurs whichever is first.
 *  \param ts time stamp used to determine if event / command list has been consumed.
 *  \return QS_OK if the object (e.g. a list) associated with a time stamp has been retired 
 *                completely by the ASIC (e.g. all instructions in front of the time stamp have
 *                been completed execution), and an error condition otherwise.
 *  \sa QS_ALLOC (QSAllocList), QS_TS_RETIRED (QSTimeStampRetired), QS_SUBMITLIST (QSSubmitList)
 */
typedef QS_RETURNCODE (__stdcall *QS_TS_RETIRED)(QS_HCLIENT hClient, DWORD dwFlags, QS_TIMESTAMP ts);


/** \brief Function to assist in debugging of HW, SW and performance issues. (WinNT/Win9x)
 *
 *  Function is used to provide debugging capabilities for HW, SW and performance related issues.
 *  The description of the packet capture format is listed in the QS Appendix under \ref QSBinDump
 *  
 *  \param pDebug Pointer to the QS_DEBUG structure.  See descriptions of QS_DEBUG structure and
 *                debug state bit flags QS_DEBUG_*.
 *  \sa QS_REG_CLIENT (QSRegisterClient), QS_UNREG_CLIENT (QSUnregisterClient).
 */
typedef QS_RETURNCODE (__stdcall *QS_DBG)(QS_DEBUG *pDebug);

/** \brief QS function pointers (version 1).
 *
 *  Structure of QS function pointers for version 1 functions.
 */
typedef struct _QS_FUNC_
{
  DWORD                 dwSize;
  QS_EP                 QSAllocList;
  QS_EP                 QSFreeList;
  QS_EP                 QSExit;
  QS_EP                 QSQueryCaps;
  QS_EP                 QSRegisterClient;
  QS_EP                 QSRegisterHWND;
  QS_EP                 QSSubmitList;
  QS_EP                 QSSynchronize;
  QS_EP                 QSTimeStampElapsed;
  QS_EP                 QSUnregisterClient;
  QS_EP                 QSUnregisterHWND;
  QS_EP                 QSTimeStampConsumed;
  QS_EP                 QSTimeStampRetired;
  QS_EP                 QSDebug;
  DWORD                 padding[1]; // Add DWORDs to become 16-byte aligned
                                    // Note, we should update this to be more
                                    // IA64 friendly?
} QS_FUNC;

// The following exports provide the legacy QS functionality known as 
// version 1 (major version == 1).
/** \brief Initialize the QS API, obsolete (WinNT/ Win9x)
 *  
 *  QS qualifies the API version, and header files are synchronized using the QS_VERSION define.
 *  Provided versions are synchronized, the Queue Server's function pointers are returned via
 *  the QS)FUNC structure.
 *  Underlying implementation of QSInit on WinNT and Win9X may differ.
 *  QS.H provides prototypes of all the functions returned in pFunctions.
 * 
 *  \param pFunctions pointer to structure of QS functions.
 *  \param QS_VERSION defined version value.
 *  \return  
 *           - QS_OK if successful, an error code otherwise.
 *           - QS_VERSIONNOTSUPPORTED for incompatible QS versions
 *           - QS_DMANOTAVAILABLE if DMA is not supported in the current configuration and the
 *              queue server cannot emulate DMA.
 *  \sa QS_REG_CLIENT (QSRegisterClient).
 */
QS_RETURNCODE __stdcall QSInit(QS_FUNC *pFunctions, DWORD QS_VERSION);
QS_RETURNCODE __stdcall QSInit_nop(QS_FUNC *pFunctions, DWORD QS_VERSION);
QS_RETURNCODE __stdcall QSInitDVD(QS_FUNC *pFunctions, DWORD QS_VERSION);

/***********************************Functions********************************\
*  QS interface version 2
\****************************************************************************/

// The following are the prototypes for the functions passed back by 
// QSInit2 functions below....
/** \brief Allocates a command list (WinNT / Win9x)
 *  
 *  Allocates linearly contiguous memory of the size requested if successful.  A handle to the allocated list,
 *  a pointer to the list itself, a Memory controller address for the start of the list and the size of 
 *  the list in byes are returned in the hOutList, pList, dwListOffset and dwListSize parameters repectively
 *  on success.  
 *
 *  The configuration of the target HW device may affect the performance of the command list.  The QSQueryCaps 
 *  entry point helps to describe these properties. The dwListSize parameter's value on input must be aligned on 
 *  an 8byte (or 2 PM4 entries) boundary.  Note, the QS will round this value up if is not aligned correctly...
 *  
 *  If QS_CAPS_LISTLOCAL is returned from QSQueryCaps2, the QS supports the allocation of local or FB buffers.  
 *  In this case, clients can set the flag QS_FLAG_ALLOC_LOCAL to obtain an indirect buffer from th elocal heap. 
 *  Note, this local heap is shared with all other local buffer use (such as Direct Draw surfaces). All other 
 *  allocaiton requests come from the non-local reserve pool.
 *
 *  The NON-LOCAL lists come from a reserved pool (most liky in AGP memory).  That is, this memory is not available
 *  for general surface use, but reserved for allocation from this function alone.  Note, the total size of the 
 *  indirect buffer reserve is returned from QSQueryCaps2.
 *  Setting both QS_FLAG_ALLOC_LOCAL and QS_FLAG_ALLOC_NONLOCAL will have unpredictable results. Only after 
 *  attempting to allocate the size requested from the specified allocation pool will the QS process 
 *  QS_FLAG_ALLOC_SMALLER directive.
 *
 *  Clients should zero initialize the lTimeStamp field of the pParam.  If the call implements reporting of the 
 *  last read timestamp from the hardware, the return value for this field will be the last timestamp elapsed on the 
 *  currently selected target device.  This allows clients to read the timestamp without the additional call overhead
 *  to QSTimeStapRetired.
 *
 *  Clients SHOULD NOT hold multiple list for the QS allows for multiple clients of which the total required command
 *  buffer requirements exceed to total non-local reserve.
 *
 *  Under NT variants, "pParam->pList" is a virtual address mapped to the active process (during the call to
 *  QSRegisterClient2) if the client is a Ring3 client.  If the client is Ring0, the virtual address is in kernel space.
 *  Under Win9x, "pParam->pList" is simply a virtual address in shared memory space (>= 0x80000000).
 *
 *  \param hDevice handle of the target hardware device (Version 2 ONLY).
 *  \param pParam bit flags specifying how the list is to be submitted.  See definitions of QS_FLAG_ALLOC_*.
 *  \return QS_OK return upon success and an error condiiton otherwise.
 *  \sa QS_ALLOC2 (QSAllocList2), QS_TS_CONSUMED2 (QSTimeStampConsumed2), QS_TS_RETIRED2 (QSTimeStampRetired2).                          
 */
typedef QS_RETURNCODE (__stdcall *QS_ALLOC2)(QS_HDEVICE hDevice, QS_PARAM *pParam);


/** \brief Frees a command list without submitting it (WinNT / Win9x)
 *  
 *  Provides a way for the Client to free a list (i.e. a memory block) witout submitting it.
 *  
 *  \param hDevice handle of the target hardware device (Version 2 ONLY).
 *  \param pParam pointer to function parameter structure, cannot be NULL.
 *                See descriptions on QS_FLAG_FREE_*.
 *  \return QS_OK on success and an error otherwise.
 *  \sa QS_ALLOC2 (QSAllocList2), QS_QUERYCAPS2 (QSQueryCaps2), and QS_SUBMITLIST2 (QSSubmitList).         
 */
typedef QS_RETURNCODE (__stdcall *QS_FREELIST2)(QS_HDEVICE hDevice, QS_PARAM *pParam);


/** \brief Exit and close the QS API (WinNT / Win9x)
 *
 *  Closes the QS API. Must be called to ensure resources allocated during QSInit are freed.
 *
 *  \param hDevice handle of the target HW device (Version 2 ONLY).
 *  \return QS_OK is always returned, as long as the hDevice is valid.
 *  \sa QSInit2
 */
typedef QS_RETURNCODE (__stdcall *QS_EXIT2)(QS_HDEVICE hDevice);


/** \brief Queries the capabilities of thetarget hardware device (WinNT/Win9x)
 *
 *  Provides the capabilities and some general info for a given device.
 *  QSQueryCaps2 (QS_QUERYCAPS2)  can be called at any time, after the API is initialized.
 *
 *   - QSRegisterHWND (QS_REG_HWND2) and QSUnregisterHWND2 (QS_UNREG_HWND2) are truly
 *     functional ONLY if the capability QS_CAPS_HWNDTRACKING is returned.
 *   - Local list allocation is only possible if QS_CAPS_LISTSLOCAL is returned.
 *   - The capability bit QS_CAPS_QSEMU is set if the QS is capable of supporting QS_EMU.
 *   - QSCentralMemoryMgr2 (QS_CMM2) may be called ONLY IF QS_CAPS_CENTRAL_MEM_MGR
 *     is returned.  If QS_CMM2 is supported, it should be used to query any resource info
 *     (such as memory totals) instead of the values returned in this structure.
 *   - See desicriptions on QS_CAPS_*.
 *
 *  \param hDevice handle of the target hardware device.
 *  \param pCaps pointer to caps structure returned with device capabilities, cannot be NULL.
 *               See descriptions of structure QS_CAPS
 *  \return QS_OK if successful, and an error condition otherwise.
 *  \sa QSInit2
 */
typedef QS_RETURNCODE (__stdcall *QS_QUERYCAPS2)(QS_HDEVICE hDevice, QS_CAPS *pCaps);


/** \brief Registers the client on a target device with the QS (WinNT / Win9x)
 *  
 *  QS registers a new client within the server.
 *  All clients must call QSRegisterClient before QS operations can be executed.
 *  WinNT maps command lists into the user space of the client when the client is registered.
 *
 *  \param hDevice handle of the target hardware device.
 *  \param phClient pointer to a client handle created.
 *  \return QS_OK if successful, and an error condition otherwise.
 *          Error values include QS_TOOMANYCLIENTS if the queue server has exceeded the number
 *          clients it can manage.  Note, this should not happen in NT variants.
 *  \sa QS_UNREG_CLIENT2 (QSUnRegisterClient2)
 */
typedef QS_RETURNCODE (__stdcall *QS_REG_CLIENT2)(QS_HDEVICE hDevice, QS_HCLIENT *phClient);


/** \brief Registers a window handle tracked for the client in the QS (WinNT/Win9x)
 *  
 *  QS registers the window handle and tracks clipping objects against the window.
 *  List submitted to through QSSubmitList are applied against the clipping list for the
 *  window.  Using auxiliary hardware scissors to clip the list, the list is submitted
 *  against one or more clipping rectangles for the window.  The operation is considered atomic.
 * 
 *  All clients must call QSRegisterClient2 (QS_REG_CLIENT2) before the window handle for
 *  a client can be registered in the QS.  Clients should register a window only when rendering
 *  directly to the display surface to manage the interaction between various windows on the desktop.
 *  Clients using QSRegisterHWND2 (QS_REG_HWND2) should not program the auxiliary scissors in any
 *  submitted lists.
 *
 *  This function should ONLY be called if the current QS/QSLIB is capable of tracking windows and
 *  supporting front buffer clipping (QSQueryCaps set the bit QS_CAPS_HWNDTRACKING in pCaps->dwCaps).
 *
 *  \param hDevice handle of the target hardware device.
 *  \param pWnd pointer to function parameter structure, cannot be NULL
 *              See description of QS_HWND.
 *  \sa QS_UNREG_HWND2 (QSUnregisterHWND2), QS_QUERYCAPS2 (QSQueryCaps2).
 */
typedef QS_RETURNCODE (__stdcall *QS_REG_HWND2)(QS_HDEVICE hDevice, QS_HWND *pWnd);


/** \brief Submits a list of commands to the HW queue for execution.
 *
 *  QS posts the command list to the HW Queue of the device associated with the client.
 *  QS_FLAGS determine the state of the command list after submission.
 *  
 *  Command lists must be created via QSAllocList before they can be submitted.  Pointers to command
 *  lists are invalid after submission unless QS_FLAG_REUSE is set. 
 *
 *  If QS_FLAG_TIMESTAMP_RETIRED is set, lTimeStamp can be used to track when the commands in the submitted
 *  list are retired. If QS_FLAG_TIMESTAMP_CONSUMED is set, the lTimeStamp can be used to track when the
 *  commands in the submitted list are consumed.  If both flags are set, the lTimeStamp value can be used to 
 *  track both events.  If neither flag is set, QS will assume QS_FLAG_TIMESTAMP_RETIRED.  If the QS cannot
 *  track when a list is consumed, the QS will track on retired.
 *
 *  For R128 Win9x ONLY:
 *  - The parameters dwWindowXOffset and dwWindowYOffset are required for use of front buffer
 *    clipping of a client-registerd window with QSRegisterHWND.  These parameters represetn the (X,Y) offset
 *    from the Primary surface to the Memory controller(MC) address used for the rendering surface within
 *    the primary.  Note, if you use the MC address for the primary itself, this offset value should be (0,0).
 *  - Under multi-monitor solutions, the current R128 Win9x implementation requires that the monitor offset also 
 *    be added to the (dwWindowXOffset, dwWindowYOffset).  This is due to the method of which the cliplist
 *    information is obtained (through DDClipper object), and the cliplist happens to be in desktop instead of 
 *    device coordinates.
 *
 *  Clients can issue a buffer flip by setting the QS_FLAG_FLIP_HORIZONTAL flag for flips on a horizontal blank,
 *  and QS_FLAG_FLIP_VERTICAL for vertical blank.  If the client need the raster engine of the target device to stall
 *  until the buffer flip has completed, the QS_FLAG_FLIP_QUEUE_WAIT flag must be set.  Buffer flips are queued into
 *  the command stream before wait commands when both flags are specified.  Clients can issue buffer flips and wait
 *  commands through the QSSubmit2 call even if the hInList is null.
 *  
  *  QS_FLAG_CONTEXT is used to optimize the loading the state registers into the hardware, by using the QS to detect
 *  if reloading of the state changes is not required.  dwListOffset specified where from the beginning of the list
 *  in bytes the QS should start the list, if the context does not need to be reloaded.  dwListOffset must be 8 byte
 *  aligned (or two PM4 entries).  Clients must ensure the QS supports QS_CAPS_CONTEXT.
 *
 *  QS_FLAG_NO_SWITCHABLE_STATE indicates to the QS that the submitted list
 *  does not write to any registers that are context-switched; the list is
 *  a nop wrt to context switching.  This is an optimization for OpenGL
 *  in fullscreen exclusive mode.  In this case there are two QS clients,
 *  one does the rendering and the other submits only flip commands;
 *  the flip commands only write RB3D_DSTCACHE_CTLSTAT, WAIT_UNTIL
 *  and CRTC_OFFSET.  Thus there is no need to save and restore the state
 *  of the rendering client around the flip submit.
 *  This flag is only meaningful if context switching is supported
 *  (QS_CAPS2_CONTEXT_SWITCH).
 *
 *  \param hDevice handle of the target hardware device (Version 2 ONLY).
 *  \param pParam pointer to function parameter structure, cannot be NULL. If QS_FLAG_REUSE is set in dwFlags, 
 *                the server preserves the list for additional subsequent submissions, otherwise the handle to 
 *                the list is invalid after the call. If the calling client has successfully called QSRegisterHWND2 
 *                the submitted list will be clipped using (dwWindowXOffset, dwWindowYOffset) as the desktop or 
 *                "screen" offset to the current window drawing origin, since clipping list information is based on
 *                desktop or "screen" coordinates. See description of structure QS_PARAM.
 *  \return QS_OK if successful, otherwise an error condition is returned.
 *          Possible error codes are:
 *          - QS_BADPARAMETER: on a bad parameter or size mismatch in the structure.
 *          - QS_ERRORUNKNOWN: when the device is unavailable.
 *  \sa QS_ALLOC2 (QSAllocList2), QS_TS_CONSUMED2 (QSTimeStampConsumed2), QS_TS_RETIRED2 (QSTimeStampRetired2).
 */
typedef QS_RETURNCODE (__stdcall *QS_SUBMITLIST2)(QS_HDEVICE hDevice, QS_PARAM *pParam);


/** \brief Synchronized the CPU with the graphics accelerator (WinNT/Win9x)
 *
 *  QS posts a signal to the HW that synchronization with the CPU is requested.  AGP devices
 *  flushes write buffers to ensure system memory is updated.  QS returns when the ASIC is idle.
 *  Note that the client is responsible to ensure that no other processes queue commands to the
 *  graphics accelerator before their synchronizing event has completed.
 *
 *  \param hDevice handle of the target HW device.
 *  \sa QS_TS_CONSUMED2 (QSTimeStampConsumed2), QS_TS_RETIRED2 (QSTimeStampRetired2).
 */
typedef QS_RETURNCODE (__stdcall *QS_SYNCH2)(QS_HDEVICE hDevice);


/** \brief Tests if a time stamp has elapsed / retired on the target hardware. (WinNT/Win9x)
 *         (Legacy function, use QSTimeStampRetired).
 *
 *  To determine if a command list has been retired, query QSTimeStampElapsed with the time
 *  stamp returned from QSSubmitList.
 *
 *  This is a legacy function provided for backward compatibility with clients written to 
 *  the QS version 1.10.7.  Clients are encouraged to use QSTimeStampRetired.
 *
 *  \param hDevice handle of the target HW device.
 *  \param handle of the client.
 *  \param ts time stamp used to determine if event/command list has ben retired.
 *  \return QS_OK if the object (e.g. a list) associated witha  time stamp has elapsed,
 *                hence completed execution by the ASIC (all instructions in front of the 
 *                time stamp have been retired), and an error condition otherwise.
 *  \sa QS_ALLOC2 (QSAllocList2), QS_TS_CONSUMED2 (QSTimeStampConsumed2), 
 *      QS_TS_RETIRED2 (QSTimeStampRetired2), QS_SUBMITLIST2 (QSSubmitList2).
 */
typedef QS_RETURNCODE (__stdcall *QS_TS_ELAPSED2)(QS_HDEVICE hDevice, QS_HCLIENT hClient, QS_TIMESTAMP ts);


/** \brief Unregisters the client with the QS. (WinNT/Win9x)
 *  
 *  QS unregisters the client and frees resources associated with the client.
 *  The functionality of server operations after unregistering the client is undefined.
 *  Clients are responsible to release allocated lists created by QSAllocList2, but not yet
 *  submitted.
 *
 *  For Rage128 9x, the QS does not guarantee resource checking to ensure Client freed it's resources.
 *  All other versions will automatically release all resources still held by the QS client.
 *  Note, Ring 3 clients on current CMM/QS solutions under NT will automatically clean up QS
 *  clients registered against a proscess when a the process terminates (if any still around).
 *
 *  WinNT variants unmap command lists from the user space of the client when the client is
 *  unregistered.
 *
 *  TheQS is responsible to restore the correct CRTC offset for clients that issue buffer flips.
 *  When a client that has been issuing buffer flips on a horizontal blank has terminated,
 *  the QS is responsible to restore the state of target devices to buffer flip in the state 
 *  HW was in before the QS was loaded.  (i.e. If the HW was in a vertical blanking mode, and 
 *  the client was flippin gon a ahorizontal blank, the QS must restore flipping mode to that
 *  of a vertical blank).
 *
 *  \param hDevice handle of the target HW device.
 *  \param hClient client handle to be unregistered.
 *  \return QS_OK if successful, and an error condition otherwise.
 *  \sa QS_REG_CLIENT2 (QSRegisterClient2), QS_ALLOC2 (QSAllocList2), 
 *      QS_SUBMITLIST2 (QSSubmitList2).
 *
 */
typedef QS_RETURNCODE (__stdcall *QS_UNREG_CLIENT2)(QS_HDEVICE hDevice, QS_HCLIENT hClient);


/** \brief Unregisters the window handle for client with the QS (WinNT/Win9x)
 *  
 *  QS unregisters the client's window handle and stops tracking the delta regions for the window.
 *  This function should ONLY be called if the current QS/QSLIB is capable of tracking windows
 *  and support front buffer clipping.  (QSQueryCaps set the bit QS_CAPS_HWNDTRACKING in
 *  pCaps->dwCpas).
 *
 *  \param hDevice handle of the target HW device.
 *  \param hClient client handle for which the window handle is to be unregistered.
 *  \sa QS_REG_HWND2 (QSRegisterHWND2), QS_QUERYCAPS2 (QSQueryCaps2).
 */
typedef QS_RETURNCODE (__stdcall *QS_UNREG_HWND2)(QS_HDEVICE hDevice, QS_HCLIENT hClient);


/** \brief Tests if a time stamp has been consumed on the target hardware.
 *  
 *  To determine if a command list has been consumed, query QS_TimestampConsumed with the 
 *  time stamp returned from QSSubmit list.
 *  
 *  If the QS cannot track when a list is consumed, the QS will conservatiely track when a list
 *  is consumed by tracking when it's retired, making QSTimeStampConsumed synonymous with
 *  QSTimeStampRetired.
 *
 *  Clients specifying QS_FLAG_WAIT cause the QS to busy loop until the specified time stamp is
 *  consumed or timeout occurs whichever is first.  The QS may still return an error condition
 *  if an error occurs.  If the QS_CAPS_TIMEOUT_ENABLE capability bit is set then the client
 *  must be able to handle the QS_TIMED_OUT return code, the timeout is infinite otherwise.
 *
 *  Clients must ensure the QS reports support for this function by testing for 
 *  QS_CAPS_MULTITIMESTAMP capability in QSQueryCaps function.
 *
 *  \param hDevice handle of the target hardware device.
 *  \param hClient handle of the client.
 *  \param dwFlags bit flags specifying which devices to track list consumption on.
 *                 - QS_FLAG_WAIT:  causes the QS to wait until the time stamp has been consumed
 *                                  or timeout occurs whichever is first.
 *  \param ts time stamp used to determine if event / command list has been consumed.
 *  \return QS_OK if the object (e.g. a list) associated with a time stamp has been read 
 *                completely by the micro-code engine (e.g. all commands have entered the ASIC),
 *                and an error condition otherwise.
 *  \sa QS_ALLOC2 (QSAllocList2), QS_TS_RETIRED2 (QSTimeStampRetired2), QS_SUBMITLIST2 (QSSubmitList2)
 */
typedef QS_RETURNCODE (__stdcall *QS_TS_CONSUMED2)(QS_HDEVICE hDevice, QS_HCLIENT hClient, DWORD dwFlags, QS_TIMESTAMP ts);


/** \brief Tests if the object (e.g. a list) associated with a time stamp has been retired on
 *         the target hardware.
 *
 *  Clients specifying QS_FLAG_WAIT cause the QS to busy loop until the specified timestamp 
 *  is retired or timeout occurs whichever is first.  The QS may still return an error condition
 *  if an error occurs.  If the QS_CAPS_TIMEOUT_ENABLED capability bit is set then the client
 *  must be able to handle the QS_TIMED_OUT return code, the timeout is infinite otherwise.
 *  
 *  Clients must ensure the QS reports support for this function by testing for 
 *  QS_CAPS_MULTITIMESTAMP capability bit in QSQueryCaps function.
 *
 *  \param hDevice handle of the target hardware device.
 *  \param hClient handle of the client.
 *  \param dwFlags bit flags specifying which devices to track list consumption on.
 *                 - QS_FLAG_WAIT:  causes the QS to wait until the time stamp has been consumed
 *                                  or timeout occurs whichever is first.
 *  \param ts time stamp used to determine if event / command list has been consumed.
 *  \return QS_OK if the object (e.g. a list) associated with a time stamp has been retired 
 *                completely by the ASIC (e.g. all instructions in front of the time stamp have
 *                been completed execution), and an error condition otherwise.
 *  \sa QS_ALLOC2 (QSAllocList2), QS_TS_RETIRED2 (QSTimeStampRetired2), QS_SUBMITLIST2 (QSSubmitList2)
 */
typedef QS_RETURNCODE (__stdcall *QS_TS_RETIRED2)(QS_HDEVICE hDevice, QS_HCLIENT hClient, DWORD dwFlags, QS_TIMESTAMP ts);


/** \brief Function to assist in debugging of HW, SW and performance issues. (WinNT/Win9x)
 *
 *  Function is used to provide debugging capabilities for HW, SW and performance related issues.
 *  Clients can call the QSDebug function only if the QS_CAPS_DEBUG capability is set when querying the QS capabilities.
 *  The description of the packet capture format is listed in the QS Appendix under \ref QSBinDump
 *
 *  \param hDevice handle of the target hardware device (Version 2 ONLY).
 *  \param pDebug Pointer to the QS_DEBUG structure.  See descriptions of QS_DEBUG structure and
 *                debug state bit flags QS_DEBUG_*.
 *  \sa QS_REG_CLIENT2 (QSRegisterClient2), QS_UNREG_CLIENT2 (QSUnregisterClient2).
 *
 */
typedef QS_RETURNCODE (__stdcall *QS_DBG2)(QS_HDEVICE hDevice, QS_DEBUG *pDebug);

/** \brief QSCentrolMemoryMgr2 - Interface to central memory manager (WinNT / Win9x)
 *
 *  This is the interface function to central memory manager support.  It utilizes the information such as
 *  process space and resource cleanup for the QS registered client, and rides off the defined and tested
 *  interface for Ring3 and Ring0 client.
 *
 *  \param hDevice Handle of the target hardware device.
 *  \param dwCMMOpCode Op code of the desired functions (defined in CMM.H)
 *  \param dwInputSize Size in bytes of input structure
 *  \param pInput Pointer to input structure (defined in CMM.H)
 *  \param dwOutputSize Size in bytes of output structure
 *  \param pOutput Pointer to the output structure (defined in CMM.H)
 *  \sa See descriptions in cmm.h
 */
typedef QS_RETURNCODE (__stdcall *QS_CMM2)(QS_HDEVICE hDevice, DWORD dwCMMOpCode,
                                           DWORD dwInputSize, void *pInput,
                                           DWORD dwOutputSize, void *pOutput);

/** \brief Returns a Ring3 scratch register pointer to the caller (WinNT / Win9x)
 *
 *  This function provides clients with access to the ASIC scratch registers.
 *  Scratch registers that are being read by DMA always have the current value.
 *  The client will always get the current value if they dereference the appropriate
 *  pointer in the pRegisters structure.  Scratch registers that are not being read
 *  by DMA are read as a one-time operation.  In this case, the client must call 
 *  this function again each time they want the current value.
 *
 *  \param hDevice handle of the target HW device.
 *  \param pParam pointer to function parameter structure.  
 *                See descriptions on PQS_SCRATCH_REGISTER_PARAMETERS
 *  \sa
 */
typedef QS_RETURNCODE (__stdcall *QS_GET_SCRATCH_REGS)(QS_HDEVICE hDevice,
                                       PQS_SCRATCH_REGISTER_PARAMETERS pParam);

/** \brief Queries and sets miscellenious state (WinNT / Win9x)
 *
 *  This function lets clients query and set some special state parameters. These 
 *  parameters let the client to fine tune QS behavior to the client's needs. One 
 *  typical use of such parameters is tuning the QS performance dynamically.
 *
 *  \param hDevice handle of the target HW device.
 *  \param pParamIn pointer to function input parameter structure.
 *  \param pParamOut pointer to function output parameter structure.
 *                See descriptions on PQS_QUERY_AND_SET_STATE2.
 *  \sa
 */
typedef QS_RETURNCODE (__stdcall *QS_QUERY_AND_SET_STATE2)(QS_HDEVICE hDevice,
                                       PQS_STATE_IN   pParamIn,
                                       PQS_STATE_OUT  pParamOut);

typedef QS_RETURNCODE (__stdcall *QS_IDCT_CONTROL)(QS_HDEVICE hDevice,
                                                   DWORD dwIdctOpCode,
                                                   void *pParam);

/** \brief QS function pointers (version 2).
 *
 * Structure of QS function pointers for version 2 functions.
 */                                                   
typedef struct _QS_FUNC2_
{
  DWORD                   dwSize;
  DWORD                   dwFlags;
  QS_ALLOC2               QSAllocList2;
  QS_FREELIST2            QSFreeList2;
  QS_EXIT2                QSExit2;
  QS_QUERYCAPS2           QSQueryCaps2;
  QS_REG_CLIENT2          QSRegisterClient2;
  QS_REG_HWND2            QSRegisterHWND2;
  QS_SUBMITLIST2          QSSubmitList2;
  QS_SYNCH2               QSSynchronize2;
  QS_TS_ELAPSED2          QSTimeStampElapsed2;
  QS_UNREG_CLIENT2        QSUnregisterClient2;
  QS_UNREG_HWND2          QSUnregisterHWND2;
  QS_TS_CONSUMED2         QSTimeStampConsumed2;
  QS_TS_RETIRED2          QSTimeStampRetired2;
  QS_DBG2                 QSDebug2;
  QS_CMM2                 QSCentralMemoryMgr2;
  QS_GET_SCRATCH_REGS     QSGetScratchRegisters;
  QS_IDCT_CONTROL         QSIdctControl2;
  QS_QUERY_AND_SET_STATE2 QSQueryAndSetState2;
  void *                  pQSFunc2Pad[8]; // Add pointers for future expansion
} QS_FUNC2;


// The following exports provide the QS functionality known as 
// version 2 (currently, major version == 1, but will be changed to 2).
/** \brief Initialize the QS API (WinNT/ Win9x)
    
    QS qualifies the API version, and header files are synchronized using the QS_VERSION define.
    Provided versions are synchronized, the Queue Server's function pointers are returned via
    the QS)FUNC structure.
    Underlying implementation of QSInit on WinNT and Win9X may differ.
    QS.H provides prototypes of all the functions returned in pFunctions.

    \param hDevice handle of the target HW device.
    \param pFunctions pointer to structure of QS functions.
    \param QS_VERSION defined version value.
    \return  
             - QS_OK if successful, an error code otherwise.
             - QS_VERSIONNOTSUPPORTED for incompatible QS versions
             - QS_DMANOTAVAILABLE if DMA is not supported in the current configuration and the
               queue server cannot emulate DMA.
    \sa QS_REG_CLIENT (QSRegisterClient).

 */
QS_RETURNCODE __stdcall QSInit2(QS_HDEVICE hDevice, QS_FUNC2 *pFunctions, DWORD QS_VERSION);
QS_RETURNCODE __stdcall QSInit2_nop(QS_HDEVICE hDevice, QS_FUNC2 *pFunctions, DWORD QS_VERSION);
QS_RETURNCODE __stdcall QSInit2DVD(QS_HDEVICE hDevice, QS_FUNC2 *pFunctions, DWORD QS_VERSION);


#ifdef __cplusplus
}
#endif

#endif /*_QS_H*/

/** \page QSAppendix Appendix

\subsection QSVersion2 QS Version2

QS Version2 is essentially an interface change to allow the clients to "define" the device context (QS_HDEVICE or HDC)
for each entry point.  This is to facilitate true multi-monitor support as well as a single library deliverable for 
all asics (but not Windows OS versions - Win9x is different then WinNT variants).  

Version2 also has a flags field for the call to QSInit2… which currently accepts the following flags:
QS_INITFLAG_RING0_CLIENT - Signals virtual addresses need to be in kernel space.
QS_INITFLAG_RING3_CLIENT - Signals virtual addresses need to be in kernel space.

\subsection QSWindowsNT Windows NT (4.0, W2K, XP) 

<b> Ring 3 clients (OGL, etc…) </b>
<HR>
 - Client lib:      qsnt.lib
 - QS_HDEVICE:      HDC returned from call to CreateDC.  

\note Nt5x variants may wish to use MonitorFromWindow to acquire the correct HDC.

\note these Ring3 clients are responsible for creating a client for each different process context of the driver.   
Clients should not assume that the properties of a client in one process context are applicable to another process 
context.

\note special clients (like DVD) that reside in the display driver (under the graphics mutex) and that request 
process space virtual addresses must use the Ring0 clientlib (which is none) and QS_HDEVICE.  The virtual addresses 
will be mapped to the active process by use of the QSINit2 flag QS_INITFLAG_RING3_CLIENT.

\note qsnt.lib is required if the client wishes to utilize the front buffer clipping support of the QS.

  
<b> Ring 0 clients (Ddraw, D3D, etc…) </b>
<HR>
 - Client lib:		None!  Need to call QSInit or QSInit2 directly in the display driver (see Qswrap.c).
 - QS_HDEVICE:		Driver instance (or ppdev).  See Qswrap.c.

These clients do not have support for front buffer clipping.

\subsection QSW9x_NonR128 Windows (95 / 98) for non-Rage128 variants (Radeon, etc…)

<b> Ring 3 clients (OGL, etc…) </b>
<HR>
 - Client lib:     qs9x_r3.lib
 - QS_HDEVICE:      HDC returned from call to CreateDC.  

Since all 9x clients use virtual addresses in shared memory (instead of mapping to active process), these 
clients are simply defined by the fact they currently do NOT hold the Win16 mutex (need to acquire thread 
synchronization graphics device).

Front buffer clipping is available to these clients.

<b> Ring 0 clients (Ddraw, D3D, etc…) </b>
<HR>
 - Client lib:      qs9x_r0.lib
 - QS_HDEVICE:      HDC returned from call to CreateDC.  

Since all 9x clients use virtual addresses in shared memory (instead of mapping to active process), these 
clients are simply defined by the fact they currently DO hold the Win16 mutex (DO NOT need to acquire thread 
synchronization graphics device).

Front buffer clipping is available to these clients.

\subsection QSW9x_R128 Windows (95 / 98) for Rage128 variants

<b> Ring 3 clients (OGL, etc…) </b>
<HR>
 - Client lib:      qs9xpro.lib
 - QS_HDEVICE:      HDC returned from call to CreateDC.  

Since all 9x clients use virtual addresses in shared memory (instead of mapping to active process), these clients 
are simply defined by the fact they currently do NOT hold the Win16 mutex (need to acquire thread synchronization
graphics device).

\note Due to the complex nature of the method of which the win16 mutex is obtained, this clientlib is NOT thread safe.

Front buffer clipping is available to these clients.

<b> Ring 0 clients (Ddraw, D3D, etc…) </b>
<HR>
 - Client lib:		qs9xnop.lib
 - QS_HDEVICE:		HDC returned from call to CreateDC.  

Since all 9x clients use virtual addresses in shared memory (instead of mapping to active process), these 
clients are simply defined by the fact they currently DO hold the Win16 mutex (DO NOT need to acquire thread
synchronization graphics device).

Front buffer clipping is NOT available to these clients.


\subsection QSMultiMonitor Multi-Monitor Support

It is the QS clients responsibility to correctly define an HDC for the desired destination device.  
Below is some sample code (written for the Ring3 application QSTest.exe) that correctly defines the desired 
HDC for multi-monitor use based on the rendering window.  Note, the Rage128 Win9x solution must add the 
"pXAdjust" and "pYAdjust" values to the dwWindowXOffset and dwWindowYOffset during QSSubmitList to obtain 
the correct clipping results.

\code

HDC  GetMonitorDC(HWND hWnd, LONG *pXAdjust, LONG *pYAdjust)
{
    MONITORINFOEX   monitorInfo;
    HMONITOR        hMonitor;
    HDC             hDevice;
    OSVERSIONINFO   osInfo;
    BOOL            bSupportsMultiMon = FALSE;

    osInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    if (GetVersionEx(&osInfo))
    {
        if (osInfo.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
        {
            //Win98?
            If (osInfo.dwMinorVersion > 0) bSupportsMultiMon = TRUE;
        }
        else if (osInfo.dwPlatformId == VER_PLATFORM_WIN32_NT)
        {
            // NT5 or greater…
            if (osInfo.dwMajorVersion > 4) bSupportsMultiMon = TRUE;
        }
    }    
    if (bSupportsMultiMon)
    {
        hMonitor   = MonitorFromWindow(hWnd, MONITOR_DEFAULTTOPRIMARY);
        ZeroMemory(&monitorInfo, sizeof( MONITORINFOEX));
	    monitorInfo.cbSize = sizeof( MONITORINFOEX );
	    GetMonitorInfo(hMonitor, (MONITORINFO*)&monitorInfo);
	    hDevice = CreateDC(NULL, monitorInfo.szDevice, NULL, NULL);
        *pXAdjust = monitorInfo.rcMonitor.left;
        *pYAdjust = monitorInfo.rcMonitor.top;
    }
    else
    {
        hDevice = CreateDC("DISPLAY", NULL, NULL, NULL);
        *pXAdjust = 0;
        *pYAdjust = 0;
    }
    return hDevice;
}

//----------------------------------------------------
void ReleaseMonitorDC(HDC hDevice)
{
    if (hDevice != NULL)
    {
        DeleteDC(hDevice);
    }
}
 
\endcode


\subsection QSBinDump Binary Dump Format for PM4 Packets

A binary file is produced when QSDebug is called with QS_DEBUG_CAPENABLE set.  This binary file consists of a 
sequence of "Submit" packets.  A Submit packet consists of a DWORD count followed by a series of legal PM4 packets.  
Typically the PM4 packets are taken from indirect buffers but they can also be constructed by other means.  

There are two types of Submit packets:
- a Header Submit packet; and 
- an IB Submit packet.

As shown in the following table, the dumped file contains a Header Submit packet followed by a series of IB Submit 
packets.  All data are written in \e binary.

       
<b> <center>          Description    </center> </b>
    <center>    Header Submit Packet </center>
    <center>    1st IB Submit Packet </center>
    <center>    2nd IB Submit Packet </center>
    <center>            · · ·        </center>

One goal in defining this binary format is to make the playback of the dump as simple as possible when testing 
for functionality.  As much as possible, the format has been defined such that each Submit packet can be submitted 
"as is" to a Rage 6 graphics chip and be processed by the graphics chip properly.  

The one place where this is not the case is when playing back 3D packets that use  Local Vertex Buffers (LVBs).  
In order for the dumps to be played back correctly, the vertex data in the LVBs must also be dumped.  This is done 
by including a newly created 3D_DRAW_IMMD packet after every draw packet that uses LVBs.  The newly created 
3D_DRAW_IMMD packet contains the vertex data for the preceding draw packet that uses LVBs. 

An additional complication arises when capturing vertex data for newly created 3D_DRAW_IMMD packets.  
To access the Vertex Buffers containing the data, the capture program needs the linear addresses of the Vertex 
Buffers.  However, only physical addresses are available from the PM4 stream.  The most expedient solution for 
obtaining the linear address from a physical address was to have the 3D drivers provide the associated linear 
address in Type 3 NOP packets in the PM4 stream.  

The remainder of this section describes the format of the two different types of Submit packets: the Header Submit 
Packet and the IB Submit Packet.  Details on dumping vertex data and obtaining the linear addresses of Vertex Buffers 
are given at the end of the sub-section that describes the format of the IB Submit Packet.


\subsection HdrSubmitPkt HEADER SUBMIT PACKET


The Header Submit packet contains information for allowing memory addresses in the captured PM4 data to 
be relocated.  The following table shows the structure of a Header Submit Packet.


<TABLE>
<TR><TD><B>Contents      </B></TD><TD><B>Size  </B></TD><TD><B>Description </B></TD></TR>
<TR><TD>Header Count     </TD><TD>1 DWORD   </TD><TD>Number of DWORDs contained in this Submit packet. This should be 7.             </TD></TR>
<TR><TD>Type 3 NOP Packet</TD><TD>7 DWORDs  </TD><TD>A PM4 Type 3 NOP packet that contains two Type 0 packets. See below for details.</TD></TR>
</TABLE>

<B> Type 3 NOP Packet </B>

The Type 3 NOP packet contains two Type 0 packets in its IT_BODY.  The two Type 0 packets contain the contents 
of the registers that give the location of the frame buffer, AGP space, and PCI GART space in the Rage 6 internal 
address space.  The following table illustrates the format of this Type 3 NOP packet.

<TABLE>
<TR><TD><B>Contents     </B></TD><TD><B>Size</B></TD><TD><B>Description                              </B></TD></TR>
<TR><TD>PM4 HEADER	    </TD><TD>1 DWORD    </TD><TD>Header for Type 3 NOP. This should be 0xc0051000.      </TD></TR>
<TR><TD>PM4 HEADER	    </TD><TD>1 DWORD    </TD><TD>Header for Type 0 packet. This should be 0x00010052    </TD></TR>
<TR><TD>MC_FB_LOCATION  </TD><TD>1 DWORD    </TD><TD>Contents of MC_FB_LOCATION register.                   </TD></TR>
<TR><TD>MC_AGP_LOCATION </TD><TD>1 DWORD    </TD><TD>Contents of MC_AGP_LOCATION register.                  </TD></TR>
<TR><TD>PM4 HEADER	    </TD><TD>1 DWORD    </TD><TD>Header for Type 0 packet. This should be 0x00010077.   </TD></TR>
<TR><TD>AIC_LO_ADDR     </TD><TD>1 DWORD    </TD><TD>Contents of AIC_LO_ADDR register.                      </TD></TR>
<TR><TD>AIC_HI_ADDR     </TD><TD>1 DWORD    </TD><TD>Contents of AIC_HI_ADDR register.                      </TD></TR>
</TABLE>

\subsection IBSubmitPacket IB SUBMIT PACKET


An IB Submit packet typically contains the contents of an indirect buffer that is being submitted via the Queue Server.
If desired, it is also possible for the QS to create a sequence of PM4 packets internally to be dumped in such a Submit 
Packet.  The following table shows the structure of an IB Submit packet.

<TABLE>
<TR><TD><B> Contents   </B></TD><TD><B> Size  </B></TD><TD><B> Description </B></TD></TR>
<TR><TD>COUNT         </TD><TD>1 DWORD        </TD><TD>Number of DWORDs contained in rest of IB Submit packet: 
                                                       COUNT=Sum( #DWORDs in each PM4 packet). See below for details.</TD></TR>
<TR><TD>Type 2 Packet </TD><TD>1 DWORD        </TD><TD>See below for details.                                        </TD></TR>
<TR><TD>PM4 Packet    </TD><TD>variable length</TD><TD>Raw PM4 packet data.  See below for details.                  </TD></TR>
<TR><TD>PM4 Packet    </TD><TD>variable length</TD><TD>Raw PM4 packet data.  See below for details.                  </TD></TR>
<TR><TD>· · ·	      </TD><TD>· · ·          </TD><TD>· · ·                                                         </TD></TR>
<TR><TD>PM4 Packet    </TD><TD>variable length</TD><TD>Last PM4 Packet in this Submit packet.  See below for details.</TD></TR>
</TABLE>

\b COUNT

COUNT specifies the number of DWORDs contained in the rest of the Submit packet.   Typically, the value of 
COUNT would be N+1 where
 - N is the size, in DWORDs, of the indirect buffer being captured for this Submit packet; and
 - 1 DWORD is for the Type 2 Packet.
However, additional PM4 packets are sometimes inserted into the sequence, particularly when dumping vertex buffers, 
and the COUNT value must be adjusted to reflect this.  See below for details on how PM4 packets from indirect 
buffers are captured.

<B> Type 2 Packet </B>

For each indirect buffer that is captured, a Type 2 NOP packet is written after the COUNT and before the PM4 packets 
from the indirect buffer.  This Type 2 NOP packet is used to indicate the address space in which the indirect buffer 
being captured is located.  The address space is known by the Queue Server at the time the packets are captured.  

The encoding for each address space uses the byte address of the register that specifies the base for that space.  
The following table shows the Type 2 NOP packet that is to be generated for each address space:

<TABLE>
<TR><TD><B>Type 2 NOP Packet   </B></TD><TD><B>Address Space        </B></TD></TR>
<TR><TD>0x80000000	        </TD><TD>None (see note below)  </TD></TR>
<TR><TD>0x80000148	        </TD><TD>Frame Buffer           </TD></TR>
<TR><TD>0x8000014c	        </TD><TD>AGP space              </TD></TR>
<TR><TD>0x800001dc	        </TD><TD>PCI GART space         </TD></TR>
</TABLE>
The encoding 0x80000000 is to be used when the location of an indirect buffer is either unknown or does not matter.
 

<B> PM4 Packet </B>

All PM4 packets, except those that index into Local Vertex Buffers, are captured as follows:

 - Type 0: These packets are written to disk in their original form in binary.

 - Type 1: These packets are written to disk in their original form in binary.

 - Type 2: These packets are written to disk in their original form in binary.

 - Type 3: Packets that do not reference Local Vertex Buffers are written to disk in their original form in binary.


Packets that index into Local Vertex Buffers (LVBs) require additional processing.  For the purposes of this 
description, we call such packets "indexed primitives."  The IT_OPCODES of indexed primitives are 3D_DRAW_INDX, 
3D_DRAW_VBUF and 3D_RNDR_GEN_INDX_PRIM.  The following describes how these are to be processed.

 -# Set the RESERVED (low order byte) field of the indexed primitive's header to the original IT_OPCODE.
 -# Set the IT_OPCODE field in the header of the indexed primitive to NOP=0x10.
 -# Write the NOPped indexed primitive to disk in binary.
 -# Create a 3D_DRAW_IMMD packet that contains the equivalent vertex information as the original indexed primitive 
    packet.  The actual vertex information can be obtained from the LVBs.  Details on accessing the associated LVBs are 
    provided at the end of this section.  Note that while SE_VTX_FMT is the same, SE_VF_CNTL.PRIM_WALK must be changed 
    from 1 to 3.
 -# Write the newly created 3D_DRAW_IMMD to disk in binary.  Note that this newly created packet immediately follows 
    the original (now NOPped) indexed primitive packet.

The following table shows the captured format of Type 3 packets that use LVBs.

<B> ***START OF INDEXED PRIMITIVE*** </B>
<TABLE>
<TR><TD><B> Contents   </B></TD><TD><B> Size     </B></TD><TD><B> Description </B></TD></TR>
<TR><TD>PM4 HEADER	        </TD><TD>1 DWORD</TD><TD>Type 3 PM4 header of the indexed primitive.  The IT_OPCODE 
                                                     field should be set to NOP=0x10 and the RESERVED field 
                                                     should be set to the original IT_OPCODE.                   </TD></TR>
<TR><TD>SE_VTX_FMT	            </TD><TD>1 DWORD    </TD><TD>Unchanged.                                         </TD></TR>
<TR><TD>SE_VF_CNTL	            </TD><TD>1 DWORD    </TD><TD>Unchanged.                                         </TD></TR>
<TR><TD>[indx 2 | indx 1]	    </TD><TD>1 DWORD    </TD><TD>Unchanged.                                         </TD></TR>
<TR><TD>[indx 4 | indx 3]	    </TD><TD>1 DWORD    </TD><TD>Unchanged.                                         </TD></TR>
<TR><TD>· · ·	                </TD><TD>· · ·	    </TD><TD>· · ·                                              </TD></TR>
<TR><TD>· · ·	                </TD><TD>· · ·	    </TD><TD>· · ·                                              </TD></TR>
<TR><TD>[indx n | indx n - 1]	</TD><TD>1 DWORD    </TD><TD>Unchanged.                                         </TD></TR>
</TABLE>
<B> ***START OF NEWLY CREATED 3D_DRAW_IMMD*** </B>
<TABLE>
<TR><TD>PM4 HEADER              </TD><TD>1 DWORD    </TD><TD>Type 3 PM4 header of the new 3D_DRAW_IMMD packet. 
                                                             The COUNT field must reflect the contents of this 
                                                             packet.  See note below.                           </TD></TR>
<TR><TD>SE_VTX_FMT	            </TD><TD>1 DWORD    </TD><TD>SE_VTX_FMT should be the same as the one 
                                                             in the original indexed primitive.                 </TD></TR>
<TR><TD>SE_VF_CNTL	            </TD><TD>1 DWORD    </TD><TD>SE_VF_CNTL.PRIM_WALK should be changed from 1 to 3 
                                                             and the rest of the DWORD should remain the same 
                                                             as the original indexed primitive.                                  </TD></TR>
<TR><TD>FTLVERTEX_1	    </TD><TD>variable length    </TD><TD>Vertex information extracted from LVB[ [indx 1] ].  </TD></TR>
<TR><TD>FTLVERTEX_2	    </TD><TD>variable length    </TD><TD>Vertex information extracted from LVB[ [indx 2] ].  </TD></TR>
<TR><TD>FTLVERTEX_3	    </TD><TD>variable length    </TD><TD>Vertex information extracted from LVB[ [indx 3] ].  </TD></TR>
<TR><TD>FTLVERTEX_4	    </TD><TD>variable length    </TD><TD>Vertex information extracted from LVB[ [indx 4] ].  </TD></TR>
<TR><TD>· · ·	        </TD><TD>· · ·	            </TD><TD>· · ·                                               </TD></TR>
<TR><TD>FTLVERTEX_n-1	</TD><TD>variable length    </TD><TD>Vertex information extracted from LVB[ [indx n-1] ].</TD></TR>
<TR><TD>FTLVERTEX_n	    </TD><TD>variable length    </TD><TD>Vertex information extracted from LVB[ [indx n] ].  </TD></TR>
</TABLE>


PM4 Header for Newly Created 3D_DRAW_IMMD Packet
<HR>
This PM4 header is the same as a regular Type 3 PM4 header.  In particular, the COUNT field is one less the number 
of DWORDS in the IT_BODY of this packet.   One difference, however, is the RESERVED field.  It is possible that the 
number of DWORDs in the newly created packet will overflow the 14-bit COUNT field.  If this occurs, the least 
significant 14 bits of the count are to be stored in the COUNT field and the remaining most significant bits are to 
be stored in the RESERVED field. The following table shows how the header fields are defined for the newly created 
packet.

<TABLE>
<TR><TD><B>Bits </B></TD><TD><B>Field Name  </B></TD><TD><B>Description  </B></TD></TR>
<TR><TD>7:0	    </TD><TD>RESERVED	</TD><TD>Most significant 8 bits of N-1, where N is the number of DWORDs in the IT_BODY.    </TD></TR>
<TR><TD>15:8	</TD><TD>IT_OPCODE	</TD><TD>Operation to be carried out.  It should be 0x29 for 3D_DRAW_IMMD.                  </TD></TR>
<TR><TD>29:16	</TD><TD>COUNT	    </TD><TD>Least significant 14 bits of N-1, where N is the number of DWORDs in the IT_BODY.  </TD></TR>
<TR><TD>31:30	</TD><TD>TYPE	    </TD><TD>Packet identifier.  It should be 3.                                                </TD></TR>
</TABLE>

Note that when the count value overflows the COUNT field, playing back this packet  as is will cause the graphics 
chip to hang.

Accessing Local Vertex Buffers
<HR>
The physical address of Vertex Buffers can be extracted from 3D_LOAD_VBPTR packets that are in the PM4 stream 
that is being captured.  However, to access the Vertex Buffers, the capture program requires the linear address.  
Converting a physical address into its corresponding linear address is problematic because the QS does not keep 
track of this address mapping nor does it know the linear address of the Vertex Buffers.

Three possible solutions were considered:
 -# Vertex buffers are stored in either AGP space or in the frame buffer.  Since the linear addresses of the AGP 
    base and the frame buffer are available to the QS in global variables, converting a VB's physical address into its 
    linear address can be done by computing offsets.
 -# A VxD function that converts a physical address into its linear address can be used.
 -# The 3D drivers can provide the linear addresses in the PM4 stream by including a Type 3 NOP packet after every 
    3D_LOAD_VBPNTR packet.  The contents of the Type 3 NOP packet is to be:

<TABLE>
<TR><TD><B>Ordinal </B></TD><TD><B>Field Name     </B></TD><TD><B>Description     </B></TD></TR>
<TR><TD>1       </TD><TD>[PM4 Header]	</TD><TD>PM4 header for Type 3 NOP packet.</TD></TR>
<TR><TD>2       </TD><TD>VTX_AOS_ADDR0	</TD><TD>Virtual address of the first vertex buffer in the preceding 3D_LOAD_VBPNTR packet.</TD></TR>
<TR><TD>3       </TD><TD>VTX_AOS_ADDR1	</TD><TD>Virtual address of the second vertex buffer in the preceding 3D_LOAD_VBPNTR packet.</TD></TR>
</TABLE>

The first solution works if Vertex Buffers are located in the frame buffer.  It does not work if VBs are stored in 
AGP space because the linear address space of AGP is not contiguous.  Specifically, VBs are stored in the DirectDraw 
heap which is allocated separately from the Ring Buffer space.

The second solution requires re-mapping the entire address space and appeared to be difficult to implement.

The third solution had the highest chance of success at the time and was also the most expedient one to implement.

The decision was to use the third solution.  Because this solution changes the PM4 stream for the sole purpose of 
facilitating the capture of PM4 packets, the Type 3 NOP packets are generated by only the Debug versions of the 3D 
drivers.  The Production versions do not produce these extra packets to avoid adversely affecting performance.

In addition, the first solution is also used in the current implementation as a fall-back mechanism in case the linear 
addresses  are not available in the PM4 stream and Vertex Buffers are stored in the frame buffer (or by some miracle, 
AGP space is contiguous).  If the fall-back mechanism is used for Vertex Buffers stored in AGP space which is not 
contiguous, either dumping will terminate abnormally or the vertex data in the dump will be corrupt and playback will 
most likely terminate abnormally.

\subsection RegEnt Registry Entries
See the documentation on CMM.H for a complete explanation of the various registry keys used to control the operation
of the CMM-QS.

*/

//@}



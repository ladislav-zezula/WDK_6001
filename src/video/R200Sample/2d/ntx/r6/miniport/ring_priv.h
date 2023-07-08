

/*****************************************************************************\
* 
*  Module Name    qs_asic.h
*  Project        Rage WindowsNT
*  Device         Rage
*
*  Description    header file for Rage driver
*  
*
*  Copyright (C) 1997-2003 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
\*****************************************************************************/

#ifndef _RING_PRIV_H
#define _RING_PRIV_H

#define PM4_PACKET0_NOP     0x00000000          // Empty header of type-0 packtes
#define PM4_PACKET1_NOP     0x40000000          // Empty header of type-1 packtes
#define PM4_PACKET2_NOP     0x80000000          // Empty header of type-2 packtes (reserved)

#define PM4_PACKET3_NOP                 0xC0001000      // Do nothing.
#define PM4_COUNT_SHIFT     16
#define PM4_MICROCODE_SIZE_R6x          256
#define PM4_PACKET3_SET_SCISSORS        0xC0001E00      // Set up scissors.
#define PM4_PACKET3_WAIT_FOR_IDLE       0xC0002600      // Wait for the engine to be idle. 
#define PM4_PACKET3_INVALID_OPCODE      0xC000FF00      // Well-defined invalid packet


// Use this inside all spinloops
_inline void QS_PAUSE()
{
#ifdef _WIN64
	/* No Pause needed for IA64 or K8 */;
#else
    __asm _emit 0xf3; __asm _emit 0x90; // instead of _asm pause because of the 9x compiler.
#endif
}

#define EXTRA_RB_WAITUNTIL_SYNC_CMD_SIZE 2
#define EXTRA_RB_WAITUNTIL_SYNC //Adds extra WAIT_UNTIL commands into the Ring Buffer in an attempt to help find R200 hw hangs
#define EXTRA_RB_WAITUNTIL_SYNC_FLAGS WAIT_UNTIL__WAIT_DMA_GUI_IDLE_MASK | WAIT_UNTIL__WAIT_3D_IDLECLEAN_MASK | WAIT_UNTIL__WAIT_2D_IDLECLEAN_MASK;


// Used in the shared-asic-flags (part of the shared-asic-block)
#define ASIC_PM4_ENABLED                0x00000001 // PM4 is enabled
#define ASIC_MMR_ENABLED                0x00000002 // MMR's are enabled/visible
#define ASIC_IDLE                       0x00000004 // ASIC is idle
#define ASIC_NEEDS_FLUSH                0x00000040 // ASIC needs pcache flush
#define ASIC_SUBMIT_PENDING             0x00000100 // Someone has space alloc'd
                                                   // against ring not yet subm.
#define ASIC_FORCE_HOST_RING_FLUSH      0x00000200 // PM4 ring may be cached
                                                   // on host side and needs
                                                   // flush for asic access.

#define ASIC_LAST_OWNER_2D              0x00001000 // last PM4 ring-buffer owner is 2D
#define ASIC_LAST_OWNER_3D              0x00002000 // last PM4 ring-buffer owner is 3D

// Defines the state of the qs-disable-flags
#define QS_DISABLE_LISTSLOCAL                   0x00000001
#define QS_DISABLE_LISTSNONLOCAL                0x00000002
#define QS_DISABLE_DEBUG                        0x00000008
#define QS_DISABLE_MEMWRITE                     0x00000020
#define QS_DISABLE_FLIP                         0x00000100
#define QS_DISABLE_RPTRWRITEBACK                0x00000400
#define QS_DISABLE_TIMESTAMPWRITEBACK           0x00002000
#define QS_DISABLE_BITBLT_THROTTLE_WRITEBACK    0x00008000
#define QS_DISABLE_PIXEL_CACHE_PURGE_WRITEBACK  0x00010000
#define QS_DISABLE_3D_SCRATCH_0_WRITEBACK       0x00020000
#define QS_DISABLE_3D_SCRATCH_1_WRITEBACK       0x00040000
#define QS_DISABLE_RESERVED19                   0x02000000
#define QS_DISABLE_RESERVED1D                   0x20000000
#define QS_DISABLE_RESERVED1E                   0x40000000
#define QS_DISABLE_ENTIRELY                     0x80000000
#define QS_DISABLE_ALL                          0xFFFFFFFF
#define QS_DISABLE_SCRATCH_WRITEBACKS           (QS_DISABLE_TIMESTAMPWRITEBACK | \
                                                 QS_DISABLE_BITBLT_THROTTLE_WRITEBACK | \
                                                 QS_DISABLE_PIXEL_CACHE_PURGE_WRITEBACK | \
                                                 QS_DISABLE_3D_SCRATCH_0_WRITEBACK | \
                                                 QS_DISABLE_3D_SCRATCH_1_WRITEBACK | \
                                                 QS_DISABLE_MEMWRITE)

#define _WRITEPTR(pHw) ((pHw)->dWPTR)

/////////////////////////////////////////////////////////////////////////////////////////
//
// STUFF THAT ONLY THE QUEUE SERVER NEEDS ACCESS TO !  THE DISPLAY DRIVER MAY
// NOT, UNDER ANY CIRCUMSTANCES, USE ANYTHING THAT IS CONTAINED IN THIS FILE
//
/////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////
    // Constants
    /////////////////////////////////////////////////////////////////////
#ifndef ONE_K
#define ONE_K   1024
#endif

#ifndef ONE_MEG
#define ONE_MEG 1048576
#endif


//
// Internal QS ASIC flags
//
// PM4 RPTR writeback is enabled
#define QS_ASIC_PM4RPTRWRITEBACK        0x00000001

    // These flags make up the dQSFlags field in the qs-private-info structure...
#define QS_IFH_ENABLED               0x00000002 // Infinitely Fast Hardware

// dwFlag is one of the QS_DISABLE_SCRATCH_WRITEBACKS flags
#define QS_SCRATCH_WRITEBACK_DISABLED(pQSprivateInfo, dwFlag) \
                        ((pQSprivateInfo->dQSDisableFlags & dwFlag) == dwFlag)

#define QS_SCRATCH_WRITEBACK_ENABLED(pQSprivateInfo, dwFlag) \
                        ((pQSprivateInfo->dQSDisableFlags & dwFlag) == 0)

// The bits in these must correspond to the bits in the scratch umask
// register.
#define QS_SCRATCH_WB_TIMESTAMP                 0x0000000F
#define QS_SCRATCH_WB_BITBLT_COMMAND_THROTTLE   0x00000010
#define QS_SCRATCH_WB_PIXEL_CACHE_PURGE         0x00000020
#define QS_SCRATCH_WB_3D_0                      0x00000040
#define QS_SCRATCH_WB_3D_1                      0x00000080

// Lets align the PM4 resources to the MAX USWC buffer size
// avoid avoid flushing the on every submit. [RA]
#define HOST_MAX_USWC_BUFFER_IN_ENTRIES         (64 >> 2)
#define PM4_RING_ENTRY_ALIGNMENT                HOST_MAX_USWC_BUFFER_IN_ENTRIES

    /******************************Public*Definition***************************\
    * Ring Buffer Macro's
    *
    * PM4 ring buffer is a piece of linear continuous memory.  Drawing commands
    * are queued into the ring buffer.  Hardware reads from the ring buffer in
    * system memory to retrieve it's commands.  This algorighm is designed to 
    * decouple the CPU from the hardware, increasing concurrency;  It is further
    * designed to the slow reduce bus traffic generated by the CPU in the
    * conventional MMR / PIO driver model.
    * 
    * RPTR is used to index where the hardware has read up to in the ring buffer
    * WPTR indicates where the CPU has written commands up to.  Using these two
    * indicies, the driver can determine what space is available in the ring
    * buffer. RPTR and WPTR are an index count in DWORDS (not linear addresses).
    *
    * To quickly manage the ring buffer, the following restrictions are placed
    * upon the queing commands into the buffer
    *      
    *      1) No single submission can exceede the size of the buffer
    *      2) No single submission can wrap around the tail of the buffer
    *      3) Only one client can submit commands at any time
    *      4) WPTR and RPTR are equal only when the hardware has no commands
    *         to consume within the ring buffer
    *      5) 6 free spaces are always in the buffer at any time; these spaces
    *         are used to update scratch registers, and wrap the buffer to the
    *         start when insufficient space to allocate a submission before the
    *         end of the buffer
    *      6) No client can **ever** access the ring buffer without using the
    *         macros supplied here-in
    *      7) A single scratch counter of 64 bits, and the RPTR value, for a 
    *         total of 96 bits are used to time events / commands
    *
    * PM4 macro's rely on variables
    *     pDevice - pointer to the CMM_SUPER_HDEVICE structure.  Used *only*
    *               for ring buffer dump capabilities (i.e., we need a handle
    *               to the kernel driver).
    *     pHw - pointer to shared ASICBLOCK structure
    *     s   - space required in dwords
    *     a   - address of/to next free PM4 DWORD
    *
    \**************************************************************************/
    // PM4_ALLOC guarantees a consecutive linear space of s DWORDS in the PM4
    //           buffer.  The requested space may be more than the space 
    //           actually consumed, but the space consumed can never exceede the
    //           space requested.  After space is allocated, the driver need
    //           submit the data for it to be consumed.
    //
    //           Note: always reserve 6 spaces at all time in the ring buffer
    //                 allowing the driver to insert jump/nop instructions to
    //                 get to the start of the buffer, and upload the scratch
    //                 registers.
    //
    //                 64 entries (20h) are reserved for the PM4 ring buffer
    //                 overread bug for when the ring buffer wraps [GG]
    //
    // PM4_IDLE is used to idle the graphics engine by waiting for all pending
    //          drawing operations to complete.  It is recomended that the
    //          hardware be locked when idling to ensure no other processes get
    //          into the hardware queuing up more drawing operations.  PM4_IDLE
    //          sets the lFree count of PM4 ring buffer spaces to the size of
    //          the ring, to avoid polling the idle hardware on the next drawing
    //          operation.  Note that the function calls the debug version for
    //          both the release and debug versions of the driver -- it isn't
    //          exactly a performance critical routine...
    //
    //
    // PM4_QUEUE queues PM4 data into the ring buffer, without updating the
    //           hardware to pick up the data.  The state machine for
    //           managing the PM4 ring buffer within the driver considers the
    //           data inserted into the ring buffer as uploaded to the hardware
    //           but the hardware has not been told to fetch the data as the WPTR
    //           update has not occured. [GG]
    //
    // PM4_SUBMIT updates the PM4 pointers to reflect new data in the buffer.
    //
    // PM4_RELEASE is used to free space allocated in the ring buffer, by
    //             a PM4_ALLOC;  The ring pointers are not moved, and no hardware is
    //             updated.  This macro is usefull for routines which determine a 
    //             rendering failure after performing an ALLOC, and wish to fail or punt
    //             the work elsewhere.  Currently it does nothing.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define QS_PM4_ALLOC(pHw,s,a)           QS_PM4alloc (pHw,s,(PVOID *)&a)
#define QS_PM4_IDLE(pHwDeviceExtension, pHw) QS_PM4idle(pHwDeviceExtension, pHw)
#define QS_PM4_SUBMIT(pHw,a)    QS_PM4submit (pHw,(PVOID *)&a)


    /////////////////////////////////////////////////////////////////////
    // Structures
    /////////////////////////////////////////////////////////////////////

typedef 
//__declspec (align(64))
struct _ASICBLOCK
{
    /** Points to the start of the ring buffer block returned via the last
        call to the pm4-alloc routine.*/
    LPBYTE   pRing;

    /** pRingBase points to the first location in the ring buffer. This value never changes.*/
    LPBYTE   pRingBase;

    /** pMMR is the offset to the base of memory mapped registers, this pointer
       is declared as volatile so the compiler does not optimize reads from this
       pointer since MMR's can be modified externally to the driver.*/
    LPBYTE  volatile pMMR;

    /** Amount of ring space that has been allocated since the last pm4-queue
        or pm4-submit operation.*/
    DWORD    dwRingSpaceUsedDWORDs;

    /** dwSharedAsicFlags are bitwise binary flags specific to the ASIC state.*/
    DWORD    volatile dwSharedAsicFlags;

    /** lFree is a local copy of the amount of free ring buffer space. */
    LONG     lFree;

    /** dMaxPM4Alloc is the maximum size of a single PM4_ALLOC call.*/
    LONG     dMaxPM4Alloc;

    /** dAlignPM4SubmitMask specifies the alignment used for PM4 buffer
       submissions when alignment is enabled.*/
    DWORD    dAlignPM4SubmitMask;

    /** dWPTR is a copy of the last PM4 write pointer written to the HW.*/
    DWORD    dWPTR;

    /** dRingSize is the size of the ring buffer in entries.*/
    DWORD    dRingSize;


    // ****************************************************************
    // Attention! This structure must be padded up to 64-byte boundary 
    // (P4 processor cache line).
    // ****************************************************************
    __int64               liTotalRingCount;

} SHARED_ASICBLOCK, *PSHARED_ASICBLOCK;

/** this structure defines the DMA dummy block used for PM4 ISR support.*/
typedef struct _PM4_DMA_DUMMY_BLOCK_
{
    DWORD   dwDMA_GUI_SRC_ADDR;
    DWORD   dwDMA_GUI_DST_ADDR;
    DWORD   dwDMA_GUI_COMMAND;
    DWORD   dwAlignFiller;
    DWORD   dwSrcAddr;
    DWORD   dwDstAddr;
    DWORD   dwFiller[2];
} PM4_DMA_DUMMY_BLOCK;

typedef struct _CXSW_REG_BLOCK_ CXSW_REG_BLOCK;

typedef struct _QS_PRIVATE_INFO_ QS_PRIVATE_INFO;

//
// definitions for function pointers located at end of QS_PRIVATE_INFO structure.
// creating definitions for these functions makes the structure easier to visualize.
//
typedef void (*QS_INSERT_PM4_PACKET)(QS_PRIVATE_INFO *pQSprivateInfo, PDWORD *ppdwAddr);
typedef DWORD (*QS_CONSUMED_TIME_STAMP)(QS_PRIVATE_INFO *pQSprivateInfo, PDWORD *ppdwAddr);
typedef void (*QS_PM4INTERRUPTDISABLE)(QS_PRIVATE_INFO *QSprivateInfo);

    //! This structure lists and documents all such registers I/O-ed by CMMQS where 
    //! the registers are known at compile time (in other words, the offset used in 
    //! QS_IND and QS_OUTD macros is constant). Using this structure instead of 
    //! using the common pMMR pointer in shared asic block accomplishes 3 goals:
    //! 1.  It allows sharing common register code accross different ASICs where register 
    //!     offsets may be different in different ASICs.
    //! 2.  It improves performance (at least in theory) - any register access now is 
    //!     performed in a single CPU command on i386 platforms given a pointer to 
    //!     QS_PRIVATE_INFO has been loaded into a CPU register.
    //! 3.  Makes easier new ASIC bring up since if older register code tries to 
    //!     program registers on the new ASIC which no longer exist it would crash 
    //!     in software.
    //! Try to keep the same register order as the order in the asic header files for 
    //! consistency reasons but place the registers shared by the newest ASIC first.

#define QS_REG_POINTER_NAME(name)   pdw_mm##name
#define QS_DEFINE_REG(name)         volatile DWORD   * QS_REG_POINTER_NAME(name);


    // The following registers are shared among all ASICs
    // Sometimes their format and meaning are also identical.
#define QS_REG_MAP_COMMON \
    \
    /* BIF Block */\
    QS_DEFINE_REG(BUS_CNTL)\
    QS_DEFINE_REG(AIC_CTRL)\
    QS_DEFINE_REG(AIC_LO_ADDR)\
    QS_DEFINE_REG(AIC_HI_ADDR)\
    \
    /* RBBM Block */\
    QS_DEFINE_REG(WAIT_UNTIL)\
    QS_DEFINE_REG(RBBM_STATUS)\
    QS_DEFINE_REG(RBBM_SOFT_RESET)\
    \
    /* CP Block */\
    QS_DEFINE_REG(CP_RB_BASE)\
    QS_DEFINE_REG(CP_RB_CNTL)\
    QS_DEFINE_REG(CP_RB_RPTR_ADDR)\
    QS_DEFINE_REG(CP_RB_RPTR)\
    QS_DEFINE_REG(CP_RB_WPTR)\
    QS_DEFINE_REG(CP_RB_WPTR_DELAY)\
    \
    QS_DEFINE_REG(CP_CSQ_CNTL)\
    QS_DEFINE_REG(CP_ME_CNTL)\
    QS_DEFINE_REG(CP_STAT)\
    \
    QS_DEFINE_REG(GUI_SCRATCH_REG0)\
    QS_DEFINE_REG(GUI_SCRATCH_REG1)\
    QS_DEFINE_REG(GUI_SCRATCH_REG2)\
    QS_DEFINE_REG(GUI_SCRATCH_REG3)\
    QS_DEFINE_REG(GUI_SCRATCH_REG4)\
    QS_DEFINE_REG(GUI_SCRATCH_REG5)\
    QS_DEFINE_REG(GUI_SCRATCH_REG6)\
    QS_DEFINE_REG(GUI_SCRATCH_REG7)\
    QS_DEFINE_REG(SCRATCH_UMSK)\
    QS_DEFINE_REG(SCRATCH_ADDR)

#define QS_REG_MAP_RADEON \
    \
    /* CB Block */\
    QS_DEFINE_REG(RB2D_DSTCACHE_CTLSTAT)\
    \
    /* E2 Block */\
    QS_DEFINE_REG(DP_DST_ENDIAN)\
    QS_DEFINE_REG(SRC_X_Y)\
    QS_DEFINE_REG(DP_SRC_ENDIAN)\
    QS_DEFINE_REG(DSTCACHE_CTLSTAT)\
    QS_DEFINE_REG(DEFAULT_PITCH_OFFSET)\
    QS_DEFINE_REG(DEFAULT_SC_BOTTOM_RIGHT)\
    QS_DEFINE_REG(DEFAULT2_PITCH_OFFSET)\
    QS_DEFINE_REG(DEFAULT2_SC_BOTTOM_RIGHT)\
    \
    /* MC Block */\
    QS_DEFINE_REG(MC_AGP_LOCATION)\
    QS_DEFINE_REG(AGP_BASE)\
    QS_DEFINE_REG(MC_FB_LOCATION)\
    \
    /* RBBM Block */\
    QS_DEFINE_REG(ISYNC_CNTL)\
    QS_DEFINE_REG(GEN_INT_CNTL)\
    QS_DEFINE_REG(GEN_INT_STATUS)\
    \
    /* HDP Block */\
    QS_DEFINE_REG(HOST_PATH_CNTL)\
    QS_DEFINE_REG(SURFACE_CNTL)\
    \
    /* DISPLAY Block */\
    QS_DEFINE_REG(CRTC_GUI_TRIG_VLINE)\
    QS_DEFINE_REG(DISPLAY_BASE_ADDR)\
    QS_DEFINE_REG(CLOCK_CNTL_INDEX)\
    QS_DEFINE_REG(CLOCK_CNTL_DATA)\
    \
    /* CP Block */\
    QS_DEFINE_REG(CP_IB_BASE)\
    QS_DEFINE_REG(CP_ME_RAM_ADDR)\
    QS_DEFINE_REG(CP_ME_RAM_DATAH)\
    QS_DEFINE_REG(CP_ME_RAM_DATAL)\
    QS_DEFINE_REG(DMA_GUI_TABLE_ADDR)\
    QS_DEFINE_REG(DMA_GUI_STATUS)\
    QS_DEFINE_REG(CP_GUI_SRC_ADDR)\
    QS_DEFINE_REG(CP_GUI_DST_ADDR)\
    QS_DEFINE_REG(CP_GUI_COMMAND)\
    \
    /* Older than R300 */\
    QS_DEFINE_REG(RE_SCISSOR_TL_0)\
    QS_DEFINE_REG(RE_AUX_SCISSOR_CNTL)\
    QS_DEFINE_REG(RB3D_PD1_DATA)\
    QS_DEFINE_REG(SE_VF_CNTL)

#define QS_REG_MAP    QS_REG_MAP_COMMON  QS_REG_MAP_RADEON

    // This will automatically generate a structure with members of the following form:
    // volatile DWORD   *pdw_##registerOffsetName;
    // Note: we need a structure and not an array for performance reasons (this way 
    // all the offsets are know at compile time and are generated into the code).
typedef struct _QS_ASIC_REGS_ 
{
    QS_REG_MAP
} QS_ASIC_REGS, *PQS_ASIC_REGS;

#define QS_INVALID_POINTER    (DWORD_PTR(-1))

    //! This macro reconstructs the register offset as a difference between pointers. 
    //! Use it to abstract register offset between different ASICs whenever 
    //! performance is not a concern. Remember that this offset is in DWORDs rather 
    //! than bytes. This way we can reuse the same register table. Having a DWORD* cast 
    //! is probably more efficient than shifting the result. When performance is a concern, 
    //! use #define constants with ASIC-specific names.
    //! This macro will also result in an invalid Type-3 opcode if used for wrong ASIC.
#define QS_REG_OFFSET(pAsic, name)                                                                      \
    ((DWORD_PTR)(void*)(((QS_ASICBLOCK*)(pAsic))->regs. QS_REG_POINTER_NAME(name)) != QS_INVALID_POINTER ?  \
    ((DWORD)                                                                                            \
    ((DWORD*)(void*)(((QS_ASICBLOCK*)(pAsic))->regs. QS_REG_POINTER_NAME(name))                         \
    - (DWORD*)(void*)(((QS_ASICBLOCK*)(pAsic))->Hw.pMMR))) : PM4_PACKET3_INVALID_OPCODE)

    //! The same abstraction pattern is used for abstracting Type-0 PM4 packets...
typedef struct _QS_ASIC_PM4_HEADER_ 
{
    DWORD   dwLengthInDwords;
    DWORD   dwLengthInBytes;
    DWORD   dwIndex1;
    DWORD   dwIndex2;

} QS_ASIC_PM4_HEADER, *PQS_ASIC_PM4_HEADER;


#define QS_PM4_ENTRIES_FlushCacheAfterIdle_R6     6
#define QS_PM4_ENTRIES_FlushCacheAfterIdle_MAX    6
//
#define QS_PM4_ENTRIES_FlushCache2D3D_R6          2
#define QS_PM4_ENTRIES_FlushCache2D3D_MAX         4
//
#define QS_PM4_ENTRIES_RetiredTS_R6               5
#define QS_PM4_ENTRIES_RetiredTS_MAX              12

#define QS_PM4_STAMP_ENTRIES_CONSUMED_R6          3

#define QS_PM4_ENTRIES_RETIRED_CONSUMED  (QS_PM4_STAMP_ENTRIES_CONSUMED_R6)

#define _QS_PM4_PACKET(name)          dwBody_##name
#define QS_DEFINE_PM4_0(name)   QS_ASIC_PM4_HEADER  Header_##name##; DWORD _QS_PM4_PACKET(name) [QS_PM4_ENTRIES_##name##_MAX];

#define QS_PM4copy(pAsic, pRing, name)                                                              \
    ASSERT(((QS_ASICBLOCK*)(pAsic))->pm4.Header_##name##.dwLengthInDwords * sizeof(DWORD)  \
      == ((QS_ASICBLOCK*)(pAsic))->pm4.Header_##name##.dwLengthInBytes);       \
    memcpy((pRing), ((QS_ASICBLOCK*)(pAsic))->pm4._QS_PM4_PACKET(name),                             \
      ((QS_ASICBLOCK*)(pAsic))->pm4.Header_##name##.dwLengthInBytes);                               \
    (pRing) += ((QS_ASICBLOCK*)(pAsic))->pm4.Header_##name##.dwLengthInDwords;

// These macros are inlined better by compiler b/c it uses constant size. It may result in copying 
// a extra Type-0 NOPs though.
#define QS_PM4copy_short(pAsic, pRing, name)                                                        \
    ASSERT(((QS_ASICBLOCK*)(pAsic))->pm4.Header_##name##.dwLengthInDwords * sizeof(DWORD)  \
      == ((QS_ASICBLOCK*)(pAsic))->pm4.Header_##name##.dwLengthInBytes);       \
    memcpy((pRing), ((QS_ASICBLOCK*)(pAsic))->pm4._QS_PM4_PACKET(name),                             \
      sizeof(((QS_PRIVATE_INFO*)NULL)->QSasic.pm4. _QS_PM4_PACKET(name)));                          \
    (pRing) += (sizeof(((QS_PRIVATE_INFO*)NULL)->QSasic.pm4. _QS_PM4_PACKET(name)) / sizeof(DWORD));

// Should not be used normally. Unfortunately SHARED_ASICBLOCK uses BYTE* pointer for ring buffer.
#define QS_PM4copy_bytes(pAsic, pRing, name)                                                        \
    ASSERT(((QS_ASICBLOCK*)(pAsic))->pm4.Header_##name##.dwLengthInDwords * sizeof(DWORD)  \
      == ((QS_ASICBLOCK*)(pAsic))->pm4.Header_##name##.dwLengthInBytes);       \
    memcpy((pRing), ((QS_ASICBLOCK*)(pAsic))->pm4._QS_PM4_PACKET(name),                             \
      ((QS_ASICBLOCK*)(pAsic))->pm4.Header_##name##.dwLengthInBytes);                               \
    (pRing) += ((QS_ASICBLOCK*)(pAsic))->pm4.Header_##name##.dwLengthInBytes;
#define QS_PM4copy_short_bytes(pAsic, pRing, name)                                                  \
    ASSERT(((QS_ASICBLOCK*)(pAsic))->pm4.Header_##name##.dwLengthInDwords * sizeof(DWORD)  \
      == ((QS_ASICBLOCK*)(pAsic))->pm4.Header_##name##.dwLengthInBytes);       \
    memcpy((pRing), ((QS_ASICBLOCK*)(pAsic))->pm4._QS_PM4_PACKET(name),                             \
      sizeof(((QS_PRIVATE_INFO*)NULL)->QSasic.pm4. _QS_PM4_PACKET(name)));                          \
    (pRing) += (sizeof(((QS_PRIVATE_INFO*)NULL)->QSasic.pm4. _QS_PM4_PACKET(name)));


#define QS_PM4_MAP \
    \
    QS_DEFINE_PM4_0(FlushCacheAfterIdle)\
    QS_DEFINE_PM4_0(FlushCache2D3D)\
    QS_DEFINE_PM4_0(RetiredTS)

    // This will automatically generate a structure defining PM4 packets without 
    // any space waste (array with elements of max size could waste too much space). 
    // Structure is also better for performance..
typedef struct _QS_ASIC_PM4_PACKETS_ 
{
    QS_PM4_MAP
} QS_ASIC_PM4_PACKETS, *PQS_ASIC_PM4_PACKETS;


//
// The scratch register pointer structure. This MUST match the
// QS_SCRATCH_REGISTERS structure in qs.h EXCEPT this structure
// does not have const fields.
//
// This is the private version of QS_SCRATCH_REGISTERS.
//
// This is defined in a "public" header file for the benefit of the
// 9x display driver.  Anybody crazy enough to look at this structure
// directly deserves whatever data you get from it.  :-)
//
struct QS_SCRATCH_REGISTERS_INTERNAL_EXT
{
    // [GUI_]SCRATCH_REG0 and 1
    LARGE_INTEGER volatile   tsLastReadRetired;

    // [GUI_]SCRATCH_REG2 and 3
    LARGE_INTEGER volatile   tsLastReadConsumed;

    // [GUI_]SCRATCH_REG4
    DWORD volatile          dwBitBltCommandThrottle;

    // [GUI_]SCRATCH_REG5
    DWORD volatile          dwPixelCachePurge;

    // SCRATCH_REG6 and 7
    DWORD volatile          dw3dScratchRegister0;
    DWORD volatile          dw3dScratchRegister1;

    // dwRPTR is the the PM4 read pointer written out by the hardware into
    // the system.  Since the hardware can update this memory directly
    // the compiler cannot optimize this into a register as the CPU will
    // not pick up external updates from the hardware.  Frequently used
    // variables are stored in the first cache line for efficiency.
    // Since the RPTR writeback causes the L1 and L2 caches to be flushed of
    // any cache line containing the RPTR (PCI Snooping), the RPTR variable
    // is not stored with the frequently used variables. [GG]
    DWORD volatile                  dwRPTR;
    DWORD volatile                  dwHostBltRetiredCount;
};

/** This structure is used to communicate mode-set information from the
    display driver to the CMM library.*/
typedef struct
{
    BOOL   bBusMasteringEnabled;
    BOOL   bFeatureWSboard;
    BOOL   bBlockWriteDisabled;
    DWORD  dwFormat;
} QS_STATE_INFO, *PQS_STATE_INFO;

// Need to forward-declare QS_ASICBLOCK because of reference cycle
typedef struct _QS_ASICBLOCK_ QS_ASICBLOCK, *PQS_ASICBLOCK;
    // This structure contains the elements of the ASICBLOCK structure
    // that are needed only by the QS.
__declspec(align(64))
struct _QS_ASICBLOCK_ {

    // This field must be the first.
    // SHARED_ASICBLOCK is multiple of 64-bytes so that the first field 
    // following it is guaranteed to be cache-alligned on P4 as long as 
    // this structure itself is allocated with 64-byte allignment (it is). 
    // SHARED_ASICBLOCK being a first field of QS_ASICBLOCK instead of 
    // being a separate structure helps performance by avoiding unnecessary 
    // pointer references from the SHARED_ASICBLOCK pointer passed from 2D 
    // to QS private data such as QS_ASICBLOCK and QS_PRIVATE_INFO inside 
    // numerous QS functions.
    __declspec(align(64))
     SHARED_ASICBLOCK        Hw;

    __declspec(align(64))
    
    // 64bit counter of retired timestamp operation last loaded via PM4
    LARGE_INTEGER            liLastWrittenRetired;

    // 64bit counter of comnsumed timestamp operation last loaded via PM4
    LARGE_INTEGER            liLastWrittenConsumed;

    DWORD                   dwQSflags;

    // Used to pad the beginning of the ring for HW workarounds or 
    // required PM4 commands...[RA]
    DWORD                   dRingPad;

    DWORD                   dwPM4Alignment;

    // Fill out this cache line and assure that the private info pointer
    // ends up aligned correctly.
    DWORD                   padding 
      //[9]
      ;

    /************************** 32 BYTE CACHE LINE **************************/

    // Pointer the the ASIC scratch registers (which may be volatile)
    QS_SCRATCH_REGISTERS_INTERNAL_EXT  *pScratchRegisters;

#if DBG
    // pbRingLast indicates the last location of the ring buffer, or the start
    // of the pring up to the last PM4_SUBMIT
    PBYTE                   pbRingLast;
#endif /* DBG */

    DWORD  dwHostPathCntlValue;
    DWORD  dwHostPathRegOffset;   // In DWORDs b/c it is a register offset

    // For PM4 use of 3D clip regs (and binary compat).
    DWORD                   dMM_3DClipCntl;
    DWORD                   dMM_3DClipCntlEnableOne;
    DWORD                   dMM_3DClipCntlEnableAll;
    DWORD                   dMM_3DClipCntlEnableAllSubtractive;
    DWORD                   dMM_3DClipCntlDisable;
    DWORD                   dMM_3DClipTL;
    DWORD                   dMM_3DClipFlush;

    DWORD                   dMM_3DClipMask;
    DWORD                   dMM_3DClipShift;
    DWORD                   dMM_3DClipOffset;
    DWORD                   dMM_3DSetBRExclusive;
    DWORD                   dSC_ScissorRegCount;
    DWORD                   dSC_SubtractiveScissorRegCount;
    DWORD                   dMM_IntDMATable;
    DWORD                   dMM_IntDMATableDirect;
    DWORD                   dMM_IntSW;
    DWORD                   dMM_TSConsumed;

    // Pointers to ASIC registers used by CMMQS
    QS_ASIC_REGS            regs;

    // ASIC-specific precalculated PM4 packet data
    QS_ASIC_PM4_PACKETS     pm4;

};  // _QS_ASICBLOCK_

/** This structure contains information that used to reside in the PDEV
    but is only strictly required by the QS.  Note that this isn't really
    ASIC-dependent QS info, so it doesn't really belong in this header file
    but for now it's a convenient home. */
typedef struct _QS_PRIVATE_INFO_
{
    /** This structure must be the first field for alignment reasons.*/
    QS_ASICBLOCK            QSasic;

    // "Up-casts"
#define QS_HW_TO_PRIVATE(pHw)               ((QS_PRIVATE_INFO*)(void*)((pHw)))

    // "Down-casts"
#define QS_PRIVATE_TO_HW(pQSprivateInfo)    ((SHARED_ASICBLOCK*)(void*)((pQSprivateInfo)))

    /** Information read by the miniport from the registry*/
    struct _CMMQS_REGISTRY_INTERNAL *pRegistryInfo;

    /** Set to TRUE once the ring buffers and DMA information has been
        sent to the ASIC, FALSE otherwise.*/
    BOOL                    bPM4initialized;

    /** dQSDisableFlags are used to disable functions within the QS*/
    DWORD                   dQSDisableFlags;

    /** dQSDisable2Flags are used to disable functions within the QS*/
    DWORD                   dQSDisable2Flags;

    /** dQSFlags are used to control the state of the QS within the driver.*/
    DWORD                   dQSFlags;

    /** The settings of a bunch of DRV flags that don't change after the
        PDEV has been created.*/
    QS_STATE_INFO           qsDrvState;

    /** liCentralStamp is the single common timestamp used for tracking events*/
    LARGE_INTEGER            liCentralStamp;

    // Track information about the ASIC that we're running on here...
    DWORD                   dwAsicFamily;
    DWORD                   dwAsicID;
    DWORD                   dwAsicRev;

    // This for QS Timeout (1) and PM4 TS Interrupt (2) support (they are independent but related).
    // The first is used in Win2K and greater, the latter is used in XP and greater.
    //
    // PM4 TS Interrupt
    DWORD                       dwPM4_DummyBlock_MCAddress;

    // QS Private Function table
    QS_INSERT_PM4_PACKET            qs_PM4InsertInterruptPacket;
    QS_PM4INTERRUPTDISABLE          qs_PM4InterruptDisable;
    QS_CONSUMED_TIME_STAMP          qs_PM4ConsumedStamp;

    PVOID                           pHwDeviceExtension;
    PVOID                           pPrivateBuffers;

    PVOID                           pRingBasePhysical;

//	the struct must be 64 bytes alligned because of QS_ASICBLOCK
//	an allocated memory block may be not alligned and the struct pointer 
//  sometimes have to be moved inside the block to place pntr on 64 byte boudary
//	the block have to be freed on unload and the original must be saved

	PVOID							pMemToBeFreedOnUnload;

} QS_PRIVATE_INFO, *PQS_PRIVATE_INFO;


    /////////////////////////////////////////////////////////////////////
    // Prototypes
    /////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////
// Miscellaneous macros
/////////////////////////////////////////////////////////////////////

#define CMM_IS_RADEON200_VARIANT(family)               \
        (                                              \
            CMM_IS_RADEON200_LITE_VARIANT(family) ||   \
            (FAMILY_RADEON200 == family)               \
        )
   
#define CMM_IS_RADEON200_LITE_VARIANT(family)   \
        (                                       \
            (FAMILY_M9 == family)          ||   \
            (FAMILY_M9PLUS == family)      ||   \
            (FAMILY_RV250 == family)       ||   \
            (FAMILY_RV280 == family)       ||   \
            (FAMILY_RS300 == family)            \
        )

/////////////////////////////////////////////////////////////////////
// MMIO and I/O access macros (register access macros)
/////////////////////////////////////////////////////////////////////
#define QS_IND_dynamic(pAsic, dwReg)          qs_MMIO_Read  ((QS_ASICBLOCK*)(void*)(pAsic), (dwReg))
#define QS_OUTD_dynamic(pAsic, dwReg, dwData) qs_MMIO_Write ((QS_ASICBLOCK*)(void*)(pAsic), (dwReg), (dwData))
#define   QS_IND(pAsic, registerOffsetName)         (*((QS_ASICBLOCK*)(void*)(pAsic))->regs.pdw_##registerOffsetName)
#define  QS_OUTD(pAsic, registerOffsetName, dwReg)  (*((QS_ASICBLOCK*)(void*)(pAsic))->regs.pdw_##registerOffsetName) = (dwReg)

#define QS_IO_IND(pHwDeviceExtension, pHw, dwReg)           OS_ReadPort(pHwDeviceExtension, (dwReg << 2))
#define QS_IO_OUTD(pKernelAccess, pHw, dwReg, dwData)  OS_WritePort(pKernelAccess, pHw, (dwReg << 2), dwData)



#define QS_PM4_DMA_INTERRUPT_ENTRIES        2
//
#define QS_PM4_INTERRUPT_ENTRIES_MAX        4

#define QS_PM4_POST_SUBMIT      0

    /////////////////////////////////////////////////////////////////////
    // Radeon specific macros
    /////////////////////////////////////////////////////////////////////

    #define QS_PM4_WRAPOVERREADSPACE    0
    #define QS_PM4_RESERVEDSPACE        (2 + QS_PM4_WRAPOVERREADSPACE + QS_PM4_POST_SUBMIT)

    // Forces an update of the ASICs copy of the WPTR (i.e., essentially
    // is the trigger that causes the ASIC to start processing more ring
    // buffer data.
    #define QS_PM4_UPDATE_WPTR(pHw)     QS_OUTD ((pHw), mmCP_RB_WPTR, _WRITEPTR((pHw)))

    // Returns TRUE if the associated ASIC is still processing ring data
    #define QS_GUIBUSY(pHw)                   (QS_IND ((pHw), mmRBBM_STATUS) & RBBM_STATUS__GUI_ACTIVE)
    #define QS_IO_GUIBUSY(pHwDeviceExtension, pHw) (QS_IO_IND (pHwDeviceExtension, pHw, mmRBBM_STATUS) & RBBM_STATUS__GUI_ACTIVE)

    // MQUIETDOWN waits until the ASIC indicates that it has finished
    // executing all the packets in the command stream
    #define QS_QUIETDOWN(pHw)                     while (QS_GUIBUSY ((pHw))){QS_PAUSE();}
    #define QS_IO_QUIETDOWN(pHwDeviceExtension, pHw)   while (QS_IO_GUIBUSY (pHwDeviceExtension, pHw))

        // Forces an update of the local copy of the RPTR from the ASIC
    #define PM4_UPDATE_RPTR(pQSasic)    (pQSasic)->pScratchRegisters->dwRPTR = QS_IND ((pQSasic), mmCP_RB_RPTR)         

    #define PM4_DISABLE_DSTSCISSOR_ENTRIES    3
    #define PM4_DISABLE_DSTSCISSOR(pQSprivate,a)                                            \
            {                                                                                 \
                *((DWORD*)a+0) = (DWORD) (QS_PM4_PACKET3_SET_DSTSCISSORS | (1<<PM4_COUNT_SHIFT));\
                *((DWORD*)a+1) = FULL_SC_TOP_LEFT;                                            \
                *((DWORD*)a+2) = FULL_SC_BOTTOM_RIGHT;                                        \
				((DWORD*)a) += 3;                                                           \
            }

    #define PM4_DISABLE_AUX_SCISSORS_ENTRIES    2
    #define PM4_DISABLE_AUX_SCISSORS(pAsic,a)                                            \
            {                                                                                 \
                *((DWORD*)a+0) = (pAsic)->dMM_3DClipCntl | PM4_PACKET0_NOP;                \
                *((DWORD*)a+1) = (pAsic)->dMM_3DClipCntlDisable;                           \
				((DWORD*)a) += 2;                                                            \
            }

    #define PM4_PRE_IND_SUBMIT_ENTRIES          0
    #define PM4_PRE_IND_SUBMIT(p,a)             ;

    // r300 requires a backend register write after every submit,
    // in order to flush out any partial quads, allowing the 3d
    // subsystem to go idle.  So allocate ring space for this, 
    // but leave PM4_POST_IND_SUBMIT empty, we'll only do anything
    // post-submit on r300.
    //
    #define PM4_POST_IND_SUBMIT_ENTRIES         2

    #define PM4_POST_IND_SUBMIT(p,a)            ;

    #define PM4_IND_SUBMIT_ENTRIES              3 + PM4_PRE_IND_SUBMIT_ENTRIES + PM4_POST_IND_SUBMIT_ENTRIES
    #define _PM4_IND_SUBMIT(p,a,dwIndOffset,dwIndSize)                                        \
            {                                                                                 \
                PM4_PRE_IND_SUBMIT(p,a);                                                      \
                /* program out the parser and HBUI to fetch data from the indirect      */    \
                /* PM4 buffer, the hardware refers to the indirect buffer from a 0      */    \
                /* based offset from the start of AGP memory, or from the start of the  */    \
                /* scatter gather table.                                                */    \
                *((DWORD*)a+0) = (PM4_PACKET0_NOP | mmCP_IB_BASE) | (1 << PM4_COUNT_SHIFT);   \
                /* PM4_IW_INDOFF must be in terms of BYTES                              */    \
                *((DWORD*)a+1) = dwIndOffset;                                                 \
                *((DWORD*)a+2) = dwIndSize;                                                   \
				((DWORD*)a) += 3;                                                           \
                PM4_POST_IND_SUBMIT(p,a);                                                     \
            }


    #define QS_PM4_MAX_COUNT           0x3FFF


    // PM4 packet define for setting 2D destination scissors.
    #define QS_PM4_PACKET3_SET_DSTSCISSORS   PM4_PACKET3_SET_SCISSORS

    #define FULL_SC_TOP_LEFT                 0x00000000
    #define FULL_SC_BOTTOM_RIGHT             (((DEFAULT_SC_BOTTOM_RIGHT__DEFAULT_SC_RIGHT_MASK >> 1) \
                                             & DEFAULT_SC_BOTTOM_RIGHT__DEFAULT_SC_RIGHT_MASK)     \
                                             | ((DEFAULT_SC_BOTTOM_RIGHT__DEFAULT_SC_BOTTOM_MASK >> 1) \
                                             & DEFAULT_SC_BOTTOM_RIGHT__DEFAULT_SC_BOTTOM_MASK))

    #define PM4_IND_SUBMIT(pHw,a,dwIndOffset,dwIndSize)   _PM4_IND_SUBMIT (pHw, a, dwIndOffset, dwIndSize)

#endif // _RING_PRIV_H


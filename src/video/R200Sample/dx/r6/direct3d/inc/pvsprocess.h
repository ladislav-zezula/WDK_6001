

//    
//  Workfile: PvsOptRoutines.h
//
//
//  Trade secret of ATI Technologies, Inc.
//  Copyright 2000-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//
#ifndef _PVSPROCESS_H
#define _PVSPROCESS_H

#include "PvsMicrocode.h"

extern DWORD PvsProcess(LPVOID pDriverObj, 
                         DWORD *pdwOrigCode, DWORD dwCodeCount,
                         DWORD *pdwNewCode, DWORD *dwNewCodeCount, DWORD *dwNewLastPosInstr,
                         DWORD *pdwPositionCode, DWORD *dwPositionCodeCount,
                         DWORD dwControls);


// define the maximum number of pages the dependency graph can allocate
#define MAX_DEP_GRAPH_PAGES 256
#define MAX_INFO_PAGES 256

// This #define is used to mark an empty slot in the temp and a0
// tracking table. This marker cannot conflict (bitwize) with any
// valid instruction number
#define PVS_DELETED_MARKER      0x4000
#define PVS_INSTR_MASK          0x0fff

// Link list element containing
// information needed for the depedency graph
typedef struct PvsOpItemStruct {
    DWORD       instr_num;
    DWORD       we;
    DWORD       aux0;        // auxilliary information
    DWORD       aux1;        // auxilliary information
    struct PvsOpItemStruct *next;
} PvsOpItem;

// Link list element for lists of instruction numbers
typedef struct PvsInstrListStruct {
    DWORD       instr_num;
    struct PvsInstrListStruct *next;
} PvsInstrList;

typedef struct PvsDepGraphStruct {
    // information for page based memory allocation of dependency graph
    BYTE      *pPageBase[MAX_DEP_GRAPH_PAGES];  // array of pointers to allocated pages
    DWORD     dwPageCount;       // count of currently allocated pages
    BYTE      *pNextSpace;      // pointer to next location for allocation
    DWORD     dwBytesLeftInPage;
    // dependency graph information
    PvsOpItem *dep_list[PVS_MAX_CODE_LINES][3];     // list of instructions (and that instruction's write enables) on which each source is dependent
    DWORD     srcmask[PVS_MAX_CODE_LINES];          // bitwise mask of sources for this instruction (avoids repetitive determination)
    DWORD     pos_out[PVS_MAX_CODE_LINES];          // boolean indicates that this instruction is used to produce position output
    PvsOpItem *src_list[PVS_MAX_CODE_LINES];        // list of instructions that are dependent on this instruction (and on which write enable of this instruction)
    PvsOpItem *loc_grp_list[PVS_MAX_CODE_LINES];    // local writer group (other instructions that write to vectors read with this instruction's output)
    PvsOpItem *gbl_grp_list[PVS_MAX_CODE_LINES];    // global write group (remap list -- union of all threads loc_grp_list that involve this instruction) 
    PvsOpItem *top_list;
    DWORD     dep_chain_length[PVS_MAX_CODE_LINES]; // maximum number of instructions from this instruction to an output
} PvsDependencyGraph;

#define PVS_CTRL_NOT_USED                   0x0001
#define PVS_CTRL_MAD_MACRO                  0x0002        // use for debug only
#define PVS_CTRL_POST_SPLIT_MADS            0x0004        // use for debug only
#define PVS_CTRL_PRE_SPLIT_MADS             0x0008        // use for debug only
#define PVS_CTRL_STRONG_CHECK               0x0010
#define PVS_CTRL_CHECK                      0x0020
#define PVS_CTRL_FIX_EXPP_FRAC              0x0080        // convert EXPP to FRAC where applicable
#define PVS_CTRL_SKIP_PROCESS               0x0100        
#define PVS_CTRL_REDUCE_WRITE_ENABLES       0x0200        // reduce write enables (valid only with PVS_OPT_CTRL_SKIP_OPTIMIZER) or
                                                              // if the optimizer executes unsucessfully.
                                                              // write enables are always reduced if the optimizer executes sucessfully
#define PVS_SUCCESS                         0             
#define PVS_ERR_EMPTY_PROG                  1
#define PVS_ERR_EMPTY_NEXT_LIST             2
#define PVS_ERR_OPTIMIZER_CORNER            3
#define PVS_PROG_PROB_CRITERIA_SWITCH       4
#define PVS_ERR_OPTIMIZER_NO_TEMP           5
#define PVS_ERR_FAILED_CHECK                6
#define PVS_ERR_FAILED_MALLOC               7
#define PVS_ERR_FAILED_CHECK_3_TEMPS        8
#define PVS_ERR_FAILED_CHECK_MISSING_DEP    9

#endif // _PVSPROCESS_H

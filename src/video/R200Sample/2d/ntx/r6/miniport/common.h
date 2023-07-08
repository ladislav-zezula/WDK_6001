

/*****************************************************************************\
* 
*  Module Name    COMMON.H
*  Project        Longhorn
*  Device         R200
*
*  Description    Contains macros and defines used throughout the miniport.
*
*  Copyright (c) 2004 ATI Technologies Inc. (unpublished)
*
*  All rights reserved.
*  The year included in the foregoing notice is the year of creation of the work.
*
*  LOG OF CHANGES

\*****************************************************************************/

#ifndef _COMMON_H_
#define _COMMON_H_


#include <DriverSpecs.h>

__kernel_driver

//
// Define typedefs to be used throughout the miniport.
//
#ifdef BOOL
#undef BOOL
#endif

#ifdef DWORD
#undef DWORD
#endif

#ifdef PDWORD
#undef PDWORD
#endif

/*
typedef unsigned long BOOL;
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned long *PULONG;
*/

//
// Common header files.
//
#include <stdio.h>
#include <stdlib.h>
#include "dal.h"
#include "cwddedi.h"
#include "dderror.h"
#include "devioctl.h"
#ifndef _DAL_H
#include <ntddk.h>
#include <dispmprt.h>
#endif  // _DAL_H
#include "vidlog.h"
#include "ragent.h"
#include "global.h"

#define LCD_SETACTIVE                     0x0001
#define CRT_SETACTIVE                     0x0002 
#define TV_SETACTIVE                      0x0004
#define DFP_SETACTIVE                     0x0008

#define LCD_CONNECTED                     0x0100
#define CRT_CONNECTED                     0x0200 
#define TV_CONNECTED                      0x0400
#define DFP_CONNECTED                     0x0800


#define CAP_ID_AGP          0x2     
#define CSO_CAPS_PTR        0x34    


#define AGP_CAP_ID_REG                 0x00
#define AGP_STATUS_REG                 0x04
#define AGP_COMMAND_REG                0x08
#define AGP_REVISION_30                0x03
#define AGP_REVISION_20_10             0x02 

//
// Defines for various AGP register fields as DWORD fields
//

#define AGP_CAP_ID_REG__CAP_ID_MASK         0x000000FF
#define AGP_CAP_ID_REG__NEXT_PTR_MASK       0x0000FF00

#define AGP_STATUS_REG__MODE_AGP30          0x00000008

#define AGP_STATUS_REG__RATE_MASK           0x00000007
#define AGP_STATUS_REG__FW_EN               0x00000010
#define AGP_STATUS_REG__SBA_EN              0x00000200
#define AGP_STATUS_REG__RQ_MASK             0xFF000000


#define AGP_COMMAND_REG__RATE_MASK          0x00000007
#define AGP_COMMAND_REG__FW_MASK            0x00000010
#define AGP_COMMAND_REG__AGP_ENABLE         0x00000100
#define AGP_COMMAND_REG__SBA_EN             0x00000200

//
// Define baseclass and subclass for south & north bridge
//
#define SYSTEM_DEVICE_BASECLASS             0x0006
#define SYSTEM_DEVICE_NORTHBRIDGE           0x0000
#define SYSTEM_DEVICE_SOUTHBRIDGE           0x0001
#define SYSTEM_DEVICE_PCIPCIBRIDGE          0x0004

typedef struct tagCWDDEDI_CONTRCONFIG
{
    CWDDECMD CmdBuffer;
    CONTROLLERCONFIG ContrConfig[MAX_NUMBER_CONTROLLERS];
}CWDDEDI_CONTRCONFIG;

#endif  // _COMMON_H_


/*++
    Copyright (c) 2000,2001 Microsoft Corporation

    Module Name:
        pch.h

    Abstract:
        Pre-compile C header file.

    Environment:
        Kernel mode

--*/

#ifndef _PCH_H
#define _PCH_H

#define COMPONENT_NAME          "HBTN"
#define INTERNAL
#define EXTERNAL

#if DBG
#ifndef DEBUG
  #define DEBUG
#endif
#ifndef TRACING
  #define TRACING
#endif
#endif

#ifdef DEBUG
  #define SIMULATE_KBD
#endif

#include <wdm.h>
#include <hidport.h>
#include <strsafe.h>
#include "hbtnkey.h"
#include <hidbtn.h>
#include <errlog.h>

#define INC_HID_NAMES
  #include <wtrace.h>
#endif  //ifndef _PCH_H


/*++
    Copyright (c) Microsoft Corporation

    Module Name:
        pch.h

    Abstract:
        Pre-compile C header file.

    Environment:
        Kernel mode

--*/

#pragma once

#define COMPONENT_NAME          "HPEN"
#define INTERNAL
#define EXTERNAL

#if DBG
#ifndef DEBUG
  #define DEBUG
#endif
#endif


#include <wdm.h>
#include <ntddser.h>
#include <hidport.h>
#include <strsafe.h>
#include "wacompen.h"
#include <hidpen.h>
#include <serial.h>
#include <errlog.h>
  #include <wtrace.h>

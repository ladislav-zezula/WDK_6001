/*++

Copyright (c) 1998  Microsoft Corporation

Module Name:

    pch.h

Abstract

--*/

#include <wdm.h>
#include "wdf.h"

//TODO: Cannot include  <ntstrsafe.h> and <wdmsec.h> if DRIVETYPE=WDM

#pragma warning(disable:4214)  // bit field types other than int warning

#include <1394.h>

#pragma warning(default:4214)

#include "common.h"
#include "1394samp.h"
#include "debug.h"



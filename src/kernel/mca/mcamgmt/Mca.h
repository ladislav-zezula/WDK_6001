/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    Mca.h

Abstract:

    (See module header of Mca.cpp)
    
[Notes:]

    Header file for Mca.cpp
        
--*/

#ifndef MCA_H
#define MCA_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wbemcli.h>

#include "mce.h"
#include "MCAObjectSink.h"
#include "Common.h"
#include "CorrectedEngine.h"
#include "FatalEngine.h"
#include <dontuse.h>

#define TIME_OUT_MAX 60

//
// Function prototypes for Mca.cpp
//
BOOL
MCAParseArguments(
	IN INT ArgumentCount,
	__in_ecount(ArgumentCount) IN PWCHAR ArgumentList[]
	);

VOID
MCAPrintTitle(
    VOID
    );

VOID
MCAPrintUsage(
	VOID
	);

#endif


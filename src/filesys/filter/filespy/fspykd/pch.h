/*++

Copyright (c) 1992  Microsoft Corporation

Module Name:

    pch.h

Abstract:

    Header file which allows kernel and user mode header files
	to be included together for compilation of debugger extensions.


Environment:

    User Mode.

--*/
#include <windows.h>
#include <string.h>
#define KDEXT_64BIT
#include <wdbgexts.h>
#include <stdlib.h>
#include <stdio.h>
#include <fspydef.h>


/*++

Copyright (c) 1998  Microsoft Corporation

Module Name:

    pch.h
--*/

#include <wdm.h>

#include <1394.h>
#include "1394common.h"
#include "1394vdev.h"
#include "debug.h"


#ifdef _1394VDEV_C
#include "util.c"
#include "1394api.c"
#include "asyncapi.c"
#include "isochapi.c"
#endif


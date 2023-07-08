/*++

Copyright (c) 1998  Microsoft Corporation

Module Name: 

    pch.h
--*/

#include <windows.h>
#include <strsafe.h>
#include <setupapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <winioctl.h>
#include <ntdd1394.h>
#include <initguid.h>
#include "wdf_common.h"
#include "wdf_vdev_api.h"

#include "debug.h"
#include "util.h"
#include "async.h"
#include "isoch.h"
#include "1394.h"
#include "resource.h"
#include "local.h"
#define STRSAFE_NO_DEPRECATE
#include <strsafe.h>



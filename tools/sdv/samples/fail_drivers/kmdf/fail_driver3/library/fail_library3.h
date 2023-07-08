/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    fail_library3.h

Environment:

    Kernel mode

--*/


#include <NTDDK.h>  
#include <wdf.h>

VOID
SDVTest_wdf_FDOPowerPolicyOwnerAPI(
    PWDFDEVICE_INIT  DeviceInit
    );

VOID
SDVTest_wdf_RequestCompleted(
    WDFREQUEST  Request
    );

VOID
SDVTest_wdf_ReqNotCanceled(
    WDFREQUEST  Request
    );

VOID
SDVTest_wdf_NotPowerPolicyOwner();

VOID
SDVTest_wdf_MarkCancOnCancReq(
    WDFREQUEST  Request
    );

VOID
SDVTest_EvtRequestCancel(
    IN WDFREQUEST  Request
    );
/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

_WdfVersionBuild_

Module Name:

    wdftimer.h

Abstract:

    This is the C header for driver framework TIMER object

Revision History:


--*/

#ifndef _WDFTIMER_H_
#define _WDFTIMER_H_



#if (NTDDI_VERSION >= NTDDI_WIN2K)



//
// This is the function that gets called back into the driver
// when the TIMER fires.
//
typedef
VOID
(EVT_WDF_TIMER) (
    IN WDFTIMER  Timer
    );

typedef EVT_WDF_TIMER *PFN_WDF_TIMER;

typedef struct _WDF_TIMER_CONFIG {
    ULONG         Size;
    PFN_WDF_TIMER EvtTimerFunc;

    LONG          Period;

    //
    // If this is TRUE, the Timer will automatically serialize
    // with the event callback handlers of its Parent Object.
    //
    // Parent Object's callback constraints should be compatible
    // with the Timer DPC (DISPATCH_LEVEL), or the request will fail.
    //
    BOOLEAN       AutomaticSerialization;

} WDF_TIMER_CONFIG, *PWDF_TIMER_CONFIG;

VOID
FORCEINLINE
WDF_TIMER_CONFIG_INIT(
    IN PWDF_TIMER_CONFIG Config,
    IN PFN_WDF_TIMER     EvtTimerFunc
    )
{
    RtlZeroMemory(Config, sizeof(WDF_TIMER_CONFIG));
    Config->Size = sizeof(WDF_TIMER_CONFIG);
    Config->EvtTimerFunc = EvtTimerFunc;
    Config->Period = 0;

    Config->AutomaticSerialization = TRUE;
}

VOID
FORCEINLINE
WDF_TIMER_CONFIG_INIT_PERIODIC(
    IN PWDF_TIMER_CONFIG Config,
    IN PFN_WDF_TIMER     EvtTimerFunc,
    IN LONG             Period
    )
{
    RtlZeroMemory(Config, sizeof(WDF_TIMER_CONFIG));
    Config->Size = sizeof(WDF_TIMER_CONFIG);
    Config->EvtTimerFunc = EvtTimerFunc;
    Config->Period = Period;

    Config->AutomaticSerialization = TRUE;
}


//
// WDF Function: WdfTimerCreate
//
typedef
__checkReturn
__drv_maxIRQL(DISPATCH_LEVEL)
WDFAPI
NTSTATUS
(*PFN_WDFTIMERCREATE)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    PWDF_TIMER_CONFIG Config,
    __in
    PWDF_OBJECT_ATTRIBUTES Attributes,
    __out
    WDFTIMER* Timer
    );

__checkReturn
__drv_maxIRQL(DISPATCH_LEVEL)
NTSTATUS
FORCEINLINE
WdfTimerCreate(
    __in
    PWDF_TIMER_CONFIG Config,
    __in
    PWDF_OBJECT_ATTRIBUTES Attributes,
    __out
    WDFTIMER* Timer
    )
{
    return ((PFN_WDFTIMERCREATE) WdfFunctions[WdfTimerCreateTableIndex])(WdfDriverGlobals, Config, Attributes, Timer);
}

//
// WDF Function: WdfTimerStart
//
typedef
__drv_maxIRQL(DISPATCH_LEVEL)
WDFAPI
BOOLEAN
(*PFN_WDFTIMERSTART)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    WDFTIMER Timer,
    LONGLONG DueTime
    );

__drv_maxIRQL(DISPATCH_LEVEL)
BOOLEAN
FORCEINLINE
WdfTimerStart(
    __in
    WDFTIMER Timer,
    LONGLONG DueTime
    )
{
    return ((PFN_WDFTIMERSTART) WdfFunctions[WdfTimerStartTableIndex])(WdfDriverGlobals, Timer, DueTime);
}

//
// WDF Function: WdfTimerStop
//
typedef
__drv_when(Wait == __true, __drv_maxIRQL(PASSIVE_LEVEL))
__drv_when(Wait == __false, __drv_maxIRQL(DISPATCH_LEVEL))
WDFAPI
BOOLEAN
(*PFN_WDFTIMERSTOP)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    WDFTIMER Timer,
    BOOLEAN Wait
    );

__drv_when(Wait == __true, __drv_maxIRQL(PASSIVE_LEVEL))
__drv_when(Wait == __false, __drv_maxIRQL(DISPATCH_LEVEL))
BOOLEAN
FORCEINLINE
WdfTimerStop(
    __in
    WDFTIMER Timer,
    BOOLEAN Wait
    )
{
    return ((PFN_WDFTIMERSTOP) WdfFunctions[WdfTimerStopTableIndex])(WdfDriverGlobals, Timer, Wait);
}

//
// WDF Function: WdfTimerGetParentObject
//
typedef
WDFAPI
WDFOBJECT
(*PFN_WDFTIMERGETPARENTOBJECT)(
    __in
    PWDF_DRIVER_GLOBALS DriverGlobals,
    __in
    WDFTIMER Timer
    );

WDFOBJECT
FORCEINLINE
WdfTimerGetParentObject(
    __in
    WDFTIMER Timer
    )
{
    return ((PFN_WDFTIMERGETPARENTOBJECT) WdfFunctions[WdfTimerGetParentObjectTableIndex])(WdfDriverGlobals, Timer);
}



#endif // (NTDDI_VERSION >= NTDDI_WIN2K)


#endif // _WDFTIMER_H_


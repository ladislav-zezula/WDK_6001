/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

/* ..\wdm\harness-copyright.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

/*

Module Name:
    
    SDV harness


Abstract:
    
    Functions as representation of Windows OS for SDV.  It boots the 
    device driver and puts it into various states via its entry 
    DriverEntry routine and dispatch routines, etc.


Environment:

    Symbolic execution in Static Driver Verifier.

*/
/* ..\wdm\harness-copyright.c end */

/* ..\wdm\malloc.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

char * malloc(int);
/* ..\wdm\malloc.c end */

/* ..\wdm\harness-parts.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

#include <ntifs.h>

#include <ntdddisk.h>

#include "sdv-map.h"
#include "dispatch_routines.h"
#include "sdv_stubs.h"

VOID
sdv_SetMajorFunction(
    PIRP pirp,
    UCHAR fun
    );

VOID
sdv_SetPowerIrpMinorFunction(
    PIRP pirp
    );

VOID
sdv_SetStatus(
    PIRP pirp
    );


NTSTATUS
sdv_DoNothing(
    );


NTSTATUS         
sdv_RunDispatchFunction(
    PDEVICE_OBJECT po, 
    PIRP pirp
    );

NTSTATUS         
sdv_RunQueryDeviceRelations(
    PDEVICE_OBJECT po, 
    PIRP pirp
    );

PIRP             
sdv_MakeAbstractIrp(PIRP pirp
    );


PIRP             
sdv_MakeStartDeviceIrp(PIRP pirp
    );


PIRP             
sdv_MakeRemoveDeviceIrp(PIRP pirp
    );

LONG
SdvMakeChoice();

POWER_STATE
sdv_Make_POWER_STATE();

VOID
sdv_RunStartIo(
    PDEVICE_OBJECT po, 
    PIRP pirp
    );

VOID
sdv_RunDPC(
    struct _KDPC * kdpc, 
    PVOID pv1, 
    PVOID pv2, 
    PVOID pv3
    );

VOID
sdv_RunISR(
    struct _KINTERRUPT *ki, 
    PVOID pv1
    );

VOID
sdv_RunCancelRoutine(
    PDEVICE_OBJECT po, 
    PIRP pirp
    );


VOID
sdv_RunUnload(
    PDRIVER_OBJECT pdrivo
    );

NTSTATUS sdv_RunAddDevice(
    PDRIVER_OBJECT p1,
    PDEVICE_OBJECT p2
    );

VOID SdvExit();

VOID SdvAssume(int e);

VOID SdvAssumeSoft(int e);





int sdv_start_irp_already_issued = 0;
int sdv_remove_irp_already_issued = 0;




NTSTATUS
sdv_compFptr_dummy (
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    )
{
    return STATUS_SUCCESS;
}

PIO_COMPLETION_ROUTINE sdv_compFptr = sdv_compFptr_dummy;

int sdv_compFset = 0;



VOID
sdv_cancelFptr_dummy (
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    )
{
}


PDRIVER_CANCEL sdv_cancelFptr = sdv_cancelFptr_dummy;

int sdv_cancelFptr_set = 0;


BOOLEAN
sdv_isr_dummy (
    IN struct _KINTERRUPT * Interrupt,
    IN PVOID ServiceContext
    )
{
    return FALSE;
}

PKSERVICE_ROUTINE  sdv_isr_function = sdv_isr_dummy;


BOOLEAN sdv_isr_registered = FALSE;


VOID
sdv_dpc_dummy (
    IN struct _KDPC * Dpc,
    IN PVOID DeferredContext,
    IN PVOID SystemArgument1,
    IN PVOID SystemArgument2
    )
{
}

PKDEFERRED_ROUTINE  sdv_dpc = sdv_dpc_dummy;


IRP sdv_harnessIrp;
PIRP sdv_irp = &sdv_harnessIrp; 
IO_STACK_LOCATION sdv_harnessStackLocation;
IO_STACK_LOCATION sdv_harnessStackLocation_next;

IRP sdv_other_harnessIrp;
PIRP sdv_other_irp = &sdv_other_harnessIrp;
IO_STACK_LOCATION sdv_other_harnessStackLocation;
IO_STACK_LOCATION sdv_other_harnessStackLocation_next;

int sdv_harnessDeviceExtension_val;
int sdv_harnessDeviceExtension_two_val;

PVOID sdv_harnessDeviceExtension = (PVOID) &sdv_harnessDeviceExtension_val;
PVOID sdv_harnessDeviceExtension_two = (PVOID) &sdv_harnessDeviceExtension_two_val;



int sdv_io_create_device_called = 0;

int sdv_context_val ;
PVOID sdv_context = (PVOID) &sdv_context_val;
int sdv_start_info_val ;
ULONG_PTR sdv_start_info = (ULONG_PTR) &sdv_start_info_val;
int sdv_end_info_val ;
ULONG_PTR sdv_end_info = (ULONG_PTR) &sdv_end_info_val;


/* SDV_DIRQL:

   The OS model raises IRQL to DIRQL by the use of the SDV_DIRQL
   macro.  DIRQL is not a specific IRQL, but rather a range of
   possible Device IRQLs (On X86 from 3-26, on AMD64 from 3-11 and on
   IA64 from 4-11).  The OS Model nevertheless declares SDV_DIRQL as
   the concrete value 4 (which is a valid DIRQL representative for all
   architectures).  See ntddk_slic.h for details why this
   concretization is proper and will not result in loss of any traces.
*/

#define SDV_DIRQL 4


/* SDV OS Model IRQL Stack:

The OS Model contains a Bounded IRQL Stack.

The Bounded IRQL Stack should only be changed in OS Model DDIs and
only using 1) the operation SDV_IRQL_PUSH for pushing onto the stack
and 2) SDV_IRQL_POP and SDV_IRQL_POPTO for popping from the stack.

The stack is used in a number of rules that specify proper stack
behaviour for pairs of DDIs such as for example KeAcquireSpinLock and
KeReleaseSpinLock.

Pushing is used in the OS Model when a DDI sets/increases the IRQL to
a new and weakly higher IRQL.  An example of such a DDI is
KeAcquireSpinLock.

Popping is used in the OS Model when a DDI restores/lowers the IRQL to
a new and weakly lower IRQL.  An example of such a DDI is
KeReleaseSpinLock.

The stack is represented by the global variables sdv_irql_current,
sdv_irql_previous, sdv_irql_previous_2 and sdv_irql_previous_3.
sdv_irql_current is considered the top of the stack, sdv_irql_previous
is the second element of the stack and so on.

The stack is bounded.  Currently to height three.  This means that the
OS Model will not correctly capture the meaning of more than three
pushes to the stack.  Certain rules that check proper stack behaviour
takes this into account by counting current depth of the stack.

*/

/* Global IRQL stack, 4 levels high: */
KIRQL sdv_irql_current = PASSIVE_LEVEL;
KIRQL sdv_irql_previous = PASSIVE_LEVEL;
KIRQL sdv_irql_previous_2 = PASSIVE_LEVEL;
KIRQL sdv_irql_previous_3 = PASSIVE_LEVEL;

/* Operations on the global IRQL stack: */

/*
   SDV_IRQL_PUSH(new_irql):
     Change to new_irql IRQL, pushing old levels on the stack
*/

#define SDV_IRQL_PUSH(new_irql) \
    sdv_irql_previous_3 = sdv_irql_previous_2; \
    sdv_irql_previous_2 = sdv_irql_previous; \
    sdv_irql_previous = sdv_irql_current; \
    sdv_irql_current = new_irql

/*
   SDV_IRQL_POP():
     Change to previous IRQL, popping it from the stack
*/

#define SDV_IRQL_POP() \
    sdv_irql_current = sdv_irql_previous; \
    sdv_irql_previous = sdv_irql_previous_2; \
    sdv_irql_previous_2 = sdv_irql_previous_3

/*
   SDV_IRQL_POPTO(new_irql):
     Change to new_irql IRQL,
     popping (and ignoring) an IRQL from the stack
*/

#define SDV_IRQL_POPTO(new_irql) \
    sdv_irql_current = new_irql; \
    sdv_irql_previous = sdv_irql_previous_2; \
    sdv_irql_previous_2 = sdv_irql_previous_3



struct _KDPC sdv_kdpc_val;
struct _KDPC * sdv_kdpc = &sdv_kdpc_val;

int sdv_DpcContext;
PVOID sdv_pDpcContext = &sdv_DpcContext;


PVOID sdv_pv1;
PVOID sdv_pv2;
PVOID sdv_pv3;

DRIVER_OBJECT sdv_driver_object;


DEVICE_OBJECT sdv_devobj_two;
PDEVICE_OBJECT sdv_p_devobj_two = &sdv_devobj_two;



DEVICE_OBJECT sdv_devobj_one;
PDEVICE_OBJECT sdv_p_devobj_one = &sdv_devobj_one;

int sdv_kinterrupt_val;
struct _KINTERRUPT *sdv_kinterrupt = (struct _KINTERRUPT *) &sdv_kinterrupt_val;



#define SDV_MAIN_INIT()\
    sdv_devobj_one.DeviceExtension = &sdv_harnessDeviceExtension;\
    sdv_devobj_two.DeviceExtension = &sdv_harnessDeviceExtension_two;\
    sdv_irp->Tail.Overlay.CurrentStackLocation = &sdv_harnessStackLocation;\
    sdv_other_irp->Tail.Overlay.CurrentStackLocation = &sdv_other_harnessStackLocation


VOID 
sdv_SetPowerIrpMinorFunction(
    PIRP pirp
    )  
/*

Routine Description:

    Sets the MN IRP fields to the possible values.  

Arguments:

    pirp - The IRP to set.

Notes:
    Note how we're using non-determinism here with "x" and "y".  "x", for
    example, could take on any value.

*/
{
    PIO_STACK_LOCATION r = IoGetCurrentIrpStackLocation(pirp);
    LONG x = SdvMakeChoice();
    LONG y = SdvMakeChoice();

    switch (x) {
        case 0:
        r->MinorFunction = IRP_MN_SET_POWER;
        switch (y) {
            case 0:
            r->Parameters.Power.Type = SystemPowerState;
            break;

            case 1:
            default:
            r->Parameters.Power.Type = DevicePowerState;
            break;
        }
              break;

        case 1:
        r->MinorFunction = IRP_MN_QUERY_POWER;
        switch (y) {

            case 0:
            r->Parameters.Power.Type = SystemPowerState;
            break;

            case 1:
            default:
            r->Parameters.Power.Type = DevicePowerState;
            break;
        }
        break;


        case 2:
        r->MinorFunction = IRP_MN_POWER_SEQUENCE;
        break;      


        case 3:
        default:
        r->MinorFunction = IRP_MN_WAIT_WAKE;
        break;
        }
}




PIRP 
sdv_MakeRemoveDeviceIrp(PIRP pirp
    )
{
    PIO_STACK_LOCATION ps = IoGetCurrentIrpStackLocation(pirp);

    ps->MajorFunction = IRP_MJ_PNP;
    ps->MinorFunction = IRP_MN_REMOVE_DEVICE;
    pirp->CancelRoutine = NULL;
    
    sdv_SetStatus(pirp);

    return pirp;
}




PIRP 
sdv_MakeStartDeviceIrp(PIRP pirp
    )
{
    PIO_STACK_LOCATION ps = IoGetCurrentIrpStackLocation(pirp);

    ps->MajorFunction = IRP_MJ_PNP;
    ps->MinorFunction = IRP_MN_START_DEVICE;
    pirp->CancelRoutine = NULL;
    
    sdv_SetStatus(pirp);

    return pirp;
}



UCHAR 
sdv_ChooseMajorFunction(
    )
{
    UCHAR choice = (UCHAR) SdvMakeChoice();
    return choice;
}


PIRP 
sdv_MakeAbstractIrp(
    PIRP pirp
    )
/*

Routine Description:

    Intended to "reset" an irp with new non-deterministically choosen
    values.

Notes:
    This doesn't really reset the IRP yet.  We should set all fields to 
    new non-determinstic fields allowing us to find more bugs.

*/
{
    UCHAR fun = sdv_ChooseMajorFunction();

    sdv_SetMajorFunction( pirp, fun ); 

    if (fun==IRP_MJ_POWER) {
        sdv_SetPowerIrpMinorFunction(pirp);
    }

    sdv_SetStatus(pirp);

    pirp->CancelRoutine = NULL;


    return pirp;    
}


VOID
sdv_SetMajorFunction(
    PIRP pirp,
    UCHAR fun
    )
{

    PIO_STACK_LOCATION ps = IoGetCurrentIrpStackLocation(pirp);
    ps->MajorFunction = fun;   

}




VOID 
sdv_SetStatus(
    PIRP pirp
    )
{
    LONG choice = SdvMakeChoice();

    switch(choice) {
        case 0:
            pirp->IoStatus.Status = STATUS_NOT_SUPPORTED;
            break;
        case 1:
        default:
            pirp->IoStatus.Status = STATUS_SUCCESS;
            break;
    }
}


        

NTSTATUS 
sdv_DoNothing(
    )
{
    return STATUS_UNSUCCESSFUL;
}





LONG 
SdvMakeChoice(
    )
/*

Routine Description:

    Non-deterministically chooses a value and returns it:
    to full cl we return 0, but then assignment x = SdvMakeChoice
    is eliminated - so that x remains uninitialized

Arguments:

Notes:
    Note how we're using non-determinism here:  "x" can be any value.

    If you wanted to take this harness and actually execute it, you need
    to implement the non-determinism.  Changing this function would be a
    start, but you would also need to change the places where IRPs and other
    types are non-deterministically choosen.

*/
{
    return 0;
}

POWER_STATE
sdv_Make_POWER_STATE(
    )
{
  POWER_STATE x;
  int y = SdvMakeChoice();
  switch(y) {
    case 1 : x.SystemState = SdvMakeChoice(); break;
    default: x.DeviceState = SdvMakeChoice(); break;
  }
  return x;
}


NTSTATUS 
sdv_RunDispatchFunction(
    PDEVICE_OBJECT po, 
    PIRP pirp
    )
/*

Routine Description:

    Finds the appropriate dispatch function, and then applies it to the
    IRP argument.

Arguments:

    po - pointer to the device object.    
    pirp - pointer to the irp that we're using.

Return value:

    we're passing the dispatch's return value back.

Notes:
    
    We're interacting with SDV meta-data here.  If "fun_IRP_MJ_CREATE" is
    defined in the meta-data, then we're calling it.  Otherwise: we call
    the sdv_DoNothing() function.

*/
{
    NTSTATUS status;
    int x = SdvMakeChoice();
    UCHAR minor_function = (UCHAR) SdvMakeChoice();

    PIO_STACK_LOCATION ps = IoGetCurrentIrpStackLocation(pirp);


    sdv_end_info = sdv_start_info = pirp->IoStatus.Information;
 
    sdv_SetStatus(pirp);

    pirp->CancelRoutine = NULL;


    ps->MinorFunction = minor_function;

    sdv_stub_dispatch_begin();

    switch (x) { 

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_CLEANUP
        case IRP_MJ_CLEANUP:
        ps->MajorFunction = IRP_MJ_CLEANUP;
#ifdef fun_IRP_MJ_CLEANUP
        status = fun_IRP_MJ_CLEANUP(po,pirp);
#else
        status = sdv_DoNothing();
#endif
        break;
#endif

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_CLOSE
        case IRP_MJ_CLOSE:
        ps->MajorFunction = IRP_MJ_CLOSE;
#ifdef fun_IRP_MJ_CLOSE
        status = fun_IRP_MJ_CLOSE(po,pirp);
#else
        status = sdv_DoNothing();
#endif
        break;
#endif

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_CREATE
        case IRP_MJ_CREATE:
        ps->MajorFunction = IRP_MJ_CREATE;
#ifdef fun_IRP_MJ_CREATE
        status = fun_IRP_MJ_CREATE(po,pirp);
#else
        status = sdv_DoNothing();
#endif
        break;
#endif

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_DEVICE_CONTROL
        case IRP_MJ_DEVICE_CONTROL:
        ps->MajorFunction = IRP_MJ_DEVICE_CONTROL;
#ifdef fun_IRP_MJ_DEVICE_CONTROL
        status = fun_IRP_MJ_DEVICE_CONTROL(po,pirp);
#else
        status = sdv_DoNothing();
#endif
        break;
#endif

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_FILE_SYSTEM_CONTROL
        case IRP_MJ_FILE_SYSTEM_CONTROL:
#ifdef fun_IRP_MJ_FILE_SYSTEM_CONTROL
        status = fun_IRP_MJ_FILE_SYSTEM_CONTROL(po,pirp);
#else
        status = sdv_DoNothing();
#endif
        break;
#endif

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_FLUSH_BUFFERS
        case IRP_MJ_FLUSH_BUFFERS:
        ps->MajorFunction = IRP_MJ_FLUSH_BUFFERS;
#ifdef fun_IRP_MJ_FLUSH_BUFFERS
        status = fun_IRP_MJ_FLUSH_BUFFERS(po,pirp);
#else
        status = sdv_DoNothing();
#endif
        break;
#endif

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_INTERNAL_DEVICE_CONTROL
        case IRP_MJ_INTERNAL_DEVICE_CONTROL:
        ps->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;
#ifdef fun_IRP_MJ_INTERNAL_DEVICE_CONTROL
        status = fun_IRP_MJ_INTERNAL_DEVICE_CONTROL(po,pirp);
#else
        status = sdv_DoNothing();
#endif
        break;
#endif


#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_LOCK_CONTROL
        case IRP_MJ_LOCK_CONTROL:
#ifdef fun_IRP_MJ_LOCK_CONTROL
        status = fun_IRP_MJ_LOCK_CONTROL(po,pirp);
#else
        status = sdv_DoNothing();
#endif
        break;
#endif

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_QUERY_INFORMATION
        case IRP_MJ_QUERY_INFORMATION:
        ps->MajorFunction = IRP_MJ_QUERY_INFORMATION;
#ifdef fun_IRP_MJ_QUERY_INFORMATION
        status = fun_IRP_MJ_QUERY_INFORMATION(po,pirp);
#else
        status = sdv_DoNothing();
#endif
        break;
#endif

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_READ
        case IRP_MJ_READ:
        ps->MajorFunction = IRP_MJ_READ;
#ifdef fun_IRP_MJ_READ
        status = fun_IRP_MJ_READ(po,pirp);
#else
        status = sdv_DoNothing();
#endif
        break;
#endif

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_SET_INFORMATION
        case IRP_MJ_SET_INFORMATION:
        ps->MajorFunction = IRP_MJ_SET_INFORMATION;
#ifdef fun_IRP_MJ_SET_INFORMATION
        status = fun_IRP_MJ_SET_INFORMATION(po,pirp);
#else
        status = sdv_DoNothing();
#endif
        break;
#endif

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_SYSTEM_CONTROL
        case IRP_MJ_SYSTEM_CONTROL:
        ps->MajorFunction = IRP_MJ_SYSTEM_CONTROL;
#ifdef fun_IRP_MJ_SYSTEM_CONTROL
        status = fun_IRP_MJ_SYSTEM_CONTROL(po,pirp);
#else
        status = sdv_DoNothing();
#endif
        break;
#endif

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_WRITE
        case IRP_MJ_WRITE:
        ps->MajorFunction = IRP_MJ_WRITE;
#ifdef fun_IRP_MJ_WRITE
        status = fun_IRP_MJ_WRITE(po,pirp);
#else
        status = sdv_DoNothing();
#endif
        break;
#endif

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_PNP
        case IRP_MJ_PNP:
        ps->MajorFunction = IRP_MJ_PNP;


 
        if (ps->MinorFunction == IRP_MN_START_DEVICE) {
            SdvAssume(!sdv_start_irp_already_issued);
        }

	if (ps->MinorFunction == IRP_MN_CANCEL_REMOVE_DEVICE) {
	    SdvAssume(!sdv_remove_irp_already_issued);
	}

        if (ps->MinorFunction == IRP_MN_REMOVE_DEVICE) {
            sdv_remove_irp_already_issued = 1;
#ifdef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_PNP_MN_REMOVE_DEVICE
            SdvExit();
#endif
        }

#ifdef fun_IRP_MJ_PNP
        status = fun_IRP_MJ_PNP(po,pirp);
#else
        status = sdv_DoNothing();
#endif
        break;
#endif

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_IRP_MJ_POWER
        case IRP_MJ_POWER:
        ps->MajorFunction = IRP_MJ_POWER;
#ifdef fun_IRP_MJ_POWER
        sdv_SetPowerIrpMinorFunction(pirp);
        status = fun_IRP_MJ_POWER(po,pirp);
#else
        status = sdv_DoNothing();
#endif
        break;
#endif

        default:
        status = sdv_DoNothing();
        break;
    }
    
    sdv_stub_dispatch_end(status,pirp);

    sdv_end_info = pirp->IoStatus.Information;
    return status;
}

NTSTATUS 
sdv_RunQueryDeviceRelations(
    PDEVICE_OBJECT po, 
    PIRP pirp
    )
/*

Routine Description:

   Call PNP dispatch with IRP_MN_QUERY_DEVICE_RELATIONS

Arguments:

    po - pointer to the device object.    
    pirp - pointer to the irp that we're using.

Return value:

    we're passing the dispatch's return value back.

Notes:
    

*/
{
    NTSTATUS status;
    PIO_STACK_LOCATION ps = IoGetCurrentIrpStackLocation(pirp);

    sdv_end_info = sdv_start_info = pirp->IoStatus.Information;
 
    sdv_SetStatus(pirp);

    pirp->CancelRoutine = NULL;


    ps->MinorFunction = IRP_MN_QUERY_DEVICE_RELATIONS;
    ps->MajorFunction = IRP_MJ_PNP;

#ifdef fun_IRP_MJ_PNP
        status = fun_IRP_MJ_PNP(po,pirp);
#else
        status = sdv_DoNothing();
#endif

	return status;
}

NTSTATUS 
sdv_RunStartDevice(
    PDEVICE_OBJECT po, 
    PIRP pirp
    )
/*

Routine Description:

   Run the start device function

Arguments:

    po - pointer to the device object.    
    pirp - pointer to the irp that we're using.

Return value:

    we're passing the dispatch's return value back.

Notes:
    
    We're interacting with SDV meta-data here.  If "fun_IRP_MJ_CREATE" is
    defined in the meta-data, then we're calling it.  Otherwise: we call
    the sdv_DoNothing() function.

*/
{
    NTSTATUS status;

    PIO_STACK_LOCATION ps = IoGetCurrentIrpStackLocation(pirp);
    ps->MajorFunction = IRP_MJ_PNP;
    ps->MinorFunction = IRP_MN_START_DEVICE;
    pirp->CancelRoutine = NULL;
    
    sdv_SetStatus(pirp);
    sdv_start_irp_already_issued = 1;

    sdv_stub_dispatch_begin();
   
    #ifdef fun_IRP_MJ_PNP
        status = fun_IRP_MJ_PNP(po,pirp);
    #else
        status = sdv_DoNothing();
    #endif
    sdv_stub_dispatch_end(status,pirp);

    return status;
}

NTSTATUS 
sdv_RunRemoveDevice(
    PDEVICE_OBJECT po, 
    PIRP pirp
    )
/*

Routine Description:

   Run the remove device function

Arguments:

    po - pointer to the device object.    
    pirp - pointer to the irp that we're using.

Return value:

    we're passing the dispatch's return value back.

*/
{

    NTSTATUS status;

    PIO_STACK_LOCATION ps = IoGetCurrentIrpStackLocation(pirp);
    ps->MajorFunction = IRP_MJ_PNP;
    ps->MinorFunction = IRP_MN_REMOVE_DEVICE;
    pirp->CancelRoutine = NULL;
    
 
    SdvAssume(!sdv_remove_irp_already_issued);
   
    sdv_stub_dispatch_begin();


    sdv_SetStatus(pirp);

    
   
    #ifdef fun_IRP_MJ_PNP
        status = fun_IRP_MJ_PNP(po,pirp);
    #else
        status = sdv_DoNothing();
    #endif
    sdv_stub_dispatch_end(status,pirp);

    return status;

}



VOID
sdv_RunStartIo(
    PDEVICE_OBJECT po, 
    PIRP pirp
    )
{
    sdv_stub_startio_begin();
#ifdef fun_DriverStartIo
    pirp->CancelRoutine = NULL;
    fun_DriverStartIo(po, pirp);
#else
    sdv_DoNothing();
#endif
    sdv_stub_startio_end();
}


VOID
sdv_RunDPC(
    struct _KDPC * kdpc, 
    PVOID pv1, 
    PVOID pv2, 
    PVOID pv3
    )
{
    sdv_stub_dpc_begin();
    sdv_dpc(kdpc, pv1, pv2, pv3);
    sdv_stub_dpc_end();
}



VOID
sdv_RunISR(
    struct _KINTERRUPT *ki, 
    PVOID pv1
    )
{
    if( sdv_isr_registered == TRUE ) {
        sdv_stub_isr_begin();
        sdv_isr_function(ki, pv1);
        sdv_stub_isr_end();
    }
}



VOID
sdv_RunCancelRoutine(
    PDEVICE_OBJECT po, 
    PIRP pirp
    )
{
    if (sdv_cancelFptr_set) {
        IoAcquireCancelSpinLock(&(pirp->CancelIrql));
        sdv_stub_cancel_begin();
        sdv_cancelFptr(po, pirp);
        sdv_stub_cancel_end();
    } 
}




VOID
sdv_RunUnload(
    PDRIVER_OBJECT pdrivo
    )
{
#ifdef fun_DriverUnload
    fun_DriverUnload(pdrivo);
#else
    sdv_DoNothing();
#endif
}




NTSTATUS sdv_RunAddDevice(
    PDRIVER_OBJECT p1,
    PDEVICE_OBJECT p2
    )
{

    NTSTATUS status;
    sdv_stub_add_begin();
#ifdef fun_AddDevice
    status = fun_AddDevice(p1,p2);
#else
    status = sdv_DoNothing();
#endif
    sdv_stub_add_end();
    return status;
}


VOID SdvAssume(int e)
/*
Routine Description:
    Acts like an ASSERT, but halts analysis if the assert fails.
*/
{
  if (!e) SdvExit();
}


VOID SdvAssumeSoft(int e)
/*
Routine Description:
   Acts like an SdvAssume.   
*/
{
  if (!e) SdvExit();
}




/* 
    Disable for SdvExit: C4717: recursive on all control paths,
    function will cause runtime stack overflow.

    This is correctly flagged by the compiler, and would be a serious
    issue if the harness was to be executed rather than simulated.

    However in this case, this is per design in order to simulate
    non-progress:
*/
#pragma warning(disable:4717)

VOID SdvExit() 
/*

Routine Description:

    Acts like "exit()" within the context of model checking.

Notes:
    Since SdvExit contributes no extra reachable states, this serves as a
    dead-end of sorts to tools based on reachabilitity analysis.

*/
{ 
    SdvExit();

    /* Enable after SdvExit: C4717: */
    #pragma warning(default:4717)
}

/* ..\wdm\harness-parts.c end */

/* ..\wdm\ntddk-io.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/



typedef struct _IO_WORKITEM *PIO_WORKITEM;

typedef
VOID
(*PIO_WORKITEM_ROUTINE) (
    IN PDEVICE_OBJECT DeviceObject,
    IN PVOID Context
    );

typedef
VOID
(*PIO_WORKITEM_ROUTINE_EX) (
    IN PVOID IoObject,
    IN PVOID Context,
    IN PIO_WORKITEM IoWorkItem
    );

typedef struct _IO_WORKITEM {
    WORK_QUEUE_ITEM WorkItem;
    PIO_WORKITEM_ROUTINE_EX Routine;
    PVOID IoObject;
    PVOID Context;
    ULONG Type;
#if DBG
    ULONG Size;
#endif
} IO_WORKITEM;


DEVICE_OBJECT sdv_devobj_top;
PDEVICE_OBJECT sdv_p_devobj_top = &sdv_devobj_top;

CONTROLLER_OBJECT sdv_IoCreateController_CONTROLLER_OBJECT;
KEVENT sdv_IoCreateNotificationEvent_KEVENT;
KEVENT sdv_IoCreateSynchronizationEvent_KEVENT;
DEVICE_OBJECT sdv_IoGetDeviceObjectPointer_DEVICE_OBJECT;
DEVICE_OBJECT sdv_IoGetDeviceToVerify_DEVICE_OBJECT;
DMA_ADAPTER sdv_IoGetDmaAdapter_DMA_ADAPTER;
GENERIC_MAPPING sdv_IoGetFileObjectGenericMapping_GENERIC_MAPPING;
DEVICE_OBJECT sdv_IoGetRelatedDeviceObject_DEVICE_OBJECT;
struct _DRIVE_LAYOUT_INFORMATION_EX sdv_IoReadPartitionTableEx_DRIVE_LAYOUT_INFORMATION_EX;




NTKERNELAPI
VOID
IoAcquireCancelSpinLock(
    OUT PKIRQL p_old_irql
    )
{
    SDV_IRQL_PUSH(DISPATCH_LEVEL);
    *p_old_irql = sdv_irql_previous;
}

NTSTATUS
sdv_IoAcquireRemoveLock(
    IN PIO_REMOVE_LOCK RemoveLock,
    IN PVOID Tag
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_UNSUCCESSFUL;
        default: 
            if (sdv_remove_irp_already_issued) {
                return STATUS_DELETE_PENDING;
            }
            else {
	        return STATUS_SUCCESS;
            }
    }
}

NTSYSAPI
NTSTATUS
NTAPI
IoAcquireRemoveLockEx(
    IN PIO_REMOVE_LOCK RemoveLock,
    IN OPTIONAL PVOID Tag,
    IN PCSTR File,
    IN ULONG Line,
    IN ULONG RemlockSize
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_UNSUCCESSFUL;
        default: 
            if (sdv_remove_irp_already_issued) {
                return STATUS_DELETE_PENDING;
            }
            else {
	        return STATUS_SUCCESS;
            }
    }
}

NTKERNELAPI
VOID
sdv_IoAdjustPagingPathCount(
    IN PLONG Count,
    IN BOOLEAN Increment
    )
{
}

NTKERNELAPI
NTSTATUS
sdv_IoAllocateAdapterChannel(
    IN PADAPTER_OBJECT AdapterObject,
    IN PDEVICE_OBJECT DeviceObject,
    IN ULONG NumberOfMapRegisters,
    IN PDRIVER_CONTROL ExecutionRoutine,
    IN PVOID Context
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_INSUFFICIENT_RESOURCES;
    }
}

NTKERNELAPI
VOID
IoAllocateController(
    IN PCONTROLLER_OBJECT ControllerObject,
    IN PDEVICE_OBJECT DeviceObject,
    IN PDRIVER_CONTROL ExecutionRoutine,
    IN PVOID Context
    )
{
}

NTKERNELAPI
NTSTATUS
IoAllocateDriverObjectExtension(
    IN PDRIVER_OBJECT DriverObject,
    IN PVOID ClientIdentificationAddress,
    IN ULONG DriverObjectExtensionSize,
    OUT PVOID *DriverObjectExtension
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_INSUFFICIENT_RESOURCES;
        default: return STATUS_OBJECT_NAME_COLLISION;
    }
}

NTKERNELAPI
PVOID
IoAllocateErrorLogEntry(
    IN PVOID IoObject,
    IN UCHAR EntrySize
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return malloc(0);
        default: return NULL;
    }
}

NTKERNELAPI
PIRP
IoAllocateIrp(
    IN CCHAR StackSize,
    IN BOOLEAN ChargeQuota
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return sdv_other_irp;
        default: return NULL;
    }
}

NTKERNELAPI
PMDL
IoAllocateMdl(
    IN PVOID VirtualAddress,
    IN ULONG Length,
    IN BOOLEAN SecondaryBuffer,
    IN BOOLEAN ChargeQuota,
    IN OUT PIRP pirp OPTIONAL
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return (PMDL) malloc(0);
        default: return NULL;
    }
}

PIO_WORKITEM
IoAllocateWorkItem(
    IN PDEVICE_OBJECT DeviceObject
    )
{
    int choice = SdvMakeChoice();
    PIO_WORKITEM ioWorkItem = (PIO_WORKITEM) malloc(0);
    switch (choice) {

    case 0:

        SdvAssume(ioWorkItem != NULL);
        ioWorkItem->WorkItem.List.Flink = NULL;
        return ioWorkItem;

    default:

        return NULL;

    }
}

VOID
sdv_IoAssignArcName(
    IN PUNICODE_STRING ArcName,
    IN PUNICODE_STRING DeviceName
    )
{
}

NTKERNELAPI
NTSTATUS
IoAssignResources(
    IN PUNICODE_STRING RegistryPath,
    IN PUNICODE_STRING DriverClassName OPTIONAL,
    IN PDRIVER_OBJECT DriverObject,
    IN PDEVICE_OBJECT DeviceObject OPTIONAL,
    IN PIO_RESOURCE_REQUIREMENTS_LIST RequestedResources,
    IN OUT PCM_RESOURCE_LIST *AllocatedResources
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
NTSTATUS
IoAttachDevice(
    IN PDEVICE_OBJECT SourceDevice,
    IN PUNICODE_STRING TargetDevice,
    OUT PDEVICE_OBJECT *AttachedDevice
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_INVALID_PARAMETER;
        case 2: return STATUS_OBJECT_TYPE_MISMATCH;
        case 3: return STATUS_OBJECT_NAME_INVALID;
        default: return STATUS_INSUFFICIENT_RESOURCES;
    }
}

NTKERNELAPI
NTSTATUS
IoAttachDeviceByPointer(
    IN PDEVICE_OBJECT SourceDevice,
    IN PDEVICE_OBJECT TargetDevice
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
PDEVICE_OBJECT
IoAttachDeviceToDeviceStack(
    IN PDEVICE_OBJECT SourceDevice,
    IN PDEVICE_OBJECT TargetDevice
    )
{
    if (TargetDevice == sdv_p_devobj_one) {
        return TargetDevice;
    } else {
        return NULL;
    }
}

NTKERNELAPI
PIRP
IoBuildAsynchronousFsdRequest(
    IN ULONG MajorFunction,
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PVOID Buffer OPTIONAL,
    IN ULONG Length OPTIONAL,
    IN PLARGE_INTEGER StartingOffset OPTIONAL,
    IN PIO_STATUS_BLOCK IoStatusBlock OPTIONAL
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {

    case 0:

        sdv_other_irp->Tail.Overlay.CurrentStackLocation->MajorFunction=
            (UCHAR) MajorFunction;
        return sdv_other_irp;

    default:

        return NULL;

    }
}

NTKERNELAPI
PIRP
IoBuildDeviceIoControlRequest(
    IN ULONG IoControlCode,
    IN PDEVICE_OBJECT DeviceObject,
    IN PVOID InputBuffer OPTIONAL,
    IN ULONG InputBufferLength,
    OUT PVOID OutputBuffer OPTIONAL,
    IN ULONG OutputBufferLength,
    IN BOOLEAN InternalDeviceIoControl,
    IN PKEVENT Event,
    OUT PIO_STATUS_BLOCK IoStatusBlock
    )
{
    int choice = SdvMakeChoice();

    IoStatusBlock->Status = STATUS_SUCCESS;

    switch (choice) {

    case 0:

        sdv_other_irp->Tail.Overlay.CurrentStackLocation->MajorFunction=
            IRP_MJ_DEVICE_CONTROL;
        return sdv_other_irp;

    default:

        return NULL;

    }
}

NTKERNELAPI
VOID
IoBuildPartialMdl(
    IN PMDL SourceMdl,
    IN OUT PMDL TargetMdl,
    IN PVOID VirtualAddress,
    IN ULONG Length
    )
{
}

NTKERNELAPI
PIRP
IoBuildSynchronousFsdRequest(
    IN ULONG MajorFunction,
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PVOID Buffer OPTIONAL,
    IN ULONG Length OPTIONAL,
    IN PLARGE_INTEGER StartingOffset OPTIONAL,
    IN PKEVENT Event,
    OUT PIO_STATUS_BLOCK IoStatusBlock
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {

    case 0:

        sdv_other_irp->Tail.Overlay.CurrentStackLocation->MajorFunction=
            (UCHAR) MajorFunction;
            return sdv_other_irp;

    default:

            return NULL;

    }
}

NTKERNELAPI
NTSTATUS
sdv_IoCallDriver(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp
    )
{

    int choice = SdvMakeChoice();
    NTSTATUS compRetStatus;
    PVOID lcontext = sdv_context;

    NTSTATUS status;

    switch (choice) {

    case 0:

        Irp->IoStatus.Status = STATUS_SUCCESS;
        status=STATUS_SUCCESS;
        Irp->PendingReturned = 0;
        break;

    case 1:

        Irp->IoStatus.Status = STATUS_UNSUCCESSFUL;
        status=STATUS_UNSUCCESSFUL;
        Irp->PendingReturned = 0;
        break;

    default:
        status=STATUS_PENDING;
        Irp->PendingReturned = 1;
        break;

    }

    SdvAssume(Irp->IoStatus.Status != STATUS_PENDING);

    if (status != STATUS_PENDING) {
        SdvAssume( status == Irp->IoStatus.Status) ;
    }

    if (sdv_compFset) {
        sdv_stub_completion_begin(Irp);
        compRetStatus = (*sdv_compFptr)(DeviceObject, Irp, lcontext);
        sdv_stub_completion_end(Irp);

        if(compRetStatus == STATUS_MORE_PROCESSING_REQUIRED)
            sdv_stub_MoreProcessingRequired(Irp);
    }

    return status;
}

NTKERNELAPI
BOOLEAN
IoCancelIrp(
    IN PIRP Irp
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return FALSE;
        default: return TRUE;
    }
}

NTKERNELAPI
NTSTATUS
IoCheckShareAccess(
    IN ACCESS_MASK DesiredAccess,
    IN ULONG DesiredShareAccess,
    IN OUT PFILE_OBJECT FileObject,
    IN OUT PSHARE_ACCESS ShareAccess,
    IN BOOLEAN Update
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_SHARING_VIOLATION;
    }
}

VOID
sdv_IoCompleteRequest(
    IN PIRP pirp,
    IN CCHAR PriorityBoost
    )
{
}

NTKERNELAPI
NTSTATUS
IoConnectInterrupt(
    OUT PKINTERRUPT *InterruptObject,
    IN PKSERVICE_ROUTINE ServiceRoutine,
    IN PVOID ServiceContext,
    IN PKSPIN_LOCK SpinLock OPTIONAL,
    IN ULONG Vector,
    IN KIRQL Irql,
    IN KIRQL SynchronizeIrql,
    IN KINTERRUPT_MODE InterruptMode,
    IN BOOLEAN ShareVector,
    IN KAFFINITY ProcessorEnableMask,
    IN BOOLEAN FloatingSave
    )
{
    int choice = SdvMakeChoice();
    sdv_isr_registered = TRUE;
    sdv_isr_function = ServiceRoutine;
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_INVALID_PARAMETER;
        default: return STATUS_INSUFFICIENT_RESOURCES;
    }
}

#if WINVER >= 0x0600
NTKERNELAPI
NTSTATUS
IoConnectInterruptEx(
    IN OUT PIO_CONNECT_INTERRUPT_PARAMETERS Parameters
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_INVALID_DEVICE_REQUEST;
        case 3: return STATUS_INVALID_PARAMETER;
        case 4: return STATUS_INVALID_PARAMETER_1;
        case 5: return STATUS_INVALID_PARAMETER_10;
        default: return STATUS_NOT_FOUND;
    }
}
#endif

VOID
sdv_IoCopyCurrentIrpStackLocationToNext(
    IN PIRP pirp
    )
{
    if (pirp == &sdv_harnessIrp) {
        sdv_harnessStackLocation_next.MinorFunction =
            sdv_harnessStackLocation.MinorFunction;
        sdv_harnessStackLocation_next.MajorFunction =
            sdv_harnessStackLocation.MajorFunction;
    };
    if (pirp == &sdv_other_harnessIrp) {
        sdv_other_harnessStackLocation_next.MinorFunction =
            sdv_other_harnessStackLocation.MinorFunction;
        sdv_other_harnessStackLocation_next.MajorFunction =
            sdv_other_harnessStackLocation.MajorFunction;
    }
}

NTKERNELAPI
PCONTROLLER_OBJECT
IoCreateController(
    IN ULONG Size
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return &sdv_IoCreateController_CONTROLLER_OBJECT;
        default: return NULL;
    }
}

NTKERNELAPI
NTSTATUS
IoCreateDevice(
    IN PDRIVER_OBJECT DriverObject,
    IN ULONG DeviceExtensionSize,
    IN PUNICODE_STRING DeviceName OPTIONAL,
    IN DEVICE_TYPE DeviceType,
    IN ULONG DeviceCharacteristics,
    IN BOOLEAN Exclusive,
    OUT PDEVICE_OBJECT *DeviceObject
    )
{

    int choice = SdvMakeChoice();

    sdv_io_create_device_called++;

    switch (choice) {
        case 0: (*DeviceObject) = sdv_p_devobj_two; return STATUS_SUCCESS;
        case 1: (*DeviceObject) = NULL; return STATUS_UNSUCCESSFUL;
        case 2: (*DeviceObject) = NULL; return STATUS_INSUFFICIENT_RESOURCES;
        case 3: (*DeviceObject) = NULL; return STATUS_OBJECT_NAME_EXISTS;
        default: (*DeviceObject) = NULL; return STATUS_OBJECT_NAME_COLLISION;
    }
}

NTKERNELAPI
NTSTATUS
sdv_IoCreateDeviceSecure(
    IN PDRIVER_OBJECT DriverObject,
    IN ULONG DeviceExtensionSize,
    IN PUNICODE_STRING DeviceName OPTIONAL,
    IN DEVICE_TYPE DeviceType,
    IN ULONG DeviceCharacteristics,
    IN BOOLEAN Exclusive,
    IN PCUNICODE_STRING DefaultSDDLString,
    IN LPCGUID DeviceClassGuid OPTIONAL,
    OUT PDEVICE_OBJECT *DeviceObject
    )
{

    int choice = SdvMakeChoice();

    sdv_io_create_device_called++;

    switch (choice) {
        case 0: (*DeviceObject) = sdv_p_devobj_two; return STATUS_SUCCESS;
        case 1: (*DeviceObject) = NULL; return STATUS_UNSUCCESSFUL;
        case 2: (*DeviceObject) = NULL; return STATUS_INSUFFICIENT_RESOURCES;
        case 3: (*DeviceObject) = NULL; return STATUS_OBJECT_NAME_EXISTS;
        default: (*DeviceObject) = NULL; return STATUS_OBJECT_NAME_COLLISION;
    }
}

NTKERNELAPI
NTSTATUS
IoCreateFile(
    OUT PHANDLE FileHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    OUT PIO_STATUS_BLOCK IoStatusBlock,
    IN PLARGE_INTEGER AllocationSize OPTIONAL,
    IN ULONG FileAttributes,
    IN ULONG ShareAccess,
    IN ULONG Disposition,
    IN ULONG CreateOptions,
    IN PVOID EaBuffer OPTIONAL,
    IN ULONG EaLength,
    IN CREATE_FILE_TYPE CreateFileType,
    IN PVOID ExtraCreateParameters OPTIONAL,
    IN ULONG Options
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
PKEVENT
IoCreateNotificationEvent(
    IN PUNICODE_STRING EventName,
    OUT PHANDLE EventHandle
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return &sdv_IoCreateNotificationEvent_KEVENT;
        default: return NULL;
    }
}

NTKERNELAPI
NTSTATUS
IoCreateSymbolicLink(
    IN PUNICODE_STRING SymbolicLinkName,
    IN PUNICODE_STRING DeviceName
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
PKEVENT
IoCreateSynchronizationEvent(
    IN PUNICODE_STRING EventName,
    OUT PHANDLE EventHandle
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return &sdv_IoCreateSynchronizationEvent_KEVENT;
        default: return NULL;
    }
}

NTKERNELAPI
NTSTATUS
IoCreateUnprotectedSymbolicLink(
    IN PUNICODE_STRING SymbolicLinkName,
    IN PUNICODE_STRING DeviceName
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTSTATUS
sdv_IoCsqInitialize(
    IN PIO_CSQ Csq,
    IN PIO_CSQ_INSERT_IRP CsqInsertIrp,
    IN PIO_CSQ_REMOVE_IRP CsqRemoveIrp,
    IN PIO_CSQ_PEEK_NEXT_IRP CsqPeekNextIrp,
    IN PIO_CSQ_ACQUIRE_LOCK CsqAcquireLock,
    IN PIO_CSQ_RELEASE_LOCK CsqReleaseLock,
    IN PIO_CSQ_COMPLETE_CANCELED_IRP CsqCompleteCanceledIrp
    )
{
    Csq->CsqInsertIrp = CsqInsertIrp;
    Csq->CsqRemoveIrp = CsqRemoveIrp;
    Csq->CsqPeekNextIrp = CsqPeekNextIrp;
    Csq->CsqAcquireLock = CsqAcquireLock;
    Csq->CsqReleaseLock = CsqReleaseLock;
    Csq->CsqCompleteCanceledIrp = CsqCompleteCanceledIrp;
    Csq->ReservePointer = NULL;

    Csq->Type = IO_TYPE_CSQ;

    return STATUS_SUCCESS;
}

NTKERNELAPI
NTSTATUS
sdv_IoCsqInitializeEx(
    IN PIO_CSQ Csq,
    IN PIO_CSQ_INSERT_IRP_EX CsqInsertIrp,
    IN PIO_CSQ_REMOVE_IRP CsqRemoveIrp,
    IN PIO_CSQ_PEEK_NEXT_IRP CsqPeekNextIrp,
    IN PIO_CSQ_ACQUIRE_LOCK CsqAcquireLock,
    IN PIO_CSQ_RELEASE_LOCK CsqReleaseLock,
    IN PIO_CSQ_COMPLETE_CANCELED_IRP CsqCompleteCanceledIrp 
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

VOID
sdv_IoCsqInsertIrp(
    IN PIO_CSQ Csq,
    IN PIRP pirp,
    IN PIO_CSQ_IRP_CONTEXT Context
    )
{
    Csq->CsqInsertIrp(Csq, pirp);
    IoMarkIrpPending(pirp);
}

NTSTATUS
sdv_IoCsqInsertIrpEx(
    IN PIO_CSQ Csq,
    IN PIRP pirp,
    IN PIO_CSQ_IRP_CONTEXT Context,
    IN PVOID InsertContext
    )
{
    NTSTATUS status;

    PIO_CSQ_INSERT_IRP_EX func;

    func = (PIO_CSQ_INSERT_IRP_EX)Csq->CsqInsertIrp;

    status = func(Csq, pirp, InsertContext);

    if (!NT_SUCCESS(status)) {
        return status;
    }
    IoMarkIrpPending(pirp);

    return status;
}

NTKERNELAPI
PIRP
sdv_IoCsqRemoveIrp(
    IN PIO_CSQ Csq,
    IN PIO_CSQ_IRP_CONTEXT Context
    )
{

    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return (PIRP) malloc(0);
        default: return NULL;
    }
}

PIRP
sdv_IoCsqRemoveNextIrp(
    IN PIO_CSQ Csq,
    IN PVOID PeekContext
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return (PIRP) malloc(0);
        default: return NULL;
    }
}

NTKERNELAPI
VOID
sdv_IoDeassignArcName(
    IN PUNICODE_STRING ArcName
    )
{
}

NTKERNELAPI
VOID
IoDeleteController(
    IN PCONTROLLER_OBJECT ControllerObject
    )
{
}

NTKERNELAPI
VOID
IoDeleteDevice(
    IN PDEVICE_OBJECT DeviceObject
    )
{
}

NTKERNELAPI
NTSTATUS
IoDeleteSymbolicLink(
    IN PUNICODE_STRING SymbolicLinkName
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
VOID
IoDetachDevice(
    IN OUT PDEVICE_OBJECT TargetDevice
    )
{
}

NTKERNELAPI
VOID
IoDisconnectInterrupt(
    IN PKINTERRUPT InterruptObject
    )
{
}

#if WINVER >= 0x0600
NTKERNELAPI
VOID
IoDisconnectInterruptEx(
    IN OUT PIO_DISCONNECT_INTERRUPT_PARAMETERS Parameters
    )
{
}
#endif

NTKERNELAPI
BOOLEAN
sdv_IoFlushAdapterBuffers(
    IN PADAPTER_OBJECT AdapterObject,
    IN PMDL Mdl,
    IN PVOID MapRegisterBase,
    IN PVOID CurrentVa,
    IN ULONG Length,
    IN BOOLEAN WriteToDevice
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return FALSE;
        default: return TRUE;
    }
}

NTKERNELAPI
BOOLEAN
IoForwardIrpSynchronously(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp 
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return FALSE;
        default: return TRUE;
    }
}

NTKERNELAPI
VOID
sdv_IoFreeAdapterChannel(
    IN PADAPTER_OBJECT AdapterObject
    )
{
}

NTKERNELAPI
VOID
IoFreeController(
    IN PCONTROLLER_OBJECT ControllerObject
    )
{
}

NTKERNELAPI
VOID
IoFreeErrorLogEntry(
    PVOID ElEntry
    )
{
}

NTKERNELAPI
VOID
IoFreeIrp(
    IN PIRP pirp
    )
{
}

VOID 
sdv_IoFreeMapRegisters(
    IN PADAPTER_OBJECT AdapterObject,
    IN PVOID MapRegisterBase,
    IN ULONG NumberOfMapRegisters
    )
{
}

NTKERNELAPI
VOID
IoFreeMdl(
    IN PMDL Mdl
    )
{
}

VOID
IoFreeWorkItem(
    IN PIO_WORKITEM IoWorkItem
    )
{
}

NTKERNELAPI
PDEVICE_OBJECT
IoGetAttachedDeviceReference(
    IN PDEVICE_OBJECT DeviceObject
    )
{
    return &sdv_devobj_top;
}

NTKERNELAPI
NTSTATUS
IoGetBootDiskInformation(
    IN OUT PBOOTDISK_INFORMATION BootDiskInformation,
    IN ULONG Size
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_INVALID_PARAMETER;
        default: return STATUS_TOO_LATE;
    }
}

NTKERNELAPI
PCONFIGURATION_INFORMATION
IoGetConfigurationInformation(
    VOID
    )
{
    return (PCONFIGURATION_INFORMATION) malloc(0);
}

PIO_STACK_LOCATION
sdv_IoGetCurrentIrpStackLocation(
    IN PIRP pirp
    )
{
    return (pirp->Tail.Overlay.CurrentStackLocation);
}

NTKERNELAPI
PEPROCESS
IoGetCurrentProcess(
    VOID
    )
{
    PEPROCESS p = (PEPROCESS) malloc(0);
    return p;
}

NTKERNELAPI
NTSTATUS
NTAPI
IoGetDeviceInterfaceAlias(
    IN PUNICODE_STRING SymbolicLinkName,
    IN CONST GUID *AliasInterfaceClassGuid,
    OUT PUNICODE_STRING AliasSymbolicLinkName
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_OBJECT_NAME_NOT_FOUND;
        case 3: return STATUS_OBJECT_PATH_NOT_FOUND;
        default: return STATUS_INVALID_HANDLE;
    }
}

NTKERNELAPI
NTSTATUS
NTAPI
IoGetDeviceInterfaces(
    IN CONST GUID *InterfaceClassGuid,
    IN PDEVICE_OBJECT PhysicalDeviceObject OPTIONAL,
    IN ULONG Flags,
    OUT PWSTR *SymbolicLinkList
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: SdvAssume(*SymbolicLinkList != NULL);  
                return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        default: return STATUS_INVALID_DEVICE_REQUEST;
    }
}

NTKERNELAPI
NTSTATUS
IoGetDeviceObjectPointer(
    IN PUNICODE_STRING ObjectName,
    IN ACCESS_MASK DesiredAccess,
    OUT PFILE_OBJECT *FileObject,
    OUT PDEVICE_OBJECT *DeviceObject
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: *DeviceObject = &sdv_IoGetDeviceObjectPointer_DEVICE_OBJECT;
                return STATUS_SUCCESS;
        case 1: return STATUS_OBJECT_TYPE_MISMATCH;
        case 2: return STATUS_INVALID_PARAMETER;
        case 3: return STATUS_PRIVILEGE_NOT_HELD;
        case 4: return STATUS_INSUFFICIENT_RESOURCES;
        default: return STATUS_OBJECT_NAME_INVALID;
    }
}

NTKERNELAPI
NTSTATUS
IoGetDeviceProperty(
    IN PDEVICE_OBJECT DeviceObject,
    IN DEVICE_REGISTRY_PROPERTY DeviceProperty,
    IN ULONG BufferLength,
    OUT PVOID PropertyBuffer,
    OUT PULONG ResultLength
    )
{
    ULONG L = SdvMakeChoice();
    if ( L <= 0 ) {
        switch ( L ) {
            case 0: return STATUS_UNSUCCESSFUL;
            case -1: return STATUS_INVALID_PARAMETER_2;
            default: return STATUS_INVALID_DEVICE_REQUEST;
        }
    } else if ( L <= BufferLength ) {
        *ResultLength = L;
        return STATUS_SUCCESS;
    } else {
        *ResultLength = L;
        return STATUS_BUFFER_TOO_SMALL;
    }
}

NTKERNELAPI
PDEVICE_OBJECT
IoGetDeviceToVerify(
    IN PETHREAD Thread
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return NULL;
        default: return &sdv_IoGetDeviceToVerify_DEVICE_OBJECT;
    }
}

NTKERNELAPI
PDMA_ADAPTER
IoGetDmaAdapter(
    IN PDEVICE_OBJECT PhysicalDeviceObject,
    IN PDEVICE_DESCRIPTION DeviceDescription,
    IN OUT PULONG NumberOfMapRegisters
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return NULL;
        default: return &sdv_IoGetDmaAdapter_DMA_ADAPTER;
    }
}

NTKERNELAPI
PVOID
IoGetDriverObjectExtension(
    IN PDRIVER_OBJECT DriverObject,
    IN PVOID ClientIdentificationAddress
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return malloc(0);
        default: return NULL;
    }
}

NTKERNELAPI
PGENERIC_MAPPING
IoGetFileObjectGenericMapping(
    VOID
    )
{
    return &sdv_IoGetFileObjectGenericMapping_GENERIC_MAPPING;
}

NTKERNELAPI
ULONG
sdv_IoGetFunctionCodeFromCtlCode(
    IN ULONG ControlCode
    )
{
    ULONG res;
    res = SdvMakeChoice();
    return res;
}

NTKERNELAPI
PVOID
IoGetInitialStack(
    VOID
    )
{
    return malloc(0);
}

PIO_STACK_LOCATION
sdv_IoGetNextIrpStackLocation(
    IN PIRP pirp
    )
{
    if (pirp == &sdv_harnessIrp) {
        return &sdv_harnessStackLocation_next;
    } else if (pirp == &sdv_other_harnessIrp) {
        return &sdv_other_harnessStackLocation_next;
    } else {
        SdvAssume(0);
        return &sdv_harnessStackLocation;
    }
}

NTKERNELAPI
PDEVICE_OBJECT
IoGetRelatedDeviceObject(
    IN PFILE_OBJECT FileObject
    )
{
    return &sdv_IoGetRelatedDeviceObject_DEVICE_OBJECT;
}

NTKERNELAPI
ULONG_PTR
sdv_IoGetRemainingStackSize(
    VOID
    )
{
    ULONG_PTR l = SdvMakeChoice();
    return l;
}

NTKERNELAPI
VOID
IoGetStackLimits(
    OUT PULONG_PTR LowLimit,
    OUT PULONG_PTR HighLimit
    )
{
}

VOID
sdv_IoInitializeDpcRequest(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIO_DPC_ROUTINE DpcRoutine
    )
{
    sdv_dpc = (PKDEFERRED_ROUTINE) DpcRoutine;
}

NTKERNELAPI
VOID
IoInitializeIrp(
    IN OUT PIRP Irp,
    IN USHORT PacketSize,
    IN CCHAR StackSize
    )
{
}

NTKERNELAPI
VOID
sdv_IoInitializeRemoveLock(
    IN PIO_REMOVE_LOCK Lock,
    IN ULONG AllocateTag,
    IN ULONG MaxLockedMinutes,
    IN ULONG HighWatermark
    )
{
}


NTKERNELAPI
NTSTATUS
IoInitializeTimer(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIO_TIMER_ROUTINE TimerRoutine,
    IN PVOID Context
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

VOID
IoInitializeWorkItem(
    IN PVOID IoObject,
    IN PIO_WORKITEM IoWorkItem
    )
{
}

NTKERNELAPI
VOID
IoInvalidateDeviceRelations(
    IN PDEVICE_OBJECT DeviceObject,
    IN DEVICE_RELATION_TYPE Type
    )
{
}

NTKERNELAPI
VOID
IoInvalidateDeviceState(
    IN PDEVICE_OBJECT PhysicalDeviceObject
    )
{
}

NTKERNELAPI
BOOLEAN
IoIs32bitProcess(
    IN PIRP Irp OPTIONAL
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return FALSE;
        default: return TRUE;
    }
}

NTKERNELAPI
BOOLEAN
sdv_IoIsErrorUserInduced(
    IN NTSTATUS Status
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return FALSE;
        default: return TRUE;
    }
}

NTKERNELAPI
BOOLEAN
IoIsWdmVersionAvailable(
    IN UCHAR MajorVersion,
    IN UCHAR MinorVersion
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return FALSE;
        default: return TRUE;
    }
}

NTKERNELAPI
PIRP
IoMakeAssociatedIrp(
    IN PIRP pirp,
    IN CCHAR StackSize
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return sdv_other_irp;
        default: return NULL;
    }
}

NTKERNELAPI
PHYSICAL_ADDRESS
sdv_IoMapTransfer(
    IN PADAPTER_OBJECT AdapterObject,
    IN PMDL Mdl,
    IN PVOID MapRegisterBase,
    IN PVOID CurrentVa,
    IN OUT PULONG Length,
    IN BOOLEAN WriteToDevice
    )
{
    PHYSICAL_ADDRESS l;
    l.QuadPart = (LONGLONG) SdvMakeChoice();
    return l;
}

VOID
sdv_IoMarkIrpPending(
    IN OUT PIRP pirp
    )
{
}

NTKERNELAPI
NTSTATUS
IoOpenDeviceInterfaceRegistryKey(
    IN PUNICODE_STRING SymbolicLinkName,
    IN ACCESS_MASK DesiredAccess,
    OUT PHANDLE DeviceInterfaceKey
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_OBJECT_NAME_NOT_FOUND;
        case 3: return STATUS_OBJECT_PATH_NOT_FOUND;
        default: return STATUS_INVALID_PARAMETER;
    }
}

NTKERNELAPI
NTSTATUS
IoOpenDeviceRegistryKey(
    IN PDEVICE_OBJECT DeviceObject,
    IN ULONG DevInstKeyType,
    IN ACCESS_MASK DesiredAccess,
    OUT PHANDLE DevInstRegKey
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_INVALID_PARAMETER;
        default: return STATUS_INVALID_DEVICE_REQUEST;
    }
}

NTKERNELAPI
NTSTATUS
IoQueryDeviceDescription(
    IN PINTERFACE_TYPE BusType OPTIONAL,
    IN PULONG BusNumber OPTIONAL,
    IN PCONFIGURATION_TYPE ControllerType OPTIONAL,
    IN PULONG ControllerNumber OPTIONAL,
    IN PCONFIGURATION_TYPE PeripheralType OPTIONAL,
    IN PULONG PeripheralNumber OPTIONAL,
    IN PIO_QUERY_DEVICE_ROUTINE CalloutRoutine,
    IN PVOID Context
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
VOID
IoQueueWorkItem(
    IN PIO_WORKITEM IoWorkItem,
    IN PIO_WORKITEM_ROUTINE WorkerRoutine,
    IN WORK_QUEUE_TYPE QueueType,
    IN PVOID Context
    )
{
}

NTKERNELAPI
VOID
IoQueueWorkItemEx(
    IN PIO_WORKITEM IoWorkItem,
    IN PIO_WORKITEM_ROUTINE_EX WorkerRoutine,
    IN WORK_QUEUE_TYPE QueueType,
    IN PVOID Context
    )
{
}

NTKERNELAPI
VOID
IoRaiseHardError(
    IN PIRP Irp,
    IN PVPB Vpb OPTIONAL,
    IN PDEVICE_OBJECT RealDeviceObject
    )
{
}

NTKERNELAPI
BOOLEAN
IoRaiseInformationalHardError(
    IN NTSTATUS ErrorStatus,
    IN PUNICODE_STRING String OPTIONAL,
    IN PKTHREAD Thread OPTIONAL
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return FALSE;
        default: return TRUE;
    }
}

NTKERNELAPI
VOID
IoRegisterBootDriverReinitialization(
    IN PDRIVER_OBJECT DriverObject,
    IN PDRIVER_REINITIALIZE DriverReinitializationRoutine,
    IN PVOID Context
    )
{
}

NTKERNELAPI
NTSTATUS
NTAPI
IoRegisterDeviceInterface(
    IN PDEVICE_OBJECT PhysicalDeviceObject,
    IN CONST GUID *InterfaceClassGuid,
    IN PUNICODE_STRING ReferenceString, OPTIONAL
    OUT PUNICODE_STRING SymbolicLinkName
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: SdvAssume(SymbolicLinkName->Buffer != NULL);
                return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        default: return STATUS_INVALID_DEVICE_REQUEST;
    }
}

NTKERNELAPI
VOID
IoRegisterDriverReinitialization(
    IN PDRIVER_OBJECT DriverObject,
    IN PDRIVER_REINITIALIZE DriverReinitializationRoutine,
    IN PVOID Context
    )
{
}

NTKERNELAPI
NTSTATUS
IoRegisterLastChanceShutdownNotification(
    IN PDEVICE_OBJECT DeviceObject
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
NTSTATUS
IoRegisterPlugPlayNotification(
    IN IO_NOTIFICATION_EVENT_CATEGORY EventCategory,
    IN ULONG EventCategoryFlags,
    IN PVOID EventCategoryData OPTIONAL,
    IN PDRIVER_OBJECT DriverObject,
    IN PDRIVER_NOTIFICATION_CALLBACK_ROUTINE CallbackRoutine,
    IN PVOID Context,
    OUT PVOID *NotificationEntry
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
NTSTATUS
IoRegisterShutdownNotification(
    IN PDEVICE_OBJECT DeviceObject
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
VOID
IoReleaseCancelSpinLock(
    IN KIRQL new_irql
    )
{
    SDV_IRQL_POPTO(new_irql);
}

VOID
sdv_IoReleaseRemoveLock(
    IN PIO_REMOVE_LOCK RemoveLock,
    IN PVOID Tag
    )
{
}

VOID
sdv_IoReleaseRemoveLockAndWait(
    IN PIO_REMOVE_LOCK RemoveLock,
    IN PVOID Tag
    )
{
}



NTKERNELAPI
VOID
IoRemoveShareAccess(
    IN PFILE_OBJECT FileObject,
    IN OUT PSHARE_ACCESS ShareAccess
    )
{
}

NTKERNELAPI
NTSTATUS
IoReportDetectedDevice(
    IN PDRIVER_OBJECT DriverObject,
    IN INTERFACE_TYPE LegacyBusType,
    IN ULONG BusNumber,
    IN ULONG SlotNumber,
    IN PCM_RESOURCE_LIST ResourceList,
    IN PIO_RESOURCE_REQUIREMENTS_LIST ResourceRequirements OPTIONAL,
    IN BOOLEAN ResourceAssigned,
    IN OUT PDEVICE_OBJECT *DeviceObject
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
NTSTATUS
IoReportResourceForDetection(
    IN PDRIVER_OBJECT DriverObject,
    IN PCM_RESOURCE_LIST DriverList OPTIONAL,
    IN ULONG DriverListSize OPTIONAL,
    IN PDEVICE_OBJECT DeviceObject OPTIONAL,
    IN PCM_RESOURCE_LIST DeviceList OPTIONAL,
    IN ULONG DeviceListSize OPTIONAL,
    OUT PBOOLEAN ConflictDetected
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        default: return STATUS_CONFLICTING_ADDRESSES;
    }
}

NTKERNELAPI
NTSTATUS
IoReportResourceUsage(
    IN PUNICODE_STRING DriverClassName OPTIONAL,
    IN PDRIVER_OBJECT DriverObject,
    IN PCM_RESOURCE_LIST DriverList OPTIONAL,
    IN ULONG DriverListSize OPTIONAL,
    IN PDEVICE_OBJECT DeviceObject,
    IN PCM_RESOURCE_LIST DeviceList OPTIONAL,
    IN ULONG DeviceListSize OPTIONAL,
    IN BOOLEAN OverrideConflict,
    OUT PBOOLEAN ConflictDetected
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
NTSTATUS
IoReportTargetDeviceChange(
    IN PDEVICE_OBJECT PhysicalDeviceObject,
    IN PVOID NotificationStructure
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        default: return STATUS_INVALID_DEVICE_REQUEST;
    }
}

NTKERNELAPI
NTSTATUS
IoReportTargetDeviceChangeAsynchronous(
    IN PDEVICE_OBJECT PhysicalDeviceObject,
    IN PVOID NotificationStructure,
    IN PDEVICE_CHANGE_COMPLETE_CALLBACK Callback OPTIONAL,
    IN PVOID Context OPTIONAL
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        default: return STATUS_INVALID_DEVICE_REQUEST;
    }
}

NTKERNELAPI
VOID
IoRequestDeviceEject(
    IN PDEVICE_OBJECT PhysicalDeviceObject
    )
{
}

NTKERNELAPI
VOID
sdv_IoRequestDpc(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PVOID Context
    )
{
}

NTKERNELAPI
VOID
IoReuseIrp(
    IN OUT PIRP Irp,
    IN NTSTATUS Status
    )
{
}

PDRIVER_CANCEL
sdv_IoSetCancelRoutine(
    IN PIRP pirp,
    IN PDRIVER_CANCEL CancelRoutine
    )
{
    /* Suppress C4055: Casting data pointers to function pointers.
       This is acceptable as the OS Model will not be executed: */
    #pragma warning(disable:4055)
    PDRIVER_CANCEL r = (PDRIVER_CANCEL) malloc(0);
    #pragma warning(default:4055)
    pirp->CancelRoutine = CancelRoutine;
    sdv_cancelFptr = CancelRoutine;
    sdv_cancelFptr_set = 1;
    return r;
}

NTKERNELAPI
VOID
sdv_IoSetCompletionRoutine(
    IN PIRP pirp,
    IN PIO_COMPLETION_ROUTINE CompletionRoutine,
    IN PVOID Context,
    IN BOOLEAN InvokeOnSuccess,
    IN BOOLEAN InvokeOnError,
    IN BOOLEAN InvokeOnCancel
    )
{
    sdv_compFptr = CompletionRoutine;
    sdv_compFset = 1;
    sdv_context = Context;
}

NTKERNELAPI
NTSTATUS
sdv_IoSetCompletionRoutineEx(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PIO_COMPLETION_ROUTINE CompletionRoutine,
    IN PVOID Context,
    IN BOOLEAN InvokeOnSuccess,
    IN BOOLEAN InvokeOnError,
    IN BOOLEAN InvokeOnCancel
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: 
           sdv_compFptr = CompletionRoutine;
           sdv_compFset = 1;
           sdv_context = Context;
 	   return STATUS_SUCCESS;
        default: return STATUS_INSUFFICIENT_RESOURCES;
    }
}

NTKERNELAPI
NTSTATUS
IoSetDeviceInterfaceState(
    IN PUNICODE_STRING SymbolicLinkName,
    IN BOOLEAN Enable
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_OBJECT_NAME_EXISTS;
        default: return STATUS_OBJECT_NAME_NOT_FOUND;
    }
}

NTKERNELAPI
VOID
IoSetHardErrorOrVerifyDevice(
    IN PIRP Irp,
    IN PDEVICE_OBJECT DeviceObject
    )
{
}

NTKERNELAPI
VOID
sdv_IoSetNextIrpStackLocation(
    IN OUT PIRP Irp
    )
{
}

NTKERNELAPI
VOID
IoSetShareAccess(
    IN ACCESS_MASK DesiredAccess,
    IN ULONG DesiredShareAccess,
    IN OUT PFILE_OBJECT FileObject,
    OUT PSHARE_ACCESS ShareAccess
    )
{
}

VOID
IoSetStartIoAttributes(
    IN PDEVICE_OBJECT DeviceObject,
    IN BOOLEAN DeferredStartIo,
    IN BOOLEAN NonCancelable
    )
{
}

NTKERNELAPI
NTSTATUS
IoSetSystemPartition(
    PUNICODE_STRING VolumeNameString
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
BOOLEAN
IoSetThreadHardErrorMode(
    IN BOOLEAN EnableHardErrors
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return FALSE;
        default: return TRUE;
    }
}

NTKERNELAPI
USHORT
sdv_IoSizeOfIrp(
    IN CCHAR StackSize
    )
{
    USHORT l = (USHORT) SdvMakeChoice();
    return l;
}

NTKERNELAPI
ULONG
sdv_IoSizeofWorkItem(
    VOID
    )
{
    ULONG l = SdvMakeChoice();
    return l;
}

VOID
sdv_IoSkipCurrentIrpStackLocation(
    IN PIRP pirp
    )
{
    sdv_IoCopyCurrentIrpStackLocationToNext(pirp);
}

NTKERNELAPI
VOID
IoStartNextPacket(
    IN PDEVICE_OBJECT DeviceObject,
    IN BOOLEAN Cancelable
    )
{
}

VOID 
IoStartNextPacketByKey(
    IN PDEVICE_OBJECT DeviceObject,
    IN BOOLEAN Cancelable,
    IN ULONG Key
    )
{
}

NTKERNELAPI
VOID
IoStartPacket(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PULONG Key OPTIONAL,
    IN PDRIVER_CANCEL CancelFunction OPTIONAL
    )
{
}

NTKERNELAPI
VOID
IoStartTimer(
    IN PDEVICE_OBJECT DeviceObject
    )
{
}

NTKERNELAPI
VOID
IoStopTimer(
    IN PDEVICE_OBJECT DeviceObject
    )
{
}

VOID
IoUninitializeWorkItem(
    IN PIO_WORKITEM IoWorkItem
    )
{
}

NTKERNELAPI
NTSTATUS
IoUnregisterPlugPlayNotification(
    IN PVOID NotificationEntry
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
VOID
IoUnregisterShutdownNotification(
    IN PDEVICE_OBJECT DeviceObject
    )
{
}

NTKERNELAPI
VOID
IoUpdateShareAccess(
    IN PFILE_OBJECT FileObject,
    IN OUT PSHARE_ACCESS ShareAccess
    )
{
}

NTSTATUS
IoValidateDeviceIoControlAccess(
    IN PIRP pirp,
    IN ULONG RequiredAccess
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_ACCESS_DENIED;
        default: return STATUS_INVALID_PARAMETER;
    }
}

NTKERNELAPI
NTSTATUS
IoVerifyPartitionTable(
    IN PDEVICE_OBJECT DeviceObject,
    IN BOOLEAN FixErrors
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_DISK_CORRUPT_ERROR;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
NTSTATUS
IoVolumeDeviceToDosName(
    IN PVOID VolumeDeviceObject,
    OUT PUNICODE_STRING DosName
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
NTSTATUS
IoWMIAllocateInstanceIds(
    IN GUID *Guid,
    IN ULONG InstanceCount,
    OUT ULONG *FirstInstanceId
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        default: return STATUS_INSUFFICIENT_RESOURCES;
    }
}

NTKERNELAPI
NTSTATUS
IoWMIDeviceObjectToInstanceName(
    IN PVOID DataBlockObject,
    IN PDEVICE_OBJECT DeviceObject,
    OUT PUNICODE_STRING InstanceName
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        default: return STATUS_WMI_INSTANCE_NOT_FOUND;
    }
}

NTKERNELAPI
ULONG
sdv_IoWMIDeviceObjectToProviderId(
    IN PDEVICE_OBJECT DeviceObject
    )
{
    ULONG l = SdvMakeChoice();
    return l;
}

NTKERNELAPI
NTSTATUS
IoWMIExecuteMethod(
    IN PVOID DataBlockObject,
    IN PUNICODE_STRING InstanceName,
    IN ULONG MethodId,
    IN ULONG InBufferSize,
    IN OUT PULONG OutBufferSize,
    IN OUT PUCHAR InOutBuffer
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_WMI_GUID_NOT_FOUND;
        case 3: return STATUS_WMI_INSTANCE_NOT_FOUND;
        case 4: return STATUS_WMI_ITEMID_NOT_FOUND;
        default: return STATUS_BUFFER_TOO_SMALL;
    }
}

NTKERNELAPI
NTSTATUS
IoWMIHandleToInstanceName(
    IN PVOID DataBlockObject,
    IN HANDLE FileHandle,
    OUT PUNICODE_STRING InstanceName
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        default: return STATUS_WMI_INSTANCE_NOT_FOUND;
    }
}

NTKERNELAPI
NTSTATUS
IoWMIOpenBlock(
    IN GUID *DataBlockGuid,
    IN ULONG DesiredAccess,
    OUT PVOID *DataBlockObject
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
NTSTATUS
IoWMIQueryAllData(
    IN PVOID DataBlockObject,
    IN OUT ULONG *InOutBufferSize,
    OUT PVOID OutBuffer
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_WMI_GUID_NOT_FOUND;
        default: return STATUS_BUFFER_TOO_SMALL;
    }
}

NTKERNELAPI
NTSTATUS
IoWMIQueryAllDataMultiple(
    IN PVOID *DataBlockObjectList,
    IN ULONG ObjectCount,
    IN OUT ULONG *InOutBufferSize,
    OUT PVOID OutBuffer
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        default: return STATUS_BUFFER_TOO_SMALL;
    }
}

NTKERNELAPI
NTSTATUS
IoWMIQuerySingleInstance(
    IN PVOID DataBlockObject,
    IN PUNICODE_STRING InstanceName,
    IN OUT ULONG *InOutBufferSize,
    OUT PVOID OutBuffer
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_WMI_GUID_NOT_FOUND;
        case 3: return STATUS_WMI_INSTANCE_NOT_FOUND;
        default: return STATUS_BUFFER_TOO_SMALL;
    }
}

NTKERNELAPI
NTSTATUS
IoWMIQuerySingleInstanceMultiple(
    IN PVOID *DataBlockObjectList,
    IN PUNICODE_STRING InstanceNames,
    IN ULONG ObjectCount,
    IN OUT ULONG *InOutBufferSize,
    OUT PVOID OutBuffer
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        default: return STATUS_BUFFER_TOO_SMALL;
    }
}

NTKERNELAPI
NTSTATUS
IoWMIRegistrationControl(
    IN PDEVICE_OBJECT DeviceObject,
    IN ULONG Action
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        default: return STATUS_INVALID_PARAMETER;
    }
}

#if WINVER > 0x0500
NTKERNELAPI
NTSTATUS
IoWMISetNotificationCallback(
    IN PVOID Object,
    IN WMI_NOTIFICATION_CALLBACK Callback,
    IN PVOID Context
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}
#endif

#if WINVER > 0x0500
NTKERNELAPI
NTSTATUS
IoWMISetSingleInstance(
    IN PVOID DataBlockObject,
    IN PUNICODE_STRING InstanceName,
    IN ULONG Version,
    IN ULONG ValueBufferSize,
    IN PVOID ValueBuffer
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_WMI_GUID_NOT_FOUND;
        case 3: return STATUS_WMI_INSTANCE_NOT_FOUND;
        case 4: return STATUS_WMI_READ_ONLY;
        default: return STATUS_WMI_SET_FAILURE;
    }
}
#endif

#if WINVER > 0x0500
NTKERNELAPI
NTSTATUS
IoWMISetSingleItem(
    IN PVOID DataBlockObject,
    IN PUNICODE_STRING InstanceName,
    IN ULONG DataItemId,
    IN ULONG Version,
    IN ULONG ValueBufferSize,
    IN PVOID ValueBuffer
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_WMI_GUID_NOT_FOUND;
        case 3: return STATUS_WMI_INSTANCE_NOT_FOUND;
        case 4: return STATUS_WMI_ITEMID_NOT_FOUND;
        case 5: return STATUS_WMI_READ_ONLY;
        default: return STATUS_WMI_SET_FAILURE;
    }
}
#endif

NTKERNELAPI
NTSTATUS
IoWMISuggestInstanceName(
    IN PDEVICE_OBJECT PhysicalDeviceObject OPTIONAL,
    IN PUNICODE_STRING SymbolicLinkName OPTIONAL,
    IN BOOLEAN CombineNames,
    OUT PUNICODE_STRING SuggestedInstanceName
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_INSUFFICIENT_RESOURCES;
        default: return STATUS_NO_MEMORY;
    }
}

NTKERNELAPI
NTSTATUS
IoWMIWriteEvent(
    IN PVOID WnodeEventItem
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_BUFFER_OVERFLOW;
        default: return STATUS_INSUFFICIENT_RESOURCES;
    }
}

NTKERNELAPI
VOID
IoWriteErrorLogEntry(
    IN PVOID ElEntry
    )
{
}




NTKERNELAPI
NTSTATUS
IoAttachDeviceToDeviceStackSafe(
    IN PDEVICE_OBJECT SourceDevice,
    IN PDEVICE_OBJECT TargetDevice,
    IN OUT PDEVICE_OBJECT *AttachedToDeviceObject 
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_NO_SUCH_DEVICE;
    }
}



NTKERNELAPI
NTSTATUS
IoCheckEaBufferValidity(
    IN PFILE_FULL_EA_INFORMATION EaBuffer,
    IN ULONG EaLength,
    OUT PULONG ErrorOffset
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_EA_LIST_INCONSISTENT;
    }
}




NTKERNELAPI
NTSTATUS
IoCheckQuotaBufferValidity(
    IN PFILE_QUOTA_INFORMATION QuotaBuffer,
    IN ULONG QuotaLength,
    OUT PULONG ErrorOffset
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_DATATYPE_MISALIGNMENT;
        default: return STATUS_QUOTA_LIST_INCONSISTENT;
    }
}

NTKERNELAPI
NTSTATUS
IoCreateFileSpecifyDeviceObjectHint(
    OUT PHANDLE FileHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    OUT PIO_STATUS_BLOCK IoStatusBlock,
    IN PLARGE_INTEGER AllocationSize OPTIONAL,
    IN ULONG FileAttributes,
    IN ULONG ShareAccess,
    IN ULONG Disposition,
    IN ULONG CreateOptions,
    IN PVOID EaBuffer OPTIONAL,
    IN ULONG EaLength,
    IN CREATE_FILE_TYPE CreateFileType,
    IN PVOID ExtraCreateParameters OPTIONAL,
    IN ULONG Options,
    IN PVOID DeviceObject
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_INVALID_DEVICE_OBJECT_PARAMETER;
        case 3: return STATUS_MOUNT_POINT_NOT_RESOLVED;
        default: return STATUS_OBJECT_PATH_SYNTAX_BAD;
    }
}




NTKERNELAPI
NTSTATUS
IoEnumerateDeviceObjectList(
    IN PDRIVER_OBJECT DriverObject,
    IN PDEVICE_OBJECT *DeviceObjectList,
    IN ULONG DeviceObjectListSize,
    OUT PULONG ActualNumberDeviceObjects
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_BUFFER_TOO_SMALL;
    }
}

NTKERNELAPI
NTSTATUS
IoEnumerateRegisteredFiltersList(
    IN PDRIVER_OBJECT *DriverObjectList,
    IN ULONG DriverObjectListSize,
    OUT PULONG ActualNumberDriverObjects
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_BUFFER_TOO_SMALL;
    }
}





NTKERNELAPI
NTSTATUS
IoGetDiskDeviceObject(
    IN PDEVICE_OBJECT FileSystemDeviceObject,
    OUT PDEVICE_OBJECT *DeviceObject
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_INVALID_PARAMETER;
        case 1: return STATUS_VOLUME_DISMOUNTED;
        default: return STATUS_SUCCESS;
    }
}




NTKERNELAPI
NTSTATUS
IoGetRequestorSessionId(
    IN PIRP Irp,
    OUT PULONG pSessionId
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}









NTKERNELAPI
NTSTATUS
IoQueryFileDosDeviceName(
    IN PFILE_OBJECT FileObject,
    OUT POBJECT_NAME_INFORMATION *ObjectNameInformation
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        default: return STATUS_INSUFFICIENT_RESOURCES;
    }
}





NTKERNELAPI
NTSTATUS
IoRegisterFsRegistrationChange(
    IN PDRIVER_OBJECT DriverObject,
    IN PDRIVER_FS_NOTIFICATION DriverNotificationRoutine
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_INSUFFICIENT_RESOURCES;
    }
}

NTKERNELAPI
NTSTATUS
IoRegisterFsRegistrationChangeEx(
    IN PDRIVER_OBJECT  DriverObject,
    IN PDRIVER_FS_NOTIFICATION  DriverNotificationRoutine
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_INSUFFICIENT_RESOURCES;
    }
}



NTKERNELAPI
NTSTATUS
IoSetFileOrigin(
    IN PFILE_OBJECT FileObject,
    IN BOOLEAN Remote
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_INVALID_PARAMETER_MIX;
    }
}







NTKERNELAPI
NTSTATUS
IoVerifyVolume(
    IN PDEVICE_OBJECT DeviceObject,
    IN BOOLEAN AllowRawMount
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_INSUFFICIENT_RESOURCES;
        case 2: return STATUS_UNSUCCESSFUL;
        default: return STATUS_WRONG_VOLUME;
    }
}






#if WINVER > 0x0500
NTKERNELAPI
NTSTATUS
IoCreateDisk(
    IN PDEVICE_OBJECT DeviceObject,
    IN PCREATE_DISK Disk
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}
#endif

#if WINVER > 0x0500
NTKERNELAPI
NTSTATUS
IoReadDiskSignature(
    IN PDEVICE_OBJECT DeviceObject,
    IN ULONG BytesPerSector,
    OUT PDISK_SIGNATURE Signature
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        default: return STATUS_DISK_CORRUPT_ERROR;
    }
}
#endif

#if WINVER > 0x0500
DECLSPEC_DEPRECATED_DDK
#endif
NTKERNELAPI
NTSTATUS
#if WINVER > 0x0500
FASTCALL
#endif
IoReadPartitionTable(
    IN PDEVICE_OBJECT DeviceObject,
    IN ULONG SectorSize,
    IN BOOLEAN ReturnRecognizedPartitions,
    OUT struct _DRIVE_LAYOUT_INFORMATION **PartitionBuffer
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
NTSTATUS
IoReadPartitionTableEx(
    IN PDEVICE_OBJECT DeviceObject,
    IN struct _DRIVE_LAYOUT_INFORMATION_EX **PartitionBuffer
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: *PartitionBuffer=&sdv_IoReadPartitionTableEx_DRIVE_LAYOUT_INFORMATION_EX;
                return STATUS_SUCCESS;
        default: *PartitionBuffer=NULL;
                 return STATUS_UNSUCCESSFUL;
    }
}

#if WINVER > 0x0500
DECLSPEC_DEPRECATED_DDK
#endif
NTKERNELAPI
NTSTATUS
#if WINVER > 0x0500
FASTCALL
#endif
IoSetPartitionInformation(
    IN PDEVICE_OBJECT DeviceObject,
    IN ULONG SectorSize,
    IN ULONG PartitionNumber,
    IN ULONG PartitionType
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
NTSTATUS
IoSetPartitionInformationEx(
    IN PDEVICE_OBJECT DeviceObject,
    IN ULONG PartitionNumber,
    IN struct _SET_PARTITION_INFORMATION_EX *PartitionInfo
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

#if WINVER > 0x0500
DECLSPEC_DEPRECATED_DDK
#endif
NTKERNELAPI
NTSTATUS
#if WINVER > 0x0500
FASTCALL
#endif
IoWritePartitionTable(
    IN PDEVICE_OBJECT DeviceObject,
    IN ULONG SectorSize,
    IN ULONG SectorsPerTrack,
    IN ULONG NumberOfHeads,
    IN struct _DRIVE_LAYOUT_INFORMATION *PartitionBuffer
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_DEVICE_NOT_READY;
        default: return STATUS_INSUFFICIENT_RESOURCES;
    }
}

NTKERNELAPI
NTSTATUS
IoWritePartitionTableEx(
    IN PDEVICE_OBJECT DeviceObject,
    IN struct _DRIVE_LAYOUT_INFORMATION_EX *PartitionBuffer
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_DEVICE_NOT_READY;
        default: return STATUS_INSUFFICIENT_RESOURCES;
    }
}


/* ..\wdm\ntddk-io.c end */

/* ..\wdm\ntddk-rtl.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

NTSYSAPI
NTSTATUS
NTAPI
RtlAnsiStringToUnicodeString(
    PUNICODE_STRING DestinationString,
    PANSI_STRING SourceString,
    BOOLEAN AllocateDestinationString
    )
{
    int x = SdvMakeChoice();
    switch (x) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTSYSAPI
VOID
NTAPI
RtlAssert(
    PVOID FailedAssertion,
    PVOID FileName,
    ULONG LineNumber,
    PCHAR Message
    ) 
{
}

NTSYSAPI                                            
NTSTATUS                                            
NTAPI                                               
RtlCharToInteger(                                  
    PCSZ String,                                    
    ULONG Base,                                     
    PULONG Value                                    
    )
{
    NTSTATUS r = SdvMakeChoice();
    return r;
}

NTSYSAPI
NTSTATUS
NTAPI
RtlCheckRegistryKey(
    IN ULONG RelativeTo,
    IN PWSTR Path
    )
{
    NTSTATUS r = SdvMakeChoice();
    return r;
}

NTSYSAPI
SIZE_T
NTAPI
RtlCompareMemory(
    const VOID *Source1,
    const VOID *Source2,
    SIZE_T Length
    )
{
    SIZE_T r = SdvMakeChoice();
    return r;
}

NTSYSAPI
VOID
NTAPI
RtlCopyMemory32(
   VOID UNALIGNED *Destination,
   CONST VOID UNALIGNED *Source,
   ULONG Length
   ) 
{  
}

NTSYSAPI
NTSTATUS
NTAPI
RtlCreateRegistryKey(
    IN ULONG RelativeTo,
    IN PWSTR Path
    )
{
    NTSTATUS r = SdvMakeChoice();
    return r;
}

NTSYSAPI
NTSTATUS
NTAPI
RtlCreateSecurityDescriptor(
    PSECURITY_DESCRIPTOR SecurityDescriptor,
    ULONG Revision
    )
{
    NTSTATUS r = SdvMakeChoice();
    return r;
}

NTSYSAPI
NTSTATUS
NTAPI
RtlDeleteRegistryValue(
    IN ULONG RelativeTo,
    IN PCWSTR Path,
    IN PCWSTR ValueName
    )
{
    int x = SdvMakeChoice();
    switch (x) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTSYSAPI
ULONG
NTAPI
RtlFindLastBackwardRunClear(
    IN PRTL_BITMAP BitMapHeader,
    IN ULONG FromIndex,
    IN PULONG StartingRunIndex
    )
{
    ULONG r = SdvMakeChoice();
    return r;
}

NTSYSAPI
CCHAR
NTAPI
RtlFindLeastSignificantBit(
    IN ULONGLONG Set
    )
{
    CCHAR r = (CCHAR) SdvMakeChoice();
    return r;
}

NTSYSAPI
CCHAR
NTAPI
RtlFindMostSignificantBit(
    IN ULONGLONG Set
    )
{
    CCHAR r = (CCHAR) SdvMakeChoice();
    return r;
}

NTSYSAPI
VOID
NTAPI
RtlFreeAnsiString(
    PANSI_STRING AnsiString
    ) 
{  
}

NTSYSAPI
VOID
NTAPI
RtlFreeUnicodeString(
    PUNICODE_STRING UnicodeString
    ) 
{ 
}

NTSYSAPI
NTSTATUS
RtlGetVersion(
    OUT PRTL_OSVERSIONINFOW lpVersionInformation
    )
{
    NTSTATUS r = SdvMakeChoice();
    return r;
}

NTSYSAPI
NTSTATUS
NTAPI
RtlGUIDFromString(
    IN PUNICODE_STRING GuidString,
    OUT GUID* Guid
    )
{
    NTSTATUS r = SdvMakeChoice();
    return r;
}

NTSYSAPI
VOID
NTAPI
RtlInitAnsiString(
    PANSI_STRING DestinationString,
    PCSZ SourceString
    ) 
{  
}

NTSYSAPI
VOID
NTAPI
RtlInitString(
    PSTRING DestinationString,
    PCSZ SourceString
    ) 
{  
}

NTSYSAPI
VOID
NTAPI
RtlInitUnicodeString(
    IN OUT PUNICODE_STRING DestinationString,
    IN PCWSTR SourceString
    ) 
{  
    /* 
        Disable for RtlInitUnicodeString: C4090: '=' : different
        'const' qualifiers.
      
        This is correctly flagged by the compiler, and would be a serious
        issue if the harness was to be executed rather than simulated.

        However, in this case this is per design in order to simulate
        copy of data:
    */
    #pragma warning(disable:4090)

    if (DestinationString) {
        DestinationString->Buffer = SourceString;

    /* Enable after RtlInitUnicodeString: C4090: */
   #pragma warning(default:4090)

    }
}

NTSYSAPI
NTSTATUS
NTAPI
RtlInt64ToUnicodeString(
    IN ULONGLONG Value,
    IN ULONG Base OPTIONAL,
    IN OUT PUNICODE_STRING String
    )
{
    NTSTATUS r = SdvMakeChoice();
    return r;
}

NTSYSAPI
NTSTATUS
NTAPI
RtlIntegerToUnicodeString(
    ULONG Value,
    ULONG Base,
    PUNICODE_STRING String
    )
{
    NTSTATUS r = SdvMakeChoice();
    return r;
}

NTSYSAPI
ULONG
NTAPI
RtlLengthSecurityDescriptor(
    PSECURITY_DESCRIPTOR SecurityDescriptor
    )
{
    ULONG r = SdvMakeChoice();
    return r;
}

NTSYSAPI
VOID
NTAPI
RtlMapGenericMask(
    PACCESS_MASK AccessMask,
    PGENERIC_MAPPING GenericMapping
    ) 
{  
}

NTSYSAPI
VOID
NTAPI
sdv_RtlMoveMemory(
    VOID UNALIGNED *Destination,
    CONST VOID UNALIGNED *Source,
    SIZE_T Length
    ) 
{
}

NTSYSAPI
NTSTATUS
NTAPI
RtlQueryRegistryValues(
    IN ULONG RelativeTo,
    IN PCWSTR Path,
    IN PRTL_QUERY_REGISTRY_TABLE QueryTable,
    IN PVOID Context,
    IN PVOID Environment OPTIONAL
    )
{
    int x = SdvMakeChoice();
    switch (x) {
        case 0: return STATUS_SUCCESS;
#ifdef SLAM_PRECISE_STATUS
        case 1: return STATUS_INVALID_PARAMETER;
        case 2: return STATUS_OBJECT_NAME_NOT_FOUND;
#endif
        default: return STATUS_UNSUCCESSFUL;
  }
}

NTSYSAPI
NTSTATUS
NTAPI
RtlSetDaclSecurityDescriptor(
    PSECURITY_DESCRIPTOR SecurityDescriptor,
    BOOLEAN DaclPresent,
    PACL Dacl,
    BOOLEAN DaclDefaulted
    )
{
    NTSTATUS r = SdvMakeChoice();
    return r;
}

NTSYSAPI
NTSTATUS
NTAPI
RtlStringFromGUID(
    IN REFGUID Guid,
    OUT PUNICODE_STRING GuidString
    )
{
    NTSTATUS r = SdvMakeChoice();
    SdvAssume(r != STATUS_PENDING);
    return r;
}

ULONG
FASTCALL
RtlU_longByteSwap(
    IN ULONG Source
    )
{
    ULONG r = SdvMakeChoice();
    return r;
}

ULONGLONG
FASTCALL
RtlU_longlongByteSwap(
    IN ULONGLONG Source
    )
{
    ULONGLONG r = SdvMakeChoice();
    return r;
}

USHORT
FASTCALL
RtlU_shortByteSwap(
    IN USHORT Source
    )
{
    USHORT r = (USHORT) SdvMakeChoice();
    return r;
}

NTSYSAPI
CHAR
NTAPI
RtlUpperChar(
    CHAR Character
    )
{
    CHAR r = (CHAR) SdvMakeChoice();
    return r;
}

NTSYSAPI
BOOLEAN
NTAPI
RtlValidRelativeSecurityDescriptor(
    IN PSECURITY_DESCRIPTOR SecurityDescriptorInput,
    IN ULONG SecurityDescriptorLength,
    IN SECURITY_INFORMATION RequiredInformation
    )
{
    BOOLEAN b = (BOOLEAN) SdvMakeChoice();
    return b;
}

NTSYSAPI
BOOLEAN
NTAPI
RtlValidSecurityDescriptor(
    PSECURITY_DESCRIPTOR SecurityDescriptor
    )
{
    BOOLEAN b = (BOOLEAN) SdvMakeChoice();
    return b;
}

NTSYSAPI
NTSTATUS
RtlVerifyVersionInfo(
    IN PRTL_OSVERSIONINFOEXW VersionInfo,
    IN ULONG TypeMask,
    IN ULONGLONG  ConditionMask
    )
{
    NTSTATUS r = SdvMakeChoice();
    return r;
}

NTSYSAPI
NTSTATUS
NTAPI
RtlVolumeDeviceToDosName(
    IN  PVOID           VolumeDeviceObject,
    OUT PUNICODE_STRING DosName
    )
{
    NTSTATUS r = SdvMakeChoice();
    return r;
}

NTSYSAPI
ULONG
NTAPI
RtlWalkFrameChain(
    OUT PVOID *Callers,
    IN ULONG Count,
    IN ULONG Flags
    ) 
{ 
    ULONG r = SdvMakeChoice(); 
    return r; 
}

NTSYSAPI
NTSTATUS
NTAPI
RtlWriteRegistryValue(
    IN ULONG RelativeTo,
    IN PCWSTR Path,
    IN PCWSTR ValueName,
    IN ULONG ValueType,
    IN PVOID ValueData,
    IN ULONG ValueLength
    )
{
    NTSTATUS r = SdvMakeChoice();
    return r;
}

NTSYSAPI
VOID
NTAPI
sdv_RtlZeroMemory(
    VOID UNALIGNED *Destination,
    SIZE_T Length
    ) 
{
}
/* ..\wdm\ntddk-rtl.c end */

/* ..\wdm\ntddk-zw.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/



int sdv_ZwCreateKey_1;
int sdv_ZwCreateKey_2;
static int sdv_ZwCreateKey_count = 0;

int sdv_ZwOpenKey_1;
int sdv_ZwOpenKey_2;
static int sdv_ZwOpenKey_count = 0;




NTSTATUS
ZwCancelTimer(
    IN HANDLE TimerHandle,
    OUT PBOOLEAN CurrentState OPTIONAL
    )
{
    NTSTATUS r = SdvMakeChoice();
    SdvAssume(r != STATUS_PENDING);
    return r;
}

NTSYSAPI
NTSTATUS
NTAPI
ZwClose(
    IN HANDLE Handle
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_INVALID_HANDLE;
        default: return STATUS_HANDLE_NOT_CLOSABLE;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwCreateDirectoryObject(
    OUT PHANDLE DirectoryHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_ACCESS_DENIED;
        case 3: return STATUS_ACCESS_VIOLATION;
        default: return STATUS_DATATYPE_MISALIGNMENT;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwCreateFile(
    OUT PHANDLE FileHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    OUT PIO_STATUS_BLOCK IoStatusBlock,
    IN PLARGE_INTEGER AllocationSize OPTIONAL,
    IN ULONG FileAttributes,
    IN ULONG ShareAccess,
    IN ULONG CreateDisposition,
    IN ULONG CreateOptions,
    IN PVOID EaBuffer OPTIONAL,
    IN ULONG EaLength
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwCreateKey(
    OUT PHANDLE KeyHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    IN ULONG TitleIndex,
    IN PUNICODE_STRING Class OPTIONAL,
    IN ULONG CreateOptions,
    OUT PULONG Disposition OPTIONAL
    )
{
    NTSTATUS r = SdvMakeChoice();
    if (NT_SUCCESS(r)) {
        SdvAssume(NT_SUCCESS(r));
        switch (sdv_ZwCreateKey_count) {
        case 0:
            SdvAssume(sdv_ZwCreateKey_count == 0);
            sdv_ZwCreateKey_count++;
            *KeyHandle = (HANDLE) &sdv_ZwCreateKey_1;
            break;
        default:
            SdvAssume(sdv_ZwCreateKey_count != 0);
            *KeyHandle = (HANDLE) &sdv_ZwCreateKey_2;
        }
    } else {
        SdvAssume(!NT_SUCCESS(r));
        SdvAssume(r != STATUS_PENDING);
    }
    return r;
}

NTKERNELAPI
NTSTATUS
ZwCreateSection(
    OUT PHANDLE SectionHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
    IN PLARGE_INTEGER MaximumSize OPTIONAL,
    IN ULONG SectionPageProtection,
    IN ULONG AllocationAttributes,
    IN HANDLE FileHandle OPTIONAL
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_FILE_LOCK_CONFLICT;
        case 3: return STATUS_INVALID_FILE_FOR_SECTION;
        case 4: return STATUS_INVALID_PAGE_PROTECTION;
        case 5: return STATUS_MAPPED_FILE_SIZE_ZERO;
        default: return STATUS_SECTION_TOO_BIG;
    }
}

NTSTATUS
ZwCreateTimer(
    OUT PHANDLE TimerHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
    IN TIMER_TYPE TimerType
    )
{
    NTSTATUS r = SdvMakeChoice();
    SdvAssume(r != STATUS_PENDING);
    return r;
}

NTSYSAPI
NTSTATUS
NTAPI
ZwDeleteKey(
    IN HANDLE KeyHandle
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_ACCESS_DENIED;
        default: return STATUS_INVALID_HANDLE;
    }
}

NTKERNELAPI
NTSTATUS
ZwDeleteValueKey(
    IN HANDLE KeyHandle,
    IN PUNICODE_STRING ValueName
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwEnumerateKey(
    IN HANDLE KeyHandle,
    IN ULONG Index,
    IN KEY_INFORMATION_CLASS KeyInformationClass,
    OUT PVOID KeyInformation,
    IN ULONG Length,
    OUT PULONG ResultLength
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_BUFFER_OVERFLOW;
        case 3: return STATUS_BUFFER_TOO_SMALL;
        case 4: return STATUS_INVALID_PARAMETER;
        default: return STATUS_NO_MORE_ENTRIES;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwEnumerateValueKey(
    IN HANDLE KeyHandle,
    IN ULONG Index,
    IN KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
    OUT PVOID KeyValueInformation,
    IN ULONG Length,
    OUT PULONG ResultLength
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_BUFFER_OVERFLOW;
        case 3: return STATUS_BUFFER_TOO_SMALL;
        case 4: return STATUS_INVALID_PARAMETER;
        default: return STATUS_NO_MORE_ENTRIES;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwFlushKey(
    IN HANDLE KeyHandle
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwMakeTemporaryObject(
    IN HANDLE Handle
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwMapViewOfSection(
    IN HANDLE SectionHandle,
    IN HANDLE ProcessHandle,
    IN OUT PVOID *BaseAddress,
    IN ULONG_PTR ZeroBits,
    IN SIZE_T CommitSize,
    IN OUT PLARGE_INTEGER SectionOffset OPTIONAL,
    IN OUT PSIZE_T ViewSize,
    IN SECTION_INHERIT InheritDisposition,
    IN ULONG AllocationType,
    IN ULONG Win32Protect
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_CONFLICTING_ADDRESSES;
        case 3: return STATUS_INVALID_PAGE_PROTECTION;
        default: return STATUS_SECTION_PROTECTION;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwOpenFile(
    OUT PHANDLE FileHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    OUT PIO_STATUS_BLOCK IoStatusBlock,
    IN ULONG ShareAccess,
    IN ULONG OpenOptions
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwOpenKey(
    OUT PHANDLE KeyHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes
    )
{
    NTSTATUS r = SdvMakeChoice();
    if (NT_SUCCESS(r)) {
        SdvAssume(NT_SUCCESS(r));
        switch (sdv_ZwOpenKey_count) {
        case 0:
            SdvAssume(sdv_ZwOpenKey_count == 0);
            sdv_ZwOpenKey_count++;
            *KeyHandle = (HANDLE) &sdv_ZwOpenKey_1;
            break;
        default: 
            SdvAssume(sdv_ZwOpenKey_count != 0);
            *KeyHandle = (HANDLE) &sdv_ZwOpenKey_2;
        } 
    } else {
        SdvAssume(!NT_SUCCESS(r));
        SdvAssume(r != STATUS_PENDING);
    }
    return r;
}

NTSYSAPI
NTSTATUS
NTAPI
ZwOpenSection(
    OUT PHANDLE SectionHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_ACCESS_DENIED;
        default: return STATUS_INVALID_HANDLE;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwOpenSymbolicLinkObject(
    OUT PHANDLE LinkHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTSTATUS
ZwOpenTimer(
    OUT PHANDLE TimerHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes
    )
{
    NTSTATUS r = SdvMakeChoice();
    SdvAssume(r != STATUS_PENDING);
    return r;
}

NTSYSAPI
NTSTATUS
NTAPI
ZwQueryInformationFile(
    IN HANDLE FileHandle,
    OUT PIO_STATUS_BLOCK IoStatusBlock,
    OUT PVOID FileInformation,
    IN ULONG Length,
    IN FILE_INFORMATION_CLASS FileInformationClass
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwQueryKey(
    IN HANDLE KeyHandle,
    IN KEY_INFORMATION_CLASS KeyInformationClass,
    OUT PVOID KeyInformation,
    IN ULONG Length,
    OUT PULONG ResultLength
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_BUFFER_OVERFLOW;
        case 3: return STATUS_BUFFER_TOO_SMALL;
        default: return STATUS_INVALID_PARAMETER;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwQuerySymbolicLinkObject(
    IN HANDLE LinkHandle,
    IN OUT PUNICODE_STRING LinkTarget,
    OUT PULONG ReturnedLength OPTIONAL
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_BUFFER_TOO_SMALL;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwQueryValueKey(
    IN HANDLE KeyHandle,
    IN PUNICODE_STRING ValueName,
    IN KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
    OUT PVOID KeyValueInformation,
    IN ULONG Length,
    OUT PULONG ResultLength
    )
{
    /* 
      This model for ZwQueryValueKey has a custom body that supports a
      common pattern in drivers: To initially call ZwQueryValueKey
      with Length==0 in order to determine a ResultLenght x, then
      allocate this amount x of memory and thereafter make a
      subsequent call to ZwQueryValueKey with new Length==x.  In the
      first case the driver can assume that STATUS_SUCCESS is not
      returned.
    */
    int choice = SdvMakeChoice();

    if(Length!=0) {
        switch (choice) {
            case 0: return STATUS_SUCCESS;
            case 1: return STATUS_UNSUCCESSFUL;
            case 2: return STATUS_BUFFER_OVERFLOW;
            case 3: return STATUS_BUFFER_TOO_SMALL;
            default: return STATUS_INVALID_PARAMETER;
        }
    }
    else {
        switch (choice) {
            case 0: return STATUS_UNSUCCESSFUL;
            case 1: return STATUS_BUFFER_OVERFLOW;
            case 2: return STATUS_BUFFER_TOO_SMALL;
            default: return STATUS_INVALID_PARAMETER;
        }
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwReadFile(
    IN HANDLE FileHandle,
    IN HANDLE Event OPTIONAL,
    IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
    IN PVOID ApcContext OPTIONAL,
    OUT PIO_STATUS_BLOCK IoStatusBlock,
    OUT PVOID Buffer,
    IN ULONG Length,
    IN PLARGE_INTEGER ByteOffset OPTIONAL,
    IN PULONG Key OPTIONAL
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwSetInformationFile(
    IN HANDLE FileHandle,
    OUT PIO_STATUS_BLOCK IoStatusBlock,
    IN PVOID FileInformation,
    IN ULONG Length,
    IN FILE_INFORMATION_CLASS FileInformationClass
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwSetInformationThread(
    IN HANDLE ThreadHandle,
    IN THREADINFOCLASS ThreadInformationClass,
    IN PVOID ThreadInformation,
    IN ULONG ThreadInformationLength
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_INFO_LENGTH_MISMATCH;
        default: return STATUS_INVALID_PARAMETER;
    }
}

NTSTATUS
ZwSetTimer(
    IN HANDLE TimerHandle,
    IN PLARGE_INTEGER DueTime,
    IN PTIMER_APC_ROUTINE TimerApcRoutine OPTIONAL,
    IN PVOID TimerContext OPTIONAL,
    IN BOOLEAN WakeTimer,
    IN LONG Period OPTIONAL,
    OUT PBOOLEAN PreviousState OPTIONAL
    )
{
    NTSTATUS r = SdvMakeChoice();
    SdvAssume(r != STATUS_PENDING);
    return r;
}

NTSYSAPI
NTSTATUS
NTAPI
ZwSetValueKey(
    IN HANDLE KeyHandle,
    IN PUNICODE_STRING ValueName,
    IN ULONG TitleIndex OPTIONAL,
    IN ULONG Type,
    IN PVOID Data,
    IN ULONG DataSize
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        case 2: return STATUS_ACCESS_DENIED;
        default: return STATUS_INVALID_HANDLE;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwUnmapViewOfSection(
    IN HANDLE ProcessHandle,
    IN PVOID BaseAddress
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        case 1: return STATUS_UNSUCCESSFUL;
        default: return STATUS_INVALID_PARAMETER;
    }
}

NTSYSAPI
NTSTATUS
NTAPI
ZwWriteFile(
    IN HANDLE FileHandle,
    IN HANDLE Event OPTIONAL,
    IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
    IN PVOID ApcContext OPTIONAL,
    OUT PIO_STATUS_BLOCK IoStatusBlock,
    IN PVOID Buffer,
    IN ULONG Length,
    IN PLARGE_INTEGER ByteOffset OPTIONAL,
    IN PULONG Key OPTIONAL
    )
{
    int choice = SdvMakeChoice();
    switch (choice) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}


/* ..\wdm\ntddk-zw.c end */

/* ..\wdm\ntddk-ke.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

#if WINVER > 0x0500
_DECL_HAL_KE_IMPORT
VOID
FASTCALL
KeAcquireInStackQueuedSpinLock(
    IN PKSPIN_LOCK SpinLock,
    IN PKLOCK_QUEUE_HANDLE LockHandle
    ) 
{
    SDV_IRQL_PUSH(DISPATCH_LEVEL);
}
#endif

#if WINVER > 0x0500
NTKERNELAPI
VOID
FASTCALL
KeAcquireInStackQueuedSpinLockAtDpcLevel(
    IN PKSPIN_LOCK SpinLock,
    IN PKLOCK_QUEUE_HANDLE LockHandle
    ) 
{
}
#endif

#if WINVER > 0x0500
NTKERNELAPI
VOID
FASTCALL
KeAcquireInStackQueuedSpinLockForDpc(
    IN PKSPIN_LOCK SpinLock,
    IN PKLOCK_QUEUE_HANDLE LockHandle
    ) 
{
    SDV_IRQL_PUSH(DISPATCH_LEVEL);
}
#endif

KIRQL
KeAcquireInterruptSpinLock(
    IN PKINTERRUPT Interrupt
    )
{
    SDV_IRQL_PUSH(SDV_DIRQL);
    return sdv_irql_previous;
}

VOID
sdv_KeAcquireSpinLock(
    IN PKSPIN_LOCK SpinLock,
    OUT PKIRQL p_old_irql
    ) 
{
    SDV_IRQL_PUSH(DISPATCH_LEVEL);
    (*p_old_irql) = sdv_irql_previous;
}

VOID
sdv_KeAcquireSpinLockAtDpcLevel(
    IN PKSPIN_LOCK  SpinLock
    ) 
{
}

NTKERNELAPI
KIRQL
KeAcquireSpinLockRaiseToDpc(
    IN PKSPIN_LOCK SpinLock
    ) 
{ 
    SDV_IRQL_PUSH(DISPATCH_LEVEL);
    return sdv_irql_previous;
}

NTKERNELAPI
DECLSPEC_NORETURN
VOID
NTAPI
KeBugCheck (
    __in ULONG BugCheckCode
    )
{
    /* Simulate bug check by stopping verification: */
    SdvExit();
}

NTKERNELAPI
DECLSPEC_NORETURN
VOID
NTAPI
KeBugCheckEx(
    __in ULONG BugCheckCode,
    __in ULONG_PTR BugCheckParameter1,
    __in ULONG_PTR BugCheckParameter2,
    __in ULONG_PTR BugCheckParameter3,
    __in ULONG_PTR BugCheckParameter4
    )
{
    /* Simulate bug check by stopping verification: */
    SdvExit();
}

NTKERNELAPI
VOID
KeClearEvent(
    IN PRKEVENT Event
    ) 
{
}

NTKERNELAPI                                         
NTSTATUS                                            
KeDelayExecutionThread(                            
    IN KPROCESSOR_MODE WaitMode,                    
    IN BOOLEAN Alertable,                           
    IN PLARGE_INTEGER Interval                      
    )
{
    int x = SdvMakeChoice();
    switch (x) {
        case 0: return STATUS_SUCCESS;
#ifdef SLAM_PRECISE_STATUS
        case 1: return STATUS_ALERTED;
        default: return STATUS_USER_APC;
#else
        default: return STATUS_UNSUCCESSFUL;
#endif
  }
}

NTKERNELAPI
VOID
sdv_KeEnterCriticalRegion(
    VOID
    )
{
}

NTKERNELAPI
VOID
sdv_KeFlushIoBuffers(
    IN PMDL Mdl,
    IN BOOLEAN ReadOperation,
    IN BOOLEAN DmaOperation
    )
{
}

NTHALAPI
KIRQL
NTAPI
sdv_KeGetCurrentIrql() 
{
    return sdv_irql_current;
}

NTKERNELAPI
VOID
KeInitializeDpc(
    IN PRKDPC Dpc,
    IN PKDEFERRED_ROUTINE DeferredRoutine,
    IN PVOID DeferredContext
    ) 
{ 
    sdv_dpc = DeferredRoutine;
}

NTKERNELAPI
VOID
KeInitializeEvent(
    IN PRKEVENT Event,
    IN EVENT_TYPE Type,
    IN BOOLEAN State
    )
{ 
}

NTKERNELAPI
BOOLEAN
KeInsertByKeyDeviceQueue(
    IN PKDEVICE_QUEUE DeviceQueue,
    IN PKDEVICE_QUEUE_ENTRY DeviceQueueEntry,
    IN ULONG SortKey
    )
{
    BOOLEAN b = (BOOLEAN) SdvMakeChoice();
    return b;
}

NTKERNELAPI
BOOLEAN
KeInsertDeviceQueue(
    IN PKDEVICE_QUEUE DeviceQueue,
    IN PKDEVICE_QUEUE_ENTRY DeviceQueueEntry
    )
{
    BOOLEAN b = (BOOLEAN) SdvMakeChoice();
    return b;
}

NTKERNELAPI
BOOLEAN
KeInsertQueueDpc(
    IN PRKDPC Dpc,
    IN PVOID SystemArgument1,
    IN PVOID SystemArgument2
    )
{
    BOOLEAN b = (BOOLEAN) SdvMakeChoice();
    return b;
}
NTKERNELAPI
VOID
sdv_KeLeaveCriticalRegion(
    VOID
    )
{
}

VOID
sdv_KeLowerIrql(
    IN KIRQL new_irql
    ) 
{  
    SDV_IRQL_POPTO(new_irql);
}

NTKERNELAPI
LONG
KePulseEvent(
    IN PRKEVENT Event,
    IN KPRIORITY Increment,
    IN BOOLEAN Wait
    )
{
    LONG l = SdvMakeChoice();
    return l;
}

VOID
sdv_KeRaiseIrql(
    IN KIRQL new_irql,
    OUT PKIRQL p_old_irql
    ) 
{  
    SDV_IRQL_PUSH(new_irql);
    *p_old_irql = sdv_irql_previous;
}

KIRQL
KeRaiseIrqlToDpcLevel(
    VOID
    ) 
{ 
    SDV_IRQL_PUSH(DISPATCH_LEVEL);
    return sdv_irql_previous;
}

KIRQL
sdv_KeRaiseIrqlToSynchLevel(
    VOID
    ) 
{ 
    KIRQL r = (KIRQL) SdvMakeChoice(); 
    return r; 
}

NTKERNELAPI
LONG
KeReadStateEvent(
    IN PRKEVENT Event
    )
{
    LONG l = SdvMakeChoice();
    return l;
}

#if WINVER > 0x0500
_DECL_HAL_KE_IMPORT
VOID
FASTCALL
KeReleaseInStackQueuedSpinLock(
    IN PKLOCK_QUEUE_HANDLE LockHandle
    ) 
{
    SDV_IRQL_POP();
}
#endif

#if WINVER > 0x0500
NTKERNELAPI
VOID
FASTCALL
KeReleaseInStackQueuedSpinLockForDpc(
    IN PKLOCK_QUEUE_HANDLE LockHandle
    ) 
{
    SDV_IRQL_POP();
}
#endif

#if WINVER > 0x0500
NTKERNELAPI
VOID
FASTCALL
KeReleaseInStackQueuedSpinLockFromDpcLevel(
    IN PKLOCK_QUEUE_HANDLE LockHandle
    ) 
{
}
#endif

VOID
KeReleaseInterruptSpinLock(
    IN PKINTERRUPT Interrupt,
    IN KIRQL old_irql
    )
{
    SDV_IRQL_POPTO(old_irql);
}

NTKERNELAPI
LONG
KeReleaseSemaphore(
    IN PRKSEMAPHORE Semaphore,
    IN KPRIORITY Increment,
    IN LONG Adjustment,
    IN BOOLEAN Wait
    ) 
{
    LONG r = SdvMakeChoice(); 
    return r;
}

VOID
sdv_KeReleaseSpinLock(
    IN PKSPIN_LOCK  SpinLock,
    IN KIRQL  new_irql
    ) 
{
    SDV_IRQL_POPTO(new_irql);
}

VOID
sdv_KeReleaseSpinLockFromDpcLevel(
    IN PKSPIN_LOCK  SpinLock
    ) 
{
}

NTKERNELAPI
LONG
KeResetEvent(
    IN PRKEVENT Event
    ) 
{
    LONG l = SdvMakeChoice();
    return l;
}

NTKERNELAPI
LONG
KeSetEvent(
    IN PRKEVENT Event,
    IN KPRIORITY Increment,
    IN BOOLEAN Wait
    ) 
{
    LONG r = SdvMakeChoice(); 
    return r;
}

BOOLEAN
KeSynchronizeExecution(
    IN PKINTERRUPT Interrupt,
    IN PKSYNCHRONIZE_ROUTINE SynchronizeRoutine,
    IN PVOID SynchronizeContext
    )
{
    BOOLEAN b;

    /* SynchronizeRoutine must be non-null.  Check anyhow. */
    if ( SynchronizeRoutine == NULL )
    {
        return FALSE;
    }

    SDV_IRQL_PUSH(SDV_DIRQL);
    b = SynchronizeRoutine( SynchronizeContext );
    SDV_IRQL_POP();
    return b;
}

NTKERNELAPI
NTSTATUS
KeWaitForMultipleObjects(
    IN ULONG Count,
    IN PVOID Object[],
    IN WAIT_TYPE WaitType,
    IN KWAIT_REASON WaitReason,
    IN KPROCESSOR_MODE WaitMode,
    IN BOOLEAN Alertable,
    IN PLARGE_INTEGER Timeout OPTIONAL,
    IN PKWAIT_BLOCK WaitBlockArray OPTIONAL
    )  
{
    int x = SdvMakeChoice();
      
    switch (x) { 
        case 0: return STATUS_SUCCESS;
#ifdef SLAM_PRECISE_STATUS
        case 1: return STATUS_ALERTED;
        case 2: return STATUS_USER_APC;
        default: return STATUS_TIMEOUT;
#else
        default: return STATUS_UNSUCCESSFUL;
#endif
    }
}

NTKERNELAPI
NTSTATUS
KeWaitForMutexObject(
    IN PRKMUTEX Mutex,
    IN KWAIT_REASON WaitReason,
    IN KPROCESSOR_MODE WaitMode,
    IN BOOLEAN Alertable,
    IN PLARGE_INTEGER Timeout OPTIONAL
    )
{

    int x = SdvMakeChoice();

    switch (x) {
        case 0: return STATUS_SUCCESS;
#ifdef SLAM_PRECISE_STATUS
        case 1: return STATUS_ALERTED;
        case 2: return STATUS_USER_APC;
        default: return STATUS_TIMEOUT;
#else
        default: return STATUS_UNSUCCESSFUL;
#endif
    }
}

NTKERNELAPI
NTSTATUS
KeWaitForSingleObject(
    IN PVOID Object,
    IN KWAIT_REASON WaitReason,
    IN KPROCESSOR_MODE WaitMode,
    IN BOOLEAN Alertable,
    IN PLARGE_INTEGER Timeout OPTIONAL
    )
{

    int x = SdvMakeChoice();

    switch (x) {
        case 0: return STATUS_SUCCESS;
#ifdef SLAM_PRECISE_STATUS
        case 1: return STATUS_ALERTED;
        case 2: return STATUS_USER_APC;
        default: return STATUS_TIMEOUT;
#else
        default: return STATUS_UNSUCCESSFUL;
#endif
    }
}




/* ..\wdm\ntddk-ke.c end */

/* ..\wdm\ntddk-mm.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

NTKERNELAPI
PVOID
MmAllocateContiguousMemory(
    IN SIZE_T NumberOfBytes,
    IN PHYSICAL_ADDRESS HighestAcceptableAddress
    ) 
{
    int x = SdvMakeChoice();
    switch (x) {
        case 0: return malloc(0);
        default: return NULL;
    }
}

ULONG
sdv_MmGetMdlByteCount(
    IN PMDL Mdl
     )
{
    ULONG x = ((ULONG)SdvMakeChoice());
    return  x;
}

ULONG
sdv_MmGetMdlByteOffset (
    IN PMDL Mdl
    )
{
    ULONG x = ((ULONG)SdvMakeChoice());
    return x;
}


PPFN_NUMBER
sdv_MmGetMdlPfnArray(
    IN PMDL Mdl
    )
{
    PPFN_NUMBER x = ((PPFN_NUMBER)((ULONG_PTR)SdvMakeChoice()));
    return x;
}


PVOID
sdv_MmGetMdlVirtualAddress(
    IN PMDL Mdl
     )
{
    PVOID x = ((PVOID)((ULONG_PTR) SdvMakeChoice()));
	return x;
}

PVOID
sdv_MmGetSystemAddressForMdlSafe(
     IN PMDL MDL,
     IN MM_PAGE_PRIORITY PRIORITY
     ) 
{
    PVOID p = ((PVOID)((ULONG_PTR) SdvMakeChoice()));
    return p;
}
PVOID
sdv_MmLockPagableCodeSection(
    IN PVOID  AddressWithinSection
    ) 
{
    return(AddressWithinSection);
}

NTKERNELAPI
VOID
MmLockPagableSectionByHandle(
    IN PVOID ImageSectionHandle
    )
{
}

int sdv_MmMapIoSpace_int=0;  

NTKERNELAPI
PVOID
MmMapIoSpace(
    IN PHYSICAL_ADDRESS PhysicalAddress,
    IN SIZE_T NumberOfBytes,
    IN MEMORY_CACHING_TYPE CacheType
    )
{
    return (PVOID) &sdv_MmMapIoSpace_int;
}

NTKERNELAPI
PVOID
MmMapLockedPages(
    IN PMDL MemoryDescriptorList,
    IN KPROCESSOR_MODE AccessMode
    ) 
{
    PVOID r = ((PVOID)((ULONG_PTR) SdvMakeChoice()));
    return r;
}

NTKERNELAPI
PVOID
MmMapLockedPagesSpecifyCache(
     IN PMDL MemoryDescriptorList,
     IN KPROCESSOR_MODE AccessMode,
     IN MEMORY_CACHING_TYPE CacheType,
     IN PVOID BaseAddress,
     IN ULONG BugCheckOnFailure,
     IN MM_PAGE_PRIORITY Priority
     ) 
{
    PVOID r = ((PVOID)((ULONG_PTR) SdvMakeChoice()));
    return r;
}


NTKERNELAPI
PVOID
MmPageEntireDriver(
    IN PVOID AddressWithinSection
    )
{
    PVOID p = ((PVOID)((ULONG_PTR) SdvMakeChoice()));
    return p;
}

VOID
sdv_MmPrepareMdlForReuse(
    IN PMDL Mdl
    )
{
}

NTKERNELAPI
VOID
MmResetDriverPaging(
    IN PVOID AddressWithinSection
    )
{
}

NTKERNELAPI
VOID
MmUnlockPagableImageSection(
    IN PVOID ImageSectionHandle
    )
{
}
/* ..\wdm\ntddk-mm.c end */

/* ..\wdm\ntddk-ex.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

NTKERNELAPI
VOID
FASTCALL
sdv_ExAcquireFastMutex(
    IN PFAST_MUTEX FastMutex
    ) 
{  
    SDV_IRQL_PUSH(APC_LEVEL);
}

NTKERNELAPI
VOID
FASTCALL
ExAcquireFastMutexUnsafe(
    IN PFAST_MUTEX  FastMutex
    ) 
{
}

NTKERNELAPI
BOOLEAN
ExAcquireResourceExclusiveLite(
    IN PERESOURCE Resource,
    IN BOOLEAN Wait
    ) 
{ 
    if (Wait) { return TRUE; }
    else {
        BOOLEAN b = (BOOLEAN) SdvMakeChoice();
        return b;
    };
}

NTKERNELAPI
BOOLEAN
ExAcquireResourceSharedLite(
    IN PERESOURCE Resource,
    IN BOOLEAN Wait
    ) 
{
    if (Wait) { return TRUE; }
    else {
        BOOLEAN b = (BOOLEAN) SdvMakeChoice();
        return b;
    };
}

NTKERNELAPI
BOOLEAN
ExAcquireSharedStarveExclusive(
    IN PERESOURCE Resource,
    IN BOOLEAN Wait
    ) 
{ 
    if (Wait) { return TRUE; }
    else {
        BOOLEAN b = (BOOLEAN) SdvMakeChoice();
        return b;
    };
}

NTKERNELAPI
BOOLEAN
ExAcquireSharedWaitForExclusive(
    IN PERESOURCE Resource,
    IN BOOLEAN Wait
    ) 
{ 
    if (Wait) { return TRUE; }
    else {
        BOOLEAN b = (BOOLEAN) SdvMakeChoice();
        return b;
    };
}

NTKERNELAPI
PVOID
sdv_ExAllocatePool(
    IN POOL_TYPE PoolType,
    IN SIZE_T NumberOfBytes
    ) 
{ 
    return malloc(0);
}

NTKERNELAPI
PVOID
sdv_ExAllocatePoolWithQuota(
    IN POOL_TYPE PoolType,
    IN SIZE_T NumberOfBytes
    )
{
    return malloc(0);
}

NTKERNELAPI
PVOID
sdv_ExAllocatePoolWithQuotaTag(
    IN POOL_TYPE PoolType,
    IN SIZE_T NumberOfBytes,
    IN ULONG Tag
    )
{
    return malloc(0);
}

NTKERNELAPI
PVOID
NTAPI
ExAllocatePoolWithTag(
    IN POOL_TYPE PoolType,
    IN SIZE_T NumberOfBytes,
    IN ULONG Tag
    ) 
{
    return malloc(0);
}

NTKERNELAPI
PVOID
NTAPI
ExAllocatePoolWithTagPriority(
    IN POOL_TYPE PoolType,
    IN SIZE_T NumberOfBytes,
    IN ULONG Tag,
    IN EX_POOL_PRIORITY Priority
    )
{
    return malloc(0);
}

NTKERNELAPI
NTSTATUS
ExCreateCallback(
    OUT PCALLBACK_OBJECT *CallbackObject,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    IN BOOLEAN Create,
    IN BOOLEAN AllowMultipleCallbacks
    ) 
{ 
    int x = SdvMakeChoice();
    switch (x) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
NTSTATUS
ExDeleteResourceLite(
    IN PERESOURCE Resource
    ) 
{ 
    int x = SdvMakeChoice();
    if (x) {
        return STATUS_SUCCESS;
    } else {
        return STATUS_UNSUCCESSFUL;
    }
}

NTKERNELAPI
VOID
NTAPI
sdv_ExFreePool(
    IN PVOID P
    ) 
{
}

VOID
sdv_ExInitializeFastMutex(
    IN PFAST_MUTEX FastMutex
    )
{
}

NTKERNELAPI
NTSTATUS
ExInitializeResourceLite(
    IN PERESOURCE Resource
    ) 
{ 
    return STATUS_SUCCESS; 
}

NTKERNELAPI
PLIST_ENTRY
FASTCALL
sdv_ExInterlockedInsertHeadList(
    IN PLIST_ENTRY ListHead,
    IN PLIST_ENTRY ListEntry,
    IN PKSPIN_LOCK Lock
    ) 
{
    PVOID p = ((PVOID)((ULONG_PTR) SdvMakeChoice()));
    return p;
}

NTKERNELAPI
PLIST_ENTRY
FASTCALL
sdv_ExInterlockedInsertTailList(
    IN PLIST_ENTRY ListTail,
    IN PLIST_ENTRY ListEntry,
    IN PKSPIN_LOCK Lock
    ) 
{
    PVOID p = ((PVOID)((ULONG_PTR) SdvMakeChoice()));
    return p;
}

NTKERNELAPI
PSINGLE_LIST_ENTRY
FASTCALL
sdv_ExInterlockedPushEntryList(
    IN PSINGLE_LIST_ENTRY ListHead,
    IN PSINGLE_LIST_ENTRY ListEntry,
    IN PKSPIN_LOCK Lock
    )
{
    PVOID p = ((PVOID)((ULONG_PTR) SdvMakeChoice()));
    return p;
}

NTKERNELAPI
DECLSPEC_NORETURN
VOID
ExRaiseAccessViolation (
    VOID
    )
{
    /* As SDV does not support SEH: Stop verification: */
    /* This is unsound but is useful for suppressing false defects */ 
    SdvExit();
}

NTKERNELAPI
DECLSPEC_NORETURN
VOID
ExRaiseDatatypeMisalignment (
    VOID
    )
{
    /* As SDV does not support SEH: Stop verification: */
    /* This is unsound but is useful for suppressing false defects */ 
    SdvExit();
}

NTKERNELAPI
DECLSPEC_NORETURN
VOID
NTAPI
ExRaiseStatus (
    __in NTSTATUS Status
    )
{
    /* As SDV does not support SEH: Stop verification: */
    /* This is unsound but is useful for suppressing false defects */ 
    SdvExit();
}

NTKERNELAPI
NTSTATUS
ExReinitializeResourceLite(
    IN PERESOURCE Resource
    ) 
{ 
    return STATUS_SUCCESS; 
}

NTKERNELAPI
VOID
FASTCALL
sdv_ExReleaseFastMutex(
    IN PFAST_MUTEX FastMutex
    ) 
{  
    SDV_IRQL_POP();
}

NTKERNELAPI
VOID
FASTCALL
ExReleaseFastMutexUnsafe(
    IN PFAST_MUTEX  FastMutex
    ) 
{
}
    
NTKERNELAPI
VOID
ExReleaseResourceForThreadLite(
    IN PERESOURCE Resource,
    IN ERESOURCE_THREAD ResourceThreadId
    ) 
{
}

NTKERNELAPI
VOID
FASTCALL
ExReleaseResourceLite(
    IN PERESOURCE Resource    
    ) 
{
}

NTHALAPI
BOOLEAN
FASTCALL
sdv_ExTryToAcquireFastMutex(
    IN PFAST_MUTEX FastMutex
    ) 
{ 
    BOOLEAN b = (BOOLEAN) SdvMakeChoice(); 
    return b;
}

NTKERNELAPI
NTSTATUS
ExUuidCreate(
    OUT UUID *Uuid
    ) 
{ 
    int x = SdvMakeChoice();
    switch (x) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_RETRY;
    }
}
/* ..\wdm\ntddk-ex.c end */

/* ..\wdm\ntddk-misc.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

PCHAR sdv_containing_record(
    IN PCHAR Address
    )
{
    PCHAR record = (PCHAR) malloc(0);
    SdvAssume(record != NULL && record != Address);
    return record;
}

VOID
NTAPI
DbgBreakPoint(
    VOID
    )
{
}

NTSYSAPI
VOID
NTAPI
DbgBreakPointWithStatus(
    IN ULONG Status
    )
{
}

VOID
sdv_InitializeObjectAttributes(
     OUT POBJECT_ATTRIBUTES p,
     IN PUNICODE_STRING n,
     IN ULONG a,
     IN HANDLE r,
     IN PSECURITY_DESCRIPTOR s
     )
{
}

NTKERNELAPI
LONG
FASTCALL
sdv_InterlockedDecrement(
    IN LONG *Addend
    )
{
    (*Addend)--;
    return *Addend;
}

NTKERNELAPI
LONG
FASTCALL
sdv_InterlockedIncrement(
    IN LONG *Addend
    )
{
    (*Addend)++;
    return *Addend;
}

NTKERNELAPI
VOID
NTAPI
ProbeForRead(
    IN CONST VOID *Address,
    IN SIZE_T Length,
    IN ULONG Alignment
    )
{
}

NTKERNELAPI
VOID
NTAPI
ProbeForWrite (
    IN PVOID Address,
    IN SIZE_T Length,
    IN ULONG Alignment
    )
{
}

ULONGLONG
NTAPI
VerSetConditionMask(
        IN  ULONGLONG   ConditionMask,
        IN  ULONG   TypeMask,
        IN  UCHAR   Condition
    )
{
    ULONGLONG r = SdvMakeChoice();
    return r;
}



BOOLEAN sdv_NT_ERROR (
    NTSTATUS Status
    )
{
    int choice = SdvMakeChoice();
    if( 0 <= Status && Status <= 0x1FFFFFFF ) {
        return FALSE ;
    } else {
      return choice ? TRUE : FALSE ;
    }
}
/* ..\wdm\ntddk-misc.c end */

/* wdf-harness-parts.c begin */
#include "wdf.h"

#define NUMBER_OF_DEVICES 1

int notused_4p_devobj;
PDEVICE_OBJECT p_devobj = (PDEVICE_OBJECT) &notused_4p_devobj;


PUNICODE_STRING hregistry_path;
PDRIVER_OBJECT hp_driver;

int notused_4hdriver;
WDFDRIVER hdriver = (WDFDRIVER) &notused_4hdriver;

int notused_4hdrctx;
PVOID hdrctx = (PVOID) &notused_4hdrctx;

int init_4hdevice_init;
int notused_4hdevice_init;
PWDFDEVICE_INIT hdevice_init = (PWDFDEVICE_INIT) &init_4hdevice_init;   

int init_4hcontrol_deviceinit;
int notused_4hcontrol_deviceinit;
int control=0;
PWDFDEVICE_INIT hcontrol_deviceinit = (PWDFDEVICE_INIT) &init_4hcontrol_deviceinit;

int init_4hpdo_deviceinit;
int pdo=0;
int notused_4hpdo_deviceinit;
PWDFDEVICE_INIT hpdo_deviceinit = (PWDFDEVICE_INIT) &init_4hpdo_deviceinit;

int init_4hcontrol_deviceinit1;
int notused_4hcontrol_deviceinit1;
PWDFDEVICE_INIT hcontrol_deviceinit1 =(PWDFDEVICE_INIT) &init_4hcontrol_deviceinit1;

int init_4hpdo_deviceinit1;
int notused_4hpdo_deviceinit1;
PWDFDEVICE_INIT hpdo_deviceinit1 = (PWDFDEVICE_INIT) &init_4hpdo_deviceinit1;


int init_4hcontrol_deviceinit2;
int notused_4hcontrol_deviceinit2;
PWDFDEVICE_INIT hcontrol_deviceinit2_notused =(PWDFDEVICE_INIT) &init_4hcontrol_deviceinit2;

int init_4hpdo_deviceinit2;
int notused_4hpdo_deviceinit2;
PWDFDEVICE_INIT hpdo_deviceinit2_notused = (PWDFDEVICE_INIT) &init_4hpdo_deviceinit2;

int init_4hdevice, init_4hdevice1, init_4hdevice2;
int notused_4hdevice, notused_4hdevice1, notused_4hdevice2;
WDFDEVICE hdevice  = (WDFDEVICE)&init_4hdevice, 
          hdevice1 = (WDFDEVICE)&init_4hdevice1, 
		  hdevice2 = (WDFDEVICE)&init_4hdevice2; 

int init_4hcontrol_device;
int notused_4hcontrol_device;  
WDFDEVICE hcontrol_device = (WDFDEVICE)&init_4hcontrol_device;

int init_4hpdo_device;
int notused_4hpdo_device;
WDFDEVICE hpdo_device = (WDFDEVICE)&init_4hpdo_device; 


int init_4hcontrol_device1;
int notused_4hcontrol_device1;  
WDFDEVICE hcontrol_device1 = (WDFDEVICE)&init_4hcontrol_device1;

int init_4hpdo_device1;
int notused_4hpdo_device1;
WDFDEVICE hpdo_device1 = (WDFDEVICE)&init_4hpdo_device1; 

int init_4husb_device;
int notused_4husb_device;
WDFUSBDEVICE husb_device = (WDFUSBDEVICE)&init_4husb_device; 

int init_4hiotarget;
int notused_4hiotarget;
WDFIOTARGET hiotarget = (WDFIOTARGET) &init_4hiotarget;

WDFCOLLECTION hResourceList, hResourceListTranslated;
PVOID hdctx;

WDF_DEVICE_POWER_POLICY_STATE powerstate = (WDF_DEVICE_POWER_POLICY_STATE) 0;
WDFDMAENABLER  dmaenabler=(WDFDMAENABLER)0;

int notused_4hdevcollection;
WDFCOLLECTION hdevcollection = (WDFCOLLECTION) &notused_4hdevcollection;   

ULONG hdevcollection_count = 0;

int notused_4hdefqueue;
WDFQUEUE hdefqueue = (WDFQUEUE) &notused_4hdefqueue;

int notused_4hqctx;
PVOID hqctx = (PVOID) &notused_4hqctx;

int notused_4hrequest, notused1_4hrequest1;
PVOID hrequest = (PVOID) &notused_4hrequest, hrequest1 = (PVOID) &notused1_4hrequest1;

int notused_4hrctx;
PVOID hrctx = (PVOID) &notused_4hrctx;

PWDF_REQUEST_PARAMETERS hp_params;

int notused_4htimer;
WDFTIMER htimer = (WDFTIMER)&notused_4htimer;

int notused_4hwork_item;
WDFWORKITEM hwork_item = (WDFWORKITEM)&notused_4hwork_item;

int notused_4hdpc;     
WDFDPC hdpc = (WDFDPC)&notused_4hdpc;

int notused_4hinterrupt;     
WDFINTERRUPT hinterrupt = (WDFINTERRUPT)&notused_4hinterrupt;

ULONG hmessageID = 0;

int notused_4htctx;
PVOID htctx = (PVOID) &notused_4htctx;

size_t hln, hln2;

ULONG hln3;

int notused_4hbuffer;
int init_4hbuffer;
PVOID hbuffer = &init_4hbuffer;

int init_4hcur_buffer;
PVOID hcur_buffer = &init_4hcur_buffer;

int notused_4hmemory;
int init_4hmemory;
WDFMEMORY hmemory = (WDFMEMORY)&init_4hmemory;

int init_4hcur_memory;
PVOID hcur_memory = &init_4hcur_memory;

int notused_4hmdl;
int init_4hmdl;
PMDL hmdl = (PMDL)&init_4hmdl;

int init_4hcur_mdl;
PVOID hcur_mdl = &init_4hcur_mdl;

int notused_4hfileobj; 
WDFFILEOBJECT hfileobj = (WDFFILEOBJECT) &notused_4hfileobj;

int notused_4hfctx;
PVOID hfctx = (PVOID) &notused_4hfctx;

int* pnotused = &sdv_MmMapIoSpace_int;

int notused1 = 0;
int* pnotused1 = &notused1;

int notused_4wdfobject1;

ULONG hact = 3;

int rwcalled = 0;
int rwcalled1 = 0;

int reqpresented = 0;
int reqpresented1 = 0;

int reqcompleted = 0;
int reqcompleted1 = 0;


BOOLEAN sdv_WdfIoQueueNoRequests = 1;
BOOLEAN sdv_WdfIoQueueDriverNoRequests = 1;
NTSTATUS
sdv_SetReturnStatus()
{
	LONG choice = SdvMakeChoice();

    switch(choice) {
        case 0:
            return (NTSTATUS) STATUS_NOT_SUPPORTED;
            break;
        case 1:
        default:
            return (NTSTATUS) STATUS_SUCCESS;
            break;
    }
}


WDF_DEVICE_POWER_POLICY_STATE
sdv_SetDevicePowerPolicyState()
{
	WDF_DEVICE_POWER_POLICY_STATE powerstate = (WDF_DEVICE_POWER_POLICY_STATE) SdvMakeChoice();
	return powerstate;
    /*switch(choice) {
        case 0:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 1:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 2:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 3:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 4:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 5:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 6:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 7:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 8:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 9:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 10:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 11:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 12:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 13:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 14:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 15:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 16:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 17:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 18:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 19:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 20:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 21:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 22:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 23:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 24:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 25:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 26:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 27:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 28:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 29:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 30:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 31:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 32:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 33:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 34:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 35:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 36:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 37:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 38:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 39:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;

		case 40:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 41:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 42:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 43:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 44:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 45:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 46:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 47:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 48:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 49:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 50:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 51:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 52:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 53:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 54:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 55:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 56:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 57:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 58:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 59:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 60:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 61:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 62:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 63:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 64:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 65:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 66:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 67:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 68:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 69:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 70:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 71:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 72:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 73:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 74:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 75:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 76:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 77:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 78:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 79:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 80:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 81:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 82:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 83:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 84:
            return (WDF_DEVICE_POWER_POLICY_STATE) ;
            break;
		case 85:
        default:
            return (WDF_DEVICE_POWER_POLICY_STATE) WdfDevStatePowerNull;
            break;
    }*/
}/* wdf-harness-parts.c end */

/* wdf-harness-simple.c begin */
#if SDV_HARNESS==SDV_HARNESS_DRIVER_CREATE




void sdv_main ()
{
 
  NTSTATUS  ntstatus = STATUS_SUCCESS;


    ntstatus = DriverEntry(hp_driver, hregistry_path);
    SdvAssume (NT_SUCCESS(ntstatus));

  /*  status = fun_WDF_DRIVER_DEVICE_ADD(hdriver, hdevice_init);
    SdvAssume (NT_SUCCESS(status));*/



#ifdef fun_WDF_DRIVER_UNLOAD
	fun_WDF_DRIVER_UNLOAD(hdriver);
#endif
	} 
#endif
/* wdf-harness-simple.c end */

/* wdf-harness-flat-simple.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

/*****************************************************************************

    wdf-harness-flat-simple.c provides a flat harness for exercising a WDF driver.

    The flat harness is useful for checking issues that are of a local
    nature, for example IRQL checking, simple resource allocation and
    synchronization primitives.

    The flat harness only calls the driver once.  For a more complete
    and realistic harness that calls the driver repeatedly see the PNP
    harness in pnp-harness.c

    The following variations of the flat harness are available:
        SDV_WDF_FLAT_SIMPLE_HARNESS

    The harnesses exercises the driver as follows:
        SDV_WDF_FLAT_SIMPLE_HARNESS =
            ALL KMDF callbacks

     
*****************************************************************************/

#define SDV_WDF_IS_FLAT_HARNESS() \
    ( \
		SDV_HARNESS==SDV_WDF_FLAT_SIMPLE_HARNESS \
	)


#if SDV_WDF_IS_FLAT_HARNESS()



WDFCHILDLIST										jchildlist;
PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER		jPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER;
PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER		sPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER;
PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER		dPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER;
PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER		jPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER;
PCWDF_DEVICE_PNP_NOTIFICATION_DATA					j_pnp_not_data;
PCWDF_DEVICE_POWER_NOTIFICATION_DATA				j_power_not_data;
PCWDF_DEVICE_POWER_POLICY_NOTIFICATION_DATA			j_power_pol_not_data;
WDF_POWER_DEVICE_STATE								pWDF_POWER_DEVICE_STATE;
WDF_POWER_DEVICE_STATE								tWDF_POWER_DEVICE_STATE;
WDFCMRESLIST										rawResources;
WDFCMRESLIST										transResources;
WDF_SPECIAL_FILE_TYPE								notificationType;
BOOLEAN												jbool;
DEVICE_RELATION_TYPE								relationType;
WDFREQUEST											jRequest;
WDFDMAENABLER											jWdfEnabler;
WDFIORESREQLIST										jIoResourceRequirementsList;
WDFOBJECT											jAssociatedObject;
ULONG												jActionFlags;
size_t												jlength;
size_t												joblength;
size_t												jiblength;
ULONG												jIoControlCode;
WDFCONTEXT											jContext;
WDFOBJECT											jObject;
WDFCMRESLIST										jResources;
SYSTEM_POWER_STATE									jPowerState;
WDFDMATRANSACTION									jTransaction;
PVOID												jContext;
WDF_DMA_DIRECTION									jDirection;
PSCATTER_GATHER_LIST								jSglist;
WDFDPC												jDpc;
WDFTIMER											jTimer;
WDFWMIINSTANCE										jWmiInstance;
ULONG												jOutBufferSize;
PVOID												jOutBuffer;
PULONG												jBufferUsed;
ULONG												jInBufferSize;
PVOID												jInBuffer;
ULONG												jDataItemId;
ULONG												jMethodId;
PVOID												jBuffer;
WDFWORKITEM											jWorkItem;
LPGUID												jInterfaceType;
PINTERFACE											jExposedInterface;
PVOID												jExposedInterfaceSpecificData;
WDFWMIPROVIDER										jWmiProvider;
WDF_WMI_PROVIDER_CONTROL							jControl;
BOOLEAN												jEnable;



void Choice_Dispatch()
{
		int irql = SdvMakeChoice();

		switch(irql)
		{
		case 0:
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			break;
		case 1:
			SDV_IRQL_PUSH(APC_LEVEL);
			break;
		default:
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
		}

}

void sdv_main ()
{
 
	LONG choice;
	
	NTSTATUS  ntstatus = STATUS_SUCCESS;
  
	choice = SdvMakeChoice();

    switch (choice) {
    
	case 0: 
		ntstatus = DriverEntry(hp_driver, hregistry_path);
		SdvAssume (NT_SUCCESS(ntstatus));
		break;
	
	case 1: 
		#ifdef fun_WDF_DEVICE_CONTEXT_CLEANUP
			Choice_Dispatch();
			fun_WDF_DEVICE_CONTEXT_CLEANUP(hdriver);
		#endif
        break;

	case 2: 
        #ifdef fun_WDF_DEVICE_CONTEXT_DESTROY
			Choice_Dispatch();
			fun_WDF_DEVICE_CONTEXT_DESTROY(hdriver);
		#endif
        break;

	case 3: 
        #ifdef fun_WDF_IO_QUEUE_CONTEXT_CLEANUP_CALLBACK
			Choice_Dispatch();
			fun_WDF_IO_QUEUE_CONTEXT_CLEANUP_CALLBACK(hdriver);
		#endif
        break;

	case 4: 
 
        #ifdef fun_WDF_IO_QUEUE_CONTEXT_DESTROY_CALLBACK
			Choice_Dispatch();
			fun_WDF_IO_QUEUE_CONTEXT_DESTROY_CALLBACK(hdriver);
		#endif

	case 5: 
        #ifdef fun_WDF_CHILD_LIST_CREATE_DEVICE 
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_CHILD_LIST_CREATE_DEVICE(jchildlist,jPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER,hdevice_init);
		#endif
        break;

	case 6: 

        #ifdef fun_WDF_CHILD_LIST_SCAN_FOR_CHILDREN
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_CHILD_LIST_SCAN_FOR_CHILDREN(jchildlist);
		#endif
        break;

	case 7:  
        #ifdef fun_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COPY

		Choice_Dispatch();
		fun_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COPY(jchildlist,sPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER,dPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER);
		
		#endif
        break;
        
	case 8: 
        #ifdef fun_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_DUPLICATE
			
			Choice_Dispatch();
			fun_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_DUPLICATE(jchildlist,sPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER,dPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER);
		
		#endif
        break;

	case 9: 
        #ifdef fun_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE

			Choice_Dispatch();
			fun_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE(jchildlist,sPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER,dPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER);

		#endif
        break;

	case 10: 
        #ifdef fun_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_CLEANUP

			Choice_Dispatch();
			fun_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_CLEANUP(jchildlist,jPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER);

		#endif
        break;

	case 11: 
        #ifdef fun_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_COPY
			Choice_Dispatch();
			fun_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_COPY(jchildlist,sPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER,dPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER);
		#endif
        break;

	case 12: 
        #ifdef fun_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_DUPLICATE
			Choice_Dispatch();
			fun_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_DUPLICATE(jchildlist,sPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER,dPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER);
		#endif
        break;

	case 13: 
        #ifdef fun_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_CLEANUP
			Choice_Dispatch();
			fun_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_CLEANUP(jchildlist,jPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER);
		#endif
        break;

	case 14: 
        #ifdef fun_WDF_CHILD_LIST_DEVICE_REENUMERATED
			Choice_Dispatch();
			fun_WDF_CHILD_LIST_DEVICE_REENUMERATED(jchildlist,hdevice,sPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER,dPWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER);
		#endif
        break;

	case 15:
        /*#ifdef fun_WDF_CLASS_EXTENSIONIN_BIND
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_CLASS_EXTENSIONIN_BIND(hdriver);
		#endif*/
        break;

	case 16:
        /*#ifdef fun_WDF_CLASS_EXTENSIONIN_UNBIND
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_CLASS_EXTENSIONIN_UNBIND(hdriver);
		#endif*/
        break;

	case 17: 
        #ifdef fun_WDF_DEVICE_SHUTDOWN_NOTIFICATION
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_SHUTDOWN_NOTIFICATION(hdevice);
		#endif
        break;

	case 18: 
        #ifdef fun_WDF_DRIVER_ADD_DEVICE
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DRIVER_ADD_DEVICE(hdriver);
		#endif
        break;

	case 19: 
        #ifdef fun_WDF_FILE_CLOSE
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_FILE_CLOSE(hfileobj);
		#endif
        break;

	case 20: 
        #ifdef fun_WDF_FILE_CLEANUP
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_FILE_CLEANUP(hfileobj);
		#endif
        break;

	case 21: 
        #ifdef fun_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION(hdevice,j_pnp_not_data);
		#endif
        break;

	case 22: 
        #ifdef fun_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION(hdevice,j_power_not_data);
		#endif
        break;

	case 23: 
        #ifdef fun_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION(hdevice, j_power_pol_not_data);
		#endif
        break;

	case 24: 
        #ifdef fun_WDF_DEVICE_D0_ENTRY
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_D0_ENTRY(hdevice,pWDF_POWER_DEVICE_STATE);
		#endif
        break;

	case 25: 
		#ifdef fun_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED(hdevice,pWDF_POWER_DEVICE_STATE);
		#endif
        break;

	case 26: 
        #ifdef fun_WDF_DEVICE_D0_EXIT
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_D0_EXIT(hdevice,tWDF_POWER_DEVICE_STATE);
		#endif
        break;

	case 27: 
        #ifdef fun_WDF_DEVICE_D0_EXIT_PRE_INTERRUPTS_DISABLED
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_D0_EXIT_PRE_INTERRUPTS_DISABLED(hdevice,tWDF_POWER_DEVICE_STATE);
		#endif
        break;

	case 28: 
        #ifdef fun_WDF_DEVICE_PREPARE_HARDWARE
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_PREPARE_HARDWARE(hdevice,rawResources,transResources);
		#endif
        break;

	case 29: 
        #ifdef fun_WDF_DEVICE_RELEASE_HARDWARE
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_RELEASE_HARDWARE(hdevice,transResources);
		#endif
        break;

	case 30: 
        #ifdef fun_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP(hdevice);
		#endif
        break;

	case 31: 
        #ifdef fun_WDF_DEVICE_SELF_MANAGED_IO_FLUSH
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_SELF_MANAGED_IO_FLUSH(hdevice);
		#endif
        break;

	case 32: 
        #ifdef fun_WDF_DEVICE_SELF_MANAGED_IO_INIT
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_SELF_MANAGED_IO_INIT(hdevice);
		#endif
        break;

	case 33: 
        #ifdef fun_WDF_DEVICE_SELF_MANAGED_IO_SUSPEND
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_SELF_MANAGED_IO_SUSPEND(hdevice);
		#endif
        break;

	case 34: 
        #ifdef fun_WDF_DEVICE_SELF_MANAGED_IO_RESTART
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_SELF_MANAGED_IO_RESTART(hdevice);
		#endif
        break;

	case 35: 
        #ifdef fun_WDF_DEVICE_QUERY_STOP
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_QUERY_STOP(hdevice);
		#endif
        break;

	case 36: 
        #ifdef fun_WDF_DEVICE_QUERY_REMOVE
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_QUERY_REMOVE(hdevice);
		#endif
        break;

	case 37: 
        #ifdef fun_WDF_DEVICE_SURPRISE_REMOVAL
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_SURPRISE_REMOVAL(hdevice);
		#endif
        break;

	case 38: 
        #ifdef fun_WDF_DEVICE_USAGE_NOTIFICATION
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_USAGE_NOTIFICATION(hdevice, notificationType, jbool);
		#endif
        break;

	case 39: 
        #ifdef fun_WDF_DEVICE_RELATIONS_QUERY
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_RELATIONS_QUERY(hdevice, relationType);
		#endif
        break;

	case 40: 
        #ifdef fun_WDF_DEVICE_ARM_WAKE_FROM_S0
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_ARM_WAKE_FROM_S0(hdevice);
		#endif
        break;

	case 41: 
        #ifdef fun_WDF_DEVICE_ARM_WAKE_FROM_SX
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_ARM_WAKE_FROM_SX(hdevice);
		#endif
        break;

	case 42: 
        #ifdef fun_WDF_DEVICE_DISARM_WAKE_FROM_S0
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_DISARM_WAKE_FROM_S0(hdevice);
		#endif
        break;

	case 43: 
        #ifdef fun_WDF_DEVICE_DISARM_WAKE_FROM_SX
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_DISARM_WAKE_FROM_SX(hdevice);
		#endif
        break;

	case 44: 
        #ifdef fun_WDF_DEVICE_WAKE_FROM_S0_TRIGGERED
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_WAKE_FROM_S0_TRIGGERED(hdriver);
		#endif
        break;

	case 45: 
        #ifdef fun_WDF_DEVICE_WAKE_FROM_SX_TRIGGERED
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_WAKE_FROM_SX_TRIGGERED(hdevice);
		#endif
        break;

	case 46: 
        #ifdef fun_WDF_IO_IN_CALLER_CONTEXT
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_IO_IN_CALLER_CONTEXT(hdevice,jRequest);
		#endif
        break;

	case 47: 
        #ifdef fun_WDF_DMA_ENABLER_FILL
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DMA_ENABLER_FILL(jWdfEnabler);
		#endif
        break;

	case 48: 
        #ifdef fun_WDF_DMA_ENABLER_FLUSH
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DMA_ENABLER_FLUSH(jWdfEnabler);
		#endif
        break;

	case 49: 
        #ifdef fun_WDF_DMA_ENABLER_ENABLE
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DMA_ENABLER_ENABLE(jWdfEnabler);
		#endif
        break;

	case 50: 
        #ifdef fun_WDF_DMA_ENABLER_DISABLE
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DMA_ENABLER_DISABLE(jWdfEnabler);
		#endif
        break;

	case 51: 
        #ifdef fun_WDF_DMA_ENABLER_SELFMANAGED_IO_START
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DMA_ENABLER_SELFMANAGED_IO_START(jWdfEnabler);
		#endif
        break;

	case 52: 
        #ifdef fun_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP(jWdfEnabler);
		#endif
        break;

	case 53: 
        #ifdef fun_WDF_DRIVER_DEVICE_ADD
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DRIVER_DEVICE_ADD(hdriver, hdevice_init);
		#endif
        break;

	case 54: 
        #ifdef fun_WDF_DRIVER_UNLOAD
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DRIVER_UNLOAD(hdriver);
		#endif
        break;

	case 55: 
        /*#ifdef fun_WDF_TRACE_CALLBACK
			fun_WDF_TRACE_CALLBACK(hdriver);
		#endif*/
        break;

	case 56: 
        #ifdef fun_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS(hdevice,jIoResourceRequirementsList);
		#endif
        break;

	case 57: 
        #ifdef fun_WDF_DEVICE_REMOVE_ADDED_RESOURCES
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_REMOVE_ADDED_RESOURCES(hdevice,rawResources,transResources);
		#endif
        break;

	case 58: 
        #ifdef fun_WDF_INTERRUPT_ISR
			SDV_IRQL_PUSH(DISPATCH_LEVEL + 1);
			fun_WDF_INTERRUPT_ISR(hinterrupt,hmessageID);
		#endif
        break;

	case 59: 
        #ifdef fun_WDF_INTERRUPT_DPC
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_INTERRUPT_DPC(hinterrupt,jAssociatedObject);
		#endif
        break;

	case 60: 
		#ifdef fun_WDF_INTERRUPT_ENABLE
			SDV_IRQL_PUSH(DISPATCH_LEVEL + 1);
			fun_WDF_INTERRUPT_ENABLE(hinterrupt, hdevice);
		#endif
        break;

	case 61: 
		#ifdef fun_WDF_INTERRUPT_DISABLE
			SDV_IRQL_PUSH(DISPATCH_LEVEL + 1);
			fun_WDF_INTERRUPT_DISABLE(hinterrupt, hdevice);
		#endif
        break;

	case 62: 
		#ifdef fun_WDF_IO_QUEUE_IO_DEFAULT
			Choice_Dispatch();
			fun_WDF_IO_QUEUE_IO_DEFAULT(hdefqueue, jRequest);
		#endif
        break;

	case 63: 
        #ifdef fun_WDF_IO_QUEUE_IO_STOP
			Choice_Dispatch();
			fun_WDF_IO_QUEUE_IO_STOP(hdefqueue, jRequest,jActionFlags);
		#endif
        break;

	case 64: 
        #ifdef fun_WDF_IO_QUEUE_IO_RESUME
			Choice_Dispatch();
			fun_WDF_IO_QUEUE_IO_RESUME(hdefqueue, jRequest);
		#endif
        break;

	case 65: 
        #ifdef fun_WDF_IO_QUEUE_IO_READ
			Choice_Dispatch();
			fun_WDF_IO_QUEUE_IO_READ(hdefqueue, jRequest, jlength);
		#endif
        break;

	case 66: 
        #ifdef fun_WDF_IO_QUEUE_IO_WRITE
			Choice_Dispatch();
			fun_WDF_IO_QUEUE_IO_WRITE(hdefqueue, jRequest, jlength);
		#endif
        break;

	case 67: 
        #ifdef fun_WDF_IO_QUEUE_IO_DEVICE_CONTROL
			Choice_Dispatch();
			fun_WDF_IO_QUEUE_IO_DEVICE_CONTROL(hdefqueue, jRequest, joblength, jiblength, jIoControlCode);
		#endif
        break;

	case 68: 
        #ifdef fun_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL
			Choice_Dispatch();
			fun_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL(hdefqueue, jRequest, joblength, jiblength, jIoControlCode);
		#endif
        break;

	case 69: 
        #ifdef fun_WDF_IO_QUEUE_IO_CANCELED_ON_QUEUE
			Choice_Dispatch();
			fun_WDF_IO_QUEUE_IO_CANCELED_ON_QUEUE(hdefqueue, jRequest);
		#endif
        break;

	case 70: 
		#ifdef fun_SDV_WDF_IO_QUEUE_STATE
			Choice_Dispatch();
			fun_SDV_WDF_IO_QUEUE_STATE(hdefqueue, jContext);
		#endif
        break;

	case 71: 
        #ifdef fun_WDF_IO_TARGET_QUERY_REMOVE
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_IO_TARGET_QUERY_REMOVE(hiotarget);
		#endif
        break;

	case 72: 
        #ifdef fun_WDF_IO_TARGET_REMOVE_CANCELED
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_IO_TARGET_REMOVE_CANCELED(hiotarget);
		#endif
        break;

	case 73: 
        #ifdef fun_WDF_IO_TARGET_REMOVE_COMPLETE
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_IO_TARGET_REMOVE_COMPLETE(hiotarget);
		#endif
        break;

	case 74: 
		#ifdef fun_WDF_OBJECT_CONTEXT_CLEANUP
			Choice_Dispatch();
			fun_WDF_OBJECT_CONTEXT_CLEANUP(jObject);
		#endif
        break;

	case 75: 
        #ifdef fun_WDF_OBJECT_CONTEXT_DESTROY
			Choice_Dispatch();
			fun_WDF_OBJECT_CONTEXT_DESTROY(jObject);
		#endif
        break;

	case 76: 
        #ifdef fun_WDF_DEVICE_RESOURCES_QUERY
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_RESOURCES_QUERY(hdevice, jResources);
		#endif
        break;

	case 77: 
        #ifdef fun_WDF_DEVICE_RESOURCE_REQUIREMENTS_QUERY
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_RESOURCE_REQUIREMENTS_QUERY(hdevice, jIoResourceRequirementsList);
		#endif
        break;

	case 78: 
        #ifdef fun_WDF_DEVICE_EJECT
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_EJECT(hdevice);
		#endif
        break;

	case 79: 
        #ifdef fun_WDF_DEVICE_SET_LOCK
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_SET_LOCK(hdevice, jbool);
		#endif
        break;

	case 80: 
        #ifdef fun_WDF_DEVICE_ENABLE_WAKE_AT_BUS
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_ENABLE_WAKE_AT_BUS(hdevice, jPowerState);
		#endif
        break;

	case 81: 
        #ifdef fun_WDF_DEVICE_DISABLE_WAKE_AT_BUS
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_DISABLE_WAKE_AT_BUS(hdevice);
		#endif
        break;

	case 82: 
        #ifdef fun_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST(hdevice, jInterfaceType, jExposedInterface, jExposedInterfaceSpecificData);
		#endif
        break;

	case 83: 

        #ifdef fun_WDF_WMI_PROVIDER_FUNCTION_CONTROL
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_PROVIDER_FUNCTION_CONTROL(jWmiProvider, jControl, jEnable);
		#endif
        break;

	case 84:
        #ifdef fun_WDF_PROGRAM_DMA_1
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_PROGRAM_DMA_1(jTransaction,hdevice,jContext,jDirection,jSglist);
		#endif
        break;

	case 85:
        #ifdef fun_WDF_PROGRAM_DMA_2
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_PROGRAM_DMA_2(jTransaction,hdevice,jContext,jDirection,jSglist);
		#endif
        break;

	case 86:
        #ifdef fun_WDF_PROGRAM_DMA_3
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_PROGRAM_DMA_3(jTransaction,hdevice,jContext,jDirection,jSglist);
		#endif
        break;

	case 87:
        #ifdef fun_WDF_PROGRAM_DMA_4
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_PROGRAM_DMA_4(jTransaction,hdevice,jContext,jDirection,jSglist);
		#endif
        break;

	case 88:
        #ifdef fun_WDF_PROGRAM_DMA_5
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_PROGRAM_DMA_5(jTransaction,hdevice,jContext,jDirection,jSglist);
		#endif
        break;

	case 89:
        #ifdef fun_WDF_PROGRAM_DMA_6
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_PROGRAM_DMA_6(jTransaction,hdevice,jContext,jDirection,jSglist);
		#endif
        break;


	case 90:
        #ifdef fun_WDF_DPC_1
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_DPC_1(jDpc);
		#endif
        break;

	case 91:
        #ifdef fun_WDF_DPC_2
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_DPC_2(jDpc);
		#endif
        break;

	case 92:
        #ifdef fun_WDF_DPC_3
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_DPC_3(jDpc);
		#endif
        break;

	case 93:
        #ifdef fun_WDF_DPC_4
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_DPC_4(jDpc);
		#endif
        break;

	case 94:
        #ifdef fun_WDF_DPC_5
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_DPC_5(jDpc);
		#endif
        break;

	case 95:
        #ifdef fun_WDF_DPC_6
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_DPC_6(jDpc);
		#endif
        break;

	case 96:
        #ifdef fun_WDF_DPC_7
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_DPC_7(jDpc);
		#endif
        break;

	case 97:
        #ifdef fun_WDF_INTERRUPT_SYNCHRONIZE_1
			SDV_IRQL_PUSH(DISPATCH_LEVEL + 1);
			fun_WDF_INTERRUPT_SYNCHRONIZE_1(hinterrupt,jContext);
		#endif
        break;

	case 98:
        #ifdef fun_WDF_INTERRUPT_SYNCHRONIZE_2
			SDV_IRQL_PUSH(DISPATCH_LEVEL + 1);
			fun_WDF_INTERRUPT_SYNCHRONIZE_2(hinterrupt,jContext);
		#endif
        break;

	case 99:
        #ifdef fun_WDF_INTERRUPT_SYNCHRONIZE_3
			SDV_IRQL_PUSH(DISPATCH_LEVEL + 1);
			fun_WDF_INTERRUPT_SYNCHRONIZE_3(hinterrupt,jContext);
		#endif
        break;

	case 100:
        #ifdef fun_WDF_INTERRUPT_SYNCHRONIZE_4
			SDV_IRQL_PUSH(DISPATCH_LEVEL + 1);
			fun_WDF_INTERRUPT_SYNCHRONIZE_4(hinterrupt,jContext);
		#endif
        break;

	case 101:
        #ifdef fun_WDF_INTERRUPT_SYNCHRONIZE_5
			SDV_IRQL_PUSH(DISPATCH_LEVEL + 1);
			fun_WDF_INTERRUPT_SYNCHRONIZE_5(hinterrupt,jContext);
		#endif
        break;

	case 102:
        #ifdef fun_WDF_INTERRUPT_SYNCHRONIZE_6
			SDV_IRQL_PUSH(DISPATCH_LEVEL + 1);
			fun_WDF_INTERRUPT_SYNCHRONIZE_6(hinterrupt,jContext);
		#endif
        break;

	case 103:
        #ifdef fun_WDF_INTERRUPT_SYNCHRONIZE_7
			SDV_IRQL_PUSH(DISPATCH_LEVEL + 1);
			fun_WDF_INTERRUPT_SYNCHRONIZE_7(hinterrupt,jContext);
		#endif
        break;

	case 104:
        #ifdef fun_WDF_INTERRUPT_SYNCHRONIZE_8
			SDV_IRQL_PUSH(DISPATCH_LEVEL + 1);
			fun_WDF_INTERRUPT_SYNCHRONIZE_8(hinterrupt,jContext);
		#endif
        break;

	case 105:
        #ifdef fun_WDF_INTERRUPT_SYNCHRONIZE_9
			SDV_IRQL_PUSH(DISPATCH_LEVEL + 1);
			fun_WDF_INTERRUPT_SYNCHRONIZE_9(hinterrupt,jContext);
		#endif
        break;

	case 106:
        #ifdef fun_WDF_INTERRUPT_SYNCHRONIZE_10
			SDV_IRQL_PUSH(DISPATCH_LEVEL + 1);
			fun_WDF_INTERRUPT_SYNCHRONIZE_10(hinterrupt,jContext);
		#endif
        break;

	case 107:
        #ifdef fun_WDF_INTERRUPT_SYNCHRONIZE_11
			SDV_IRQL_PUSH(DISPATCH_LEVEL + 1);
			fun_WDF_INTERRUPT_SYNCHRONIZE_11(hinterrupt,jContext);
		#endif
        break;

	case 108:
        #ifdef fun_WDF_REQUEST_CANCEL_1
			Choice_Dispatch();
			fun_WDF_REQUEST_CANCEL_1(jRequest);
		#endif
        break;

	case 109:
        #ifdef fun_WDF_REQUEST_CANCEL_2
			Choice_Dispatch();
			fun_WDF_REQUEST_CANCEL_2(jRequest);
		#endif
        break;

	case 110:
        #ifdef fun_WDF_REQUEST_CANCEL_3
			Choice_Dispatch();
			fun_WDF_REQUEST_CANCEL_3(jRequest);
		#endif
        break;

	case 111:
        #ifdef fun_WDF_REQUEST_CANCEL_4
			Choice_Dispatch();
			fun_WDF_REQUEST_CANCEL_4(jRequest);
		#endif
        break;

	case 112:
        #ifdef fun_WDF_REQUEST_CANCEL_5
			Choice_Dispatch();
			fun_WDF_REQUEST_CANCEL_5(jRequest);
		#endif
        break;

	case 113:
        #ifdef fun_WDF_REQUEST_CANCEL_6
			Choice_Dispatch();
			fun_WDF_REQUEST_CANCEL_6(jRequest);
		#endif
        break;


	case 114:
        #ifdef fun_WDF_TIMER_1
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_TIMER_1(jTimer);
		#endif
        break;

	case 115:
        #ifdef fun_WDF_TIMER_2
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_TIMER_2(jTimer);
		#endif
        break;

	case 116:
        #ifdef fun_WDF_TIMER_3
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_TIMER_3(jTimer);
		#endif
        break;

	case 117:
        #ifdef fun_WDF_TIMER_4
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_TIMER_4(jTimer);
		#endif
        break;

	case 118:
        #ifdef fun_WDF_TIMER_5
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_TIMER_5(jTimer);
		#endif
        break;

	case 119:
        #ifdef fun_WDF_TIMER_6
			SDV_IRQL_PUSH(DISPATCH_LEVEL);
			fun_WDF_TIMER_6(jTimer);
		#endif
        break;

	case 120:
        #ifdef fun_WDF_WMI_INSTANCE_QUERY_INSTANCE_1
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_QUERY_INSTANCE_1(jWmiInstance,jOutBufferSize,jOutBuffer,jBufferUsed);
		#endif
        break;

	case 121:
        #ifdef fun_WDF_WMI_INSTANCE_QUERY_INSTANCE_2
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_QUERY_INSTANCE_2(jWmiInstance,jOutBufferSize,jOutBuffer,jBufferUsed);
		#endif
        break;

	case 122:
        #ifdef fun_WDF_WMI_INSTANCE_QUERY_INSTANCE_3
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_QUERY_INSTANCE_3(jWmiInstance,jOutBufferSize,jOutBuffer,jBufferUsed);
		#endif
        break;

	case 123:
        #ifdef fun_WDF_WMI_INSTANCE_QUERY_INSTANCE_4
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_QUERY_INSTANCE_4(jWmiInstance,jOutBufferSize,jOutBuffer,jBufferUsed);
		#endif
        break;

	case 124:
        #ifdef fun_WDF_WMI_INSTANCE_QUERY_INSTANCE_5
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_QUERY_INSTANCE_5(jWmiInstance,jOutBufferSize,jOutBuffer,jBufferUsed);
		#endif
        break;

	case 125:
        #ifdef fun_WDF_WMI_INSTANCE_SET_INSTANCE_1
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_SET_INSTANCE_1(jWmiInstance,jInBufferSize,jInBuffer);
		#endif
        break;

	case 126:
        #ifdef fun_WDF_WMI_INSTANCE_SET_INSTANCE_2
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_SET_INSTANCE_2(jWmiInstance,jInBufferSize,jInBuffer);
		#endif
        break;

	case 127:
        #ifdef fun_WDF_WMI_INSTANCE_SET_INSTANCE_3
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_SET_INSTANCE_3(jWmiInstance,jInBufferSize,jInBuffer);
		#endif
        break;

	case 128:
        #ifdef fun_WDF_WMI_INSTANCE_SET_INSTANCE_4
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_SET_INSTANCE_4(jWmiInstance,jInBufferSize,jInBuffer);
		#endif
        break;

	case 129:
        #ifdef fun_WDF_WMI_INSTANCE_SET_INSTANCE_5
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_SET_INSTANCE_5(jWmiInstance,jInBufferSize,jInBuffer);
		#endif
        break;

	case 130:
        #ifdef fun_WDF_WMI_INSTANCE_SET_ITEM_1
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_SET_ITEM_1(jWmiInstance,jDataItemId,jInBufferSize,jInBuffer);
		#endif
        break;

	case 131:
        #ifdef fun_WDF_WMI_INSTANCE_SET_ITEM_2
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_SET_ITEM_2(jWmiInstance,jDataItemId,jInBufferSize,jInBuffer);
		#endif
        break;

	case 132:
        #ifdef fun_WDF_WMI_INSTANCE_SET_ITEM_3
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_SET_ITEM_3(jWmiInstance,jDataItemId,jInBufferSize,jInBuffer);
		#endif
        break;

	case 133:
        #ifdef fun_WDF_WMI_INSTANCE_SET_ITEM_4
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_SET_ITEM_4(jWmiInstance,jDataItemId,jInBufferSize,jInBuffer);
		#endif
        break;

	case 134:
        #ifdef fun_WDF_WMI_INSTANCE_SET_ITEM_5
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_SET_ITEM_5(jWmiInstance,jDataItemId,jInBufferSize,jInBuffer);
		#endif
        break;

	case 135:
        #ifdef fun_WDF_WMI_INSTANCE_EXECUTE_METHOD_1
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_EXECUTE_METHOD_1(jWmiInstance,jMethodId,jInBufferSize,jOutBufferSize,jBuffer,jBufferUsed);
		#endif
        break;

	case 136:
        #ifdef fun_WDF_WMI_INSTANCE_EXECUTE_METHOD_2
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_EXECUTE_METHOD_2(jWmiInstance,jMethodId,jInBufferSize,jOutBufferSize,jBuffer,jBufferUsed);
		#endif
        break;


	case 137:
        #ifdef fun_WDF_WMI_INSTANCE_EXECUTE_METHOD_3
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_EXECUTE_METHOD_3(jWmiInstance,jMethodId,jInBufferSize,jOutBufferSize,jBuffer,jBufferUsed);
		#endif
        break;


	case 138:
        #ifdef fun_WDF_WMI_INSTANCE_EXECUTE_METHOD_4
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_EXECUTE_METHOD_4(jWmiInstance,jMethodId,jInBufferSize,jOutBufferSize,jBuffer,jBufferUsed);
		#endif
        break;


	case 139:
        #ifdef fun_WDF_WMI_INSTANCE_EXECUTE_METHOD_5
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WMI_INSTANCE_EXECUTE_METHOD_5(jWmiInstance,jMethodId,jInBufferSize,jOutBufferSize,jBuffer,jBufferUsed);
		#endif
        break;

	case 140:
        #ifdef fun_WDF_WORKITEM_1
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WORKITEM_1(jWorkItem);
		#endif
        break;

	case 141:
        #ifdef fun_WDF_WORKITEM_2
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WORKITEM_2(jWorkItem);
		#endif
        break;

	case 142:
        #ifdef fun_WDF_WORKITEM_3
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WORKITEM_3(jWorkItem);
		#endif
        break;

	case 143:
        #ifdef fun_WDF_WORKITEM_4
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WORKITEM_4(jWorkItem);
		#endif
        break;

	case 144:
        #ifdef fun_WDF_WORKITEM_5
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WORKITEM_5(jWorkItem);
		#endif
        break;

	case 145:
        #ifdef fun_WDF_WORKITEM_6
			SDV_IRQL_PUSH(PASSIVE_LEVEL);
			fun_WDF_WORKITEM_6(jWorkItem);
		#endif
        break;

	default:
		break;

	}
}

#endif
/* wdf-harness-flat-simple.c end */

/* wdf-pnp-harness.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

/*****************************************************************************

    wdf-pnp-harness.c provides a PNP harness for exercising a driver.

    

    The following variations of the KMDF PNP harness are available:
        SDV_HARNESS_PNP_DEFERRED_IO_REQUESTS
        SDV_HARNESS_PNP_IO_REQUESTS
        
*****************************************************************************/

#define SDV_IS_KMDF_PNP_HARNESS() \
    ( \
        SDV_HARNESS==SDV_HARNESS_PNP_DEFERRED_IO_REQUESTS || \
        SDV_HARNESS==SDV_HARNESS_PNP_IO_REQUESTS \
    )

#if SDV_IS_KMDF_PNP_HARNESS()

int h_i;

void sdv_main ()
{
  int sdv_choice = SdvMakeChoice(); 
  
  #if SDV_HARNESS==SDV_HARNESS_PNP_DEFERRED_IO_REQUESTS
	int sdv_choice1 = SdvMakeChoice();
  #endif 
  
  NTSTATUS  ntstatus = STATUS_SUCCESS;
  NTSTATUS status = STATUS_SUCCESS;

  
/*****************************************************************************
    For all the harness(es):
        SDV_HARNESS_PNP_DEFERRED_IO_REQUESTS
        SDV_HARNESS_PNP_IO_REQUESTS
    Exercise:
        DriverEntry;
		fun_WDF_DRIVER_DEVICE_ADD;
*****************************************************************************/
    ntstatus = DriverEntry(hp_driver, hregistry_path);
    SdvAssume (NT_SUCCESS(ntstatus));


	for (h_i=1; h_i<=NUMBER_OF_DEVICES; h_i++)
	{   
      #ifdef fun_WDF_DRIVER_DEVICE_ADD
         status = fun_WDF_DRIVER_DEVICE_ADD(hdriver, hdevice_init);
         SdvAssume (NT_SUCCESS(status));
      #endif
	}

if (NT_SUCCESS(status)) {
  #ifdef fun_WDF_DEVICE_SELF_MANAGED_IO_INIT
		status = fun_WDF_DEVICE_SELF_MANAGED_IO_INIT(hdevice);
		SdvAssume (NT_SUCCESS(status));
  #endif

switch (sdv_choice) {
#ifdef fun_WDF_IO_QUEUE_IO_DEFAULT 
#define SWITCH1MACRO_DEFINED
	  case 0:
	     rwcalled = 1;
		 reqpresented = 1;
		 fun_WDF_IO_QUEUE_IO_DEFAULT(hdefqueue,hrequest);
	  break;
#endif
#ifdef fun_WDF_IO_QUEUE_IO_READ
#define SWITCH1MACRO_DEFINED
	  case 1:
	    rwcalled = 1;
	    reqpresented = 1;
	    fun_WDF_IO_QUEUE_IO_READ(hdefqueue,hrequest,hln);
	  break;
#endif
#ifdef fun_WDF_IO_QUEUE_IO_WRITE
#define SWITCH1MACRO_DEFINED
	  case 2: 
	    rwcalled = 1;
	    reqpresented = 1;
	    fun_WDF_IO_QUEUE_IO_WRITE(hdefqueue,hrequest,hln);
	  break;
#endif
#ifdef fun_WDF_IO_QUEUE_IO_DEVICE_CONTROL
#define SWITCH1MACRO_DEFINED
	  case 3: 
	    rwcalled = 1;
	    reqpresented = 1;
	    fun_WDF_IO_QUEUE_IO_DEVICE_CONTROL(hdefqueue,hrequest,hln,hln2,hln3);
	  break;
#endif
#ifdef fun_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL
#define SWITCH1MACRO_DEFINED
	  case 4:
	    rwcalled = 1;
	    reqpresented = 1;
	    fun_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL(hdefqueue,hrequest,hln,hln2,hln3);
	  break;
#endif
#if SDV_HARNESS==SDV_HARNESS_DRIVER_CREATE
	#ifdef fun_WDF_IO_QUEUE_IO_STOP
	#define SWITCH1MACRO_DEFINED
		  case 5: 
			SdvAssume(reqpresented);
			SdvAssume(!reqcompleted);
			fun_WDF_IO_QUEUE_IO_STOP(hdefqueue,hrequest,hact);
			#ifdef fun_WDF_IO_QUEUE_IO_RESUME
			  fun_WDF_IO_QUEUE_IO_RESUME(hdefqueue,hrequest);
			#endif
		  break;
	#endif
#endif

#if defined (SWITCH1MACRO_DEFINED)
	default: 
	  SdvAssume(0);             
	  break;
#endif
}



#if SDV_HARNESS==SDV_HARNESS_PNP_DEFERRED_IO_REQUESTS
#undef SWITCH1MACRO_DEFINED

switch (sdv_choice1) {
#ifdef fun_WDF_REQUEST_CANCEL_1
  case 0:
	  SdvAssume(reqpresented);
 	  SdvAssume(!reqcompleted);
	  fun_WDF_REQUEST_CANCEL_1(hrequest);
	  break;
#endif
#ifdef fun_WDF_REQUEST_CANCEL_2
  case 1:
	  SdvAssume(reqpresented);
 	  SdvAssume(!reqcompleted);
	  fun_WDF_REQUEST_CANCEL_2(hrequest);
	  break;
#endif
#ifdef fun_WDF_REQUEST_CANCEL_3
  case 2:
	  SdvAssume(reqpresented);
 	  SdvAssume(!reqcompleted);
	  fun_WDF_REQUEST_CANCEL_3(hrequest);
	  break;
#endif
#ifdef fun_WDF_REQUEST_CANCEL_4
  case 3:
	  SdvAssume(reqpresented);
 	  SdvAssume(!reqcompleted);
	  fun_WDF_REQUEST_CANCEL_4(hrequest);
	  break;
#endif
#ifdef fun_WDF_REQUEST_CANCEL_5
  case 4:
	  SdvAssume(reqpresented);
 	  SdvAssume(!reqcompleted);
	  fun_WDF_REQUEST_CANCEL_5(hrequest);
	  break;
#endif
#ifdef fun_WDF_REQUEST_CANCEL_6
  case 5:
	  SdvAssume(reqpresented);
 	  SdvAssume(!reqcompleted);
	  fun_WDF_REQUEST_CANCEL_6(hrequest);
	  break;
#endif


#ifdef fun_WDF_IO_QUEUE_IO_STOP
  case 6: 
	  SdvAssume(reqpresented);
	  SdvAssume(!reqcompleted);
	  fun_WDF_IO_QUEUE_IO_STOP(hdefqueue,hrequest,hact);
      #ifdef fun_WDF_IO_QUEUE_IO_RESUME
	    fun_WDF_IO_QUEUE_IO_RESUME(hdefqueue,hrequest);
      #endif
      break;
#endif
#ifdef fun_WDF_TIMER_1
#define SWITCH2MACRO_DEFINED
  case 7:
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_TIMER_1(htimer);
	  break;
#endif
#ifdef fun_WDF_TIMER_2
#define SWITCH2MACRO_DEFINED
  case 8:
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_TIMER_2(htimer);
	  break;
#endif
#ifdef fun_WDF_TIMER_3
#define SWITCH2MACRO_DEFINED
  case 9:
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_TIMER_3(htimer);
	  break;
#endif
#ifdef fun_WDF_TIMER_4
#define SWITCH2MACRO_DEFINED
  case 10:
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_TIMER_4(htimer);
	  break;
#endif
#ifdef fun_WDF_TIMER_5
#define SWITCH2MACRO_DEFINED
  case 11:
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_TIMER_5(htimer);
	  break;
#endif
#ifdef fun_WDF_TIMER_6
#define SWITCH2MACRO_DEFINED
  case 12:
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_TIMER_6(htimer);
	  break;
#endif
#ifdef fun_WDF_INTERRUPT_ISR
#define SWITCH2MACRO_DEFINED
 case 13:
      fun_WDF_INTERRUPT_ISR(hinterrupt, hmessageID);
#ifdef fun_WDF_INTERRUPT_DPC
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_INTERRUPT_DPC(hinterrupt, hdevice);
#endif
#ifdef fun_WDF_INTERRUPT_ENABLE  
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      status = fun_WDF_INTERRUPT_ENABLE(hinterrupt, hdevice);	  
#endif
#ifdef fun_WDF_INTERRUPT_DISABLE  
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      status = fun_WDF_INTERRUPT_DISABLE(hinterrupt, hdevice);
#endif
	  break;
#endif
#ifdef fun_WDF_DPC_1
#define SWITCH2MACRO_DEFINED
 case 14:  
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_DPC_1(hdpc);
      break;	  
#endif
#ifdef fun_WDF_DPC_2
#define SWITCH2MACRO_DEFINED
 case 15:  
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_DPC_2(hdpc);
      break;  
#endif
#ifdef fun_WDF_DPC_3
#define SWITCH2MACRO_DEFINED
 case 16:  
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_DPC_3(hdpc);
      break;  
#endif
#ifdef fun_WDF_DPC_4
#define SWITCH2MACRO_DEFINED
 case 17:  
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_DPC_4(hdpc);
      break;  
#endif
#ifdef fun_WDF_DPC_5
#define SWITCH2MACRO_DEFINED
 case 18:  
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_DPC_5(hdpc);
      break;  
#endif
#ifdef fun_WDF_DPC_6
#define SWITCH2MACRO_DEFINED
 case 19:  
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_DPC_6(hdpc);
      break;  
#endif
#ifdef fun_WDF_DPC_7
#define SWITCH2MACRO_DEFINED
 case 20:  
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_DPC_7(hdpc);
      break;  
#endif
#ifdef fun_WDF_WORKITEM_1
#define SWITCH2MACRO_DEFINED
 case 21:
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_WORKITEM_1(hwork_item);
	  break;
#endif
#ifdef fun_WDF_WORKITEM_2
#define SWITCH2MACRO_DEFINED
 case 22:
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_WORKITEM_2(hwork_item);
	  break;
#endif
#ifdef fun_WDF_WORKITEM_3
#define SWITCH2MACRO_DEFINED
 case 23:
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_WORKITEM_3(hwork_item);
	  break;
#endif
#ifdef fun_WDF_WORKITEM_4
#define SWITCH2MACRO_DEFINED
 case 24:
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_WORKITEM_4(hwork_item);
	  break;
#endif
#ifdef fun_WDF_WORKITEM_5
#define SWITCH2MACRO_DEFINED
 case 25:
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_WORKITEM_5(hwork_item);
	  break;
#endif
#ifdef fun_WDF_WORKITEM_6
#define SWITCH2MACRO_DEFINED
 case 26:
      SdvAssume(reqpresented);
      SdvAssume(!reqcompleted);
      fun_WDF_WORKITEM_6(hwork_item);
	  break;
#endif




#if defined (SWITCH2MACRO_DEFINED)
default: 
	  SdvAssume(0);   
	  break;
#endif
}


#endif


#if SDV_HARNESS==SDV_HARNESS_PNP_DEFERRED_IO_REQUESTS
	#undef SWITCH2MACRO_DEFINED
#endif

#if SDV_HARNESS==SDV_HARNESS_PNP_IO_REQUESTS
#undef SWITCH1MACRO_DEFINED
#ifdef fun_WDF_REQUEST_CANCEL_1
      SdvAssume(reqpresented);
	  SdvAssume(!reqcompleted);
	  fun_WDF_REQUEST_CANCEL_1(hrequest);
#endif
#endif



#ifdef fun_WDFDEVICE_WDM_IRP_PREPROCESS_1
	status=fun_WDFDEVICE_WDM_IRP_PREPROCESS_1(hdevice,sdv_irp);
#endif

#ifdef fun_WDFDEVICE_WDM_IRP_PREPROCESS_2
	status=fun_WDFDEVICE_WDM_IRP_PREPROCESS_2(hdevice,sdv_irp);
#endif

#ifdef fun_WDFDEVICE_WDM_IRP_PREPROCESS_3
	status=fun_WDFDEVICE_WDM_IRP_PREPROCESS_3(hdevice,sdv_irp);
#endif

#ifdef fun_WDFDEVICE_WDM_IRP_PREPROCESS_4
	status=fun_WDFDEVICE_WDM_IRP_PREPROCESS_4(hdevice,sdv_irp);
#endif

#ifdef fun_WDFDEVICE_WDM_IRP_PREPROCESS_5
	status=fun_WDFDEVICE_WDM_IRP_PREPROCESS_5(hdevice,sdv_irp);
#endif

#ifdef fun_WDFDEVICE_WDM_IRP_PREPROCESS_6
	status=fun_WDFDEVICE_WDM_IRP_PREPROCESS_6(hdevice,sdv_irp);
#endif


#ifdef fun_WDF_DEVICE_WAKE_FROM_SX_TRIGGERED
      fun_WDF_DEVICE_WAKE_FROM_SX_TRIGGERED(hdevice);
#endif

#ifdef fun_WDF_DEVICE_D0_ENTRY
      fun_WDF_DEVICE_D0_ENTRY(hdevice,powerstate);
#endif

#ifdef fun_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED
      fun_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED(hdevice,powerstate);
#endif


#ifdef fun_WDF_CHILD_LIST_SCAN_FOR_CHILDREN
      fun_WDF_CHILD_LIST_SCAN_FOR_CHILDREN(dmaenabler);
#endif

#ifdef fun_WDF_DMA_ENABLER_FILL
      fun_WDF_DMA_ENABLER_FILL(dmaenabler);
#endif

#ifdef fun_WDF_DMA_ENABLER_ENABLE
      fun_WDF_DMA_ENABLER_ENABLE(dmaenabler);
#endif

#ifdef fun_WDF_DMA_ENABLER_SELFMANAGED_IO_START
      fun_WDF_DMA_ENABLER_SELFMANAGED_IO_START(dmaenabler);
#endif

#ifdef fun_WDF_DEVICE_DISARM_WAKE_FROM_S0
      fun_WDF_DEVICE_DISARM_WAKE_FROM_S0(hdevice);
#endif
#ifdef fun_WDF_DEVICE_DISARM_WAKE_FROM_SX
      fun_WDF_DEVICE_DISARM_WAKE_FROM_SX(hdevice);
#endif

#ifdef fun_WDF_DEVICE_SELF_MANAGED_IO_INIT
      fun_WDF_DEVICE_SELF_MANAGED_IO_INIT(hdevice);
#endif

#ifdef fun_WDF_DEVICE_SELF_MANAGED_IO_RESTART
      fun_WDF_DEVICE_SELF_MANAGED_IO_RESTART(hdevice);
#endif
#ifdef fun_WDF_DEVICE_DISABLE_WAKE_AT_BUS
      fun_WDF_DEVICE_DISABLE_WAKE_AT_BUS(hdevice);
#endif
#ifdef fun_WDF_IO_QUEUE_IO_STOP
      fun_WDF_IO_QUEUE_IO_STOP(hdefqueue,hrequest,hact);
#endif
#ifdef fun_WDF_IO_QUEUE_IO_RESUME
      fun_WDF_IO_QUEUE_IO_RESUME(hdefqueue,hrequest);
#endif

#ifdef fun_WDF_IO_QUEUE_CONTEXT_CLEANUP_CALLBACK
	fun_WDF_IO_QUEUE_CONTEXT_CLEANUP_CALLBACK(hqctx);
#endif

#ifdef fun_WDF_IO_QUEUE_CONTEXT_DESTROY_CALLBACK
	fun_WDF_IO_QUEUE_CONTEXT_DESTROY_CALLBACK(hqctx);
#endif

#ifdef fun_WDF_FILE_CONTEXT_CLEANUP_CALLBACK
	fun_WDF_FILE_CONTEXT_CLEANUP_CALLBACK(hfctx);
#endif

#ifdef fun_WDF_FILE_CONTEXT_DESTROY_CALLBACK
	fun_WDF_FILE_CONTEXT_DESTROY_CALLBACK(hfctx);
#endif

#ifdef fun_WDF_FILE_CLOSE
        fun_WDF_FILE_CLOSE(hfileobj);
#endif
#ifdef fun_WDF_FILE_CLEANUP
	fun_WDF_FILE_CLEANUP(hdevice);
#endif

#ifdef fun_WDF_DEVICE_SELF_MANAGED_IO_SUSPEND
	ntstatus = fun_WDF_DEVICE_SELF_MANAGED_IO_SUSPEND(hdevice);
#endif

#ifdef fun_WDF_DEVICE_SELF_MANAGED_IO_FLUSH
	fun_WDF_DEVICE_SELF_MANAGED_IO_FLUSH(hdevice);
#endif

#ifdef fun_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP
	fun_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP(hdevice);
#endif

#ifdef fun_WDF_DEVICE_SURPRISE_REMOVAL
	fun_WDF_DEVICE_SURPRISE_REMOVAL(hdevice);
#endif


#ifdef fun_WDF_DEVICE_CONTEXT_CLEANUP  
	fun_WDF_DEVICE_CONTEXT_CLEANUP(hdevice);
	
	#if SDV_HARNESS==SDV_HARNESS_PNP_IO_REQUESTS
	if (hdevcollection_count != 0)
	{
		for (h_i=hdevcollection_count-1; h_i>0; h_i--)
		{
			fun_WDF_DEVICE_CONTEXT_CLEANUP(hdevice);
		}
	}
	#endif
#endif

#ifdef fun_WDF_DEVICE_CONTEXT_DESTROY  
	fun_WDF_DEVICE_CONTEXT_DESTROY(hdevice);
	
	#if SDV_HARNESS==SDV_HARNESS_PNP_IO_REQUESTS
	if (hdevcollection_count != 0)
	{
		for (h_i=hdevcollection_count-1; h_i>0; h_i--)
		{
			fun_WDF_DEVICE_CONTEXT_DESTROY(hdevice);
		}
	}
	#endif
#endif


#ifdef fun_WDF_DEVICE_SHUTDOWN_NOTIFICATION
	fun_WDF_DEVICE_SHUTDOWN_NOTIFICATION(hdevice);
#endif

#ifdef fun_WDF_DRIVER_UNLOAD
	fun_WDF_DRIVER_UNLOAD(hdriver);
#endif

	}
}

#endif

/* wdf-pnp-harness.c end */

/* wdf_sdv_stubs.c begin */

/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/


void __cdecl main() 
{
    sdv_main();
}
VOID
sdv_WDF_DRIVER_CONFIG_INIT(
    OUT PWDF_DRIVER_CONFIG Config,
    IN PFN_WDF_DRIVER_DEVICE_ADD EvtDriverDeviceAdd
    )
{
}

WDFAPI
NTSTATUS
sdv_WdfDriverCreate(
    IN           PDRIVER_OBJECT          DriverObject,
    IN           PUNICODE_STRING         RegistryPath,
    IN OPTIONAL  PWDF_OBJECT_ATTRIBUTES  DriverAttributes,
    IN           PWDF_DRIVER_CONFIG      DriverConfig,
    OUT OPTIONAL WDFDRIVER*              Driver
    )
{ 
	int x = SdvMakeChoice();
    switch (x) { 
        case 0: 
	            hdriver = (WDFDRIVER) &notused_4hdriver;
			    *Driver = hdriver;
			    return STATUS_SUCCESS;
#ifdef SLAM_PRECISE_STATUS
        case 1: 
			     hdriver = (WDFDRIVER) &notused_4hdriver;
			    *Driver = hdriver;
			    return STATUS_INVALID_PARAMETER;
        default:
			     hdriver = (WDFDRIVER) &notused_4hdriver;
			    *Driver = hdriver;
			    return STATUS_INSUFFICIENT_RESOURCES;
#else
        default: 
			     hdriver = (WDFDRIVER) &notused_4hdriver;
			     *Driver = hdriver;
			     return STATUS_UNSUCCESSFUL;
#endif
                                      
	}
}

NTSTATUS
sdv_WdfDriverOpenParametersRegistryKey(
    IN WDFDRIVER Driver,
    IN ACCESS_MASK DesiredAccess,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    OUT WDFKEY* Key
    )
{
	*Key = (WDFKEY)malloc(0);
	return sdv_SetReturnStatus();
}

PDRIVER_OBJECT
sdv_WdfDriverWdmGetDriverObject(
    IN WDFDRIVER Driver
	)
{
	return hp_driver;
}
WDFAPI
NTSTATUS
sdv_WdfDeviceCreate(
    IN OUT PWDFDEVICE_INIT* DeviceInit,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES DeviceAttributes,
    OUT WDFDEVICE* Device
    )
{ 
	int x = SdvMakeChoice();
    switch (x) 
	{ 
        case 0: 
			if (*DeviceInit == hdevice_init)
			{
				#ifdef SDV_DEVICE_INIT_NULL
					hdevice_init=NULL;
					*DeviceInit=NULL;
				#endif
				SdvAssume(*DeviceInit == hdevice_init);
				hdevice = (WDFDEVICE) &notused_4hdevice;
                *Device = hdevice;
			
			}
			else
			{
				if (*DeviceInit == hcontrol_deviceinit) 
				{
					#ifdef SDV_DEVICE_INIT_NULL
						hcontrol_deviceinit=NULL;
						*DeviceInit=NULL;
					#endif
					SdvAssume(*DeviceInit == hcontrol_deviceinit);
					hcontrol_device = (WDFDEVICE) &notused_4hcontrol_device;
					*Device = hcontrol_device;
				}
				else if (*DeviceInit == hcontrol_deviceinit1) 
				{
					#ifdef SDV_DEVICE_INIT_NULL
						hcontrol_deviceinit1=NULL;
						*DeviceInit=NULL;
					#endif
					SdvAssume(*DeviceInit == hcontrol_deviceinit1);
					hcontrol_device1 = (WDFDEVICE) &notused_4hcontrol_device1;
					*Device = hcontrol_device1;
				}
				else if (*DeviceInit == hpdo_deviceinit) 
				{
						#ifdef SDV_DEVICE_INIT_NULL
							hpdo_deviceinit=NULL;
							*DeviceInit=NULL;
						#endif
						SdvAssume(*DeviceInit == hpdo_deviceinit);
						hpdo_device = (WDFDEVICE) &notused_4hpdo_device;
						*Device = hpdo_device;
				}
				else
				{
					if (*DeviceInit == hpdo_deviceinit1) 
					{
						#ifdef SDV_DEVICE_INIT_NULL
							hpdo_deviceinit1=NULL;
							*DeviceInit=NULL;
						#endif
						SdvAssume(*DeviceInit == hpdo_deviceinit1);
						hpdo_device1 = (WDFDEVICE) &notused_4hpdo_device1;
						*Device = hpdo_device1;
					}
					
				}
			}
			return STATUS_SUCCESS;
			
#ifdef SLAM_PRECISE_STATUS
        case 1: if (*DeviceInit == hdevice_init)
				{
			    SdvAssume(*DeviceInit == hdevice_init);
				hdevice = (WDFDEVICE) &notused_4hdevice;
                *Device = hdevice;
				}
				else
				{
					if (*DeviceInit == hcontrol_deviceinit) 
					{   
						SdvAssume(*DeviceInit == hcontrol_deviceinit);
						hcontrol_device = (WDFDEVICE) &notused_4hcontrol_device;
						*Device = hcontrol_device;
					}
					else if (*DeviceInit == hcontrol_deviceinit1) 
					{   
						SdvAssume(*DeviceInit == hcontrol_deviceinit1);
						hcontrol_device1 = (WDFDEVICE) &notused_4hcontrol_device1;
						*Device = hcontrol_device1;
					}
					else if (*DeviceInit == hpdo_deviceinit) 
					{
						SdvAssume(*DeviceInit == hpdo_deviceinit);
						hpdo_device = (WDFDEVICE) &notused_4hpdo_device;
						*Device = hpdo_device;
						
					}
					else
					{
						if (*DeviceInit == hpdo_deviceinit1) {
						SdvAssume(*DeviceInit == hpdo_deviceinit1);
						hpdo_device1 = (WDFDEVICE) &notused_4hpdo_device1;
						*Device = hpdo_device1;
						
						}
					}
				}
				return STATUS_INVALID_PARAMETER;
        case 2: if (*DeviceInit == hdevice_init){
			    hdevice = (WDFDEVICE) &notused_4hdevice;
                *Device = hdevice;
				}
				else
				{
					if (*DeviceInit == hcontrol_deviceinit)
					{
						hcontrol_device = (WDFDEVICE) &notused_4hcontrol_device;
						*Device = hcontrol_device;
					}
					else if (*DeviceInit == hcontrol_deviceinit1)
					{
						hcontrol_device1 = (WDFDEVICE) &notused_4hcontrol_device1;
						*Device = hcontrol_device1;
					}
					else if (*DeviceInit == hpdo_deviceinit) 
					{
							hpdo_device = (WDFDEVICE) &notused_4hpdo_device;
							*Device = hpdo_device;
					}
					else
					{
						if (*DeviceInit == hpdo_deviceinit1) {
							hpdo_device1 = (WDFDEVICE) &notused_4hpdo_device1;
							*Device = hpdo_device1;
						}
						
					}
				}
			    return STATUS_INVALID_DEVICE_STATE;
		case 3: if (*DeviceInit == hdevice_init)
				{
					hdevice = (WDFDEVICE) &notused_4hdevice;
					*Device = hdevice;
				}
				else
				{
					if (*DeviceInit == hcontrol_deviceinit) 
					{
						hcontrol_device = (WDFDEVICE) &notused_4hcontrol_device;
						*Device = hcontrol_device;
					}
					else if (*DeviceInit == hcontrol_deviceinit1)
					{
						hcontrol_device1 = (WDFDEVICE) &notused_4hcontrol_device1;
						*Device = hcontrol_device1;
					}
					else if (*DeviceInit == hpdo_deviceinit) 
					{
							hpdo_device = (WDFDEVICE) &notused_4hpdo_device;
							*Device = hpdo_device;
					}
					else
					{
						if (*DeviceInit == hpdo_deviceinit1) 
						{
							hpdo_device1 = (WDFDEVICE) &notused_4hpdo_device1;
							*Device = hpdo_device1;
						
						}
						
					}
				}
			    return STATUS_INVALID_SECURITY_DESCR;
        default: if (*DeviceInit == hdevice_init)
				 {
					hdevice = (WDFDEVICE) &notused_4hdevice;
					*Device = hdevice;
				}
				else
				{
					if (*DeviceInit == hcontrol_deviceinit) 
					{
						hcontrol_device = (WDFDEVICE) &notused_4hcontrol_device;
						*Device = hcontrol_device;
					}
					else if (*DeviceInit == hcontrol_deviceinit1)
					{
						hcontrol_device1 = (WDFDEVICE) &notused_4hcontrol_device1;
						*Device = hcontrol_device1;
					}
					else if (*DeviceInit == hpdo_deviceinit) 
					{
							hpdo_device = (WDFDEVICE) &notused_4hpdo_device;
							*Device = hpdo_device;
					}
					else
					{
						if (*DeviceInit == hpdo_deviceinit1) 
						{
							hpdo_device1 = (WDFDEVICE) &notused_4hpdo_device1;
							*Device = hpdo_device1;
						
						}
					}
				}
			    return STATUS_INSUFFICIENT_RESOURCES;
#else
        default: if (*DeviceInit == hdevice_init)
				{
				SdvAssume(*DeviceInit == hdevice_init);
				hdevice = (WDFDEVICE) &notused_4hdevice;
                *Device = hdevice;
				}
				else
				{
					if (*DeviceInit == hcontrol_deviceinit) 
					{
						SdvAssume(*DeviceInit == hcontrol_deviceinit);
						hcontrol_device = (WDFDEVICE) &notused_4hcontrol_device;
						*Device = hcontrol_device;
					}
					else if (*DeviceInit == hcontrol_deviceinit1) 
					{
						SdvAssume(*DeviceInit == hcontrol_deviceinit1);
						hcontrol_device1 = (WDFDEVICE) &notused_4hcontrol_device1;
						*Device = hcontrol_device1;
					}
					else if (*DeviceInit == hpdo_deviceinit) 
					{
						SdvAssume(*DeviceInit == hpdo_deviceinit);
						hpdo_device = (WDFDEVICE) &notused_4hpdo_device;
						*Device = hpdo_device;
					}
					else
					{
						if (*DeviceInit == hpdo_deviceinit1) 
						{
							SdvAssume(*DeviceInit == hpdo_deviceinit1);
							hpdo_device1 = (WDFDEVICE) &notused_4hpdo_device1;
							*Device = hpdo_device1;
						}
					}
				}
			    return STATUS_UNSUCCESSFUL;
#endif
    }
}
WDFAPI NTSTATUS
sdv_WdfDeviceCreateSymbolicLink(
    IN WDFDEVICE  Device,
    IN PCUNICODE_STRING  SymbolicLinkName
    )
{
	return sdv_SetReturnStatus();
}
WDFAPI
NTSTATUS
sdv_WdfDeviceCreateDeviceInterface(
    IN WDFDEVICE Device,
    IN CONST GUID* InterfaceClassGUID,
    IN OPTIONAL PUNICODE_STRING ReferenceString
    )
{ 
    return sdv_SetReturnStatus(); 
}
WDFAPI WDFDRIVER
sdv_WdfDeviceGetDriver(
   IN WDFDEVICE  Device
   )
{
	return hdriver;
}
WDFQUEUE
sdv_WdfDeviceGetDefaultQueue(
    IN WDFDEVICE Device
    )
{
	return hdefqueue;
}
NTSTATUS
sdv_WdfDeviceOpenRegistryKey(
    IN WDFDEVICE Device,
    IN ULONG DeviceInstanceKeyType,
    IN ACCESS_MASK DesiredAccess,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    OUT WDFKEY* Key
    )
{
	*Key = (WDFKEY)malloc(0);
	return sdv_SetReturnStatus();
}
PVOID
sdv_WdfObjectGet_DEVICE_CONTEXT(
   IN WDFDEVICE Device
   )
{  
	return hdctx;
}
PVOID
sdv_WdfObjectGet_CONTROL_DEVICE_CONTEXT(
   IN WDFDEVICE ControlDevice
   )
{  
	return hdctx;
}
PVOID
sdv_WdfObjectGet_QUEUE_CONTEXT(
   IN WDFQUEUE Queue
   )
{ 
	return hqctx;
}
PVOID
sdv_WdfObjectGet_TIMER_CONTEXT(
   IN WDFTIMER Timer
   )
{  
	return htctx;
}
PVOID
sdv_WdfObjectGet_DRIVER_CONTEXT(
    IN WDFDRIVER Driver
	)
{ 
	return hdrctx;
}
VOID
sdv_WDF_IO_QUEUE_CONFIG_INIT(
    IN PWDF_IO_QUEUE_CONFIG      Config,
    IN WDF_IO_QUEUE_DISPATCH_TYPE DispatchType
    )
{
	Config = (PWDF_IO_QUEUE_CONFIG)malloc(0);
}
VOID
sdv_WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE(
    OUT PWDF_IO_QUEUE_CONFIG      Config,
    IN WDF_IO_QUEUE_DISPATCH_TYPE DispatchType
    )
{
	Config = (PWDF_IO_QUEUE_CONFIG)malloc(0);
}
WDFAPI
NTSTATUS
sdv_WdfIoQueueCreate(
    IN WDFDEVICE Device,
    IN PWDF_IO_QUEUE_CONFIG Config,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES QueueAttributes,
    OUT WDFQUEUE* Queue
    )
{ 
    int x = SdvMakeChoice();
    switch (x) { 
        case 0:  *Queue = hdefqueue;
			     return STATUS_SUCCESS;
#ifdef SLAM_PRECISE_STATUS
        case 1:  
			     *Queue = hdefqueue;
			     return STATUS_INSUFFICIENT_RESOURCES;
        default: 
			     *Queue = hdefqueue;
			     return STATUS_INFO_LENGTH_MISMATCH;
#else
        default: 
			     *Queue = hdefqueue;
			     return STATUS_UNSUCCESSFUL;
#endif
	}
}

WDFDEVICE
sdv_WdfIoQueueGetDevice(
    IN WDFQUEUE Queue
    )
{
	return hdevice;
}
PVOID
sdv_WdfObjectGetTypedContextWorker(
    IN WDFOBJECT Handle,
    IN PCWDF_OBJECT_CONTEXT_TYPE_INFO TypeInfo
    )
{
	return NULL;
}
VOID
sdv_WDF_TIMER_CONFIG_INIT_PERIODIC(
    IN PWDF_TIMER_CONFIG Config,
    IN PFN_WDF_TIMER     EvtTimerFunc,
    IN ULONG             Period
    )
{
}
WDFAPI
NTSTATUS
sdv_WdfTimerCreate(
    IN  PWDF_TIMER_CONFIG            Config,
    IN  PWDF_OBJECT_ATTRIBUTES Attributes,
    OUT WDFTIMER*              Timer
    )
{ 
	int x = SdvMakeChoice();
    switch (x) { 
        case 0: htimer = (WDFTIMER) &notused_4htimer;
			    *Timer = htimer;				
			    return STATUS_SUCCESS;
#ifdef SLAM_PRECISE_STATUS
        case 1: 
			    htimer = (WDFTIMER) &notused_4htimer;
			    *Timer = htimer;
			    return STATUS_INSUFFICIENT_RESOURCES;
        default: 
			    htimer = (WDFTIMER) &notused_4htimer;
			    *Timer = htimer;
			    return STATUS_INVALID_PARAMETER;
#else
        default: 
			    htimer = (WDFTIMER) &notused_4htimer;
			    *Timer = htimer;
			    return STATUS_UNSUCCESSFUL;
#endif
	}
}
BOOLEAN
sdv_WdfTimerStart(
    IN WDFTIMER Timer,
    IN LONGLONG DueTime
    )
{
	return (BOOLEAN) SdvMakeChoice();
}
BOOLEAN
sdv_WdfTimerStop(
    IN WDFTIMER Timer,
    IN BOOLEAN Wait
    )
{
	return (BOOLEAN) SdvMakeChoice();
}
WDFOBJECT
FORCEINLINE
sdv_WdfTimerGetParentObject(
    IN WDFTIMER Timer
    )
{
	return (WDFOBJECT)((HANDLE)((PVOID)((ULONG_PTR) SdvMakeChoice())));
}
VOID
sdv_WDF_WORKITEM_CONFIG_INIT(
    OUT PWDF_WORKITEM_CONFIG Config,
    IN PFN_WDF_WORKITEM     EvtWorkItemFunc
    )
{
	Config = (PWDF_WORKITEM_CONFIG)malloc(0);
}
NTSTATUS
sdv_WdfWorkItemCreate(
    IN PWDF_WORKITEM_CONFIG Config,
	IN OPTIONAL PWDF_OBJECT_ATTRIBUTES Attributes,
    OUT WDFWORKITEM* WorkItem
    )
{
	int x = SdvMakeChoice();
    switch (x) { 
        case 0: hwork_item = (WDFWORKITEM) &notused_4hwork_item;
			    *WorkItem = hwork_item;				
			    return STATUS_SUCCESS;
		default: 
			    hwork_item = (WDFWORKITEM) &notused_4hwork_item;
			    *WorkItem = hwork_item;
			    return STATUS_UNSUCCESSFUL;
	}
}
VOID
sdv_WdfWorkItemEnqueue(
    IN WDFWORKITEM WorkItem
    )
{
}
VOID
sdv_WDF_DPC_CONFIG_INIT(
    IN PWDF_DPC_CONFIG Config,
    IN PFN_WDF_DPC     EvtDpcFunc
    )
{
}
NTSTATUS
sdv_WdfDpcCreate(
    IN PWDF_DPC_CONFIG Config,
    IN PWDF_OBJECT_ATTRIBUTES Attributes,
    OUT WDFDPC* Dpc)
{
	int x = SdvMakeChoice();
    switch (x) { 
        case 0: hdpc = (WDFDPC) &notused_4hdpc;
			    *Dpc = hdpc;				
			    return STATUS_SUCCESS;
		default: 
			    hdpc = (WDFDPC) &notused_4hdpc;
			    *Dpc = hdpc;
			    return STATUS_UNSUCCESSFUL;
	}
}
BOOLEAN
sdv_WdfDpcEnqueue(
    IN WDFDPC Dpc
    )
{
	return (BOOLEAN) SdvMakeChoice();
}
BOOLEAN
sdv_WdfDpcCancel(
    IN WDFDPC Dpc,
    IN BOOLEAN Wait
    )
{
	return (BOOLEAN) SdvMakeChoice();
}
size_t
sdv_WdfCommonBufferGetLength(
    IN WDFCOMMONBUFFER CommonBuffer
    )
{ 
  return (size_t) SdvMakeChoice();
}

PHYSICAL_ADDRESS
sdv_WdfCommonBufferGetAlignedLogicalAddress(
    IN WDFCOMMONBUFFER CommonBuffer
    )
{
	PHYSICAL_ADDRESS x = {0};
	return x;
}

PVOID
sdv_WdfCommonBufferGetAlignedVirtualAddress(
    IN WDFCOMMONBUFFER CommonBuffer
	)
{
	return (PVOID) pnotused;
}

NTSTATUS
sdv_WdfCommonBufferCreate(
    IN WDFDMAENABLER DmaEnabler,
    IN size_t Length,
	IN OPTIONAL PWDF_OBJECT_ATTRIBUTES Attributes,
    OUT WDFCOMMONBUFFER* CommonBufferHandle
    )
{
	*CommonBufferHandle = (WDFCOMMONBUFFER)malloc(0);
	return sdv_SetReturnStatus();
}

VOID
sdv_WdfRequestSetCompletionRoutine(
    IN WDFREQUEST Request,
    IN PFN_WDF_REQUEST_COMPLETION_ROUTINE CompletionRoutine,
    IN WDFCONTEXT CompletionContext
    )
{
}

NTSTATUS
sdv_WdfRequestCreate(
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES RequestAttributes,
    IN OPTIONAL WDFIOTARGET IoTarget,
    OUT WDFREQUEST* Request
    )
{
	*Request = (WDFREQUEST) malloc(0);
	return sdv_SetReturnStatus();
}
WDFFILEOBJECT
sdv_WdfRequestGetFileObject(
    IN WDFREQUEST Request
    )
{
	return hfileobj;
}
NTSTATUS
sdv_WdfRequestRetrieveOutputBuffer(
	IN WDFREQUEST Request,
	IN size_t  MinimumRequiredSize,
	OUT PVOID* Buffer,
	OUT size_t* Length
	)
{
	int x = SdvMakeChoice();
	Length = (size_t*)malloc(0);
    switch (x) { 
        case 0:  hbuffer = (PVOID) &notused_4hbuffer;
			     *Buffer = (PVOID) hbuffer;      
			     return STATUS_SUCCESS;
        default: 
			     hbuffer = (PVOID) &notused_4hbuffer;
			     *Buffer = (PVOID) hbuffer;  
			     return STATUS_UNSUCCESSFUL;
	}
}

NTSTATUS
sdv_WdfRequestRetrieveInputBuffer(
    IN WDFREQUEST Request,
    IN size_t  MinimumRequiredSize,
    OUT PVOID* Buffer,
    OUT size_t* Length
    )
{
	int x = SdvMakeChoice();
	Length = (size_t*)malloc(0);
    switch (x) { 
        case 0:  hbuffer = (PVOID) &notused_4hbuffer;
			     *Buffer = (PVOID) hbuffer;      
			     return STATUS_SUCCESS;
        default: 
			     hbuffer = (PVOID) &notused_4hbuffer;
			     *Buffer = (PVOID) hbuffer;
			     return STATUS_UNSUCCESSFUL;
	}
}
NTSTATUS
sdv_WdfRequestRetrieveUnsafeUserInputBuffer(
    IN WDFREQUEST Request,
    IN size_t MinimumRequiredLength,
    OUT PVOID* InputBuffer,
    OUT OPTIONAL size_t* Length
    )
{
	int x = SdvMakeChoice();
	Length = (size_t*)malloc(0);
    switch (x) { 
        case 0:  hbuffer = (PVOID) &notused_4hbuffer;
			     *InputBuffer = (PVOID) hbuffer;      
			     return STATUS_SUCCESS;
        default: 
			     hbuffer = (PVOID) &notused_4hbuffer;
			     *InputBuffer = (PVOID) hbuffer;
			     return STATUS_UNSUCCESSFUL;
	}
}
NTSTATUS
sdv_WdfRequestRetrieveUnsafeUserOutputBuffer(
    IN WDFREQUEST Request,
    IN size_t MinimumRequiredLength,
    OUT PVOID* OutputBuffer,
    OUT OPTIONAL size_t* Length
    )
{
	int x = SdvMakeChoice();
	Length = (size_t*)malloc(0);
    switch (x) { 
        case 0:  hbuffer = (PVOID) &notused_4hbuffer;
			     *OutputBuffer = (PVOID) hbuffer;      
			     return STATUS_SUCCESS;
        default: 
			     hbuffer = (PVOID) &notused_4hbuffer;
			     *OutputBuffer = (PVOID) hbuffer;
			     return STATUS_UNSUCCESSFUL;
	}
}
NTSTATUS
sdv_WdfRequestRetrieveOutputMemory(
	IN WDFREQUEST Request,
	OUT WDFMEMORY* Memory
	)
{

	int x = SdvMakeChoice();
    switch (x) { 
        case 0:  hmemory = (WDFMEMORY) &notused_4hmemory;
			     *Memory = hmemory;      
			     return STATUS_SUCCESS;
        default: 
			     hmemory = (WDFMEMORY) &notused_4hmemory;
			     *Memory = hmemory; 
			     return STATUS_NOT_SUPPORTED;
	}
}

NTSTATUS
sdv_WdfRequestRetrieveInputMemory(
	IN WDFREQUEST Request,
	OUT WDFMEMORY* Memory
	)
{
	int x = SdvMakeChoice();
    switch (x) { 
        case 0:  hmemory = (WDFMEMORY) &notused_4hmemory;
			     *Memory = hmemory;      
			     return STATUS_SUCCESS;
        default: 
			     hmemory = (WDFMEMORY) &notused_4hmemory;
			     *Memory = hmemory;
			     return STATUS_NOT_SUPPORTED;
	}
}

NTSTATUS
sdv_WdfRequestRetrieveOutputWdmMdl(
	IN WDFREQUEST Request,
	OUT PMDL* Mdl
	)
{
	int x = SdvMakeChoice();
    switch (x) { 
        case 0:  hmdl = (PMDL) &notused_4hmdl;
			     *Mdl = hmdl;      
			     return STATUS_SUCCESS;
        default: 
			     hmdl = (PMDL) &notused_4hmdl;
			     *Mdl = hmdl;
			     return STATUS_NOT_SUPPORTED;
	}
}

NTSTATUS
sdv_WdfRequestRetrieveInputWdmMdl(
	IN WDFREQUEST Request,
	OUT PMDL* Mdl
	)
{
	int x = SdvMakeChoice();
    switch (x) { 
        case 0:  hmdl = (PMDL) &notused_4hmdl;
			     *Mdl = hmdl;      
			     return STATUS_SUCCESS;
        default: 
			     hmdl = (PMDL) &notused_4hmdl;
			     *Mdl = hmdl; 
			     return STATUS_NOT_SUPPORTED;
	}
	
}
PVOID
sdv_WdfMemoryGetBuffer(
    IN WDFMEMORY Memory,
    OUT OPTIONAL size_t* BufferSize
    )
{
	BufferSize = (size_t*)malloc(0);
	return (PVOID) pnotused;
}
VOID
sdv_WDF_MEMORY_DESCRIPTOR_INIT_HANDLE(
    OUT PWDF_MEMORY_DESCRIPTOR Descriptor,
    IN WDFMEMORY Memory,
    IN OPTIONAL PWDFMEMORY_OFFSET Offsets
    )
{
	Descriptor = (PWDF_MEMORY_DESCRIPTOR)malloc(0);
}
VOID
sdv_WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(
    OUT PWDF_MEMORY_DESCRIPTOR Descriptor,
    IN PVOID Buffer,
    IN ULONG BufferLength
    )
{
	Descriptor = (PWDF_MEMORY_DESCRIPTOR)malloc(0);
}

NTSTATUS
sdv_WdfMemoryCreate(
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES Attributes,
    IN POOL_TYPE PoolType,
    IN OPTIONAL ULONG PoolTag,
    IN size_t BufferSize,
    OUT WDFMEMORY* Memory,
    OUT OPTIONAL PVOID* Buffer
    )
{
	* Memory = (WDFMEMORY)malloc(0);
    return sdv_SetReturnStatus();	
}
NTSTATUS
sdv_WdfMemoryCreatePreallocated(
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES Attributes,
    IN PVOID Buffer,
    IN size_t BufferSize,
    OUT WDFMEMORY* Memory
    )
{
	* Memory = (WDFMEMORY)malloc(0);
	return sdv_SetReturnStatus();
}

NTSTATUS
sdv_WdfMemoryAssignBuffer(
    IN WDFMEMORY Memory,
    IN PVOID Buffer,
    IN size_t BufferSize
    )
{
	return sdv_SetReturnStatus();
}

NTSTATUS
sdv_WdfMemoryCopyFromBuffer(
    IN WDFMEMORY DestinationMemory,
    IN size_t DestinationOffset,
    IN PVOID Buffer,
    IN size_t NumBytesToCopyFrom
    )
{
	return sdv_SetReturnStatus();
}

NTSTATUS
sdv_WdfMemoryCopyToBuffer(
    IN WDFMEMORY SourceMemory,
    IN size_t SourceOffset,
    IN OUT PVOID Buffer,
    IN size_t NumBytesToCopyTo
    )
{
	return sdv_SetReturnStatus();
}

VOID
sdv_WDF_MEMORY_DESCRIPTOR_INIT_MDL(
    OUT PWDF_MEMORY_DESCRIPTOR Descriptor,
    IN PMDL Mdl,
    IN ULONG BufferLength
    )
{
	Descriptor = (PWDF_MEMORY_DESCRIPTOR)malloc(0);
}

NTSTATUS
sdv_WdfDmaTransactionInitialize(
    IN WDFDMATRANSACTION DmaTransaction,
    IN PFN_WDF_PROGRAM_DMA EvtProgramDmaFunction,
    IN WDF_DMA_DIRECTION DmaDirection,
    IN PMDL Mdl,
    IN PVOID VirtualAddress,
    IN size_t  Length
    )
{
	return sdv_SetReturnStatus();
}

NTSTATUS
sdv_WdfDmaTransactionCreate(
    IN WDFDMAENABLER DmaEnabler,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES Attributes,
    OUT WDFDMATRANSACTION* DmaTransaction
    )
{
	* DmaTransaction = (WDFDMATRANSACTION)malloc(0);
	return sdv_SetReturnStatus();
}

WDFDEVICE
sdv_WdfDmaTransactionGetDevice(
    IN WDFDMATRANSACTION DmaTransaction
    )
{
	return (WDFDEVICE) pnotused;
}

size_t
sdv_WdfDmaTransactionGetCurrentDmaTransferLength(
    __in
    WDFDMATRANSACTION DmaTransaction
    )
{
	return (size_t) SdvMakeChoice();
}

WDFREQUEST
sdv_WdfDmaTransactionGetRequest(
    IN WDFDMATRANSACTION DmaTransaction
    )
{
	return (WDFREQUEST) pnotused;
}

VOID
sdv_WdfDmaTransactionSetMaximumLength(
    IN WDFDMATRANSACTION DmaTransaction,
    IN size_t MaximumLength
    )
{
}

size_t
sdv_WdfDmaTransactionGetBytesTransferred(
    IN WDFDMATRANSACTION DmaTransaction
    )
{
	return (size_t) SdvMakeChoice();
}

BOOLEAN
sdv_WdfDmaTransactionDmaCompletedFinal(
    IN WDFDMATRANSACTION DmaTransaction,
    IN size_t FinalTransferredLength,
    OUT NTSTATUS* Status
    )
{
	*Status = ((NTSTATUS)(ULONG_PTR)malloc(0));
	return (BOOLEAN) SdvMakeChoice();
}

BOOLEAN
sdv_WdfDmaTransactionDmaCompletedWithLength(
    IN WDFDMATRANSACTION DmaTransaction,
    IN size_t TransferredLength,
    OUT NTSTATUS* Status
    )
{
	*Status = ((NTSTATUS)(ULONG_PTR)malloc(0));
	return (BOOLEAN) SdvMakeChoice();
}

BOOLEAN
sdv_WdfDmaTransactionDmaCompleted(
    IN WDFDMATRANSACTION DmaTransaction,
    OUT NTSTATUS* Status
    )
{
	*Status = ((NTSTATUS)(ULONG_PTR)malloc(0));
	return (BOOLEAN) SdvMakeChoice();
}

NTSTATUS
sdv_WdfDmaTransactionRelease(
    IN WDFDMATRANSACTION DmaTransaction
    )
{
	return sdv_SetReturnStatus();
}


NTSTATUS
sdv_WdfDmaTransactionExecute(
    IN WDFDMATRANSACTION DmaTransaction,
    IN OPTIONAL PVOID Context
	)
{
    return sdv_SetReturnStatus();
}

NTSTATUS
sdv_WdfDmaTransactionInitializeUsingRequest(
    IN WDFDMATRANSACTION DmaTransaction,
    IN WDFREQUEST Request,
    IN PFN_WDF_PROGRAM_DMA EvtProgramDmaFunction,
    IN WDF_DMA_DIRECTION DmaDirection
    )
{
	return sdv_SetReturnStatus();
}

VOID
sdv_WdfDmaEnablerSetMaximumScatterGatherElements(
    IN WDFDMAENABLER DmaEnabler,
    IN size_t MaximumFragments
    )
{
}

size_t
sdv_WdfDmaEnablerGetMaximumScatterGatherElements(
    IN WDFDMAENABLER DmaEnabler
    )
{
	return (size_t) SdvMakeChoice();
}

size_t
sdv_WdfDmaEnablerGetMaximumLength(
    IN WDFDMAENABLER DmaEnabler
    )
{
	return (size_t) SdvMakeChoice();
}

NTSTATUS
sdv_WdfDmaEnablerCreate(
    IN WDFDEVICE Device,
    IN PWDF_DMA_ENABLER_CONFIG Config,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES Attributes,
    OUT WDFDMAENABLER* DmaEnablerHandle
    )
{
	* DmaEnablerHandle = (WDFDMAENABLER)malloc(0);
	return sdv_SetReturnStatus();
}

VOID
sdv_WDF_DMA_ENABLER_CONFIG_INIT(
    IN  PWDF_DMA_ENABLER_CONFIG  Config,
    IN  WDF_DMA_PROFILE          Profile,
    IN  size_t                   MaximumLength
    )
{
}
NTSTATUS
sdv_WdfRegistryAssignULong(
    IN WDFKEY Key,
    IN PCUNICODE_STRING ValueName,
    IN ULONG Value
    )
{
	return sdv_SetReturnStatus();
}


NTSTATUS
sdv_WdfRegistryAssignString(
    IN WDFKEY Key,
    IN PCUNICODE_STRING ValueName,
    IN WDFSTRING String
    )
{
	return sdv_SetReturnStatus();
}

NTSTATUS
sdv_WdfRegistryAssignMultiString(
    IN WDFKEY Key,
    IN PCUNICODE_STRING ValueName,
    IN WDFCOLLECTION StringsCollection
	)
{
	return sdv_SetReturnStatus();
}

NTSTATUS
sdv_WdfRegistryAssignMemory(
    IN WDFKEY Key,
    IN PCUNICODE_STRING ValueName,
    IN ULONG ValueType,
    IN WDFMEMORY Memory,
    IN OPTIONAL PWDFMEMORY_OFFSET MemoryOffsets
    )
{
	return sdv_SetReturnStatus();
}

NTSTATUS
sdv_WdfRegistryAssignValue(
    IN WDFKEY Key,
    IN PCUNICODE_STRING ValueName,
    IN ULONG ValueType,
    IN ULONG ValueLength,
    IN PVOID Value
    )
{
	return sdv_SetReturnStatus();
}

NTSTATUS
sdv_WdfRegistryQueryULong(
    IN WDFKEY Key,
    IN PCUNICODE_STRING ValueName,
    OUT PULONG Value
    )
{
	Value = ((PULONG)((ULONG_PTR) SdvMakeChoice()));
	return sdv_SetReturnStatus();
}

NTSTATUS
sdv_WdfRegistryQueryString(
    IN WDFKEY Key,
    IN PCUNICODE_STRING ValueName,
    OUT PCUNICODE_STRING Value
    )
{
	Value = ((PCUNICODE_STRING)(PLONG)(ULONG_PTR)SdvMakeChoice());
	return sdv_SetReturnStatus();
}
VOID
sdv_WdfRegistryClose(
    IN WDFKEY Key
    )
{
	
}
VOID
sdv_WDF_OBJECT_ATTRIBUTES_INIT(
    IN PWDF_OBJECT_ATTRIBUTES Attributes
    )
{
}

VOID
sdv_WdfObjectReference(
    IN WDFOBJECT Handle)
{
	
}

VOID
sdv_WdfObjectDereference(
    IN WDFOBJECT Handle)
{
	
}

WDFAPI
VOID
sdv_WdfRequestComplete(
   IN  WDFREQUEST Request,
   IN  NTSTATUS  RequestStatus
   )
{
	if (Request == hrequest) {
		if (reqpresented == 1) reqcompleted = 1;}
	if (Request == hrequest1) {           
	          if (reqpresented1 == 1) reqcompleted1 = 1;}
	
}

WDFAPI
VOID
sdv_WdfRequestCompleteWithInformation(
   IN  WDFREQUEST Request,
   IN  NTSTATUS  RequestStatus,
   IN ULONG_PTR Information
   )
{
    if (Request == hrequest) {
		if (reqpresented == 1) reqcompleted = 1;}
	if (Request == hrequest1) {           
	          if (reqpresented1 == 1) reqcompleted1 = 1;}
	
}

VOID
sdv_WdfRequestCompleteWithPriorityBoost(
    IN WDFREQUEST Request,
    IN NTSTATUS Status,
    IN CCHAR PriorityBoost
    )
{
    if (Request == hrequest) {
		if (reqpresented == 1) reqcompleted = 1;}
	if (Request == hrequest1) {           
	          if (reqpresented1 == 1) reqcompleted1 = 1;}
	
}

VOID
sdv_WDF_REQUEST_PARAMETERS_INIT(
    OUT PWDF_REQUEST_PARAMETERS Parameters
    )
{
	Parameters = (PWDF_REQUEST_PARAMETERS)malloc(0);
}

VOID
sdv_WdfRequestGetParameters(
    IN WDFREQUEST Request,
    OUT PWDF_REQUEST_PARAMETERS Parameters
    )
{
	Parameters = (PWDF_REQUEST_PARAMETERS)malloc(0);
}

VOID
sdv_WdfRequestMarkCancelable(
    IN WDFREQUEST Request,
    IN PFN_WDF_REQUEST_CANCEL EvtRequestCancel
    )
{
}

NTSTATUS
sdv_WdfRequestUnmarkCancelable(
    IN WDFREQUEST Request
    )
{
	LONG choice = SdvMakeChoice();

    switch(choice) {
        case 0:
            return (NTSTATUS) STATUS_NOT_SUPPORTED;
            break;
        case 1:
			return (NTSTATUS) STATUS_CANCELLED;
			break;
        default:
            return (NTSTATUS) STATUS_SUCCESS;
            break;
	}
}

BOOLEAN
sdv_WdfRequestIsCanceled(
    IN WDFREQUEST Request
    )
{
	return (BOOLEAN) SdvMakeChoice();
}

WDFAPI
BOOLEAN
sdv_WdfRequestSend(
    IN WDFREQUEST Request,
    IN WDFIOTARGET Target,
    IN OPTIONAL PWDF_REQUEST_SEND_OPTIONS RequestOptions
    )
{
	return (BOOLEAN) SdvMakeChoice();
}
NTSTATUS
sdv_WdfRequestGetStatus(
    IN WDFREQUEST Request
    )
{
	return sdv_SetReturnStatus();
}
WDFQUEUE
sdv_WdfRequestGetIoQueue(
    IN WDFREQUEST Request
    )
{
	return hdefqueue;
}
WDFAPI
NTSTATUS
sdv_WdfIoTargetSendReadSynchronously (
    IN WDFIOTARGET IoTarget,
    IN OPTIONAL WDFREQUEST Request,
    IN OPTIONAL PWDF_MEMORY_DESCRIPTOR OutputBuffer,
    IN OPTIONAL PLONGLONG  DeviceOffset,
    IN OPTIONAL PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    OUT OPTIONAL PULONG_PTR BytesRead
    )
{
	BytesRead = (PULONG_PTR)malloc(0);
	return sdv_SetReturnStatus();
}
WDFAPI
NTSTATUS
sdv_WdfIoTargetSendWriteSynchronously (
    IN WDFIOTARGET IoTarget,
    IN OPTIONAL WDFREQUEST Request,
    IN OPTIONAL PWDF_MEMORY_DESCRIPTOR InputBuffer,
    IN OPTIONAL PLONGLONG DeviceOffset,
    IN OPTIONAL PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    OUT OPTIONAL PULONG_PTR BytesWritten
    )
{
	BytesWritten = (PULONG_PTR)malloc(0);
	return sdv_SetReturnStatus();
}
WDFAPI
NTSTATUS
sdv_WdfIoTargetSendIoctlSynchronously (
    IN WDFIOTARGET IoTarget,
    IN OPTIONAL WDFREQUEST Request,
    IN ULONG IoctlCode,
    IN OPTIONAL PWDF_MEMORY_DESCRIPTOR InputBuffer,
    IN OPTIONAL PWDF_MEMORY_DESCRIPTOR OutputBuffer,
    IN OPTIONAL PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    OUT OPTIONAL PULONG_PTR BytesReturned
    )
{
	BytesReturned = (PULONG_PTR)malloc(0);
	return sdv_SetReturnStatus();
}
WDFAPI
NTSTATUS
sdv_WdfIoTargetSendInternalIoctlSynchronously (
    IN WDFIOTARGET IoTarget,
    IN OPTIONAL WDFREQUEST Request,
    IN ULONG IoctlCode,
    IN OPTIONAL PWDF_MEMORY_DESCRIPTOR InputBuffer,
    IN OPTIONAL PWDF_MEMORY_DESCRIPTOR OutputBuffer,
    IN OPTIONAL PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    OUT OPTIONAL PULONG_PTR BytesReturned
    )
{
	BytesReturned = (PULONG_PTR)malloc(0);
	return sdv_SetReturnStatus();
}
WDFAPI
NTSTATUS
sdv_WdfIoTargetSendInternalIoctlOthersSynchronously (
    IN WDFIOTARGET IoTarget,
    IN OPTIONAL WDFREQUEST Request,
    IN ULONG IoctlCode,
    IN OPTIONAL PVOID OtherArg1,
    IN OPTIONAL PVOID OtherArg2,
    IN OPTIONAL PVOID OtherArg4,
    IN OPTIONAL PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    OUT PULONG_PTR BytesReturned
    )
{
	BytesReturned = (PULONG_PTR)malloc(0);
	return sdv_SetReturnStatus();
}
VOID
sdv_WdfIoTargetStop(
    OUT WDFIOTARGET IoTarget,
    IN WDF_IO_TARGET_SENT_IO_ACTION  Action
    )
{
	IoTarget = (WDFIOTARGET)malloc(0);
	
}
WDFAPI
NTSTATUS
sdv_WdfDeviceEnqueueRequest(
    IN WDFDEVICE Device,
    IN WDFREQUEST Request
    )
{
	return sdv_SetReturnStatus();
}
NTSTATUS
sdv_WdfRequestForwardToIoQueue(
    IN WDFREQUEST Request,
    IN WDFQUEUE DestinationQueue
    )
{
	return sdv_SetReturnStatus();
}
VOID
sdv_WdfRequestStopAcknowledge(
    IN WDFREQUEST Request,
    IN BOOLEAN Requeue
    )
{
	
}
NTSTATUS
sdv_WdfIoQueueRetrieveRequestByFileObject(
    IN WDFQUEUE Queue,
    IN WDFFILEOBJECT FileObject,
    OUT WDFREQUEST* OutRequest
    )
{
	*OutRequest = (WDFREQUEST)malloc(0);
    return sdv_SetReturnStatus();
}
NTSTATUS
sdv_WdfIoQueueFindRequest(
    IN WDFQUEUE Queue,
    IN WDFREQUEST FoundRequest,
    IN WDFFILEOBJECT FileObject,
    OUT PWDF_REQUEST_PARAMETERS Parameters,
    OUT WDFREQUEST* OutRequest
    )
{
	Parameters = (PWDF_REQUEST_PARAMETERS)malloc(0);
	*OutRequest = (WDFREQUEST)malloc(0);
    return sdv_SetReturnStatus();
}
NTSTATUS
sdv_WdfIoQueueRetrieveFoundRequest(
    IN WDFQUEUE Queue,
    IN WDFREQUEST FoundRequest,
    OUT WDFREQUEST* OutRequest
    )
{
	*OutRequest = (WDFREQUEST)malloc(0);
    return sdv_SetReturnStatus();
}
VOID
sdv_WdfIoQueueDrainSynchronously(
    IN WDFQUEUE Queue
    )
{
}
VOID
sdv_WdfIoQueueDrain(
    IN WDFQUEUE Queue,
    IN PFN_WDF_IO_QUEUE_STATE DrainComplete,
    IN WDFCONTEXT Context
    )
{
}
VOID
sdv_WdfIoQueuePurge(
    WDFQUEUE Queue,
    PFN_WDF_IO_QUEUE_STATE PurgeComplete,
    WDFCONTEXT Context
    )
{
}
NTSTATUS
sdv_WdfIoQueueReadyNotify(
    IN WDFQUEUE Queue,
    IN OPTIONAL PFN_WDF_IO_QUEUE_STATE QueueReady,
    IN OPTIONAL WDFCONTEXT Context
    )
{
	return sdv_SetReturnStatus();
}
NTSTATUS
sdv_WdfIoQueueRetrieveNextRequest(
    IN WDFQUEUE Queue,
    OUT WDFREQUEST* OutRequest
    )
{
	*OutRequest = (WDFREQUEST)malloc(0);
	return sdv_SetReturnStatus();
}
VOID
sdv_WdfIoQueueStart(
    IN WDFQUEUE Queue
    )
{
}
VOID
sdv_WdfIoQueueStop(
    IN WDFQUEUE Queue,
    IN OPTIONAL PFN_WDF_IO_QUEUE_STATE StopComplete,
    IN OPTIONAL WDFCONTEXT Context
    )
{
}
VOID
sdv_WdfIoQueueStopSynchronously(
    IN WDFQUEUE Queue
    )
{
}
WDF_IO_QUEUE_STATE
sdv_WdfIoQueueGetState(
    IN WDFQUEUE Queue,
    OUT OPTIONAL PULONG QueueRequests,
    OUT OPTIONAL PULONG DriverRequests
    )
{
	QueueRequests = (PULONG)malloc(0);
    DriverRequests = (PULONG)malloc(0);
	return (WDF_IO_QUEUE_STATE) SdvMakeChoice();
}
BOOLEAN
sdv_WDF_IO_QUEUE_IDLE(
IN WDF_IO_QUEUE_STATE Status)
{
      return((Status & sdv_WdfIoQueueNoRequests) &&    
        (Status & sdv_WdfIoQueueDriverNoRequests))? TRUE: FALSE;
}
VOID
sdv_WDF_PNPPOWER_EVENT_CALLBACKS_INIT(
    OUT PWDF_PNPPOWER_EVENT_CALLBACKS Callbacks
    )
{
	Callbacks = (PWDF_PNPPOWER_EVENT_CALLBACKS)malloc(0);
}
VOID
sdv_WdfDeviceInitSetPnpPowerEventCallbacks(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PWDF_PNPPOWER_EVENT_CALLBACKS PnpPowerEventCallbacks
    )
{
}
VOID
sdv_WdfDeviceInitSetRequestAttributes(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PWDF_OBJECT_ATTRIBUTES RequestAttributes
    )
{
}
NTSTATUS
sdv_WdfDeviceInitAssignWdmIrpPreprocessCallback(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PFN_WDFDEVICE_WDM_IRP_PREPROCESS EvtDevicePreprocessWdmIrp,
    UCHAR MajorFunction,
    IN OPTIONAL PUCHAR MinorFunctions,
    ULONG NumMinorFunctions
    )
{
	return sdv_SetReturnStatus();
}
VOID
sdv_WdfDeviceInitSetIoInCallerContextCallback(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PFN_WDF_IO_IN_CALLER_CONTEXT EvtIoInCallerContext
    )
{
}
PUNICODE_STRING
sdv_WdfFileObjectGetFileName(
    IN WDFFILEOBJECT FileObject
    )
{
	return (PUNICODE_STRING) pnotused1;
}
WDFAPI VOID
sdv_WdfDeviceInitSetExclusive(
    IN PWDFDEVICE_INIT  DeviceInit,
    IN BOOLEAN  IsExclusive
    )
{
}
NTSTATUS
sdv_WdfDeviceInitAssignName(
	IN PWDFDEVICE_INIT  DeviceInit,
    IN PCUNICODE_STRING  DeviceName
     )
{
	return sdv_SetReturnStatus();
}
WDFAPI VOID
sdv_WdfDeviceInitFree(
    OUT PWDFDEVICE_INIT  DeviceInit
    )
{
	DeviceInit = (PWDFDEVICE_INIT)malloc(0);
}
WDFAPI VOID
sdv_WdfDeviceInitSetPowerPolicyOwnership(
    IN PWDFDEVICE_INIT  DeviceInit,
    IN BOOLEAN  IsPowerPolicyOwner
    )
{
}
VOID
FORCEINLINE
sdv_WdfDeviceInitSetFileObjectConfig(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PWDF_FILEOBJECT_CONFIG  FileObjectConfig,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES FileObjectAttributes
    )
{
}
VOID
sdv_WdfDeviceInitSetPowerPolicyEventCallbacks(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PWDF_POWER_POLICY_EVENT_CALLBACKS PowerPolicyEventCallbacks
    )
{
}
NTSTATUS
sdv_WdfDeviceInitRegisterPnpStateChangeCallback(
    PWDFDEVICE_INIT DeviceInit,
    WDF_DEVICE_PNP_STATE PnpState,
    PFN_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION  EvtDevicePnpStateChange,
    ULONG CallbackTypes
    )
{
	return sdv_SetReturnStatus();
}
NTSTATUS
sdv_WdfDeviceInitRegisterPowerStateChangeCallback(
    PWDFDEVICE_INIT DeviceInit,
    WDF_DEVICE_POWER_STATE PowerState,
    PFN_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION  EvtDevicePowerStateChange,
    ULONG CallbackTypes
    )
{
	return sdv_SetReturnStatus();
}
NTSTATUS
sdv_WdfDeviceInitRegisterPowerPolicyStateChangeCallback(
    PWDFDEVICE_INIT DeviceInit,
    WDF_DEVICE_POWER_POLICY_STATE PowerPolicyState,
	PFN_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION  EvtDevicePowerPolicyStateChange,
    ULONG CallbackTypes
    )
{
	return sdv_SetReturnStatus();
}
VOID
sdv_WdfDeviceInitSetIoType(
    IN PWDFDEVICE_INIT DeviceInit,
    IN WDF_DEVICE_IO_TYPE IoType
    )
{
}
VOID
sdv_WdfDeviceInitSetPowerNotPageable(
    IN PWDFDEVICE_INIT DeviceInit
    )
{
}
VOID
sdv_WdfDeviceInitSetPowerPageable(
    IN PWDFDEVICE_INIT DeviceInit
    )
{
}
VOID
sdv_WdfDeviceInitSetPowerInrush(
    IN PWDFDEVICE_INIT DeviceInit
    )
{
}
VOID
sdv_WdfDeviceInitSetDeviceType(
    IN PWDFDEVICE_INIT DeviceInit,
    IN DEVICE_TYPE DeviceType
    )
{
}
NTSTATUS
sdv_WdfDeviceInitAssignSDDLString(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PCUNICODE_STRING SDDLString
    )
{
	return sdv_SetReturnStatus();
}
VOID
sdv_WdfDeviceInitSetDeviceClass(
    IN PWDFDEVICE_INIT DeviceInit,
    IN CONST GUID* DeviceClassGuid
    )
{
}
VOID
sdv_WdfDeviceInitSetCharacteristics(
    IN PWDFDEVICE_INIT DeviceInit,
    IN ULONG DeviceCharacteristics,
    IN BOOLEAN OrInValues
    )
{
}
PDEVICE_OBJECT
sdv_WdfFdoInitWdmGetPhysicalDevice(
    IN PWDFDEVICE_INIT  DeviceInit
	)
{
	return (p_devobj);
}
VOID
sdv_WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT(
    PWDF_DEVICE_POWER_POLICY_IDLE_SETTINGS Settings,
    WDF_POWER_POLICY_S0_IDLE_CAPABILITIES IdleCaps
    )
{
}
VOID
sdv_WdfFdoInitSetFilter(
    IN PWDFDEVICE_INIT  DeviceInit
	)
{ 
}
NTSTATUS
sdv_WdfFdoInitOpenRegistryKey(
    IN PWDFDEVICE_INIT DeviceInit,
    IN ULONG DeviceInstanceKeyType,
    IN ACCESS_MASK DesiredAccess,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    OUT WDFKEY* Key
    )
{
	*Key = (WDFKEY)malloc(0);
	return sdv_SetReturnStatus();
}
NTSTATUS
sdv_WdfFdoInitQueryProperty(
    IN PWDFDEVICE_INIT DeviceInit,
    IN DEVICE_REGISTRY_PROPERTY DeviceProperty,
    IN ULONG BufferLength,
    OUT PVOID PropertyBuffer,
    OUT PULONG ResultLength
    )
{
	PropertyBuffer = malloc(0);
	ResultLength = (PULONG)malloc(0);
	return sdv_SetReturnStatus();
}
NTSTATUS
sdv_WdfFdoInitAllocAndQueryProperty(
    IN PWDFDEVICE_INIT DeviceInit,
    IN DEVICE_REGISTRY_PROPERTY DeviceProperty,
    IN POOL_TYPE PoolType,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    OUT WDFMEMORY* PropertyMemory
    )
{
	* PropertyMemory = (WDFMEMORY)malloc(0);
	return sdv_SetReturnStatus();
}
VOID
sdv_WdfFdoInitSetEventCallbacks(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PWDF_FDO_EVENT_CALLBACKS FdoEventCallbacks
    )
{
}
VOID
sdv_WdfFdoInitSetDefaultChildListConfig(
    IN OUT PWDFDEVICE_INIT DeviceInit,
    IN PWDF_CHILD_LIST_CONFIG Config,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES DefaultChildListAttributes
    )
{
	DeviceInit = (PWDFDEVICE_INIT)malloc(0);
}
VOID
sdv_WdfPdoInitSetEventCallbacks(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PWDF_PDO_EVENT_CALLBACKS DispatchTable
    )
{
}
NTSTATUS
sdv_WdfPdoInitAssignDeviceID(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PCUNICODE_STRING DeviceID
    )
{
	return sdv_SetReturnStatus();
}
NTSTATUS
sdv_WdfPdoInitAssignInstanceID(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PCUNICODE_STRING InstanceID
    )
{
	return sdv_SetReturnStatus();
}
NTSTATUS
sdv_WdfPdoInitAddHardwareID(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PCUNICODE_STRING HardwareID
    )
{
	return sdv_SetReturnStatus();
}
NTSTATUS
sdv_WdfPdoInitAddCompatibleID(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PCUNICODE_STRING CompatibleID
    )
{
	return sdv_SetReturnStatus();
}
NTSTATUS
sdv_WdfPdoInitAddDeviceText(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PCUNICODE_STRING DeviceDescription,
    IN PCUNICODE_STRING DeviceLocation,
    IN LCID LocaleId
    )
{
	return sdv_SetReturnStatus();
}
VOID
sdv_WdfPdoInitSetDefaultLocale(
    IN PWDFDEVICE_INIT DeviceInit,
    IN LCID LocaleId
    )
{
}
NTSTATUS
sdv_WdfPdoInitAssignRawDevice(
    IN PWDFDEVICE_INIT DeviceInit,
    IN CONST GUID* DeviceClassGuid
    )
{
	return sdv_SetReturnStatus();
}
NTSTATUS
sdv_WdfDeviceAssignS0IdleSettings(
    WDFDEVICE Device,
    PWDF_DEVICE_POWER_POLICY_IDLE_SETTINGS Settings
    )
{
	return sdv_SetReturnStatus();
}
VOID
sdv_WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS_INIT(
    PWDF_DEVICE_POWER_POLICY_WAKE_SETTINGS Settings
    )
{
}
NTSTATUS
sdv_WdfDeviceAssignSxWakeSettings(
    WDFDEVICE Device,
    PWDF_DEVICE_POWER_POLICY_WAKE_SETTINGS Settings
    )
{
	return sdv_SetReturnStatus();
}
VOID
sdv_WDF_POWER_POLICY_EVENT_CALLBACKS_INIT(
    PWDF_POWER_POLICY_EVENT_CALLBACKS Callbacks
    )
{
}
NTSTATUS
sdv_WdfCollectionCreate(
	IN OPTIONAL PWDF_OBJECT_ATTRIBUTES CollectionAttributes,
    OUT WDFCOLLECTION *Collection
	)
{
	*Collection = (WDFCOLLECTION)malloc(0);
	return sdv_SetReturnStatus();
}
WDFOBJECT
sdv_WdfCollectionGetFirstItem(
    WDFCOLLECTION Collection
    )
{
	return ((WDFOBJECT) &notused_4wdfobject1);
}
WDFOBJECT
sdv_WdfCollectionGetItem(
    IN WDFCOLLECTION Collection,
    IN ULONG Index
    )
{
	return ((WDFOBJECT) &notused_4wdfobject1);
}
WDFAPI NTSTATUS
sdv_WdfCollectionAdd(
    IN WDFCOLLECTION Collection,
    IN WDFOBJECT Object
    )
{ 
	int x = SdvMakeChoice();
	switch (x) { 
        case 0: 
	           hdevcollection_count += 1;
			   return STATUS_SUCCESS;
        default: 
			     hdevcollection_count = 0;
			     return STATUS_UNSUCCESSFUL;
	}
}
VOID
sdv_WdfCollectionRemoveItem(
    IN WDFCOLLECTION Collection,
    IN WDFOBJECT Item
    )
{
	int x = SdvMakeChoice();
	switch (x) { 
        case 0: 
	           hdevcollection_count -= 1;
        default: 
			     hdevcollection_count = 0;
	}
}
WDFAPI ULONG
sdv_WdfCollectionGetCount(
    IN WDFCOLLECTION Collection
    )
{
	return (ULONG) hdevcollection_count;
}
VOID
sdv_WdfObjectDelete(
    IN WDFOBJECT Object
    )
{
}
NTSTATUS
sdv_WdfFdoQueryForInterface(
    IN WDFDEVICE Device,
    IN LPCGUID InterfaceType,
    IN OUT PINTERFACE Interface,
    IN USHORT Size,
    IN USHORT Version,
    IN OUT PVOID InterfaceSpecificData
    )
{
	Interface = (PVOID)malloc(0);
	return sdv_SetReturnStatus();
}
VOID
sdv_WDF_DEVICE_STATE_INIT(
    OUT PWDF_DEVICE_STATE PnpDeviceState
    )
{
	PnpDeviceState = (PWDF_DEVICE_STATE)malloc(0);
}
VOID
sdv_WdfDeviceSetDeviceState(
    IN WDFDEVICE Device,
    IN PWDF_DEVICE_STATE DeviceState
    )
{
}
NTSTATUS
sdv_WdfDeviceAssignMofResourceName(
    IN WDFDEVICE Device,
    IN PCUNICODE_STRING MofResourceName
    )
{
	return sdv_SetReturnStatus();
}
PDEVICE_OBJECT
sdv_WdfDeviceWdmGetDeviceObject(
    IN WDFDEVICE Device
    )
{
	return ((PDEVICE_OBJECT) pnotused);
}
PDEVICE_OBJECT
sdv_WdfDeviceWdmGetPhysicalDevice(
    IN WDFDEVICE Device
    )
{
	return ((PDEVICE_OBJECT) pnotused);
}
#ifndef init_free
WDFAPI 
PWDFDEVICE_INIT
sdv_WdfControlDeviceInitAllocate(
    IN WDFDRIVER  Driver,
    IN CONST UNICODE_STRING*  SDDLString
    )
{
	int x = SdvMakeChoice();
    switch (x) { 
       case 0: hcontrol_deviceinit = (PWDFDEVICE_INIT) &notused_4hcontrol_deviceinit;
	           return (hcontrol_deviceinit); 		    
		default: 
			    hcontrol_deviceinit = (PWDFDEVICE_INIT) &notused_4hcontrol_deviceinit;
                return (hcontrol_deviceinit);
	}
}
#endif

#ifdef init_free
WDFAPI 
PWDFDEVICE_INIT
sdv_WdfControlDeviceInitAllocate(
    IN WDFDRIVER  Driver,
    IN CONST UNICODE_STRING*  SDDLString
    )
{
	if(control==0)
	{
		control=1;
		return (hcontrol_deviceinit);
	}
	else if(control==1)
	{
		control++;
		return (hcontrol_deviceinit1);
	}
	else 
	{
		control++;
		return (hcontrol_deviceinit2_notused);
	}
}
#endif

VOID
sdv_WdfControlDeviceInitSetShutdownNotification(
    IN PWDFDEVICE_INIT DeviceInit,
    IN PFN_WDF_DEVICE_SHUTDOWN_NOTIFICATION Notification,
    IN UCHAR Flags
    )
{
}
#ifdef init_free
PWDFDEVICE_INIT
sdv_WdfPdoInitAllocate(
IN WDFDEVICE ParentDevice
)
{
	if(pdo==0)
	{
		pdo=1;
		return (hpdo_deviceinit);
		
	}
	else if(pdo==1)
	{
		pdo++;
		return (hpdo_deviceinit1);
	}
	else 
	{
		pdo++;
		return (hpdo_deviceinit2_notused);
	}
	
}

#endif

#ifndef init_free
PWDFDEVICE_INIT
sdv_WdfPdoInitAllocate(
    IN WDFDEVICE ParentDevice
    )
{
	int x = SdvMakeChoice();
    switch (x) { 
       case 0: hpdo_deviceinit = (PWDFDEVICE_INIT) &notused_4hpdo_deviceinit;
	           return (hpdo_deviceinit); 		    
		default: 
			    hpdo_deviceinit = (PWDFDEVICE_INIT) &notused_4hpdo_deviceinit;
                return (hpdo_deviceinit);
	}
}
#endif
VOID
sdv_WdfControlFinishInitializing(
    WDFDEVICE Device
    )
{
}
VOID
sdv_WDF_INTERRUPT_CONFIG_INIT(
    OUT PWDF_INTERRUPT_CONFIG Configuration,
    IN  PFN_WDF_INTERRUPT_ISR EvtInterruptIsr,
    IN  PFN_WDF_INTERRUPT_DPC EvtInterruptDpc
    )
{
	Configuration = (PWDF_INTERRUPT_CONFIG)malloc(0);
}
NTSTATUS
sdv_WdfInterruptCreate(
    IN WDFDEVICE Device,
    IN PWDF_INTERRUPT_CONFIG Configuration,
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES Attributes,
    OUT WDFINTERRUPT* Interrupt
    )
{
	int x = SdvMakeChoice();
    switch (x) { 
        case 0: hinterrupt = (WDFINTERRUPT) &notused_4hinterrupt;
			    *Interrupt = hinterrupt;				
			    return STATUS_SUCCESS;
		default: 
			     hinterrupt = (WDFINTERRUPT) &notused_4hinterrupt;
			     *Interrupt = hinterrupt;
			     return STATUS_UNSUCCESSFUL;
	}
}
BOOLEAN
sdv_WdfInterruptSynchronize(
    IN WDFINTERRUPT Interrupt,
    IN PFN_WDF_INTERRUPT_SYNCHRONIZE Callback,
    IN WDFCONTEXT Context
    )
{
	return (BOOLEAN) SdvMakeChoice();
}

NTSTATUS
sdv_WdfSpinLockCreate(
    IN OPTIONAL PWDF_OBJECT_ATTRIBUTES SpinLockAttributes,
    OUT WDFSPINLOCK* SpinLock
    )
{
	* SpinLock = (WDFSPINLOCK)malloc(0);
	return sdv_SetReturnStatus();
}
VOID
sdv_WdfSpinLockAcquire(
    IN WDFSPINLOCK SpinLock
    )
{
}
VOID
sdv_WdfSpinLockRelease(
    IN WDFSPINLOCK SpinLock
    )
{
}
VOID
sdv_WdfObjectAcquireLock(
    IN WDFOBJECT Object
    )
{
}
VOID
sdv_WdfObjectReleaseLock(
    IN WDFOBJECT Object
    )
{
}
VOID
sdv_WPP_INIT_TRACING(
	 IN PDRIVER_OBJECT DriverObject,
     IN PUNICODE_STRING RegistryPath
           )
{
}
VOID
sdv_WdfStringGetUnicodeString(
    IN WDFSTRING String,
    PUNICODE_STRING UnicodeString
    )
{
}
WDF_DEVICE_POWER_STATE
sdv_WdfDeviceGetDevicePowerState(
    __in WDFDEVICE Device
    )
{
	return sdv_SetDevicePowerPolicyState();
}
WDF_DEVICE_POWER_POLICY_STATE
sdv_WdfDeviceGetDevicePowerPolicyState(
    __in WDFDEVICE Device
    )
{
	return sdv_SetDevicePowerPolicyState();
}
VOID
sdv_WdfDeviceSetPowerCapabilities(
    __in WDFDEVICE Device,
    __in PWDF_DEVICE_POWER_CAPABILITIES PowerCapabilities
    )
{
}
WDFDEVICE
sdv_WdfWdmDeviceGetWdfDeviceHandle(
    IN PDEVICE_OBJECT DeviceObject
    )
{
	return hdevice;
}
void 
sdv_save_request(void *r)
{

}
void 
sdv_retrieve_request(void *r)
{
	r=(void *)(WDFREQUEST)hrequest;
}
NTSTATUS  
sdv_WdfDeviceWdmDispatchPreprocessedIrp(WDFDEVICE  Device,PIRP  Irp)
{
	return sdv_SetReturnStatus(); 
}


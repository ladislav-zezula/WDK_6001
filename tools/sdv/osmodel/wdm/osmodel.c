/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

/* harness-copyright.c begin */
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
/* harness-copyright.c end */

/* malloc.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

char * malloc(int);
/* malloc.c end */

/* harness-parts.c begin */
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

/* harness-parts.c end */

/* flat-harness.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

/*****************************************************************************

    flat-harness.c provides a flat harness for exercising a driver.

    The flat harness is useful for checking issues that are of a local
    nature, for example IRQL checking, simple resource allocation and
    synchronization primitives.

    The flat harness only calls the driver once.  For a more complete
    and realistic harness that calls the driver repeatedly see the PNP
    harness in pnp-harness.c

    The following variations of the flat harness are available:
        SDV_FLAT_DISPATCH_HARNESS
        SDV_FLAT_DISPATCH_STARTIO_HARNESS
        SDV_FLAT_SIMPLE_HARNESS
        SDV_FLAT_HARNESS

    The harnesses exercises the driver as follows:
        SDV_FLAT_DISPATCH_HARNESS =
            DoNothing ||
            sdv_RunDispatchFunction

        SDV_FLAT_DISPATCH_STARTIO_HARNESS =
            SDV_FLAT_DISPATCH_HARNESS ||
            sdv_RunStartIo

        SDV_FLAT_SIMPLE_HARNESS =
            SDV_FLAT_DISPATCH_STARTIO_HARNESS ||
            sdv_RunDPC ||
            sdv_RunISR ||
            sdv_RunCancelRoutine

        SDV_FLAT_HARNESS =
            SDV_FLAT_SIMPLE_HARNESS ||
            DriverEntry ||
            sdv_RunAddDevice ||
            sdv_RunStartDevice
            sdv_RunRemoveDevice ||
            sdv_RunUnload

*****************************************************************************/

#define SDV_IS_FLAT_HARNESS() \
    ( \
        SDV_HARNESS==SDV_FLAT_DISPATCH_HARNESS || \
        SDV_HARNESS==SDV_FLAT_DISPATCH_STARTIO_HARNESS || \
        SDV_HARNESS==SDV_FLAT_SIMPLE_HARNESS || \
        SDV_HARNESS==SDV_FLAT_HARNESS \
    )

#if SDV_IS_FLAT_HARNESS()

int sdv_is_flat_harness;


void sdv_main() 
{
    UNICODE_STRING u;
    NTSTATUS status;
    LONG choice;

    /* Suppress C4101: Unreferenced local variable.
       Certain flawors of the OS Model does not reference u and status.
       Reference them explicitly to suppress warning: */
    u;
    status;

    sdv_compFptr = NULL;

    choice = SdvMakeChoice();

    switch (choice) {

/*****************************************************************************
    For all the harness(es):
        SDV_FLAT_DISPATCH_HARNESS
        SDV_FLAT_DISPATCH_STARTIO_HARNESS
        SDV_FLAT_SIMPLE_HARNESS
        SDV_FLAT_HARNESS
    Exercise:
        sdv_RunDispatchFunction ||
*****************************************************************************/

    case 0: 
        sdv_stub_driver_init();
        sdv_RunDispatchFunction(sdv_p_devobj_two, sdv_irp);
        break;

/*****************************************************************************
    Additionally for the harness(es):
        SDV_FLAT_DISPATCH_STARTIO_HARNESS
    Exercise:
        sdv_RunStartIo ||
*****************************************************************************/

#if (SDV_HARNESS!=SDV_FLAT_DISPATCH_HARNESS)

#ifdef fun_DriverStartIo
    case 1: 
        sdv_stub_driver_init();
        sdv_RunStartIo(sdv_p_devobj_two, sdv_irp);
        break;
#endif

/*****************************************************************************
    Additionally for the harness(es):
        SDV_FLAT_SIMPLE_HARNESS
        SDV_FLAT_HARNESS
    Exercise:
        sdv_RunDPC ||
        sdv_RunISR ||
        sdv_RunCancelRoutine ||
*****************************************************************************/

#if (SDV_HARNESS!=SDV_FLAT_DISPATCH_STARTIO_HARNESS)

    case 2: 
        sdv_stub_driver_init();
        sdv_RunDPC(sdv_kdpc,sdv_pDpcContext,sdv_pv2,sdv_pv3);
        break;

    case 3: 
        sdv_stub_driver_init();
        sdv_RunISR(sdv_kinterrupt,sdv_pv1);
        break;

    case 4: 
      sdv_stub_driver_init();
      sdv_RunCancelRoutine(sdv_p_devobj_two, sdv_irp);
      break;

/*****************************************************************************
    Additionally for the harness(es):
        SDV_FLAT_HARNESS
    Exercise:
        DriverEntry ||
        sdv_RunAddDevice ||
        sdv_RunStartDevice ||
        sdv_RunRemoveDevice ||
        sdv_RunUnload
*****************************************************************************/

#if (SDV_HARNESS!=SDV_FLAT_SIMPLE_HARNESS)

    case 5: 
        status = DriverEntry(&sdv_driver_object, &u);
        break;

#ifdef fun_AddDevice
    case 6: 
        status = sdv_RunAddDevice(&sdv_driver_object,sdv_p_devobj_one);
        break;
#endif

#ifdef fun_IRP_MJ_PNP
    case 7: 
        sdv_stub_driver_init();
        status = sdv_RunStartDevice(sdv_p_devobj_two, sdv_irp);
        break;
#endif

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_REMOVE_DEVICE
#ifdef fun_IRP_MJ_PNP
    case 8:
        status = sdv_RunRemoveDevice(sdv_p_devobj_two, sdv_irp);
        break; 
#endif
#endif

#ifndef SDV_FLAT_HARNESS_MODIFIER_NO_UNLOAD
#ifdef fun_DriverUnload
    case 9:
        sdv_RunUnload(&sdv_driver_object);
        break;
#endif
#endif

#endif
#endif
#endif

    }
}

#endif
/* flat-harness.c end */

/* pnp-harness.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

/*****************************************************************************

    pnp-harness.c provides a PNP harness for exercising a driver.

    The PNP harness is useful for checking issues that inherently
    depends on proper initialization of the driver.  Examples are
    memory freeing, attachment to the device stack.

    The PNP harness calls the driver repeatedly.  For a simpler
    harness that only calls the driver once see the flat harness in
    flat-harness.c

    The following variations of the PNP harness are available:
        SDV_PNP_HARNESS_SMALL
        SDV_PNP_HARNESS_UNLOAD
        SDV_PNP_HARNESS

    The harnesses exercises the driver as follows:
        SDV_PNP_HARNESS_SMALL =
            DriverEntry;
            sdv_RunAddDevice;
            sdv_RunDispatchFunction

        SDV_PNP_HARNESS_UNLOAD =
            DriverEntry;
            sdv_RunAddDevice;
            ( sdv_RunRemoveDevice ||
              sdv_RunUnload )

        SDV_PNP_HARNESS =
            DriverEntry;
            sdv_RunAddDevice;
            sdv_RunStartDevice
            ( DoNothing ||
              sdv_RunStartIo ||
              sdv_RunDPC ||
              sdv_RunISR ||
              sdv_RunCancelRoutine ||
              sdv_RunDispatchFunction );
            sdv_RunRemoveDevice;
            sdv_RunUnload

*****************************************************************************/

#define SDV_IS_PNP_HARNESS() \
    ( \
        SDV_HARNESS==SDV_PNP_HARNESS || \
        SDV_HARNESS==SDV_PNP_HARNESS_UNLOAD || \
        SDV_HARNESS==SDV_PNP_HARNESS_SMALL \
    )

#if SDV_IS_PNP_HARNESS()

void sdv_main()
{
    UNICODE_STRING u;
    NTSTATUS status;
    LONG choice;
    
    sdv_compFptr = NULL;

    choice = SdvMakeChoice();

/*****************************************************************************
    For all the harness(es):
        SDV_PNP_HARNESS_UNLOAD
        SDV_PNP_HARNESS_SMALL
        SDV_PNP_HARNESS
    Exercise:
        DriverEntry;
        sdv_RunAddDevice;
*****************************************************************************/

    status = DriverEntry(&sdv_driver_object, &u);
    SdvAssume (NT_SUCCESS(status));

#ifdef fun_AddDevice
    status = sdv_RunAddDevice(&sdv_driver_object,sdv_p_devobj_one);
    SdvAssume (NT_SUCCESS(status));
#endif

    sdv_stub_driver_init();

/*****************************************************************************
    Additionally For the harness(es):
        SDV_PNP_HARNESS_SMALL
    Exercise:
        sdv_RunDispatchFunction;
*****************************************************************************/

#if (SDV_HARNESS==SDV_PNP_HARNESS_SMALL)

    sdv_RunDispatchFunction(sdv_p_devobj_two, sdv_irp);

#endif

/*****************************************************************************
    Additionally For the harness(es):
        SDV_PNP_HARNESS_UNLOAD
    Exercise:
        ( sdv_RunRemoveDevice ||
          sdv_RunUnload)
*****************************************************************************/

#if (SDV_HARNESS==SDV_PNP_HARNESS_UNLOAD)

    switch (choice) {

#ifdef fun_IRP_MJ_PNP
    case 0:
        status = sdv_RunRemoveDevice(sdv_p_devobj_two, sdv_irp);
        break;
#endif

#ifdef fun_DriverUnload
    default:
        sdv_RunUnload(&sdv_driver_object);
#endif
    }

#endif

/*****************************************************************************
    Additionally For the harness(es):
        SDV_PNP_HARNESS
    Exercise:
        sdv_RunStartDevice
        ( sdv_RunStartIo ||
          sdv_RunDPC ||
          sdv_RunISR ||
          sdv_RunCancelRoutine ||
          sdv_RunDispatchFunction);
        sdv_RunRemoveDevice;
        sdv_RunUnload
*****************************************************************************/

#if (SDV_HARNESS==SDV_PNP_HARNESS)

#ifdef fun_IRP_MJ_PNP
    status = sdv_RunStartDevice(sdv_p_devobj_two, sdv_irp);
    SdvAssume (NT_SUCCESS(status));
#endif

    switch (choice) {

#ifdef fun_DriverStartIo
    case 0: 
        sdv_RunStartIo(sdv_p_devobj_two, sdv_irp);
        break;
#endif

    case 1:
        sdv_RunDPC(sdv_kdpc,sdv_pDpcContext,sdv_pv2,sdv_pv3);
        break;

    case 2:
        sdv_RunISR(sdv_kinterrupt,sdv_pv1);
        break;

    case 3: 
        sdv_RunCancelRoutine(sdv_p_devobj_two, sdv_irp);
        break;
    
    case 4:
        sdv_RunDispatchFunction(sdv_p_devobj_two, sdv_irp);
        break;
    
    }

#ifdef fun_IRP_MJ_PNP
    status = sdv_RunRemoveDevice(sdv_p_devobj_two, sdv_irp);
#endif

#ifdef fun_DriverUnload
    if (sdv_io_create_device_called<2) {
        sdv_driver_object.DeviceObject = NULL;
    }
    sdv_RunUnload(&sdv_driver_object);
#endif

#endif

}

#endif
/* pnp-harness.c end */

/* sdv_stubs.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/


void __cdecl main() 
{
    SDV_MAIN_INIT(); 
    sdv_main();
}


void sdv_do_paged_code_check() { }


void sdv_do_assert_check(int exp) 
{
    SdvAssumeSoft(exp);
}

char sdv_alloc_dummy;

char* malloc(
    int i
    )
{
    return &sdv_alloc_dummy;
}

void sdv_stub_driver_init() { }
void sdv_stub_completion_begin(PIRP pirp)
{ 
    SDV_IRQL_PUSH(DISPATCH_LEVEL);
}

void sdv_stub_completion_end(PIRP pirp)
{ 
    SDV_IRQL_POP();
}

void sdv_stub_PowerQuery() { }

void sdv_stub_PowerUpOrDown() { }

void sdv_stub_dpc_begin()
{
    SDV_IRQL_PUSH(DISPATCH_LEVEL);
}

void sdv_stub_dpc_end()
{
    SDV_IRQL_POPTO(PASSIVE_LEVEL);
}

void sdv_stub_isr_begin()
{
    SDV_IRQL_PUSH(SDV_DIRQL);
}

void sdv_stub_isr_end()
{ 
    SDV_IRQL_POPTO(PASSIVE_LEVEL);
}

void sdv_stub_startio_begin()
{
    SDV_IRQL_PUSH(DISPATCH_LEVEL);
}

void sdv_stub_startio_end()
{ 
    SDV_IRQL_POPTO(PASSIVE_LEVEL);
}

void sdv_stub_dispatch_begin()
{
    SDV_IRQL_PUSH(PASSIVE_LEVEL);
}

void sdv_stub_dispatch_end(NTSTATUS s, PIRP pirp)
{
}

void sdv_stub_cancel_begin() { }
void sdv_stub_cancel_end() { }

void sdv_stub_add_begin() { }
void sdv_stub_add_end() { }

void sdv_stub_unload_begin() 
{ 
    SDV_IRQL_POPTO(PASSIVE_LEVEL);
}

void sdv_stub_unload_end() { }


void sdv_stub_MoreProcessingRequired(PIRP pirp) { }
void sdv_stub_WmiIrpProcessed(PIRP pirp) { }
void sdv_stub_WmiIrpNotCompleted(PIRP pirp) { }
void sdv_stub_WmiIrpForward(PIRP pirp) { }

void sdv_dummy_Cancel_Routine(
    PDEVICE_OBJECT p,
    PIRP pirp
    )
{
    IoReleaseCancelSpinLock(sdv_irql_previous);
}

void sdv_dummy_Cancel_Flow(
    )
{
  sdv_cancelFptr = sdv_dummy_Cancel_Routine ;
}
/* sdv_stubs.c end */

/* ntddk-ex.c begin */
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
/* ntddk-ex.c end */

/* ntddk-fs.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

NTKERNELAPI
BOOLEAN
FsRtlIsTotalDeviceFailure(
    IN NTSTATUS Status
    ) 
{ 
    BOOLEAN b = (BOOLEAN) SdvMakeChoice(); 
    return b; 
}
/* ntddk-fs.c end */

/* ntddk-io.c begin */
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


/* ntddk-io.c end */

/* ntddk-ke.c begin */
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




/* ntddk-ke.c end */

/* ntddk-mm.c begin */
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
/* ntddk-mm.c end */

/* ntddk-nc.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

NTSTATUS
NTAPI
NtOpenProcess (
    OUT PHANDLE ProcessHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    IN PCLIENT_ID ClientId OPTIONAL
    ) 
{ 
    NTSTATUS r = SdvMakeChoice(); 
    return r; 
}

NTSTATUS
NTAPI
NtQueryInformationProcess(
    IN HANDLE ProcessHandle,
    IN PROCESSINFOCLASS ProcessInformationClass,
    OUT PVOID ProcessInformation,
    IN ULONG ProcessInformationLength,
    OUT PULONG ReturnLength OPTIONAL
    ) 
{ 
    NTSTATUS r = SdvMakeChoice(); 
    return r; 
}
/* ntddk-nc.c end */

/* ntddk-ob.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

LONG_PTR
sdv_ObDereferenceObject (
    IN PVOID Object
    )
{
    LONG_PTR p = (LONG_PTR) SdvMakeChoice();
    return p;
}

NTSTATUS
ObGetObjectSecurity(
    IN PVOID Object,
    OUT PSECURITY_DESCRIPTOR *SecurityDescriptor,
    OUT PBOOLEAN MemoryAllocated
    ) 
{ 
    NTSTATUS r = SdvMakeChoice(); 
    return r; 
}

LONG_PTR
sdv_ObReferenceObject(
    IN PVOID Object
    )
{
    LONG_PTR p = (LONG_PTR) SdvMakeChoice();
    return p;
}

NTKERNELAPI                                                     
NTSTATUS                                                        
ObReferenceObjectByHandle(                                      
    IN HANDLE Handle,                                           
    IN ACCESS_MASK DesiredAccess,                               
    IN POBJECT_TYPE ObjectType OPTIONAL,                        
    IN KPROCESSOR_MODE AccessMode,                              
    OUT PVOID *Object,                                          
    OUT POBJECT_HANDLE_INFORMATION HandleInformation OPTIONAL   
    )
{
    int x = SdvMakeChoice();
    switch (x) { 
        case 0: return STATUS_SUCCESS;
#ifdef SLAM_PRECISE_STATUS
        case 1: return STATUS_OBJECT_TYPE_MISMATCH;
        case 2: return STATUS_ACCESS_DENIED;
        default: return STATUS_INVALID_HANDLE;
#else
        default: return STATUS_UNSUCCESSFUL;
#endif
    }
}          

NTKERNELAPI
NTSTATUS
ObReferenceObjectByPointer(
    IN PVOID Object,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_TYPE ObjectType,
    IN KPROCESSOR_MODE AccessMode
    ) 
{ 
    NTSTATUS r = SdvMakeChoice(); 
    return r; 
}

VOID
ObReleaseObjectSecurity(
    IN PSECURITY_DESCRIPTOR SecurityDescriptor,
    IN BOOLEAN MemoryAllocated
    ) 
{  
}
/* ntddk-ob.c end */

/* ntddk-po.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

NTKERNELAPI
NTSTATUS
sdv_PoCallDriver(
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
PULONG
PoRegisterDeviceForIdleDetection(
    IN PDEVICE_OBJECT     DeviceObject,
    IN ULONG              ConservationIdleTime,
    IN ULONG              PerformanceIdleTime,
    IN DEVICE_POWER_STATE State
    ) 
{ 
    PULONG r = ((PULONG)((ULONG_PTR) SdvMakeChoice()));
    return r; 
}

NTKERNELAPI
PVOID
PoRegisterSystemState(
    IN PVOID StateHandle,
    IN EXECUTION_STATE Flags
    ) 
{ 
	PVOID r = ((PVOID)((ULONG_PTR) SdvMakeChoice()));
        return r; 
}

NTKERNELAPI
NTSTATUS
PoRequestPowerIrp(
    IN PDEVICE_OBJECT DeviceObject,
    IN UCHAR MinorFunction,
    IN POWER_STATE PowerState,
    IN PREQUEST_POWER_COMPLETE CompletionFunction,
    IN PVOID Context,
    OUT PIRP *Irp OPTIONAL
    ) {
    int x = SdvMakeChoice();
    switch (x) {
        case 0:
	  return STATUS_PENDING;
        case 1: return STATUS_INSUFFICIENT_RESOURCES;
        default: return STATUS_INVALID_PARAMETER;
    }
}

NTKERNELAPI
POWER_STATE
PoSetPowerState(
    IN PDEVICE_OBJECT   DeviceObject,
    IN POWER_STATE_TYPE Type,
    IN POWER_STATE      State
    ) 
{ 
    POWER_STATE r = sdv_Make_POWER_STATE(); 
    return r; 
}

NTKERNELAPI
VOID
PoSetSystemState(
    IN EXECUTION_STATE Flags
    ) 
{  
}

NTKERNELAPI
VOID
PoStartNextPowerIrp(
    IN PIRP    Irp
    ) 
{  
}

NTKERNELAPI
VOID
PoUnregisterSystemState(
    IN PVOID StateHandle
    ) 
{  
}

/* ntddk-po.c end */

/* ntddk-ps.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

NTKERNELAPI
NTSTATUS
PsCreateSystemThread(
    OUT PHANDLE ThreadHandle,
    IN ULONG DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
    IN HANDLE ProcessHandle OPTIONAL,
    OUT PCLIENT_ID ClientId OPTIONAL,
    IN PKSTART_ROUTINE StartRoutine,
    IN PVOID StartContext
    )
{
    int x = SdvMakeChoice();
    switch (x) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}

BOOLEAN
PsGetVersion(
    PULONG MajorVersion OPTIONAL,
    PULONG MinorVersion OPTIONAL,
    PULONG BuildNumber OPTIONAL,
    PUNICODE_STRING CSDVersion OPTIONAL
    ) 
{ 
    BOOLEAN b = (BOOLEAN) SdvMakeChoice(); 
    return b; 
}

NTSTATUS
PsSetCreateProcessNotifyRoutine(
    IN PCREATE_PROCESS_NOTIFY_ROUTINE NotifyRoutine,
    IN BOOLEAN Remove
    ) 
{ 
    NTSTATUS r = SdvMakeChoice();
    return r; 
}

NTSTATUS
PsSetCreateThreadNotifyRoutine(
    IN PCREATE_THREAD_NOTIFY_ROUTINE NotifyRoutine
    ) 
{ 
    NTSTATUS r = SdvMakeChoice(); 
    return r; 
}

NTSTATUS
PsSetLoadImageNotifyRoutine(
    IN PLOAD_IMAGE_NOTIFY_ROUTINE NotifyRoutine
    ) 
{ 
    NTSTATUS r = SdvMakeChoice(); 
    return r; 
}

NTKERNELAPI
NTSTATUS
PsTerminateSystemThread(
    IN NTSTATUS ExitStatus
    )
{
    int x = SdvMakeChoice();;
    switch (x) {
        case 0: return STATUS_SUCCESS;
        default: return STATUS_UNSUCCESSFUL;
    }
}
/* ntddk-ps.c end */

/* ntddk-se.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

NTKERNELAPI
BOOLEAN
SeAccessCheck(
    IN PSECURITY_DESCRIPTOR SecurityDescriptor,
    IN PSECURITY_SUBJECT_CONTEXT SubjectSecurityContext,
    IN BOOLEAN SubjectContextLocked,
    IN ACCESS_MASK DesiredAccess,
    IN ACCESS_MASK PreviouslyGrantedAccess,
    OUT PPRIVILEGE_SET *Privileges OPTIONAL,
    IN PGENERIC_MAPPING GenericMapping,
    IN KPROCESSOR_MODE AccessMode,
    OUT PACCESS_MASK GrantedAccess,
    OUT PNTSTATUS AccessStatus
    ) 
{ 
    BOOLEAN b = (BOOLEAN) SdvMakeChoice(); 
    return b; 
}

NTKERNELAPI
NTSTATUS
SeAssignSecurity(
    IN PSECURITY_DESCRIPTOR ParentDescriptor OPTIONAL,
    IN PSECURITY_DESCRIPTOR ExplicitDescriptor,
    OUT PSECURITY_DESCRIPTOR *NewDescriptor,
    IN BOOLEAN IsDirectoryObject,
    IN PSECURITY_SUBJECT_CONTEXT SubjectContext,
    IN PGENERIC_MAPPING GenericMapping,
    IN POOL_TYPE PoolType
    ) 
{ 
    NTSTATUS r = SdvMakeChoice(); 
    return r; 
}

NTKERNELAPI
NTSTATUS
SeAssignSecurityEx(
    IN PSECURITY_DESCRIPTOR ParentDescriptor OPTIONAL,
    IN PSECURITY_DESCRIPTOR ExplicitDescriptor OPTIONAL,
    OUT PSECURITY_DESCRIPTOR *NewDescriptor,
    IN GUID *ObjectType OPTIONAL,
    IN BOOLEAN IsDirectoryObject,
    IN ULONG AutoInheritFlags,
    IN PSECURITY_SUBJECT_CONTEXT SubjectContext,
    IN PGENERIC_MAPPING GenericMapping,
    IN POOL_TYPE PoolType
    ) 
{ 
    NTSTATUS r = SdvMakeChoice(); 
    return r; 
}

NTKERNELAPI
NTSTATUS
SeDeassignSecurity(
    IN OUT PSECURITY_DESCRIPTOR *SecurityDescriptor
    ) 
{ 
    NTSTATUS r = SdvMakeChoice(); 
    return r; 
}

NTKERNELAPI                                                     
BOOLEAN                                                         
SeSinglePrivilegeCheck(                                         
    LUID PrivilegeValue,                                        
    KPROCESSOR_MODE PreviousMode                                
    ) 
{ 
    BOOLEAN b = (BOOLEAN) SdvMakeChoice(); 
    return b;
}                                                          

NTKERNELAPI
BOOLEAN
SeValidSecurityDescriptor(
    IN ULONG Length,
    IN PSECURITY_DESCRIPTOR SecurityDescriptor
    ) 
{ 
    BOOLEAN b = (BOOLEAN) SdvMakeChoice(); 
    return b; 
}
/* ntddk-se.c end */

/* ntddk-rtl.c begin */
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
/* ntddk-rtl.c end */

/* ntddk-zw.c begin */
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


/* ntddk-zw.c end */

/* ntddk-misc.c begin */
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
/* ntddk-misc.c end */

/* ntddk-hal.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

NTSTATUS
sdv_HalQuerySystemInformation(
    IN HAL_QUERY_INFORMATION_CLASS  InformationClass,
    IN ULONG  BufferSize,
    OUT PVOID  Buffer,
    OUT PULONG  ReturnedLength
    )
{
    NTSTATUS r = SdvMakeChoice();

    SdvAssume(r != STATUS_PENDING);
    return r;
}
/* ntddk-hal.c end */

/* ntddk-wmi.c begin */
/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

typedef enum {
        IrpProcessed,
        IrpNotCompleted,
        IrpNotWmi,
        IrpForward
    } SYSCTL_IRP_DISPOSITION, *PSYSCTL_IRP_DISPOSITION;

NTSTATUS
WmiSystemControl(
    IN PVOID  WmiLibInfo,
    IN PDEVICE_OBJECT  DeviceObject,
    IN PIRP  pirp,
    OUT PSYSCTL_IRP_DISPOSITION  IrpDisposition
    )
{
    int x = SdvMakeChoice();
    int y = SdvMakeChoice();
    NTSTATUS s;
    switch (x) {
        case 0: 
            *IrpDisposition = IrpProcessed;
            s = STATUS_SUCCESS;
            sdv_stub_WmiIrpProcessed(pirp);
            break;
        case 1:
            *IrpDisposition = IrpNotCompleted;
            s = STATUS_SUCCESS;
            sdv_stub_WmiIrpNotCompleted(pirp);
            break;
        case 2:
            *IrpDisposition = IrpForward;
            s = STATUS_SUCCESS;
            sdv_stub_WmiIrpForward(pirp);
            break;
        default:    
            *IrpDisposition = IrpNotWmi;
            sdv_stub_WmiIrpForward(pirp);
            switch (y){
                case 0:
                s = STATUS_SUCCESS;
                break;
            default:
                s = STATUS_INVALID_DEVICE_REQUEST;
                break;
            }
    }
    return s;
}
/* ntddk-wmi.c end */


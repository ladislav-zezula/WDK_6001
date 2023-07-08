/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

Module Name:

    Interrupt.c

Abstract:

    This modules has routines configure a continuous reader on an
    interrupt pipe to asynchronously read toggle switch states.

Environment:

    Kernel mode

--*/

#include <osrusbfx2.h>

#if defined(EVENT_TRACING)
#include "interrupt.tmh"
#endif


__drv_requiresIRQL(PASSIVE_LEVEL)
NTSTATUS
OsrFxConfigContReaderForInterruptEndPoint(
    __in PDEVICE_CONTEXT DeviceContext
    )
/*++

Routine Description:

    This routine configures a continuous reader on the
    interrupt endpoint. It's called from the PrepareHarware event.

Arguments:


Return Value:

    NT status value

--*/
{
    WDF_USB_CONTINUOUS_READER_CONFIG contReaderConfig;
    NTSTATUS status;

    WDF_USB_CONTINUOUS_READER_CONFIG_INIT(&contReaderConfig,
                                          OsrFxEvtUsbInterruptPipeReadComplete,
                                          DeviceContext,    // Context
                                          sizeof(UCHAR));   // TransferLength
    //
    // Reader requests are not posted to the target automatically.
    // Driver must explictly call WdfIoTargetStart to kick start the
    // reader.  In this sample, it's done in D0Entry.
    // By defaut, framework queues two requests to the target
    // endpoint. Driver can configure up to 10 requests with CONFIG macro.
    //
    status = WdfUsbTargetPipeConfigContinuousReader(DeviceContext->InterruptPipe,
                                                    &contReaderConfig);

    if (!NT_SUCCESS(status)) {
        TraceEvents(TRACE_LEVEL_ERROR, DBG_PNP,
                    "OsrFxConfigContReaderForInterruptEndPoint failed %x\n",
                    status);
        return status;
    }

    return status;
}


__drv_requiresIRQL(DISPATCH_LEVEL)
VOID
OsrFxEvtUsbInterruptPipeReadComplete(
    __in WDFUSBPIPE  Pipe,
    __in WDFMEMORY   Buffer,
    __in size_t      NumBytesTransferred,
    __in WDFCONTEXT  Context
    )
/*++

Routine Description:

    This the completion routine of the continour reader. This can
    called concurrently on multiprocessor system if there are
    more than one readers configured. So make sure to protect
    access to global resources.

Arguments:

    Buffer - This buffer is freed when this call returns.
             If the driver wants to delay processing of the buffer, it
             can take an additional referrence.

    Context - Provided in the WDF_USB_CONTINUOUS_READER_CONFIG_INIT macro

Return Value:

    NT status value

--*/
{
    PUCHAR          switchState = NULL;
    WDFDEVICE       device;
    PDEVICE_CONTEXT pDeviceContext = Context;

    UNREFERENCED_PARAMETER(NumBytesTransferred);
    UNREFERENCED_PARAMETER(Pipe);

    device = WdfObjectContextGetObject(pDeviceContext);

    ASSERT(NumBytesTransferred == sizeof(UCHAR));

    switchState = WdfMemoryGetBuffer(Buffer, NULL);

    TraceEvents(TRACE_LEVEL_INFORMATION, DBG_INIT,
                "OsrFxEvtUsbInterruptPipeReadComplete SwitchState %x\n",
                *switchState);

    pDeviceContext->CurrentSwitchState = *switchState;

    //
    // Handle any pending Interrupt Message IOCTLs. Note that the OSR USB device
    // will generate an interrupt message when the the device resumes from a low
    // power state. So if the Interrupt Message IOCTL was sent after the device
    // has gone to a low power state, the pending Interrupt Message IOCTL will
    // get completed in the function call below, before the user twiddles the
    // dip switches on the OSR USB device. If this is not the desired behavior
    // for your driver, then you could handle this condition by maintaining a
    // state variable on D0Entry to track interrupt messages caused by power up.
    //
    OsrUsbIoctlGetInterruptMessage(device);

}



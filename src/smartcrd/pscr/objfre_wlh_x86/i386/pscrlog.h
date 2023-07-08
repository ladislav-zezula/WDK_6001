// BUILD Version: 0001    // Increment this if a change has global effects
/*++

Copyright (c) 1997	SCM Microsystems, Inc

Module Name:

    PscrLog.mc

Abstract:

    Constant definitions for the I/O error code log values.

Revision History:

--*/

#ifndef __PSCRLOG_H__
#define __PSCRLOG_H__

//
//  Status values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-------------------------+-------------------------------+
//  |Sev|C|       Facility          |               Code            |
//  +---+-+-------------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//

//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//
#define FACILITY_SCARD                   0x10
#define FACILITY_RPC_STUBS               0x3
#define FACILITY_RPC_RUNTIME             0x2
#define FACILITY_IO_ERROR_CODE           0x4


//
// Define the severity codes
//
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: PSCR_NO_DEVICE_FOUND
//
// MessageText:
//
// No PSCR Smart Card reader found in the system. 
//
#define PSCR_NO_DEVICE_FOUND             ((NTSTATUS)0xC0100001L)

//
// MessageId: PSCR_CANT_INITIALIZE_READER
//
// MessageText:
//
// The reader inserted is not working properly.
// Please try to change the 'Input/Output Range' and/or 'Interrupt Request' 
// settings in Device Manager.
//
#define PSCR_CANT_INITIALIZE_READER      ((NTSTATUS)0xC0100002L)

//
// MessageId: PSCR_INSUFFICIENT_RESOURCES
//
// MessageText:
//
// Insufficient system resources to start device.
//
#define PSCR_INSUFFICIENT_RESOURCES      ((NTSTATUS)0xC0100003L)

//
// MessageId: PSCR_ERROR_INTERRUPT
//
// MessageText:
//
// Can't connect to the interrupt provided by the system.
// Please try to change the 'Interrupt Request' setting in Device Manager.
//
#define PSCR_ERROR_INTERRUPT             ((NTSTATUS)0xC0100004L)

//
// MessageId: PSCR_ERROR_IO_PORT
//
// MessageText:
//
// No I/O port specified or port can not be mapped.
// Please try to change the 'Input/Output Range' setting in the Device Manager.
//
#define PSCR_ERROR_IO_PORT               ((NTSTATUS)0xC0100005L)

//
// MessageId: PSCR_ERROR_CLAIM_RESOURCES
//
// MessageText:
//
// Resources can not be claimed or an resource conflict exists.
//
#define PSCR_ERROR_CLAIM_RESOURCES       ((NTSTATUS)0xC0100006L)

//
// MessageId: PSCR_NO_MEMORY
//
// MessageText:
//
// The system does not have enough memory.
//
#define PSCR_NO_MEMORY                   ((NTSTATUS)0xC0040007L)

//
// MessageId: PSCR_WRONG_FIRMWARE
//
// MessageText:
//
// Your reader needs firmware version 2.30 or higher to work with this driver. 
//
#define PSCR_WRONG_FIRMWARE              ((NTSTATUS)0x80100007L)

#endif // __PSCRLOG_H__

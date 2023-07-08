/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    hw_eprom.c

Abstract:
    EEPROM access functions
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created
    01-15-2006    Renamed hw_eprom.c to hw_eprom.c

Notes:

--*/

#include "hw_pcomp.h"

#include "r8180equ.h"
#include "Rtl8180.h"
#include "hw_eprom.h"

#pragma hdrstop
#pragma warning (disable: 4244 4514)

#define EEPROM_MAX_SIZE        	256
#define	CSR_EEPROM_CONTROL_REG	CR9346
#define	CLOCK_RATE				50			//100us		
//*****************************************************************************
//
//            I/O based Read EEPROM Routines
//
//*****************************************************************************

//-----------------------------------------------------------------------------
// Procedure:   EEpromAdapter->EepromAddressSize
//
// Description: determines the number of bits in an address for the eeprom
//              acceptable values are 64, 128, and 256
//
// Arguments:
//      Size -- size of the eeprom
//
// Returns:
//      bits in an address for that size eeprom
//-----------------------------------------------------------------------------

USHORT 
GetEEpromAddressSize(
    USHORT  Size)
{
    switch (Size)
    {
        case 64:    return 6;
        case 128:   return 7;
        case 256:   return 8;
    }

    return 0;
}

//-----------------------------------------------------------------------------
// Procedure:   GetEEpromSize
//
// Description: This routine determines the size of the EEPROM.
//
// Arguments:
//      Reg - EEPROM word to read.
//
// Returns:
//      Size of the EEPROM, or zero if error.
//-----------------------------------------------------------------------------

USHORT
GetEEpromSize(
	PUCHAR	CSRBaseIoAddress)
{
	USHORT x, data;
    USHORT size = 1;

    // select EEPROM, reset bits, set EECS
    x = READ_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG));

	x &= ~(EEDI | EEDO | EESK | CR9346_EEM0);
    x |= CR9346_EEM1 | EECS;
    WRITE_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG), (UCHAR)x);

    // write the read opcode
	ShiftOutBits(CSRBaseIoAddress,EEPROM_READ_OPCODE, 3);

    // experiment to discover the size of the eeprom.  request register zero
    // and wait for the eeprom to tell us it has accepted the entire address.
    x = READ_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG));
    do
	{
        size *= 2;          // each bit of address doubles eeprom size
        x |= EEDO;          // set bit to detect "dummy zero"
        x &= ~EEDI;         // address consists of all zeros

        WRITE_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG), (UCHAR)x);
        KeStallExecutionProcessor(CLOCK_RATE);
        RaiseClock(CSRBaseIoAddress, &x);
        LowerClock(CSRBaseIoAddress, &x);

        // check for "dummy zero"
		x = READ_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG));
        if (size > EEPROM_MAX_SIZE)
        {
            size = 0;
            break;
        }
    }
	while (x & EEDO);

	// Now read the data (16 bits) in from the selected EEPROM word
	data = ShiftInBits(CSRBaseIoAddress);

    EEpromCleanup(CSRBaseIoAddress);
    
    return size;
}

//-----------------------------------------------------------------------------
// Procedure:   ReadEEprom
//
// Description: This routine serially reads one word out of the EEPROM.
//
// Arguments:
//      Reg - EEPROM word to read.
//
// Returns:
//      Contents of EEPROM word (Reg).
//-----------------------------------------------------------------------------
USHORT 
ReadEEprom(
	PUCHAR	CSRBaseIoAddress,
	UCHAR	AddressSize,
    USHORT 	Reg)
{
    USHORT x;
    USHORT data;

    // select EEPROM, reset bits, set EECS
    x = READ_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG));

    x &= ~(EEDI | EEDO | EESK | CR9346_EEM0);
    x |= CR9346_EEM1 | EECS;
    WRITE_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG), (UCHAR)x);

    // write the read opcode and register number in that order
    // The opcode is 3bits in length, reg is 6 bits long
    ShiftOutBits(CSRBaseIoAddress, EEPROM_READ_OPCODE, 3);
    ShiftOutBits(CSRBaseIoAddress, Reg, AddressSize);

    // Now read the data (16 bits) in from the selected EEPROM word
    data = ShiftInBits(CSRBaseIoAddress);

    EEpromCleanup(CSRBaseIoAddress);
    return data;
}

//-----------------------------------------------------------------------------
// Procedure:   ShiftOutBits
//
// Description: This routine shifts data bits out to the EEPROM.
//
// Arguments:
//      data - data to send to the EEPROM.
//      count - number of data bits to shift out.
//
// Returns: (none)
//-----------------------------------------------------------------------------

VOID 
ShiftOutBits(
	PUCHAR	CSRBaseIoAddress,
    USHORT data,
	USHORT count)
{
    USHORT x,mask;

    mask = 0x01 << (count - 1);
    x = READ_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG));

    x &= ~(EEDO | EEDI);

    do
    {
        x &= ~EEDI;
        if(data & mask)
            x |= EEDI;

        WRITE_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG), (UCHAR)x);
        KeStallExecutionProcessor(CLOCK_RATE);
        RaiseClock(CSRBaseIoAddress, &x);
        LowerClock(CSRBaseIoAddress, &x);
        mask = mask >> 1;
    } while(mask);

    x &= ~EEDI;
    WRITE_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG), (UCHAR)x);
}

//-----------------------------------------------------------------------------
// Procedure:   ShiftInBits
//
// Description: This routine shifts data bits in from the EEPROM.
//
// Arguments:
//
// Returns:
//      The contents of that particular EEPROM word
//-----------------------------------------------------------------------------

USHORT 
ShiftInBits(
	PUCHAR	CSRBaseIoAddress)
{
    USHORT x,d,i;
    x = READ_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG));

    x &= ~( EEDO | EEDI);
    d = 0;

    for(i=0; i<16; i++)
    {
        d = d << 1;
        RaiseClock(CSRBaseIoAddress, &x);

        x = READ_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG));

        x &= ~(EEDI);
        if(x & EEDO)
            d |= 1;

        LowerClock(CSRBaseIoAddress, &x);
    }

    return d;
}

//-----------------------------------------------------------------------------
// Procedure:   RaiseClock
//
// Description: This routine raises the EEPOM's clock input (EESK)
//
// Arguments:
//      x - Ptr to the EEPROM control register's current value
//
// Returns: (none)
//-----------------------------------------------------------------------------

VOID 
RaiseClock(
	PUCHAR	CSRBaseIoAddress,
    USHORT *x)
{
    *x = *x | EESK;
    WRITE_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG), (UCHAR)(*x));
    KeStallExecutionProcessor(CLOCK_RATE);
}


//-----------------------------------------------------------------------------
// Procedure:   LowerClock
//
// Description: This routine lower's the EEPOM's clock input (EESK)
//
// Arguments:
//      x - Ptr to the EEPROM control register's current value
//
// Returns: (none)
//-----------------------------------------------------------------------------

VOID 
LowerClock(
	PUCHAR	CSRBaseIoAddress,
    USHORT *x)
{
    *x = *x & ~EESK;
    WRITE_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG), (UCHAR)(*x));
    KeStallExecutionProcessor(CLOCK_RATE);
}

//-----------------------------------------------------------------------------
// Procedure:   EEpromCleanup
//
// Description: This routine returns the EEPROM to an idle state
//
// Arguments:
//
// Returns: (none)
//-----------------------------------------------------------------------------

VOID 
EEpromCleanup(
	PUCHAR	CSRBaseIoAddress)
{
    USHORT x;
    x = READ_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG));

    x &= ~(EECS | EEDI);
    WRITE_PORT_UCHAR((PUCHAR)(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG), (UCHAR)x);

    RaiseClock(CSRBaseIoAddress, &x);
    LowerClock(CSRBaseIoAddress, &x);
}

//*****************************************************************************
//
//            EEPROM Write Routines
//
//*****************************************************************************

//-----------------------------------------------------------------------------
// Procedure:   D100UpdateChecksum
//
// Description: Calculates the checksum and writes it to the EEProm.  This
//              routine assumes that the checksum word is the last word in
//              a 64 word EEPROM.  It calculates the checksum accroding to
//              the formula: Checksum = 0xBABA - (sum of first 63 words).
//
// Arguments:
//      Adapter - Ptr to this card's adapter data structure
//
// Returns: (none)
//-----------------------------------------------------------------------------

VOID
UpdateChecksum(
	PUCHAR	CSRBaseIoAddress)
{
    USHORT    Checksum=0;
//    USHORT    Iter;

	UNREFERENCED_PARAMETER(CSRBaseIoAddress);

//    for (Iter = 0; Iter < 0x3F; Iter++) 
//        Checksum += ReadEEprom( CSRBaseIoAddress, Iter );

    Checksum = (USHORT)0xBABA - Checksum;
//    WriteEEprom( CSRBaseIoAddress, 0x3F, Checksum );
}

//-----------------------------------------------------------------------------
// Procedure:   WriteEEprom
//
// Description: This routine writes a word to a specific EEPROM location.
//
// Arguments:
//      Adapter - Ptr to this card's adapter data structure.
//      reg - The EEPROM word that we are going to write to. 
//      data - The data (word) that we are going to write to the EEPROM. 
//
// Returns: (none)
//-----------------------------------------------------------------------------

VOID
WriteEEprom(
	PUCHAR	CSRBaseIoAddress,
	UCHAR	AddressSize,
	USHORT reg,
    USHORT data)
{
    UCHAR x;

    // select EEPROM, mask off ASIC and reset bits, set EECS
    x = READ_PORT_UCHAR(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG);

    x &= ~(EEDI | EEDO | EESK | CR9346_EEM0);
    x |= CR9346_EEM1 | EECS;
    WRITE_PORT_UCHAR((CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG), x);

    ShiftOutBits(CSRBaseIoAddress, EEPROM_EWEN_OPCODE, 5);
    /////ShiftOutBits(CSRBaseIoAddress, reg, 4);
	ShiftOutBits(CSRBaseIoAddress, 0, 6);

    StandBy( CSRBaseIoAddress);

    // Erase this particular word.  Write the erase opcode and register
    // number in that order. The opcode is 3bits in length; reg is 6 bits long.
    ShiftOutBits(CSRBaseIoAddress, EEPROM_ERASE_OPCODE, 3);
    ShiftOutBits(CSRBaseIoAddress, reg, AddressSize);

    if (WaitEEPROMCmdDone(CSRBaseIoAddress ) == FALSE) 
    {
        return;
    }

    StandBy(CSRBaseIoAddress );

    // write the new word to the EEPROM

    // send the write opcode the EEPORM
    ShiftOutBits(CSRBaseIoAddress, EEPROM_WRITE_OPCODE, 3);

    // select which word in the EEPROM that we are writing to.
    ShiftOutBits(CSRBaseIoAddress, reg, AddressSize);

    // write the data to the selected EEPROM word.
    ShiftOutBits(CSRBaseIoAddress, data, 16);

    if (WaitEEPROMCmdDone(CSRBaseIoAddress ) == FALSE) 
    {
//        DbgPrint("D100: Failed EEPROM Write");
        return;
    }

    StandBy(CSRBaseIoAddress );

    ShiftOutBits(CSRBaseIoAddress, EEPROM_EWDS_OPCODE, 5);
    ShiftOutBits(CSRBaseIoAddress, reg, 4);

    EEpromCleanup(CSRBaseIoAddress );
    return;
}

//-----------------------------------------------------------------------------
// Procedure:   WaitEEPROMCmdDone
//
// Description: This routine waits for the the EEPROM to finish its command.
//              Specifically, it waits for EEDO (data out) to go high.
//
// Arguments:
//      Adapter - Ptr to this card's adapter data structure.
//
// Returns:
//      TRUE - If the command finished
//      FALSE - If the command never finished (EEDO stayed low)
//-----------------------------------------------------------------------------

USHORT
WaitEEPROMCmdDone(
	PUCHAR	CSRBaseIoAddress)
{

    UCHAR 	x;
    USHORT	i;

    StandBy(CSRBaseIoAddress );
    for (i=0; i<200; i++) 
    {
        x = READ_PORT_UCHAR(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG );
        if (x & EEDO)
            return (TRUE);
        KeStallExecutionProcessor(CLOCK_RATE);
    }
    return FALSE;
}


//-----------------------------------------------------------------------------
// Procedure:   StandBy
//
// Description: This routine lowers the EEPROM chip select (EECS) for a few
//              microseconds.
//
// Arguments:
//      Adapter - Ptr to this card's adapter data structure.
//
// Returns: (none)
//-----------------------------------------------------------------------------

VOID
StandBy(
	PUCHAR	CSRBaseIoAddress)
{
    UCHAR    x;

    x = READ_PORT_UCHAR(CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG);

    x &= ~(EECS | EESK);
    WRITE_PORT_UCHAR((CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG), x);

    KeStallExecutionProcessor(CLOCK_RATE);
    x |= EECS;
    WRITE_PORT_UCHAR((CSRBaseIoAddress + CSR_EEPROM_CONTROL_REG), x);
	KeStallExecutionProcessor(CLOCK_RATE);
}


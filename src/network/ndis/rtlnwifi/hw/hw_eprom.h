/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    hw_eprom.h

Abstract:
    EEPROM access functions
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created
    01-15-2006    Renamed hw_eprom.h to hw_eprom.h

Notes:

--*/
	//eeprom.c
	USHORT ReadEEprom(
						IN PUCHAR CSRBaseIoAddress,
						IN UCHAR  AddressSize,
						IN USHORT Reg);
						
	VOID ShiftOutBits(	IN PUCHAR CSRBaseIoAddress,
						IN USHORT data,
						IN USHORT count	);
	USHORT ShiftInBits(
						IN PUCHAR CSRBaseIoAddress);
						
	VOID RaiseClock(	IN PUCHAR CSRBaseIoAddress,
						IN OUT USHORT *x );
						
	VOID LowerClock(	IN PUCHAR CSRBaseIoAddress,
						IN OUT USHORT *x);
						
	VOID EEpromCleanup(	IN PUCHAR CSRBaseIoAddress);

	void UpdateChecksum(PUCHAR	CSRBaseIoAddress);
	
	void WriteEEprom(	PUCHAR	CSRBaseIoAddress,
						UCHAR	AddressSize,
						USHORT reg,
					    USHORT data);
					    
	USHORT WaitEEPROMCmdDone(
						PUCHAR	CSRBaseIoAddress);
	VOID StandBy(
		PUCHAR	CSRBaseIoAddress);


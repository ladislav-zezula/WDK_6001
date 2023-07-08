#pragma once 

BOOLEAN
SetRFPowerState(
    PNIC                Nic, 
    RT_RF_POWER_STATE   eRFPowerState
    );


// Phy functions
void SwChnlPhy(
    PNIC    pNic,
    UCHAR   channel
    );

VOID
HwInternalStartReqComplete(
    IN  PNIC        pNic
    );

ULONG
HwRSSI(
    PNIC        pNic,
    RX_STATUS_DESC_8187     RxDesc
    );

void
HwRestoreToBeforeScan(
    IN PNIC pNic
    );    

void
HwPeriodTimerHandler(
	IN PNIC pNic
	);	

void
HwPostSendHandler(
    IN PNIC     pNic,
    IN ULONG    sentBufferLength
    );



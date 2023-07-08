/****************************************************************************
** COPYRIGHT (C) Realtek Semiconductor Corp.,                              **
** THIS FILE IS PART OF THE Realtek RTL8180/RTL8185 Adapter driver         **
****************************************************************************/

NDIS_STATUS 
HwReadAdapterInfo(
	IN PNIC         pNic
	);

void	
HwInitializeAdapter(
	IN PNIC		pNic,
	IN BOOL     temp
	);

VOID
HwTxFillDescriptor(
    IN  PNIC       pNic,
    IN  PTX_DESC   pDesc,
    IN  PUCHAR     pHeader,
    IN  BOOLEAN    bFirstSeg,
    IN  BOOLEAN    bLastSeg,
    IN  ULONG      PhyAddressLow,
    IN  ULONG      BufferLen,
    IN  ULONG      PktLen,
    IN  USHORT     Rate,
    IN  BOOLEAN    bMulticast,
    IN  BOOLEAN    bUseShortPreamble,
    IN  BOOLEAN    bMoreFrag,
    IN  BOOLEAN    bRTSEnable,
    IN  BOOLEAN    bCTSToSelf,
    IN  USHORT     RTSRate,
    IN  BOOLEAN    bSetOwnBit,
    IN  BOOLEAN    bNoEncrypt,
    IN  ULONG      QueueID
	);

void
HwSwitchTxAntenna(
	IN PNIC			pNic
	);

void
HwSetNicPSMode(
	IN PNIC		pNic,
	IN BOOLEAN	bPowerSave
	);

VOID
HwInternalStartReqComplete(
    IN  PNIC        pNic
    );

ULONG
HwRSSI(
    IN  PNIC		pNic,
	IN  PNIC_RX_FRAGMENT    pNicFragment
	);

VOID
HwChangeTxpowerLevel(
    IN  PNIC        pNic,
    IN  ULONG	    powerLevelPercent
    );

// Phy functions
void SwChnlPhy(
	PNIC	pNic,
	UCHAR	channel,
	BOOLEAN HighIRQLevel
	);

void SetRFPowerState(
	PNIC	pNic,
	UCHAR	RFPowerState
	);

void SetTxPowerLevel(
	PNIC	pNic,
	UCHAR	channel,
	BOOLEAN HighIRQLevel
	);


void
CamAddOneEntry(
    IN  PNIC        pNic,
    IN  PNICKEY     NicKey,
    IN  UCHAR       KeyIndex
    );

void
CamDeleteOneEntry(
    IN PNIC  pNic,
    IN UCHAR KeyIndex
    );

void
CamSetEncryption(
    IN PNIC  pNic,
    IN DOT11_CIPHER_ALGORITHM algoId,
    IN BOOLEAN useDefaultKey
    );

void
UpdateBeaconSequenceNumber(
    IN PNIC  pNic
    );

void
HwSaveAdjustBeforeScan(
	IN PNIC pNic
	);

void
HwRestoreToBeforeScan(
	IN PNIC pNic
	);    

void
HwPeriodTimerHandler(
	IN PNIC pNic
	);	


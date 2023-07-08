/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    Hw_Nic.c

Abstract:
    HW layer NIC specific function
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created

Notes:

--*/
#define NIC_DELAY_POST_RESET            20

#define RX_DESC_SIZE	16
#define TX_DESC_SIZE	32

#define DoCoalesceThreshold		8

#define		NUM_11A_CHANNEL			46
#define		NUM_11G_CHANNEL			14

//regulatory domain
#define	DOMAIN_FROM_EEPROM				0x0100
#define	DOMAIN_FROM_COUNTRY				0x0200
#define	DOMAIN_FROM_UI					0x0400
#define	CHANNELPLAN_MASK					0x000f

// Regulatory domain values that are not defined yet in the windot11.h
#define HW_REG_DOMAIN_MKK1          0x00000041
#define HW_REG_DOMAIN_ISRAEL        0x00000042


#define MAX_BEACON_PERIOD		1024
#define LIMIT_BEACON_PERIOD(_Period)		\
	if((_Period)>=MAX_BEACON_PERIOD)		\
		(_Period)=MAX_BEACON_PERIOD-1;

#define	HWPERIOD_TIMER_IN_MS	2000 //ms


#define GetListHeadEntry(ListHead)  ((ListHead)->Flink)


// TODO: Testing Check For Hang hypothesis
/*
// N=1~...
#define HwIncrementNextDescToSend(	_pNic, _Queue, N)		\
	(_pNic)->TxInfo.TxNextDescToSend[_Queue]=((_pNic)->TxInfo.TxNextDescToSend[_Queue]+N)%(_pNic)->TxInfo.TxTotalDescNum[_Queue]

#define HwIncrementTxNextDescToCheck(_pNic, _Queue, N)		\
	(_pNic)->TxInfo.TxNextDescToCheck[_Queue]=((_pNic)->TxInfo.TxNextDescToCheck[_Queue]+N)%(_pNic)->TxInfo.TxTotalDescNum[_Queue]
*/

VOID
HwIncrementNextDescToSend(
    IN  PNIC    pNic,
    IN  INT     QueueIndex,
    IN  INT     Increment,
    IN  BOOLEAN bTxDescProtection);

/*
// N=1~...
#define HwIncrementNextDescToSend(_pNic, _Queue, N)		\
{                                                               \
	(_pNic)->TxInfo.TxNextDescToSend[_Queue]=((_pNic)->TxInfo.TxNextDescToSend[_Queue]+N)%(_pNic)->TxInfo.TxTotalDescNum[_Queue];   \
	InterlockedExchangeAdd(&(_pNic)->TxInfo.TxBusyDescCount[_Queue], (LONG)N);                 \
}
*/
#define HwIncrementTxNextDescToCheck(_pNic, _Queue, N)		\
{                                                               \
	(_pNic)->TxInfo.TxNextDescToCheck[_Queue]=((_pNic)->TxInfo.TxNextDescToCheck[_Queue]+N)%(_pNic)->TxInfo.TxTotalDescNum[_Queue]; \
	InterlockedExchangeAdd(&(_pNic)->TxInfo.TxBusyDescCount[_Queue], (((LONG)N) * -1));                 \
}

/*
    A lock protection is needed only for NORMAL_QUEUE.
    HIGH_QUEUE is used in ISR so no synchronization is needed.
    LOW_QUEUE is for data and synchronization is done else where.
*/
PTX_DESC
HwGetNextDescToSend(
    IN  PNIC    pNic,
    IN  INT     QueueIndex,
    IN  INT     Increment,
    IN  BOOLEAN bTxDescProtection
    );
/*
// N=0~...
#define HwGetNextDescToSend(_pNic,_Queue, N)		\
	&(_pNic)->TxInfo.TxDesc[_Queue][((_pNic)->TxInfo.TxNextDescToSend[_Queue]+N)%(_pNic)->TxInfo.TxTotalDescNum[_Queue]]
*/
#define HwGetNextDescToCheck(_pNic,_Queue, N)		\
	&(_pNic)->TxInfo.TxDesc[_Queue][((_pNic)->TxInfo.TxNextDescToCheck[_Queue]+N)%(_pNic)->TxInfo.TxTotalDescNum[_Queue]]


#define HwTxPolling(_pNic,_Queue)				\
	WritePortUchar( (_pNic), TPPoll, TPPoll_LPQ<<(_Queue))

#define HwNormalQGetNextToSendBuffer(_pNic)	\
	(_pNic)->TxInfo.pTxNormalQBufVa[(_pNic)->TxInfo.TxNextDescToSend[NORMAL_QUEUE]]

#define HwHighQGetNextToSendBuffer(_pNic)	\
	(_pNic)->TxInfo.pTxHighQBufVa[(_pNic)->TxInfo.TxNextDescToSend[HIGH_QUEUE]]

#define HwIsAddr1Match(_TxBuf,_Addr)			\
	(BOOLEAN)(memcmp((PUCHAR)(_TxBuf)+4, _Addr, 6)==0)

#define HwIsBroadcast(_TxBuf)										\
	((BOOLEAN)(													\
					((((UCHAR *)(_TxBuf))[4])==(UCHAR)0xff)	&&		\
					((((UCHAR *)(_TxBuf))[5])==(UCHAR)0xff)	&&		\
					((((UCHAR *)(_TxBuf))[6])==(UCHAR)0xff)	&&		\
					((((UCHAR *)(_TxBuf))[7])==(UCHAR)0xff)	&&		\
					((((UCHAR *)(_TxBuf))[8])==(UCHAR)0xff)	&&		\
					((((UCHAR *)(_TxBuf))[9])==(UCHAR)0xff)			\
																))

#define HwIsMulticast(_TxBuf)					\
	((BOOLEAN)(((_TxBuf)[4]&0x01)!=0))


void 
HwInitializeVariable(
	IN PNIC		pNic
	);

VOID
HwGetHardwareID(
	IN PNIC		pNic
	);

NDIS_STATUS 
HwSetNICAddress(
	IN  PNIC    pNic
	);

BOOLEAN
HwSetRFState(
    IN  PNIC    pNic,
    IN  UCHAR	RFPowerState
    );

// Called at passive
VOID
HwSetRadioState(
    IN  PNIC    pNic,
    IN  BOOLEAN bPowerOn
    );

USHORT 
HwGenerateBeacon(
	PNIC		pNic,
	PUCHAR		BeaconBuf,
	BOOLEAN		APModeFlag
	);

void 
HwSetupBeacon(
	PNIC		pNic,
	PUCHAR		BeaconBuf,
	USHORT 		BeaconBufLen,
	ULONG		BeaconBufPaLow,
	USHORT		Rate
	);

UCHAR
HwMRateToHwRate(
	UCHAR	rate
	);

UCHAR
HwHwRateToMRate(
	UCHAR	rate
	);

ULONG64
HwDataRateToLinkSpeed(
    UCHAR  rate
    );

NDIS_STATUS
HwAllocateAlignPhyMemory(
	PNIC					pNic,
	ULONG					Length,
	PUCHAR					*VirtualAddr,
	NDIS_PHYSICAL_ADDRESS	*PhysicalAddr,
	PUCHAR					*AlignVirtualAddr,
	NDIS_PHYSICAL_ADDRESS	*AlignPhysicalAddr
	);

void
HwLinkTxDesc(
	PUCHAR					VirtualAddr,
	NDIS_PHYSICAL_ADDRESS	PhysicalAddr,
	USHORT					DescSize,
	USHORT					DescNum
	);

ULONG
HwGetTxBusyDescNum(
	PNIC					pNic,
	int						QueueIndex
	);

ULONG
HwGetTxFreeDescNum(
	PNIC					pNic,
	int						QueueIndex
	);

void 
HwTransmitNextPacketWithLocalBuffer(
	IN PNIC		pNic,
	IN ULONG	QueueIndex,
	IN USHORT	PktSize,
	IN USHORT	Rate,
	IN BOOLEAN	bAIDContained,
	IN BOOLEAN  bTxDescProtection
	);

void
HwOnProbe(
	IN PNIC		pNic,
	IN PUCHAR	ProbePktBuf,
	IN USHORT	ProbePktLen,
	IN USHORT	ProbePktRate
	);

void
HwSendProbe(
	IN PNIC		            pNic,
	IN PDOT11_MAC_ADDRESS   pBSSID,
	IN PDOT11_SSID          pSSID,
	IN PUCHAR               ScanAppendIEByteArray,
	IN USHORT               ScanAppendIEByteArrayLength
	);

USHORT
HwGetHighestRate(
	IN PDOT11_RATE_SET	pRateSet
	);

LONG
HwGetPositionInBuffer(
	IN	ULONG	PriorLength,
	IN	ULONG	BufferLength,
	IN	ULONG	TotalOffset
	);

ULONG
HwGetPhysicalAddressFromScatterGatherList(
	IN SCATTER_GATHER_LIST 	*pFragList,
	IN ULONG				Offset
	);

//
// Hardware receive related function
//

VOID
HwReturnFragment(
	IN PNIC				pNic,
	IN PNIC_RX_FRAGMENT	pNicFragment
	);

VOID
HwResetReceive(
	IN  PNIC    pNic
	);

BOOLEAN
HwFragmentIsDuplicate(
    IN  PNIC                            pNic,
    IN  PNIC_RX_FRAGMENT                pNicFragment
    );

void
HwHandleTimingCriticalPacket(
	IN PNIC         pNic
	);

VOID
HwResponseToPacket(
	IN PNIC		        pNic,
	IN PNIC_RX_FRAGMENT pNicFragment
	);

BOOLEAN
HwFilterPacket(
	IN PNIC		        pNic,
	IN PNIC_RX_FRAGMENT pNicFragment
	);

void
HwScanCallback(
	IN PVOID		SystemSpecific1,
	IN PVOID		param,
	IN PVOID		SystemSpecific2,
	IN PVOID		SystemSpecific3 
	);

void
HwAwakeCallback(
	IN PVOID		SystemSpecific1,
	IN PVOID		param,
	IN PVOID		SystemSpecific2,
	IN PVOID		SystemSpecific3 
	);

void
HwPeriodTimerCallback(
	IN PVOID		SystemSpecific1,
	IN PVOID		param,
	IN PVOID		SystemSpecific2,
	IN PVOID		SystemSpecific3 
	);

VOID
HwSwChnlWorkItem(
	IN PVOID            Context,
	IN NDIS_HANDLE      NdisIoWorkItemHandle  // non-NULL only when NDIS calls back this routine
	);

void
HwJoinTimeoutCallback(
	IN PVOID		SystemSpecific1,
	IN PVOID		param,
	IN PVOID		SystemSpecific2,
	IN PVOID		SystemSpecific3 
	);

NDIS_STATUS
HwUpdateInfoFromBSSInformation(
	IN PNIC		pNic,
	IN PSTA_BSS_ENTRY        pBSSEntry
	);

NDIS_STATUS
HwSetPacketFilter(
	PNIC pNic,
	ULONG PacketFilter
	);


NDIS_STATUS
HwGetInfoIEWithOUI(
	IN PUCHAR pucInfoBlob,
	IN ULONG uSizeOfBlob,
	IN UCHAR ucInfoId,
	OUT PUCHAR pucLength,
	IN OUT PVOID * ppvInfoEle,
	IN OUT PULONG pOffset
	);
	
BOOLEAN
HwAddIE(
	IN PNIC		pNic,
	IN UCHAR	ID,
	IN UCHAR	Size,
	IN PUCHAR	Data
	);

VOID
HwRemoveIE(
	IN PNIC		pNic,
	IN UCHAR	ID,
	IN PUCHAR	Data
	);

PUCHAR
HwGetIE(
	IN PNIC		pNic,
	IN UCHAR	ID,
	IN UCHAR	Index,
	OUT PUCHAR	Size
	);

VOID
HwClearAllIE(
	IN PNIC		pNic
	);

BOOLEAN
HwSendNullPkt(
	IN PNIC		pNic
	);

BOOLEAN
HwSendPSPoll(
	IN PNIC		pNic
	);

ULONG
HwComputeCrc(
	IN PUCHAR Buffer,
	IN UINT Length
	);

VOID
HwGetMulticastBit(
	IN UCHAR Address[ETH_LENGTH_OF_ADDRESS],
	OUT UCHAR * Byte,
	OUT UCHAR * Value
	);

NDIS_STATUS
HwSetMulticastMask(
	IN PNIC		pNic,
	IN BOOLEAN	bAcceptAll
	);

VOID
HwDoze(
	IN PNIC		pNic,
	IN ULONG	ulDozeTime,
	IN BOOLEAN  bDeviceIRQL	
	);

BOOLEAN
HwAwake(
	IN PNIC		pNic,
	IN BOOLEAN  bDeviceIRQL
	);

void
HwRemoveKeyEntry(
    IN PNIC pNic,
    IN UCHAR index);

void
HwUpdateKeyEntry(
    IN PNIC pNic,
    IN PNICKEY pNicKey,
    IN UCHAR index);

void
HwAddKeyEntry(
    IN PNIC pNic,
    IN PNICKEY pNicKey,
    IN UCHAR index);

void
HwDeleteAllKeys(
    IN  PNIC pNic
    );

NDIS_STATUS
HwUpdateInfoFromdot11BSSDescription(
	IN PNIC		pNic,
	IN PDOT11_BSS_DESCRIPTION	dot11BSSDescription
	);

NDIS_STATUS
HwGetInfoIEWithOUI(
	IN PUCHAR pucInfoBlob,
	IN ULONG uSizeOfBlob,
	IN UCHAR ucInfoId,
	OUT PUCHAR pucLength,
	IN OUT PVOID * ppvInfoEle,
	IN OUT PULONG pOffset
	);

VOID
HwUpdateTxRetryStat(
    IN PNIC                 pNic,
    IN PMP_TX_MSDU          pMpTxd,
    IN USHORT               retryCount
    );

VOID
HwUpdateTxDataRate(
    IN PNIC                     pNic
    );



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

#define RX_DESC_SIZE    16
#define TX_DESC_SIZE    32

#define DoCoalesceThreshold     8

#define     NUM_11A_CHANNEL         46
#define     NUM_11G_CHANNEL         14

//   
//  regulatory domain
//
#define	DOMAIN_FROM_EEPROM				0x0100
#define	DOMAIN_FROM_COUNTRY				0x0200
#define	DOMAIN_FROM_UI					0x0400
#define	CHANNELPLAN_MASK                0x000f

// Regulatory domain values that are not defined yet in the windot11.h
#define HW_REG_DOMAIN_MKK1          0x00000041
#define HW_REG_DOMAIN_ISRAEL        0x00000042


#define MAX_BEACON_PERIOD       1024
#define LIMIT_BEACON_PERIOD(_Period)        \
    if((_Period)>=MAX_BEACON_PERIOD)        \
        (_Period)=MAX_BEACON_PERIOD-1;

#define	HWPERIOD_TIMER_IN_MS	2000 //ms

#define GetListHeadEntry(ListHead)  ((ListHead)->Flink)
#define GetListTailEntry(ListHead)  ((ListHead)->Blink)


// TODO: Testing Check For Hang hypothesis
/*
// N=1~...
#define HwIncrementNextDescToSend(  _pNic, _Queue, N)       \
    (_pNic)->TxInfo.TxNextDescToSend[_Queue]=((_pNic)->TxInfo.TxNextDescToSend[_Queue]+N)%(_pNic)->TxInfo.TxTotalDescNum[_Queue]

#define HwIncrementTxNextDescToCheck(_pNic, _Queue, N)      \
    (_pNic)->TxInfo.TxNextDescToCheck[_Queue]=((_pNic)->TxInfo.TxNextDescToCheck[_Queue]+N)%(_pNic)->TxInfo.TxTotalDescNum[_Queue]
*/

// N=1~...
#define HwIncrementNextDescToSend(_pNic, _Queue, N)     \
{                                                               \
    (_pNic)->TxInfo.TxNextDescToSend[_Queue]=((_pNic)->TxInfo.TxNextDescToSend[_Queue]+N)%(_pNic)->TxInfo.TxTotalDescNum[_Queue];   \
    InterlockedExchangeAdd(&(_pNic)->TxInfo.TxBusyDescCount[_Queue], (LONG)N);                 \
    MPVERIFY(HwGetTxBusyDescNum(_pNic, _Queue) == (ULONG)(_pNic)->TxInfo.TxBusyDescCount[_Queue]);   \
}

#define HwIncrementTxNextDescToCheck(_pNic, _Queue, N)      \
{                                                               \
    (_pNic)->TxInfo.TxNextDescToCheck[_Queue]=((_pNic)->TxInfo.TxNextDescToCheck[_Queue]+N)%(_pNic)->TxInfo.TxTotalDescNum[_Queue]; \
    InterlockedExchangeAdd(&(_pNic)->TxInfo.TxBusyDescCount[_Queue], (((LONG)N) * -1));                 \
    MPVERIFY(HwGetTxBusyDescNum(_pNic, _Queue) == (ULONG)(_pNic)->TxInfo.TxBusyDescCount[_Queue]);  \
}


// N=0~...
#define HwGetNextDescToSend(_pNic,_Queue, N)        \
    &(_pNic)->TxInfo.TxDesc[_Queue][((_pNic)->TxInfo.TxNextDescToSend[_Queue]+N)%(_pNic)->TxInfo.TxTotalDescNum[_Queue]]

#define HwGetNextDescToCheck(_pNic,_Queue, N)       \
    &(_pNic)->TxInfo.TxDesc[_Queue][((_pNic)->TxInfo.TxNextDescToCheck[_Queue]+N)%(_pNic)->TxInfo.TxTotalDescNum[_Queue]]

#define HwGetHWDESCAdjustedBuffer(Buf) \
           ( (PUCHAR)(Buf) + RTL8187_HWDESC_HEADER_LEN )

PVOID
HwNormalQGetNextToSendBuffer(
    IN  PNIC       Nic
    );

PVOID
HwHighQGetNextToSendBuffer(
    IN  PNIC       Nic
    );

#define HwIsAddr1Match(_TxBuf,_Addr)            \
    (BOOLEAN)(memcmp((PUCHAR)(_TxBuf)+4, _Addr, 6)==0)

#define HwIsBroadcast(_TxBuf)                                       \
    ((BOOLEAN)(                                                 \
                    ((((UCHAR *)(_TxBuf))[4])==(UCHAR)0xff) &&      \
                    ((((UCHAR *)(_TxBuf))[5])==(UCHAR)0xff) &&      \
                    ((((UCHAR *)(_TxBuf))[6])==(UCHAR)0xff) &&      \
                    ((((UCHAR *)(_TxBuf))[7])==(UCHAR)0xff) &&      \
                    ((((UCHAR *)(_TxBuf))[8])==(UCHAR)0xff) &&      \
                    ((((UCHAR *)(_TxBuf))[9])==(UCHAR)0xff)         \
                                                                ))

#define HwIsMulticast(_TxBuf)                   \
    ((BOOLEAN)(((_TxBuf)[4]&0x01)!=0))


typedef struct _TIMER_NIC_CONTEXT {
    PNIC        Nic;
}   TIMER_NIC_CONTEXT, *PTIMER_NIC_CONTEXT;

//
// Specify an accessor method for the WMI_SAMPLE_DEVICE_DATA structure.
//
WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(TIMER_NIC_CONTEXT, GetTimerContext)

typedef struct _WORKITEM_CONTEXT {
    PNIC        Nic;
}   WORKITEM_CONTEXT, *PWORKITEM_CONTEXT;

//
// Specify an accessor method for the WMI_SAMPLE_DEVICE_DATA structure.
//
WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(WORKITEM_CONTEXT, GetWorkItemContext)



void 
HwInitializeVariable(
    IN PNIC     Nic
    );

void 
HwResetVariable(
    IN PNIC     Nic
    );

VOID
HwSetHardwareID(
    IN PNIC     Nic
    );

NDIS_STATUS 
HwSetNICAddress(
    IN  PNIC Nic
    );

BOOLEAN
HwSetRFState(
    IN  PNIC                Nic,
    IN  RT_RF_POWER_STATE   RFPowerState
    );

//
// Called at passive
//
VOID
HwSetRadioState(
    IN  PNIC    Nic,
    IN  BOOLEAN bPowerOn
    );


USHORT 
HwGenerateBeacon(
    PNIC        Nic,
    PUCHAR      BeaconBuf,
    BOOLEAN     APModeFlag
    );

void 
HwSetupBeacon(
    PNIC        Nic,
    PUCHAR      BeaconBuf,
    USHORT      BeaconBufLen,
    ULONG       BeaconBufPaLow,
    USHORT      Rate
    );

UCHAR
HwMRateToHwRate(
    UCHAR   Rate
    );

UCHAR
HwHwRateToMRate(
    UCHAR   Rate
    );

ULONG64
HwDataRateToLinkSpeed(
    UCHAR  Rate
    );

NDIS_STATUS
HwAllocateAlignPhyMemory(
    PNIC                    Nic,
    ULONG                   Length,
    PUCHAR                  *VirtualAddr,
    NDIS_PHYSICAL_ADDRESS   *PhysicalAddr,
    PUCHAR                  *AlignVirtualAddr,
    NDIS_PHYSICAL_ADDRESS   *AlignPhysicalAddr
    );

void
HwLinkTxDesc(
    PUCHAR                  VirtualAddr,
    NDIS_PHYSICAL_ADDRESS   PhysicalAddr,
    USHORT                  DescSize,
    USHORT                  DescNum
    );

ULONG
HwGetTxBusyDescNum(
    PNIC                    Nic,
    int                     QueueIndex
    );

ULONG
HwGetTxFreeDescNum(
    PNIC                    Nic,
    int                     QueueIndex
    );

void 
HwTransmitNextPacketWithLocalBuffer(
    IN PNIC     Nic,
    IN UCHAR    QueueIndex,
    IN USHORT   PktSize,
    IN USHORT   Rate,
    IN BOOLEAN  bAIDContained,
    IN PUCHAR   Desc
    );

void
HwOnProbe(
    IN PNIC     Nic,
    IN PUCHAR   ProbePktBuf,
    IN USHORT   ProbePktLen,
    IN USHORT   ProbePktRate
    );

void
HwSendProbe(
    IN PNIC                 Nic,
    IN PDOT11_MAC_ADDRESS   BSSID,
    IN PDOT11_SSID          SSID,
    IN PUCHAR               ScanAppendIEByteArray,
    IN USHORT               ScanAppendIEByteArrayLength
    );

USHORT
HwGetHighestRate(
    IN PDOT11_RATE_SET  RateSet
    );

LONG
HwGetPositionInBuffer(
    IN  ULONG   PriorLength,
    IN  ULONG   BufferLength,
    IN  ULONG   TotalOffset
    );

ULONG
HwGetPhysicalAddressFromScatterGatherList(
    IN SCATTER_GATHER_LIST  *FragList,
    IN ULONG                Offset
    );

//
// Hardware receive related function
//

VOID
HwReturnFragment(
    IN PNIC             Nic,
    IN PNIC_RX_FRAGMENT NicFragment
    );

VOID
HwResetReceive(
    IN  PNIC    Nic
    );

BOOLEAN
HwFragmentIsDuplicate(
                     IN  PNIC              Nic,
                     IN  PNIC_RX_FRAGMENT  NicFragment
                     );

void
HwHandleTimingCriticalPacket(
    IN PNIC         Nic
    );


VOID
HwResponseToPacket(
    IN PNIC             Nic,
    IN PNIC_RX_FRAGMENT NicFragment
    );

BOOLEAN
HwFilterPacket(
    IN PNIC             Nic,
    IN PNIC_RX_FRAGMENT NicFragment
    );

VOID
HwScanCallback(
     IN WDFTIMER  Timer
    );

void
HwAwakeCallback(
    IN WDFTIMER  Timer
    );

VOID
HwSwChnlWorkItem(
    IN WDFWORKITEM  WorkItem
    );

VOID
HwSwChnlWorker(
    PNIC    Nic 
    );

void
HwJoinTimeoutCallback(
    IN  WDFTIMER  Timer
    );

VOID
HwPeriodTimerCallback(
    IN WDFTIMER     Timer
    );

NDIS_STATUS
HwUpdateInfoFromBSSInformation(
    IN PNIC             Nic,
    IN PSTA_BSS_ENTRY   BSSEntry
    );

NDIS_STATUS
HwSetPacketFilter(
    PNIC    Nic,
    ULONG   PacketFilter
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
    IN PNIC     Nic,
    IN UCHAR    ID,
    IN UCHAR    Size,
    IN PUCHAR   Data
    );

VOID
HwRemoveIE(
    IN PNIC     Nic,
    IN UCHAR    ID,
    IN PUCHAR   Data
    );

PUCHAR
HwGetIE(
    IN PNIC     Nic,
    IN UCHAR    ID,
    IN UCHAR    Index,
    OUT PUCHAR  Size
    );

VOID
HwClearAllIE(
    IN PNIC     Nic
    );

BOOLEAN
HwSendNullPkt(
    IN PNIC     Nic
    );          

BOOLEAN
HwSendPSPoll(
    IN PNIC     Nic
    );

ULONG
HwComputeCrc(
    IN PUCHAR   Buffer,
    IN UINT     Length
    );

VOID
HwGetMulticastBit(
    IN UCHAR    Address[ETH_LENGTH_OF_ADDRESS],
    OUT UCHAR * Byte,
    OUT UCHAR * Value
    );

NDIS_STATUS
HwSetMulticastMask(
    IN PNIC     Nic,
    IN BOOLEAN  bAcceptAll
    );

VOID
HwDoze(
    IN PNIC     Nic,
    IN ULONG    ulDozeTime
    );

BOOLEAN
HwAwake(
    IN PNIC     Nic
    );

void
HwRemoveKeyEntry(
    IN PNIC Nic,
    IN UCHAR Index,
    IN  DOT11_CIPHER_ALGORITHM  AlgoId
    );

void
HwAddKeyEntry(
    IN PNIC Nic,
    IN PNICKEY NicKey,
    IN UCHAR Index);

void
HwDeleteAllKeys(
    IN  PNIC Nic
    );

NDIS_STATUS
HwUpdateInfoFromdot11BSSDescription(
    IN PNIC     Nic,
    IN PDOT11_BSS_DESCRIPTION   Dot11BSSDescription
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

UCHAR
HwTxRetryLimit(
    IN  PNIC    Nic,
    IN  USHORT  DataRate    
    );

USHORT
GetSequenceNumber(
    IN PNIC        Nic
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




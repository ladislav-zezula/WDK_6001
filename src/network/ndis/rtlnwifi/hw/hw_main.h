/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    Hw_Main.h

Abstract:
    HW layer defines
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created

Notes:

--*/
#ifndef _NATIVE_WIFI_HW_MAIN_H
#define _NATIVE_WIFI_HW_MAIN_H

#include "r8180equ.h"
#include "rtl8180.h"
#include "hw_80211.h"

#include "r8185typ.h"
#include "rtl8185.h"

#define HW11_MEMORY_TAG         'HltR'

#define LOW_QUEUE			0
#define NORMAL_QUEUE		1
#define HIGH_QUEUE			2
#define BEACON_QUEUE		3
#define TX_QUEUE_NUM		4

#define MAX_NUM_PHY_TYPES                       5
#define MAX_NUM_DOT11_REG_DOMAINS_VALUE         10
#define MAX_NUM_DIVERSITY_SELECTION_RX_LIST     256

#define MAX_MPDU_LENGTH                         2346

#define MAX_IE_NUMBER                           10      // Max value is 128 (one bit reserved)

#define KEY_TABLE_SIZE                          16
#define KEY_MAPPING_KEY_TABLE_SIZE              (KEY_TABLE_SIZE - DOT11_MAX_NUM_DEFAULT_KEY)
#define PER_STA_KEY_TABLE_SIZE                  KEY_MAPPING_KEY_TABLE_SIZE

#define DUPLICATE_DETECTION_CACHE_LENGTH        8

// 
// If link quality of the AP we are associated with is below this value,
// we will use the lower data rate for communicating with this AP
//
#define LOW_RATE_LINK_QUALITY_THRESHOLD         40 
//
// The lower data rate we would select would be some value below this
// max
//
#define LOW_RATE_MAX_DATA_RATE                  24

#define WritePortUchar(pNic, Address, Val)     \
    WRITE_PORT_UCHAR( (PUCHAR)((PUCHAR)pNic->CardInfo.PortOffset + Address), (UCHAR)(Val))
#define WritePortUshort(pNic, Address, Val)     \
    WRITE_PORT_USHORT( (PUSHORT)((PUCHAR)pNic->CardInfo.PortOffset + Address), (USHORT)(Val))
#define WritePortUlong(pNic, Address, Val)     \
    WRITE_PORT_ULONG( (PULONG)((PUCHAR)pNic->CardInfo.PortOffset + Address), (ULONG)(Val))


#define ReadPortUchar(pNic, Address, Val)     \
    (*Val = READ_PORT_UCHAR( (PUCHAR)((PUCHAR)pNic->CardInfo.PortOffset + Address)))
#define ReadPortUshort(pNic, Address, Val)     \
    (*Val = READ_PORT_USHORT( (PUSHORT)((PUCHAR)pNic->CardInfo.PortOffset + Address)))
#define ReadPortUlong(pNic, Address, Val)     \
    (*Val = READ_PORT_ULONG( (PULONG)((PUCHAR)pNic->CardInfo.PortOffset + Address)))


#define UpdatePortUchar(pNic, Address, UpdateOperation)             \
{                                                                   \
    UCHAR   _tempReadVal_;                                          \
    ReadPortUchar(pNic, Address, &_tempReadVal_);                   \
    WritePortUchar(pNic, Address, (_tempReadVal_ UpdateOperation));  \
}


#define HW11_RESOURCE_BUFFER_SIZE       (sizeof(NDIS_RESOURCE_LIST) \
                                            + (10 * sizeof(CM_PARTIAL_RESOURCE_DESCRIPTOR)))
#define HW_PCI_CONFIG_BUFFER_LENGTH	    PCI_COMMON_HDR_LENGTH

#define NIC_MAP_IOSPACE_LENGTH			sizeof(REG_STRUC)

#define NIC_INTERRUPT_MODE				NdisInterruptLevelSensitive 

#define NIC_NUM_REG_PARAMS              (((ULONG)sizeof (NICRegTable)) / ((ULONG)sizeof(NIC_REG_ENTRY)))


#define     HW_DEFAULT_PROBE_DELAY                      0
#define     HW_DEFAULT_ACTIVE_SCAN_CHANNEL_PARK_TIME    60
#define     HW_DEFAULT_PASSIVE_SCAN_CHANNEL_PARK_TIME   130

typedef struct _CHANNEL_LIST {
	ULONG	channel[200];
	ULONG	len;
} CHANNEL_LIST, *PCHANNEL_LIST;

//
// If we want to send multiple probes per channel, we can add an
// extra state e.g. ScanStatePerformScan_Pass2 and it will happen
//
typedef enum _SCAN_STATE
{
	ScanStateSwChnl = 0,
	ScanStatePerformScan_Pass1,
	ScanStateMaxState
} SCAN_STATE;


EXTERN CHANNEL_LIST	ChannelListAB[];
EXTERN CHANNEL_LIST	ChannelListB[];

typedef NDIS_STATUS
(*HW_RECEIVE_PROCESSING_FUNCTION)(
	IN PNIC		        pNic,
	IN PNIC_RX_FRAGMENT pNicFragment
	);

typedef enum _RF_POWER_STATE {
	RF_ON,                          // Radio ON
	RF_SLEEP,                       // Radio in low power save
	RF_OFF,                         // Radio OFF due to power save
	RF_SHUT_DOWN                    // Radio turned OFF
} RF_POWER_STATE, *PRF_POWER_STATE;

typedef enum _NIC_STATE {
	NIC_INIT_STATE,
	NIC_OP_STATE
} NIC_STATE, * PNIC_STATE;

typedef enum _STA_JOIN_STATE {
	STA_JOIN_STATE_IDLE,
	STA_JOIN_STATE_WAIT_BEACON,
	STA_JOIN_STATE_AUTHENTICATE,
	STA_JOIN_STATE_ASSOCIATE,
	STA_JOIN_STATE_SUCCESS
} STA_JOIN_STATE, *PSTA_JOIN_STATE;


typedef enum _STA_AUTH_AGLORITHM {
	STA_AUTH_ALGORITHM_OPEN,
	STA_AUTH_ALGORITHM_SHARED
} STA_AUTH_ALGORITHM, *PSTA_AUTH_ALGORITHM;


typedef enum _STA_AUTH_STATE {
	STA_AUTH_STATE_IDLE,
	STA_AUTH_STATE_WAIT_SECOND_FRAME,
	STA_AUTH_STATE_WAIT_FOURTH_FRAME,
	STA_AUTH_STATE_SUCCESS
} STA_AUTH_STATE, *PSTA_AUTH_STATE;


typedef enum _STA_ASSOCIATE_STATE {
	STA_ASSOCIATE_STATE_IDLE,
	STA_ASSOCIATE_STATE_WAIT_RESPONSE,
	STA_ASSOCIATE_STATE_SUCCESS
} STA_ASSOCIATE_STATE, *PSTA_ASSOCIATE_STATE;


typedef struct _JOIN_REQUEST_INFO {
	STA_JOIN_STATE				JoinState;
	STA_AUTH_ALGORITHM			AuthAlgorithm;
	STA_AUTH_STATE				AuthState;
	STA_ASSOCIATE_STATE		    AssoState;
	PDOT11_STATUS_INDICATION	pDot11StatusIndication;
} JOIN_REQUEST_INFO, *PJOIN_REQUEST_INFO;

typedef struct _IE {
	BOOLEAN		bUse;
	UCHAR		ID;
	ULONG		OUI;
	UCHAR		Size;
	UCHAR		Data[256];
} IE, *pIE;


typedef struct _NIC_REG_ENTRY {
	NDIS_STRING		RegName;		// variable name text
	BOOLEAN			bRequired;		// 1 -> required, 0 -> optional
	UCHAR			Type;			// NdisParameterInteger/NdisParameterHexInteger/NdisParameterStringle/NdisParameterMultiString
	UINT			StructOffset;		// offset of struct to MP_ADAPTER field
	UINT			FieldOffset;		// offset to structure
	UINT			FieldSize;		// size (in bytes) of the field
	UINT			Default;			// default value to use
	UINT			Min;				// minimum value allowed
	UINT			Max;			// maximum value allowed
} NIC_REG_ENTRY, *PNIC_REG_ENTRY;


typedef struct _DUPE_CACHE_ENTRY {
    USHORT          SequenceControl;
    DOT11_MAC_ADDRESS   Address2;
} DUPE_CACHE_ENTRY, *PDUPE_CACHE_ENTRY;

typedef
VOID
(*HW_CHANNEL_SWITCH_COMPLETE_HANDLER)(
    IN  PNIC    pNic
    );


typedef struct _HwFragment {
	ULONG		PacketOffset;
	ULONG		PhyAddrLow;
	ULONG		Length;
	ULONG		FragIndex;
	UCHAR		StartOfFrag:1;
	UCHAR		EndOfFrag:1;
} HwFragment, *PHwFragment;


typedef struct _RX_SEQUENCE{
	unsigned short	FragmentNum:4;
	unsigned short	SequenceNum:12;
} RX_SEQUENCE, *PRX_SEQUENCE;

typedef	enum _RT_BUS_TYPE{
	BUS_TYPE_CARDBUS,
	BUS_TYPE_MINIPCI,
	BUS_TYPE_PCI,
} RTBusType;

typedef enum _HARDWARE_ID{
	HW_ID_8180,
	HW_ID_8185
} HARDWARE_ID, *PHARDWARE_ID;

typedef	enum _VERSION_ID {
	VERSION_8180    = 0x00000000,
	VERSION_8180_D  = 0x00000100,
	VERSION_8180_F  = 0x00000200,
    VERSION_8185    = 0x01000000,	// Generic, don't use this one
	VERSION_8185_C  = 0x01000100,	// for Rtl8185 version A~C
	VERSION_8185_D  = 0x01000200,
} VERSION_ID, *PVERSION_ID;

typedef struct _NIC_TX_MSDU {
    // Used to link the TX MSDU in our ready to send list
	LIST_ENTRY                  PostSGLink;
    
    // Added as dummy for now
	PMP_TX_MSDU					pMpTxd;

	NDIS_PHYSICAL_ADDRESS		NicTxdPhysicalAddress;
	
	PUCHAR						CoalesceBuf;
	NDIS_PHYSICAL_ADDRESS		CoalesceBufPa;		
	
	BOOLEAN						WaitSendToComplete;
	BOOLEAN						bFailedDuringSend;
	BOOLEAN						bMulticastDestAddr;
	BOOLEAN						RTSEnabled;
    BOOLEAN                     TxSucceeded;
	ULONG                       TotalMSDULength;
	USHORT						QueueIDUsed;
	USHORT                      TxRate;
	ULONG						FirstDescUsed;
	ULONG						TotalDescUsed;
	ULONG						SucceedFragCount;
	
} NIC_TX_MSDU, *PNIC_TX_MSDU;


typedef struct _NIC_RX_FRAGMENT {
	LIST_ENTRY			    FragmentList;
	PMP_RX_FRAGMENT         MpFragment;
	RX_DESC				    RxDesc;
	USHORT					RxDescNum;
	PETH_RX_BUFFER_STRUC	RxBuffer;
	NDIS_PHYSICAL_ADDRESS	RxBufferPhys;
	RX_SEQUENCE				SequenceControl;
    USHORT                  DataSize;
    USHORT                  DataOffset;
    BOOLEAN                 Encrypted;
    BOOLEAN                 Unicast;        // Not Multicast or broadcast
    UCHAR                   Channel;        // channel number at which the frame was received, valid only for
                                            // beacon and probe response frames.
    PNICKEY                 NicKey;
    ULONGLONG               FrameNumber;
} NIC_RX_FRAGMENT, *PNIC_RX_FRAGMENT;


typedef struct _NIC_RX_MSDU
{
	LIST_ENTRY              Link;
	ULONG                   TotalPacketSize;
	ULONG                   NumFragments;
	PNIC_RX_FRAGMENT        Fragments[16];
} NIC_RX_MSDU, *PNIC_RX_MSDU;


typedef struct _NICCARDINFO {
	UCHAR					PermanentAddress[6];
	UCHAR					MacAddr[6];
	UCHAR					StationID[6];	// Not for Tx/Rx
	BOOLEAN					bOverrideAddress;

	ULONG					IoBaseAddress;
	PVOID					CSRAddress;
	PVOID					PortOffset;
	ULONG					IoRange;
	
	UCHAR					RevisionID;
	USHORT					SubVendorID;
	USHORT					SubSystemID;

    BOOLEAN					AutoloadFailFlag;
	BOOLEAN					ResetInProgress;

	BOOLEAN                 SurpriseRemoved;

	BOOLEAN					InterruptsAreEnabled;
	USHORT					IntrMask;

	//NDIS_MINIPORT_INTERRUPT	Interrupt;
	ULONG					InterruptLevel;

	NDIS_PHYSICAL_ADDRESS	MemPhysAddress;
	ULONG					SlotNumber;

	BOOLEAN					MWIEnable;

	HARDWARE_ID			    HardwareID;
	VERSION_ID				VersionID;
	BOOLEAN					SoftwareSeq;
	RTBusType				BusType;
	UCHAR					VerificationType;

	// contention window
	UCHAR				    RegPacketControlCW;

	// retry limit
	UCHAR				    RegPacketControlRL;

	// Tx AGC
	UCHAR				    RegPacketControlAGC;
	UCHAR				    RegAGC;
	UCHAR				    RegCCK_TxAGC;
	UCHAR				    RegOFDM_TxAGC;

	// Tx Antenna
	UCHAR				    RegPacketControlAntenna;
	UCHAR				    RegAntenna;
	UCHAR				    RegCCK_TxAntenna;
	UCHAR				    RegOFDM_TxAntenna;
	UCHAR				    RegFeedbackControlAntenna;

	// auto rate fallback control
	BOOLEAN				    bRegAutoRateFallback;
	UCHAR				    RegAutoRateFallbackStep;

	BRSR_AR_STRUCT		    BRSR_AR_Setting;
} NICCARDINFO, *PNICCARDINFO;


typedef struct _NICRXINFO {
	PUCHAR					RxDescVa;						// Desc virtual address without alignment
	NDIS_PHYSICAL_ADDRESS	RxDescPa;						// Physical address withouy alignment
	PRX_DESC				RxDesc;							// Desc virtual address with alignment
	NDIS_PHYSICAL_ADDRESS	RxDescPhy;						// Physical address with alignment

	NDIS_SPIN_LOCK			FragListLock;
	LIST_ENTRY				RxFragList;
	USHORT 					RxFragListLen;

	DUPE_CACHE_ENTRY        DupePacketCache[2 * DUPLICATE_DETECTION_CACHE_LENGTH];
	UCHAR                   NextDupeCacheIndexData;         // Next index to put entry in for data packets
	UCHAR                   NextDupeCacheIndexOther;        // Next index to put entry in for other packets

    LIST_ENTRY				RxUnusedFragList;               // List of fragments not currently in use
    
	USHORT					RxTotalDescNum;				    // Hw support Desc max_number
	USHORT					RxAvailableDescNum;			    // Num HW_DESC free for hardware to use
	USHORT					RxNextDescToReturn;			    // Hw Desc current using id_number
	USHORT					RxNextDescToReceive;			// The next desc hardware will fill in

	HW_RECEIVE_PROCESSING_FUNCTION      ReceiveProcessingFunction;
	ULONG					ReceiveFilter;					// This filter is got from OID
	NDIS_SPIN_LOCK          ReceiveFilterLock;              // Lock to protect setting of this filter
	
	ULONG					ReceiveConfig;					// This filter is for a Hw filter

	NPAGED_LOOKASIDE_LIST	RecvFRAGMENTLookaside; 	    	// lookaside lists for NIC_RX_FRAGMENT

	// Multicast Address List
	UINT					MCAddressCount;
	UCHAR					MCAddressList[HW11_MAX_MCAST_LIST_SIZE][DOT11_ADDRESS_SIZE];
	UCHAR					MCRegValues[8];
	
} NICRXINFO, *PNICRXINFO;


typedef struct _NICTXINFO {
	PUCHAR					TxDescVa[TX_QUEUE_NUM];		// Desc virtual address without alignment
	NDIS_PHYSICAL_ADDRESS	TxDescPa[TX_QUEUE_NUM];		// Physical address without alignment
	PTX_DESC				TxDesc[TX_QUEUE_NUM];			// Desc virtual address with alignment
	NDIS_PHYSICAL_ADDRESS	TxDescPhy[TX_QUEUE_NUM];		// Physical address with alignment

	USHORT					TxTotalDescNum[TX_QUEUE_NUM];

    NDIS_SPIN_LOCK          TxDescLock;
	LONG					TxNextDescToSend[TX_QUEUE_NUM];
	LONG					TxNextDescToCheck[TX_QUEUE_NUM];
	LONG                    TxBusyDescCount[TX_QUEUE_NUM];

	PUCHAR					*pTxNormalQBufVa;				// Pointer array for Normal queue buffer
	NDIS_PHYSICAL_ADDRESS	*pTxNormalQBufPa;

	PUCHAR					*pTxHighQBufVa;					// Pointer array for High queue buffer
	NDIS_PHYSICAL_ADDRESS	*pTxHighQBufPa;

	PUCHAR					TxBeaconBufVa[2];				// Beacon queue buffer
	NDIS_PHYSICAL_ADDRESS	TxBeaconBufPa[2];

	ULONG					TransmitConfig;

    // MSDU that we have been SGed, but we are not able to send
    // due to lack of enough descriptors would be temporarily queued
    // here. The MP portion is lead to believe that these packets
    // actually have been submitted to hardware    
	LIST_ENTRY              PostSGMSDUList;

	NDIS_SPIN_LOCK          PostSGListLock;

	LONG                    PostSGMSDUListLength;   // Incremented after adding PostSGMSDUList
	                                                // and decremented after removing

    LONG                    Reserved;

	UCHAR                   TxPowerLevelPercent;	//change the powerlevel of Tx

	USHORT                  SequenceNumber;         // Sequence number for 8185

    ULONG                   MinPacketsSentForTxRateUpdate;
    ULONG                   TxFailureThresholdForRateFallback;
    ULONG                   TxFailureThresholdForRateIncrease;
    ULONG                   TxFailureThresholdForRoam;
    ULONG                   TxDataRateFallbackSkipLevel;
} NICTXINFO, *PNICTXINFO;


typedef struct _NICEEPROMINFO {
	UCHAR					EepromAddressSize;
	USHORT					EEPROMVersion;
	BOOLEAN					AutoloadFailFlag;
} NICEEPROMINFO, *PNICEEPROMINFO;

typedef struct _NICRFINFO {
	// RF chip information
	USHORT					RFChipID;
	UCHAR					RFProgType;
	BOOLEAN					DigitalPhy;
	USHORT					ChannelPlan;

    // RF power state
	BOOLEAN					RadioOff;						// True if we want long-term Radio off 
	RF_POWER_STATE			RFPowerState;					// Current Radio state
    LONG                    AccessRefCount;
    BOOLEAN                 RadioStateChangeInProgress;
    
    // Tx Power control
	UCHAR					TxPowerLevel[200];	// Zero-based channel index
	UCHAR					TxPowerLevelOFDM[200];

	UCHAR					EEPROMTxPowerLevel[200];	// Zero-based channel index
	UCHAR					EEPROMTxPowerLevelOFDM[200];

	// Reg Domain
	USHORT					RegDomain;

    // Carrier Sense
	USHORT					CSThreshold;
	ULONG					CSMethod;

    // Antenna Settings
	BOOLEAN					AntennaDiversity;
	BOOLEAN					DefaultAntennaB;
	ULONG					CurrentTxAntenna;
	ULONG					CurrentRxAntenna;

	BOOLEAN					bThreeWireMode;
	UCHAR					EnergyThreshold;
	UCHAR					InterfaceDebugMode;
	UCHAR					EnableGPIO0;
	ULONG					VersionID;
	BOOLEAN					b2ndCut;
	UCHAR					RegZebraVersion;
	UCHAR					ChargePump;
	UCHAR					TXChargePump;
	UCHAR					RXChargePump;
	UCHAR					CornerChange;
	UCHAR					TXAntenna;
	UCHAR					RXAntenna;
	UCHAR					TXOFDMPower;
	UCHAR					TXCCKPower;
	UCHAR					FastFalseAlarm;
	UCHAR					CCKFastFalseAlarm;
	UCHAR					EVMCheck;
	UCHAR					SamplingPhase;
	UCHAR					AGCmode;
	LONG					SmoothedSignalStrength;
	WIRELESS_MODE			OMC_CurrentWirelessMode;
	BOOLEAN					bTRSwitch;

	//dig function
	//BOOLEAN				bDebugDIG;
	BOOLEAN					bDig;
	UCHAR					DIG_CurrentInitialGain;
		
	ULONG					DIG_UpgradeThreshold;
	ULONG					DIG_FallbackThreshold;
		
	USHORT					DIG_NumberUpgradeVote;
	USHORT					DIG_NumberFallbackVote;
	USHORT					DIG_NumberCCKUpgradeVote;//for CCK false alarm
	USHORT					DIG_NumberCCKFallbackVote;//for CCK false alarm
	BOOLEAN					DIG_bTimeUnitDirty;
	UCHAR					ImprovingSensitivity;
	//save_info_before_scan
	UCHAR					BForScan_DIG_InitialGain;	
	UCHAR					BForScan_EnergyThreshold;
	
	
} NICRFINFO, *PNICRFINFO;

typedef struct _NICSTATISTICSINFO {

    ULONGLONG				RxNoBuf;    // RX no buffer error

    ULONGLONG		NumTxBeaconOk;
    ULONGLONG		NumTxBeaconErr;	
	
    DOT11_MAC_FRAME_STATISTICS  UcastCounters;
    DOT11_MAC_FRAME_STATISTICS  McastCounters;
    DOT11_PHY_FRAME_STATISTICS  PhyCounters[MAX_NUM_PHY_TYPES];

} NICSTATISTICSINFO, *PNICSTATISTICSINFO;


typedef struct _NICDUPLICATEINFO {
	USHORT					EarlyRxThreshold;
	USHORT					DefaultBeaconRate;  // Default beacon rate for b/g mode
	ULONG					RTS_Threshold;
	ULONG					Frag_Threshold;
	ULONG					ShortRetryLimit;
	ULONG					LongRetryLimit;
	ULONG					MaxTxLifeTime;
	ULONG					MaxRxLifeTime;
	ULONG					MediaOccupancyLimit;
	ULONG					CFPPeriod;
	ULONG					CFPMaxDuration;
	ULONG					BeaconInterval;
	ULONG                   JoinFailureTimeout;
} NICDUPLICATEINFO, *PNICDUPLICATE;

typedef struct _NICKEY
{
    BOOLEAN                     Persistent;
    BOOLEAN                     Valid;
    DOT11_MAC_ADDRESS           MacAddr;
    DOT11_CIPHER_ALGORITHM      AlgoId;
    UCHAR                       KeyLength;              // length of KeyValue in bytes
    UCHAR                       KeyValue[16];           // 128 bits
    UCHAR                       TxMICKey[8];            // for TKIP only
    UCHAR                       RxMICKey[8];            // for TKIP only
    union {
        struct {
            ULONGLONG           PN:48;                  // for CCMP
            ULONGLONG           PN_unused:16;
        };
        struct {
            ULONGLONG           TSC:48;                 // for TKIP
            ULONGLONG           TSC_unused:16;
        };
        struct {
            ULONG               IV:24;                  // for WEP 
            ULONG               IV_unused:8;
        };
    };
    struct {
        ULONGLONG               ReplayCounter:48;       // for CCMP or TKIP
        ULONGLONG               ReplayCounter_unused:16;
    };
} NICKEY, *PNICKEY;

typedef struct _NIC_PER_STA_KEY
{
    DOT11_MAC_ADDRESS           StaMacAddr;
    BOOLEAN                     Valid;
    NICKEY                      NicKey[DOT11_MAX_NUM_DEFAULT_KEY];
} NIC_PER_STA_KEY, *PNIC_PER_STA_KEY;

//
// PHY specific MIB. The MIB could be different for different vendors.
//
typedef struct _NICPHYMIB       
{
    DOT11_PHY_TYPE                      PhyType;
    ULONG                               PhyID;
    DOT11_RATE_SET                      OperationalRateSet;
    DOT11_RATE_SET                      BasicRateSet;
    DOT11_RATE_SET                      ActiveRateSet;
    UCHAR                               Channel;
    DOT11_SUPPORTED_DATA_RATES_VALUE_V2	SupportedDataRatesValue;
} NICPHYMIB, *PNICPHYMIB;

//
// Encryption info structure
//
typedef struct _NIC_ENCRYPTION_INFO
{
    UCHAR       RetreatedSize;
    BOOLEAN     MICMdlAdded;
    PVOID       MICData;
    ULONG       LastMdlByteCount;
    PMDL        MICMdl;    
} NIC_ENCRYPTION_INFO, *PNIC_ENCRYPTION_INFO;

typedef struct _NICMANAGEMENTINFO
{
	// switch channel related variable
	BOOLEAN								SwChnlInProgress;		// indicate if switch channel is in progress
	UCHAR								DestChannel;			// destination channel in channel switch
	HW_CHANNEL_SWITCH_COMPLETE_HANDLER  ChannelSwitchedHandler;
	NDIS_HANDLE 						SwChnlWorkItem;
	UCHAR								SwChnlStage;
	UCHAR								SwChnlStep;

	// Scan related variable
	NDIS_MINIPORT_TIMER					Timer_Scan;				// timer for survey scan
	BOOLEAN								bScanInProgress;
	BOOLEAN                             ScanCancelOperation;          // indicates if scan should be stopped
    PDOT11_SCAN_REQUEST_V2              ScanRequest;
    ULONG                               ScanProbeDelay;
    ULONG                               ScanChannelCount;
    PULONG                              ScanChannelList;
    ULONG                               ScanChannelTime;
    ULONG                               ScanCurrentChannelIndex;
    SCAN_STATE                          ScanCurrentState;
    ULONGLONG                           ScanChannelSwitchTime;
    UCHAR                               ScanCurrentChannel;

	// 802.11 Power management
	DOT11_POWER_MGMT_MODE			    PowerMgmtMode;
	NDIS_MINIPORT_TIMER					Timer_Awake;			// timer for survey scan
	PTX_DESC							pPowerMgmtChangePktDesc;
	BOOLEAN								bPowerMgmtChangePktSent;
	BOOLEAN								bATIMPacketReceived;
    BOOLEAN                             bUnicastDataAvailable;
    ULONGLONG                           WakeupTime;
    NDIS_SPIN_LOCK                      PowerMgmtLock;
    BOOLEAN                             bSleepOnInterruptComplete;

	NDIS_DEVICE_POWER_STATE             NextDevicePowerState;

	UCHAR								SSID[33];				// 1 byte for 0
	UCHAR								BssId[6];
    UCHAR                               APJoinBSSID[6];         //  For AP join mode.

	USHORT								CapInfo;
	USHORT								AtimWindow;

	TIM									Tim;
	
	USHORT								DtimCount;
	USHORT								DtimPeriod;

	CHAR								IEMap[256];				// Used to indicate if an IE is available(This array size should not be changed)
	IE									IEs[MAX_IE_NUMBER];		// Store all information elements
	USHORT								WPAIECount;

	UCHAR								NextBeaconIndex;

	JOIN_REQUEST_INFO					JoinRequestInfo;
	NDIS_MINIPORT_TIMER					Timer_JoinTimeout;		// timer for Join timeout
	ULONG                               JoinWaitBeaconToSynchronize;

	ULONG								CCAModeSupported;
	ULONG								CurrentCCAMode;

	BOOLEAN								bScanCompleteIndicated;
	BOOLEAN                             bAdvertiseBSS;

	ULONG								uMPDUMaxLength;

	LONG								EDThreshold;
    BOOLEAN                             ShortSlotTimeOptionEnabled;

	LARGE_INTEGER						DelaySleepTimeStamp;
	ULONG								DelaySleepValue;

	DOT11_OFFLOAD_CAPABILITY			OffloadCapability;
	DOT11_CURRENT_OFFLOAD_CAPABILITY	CurrentOffloadCapability;

	DOT11_OPERATION_MODE_CAPABILITY	OperationModeCapability;
	DOT11_CURRENT_OPERATION_MODE		CurrentOperationMode;
	DOT11_BSS_TYPE						CurrentBSSType;

	DOT11_OPTIONAL_CAPABILITY			OptionalCapability;
	DOT11_CURRENT_OPTIONAL_CAPABILITY	CurrentOptionalCapability;

	USHORT								CurrentBeaconRate;		// Used for Beacon and Probe request
    USHORT                              CurrentTXDataRate;
    USHORT                              CurrentTXMgmtRate;

    DOT11_DIVERSITY_SUPPORT			    DiversitySupport;

	DOT11_SUPPORTED_POWER_LEVELS		SupportedPowerLevels;
	ULONG								CurrentTxPowerLevel; // 1..8

	PDOT11_REG_DOMAINS_SUPPORT_VALUE	pRegDomainsSupportValue;

	PDOT11_DIVERSITY_SELECTION_RX_LIST	pDiversitySelectionRxList;

    BOOLEAN                             SafeModeEnabled;
    
	// For 8185
	UCHAR								dot11CurrentWirelessMode;
	WIRELESS_MODE_SETTING				WirelessModeSetting[5];

	UCHAR								RegWirelessMode;
	UCHAR								RegPacketControlRL;
	UCHAR								RegPacketControlAGC;
	UCHAR								RegCCK_TxAGC;
	UCHAR								RegOFDM_TxAGC;
	UCHAR								RegPacketControlAntenna;
	UCHAR								RegCCK_TxAntenna;
	UCHAR								RegOFDM_TxAntenna;
	UCHAR								RegFeedbackControlAntenna;
	
    // auto rate fallback control
	BOOLEAN								bRegAutoRateFallback;
	UCHAR								RegAutoRateFallbackStep;

    // encryption related info 
    NICKEY                              KeyTable[KEY_TABLE_SIZE];   // 0-3 is default key, 4+ is key mapping key 
    UCHAR                               DefaultKeyID;
    UCHAR                               KeyMappingKeyCount;
    NIC_PER_STA_KEY                     PerStaKey[PER_STA_KEY_TABLE_SIZE];
    UCHAR                               PerStaKeyCount;
    DOT11_AUTH_ALGORITHM                HwAuthAlgorithm;
    DOT11_CIPHER_ALGORITHM              HwUnicastCipher;
    DOT11_CIPHER_ALGORITHM              HwMulticastCipher;
    NPAGED_LOOKASIDE_LIST               EncryptionInfoList;
    NPAGED_LOOKASIDE_LIST               MICDataList;

    // PHY specific MIB
    PDOT11_SUPPORTED_PHY_TYPES          pSupportedPhyTypes;
    ULONG                               OperatingPhyId;         // ID of currently operating PHY
    ULONG                               SelectedPhyId;          // index of PHY that any PHY specific OID is applied to

    NDIS_SPIN_LOCK                      PhyMIBConfigLock;       // currently used when configuring ActiveRateSet in PhyMIB
    NICPHYMIB                           PhyMIB[MAX_NUM_PHY_TYPES];
    PNICPHYMIB                          OperatingPhyMIB;        // for currently operating PHY (by OperatingPhyId)
    PNICPHYMIB                          SelectedPhyMIB;         // for currently selected PHY (by SelectedPhyId)

    //HW specific management function
    NDIS_MINIPORT_TIMER                 Timer_HwPeriod;          //for some HW dynamic funtionalities
    LONG                                HwPeriodTimerSync;

    /* the following flag are used for Realtek private functions only*/
    //some Realtek used variable
    ULONG                               SignalStrengthForImprovingIG; 

    // enable sending CTS to self for g-mode protection
    BOOLEAN                             bEnableSendCTSToSelf;

    // current device's connection state
    BOOLEAN                             bDeviceConnected;
    
    /** Total data send retry count for Tx rate negotiation*/
    LONG                                TotalRetryCount;
    ULONG                               PacketsSentForTxRateCheck;
    UCHAR                               MinPacketsSentForTxRateUpdate;
    USHORT                              PrevTxDataRate;
    USHORT                              TxRateIncreaseWaitCount;
    USHORT                              TxRateIncreaseWaitRequired;
	
    /* for fair Ad hoc beacon */
    BOOLEAN					bAdhocCoordinator;
	
} NICMANAGEMENTINFO, *PNICMANAGEMENTINFO;


typedef struct _NIC
{
	/** The handle to be passed to NDIS when calling functions */
	NDIS_HANDLE				MiniportAdapterHandle;
	
	/** Pointer to the associated Adapter instance */
	PADAPTER				pAdapter;

    /** Pointer to the associated Station instance */
	PSTATION                pStation;
	
	//3 Card Information
	NICCARDINFO			CardInfo;
	//3 Rx releated Variable
	NICRXINFO				RxInfo;
	//3 Tx releated Variable
	NICTXINFO				TxInfo;
	//3 EEPROM Releated Variable
	NICEEPROMINFO			EEPROMInfo;
	//3 RF releated Variable
	NICRFINFO				RfInfo;
	//3 Statistics releatedVariable
	NICSTATISTICSINFO		StatisticsInfo;
	//3 Variable read from Registry and will change locally
	NICDUPLICATEINFO		DupCurrentInfo;
	NICDUPLICATEINFO		DupRegistryInfo;
	//3 Managementl releated Variable(switch channel,...)
	NICMANAGEMENTINFO		ManagementInfo;
	
} NIC, *PNIC;

//
// Macros to make code more readable
//
#define HW_IS_IN_AP_MODE(_Nic)      \
    (FALSE)
    
#define HW_IS_IN_STA_INFRA_MODE(_Nic)     \
    (_Nic->ManagementInfo.CurrentOperationMode.uCurrentOpMode == DOT11_OPERATION_MODE_EXTENSIBLE_STATION && _Nic->ManagementInfo.CurrentBSSType == dot11_BSS_type_infrastructure)

#define HW_IS_IN_STA_ADHOC_MODE(_Nic)     \
    (_Nic->ManagementInfo.CurrentOperationMode.uCurrentOpMode == DOT11_OPERATION_MODE_EXTENSIBLE_STATION && _Nic->ManagementInfo.CurrentBSSType == dot11_BSS_type_independent)

#define HW_IS_IN_NETWORK_MONITOR_MODE(_Nic)     \
    (_Nic->ManagementInfo.CurrentOperationMode.uCurrentOpMode == DOT11_OPERATION_MODE_NETWORK_MONITOR)
    
#define HW_WAIT_FOR_BSS_JOIN(_Nic)     (_Nic->ManagementInfo.JoinWaitBeaconToSynchronize = 1)
#define HW_STOP_WAITING_FOR_JOIN(_Nic)      \
    (InterlockedCompareExchange((PLONG)&_Nic->ManagementInfo.JoinWaitBeaconToSynchronize, 0, 1) == 1)

#define HW_MDL_BYTECOUNT(_Mdl) ((_Mdl)->ByteCount)

//
// Some functions that are being called from multiple files
//

VOID
HwResetParameters(
    IN  PNIC                pNic,
    IN  DOT11_RESET_TYPE    ResetType
    );

VOID
HwCheckForATIMPacketSendCompletion(
    IN      PNIC    pNic
    );

void
HwSetChannel(
    PNIC        pNic,
    UCHAR       ucChannel,
    HW_CHANNEL_SWITCH_COMPLETE_HANDLER      ChannelSwitchCompleteHandler
    );

void
HwSetChannelSync(
    IN  PNIC pNic,
    IN  UCHAR ucChannel
    );

NDIS_STATUS
HwProcessReceiveAPMode(
    IN PNIC		        pNic,
    IN PNIC_RX_FRAGMENT pNicFragment
    );

NDIS_STATUS
HwProcessReceiveSTAMode(
    IN PNIC		        pNic,
    IN PNIC_RX_FRAGMENT pNicFragment
    );

NDIS_STATUS
HwProcessReceiveAdhocMode(
    IN PNIC		        pNic,
    IN PNIC_RX_FRAGMENT pNicFragment
    );


NDIS_STATUS
HwProcessReceiveAnyModeForIndicateAck(
    IN PNIC		        pNic,
    IN PNIC_RX_FRAGMENT pNicFragment
    );

NDIS_STATUS
HwProcessReceiveSTAModeWaitForJoin(
	IN PNIC		        pNic,
	IN PNIC_RX_FRAGMENT pNicFragment
	);

NDIS_STATUS
HwProcessReceiveAdHocSTAModeWaitForJoin(
	IN PNIC		        pNic,
	IN PNIC_RX_FRAGMENT pNicFragment
	);

VOID
HwAdjustReceiveProcessingFunction(
    IN  PNIC        pNic
    );

void 
HwGetVersion(
	IN  PNIC        pNic
	);

void 
HwGetBusType(
	IN  PNIC        pNic
	);

void
HwSetBSSIDAndBcnIntv(
    IN  PNIC pNic
    );

NDIS_STATUS
HwCalculateMIC(
    IN  PNET_BUFFER     NetBuffer,
    IN  UCHAR           Priority,
    IN  PUCHAR          MICKey,
    OUT PUCHAR          MICData
    );

PNICKEY
HwFindPerStaKey(
    IN PNIC                 pNic,
    IN DOT11_MAC_ADDRESS    MacAddr,
    IN UCHAR                keyId
    );

#endif  // _NATIVE_WIFI_HW_MAIN_H


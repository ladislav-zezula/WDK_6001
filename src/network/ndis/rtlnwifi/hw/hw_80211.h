/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    hw_80211.h

Abstract:
    Commoon hardware structures
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created
    01-15-2006    Renamed hw_802_11.h to hw_80211.h

Notes:

--*/
#ifndef HW_802_11_HEADER
#define HW_802_11_HEADER

#define sAckCtsLng		112		// bits in ACK and CTS frames
#define sCrcLng			4		// octets for crc32 (FCS, ICV)
#define aSifsTime		10
#define sMacHdrLng		24		// octets in data header, no WEP

#define PacketGetType(_packet)	((_packet).Octet[0] & 0xFC)

#define FillOctetString(_os,_octet,_len)		\
	(_os).Octet=(PUCHAR)(_octet);					\
	(_os).Length=(_len)

typedef struct _OctetString
{
	PUCHAR	Octet;
	USHORT	Length;
}OctetString,*pOctetString;

typedef	enum _ElementID{
	EID_SsId = 0, 		/* service set identifier (0:32) */
	EID_SupRates = 1,	/* supported rates (1:8) */
	EID_FHParms = 2, 	/* FH parameter set (5) */
	EID_DSParms = 3, 	/* DS parameter set (1) */
	EID_CFParms = 4, 	/* CF parameter set (6) */
	EID_Tim = 5,		/* Traffic Information Map (4:254) */
	EID_IbssParms = 6,	/* IBSS parameter set (2) */
	EID_Ctext = 16,		/* challenge text*/
	EID_ExtSupRates = 50,
}ElementID;

typedef enum _Capability{
	cESS		= 0x01,
	cIBSS		= 0x02,
	cPollable	= 0x04,
	cPollReq	= 0x01,
	cPrivacy	= 0x10,
	cShortPreamble=0x20,
	cPBCC		= 0x40,
}Capability;

typedef	enum	_TypeSubtype{
	Type_Asoc_Req		= 0x00,
	Type_Asoc_Rsp		= 0x10,
	Type_Reasoc_Req	= 0x20,
	Type_Reasoc_Rsp	= 0x30,
	Type_Probe_Req		= 0x40,
	Type_Probe_Rsp		= 0x50,
	Type_Beacon		= 0x80,
	Type_Atim			= 0x90,
	Type_Disasoc		= 0xa0,
	Type_Auth			= 0xb0,
	Type_Deauth		= 0xc0,
	Type_PS_poll		= 0xa4,//= MkString(S8(0,0,1,0,0,1,0,1));
	Type_RTS			= 0xb4,//= MkString(S8(0,0,1,0,1,1,0,1));
	Type_CTS			= 0xc4,//= MkString(S8(0,0,1,0,0,0,1,1));
	Type_Ack			= 0xd4,//= MkString(S8(0,0,1,0,1,0,1,1));
	Type_Cfend			= 0xe4,//= MkString(S8(0,0,1,0,0,1,1,1));
	Type_Cfend_Ack		= 0xf4,//= MkString(S8(0,0,1,0,1,1,1,1));
	Type_Data			= 0x08,//= MkString(S8(0,0,0,1,0,0,0,0));
	Type_Data_Ack		= 0x18,//= MkString(S8(0,0,0,1,1,0,0,0));
	Type_Data_Poll		= 0x28,//= MkString(S8(0,0,0,1,0,1,0,0));
	Type_Data_Poll_Ack = 0x38,//= MkString(S8(0,0,0,1,1,1,0,0));
	Type_Null_Frame	= 0x48,//= MkString(S8(0,0,0,1,0,0,1,0));
	Type_Cfack			= 0x58,//= MkString(S8(0,0,0,1,1,0,1,0));
	Type_Cfpoll			= 0x68,//= MkString(S8(0,0,0,1,0,1,1,0));
	Type_Cfpoll_Ack		= 0x78,//= MkString(S8(0,0,0,1,1,1,1,0));

}TypeSubtype;

typedef	union _FrameControl
{
	USHORT	shortData;
	UCHAR	charData[2];
	struct
	{
		USHORT	ProtocolVersion:2;
		USHORT	Type:2;
		USHORT	Subtype:4;
		USHORT	ToDS:1;
		USHORT	FromDS:1;
		USHORT	MoreFrag:1;
		USHORT	Retry:1;
		USHORT	PwrMgt:1;
		USHORT	MoreData:1;
		USHORT	WEP:1;
		USHORT	Order:1;
	}field;
}FrameControl;

typedef struct _GeneralPacketPartial{
	FrameControl		frameCtl;
	USHORT			Duration;
	UCHAR			Addr1[6];
	UCHAR			Addr2[6];
	UCHAR			Addr3[6];
	USHORT			Seq;
}GeneralPacketPartial, *pGeneralPacketPartial;

typedef struct _BeaconProbeRspPartial{
	GeneralPacketPartial	GenPacketPartial;
	ULONGLONG			TimeStamp;
	USHORT				BeaconInterval;
	USHORT				CapabilityInfo;
}BeaconProbeRspPartial, *pBeaconProbeRspPartial;

typedef struct _AuthenticatePacketPartial{
	GeneralPacketPartial	GenPacketPartial;
	USHORT				AuthAlgNum;
	USHORT				AuthSeqNum;
	USHORT				StatusCode;
	UCHAR				ChallengeText[1];
}AuthenticatePacketPartial, *pAuthenticatePacketPartial;

typedef struct _AssociateReqPartial{
	GeneralPacketPartial	GenPacketPartial;
	USHORT				CapabilityInfo;
	USHORT				ListenInterval;
}AssociateReqPartial, *pAssociateReqPartial;

typedef struct _AssociateRspPartial{
	GeneralPacketPartial	GenPacketPartial;
	USHORT				CapabilityInfo;
	USHORT				StatusCode;
	USHORT				AID;
}AssociateRspPartial, *pAssociateRspPartial;

typedef struct _TIM{
	UCHAR	DtimCount;
	UCHAR	DtimPeriod;
	UCHAR	BitmapCtrl;
	UCHAR	PartialVirtualBitmap[251];
}TIM,*pTIM;

// ===============================================
//3 Function declaration
// ===============================================
BOOLEAN	
EqualOS(
	OctetString	os1,
	OctetString	os2);

OctetString 
PacketGetElement(
	OctetString	packet,
	ElementID ID);

void
PacketMakeElement(
	OctetString		*packet,
	ElementID		ID,
	OctetString		info);

void
PacketAppendData(
	OctetString		*packet,
	OctetString		data);

BOOLEAN
TimGetBcMcBit(
	OctetString	Tim);

BOOLEAN	
TimGetAIDBit( 
	OctetString		Tim, 
	unsigned short	AID);

USHORT 
ComputeTxTime(
	IN USHORT	FrameLength,			//3in byte
	IN ULONG	DataRate,				//3in 0.5 Mbits
	IN BOOLEAN	bManagementFrame,
	IN BOOLEAN	bShortPreamble);

void
ComputePLCPLength(
	IN USHORT		FrameLength,		//3in byte
	IN ULONG		DataRate,			//3in 0.5 Mbits
	OUT USHORT		*FrameTime,
	OUT USHORT		*LengExt 
	);

#endif


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
#include "hw_pcomp.h"

#include <stdio.h>
#include "Hw_main.h"
#include "hw_eprom.h"
#include "Hw_Nic.h"
#include "Hw_Func.h"
#include "hw_80211.h"

#include "mp_util.h"
#include "mp_send.h"
#if DOT11_TRACE_ENABLED
#include "Hw_Nic.tmh"
#endif


// Combined a/b/g channels. 11a channels 
CHANNEL_LIST ChannelListAB[] = {
    {{1,2,3,4,5,6,7,8,9,10,11,36,40,44,48,52,56,60,64}, 19},		//default
    {{1,2,3,4,5,6,7,8,9,10,11,36,40,44,48,52,56,60,64},19},		//FCC
    {{1,2,3,4,5,6,7,8,9,10,11,36,40,44,48,52,56,60,64},19}, 		//DOC, FCC
    {{1,2,3,4,5,6,7,8,9,10,11,12,13,36,40,44,48,52,56,60,64},21},	//ETSI										//ETSI
    {{1,2,3,4,5,6,7,8,9,10,11,12,13,36,40,44,48,52,56,60,64},21},	//Spain, ETSI
    {{1,2,3,4,5,6,7,8,9,10,11,12,13,36,40,44,48,52,56,60,64},21},	//France, ETSI
    {{14,36,40,44,48,52,56,60,64},9},							   //mkk
    {{1,2,3,4,5,6,7,8,9,10,11,12,13,14, 36,40,44,48,52,56,60,64},22}, //mkk1 , also TELE
    {{1,2,3,4,5,6,7,8,9,10,11,12,13,36,40,44,48,52,56,60,64},21}	//Israel
};

// b/g channels only.
CHANNEL_LIST ChannelListB[] = {
    {{1,2,3,4,5,6,7,8,9,10,11}, 11},				//default
    {{1,2,3,4,5,6,7,8,9,10,11}, 11},				//FCC
    {{1,2,3,4,5,6,7,8,9,10,11}, 11},				//DOC, FCC
    {{1,2,3,4,5,6,7,8,9,10,11,12,13}, 13},			//ETSI
    {{1,2,3,4,5,6,7,8,9,10,11,12,13}, 13},			//SPAIN
    {{1,2,3,4,5,6,7,8,9,10,11,12,13}, 13},			//France
    {{14},1},									//MKK
    {{1,2,3,4,5,6,7,8,9,10,11,12,13,14}, 14},		//MKK1, tele
    {{1,2,3,4,5,6,7,8,9,10,11,12,13},13}			//Israel
};

#define HW_TRANSITION_SCAN_STATE(_Scan_State)    \
    (_Scan_State = ((_Scan_State + 1) % ScanStateMaxState))


void 
HwInitializeVariable(
    IN  PNIC pNic)
{
    USHORT    Index;

    pNic->ManagementInfo.bScanCompleteIndicated = FALSE;
    pNic->ManagementInfo.bScanInProgress = FALSE;

    pNic->ManagementInfo.uMPDUMaxLength = MAX_MPDU_LENGTH;

    pNic->ManagementInfo.EDThreshold = -65;
    pNic->ManagementInfo.ShortSlotTimeOptionEnabled = FALSE;

    pNic->DupCurrentInfo.MediaOccupancyLimit = 100;
    pNic->DupCurrentInfo.CFPPeriod = 255;
    pNic->DupCurrentInfo.CFPMaxDuration = 100;
    pNic->DupCurrentInfo.BeaconInterval = 100;

    pNic->DupCurrentInfo.RTS_Threshold = 2347;
    pNic->DupCurrentInfo.Frag_Threshold = 2346;
    pNic->DupCurrentInfo.ShortRetryLimit = 7;
    pNic->DupCurrentInfo.LongRetryLimit = 7;
    pNic->DupCurrentInfo.MaxTxLifeTime = 512;
    pNic->DupCurrentInfo.MaxRxLifeTime = 512;
    pNic->DupCurrentInfo.DefaultBeaconRate = 2;        // Set default beacon rate to 2 Mbps

    pNic->CardInfo.ResetInProgress = FALSE;
    pNic->ManagementInfo.SwChnlInProgress = FALSE;

    pNic->CardInfo.IntrMask = IMR_TimeOut | IMR_TBDOK | IMR_TBDER | IMR_THPDER | IMR_THPDOK |
                              IMR_TNPDER | IMR_TNPDOK | /* IMR_RXFOVW | IMR_RDU | */ 
                              IMR_TLPDER | IMR_TLPDOK | IMR_RER | IMR_ROK;

    pNic->RfInfo.RadioOff = FALSE;
    pNic->RfInfo.RFPowerState = RF_ON;

    pNic->ManagementInfo.PowerMgmtMode.dot11PowerMode = dot11_power_mode_active;
    pNic->ManagementInfo.PowerMgmtMode.usAID = 0;
    NdisAllocateSpinLock(&pNic->ManagementInfo.PowerMgmtLock);

    pNic->RfInfo.CurrentRxAntenna = 1;
    pNic->RfInfo.CurrentTxAntenna = 1;
    
    pNic->CardInfo.MWIEnable = FALSE;

    RtlCopyMemory((PCHAR)pNic->ManagementInfo.SSID, "Realtek AP", sizeof("Realtek AP"));

    pNic->ManagementInfo.CapInfo = cESS /*|cShortPreamble*/;
    pNic->ManagementInfo.AtimWindow = 0;    /* set only when power management is enabled */

    pNic->ManagementInfo.DtimPeriod = 5;
    pNic->ManagementInfo.DtimCount = pNic->ManagementInfo.DtimPeriod - 1;

    pNic->ManagementInfo.NextBeaconIndex = 0;

    pNic->ManagementInfo.Tim.BitmapCtrl = pNic->ManagementInfo.Tim.PartialVirtualBitmap[0] = 0;
    
    // These variable should initialize from registry
    pNic->DupCurrentInfo.EarlyRxThreshold = 7;

    pNic->RxInfo.RxTotalDescNum = 64;
    for (Index = 0; Index < 2 * DUPLICATE_DETECTION_CACHE_LENGTH; Index++)
    {
        NdisZeroMemory(&pNic->RxInfo.DupePacketCache[Index], sizeof(DUPE_CACHE_ENTRY));
    }
    pNic->RxInfo.NextDupeCacheIndexData = 0;
    pNic->RxInfo.NextDupeCacheIndexOther = DUPLICATE_DETECTION_CACHE_LENGTH;

    //
    // Set to receive management packets initially
    //
    pNic->RxInfo.ReceiveFilter = NDIS_PACKET_TYPE_802_11_DIRECTED_MGMT | 
                                 NDIS_PACKET_TYPE_802_11_MULTICAST_MGMT |
                                 NDIS_PACKET_TYPE_802_11_BROADCAST_MGMT;

    pNic->RxInfo.ReceiveConfig = pNic->RfInfo.CSMethod | RCR_ENMARP | 
                                 RCR_AMF | RCR_APM |                 //accept management
                                 //RCR_ADF |                         //accept data
                                 RCR_AB | RCR_AM |                   //accept BC/MC
                                 //RCR_APM |                         //accept UC (to non-local MAC address)
                                 RCR_AICV | /* RCR_ACRC32 | */       //accept ICV/CRC error packet
                                 ((USHORT)0x07 << RCR_FIFO_OFFSET) |
                                 (pNic->DupCurrentInfo.EarlyRxThreshold << RCR_FIFO_OFFSET) |
                                 (7 << RCR_MXDMA_OFFSET);

    if (pNic->DupCurrentInfo.EarlyRxThreshold == 7)                 // Turn OnlyErlPkt when early Rx is turn off
        pNic->RxInfo.ReceiveConfig |= RCR_OnlyErlPkt;
    
    pNic->TxInfo.TxTotalDescNum[LOW_QUEUE] = 64;
    pNic->TxInfo.TxTotalDescNum[NORMAL_QUEUE] = 24;
    pNic->TxInfo.TxTotalDescNum[HIGH_QUEUE] = 24;
    pNic->TxInfo.TxTotalDescNum[BEACON_QUEUE] = 2;

    pNic->TxInfo.TransmitConfig = (7l << TCR_MXDMA_OFFSET) |                        // TCR_MXDMA_OFFSET
                                   (pNic->DupCurrentInfo.ShortRetryLimit << 8) |    // Short retry limit
                                   (pNic->DupCurrentInfo.LongRetryLimit) |          // Long retry limit
                                   (0 ? 0x00060000 : 0) |                           // Continuous Tx
                                   (0 ? TCR_SAT : 0);                               // Rate dependent ACK

    pNic->TxInfo.TxPowerLevelPercent = 100;		//by default, Txpower emit 100% of permitted power

    pNic->ManagementInfo.CCAModeSupported = DOT11_CCA_MODE_CS_ONLY;
    pNic->ManagementInfo.CurrentCCAMode = DOT11_CCA_MODE_CS_ONLY;

    pNic->ManagementInfo.OffloadCapability.uReserved = 0;
    pNic->ManagementInfo.OffloadCapability.uFlags = 0;
    pNic->ManagementInfo.OffloadCapability.uSupportedWEPAlgorithms = 0;
    pNic->ManagementInfo.OffloadCapability.uNumOfReplayWindows = 0;
    pNic->ManagementInfo.OffloadCapability.uMaxWEPKeyMappingLength = 0;
    pNic->ManagementInfo.OffloadCapability.uSupportedAuthAlgorithms = 0;
    pNic->ManagementInfo.OffloadCapability.uMaxAuthKeyMappingLength = 0;

    pNic->ManagementInfo.CurrentOffloadCapability.uReserved = 0;
    pNic->ManagementInfo.CurrentOffloadCapability.uFlags = 0;

    pNic->ManagementInfo.OperationModeCapability.uReserved = 0;
    pNic->ManagementInfo.OperationModeCapability.uMajorVersion = MP_OPERATION_MODE_CAPABILITY_MAJOR_VERSION;
    pNic->ManagementInfo.OperationModeCapability.uMinorVersion = MP_OPERATION_MODE_CAPABILITY_MINOR_VERSION;
    // We can buffer as many packets as OS sends.
    pNic->ManagementInfo.OperationModeCapability.uNumOfTXBuffers = 0;
    pNic->ManagementInfo.OperationModeCapability.uNumOfRXBuffers = pNic->RxInfo.RxTotalDescNum;

    pNic->ManagementInfo.CurrentOperationMode.uReserved = 0;
    
    pNic->ManagementInfo.OperationModeCapability.uOpModeCapability = DOT11_OPERATION_MODE_EXTENSIBLE_STATION 
        | DOT11_OPERATION_MODE_NETWORK_MONITOR;
    pNic->ManagementInfo.CurrentOperationMode.uCurrentOpMode = DOT11_OPERATION_MODE_EXTENSIBLE_STATION;
    pNic->RxInfo.ReceiveProcessingFunction = HwProcessReceiveSTAMode;

    pNic->ManagementInfo.OptionalCapability.uReserved = 0;
    pNic->ManagementInfo.OptionalCapability.bDot11PCF = FALSE;
    pNic->ManagementInfo.OptionalCapability.bDot11PCFMPDUTransferToPC = FALSE;
    pNic->ManagementInfo.OptionalCapability.bStrictlyOrderedServiceClass = FALSE;

    pNic->ManagementInfo.CurrentOptionalCapability.uReserved = 0;
    pNic->ManagementInfo.CurrentOptionalCapability.bDot11CFPollable = FALSE;
    pNic->ManagementInfo.CurrentOptionalCapability.bDot11PCF = FALSE;
    pNic->ManagementInfo.CurrentOptionalCapability.bDot11PCFMPDUTransferToPC = FALSE;
    pNic->ManagementInfo.CurrentOptionalCapability.bStrictlyOrderedServiceClass = FALSE;

    pNic->ManagementInfo.pSupportedPhyTypes->uNumOfEntries = 1;
    pNic->ManagementInfo.pSupportedPhyTypes->uTotalNumOfEntries = MAX_NUM_PHY_TYPES;

    pNic->ManagementInfo.PhyMIB[0].PhyID =0 ;
    
    pNic->ManagementInfo.pSupportedPhyTypes->dot11PHYType[0] = dot11_phy_type_hrdsss;
    pNic->ManagementInfo.PhyMIB[0].PhyType = dot11_phy_type_hrdsss;

    pNic->ManagementInfo.PhyMIB[0].OperationalRateSet.ucRateSet[0] = 2;
    pNic->ManagementInfo.PhyMIB[0].OperationalRateSet.ucRateSet[1] = 4;
    pNic->ManagementInfo.PhyMIB[0].OperationalRateSet.ucRateSet[2] = 11;
    pNic->ManagementInfo.PhyMIB[0].OperationalRateSet.ucRateSet[3] = 22;
    pNic->ManagementInfo.PhyMIB[0].OperationalRateSet.uRateSetLength = 4;

    NdisAllocateSpinLock(&pNic->ManagementInfo.PhyMIBConfigLock);
    pNic->ManagementInfo.PhyMIB[0].ActiveRateSet.uRateSetLength = 0;

    pNic->ManagementInfo.PhyMIB[0].BasicRateSet.ucRateSet[0] = 2;
    pNic->ManagementInfo.PhyMIB[0].BasicRateSet.ucRateSet[1] = 4;
    pNic->ManagementInfo.PhyMIB[0].BasicRateSet.ucRateSet[2] = 11;
    pNic->ManagementInfo.PhyMIB[0].BasicRateSet.ucRateSet[3] = 22;
    pNic->ManagementInfo.PhyMIB[0].BasicRateSet.uRateSetLength = 4;

    pNic->ManagementInfo.PhyMIB[0].SupportedDataRatesValue.ucSupportedTxDataRatesValue[0] = 2;
    pNic->ManagementInfo.PhyMIB[0].SupportedDataRatesValue.ucSupportedTxDataRatesValue[1] = 4;
    pNic->ManagementInfo.PhyMIB[0].SupportedDataRatesValue.ucSupportedTxDataRatesValue[2] = 11;
    pNic->ManagementInfo.PhyMIB[0].SupportedDataRatesValue.ucSupportedTxDataRatesValue[3] = 22;

    pNic->ManagementInfo.PhyMIB[0].SupportedDataRatesValue.ucSupportedRxDataRatesValue[0] = 2;
    pNic->ManagementInfo.PhyMIB[0].SupportedDataRatesValue.ucSupportedRxDataRatesValue[1] = 4;
    pNic->ManagementInfo.PhyMIB[0].SupportedDataRatesValue.ucSupportedRxDataRatesValue[2] = 11;
    pNic->ManagementInfo.PhyMIB[0].SupportedDataRatesValue.ucSupportedRxDataRatesValue[3] = 22;
    
    for (Index = 4; Index < MAX_NUM_SUPPORTED_RATES_V2; Index++) 
    {
        pNic->ManagementInfo.PhyMIB[0].SupportedDataRatesValue.ucSupportedTxDataRatesValue[Index] = 0;
        pNic->ManagementInfo.PhyMIB[0].SupportedDataRatesValue.ucSupportedRxDataRatesValue[Index] = 0;
    }
  
    pNic->ManagementInfo.PhyMIB[0].Channel = HW11_DEFAULT_CHANNEL;
   
    pNic->ManagementInfo.CurrentBeaconRate = 4;         // Set default beacon rate to 2 Mbps
    pNic->ManagementInfo.CurrentTXMgmtRate = 4;         // Set default mgmt rate to 2 Mbps
    pNic->ManagementInfo.CurrentTXDataRate = 22;        // Set default data rate to 11 Mbps
    
    pNic->ManagementInfo.OperatingPhyId = 0;
    pNic->ManagementInfo.SelectedPhyId = 0;
    pNic->ManagementInfo.OperatingPhyMIB = pNic->ManagementInfo.PhyMIB;
    pNic->ManagementInfo.SelectedPhyMIB = pNic->ManagementInfo.PhyMIB;

    pNic->ManagementInfo.DiversitySupport = dot11_diversity_support_dynamic;

    pNic->ManagementInfo.SupportedPowerLevels.uNumOfSupportedPowerLevels = 4;
    pNic->ManagementInfo.SupportedPowerLevels.uTxPowerLevelValues[0] = 10;
    pNic->ManagementInfo.SupportedPowerLevels.uTxPowerLevelValues[1] = 20;
    pNic->ManagementInfo.SupportedPowerLevels.uTxPowerLevelValues[2] = 30;
    pNic->ManagementInfo.SupportedPowerLevels.uTxPowerLevelValues[3] = 50;
    pNic->ManagementInfo.CurrentTxPowerLevel = 1;    // 1 based

    pNic->ManagementInfo.pRegDomainsSupportValue->uNumOfEntries = 7;
    pNic->ManagementInfo.pRegDomainsSupportValue->uTotalNumOfEntries = MAX_NUM_DOT11_REG_DOMAINS_VALUE;
    for (Index=0; Index < pNic->ManagementInfo.pRegDomainsSupportValue->uNumOfEntries; Index++)
        pNic->ManagementInfo.pRegDomainsSupportValue->dot11RegDomainValue[Index].uRegDomainsSupportIndex = Index;

    pNic->ManagementInfo.pRegDomainsSupportValue->dot11RegDomainValue[0].uRegDomainsSupportValue = DOT11_REG_DOMAIN_OTHER;
    pNic->ManagementInfo.pRegDomainsSupportValue->dot11RegDomainValue[1].uRegDomainsSupportValue = DOT11_REG_DOMAIN_FCC;
    pNic->ManagementInfo.pRegDomainsSupportValue->dot11RegDomainValue[2].uRegDomainsSupportValue = DOT11_REG_DOMAIN_DOC;
    pNic->ManagementInfo.pRegDomainsSupportValue->dot11RegDomainValue[3].uRegDomainsSupportValue = DOT11_REG_DOMAIN_ETSI;
    pNic->ManagementInfo.pRegDomainsSupportValue->dot11RegDomainValue[4].uRegDomainsSupportValue = DOT11_REG_DOMAIN_SPAIN;
    pNic->ManagementInfo.pRegDomainsSupportValue->dot11RegDomainValue[5].uRegDomainsSupportValue = DOT11_REG_DOMAIN_FRANCE;
    pNic->ManagementInfo.pRegDomainsSupportValue->dot11RegDomainValue[6].uRegDomainsSupportValue = DOT11_REG_DOMAIN_MKK;
    // These two are supported, but the OS doesnt recognize these and hence we wont report these to the OS (NumOfEntries = 7)
    pNic->ManagementInfo.pRegDomainsSupportValue->dot11RegDomainValue[7].uRegDomainsSupportValue = HW_REG_DOMAIN_MKK1;
    pNic->ManagementInfo.pRegDomainsSupportValue->dot11RegDomainValue[8].uRegDomainsSupportValue = HW_REG_DOMAIN_ISRAEL;

    pNic->ManagementInfo.pDiversitySelectionRxList->uNumOfEntries = 2; 
    pNic->ManagementInfo.pDiversitySelectionRxList->uTotalNumOfEntries = MAX_NUM_DIVERSITY_SELECTION_RX_LIST;
    pNic->ManagementInfo.pDiversitySelectionRxList->dot11DiversitySelectionRx[0].uAntennaListIndex = 1;
    pNic->ManagementInfo.pDiversitySelectionRxList->dot11DiversitySelectionRx[0].bDiversitySelectionRX = TRUE;
    pNic->ManagementInfo.pDiversitySelectionRxList->dot11DiversitySelectionRx[1].uAntennaListIndex = 2;
    pNic->ManagementInfo.pDiversitySelectionRxList->dot11DiversitySelectionRx[1].bDiversitySelectionRX = TRUE;

    pNic->ManagementInfo.DelaySleepValue = 0;

    //by default. the wirelessmode should not exist
    pNic->ManagementInfo.dot11CurrentWirelessMode = 0;

    if (pNic->CardInfo.HardwareID == HW_ID_8185) 
    {
        //
        // Updates hardware specific variables and some of the Native Wi-Fi capability
        // to match the hardware capabilities
        //
        Init8185(pNic);
    }
    
    // initialization for g-mode protection
    pNic->ManagementInfo.bEnableSendCTSToSelf = FALSE;

    pNic->ManagementInfo.bDeviceConnected = FALSE;
    
    // initialization for rate negotiation
    pNic->ManagementInfo.TotalRetryCount = 0;
    pNic->ManagementInfo.PacketsSentForTxRateCheck = 0;
    pNic->ManagementInfo.PrevTxDataRate = 0;
    pNic->ManagementInfo.TxRateIncreaseWaitCount = 0;
    pNic->ManagementInfo.TxRateIncreaseWaitRequired = 1;
    
    Hw11ResetMacMIBs(pNic);
    Hw11ResetPhyMIBs(pNic);
    HwResetParameters(pNic, 0);
}
   
VOID
Hw11ResetMacMIBs(
    IN   PNIC    pNic
    )
{
    //
    // If a variable must be reset during "MAC Reset", 
    // then it should be put here
    //

    pNic->RxInfo.MCAddressCount = 0;
    ETH_COPY_NETWORK_ADDRESS(pNic->CardInfo.StationID, pNic->CardInfo.PermanentAddress);
    ETH_COPY_NETWORK_ADDRESS(pNic->CardInfo.MacAddr, pNic->CardInfo.PermanentAddress);
}


VOID
Hw11ResetPhyMIBs(
    IN  PNIC    pNic
    )
{
    pNic->ManagementInfo.SelectedPhyId = 0;
    pNic->ManagementInfo.SelectedPhyMIB = pNic->ManagementInfo.PhyMIB;
}

VOID
Hw11ResetStatistics(
    IN  PNIC pNic
    )
{
    // MAC statistics
    NdisZeroMemory(&pNic->StatisticsInfo, FIELD_OFFSET(NICSTATISTICSINFO, PhyCounters));

    // PHY statistics
    NdisZeroMemory(
        pNic->StatisticsInfo.PhyCounters, 
        sizeof(DOT11_PHY_FRAME_STATISTICS) * MAX_NUM_PHY_TYPES
        );
}

VOID
HwResetParameters(
    IN  PNIC                pNic,
    IN  DOT11_RESET_TYPE    ResetType
    )
{
    //
    // Parameters that should be reset irrespective of MIB reset come here.
    //
    UNREFERENCED_PARAMETER(ResetType);

    pNic->ManagementInfo.CurrentBSSType = dot11_BSS_type_infrastructure;

    pNic->ManagementInfo.DefaultKeyID = 0;
    pNic->ManagementInfo.HwAuthAlgorithm = DOT11_AUTH_ALGO_80211_OPEN;
    pNic->ManagementInfo.HwUnicastCipher = DOT11_CIPHER_ALGO_NONE;
    pNic->ManagementInfo.HwMulticastCipher = DOT11_CIPHER_ALGO_NONE;
    HwDeleteAllKeys(pNic);

    pNic->ManagementInfo.pPowerMgmtChangePktDesc = NULL;
    pNic->ManagementInfo.bPowerMgmtChangePktSent = FALSE;
    pNic->ManagementInfo.bATIMPacketReceived = FALSE;
    pNic->ManagementInfo.bUnicastDataAvailable = FALSE;
    pNic->ManagementInfo.WakeupTime = 0;
    pNic->ManagementInfo.PowerMgmtMode.usAID = 0;
    pNic->ManagementInfo.bSleepOnInterruptComplete = FALSE;
    pNic->ManagementInfo.SafeModeEnabled = FALSE;

    pNic->RfInfo.AccessRefCount = 0;
    pNic->RfInfo.RadioStateChangeInProgress = FALSE;
    
    pNic->CardInfo.IntrMask = IMR_TimeOut | IMR_TBDOK | IMR_TBDER | IMR_THPDER | IMR_THPDOK |
                              IMR_TNPDER | IMR_TNPDOK | /* IMR_RXFOVW | IMR_RDU | */
                              IMR_TLPDER | IMR_TLPDOK | IMR_RER | IMR_ROK;

    HwClearAllIE(pNic);
}


NDIS_STATUS
HwSetNICAddress(
    IN  PNIC    pNic
    )
{
    ULONG TempUlong;

    WritePortUchar(pNic, CR9346, CR9346_EEM0 + CR9346_EEM1);

    TempUlong = pNic->CardInfo.MacAddr[3];
    TempUlong = TempUlong << 8;
    TempUlong = TempUlong + pNic->CardInfo.MacAddr[2];
    TempUlong = TempUlong << 8;
    TempUlong = TempUlong + pNic->CardInfo.MacAddr[1];
    TempUlong = TempUlong << 8;
    TempUlong = TempUlong + pNic->CardInfo.MacAddr[0];

    WritePortUlong(pNic, IDR0, TempUlong);

    TempUlong = pNic->CardInfo.MacAddr[5];
    TempUlong = TempUlong << 8;
    TempUlong = TempUlong + pNic->CardInfo.MacAddr[4];

    WritePortUlong(pNic, IDR4, TempUlong);

    WritePortUchar(pNic, CR9346, 0);

    return NDIS_STATUS_SUCCESS;
}

// Called at PASSIVE, DISPATCH & DIRQL
// Returns TRUE if at the end of the call, the new state of the RF is the requested
// state, returns FALSE otherwise
BOOLEAN
HwSetRFState(
    IN  PNIC    pNic,
    IN  UCHAR	NewRFState
    )
{
    BOOLEAN     bResult = TRUE;
    
    do
    {
        if (InterlockedIncrement(&pNic->RfInfo.AccessRefCount) == 1)
        {
            if (pNic->RfInfo.RadioStateChangeInProgress)
            {
                // Radio state is being changed, dont proceed
                bResult = FALSE;
                break;
            }
            
            if ((NewRFState == RF_ON) || (NewRFState == RF_SLEEP))
            {
                if (pNic->RfInfo.RadioOff == TRUE)
                {
                    // Radio is OFF, dont change RF state
                    bResult = FALSE;
                    break;
                }
            }
            
            SetRFPowerState(pNic, NewRFState);
        }
        else
        {
            // Another thread is changing RF/Radio state,
            // dont modify. We bail out and the caller can decide if it wants to
            // reattempt (we dont wait since we may be called at high IRQL, etc)
            MpTrace(COMP_POWER, DBG_LOUD, ("Unable to set RF/Radio state as something else is updating it\n"));
            bResult = FALSE;
        }
    }while (FALSE);

    InterlockedDecrement(&pNic->RfInfo.AccessRefCount);
    
    return bResult;
}

// Called at passive
VOID
HwSetRadioState(
    IN  PNIC    pNic,
    IN  BOOLEAN bPowerOn
    )
{
    // Set flag so other threads (power save, scan timer, etc) wont change
    // state behind us
    pNic->RfInfo.RadioStateChangeInProgress = TRUE;

    // We wait for ever for other threads to not reach this state
    while (pNic->RfInfo.AccessRefCount != 0);

    //
    // Set the Radio state
    //
    if (bPowerOn)
    {
        SetRFPowerState(pNic, RF_ON);
        pNic->RfInfo.RadioOff = FALSE;
    }
    else
    {
        pNic->RfInfo.RadioOff = TRUE;

        SetRFPowerState(pNic, RF_SHUT_DOWN);
        UpdatePortUchar(pNic, MSR, &0xF3);
    }

    pNic->RfInfo.RadioStateChangeInProgress = FALSE;
}

USHORT
HwGenerateBeacon(
    IN  PNIC pNic,
    IN  PUCHAR BeaconBuf,
    IN  BOOLEAN APModeFlag)
{
    int                     i, j;
    OctetString             os;
    OctetString             Beacon;
    BeaconProbeRspPartial  *pBeaconPartial;
    MP_TIM_ELEMENT          dot11TimElement;
    UCHAR                   Rates[7] = {0x82, 0x84, 0x8b, 0x96, 0x8c, 0x98, 0xb0};
    UCHAR		            ExRates[8] = {0x0c, 0x12, 0x18, 0x24, 0x30, 0x48, 0x60, 0x6C};
    
    // Setup Beacon Packet
    pBeaconPartial = (BeaconProbeRspPartial *)BeaconBuf;

    pBeaconPartial->GenPacketPartial.frameCtl.charData[0] = Type_Beacon;
    pBeaconPartial->GenPacketPartial.frameCtl.charData[1] = 0;
    
    pBeaconPartial->GenPacketPartial.Duration = 0;
    NdisFillMemory( pBeaconPartial->GenPacketPartial.Addr1, 6, 0xff);
    ETH_COPY_NETWORK_ADDRESS(pBeaconPartial->GenPacketPartial.Addr2, pNic->CardInfo.MacAddr);
    ETH_COPY_NETWORK_ADDRESS(pBeaconPartial->GenPacketPartial.Addr3, pNic->ManagementInfo.BssId);
    
    pBeaconPartial->GenPacketPartial.Seq = 0;
    pBeaconPartial->BeaconInterval = (USHORT)pNic->DupCurrentInfo.BeaconInterval;
    pBeaconPartial->CapabilityInfo = pNic->ManagementInfo.CapInfo;

    FillOctetString(Beacon, BeaconBuf, 0x24);
    
    FillOctetString(os, pNic->ManagementInfo.SSID, (USHORT)strlen((PCHAR)pNic->ManagementInfo.SSID));

    PacketMakeElement(&Beacon, EID_SsId, os);

    if (pNic->CardInfo.HardwareID == HW_ID_8185)
    {
        //A's packet 
        if (pNic->ManagementInfo.dot11CurrentWirelessMode == WIRELESS_MODE_A)
        {
            FillOctetString(os, ExRates, 8);
    	    PacketMakeElement(&Beacon, EID_SupRates, os);
        }
        else if(pNic->ManagementInfo.dot11CurrentWirelessMode == WIRELESS_MODE_B)
        {
            FillOctetString(os, Rates, 4);
    	    PacketMakeElement(&Beacon, EID_SupRates, os);
        }
        else //G mode
        {
            FillOctetString(os, Rates, 4);
            PacketMakeElement(&Beacon, EID_SupRates, os);

            //fill up extented rate
            FillOctetString(os,ExRates,8);
            PacketMakeElement(&Beacon, EID_ExtSupRates, os);	 
        }
    }
    else
    {
        // 8180
        FillOctetString(os, Rates, 4);
        PacketMakeElement(&Beacon, EID_SupRates, os);
    }
    

    FillOctetString(os, &pNic->ManagementInfo.OperatingPhyMIB->Channel, 1);
    PacketMakeElement(&Beacon, EID_DSParms, os);

    if (APModeFlag)         // TIM parameter field
    {
        USHORT      uSize;
        uSize = 6;
        FillOctetString(os, ((PUCHAR)&dot11TimElement) + sizeof(DOT11_INFO_ELEMENT), uSize - 2);
        PacketMakeElement(&Beacon, EID_Tim, os);
    }
    else       // IBSS parameter field
    {
        FillOctetString(os, (PUCHAR)&pNic->ManagementInfo.AtimWindow, 2);
        PacketMakeElement(&Beacon, EID_IbssParms, os);
    }

    //3 Append other IEs
    for (i = EID_IbssParms + 1; i < 256; i++) 
    {
        UCHAR   Size;
        PUCHAR  Data;

        j = 0;
        do 
        {
            Data = HwGetIE(pNic, (UCHAR)i, (UCHAR)j, &Size);
            if (Data != NULL) 
            {
                FillOctetString(os, Data, Size);
                PacketMakeElement(&Beacon, i, os);
            }

            j++;
        } while (i == 0xdd && Data != NULL);
    }

    return Beacon.Length;
}

void
HwSetupBeacon(
    IN  PNIC pNic,
    IN  PUCHAR BeaconBuf,
    IN  USHORT BeaconBufLen,
    IN  ULONG BeaconBufPaLow,
    IN  USHORT Rate
    )
{
    HwTxFillDescriptor(pNic,
                       pNic->TxInfo.TxDesc[BEACON_QUEUE],
                       BeaconBuf,
                       TRUE,
                       TRUE,
                       BeaconBufPaLow,
                       BeaconBufLen,
                       BeaconBufLen,
                       Rate,
                       TRUE,
                       FALSE,
                       FALSE,
                       FALSE,
                       FALSE,
                       0,
                       TRUE,
                       FALSE,
                       BEACON_QUEUE);
}


void
HwPeriodTimerCallback(
	IN PVOID		SystemSpecific1,
	IN PVOID		param,
	IN PVOID		SystemSpecific2,
	IN PVOID		SystemSpecific3 
	)
{
    PNIC pNic = (PNIC)param;

    UNREFERENCED_PARAMETER(SystemSpecific1);
    UNREFERENCED_PARAMETER(SystemSpecific2);
    UNREFERENCED_PARAMETER(SystemSpecific3);

    // Hardware function does the work
    HwPeriodTimerHandler(pNic);
    
    // Tx data rate negotiation
        HwUpdateTxDataRate(pNic);

    //
    // If permitted (Sync > 1), requeue the timer
    //
    if (pNic->ManagementInfo.HwPeriodTimerSync > 1)
    {
        // If 1, this timer should not be requeued (the count is for this timer)
        NdisInterlockedIncrement(&pNic->ManagementInfo.HwPeriodTimerSync);   // New timer queued
        NdisMSetPeriodicTimer(&pNic->ManagementInfo.Timer_HwPeriod,HWPERIOD_TIMER_IN_MS);        
    }

    // This timer is done
    NdisInterlockedDecrement(&pNic->ManagementInfo.HwPeriodTimerSync);   // Stop queuing new timers

}


UCHAR
HwMRateToHwRate(
    IN  UCHAR    rate)
{
    switch(rate)
    {
        case 2:     return 0;
        case 4:     return 1;
        case 11:    return 2;
        case 22:    return 3;
        case 12:    return 4;
        case 18:    return 5;
        case 24:    return 6;
        case 36:    return 7;
        case 48:    return 8;
        case 72:    return 9;
        case 96:    return 10;
        case 108:   return 11;

        default:
            MpTrace(COMP_SEND, DBG_SERIOUS, ("!!MRate not supported. Rate: %d!!\n", rate));
            MPASSERT(FALSE);
            break;
    }

    return 0;
}

UCHAR
HwHwRateToMRate(
    IN  UCHAR    rate)
{
    static UCHAR RateMap[] = {2, 4, 11, 22, 12, 18, 24, 36, 48, 72, 96, 108};

    if (rate < sizeof(RateMap))
        return RateMap[rate];

    MpTrace(COMP_SEND, DBG_SERIOUS, ("!!HwRate not supported. Rate: %d!!\n", rate));
    MPASSERT(FALSE);

    return 2;
}

ULONG64
HwDataRateToLinkSpeed(
    UCHAR  rate
    )
{
    return ((ULONG64)500000) * rate;
}

UCHAR
HwLinkSpeedToDataRate(
    ULONG64 linkSpeed
    )
{
    return (UCHAR)(linkSpeed / 500000);
}

NDIS_STATUS
HwAllocateAlignPhyMemory(
    IN  PNIC                    pNic,
    IN  ULONG                   Length,
    IN  PUCHAR                 *VirtualAddr,
    IN  NDIS_PHYSICAL_ADDRESS  *PhysicalAddr,
    IN  PUCHAR                 *AlignVirtualAddr,
    IN  NDIS_PHYSICAL_ADDRESS  *AlignPhysicalAddr)
{
    ULONG            PhyAddr;
    ULONG            NewPhyAddr;
    ULONG            Offset;

    if (Length > MAXUSHORT) // integer overflow check
    {
        return NDIS_STATUS_RESOURCES;
    }
    Length += 0xff;        // for alignment
    
    NdisMAllocateSharedMemory(pNic->MiniportAdapterHandle,
                              Length,
                              FALSE,
                              (void **)VirtualAddr,
                              PhysicalAddr);
    
    if (*VirtualAddr == NULL) 
    {
        return NDIS_STATUS_RESOURCES;
    }

    NdisZeroMemory(*VirtualAddr, Length);
    PhyAddr = NdisGetPhysicalAddressLow(*PhysicalAddr);
    NewPhyAddr = ((PhyAddr + 0xff) & 0xFFFFFF00);
    Offset = NewPhyAddr - PhyAddr;
    
    (*AlignPhysicalAddr).LowPart = (*PhysicalAddr).LowPart + Offset;
    (*AlignPhysicalAddr).HighPart = (*PhysicalAddr).HighPart;
    
    *AlignVirtualAddr = *VirtualAddr + Offset;

    return NDIS_STATUS_SUCCESS;
}

void
HwLinkTxDesc(
    IN  PUCHAR                    VirtualAddr,
    IN  NDIS_PHYSICAL_ADDRESS     PhysicalAddr,
    IN  USHORT                    DescSize,
    IN  USHORT                    DescNum)
{
    int i;
    PTX_DESC TxDesc = (PTX_DESC)VirtualAddr;
    
    for (i = 0; i < DescNum - 1; i++)
    {
        TxDesc[i].NextDescAddress = PhysicalAddr.LowPart + DescSize * (i + 1);
    }

    TxDesc[i].NextDescAddress = PhysicalAddr.LowPart;
}


ULONG
HwGetTxBusyDescNum(
    IN  PNIC pNic,
    IN  int QueueIndex)
{
    int BusyNum = pNic->TxInfo.TxNextDescToSend[QueueIndex] - pNic->TxInfo.TxNextDescToCheck[QueueIndex];
    
    if (BusyNum < 0)
    {
        BusyNum += pNic->TxInfo.TxTotalDescNum[QueueIndex];
    }

    return BusyNum;
}

ULONG
HwGetTxFreeDescNum(
    IN  PNIC pNic,
    IN  int QueueIndex)
{
    //
    // The -1 is there because we cannot use all the desc for rtl8180. We have to leave at least one
    // free at all times.
    //
    return pNic->TxInfo.TxTotalDescNum[QueueIndex] - HwGetTxBusyDescNum(pNic,QueueIndex) - 1;
}


void 
HwTransmitNextPacketWithLocalBuffer(
    IN  PNIC       pNic,
    IN  ULONG      QueueIndex,
    IN  USHORT     PktSize,
    IN  USHORT     Rate,
    IN  BOOLEAN    bAIDContained,
    IN  BOOLEAN    bTxDescProtection)
{
    PTX_DESC    pDesc;
    PUCHAR      TxBuf;
    ULONG       TxBufPaLow;
    USHORT      AckCtsTime;

    if (HwGetTxFreeDescNum(pNic, QueueIndex) > 0) 
    { 
        if (HwAwake(pNic, TRUE) == FALSE)
        {
            return; // This packet wont be sent, we drop it silently
        }
    	 
        pDesc=HwGetNextDescToSend(pNic,QueueIndex,0, bTxDescProtection);

        if (QueueIndex == NORMAL_QUEUE) 
        {
            TxBuf = HwNormalQGetNextToSendBuffer(pNic);
            TxBufPaLow = pNic->TxInfo.pTxNormalQBufPa[pNic->TxInfo.TxNextDescToSend[QueueIndex]].LowPart;
        }
        else if (QueueIndex == HIGH_QUEUE) 
        {
            TxBuf = HwHighQGetNextToSendBuffer(pNic);
            TxBufPaLow = pNic->TxInfo.pTxHighQBufPa[pNic->TxInfo.TxNextDescToSend[QueueIndex]].LowPart;
        }
        else 
        {
            return;
        }

        if (!bAIDContained)
        {
            if (HwIsMulticast(TxBuf)) 
            {
                *((USHORT *)(&TxBuf[2])) = 0;    // Set duration to 0
            }
            else 
            {
                AckCtsTime = ComputeTxTime(sAckCtsLng / 8, Rate, TRUE, FALSE);    // calculate AckCtsTime
                *((USHORT *)(&TxBuf[2])) = aSifsTime + AckCtsTime;
            }
        }

        HwTxFillDescriptor(pNic,
                           pDesc,
                           TxBuf,
                           TRUE,
                           TRUE,
                           TxBufPaLow,
                           PktSize,
                           PktSize,
                           Rate,
                           HwIsMulticast(TxBuf),
                           FALSE,
                           FALSE,
                           FALSE,
                           FALSE,
                           0,
                           TRUE,
                           FALSE,
                           QueueIndex);

        HwTxPolling(pNic,QueueIndex);
        HwIncrementNextDescToSend(pNic, QueueIndex, 1, bTxDescProtection);
    }
}

// Called: DeviceIRQL
void
HwOnProbe(
    IN  PNIC      pNic,
    IN  PUCHAR    ProbePktBuf,
    IN  USHORT    ProbePktLen,
    IN  USHORT    ProbePktRate)
{
    int                     i, j;
    PUCHAR                  TxBuf;
    OctetString             os;
    OctetString             ProbeReq;
    OctetString             ProbeRsp;
    BeaconProbeRspPartial  *pProbeRspPartial;
    UCHAR                   Rates[7] = {0x82, 0x84, 0x8b, 0x96, 0x8c, 0x98, 0xb0};
    UCHAR		            ExRates[8] = {0x0c, 0x12, 0x18, 0x24, 0x30, 0x48, 0x60, 0x6C};
	
    // TODO: original design was to send probe response in high queue with locking.
    // however, the hardware does not send anything in high queue although
    // all register settings are correct. before realtek responds and provides
    // a solution, we will have to use normal queue without lock. this is ok
    // for ap as all other packets from LWF are sent in low queue. the problem
    // is in adhoc mode, this change will cause a same tx desc to be acquired
    // by multiple senders.
    
    if (HwGetTxFreeDescNum(pNic, NORMAL_QUEUE) > 0) 
    {
        TxBuf = HwNormalQGetNextToSendBuffer(pNic);

        //
        // Setup Probe Response Packet
        //
        FillOctetString(ProbeReq, ProbePktBuf, ProbePktLen);
        
        pProbeRspPartial = (BeaconProbeRspPartial *) TxBuf;

        pProbeRspPartial->GenPacketPartial.frameCtl.charData[0] = Type_Probe_Rsp;
        pProbeRspPartial->GenPacketPartial.frameCtl.charData[1] = 0;
        pProbeRspPartial->GenPacketPartial.Duration = 0;

        NdisMoveMemory(pProbeRspPartial->GenPacketPartial.Addr1, ProbeReq.Octet + 10, 6);
        ETH_COPY_NETWORK_ADDRESS(pProbeRspPartial->GenPacketPartial.Addr2, pNic->CardInfo.MacAddr);
        ETH_COPY_NETWORK_ADDRESS(pProbeRspPartial->GenPacketPartial.Addr3, pNic->ManagementInfo.BssId);
        pProbeRspPartial->GenPacketPartial.Seq = 0;        
        pProbeRspPartial->BeaconInterval = (USHORT)pNic->DupCurrentInfo.BeaconInterval;
        pProbeRspPartial->CapabilityInfo = pNic->ManagementInfo.CapInfo;

        // Size of Probe Response, can not use sizeof(BeaconProbeRspPartial)
        FillOctetString(ProbeRsp, TxBuf, 0x24);

        FillOctetString(os, pNic->ManagementInfo.SSID, (USHORT)strlen((CHAR*)pNic->ManagementInfo.SSID));
        PacketMakeElement(&ProbeRsp, EID_SsId, os);

        if (pNic->CardInfo.HardwareID == HW_ID_8185)
        {
            if (pNic->ManagementInfo.dot11CurrentWirelessMode == WIRELESS_MODE_A)
            {
                FillOctetString(os, ExRates, 8);
    	        PacketMakeElement(&ProbeRsp, EID_SupRates, os);
            }
            else if (pNic->ManagementInfo.dot11CurrentWirelessMode == WIRELESS_MODE_B)
            {
                FillOctetString(os, Rates, 4);
    	        PacketMakeElement(&ProbeRsp, EID_SupRates, os);
            }
            else //wirelessmodeG
            {
           	    FillOctetString(os, Rates, 4);
    	 	    PacketMakeElement(&ProbeRsp, EID_SupRates, os);

    	 	    //fill up extented rate
    		    FillOctetString(os,ExRates,8);
    		    PacketMakeElement(&ProbeRsp, EID_ExtSupRates, os);
            }
        }
        else
        {
            // 8180
            FillOctetString(os, Rates, 4);
    	    PacketMakeElement(&ProbeRsp, EID_SupRates, os);
        }

        FillOctetString(os, &pNic->ManagementInfo.OperatingPhyMIB->Channel, 1);
        PacketMakeElement(&ProbeRsp, EID_DSParms, os);

        if (pNic->ManagementInfo.CurrentBSSType == dot11_BSS_type_independent) 
        {
            FillOctetString(os, (PUCHAR)&pNic->ManagementInfo.AtimWindow, 2);
            PacketMakeElement(&ProbeRsp, EID_IbssParms, os);
        }

        //
        // Append other IEs
        //
        for (i = EID_IbssParms + 1; i < 256; i++)
        {
            UCHAR   Size;
            PUCHAR  Data;

            j = 0;
            do 
            {
                Data = HwGetIE(pNic, (UCHAR)i, (UCHAR)j, &Size);
                if (Data != NULL)
                {
                    FillOctetString(os, Data, Size);
                    PacketMakeElement(&ProbeRsp, i, os);
                }

                j++;
            } while(i == 0xdd && Data!=NULL);
        }

        //
        // Read the timestamp from TSF and place it in the Probe Response
        // Read the high word first. Low word changes frequently and we 
        // want the freshest value we can get.
        //
        ReadPortUlong(pNic, TSFR + 0x04, (((PULONG)&pProbeRspPartial->TimeStamp) + 1));
        ReadPortUlong(pNic, TSFR, (PULONG)&pProbeRspPartial->TimeStamp);
        
        HwTransmitNextPacketWithLocalBuffer(pNic,
                                            NORMAL_QUEUE,         // TODO: should really use high queue here
                                            ProbeRsp.Length,
                                            ProbePktRate,
                                            FALSE,
                                            FALSE);
    }
}

// Called: DISPATCH
void
HwSendProbe(
    IN PNIC                 pNic,
    IN PDOT11_MAC_ADDRESS   pBSSID,
    IN PDOT11_SSID          pSSID,
    IN PUCHAR               ScanAppendIEByteArray,
    IN USHORT               ScanAppendIEByteArrayLength
    )
{
    PUCHAR                  TxBuf;
    OctetString             os;
    OctetString             ProbeRsp;
    GeneralPacketPartial   *pProbeRequestPartial;
    BOOLEAN                 bAnyProbe;
    UCHAR                   Rates[7] = {0x82, 0x84, 0x8b, 0x96, 0x8c, 0x98, 0xb0};
    UCHAR		            ExRates[8] = {0x0c, 0x12, 0x18, 0x24, 0x30, 0x48, 0x60, 0x6C};

    bAnyProbe = FALSE;
    
    if (HwGetTxFreeDescNum(pNic, NORMAL_QUEUE) > 0)
    {
        TxBuf = HwNormalQGetNextToSendBuffer(pNic);

        //
        // Setup Probe Response Packet
        //
        pProbeRequestPartial = (GeneralPacketPartial *) TxBuf;

        pProbeRequestPartial->frameCtl.charData[0] = Type_Probe_Req;
        pProbeRequestPartial->frameCtl.charData[1] = 0;
        pProbeRequestPartial->Duration = 0;
        NdisFillMemory(pProbeRequestPartial->Addr1, 6, (UCHAR)0xff);
        ETH_COPY_NETWORK_ADDRESS(pProbeRequestPartial->Addr2, pNic->CardInfo.MacAddr);
        NdisMoveMemory(pProbeRequestPartial->Addr3, pBSSID, 6);
        pProbeRequestPartial->Seq = 0;

        //
        // Size of Probe Request, can not use sizeof(GeneralPacketPartial)
        //
        FillOctetString(ProbeRsp, TxBuf, 0x18);
        
        FillOctetString(os, pSSID->ucSSID, bAnyProbe ? 0 : (USHORT)pSSID->uSSIDLength);
        PacketMakeElement(&ProbeRsp, EID_SsId, os);

        if (pNic->CardInfo.HardwareID == HW_ID_8185)
        {
            if (pNic->ManagementInfo.dot11CurrentWirelessMode == WIRELESS_MODE_A)
            {
                FillOctetString(os, ExRates, 8);
    	        PacketMakeElement(&ProbeRsp, EID_SupRates, os);
            }
            else if (pNic->ManagementInfo.dot11CurrentWirelessMode == WIRELESS_MODE_B)
            {
                FillOctetString(os, Rates, 4);
    	        PacketMakeElement(&ProbeRsp, EID_SupRates, os);
            }
            else //wirelessmodeG
            {
           	    FillOctetString(os, Rates, 4);
    	 	    PacketMakeElement(&ProbeRsp, EID_SupRates, os);

    	 	    //fill up extented rate
    		    FillOctetString(os,ExRates,8);
    		    PacketMakeElement(&ProbeRsp, EID_ExtSupRates, os);
            }
        }
        else
        {
            // 8180
            FillOctetString(os, Rates, 4);
    	    PacketMakeElement(&ProbeRsp, EID_SupRates, os);
        }

        if (ScanAppendIEByteArrayLength > 0) 
        {
            //
            // Append IEs needed for WPA etc.
            //
            FillOctetString(os, ScanAppendIEByteArray, ScanAppendIEByteArrayLength);
            PacketAppendData(&ProbeRsp, os);
        }

        HwTransmitNextPacketWithLocalBuffer(pNic,
                                            NORMAL_QUEUE,
                                            ProbeRsp.Length,
                                            pNic->ManagementInfo.CurrentBeaconRate,
                                            FALSE,
                                            TRUE);
    }
}

LONG
HwGetPositionInBuffer(
    IN  ULONG    PriorLength,
    IN  ULONG    BufferLength,
    IN  ULONG    TotalOffset)
{
    if (TotalOffset >= PriorLength && TotalOffset < (PriorLength + BufferLength))
        return TotalOffset - PriorLength;
    else
        return -1;
}

ULONG
HwGetPhysicalAddressFromScatterGatherList(
    IN  SCATTER_GATHER_LIST *pFragList,
    IN  ULONG Offset)
{
    ULONG i, PriorLength;

    for (i = 0, PriorLength = 0; i < pFragList->NumberOfElements; i++)
    {
        if (Offset >= PriorLength && Offset < (PriorLength + pFragList->Elements[i].Length))
            return pFragList->Elements[i].Address.LowPart + (Offset - PriorLength);
        
        PriorLength += pFragList->Elements[i].Length;
    }

    return 0;
}

void
HwScanComplete(
    IN  PNIC pNic
    )
{
    MpTrace(COMP_SCAN, DBG_LOUD, ("Scan operation completed\n"));
    
    //
    // Free the memory allocated for this operation
    //
    MP_FREE_MEMORY(pNic->ManagementInfo.ScanChannelList);
// 2    MP_FREE_MEMORY(pNic->ManagementInfo.ScanRequest);

    pNic->ManagementInfo.ScanChannelList = NULL;
    pNic->ManagementInfo.ScanRequest = NULL;
    
    //
    // Indicate scan completion to the OS
    //
    if (pNic->ManagementInfo.ScanCancelOperation)
        Mp11ScanComplete(pNic->pAdapter, NDIS_STATUS_REQUEST_ABORTED);
    else
        Mp11ScanComplete(pNic->pAdapter, NDIS_STATUS_SUCCESS);

    //
    // reset the scan state variables (after we have completed the scan)
    //
    pNic->ManagementInfo.bScanInProgress = FALSE;
    pNic->ManagementInfo.bScanCompleteIndicated = TRUE;

    //restore Hw related parameter 
    HwRestoreToBeforeScan(pNic);
	
    //
    // If we are in power saving mode and we are not associated, turn off the RF.
    // If we are associated, RF will be turned off by HwResponseToPacket.
    //
    NdisAcquireSpinLock(&pNic->ManagementInfo.PowerMgmtLock);
    if (pNic->ManagementInfo.PowerMgmtMode.dot11PowerMode == dot11_power_mode_powersave &&
        pNic->ManagementInfo.PowerMgmtMode.usAID == 0)
    {
        MpTrace(COMP_POWER, DBG_LOUD, (" *** RF OFF indefinitely\n"));
        HwSetRFState(pNic, RF_OFF);
    }
    NdisReleaseSpinLock(&pNic->ManagementInfo.PowerMgmtLock);
}


VOID
HwScanRestoreOriginalChannel(
    IN  PNIC pNic
    )
{
    HwScanComplete(pNic);
}

VOID
HwScanChannelSwitchComplete(
    IN  PNIC pNic
    )
{
    MpTrace(COMP_SCAN, DBG_LOUD, ("Channel switched\n"));

    //
    // The current scan state should be switch channel
    //
    MPVERIFY(pNic->ManagementInfo.ScanCurrentState == ScanStateSwChnl);

    //
    // ScanCallback has requested a channel switch. That operation has
    // been completed. We need to:
    // 1. Transition the scan state from Switch to Scan
    // 2. Schedule the ScanCallback DPC asap to do the scan.
    //
    HW_TRANSITION_SCAN_STATE(pNic->ManagementInfo.ScanCurrentState);
    NdisMSetTimer(&pNic->ManagementInfo.Timer_Scan,
                  pNic->ManagementInfo.ScanProbeDelay);
}

VOID
HwScanCallback(
    IN  PVOID SystemSpecific1,
    IN  PVOID param,
    IN  PVOID SystemSpecific2,
    IN  PVOID SystemSpecific3 )
{
    PNIC    pNic;
    ULONG   uRescheduleTime;

    UNREFERENCED_PARAMETER(SystemSpecific1);
    UNREFERENCED_PARAMETER(SystemSpecific2);
    UNREFERENCED_PARAMETER(SystemSpecific3);

    pNic = (PNIC) param;
    
    while (TRUE) 
    {
        if (pNic->ManagementInfo.ScanCurrentChannelIndex == pNic->ManagementInfo.ScanChannelCount) 
        {
            //
            // Last channel has been scanned. Revert to the channel we had before scan started
            //
            MpTrace(COMP_SCAN, DBG_LOUD, ("Done with the last channel. Revert back to original channel\n"));
            
            if (pNic->ManagementInfo.DestChannel == pNic->ManagementInfo.OperatingPhyMIB->Channel)
            {
                MpTrace(COMP_SCAN, DBG_LOUD, ("Already on target channel! Switch not required\n"));
                HwScanComplete(pNic);
            }
            else 
            {
                HwSetChannel(pNic, pNic->ManagementInfo.OperatingPhyMIB->Channel, HwScanRestoreOriginalChannel);
            }
            
            //
            // Don't reschedule the DPC. We are done.
            //
            return;
        }
        else if (pNic->ManagementInfo.ScanCancelOperation)
        {
            //
            // Scan operation has been cancelled
            //
            MpTrace(COMP_SCAN, DBG_LOUD, ("Scan operation has been cancelled\n"));
            
            //
            // Set the termination condition to true. This will cancel scan automatically
            //
            pNic->ManagementInfo.ScanCurrentChannelIndex = pNic->ManagementInfo.ScanChannelCount;

            continue;
        }
        else {
            if (pNic->ManagementInfo.ScanCurrentState == ScanStateSwChnl)
            {
                ULONG   uDestChannel;
                
                //
                // Switch to the next channel. ScanCurrentChannelIndex point to it.
                //                
                uDestChannel = pNic->ManagementInfo.ScanChannelList[pNic->ManagementInfo.ScanCurrentChannelIndex];
                
                MpTrace(COMP_SCAN, DBG_LOUD, ("Switching to Channel %d\n", uDestChannel));
                HwSetChannel(pNic, (UCHAR)uDestChannel, HwScanChannelSwitchComplete);
                
                //
                // Don't rescedule the DPC. We will do that when the channel switch completes
                //
                return;
            }
            else
            {
                ULONG                   i, BytesParsed = 0;
                PDOT11_SSID             pDot11SSID;
                PDOT11_SCAN_REQUEST_V2  pDot11ScanRequest = pNic->ManagementInfo.ScanRequest;
                
                //
                // Scan the current channel
                //
                if ((pDot11ScanRequest->dot11ScanType == dot11_scan_type_active) ||
                    (pDot11ScanRequest->dot11ScanType == (dot11_scan_type_active | dot11_scan_type_forced)) ||
                    (pDot11ScanRequest->dot11ScanType == dot11_scan_type_auto) ||
                    (pDot11ScanRequest->dot11ScanType == (dot11_scan_type_auto | dot11_scan_type_forced)))
                {
                    //
                    // For active scan send out probes. Auto is active for us.
                    // We will send out a probe request for each SSID in the request
                    //
                    for (i = 0; i < pDot11ScanRequest->uNumOfdot11SSIDs; i++) 
                    {
                        pDot11SSID = (PDOT11_SSID) (pDot11ScanRequest->ucBuffer + 
                                                    pDot11ScanRequest->udot11SSIDsOffset + 
                                                    BytesParsed);

                        HwSendProbe(pNic,
                                    &pDot11ScanRequest->dot11BSSID,
                                    pDot11SSID,
                                    pDot11ScanRequest->ucBuffer + pDot11ScanRequest->uIEsOffset,
                                    (USHORT) pDot11ScanRequest->uIEsLength);
                        
                        BytesParsed += sizeof(DOT11_SSID);
                    }
                }
                else 
                {
                    //
                    // If passive scanning, we will park longer. Beacons and probes
                    // are indicated up anyways. We need not do anything.
                    //
                }

                //
                // Move to the next Scan state.
                //
                HW_TRANSITION_SCAN_STATE(pNic->ManagementInfo.ScanCurrentState);

                //
                // If we are going to switch to the next channel, 
                // move to the desired channel
                //
                if (pNic->ManagementInfo.ScanCurrentState == ScanStateSwChnl) 
                {
                    pNic->ManagementInfo.ScanCurrentChannelIndex++;
                }

                uRescheduleTime = pNic->ManagementInfo.ScanChannelTime;
            }
        }

        //
        // Always break out. We will loop only if cancel is received.
        //
        break;
    }

    //
    // Reschedule the DPC
    //
    MPVERIFY(uRescheduleTime > 0);
    NdisMSetTimer(&pNic->ManagementInfo.Timer_Scan, uRescheduleTime);
}


VOID
HwSwChnlWorkItem(
    IN  PVOID           Context,
    IN  NDIS_HANDLE     NdisIoWorkItemHandle
    )
{
    PNIC pNic = (PNIC) Context;
    
    UNREFERENCED_PARAMETER(NdisIoWorkItemHandle);

    SwChnlPhy(pNic, pNic->ManagementInfo.DestChannel, FALSE);
    
    if (pNic->ManagementInfo.bScanInProgress)
    {
        ReadPortUlong(pNic, TSFR + 0x04, (((PULONG)&pNic->ManagementInfo.ScanChannelSwitchTime) + 1));
        ReadPortUlong(pNic, TSFR, (PULONG)&pNic->ManagementInfo.ScanChannelSwitchTime);
        pNic->ManagementInfo.ScanCurrentChannel = pNic->ManagementInfo.DestChannel;
    }
    else
    {
        pNic->ManagementInfo.OperatingPhyMIB->Channel = pNic->ManagementInfo.DestChannel;
    }

    //
    // Call the completion routine if provided.
    // There is need for a completion routine if OS calls
    // us (OID_DOT11_CURRENT_CHANNEL, START_REQUEST, JOIN_REQUEST)
    // but not if we are changing the channel ourselves (example
    // during a scan operation)
    //
    if (pNic->ManagementInfo.ChannelSwitchedHandler != NULL)
    {
        pNic->ManagementInfo.ChannelSwitchedHandler(pNic);
    }
}

void
HwJoinTimeoutCallback(
    IN  PVOID SystemSpecific1,
    IN  PVOID param,
    IN  PVOID SystemSpecific2,
    IN  PVOID SystemSpecific3)
{
    PNIC    pNic = (PNIC) param;
    
    UNREFERENCED_PARAMETER(SystemSpecific1);
    UNREFERENCED_PARAMETER(SystemSpecific2);
    UNREFERENCED_PARAMETER(SystemSpecific3);

    MPVERIFY(HW_IS_IN_STA_ADHOC_MODE(pNic) == FALSE);

    //
    // Cancel the Join operation if it has not already completed
    //
    if (HW_STOP_WAITING_FOR_JOIN(pNic) == TRUE) 
    {
        //
        // Restore the packet filter before failing Join
        //
        Hw11ResetFilterFunction(pNic);

        MpTrace(COMP_ASSOC, DBG_NORMAL, ("Cancelled the Join Operation as it took too long\n"));

        Sta11JoinCompleteInfra(pNic->pStation, NDIS_STATUS_FAILURE);

    }
}

NDIS_STATUS
HwGetInfoIEWithOUI(
    IN PUCHAR pucInfoBlob,
    IN ULONG uSizeOfBlob,
    IN UCHAR ucInfoId,
    OUT PUCHAR pucLength,
    IN OUT PVOID * ppvInfoEle,
    IN OUT PULONG pOffset
    )
{
    NDIS_STATUS ndisStatus = NDIS_STATUS_FAILURE;
    PDOT11_INFO_ELEMENT pInfoEleHdr = NULL;
    ULONG uRequiredSize = 0;

    *pucLength = 0;
    *ppvInfoEle = NULL;
    uSizeOfBlob -= *pOffset;
    pucInfoBlob += *pOffset;
    while(uSizeOfBlob) 
    {
        pInfoEleHdr = (PDOT11_INFO_ELEMENT)pucInfoBlob;
        if (uSizeOfBlob < sizeof(DOT11_INFO_ELEMENT))
            break;

        uRequiredSize = (ULONG)(pInfoEleHdr->Length) + sizeof(DOT11_INFO_ELEMENT);
        if (uSizeOfBlob < uRequiredSize)
            break;

        *pOffset+=uRequiredSize;
        if (pInfoEleHdr->ElementID == ucInfoId) 
        {
            *pucLength = pInfoEleHdr->Length;
            *ppvInfoEle = pucInfoBlob + sizeof(DOT11_INFO_ELEMENT);
            ndisStatus = NDIS_STATUS_SUCCESS;
            break;
        }

        uSizeOfBlob -= uRequiredSize;
        pucInfoBlob += uRequiredSize;
    }

    return ndisStatus;
}


BOOLEAN
HwAddIE(
    IN  PNIC     pNic,
    IN  UCHAR    ID,
    IN  UCHAR    Size,
    IN  PUCHAR   Data
    )
{
    // This function only stores IE which has ID large than EID_IbssParms.
    // It can not be used to update IE.
    // To update IE, you must call HwRemoveIE() before this function
    
    int index;

    //
    // Find the IE buffer to add the new IE.
    //
    for(index = 0; index < MAX_IE_NUMBER; index++)
    {
        if (pNic->ManagementInfo.IEs[index].bUse == FALSE)      // Add IE if there is unused IE buffer
        {    
            if (ID == 0xdd) 
            {
                pNic->ManagementInfo.WPAIECount++;
                pNic->ManagementInfo.IEs[index].OUI = *((PULONG)Data);
            }
            
            pNic->ManagementInfo.IEs[index].bUse=TRUE;
            pNic->ManagementInfo.IEs[index].ID=ID;
            pNic->ManagementInfo.IEs[index].Size=Size;
            NdisMoveMemory(pNic->ManagementInfo.IEs[index].Data, Data, Size);
            pNic->ManagementInfo.IEMap[ID] = (CHAR) index;

            return TRUE;
        }
    }
            
    return FALSE;
}

VOID
HwRemoveIE(
    IN  PNIC   pNic,
    IN  UCHAR  ID,
    IN  PUCHAR Data
    )
{
    int index;

    if (pNic->ManagementInfo.IEMap[ID] != -1)    // Update IE(this ID already exist)
    {
        if (ID != 0xdd)        // Not WPA IE
        {
            index=pNic->ManagementInfo.IEMap[ID];
            pNic->ManagementInfo.IEMap[ID] = -1;
            pNic->ManagementInfo.IEs[index].bUse = FALSE;
        }
        else
        {
            // Search IE with ID and OUI
            for (index = 0; index < MAX_IE_NUMBER; index++) 
            {
                if (pNic->ManagementInfo.IEs[index].bUse == TRUE &&
                    pNic->ManagementInfo.IEs[index].ID == 0xdd && 
                    pNic->ManagementInfo.IEs[index].OUI == *((ULONG UNALIGNED *)Data))
                {
                    pNic->ManagementInfo.WPAIECount--;
                    pNic->ManagementInfo.IEs[index].bUse = FALSE;
                    
                    if (pNic->ManagementInfo.WPAIECount == 0) 
                    {
                        pNic->ManagementInfo.IEMap[ID] = -1;
                        break;
                    }
                }
            }
        }
    }
}

PUCHAR
HwGetIE(
    IN  PNIC               pNic,
    IN  UCHAR              ID,
    IN  UCHAR              SubIEIndex,
    OUT PUCHAR             Size
    )
{
    int index;

    if (pNic->ManagementInfo.IEMap[ID] == -1)
        return NULL;

    if (ID != 0xdd)
        index = pNic->ManagementInfo.IEMap[ID];
    else 
    {
        if (SubIEIndex >= pNic->ManagementInfo.WPAIECount)
            return NULL;
        
        for (index = 0; index < MAX_IE_NUMBER; index++)
        {
            if (pNic->ManagementInfo.IEs[index].bUse == TRUE && pNic->ManagementInfo.IEs[index].ID == 0xdd) {
                if (SubIEIndex == 0)
                    break;

                SubIEIndex--;
            }
        }
    }
    
    MPASSERTMSG("Get IE Error", index < MAX_IE_NUMBER);
    MPASSERTMSG("Get IE Error", pNic->ManagementInfo.IEs[index].bUse == TRUE && pNic->ManagementInfo.IEs[index].ID == ID);
    
    if (index >= MAX_IE_NUMBER)
    {
        ASSERT(FALSE);
        return NULL;
    }
    
    *Size = pNic->ManagementInfo.IEs[index].Size;
    return pNic->ManagementInfo.IEs[index].Data;
}

VOID
HwClearAllIE(
    IN  PNIC        pNic
    )
{
    int i;

    for ( i = 0; i < MAX_IE_NUMBER; i++)
        pNic->ManagementInfo.IEs[i].bUse = FALSE;

    pNic->ManagementInfo.WPAIECount = 0;

    // Set all Map to -1(unused)
    NdisFillMemory(pNic->ManagementInfo.IEMap, sizeof(pNic->ManagementInfo.IEMap), 0xff);
}

// Called: DISPATCH
BOOLEAN
HwSendNullPkt(
    IN  PNIC   pNic
    )
{
    PUCHAR                  TxBuf;
    GeneralPacketPartial   *pNullPkt;

    if (HwGetTxFreeDescNum(pNic, NORMAL_QUEUE) > 0) 
    {
        //
        // Save Desc pointer, so that we can check send status of this packet
        //
        pNic->ManagementInfo.pPowerMgmtChangePktDesc=HwGetNextDescToSend(pNic, NORMAL_QUEUE, 0, TRUE);
        TxBuf=HwNormalQGetNextToSendBuffer(pNic);

        //
        // Setup NULL Packet
        //
        pNullPkt = (GeneralPacketPartial *) TxBuf;

        pNullPkt->frameCtl.charData[0] = Type_Null_Frame;
        pNullPkt->frameCtl.field.ToDS= 1;
        pNullPkt->Duration = 0;
        NdisMoveMemory(pNullPkt->Addr1, pNic->ManagementInfo.BssId, 6);
        ETH_COPY_NETWORK_ADDRESS(pNullPkt->Addr2, pNic->CardInfo.MacAddr);
        NdisMoveMemory(pNullPkt->Addr3, pNic->ManagementInfo.BssId, 6);
        pNullPkt->Seq = 0;

        HwTransmitNextPacketWithLocalBuffer(pNic,
                                            NORMAL_QUEUE,
                                            24,
                                            pNic->ManagementInfo.CurrentBeaconRate,
                                            FALSE,
                                            TRUE);
        
        return TRUE;
    }
    else
        return FALSE;
}

// Called: DISPATCH
BOOLEAN
HwSendPSPoll(
    IN  PNIC pNic
    )
{
    PUCHAR                  TxBuf;
    GeneralPacketPartial   *pPSPoll;

    if(HwGetTxFreeDescNum(pNic, NORMAL_QUEUE) > 0)
    {
        TxBuf=HwNormalQGetNextToSendBuffer(pNic);

        //
        // Setup PS-Poll Packet
        //
        pPSPoll = (GeneralPacketPartial *) TxBuf;

        pPSPoll->frameCtl.charData[0] = Type_PS_poll;
        pPSPoll->frameCtl.charData[1] = 0;
        pPSPoll->Duration = pNic->ManagementInfo.PowerMgmtMode.usAID | 0xC000;
        NdisMoveMemory(pPSPoll->Addr1, pNic->ManagementInfo.BssId, 6);
        ETH_COPY_NETWORK_ADDRESS(pPSPoll->Addr2, pNic->CardInfo.MacAddr);

        HwTransmitNextPacketWithLocalBuffer(pNic,
                                            NORMAL_QUEUE,
                                            16,
                                            pNic->ManagementInfo.CurrentBeaconRate,
                                            TRUE,
                                            TRUE);
        
        return TRUE;
    }
    else
        return FALSE;
}

ULONG
HwComputeCrc(
    IN  PUCHAR Buffer,
    IN  UINT Length
    )
{
    ULONG Crc, Carry;
    UINT i, j;
    UCHAR CurByte;

    Crc = 0xffffffff;

    for (i = 0; i < Length; i++)
    {
        CurByte = Buffer[i];
        for (j = 0; j < 8; j++)
        {
            Carry = ((Crc & 0x80000000) ? 1 : 0) ^ (CurByte & 0x01);
            Crc <<= 1;
            CurByte >>= 1;
            if (Carry)
            {
                Crc = (Crc ^ 0x04c11db6) | Carry;
            }
        }
    }
    Crc = Crc & 0x0ff000000;                    // 95.05.04     Sid
    return Crc;
}

VOID
HwGetMulticastBit(
    IN  PUCHAR Address,
    OUT PUCHAR Byte,
    OUT PUCHAR Value
    )
{
    ULONG     Crc;
    UINT     BitNumber;

    Crc = HwComputeCrc(Address, ETH_LENGTH_OF_ADDRESS);

    // The bit number is now in the 6 most significant bits of CRC.
    BitNumber = (UINT)((Crc >> 26) & 0x3f);
    *Byte = (UCHAR)(BitNumber / 8);
    *Value = (UCHAR)((UCHAR)1 << (BitNumber % 8));
}

NDIS_STATUS
HwSetMulticastMask(
    IN  PNIC       pNic,
    IN  BOOLEAN    bAcceptAll
    )
{
    UINT     i;
    UCHAR    Byte;
    UCHAR    Bit;
    ULONG    MultiCast_03;
    ULONG    MultiCast_47;
    ULONG    AddressCount = pNic->RxInfo.MCAddressCount;
    UCHAR    ExceptMAddress[6] = {0x01, 0x40, 0x96, 0x00, 0x00, 0x00};

    if (bAcceptAll)
    {
        WritePortUlong( pNic, MAR0, 0xffffffff );
        WritePortUlong( pNic, MAR4, 0xffffffff );
    }
    else {
        //
        // Clear all bits
        //
        NdisZeroMemory(pNic->RxInfo.MCRegValues, 8);

        //
        // Now turn on the bit for each address in the multicast list.
        //
        for (i = 0; (i < AddressCount) && (i < HW11_MAX_MCAST_LIST_SIZE); i++) 
        {
            HwGetMulticastBit(pNic->RxInfo.MCAddressList[i], &Byte, &Bit);
            pNic->RxInfo.MCRegValues[Byte] |= Bit;
        }

        //
        // Turn Except Multicast Address
        //
        HwGetMulticastBit(ExceptMAddress, &Byte, &Bit);    // For Cisco to get IP address
        pNic->RxInfo.MCRegValues[Byte] |= Bit;
        
        //
        // Write Multicast bits to register
        //
        MultiCast_03 = 0;
        MultiCast_47 = 0;

        for (i = 0; i < 4; i++)
            MultiCast_03 = MultiCast_03 + ((pNic->RxInfo.MCRegValues[i])<<(8*i));

        for (; i<8; i++)
            MultiCast_47 = MultiCast_47 + ((pNic->RxInfo.MCRegValues[i])<<(8*(i-4)));

        WritePortUlong(pNic, MAR0, MultiCast_03);
        WritePortUlong(pNic, MAR4, MultiCast_47);
    }

    return NDIS_STATUS_SUCCESS;
}

// Can be called at device IRQL
VOID
HwDoze(
    IN  PNIC     pNic,
    IN  ULONG    ulDozeTime,
	IN  BOOLEAN  bDeviceIRQL       // in micro-second
    )
{
    LARGE_INTEGER   CurrentTime;
    ULONGLONG       TimeDifference;

    if(pNic->ManagementInfo.bScanInProgress)
    {
		return;
    }
    
    //
    // Shorten the doze time by 15ms. This accommodates the radio switch on
    // time and kernel DPC timer inaccuracy.
    //
    ulDozeTime = ulDozeTime / 1000;    // in ms
    if (ulDozeTime > 20)
        ulDozeTime -= 15;
    else
        return;
                
    //
    // Check if we can NOT sleep (due to uDelaySleepValue)
    //
    if (pNic->ManagementInfo.DelaySleepValue > 0) 
    {
        NdisGetCurrentSystemTime(&CurrentTime);

        //
        // TimeDifference is in micro-second.
        //
        TimeDifference = (CurrentTime.QuadPart - pNic->ManagementInfo.DelaySleepTimeStamp.QuadPart) / 10;
        if (TimeDifference > pNic->ManagementInfo.DelaySleepValue)
            pNic->ManagementInfo.DelaySleepValue = 0;
        else
            return;
    }

    if (pNic->ManagementInfo.bPowerMgmtChangePktSent)
    {        
        //
        // Make sure a NULL packet with power management set is sent out
        //
        if (pNic->RfInfo.RFPowerState == RF_ON)
        {            
            //
            // Make sure we are not already in PS mode
            //
            if (!pNic->ManagementInfo.bScanInProgress && HwGetTxBusyDescNum(pNic, LOW_QUEUE) == 0) 
            {
                if (bDeviceIRQL)
                {
                    // We will wake up on ATIM interval
                    
                    if (pNic->ManagementInfo.PowerMgmtMode.uPowerSaveLevel == DOT11_POWER_SAVE_LEVEL_FAST_PSP)
                        SetRFPowerState(pNic, RF_SLEEP);
                    else if(pNic->ManagementInfo.PowerMgmtMode.uPowerSaveLevel == DOT11_POWER_SAVE_LEVEL_MAX_PSP)
                        SetRFPowerState(pNic, RF_OFF);
                }
                else
                {
                    NdisMSetTimer(&pNic->ManagementInfo.Timer_Awake, ulDozeTime);
                
                    MpTrace(COMP_POWER, DBG_LOUD, (" *** RF OFF for %dms\n", ulDozeTime));

                    if (pNic->ManagementInfo.PowerMgmtMode.uPowerSaveLevel == DOT11_POWER_SAVE_LEVEL_FAST_PSP)
                        HwSetRFState(pNic, RF_SLEEP);
                    else if(pNic->ManagementInfo.PowerMgmtMode.uPowerSaveLevel == DOT11_POWER_SAVE_LEVEL_MAX_PSP)
                    {
            			//todo Find a right way to make this chip turn off quickly
            			if(pNic->RfInfo.RFChipID==10)
            				HwSetRFState(pNic, RF_SLEEP);
            			else
            				HwSetRFState(pNic, RF_OFF);
                    }
                }
            }
        }
    }
}

// Called at PASSIVE or DISPATCH
BOOLEAN
HwSetRFOn(
	IN PNIC		pNic,
	IN UCHAR    MaxRetries
	)
{
    UCHAR   RetryCount = 0;
	
    //
    // This is at dispatch, dont spin for long
    //
    while (RetryCount < MaxRetries)
    {
        if (HwSetRFState(pNic, RF_ON) == FALSE)
        {
            // If radio is OFF, hw awake can fail. It can also fail
            // if something else is changing radio state, in which case, we try
            // try again
            if (pNic->RfInfo.RadioOff == TRUE)
            {
                // Failed because radio was OFF
                break;
            }
            else
            {
                //
                // Something else is toggling RF state
                //
                NdisStallExecution(10); // Stall for 10 microseconds
            }
        }
        else
        {
            // Hw awake OK
            return TRUE;
        }
        RetryCount++;
    }

    return FALSE;
}

BOOLEAN
HwAwake(
	IN PNIC		pNic,
	IN BOOLEAN  bDeviceIRQL
	)
{
    BOOLEAN        Canceled;
    
    if (pNic->RfInfo.RFPowerState != RF_ON) 
    {
        MpTrace(COMP_POWER, DBG_LOUD, (" *** RF ON\n"));

        if (!bDeviceIRQL)
        {
            //
            // Try to cancel timer in case we are not called by timer this time
            //
            NdisMCancelTimer(&pNic->ManagementInfo.Timer_Awake, &Canceled);

            // Enable RF and retry 3 times if something else is using it
            return HwSetRFOn(pNic, 3);
        }
        else
        {
            return HwSetRFState(pNic, RF_ON);
        }
    }
    
    return TRUE;
}

void
HwAwakeCallback(
    IN  PVOID SystemSpecific1,
    IN  PVOID param,
    IN  PVOID SystemSpecific2,
    IN  PVOID SystemSpecific3)
{
    PNIC pNic = (PNIC)param;

    UNREFERENCED_PARAMETER(SystemSpecific1);
    UNREFERENCED_PARAMETER(SystemSpecific2);
    UNREFERENCED_PARAMETER(SystemSpecific3);

    // If radio is OFF, the callback wont turn on the radio
    HwAwake(pNic, FALSE);
}

void
HwSetBSSIDAndBcnIntv(
    IN  PNIC pNic
    )
{
    WritePortUshort(pNic, BSSIDR, *((PUSHORT)(pNic->ManagementInfo.BssId)));
    WritePortUlong(pNic, BSSIDR + 2, *((PULONG)(pNic->ManagementInfo.BssId + 2)));
    WritePortUshort(pNic, BcnIntv, pNic->DupCurrentInfo.BeaconInterval);
}

void
HwRemoveKeyEntry(
    IN PNIC pNic,
    IN UCHAR index)
{
    ULONG   dkreg[4] = {DK0, DK1, DK2, DK3};

    if (pNic->CardInfo.HardwareID == HW_ID_8185)
    {
        CamDeleteOneEntry(pNic, index);
    }
    else if (index < DOT11_MAX_NUM_DEFAULT_KEY)
    {
        WritePortUlong(pNic, dkreg[index], 0);
        WritePortUlong(pNic, dkreg[index] + 4, 0);
        WritePortUlong(pNic, dkreg[index] + 8, 0);
        WritePortUlong(pNic, dkreg[index] + 12, 0);
    }

    if (index >= DOT11_MAX_NUM_DEFAULT_KEY && pNic->ManagementInfo.KeyMappingKeyCount > 0)
    {
        pNic->ManagementInfo.KeyMappingKeyCount--;
    }
}

void
HwAddKeyEntry(
    IN PNIC pNic,
    IN PNICKEY pNicKey,
    IN UCHAR index)
{
    ULONG   dkreg[4] = {DK0, DK1, DK2, DK3};

    ASSERT(pNicKey->Valid);

    if (pNic->CardInfo.HardwareID == HW_ID_8185)
    {   
        CamAddOneEntry(pNic, pNicKey, index);
    }
    else if (index < DOT11_MAX_NUM_DEFAULT_KEY)
    {
        WritePortUlong(pNic, dkreg[index], *((PULONG)pNicKey->KeyValue));
        WritePortUlong(pNic, dkreg[index] + 4, *((PULONG)(pNicKey->KeyValue + 4)));
        WritePortUlong(pNic, dkreg[index] + 8, *((PULONG)(pNicKey->KeyValue + 8)));
        WritePortUlong(pNic, dkreg[index] + 12, *((PULONG)(pNicKey->KeyValue + 12)));
    }

    if (index >= DOT11_MAX_NUM_DEFAULT_KEY)
    {
        pNic->ManagementInfo.KeyMappingKeyCount++;
        ASSERT(pNic->ManagementInfo.KeyMappingKeyCount <= KEY_MAPPING_KEY_TABLE_SIZE);
    }
}


void
HwUpdateKeyEntry(
    IN PNIC pNic,
    IN PNICKEY pNicKey,
    IN UCHAR index)
{
    ULONG   dkreg[4] = {DK0, DK1, DK2, DK3};

    ASSERT(pNicKey->Valid);

    if (pNic->CardInfo.HardwareID == HW_ID_8185)
    {   
        CamAddOneEntry(pNic, pNicKey, index);
    }
    else if (index < DOT11_MAX_NUM_DEFAULT_KEY)
    {
        WritePortUlong(pNic, dkreg[index], *((PULONG)pNicKey->KeyValue));
        WritePortUlong(pNic, dkreg[index] + 4, *((PULONG)(pNicKey->KeyValue + 4)));
        WritePortUlong(pNic, dkreg[index] + 8, *((PULONG)(pNicKey->KeyValue + 8)));
        WritePortUlong(pNic, dkreg[index] + 12, *((PULONG)(pNicKey->KeyValue + 12)));
    }

    ASSERT(pNic->ManagementInfo.KeyMappingKeyCount <= KEY_MAPPING_KEY_TABLE_SIZE);
}


void
Hw11DeleteNonPersistentKey(
    IN  PNIC pNic
    )
{
    PNICKEY             pNicKey;
    UCHAR               index;
    UCHAR               index2;
    PNIC_PER_STA_KEY    pPerStaKey;
    BOOLEAN             noValidKeys;

    //
    // Go through the key table, invalidate any key which is not persistent. 
    //
    pNicKey = pNic->ManagementInfo.KeyTable;
    for (index = 0; index < KEY_TABLE_SIZE; index++, pNicKey++)
    {
        if (pNicKey->Valid && !pNicKey->Persistent)
        {
            NdisZeroMemory(pNicKey, sizeof(NICKEY));
            HwRemoveKeyEntry(pNic, index);
        }
    }

    //
    // Invalidate any per-STA key which is not persistent. 
    //
    pPerStaKey = pNic->ManagementInfo.PerStaKey;
    for (index = 0; index < PER_STA_KEY_TABLE_SIZE; index++, pPerStaKey++)
    {
        if (pPerStaKey->Valid)
        {
            noValidKeys = TRUE;
            pNicKey = pPerStaKey->NicKey;
            for (index2 = 0; index2 < DOT11_MAX_NUM_DEFAULT_KEY; index2++, pNicKey++)
            {
                if (pNicKey->Valid)
                {
                    if (!pNicKey->Persistent)
                    {
                        NdisZeroMemory(pNicKey, sizeof(NICKEY));
                    }
                    else
                    {
                        noValidKeys = FALSE;
                    }
                }
            }
            
            if (noValidKeys)
            {
                pPerStaKey->Valid = FALSE;
                ASSERT(pNic->ManagementInfo.PerStaKeyCount > 0);
                pNic->ManagementInfo.PerStaKeyCount--;
            }
        }
    }
}

void
Hw11DeleteNonPersistentMappingKey(
    IN  PNIC pNic,
    IN  DOT11_MAC_ADDRESS MacAddr
    )
{
    PNICKEY             pNicKey;
    UCHAR               index;
    UCHAR               index2;
    PNIC_PER_STA_KEY    pPerStaKey;
    BOOLEAN             noValidKeys;

    //
    // Go through the key mapping key table, invalidate any matching key which is not persistent. 
    //
    pNicKey = pNic->ManagementInfo.KeyTable;
    for (index = DOT11_MAX_NUM_DEFAULT_KEY; index < KEY_TABLE_SIZE; index++, pNicKey++)
    {
        if (pNicKey->Valid && 
            !pNicKey->Persistent && 
            NdisEqualMemory(pNicKey->MacAddr, MacAddr, sizeof(DOT11_MAC_ADDRESS)) == 1)
        {
            NdisZeroMemory(pNicKey, sizeof(NICKEY));
            HwRemoveKeyEntry(pNic, index);
        }
    }

    //
    // Invalidate any matching per-STA key which is not persistent. 
    //
    pPerStaKey = pNic->ManagementInfo.PerStaKey;
    for (index = 0; index < PER_STA_KEY_TABLE_SIZE; index++, pPerStaKey++)
    {
        if (pPerStaKey->Valid &&
            NdisEqualMemory(pPerStaKey->StaMacAddr, MacAddr, sizeof(DOT11_MAC_ADDRESS)) == 1)
        {
            noValidKeys = TRUE;
            pNicKey = pPerStaKey->NicKey;
            for (index2 = 0; index2 < DOT11_MAX_NUM_DEFAULT_KEY; index2++, pNicKey++)
            {
                if (pNicKey->Valid)
                {
                    if (!pNicKey->Persistent)
                    {
                        NdisZeroMemory(pNicKey, sizeof(NICKEY));
                    }
                    else
                    {
                        noValidKeys = FALSE;
                    }
                }
            }
            
            if (noValidKeys)
            {
                pPerStaKey->Valid = FALSE;
                ASSERT(pNic->ManagementInfo.PerStaKeyCount > 0);
                pNic->ManagementInfo.PerStaKeyCount--;
            }
        }
    }
}

void
HwDeleteAllKeys(
    IN  PNIC pNic
    )
{
    PNICKEY     pNicKey;
    UCHAR       index;

    //
    // Clear key table and hardware key setting.
    //
    pNicKey = pNic->ManagementInfo.KeyTable;
    for (index = 0; index < KEY_TABLE_SIZE; index++, pNicKey++)
    {
        NdisZeroMemory(pNicKey, sizeof(NICKEY));
        HwRemoveKeyEntry(pNic, index);
    }

    pNic->ManagementInfo.KeyMappingKeyCount = 0;

    //
    // Clear per-Sta key table.
    //
    for (index = 0; index < PER_STA_KEY_TABLE_SIZE; index++)
    {
        NdisZeroMemory(pNic->ManagementInfo.PerStaKey + index, sizeof(NIC_PER_STA_KEY));
    }

    pNic->ManagementInfo.PerStaKeyCount = 0;
}

void 
Hw11SetDefaultKeyID(
    IN  PNIC pNic,
    IN  ULONG keyID
    )
{
    ASSERT(keyID < DOT11_MAX_NUM_DEFAULT_KEY);
    pNic->ManagementInfo.DefaultKeyID = (UCHAR)keyID;
}

ULONG
Hw11GetDefaultKeyID(
    IN  PNIC pNic
    )
{
    return pNic->ManagementInfo.DefaultKeyID;
}

BOOLEAN
Hw11WEP104Implemented(
    IN  PNIC pNic
    )
{
    UNREFERENCED_PARAMETER(pNic);
    return TRUE;
}

BOOLEAN
Hw11WEP40Implemented(
    IN  PNIC pNic
    )
{
    UNREFERENCED_PARAMETER(pNic);
    return TRUE;
}

BOOLEAN
Hw11TKIPImplemented(
    IN  PNIC pNic
    )
{
    return (BOOLEAN)(pNic->CardInfo.HardwareID == HW_ID_8185);
}

BOOLEAN
Hw11CCMPImplemented(
    IN  PNIC pNic
    )
{
    return (BOOLEAN)(pNic->CardInfo.HardwareID == HW_ID_8185);
}

USHORT
Hw11GetRSNCapability(
    IN  PNIC pNic
    )
{
    UNREFERENCED_PARAMETER(pNic);
    return 0;
}

void
Hw11SetAuthentication(
    IN  PNIC pNic,
    IN  DOT11_AUTH_ALGORITHM  algoId
    )
{
    pNic->ManagementInfo.HwAuthAlgorithm = algoId;
}

void
Hw11SetCurrentBSSType(
    IN  PNIC pNic,
    IN  DOT11_BSS_TYPE  type
    )
{
    pNic->ManagementInfo.CurrentBSSType = type;
}

NDIS_STATUS
Hw11SetSafeModeOption(
    IN  PNIC            pNic,
    IN  BOOLEAN         safeModeEnabled
    )
{
    if (safeModeEnabled)
    {
        //
        // We would program the hardware to not do any encryption (both unicast and multicast ciphers)
        //
        Hw11SetEncryption(pNic, TRUE, DOT11_CIPHER_ALGO_NONE);
        Hw11SetEncryption(pNic, FALSE, DOT11_CIPHER_ALGO_NONE);
    }
    else
    {
        // Cipher would have already been set when safe mode is configured
        // (enabled or disabled)
#if 0        
        //
        // The hardware would be programmed when the OS sets the ciphers
        //
        MPVERIFY(pNic->ManagementInfo.HwUnicastCipher == DOT11_CIPHER_ALGO_NONE);
#endif
    }

    pNic->ManagementInfo.SafeModeEnabled = safeModeEnabled;
    
    return NDIS_STATUS_SUCCESS;
}

BOOLEAN
Hw11GetSafeModeOption(
    IN  PNIC            pNic 
    )
{
    return pNic->ManagementInfo.SafeModeEnabled;
}

void
Hw11SetEncryption(
    IN  PNIC pNic,
    IN  BOOLEAN isUnicast,
    IN  DOT11_CIPHER_ALGORITHM  algoId
    )
{
    BOOLEAN useDefaultKey;

    MpTrace(COMP_OID, DBG_LOUD, ("Hw11SetEncrytion: %s %d\n", isUnicast ? "Unicast" : "Multicast", algoId));

    /*** Valid combinations of multicast/unicast cipher algorithms

    Multicast\Unicast       WEP      WEP40      WEP104      TKIP     CCMP      NONE
        WEP                  Y
        WEP40                          Y*                     Y        Y
        WEP104                                    Y*          Y        Y
        TKIP                                                  Y        Y
        CCMP                                                           Y
        NONE                                                                    Y
 
      Y*: Not currently used by Microsoft 802.11 Security module but can be supported by vendors 
          if they want to connect to WPA AP that does not support pairwise keys.

    ***/

    //
    // Update the encryption algorithm. When set unicast cipher, also clear all keys. 
    //
    if (isUnicast)
    {
        HwDeleteAllKeys(pNic);
        pNic->ManagementInfo.HwUnicastCipher = algoId;

        //
        // Program the hardware
        //
        if (pNic->ManagementInfo.SafeModeEnabled == FALSE)
        {
            if (pNic->CardInfo.HardwareID == HW_ID_8185)
            {
                //
                // Don't use default key for WPA2PSK in adhoc mode.
                //
                useDefaultKey = (BOOLEAN)(!(pNic->ManagementInfo.CurrentBSSType == dot11_BSS_type_independent &&
                                            pNic->ManagementInfo.HwAuthAlgorithm == DOT11_AUTH_ALGO_RSNA_PSK));
                CamSetEncryption(pNic, algoId, useDefaultKey);
            }
            else
            {
                switch (algoId) 
                {
                    case DOT11_CIPHER_ALGO_NONE:
                        WritePortUchar(pNic, SCR, 0);
                        break;

                    case DOT11_CIPHER_ALGO_WEP40:
                        WritePortUchar(pNic, SCR, SCR_RxSecOn | SCR_TxSecOn | SCR_WEP40);
                        break;

                    case DOT11_CIPHER_ALGO_WEP104:
                        WritePortUchar(pNic, SCR, SCR_RxSecOn | SCR_TxSecOn | SCR_WEP104);
                        break;

                    case DOT11_CIPHER_ALGO_WEP:
                        //
                        // Will program it when we get actual key.
                        //
                        break;

                    default:
                        ASSERT(0);
                }
            }
        }
    }
    else
    {
        pNic->ManagementInfo.HwMulticastCipher = algoId;
    }
}

NDIS_STATUS
HwSetKey(
    IN  PNIC pNic,
    IN  PNICKEY pNicKey,
    IN  UCHAR keyIndex,
    IN  BOOLEAN perStaKey,
    IN  BOOLEAN persistent,
    IN  DOT11_CIPHER_ALGORITHM algoId,
    IN  ULONG keyLength,
    IN  PUCHAR keyValue
    )
{
    ULONG                       i;
    PDOT11_KEY_ALGO_CCMP        CCMPKey = NULL;
    PDOT11_KEY_ALGO_TKIP_MIC    TKIPKey = NULL;
    BOOLEAN                     isKeyUpdate = FALSE;

    MPVERIFY(pNic->ManagementInfo.SafeModeEnabled == FALSE);

    //
    // If keyLength is non-zero, the key is to be added, otherwise, it is to be deleted.
    // Note: MacAddr of the key is already set.
    //    
    if (keyLength != 0)
    {
        //
        // If the algoId is generic WEP, change it to WEP40 or WEP104 depending on the key length.
        //

        switch (algoId)
        {
            case DOT11_CIPHER_ALGO_WEP:
                switch (keyLength)
                {
                    case 40 / 8:
                        algoId = DOT11_CIPHER_ALGO_WEP40;
                        break;

                    case 104 / 8:
                        algoId = DOT11_CIPHER_ALGO_WEP104;
                        break;

                    default:
                        return NDIS_STATUS_INVALID_DATA;
                }

                // fall through

            case DOT11_CIPHER_ALGO_WEP104:
            case DOT11_CIPHER_ALGO_WEP40:
                break;

            case DOT11_CIPHER_ALGO_CCMP:
                //
                // Validate the key length
                //
                if (keyLength < FIELD_OFFSET(DOT11_KEY_ALGO_CCMP, ucCCMPKey)) 
                {
                    return NDIS_STATUS_INVALID_DATA;
                }
                
                CCMPKey = (PDOT11_KEY_ALGO_CCMP)keyValue;
                if (keyLength < FIELD_OFFSET(DOT11_KEY_ALGO_CCMP, ucCCMPKey) + 
                                CCMPKey->ulCCMPKeyLength)
                {
                    return NDIS_STATUS_INVALID_DATA;
                }

                //
                // Only support 16-byte CCMP key 
                //
                if (CCMPKey->ulCCMPKeyLength != 16)
                {
                    return NDIS_STATUS_INVALID_DATA;
                }
                
                keyLength = CCMPKey->ulCCMPKeyLength;
                keyValue = CCMPKey->ucCCMPKey;
                
                break;

            case DOT11_CIPHER_ALGO_TKIP:
                //
                // Validate the key length
                //
                if (keyLength < FIELD_OFFSET(DOT11_KEY_ALGO_TKIP_MIC, ucTKIPMICKeys)) 
                {
                    return NDIS_STATUS_INVALID_DATA;
                }
                
                TKIPKey = (PDOT11_KEY_ALGO_TKIP_MIC)keyValue;
                if (keyLength < FIELD_OFFSET(DOT11_KEY_ALGO_TKIP_MIC, ucTKIPMICKeys) + 
                                TKIPKey->ulTKIPKeyLength +
                                TKIPKey->ulMICKeyLength) 
                {
                    return NDIS_STATUS_INVALID_DATA;
                }
                
                //
                // Only support 16-byte TKIP key and 8-byte Tx/Rx MIC key
                //
                if (TKIPKey->ulTKIPKeyLength != 16 || TKIPKey->ulMICKeyLength != 16)
                {
                    return NDIS_STATUS_INVALID_DATA;
                }

                keyLength = TKIPKey->ulTKIPKeyLength;
                keyValue = TKIPKey->ucTKIPMICKeys;
                
                break;
        }

        //
        // If the current encryption algorithm is WEP, change it to more specific WEP40 or WEP104.
        //

        if (pNic->ManagementInfo.HwUnicastCipher == DOT11_CIPHER_ALGO_WEP &&
            (algoId == DOT11_CIPHER_ALGO_WEP40 || algoId == DOT11_CIPHER_ALGO_WEP104))
        {
            pNic->ManagementInfo.HwUnicastCipher = algoId;

            //
            // For RTL8180, also program the hardware
            //

            if (pNic->CardInfo.HardwareID == HW_ID_8180)
            {
                ASSERT(!perStaKey);
                WritePortUchar(pNic, 
                               SCR, 
                               SCR_RxSecOn | SCR_TxSecOn | (algoId == DOT11_CIPHER_ALGO_WEP40 ? SCR_WEP40 : SCR_WEP104));
            }
        }

        if (pNic->ManagementInfo.HwMulticastCipher == DOT11_CIPHER_ALGO_WEP &&
            (algoId == DOT11_CIPHER_ALGO_WEP40 || algoId == DOT11_CIPHER_ALGO_WEP104))
        {
            pNic->ManagementInfo.HwMulticastCipher = algoId;
        }

        //
        // We should never have unicast and multicast cipher with different length of WEP.
        // See comment in function Hw11SetEncryption().
        //
        ASSERT(!(pNic->ManagementInfo.HwUnicastCipher == DOT11_CIPHER_ALGO_WEP40 && 
                 pNic->ManagementInfo.HwMulticastCipher == DOT11_CIPHER_ALGO_WEP104));

        ASSERT(!(pNic->ManagementInfo.HwUnicastCipher == DOT11_CIPHER_ALGO_WEP104 && 
                 pNic->ManagementInfo.HwMulticastCipher == DOT11_CIPHER_ALGO_WEP40));

        //
        // For key mapping key, its algorithm must match current unicast cipher (unless 
        // the key is for multicast/broadcast data frames).
        //
        // For per-STA key, or key mapping key for multicast/broadcast data frames, 
        // its algorithm must match the current unicast cipher.
        //
        // For default key, its algorithm must match either the current unicast cipher
        // or the current multicast cipher. 
        //
        if (pNic->ManagementInfo.HwUnicastCipher != algoId && 
            keyIndex >= DOT11_MAX_NUM_DEFAULT_KEY && 
            ETH_IS_UNICAST(pNicKey->MacAddr))
        {
            return NDIS_STATUS_INVALID_DATA;
        }

        if (pNic->ManagementInfo.HwMulticastCipher != algoId && 
            (perStaKey || ETH_IS_MULTICAST(pNicKey->MacAddr)))
        {
            return NDIS_STATUS_INVALID_DATA;
        }

        if (pNic->ManagementInfo.HwUnicastCipher != algoId && 
            pNic->ManagementInfo.HwMulticastCipher != algoId)
        {
            return NDIS_STATUS_INVALID_DATA;
        }

        // Was the old key valid, or is this a new entry
        isKeyUpdate = pNicKey->Valid;
        
        //
        // Update the key entry for valid key. We cannot fail after this point. Otherwise, 
        // the existing key will be modified when we fail to set the new key.
        //

        pNicKey->Valid = TRUE;
        pNicKey->Persistent = persistent;
        pNicKey->KeyLength = (UCHAR) keyLength;
        pNicKey->AlgoId = algoId;

#if DBG
        if (keyIndex < DOT11_MAX_NUM_DEFAULT_KEY)
        {
            MpTrace(COMP_OID, DBG_NORMAL, ("Update %s key %d (algo %d): ", 
                    perStaKey ? "per-STA" : "default", keyIndex, algoId));
        }
        else
        {
            MpTrace(COMP_OID, DBG_NORMAL, ("Update key mapping key for %02X-%02X-%02X-%02X-%02X-%02X (algo %d): ", 
                    pNicKey->MacAddr[0], pNicKey->MacAddr[1], pNicKey->MacAddr[2], 
                    pNicKey->MacAddr[3], pNicKey->MacAddr[4], pNicKey->MacAddr[5], algoId));
        }
#endif

        for (i = 0; i < keyLength; i++) 
        {
            pNicKey->KeyValue[i] = keyValue[i];
            MpTrace(COMP_OID, DBG_NORMAL, ("%02X", keyValue[i]));
        }
        MpTrace(COMP_OID, DBG_NORMAL, ("\n"));

        for (i = keyLength; i < sizeof(pNicKey->KeyValue); i++) 
            pNicKey->KeyValue[i] = 0;

        switch (algoId)
        {
            case DOT11_CIPHER_ALGO_WEP:
            case DOT11_CIPHER_ALGO_WEP104:
            case DOT11_CIPHER_ALGO_WEP40:
                pNicKey->IV = 1;
                break;

            case DOT11_CIPHER_ALGO_CCMP:
                pNicKey->PN = 1;
                pNicKey->ReplayCounter = ((ULONGLONG)CCMPKey->ucIV48Counter[0]) |
                                         (((ULONGLONG)CCMPKey->ucIV48Counter[1]) << 8) |
                                         (((ULONGLONG)CCMPKey->ucIV48Counter[2]) << 16) |
                                         (((ULONGLONG)CCMPKey->ucIV48Counter[3]) << 24) |
                                         (((ULONGLONG)CCMPKey->ucIV48Counter[4]) << 32) |
                                         (((ULONGLONG)CCMPKey->ucIV48Counter[5]) << 40);
                break;

            case DOT11_CIPHER_ALGO_TKIP:
                pNicKey->TSC = 1;

                pNicKey->ReplayCounter = ((ULONGLONG)TKIPKey->ucIV48Counter[0]) |
                                         (((ULONGLONG)TKIPKey->ucIV48Counter[1]) << 8) |
                                         (((ULONGLONG)TKIPKey->ucIV48Counter[2]) << 16) |
                                         (((ULONGLONG)TKIPKey->ucIV48Counter[3]) << 24) |
                                         (((ULONGLONG)TKIPKey->ucIV48Counter[4]) << 32) |
                                         (((ULONGLONG)TKIPKey->ucIV48Counter[5]) << 40);
                NdisMoveMemory(pNicKey->RxMICKey, Add2Ptr(keyValue, keyLength), 8);
                NdisMoveMemory(pNicKey->TxMICKey, Add2Ptr(keyValue, keyLength + 8), 8);
                break;
        }

        //
        // Program the hardware.
        //
        if (!perStaKey)
        {
            if (isKeyUpdate)
            {
                HwUpdateKeyEntry(pNic, pNicKey, keyIndex);
            }
            else
            {
                HwAddKeyEntry(pNic, pNicKey, keyIndex);
            }
        }
    }
    else 
    {
        //
        // Remove the key from hardware.
        //
        NdisZeroMemory(pNicKey, sizeof(NICKEY));
        if (!perStaKey)
        {
            HwRemoveKeyEntry(pNic, keyIndex);
        }
    }

    return NDIS_STATUS_SUCCESS;
}

NDIS_STATUS 
HwSetPerStaDefaultKey(
    IN  PNIC pNic,
    IN  DOT11_MAC_ADDRESS MacAddr,
    IN  ULONG keyID,
    IN  BOOLEAN persistent,
    IN  DOT11_CIPHER_ALGORITHM algoId,
    IN  ULONG keyLength,
    IN  PUCHAR keyValue
    )
{
    PNIC_PER_STA_KEY    pPerStaKey;
    ULONG               index;
    ULONG               emptyIndex;
    NDIS_STATUS         ndisStatus;

    //
    // per-STA default key is only supported by RTL8185. Actually even RTL8185
    // doesn't support it in hardware, but we support WPA2PSK for adhoc on RTL8185, 
    // so we just have to support per-STA default key in software.
    //
    ASSERT(pNic->CardInfo.HardwareID == HW_ID_8185);
    ASSERT(pNic->ManagementInfo.HwAuthAlgorithm == DOT11_AUTH_ALGO_RSNA_PSK);
    if (pNic->CardInfo.HardwareID != HW_ID_8185 ||
        pNic->ManagementInfo.HwAuthAlgorithm != DOT11_AUTH_ALGO_RSNA_PSK)
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }

    //
    // Search the per-STA key table to find either a matching MacAddr or an empty key entry.
    //
    emptyIndex = PER_STA_KEY_TABLE_SIZE;
    pPerStaKey = pNic->ManagementInfo.PerStaKey;
    for (index = 0; index < PER_STA_KEY_TABLE_SIZE; index++, pPerStaKey++)
    {
        if (pPerStaKey->Valid && NdisEqualMemory(pPerStaKey->StaMacAddr, MacAddr, sizeof(DOT11_MAC_ADDRESS)) == 1)
        {
            break;
        }

        if (!pPerStaKey->Valid && emptyIndex == PER_STA_KEY_TABLE_SIZE)
        {
            emptyIndex = index;
        }
    }

    if (index == PER_STA_KEY_TABLE_SIZE)
    {
        //
        // We did not find a per-STA key with matching MacAddr. 
        //

        if (keyLength == 0)
        {
            //
            // If we are asked to delete a per-STA key, fail the request.
            //
            return NDIS_STATUS_INVALID_DATA;
        }
        else if (emptyIndex == PER_STA_KEY_TABLE_SIZE)
        {
            //
            // If we are asked to add a key but the table is full, fail the request.
            //
            return NDIS_STATUS_RESOURCES;
        }

        pPerStaKey = pNic->ManagementInfo.PerStaKey + emptyIndex;
        ETH_COPY_NETWORK_ADDRESS(pPerStaKey->StaMacAddr, MacAddr);
    }

    //
    // Set the key in NicKey structure.
    //
    ndisStatus = HwSetKey(pNic, 
                          pPerStaKey->NicKey + keyID, 
                          (UCHAR)keyID, 
                          TRUE,
                          persistent, 
                          algoId, 
                          keyLength, 
                          keyValue);

    //
    // If key is set successfully, update the "Valid" flag of the per-Sta key.
    //
    if (ndisStatus == NDIS_STATUS_SUCCESS) 
    {
        if (keyLength != 0)
        {
            if (!pPerStaKey->Valid)
            {
                pPerStaKey->Valid = TRUE;
                ASSERT(pNic->ManagementInfo.PerStaKeyCount < PER_STA_KEY_TABLE_SIZE);
                pNic->ManagementInfo.PerStaKeyCount++;
            }
        }
        else 
        {
            ASSERT(pPerStaKey->Valid);
            for (index = 0; index < DOT11_MAX_NUM_DEFAULT_KEY; index++)
            {
                if (pPerStaKey->NicKey[index].Valid)
                    break;
            }

            if (index == DOT11_MAX_NUM_DEFAULT_KEY)
            {
                pPerStaKey->Valid = FALSE;
                ASSERT(pNic->ManagementInfo.PerStaKeyCount > 0);
                pNic->ManagementInfo.PerStaKeyCount--;
            }
        }
    }

    return ndisStatus;
}

NDIS_STATUS 
Hw11SetDefaultKey(
    IN  PNIC pNic,
    IN  DOT11_MAC_ADDRESS MacAddr,
    IN  ULONG keyID,
    IN  BOOLEAN persistent,
    IN  DOT11_CIPHER_ALGORITHM algoId,
    IN  ULONG keyLength,
    IN  PUCHAR keyValue
    )
{
    //
    // Note that both this function and other functions accessing key table are called
    // as a result of OID set. As such, no locking is needed since NDIS serializes
    // the OID set operation. If this premise is no longer valid, locking will
    // be needed.
    //

    ASSERT(keyID < DOT11_MAX_NUM_DEFAULT_KEY);
    if (keyID >= DOT11_MAX_NUM_DEFAULT_KEY)
        return NDIS_STATUS_INVALID_DATA;

    if (pNic->ManagementInfo.CurrentBSSType == dot11_BSS_type_independent && (MacAddr[0] != 0 || 
                                                                              MacAddr[1] != 0 || 
                                                                              MacAddr[2] != 0 || 
                                                                              MacAddr[3] != 0 ||
                                                                              MacAddr[4] != 0 ||
                                                                              MacAddr[5] != 0))
    {
        //
        // Handle the per-STA default key.
        //
        ASSERT(ETH_IS_UNICAST(MacAddr));
        return HwSetPerStaDefaultKey(pNic,
                                     MacAddr,
                                     keyID,
                                     persistent,
                                     algoId,
                                     keyLength,
                                     keyValue);
    }
    else
    {
        //
        // Save the new default key in the key table. 
        //
        return HwSetKey(pNic, 
                        pNic->ManagementInfo.KeyTable + keyID,
                        (UCHAR)keyID, 
                        FALSE,
                        persistent, 
                        algoId, 
                        keyLength, 
                        keyValue);
    }
}

NDIS_STATUS 
Hw11SetKeyMappingKey(
    IN  PNIC pNic,
    IN  DOT11_MAC_ADDRESS MacAddr,
    IN  DOT11_DIRECTION direction,
    IN  BOOLEAN persistent,
    IN  DOT11_CIPHER_ALGORITHM algoId,
    IN  ULONG keyLength,
    IN  PUCHAR keyValue
    )
{
    PNICKEY pNicKey = NULL;
    ULONG   index;
    ULONG   emptyIndex;
    
    //
    // We don't support uni-direction key mapping keys
    //
    if (direction != DOT11_DIR_BOTH)
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }

    //
    // Search the key mapping table to find either a matching MacAddr or an empty key entry.
    //
    emptyIndex = 0;
    for (index = DOT11_MAX_NUM_DEFAULT_KEY; index < KEY_TABLE_SIZE; index++)
    {
        pNicKey = pNic->ManagementInfo.KeyTable + index;
        if (pNicKey->Valid && NdisEqualMemory(pNicKey->MacAddr, MacAddr, sizeof(DOT11_MAC_ADDRESS)) == 1)
        {
            break;
        }

        if (!pNicKey->Valid && emptyIndex == 0)
        {
            emptyIndex = index;
        }
    }

    if (index == KEY_TABLE_SIZE)
    {
        //
        // We did not find a key with matching MacAddr. 
        //

        if (keyLength == 0)
        {
            //
            // If we are asked to delete a key, fail the request.
            //
            return NDIS_STATUS_INVALID_DATA;
        }
        else if (emptyIndex == 0)
        {
            //
            // If we are asked to add a key but the table is full, fail the request.
            //
            return NDIS_STATUS_RESOURCES;
        }

        pNicKey = pNic->ManagementInfo.KeyTable + emptyIndex;
        ETH_COPY_NETWORK_ADDRESS(pNicKey->MacAddr, MacAddr);
    }

    return HwSetKey(pNic, 
                    pNicKey, 
                    (UCHAR)(pNicKey - pNic->ManagementInfo.KeyTable), 
                    FALSE,
                    persistent, 
                    algoId, 
                    keyLength, 
                    keyValue);
}

void 
Hw11RestoreEncryption(
    IN  PNIC pNic
    )
{
    PNICKEY pNicKey;
    UCHAR   index;
    BOOLEAN useDefaultKey;

    if ((pNic->ManagementInfo.HwUnicastCipher != DOT11_CIPHER_ALGO_NONE) &&
        (pNic->ManagementInfo.SafeModeEnabled == FALSE))
    {
        //
        // Reset encryption mode on the hardware
        //
        if (pNic->CardInfo.HardwareID == HW_ID_8185)
        {
            //
            // Don't use default key for WPA2PSK in adhoc mode.
            //
            useDefaultKey = (BOOLEAN)(!(pNic->ManagementInfo.CurrentBSSType == dot11_BSS_type_independent &&
                                        pNic->ManagementInfo.HwAuthAlgorithm == DOT11_AUTH_ALGO_RSNA_PSK));
            CamSetEncryption(pNic, pNic->ManagementInfo.HwUnicastCipher, useDefaultKey);
        }
        else
        {
            switch (pNic->ManagementInfo.HwUnicastCipher) 
            {
                case DOT11_CIPHER_ALGO_NONE:
                    WritePortUchar(pNic, SCR, 0);
                    break;

                case DOT11_CIPHER_ALGO_WEP40:
                    WritePortUchar(pNic, SCR, SCR_RxSecOn | SCR_TxSecOn | SCR_WEP40);
                    break;

                case DOT11_CIPHER_ALGO_WEP104:
                    WritePortUchar(pNic, SCR, SCR_RxSecOn | SCR_TxSecOn | SCR_WEP104);
                    break;

                case DOT11_CIPHER_ALGO_WEP:
                    //
                    // Will program it when we get actual key.
                    //
                    break;
                    
                default:
                    ASSERT(0);
                    
            }
        }
    }
    else
    {
        // No encryption, we dont do anything
        return;
    }
    
    
    //
    // Each time we add the key, this counter will get
    // updated
    //
    pNic->ManagementInfo.KeyMappingKeyCount = 0;

    //
    // Plum all keys to hardware
    //
    for (index = 0; index < KEY_TABLE_SIZE; index++)
    {
        pNicKey = pNic->ManagementInfo.KeyTable + index;
        if (pNicKey->Valid)
        {
            //
            // Program the hardware.
            //
            HwAddKeyEntry(pNic, pNicKey, index);
        }
    }
}

PNICKEY
Hw11FindKeyMappingKey(
    IN PNIC                 pNic,
    IN DOT11_MAC_ADDRESS    MacAddr
    )
{
    PNICKEY pNicKey;
    UCHAR   index;
    UCHAR   count = pNic->ManagementInfo.KeyMappingKeyCount;

    if (count == 0)
        return NULL;

    for (index = DOT11_MAX_NUM_DEFAULT_KEY; index < KEY_TABLE_SIZE; index++)
    {
        pNicKey = pNic->ManagementInfo.KeyTable + index;
        if (pNicKey->Valid)
        {
            if (NdisEqualMemory(pNicKey->MacAddr, MacAddr, sizeof(DOT11_MAC_ADDRESS)) == 1)
            {
                return pNicKey;
            }

            count--;
            if (count == 0)
            {
                return NULL;
            }
        }
    }

    //
    // Can reach here if we dont find a key for the specific AP
    //

    return NULL;
}

PNICKEY
HwFindPerStaKey(
    IN PNIC                 pNic,
    IN DOT11_MAC_ADDRESS    MacAddr,
    IN UCHAR                keyId
    )
{
    PNIC_PER_STA_KEY    pPerStaKey;
    PNICKEY             pNicKey;
    UCHAR               index;
    UCHAR               count = pNic->ManagementInfo.PerStaKeyCount;

    ASSERT(keyId < DOT11_MAX_NUM_DEFAULT_KEY);

    if (count == 0)
        return NULL;

    for (index = 0; index < PER_STA_KEY_TABLE_SIZE; index++)
    {
        pPerStaKey = pNic->ManagementInfo.PerStaKey + index;
        if (pPerStaKey->Valid)
        {
            if (NdisEqualMemory(pPerStaKey->StaMacAddr, MacAddr, sizeof(DOT11_MAC_ADDRESS)) == 1)
            {
                pNicKey = pPerStaKey->NicKey + keyId;
                return (pNicKey->Valid ? pNicKey : NULL);
            }

            count--;
            if (count == 0)
            {
                return NULL;
            }
        }
    }

    //
    // Should not reach here.
    //

    ASSERT(0);
    return NULL;
}

BOOLEAN
HwSelectLowestMatchingRate(
    PUCHAR          APRatesIE,
    UCHAR           APRatesIELength,
    PDOT11_RATE_SET STARateSet,
    PUSHORT         SelectedRate
    )
{
    UCHAR           indexHwRates;
    UCHAR           indexAPRates;

    for (indexHwRates = 0; indexHwRates < STARateSet->uRateSetLength; indexHwRates++)
    {
        for (indexAPRates = 0; indexAPRates < APRatesIELength; indexAPRates++)
        {
            if (STARateSet->ucRateSet[indexHwRates] == (APRatesIE[indexAPRates] & 0x7f))
            {
                *SelectedRate = STARateSet->ucRateSet[indexHwRates];
                return TRUE;
            }
        }
    }

    return FALSE;
}

NDIS_STATUS
HwUpdateInfoFromBSSInformation(
    IN PNIC        pNic,
    IN PSTA_BSS_ENTRY        pBSSEntry
    )
{
    NDIS_STATUS     ndisStatus;
    DOT11_SSID      SSID;
    PUCHAR          APRatesIE;
    UCHAR           APRatesIELength;
    PDOT11_RATE_SET STARateSet;

    ndisStatus = Dot11CopySSIDFromMemoryBlob(
        pBSSEntry->pDot11InfoElemBlob,
        pBSSEntry->InfoElemBlobSize,
        &SSID
        );

    if (ndisStatus == NDIS_STATUS_SUCCESS)
    {
        NdisMoveMemory(pNic->ManagementInfo.SSID, &(SSID.ucSSID), SSID.uSSIDLength);
        pNic->ManagementInfo.SSID[SSID.uSSIDLength] = 0;

        MpTrace(COMP_OID, DBG_LOUD, ("Update Info:SSID = %s\n", (CHAR*)pNic->ManagementInfo.SSID));
    }
    else
    {
        //
        // A required IE is missing. Fail the request.
        //
        MpTrace(COMP_OID, DBG_SERIOUS, ("Failure! Mandatory SSID Info Element not found in request\n"));
        return NDIS_STATUS_INVALID_DATA;
    }


    //3 Get the BSSID
    ETH_COPY_NETWORK_ADDRESS(pNic->ManagementInfo.BssId, pBSSEntry->Dot11BSSID);
    MpTrace(COMP_OID, DBG_LOUD, ("Update Info:BSSID = %02x-%02x-%02x-%02x-%02x-%02x\n", 
        pNic->ManagementInfo.BssId[0], pNic->ManagementInfo.BssId[1], 
        pNic->ManagementInfo.BssId[2], pNic->ManagementInfo.BssId[3], 
        pNic->ManagementInfo.BssId[4], pNic->ManagementInfo.BssId[5]));

    pNic->ManagementInfo.CapInfo = pBSSEntry->Dot11Capability.usValue;
    MpTrace(COMP_OID, DBG_LOUD, ("Update Info:CapInfo = %4x\n", pNic->ManagementInfo.CapInfo));

    ASSERT(pNic->ManagementInfo.CurrentBSSType == pBSSEntry->Dot11BSSType);

    pNic->DupCurrentInfo.BeaconInterval = pBSSEntry->BeaconInterval;
    LIMIT_BEACON_PERIOD(pNic->DupCurrentInfo.BeaconInterval);
   
    //
    // Verify that ATIM window is smaller than beacon interval.
    // This kind of misconfiguration can put hardware into unpredictable state
    //
    MPVERIFY(pNic->DupCurrentInfo.BeaconInterval > pNic->ManagementInfo.AtimWindow);
    MpTrace(COMP_OID, DBG_LOUD, ("Update Info:BeaconInterval = %d\n", pNic->DupCurrentInfo.BeaconInterval));

    //
    // For management packets, pick the lowest data rate supported between the AP and us as the
    // rate for management packets
    //
    STARateSet = &pNic->ManagementInfo.PhyMIB[pBSSEntry->PhyId].BasicRateSet;       
    pNic->ManagementInfo.CurrentTXMgmtRate = pNic->ManagementInfo.CurrentBeaconRate;    // Default
    
    ndisStatus = Dot11GetInfoEle(
        pBSSEntry->pDot11InfoElemBlob,
        pBSSEntry->InfoElemBlobSize,
        DOT11_INFO_ELEMENT_ID_SUPPORTED_RATES,
        &APRatesIELength,
        &APRatesIE
        );
    if (ndisStatus == NDIS_STATUS_SUCCESS)
    {
        if (!HwSelectLowestMatchingRate(
                APRatesIE,
                APRatesIELength,
                STARateSet,
                &pNic->ManagementInfo.CurrentTXMgmtRate
                ))
        {
            //
            // Look in the extended rates set
            //
            ndisStatus = Dot11GetInfoEle(
                pBSSEntry->pDot11InfoElemBlob,
                pBSSEntry->InfoElemBlobSize,
                DOT11_INFO_ELEMENT_ID_EXTD_SUPPORTED_RATES,
                &APRatesIELength,
                &APRatesIE
                );
            if (ndisStatus == NDIS_STATUS_SUCCESS)
            {
                if (!HwSelectLowestMatchingRate(
                        APRatesIE,
                        APRatesIELength,
                        STARateSet,
                        &pNic->ManagementInfo.CurrentTXMgmtRate
                        ))
                {
                    // 
                    // Didnt find any prefered data rate, select the default
                    //
                    pNic->ManagementInfo.CurrentTXMgmtRate = pNic->ManagementInfo.CurrentBeaconRate;                    
                }
            }
        }
    }
    return NDIS_STATUS_SUCCESS;
}

NDIS_STATUS
HwUpdateInfoFromdot11BSSDescription(
    IN PNIC        pNic,
    IN PDOT11_BSS_DESCRIPTION    dot11BSSDescription
    )
{
    int i;
    ULONG ulOffset;
    UCHAR ucLength = 0;
    PUCHAR pucParam = NULL;
    NDIS_STATUS     ndisStatus;
    DOT11_SSID      SSID;

    ndisStatus = Dot11CopySSIDFromMemoryBlob(
        dot11BSSDescription->ucBuffer,
        dot11BSSDescription->uBufferLength,
        &SSID
        );

    if (ndisStatus == NDIS_STATUS_SUCCESS)
    {
        NdisMoveMemory(pNic->ManagementInfo.SSID, SSID.ucSSID, SSID.uSSIDLength);
        pNic->ManagementInfo.SSID[SSID.uSSIDLength] = 0;

        MpTrace(COMP_OID, DBG_LOUD, ("Update Info:SSID = %s\n", (CHAR*)pNic->ManagementInfo.SSID));
    }
    else
    {
        //
        // A required IE is missing. Fail the request.
        //
        MpTrace(COMP_OID, DBG_SERIOUS, ("Failure! Mandatory SSID Info Element not found in request\n"));
        return NDIS_STATUS_INVALID_DATA;
    }

    //3 Get the BSSID
    ETH_COPY_NETWORK_ADDRESS(pNic->ManagementInfo.BssId, dot11BSSDescription->dot11BSSID);
    MpTrace(COMP_OID, DBG_LOUD, ("Update Info:BSSID = %02x-%02x-%02x-%02x-%02x-%02x\n", 
        pNic->ManagementInfo.BssId[0], pNic->ManagementInfo.BssId[1], 
        pNic->ManagementInfo.BssId[2], pNic->ManagementInfo.BssId[3], 
        pNic->ManagementInfo.BssId[4], pNic->ManagementInfo.BssId[5]));
   
    //3 Update all other IEs
    for(i=EID_IbssParms+1;i<256;i++)
    {
        ulOffset=0;
        do
        {
            ndisStatus = HwGetInfoIEWithOUI(
                        dot11BSSDescription->ucBuffer,
                        dot11BSSDescription->uBufferLength,
                        (UCHAR)i,
                        &ucLength,
                        &pucParam,
                        &ulOffset
                        );
            if(ndisStatus!=NDIS_STATUS_SUCCESS)
                break;
         
            HwAddIE(pNic,(UCHAR)i,ucLength,pucParam);
        }while(i==0xdd);
    }
   
    pNic->ManagementInfo.CapInfo=dot11BSSDescription->usCapabilityInformation;
    MpTrace(COMP_OID, DBG_LOUD, ("Update Info:CapInfo = %4x\n", pNic->ManagementInfo.CapInfo));
    
    ASSERT(pNic->ManagementInfo.CurrentBSSType == dot11BSSDescription->dot11BSSType);

    pNic->DupCurrentInfo.BeaconInterval=dot11BSSDescription->usBeaconPeriod;
    LIMIT_BEACON_PERIOD(pNic->DupCurrentInfo.BeaconInterval);

    //
    // Verify that ATIM window is smaller than beacon interval.
    // This kind of misconfiguration can put hardware into unpredictable state
    //
    MPVERIFY(pNic->DupCurrentInfo.BeaconInterval > pNic->ManagementInfo.AtimWindow);
    MpTrace(COMP_OID, DBG_LOUD, ("Update Info:BeaconInterval = %d\n", pNic->DupCurrentInfo.BeaconInterval));
   
    return NDIS_STATUS_SUCCESS;
}

void
Hw11ResetFilterFunction(
    IN  PNIC pNic
    )
{
    pNic->RxInfo.ReceiveProcessingFunction = HwProcessReceiveSTAMode;
}

NDIS_STATUS
Hw11SetPowerMgmtMode(
    IN  PNIC pNic,
    IN  PDOT11_POWER_MGMT_MODE mode
    )
{
    NdisAcquireSpinLock(&pNic->ManagementInfo.PowerMgmtLock);

    if (mode->dot11PowerMode != dot11_power_mode_unknown)
    {    // ignore unknown case
        pNic->ManagementInfo.PowerMgmtMode = *mode;

        if (mode->dot11PowerMode == dot11_power_mode_active)
        {    // dot11_power_mode_active
            HwSetNicPSMode(pNic, FALSE);
        }
        else if (mode->dot11PowerMode == dot11_power_mode_powersave)
        {    // dot11_power_mode_powersave
            HwSetNicPSMode(pNic, TRUE);
        }

        //
        // If we are associated, we have to send a NULL data frame first notifying 
        // the AP if we are in PS mode. Otherwise, set the RF immediately, unless we are
        // in the middle of scanning. 
        //

        if (mode->usAID != 0)
        {
            pNic->ManagementInfo.bPowerMgmtChangePktSent = FALSE;
            HwSendNullPkt(pNic);
        }
        else if (!pNic->ManagementInfo.bScanInProgress)
        {
            MpTrace(COMP_POWER, DBG_LOUD, 
                    (" *** RF %s indefinitely\n", mode->dot11PowerMode == dot11_power_mode_active ? "ON" : "OFF"));

            if (mode->dot11PowerMode == dot11_power_mode_active)
            {
                HwSetRFOn(pNic, 3);
            }
            else
            {
                HwSetRFState(pNic, RF_OFF);
            }
        }
    }
    
    NdisReleaseSpinLock(&pNic->ManagementInfo.PowerMgmtLock);

    return NDIS_STATUS_SUCCESS;    
}

VOID
HwIndicateNewLinkSpeed(
    IN PNIC     pNic,
    IN ULONG64  linkSpeed
    )    
{
    NDIS_STATUS_INDICATION  statusIndication;
    NDIS_LINK_STATE         linkState;
    
    NdisZeroMemory(&statusIndication, sizeof(NDIS_STATUS_INDICATION));
    NdisZeroMemory(&linkState, sizeof(NDIS_LINK_STATE));
    
    //
    // Fill in object headers
    //
    statusIndication.Header.Type = NDIS_OBJECT_TYPE_STATUS_INDICATION;
    statusIndication.Header.Revision = NDIS_STATUS_INDICATION_REVISION_1;
    statusIndication.Header.Size = sizeof(NDIS_STATUS_INDICATION);

    linkState.Header.Revision = NDIS_LINK_STATE_REVISION_1;
    linkState.Header.Type = NDIS_OBJECT_TYPE_DEFAULT;
    linkState.Header.Size = sizeof(NDIS_LINK_STATE);

    //
    // Link state buffer
    //
    linkState.MediaConnectState = MediaConnectStateConnected;
    linkState.MediaDuplexState = MediaDuplexStateHalf;
    linkState.RcvLinkSpeed = linkSpeed;
    linkState.XmitLinkSpeed = linkSpeed;
   
    //
    // Fill in the status buffer
    // 
    statusIndication.StatusCode = NDIS_STATUS_LINK_STATE;
    statusIndication.SourceHandle = pNic->MiniportAdapterHandle;
    statusIndication.DestinationHandle = NULL;
    statusIndication.RequestId = 0;

    statusIndication.StatusBuffer = &linkState;
    statusIndication.StatusBufferSize = sizeof(NDIS_LINK_STATE);
    
    //
    // Indicate the status to NDIS
    //
    Mp11IndicateStatusIndication(
        pNic->pAdapter,
        &statusIndication
        );
}

void
Hw11SetTXDataRate(
    IN PNIC     pNic,
    IN PDOT11_RATE_SET APRateSet,
    IN ULONG    LinkQuality
    )
{
    PDOT11_RATE_SET STARateSet;
    ULONG           indexHwRates;
    ULONG           indexAPRates;
    
    //
    // Select the best rate supported by both AP and us. 
    //

    STARateSet = &pNic->ManagementInfo.OperatingPhyMIB->OperationalRateSet;

    NdisAcquireSpinLock(&pNic->ManagementInfo.PhyMIBConfigLock);
    pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.uRateSetLength = 0;
    //
    // We merge the rates from the AP and the client to create the 
    // currently active data rates table
    //
    for (indexHwRates = 0; indexHwRates < STARateSet->uRateSetLength; indexHwRates++) 
    {
        for (indexAPRates = 0; indexAPRates < APRateSet->uRateSetLength; indexAPRates++)
        {
            if (STARateSet->ucRateSet[indexHwRates] == (APRateSet->ucRateSet[indexAPRates] & 0x7f))
            {
                pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.ucRateSet
                    [pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.uRateSetLength]
                        = STARateSet->ucRateSet[indexHwRates];

                pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.uRateSetLength++;
                break;
            }
        }
    }

    //
    // If we dont find any rates, we will stick with our management packet rate
    //
    if (pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.uRateSetLength == 0)
    {
        pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.ucRateSet[0] = 
            (UCHAR) pNic->ManagementInfo.CurrentBeaconRate;
        pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.uRateSetLength = 1;
    }
    else if (pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.uRateSetLength > 1)
    {
        // bubble sort data rates in ascending order
        INT     i, j;
        UCHAR   temp;
        for (i = pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.uRateSetLength - 1; i >= 0; i--)
        {
            for (j = 1; j <= i; j++)
            {
                if (pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.ucRateSet[j - 1] > 
                    pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.ucRateSet[j])
                {
                    temp = pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.ucRateSet[j - 1];
                    pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.ucRateSet[j - 1] = 
                        pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.ucRateSet[j];
                    pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.ucRateSet[j] = temp;
                }
            }
        }
    }

    if (LinkQuality < LOW_RATE_LINK_QUALITY_THRESHOLD)
    {
        //
        // The link quality is low, we will go for the lower start rate instead of 
        // the max supported. The hardware does rate fallback, so we pick
        // something that would cause the least number of retrys
        //
        for (indexHwRates = pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.uRateSetLength - 1; 
             indexHwRates > 0;
             indexHwRates--) 
        {
            //
            // Check for a rate supported by both us and the AP that is below the max we prefer to use
            //
            if (pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.ucRateSet[indexHwRates] <= LOW_RATE_MAX_DATA_RATE)
            {
                //
                // Found the rate we want to use
                //
                break;
            }
        }
        
        pNic->ManagementInfo.CurrentTXDataRate = 
                    pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.ucRateSet[indexHwRates];
        
    }
    else
    {
        // 
        // Pick the highest data rate supported between us and the AP
        //
        pNic->ManagementInfo.CurrentTXDataRate = 
                    pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.ucRateSet
                        [pNic->ManagementInfo.OperatingPhyMIB->ActiveRateSet.uRateSetLength - 1];
    }

    NdisReleaseSpinLock(&pNic->ManagementInfo.PhyMIBConfigLock);
    MpTrace(COMP_ASSOC, DBG_LOUD, ("TX Data rate: %d\n", pNic->ManagementInfo.CurrentTXDataRate));

    //
    // Indicate NDIS_STATUS_LINK_STATE to inform the OS about the new 
    // link speed
    //
    HwIndicateNewLinkSpeed(pNic, HwDataRateToLinkSpeed((UCHAR)pNic->ManagementInfo.CurrentTXDataRate));    

    // indicate link quality after receive next packet
    Sta11NotifyEventUpdateLinkQuality(pNic->pStation, TRUE);
}

DOT11_PHY_TYPE
Hw11DeterminePHYType(
    IN PNIC pNic,
    IN DOT11_CAPABILITY Capability,
    IN UCHAR Channel
    )
{
    if (pNic->CardInfo.HardwareID == HW_ID_8180)
        return dot11_phy_type_hrdsss;
    else if (Channel > 14)
        return dot11_phy_type_ofdm;
    else
    {
        //
        // We have to determine between B and G.
        // If the Capability contains G-only field, it must be G
        // Otherwise, use our current operating PHY type.
        //
        if (Capability.ShortSlotTime || 
            Capability.DSSSOFDM ||
            pNic->ManagementInfo.OperatingPhyMIB->PhyType == dot11_phy_type_ofdm)
        {
            return dot11_phy_type_erp;
        }
        else
        {
            return pNic->ManagementInfo.OperatingPhyMIB->PhyType;
        }
    }
}

VOID
HwUpdateTxRetryStat(
    IN PNIC                 pNic,
    IN PMP_TX_MSDU          pMpTxd,
    IN USHORT               retryCount
    )
{
    PMP_DOT11_MGMT_DATA_MAC_HEADER  fragmentHeader = NULL;
    PNET_BUFFER                     currentNetBuffer = NULL;

    do
    {
        if (pNic->ManagementInfo.bDeviceConnected == FALSE)
        {
            // only update retry statistics when device is connected
            break;
        }
        
        currentNetBuffer = NET_BUFFER_LIST_FIRST_NB(pMpTxd->NetBufferList);
        if (currentNetBuffer == NULL)
        {
            break;
        }

        if (Dot11GetMacHeaderFromNB(currentNetBuffer, (PDOT11_MAC_HEADER*)&fragmentHeader) != NDIS_STATUS_SUCCESS)
        {
            break;
        }

        if (fragmentHeader->FrameControl.Type != DOT11_FRAME_TYPE_DATA)
        {
            // only update retry statistics for control, management, and unicast data packets
            break;
        }
        
        InterlockedExchangeAdd(&pNic->ManagementInfo.TotalRetryCount, retryCount);

        // this function is called for every packet sent
        InterlockedIncrement((LONG*)&pNic->ManagementInfo.PacketsSentForTxRateCheck);
    } while (FALSE);
}

/*
    Tx rate negotiation algorithm:
    Preconditions to update tx data rate:
            1) device is in connect state; 
            2)device has sent at lease 100 data packets

    retransmitPercentage = (toal retry) / (total packets sent)

    if retransmit percentage <= threshold for rate increase which default to 35%
        if not sending at the highest rate
            if previously came down from higher rate and wait count < wait required
                increase wait count and exit
            else
                if not previously came down from higher rate
                    reset wait required
                else leave wait required unchanged
                increase current tx rate to next higher rate, reset all other counters and exit

    if retransmit percentage >= threshold for roam which default to 350%
        if already send at the lowest rate
            try to roam to a better AP, reset all counters and exit
        else if there are at least fallback skip (which default to 3) lower data rates available
            reduce current tx rate to third lower data rate, reset all counters and exit
        else if current sending at second lowest rate
            set current tx rate to the lowest value, reset all counters and exit
        else fall through to following rate fallback handler

    if retransmit percentage >= threshold for rate fallback which default to 125%
    and not sending at the lowest rate
        if previously came up from lower rate
            double current wait required
        else reset wait required
        reduce current tx rate to next lower value, reset all other counters and exit
*/
VOID 
HwUpdateTxDataRate(
    IN PNIC                     pNic
    )
{
    PNICMANAGEMENTINFO  pManagementInfo = &pNic->ManagementInfo;
    PDOT11_RATE_SET     pActiveRateSet = &pManagementInfo->OperatingPhyMIB->ActiveRateSet;
    ULONG               rateIndex = 0;
    USHORT              prevTxRate = 0;
    ULONG               totalRetry = pManagementInfo->TotalRetryCount;
    ULONG               totalSend = pManagementInfo->PacketsSentForTxRateCheck;

    if (totalSend < pNic->TxInfo.MinPacketsSentForTxRateUpdate ||
        pManagementInfo->bDeviceConnected == FALSE)
    {
        return;
    }

    // reset counters
    InterlockedExchange(&pManagementInfo->TotalRetryCount, 0);
    InterlockedExchange((LONG*)&pManagementInfo->PacketsSentForTxRateCheck, 0);

    // acquire lock before accessing ActiveRateSet in PhyMIB
    NdisAcquireSpinLock(&pNic->ManagementInfo.PhyMIBConfigLock);
    
    for (rateIndex = 0; rateIndex < pActiveRateSet->uRateSetLength; rateIndex++)
    {
        if (pManagementInfo->CurrentTXDataRate == pActiveRateSet->ucRateSet[rateIndex])
        {
            prevTxRate = pManagementInfo->CurrentTXDataRate;
            break;
        }
    }

    do
    {
        ULONG   retransmitPercentage = 0;

        // prevTxRate equals 0 means pManagementInfo->CurrentTXDataRate 
        // is not in pActiveRateSet->ucRateSet list
        if (prevTxRate == 0)
        {
            break;
        }

        retransmitPercentage = totalRetry * 100 / totalSend;

        MpTrace(COMP_DBG, DBG_TRACE, ("%s: retransmitPercentage=%d(%d/%d), waitCount=%d, "
            "waitRequired=%d, prevRate=%d\n", 
            __FUNCTION__, 
            retransmitPercentage, totalRetry, totalSend, 
            pManagementInfo->TxRateIncreaseWaitCount, 
            pManagementInfo->TxRateIncreaseWaitRequired, 
            pManagementInfo->PrevTxDataRate));

        if (retransmitPercentage <= pNic->TxInfo.TxFailureThresholdForRateIncrease)
        {
            // Consider going up
            
            if (rateIndex < pActiveRateSet->uRateSetLength - 1)
            {
                if ((pManagementInfo->PrevTxDataRate == pActiveRateSet->ucRateSet[rateIndex + 1]) &&
                    (pManagementInfo->TxRateIncreaseWaitCount + 1 < pManagementInfo->TxRateIncreaseWaitRequired))
                {
                    // I just came down from the rate above me, i dont want to go up yet due to WaitRequired
                    pManagementInfo->TxRateIncreaseWaitCount++;

                    MpTrace(COMP_DBG, DBG_TRACE, ("%s: WAIT before increasing Tx rate. retransmitPercentage=%d(%d/%d), "
                        "waitCount=%d, waitRequired=%d, prevRate=%d\n",
                        __FUNCTION__,
                        retransmitPercentage, totalRetry, totalSend, pManagementInfo->TxRateIncreaseWaitCount, 
                        pManagementInfo->TxRateIncreaseWaitRequired, pManagementInfo->PrevTxDataRate));
                }
                else
                {
                    // 1. I came down rate above me and WaitCount >= WaitRequired
                    // 2. I came up from rate below me, no need to wait for additional time
                    if (pManagementInfo->PrevTxDataRate != pActiveRateSet->ucRateSet[rateIndex + 1])
                    {
                        // Case 2 above
                        pManagementInfo->TxRateIncreaseWaitRequired = 1;
                    }
                    else
                    {
                        // Case 1 above
                        /** don't reset TxRateIncreaseWaitRequired as we need to double */
                        /** the value if fallback to the current rate again */
                    }
                    pManagementInfo->PrevTxDataRate = pManagementInfo->CurrentTXDataRate;
                    pManagementInfo->TxRateIncreaseWaitCount = 0;
                    
                    MpTrace(COMP_DBG, DBG_TRACE, ("%s: increasing Tx data rate from %d to %d. "
                        "retransmitPercentage = %d(%d/%d), waitCount=%d, waitRequired=%d, prevRate=%d\n",
                        __FUNCTION__, 
                        pManagementInfo->CurrentTXDataRate, pActiveRateSet->ucRateSet[rateIndex + 1],
                        retransmitPercentage, totalRetry, totalSend,
                        pManagementInfo->TxRateIncreaseWaitCount, 
                        pManagementInfo->TxRateIncreaseWaitRequired, 
                        pManagementInfo->PrevTxDataRate));
                    
                    pManagementInfo->CurrentTXDataRate = pActiveRateSet->ucRateSet[rateIndex + 1];
                }
            }
            break;
        }

        if (retransmitPercentage >= pNic->TxInfo.TxFailureThresholdForRoam)
        {
            ULONG   rateSkipLevel = pNic->TxInfo.TxDataRateFallbackSkipLevel;
            
            // Really large retry count, consider roaming
            
            if (rateIndex == 0)
            {
                // I am sending at the lowest rate. Either roam or disconnect.
                MpTrace(COMP_DBG, DBG_TRACE, ("%s: too many retransmit happened while "
                    "transmitting at the lowest data rate. Attempting to roam. "
                    "retransmitPercentage=%d(%d/%d), waitCount=%d, waitRequired=%d, prevRate=%d", 
                    __FUNCTION__,
                    retransmitPercentage, totalRetry, totalSend, 
                    pManagementInfo->TxRateIncreaseWaitCount,
                    pManagementInfo->TxRateIncreaseWaitRequired, 
                    pManagementInfo->PrevTxDataRate));

                Sta11NotifyEventRoamForSendFailures(pNic->pStation);

                // reset counters
                pManagementInfo->PrevTxDataRate = 0;
                pManagementInfo->TxRateIncreaseWaitRequired = 1;
                pManagementInfo->TxRateIncreaseWaitCount = 0;
                break;
            }
            else if (rateIndex >= rateSkipLevel)
            {
                // try to go down three rates
                MpTrace(COMP_DBG, DBG_TRACE, ("%s: too many retransmit happened. Reducing Tx rate from %d to %d.\n",
                        __FUNCTION__, 
                        pManagementInfo->CurrentTXDataRate,
                        pActiveRateSet->ucRateSet[rateIndex - rateSkipLevel]));

                pManagementInfo->CurrentTXDataRate = pActiveRateSet->ucRateSet[rateIndex - rateSkipLevel];
                pManagementInfo->PrevTxDataRate = 0;
                pManagementInfo->TxRateIncreaseWaitRequired = 1;
                pManagementInfo->TxRateIncreaseWaitCount = 0;
                break;
            }
            else if (rateIndex != 1)
            {
                // set tx rate to the lowest rate
                MpTrace(COMP_DBG, DBG_TRACE, ("%s: too many retransmit happened. Reducing Tx rate from "
                        "%d to lowest %d.\n",
                        __FUNCTION__, 
                        pManagementInfo->CurrentTXDataRate,
                        pActiveRateSet->ucRateSet[0]));

                pManagementInfo->CurrentTXDataRate = pActiveRateSet->ucRateSet[0];
                pManagementInfo->PrevTxDataRate = 0;
                pManagementInfo->TxRateIncreaseWaitRequired = 1;
                pManagementInfo->TxRateIncreaseWaitCount = 0;
                break;
            }
            else
            {
                // rateIndex equals to 1. this is the same as lowering tx rate by 1 level
                // which is what rate fallback handler does. fall through.
            }
        }

        if (retransmitPercentage >= pNic->TxInfo.TxFailureThresholdForRateFallback && rateIndex > 0)
        {
            // consider going down. no need to wait for additional time
            
            if (pManagementInfo->PrevTxDataRate == pActiveRateSet->ucRateSet[rateIndex - 1])
            {
                pManagementInfo->TxRateIncreaseWaitRequired *= 2;
            }
            else
            {
                pManagementInfo->TxRateIncreaseWaitRequired = 1;
            }
            pManagementInfo->PrevTxDataRate = pManagementInfo->CurrentTXDataRate;
            pManagementInfo->TxRateIncreaseWaitCount = 0;
            
            MpTrace(COMP_DBG, DBG_TRACE, ("%s: reducing Tx data rate from %d to %d. "
                "retransmitPercentage=%d(%d/%d), waitCount=%d, waitRequired=%d, prevRate=%d\n",
                __FUNCTION__, 
                pManagementInfo->CurrentTXDataRate, 
                pActiveRateSet->ucRateSet[rateIndex - 1],
                retransmitPercentage, totalRetry, totalSend, 
                pManagementInfo->TxRateIncreaseWaitCount, 
                pManagementInfo->TxRateIncreaseWaitRequired,
                pManagementInfo->PrevTxDataRate));

            pManagementInfo->CurrentTXDataRate = pActiveRateSet->ucRateSet[rateIndex - 1];
            break;
        }
    } while (FALSE);

    NdisReleaseSpinLock(&pNic->ManagementInfo.PhyMIBConfigLock);

    if (prevTxRate != pManagementInfo->CurrentTXDataRate)
    {
        // set state so that new link quality will be indicated 
        // when next packet comes in
        Sta11NotifyEventUpdateLinkQuality(pNic->pStation, TRUE);
        
        // indicate new link speed
        HwIndicateNewLinkSpeed(pNic, HwDataRateToLinkSpeed((UCHAR)pManagementInfo->CurrentTXDataRate));
    }
}


NDIS_STATUS
Hw11QueryLinkParameters(
    IN PNIC     pNic,
    OUT PNDIS_LINK_PARAMETERS      pLinkParams
    )
{
    //
    // Report the current link speed to the OS
    //
    pLinkParams->MediaDuplexState = MediaDuplexStateHalf;
    pLinkParams->XmitLinkSpeed = HwDataRateToLinkSpeed((UCHAR)pNic->ManagementInfo.CurrentTXDataRate);
    pLinkParams->RcvLinkSpeed = HwDataRateToLinkSpeed((UCHAR)pNic->ManagementInfo.CurrentTXDataRate);
    pLinkParams->PauseFunctions = NdisPauseFunctionsUnsupported;
    pLinkParams->AutoNegotiationFlags = NDIS_LINK_STATE_DUPLEX_AUTO_NEGOTIATED;

    return NDIS_STATUS_SUCCESS;
}

NDIS_STATUS
Hw11SetLinkParameters(
    IN PNIC     pNic,
    IN PNDIS_LINK_PARAMETERS      pLinkParams
    )
{
    PDOT11_RATE_SET STARateSet;
    ULONG           index;
    UCHAR           dataRate;
    
    if (pLinkParams->RcvLinkSpeed != pLinkParams->XmitLinkSpeed)
    {
        // For us the TX and RX rates must be the same
        return NDIS_STATUS_INVALID_DATA;
    }

    // If the rate specified by the user is valid, we are going to attempt to 
    // transmit at that rate (even if it may not be acceptable to the AP)
    dataRate = HwLinkSpeedToDataRate(pLinkParams->XmitLinkSpeed);

    STARateSet = &pNic->ManagementInfo.OperatingPhyMIB->OperationalRateSet;

    // Is this a supported data rate?
    for (index = 0; index < STARateSet->uRateSetLength; index++)
    {
        if (STARateSet->ucRateSet[index] == dataRate)
        {
            pNic->ManagementInfo.CurrentTXDataRate = STARateSet->ucRateSet[index];
            MpTrace(COMP_ASSOC, DBG_LOUD, ("TX Data rate: %d\n", STARateSet->ucRateSet[index]));
            
            //
            // Indicate NDIS_STATUS_LINK_STATE to inform the OS about the new 
            // link speed
            //
            HwIndicateNewLinkSpeed(pNic, HwDataRateToLinkSpeed((UCHAR)pNic->ManagementInfo.CurrentTXDataRate));

            // TODO: indicate link quality here???
            
            return NDIS_STATUS_SUCCESS;
        }
    }

    // Unsupported data rate
    return NDIS_STATUS_INVALID_DATA;
}

VOID
HwIncrementNextDescToSend(
    IN  PNIC    pNic,
    IN  INT     QueueIndex,
    IN  INT     Increment,
    IN  BOOLEAN bTxDescProtection)
{
    if (bTxDescProtection == TRUE)
    {
        NdisAcquireSpinLock(&pNic->TxInfo.TxDescLock);
        pNic->TxInfo.TxNextDescToSend[QueueIndex] = (pNic->TxInfo.TxNextDescToSend[QueueIndex] + Increment) % pNic->TxInfo.TxTotalDescNum[QueueIndex];
        NdisReleaseSpinLock(&pNic->TxInfo.TxDescLock);
    }
    else
    {
        pNic->TxInfo.TxNextDescToSend[QueueIndex] = (pNic->TxInfo.TxNextDescToSend[QueueIndex] + Increment) % pNic->TxInfo.TxTotalDescNum[QueueIndex];
    }

    InterlockedExchangeAdd(&pNic->TxInfo.TxBusyDescCount[QueueIndex], (LONG)Increment);
}

PTX_DESC
HwGetNextDescToSend(
    IN  PNIC    pNic,
    IN  INT     QueueIndex,
    IN  INT     Increment,
    IN  BOOLEAN bTxDescProtection
    )
{
    PTX_DESC    pDesc = NULL;
    
    if (bTxDescProtection == TRUE)
    {
        NdisAcquireSpinLock(&pNic->TxInfo.TxDescLock);
        pDesc = &pNic->TxInfo.TxDesc[QueueIndex][(pNic->TxInfo.TxNextDescToSend[QueueIndex] + Increment) % pNic->TxInfo.TxTotalDescNum[QueueIndex]]; 
        NdisReleaseSpinLock(&pNic->TxInfo.TxDescLock);
    }
    else
    {
        pDesc = &pNic->TxInfo.TxDesc[QueueIndex][(pNic->TxInfo.TxNextDescToSend[QueueIndex] + Increment) % pNic->TxInfo.TxTotalDescNum[QueueIndex]];
    }

    return pDesc;
}

VOID
Hw11CheckForHighQCompletion(
    IN  PNIC    pNic 
    )
{
    PTX_STATUS_DESC pDesc;

    //
    // Check High Queue(This should be transparent for upper layer)
    // We are check if an ATIM packet has been send completed
    //
    
    while(HwGetTxBusyDescNum(pNic, HIGH_QUEUE) > 0)
    {

        //
        // probe response is sent with high queue
        //
        
        pDesc = (PTX_STATUS_DESC)HwGetNextDescToCheck(pNic, HIGH_QUEUE, 0);
        
        if (!pDesc->OWN)
        {
            // in AP or ad-hoc STA, only probe response is sent with high queue
            HwIncrementTxNextDescToCheck(pNic, HIGH_QUEUE, 1);
        }
        else 
        {
            break;
        }
    }
}




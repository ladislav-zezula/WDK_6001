/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    Hw_Main.c

Abstract:
    HW layer PNP functions
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created

Notes:

--*/

#include "hw_pcomp.h"

#include "Hw_Main.h"
#include "Hw_Nic.h"
#include "Hw_Func.h"
#include "Hw_Def.h"

#if DOT11_TRACE_ENABLED
#include "Hw_Main.tmh"
#endif


NIC_REG_ENTRY NICRegTable[] = {
    {NDIS_STRING_CONST("RxTotalDescNum"),       // Reg value name
     0,                                         // 1 -> required,0 -> optional
     NdisParameterInteger,                      // Type
     FIELD_OFFSET(NIC,RxInfo),                  // Struct offset in MP_ADAPTER
     FIELD_OFFSET(NICRXINFO,RxTotalDescNum),    // Struct offset
     sizeof(((NICRXINFO *)0)->RxTotalDescNum),  // Size of the field
     64,                                        // Default value
     1,                                         // Min value
     64},                                       // Max value

    {NDIS_STRING_CONST("RadioOff"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,RadioOff),
     sizeof(((NICRFINFO *)0)->RadioOff),
     0,                                         // Default = On
     0,
     1},

    {NDIS_STRING_CONST("ShortRetryLimit"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,DupRegistryInfo),
     FIELD_OFFSET(NICDUPLICATEINFO,ShortRetryLimit),
     sizeof(((NICDUPLICATEINFO *)0)->ShortRetryLimit),
     7,
     0,
     15},

    {NDIS_STRING_CONST("LongRetryLimit"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,DupRegistryInfo),
     FIELD_OFFSET(NICDUPLICATEINFO,LongRetryLimit),
     sizeof(((NICDUPLICATEINFO *)0)->LongRetryLimit),
     7,
     0,
     15},

    {NDIS_STRING_CONST("DefaultBeaconRate"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,DupRegistryInfo),
     FIELD_OFFSET(NICDUPLICATEINFO,DefaultBeaconRate),
     sizeof(((NICDUPLICATEINFO *)0)->DefaultBeaconRate),
     1,
     2,
     2},

    {NDIS_STRING_CONST("InterfaceDebugMode"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,InterfaceDebugMode),
     sizeof(((NICRFINFO *)0)->InterfaceDebugMode),
     1,
     0,
     3},

    {NDIS_STRING_CONST("EnableGPIO0"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,EnableGPIO0),
     sizeof(((NICRFINFO *)0)->EnableGPIO0),
     0,
     0,
     1},

    {NDIS_STRING_CONST("b2ndCut"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,b2ndCut),
     sizeof(((NICRFINFO *)0)->b2ndCut),
     0,
     0,
     0x1},

    {NDIS_STRING_CONST("ZebraVersion"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,RegZebraVersion),
     sizeof(((NICRFINFO *)0)->RegZebraVersion),
     1,
     0,
     2},

    {NDIS_STRING_CONST("ChargePump"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,ChargePump),
     sizeof(((NICRFINFO *)0)->ChargePump),
     2,
     0,
     6},

    {NDIS_STRING_CONST("TXChargePump"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,TXChargePump),
     sizeof(((NICRFINFO *)0)->TXChargePump),
     6,
     0,
     7},

    {NDIS_STRING_CONST("RXChargePump"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,RXChargePump),
     sizeof(((NICRFINFO *)0)->RXChargePump),
     0,
     0,
     7},

    {NDIS_STRING_CONST("CornerChange"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,CornerChange),
     sizeof(((NICRFINFO *)0)->CornerChange),
     0,
     0,
     2},

    {NDIS_STRING_CONST("TXAntenna"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,TXAntenna),
     sizeof(((NICRFINFO *)0)->TXAntenna),
     0,
     0,
     1},

    {NDIS_STRING_CONST("RXAntenna"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,RXAntenna),
     sizeof(((NICRFINFO *)0)->RXAntenna),
     0,
     0,
     1},

/*
    {NDIS_STRING_CONST("TXOFDMPower"),
     0,
     NdisParameterInteger,
     MP_OFFSET(TXOFDMPower),
     MP_SIZE(TXOFDMPower),
     1,
     0,
     3},

    {NDIS_STRING_CONST("TXCCKPower"),
     0,
     NdisParameterInteger,
     MP_OFFSET(TXCCKPower),
     MP_SIZE(TXCCKPower),
     1,
     0,
     3},
*/

    {NDIS_STRING_CONST("FastFalseAlarm"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,FastFalseAlarm),
     sizeof(((NICRFINFO *)0)->FastFalseAlarm),
     1,
     0,
     1},

    {NDIS_STRING_CONST("CCKFastFalseAlarm"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,CCKFastFalseAlarm),
     sizeof(((NICRFINFO *)0)->CCKFastFalseAlarm),
     1,
     0,
     1},

    {NDIS_STRING_CONST("EVMCheck"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,EVMCheck),
     sizeof(((NICRFINFO *)0)->EVMCheck),
     1,
     0,
     3},

    {NDIS_STRING_CONST("AGCmode"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,AGCmode),
     sizeof(((NICRFINFO *)0)->AGCmode),
     1,
     0,
     1},

    {NDIS_STRING_CONST("SamplingPhase"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,SamplingPhase),
     sizeof(((NICRFINFO *)0)->SamplingPhase),
     1,
     0,
     1},

    {NDIS_STRING_CONST("EnableGPIO0"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,EnableGPIO0),
     sizeof(((NICRFINFO *)0)->EnableGPIO0),
     0,
     0,
     1},

    {NDIS_STRING_CONST("VerificationType"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,CardInfo),
     FIELD_OFFSET(NICCARDINFO,VerificationType),
     sizeof(((NICCARDINFO *)0)->VerificationType),
     1,
     0,
     4},

    {NDIS_STRING_CONST("PacketControlCW"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,CardInfo),
     FIELD_OFFSET(NICCARDINFO,RegPacketControlCW),
     sizeof(((NICCARDINFO *)0)->RegPacketControlCW),
     UNIVERSAL_CONTROL_CW,
     UNIVERSAL_CONTROL_CW,
     PACKET_CONTROL_CW},

    {NDIS_STRING_CONST("PacketControlRL"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,CardInfo),
     FIELD_OFFSET(NICCARDINFO,RegPacketControlRL),
     sizeof(((NICCARDINFO *)0)->RegPacketControlRL),
     UNIVERSAL_CONTROL_RL,
     UNIVERSAL_CONTROL_RL,
     PACKET_CONTROL_RL},

    {NDIS_STRING_CONST("PacketControlAGC"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,CardInfo),
     FIELD_OFFSET(NICCARDINFO,RegPacketControlAGC),
     sizeof(((NICCARDINFO *)0)->RegPacketControlAGC),
     UNIVERSAL_CONTROL_AGC,
     UNIVERSAL_CONTROL_AGC,
     PACKET_CONTROL_AGC},

    {NDIS_STRING_CONST("CCK_TxAGC"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,CardInfo),
     FIELD_OFFSET(NICCARDINFO,RegCCK_TxAGC),
     sizeof(((NICCARDINFO *)0)->RegCCK_TxAGC),
     128,
     1,
     255},

    {NDIS_STRING_CONST("OFDM_TxAGC"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,CardInfo),
     FIELD_OFFSET(NICCARDINFO,
     RegOFDM_TxAGC),
     sizeof(((NICCARDINFO *)0)->RegOFDM_TxAGC),
     128,
     1,
     255},

    {NDIS_STRING_CONST("AGC"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,CardInfo),
     FIELD_OFFSET(NICCARDINFO,RegAGC),
     sizeof(((NICCARDINFO *)0)->RegAGC),
     1,
     1,
     100},

    {NDIS_STRING_CONST("PacketControlAntenna"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,CardInfo),
     FIELD_OFFSET(NICCARDINFO,RegPacketControlAntenna),
     sizeof(((NICCARDINFO *)0)->RegPacketControlAntenna),
     UNIVERSAL_CONTROL_ANTENNA,
     UNIVERSAL_CONTROL_ANTENNA,
     PACKET_CONTROL_ANTENNA},

    {NDIS_STRING_CONST("CCK_TxAntenna"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,CardInfo),
     FIELD_OFFSET(NICCARDINFO,RegCCK_TxAntenna),
     sizeof(((NICCARDINFO *)0)->RegCCK_TxAntenna),
     0,
     0,
     1},

    {NDIS_STRING_CONST("OFDM_TxAntenna"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,CardInfo),
     FIELD_OFFSET(NICCARDINFO,RegOFDM_TxAntenna),
     sizeof(((NICCARDINFO *)0)->RegOFDM_TxAntenna),
     0,
     0,
     1},

    {NDIS_STRING_CONST("FeedbackControAntenna"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,CardInfo),
     FIELD_OFFSET(NICCARDINFO,RegFeedbackControlAntenna),
     sizeof(((NICCARDINFO *)0)->RegFeedbackControlAntenna),
     1,
     0,
     1},

    {NDIS_STRING_CONST("bAutoRateFallback"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,CardInfo),
     FIELD_OFFSET(NICCARDINFO,bRegAutoRateFallback),
     sizeof(((NICCARDINFO *)0)->bRegAutoRateFallback),
     TRUE,
     FALSE,
     TRUE},

    {NDIS_STRING_CONST("AutoRateFallbackStep"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,CardInfo),
     FIELD_OFFSET(NICCARDINFO,RegAutoRateFallbackStep),
     sizeof(((NICCARDINFO *)0)->RegAutoRateFallbackStep),
     0,
     0,
     3},

    {NDIS_STRING_CONST("ChannelPlan"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,RfInfo),
     FIELD_OFFSET(NICRFINFO,ChannelPlan),
     sizeof(((NICRFINFO *)0)->ChannelPlan),
     DOMAIN_FROM_EEPROM,					//default , look at EEprom for values
     0,
     0x00ff},

    {NDIS_STRING_CONST("MinPacketsSentForTxRateUpdate"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,TxInfo),
     FIELD_OFFSET(NICTXINFO, MinPacketsSentForTxRateUpdate),
     sizeof(((NICTXINFO *)0)->MinPacketsSentForTxRateUpdate),
     100,
     10,
     500},

    {NDIS_STRING_CONST("TxFailureThresholdForRateFallback"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,TxInfo),
     FIELD_OFFSET(NICTXINFO, TxFailureThresholdForRateFallback),
     sizeof(((NICTXINFO *)0)->TxFailureThresholdForRateFallback),
     125,
     50,
     200},

    {NDIS_STRING_CONST("TxFailureThresholdForRateIncrease"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,TxInfo),
     FIELD_OFFSET(NICTXINFO,TxFailureThresholdForRateIncrease),
     sizeof(((NICTXINFO *)0)->TxFailureThresholdForRateIncrease),
     35,
     0,
     50},

    {NDIS_STRING_CONST("TxFailureThresholdForRoam"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,TxInfo),
     FIELD_OFFSET(NICTXINFO,TxFailureThresholdForRoam),
     sizeof(((NICTXINFO *)0)->TxFailureThresholdForRoam),
     350,
     300,
     600},

    {NDIS_STRING_CONST("TxDataRateFallbackSkipLevel"),
     0,
     NdisParameterInteger,
     FIELD_OFFSET(NIC,TxInfo),
     FIELD_OFFSET(NICTXINFO,TxDataRateFallbackSkipLevel),
     sizeof(((NICTXINFO *)0)->TxDataRateFallbackSkipLevel),
     3,
     1,
     6},
};

NDIS_STATUS
Hw11SetOptionalServices(
    IN  NDIS_HANDLE  NdisMiniportDriverHandle,
    IN  NDIS_HANDLE  MiniportDriverContext
    )
{
    UNREFERENCED_PARAMETER(NdisMiniportDriverHandle);
    UNREFERENCED_PARAMETER(MiniportDriverContext);

    return NDIS_STATUS_SUCCESS;
}


VOID
Hw11MiniportPause(
    IN  PNIC                                pNic,
    IN  PNDIS_MINIPORT_PAUSE_PARAMETERS     MiniportPauseParameters
    )
{
    UNREFERENCED_PARAMETER(pNic);
    UNREFERENCED_PARAMETER(MiniportPauseParameters);
}


NDIS_STATUS
Hw11MiniportRestart(
    IN  PNIC                                pNic,
    IN  PNDIS_MINIPORT_RESTART_PARAMETERS   MiniportRestartParameters
    )
{
    UNREFERENCED_PARAMETER(pNic);
    UNREFERENCED_PARAMETER(MiniportRestartParameters);

    return NDIS_STATUS_SUCCESS;
}


NDIS_STATUS
Hw11AllocateNic(
    IN  NDIS_HANDLE     MiniportAdapterHandle,
    OUT PNIC*           ppNic,
    IN  PADAPTER        pAdapter,
    IN  PSTATION        pStation
    )
{
    NDIS_STATUS ndisStatus;
    ULONG       size;
    
    
    ndisStatus = NDIS_STATUS_RESOURCES;
    __try
    {

        //
        // Allocate NIC structure.
        //
        MP_ALLOCATE_MEMORY(MiniportAdapterHandle, ppNic, sizeof(NIC), HW11_MEMORY_TAG);
        if (*ppNic == NULL) 
        {
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Failed to allocate memory for NIC\n"));
            __leave;
        }
        NdisZeroMemory((*ppNic), sizeof(NIC));

        size = sizeof(DOT11_SUPPORTED_PHY_TYPES) + (MAX_NUM_PHY_TYPES - 1) * sizeof(DOT11_PHY_TYPE);
        MP_ALLOCATE_MEMORY(MiniportAdapterHandle,
                           &((*ppNic)->ManagementInfo.pSupportedPhyTypes),
                           size,
                           HW11_MEMORY_TAG);
        if ((*ppNic)->ManagementInfo.pSupportedPhyTypes == NULL)
        {
            MpTrace(COMP_INIT_PNP,
                    DBG_SERIOUS,
                    ("Failed to allocate memory for NIC->ManagementInfo.pSupportedPhyTypes\n"));
            __leave;
        }
        NdisZeroMemory((*ppNic)->ManagementInfo.pSupportedPhyTypes, size);
    
        size = sizeof(DOT11_REG_DOMAINS_SUPPORT_VALUE) + 
               (MAX_NUM_DOT11_REG_DOMAINS_VALUE - 1) * sizeof(DOT11_REG_DOMAIN_VALUE);
        MP_ALLOCATE_MEMORY(MiniportAdapterHandle,
                           &((*ppNic)->ManagementInfo.pRegDomainsSupportValue),
                           size,
                           HW11_MEMORY_TAG);
        if ((*ppNic)->ManagementInfo.pRegDomainsSupportValue == NULL)
        {
            MpTrace(COMP_INIT_PNP,
                    DBG_SERIOUS,
                    ("Failed to allocate memory for NIC->ManagementInfo.pRegDomainsSupportValue\n"));
            __leave;
        }
        NdisZeroMemory((*ppNic)->ManagementInfo.pRegDomainsSupportValue, size);

        size = sizeof(DOT11_DIVERSITY_SELECTION_RX_LIST) +
              (MAX_NUM_DIVERSITY_SELECTION_RX_LIST - 1) * sizeof(DOT11_DIVERSITY_SELECTION_RX);
        MP_ALLOCATE_MEMORY(MiniportAdapterHandle,
                           &((*ppNic)->ManagementInfo.pDiversitySelectionRxList),
                           size, 
                           HW11_MEMORY_TAG);
        if ((*ppNic)->ManagementInfo.pDiversitySelectionRxList == NULL) 
        {
            MpTrace(COMP_INIT_PNP,
                    DBG_SERIOUS,
                    ("Failed to allocate memory for NIC->ManagementInfo.pDiversitySelectionRxList\n"));
            __leave;
        }
        NdisZeroMemory((*ppNic)->ManagementInfo.pDiversitySelectionRxList, size);

        //
        // Allocate the spin locks we need
        //
        NdisAllocateSpinLock(&(*ppNic)->RxInfo.ReceiveFilterLock);
        NdisAllocateSpinLock(&(*ppNic)->TxInfo.PostSGListLock);
        NdisAllocateSpinLock(&(*ppNic)->TxInfo.TxDescLock);

        (*ppNic)->MiniportAdapterHandle = MiniportAdapterHandle;
        (*ppNic)->pAdapter = pAdapter;
        (*ppNic)->pStation = pStation;
        
        HwInitializeVariable(*ppNic);

        ndisStatus = NDIS_STATUS_SUCCESS;
    } 
    __finally 
    {
    }

    return ndisStatus;
}


VOID
Hw11FreeNic(
    IN  PNIC         pNic
    )
{
    MPVERIFY(pNic);

    if (pNic->CardInfo.CSRAddress) 
    {
        NdisMUnmapIoSpace(pNic->MiniportAdapterHandle,
                          pNic->CardInfo.CSRAddress,
                          NIC_MAP_IOSPACE_LENGTH);
        pNic->CardInfo.CSRAddress = NULL;
    }

    if (pNic->CardInfo.PortOffset) 
    {
        NdisMDeregisterIoPortRange(pNic->MiniportAdapterHandle,
                                   pNic->CardInfo.IoBaseAddress,
                                   pNic->CardInfo.IoRange,
                                   pNic->CardInfo.PortOffset);
        pNic->CardInfo.PortOffset = NULL;
    }

    MP_FREE_MEMORY(pNic->ManagementInfo.pSupportedPhyTypes);
    MP_FREE_MEMORY(pNic->ManagementInfo.pRegDomainsSupportValue);
    MP_FREE_MEMORY(pNic->ManagementInfo.pDiversitySelectionRxList);

    //
    // Free the spinlocks we have allocated
    //
    NdisFreeSpinLock(&pNic->RxInfo.ReceiveFilterLock);
    NdisFreeSpinLock(&pNic->TxInfo.PostSGListLock);

    if (pNic->ManagementInfo.SwChnlWorkItem != NULL)
    {
        NdisFreeIoWorkItem(pNic->ManagementInfo.SwChnlWorkItem);
        pNic->ManagementInfo.SwChnlWorkItem = NULL;
    }

    MP_FREE_MEMORY(pNic);
}


NDIS_STATUS
Hw11InitializeNic(
    IN  PNIC         pNic
    )
{
    NDIS_STATUS         ndisStatus = NDIS_STATUS_ADAPTER_NOT_FOUND;
    NDIS_ERROR_CODE     ErrorCode = NDIS_ERROR_CODE_ADAPTER_NOT_FOUND;

    MPVERIFY(pNic);

    __try 
    {
        NdisMInitializeTimer(&pNic->ManagementInfo.Timer_Scan,
                             pNic->MiniportAdapterHandle,
                             HwScanCallback,
                             pNic);

        NdisMInitializeTimer(&pNic->ManagementInfo.Timer_JoinTimeout,
                             pNic->MiniportAdapterHandle,
                             HwJoinTimeoutCallback,
                             pNic);

        NdisMInitializeTimer(&pNic->ManagementInfo.Timer_Awake,
                             pNic->MiniportAdapterHandle,
                             HwAwakeCallback,
                             pNic);

        NdisMInitializeTimer(&pNic->ManagementInfo.Timer_HwPeriod,
                             pNic->MiniportAdapterHandle,
                             HwPeriodTimerCallback,
                             pNic);


        //
        // Allocate the work item (HwSwChnlWorkItem)
        //
        pNic->ManagementInfo.SwChnlWorkItem = NdisAllocateIoWorkItem(pNic->MiniportAdapterHandle);
        if(pNic->ManagementInfo.SwChnlWorkItem == NULL)
        {
            NdisWriteErrorLogEntry(pNic->MiniportAdapterHandle,
                                   NDIS_ERROR_CODE_OUT_OF_RESOURCES,
                                   0);
            ndisStatus = NDIS_STATUS_RESOURCES;
            __leave;
        }

        ndisStatus = HwReadAdapterInfo(pNic);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            NdisWriteErrorLogEntry(pNic->MiniportAdapterHandle,
                                   ErrorCode,
                                   0);
            __leave;
        }

        //
        // Get hardware version and type. If the card is 8185, do the 8185 specific initialization.
        //
        HwGetVersion(pNic);
        HwGetBusType(pNic);
        if (pNic->CardInfo.HardwareID == HW_ID_8185) 
        {
            Init8185(pNic);

            //
            // Allocate two lookaside lists for encryption info structure and MIC data strucure.
            //

            NdisInitializeNPagedLookasideList(&pNic->ManagementInfo.EncryptionInfoList,
                                              NULL,
                                              NULL,
                                              0,
                                              sizeof(NIC_ENCRYPTION_INFO),
                                              HW11_MEMORY_TAG,
                                              0);

            NdisInitializeNPagedLookasideList(&pNic->ManagementInfo.MICDataList,
                                              NULL,
                                              NULL,
                                              0,
                                              8,
                                              HW11_MEMORY_TAG,
                                              0);
        }
    }
    __finally 
    {
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            if (pNic->ManagementInfo.SwChnlWorkItem != NULL)
            {
                NdisFreeIoWorkItem(pNic->ManagementInfo.SwChnlWorkItem);
                pNic->ManagementInfo.SwChnlWorkItem = NULL;
            }
        }
    }

    return ndisStatus;
}


NDIS_STATUS
Hw11StartNic(
    IN  PNIC pNic
    )
{
    HwInitializeAdapter(pNic,TRUE);

    //
    // Start the periodic timer used for hardware specific code
    //
    pNic->ManagementInfo.HwPeriodTimerSync = 1;     // A value > 0 means the timer can be queued
    NdisInterlockedIncrement(&pNic->ManagementInfo.HwPeriodTimerSync);  // Timer is queued
    NdisMSetTimer(&pNic->ManagementInfo.Timer_HwPeriod,HWPERIOD_TIMER_IN_MS);

    return NDIS_STATUS_SUCCESS;
}


ULONG
Hw11GetMPDUMaxLength(
    IN  PNIC pNic
    )
{
    UNREFERENCED_PARAMETER(pNic);
    return pNic->ManagementInfo.uMPDUMaxLength;
}

VOID
Hw11TerminateNic(
    IN  PNIC pNic
)
{
    BOOLEAN Cancelled;

    //
    // Cancel the perioid timer and if necessary, wait for it to complete
    //    
    NdisInterlockedDecrement(&pNic->ManagementInfo.HwPeriodTimerSync);   // Stop queuing new timers    
    NdisMCancelTimer(&pNic->ManagementInfo.Timer_HwPeriod, &Cancelled);
    if (Cancelled == FALSE)
    {
        // If the timer is already running, wait for it to finish
        while (pNic->ManagementInfo.HwPeriodTimerSync > 0)
        {
            NdisMSleep(100);
        }
    }
    
    //
    // Cancel all other timers (these are all stopped already)
    //
    NdisMCancelTimer(&pNic->ManagementInfo.Timer_Scan, &Cancelled);
    NdisMCancelTimer(&pNic->ManagementInfo.Timer_JoinTimeout, &Cancelled);
    NdisMCancelTimer(&pNic->ManagementInfo.Timer_Awake, &Cancelled);

    //
    // Delete encryption info and MIC data lookaside list.
    //
    if (pNic->CardInfo.HardwareID == HW_ID_8185) 
    {
        NdisDeleteNPagedLookasideList(&pNic->ManagementInfo.EncryptionInfoList);
        NdisDeleteNPagedLookasideList(&pNic->ManagementInfo.MICDataList);
    }
}


NDIS_STATUS
Hw11SelfTest(
    IN  PNIC pNic
    )
{
    UNREFERENCED_PARAMETER(pNic);
    return NDIS_STATUS_SUCCESS;
}

VOID
Hw11ReadRegistryConfiguration(
    IN  PNIC         pNic,
    IN  NDIS_HANDLE  hConfigurationHandle
    )
{
    NDIS_STATUS     Status = NDIS_STATUS_SUCCESS;
    PNIC_REG_ENTRY  pRegEntry;
    UINT            i;
    UINT            value = 0;
    PUCHAR          pointer;
    PNDIS_CONFIGURATION_PARAMETER ReturnedValue;
    PUCHAR          NetworkAddress;
    UINT            Length;
    
    //
    // read all the registry values 
    //
    for (i = 0, pRegEntry = NICRegTable; i < NIC_NUM_REG_PARAMS; i++, pRegEntry++)
    {

        //
        // Read the registry value if the hConfigurationHandle is valid.
        //
        Status = NDIS_STATUS_FAILURE;
        pointer = ((PUCHAR)pNic) + pRegEntry->StructOffset + pRegEntry->FieldOffset;

        if (hConfigurationHandle != NULL)
        {

            //
            // Get the configuration value for a specific parameter.  Under NT the
            // parameters are all read in as DWORDs.
            //
            NdisReadConfiguration(&Status,
                                  &ReturnedValue,
                                  hConfigurationHandle,
                                  &pRegEntry->RegName,
                                  (enum _NDIS_PARAMETER_TYPE)pRegEntry->Type);

            //
            // If the parameter was present,then check its value for validity.
            //
            if (Status == NDIS_STATUS_SUCCESS) 
            {
                if ((pRegEntry->Type == NdisParameterInteger) || (pRegEntry->Type == NdisParameterHexInteger))
                {
                    
                    //
                    // Check that param value is not too small or too large
                    //
                    if (ReturnedValue->ParameterData.IntegerData < pRegEntry->Min ||
                        ReturnedValue->ParameterData.IntegerData > pRegEntry->Max)
                    {
                        value = pRegEntry->Default;
                    }
                    else
                    {
                        value = ReturnedValue->ParameterData.IntegerData;
                    }

                }
                else 
                {
                    ASSERT(FALSE);
                    continue;
                }
            }
        }

        //
        // If the configuration handle is invalid or if we failed to read the
        // registry value, use the default value.
        //
        if (Status != NDIS_STATUS_SUCCESS)
        {

            //
            // If this registry value is required, we fail.
            //
            if (pRegEntry->bRequired) 
            {
                ASSERT(FALSE);
                Status = NDIS_STATUS_FAILURE;
                break;
            }
            else 
            {
                if (pRegEntry->Type == NdisParameterInteger || pRegEntry->Type == NdisParameterHexInteger) 
                {
                    value = pRegEntry->Default;
                }
                else 
                {
                    ASSERT(FALSE);
                    continue;
                }
            }

            Status = NDIS_STATUS_SUCCESS;
        }

        //
        // Store the value in the adapter structure.
        //
        switch (pRegEntry->FieldSize) 
        {
            case 1:
                *((PUCHAR) pointer) = (UCHAR) value;
                break;

            case 2:
                *((PUSHORT) pointer) = (USHORT) value;
                break;

            case 4:
                *((PULONG) pointer) = (ULONG) value;
                break;

            default:
                break;
        }
    }

    //
    // Read NetworkAddress registry value. Use it as the current address if any.
    //
    if (Status == NDIS_STATUS_SUCCESS && hConfigurationHandle != NULL) 
    {
        NdisReadNetworkAddress(&Status,
                               (void **)&NetworkAddress,
                               &Length,
                               hConfigurationHandle);

        //
        // If there is a NetworkAddress override in registry,use it 
        //
        if ((Status == NDIS_STATUS_SUCCESS) && (Length == ETH_LENGTH_OF_ADDRESS)) 
        {
            if (!ETH_IS_MULTICAST(NetworkAddress) && !ETH_IS_BROADCAST(NetworkAddress)) 
            {
                if ((NetworkAddress[0] == 0x00) &&
                    (NetworkAddress[1] == 0x00) &&
                    (NetworkAddress[2] == 0x00) &&
                    (NetworkAddress[3] == 0x00) &&
                    (NetworkAddress[4] == 0x00) &&
                    (NetworkAddress[5] == 0x00)) 
                { // Network addr = 00 00 00 00 00 00
                    pNic->CardInfo.bOverrideAddress = FALSE;
                }
                else 
                {
                    ETH_COPY_NETWORK_ADDRESS(pNic->CardInfo.MacAddr,NetworkAddress);
                    ETH_COPY_NETWORK_ADDRESS(pNic->ManagementInfo.BssId,NetworkAddress);
                    pNic->CardInfo.bOverrideAddress = TRUE;
                }
            }
        }

        Status = NDIS_STATUS_SUCCESS;
    }
}

BOOLEAN
Hw11StatusHasChanged(
    IN  PNIC        pNic
    )
{
    UNREFERENCED_PARAMETER(pNic);
    return FALSE;
}

BOOLEAN
Hw11NicIsResetting(
    IN  PNIC pNic
    )
{
    UNREFERENCED_PARAMETER(pNic);
    return FALSE;
}

ULONG64
Hw11GetLinkSpeed(
    IN  PNIC pNic
    )
{
    // Return the current link speed or default (non-zero) value 
    return HwDataRateToLinkSpeed((UCHAR)pNic->ManagementInfo.CurrentTXDataRate);
}

ULONG
Hw11GetInterruptLevel(
    IN  PNIC    pNic
    )
{
    return pNic->CardInfo.InterruptLevel;
}

VOID
Hw11EnableInterrupt(
    IN  PNIC pNic
    )
{
    WritePortUshort(pNic, IMR, pNic->CardInfo.IntrMask);
}

VOID
Hw11DisableInterrupt(
    IN  PNIC pNic
    )
{
    WritePortUshort(pNic, IMR, 0);
}

BOOL
Hw11InterruptEnabled(
    IN  PNIC pNic
    )
{
    USHORT  Data;

    ReadPortUshort(pNic, IMR, &Data);
    return (Data != 0);
}


BOOLEAN
Hw11InterruptRecognized(
    IN  PNIC pNic,
    OUT PBOOLEAN pbQueueMiniportHandleInterrupt
    )
{
    USHORT  isr;
    PDOT11_PHY_FRAME_STATISTICS pPhyStats = &pNic->StatisticsInfo.PhyCounters[Hw11QueryOperatingPhyId(pNic)];
    
    //
    // Read from ISR value from the hardware
    //
    ReadPortUshort(pNic, ISR, &isr);

    //
    // If surprise removal has occured,set the flag
    //
    if (isr == 0xFFFF) 
    {
        pNic->CardInfo.SurpriseRemoved = TRUE;
        *pbQueueMiniportHandleInterrupt = FALSE;
        return FALSE;
    }

    //
    // Time critical job handling
    //
    if (HW_IS_IN_STA_ADHOC_MODE(pNic))
    {    
        if (isr & IMR_TBDOK)
        {

             //
             //Add by maddest for OID_RT_GET_TX_OK and OID_RT_GET_TX_ERR
             //
             pNic->StatisticsInfo.NumTxBeaconOk++;
             pNic->ManagementInfo.bAdhocCoordinator=TRUE;
		 
            //
            // Update the sequence number in the packets
            //
            UpdateBeaconSequenceNumber(pNic);
        }
        
		
        //
        //Add by maddest for OID_RT_GET_TX_OK and OID_RT_GET_TX_ERR
        //		
        else if(isr & IMR_TBDER)
        {
            pNic->StatisticsInfo.NumTxBeaconErr++;
            pNic->ManagementInfo.bAdhocCoordinator=FALSE;		   
        }

        CheckBeacon(pNic,isr);
        
        if (isr & IMR_ATIMInt)
        {
            //
            // The ATIM window has passed away.
            //
            if (pNic->ManagementInfo.PowerMgmtMode.dot11PowerMode == dot11_power_mode_powersave &&
                !pNic->ManagementInfo.bATIMPacketReceived)
            {
                HwDoze(pNic, (pNic->DupCurrentInfo.BeaconInterval - pNic->ManagementInfo.AtimWindow) << 10, TRUE);
            }

            pNic->ManagementInfo.bATIMPacketReceived = FALSE;
        }
    }
    
    //3 Check Normal Queue(This should be transparent for upper layer)
    while (HwGetTxBusyDescNum(pNic, NORMAL_QUEUE) > 0)
    {
        PTX_STATUS_DESC pDesc = (PTX_STATUS_DESC) HwGetNextDescToCheck(pNic, NORMAL_QUEUE, 0);
        if (!pDesc->OWN) 
        {    // Own bit 0
            HwIncrementTxNextDescToCheck(pNic, NORMAL_QUEUE, 1);
            if (pDesc == (PTX_STATUS_DESC)pNic->ManagementInfo.pPowerMgmtChangePktDesc) 
            {
                pNic->ManagementInfo.bPowerMgmtChangePktSent = TRUE;
                pNic->ManagementInfo.pPowerMgmtChangePktDesc = NULL;
            }

            //
            // Update statistics for packets sent using NORMAL_QUEUE (eg. mgmt packets)
            // 
            if (pDesc->TOK)
            {
                //
                // These counters are also incremented by the InterruptHandler.
                // The ISR/DPC relationship allows us to increment these
                // without locks
                //
                pPhyStats->ullTransmittedFrameCount++;
                pPhyStats->ullTransmittedFragmentCount++;
                if (pDesc->RC > 0)
                {
                    pPhyStats->ullRetryCount++;
                    if (pDesc->RC > 1)
                    {
                        pPhyStats->ullMultipleRetryCount++;
                    }
                }
            }
            else
            {
                pPhyStats->ullFailedCount++;
            }
        }
        else
            break;
    }
    
    if (isr & (IMR_ROK | IMR_RER | IMR_RXFOVW | IMR_RDU)) 
    {
        //
        // Response to Probe (Only for IBSS mode)
        //
        if (HW_IS_IN_STA_ADHOC_MODE(pNic)) 
        {
            HwHandleTimingCriticalPacket(pNic);
        }
    }

    if (isr & (IMR_RXFOVW|IMR_RDU)) 
    {
        pNic->StatisticsInfo.RxNoBuf++;
    }

    if (isr & pNic->CardInfo.IntrMask)
    {
        if (isr == IMR_BcnInt)
        {
            //
            // If this is only a beacon interrupt,no DPC is needed.
            // Beacons have already been handled at DIRQL
            //
            *pbQueueMiniportHandleInterrupt = FALSE;
        }
        else 
        {
            //
            // We need a DPC to handle this interrupt
            //
            *pbQueueMiniportHandleInterrupt = TRUE;
        }

        return TRUE;
    }
    else 
    {
        return FALSE;
    }
}


VOID
Hw11ClearInterrupt(
    IN  PNIC pNic
    )
{
    USHORT  Data;

    //
    // Read from ISR and write the value back to clear interrupt
    //
    ReadPortUshort(pNic, ISR, &Data);
    WritePortUshort(pNic, ISR, Data);        

    //
    // We undo what we did in Hw11ReceiveInterruptComplete: 
    // We clear the RDU bit (for next EnableInterrupt call)
    //
    InterlockedAnd((LONG*)&pNic->CardInfo.IntrMask, ~(IMR_RDU));
}

VOID
Hw11ReceiveInterruptComplete(
    IN  PNIC            pNic
    )
{
    LARGE_INTEGER           CurrentTime;

    //
    // If receives are available, we would temporarily enable the
    // RDU interrupt to ensure that we get interrupt again. Keeping this
    // interrupt on all the time would cause problems with Reset/Pause 
    // scenarios where we cannot empty the receive descriptors, and
    // so may keep getting interrupted
    //
    if (Hw11ReceiveIsAvailable(pNic))
    {
        //
        // New receives are available, but we didnt indicate
        // them in this interrupt. Enable RDU in IntrMask. This would be 
        // reset by the ClearInterrupt routine
        //
        InterlockedOr((LONG*)&pNic->CardInfo.IntrMask, IMR_RDU);
    }

    //
    // If we are supposed to turn off the RF due to power management, do
    // it now
    //
    if (pNic->ManagementInfo.PowerMgmtMode.dot11PowerMode == dot11_power_mode_powersave)
    {
        if (pNic->ManagementInfo.bSleepOnInterruptComplete)
        {
            // Sleep
            NdisGetCurrentSystemTime(&CurrentTime);
            CurrentTime.QuadPart /= 10;

            if (pNic->ManagementInfo.WakeupTime > (ULONGLONG)CurrentTime.QuadPart)
            {
                HwDoze(pNic, 
                    (ULONG)(pNic->ManagementInfo.WakeupTime - (ULONGLONG)CurrentTime.QuadPart),
                    FALSE
                    );
            }
            
            pNic->ManagementInfo.bSleepOnInterruptComplete = FALSE;
        }
    }
}

VOID
Hw11Shutdown(
    IN  PNIC pNic)
{
    Hw11HaltNic(pNic);
}

VOID
Hw11HaltNic(
    IN  PNIC pNic)
{
    //
    // No I/O if device has been surprise removed
    //
    if (pNic->CardInfo.SurpriseRemoved == FALSE)
    {
        UpdatePortUchar(pNic, MSR, &0XF3);      // default network type to 'No  Link'
        WritePortUchar(pNic, CMDR, CR_RST);     // disable tx/rx
        NdisStallExecution(200000);             // Cannot call NdisMSleep, may be called at DISPATCHER level.
        SetRFPowerState(pNic, RF_OFF);
    }
}

VOID
Hw11DevicePnPEvent(
    IN  PNIC  pNic,
    IN  NDIS_DEVICE_PNP_EVENT DevicePnPEvent,
    IN  PVOID InformationBuffer,
    IN  ULONG InformationBufferLength
    )
{
    UNREFERENCED_PARAMETER(InformationBuffer);
    UNREFERENCED_PARAMETER(InformationBufferLength);

    if (DevicePnPEvent == NdisDevicePnPEventSurpriseRemoved)
    {
        //
        // If hardware has been surprise removed,remember that.
        // We have to make sure we do not try to do any I/O on ports
        // if device has been surprise removed.
        //
        pNic->CardInfo.SurpriseRemoved = TRUE;

        //
        // We must stop advertising sending beacons and probes.
        // as the hardware is no longer present
        //
        pNic->ManagementInfo.bAdvertiseBSS = FALSE;
    }
}

NDIS_STATUS
HwParsePciConfiguration(
    IN  PNIC pNic,
    IN  PUCHAR pucBuffer,
    IN  ULONG ulBufferSize
    )
{
    NDIS_STATUS             ndisStatus = NDIS_STATUS_ADAPTER_NOT_FOUND;
    NDIS_ERROR_CODE         ErrorCode = NDIS_ERROR_CODE_ADAPTER_NOT_FOUND;
    PPCI_COMMON_CONFIG      pPciConfig = (PPCI_COMMON_CONFIG) pucBuffer;
    USHORT                  usPciCommand;
    ULONG                   uResult, ErrorValue = 0;

    UNREFERENCED_PARAMETER(ulBufferSize);
    MPVERIFY(ulBufferSize == HW_PCI_CONFIG_BUFFER_LENGTH);
    MPVERIFY(pucBuffer);

    __try 
    {
        pNic->CardInfo.RevisionID  = pPciConfig->RevisionID;
        pNic->CardInfo.SubVendorID = pPciConfig->u.type0.SubVendorID;
        pNic->CardInfo.SubSystemID = pPciConfig->u.type0.SubSystemID;

        usPciCommand = pPciConfig->Command;
        if ((usPciCommand & PCI_ENABLE_WRITE_AND_INVALIDATE) && (pNic->CardInfo.MWIEnable))
            pNic->CardInfo.MWIEnable = TRUE;
        else
            pNic->CardInfo.MWIEnable = FALSE;

        //
        // Enable bus matering if it isn't enabled by the BIOS
        //
        if (!(usPciCommand & PCI_ENABLE_BUS_MASTER)) 
        {
            MpTrace(COMP_INIT_PNP,
                    DBG_SERIOUS,
                    ("Bus master is not enabled by BIOS! usPciCommand=%x\n", usPciCommand));

            usPciCommand |= CMD_BUS_MASTER;

            uResult = NdisMSetBusData(pNic->MiniportAdapterHandle,
                                      PCI_WHICHSPACE_CONFIG,
                                      FIELD_OFFSET(PCI_COMMON_CONFIG,Command),
                                      &usPciCommand,
                                      sizeof(USHORT));

            if (uResult != sizeof(USHORT))
            {
                MpTrace(COMP_INIT_PNP,
                        DBG_SERIOUS,
                        ("Writing to PCI bus failed! uResult=%d\n",uResult));
                ErrorValue = ERRLOG_WRITE_PCI_SLOT_FAILED;
                __leave;
            }

            uResult = NdisMGetBusData(pNic->MiniportAdapterHandle,
                                      pNic->CardInfo.SlotNumber,
                                      FIELD_OFFSET(PCI_COMMON_CONFIG, Command),
                                      &usPciCommand,
                                      sizeof(USHORT));

            if (uResult != sizeof(USHORT))
            {
                MpTrace(COMP_INIT_PNP,
                        DBG_SERIOUS,
                        ("Reading from PCI bus failed! ulResult=%d\n",uResult));
                ErrorValue = ERRLOG_READ_PCI_SLOT_FAILED;
                __leave;
            }

            if( !(usPciCommand & PCI_ENABLE_BUS_MASTER))
            {
                MpTrace(COMP_INIT_PNP,
                        DBG_SERIOUS,
                        ("Failed to enable bus master! usPciCommand=%x\n", usPciCommand));

                ErrorCode = NDIS_ERROR_CODE_ADAPTER_DISABLED;
                ErrorValue = ERRLOG_BUS_MASTER_DISABLED;
                __leave;
            }
        }

        MpTrace(COMP_INIT_PNP, DBG_NORMAL, ("Bus master is enabled. usPciCommand=%x\n", usPciCommand));
        ndisStatus = NDIS_STATUS_SUCCESS;
    }
    __finally 
    {
        if (ndisStatus != NDIS_STATUS_SUCCESS) 
        {
            //
            // Write the specific error code in the event log
            //
            NdisWriteErrorLogEntry(pNic->MiniportAdapterHandle,
                                   ErrorCode,
                                   1,
                                   ErrorValue);
        }
    }

    return ndisStatus;
}


NDIS_STATUS
Hw11FindAdapter(
    IN  PNIC pNic,
    OUT NDIS_ERROR_CODE *ErrorCode,
    OUT PULONG ErrorValue
    )
{
    ULONG                   size;
    NDIS_STATUS             ndisStatus = NDIS_STATUS_SUCCESS;
    UCHAR                   buffer[HW_PCI_CONFIG_BUFFER_LENGTH];
    PPCI_COMMON_CONFIG      pPciConfig = (PPCI_COMMON_CONFIG) buffer;
    BOOLEAN                 iDcheckFalse = FALSE;


    //
    // Make sure adapter is present on the bus.
    // If present,verify the PCI configuration values.
    //
    size = NdisMGetBusData(pNic->MiniportAdapterHandle,
                           PCI_WHICHSPACE_CONFIG,
                           FIELD_OFFSET(PCI_COMMON_CONFIG,VendorID),
                           pPciConfig,
                           HW_PCI_CONFIG_BUFFER_LENGTH);
    
    if (size != HW_PCI_CONFIG_BUFFER_LENGTH) 
    {
        MpTrace(COMP_INIT_PNP,
                DBG_SERIOUS,
                ("NdisReadPciSlotInformation failed. Number of bytes of Config info returned is %d\n", size));

        *ErrorCode = NDIS_ERROR_CODE_ADAPTER_NOT_FOUND;
        *ErrorValue = ERRLOG_READ_PCI_SLOT_FAILED;
        return NDIS_STATUS_ADAPTER_NOT_FOUND;
    }

    //Check device ID and Vendor ID
    if (pPciConfig->VendorID != HW11_PCI_VENDOR_ID || 
        pPciConfig->DeviceID != HW11_PCI_8180_DEVICE_ID && pPciConfig->DeviceID != HW11_PCI_8185_DEVICE_ID) 
    {

        iDcheckFalse= TRUE;
    }

    //Check revision ID, avoid to misuse the future rivision
    if(pPciConfig->DeviceID == HW11_PCI_8185_DEVICE_ID)
    {
        if(pPciConfig->RevisionID!=HW_PCI_8185_REVISION_ID1)
            iDcheckFalse= TRUE;
    }
        
    if(iDcheckFalse)
    {
        MpTrace(COMP_INIT_PNP,
                DBG_SERIOUS,
                ("VendorID/DeviceID don't match - %x/%x\n", pPciConfig->VendorID, pPciConfig->DeviceID));

        *ErrorCode = NDIS_ERROR_CODE_ADAPTER_NOT_FOUND;
        *ErrorValue = ERRLOG_VENDOR_DEVICE_MISMATCH;
        return NDIS_STATUS_ADAPTER_NOT_FOUND;
    }

    //
    // Allow the hardware to look at PCI config information.
    //
    ndisStatus = HwParsePciConfiguration(pNic, buffer, size);
    if (ndisStatus != NDIS_STATUS_SUCCESS) 
    {
        MpTrace(COMP_INIT_PNP, 
                DBG_SERIOUS, 
                ("Failed Hw11ParsePciConfiguration. Status = 0x%08x\n", ndisStatus));
    }

    return ndisStatus;
}



NDIS_STATUS
Hw11AddAdapterResource(
    IN  PNIC pNic,
    IN  PCM_PARTIAL_RESOURCE_DESCRIPTOR pResource
    )
{
    NDIS_STATUS         ndisStatus = NDIS_STATUS_SUCCESS;
    NDIS_ERROR_CODE     ErrorCode = NDIS_STATUS_SUCCESS;
    ULONG               ErrorValue = 0;
    
    switch (pResource->Type) 
    {
        case CmResourceTypePort:
            pNic->CardInfo.IoBaseAddress = NdisGetPhysicalAddressLow(pResource->u.Port.Start); 
            pNic->CardInfo.IoRange = pResource->u.Port.Length;

            MpTrace(COMP_INIT_PNP, DBG_LOUD, ("IoBaseAddress = 0x%x\n", pNic->CardInfo.IoBaseAddress));
            MpTrace(COMP_INIT_PNP, DBG_LOUD, ("IoRange = x%x\n", pNic->CardInfo.IoRange));

            //
            // Map bus-relative IO range to system IO space
            //
            ndisStatus = NdisMRegisterIoPortRange((PVOID *)&pNic->CardInfo.PortOffset,
                                                  pNic->MiniportAdapterHandle,
                                                  pNic->CardInfo.IoBaseAddress,
                                                  pNic->CardInfo.IoRange);
            if (ndisStatus != NDIS_STATUS_SUCCESS) 
            {
                MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("NdisMRegisterioPortRange failed\n"));
                ErrorCode = NDIS_ERROR_CODE_BAD_IO_BASE_ADDRESS;
                ErrorValue = ERRLOG_REGISTER_IO_PORT_RANGE_FAILED;
            }

            break;

        case CmResourceTypeInterrupt:
            pNic->CardInfo.InterruptLevel = pResource->u.Interrupt.Level;
            
            MpTrace(COMP_INIT_PNP, DBG_LOUD, ("InterruptLevel = x%x\n", pNic->CardInfo.InterruptLevel));
            break;

        case CmResourceTypeMemory:
            //
            // Hw11 CSR memory space should be 0x400,other memory is for 
            // flash address,a boot ROM address,etc.
            //
            if (pResource->u.Memory.Length <= 0x400)
            {
                pNic->CardInfo.MemPhysAddress = pResource->u.Memory.Start;
                
                MpTrace(COMP_INIT_PNP,
                        DBG_LOUD,
                        ("MemPhysAddress(Low) = 0x%0x\n", NdisGetPhysicalAddressLow(pNic->CardInfo.MemPhysAddress)));
                MpTrace(COMP_INIT_PNP,
                        DBG_LOUD,
                        ("MemPhysAddress(High) = 0x%0x\n", NdisGetPhysicalAddressHigh(pNic->CardInfo.MemPhysAddress)));

                //
                // Map bus-relative registers to virtual system-space
                //
                ndisStatus = NdisMMapIoSpace((PVOID *) &(pNic->CardInfo.CSRAddress),
                                             pNic->MiniportAdapterHandle,
                                             pNic->CardInfo.MemPhysAddress,
                                             NIC_MAP_IOSPACE_LENGTH);
                if (ndisStatus != NDIS_STATUS_SUCCESS) 
                {
                    MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("NdisMMapIoSpace failed\n"));
                    ErrorCode = NDIS_ERROR_CODE_RESOURCE_CONFLICT;
                    ErrorValue = ERRLOG_MAP_IO_SPACE_FAILED;
                    break;
                }
            }
            else 
            {
                //
                // This memory resources is not what we are seeking. We will not use it.
                // This is not a fatal error
                //
                ndisStatus = NDIS_STATUS_NOT_ACCEPTED;
            }
            break;
    }

    if (ndisStatus != NDIS_STATUS_SUCCESS && ErrorCode != NDIS_STATUS_SUCCESS) 
    {
        NdisWriteErrorLogEntry(pNic->MiniportAdapterHandle,
                               ErrorCode,
                               1,
                               ErrorValue);
    }

    return ndisStatus;
}


VOID
Hw11SharedMemoryAllocateComplete(
    IN  PNIC                    pNic,
    IN  PVOID                   VirtualAddress,
    IN  PNDIS_PHYSICAL_ADDRESS  PhysicalAddress,
    IN  ULONG                   Length,
    IN  PVOID                   Context
    )
{
    NDIS_STATUS     ndisStatus;    
    PNIC_RX_FRAGMENT    pNicFragment;
    
    pNicFragment = (PNIC_RX_FRAGMENT)Context;
    if (VirtualAddress == NULL) 
    {
        MpTrace(COMP_RECV, DBG_SERIOUS, ("Failed to NdisMAllocateSharedMemoryAsync \n"));
        NdisFreeToNPagedLookasideList(&pNic->RxInfo.RecvFRAGMENTLookaside, pNicFragment);
    }
    else 
    {
        pNicFragment->RxBuffer = VirtualAddress;
        pNicFragment->RxBufferPhys = *PhysicalAddress;
        
        NdisAcquireSpinLock(&pNic->RxInfo.FragListLock);
        
        ndisStatus = Mp11AssociateRxFragment(pNic->pAdapter,pNicFragment, &pNicFragment->MpFragment);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace(COMP_RECV, DBG_SERIOUS, ("Failed to Mp11AssociateRxFragment\n"));
            NdisReleaseSpinLock(&pNic->RxInfo.FragListLock);
            NdisMFreeSharedMemory(pNic->MiniportAdapterHandle,
                                  Length,
                                  FALSE,
                                  VirtualAddress,
                                  *PhysicalAddress);
            pNicFragment->RxBuffer = NULL;
            NdisFreeToNPagedLookasideList(&pNic->RxInfo.RecvFRAGMENTLookaside, pNicFragment);
        }
        else
        {
            //
            // Give control of the RX_DESC in this fragment to the hardware
            //
            if (pNic->RxInfo.RxFragListLen >= pNic->RxInfo.RxTotalDescNum)
            {
                //
                // This descriptor is ready, but not yet available to the hardware
                // Store this in the unused fragments list
                // 
                InsertTailList(&pNic->RxInfo.RxUnusedFragList, &pNicFragment->FragmentList);
            }
            else 
            {
                //
                // Give control of the RX_DESC in this fragment to the hardware
                //
                HwReturnFragment(pNic, pNicFragment); 

                //
                // Add this fragment to the available Frag list
                //
                InsertTailList(&pNic->RxInfo.RxFragList, &pNicFragment->FragmentList);
                pNic->RxInfo.RxFragListLen++;
            }            
            NdisReleaseSpinLock(&pNic->RxInfo.FragListLock);
        }
    }
}

// Called at device IRQL (via SynchronizeWithInterrupt)
VOID
Hw11SetDevicePowerState(
    IN  PNIC                        pNic,
    IN  NDIS_DEVICE_POWER_STATE     DevicePowerState
    )
{
    UCHAR                   PMSupport = 0;
    UCHAR                   PMEStatus = 0;
    UCHAR                   NICPS;

    if (DevicePowerState == NdisDeviceStateD0)
    {
        //
        // Check if Power management enabled.
        //
        NdisMGetBusData(pNic->MiniportAdapterHandle,
                        pNic->CardInfo.SlotNumber,
                        PMID,
                        &PMSupport,
                        sizeof(PMSupport));

        if (PMSupport & 0x01)
        {
            NICPS = 0;
            NdisMSetBusData(pNic->MiniportAdapterHandle,
                            pNic->CardInfo.SlotNumber,
                            PMCSR,
                            &NICPS,
                            sizeof(NICPS));
        }

        //
        // Clear PME_Status
        //
        NdisMGetBusData(pNic->MiniportAdapterHandle,
                        pNic->CardInfo.SlotNumber,
                        PMCtl,
                        &PMEStatus,
                        sizeof(PMEStatus));

        PMEStatus |= 0x80;

        NdisMSetBusData(pNic->MiniportAdapterHandle,
                        pNic->CardInfo.SlotNumber,
                        PMCtl,
                        &PMEStatus,
                        sizeof(PMEStatus));
    }
    else
    {
        Hw11DisableInterrupt(pNic);

        UpdatePortUchar(pNic, MSR, &0XF3);      // default network type to 'No  Link'   
        WritePortUchar(pNic, CMDR, CR_RST);     // turn of LED
        NdisStallExecution(200000);
        SetRFPowerState(pNic, RF_OFF);
    }
}

NDIS_STATUS
Hw11QueryStatistics(
    IN PNIC             pNic,
    IN NDIS_OID         Oid,
    IN OUT PVOID        StatBuffer,
    IN OUT PULONG       BytesWritten
    )
{
    ULONG               PhyId;
    ULONGLONG           StatValue = 0;
    NDIS_STATISTICS_INFO    StatStruct;

    NdisZeroMemory(&StatStruct, sizeof(NDIS_STATISTICS_INFO));
    StatStruct.Header.Revision = NDIS_OBJECT_REVISION_1;
    StatStruct.Header.Type = NDIS_OBJECT_TYPE_DEFAULT;
    StatStruct.Header.Size = sizeof(NDIS_STATISTICS_INFO);

    StatStruct.SupportedStatistics = NDIS_STATISTICS_FLAGS_VALID_RCV_DISCARDS          |
                                     NDIS_STATISTICS_FLAGS_VALID_RCV_ERROR             |
                                     NDIS_STATISTICS_FLAGS_VALID_XMIT_ERROR            |
                                     NDIS_STATISTICS_FLAGS_VALID_DIRECTED_FRAMES_RCV   |
                                     NDIS_STATISTICS_FLAGS_VALID_DIRECTED_FRAMES_XMIT;
                                     
    //
    // Merge phy counters
    //
    for (PhyId = 0; 
            PhyId < pNic->ManagementInfo.pSupportedPhyTypes->uNumOfEntries; 
            PhyId++
        )
    {
        switch (Oid)
        {
            case OID_GEN_XMIT_OK:
                StatValue += pNic->StatisticsInfo.PhyCounters[PhyId].ullTransmittedFragmentCount;
                break;
                
            case OID_GEN_XMIT_ERROR:
                StatValue += pNic->StatisticsInfo.PhyCounters[PhyId].ullFailedCount;
                break;

            case OID_GEN_RCV_OK:
                StatValue += pNic->StatisticsInfo.PhyCounters[PhyId].ullReceivedFragmentCount;
                break;
            
            case OID_GEN_RCV_ERROR:
                StatValue += pNic->StatisticsInfo.PhyCounters[PhyId].ullFCSErrorCount;
                break;

            case OID_GEN_RCV_CRC_ERROR:
                StatValue += pNic->StatisticsInfo.PhyCounters[PhyId].ullFCSErrorCount;
                break;

            case OID_GEN_STATISTICS:
                StatStruct.ifInDiscards += pNic->StatisticsInfo.PhyCounters[PhyId].ullFCSErrorCount;
                StatStruct.ifInErrors += pNic->StatisticsInfo.PhyCounters[PhyId].ullFCSErrorCount;
                
                StatStruct.ifHCInUcastPkts += pNic->StatisticsInfo.PhyCounters[PhyId].ullReceivedFragmentCount;
                StatStruct.ifHCOutUcastPkts += pNic->StatisticsInfo.PhyCounters[PhyId].ullTransmittedFragmentCount;
                
                StatStruct.ifOutErrors += pNic->StatisticsInfo.PhyCounters[PhyId].ullFailedCount;
                break;
        }
    }

    //
    // For some OIDs, we add other stats
    //

    switch (Oid)
    {
        case OID_GEN_XMIT_ERROR:
            StatValue += pNic->StatisticsInfo.UcastCounters.ullTransmittedFailureFrameCount;
            StatValue += pNic->StatisticsInfo.McastCounters.ullTransmittedFailureFrameCount;
            break;
        
        case OID_GEN_RCV_ERROR:
            StatValue += pNic->StatisticsInfo.UcastCounters.ullReceivedFailureFrameCount;
            StatValue += pNic->StatisticsInfo.McastCounters.ullReceivedFailureFrameCount;
            break;

        case OID_GEN_RCV_NO_BUFFER:
            StatValue = pNic->StatisticsInfo.RxNoBuf;
            break;

        case OID_GEN_STATISTICS:
            StatStruct.ifInDiscards += (pNic->StatisticsInfo.RxNoBuf +
                                        pNic->StatisticsInfo.UcastCounters.ullReceivedFailureFrameCount +
                                        pNic->StatisticsInfo.McastCounters.ullReceivedFailureFrameCount
                                        );
        
            StatStruct.ifInErrors += (pNic->StatisticsInfo.UcastCounters.ullReceivedFailureFrameCount +
                                        pNic->StatisticsInfo.McastCounters.ullReceivedFailureFrameCount
                                        );
            
            StatStruct.ifOutErrors += (pNic->StatisticsInfo.UcastCounters.ullTransmittedFailureFrameCount +
                                        pNic->StatisticsInfo.McastCounters.ullTransmittedFailureFrameCount
                                        );

            break;
    }

    if (Oid == OID_GEN_STATISTICS)
    {
        NdisMoveMemory(StatBuffer, &StatStruct, sizeof(NDIS_STATISTICS_INFO));    
        *BytesWritten = sizeof(NDIS_STATISTICS_INFO);
    }
    else
    {    
        NdisMoveMemory(StatBuffer, &StatValue, sizeof(ULONGLONG));
        *BytesWritten = sizeof(ULONGLONG);
    }

    return NDIS_STATUS_SUCCESS;
}

void 
HwGetVersion(
    IN  PNIC pNic
    )
{
    ULONG            TCRContent;

    ReadPortUlong(pNic, TCR, &TCRContent);
    
    switch (TCRContent & 0x0e000000) 
    {
        case 0x04000000:    // version A-D
            pNic->CardInfo.VersionID = VERSION_8180_D;
            pNic->CardInfo.SoftwareSeq = FALSE;
            break;

        case 0x06000000:    // version F
            pNic->CardInfo.VersionID = VERSION_8180_F; 
            pNic->CardInfo.SoftwareSeq = TRUE;
            break;

        case 0x08000000:    // RTL8185 version A~C
            pNic->CardInfo.VersionID = VERSION_8185_C;
            pNic->CardInfo.SoftwareSeq = TRUE;
            break;

        case 0x0A000000:    // RTL8185 version D
            pNic->CardInfo.VersionID = VERSION_8185_D;
            pNic->CardInfo.SoftwareSeq = TRUE;
            break;

        default:
            pNic->CardInfo.VersionID = VERSION_8185_C;
            pNic->CardInfo.SoftwareSeq = TRUE;
            break;
    }
}

void 
HwGetBusType(
    IN  PNIC pNic
    )
{
    UCHAR    tmpCfg3;
    
    ReadPortUchar(pNic, CONFIG3, &tmpCfg3);
    
    if (tmpCfg3 & Config3_CardBEn) 
    {
        pNic->CardInfo.BusType = BUS_TYPE_CARDBUS;
    }
    else if (tmpCfg3 & Config3_CLKRUN_En) 
    {
        pNic->CardInfo.BusType = BUS_TYPE_MINIPCI;
    }
    else
    {
        pNic->CardInfo.BusType = BUS_TYPE_PCI;
    }
}

#define ROL32(A,n)      ((A << n) | ((A >> (32 - n)) & ((1UL << n) - 1)))
#define ROR32(A,n)      ROL32(A, (32 - n))

INLINE 
VOID
HwMICBlock(
    PULONG  L,
    PULONG  R
    )
{
    *R ^= ROL32(*L, 17);
    *L += *R;
    *R ^= ((*L & 0xff00ff00) >> 8) | ((*L & 0x00ff00ff) << 8);
    *L += *R;
    *R ^= ROL32(*L, 3);
    *L += *R;
    *R ^= ROR32(*L, 2);
    *L += *R;
}

NDIS_STATUS
HwCalculateMIC(
    IN  PNET_BUFFER     NetBuffer,
    IN  UCHAR           Priority,
    IN  PUCHAR          MICKey,
    OUT PUCHAR          MICData
    )
{
    ULONG                   L, R;
    ULONG                   length;
    PMDL                    mdl;
    ULONG                   offset;
    PUCHAR                  bytePtr;
    ULONG                   index;
    ULONG                   count;
    ULONG                   dataSize;
    ULONG                   data;
    PUCHAR                  SA;
    PUCHAR                  DA;
    ULONG                   headerSize;
    PDOT11_DATA_LONG_HEADER dataHeader;

    // 
    // Note: only the first MDL is guaranteed to be mapped to system virtual space.
    //

    //
    // Find data header.
    //
    mdl = NET_BUFFER_CURRENT_MDL(NetBuffer);
    dataHeader = Add2Ptr(mdl->MappedSystemVa, NET_BUFFER_CURRENT_MDL_OFFSET(NetBuffer));

    //
    // Find SA, DA and header size.
    //
    if (dataHeader->FrameControl.ToDS)
    {
        DA = dataHeader->Address3;
        if (dataHeader->FrameControl.FromDS) 
        {
            headerSize = sizeof(DOT11_DATA_LONG_HEADER);
            SA = dataHeader->Address4;
        } 
        else 
        {
            headerSize = sizeof(DOT11_DATA_SHORT_HEADER);
            SA = dataHeader->Address2;
        }
    } 
    else 
    {
        headerSize = sizeof(DOT11_DATA_SHORT_HEADER);
        DA = dataHeader->Address1;
        if (dataHeader->FrameControl.FromDS) 
        {
            SA = dataHeader->Address3;
        } 
        else 
        {
            SA = dataHeader->Address2;
        }
    }

    //
    // Find the size of data the MIC is calculated on.
    //
    dataSize = NET_BUFFER_DATA_LENGTH(NetBuffer) - headerSize;
    length = 16 + dataSize + 5;                     // MSDU + 5 bytes pad (one 0x5a, four 0s)
    if (length & 0x03)
    {
        length += 4 - (length & 0x03);              // extra 0-3 bytes of 0s pad
    }
    length >>= 2;

    //
    // Find the starting offset for actual data (payload).
    // Caller guarantees that the header is in one single MDL.
    //
    offset = NET_BUFFER_CURRENT_MDL_OFFSET(NetBuffer) + headerSize;
    ASSERT(offset <= mdl->ByteCount);
    bytePtr = Add2Ptr(mdl->MappedSystemVa, offset);

    //
    // Initial L and R value from MIC key.
    //
    L = *((ULONG UNALIGNED *)MICKey);
    R = *((ULONG UNALIGNED *)(MICKey + 4));

    //
    // Loop to calculate the MIC
    //
    for (index = 0; index < length - 1; index++)
    {
        switch (index)
        {
            case 0:
                data = *((ULONG UNALIGNED *)DA);
                break;

            case 1:
                data = *((USHORT UNALIGNED *)SA);
                data <<= 16;
                data |= *((USHORT UNALIGNED *)(DA + 4));
                break;

            case 2:
                data = *((ULONG UNALIGNED *)(SA + 2));
                break;

            case 3:
                data = Priority;
                break;

            default:
                //
                // Data
                //
                if (offset + 4 <= mdl->ByteCount && (index - 4) * 4 + 4 <= dataSize)
                {
                    //
                    // We can get the whole ULONG in contiguous virtual memory.
                    //
                    data = *((ULONG UNALIGNED *)bytePtr);
                    bytePtr += 4;
                    offset += 4;
                }
                else 
                {
                    //
                    // We can't get the whole ULONG in contiguous virtual memory.
                    // Get one byte at a time. 
                    //
                    count = 0;
                    data = 0;
                    while (count < 4)
                    {
                        ASSERT((index - 4) * 4 + count <= dataSize);
                        if ((index - 4) * 4 + count == dataSize)
                        {
                            //
                            // We are done reading. Append 0x5a at the end.
                            //
                            data |= 0x5a << (count * 8);
                            break;
                        }
                        else if (offset < mdl->ByteCount)
                        {
                            //
                            // We can get the next byte without going to next MDL
                            //
                            data |= ((ULONG)(*bytePtr)) << (count * 8);
                            bytePtr++;
                            offset++;
                            count++;
                        }
                        else 
                        {
                            //
                            // We are at the end of a MDL. Follow the link to
                            // traverse to the next MDL.
                            //
                            mdl = mdl->Next;
                            ASSERT(mdl);

                            //
                            // Map the new MDL to system virtual space.
                            //
                            bytePtr = NdisBufferVirtualAddressSafe(mdl, NormalPagePriority);
                            if (!bytePtr)
                            {
                                return NDIS_STATUS_RESOURCES;
                            }

                            offset = 0;
                        }
                    }
                }
        }
    
        L ^= data;
        HwMICBlock(&L, &R); 
    }

    HwMICBlock(&L, &R); 
    *((ULONG UNALIGNED *)MICData) = L;
    *((ULONG UNALIGNED *)(MICData + 4)) = R;

    return NDIS_STATUS_SUCCESS;
}

VOID
Hw11NotifyEventConnectionState(
    IN  PNIC            pNic,
    IN  BOOLEAN         bState
    )
{
    pNic->ManagementInfo.bDeviceConnected = bState;

    // when connection state is changed, reset counters for rate negotiation
    pNic->ManagementInfo.TotalRetryCount = 0;
    pNic->ManagementInfo.PacketsSentForTxRateCheck = 0;
    pNic->ManagementInfo.PrevTxDataRate = 0;
    pNic->ManagementInfo.TxRateIncreaseWaitCount = 0;
    pNic->ManagementInfo.TxRateIncreaseWaitRequired = 1;
}



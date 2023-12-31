/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    Hw_Oids.c

Abstract:
    Hw layer OID handling functions
    
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
#if DOT11_TRACE_ENABLED
#include "Hw_Oids.tmh"
#endif

#define TotalRegDomain      (sizeof(RegDomainMap) / sizeof(ULONG))
ULONG RegDomainMap [] = {
    DOT11_REG_DOMAIN_OTHER,
    DOT11_REG_DOMAIN_FCC,
    DOT11_REG_DOMAIN_DOC,
    DOT11_REG_DOMAIN_ETSI,
    DOT11_REG_DOMAIN_SPAIN,
    DOT11_REG_DOMAIN_FRANCE,
    DOT11_REG_DOMAIN_MKK,
    HW_REG_DOMAIN_MKK1,
    HW_REG_DOMAIN_ISRAEL
};

const USHORT ConvertChannelplanToDomain[] ={
	1,	//channel plan fcc map to domain FCC
	1,	//channel plan IC map to domain FCC
	2,	//ETSI map to ETSI
	3,	//Spain map to Spain
	4,	//France
	5,	//MKK
	6,	//MKK1
	7,	//Israel
	6,	//TELEC map to FCC
};

VOID
HwChannelSwitchRequestComplete(
    IN  PNIC    pNic
    )
{
    //
    // Currently OID_DOT11_CURRENT_CHANNEL should be pending. Complete it.
    // Remember to clear the completion handler before completing the OID.
    // A scan request will wrong cause a completion to occur otherwise.
    //
    pNic->ManagementInfo.ChannelSwitchedHandler = NULL;
    Mp11CompletePendedRequest(pNic->pAdapter, NDIS_STATUS_SUCCESS);
}

void
Hw11QueryOpModeCap(
    IN  PNIC pNic,
    OUT PDOT11_OPERATION_MODE_CAPABILITY pDot11OpModeCap
    )
{
    NdisMoveMemory(pDot11OpModeCap,
                   &pNic->ManagementInfo.OperationModeCapability,
                   sizeof(DOT11_OPERATION_MODE_CAPABILITY));
}

NDIS_STATUS
Hw11QueryOptionalCapability(
    IN  PNIC pNic,
    OUT PDOT11_OPTIONAL_CAPABILITY pDot11OptionalCapability
    )
{
    NdisMoveMemory(pDot11OptionalCapability,
                   &pNic->ManagementInfo.OptionalCapability,
                   sizeof(DOT11_OPTIONAL_CAPABILITY));

    return NDIS_STATUS_SUCCESS;
}

VOID
Hw11QueryOperationalRateSet(
    IN  PNIC            pNic,
    OUT PDOT11_RATE_SET pDot11RateSet,
    IN  BOOLEAN         selectedPhy 
    )
{
    PNICPHYMIB  PhyMib;
    ULONG       Index;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

    for (Index = 0; Index < PhyMib->OperationalRateSet.uRateSetLength; Index++) 
    {
        pDot11RateSet->ucRateSet[Index] = PhyMib->OperationalRateSet.ucRateSet[Index];
    }

    pDot11RateSet->uRateSetLength = Index;
}

VOID
Hw11QueryBasicRateSet(
    IN  PNIC            pNic,
    OUT PDOT11_RATE_SET pDot11RateSet,
    IN  BOOLEAN         selectedPhy 
    )
{
    PNICPHYMIB PhyMib;
    ULONG   Index;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

    for (Index = 0; Index < PhyMib->BasicRateSet.uRateSetLength; Index++) 
    {
        pDot11RateSet->ucRateSet[Index] = PhyMib->BasicRateSet.ucRateSet[Index];
    }

    pDot11RateSet->uRateSetLength = Index;
}

NDIS_STATUS
Hw11QuerySupportedPHYTypes(
    IN  PNIC pNic,
    IN  ULONG uNumMaxEntries,
    OUT PDOT11_SUPPORTED_PHY_TYPES pDot11SupportedPhyTypes
    )
{
    USHORT    Index;

    if (uNumMaxEntries < pNic->ManagementInfo.pSupportedPhyTypes->uNumOfEntries) 
    {
        pDot11SupportedPhyTypes->uTotalNumOfEntries = pNic->ManagementInfo.pSupportedPhyTypes->uNumOfEntries;    
        pDot11SupportedPhyTypes->uNumOfEntries = uNumMaxEntries;

        for (Index = 0; Index < uNumMaxEntries; Index++)
            pDot11SupportedPhyTypes->dot11PHYType[Index] = pNic->ManagementInfo.pSupportedPhyTypes->dot11PHYType[Index];
        
        return NDIS_STATUS_BUFFER_OVERFLOW;
    }
    else 
    {
        pDot11SupportedPhyTypes->uTotalNumOfEntries = pNic->ManagementInfo.pSupportedPhyTypes->uNumOfEntries;
        pDot11SupportedPhyTypes->uNumOfEntries = pNic->ManagementInfo.pSupportedPhyTypes->uNumOfEntries;
        
        for (Index = 0; Index < pNic->ManagementInfo.pSupportedPhyTypes->uNumOfEntries; Index++)
            pDot11SupportedPhyTypes->dot11PHYType[Index] = pNic->ManagementInfo.pSupportedPhyTypes->dot11PHYType[Index];
        
        return NDIS_STATUS_SUCCESS;
    }
}

BOOLEAN
Hw11IsPhyTypeSupported(
    IN  PNIC pNic,
    IN  DOT11_PHY_TYPE PhyType
    )
{
    USHORT    Index;

    for (Index = 0; Index < pNic->ManagementInfo.pSupportedPhyTypes->uNumOfEntries; Index++)
    {
        if (pNic->ManagementInfo.pSupportedPhyTypes->dot11PHYType[Index] == PhyType)
            return TRUE;
    }

    return FALSE;
}

DOT11_PHY_TYPE
Hw11QueryCurrentPhyType(
    IN  PNIC pNic
    )
{
    return pNic->ManagementInfo.OperatingPhyMIB->PhyType;
}

ULONG
Hw11FindSelectedPhyID(
	IN PNIC pNic,
	IN DOT11_PHY_TYPE PhyType
	)
{
	UCHAR i;

	for(i = (UCHAR)pNic->ManagementInfo.pSupportedPhyTypes->uNumOfEntries;i>0;i--)
	{
		if(PhyType == pNic->ManagementInfo.PhyMIB[i-1].PhyType)
		{
			return pNic->ManagementInfo.PhyMIB[i-1].PhyID;
		}
	}

	//if not found, use default
	return 0;
}

NDIS_STATUS
Hw11SetCurrentPhyType(
    IN PNIC pNic,
    IN DOT11_PHY_TYPE   PhyType
    )
{
    UCHAR channel= HW11_DEFAULT_CHANNEL;

    //
    // If it is already the current phy, we are done.
    //
    if (PhyType == pNic->ManagementInfo.OperatingPhyMIB->PhyType)
        return NDIS_STATUS_SUCCESS;

    //
    // Check if we support the phy type.
    //
    if (!Hw11IsPhyTypeSupported(pNic, PhyType))
        return NDIS_STATUS_CAPABILITY_UNAVAILABLE;

    // Set target wireless mode (maybe better as a workitem)
    if (PhyType == dot11_phy_type_ofdm)
    {
		channel = HW11_DEFAULT_CHANNEL_A;
    }
    else if(PhyType ==dot11_phy_type_hrdsss )
    {
		channel = HW11_DEFAULT_CHANNEL;
    }
    else
    {   
        //G mode
		channel = HW11_DEFAULT_CHANNEL;
    }

    //for wirelessmode
    pNic->ManagementInfo.SelectedPhyId = Hw11FindSelectedPhyID(pNic,PhyType);
	pNic->ManagementInfo.SelectedPhyMIB = pNic->ManagementInfo.PhyMIB+pNic->ManagementInfo.SelectedPhyId;

    //
    // Set the target channel depending on the phy type
    //
    HwSetChannel(pNic, channel, HwChannelSwitchRequestComplete);

    return NDIS_STATUS_PENDING;
}

ULONG
Hw11QueryOperatingPhyId(
    IN  PNIC pNic
    )
{
    return pNic->ManagementInfo.OperatingPhyId;
}

NDIS_STATUS
Hw11SetOperatingPhyId(
    IN PNIC pNic,
    IN  ULONG PhyId
    )
{
    if (PhyId >= pNic->ManagementInfo.pSupportedPhyTypes->uNumOfEntries)
    {
        return NDIS_STATUS_INVALID_DATA;
    }
    else if (PhyId != pNic->ManagementInfo.OperatingPhyId)
    {
        //
        // Since it is not a OID request, we can't call HwSetChannel, which will
        // complete the currently pending OID.
        //
        pNic->ManagementInfo.OperatingPhyId = PhyId;        
        HwSetChannelSync(pNic, pNic->ManagementInfo.PhyMIB[PhyId].Channel);
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_SUCCESS;
    }
}

ULONG
Hw11QuerySelectedPhyId(
    IN  PNIC pNic
    )
{
    return pNic->ManagementInfo.SelectedPhyId;
}

NDIS_STATUS
Hw11SetSelectedPhyId(
    IN  PNIC pNic,
    IN  ULONG PhyId
    )
{
    if (PhyId >= pNic->ManagementInfo.pSupportedPhyTypes->uNumOfEntries)
    {
        return NDIS_STATUS_INVALID_DATA;
    }
    else
    {
        MpTrace(COMP_OID, DBG_LOUD, (">>> Selected PhyId: %d <<<\n", PhyId));
        pNic->ManagementInfo.SelectedPhyId = PhyId;
        pNic->ManagementInfo.SelectedPhyMIB = pNic->ManagementInfo.PhyMIB + PhyId;
        return NDIS_STATUS_SUCCESS;
    }
}

NDIS_STATUS
Hw11SetDesiredPhyIdList(
    IN  PNIC pNic,
    IN  ULONG*  PhyIDList,
    IN  ULONG   PhyIDCount
    )
{
    if (PhyIDCount < 1)
        return NDIS_STATUS_INVALID_DATA;

    if (PhyIDList[0] == DOT11_PHY_ID_ANY)
        return NDIS_STATUS_SUCCESS;
    
    if (pNic->ManagementInfo.CurrentOperationMode.uCurrentOpMode == DOT11_OPERATION_MODE_NETWORK_MONITOR)
    {
        //
        // In netmon mode, we immediately switch to the first PHY in the list
        //
        return Hw11SetOperatingPhyId(pNic, PhyIDList[0]);
    }
    else
    {
        //
        // Automatically set the PHY to the first PHY in the list. This
        // can change later
        //
        if (PhyIDList[0] != pNic->ManagementInfo.OperatingPhyId)
        {
            return Hw11SetOperatingPhyId(pNic, PhyIDList[0]);            
        }
    }

    return NDIS_STATUS_SUCCESS;
}

DOT11_DIVERSITY_SUPPORT
Hw11QueryDiversitySupport(
    IN  PNIC pNic
    )
{
    return pNic->ManagementInfo.DiversitySupport;
}


VOID
Hw11QuerySupportedPowerLevels(
    IN  PNIC pNic,
    OUT PDOT11_SUPPORTED_POWER_LEVELS pDot11SupportedPowerLevels
    )
{
    USHORT    Index;

    pDot11SupportedPowerLevels->uNumOfSupportedPowerLevels = pNic->ManagementInfo.SupportedPowerLevels.uNumOfSupportedPowerLevels;
    for( Index=0; Index < pNic->ManagementInfo.SupportedPowerLevels.uNumOfSupportedPowerLevels; Index++ )
        pDot11SupportedPowerLevels->uTxPowerLevelValues[Index] = pNic->ManagementInfo.SupportedPowerLevels.uTxPowerLevelValues[Index];
}


NDIS_STATUS
Hw11QueryRegDomainsSupportValue(
    IN  PNIC pNic,
    IN  ULONG uNumMaxEntries,
    OUT PDOT11_REG_DOMAINS_SUPPORT_VALUE pDot11RegDomainsSupportValue
    )

{
    USHORT    Index;

    if (uNumMaxEntries < pNic->ManagementInfo.pRegDomainsSupportValue->uNumOfEntries)
    {
        pDot11RegDomainsSupportValue->uNumOfEntries = uNumMaxEntries;
        pDot11RegDomainsSupportValue->uTotalNumOfEntries = pNic->ManagementInfo.pRegDomainsSupportValue->uNumOfEntries;
        for( Index=0; Index<uNumMaxEntries; Index++ )
        {
            pDot11RegDomainsSupportValue->dot11RegDomainValue[Index].uRegDomainsSupportIndex = pNic->ManagementInfo.pRegDomainsSupportValue->dot11RegDomainValue[Index].uRegDomainsSupportIndex;
            pDot11RegDomainsSupportValue->dot11RegDomainValue[Index].uRegDomainsSupportValue = pNic->ManagementInfo.pRegDomainsSupportValue->dot11RegDomainValue[Index].uRegDomainsSupportValue;
        }

        return NDIS_STATUS_BUFFER_OVERFLOW;
    }
    else
    {
        pDot11RegDomainsSupportValue->uNumOfEntries = pNic->ManagementInfo.pRegDomainsSupportValue->uNumOfEntries;
        pDot11RegDomainsSupportValue->uTotalNumOfEntries = pNic->ManagementInfo.pRegDomainsSupportValue->uNumOfEntries;

        for( Index=0; Index < pNic->ManagementInfo.pRegDomainsSupportValue->uNumOfEntries; Index++ )
        {
            pDot11RegDomainsSupportValue->dot11RegDomainValue[Index].uRegDomainsSupportIndex = pNic->ManagementInfo.pRegDomainsSupportValue->dot11RegDomainValue[Index].uRegDomainsSupportIndex;
            pDot11RegDomainsSupportValue->dot11RegDomainValue[Index].uRegDomainsSupportValue = pNic->ManagementInfo.pRegDomainsSupportValue->dot11RegDomainValue[Index].uRegDomainsSupportValue;
        }    

        return NDIS_STATUS_SUCCESS;
    }
    ///
}

NDIS_STATUS
Hw11QueryRecvSensitivityList(
    IN  PNIC pNic,
    IN  ULONG uMaxEntries,
    IN OUT PDOT11_RECV_SENSITIVITY_LIST pDot11RecvSensitivityList
    )
{
    NDIS_STATUS     ndisStatus = NDIS_STATUS_SUCCESS;
    ULONG           i;
    PNICPHYMIB      PhyMib = NULL;
    
    do
    {
        if (pDot11RecvSensitivityList->uPhyId >= pNic->ManagementInfo.pSupportedPhyTypes->uNumOfEntries)
        {
            MpTrace(COMP_OID, DBG_SERIOUS, ("Phy Id not supported by the NIC\n"));
            ndisStatus = NDIS_STATUS_CAPABILITY_UNAVAILABLE;
            break;
        }

        PhyMib = pNic->ManagementInfo.PhyMIB + pDot11RecvSensitivityList->uPhyId;

        pDot11RecvSensitivityList->uTotalNumOfEntries = 0;
        for (i = 0; i < MAX_NUM_SUPPORTED_RATES_V2; i++)
        {
            if (PhyMib->SupportedDataRatesValue.ucSupportedRxDataRatesValue[i] != 0)
                pDot11RecvSensitivityList->uTotalNumOfEntries++;
        }
        
        //
        // Find out how many entries can we place?
        //
        if (uMaxEntries < pDot11RecvSensitivityList->uTotalNumOfEntries)
        {
            pDot11RecvSensitivityList->uNumOfEntries = uMaxEntries;
            ndisStatus = NDIS_STATUS_INVALID_LENGTH;
        }
        else
        {
            pDot11RecvSensitivityList->uNumOfEntries = pDot11RecvSensitivityList->uTotalNumOfEntries;
            ndisStatus = NDIS_STATUS_SUCCESS;
        }

        MPVERIFY(pDot11RecvSensitivityList->uNumOfEntries >= 1 && pDot11RecvSensitivityList->uNumOfEntries <= 4);

        //
        // There is at least one element we can fill.
        //
        for (i = 0; i < pDot11RecvSensitivityList->uNumOfEntries; i++)
        {
            pDot11RecvSensitivityList->dot11RecvSensitivity[i].ucDataRate = PhyMib->SupportedDataRatesValue.ucSupportedRxDataRatesValue[i];           
            pDot11RecvSensitivityList->dot11RecvSensitivity[i].lRSSIMax = Hw11GetMaxRSSI(pNic, pDot11RecvSensitivityList->dot11RecvSensitivity[i].ucDataRate);
            pDot11RecvSensitivityList->dot11RecvSensitivity[i].lRSSIMin = Hw11GetMinRSSI(pNic, pDot11RecvSensitivityList->dot11RecvSensitivity[i].ucDataRate);
        }
    } while(FALSE);

    return ndisStatus;
}


void
HwSetChannel(
    IN  PNIC pNic,
    IN  UCHAR ucChannel,
    IN  HW_CHANNEL_SWITCH_COMPLETE_HANDLER ChannelSwitchCompleteHandler
    )
{
    //
    // Currently all requests to switch channel must be pended with
    // a completion handler provided
    //
    MPVERIFY(ChannelSwitchCompleteHandler);
    
    pNic->ManagementInfo.DestChannel = ucChannel;    // For WorkItem
    pNic->ManagementInfo.ChannelSwitchedHandler = ChannelSwitchCompleteHandler;

    NdisQueueIoWorkItem(
        pNic->ManagementInfo.SwChnlWorkItem,
        HwSwChnlWorkItem,
        pNic
        );    
}

void
HwSetChannelSync(
    IN  PNIC pNic,
    IN  UCHAR ucChannel
    )
{
    //
    // Switch channel synchroneously
    //
    
    pNic->ManagementInfo.DestChannel = ucChannel;
    pNic->ManagementInfo.ChannelSwitchedHandler = NULL;
    HwSwChnlWorkItem(pNic, NULL);
}

ULONG
Hw11GetCurrentChannelId(
    IN PNIC         pNic
    )
{
    return (ULONG)pNic->ManagementInfo.OperatingPhyMIB->Channel;
}

NDIS_STATUS
Hw11GetChannel(
    IN  PNIC         pNic,
    OUT PULONG       channel,
    IN  BOOLEAN      selectedPhy 
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

    if (PhyMib->PhyType == dot11_phy_type_dsss ||
        PhyMib->PhyType == dot11_phy_type_hrdsss ||
        PhyMib->PhyType == dot11_phy_type_erp)
    {
        *channel = (ULONG)PhyMib->Channel;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

NDIS_STATUS
Hw11GetOfdmFrequency(
    IN  PNIC        pNic,
    OUT PULONG      freq,
    IN  BOOLEAN     selectedPhy 
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

    if (PhyMib->PhyType == dot11_phy_type_ofdm)
    {
        *freq = (ULONG)PhyMib->Channel;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

NDIS_STATUS
Hw11SetChannel(
    IN PNIC         pNic,
    IN ULONG        channel,
    IN BOOLEAN      selectedPhy 
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

    if (PhyMib->PhyType == dot11_phy_type_dsss ||
        PhyMib->PhyType == dot11_phy_type_hrdsss ||
        PhyMib->PhyType == dot11_phy_type_erp)
    {
        PhyMib->Channel = (UCHAR)channel;
        if (PhyMib == pNic->ManagementInfo.OperatingPhyMIB)
        {
            HwSetChannel(pNic, (UCHAR)channel, HwChannelSwitchRequestComplete);
            return NDIS_STATUS_PENDING;
        }
        else
        {
            return NDIS_STATUS_SUCCESS;
        }
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

NDIS_STATUS
Hw11SetOfdmFrequency(
    IN PNIC         pNic,
    IN ULONG        freq,
    IN BOOLEAN      selectedPhy 
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

    if (PhyMib->PhyType == dot11_phy_type_ofdm)
    {
        PhyMib->Channel = (UCHAR)freq;
        if (PhyMib == pNic->ManagementInfo.OperatingPhyMIB)
        {
            HwSetChannel(pNic, (UCHAR)freq, HwChannelSwitchRequestComplete);
            return NDIS_STATUS_PENDING;
        }
        else
        {
            return NDIS_STATUS_SUCCESS;
        }
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}


NDIS_STATUS
Hw11QueryCCAModeSupported(
    IN  PNIC        pNic,
    OUT PULONG      value,
    IN  BOOLEAN     selectedPhy 
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

    if (PhyMib->PhyType == dot11_phy_type_dsss ||
        PhyMib->PhyType == dot11_phy_type_hrdsss ||
        PhyMib->PhyType == dot11_phy_type_erp)
    {
        *value = pNic->ManagementInfo.CCAModeSupported;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

NDIS_STATUS
Hw11QueryCurrentCCA(
    IN  PNIC        pNic,
    OUT PULONG      value,
    IN  BOOLEAN     selectedPhy 
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

    if (PhyMib->PhyType == dot11_phy_type_dsss ||
        PhyMib->PhyType == dot11_phy_type_hrdsss ||
        PhyMib->PhyType == dot11_phy_type_erp)
    {
        *value = pNic->ManagementInfo.CurrentCCAMode;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}


NDIS_STATUS
Hw11QueryEdThreshold(
    IN  PNIC         pNic,
    OUT PULONG       value,
    IN  BOOLEAN      selectedPhy 
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

    if (PhyMib->PhyType == dot11_phy_type_dsss ||
        PhyMib->PhyType == dot11_phy_type_hrdsss ||
        PhyMib->PhyType == dot11_phy_type_erp)
    {
        *value = pNic->ManagementInfo.EDThreshold;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

ULONG
Hw11QueryRTSThreshold(
    IN PNIC pNic
    )
{    //3 OK
    return pNic->DupCurrentInfo.RTS_Threshold;
}

NDIS_STATUS
Hw11SetRTSThreshold(
    IN PNIC pNic,
    IN ULONG uValue
    )
{    //3 OK
    if(uValue>2347)
        pNic->DupCurrentInfo.RTS_Threshold=2347;
    else
        pNic->DupCurrentInfo.RTS_Threshold=uValue;
    
    return NDIS_STATUS_SUCCESS;    
}

ULONG
Hw11QueryShortRetryLimit(
    IN PNIC pNic
    )
{    //3 OK
    return pNic->DupCurrentInfo.ShortRetryLimit;
}

ULONG
Hw11QueryLongRetryLimit(
    IN PNIC pNic
    )
{    //3 OK
    return pNic->DupCurrentInfo.LongRetryLimit;
}

ULONG
Hw11GetFragmentationThreshold(
    IN PNIC pNic
    )
{
    return pNic->DupCurrentInfo.Frag_Threshold;
}

NDIS_STATUS
Hw11SetFragmentationThreshold(
    IN PNIC pNic,
    IN ULONG uValue
    )
{
    if(uValue>2346)
        pNic->DupCurrentInfo.Frag_Threshold=2346;
    else if(uValue<256)
        pNic->DupCurrentInfo.Frag_Threshold=256;
    else    
        pNic->DupCurrentInfo.Frag_Threshold=uValue;
    
    return NDIS_STATUS_SUCCESS;
}

ULONG
Hw11QueryMaxTXMSDULifeTime(
    IN PNIC pNic
    )
{
    return pNic->DupCurrentInfo.MaxTxLifeTime;
}

ULONG
Hw11QueryMaxReceiveLifeTime(
    IN PNIC pNic
    )
{
    return pNic->DupCurrentInfo.MaxRxLifeTime;
}

ULONG
Hw11QueryCurrentRegDomain(
    IN PNIC pNic
    )
{    //3 OK
    if(pNic->RfInfo.RegDomain >= TotalRegDomain)
        return DOT11_REG_DOMAIN_OTHER;
    
    return RegDomainMap[pNic->RfInfo.RegDomain];
}

NDIS_STATUS
Hw11SetCurrentRegDomain(
    IN PNIC pNic,
    IN ULONG uValue
    )
{    //3 OK
    USHORT i;
    for(i=0;i<TotalRegDomain;i++)
    {
        if(RegDomainMap[i]==uValue)
            pNic->RfInfo.RegDomain=i;
    }
    pNic->RfInfo.ChannelPlan = DOMAIN_FROM_UI; //clear all channel settings, force it obey UI
    
    return NDIS_STATUS_SUCCESS;
}

PDOT11_MAC_ADDRESS
Hw11GetMACAddress(
    PNIC pNic
    )
{    //3 OK
    return (PDOT11_MAC_ADDRESS)pNic->CardInfo.MacAddr;
}

PDOT11_MAC_ADDRESS
Hw11GetCurrentBSSID(
    PNIC pNic
    )
{
    return (PDOT11_MAC_ADDRESS)pNic->ManagementInfo.BssId;
}

VOID
Hw11SetMACAddress(
    IN  PNIC                    pNic,
    IN  DOT11_MAC_ADDRESS       MacAddress
    )
{
    ETH_COPY_NETWORK_ADDRESS(pNic->CardInfo.MacAddr, MacAddress);
    MpTrace(COMP_INIT_PNP, DBG_LOUD, ("Setting Mac Address to %02x-%02x-%02x-%02x-%02x-%02x\n", 
        MacAddress[0], MacAddress[1], 
        MacAddress[2], MacAddress[3], 
        MacAddress[4], MacAddress[5]));
    
    HwSetNICAddress(pNic);
}

VOID
Hw11QueryStationId(
    IN PNIC pNic,
    IN DOT11_MAC_ADDRESS Dot11MacAddress
    )
{    //3 OK
    NdisMoveMemory(Dot11MacAddress,pNic->CardInfo.StationID,6);
}

ULONG
Hw11QueryMediumOccupancyLimit(
    IN PNIC pNic
    )
{
    return pNic->DupCurrentInfo.MediaOccupancyLimit;
}

BOOLEAN
Hw11QueryCFPollable(
    IN PNIC pNic
    )
{
    UNREFERENCED_PARAMETER(pNic);
    return FALSE;    
}

void
Hw11QueryPowerMgmtMode(
    IN PNIC pNic,
    OUT PDOT11_POWER_MGMT_MODE pDot11PowerMgmtMode
    )
{
    NdisMoveMemory(
        pDot11PowerMgmtMode,
        &pNic->ManagementInfo.PowerMgmtMode,
        sizeof(DOT11_POWER_MGMT_MODE));
}

NDIS_STATUS
Hw11CanTransitionPower(
    IN  PNIC    pNic,
    IN  NDIS_DEVICE_POWER_STATE NewDevicePowerState
    )
{
    //
    // Transition is always possible. If ever a need occurs for the driver
    // to veto a power transtion, we will do it here.
    //
    UNREFERENCED_PARAMETER(pNic);
    UNREFERENCED_PARAMETER(NewDevicePowerState);
    
    return NDIS_STATUS_SUCCESS;
}

ULONG
Hw11QueryBeaconPeriod(
    IN PNIC pNic
    )
{    //3 OK
    return pNic->DupCurrentInfo.BeaconInterval;
}

NDIS_STATUS
Hw11SetBeaconPeriod(
    IN PNIC pNic,
    IN ULONG uValue
    )
{    //3 OK
    pNic->DupCurrentInfo.BeaconInterval=uValue;
    LIMIT_BEACON_PERIOD(pNic->DupCurrentInfo.BeaconInterval);
    
    return NDIS_STATUS_SUCCESS;        
}

UCHAR
Hw11QueryDTIMCount(
    IN  PNIC    pNic
    )
{
    return (UCHAR)pNic->ManagementInfo.DtimCount;
}

ULONG
Hw11QueryDTIMPeriod(
    IN PNIC pNic
    )
{
    return pNic->ManagementInfo.DtimPeriod;
}

ULONG
Hw11QueryCurrentTXPowerLevel(
    IN PNIC pNic
    )
{
    return pNic->ManagementInfo.CurrentTxPowerLevel;
}

VOID
Hw11QueryCurrentOperationMode(
    PNIC pNic,
    PDOT11_CURRENT_OPERATION_MODE pDot11CurrentOperationMode
    )
{
    NdisMoveMemory(
        &pDot11CurrentOperationMode->uCurrentOpMode,
        &pNic->ManagementInfo.CurrentOperationMode.uCurrentOpMode,
        sizeof(ULONG)
        );
}

NDIS_STATUS
Hw11FrequencyBandsSupported(
    IN  PNIC        pNic,
    OUT PULONG      value,
    IN  BOOLEAN     selectedPhy
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

    if (PhyMib->PhyType == dot11_phy_type_ofdm)
    {
        *value = DOT11_FREQUENCY_BANDS_LOWER | DOT11_FREQUENCY_BANDS_MIDDLE;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_INVALID_STATE;
    }
}

NDIS_STATUS
Hw11SetOperationMode(
    PNIC pNic,
    PDOT11_CURRENT_OPERATION_MODE pDot11CurrentOperationMode
    )
{
    pNic->ManagementInfo.CurrentOperationMode.uCurrentOpMode = pDot11CurrentOperationMode->uCurrentOpMode;
    if ((pNic->ManagementInfo.CurrentOperationMode.uCurrentOpMode ==
        DOT11_OPERATION_MODE_EXTENSIBLE_STATION) ||
        (pNic->ManagementInfo.CurrentOperationMode.uCurrentOpMode ==
        DOT11_OPERATION_MODE_NETWORK_MONITOR))
    {
        pNic->RxInfo.ReceiveProcessingFunction = HwProcessReceiveSTAMode;
        
        if (pDot11CurrentOperationMode->uCurrentOpMode == DOT11_OPERATION_MODE_NETWORK_MONITOR)
        {
            //
            // Turn off encryption in the hardware
            //
            Hw11SetEncryption(pNic, TRUE, DOT11_CIPHER_ALGO_NONE);
        }
        
    }
    else
    {
        return NDIS_STATUS_NOT_ACCEPTED;
    }
    return NDIS_STATUS_SUCCESS;
}

ULONG
Hw11QueryATIMWindow(
    IN PNIC pNic
    )
{
    return (ULONG)pNic->ManagementInfo.AtimWindow;
}

NDIS_STATUS
Hw11SetATIMWindow(
    IN PNIC pNic,
    IN ULONG uValue
    )
{
    pNic->ManagementInfo.AtimWindow=(USHORT)uValue;
    LIMIT_BEACON_PERIOD(pNic->ManagementInfo.AtimWindow);
    
    return NDIS_STATUS_SUCCESS;                
}

NDIS_STATUS
HwTranslateChannelFreqToLogicalID(
    IN  PULONG  pulChannelFreqList,
    IN  ULONG   uNumChannels,
    OUT __out_ecount(uNumChannels) PULONG  uLogicalChannelList
    )
{
    ULONG i, uFreqDiffFromBase;
    NDIS_STATUS     ndisStatus = NDIS_STATUS_SUCCESS;

    NdisZeroMemory(uLogicalChannelList, uNumChannels * sizeof(ULONG));
    
    for (i=0; i<uNumChannels; i++)
    {
        //
        // Validate that frequences are correct
        //
        if (pulChannelFreqList[i] == 2484)
        {
            uLogicalChannelList[i] = 14;
            continue;
        }
        else if (pulChannelFreqList[i] >= 2412 && pulChannelFreqList[i] <= 2472)
        {
            uFreqDiffFromBase = pulChannelFreqList[i] - 2412 + 5;
        }
        else if (pulChannelFreqList[i] >= 5000 && pulChannelFreqList[i] <= 6000)
        {
            uFreqDiffFromBase = pulChannelFreqList[i] - 2412;
        }
        else
        {
            ndisStatus = NDIS_STATUS_INVALID_DATA;
            break;
        }

        if (uFreqDiffFromBase % 5 != 0)
        {
            ndisStatus = NDIS_STATUS_INVALID_DATA;
            break;
        }
        
        uLogicalChannelList[i] = uFreqDiffFromBase / 5;
    }

    return ndisStatus;
}

NDIS_STATUS
Hw11StartScan(
    PNIC                    pNic,
    PDOT11_SCAN_REQUEST_V2  pDot11ScanRequest,
    ULONG                   ScanRequestBufferLength
    )
{
    NDIS_STATUS             ndisStatus = NDIS_STATUS_SUCCESS;
    PDOT11_PHY_TYPE_INFO    pDot11PhyTypeInfo;
    BOOLEAN                 bUseDefaultParameters = FALSE;
    PCHANNEL_LIST           ChannelList;
    ULONG                   Index;

    UNREFERENCED_PARAMETER(ScanRequestBufferLength);

    do
    {
        if (pDot11ScanRequest->bRestrictedScan == FALSE)
        {
            if (pDot11ScanRequest->uNumOfPhyTypeInfos > 0)
            {
                //
                // Perform some validation on the scan request that is hw specific
                //
                pDot11PhyTypeInfo = (PDOT11_PHY_TYPE_INFO) 
                    (pDot11ScanRequest->ucBuffer + pDot11ScanRequest->uPhyTypeInfosOffset);

                //
                // Copy some of the information needed to perform the scan
                //        
                if (pDot11PhyTypeInfo->bUseParameters)
                {
                    // This is already validated by MP portion. Just checking
                    MPVERIFY(pDot11PhyTypeInfo->ChDescriptionType != ch_description_type_phy_specific);
                    
                    //
                    // We will be using parameters as defined by the caller
                    // 
                    pNic->ManagementInfo.ScanProbeDelay = pDot11PhyTypeInfo->uProbeDelay;
                    pNic->ManagementInfo.ScanChannelTime = pDot11PhyTypeInfo->uMinChannelTime + 
                        ((pDot11PhyTypeInfo->uMaxChannelTime - pDot11PhyTypeInfo->uMinChannelTime) / 2);

                    //
                    // Get the channel list specified by the caller
                    //
                    pNic->ManagementInfo.ScanChannelCount = pDot11PhyTypeInfo->uChannelListSize / 4;
                    MP_ALLOCATE_MEMORY(
                        pNic->MiniportAdapterHandle, 
                        &pNic->ManagementInfo.ScanChannelList,
                        pDot11PhyTypeInfo->uChannelListSize,
                        HW11_MEMORY_TAG
                        );
                    if (pNic->ManagementInfo.ScanChannelList == NULL)
                    {
                        ndisStatus = NDIS_STATUS_RESOURCES;
                        break;
                    }

                    if (pDot11PhyTypeInfo->ChDescriptionType == ch_description_type_logical)
                    {
                        //
                        // Channels are already logical numbers. Just copy them
                        //
                        NdisMoveMemory(
                            pNic->ManagementInfo.ScanChannelList,
                            pDot11PhyTypeInfo->ucChannelListBuffer,
                            pDot11PhyTypeInfo->uChannelListSize
                            );
                    }
                    else
                    {
                        //
                        // We have channel frequencies. Convert to logical numbers.
                        //
                        ndisStatus = HwTranslateChannelFreqToLogicalID(
                                        (PULONG) pDot11PhyTypeInfo->ucChannelListBuffer,
                                        pDot11PhyTypeInfo->uChannelListSize/4,
                                        pNic->ManagementInfo.ScanChannelList
                                        );

                        if (ndisStatus != NDIS_STATUS_SUCCESS)
                            break;
                    }
                }
                else
                {
                    //
                    // Use default values for this phy
                    //
                    bUseDefaultParameters = TRUE;
                }
            }
            else
            {
                //
                // There are no Phy Type Info object. Use default values
                //
                bUseDefaultParameters = TRUE;
            }
            
            if (bUseDefaultParameters == TRUE)
            {
                //
                // We will be using our own defaults
                //
                pNic->ManagementInfo.ScanProbeDelay = HW_DEFAULT_PROBE_DELAY;
                if ((pDot11ScanRequest->dot11ScanType == dot11_scan_type_passive) ||
                    (pDot11ScanRequest->dot11ScanType == (dot11_scan_type_passive | dot11_scan_type_forced)))
                {
                    // Park longer to passive scans.
                    pNic->ManagementInfo.ScanChannelTime = HW_DEFAULT_PASSIVE_SCAN_CHANNEL_PARK_TIME;
                }
                else
                {
                    pNic->ManagementInfo.ScanChannelTime = HW_DEFAULT_ACTIVE_SCAN_CHANNEL_PARK_TIME;
                }


                if((pNic->RfInfo.ChannelPlan & DOMAIN_FROM_EEPROM) ||
                    (pNic->RfInfo.ChannelPlan & DOMAIN_FROM_COUNTRY))
                {
                    if (Hw11IsPhyTypeSupported(pNic, dot11_phy_type_ofdm))
                    {
                        Index = pNic->RfInfo.ChannelPlan & CHANNELPLAN_MASK;

                        if (Index >= sizeof(ConvertChannelplanToDomain)/sizeof(USHORT))
                        {
                            ndisStatus = NDIS_STATUS_RESOURCES;
                            break;
                        }
                        ChannelList = &ChannelListAB[ConvertChannelplanToDomain[Index]];
                    }
                    else
                    {
                        Index = pNic->RfInfo.ChannelPlan & CHANNELPLAN_MASK;

                        if (Index >= sizeof(ConvertChannelplanToDomain)/sizeof(USHORT))
                        {
                            ndisStatus = NDIS_STATUS_RESOURCES;
                            break;
                        }
                        ChannelList = &ChannelListB[ConvertChannelplanToDomain[Index]];
                    }
                }
                else
                {
                    if (Hw11IsPhyTypeSupported(pNic, dot11_phy_type_ofdm))
                    {
                        ChannelList = &ChannelListAB[pNic->RfInfo.RegDomain];
                    }
                    else
                    {
                        ChannelList = &ChannelListB[pNic->RfInfo.RegDomain];
                    }
                }
        		
                pNic->ManagementInfo.ScanChannelCount = ChannelList->len;
                MP_ALLOCATE_MEMORY(
                    pNic->MiniportAdapterHandle, 
                    &pNic->ManagementInfo.ScanChannelList,
                    pNic->ManagementInfo.ScanChannelCount * sizeof(ULONG),
                    HW11_MEMORY_TAG
                    );
                if (pNic->ManagementInfo.ScanChannelList == NULL)
                {
                    ndisStatus = NDIS_STATUS_RESOURCES;
                    break;
                }

                NdisMoveMemory(
                    pNic->ManagementInfo.ScanChannelList,
                    ChannelList->channel,
                    pNic->ManagementInfo.ScanChannelCount * sizeof(ULONG)
                    );
            }
        }
        else
        {
            //
            // Normal extensible station driver by itself does not need to support restricted scan. However,
            // our station portion can use this for internal scan request
            //
            ULONG   uScanChannel;
            
            //
            // We are guaranteed to be in OP State as Mp portion verified it.
            //
            pNic->ManagementInfo.ScanProbeDelay = HW_DEFAULT_PROBE_DELAY;
            if ((pDot11ScanRequest->dot11ScanType == dot11_scan_type_passive) ||
                (pDot11ScanRequest->dot11ScanType == (dot11_scan_type_passive | dot11_scan_type_forced)))
            {
                // Park longer to passive scans.
                pNic->ManagementInfo.ScanChannelTime = HW_DEFAULT_PASSIVE_SCAN_CHANNEL_PARK_TIME;
            }
            else
            {
                pNic->ManagementInfo.ScanChannelTime = HW_DEFAULT_ACTIVE_SCAN_CHANNEL_PARK_TIME;
            }

            //
            // We will be scanning only the channel we are active on currently
            //
            pNic->ManagementInfo.ScanChannelCount = 1;
            
            MP_ALLOCATE_MEMORY(
                pNic->MiniportAdapterHandle,
                &pNic->ManagementInfo.ScanChannelList,
                sizeof(ULONG),
                HW11_MEMORY_TAG
                );
            if (pNic->ManagementInfo.ScanChannelList == NULL)
            {
                ndisStatus = NDIS_STATUS_RESOURCES;
                break;
            }

            uScanChannel = (ULONG) pNic->ManagementInfo.OperatingPhyMIB->Channel;

            NdisMoveMemory(
                pNic->ManagementInfo.ScanChannelList,
                &uScanChannel,
                sizeof(ULONG)
                );
        }
        
        //
        // Save the scan request structure that the caller passed
        //
        pNic->ManagementInfo.ScanRequest = pDot11ScanRequest;
        
        //
        // Reset scan state
        //
        pNic->ManagementInfo.ScanCancelOperation = FALSE;
        pNic->ManagementInfo.bScanCompleteIndicated = FALSE;
        pNic->ManagementInfo.ScanChannelSwitchTime = 0xffffffffffffffff;
        pNic->ManagementInfo.bScanInProgress = TRUE;
        pNic->ManagementInfo.ScanCurrentChannelIndex = 0;
        pNic->ManagementInfo.ScanCurrentState = ScanStateSwChnl;
        
        //
        // Wakeup the NIC if it is sleeping
        //
        if (HwAwake(pNic, FALSE) == FALSE)
        {
            // Radio is OFF
            ndisStatus = NDIS_STATUS_DOT11_POWER_STATE_INVALID;
            pNic->ManagementInfo.bScanInProgress = TRUE;
            break;
        }

    	//save/adjust HW related parameter that need to be saved/adjusted during scan
    	HwSaveAdjustBeforeScan(pNic);        
        
        NdisMSetTimer(&pNic->ManagementInfo.Timer_Scan, 0);
    } while(FALSE);

    if (ndisStatus != NDIS_STATUS_SUCCESS)
    {
        if (pNic->ManagementInfo.ScanChannelList != NULL)
            MP_FREE_MEMORY(pNic->ManagementInfo.ScanChannelList);

        //
        // In case of failure, caller free the structure
        //
        pNic->ManagementInfo.ScanRequest = NULL;
    }
    
    return ndisStatus;
}

VOID
Hw11CancelScan(
    PNIC    pNic
    )
{
    MPVERIFY(NDIS_CURRENT_IRQL() < DISPATCH_LEVEL);
    
    pNic->ManagementInfo.ScanCancelOperation = TRUE;

    // Wait for scan operation to be completed.
    while(pNic->ManagementInfo.bScanCompleteIndicated != TRUE)
    {
        MpTrace(COMP_SCAN, DBG_NORMAL, ("Waiting for scan operation to complete\n"));
        NdisMSleep(20 * 1000);
    }
}

void
Hw11StartBSSAdvertisment(
    IN PNIC    pNic)
{
    pNic->ManagementInfo.bAdvertiseBSS = TRUE;
    
    //3 This section should be call when IM set the driver to AP or ADHOC mode
    HwSetupBeacon(
        pNic, 
        pNic->TxInfo.TxBeaconBufVa[pNic->ManagementInfo.NextBeaconIndex], 
        HwGenerateBeacon(pNic, pNic->TxInfo.TxBeaconBufVa[pNic->ManagementInfo.NextBeaconIndex], (BOOLEAN)(pNic->ManagementInfo.CurrentBSSType == dot11_BSS_type_infrastructure)),
        pNic->TxInfo.TxBeaconBufPa[pNic->ManagementInfo.NextBeaconIndex].LowPart, 
        pNic->ManagementInfo.CurrentBeaconRate
        );
    
    pNic->ManagementInfo.NextBeaconIndex=(pNic->ManagementInfo.NextBeaconIndex+1)%2;
}


void
Hw11StopBSSAdvertisment(
    IN PNIC    pNic)
{
    pNic->ManagementInfo.bAdvertiseBSS = FALSE;
}


NDIS_STATUS
Hw11ReadResetStatus(
    IN PNIC pNic
    )
{
    UNREFERENCED_PARAMETER(pNic);
    return NDIS_STATUS_SUCCESS;                    
}

BOOLEAN
Hw11QueryNicPowerState(
    IN PNIC pNic,
    IN BOOLEAN selectedPhy
    )
{
    UNREFERENCED_PARAMETER(pNic);
    UNREFERENCED_PARAMETER(selectedPhy);

    // RTL8180/8185 does not support per phy power state.

    return (!pNic->RfInfo.RadioOff);
}

VOID
HwIndicateCurrentPhyPowerState(
    IN PNIC     pNic,
    IN ULONG    phyId
    )
{
    NDIS_STATUS_INDICATION  statusIndication;
    DOT11_PHY_STATE_PARAMETERS phyStateParams;
    
    NdisZeroMemory(&statusIndication, sizeof(NDIS_STATUS_INDICATION));
    NdisZeroMemory(&phyStateParams, sizeof(DOT11_PHY_STATE_PARAMETERS));
    
    //
    // Fill in object headers
    //
    statusIndication.Header.Type = NDIS_OBJECT_TYPE_STATUS_INDICATION;
    statusIndication.Header.Revision = NDIS_STATUS_INDICATION_REVISION_1;
    statusIndication.Header.Size = sizeof(NDIS_STATUS_INDICATION);

    phyStateParams.Header.Type = NDIS_OBJECT_TYPE_DEFAULT;
    phyStateParams.Header.Revision = DOT11_PHY_STATE_PARAMETERS_REVISION_1;
    phyStateParams.Header.Size = sizeof(DOT11_PHY_STATE_PARAMETERS);

    //
    // Phy state buffer
    //
    phyStateParams.uPhyId = phyId;
    phyStateParams.bHardwarePhyState = TRUE;            // We dont have Hardware switch
    phyStateParams.bSoftwarePhyState = !pNic->RfInfo.RadioOff;
   
    //
    // Fill in the status buffer
    // 
    statusIndication.StatusCode = NDIS_STATUS_DOT11_PHY_STATE_CHANGED;
    statusIndication.SourceHandle = pNic->MiniportAdapterHandle;
    statusIndication.DestinationHandle = NULL;
    statusIndication.RequestId = 0;

    statusIndication.StatusBuffer = &phyStateParams;
    statusIndication.StatusBufferSize = sizeof(DOT11_PHY_STATE_PARAMETERS);
        
    Mp11IndicateStatusIndication(
        pNic->pAdapter,
        &statusIndication
        );

}

NDIS_STATUS
HwPersistRadioPowerState(
    IN PNIC     pNic,
    IN BOOLEAN  RadioOff
    )
{
    NDIS_CONFIGURATION_OBJECT       ConfigObject;
    NDIS_HANDLE                     RegistryConfigurationHandle = NULL;
    NDIS_CONFIGURATION_PARAMETER    Parameter;
    NDIS_STRING                     RegName = NDIS_STRING_CONST("RadioOff");
    NDIS_STATUS                     ndisStatus;

    ConfigObject.Header.Type = NDIS_OBJECT_TYPE_CONFIGURATION_OBJECT;
    ConfigObject.Header.Revision = NDIS_CONFIGURATION_OBJECT_REVISION_1;
    ConfigObject.Header.Size = sizeof( NDIS_CONFIGURATION_OBJECT );
    ConfigObject.NdisHandle = pNic->MiniportAdapterHandle;
    ConfigObject.Flags = 0;

    ndisStatus = NdisOpenConfigurationEx(
                    &ConfigObject,
                    &RegistryConfigurationHandle
                    );

    if ((ndisStatus == NDIS_STATUS_SUCCESS) && (RegistryConfigurationHandle != NULL))
    {
        NdisZeroMemory(&Parameter, sizeof(NDIS_CONFIGURATION_PARAMETER));

        Parameter.ParameterData.IntegerData = (RadioOff ? 1 : 0);
        Parameter.ParameterType = NdisParameterInteger;
        
        NdisWriteConfiguration(&ndisStatus,
            RegistryConfigurationHandle,
            &RegName,
            &Parameter
            );
    }
    
    //
    // Close the handle to the registry
    //
    if (RegistryConfigurationHandle)
    {
        NdisCloseConfiguration(RegistryConfigurationHandle);
    }

    return ndisStatus;
}

NDIS_STATUS
Hw11SetNicPowerState(
    IN PNIC     pNic,
    IN BOOLEAN  bPowerOn,
    IN BOOLEAN  selectedPhy
    )
{
    NDIS_STATUS             ndisStatus = NDIS_STATUS_SUCCESS;
    
    //
    // Our RF cannot be selectively turned on/off. We turn on or turn off all the phys
    // anytime this OID is set
    //
    UNREFERENCED_PARAMETER(selectedPhy);

    //
    // Check if we are already in the specified state.
    //
    if (pNic->RfInfo.RadioOff == !bPowerOn)
    {
        // No need to take status indications if we are
        // already in the correct state
        return NDIS_STATUS_SUCCESS;
    }

    if (!bPowerOn)
    {
        // If a scan is active, cancel scan
        if (pNic->ManagementInfo.bScanInProgress)
        {
            Hw11CancelScan(pNic);
        }
    }        

    //
    // Update Radio state
    //
    HwSetRadioState(
        pNic,
        bPowerOn
        );

    //
    // Save the new radio state in the registry
    //
    ndisStatus = HwPersistRadioPowerState(pNic, pNic->RfInfo.RadioOff);
    if (ndisStatus != NDIS_STATUS_SUCCESS)
    {
        MpTrace(COMP_OID, DBG_SERIOUS, ("Unable to persist new radio state in the registry\n"));
        return ndisStatus;
    }

    //
    // Report the new power state to the OS
    //    
    HwIndicateCurrentPhyPowerState(
        pNic,
        DOT11_PHY_ID_ANY
        );
    
    return ndisStatus;
}

NDIS_STATUS
Hw11QueryCurrentOptionalCapability(
    IN PNIC pNic,
    IN PDOT11_CURRENT_OPTIONAL_CAPABILITY pDot11CurrentOptionalCapability
    )
{
    NdisMoveMemory(
        pDot11CurrentOptionalCapability,
        &pNic->ManagementInfo.CurrentOptionalCapability,
        sizeof(DOT11_CURRENT_OPTIONAL_CAPABILITY));
    
    return NDIS_STATUS_SUCCESS;                    
}

DOT11_TEMP_TYPE
Hw11QueryTempType(
    IN PNIC pNic
    )
{
    UNREFERENCED_PARAMETER(pNic);

    //
    // RTL8180/8185 can work in the range of 0 to 70 degrees C. Since there is no such range in 
    // DOT11_TEMP_TYPE, we return dot11_temp_type_1 (0C - 40C).
    //
    return dot11_temp_type_1;
}

ULONG
Hw11QueryCurrentTXAntenna(
    IN PNIC pNic
    )
{
    return  pNic->RfInfo.CurrentTxAntenna;
}

ULONG
Hw11QueryCurrentRXAntenna(
    IN PNIC pNic
    )
{
    return pNic->RfInfo.CurrentRxAntenna;;
}

NDIS_STATUS
Hw11QuerySupportedTXAntenna(
    IN PNIC pNic,
    IN ULONG uNumMaxEntries,
    OUT PDOT11_SUPPORTED_ANTENNA_LIST pDot11SupportedAntennaList
    )
{    //3 OK
    ULONG    i;
    
    UNREFERENCED_PARAMETER(pNic);

    if (uNumMaxEntries < 2)
    {
        pDot11SupportedAntennaList->uNumOfEntries = 0;
        pDot11SupportedAntennaList->uTotalNumOfEntries=2;

        return NDIS_STATUS_BUFFER_OVERFLOW;
    }
    else
    {
        pDot11SupportedAntennaList->uTotalNumOfEntries=2;

        for(i=0;i<2 && i<uNumMaxEntries;i++)
        {
            pDot11SupportedAntennaList->dot11SupportedAntenna[i].uAntennaListIndex=i+1;
            pDot11SupportedAntennaList->dot11SupportedAntenna[i].bSupportedAntenna=TRUE;
        }
        
        pDot11SupportedAntennaList->uNumOfEntries=2;
        
        return NDIS_STATUS_SUCCESS;
    }
}

NDIS_STATUS
Hw11QuerySupportedRXAntenna(
    IN PNIC pNic,
    IN ULONG uNumMaxEntries,
    OUT PDOT11_SUPPORTED_ANTENNA_LIST pDot11SupportedAntennaList
    )
{    //3 OK
    return Hw11QuerySupportedTXAntenna(pNic, uNumMaxEntries, pDot11SupportedAntennaList);
}

NDIS_STATUS
Hw11QueryDiversitySelectionRX(
    IN PNIC pNic,
    IN ULONG uNumMaxEntries,
    OUT PDOT11_DIVERSITY_SELECTION_RX_LIST pDot11DiversitySelectionRXList
    )
{
    USHORT    Index;

    if( uNumMaxEntries < pNic->ManagementInfo.pDiversitySelectionRxList->uNumOfEntries )
    {
        pDot11DiversitySelectionRXList->uTotalNumOfEntries = pNic->ManagementInfo.pDiversitySelectionRxList->uNumOfEntries;
        pDot11DiversitySelectionRXList->uNumOfEntries = uNumMaxEntries;
        for( Index=0; Index<uNumMaxEntries; Index++ )
        {
            pDot11DiversitySelectionRXList->dot11DiversitySelectionRx[Index].uAntennaListIndex = pNic->ManagementInfo.pDiversitySelectionRxList->dot11DiversitySelectionRx[Index].uAntennaListIndex;
            pDot11DiversitySelectionRXList->dot11DiversitySelectionRx[Index].bDiversitySelectionRX =pNic->ManagementInfo.pDiversitySelectionRxList->dot11DiversitySelectionRx[Index].bDiversitySelectionRX;
        }
        return NDIS_STATUS_BUFFER_OVERFLOW;
    }
    else
    {
        pDot11DiversitySelectionRXList->uNumOfEntries = pNic->ManagementInfo.pDiversitySelectionRxList->uNumOfEntries;
        pDot11DiversitySelectionRXList->uNumOfEntries = uNumMaxEntries;
        for( Index=0; Index<pNic->ManagementInfo.pDiversitySelectionRxList->uNumOfEntries; Index++ )
        {
            pDot11DiversitySelectionRXList->dot11DiversitySelectionRx[Index].uAntennaListIndex = pNic->ManagementInfo.pDiversitySelectionRxList->dot11DiversitySelectionRx[Index].uAntennaListIndex;
            pDot11DiversitySelectionRXList->dot11DiversitySelectionRx[Index].bDiversitySelectionRX =pNic->ManagementInfo.pDiversitySelectionRxList->dot11DiversitySelectionRx[Index].bDiversitySelectionRX;
        }
    
        return NDIS_STATUS_SUCCESS;                        
    }
}

NDIS_STATUS
Hw11SetMCastList(
    PNIC pNic,
    PVOID pvInformationBuffer,
    ULONG uInformationBufferLength
    )
{
    if(uInformationBufferLength>0)
    {
        //3 Save address list
        pNic->RxInfo.MCAddressCount=uInformationBufferLength/DOT11_ADDRESS_SIZE;
        NdisMoveMemory(pNic->RxInfo.MCAddressList,pvInformationBuffer,uInformationBufferLength);

        //3 Set HW multicast mask
        if(pNic->RxInfo.ReceiveFilter & (NDIS_PACKET_TYPE_ALL_MULTICAST |
                                         NDIS_PACKET_TYPE_802_11_ALL_MULTICAST_MGMT))
            HwSetMulticastMask(pNic,TRUE);
        else if(pNic->RxInfo.ReceiveFilter & (NDIS_PACKET_TYPE_MULTICAST |
                                              NDIS_PACKET_TYPE_802_11_MULTICAST_MGMT))
            HwSetMulticastMask(pNic,FALSE);
    }
    return NDIS_STATUS_SUCCESS;                        
}

VOID
Hw11QueryPnPCapabilities(
    IN PNIC     pNic,
    OUT PNDIS_PNP_CAPABILITIES pNdisPnPCapabilities
    )
{
    UNREFERENCED_PARAMETER(pNic);
    NdisZeroMemory(pNdisPnPCapabilities, sizeof(NDIS_PNP_CAPABILITIES));
}

NDIS_STATUS
Hw11QueryInterruptModerationSettings(
    IN PNIC     pNic,
    OUT PNDIS_INTERRUPT_MODERATION_PARAMETERS      pIntModParams
    )
{
    UNREFERENCED_PARAMETER(pNic);
    
    // Interrupt moderation not supported
    pIntModParams->Flags = 0;
    pIntModParams->InterruptModeration = NdisInterruptModerationNotSupported;

    return NDIS_STATUS_SUCCESS;
}

NDIS_STATUS
Hw11SetInterruptModerationSettings(
    IN PNIC     pNic,
    IN PNDIS_INTERRUPT_MODERATION_PARAMETERS      pIntModParams
    )
{
    UNREFERENCED_PARAMETER(pNic);
    UNREFERENCED_PARAMETER(pIntModParams);
    
    // Interrupt moderation not supported
    return NDIS_STATUS_INVALID_DATA;
}

NDIS_STATUS
Hw11SetOperationalRateSet(
    IN  PNIC            pNic,
    IN  PDOT11_RATE_SET pDot11RateSet,
    IN  BOOLEAN         selectedPhy 
    )
{
    PNICPHYMIB PhyMib;
    ULONG   Index;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

    for (Index = 0; Index < pDot11RateSet->uRateSetLength; Index++)
    {
        PhyMib->OperationalRateSet.ucRateSet[Index] = pDot11RateSet->ucRateSet[Index];
    }

    PhyMib->OperationalRateSet.uRateSetLength = pDot11RateSet->uRateSetLength;
    return NDIS_STATUS_SUCCESS;                        
}

ULONG
Hw11QueryRFUsage(
    IN PNIC                pNic
    )
{
    UNREFERENCED_PARAMETER(pNic);
    
    //
    // TODO: The hardware does not support this.
    // What would be an appropriate value to return
    //
    
    return 10;    // In percentage
}

NDIS_STATUS
Hw11QueryShortPreambleOptionImplemented(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

	if (PhyMib->PhyType == dot11_phy_type_hrdsss ||
        PhyMib->PhyType == dot11_phy_type_erp)
    {
        *value = (BOOLEAN)(PhyMib->PhyType == dot11_phy_type_erp);  // only RTL8185 works with short preamble
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

NDIS_STATUS
Hw11QueryPbccOptionImplemented(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

	if (PhyMib->PhyType == dot11_phy_type_hrdsss ||
        PhyMib->PhyType == dot11_phy_type_erp)
    {
        *value = FALSE;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

NDIS_STATUS
Hw11QueryErpPbccOptionImplemented(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

	if (PhyMib->PhyType == dot11_phy_type_erp)
    {
        *value = FALSE;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

NDIS_STATUS
Hw11QueryErpPbccOptionEnabled(
    IN  PNIC            pNic,
    OUT PBOOLEAN        value,
    IN  BOOLEAN         selectedPhy
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

	if (PhyMib->PhyType == dot11_phy_type_erp)
    {
        *value = FALSE;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

NDIS_STATUS
Hw11SetErpPbccOptionEnabled(
    IN PNIC				pNic,
    IN BOOLEAN          value,
    IN BOOLEAN          selectedPhy
    )
{
    UNREFERENCED_PARAMETER(pNic);
    UNREFERENCED_PARAMETER(value);
    UNREFERENCED_PARAMETER(selectedPhy);

	return NDIS_STATUS_NOT_SUPPORTED;
}

NDIS_STATUS
Hw11QueryDsssOfdmOptionImplemented(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

	if (PhyMib->PhyType == dot11_phy_type_erp)
    {
        *value = FALSE;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

NDIS_STATUS
Hw11QueryDsssOfdmOptionEnabled(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

	if (PhyMib->PhyType == dot11_phy_type_erp)
    {
        *value = FALSE;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

NDIS_STATUS
Hw11SetDsssOfdmOptionEnabled(
    IN PNIC				pNic,
    IN BOOLEAN          value,
    IN BOOLEAN          selectedPhy
    )
{
    UNREFERENCED_PARAMETER(pNic);
    UNREFERENCED_PARAMETER(value);
    UNREFERENCED_PARAMETER(selectedPhy);

	return NDIS_STATUS_NOT_SUPPORTED;
}

NDIS_STATUS
Hw11QueryShortSlotTimeOptionImplemented(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

	if (PhyMib->PhyType == dot11_phy_type_erp)
    {
        *value = TRUE;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

NDIS_STATUS
Hw11QueryShortSlotTimeOptionEnabled(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

	if (PhyMib->PhyType == dot11_phy_type_erp)
    {
        *value = pNic->ManagementInfo.ShortSlotTimeOptionEnabled;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

NDIS_STATUS
Hw11SetShortSlotTimeOptionEnabled(
    IN PNIC				pNic,
    IN BOOLEAN          value,
    IN BOOLEAN          selectedPhy
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

	if (PhyMib->PhyType == dot11_phy_type_erp)
    {
        pNic->ManagementInfo.ShortSlotTimeOptionEnabled = value;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

NDIS_STATUS
Hw11QueryChannelAgilityPresent(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

	if (PhyMib->PhyType == dot11_phy_type_hrdsss ||
        PhyMib->PhyType == dot11_phy_type_erp)
    {
        *value = FALSE;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

NDIS_STATUS
Hw11QueryChannelAgilityEnabled(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    )
{
    PNICPHYMIB PhyMib;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

	if (PhyMib->PhyType == dot11_phy_type_hrdsss ||
        PhyMib->PhyType == dot11_phy_type_erp)
    {
        *value = FALSE;
        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_NOT_SUPPORTED;
    }
}

NDIS_STATUS
Hw11QuerySupportedGUIDS(
    IN  PNIC                        pNic
    )
{
    UNREFERENCED_PARAMETER(pNic);
    return NDIS_STATUS_NOT_SUPPORTED;
}


NDIS_STATUS Hw11ResetStep2(
    IN PNIC pNic
    )
{
    UCHAR tmpMSR;
    ReadPortUchar(pNic, MSR, &tmpMSR);
    tmpMSR&=0xf3;       // No Link
    WritePortUchar(pNic, MSR, tmpMSR);

    // Issue Tx/Rx reset
    WritePortUchar(pNic, CMDR,    CR_RST);

    return NDIS_STATUS_SUCCESS;
}

NDIS_STATUS Hw11ResetStep3(
    IN PNIC pNic,
    IN DOT11_RESET_TYPE ResetType
    )
{
    int i;

    //3 Reset receive related variables
    HwResetReceive(pNic);

    //3  Reset transmit related variables
    for(i=0;i<TX_QUEUE_NUM;i++)
    {    // Reinitialize Tx desc and index
        NdisZeroMemory(
            (UCHAR *)pNic->TxInfo.TxDesc[i],
            TX_DESC_SIZE*pNic->TxInfo.TxTotalDescNum[i]);
        
        HwLinkTxDesc(
            (UCHAR *)pNic->TxInfo.TxDesc[i],
            pNic->TxInfo.TxDescPhy[i],
            TX_DESC_SIZE,
            pNic->TxInfo.TxTotalDescNum[i]);
        
        pNic->TxInfo.TxNextDescToSend[i]=0;
        pNic->TxInfo.TxNextDescToCheck[i]=0;
    }

    //
    // The assumption with the packets in the PostSG queue is
    // that the Mp thinks they are being sent and hence on a reset
    // it will clean those up. Here, we just reset the queue without
    // touching the entries
    //
    pNic->TxInfo.PostSGMSDUListLength = 0;
    InitializeListHead(&pNic->TxInfo.PostSGMSDUList);

    // REVIEW:
    for(i=0;i<TX_QUEUE_NUM;i++)
       pNic->TxInfo.TxBusyDescCount[i] = 0;

    if (ResetType != 0 && 
        ResetType != MP_RESET_TYPE_NDIS_RESET &&
        ResetType != MP_RESET_TYPE_INTERNAL_RESET)
    {
        //
        // This is a DOT11 RESET. Clean up any state needed.
        //
        HwResetParameters(pNic, ResetType);
    }

    //3 Reset hardware
    HwInitializeAdapter(pNic,FALSE);

    return NDIS_STATUS_SUCCESS;
    
}

NDIS_STATUS Hw11ResetStep4(
    IN PNIC pNic
    )
{
    // enable tx/rx
    WritePortUchar(pNic, CMDR,    CR_RE|CR_TE|(pNic->CardInfo.MWIEnable?CR_MulRW:0) );

    return NDIS_STATUS_SUCCESS;
}


NDIS_STATUS
Hw11SetPacketFilter(
    PNIC pNic,
    ULONG PacketFilter
    )
{
    NDIS_STATUS     ndisStatus;
        
    ndisStatus = HwSetPacketFilter(pNic, PacketFilter);

    return ndisStatus;
}



NDIS_STATUS
Hw11ValidateOperationalRates(
    IN  PNIC                pNic,
    IN  ULONG               PhyId,
    IN  PUCHAR              pDataRateSet,
    IN  ULONG               RateSetLength
    )
{
    NDIS_STATUS     ndisStatus = NDIS_STATUS_SUCCESS;
    ULONG           i, j;
    BOOLEAN         bRateFound;
    PDOT11_RATE_SET opRateSet;

    do
    {
        opRateSet = &pNic->ManagementInfo.PhyMIB[PhyId].OperationalRateSet;

        if (RateSetLength > DOT11_RATE_SET_MAX_LENGTH)
        {
            MpTrace(COMP_ASSOC, DBG_LOUD, ("Bad rate set size in Rate Set\n"));
            ndisStatus = NDIS_STATUS_INVALID_DATA;
            break;
        }

        for (i = 0; i < RateSetLength; i++)
        {
            bRateFound = FALSE;
            
            for (j = 0; j < opRateSet->uRateSetLength; j++)
            {
                if ((pDataRateSet[i] & 0x7F) == opRateSet->ucRateSet[j])
                {
                    bRateFound = TRUE;
                    break;
                }
            }
                
            if (bRateFound == FALSE)
            {
                MpTrace(COMP_ASSOC, DBG_LOUD,  ("Bad data rate %d detected\n", pDataRateSet[i]));
                ndisStatus = NDIS_STATUS_INVALID_DATA;
                break;
            }
        }
    } while(FALSE);

    return ndisStatus;
}

ULONG
Hw11DefaultKeyTableSize(
    IN PNIC                 pNic
    )
{
    UNREFERENCED_PARAMETER(pNic);
    return DOT11_MAX_NUM_DEFAULT_KEY;
}


ULONG
Hw11KeyMappingKeyTableSize(
    IN PNIC                 pNic
    )
{
    return (pNic->CardInfo.HardwareID == HW_ID_8180) ? 0 : KEY_MAPPING_KEY_TABLE_SIZE;
}

ULONG
Hw11PerStaKeyTableSize(
    IN PNIC                 pNic
    )
{
    return (pNic->CardInfo.HardwareID == HW_ID_8180) ? 0 : PER_STA_KEY_TABLE_SIZE;
}

NDIS_STATUS
HwValidateInfoElementsInBlob(
    IN PNIC   pNic,
    IN PUCHAR pucInfoBlob,
    IN ULONG uSizeOfBlob
    )
{
    UNREFERENCED_PARAMETER(pNic);    
    UNREFERENCED_PARAMETER(pucInfoBlob);
    UNREFERENCED_PARAMETER(uSizeOfBlob);

    return NDIS_STATUS_SUCCESS;
}


VOID
HwJoinChannelSwitchComplete(
    IN  PNIC   pNic
    )
{
    ULONG                   JoinFailureInMs;
    
    //
    // Clear out the handler and indicate completion to OS
    //
    pNic->ManagementInfo.ChannelSwitchedHandler = NULL;

	//3 Adopt setting to hardware
    HwSetBSSIDAndBcnIntv(pNic);

    //
    // Set the timeout timer for Join Failure case. 
    //
    JoinFailureInMs = MP_TU_TO_MS(pNic->DupCurrentInfo.JoinFailureTimeout * pNic->DupCurrentInfo.BeaconInterval);
    MpTrace(COMP_OID, DBG_LOUD, ("Setting Join Timeout timer for %d ms\n", JoinFailureInMs));
    NdisMSetTimer(&pNic->ManagementInfo.Timer_JoinTimeout, JoinFailureInMs);
    
    //
    //3 Set the appropriate filtering function and wait for Join Beacon
    //
    HW_WAIT_FOR_BSS_JOIN(pNic);
    pNic->RxInfo.ReceiveProcessingFunction =  HwProcessReceiveSTAModeWaitForJoin;
}


NDIS_STATUS
Hw11JoinInfra(
    IN PNIC		                pNic,
    IN PSTA_BSS_ENTRY           pBSSEntry,
    IN ULONG                    JoinFailureTimeout
    )    
{
    NDIS_STATUS         ndisStatus;
    UCHAR               ucChannel, ucCurrentChannel;

	MpEntry;
    
    do
    {
        //
        // Verify the IE in the blob
        //
        ndisStatus = HwValidateInfoElementsInBlob(
            pNic,
            pBSSEntry->pDot11InfoElemBlob,
            pBSSEntry->InfoElemBlobSize
            );
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            break;
        }
              
    	//3 Update SSID,BSSID,Capability and Beacon Interval
        ndisStatus = HwUpdateInfoFromBSSInformation(
            pNic, 
            pBSSEntry
            );
    	if (ndisStatus != NDIS_STATUS_SUCCESS)
    	    break;

    	// Save join failure timeout for later
    	pNic->DupCurrentInfo.JoinFailureTimeout = JoinFailureTimeout;
    	
        //
        // Depending on the hardware, NIC may have to do multiple things. At least
        // the current channel would have to change for all NICs.
        // Handling of timeouts, synchronizing with the BSS are all responsibilities
        // of the Hw11 functions and the NIC.
        //
        if (pBSSEntry->Channel != 0) 
        {
            ucChannel = pBSSEntry->Channel;
        }
        else
        {
            ndisStatus = Dot11GetChannelForDSPhy(
                            pBSSEntry->pDot11InfoElemBlob,
                            pBSSEntry->InfoElemBlobSize,
                            &ucChannel
                            );
            if (ndisStatus != NDIS_STATUS_SUCCESS)
            {
                //
                // Channel info not found in the blob. Stick to
                // the channel NIC is currently on.
                //
                ucChannel = (UCHAR)Hw11GetCurrentChannelId(pNic);
                ndisStatus = NDIS_STATUS_SUCCESS;
            }
        }

        //
        // Switch the channel in use if needed. This request will pend.
        //
        ucCurrentChannel = (UCHAR)Hw11GetCurrentChannelId(pNic);
        if(ucCurrentChannel != ucChannel)
        {
            MpTrace(COMP_ASSOC, DBG_NORMAL, ("Setting channel number %d\n", ucChannel));
            HwSetChannel(pNic, ucChannel, HwJoinChannelSwitchComplete);
        }
        else
        {
            //
            // No need to switch the channel. Indicate Join complete
            //
            HwJoinChannelSwitchComplete(pNic);
        }
        
        // check the beacon for protection bit and enable g-mode protection if the bit is set
        Hw11CheckForProtectionInERP(pNic, pBSSEntry->pDot11InfoElemBlob, pBSSEntry->InfoElemBlobSize);
        
        //
        // We will always pend this OID. BSS Join is complete only when the beacon
        // has been received from the AP we are joining to. HwProcessReceiveSTAModeWaitForJoin
        // will do that for us.
        //
        ndisStatus = NDIS_STATUS_PENDING;
	} while(FALSE);
	
	MpExit;
	
	return ndisStatus;
}

VOID
Hw11QuerySupportedDataRatesValue(
    IN  PNIC                                    pNic,
    OUT PDOT11_SUPPORTED_DATA_RATES_VALUE_V2    pDot11SupportedDataRatesValue,
    IN  BOOLEAN                                 selectedPhy 
    )
{
    PNICPHYMIB PhyMib;
    ULONG   Index;

    PhyMib = selectedPhy ? pNic->ManagementInfo.SelectedPhyMIB : pNic->ManagementInfo.OperatingPhyMIB;

    for (Index = 0; Index < MAX_NUM_SUPPORTED_RATES_V2; Index++)
    {
        pDot11SupportedDataRatesValue->ucSupportedTxDataRatesValue[Index] = PhyMib->SupportedDataRatesValue.ucSupportedTxDataRatesValue[Index];
        pDot11SupportedDataRatesValue->ucSupportedRxDataRatesValue[Index] = PhyMib->SupportedDataRatesValue.ucSupportedRxDataRatesValue[Index];
    }
}

NDIS_STATUS
Hw11StartAdHoc(
    IN  PNIC		            pNic,
    IN  PDOT11_BSS_DESCRIPTION  BSSDescription
    )    
{
    
    NDIS_STATUS ndisStatus;

    //
    // Update SSID, BSSID, Capability and Beacon Interval
    //

    if (BSSDescription)
    {
        ndisStatus = HwUpdateInfoFromdot11BSSDescription(pNic, BSSDescription);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
            return ndisStatus;
    }

    //
    // Start beaconing.
    //

    HwInternalStartReqComplete(pNic);
    Hw11StartBSSAdvertisment(pNic);

    return NDIS_STATUS_SUCCESS;
}

void
Hw11StopAdHoc(
    IN  PNIC		             pNic
    )
{
    //
    // Stop beaconing.
    //
    Hw11StopBSSAdvertisment(pNic);
}

NDIS_STATUS
Hw11JoinAdHoc(
    IN  PNIC		            pNic,
    IN  PDOT11_BSS_DESCRIPTION  BSSDescription
    )    
{
    NDIS_STATUS ndisStatus;
    UCHAR       channel;

    //
    // Update SSID, BSSID, Capability and Beacon Interval
    //

    ndisStatus = HwUpdateInfoFromdot11BSSDescription(pNic, BSSDescription);
    if (ndisStatus != NDIS_STATUS_SUCCESS)
        return ndisStatus;

    //
    // Depending on the hardware, NIC may have to do multiple things. At least
    // the current channel would have to change for all NICs.
    // Handling of timeouts, synchronizing with the BSS are all responsibilities
    // of the Hw11 functions and the NIC.
    //

    ndisStatus = Dot11GetChannelForDSPhy(BSSDescription->ucBuffer,
                                         BSSDescription->uBufferLength,
                                         &channel);
    if (ndisStatus == NDIS_STATUS_SUCCESS) 
    {
        //
        // Switch the channel in use if needed. 
        //

        if (channel != (UCHAR)Hw11GetCurrentChannelId(pNic)) 
        {
            HwSetChannelSync(pNic, channel);
        }
    }

    //
    // Adopt setting to hardware
    //

    HwSetBSSIDAndBcnIntv(pNic);

    //
    // Set the appropriate filtering function and wait for Join Beacon
    //

    HW_WAIT_FOR_BSS_JOIN(pNic);
    pNic->RxInfo.ReceiveProcessingFunction = HwProcessReceiveAdHocSTAModeWaitForJoin;

    return NDIS_STATUS_SUCCESS;
}

NDIS_STATUS HwSetPacketFilter(
    PNIC pNic,
    ULONG PacketFilter
    )
{
    ULONG MaskBits;

    MaskBits =RCR_ACF | RCR_ADF | RCR_AM | RCR_AAP;

    //3 Change the corresponding HW filter and set into the HW
    // Clear all releated bits
    pNic->RxInfo.ReceiveConfig &= ~MaskBits;

    // Set ACF bit
    // To receive ps-poll, we don't need to set ACF bit
    if (PacketFilter & (NDIS_PACKET_TYPE_802_11_DIRECTED_CTRL |
					    NDIS_PACKET_TYPE_802_11_BROADCAST_CTRL |
					    NDIS_PACKET_TYPE_802_11_PROMISCUOUS_CTRL))
        pNic->RxInfo.ReceiveConfig |= RCR_ACF;

    // Set AMF bit
    if (PacketFilter & (NDIS_PACKET_TYPE_802_11_DIRECTED_MGMT |
                        NDIS_PACKET_TYPE_802_11_BROADCAST_MGMT |
                        NDIS_PACKET_TYPE_802_11_MULTICAST_MGMT |
                        NDIS_PACKET_TYPE_802_11_ALL_MULTICAST_MGMT |
                        NDIS_PACKET_TYPE_802_11_PROMISCUOUS_MGMT)) 
        pNic->RxInfo.ReceiveConfig |= RCR_AMF;

    // Set ADF bit
    if (PacketFilter & (NDIS_PACKET_TYPE_DIRECTED |
                        NDIS_PACKET_TYPE_MULTICAST |
                        NDIS_PACKET_TYPE_ALL_MULTICAST |
                        NDIS_PACKET_TYPE_BROADCAST |
                        NDIS_PACKET_TYPE_PROMISCUOUS |
                        NDIS_PACKET_TYPE_802_11_RAW_DATA))
        pNic->RxInfo.ReceiveConfig |= RCR_ADF;

    // Set AB bit
    if (PacketFilter & (NDIS_PACKET_TYPE_BROADCAST |
                        NDIS_PACKET_TYPE_802_11_BROADCAST_MGMT |
					    NDIS_PACKET_TYPE_802_11_BROADCAST_CTRL))
        pNic->RxInfo.ReceiveConfig |= RCR_AB;

    // Set AM bit
    if (PacketFilter & (NDIS_PACKET_TYPE_MULTICAST | 
                        NDIS_PACKET_TYPE_ALL_MULTICAST |
                        NDIS_PACKET_TYPE_802_11_MULTICAST_MGMT |
                        NDIS_PACKET_TYPE_802_11_ALL_MULTICAST_MGMT))
        pNic->RxInfo.ReceiveConfig |= RCR_AM;

    // Set APM bit
    if (PacketFilter & (NDIS_PACKET_TYPE_DIRECTED |
                        NDIS_PACKET_TYPE_802_11_DIRECTED_MGMT |
					    NDIS_PACKET_TYPE_802_11_DIRECTED_CTRL))
        pNic->RxInfo.ReceiveConfig |= RCR_APM;

    // Set AAP bit
    if (PacketFilter & (NDIS_PACKET_TYPE_PROMISCUOUS |
                        NDIS_PACKET_TYPE_802_11_PROMISCUOUS_MGMT |
					    NDIS_PACKET_TYPE_802_11_PROMISCUOUS_CTRL))
        pNic->RxInfo.ReceiveConfig |= RCR_AAP;

    NdisAcquireSpinLock(&pNic->RxInfo.ReceiveFilterLock);
    pNic->RxInfo.ReceiveFilter = PacketFilter;
    WritePortUlong(pNic, RCR, pNic->RxInfo.ReceiveConfig);
    NdisReleaseSpinLock(&pNic->RxInfo.ReceiveFilterLock);
    
    //3 Set HW multicast mask
    if (PacketFilter & (NDIS_PACKET_TYPE_ALL_MULTICAST |
					    NDIS_PACKET_TYPE_802_11_ALL_MULTICAST_MGMT))
        HwSetMulticastMask(pNic, TRUE);
    else if (PacketFilter & (NDIS_PACKET_TYPE_MULTICAST |
			                 NDIS_PACKET_TYPE_802_11_MULTICAST_MGMT))
        HwSetMulticastMask(pNic, FALSE);
    
    return NDIS_STATUS_SUCCESS;                
}

BOOLEAN
Hw11QueryHardwarePhyState(
    PNIC pNic
    )
{
    UNREFERENCED_PARAMETER(pNic);

    // Always TRUE since there is no hardware setting to turn off the radio
    return TRUE;
}

NDIS_STATUS
Hw11QueryDataRateMappingTable(
    IN  PNIC pNic,
    OUT PDOT11_DATA_RATE_MAPPING_TABLE  pDataRateMappingTable,
    IN  ULONG           TotalLength
    )
{
    UNREFERENCED_PARAMETER(pNic);
    UNREFERENCED_PARAMETER(pDataRateMappingTable);
    UNREFERENCED_PARAMETER(TotalLength);

    //
    // We don't support non-standard data rate.
    //
    return NDIS_STATUS_NOT_SUPPORTED;
}

NDIS_STATUS
Hw11Fill80211Attributes(
    IN  PNIC pNic,
    OUT PNDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES attr
    )
{
    PDOT11_PHY_ATTRIBUTES   PhyAttr;
    ULONG                   PhyId;
    ULONG                   index;
    UCHAR                   rate;

    attr->NumOfTXBuffers = pNic->ManagementInfo.OperationModeCapability.uNumOfTXBuffers;
    attr->NumOfRXBuffers = pNic->ManagementInfo.OperationModeCapability.uNumOfRXBuffers;
    attr->MultiDomainCapabilityImplemented = TRUE;
    attr->NumSupportedPhys = pNic->ManagementInfo.pSupportedPhyTypes->uNumOfEntries;

    MP_ALLOCATE_MEMORY(pNic->MiniportAdapterHandle, 
                       &attr->SupportedPhyAttributes,
                       attr->NumSupportedPhys * sizeof(DOT11_PHY_ATTRIBUTES),
                       HW11_MEMORY_TAG);
    if (attr->SupportedPhyAttributes == NULL)
    {
        return NDIS_STATUS_RESOURCES;
    }

    for (PhyId = 0, PhyAttr = attr->SupportedPhyAttributes; PhyId < attr->NumSupportedPhys; PhyId++, PhyAttr++)
    {
        MP_ASSIGN_NDIS_OBJECT_HEADER(PhyAttr->Header, 
                                     NDIS_OBJECT_TYPE_DEFAULT,
                                     DOT11_PHY_ATTRIBUTES_REVISION_1,
                                     sizeof(DOT11_PHY_ATTRIBUTES));

        PhyAttr->PhyType = pNic->ManagementInfo.PhyMIB[PhyId].PhyType;
        PhyAttr->bHardwarePhyState = Hw11QueryHardwarePhyState(pNic);
        PhyAttr->bSoftwarePhyState = !pNic->RfInfo.RadioOff;
        PhyAttr->bCFPollable = Hw11QueryCFPollable(pNic);
        PhyAttr->uMPDUMaxLength = pNic->ManagementInfo.uMPDUMaxLength;
        PhyAttr->TempType = Hw11QueryTempType(pNic);
        PhyAttr->DiversitySupport = Hw11QueryDiversitySupport(pNic);

        PhyAttr->uNumberSupportedPowerLevels = pNic->ManagementInfo.SupportedPowerLevels.uNumOfSupportedPowerLevels;
        for (index = 0; index < PhyAttr->uNumberSupportedPowerLevels; index++)
        {
            PhyAttr->TxPowerLevels[index] = pNic->ManagementInfo.SupportedPowerLevels.uTxPowerLevelValues[index];
        }

        switch (PhyAttr->PhyType)
        {
            case dot11_phy_type_hrdsss:
                PhyAttr->HRDSSSAttributes.bShortPreambleOptionImplemented = FALSE;
                PhyAttr->HRDSSSAttributes.bPBCCOptionImplemented = FALSE;
                PhyAttr->HRDSSSAttributes.bChannelAgilityPresent = FALSE;
                PhyAttr->HRDSSSAttributes.uHRCCAModeSupported = pNic->ManagementInfo.CCAModeSupported;
                break;

            case dot11_phy_type_ofdm:
                PhyAttr->OFDMAttributes.uFrequencyBandsSupported = DOT11_FREQUENCY_BANDS_LOWER | 
                                                                   DOT11_FREQUENCY_BANDS_MIDDLE;
                break;

            case dot11_phy_type_erp:
                PhyAttr->ERPAttributes.bShortPreambleOptionImplemented = TRUE;
                PhyAttr->ERPAttributes.bPBCCOptionImplemented = FALSE;
                PhyAttr->ERPAttributes.bChannelAgilityPresent = FALSE;
                PhyAttr->ERPAttributes.uHRCCAModeSupported = pNic->ManagementInfo.CCAModeSupported;
                PhyAttr->ERPAttributes.bERPPBCCOptionImplemented = FALSE;
                PhyAttr->ERPAttributes.bDSSSOFDMOptionImplemented = FALSE;
                PhyAttr->ERPAttributes.bShortSlotTimeOptionImplemented = TRUE;
                break;

            default:
                break;
        }

        NdisMoveMemory(&PhyAttr->SupportedDataRatesValue,
                       &pNic->ManagementInfo.PhyMIB[PhyId].SupportedDataRatesValue,
                       sizeof(DOT11_SUPPORTED_DATA_RATES_VALUE_V2));

        index = 0;
        while ((rate = PhyAttr->SupportedDataRatesValue.ucSupportedTxDataRatesValue[index]) != 0 && 
               index < DOT11_RATE_SET_MAX_LENGTH)
        {
            PhyAttr->DataRateMappingEntries[index].ucDataRateIndex = rate;
            PhyAttr->DataRateMappingEntries[index].ucDataRateFlag = 0;
            PhyAttr->DataRateMappingEntries[index].usDataRateValue = (USHORT)rate;

            index++;
        }

        PhyAttr->uNumDataRateMappingEntries = index;
    }

    return NDIS_STATUS_SUCCESS;
}

VOID
Hw11Cleanup80211Attributes(
    IN PNIC pNic,
    IN PNDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES attr
    )
{
    UNREFERENCED_PARAMETER(pNic);

    if (attr->SupportedPhyAttributes)
    {
        MP_FREE_MEMORY(attr->SupportedPhyAttributes);
    }
}


NDIS_STATUS
Hw11QueryDot11Statistics(
    IN PNIC pNic,
    IN PDOT11_STATISTICS pDot11Stats,
    IN ULONG InformationBufferLength,
    OUT PULONG BytesWritten,
    OUT PULONG BytesNeeded
    )
{
    ULONG                   statsSize = sizeof(DOT11_STATISTICS) +
        (pNic->ManagementInfo.pSupportedPhyTypes->uNumOfEntries - 1) * sizeof(DOT11_PHY_FRAME_STATISTICS);
    PDOT11_PHY_FRAME_STATISTICS     PhyStats;
    ULONG                   PhyId;

    if (InformationBufferLength < statsSize)
    {
        *BytesNeeded = statsSize;
        return NDIS_STATUS_BUFFER_OVERFLOW;
    }

    // Unicast counters
    NdisMoveMemory(&pDot11Stats->MacUcastCounters, 
        &pNic->StatisticsInfo.UcastCounters, 
        sizeof(DOT11_MAC_FRAME_STATISTICS)
        );

    // Multicast counters
    NdisMoveMemory(&pDot11Stats->MacMcastCounters, 
        &pNic->StatisticsInfo.McastCounters, 
        sizeof(DOT11_MAC_FRAME_STATISTICS)
        );

    // Phy counters
    for (PhyId = 0, PhyStats = pDot11Stats->PhyCounters; 
            PhyId < pNic->ManagementInfo.pSupportedPhyTypes->uNumOfEntries; 
            PhyId++, PhyStats++
        )
    {
        NdisMoveMemory(PhyStats, 
            &pNic->StatisticsInfo.PhyCounters[PhyId], 
            sizeof(DOT11_PHY_FRAME_STATISTICS)
            );
    }

    *BytesWritten = statsSize;

    return NDIS_STATUS_SUCCESS;
}


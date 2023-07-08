/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    Mp_Main.c

Abstract:
    MP layer main entry points from NDIS
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created

Notes:

--*/
#include "Precomp.h"

#include "Mp_Oids.h"
#include "Mp_Main.h"
#if DOT11_TRACE_ENABLED
#include "Mp_Main.tmh"
#endif



NDIS_HANDLE                 GlobalDriverContext = NULL;
NDIS_HANDLE                 GlobalDriverHandle = NULL;


MP_REG_ENTRY MPRegTable[] = {
// reg value name                           Offset in ADAPTER               Field size                   Default Value          Min                 Max
    {NDIS_STRING_CONST("*ReceiveBuffers"),  MP_OFFSET(TotalRxMSDU),         MP_SIZE(TotalRxMSDU),       HW11_DEF_RX_MSDUS,  HW11_MIN_RX_MSDUS,  HW11_MAX_RX_MSDUS},
    {NDIS_STRING_CONST("MinRxBuffers"),     MP_OFFSET(MinRxMSDU),           MP_SIZE(MinRxMSDU),            HW11_MIN_RX_MSDUS,  HW11_MIN_RX_MSDUS,  HW11_MIN_RX_MSDUS},
    {NDIS_STRING_CONST("MaxRxBuffers"),     MP_OFFSET(MaxRxMSDU),           MP_SIZE(MaxRxMSDU),            HW11_MAX_RX_MSDUS,  HW11_MAX_RX_MSDUS,  HW11_MAX_RX_MSDUS},
    {NDIS_STRING_CONST("*TransmitBuffers"), MP_OFFSET(TotalTxMSDUs),        MP_SIZE(TotalTxMSDUs),      HW11_DEF_TX_MSDUS,  HW11_MIN_TX_MSDUS,  HW11_MAX_TX_MSDUS},
};

#define MP_NUM_REG_PARAMS (sizeof (MPRegTable) / sizeof(MP_REG_ENTRY))


/**
 * This function Deallocates an adapter object, returning all the resources back to
 * the system. Any allocations that are made for Adapter, must be deallocated from
 * here
 * 
 * \param pAdapter The adapter object to deallocate
 * \sa MpAllocateAdapter
 */
VOID
MpFreeAdapter(
    IN PADAPTER                   pAdapter
    )
{
    //
    // Free locks and other small resources
    //
    NdisFreeSpinLock(&pAdapter->SendLock);
    NdisFreeSpinLock(&pAdapter->ResetPnPLock);

    //
    // Free the resources allocated for station information
    // 
    if (pAdapter->pStation)
    {
        Sta11FreeStation(pAdapter->pStation);
    }

    //
    // Free the resources allocated by the NIC
    //
    if (pAdapter->pNic)
    {
        Hw11FreeNic(pAdapter->pNic);
    }

    if(pAdapter->NdisResetWorkItem)
    {
        NdisFreeIoWorkItem(pAdapter->NdisResetWorkItem);
    }

    if (pAdapter->Dot11ResetWorkItem)
    {
        NdisFreeIoWorkItem(pAdapter->Dot11ResetWorkItem);
    }

    //
    // Free the Packet queue
    //
    MpDeinitNBLQueue(&pAdapter->TxQueue);

    MP_FREE_MEMORY(pAdapter);
}


/**
 * This routine allocates and initializes an Adapter data structure.
 * This DS represents a Physical Network Adapter present on the
 * system and allows us to work with it.
 * 
 * \param MiniportAdapterHandle     The handle needed to call NDIS API on this adapter
 * \param ppAdapter     The pointer to newly created adapter is returned in this variable
 * \return NDIS_STATUS_SUCCESS if all goes well, else appropriate error code
 * \sa MpFreeAdapter, MpInitialize
 */
NDIS_STATUS
MpAllocateAdapter(
    IN NDIS_HANDLE MiniportAdapterHandle,
    OUT PADAPTER* ppAdapter
    )
/*++

Routine Description:
    This routine allocates and initialize an adapter structure.

Arguments:

Return Value:

--*/

{
    PADAPTER                pAdapter = NULL;
    PNIC                    pNic = NULL;
    PSTATION                pStation = NULL;
    NDIS_STATUS             ndisStatus = NDIS_STATUS_SUCCESS;

    *ppAdapter = NULL;
    
    do
    {
        //
        // Allocate a ADAPTER data structure.
        //
        MP_ALLOCATE_MEMORY(MiniportAdapterHandle, &pAdapter, sizeof(ADAPTER), MP_MEMORY_TAG);
        if (pAdapter == NULL)
        {
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("MpAllocateAdapter: Failed to allocate %d bytes for ADAPTER\n",
                                 sizeof(ADAPTER)));
            ndisStatus = NDIS_STATUS_RESOURCES;
            break;
        }        
        
        //
        // Initialize it.
        //
        NdisZeroMemory(pAdapter, sizeof(ADAPTER));
        NdisInitializeListHead(&pAdapter->Link);
        NdisAllocateSpinLock(&pAdapter->SendLock);
        NdisInitializeEvent(&pAdapter->MiniportRefCountZeroEvent);  // Will be reset during Restart
        NdisInitializeEvent(&pAdapter->ActiveSendersDoneEvent);
        NdisResetEvent(&pAdapter->ActiveSendersDoneEvent);
        NdisInitializeEvent(&pAdapter->SGOperationsDoneEvent);
        NdisResetEvent(&pAdapter->SGOperationsDoneEvent);
        NdisInitializeEvent(&pAdapter->HaltWaitEvent);
        NdisResetEvent(&pAdapter->HaltWaitEvent);
        NdisInitializeEvent(&pAdapter->AllReceivesHaveReturnedEvent);
        NdisResetEvent(&pAdapter->AllReceivesHaveReturnedEvent);
        NDIS_INIT_MUTEX(&pAdapter->ResetPnPMutex);

        //
        // Allocate the work item (MpDot11ResetWorkItem)
        //
        pAdapter->Dot11ResetWorkItem = NdisAllocateIoWorkItem(MiniportAdapterHandle);
        if(pAdapter->Dot11ResetWorkItem == NULL)
        {
            MpTrace (COMP_INIT_PNP, DBG_SERIOUS, ("Failed to allocate Dot11 Reset Workitem \n"));
            ndisStatus = NDIS_STATUS_RESOURCES;
            break;
        }
        
        //
        // Allocate the work item (MpResetWorkItem)
        //
        pAdapter->NdisResetWorkItem = NdisAllocateIoWorkItem(MiniportAdapterHandle);
        if(pAdapter->NdisResetWorkItem == NULL)
        {
            MpTrace (COMP_INIT_PNP, DBG_SERIOUS, ("Failed to allocate Ndis Reset Workitem \n"));
            ndisStatus = NDIS_STATUS_RESOURCES;
            break;
        }

        //
        // Set power state of miniport to D0.
        //
        pAdapter->DevicePowerState = NdisDeviceStateD0;

        //
        // Allocate the Station data structure. This will maintain all 
        // MAC state
        // 
        ndisStatus = Sta11AllocateStation(MiniportAdapterHandle, &pStation);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace (COMP_INIT_PNP, DBG_SERIOUS, ("Sta11AllocateStation failed with status 0x%08x\n", ndisStatus));
            break;
        }

        pAdapter->pStation = pStation;

        //
        // Allocate the NIC data structure. This will include the hardware
        // specific data that Hw11 functions will use
        //
        ndisStatus = Hw11AllocateNic(MiniportAdapterHandle, &pNic, pAdapter, pStation);
        if(ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace (COMP_INIT_PNP, DBG_SERIOUS, ("Hw11AllocateNic failed with status 0x%08x\n", ndisStatus));
            break;
        }
        
        pAdapter->pNic = pNic;

        //
        // Initialize the station state. The NIC is not ready, station cannot yet call any interfaces
        // 
        ndisStatus = Sta11InitializeStation(pStation, pAdapter, pNic);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace (COMP_INIT_PNP, DBG_SERIOUS, ("Sta11InitializeState failed with status 0x%08x\n", ndisStatus));
            break;
        }

        MpInitNBLQueue(&(pAdapter->TxQueue));
        
    }while (FALSE);
    
    if (ndisStatus != NDIS_STATUS_SUCCESS)
    {
        if (pAdapter)
        {
            MpFreeAdapter(pAdapter);
            pAdapter = NULL;
        }
    }
    
    //
    // Return the allocated Adapter refernce
    //
    *ppAdapter = pAdapter;
    
    return ndisStatus;
}


NDIS_STATUS
MpDiscoverAdapterResources(
    IN  PADAPTER                pAdapter,
    IN  PNDIS_RESOURCE_LIST     ResList,
    OUT NDIS_ERROR_CODE*        ErrorCode,
    OUT PULONG                  ErrorValue
    )
{
    ULONG           index;
    NDIS_STATUS     ndisStatus = NDIS_STATUS_SUCCESS;
    BOOLEAN         bResPort = FALSE, bResInterrupt = FALSE, bResMemory = FALSE;
    PCM_PARTIAL_RESOURCE_DESCRIPTOR pResDesc;
    
    do
    {
        for(index=0; index < ResList->Count; index++)
        {
            pResDesc = &ResList->PartialDescriptors[index];

            //
            // Notify Hw11 about the resources found
            //
            ndisStatus = Hw11AddAdapterResource(pAdapter->pNic, pResDesc);
            
            //
            // If the resource was successfully accepted, remember its type
            //
            if (ndisStatus == NDIS_STATUS_SUCCESS)
            {
                switch(pResDesc->Type)
                {
                    case CmResourceTypePort:
                        bResPort = TRUE;
                        break;

                    case CmResourceTypeInterrupt:
                        bResInterrupt = TRUE;
                        break;

                    case CmResourceTypeMemory:
                        bResMemory = TRUE;
                        break;
                }
            }
            else if(ndisStatus != NDIS_STATUS_NOT_ACCEPTED)
            {
                //
                // This is an unrecoverable error. The Hw11 probably came across a resource
                // that caused fatal error while being mapped or used. Details about the
                // the failure should be in the event log. Bail out.
                //
                MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Failed to add adapter resource. Status = 0x%08x\n", ndisStatus));
                break;
            }
        }

        //
        // Make sure that the hardware has found its port, interrupt and memory resources.
        // If any of them is missing, fail initialization
        //
        if(!bResPort || !bResInterrupt || !bResMemory)
        {
            ndisStatus = NDIS_STATUS_RESOURCE_CONFLICT;
            *ErrorCode = NDIS_ERROR_CODE_RESOURCE_CONFLICT;
            
            if(!bResPort)
                *ErrorValue = ERRLOG_NO_IO_RESOURCE;
            else if(!bResInterrupt)
                *ErrorValue = ERRLOG_NO_INTERRUPT_RESOURCE;
            else 
                *ErrorValue = ERRLOG_NO_MEMORY_RESOURCE;            
            break;
        }
    } while(FALSE);

    return ndisStatus;
}


NDIS_STATUS
MpRegisterInterrupt(
    IN  PADAPTER                pAdapter,
    OUT NDIS_ERROR_CODE*        ErrorCode,
    OUT PULONG                  ErrorValue
    )
{
    NDIS_STATUS                 ndisStatus;
    NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS     InterruptChars;

    NdisZeroMemory(&InterruptChars, sizeof(NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS));

    InterruptChars.Header.Type = NDIS_OBJECT_TYPE_MINIPORT_INTERRUPT;
    InterruptChars.Header.Revision = NDIS_MINIPORT_INTERRUPT_REVISION_1;
    InterruptChars.Header.Size = sizeof(NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS);

    InterruptChars.InterruptHandler = MPISR;
    InterruptChars.InterruptDpcHandler = MPHandleInterrupt;
    InterruptChars.DisableInterruptHandler = MPDisableInterrupt;
    InterruptChars.EnableInterruptHandler = MPEnableInterrupt;

    ndisStatus = NdisMRegisterInterruptEx(
        pAdapter->MiniportAdapterHandle,
        pAdapter,
        &InterruptChars,
        &pAdapter->InterruptHandle
        );
    if(ndisStatus != NDIS_STATUS_SUCCESS)
    {
        MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Failed to register interrupt with NDIS. Status = 0x%x\n", ndisStatus));
        *ErrorCode = NDIS_ERROR_CODE_INTERRUPT_CONNECT;
        *ErrorValue = ERRLOG_REGISTER_INTERRUPT_FAILED;
    }

    return ndisStatus;
}


INLINE VOID
MpResetMacMIBs(
    IN  PADAPTER    pAdapter
    )
{
    Hw11ResetMacMIBs(pAdapter->pNic);

    ETH_COPY_NETWORK_ADDRESS(pAdapter->CurrentAddress, pAdapter->PermanentAddress);
    pAdapter->OperationMode     = DOT11_OPERATION_MODE_EXTENSIBLE_STATION;
    pAdapter->AutoConfigEnabled = DOT11_PHY_AUTO_CONFIG_ENABLED_FLAG | 
                                    DOT11_MAC_AUTO_CONFIG_ENABLED_FLAG;
    // Clear netmon mode
    MP_CLEAR_STATUS_FLAG(pAdapter, MP_ADAPTER_NETWORK_MONITOR_MODE);
    pAdapter->State             = INIT_STATE;
    pAdapter->Dot11RunningMode  = RUNNING_MODE_UNKNOWN;
    pAdapter->MaxRxLifeTime     = 512;

    // Choose the correct receive processing handler
    MpAdjustReceiveHandler(pAdapter);

    //
    // Reset all counters. Some of them are not MIBs but we will reset
    // them anyways
    //
    pAdapter->TotalTransmits = 0;
    pAdapter->TotalTransmitsSnapShot = 0;
    pAdapter->NumStalledSendTicks = 0;
    pAdapter->TotalGoodTransmits = 0;
    pAdapter->TotalGoodReceives = 0;
    pAdapter->ReassemblyFailedReceives = 0;
    pAdapter->TotalBadTransmits = 0;
    pAdapter->TotalBadReceives = 0;
    pAdapter->uMPDUMaxLength = Hw11GetMPDUMaxLength(pAdapter->pNic);
}


INLINE VOID
MpResetPhyMIBs(
    IN  PADAPTER    pAdapter
    )
{
    Hw11ResetPhyMIBs(pAdapter->pNic);
}

INLINE NDIS_STATUS
MpSetGeneralAttributes(
    IN  PADAPTER                        pAdapter
    )
{
    NDIS_MINIPORT_ADAPTER_ATTRIBUTES        MiniportAttributes;
    NDIS_PNP_CAPABILITIES                   PnpCapabilities;
    
    NdisZeroMemory(&MiniportAttributes, sizeof(MiniportAttributes));
    MiniportAttributes.GeneralAttributes.Header.Type = NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES;
    MiniportAttributes.GeneralAttributes.Header.Revision = NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES_REVISION_1;
    MiniportAttributes.GeneralAttributes.Header.Size = sizeof(NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES);

    MiniportAttributes.GeneralAttributes.MediaType = MP_MEDIA_TYPE;
    MiniportAttributes.GeneralAttributes.PhysicalMediumType = MP_PHYSICAL_MEDIA_TYPE;    
    MiniportAttributes.GeneralAttributes.MtuSize = MP_802_11_MAX_FRAME_SIZE - MP_802_11_SHORT_HEADER_SIZE;
    MiniportAttributes.GeneralAttributes.MaxXmitLinkSpeed = HW11_LINK_SPEED;
    MiniportAttributes.GeneralAttributes.MaxRcvLinkSpeed = HW11_LINK_SPEED;
    MiniportAttributes.GeneralAttributes.XmitLinkSpeed = NDIS_LINK_SPEED_UNKNOWN;
    MiniportAttributes.GeneralAttributes.RcvLinkSpeed = NDIS_LINK_SPEED_UNKNOWN;
    MiniportAttributes.GeneralAttributes.MediaConnectState = MediaConnectStateConnected;
    MiniportAttributes.GeneralAttributes.MediaDuplexState = MediaDuplexStateHalf;
    MiniportAttributes.GeneralAttributes.LookaheadSize = MP_802_11_MAXIMUM_LOOKAHEAD;
    MiniportAttributes.GeneralAttributes.PowerManagementCapabilities = &PnpCapabilities;
    Hw11QueryPnPCapabilities(pAdapter->pNic, MiniportAttributes.GeneralAttributes.PowerManagementCapabilities);
    
    MiniportAttributes.GeneralAttributes.MacOptions = NDIS_MAC_OPTION_COPY_LOOKAHEAD_DATA | 
                                         NDIS_MAC_OPTION_TRANSFERS_NOT_PEND |
                                         NDIS_MAC_OPTION_NO_LOOPBACK;
    
    MiniportAttributes.GeneralAttributes.SupportedPacketFilters = NDIS_PACKET_TYPE_DIRECTED |
                                                     NDIS_PACKET_TYPE_MULTICAST |
                                                     NDIS_PACKET_TYPE_ALL_MULTICAST |
                                                     NDIS_PACKET_TYPE_BROADCAST;
    
    MiniportAttributes.GeneralAttributes.MaxMulticastListSize = HW11_MAX_MCAST_LIST_SIZE;
    MiniportAttributes.GeneralAttributes.MacAddressLength = ETH_LENGTH_OF_ADDRESS;
    
    NdisMoveMemory(
        &MiniportAttributes.GeneralAttributes.PermanentMacAddress,
        pAdapter->PermanentAddress,
        ETH_LENGTH_OF_ADDRESS
        );
    
    NdisMoveMemory(
        &MiniportAttributes.GeneralAttributes.CurrentMacAddress,
        pAdapter->CurrentAddress,
        ETH_LENGTH_OF_ADDRESS
        );
    
    MiniportAttributes.GeneralAttributes.RecvScaleCapabilities = NULL;
    MiniportAttributes.GeneralAttributes.AccessType = NET_IF_ACCESS_BROADCAST;
    MiniportAttributes.GeneralAttributes.DirectionType = NET_IF_DIRECTION_SENDRECEIVE;
    MiniportAttributes.GeneralAttributes.IfType = IF_TYPE_IEEE80211;
    MiniportAttributes.GeneralAttributes.IfConnectorPresent = TRUE;
    MiniportAttributes.GeneralAttributes.DataBackFillSize = HW11_REQUIRED_BACKFILL_SIZE;

    MpQuerySupportedOidsList(
        &MiniportAttributes.GeneralAttributes.SupportedOidList,
        &MiniportAttributes.GeneralAttributes.SupportedOidListLength
        );
    
    //
    // Register the Generic miniport attributes with NDIS
    //
    return NdisMSetMiniportAttributes(
        pAdapter->MiniportAdapterHandle,
        &MiniportAttributes
        );
}

INLINE NDIS_STATUS
MpSet80211Attributes(
    IN  PADAPTER                        pAdapter
    )
{
    NDIS_STATUS ndisStatus = NDIS_STATUS_SUCCESS;
    NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES  attr;

    __try
    {
        NdisZeroMemory(&attr, sizeof(NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES));

        attr.Header.Type = NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES;
        attr.Header.Revision = NDIS_MINIPORT_ADAPTER_802_11_ATTRIBUTES_REVISION_1;
        attr.Header.Size = sizeof(NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES);
        attr.OpModeCapability = (DOT11_OPERATION_MODE_EXTENSIBLE_STATION |
                                 DOT11_OPERATION_MODE_NETWORK_MONITOR);

        //
        // Call Hardware and Station lay to fill the attribute structure.
        //
        ndisStatus = Hw11Fill80211Attributes(pAdapter->pNic, &attr);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
            __leave;

        ndisStatus = Sta11Fill80211Attributes(pAdapter->pStation, &attr);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
            __leave;


        //
        // Register the 802.11 miniport attributes with NDIS
        //
        NdisMSetMiniportAttributes(
            pAdapter->MiniportAdapterHandle,
            (PNDIS_MINIPORT_ADAPTER_ATTRIBUTES)&attr
            );
    }
    __finally
    {
        //
        // Call Hardware and Station lay to clean up the attribute structure.
        //
        Hw11Cleanup80211Attributes(pAdapter->pNic, &attr);
        Sta11Cleanup80211Attributes(pAdapter->pStation, &attr);
    }

    return ndisStatus;
}

VOID 
MpInternalPause(
    IN  PADAPTER                            pAdapter,
    IN  PNDIS_MINIPORT_PAUSE_PARAMETERS     MiniportPauseParameters
    )
{
    UNREFERENCED_PARAMETER(MiniportPauseParameters);
    
    MPVERIFY(MP_GET_NDIS_PNP_STATE(pAdapter) == MINIPORT_PAUSING);

    //
    // Pause Step 2 - Force cleanup
    //

    //
    // Send lock to serialize against other operations
    //
    MP_ACQUIRE_SEND_LOCK(pAdapter, FALSE);

    //
    // Notify hardware about pause. As an optimization, hardware can
    // turn off send receive units etc.
    //
    Hw11MiniportPause(pAdapter->pNic, MiniportPauseParameters);
    
    //
    // Cancel all pending sends
    //
    MpCompleteQueuedTxMSDUs(pAdapter);
    
    //
    // Complete all packets pending in the TxQueue
    //
    MpCompleteQueuedNBL(pAdapter);

    MP_RELEASE_SEND_LOCK(pAdapter, FALSE);
}


/**
 * This helper function uses NDIS API to read keys and values from the registry.
 * Use these values to make any configurations that the user may want.
 * It is always recommended to access the registry and initialize everything while
 * in the context on MiniportInitialize. Reading and writing to registry while NIC is
 * up and running always causes a performace hit.
 * 
 * \param pAdapter          The adapter whose configuration will be read
 * \sa MpInitialize
 */
VOID
MpReadRegistryConfiguration(
    IN OUT PADAPTER pAdapter
    )
{
    NDIS_STATUS                     ndisStatus = NDIS_STATUS_SUCCESS;
    ULONG                           i, ValueRead;
    PUCHAR                          pucDestination;
    PMP_REG_ENTRY                   pRegEntry;
    PNDIS_CONFIGURATION_PARAMETER   Parameter = NULL;
    BOOLEAN                         bRegistryOpened;
    NDIS_HANDLE                     RegistryConfigurationHandle;
    NDIS_CONFIGURATION_OBJECT       ConfigObject;

    ConfigObject.Header.Type = NDIS_OBJECT_TYPE_CONFIGURATION_OBJECT;
    ConfigObject.Header.Revision = NDIS_CONFIGURATION_OBJECT_REVISION_1;
    ConfigObject.Header.Size = sizeof( NDIS_CONFIGURATION_OBJECT );
    ConfigObject.NdisHandle = pAdapter->MiniportAdapterHandle;
    ConfigObject.Flags = 0;

    ndisStatus = NdisOpenConfigurationEx(
                    &ConfigObject,
                    &RegistryConfigurationHandle
                    );

    if (ndisStatus == NDIS_STATUS_SUCCESS)
    {
        bRegistryOpened = TRUE;
    }
    else
    {
        MpTrace (COMP_INIT_PNP, DBG_SERIOUS, ("Unable to Open Configuration. Will revert to defaults for all values\n"));
        bRegistryOpened = FALSE;
    }
    
    for(i=0; i<MP_NUM_REG_PARAMS; i++)
    {
        //
        // Get the registry entry we will be reading
        //
        pRegEntry= &MPRegTable[i];

        //
        // Figure out where in the adapter structure this value will be placed
        //
        pucDestination = (PUCHAR) pAdapter + pRegEntry->FieldOffset;

        //
        // Read this entry from the registry. All parameters under NT are DWORDs
        //
        if (bRegistryOpened == TRUE)
        {
            NdisReadConfiguration(
                &ndisStatus,
                &Parameter,
                RegistryConfigurationHandle,
                &pRegEntry->RegName,
                NdisParameterInteger
                );
        }
        else
        {
            //
            // Report failure of reading registry. Will revert to defaults
            //
            ndisStatus = NDIS_STATUS_FAILURE;
        }

        if (ndisStatus == NDIS_STATUS_SUCCESS)
        {
            if(Parameter->ParameterData.IntegerData < pRegEntry->Min || 
                Parameter->ParameterData.IntegerData > pRegEntry->Max)
            {
                MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("A bad value %d read from registry. Reverting to default value %d",
                                            Parameter->ParameterData.IntegerData,
                                            pRegEntry->Default
                                            ));
                ValueRead = pRegEntry->Default;
            }
            else
            {
                ValueRead = Parameter->ParameterData.IntegerData;
            }
        }
        else
        {
            MpTrace(COMP_INIT_PNP, DBG_NORMAL, ("Unable to read from registry. Reverting to default value: %d\n",
                                        pRegEntry->Default
                                        ));
            ValueRead = pRegEntry->Default;
        }

        //
        // Moving the registry values in the adapter data structure
        //
        switch(pRegEntry->FieldSize)
        {
            case 1:
                *((PUCHAR) pucDestination)  = (UCHAR) ValueRead;
                break;
            case 2:
                *((PUSHORT) pucDestination) = (USHORT) ValueRead;
                break;
            case 4:
                *((PULONG) pucDestination)  = (ULONG) ValueRead;
                break;
            default:
                MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Bogus field size %d\n", pRegEntry->FieldSize));
                break;
        }
    }

    //
    // Now allow the hardware to read its own parameters from registry
    //
    Hw11ReadRegistryConfiguration(pAdapter->pNic, RegistryConfigurationHandle);

    //
    // Now allow the station to read its own parameters from registry
    //
    Sta11ReadRegistryConfiguration(pAdapter->pStation, RegistryConfigurationHandle);

    //
    // Close the handle to the registry
    //
    if (RegistryConfigurationHandle)
    {
        NdisCloseConfiguration(RegistryConfigurationHandle);
    }

    
    if (ndisStatus != NDIS_STATUS_SUCCESS)
    {
        MpTrace (COMP_INIT_PNP, DBG_SERIOUS, ("Failed to read from registry. Status = 0x%08x\n", ndisStatus));
    }
}


NDIS_STATUS
MpGetAdapterStatus(
    IN PADAPTER         pAdapter
    )
{
    NDIS_STATUS ndisStatus;

    if (MP_TEST_STATUS_FLAG(pAdapter, MP_ADAPTER_NDIS_PAUSE_IN_PROGRESS))
        ndisStatus = NDIS_STATUS_PAUSED;
    else if (MP_TEST_STATUS_FLAG(pAdapter, MP_ADAPTER_RESET_IN_PROGRESS))
        ndisStatus = NDIS_STATUS_RESET_IN_PROGRESS;
    else if (MP_TEST_STATUS_FLAG(pAdapter, MP_ADAPTER_HALT_IN_PROGRESS))
        ndisStatus = NDIS_STATUS_CLOSING;
    else if (MP_TEST_STATUS_FLAG(pAdapter, MP_ADAPTER_SURPRISE_REMOVED))
        ndisStatus = NDIS_STATUS_CLOSING;
    else if (MP_TEST_STATUS_FLAG(pAdapter, MP_ADAPTER_REMOVE_IN_PROGRESS))
        ndisStatus = NDIS_STATUS_CLOSING;
    else if MP_TEST_STATUS_FLAG(pAdapter, MP_ADAPTER_HARDWARE_ERROR)
        ndisStatus = NDIS_STATUS_DEVICE_FAILED;
    else
        ndisStatus = NDIS_STATUS_FAILURE;       // return a generc error

    return ndisStatus;
}


INLINE BOOLEAN
MpRemoveAdapter(
    IN PADAPTER pAdapter
    )
{
    if (!(MP_SET_CLEAR_STATUS_FLAG(
            pAdapter,
            MP_ADAPTER_REMOVE_IN_PROGRESS,      // Set this bit
            MP_ADAPTER_RESET_IN_PROGRESS        // Clear this bit
            ) & MP_ADAPTER_REMOVE_IN_PROGRESS))  // Test this bit
    {
        //
        // Request a removal.
        //
        NdisWriteErrorLogEntry(
            pAdapter->MiniportAdapterHandle,
            NDIS_ERROR_CODE_HARDWARE_FAILURE,
            1,
            ERRLOG_REMOVE_MINIPORT
            );
        
        NdisMRemoveMiniport(pAdapter->MiniportAdapterHandle);

        return TRUE;
    }
    else
    {
        //
        // Adapter is already in removal. No need to request one.
        //
        return FALSE;
    }
}


/**
 * This routine resets the miniport. As part of reset, the NIC is asked to stop its
 * interrupts, send and receive units (and any other units NIC feels should be reset).
 * All submitted TX_MSDUs that have not yet been sent are failed. Any packets waiting in
 * the TxQueue are also failed.
 *
 * \param pAdapter      The adapter being reset
 * \param ResetType     The type of reset to perform 
 * \sa MpReset, MpResetWorkItem
 */
INLINE NDIS_STATUS
MpResetInternalRoutine(
    IN PADAPTER             pAdapter,
    IN MP_RESET_TYPE        ResetType
    )
{
    //
    // CHANGED BEHAVIOR ON 6/10/2006 TO BE CALLED AT DISPATCH WITH SEND_LOCK HELD
    //
    
    NDIS_STATUS ndisStatus;
    
    MpEntry;

    //
    // Reset Step 2 - Force cleanup
    //

    //
    // Disable interrupts
    //
    Hw11DisableInterrupt(pAdapter->pNic);
    
    do
    {
        //
        // Issue a reset start to the NIC. Nic should suspend transmit and receive units
        // among other things.
        //
        ndisStatus = Hw11ResetStep2(pAdapter->pNic);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("An error 0x%08x occured during Hw11ResetStep2. Will attempt to continue\n", ndisStatus));
            if (ndisStatus != NDIS_STATUS_SOFT_ERRORS)
            {
                MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Unable to recover from the error. Aborting reset request\n"));
                break;
            }
        }

        //
        // Notify CustomInterfaces about the reset operation
        //
        MpEventMiniportReset(pAdapter); 

        //
        // Ask the station to reset
        //
        Sta11ResetStep2(pAdapter->pStation, ResetType);

        //
        // Try to free the unsent packets that have been submitted to the hardware
        //
        MpCompleteQueuedTxMSDUs(pAdapter);

        //
        // Free the packets that are waiting in the TxQueue.
        //
        MpCompleteQueuedNBL(pAdapter);

        //
        // Reintialize the send engine to bring to init state
        //
        MpReinitializeSendEngine(pAdapter);
        
    } while(FALSE);

    //
    // Everything has been cleaned up, we dont need the lock to reset the hardware
    //
    MP_RELEASE_SEND_LOCK(pAdapter, FALSE);

    //
    // Reset Step 3 - Reinitialize MAC and PHY state
    //
    ndisStatus = Hw11ResetStep3(pAdapter->pNic, ResetType);
    if (ndisStatus != NDIS_STATUS_SUCCESS)
    {
        MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Failure occured while resetting the NIC. Reset Type: %d, Error: 0x%08x\n", ResetType, ndisStatus));

        MP_ACQUIRE_SEND_LOCK(pAdapter, FALSE);
        //
        // Enable the interrupts back on
        //
        Hw11EnableInterrupt(pAdapter->pNic);       
        return ndisStatus;  // Send lock held
    }

    //
    // Reset Step 4 - Restart anything that may have been stopped
    //
    MP_ACQUIRE_SEND_LOCK(pAdapter, FALSE);
    
    //
    // Issue a reset end to the NIC. Hw11 should reinitialize all the Rx descriptors
    // and restart send/receive units among other things.
    //
    ndisStatus = Hw11ResetStep4(pAdapter->pNic);
    if (ndisStatus != NDIS_STATUS_SUCCESS)
    {
        MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("An error 0x%08x occured during Hw11ResetStep4.\n", ndisStatus));
    }

    //
    // Enable the interrupts back on
    //
    Hw11EnableInterrupt(pAdapter->pNic);

    MpExit;
    return ndisStatus;
}


/**
 * This is the work item in which NDIS reset operation will be executed if
 * it was pended.
 *
 * This routine waits for any active senders doing send to complete. When
 * they do complete, MpResetInternalRoutine is invoked which executes the
 * actual reset of the miniport driver and the hardware.
 * 
 * \param Context       The context we registered when initializing the NIC
 * \sa MpReset, MpResetInternalRoutine
 */
VOID
MpResetWorkItem(
    IN PVOID            Context,
    IN NDIS_HANDLE      NdisIoWorkItemHandle
    )
{
    NDIS_STATUS     ndisStatus;
    PADAPTER        pAdapter = (PADAPTER) Context;
    UNREFERENCED_PARAMETER(NdisIoWorkItemHandle);

    //
    // This lock synchronizes between Reset/Pause/Restart
    //
    MP_ACQUIRE_RESET_PNP_LOCK(pAdapter);

    //
    // If the scan operation is in progress, cancel it.
    //
    if (MP_TEST_STATUS_FLAG(pAdapter, MP_ADAPTER_HW_IS_SCANNING))
    {
        Hw11CancelScan(pAdapter->pNic);
    }
    MPVERIFY(!MP_TEST_STATUS_FLAG(pAdapter, MP_ADAPTER_HW_IS_SCANNING));

    //
    // Reset Step 1 - Wait for things to cleanup
    //

    //
    // Dont redo the work that is already done by
    // the Dot11Reset/Pause routines (protected by PNP lock)
    //
    if (MP_INCREMENT_RESET_PAUSE_COUNT(pAdapter) == 1)
    {
        //
        // Remove the Active Sender count we added during Initialize
        //
        MP_DECREMENT_ACTIVE_SENDERS(pAdapter);
        NdisWaitEvent(&pAdapter->ActiveSendersDoneEvent, MP_NEVER_TIMEOUT);
        
        //
        // Wait for all pending SG operations to complete
        //
        MP_DECREMENT_ADAPTER_PENDING_SG_OP(pAdapter);
        NdisWaitEvent(&pAdapter->SGOperationsDoneEvent, MP_NEVER_TIMEOUT);
        
        //
        // Remove the Active Receivers count added during Initialize
        // We can Reset when the count reaches 1 or less.
        //
        MP_DECREMENT_ACTIVE_RECEIVERS(pAdapter);
        while(pAdapter->NumActiveReceivers >= 1)
        {
            NdisMSleep(10 * 1000);  // 10 msec
        }
    }
    
    //
    // Have the station reset
    //
    Sta11ResetStep1(pAdapter->pStation, MP_RESET_TYPE_NDIS_RESET);

    MP_ACQUIRE_SEND_LOCK(pAdapter, FALSE);
    ndisStatus = MpResetInternalRoutine(pAdapter, MP_RESET_TYPE_NDIS_RESET);

    //
    // Reset the variables that may have potentially caused the reset to occur
    //
    pAdapter->TotalTransmitsSnapShot = 0;
    pAdapter->NumStalledSendTicks = 0;

    //
    // Undo the pause/reset work from before
    //
    if (MP_DECREMENT_RESET_PAUSE_COUNT(pAdapter) == 0)
    {
        //
        // Reset the ActiveSenders Event and put the reference back on
        //
        MP_INCREMENT_ACTIVE_SENDERS(pAdapter);
        NdisResetEvent(&pAdapter->ActiveSendersDoneEvent);
        
        //
        // Reset the SGOperations event and put the ref back
        //
        MP_INCREMENT_ADAPTER_PENDING_SG_OP(pAdapter);
        NdisResetEvent(&pAdapter->SGOperationsDoneEvent);

        //
        // Place the Ref Count back on ActiveReceivers.
        //
        MP_INCREMENT_ACTIVE_RECEIVERS(pAdapter);
    }

    //
    // After NdisReset, the station may reassociate if it was already
    // associated
    //
    Sta11ResetStep4(pAdapter->pStation, MP_RESET_TYPE_NDIS_RESET);

    if (ndisStatus == NDIS_STATUS_SUCCESS || ndisStatus == NDIS_STATUS_SOFT_ERRORS)
    {
        //
        // Reset completed successfully. Soft errors are recoverable.
        // Reset the NumResetAttempts counter and clear any error flags if set.
        //
        pAdapter->NumResetAttempts = 0;
        MP_CLEAR_STATUS_FLAG(pAdapter, (MP_ADAPTER_RESET_IN_PROGRESS | MP_ADAPTER_HARDWARE_ERROR | MP_ADAPTER_NON_RECOVER_ERROR));
        ndisStatus = NDIS_STATUS_SUCCESS;
    }
    else
    {
        //
        // Reset did not occur successfully.
        //
        if (pAdapter->NumResetAttempts < MP_RESET_ATTEMPTS_THRESHOLD)
        {
            //
            // Another attempt failed. Will try again later.
            //
            pAdapter->NumResetAttempts++;
        }
        else
        {
            //
            // Repeated attempts to reset have failed. Remove this adapter.
            //
            MpRemoveAdapter(pAdapter);
        }

        //
        // Reset completed but not successfully. Leave error bits on
        //
        MP_CLEAR_STATUS_FLAG(pAdapter, MP_ADAPTER_RESET_IN_PROGRESS);
    }

    MP_RELEASE_SEND_LOCK(pAdapter, FALSE);
    
    MP_RELEASE_RESET_PNP_LOCK(pAdapter);

    //
    // notify NDIS that reset is complete
    //
    NdisMResetComplete(
        pAdapter->MiniportAdapterHandle,
        ndisStatus,
        HW11_REQUIRES_ADDRESS_RESET
        );
}



INLINE VOID
MpOnSurpriseRemoval(
    IN  PADAPTER        pAdapter
    )
{
    //
    // Set the surprise removal flag. We need to remember this
    // in case other requests get submitted to the miniport
    //
    MP_SET_STATUS_FLAG(pAdapter, MP_ADAPTER_SURPRISE_REMOVED);

    MP_ACQUIRE_SEND_LOCK(pAdapter, FALSE);

    //
    // Any NBL that may be pending in the hardware or driver
    // must be failed back to NDIS with the appropriate error code
    //
    MpCompleteQueuedTxMSDUs(pAdapter);
    
    MpCompleteQueuedNBL(pAdapter);
    
    MP_RELEASE_SEND_LOCK(pAdapter, FALSE);
}


//
// NDIS and WDM Driver handlers
//

NTSTATUS
DriverEntry(
    IN    PDRIVER_OBJECT        pDriverObject,
    IN    PUNICODE_STRING       RegistryPath
    )
{
    NDIS_STATUS                             Status = NDIS_STATUS_FAILURE;
    NDIS_MINIPORT_DRIVER_CHARACTERISTICS    MChars;

    #if DOT11_TRACE_ENABLED
        WPP_INIT_TRACING(pDriverObject, RegistryPath);
    #endif

    MpTrace(COMP_INIT_PNP, DBG_SERIOUS, (__DATE__ " " __TIME__ " DriverEntry called!\n"));

    do
    {
        NdisZeroMemory(&MChars, sizeof(NDIS_MINIPORT_DRIVER_CHARACTERISTICS));

        //
        // Set the type and version of this structure
        //
        MChars.Header.Type      = NDIS_OBJECT_TYPE_MINIPORT_DRIVER_CHARACTERISTICS;
        MChars.Header.Size      = sizeof(NDIS_MINIPORT_DRIVER_CHARACTERISTICS);
        MChars.Header.Revision  = NDIS_MINIPORT_DRIVER_CHARACTERISTICS_REVISION_1;
        
        MChars.MajorNdisVersion = MP_MAJOR_NDIS_VERSION;
        MChars.MinorNdisVersion = MP_MINOR_NDIS_VERSION;

        MChars.MajorDriverVersion = HW11_MAJOR_DRIVER_VERSION;
        MChars.MinorDriverVersion = HW11_MINOR_DRIVER_VERSION;

        //
        // Init/PnP handlers
        //
        MChars.InitializeHandlerEx      = MPInitialize;
        MChars.RestartHandler           = MPRestart;
        MChars.PauseHandler             = MPPause;
        MChars.ShutdownHandlerEx        = MPAdapterShutdown;
        MChars.DevicePnPEventNotifyHandler  = MPDevicePnPEvent;
        MChars.HaltHandlerEx            = MPHalt;
        MChars.UnloadHandler            = DriverUnload;
        
        //
        // Query/Set/Method requests handlers
        //
        MChars.OidRequestHandler        = MPRequest;
        MChars.CancelOidRequestHandler  = MPCancelRequest;

        //
        // Set optional miniport services handler
        //
        MChars.SetOptionsHandler        = MPSetOptions;
        
        //
        // Send/Receive handlers
        //
        MChars.SendNetBufferListsHandler    = MPSendNetBufferLists;
        MChars.CancelSendHandler            = MPCancelSendNetBufferLists;
        MChars.ReturnNetBufferListsHandler  = MPReturnNetBufferLists;
        
        //
        // Fault handling handlers
        //
        MChars.CheckForHangHandlerEx        = MPCheckForHang;
        MChars.ResetHandlerEx               = MPReset;
                
        //
        // Register the miniport driver with NDIS
        //
        Status = NdisMRegisterMiniportDriver(
                    pDriverObject,
                    RegistryPath,
                    GlobalDriverContext,
                    &MChars,
                    &GlobalDriverHandle
                    );
        if (Status != NDIS_STATUS_SUCCESS)
        {
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Failed to register miniport with NDIS. Status = 0x%x\n", Status));
            break;
        }

#if DBG
#if !DOT11_TRACE_ENABLED
        //
        // Read debug mask from registry
        //
        MpReadGlobalDebugMask(GlobalDriverHandle);
#endif
#endif

    }
    while (FALSE);
    
    if (Status != NDIS_STATUS_SUCCESS)
    {
        #if DOT11_TRACE_ENABLED
            WPP_CLEANUP(pDriverObject);
        #endif
    }

    return(Status);
}


VOID
DriverUnload(
    IN    PDRIVER_OBJECT            DriverObject
    )
{
    UNREFERENCED_PARAMETER(DriverObject);
    
    MpEntry;
    
    //
    // Deregister this miniport from NDIS
    //
    NdisMDeregisterMiniportDriver(GlobalDriverHandle);
    
    MpExit;
    
    #if DOT11_TRACE_ENABLED
        WPP_CLEANUP(DriverObject);
    #endif

    MP_DUMP_LEAKING_BLOCKS();
}


NDIS_STATUS 
MPInitialize(
    IN  NDIS_HANDLE                        MiniportAdapterHandle,
    IN  NDIS_HANDLE                        MiniportDriverContext,
    IN  PNDIS_MINIPORT_INIT_PARAMETERS     MiniportInitParameters
    )
{
    PADAPTER                    pAdapter = NULL;
    NDIS_STATUS                 ndisStatus = NDIS_STATUS_SUCCESS;
    NDIS_ERROR_CODE             ErrorCode = NDIS_STATUS_SUCCESS;    
    ULONG                       ErrorValue = 0;
    BOOLEAN                     bHw11Initialized = FALSE, bInterruptRegistered = FALSE;
    BOOLEAN                     bSendEngineInitialized = FALSE, bReceiveEngineInitialized = FALSE;
    BOOLEAN                     bHw11Started = FALSE, bCustomInterfacesInitialized = FALSE;
    BOOLEAN                     bSta11Started = FALSE;
    NDIS_MINIPORT_ADAPTER_ATTRIBUTES    MiniportAttributes;
    
    UNREFERENCED_PARAMETER(MiniportDriverContext);
    
    MpEntry;
    
    MpTrace(COMP_INIT_PNP, DBG_LOUD, ("MiniportAdapterHandle: %p\n", MiniportAdapterHandle));
    
    do
    {
        //
        // Allocate the Adapter data structure
        //
        ndisStatus = MpAllocateAdapter (MiniportAdapterHandle, &pAdapter);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
            break;
        
        pAdapter->MiniportAdapterHandle = MiniportAdapterHandle;
        
        //
        // Set the miniport registration attributes with NDIS
        //
        NdisZeroMemory(&MiniportAttributes, sizeof(MiniportAttributes));
        MiniportAttributes.RegistrationAttributes.Header.Type = NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES;
        MiniportAttributes.RegistrationAttributes.Header.Revision = NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES_REVISION_1;
        MiniportAttributes.RegistrationAttributes.Header.Size = sizeof(NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES);
        MiniportAttributes.RegistrationAttributes.MiniportAdapterContext = pAdapter;
        MiniportAttributes.RegistrationAttributes.AttributeFlags = HW11_NDIS_MINIPORT_ATTRIBUTES;
        MiniportAttributes.RegistrationAttributes.CheckForHangTimeInSeconds = HW11_CHECK_FOR_HANG_TIME_IN_SECONDS;
        MiniportAttributes.RegistrationAttributes.InterfaceType = HW11_BUS_INTERFACE_TYPE;

        NdisMSetMiniportAttributes(
            MiniportAdapterHandle,
            &MiniportAttributes
            );

        //
        // Access registry configuration parameters for this miniport.
        //
        MpReadRegistryConfiguration(
                    pAdapter
                    );
        
        //
        // Find the adapter on the bus and read its bus configuration space
        //
        ndisStatus = Hw11FindAdapter(pAdapter->pNic, &ErrorCode, &ErrorValue);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            break;
        }

        //
        // Find the resources that have been assigned to this adapter
        //
        ndisStatus = MpDiscoverAdapterResources(
                        pAdapter,
                        MiniportInitParameters->AllocatedResources,
                        &ErrorCode,
                        &ErrorValue
                        );
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            break;
        }

        //
        // Initialize the hardware.
        //
        ndisStatus = Hw11InitializeNic(pAdapter->pNic);
        if(ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Failed to initialize NIC successfully.\n"));
            break;
        }
        bHw11Initialized = TRUE;
 
        //
        // Fill the Miniport 802.11 Attributes, we can do so as soon as NIC is initialized.
        //
        ndisStatus = MpSet80211Attributes(pAdapter);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Failed to set 80211 attributes\n"));
            break;
        }

        //
        // Initialize the Mp Send Engine. This will also initialize Hw11 Send engine
        // 
        ndisStatus = MpInitializeSendEngine(pAdapter);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Failed to initialize the Send Engine\n"));
            break;
        }
        bSendEngineInitialized = TRUE;

        //
        // Initialize the Hw11 Receive Engine. This will also initialize Mp Receive engine
        // 
        ndisStatus = Hw11InitializeReceive(pAdapter->pNic, pAdapter->TotalRxMSDU);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Failed to initialize the Receive Engine\n"));
            break;
        }
        bReceiveEngineInitialized = TRUE;

        //
        // Initialize Custom Interfaces for this miniport driver
        //
        ndisStatus = MpEventInitialize(pAdapter);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Failed to initialize the Custom Interfaces\n"));
            break;
        }
        bCustomInterfacesInitialized = TRUE;

        //
        // Disable interrupts
        // We should disable interrupts before the are registered.
        // They will be enabled right at the end of Initialize
        //
        Hw11DisableInterrupt(pAdapter->pNic);

        //
        // Register interrupt with NDIS
        //
        ndisStatus = MpRegisterInterrupt(
            pAdapter,
            &ErrorCode,
            &ErrorValue
            );
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Failed to register interrupt with NDIS\n"));
            break;
        }

        bInterruptRegistered = TRUE;
        
        //
        // Start the NIC. If anything fails after this point,
        // we must issue a Halt to the NIC before returning
        // from initialize
        //
        ndisStatus = Hw11StartNic(pAdapter->pNic);
        if(ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Failed to start NIC successfully.\n"));
            break;
        }
        bHw11Started = TRUE;

        //
        // Initialize the MIB values we maintain at MP level
        //
        ETH_COPY_NETWORK_ADDRESS(pAdapter->PermanentAddress, Hw11GetMACAddress(pAdapter->pNic));
        MpResetMacMIBs(pAdapter);
        MpResetPhyMIBs(pAdapter);

        //
        // Fill the Miniport Generic Attributes
        //
        ndisStatus = MpSetGeneralAttributes(pAdapter);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Failed to set general attributes\n"));
            break;
        }

        //
        // The miniport will start in the Paused PnP state
        //
        MP_SET_NDIS_PNP_STATE(pAdapter, MINIPORT_PAUSED);

        //
        // We are started as paused. Add the paused counter. When we restart
        // again, we will be adding refcounts for active receives, pending
        // SG operations, etc
        //
        MP_INCREMENT_RESET_PAUSE_COUNT(pAdapter);        

        //
        // This Ref count should be incremented if there are any
        // operations outstanding on this miniport that should prevent
        // miniport from halting
        //
        MP_INCREMENT_REF(pAdapter);
        
        //
        // Enable interrupts on the NIC.
        //
        MpTrace(COMP_INIT_PNP, DBG_LOUD, ("Turning Interrupts on!\n"));
        Hw11EnableInterrupt(pAdapter->pNic);
        
        //
        // Run NIC self-test if it is needed
        //
        ndisStatus = Hw11SelfTest(pAdapter->pNic);
        if(ndisStatus != NDIS_STATUS_SUCCESS)
        {
            Hw11DisableInterrupt(pAdapter->pNic);
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Hardware failed self test. Could not initialize\n"));
            break;
        }

        //
        // The NIC is ready to go, initialize the station
        //
        ndisStatus = Sta11StartStation(pAdapter->pStation);
        if(ndisStatus != NDIS_STATUS_SUCCESS)
        {
            Hw11DisableInterrupt(pAdapter->pNic);
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Station failed initialize\n"));
            break;
        }
        bSta11Started = TRUE;

        ndisStatus = NDIS_STATUS_SUCCESS;
    } while(FALSE);
    
    if (ndisStatus != NDIS_STATUS_SUCCESS)
    {
        MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("MPInitialize failed! Error code: 0x%08x\n", ndisStatus));
        
        //
        // Initialization failed. Free up any resources that are currently allocated
        //
        if (pAdapter)
        {
            if (bInterruptRegistered)
                NdisMDeregisterInterruptEx(pAdapter->InterruptHandle);  // Remove interrupt ASAP
            if (bSta11Started)                              // Stop the station
                Sta11StopStation(pAdapter->pStation, NdisHaltDeviceInitializationFailed);       
            if (bHw11Initialized)
                Hw11TerminateNic(pAdapter->pNic);           // Uninitialize the NIC
            if (bReceiveEngineInitialized)
                Hw11TerminateReceive(pAdapter->pNic);       // Free all receive resources
            if (bSendEngineInitialized)
                MpTerminateSendEngine(pAdapter);            // Free all send resources
            if(bCustomInterfacesInitialized)
                MpEventTerminate(pAdapter); 

            //
            // Now free allocated resources. This also frees resources allocated by NIC
            //
            MpFreeAdapter(pAdapter);
        }
        
        if (ErrorCode != NDIS_STATUS_SUCCESS)
        {
            NdisWriteErrorLogEntry(
                pAdapter->MiniportAdapterHandle,
                ErrorCode,
                1,
                ErrorValue
                );
        }
    }

    MpExit;

    return ndisStatus;
}


NDIS_STATUS 
MPRestart(
    IN  NDIS_HANDLE     MiniportAdapterContext,
    IN  PNDIS_MINIPORT_RESTART_PARAMETERS   MiniportRestartParameters
    )
{
    PADAPTER        pAdapter = (PADAPTER) MiniportAdapterContext;
    NDIS_STATUS     ndisStatus;
    
    UNREFERENCED_PARAMETER(MiniportRestartParameters);
    
    MpEntry;

    MP_VERIFY_PASSIVE_IRQL();

    MPASSERT(MP_GET_NDIS_PNP_STATE(pAdapter) == MINIPORT_PAUSED);

    //
    // Synchronize the Restart operation with Pause and Reset
    //
    MP_ACQUIRE_RESET_PNP_LOCK(pAdapter);

    do
    {
        MP_ACQUIRE_SEND_LOCK(pAdapter, FALSE);

        //
        // If no Reset/Dot11Reset is pending, we can restart
        //
        if (MP_DECREMENT_RESET_PAUSE_COUNT(pAdapter) == 0)
        {
            //
            // This Ref Count will be removed on Pause. Needed to make sure no receives
            // are occuring when Pause occurs
            //
            MP_INCREMENT_ACTIVE_RECEIVERS(pAdapter);
            
            //
            // We always keep one reference on active senders unless we are pausing/halting
            // or resetting. This avoid repeated signal of the associated event. We will
            // be resetting that event as well
            //
            MP_INCREMENT_ACTIVE_SENDERS(pAdapter);
            NdisResetEvent(&pAdapter->ActiveSendersDoneEvent);

            //
            // Always keep one reference for purpose of PnP on SG Operations
            //
            MP_INCREMENT_ADAPTER_PENDING_SG_OP(pAdapter);
        }
        
        //
        // Increment the receive Ref count on the miniport. The reciprocal for this
        // call is in MiniportPause. This way we will not signal AllReceivesHaveReturned
        // event till MiniportPause is called.
        //
        MP_INCREMENT_PENDING_RECEIVES(pAdapter);
        NdisResetEvent(&pAdapter->AllReceivesHaveReturnedEvent);
        
        //
        // Notify the hardware so it can undone any ops done during Pause
        //
        ndisStatus = Hw11MiniportRestart(pAdapter->pNic, MiniportRestartParameters);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Hw11MiniportRestart failed with status 0x%08x\n", ndisStatus));
            MP_RELEASE_SEND_LOCK(pAdapter, FALSE);
            break;
        }
        
        //
        // The miniport is now operational
        //
        MP_CLEAR_STATUS_FLAG(pAdapter, MP_ADAPTER_NDIS_PAUSE_IN_PROGRESS);
        MP_SET_NDIS_PNP_STATE(pAdapter, MINIPORT_RUNNING);
    
        MP_RELEASE_SEND_LOCK(pAdapter, FALSE);
    }while(FALSE);
    
    MP_RELEASE_RESET_PNP_LOCK(pAdapter);
    
    MpExit;
    
    return ndisStatus;
}


NDIS_STATUS 
MPPause(
    IN  NDIS_HANDLE      MiniportAdapterContext,
    IN  PNDIS_MINIPORT_PAUSE_PARAMETERS     MiniportPauseParameters
    )
{
    PADAPTER        pAdapter = (PADAPTER) MiniportAdapterContext;
    NDIS_STATUS     ndisStatus;
    ULONG           CurrentStatus, uReceiveCount;

    MpEntry;

    MP_VERIFY_PASSIVE_IRQL();
    
    MPASSERT(MP_GET_NDIS_PNP_STATE(pAdapter) == MINIPORT_RUNNING);
    
    MP_ACQUIRE_RESET_PNP_LOCK(pAdapter);
    
    do
    {
        //
        // Pause Step 0 - Set flags
        //
        
        //
        // Acquire the lock and make sure that all sends will fail from this point on
        //
        MP_ACQUIRE_SEND_LOCK(pAdapter, FALSE);

        //
        // Mark adapter as going in pause. The lock helps synchronize with send operations
        //
        MP_SET_NDIS_PNP_STATE(pAdapter, MINIPORT_PAUSING);
        CurrentStatus = MP_SET_STATUS_FLAG(pAdapter, MP_ADAPTER_NDIS_PAUSE_IN_PROGRESS);
        
        MP_RELEASE_SEND_LOCK(pAdapter, FALSE);

        //
        // Pause Step 1 - Wait for stuff to cleanup
        //

        //
        // If a scan operation is in progress, cancel it first! All kinds
        // of sends and receives must cease.
        //
        if (MP_TEST_STATUS_FLAG(pAdapter, MP_ADAPTER_HW_IS_SCANNING))
        {
            Hw11CancelScan(pAdapter->pNic);
        }
        MPVERIFY(!MP_TEST_STATUS_FLAG(pAdapter, MP_ADAPTER_HW_IS_SCANNING));

        //
        // If we are already performing a Reset/Dot11Reset, the active
        // senders, etc is down
        //
        if (MP_INCREMENT_RESET_PAUSE_COUNT(pAdapter) == 1)
        {
            //
            // Remove the Active Sender count we added during MPRestart
            //
            MP_DECREMENT_ACTIVE_SENDERS(pAdapter);
            NdisWaitEvent(&pAdapter->ActiveSendersDoneEvent, MP_NEVER_TIMEOUT);
            
            //
            // Wait for all pending SG operations to complete
            //
            MP_DECREMENT_ADAPTER_PENDING_SG_OP(pAdapter);
            NdisWaitEvent(&pAdapter->SGOperationsDoneEvent, MP_NEVER_TIMEOUT);
            
            //
            // Remove the Active Receivers count added during Restart.
            // We can pause when the count reaches 1 or less.
            //
            MP_DECREMENT_ACTIVE_RECEIVERS(pAdapter);
            while(pAdapter->NumActiveReceivers >= 1)
            {
                NdisMSleep(10 * 1000);  // 10 msec
            }
        }
        
        //
        // Remove the ref we added in MPRestart on receives indicated up to OS
        //
        if ((uReceiveCount = MP_DECREMENT_PENDING_RECEIVES(pAdapter)) == 0)
        {
            NdisSetEvent(&pAdapter->AllReceivesHaveReturnedEvent);
        }
        NdisWaitEvent(&pAdapter->AllReceivesHaveReturnedEvent, MP_NEVER_TIMEOUT);
        
        //
        // Pause the miniport by dropping pending send packets etc.
        //
        MpInternalPause(pAdapter, MiniportPauseParameters);
        
        //
        // Set the miniport state as paused
        // 
        MP_SET_NDIS_PNP_STATE(pAdapter, MINIPORT_PAUSED);
        
        ndisStatus = NDIS_STATUS_SUCCESS;
    } while(FALSE);
    
    MP_RELEASE_RESET_PNP_LOCK(pAdapter);    
    MpExit;
    
    return ndisStatus;
}


/**
 * 
 * 
 * \param 
 * \param 
 * \param 
 * \param 
 * \return 
 * \sa 
 */
NDIS_STATUS
MPRequest(
    IN  NDIS_HANDLE         MiniportAdapterContext,
    IN  PNDIS_OID_REQUEST   NdisRequest
    )
{
    PADAPTER        pAdapter = (PADAPTER)   MiniportAdapterContext;
    NDIS_STATUS     ndisStatus;

    //
    // If the adapter has been surprise removed, fail request
    //
    if (MP_TEST_STATUS_FLAG(pAdapter, MP_ADAPTER_SURPRISE_REMOVED))
    {
        ndisStatus = NDIS_STATUS_FAILURE;
        MpTrace(COMP_OID, DBG_SERIOUS, ("NdisRequest failed as surprise removal is in progress\n"));
        return ndisStatus;
    }

    //
    // Assume by default, the request will pend. Covers the worst case
    //
    pAdapter->PendedRequest = NdisRequest;
    
    switch(NdisRequest->RequestType)
    {
        case NdisRequestQueryInformation:
        case NdisRequestQueryStatistics:
            ndisStatus = MpQueryInformation(
                            pAdapter,
                            NdisRequest->DATA.QUERY_INFORMATION.Oid,
                            NdisRequest->DATA.QUERY_INFORMATION.InformationBuffer,
                            NdisRequest->DATA.QUERY_INFORMATION.InformationBufferLength,
                            (PULONG)&NdisRequest->DATA.QUERY_INFORMATION.BytesWritten,
                            (PULONG)&NdisRequest->DATA.QUERY_INFORMATION.BytesNeeded
                            );
            break;

        case NdisRequestSetInformation:
            ndisStatus = MpSetInformation(
                            pAdapter,
                            NdisRequest->DATA.SET_INFORMATION.Oid,
                            NdisRequest->DATA.SET_INFORMATION.InformationBuffer,
                            NdisRequest->DATA.SET_INFORMATION.InformationBufferLength,
                            (PULONG)&NdisRequest->DATA.SET_INFORMATION.BytesRead,
                            (PULONG)&NdisRequest->DATA.SET_INFORMATION.BytesNeeded
                            );
            break;

        case NdisRequestMethod:
            ndisStatus = MpQuerySetInformation(
                            pAdapter,
                            NdisRequest->DATA.METHOD_INFORMATION.Oid,
                            NdisRequest->DATA.METHOD_INFORMATION.InformationBuffer,
                            NdisRequest->DATA.METHOD_INFORMATION.InputBufferLength,
                            NdisRequest->DATA.METHOD_INFORMATION.OutputBufferLength,
                            NdisRequest->DATA.METHOD_INFORMATION.MethodId,
                            (PULONG)&NdisRequest->DATA.METHOD_INFORMATION.BytesWritten,
                            (PULONG)&NdisRequest->DATA.METHOD_INFORMATION.BytesRead,
                            (PULONG)&NdisRequest->DATA.METHOD_INFORMATION.BytesNeeded
                            );
            break;

        default:
            ndisStatus = NDIS_STATUS_NOT_SUPPORTED;
            break;
    }
    
    if (ndisStatus != NDIS_STATUS_PENDING)
    {
        //
        // Request has completed
        //
        pAdapter->PendedRequest = NULL;
    }
    else
    {
        MpTrace(COMP_OID, DBG_NORMAL, ("Request has been pended. Will complete asynchronously\n"));
    }
    
    return ndisStatus;
}

VOID MPCancelRequest(
    IN NDIS_HANDLE hMiniportAdapterContext,
    IN PVOID       RequestId
)
{
    UNREFERENCED_PARAMETER(hMiniportAdapterContext);
    UNREFERENCED_PARAMETER(RequestId);

}

/**
 * This function is called to register any additional services that this
 * driver can provide. Currently, there are none for the Mp portion. If
 * there are any to be provided, the Hw functions must do it themselves.
 * 
 * \return NDIS_STATUS_SUCCESS on success else appopriate failure
 * \sa Hw11SetOptionalServices, MiniportSetOptions from the DDK
 */
NDIS_STATUS
MPSetOptions(
    IN NDIS_HANDLE  NdisMiniportDriverHandle,
    IN NDIS_HANDLE  MiniportDriverContext
    )
{
    NDIS_STATUS         ndisStatus;
    
    MpEntry;

    ndisStatus = Hw11SetOptionalServices(NdisMiniportDriverHandle, MiniportDriverContext);
    
    MpExit;
    
    return ndisStatus;
}


/**
 * This function is called in by NDIS periodically (as requested) and the NIC
 * can perform some self tests during this function. If the NIC discovers a
 * problem, it can request a Reset from NDIS. If there is an error that occurs
 * in Hw11 that requires a reset, please set MP_ADAPTER_HARDWARE_ERROR bit
 * using MP_SET_STATUS_FLAG and reset will be invoked. 
 * 
 * \param MiniportAdapterContext    The adapter context for this miniport
 * \return TRUE if miniport needs to be reset else FALSE
 * \sa MP_SET_STATUS_FLAG, MpEventCheckForHang
 */
BOOLEAN
MPCheckForHang(
    IN  NDIS_HANDLE     MiniportAdapterContext
    )
{
    PADAPTER        pAdapter = (PADAPTER) MiniportAdapterContext;
    BOOLEAN         bNeedReset = FALSE;
    
    do
    {
        //
        // Invoke MpEventCheckForHang. See if reset is needed.
        //
        if (MpEventCheckForHang(pAdapter))
        {
            MpTrace(COMP_MISC, DBG_SERIOUS, ("MpEventCheckForHang has requested a reset\n"));
            bNeedReset = TRUE;
            break;            
        }

        //
        // If a hardware error has occured, ask NDIS to reset us
        //
        if (MP_TEST_STATUS_FLAG(pAdapter, (MP_ADAPTER_NON_RECOVER_ERROR | MP_ADAPTER_HARDWARE_ERROR)))
        {
            MpTrace(COMP_MISC, DBG_SERIOUS, ("Requesting reset since a hardware error has occured\n"));
            bNeedReset = TRUE;
            break;
        }
        
        //
        // Check to see if packet are not getting sent. Ask for reset if stalled.
        //
        if (pAdapter->PendingSends > 0)
        {
            if (pAdapter->TotalTransmitsSnapShot == 0)
            {
                //
                // Take a snap shot of the total transmits done so far. Sampling begins now
                //
                MpTrace(COMP_MISC, DBG_LOUD, ("Restart monitoring the total transmit count\n"));
                pAdapter->TotalTransmitsSnapShot = pAdapter->TotalTransmits;
            }
            else if (pAdapter->TotalTransmitsSnapShot == pAdapter->TotalTransmits)
            {
                MpTrace(COMP_MISC, DBG_LOUD, ("%d sample periods of total transmits have occured\n", pAdapter->NumStalledSendTicks));
                
                //
                // If the number of sends pended on the Hw11 has not changed we will
                // count a tick interval of stalled send period.
                //
                pAdapter->NumStalledSendTicks++;

                MPASSERTMSG(
                    "If one more CheckForHang detects stalled sends, we will reset! Investigate\n",
                    pAdapter->NumStalledSendTicks != MP_SENDS_HAVE_STALLED_PERIOD - 1
                    );

                if(pAdapter->NumStalledSendTicks >= MP_SENDS_HAVE_STALLED_PERIOD)
                {
                    MpTrace(COMP_MISC, DBG_SERIOUS, ("Send Engine seems to be stalled. Requesting reset\n"));
                    MpTrace(COMP_TESTING, DBG_SERIOUS, ("Requesting reset from NDIS\n"));
                    MPASSERTMSG("Reset should not occur normally! Investigate\n", FALSE);
                    bNeedReset = TRUE;
                    break;
                }
            }
            else
            {
                //
                // Everything is ok. Pended sends have been completing.
                //
                MpTrace(COMP_MISC, DBG_LOUD, ("Transmissions are working properly.\n"));
                MPVERIFY(pAdapter->TotalTransmitsSnapShot < pAdapter->TotalTransmits);
                pAdapter->TotalTransmitsSnapShot = 0;
                pAdapter->NumStalledSendTicks = 0;
            }
        }
            
        //
        // Sample the usage of Rx MSDU list. Will be used during MpReturnPackets to determine
        // if we need to shrink the Rx MSDU list.
        //
        if (pAdapter->RxMSDUListSampleTicks < MP_RX_MSDU_LIST_SAMPLING_PERIOD)
        {
            pAdapter->RxMSDUListSampleTicks++;
            pAdapter->NumRxMSDUNotUtilized += (pAdapter->TotalRxMSDUAllocated - pAdapter->PendingReceives);
        }
        else
        {
            MpTrace(COMP_MISC, DBG_LOUD, ("Percentage of Under Utilization = %d\n", (pAdapter->NumRxMSDUNotUtilized * 100) / (pAdapter->RxMSDUListSampleTicks * pAdapter->TotalRxMSDUAllocated)));
            pAdapter->RxMSDUListSampleTicks = 0;
            pAdapter->NumRxMSDUNotUtilized = 0;
        }
        MpTrace(COMP_MISC, DBG_TRACE, ("%d sample periods of Rx MSDU list have passed\n", pAdapter->RxMSDUListSampleTicks));
    } while(FALSE);
    
    return bNeedReset;
}


/**
 * This routine is called by NDIS when miniport is to be reset. If the miniport is
 * already in reset, we will return NDIS_STATUS_RESET_IN_PROGRESS. If the miniport
 * has a unrecoverable hardware error, we will request a miniport removal and abandon
 * a reset attempt. MpResetInternalRoutine is then invoked which executes the actual 
 * reset opertaion.
 * 
 * \param AddressingReset   We will set it to true so NDIS will set multicast address for us
 * \param MiniportAdapterContext The context for this miniport.
 * \sa See MiniportReset in DDK for full details, MpResetInternalRoutine, MpResetWorkItem
 */
NDIS_STATUS
MPReset(
    IN  NDIS_HANDLE     MiniportAdapterContext,
    OUT PBOOLEAN        AddressingReset
    )
{
    NDIS_STATUS     ndisStatus = NDIS_STATUS_PENDING;
    PADAPTER        pAdapter = (PADAPTER) MiniportAdapterContext;
    ULONG           CurrentStatus;
    
    MpTrace(COMP_MISC, DBG_SERIOUS, ("The miniport driver has been reset\n"));
    
    //
    // Request NDIS to add the addresses on the miniport through OIDs
    // once the reset is complete.
    //
    *AddressingReset = HW11_REQUIRES_ADDRESS_RESET;
    
    MP_ACQUIRE_SEND_LOCK(pAdapter, FALSE);
    
    do
    {
        //
        // Reset Step 0 - We set flags so that the other routines 
        // stop proceeding forward
        //
        
        CurrentStatus = MP_SET_STATUS_FLAG(pAdapter, MP_ADAPTER_RESET_IN_PROGRESS);
                
        if (CurrentStatus & MP_ADAPTER_RESET_IN_PROGRESS)
        {
            //
            // The "in reset" bit is already set. Tell NDIS we are already in reset and
            // return immediately.
            //
            ndisStatus = NDIS_STATUS_RESET_IN_PROGRESS;
            break;
        }
        
        //
        // If our halt handler has been called, we should not reset
        //
        if (CurrentStatus & MP_ADAPTER_HALT_IN_PROGRESS)
        {
            MPASSERT(FALSE);    // Would be an interesting scenario to investigate
            MP_CLEAR_STATUS_FLAG(pAdapter, MP_ADAPTER_RESET_IN_PROGRESS);
            ndisStatus = NDIS_STATUS_SUCCESS;
            break;
        }
        
        //
        // If the adapter has Non-Recoverable hardware errors, request removal
        //
        if (CurrentStatus & MP_ADAPTER_NON_RECOVER_ERROR)
        {
            MP_CLEAR_STATUS_FLAG(pAdapter, MP_ADAPTER_RESET_IN_PROGRESS);
            ndisStatus = NDIS_STATUS_HARD_ERRORS;
            MpRemoveAdapter(pAdapter);
            break;
        }
    } while(FALSE);
    
    MP_RELEASE_SEND_LOCK(pAdapter, FALSE);
    
    if (ndisStatus == NDIS_STATUS_PENDING)
    {
        MpTrace(COMP_MISC, DBG_NORMAL, ("Scheduling a work item to complete the reset\n"));

        NdisQueueIoWorkItem(
            pAdapter->NdisResetWorkItem,
            MpResetWorkItem,
            pAdapter        
            );
    }
    
    return ndisStatus;
}


VOID MPAllocateComplete(
    IN  NDIS_HANDLE             MiniportAdapterContext,
    IN  PVOID                   VirtualAddress,
    IN  PNDIS_PHYSICAL_ADDRESS  PhysicalAddress,
    IN  ULONG                   Length,
    IN  PVOID                   Context
    )
{
    PADAPTER        pAdapter = (PADAPTER) MiniportAdapterContext;

    MpTrace(COMP_RECV, DBG_NORMAL, ("Asynchronous shared memory allocation completed\n"));
    
    //
    // Notify Hw11 about completion of allocation call
    //
    Hw11SharedMemoryAllocateComplete(
        pAdapter->pNic,
        VirtualAddress,
        PhysicalAddress,
        Length,
        Context
        );

    //
    // Decrement the ref count incremented at allocate time.
    //
    MP_DECREMENT_REF(pAdapter);
}


VOID
MPDevicePnPEvent(
    IN NDIS_HANDLE                  MiniportAdapterContext,
    IN PNET_DEVICE_PNP_EVENT        NetDevicePnPEvent
    )
{
    PADAPTER            pAdapter = (PADAPTER) MiniportAdapterContext;
    NDIS_DEVICE_PNP_EVENT        DevicePnPEvent = NetDevicePnPEvent->DevicePnPEvent;
    PVOID                        InformationBuffer = NetDevicePnPEvent->InformationBuffer;
    ULONG                        InformationBufferLength = NetDevicePnPEvent->InformationBufferLength;

    MpEntry;

    switch (DevicePnPEvent)
    {
        case NdisDevicePnPEventQueryRemoved:
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("MPDevicePnPEventNotify: NdisDevicePnPEventQueryRemoved\n"));
            break;

        case NdisDevicePnPEventRemoved:
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("MPDevicePnPEventNotify: NdisDevicePnPEventRemoved\n"));
            break;       

        case NdisDevicePnPEventSurpriseRemoved:
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("MPDevicePnPEventNotify: NdisDevicePnPEventSurpriseRemoved\n"));
            MpOnSurpriseRemoval(pAdapter);
            break;

        case NdisDevicePnPEventQueryStopped:
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("MPDevicePnPEventNotify: NdisDevicePnPEventQueryStopped\n"));
            break;

        case NdisDevicePnPEventStopped:
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("MPDevicePnPEventNotify: NdisDevicePnPEventStopped\n"));
            break;      
            
        case NdisDevicePnPEventPowerProfileChanged:
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("MPDevicePnPEventNotify: NdisDevicePnPEventPowerProfileChanged\n"));
            break;      
            
        default:
            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("MPDevicePnPEventNotify: unknown PnP event %x \n", DevicePnPEvent));
            MpExit;
            return;
    }

    //
    // This is a valid PnPEvent. Notify Hw11 about it.
    //
    Hw11DevicePnPEvent(
        pAdapter->pNic,
        DevicePnPEvent,
        InformationBuffer,
        InformationBufferLength
        );

    MpExit;
}


VOID MPAdapterShutdown(
    IN  NDIS_HANDLE             MiniportAdapterContext,
    IN  NDIS_SHUTDOWN_ACTION    ShutdownAction
    )
{
    PADAPTER pAdapter = (PADAPTER) MiniportAdapterContext;

    UNREFERENCED_PARAMETER(ShutdownAction);

    //
    // Any place where we are reading registers and making major
    // decisions we should consider protecting against FFFF for surprise 
    // removal case
    //

    MpEntry;

    if (MP_TEST_STATUS_FLAG(pAdapter, MP_ADAPTER_SURPRISE_REMOVED) == FALSE)
    {
        //
        // Disable Interrupts only if adapter has not been removed
        //
        Hw11DisableInterrupt(pAdapter->pNic);

        //
        // Issue a shutdown to the NIC. NIC should go into a known state
        // and shut off power to the antenna. If surprise removal has
        // occurred, we will not do this.
        //
        Hw11Shutdown(pAdapter->pNic);
    }       

    MpExit;
}


VOID MPHalt(
    IN  NDIS_HANDLE             MiniportAdapterContext,
    IN  NDIS_HALT_ACTION        HaltAction
    )
{
    PADAPTER    pAdapter = (PADAPTER) MiniportAdapterContext;
    ULONG       CurrentStatus;
    
    MpEntry;
    
    //
    // Mark the miniport as going in halt
    //
    CurrentStatus = MP_SET_STATUS_FLAG(pAdapter, MP_ADAPTER_HALT_IN_PROGRESS);
    if (CurrentStatus & MP_ADAPTER_RESET_IN_PROGRESS)
    {
        //
        // A reset operation is currently occuring. We cannot halt till it completes
        //
        while (MP_TEST_STATUS_FLAG(pAdapter, MP_ADAPTER_RESET_IN_PROGRESS) == TRUE)
        {
            NdisMSleep(20 * 1000);      // 20 milliseconds
        }
    }
    
    MPASSERTMSG("No sends should have been pended on the miniport when halt is called\n",
                  (pAdapter->PendingSends == 0));
    
    //
    // Scan should not be in progress during halt
    //
    MPASSERT(MP_DOT11_SCAN_IN_PROGRESS(pAdapter) == FALSE);

    //
    // First issue a shutdown to stop interrupts and turn off hardware
    //
    MPAdapterShutdown(MiniportAdapterContext, NdisShutdownPowerOff);
    
    //
    // Deregister interrupts as soon as possible
    //
    NdisMDeregisterInterruptEx(pAdapter->InterruptHandle);
    
    if (MP_TEST_STATUS_FLAG(pAdapter, MP_ADAPTER_SURPRISE_REMOVED) == FALSE)
    {
        //
        // Pause the beaconing
        //
        Hw11StopAdHoc(pAdapter->pNic);
    }
    
    //
    // Drop any Rx MSDUs that have exceeded RxLifeTime value. We cannot
    // free all receive resources without this.
    //
    MpExpireReassemblingPackets(pAdapter, FALSE);
    
    //
    // Invoke the terminate event
    //
    MpEventTerminate(pAdapter);

    //
    // Stop the station
    //
    Sta11StopStation(pAdapter->pStation, HaltAction);
    
    //
    // If ref count is not zero yet that implies:
    // 1. A pending Async Shared memory allocation
    // 2. We are in the middle of a scan
    //
    MP_DECREMENT_REF(pAdapter);
    if (pAdapter->RefCount > 0)
    {
        do
        {
            if(NdisWaitEvent(&pAdapter->HaltWaitEvent, 2000))
            {
                break;
            }

            MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Waiting 2 more seconds for all Miniport Ref Count to go to zero\n"));
        } while(TRUE);
    }
    
    MPVERIFY(pAdapter->NumActiveReceivers == 0);
    
    //
    // By the time Halt is called as indicated received should have been returned
    //
    MPASSERT(pAdapter->PendingReceives == 0);
    
    if (MP_TEST_STATUS_FLAG(pAdapter, MP_ADAPTER_SURPRISE_REMOVED) == FALSE)
    {
        //
        // Inform the hardware that it is being halted.
        //
        Hw11HaltNic(pAdapter->pNic);
    }
    
    //
    // Release all resources kept for send and receive
    //
    Hw11TerminateReceive(pAdapter->pNic);
    MpTerminateSendEngine(pAdapter);
    
    //
    // Uninitialize the NIC
    //
    Hw11TerminateNic(pAdapter->pNic);
    
    //
    // Free adapter resources. Also frees up NIC resources.
    //
    MpFreeAdapter(pAdapter);
    
    MpExit;
}



//
// Some Mp11 handlers
//


NDIS_STATUS
Mp11AllocateSharedMemoryAsync(
    IN PADAPTER         pAdapter,
    IN ULONG            Length,
    IN BOOLEAN          Cached,
    IN PVOID            Context
    )
{
    NDIS_STATUS ndisStatus;

    //
    // Increment ref count on the adapter.
    // Adapter cannot halt (go away) till this call completes
    //
    MP_INCREMENT_REF(pAdapter);
    
    if ((ndisStatus = NdisMAllocateSharedMemoryAsync(
            pAdapter->MiniportAdapterHandle,
            Length,
            Cached,
            Context
            )) == NDIS_STATUS_FAILURE)
    {
        //
        // Allocate failed. Remove the Ref
        //
        MP_DECREMENT_REF(pAdapter);
    }

    return ndisStatus;
}

VOID
Mp11InternalReset(
    IN  PADAPTER        pAdapter,
	IN  MP_RESET_TYPE   ResetType
    )
{
    MP_ACQUIRE_SEND_LOCK(pAdapter, FALSE);    
	MpResetInternalRoutine(pAdapter, ResetType);
    MP_RELEASE_SEND_LOCK(pAdapter, FALSE);
}


VOID
Mp11IndicateStatusIndication(
    IN  PADAPTER        pAdapter,
    IN  PNDIS_STATUS_INDICATION pStatusIndication
    )
{
    NdisMIndicateStatusEx(
        pAdapter->MiniportAdapterHandle,
        pStatusIndication
        );
}


/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    Hw_Send.c

Abstract:
    Hw layer send processing functions
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created

Notes:

--*/
#include "hw_pcomp.h"

#include "Hw_main.h"
#include "Hw_Nic.h"
#include "Hw_ccmp.h"
#include "Hw_Func.h"
#include "Mp_util.h"

#include "Mp_Send.h"
#if DOT11_TRACE_ENABLED
#include "Hw_Send.tmh"
#endif

NDIS_STATUS
Hw11InitializeSend(
    IN  PNIC pNic,
    IN  ULONG NumTxd
    )
{
    int         i, QueueIndex;
    NDIS_STATUS Status=NDIS_STATUS_SUCCESS;

    UNREFERENCED_PARAMETER(NumTxd);

    __try 
    {
        InitializeListHead(&pNic->TxInfo.PostSGMSDUList);

        //
        // Alloc Tx Desc(256 byte alignment)
        //
        for (i = 0; i < TX_QUEUE_NUM; i++) 
        {
            Status = HwAllocateAlignPhyMemory(pNic,
                                              TX_DESC_SIZE * pNic->TxInfo.TxTotalDescNum[i],
                                              &pNic->TxInfo.TxDescVa[i],
                                              &pNic->TxInfo.TxDescPa[i],
                                              (UCHAR **)&pNic->TxInfo.TxDesc[i],
                                              &pNic->TxInfo.TxDescPhy[i]);
            if (Status != NDIS_STATUS_SUCCESS) 
            {
                MpTrace(COMP_SEND, DBG_SERIOUS, ("HwAllocateAlignPhyMemory fail!\n"));
                __leave;
            }
                
            HwLinkTxDesc((UCHAR *)pNic->TxInfo.TxDesc[i],
                         pNic->TxInfo.TxDescPhy[i],
                         TX_DESC_SIZE,
                         pNic->TxInfo.TxTotalDescNum[i]);
        }

        //
        // Allocate Beacon Buffer
        //
        for (i = 0; i < 2; i++)
        {
            NdisMAllocateSharedMemory(pNic->MiniportAdapterHandle,
                                      MAX_TX_RX_PACKET_SIZE,
                                      FALSE,
                                      (void **)&pNic->TxInfo.TxBeaconBufVa[i],
                                      &pNic->TxInfo.TxBeaconBufPa[i]);

            if (pNic->TxInfo.TxBeaconBufVa[i] == NULL)
            {
                Status=NDIS_STATUS_RESOURCES;
                MpTrace(COMP_SEND, DBG_SERIOUS, ("Allocate Beacon Buffer failed!\n"));
                __leave;    // Note: try/leave is used for ease of breaking out and not for exception handling
            }
        }

        //
        // Allocate Normal/High Queue local Buffer for Transmitting Management/ATIM Packet
        //
        for (QueueIndex=NORMAL_QUEUE; QueueIndex <= HIGH_QUEUE; QueueIndex++) 
        {
            PUCHAR    **va;
            PNDIS_PHYSICAL_ADDRESS *pa;
            
            if (QueueIndex == NORMAL_QUEUE) 
            {
                va = &pNic->TxInfo.pTxNormalQBufVa;
                pa = &pNic->TxInfo.pTxNormalQBufPa;
            }
            else 
            {
                va = &pNic->TxInfo.pTxHighQBufVa;
                pa = &pNic->TxInfo.pTxHighQBufPa;
            }

            MP_ALLOCATE_MEMORY(pNic->MiniportAdapterHandle,
                               (PVOID *)va, 
                               sizeof(PUCHAR) * pNic->TxInfo.TxTotalDescNum[QueueIndex],
                               HW11_MEMORY_TAG);

            if (*va == NULL) 
            {
                Status = NDIS_STATUS_RESOURCES;
                __leave;
            }
            NdisZeroMemory(*va, sizeof(PUCHAR) * pNic->TxInfo.TxTotalDescNum[QueueIndex]);

            MP_ALLOCATE_MEMORY(pNic->MiniportAdapterHandle,
                               (PVOID *)pa, 
                               sizeof(NDIS_PHYSICAL_ADDRESS) * pNic->TxInfo.TxTotalDescNum[QueueIndex],
                               HW11_MEMORY_TAG);

            if (*pa == NULL) 
            {
                Status = NDIS_STATUS_RESOURCES;
                MP_FREE_MEMORY((PVOID)(*va));
                *va = NULL;
                __leave;
            }
            
            for (i = 0; i < pNic->TxInfo.TxTotalDescNum[QueueIndex]; i++)
            {
                NdisMAllocateSharedMemory(pNic->MiniportAdapterHandle,
                                          MAX_TX_RX_PACKET_SIZE,
                                          FALSE,
                                          (void **) &((*va)[i]),
                                          &((*pa)[i]));

                if ((*va)[i] == NULL)
                {
                    Status=NDIS_STATUS_RESOURCES;
                    __leave;
                }
            }
        }
    }
    __finally 
    {
        if (Status != NDIS_STATUS_SUCCESS)
        {
            //
            // Cleanup
            //
            Hw11TerminateSend(pNic);
        }
    }

    return Status;
}


VOID
Hw11TerminateSend(
    IN  PNIC pNic
    )
{
    int i, QueueIndex;
    PUCHAR    **va;
    PNDIS_PHYSICAL_ADDRESS *pa;

    //
    // Free Normal/High queue allocated buffers
    //
    for(QueueIndex = NORMAL_QUEUE; QueueIndex <= HIGH_QUEUE; QueueIndex++) 
    {
        if (QueueIndex == NORMAL_QUEUE) 
        {
            va = &pNic->TxInfo.pTxNormalQBufVa;
            pa = &pNic->TxInfo.pTxNormalQBufPa;
        }
        else 
        {
            va = &pNic->TxInfo.pTxHighQBufVa;
            pa = &pNic->TxInfo.pTxHighQBufPa;
        }

        if (*va != NULL)
        {
            //
            // Free Normal/High Queue Buffer
            //
            for (i = 0; i < pNic->TxInfo.TxTotalDescNum[QueueIndex]; i++)
            {
                if ((*va)[i] != NULL)
                {
                    NdisMFreeSharedMemory(pNic->MiniportAdapterHandle,
                                          MAX_TX_RX_PACKET_SIZE,
                                          FALSE,
                                          (void *)((*va)[i]),
                                          (*pa)[i]);
                }
            }

            MP_FREE_MEMORY((PVOID)(*va));
            MP_FREE_MEMORY((PVOID)(*pa));
        }
    }

    //
    // Free Beacon Buffer
    //
    for (i = 0; i < 2; i++) 
    {
        if (pNic->TxInfo.TxBeaconBufVa[i] != NULL)
        {
            NdisMFreeSharedMemory(pNic->MiniportAdapterHandle,
                                  MAX_TX_RX_PACKET_SIZE,
                                  FALSE,
                                  (void *)pNic->TxInfo.TxBeaconBufVa[i],
                                  pNic->TxInfo.TxBeaconBufPa[i]);
        }
    }

    //
    // Free Tx Desc
    //
    for (i = 0; i < TX_QUEUE_NUM; i++) 
    {
        if (pNic->TxInfo.TxDescVa[i] != NULL)
        {
            NdisMFreeSharedMemory(pNic->MiniportAdapterHandle,
                                  TX_DESC_SIZE*pNic->TxInfo.TxTotalDescNum[i] + 0xff,
                                  FALSE,
                                  pNic->TxInfo.TxDescVa[i],
                                  pNic->TxInfo.TxDescPa[i]);
        }
    }
}

VOID
Hw11CheckForSends(
    IN  PNIC pNic
    )
{
    // Ask the hardware to check the send queues
    HwTxPolling(pNic, LOW_QUEUE);
}

NDIS_STATUS
Hw11AssociateTxMSDU(
    IN  PNIC            pNic,
    IN  PMP_TX_MSDU     pMpTxd,
    OUT PNIC_TX_MSDU*   ppNicTxd
    )
{
    NDIS_PHYSICAL_ADDRESS   NicTxdPhysicalAddress;

    UNREFERENCED_PARAMETER(pMpTxd);

    //
    // Allocate NIC_TX_MSDU and initialize it
    //
    NdisMAllocateSharedMemory(pNic->MiniportAdapterHandle,
                              sizeof(NIC_TX_MSDU),
                              FALSE,
                              ppNicTxd,
                              &NicTxdPhysicalAddress);
    if (*ppNicTxd == NULL) 
    {
        return NDIS_STATUS_RESOURCES;
    }

    NdisZeroMemory(*ppNicTxd, sizeof(NIC_TX_MSDU));
    (*ppNicTxd)->pMpTxd = pMpTxd;
    (*ppNicTxd)->NicTxdPhysicalAddress = NicTxdPhysicalAddress;

    //
    // Allocate Coalesce buffer
    //
    NdisMAllocateSharedMemory(pNic->MiniportAdapterHandle,
                              MAX_TX_RX_PACKET_SIZE,
                              FALSE,
                              &((*ppNicTxd)->CoalesceBuf),
                              &((*ppNicTxd)->CoalesceBufPa));
    if ((*ppNicTxd)->CoalesceBuf == NULL)
    {
        NdisMFreeSharedMemory(pNic->MiniportAdapterHandle, 
            sizeof(NIC_TX_MSDU), 
            FALSE, 
            *ppNicTxd, 
            NicTxdPhysicalAddress
            );

        return NDIS_STATUS_RESOURCES;        
    }

    return NDIS_STATUS_SUCCESS;
}


VOID
Hw11DisassociateTxMSDU(
    IN  PNIC         pNic,
    IN  PNIC_TX_MSDU pNicTxd
    )
{
    //
    // Free Coalesce buffer
    //
    NdisMFreeSharedMemory(pNic->MiniportAdapterHandle,
                          MAX_TX_RX_PACKET_SIZE,
                          FALSE,
                          (pNicTxd)->CoalesceBuf,
                          (pNicTxd)->CoalesceBufPa);

    //
    // Free NIC_TX_MSDU
    //
    NdisMFreeSharedMemory(pNic->MiniportAdapterHandle,
                          sizeof(NIC_TX_MSDU),
                          FALSE,
                          pNicTxd,
                          pNicTxd->NicTxdPhysicalAddress);
}


NDIS_STATUS
HwCopyNBLToBuffer(
    IN  PNET_BUFFER_LIST    NetBufferList,
    OUT PUCHAR              pDest,
    OUT PULONG              BytesCopied
    ) 
{
    NDIS_STATUS     ndisStatus = NDIS_STATUS_SUCCESS;
    PNET_BUFFER     CurrentNetBuffer;
    PMDL            CurrentMdl;
    LONG            CurrLength;
    PUCHAR          pSrc;
    
    __try
    {
        *BytesCopied = 0;
        for (CurrentNetBuffer = NET_BUFFER_LIST_FIRST_NB(NetBufferList);
             CurrentNetBuffer != NULL;
             CurrentNetBuffer = NET_BUFFER_NEXT_NB(CurrentNetBuffer))
        {
            CurrentMdl = NET_BUFFER_CURRENT_MDL(CurrentNetBuffer);

            pSrc = MmGetSystemAddressForMdlSafe(CurrentMdl, NormalPagePriority);
            if (!pSrc)
            {
                ndisStatus = NDIS_STATUS_RESOURCES;
                __leave;
            }
            
            //
            // For the first MDL with data, we need to skip the free space
            //
            pSrc += NET_BUFFER_CURRENT_MDL_OFFSET(CurrentNetBuffer);
            CurrLength = MmGetMdlByteCount(CurrentMdl) - NET_BUFFER_CURRENT_MDL_OFFSET(CurrentNetBuffer);

            if (CurrLength > 0)
            {
                if (CurrLength + *BytesCopied > MP_802_11_MAX_FRAME_SIZE)
                {
                    MpTrace(COMP_SEND, DBG_SERIOUS, ("%s: The total MSDU size (%d) is greater than max "
                        "allowed (%d)\n", __FUNCTION__, CurrLength + *BytesCopied, MP_802_11_MAX_FRAME_SIZE));
                    
                    ndisStatus = NDIS_STATUS_INVALID_LENGTH;
                    break;  /* break out for loop */
                }
                
                //
                // Copy the data.
                // 
                NdisMoveMemory(pDest, pSrc, CurrLength);
                *BytesCopied += CurrLength;
                pDest += CurrLength;
                
//                MPASSERTMSG("The total MSDU size is greater than max allowed\n",
//                            *BytesCopied <= MP_802_11_MAX_FRAME_SIZE);
            }

            CurrentMdl = NDIS_MDL_LINKAGE(CurrentMdl);
            while (CurrentMdl)
            {
                pSrc = MmGetSystemAddressForMdlSafe(CurrentMdl, NormalPagePriority);
                if (!pSrc)
                {
                    ndisStatus = NDIS_STATUS_RESOURCES;
                    __leave;
                }

                CurrLength = MmGetMdlByteCount(CurrentMdl);

                if (CurrLength > 0)
                {
                    if (CurrLength + *BytesCopied > MP_802_11_MAX_FRAME_SIZE)
                    {
                        MpTrace(COMP_SEND, DBG_SERIOUS, ("%s: The total MSDU size (%d) is greater than max "
                            "allowed (%d)\n", __FUNCTION__, CurrLength + *BytesCopied, MP_802_11_MAX_FRAME_SIZE));
                        
                        ndisStatus = NDIS_STATUS_INVALID_LENGTH;
                        break;  /* break out while and for loop */
                    }

                    //
                    // Copy the data.
                    //
                    NdisMoveMemory(pDest, pSrc, CurrLength);
                    *BytesCopied += CurrLength;
                    pDest += CurrLength;
                    
//                    MPASSERTMSG("The total MSDU size is greater than max allowed\n",
//                                *BytesCopied <= MP_802_11_MAX_FRAME_SIZE);
                }

                CurrentMdl = NDIS_MDL_LINKAGE(CurrentMdl);
            }
        }
    }
    __finally 
    {
    }

    return ndisStatus;
}

/*
    if UseProtection bit is set in beacon, send out a CTS to self  
    at 11mbps because other NonERP-STA cannot see the packets sent
    at high data rate.
*/
BOOLEAN
HwEnableSendCTSToSelf(
    IN  PNIC                    pNic,
    IN  USHORT                  currentDataRate,
    OUT PUSHORT                 pRTSCTSRate
    )
{
    BOOLEAN     bCTSToSelf = FALSE;

    ASSERT (pRTSCTSRate != NULL);
    
    if (pNic->ManagementInfo.bEnableSendCTSToSelf == TRUE &&
        pNic->ManagementInfo.OperatingPhyMIB->PhyType == dot11_phy_type_erp &&
        currentDataRate > 22)       // if the data rate is at 11mbps or less, there is no need to send CTS to self
    {
        bCTSToSelf = TRUE;
        *pRTSCTSRate = 22;      // 11mbps
    }
    else
    {
        *pRTSCTSRate = currentDataRate;
    }

    return bCTSToSelf;
}

NDIS_STATUS
HwTransmitPacketCoalesce(
    IN PNIC         pNic,
    IN PMP_TX_MSDU  pMpTxd,
    IN ULONG        QueueID,
    IN USHORT       NumTxDescNeeded
    )
{
    BOOLEAN                 bShortPreamble;
    USHORT                  i, Rate;
    ULONG                   uBytesCopied = 0, DataOffset = 0;
    PNIC_TX_MSDU            NicTxd;
    PTX_DESC                Desc;
    PNET_BUFFER             CurrentNetBuffer;
    NDIS_STATUS             ndisStatus;
    BOOLEAN                 bCTSToSelf = FALSE;
    USHORT                  RTSCTSRate = 0;

    MPVERIFY(NumTxDescNeeded == pMpTxd->SGElementListCount);

    NicTxd = pMpTxd->NicTxd;

    bShortPreamble = (BOOLEAN)((pNic->ManagementInfo.CapInfo & DOT11_CAPABILITY_SHORT_PREAMBLE) && 
                               (pNic->ManagementInfo.OperatingPhyMIB->PhyType == dot11_phy_type_erp));
    Rate = NicTxd->TxRate;

    bCTSToSelf = HwEnableSendCTSToSelf (pNic, Rate, &RTSCTSRate);

    //
    // Coalesce all the data in the coalesce buffer
    //
    ndisStatus = HwCopyNBLToBuffer(pMpTxd->NetBufferList,
                                   NicTxd->CoalesceBuf,
                                   &uBytesCopied);
    if (ndisStatus != NDIS_STATUS_SUCCESS)
    {
        //
        // Failed to coalesce this packet. We will fail the Tx MSDU
        //
        return ndisStatus;
    }

    NicTxd->QueueIDUsed = (USHORT)QueueID;
    NicTxd->FirstDescUsed = pNic->TxInfo.TxNextDescToSend[QueueID];
    NicTxd->TotalDescUsed = NumTxDescNeeded;
    MpTrace(COMP_TESTING, DBG_LOUD, ("First Desc: %d\n", pNic->TxInfo.TxNextDescToSend[QueueID]));
    
    //
    // Fill a TX_DESC for each scatter gather element for each MPDU
    //
    CurrentNetBuffer = NET_BUFFER_LIST_FIRST_NB(pMpTxd->NetBufferList);

    if (NumTxDescNeeded > 1)
    {
        //
        // We will start from the 2nd MPDU (if present) and will fill in the
        // first one when we are done with all the others. 2nd MPDU means 2nd NB
        // We will also need to skip the data offset (free space) and data length
        // of the first NetBuffer as well.
        //
        DataOffset = NET_BUFFER_DATA_LENGTH(CurrentNetBuffer);
        CurrentNetBuffer = NET_BUFFER_NEXT_NB(CurrentNetBuffer);
        MPVERIFY(CurrentNetBuffer);
    }
    else
    {
        //
        // There is only on MPDU so only one TX_DESC needed
        // We will not enter the loop and directly fill the
        // TX_DESC for the first NetBuffer
        //
        MPVERIFY(NumTxDescNeeded == 1);
    }
    
    for (i = 1; i < NumTxDescNeeded; i++)
    {

        //
        // Get the next descriptor we will be filling
        //
        Desc = HwGetNextDescToSend(pNic, QueueID, i, FALSE);
        HwTxFillDescriptor(pNic,
                           Desc,
                           NicTxd->CoalesceBuf + DataOffset,
                           TRUE,               // Start Of MPDU
                           TRUE,               // End of MPDU
                           NicTxd->CoalesceBufPa.LowPart + DataOffset,
                           NET_BUFFER_DATA_LENGTH(CurrentNetBuffer),
                           NET_BUFFER_DATA_LENGTH(CurrentNetBuffer),
                           Rate,
                           HwIsMulticast(NicTxd->CoalesceBuf + DataOffset),
                           bShortPreamble,
                           (BOOLEAN)(i != NumTxDescNeeded - 1),
                           NicTxd->RTSEnabled,
                           bCTSToSelf,
                           RTSCTSRate,
                           TRUE,
                           FALSE,
                           QueueID);

        //
        // One more TX_DESC used up.
        // Move to the next MPDU
        //
        DataOffset += NET_BUFFER_DATA_LENGTH(CurrentNetBuffer);
        CurrentNetBuffer = NET_BUFFER_NEXT_NB(CurrentNetBuffer);
    }

    //
    // Now fill out TX_DESC for the first MPDU
    //
    CurrentNetBuffer = NET_BUFFER_LIST_FIRST_NB(pMpTxd->NetBufferList);
    Desc = HwGetNextDescToSend(pNic, QueueID, 0, FALSE);

    HwTxFillDescriptor(pNic,
                       Desc,
                       NicTxd->CoalesceBuf,
                       TRUE,               // Start Of MPDU
                       TRUE,               // End of MPDU
                       NicTxd->CoalesceBufPa.LowPart,
                       NET_BUFFER_DATA_LENGTH(CurrentNetBuffer),
                       NET_BUFFER_DATA_LENGTH(CurrentNetBuffer),
                       Rate,
                       HwIsMulticast(NicTxd->CoalesceBuf),
                       bShortPreamble,
                       (BOOLEAN)(NumTxDescNeeded > 1),
                       NicTxd->RTSEnabled,
                       bCTSToSelf,
                       RTSCTSRate,
                       TRUE,
                       FALSE,
                       QueueID);

    // Mark this Tx MSDU as waiting for send completion
    NicTxd->WaitSendToComplete = TRUE;
    
    // Poll the Hw to send
    HwTxPolling(pNic, (UCHAR)QueueID);
    
    // We have used up these many descriptors
    HwIncrementNextDescToSend(pNic, QueueID, NumTxDescNeeded, FALSE);

    return NDIS_STATUS_SUCCESS;
}


ULONG
HwCountTxResourceNeeded(
    IN  PMP_TX_MSDU         pMpTxd,
    OUT BOOLEAN             *UseCoalesce
    )
{
    ULONG                   i, TotalDescNeeded = 0;
    USHORT                  usNumberOfMPDU = 0;
    SCATTER_GATHER_LIST    *pFragList;
    PNET_BUFFER             CurrentNetBuffer;
    PNET_BUFFER_LIST        pNetBufferList = pMpTxd->NetBufferList;
    
    //
    // Initially assume that we do not need coalescing.
    //
    *UseCoalesce = FALSE;
    
    //
    // Each NB in the NBL could be a MPDU. However the OS 
    // only gives us a single NET_BUFFER in the NET_BUFFER_LIST.
    //
    CurrentNetBuffer = NET_BUFFER_LIST_FIRST_NB(pNetBufferList);
    while (CurrentNetBuffer != NULL)
    {
        pFragList = (PSCATTER_GATHER_LIST) pMpTxd->SGElementList[usNumberOfMPDU];
        
        if (pFragList->NumberOfElements >= DoCoalesceThreshold)
        {
            // It is better to coalesce this MSDU
            if (UseCoalesce != NULL)
                *UseCoalesce = TRUE;

            TotalDescNeeded = pMpTxd->SGElementListCount;
            goto done;
        }
        else
        {
            TotalDescNeeded += pFragList->NumberOfElements;
        }
        
        for (i = 0; i < pFragList->NumberOfElements; i++)
        {
            // This is the hardware limitation
            if (pFragList->Elements[i].Length <= 4)
            {
                if (UseCoalesce != NULL)
                    *UseCoalesce = TRUE;

                TotalDescNeeded = pMpTxd->SGElementListCount;
                goto done;
            }
        }
        
        usNumberOfMPDU++;
        CurrentNetBuffer = NET_BUFFER_NEXT_NB(CurrentNetBuffer);
    }

done:
    return TotalDescNeeded;
}


VOID
HwTransmitPacket(
    IN  PNIC   pNic,
    IN  PMP_TX_MSDU pMpTxd,
    IN  ULONG  QueueID,
    IN  USHORT NumTxDescNeeded
    )
{
    BOOLEAN                 bShortPreamble, bFirstSeg;
    USHORT                  i, j, Rate, NumTxDescUsed = 0;
    ULONG                   MdlDataOffset;
    PNIC_TX_MSDU            NicTxd;
    PTX_DESC                Desc, FirstDesc;
    PNET_BUFFER             CurrentNetBuffer;
    PSCATTER_GATHER_LIST    SGList;
    PSCATTER_GATHER_ELEMENT SGElement;
    PUCHAR                  header = NULL;
    ULONG                   length;
    USHORT                  RTSCTSRate = 0;
    BOOLEAN                 bCTSToSelf = FALSE;

    UNREFERENCED_PARAMETER(NumTxDescNeeded);

    MPVERIFY(QueueID == LOW_QUEUE);
    
    NicTxd = pMpTxd->NicTxd;
    
    //
    // Information that applies to all fragments in the NBL
    //
    NicTxd->QueueIDUsed = (USHORT)QueueID;
    
    bShortPreamble = (BOOLEAN)((pNic->ManagementInfo.CapInfo & DOT11_CAPABILITY_SHORT_PREAMBLE) && 
                               (pNic->ManagementInfo.OperatingPhyMIB->PhyType == dot11_phy_type_erp));
    Rate = NicTxd->TxRate;


    bCTSToSelf = HwEnableSendCTSToSelf (pNic, Rate, &RTSCTSRate);

    NicTxd->FirstDescUsed = pNic->TxInfo.TxNextDescToSend[QueueID];
    FirstDesc = HwGetNextDescToSend(pNic, QueueID, 0, FALSE);
    MpTrace(COMP_TESTING, DBG_LOUD, ("First Desc: %d\n", pNic->TxInfo.TxNextDescToSend[QueueID]));

    //
    // Fill a TX_DESC for each scatter gather element for each MPDU
    //
    CurrentNetBuffer = NET_BUFFER_LIST_FIRST_NB(pMpTxd->NetBufferList);
    for (i = 0; i < pMpTxd->SGElementListCount; i++)
    {
        SGList = (PSCATTER_GATHER_LIST) pMpTxd->SGElementList[i];
        MdlDataOffset = NET_BUFFER_CURRENT_MDL_OFFSET(CurrentNetBuffer);
        bFirstSeg = TRUE;
        
        NdisQueryBufferSafe(NET_BUFFER_FIRST_MDL(CurrentNetBuffer),
                            &header,
                            &length,
                            NormalPagePriority);
        if (!header)
            return;

        header += MdlDataOffset;

        for (j = 0; j < (USHORT)SGList->NumberOfElements; j++) 
        {
            //
            // Get the scatter gather element for this TX_DESC
            //
            SGElement = &SGList->Elements[j];
            
            if (MdlDataOffset > 0 && SGElement->Length <= MdlDataOffset)
            {
                MdlDataOffset -= SGElement->Length;
            }
            else
            {
                // Get the next descriptor we will be filling
                Desc = HwGetNextDescToSend(pNic, QueueID, NumTxDescUsed, FALSE);

                //
                // One more TX_DESC used up
                //
                NumTxDescUsed++;
                
                HwTxFillDescriptor(pNic,
                                   Desc,
                                   header,
                                   bFirstSeg,                                               // Start Of MPDU
                                   (BOOLEAN)(j == (USHORT)SGList->NumberOfElements - 1),    // End of MPDU
                                   SGElement->Address.LowPart + MdlDataOffset,
                                   SGElement->Length - MdlDataOffset,
                                   NET_BUFFER_DATA_LENGTH(CurrentNetBuffer),
                                   Rate,
                                   ((bFirstSeg == FALSE) || (bFirstSeg && NicTxd->bMulticastDestAddr)),
                                   bShortPreamble,
                                   (BOOLEAN) ((i != pMpTxd->SGElementListCount - 1) && (j != SGList->NumberOfElements - 1)),
                                   NicTxd->RTSEnabled,
                                   bCTSToSelf,
                                   RTSCTSRate,
                                   (BOOLEAN) (NumTxDescUsed != 1),  // TRUE for all descriptors except first
                                   FALSE,
                                   QueueID);
                   
                //
                // We only want to reduce MdlDataOffset from the first SG element
                //
                MdlDataOffset = 0;
                bFirstSeg = FALSE;
            }
        }
        
        CurrentNetBuffer = NET_BUFFER_NEXT_NB(CurrentNetBuffer);
    }

    MPVERIFY(CurrentNetBuffer == NULL);

    // We need this info for send completion
    NicTxd->TotalDescUsed = NumTxDescUsed;
    MPVERIFY(NumTxDescUsed <= NumTxDescNeeded);
    
    // We have used up these many descriptors
    HwIncrementNextDescToSend(pNic, QueueID, NumTxDescUsed, FALSE);
    
    MPVERIFY(((PTX_STATUS_DESC) HwGetNextDescToSend(pNic, LOW_QUEUE, 0, FALSE))->OWN == 0);
    
    // Now set the OWN bit on the first DESC. This will prompt the
    // hardware to send out the entire MSDU
    FirstDesc->Status |= TXS_OWN;
    
    // Poll the Hw to send
    HwTxPolling(pNic, (UCHAR)QueueID);
}

BOOLEAN
Hw11CanTransmitNBL(
    IN  PNIC                       pNic,
    IN  PNET_BUFFER_LIST           NetBufferList,
    IN  PDOT11_EXTSTA_SEND_CONTEXT Dot11SendContext
    )
{
    UNREFERENCED_PARAMETER(pNic);
    UNREFERENCED_PARAMETER(NetBufferList);
    UNREFERENCED_PARAMETER(Dot11SendContext);

    return TRUE;
}

NDIS_STATUS
HwPrepareTxMSDUForSend(
    IN  PNIC pNic,
    IN  PMP_TX_MSDU pMpTxd
    )
{
    NDIS_STATUS                     ndisStatus = NDIS_STATUS_FAILURE;
    PNET_BUFFER                     CurrentNetBuffer;
    PNIC_TX_MSDU                    pNicTxd;
    PMP_DOT11_MGMT_DATA_MAC_HEADER  FragmentHeader;
    BOOLEAN                         bLastFrag, bShortPreamble;
    ULONG                           MSDULength = 0;
    USHORT                          Rate, AckCtsTime, usDuration, usFragNumber = 0;

    PNICKEY                         pNicKey = NULL;
    ULONG                           headerSize;
    PUCHAR                          EncryptionIV;
    UCHAR                           keyId;
    PNIC_ENCRYPTION_INFO            EncryptionInfo = NULL;
    PUCHAR                          MICData = NULL;
    PMDL                            MICMdl = NULL;
    PMDL                            LastMdl = NULL;
    BOOLEAN                         KeyMappingKey = FALSE;
    BOOLEAN                         DoSoftwareEncryption = FALSE;

    pNicTxd = pMpTxd->NicTxd;

    bShortPreamble = (BOOLEAN)((pNic->ManagementInfo.CapInfo & DOT11_CAPABILITY_SHORT_PREAMBLE) && 
                               (pNic->ManagementInfo.OperatingPhyMIB->PhyType == dot11_phy_type_erp));
    //
    // Default TX rate for all packets
    //
    Rate = pNic->ManagementInfo.CurrentTXDataRate;

    CurrentNetBuffer = NET_BUFFER_LIST_FIRST_NB(pMpTxd->NetBufferList);

    while (CurrentNetBuffer != NULL)
    {
        //
        // This is a new MPDU (802.11 fragment) to be sent out
        // Get the first MDL that has the 802.11 header present in it.
        //
        ndisStatus = Dot11GetMacHeaderFromNB(CurrentNetBuffer, (PDOT11_MAC_HEADER *) &FragmentHeader);
        if (ndisStatus != NDIS_STATUS_SUCCESS) 
        {
            break;
        }

        //
        // If hardware encryption is enabled, check if this frame needs to be encrypted.
        // If so, make sure default WEP key is properly set, and set the WEP bit in the frame header.
        //
        if ((pNic->ManagementInfo.HwUnicastCipher != DOT11_CIPHER_ALGO_NONE) &&
            (FragmentHeader->FrameControl.Type == DOT11_FRAME_TYPE_DATA) &&
            (pNic->ManagementInfo.SafeModeEnabled == FALSE))
        {

            //
            // Find the key that would be used to encrypt the frame if the frame were to be encrypted
            // For unicast frame, search the matching key in the key mapping table first. If not found, 
            // used default key. For multicast frame, only use the default key.
            //
            if (ETH_IS_UNICAST(FragmentHeader->Address1))
            {
                pNicKey = Hw11FindKeyMappingKey(pNic, FragmentHeader->Address1);
            }
            
            if (pNicKey) 
            {
                KeyMappingKey = TRUE;
            }
            else
            {
                pNicKey = pNic->ManagementInfo.KeyTable + pNic->ManagementInfo.DefaultKeyID;
                if (!pNicKey->Valid)
                    pNicKey = NULL;
            }

            //
            // Lookup the ExemptionActionType in the send context info of this frame
            // to determine if we need to encrypt the frame.
            //

            switch (pMpTxd->Dot11SendContext->usExemptionActionType)
            {
                case DOT11_EXEMPT_NO_EXEMPTION:
                    
                    //
                    // We want to encrypt this frame.
                    //

                    FragmentHeader->FrameControl.WEP = 1;
                    break;

                case DOT11_EXEMPT_ALWAYS:
                    
                    //
                    // We don't encrypt this frame.
                    //
                    
                    FragmentHeader->FrameControl.WEP = 0;

                    //
                    // For these packets, we use lower rate for transmission
                    //
                    Rate = pNic->ManagementInfo.CurrentTXMgmtRate;
                    break;

                case DOT11_EXEMPT_ON_KEY_MAPPING_KEY_UNAVAILABLE:

                    //
                    // We encrypt this frame if and only if a key mapping key is set.
                    //

                    FragmentHeader->FrameControl.WEP = (KeyMappingKey ? 1 : 0);
                    Rate = pNic->ManagementInfo.CurrentTXMgmtRate;
                    break;

                default:
                    ASSERT(0);
                    FragmentHeader->FrameControl.WEP = 1;
                    break;
            }

            //
            // If the frame is to be encrypted, but no key is not set, either reject the frame 
            // or clear the WEP bit.
            //

            if (FragmentHeader->FrameControl.WEP && !pNicKey) 
            {
                //
                // If this is a unicast frame or if the BSSPrivacy is on, reject the frame. Otherwise,
                // clear the WEP bit so we will not encrypt the frame.
                //

                if (ETH_IS_UNICAST(FragmentHeader->Address1) || 
                    (pNic->ManagementInfo.CapInfo & DOT11_CAPABILITY_INFO_PRIVACY))
                {
                    return NDIS_STATUS_NOT_ACCEPTED;
                }
                else 
                {
                    FragmentHeader->FrameControl.WEP = 0;
                }
            }

            //
            // For RTL8185, reserve IV field if hardware needs to do the encryption. 
            //

            if (pNic->CardInfo.HardwareID == HW_ID_8185 && FragmentHeader->FrameControl.WEP)
            {
                __try
                {
                    //
                    // Allocate an encryption info structure to save our encryption context
                    //
                    EncryptionInfo = NdisAllocateFromNPagedLookasideList(&pNic->ManagementInfo.EncryptionInfoList);
                    if (!EncryptionInfo)
                    {
                        ndisStatus = NDIS_STATUS_RESOURCES;
                        __leave;
                    }

                    EncryptionInfo->RetreatedSize = 0;
                    EncryptionInfo->MICMdlAdded = FALSE;
                    EncryptionInfo->MICData = NULL;
                    EncryptionInfo->LastMdlByteCount = 0;
                    EncryptionInfo->MICMdl = NULL;

                    //
                    // For TKIP, we need to calculate MIC and append it at the end of MSDU.
                    // For WPA2PSK adhoc, we need to do software encryption. Also allocate
                    // a MIC, but don't do MIC calculation.
                    //
                    if (pNicKey->AlgoId == DOT11_CIPHER_ALGO_TKIP ||
                        (pNicKey->AlgoId == DOT11_CIPHER_ALGO_CCMP &&
                         !ETH_IS_UNICAST(FragmentHeader->Address1) &&
                         pNic->ManagementInfo.CurrentBSSType == dot11_BSS_type_independent &&
                         pNic->ManagementInfo.HwAuthAlgorithm == DOT11_AUTH_ALGO_RSNA_PSK))
                    {
                        ULONG   remainingDataLength = 0, byteCount = 0;
                        
                        //
                        // Allocate a MDL of 8 bytes.
                        //
                        MICData = NdisAllocateFromNPagedLookasideList(&pNic->ManagementInfo.MICDataList);
                        if (!MICData)
                        {
                            ndisStatus = NDIS_STATUS_RESOURCES;
                            __leave;
                        }

                        MICMdl = NdisAllocateMdl(pNic->MiniportAdapterHandle, MICData, 8);
                        if (!MICMdl) 
                        {
                            ndisStatus = NDIS_STATUS_RESOURCES;
                            __leave;
                        }

                        //
                        // Calculate MIC
                        //
                        if (pNicKey->AlgoId == DOT11_CIPHER_ALGO_TKIP)
                        {
                            ndisStatus = HwCalculateMIC(CurrentNetBuffer, 0, pNicKey->TxMICKey, MICData);
                            if (ndisStatus != NDIS_STATUS_SUCCESS)
                            {
                                __leave;
                            }
                        }
                        else
                        {
                            DoSoftwareEncryption = TRUE;
                        }

                        //
                        // Chain the new MDL at the end of the NET_BUFFER.
                        //
                        LastMdl = NET_BUFFER_FIRST_MDL(CurrentNetBuffer);

                        remainingDataLength = NET_BUFFER_DATA_OFFSET(CurrentNetBuffer) + NET_BUFFER_DATA_LENGTH(CurrentNetBuffer);
                        byteCount = MmGetMdlByteCount(LastMdl);
                        while(remainingDataLength > byteCount)
                        {
                            remainingDataLength -= byteCount;
                            LastMdl = LastMdl->Next;
                            byteCount = MmGetMdlByteCount(LastMdl);
                        }

                        EncryptionInfo->LastMdlByteCount = byteCount;
                        EncryptionInfo->MICMdl = MICMdl;
                        HW_MDL_BYTECOUNT(LastMdl) = remainingDataLength;
                        MICMdl->Next = LastMdl->Next;
                        LastMdl->Next = MICMdl;
                        EncryptionInfo->MICMdlAdded = TRUE;
                        EncryptionInfo->MICData = MICData;
                        NET_BUFFER_DATA_LENGTH(CurrentNetBuffer) += 8;
                    }

                    //
                    // Find the size of header and IV field.
                    //
                    headerSize = (FragmentHeader->FrameControl.FromDS && FragmentHeader->FrameControl.ToDS) ?
                                 sizeof(DOT11_DATA_LONG_HEADER) : sizeof(DOT11_DATA_SHORT_HEADER);

                    if (pNicKey->AlgoId == DOT11_CIPHER_ALGO_TKIP ||
                        pNicKey->AlgoId == DOT11_CIPHER_ALGO_CCMP)
                    {
                        EncryptionInfo->RetreatedSize = 8;
                    }
                    else
                    {
                        EncryptionInfo->RetreatedSize = 4;
                    }

                    //
                    // IM driver must guarantee 8 available bytes for retreat. WEP IV will use 4 bytes,
                    // CCMP/TKIP IV will use 8 bytes.
                    //
                    ASSERT(NET_BUFFER_DATA_OFFSET(CurrentNetBuffer) >= HW11_REQUIRED_BACKFILL_SIZE);
                    ASSERT(NET_BUFFER_FIRST_MDL(CurrentNetBuffer) == NET_BUFFER_CURRENT_MDL(CurrentNetBuffer));

                    ndisStatus = NdisRetreatNetBufferDataStart(CurrentNetBuffer, 
                                                               EncryptionInfo->RetreatedSize, 
                                                               0, 
                                                               NULL);
                    if (ndisStatus != NDIS_STATUS_SUCCESS)
                    {
                        ndisStatus = NDIS_STATUS_RESOURCES;
                        __leave;
                    }

                    //
                    // Because we have enough space for retreat and we are at the first MDL, the retreated 
                    // portion is still in the first MDL. We can simply move the 802.11 header to make room
                    // for encryption IV.
                    // Note: cannot call NdisMoveMemory since source and destination overlaps.
                    //
                    FragmentHeader = (PMP_DOT11_MGMT_DATA_MAC_HEADER)
                                     (((PCHAR)FragmentHeader) - EncryptionInfo->RetreatedSize);

                    RtlMoveMemory(FragmentHeader, 
                                  ((PCHAR)FragmentHeader) + EncryptionInfo->RetreatedSize, 
                                  headerSize);

                    //
                    // Now initialize the IV field.
                    //
                    EncryptionIV = Add2Ptr(FragmentHeader, headerSize);
                    keyId = (UCHAR)(pNicKey - pNic->ManagementInfo.KeyTable);
                    if (keyId >= DOT11_MAX_NUM_DEFAULT_KEY)
                        keyId = 0;

                    switch (pNicKey->AlgoId)
                    {
                        case DOT11_CIPHER_ALGO_WEP40:
                        case DOT11_CIPHER_ALGO_WEP104:
                            EncryptionIV[0] = (UCHAR)(pNicKey->IV & 0xff);
                            EncryptionIV[1] = (UCHAR)((pNicKey->IV >> 8) & 0xff);
                            EncryptionIV[2] = (UCHAR)((pNicKey->IV >> 16) & 0xff);
                            EncryptionIV[3] = (keyId << 6);

                            pNicKey->IV++;

                            break;

                        case DOT11_CIPHER_ALGO_CCMP:
                            EncryptionIV[0] = (UCHAR)(pNicKey->PN & 0xff);
                            EncryptionIV[1] = (UCHAR)((pNicKey->PN >> 8) & 0xff);
                            EncryptionIV[2] = 0;
                            EncryptionIV[3] = 0x20 | (keyId << 6);
                            EncryptionIV[4] = (UCHAR)((pNicKey->PN >> 16) & 0xff);
                            EncryptionIV[5] = (UCHAR)((pNicKey->PN >> 24) & 0xff);
                            EncryptionIV[6] = (UCHAR)((pNicKey->PN >> 32) & 0xff);
                            EncryptionIV[7] = (UCHAR)((pNicKey->PN >> 40) & 0xff);

                            pNicKey->PN++;

                            if (DoSoftwareEncryption)
                            {
                                ndisStatus = HwEncryptCCMP(pNicKey, CurrentNetBuffer);
                                if (ndisStatus != NDIS_STATUS_SUCCESS)
                                    __leave;
                            }
                            
                            break;

                        case DOT11_CIPHER_ALGO_TKIP:
                            EncryptionIV[0] = (UCHAR)((pNicKey->TSC >> 8) & 0xff);
                            EncryptionIV[1] = (EncryptionIV[0] | 0x20) & 0x7f;
                            EncryptionIV[2] = (UCHAR)(pNicKey->TSC & 0xff);
                            EncryptionIV[3] = 0x20 | (keyId << 6);
                            EncryptionIV[4] = (UCHAR)((pNicKey->TSC >> 16) & 0xff);
                            EncryptionIV[5] = (UCHAR)((pNicKey->TSC >> 24) & 0xff);
                            EncryptionIV[6] = (UCHAR)((pNicKey->TSC >> 32) & 0xff);
                            EncryptionIV[7] = (UCHAR)((pNicKey->TSC >> 40) & 0xff);

                            pNicKey->TSC++;
                            
                            break;

                        case DOT11_CIPHER_ALGO_WEP:     // this should not be there.
                        default:
                            ASSERT(0);
                            break;
                    }

                    //
                    // Use the MiniportReserved[0] to save the encryption info context.
                    //
                    ndisStatus = NDIS_STATUS_SUCCESS;
                    CurrentNetBuffer->MiniportReserved[0] = EncryptionInfo;
                }
                __finally 
                {
                    if (ndisStatus != NDIS_STATUS_SUCCESS)
                    {
                        if (EncryptionInfo)
                        {
                            NdisFreeToNPagedLookasideList(&pNic->ManagementInfo.EncryptionInfoList, EncryptionInfo);
                        }

                        if (LastMdl)
                        {
                            LastMdl->Next = NULL;
                            NET_BUFFER_DATA_LENGTH(CurrentNetBuffer) -= 8;
                        }

                        if (MICMdl)
                        {
                            NdisFreeMdl(MICMdl);
                        }

                        if (MICData)
                        {
                            NdisFreeToNPagedLookasideList(&pNic->ManagementInfo.MICDataList, MICData);
                        }
                    }
                }

                if (ndisStatus != NDIS_STATUS_SUCCESS)
                    return ndisStatus;
            }
        }

        //
        // We need to know if this is the last fragment for some operations
        // We also need to total length of this MSDU
        //
        bLastFrag = (BOOLEAN)(NET_BUFFER_NEXT_NB(CurrentNetBuffer) == NULL);
        MSDULength += NET_BUFFER_DATA_LENGTH(CurrentNetBuffer);

        //
        // Calculate the Duration/ID field for this packet
        //
        if (HwIsMulticast((PUCHAR)FragmentHeader)) 
        {
            // For multicast/broadcast packets no duration field needed
            pNicTxd->bMulticastDestAddr = TRUE;
            usDuration = 0;
        }
        else 
        {
            pNicTxd->bMulticastDestAddr = FALSE;
            
            // Calculate the duration field value
            AckCtsTime = ComputeTxTime(sAckCtsLng / 8, Rate, FALSE, bShortPreamble);
            if (bLastFrag) 
            {
                usDuration = aSifsTime + AckCtsTime;
            }
            else
            {
                usDuration = 3 * aSifsTime + 2 * AckCtsTime + 
                             ComputeTxTime((USHORT)(NET_BUFFER_DATA_LENGTH(CurrentNetBuffer) + sCrcLng), 
                                           Rate, 
                                           FALSE, 
                                           bShortPreamble);
            }
        }
        
        //
        // Set the calculated duration in the packet
        //
        NdisMoveMemory(&FragmentHeader->DurationID, &usDuration, sizeof(USHORT));

        //
        // Set the Sequence control in the packet
        //
        NdisMoveMemory(&FragmentHeader->SequenceControl, &usFragNumber, 2);
        usFragNumber = usFragNumber + 1;
        pNicTxd->TxRate = Rate;

        //
        // It is by design that net buffer shall be not updated after calling NDIS to
        // allocate SG list. Therefore, we assign sequence number for each net buffer 
        // here.
        // 
        HwInsertSequenceNumForNB(pNic, FragmentHeader, bLastFrag);
        
        //
        // Determine if we will use RTS to send this MSDU
        //
        if (bLastFrag) 
        {
            if ((MSDULength + 4) > pNic->DupCurrentInfo.RTS_Threshold && 
                pNic->DupCurrentInfo.Frag_Threshold > pNic->DupCurrentInfo.RTS_Threshold)
            {
                pNicTxd->RTSEnabled = TRUE;
            }
            else
            {
                pNicTxd->RTSEnabled = FALSE;
            }

            //
            // Save the Total MSDU length in the NicTxd
            //
            pNicTxd->TotalMSDULength = MSDULength;
        }
        
        //
        // Move to the next MPDU
        //
        CurrentNetBuffer = NET_BUFFER_NEXT_NB(CurrentNetBuffer);
    }

    return ndisStatus;
}

//
// Return values:
//  NDIS_STATUS_SUCCESS: The packet was handed to hardware
//  NDIS_STATUS_RESOURCES: The packet could not be handed
//          to hardware due to lack of resources
//  NDIS_STATUS_FAILURE: Send failed due to reasons other
//          than low Hw resources
//
NDIS_STATUS
HwTransmitTxMSDU(
    IN  PNIC pNic,
    IN  PMP_TX_MSDU pMpTxd
    )
{
    BOOLEAN         UseCoalesce;
    ULONG           NumTxDescNeeded, NumTxDescAvailable;
    NDIS_STATUS     ndisStatus;
    BOOLEAN         CanTransmit = FALSE;

    NumTxDescNeeded = HwCountTxResourceNeeded(pMpTxd, &UseCoalesce);
    NumTxDescAvailable = HwGetTxFreeDescNum(pNic, LOW_QUEUE);

    if (NumTxDescAvailable >= NumTxDescNeeded)
    {
        //
        // Enough descriptors to send the packet
        //
        CanTransmit = TRUE;
    }
    else
    {
        //
        // Not enough descriptors to send the NET_BUFFER_LIST as is, 
        // but might be able to transmit by coalescing
        //
        MpTrace(COMP_TESTING, DBG_LOUD, ("Tx Coalesce: Needed %d, Available %d\n",
            NumTxDescNeeded,
            NumTxDescAvailable)
            );
            
        NumTxDescNeeded = pMpTxd->SGElementListCount;   // One Desc per fragment
        if (NumTxDescAvailable > NumTxDescNeeded)
        {
            UseCoalesce = TRUE;
            CanTransmit = TRUE;
        }
    }
    
    if (CanTransmit)
    {
        if (HwAwake(pNic, FALSE) == FALSE)
        {
            // Radio is OFF, drop this packet
            ndisStatus = NDIS_STATUS_DOT11_POWER_STATE_INVALID;
        }
        else
        {
            if (pMpTxd->Dot11SendContext->uDelayedSleepValue > 0) 
            {
                //
                // Save DelaySleepValue
                //
                NdisGetCurrentSystemTime(&pNic->ManagementInfo.DelaySleepTimeStamp);
                pNic->ManagementInfo.DelaySleepValue += pMpTxd->Dot11SendContext->uDelayedSleepValue;
            }

            if (UseCoalesce == FALSE)
            {
                MpTrace(COMP_TESTING, DBG_LOUD, ("Tx Tx MSDU %p. Use Desc: %d\n", pMpTxd, NumTxDescNeeded));
                HwTransmitPacket(pNic, pMpTxd, LOW_QUEUE, (USHORT)NumTxDescNeeded);
                ndisStatus = NDIS_STATUS_SUCCESS;
            }
            else 
            {
                MpTrace(COMP_TESTING, DBG_LOUD, ("Tx Coalesce Tx MSDU %p. Use Desc: %d\n", pMpTxd, NumTxDescNeeded));
                ndisStatus = HwTransmitPacketCoalesce(pNic, pMpTxd, LOW_QUEUE, (USHORT)NumTxDescNeeded);

                if (ndisStatus != NDIS_STATUS_SUCCESS)
                {
                    ndisStatus = NDIS_STATUS_FAILURE;   // Just a failure
                }
            }
        }
    }
    else 
    {
        MpTrace(COMP_TESTING, DBG_LOUD, ("Tx Queued: Needed %d, Available %d\n",
            NumTxDescNeeded,
            NumTxDescAvailable)
            );

        ndisStatus = NDIS_STATUS_RESOURCES;
    }
    
    return ndisStatus;
}


VOID
Hw11TxMSDUScatterGatherComplete(
    IN  PNIC pNic,
    IN  PMP_TX_MSDU pMpTxd,
    IN  NDIS_STATUS ndisStatus,
    IN  BOOLEAN DispatchLevel
    )
{
    UNREFERENCED_PARAMETER(DispatchLevel);
    
    MPVERIFY(MP_TEST_FLAG(pMpTxd, MP_TX_MSDU_SCATTER_GATHER_REQUESTED));

    MpTrace(COMP_TESTING, DBG_SERIOUS, ("SG complete for Tx MSDU %p with Status 0x%08x\n", pMpTxd, ndisStatus));

    if (ndisStatus == NDIS_STATUS_SUCCESS) 
    {
        //
        // If we have entries in our post SG pending list, we shouldnt
        // send this new packet yet. Instead we will queue it and it
        // will be sent later
        //
        if (pNic->TxInfo.PostSGMSDUListLength != 0)
        {
            //
            // Queue this packet for sending from Hw11ProcessPendingSend
            // There is a possibility that Hw11ProcessPendingSend runs
            // before we queue in which case we would have to wait
            // for the next interrupt
            //
            NdisDprAcquireSpinLock(&pNic->TxInfo.PostSGListLock);
            InsertTailList(
                &pNic->TxInfo.PostSGMSDUList,
                &(pMpTxd->NicTxd->PostSGLink)
                );
            NdisDprReleaseSpinLock(&pNic->TxInfo.PostSGListLock);
            NdisInterlockedIncrement(&pNic->TxInfo.PostSGMSDUListLength);

            MpTrace(COMP_TESTING, DBG_LOUD, ("Queuing out of order send %p\n", pMpTxd));

            //
            // This is still send success
            //
            pMpTxd->NicTxd->bFailedDuringSend = FALSE;
        }
        else
        {
            //
            // If we manage send this packet successfully, we will wait for it to complete.
            // Else, we fail it
            //
            ndisStatus = HwTransmitTxMSDU(pNic, pMpTxd);
            switch (ndisStatus)
            {
                case NDIS_STATUS_SUCCESS:
                {
                    pMpTxd->NicTxd->bFailedDuringSend = FALSE;
                    break;
                }
                case NDIS_STATUS_RESOURCES:
                {
                    //
                    // Queue the TX_MSDU so that we can send it later. Send is successful
                    //
                    MpTrace(COMP_TESTING, DBG_LOUD, ("Queuing send %p\n", pMpTxd));

                    NdisDprAcquireSpinLock(&pNic->TxInfo.PostSGListLock);
                    InsertTailList(
                        &pNic->TxInfo.PostSGMSDUList,
                        &(pMpTxd->NicTxd->PostSGLink)
                        );
                    NdisDprReleaseSpinLock(&pNic->TxInfo.PostSGListLock);
                    NdisInterlockedIncrement(&pNic->TxInfo.PostSGMSDUListLength);
                    
                    pMpTxd->NicTxd->bFailedDuringSend = FALSE;                    
                    break;
                }
                default:
                {
                    // Other send failure
                    pMpTxd->NicTxd->WaitSendToComplete = FALSE;
                    pMpTxd->NicTxd->bFailedDuringSend = TRUE;
                }
            }
        }
    }
    else 
    {
        //
        // Scatter gather failed! We will fail this Tx MSDU.
        // If status is NDIS_STATUS_RESOURCES, we can try
        // again and might get lucky. But we cannot try again
        // if we failed due to a reset in progress
        //
        pMpTxd->NicTxd->WaitSendToComplete = FALSE;
    }
}


VOID
Hw11CleanupNetBufferList(
    IN  PNIC pNic,
    IN  PNET_BUFFER_LIST    NetBufferList
    )
{
    PNET_BUFFER_LIST        CurrentNetBufferList;
    PNET_BUFFER             CurrentNetBuffer;
    PNIC_ENCRYPTION_INFO    EncryptionInfo;
    PMDL                    LastMdl;

    //
    // Cleanup is only applicable for RTL8185
    //
    if (pNic->CardInfo.HardwareID != HW_ID_8185)
        return;

    //
    // For each NET_BUFFER that contains our encryption info, advance the 
    // user data, drop the last MDL, and free the encryption info structure.
    //
    for (CurrentNetBufferList = NetBufferList;
         CurrentNetBufferList != NULL;
         CurrentNetBufferList = NET_BUFFER_LIST_NEXT_NBL(CurrentNetBufferList))
    {
        CurrentNetBuffer = NET_BUFFER_LIST_FIRST_NB(CurrentNetBufferList);
        ASSERT(!NET_BUFFER_NEXT_NB(CurrentNetBuffer));

        EncryptionInfo = (PNIC_ENCRYPTION_INFO)CurrentNetBuffer->MiniportReserved[0];

        if (EncryptionInfo) 
        {
            if (EncryptionInfo->RetreatedSize)
            {
                NdisAdvanceNetBufferDataStart(CurrentNetBuffer, 
                                              EncryptionInfo->RetreatedSize,
                                              FALSE,
                                              NULL);
            }

            if (EncryptionInfo->MICMdlAdded)
            {
                LastMdl = NET_BUFFER_FIRST_MDL(CurrentNetBuffer);
                ASSERT(LastMdl->Next);

                while (LastMdl->Next != EncryptionInfo->MICMdl)
                {
                    LastMdl = LastMdl->Next;
                }

                NdisFreeToNPagedLookasideList(&pNic->ManagementInfo.MICDataList, EncryptionInfo->MICData);
                HW_MDL_BYTECOUNT(LastMdl) = EncryptionInfo->LastMdlByteCount;
                LastMdl->Next = EncryptionInfo->MICMdl->Next;
                NdisFreeMdl(EncryptionInfo->MICMdl);
                NET_BUFFER_DATA_LENGTH(CurrentNetBuffer) -= 8;
            }

            CurrentNetBuffer->MiniportReserved[0] = NULL;
            NdisFreeToNPagedLookasideList(&pNic->ManagementInfo.EncryptionInfoList, EncryptionInfo);
        }
    }
}

NDIS_STATUS
Hw11TransmitTxMSDU(
    IN  PNIC pNic,
    IN  PMP_TX_MSDU pMpTxd,
    IN  BOOLEAN DispatchLevel
    )
{
    //
    // We will wait for send completion for this TX_MSDU by default.
    // If we fail in sending this TX_MSDU for any reason, set this flag to
    // FALSE. Also initialize Tx MSDU completion status to FALSE. Only
    // when we have sent all the TX_DESC for this packet successfully,
    // we will set this to true.
    //
    pMpTxd->NicTxd->WaitSendToComplete = TRUE;
    pMpTxd->NicTxd->TxSucceeded = FALSE;
    pMpTxd->NicTxd->bFailedDuringSend = FALSE;
    pMpTxd->NicTxd->SucceedFragCount = 0;
    
    //
    // Prepare this Tx MSDU for sending
    //
    if (HwPrepareTxMSDUForSend(pNic, pMpTxd) == NDIS_STATUS_SUCCESS) 
    {
        //
        // We need to do scatter gather for this Tx MSDU before we can ascertain if we can
        // send it. We don't care about the return value for now since we will be
        // called back on Hw11TxMSDUScatterGatherComplete above
        //
        MPVERIFY(!MP_TEST_FLAG(pMpTxd, MP_TX_MSDU_SCATTER_GATHER_REQUESTED));
        MpTrace(COMP_TESTING, DBG_SERIOUS, ("Scatter Gather Tx MSDU %p\n", pMpTxd));
        Mp11PerformScatterGather(pNic->pAdapter, pMpTxd, DispatchLevel);
        
        MPVERIFY(pMpTxd->SendFlags & MP_TX_MSDU_IS_IN_SEND);
    }
    else 
    {
        //
        // We cannot send this packet! Fail it during SendComplete
        //
        MpTrace(COMP_TESTING, DBG_SERIOUS, ("Could not prepare Tx MSDU %p\n", pMpTxd));
        pMpTxd->NicTxd->WaitSendToComplete = FALSE;
        pMpTxd->NicTxd->bFailedDuringSend = TRUE;
    }
    
    return NDIS_STATUS_SUCCESS;
}


BOOLEAN
Hw11TxMSDUIsComplete(
    IN  PNIC pNic,
    IN  PNIC_TX_MSDU pNicTxd
    )
{
    ULONG                       i;
    BOOLEAN                     bTxMSDUFailed = FALSE;
    PDOT11_EXTSTA_SEND_CONTEXT  pSendContext;
    PTX_STATUS_DESC             pCurrentDesc, pLastDesc;
    int                         DescUsed;
    PDOT11_PHY_FRAME_STATISTICS pPhyStats = &pNic->StatisticsInfo.PhyCounters[Hw11QueryOperatingPhyId(pNic)];
    
    //
    // Check Low Queue(System Packet)
    //
    if (!pNicTxd->WaitSendToComplete) {
        MpTrace(COMP_TESTING, DBG_LOUD, ("Not waiting: %p\n", pNicTxd->pMpTxd));
        return TRUE;
    }

    if (pNicTxd->bFailedDuringSend)
    {
        //
        // Failed during preparing send
        //
        // If this failed Tx MSDU was for a packet whose ACK needed to
        // be indicated, we have to cleanup.
        //
        MpTrace(COMP_TESTING, DBG_LOUD, ("Failed Tx MSDU: %p\n", pNicTxd->pMpTxd));
        
        pNicTxd->WaitSendToComplete = FALSE;
        pNicTxd->SucceedFragCount = 0;

        //
        // Generic send failure
        //
        if(pNicTxd->bMulticastDestAddr)
        {
            pNic->StatisticsInfo.McastCounters.ullTransmittedFailureFrameCount++;
        }
        else
        {
            pNic->StatisticsInfo.UcastCounters.ullTransmittedFailureFrameCount++;
        }
        return TRUE;
    }

    if (HwGetTxBusyDescNum(pNic, LOW_QUEUE) > 0) 
    {
        DescUsed = pNicTxd->TotalDescUsed;
        MPVERIFY(pNic->TxInfo.TxNextDescToCheck[LOW_QUEUE] == (LONG)pNicTxd->FirstDescUsed);
        pLastDesc = (PTX_STATUS_DESC)HwGetNextDescToCheck(pNic, LOW_QUEUE, DescUsed - 1);
        
        if (!pLastDesc->OWN)
        {
            //
            // Own bit 0
            //
            
            pSendContext = pNicTxd->pMpTxd->Dot11SendContext;
            pNicTxd->SucceedFragCount = 0;
            for (i = 0; i < pNicTxd->TotalDescUsed; i++) 
            {
                pCurrentDesc = (PTX_STATUS_DESC)HwGetNextDescToCheck(pNic, LOW_QUEUE, i);
                if (pCurrentDesc->LS)
                {
                    if (pCurrentDesc->TOK)
                    {
                        pNicTxd->SucceedFragCount++;
                        pPhyStats->ullTransmittedFrameCount++;
                        pPhyStats->ullTransmittedFragmentCount++;

                        if(pNicTxd->bMulticastDestAddr)
                        {
                            pPhyStats->ullMulticastTransmittedFrameCount++;
                        }

                        if(pCurrentDesc->RC > 0)
                        {
                            pPhyStats->ullRetryCount++;
                            if (pCurrentDesc->RC > 1)
                            {
                                pPhyStats->ullMultipleRetryCount++;
                            }
                        }

                    }
                    else
                    {
                        pPhyStats->ullFailedCount++;
                        bTxMSDUFailed = TRUE;
                    }

                    HwUpdateTxRetryStat(pNic, pNicTxd->pMpTxd, pCurrentDesc->RC);

                    if(pCurrentDesc->RC > 0)
                    {
                        pPhyStats->ullACKFailureCount += pCurrentDesc->RC;
                    }

                    if (pNicTxd->RTSEnabled)
                    {
                        UCHAR RtsRetry = ((PUCHAR)pCurrentDesc)[1] & 0x7F;
                        pPhyStats->ullRTSFailureCount++;
                        if(RtsRetry < pNic->DupCurrentInfo.LongRetryLimit)
                        {
                            pPhyStats->ullRTSSuccessCount++;
                        }
                    }
                }
            }

            if (!bTxMSDUFailed)
            {
                pNicTxd->TxSucceeded = TRUE;

                if(pNicTxd->bMulticastDestAddr)
                {
                    // Multicast 
                    pNic->StatisticsInfo.McastCounters.ullTransmittedFrameCount++;
                }
                else
                {
                    pNic->StatisticsInfo.UcastCounters.ullTransmittedFrameCount++;
                }
            }

            HwIncrementTxNextDescToCheck(pNic, LOW_QUEUE, DescUsed);
            pNicTxd->WaitSendToComplete = FALSE;
            pNicTxd->FirstDescUsed = 0;
            pNicTxd->TotalDescUsed = 0;
            return TRUE;
        }
    }

    return FALSE;
}

VOID
Hw11ReinitializeTxMSDU(
    IN  PNIC_TX_MSDU pNicTxd
    )
{
    UNREFERENCED_PARAMETER(pNicTxd);
}


NDIS_STATUS
Hw11TxMSDUTransmissionStatus(
    IN  PNIC pNic,
    IN  PNIC_TX_MSDU pNicTxd
    )
{
    UNREFERENCED_PARAMETER(pNic);
    if (pNicTxd->bFailedDuringSend)
    {
        // Failed due to low resources, etc...
        return NDIS_STATUS_FAILURE;
    }
    else
    {
        // Either succeeded or did not get an ACK (pNicTxd->TxSucceeded == FALSE), both 
        // translate to success for the OS
        return NDIS_STATUS_SUCCESS;
    }
}

// Called: DISPATCH/Passive
NDIS_STATUS
Hw11SendMgmtPacket(
    IN  PNIC            pNic,
    IN  PSTA_BSS_ENTRY  pBSSEntry,
    IN  PUCHAR          pMgmtPacket,
    IN  USHORT          MgmtPacketLength
    )
{
    PUCHAR              TxBuf;
    PNICKEY             pNicKey = NULL;
    USHORT              ExtraIV = 0;
    PUCHAR              EncryptionIV;

    UNREFERENCED_PARAMETER(pBSSEntry);
    
    //
    // If hardware WEP encryption is enabled and this frame requires WEP, 
    // check if default WEP key is properly set
    //
    if (pNic->ManagementInfo.HwUnicastCipher != DOT11_CIPHER_ALGO_NONE && ((PDOT11_FRAME_CTRL)pMgmtPacket)->WEP)
    {
        MPVERIFY(pNic->ManagementInfo.SafeModeEnabled == FALSE);
        
        pNicKey = pNic->ManagementInfo.KeyTable + pNic->ManagementInfo.DefaultKeyID;
        if (!pNicKey->Valid)
        {
            return NDIS_STATUS_NOT_ACCEPTED;
        }

        //
        // For RTL8185, we need to insert the IV field. 
        //
        if (pNic->CardInfo.HardwareID == HW_ID_8185)
        {
            ExtraIV = 4;
        }
    }

    //
    // For our hardware, we send management packets on the 
    // NORMAL_QUEUE
    // 
    if (HwGetTxFreeDescNum(pNic, NORMAL_QUEUE) > 0) 
    {
        TxBuf = HwNormalQGetNextToSendBuffer(pNic);

        NdisMoveMemory(
            TxBuf,
            pMgmtPacket,
            DOT11_MGMT_HEADER_SIZE
            );

        if (ExtraIV) 
        {
            EncryptionIV = Add2Ptr(TxBuf, DOT11_MGMT_HEADER_SIZE);
            EncryptionIV[0] = (UCHAR)(pNicKey->IV & 0xff);
            EncryptionIV[1] = (UCHAR)((pNicKey->IV >> 8) & 0xff);
            EncryptionIV[2] = (UCHAR)((pNicKey->IV >> 16) & 0xff);
            EncryptionIV[3] = (pNic->ManagementInfo.DefaultKeyID << 6);

            pNicKey->IV++;
        }

        NdisMoveMemory(
            TxBuf + DOT11_MGMT_HEADER_SIZE + ExtraIV,
            pMgmtPacket + DOT11_MGMT_HEADER_SIZE,
            MgmtPacketLength - DOT11_MGMT_HEADER_SIZE
            );

        MgmtPacketLength = MgmtPacketLength + ExtraIV;

        HwTransmitNextPacketWithLocalBuffer(pNic,
                                            NORMAL_QUEUE,
                                            MgmtPacketLength,
                                            pNic->ManagementInfo.CurrentTXMgmtRate,
                                            FALSE,
                                            TRUE
                                            );

        return NDIS_STATUS_SUCCESS;
    }
    else
    {
        return NDIS_STATUS_RESOURCES;
    }
}

VOID
Hw11ProcessPendingSend(
    IN  PNIC pNic
    )
{
    PNIC_TX_MSDU    pNicTxd = NULL;
    PMP_TX_MSDU     pMpTxd;
    PLIST_ENTRY     pPendingSend;
    NDIS_STATUS     ndisStatus;
    
    while (pNic->TxInfo.PostSGMSDUListLength != 0)
    {
        //
        // We have entries queued that have been SGed but
        // not yet been sent. Lets try to send them
        //
        NdisDprAcquireSpinLock(&pNic->TxInfo.PostSGListLock);
        
        //
        // We always increment PostSGMSDUListLength after insert,
        // so this should not happen
        //
        MPVERIFY(!IsListEmpty(&pNic->TxInfo.PostSGMSDUList));
        pPendingSend = RemoveHeadList(&pNic->TxInfo.PostSGMSDUList);
        pNicTxd = CONTAINING_RECORD(pPendingSend, NIC_TX_MSDU, PostSGLink);
        NdisDprReleaseSpinLock(&pNic->TxInfo.PostSGListLock);

        pMpTxd = pNicTxd->pMpTxd;

        MpTrace(COMP_TESTING, DBG_LOUD, ("Reattempting send %p\n", pMpTxd));

        ndisStatus = HwTransmitTxMSDU(pNic, pMpTxd);
        switch (ndisStatus)
        {
            case NDIS_STATUS_SUCCESS:
            {
                pMpTxd->NicTxd->bFailedDuringSend = FALSE;
                break;
            }
            case NDIS_STATUS_RESOURCES:
            {
                //
                // Requeue this packet at the head and we wont 
                // attempt to send any more
                //
                NdisDprAcquireSpinLock(&pNic->TxInfo.PostSGListLock);
                InsertHeadList(
                    &pNic->TxInfo.PostSGMSDUList,
                    &(pMpTxd->NicTxd->PostSGLink)
                    );
                NdisDprReleaseSpinLock(&pNic->TxInfo.PostSGListLock);
                MpTrace(COMP_TESTING, DBG_LOUD, ("Requeuing to send %p\n", pMpTxd));

                pMpTxd->NicTxd->bFailedDuringSend = FALSE;                    
                break;
            }
            default:
            {
                // Other send failure
                pMpTxd->NicTxd->WaitSendToComplete = FALSE;
                pMpTxd->NicTxd->bFailedDuringSend = TRUE;
                NdisInterlockedDecrement(&pNic->TxInfo.PostSGMSDUListLength);
                break;
            }
        }

        if (ndisStatus == NDIS_STATUS_RESOURCES)
        {
            //
            // Still not enough resources. Dont send (packet has been
            // requeued)
            //
            break;
        }
        else
        {
            //
            // To avoid out of order sending, we decrement only after
            // we have submitted this packet to the hardware
            //
            NdisInterlockedDecrement(&pNic->TxInfo.PostSGMSDUListLength);
        }
    }

    //
    // If we have packets in the low priority queue and the hardware thinks its done, lets
    // ask it to check again
    //
    if (HwGetTxBusyDescNum(pNic, LOW_QUEUE) > 0) 
    {   
        UCHAR tmp;
        
        ReadPortUchar(pNic, TPPoll, &tmp);
        if (tmp & (TPPoll_LPQ<<LOW_QUEUE))
        {
            // Ask the hardware to check the send queues
            HwTxPolling(pNic, LOW_QUEUE);
        }
    }    
}

VOID
Hw11CheckForProtectionInERP(
    IN  PNIC            pNic,
    IN  PUCHAR          pInfoBlob,
    IN  ULONG           infoBlobLength
    )
{
    NDIS_STATUS     status = NDIS_STATUS_SUCCESS;
    UCHAR           erpIELength = 0;
    PUCHAR          erpIEBuf = NULL;

    status = Dot11GetInfoEle(
                pInfoBlob,
                infoBlobLength,
                DOT11_INFO_ELEMENT_ID_ERP,
                &erpIELength,
                &erpIEBuf
                );

    if (status != NDIS_STATUS_SUCCESS || erpIELength != 1)    // ERP IE length has to be 1
    {
        pNic->ManagementInfo.bEnableSendCTSToSelf = FALSE;
    }
    else
    {
        pNic->ManagementInfo.bEnableSendCTSToSelf = (((DOT11_ERP_IE*)erpIEBuf)->UseProtection == 1);;
    }
}

BOOLEAN
HwInsertSequenceNumForNB(
    IN PNIC                 pNic,
    IN PMP_DOT11_MGMT_DATA_MAC_HEADER    pFragmentHeader,
    IN BOOLEAN              IncrementSequenceNumber
    )
{
    BOOLEAN     retVal = FALSE;
    PUCHAR      header = (PUCHAR)pFragmentHeader;
    
    if (header != NULL)
    {
    	header[22] |= ((UCHAR)(pNic->TxInfo.SequenceNumber & 0x000f)) << 4;
    	header[23] = (UCHAR)((pNic->TxInfo.SequenceNumber & 0x0ff0) >> 4);

        if (IncrementSequenceNumber == TRUE)
        {
        	pNic->TxInfo.SequenceNumber++;
        	if (pNic->TxInfo.SequenceNumber == 4096)
            {
        		pNic->TxInfo.SequenceNumber = 0;
            }   
        }

        retVal = TRUE;
    }

    return retVal;
}





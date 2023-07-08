/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    Hw_Recv.c

Abstract:
    Hw layer receive processing functions
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created

Notes:

--*/
#include "hw_pcomp.h"
#include "Hw_main.h"
#include "Hw_Nic.h"
#include "Hw_Func.h"
#include "Hw_ccmp.h"
#include "Mp_Recv.h"
#if DOT11_TRACE_ENABLED
#include "Hw_Recv.tmh"
#endif

//
// If this table ever changes, adjust HwTranslateChannelFreqToLogical
//
ULONG DSSS_Freq_Channel[] = {
    0,
    2412,
    2417,
    2422,
    2427,
    2432,
    2437,
    2442,
    2447,
    2452,
    2457,
    2462,
    2467,
    2472,
    2484
};

#define MP_INCREMENT_RETURN_CURRENT_POINTER(_Nic)    \
    (_Nic->RxInfo.RxNextDescToReturn = (_Nic->RxInfo.RxNextDescToReturn + 1) % _Nic->RxInfo.RxTotalDescNum)

/*
 * Given the physical address of a buffer within an RX_DESC, this macro returns the
 * virtual address of the buffer. This is possible since all RX_DESC are fixed size
 * data structure and come from a contiguous piece of shared memory. By calculating
 * the offset of the physical memory, we can compute the offset in the virtual memory
 * (it should be because of contiguity)
 */
#if DMA_64_BITS
    #define MP_GET_RX_BUFFER_VIRTUAL_ADDRESS(_RxInfo, _RxDesc)          \
        (_RxInfo->RxDesc + (_RxInfo->BufferAddress - _RxInfo->RxDescPhy))
#else   // DMA_64_BITS
    #define MP_GET_RX_BUFFER_VIRTUAL_ADDRESS(_RxInfo, _RxDesc)          \
        (_RxInfo->RxDesc + (_RxInfo->BufferAddress.LowPart - NdisGetPhysicalAddressLow(_RxInfo->RxDescPhy)))
#endif  // DMA_64_BITS


NDIS_STATUS
Hw11InitializeReceive(
    IN  PNIC pNic,
    IN  ULONG TotalFragments
    )
{
    NDIS_STATUS      ndisStatus = NDIS_STATUS_SUCCESS;
    UCHAR            descCount;
    PNIC_RX_FRAGMENT pNicFragment;
    BOOLEAN          bMpInitialized = FALSE;

    __try 
    {
        InitializeListHead(&pNic->RxInfo.RxFragList);
        InitializeListHead(&pNic->RxInfo.RxUnusedFragList);

        NdisInitializeNPagedLookasideList(&pNic->RxInfo.RecvFRAGMENTLookaside,
                                          NULL,
                                          NULL,
                                          0,
                                          sizeof(NIC_RX_FRAGMENT),
                                          HW11_MEMORY_TAG,
                                          0);
    
        //
        // Alloc Hw Rx_Desc 
        //
        ndisStatus = HwAllocateAlignPhyMemory(pNic,
                                              RX_DESC_SIZE*pNic->RxInfo.RxTotalDescNum,
                                              &pNic->RxInfo.RxDescVa,
                                              &pNic->RxInfo.RxDescPa,
                                              (UCHAR **)&pNic->RxInfo.RxDesc,
                                              &pNic->RxInfo.RxDescPhy);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace(COMP_RECV, DBG_SERIOUS, ("HwAllocateAlignPhyMemory fail!\n"));
            __leave;
        }

        pNic->RxInfo.RxDesc[pNic->RxInfo.RxTotalDescNum-1].status |= RXS_EOR;    // Set EOR bit
        pNic->RxInfo.RxAvailableDescNum = 0;
        pNic->RxInfo.RxNextDescToReturn = 0;
        pNic->RxInfo.RxNextDescToReceive = 0;

        //
        // Allocate pAdapter->ReceivePacketPool and pAdapter->ReceiveBufferPool
        //
        ndisStatus = Mp11InitializeReceiveEngine(pNic->pAdapter, TotalFragments);
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            MpTrace(COMP_RECV, DBG_SERIOUS, ("Mp11InitializeReceiveEngine fail!\n"));
            __leave;
        }
        bMpInitialized = TRUE;

        //
        // Set Receive Fragment List
        //
        for (descCount = 0; descCount < TotalFragments; descCount++) 
        {
            pNicFragment = NdisAllocateFromNPagedLookasideList(&pNic->RxInfo.RecvFRAGMENTLookaside);
            if (!pNicFragment) 
            {
                MpTrace(COMP_RECV, DBG_SERIOUS, ("NIC_RX_MSDU_OUT_OF_LOOKASIDE_MEMORY for RecvFRAGMENTLookaside\n"));
                continue;   // We try to allocate as many as we can
            }

            //
            // Clear out the NicFragment structure
            //
            NdisZeroMemory(pNicFragment, sizeof(NIC_RX_FRAGMENT));

            //
            // Allocate the shared memory for this Fragment
            // This implementation is wasting memory. We can be
            // more efficient by allocating shared memory in larger
            // chunks and managing them ourselves
            //
            NdisMAllocateSharedMemory(pNic->MiniportAdapterHandle,
                                      sizeof(ETH_RX_BUFFER_STRUC),
                                      FALSE,
                                      (void **)&pNicFragment->RxBuffer,
                                      &pNicFragment->RxBufferPhys);

            if (!pNicFragment->RxBuffer) 
            {
                MpTrace(COMP_RECV, DBG_SERIOUS, ("Allocate NIC_RX_FRAGMENT share memory fail!\n"));
                NdisFreeToNPagedLookasideList(&pNic->RxInfo.RecvFRAGMENTLookaside, pNicFragment);
                continue;
            }
            
            ndisStatus = Mp11AssociateRxFragment(pNic->pAdapter, pNicFragment, &pNicFragment->MpFragment);
            if (ndisStatus != NDIS_STATUS_SUCCESS) 
            {
                MpTrace(COMP_RECV, DBG_SERIOUS, ("Failed to Mp11AssociateRxFragment\n"));
                NdisMFreeSharedMemory(pNic->MiniportAdapterHandle,
                                      sizeof(ETH_RX_BUFFER_STRUC),
                                      FALSE,
                                      pNicFragment->RxBuffer,
                                      pNicFragment->RxBufferPhys);
                pNicFragment->RxBuffer = NULL;
                NdisFreeToNPagedLookasideList(&pNic->RxInfo.RecvFRAGMENTLookaside, pNicFragment);
                ndisStatus = NDIS_STATUS_SUCCESS;   // Error will be masked as we retry
                continue;
            }
            
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
        }

        NdisAllocateSpinLock(&pNic->RxInfo.FragListLock);
    }
    __finally 
    {
        if (ndisStatus != NDIS_STATUS_SUCCESS)
        {
            // Cleanup
            if (bMpInitialized)
            {
                Mp11TerminateReceiveEngine(pNic->pAdapter);
            }
                        
            if (pNic->RxInfo.RxDescVa)
            {
                NdisMFreeSharedMemory(pNic->MiniportAdapterHandle,
                                      RX_DESC_SIZE*pNic->RxInfo.RxTotalDescNum,
                                      FALSE,
                                      pNic->RxInfo.RxDescVa,
                                      pNic->RxInfo.RxDescPa);
                pNic->RxInfo.RxDescVa = NULL;
            }
            
            NdisDeleteNPagedLookasideList(&pNic->RxInfo.RecvFRAGMENTLookaside);
        }
        else    // NDIS_STATUS_SUCCESS
        {
            if (pNic->RxInfo.RxFragListLen == 0)
            {
                //
                // We were not able to allocate any fragments, initialize failed
                //
                Hw11TerminateReceive(pNic);
                ndisStatus = NDIS_STATUS_RESOURCES;
            }
        }    
    }

    return ndisStatus;
}


VOID
Hw11TerminateReceive(
    IN  PNIC pNic
    )
{
    PNIC_RX_FRAGMENT pNicFragment;
    ULONG            TestOnly = 0;

    //
    // Merge unused queue into FragList queue, so we need only one resource-free code
    //
    while (!IsListEmpty(&pNic->RxInfo.RxUnusedFragList)) 
    {
        pNicFragment = (PNIC_RX_FRAGMENT) RemoveHeadList(&pNic->RxInfo.RxUnusedFragList);

        InsertTailList(&pNic->RxInfo.RxFragList, &pNicFragment->FragmentList);
        pNic->RxInfo.RxFragListLen++;
    }
    
    while (pNic->RxInfo.RxFragListLen > 0) 
    {
        TestOnly++;
        pNicFragment = (PNIC_RX_FRAGMENT)RemoveHeadList(&pNic->RxInfo.RxFragList);
        pNic->RxInfo.RxFragListLen--;

        Mp11DisassociateRxFragment(pNic->pAdapter, pNicFragment);

        //
        // Free the shared memory for this NIC_RX_FRAGMENT
        //
        if (pNicFragment->RxBuffer)
        {
            NdisMFreeSharedMemory(pNic->MiniportAdapterHandle,
                                  sizeof(ETH_RX_BUFFER_STRUC),
                                  FALSE,
                                  pNicFragment->RxBuffer,
                                  pNicFragment->RxBufferPhys);
            pNicFragment->RxBuffer = NULL;            
        }

        NdisFreeToNPagedLookasideList(&pNic->RxInfo.RecvFRAGMENTLookaside, pNicFragment);
    }

    //
    // Free MP Rx MSDU LookAsideList, RxBufferPool, RxPacketPool
    //
    Mp11TerminateReceiveEngine(pNic->pAdapter);
    
    //
    // Free shared memory allocated during Initialize
    //
    NdisDeleteNPagedLookasideList(&pNic->RxInfo.RecvFRAGMENTLookaside);

    //
    // Free Hw Rx_Desc 
    //
    if (pNic->RxInfo.RxDescVa)
    {
        NdisMFreeSharedMemory(pNic->MiniportAdapterHandle,
                              RX_DESC_SIZE*pNic->RxInfo.RxTotalDescNum,
                              FALSE,
                              pNic->RxInfo.RxDescVa,
                              pNic->RxInfo.RxDescPa);
        pNic->RxInfo.RxDescVa = NULL;
    }

    NdisFreeSpinLock(&pNic->RxInfo.FragListLock);
}


VOID
HwReturnFragment(
    IN  PNIC pNic,
    IN  PNIC_RX_FRAGMENT pNicFragment
    )
{
    PRX_DESC        RxDesc;
    USHORT          uLastDescIndex;

    //
    // Get the RX_DESC this fragment can be associated with
    //
    uLastDescIndex = pNic->RxInfo.RxNextDescToReturn;
    RxDesc = &pNic->RxInfo.RxDesc[uLastDescIndex];

    pNicFragment->DataOffset = 0;
    pNicFragment->DataSize = 0;
    pNicFragment->Encrypted = FALSE;
    pNicFragment->Unicast = FALSE;
    pNicFragment->Channel = 0;
    pNicFragment->NicKey = NULL;
    pNicFragment->FrameNumber = 0;

    //
    // Associate the fragment with the chosen RX_DESC
    //
    pNicFragment->RxDescNum = uLastDescIndex;
#if DMA_64_BITS
    RxDesc->BufferAddress = pNicFragment->RxBufferPhys;
#else
    RxDesc->BufferAddress.LowPart = NdisGetPhysicalAddressLow(pNicFragment->RxBufferPhys);
#endif

    RxDesc->length  = sizeof(ETH_RX_BUFFER_STRUC);
    if (uLastDescIndex == (pNic->RxInfo.RxTotalDescNum - 1))
        RxDesc->status = RXS_OWN | RXS_FS | RXS_LS | RXS_EOR;
    else
        RxDesc->status = RXS_OWN | RXS_FS | RXS_LS;

    //
    // Increment the pointer to the next fragment that will return
    //
    MP_INCREMENT_RETURN_CURRENT_POINTER(pNic);

    //
    // One more fragment available to the hardware for receiving
    //
    NdisInterlockedIncrement((PLONG)&pNic->RxInfo.RxAvailableDescNum);
}


VOID
Hw11ReturnFragment(
    IN  PNIC             pNic,
    IN  PNIC_RX_FRAGMENT pNicFragment,
    IN  BOOLEAN          DispatchLevel
    )
{
    MP_ACQUIRE_SPIN_LOCK(&pNic->RxInfo.FragListLock, DispatchLevel);

    if (pNic->RxInfo.RxFragListLen >= pNic->RxInfo.RxTotalDescNum)
    {
        //
        // If the RxFragList has the max possible allowed fragments already in
        // there (the Rtl8180 has a max on 64 desc), we cannot add any right now.
        // When we indicate any frag up, we can then get some Frags from the RxUnunsed
        // Frag list to keep the RxFragList populated
        // 
        InsertTailList(&pNic->RxInfo.RxUnusedFragList, &pNicFragment->FragmentList);
    }
    else 
    {
        //
        // Return the RX_DESC in this fragment to the hardware
        //
        HwReturnFragment(pNic, pNicFragment); 

        //
        // Add this fragment to the available Frag list
        //
        InsertTailList(&pNic->RxInfo.RxFragList, &pNicFragment->FragmentList);
        pNic->RxInfo.RxFragListLen++;
    }
    
    MP_RELEASE_SPIN_LOCK(&pNic->RxInfo.FragListLock, DispatchLevel);
}


VOID
Hw11FreeFragment(
    IN  PNIC             pNic,
    IN  PNIC_RX_FRAGMENT pNicFragment
    )
{
    Mp11DisassociateRxFragment(pNic->pAdapter, pNicFragment);

    //
    // Free the shared memory for this NIC_RX_FRAGMENT
    //
    if (pNicFragment->RxBuffer) 
    {
        NdisMFreeSharedMemory(pNic->MiniportAdapterHandle,
                              sizeof(ETH_RX_BUFFER_STRUC),
                              FALSE,
                              pNicFragment->RxBuffer,
                              pNicFragment->RxBufferPhys);
        pNicFragment->RxBuffer = NULL;            
    }

    NdisFreeToNPagedLookasideList(&pNic->RxInfo.RecvFRAGMENTLookaside, pNicFragment);
}


BOOLEAN
Hw11ReceiveIsAvailable(
    IN  PNIC pNic
    )
{
    PNIC_RX_FRAGMENT    pNicFragment;
    PRX_DESC            pRxDesc;

    NdisDprAcquireSpinLock(&pNic->RxInfo.FragListLock);
    if (!IsListEmpty(&pNic->RxInfo.RxFragList)) 
    {
        MPVERIFY(pNic->RxInfo.RxAvailableDescNum > 0);
        
        //
        // Get the next fragment we expect to be filled in by the hardware
        //
        pNicFragment = (PNIC_RX_FRAGMENT) GetListHeadEntry(&pNic->RxInfo.RxFragList);
        pRxDesc = &pNic->RxInfo.RxDesc[pNicFragment->RxDescNum];

        //
        // If the hardware owns this RX_DESC, there is no receive. If there was
        // a receive, hardware will clear the RXS_OWN bit to give OS ownership
        // of the descriptor.
        //
        if (pRxDesc->status & RXS_OWN)
        {
            NdisDprReleaseSpinLock(&pNic->RxInfo.FragListLock);
            return FALSE;
        }
        else 
        {
            NdisDprReleaseSpinLock(&pNic->RxInfo.FragListLock);
            return TRUE;
        }
    }
    else 
    {
        //
        // There cannot be a receive frame, since hardware has no RX_DESC free 
        // available to use.
        //
        NdisDprReleaseSpinLock(&pNic->RxInfo.FragListLock);
        return FALSE;
    }
}

PNIC_RX_FRAGMENT
Hw11GetReceivedFragment(
    IN  PNIC        pNic,
    IN  BOOLEAN     bRawReceive
    )
{
    PNIC_RX_FRAGMENT    pNicFragment;
    PNIC_RX_FRAGMENT    pUnusedNicFragment;
    PDOT11_MAC_HEADER   pFragmentHdr;
    USHORT              headerSize;
    USHORT              overhead;
    USHORT              IVSize;
    UCHAR               keyId;
    PNICKEY             pNicKey = NULL;
    PUCHAR              EncryptionIV;
    NDIS_STATUS         status;
    PDOT11_PHY_FRAME_STATISTICS pPhyStats = NULL;

    NdisDprAcquireSpinLock(&pNic->RxInfo.FragListLock);

    //
    // One less descriptor in use by hardware
    //
    NdisInterlockedDecrement((PLONG)&pNic->RxInfo.RxAvailableDescNum);

    //
    // Get the fragment in question
    //
    pNicFragment = (PNIC_RX_FRAGMENT) RemoveHeadList(&pNic->RxInfo.RxFragList);
    pNic->RxInfo.RxFragListLen--;

    //
    // This fragment RX_DESC should be the RX_DESC of the received frame 
    //
    NdisMoveMemory(&pNicFragment->RxDesc, &pNic->RxInfo.RxDesc[pNicFragment->RxDescNum], sizeof(RX_DESC));

    //
    // This RX_DESC is currently free. If we have Unused Frags, we can assign this
    // DESC to such a frag so that we can immediately receive a frame that comes
    // along and not have to wait for a return to occur. We must not do this, however,
    // if the list length is already at max (64 for Rtl8180). The unused Frags will
    // remain in the unused list till the shriking algorithm kicks in a frees up the
    // excess (when the network traffic load reduces).
    //

    while (pNic->RxInfo.RxFragListLen < pNic->RxInfo.RxTotalDescNum)
    {
        if (IsListEmpty(&pNic->RxInfo.RxUnusedFragList))
            break;
        
        pUnusedNicFragment = (PNIC_RX_FRAGMENT) RemoveHeadList(&pNic->RxInfo.RxUnusedFragList);
        HwReturnFragment(pNic, pUnusedNicFragment); 

        //
        // Add this fragment to the available Frag list
        //
        InsertTailList(&pNic->RxInfo.RxFragList, &pUnusedNicFragment->FragmentList);
        pNic->RxInfo.RxFragListLen++;
    }

    NdisDprReleaseSpinLock(&pNic->RxInfo.FragListLock);
    
    // Precautionary
    MPASSERTMSG("This desc should have been owned by the OS.\n", !(pNicFragment->RxDesc.status & RXS_OWN));

    if (pNicFragment->RxDesc.status & RXS_PAR)
    {
        pNicFragment->Unicast = TRUE;
    }
    else
    {
        pNicFragment->Unicast = FALSE;
    }

    if (bRawReceive)
    {
        //
        // In raw mode we return the raw packets without doing any adjustment
        // specific to our hardware
        //
        pNicFragment->DataSize = pNicFragment->RxDesc.length;

        //
        // Update stats for received packets
        //
        pPhyStats = &pNic->StatisticsInfo.PhyCounters[Hw11QueryOperatingPhyId(pNic)];
        pPhyStats->ullReceivedFragmentCount++;
        return pNicFragment;
    }

    //
    // Find the header size of the frame. 
    //
    pFragmentHdr = (PDOT11_MAC_HEADER) Hw11GetVirtualAddress(pNicFragment);
    headerSize = (pFragmentHdr->FrameControl.FromDS && pFragmentHdr->FrameControl.ToDS) ?
                 sizeof(DOT11_DATA_LONG_HEADER) : sizeof(DOT11_DATA_SHORT_HEADER);

    //
    // Check if we need to decrypt the multicast data frame in software. We only
    // do so when we are doing WPA2PSK in adhoc mode.  
    //
    if (pFragmentHdr->FrameControl.WEP && 
        pNic->ManagementInfo.CurrentBSSType == dot11_BSS_type_independent &&
        pNic->ManagementInfo.HwAuthAlgorithm == DOT11_AUTH_ALGO_RSNA_PSK &&
        pFragmentHdr->FrameControl.Type == DOT11_FRAME_TYPE_DATA &&
        pFragmentHdr->FrameControl.FromDS == 0 &&
        pFragmentHdr->FrameControl.ToDS == 0 &&
        NdisEqualMemory(((PDOT11_DATA_SHORT_HEADER)pFragmentHdr)->Address3,
                        pNic->ManagementInfo.BssId,
                        sizeof(DOT11_MAC_ADDRESS)) &&
        ETH_IS_MULTICAST(pFragmentHdr->Address1) &&
        !pNicFragment->RxDesc.Decrypted)
    {
        ASSERT(pNic->CardInfo.HardwareID == HW_ID_8185);

        keyId = *((PUCHAR)Add2Ptr(pFragmentHdr, headerSize + 3));
        pNicKey = HwFindPerStaKey(pNic, 
                                  ((PDOT11_DATA_SHORT_HEADER)pFragmentHdr)->Address2,
                                  keyId >> 6);

        if (pNicKey && pNicKey->AlgoId == DOT11_CIPHER_ALGO_CCMP) 
        {
            status = HwDecryptCCMP(pNicKey, 
                                   (PUCHAR)pFragmentHdr, 
                                   pNicFragment->RxDesc.length - 4);
            
            //
            // We attempted to decrypt the data. Set the Decrypted flag, and if 
            // decryption failed, set the RXS_ICV in CRCstatus. 
            //
            pNicFragment->RxDesc.Decrypted = 1;
            if (status != NDIS_STATUS_SUCCESS)
            {
                pNicFragment->RxDesc.CRCstatus |= RXS_ICV;
                // Stats are incremented somewhere else
            }
        }
    }

    //
    // When encryption is enabled, RTL8180/8185 does the decryption on receive but 
    // does not automatically remove IV and ICV/MIC fields. Manually removes them. It is 
    // done by copying the MAC header forward for the size of IV field. 
    //
    if (pFragmentHdr->FrameControl.WEP && 
        (pNic->ManagementInfo.HwUnicastCipher != DOT11_CIPHER_ALGO_NONE) &&
        (pNic->ManagementInfo.SafeModeEnabled == FALSE) &&
        (pNic->CardInfo.HardwareID == HW_ID_8180 || pNicFragment->RxDesc.Decrypted)) 
    {
        //
        // Clear the WEP flag.
        //
        pFragmentHdr->FrameControl.WEP = 0;

        //
        // Figure out which key decrypted this frame.
        //
        if (!pNicKey) 
        {
            if (ETH_IS_UNICAST(pFragmentHdr->Address1) && pFragmentHdr->FrameControl.Type == DOT11_FRAME_TYPE_DATA)
            {
                pNicKey = Hw11FindKeyMappingKey(pNic, ((PDOT11_DATA_SHORT_HEADER)pFragmentHdr)->Address2);
            }
            
            if (!pNicKey) {
                keyId = *((PUCHAR)Add2Ptr(pFragmentHdr, headerSize + 3));
                pNicKey = pNic->ManagementInfo.KeyTable + (keyId >> 6);
            }
        }

        if (pNicKey->Valid)
        {
            //
            // Find the IVSize and total overhead due to encryption and CRC.
            //
            EncryptionIV = Add2Ptr(pFragmentHdr, headerSize);
            switch (pNicKey->AlgoId)
            {
                case DOT11_CIPHER_ALGO_TKIP:

                    // 
                    // 8 bytes IV, 4 byte ICV, 4 bytes CRC. The per-MSDU MIC is removed after frame 
                    // reassembling and MIC failure checking.
                    //

                    IVSize = 8;
                    overhead = 16;
                    pNicFragment->FrameNumber = (((ULONGLONG)EncryptionIV[0]) << 8) |
                                                ((ULONGLONG)EncryptionIV[2]) |
                                                (((ULONGLONG)EncryptionIV[4]) << 16) |
                                                (((ULONGLONG)EncryptionIV[5]) << 24) |
                                                (((ULONGLONG)EncryptionIV[6]) << 32) |
                                                (((ULONGLONG)EncryptionIV[7]) << 40);

                    break;

                case DOT11_CIPHER_ALGO_CCMP:

                    // 
                    // 8 bytes IV, 8 bytes MIC, 4 bytes CRC. 
                    //

                    IVSize = 8;
                    overhead = 20;
                    pNicFragment->FrameNumber = ((ULONGLONG)EncryptionIV[0]) |
                                                (((ULONGLONG)EncryptionIV[1]) << 8) |
                                                (((ULONGLONG)EncryptionIV[4]) << 16) |
                                                (((ULONGLONG)EncryptionIV[5]) << 24) |
                                                (((ULONGLONG)EncryptionIV[6]) << 32) |
                                                (((ULONGLONG)EncryptionIV[7]) << 40);

                    break;

                case DOT11_CIPHER_ALGO_WEP104:
                case DOT11_CIPHER_ALGO_WEP40:

                    // 
                    // 4 bytes IV, 4 bytes ICV, 4 bytes CRC. 
                    //

                    IVSize = 4;
                    overhead = 12;
                    break;

                default:
                    ASSERT(0);
                    IVSize = 0;
                    overhead = 0;
                    break;
            }

            //
            // Copy the header. It is probably the most efficient way to get rid of the IV field.
            // Note: cannot call NdisMoveMemory since source and destination overlaps.
            //
            RtlMoveMemory(((PCHAR)pFragmentHdr) + IVSize, pFragmentHdr, headerSize);

            //
            // Set the data size and offset.
            //

            pNicFragment->DataOffset = IVSize;
            pNicFragment->DataSize = pNicFragment->RxDesc.length - overhead;
            pNicFragment->Encrypted = TRUE;
            pNicFragment->NicKey = pNicKey;
        }
        else
        {
            //
            // Hardware attempted decryption, but the key it used was not valid
            //
            pNicFragment->DataSize = pNicFragment->RxDesc.length - 4;   // CRC
            pNicFragment->Encrypted = TRUE;
            pNicFragment->NicKey = pNicKey;
            pNicFragment->RxDesc.CRCstatus |= RXS_ICV;      // Mark as an ICV error
        }
    }
    else
    {
        pNicFragment->DataSize = pNicFragment->RxDesc.length - 4;   // CRC
        pNicFragment->Encrypted = (BOOLEAN)(pFragmentHdr->FrameControl.WEP == 1);
    }

    return pNicFragment;
}

BOOLEAN
Hw11FragmentIsGood(
    IN  PNIC pNic,
    IN  PNIC_RX_FRAGMENT pNicFragment
    )
{
    PDOT11_PHY_FRAME_STATISTICS pPhyStats = &pNic->StatisticsInfo.PhyCounters[Hw11QueryOperatingPhyId(pNic)];
    PNICKEY                     pNicKey;

    //
    // check the status of the fragment
    //
    if (pNicFragment->RxDesc.CRCstatus & RXS_CRC32) 
    {
        pPhyStats->ullFCSErrorCount++;
        return FALSE;
    }
    else if (pNicFragment->RxDesc.CRCstatus & RXS_ICV)
    {
        if (pNicFragment->Encrypted)
        {
            //
            // For MAC counters, we shouldnt count duplicates, filter those 
            // counters out
            //
            if (HwFragmentIsDuplicate(pNic, pNicFragment))
            {
                // Drop and dont count
                return FALSE;
            }
        
            pNicKey = pNicFragment->NicKey;
            if (pNicKey != NULL)
            {
                if (pNicKey->Valid)
                {
                    //
                    // Decryption failed even though we think we have
                    // a valid key. This counts as an ICV error
                    //
                    switch (pNicKey->AlgoId)
                    {
                        case DOT11_CIPHER_ALGO_CCMP:
                            // This is unlikely
                            if (pNicFragment->Unicast)
                            {
                                pNic->StatisticsInfo.UcastCounters.ullCCMPDecryptErrors++;
                            }
                            else
                            {
                                pNic->StatisticsInfo.McastCounters.ullCCMPDecryptErrors++;
                            }
                            break;
                            
                        case DOT11_CIPHER_ALGO_TKIP:
                            if (pNicFragment->Unicast)
                            {
                                pNic->StatisticsInfo.UcastCounters.ullTKIPICVErrorCount++;
                            }
                            else
                            {
                                pNic->StatisticsInfo.McastCounters.ullTKIPICVErrorCount++;
                            }                        
                            break;
                        
                        case DOT11_CIPHER_ALGO_WEP104:
                        case DOT11_CIPHER_ALGO_WEP40:
                            if (pNicFragment->Unicast)
                            {
                                pNic->StatisticsInfo.UcastCounters.ullWEPICVErrorCount++;
                            }
                            else
                            {
                                pNic->StatisticsInfo.McastCounters.ullWEPICVErrorCount++;
                            }
                            break;
                            
                        default:
                            break;
                    }
                }
                else
                {
                    //
                    // Decryption failed and the key we have is invalid. This happens 
                    // when the hardware uses a default key for decrypting a packet, but
                    // the default key was not set
                    //
                    if (pNicFragment->Unicast)
                    {
                        pNic->StatisticsInfo.UcastCounters.ullWEPUndecryptableCount++;
                    }
                    else
                    {
                        pNic->StatisticsInfo.McastCounters.ullWEPUndecryptableCount++;
                    }
                }
            }
            else
            {
                //
                // No key found - Our hardware would still have done the decryption (using a bogus
                // default key id) and this is accounted in the check above (!NicKey->Valid)
                //
            }
            
            if (pNicFragment->Unicast)
            {
                pNic->StatisticsInfo.UcastCounters.ullDecryptFailureCount++;
            }
            else
            {
                pNic->StatisticsInfo.McastCounters.ullDecryptFailureCount++;
            }
        }

        return FALSE;
    }

    if ((pNicFragment->RxDesc.status & (RXS_BOVF | RXS_DMAFAIL)) ||
        (pNicFragment->RxDesc.status & (RXS_FS | RXS_LS)) != (RXS_FS | RXS_LS) ||
        (pNicFragment->RxDesc.length == 4080))
    {
        //
        // Generic error
        //
        if (pNicFragment->Unicast)
        {
            pNic->StatisticsInfo.UcastCounters.ullReceivedFailureFrameCount++;
        }
        else
        {
            pNic->StatisticsInfo.McastCounters.ullReceivedFailureFrameCount++;
        }
        return FALSE;
    }
    else 
    {
        //
        // Update some statistics
        //
        pPhyStats->ullReceivedFragmentCount++;

        //
        // Drop any duplicate frames
        //
        return !HwFragmentIsDuplicate(pNic, pNicFragment);
    }
}

BOOLEAN
Hw11FilterFragment(
    IN  PNIC pNic,
    IN  PNIC_RX_FRAGMENT pNicFragment
    )
{
    PUCHAR      pktbuf = Add2Ptr(pNicFragment->RxBuffer, pNicFragment->DataOffset);
    UCHAR       type = (pktbuf[0] & 0x0f) >> 2;
    BOOLEAN     bAddrMatch = HwIsAddr1Match(pktbuf, pNic->CardInfo.MacAddr);
    BOOLEAN     bIsBroadcast = HwIsBroadcast(pktbuf);
    BOOLEAN     bIsMulticast = HwIsMulticast(pktbuf);
    PDOT11_PHY_FRAME_STATISTICS pPhyStats = NULL;

    switch(type)
    {
    case DOT11_FRAME_TYPE_MANAGEMENT:
        if (bAddrMatch && (pNic->RxInfo.ReceiveFilter & NDIS_PACKET_TYPE_802_11_DIRECTED_MGMT))
            return TRUE;
        
        if (bIsBroadcast && (pNic->RxInfo.ReceiveFilter & NDIS_PACKET_TYPE_802_11_BROADCAST_MGMT))
            return TRUE;

        if (bIsMulticast && (pNic->RxInfo.ReceiveFilter & (NDIS_PACKET_TYPE_802_11_MULTICAST_MGMT | 
                                                           NDIS_PACKET_TYPE_802_11_ALL_MULTICAST_MGMT)))
            return TRUE;

        if (pNic->RxInfo.ReceiveFilter & NDIS_PACKET_TYPE_802_11_PROMISCUOUS_MGMT)
        {
            pPhyStats = &pNic->StatisticsInfo.PhyCounters[Hw11QueryOperatingPhyId(pNic)];
            pPhyStats->ullPromiscuousReceivedFragmentCount++;
            return TRUE;
        }

        break;
        
    case DOT11_FRAME_TYPE_CONTROL:
        if (bAddrMatch && (pNic->RxInfo.ReceiveFilter & NDIS_PACKET_TYPE_802_11_DIRECTED_CTRL))
            return TRUE;

        if (bIsBroadcast && (pNic->RxInfo.ReceiveFilter & NDIS_PACKET_TYPE_802_11_BROADCAST_CTRL))
            return TRUE;

        if (pNic->RxInfo.ReceiveFilter & NDIS_PACKET_TYPE_802_11_PROMISCUOUS_CTRL)
        {
            pPhyStats = &pNic->StatisticsInfo.PhyCounters[Hw11QueryOperatingPhyId(pNic)];
            pPhyStats->ullPromiscuousReceivedFragmentCount++;
            return TRUE;
        }        

        //
        // Note: no multicast control frame.
        //

        break;
        
    case DOT11_FRAME_TYPE_DATA:
        if (bAddrMatch && (pNic->RxInfo.ReceiveFilter & NDIS_PACKET_TYPE_DIRECTED))
            return TRUE;

        if (bIsBroadcast && (pNic->RxInfo.ReceiveFilter & NDIS_PACKET_TYPE_BROADCAST))
            return TRUE;

        if (bIsMulticast&& (pNic->RxInfo.ReceiveFilter & (NDIS_PACKET_TYPE_MULTICAST | 
                                                          NDIS_PACKET_TYPE_ALL_MULTICAST)))
            return TRUE;

        if (pNic->RxInfo.ReceiveFilter & (NDIS_PACKET_TYPE_PROMISCUOUS | 
                                          NDIS_PACKET_TYPE_802_11_RAW_DATA))
        {
            pPhyStats = &pNic->StatisticsInfo.PhyCounters[Hw11QueryOperatingPhyId(pNic)];
            pPhyStats->ullPromiscuousReceivedFragmentCount++;
            return TRUE;
        }

        break;
        
    default:
        //
        // Reserved packet should always be filtered
        //
        return FALSE;
    }

    return FALSE;
}

NDIS_STATUS
Hw11GrowFragmentPool(
    IN  PNIC         pNic,
    IN  ULONG        NumFragmentsToAllocate,
    IN  ULONG        MaxFragmentsToAllocate
    )
{
    ULONG           i;
    PNIC_RX_FRAGMENT    pNicFragment;

    UNREFERENCED_PARAMETER(MaxFragmentsToAllocate);

    for (i = 0; i < NumFragmentsToAllocate; i++) 
    {
        pNicFragment = NdisAllocateFromNPagedLookasideList(&pNic->RxInfo.RecvFRAGMENTLookaside);
        if (!pNicFragment)
        {
            MpTrace(COMP_RECV, DBG_SERIOUS, ("NIC_RX_MSDU_OUT_OF_LOOKASIDE_MEMORY for RecvFRAGMENTLookaside\n"));
            continue;
        }
        
        //
        // Clear out the NicFragment structure
        //
        NdisZeroMemory(pNicFragment, sizeof(NIC_RX_FRAGMENT));
        
        //
        // Hw11SharedMemoryAllocateComplete() will be called when complete
        //
        if (Mp11AllocateSharedMemoryAsync(pNic->pAdapter,
                                          sizeof(ETH_RX_BUFFER_STRUC),
                                          FALSE,
                                          pNicFragment) == NDIS_STATUS_FAILURE) 
        {
            //
            // We were not able to allocate memory! Free the fragment associated
            //
            MpTrace(COMP_RECV, DBG_SERIOUS, ("Failed to NdisMAllocateSharedMemoryAsync\n"));
            NdisFreeToNPagedLookasideList(&pNic->RxInfo.RecvFRAGMENTLookaside, pNicFragment);

            //
            // Do not try to allocate any more memory. System is running low.
            //
            break;
        }
    }
    
    return NDIS_STATUS_SUCCESS;
}


VOID
HwResetReceive(
    IN  PNIC pNic
    )
{
    ULONG               i;
    PNIC_RX_FRAGMENT    pNicFragment;

    NdisAcquireSpinLock(&pNic->RxInfo.FragListLock);
    
    //
    // Reset the receive list of fragments.
    // First we take ownership of all the RX_DESC away from the HW
    // Next we will assocaite the RX_DESC at the 
    // head of the array with the fragments that are
    // available to us. When hardware resumes, it will start
    // from the head of the array.
    // Note: This mechanism can potentially causes frames to be lost.
    //
    
    pNic->RxInfo.RxNextDescToReturn = 0;
    pNic->RxInfo.RxAvailableDescNum = 0;

    for(i = 0; i < pNic->RxInfo.RxTotalDescNum; i++) 
    {
        pNic->RxInfo.RxDesc[i].status &= ~RXS_OWN;
    }
    
    pNicFragment = (PNIC_RX_FRAGMENT)GetListHeadEntry(&pNic->RxInfo.RxFragList);
    while (pNicFragment) 
    {
        if ((PVOID)pNicFragment == (PVOID)&pNic->RxInfo.RxFragList)
        {
            break;
        }        

        //
        // return ownership to hardware
        //
        HwReturnFragment(pNic, pNicFragment);

        //
        // Go to next fragment
        //
        pNicFragment = (PNIC_RX_FRAGMENT)pNicFragment->FragmentList.Flink;
    }
    
    NdisReleaseSpinLock(&pNic->RxInfo.FragListLock);
}

ULONG
Hw11GetCalibratedRSSI(
    IN  PNIC            pNic,
    IN  PNIC_RX_FRAGMENT    pNicFragment
    )
{
    return HwRSSI(pNic, pNicFragment); //0-100;
}

LONG
Hw11GetRSSI(
    IN  PNIC            pNic,
    IN  PNIC_RX_FRAGMENT    pNicFragment
    )
{
    return (LONG)(((HwRSSI(pNic,pNicFragment) + 1) >> 1) - 95); //dBm
}

LONG
Hw11GetMinRSSI(
    IN  PNIC pNic,
    IN  ULONG uDataRate
    )
{
    UNREFERENCED_PARAMETER(pNic);
    UNREFERENCED_PARAMETER(uDataRate);

    // TODO: RSSI typically does change with Data rate
    return -95;
}


LONG
Hw11GetMaxRSSI(
    IN  PNIC pNic,
    IN  ULONG uDataRate
    )
{
    UNREFERENCED_PARAMETER(pNic);
    UNREFERENCED_PARAMETER(uDataRate);

    // TODO: RSSI typically does change with Data rate
    return -45;
}

UCHAR
Hw11GetDataRate(
    IN  PNIC            pNic,
    IN  PNIC_RX_FRAGMENT    pNicFragment
    )
{
    UCHAR HwRate;
    UNREFERENCED_PARAMETER(pNic);
    
    HwRate = (UCHAR) ((pNicFragment->RxDesc.status & 0x00f0) >> 4); // RxDesc.status Bit7-4 is RXRATE

    return HwHwRateToMRate(HwRate);
}

ULONG
Hw11GetChannelCenterFrequency(
    IN  PNIC            pNic,
    IN  PNIC_RX_FRAGMENT    pNicFragment
    )
{
    UCHAR               Channel = pNic->ManagementInfo.OperatingPhyMIB->Channel;

    if (pNicFragment->Channel != 0)
    {
        // For Beacons & probes received during scanning, we would 
        // have saved the channel. Use that instead
        Channel = pNicFragment->Channel;
    }

    if (Channel >= 15)
    {
        // 11a channel
        return 5000 + 5 * Channel;
    }
    else
    {
        return DSSS_Freq_Channel[Channel];
    }
}

VOID
Hw11FillReceiveContext(
    IN  PNIC pNic,
    IN  PNIC_RX_FRAGMENT pNicFragment,
    IN OUT PDOT11_EXTSTA_RECV_CONTEXT Dot11RecvContext
    )
{
    //
    // Fill in the send context fields that are always needed
    //
    MP_ASSIGN_NDIS_OBJECT_HEADER(Dot11RecvContext->Header, 
                                 NDIS_OBJECT_TYPE_DEFAULT,
                                 DOT11_EXTSTA_RECV_CONTEXT_REVISION_1,
                                 sizeof(DOT11_EXTSTA_RECV_CONTEXT));
    Dot11RecvContext->uPhyId = Hw11QueryOperatingPhyId(pNic);
    Dot11RecvContext->lRSSI = Hw11GetRSSI(pNic, pNicFragment);
    Dot11RecvContext->ucDataRate = Hw11GetDataRate(pNic, pNicFragment);
    Dot11RecvContext->uChCenterFrequency = Hw11GetChannelCenterFrequency(pNic, pNicFragment);   
    Dot11RecvContext->uReceiveFlags = 0;

    if (HW_IS_IN_NETWORK_MONITOR_MODE(pNic))
    {
        //
        // If this packet has a FCS error, set the RAW packet FCS error flag
        //
        if (pNicFragment->RxDesc.CRCstatus & RXS_CRC32) 
            Dot11RecvContext->uReceiveFlags = DOT11_RECV_FLAG_RAW_PACKET_FCS_FAILURE;
    }
}

BOOLEAN
HwIsSSIDAny(
    IN  PDOT11_SSID SSID
    )
{
    if (SSID->uSSIDLength == 0)   // a kind of "ANY SSID"
    {
        return TRUE;
    }

    return (BOOLEAN)((SSID->uSSIDLength == 3) &&
                     (SSID->ucSSID[0] == 'A' || SSID->ucSSID[0] == 'a') &&
                     (SSID->ucSSID[1] == 'N' || SSID->ucSSID[1] == 'n') &&
                     (SSID->ucSSID[2] == 'Y' || SSID->ucSSID[2] == 'y'));
}

void
HwHandleTimingCriticalPacket(
    IN  PNIC pNic
    )
{
    PNIC_RX_FRAGMENT    pNicFragment;
    PRX_DESC            pRxDesc;
    DOT11_SSID          SSID;
    NDIS_STATUS         ndisStatus;
    PUCHAR              pktbuf;

    if (pNic->ManagementInfo.bAdvertiseBSS == FALSE) 
    {
        //
        // We should not be advertising the BSS right now.
        // No need to handle probe requests.
        //
        return;
    }
    
    pNicFragment = (PNIC_RX_FRAGMENT)GetListHeadEntry(&pNic->RxInfo.RxFragList);
    pktbuf = Add2Ptr(pNicFragment->RxBuffer, pNicFragment->DataOffset);

    //
    // Scan Probr_req for all RecvFragList
    //
    while (pNicFragment) 
    {
        if ((PVOID)pNicFragment == (PVOID)pNic->RxInfo.RxFragList.Blink)
        {
            break;
        }

        pRxDesc = &pNic->RxInfo.RxDesc[pNicFragment->RxDescNum];
        if (pRxDesc->status & RXS_OWN)
        {
            //
            // not closed
            //
            break;
        }

        //
        // A good packet? drop it if not.
        //
        if ((pNicFragment->RxDesc.CRCstatus & (RXS_CRC32 | RXS_ICV)) ||
            (pNicFragment->RxDesc.status & (RXS_BOVF | RXS_DMAFAIL)) ||
            ((pNicFragment->RxDesc.status & (RXS_FS | RXS_LS)) != (RXS_FS | RXS_LS)))
        {
            //
            // discard CRC packet(Except sniffer mode)
            //
            pNicFragment = (PNIC_RX_FRAGMENT)pNicFragment->FragmentList.Flink;
            continue;
        }

        if (*pktbuf == 0x40 && pNicFragment->RxDesc.length > sizeof(DOT11_MGMT_HEADER)) 
        {

            //
            // received a Probe Request, need to send a Probe Response.
            // If the SSID is not ANY or we are a hidden node and this is not
            // a directed request, do not respond to probe
            // 
            
            ndisStatus = Dot11CopySSIDFromMemoryBlob(pktbuf + sizeof(DOT11_MGMT_HEADER),
                                                     (ULONG)(pNicFragment->RxDesc.length - sizeof(DOT11_MGMT_HEADER)),
                                                     &SSID);

            if (ndisStatus == NDIS_STATUS_SUCCESS) 
            {
                //
                // Not responding to a probe-request packet with different SSID
                //
                if (HwIsSSIDAny(&SSID) == FALSE &&
                    RtlCompareMemory(pNic->ManagementInfo.SSID, SSID.ucSSID, SSID.uSSIDLength) != SSID.uSSIDLength)
                {
                    pNicFragment = (PNIC_RX_FRAGMENT)pNicFragment->FragmentList.Flink;
                    continue;
                }

                HwOnProbe(pNic, 
                          pktbuf, 
                          (USHORT)pNicFragment->RxDesc.length, 
                          HwHwRateToMRate((UCHAR)((pNicFragment->RxDesc.status & 0xf0) >> 4)));
            }
        }

        pNicFragment = (PNIC_RX_FRAGMENT)pNicFragment->FragmentList.Flink;
    }
}

VOID
HwResponseToPacket(
    IN  PNIC pNic,
    IN  PNIC_RX_FRAGMENT pNicFragment
    )
{
    PUCHAR                  pktbuf;
    USHORT                  pktlen;
    UCHAR                   type;
    UCHAR                   subtype;
    BOOLEAN                 bKeepAwake;
    OctetString             Packet, Tim;
    PDOT11_POWER_MGMT_MODE  PowerMgmtMode;
    PDOT11_BEACON_FRAME     BeaconFrame;
    LARGE_INTEGER           CurrentTime;
    ULONGLONG               PhaseDiff;
    ULONG                   SkipCount;
    ULONG                   DTIMCount;

    //
    // if power saving is not turned on simply return. We will stay awake
    //

    PowerMgmtMode = &pNic->ManagementInfo.PowerMgmtMode;
    if (PowerMgmtMode->dot11PowerMode == dot11_power_mode_active)
    {
        return;
    }

    //
    // If we are not associated (with an AP), unless we are in the middle of a scanning, turn 
    // off RF indifinitely. If we are in the middle of a scanning, stay awake.
    //

    if (PowerMgmtMode->usAID == 0) 
    {
        if (!pNic->ManagementInfo.bScanInProgress)
        {
            MpTrace(COMP_POWER, DBG_LOUD, (" *** RF OFF indefinitely\n"));
            HwSetRFState(pNic, RF_OFF);
        }

        return;
    }

    //
    // Initialize local variables.
    //

    pktbuf = Add2Ptr(pNicFragment->RxBuffer, pNicFragment->DataOffset);
    pktlen = pNicFragment->RxDesc.length - 4;
    type = (pktbuf[0]  & 0x0f) >> 2;
    subtype = (pktbuf[0]  & 0xf0) >> 4;
    bKeepAwake = TRUE;

    //
    // Determine if we can doze depending on the frame received.
    //

    switch (type)
    {
    case 0:             // Management
        switch (subtype) 
        {
        case 0x8:       // Beacon
            if (HW_IS_IN_STA_INFRA_MODE(pNic) &&
                PowerMgmtMode->dot11PowerMode == dot11_power_mode_powersave &&
                memcmp(pktbuf + 16, pNic->ManagementInfo.BssId, 6) == 0) 
            {
                //
                // This Beacon is mine
                //

                NdisGetCurrentSystemTime(&CurrentTime);
                CurrentTime.QuadPart /= 10;

                //
                // Determine how many more beacons we can skip.
                //

                SkipCount = PowerMgmtMode->usListenInterval;
                
                FillOctetString(Packet, pktbuf, pktlen);
                Tim=PacketGetElement(Packet, EID_Tim);

                if (Tim.Length != 0) 
                {

                    //
                    // Sucessfully found TIM element. If there is UC data for us, send PS-Poll.
                    // If we are to receive DTIM and the DTIM count is 0 and there is MC/BC data, keep
                    // awake to receive it.
                    //
                    if (TimGetAIDBit(Tim, (USHORT)(PowerMgmtMode->usAID & 0x3fff)))
                    {
                        HwSendPSPoll(pNic);
                        pNic->ManagementInfo.bUnicastDataAvailable = TRUE;
                    }
                    else if (!PowerMgmtMode->bReceiveDTIMs || Tim.Octet[0] != 0 || !TimGetBcMcBit(Tim)) 
                    {
                        bKeepAwake = FALSE;
                    }

                    //
                    // Update SkipCount if we are to receive DTIM.
                    //

                    if (PowerMgmtMode->bReceiveDTIMs) 
                    {
                        DTIMCount = Tim.Octet[0] ? Tim.Octet[0] : Tim.Octet[1];
                        if (SkipCount > DTIMCount)
                            SkipCount = DTIMCount;
                    }
                }

                //
                // Calculate the time different between when the beacon is supposed to be transmitted 
                // and when it is actually transmitted.
                //

                BeaconFrame = Add2Ptr(pktbuf, sizeof(DOT11_MGMT_HEADER));
                PhaseDiff = BeaconFrame->Timestamp % (((ULONGLONG)BeaconFrame->BeaconInterval) << 10);

                //
                // Calculate the time instant (in micro-second) we would have to wake up for the next beacon.
                //
                ASSERT(SkipCount > 0);
                pNic->ManagementInfo.WakeupTime = CurrentTime.QuadPart - PhaseDiff +
                                                  (((ULONGLONG)(SkipCount * BeaconFrame->BeaconInterval)) << 10);
            }

            break;
            
        case 0x9:       // ATIM
            if (HW_IS_IN_STA_ADHOC_MODE(pNic) && memcmp(pktbuf + 4, pNic->CardInfo.MacAddr, 6) == 0 &&
                PowerMgmtMode->dot11PowerMode == dot11_power_mode_powersave)
            {
                //
                // We have been notified by a station that it has packets 
                // buffered for us. We must stay awake.
                //
                pNic->ManagementInfo.bATIMPacketReceived = TRUE;
            }

            break;
        }

        break;
        
    case 1:             // Control
        break;
        
    case 2:             // Data
        switch (subtype) {
        case 0x0:       // Data
            if (PowerMgmtMode->dot11PowerMode == dot11_power_mode_powersave && HW_IS_IN_STA_INFRA_MODE(pNic))
            {
                //
                // For BC/MC data, we don't send PS-poll. We keep awake if either the "more data" bit is  
                // set or we know there is unicast data for us.
                //
                // For UC data, if the "more data" bit is set, send PS-Poll, otherwise, we will not keep awake.
                //

                if (HwIsMulticast(pktbuf) || HwIsBroadcast(pktbuf)) 
                {
                    bKeepAwake = ((pktbuf[1] & 0x20) || pNic->ManagementInfo.bUnicastDataAvailable);
                }
                else if (memcmp(pktbuf + 4, pNic->CardInfo.MacAddr, 6) == 0)
                {
                    //
                    // More data bit is set
                    //
                    if ((pktbuf[1] & 0x20) != 0) 
                    {
                        HwSendPSPoll(pNic);
                    }
                    else 
                    {
                        pNic->ManagementInfo.bUnicastDataAvailable = FALSE;

                        //
                        // TODO:
                        // Comment out the following for now. It appears that if we turn off
                        // RF at this point, we will have problem receiveing broadcast message
                        // later on. We don't understand why it is the case yet, but it must be
                        // investigated.
                        //
                        
                        //bKeepAwake = FALSE;
                    }
                }
            }

            break;
        }

        break;
    }
    
    if (PowerMgmtMode->dot11PowerMode == dot11_power_mode_powersave)
    {
        if (!bKeepAwake)
        {
            //
            // Eventually when the interrupt handling is completed, sleep. This may
            // get overwritten if we have more packets in the queue and the new
            // packet tells us not to go to sleep
            //
            pNic->ManagementInfo.bSleepOnInterruptComplete = TRUE;
        }
    }
}

PMP_RX_FRAGMENT
Hw11GetMpFragment(
    IN  PNIC_RX_FRAGMENT pNicFragment
    )
{
    MPVERIFY(pNicFragment);

    return pNicFragment->MpFragment;
}

USHORT
Hw11GetFragmentDataSize(
    IN  PNIC_RX_FRAGMENT pNicFragment
    )
{
    return pNicFragment->DataSize; 
}

USHORT
Hw11GetFragmentDataOffset(
    IN  PNIC_RX_FRAGMENT pNicFragment
    )
{
    return pNicFragment->DataOffset;
}

BOOLEAN
Hw11IsFragmentEncrypted(
    IN  PNIC_RX_FRAGMENT pNicFragment
    )
{
    return pNicFragment->Encrypted; 
}

BOOLEAN
Hw11GetFragmentChannel(
    IN  PNIC_RX_FRAGMENT pNicFragment
    )
{
    return pNicFragment->Channel; 
}

PVOID
Hw11GetVirtualAddress(
    IN  PNIC_RX_FRAGMENT pNicFragment
    )
{
    return (PVOID)pNicFragment->RxBuffer;
}

PVOID
Hw11GetFragmentDataStart(
    IN  PNIC_RX_FRAGMENT pNicFragment
    )
{
    return (PVOID)Add2Ptr(Hw11GetVirtualAddress(pNicFragment), Hw11GetFragmentDataOffset(pNicFragment));
}

// Called for Data and Management packets on 
BOOLEAN
HwIsFragmentInDuplicateTable(
    IN  PNIC                            pNic,
    IN  PUCHAR                          pPacketBuffer
    )
{
    UCHAR                               Index;
    PMP_DOT11_MGMT_DATA_MAC_HEADER      pPacketHeader = (PMP_DOT11_MGMT_DATA_MAC_HEADER)pPacketBuffer;
    UCHAR                               StartIndex, EndIndex;

    //
    // For duplicate detection, we compare the <Address 2, sequence-number, fragment-number> tuple to
    // the last received value. If all match, this is a retransmitted packet that we have already
    // receive indicated and would drop
    //
    if (HwIsMulticast(pPacketBuffer))
    {
        // We dont cache broadcast/multicast packet information
        return FALSE;   
    }

    //
    // A bunch of probe responses come in during scans, etc. This could cause us
    // to indicate up retry data packets. We handle this by separating cached entries for data
    // packets from other packet types
    //
    if (pPacketHeader->FrameControl.Type == DOT11_FRAME_TYPE_DATA)
    {
        StartIndex = 0;
        EndIndex = DUPLICATE_DETECTION_CACHE_LENGTH;
    }
    else
    {
        StartIndex = DUPLICATE_DETECTION_CACHE_LENGTH;
        EndIndex = 2 * DUPLICATE_DETECTION_CACHE_LENGTH;
    }
    

    //
    // The duplicate's cache is indexed using addresses
    //
    for (Index = StartIndex; Index < EndIndex; Index++)
    {
        if (MP_COMPARE_MAC_ADDRESS(pNic->RxInfo.DupePacketCache[Index].Address2, pPacketHeader->Address2))
        {
            if (pPacketHeader->FrameControl.Retry)
            {
                //
                // This is a retry if same sequence control
                //
                if (pNic->RxInfo.DupePacketCache[Index].SequenceControl == pPacketHeader->SequenceControl.usValue)
                {
                    return TRUE;
                }
            }

            //
            // Save latest sequence number
            //
            pNic->RxInfo.DupePacketCache[Index].SequenceControl = pPacketHeader->SequenceControl.usValue;
            return FALSE;
        }
    }

    //
    // Store the tuple information from this packet
    //

    //
    // This address is not cached. We just add it to the next index in the cache
    //
    if (pPacketHeader->FrameControl.Type == DOT11_FRAME_TYPE_DATA)
    {
        Index = ((pNic->RxInfo.NextDupeCacheIndexData + 1) % DUPLICATE_DETECTION_CACHE_LENGTH);
        pNic->RxInfo.NextDupeCacheIndexData = Index;
    }
    else
    {
        Index = ((pNic->RxInfo.NextDupeCacheIndexOther + 1) % DUPLICATE_DETECTION_CACHE_LENGTH)
                    + DUPLICATE_DETECTION_CACHE_LENGTH;
        pNic->RxInfo.NextDupeCacheIndexOther = Index;
    }
    
    NdisMoveMemory(pNic->RxInfo.DupePacketCache[Index].Address2, 
        pPacketHeader->Address2, 
        sizeof(DOT11_MAC_ADDRESS)
        );
    pNic->RxInfo.DupePacketCache[Index].SequenceControl = pPacketHeader->SequenceControl.usValue;

    return FALSE;
}

// Returns TRUE if this fragment is duplicate and should be dropped. FALSE otherwise
BOOLEAN
HwFragmentIsDuplicate(
    IN  PNIC                            pNic,
    IN  PNIC_RX_FRAGMENT                pNicFragment
    )
{
    PUCHAR                              pPacketBuffer = Add2Ptr(pNicFragment->RxBuffer, pNicFragment->DataOffset);
    PDOT11_MAC_HEADER                   pPacketHeader = (PDOT11_MAC_HEADER)pPacketBuffer;

    //
    // Reject packets which are not correct length
    //
    switch(pPacketHeader->FrameControl.Type)
    {
    case DOT11_FRAME_TYPE_MANAGEMENT:
    case DOT11_FRAME_TYPE_DATA:
        if (pNicFragment->DataSize < sizeof(MP_DOT11_MGMT_DATA_MAC_HEADER))
            return TRUE;    // Drop the packet

        //
        // Additional packet filtering - duplication detection
        //
        if (HwIsFragmentInDuplicateTable(pNic, pPacketBuffer))
        {
            PDOT11_PHY_FRAME_STATISTICS pPhyStats = &pNic->StatisticsInfo.PhyCounters[Hw11QueryOperatingPhyId(pNic)];
            pPhyStats->ullFrameDuplicateCount++;    // Duplicate
        
            return TRUE;    // Drop the packet
        }

        break;
        
    case DOT11_FRAME_TYPE_CONTROL:    
        break;
        
    default:
        //
        // Reserved packet are filtered out
        //
        return TRUE;    // Drop the packet
    }

    // Not duplicate
    return FALSE;
}

NDIS_STATUS
Hw11PacketReceived(
    IN  PNIC                            pNic,
    IN  PNIC_RX_FRAGMENT                pNicFragment,
    IN  PMP_RX_FRAGMENT                 pMpFragment
    )
{
    PUCHAR      pktbuf = Add2Ptr(pNicFragment->RxBuffer, pNicFragment->DataOffset);
    UCHAR       type = (pktbuf[0] & 0x0f) >> 2;
    UCHAR       subtype = (pktbuf[0] & 0xf0) >> 4;
    ULONGLONG   timestamp;

    UNREFERENCED_PARAMETER(pMpFragment);    
    
    //
    // During a scan operation, for beacon and probe response frames, check its timestamp. 
    // If it's not out-dated, save the channel number at which it was received. 
    // Otherwise, drop the frame.
    //

    if (pNic->ManagementInfo.bScanInProgress &&
        type == DOT11_FRAME_TYPE_MANAGEMENT &&
        (subtype == DOT11_MGMT_SUBTYPE_BEACON || subtype == DOT11_MGMT_SUBTYPE_PROBE_RESPONSE))
    {
        timestamp = ((ULONGLONG)NdisGetPhysicalAddressLow(pNicFragment->RxDesc.BufferAddress)) |
                    (((ULONGLONG)NdisGetPhysicalAddressHigh(pNicFragment->RxDesc.BufferAddress)) << 32);

        if (timestamp < pNic->ManagementInfo.ScanChannelSwitchTime)
            return NDIS_STATUS_NOT_ACCEPTED;

        pNicFragment->Channel = pNic->ManagementInfo.ScanCurrentChannel;
    }

    //
    // Check if we need to send ps-poll (probe is handled 
    // in function HwHandleTimingCriticalPacket() )
    //
    HwResponseToPacket(pNic, pNicFragment);

    //
    // Do any other processing that we may need
    //
    return pNic->RxInfo.ReceiveProcessingFunction(pNic, pNicFragment);
}

// Default, we dont need any special processing
NDIS_STATUS
HwProcessReceiveSTAMode(
    IN  PNIC pNic,
    IN  PNIC_RX_FRAGMENT pNicFragment
    )
{
    UNREFERENCED_PARAMETER(pNic);
    UNREFERENCED_PARAMETER(pNicFragment);

    return NDIS_STATUS_SUCCESS;
}

NDIS_STATUS
HwProcessReceiveSTAModeWaitForJoin(
	IN PNIC		        pNic,
	IN PNIC_RX_FRAGMENT pNicFragment
	)
{
	PUCHAR	    pktbuf = Add2Ptr(pNicFragment->RxBuffer, pNicFragment->DataOffset);
	UCHAR	    type=(pktbuf[0]  & 0x0f)>>2, tmpMSR;
	UCHAR       subtype=(pktbuf[0]  & 0xf0)>>4;
	BOOLEAN     Canceled;

    if (type == DOT11_FRAME_TYPE_MANAGEMENT     &&
         subtype ==  DOT11_MGMT_SUBTYPE_BEACON    &&
         MP_COMPARE_MAC_ADDRESS(((PDOT11_MGMT_HEADER)pktbuf)->SA, pNic->ManagementInfo.BssId) &&
         HW_STOP_WAITING_FOR_JOIN(pNic) == TRUE)
    {
        //
        // We have received the beacon that synchronises us with the BSS.
        // We will complete the pending Join/Start request and swap filter
        // handler to a function that does not make this unecessary check
        // We don't care whether the Timer got cancelled or not. The macro
        // HW_STOP_WAITING_FOR_JOIN synchronizes us with the cancel operation
        //
        NdisMCancelTimer(&pNic->ManagementInfo.Timer_JoinTimeout, &Canceled);
        
    	//
    	// Set the Associated OK with link in hardware
    	//
        ReadPortUchar(pNic, MSR, &tmpMSR);
        tmpMSR |= MSR_mAssoc;
        WritePortUchar( pNic, MSR, tmpMSR);
        
        //
        // Set the filtering function to the one optimized for STA mode
        //
        
        pNic->RxInfo.ReceiveProcessingFunction =  HwProcessReceiveSTAMode;
        Sta11JoinCompleteInfra(pNic->pStation, NDIS_STATUS_SUCCESS);
        MpTrace(COMP_RECV, DBG_NORMAL, ("Received beacon that sync us with the BSS\n"));
    }

    return NDIS_STATUS_SUCCESS;
}

NDIS_STATUS
HwProcessReceiveAdHocSTAModeWaitForJoin(
	IN PNIC		        pNic,
	IN PNIC_RX_FRAGMENT pNicFragment
	)
{	//3 Return false if this packet should be dropped
	PUCHAR	    pktbuf = Add2Ptr(pNicFragment->RxBuffer, pNicFragment->DataOffset);
	UCHAR	    type=(pktbuf[0]  & 0x0f)>>2, tmpMSR;
	UCHAR       subtype=(pktbuf[0]  & 0xf0)>>4;

    if (type == DOT11_FRAME_TYPE_MANAGEMENT     &&
         subtype ==  DOT11_MGMT_SUBTYPE_BEACON    &&
         MP_COMPARE_MAC_ADDRESS(((PDOT11_MGMT_HEADER)pktbuf)->BSSID, pNic->ManagementInfo.BssId) &&
         HW_STOP_WAITING_FOR_JOIN(pNic) == TRUE)
    {   
    	//
    	// Set the Associated OK with link in hardware
    	//
        ReadPortUchar(pNic, MSR, &tmpMSR);
        tmpMSR |= MSR_mAssoc;
        WritePortUchar( pNic, MSR, tmpMSR);
        
        //
        // Set the filtering function to the one optimized for STA mode
        //
        pNic->RxInfo.ReceiveProcessingFunction =  HwProcessReceiveSTAMode;
        
        Sta11JoinCompleteAdHoc(pNic->pStation, NDIS_STATUS_SUCCESS);
        MpTrace(COMP_RECV, DBG_NORMAL, ("Received beacon that sync us with the BSS\n"));
    }

    return NDIS_STATUS_SUCCESS;
}

NDIS_STATUS
Hw11SecurityCheck(
    IN PNIC                 pNic,
    IN PNET_BUFFER          NetBuffer,
    IN PNIC_RX_FRAGMENT    *ppNicFragment,
    IN ULONG                FragmentCount
    )
{
    PNIC_RX_FRAGMENT    pNicFragment;
    PNICKEY             pNicKey;
    UCHAR               ReceivedMIC[8];
    UCHAR               CalculatedMIC[8];
    NDIS_STATUS         ndisStatus;
    PMDL                mdl;
    ULONG               length;
    ULONG               offset;
    ULONG               index;
    PDOT11_PHY_FRAME_STATISTICS pPhyStats = &pNic->StatisticsInfo.PhyCounters[Hw11QueryOperatingPhyId(pNic)];

    UNREFERENCED_PARAMETER(pNic);

    //
    // This function does the MIC failure checking and replay counter checking.
    // If either one is done by hardware, its respective portion can be skipped.
    //

    //
    // Get the key that decrypted this MSDU. If we did not decrypted this MSDU, as
    // indicated by a NULL key, simply return success.
    //
    ASSERT(FragmentCount >= 1);
    pNicFragment = ppNicFragment[0];
    pNicKey = pNicFragment->NicKey;
    if (!pNicKey)
    {
        if (pNicFragment->Unicast)
        {
            pNic->StatisticsInfo.UcastCounters.ullReceivedFrameCount++;
        }
        else
        {
            pNic->StatisticsInfo.McastCounters.ullReceivedFrameCount++;
        }
        pPhyStats->ullReceivedFrameCount++;        
        return NDIS_STATUS_SUCCESS;
    }

    if (pNicKey->AlgoId == DOT11_CIPHER_ALGO_TKIP)
    {
        //
        // If the MSDU was decrypted by TKIP, check MIC and replay counter.
        // First, get the MIC field. Note that MIC could span across two MDLs.
        // All MDLs on the NET_BUFFER must have been mapped to some virtual addresses.
        //

        mdl = NET_BUFFER_CURRENT_MDL(NetBuffer);
        length = NET_BUFFER_DATA_LENGTH(NetBuffer);
        offset = NET_BUFFER_CURRENT_MDL_OFFSET(NetBuffer);

        ASSERT(length > sizeof(ReceivedMIC));
        ASSERT(mdl->ByteCount >= offset);

        //
        // Find the MDL that that contains (at least the first byte of) MIC.
        //

        while (length - (mdl->ByteCount - offset) >= sizeof(ReceivedMIC))
        {
            length -= mdl->ByteCount - offset;
            mdl = mdl->Next;
            ASSERT(mdl);
            offset = 0;
        }

        //
        // Found that MDL. Calculate the offset of MIC in the MDL. Copy MIC to our buffer.
        //
        offset += length - sizeof(ReceivedMIC);
        for (index = 0; index < sizeof(ReceivedMIC); index++)
        {
            ReceivedMIC[index] = *((PUCHAR)Add2Ptr(mdl->MappedSystemVa, offset));
            offset++;

            if (offset >= mdl->ByteCount)
            {
                mdl = mdl->Next;
                offset = 0;
            }
        }

        //
        // Shorten the actual data by size of MIC. Then calculate the MIC based on
        // receiving data and Rx MIC key.
        //
        NET_BUFFER_DATA_LENGTH(NetBuffer) -= sizeof(ReceivedMIC);
        ndisStatus = HwCalculateMIC(NetBuffer, 0, pNicKey->RxMICKey, CalculatedMIC);
        ASSERT(ndisStatus == NDIS_STATUS_SUCCESS);

        //
        // Compare the received MIC vs. calculated MIC. If there is mismatch, indicated
        // MIC failure.
        //
        if (NdisEqualMemory(ReceivedMIC, CalculatedMIC, sizeof(ReceivedMIC)) != 1)
        {
            mdl = NET_BUFFER_CURRENT_MDL(NetBuffer);
            offset = NET_BUFFER_CURRENT_MDL_OFFSET(NetBuffer);
            index = (ULONG)(pNicKey - pNic->ManagementInfo.KeyTable);       // key index

            Sta11IndicateMICFailure(pNic->pStation, 
                                    Add2Ptr(mdl->MappedSystemVa, offset),
                                    (index < DOT11_MAX_NUM_DEFAULT_KEY) ?  index : 0,
                                    (BOOLEAN)(index < DOT11_MAX_NUM_DEFAULT_KEY));

            MpTrace(COMP_RECV, DBG_SERIOUS, ("MIC failure detected!\n"));

            if (pNicFragment->Unicast)
            {
                pNic->StatisticsInfo.UcastCounters.ullTKIPLocalMICFailures++;
                pNic->StatisticsInfo.UcastCounters.ullDecryptFailureCount++;
            }
            else
            {
                pNic->StatisticsInfo.McastCounters.ullTKIPLocalMICFailures++;
                pNic->StatisticsInfo.McastCounters.ullDecryptFailureCount++;
            }
            return NDIS_STATUS_NOT_ACCEPTED;
        }

        //
        // Replay counter checking for TKIP. This is done after MIC verification. 
        // Two things are checked:
        //   1. The frame number of the first fragment in a MSDU must be greater than
        //      the replay counter for the key that decrypted the MSDU.
        //   2. The frame number of the all fragments in a MSDU must be monotonically
        //      increased, but not necessarily sequential (unlike in CCMP).
        //
        if (pNicFragment->FrameNumber <= pNicKey->ReplayCounter)
        {
            MpTrace(COMP_RECV, DBG_SERIOUS, ("Replay counter failed!\n"));
            if (pNicFragment->Unicast)
            {
                pNic->StatisticsInfo.UcastCounters.ullTKIPReplays++;
                pNic->StatisticsInfo.UcastCounters.ullDecryptFailureCount++;
            }
            else
            {
                pNic->StatisticsInfo.McastCounters.ullTKIPReplays++;
                pNic->StatisticsInfo.McastCounters.ullDecryptFailureCount++;
            }
            return NDIS_STATUS_NOT_ACCEPTED;
        }

        for (index = 0; index < FragmentCount - 1; index++)
        {
            if (ppNicFragment[index]->FrameNumber >= ppNicFragment[index + 1]->FrameNumber)
            {
                MpTrace(COMP_RECV, DBG_SERIOUS, ("Replay counter failed!\n"));
                if (pNicFragment->Unicast)
                {
                    pNic->StatisticsInfo.UcastCounters.ullTKIPReplays++;
                    pNic->StatisticsInfo.UcastCounters.ullDecryptFailureCount++;
                }
                else
                {
                    pNic->StatisticsInfo.McastCounters.ullTKIPReplays++;
                    pNic->StatisticsInfo.McastCounters.ullDecryptFailureCount++;
                }
                return NDIS_STATUS_NOT_ACCEPTED;
            }
        }

        //
        // Passed replay counter check. Update the replay counter in the key to frame number of
        // the last fragment in the MSDU.
        //
        pNicKey->ReplayCounter = ppNicFragment[FragmentCount - 1]->FrameNumber;
    }
    else if (pNicKey->AlgoId == DOT11_CIPHER_ALGO_CCMP)
    {
        //
        // If the MSDU was decrypted by CCMP, check replay counter.
        // Two things are checked:
        //   1. The frame number of the first fragment in a MSDU must be greater than
        //      the replay counter for the key that decrypted the MSDU.
        //   2. The frame number of the all fragments in a MSDU must be sequential.
        //
        if (pNicFragment->FrameNumber <= pNicKey->ReplayCounter)
        {
            MpTrace(COMP_RECV, DBG_SERIOUS, ("Replay counter failed!\n"));
            if (pNicFragment->Unicast)
            {
                pNic->StatisticsInfo.UcastCounters.ullCCMPReplays++;
                pNic->StatisticsInfo.UcastCounters.ullDecryptFailureCount++;
            }
            else
            {
                pNic->StatisticsInfo.McastCounters.ullCCMPReplays++;
                pNic->StatisticsInfo.McastCounters.ullDecryptFailureCount++;
            }
            return NDIS_STATUS_NOT_ACCEPTED;
        }

        for (index = 0; index < FragmentCount - 1; index++)
        {
            if (ppNicFragment[index]->FrameNumber + 1 != ppNicFragment[index + 1]->FrameNumber)
            {
                MpTrace(COMP_RECV, DBG_SERIOUS, ("Replay counter failed!\n"));
                if (pNicFragment->Unicast)
                {
                    pNic->StatisticsInfo.UcastCounters.ullCCMPReplays++;
                    pNic->StatisticsInfo.UcastCounters.ullDecryptFailureCount++;
                }
                else
                {
                    pNic->StatisticsInfo.McastCounters.ullCCMPReplays++;
                    pNic->StatisticsInfo.McastCounters.ullDecryptFailureCount++;
                }
                return NDIS_STATUS_NOT_ACCEPTED;
            }
        }

        //
        // Passed replay counter check. Update the replay counter in the key to frame number of
        // the last fragment in the MSDU.
        //
        pNicKey->ReplayCounter = ppNicFragment[FragmentCount - 1]->FrameNumber;
    }

    if (pNicFragment->Unicast)
    {
        pNic->StatisticsInfo.UcastCounters.ullDecryptSuccessCount++;
        pNic->StatisticsInfo.UcastCounters.ullReceivedFrameCount++;
    }
    else
    {
        pNic->StatisticsInfo.McastCounters.ullDecryptSuccessCount++;
        pNic->StatisticsInfo.McastCounters.ullReceivedFrameCount++;
    }
    pPhyStats->ullReceivedFrameCount++;        

    return NDIS_STATUS_SUCCESS;
}


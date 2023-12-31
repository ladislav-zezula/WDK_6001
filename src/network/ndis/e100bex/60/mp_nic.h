/*++

Copyright (c) 1999  Microsoft Corporation

Module Name:
    mp_nic.h

Abstract:
    Function prototypes for mp_nic.c, mp_init.c and mp_req.c

Revision History:

Notes:

--*/

#ifndef _MP_NIC_H
#define _MP_NIC_H

#define NIC_INTERRUPT_DISABLED(_adapter) \
   (_adapter->CSRAddress->ScbCommandHigh & SCB_INT_MASK)
   
#define NIC_INTERRUPT_ACTIVE(_adapter) \
      (((_adapter->CSRAddress->ScbStatus & SCB_ALL_INTERRUPT_BITS) != SCB_ALL_INTERRUPT_BITS) \
       && (_adapter->CSRAddress->ScbStatus & SCB_ACK_MASK))

#define NIC_ACK_INTERRUPT(_adapter, _value) { \
   _value = _adapter->CSRAddress->ScbStatus & SCB_ACK_MASK; \
   _adapter->CSRAddress->ScbStatus = _value; }        

#define NIC_IS_RECV_READY(_adapter) \
    ((_adapter->CSRAddress->ScbStatus & SCB_RUS_MASK) == SCB_RUS_READY)
    
__inline VOID NICDisableInterrupt(
    IN PMP_ADAPTER Adapter)
{
   Adapter->CSRAddress->ScbCommandHigh = SCB_INT_MASK;
}

__inline VOID NICEnableInterrupt(
    IN PMP_ADAPTER Adapter)
{
    Adapter->CSRAddress->ScbCommandHigh = 0;
}
    

//
//  MP_NIC.C
//                    
NDIS_STATUS MiniportSendNetBufferList(
    IN  PMP_ADAPTER         Adapter,
    IN  PNET_BUFFER_LIST    NetBufferList,
    IN  BOOLEAN             bFromQueue);
   
NDIS_STATUS NICSendNetBuffer(
    IN  PMP_ADAPTER     Adapter,
    IN  PMP_TCB         pMpTcb,
    IN  PMP_FRAG_LIST   pFragList);
                                
ULONG MpCopyPacket(
    IN  PMDL            CurrMdl,
    IN  PMP_TXBUF       pMpTxbuf); 

ULONG MpCopyNetBuffer(
    IN  PNET_BUFFER     NetBuffer,
    IN  PMP_TXBUF       pMpTxbuf);

    
NDIS_STATUS NICStartSend(
    IN  PMP_ADAPTER     Adapter,
    IN  PMP_TCB         pMpTcb);
   
NDIS_STATUS MpHandleSendInterrupt(
    IN  PMP_ADAPTER     Adapter);
                   
VOID MpHandleRecvInterrupt(
    IN  PMP_ADAPTER     Adapter);
   
VOID NICReturnRFD(
    IN  PMP_ADAPTER     Adapter,
    IN  PMP_RFD         pMpRfd);
   
NDIS_STATUS NICStartRecv(
    IN  PMP_ADAPTER     Adapter);

VOID MpFreeQueuedSendNetBufferLists(
    IN  PMP_ADAPTER     Adapter);

void MpFreeBusySendNetBufferLists(
    IN  PMP_ADAPTER     Adapter);
                            
void NICResetRecv(
    IN  PMP_ADAPTER     Adapter);

VOID MpLinkDetectionDpc(
    IN  PVOID       SystemSpecific1,
    IN  PVOID       FunctionContext,
    IN  PVOID       SystemSpecific2, 
    IN  PVOID       SystemSpecific3);

VOID
MPIndicateLinkState(
    IN  PMP_ADAPTER     Adapter
    );

//
// MP_INIT.C
//                  
      
NDIS_STATUS 
MpFindAdapter(
    IN  PMP_ADAPTER             Adapter,
    IN  PNDIS_RESOURCE_LIST     resList
    );

NDIS_STATUS NICReadAdapterInfo(
    IN  PMP_ADAPTER     Adapter);
              
NDIS_STATUS MpAllocAdapterBlock(
    OUT PMP_ADAPTER    *pAdapter,
    IN  NDIS_HANDLE     MiniportAdapterHandle
    );
    
void MpFreeAdapter(
    IN  PMP_ADAPTER     Adapter);
                                         
NDIS_STATUS NICReadRegParameters(
    IN  PMP_ADAPTER     Adapter);
                                              
NDIS_STATUS NICAllocAdapterMemory(
    IN  PMP_ADAPTER     Adapter);
   
VOID NICInitSend(
    IN  PMP_ADAPTER     Adapter);

NDIS_STATUS NICInitRecv(
    IN  PMP_ADAPTER     Adapter);

ULONG NICAllocRfd(
    IN  PMP_ADAPTER     Adapter, 
    IN  PMP_RFD         pMpRfd);
    
VOID NICFreeRfd(
    IN  PMP_ADAPTER     Adapter, 
    IN  PMP_RFD         pMpRfd,
    IN  BOOLEAN         DispatchLevel);
   
NDIS_STATUS NICSelfTest(
    IN  PMP_ADAPTER     Adapter);

NDIS_STATUS NICInitializeAdapter(
    IN  PMP_ADAPTER     Adapter);

VOID HwSoftwareReset(
    IN  PMP_ADAPTER     Adapter);

NDIS_STATUS HwConfigure(
    IN  PMP_ADAPTER     Adapter);

NDIS_STATUS HwSetupIAAddress(
    IN  PMP_ADAPTER     Adapter);

NDIS_STATUS HwClearAllCounters(
    IN  PMP_ADAPTER     Adapter);

//
// MP_REQ.C
//                  
    
NDIS_STATUS NICGetStatsCounters(
    IN  PMP_ADAPTER     Adapter, 
    IN  NDIS_OID        Oid,
    OUT PULONG64        pCounter);
    
NDIS_STATUS NICSetPacketFilter(
    IN  PMP_ADAPTER     Adapter,
    IN  ULONG           PacketFilter);

NDIS_STATUS NICSetMulticastList(
    IN  PMP_ADAPTER     Adapter);
    
ULONG NICGetMediaConnectStatus(
    IN  PMP_ADAPTER     Adapter);
    
VOID
MPFillPoMgmtCaps (
    IN PMP_ADAPTER Adapter, 
    IN OUT PNDIS_PNP_CAPABILITIES   pPower_Management_Capabilities, 
    IN OUT  PNDIS_STATUS pStatus,
    IN OUT  PULONG pulInfoLen
    );

                    
#endif  // MP_NIC_H


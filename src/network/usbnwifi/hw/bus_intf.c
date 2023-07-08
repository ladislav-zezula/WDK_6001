/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    Hw_bus_interface.c

Abstract:
    
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created

Notes:

--*/

#include "hw_pcomp.h"

#pragma warning(disable:4200)  // nameless struct/union
#pragma warning(disable:4201)  // nameless struct/union
#pragma warning(disable:4214)  // bit field types other than int

#include "usb_main.h"
#include "bus_intf.h"
#include "8187_gen.h"

#include "usb_xmit.h"
#include "usb_recv.h"


#pragma warning(default:4200)
#pragma warning(default:4201)
#pragma warning(default:4214)


NDIS_STATUS
HwInitializeBus(
    IN PNIC Nic
    )
{
    NDIS_STATUS ndisStatus;

    ndisStatus =  HwUSBSpecificInit(Nic);
    //InitializeVariables here
    //tod do i need this here 
    //InitializeVariables(Nic);
    return ndisStatus ;
}

VOID
HwDeInitBus(
    IN PNIC Nic
    )
{
    HwUsbDeInit(Nic);
}

NDIS_STATUS
HwReadAdapterInfo(
    IN PNIC Nic
    )
{
    NDIS_STATUS  ndisStatus;
    
    ndisStatus = ReadNicInfo8187(Nic); 
    return ndisStatus;
}



NDIS_STATUS
HwInitializeAdapter(
    IN PNIC Nic
    )
{
    //
    //channel will come from reg stetings   . Initialize to channel 1
    //
    return InitializeNic8187(Nic, 1);
}

NDIS_STATUS
HwBusAllocateRecvResources(
    IN PNIC Nic
    )

{
    return HwUsbAllocateRecvResources(Nic);
}

NDIS_STATUS
HwBusAllocateXmitResources(
    IN PNIC Nic ,
    IN  ULONG NumTxd
    )

{
    return HwUsbAllocateXmitResources(Nic, NumTxd);
}



VOID
HwBusFreeXmitResources(
    IN PNIC Nic
    )
{
    HwUsbFreeXmitMemory(Nic);
    return ;

}


NDIS_STATUS
HwBusFreeRecvResources(
    IN PNIC Nic
    )
{
    return HwUsbFreeRecvResources(Nic);
}

NDIS_STATUS
HwBusFindAdapterAndResources(
    IN PNIC Nic
    )
{
    UNREFERENCED_PARAMETER(Nic);
    
    return NDIS_STATUS_SUCCESS;
    //no op for usb
}

NDIS_STATUS
HwBusStartDevice(
                IN PNIC Nic
                 )
{
    NDIS_STATUS ndisStatus;
    
    ndisStatus = HwUsbRecvStart(Nic);
    if (ndisStatus != NDIS_STATUS_SUCCESS) {
        MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Failed to start Recv IoTarget.\n"));
    }
    ndisStatus = HwUsbXmitStart(Nic);
    if (ndisStatus != NDIS_STATUS_SUCCESS) {
        MpTrace(COMP_INIT_PNP, DBG_SERIOUS, ("Failed to  start Transmit IoTarget.\n"));
    }
    return ndisStatus;
}

NDIS_STATUS
HwBusSendPacketAsync(
    IN PNIC Nic,
    IN UCHAR            QueueType,
    IN ULONG            BufferLength,
    IN PVOID            Buffer,
    IN PNIC_TX_MSDU     NicTxd 
    )
{
    NTSTATUS ntStatus;
    NDIS_STATUS ndisStatus;

    ntStatus =  HwUsbSendPacketAsync(Nic,  QueueType, BufferLength, Buffer, NicTxd);    

    NT_STATUS_TO_NDIS_STATUS(ntStatus, &ndisStatus);
    return    ndisStatus;    
}

VOID
HwBusStopNotification(
    IN PNIC Nic
    )
{
    HwUsbStopAllPipes(Nic);
}


VOID
HwBusFreeRecvFragment(
                IN  PNIC Nic,
                IN  PNIC_RX_FRAGMENT NicFragment
                ) 
{
    HwUsbFreeRecvFragment(Nic,NicFragment );
}




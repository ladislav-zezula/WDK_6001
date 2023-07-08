
NDIS_STATUS
HwInitializeBus(
    IN PNIC Nic
    )  ;

VOID
HwDeInitBus(
    IN PNIC Nic
    );

NDIS_STATUS
HwReadAdapterInfo(
    IN PNIC Nic
    ) ;

NDIS_STATUS
HwInitializeAdapter(
    IN PNIC Nic
    );

NDIS_STATUS
ReadNicInfo8187(
    IN PNIC         Nic
    );

VOID
InitializeVariables8187(
    IN PNIC         Nic
    );
 
NDIS_STATUS
HwBusStartDevice(
                IN PNIC Nic
                 );


NDIS_STATUS
HwBusFreeRecvResources(
    IN PNIC Nic
    );


NDIS_STATUS
HwBusAllocateRecvResources(
    IN PNIC Nic
    );

NDIS_STATUS
HwBusAllocateXmitResources(
    IN PNIC Nic ,
    IN  ULONG NumTxd
    )  ;

VOID
HwBusFreeXmitResources(
    IN PNIC Nic
    ) ;

NDIS_STATUS
HwBusFindAdapterAndResources(
    IN PNIC Nic
    ) ;


NDIS_STATUS
HwBusSendPacketAsync(
    IN PNIC             Nic,
    IN UCHAR            QueueType,
    IN ULONG            BufferLength,
    IN PVOID            Buffer,
    IN PNIC_TX_MSDU     NicTxd 
    ) ;

VOID
HwBusStopNotification(
    IN PNIC Nic
    );

VOID
HwBusFreeRecvFragment(
                IN  PNIC Nic,
                IN  PNIC_RX_FRAGMENT NicFragment
                ) ;



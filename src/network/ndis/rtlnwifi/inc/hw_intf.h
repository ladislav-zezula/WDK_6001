/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    hw_intf.h

Abstract:
    Interface functions into Hw layer
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created
    01-15-2006    Renamed hw_interface.h to hw_inf.h
    06-10-2006    Renamed:
                    Hw11ResetStart to Hw11ResetStep2
                    Hw11Reset to Hw11ResetStep3
                    Hw11ResetEnd to Hw11ResetStep4

Notes:

--*/

#ifndef _HW_INTERFACE_H

#define _HW_INTERFACE_H


//
// Some definitions that will be used by the miniport portion
// Many of them are static values reflecting various capabilities
// of the hardware and should be set appropriately
//

/**
 * Please enter the name of e-mail of the person who is responsible for debugging
 * issues in this driver. This variable is used only for debug versions of the driver
 * and helps testers out there quickly locate the troubleshooter.
 */
#define HW11_MINIPORT_OWNER_EMAIL   HW_OWNER_EMAIL

#define HW11_MAJOR_DRIVER_VERSION   HW_MAJOR_DRIVER_VERSION
#define HW11_MINOR_DRIVER_VERSION   HW_MINOR_DRIVER_VERSION

/** The minimum channel number supported by the hardware for DSSS PHY */
#define HW11_MIN_CHANNEL_NUMBER     HW_MIN_CHANNEL_NUMBER

/** The maximum channel number supported by the hardware for DSSS PHY */
#define HW11_MAX_CHANNEL_NUMBER     HW_MAX_CHANNEL_NUMBER

/** The minimum frequency supported by the hardware for OFDM PHY */
#define HW11_MIN_OFDM_FREQ          HW_MIN_OFDM_FREQ

/** The maximum frequency supported by the hardware for OFDM PHY */
#define HW11_MAX_OFDM_FREQ          HW_MAX_OFDM_FREQ

/** The default channel that the NIC will initialize itself with in b/g mode*/
#define HW11_DEFAULT_CHANNEL        HW_DEFAULT_CHANNEL

/** The default channel that the NIC will initialize itself with in "a" mode*/
#define HW11_DEFAULT_CHANNEL_A      HW_DEFAULT_CHANNEL_A

/** 
 * Specifies the type of interrupt that the NIC generates as one of the following values: 
 * NdisInterruptLatched          Interrupts are triggered by a transition from low to high on the interrupt line.
 * NdisInterruptLevelSensitive   Interrupts are active as long as the interrupt line is asserted. 
 */
#define HW11_INTERRUPT_MODE         HW_INTERRUPT_MODE

/** The interrupt for this miniport is sharable with other devices */
#define HW11_INTERRUPT_SHARABLE     HW_INTERRUPT_SHARABLE

/** The time interval in which NDIS should call MiniportCheckForHang handler. See NdisMSetAttributesEx for details */
#define HW11_CHECK_FOR_HANG_TIME_IN_SECONDS   HW_CHECK_FOR_HANG_TIME_IN_SECONDS

/** Specifies the miniport attributes that are passed to NDIS */
#define HW11_NDIS_MINIPORT_ATTRIBUTES   HW_MINIPORT_NDIS_ATTRIBUTES    

/** Specifies the I/O bus interface type of the NIC, which usually is the type of I/O bus on which the NIC is connected */
#define HW11_BUS_INTERFACE_TYPE         HW_BUS_INTERFACE_TYPE

/** the manufacturer of the device. This must be a value allocated by the PCI SIG */
#define HW11_PCI_VENDOR_ID              HW_PCI_VENDOR_ID

/** Identifies the particular device. This value is assigned by the manufacturer */
#define HW11_PCI_8180_DEVICE_ID         HW_PCI_8180_DEVICE_ID
#define HW11_PCI_8185_DEVICE_ID         HW_PCI_8185_DEVICE_ID

/** Set to true if the miniport requires Address reset by NDIS on a reset */
#define HW11_REQUIRES_ADDRESS_RESET     HW_REQUIRES_ADDRESS_RESET

/** The link speed supported by this hardware */
#define HW11_LINK_SPEED                 HW_LINK_SPEED

/** Minimum number of Rx MSDUs that we can allocate or shrink to */
#define HW11_MIN_RX_MSDUS                   HW_MIN_RX_MSDUS
/** Maximum number of Rx MSDUs that we will ever allocate or grow to */
#define HW11_MAX_RX_MSDUS                   HW_MAX_RX_MSDUS
/** Default number of Rx MSDUs to start with */
#define HW11_DEF_RX_MSDUS                   HW_DEF_RX_MSDUS

#if (HW11_DEF_RX_MSDUS < HW11_MIN_RX_MSDUS)
    #error The default number of RX_MSDUs can never be less than the minimum
#endif
#if (HW11_DEF_RX_MSDUS > HW11_MAX_RX_MSDUS)
    #error The default number of RX_MSDUs can never be greater than the maximum
#endif


/** Minimum number of Tx MSDUs that need to be initialized with */
#define HW11_MIN_TX_MSDUS               HW_MIN_TX_MSDUS
/** Maximum number of Tx MSDUs that we can allocate */
#define HW11_MAX_TX_MSDUS               HW_MAX_TX_MSDUS
/** Default number of Tx MSDUs to allocate and initialize miniport with */
#define HW11_DEF_TX_MSDUS               HW_DEF_TX_MSDUS

#if (HW11_DEF_TX_MSDUS < HW11_MIN_TX_MSDUS)
    #error The default number of TX_MSDUs can never be less than the minimum
#endif
#if (HW11_DEF_TX_MSDUS > HW11_MAX_TX_MSDUS)
    #error The default number of TX_MSDUs can never be greater than the maximum
#endif

/**
 * This enumeration type lists all the possible error entries that can be placed
 * in the Event log by the miniport. Vendors should add any new error entries to this
 * enumeration type before using it. This will provide one consolidated place to check
 * for all error codes.
 */
typedef enum _HW11_ERROR_LOG_ENTRY{
    ERRLOG_READ_PCI_SLOT_FAILED = 101,
    ERRLOG_WRITE_PCI_SLOT_FAILED,
    ERRLOG_VENDOR_DEVICE_MISMATCH,
    ERRLOG_BUS_MASTER_DISABLED,
    ERRLOG_QUERY_ADAPTER_RESOURCES_FAILED,
    ERRLOG_NO_IO_RESOURCE,
    ERRLOG_NO_INTERRUPT_RESOURCE,
    ERRLOG_NO_MEMORY_RESOURCE,
    ERRLOG_OUT_OF_SG_RESOURCES,
    ERRLOG_REGISTER_INTERRUPT_FAILED,
    ERRLOG_REGISTER_IO_PORT_RANGE_FAILED,
    ERRLOG_MAP_IO_SPACE_FAILED,
    ERRLOG_REMOVE_MINIPORT
} HW11_ERROR_LOG_ENTRY;


/** Maximum number of on-NIC multicast address entries */
#define HW11_MAX_MCAST_LIST_SIZE    HW_MAX_MCAST_LIST_SIZE

/** The backfill size this miniport driver needs */
#define HW11_REQUIRED_BACKFILL_SIZE   HW_REQUIRED_BACKFILL_SIZE

/** Defines the maximum number of MAC Address States this miniport can maintain */
#define HW11_MAX_MAC_ADDRESS_STATES    HW_MAX_MAC_ADDRESS_STATES

//
// Forward declaration
//
typedef struct _ADAPTER         ADAPTER, *PADAPTER;
typedef struct _MP_TX_MSDU      MP_TX_MSDU, *PMP_TX_MSDU;
typedef struct _MP_RX_MSDU      MP_RX_MSDU, *PMP_RX_MSDU;
typedef struct _MP_RX_FRAGMENT  MP_RX_FRAGMENT, *PMP_RX_FRAGMENT ;


typedef struct _NIC_TX_MSDU     NIC_TX_MSDU, *PNIC_TX_MSDU;
typedef struct _NIC_RX_MSDU     NIC_RX_MSDU, *PNIC_RX_MSDU;
typedef struct _NIC_RX_FRAGMENT NIC_RX_FRAGMENT, *PNIC_RX_FRAGMENT;
typedef struct _NIC             NIC, *PNIC;
typedef struct _NICKEY          NICKEY, *PNICKEY;

typedef struct _STA_BSS_ENTRY   STA_BSS_ENTRY, *PSTA_BSS_ENTRY;
typedef struct _STATION         STATION, *PSTATION;

/**
 * This function is called from Miniport Initialize and NIC are
 * required to allocate resources needed for operation in this function.
 * If any error occurs, this function must add an Entry in the Event Log
 * using NdisWriteErrorLogEntry function.
 * 
 * \param MiniportAdapterHandle     The handle that can be passed to NDIS when
 *                                  calling NDIS API.
 * \param pNic                      The context for this NIC
 * \param pAdapter                  Pointer to the associated adapter context. This
 *                                  will be needed when calling Mp11 functions.
 * \param pStation                  Pointer to the associated station context. This
 *                                  will be needed when calling Sta11 functions.
 * \return NDIS_STATUS_SUCCESS on success, else the appropriate failure.
 * \sa Hw11FreeNic, Hw11InitializeNic
 */
NDIS_STATUS
Hw11AllocateNic(
    IN  NDIS_HANDLE     MiniportAdapterHandle,
    OUT PNIC*           ppNic,
    IN  PADAPTER        pAdapter,
    IN  PSTATION        pStation
    );

/**
 * This function is called when all the resources allocated for the operation of
 * the NIC have to be released. Typically, this function will be called when
 * Miniport is being halted.
 * 
 * \param pNic          The context for this NIC
 * \sa Hw11AllocateNic, Hw11InitializeNic
 */
VOID
Hw11FreeNic(
    IN PNIC         pNic
    );

/**
 * This function is called when MiniportInitialize is running. This function is called
 * immediately after Hw11AllocateNic returns successfully. Initialize all members of the
 * NIC data structure within this function. If an error occurs during the initialization
 * that will cause the MiniportInitialize to fail, please log an entry in the Event Log.
 * 
 * \param pNic          The context for this NIC
 * \return NDIS_STATUS_SUCCESS if all initializations occurs successfully, else failure
 * \sa Hw11AllocateNic, Hw11TerminateNic, Hw11FreeNic, Hw11StartNic
 */
NDIS_STATUS
Hw11InitializeNic(
    IN PNIC         pNic
    );

/**
 * This function is called to uninitialize any variables that were initialized during the
 * call to Hw11InitializeNic or some other function. This function will typically be called
 * when Miniport is being halted.
 * 
 * \param pNic          The context for this NIC
 * \sa Hw11InitializeNic
 */
VOID
Hw11TerminateNic(
    IN PNIC         pNic
);


/**
 * This API is called when all initialization have been done for the miniport, interrupts
 * are regsitered and we expect the NIC to resume operational behavior. Starting up
 * Send and receive units would be one example of operations to be executed here.
 * 
 * \param pNic      The context for this NIC
 * \return NDIS_STATUS_SUCCESS on success else appropriate failure
 * \sa Hw11InitializeNic, Hw11HaltNic
 */
NDIS_STATUS
Hw11StartNic(
    IN  PNIC        pNic
    );

/**
 * This function is called from MiniportHalt. The NIC should put the
 * hardware in a known state as MiniportHalt is usually followed by
 * a warm boot. If there is any cleanup other than allocations that 
 * need to be done, it can be handled here. Typically, we should expect
 * Hw11HaltNic to undo operations done by Hw11StartNic
 * 
 * \warning Please do not try to write to any ports if the Hw has been
 * surprise removed.
 *
 * This function is invoked at IRQL = DISPATCH
 * 
 * \param pNic      The context for this NIC
 * \sa Hw11StartNic, Hw11Shutdown, MiniportHalt from DDK
 */
VOID
Hw11HaltNic(
    PNIC        pNic
    );



/**
 * This routine looks for the adapter on the bus it shoud be present and goes through
 * its config space as well.
 */
NDIS_STATUS
Hw11FindAdapter(
    IN  PNIC                    pNic,
    OUT NDIS_ERROR_CODE*        ErrorCode,
    OUT PULONG                  ErrorValue
    );


/**
 * This function is called to notify Hw11 about resources that have been found for
 * this adapter. These resources are located using NdisMQueryAdapterResources API.
 * Hw11 should look at the resource type and keep information about it stored with
 * itself so that it can utilize these resources at a later time. Typical resources
 * used by adapters include Ports, Interrupt and memory.
 * 
 * \param pNic      The context for this NIC
 * \prarm pResource The resource that has been discovered
 * \return NDIS_STATUS_SUCCESS if the resource was good and utilized. Return 
 * NDIS_STATUS_NOT_ACCEPTED if the resource is not utilized. Otherwise appropriate
 * failure code.
 * \sa MpInitialize, Hw11InitializeNic, Hw11ParsePciConfiguration
 */
NDIS_STATUS
Hw11AddAdapterResource(
    IN PNIC    pNic,
    IN PCM_PARTIAL_RESOURCE_DESCRIPTOR  pResource
    );

/**
 * This function is called when MiniportInitialize is running. The NIC is supposed to
 * allocate and initialize all data it needs for a normal send operation. This preallocation
 * is important since we do not want allocations to be occuring during sends to avoid a
 * performace penalty. Any errors that occur during initialization must be placed in the
 * Event Log.
 * 
 * \param pNic      The context for this NIC
 * \param NumTxd    The number of TX_MSDU's that the NIC needs to allocate
 * \return NDIS_STATUS_SUCCESS if the allocation and initializations succeed, else 
 * appropriate failure code
 * \sa Hw11TerminateSend, MP_TX_MSDU
 */
NDIS_STATUS
Hw11InitializeSend(
    IN PNIC         pNic,
    IN ULONG        NumTxd
    );

/**
 * This function will uninitalize and release all resources that were previously allocated
 * for send operations. Typically, this function will be called when miniport is being halted.
 * 
 * \param pNic          The context for this NIC
 * \sa Hw11InitializeSend, MP_TX_MSDU
 */
VOID
Hw11TerminateSend(
    IN PNIC         pNic
    );

/**
 * 
 * 
 * \param pNic
 * \return 
 * \sa 
 */
VOID
Hw11CheckForSends(
    IN PNIC         pNic
    );
    
/**
 * This function should allocate and Initialize data that is needed for receiving packets.
 * This function is called while MiniportInitialize is running.
 *
 * When this function is done allocating resources (typically shared memory) for receiving
 * data, it should call Mp11InitializeReceiveEngine. This will allow the Mp portion of the
 * driver to make allocations and initialization for receiving packets. Following this
 * initialization, this function should call Mp11AssociateRxFragment for each NIC_RX_FRAGMENT that
 * has been allocated. This allows the Mp portion to create a static association between a
 * MP_RX_FRAGMENT and a NIC_RX_FRAGMENT. This association is vital for the receive process to work 
 * correctly.
 *
 * Any errors that occur during allocations and initializations must be recorded in the
 * event log.
 * 
 * \param pNic              The context for this NIC
 * \param TotalFragments    The number of fragments that this NIC should be allocating
 * \return NDIS_STATUS_SUCCESS on success, else the appropriate failure code
 * \sa Hw11TerminateReceive, MP_RX_FRAGMENT, Mp11InitializeReceiveEngine
 */
NDIS_STATUS
Hw11InitializeReceive(
    IN PNIC         pNic,
    IN ULONG        TotalFragments
    );

/**
 * This function is called to release all resources that were allocated for receiving
 * packets by the NIC. This function will typically be called when Miniport is being halted.
 * 
 * Before NIC releases all its resources, the NIC should call Mp11DisassociateRxFragment for
 * each frag that was previously associated, This gives the Mp portion a chance to clean
 * up associations between MP and NIC fragments. Once all associations are broken, this function
 * should call Mp11TerminateReceiveEngine to allow the Mp portion of the driver to clean 
 * up all the allocations made. After that is done, NIC can releases its own resources 
 * (typically NICFRAGMENT and allocated shared memory) safely.
 * 
 * \param pNic          The context for this NIC
 * \sa Hw11InitializeReceive, MP_RX_FRAGMENT
 */
VOID
Hw11TerminateReceive(
    IN PNIC         pNic
    );

/**
 * This function is called when the miniport driver starts to run low on
 * the available Receive Buffers for receiving packets. The hardware should
 * allocate NicFragment and call Mp11AssociateRxFragment so that the corresponding
 * MpFragment can be setup. As usual, the Hw11 function should add the frag into the
 * existing pool of fragments appropriately. This function would require shared
 * memory to be allocated via Mp11AllocateSharedMemoryAsync so it should return
 * NDIS_STATUS_PENDING when the allocation request pends.
 * 
 * \param pNic                      The context for the NIC
 * \param NumFragmentsToAllocate    This is the number of fragments NIC should grow the Pool
 *                                  by. This number can be overridden, The Nic can choose
 *                                  to allocate a different number of fragments as long as it
 *                                  does not exceed MaxFragmentsToAllocate
 * \param MaxFragmentsToAllocate    The maximum number of frags the hardware is allowed to
 *                                  grow the pool by. This number MUST NOT be exceeded.
 * \return NDIS_STATUS_PENDING if request to grow the pool pended else NDIS_STATUS_FAILURE
 * \sa Mp11AllocateSharedMemoryAsync, Mp11AssociateRxFragment
 */
NDIS_STATUS
Hw11GrowFragmentPool(
    IN PNIC         pNic,
    IN ULONG        NumFragmentsToAllocate,
    IN ULONG        MaxFragmentsToAllocate
    );


/**
 * This function is called before a packet is prepared and submitted to hardware
 * for transmission. If the return value is false, the packet will be queued up
 * and we will try to send it again when a send complete occurs.
 *
 * This function will not be called if a scan operation is outstanding on the
 * hardware.
 *
 * \param pNic              The NIC context for this miniport
 * \param NetBufferList     The NET_BUFFER_LISt that needs to be transmitted.
 * \param Dot11SendContext  The Dot11 send context structure from the NET_BUFFER_LIST
 */
BOOLEAN
Hw11CanTransmitNBL(
    IN PNIC                     pNic,
    IN PNET_BUFFER_LIST         NetBufferList,
    IN PDOT11_EXTSTA_SEND_CONTEXT      Dot11SendContext
    );
    
/**
 * This function is called from the SendComplete interrupt handler to
 * allow the Hw to send any packets it may have pended due to lack of
 * resources. This function is not serialized against the send handler
 *
 * \param pNic              The NIC context for this miniport
 */
VOID
Hw11ProcessPendingSend(
    IN  PNIC pNic
    );


/**
 * This function is called when an assoication has to be created between a
 * MP_TX_MSDU and a NIC_TX_MSDU. This association is vital for the send to work correctly.
 * 
 * \param pNic      The context for this NIC
 * \param pMpTxd    The Miniport TX_MSDU for which an association is to be created
 * \param ppNicTxd  This variable will contain a pointer to the NIC_TX_MSDU with which
 *                  pMpTxd has been associated. This variable will be used only if
 *                  the function succeeds (i.e. returns NDIS_STATUS_SUCCESS)
 * \return NDIS_STATUS_SUCCESS on successful initialization and association
 * of the miniport TX_MSDU with Nic TX_MSDU, else the appropriate error.
 * \sa Hw11DisassociateTxMSDU, Hw11InitializeSend
 */
NDIS_STATUS
Hw11AssociateTxMSDU(
    IN PNIC         pNic,
    IN PMP_TX_MSDU  pMpTxd,
    OUT PNIC_TX_MSDU*   ppNicTxd
    );

/**
 * This function is called to disassociate a previously associated Tx MSDU. This will
 * typically happen only during MiniportHalt.
 * 
 * \param pNic      The NIC context for this miniport
 * \param pNicTxd   The NIC_TX_MSDU to be disassocaited
 * \sa Hw11AssociateTxMSDU, Hw11TerminateSend
 */
VOID
Hw11DisassociateTxMSDU(
    IN PNIC         pNic,
    IN PNIC_TX_MSDU pNicTxd
    );

/**
 * The function will return a pointer to the base virtual address of
 * previously allocated system-space memory that is being mapped by this fragment.
 * The virtual memory should have already been preallocated by the Hw11 and, 
 * therefore, this function cannot fail.
 * 
 * \param pNicFragment  Pointer to the NIC_RX_FRAGMENT whose system virtual address is needed
 * \return Pointer to the system virtual address this fragment will be mapping
 * \sa Hw11AssociateFragment, Hw11GetFragmentDataStart
 */
PVOID
Hw11GetVirtualAddress(
    IN PNIC_RX_FRAGMENT   pNicFragment
    );

/**
 * The function will return a pointer to the start of the network data
 * in a fragment (including the 80211 headers). This differs from Hw11GetVirtualAddress 
 * for encrption, etc cases where part of the buffer returned by GetVirtualAddress 
 * may be unused because it contained the IV, etc. 
 * 
 * \param pNicFragment  Pointer to the NIC_RX_FRAGMENT whose data start is needed
 * \return Pointer to the data start in the fragment
 * \sa Hw11AssociateFragment, Hw11GetVirtualAddress
 */
PVOID
Hw11GetFragmentDataStart(
    IN PNIC_RX_FRAGMENT   pNicFragment
    );

/**
 * This function will check if the TX_MSDU in question has been completely sent.
 * 
 * \param pNicTxd       The NIC_TX_MSDU to be checked for completion status.
 * \return TRUE if the TX_MSDU has been transmitted successfully, else false
 * \sa Hw11TransmitPacket
 */
BOOLEAN
Hw11TxMSDUIsComplete(
    IN PNIC             pNic,
    IN PNIC_TX_MSDU     pNicTxd
    );


/**
 * Return the Tx Status of a Tx MSDU. If the Tx MSDU was transmitted successfully (ACK
 * received in case of unicast traffic) then this function returns NDIS_STATUS_SUCCESS.
 * Else the appropriate failure code is returned.
 * \param pNic      The Nic context for this miniport
 * \param pNicTxd   The Tx MSDU we need Tx Status for
 * \return NDIS_STATUS_SUCCESS on success, else failure code
 * \sa Hw11TxMSDUIsComplete
 */
NDIS_STATUS
Hw11TxMSDUTransmissionStatus(
    IN  PNIC            pNic,
    IN  PNIC_TX_MSDU    pNicTxd
    );


/**
 * This function is called to release a NIC Fragment. After this call, the Hw11 can 
 * reclaim the frag for indicating received frames to NDIS. Calls to this function
 * are not synchronized. More than one thread can be calling this function at the
 * same time. This function must provide any required synchronization.
 *
 * \param pNic              The context for this Nic.
 * \param pNicFragment      The fragment being returned to the NIC
 * \param DispatchLevel     True if we are at IRQL DISPATCH
 * \sa Hw11FreeFragment
 */
VOID
Hw11ReturnFragment(
    IN PNIC             pNic,
    IN PNIC_RX_FRAGMENT pNicFragment,
    IN BOOLEAN          DispatchLevel
    );

/**
 * This function is called to free a NIC_RX_FRAGMENT. After this call, the Hw11 can
 * reuse the associated Receive Descriptor for receiving 802.11 packets. Any
 * shared memory that was allocated for this fragment can be freed however.
 * This function is called to free any fragments that were allocated on the fly
 * because the miniport was running low on Receive Descriptors.
 *
 * This function is always called at IRDL = DISPATCH. Hw11 functions should use
 * NdisDrpAcquire/ReleaseSpinLock function if they need to use a lock for
 * synchronization.
 * 
 * \param pNic          The context for this Nic.
 * \param pNicFragment  The fragment being returned to the NIC
 * \sa Hw11ReturnFragment
 */
VOID
Hw11FreeFragment(
    IN PNIC             pNic,
    IN PNIC_RX_FRAGMENT pNicFragment
    );

/**
 * This function checks to see if the received packet is a good frame that can be
 * indicated up to NDIS. The reason for frame being bad is data corruption only.
 * Do not overload this function to drop packets for any other reason. This would
 * cause counters to become inaccurate. For dropping fragments for reasons such as
 * software filtering etc. use Hw11FilterFragment
 * 
 * \param pNicFragment      The NIC_RX_FRAGMENT to be checked for validity
 * \return TRUE if the frame is good and should be indicated up to NDIS else false
 * \sa Hw11FilterFragment
 */
BOOLEAN
Hw11FragmentIsGood(
    IN PNIC             pNic,
    IN PNIC_RX_FRAGMENT pNicFragment
    );

/**
 * Informs the hardware of a packet receive. This is invoked in the 
 * context of a receive handler DPC and invoked for every valid receive
 * packet.
 * 
 * \param pNic          NIC structure      
 * \param pNicFragment  NIC_RX_FRAGMENT structure to use when invoking HW functions
 * \param pMpFragment   MP_RX_FRAGMENT structure
 * \return NDIS_STATUS whether the packet is acceptable or not
 */
NDIS_STATUS
Hw11PacketReceived(
    IN  PNIC                            pNic,
    IN  PNIC_RX_FRAGMENT                pNicFragment,
    IN  PMP_RX_FRAGMENT                 pMpFragment
    );

/**
 * If the fragment should be dropped for any reason specific to hardware (software
 * filtering) etc, then this function should return a false.
 * 
 * \param pNicFragment  The NIC_RX_FRAGMENT to be checked for validity
 * \return TRUE if the frame is should be indicated up to NDIS else false
 * \sa Hw11FragmentIsGood
 */
BOOLEAN
Hw11FilterFragment(
    IN PNIC             pNic,
    IN PNIC_RX_FRAGMENT pNicFragment
    );

/**
 * This function is called to fill in any information that the hardware can
 * in the Receive Context that will be indicated up for the fragment.
 *
 * \param pNic                      The Nic context for this miniport
 * \param pNicFragment              The Nic Fragment for which we need context
 * \param Dot11RecvContext          The Context to be filled in
 */
VOID
Hw11FillReceiveContext(
    IN  PNIC                        pNic,
    IN  PNIC_RX_FRAGMENT            pNicFragment,
    IN OUT PDOT11_EXTSTA_RECV_CONTEXT   Dot11RecvContext
    );

/**
 * Returns the MP_RX_FRAGMENT associated with a NIC_RX_FRAGMENT.
 * \param pNicFragment      The fragment whose MP_RX_FRAGMENT is needed.
 * \return The MP_RX_FRAGMENT associated with this NIC_RX_FRAGMENT.
 * \sa Mp11AssociateRxFragment, Hw11GetFragment
 */
PMP_RX_FRAGMENT 
Hw11GetMpFragment(
    IN PNIC_RX_FRAGMENT pNicFragment
    );

/**
 * Returns the size in bytes of the fragment. This includes the header size but
 * excludes the CRC of the fragment. The size must not exceed the MAX_FRAME_SIZE.
 *
 * \param pNicFragment      The fragment whose size is being queried.
 * \return The size in bytes.
 * \sa Hw11GetFragmentCount, Hw11GetFragment, Hw11GetMpFragment
 */
USHORT
Hw11GetFragmentDataSize(
    IN PNIC_RX_FRAGMENT pNicFragment
    );

/**
 * Returns the offset in bytes of the fragment where the actual network data starts. 
 *
 * \param pNicFragment      The fragment whose size is being queried.
 * \return The offset in bytes.
 * \sa Hw11GetFragmentCount, Hw11GetFragment, Hw11GetMpFragment
 */
USHORT
Hw11GetFragmentDataOffset(
    IN PNIC_RX_FRAGMENT pNicFragment
    );

/**
 * Returns the encryption status of the fragment. 
 *
 * \param pNicFragment      The fragment whose size is being queried.
 * \return TRUE or FALSE indicating whether the fragment was encrypted when it
 *         was received by hardware.
 * \sa Hw11GetFragmentCount, Hw11GetFragment, Hw11GetMpFragment
 */
BOOLEAN
Hw11IsFragmentEncrypted(
    IN  PNIC_RX_FRAGMENT pNicFragment
    );

/**
 * Returns the channel number the beacon or probe response frame was received at during scan operation. 
 *
 * \param pNicFragment      The fragment whose size is being queried.
 * \return channel number at which the frame was received for the beacon or probe response frame
 *         during scan operation. 
 * \sa Hw11GetFragment, Hw11GetMpFragment
 */
BOOLEAN
Hw11GetFragmentChannel(
    IN  PNIC_RX_FRAGMENT pNicFragment
    );

/**
 * Called when allocation of shared memory completes asynchronously
 * \sa Mp11SharedMemoryAsync
 */
VOID
Hw11SharedMemoryAllocateComplete(
    IN  PNIC                    pNic,
    IN  PVOID                   VirtualAddress,
    IN  PNDIS_PHYSICAL_ADDRESS  PhysicalAddress,
    IN  ULONG                   Length,
    IN  PVOID                   Context
    );

/**
 * Perform any test on the hardware to ensure it is working correctly.
 * 
 * \param pNic          The context for this NIC
 * \return NDIS_STATUS_SUCCESS if the hardware is working correctly, else
 * failure
 */
NDIS_STATUS
Hw11SelfTest(
    IN PNIC    pNic
    );

/**
 * If the NIC needs to read any configuration values from the registry and store
 * them, it can be done in this function. This function is called during MiniportInitialize.
 * The configuration handle passed in will NOT remain alive after this function ends so
 * do not try to use it later.
 *
 * \warning This function must NEVER fail. NIC should always be able to use default
 * values. Initialization of the NIC failing due to registry values being incorrect
 * is a security problem.
 * 
 * \param pNic                  The context for this NIC
 * \param hConfigurationHandle  The handle to Configuration object returned by
 * NdisOpenConfiguration
 * \sa MpReadRegistryConfiguration
 */
VOID
Hw11ReadRegistryConfiguration(
    IN PNIC         pNic,
    IN NDIS_HANDLE  hConfigurationHandle
    );


/**
 * While handling Interrupt for receive, the Mp functions will query and ask
 * the Hw11 if there are any packets that are ready to be indicated to NDIS. If
 * such a packet is ready this function should return true.
 * 
 * \param pNic      The NIC context for this miniport.
 * \return TRUE if an 802.11 MPDU is ready to be indicated, else false
 * \sa Hw11GetReceivedFragment, Hw11FragmentIsGood
 */
BOOLEAN
Hw11ReceiveIsAvailable(
    PNIC        pNic
    );


/**
 * This function is called to retrieve a fragment from the NIC that it previously
 * claimed to have received. This function can be called after Hw11ReceiveIsAvailable
 * returns TRUE.
 * \param pNic      The Nic context for this miniport
 * \param bRawReceive   True if the caller wants to receive the raw packet
 * \return Returns the next MPDU received by the hardware.
 * \sa Hw11ReceiveIsAvailable
 */
PNIC_RX_FRAGMENT
Hw11GetReceivedFragment(
    PNIC        pNic,
    BOOLEAN     bRawReceive
    );


/**
 * This function is called from MiniportShutdown. During shutdown, NIC should put itself
 * in a known state. Power to the antenna needs to be turned off as well.
 *
 * The interrupts will already have been disabled by MiniportShutdown and need not be done
 * in Hw11Shutdown. This function will -NOT- be called if the device has been surprise
 * removed.
 * 
 * \param pNic      The context for this NIC
 * \sa Hw11InitializeNic, Hw11HaltNic, Hw11DevicePnPEvent, MiniportShutdown from DDK
 */
VOID
Hw11Shutdown(
    PNIC        pNic
    );

/**
 * This function is called when NDIS issues a reset to the miniport.
 * The hardware should stop its transmit and receive units and any
 * other hardware that needs to be reset.
 * 
 * \param pNic      The context for this NIC
 * \sa Hw11ResetStep4, Hw11Shutdown, Hw11HaltNic, MiniportReset from DDK.
 * \return See MiniportReset in DDK for return values.
 */
NDIS_STATUS
Hw11ResetStep2(
    PNIC        pNic
    );

/**
 * This function is called when a reset that was previously issued is
 * completing. Typically, a NIC should reverse the actions that it took
 * in Hw11ResetStep2 i.e. start its transmit and receive units and any
 * other hardware that had been stopped. This function would also need
 * to make sure that the data structure in which fragment are maintained is
 * reinitialzied. Due to the receive unit having been restarted, the fragment
 * list would need to be put in a valid state as well. THe goal is that
 * after the reset, the NIC should be in its initialized state.
 * 
 * \param pNic      The context for this NIC
 * \sa Hw11ResetStep2, Hw11Shutdown, Hw11HaltNic, MiniportReset from DDK.
 * \return See MiniportReset in DDK for return values.
 */
NDIS_STATUS
Hw11ResetStep4(
    PNIC        pNic
    );


VOID
Hw11ResetStatistics(
    IN  PNIC pNic
    );

/**
 * This function is called from MiniportReset. This function is called to
 * reinitialize the TX_MSDU. During the reset, all pended sends are completed,
 * the send and receive unit on the NIC is reset and as the entire TX_MSDU and
 * fragment list is reinitialized. This way, the NIC is brough back to Initialize
 * state and can continue to function.
 * 
 * \param pNicTxd   The NIC_TX_MSDU to be reinitialized
 * \sa Hw11ResetStep2, Hw11ResetStep4
 */
VOID
Hw11ReinitializeTxMSDU(
    PNIC_TX_MSDU     pNicTxd
    );


/**
 * This function is invoked when the driver receives a PnP event notification
 * from the OS. A useful example of one such notification for 802.11 drivers
 * would be NdisDevicePnPEventSurpriseRemoved. Other notifications could also
 * be useful.
 * 
 * \param pNic                  The context for this NIC
 * \param DevicePnPEvent        The PnP event that has occurred
 * \param InformationBuffer     Extra data about the PnP event
 * \param InformationBufferLength   Length of Information buffer
 * \sa Hw11HaltNic, Hw11Shutdown
 */
VOID
Hw11DevicePnPEvent(
    IN PNIC                         pNic,
    IN NDIS_DEVICE_PNP_EVENT        DevicePnPEvent,
    IN PVOID                        InformationBuffer,
    IN ULONG                        InformationBufferLength
    );


/**
 * This function is called to allow the Hw to register (or override) additional
 * services that this driver can perform.
 *
 * \sa MiniportSetOptions from the DDK
 */
NDIS_STATUS
Hw11SetOptionalServices(
    IN NDIS_HANDLE  NdisMiniportDriverHandle,
    IN NDIS_HANDLE  MiniportDriverContext
    );

/**
 * This function notifies the hardware about miniport pause event.
 *
 * \param pNic      The context for this NIC
 * \param MiniportPauseParameters   Miniport pause parameters structure
 */
VOID
Hw11MiniportPause(
    IN  PNIC                                pNic,
    IN  PNDIS_MINIPORT_PAUSE_PARAMETERS     MiniportPauseParameters
    );

/**
 * This function notifies the hardware about miniport restart event. 
 * The miniport would undo any operations it performed during the pause
 * notification
 *
 * \param pNic      The context for this NIC
 * \param MiniportRestartParameters   Miniport restart parameters structure
 * \return NDIS_STATUS
 */
NDIS_STATUS
Hw11MiniportRestart(
    IN  PNIC                                pNic,
    IN  PNDIS_MINIPORT_RESTART_PARAMETERS   MiniportRestartParameters
    );

/**
 * This function asks the hardware to start a scan. The pDot11ScanRequest
 * buffer contains the settings the hardware should use for scanning. Though
 * this is an extensible station mode miniport, the hardware should support
 * soft station mode scan structures since the miniport/station portion
 * can modify the scan buffer and set soft station parameters before passing 
 * the buffer to the hardware
 *
 * \param pNic      The context for this NIC
 * \param pDot11ScanRequest     The DOT11_SCAN_REQUEST_V2 block setting
 *                              scan parameters
 * \param ScanRequestBufferLength   Lenght of scan request block
 * \return NDIS_STATUS
 */
NDIS_STATUS
Hw11StartScan(
    PNIC                        pNic,
    PDOT11_SCAN_REQUEST_V2      pDot11ScanRequest,
    ULONG                       ScanRequestBufferLength
    );

/**
 * This function is called to hand a packet to the Hw11 for transmission.
 * The packet is formatted as a MP_TX_MSDU which contains various important
 * information for the Hw11. This function can be called at IRQL >= PASSIVE.
 * Calls to this function are serialized by the Mp functions.
 *
 * Irrespective of whether this packet gets transmitted or queued for transmission,
 * the NIC must generate an interrupt for the packets handed to this function.
 * NIC must not try to allocate any memory during this data path or attempt other
 * operations that could fail. All allocations etc. must be done before hand during
 * MiniportInitialize and its associated functions. The only reason this function can
 * ever fail is if there are not enough resources presently currently to send this Tx MSDU.
 * In this situation, NIC should return NDIS_STATUS_RESOURCES. After a send complete,
 * when some resources have freed up, this function will be invoked again with the same
 * Tx MSDU that had previously failed. The miniport will keep trying the same Tx MSDU forever
 * till it gets sent. If the Tx MSDU is so fragmented that NIC will never be able to send
 * it, then packet coalescing should be used to resolve this issue.
 * 
 * \param pNic      The NIC context for the miniport
 * \param pMpTxd    The TX_MSDU to be transmitted
 * \return  NDIS_STATUS_SUCCESS if all goes well else NDIS_STATUS_RESOURCES if there
 * are not enough resources for sending this packet right now. NO OTHER ERROR STATUS
 * SHOULD BE RETURNED.
 * \sa Mp11PollForTransmission, Hw11TxMSDUIsComplete
 */
NDIS_STATUS
Hw11TransmitTxMSDU(
    IN PNIC                     pNic,
    IN PMP_TX_MSDU              pMpTxd,
    IN BOOLEAN                  DispatchLevel
    );

 /**
  * This function is called when a Tx MSDU previously submitted for SG has
  * been completed. The SG operation could have failed and the ndisStatus
  * field should be looked at before any action is taken. If the SG oepration
  * failed due to low resources, the Hw can either try again later or fail
  * the send as it sees fit. However, if the SG operation failed due to a reset,
  * this Tx MSDU MUST be dropped and SG not retried.
  * 
  * \param pNic             The NIC context for this miniport
  * \param pMpTxd           The MP_TX_MSDU that was being scatter gathered
  * \param ndisStatus       Status of the operation (success or failure)
  * \param DispatchLevel    True if Dispatch Level IRQL, else false
  * \sa Mp11PerformScatterGather
  */
VOID
Hw11TxMSDUScatterGatherComplete(
    IN  PNIC                    pNic,
    IN  PMP_TX_MSDU             pMpTxd,
    IN  NDIS_STATUS             ndisStatus,
    IN  BOOLEAN                 DispatchLevel
    );



/**
 * Returns the link speed for the underlying hardware. Please do not return a link
 * speed of zero. Even if there is no association or RF link, driver should report 
 * useful default values.
 * 
 * \param pNic      The NIC context for the adapter
 * \return The link speed in units of bps
 * \sa OID_GEN_LINK_SPEED
 */
ULONG64
Hw11GetLinkSpeed(
    PNIC pNic
    );

/**
 * Returns the Interrupt level for this NIC. The expected values are
 * NdisInterruptLatched  or NdisInterruptLevelSensitive .
 * 
 * \param pNic      The NIC context for this miniport
 * \return The Interrupt level for this NIC
 * \sa NdisMRegisterInterrupt, MPInitialize
 */
ULONG
Hw11GetInterruptLevel(
    PNIC    pNic
    );

/**
 * Enable the interrupts of the hardware.
 *
 * \param pNic      The NIC context for this miniport
 * \sa Hw11EnableInterrupt, Hw11DisableInterrupt, Hw11InterruptEnabled,
 *     Hw11InterruptRecognized, Hw11ClearInterrupt
 */
VOID
Hw11EnableInterrupt(
    PNIC pNic
    );


/**
 * Disable the interrupts of the hardware. This function will -NOT- be 
 * called if the device has been surprise removed.
 * 
 * \param pNic      The NIC context for this miniport
 * \sa Hw11EnableInterrupt, Hw11DisableInterrupt, Hw11InterruptEnabled,
 *     Hw11InterruptRecognized, Hw11ClearInterrupt, Hw11HaltNic */
VOID
Hw11DisableInterrupt(
    PNIC pNic
    );

/**
 * Check if the interrupt on the hardware are enabled
 * 
 * \param pNic      The NIC context for this miniport
 * \return True if the interrupts are enabled else false
 * \sa Hw11EnableInterrupt, Hw11DisableInterrupt, Hw11InterruptEnabled,
 *     Hw11InterruptRecognized, Hw11ClearInterrupt
 */
BOOL
Hw11InterruptEnabled(
    PNIC pNic
    );

/**
 * Check if the hardware has interrupted the system. If the NIC
 * claims the interrupt, it should return true.
 * 
 * \param pNic                              The NIC context for this miniport
 * \param pbQueueMiniportHandleInterrupt    Set this to true if miniport needs the
 * the interrupt handling DPC to be queued.
 * \return TRUE if the hardware had interrupted the system, else FALSE.
 * \warning Please set the values to TRUE and FALSE and do not try to use any
 * non zero value as TRUE. The OS requires tradition 0 or 1 values
 * \sa Hw11EnableInterrupt, Hw11DisableInterrupt, Hw11InterruptEnabled,
 *     Hw11InterruptRecognized, Hw11ClearInterrupt
 */
BOOLEAN
Hw11InterruptRecognized(
    IN  PNIC            pNic,
    OUT PBOOLEAN        pbQueueMiniportHandleInterrupt
    );

/**
 * If the hardware had previously interrupted the system, this
 * call will clear the state claiming that interrupt. A subsequent call
 * to Hw11InterruptRecognized should not return true unless a new
 * interrupt was generated by the hardware between the two calls.
 * 
 * \param pNic      The NIC context for this miniport
 * \sa Hw11EnableInterrupt, Hw11DisableInterrupt, Hw11InterruptEnabled,
 *     Hw11InterruptRecognized, Hw11ClearInterrupt
 */
VOID
Hw11ClearInterrupt(
    PNIC pNic
    );

/**
 * Sets the operation mode on the hardware portion. This is a 
 * good place to set the hardware up for the various
 * operation modes. Using some smart function pointer can avoid
 * the cost of extra if conditions that check for current mode before
 * deciding what action to take.
 *
 * \param pNic      The NIC context for this miniport
 * \param pDot11CurrentOperationMode      The new operation mode
 */
NDIS_STATUS
Hw11SetOperationMode(
    PNIC pNic,
    PDOT11_CURRENT_OPERATION_MODE pDot11CurrentOperationMode
    );

VOID
Hw11QueryCurrentOperationMode(
    PNIC pNic,
    PDOT11_CURRENT_OPERATION_MODE pDot11CurrentOperationMode
    );

/**
 * This function is called when an Oustanding Scan operation is to be
 * cancelled. This function should return only when the Scan Operation
 * has been completed. This function will always be called at Passive
 * IRQL.
 *
 * \param pNic      The NIC context for this miniport
 */
VOID
Hw11CancelScan(
    PNIC    pNic
    );
    

NDIS_STATUS
Hw11SetMCastList(
    PNIC pNic,
    PVOID pvInformationBuffer,
    ULONG uInformationBufferLength
    );

PDOT11_MAC_ADDRESS
Hw11GetMACAddress(
    PNIC pNic
    );

PDOT11_MAC_ADDRESS
Hw11GetCurrentBSSID(
    PNIC pNic
    );

VOID
Hw11SetMACAddress(
    IN  PNIC                    pNic,
    IN  DOT11_MAC_ADDRESS       MacAddress
    );

NDIS_STATUS
Hw11SetCurrentChannel(
    IN PNIC pNic,
    IN ULONG channel
    );

ULONG
Hw11GetCurrentChannelId(
    IN PNIC pNic
    );

NDIS_STATUS
Hw11SetChannel(
    IN PNIC         pNic,
    IN ULONG        channel,
    IN BOOLEAN      selectedPhy 
    );

NDIS_STATUS
Hw11GetChannel(
    IN  PNIC         pNic,
    OUT PULONG       channel,
    IN  BOOLEAN      selectedPhy 
    );

VOID
Hw11StopBSSAdvertisment(
    IN PNIC         pNic
    );

VOID
Hw11StartBSSAdvertisment(
    IN PNIC         pNic
    );

VOID
Hw11QueryOpModeCap(
    IN PNIC pNic,
    PDOT11_OPERATION_MODE_CAPABILITY pDot11OpModeCap
    );

ULONG
Hw11GetMPDUMaxLength(
    IN PNIC pNic
    );

/**
 * This is called between Hw11ResetStep2 and Hw11ResetStep4 calls and 
 * requests the hardware to reset the MAC/PHY
 * 
 * \param pNic      The NIC context for this miniport
 * \param ResetType Reset type (determines whether to reset MAC/PHY or both)
 */
NDIS_STATUS
Hw11ResetStep3(
    IN PNIC pNic,
    IN MP_RESET_TYPE ResetType
    );

VOID
Hw11ResetMacMIBs(
    IN  PNIC    pNic
    );

VOID
Hw11ResetPhyMIBs(
    IN  PNIC    pNic
    );


NDIS_STATUS
Hw11ReadResetStatus(
    IN PNIC pNic
    );

ULONG
Hw11QueryATIMWindow(
    IN PNIC pNic
    );

BOOLEAN
Hw11QueryCFPollable(
    IN PNIC pNic
    );

VOID
Hw11QueryPowerMgmtMode(
    IN PNIC pNic,
    OUT PDOT11_POWER_MGMT_MODE pDot11PowerMgmtMode
    );

NDIS_STATUS
Hw11CanTransitionPower(
    IN  PNIC    pNic,
    IN  NDIS_DEVICE_POWER_STATE NewDevicePowerState
    );

ULONG
Hw11QueryBeaconPeriod(
    IN PNIC pNic
    );

ULONG
Hw11QueryDTIMPeriod(
    IN PNIC pNic
    );

UCHAR
Hw11QueryDTIMCount(
    IN  PNIC    pNic
    );

ULONG
Hw11QueryRTSThreshold(
    IN PNIC pNic
    );

ULONG
Hw11QueryShortRetryLimit(
    IN PNIC pNic
    );

ULONG
Hw11QueryLongRetryLimit(
    IN PNIC pNic
    );

ULONG
Hw11QueryMaxTXMSDULifeTime(
    IN PNIC pNic
    );

ULONG
Hw11QueryMaxReceiveLifeTime(
    IN PNIC pNic
    );


NDIS_STATUS
Hw11SetATIMWindow(
    IN PNIC pNic,
    IN ULONG uValue
    );


NDIS_STATUS
Hw11SetBeaconPeriod(
    IN PNIC pNic,
    IN ULONG uValue
    );

NDIS_STATUS
Hw11SetRTSThreshold(
    IN PNIC pNic,
    IN ULONG uValue
    );

ULONG
Hw11GetFragmentationThreshold(
    IN PNIC pNic
    );

NDIS_STATUS
Hw11SetFragmentationThreshold(
    IN PNIC pNic,
    IN ULONG uValue
    );

NDIS_STATUS
Hw11QueryRecvSensitivityList(
    IN PNIC pNic,
    IN ULONG uMaxEntries,
    IN OUT PDOT11_RECV_SENSITIVITY_LIST pDot11RecvSensitivityList
    );

VOID
Hw11QueryOperationalRateSet(
    IN  PNIC            pNic,
    OUT PDOT11_RATE_SET pDot11RateSet,
    IN  BOOLEAN         selectedPhy 
    );

VOID
Hw11QueryBasicRateSet(
    IN  PNIC            pNic,
    OUT PDOT11_RATE_SET pDot11RateSet,
    IN  BOOLEAN         selectedPhy 
    );

NDIS_STATUS
Hw11SetOperationalRateSet(
    IN  PNIC            pNic,
    IN  PDOT11_RATE_SET pDot11RateSet,
    IN  BOOLEAN         selectedPhy 
    );

NDIS_STATUS
Hw11QueryCCAModeSupported(
    IN  PNIC        pNic,
    OUT PULONG      value,
    IN  BOOLEAN     selectedPhy 
    );

NDIS_STATUS
Hw11QueryCurrentCCA(
    IN  PNIC        pNic,
    OUT PULONG      value,
    IN  BOOLEAN     selectedPhy 
    );

NDIS_STATUS
Hw11QueryEdThreshold(
    IN  PNIC         pNic,
    OUT PULONG       value,
    IN  BOOLEAN      selectedPhy 
    );

BOOLEAN
Hw11QueryNicPowerState(
    IN PNIC pNic,
    IN BOOLEAN selectedPhy
    );

NDIS_STATUS
Hw11SetNicPowerState(
    IN PNIC     pNic,
    IN BOOLEAN  bPowerOn,
    IN BOOLEAN  selectedPhy
    );

NDIS_STATUS
Hw11QueryOptionalCapability(
    IN PNIC pNic,
    PDOT11_OPTIONAL_CAPABILITY pDot11OptionalCapability
    );

NDIS_STATUS
Hw11QueryCurrentOptionalCapability(
    IN PNIC pNic,
    IN PDOT11_CURRENT_OPTIONAL_CAPABILITY pDot11CurrentOptionalCapability
    );

ULONG
Hw11QueryMediumOccupancyLimit(
    IN PNIC pNic
    );

ULONG
Hw11QueryCurrentRegDomain(
    IN PNIC pNic
    );

DOT11_TEMP_TYPE
Hw11QueryTempType(
    IN PNIC pNic
    );

ULONG
Hw11QueryCurrentTXAntenna(
    IN PNIC pNic
    );

DOT11_DIVERSITY_SUPPORT
Hw11QueryDiversitySupport(
    IN PNIC pNic
    );

ULONG
Hw11QueryCurrentRXAntenna(
    IN PNIC pNic
    );

VOID
Hw11QuerySupportedPowerLevels(
    IN PNIC pNic,
    PDOT11_SUPPORTED_POWER_LEVELS pDot11SupportedPowerLevels
    );

ULONG
Hw11QueryCurrentTXPowerLevel(
    IN PNIC pNic
    );

NDIS_STATUS
Hw11QueryRegDomainsSupportValue(
    IN PNIC pNic,
    IN ULONG uNumMaxEntries,
    OUT PDOT11_REG_DOMAINS_SUPPORT_VALUE pDot11RegDomainsSupportValue
    );

NDIS_STATUS
Hw11QuerySupportedTXAntenna(
    IN PNIC pNic,
    IN ULONG uNumMaxEntries,
    OUT PDOT11_SUPPORTED_ANTENNA_LIST pDot11SupportedAntennaList
    );

NDIS_STATUS
Hw11QuerySupportedRXAntenna(
    IN PNIC pNic,
    IN ULONG uNumMaxEntries,
    OUT PDOT11_SUPPORTED_ANTENNA_LIST pDot11SupportedAntennaList
    );

ULONG
Hw11QueryRFUsage(
    IN PNIC				pNic
    );

NDIS_STATUS
Hw11QueryShortPreambleOptionImplemented(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    );

NDIS_STATUS
Hw11QueryPbccOptionImplemented(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    );

NDIS_STATUS
Hw11QueryErpPbccOptionImplemented(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    );

NDIS_STATUS
Hw11QueryErpPbccOptionEnabled(
    IN  PNIC            pNic,
    OUT PBOOLEAN        value,
    IN  BOOLEAN         selectedPhy
    );

NDIS_STATUS
Hw11SetErpPbccOptionEnabled(
    IN  PNIC			pNic,
    IN  BOOLEAN         value,
    IN  BOOLEAN         selectedPhy
    );

NDIS_STATUS
Hw11QueryDsssOfdmOptionImplemented(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    );

NDIS_STATUS
Hw11QueryDsssOfdmOptionEnabled(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    );

NDIS_STATUS
Hw11SetDsssOfdmOptionEnabled(
    IN PNIC				pNic,
    IN BOOLEAN          value,
    IN BOOLEAN          selectedPhy
    );

NDIS_STATUS
Hw11QueryShortSlotTimeOptionImplemented(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    );

NDIS_STATUS
Hw11QueryShortSlotTimeOptionEnabled(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    );

NDIS_STATUS
Hw11SetShortSlotTimeOptionEnabled(
    IN PNIC				pNic,
    IN BOOLEAN          value,
    IN BOOLEAN          selectedPhy
    );

NDIS_STATUS
Hw11QueryChannelAgilityPresent(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    );

NDIS_STATUS
Hw11QueryChannelAgilityEnabled(
    IN  PNIC             pNic,
    OUT PBOOLEAN         value,
    IN  BOOLEAN          selectedPhy
    );

NDIS_STATUS
Hw11QueryDiversitySelectionRX(
    IN PNIC pNic,
    IN ULONG uNumMaxEntries,
    OUT PDOT11_DIVERSITY_SELECTION_RX_LIST pDot11DiversitySelectionRXList
    );

VOID
Hw11QueryStationId(
    IN PNIC pNic,
    IN DOT11_MAC_ADDRESS Dot11MacAddress
    );

VOID
Hw11QueryPnPCapabilities(
    IN PNIC     pNic,
    OUT PNDIS_PNP_CAPABILITIES pNdisPnPCapabilities
    );

NDIS_STATUS
Hw11QueryInterruptModerationSettings(
    IN PNIC     pNic,
    OUT PNDIS_INTERRUPT_MODERATION_PARAMETERS      pIntModParams
    );

NDIS_STATUS
Hw11SetInterruptModerationSettings(
    IN PNIC     pNic,
    IN PNDIS_INTERRUPT_MODERATION_PARAMETERS      pIntModParams
    );

NDIS_STATUS
Hw11QueryLinkParameters(
    IN PNIC     pNic,
    OUT PNDIS_LINK_PARAMETERS      pLinkParams
    );

NDIS_STATUS
Hw11SetLinkParameters(
    IN PNIC     pNic,
    IN PNDIS_LINK_PARAMETERS      pLinkParams
    );

NDIS_STATUS
Hw11GetOfdmFrequency(
    IN  PNIC        pNic,
    OUT PULONG      freq,
    IN  BOOLEAN     selectedPhy 
    );

NDIS_STATUS
Hw11SetOfdmFrequency(
    IN PNIC         pNic,
    IN ULONG        freq,
    IN BOOLEAN      selectedPhy 
    );

NDIS_STATUS
Hw11FrequencyBandsSupported(
    IN  PNIC        pNic,
    OUT PULONG      value,
    IN  BOOLEAN     selectedPhy
    );

NDIS_STATUS
Hw11SetCurrentRegDomain(
    IN PNIC pNic,
    IN ULONG uValue
    );

NDIS_STATUS
Hw11QuerySupportedPHYTypes(
    IN PNIC pNic,
    IN ULONG uNumMaxEntries,
    IN OUT PDOT11_SUPPORTED_PHY_TYPES pDot11SupportedPhyTypes
    );

DOT11_PHY_TYPE
Hw11QueryCurrentPhyType(
    IN PNIC pNic
    );

ULONG
Hw11FindSelectedPhyID(
    IN PNIC pNic,
	IN DOT11_PHY_TYPE PhyType
    );

NDIS_STATUS
Hw11SetCurrentPhyType(
    IN PNIC pNic,
    IN DOT11_PHY_TYPE   PhyType
    );

BOOLEAN
Hw11IsPhyTypeSupported(
    IN  PNIC pNic,
    IN  DOT11_PHY_TYPE PhyType
    );

NDIS_STATUS
Hw11QueryStatistics(
    IN PNIC             pNic,
    IN NDIS_OID         Oid,
    IN OUT PVOID        StatBuffer,
    IN OUT PULONG       BytesWritten
    );

ULONG
Hw11GetCalibratedRSSI(
    IN  PNIC            pNic,
    IN  PNIC_RX_FRAGMENT    pNicFragment
    );

LONG
Hw11GetRSSI(
    IN  PNIC            pNic,
    IN  PNIC_RX_FRAGMENT    pNicFragment
    );

LONG
Hw11GetMinRSSI(
    IN  PNIC            pNic,
    IN  ULONG           uDataRate
    );

LONG
Hw11GetMaxRSSI(
    IN  PNIC            pNic,
    IN  ULONG           uDataRate
    );

UCHAR
Hw11GetDataRate(
    IN  PNIC            pNic,
    IN  PNIC_RX_FRAGMENT    pNicFragment
    );

ULONG
Hw11GetChannelCenterFrequency(
    IN  PNIC            pNic,
    IN  PNIC_RX_FRAGMENT    pNicFragment
    );

VOID
Hw11SetDevicePowerState(
    IN  PNIC		                pNic,
    IN  NDIS_DEVICE_POWER_STATE     DevicePowerState
    );

NDIS_STATUS
Hw11QuerySupportedGUIDS(
    IN  PNIC                        pNic
    );

NDIS_STATUS
Hw11SetPacketFilter(
    PNIC pNic,
    ULONG PacketFilter
    );

NDIS_STATUS
Hw11ValidateOperationalRates(
    IN  PNIC            pNic,
    IN  ULONG           PhyId,
    IN  PUCHAR          pDataRatesSet,
    IN  ULONG           RateSetLength
    );

/**
 * Sets that hardware up for joining to the specified
 * infrastructure network. The hardware should 
 * set itself up to synchronize to beacons from the specified 
 * access point. Once the join has completed, the Sta11JoinCompleteInfra 
 * routine should be called.
 *
 * \param pNic          The NIC context
 * \param pBSSEntry     Information about the AP to join
 * \param JoinFailureTimeout   Number of beacon intervals within which
 *                      we must complete the beacon or fail
 */
NDIS_STATUS
Hw11JoinInfra(
    IN PNIC		                pNic,
    IN PSTA_BSS_ENTRY           pBSSEntry,
    IN ULONG                    JoinFailureTimeout
    );
    
BOOLEAN 
Hw11WEP104Implemented(
    IN  PNIC pNic
    );

BOOLEAN 
Hw11WEP40Implemented(
    IN  PNIC pNic
    );

BOOLEAN 
Hw11TKIPImplemented(
    IN  PNIC pNic
    );

BOOLEAN 
Hw11CCMPImplemented(
    IN  PNIC pNic
    );

USHORT
Hw11GetRSNCapability(
    IN  PNIC pNic
    );

void
Hw11SetCurrentBSSType(
    IN  PNIC pNic,
    IN  DOT11_BSS_TYPE  type
    );

void
Hw11SetEncryption(
    IN  PNIC pNic,
    IN  BOOLEAN isUnicast,
    IN  DOT11_CIPHER_ALGORITHM  algoId
    );

void
Hw11SetAuthentication(
    IN  PNIC pNic,
    IN  DOT11_AUTH_ALGORITHM  algoId
    );

NDIS_STATUS
Hw11SetDefaultKey(
    IN  PNIC pNic,
    IN  DOT11_MAC_ADDRESS MacAddr,
    IN  ULONG keyID,
    IN  BOOLEAN persist,
    IN  DOT11_CIPHER_ALGORITHM algoId,
    IN  ULONG keyLength,
    IN  PUCHAR keyValue
    );

NDIS_STATUS 
Hw11SetKeyMappingKey(
    IN  PNIC pNic,
    IN  DOT11_MAC_ADDRESS MacAddr,
    IN  DOT11_DIRECTION direction,
    IN  BOOLEAN persistent,
    IN  DOT11_CIPHER_ALGORITHM algoId,
    IN  ULONG keyLength,
    IN  PUCHAR keyValue
    );

PNICKEY
Hw11FindKeyMappingKey(
    IN PNIC                 pNic,
    IN DOT11_MAC_ADDRESS    MacAddr
    );

void 
Hw11DeleteNonPersistentKey(
    IN  PNIC pNic
    );

void
Hw11DeleteNonPersistentMappingKey(
    IN  PNIC pNic,
    IN  DOT11_MAC_ADDRESS MacAddr
    );

/**
 * Restore any encryption settings (keys/mode) on the hardware. This is called after
 * a reset
 */
void 
Hw11RestoreEncryption(
    IN  PNIC pNic
    );

void
Hw11SetDefaultKeyID(
    IN  PNIC pNic,
    IN  ULONG keyID
    );

ULONG
Hw11GetDefaultKeyID(
    IN  PNIC pNic
    );

void
Hw11ResetFilterFunction(
    IN  PNIC pNic
    );

/**
 * This function is used to ask the hardware to synchronize 
 * itself with specified Adhoc station beacons.
 * 
 * \param pNic              The NIC context
 * \param BSSDescription    The BSS entry to synchronize to
 */
NDIS_STATUS
Hw11JoinAdHoc(
    IN  PNIC		             pNic,
    IN  PDOT11_BSS_DESCRIPTION  BSSDescription
    );

/**
 * This function is used to ask the hardware to start adhoc beaconing 
 * using specified bss information
 * 
 * \param pNic              The NIC context
 * \param BSSDescription    The BSS information to use for
 *                          adhoc station beacons
 */
NDIS_STATUS
Hw11StartAdHoc(
    IN  PNIC		             pNic,
    IN  PDOT11_BSS_DESCRIPTION  BSSDescription
    );

/**
 * This function is used to ask the hardware to stop adhoc beaconing.
 * 
 * \param pNic              The NIC context
 */
void
Hw11StopAdHoc(
    IN  PNIC		             pNic
    );

NDIS_STATUS
Hw11SetPowerMgmtMode(
    IN  PNIC pNic,
    IN  PDOT11_POWER_MGMT_MODE pDot11PowerMgmtMode
    );

VOID
Hw11QuerySupportedDataRatesValue(
    IN  PNIC                                    pNic,
    OUT PDOT11_SUPPORTED_DATA_RATES_VALUE_V2    pDot11SupportedDataRatesValue,
    IN  BOOLEAN                                 selectedPhy 
    );

VOID
Hw11CleanupNetBufferList(
    IN  PNIC pNic,
    IN  PNET_BUFFER_LIST    NetBufferList
    );

NDIS_STATUS
Hw11SecurityCheck(
    IN PNIC                 pNic,
    IN PNET_BUFFER          NetBuffer,
    IN PNIC_RX_FRAGMENT    *ppNicFragment,
    IN ULONG                FragmentCount
    );

ULONG
Hw11DefaultKeyTableSize(
    IN PNIC                 pNic
    );

ULONG
Hw11KeyMappingKeyTableSize(
    IN PNIC                 pNic
    );

ULONG
Hw11PerStaKeyTableSize(
    IN PNIC                 pNic
    );

ULONG
Hw11QueryOperatingPhyId(
    IN  PNIC pNic
    );


void
Hw11SetTXDataRate(
    IN PNIC pNic,
    IN PDOT11_RATE_SET  APRateSet,
    IN ULONG            LinkQuality
    );

DOT11_PHY_TYPE
Hw11DeterminePHYType(
    IN PNIC pNic,
    IN DOT11_CAPABILITY Capability,
    IN UCHAR Channel
    );

BOOLEAN
Hw11QueryHardwarePhyState(
    PNIC pNic
    );

NDIS_STATUS
Hw11SetOperatingPhyId(
    IN PNIC pNic,
    IN  ULONG PhyId
    );

ULONG
Hw11QuerySelectedPhyId(
    IN  PNIC pNic
    );

NDIS_STATUS
Hw11SetSelectedPhyId(
    IN  PNIC pNic,
    IN  ULONG PhyId
    );

NDIS_STATUS
Hw11SetDesiredPhyIdList(
    IN  PNIC pNic,
    IN  ULONG*  PhyIDList,
    IN  ULONG   PhyIDCount
    );

NDIS_STATUS
Hw11QueryDataRateMappingTable(
    IN  PNIC pNic,
    OUT PDOT11_DATA_RATE_MAPPING_TABLE  pDataRateMappingTable,
    IN  ULONG           TotalLength
    );

NDIS_STATUS
Hw11Fill80211Attributes(
    IN  PNIC pNic,
    OUT PNDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES attr
    );

VOID
Hw11Cleanup80211Attributes(
    IN PNIC pNic,
    IN PNDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES attr
    );


NDIS_STATUS
Hw11QueryDot11Statistics(
    IN PNIC pNic,
    IN PDOT11_STATISTICS pDot11Stats,
    IN ULONG InformationBufferLength,
    OUT PULONG BytesWritten,
    OUT PULONG BytesNeeded
    );

NDIS_STATUS
Hw11SetSafeModeOption(
    IN  PNIC            pNic,
    IN  BOOLEAN         safeModeEnabled
    );

BOOLEAN
Hw11GetSafeModeOption(
    IN  PNIC            pNic 
    );


VOID
Hw11CheckForProtectionInERP(
    IN  PNIC            pNic,
    IN  PUCHAR          pInfoBlob,
    IN  ULONG           infoBlobLength
    );

VOID
Hw11NotifyEventConnectionState(
    IN  PNIC            pNic,
    IN  BOOLEAN         bState
    );

VOID
Hw11CheckForHighQCompletion(
    IN  PNIC    pNic 
    );

void
CheckBeacon(
    IN   PNIC       pNic,
    IN   USHORT     IntStatus
);

BOOLEAN
HwInsertSequenceNumForNB(
    IN  PNIC            pNic,
    IN  PMP_DOT11_MGMT_DATA_MAC_HEADER     pFragmentHeader,
    IN  BOOLEAN         IncrementSequenceNumber
    );

#endif //_HW_INTERFACE_H


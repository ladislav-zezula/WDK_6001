/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:
    st_intf.h

Abstract:
    Interface functions into Sta layer
    
Revision History:
      When        What
    ----------    ----------------------------------------------
    08-01-2005    Created
    01-15-2006    Renamed STA_Interface.h to st_intf.h
    06-10-2006    Renamed:
                    Sta11ResetStart to Sta11ResetStep1
                    Sta11Reset to Sta11ResetStep2
                    Sta11ResetEnd to Sta11ResetStep4
                  

Notes:

--*/
#ifndef _STATION_INTERFACE_H
#define _STATION_INTERFACE_H

//
// Forward declaration
//
typedef struct _ADAPTER         ADAPTER, *PADAPTER;
typedef struct _MP_TX_MSDU      MP_TX_MSDU, *PMP_TX_MSDU;
typedef struct _MP_RX_MSDU      MP_RX_MSDU, *PMP_RX_MSDU;
typedef struct _MP_RX_FRAGMENT  MP_RX_FRAGMENT, *PMP_RX_FRAGMENT;


typedef struct _NIC_TX_MSDU     NIC_TX_MSDU, *PNIC_TX_MSDU;
typedef struct _NIC_RX_MSDU     NIC_RX_MSDU, *PNIC_RX_MSDU;
typedef struct _NIC_RX_FRAGMENT NIC_RX_FRAGMENT, *PNIC_RX_FRAGMENT;
typedef struct _NIC             NIC, *PNIC;


typedef struct _STATION         STATION, *PSTATION;

/**
 * Called during initialization. Allocates and initializes the station 
 * structure. 
 * 
 * \param MiniportAdapterHandle MiniportHandle registered with Ndis
 * \param ppStation             Returns the allocated STATION structure
 * \param pAdapter              ADAPTER structure to use when calling
 *                              Mp11 functions
 * \param pNic                  NIC structure to use when calling
 *                              Hw11 functions
 * \return                      Appropriate NDIS_STATUS 
 * \sa Sta11FreeStation
 */
NDIS_STATUS
Sta11AllocateStation(
    IN  NDIS_HANDLE     MiniportAdapterHandle,
    OUT PSTATION*       ppStation
    );

/**
 * Initializes the internal variables in the station. When this is called,
 * the NIC is not ready, station cannot yet call any Hw11 interfaces
 * 
 * \param pStation              The STATION structure that was previously
 *                              allocated
 * \param pAdapter              ADAPTER structure to use when calling
 *                              Mp11 functions
 * \param pNic                  NIC structure to use when calling
 *                              Hw11 functions
 * \return                      Appropriate NDIS_STATUS 
 * \sa Sta11StartStation, Sta11FreeStation
 */
NDIS_STATUS
Sta11InitializeStation(
    IN  PSTATION        pStation,
    IN  PADAPTER        pAdapter,
    IN  PNIC            pNic
    );

/**
 * Frees the STATION structure when miniport is being cleaned up. This
 * function is only called if Sta11AllocateStation succeeds. This function
 * cannot invoke any of the Hw11 functions. This function is invoked at
 * IRQL_PASSIVE
 * 
 * \param pStation      Previously allocated STATION structure
 * \sa Sta11AllocateStation
 */
VOID
Sta11FreeStation(
    IN  PSTATION        pStation
    );

/**
 * Informs the station that the NIC is ready and it can initialize
 * itself and initiate station functionality. This is called while
 * the miniport is still in the paused state and hence it must not
 * indicate any packets
 * 
 * \param pStation      STATION structure
 */
NDIS_STATUS
Sta11StartStation(
    IN  PSTATION        pStation
    );

/**
 * Informs the station that the NIC has already stopped and it should
 * stop and cleanup. When this is called, the NIC is already stopped
 * and interrupts disabled. This is called on halt or if initialize
 * has failed.
 * 
 * \param pStation      STATION structure
 * \param HaltAction    Reason for the stop. This corresponds to HaltAction
 *                      from MiniportHaltEx. NdisHaltDeviceInitializationFailed is
 *                      overloaded and used for Stop called due to miniport
 *                      initialize failure
 */
VOID
Sta11StopStation(
    IN  PSTATION        pStation,
    IN  NDIS_HALT_ACTION    HaltAction
    );

/**
 * If the STATION needs to read any configuration values from the registry and store
 * them, it can be done in this function. This function is called during MiniportInitialize.
 * The configuration handle passed in will NOT remain alive after this function ends so
 * do not try to use it later.
 *
 * \warning This function must NEVER fail. Station should always be able to use default
 * values. Initialization of the Station failing due to registry values being incorrect
 * is a security problem.
 * 
 * \param pStation              STATION structure
 * \param hConfigurationHandle  The handle to Configuration object returned by
 * NdisOpenConfiguration
 * \sa MpReadRegistryConfiguration
 */
VOID
Sta11ReadRegistryConfiguration(
    IN PSTATION         pStation,
    IN NDIS_HANDLE      hConfigurationHandle
    );

/**
 * Informs the station that the miniport is about to be reset (either 
 * NdisReset or OID_DOT11_RESET). This is called before the reset 
 * has actually begun. This function is invoked at IRQL_PASSIVE.
 * 
 * \param pStation      STATION structure
 * \param ResetType     The type/cause of the reset
 *
 */
VOID
Sta11ResetStep1(
    IN  PSTATION         pStation,
    IN  MP_RESET_TYPE    ResetType
    );

/**
 * Reset the station state. This is called during NdisReset and OID_DOT11_RESET. 
 * This function is invoked at IRQL_DISPATCH
 * 
 * \param pStation      STATION structure
 * \param ResetType     The type/cause of the reset
 *
 */
VOID
Sta11ResetStep2(
    IN  PSTATION         pStation,
    IN  MP_RESET_TYPE    ResetType
    );

/**
 * Informs the station that the miniport has completed the reset (either 
 * NdisReset or OID_DOT11_RESET). This is called after the reset 
 * has completed. This function is invoked at IRQL_DISPATCH
 * 
 * \param pStation      STATION structure
 * \param ResetType     The type/cause of the reset
 *
 */
VOID
Sta11ResetStep4(
    IN  PSTATION         pStation,
    IN  MP_RESET_TYPE    ResetType
    );

/**
 * Informs the station of a packet receive. This is invoked in the 
 * context of a receive handler DPC and invoked for every valid receive
 * packet.
 * 
 * \param pStation      STATION structure      
 * \param pMpFragment   MP_RX_FRAGMENT structure
 * \param pNicFragment  NIC_RX_FRAGMENT structure to use when invoking HW functions
 * \param pFragmentHdr  pointer to DOT11_MAC_HEADER
 * \param FragmentSize  Length of the PACKET
 * \return NDIS_STATUS whether the packet is acceptable or not
 */
NDIS_STATUS
Sta11PacketReceived(
    IN  PSTATION                        pStation,
    IN  PMP_RX_FRAGMENT                 pMpFragment,
    IN  PNIC_RX_FRAGMENT                pNicFragment,
    IN  PDOT11_MAC_HEADER               pFragmentHdr,
    IN  USHORT                          uFragmentSize
    );
    
/**
 * Invoked on OID_DOT11_ENUM_BSS_LIST to populate the structure with
 * discovered access points information
 * 
 * \param pStation              STATION structure
 * \param pDot11ByteArray       DOT11_BYTE_ARRAY to populate
 * \param TotalLength           Total length of the buffer
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11EnumerateBSSList(
    IN  PSTATION         pStation,
    IN  OUT PDOT11_BYTE_ARRAY        pDot11ByteArray,
    IN  ULONG            TotalLength
    );

/**
 * Invoked on OID_DOT11_FLUSH_BSS_LIST to clear discovered access
 * points
 *
 * \param pStation              STATION structure
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11FlushBSSList(
    IN  PSTATION        pStation
    );

/**
 * Invoked on OID_DOT11_DESIRED_BSS_TYPE query 
 * 
 * \param pStation              STATION structure
 * \param bssType               Pointer to the BSS type to be queried
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryDesiredBSSType(
    IN  PSTATION        pStation,
    IN  PDOT11_BSS_TYPE bssType
    );

/**
 * Invoked on OID_DOT11_DESIRED_SSID_LIST query
 * 
 * \param pStation              STATION structure
 * \param pDot11SSIDList        Structure to populate
 * \param TotalLength           Total length of the structure
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryDesiredSSIDList(
    IN  PSTATION        pStation,
    OUT PDOT11_SSID_LIST    pDot11SSIDList,
    IN  ULONG           TotalLength
    );

/**
 * Invoked on OID_DOT11_EXCLUDED_MAC_ADDRESS_LIST query.
 * 
 * \param pStation              STATION structure
 * \param pDot11MacAddrList     Structure to populate
 * \param TotalLength           Total length of the structure
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryExcludedMACAddressList(
    IN  PSTATION        pStation,
    OUT PDOT11_MAC_ADDRESS_LIST pDot11MacAddrList,
    IN  ULONG           TotalLength
    );

/**
 * Invoked on OID_DOT11_QUERY_DESIRED_BSSID_LIST query
 * 
 * \param pStation              STATION structure
 * \param pDot11MacAddrList     Structure to populate
 * \param TotalLength           Total length of the structure
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryDesiredBSSIDList(
    IN  PSTATION        pStation,
    OUT PDOT11_BSSID_LIST   pDot11BSSIDList,
    IN  ULONG           TotalLength
    );

/**
 * Invoked on OID_DOT11_ENABLED_AUTHENTICATION_ALGORITHM query
 * 
 * \param pStation              STATION structure
 * \param pAuthAlgoList         Structure to populate
 * \param TotalLength           Total length of the structure
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryEnabledAuthenticationAlgorithm(
    IN  PSTATION        pStation,
    OUT PDOT11_AUTH_ALGORITHM_LIST  pAuthAlgoList,
    IN  ULONG           TotalLength
    );

/**
 * Invoked to OID_DOT11_SUPPORTED_UNICAST_ALGORITHM_PAIR query
 * 
 * \param pStation              STATION structure
 * \param pAuthCipherList       Structure to populate
 * \param TotalLength           Total length of the structure
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QuerySupportedUnicastAlgorithmPair(
    IN  PSTATION        pStation,
    OUT PDOT11_AUTH_CIPHER_PAIR_LIST    pAuthCipherList,
    IN  ULONG           TotalLength
    );

/**
 * Invoked on OID_DOT11_SUPPORTED_MULTICAST_ALGORITHM_PAIR query
 * 
 * \param pStation              STATION structure
 * \param pAuthCipherList       Structure to populate
 * \param TotalLength           Total length of the structure
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QuerySupportedMulticastAlgorithmPair(
    IN  PSTATION        pStation,
    PDOT11_AUTH_CIPHER_PAIR_LIST    pAuthCipherList,
    IN  ULONG           TotalLength
    );

/**
 * Invoked on OID_DOT11_ENABLED_UNICAST_ALGORITHM_PAIR query
 * 
 * \param pStation              STATION structure
 * \param pAuthCipherList       Structure to populate
 * \param TotalLength           Total length of the structure
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryEnabledUnicastCipherAlgorithm(
    IN  PSTATION        pStation,
    OUT PDOT11_CIPHER_ALGORITHM_LIST  pAuthCipherList,
    IN  ULONG           TotalLength
    );
    
/**
 * Invoked on OID_DOT11_ENABLED_MULTICAST_ALGORITHM_PAIR query
 * 
 * \param pStation              STATION structure
 * \param pAuthCipherList       Structure to populate
 * \param TotalLength           Total length of the structure
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryEnabledMulticastCipherAlgorithm(
    IN  PSTATION        pStation,
    OUT PDOT11_CIPHER_ALGORITHM_LIST  pAuthCipherList,
    IN  ULONG           TotalLength
    );

/**
 * Invoked on OID_DOT11_CIPHER_DEFAULT_KEY_ID query
 * 
 * \param pStation              STATION structure
 * \param keyID                 caller allocated ULONG pointer to store the default keyID.
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryCipherDefaultKeyID(
    IN  PSTATION pStation,
    IN  PULONG keyID
    );

/**
 * Invoked on OID_DOT11_EXTSTA_CAPABILITY query
 * 
 * \param pStation              STATION structure
 * \param pDot11ExtStaCap       Structure to populate
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryExtStaCapability(
    IN  PSTATION        pStation,
    OUT PDOT11_EXTSTA_CAPABILITY   pDot11ExtStaCap
    );

/**
 * Invoked on OID_DOT11_EXCLUDE_UNENCRYPTED query. 
 * 
 * \param pStation              STATION structure
 * \param param                 caller allocated BOOLEAN pointer to store the parameter value.
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryExcludeUnencrypted(
    IN  PSTATION pStation,
    IN  PBOOLEAN param
    );

/**
 * Invoked on OID_DOT11_PRIVACY_EXEMPTION_LIST query. The MP functions
 * have already verified that buffer is big enough to
 * contain NumEntries privacy exemption list
 * 
 * 
 * \param pStation              STATION structure
 * \param list                  Privacy exemption list to populate
 * \param TotalLength           Total length of the structure
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryPrivacyExemptionList(
    IN  PSTATION                      pStation,
    OUT PDOT11_PRIVACY_EXEMPTION_LIST list,
    IN  ULONG                         TotalLength
    );

/**
 * Invoked on OID_DOT11_DATA_RATE_MAPPING_TABLE query
 * 
 * \param pStation              STATION structure
 * \param pDataRateMappingTable Structure to populate
 * \param TotalLength           Total length of structure
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryDataRateMappingTable(
    IN  PSTATION        pStation,
    OUT PDOT11_DATA_RATE_MAPPING_TABLE  pDataRateMappingTable,
    IN  ULONG           TotalLength
    );

/**
 * Invoked on OID_DOT11_POWER_MGMT_REQUEST query. 
 * 
 * \param pStation              STATION structure
 * \param PowerSavingLevel      Caller allocated ULONG pointer to store the power saving level
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryPowerMgmtRequest(
    IN  PSTATION pStation,
    IN  PULONG PowerSavingLevel
    );


/**
 * Invoked on OID_DOT11_IBSS_PARAMS query. 
 * 
 * \param pStation              STATION structure
 * \param InformationBuffer     Information buffer to fill the DOT11_IBSS_PARAMS structure into. This
 *                              structure is atleast DOT11_IBSS_PARAMS bytes long
 * \param InformationBufferLength   Length of information buffer
 * \param BytesWritten          Number of into Information Buffer
 * \param BytesNeeded           Number of bytes needed for filling DOT11_IBSS_PARAMS
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS 
Sta11QueryIBSSParameters(
    IN  PSTATION pStation,
    IN  PVOID InformationBuffer,
    IN  ULONG InformationBufferLength,
    IN OUT PULONG BytesWritten,
    IN OUT PULONG BytesNeeded
    );

/**
 * Invoked on OID_DOT11_HARDWARE_PHY_STATE query. 
 * 
 * \param pStation              STATION structure
 * \param pState                caller allocated BOOLEAN pointer to store the hardware PHY state 
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryHardwarePhyState(
    IN  PSTATION        pStation,
    OUT PBOOLEAN        pState
    );

/**
 * Invoked on OID_DOT11_DESIRED_PHY_LIST query. 
 * 
 * \param pStation              STATION structure
 * \param PhyIdList             PHY ID list structure to populate
 * \param TotalLength           Total length of structure
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryDesiredPhyList(
    IN  PSTATION        pStation,
    OUT PDOT11_PHY_ID_LIST  PhyIdList,
    IN  ULONG           TotalLength
    );

/**
 * Invoked on OID_DOT11_ACTIVE_PHY_LIST query. 
 * 
 * \param pStation              STATION structure
 * \param PhyIdList             PHY ID list structure to populate
 * \param TotalLength           Total length of structure
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryActivePhyList(
    IN  PSTATION        pStation,
    OUT PDOT11_PHY_ID_LIST  PhyIdList,
    IN  ULONG           TotalLength
    );

/**
 * Invoked on OID_DOT11_CURRENT_PHY_ID query. 
 * 
 * \param pStation              STATION structure
 * \param PhyId                 caller allocated ULONG pointer to store the current Phy ID
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryCurrentPhyId(
    IN  PSTATION        pStation,
    IN  PULONG          PhyId
    );

/**
 * Invoked on OID_DOT11_PMKID_LIST query. 
 * 
 * \param pStation              STATION structure
 * \param PMKIDList             PMKID list structure to populate
 * \param TotalLength           Total length of structure
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryPMKIDList(
    IN  PSTATION        pStation,
    OUT PDOT11_PMKID_LIST  PMKIDList,
    IN  ULONG           TotalLength
    );

/**
 * Invoked on OID_DOT11_MEDIA_STREAMING_ENABLED query. 
 * 
 * \param pStation              STATION structure
 * \param mediaStreamingEnabled caller allocated BOOLEAN pointer to store the current setting
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryMediaStreamingOption(
    IN  PSTATION        pStation,
    OUT PBOOLEAN        mediaStreamingEnabled
    );

/**
 * Invoked on OID_DOT11_UNREACHABLE_DETECTION_THRESHOLD query. 
 * 
 * \param pStation              STATION structure
 * \param threshold             caller allocated ULONG pointer to store the current threshold
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryUnreachableDetectionThreshold(
    IN  PSTATION        pStation,
    IN  PULONG          threshold
    );

/**
 * Invoked on OID_DOT11_UNICAST_USE_GROUP_ENABLED query. 
 * 
 * \param pStation              STATION structure
 * \param unicastUseGroupEnabled  caller allocated BOOLEAN pointer to store the current settting
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryUnicastUseGroupOption(
    IN  PSTATION        pStation,
    IN  PBOOLEAN        unicastUseGroupEnabled
    );
    
/**
 * Invoked on OID_DOT11_SAFE_MODE_ENABLED query. 
 * 
 * \param pStation              STATION structure
 * \param safeModeEnabled      caller allocated BOOLEAN pointer to store the current settting
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QuerySafeModeOption(
    IN  PSTATION        pStation,
    IN  PBOOLEAN        safeModeEnabled
    );

/**
 * Invoked on OID_DOT11_HIDDEN_NETWORK_ENABLED query. 
 * 
 * \param pStation              STATION structure
 * \param hiddenNetworkEnabled      caller allocated BOOLEAN pointer to store the current settting
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryHiddenNetworkOption(
    IN  PSTATION        pStation,
    IN  PBOOLEAN        hiddenNetworkEnabled
    );


/**
 * Invoked on OID_DOT11_STATISTICS query
 * 
 * \param pStation              STATION structure
 * \param pDot11Stats
 * \param InformationBufferLength
 * \param BytesWritten
 * \param BytesNeeded
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11QueryDot11Statistics(
    IN  PSTATION        pStation,
    IN PDOT11_STATISTICS pDot11Stats,
    IN ULONG InformationBufferLength,
    OUT PULONG BytesWritten,
    OUT PULONG BytesNeeded
    );

/**
 * Invoked on OID_DOT11_DESIRED_BSS_TYPE set 
 * 
 * \param pStation              STATION structure
 * \param bssType               The BSS type as requested by the OS
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetDesiredBSSType(
    IN  PSTATION        pStation,
    IN  DOT11_BSS_TYPE  bssType
    );


/**
 * Invoked on OID_DOT11_CURRENT_OPERATION_MODE set 
 * 
 * \param pStation              STATION structure
 * \param currentOperationMode  The operation mode as requested by the OS
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetOperationMode(
    IN  PSTATION        pStation,
    IN  PDOT11_CURRENT_OPERATION_MODE currentOperationMode
    );
    

/**
 * Invoked on OID_DOT11_DESIRED_SSID_LIST set. The MP functions
 * have already verified that buffer is big enough to
 * contain NumEntries SSIDs
 * 
 * \param pStation              STATION structure
 * \param pDot11SSIDList        List of SSIDs to set
 * \param pBytesRead            Returns number of BytesRead
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetDesiredSSIDList(
    IN  PSTATION        pStation,
    IN  PDOT11_SSID_LIST    pDot11SSIDList,
    OUT PULONG          pBytesRead
    );

/**
 * Invoked on OID_DOT11_EXCLUDED_MAC_ADDRESS_LIST set. The MP functions
 * have already verified that buffer is big enough to
 * contain NumEntries MAC addresses
 * 
 * 
 * \param pStation              STATION structure
 * \param pDot11MacAddrList     List of MAC  addresses to populate
 * \param pBytesRead            Returns number of BytesRead
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetExcludedMACAddressList(
    IN  PSTATION        pStation,
    IN  PDOT11_MAC_ADDRESS_LIST pDot11MacAddrList,
    OUT PULONG          pBytesRead
    );

/**
 * Invoked on OID_DOT11_DESIRED_BSSID_LIST set. The MP functions
 * has already verified that buffer is big enough to
 * contain NumEntries BSSIDs
 * 
 * \param pStation              STATION structure
 * \param pDot11BSSIDList       List of BSSIDs
 * \param pBytesRead            Returns number of BytesRead
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetDesiredBSSIDList(
    IN  PSTATION        pStation,
    IN  PDOT11_BSSID_LIST   pDot11BSSIDList,
    OUT PULONG          pBytesRead
    );

/**
 * Invoked on OID_DOT11_ENABLED_AUTHENTICATION_ALGORITHMS set. 
 * The MP functions has already verified that buffer is big enough to
 * contain NumEntries auth algorithm pairs
 * 
 * \param pStation              STATION structure
 * \param pAuthAlgoList         List of Auth algorithms
 * \param pBytesRead            Returns number of BytesRead
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetEnabledAuthenticationAlgorithm(
    IN  PSTATION        pStation,
    IN  PDOT11_AUTH_ALGORITHM_LIST  pAuthAlgoList,
    OUT PULONG          pBytesRead
    );

/**
 * Invoked on OID_DOT11_ENABLED_UNICAST_CIPHER_ALGORITHM set. 
 * The MP functions has already verified that buffer is big enough to
 * contain NumEntries auth algorithm pairs
 * 
 * \param pStation              STATION structure
 * \param pCipherAlgoList       List of cipher algorithms
 * \param pBytesRead            Returns number of BytesRead
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetEnabledUnicastCipherAlgorithm(
    IN  PSTATION        pStation,
    IN  PDOT11_CIPHER_ALGORITHM_LIST  pCipherAlgoList,
    OUT PULONG          pBytesRead
    );

/**
 * Invoked on OID_DOT11_ENABLED_MULTICAST_CIPHER_ALGORITHM set. 
 * The MP functions has already verified that buffer is big enough to
 * contain NumEntries auth algorithm pairs
 * 
 * \param pStation              STATION structure
 * \param pCipherAlgoList       List of cipher algorithms
 * \param pBytesRead            Returns number of BytesRead
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetEnabledMulticastCipherAlgorithm(
    IN  PSTATION        pStation,
    IN  PDOT11_CIPHER_ALGORITHM_LIST  pCipherAlgoList,
    OUT PULONG          pBytesRead
    );

/**
 * Invoked on OID_DOT11_CIPHER_DEFAULT_KEY_ID set. 
 * 
 * \param pStation              STATION structure
 * \param keyID                 new default key ID
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetCipherDefaultKeyID(
    IN  PSTATION pStation,
    IN  ULONG keyID
    );

/**
 * Invoked on OID_DOT11_CIPHER_DEFAULT_KEY set. 
 * 
 * \param pStation              STATION structure
 * \param defaultKey            default key to be set
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetCipherDefaultKey(
    IN  PSTATION pStation,
    IN  PDOT11_CIPHER_DEFAULT_KEY_VALUE defaultKey
    );

/**
 * Invoked on OID_DOT11_CIPHER_KEY_MAPPING_KEY set. 
 * 
 * \param pStation              STATION structure
 * \param pKeyMappingKeys       a list of key mapping keys to be set
 * \param TotalLength           total length of all the keys in the list.
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetCipherKeyMappingKey(
    IN  PSTATION pStation,
    IN  PDOT11_CIPHER_KEY_MAPPING_KEY_VALUE pKeyMappingKeys,
    IN  ULONG TotalLength
    );

/**
 * Invoked on OID_DOT11_EXCLUDE_UNENCRYPTED set. 
 * 
 * \param pStation              STATION structure
 * \param param                 BOOLEAN param value
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetExcludeUnencrypted(
    IN  PSTATION pStation,
    IN  BOOLEAN param
    );

/**
 * Invoked on OID_DOT11_PRIVACY_EXEMPTION_LIST set. The MP functions
 * have already verified that buffer is big enough to
 * contain NumEntries privacy exemption list
 * 
 * 
 * \param pStation              STATION structure
 * \param list                  Privacy exemption list to populate
 * \param pBytesRead            Returns number of BytesRead
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetPrivacyExemptionList(
    IN  PSTATION                      pStation,
    IN  PDOT11_PRIVACY_EXEMPTION_LIST list,
    OUT PULONG              pBytesRead
    );

/**
 * Invoked on OID_DOT11_POWER_MGMT_REQUEST set. 
 * 
 * \param pStation              STATION structure
 * \param PowerSavingLevel      desired power saving level
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetPowerMgmtRequest(
    IN  PSTATION pStation,
    IN  ULONG PowerSavingLevel
    );

/**
 * Invoked on OID_DOT11_IBSS_PARAMS set. 
 * 
 * \param pStation              STATION structure
 * \param pDot11IBSSParams      The IBSS configuration parameters to set
 * \param BytesRead             Number of bytes read
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetIBSSParameters(
    IN  PSTATION pStation,
    IN  PDOT11_IBSS_PARAMS pDot11IBSSParams,
    OUT PULONG BytesRead
    );

/**
 * Invoked on OID_DOT11_DESIRED_PHY_LIST set. 
 * 
 * \param pStation              STATION structure
 * \param PhyIdList             PHY ID list structure to set
 * \param BytesRead             Number of bytes read
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetDesiredPhyList(
    IN  PSTATION            pStation,
    IN  PDOT11_PHY_ID_LIST  PhyIdList,
    OUT PULONG              BytesRead
    );

/**
 * Invoked on OID_DOT11_CURRENT_PHY_ID set. 
 * 
 * \param pStation              STATION structure
 * \param PhyId                 PHY ID to set
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetCurrentPhyId(
    IN  PSTATION        pStation,
    IN  ULONG           PhyId
    );

/**
 * Invoked on OID_DOT11_MEDIA_STREAMING_ENABLED set. 
 * 
 * \param pStation              STATION structure
 * \param mediaStreamingEnabled new media streaming setting
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetMediaStreamingOption(
    IN  PSTATION        pStation,
    IN  BOOLEAN         mediaStreamingEnabled
    );

/**
 * Invoked on OID_DOT11_PMKID_LIST set. 
 * 
 * \param pStation              STATION structure
 * \param PMKIDList             PMKID list structure to set
 * \param BytesRead             Number of bytes read
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetPMKIDList(
    IN  PSTATION            pStation,
    IN  PDOT11_PMKID_LIST  PMKIDList,
    OUT PULONG              BytesRead
    );

/**
 * Invoked on OID_DOT11_UNREACHABLE_DETECTION_THRESHOLD set. 
 * 
 * \param pStation              STATION structure
 * \param threshold             New threshold to set to
 *
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetUnreachableDetectionThreshold(
    IN  PSTATION        pStation,
    IN  ULONG           threshold
    );

/**
 * Invoked on OID_DOT11_UNICAST_USE_GROUP_ENABLED set. 
 * 
 * \param pStation              STATION structure
 * \param unicastUseGroupEnabled      The new value for unicast use group enabled
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetUnicastUseGroupOption(
    IN  PSTATION pStation,
    IN  BOOLEAN  unicastUseGroupEnabled
    );

/**
 * Invoked on OID_DOT11_SAFE_MODE_ENABLED set. 
 * 
 * \param pStation              STATION structure
 * \param safeModeEnabled      The new safe mode setting
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetSafeModeOption(
    IN  PSTATION pStation,
    IN  BOOLEAN  safeModeEnabled
    );

/**
 * Invoked on OID_DOT11_HIDDEN_NETWORK_ENABLED set. 
 * 
 * \param pStation              STATION structure
 * \param hiddenNetworkEnabled      The new safe mode setting
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11SetHiddenNetworkOption(
    IN  PSTATION pStation,
    IN  BOOLEAN  hiddenNetworkEnabled
    );

/**
 * Invoked on OID_DOT11_SCAN_REQUEST.
 * 
 * \param pStation              STATION structure
 * \param ScanRequestID         The ID to use when completing the scan request
 * \param pDot11ScanRequest     The V2 scan request structure
 * \param ScanRequestBufferLength  Length of request buffer
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11StartScan(
    IN  PSTATION            pStation,
    IN  PVOID               ScanRequestID,
    IN  PDOT11_SCAN_REQUEST_V2 pDot11ScanRequest,
    OUT ULONG               ScanRequestBufferLength
    );


/**
 * This function should be called by Mp when an outstanding scan operation completes.
 * Scan operations always pends and have to be completed asynchronously.
 * 
 * \param pStation          The STATION structure
 * \param ndisStatus        The success status of the scan request
 * \sa Sta11StartScan
 */
VOID
Sta11ScanComplete(
    IN  PSTATION        pStation,
    IN  NDIS_STATUS     ndisStatus
    );

/**
 * Initiates connection to an 802.11 infrastructure network. 
 * This function must return before the connection process has 
 * completed. Completion will be indicated by status indication
 * 
 * \param pStation              STATION structure
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11ConnectInfra(
    IN  PSTATION        pStation
    );


/**
 * Initiate disconnection from an 802.11 infrastructure network
 * 
 * \param pStation              STATION structure
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11DisconnectInfra(
    IN  PSTATION        pStation
    );

/**
 * Invoked once the hardware has synchronized with an access point or
 * has timed out waiting
 * 
 * \param pStation              STATION structure
 * \param ndisStatus            NDIS_STATUS from the Join attempt
 */
VOID
Sta11JoinCompleteInfra(
    IN  PSTATION        pStation,
    IN  NDIS_STATUS     ndisStatus
    );

/**
 * Initiates connection to an 802.11 independent (adhoc) network. 
 * This function must return before the connection process has 
 * completed. Completion will be indicated by status indication
 * 
 * \param pStation              STATION structure
 * \return NDIS_STATUS
 */
NTSTATUS
Sta11ConnectAdHoc(
    IN  PSTATION pStation
    );

/**
 * Initiate disconnection from an 802.11 independent (adhoc) network
 * 
 * \param pStation              STATION structure
 * \return NDIS_STATUS
 */
NTSTATUS
Sta11DisconnectAdHoc(
    IN  PSTATION pStation
    );

/**
 * Invoked once the hardware has synchronized with an Ad Hoc network or
 * has timed out waiting
 * 
 * \param pStation              STATION structure
 * \param ndisStatus            NDIS_STATUS from the Join attempt
 */

VOID
Sta11JoinCompleteAdHoc(
    IN  PSTATION pStation,
    IN  NDIS_STATUS ndisStatus
    );

/**
 * Invoked on an OID_DOT11_ENUM_ASSOCIATION_INFO query request
 * when the BSS type is set to infrastructure
 * 
 * \param pStation              STATION structure
 * \param pAssocInfoList        Buffer to fill association information into
 * \param TotalLength           Length of association information buffer
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11EnumerateAssociationInfoInfra(
    IN  PSTATION        pStation,
    OUT PDOT11_ASSOCIATION_INFO_LIST   pAssocInfoList,
    IN  ULONG           TotalLength
    );

/**
 * Invoked on an OID_DOT11_ENUM_ASSOCIATION_INFO query request
 * when the BSS type is set to adhoc
 * 
 * \param pStation              STATION structure
 * \param pAssocInfoList        Buffer to fill association information into
 * \param TotalLength           Length of association information buffer
 * \return NDIS_STATUS
 */
NDIS_STATUS
Sta11EnumerateAssociationInfoAdHoc(
    IN  PSTATION        pStation,
    OUT PDOT11_ASSOCIATION_INFO_LIST   pAssocInfoList,
    IN  ULONG           TotalLength
    );

/**
 * 
 * This function is called when a packet to be sent is submitted to
 * the miniport driver. This function can perform a number of operations
 * on the packet being sent. Please be careful about major operations
 * like subsuming packets etc. as they may affect the operation of the
 * rest of the miniport driver.
 * 
 * \param pStation              STATION structure
 * \param pNetBufferList        The NetBufferList submitted to the driver
 * \param SendFlags             Send flags such a dispatch level, etc
 * \param pDot11SendContext     The send context for this packet
 *
 * \return NDIS_STATUS_SUCCESS if this packet has been subsumed by this function.
 * Responsibility for sending and send completing this packet is on this function.
 * NDIS_STATUS_NOT_RECOGNIZED be returned if this packet is to process normally.
 * Any other status will be treated as failure and packet failed back to the OS.
 */
NDIS_STATUS
Sta11SendNetBufferList(
    IN  PSTATION        pStation,
    IN  PNET_BUFFER_LIST    pNetBufferList,
    IN  ULONG           SendFlags,
    IN  PDOT11_EXTSTA_SEND_CONTEXT  pSendContext
    );


/**
 * Determine if the station can send packets at this time or not. This is generally used
 * to block sending during scanning, etc. If this returns FALSE, the MP portion
 * will queue the packets up for later sending. If true, the Sta11ProcessSend routine 
 * will be called to start sending
 *
 * \param pStation              STATION structure
 * \return TRUE if the station can send packets at this time. FALSE otherwise
 */
BOOLEAN
Sta11CanTransmit(
    IN  PSTATION        pStation
    );


/**
 * This function is called just before a NET_BUFFER_LIST is going to
 * be submitted to hardware for sending. This function can update the MP_TX_MSDU 
 * structure with information that it wants the hardware portion to look
 * at when sending the packet out.
 * 
 * \param pStation              STATION structure
 * \param pMpTxd                The MSDU descriptor the packet to be transmitted
 *
 */
VOID
Sta11ProcessSend(
    IN  PSTATION        pStation,
    IN  PMP_TX_MSDU     pMpTxd
    );

/*
 * This function is called to notify when a send complete has occured and
 * is about to relayed to NDIS. Note that this function is only called
 * for TX MSDU that were actually handed to the hardware. Packets failed because
 * of issues that prevented us from ever handing the packet to the hardware
 * may not be provided to this API.
 *
 * \param   pStation            STATION structure
 * \param   pTxd                The TX MSDU completing
 * \param   ndisStatus          Completion status for this packet
 */
VOID 
Sta11ProcessSendComplete(
    IN  PSTATION        pStation,
    IN  PMP_TX_MSDU     pMpTxd,
    IN  NDIS_STATUS     ndisStatus
    ); 

/*
 * This function is called fill the station portion of the 
 * NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES structure.
 *
 * \param   pStation            STATION structure
 * \param   attr                NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES structure
 */
NDIS_STATUS
Sta11Fill80211Attributes(
    IN  PSTATION        pStation,
    OUT PNDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES attr
    );

/*
 * This function is called cleanup the station portion of the 
 * NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES structure.
 *
 * \param   pStation            STATION structure
 * \param   attr                NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES structure
 */
VOID
Sta11Cleanup80211Attributes(
    IN PSTATION        pStation,
    IN PNDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES attr
    );

/*
 * This function is called by hardware layer to indicate MIC failure
 *
 * \param   pStation            STATION structure
 * \param   Header              802.11 header of the data frame in which MIC failure was detected
 * \param   KeyId               KeyId of the default key on which MIC failure was detected
 * \param   IsDefaultKey        Indicating if the key on which MIC failure was detected is a default key
 */
VOID
Sta11IndicateMICFailure(
    IN PSTATION                 pStation,
    IN PDOT11_DATA_SHORT_HEADER Header,
    IN ULONG                    KeyId,
    IN BOOLEAN                  IsDefaultKey
    );

// Invoked when the OID_PNP_SET_POWER is received to put device to sleep. This is
// called before hardware is called
VOID
Sta11PowerSleep(
    IN PSTATION                 pStation,
    IN NDIS_DEVICE_POWER_STATE  NewDeviceState
    );

// Invoked when the OID_PNP_SET_POWER is received to wake up device (being set to 
// NdisDeviceStateD0) . This is called after hardware is called and ready
VOID
Sta11PowerWakeup(
    IN PSTATION                 pStation
    );

VOID
Sta11NotifyEventRoamForSendFailures(
    IN  PSTATION        pStation
    );

VOID
Sta11NotifyEventUpdateLinkQuality(
    IN  PSTATION        pStation,
    IN  BOOLEAN         bState
    );

#endif //_STATION_INTERFACE_H


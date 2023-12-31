/*++

Copyright (C) Microsoft Corporation, 2004

Module Name:

    ahci_reg.h

Abstract:



Notes:

Revision History:

        Nathan Obr (natobr),  February 2005
--*/

#pragma once

typedef union _AHCI_DATA_BASE_ADDRESS {

    struct {
        ULONG DBA :31; //Data Base Address:Indicates the 32-bit physical address of the data block. The block must be word aligned, indicated by bit 0 being reserved.
        ULONG DW0_Reserved :1; 
    };
    
    ULONG AsUlong;

} AHCI_DATA_BASE_ADDRESS, *PAHCI_DATA_BASE_ADDRESS;
typedef union _AHCI_PRDT_DESCRIPTION_INFORMATION {
    
    struct {
        //LSB
        ULONG DBC :22; //Data Byte Count: A ?0 based value that Indicates the length, in bytes, of the data block. A maximum of length of 4MB may exist for any entry. Bit ?0 of this field must always be ?1 to indicate an even byte count. A value of ?1 indicates 2 bytes, ?3 indicates 4 bytes, etc.
        ULONG DW3_Reserved :9;
        ULONG I :1; //Interrupt on Completion: When set, indicates that hardware should assert an interrupt when the data block for this entry has transferred, which means that no data is in the HBA hardware. Data may still be in flight to system memory (disk reads), or at the device (an R_OK or R_ERR has yet to be received). The HBA shall set the PxIS.DPS bit after completing the data transfer, and if enabled, generate an interrupt.
    };    //MSB

    ULONG AsUlong;

} AHCI_PRDT_DESCRIPTION_INFORMATION, *PAHCI_PRDT_DESCRIPTION_INFORMATION;

//Physical Region Descriptor Table as defined in AHCI1.0 section 4.2.3.3
typedef struct _AHCI_PRDT {     

    //DW 0 ? Data Base Address
    AHCI_DATA_BASE_ADDRESS DBA;

    //DW 1 ? Data Base Address Upper
    ULONG DBAU; //Data Base Address Upper 32-bits: This is the upper 32-bits of the data block physical address. It is only valid if the HBA indicated that it can support 64-bit addressing through the S64A bit in the capabilities register, and is ignored otherwise. 
    
    //DW 2 ? Reserved
    ULONG Reserved;

    //DW 3 ? Description Information
    AHCI_PRDT_DESCRIPTION_INFORMATION DI;

} AHCI_PRDT, *PAHCI_PRDT;

//Command Table as defined in AHCI1.0 section 4.2.3
typedef struct _AHCI_COMMAND_TABLE {
    
    AHCI_H2D_REGISTER_FIS CFIS;//[20]//AHCI1.0 section 4.2.3.1 Command FIS (CFIS): This is a software constructed FIS. For data transfer operations, this is the H2D Register FIS format as specified in the Serial ATA 1.0a specification. The HBA sets PxTFD.STS.BSY, and then sends this structure to the attached port. If a Port Multiplier is attached, this field must have the Port Multiplier port number in the FIS itself it shall not be added by the HBA. Valid CFIS lengths are 2 to 16 Dwords and must be in Dword granularity.  
    UCHAR CFIS_Padding[44];  
    UCHAR ACMD[16];  //AHCI1.0 section 4.2.3.2 ATAPI Command (ACMD): This is a software constructed region of 12 or 16 bytes in length that contains the ATAPI command to transmit if the ?A? bit is set in the command header. The ATAPI command must be either 12 or 16 bytes in length. The length transmitted by the HBA is determined by the PIO setup FIS that is sent by the device requesting the ATAPI command.
    UCHAR Reserved1[48];
    AHCI_PRDT PRDT[33]; //elements in a sglist are 4K (except for maybe the first and last one). Ataport will not send more than 128K, therefore no more than 33 PRD entries.
                        //if the PRD Table had 32 entries this structure would come out to 640 which has nice 128 byte alignment (required for all instances of these structures),
    UCHAR Reserved2[112];//but since it has 33 entries it comes out to 656.  another 112 bytes at the end is needed to restore 128 byte alignment and make the structure 768 bytes

} AHCI_COMMAND_TABLE, *PAHCI_COMMAND_TABLE;

typedef union _AHCI_COMMAND_TABLE_BASE_ADDRESS {

    struct {
        //LSB
        ULONG DW2_Reserved :7;//128 byte alignment
        ULONG CTBA :25; //Command Table Descriptor Base Address: Indicates the 32-bit physical address of the command table, which contains the command FIS, ATAPI Command, and PRD table. This address must be aligned to a 128-byte cache line, indicated by bits 06:00 being reserved.
        //MSB
    };

    ULONG AsUlong;

} AHCI_COMMAND_TABLE_BASE_ADDRESS, AHCI_COMMAND_TABLE_BASE_ADDRESS;

typedef union _AHCI_COMMAND_HEADER_DESCRIPTION_INFORMATION {    
    
    struct {
        //LSB
        ULONG CFL :5;//Command FIS Length: Length of the Command FIS. A ?0 represents 0 DW, ?4 represents 4 DW. A length of ?0 or ?1 is illegal. The maximum value allowed is 10h, or 16 DW. The HBA uses this field to know the length of the FIS it shall send to the device.
        ULONG A :1;//ATAPI: When ?1 , indicates that a PIO setup FIS shall be sent by the device indicating a transfer for the ATAPI command. The HBA may prefetch data from CTBAz[ACMD] in anticipation of receiving the PIO Setup FIS.
        ULONG W :1;//Write: When set, indicates that the direction is a device write (data from system memory to device). When cleared, indicates that the direction is a device read (data from device to system memory). If this bit is set and the P bit is set, the HBA may prefetch data in anticipation of receiving a DMA Setup FIS, a DMA Activate FIS, or PIO Setup FIS, in addition to prefetching PRDs.
        ULONG P :1;//Prefetchable: This bit is only valid if the PRDTL field is non-zero. When set and PRDTL is non-zero, the HBA may prefetch PRDs in anticipation of performing a data transfer. System software should not set this bit when using native command queuing commands. Note: The HBA may prefetch the ATAPI command, PRD entries, and data regardless of the state of this bit. However, it is recommended that the HBA use this information from software to avoid prefetching needlessly.
        
        ULONG R :1;//Reset: When ?1 , indicates that the command that software built is for a device reset. The HBA must perform a SYNC escape (if necessary) to get the device into an idle state before sending the command. See section 10.4 for details on reset.
        ULONG B :1;//BIST: When ?1 , indicates that the command that software built is for sending a BIST FIS. The HBA shall send the FIS and enter a test mode. The tests that can be run in this mode are outside the scope of this specification.
        ULONG C :1;//Clear Busy upon R_OK: When set, the HBA shall clear PxTFD.STS.BSY and PxCI.CI(z) after transmitting this FIS and receiving R_OK. When cleared, the HBA shall not clear PxTFD.STS.BSY nor PxCI.CI(z) after transmitting this FIS and receiving R_OK.
        ULONG DW0_Reserved :1;        
        ULONG PMP :4;//Port Multiplier Port: Indicates the port number that should be used when constructing data FISes on transmit, and to check against all FISes received for this command. This value must be set to 0h if a Port Multiplier is not attached (PxCMD.PMA is ?0 ).
        
        ULONG PRDTL :16;//Physical Region Descriptor Table Length: Length of the scatter/gather descriptor table in entries, called the Physical Region Descriptor Table. Each entry is 4 DW. A ?0 represents 0 entries, FFFFh represents 65,535 entries. The HBA uses this field to know when to stop fetching PRDs. If this field is ?0 , then no data transfer shall occur with the command.
        //MSB
    };

    ULONG AsUlong;

}  AHCI_COMMAND_HEADER_DESCRIPTION_INFORMATION, *PAHCI_COMMAND_HEADER_DESCRIPTION_INFORMATION;

//Command Header as defined in AHCI1.0 section 4.2.2
typedef struct _AHCI_COMMAND_HEADER {

    //DW 0 - Description Information
    AHCI_COMMAND_HEADER_DESCRIPTION_INFORMATION DI;

    //DW 1 - Command Status
    ULONG PRDBC; //Physical Region Descriptor Byte Count: Indicates the current byte count that has transferred on device writes (system memory to device) or device reads (device to system memory). For rules on when this field is updated, refer to section 5.3.1

    //DW 2 - Command Table Base Address
    AHCI_COMMAND_TABLE_BASE_ADDRESS CTBA;

    //DW 3 - Command Table Base Address Upper
    ULONG CTBAU; //Command Table Descriptor Base Address Upper 32-bits: This is the upper 32-bits of the Command Table Base. It is only valid if the HBA indicated that it can support 64-bit addressing through the S64A bit in the capabilities register, and is ignored otherwise.

    ULONG Reserved[4];

} AHCI_COMMAND_HEADER, *PAHCI_COMMAND_HEADER; 

//Received FIS as defined in AHCI1.0 section 4.2.1
//AHCI_PORT->FBU:FB points to the AHCI_RECEIVED_FIS
typedef struct _AHCI_RECEIVED_FIS{
   
    AHCI_DMA_SETUP_FIS DmaSetupFis;    //When a DMA setup FIS arrives from the device, the HBA copies it to the DSFIS area of this structure.        
    UCHAR Reserved1[4];    
    AHCI_PIO_SETUP_FIS PioSetupFis;    //When a PIO setup FIS arrives from the device, the HBA copies it to the PSFIS area of this structure. 
    UCHAR Reserved2[12];    
    AHCI_D2H_REGISTER_FIS D2hRegisterFis;        //When a D2H Register FIS arrives from the device, the HBA copies it to the RFIS area of this structure. 
    UCHAR Reserved3[4];
    AHCI_SET_DEVICE_BITS_FIS SetDeviceBitsFis;    //When a Set Device Bits FIS arrives from the device, the HBA copies it to the SDBFIS area of this structure. 
    AHCI_UNKNOWN_FIS UnknownFis;        //When an unknown FIS arrives from the device, the HBA copies it to the UFIS area in this structure, and sets PxSERR.DIAG.F, which is reflected in PxIS.UFS when the FIS is posted to memory. A maximum of 64-bytes of an unknown FIS type may be sent to an HBA. If an unknown FIS arrives that is longer than 64-bytes, the FIS is considered illegal and is handled as described in section 6.1.2. While the length of the FIS is unknown to the HBA, it is expected to be known by system software, and therefore only the valid bytes shall be processed by software. The HBA is not required to tolerate receiving an unknown FIS when the HBA is expecting a Data FIS from the device or when the HBA is about to transfer a Data FIS to the device based on the command protocol being used.
    UCHAR Reserved4[96];

}  AHCI_RECEIVED_FIS, *PAHCI_RECEIVED_FIS;



//Command List Base Address as defined in AHCI section 3.3.1
typedef union _AHCI_COMMAND_LIST_BASE_ADDRESS { //Port Command List Base Address as defined in AHCI1.0 section 3.3.1 
    struct {     
        //LSB
        ULONG DW0_Reserved :10; //1K alignment
        ULONG CLB :22; //Command List Base Address: Indicates the 32-bit base physical address for the command list for this port. This base is used when fetching commands to execute. The structure pointed to by this address range is 1K-bytes in length. This address must be 1K-byte aligned as indicated by bits 09:00 being read only.        
        //MSB
    };

    ULONG AsUlong;

} AHCI_COMMAND_LIST_BASE_ADDRESS, *PAHCI_COMMAND_LIST_BASE_ADDRESS;

//FIS Base Address as defined in AHCI sectin 3.3.3
typedef union _AHCI_FIS_BASE_ADDRESS { //FIS Base Address as defined in AHCI1.0 section 3.3.3
    struct {
        //LSB
        ULONG DW2_Reserved :8; //256 byte alignment
        ULONG FB :24; //FIS Base Address: Indicates the 32-bit base physical address for received FISes. The structure pointed to by this address range is 256 bytes in length. This address must be 256-byte aligned as indicated by bits 07:00 being read only.
        //MSB
    };

    ULONG AsUlong;

}  AHCI_FIS_BASE_ADDRESS, *PAHCI_FIS_BASE_ADDRESS;

//Interrupt Status as defined in AHCI section 3.3.5
typedef union _AHCI_INTERRUPT_STATUS {

    struct {
        //LSB
        ULONG DHRS:1; //Device to Host Register FIS Interrupt: A D2H Register FIS has been received with the 'I' bit set, and has been copied into system memory.
        ULONG PSS :1; //PIO Setup FIS Interrupt: A PIO Setup FIS has been received with the 'I' bit set, it has been copied into system memory, and the data related to that FIS has been transferred. This bit shall be set even if the data transfer resulted in an error.
        ULONG DSS :1; //DMA Setup FIS Interrupt: A DMA Setup FIS has been received with the 'I' bit set and has been copied into system memory.
        ULONG SDBS :1; //Set Device Bits Interrupt: A Set Device Bits FIS has been received with the 'I' bit set and has been copied into system memory.
        ULONG UFS :1; //Unknown FIS Interrupt: When set to '1 , indicates that an unknown FIS was received and has been copied into system memory. This bit is cleared to ?0 by software clearing the PxSERR.DIAG.F bit to ?0 . Note that this bit does not directly reflect the PxSERR.DIAG.F bit. PxSERR.DIAG.F is set immediately when an unknown FIS is detected, whereas this bit is set when that FIS is posted to memory. Software should wait to act on an unknown FIS until this bit is set to ?1 or the two bits may become out of sync.
        ULONG DPS :1; //Descriptor Processed: A PRD with the 'I' bit set has transferred all of its data. Refer to section 5.3.2.
        ULONG PCS :1; //Port Connect Change Status: 1=Change in Current Connect Status. 0=No change in Current Connect Status. This bit reflects the state of PxSERR.DIAG.X. This bit is only cleared when PxSERR.DIAG.X is cleared.
        ULONG DMPS :1; //Device Mechanical Presence Status (DMPS): When set, indicates that a mechanical presence switch attached to this port has been opened or closed, which may lead to a change in the connection state of the device.  This bit is only valid if both CAP.SMPS and P0CMD.MPSP are set to 1.
        ULONG DW4_Reserved :14; 
        ULONG PRCS :1; //PhyRdy Change Status: When set to '1 indicates the internal PhyRdy signal changed state. This bit reflects the state of P0SERR.DIAG.N. To clear this bit, software must clear P0SERR.DIAG.N to ?0 .
        ULONG IPMS :1; //Incorrect Port Multiplier Status: Indicates that the HBA received a FIS from a device whose Port Multiplier field did not match what was expected.  The IPMS bit may be set during enumeration of devices on a Port Multiplier due to the normal Port Multiplier enumeration process.  It is recommended that IPMS only be used after enumeration is complete on the Port Multiplier.
        ULONG OFS :1; //Overflow Status: Indicates that the HBA received more bytes from a device than was specified in the PRD table for the command.
        ULONG DW4_Reserved2 :1;
        ULONG INFS :1; //Interface Non-fatal Error Status: Indicates that the HBA encountered an error on the Serial ATA interface but was able to continue operation. Refer to section 6.1.2.
        ULONG IFS :1; //Interface Fatal Error Status: Indicates that the HBA encountered an error on the Serial ATA interface which caused the transfer to stop. Refer to section 6.1.2.
        ULONG HBDS :1; //Host Bus Data Error Status: Indicates that the HBA encountered a data error (uncorrectable ECC / parity) when reading from or writing to system memory.
        ULONG HBFS :1; //Host Bus Fatal Error Status: Indicates that the HBA encountered a host bus error that it cannot recover from, such as a bad software pointer. In PCI, such an indication would be a target or master abort.
        ULONG TFES :1; //Task File Error Status: This bit is set whenever the status register is updated by the device and the error bit (bit 0) is set.
        ULONG CPDS :1; //Cold Port Detect Status: When set, a device status has changed as detected by the cold presence detect logic. This bit can either be set due to a non-connected port receiving a device, or a connected port having its device removed. This bit is only valid if the port supports cold presence detect as indicated by PxCMD.CPD set to ?1 .    
        //MSB
    };

    ULONG AsUlong;

}  AHCI_INTERRUPT_STATUS, *PAHCI_INTERRUPT_STATUS;

//Interrupt Enable as defined in AHCI1.0 section 3.3.6
typedef union _AHCI_INTERRUPT_ENABLE {

    struct {
        //LSB
        ULONG DHRE :1; // Device to Host Register FIS Interrupt Enable: When set, GHC.IE is set, and P0IS.DHRS is set, the HBA shall generate an interrupt.
        ULONG PSE :1; // PIO Setup FIS Interrupt Enable: When set, GHC.IE is set, and P0IS.PSS is set, the HBA shall generate an interrupt.
        ULONG DSE :1; // DMA Setup FIS Interrupt Enable: When set, GHC.IE is set, and P0IS.DSS is set, the HBA shall generate an interrupt.
        ULONG SDBE :1; // Set Device Bits FIS Interrupt Enable: When set, GHC.IE is set, and P0IS.SDBS is set, the HBA shall generate an interrupt.
        ULONG UFE :1; // Unknown FIS Interrupt Enable: When set, GHC.IE is set, and P0IS.UFS is set to ?1 , the HBA shall generate an interrupt.
        ULONG DPE :1; // Descriptor Processed Interrupt Enable: When set, GHC.IE is set, and P0IS.DPS is set, the HBA shall generate an interrupt.
        ULONG PCE :1; // Port Change Interrupt Enable: When set, GHC.IE is set, and P0IS.PCS is set, the HBA shall generate an interrupt.
        ULONG DMPE :1; //Device Mechanical Presence Enable (DMPE): When set, and GHC.IE is set to 1, and P0IS.DMPS is set, the HBA shall generate an interrupt.  For systems that do not support a mechanical presence switch, this bit shall be a read-only 0.
        ULONG DW5_Reserved :14; // 
        ULONG PRCE :1; // PhyRdy Change Interrupt Enable: When set to ?1 , and GHC.IE is set to ?1 , and P0IS.PRCS is set to ?1 , the HBA shall generate an interrupt.
        ULONG IPME :1; // Incorrect Port Multiplier Enable: When set, and GHC.IE and P0IS.IPMS are set, the HBA shall generate an interupt.
        ULONG OFE :1; // Overflow Enable: When set, and GHC.IE and P0IS.OFS are set, the HBA shall generate an interupt.
        ULONG DW5_Reserved2 :1; // 
        ULONG INFE :1; // Interface Non-fatal Error Enable: When set, GHC.IE is set, and P0IS.INFS is set, the HBA shall generate an interrupt.
        ULONG IFE :1; // Interface Fatal Error Enable: When set, GHC.IE is set, and P0IS.IFS is set, the HBA shall generate an interrupt..
        ULONG HBDE :1; // Host Bus Data Error Enable: when set, GHC.IE is set, and P0IS.HBDS is set, the HBA shall generate an interrupt..
        ULONG HBFE :1; // Host Bus Fatal Error Enable: When set, GHC.IE is set, and P0IS.HBFS is set, the HBA shall generate an interrupt.
        ULONG TFEE :1; // Task File Error Enable: When set, GHC.IE is set, and P0S.TFES is set, the HBA shall generate an interrupt.
        ULONG CPDE :1; //Cold Presence Detect Enable: When set, GHC.IE is set, and P0S.CPDS is set, the HBA shall generate an interrupt. For systems that do not support cold presence detect, this bit shall be a read-only ?0 .
        //MSB
    };

    ULONG AsUlong;

} AHCI_INTERRUPT_ENABLE, *PAHCI_INTERRUPT_ENABLE;

//Command and Status as defined in AHCI1.0 section 3.3.7
typedef union _AHCI_COMMAND {

    struct {
        //LSB
        ULONG ST :1; // Start: When set, the HBA may process the command list. When cleared, the HBA may not process the command list. Whenever this bit is changed from a ?0 to a, the HBA starts processing the command list at entry ?0 . Whenever this bit is changed from a ?1 to a ?0 , the PxCI register is cleared by the HBA upon the HBA putting the controller into an idle state. This bit shall only be set to 1 by software after PxCMD.FRE has been set to 1. Refer to section 10.3.1 for important restrictions on when ST can be set to ?1 .
        ULONG SUD :1; // Spin-Up Device: This bit is read/write for HBAs that support staggered spin-up via CAP.SSS. This bit is read only ?1 for HBAs that do not support staggered spin-up. On an edge detect from ?0 to ?1 , the HBA shall start a COMRESET initializatoin sequence to the device. Clearing this bit to 0 does not cause any OOB signal to be sent on the interface.  When this bit is cleared to 0 and PxSCTL.DET=0h, the HBA will enter listen mode as detailed in section 10.9.1.
        ULONG POD :1; // Power On Device: This bit is read/write for HBAs that support cold presence detection on this port as indicated by PxCMD.CPD set to ?1 . This bit is read only ?1 for HBAs that do not support cold presence detect. When set, the HBA sets the state of a pin on the HBA to ?1 so that it may be used to provide power to a cold-presence detectable port.
        ULONG CLO :1; // Command List Override: Setting this bit to ?1 causes PxTFD.STS.BSY and PxTFD.STS.DRQ to be cleared to ?0 . This allows a software reset to be transmitted to the device regardless of whether the BSY and DRQ bits are still set in the PxTFD.STS register. The HBA sets this bit to ?0 when PxTFD.STS.BSY and PxTFD.STS.DRQ have been cleared to ?0 . A write to this register with a value of ?0 shall have no effect. This bit shall only be set to ?1 immediately prior to setting the PxCMD.ST bit to ?1 from previous value of ?0 . Setting this bit to ?1 at any other time is not supported and will result in indeterminate behavior.
        ULONG FRE :1; // FIS Receive Enable: When set, the HBA may post received FISes into the FIS receive area pointed to by PxFB (and for 64-bit HBAs, PxFBU). When cleared, received FISes are not accepted by the HBA, except for the first D2H register FIS after the initialization sequence, and no FISes are posted to the FIS receive area. System software must not set this bit until PxFB (PxFBU) have been programmed with valid pointer to the FIS receive area, and if software wishes to move the base, this bit must first be cleared, and software must wait for the FR bit in this register to be cleared. Refer to section 10.3.2 for important restrictions on when FRE can be set and cleared.
        ULONG DW6_Reserved :3; // 

        ULONG CCS :5; // Current Command Slot: This field is valid when P0CMD.ST is set to ?1 and shall be set to the command slot value of the command that is currently being issued by the HBA. When P0CMD.ST transitions from ?1 to ?0 , this field shall be reset to ?0 . After P0CMD.ST transitions from ?0 to ?1 , the highest priority slot to issue from next is command slot 0. After the first command has been issued, the highest priority slot to issue from next is P0CMD.CCS + 1. For example, after the HBA has issued its first command, if CCS = 0h and P0CI is set to 3h, the next command that will be issued is from command slot 1.
        ULONG MPSS :1; // Mechanical Presence Switch State: The MPSS bit reports the state of an interlocked switch attached to this port. If CAP.SIS is set to ?1? and the interlocked switch is closed then this bit is cleared to ?0 . If CAP.SIS is set to ?1 and the interlocked switch is open then this bit is set to ?1 . If CAP.SIS is set to ?0 then this bit is cleared to ?0 . Software should only use this bit if both CAP.SIS and P0CMD.ISP are set to ?1 .
        ULONG FR :1; // FIS Receive Running: When set, the FIS Receive DMA engine for the port is running. See section 10.3.2 for details on when this bit is set and cleared by the HBA.
        ULONG CR :1; // Command List Running: When this bit is set, the command list DMA engine for the port is running. See the AHCI state machine in section 5.2.2 for details on when this bit is set and cleared by the HBA.

        ULONG CPS :1; // Cold Presence State: The CPS bit reports whether a device is currently detected on this port. If CPS is set to ?1 , then the HBA detects via cold presence that a device is attached to this port. If CPS is cleared to ?0 , then the HBA detects via cold presence that there is no device attached to this port.
        ULONG PMA :1; // Port Multiplier Attached: This bit is read/write for HBAs that support a Port Multiplier (CAP.SPM = ?1 ). This bit is read-only for HBAs that do not support a port Multiplier (CAP.SPM = ?0 ). When set to ?1 by software, a Port Multiplier is attached to the HBA for this port. When cleared to ?0 by software, a Port Multiplier is not attached to the HBA for this port. Software is responsible for detecting whether a Port Multiplier is present; hardware does not auto-detect the presence of a Port Multiplier.
        ULONG HPCP :1; // Hot Plug Capable Port:  When set to 1, indicates that this ports signal and power connectors are externally accessible via a joint signal and power connector for blindmate device hot plug.  When cleared to 0, indicates that this ports signal and power connectors are not externally accessible via a joint signal and power connector.
        ULONG MPSP :1; // Mechanical Presence Switch Attached to Port : If set to ?1 , the platform supports an interlocked switch attached to this port. If cleared to ?0 , the platform does not support an interlocked switch attached to this port. When this bit is set to ?1 , P0CMD.HPCP should also be set to ?1 .
        ULONG CPD :1; // Cold Presence Detection: If set to ?1 , the platform supports cold presence detection on this port. If cleared to ?0 , the platform does not support cold presence detection on this port. When this bit is set to ?1 , P0CMD.HPCP should also be set to ?1 .
        ULONG ESP :1; //AHCI 1.1 External SATA Port: When set to '1', indicates that this ports signal connector is externally accessible on a signal only connector. When set to '1', CAP.SXS shall be set to '1'. When cleared to 0, indicates that this ports signal connector is not externally accessible on a signal only connector.  ESP is mutually exclusive with the HPCP bit in this register. 
        ULONG DW6_Reserved2 :2; //
        ULONG ATAPI :1; // Device is ATAPI: When set, the connected device is an ATAPI device. This bit is used by the HBA to control whether or not to generate the desktop LED when commands are active. See section 10.10 for details on the activity LED.
        ULONG DLAE :1; // Drive LED on ATAPI Enable: When set, the HBA shall drive the LED pin active for commands regardless of the state of P0CMD.ATAPI. When cleared, the HBA shall only drive the LED pin active for commands if P0CMD.ATAPI set to ?0 . See section 10.10 for details on the activity LED.
        ULONG ALPE :1; // Aggressive Link Power Management Enable: When set to '1', the HBA shall aggressively enter a lower link power state (Partial or Slumber) based upon the setting of the ASP bit. Software shall only set this bit to 1 if CAP.SALP is set to 1; if CAP.SALP is cleared to 0 software shall treat this bit as reserved. See section 8.3.1.3 for details.
        ULONG ASP :1; // Aggressive Slumber / Partial: When set to '1', and ALPE is set, the HBA shall aggressively enter the Slumber state when it clears the PxCI register and the PxSACT register is cleared or when it clears the PxSACT register and PxCI is cleared. When cleared, and ALPE is set, the HBA shall aggressively enter the Partial state when it clears the PxCI register and the PxSACT register is cleared or when it clears the PxSACT register and PxCI is cleared.  If CAP.SALP is cleared to 0 software shall treat this bit as reserved.  See section 8.3.1.3 for details.
        ULONG ICC :4; // Interface Communication Control: This field is used to control power management states of the interface. If the Link layer is currently in the L_IDLE state, writes to this field shall cause the HBA to initiate a transition to the interface power management state requested. If the Link layer is not currently in the L_IDLE state, writes to this field shall have no effect.
        //MSB
    };

    ULONG AsUlong;

}  AHCI_COMMAND, *PAHCI_COMMAND;

//Status of the Task File Data as defined in AHCI1.0 section 3.3.8
typedef union _AHCI_TASK_FILE_DATA_STATUS {
    
    struct {
        //LSB
        UCHAR ERR :1; // Indicates an error during the transfer.
        UCHAR CS1 :2; //Command Specific
        UCHAR DRQ :1; // Indicates a data transfer is requested
        UCHAR CS2 :3; //Command Specific
        UCHAR BSY :1; // Indicates the interface is busy
        //MSB
    };

    UCHAR AsUchar;

} AHCI_TASK_FILE_DATA_STATUS, *PAHCI_TASK_FILE_DATA_STATUS;

//Task File Data as defined in AHCI1.0 section 3.3.8
typedef union _AHCI_TASK_FILE_DATA {
    
    struct {
        //LSB
        AHCI_TASK_FILE_DATA_STATUS STS; //Status: Contains the latest copy of the task file status register.
        UCHAR ERR;  //Error: Contains the latest copy of the task file error register.
        USHORT DW8_Reserved;
        //MSB
    };

    ULONG AsUlong;

}  AHCI_TASK_FILE_DATA, *PAHCI_TASK_FILE_DATA;

//Signature as defined in AHCI1.0 section 3.3.9
typedef union _AHCI_SIGNATURE {
//Signature: Contains the signature received from a device D2H Register FIS.
    
    struct {
        //LSB
        ULONG Sector_Count :8;
        ULONG LBA_Low :8;
        ULONG LBA_Mid :8;
        ULONG LBA_High :8;    
        //MSB
    };

    ULONG AsUlong;

}  AHCI_SIGNATURE, *PAHCI_SIGNATURE;

//Serial ATA Status as defined in AHCI1.0 section 3.3.10
typedef union _AHCI_SERIAL_ATA_STATUS {

    struct {
        //LSB
        ULONG DET :4; //Device Detection: Indicates the interface device detection and Phy state.
        ULONG SPD :4; //Current Interface Speed: Indicates the negotiated interface communication speed.    
        ULONG IPM :4; //Interface Power Management: Indicates the current interface state:
        ULONG DW10_Reserved :20;
        //MSB
    };

    ULONG AsUlong;

} AHCI_SERIAL_ATA_STATUS, *PAHCI_SERIAL_ATA_STATUS;

//Serial ATA Control as defined in AHCI1.0 section 3.3.11
typedef union _AHCI_SERIAL_ATA_CONTROL {

    struct {
          //LSB
        ULONG DET :4; // Device Detection Initialization: Controls the HBA's device detection and interface initialization. 0h No device detection or initialization action requested 1h Perform interface communication initialization sequence to establish communication. This is functionally equivalent to a hard reset and results in the interface being reset and communications reinitialized. While this field is 1h, COMRESET is continuously transmitted on the interface. Software should leave the DET field set to 1h for a minimum of 1 millisecond to ensure that a COMRESET is sent on the interface. 4h Disable the Serial ATA interface and put Phy in offline mode. All other values reserved This field may only be modified when P0CMD.ST is '0 . Changing this field while the P0CMD.ST bit is set to '1 results in undefined behavior. When P0CMD.ST is set to '1 , this field should have a value of 0h.Note: It is permissible to implement any of the Serial ATA defined behaviors for transmission of COMRESET when DET=1h.
        ULONG SPD :4; // Speed Allowed: Indicates the highest allowable speed of the interface. 0h No speed negotiation restrictions 1h Limit speed negotiation to Generation 1 communication rate 2h Limit speed negotiation to a rate not greater than Generation 2 communication rate All other values reserved
        ULONG IPM :4; // Interface Power Management Transitions Allowed: Indicates which power states the HBA is allowed to transition to. If an interface power management state is disabled, the HBA is not allowed to initiate that state and the HBA must PMNAK P any request from the device to enter that state. 0h No interface restrictions 1h Transitions to the Partial state disabled 2h Transitions to the Slumber state disabled 3h Transitions to both Partial and Slumber states disabled All other values reserved
        ULONG SPM :4; // Select Power Management: This field is not used by AHCI
        ULONG PMP :4; // Port Multiplier Port: This field is not used by AHCI.
        ULONG DW11_Reserved :12;
        //MSB
    };

    ULONG AsUlong;

}  AHCI_SERIAL_ATA_CONTROL, *PAHCI_SERIAL_ATA_CONTROL;

//Diagnostics in Serial ATA Error as defined in AHCI1.0 section 3.3.12
typedef union _AHCI_SERIAL_ATA_ERROR_DIAGNOSTICS {

    struct {
        //LSB
        USHORT N :1; //PhyRdy Change: Indicates that the PhyRdy signal changed state. This bit is reflected in the P0IS.PRCS bit.
        USHORT I :1; //Phy Internal Error: Indicates that the Phy detected some internal error.
        USHORT W :1; //Comm Wake: Indicates that a Comm Wake signal was detected by the Phy.
        USHORT B :1; //10B to 8B Decode Error: Indicates that one or more 10B to 8B decoding errors occurred.
        USHORT D :1; //Disparity Error: This field is not used by AHCI.
        USHORT C :1; //CRC Error: Indicates that one or more CRC errors occurred with the Link Layer.
        USHORT H :1; //Handshake Error: Indicates that one or more R_ERR handshake response was received in response to frame transmission. Such errors may be the result of a CRC error detected by the recipient, a disparity or 8b/10b decoding error, or other error condition leading to a negative handshake on a transmitted frame.
        USHORT S :1; //Link Sequence Error: Indicates that one or more Link state machine error conditions was encountered. The Link Layer state machine defines the conditions under which the link layer detects an erroneous transition.
        USHORT T :1; //Transport state transition error: Indicates that an error has occurred in the transition from one state to another within the Transport layer since the last time this bit was cleared.
        USHORT F :1; //Unknown FIS Type: Indicates that one or more FISs were received by the Transport layer with good CRC, but had a type field that was not recognized/known.
        USHORT X :1; //Exchanged: When set to one this bit indicates that a change in device presence has been detected since the last time this bit was cleared.  The means by which the implementation determines that the device presence has changed is vendor specific. This bit shall always be set to one anytime a COMINIT signal is received.  This bit is reflected in the P0IS.PCS bit.
        USHORT Reserved :5;
        //MSB
    };

    USHORT AsUshort;

}  AHCI_SERIAL_ATA_ERROR_DIAGNOSTICS, *PAHCI_SERIAL_ATA_ERROR_DIAGNOSTICS;

 //Error in Serial ATA Error as defined in AHCI1.0 section 3.3.12
typedef union _AHCI_SERIAL_ATA_ERROR_ERROR {

    struct {
        //LSB
        USHORT I :1; //Recovered Data Integrity Error: A data integrity error occurred that was recovered by the interface through a retry operation or other recovery action.
        USHORT M :1; //Recovered Communications Error: Communications between the device and host was temporarily lost but was re-established. This can arise from a device temporarily being removed, from a temporary loss of Phy synchronization, or from other causes and may be derived from the PhyNRdy signal between the Phy and Link layers.
        USHORT Reserved :6; //
        USHORT T :1; //Transient Data Integrity Error: A data integrity error occurred that was not recovered by the interface.
        USHORT C :1; //Persistent Communication or Data Integrity Error: A communication error that was not recovered occurred that is expected to be persistent. Persistent communications errors may arise from faulty interconnect with the device, from a device that has been removed or has failed, or a number of other causes.
        USHORT P :1; //Protocol Error: A violation of the Serial ATA protocol was detected.
        USHORT E :1; //Internal Error: The host bus adapter experienced an internal error that caused the operation to fail and may have put the host bus adapter into an error state.  The internal error may include a master or target abort when attempting to access system memory, an elasticity buffer overflow, a primitive mis-alignment, a synchronization FIFO overflow, and other internal error conditions.  Typically when an internal error occurs, a non-fatal or fatal status bit in the PxIS register will also be set to give software guidance on the recovery mechanism required.
        USHORT Reserved2 :4;    
        //MSB
    };

    USHORT AsUshort;

} AHCI_SERIAL_ATA_ERROR_ERROR, *PAHCI_SERIAL_ATA_ERROR_ERROR;

//Serial ATA Error as defined in AHCI1.0 section 3.3.12
typedef union _AHCI_SERIAL_ATA_ERROR {

    struct {
        //LSB
        AHCI_SERIAL_ATA_ERROR_ERROR ERR; //Error: The ERR field contains error information for use by host software in determining the appropriate response to the error condition. If one or more of bits 11:8 of this register are set, the controller shall stop the current transfer.
        AHCI_SERIAL_ATA_ERROR_DIAGNOSTICS DIAG;    //Diagnostics: - Contains diagnostic error information for use by diagnostic software in validating correct operation or isolating failure modes
        //MSB
    };

    ULONG AsUlong;

} AHCI_SERIAL_ATA_ERROR, *PAHCI_SERIAL_ATA_ERROR;

//SNotification as defined in AHCI1.1 section 3.3.15
typedef union _AHCI_SNOTIFICATION {

    struct {
        //LSB
        ULONG PMN :16; //This field indicates whether a particular device with the corresponding PM Port number issued a Set Device Bits FIS to the host with the Notification bit set.
        ULONG Reserved :16;    
        //MSB
    };

    ULONG AsUlong;

} AHCI_SNOTIFICATION, *PAHCI_SNOTIFICATION;

typedef struct _AHCI_PORT {

    //Port Command List Base Address as defined in AHCI1.0 section 3.3.1 
    AHCI_COMMAND_LIST_BASE_ADDRESS CLB; 
    //Command List Base Address Upper 32-bits as defined in AHCI1.0 section 3.3.2
    ULONG CLBU; //Command List Base Address Upper: Indicates the upper 32-bits for the command list base physical address for this port. This base is used when fetching commands to execute. This register shall be read only ?0 for HBAs that do not support 64-bit addressing.

    //FIS Base Address as defined in AHCI1.0 section 3.3.3
    AHCI_FIS_BASE_ADDRESS FB;     
    //FIS Base Address Upper 32-bits as defined in AHCI section 3.3.4
    ULONG FBU; //FIS Base Address Upper: Indicates the upper 32-bits for the received FIS base physical address for this port. This register shall be read only ?0 for HBAs that do not support 64-bit addressing.

    AHCI_INTERRUPT_STATUS IS;
    
    AHCI_INTERRUPT_ENABLE IE;
    
    AHCI_COMMAND CMD;
    
    ULONG DW7_Reserved;

    AHCI_TASK_FILE_DATA TFD;

    AHCI_SIGNATURE SIG;

    AHCI_SERIAL_ATA_STATUS SSTS;
        
    AHCI_SERIAL_ATA_CONTROL SCTL;

    AHCI_SERIAL_ATA_ERROR SERR;
    
    //Serial ATA Active as defined in AHCI1.0 section 3.3.13
    ULONG SACT; //Device Status: Device Status (DS):  This field is bit significant.  Each bit corresponds to the TAG and command slot of a native queued command, where bit 0 corresponds to TAG 0 and command slot 0. This field is set by software prior to issuing a native queued command for a particular command slot.  Prior to writing PxCI[TAG] to 1, software will set DS[TAG] to 1 to indicate that a command with that TAG is outstanding.  The device clears bits in this field by sending a Set Device Bits FIS to the host.  The HBA clears bits in this field that are set to 1 in the SActive field of the Set Device Bits FIS.  The HBA only clears bits that correspond to native queued commands that have completed successfully.  Software should only write this field when PxCMD.ST is set to 1.  This field is cleared when PxCMD.ST is written from a 1 to a 0 by software.  This field is not cleared by a COMRESET or a software reset.

    //Command Issue    as defined in AHCI1.0 section 3.3.14
    ULONG CI; //Commands Issued: This field is bit significant.  Each bit corresponds to a command slot, where bit 0 corresponds to command slot 0.  This field is set by software to indicate to the HBA that a command has been built in system memory for a command slot and may be sent to the device.  When the HBA receives a FIS which clears the BSY, DRQ, and ERR bits for the command, it clears the corresponding bit in this register for that command slot. Bits in this field shall only be set to 1 by software when PxCMD.ST is set to 1. This field is also cleared when PxCMD.ST is written from a 1 to a 0 by software.

    AHCI_SNOTIFICATION SNTF;

    ULONG ReservedForFIS_Based_Switching;

    ULONG Reserved[11];

    ULONG VendorSpecific[4];
}  AHCI_PORT, *PAHCI_PORT;



//HBA Capabilities as defined in AHCI1.0 section 3.1.1
typedef union _AHCI_HBA_CAPABILITIES  {
    
    struct {
        //LSB
        ULONG NP :5; //Number of Ports: 0 s based value indicating the maximum number of ports supported by the HBA silicon. A maximum of 32 ports can be supported. A value of ?0h?, indicating one port, is the minimum requirement. Note that the number of ports indicated in this field may be more than the number of ports indicated in the GHC.PI register.
        ULONG SXS :1; //AHCI 1.1 Supports External SATA: When set to 1, indicates that the HBA has one or more Serial ATA ports that has a signal only connector that is externally accessible. If this bit is set, software may refer to the PxCMD.ESP bit to determine whether a specific port has its signal connector externally accessible as a signal only connector (i.e. power is not part of that connector).  When the bit is cleared to 0, indicates that the HBA has no Serial ATA ports that have a signal only connector externally accessible.
        ULONG EMS :1; //AHCI 1.1 Enclosure Management Supported: When set to 1, indicates that the HBA supports enclosure management as defined in section 12.  When enclosure management is supported, the HBA has implemented the EM_LOC and EM_CTL global HBA registers.  When cleared to 0, indicates that the HBA does not support enclosure management and the EM_LOC and EM_CTL global HBA registers are not implemented.
        ULONG CCCS :1; //AHCI 1.1 Command Completion Coalescing Supported: When set to 1, indicates that the HBA supports command completion coalescing as defined in section 11.  When command completion coalescing is supported, the HBA has implemented the CCC_CTL and the CCC_PORTS global HBA registers.  When cleared to 0, indicates that the HBA does not support command completion coalescing and the CCC_CTL and CCC_PORTS global HBA registers are not implemented.  
        ULONG NCS :5; //Number of Command Slots: 0 s based value indicating the number of command slots supported by this HBA. A minimum of 1 and maximum of 32 slots can be supported.
        ULONG PSC :1; //Partial State Capable: Indicates whether the HBA can support transitions to the Partial state. When cleared to ?0 , software must not allow the HBA to initiate transitions to the Partial state via agressive link power management nor the PxCMD.ICC field in each port, and the PxSCTL.IPM field in each port must be programmed to disallow device initiated Partial requests. When set to ?1 , HBA and device initiated Partial requests can be supported.
        ULONG SSC :1; //Slumber State Capable: Indicates whether the HBA can support transitions to the Slumber state. When cleared to ?0 , software must not allow the HBA to initiate transitions to the Slumber state via agressive link power management nor the PxCMD.ICC field in each port, and the PxSCTL.IPM field in each port must be programmed to disallow device initiated Slumber requests. When set to ?1 , HBA and device initiated Slumber requests can be supported.
        ULONG PMD :1; //PIO Multiple DRQ Block: If set to 1 , the HBA supports multiple DRQ block data transfers for the PIO command protocol. If cleared to ?0 the HBA only supports single DRQ block data transfers for the PIO command protocol.
        ULONG FBSS :1; //AHCI 1.1  FIS-based Switching Supported: When set to 1, indicates that the HBA supports Port Multiplier FIS-based switching. When cleared to 0, indicates that the HBA does not support FIS-based switching.  AHCI 1.0 and 1.1 HBAs shall have this bit cleared to 0.
        ULONG SPM :1; //Supports Port Multiplier: Indicates whether the HBA can support a Port Multiplier. When set, a Port Multiplier using command-based switching is supported. When cleared to ?0 , a Port Multiplier is not supported, and a Port Multiplier may not be attached to this HBA.
        ULONG SAM :1; //Supports AHCI mode only: The SATA controller may optionally support AHCI access mechanisms only. A value of '0' indicates that in addition to the native AHCI mechanism (via ABAR), the SATA controller implements a legacy, task-file based register interface such as SFF-8038i. A value of '1' indicates that the SATA controller does not implement a legacy, task-file based register interface.
        ULONG SNZO :1; //Supports Non-Zero DMA Offsets: When set to 1 , indicates that the HBA can support non-zero DMA offsets for DMA Setup FISes. This bit is reserved for future AHCI enhancements. AHCI 1.0 HBAs must have this bit cleared to ?0 .
        ULONG ISS :4; //Interface Speed Support: Indicates the maximum speed the HBA can support on its ports. These encodings match the PxSCTL.DET.SPD field, which is programmable by system software. Values are:
        ULONG SCLO :1; //Supports Command List Override: When set to 1 , indicates that the HBA supports the PxCMD.CLO bit and its associated function. When cleared to ?0 , the HBA is not capable of clearing the BSY and DRQ bits in the Status register in order to issue a software reset if these bits are still set from a previous operation.
        ULONG SAL :1; //Supports Activity LED: When set to 1 , indicates that the HBA supports a single output pin which indicates activity. This pin can be connected to an LED on the platform to indicate device activity on any drive. See section 10.10 for more information.
        ULONG SALP :1; //Supports Aggressive Link Power Management: When set to ?1 , indicates that the HBA can support auto-generating link requests to the Partial or Slumber states when there are no commands to process. Refer to section 8.3.1.3.
        ULONG SSS :1; //Supports Staggered Spin-up: When set to 1 , indicates that the HBA supports staggered spin-up on its ports, for use in balancing power spikes. This value is loaded by the BIOS prior to OS initiallization.
        ULONG SMPS :1; //Supports Mechanical Presence Switch: ): When set to 1, the HBA supports mechanical presence switches on its ports for use in hot plug operations.  When cleared to 0, this function is not supported.  This value is loaded by the BIOS prior to OS initialization.
        ULONG SSNTF :1; //AHCI 1.1 Supports SNotification Register: When set to 1, indicates that the HBA supports the PxSNTF (SNotification) register and its associated functionality.  When cleared to 0, the HBA does not support the PxSNTF (SNotification) register and its associated functionality.  Refer to section 10.10.1.
        ULONG SNCQ :1; //Supports Native Command Queuing: Indicates whether the HBA supports Serial ATA native command queuing. If set to ?1 , an HBA shall handle DMA Setup FISes natively, and shall handle the auto-activate optimization through that FIS. If cleared to ?0 , native command queuing is not supported and software should not issue any native command queuing commands.
        ULONG S64A :1; //Supports 64-bit Addressing: Indicates whether the HBA can access 64-bit data structures. If true, the HBA shall make the 32-bit upper bits of the port DMA Descriptor, the PRD Base, and each PRD entry read/write. If cleared, these are read- only and treated as ?0 by the HBA.
        //MSB
    };

    ULONG AsUlong;

}  AHCI_HBA_CAPABILITIES, *PAHCI_HBA_CAPABILITIES;

//Global HBA Control as defined in AHCI1.0 section 3.1.2
typedef union _AHCI_Global_HBA_CONTROL {
    
    struct {
        //LSB
        ULONG HR :1; //HBA Reset: When set by SW, this bit causes an internal reset of the HBA. All state machines that relate to data transfers and queuing shall return to an idle condition, and all ports shall be re-initialized via COMRESET (if staggered spin-up is not supported). If staggered spin-up is supported, then it is the responsibility of software to spin-up each port after the reset has completed. When the HBA has performed the reset action, it shall reset this bit to ?0 . A software write of ?0 shall have no effect. For a description on which bits are reset when this bit is set, see section 10.4.3.
        ULONG IE :1; //Interrupt Enable: This global bit enables interrupts from the HBA. When cleared (reset default), all interrupt sources from all ports are disabled. When set, interrupts are enabled.
        ULONG MRSM :1; //MSI Revert to Single Message: When set to 1 by hardware, indicates that the HBA requested more than one MSI vector but has reverted to using the first vector only.  When this bit is cleared to 0, the HBA has not reverted to single MSI mode (i.e. hardware is already in single MSI mode, software has allocated the number of messages requested, or hardware is sharing interrupt vectors if MC.MME < MC.MMC).
        ULONG Reserved :28; //3-30
        ULONG AE :1; //AHCI Enable: When set, indicates that communication to the HBA shall be via AHCI mechanisms. This can be used by an HBA that supports both legacy mechanisms (such as SFF-8038i) and AHCI to know when the HBA is running under an AHCI driver. When set, software shall only communicate with the HBA using AHCI. When cleared, software shall only communicate with the HBA using legacy mechanisms. When cleared FISes are not posted to memory and no commands are sent via AHCI mechanisms. Software shall set this bit to ?1 before accessing other AHCI registers. The implementation of this bit is dependent upon the value of the CAP.SAM bit. If CAP.SAM is '0', then GHC.AE shall be read-write and shall have a reset value of '0'. If CAP.SAM is '1', then AE shall be read-only and shall have a reset value of '1'.    
        //MSB
    };

    ULONG AsUlong;

} AHCI_Global_HBA_CONTROL, *PAHCI_Global_HBA_CONTROL;

//Version as defined in AHCI1.0 section 3.1.5
typedef union _AHCI_VERSION {
    
    struct {
        //LSB
        ULONG MNR :16; //Minor Version Number
        ULONG MJR :16; //Major Version Number
        //MSB
    };
    
    ULONG AsUlong;

} AHCI_VERSION, *PAHCI_VERSION;

//Command Completion Coalescing Control as defined in AHCI1.2 section 3.1.6
typedef union _AHCI_COMMAND_COMPLETION_COALESCING_CONTROL {

        struct {
        //LSB
        ULONG EN: 1; //Enable: When cleared to 0, the command completion coalescing feature is disabled and no CCC interrupts are generated.  When set to 1, the command completion coalescing feature is enabled and CCC interrupts may be generated based on timeout or command completion conditions.  Software shall only change the contents of the TV and CC fields when EN is cleared to 0. On transition of this bit from 0 to 1, any updated values for the TV and CC fields shall take effect.
        ULONG Reserved: 2;
        ULONG INT: 5; //Interrupt: Specifies the interrupt used by the CCC feature.  This interrupt must be marked as unused in the Ports Implemented (PI) register by the corresponding bit being set to 0.  Thus, the CCC interrupt corresponds to the interrupt for an unimplemented port on the controller.  When a CCC interrupt occurs, the IS.IPS[INT] bit shall be asserted to 1.  This field also specifies the interrupt vector used for MSI.
        ULONG CC: 8; //Command Completions: Specifies the number of command completions that are necessary to cause a CCC interrupt.  The HBA has an internal command completion counter, hCccComplete.  hCccComplete is incremented by one each time a selected port has a command completion.  When hCccComplete is equal to the command completions value, a CCC interrupt is signaled.  The internal command completion counter is reset to 0 on the assertion of each CCC interrupt.  A value of 0 for this field shall disable CCC interrupts being generated based on the number of commands completed, i.e. CCC interrupts are only generated based on the timer in this case.
        ULONG TV: 16; //Timeout Value: The timeout value is specified in 1 millisecond intervals.  The timer accuracy shall be within 5%.  hCccTimer is loaded with this timeout value.  hCccTimer is only decremented when commands are outstanding on selected ports, as defined in section 11.2.  The HBA will signal a CCC interrupt when hCccTimer has decremented to 0.  hCccTimer is reset to the timeout value on the assertion of each CCC interrupt.  A timeout value of 0  is reserved.
        //MSB
    };

    ULONG AsUlong;

}AHCI_COMMAND_COMPLETION_COALESCING_CONTROL, *PAHCI_COMMAND_COMPLETION_COALESCING_CONTROL;

//Enclosure Management Location as defined in AHCI1.2 section 3.1.8
typedef union _AHCI_ENCLOSURE_MANAGEMENT_LOCATION {

    struct {
        //LSB
        ULONG SZ :16; //Buffer Size: Specifies the size of the transmit message buffer area in Dwords.  If both transmit and receive buffers are supported, then the transmit buffer begins at ABAR[EM_LOC.OFST*4] and the receive buffer directly follows it.  If both transmit and receive buffers are supported, both buffers are of the size indicated in the Buffer Size field.  A value of 0 is invalid.
        ULONG OFST :16; //Offset: The offset of the message buffer in Dwords from the beginning of the ABAR.   
        //MSB
    };

    ULONG AsUlong;

} AHCI_ENCLOSURE_MANAGEMENT_LOCATION, *PAHCI_ENCLOSURE_MANAGEMENT_LOCATION;

//Enclosure Management Control as defined in AHCI1.2 section 3.1.9
typedef union _AHCI_ENCLOSURE_MANAGEMENT_CONTROL {

    struct {
        //LSB
        ULONG STS_MR :1; //Message Received: The HBA sets this bit to a 1 when a message is completely received into the message buffer.  When software detects this bit is a 1, software should read the message and perform any actions necessary.  When software is finished reading the message in the buffer, software writes a 1 to this bit in order to clear it.  A write of 0 to this bit by software shall have no effect.
        ULONG Reserved0 :7;
        ULONG CTL_TM :1; //Transmit Message: When set to 1 by software, the HBA shall transmit the message contained in the message buffer.  When the message is completely sent, the HBA shall clear this bit to 0.  A write of 0 to this bit by software shall have no effect.  Software shall not change the contents of the message buffer while CTL.TM is set to 1.
        ULONG CTL_RST :1; //Reset: When set to 1 by software, the HBA shall reset all enclosure management message logic and the attached enclosure processor (if applicable) and take all appropriate reset actions to ensure messages can be transmitted/received after the reset.  After the HBA completes the reset operation, the HBA shall set the value to 0.  A write of 0 by software to this field shall have no effect.
        ULONG Reserved1 :6;
        ULONG SUPP_LED :1; //LED Message Types:  If set to 1, the HBA supports the LED message type defined in section 12.2.1.
        ULONG SUPP_SAFTE :1; //SAF-TE Enclosure Management Messages:  If set to 1, the HBA supports the SAF-TE message type. 
        ULONG SUPP_SES2 :1; //SES-2 Enclosure Management Messages:  If set to 1, the HBA supports the SES-2 message type. 
        ULONG SUPP_SGPIO :1; //SGPIO Enclosure Management Messages:  If set to 1, the HBA supports the SGPIO register interface message type. 
        ULONG Reserved2 :4;
        ULONG ATTR_SMB :1; //Single Message Buffer:  If set to 1, the HBA has one message buffer that is shared for messages to transmit and messages received.  In this case, unsolicited receive messages are not supported and it is softwares responsibility to manage access to this buffer.  If cleared to 0, there are separate receive and transmit buffers such that unsolicited messages could be supported.
        ULONG ATTR_XMT :1; //Transmit Only:  If set to 1, the HBA only supports transmitting messages and does not support receiving messages.  If cleared to 0, the HBA supports transmitting and receiving messages.
        ULONG ATTR_ALHD :1; //Activity LED Hardware Driven:  If set to 1, the HBA drives the activity LED for the LED message type in hardware and does not utilize software settings for this LED.  The HBA does not begin transmitting the hardware based activity signal until after software has written CTL.TM=1 after a reset condition.
        ULONG ATTR_PM :1; //Port Multiplier Support: If set to 1, the HBA supports enclosure management messages for devices attached via a Port Multiplier.  If cleared to 0, the HBA does not support enclosure management messages for devices attached via a Port Multiplier.  When cleared to 0, software should use the Serial ATA enclosure management bridge that is built into many Port Multipliers for enclosure services with these devices.  For more information on Serial ATA enclosure management bridges, refer to the Serial ATA Revision 2.5 specification.
        ULONG Reserved3 :4;
        //MSB
    };

    ULONG AsUlong;

}AHCI_ENCLOSURE_MANAGEMENT_CONTROL, *PAHCI_ENCLOSURE_MANAGEMENT_CONTROL;

//HBA Capabilities Extended as defined in AHCI1.2 section 3.1.10
typedef union _AHCI_HBA_CAPABILITIES2 {

    struct {
        //LSB
        ULONG BOH :1; //BIOS/OS Handoff:  When set to 1, the HBA supports the BIOS/OS handoff mechanism defined in section TBD.  When cleared to 0, the HBA does not support the BIOS/OS handoff mechanism.
        ULONG Reserved :31;
        //MSB
    };

    ULONG AsUlong;

}AHCI_HBA_CAPABILITIES2, *PAHCI_HBA_CAPABILITIES2;

typedef struct _AHCI_MEMORY_REGISTERS{

        AHCI_HBA_CAPABILITIES CAP; //Host Capabilities           
        AHCI_Global_HBA_CONTROL GHC; //Global Host Control       
        ULONG IS; //Interrupt Status                           
        ULONG PI; //Ports Implemented                           
        AHCI_VERSION VS; //Version                              
        AHCI_COMMAND_COMPLETION_COALESCING_CONTROL CCC_CTL; //Command Completion Coalescing Control
        ULONG CCC_PORTS; //Command Completion Coalsecing Ports
        AHCI_ENCLOSURE_MANAGEMENT_CONTROL EM_LOC; //Enclosure Management Location
        AHCI_ENCLOSURE_MANAGEMENT_CONTROL EM_CTL; //Enclosure Management Control
        AHCI_HBA_CAPABILITIES2 CAP2;
        ULONG Reserved[0x1e];//Reserved                          
        ULONG VendorSpecific[0x18];//Vendor Specific              
        AHCI_PORT PortList[32];

}AHCI_MEMORY_REGISTERS, *PAHCI_MEMORY_REGISTERS;


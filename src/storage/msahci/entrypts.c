/*++

Copyright (C) Microsoft Corporation, 2005

Module Name:

    entrypts.c

Abstract:

    This header file contains function of entry points to the AHCI ATA miniport.  
    This includes ATA miniport interface functions for both channel and controller interfaces.

Notes:

Revision History:

        Nathan Obr (natobr),  February 2005 - September 2006 rev 1 (NCQ, LPM, Hotplug, persistant state) 
                              December 2006 - August 2007    rev 2 (async)
--*/

#include "geninc.h"

//#pragma alloc_text(INIT, DriverEntry)

ULONG    //REMOVE: 1PCIIDEX to driver entry
DriverEntry (       //  DriverEntry(
    PVOID Argument1,//    IN PDRIVER_OBJECT  DriverObject, 
    PVOID Argument2 //    IN PUNICODE_STRING  RegistryPath 
    )               //    )
/*++
The only goal of DriverEntry is to create an IDE_CONTROLLER_INTERFACE, populate and 
send it to AtaPortInitializeEx.

It assumes:
    DriverEntry is the first function called in msahci.sys
    The OS-specific port driver allocates a controller extension initializes it and sends it to AtaPortInitializeEx. 
    AtaPortInitializeEx initializes the miniport driver’s dispatch tables and allocates an extension for the driver object. 
    It stores the pointer to the AtaControllerInitialize entry point and the ControllerExtensionSize in the driver object extension for later use.

Called by:                              
    external

It performs:
    (overview)
    1. Initialization of the Ide Controller Interface
    2. Calling into PCIIDEX through AtaPortInitializeEx.
    (details)
    1.1 Initialize IDE_CONTROLLER_INTERFACE to 0s
    1.2 The miniport driver indicates the support for the channel interface by setting the ChannelExtensionSize and the AtaChannelInitRoutine entry point in the controller interface structure.
    1.3 Add mini driver entry points
    1.4 add pointers to data structures and IO alignment
    2.1 The miniport must call AtaPortInitializeEx from its DriverEntry routine. 

Affected Variables/Registers:
    none

Return Values:
    The miniport driver must return TRUE if the initialization succeeded. If the miniport driver fails to initialize it must return FALSE.
    Initialization success is dependant on AtaPortInitializeEx's Return Value

--*/
{                                        //used to initialize the IDE Controller Interface
    IDE_CONTROLLER_INTERFACE IdeControllerInterface;
    PUCHAR pIdeControllerInterface  = (PUCHAR) &IdeControllerInterface;
    int i=0;

  //1.1 initialize IDE_CONTROLLER_INTERFACE to 0s
    for (i= 0; i<sizeof(IDE_CONTROLLER_INTERFACE); i++) {
        (*(pIdeControllerInterface))=0;
        pIdeControllerInterface++; 
    }
  //1.2 The miniport driver indicates the support
    IdeControllerInterface.ChannelExtensionSize= sizeof(AHCI_CHANNEL_EXTENSION); 
    IdeControllerInterface.AtaChannelInitRoutine= AhciChannelInitRoutine;
  //1.3 Add mini driver entry points 
    IdeControllerInterface.AtaControllerChannelEnabled = AhciChannelEnabled;
    IdeControllerInterface.AtaControllerTransferModeSelect = NULL;
    IdeControllerInterface.AtaAdapterControl= AhciAdapterControl;
  //1.4 add pointers to data structures and IO alignment
    IdeControllerInterface.Version= sizeof(IDE_CONTROLLER_INTERFACE);
    IdeControllerInterface.ControllerExtensionSize= sizeof(AHCI_CONTROLLER_EXTENSION);
    IdeControllerInterface.AlignmentMask = 1; // The PRDT DBA must be word aligned.

  //2.1 call into PCIIDEX where it will handle creating the controller's FDO
    return AtaPortInitializeEx( Argument1, //DriverObject,
                                Argument2, //RegistryPath,
                                &IdeControllerInterface);
}

BOOLEAN  
  AhciAdapterControl(
    PVOID ControllerExtension,
    IN IDE_CONTROL_ACTION ControlAction,
    IN PVOID Parameters //when ControlAction is IdeStart, this is a pointer to a IDE_CONTROLLER_CONFIGURATION
    )
/*++
This is a CONTROLLER dispatch routine for for notifications the miniport driver receives about the various PNP and power events in the system. 
This function is a function dispatcher for the IDE_CONTROL_ACTIONS: Start, Stop, PowerUp, and PowerDown

It assumes:
    The port driver ensures that there is no outstanding I/O on the adapter before invoking this routine. 

Called by:    
    external

It performs:
    Dispatch based on the IDE_CONTROL_ACTIONS for the Controller

Affected Variables/Registers:
    none

Return Values:
    The miniport driver must return TRUE to acknowledge the completion of the requested action. 
    A return value of FALSE indicates that the miniport was not able to complete the action successfully. 
    A return value of FALSE for certain actions might cause the device installation to fail.

    FALSE is only valid if the IDE_CONTROLLER_CONFIGURATION structure is not the right version.
    This causes the PCIIDEX driver to return from IRP_MJ_PnP with a STATUS_REVISION_MISMATCH
--*/
{                    //Used to perform dispatch
    BOOLEAN retVal;
    PIDE_CONTROLLER_CONFIGURATION controllerConfiguration;
    PAHCI_CONTROLLER_EXTENSION controllerExtension = (PAHCI_CONTROLLER_EXTENSION) ControllerExtension;

    switch (ControlAction) {
    case IdeStart:

        controllerConfiguration = Parameters;
        retVal = AhciAdapterControlIdeStart(ControllerExtension, controllerConfiguration);
        break;     

    case IdeStop:

        retVal = AhciAdapterControlIdeStop(ControllerExtension);
        break;

    case IdePowerUp:

        retVal = AhciAdapterControlIdePowerUp(ControllerExtension);
        break;

    case IdePowerDown:
        retVal = AhciAdapterControlIdePowerDown(ControllerExtension);
        break;

    default:        
        retVal = FALSE;
        break;
    }
    return retVal;
}

ATA_CHANNEL_STATE  
  AhciChannelEnabled(
    IN PVOID ControllerExtension,
    IN ULONG Channel
    )
/*++
AtaControllerChannelEnabled is an optional routine.   This is an optional routine and should not have controller critical steps in it.
This function is not called in the case of a channel restart, only on QueryDeviceRelations
If the miniport driver does not implement this routine a default handler will be loaded, and all channels are assumed to be enabled.  

PCIIDEX uses this function to help it build PDOs for each channel.  
Once the PDOs are created, it is time to load ATAport who will start the channels and do enumeration for the device(s) on the channel(s).

It assumes:
    This function will be called with 'ULONG Channel' valuse from 0 to (ControllerConfiguration->NumberOfChannels - 1) which was given to PCIIDEX in AhciAdapterControl (IdeStart).

Called by:    
    external

It performs:
    (overview)
    1. Verification of channel's existance

    (details)
    1.1 Initialize variables
    1.2 Verify the channel's existance
        Ataport doesn't support sparse channels explicitly.  It is possible this channel doesn't exist.

Affected Variables/Registers:

Return Values:
    ChannelStateEnabled = Channel is ready to be used by time this function finishes
    ChannelStateDisabled= If previously enabled, this state causes the port driver to mark the channel dead
    ChannelStateUnKnown = use only if you want the port driver to assert.
--*/
{
    ATA_CHANNEL_STATE state;
    PAHCI_CONTROLLER_EXTENSION controllerExtension;
                             //structures to get information from the Controller
    PAHCI_MEMORY_REGISTERS abar;
    ULONG pi;
  
  //this is an optional routine and should not have controller critical steps in it.
  //this is not called in the case of a channel restart, only on QueryDeviceRelations

  //1.1 Initialize variables
    state = ChannelStateUnKnown;
    controllerExtension = (PAHCI_CONTROLLER_EXTENSION) ControllerExtension;
    abar = (PAHCI_MEMORY_REGISTERS) controllerExtension->ABAR_Address;
    pi = AtaPortReadRegisterUlong(&abar->PI);
  //1.2 Verify the channel's existance
    if ( (pi & (1 << Channel) ) == 0){
        return ChannelStateDisabled;
    }

    return ChannelStateEnabled;
}

BOOLEAN     
  AhciChannelInitRoutine(
    IN PVOID ChannelExtension,
    OUT PIDE_CHANNEL_INTERFACE ChannelInterface,
    IN PVOID ControllerExtension
    )
{
/*++
This is the first time that we see the Channel Interface.  Ataport has initialized some of it,  we have to initialize the rest. 
This is the first time that we see the Channel Extension whose size was specified in IdeControllerInterface.ChannelExtensionSize at DriverEntry. 
Time to start initializing the Channel Extension.

It assumes:
    The ChannelInitialize routine is called when Ataport's AddDevice is creating the Channel's FDO Extension.

Called by:    
    external

It performs:
    (overview)
    1. Start with some defensive structure checking
    2. Fill in ControllerExtension
    3. Initialization of the Channel Extension
    4. Initialization of the Channel Interface
    (details)
    1.1 Initialize Variables
    1.2 Verify the Channel Interface is the version we are expecting.
    2.1 Fill in ControllerExtension
    3.1 Initialize Channel Extension
    3.2 Check for controller matched accomodations
    3.3 Keep a copy of the Controller's Capabilities
    3.4 Finally, Intialize the Command and Interrupt logging
    4.1 Initialization of the Channel Interface

Affected Variables/Registers:
    ControllerExtension
    ChannelExtension
    ChannelInterface

Return Values:
    FALSE is only valid if the IDE_CONTROLLER_CONFIGURATION structure is not the right version.
    This causes the AtaPort driver to return from IRP_MJ_PnP, IRP_MN_START with a STATUS_REVISION_MISMATCH
    True if the function excecuted entirely.
*/
    PAHCI_CHANNEL_EXTENSION channelExtension;
    PAHCI_CONTROLLER_EXTENSION controllerExtension;

  //1.1 Initialize Variables
    channelExtension = (PAHCI_CHANNEL_EXTENSION) ChannelExtension;
    controllerExtension = (PAHCI_CONTROLLER_EXTENSION) ControllerExtension;
    RecordExecutionHistory(channelExtension, 0x00000001);//AhciChannelInitRoutine
  //1.2 Verify the Channel Interface
    if (ChannelInterface->Version != sizeof(IDE_CHANNEL_INTERFACE) ){
        return FALSE;
    }

  //2.1 Fill in ControllerExtension
    controllerExtension->ExtensionOnSlot[ChannelInterface->ChannelNumber] = channelExtension;

  //3.1    Initialize Channel Extension
    channelExtension->ChannelNumber = ChannelInterface->ChannelNumber;                
    
    channelExtension->StateFlags.StartCapable = FALSE;
    channelExtension->StateFlags.Crashing = FALSE;
    channelExtension->StateFlags.IgnoreHotplugDueToResetInProgress = TRUE;
    channelExtension->StateFlags.QueuePaused = FALSE;

    channelExtension->StateFlags.NCQ_Disallowed  = FALSE;
    channelExtension->StateFlags.NCQ_Activated = FALSE;
    channelExtension->StateFlags.NCQ_Succeeded = FALSE;
    channelExtension->StateFlags.NCQ_NeverNonQueuedErrorRecovery = FALSE;
        
    channelExtension->StateFlags.CallAhciReset = FALSE;
    channelExtension->StateFlags.CallAhciNonQueuedErrorRecovery = FALSE;
    channelExtension->StateFlags.CallAhciReportBusChange = FALSE;
    channelExtension->StateFlags.IgnoreHotPlug = FALSE;

    channelExtension->StateFlags.SingleIo = FALSE;
    channelExtension->StateFlags.ResetInInit = FALSE;
    channelExtension->StateFlags.Hipm_Disallowed = FALSE;
    channelExtension->StateFlags.Dipm_Allowed = FALSE;

    channelExtension->Px = NULL;
    channelExtension->ControllerIS = NULL;

  //3.2 Check for controller matched accomodations

    channelExtension->SlotManager.CommandsIssued = 0;
    channelExtension->SlotManager.CommandsToComplete = 0;
    channelExtension->SlotManager.HighPriorityAttribute = 0;
    channelExtension->SlotManager.NCQueueSlice = 0;
    channelExtension->SlotManager.NormalQueueSlice = 0;
    channelExtension->SlotManager.SingleIoSlice = 0;
    channelExtension->CCS = 1;
  //3.3 Keep a copy of the Controller's Capabilities
    channelExtension->CAP = controllerExtension->CAP;
  //3.4 Finally, Intialize the Command and Interrupt logging
    channelExtension->CommandHistoryNextAvailableIndex = 0;
    channelExtension->ExecutionHistoryNextAvailableIndex = 0;
    
  //4.1 Initialization of the Channel Interface
    ChannelInterface->IdeHwInitialize = AhciHwInitialize;
    ChannelInterface->IdeHwBuildIo = AhciHwBuildIo;
    ChannelInterface->IdeHwStartIo = AhciHwStartIo;
    ChannelInterface->IdeHwInterrupt = AhciHwInterrupt;
    ChannelInterface->IdeHwReset = AhciHwReset;
    ChannelInterface->IdeHwControl = AhciHwControl;

    RecordExecutionHistory(channelExtension, 0x10000001);//Exit AhciChannelInitRoutine

    return TRUE;
}

BOOLEAN     
  AhciHwControl (
    IN PVOID ChannelExtension,    //TODO: Isn't Ataport sending in the FDO_EXTENSION, not CHANNEL_EXTENSION?
    IN IDE_CONTROL_ACTION ControlAction,
    IN PVOID Parameters
    )
/*++
This is a CHANNEL dispatch routine for notifications the miniport driver receives about the various PNP and power events in the system. 
This function is a function dispatcher for the Channel IDE_CONTROL_ACTIONS: Start, Stop, PowerUp, and PowerDown

It assumes:
    The port driver ensures that there is no outstanding I/O on the adapter before invoking this routine. 
    Interrupts are connected

Called by:    
    external

It performs:
    Dispatch based on the IDE_CONTROL_ACTIONS for the Channel

Affected Variables/Registers:
    none

Return Values:
    FALSE causes the Ataport driver to return from IRP_MJ_PnP with a STATUS_UNSUCCESSFUL.
    This implementation only returns FALSE if the IDE_CHANNEL_CONFIGURATION structure is not the right version.
--*/
{
    BOOLEAN retVal;
    PIDE_CHANNEL_CONFIGURATION channelConfiguration;

    RecordExecutionHistory(ChannelExtension, 0x00000002);//AhciHwControl
    switch (ControlAction) {
    case IdeStart:

        channelConfiguration = (PIDE_CHANNEL_CONFIGURATION) Parameters;
        retVal = AhciHwControlIdeStart(ChannelExtension, channelConfiguration);
        break;

    case IdeStop:

        retVal = AhciHwControlIdeStop(ChannelExtension);
        break;

    case IdePowerUp:

        retVal = AhciHwControlIdePowerUp(ChannelExtension);
        break;

    case IdePowerDown:
        retVal = AhciHwControlIdePowerDown(ChannelExtension);
        break;

    default:        
        retVal = FALSE;
        break;
    }

    RecordExecutionHistory(ChannelExtension, 0x10000002);//Exit AhciHwControl
    return retVal;
}

BOOLEAN     
  AhciHwBuildIo (
    IN PVOID ChannelExtension,
    IN PIDE_REQUEST_BLOCK Irb
    )
/*++
The AtaHwBuildIo routine performs unsynchronized processing of the request. 
The miniport driver must not touch any shared data in its channel extension from this routine. 
The miniport driver must not call any of the library routines exported by the port driver from AtaHwBuildIo. 
If the miniport driver wishes to complete a request from this routine, it must set the IrbStatus to the appropriate completion status, not by calling AtaPortCompleteRequest. 
The port driver will complete any Irb with an IrbStatus that is not IRB_STATUS_PENDING.

The miniport driver could use this routine to indicate its preferences for the given request to the port driver 
The miniport could request the port driver to map the DataBuffer by setting the appropriate IrbFlags in the Irb.

It assumes:
    This routine is invoked without holding any locks. 
    AtaHwBuildIo is called on an IRB before issuing that IRB request to the AtaHwStartIo routine.

Called by:    
    external

It performs:
    If the channel is not started, it makes sure the IO timeout value is long enough to let the channel start.

Affected Variables/Registers:
    IRB

Return Values:
    TRUE
--*/
{
    PAHCI_CHANNEL_EXTENSION channelExtension = (PAHCI_CHANNEL_EXTENSION) ChannelExtension;
    if ( (channelExtension->StartState.ChannelNextStartState != StartComplete) && (Irb->TimeOutValue < 10) ) {
        Irb->TimeOutValue = 10;
    }

    return TRUE;
}

BOOLEAN
  AhciHwStartIo (
    IN PVOID ChannelExtension,
    IN PIDE_REQUEST_BLOCK Irb
    )
{
/*++
This function processes an IRB which commonly includes translating it into a command FIS and programming a AHCI controller command slot. 

As soon as it receives the initial request for a target peripheral, the ATAport driver calls the AtaHwStartIo routine with an input IRB. 
After this call, the HBA miniport driver owns the request and is expected to complete it.  ATAport will not touch the request until the IRB is sent back using AtaPortCompleteRequest.

It assumes:
    On return from this routine the miniport driver should be prepared to receive the next request from the port driver. 

Called by:    
    external

It performs:
    (overview)
    1. Prepare structures and controller for command processing
    2. Build a command as per AHCI 1.1 Section 5.5.1
    3. Keep track of the IRB for future processing
    (details)
    1.1 Initialize variables
    1.2 Check if command processing requires hardware. If not succeed the command.
    1.3 Verify the channel is running
    1.4 Find a slot/tag
    1.5 Initialize the Command Header, Slot and History structures

    2.1 Perform IO transformations if needed
    2.2 Program the Command Table, PRD Table and Command Header 
    2.3 Build the Command Header
    2.4 Get the Command Table's physical address and verify the alignment 
    
    3.1 Put the slot content in the correct queue

Affected Variables/Registers:
    channelExtension
    IRB, tag
    Command Header, Command Table

Return Values:
    AtaHwStartIo returns TRUE to acknowledge the receipt of the Irb. 
    A return value of FALSE is ignored by the ATAport driver.  
    If this function is ever modified to return false, MSAHCI functions must be modified to check for it.
--*/
    PAHCI_CHANNEL_EXTENSION channelExtension;
    AHCI_SERIAL_ATA_STATUS ssts;
    PSLOT_CONTENT slotContent;
    PCOMMAND_HISTORY cmdHistory;
    ULONG ci;
    ULONG sact;
    PAHCI_COMMAND_HEADER cmdHeader;
    PAHCI_COMMAND_TABLE cmdTable;
    PUCHAR cmdTableInitializer;
    ULONG i;
    ULONG prdtLength;
    IDE_PHYSICAL_ADDRESS  irbExtensionPhysicalAddress;

  //1.1 Initialize Variables
    channelExtension = (PAHCI_CHANNEL_EXTENSION) ChannelExtension;
    ci = AtaPortReadRegisterUlong(&channelExtension->Px->CI);
    sact = AtaPortReadRegisterUlong(&channelExtension->Px->SACT);
    ssts.AsUlong = AtaPortReadRegisterUlong(&channelExtension->Px->SSTS.AsUlong);
    RecordExecutionHistory(channelExtension, 0x00000020);//AhciHwStartIo
 
  //1.2 Determine if the request requires controller resources, slot and command history
    if (! RequiresControllerResources(channelExtension, Irb)) {
        RecordExecutionHistory(channelExtension, 0x10010020);//No Slot Resources Needed
        return TRUE;
    }

  //1.3 Check if command processing should happen
    if (channelExtension->StartState.ChannelNextStartState == StartFailed) {
        Irb->IrbStatus = IRB_STATUS_SELECTION_TIMEOUT;
        AhciCompleteRequest(channelExtension, Irb);
        RecordExecutionHistory(channelExtension, 0x10020020);//No Device Present
        return TRUE;

        RecordExecutionHistory(channelExtension, 0x10020020);//No Device Present
    }

  //1.4 Find an open slot/tag (AHCI 1.1 Section 5.5.1)
    GetTag(channelExtension, Irb);
    // If no tag is available, reject the command to be retried later
    if( Irb->QueueTag == 0xff ) {
        channelExtension->Reserved0 |= (1 << 4);
        
        AtaPortDeviceBusy(channelExtension, 0xFF, 0, 1);
        Irb->IrbStatus = IRB_STATUS_BUSY;
        AhciCompleteRequest(channelExtension, Irb);
        RecordExecutionHistory(channelExtension, 0x10030020);//AllocateQueueTagFailed
        return TRUE;
    } 
    // if the tag returned can't be used, something is seriously wrong. Reject the command to be retried later
    if( ( ( (1 << Irb->QueueTag) & ci) > 0) || ( ( (1 << Irb->QueueTag) & sact) > 0) ) {
        channelExtension->Reserved0 |= (1 << 5);
        
        AtaPortDeviceBusy(channelExtension, 0xFF, 0, 2);
        Irb->IrbStatus = IRB_STATUS_BUSY;
        AhciCompleteRequest(channelExtension, Irb);
        RecordExecutionHistory(channelExtension, 0x10040020);//Tag given for slot in use
        return TRUE;
    } //Irb->QueueTag and Slot[Irb->QueueTag] are now guaranteed ready.

  //1.5 Initialize the Command Header, Slot and History structures
    cmdTableInitializer = (PUCHAR) Irb->SenseInfoBuffer;
    for (i= 0; i < Irb->SenseInfoBufferLength; i++) {
        (*(cmdTableInitializer))=0x0;
        cmdTableInitializer++; 
    }
    cmdHeader = channelExtension->CommandList;
    cmdHeader += Irb->QueueTag;
    //Identify slot and history
    slotContent = &channelExtension->Slot[Irb->QueueTag]; 
    if ( channelExtension->CommandHistoryNextAvailableIndex >= 64) {
        channelExtension->CommandHistoryNextAvailableIndex = 0;
    }else{
        channelExtension->CommandHistoryNextAvailableIndex++;
    }
    // Initialize slot and history
    slotContent->CommandHistoryIndex = channelExtension->CommandHistoryNextAvailableIndex;
    cmdHistory = &channelExtension->CommandHistory[slotContent->CommandHistoryIndex];
    slotContent->Irb = Irb; 
    slotContent->CmdHeader = cmdHeader;
 
    cmdHistory->Tag = slotContent->Irb->QueueTag;
    AtaPortMoveMemory(&cmdHistory->InitialTaskFile, &slotContent->Irb->IdeTaskFile, 0x10);
    AtaPortMoveMemory(&cmdHistory->InitialPx, channelExtension->Px, 0x40);
    cmdHistory->Function = slotContent->Irb->Function;
    cmdHistory->IrbStatus = 0;
    
  //2.1 Perform IO transformations if needed
    if( ! IsReturnResults(slotContent->Irb) ) {
        //If NCQ is supported, make this IO NCQ as long as it isn't passed thru
        if( channelExtension->StateFlags.NCQ_Activated ) {
            if (Irb->Function == IRB_FUNCTION_ATA_WRITE)  {
                // Keep track of FUA to add it back in when the command is put in the FIS
                if( (Irb->IdeTaskFile.Current.bCommandReg == IDE_COMMAND_WRITE_DMA_FUA_EXT) || 
                    (Irb->IdeTaskFile.Current.bCommandReg == IDE_COMMAND_WRITE_MULTIPLE_FUA_EXT) ) {
                        slotContent->StateFlags.FUA = TRUE;
                }
                Irb->IdeTaskFile.Current.bCommandReg = 0x61; //WRITE FPDMA QUEUED
            }
            if (Irb->Function == IRB_FUNCTION_ATA_READ) {
                Irb->IdeTaskFile.Current.bCommandReg = 0x60; //READ FPDMA QUEUED
            }
        } else {
            // Make all writes into WRITE_DMA
            if (Irb->Function == IRB_FUNCTION_ATA_WRITE)  {
                // If FUA, keep track of FUA even there is nothing to do with this bit later
                if( (Irb->IdeTaskFile.Current.bCommandReg == IDE_COMMAND_WRITE_DMA_FUA_EXT) || 
                    (Irb->IdeTaskFile.Current.bCommandReg == IDE_COMMAND_WRITE_MULTIPLE_FUA_EXT) ) {
                        Irb->IdeTaskFile.Current.bCommandReg = IDE_COMMAND_WRITE_DMA_FUA_EXT;
                        slotContent->StateFlags.FUA = TRUE;
                } else {
                    // otherwise transform to plain WRITE_DMA
                    if (Is48BitIrb(slotContent->Irb)) {
                        Irb->IdeTaskFile.Current.bCommandReg = IDE_COMMAND_WRITE_DMA_EXT; 
                    } else {
                        Irb->IdeTaskFile.Current.bCommandReg = IDE_COMMAND_WRITE_DMA; 
                    }
                }
            }
            // Make all reads into READ_DMA
            if (Irb->Function == IRB_FUNCTION_ATA_READ) {
                if (Is48BitIrb(slotContent->Irb)) {
                    Irb->IdeTaskFile.Current.bCommandReg = IDE_COMMAND_READ_DMA_EXT; 
                } else {
                    Irb->IdeTaskFile.Current.bCommandReg = IDE_COMMAND_READ_DMA; 
                }
            }
        }
    }
  //2.2 Program the Command Table, PRD Table and Command Header    
    //Zero Initialize the Command Table
    cmdTable = (PAHCI_COMMAND_TABLE) slotContent->Irb->IrbExtension;
    cmdTableInitializer = (PUCHAR) cmdTable;
    for (i= 0; i < sizeof(AHCI_COMMAND_TABLE); i++) {
        (*(cmdTableInitializer))=0;
        cmdTableInitializer++; 
    }
    //Program the CFIS in the CommandTable
    if ( IsMiniportCommand(slotContent->Irb) ) {
        if(slotContent->Irb->Function == IRB_FUNCTION_POWER_CHANGE) {
            if ( slotContent->Irb->PowerChange.DesiredPowerState == IdePowerD3 ) {
                NonDataCMDtoATA_CFIS(channelExtension, slotContent, IDE_COMMAND_STANDBY_IMMEDIATE);
            } else {
                slotContent->Irb->IrbStatus = IRB_STATUS_SUCCESS;
                cmdHistory->Tag |= (0x14 << 8);
                ReleaseSlottedCommand(channelExtension, Irb->QueueTag);//slotContent);
                RecordExecutionHistory(channelExtension, 0x10050020);//Power Change action not needed
                return TRUE;
            }    
        } else {
            slotContent->Irb->IrbStatus = IRB_STATUS_INVALID_REQUEST;
            cmdHistory->Tag |= (0x16 << 8);
            ReleaseSlottedCommand(channelExtension, Irb->QueueTag); //slotContent);
            RecordExecutionHistory(channelExtension, 0x10060020);//Invalid Miniport Command
            return TRUE;
        }
    } else if ( IsAtapiCommand(slotContent->Irb) ) {
        IRBtoATAPI_CFIS(channelExtension, slotContent);
    } else if ( IsAtaCommand(slotContent->Irb) ) {
        IRBtoATA_CFIS(channelExtension, slotContent);
    } else {
        slotContent->Irb->IrbStatus = IRB_STATUS_INVALID_REQUEST;
        cmdHistory->Tag |= (0x17 << 8);
        ReleaseSlottedCommand(channelExtension, Irb->QueueTag); //slotContent);
        RecordExecutionHistory(channelExtension, 0x10070020);//Invalid IRB Function
        return TRUE;
    }

  //2.3 Build the Command Header
    if( IRB_FOR_DATA_TRANSFER(slotContent->Irb) ) {
        prdtLength = IRBtoPRDT(channelExtension, slotContent);
        if (prdtLength == -1) {
            slotContent->Irb->IrbStatus = IRB_STATUS_INVALID_REQUEST;
            cmdHistory->Tag |= (0x19 << 8);
            ReleaseSlottedCommand(channelExtension, Irb->QueueTag); //slotContent);
            RecordExecutionHistory(channelExtension, 0x10070020);//Invalid IRB Function
            return TRUE;
        }
        IRBtoCmdHeader(channelExtension, slotContent, prdtLength, FALSE);
    } else {
        IRBtoCmdHeader(channelExtension, slotContent, 0, FALSE);
    } 
  //2.4 Get the Command Table's physical address and verify the alignment
    if (&channelExtension->Local.Irb == Irb) {
        irbExtensionPhysicalAddress = channelExtension->Local.IrbExtensionPhysicalAddress;
    } else {
        irbExtensionPhysicalAddress = AtaPortGetPhysicalAddress(channelExtension,NULL,slotContent->Irb->IrbExtension,NULL);    
    }  
    if ((irbExtensionPhysicalAddress.LowPart % 128) == 0 ) {
        cmdHeader->CTBA.AsUlong = irbExtensionPhysicalAddress.LowPart;
    } else {
        slotContent->Irb->IrbStatus = IRB_STATUS_INVALID_REQUEST;
        cmdHistory->Tag |= (0x18 << 8);
        ReleaseSlottedCommand(channelExtension, Irb->QueueTag); //slotContent);
        RecordExecutionHistory(channelExtension, 0x10080020);//Invalid PhyscialAddress alignment
        return TRUE;
    }
    //If the controller supports 64 bits, write the high part too
    if (channelExtension->CAP.S64A)    {
        AtaPortWriteRegisterUlong(&cmdHeader->CTBAU, irbExtensionPhysicalAddress.HighPart);
    }

  //3.1 Sort it 
    //Keep track of high priority outside of the Slices 
    if ( IsHighPriorityIrb(slotContent->Irb) ){
        channelExtension->SlotManager.HighPriorityAttribute |= ( 1 << slotContent->Irb->QueueTag);
    }
    //Put the slot content in the correct Slice
    if ( IsFPDMACommand(slotContent->Irb)) {
        channelExtension->SlotManager.NCQueueSlice |= ( 1 << slotContent->Irb->QueueTag);
    } else if ( IsReturnResults(slotContent->Irb) ) {
        channelExtension->SlotManager.SingleIoSlice |= ( 1 << slotContent->Irb->QueueTag);
    } else if ( IsNormalCommand(slotContent->Irb)) {
        channelExtension->SlotManager.NormalQueueSlice |= ( 1 << slotContent->Irb->QueueTag);
    } else {
        channelExtension->SlotManager.SingleIoSlice |= ( 1 << slotContent->Irb->QueueTag);
    }
    //Check to see if IO is ready to be programmed
    ActivateQueue(channelExtension);

    RecordExecutionHistory(channelExtension, 0x10000020);//Exit AhciHwStartIo
    return TRUE;
}

BOOLEAN
  ActivateQueue(
    PAHCI_CHANNEL_EXTENSION ChannelExtension
    )
/*++

It assumes:

Called by:    
    AhciHwStartIO
It performs:
    (overview)
    1. Ensures the channel is ready for programming
    2. Program the next IO according to the priority scheme
    (details)
    1.1  Initialize variables
    1.2 If the programming should not happen now, leave, ActivateQueue will be called again when these conditions are changed
    2.1 Choose the Queue with which to program the controller
        Algorithm:
            2.1.1 Single IO IRBs (including Request Sense and non data control commands) have highest priority.
            2.1.2 When there are no Single IO commands, Normal IO get the next highest priority
            2.1.3 When there are no Single or Normal commands, NCQ commands get the next highest priority
            2.1.4 In the case that no IO is present in any Slices, program nothing
    2.2 Program all the IO from the chosen queue into the controller

Affected Variables/Registers:
    channelExtension
    CI
    SACT
Return Values:
--*/
{
    AHCI_COMMAND cmd;
    AHCI_SERIAL_ATA_CONTROL sctl;
    ULONG sact;
    ULONG ci;
    ULONG slotsToActivate;
    BOOLEAN activateNcq;
    int i;

  //1.1 Initialize variables
    RecordExecutionHistory(ChannelExtension, 0x00000022);//ActivateQueue
    slotsToActivate = 0;
    activateNcq = FALSE;

  //1.2 If the programming should not happen now, leave
    if (ChannelExtension->StateFlags.StartCapable == FALSE) {
        RecordExecutionHistory(ChannelExtension, 0x10030022);//Channel Not Start Capable 
        return FALSE;
    }
    if ( ChannelExtension->StateFlags.QueuePaused == TRUE) {
        RecordExecutionHistory(ChannelExtension, 0x10020022);//Channel Queue Paused
        return FALSE;
    }
    cmd.AsUlong = AtaPortReadRegisterUlong(&ChannelExtension->Px->CMD.AsUlong);
    if (cmd.ST == 0) {
        RecordExecutionHistory(ChannelExtension, 0x10010022);//Channel Not Yet Started 
        return FALSE;
    }

  //2.1 Choose the Queue with which to program the controller
    sact = AtaPortReadRegisterUlong(&ChannelExtension->Px->SACT);
    ci = AtaPortReadRegisterUlong(&ChannelExtension->Px->CI);
  //2.1.2 Single IO IRBs have highest priority.
    if( ChannelExtension->SlotManager.SingleIoSlice != 0) {
        if ( ( sact == 0 ) && ( ci == 0 ) ) {
            //Safely get Single IO in round robin fashion
            i = GetSingleIo(ChannelExtension);
            if (i != 0xff) {
                slotsToActivate = (1 << i);
                ChannelExtension->SlotManager.SingleIoSlice &= ~(1 << i);
                ChannelExtension->StateFlags.QueuePaused = TRUE;            //and pause the queue so no other IO get programmed
            } 
        }
  //2.1.2 When there are no Single IO commands, Normal IO get the next highest priority
    } else if( ChannelExtension->SlotManager.NormalQueueSlice != 0) {
        // Normal commands can not be sent when NCQ commands are outstanding.  When the NCQ commands complete ActivateQueue will get called again.
        if ( sact == 0) {
            //Grab the High Priority Normal IO before the Low Priority Normal IO
            slotsToActivate = ChannelExtension->SlotManager.HighPriorityAttribute & ChannelExtension->SlotManager.NormalQueueSlice;
            if (slotsToActivate > 0) {
                ChannelExtension->SlotManager.NormalQueueSlice &= ~slotsToActivate;
            } else {
                slotsToActivate = ChannelExtension->SlotManager.NormalQueueSlice;
                ChannelExtension->SlotManager.NormalQueueSlice = 0;                
            }
        }
  //2.1.3 When there are no Single or Normal commands, NCQ commands get the next highest priority
    } else if (ChannelExtension->SlotManager.NCQueueSlice != 0) {
        // NCQ commands can not be sent when Normal commands are outstanding.  When the Normal commands complete, Activate Queue will get called again.
        if ( ( ci != 0 ) && (sact == 0) ) {
            slotsToActivate = 0;
        } else {
            //Grab the High Priority NCQ IO before the Low Priority NCQ IO
            slotsToActivate = ChannelExtension->SlotManager.HighPriorityAttribute & ChannelExtension->SlotManager.NCQueueSlice;
            if (slotsToActivate > 0) {
                activateNcq = TRUE;     //Remember to program SACT for these commands
                ChannelExtension->SlotManager.NCQueueSlice &= ~slotsToActivate;
            } else {
                activateNcq = TRUE;
                slotsToActivate = ChannelExtension->SlotManager.NCQueueSlice;
                ChannelExtension->SlotManager.NCQueueSlice = 0;
            } 
        }
  //2.1.4 In the case that no IO is present in any Slices, program nothing
    } else {
        RecordExecutionHistory(ChannelExtension, 0x10040022);//No Commands to program
        return FALSE;
    }
  //2.1 Program all the IO from the chosen queue into the controller
    ChannelExtension->SlotManager.CommandsIssued |= slotsToActivate;

    if (activateNcq) {
        AtaPortWriteRegisterUlong(&ChannelExtension->Px->SACT, slotsToActivate);
    }
    AtaPortWriteRegisterUlong(&ChannelExtension->Px->CI, slotsToActivate);

    RecordExecutionHistory(ChannelExtension, 0x10050022);//Exit ActivateQueue
    return TRUE;
}

BOOLEAN
  AhciHwInterrupt (
    IN PVOID ChannelExtension
    )
{
/*++
AtaHwInterrupt is the interrupt handler. 
If the miniport driver requires a large amount of time to process the interrupt it must defer processing to a worker routine.
This routine must attemp one clear the interrupt on the HBA before it returns TRUE.

It assumes:
    The following AtaPort routines shall not be called from the AtaHwInterrupt routine – AtaPortCompleteAllRequests and AtaPortDeviceBusy. 
    The miniport could however request for a worker routine and make the calls in the worker routine.

Called by:    
    external

It performs:
    (overview)
    1. Prepare for handling the interrupt
    2. Handle interrupts on this channel
    3. Clear channel interrupt
    4. Complete outstanding commands
    5. Handle error processing if necessary
    (details)
    1.1 Verify the interrupt is for this channel
    1.2 Initialize Variables
        AHCI 1.1 Section 5.5.3 - 1.    
        "Software determines the cause of the interrupt by reading the PxIS register.  It is possible for multiple bits to be set"
    2.1 Understand interrupts on this channel
        AHCI 1.1 Section 5.5.3 - 2.    
        "Software clears appropriate bits in the PxIS register corresponding to the cause of the interrupt."
        2.1.1 Handle Fatal Errors
            Clear the PxIS Fatal Error bits
            And prep for error handling
        2.1.2 Handle Normal Command Completion
            Clear the PxIS Normal Command Completion bits
        2.1.3 Handle non Native HotPlug Events
        2.1.3 Handle Serial ATA Errors
            Clear the PxSERR bits to clear PxIS
        2.1.4 Handle Datalength Mismatch Error
            Clear the PxIS Overflow bit bits
            And prep for dataLengthMisMatch handling
    3.1 Clear channel interrupt
        AHCI 1.1 Section 5.5.3 - 3.    
        "Software clears the interrupt bit in IS.IPS corresponding to the port."
    4.1 Complete outstanding commands
        AHCI 1.1 Section 5.5.3 - 4.    
        "If executing non-queued commands, software reads the PxCI register, and compares the current value to the list of commands previously issued by software that are still outstanding.  If executing native queued commands, software reads the PxSACT register and compares the current value to the list of commands previously issued by software.  Software completes with success any outstanding command whose corresponding bit has been cleared in the respective register. PxCI and PxSACT are volatile registers; so
ftware should only use their values to determine commands that have completed, not to determine which commands have previously been issued."
        4.1.1 Determine if there was an ATA error on the command completed. Error register is only valid if bit0 of Status is 1
        4.1.2 Check to see if the right amount of data transfered
            set channelExtension->Slot[i]->DataTransferLength = the amount transfered
        4.1.3 Otherwise, command completed successfully
    5.1 Handle error processing
        Until the error recovery can be completed, don't let any more IO's come through
        AHCI 1.1 Section 5.5.3 - 5.    
        "If there were errors, noted in the PxIS register, software performs error recovery actions (see section 6.2.2)."
        AHCI 1.1 Section 6.2.2.1 Non-Queued Error Recovery (this may take a while, better queue a DPC)
        Complete further processing in the worker routine and enable interrupts on the channel
    5.2 Handle bus rescan processing processing
Affected Variables/Registers:

Return Values:
    AtaHwInterrrupt returns TRUE if the interrupt is generated by the channel. 
    If the channel did not generate the interrupt the routine should return FALSE as soon as possible. The port driver would then call the AtaHwInterrupt routine for the next channel.
--*/
    PAHCI_CHANNEL_EXTENSION channelExtension = (PAHCI_CHANNEL_EXTENSION) ChannelExtension;
                            //Error Handling flags
    AHCI_TASK_FILE_DATA tfd;
                            //Interrupt handling structures
    AHCI_INTERRUPT_STATUS pxis;
    AHCI_INTERRUPT_STATUS pxisMask;
    ULONG ci;
    ULONG sact;
    ULONG outstanding;
    ULONG is;
    AHCI_SERIAL_ATA_STATUS ssts;
    AHCI_SERIAL_ATA_ERROR serr;
    AHCI_SERIAL_ATA_ERROR serrMask;
    AHCI_COMMAND cmd;
    UCHAR ataStatus;
    UCHAR offendingNCQ_Command;
    
    PAHCI_COMMAND_HEADER cmdHeader;
    UCHAR i;

  //1.1 Verify the interrupt is for this channel
    is = AtaPortReadRegisterUlong(channelExtension->ControllerIS);
    if( (is & (1 << channelExtension->ChannelNumber)) == 0) {
        return FALSE;
    }
    RecordExecutionHistory(ChannelExtension, 0x00000005);//AhciHwInterrupt

  //1.2 Initialize Variables
    cmdHeader = channelExtension->CommandList;
    pxis.AsUlong = AtaPortReadRegisterUlong(&channelExtension->Px->IS.AsUlong);
    pxisMask.AsUlong = serrMask.AsUlong = 0;
    ssts.AsUlong = AtaPortReadRegisterUlong(&channelExtension->Px->SSTS.AsUlong);
    ci = AtaPortReadRegisterUlong(&channelExtension->Px->CI);
    sact = AtaPortReadRegisterUlong(&channelExtension->Px->SACT);

  //2.1 Understand interrupts on this channel
    //2.1.1 Handle Fatal Errors
    if (pxis.IFS || pxis.HBDS || pxis.HBFS || pxis.TFES) {
        channelExtension->Reserved0 |= (1 << 0);
        pxisMask.AsUlong = 0;
        pxisMask.IFS = pxisMask.HBDS = pxisMask.HBFS = pxisMask.TFES = 1;
        AtaPortWriteRegisterUlong( &channelExtension->Px->IS.AsUlong, pxisMask.AsUlong);
        
      //call the correct error handling based on current hw queue workload type
        sact = AtaPortReadRegisterUlong(&channelExtension->Px->SACT);
        if(sact != 0) {
          //5.1 Handle error processing
            channelExtension->StateFlags.CallAhciReset = TRUE;
            AtaPortRequestSynchronizedRoutine(channelExtension, WorkerDispatch);

          //Give NCQ one chance
            if ( channelExtension->StateFlags.NCQ_Succeeded == FALSE ){
                channelExtension->StateFlags.NCQ_Activated = FALSE;
            }
        } else {
          //5.1 Handle error processing
            channelExtension->StateFlags.CallAhciNonQueuedErrorRecovery = TRUE;
            AtaPortRequestSynchronizedRoutine(channelExtension, WorkerDispatch);
        }
    }

    //2.1.3 Handle non Native HotPlug Events
    if (pxis.DMPS) {
        cmd.AsUlong = AtaPortReadRegisterUlong(&channelExtension->Px->CMD.AsUlong);
        if (cmd.MPSP) {
            pxisMask.AsUlong = 0;
            pxisMask.DMPS = 1;
            AtaPortWriteRegisterUlong( &channelExtension->Px->IS.AsUlong, pxisMask.AsUlong);
          //5.2 Handle bus rescan processing processing
            channelExtension->StateFlags.CallAhciReportBusChange = TRUE;
            AtaPortRequestSynchronizedRoutine(channelExtension, WorkerDispatch);
        }
    }

    if (pxis.CPDS) {
        cmd.AsUlong = AtaPortReadRegisterUlong(&channelExtension->Px->CMD.AsUlong);
        pxisMask.AsUlong = 0;
        pxisMask.CPDS = 1;
        AtaPortWriteRegisterUlong( &channelExtension->Px->IS.AsUlong, pxisMask.AsUlong);
      //5.2 Handle bus rescan processing processing
        channelExtension->StateFlags.CallAhciReportBusChange = TRUE;
        AtaPortRequestSynchronizedRoutine(channelExtension, WorkerDispatch);
    }

    //2.1.3.1 Handle Serial ATA Errors (Hotplug insertion or unsolicited COMINIT)
    if (pxis.PCS) {
        //When PxSERR.DIAG.X is set to one this bit indicates a COMINIT signal was received.  This bit is reflected in the P0IS.PCS bit.
        serrMask.DIAG.X = 1;
        AtaPortWriteRegisterUlong(&channelExtension->Px->SERR.AsUlong, serrMask.AsUlong);
        
        //PCS = 1 could be an unsolicited COMINIT on an already detected drive. See 6.2.2.3    Recovery of Unsolicited COMINIT 
        if ((!channelExtension->StateFlags.IgnoreHotplugDueToResetInProgress) && 
            (!cmd.ST ) ){
          //5.2 Handle bus rescan processing processing
            channelExtension->StateFlags.CallAhciReportBusChange = TRUE;
            AtaPortRequestSynchronizedRoutine(channelExtension, WorkerDispatch);
        }
    }
    //2.1.3.2 Handle Serial ATA Errors (Hotplug removal or PHY Power Management event)
    if (pxis.PRCS) {
        //Hot plug removals are detected via the PxIS.PRCS bit that directly reflects the PxSERR.DIAG.N bit.  
        //Note that PxSERR.DIAG.N is also set to ‘1’ on insertions and during interface power management entry/exit.
        serrMask.DIAG.N = 1;
        AtaPortWriteRegisterUlong(&channelExtension->Px->SERR.AsUlong, serrMask.AsUlong);
        if ( (channelExtension->StateFlags.IgnoreHotPlug == FALSE) && (ssts.DET == 0) && (ssts.IPM == 0) ) {
            if (! channelExtension->StateFlags.IgnoreHotplugDueToResetInProgress) {
              //5.2 Handle bus rescan processing processing            
                channelExtension->StateFlags.CallAhciReportBusChange = TRUE;
                AtaPortRequestSynchronizedRoutine(channelExtension, WorkerDispatch);
            }
        }
    }
    //2.1.3.3 Handle Serial ATA Errors (everything else)
    serr.AsUlong = AtaPortReadRegisterUlong(&channelExtension->Px->SERR.AsUlong);
    AtaPortWriteRegisterUlong(&channelExtension->Px->SERR.AsUlong, ~0);
    //2.1.4 Handle Datalength Mismatch Error
    if (pxis.OFS) {
        channelExtension->Reserved0 |= (1 << 2);
        pxisMask.AsUlong = 0;
        pxisMask.OFS = 1;
        AtaPortWriteRegisterUlong( &channelExtension->Px->IS.AsUlong, pxisMask.AsUlong);
      //5.1 Handle error processing
        channelExtension->StateFlags.CallAhciReset = TRUE;
        AtaPortRequestSynchronizedRoutine(channelExtension, WorkerDispatch);
    }

    //2.1.15 Handle NonFatal Errors
    if (pxis.INFS) {
        channelExtension->Reserved0 |= (1 << 1);
        pxisMask.AsUlong = 0;
        pxisMask.INFS = 1;
        AtaPortWriteRegisterUlong( &channelExtension->Px->IS.AsUlong, pxisMask.AsUlong);
    } 
    //2.1.2 Handle Normal Command Completion
    if (pxis.DHRS || pxis.PSS || pxis.DSS || pxis.SDBS || pxis.DPS) {
        pxisMask.AsUlong =0x2F;
        AtaPortWriteRegisterUlong( &channelExtension->Px->IS.AsUlong, pxisMask.AsUlong);
    } 

  //3.1 Clear channel interrupt    
    is = 0;
    is |= (1 << channelExtension->ChannelNumber);    
    AtaPortWriteRegisterUlong(channelExtension->ControllerIS, is);

  //4.1    Complete outstanding commands
    outstanding = ci | sact;
    if( ((channelExtension->SlotManager.CommandsIssued & ~outstanding) > 0) && 
        (channelExtension->StateFlags.CallAhciReset == FALSE) &&
        (channelExtension->StateFlags.CallAhciNonQueuedErrorRecovery == FALSE)
       ){
        channelExtension->SlotManager.CommandsToComplete |= channelExtension->SlotManager.CommandsIssued & ~outstanding;
        channelExtension->SlotManager.CommandsIssued &= outstanding;
        AhciCompleteIssuedIRBs(channelExtension, IRB_STATUS_SUCCESS);
    }

    RecordExecutionHistory(ChannelExtension, 0x10000005);//Exit AhciHwInterrupt
    return TRUE;
}
BOOLEAN
  AhciHwReset (
    IN PVOID ChannelExtension
    )
{
/*++
AtaHwReset can be called even if the miniport driver is not ready for another request. 
The miniport driver should complete all pending requests and must reset the given channel.

It assumes:
    nothing

Called by:    
    external

It performs:
    COMRESET along with completing commands to be retried and restoring settings that may be be persistent across a COMRESET
    
    (overview)
    1 Initialize 
    2 Perform COMReset
    3 Complete all outstanding commands
    4 Restore device configuration

Affected Variables/Registers:
    SCTL, CI, SACT
    Channel Extension

Return Values:
    AtaHwReset return TRUE if the reset operation succeeded. 
    If the reset failed the routine must return FALSE. 
--*/
    PAHCI_CHANNEL_EXTENSION channelExtension;
    PSLOT_CONTENT slotContent;
    UCHAR i;
    UCHAR numberOfCommandsOutstanding;

  //1.1 Initialize Variables
    channelExtension = (PAHCI_CHANNEL_EXTENSION) ChannelExtension;
    RecordExecutionHistory(channelExtension, 0x00000006);//AhciHwReset

  //2.1 Stop the channel
    if (! P_NotRunning(channelExtension, channelExtension->Px) ) {
        return FALSE;
    }
  //2.2 Perform the COMRESET
    AhciCOMRESET(channelExtension, channelExtension->Px);

  //3.1 Complete all outstanding commands for retry
    channelExtension->SlotManager.CommandsToComplete |= 
                    (channelExtension->SlotManager.NCQueueSlice | 
                     channelExtension->SlotManager.NormalQueueSlice | 
                     channelExtension->SlotManager.SingleIoSlice |
                     channelExtension->SlotManager.CommandsIssued);
    channelExtension->SlotManager.CommandsIssued = 0;
    channelExtension->SlotManager.NCQueueSlice = 0;
    channelExtension->SlotManager.NormalQueueSlice = 0;
    channelExtension->SlotManager.SingleIoSlice = 0;
    channelExtension->SlotManager.HighPriorityAttribute = 0;

    numberOfCommandsOutstanding = 0;
    for (i=0; i <= (channelExtension->CAP.NCS); i++) {
        if( ( channelExtension->SlotManager.CommandsToComplete & (1 << i) ) > 0) {
            numberOfCommandsOutstanding++;                
        }
    }

    if (numberOfCommandsOutstanding > 1);
        for (i=0; i <= (channelExtension->CAP.NCS); i++) {
            if( ( channelExtension->SlotManager.CommandsToComplete & (1 << i) ) > 0) {
                slotContent = &channelExtension->Slot[i];
                if (slotContent->Irb->Function == IRB_FUNCTION_ATA_IDENTIFY)
                {
                    slotContent->Irb->IrbStatus = IRB_STATUS_BUSY;
                }
            }
        }

    AhciCompleteIssuedIRBs(channelExtension, IRB_STATUS_BUS_RESET);
 
  //4.1 Restore device configuration
    RestorePreservedSettings(ChannelExtension);
  //2.3 Start the channel
    P_Running_StartAttempt(ChannelExtension); 

    RecordExecutionHistory(channelExtension, 0x10000006);//Exit AhciHwReset
    return TRUE;
}

BOOLEAN 
  AhciHwInitialize (
    IN PVOID ChannelExtension,
    IN OUT PIDE_DEVICE_PARAMETERS DeviceParameters,
    IN PIDENTIFY_DEVICE_DATA IdentifyData
    )
{
/*++
The AtaHwInitialize routine is called as soon as the devices on a channel are enumerated. It is called once for every device enumerated on the channel. 
The routine is responsible to configure the device based on the parameters specified in the DeviceParameters structure. 
It is recommended that the miniport driver configure the device based on the values set by the port driver. 
However, the miniport could modify the parameters in exceptional cases and configure the device accordingly. 
On return from this routine the port driver will update itself with the new parameters set by the miniport driver.

The AtaHwInitialize routine configures the _devices_ on the given ATA channel according to the parameters in the DeviceInfo structure. 

It assumes:
The port driver ensures that there are no outstanding requests for any device attached to that channel before invoking AtaHwInitialize.

Called by:    
    external

It performs:
    Device Initialization (This is also used in CrashDump)

    (overview)
    1 Initialize
    2 Check for controller/device matched Accomodations
    3 Negotiate Agressive Power Management
    4 Negotiate ATA features
    5 Negotiate ATAPI features
    6 Configure device with persistent configuration commands


    (details)
    1.1 Initialize Variables
    1.2 Intialize Device Parameters
    2.1 Check for controller matched Accomodations
    3.1 Negotiate Agressive Power Management
    4.1 Negotiate NCQ
    4.2 Persist Write Cache
    5.1 Persist SATA transfer mode for some SATAI/PATAPI bridge chips
    6.1 Configure device with persistent configuration commands
Affected Variables/Registers:
    
Return Values:

--*/
    PAHCI_CHANNEL_EXTENSION channelExtension;
    PUCHAR source;
    PUCHAR dest;

    AHCI_SERIAL_ATA_CONTROL sctl;
    AHCI_COMMAND cmd;

  //1.1 Initialize Variables
    channelExtension = (PAHCI_CHANNEL_EXTENSION) ChannelExtension;
    RecordExecutionHistory(channelExtension, 0x00000007);//AhciHwInitialize
  //1.2 Intialize Device Parameters
    //ATAport uses the min(DeviceParameters->NumberOfOverlappedRequests, ChannelConfiguration->NumberOfOverlappedRequests) to determine the number of IO this device can handle.  Since it is currently 1:1, they are the same.
    DeviceParameters->NumberOfOverlappedRequests = channelExtension->NumberOfOverlappedRequests; 

    //DeviceParameters came from Identify Device or Identify Packet Device. I see no need to mess with any others.
    AtaPortMoveMemory(&channelExtension->DeviceExtension[0].DeviceParameters, DeviceParameters, sizeof(IDE_DEVICE_PARAMETERS) );
    AtaPortMoveMemory(&channelExtension->DeviceExtension[0].IdentifyData, IdentifyData, sizeof(IDENTIFY_DEVICE_DATA) );
    //2.1 Check for controller/device matched Accomodations

  //3.1 Agressive Power Management
    //Controller supports APM
    if ( ( channelExtension->CAP.SALP ) && (channelExtension->StateFlags.Crashing == FALSE) ) {
        //Host initiated   
        if ( channelExtension->StateFlags.Hipm_Disallowed == FALSE) {
            if ( (channelExtension->DeviceExtension[0].IdentifyData.ReservedWords76[0] & (1 << 9)) > 0) {
                cmd.AsUlong = AtaPortReadRegisterUlong(&channelExtension->Px->CMD.AsUlong);
                cmd.ALPE = 1;
                cmd.ASP = 0; //0 = partial, 1 = slumber
                AtaPortWriteRegisterUlong(&channelExtension->Px->CMD.AsUlong, cmd.AsUlong);
            
              //Set PxSCTL.IPM to 0h to remove restrictions on any interface power management state transitions.
                sctl.AsUlong = AtaPortReadRegisterUlong(&channelExtension->Px->SCTL.AsUlong);
                sctl.IPM = 0;
                AtaPortWriteRegisterUlong(&channelExtension->Px->SCTL.AsUlong, sctl.AsUlong);
            }       
        }
        //Device initiated
        if (channelExtension->StateFlags.Dipm_Allowed == TRUE) {
            if ((channelExtension->DeviceExtension[0].IdentifyData.ReservedWords76[2] & (1 << 3)) >  0) {
              
              //The enable/disable state for device initiated power management shall persist across software reset.
              //The enable/disable state shall be reset to its default disabled state upon COMRESET.
                AddSetFeatures(channelExtension, IDE_FEATURE_ENABLE_SATA_FEATURE, IDE_SATA_FEATURE_DEVICE_INITIATED_POWER_MANAGEMENT);
                              
              //Set PxSCTL.IPM to 0h to remove restrictions on any interface power management state transitions.
                sctl.AsUlong = AtaPortReadRegisterUlong(&channelExtension->Px->SCTL.AsUlong);
                sctl.IPM = 0;
                AtaPortWriteRegisterUlong(&channelExtension->Px->SCTL.AsUlong, sctl.AsUlong);
            }   
        }
    }
  
  //4 Negotiate ATA features 
    if (DeviceParameters->IdeDeviceType == DeviceIsAta) {
      //4.1 Negotiate NCQ features
        if (channelExtension->StateFlags.Crashing == FALSE) {
            if ((channelExtension->StateFlags.NCQ_Disallowed == FALSE) && 
                 ( channelExtension->CAP.SNCQ) && 
                 ((channelExtension->DeviceExtension[0].IdentifyData.ReservedWords76[0] & (1 << 8)) > 0) &&
                 (channelExtension->DeviceExtension[0].IdentifyData.QueueDepth == 0x1F) ) { 

                DeviceParameters->AddressTranslation = Lba48BitMode;
                channelExtension->StateFlags.NCQ_Activated = TRUE;
            }
        }        
        if (channelExtension->NumberOfOverlappedRequests == 1) {
            channelExtension->StateFlags.NCQ_Activated = FALSE;
        }
      //4.2 Persist Write Cache
        AddSetFeatures(channelExtension, IDE_FEATURE_ENABLE_WRITE_CACHE, 0);
  //5.1 Persist SATA transfer mode for some SATAI/PATAPI bridge chips
    } else if (DeviceParameters->IdeDeviceType == DeviceIsAtapi) {
        AddSetFeatures(channelExtension, IDE_FEATURE_SET_TRANSFER_MODE, 0x42);
      //OPTIONAL: SATA or SATA bridge identification
      //Check "word93 == 0" to detect a SATA device, but this is just a guess based on (a) vague language in the SATA 1.0a docs and (b) field experience.
    }

  //2.1 Check for controller/device matched Accomodations

  //6.1 Configure device with persistent configuration commands
    RestorePreservedSettings(channelExtension);

    RecordExecutionHistory(channelExtension, 0x10000007);//Exit AhciHwInitialize
    return TRUE;
}

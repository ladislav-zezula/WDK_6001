/*++

Copyright (C) Microsoft Corporation, 2004

Module Name:

    state.h

Abstract:



Notes:

Revision History:

        Nathan Obr (natobr),  February 2005
--*/
#pragma once

#define KB                              (1024)
#define AHCI_MAX_TRANSFER_LENGTH        (128 * KB)
#define MAX_SETTINGS_PRESERVED          32

#define WaitOnDET       0x11
#define WaitWhileDET1   0x12
#define WaitOnDET3      0x13
#define WaitOnFRE       0x14
#define WaitOnBSYDRQ    0x15
#define StartComplete   0x16
#define StartFailed     0xff


typedef struct _CHANNEL_STATE_FLAGS {
    USHORT StartCapable :1;
    USHORT Crashing :1;
    USHORT SingleIo: 1;
    USHORT QueuePaused: 1;

    USHORT NCQ_Disallowed :1;
    USHORT NCQ_Activated :1;
    USHORT NCQ_Succeeded :1;
    USHORT NCQ_NeverNonQueuedErrorRecovery: 1;

    USHORT CallAhciReset: 1;
    USHORT CallAhciNonQueuedErrorRecovery: 1;
    USHORT CallAhciReportBusChange: 1;
    USHORT IgnoreHotPlug: 1;

    USHORT IgnoreHotplugDueToResetInProgress: 1;
    USHORT ResetInInit: 1;
    USHORT Hipm_Disallowed: 1;
    USHORT Dipm_Allowed: 1;

} CHANNEL_STATE_FLAGS, *PCHANNEL_STATE_FLAGS;

typedef struct _AHCI_DEVICE_EXTENSION {
    IDE_DEVICE_PARAMETERS DeviceParameters;
    IDENTIFY_DEVICE_DATA IdentifyData;
} AHCI_DEVICE_EXTENSION, *PAHCI_DEVICE_EXTENSION;

typedef struct _COMMAND_HISTORY {
    union {             //0x10 bytes
        IDE_TASK_FILE InitialTaskFile;
        UCHAR Cdb[16];
    };
    ULONG InitialPx[0x10]; //0x40 bytes
    ULONG CompletionPx[0x10];

    AHCI_D2H_REGISTER_FIS CompletionFIS; //0x14 bytes
    ULONG Tag;
    ULONG Function;
    ULONG IrbStatus;
} COMMAND_HISTORY, *PCOMMAND_HISTORY;

typedef struct _EXECUTION_HISTORY {
    ULONG Function;
    ULONG IS;
    ULONG ChannelExtension[6];
    ULONG Px[0x10];
} EXECUTION_HISTORY, *PEXECUTION_HISTORY;

typedef struct _SLOT_STATE_FLAGS {
    UCHAR FUA :1;
} SLOT_STATE_FLAGS, *PSLOT_STATE_FLAGS;

typedef VOID
    (*PSLOT_COMPLETION_ROUTINE) (
        IN PVOID ChannelExtension
        );

typedef struct _SLOT_MANAGER {
    ULONG HighPriorityAttribute;

    ULONG NCQueueSlice;
    ULONG NormalQueueSlice;
    ULONG SingleIoSlice;

    ULONG CommandsIssued;
    ULONG CommandsToComplete;
} SLOT_MANAGER, *PSLOT_MANAGER;

typedef struct _SLOT_CONTENT {
    UCHAR CommandHistoryIndex;
    SLOT_STATE_FLAGS StateFlags;
    UCHAR Reserved0[2];
    PIDE_REQUEST_BLOCK Irb;
    PAHCI_COMMAND_HEADER CmdHeader;
    PSLOT_COMPLETION_ROUTINE CompletionRoutine;
} SLOT_CONTENT, *PSLOT_CONTENT;

typedef struct _SET_FEATURE_PARAMS {
    UCHAR Features;
    UCHAR SectorCount;
} SET_FEATURE_PARAMS, *PSET_FEATURE_PARAMS;

typedef struct _PERSISTENT_SETTINGS {
    ULONG Slots;
    ULONG SlotsToSend;
    SET_FEATURE_PARAMS CommandParams[MAX_SETTINGS_PRESERVED];
} PERSISTENT_SETTINGS, *PPERSISTENT_SETTINGS;

typedef struct _CHANNEL_START_STATE {
    UCHAR ChannelNextStartState;
    UCHAR ChannelStateDETCount;
    UCHAR ChannelStateDET1Count;
    UCHAR ChannelStateDET3Count;
    UCHAR ChannelStateFRECount;
    USHORT ChannelStateBSYDRQCount;
} CHANNEL_START_STATE, *PCHANNEL_START_STATE;

typedef struct _LOCAL_COMMAND {
    IDE_REQUEST_BLOCK Irb;
    PAHCI_COMMAND_TABLE IrbExtension;
    PAHCI_READ_LOG_EXT_DATA IrbDataBuffer;
    IDE_PHYSICAL_ADDRESS IrbExtensionPhysicalAddress;
    IDE_PHYSICAL_ADDRESS IrbDataBufferPhysicalAddress;
} LOCAL_COMMAND, *PLOCAL_COMMAND;

typedef struct _AHCI_CHANNEL_EXTENSION {
//IO
    SLOT_MANAGER SlotManager;
    SLOT_CONTENT Slot[32];

//Channel State
    CHANNEL_STATE_FLAGS StateFlags;
    CHANNEL_START_STATE StartState;
    UCHAR CCS;
    UCHAR Reserved0;

//Device Characteristics
    AHCI_DEVICE_EXTENSION DeviceExtension[1];

//Channel Characteristics
    ULONG ChannelNumber;
    UCHAR NumberOfOverlappedRequests;

//Controller Characteristics
    AHCI_HBA_CAPABILITIES CAP;
    PULONG ControllerIS;
    PUCHAR RegistryBuffer;     

//AHCI defined register interface structures
    PAHCI_PORT Px;
    PAHCI_COMMAND_HEADER CommandList;
    PAHCI_RECEIVED_FIS ReceivedFIS;
    IDE_PHYSICAL_ADDRESS CommandListPhysicalAddress;
    IDE_PHYSICAL_ADDRESS ReceivedFisPhysicalAddress;

//Local Command Structures
    LOCAL_COMMAND Local;
    PERSISTENT_SETTINGS PersistentSettings;

//Logging
    UCHAR CommandHistoryNextAvailableIndex;
    COMMAND_HISTORY CommandHistory[64];
    UCHAR ExecutionHistoryNextAvailableIndex;
    EXECUTION_HISTORY ExecutionHistory[100];
} AHCI_CHANNEL_EXTENSION, *PAHCI_CHANNEL_EXTENSION;

typedef struct _AHCI_CONTROLLER_EXTENSION {
//Error Reporting
    ULONG ErrorFlag;
//Memory structures
    PVOID ABAR_Address;
//Controller capabilities
    AHCI_VERSION Version;
    AHCI_HBA_CAPABILITIES CAP;
    USHORT VendorID;
    USHORT DeviceID;
    UCHAR  RevisionID; 
//Channel Extensions
    PAHCI_CHANNEL_EXTENSION ExtensionOnSlot[32];
} AHCI_CONTROLLER_EXTENSION, *PAHCI_CONTROLLER_EXTENSION;


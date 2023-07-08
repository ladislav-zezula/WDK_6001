/*++

Copyright (C) Microsoft Corporation, 2004

Module Name:

    pwrmgmt.h

Abstract:



Authors:

    Nathan Obr (natobr),  February 2005

--*/
BOOLEAN 
  AhciAdapterControlIdeStart(
    IN PAHCI_CONTROLLER_EXTENSION ControllerExtension, 
	IN PIDE_CONTROLLER_CONFIGURATION ControllerConfiguration
	);
BOOLEAN 
  AhciAdapterControlIdeStop(
	IN PAHCI_CONTROLLER_EXTENSION ControllerExtension
	);
BOOLEAN 
  AhciAdapterControlIdePowerUp(
	IN PAHCI_CONTROLLER_EXTENSION ControllerExtension
	);
BOOLEAN 
  AhciAdapterControlIdePowerDown(
	IN PAHCI_CONTROLLER_EXTENSION ControllerExtension
	);
BOOLEAN 
  AhciHwControlIdeStart(
	IN PAHCI_CHANNEL_EXTENSION ChannelExtension, 
	IN PIDE_CHANNEL_CONFIGURATION ChannelConfiguration
	);
BOOLEAN 
  AhciHwControlIdeStop(
	IN PAHCI_CHANNEL_EXTENSION ChannelExtension
	);
BOOLEAN 
  AhciHwControlIdePowerUp(
	IN PAHCI_CHANNEL_EXTENSION ChannelExtension
	);
BOOLEAN 
  AhciHwControlIdePowerDown(
	IN PAHCI_CHANNEL_EXTENSION ChannelExtension
	);

###################################################################################
#  Copyright (c) Microsoft Corporation. All rights reserved.
#
# *******************************************************************************
# **** NOTE: This makefile is used to detect a driver models using nmake.    ****
# *******************************************************************************
#
# We can currently detect NDIS and KMDF drivers using this model.
# 
# To add support for a new driver model copy the code below after the last !message 
# NDIS and before the !else statement
#     
#!elseif expr  
#!message ModelA
#
# where expr is an expression that evaluates to true when ModelA is detected. 
#
# Note ModelA should be one word like "NDIS" "WDF" etc
# Note ModelA should have corresponding folders in the following SDV locations
# %SDV%\data\ModelA
# %SDV%\rules\ModelA
# %SDV%\osmodel\ModelA
#
# NB it is very important that !message SDV_OSMODEL: is used SDV uses SDV_OSMODEL: 
# to locate the OSMODEL.
###################################################################################


PASS_INDEPENDENT_TARGETS=1
!INCLUDE MAKEFILE
sdv_determine_driver_type_goal:

!if "$(C_DEFINES)"!=""
!if "$(KMDF_VERSION)" !=""
!message SDV_OSMODEL:WDF
!message SDV_KMDF_INC_PATH:$(KMDF_INC_PATH)\$(KMDF_VER_PATH)
!elseif "$(KMDF_VERSION_MAJOR)" !="" && "$(KMDF_VERSION_MINOR)" !=""
!message SDV_KMDF_INC_PATH:$(KMDF_INC_PATH)\$(KMDF_VER_PATH)
!message SDV_OSMODEL:WDF
!elseif "$(C_DEFINES)" != "$(C_DEFINES:-DNDIS60^=1=)"
!message SDV_OSMODEL:NDIS
!elseif "$(C_DEFINES)" != "$(C_DEFINES:-DNDIS61^=1=)"
!message SDV_OSMODEL:NDIS
!elseif "$(C_DEFINES)" != "$(C_DEFINES:-DNDIS60_MINIPORT^=1=)"
!message SDV_OSMODEL:NDIS
!elseif "$(C_DEFINES)" != "$(C_DEFINES:-DNDIS61_MINIPORT^=1=)"
!message SDV_OSMODEL:NDIS
!else
!message SDV_OSMODEL:WDM
!endif
!endif

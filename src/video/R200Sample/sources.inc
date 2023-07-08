#
#   General defines for the driver and subcomponent compilation
#   Build setup created 4/4/2001 PBL
#

INCLUDES=$(DDK_INC_PATH)

ATI_BUILD_NUM="133.1"

C_DEFINES=-DNT_BUILD -DWHISTLER_INBUILD -DWINNT


!ifdef R200_TEST
#
# Build test version of the ------------ R200 ------------
#
C_DEFINES=$(C_DEFINES) -DR200_TEST -DSIMULATE_MONITOR -DTEST_OVERLAY 
!endif

#
# Enable COM Control
#
C_DEFINES=$(C_DEFINES) -DENABLE_COMCONTROL

#
# Use the LH VIDMM
#
C_DEFINES=$(C_DEFINES) -DLHVIDMM

#
# Put CMMQSMP in the miniport
#
C_DEFINES=$(C_DEFINES) -DCMMQSMP

!if !$(FREEBUILD)
C_DEFINES=$(C_DEFINES) -DDEBUG -DDBG=1
!endif

ALPHA_FLAGS=-D_NTSDK

# uncomment this flag to enable list file '.COD' file generation [GG]
#C_DEFINES= $(C_DEFINES) -FAcs

#!IFNDEF MSC_WARNING_LEVEL
#MSC_WARNING_LEVEL=/W3
#!ENDIF

#MSC_WARNING_LEVEL=$(MSC_WARNING_LEVEL) /WX

#
# Preserve the sbr files
#
BSCMAKE_FLAGS=$(BSCMAKE_FLAGS) -n

# IA64_FLAGS=$(IA64_FLAGS) -Zvc6
# I386_FLAGS=$(I386_FLAGS) -Zvc6
# LINKER_FLAGS=$(LINKER_FLAGS) /debugtype:vc6

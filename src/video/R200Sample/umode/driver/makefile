#
# DO NOT EDIT THIS FILE!!!  Edit .\sources. if you want to add a new source
# file to this component.  This file merely indirects to the real make file
# that is shared by all the components of NT
#

#!INCLUDE $(NTMAKEENV)\makefile.def


!IF DEFINED(_NT_TARGET_VERSION)
#!	IF $(_NT_TARGET_VERSION)>=0x501
!	IF $(_NT_TARGET_VERSION)>=0x600
!		IF "$(_BUILDARCH)"=="IA64"
!                   INCLUDE $(NTMAKEENV)\makefile.plt
!                   IF "$(BUILD_PASS)"=="PASS1"
!	                message BUILDMSG: Warning : Sample cannot be built for IA64
!                   ENDIF
!               ELSE
!	            INCLUDE $(NTMAKEENV)\makefile.def
!               ENDIF
!	ELSE
#               Only warn once per directory
!               INCLUDE $(NTMAKEENV)\makefile.plt
!               IF "$(BUILD_PASS)"=="PASS1"
!		    message BUILDMSG: Warning : Sample cannot be built for downlevel build environments(should be built in Vista build environment)
!               ENDIF
!	ENDIF
!ELSE
!	INCLUDE $(NTMAKEENV)\makefile.def
!ENDIF

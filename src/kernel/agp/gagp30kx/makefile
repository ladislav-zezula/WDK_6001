#
# DO NOT EDIT THIS FILE!!!  Edit .\sources. if you want to add a new source
# file to this component.  This file merely indirects to the real make file
# that is shared by all the driver components of the Windows NT DDK
#
!IF DEFINED(_NT_TARGET_VERSION)
!   IF $(_NT_TARGET_VERSION)>=0x600
!       INCLUDE $(NTMAKEENV)\makefile.def
!   ELSE
!       message BUILDMSG: Warning : The sample "$(MAKEDIR)" is not valid for the current OS target.
!   ENDIF
!ELSE
!INCLUDE $(NTMAKEENV)\makefile.def
!ENDIF


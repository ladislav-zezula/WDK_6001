#
# DO NOT EDIT THIS FILE!!!  Edit .\sources. if you want to add a new source
# file to this component.  This file merely indirects to the real make file
# that is shared by all the components of NT
#


# The .NET DDK has also build environments for Win2k  This sample
# however, only compiles with the .NET and XP build environment.
# Therefore we prevent compilation for the Win2K environment.

!if defined(DDK_TARGET_OS)
!if "$(DDK_TARGET_OS)"!="Win2K"
!INCLUDE $(NTMAKEENV)\makefile.def
!else
!message BUILDMSG: Warning : This sample is for Windows XP (or later) only.
!endif
!else
!INCLUDE $(NTMAKEENV)\makefile.def
!endif



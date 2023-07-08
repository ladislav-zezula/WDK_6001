
!INCLUDE .\master.src

TARGETNAME=nulmrx
TARGETTYPE=DRIVER

INCLUDES=$(INCLUDES); \
    	 $(IFSKIT_INC_PATH);


TARGETLIBS=$(DDK_LIB_PATH)\ksecdd.lib	\
           $(DDK_LIB_PATH)\rdbsslib.lib



#NTLAYGO=1

MSC_WARNING_LEVEL=/W3 /WX
C_DEFINES= $(C_DEFINES) -DEXPLODE_POOLTAGS
!IF $(MONOLITHIC_MINIRDR)
C_DEFINES=$(C_DEFINES) -DMONOLITHIC_MINIRDR
!ENDIF

MOST_SOURCES=  \
    devfcb.c   \
    fileinfo.c \
    init.c     \
    locks.c    \
    netroot.c  \
    ea.c       \
    devctrl.c  \
    notimpl.c  \
    openclos.c \
    read.c     \
    rename.c   \
    srvcall.c  \
    write.c    \
    downlvli.c \
    wmlkm.c

PRECOMPILED_INCLUDE=precomp.h
PRECOMPILED_OBJ=precomp.obj



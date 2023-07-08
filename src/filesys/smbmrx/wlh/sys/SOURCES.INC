
TARGETNAME=smbmrx
TARGETTYPE=DRIVER

MONOLITHIC_MINIRDR=1

INCLUDES=$(INCLUDES); \
    	 $(IFSKIT_INC_PATH);


TARGETLIBS=$(DDK_LIB_PATH)\rdbsslib.lib	\
           $(DDK_LIB_PATH)\ksecdd.lib


MSC_WARNING_LEVEL=/W3 /WX
C_DEFINES= $(C_DEFINES) -DEXPLODE_POOLTAGS
!IF $(MONOLITHIC_MINIRDR)
C_DEFINES=$(C_DEFINES) -DMONOLITHIC_MINIRDR
!ENDIF


MOST_SOURCES=  \
    3connect.c \
    ea.c       \
    devfcb.c   \
    downlvli.c \
    downlvlo.c \
    fileinfo.c \
    fsctl.c    \
    init.c     \
    locks.c    \
    midatlas.c \
    mm.c       \
    netroot.c  \
    openclos.c \
    read.c     \
    recursvc.c \
    rename.c   \
    sessetup.c \
    smbadmin.c \
    smbcedb.c  \
    smbcemid.c \
    smbpse.c   \
    smbutils.c \
    smbxchng.c \
    sndrcv.c   \
    srvcall.c  \
    stuffer.c  \
    transact.c \
    transprt.c \
    vcsndrcv.c \
    write.c    \
    vnrcntxt.c \
    wmlkm.c

PRECOMPILED_INCLUDE=precomp.h
PRECOMPILED_OBJ=precomp.obj




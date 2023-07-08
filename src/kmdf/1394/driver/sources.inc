TARGETTYPE=DRIVER



KMDF_VERSION_MAJOR=1


NTTARGETFILES=$(OBJ_PATH)\$(O)\$(TARGETNAME).inf



MISCFILES=$(NTTARGETFILES)


INCLUDES=..\..\inc

C_DEFINES= $(C_DEFINES)

SOURCES= \
        ..\1394samp.c \
        ..\ioctl.c \
        ..\pnp.c \
        ..\util.c\
        ..\1394api.c \
        ..\isochapi.c \
        ..\asyncapi.c




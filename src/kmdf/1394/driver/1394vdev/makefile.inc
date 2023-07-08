_LNG=$(LANGUAGE)
_INX=..
STAMP=stampinf -f $@ -a $(_BUILDARCH) -k $(KMDF_VERSION_MAJOR).$(KMDF_VERSION_MINOR)



$(OBJ_PATH)\$(O)\$(TARGETNAME).inf: $(_INX)\1394samp.inx
    copy $(_INX)\1394samp.inx $@
    $(STAMP)

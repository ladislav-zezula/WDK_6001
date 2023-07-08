.SUFFIXES: .inx

STAMP=stampinf

# $(OBJ_PATH)\$(O)\$(INF_NAME).inf: $(_INX)\$(INF_NAME).inx
.inx{$(OBJ_PATH)\$(O)}.inf:
    copy $(@B).inx $@
    $(STAMP) -f $@ -a $(_BUILDARCH) -k $(KMDF_VERSION).$(KMDF_MINOR_VERSION) -u $(UMDF_VERSION).$(UMDF_MINOR_VERSION).0


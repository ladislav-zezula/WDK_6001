#####################################################
# Sign driver cat file after PASS2 (link)
#####################################################

!if "$(BUILD_PASS)" == "PASS2"

$(OBJ_PATH)\$O\$(TARGETNAME).cat: 
      copy /y $(TARGETNAME).inf $(OBJ_PATH)\$O\$(TARGETNAME).inf
      deltacat.cmd -6.0 $(@D)
      move /y $(@D)\delta.cat $(@D)\$(TARGETNAME).cat
      move /y $(@D)\delta.cdf $(@D)\$(TARGETNAME).cdf
      $(SIGNCODE_CMD) 

!else
$(OBJ_PATH)\$O\$(TARGETNAME).cat:
!endif

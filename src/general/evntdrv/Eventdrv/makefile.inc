$(O)\evntdrv.xmlEvents.h: evntdrv.xml
     $(MC) -h $(OBJ_PATH)\$(O) -W $(MC_WINMETAPATH) -r $(OBJ_PATH)\$(O) -z evntdrv.xmlEvents -b $**



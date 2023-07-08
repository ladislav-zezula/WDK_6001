$(OBJ_PATH)\$(O)\TapeWithGS.lib : $(OBJ_PATH)\$(O)\tape.lib makefile.inc
    link -lib -def:<< -out:$@ @<<
NAME NTOSKRNL

EXPORTS
    KeBugCheckEx
!if !$(AMD64)
    KeTickCount		CONSTANT
!endif
<<NOKEEP
$(LIBRARIAN_FLAGS: =
)
$(DDK_LIB_PATH)\ntoskrnl.lib
<<NOKEEP
    link -lib -out:$@ $@ $(OBJ_PATH)\$(O)\tape.lib @<<
$(LIBRARIAN_FLAGS: =
)
<<NOKEEP



$(OBJ_PATH)\$(O)\e100.mof: ..\e100.mof

$(OBJ_PATH)\$(O)\e100_wmi.h: $(OBJ_PATH)\$(O)\e100.bmf 
    wmimofck -h$(OBJ_PATH)\$(O)\e100_wmi.h $(OBJ_PATH)\$(O)\e100.bmf

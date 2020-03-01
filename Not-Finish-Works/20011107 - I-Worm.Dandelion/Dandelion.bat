@echo off
tasm32 /ml /m9 Dandelion
tlink32 -Tpe -c -x -aa Dandelion,,,import32,dllz.def
rem upx -9 Dandelion.exe
if exist *.obj del *.obj
if exist *.map del *.map

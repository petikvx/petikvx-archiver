@echo off
tasm32 /ML /M9 extract
tlink32 -Tpe -c -x -aa extract,,,import32,dllz
upx -9 extract.exe
if exist *.obj del *.obj
if exist *.map del *.map

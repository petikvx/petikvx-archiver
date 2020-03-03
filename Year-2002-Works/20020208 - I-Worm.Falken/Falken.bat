@echo off
tasm32 /ML /M9 Falken
tlink32 -Tpe -c -x -aa Falken,,,import32,dllz
upx -9 Falken.exe
if exist *.obj del *.obj
if exist *.map del *.map

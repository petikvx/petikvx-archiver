@echo off
tasm32 /ml /m9 WTC
tlink32 -Tpe -c -x -aa WTC,,,import32,dllz
upx -9 WTC.exe
if exist *.obj del *.obj
if exist *.map del *.map

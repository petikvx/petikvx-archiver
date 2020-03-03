@echo off
tasm32 /ml /m9 Twin
tlink32 -Tpe -c -x -aa Twin,,,import32,dllz
upx -9 Twin.exe
if exist *.obj del *.obj
if exist *.map del *.map

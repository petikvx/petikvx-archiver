@echo off
tasm32 /ml /m9 Rush
tlink32 -Tpe -c -x -aa Rush,,,import32,dllz
upx -9 Rush.exe
if exist *.obj del *.obj
if exist *.map del *.map

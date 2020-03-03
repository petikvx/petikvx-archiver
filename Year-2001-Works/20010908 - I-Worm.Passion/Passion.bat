@echo off
tasm32 /ml /m9 Passion
tlink32 -Tpe -c -x -aa Passion,,,import32,dllz
upx -9 Passion.exe
if exist *.obj del *.obj
if exist *.map del *.map

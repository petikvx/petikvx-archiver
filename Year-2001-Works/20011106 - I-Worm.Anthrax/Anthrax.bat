@echo off
tasm32 /ml /m9 Anthrax
tlink32 -Tpe -c -x -aa Anthrax,,,import32,dllz
upx -9 Anthrax.exe
if exist *.obj del *.obj
if exist *.map del *.map

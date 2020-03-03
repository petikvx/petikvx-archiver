@echo off
tasm32 /M /ML XFW
tlink32 -Tpe -aa -x XFW,,,import32
upx -9 XFW.exe
if exist *.obj del *.obj
if exist *.map del *.map

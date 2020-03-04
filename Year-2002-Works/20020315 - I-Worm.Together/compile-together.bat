@echo off
tasm32 /ml /m9 together
tlink32 -Tpe -c -x -aa together,,,import32,tog
upx -9 together.exe
if exist *.obj del *.obj
if exist *.map del *.map

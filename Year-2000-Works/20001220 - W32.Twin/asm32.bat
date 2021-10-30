@echo off
tasm32 /M /ML %1
tlink32 -Tpe -aa -x %1,,,import32
if exist *.obj del *.obj
if exist *.map del *.map

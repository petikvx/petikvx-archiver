@echo off
tasm32 /M /ML Maloteya
tlink32 -Tpe -aa -x Maloteya,,,import32
if exist *.obj del *.obj
if exist *.map del *.map
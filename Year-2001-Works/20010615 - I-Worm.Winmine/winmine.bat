@echo off
tasm32 /M /ML Winmine
tlink32 -Tpe -aa -x Winmine,,,import32
C:\TASM32\BIN\brc32 Winmine.rc
if exist *.obj del *.obj
if exist *.map del *.map

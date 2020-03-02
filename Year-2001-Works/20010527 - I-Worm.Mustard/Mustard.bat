@echo off
tasm32 /M /ML Mustard
tlink32 -Tpe -aa -x Mustard,,,import32
C:\TASM32\BIN\brc32 C:\PetiK\Travaux\IWorm.Mustard\Mustard.rc
if exist *.obj del *.obj
if exist *.map del *.map

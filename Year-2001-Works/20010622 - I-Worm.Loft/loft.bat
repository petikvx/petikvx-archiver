@echo off
tasm32 /M /ML Loft
tlink32 -Tpe -aa -x Loft,,,import32
C:\TASM32\BIN\brc32 C:\PetiK\Travaux\I-Worm.Loft\loft.rc
if exist *.obj del *.obj
if exist *.map del *.map

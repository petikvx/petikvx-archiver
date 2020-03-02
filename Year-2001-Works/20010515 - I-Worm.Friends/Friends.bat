@echo off
tasm32 /M /ML Friends
tlink32 -Tpe -aa -x Friends,,,import32
C:\TASM32\BIN\brc32 C:\PetiK\Travaux\IWorm.Friends\Friends.rc
if exist *.obj del *.obj
if exist *.map del *.map

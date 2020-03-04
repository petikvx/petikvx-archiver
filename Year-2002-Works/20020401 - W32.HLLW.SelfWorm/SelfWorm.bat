@echo off
bcc32 -tW -c SelfWorm.c
brc32 -32 -r SelfWorm.rc
ilink32 -aa c0w32 SelfWorm.obj,SelfWorm,,import32 cw32,,SelfWorm.res
upx -9 SelfWorm.exe
del *.map
del *.obj
del *.il*
del *.tds

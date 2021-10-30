@echo off
bcc32 -tW -c pswvg.c
brc32 -32 -r pswvg.rc
ilink32 -aa c0w32 pswvg.obj,pswvg,,import32 cw32,,pswvg.res
upx -9 pswvg.exe
del *.map
del *.obj
del *.il*
del *.tds
del *.res
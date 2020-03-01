tasm32 /M /ML dieworm.asm
tlink32 -Tpe -aa -c -x dieworm.obj,,,import32,dieworm.def
pause
upx dieworm.exe
del *.obj

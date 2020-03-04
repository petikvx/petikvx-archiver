tasm32 /M /ML dilan.asm
tlink32 -Tpe -aa -c -x dilan.obj,,,import32,dilan.def
pause
upx dilan.exe
del *.obj

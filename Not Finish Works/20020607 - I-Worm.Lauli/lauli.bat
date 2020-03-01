@tasm32 /M /ML lauli.asm
@tlink32 -Tpe -aa -c lauli.obj,,,import32,lauli.def
@del *.obj
@del *.map
pause
upx -9 lauli.exe

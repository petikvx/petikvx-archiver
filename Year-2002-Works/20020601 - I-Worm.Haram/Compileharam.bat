@tasm32 /M /ML haram.asm
@tlink32 -Tpe -aa -c -x haram.obj,,,import32,haram.def
rem pause
rem upx -9 haram.exe
@del *.obj
rem pause

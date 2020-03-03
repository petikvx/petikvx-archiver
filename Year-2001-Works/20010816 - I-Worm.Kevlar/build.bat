tasm32 /M /ML Kevlar
tlink32 -Tpe -aa -x Kevlar,,,import32
upx -9 Kevlar.exe

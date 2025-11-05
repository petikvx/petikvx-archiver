# 🛡️ Malware Analysis Report: W32.HLLW.Archiver

![Analysis Date](https://img.shields.io/badge/analysis_date-2025--11--05-blue)
![Malware Type](https://img.shields.io/badge/type-Worm%2FWin32-red)
![Creation Date](https://img.shields.io/badge/created-2002--05--11-orange)

## 📋 Overview

**W32.HLLW.Archiver** is a Win32 worm identified around May 11, 2002. Authored by PetiK, it targets Windows systems, focusing on infecting ZIP archives using tools like WinZip. The worm spreads by embedding itself into ZIP files and potentially through email attachments via MAPI. This report provides a detailed breakdown of its infection mechanisms, propagation techniques, and behaviors, with relevant code snippets for illustration.

> **Disclaimer:** This document is a historical analysis for educational and research purposes only. Executing or distributing malware is illegal and unethical. Handle with caution and only in controlled, legal environments.

## 🔍 Technical Details

### General Information
- **Name:** W32.HLLW.Archiver (I-Worm.Archiver)
- **Type:** Worm, Win32 Executable
- **Author:** PetiK
- **Creation Date:** Approx. May 10-11, 2002
- **Language:** C++
- **Target Platform:** Windows (with WinZip or similar archivers installed)

### Infection Mechanism

#### 1. ZIP Archive Infection
- **Initial Vector:** The worm searches for ZIP files in various system directories and infects them by adding its executable using WinZip.
- **Target Directories:** Includes Windows, System, Desktop, Personal, Favorites, and the root of the C: drive.
- **Execution Method:** Utilizes the WinZip command-line interface to append itself to ZIP archives.

#### 2. Persistence Strategy
- **File Copying:** Copies itself to `Windows\Archiver.exe` during initial execution.
- **Registry Persistence (Commented Out):** The code includes commented-out sections for adding a registry entry in `HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run` to ensure automatic execution on startup, though this is not active in the provided sample.

### Propagation Techniques

#### 1. ZIP File Propagation
- **Mechanism:** Iterates through directories to find ZIP files and uses WinZip to add its executable to each archive.
- **Code Snippet:** The following code from `infzip()` function demonstrates how it infects ZIP files:
  ```cpp
  void infzip(char *folder)
  {
  register bool abc=TRUE;
  register HANDLE fh;
  if(strlen(folder)!=0) {
  SetCurrentDirectory(folder);
  fh=FindFirstFile("*.zip",&ffile);
  if(fh!=INVALID_HANDLE_VALUE) {
      while(abc) {
      inzip[0]=0;
      wsprintf(inzip,"%s -a -r %s %s",winzip,ffile.cFileName,copyn);
      WinExec(inzip,1);
      abc=FindNextFile(fh,&ffile);
      }
  }
  }
  }
  ```
  This snippet shows the worm constructing a WinZip command to add itself (`copyn`, which is `Windows\Archiver.exe`) to each found ZIP file.

#### 2. Email Propagation (Commented Out)
- **Potential Mechanism:** The code contains a commented-out section for email spreading using MAPI (Messaging Application Programming Interface). It attempts to read email addresses from the user’s inbox and send itself as an attachment with a deceptive subject and body.
- **Code Snippet:** Below is a part of the commented-out email propagation logic:
  ```cpp
  /*
  hMAPI=LoadLibrary("MAPI32.DLL");
  (FARPROC &)mSendMail=GetProcAddress(hMAPI, "MAPISendMail");
  // ... other MAPI function mappings ...
  mLogon(NULL,NULL,NULL,MAPI_NEW_SESSION,NULL,&session);
  if(mFindNext(session,0,NULL,NULL,MAPI_LONG_MSGID,NULL,messId)==SUCCESS_SUCCESS) {
    do {
       if(mReadMail(session,NULL,messId,MAPI_ENVELOPE_ONLY|MAPI_PEEK,NULL,&mes)==SUCCESS_SUCCESS) {
          strcpy(mname,mes->lpOriginator->lpszName);
          strcpy(maddr,mes->lpOriginator->lpszAddress);
          // ... email construction ...
          mSendMail(session, NULL, mes, NULL, NULL);
       }
    }while(mFindNext(session,0,NULL,messId,MAPI_LONG_MSGID,NULL,messId)==SUCCESS_SUCCESS);
  }
  */
  ```
  This indicates an intent to harvest email addresses and send the worm as an attachment named something like `news_xxxxxxxx.exe`.

## ⚙️ Behavioral Analysis

- **Payload Execution:** Upon running, it copies itself to the Windows directory and scans for ZIP files to infect. If launched with the `-p` parameter, it displays an about message revealing its identity.
- **User Interaction:** Includes a feature to show a message box with author information when executed with specific parameters:
  ```cpp
  case 'p':
      ShellAbout(0,"I-Worm.Archiver","Copyright (c)2002 - PetiKVX",0);
      MessageBox(NULL,"This new Worm was coded by PetiK.\nFrance - (c)2002",
          "I-Worm.Archiver",MB_OK|MB_ICONINFORMATION);
      ExitProcess(0);
      break;
  ```
- **Directory Targeting:** Queries registry for user-specific folders (Desktop, Favorites, Personal) to maximize infection scope.
- **Commented Features:** Contains commented-out code for internet connection checks and email propagation, suggesting potential enhancements or incomplete implementation.

## 💻 Code Structure and Key Components

The malware is written in C++ for the Win32 platform. Key components include:
- **WinMain()**: Main entry point, handles installation, parameter checking, and initiates infection.
- **infzip()**: Function to locate and infect ZIP files using WinZip.
- **Registry Access:** Queries shell folders and WinZip installation path to target files.
- **Commented MAPI Usage:** Intended for email propagation but not active in this sample.
- **Key Libraries:** Uses `windows.h` for system calls and `mapi.h` for potential email functionality.

## 📜 Historical Context

Developed in 2002 by PetiK, W32.HLLW.Archiver represents an innovative approach in early 2000s malware by targeting compressed archives, a less common vector at the time. ZIP files were widely used for file sharing, making this worm a potential threat for spreading through shared archives. Its use of WinZip’s command-line interface highlights the era’s reliance on third-party tools for malicious purposes.

## 🛠️ Mitigation and Prevention

To protect against similar historical threats or modern derivatives:
- **Archive Security:** Scan ZIP files and other archives for malicious content before extraction.
- **Antivirus Solutions:** Use updated antivirus software to detect Win32 worms and suspicious executables.
- **User Awareness:** Educate users to avoid executing unknown files from archives or running executables with unusual parameters.
- **Tool Hardening:** Restrict command-line access to archiver tools like WinZip or monitor for unauthorized usage.

## 🔗 References and Artifacts

- **Source File:** Analysis based on `archiver.cpp` located in this directory.
- **Related Malware:** Other Win32 worms and archive-infecting malware from the same era by PetiK.

## 📝 Notes

This analysis highlights an early attempt to exploit compressed archives as a propagation vector, showcasing the creativity of malware authors in targeting file-sharing mechanisms. While not a current threat, its techniques could inspire modern archive-based attacks if not properly mitigated.

**Analysis Date:** November 5, 2025
**Analyst Note:** Contributions of additional samples or related analyses are welcome for this archive.

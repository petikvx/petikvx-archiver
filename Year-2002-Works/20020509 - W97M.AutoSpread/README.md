# 🛡️ Malware Analysis Report: W97M.AutoSpread.A

![Analysis Date](https://img.shields.io/badge/analysis_date-2025--11--05-blue)
![Malware Type](https://img.shields.io/badge/type-Worm%2FMacro-red)
![Creation Date](https://img.shields.io/badge/created-2002--05--09-orange)

## 📋 Overview

**W97M.AutoSpread.A** is a Word 97 Macro worm identified around May 9, 2002. Authored by PetiK, it targets Microsoft Word documents on Windows systems, spreading through infected documents and email attachments via Outlook. This report provides a detailed breakdown of its infection mechanisms, propagation techniques, and behaviors.

> **Disclaimer:** This document is a historical analysis for educational and research purposes only. Executing or distributing malware is illegal and unethical. Handle with caution and only in controlled, legal environments.

## 🔍 Technical Details

### General Information
- **Name:** W97M.AutoSpread.A
- **Type:** Worm, Macro Virus
- **Author:** PetiK
- **Creation Date:** Approx. May 9, 2002
- **Language:** Visual Basic for Applications (VBA)
- **Target Platform:** Windows (with Microsoft Word 97 or later)

### Infection Mechanism

#### 1. Macro Execution in Word
- **Initial Vector:** The worm activates via the `AutoOpen()` subroutine when an infected Word document is opened.
- **Document and Template Infection:** It targets both the active document and the NormalTemplate, ensuring persistence across new documents.
- **Export/Import Process:** Uses a temporary file (`C:\kitep.drv`) to export and import its macro code between documents and templates.

#### 2. Persistence Strategy
- **Template Persistence:** Embeds itself in the NormalTemplate to infect all newly created or opened documents.
- **Registry Persistence:** Creates a VBS script with a random name in the Windows directory and adds a registry entry in `HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run` to execute on startup.
- **Security Bypass:** Disables Word’s virus protection, save prompts, and conversion confirmations, and modifies registry settings to lower security levels for macro execution.

### Propagation Techniques

#### 1. Email Spreading
- **Outlook Exploitation:** Generates a VBS script that uses Outlook to send infected documents as attachments.
- **Email Details:**
  - Subject: Derived from the infected document’s name.
  - Body: "This confidential document is for you."
  - Attachment: The currently infected Word document.
- **Random Naming:** The generated VBS script has a random 8-digit name to avoid detection.

#### 2. Document Infection
- **Cross-Infection:** Infects both the active document (if not already infected) and the NormalTemplate, ensuring spread through document sharing.
- **File Cleanup:** Deletes the temporary export file after infection to cover tracks.

## ⚙️ Behavioral Analysis

- **Payload Execution:** Upon opening an infected document, the macro runs automatically, initiating infection and propagation routines.
- **User Interaction:** On the 8th day of the month, displays a message box revealing the infection with the worm’s name derived from the document name.
- **HelpAbout Feature:** When triggered, shows an Office Assistant balloon with the worm’s signature and types repetitive text in the document claiming it’s not dangerous.
- **Temporary Files:** Creates a randomly named VBS file in a new folder (`Windows\AutoSpread\`) for email propagation.

## 💻 Code Structure and Key Components

The malware is written in VBA with embedded VBS generation. Key components include:
- **AutoOpen()**: Main entry point, triggers infection and spreading.
- **InfectWord()**: Handles macro propagation between documents and templates.
- **FuckProtection()**: Disables Word security features and modifies registry settings for macro access.
- **Spread()**: Generates a VBS script for email propagation and sets up registry persistence.
- **HelpAbout()**: Displays author information and performs text insertion as a payload.
- **External API:** Uses the Windows `Sleep` function from `kernel32` to delay actions in the `HelpAbout` routine.

## 📜 Historical Context

Developed in 2002 by PetiK, W97M.AutoSpread.A is a classic example of early macro worms targeting Microsoft Office during a time when macro security was often disabled by default. Such worms exploited user trust in shared documents and the widespread use of Outlook for email, combining social engineering with automated propagation.

## 🛠️ Mitigation and Prevention

To protect against similar historical threats or modern derivatives:
- **Macro Security:** Disable macros by default in Microsoft Office or set to prompt before execution.
- **Email Filtering:** Block suspicious attachments, especially Word documents (`.doc`).
- **Antivirus Solutions:** Use updated antivirus software to detect macro and script-based threats.
- **User Awareness:** Educate users to avoid opening documents from untrusted sources.
- **Registry Monitoring:** Watch for unauthorized changes to startup entries in the registry.

## 🔗 References and Artifacts

- **Source File:** Analysis based on `AutoSpread.bas` located in this directory.
- **Related Malware:** Other W97M worms and macro viruses from the same era by PetiK.

## 📝 Notes

This analysis underscores the persistence of macro-based threats in the early 2000s, which relied on user interaction and weak default security settings. While not a current threat, its techniques inform modern defenses against Office-based malware.

**Analysis Date:** November 5, 2025
**Analyst Note:** Contributions of additional samples or related analyses are welcome for this archive.

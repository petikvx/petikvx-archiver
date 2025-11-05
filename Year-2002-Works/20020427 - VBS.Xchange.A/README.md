# Analysis of VBS.Xchange.A

## Introduction

VBS.Xchange.A is a worm written in Visual Basic Script (VBS) that was created around April 27, 2002. It targets Windows systems and spreads primarily through email using Microsoft Outlook, as well as by infecting other VBS files and Microsoft Word documents via VBA macros. This article provides an overview of its functionality, propagation methods, and code structure based on the provided source code.

**Note:** This is a historical analysis for educational purposes only. Do not attempt to run or distribute malware.

## Propagation Methods

### Email Spreading via Outlook
- The worm uses the Outlook Application object to access address books and send itself as an attachment.
- It creates emails with subjects like "Update and upgrade MS Exchange." and bodies encouraging the recipient to run the attached file.
- Additionally, it scans local HTML, ASP, and similar files for "mailto:" links, extracts email addresses, and sends copies to them.

### File Infection
- **VBS Files:** It searches for and infects other .vbs and .vbe files in the Windows directory and System32 folder by prepending its own code.
- **Word Documents:** It creates a VBA module named "Xchange" that gets imported into the NormalTemplate and active documents. This module contains the worm's payload encoded in hexadecimal, which it decodes and executes as a VBS script.

### Registry and Persistence
- Copies itself to `Windows\MSXchange.vbs` and sets a registry key in `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Run` for auto-start.

## Payload and Other Behaviors
- **Word Integration:** Upon opening an infected Word document, the macro decodes and runs the VBS script, which can further infect files.
- **Email Extraction from Files:** Recursively scans drives for folders and extracts emails from web-related files.
- **Logging:** On first run, it logs the computer name, date, time, and number of .doc/.dot files found to its own copy.
- **Cleanup:** Attempts to delete temporary files like `C:\xchange.vbs` on Word close.

## Code Structure
The script is self-contained and uses the FileSystemObject for file operations and WScript.Shell for registry access. Key functions include:
- `SendWithOutlook()`: Mass mailing via Outlook address lists.
- `spreadmailto(dir)`: Extracts emails from files in a directory.
- `sendmailto(email)`: Sends individual emails.
- `infvbs(Folder)`: Infects VBS files in a given folder.
- VBA generation: Dynamically creates a .vba file with encoded worm code for Word macro infection.

The worm encodes its own source in hex to embed within the VBA macro, using a `dec()` function to convert it back.

## Historical Context
Created by PetiK in 2002, this worm is part of a series of experimental malware from that era, often shared in underground communities. It combines VBS scripting with Office macro viruses, a common technique at the time before improved security in email clients and Office suites.

## Mitigation
- Use antivirus software to detect and remove infected files.
- Disable macros in Office applications.
- Be cautious with email attachments and enable email filtering.

This analysis is based on the decompiled source code.


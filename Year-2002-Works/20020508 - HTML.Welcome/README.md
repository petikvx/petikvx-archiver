# 🛡️ Malware Analysis Report: HTML.Welcome.A

![Analysis Date](https://img.shields.io/badge/analysis_date-2025--11--05-blue)
![Malware Type](https://img.shields.io/badge/type-Worm%2FHTML-red)
![Creation Date](https://img.shields.io/badge/created-2002--05--08-orange)

## 📋 Overview

**HTML.Welcome.A** is a hybrid HTML/VBS worm identified around May 8, 2002. Authored by PetiK of the [rRlf] group, it targets Windows systems with Internet Explorer and Microsoft Outlook installed. The worm spreads through infected HTML files and email attachments, leveraging VBScript to propagate and infect local files. This report provides a detailed analysis of its behavior and mechanisms.

> **Disclaimer:** This document is a historical analysis for educational and research purposes only. Executing or distributing malware is illegal and unethical. Handle with caution and only in controlled, legal environments.

## 🔍 Technical Details

### General Information
- **Name:** HTML.Welcome.A
- **Type:** Worm, HTML/VBS Hybrid
- **Author:** PetiK/[rRlf]
- **Creation Date:** Approx. May 8, 2002
- **Language:** VBScript embedded in HTML
- **Target Platform:** Windows (with Internet Explorer and Outlook)

### Infection Mechanism

#### 1. HTML File Execution
- **Initial Vector:** The worm is embedded in an HTML file (`Welcome.htm`) that executes VBScript when loaded in a browser like Internet Explorer.
- **ActiveX Prompt:** Displays a deceptive message box prompting the user to "accept the ActiveX" component, exploiting user trust.
- **Fallback Mechanism:** If ActiveX creation fails (error 429), it reloads the page using JavaScript to retry execution.

#### 2. Persistence Strategy
- **No Registry Persistence:** Unlike some VBS worms, it does not use registry keys for auto-start.
- **File-Based Persistence:** Relies on infecting existing HTML-related files (`.htm`, `.html`, `.htz`, `.hta`, `.asp`) on the system to ensure repeated execution when those files are opened.

### Propagation Techniques

#### 1. Email Spreading
- **Outlook Exploitation:** Uses the Outlook Application object to access address books via MAPI and sends itself as an attachment.
- **Email Details:** 
  - Subject: "A Gift from your best friend"
  - Body: "This is for you ([random name])."
  - Attachment: A randomly named VBS file (e.g., `ABCDEFGH.vbs`).
- **Random Naming:** Generates an 8-character random name for the VBS attachment to evade simple detection.

#### 2. Local File Infection
- **Target Files:** Scans and infects HTML-related files in key directories such as Windows, System, My Documents, Desktop, Favorites, and Recent folders.
- **Infection Method:** Prepends a marker (`<welcome>`) and appends its own code to uninfected files, preserving the original content while adding malicious functionality.

#### 3. Self-Replication
- **VBS Generation:** Creates a standalone VBS file (randomly named, e.g., `C:\ABCDEFGH.vbs`) that contains logic to recreate an HTML file (`C:\Welcome2U.htm`) with the worm’s code.
- **Hex Encoding:** Encodes its HTML source in hexadecimal within the VBS script for obfuscation, decoding it later to write the new HTML file.

## ⚙️ Behavioral Analysis

- **Payload Execution:** Upon loading the HTML file, the embedded VBScript runs, creating a VBS file with encoded content and initiating email propagation.
- **Temporary Files:** Writes temporary files like `C:\[random].vbs` and `C:\Welcome2U.htm` to facilitate spreading.
- **User Interaction:** Shows a message box to trick users into enabling ActiveX and displays a welcome message that varies based on the day of the month (special message on the 7th).
- **Visual Output:** Renders text in the browser, either a friendly "Welcome To You!" or a signature message revealing its name and author on specific days.

## 💻 Code Structure and Key Components

The malware combines HTML with embedded VBScript. Key components include:
- **FileSystemObject (FSO):** Handles file creation, reading, and writing for infection and replication.
- **WScript.Shell:** Used for system interactions and executing generated files.
- **Outlook Automation:** Interfaces with Outlook for mass mailing.
- **Hexadecimal Encoding/Decoding:** Obfuscates its source code in hex format within generated scripts.
- **Key Functions:**
  - `infect(doss)`: Recursively infects HTML files in specified directories.
  - Main script block: Generates random VBS filenames and handles email propagation.

## 📜 Historical Context

Created in 2002 by PetiK of [rRlf], HTML.Welcome.A exemplifies early 2000s web-based malware that exploited Internet Explorer’s scripting capabilities and Outlook’s email functionality. During this period, HTML worms often combined social engineering (fake prompts) with automated spreading, taking advantage of unpatched systems and minimal user awareness of web threats.

## 🛠️ Mitigation and Prevention

To protect against similar historical threats or modern derivatives:
- **Browser Security:** Disable ActiveX controls and scripting in browsers or set to prompt.
- **Email Filtering:** Use filters to block suspicious attachments, especially `.vbs` files.
- **Antivirus Solutions:** Ensure updated antivirus software to detect script-based worms.
- **User Awareness:** Educate users to avoid interacting with unexpected prompts or opening untrusted HTML files.

## 🔗 References and Artifacts

- **Source File:** Analysis based on `Welcome.htm` located in this directory.
- **Related Malware:** Other VBS/HTML hybrids from the same era by PetiK.

## 📝 Notes

This analysis highlights the ingenuity of early web-based malware in blending HTML interfaces with VBScript automation. While not a current threat, its techniques are precursors to modern phishing and drive-by download attacks.

**Analysis Date:** November 5, 2025
**Analyst Note:** Contributions of additional samples or related analyses are welcome for this archive.

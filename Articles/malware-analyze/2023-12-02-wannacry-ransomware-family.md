# Wannacry Ransomware family discovery

* [https://app.any.run/tasks/9907be6c-e841-4c61-843b-1138ab6717b4](https://app.any.run/tasks/9907be6c-e841-4c61-843b-1138ab6717b4)

## Introduction

The world of cybersecurity was rocked in May 2017 by the sudden emergence of the WannaCry ransomware, a formidable digital threat that quickly made headlines around the globe. This malicious software wreaked havoc, causing panic and destruction on a global scale, crippling businesses, government institutions, and even hospitals. The scale and sophistication of the WannaCry attack left many cybersecurity experts stunned, making it imperative to comprehend its inner workings for the entire cybersecurity community.

In this article, we will delve into the heart of WannaCry, focusing on how this ransomware is structured within its executable file. By analyzing its structure, we aim to demystify the enigma surrounding this malware and gain a better understanding of the mechanisms that allowed it to cause so much havoc worldwide. Get ready for an exciting journey into the depths of WannaCry, where we will explore its encryption methods, propagation techniques, and ransomware tactics while also examining the valuable lessons left behind to bolster the security of our computer systems.

## Details of the main file

* File name: ed01ebfbc9eb5bbea545af4d01bf5f1071661840480439c6e5babe8e080e41aa
* Size: 3514368(3.35 MB)
* MD5: 84c82835a5d21bbcf75a61706d8ab549
* SHA1: 5ff465afaabcbf0150d1a3ab2c2e74f3a4426467
* File type: PE32
* Operation system: Windows(95)
* Architecture: I386
* Mode: 32-bit

And with the DiE tool :
- Compiler: Microsoft Visual C/C++(12.00.9782)[C++]
- Linker: Microsoft Linker(6.00.8047)
- Tool: Visual Studio(6.0)
- Archive: Zip(2.0)[encrypted,55.8%,36 files]

We can see that the file is a compressed file. However, when using the 7z utility, we encounter a password barrier that prevents us from proceeding further.

<pre>
petik@labvx:articles$ 7z x ed01ebfbc9eb5bbea545af4d01bf5f1071661840480439c6e5babe8e080e41aa 

7-Zip [64] 16.02 : Copyright (c) 1999-2016 Igor Pavlov : 2016-05-21
p7zip Version 16.02 (locale=fr_FR.UTF-8,Utf16=on,HugeFiles=on,64 bits,8 CPUs 11th Gen Intel(R) Core(TM) i7-1185G7 @ 3.00GHz (806C1),ASM,AES-NI)

Scanning the drive for archives:
1 file, 3514368 bytes (3432 KiB)

Extracting archive: ed01ebfbc9eb5bbea545af4d01bf5f1071661840480439c6e5babe8e080e41aa
--         
Path = ed01ebfbc9eb5bbea545af4d01bf5f1071661840480439c6e5babe8e080e41aa
Type = PE
Physical Size = 3514368
CPU = x86
Characteristics = Executable 32-bit NoRelocs NoLineNums NoLocalSyms
Created = 2010-11-20 10:05:05
Headers Size = 4096
Checksum = 0
Name = diskpart.exe
Image Size = 3514368
Section Alignment = 4096
File Alignment = 4096
Code Size = 28672
Initialized Data Size = 3481600
Uninitialized Data Size = 0
Linker Version = 6.0
OS Version = 4.0
Image Version = 0.0
Subsystem Version = 4.0
Subsystem = Windows GUI
Stack Reserve = 1048576
Stack Commit = 4096
Heap Reserve = 1048576
Heap Commit = 4096
Image Base = 4194304
Comment = FileVersion: 6.1.7601.17514
FileVersion: 6.1.7601.17514 (win7sp1_rtm.101119-1850)
ProductVersion: 6.1.7601.17514
CompanyName: Microsoft Corporation
FileDescription: DiskPart
InternalName: diskpart.exe
LegalCopyright: © Microsoft Corporation. All rights reserved.
OriginalFilename: diskpart.exe
ProductName: Microsoft® Windows® Operating System
----
Path = .rsrc/XIA/2058
Size = 3446325
Packed Size = 3446325
--
Path = .rsrc/XIA/2058
Type = zip
Physical Size = 3446325

    
Enter password (will not be echoed):
</pre>

Next, we will disassemble the program using IDA, and right at the beginning of the code, we come across this.

```assembly
loc_4020B4:
lea     eax, [ebp+Filename]
push    eax             ; lpPathName
call    ds:SetCurrentDirectoryA
push    1
call    sub_4010FD
mov     [esp+6F4h+Str], offset Str ; "WNcry@2ol7" <= THIS IS THE PASSWORD
push    ebx             ; hModule
call    sub_401DAB
call    sub_401E9E
push    ebx             ; lpExitCode
push    ebx             ; dwMilliseconds
push    offset CommandLine ; "attrib +h ."
call    sub_401064
push    ebx             ; lpExitCode
push    ebx             ; dwMilliseconds
push    offset aIcaclsGrantEve ; "icacls . /grant Everyone:F /T /C /Q"
call    sub_401064
add     esp, 20h
call    sub_40170A
test    eax, eax
jz      short loc_402165
```

Therefore, we can finally unzip the file with the correct password.

```text
Everything is Ok

Files: 36
Size:       6162177
Compressed: 3514368
petik@labvx:articles$ tree 
.
├── b.wnry
├── c.wnry
├── ed01ebfbc9eb5bbea545af4d01bf5f1071661840480439c6e5babe8e080e41aa
├── msg
│   ├── m_bulgarian.wnry
│   ├── m_chinese (simplified).wnry
│   ├── m_chinese (traditional).wnry
│   ├── m_croatian.wnry
│   ├── m_czech.wnry
│   ├── m_danish.wnry
│   ├── m_dutch.wnry
│   ├── m_english.wnry
│   ├── m_filipino.wnry
│   ├── m_finnish.wnry
│   ├── m_french.wnry
│   ├── m_german.wnry
│   ├── m_greek.wnry
│   ├── m_indonesian.wnry
│   ├── m_italian.wnry
│   ├── m_japanese.wnry
│   ├── m_korean.wnry
│   ├── m_latvian.wnry
│   ├── m_norwegian.wnry
│   ├── m_polish.wnry
│   ├── m_portuguese.wnry
│   ├── m_romanian.wnry
│   ├── m_russian.wnry
│   ├── m_slovak.wnry
│   ├── m_spanish.wnry
│   ├── m_swedish.wnry
│   ├── m_turkish.wnry
│   └── m_vietnamese.wnry
├── r.wnry
├── s.wnry
├── taskdl.exe
├── taskse.exe
├── t.wnry
└── u.wnry

1 directory, 37 files

```



In the in-depth analysis of the composition of the WannaCry ransomware, we have uncovered several essential files orchestrating its formidable operation. Here is an overview of these components:

1.  **File b.wnry (Bitmap Image)**: This file appears to be used to change the victim's wallpaper once the system has been compromised.

![image](/images/wanacry/b.bmp)
    
2.  **File c.wnry (Darkweb Data)**: This file contains a list of onion addresses from the darkweb, along with a link to download the Tor Browser. These elements may be utilized by attackers to establish anonymous connections and operate on the darkweb.

```text
gx7ekbenv2riucmf.onion;57g7spgrzlojinas.onion;xxlvbrloxvriy2c5.onion;76jdd2ir2embyv47.onion;cwwnhwhlz52maqm7.onion;
https://dist.torproject.org/torbrowser/6.5.1/tor-win32-0.2.9.10.zip

```
    
3.  **File r.wnry (Ransom Note)**: This is the ransom note left by the assailants on infected systems. The note explains the victim's situation, provides instructions for paying the ransom in Bitcoin, and explains how to obtain the decryption tool. It is intended to compel the victim to cooperate.

```text
Q:  What's wrong with my files?
A:  Ooops, your important files are encrypted. It means you will not be able to access them anymore until they are decrypted.
    If you follow our instructions, we guarantee that you can decrypt all your files quickly and safely!
    Let's start decrypting!
Q:  What do I do?
A:  First, you need to pay service fees for the decryption.
    Please send %s to this bitcoin address: %s
    Next, please find an application file named "%s". It is the decrypt software.
    Run and follow the instructions! (You may need to disable your antivirus for a while.)
    
Q:  How can I trust?
A:  Don't worry about decryption.
    We will decrypt your files surely because nobody will trust us if we cheat users.
    
*   If you need our assistance, send a message by clicking <Contact Us> on the decryptor window.

```

4.  **File s.wnry (Zipped File)**: This file appears to be an unprotected archive that, when decompressed, reveals a list of files, including libraries and Tor executables, suggesting that WannaCry might use the Tor network for anonymous communications.

<pre>
petik@labvx:articles$ tree Data/ Tor/
Data/
└── Tor
Tor/
├── libeay32.dll
├── libevent-2-0-5.dll
├── libevent_core-2-0-5.dll
├── libevent_extra-2-0-5.dll
├── libgcc_s_sjlj-1.dll
├── libssp-0.dll
├── ssleay32.dll
├── tor.exe
└── zlib1.dll
</pre>

5.  **File t.wnry (Data File)**: This file begins with the string "WANACRY!" and likely contains crucial data for the ransomware's operation.
    
6.  **File taskdl.exe**: This executable appears to be associated with a specific task of the ransomware, although its exact function requires further in-depth analysis.
    
7.  **File taskse.exe**: Similar to taskdl.exe, this file seems to be a key component of the WannaCry ransomware, but its precise function warrants detailed investigation.
    
8.  **File u.wnry (The Ransomware Itself)**: Finally, this file is the ransomware proper. It is responsible for encrypting the victim's files using a public key encryption scheme and manages the ransom demand process.

9. **taskdl.exe and  taskse.exe**

* `taskdl.exe` and `taskse.exe` serve specific roles in the WannaCry ransomware infection process:

* **taskdl.exe**: This executable file is typically responsible for the initial download and deployment of the ransomware onto the victim's system. It may be used to carry out various actions, such as exploiting vulnerabilities to infect the target computer. Taskdl.exe can be the first step in the infection chain and may be associated with spreading the ransomware across a network.
    
* **taskse.exe**: This second executable file, taskse.exe, is likely used to execute specific tasks related to the encryption of the victim's files. It could be responsible for generating and managing the encryption keys needed to securely lock the files. Additionally, it may play a role in the ransom demand process by displaying the ransom note and guiding the victim on how to pay the ransom in Bitcoin.
    
* Both of these files, taskdl.exe and taskse.exe, are crucial to the overall operation of the WannaCry ransomware, although their precise functions may vary depending on different versions of the malware. Generally, they are used for installation, propagation, and file encryption, making them integral parts of the attack process.

10. **All files in msg/ Directory** 
All translations for the ransomware

![image](/images/wanacry/wannacry-02.jpeg)

![image](/images/wanacry/wannacry-01.jpeg)

### Conclusion

In conclusion, the thorough analysis of the WannaCry ransomware family highlights a crucial aspect of cybersecurity: the importance of public awareness and education. This devastating attack underscores the vulnerability of our computer systems and the urgency of adopting robust security practices. It is essential for everyone to understand the critical role of regular updates, data backups, and caution when dealing with unknown emails and links. WannaCry is not just a lesson for security experts, but a reminder for all computer users about the need to remain vigilant and informed in an ever-evolving digital world.

<iframe width="1280" height="720" src="https://www.youtube.com/embed/rEFre8G_IQw?si=HO__pDRGKc1AGpO9" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
# 🛠️ Some Practice Technics  
### ✍️ By PetiK (02/10/2002) — Remastered in 2025

---

## 📌 Introduction

This article presents some techniques that I used for my worms.  
I’m not a top-tier coder like Benny, GriYO, or Bumblebee, but I want to share what I know.  
Each section includes example source code.

### Summary:
- I: Hide a copy of the worm  
- II: Spread a worm into different drives  
- III: Extract API from `KERNEL32.DLL`

---

## 🔒 I. Hide a Copy of the Worm

Many worms use static filenames like:
- `services.exe` (XTC)
- `winmine.exe` (Chainsaw)
- `wsock2.dll` (Icecubes)

That makes them easy to find and delete.  
So instead, I randomize the filename at each execution using API calls and `GetTickCount()`.

### 📄 Steps:

1. **Create a random name in `%windir%` or `%sysdir%`:**
   - Use `GetSystemDirectoryA` to build a path
   - Generate a random filename (e.g., `jwvv.exe`, `abgqlbg.exe`, `slb.exe`)
   - Avoid repeating characters by calling `Sleep()` between loops

2. **Schedule deletion of the original worm using `WININIT.INI`:**

```
[rename]
NUL=original_name
```

3. **Copy the worm to its new location** using `CopyFileA`

4. **Register it to run on startup** via the `RUN` key in `WIN.INI`

➡️ Full source code provided below (MASM format)

---

## 💾 II. Spread a Worm into Different Drives

One copy is good. Many copies are better.  
This technique replicates the worm to multiple drives (D: to Z:), skipping floppy drives (A: and B:).

### 🧰 Code Strategy:
- Retrieve the worm’s current path with `GetModuleFileNameA`
- Loop through all drives and copy the worm as `winbackup.exe`
- Use `SetCurrentDirectoryA` to switch directories

➡️ Full MASM source included with all drive letters listed explicitly.

---

## 🧠 III. Extract API from `KERNEL32.DLL`

Debuggers like W32DASM reveal which APIs a binary uses.  
This makes it easier to detect malicious behavior like file manipulation.

### 🕵️ To avoid detection:
Instead of using standard imports, dynamically resolve function addresses at runtime.

#### 📉 Traditional view in debugger:
```
KERNEL32.CloseHandle
KERNEL32.CreateFileA
KERNEL32.WriteFile
```

#### ✅ After hiding:
Only these are shown:
```
KERNEL32.GetModuleHandleA
KERNEL32.GetProcAddress
```

### 🧪 Code Flow:
1. Get handle to `KERNEL32.DLL`
2. Use `GetProcAddress` to resolve API pointers:
   - `CloseHandle`
   - `CreateFileA`
   - `WriteFile`
3. Call them manually

➡️ MASM source provided to write a message into `C:\KernApi.txt` using dynamic API calls.

---

## 📬 Conclusion

If you have questions or suggestions, feel free to reach out:  
✉️ **petikvx@multimania.com**  
🌐 **www.petikvx.fr.fm**

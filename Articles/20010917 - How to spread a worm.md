# 🪱 How to Spread a Worm – *Vintage Techniques from 2001*  
### ✍️ By PetiK (09/17/2001) — Cleaned & Enhanced in 2025

---

## 🔍 Step 1 – Harvesting Email Addresses

The hardest part of writing a worm isn't the payload… it’s *finding who to send it to*.  
Fortunately, Windows is full of hidden address sources—if you know where to look.

---

### 📁 Source #1 – Windows Address Book (`*.WAB` files)

The Windows Address Book stores user contacts and can be located via the registry key:

```
HKEY_CURRENT_USER\Software\Microsoft\Wab\WAB4\Wab File Name
```

Rather than parsing it manually, a VBScript file can automate the process:

- Drop a `.vbs` script on `C:\`
- Query Outlook for saved contacts
- Save harvested emails to a hidden file in `C:\Windows` or `C:\System`

📌 **Example Reference**: See `Win32.HiV` by Benny, or analyze how `I-Worm.Passion` and `I-Worm.Rush` collect addresses.

---

### 🌐 Source #2 – HTML Files in Browser Cache

Internet Explorer stores lots of cached pages (`*.htm`, `*.html`) that may contain `mailto:` links or plain-text addresses.

Use this API:

```c
SHGetSpecialFolderPathA() // from SHELL32.dll
```

Or read from the registry:

```
HKEY_USERS\.DEFAULT\Software\Microsoft\Windows\
CurrentVersion\Explorer\Shell Folders\Cache
```

These files don’t always have many emails, but scanning hundreds can yield results.

---

### ✉️ Source #3 – Outlook Express Emails (`*.EML`)

Outgoing `.eml` files contain headers like:

```
To: <victim@multimania.com>
```

Just search for the string `To: <` in `.eml` files and extract the email address following it.

---

## 📨 Step 2 – Injecting Your Worm in Emails

Now that you have your target list, it's time to spread.

You can insert your worm into an existing email file (`.eml`) by manipulating MIME boundaries and injecting a second attachment, *without breaking the original mail structure*.

---

### 🧬 Anatomy of a Multipart Email

Here’s a basic `.eml` layout with one attachment:

```text
From: "PetiKVX" <petikvx@multimania.com>
To: <victim@multimania.com>
Subject: Virus Spread
Date: Sun, 16 Sep 2001 20:54:11 +0200
MIME-Version: 1.0
Content-Type: multipart/mixed;
    boundary="----=_NextPart_000_0008_01C13EF1.BF420560"
```

Then comes:

- The plain text body
- The first attachment (`Winpopup.exe`)

To **add your own virus**, inject another section like this:

```text
------=_NextPart_000_0008_01C13EF1.BF420560
Content-Type: application/x-msdownload;
    name="virus.exe"
Content-Transfer-Encoding: base64
Content-Disposition: attachment;
    filename="virus.exe"

TVpQAAIAAAAEAA8A//8AALgAAAAAAAAAQAAaAAA...
```

✅ **Important MIME Tips**:

- Remove `--` from the final boundary before your injection.
- Add `--` **only after** your payload to signal end of the message.

**Correct order at the end:**

```text
------=_NextPart_000_0008_01C13EF1.BF420560
[your payload block]

------=_NextPart_000_0008_01C13EF1.BF420560--
```

---

## 💡 Final Notes

- Always keep your payload encoded (Base64).
- Use misleading filenames to reduce suspicion.
- This trick only works if the client properly renders the modified `.eml` (e.g., Outlook Express).

---

## 📬 Got Suggestions?

Email me: **petikvx@multimania.com**  
Check my site (still alive?): **http://www.petikvx.fr.fm**

---

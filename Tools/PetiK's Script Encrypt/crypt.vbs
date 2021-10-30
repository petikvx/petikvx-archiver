On Error Resume Next
Execute Y("Οξ Εςςος Òεσυνε ΞεψτΝσηΒοψ ΆΤθισ ισ νω ζιςστ ΦΒΣ ζιμε εξγςωπτεςΆ¬φβγςιτιγαμ¬ΆΠετιΛ§σ Σγςιπτ ΕξγςωπτΆΧΣγςιπτ®Ρυιτ")
Function Y(ajuo)
For W=1 to Len(ajuo)
Y=Y & Chr(Asc(Mid(ajuo,W,1)) Xor 128)
Next
End Function
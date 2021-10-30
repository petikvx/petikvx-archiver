VERSION 5.00
Begin VB.Form about 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "PVBSWG 1.0 - About"
   ClientHeight    =   2040
   ClientLeft      =   6225
   ClientTop       =   5205
   ClientWidth     =   3615
   Icon            =   "about.frx":0000
   LinkTopic       =   "Form2"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2040
   ScaleWidth      =   3615
   Visible         =   0   'False
   Begin VB.PictureBox Picture1 
      Height          =   855
      Left            =   360
      Picture         =   "about.frx":08CA
      ScaleHeight     =   795
      ScaleWidth      =   2835
      TabIndex        =   0
      Top             =   240
      Width           =   2895
   End
   Begin VB.Label Label1 
      Caption         =   "Coded by PetiK - (c)2002 Made in France"
      Height          =   495
      Left            =   1080
      TabIndex        =   1
      Top             =   1320
      Width           =   1815
   End
End
Attribute VB_Name = "about"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

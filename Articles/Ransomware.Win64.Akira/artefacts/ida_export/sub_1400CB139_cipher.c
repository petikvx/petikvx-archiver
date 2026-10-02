__int64 __fastcall sub_1400CB139(__int64 a1, __int64 a2)
{
  __int64 v2; // rbx
  __int64 v3; // rax
  __int64 v4; // rax
  __int64 v5; // rcx

  v2 = *(_QWORD *)(a2 + 48);
  v3 = sub_14003E800(a1: (void *)(v2 + 352));
  v4 = sub_14003E3F0(a1: v2 + 384, a2: "(Full) Cipher error:", a3: v3);
  sub_140039EC0(a1: v5, a2: v4);
  sub_1400371B0(a1: v2 + 384);
  sub_1400371B0(a1: v2 + 352);
  *(_BYTE *)(v2 + 168) = 0;
  return 0;
}
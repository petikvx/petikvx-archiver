__int64 __fastcall sub_1400C7EEC(__int64 a1, __int64 a2)
{
  __int64 v3; // rcx
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v6; // rcx

  v3 = *(_QWORD *)(a2 + 96);
  _InterlockedDecrement((volatile signed __int32 *)(v3 + 56));
  Cnd_signal(a1: (_Cnd_t)(v3 + 224));
  *(_QWORD *)(a2 + 96) = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(a2 + 160) + 8LL))(a1: *(_QWORD *)(a2 + 160));
  v4 = sub_14003E680(a1: (void *)(a2 + 232));
  v5 = sub_14003E3F0(a1: a2 + 200, a2: "enqueueEncrypt failed:", a3: v4);
  sub_140039EC0(a1: v6, a2: v5);
  sub_1400371B0(a1: a2 + 200);
  sub_1400371B0(a1: a2 + 232);
  return 0;
}
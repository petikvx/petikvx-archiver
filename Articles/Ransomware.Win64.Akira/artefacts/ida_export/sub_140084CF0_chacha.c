__int64 __fastcall sub_140084CF0(_DWORD *a1, _DWORD *a2, int a3)
{
  char *v3; // r9
  _DWORD *v5; // rcx
  __int64 result; // rax

  v3 = "expand 32-byte kexpand 16-byte k ";
  a1[4] = *a2;
  a1[5] = a2[1];
  a1[6] = a2[2];
  a1[7] = a2[3];
  if ( a3 != 256 )
    v3 = "expand 16-byte k ";
  v5 = a2 + 4;
  if ( a3 != 256 )
    v5 = a2;
  a1[8] = *v5;
  a1[9] = v5[1];
  a1[10] = v5[2];
  a1[11] = v5[3];
  *a1 = *(_DWORD *)v3;
  a1[1] = *((_DWORD *)v3 + 1);
  a1[2] = *((_DWORD *)v3 + 2);
  result = *((unsigned int *)v3 + 3);
  a1[3] = result;
  return result;
}
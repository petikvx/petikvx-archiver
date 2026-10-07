// ---- sub_140001000 @ 0x140001000 ----
__int64 __fastcall sub_140001000(_QWORD **a1)
{
  _QWORD *v2; // rcx
  _QWORD *v3; // rdi
  __int64 result; // rax

  v2 = *a1;
  if ( v2 != nullptr )
  {
    do
    {
      v3 = (_QWORD *)*v2;
      result = sub_140001C10();
      *a1 = v3;
      v2 = v3;
    }
    while ( v3 != nullptr );
  }
  return result;
}


// ---- sub_140001040 @ 0x140001040 ----
__int64 __fastcall sub_140001040(char *a1, unsigned __int64 *a2, __int64 *a3, _QWORD *a4)
{
  __int64 v4; // r13
  unsigned __int64 *v6; // rsi
  char *v7; // r14
  char v8; // bp
  int v9; // r12d
  __int64 *v10; // rax
  __int64 v11; // rcx
  __int64 v12; // rdx
  __int64 **v13; // rcx
  unsigned __int64 v14; // rdx
  char *v15; // r14
  char v16; // cl
  char v17; // cl
  __int64 result; // rax
  __int64 v19; // rax
  unsigned int v20; // ebp
  unsigned __int64 v21; // rcx
  __int64 v22; // rdx
  __int64 v23; // r15
  unsigned __int8 v24; // cl
  unsigned int v25; // ebp
  unsigned __int64 v26; // rcx
  __int64 v27; // rdx
  __int64 v28; // rax
  __int64 v29; // rcx
  __int64 v30; // r15
  char *v31; // rbp
  unsigned int v32; // r14d
  double v33; // xmm0_8
  double v34; // xmm1_8
  int v35; // eax
  double v36; // xmm1_8
  double v37; // xmm2_8
  unsigned int v38; // eax
  unsigned __int64 v39; // rcx
  __int64 v40; // rdx
  __int64 v41; // rbp
  __int64 v42; // rdi
  int v43; // r15d
  unsigned __int64 *v44; // r12
  __int64 v45; // rsi
  _QWORD *v46; // r13
  __int64 v47; // rbx
  __int64 v48; // rax
  __int64 v49; // rcx
  __int64 v50; // rcx
  __int64 **v51; // rcx
  bool v52; // cc
  __int64 v53; // rdi
  __int64 v54; // rax
  __int64 v55; // rcx
  _QWORD *v56; // rax
  _QWORD *v57; // rax
  __int64 v58; // rdx
  unsigned int v59; // ebp
  unsigned __int64 v60; // rcx
  __int64 v61; // rdx
  char *v62; // rax
  char v63; // cl
  int v64; // eax
  int v65; // r8d
  int v66; // eax
  char v67; // r8
  int v68; // ecx
  int v69; // r9d
  int v70; // ecx
  char v71; // r8
  int v72; // r9d
  int v73; // r10d
  int v74; // r9d
  char v75; // r10
  int v76; // r8d
  int v77; // r9d
  int v78; // eax
  int v79; // r8d
  unsigned int v80; // r8d
  unsigned __int8 v81; // cl
  unsigned __int8 v82; // cl
  unsigned __int8 v83; // cl
  unsigned int v84; // ebp
  unsigned __int64 v85; // rcx
  __int64 v86; // rdx
  __int64 v87; // rax
  __int64 v88; // [rsp+20h] [rbp-318h]
  __int64 v89; // [rsp+20h] [rbp-318h]
  _DWORD v91[160]; // [rsp+30h] [rbp-308h]

  v6 = a2;
  v7 = a1;
  *a2 = (unsigned __int64)a1;
  v8 = 1;
  v9 = -1;
LABEL_6:
  v14 = (unsigned __int64)v7;
  while ( 2 )
  {
    if ( *(_BYTE *)v14 == 0 )
      return 9;
    v15 = (char *)v14;
    do
    {
      if ( (unsigned __int8)((__int64 (*)(void))sub_140001B10)() == 0 )
        break;
      v16 = *++v15;
    }
    while ( v16 != 0 );
    *v6 = (unsigned __int64)v15;
    v17 = *v15;
    result = 7;
    v14 = (unsigned __int64)(v15 + 1);
    switch ( *v15 )
    {
      case 0:
        continue;
      case 34:
        v23 = v14 | 0x7FF8800000000000LL;
        v24 = *(_BYTE *)v14;
        if ( *(_BYTE *)v14 == 0 )
        {
          v7 = v15 + 1;
          goto LABEL_68;
        }
        v88 = v14 | 0x7FF8800000000000LL;
        v7 = v15 + 1;
        while ( 2 )
        {
          *(_BYTE *)v14 = v24;
          if ( v24 != 92 )
          {
            if ( v24 < 0x20u || v24 == 127 )
              goto LABEL_167;
            if ( v24 != 34 )
              goto LABEL_113;
            *(_BYTE *)v14 = 0;
            v84 = (unsigned __int8)*++v7;
            v85 = (unsigned int)(unsigned __int8)v84 - 44;
            if ( (unsigned int)v85 <= 0x31 && (v86 = 0x2000000004001LL, _bittest64(&v86, v85)) )
            {
LABEL_148:
              v23 = v88;
            }
            else
            {
              v23 = v88;
              if ( (unsigned __int8)v84 != 125 && ((unsigned __int8)sub_140001B10(v84) | ((_BYTE)v84 == 0)) == 0 )
                goto LABEL_167;
            }
LABEL_68:
            if ( v9 == -1 )
            {
              *v6 = (unsigned __int64)v7;
              *a3 = v23;
              return 0;
            }
            v41 = v9;
            if ( v91[v9] != 3 )
            {
              v53 = *a4;
              if ( *a4 != 0 && (v54 = *(_QWORD *)(v53 + 8), v55 = v54 + 16, (unsigned __int64)(v54 + 16) <= 0x1000) )
              {
                v10 = (__int64 *)(v53 + v54);
                *(_QWORD *)(v53 + 8) = v55;
                v11 = *(_QWORD *)&v91[2 * v9 + 96];
                if ( v11 == 0 )
                  goto LABEL_82;
              }
              else
              {
                v56 = (_QWORD *)sub_140001B80(4096);
                if ( v56 == nullptr )
                  return 10;
                v56[1] = 32;
                *v56 = v53;
                *a4 = v56;
                v10 = v56 + 2;
                v11 = *(_QWORD *)&v91[2 * v9 + 96];
                if ( v11 == 0 )
                {
LABEL_82:
                  v13 = (__int64 **)(v10 + 1);
                  goto LABEL_4;
                }
              }
              v12 = *(_QWORD *)(v11 + 8);
              v13 = (__int64 **)(v11 + 8);
              v10[1] = v12;
LABEL_4:
              *v13 = v10;
              *(_QWORD *)&v91[2 * v9 + 96] = v10;
              goto LABEL_5;
            }
            v42 = *(_QWORD *)&v91[2 * v9 + 32];
            if ( v42 != 0 )
            {
              v89 = v23;
              v43 = v9;
              v44 = v6;
              v45 = v4;
              v46 = a4;
              v47 = *a4;
              if ( v47 != 0 && (v48 = *(_QWORD *)(v47 + 8), v49 = v48 + 24, (unsigned __int64)(v48 + 24) <= 0x1000) )
              {
                v10 = (__int64 *)(v47 + v48);
                *(_QWORD *)(v47 + 8) = v49;
                a4 = v46;
                v50 = *(_QWORD *)&v91[2 * v41 + 96];
                v4 = v45;
                if ( v50 != 0 )
                  goto LABEL_85;
              }
              else
              {
                v57 = (_QWORD *)sub_140001B80(4096);
                if ( v57 == nullptr )
                  return 10;
                v57[1] = 40;
                *v57 = v47;
                a4 = v46;
                *v46 = v57;
                v10 = v57 + 2;
                v50 = *(_QWORD *)&v91[2 * v41 + 96];
                v4 = v45;
                if ( v50 != 0 )
                {
LABEL_85:
                  v58 = *(_QWORD *)(v50 + 8);
                  v51 = (__int64 **)(v50 + 8);
                  v10[1] = v58;
                  goto LABEL_86;
                }
              }
              v51 = (__int64 **)(v10 + 1);
LABEL_86:
              v6 = v44;
              *v51 = v10;
              *(_QWORD *)&v91[2 * v41 + 96] = v10;
              v10[2] = v42;
              *(_QWORD *)&v91[2 * v41 + 32] = 0;
              v9 = v43;
              v23 = v89;
LABEL_5:
              *v10 = v23;
              v8 = 0;
            }
            else
            {
              result = 8;
              if ( v23 <= 0x7FF8000000000000LL || (v23 & 0x7800000000000LL) != 0x800000000000LL )
                return result;
              *(_QWORD *)&v91[2 * v9 + 32] = v23 & 0x7FFFFFFFFFFFLL;
              v8 = 0;
            }
            goto LABEL_6;
          }
          v62 = v7 + 1;
          switch ( v7[1] )
          {
            case '"':
            case '/':
            case '\\':
              *(_BYTE *)v14 = v7[1];
              goto LABEL_106;
            case 'b':
              *(_BYTE *)v14 = 8;
              goto LABEL_106;
            case 'f':
              *(_BYTE *)v14 = 12;
              goto LABEL_106;
            case 'n':
              *(_BYTE *)v14 = 10;
              goto LABEL_106;
            case 'r':
              *(_BYTE *)v14 = 13;
              goto LABEL_106;
            case 't':
              *(_BYTE *)v14 = 9;
              goto LABEL_106;
            case 'u':
              v63 = v7[2];
              v64 = (unsigned __int8)v63;
              if ( (unsigned __int8)(v63 - 48) > 9u
                && (v64 = v63, ((v63 ^ 0x20) & ((unsigned __int8)v63 | 0xFFFFFFDF)) - 65 > 5) )
              {
                v87 = 2;
              }
              else
              {
                v65 = v64 + 16777168;
                v66 = (v64 & 0x5F) + 16777161;
                if ( v63 < 58 )
                  v66 = v65;
                v67 = v7[3];
                v68 = (unsigned __int8)v67;
                if ( (unsigned __int8)(v67 - 48) > 9u
                  && (v68 = v67, ((v67 ^ 0x20) & ((unsigned __int8)v67 | 0xFFFFFFDF)) - 65 > 5) )
                {
                  v87 = 3;
                }
                else
                {
                  v69 = v68 + 268435408;
                  v70 = (v68 & 0x5F) + 268435401;
                  if ( v67 < 58 )
                    v70 = v69;
                  v71 = v7[4];
                  v72 = (unsigned __int8)v71;
                  if ( (unsigned __int8)(v71 - 48) > 9u
                    && (v72 = v71, ((v71 ^ 0x20) & ((unsigned __int8)v71 | 0xFFFFFFDF)) - 65 > 5) )
                  {
                    v87 = 4;
                  }
                  else
                  {
                    v73 = v72 - 48;
                    v74 = (v72 & 0x5F) - 55;
                    if ( v71 < 58 )
                      v74 = v73;
                    v75 = v7[5];
                    v76 = (unsigned __int8)v75;
                    if ( (unsigned __int8)(v75 - 48) <= 9u
                      || (v76 = v75, ((v75 ^ 0x20) & ((unsigned __int8)v75 | 0xFFFFFFDF)) - 65 <= 5) )
                    {
                      v7 += 5;
                      v77 = 16 * ((v66 << 8) + 16 * v70 + v74);
                      v78 = v76 - 48;
                      v79 = (v76 & 0x5F) - 55;
                      if ( v75 < 58 )
                        v79 = v78;
                      v80 = v77 + v79;
                      if ( (int)v80 >= 128 )
                      {
                        if ( v80 > 0x7FF )
                        {
                          *(_BYTE *)v14 = (v80 >> 12) | 0xE0;
                          *(_BYTE *)(v14 + 1) = (v80 >> 6) & 0x3F | 0x80;
                          *(_BYTE *)(v14 + 2) = v80 & 0x3F | 0x80;
                          v14 += 2LL;
                        }
                        else
                        {
                          *(_BYTE *)v14 = (v80 >> 6) | 0xC0;
                          *(_BYTE *)++v14 = v80 & 0x3F | 0x80;
                        }
                      }
                      else
                      {
                        *(_BYTE *)v14 = v80;
                      }
LABEL_113:
                      v62 = v7;
LABEL_106:
                      ++v14;
                      v24 = v62[1];
                      v7 = v62 + 1;
                      if ( v24 == 0 )
                        goto LABEL_148;
                      continue;
                    }
                    v87 = 5;
                  }
                }
              }
              v7 += v87;
LABEL_167:
              *v6 = (unsigned __int64)v7;
LABEL_168:
              result = 2;
              break;
            default:
              *v6 = (unsigned __int64)v62;
              goto LABEL_168;
          }
          return result;
        }
      case 44:
        if ( (v8 & 1) != 0 )
          return result;
        v8 = 1;
        if ( *(_QWORD *)&v91[2 * v9 + 32] != 0 )
          return result;
        continue;
      case 45:
        if ( (unsigned __int8)(*(_BYTE *)v14 - 48) < 0xAu || *(_BYTE *)v14 == 46 )
          goto LABEL_43;
        *v6 = v14;
        return 1;
      case 48:
      case 49:
      case 50:
      case 51:
      case 52:
      case 53:
      case 54:
      case 55:
      case 56:
      case 57:
LABEL_43:
        v31 = &v15[v17 == 45];
        v32 = (unsigned __int8)*v31;
        v33 = 0.0;
        if ( (unsigned __int8)(v32 - 48) <= 9u )
        {
          do
          {
            v33 = v33 * 10.0 + (double)(v32 & 0xF);
            v32 = (unsigned __int8)*++v31;
          }
          while ( (unsigned __int8)(v32 - 48) < 0xAu );
        }
        if ( (_BYTE)v32 == 46 )
        {
          v32 = (unsigned __int8)*++v31;
          if ( (unsigned __int8)(v32 - 48) <= 9u )
          {
            v34 = 1.0;
            do
            {
              v34 = v34 * 0.1;
              v33 = v33 + (double)((unsigned __int8)v32 - 48) * v34;
              v32 = (unsigned __int8)*++v31;
            }
            while ( (unsigned __int8)(v32 - 48) < 0xAu );
          }
        }
        if ( ((unsigned __int8)v32 | 0x20) != 0x65 )
          goto LABEL_61;
        v35 = (unsigned __int8)v31[1];
        if ( v35 == 45 )
        {
          v31 += 2;
          v36 = 0.1;
          v32 = (unsigned __int8)*v31;
          if ( (unsigned __int8)(v32 - 48) <= 9u )
          {
LABEL_57:
            v38 = 0;
            do
            {
              v38 = (v32 & 0xF) + 10 * v38;
              v32 = (unsigned __int8)*++v31;
            }
            while ( (unsigned __int8)(v32 - 48) < 0xAu );
            v37 = 1.0;
            if ( v38 != 0 )
            {
              do
              {
                if ( (v38 & 1) != 0 )
                  v37 = v37 * v36;
                v36 = v36 * v36;
                v52 = v38 <= 1;
                v38 >>= 1;
              }
              while ( !v52 );
            }
LABEL_60:
            v33 = v33 * v37;
LABEL_61:
            if ( v17 == 45 )
              v33 = -v33;
            v23 = *(_QWORD *)&v33;
            v39 = (unsigned int)(unsigned __int8)v32 - 44;
            if ( (unsigned int)v39 <= 0x31 && (v40 = 0x2000000004001LL, _bittest64(&v40, v39))
              || (unsigned __int8)v32 == 125
              || ((unsigned __int8)sub_140001B10(v32) | ((_BYTE)v32 == 0)) != 0 )
            {
              v7 = v31;
              goto LABEL_68;
            }
            *v6 = (unsigned __int64)v31;
            return 1;
          }
        }
        else
        {
          if ( v35 == 43 )
            v31 += 2;
          else
            ++v31;
          v36 = 10.0;
          v32 = (unsigned __int8)*v31;
          if ( (unsigned __int8)(v32 - 48) <= 9u )
            goto LABEL_57;
        }
        v37 = 1.0;
        goto LABEL_60;
      case 58:
        if ( (v8 & 1) != 0 )
          return result;
        v8 = 1;
        if ( *(_QWORD *)&v91[2 * v9 + 32] == 0 )
          return result;
        continue;
      case 91:
        if ( ++v9 == 32 )
          return 4;
        v19 = v9;
        *(_QWORD *)&v91[2 * v9 + 96] = 0;
        v91[v9] = 2;
        goto LABEL_97;
      case 93:
        if ( v9 == -1 )
          return 5;
        if ( v91[v9] != 2 )
          return 6;
        v28 = *(_QWORD *)&v91[2 * v9 + 96];
        v29 = 0x1000000000000LL;
        v30 = 0x1000000000000LL;
        if ( v28 != 0 )
          goto LABEL_93;
        goto LABEL_94;
      case 102:
        result = 3;
        if ( *(_BYTE *)v14 != 97 || v15[2] != 108 || v15[3] != 115 || v15[4] != 101 )
          return result;
        v20 = (unsigned __int8)v15[5];
        v7 = v15 + 5;
        v21 = (unsigned int)(unsigned __int8)v20 - 44;
        if ( (unsigned int)v21 <= 0x31 && (v22 = 0x2000000004001LL, _bittest64(&v22, v21))
          || (unsigned __int8)v20 == 125 )
        {
          v23 = 0x7FFA800000000000LL;
          goto LABEL_68;
        }
        v83 = sub_140001B10(v20);
        result = 3;
        v23 = 0x7FFA800000000000LL;
        if ( (v83 | ((_BYTE)v20 == 0)) == 0 )
          return result;
        goto LABEL_68;
      case 110:
        result = 3;
        if ( *(_BYTE *)v14 != 117 || v15[2] != 108 || v15[3] != 108 )
          return result;
        v59 = (unsigned __int8)v15[4];
        v7 = v15 + 4;
        v60 = (unsigned int)(unsigned __int8)v59 - 44;
        if ( (unsigned int)v60 <= 0x31 && (v61 = 0x2000000004001LL, _bittest64(&v61, v60))
          || (unsigned __int8)v59 == 125 )
        {
          v23 = 0x7FFF800000000000LL;
          goto LABEL_68;
        }
        v82 = sub_140001B10(v59);
        result = 3;
        v23 = 0x7FFF800000000000LL;
        if ( (v82 | ((_BYTE)v59 == 0)) == 0 )
          return result;
        goto LABEL_68;
      case 116:
        result = 3;
        if ( *(_BYTE *)v14 != 114 || v15[2] != 117 || v15[3] != 101 )
          return result;
        v25 = (unsigned __int8)v15[4];
        v7 = v15 + 4;
        v26 = (unsigned int)(unsigned __int8)v25 - 44;
        if ( (unsigned int)v26 <= 0x31 && (v27 = 0x2000000004001LL, _bittest64(&v27, v26))
          || (unsigned __int8)v25 == 125 )
        {
          v23 = 0x7FFA000000000000LL;
          goto LABEL_68;
        }
        v81 = sub_140001B10(v25);
        result = 3;
        v23 = 0x7FFA000000000000LL;
        if ( (v81 | ((_BYTE)v25 == 0)) == 0 )
          return result;
        goto LABEL_68;
      case 123:
        if ( ++v9 == 32 )
          return 4;
        v19 = v9;
        *(_QWORD *)&v91[2 * v9 + 96] = 0;
        v91[v9] = 3;
LABEL_97:
        *(_QWORD *)&v91[2 * v19 + 32] = 0;
        v7 = v15 + 1;
        v8 = 1;
        goto LABEL_6;
      case 125:
        if ( v9 == -1 )
          return 5;
        if ( v91[v9] != 3 )
          return 6;
        if ( *(_QWORD *)&v91[2 * v9 + 32] != 0 )
          return result;
        v28 = *(_QWORD *)&v91[2 * v9 + 96];
        v29 = 0x1800000000000LL;
        v30 = 0x1800000000000LL;
        if ( v28 != 0 )
        {
LABEL_93:
          v30 = v29 | *(_QWORD *)(v28 + 8);
          *(_QWORD *)(v28 + 8) = 0;
        }
LABEL_94:
        --v9;
        v23 = v30 | 0x7FF8000000000000LL;
        v7 = v15 + 1;
        goto LABEL_68;
      default:
        return result;
    }
  }
}


// ---- sub_140001B10 @ 0x140001b10 ----
bool __fastcall sub_140001B10(char a1)
{
  return a1 == 32 || (unsigned __int8)(a1 - 9) < 5u;
}


// ---- sub_140001B30 @ 0x140001b30 ----
__int64 __fastcall sub_140001B30()
{
  __int64 result; // rax
  char *v1; // r10
  char *StackLimit; // r11
  char v3; // [rsp+18h] [rbp+8h] BYREF

  v1 = &v3 - result;
  StackLimit = (char *)NtCurrentTeb()->NtTib.StackLimit;
  if ( &v3 - result < StackLimit )
  {
    LOWORD(v1) = (unsigned __int16)v1 & 0xF000;
    do
      StackLimit -= 4096;
    while ( v1 < StackLimit );
  }
  return result;
}


// ---- nullsub_2 @ 0x140001b7d ----
void nullsub_2()
{
  ;
}


// ---- sub_140001B80 @ 0x140001b80 ----
// attributes: thunk
__int64 __fastcall sub_140001B80(__int64 a1)
{
  return sub_14002E070(a1);
}


// ---- sub_140001B90 @ 0x140001b90 ----
unsigned __int8 *__fastcall sub_140001B90(unsigned __int8 *a1, unsigned __int8 a2, unsigned __int64 a3)
{
  unsigned __int8 *result; // rax
  unsigned __int64 v4; // r9
  unsigned __int64 v5; // r10
  __m128i v6; // xmm0
  __m128i v7; // xmm0
  __int64 v8; // r11
  unsigned __int8 *v9; // rcx

  if ( a3 == 0 )
    return a1;
  if ( a3 < 0x10 )
  {
    result = a1;
    v4 = a3;
LABEL_8:
    v9 = result;
    do
    {
      result = v9 + 1;
      *v9++ = a2;
      --v4;
    }
    while ( v4 != 0 );
    return result;
  }
  v5 = a3 & 0xFFFFFFFFFFFFFFF0uLL;
  result = &a1[a3 & 0xFFFFFFFFFFFFFFF0uLL];
  v4 = a3 & 0xF;
  v6 = _mm_cvtsi32_si128(a2);
  v7 = _mm_shuffle_epi32(_mm_shufflelo_epi16(_mm_unpacklo_epi8(v6, v6), 0), 0);
  v8 = 0;
  do
  {
    *(__m128i *)&a1[v8] = v7;
    v8 += 16;
  }
  while ( v5 != v8 );
  if ( v5 != a3 )
    goto LABEL_8;
  return result;
}


// ---- sub_140001C10 @ 0x140001c10 ----
// attributes: thunk
__int64 sub_140001C10(void)
{
  return sub_14002E0B0();
}


// ---- sub_140001C20 @ 0x140001c20 ----
__int64 __fastcall sub_140001C20(__int64 a1)
{
  sub_140001C40();
  return a1;
}


// ---- sub_140001C40 @ 0x140001c40 ----
__int64 __fastcall sub_140001C40(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // r9
  __int64 result; // rax
  unsigned __int64 v5; // r10
  unsigned __int64 v6; // r11
  __int64 v7; // rsi
  __int128 v8; // xmm1
  unsigned __int64 v9; // rcx
  __int64 v10; // rdx
  __int64 v11; // rcx

  if ( a3 == 0 )
    return a1;
  if ( a3 < 0x20 || (unsigned __int64)(a1 - a2) < 0x20 )
  {
    v3 = a2;
    result = a1;
    v5 = a3;
  }
  else
  {
    v6 = a3 & 0xFFFFFFFFFFFFFFE0uLL;
    v3 = a2 + (a3 & 0xFFFFFFFFFFFFFFE0uLL);
    result = a1 + (a3 & 0xFFFFFFFFFFFFFFE0uLL);
    v5 = a3 & 0x1F;
    v7 = 0;
    do
    {
      v8 = *(_OWORD *)(a2 + v7 + 16);
      *(_OWORD *)(a1 + v7) = *(_OWORD *)(a2 + v7);
      *(_OWORD *)(a1 + v7 + 16) = v8;
      v7 += 32;
    }
    while ( v6 != v7 );
    if ( v6 == a3 )
      return result;
  }
  v9 = v5 - 1;
  if ( (v5 & 7) != 0 )
  {
    v10 = 0;
    do
    {
      *(_BYTE *)(result + v10) = *(_BYTE *)(v3 + v10);
      ++v10;
    }
    while ( (v5 & 7) != v10 );
    v3 += v10;
    result += v10;
    v5 -= v10;
  }
  if ( v9 >= 7 )
  {
    v11 = 0;
    do
    {
      *(_BYTE *)(result + v11) = *(_BYTE *)(v3 + v11);
      *(_BYTE *)(result + v11 + 1) = *(_BYTE *)(v3 + v11 + 1);
      *(_BYTE *)(result + v11 + 2) = *(_BYTE *)(v3 + v11 + 2);
      *(_BYTE *)(result + v11 + 3) = *(_BYTE *)(v3 + v11 + 3);
      *(_BYTE *)(result + v11 + 4) = *(_BYTE *)(v3 + v11 + 4);
      *(_BYTE *)(result + v11 + 5) = *(_BYTE *)(v3 + v11 + 5);
      *(_BYTE *)(result + v11 + 6) = *(_BYTE *)(v3 + v11 + 6);
      *(_BYTE *)(result + v11 + 7) = *(_BYTE *)(v3 + v11 + 7);
      v11 += 8;
    }
    while ( v5 != v11 );
    result += v11;
  }
  return result;
}


// ---- sub_140001D60 @ 0x140001d60 ----
unsigned __int64 __fastcall sub_140001D60(unsigned __int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 result; // rax
  bool v4; // cf
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // r9
  unsigned __int64 v7; // r9
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // r10
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // r11
  __int64 v12; // rsi
  __int64 v13; // rcx
  unsigned __int64 v14; // r8
  unsigned __int64 v15; // r10
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // r8
  bool v18; // zf
  __int64 v19; // rcx
  __int128 v20; // xmm1
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // rdx
  __int64 v23; // r8
  __int64 v24; // rdx

  result = a1;
  v4 = a1 < a2;
  v5 = a1 - a2;
  if ( a2 + a3 > result && !v4 && v5 != 0 )
  {
    if ( a3 == 0 )
      return result;
    if ( a3 < 4 || a2 - result < 0x10 )
      goto LABEL_4;
    if ( a3 >= 0x10 )
    {
      v10 = a3 & 0xFFFFFFFFFFFFFFF0uLL;
      v12 = 0;
      do
      {
        *(_OWORD *)(result + a3 - 16 + v12) = *(_OWORD *)(a2 + a3 - 16 + v12);
        v12 -= 16;
      }
      while ( -(__int64)(a3 & 0xFFFFFFFFFFFFFFF0uLL) != v12 );
      if ( v10 == a3 )
        return result;
      if ( (a3 & 0xC) == 0 )
      {
        a3 &= 0xFu;
LABEL_4:
        v6 = a3;
        goto LABEL_20;
      }
    }
    else
    {
      v10 = 0;
    }
    v6 = a3 & 3;
    v13 = -(__int64)v10;
    do
    {
      *(_DWORD *)(result + a3 - 4 + v13) = *(_DWORD *)(a2 + a3 - 4 + v13);
      v13 -= 4;
    }
    while ( -(__int64)(a3 & 0xFFFFFFFFFFFFFFFCuLL) != v13 );
    if ( (a3 & 0xFFFFFFFFFFFFFFFCuLL) == a3 )
      return result;
LABEL_20:
    v14 = v6 - 1;
    v15 = v6 & 3;
    if ( (v6 & 3) != 0 )
    {
      do
      {
        v16 = v6 - 1;
        *(_BYTE *)(result + v6 - 1) = *(_BYTE *)(a2 + v6 - 1);
        --v6;
        --v15;
      }
      while ( v15 != 0 );
      if ( v14 < 3 )
        return result;
    }
    else
    {
      v16 = v6;
      if ( v14 < 3 )
        return result;
    }
    v17 = v16;
    do
    {
      *(_BYTE *)(result + v16 - 1) = *(_BYTE *)(a2 + v16 - 1);
      *(_BYTE *)(result + v16 - 2) = *(_BYTE *)(a2 + v16 - 2);
      *(_BYTE *)(result + v16 - 3) = *(_BYTE *)(a2 + v16 - 3);
      *(_BYTE *)(result + v16 - 4) = *(_BYTE *)(a2 + v16 - 4);
      v18 = v17 == 4;
      v17 -= 4LL;
      v16 = v17;
    }
    while ( !v18 );
    return result;
  }
  if ( a3 == 0 )
    return result;
  if ( a3 >= 8 && v5 >= 0x20 )
  {
    if ( a3 >= 0x20 )
    {
      v11 = a3 & 0xFFFFFFFFFFFFFFE0uLL;
      v19 = 0;
      do
      {
        v20 = *(_OWORD *)(a2 + v19 + 16);
        *(_OWORD *)(result + v19) = *(_OWORD *)(a2 + v19);
        *(_OWORD *)(result + v19 + 16) = v20;
        v19 += 32;
      }
      while ( v11 != v19 );
      if ( v11 == a3 )
        return result;
      if ( (a3 & 0x18) == 0 )
      {
        a3 &= 0x1Fu;
        v8 = result + v11;
        v7 = v11 + a2;
        goto LABEL_8;
      }
    }
    else
    {
      v11 = 0;
    }
    v21 = a3 & 0xFFFFFFFFFFFFFFF8uLL;
    v7 = a2 + (a3 & 0xFFFFFFFFFFFFFFF8uLL);
    v8 = result + (a3 & 0xFFFFFFFFFFFFFFF8uLL);
    v9 = a3 & 7;
    do
    {
      *(_QWORD *)(result + v11) = *(_QWORD *)(a2 + v11);
      v11 += 8LL;
    }
    while ( v21 != v11 );
    if ( v21 == a3 )
      return result;
    goto LABEL_35;
  }
  v7 = a2;
  v8 = result;
LABEL_8:
  v9 = a3;
LABEL_35:
  v22 = v9 - 1;
  if ( (v9 & 7) != 0 )
  {
    v23 = 0;
    do
    {
      *(_BYTE *)(v8 + v23) = *(_BYTE *)(v7 + v23);
      ++v23;
    }
    while ( (v9 & 7) != v23 );
    v7 += v23;
    v8 += v23;
    v9 -= v23;
  }
  if ( v22 >= 7 )
  {
    v24 = 0;
    do
    {
      *(_BYTE *)(v8 + v24) = *(_BYTE *)(v7 + v24);
      *(_BYTE *)(v8 + v24 + 1) = *(_BYTE *)(v7 + v24 + 1);
      *(_BYTE *)(v8 + v24 + 2) = *(_BYTE *)(v7 + v24 + 2);
      *(_BYTE *)(v8 + v24 + 3) = *(_BYTE *)(v7 + v24 + 3);
      *(_BYTE *)(v8 + v24 + 4) = *(_BYTE *)(v7 + v24 + 4);
      *(_BYTE *)(v8 + v24 + 5) = *(_BYTE *)(v7 + v24 + 5);
      *(_BYTE *)(v8 + v24 + 6) = *(_BYTE *)(v7 + v24 + 6);
      *(_BYTE *)(v8 + v24 + 7) = *(_BYTE *)(v7 + v24 + 7);
      v24 += 8;
    }
    while ( v9 != v24 );
  }
  return result;
}


// ---- sub_140002050 @ 0x140002050 ----
unsigned __int8 *__fastcall sub_140002050(unsigned __int8 *a1, unsigned __int8 a2, unsigned __int64 a3)
{
  sub_140001B90(a1, a2, a3);
  return a1;
}


// ---- sub_140002070 @ 0x140002070 ----
__int64 __fastcall sub_140002070(__int64 a1, char *a2)
{
  __int64 result; // rax
  char v3; // cl

  result = a1 - 1;
  do
  {
    v3 = *a2++;
    *(_BYTE *)++result = v3;
  }
  while ( v3 != 0 );
  return result;
}


// ---- sub_1400020A0 @ 0x1400020a0 ----
__int64 __fastcall sub_1400020A0(__int64 a1, __int64 a2)
{
  __int64 v2; // r8
  int v3; // eax
  char v4; // r9

  v2 = 0;
  do
  {
    v3 = *(char *)(a1 + v2);
    v4 = *(_BYTE *)(a2 + v2);
    if ( *(_BYTE *)(a1 + v2) == 0 )
      break;
    ++v2;
  }
  while ( (_BYTE)v3 == v4 );
  return (unsigned int)(v3 - v4);
}


// ---- start @ 0x1400020d0 ----
void __noreturn start()
{
  __int64 v0; // rdx
  __int64 (__fastcall *v1)(_DWORD *, _QWORD, __int64); // rax
  signed int v2; // ecx
  __int16 v3; // r8
  __int16 v4; // r9
  unsigned int i; // [rsp+2Ch] [rbp-2Ch]
  _DWORD v6[10]; // [rsp+30h] [rbp-28h] BYREF

  qword_14003BA38 = sub_14002F7D0(1121613081);
  qword_14003BA40 = sub_14002F7D0(2191101672LL);
  v6[0] = 0;
  LODWORD(v0) = -308314390;
  do
  {
    ++v6[0];
    v0 = ((v6[0] & 0xB385C982) * (v6[0] & 0x4C7A367D ^ 0x4C7A367D) + (v6[0] & 0x4C7A367D) * (v6[0] | 0x4C7A367D))
       ^ (unsigned int)v0;
  }
  while ( v6[0] == 0 );
  v1 = (__int64 (__fastcall *)(_DWORD *, _QWORD, __int64))sub_14002FDC0(qword_14003BA40, v0);
  qmemcpy(v6, byte_140033378, 30);
  for ( i = 0;
        i < 0xF;
        *((_WORD *)v6 + v2) = (v3 + (i & 0x7A6B) * (i & 0x8594 ^ 0x8594) + (i & 0x8594) * (i | 0x8594) - v4)
                            & (v4 + ~(2 * v4)) )
  {
    v2 = i++;
    v3 = *((_WORD *)v6 + v2);
    v4 = v3 & ((i & 0x7A6B) * (i & 0x8594 ^ 0x8594) + (i & 0x8594) * (i | 0x8594));
  }
  qword_14003BA48 = v1(v6, 0, 2048);
  if ( qword_14003BA48 != 0
    && qword_14003BA38 != 0
    && qword_14003BA40 != 0
    && (unsigned __int8)sub_14002F140() != 0
    && (unsigned __int8)sub_14002BE60() == 0
    && (unsigned __int8)sub_14002A7B0() != 0 )
  {
    sub_140006BA0();
  }
  ExitProcess(0);
}


// ---- sub_140002250 @ 0x140002250 ----
__int64 __fastcall sub_140002250(_DWORD *a1, unsigned __int8 *a2, int a3, unsigned int a4)
{
  __int64 v8; // rax
  unsigned int v9; // ebp
  unsigned __int8 *v10; // rbp
  __int64 v11; // rsi
  char *v12; // r14
  __int64 v13; // rdi
  unsigned __int64 v14; // r13
  unsigned __int8 *v15; // rbx
  char *v16; // rdx
  _DWORD *v17; // rdi
  unsigned int v18; // eax
  unsigned __int64 v19; // rsi
  unsigned __int8 *v20; // rcx
  unsigned __int8 *v21; // r11
  unsigned int v22; // ecx
  _DWORD *v23; // r8
  __int64 v24; // r9
  __int64 v25; // rdx
  _DWORD *v26; // rdx
  __int64 v27; // r11
  unsigned int v28; // r10d
  unsigned __int8 v29; // cl
  unsigned __int64 v30; // r14
  __int64 v31; // rbp
  unsigned int v32; // r8d
  __int64 v33; // r15
  unsigned __int8 v34; // r9
  __int64 v35; // rax
  _DWORD *v36; // r12
  char v37; // bl
  int v38; // ecx
  __int64 v39; // r11
  unsigned __int8 *v40; // r14
  unsigned __int64 v41; // r10
  unsigned __int64 v42; // rbx
  unsigned __int8 *v43; // r9
  _BYTE *v44; // r8
  unsigned __int64 v45; // r8
  __int64 v46; // r8
  unsigned __int8 *v47; // rcx
  _QWORD *v48; // rdx
  unsigned __int64 v49; // rax
  __int64 v50; // r9
  __int64 v51; // rax
  __int128 v52; // xmm1
  unsigned __int64 v53; // r8
  _DWORD *v54; // rax
  _DWORD *v55; // r12
  int v58; // edx
  unsigned __int8 v59; // al
  int v60; // r12d
  unsigned int v61; // edi
  int v62; // eax
  unsigned int v63; // ebp
  unsigned int v64; // ebx
  __int64 v65; // r14
  int v66; // eax
  int v67; // edx
  __int64 v68; // rax
  int v69; // r14d
  int v70; // ebx
  unsigned __int8 *v71; // r12
  unsigned int v72; // eax
  unsigned __int8 *v73; // rcx
  int v74; // r15d
  int v75; // r8d
  unsigned __int64 v76; // rdi
  __int64 v77; // r12
  __int64 v79; // [rsp+30h] [rbp-B8h]
  unsigned __int8 *v80; // [rsp+30h] [rbp-B8h]
  _QWORD *v81; // [rsp+38h] [rbp-B0h]
  unsigned __int64 v82; // [rsp+40h] [rbp-A8h]
  unsigned __int8 *v83; // [rsp+48h] [rbp-A0h]
  _DWORD *v84; // [rsp+50h] [rbp-98h]
  __int64 v85; // [rsp+58h] [rbp-90h] BYREF
  int v86; // [rsp+60h] [rbp-88h]
  unsigned int v87; // [rsp+64h] [rbp-84h]
  unsigned __int8 *v88; // [rsp+68h] [rbp-80h]
  __int64 v89; // [rsp+70h] [rbp-78h]
  _BYTE *v90; // [rsp+78h] [rbp-70h]
  unsigned __int64 v91; // [rsp+80h] [rbp-68h]
  unsigned __int64 v92; // [rsp+88h] [rbp-60h]
  unsigned __int64 v93; // [rsp+90h] [rbp-58h]
  char *v94; // [rsp+98h] [rbp-50h]
  unsigned __int8 *v95; // [rsp+A0h] [rbp-48h]

  v8 = sub_140001B80(0x4000);
  v85 = v8;
  if ( a3 <= 65546 )
  {
    v9 = sub_1400029E0((unsigned int)&v85, (_DWORD)a1, (_DWORD)a2, a3, a4);
    goto LABEL_74;
  }
  v10 = (unsigned __int8 *)v8;
  v88 = a2;
  v86 = a3;
  v11 = (unsigned int)a3;
  v12 = (char *)a1 + (unsigned int)a3;
  v87 = a4;
  v13 = (int)a4;
  if ( v8 == 0 )
  {
    v10 = (unsigned __int8 *)sub_140001B80(0x4000);
    v85 = (__int64)v10;
  }
  v14 = (unsigned __int64)a1 + v11 - 12;
  v15 = v88;
  v82 = (unsigned __int64)&v88[v13];
  sub_140002050(v10, 0, 0x4000u);
  *(_DWORD *)&v10[4 * ((unsigned int)(-1640531535 * *a1) >> 20)] = 0;
  v16 = (char *)a1 + 2;
  v17 = (_DWORD *)((char *)a1 + 1);
  v18 = (*(_DWORD *)((char *)a1 + 1) & 0x9E3779B1 ^ 0x1E3779B1) * (*(_DWORD *)((char *)a1 + 1) & 0x61C8864E)
      + (*(_DWORD *)((char *)a1 + 1) & 0x9E3779B1) * (*(_DWORD *)((char *)a1 + 1) | 0x9E3779B1);
  v93 = (unsigned __int64)(v12 - 5);
  v92 = (unsigned __int64)(v12 - 8);
  v94 = v12;
  v91 = (unsigned __int64)(v12 - 6);
  v19 = (unsigned __int64)a1;
  v20 = v15;
  v84 = a1;
  v83 = v10;
  while ( 2 )
  {
    v21 = v20;
    v81 = (_QWORD *)v19;
    v22 = 68;
    while ( 1 )
    {
      v23 = v16;
      v24 = v18 >> 20;
      v25 = *(unsigned int *)&v10[4 * v24];
      v18 = -1640531535 * *v23;
      *(_DWORD *)&v10[4 * v24] = (_DWORD)v17 - (_DWORD)a1;
      v26 = (_DWORD *)((char *)a1 + v25);
      if ( v26 >= (_DWORD *)((char *)v17 - 0xFFFF) && *v26 == *v17 )
        break;
      v16 = (char *)v23 + (v22 >> 6);
      v17 = v23;
      ++v22;
      if ( (unsigned __int64)v16 > v14 )
        goto LABEL_65;
    }
    v95 = v21;
    v27 = (unsigned int)((_DWORD)v17 - v19);
    v28 = v27 - 15;
    v29 = 16 * (_BYTE)v17 - 16 * v19;
    v30 = 0xFFFFFFFF00000000uLL * v19 + ((_QWORD)v17 << 32);
    v31 = 0;
    do
    {
      v32 = v28;
      v33 = v31;
      v34 = v29;
      v35 = v30;
      v89 = v27;
      v36 = (_DWORD *)((char *)v26 + v31);
      v19 = (unsigned __int64)v17 + v31;
      if ( (_DWORD *)((char *)v26 + v31) <= v84 )
        break;
      if ( v19 <= (unsigned __int64)v81 )
        break;
      v37 = *((_BYTE *)v17 + v31 - 1);
      --v28;
      --v31;
      v29 -= 16;
      v30 -= 0x100000000LL;
      v27 = (unsigned int)(v89 - 1);
    }
    while ( v37 == *((_BYTE *)v26 + v33 - 1) );
    v38 = v33 + (_DWORD)v17 - (_DWORD)v81;
    v39 = v35 >> 32;
    v40 = v95;
    v9 = 0;
    if ( (unsigned __int64)&v95[(v35 >> 32) + 9 + (v38 >> 8)] <= v82 )
    {
      v41 = (unsigned __int64)(v95 + 1);
      if ( v38 < 15 )
      {
        *v95 = v34;
        v10 = v83;
      }
      else
      {
        *v95 = -16;
        v10 = v83;
        if ( (unsigned int)v38 >= 0x10E )
        {
          if ( v32 >= 0x1FD )
            v32 = 509;
          v42 = ((unsigned int)v33 + (_DWORD)v17 - (_DWORD)v81 - v32 + 239) / 0xFFuLL;
          v90 = v40 + 1;
          v79 = v35 >> 32;
          sub_140002050(v40 + 1, 0xFFu, (unsigned int)(v42 + 1));
          v40[v42 + 2] = v42 + v33 + (_BYTE)v17 - (_BYTE)v81 - 14;
          sub_140001C20((__int64)&v40[v42 + 3]);
          v43 = &v40[v42 + 3 + v79];
          a1 = v84;
LABEL_32:
          v53 = v82;
          goto LABEL_38;
        }
        v41 = (unsigned __int64)(v40 + 2);
        v40[1] = (_BYTE)v17 - (_BYTE)v81 + v33 - 15;
      }
      v44 = (_BYTE *)(v41 + 8);
      if ( v41 + v39 > v41 + 8 )
        v44 = (_BYTE *)(v41 + v39);
      v45 = (unsigned __int64)&v44[~v41];
      a1 = v84;
      if ( v45 < 0x18 )
      {
        v47 = (unsigned __int8 *)v41;
        v48 = v81;
      }
      else
      {
        if ( v41 - (unsigned __int64)v81 >= 0x20 )
        {
          v46 = (v45 >> 3) + 1;
          v47 = (unsigned __int8 *)(v41 + 8 * (v46 & 0x3FFFFFFFFFFFFFFCLL));
          v48 = &v81[v46 & 0x3FFFFFFFFFFFFFFCLL];
          v49 = v41 + (int)v89;
          if ( v49 <= v41 + 8 )
            v49 = v41 + 8;
          v50 = (((v49 + ~v41) >> 3) + 1) & 0x3FFFFFFFFFFFFFFCLL;
          v51 = 0;
          do
          {
            v52 = *(_OWORD *)&v81[v51 + 2];
            *(_OWORD *)(v41 + 8 * v51) = *(_OWORD *)&v81[v51];
            *(_OWORD *)(v41 + 8 * v51 + 16) = v52;
            v51 += 4;
          }
          while ( v50 != v51 );
          v43 = (unsigned __int8 *)(v41 + v39);
          if ( v46 == (v46 & 0x3FFFFFFFFFFFFFFCLL) )
            goto LABEL_32;
          goto LABEL_36;
        }
        v47 = (unsigned __int8 *)v41;
        v48 = v81;
      }
      v43 = (unsigned __int8 *)(v41 + v39);
LABEL_36:
      v53 = v82;
      do
      {
        *(_QWORD *)v47 = *v48;
        v47 += 8;
        ++v48;
      }
      while ( v47 < v43 );
      while ( 1 )
      {
LABEL_38:
        *(_WORD *)v43 = v19 - (_WORD)v36;
        v54 = (_DWORD *)(v19 + 4);
        v55 = v36 + 1;
        v19 = (unsigned __int64)v54;
        if ( (unsigned __int64)v54 >= v14 )
        {
LABEL_41:
          if ( v19 < v92 && *v55 == *(_DWORD *)v19 )
          {
            v19 += 4LL;
            ++v55;
          }
          if ( v19 < v91 && *(_WORD *)v55 == *(_WORD *)v19 )
          {
            v19 += 2LL;
            v55 = (_DWORD *)((char *)v55 + 2);
          }
          if ( v19 < v93 )
            v19 += *(_BYTE *)v55 == *(_BYTE *)v19;
        }
        else
        {
          while ( *(_QWORD *)v19 == *(_QWORD *)v55 )
          {
            v19 += 8LL;
            v55 += 2;
            if ( v19 >= v14 )
              goto LABEL_41;
          }
          _RDX = *(_QWORD *)v55 ^ *(_QWORD *)v19;
          __asm { tzcnt   rcx, rdx }
          v19 += (unsigned int)_RCX >> 3;
        }
        v58 = v19 - (_DWORD)v54;
        if ( (unsigned __int64)&v43[(((int)v19 - (int)v54) >> 8) + 8] > v53 )
        {
          v9 = 0;
          goto LABEL_74;
        }
        v20 = v43 + 2;
        v59 = *v40;
        if ( v58 < 15 )
        {
          *v40 = v58 + v59;
          if ( v19 > v14 )
            goto LABEL_64;
        }
        else
        {
          *v40 = v59 + 15;
          v60 = v58 ^ 0xF;
          v61 = (2 * v58) & 0xFFFFFFE0;
          v62 = v61 - (v58 ^ 0xF);
          if ( v62 >= 510 )
          {
            if ( (unsigned int)v62 >= 0x3FB )
              v62 = 1019;
            v63 = v61 - (v60 + v62);
            v64 = (v63 + 509) / 0x1FE;
            v65 = 2 * v64;
            v80 = v43;
            sub_140002050(v20, 0xFFu, v65 + 2);
            v53 = v82;
            v66 = v63 - 510 * v64 + 509;
            v20 = &v80[v65 + 4];
            v67 = v60 + v63 + 509;
            v10 = v83;
            v62 = v61 - v67 + v66 - 510;
          }
          if ( v62 >= 255 )
          {
            LOBYTE(v62) = v62 + 1;
            *v20++ = -1;
          }
          *v20++ = v62;
          if ( v19 > v14 )
            goto LABEL_64;
        }
        *(_DWORD *)&v10[4 * ((unsigned int)(-1640531535 * *(_DWORD *)(v19 - 2)) >> 20)] = v19 - 2 - (_DWORD)a1;
        v68 = (unsigned int)(-1640531535 * *(_DWORD *)v19) >> 20;
        v36 = (_DWORD *)((char *)a1 + *(unsigned int *)&v10[4 * v68]);
        *(_DWORD *)&v10[4 * v68] = v19 - (_DWORD)a1;
        if ( (unsigned __int64)v36 <= v19 - 0x10000 || *v36 != *(_DWORD *)v19 )
          break;
        v43 = v20 + 1;
        *v20 = 0;
        v40 = v20;
      }
      v17 = (_DWORD *)(v19 + 1);
      v18 = -1640531535 * *(_DWORD *)(v19 + 1);
      v16 = (char *)(v19 + 2);
      if ( v19 + 2 <= v14 )
        continue;
LABEL_64:
      v21 = v20;
LABEL_65:
      v69 = (_DWORD)v94 - v19;
      v70 = (int)v88;
      v9 = 0;
      if ( (__int64)((unsigned int)((_DWORD)v94 - v19 + 240) / 0xFFuLL + (int)v94 - (int)v19 + v21 - v88 + 1) <= v87 )
      {
        v71 = v21;
        if ( v69 < 15 )
        {
          *v21 = 16 * v69;
          v77 = (__int64)(v21 + 1);
        }
        else
        {
          *v21 = -16;
          v72 = v69 - 15;
          v73 = v21 + 1;
          if ( (unsigned int)v69 >= 0x10E )
          {
            v74 = v86 + (_DWORD)a1;
            v75 = 509;
            if ( v72 < 0x1FD )
              v75 = v69 - 15;
            v76 = (unsigned int)(v74 - (v19 + v75) + 239) / 0xFFuLL;
            sub_140002050(v73, 0xFFu, v76 + 1);
            v73 = &v71[v76 + 2];
            v71 += v76 + 1;
            LOBYTE(v72) = v74 - v19 + v76 - 14;
          }
          *v73 = v72;
          v77 = (__int64)(v71 + 2);
        }
        sub_140001C20(v77);
        v9 = v69 + v77 - v70;
      }
    }
    break;
  }
LABEL_74:
  sub_140001C10(v85);
  return v9;
}


// ---- sub_1400029E0 @ 0x1400029e0 ----
__int64 __fastcall sub_1400029E0(unsigned __int8 **a1, unsigned __int64 a2, _BYTE *a3, int a4, int a5)
{
  _BYTE *v5; // r15
  __int64 v7; // rdi
  int v8; // r12d
  unsigned __int64 v9; // r8
  unsigned __int64 v10; // r14
  _BYTE *v11; // rsi
  unsigned __int8 *v12; // r15
  unsigned __int64 v14; // rbp
  _DWORD *v15; // r8
  int v16; // ecx
  unsigned int v17; // edx
  _DWORD *v18; // rax
  unsigned int v19; // r10d
  __int64 v20; // r10
  __int64 v21; // r9
  _DWORD *v22; // r9
  int v23; // edx
  _DWORD *v24; // r12
  _DWORD *v25; // rdi
  int v26; // ecx
  int v27; // eax
  int v28; // r15d
  int v29; // ecx
  __int64 v30; // r13
  unsigned __int64 v31; // rsi
  int v32; // r15d
  unsigned int v33; // ecx
  unsigned __int64 v34; // r15
  unsigned __int64 v35; // r13
  unsigned __int64 v36; // r9
  _BYTE *v37; // rax
  unsigned __int64 v38; // rdx
  __int64 v39; // rdx
  __int64 v40; // r8
  _QWORD *v41; // rax
  _QWORD *v42; // rcx
  __int64 v43; // r9
  __int128 v44; // xmm1
  bool v45; // zf
  int v46; // eax
  _DWORD *v47; // rdi
  int v50; // ecx
  char v51; // al
  unsigned int v52; // eax
  int v53; // edi
  unsigned int v54; // r15d
  __int64 v55; // r12
  int v56; // eax
  __int64 v57; // rax
  int v58; // r12d
  __int64 result; // rax
  unsigned int v60; // eax
  unsigned __int8 *v61; // rcx
  int v62; // ebx
  int v63; // edx
  unsigned __int64 v64; // rdi
  __int64 v65; // rsi
  unsigned __int64 v66; // [rsp+30h] [rbp-88h]
  int v67; // [rsp+3Ch] [rbp-7Ch]
  _BYTE *v68; // [rsp+40h] [rbp-78h]
  unsigned __int64 v69; // [rsp+48h] [rbp-70h]
  _BYTE *v70; // [rsp+50h] [rbp-68h]
  unsigned __int8 *v71; // [rsp+58h] [rbp-60h]
  char v72; // [rsp+60h] [rbp-58h]

  v5 = a3;
  v7 = a4;
  v8 = a2 + a4;
  v9 = (unsigned __int64)&a3[a5];
  LODWORD(v10) = a2;
  v11 = v5;
  if ( a4 < 13 )
  {
LABEL_57:
    v58 = v8 - v10;
    result = 0;
    if ( (unsigned __int64)&v11[v58 + 1 + (unsigned int)(v58 + 240) / 0xFFuLL] <= v9 )
    {
      if ( v58 < 15 )
      {
        *v11 = 16 * v58;
        v65 = (__int64)(v11 + 1);
      }
      else
      {
        v60 = v58 - 15;
        *v11 = -16;
        v61 = v11 + 1;
        if ( (unsigned int)(v58 - 15) >= 0xFF )
        {
          v62 = a4 + a2;
          v63 = 509;
          if ( v60 < 0x1FD )
            v63 = v58 - 15;
          v64 = (unsigned int)(v62 - (v10 + v63) + 239) / 0xFFuLL;
          sub_140002050(v61, 0xFFu, v64 + 1);
          v61 = &v11[v64 + 2];
          v11 += v64 + 1;
          LOBYTE(v60) = v62 - v10 + v64 - 14;
        }
        *v61 = v60;
        v65 = (__int64)(v11 + 2);
      }
      sub_140001C20(v65);
      return 2 * ((v58 + (_DWORD)v65) & ~(_DWORD)v5) - ((unsigned int)v5 ^ (v58 + (_DWORD)v65));
    }
    return result;
  }
  v66 = v9;
  v67 = a4;
  v69 = a2 + a4;
  v70 = v5;
  v12 = *a1;
  if ( *a1 == nullptr )
  {
    v12 = (unsigned __int8 *)sub_140001B80(0x4000);
    *a1 = v12;
  }
  v14 = a2 + v7 - 12;
  sub_140002050(v12, 0, 0x4000u);
  v11 = v70;
  v10 = a2;
LABEL_5:
  v15 = (_DWORD *)(v10 + 1);
  v16 = *(_DWORD *)(v10 + 1);
  v17 = 67;
  do
  {
    v18 = v15;
    v15 = (_DWORD *)((char *)v15 + (v17 >> 6));
    if ( (unsigned __int64)v15 > v14 )
    {
      LODWORD(v5) = (_DWORD)v70;
      v8 = v69;
      a4 = v67;
      v9 = v66;
      goto LABEL_57;
    }
    ++v17;
    v19 = -1640531535 * v16;
    v16 = *v15;
    v20 = v19 >> 19;
    v21 = *(unsigned __int16 *)&v12[2 * v20];
    *(_WORD *)&v12[2 * v20] = (_WORD)v18 - a2;
  }
  while ( *(_DWORD *)(a2 + v21) != *v18 );
  v68 = v11;
  v71 = v12;
  v22 = (_DWORD *)(a2 + v21);
  v23 = (int)v18;
  do
  {
    v24 = v18;
    v25 = v22;
    v26 = v23;
    if ( (unsigned __int64)v22 <= a2 )
      break;
    if ( (unsigned __int64)v18 <= v10 )
      break;
    v18 = (_DWORD *)((char *)v18 - 1);
    v22 = (_DWORD *)((char *)v22 - 1);
    --v23;
  }
  while ( *((_BYTE *)v24 - 1) == *((_BYTE *)v25 - 1) );
  v27 = v10 ^ v26;
  v28 = v26 & ~(_DWORD)v10;
  v29 = 2 * v28 - (v10 ^ v26);
  v30 = v29;
  v9 = v66;
  if ( (unsigned __int64)&v11[v29 + 9 + (v29 >> 8)] > v66 )
    return 0;
  v31 = (unsigned __int64)(v11 + 1);
  if ( v29 < 15 )
  {
    *v68 = 16 * v29;
    goto LABEL_20;
  }
  *v68 = -16;
  if ( (unsigned int)v29 < 0x10E )
  {
    v31 = (unsigned __int64)(v68 + 2);
    v68[1] = v29 - 15;
LABEL_20:
    v36 = v69 - 5;
    v35 = v31 + v29;
    v37 = (_BYTE *)(v31 + 8);
    if ( v35 > v31 + 8 )
      v37 = (_BYTE *)(v31 + v29);
    v38 = (unsigned __int64)&v37[~v31];
    v12 = v71;
    if ( v38 < 0x18 || v31 - v10 < 0x20 )
    {
      v41 = (_QWORD *)v31;
      v42 = (_QWORD *)v10;
    }
    else
    {
      v39 = (v38 >> 3) + 1;
      v40 = v39 & 0x3FFFFFFFFFFFFFFCLL;
      v41 = (_QWORD *)(v31 + 8 * (v39 & 0x3FFFFFFFFFFFFFFCLL));
      v42 = (_QWORD *)(v10 + 8 * (v39 & 0x3FFFFFFFFFFFFFFCLL));
      v43 = 0;
      do
      {
        v44 = *(_OWORD *)(v10 + 8 * v43 + 16);
        *(_OWORD *)(v31 + 8 * v43) = *(_OWORD *)(v10 + 8 * v43);
        *(_OWORD *)(v31 + 8 * v43 + 16) = v44;
        v43 += 4;
      }
      while ( v40 != v43 );
      v45 = v39 == v40;
      v9 = v66;
      v36 = v69 - 5;
      if ( v45 )
        goto LABEL_32;
    }
    do
      *v41++ = *v42++;
    while ( (unsigned __int64)v41 < v35 );
    goto LABEL_32;
  }
  v32 = 2 * v28;
  v72 = v32 - v27;
  v33 = v32 - v27 - 270;
  if ( v33 >= 0xFE )
    v33 = 254;
  v34 = (v32 - (v27 + v33) - 16) / 0xFFuLL;
  sub_140002050(v68 + 1, 0xFFu, v34 + 1);
  v68[v34 + 2] = v34 + v72 - 14;
  sub_140001C20(v31 + v34 + 2);
  v9 = v66;
  v35 = v34 + v31 + v30 + 2;
  v12 = v71;
  v36 = v69 - 5;
  while ( 1 )
  {
LABEL_32:
    *(_WORD *)v35 = (_WORD)v24 - (_WORD)v25;
    v46 = (_DWORD)v24 + 4;
    v47 = v25 + 1;
    v10 = (unsigned __int64)(v24 + 1);
    if ( (unsigned __int64)(v24 + 1) >= v14 )
    {
LABEL_35:
      if ( v10 < v69 - 8 && *v47 == *(_DWORD *)v10 )
      {
        v10 += 4LL;
        ++v47;
      }
      if ( v10 < v69 - 6 && *(_WORD *)v47 == *(_WORD *)v10 )
      {
        v10 += 2LL;
        v47 = (_DWORD *)((char *)v47 + 2);
      }
      if ( v10 < v36 )
        v10 += *(_BYTE *)v47 == *(_BYTE *)v10;
    }
    else
    {
      while ( *(_QWORD *)v47 == *(_QWORD *)v10 )
      {
        v10 += 8LL;
        v47 += 2;
        if ( v10 >= v14 )
          goto LABEL_35;
      }
      _RDX = *(_QWORD *)v47 ^ *(_QWORD *)v10;
      __asm { tzcnt   rcx, rdx }
      v10 += (unsigned int)_RCX >> 3;
    }
    v50 = v10 - v46;
    if ( v35 + (((int)v10 - v46) >> 8) + 8 > v9 )
      return 0;
    v11 = (_BYTE *)(v35 + 2);
    v51 = *v68;
    if ( v50 < 15 )
    {
      *v68 = v50 + v51;
      if ( v10 > v14 )
        goto LABEL_56;
    }
    else
    {
      *v68 = v51 + 15;
      v52 = v50 - 15;
      if ( (unsigned int)(v50 - 15) >= 0x1FE )
      {
        v53 = v10 - (_DWORD)v24;
        v54 = ((int)v10 - (int)v24 - 529) / 0x1FEu;
        v55 = 2 * v54;
        sub_140002050((unsigned __int8 *)(v35 + 2), 0xFFu, v55 + 2);
        v36 = v69 - 5;
        v9 = v66;
        v56 = -510 * v54;
        v12 = v71;
        v52 = v53 + v56 - 529;
        v11 = (_BYTE *)(v55 + v35 + 4);
      }
      if ( v52 >= 0xFF )
      {
        LOBYTE(v52) = v52 + 1;
        *v11++ = -1;
      }
      *v11++ = v52;
      if ( v10 > v14 )
      {
LABEL_56:
        LODWORD(v5) = (_DWORD)v70;
        v8 = v69;
        a4 = v67;
        goto LABEL_57;
      }
    }
    *(_WORD *)&v12[2 * ((unsigned int)(-1640531535 * *(_DWORD *)(v10 - 2)) >> 19)] = v10 - 2 - a2;
    v57 = (unsigned int)(-1640531535 * *(_DWORD *)v10) >> 19;
    v25 = (_DWORD *)(a2 + *(unsigned __int16 *)&v12[2 * v57]);
    *(_WORD *)&v12[2 * v57] = v10 - a2;
    if ( *v25 != *(_DWORD *)v10 )
      goto LABEL_5;
    v35 = (unsigned __int64)(v11 + 1);
    *v11 = 0;
    v68 = v11;
    v24 = (_DWORD *)v10;
  }
}


// ---- sub_140002F90 @ 0x140002f90 ----
__int64 __fastcall sub_140002F90(__int64 a1, char a2)
{
  __int64 v3; // rdi
  __int64 v4; // rbx
  unsigned int v5; // eax
  unsigned int v6; // ecx

  *(_BYTE *)a1 = a2;
  *(_QWORD *)(a1 + 56) = 0;
  *(_OWORD *)(a1 + 8) = 0;
  v3 = (unsigned int)sub_140003050(qword_14003BA50) % 0xC + 8;
  v4 = 0;
  do
  {
    while ( 1 )
    {
      v5 = sub_140003050(qword_14003BA50);
      v6 = v5 % 0x24;
      if ( v5 % 0x24 >= 0xA )
        break;
      *(_BYTE *)(a1 + v4++ + 24) = v6 | 0x30;
      if ( v3 == v4 )
        goto LABEL_5;
    }
    *(_BYTE *)(a1 + v4++ + 24) = 32 * ((v5 & 1) == 0) + v6 + 55;
  }
  while ( v3 != v4 );
LABEL_5:
  *(_BYTE *)(a1 + v4 + 24) = 0;
  return a1;
}


// ---- sub_140003050 @ 0x140003050 ----
__int64 __fastcall sub_140003050(unsigned int *a1)
{
  unsigned int v1; // eax
  unsigned __int64 i; // rax
  __m128i v3; // xmm3
  __int64 v4; // rax
  __m128i si128; // xmm2
  __m128 v6; // xmm4
  __m128i v7; // xmm5
  __m128i v8; // xmm8
  __m128i v9; // xmm4
  unsigned int v10; // r8d
  unsigned int v11; // eax
  unsigned int v12; // edx
  __m128 v13; // xmm3
  __int64 j; // rax
  __m128 v15; // xmm4
  __m128i v16; // xmm5
  unsigned int v17; // eax
  unsigned int v18; // ecx

  v1 = *a1;
  if ( *a1 == 624 )
  {
    for ( i = 624; i < 0x4E0; i = (i ^ 1) + 2 * (i & 1) )
      a1[i + 1] = ((a1[i - 623] & 0x80000000 | a1[i - 622] & 0x7FFFFFFE) >> 1)
                ^ a1[i - 226]
                ^ -(a1[i - 622] & 1)
                & 0x9908B0DF;
    v1 = 624;
  }
  else if ( v1 >= 0x4E0 )
  {
    v3 = _mm_shuffle_epi32(_mm_cvtsi32_si128(a1[625]), 0);
    v4 = 0;
    si128 = _mm_load_si128((const __m128i *)&xmmword_1400334E0);
    do
    {
      v6 = *(__m128 *)&a1[v4 + 626];
      v7 = (__m128i)_mm_or_ps(
                      _mm_and_ps(v6, (__m128)xmmword_1400334D0),
                      _mm_and_ps(_mm_shuffle_ps(_mm_shuffle_ps((__m128)v3, v6, 3), v6, 152), (__m128)xmmword_1400334C0));
      v3 = *(__m128i *)&a1[v4 + 630];
      v8 = _mm_xor_si128(
             _mm_xor_si128(
               _mm_loadu_si128((const __m128i *)&a1[v4 + 1022]),
               _mm_and_si128(_mm_srai_epi32(_mm_slli_epi32((__m128i)v6, 0x1Fu), 0x1Fu), si128)),
             _mm_srli_epi32(v7, 1u));
      v9 = _mm_xor_si128(
             _mm_xor_si128(
               _mm_loadu_si128((const __m128i *)&a1[v4 + 1026]),
               _mm_and_si128(_mm_srai_epi32(_mm_slli_epi32(v3, 0x1Fu), 0x1Fu), si128)),
             _mm_srli_epi32(
               (__m128i)_mm_or_ps(
                          _mm_and_ps((__m128)v3, (__m128)xmmword_1400334D0),
                          _mm_and_ps(
                            _mm_shuffle_ps(_mm_shuffle_ps(v6, (__m128)v3, 3), (__m128)v3, 152),
                            (__m128)xmmword_1400334C0)),
               1u));
      *(__m128i *)&a1[v4 + 1] = v8;
      *(__m128i *)&a1[v4 + 5] = v9;
      v4 += 8;
    }
    while ( v4 != 224 );
    v10 = a1[850];
    v11 = a1[851];
    a1[225] = ((_mm_cvtsi128_si32(_mm_shuffle_epi32(v3, 255)) & 0x80000000 | v10 & 0x7FFFFFFE) >> 1)
            ^ a1[1246]
            ^ -(v10 & 1)
            & 0x9908B0DF;
    a1[226] = ((v10 & 0x80000000 | v11 & 0x7FFFFFFE) >> 1) ^ a1[1247] ^ -(v11 & 1) & 0x9908B0DF;
    v12 = a1[852];
    a1[227] = ((v11 & 0x80000000 | v12 & 0x7FFFFFFE) >> 1) ^ a1[1248] ^ -(v12 & 1) & 0x9908B0DF;
    v13 = (__m128)_mm_shuffle_epi32(_mm_cvtsi32_si128(v12), 0);
    for ( j = 0; j != 396; j += 4 )
    {
      v15 = *(__m128 *)&a1[j + 853];
      v16 = _mm_srli_epi32(
              (__m128i)_mm_or_ps(
                         _mm_and_ps(v15, (__m128)xmmword_1400334D0),
                         _mm_and_ps(_mm_shuffle_ps(_mm_shuffle_ps(v13, v15, 3), v15, 152), (__m128)xmmword_1400334C0)),
              1u);
      v13 = v15;
      *(__m128i *)&a1[j + 228] = _mm_xor_si128(
                                   _mm_xor_si128(
                                     _mm_loadu_si128((const __m128i *)&a1[j + 1]),
                                     _mm_and_si128(_mm_srai_epi32(_mm_slli_epi32((__m128i)v15, 0x1Fu), 0x1Fu), si128)),
                                   v16);
    }
    a1[624] = ((a1[1248] & 0x80000000 | a1[1] & 0x7FFFFFFE) >> 1) ^ a1[397] ^ -(a1[1] & 1) & 0x9908B0DF;
    v1 = 0;
  }
  *a1 = v1 + 1;
  v17 = a1[v1 + 1];
  v18 = v17
      ^ (v17 >> 11)
      ^ ((~((v17 ^ (v17 >> 11)) << 7) | 0x9D2C5680) + ((v17 ^ (v17 >> 11)) << 7) + 1)
      ^ ((v17 ^ (v17 >> 11) ^ ((~((v17 ^ (v17 >> 11)) << 7) | 0x9D2C5680) + ((v17 ^ (v17 >> 11)) << 7) + 1)) << 15)
      & 0xEFC60000;
  return v18 ^ (v18 >> 18);
}


// ---- sub_140003370 @ 0x140003370 ----
__int64 __fastcall sub_140003370(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
{
  unsigned int v4; // esi
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // r15
  __int64 v12; // rax
  _WORD *v13; // r13
  _DWORD *v14; // rax

  LOBYTE(v4) = 1;
  if ( a4 != 0 )
  {
    v8 = a4 + 6;
    v9 = 0;
    do
      ++v8;
    while ( *(_BYTE *)(a2 + v9++) != 0 );
    v12 = sub_14002E100(*(_QWORD *)(a1 + 8), *(_QWORD *)(a1 + 16) + v8);
    *(_QWORD *)(a1 + 8) = v12;
    if ( v12 != 0 )
    {
      v13 = (_WORD *)(v12 + *(_QWORD *)(a1 + 16));
      *v13 = v9;
      v14 = (_DWORD *)sub_140001C40((__int64)(v13 + 1), a2, v9);
      *v14 = a4;
      *(_QWORD *)(a1 + 16) += sub_140001C40((__int64)(v14 + 1), a3, a4) - (_QWORD)v13;
    }
    else
    {
      return 0;
    }
  }
  return v4;
}


// ---- sub_140003420 @ 0x140003420 ----
__int64 __fastcall sub_140003420(__int64 a1, __int64 a2, char *a3, __int64 a4)
{
  __int64 v4; // rdx
  int v5; // eax
  int v6; // eax
  signed int v7; // eax
  __int64 v8; // rax
  char v9; // r10
  char *v10; // r10
  __int64 v11; // rax
  char v12; // r11
  char v13; // r11
  _BYTE *v14; // rdx
  char *v15; // r10
  char v16; // r11
  char v17; // r10
  _BYTE *v18; // r8
  int *v19; // r11
  __int64 v20; // r10
  char v21; // bl
  __int64 result; // rax
  char v23; // dl
  __int64 v24; // rdx
  char v25; // r11
  unsigned int i; // [rsp+Ch] [rbp-5Ch]
  unsigned int v27; // [rsp+Ch] [rbp-5Ch]
  __int16 v28; // [rsp+10h] [rbp-58h]
  char v29; // [rsp+12h] [rbp-56h]
  _WORD v30[2]; // [rsp+14h] [rbp-54h] BYREF
  int v31; // [rsp+18h] [rbp-50h] BYREF
  __int16 v32; // [rsp+1Ch] [rbp-4Ch]
  _QWORD v33[2]; // [rsp+20h] [rbp-48h] BYREF
  _BYTE v34[56]; // [rsp+30h] [rbp-38h]

  v4 = *(_QWORD *)(a1 + 56) + a2;
  qmemcpy(v30, ")Bl", 3);
  LODWORD(v33[0]) = 0;
  do
  {
    v5 = LODWORD(v33[0])++;
    *((_BYTE *)v30 + v5) ^= 36 * LOBYTE(v33[0]);
  }
  while ( LODWORD(v33[0]) < 3 );
  v32 = 24307;
  v31 = -1725577401;
  LODWORD(v33[0]) = 0;
  do
  {
    v6 = LODWORD(v33[0])++;
    *((_BYTE *)&v31 + v6) ^= 101 * LOBYTE(v33[0]);
  }
  while ( LODWORD(v33[0]) < 6 );
  qmemcpy(v34, byte_1400333AF, 25);
  *(_OWORD *)v33 = xmmword_14003339F;
  for ( i = 0; i < 0x29; *((_BYTE *)v33 + v7) ^= (i & 0xD3) * (i & 0x2C ^ 0x2C) + (i & 0x2C) * (i | 0x2C) )
    v7 = i++;
  v29 = 71;
  v28 = -2240;
  v27 = 0;
  do
  {
    v8 = (int)v27++;
    v9 = (v27 & 0x92) * (v27 & 0x6D ^ 0x6D) + (v27 & 0x6D) * (v27 | 0x6D);
    *((_BYTE *)&v28 + v8) = (*((_BYTE *)&v28 + v8) | v9)
                          & (-2 - (*((_BYTE *)&v28 + v8) + (v9 | ~*((_BYTE *)&v28 + v8))));
  }
  while ( v27 < 3 );
  v10 = (char *)(a1 + 24);
  v11 = -6;
  do
  {
    v12 = *((_BYTE *)&v30[1] + v11);
    *(_BYTE *)(v4 + v11++ + 6) = v12;
  }
  while ( v12 != 0 );
  do
  {
    v13 = *v10++;
    *(_BYTE *)(v4 + v11++ + 5) = v13;
  }
  while ( v13 != 0 );
  v14 = (_BYTE *)(v11 + v4 + 2);
  v15 = (char *)v33;
  do
  {
    v16 = *v15++;
    v14[2] = v16;
    ++v14;
    ++v11;
  }
  while ( v16 != 0 );
  do
  {
    v17 = *a3++;
    *++v14 = v17;
    ++v11;
  }
  while ( v17 != 0 );
  v18 = v14 + 4;
  v19 = &v31;
  do
  {
    v20 = v11;
    v21 = *(_BYTE *)v19;
    v19 = (int *)((char *)v19 + 1);
    *v14++ = v21;
    ++v18;
    ++v11;
  }
  while ( v21 != 0 );
  result = 0;
  do
  {
    v23 = *(_BYTE *)(a4 + result);
    v18[result++ - 5] = v23;
    ++v20;
  }
  while ( v23 != 0 );
  v24 = 0;
  do
  {
    v25 = *((_BYTE *)v30 + v24);
    v18[v24++ - 6 + result] = v25;
    ++v20;
  }
  while ( v25 != 0 );
  *(_QWORD *)(a1 + 56) += v20;
  return result;
}


// ---- sub_1400036C0 @ 0x1400036c0 ----
_BYTE *__fastcall sub_1400036C0(__int64 a1, __int64 a2, char *a3, __int64 a4, unsigned __int64 a5)
{
  __int64 v7; // rbx
  int v8; // eax
  signed int v9; // eax
  signed int v10; // eax
  __int64 v11; // r14
  _BYTE *v12; // rcx
  __int16 *v13; // rdx
  char v14; // r10
  char *v15; // rdx
  char v16; // r10
  __m256 *v17; // rdx
  char v18; // r10
  char v19; // dl
  char *v20; // rdx
  char v21; // r8
  _BYTE *result; // rax
  int v23; // ecx
  signed int v24; // ecx
  __int64 v25; // r8
  char *v26; // rdx
  __int64 v27; // rcx
  char v28; // r9
  __int64 v29; // rdx
  char v30; // r8
  __int64 v31; // r8
  char v32; // r10
  unsigned int i; // [rsp+28h] [rbp-A0h]
  unsigned int j; // [rsp+28h] [rbp-A0h]
  unsigned int k; // [rsp+28h] [rbp-A0h]
  __int16 v36; // [rsp+2Ch] [rbp-9Ch] BYREF
  char v37; // [rsp+2Eh] [rbp-9Ah]
  _QWORD v38[2]; // [rsp+30h] [rbp-98h] BYREF
  _WORD v39[16]; // [rsp+40h] [rbp-88h]
  __m256 v40; // [rsp+60h] [rbp-68h] BYREF
  _WORD v41[36]; // [rsp+80h] [rbp-48h]

  v7 = *(_QWORD *)(a1 + 56);
  qmemcpy(v39, byte_1400333DB, 30);
  *(_OWORD *)v38 = xmmword_1400333CB;
  v40.m256_f32[0] = 0.0;
  do
  {
    v8 = LODWORD(v40.m256_f32[0])++;
    *((_BYTE *)v38 + v8) ^= (LOBYTE(v40.m256_f32[0]) & 0xAA) * (LOBYTE(v40.m256_f32[0]) & 0x55 ^ 0x55)
                          + (LOBYTE(v40.m256_f32[0]) & 0x55) * (LOBYTE(v40.m256_f32[0]) | 0x55);
  }
  while ( LODWORD(v40.m256_f32[0]) < 0x2E );
  qmemcpy(v41, byte_140033419, 26);
  v40 = ymmword_1400333F9;
  for ( i = 0; i < 0x3A; *((_BYTE *)v40.m256_f32 + v9) ^= 24 * (_BYTE)i )
    v9 = i++;
  v37 = 23;
  v36 = -26768;
  for ( j = 0; j < 3; *((_BYTE *)&v36 + v10) ^= (j & 0xA2) * (j & 0x5D ^ 0x5D) + (j & 0x5D) * (j | 0x5D) )
    v10 = j++;
  v11 = a1 + 24;
  v12 = (_BYTE *)(v7 + a2 - 5);
  v13 = &v36;
  do
  {
    v14 = *(_BYTE *)v13;
    v13 = (__int16 *)((char *)v13 + 1);
    v12[5] = v14;
    ++v12;
  }
  while ( v14 != 0 );
  v15 = (char *)(a1 + 24);
  do
  {
    v16 = *v15++;
    v12[4] = v16;
    ++v12;
  }
  while ( v16 != 0 );
  v17 = &v40;
  do
  {
    v18 = LOBYTE(v17->m256_f32[0]);
    v17 = (__m256 *)((char *)v17 + 1);
    v12[3] = v18;
    ++v12;
  }
  while ( v18 != 0 );
  do
  {
    v19 = *a3++;
    v12[2] = v19;
    ++v12;
  }
  while ( v19 != 0 );
  v20 = (char *)v38;
  do
  {
    v21 = *v20++;
    *++v12 = v21;
  }
  while ( v21 != 0 );
  result = (_BYTE *)sub_140001C40((__int64)v12, a4, a5);
  LOBYTE(v40.m256_f32[1]) = 109;
  v40.m256_f32[0] = 9.7655911e-11;
  LODWORD(v38[0]) = 0;
  do
  {
    v23 = LODWORD(v38[0])++;
    *((_BYTE *)v40.m256_f32 + v23) ^= (v38[0] & 0xB6) * (v38[0] & 0x49 ^ 0x49)
                                    + (v38[0] & 0x49) * (LOBYTE(v38[0]) | 0x49);
  }
  while ( LODWORD(v38[0]) < 5 );
  BYTE4(v38[0]) = 80;
  LODWORD(v38[0]) = 1830627869;
  for ( k = 0; k < 5; *((_BYTE *)v38 + v24) ^= (k & 0x10 ^ 0x10) * (k & 0xEF) + (k & 0x10) * (k | 0x10) )
    v24 = k++;
  v25 = (__int64)&result[-a2 - v7 - 2];
  v26 = (char *)v38;
  do
  {
    v27 = v25;
    v28 = *v26++;
    *result++ = v28;
    ++v25;
  }
  while ( v28 != 0 );
  v29 = 0;
  do
  {
    v30 = *(_BYTE *)(v11 + v29);
    result[v29++ - 1] = v30;
    ++v27;
  }
  while ( v30 != 0 );
  v31 = 0;
  do
  {
    v32 = *((_BYTE *)v40.m256_f32 + v31);
    result[v31++ - 2 + v29] = v32;
    ++v27;
  }
  while ( v32 != 0 );
  *(_QWORD *)(a1 + 56) += v27;
  return result;
}


// ---- sub_140003A40 @ 0x140003a40 ----
__int64 __fastcall sub_140003A40(__int64 a1)
{
  unsigned int v1; // edi
  _DWORD *v2; // rbx
  unsigned __int64 v4; // r14
  _QWORD *v5; // r15
  unsigned __int8 *v6; // rdi
  unsigned int v7; // ebx
  __int64 v8; // r14
  __int64 v9; // rax
  int v10; // eax
  unsigned __int64 v11; // rbx
  int v12; // eax
  int v13; // eax
  __int64 v14; // rax
  __int16 v15; // cx
  char v16; // cl
  _WORD *v17; // rax
  char *v18; // rdx
  _BYTE v20[2]; // [rsp+2Eh] [rbp-1CAh] BYREF
  _DWORD v21[8]; // [rsp+30h] [rbp-1C8h] BYREF
  _DWORD v22[4]; // [rsp+50h] [rbp-1A8h] BYREF
  __m512 v23; // [rsp+60h] [rbp-198h]
  _WORD v24[16]; // [rsp+A0h] [rbp-158h] BYREF
  _BYTE v25[182]; // [rsp+C0h] [rbp-138h] BYREF
  _BYTE v26[120]; // [rsp+180h] [rbp-78h] BYREF

  v2 = *(_DWORD **)(a1 + 8);
  LOBYTE(v1) = 1;
  if ( v2 != nullptr )
  {
    v4 = *(_QWORD *)(a1 + 16);
    if ( v4 != 0 )
    {
      v5 = (_QWORD *)(a1 + 8);
      v6 = (unsigned __int8 *)sub_14002E070((unsigned int)(v4 / 0xFF) + (unsigned int)v4 + 56);
      v7 = sub_140002250(v2, v6, v4, (unsigned int)(v4 / 0xFF) + (unsigned int)v4 + 16);
      sub_14002E0B0(*v5);
      *(_OWORD *)v5 = 0;
      if ( v7 != 0 )
      {
        v21[0] = sub_140003050((unsigned int *)qword_14003BA50);
        v21[1] = sub_140003050((unsigned int *)qword_14003BA50);
        v21[2] = sub_140003050((unsigned int *)qword_14003BA50);
        v21[3] = sub_140003050((unsigned int *)qword_14003BA50);
        v21[4] = sub_140003050((unsigned int *)qword_14003BA50);
        v21[5] = sub_140003050((unsigned int *)qword_14003BA50);
        v21[6] = sub_140003050((unsigned int *)qword_14003BA50);
        v21[7] = sub_140003050((unsigned int *)qword_14003BA50);
        v22[0] = sub_140003050((unsigned int *)qword_14003BA50);
        v22[1] = sub_140003050((unsigned int *)qword_14003BA50);
        sub_140003ED0(v26, v21, v22, 0);
        sub_140004060(v26, v6, v6, v7);
        sub_140001C40((__int64)&v6[v7], (__int64)v21, 0x28u);
        v20[0] = (*(_BYTE *)a1 - 5 * ((*(_BYTE *)a1 / 5u) & 0xFE)) | 0x30;
        v20[1] = 0;
        v8 = sub_14002E070(v7 + 512);
        *(_QWORD *)&v25[5] = 0x680E3D3B27346743LL;
        *(_QWORD *)v25 = 0x3467435B457B7369LL;
        v23.m512_f32[0] = 0.0;
        do
        {
          v9 = SLODWORD(v23.m512_f32[0]);
          ++LODWORD(v23.m512_f32[0]);
          v25[v9] ^= 8 * LOBYTE(v23.m512_f32[0]);
        }
        while ( LODWORD(v23.m512_f32[0]) < 0xD );
        sub_140003420(a1, v8, v25, (__int64)&byte_14003BA60);
        v25[4] = 69;
        *(_DWORD *)v25 = 1639185205;
        v23.m512_f32[0] = 0.0;
        do
        {
          v10 = LODWORD(v23.m512_f32[0])++;
          v25[v10] ^= 65 * LOBYTE(v23.m512_f32[0]);
        }
        while ( LODWORD(v23.m512_f32[0]) < 5 );
        sub_140003420(a1, v8, v25, (__int64)v20);
        v11 = v7 + 40;
        v25[4] = 118;
        *(_DWORD *)v25 = -1727095526;
        v23.m512_f32[0] = 0.0;
        do
        {
          v12 = LODWORD(v23.m512_f32[0])++;
          v25[v12] ^= (LOBYTE(v23.m512_f32[0]) & 0x7E ^ 0x7E) * (LOBYTE(v23.m512_f32[0]) & 0x81)
                    + (LOBYTE(v23.m512_f32[0]) & 0x7E) * (LOBYTE(v23.m512_f32[0]) | 0x7E);
        }
        while ( LODWORD(v23.m512_f32[0]) < 5 );
        sub_1400036C0(a1, v8, v25, (__int64)v6, v11);
        sub_140001C10(v6);
        qmemcpy(v24, byte_140033498, 26);
        v23 = zmmword_140033458;
        *(_DWORD *)v25 = 0;
        do
        {
          v13 = (*(_DWORD *)v25)++;
          *((_WORD *)v23.m512_f32 + v13) ^= (*(_WORD *)v25 & 0x134E) * (*(_WORD *)v25 & 0xECB1 ^ 0xECB1)
                                          + (*(_WORD *)v25 & 0xECB1) * (*(_WORD *)v25 | 0xECB1);
        }
        while ( *(_DWORD *)v25 < 0x2Du );
        v14 = 0;
        do
        {
          v15 = *(_WORD *)((char *)v23.m512_f32 + v14 * 2);
          *(_WORD *)&v25[v14 * 2] = v15;
          ++v14;
        }
        while ( v15 != 0 );
        v16 = *(_BYTE *)(a1 + 24);
        v17 = &v24[v14 + 15];
        if ( v16 != 0 )
        {
          v18 = (char *)(a1 + 25);
          do
          {
            *v17++ = v16;
            v16 = *v18++;
          }
          while ( v16 != 0 );
        }
        *(_DWORD *)v17 = 655373;
        v17[2] = 0;
        v1 = sub_1400056B0((unsigned int)v25, v8, *(_QWORD *)(a1 + 56), 0, 0);
        sub_140001C10(v8);
        *(_QWORD *)(a1 + 56) = 0;
      }
      else
      {
        sub_140001C10(v6);
        return 0;
      }
    }
  }
  return v1;
}


// ---- sub_140003ED0 @ 0x140003ed0 ----
__int64 __fastcall sub_140003ED0(__int64 a1, _QWORD *a2, _DWORD *a3, __int64 a4)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  __int64 result; // rax
  int v9; // [rsp+0h] [rbp-Ch]
  int v10; // [rsp+0h] [rbp-Ch]
  int v11; // [rsp+0h] [rbp-Ch]
  int v12; // [rsp+0h] [rbp-Ch]

  v9 = 0;
  v4 = 2134838774;
  do
  {
    ++v9;
    v4 ^= 508523923 * v9;
  }
  while ( v9 == 0 );
  *(_DWORD *)a1 = v4;
  v10 = 0;
  v5 = 262572840;
  do
  {
    ++v10;
    v5 ^= 1015476038 * v10;
  }
  while ( v10 == 0 );
  *(_DWORD *)(a1 + 4) = v5;
  v11 = 0;
  v6 = 601638343;
  do
  {
    ++v11;
    v6 ^= (v11 & 0xA541970A) * (v11 & 0x5ABE68F5 ^ 0x5ABE68F5) + (v11 & 0x5ABE68F5) * (v11 | 0x5ABE68F5);
  }
  while ( v11 == 0 );
  *(_DWORD *)(a1 + 8) = v6;
  v12 = 0;
  v7 = 332761052;
  do
  {
    ++v12;
    v7 ^= (v12 & 0x78F5E2A8 ^ 0x78F5E2A8) * (v12 & 0x870A1D57) + (v12 & 0x78F5E2A8) * (v12 | 0x18F5E2A8);
  }
  while ( v12 == 0 );
  *(_DWORD *)(a1 + 12) = v7;
  *(_QWORD *)(a1 + 16) = *a2;
  *(_QWORD *)(a1 + 24) = a2[1];
  *(_QWORD *)(a1 + 32) = a2[2];
  *(_QWORD *)(a1 + 40) = a2[3];
  *(_QWORD *)(a1 + 48) = a4;
  *(_DWORD *)(a1 + 56) = *a3;
  result = (unsigned int)a3[1];
  *(_DWORD *)(a1 + 60) = result;
  return result;
}


// ---- sub_140004060 @ 0x140004060 ----
void __fastcall sub_140004060(__int64 a1, _OWORD *a2, _OWORD *a3, unsigned __int64 a4)
{
  unsigned __int64 v4; // rsi
  char *v7; // r10
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rdx
  int v11; // r11d
  int v12; // esi
  int v13; // r15d
  int v14; // eax
  int v15; // r8d
  int v16; // ebx
  int v17; // r13d
  int v18; // edx
  int v19; // r9d
  int v20; // edi
  int v21; // r12d
  int v22; // r10d
  int v23; // ebp
  int v24; // r14d
  int v25; // esi
  int v26; // eax
  int v27; // r8d
  int v28; // r11d
  int v29; // esi
  int v30; // eax
  int v31; // r8d
  int v32; // r11d
  int v33; // r15d
  int v34; // r13d
  int v35; // edx
  int v36; // ebx
  int v37; // r13d
  int v38; // ebx
  int v39; // edi
  int v40; // r12d
  int v41; // r15d
  int v42; // r9d
  int v43; // edi
  int v44; // r12d
  int v45; // r15d
  int v46; // r9d
  int v47; // ebp
  int v48; // r14d
  int v49; // edx
  int v50; // r10d
  int v51; // ebp
  int v52; // r14d
  int v53; // edx
  int v54; // r10d
  int v55; // esi
  int v56; // r14d
  int v57; // r15d
  int v58; // ebx
  int v59; // edi
  int v60; // r13d
  int v61; // r8d
  int v62; // r10d
  int v63; // ebp
  int v64; // r12d
  int v65; // r11d
  int v66; // r9d
  int v67; // r15d
  int v68; // eax
  int v69; // edx
  int v70; // r9d
  int v71; // r12d
  unsigned __int64 v72; // r9
  unsigned __int64 v73; // rax
  unsigned __int64 v74; // rcx
  unsigned __int64 v75; // rdx
  int v76; // [rsp+20h] [rbp-158h] BYREF
  int v77; // [rsp+24h] [rbp-154h]
  int v78; // [rsp+28h] [rbp-150h]
  int v79; // [rsp+2Ch] [rbp-14Ch]
  int v80; // [rsp+30h] [rbp-148h]
  int v81; // [rsp+34h] [rbp-144h]
  int v82; // [rsp+38h] [rbp-140h]
  int v83; // [rsp+3Ch] [rbp-13Ch]
  int v84; // [rsp+40h] [rbp-138h]
  int v85; // [rsp+44h] [rbp-134h]
  int v86; // [rsp+48h] [rbp-130h]
  int v87; // [rsp+4Ch] [rbp-12Ch]
  int v88; // [rsp+50h] [rbp-128h]
  int v89; // [rsp+54h] [rbp-124h]
  int v90; // [rsp+58h] [rbp-120h]
  int v91; // [rsp+5Ch] [rbp-11Ch]
  int v92; // [rsp+6Ch] [rbp-10Ch]
  int v93; // [rsp+70h] [rbp-108h]
  int v94; // [rsp+74h] [rbp-104h]
  char *v95; // [rsp+78h] [rbp-100h]
  _QWORD *v96; // [rsp+80h] [rbp-F8h]
  _DWORD *v97; // [rsp+88h] [rbp-F0h]
  int v98; // [rsp+94h] [rbp-E4h]
  int v99; // [rsp+98h] [rbp-E0h]
  int v100; // [rsp+9Ch] [rbp-DCh]
  int v101; // [rsp+A0h] [rbp-D8h] BYREF
  int v102; // [rsp+A4h] [rbp-D4h]
  int v103; // [rsp+A8h] [rbp-D0h]
  int v104; // [rsp+ACh] [rbp-CCh]
  int v105; // [rsp+B0h] [rbp-C8h]
  int v106; // [rsp+B4h] [rbp-C4h]
  int v107; // [rsp+B8h] [rbp-C0h]
  int v108; // [rsp+BCh] [rbp-BCh]
  int v109; // [rsp+C0h] [rbp-B8h]
  int v110; // [rsp+C4h] [rbp-B4h]
  int v111; // [rsp+C8h] [rbp-B0h]
  int v112; // [rsp+CCh] [rbp-ACh]
  __int64 v113; // [rsp+D0h] [rbp-A8h]
  int v114; // [rsp+D8h] [rbp-A0h]
  int v115; // [rsp+DCh] [rbp-9Ch]
  __int64 v116; // [rsp+E0h] [rbp-98h]
  unsigned __int64 v117; // [rsp+E8h] [rbp-90h]
  _QWORD v118[16]; // [rsp+F0h] [rbp-88h] BYREF

  if ( a4 != 0 )
  {
    v4 = a4;
    v116 = a1;
    sub_140001C40((__int64)&v101, a1, 0x40u);
    v7 = nullptr;
    while ( 1 )
    {
      v117 = v4;
      if ( v4 > 0x3F )
      {
        v95 = v7;
        v97 = a2;
        v96 = a3;
        goto LABEL_21;
      }
      if ( v4 != 0 )
        break;
LABEL_20:
      v96 = v118;
      v97 = v118;
      v95 = (char *)a3;
LABEL_21:
      sub_140001C40((__int64)&v76, (__int64)&v101, 0x40u);
      v11 = v80;
      v12 = v76;
      v13 = v77;
      v14 = v88;
      v15 = v84;
      v16 = v81;
      v17 = v89;
      v18 = v85;
      v19 = v82;
      v20 = v78;
      v21 = v90;
      v93 = v86;
      v22 = v83;
      v23 = v79;
      v24 = v91;
      v99 = 10;
      v92 = v87;
      do
      {
        v25 = v11 + v12;
        v26 = __ROL4__(v25 ^ v14, 16);
        v27 = v26 + v15;
        v28 = __ROL4__(v27 ^ v11, 12);
        v29 = v28 + v25;
        v30 = __ROL4__(v29 ^ v26, 8);
        v31 = (v30 ^ v27) + 2 * (v27 & v30);
        v32 = __ROL4__(v31 ^ v28, 7);
        v33 = v16 + v13;
        v34 = __ROL4__(v33 ^ v17, 16);
        v35 = v34 + v18;
        v36 = __ROL4__(v35 ^ v16, 12);
        v100 = v36 + v33;
        v37 = __ROL4__((v36 + v33) ^ v34, 8);
        v94 = v37 + v35;
        v38 = __ROL4__((v37 + v35) ^ v36, 7);
        v39 = v19 + v20;
        v40 = __ROL4__(v39 ^ v21, 16);
        v41 = v40 + v93;
        v42 = __ROL4__((v40 + v93) ^ v19, 12);
        v43 = v42 + v39;
        v44 = __ROL4__(v43 ^ v40, 8);
        v45 = v44 + v41;
        v46 = v45 ^ v42;
        v47 = v22 + v23;
        v48 = __ROL4__(v47 ^ v24, 16);
        v49 = v48 + v92;
        v50 = __ROL4__((v48 + v92) ^ v22, 12);
        v51 = v50 + v47;
        v52 = __ROL4__(v51 ^ v48, 8);
        v53 = v52 + v49;
        v54 = __ROL4__(v53 ^ v50, 7);
        v55 = v38 + v29;
        v56 = __ROL4__(v55 ^ v52, 16);
        v57 = v56 + v45;
        v58 = __ROL4__(v57 ^ v38, 12);
        v12 = v58 + v55;
        v59 = v54 + v43;
        v60 = __ROL4__(v59 ^ v37, 16);
        v61 = v60 + v31;
        v62 = __ROL4__(v61 ^ v54, 12);
        v20 = v62 + v59;
        v63 = v32 + v51;
        v64 = __ROL4__(v63 ^ v44, 16);
        v94 += v64;
        v65 = __ROL4__(v94 ^ v32, 12);
        v98 = v65 + v63;
        v66 = __ROL4__(v46, 7);
        v24 = __ROL4__(v12 + v56 - 2 * (v56 & v12), 8);
        v93 = v24 + v57;
        v16 = __ROL4__((v24 + v57) ^ v58, 7);
        v67 = v66 + v100;
        v68 = __ROL4__((v66 + v100) ^ v30, 16);
        v69 = v68 + v53;
        v70 = __ROL4__(v69 ^ v66, 12);
        v13 = v70 + v67;
        v14 = __ROL4__(v13 ^ v68, 8);
        v92 = v14 + v69;
        v19 = __ROL4__((v14 + v69) ^ v70, 7);
        v17 = __ROL4__(v20 + v60 - 2 * (v60 & v20), 8);
        v15 = v17 + v61;
        v22 = __ROL4__(v15 ^ v62, 7);
        v71 = v65 + v63 - 2 * (v64 & (v65 + v63)) + v64;
        v23 = v65 + v63;
        v21 = __ROL4__(v71, 8);
        v18 = v21 + v94;
        v11 = __ROL4__((v21 + v94) ^ v65, 7);
        --v99;
      }
      while ( v99 != 0 );
      v80 = v11;
      v88 = v14;
      v84 = v15;
      v81 = v16;
      v77 = v13;
      v89 = v17;
      v85 = v21 + v94;
      v82 = v19;
      v78 = v20;
      v90 = v21;
      v86 = v93;
      v83 = v22;
      v79 = v23;
      v91 = v24;
      v87 = v92;
      v76 = v101 + v12;
      a2 = v97;
      v76 = *v97 ^ (v101 + v12);
      v77 = v102 + v13;
      v77 = v97[1] ^ (v102 + v13);
      v78 = v103 + v20;
      v78 = v97[2] ^ (v103 + v20);
      v79 = v104 + v23;
      v79 = v97[3] ^ (v104 + v23);
      v80 = v105 + v11;
      v80 = v97[4] ^ (v105 + v11);
      v81 = v106 + v16;
      v81 = v97[5] ^ (v106 + v16);
      v82 = v107 + v19;
      v82 = v97[6] ^ (v107 + v19);
      v83 = v108 + v22;
      v83 = v97[7] ^ (v108 + v22);
      v84 = v109 + v15;
      v84 = v97[8] ^ (v109 + v15);
      v85 = v110 + v18;
      v85 = v97[9] ^ (v110 + v18);
      v86 = v111 + v93;
      v86 = v97[10] ^ (v111 + v93);
      v87 = v112 + v92;
      v87 = v97[11] ^ (v112 + v92);
      v88 = v113 + v14;
      v88 = v97[12] ^ (v113 + v14);
      v89 = HIDWORD(v113) + v17;
      v89 = v97[13] ^ (HIDWORD(v113) + v17);
      v90 = v114 + v21;
      v90 = v97[14] ^ (v114 + v21);
      v91 += v115;
      v91 ^= v97[15];
      LODWORD(v113) = v113 + 1;
      if ( (_DWORD)v113 == 0 )
        ++HIDWORD(v113);
      a3 = v96;
      sub_140001C40((__int64)v96, (__int64)&v76, 0x40u);
      v72 = v117;
      if ( v117 > 0x40 )
      {
        v4 = v117 - 64;
        a3 += 4;
        a2 += 4;
        v7 = v95;
      }
      else
      {
        v7 = v95;
        if ( v117 - 1 <= 0x3E )
        {
          if ( v117 < 0x10 )
          {
            v73 = 0;
            v74 = 0;
            v75 = v117 & 3;
            if ( (v117 & 3) != 0 )
              goto LABEL_36;
          }
          else
          {
            v73 = 0;
            if ( (unsigned __int64)(v95 - (char *)a3) >= 0x10 )
            {
              v73 = v117 & 0x30;
              *(_OWORD *)v95 = *a3;
              if ( v73 != 16 )
              {
                *((_OWORD *)v7 + 1) = a3[1];
                if ( (_DWORD)v73 != 32 )
                  *((_OWORD *)v7 + 2) = a3[2];
              }
              if ( v72 == v73 )
                goto LABEL_40;
            }
            v74 = v73;
            v75 = v72 & 3;
            if ( (v72 & 3) == 0 )
              goto LABEL_38;
LABEL_36:
            v74 = v73;
            do
            {
              v7[v74] = *((_BYTE *)a3 + v74);
              ++v74;
              --v75;
            }
            while ( v75 != 0 );
          }
LABEL_38:
          if ( v73 - v72 <= 0xFFFFFFFFFFFFFFFCuLL )
          {
            do
            {
              v7[v74] = *((_BYTE *)a3 + v74);
              v7[v74 + 1] = *((_BYTE *)a3 + v74 + 1);
              v7[v74 + 2] = *((_BYTE *)a3 + v74 + 2);
              v7[v74 + 3] = *((_BYTE *)a3 + v74 + 3);
              v74 += 4LL;
            }
            while ( v72 != v74 );
          }
        }
LABEL_40:
        *(_QWORD *)(v116 + 48) = v113;
        v4 = v72;
        if ( v72 <= 0x40 )
          return;
      }
    }
    if ( v4 < 0x10 )
    {
      v8 = 0;
      v9 = 0;
      v10 = v4 & 3;
      if ( (v4 & 3) == 0 )
        goto LABEL_18;
    }
    else
    {
      v8 = 0;
      if ( (unsigned __int64)((char *)v118 - (char *)a2) >= 0x10 )
      {
        v8 = v4 & 0x30;
        *(_OWORD *)v118 = *a2;
        if ( v8 != 16 )
        {
          *(_OWORD *)&v118[2] = a2[1];
          if ( (_DWORD)v8 != 32 )
            *(_OWORD *)&v118[4] = a2[2];
        }
        if ( v4 == v8 )
          goto LABEL_20;
      }
      v9 = v8;
      v10 = v4 & 3;
      if ( (v4 & 3) == 0 )
        goto LABEL_18;
    }
    v9 = v8;
    do
    {
      *((_BYTE *)v118 + v9) = *((_BYTE *)a2 + v9);
      ++v9;
      --v10;
    }
    while ( v10 != 0 );
LABEL_18:
    if ( v8 - v4 <= 0xFFFFFFFFFFFFFFFCuLL )
    {
      do
      {
        *((_BYTE *)v118 + v9) = *((_BYTE *)a2 + v9);
        *((_BYTE *)v118 + v9 + 1) = *((_BYTE *)a2 + v9 + 1);
        *((_BYTE *)v118 + v9 + 2) = *((_BYTE *)a2 + v9 + 2);
        *((_BYTE *)v118 + v9 + 3) = *((_BYTE *)a2 + v9 + 3);
        v9 += 4LL;
      }
      while ( v4 != v9 );
    }
    goto LABEL_20;
  }
}


// ---- sub_140004710 @ 0x140004710 ----
__int64 __fastcall sub_140004710(__int64 a1, __int16 *a2)
{
  __int64 result; // rax
  __int16 v3; // cx

  result = a1 - 2;
  do
  {
    v3 = *a2++;
    *(_WORD *)(result + 2) = v3;
    result += 2;
  }
  while ( v3 != 0 );
  return result;
}


// ---- sub_140004740 @ 0x140004740 ----
bool __fastcall sub_140004740(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // rax
  __int64 (__fastcall *v7)(__int64, __int64, _QWORD, _DWORD *); // r14
  int v8; // eax
  bool v9; // zf
  bool result; // al
  _DWORD v11[11]; // [rsp+2Ch] [rbp-2Ch] BYREF

  v6 = sub_14002FDC0(qword_14003BA48, 2076004194);
  v11[0] = 0;
  if ( a3 == 0 )
    return true;
  v7 = (__int64 (__fastcall *)(__int64, __int64, _QWORD, _DWORD *))v6;
  do
  {
    v8 = v7(a1, a2, a3, v11);
    v9 = v8 == 0;
    result = v8 != 0;
    if ( v9 )
      break;
    a2 += v11[0];
    a3 -= v11[0];
  }
  while ( a3 != 0 );
  return result;
}


// ---- sub_1400047C0 @ 0x1400047c0 ----
__int64 sub_1400047C0()
{
  return sub_140003ED0((__int64)&unk_14003BA88, qword_1400334F0, dword_140033510, 0);
}


// ---- sub_1400047E0 @ 0x1400047e0 ----
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_1400047E0(__int64 a1)
{
  unsigned int (__fastcall *v2)(__int64, _QWORD, _QWORD, __int128 *); // rax
  __int64 v3; // rdx
  unsigned int v5; // ebp
  __int64 v6; // rbx
  __int64 v7; // rdi
  __int64 (__fastcall *v8)(_WORD *, __int64, _QWORD, _QWORD, _DWORD); // rbx
  unsigned int v9; // eax
  __int64 v10; // rbx
  __int64 result; // rax
  void (__fastcall *v12)(__int64, _QWORD, __int64, __int64, int); // rax
  void (__fastcall *v13)(__int64); // r15
  __int64 (__fastcall *v14)(__int64, __int64, _QWORD, _QWORD); // rax
  unsigned int i; // [rsp-1CCh] [rbp-3D4h]
  _WORD v16[112]; // [rsp-188h] [rbp-390h] BYREF
  __int128 v17; // [rsp-A8h] [rbp-2B0h] BYREF
  __int128 v18; // [rsp-98h] [rbp-2A0h]
  __int128 v19; // [rsp-88h] [rbp-290h]
  __int128 v20; // [rsp-78h] [rbp-280h]
  __int128 v21; // [rsp-68h] [rbp-270h]
  __int128 v22; // [rsp-58h] [rbp-260h]
  __int64 v23; // [rsp-48h] [rbp-250h]

  v17 = 0;
  v19 = 0;
  v22 = 0;
  v21 = 0;
  v20 = 0;
  v18 = 0;
  v23 = 0;
  LODWORD(v17) = 104;
  LODWORD(v19) = -1;
  LODWORD(v22) = -1;
  v2 = (unsigned int (__fastcall *)(__int64, _QWORD, _QWORD, __int128 *))sub_14002FDC0(qword_14003BA48, 1255419155);
  v3 = 0;
  while ( *(_WORD *)(a1 + 2 * v3++) != 0 )
    ;
  v5 = 0;
  switch ( v2(a1, (unsigned int)(v3 - 1), 0, &v17) != 0 )
  {
    case false:
      LOBYTE(v5) = 0;
      result = v5;
      break;
    case true:
      v6 = (unsigned int)v19;
      v7 = sub_14002E070(2LL * (unsigned int)(v19 + 1));
      *(_WORD *)sub_140001C40(v7, *((__int64 *)&v18 + 1), 2 * v6) = 0;
      v8 = (__int64 (__fastcall *)(_WORD *, __int64, _QWORD, _QWORD, _DWORD))sub_14002FDC0(
                                                                               qword_14003BA48,
                                                                               3937182846LL);
      sub_140001C20((__int64)v16);
      for ( i = 0;
            i < 0x70;
            v16[v9] = (v16[v9] | ((i & 0x35AD) * (i & 0xCA52 ^ 0xCA52) + (i & 0xCA52) * (i | 0xCA52)))
                    ^ v16[v9]
                    & ((i & 0x35AD) * (i & 0xCA52 ^ 0xCA52) + (i & 0xCA52) * (i | 0xCA52)) )
      {
        v9 = i++;
      }
      v10 = v8(v16, 1, 0, 0, 0);
      switch ( v10 != 0 )
      {
        case false:
          result = ((__int64 (*)(void))off_140036628)();
          break;
        case true:
          v12 = (void (__fastcall *)(__int64, _QWORD, __int64, __int64, int))sub_14002FDC0(qword_14003BA48, 768134409);
          v12(v10, 0, 150000, 150000, 150000);
          v13 = (void (__fastcall *)(__int64))sub_14002FDC0(qword_14003BA48, 349916912);
          v14 = (__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))sub_14002FDC0(qword_14003BA48, 2708563245LL);
          switch ( v14(v10, v7, WORD2(v19), 0) != 0 )
          {
            case false:
              v13(v10);
              result = ((__int64 (*)(void))off_140036628)();
              break;
            case true:
              sub_14002FDC0(qword_14003BA48, 3336936774LL);
              switch ( DWORD1(v18) == 2 )
              {
                case false:
                  JUMPOUT(0x14000556ELL);
                case true:
                  result = ((__int64 (*)(void))off_140036348)();
                  break;
              }
              break;
          }
          break;
      }
      break;
  }
  return result;
}


// ---- sub_140004F3F @ 0x140004f3f ----
void sub_140004F3F()
{
  sub_14002FDC0(qword_14003BA48, 2954560499LL);
  JUMPOUT(0x140004F50LL);
}


// ---- sub_140005372 @ 0x140005372 ----
__int64 __fastcall sub_140005372(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  char v9; // bp
  __int64 v10; // r12
  _QWORD *v11; // r14
  void (__fastcall *v12)(__int64); // r15

  switch ( v9 )
  {
    case 0:
      break;
    case 1:
      switch ( v11[6] != 0 )
      {
        case false:
          switch ( v11[4] != 0 )
          {
            case false:
              goto LABEL_2;
            case true:
              switch ( v11[5] != 0 )
              {
                case false:
                  goto LABEL_2;
                case true:
                  return off_1400365B0(a1, a2, a3, a4, a5, a6, a7, a8, a9);
              }
          }
        case true:
          return off_140036540();
      }
  }
LABEL_2:
  v12(v10);
  JUMPOUT(0x1400054CDLL);
}


// ---- sub_1400054DF @ 0x1400054df ----
// positive sp value has been detected, the output may be wrong!
__int64 sub_1400054DF()
{
  return ((__int64 (*)(void))off_140036640)();
}


// ---- sub_140005630 @ 0x140005630 ----
__int64 __fastcall sub_140005630(unsigned __int64 a1, __int64 a2, __int64 a3, int a4)
{
  _BYTE *v5; // rcx
  unsigned __int64 v6; // rdx
  char v7; // dl

  v5 = (_BYTE *)(a3 + a2 - 1);
  *v5 = 0;
  if ( a1 != 0 )
  {
    while ( a1 != 0 )
    {
      v6 = a1 % a4;
      if ( v6 < 0xA )
        v7 = v6 + 48;
      else
        v7 = v6 - 10 + 97;
      *(v5 - 1) = v7;
      a1 /= (unsigned __int64)a4;
      --v5;
    }
  }
  else
  {
    *(_BYTE *)(a3 + a2 - 2) = 48;
    return a3 + a2 - 2;
  }
  return (__int64)v5;
}


// ---- sub_1400056B0 @ 0x1400056b0 ----
char __fastcall sub_1400056B0(__int64 a1, __int64 a2, unsigned __int64 a3, __int64 a4, __int64 a5)
{
  bool v7; // bp
  __m128i si128; // xmm6
  char v9; // di
  __int64 v10; // rax
  __int64 v11; // rsi
  unsigned __int64 v12; // rcx
  __int64 v13; // r10
  char *v14; // r8
  char *v15; // rdx
  unsigned __int64 v16; // r9
  unsigned __int64 v17; // r10
  __int64 v18; // r10
  __int64 v19; // r12
  char v20; // al
  __int64 v21; // rax
  unsigned int v22; // ecx
  unsigned int v23; // ecx
  int v24; // ecx
  int v25; // edx
  int v26; // ecx
  int v27; // ecx
  unsigned int v28; // edx
  char *v29; // r8
  char *v30; // r9
  char *v31; // rcx
  char *v32; // rax
  bool v33; // cc
  char *v34; // rcx
  __int64 v35; // r10
  char *v36; // r8
  char *v37; // rdx
  unsigned __int64 v38; // r9
  unsigned __int64 v39; // r10
  __int64 v40; // r10
  __int64 v41; // r12
  char v42; // al
  __int64 v43; // rdx
  __int64 v45; // [rsp+20h] [rbp-138h]
  __int64 v46; // [rsp+28h] [rbp-130h] BYREF
  __int16 v47; // [rsp+30h] [rbp-128h]
  unsigned int i; // [rsp+34h] [rbp-124h]
  bool v49; // [rsp+3Bh] [rbp-11Dh]
  unsigned int v50; // [rsp+3Ch] [rbp-11Ch] BYREF
  __int64 v51; // [rsp+40h] [rbp-118h]
  __int64 v52; // [rsp+48h] [rbp-110h]
  bool v53; // [rsp+50h] [rbp-108h]
  char v54; // [rsp+51h] [rbp-107h]
  __int64 v55; // [rsp+58h] [rbp-100h]
  unsigned __int64 v56; // [rsp+60h] [rbp-F8h]
  __int64 v57; // [rsp+68h] [rbp-F0h]
  __int64 v58; // [rsp+70h] [rbp-E8h]
  unsigned int *v59; // [rsp+78h] [rbp-E0h]
  char v60[115]; // [rsp+80h] [rbp-D8h] BYREF
  char v61; // [rsp+F3h] [rbp-65h] BYREF
  char v62; // [rsp+FFh] [rbp-59h] BYREF

  v50 = 0;
  v52 = a1;
  v54 = 0;
  v55 = a2;
  v56 = a3;
  v57 = a4;
  v58 = a5;
  v59 = &v50;
  if ( (unsigned __int8)sub_140005D60() == 0 )
    return 0;
  v7 = a2 == 0 || a3 == 0;
  v51 = -(__int64)byte_14003BAD0;
  si128 = _mm_load_si128((const __m128i *)&xmmword_1400338C0);
  v49 = v7;
LABEL_4:
  v53 = false;
  v9 = 0;
  while ( 1 )
  {
    if ( !v7 && v9 != 0 )
    {
      v10 = sub_140005630(a3, (__int64)v60, 128, 10);
      v11 = v10;
      if ( v53 )
      {
        *(_WORD *)(v10 - 2) = 11627;
        *(_DWORD *)(v10 - 6) = 1853188195;
        v11 = v10 - 6;
      }
      *(_BYTE *)(v11 - 1) = 45;
      *(_BYTE *)(v11 - 2) = v9 + 48;
      v12 = v11 - 3;
      *(_BYTE *)(v11 - 3) = 45;
      v13 = -1;
      v14 = byte_14003BAD0;
      do
      {
        v15 = v14;
        v16 = v13;
        v14 += 2;
        v13 += 2;
      }
      while ( *(_WORD *)v15 != 0 );
      if ( v15 <= byte_14003BAD0 )
        goto LABEL_21;
      v17 = (unsigned __int64)&v15[v51 - 1];
      if ( v17 >= 0x2E )
      {
        if ( v11 - ((unsigned __int64)(v15 - byte_14003BAD0 - 1) >> 1) - 4 >= (unsigned __int64)v15
          || (unsigned __int64)&v15[-((v15 - byte_14003BAD0 - 1) & 0xFFFFFFFFFFFFFFFEuLL) - 2] >= v12 )
        {
          v18 = (v17 >> 1) + 1;
          v15 = &v15[-(v18 & 0xFFFFFFFFFFFFFFF0uLL) - (v18 & 0xFFFFFFFFFFFFFFF0uLL)];
          v12 -= v18 & 0xFFFFFFFFFFFFFFF0uLL;
          v16 = -(__int64)(((v16 >> 1) + 1) & 0xFFFFFFFFFFFFFFF0uLL);
          v19 = 0;
          do
          {
            *(__m128i *)(v11 + v19 - 19) = _mm_packus_epi16(
                                             _mm_and_si128(_mm_loadu_si128((const __m128i *)&v14[2 * v19 - 34]), si128),
                                             _mm_and_si128(_mm_loadu_si128((const __m128i *)&v14[2 * v19 - 18]), si128));
            v19 -= 16;
          }
          while ( v16 != v19 );
          v7 = v49;
          if ( v18 == (v18 & 0xFFFFFFFFFFFFFFF0uLL) )
            goto LABEL_21;
        }
        else
        {
          v7 = v49;
        }
      }
      do
      {
        v20 = *(v15 - 2);
        v15 -= 2;
        *(_BYTE *)--v12 = v20;
      }
      while ( v15 > byte_14003BAD0 );
LABEL_21:
      sub_140006360(v12, v15, v14, v16);
    }
    v46 = 0xED1C71A5F6EB7B02uLL;
    v47 = 26778;
    for ( i = 0; i < 5; *((_WORD *)&v46 + v21) ^= 31570 * (_WORD)i )
      v21 = (int)i++;
    if ( (unsigned __int8)sub_1400047E0((__int64)byte_14003BAD0) != 0 )
      break;
LABEL_37:
    LODWORD(v46) = 0;
    v27 = -1462781531;
    do
    {
      LODWORD(v46) = v46 + 1;
      v27 ^= -1462781871 * v46;
    }
    while ( (_DWORD)v46 == 0 );
    if ( v50 != v27 )
    {
      v28 = v50;
      if ( v50 != 0 )
      {
        v62 = 0;
        v29 = &v61;
        v30 = &v62;
        do
        {
          v31 = v30;
          v32 = v29;
          --v30;
          *(v31 - 1) = (v28 % 0xA) | 0x30;
          --v29;
          v33 = v28 <= 9;
          v28 /= 0xAu;
        }
        while ( !v33 );
        *(v31 - 2) = 45;
        *((_WORD *)v31 - 2) = 29485;
        v34 = v31 - 4;
        v35 = -1;
        v36 = byte_14003BAD0;
        do
        {
          v37 = v36;
          v38 = v35;
          v36 += 2;
          v35 += 2;
        }
        while ( *(_WORD *)v37 != 0 );
        if ( v37 > byte_14003BAD0 )
        {
          v39 = (unsigned __int64)&v37[~(unsigned __int64)byte_14003BAD0];
          if ( v39 < 0x1E )
            goto LABEL_65;
          v40 = (v39 >> 1) + 1;
          v37 = &v37[-(v40 & 0xFFFFFFFFFFFFFFF0uLL) - (v40 & 0xFFFFFFFFFFFFFFF0uLL)];
          v34 -= v40 & 0xFFFFFFFFFFFFFFF0uLL;
          v38 = -(__int64)(((v38 >> 1) + 1) & 0xFFFFFFFFFFFFFFF0uLL);
          v41 = 0;
          do
          {
            *(__m128i *)(v32 - 8) = _mm_packus_epi16(
                                      _mm_and_si128(_mm_loadu_si128((const __m128i *)&v36[2 * v41 - 34]), si128),
                                      _mm_and_si128(_mm_loadu_si128((const __m128i *)&v36[2 * v41 - 18]), si128));
            v41 -= 16;
            v32 -= 16;
          }
          while ( v38 != v41 );
          if ( v40 != (v40 & 0xFFFFFFFFFFFFFFF0uLL) )
          {
LABEL_65:
            do
            {
              v42 = *(v37 - 2);
              v37 -= 2;
              *--v34 = v42;
            }
            while ( v37 > byte_14003BAD0 );
          }
        }
        sub_140006360(v34, v37, v36, v38);
        v50 = 0;
      }
      if ( v56 >= 0x200000 )
        v53 = v53 + 1 != 2 * v53;
      v46 = -50000000;
      if ( qword_14003BB50 != 0 )
      {
        v43 = 0;
        while ( *(_DWORD *)(qword_14003BB58 + 8 * v43) != 1475872016 )
        {
          if ( qword_14003BB50 == ++v43 )
            goto LABEL_58;
        }
        sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v43 + 4), 2, 0, (unsigned int)&v46, v45, v46, v47);
      }
      else
      {
LABEL_58:
        for ( i = 0; i == 0; ++i )
          ;
      }
      if ( ++v9 != 5 )
        continue;
    }
    byte_140036010 = ((126 - (((byte_140036010 + ~(2 * byte_140036010)) & 0xCC | byte_140036010 & 0x33) ^ 0x1F)) & 0x5D
                    | ((((byte_140036010 + ~(2 * byte_140036010)) & 0xCC | byte_140036010 & 0x33) ^ 0x1F) + 1) & 0xA2)
                   ^ 0x8E;
    if ( (unsigned __int8)sub_140005D60() == 0 )
      return 0;
    goto LABEL_4;
  }
  LODWORD(v46) = 0;
  v22 = 804376901;
  do
  {
    LODWORD(v46) = v46 + 1;
    v22 ^= 804376973 * v46;
  }
  while ( (_DWORD)v46 == 0 );
  if ( v50 < v22 )
    goto LABEL_33;
  LODWORD(v46) = 0;
  v23 = -836154859;
  do
  {
    LODWORD(v46) = v46 + 1;
    v23 = (v23 + ((-836154562 * v46) ^ v23) - (v23 & ~(-836154562 * v46))) & ~((-836154562 * v46) & v23);
  }
  while ( (_DWORD)v46 == 0 );
  if ( v50 > v23 )
  {
LABEL_33:
    LODWORD(v46) = 0;
    v24 = 1818281338;
    do
    {
      LODWORD(v46) = v46 + 1;
      v25 = ((1818281199 * v46) | v24) & (((1818281199 * v46) & v24) + ~(2 * ((1818281199 * v46) & v24)));
      v24 = v25;
    }
    while ( (_DWORD)v46 == 0 );
    if ( v50 != v25 )
    {
      LODWORD(v46) = 0;
      v26 = 177749811;
      do
      {
        LODWORD(v46) = v46 + 1;
        v26 ^= (v46 & 0xA983EA0 ^ 0xA983EA0) * (v46 & 0xF567C15F) + (v46 & 0xA983EA0) * (v46 | 0x2983EA0);
      }
      while ( (_DWORD)v46 == 0 );
      if ( v50 == v26 )
        return 0;
      goto LABEL_37;
    }
  }
  return 1;
}


// ---- sub_140005D60 @ 0x140005d60 ----
__int64 __fastcall sub_140005D60()
{
  _QWORD *v0; // rsi
  unsigned int v1; // eax
  unsigned int v2; // r8d
  int v3; // ecx
  int v4; // eax
  unsigned __int64 j; // rax
  __int64 v6; // rax
  __int64 v7; // rax
  int v8; // eax
  __int64 v9; // rax
  int v10; // eax
  unsigned int v11; // eax
  _QWORD *v12; // rax
  _BYTE *v13; // rcx
  char v15; // r9
  char *v16; // rcx
  char *v17; // rax
  unsigned int v18; // r9d
  char v19; // r8
  char v20; // r10
  unsigned int i; // [rsp+2Ch] [rbp-17Ch]
  _QWORD *v23; // [rsp+30h] [rbp-178h] BYREF
  __int64 v24; // [rsp+38h] [rbp-170h] BYREF
  __int16 v25; // [rsp+40h] [rbp-168h]
  char *v26; // [rsp+48h] [rbp-160h] BYREF
  _BYTE v27[7]; // [rsp+50h] [rbp-158h] BYREF
  __int64 v28; // [rsp+58h] [rbp-150h] BYREF
  unsigned __int64 v29[6]; // [rsp+60h] [rbp-148h] BYREF
  int v30; // [rsp+90h] [rbp-118h]
  _QWORD *v31; // [rsp+98h] [rbp-110h]
  __int16 v32; // [rsp+A0h] [rbp-108h]
  _QWORD *v33; // [rsp+A8h] [rbp-100h]
  __int64 v34; // [rsp+B0h] [rbp-F8h]
  char **v35; // [rsp+B8h] [rbp-F0h]
  __int64 *v36; // [rsp+C0h] [rbp-E8h]
  __int64 v37; // [rsp+C8h] [rbp-E0h]
  _QWORD v38[4]; // [rsp+D0h] [rbp-D8h] BYREF
  _WORD v39[16]; // [rsp+F0h] [rbp-B8h]
  _QWORD v40[18]; // [rsp+110h] [rbp-98h] BYREF

  LOBYTE(v0) = 1;
  if ( byte_140036010 != 44 && ((unsigned __int8)byte_140036010 ^ (unsigned __int8)byte_140036011) != -120 )
  {
    if ( ((unsigned __int8)byte_140036010 ^ 0xD3u) > 2 )
    {
      if ( byte_140036010 != -48 )
        goto LABEL_23;
      qmemcpy(v39, byte_140033742, 30);
      qmemcpy(v38, &ymmword_140033722, sizeof(v38));
      v0 = v40;
      sub_140001C20((__int64)v40);
      v26 = nullptr;
      v28 = 0;
      LODWORD(v31) = 0;
      do
      {
        v7 = (int)v31;
        LODWORD(v31) = (_DWORD)v31 + 1;
        *((_WORD *)v38 + v7) ^= 15283 * (_WORD)v31;
      }
      while ( (unsigned int)v31 < 0x1F );
      v31 = v38;
      v32 = 256;
      LODWORD(v29[0]) = 0;
      do
      {
        v8 = LODWORD(v29[0])++;
        *((_BYTE *)v40 + v8) ^= 24 * LOBYTE(v29[0]);
      }
      while ( LODWORD(v29[0]) < 0x89 );
      v33 = v40;
      v34 = 136;
      v35 = &v26;
      v36 = &v28;
      v37 = 0;
      v24 = 0x781C1A65BC6B5E42LL;
      v25 = -10662;
      LODWORD(v29[0]) = 0;
      do
      {
        v9 = SLODWORD(v29[0]);
        ++LODWORD(v29[0]);
        *((_WORD *)&v24 + v9) ^= 24082 * LOWORD(v29[0]);
      }
      while ( LODWORD(v29[0]) < 5 );
      qmemcpy(v29, byte_1400337F4, sizeof(v29));
      v30 = 246310612;
      LODWORD(v23) = 0;
      do
      {
        v10 = (int)v23;
        LODWORD(v23) = (_DWORD)v23 + 1;
        *((_WORD *)v29 + v10) ^= ((unsigned __int16)v23 & 0x580C) * ((unsigned __int16)v23 & 0xA7F3 ^ 0xA7F3)
                               + ((unsigned __int16)v23 & 0xA7F3) * ((unsigned __int16)v23 | 0xA7F3);
      }
      while ( (unsigned int)v23 < 0x1A );
      if ( (unsigned __int8)sub_1400047E0((__int64)v29) != 0 )
      {
        v26[v28] = 0;
        v24 = 0x7FFF800000000000LL;
        v23 = nullptr;
        if ( (unsigned int)sub_140001040(v26, v29, &v24, &v23) != 0 )
          goto LABEL_22;
        *(_DWORD *)&v27[3] = -4062895;
        *(_DWORD *)v27 = 1370027835;
        for ( i = 0; i < 7; v27[v11] ^= (i & 0x49 ^ 0x49) * (i & 0xB6) + (i & 0x49) * (i | 0x49) )
          v11 = i++;
        v12 = (_QWORD *)sub_140006B50(&v24, v27);
        if ( v12 == nullptr )
        {
LABEL_22:
          LODWORD(v0) = 0;
        }
        else
        {
          v13 = (_BYTE *)(*v12 & 0x7FFFFFFFFFFFLL);
          while ( *v13++ != 0 )
            ;
          v15 = *(v13 - 65);
          if ( v15 != 0 )
          {
            v16 = v13 - 63;
            v17 = byte_14003BAD0;
            do
            {
              if ( (unsigned __int8)((v15 | 0x20) - 97) > 5u )
              {
                v19 = v15 - 48;
                if ( (unsigned int)(v15 - 48) >= 0xA )
                  v19 = 0;
              }
              else
              {
                v19 = (v15 | 0x20) - 87;
              }
              v18 = *(v16 - 1);
              v20 = *(v16 - 1) | 0x20;
              if ( (unsigned __int8)(v20 - 97) > 5u )
              {
                v18 -= 48;
                if ( v18 >= 0xA )
                  LOBYTE(v18) = 0;
              }
              else
              {
                LOBYTE(v18) = (v20 ^ 0x9E) + ((2 * v18) & 0xC) + 11;
              }
              *(_WORD *)v17 = (unsigned __int8)(v18 | (16 * v19));
              v17 += 2;
              v15 = *v16;
              v16 += 2;
            }
            while ( v15 != 0 );
          }
          else
          {
            v17 = byte_14003BAD0;
          }
          *(_WORD *)v17 = 0;
          LOBYTE(v0) = 1;
        }
        sub_140001000(&v23);
        sub_14002E0B0(v26);
      }
      else
      {
LABEL_23:
        LODWORD(v0) = 0;
      }
    }
    else
    {
      LODWORD(v40[0]) = 0;
      v1 = 1283077693;
      do
      {
        ++LODWORD(v40[0]);
        v2 = (v40[0] & 0xB385C982) * (v40[0] & 0x4C7A367D ^ 0x4C7A367D);
        v3 = v1 & (v2 + (v40[0] & 0x4C7A367D) * (LODWORD(v40[0]) | 0x4C7A367D));
        v1 = (v1 | (v2 + (v40[0] & 0x4C7A367D) * (LODWORD(v40[0]) | 0x4C7A367D))) & (v3 + ~(2 * v3));
      }
      while ( LODWORD(v40[0]) == 0 );
      sub_140004060(
        (__int64)&unk_14003BA88,
        &xmmword_140033520[4
                         * (unsigned __int8)(byte_140036010
                                           + (byte_140036010 & 2) * (-2 - (byte_140036010 & 0xD1))
                                           + (byte_140036010 & 0xD1) * ((byte_140036010 | 0xFD) + 1)
                                           - 45)],
        v40,
        v1);
      LODWORD(v38[0]) = 0;
      v4 = 108532413;
      do
      {
        ++LODWORD(v38[0]);
        v4 ^= -357453778 * LODWORD(v38[0]);
      }
      while ( LODWORD(v38[0]) == 0 );
      LODWORD(v38[0]) = v4;
      for ( j = 0; j < 0x40; j = (v6 ^ 1) + 2 * (v6 & 1) )
      {
        *((_BYTE *)v40 + j) ^= *((_BYTE *)v38 + (j & 3));
        v6 = (j ^ 1) + 2 * (j & 1);
        *((_BYTE *)v40 + v6) ^= *((_BYTE *)v38 + (v6 & 3));
      }
      sub_1400068A0(byte_14003BAD0, 64, v40, 0);
      LOBYTE(v0) = 1;
    }
    byte_140036011 = (byte_140036010 ^ 0xD3) + ((2 * byte_140036010) & 0xB6 ^ 0x59) + 92;
  }
  return (unsigned int)v0;
}


// ---- sub_140006360 @ 0x140006360 ----
void __fastcall sub_140006360(unsigned __int8 *a1)
{
  __int64 v2; // rax
  __int64 v3; // rax
  __int64 v4; // rdi
  char v5; // al
  char *v6; // rax
  char v7; // cl
  __int64 *v8; // rax
  char v9; // cl
  unsigned int v10; // eax
  char v11; // cl
  __m128i v12; // xmm1
  __m128i v13; // xmm1
  __m128i v14; // xmm0
  __m128i v15; // xmm0
  __m128i v16; // xmm0
  __m128i v17; // xmm1
  __m128i v18; // xmm1
  __m128i v19; // xmm0
  unsigned int v20; // ecx
  char v21; // r8
  bool v22; // cf
  char v23; // cl
  char v24; // dl
  unsigned int v25; // ecx
  char v26; // r8
  char v27; // cl
  char v28; // dl
  unsigned int v29; // ecx
  unsigned __int8 v30; // r10
  __int64 v31; // rdx
  __int64 v32; // r8
  char v33; // r9
  int v34; // r9d
  unsigned int v35; // ecx
  char v36; // r11
  char v37; // cl
  char v38; // r10
  unsigned int v39; // r9d
  _BYTE *v40; // rdx
  __int64 v41; // rax
  signed int v42; // eax
  unsigned int i; // [rsp+24h] [rbp-254h]
  unsigned __int64 v44; // [rsp+28h] [rbp-250h]
  __int16 v45; // [rsp+30h] [rbp-248h]
  __int64 v46; // [rsp+38h] [rbp-240h] BYREF
  __int16 v47; // [rsp+40h] [rbp-238h]
  _DWORD *v48; // [rsp+48h] [rbp-230h]
  __int64 v49; // [rsp+50h] [rbp-228h]
  __int128 v50; // [rsp+58h] [rbp-220h]
  __int64 v51; // [rsp+68h] [rbp-210h]
  _QWORD v52[12]; // [rsp+70h] [rbp-208h] BYREF
  int v53; // [rsp+D0h] [rbp-1A8h]
  _BYTE v54[3]; // [rsp+DDh] [rbp-19Bh]
  _DWORD v55[102]; // [rsp+E0h] [rbp-198h] BYREF

  if ( byte_14003BA60 != 0 )
  {
    v46 = 0x281E796C766A6E23LL;
    v55[0] = 0;
    do
    {
      v2 = v55[0];
      v55[0] = (v55[0] ^ 1) + 2 * (v55[0] & 1);
      *((_BYTE *)&v46 + v2) ^= 5 * LOBYTE(v55[0]);
    }
    while ( v55[0] < 8u );
    *(_QWORD *)((char *)v52 + 6) = 0xD4B32667D71944B5uLL;
    v52[0] = 0x44B5D72D7DB1EF27LL;
    v55[0] = 0;
    do
    {
      v3 = v55[0];
      v55[0] = (v55[0] ^ 1) + 2 * (v55[0] & 1);
      *((_BYTE *)v52 + v3) ^= (v55[0] & 0xB9) * (v55[0] & 0x46 ^ 0x46) + (v55[0] & 0x46) * (LOBYTE(v55[0]) | 0x46);
    }
    while ( v55[0] < 0xEu );
    v4 = 0;
    do
    {
      v5 = *((_BYTE *)v52 + v4);
      *((_BYTE *)v55 + v4++) = v5;
    }
    while ( v5 != 0 );
    v6 = &byte_14003BA60;
    do
    {
      v7 = *v6++;
      v54[v4++ + 2] = v7;
    }
    while ( v7 != 0 );
    v8 = &v46;
    do
    {
      v9 = *(_BYTE *)v8;
      v8 = (__int64 *)((char *)v8 + 1);
      v54[++v4] = v9;
    }
    while ( v9 != 0 );
    v10 = sub_140003050((unsigned int *)qword_14003BA50);
    v11 = (v10 >> 28) | 0x30;
    if ( v10 >= 0xA0000000 )
      v11 = (v10 >> 28) + 87;
    v54[v4] = v11;
    v12 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v10), 0);
    v13 = (__m128i)_mm_and_ps(
                     _mm_shuffle_ps(
                       (__m128)_mm_unpacklo_epi64(_mm_srli_epi32(v12, 0x18u), _mm_srli_epi32(v12, 0x14u)),
                       (__m128)_mm_unpackhi_epi64(_mm_srli_epi32(v12, 0x10u), _mm_srli_epi32(v12, 0xCu)),
                       204),
                     (__m128)xmmword_1400338D0);
    v14 = _mm_cmpgt_epi32(v13, (__m128i)xmmword_1400338E0);
    v15 = _mm_packs_epi32(v14, v14);
    v16 = _mm_packs_epi16(v15, v15);
    v17 = _mm_packus_epi16(v13, v13);
    v18 = _mm_packus_epi16(v17, v17);
    v19 = _mm_or_si128(
            _mm_andnot_si128(v16, _mm_or_si128(v18, (__m128i)xmmword_140033900)),
            _mm_and_si128(_mm_add_epi8(_mm_load_si128((const __m128i *)&xmmword_1400338F0), v18), v16));
    v20 = (v10 >> 8) & 0xF;
    v21 = v20 + 48;
    v22 = v20 < 0xA;
    v23 = v20 + 87;
    v24 = v21;
    if ( !v22 )
      v24 = v23;
    *(_DWORD *)&v54[v4 + 1] = _mm_cvtsi128_si32(v19);
    *((_BYTE *)v55 + v4 + 2) = v24;
    v25 = (unsigned __int8)v10 >> 4;
    v26 = v25 + 48;
    v22 = v25 < 0xA;
    v27 = v25 + 87;
    v28 = v26;
    if ( !v22 )
      v28 = v27;
    *((_BYTE *)v55 + v4 + 3) = v28;
    v29 = v10 & 0xF;
    if ( v29 < 0xA )
    {
      *((_BYTE *)&v55[1] + v4) = v29 | 0x30;
      v30 = *a1;
      if ( *a1 != 0 )
      {
LABEL_20:
        v31 = 5;
        v32 = 0;
        do
        {
          v34 = v30 + (v10 >> (8 * ((v32 ^ 0x1C) & (v32 | 3)))) - 2 * (v30 & (v10 >> (8 * ((v32 ^ 0x1C) & (v32 | 3)))));
          v35 = (unsigned __int8)v34 >> 4;
          v36 = v35 + 48;
          v22 = v35 < 0xA;
          v37 = v35 + 87;
          v38 = v36;
          if ( !v22 )
            v38 = v37;
          *((_BYTE *)v55 + v31 + v4) = v38;
          v39 = v34 & 0xF;
          if ( v39 < 0xA )
            v33 = v39 | 0x30;
          else
            v33 = ((v39 - 10) ^ 0x61) + 2 * ((v39 - 10) & 0x61);
          *((_BYTE *)v55 + v31 + v4 + 1) = v33;
          v30 = a1[++v32];
          v31 += 2;
        }
        while ( v30 != 0 );
        v40 = (char *)v55 + v4 + v31;
        goto LABEL_30;
      }
    }
    else
    {
      *((_BYTE *)&v55[1] + v4) = ((v29 - 10) ^ 0x61) + 2 * ((v29 - 10) & 0x61);
      v30 = *a1;
      if ( *a1 != 0 )
        goto LABEL_20;
    }
    v40 = (char *)&v55[1] + v4 + 1;
LABEL_30:
    *v40 = 0;
    qmemcpy(v52, byte_140033848, sizeof(v52));
    v53 = -1476101192;
    LODWORD(v46) = 0;
    do
    {
      v41 = (int)v46;
      LODWORD(v46) = v46 + 1;
      *((_WORD *)v52 + v41) ^= 11346 * (_WORD)v46;
    }
    while ( (unsigned int)v46 < 0x32 );
    v46 = (__int64)v52;
    v47 = 0;
    v48 = v55;
    v49 = v40 - (_BYTE *)v55;
    v50 = 0;
    v51 = 0;
    v44 = 0x89E8A71EC491E23FuLL;
    v45 = 27691;
    for ( i = 0; i < 5; *((_WORD *)&v44 + v42) ^= (i & 0x1D90) * (i & 0xE26F ^ 0xE26F) + (i & 0xE26F) * (i | 0xE26F) )
      v42 = i++;
    sub_1400047E0((__int64)byte_14003BAD0);
  }
}


// ---- sub_140006830 @ 0x140006830 ----
__int64 __fastcall sub_140006830(unsigned int a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // r10
  char v5; // dl
  bool v6; // cf
  int v7; // edx

  *(_BYTE *)(a2 + a3 - 1) = 0;
  if ( a1 != 0 )
  {
    v4 = a3 + a2 - 1;
    do
    {
      v7 = a1 % a4;
      if ( a1 % a4 >= 0xA )
        v5 = (v7 & 0xF5) - (~(_BYTE)v7 & 0xA) + 97;
      else
        v5 = v7 | 0x30;
      *(_BYTE *)--v4 = v5;
      v6 = a1 < a4;
      a1 /= a4;
    }
    while ( !v6 );
    return v4;
  }
  else
  {
    *(_BYTE *)(a3 + a2 - 2) = 48;
    return a3 + a2 - 2;
  }
}


// ---- sub_1400068A0 @ 0x1400068a0 ----
__int64 __fastcall sub_1400068A0(_WORD *a1, __int64 a2, unsigned __int8 *a3, unsigned __int64 a4)
{
  unsigned __int8 v4; // r10
  _WORD *v5; // rax
  unsigned __int64 v6; // rdx
  __int16 v7; // r11
  unsigned __int8 *v8; // r8
  _WORD *v9; // r10
  unsigned __int8 v10; // bl
  unsigned __int8 *v11; // rsi
  unsigned __int8 v12; // si
  __int16 v13; // di
  int v14; // esi
  __int16 v15; // r11
  unsigned int v16; // esi
  __int16 v17; // r11

  v4 = *a3;
  v5 = a1;
  if ( *a3 != 0 )
  {
    v6 = a2 - 1;
    v5 = a1;
    while ( 1 )
    {
      if ( a4 != 0 && (unsigned __int64)a3 >= a4 || v6 == 0 )
        goto LABEL_46;
      v7 = v4;
      if ( (v4 & 0x80u) == 0 )
        break;
      if ( (v4 & 0xE0) == 0xC0 )
      {
        v11 = a3 + 1;
        if ( v4 < 0xC2u )
        {
          v8 = a3 + 1;
          goto LABEL_9;
        }
        v10 = *v11;
        if ( (*v11 & 0xC0) != 0x80 )
          goto LABEL_11;
        v8 = a3 + 2;
        v13 = ((v4 & 0x1F) << 6) | v10 & 0x3F;
LABEL_33:
        v9 = v5 + 1;
        *v5 = v13;
LABEL_8:
        v6 -= v9 - v5;
        v5 = v9;
        goto LABEL_9;
      }
      if ( (v4 & 0xF0) == 0xE0 )
      {
        v12 = a3[1];
        if ( v4 == 0xED )
        {
          if ( v12 >= 0xA0u )
            goto LABEL_42;
        }
        else if ( v4 == 224 && (unsigned __int8)(v12 + 64) < 0xE0u )
        {
          goto LABEL_42;
        }
        if ( (a3[1] & 0xC0) != 0x80 )
          goto LABEL_42;
        v10 = a3[2];
        if ( (v10 & 0xC0) != 0x80 )
          goto LABEL_43;
        v8 = a3 + 3;
        v13 = (v4 << 12) | ((v12 & 0x3F) << 6) | v10 & 0x3F;
        goto LABEL_33;
      }
      if ( (v4 & 0xF8) != 0xF0 || v4 > 0xF4u )
      {
LABEL_42:
        v8 = a3 + 1;
        goto LABEL_9;
      }
      v14 = a3[1];
      if ( v4 == 0xF4 )
      {
        if ( (unsigned __int8)v14 >= 0x90u )
          goto LABEL_42;
      }
      else if ( v4 == 240 && (unsigned __int8)(v14 + 64) < 0xD0u )
      {
        goto LABEL_42;
      }
      if ( (v14 & 0x3F) - (v14 + 1) != -129 )
        goto LABEL_42;
      v10 = a3[2];
      v15 = v10;
      if ( (v10 & 0xC0) != 0x80 )
      {
LABEL_43:
        v8 = a3 + 2;
        goto LABEL_10;
      }
      v10 = a3[3];
      if ( (v10 & 0xC0) != 0x80 )
      {
        v8 = a3 + 3;
        goto LABEL_10;
      }
      v16 = ((v4 & 7) << 18) + ((v14 + 1 + (~v14 | 0x3F)) << 12);
      v8 = a3 + 4;
      if ( v16 >= 0x10000 )
      {
        v17 = v15 << 6;
        if ( (v16 & 0xFFFFF800 | v17 & 0x800) != 0xD800 )
        {
          if ( v6 < 2 )
          {
            v9 = v5;
          }
          else
          {
            *v5 = (((v16 | v17 & 0xFC0) + 983040) >> 10) & 0x3FF | 0xD800;
            v9 = v5 + 2;
            v5[1] = (v10 & 0x3F) + (v17 & 0x3C0) - 9216;
          }
          goto LABEL_8;
        }
      }
LABEL_9:
      v10 = *v8;
LABEL_10:
      v11 = v8;
LABEL_11:
      v4 = v10;
      a3 = v11;
      if ( v10 == 0 )
        goto LABEL_46;
    }
    v8 = a3 + 1;
    v9 = v5 + 1;
    *v5 = v7;
    goto LABEL_8;
  }
LABEL_46:
  *v5 = 0;
  return v5 - a1;
}


// ---- sub_140006B50 @ 0x140006b50 ----
__int64 __fastcall sub_140006B50(_QWORD *a1, __int64 a2)
{
  __int64 v2; // rsi

  v2 = *a1 & 0x7FFFFFFFFFFFLL;
  if ( v2 != 0 )
  {
    while ( (unsigned int)sub_1400020A0(*(_QWORD *)(v2 + 16), a2) != 0 )
    {
      v2 = *(_QWORD *)(v2 + 8);
      if ( v2 == 0 )
        return 0;
    }
  }
  return v2;
}


// ---- sub_140006BA0 @ 0x140006ba0 ----
__int64 sub_140006BA0()
{
  __int64 v0; // rax
  unsigned int v1; // eax
  __int64 v2; // rdi
  __int16 v3; // cx
  const char *v4; // rcx
  __int16 v5; // dx
  _QWORD v7[2]; // [rsp+F0h] [rbp-168h]
  _QWORD v8[22]; // [rsp+100h] [rbp-158h]
  _DWORD v9[42]; // [rsp+1B0h] [rbp-A8h] BYREF

  *(_OWORD *)v8 = xmmword_140033928;
  *(_OWORD *)v7 = xmmword_140033918;
  *(_QWORD *)((char *)&v8[1] + 6) = 0x51A3172EDD32A364LL;
  v9[0] = 0;
  do
  {
    v0 = v9[0]++;
    *((_WORD *)v7 + v0) ^= 14897 * LOWORD(v9[0]);
  }
  while ( v9[0] < 0x13u );
  v1 = 4 * (unsigned int)v9 - 4;
  v2 = 0;
  do
  {
    v3 = *(_WORD *)((char *)v7 + v2);
    *(_WORD *)((char *)v9 + v2) = v3;
    v2 += 2;
    v1 += 4;
  }
  while ( v3 != 0 );
  v4 = "28f78af408eeef7df2e43016843788b6";
  v5 = a28f78af408eeef[0];
  switch ( a28f78af408eeef[0] != 0 )
  {
    case false:
      return off_140036A00();
    case true:
      while ( 2 )
      {
        ++v4;
        *(_WORD *)((char *)&v8[21] + v2 + 6) = v5;
        v1 += 4;
        v2 += 2;
        v5 = *v4;
        switch ( v5 != 0 )
        {
          case false:
            return off_140036A00();
          case true:
            continue;
        }
      }
  }
}


// ---- sub_140008580 @ 0x140008580 ----
char __fastcall sub_140008580(__int64 a1, unsigned __int64 a2, _QWORD *a3, _QWORD *a4)
{
  int v6; // eax
  char result; // al
  __int64 v8; // r13
  unsigned __int64 v9; // rbx
  __int64 v10; // r14
  char v11; // bp
  _OWORD *v12; // r15
  _QWORD *v13; // [rsp+30h] [rbp-B8h] BYREF
  __int64 v14; // [rsp+38h] [rbp-B0h] BYREF
  _QWORD v15[12]; // [rsp+40h] [rbp-A8h] BYREF
  int v16; // [rsp+A0h] [rbp-48h]

  qmemcpy(v15, byte_140033950, sizeof(v15));
  v16 = 1603468395;
  LODWORD(v13) = 0;
  do
  {
    v6 = (int)v13;
    LODWORD(v13) = (_DWORD)v13 + 1;
    *((_WORD *)v15 + v6) ^= ((unsigned __int16)v13 & 0x9CCE) * ((unsigned __int16)v13 & 0x6331 ^ 0x6331)
                          + ((unsigned __int16)v13 & 0x6331) * ((unsigned __int16)v13 | 0x6331);
  }
  while ( (unsigned int)v13 < 0x32 );
  result = sub_1400056B0((__int64)v15, a1, a2, (__int64)&v13, (__int64)&v14);
  if ( result != 0 )
  {
    v8 = v14;
    v9 = v14 - 40;
    v10 = v14 - 39;
    v11 = result;
    v12 = (_OWORD *)sub_14002E070(v14 - 39);
    sub_140003ED0((__int64)v15, v13, (_DWORD *)v13 + 8, 0);
    sub_140004060((__int64)v15, v13 + 5, v12, v9);
    *((_BYTE *)v12 + v8 - 40) = 0;
    *a3 = v12;
    *a4 = v10;
    sub_14002E0B0(v13);
    return v11;
  }
  return result;
}


// ---- sub_1400086F0 @ 0x1400086f0 ----
unsigned __int64 *__fastcall sub_1400086F0(unsigned __int64 *a1, __int64 a2, __int64 a3)
{
  *a1 = ((a2 << 47) & 0x8007800000000000uLL | 0x3D38000000000000LL) ^ a3 ^ 0x42C0000000000000LL
      | a3 & ((a2 << 47) | 0x7FF8000000000000LL);
  return a1;
}


// ---- sub_140008740 @ 0x140008740 ----
_QWORD *__fastcall sub_140008740(_QWORD *a1)
{
  *a1 = 0;
  return a1;
}


// ---- sub_140008750 @ 0x140008750 ----
bool __fastcall sub_140008750(_QWORD *a1)
{
  return *a1 > 0x7FF8000000000000LL && (*a1 & 0x7800000000000LL) == 0x2000000000000LL;
}


// ---- sub_140008790 @ 0x140008790 ----
__int64 __fastcall sub_140008790(_QWORD *a1)
{
  return *a1 & 0x7FFFFFFFFFFFLL;
}


// ---- sub_1400087A0 @ 0x1400087a0 ----
// attributes: thunk
__int64 __fastcall sub_1400087A0(_QWORD **a1)
{
  return sub_140001000(a1);
}


// ---- sub_1400087B0 @ 0x1400087b0 ----
__int64 __fastcall sub_1400087B0(__int64 a1)
{
  *(_OWORD *)a1 = 0;
  *(_QWORD *)(a1 + 16) = 0;
  return a1;
}


// ---- sub_1400087D0 @ 0x1400087d0 ----
char __fastcall sub_1400087D0(char a1, __int64 a2)
{
  __int64 v5; // rax
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 v8; // rax
  _BYTE *v9; // rdi
  unsigned __int8 v10; // r12
  __int64 v11; // r14
  int v12; // ebp
  _BYTE *v13; // r8
  int v14; // eax
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 v17; // rax
  _QWORD *v18; // rax
  __int64 v19; // rax
  _QWORD *v20; // rax
  __int64 v21; // rax
  __int64 v22; // r15
  __int64 v23; // rax
  _QWORD *v24; // rax
  __int64 v25; // rax
  __int64 v26; // rax
  _QWORD *v27; // rax
  __int64 v28; // rax
  unsigned int i; // [rsp+24h] [rbp-194h]
  unsigned int j; // [rsp+28h] [rbp-190h]
  unsigned int k; // [rsp+2Ch] [rbp-18Ch]
  unsigned int m; // [rsp+30h] [rbp-188h]
  int n; // [rsp+34h] [rbp-184h]
  unsigned int ii; // [rsp+38h] [rbp-180h]
  unsigned int jj; // [rsp+3Ch] [rbp-17Ch]
  unsigned int kk; // [rsp+40h] [rbp-178h]
  int v37; // [rsp+44h] [rbp-174h] BYREF
  unsigned __int64 v38; // [rsp+48h] [rbp-170h] BYREF
  _BYTE v39[5]; // [rsp+51h] [rbp-167h] BYREF
  _BYTE v40[5]; // [rsp+56h] [rbp-162h] BYREF
  _BYTE v41[5]; // [rsp+5Bh] [rbp-15Dh] BYREF
  char *v42; // [rsp+60h] [rbp-158h] BYREF
  _QWORD *v43; // [rsp+68h] [rbp-150h] BYREF
  char v44[7]; // [rsp+75h] [rbp-143h] BYREF
  _BYTE v45[11]; // [rsp+7Ch] [rbp-13Ch] BYREF
  _BYTE v46[11]; // [rsp+87h] [rbp-131h] BYREF
  char v47[14]; // [rsp+92h] [rbp-126h] BYREF
  __int64 v48; // [rsp+A0h] [rbp-118h] BYREF
  unsigned __int64 v49; // [rsp+A8h] [rbp-110h] BYREF
  _BYTE v50[64]; // [rsp+B0h] [rbp-108h] BYREF
  _BYTE v51[64]; // [rsp+F0h] [rbp-C8h] BYREF
  _BYTE v52[136]; // [rsp+130h] [rbp-88h] BYREF

  if ( byte_14003BA60 == 0 )
    return 0;
  sub_1400086F0(&v38, 15, 0);
  sub_140008740(&v43);
  sub_140009520(v44);
  for ( i = 0; i < 7; v44[v5] ^= 100 * i )
    v5 = (int)i++;
  sub_140009530(v47);
  for ( j = 0; j < 0xE; v47[v6] ^= (j & 0xD8) * (j & 0x27 ^ 0x27) + (j & 0x27) * (j | 0x27) )
    v6 = (int)j++;
  v7 = sub_140002070((__int64)v52, v47);
  v8 = sub_140002070(v7, &byte_14003BA60);
  v9 = (_BYTE *)sub_140002070(v8, v44);
  v10 = 1;
  v11 = 0;
  v12 = -1;
  do
  {
    v13 = v9;
    if ( v10 >= 0xAu )
    {
      v13 = v9 + 1;
      *v9 = v10 / 0xAu + 48;
    }
    *v13 = (v10 % 0xAu) ^ 0x30;
    v13[1] = 0;
    if ( (sub_140008580((__int64)v52, v13 + 1 - v52, &v42, &v48) & 1) == 0 )
    {
      v14 = 2;
      continue;
    }
    if ( (unsigned int)sub_140001040(v42, &v49, (__int64 *)&v38, &v43) == 0 )
    {
      sub_140009550(v41);
      for ( k = 0; k < 5; v41[v15] ^= (k & 0x1F ^ 0x1F) * (k & 0xE0) + (k & 0x1F) * (k | 0x1F) )
        v15 = (int)k++;
      v16 = sub_140006B50(&v38, (__int64)v41);
      v12 = (int)sub_140009560(v16);
      sub_140009570(v40);
      for ( m = 0; m < 5; v40[v17] ^= (m & 0x58 ^ 0x58) * (m & 0xA7) + (m & 0x58) * (m | 0x58) )
        v17 = (int)m++;
      v18 = (_QWORD *)sub_140006B50(&v38, (__int64)v40);
      v11 = sub_140008790(v18);
      sub_140009580(&v37);
      for ( n = 0; n == 0; n = 1 )
      {
        nullsub_1();
        nullsub_1();
        v37 = (-2 - ((~v37 | 0x3A72144D) + v37)) & (v37 | 0x3A72144D);
      }
      if ( v12 == v37 )
      {
        v14 = 2;
        continue;
      }
      switch ( v12 )
      {
        case 0:
          sub_140009620(v39);
          for ( ii = 0;
                ii < 5;
                v39[v19] = ~(v39[v19] & (80 * ii)) & (v39[v19] + (v39[v19] ^ (80 * ii)) - (~(80 * ii) & v39[v19])) )
          {
            nullsub_1();
            nullsub_1();
            v19 = (int)ii++;
          }
          v20 = (_QWORD *)sub_140006B50(&v38, (__int64)v39);
          v21 = sub_140008790(v20);
          v22 = sub_140009590(v21, 0);
          sub_140009630(v22, v11);
          sub_14002E0B0(v22);
          break;
        case 2:
          sub_140009EC0(v11);
          break;
        case 3:
          sub_14000A220(v46);
          for ( jj = 0; jj < 0xB; v46[v23] ^= 15 * (_BYTE)jj )
            v23 = (int)jj++;
          v24 = (_QWORD *)sub_140006B50(&v38, (__int64)v46);
          v25 = sub_140008790(v24);
          sub_14000A240(v11, v25);
          break;
        case 4:
          sub_14000B0C0(v45);
          for ( kk = 0; kk < 0xB; v45[v26] ^= 72 * (_BYTE)kk )
            v26 = (int)kk++;
          v27 = (_QWORD *)sub_140006B50(&v38, (__int64)v45);
          v28 = sub_140008790(v27);
          sub_14000B0E0(v11, v28);
          break;
        default:
          break;
      }
    }
    if ( v42 != nullptr )
      sub_140001C10(v42);
    v42 = nullptr;
    ++v10;
    sub_140001000(&v43);
    v14 = 0;
  }
  while ( v14 == 0 );
  sub_140002F90((__int64)v50, 0);
  sub_14001D5E0(v50);
  sub_14001DB30(v50);
  sub_14001DB00(v50);
  sub_140003A40((__int64)v50);
  sub_140002F90((__int64)v51, 0);
  if ( (a1 & 1) != 0 )
    sub_140028FB0(v51);
  sub_140028DF0(v51);
  sub_140003A40((__int64)v51);
  if ( v12 == 5 )
  {
    if ( a2 != 0 && v11 != 0 )
      sub_14000B910(v11, a2);
    if ( v42 != nullptr )
      sub_140001C10(v42);
    v42 = nullptr;
    sub_140001000(&v43);
  }
  sub_1400087A0(&v43);
  return 1;
}


// ---- sub_140008DF0 @ 0x140008df0 ----
__int64 __fastcall sub_140008DF0(_BYTE *a1)
{
  __int64 v2; // rax
  __int64 v3; // rax
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v6; // rdi
  __int64 v7; // rax
  __int64 v8; // rax
  unsigned int v9; // ebx
  __int64 v10; // rax
  _QWORD *v11; // rax
  __int64 v12; // rax
  bool v13; // cl
  bool v14; // dl
  char v15; // bl
  __int64 v16; // rbx
  int v17; // eax
  unsigned __int64 n; // rbx
  bool v19; // bp
  bool v20; // r14
  unsigned __int64 jj; // rsi
  bool v22; // bl
  bool v23; // di
  __int64 *v24; // rsi
  __int64 v25; // rdi
  int v26; // r9d
  unsigned __int64 mm; // rbx
  bool v28; // bp
  bool v29; // r14
  __int64 v31; // [rsp+20h] [rbp-168h]
  __int64 v32; // [rsp+28h] [rbp-160h]
  char v33; // [rsp+30h] [rbp-158h]
  int nn; // [rsp+38h] [rbp-150h]
  int kk; // [rsp+3Ch] [rbp-14Ch]
  int ii; // [rsp+40h] [rbp-148h]
  unsigned int i; // [rsp+44h] [rbp-144h]
  unsigned int j; // [rsp+48h] [rbp-140h]
  unsigned int k; // [rsp+4Ch] [rbp-13Ch]
  unsigned int m; // [rsp+50h] [rbp-138h]
  int v41; // [rsp+54h] [rbp-134h] BYREF
  int v42; // [rsp+58h] [rbp-130h] BYREF
  int v43; // [rsp+5Ch] [rbp-12Ch] BYREF
  char v44; // [rsp+63h] [rbp-125h] BYREF
  char v45; // [rsp+64h] [rbp-124h] BYREF
  char v46; // [rsp+65h] [rbp-123h] BYREF
  _BYTE v47[5]; // [rsp+66h] [rbp-122h] BYREF
  _BYTE v48[5]; // [rsp+6Bh] [rbp-11Dh] BYREF
  char *v49; // [rsp+70h] [rbp-118h] BYREF
  _QWORD *v50; // [rsp+78h] [rbp-110h] BYREF
  unsigned __int64 v51; // [rsp+80h] [rbp-108h] BYREF
  int v52; // [rsp+8Ch] [rbp-FCh]
  int v53; // [rsp+90h] [rbp-F8h]
  int v54; // [rsp+94h] [rbp-F4h]
  __int64 v55; // [rsp+98h] [rbp-F0h] BYREF
  __int64 v56; // [rsp+A0h] [rbp-E8h]
  char v57[11]; // [rsp+B7h] [rbp-D1h] BYREF
  char v58[14]; // [rsp+C2h] [rbp-C6h] BYREF
  __int64 v59; // [rsp+D0h] [rbp-B8h]
  __int64 v60; // [rsp+D8h] [rbp-B0h]
  __int64 v61; // [rsp+E0h] [rbp-A8h]
  _QWORD *v62; // [rsp+E8h] [rbp-A0h]
  _QWORD v63[2]; // [rsp+F0h] [rbp-98h] BYREF
  __int64 v64; // [rsp+100h] [rbp-88h] BYREF
  unsigned __int64 v65; // [rsp+108h] [rbp-80h] BYREF
  _BYTE v66[120]; // [rsp+110h] [rbp-78h] BYREF

  sub_1400086F0(&v51, 15, 0);
  sub_140008740(&v50);
  sub_140002050((unsigned __int8 *)&v55, 0, 0x18u);
  sub_1400087B0((__int64)&v55);
  sub_14000C4B0(v57);
  for ( i = 0; i < 0xB; v57[v2] ^= (_BYTE)i << 6 )
    v2 = (int)i++;
  sub_14000C4D0(v58);
  for ( j = 0; j < 0xE; v58[v3] ^= 3 * j )
    v3 = (int)j++;
  v4 = sub_140002070((__int64)v66, v58);
  v5 = sub_140002070(v4, &byte_14003BA60);
  v6 = sub_140002070(v5, v57);
  while ( (sub_140008580((__int64)v66, v6 - (_QWORD)v66, &v49, &v64) & 1) != 0 )
  {
    if ( (unsigned int)sub_140001040(v49, &v65, (__int64 *)&v51, &v50) != 0 )
    {
      sub_14002E0B0(v49);
      break;
    }
    sub_14000C4F0(v48);
    for ( k = 0; k < 5; v48[v7] ^= 121 * (_BYTE)k )
    {
      nullsub_1();
      nullsub_1();
      v7 = (int)k++;
    }
    v8 = sub_140006B50(&v51, (__int64)v48);
    v9 = (int)sub_140009560(v8);
    sub_14000C500(v47);
    for ( m = 0; ; v47[v10] ^= 52 * (_BYTE)m )
    {
      nullsub_1();
      nullsub_1();
      if ( m >= 5 )
        break;
      v10 = (int)m++;
    }
    v11 = (_QWORD *)sub_140006B50(&v51, (__int64)v47);
    v12 = sub_140008790(v11);
    v13 = v9 == 1;
    v14 = v9 <= 1;
    v15 = 0;
    if ( v14 )
    {
      if ( v13 )
      {
        v16 = v12;
        sub_1400087D0(*a1 & 1, 0);
        v12 = v16;
      }
      sub_14000B910(v12, &v55);
      v15 = 1;
    }
    sub_14002E0B0(v49);
    v49 = nullptr;
    sub_140001000(&v50);
    if ( (v15 & 1) != 0 )
    {
      v63[0] = -3000000000LL;
      v62 = v63;
      v54 = 0;
      for ( n = 0; ; ++n )
      {
        v19 = n < qword_14003BB50;
        if ( n >= qword_14003BB50 )
          break;
        v20 = *(_DWORD *)(qword_14003BB58 + 8 * n) == 1475872016;
        if ( *(_DWORD *)(qword_14003BB58 + 8 * n) == 1475872016 )
          sub_14002F100(*(_DWORD *)(8 * n + qword_14003BB58 + 4), 2, v54, (_DWORD)v62, v31, v32, v33);
        if ( v20 )
          break;
      }
      if ( !v19 )
      {
        sub_14000C070(&v46, &v43);
        for ( ii = 0; ii == 0; ii = 1 )
          v43 ^= 0x71D3C96Au;
      }
      v17 = 0;
    }
    else
    {
      v17 = 2;
    }
    if ( v17 != 0 )
      break;
  }
  if ( v55 != v56 )
  {
    v63[1] = 0;
    v53 = 0;
    v52 = 0;
    v61 = v55;
    v60 = (v56 - v55) >> 3;
    for ( jj = 0; ; ++jj )
    {
      v22 = jj < qword_14003BB50;
      if ( jj >= qword_14003BB50 )
        break;
      v23 = *(_DWORD *)(qword_14003BB58 + 8 * jj) == -1141078964;
      if ( *(_DWORD *)(qword_14003BB58 + 8 * jj) == -1141078964 )
        sub_14002F100(*(_DWORD *)(8 * jj + qword_14003BB58 + 4), 5, v60, v61, v52, v53, 0);
      if ( v23 )
        break;
    }
    if ( !v22 )
    {
      sub_14000C070(&v44, &v41);
      for ( kk = 0; kk == 0; kk = 1 )
        v41 ^= 0x71D3C96Au;
    }
    v24 = (__int64 *)sub_140009490(&v55);
    v25 = sub_1400094A0(&v55);
    while ( v24 != (__int64 *)v25 )
    {
      v59 = *v24;
      for ( mm = 0; ; ++mm )
      {
        v28 = mm < qword_14003BB50;
        if ( mm >= qword_14003BB50 )
          break;
        v29 = *(_DWORD *)(qword_14003BB58 + 8 * mm) == -1825720177;
        if ( *(_DWORD *)(qword_14003BB58 + 8 * mm) == -1825720177 )
          sub_14002F100(*(_DWORD *)(8 * mm + qword_14003BB58 + 4), 1, v59, v26, v31, v32, v33);
        if ( v29 )
          break;
      }
      if ( !v28 )
      {
        sub_14000C070(&v45, &v42);
        for ( nn = 0; nn == 0; nn = 1 )
          v42 ^= 0x71D3C96Au;
      }
      ++v24;
    }
  }
  sub_1400094B0(&v55);
  sub_1400087A0(&v50);
  return 0;
}


// ---- sub_140009490 @ 0x140009490 ----
__int64 __fastcall sub_140009490(__int64 a1)
{
  return *(_QWORD *)a1;
}


// ---- sub_1400094A0 @ 0x1400094a0 ----
__int64 __fastcall sub_1400094A0(__int64 a1)
{
  return *(_QWORD *)(a1 + 8);
}


// ---- sub_1400094B0 @ 0x1400094b0 ----
__int64 __fastcall sub_1400094B0(__int64 *a1)
{
  __int64 v2; // rcx
  __int64 result; // rax

  v2 = *a1;
  if ( v2 != 0 && v2 != a1[1] )
  {
    result = sub_140001C10(v2);
    *(_OWORD *)a1 = 0;
    a1[2] = 0;
  }
  return result;
}


// ---- sub_1400094E0 @ 0x1400094e0 ----
__int64 __fastcall sub_1400094E0(__int64 a1)
{
  return a1 & 0x7FFFFFFFFFFFLL;
}


// ---- sub_1400094F0 @ 0x1400094f0 ----
__int64 sub_1400094F0()
{
  return 0;
}


// ---- sub_140009500 @ 0x140009500 ----
bool __fastcall sub_140009500(_QWORD *a1, _QWORD *a2)
{
  return *a1 != *a2;
}


// ---- sub_140009510 @ 0x140009510 ----
__int64 __fastcall sub_140009510(__int64 a1)
{
  __int64 result; // rax

  result = *(_QWORD *)(*(_QWORD *)a1 + 8LL);
  *(_QWORD *)a1 = result;
  return result;
}


// ---- sub_140009520 @ 0x140009520 ----
void __fastcall sub_140009520(_DWORD *a1)
{
  *(_DWORD *)((char *)a1 + 3) = -1134197515;
  *a1 = -178734270;
}


// ---- sub_140009530 @ 0x140009530 ----
__int64 __fastcall sub_140009530(_QWORD *a1)
{
  *(_QWORD *)((char *)a1 + 6) = 0x22C6BAC8ED304C4ELL;
  *a1 = 0x4C4E99B0F9162D46LL;
  return 0x4C4E99B0F9162D46LL;
}


// ---- sub_140009550 @ 0x140009550 ----
void __fastcall sub_140009550(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = -101;
  *(_DWORD *)a1 = 422397803;
}


// ---- sub_140009560 @ 0x140009560 ----
double __fastcall sub_140009560(__int64 a1)
{
  return *(double *)a1;
}


// ---- sub_140009570 @ 0x140009570 ----
void __fastcall sub_140009570(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = -72;
  *(_DWORD *)a1 = 24957244;
}


// ---- sub_140009580 @ 0x140009580 ----
void __fastcall sub_140009580(_DWORD *a1)
{
  *a1 = 980554824;
}


// ---- sub_140009590 @ 0x140009590 ----
__int64 __fastcall sub_140009590(__int64 a1, __int64 *a2)
{
  __int64 v4; // rbx
  unsigned __int64 v5; // rcx
  unsigned __int64 v7; // rcx
  __int64 v8; // r14
  __int64 v9; // rax

  v4 = -1;
  v5 = -3;
  do
    v5 += 3LL;
  while ( *(_BYTE *)(a1 + v4++ + 1) != 0 );
  v7 = v5 >> 2;
  if ( *(_BYTE *)(a1 + v4 - 1) == 61 )
  {
    if ( *(_BYTE *)(a1 + v4 - 2) == 61 )
    {
      if ( *(_BYTE *)(a1 + v4 - 3) == 61 )
        v7 -= 3LL;
      else
        v7 -= 2LL;
    }
    else
    {
      --v7;
    }
  }
  v8 = sub_14002E070(v7 + 1);
  v9 = sub_14002D560(a1, v4, v8);
  *(_BYTE *)(v8 + v9) = 0;
  if ( a2 != nullptr )
    *a2 = v9;
  return v8;
}


// ---- sub_140009620 @ 0x140009620 ----
void __fastcall sub_140009620(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = -112;
  *(_DWORD *)a1 = 631095614;
}


// ---- sub_140009630 @ 0x140009630 ----
bool __fastcall sub_140009630(char *a1, __int64 *a2)
{
  char *v3; // r12
  __int64 v4; // rdi
  bool v5; // bp
  __int64 v7; // rbx
  int v8; // r14d
  __int16 *v9; // r13
  __int64 v10; // rax
  _QWORD *v11; // rax
  __int64 v12; // rax
  __int64 v13; // rax
  _QWORD *v14; // rax
  __int64 v15; // rax
  char *v16; // rbx
  __int64 v17; // rax
  __int64 *v18; // r15
  __int64 v19; // rax
  __int64 v20; // rax
  int v21; // r14d
  __int64 v22; // rax
  _QWORD *v23; // rax
  int v24; // ecx
  __int64 v25; // rax
  __int64 v26; // rax
  __int64 v27; // rdx
  _BYTE *v28; // rax
  _WORD *v29; // rax
  __int16 *v30; // rbx
  _QWORD *v31; // rax
  __int64 v32; // rax
  unsigned __int64 v33; // rcx
  unsigned __int64 v34; // r13
  unsigned __int64 v35; // r15
  unsigned __int64 v36; // r12
  __int64 v37; // rbx
  unsigned __int64 v38; // rax
  unsigned __int64 v39; // r14
  unsigned __int64 v40; // rbx
  __int64 v41; // rbx
  _QWORD *v42; // r14
  __int64 v43; // r15
  int i; // [rsp+3Ch] [rbp-17Ch]
  unsigned int j; // [rsp+40h] [rbp-178h]
  int k; // [rsp+44h] [rbp-174h]
  unsigned int m; // [rsp+48h] [rbp-170h]
  unsigned int n; // [rsp+4Ch] [rbp-16Ch]
  unsigned int ii; // [rsp+50h] [rbp-168h]
  unsigned int jj; // [rsp+54h] [rbp-164h]
  unsigned __int64 v51; // [rsp+58h] [rbp-160h] BYREF
  unsigned __int64 v52; // [rsp+60h] [rbp-158h]
  unsigned __int64 v53; // [rsp+68h] [rbp-150h]
  int v54; // [rsp+74h] [rbp-144h] BYREF
  __int64 v55; // [rsp+78h] [rbp-140h] BYREF
  _BYTE v56[5]; // [rsp+81h] [rbp-137h] BYREF
  _BYTE v57[5]; // [rsp+86h] [rbp-132h] BYREF
  _BYTE v58[5]; // [rsp+8Bh] [rbp-12Dh] BYREF
  _BYTE v59[5]; // [rsp+90h] [rbp-128h] BYREF
  _BYTE v60[5]; // [rsp+95h] [rbp-123h] BYREF
  _BYTE v61[6]; // [rsp+9Ah] [rbp-11Eh] BYREF
  unsigned __int64 v62; // [rsp+A0h] [rbp-118h] BYREF
  __int64 v63; // [rsp+A8h] [rbp-110h] BYREF
  __int64 v64; // [rsp+B0h] [rbp-108h] BYREF
  int v65; // [rsp+B8h] [rbp-100h]
  int v66; // [rsp+BCh] [rbp-FCh]
  __int64 v67; // [rsp+C0h] [rbp-F8h]
  __int64 v68; // [rsp+C8h] [rbp-F0h] BYREF
  unsigned __int64 v69; // [rsp+D0h] [rbp-E8h]
  __int64 v70; // [rsp+D8h] [rbp-E0h]
  __int64 v71; // [rsp+E0h] [rbp-D8h]
  __int16 *v72; // [rsp+E8h] [rbp-D0h]
  __int16 *v73; // [rsp+F0h] [rbp-C8h]
  __int64 v74; // [rsp+F8h] [rbp-C0h]
  char *v75; // [rsp+100h] [rbp-B8h]
  __int64 v76; // [rsp+108h] [rbp-B0h]
  __int64 v77; // [rsp+110h] [rbp-A8h] BYREF
  __int64 v78; // [rsp+118h] [rbp-A0h] BYREF
  __int64 v79; // [rsp+120h] [rbp-98h] BYREF
  __int64 v80; // [rsp+128h] [rbp-90h] BYREF
  _BYTE v81[136]; // [rsp+130h] [rbp-88h] BYREF

  v3 = a1;
  v4 = sub_14000BF10(a1);
  v5 = false;
  while ( a2 != nullptr )
  {
    v7 = sub_14000BF30(a2[2], &v68);
    v8 = sub_140031280(0, v7, v68, 0, 0, (__int64)&v62);
    sub_14000BFD0(&v54);
    for ( i = 0; i == 0; i = 1 )
      v54 ^= 0x2E42BCCEu;
    if ( v8 == v54 )
    {
      v9 = (__int16 *)sub_14002E070(saturated_mul(2u, v62));
      if ( (int)sub_140031280(0, v7, v68, (_DWORD)v9, v62, (__int64)&v62) >= 0 )
      {
        sub_14002E0B0(v7);
        v64 = sub_1400094E0(*a2);
        v80 = sub_1400094F0();
        while ( sub_140009500(&v64, &v80) )
        {
          v55 = *(_QWORD *)sub_140009490((__int64)&v64);
          sub_14000BFE0(v60);
          for ( j = 0; j < 5; v60[v10] ^= (j & 0x9A) * (j & 0x65 ^ 0x65) + (j & 0x65) * (j | 0x65) )
            v10 = (int)j++;
          v11 = (_QWORD *)sub_140006B50(&v55, (__int64)v60);
          v12 = sub_140008790(v11);
          v72 = (__int16 *)sub_14000BF30(v12, &v79);
          sub_14000BFF0(v59);
          for ( k = 0;
                (unsigned int)k < 5;
                v59[v13] = ~(v59[v13] & (36 * k)) & (v59[v13] + (v59[v13] ^ (36 * k)) - (~(36 * k) & v59[v13])) )
          {
            nullsub_1();
            nullsub_1();
            v13 = k;
            k = (k ^ 1) + 2 * (k & 1);
          }
          v14 = (_QWORD *)sub_140006B50(&v55, (__int64)v59);
          v15 = sub_140008790(v14);
          v16 = (char *)sub_140009590(v15, &v78);
          sub_14000C000(v58);
          for ( m = 0; m < 5; v58[v17] ^= 93 * (_BYTE)m )
            v17 = (int)m++;
          v18 = (__int64 *)sub_140006B50(&v55, (__int64)v58);
          sub_14000C010(v61);
          for ( n = 0; ; v61[v19] ^= 24 * (_BYTE)n )
          {
            nullsub_1();
            nullsub_1();
            if ( n >= 6 )
              break;
            v19 = (int)n++;
          }
          v20 = sub_140006B50(&v55, (__int64)v61);
          v21 = (int)sub_140009560(v20);
          sub_14000C020(v57);
          for ( ii = 0; ii < 5; v57[v22] ^= 85 * (_BYTE)ii )
            v22 = (int)ii++;
          v23 = (_QWORD *)sub_140006B50(&v55, (__int64)v57);
          v24 = 0;
          if ( v23 != nullptr )
            LOBYTE(v24) = sub_140008750(v23);
          v65 = v24;
          sub_14000C030(v56);
          for ( jj = 0; jj < 5; v56[v25] ^= (jj & 0xEF) * (jj & 0x10 ^ 0x10) + (jj & 0x10) * (jj | 0x10) )
            v25 = (int)jj++;
          v26 = sub_140006B50(&v55, (__int64)v56);
          v27 = 0;
          if ( v26 != 0 )
            v27 = (unsigned int)(int)sub_140009560(v26);
          v70 = v27;
          v71 = sub_14002E070(v78 + v4 + 2);
          v28 = (_BYTE *)sub_140002070(v71, v3);
          *v28 = 47;
          sub_140002070((__int64)(v28 + 1), v16);
          sub_14002E0B0(v16);
          v67 = sub_14002E070(saturated_mul(2u, v79 + v62 + 1));
          v29 = (_WORD *)sub_140004710(v67, v9);
          *v29 = 92;
          v30 = v72;
          sub_140004710((__int64)(v29 + 1), v72);
          sub_14002E0B0(v30);
          sub_140002050((unsigned __int8 *)&v51, 0, 0x18u);
          sub_1400087B0((__int64)&v51);
          if ( v18 != nullptr )
          {
            v63 = sub_1400094E0(*v18);
            v77 = sub_1400094F0();
            while ( sub_140009500(&v63, &v77) )
            {
              v73 = v9;
              v74 = v4;
              v31 = (_QWORD *)sub_140009490((__int64)&v63);
              v32 = sub_140008790(v31);
              v76 = sub_14000BF30(v32, 0);
              v33 = v52;
              v34 = (__int64)(v52 - v51) >> 3;
              v35 = v51;
              if ( v52 == v53 )
              {
                v69 = v52;
                v66 = v21;
                v75 = v3;
                v36 = v34 + 1;
                if ( ((unsigned __int64)((__int64)(v53 - v51) >> 3) >> 1) + ((__int64)(v53 - v51) >> 3) > v34 + 1 )
                  v36 = ((unsigned __int64)((__int64)(v53 - v51) >> 3) >> 1) + ((__int64)(v53 - v51) >> 3);
                v37 = (__int64)(v52 - v51) >> 3;
                v38 = sub_140001B80(8 * v36);
                v39 = v38;
                if ( v51 != 0 )
                {
                  sub_140001D60(v38, v51, v52 - v51);
                  sub_140001C10(v51);
                }
                v51 = v39;
                v52 = 8 * v37 + v39;
                v53 = 8 * v36 + v39;
                v3 = v75;
                v21 = v66;
                v33 = v69;
              }
              v40 = v33 - v35;
              if ( (__int64)(v33 - v35) >> 3 < v34 )
                sub_140001D60(v51 + v40 + 8, v51 + v40, 8 * v34 + v35 - v33);
              *(_QWORD *)(v51 + v40) = v76;
              v52 += 8LL;
              sub_140009510((__int64)&v63);
              v4 = v74;
              v9 = v73;
            }
          }
          sub_140002F90((__int64)v81, 0);
          v41 = v71;
          v5 = (sub_140016DD0((unsigned int)v81, v71, v67, (unsigned int)&v51, v70, v21, v65 & 1) & 1 | v5) != 0;
          sub_140003A40((__int64)v81);
          v42 = (_QWORD *)sub_140009490((__int64)&v51);
          v43 = sub_1400094A0((__int64)&v51);
          while ( v42 != (_QWORD *)v43 )
            sub_14002E0B0(*v42++);
          sub_140001C10(v67);
          sub_140001C10(v41);
          sub_1400094B0((__int64 *)&v51);
          sub_140009510((__int64)&v64);
        }
        sub_140001C10(v9);
      }
      else
      {
        sub_14002E0B0(v7);
        sub_140001C10(v9);
      }
    }
    else
    {
      sub_14002E0B0(v7);
    }
    a2 = (__int64 *)a2[1];
  }
  return v5;
}


// ---- sub_140009EC0 @ 0x140009ec0 ----
char __fastcall sub_140009EC0(__int64 *a1)
{
  __int64 v3; // rax
  _QWORD *v4; // rax
  __int64 v5; // rax
  _WORD *v6; // rdi
  int (__fastcall *v7)(__int64, __int64 *); // rax
  int v8; // eax
  __int64 v9; // rax
  _QWORD *v10; // rax
  __int64 v11; // rax
  __int64 v12; // rbx
  int v13; // r9d
  __int64 v14; // r14
  __int64 v15; // rax
  _QWORD *v16; // rax
  __int64 v17; // rax
  __int64 v18; // r15
  unsigned __int64 j; // r14
  bool v20; // bp
  bool v21; // r15
  __int64 v22; // [rsp+20h] [rbp-C8h]
  __int64 v23; // [rsp+28h] [rbp-C0h]
  int k; // [rsp+30h] [rbp-B8h]
  unsigned int i; // [rsp+34h] [rbp-B4h]
  int v26; // [rsp+38h] [rbp-B0h] BYREF
  char v27; // [rsp+3Fh] [rbp-A9h] BYREF
  _BYTE v28[5]; // [rsp+40h] [rbp-A8h] BYREF
  _BYTE v29[5]; // [rsp+45h] [rbp-A3h] BYREF
  _BYTE v30[6]; // [rsp+4Ah] [rbp-9Eh] BYREF
  __int64 v31; // [rsp+50h] [rbp-98h] BYREF
  __int64 v32; // [rsp+58h] [rbp-90h] BYREF
  unsigned __int64 v33; // [rsp+60h] [rbp-88h] BYREF
  _BYTE v34[8]; // [rsp+68h] [rbp-80h] BYREF
  _BYTE v35[120]; // [rsp+70h] [rbp-78h] BYREF

  sub_140002F90((__int64)v35, 0);
  while ( a1 != nullptr )
  {
    v32 = *a1;
    sub_14000C040(v29);
    LODWORD(v23) = 0;
    while ( (unsigned int)v23 < 5 )
    {
      nullsub_1();
      nullsub_1();
      v3 = (int)v23;
      LODWORD(v23) = v23 + 1;
      v29[v3] ^= 73 * (_BYTE)v23;
    }
    v4 = (_QWORD *)sub_140006B50(&v32, (__int64)v29);
    v5 = sub_140008790(v4);
    v6 = (_WORD *)sub_14000BF30(v5, v34);
    v31 = 0;
    if ( *v6 == 92
      || ((v7 = (int (__fastcall *)(__int64, __int64 *))sub_14002FDC0(qword_14003BA38, 591590463)) != nullptr
       && v7(0x80000000LL, &v31) >= 0
        ? (v8 = 0)
        : (sub_14002E0B0(v6), v8 = 4),
          v8 == 0) )
    {
      sub_14000C050(v30);
      for ( i = 0; i < 6; v30[v9] ^= (i & 8 ^ 8) * (i & 0xF7) + (i & 8) * (i | 8) )
        v9 = (int)i++;
      v10 = (_QWORD *)sub_140006B50(&v32, (__int64)v30);
      v11 = sub_140008790(v10);
      v12 = sub_14000BF30(v11, 0);
      v14 = sub_14002D260(v6, v12, &v33, v31);
      if ( v14 != 0 )
      {
        sub_14000C060(v28);
        HIDWORD(v23) = 0;
        while ( HIDWORD(v23) < 5 )
        {
          v15 = SHIDWORD(v23);
          ++HIDWORD(v23);
          v28[v15] ^= 65 * BYTE4(v23);
        }
        v16 = (_QWORD *)sub_140006B50(&v32, (__int64)v28);
        v17 = sub_140008790(v16);
        v18 = sub_140009590(v17, nullptr);
        sub_140003370((__int64)v35, v18, v14, v33);
        sub_14002E0B0(v18);
        sub_140001C10(v14);
      }
      if ( v31 != 0 )
      {
        for ( j = 0; ; ++j )
        {
          v20 = j < qword_14003BB50;
          if ( j >= qword_14003BB50 )
            break;
          v21 = *(_DWORD *)(qword_14003BB58 + 8 * j) == -1825720177;
          if ( *(_DWORD *)(qword_14003BB58 + 8 * j) == -1825720177 )
            sub_14002F100(*(_DWORD *)(8 * j + qword_14003BB58 + 4), 1, v31, v13, v22, v23, k);
          if ( v21 )
            break;
        }
        if ( !v20 )
        {
          sub_14000C070(&v27, &v26);
          for ( k = 0; k == 0; k = 1 )
            v26 ^= 0x71D3C96Au;
        }
      }
      sub_14002E0B0(v12);
      sub_14002E0B0(v6);
    }
    a1 = (__int64 *)a1[1];
  }
  return sub_140003A40((__int64)v35) & 1;
}


// ---- sub_14000A220 @ 0x14000a220 ----
__int64 __fastcall sub_14000A220(__int64 a1)
{
  *(_QWORD *)a1 = 0x170029255959666ALL;
  *(_DWORD *)(a1 + 7) = -1511659241;
  return 0x170029255959666ALL;
}


// ---- sub_14000A240 @ 0x14000a240 ----
bool __fastcall sub_14000A240(_QWORD *a1, __int64 *a2)
{
  __int64 *v2; // r14
  _QWORD *v3; // rsi
  unsigned __int64 v4; // r13
  __int64 *i; // rax
  __int64 v6; // r15
  __int64 v7; // rsi
  __int64 v8; // rdi
  __int64 v9; // r15
  __int64 v10; // rax
  _QWORD *v11; // rax
  int v12; // ebx
  __int64 v13; // rax
  _QWORD *v14; // rax
  int v15; // edi
  __int64 v16; // rax
  _QWORD *v17; // rax
  bool v18; // bp
  __int64 v19; // rax
  _QWORD *v20; // rcx
  int v21; // r9d
  bool v22; // al
  unsigned __int64 v23; // rdi
  _WORD *v24; // rbx
  unsigned int v25; // eax
  char v26; // cl
  unsigned int v27; // edx
  char v28; // dl
  char v29; // al
  unsigned __int8 v30; // al
  bool v31; // bp
  __int64 v32; // rax
  _QWORD *v33; // rax
  __int64 v34; // rax
  __int64 v35; // rdi
  int v36; // ebx
  __int64 v37; // r12
  __int64 v38; // rax
  _QWORD *v39; // rax
  __int64 v40; // rax
  __int64 v41; // rax
  _QWORD *v42; // rax
  __int64 v43; // rax
  __int64 v44; // rax
  _QWORD *v45; // rax
  __int64 v46; // rax
  __int64 v47; // rax
  _QWORD *v48; // rax
  __int64 v49; // rax
  __int64 v50; // rax
  __int64 v51; // rsi
  _QWORD *v52; // rax
  bool v53; // r15
  bool v54; // r15
  __int64 v55; // rax
  _QWORD *v56; // rax
  bool v57; // r13
  bool v58; // r13
  __int64 v59; // rax
  _QWORD *v60; // rax
  bool v61; // r14
  bool v62; // r14
  __int64 v63; // rax
  _QWORD *v64; // rax
  bool v65; // di
  bool v66; // di
  __int64 v67; // rax
  _QWORD *v68; // rax
  bool v69; // bl
  _BYTE *v70; // rax
  char v71; // r13
  char v72; // r14
  char v73; // di
  __int64 v74; // rax
  __int64 v75; // rax
  unsigned __int64 v76; // r9
  __int64 v77; // r8
  _QWORD *v78; // rdi
  __int64 v79; // rbx
  __int64 v80; // rax
  unsigned __int8 v81; // dl
  __int64 v82; // rax
  unsigned int k; // [rsp+38h] [rbp-2A0h]
  unsigned int m; // [rsp+3Ch] [rbp-29Ch]
  unsigned int n; // [rsp+40h] [rbp-298h]
  unsigned int ii; // [rsp+44h] [rbp-294h]
  int jj; // [rsp+48h] [rbp-290h]
  unsigned int kk; // [rsp+4Ch] [rbp-28Ch]
  unsigned int mm; // [rsp+50h] [rbp-288h]
  unsigned int nn; // [rsp+54h] [rbp-284h]
  unsigned int i1; // [rsp+58h] [rbp-280h]
  unsigned int i2; // [rsp+5Ch] [rbp-27Ch]
  unsigned int i3; // [rsp+60h] [rbp-278h]
  unsigned int i4; // [rsp+64h] [rbp-274h]
  unsigned int i5; // [rsp+68h] [rbp-270h]
  unsigned int i6; // [rsp+6Ch] [rbp-26Ch]
  unsigned int v98; // [rsp+70h] [rbp-268h]
  unsigned int i7; // [rsp+74h] [rbp-264h]
  unsigned int i8; // [rsp+78h] [rbp-260h]
  unsigned int j; // [rsp+7Ch] [rbp-25Ch]
  __int64 v102; // [rsp+80h] [rbp-258h] BYREF
  _BYTE v103[3]; // [rsp+89h] [rbp-24Fh] BYREF
  int v104; // [rsp+8Ch] [rbp-24Ch] BYREF
  _BYTE v105[4]; // [rsp+90h] [rbp-248h] BYREF
  _BYTE v106[4]; // [rsp+94h] [rbp-244h] BYREF
  _BYTE v107[4]; // [rsp+98h] [rbp-240h] BYREF
  _BYTE v108[4]; // [rsp+9Ch] [rbp-23Ch] BYREF
  __int64 v109; // [rsp+A0h] [rbp-238h] BYREF
  _BYTE v110[5]; // [rsp+AFh] [rbp-229h] BYREF
  _BYTE v111[5]; // [rsp+B4h] [rbp-224h] BYREF
  _BYTE v112[5]; // [rsp+B9h] [rbp-21Fh] BYREF
  _BYTE v113[5]; // [rsp+BEh] [rbp-21Ah] BYREF
  _BYTE v114[5]; // [rsp+C3h] [rbp-215h] BYREF
  __int64 v115; // [rsp+C8h] [rbp-210h] BYREF
  unsigned __int8 v116[7]; // [rsp+D2h] [rbp-206h] BYREF
  char v117[7]; // [rsp+D9h] [rbp-1FFh] BYREF
  __int64 v118; // [rsp+E0h] [rbp-1F8h]
  __int64 v119; // [rsp+E8h] [rbp-1F0h]
  __int64 v120; // [rsp+F0h] [rbp-1E8h]
  char *v121; // [rsp+F8h] [rbp-1E0h]
  _QWORD *v122; // [rsp+100h] [rbp-1D8h]
  unsigned __int64 v123; // [rsp+108h] [rbp-1D0h] BYREF
  unsigned __int8 v124[8]; // [rsp+110h] [rbp-1C8h] BYREF
  _BYTE v125[8]; // [rsp+118h] [rbp-1C0h] BYREF
  _BYTE v126[8]; // [rsp+120h] [rbp-1B8h] BYREF
  __int64 v127; // [rsp+128h] [rbp-1B0h] BYREF
  _BYTE v128[11]; // [rsp+131h] [rbp-1A7h] BYREF
  _BYTE v129[12]; // [rsp+13Ch] [rbp-19Ch] BYREF
  __int64 v130; // [rsp+148h] [rbp-190h]
  unsigned __int64 v131; // [rsp+150h] [rbp-188h]
  __int64 *v132; // [rsp+158h] [rbp-180h]
  _BYTE *v133; // [rsp+160h] [rbp-178h]
  _BYTE *v134; // [rsp+168h] [rbp-170h]
  _QWORD v135[6]; // [rsp+170h] [rbp-168h] BYREF
  unsigned __int8 v136[24]; // [rsp+1A0h] [rbp-138h] BYREF
  char v137; // [rsp+1B8h] [rbp-120h]
  _BYTE v138[64]; // [rsp+1C0h] [rbp-118h] BYREF
  _BYTE v139[16]; // [rsp+200h] [rbp-D8h] BYREF
  __int64 v140; // [rsp+210h] [rbp-C8h]
  unsigned __int8 v141[152]; // [rsp+240h] [rbp-98h] BYREF

  v2 = a2;
  v3 = a1;
  v4 = 0;
  for ( i = a2; i != nullptr; i = (__int64 *)i[1] )
    ++v4;
  v6 = 0;
  if ( v4 != 0 )
  {
    v122 = a1;
    v7 = sub_14002E070(saturated_mul(0x18u, v4));
    v8 = v7;
    do
    {
      sub_14000C080(v8);
      v8 += 24;
    }
    while ( v8 != 24 * v4 + v7 );
    v9 = 0;
    while ( v2 != nullptr )
    {
      v115 = *v2;
      sub_14000C090(v103);
      for ( j = 0; j < 3; v103[v10] ^= 126 * (_BYTE)j )
        v10 = (int)j++;
      v11 = (_QWORD *)sub_140006B50(&v115, (__int64)v103);
      v12 = sub_140008790(v11);
      sub_14000C0A0(v114);
      for ( k = 0; k < 5; v114[v13] ^= 57 * (_BYTE)k )
        v13 = (int)k++;
      v14 = (_QWORD *)sub_140006B50(&v115, (__int64)v114);
      v15 = sub_140008790(v14);
      sub_14000C0B0(v113);
      for ( m = 0; m < 5; v113[v16] ^= 114 * (_BYTE)m )
        v16 = (int)m++;
      v17 = (_QWORD *)sub_140006B50(&v115, (__int64)v113);
      v18 = false;
      if ( v17 != nullptr )
        v18 = sub_140008750(v17);
      sub_14000C0C0(v112);
      for ( n = 0; n < 5; v112[v19] ^= 49 * (_BYTE)n )
        v19 = (int)n++;
      v20 = (_QWORD *)sub_140006B50(&v115, (__int64)v112);
      v22 = false;
      if ( v20 != nullptr )
        v22 = sub_140008750(v20);
      LOBYTE(v21) = v18;
      sub_14000C0D0(24 * v9 + v7, v12, v15, v21, v22);
      v2 = (__int64 *)v2[1];
      ++v9;
    }
    v6 = v7;
    v3 = v122;
  }
  v23 = 0;
  v24 = v138;
  while ( v23 < 0x10 )
  {
    v25 = sub_140003050((unsigned int *)qword_14003BA50);
    v26 = v25;
    v27 = v25 % 0x24;
    if ( v25 % 0x24 < 0xA )
    {
      v30 = v27 + 48;
    }
    else
    {
      v28 = v27 - 10;
      v29 = 65;
      if ( (v26 & 1) == 0 )
        v29 = 97;
      v30 = v29 + v28;
    }
    *v24 = v30;
    ++v23;
    ++v24;
  }
  *v24 = 0;
  v134 = v138;
  v109 = sub_14000C0F0(v138);
  if ( v109 == 0 )
  {
    v133 = v138;
    v109 = sub_14000C110(v138);
  }
  v31 = false;
  while ( v3 != nullptr )
  {
    v102 = *v3;
    sub_14000C140(v111);
    for ( ii = 0; ii < 5; v111[v32] ^= 106 * (_BYTE)ii )
      v32 = (int)ii++;
    v33 = (_QWORD *)sub_140006B50(&v102, (__int64)v111);
    v34 = sub_140008790(v33);
    v35 = sub_14000BF30(v34, &v127);
    v36 = sub_140031280(0, v35, v127, 0, 0, (__int64)&v123);
    sub_14000C150(&v104);
    for ( jj = 0; ; jj = 1 )
    {
      nullsub_1();
      nullsub_1();
      if ( jj != 0 )
        break;
      v104 ^= 0x7382DE2Du;
    }
    if ( v36 == v104 )
    {
      v37 = sub_14002E070(saturated_mul(2u, v123));
      if ( (int)sub_140031280(0, v35, v127, v37, v123, (__int64)&v123) >= 0 )
      {
        sub_14002E0B0(v35);
        sub_14000C160(v110);
        for ( kk = 0; kk < 5; v110[v38] ^= 98 * (_BYTE)kk )
          v38 = (int)kk++;
        v39 = (_QWORD *)sub_140006B50(&v102, (__int64)v110);
        v40 = sub_140008790(v39);
        v121 = (char *)sub_140009590(v40, nullptr);
        sub_14000C170(v108);
        for ( mm = 0; ; v108[v41] ^= (mm & 0x1D ^ 0x1D) * (mm & 0xE2) + (mm & 0x1D) * (mm | 0x1D) )
        {
          nullsub_1();
          nullsub_1();
          if ( mm >= 4 )
            break;
          v41 = (int)mm++;
        }
        v42 = (_QWORD *)sub_140006B50(&v102, (__int64)v108);
        v120 = 0;
        if ( v42 != nullptr )
        {
          v43 = sub_140008790(v42);
          v120 = sub_14000BF30(v43, 0);
        }
        sub_14000C180(v107);
        for ( nn = 0; nn < 4; v107[v44] ^= 90 * (_BYTE)nn )
          v44 = (int)nn++;
        v45 = (_QWORD *)sub_140006B50(&v102, (__int64)v107);
        v119 = 0;
        if ( v45 != nullptr )
        {
          v46 = sub_140008790(v45);
          v119 = sub_14000BF30(v46, 0);
        }
        sub_14000C190(v106);
        for ( i1 = 0; i1 < 4; v106[v47] ^= 21 * (_BYTE)i1 )
          v47 = (int)i1++;
        v48 = (_QWORD *)sub_140006B50(&v102, (__int64)v106);
        v118 = 0;
        if ( v48 != nullptr )
        {
          v49 = sub_140008790(v48);
          v118 = sub_14000BF30(v49, 0);
        }
        sub_14000C1A0(v126);
        for ( i2 = 0; i2 < 8; v126[v50] ^= 78 * (_BYTE)i2 )
          v50 = (int)i2++;
        v122 = v3;
        v51 = v6;
        v52 = (_QWORD *)sub_140006B50(&v102, (__int64)v126);
        v53 = true;
        if ( v52 != nullptr )
          v53 = sub_140008750(v52);
        v54 = v53;
        sub_14000C1B0(v129);
        for ( i3 = 0; i3 < 0xC; v129[v55] ^= 13 * (_BYTE)i3 )
          v55 = (int)i3++;
        v131 = v4;
        v56 = (_QWORD *)sub_140006B50(&v102, (__int64)v129);
        v57 = true;
        if ( v56 != nullptr )
          v57 = sub_140008750(v56);
        v58 = v57;
        sub_14000C1D0(v125);
        for ( i4 = 0; i4 < 8; v125[v59] ^= 70 * (_BYTE)i4 )
        {
          nullsub_1();
          nullsub_1();
          v59 = (int)i4++;
        }
        v60 = (_QWORD *)sub_140006B50(&v102, (__int64)v125);
        v61 = true;
        if ( v60 != nullptr )
          v61 = sub_140008750(v60);
        v62 = v61;
        sub_14000C1E0(v105);
        for ( i5 = 0; ; v105[v63] ^= 5 * (_BYTE)i5 )
        {
          nullsub_1();
          nullsub_1();
          if ( i5 >= 4 )
            break;
          v63 = (int)i5++;
        }
        v64 = (_QWORD *)sub_140006B50(&v102, (__int64)v105);
        v65 = false;
        if ( v64 != nullptr )
          v65 = sub_140008750(v64);
        v66 = v65;
        sub_14000C1F0(v128);
        for ( i6 = 0; i6 < 0xB; v128[v67] ^= (i6 & 0x3E ^ 0x3E) * (i6 & 0xC1) + (i6 & 0x3E) * (i6 | 0x3E) )
          v67 = (int)i6++;
        v68 = (_QWORD *)sub_140006B50(&v102, (__int64)v128);
        v69 = true;
        if ( v68 != nullptr )
          v69 = sub_140008750(v68);
        v70 = nullptr;
        if ( v109 != 0 )
          v70 = v138;
        v135[0] = v70;
        v135[1] = v121;
        v135[2] = v120;
        v130 = v37;
        v135[3] = v37;
        v135[4] = v119;
        v135[5] = v118;
        sub_140002050(v136, 0, 0x18u);
        sub_1400087B0((__int64)v136);
        v71 = 2 * v58;
        v72 = 4 * v62;
        v73 = 8 * v66;
        v137 = ~(~v73
               | ~(((v72 ^ (v71 & 0xFB | (v54 & v137 & (v137 ^ 1) | v54 ^ v137 & (v137 ^ 1)) & 0xF9))
                  + (v71 & 0xFB | (v54 & v137 & (v137 ^ 1) | v54 ^ v137 & (v137 ^ 1)) & 0xF9)
                  - (~v72 & (v71 & 0xFB | (v54 & v137 & (v137 ^ 1) | v54 ^ v137 & (v137 ^ 1)) & 0xF9)))
                 & 0xF7))
             | (v73 & 0xAA | ~v73 & 0x55)
             ^ (((v72 ^ (v71 & 0xFB | (v54 & v137 & (v137 ^ 1) | v54 ^ v137 & (v137 ^ 1)) & 0xF9))
               + (v71 & 0xFB | (v54 & v137 & (v137 ^ 1) | v54 ^ v137 & (v137 ^ 1)) & 0xF9)
               - (~v72 & (v71 & 0xFB | (v54 & v137 & (v137 ^ 1) | v54 ^ v137 & (v137 ^ 1)) & 0xF9)))
              & 0xA2
              | ~(((v72 ^ (v71 & 0xFB | (v54 & v137 & (v137 ^ 1) | v54 ^ v137 & (v137 ^ 1)) & 0xF9))
                 + (v71 & 0xFB | (v54 & v137 & (v137 ^ 1) | v54 ^ v137 & (v137 ^ 1)) & 0xF9)
                 - (~v72 & (v71 & 0xFB | (v54 & v137 & (v137 ^ 1) | v54 ^ v137 & (v137 ^ 1)) & 0xF9)))
                & 0xF7)
              & 0x55);
        sub_14000C210(v117);
        v98 = 0;
        v4 = v131;
        v6 = v51;
        v3 = v122;
        while ( v98 < 7 )
        {
          v74 = (int)v98++;
          v117[v74] ^= 119 * v98;
        }
        v75 = sub_140002070((__int64)v141, v117);
        sub_140002070(v75, v121);
        sub_140006360(v141);
        sub_140002F90((__int64)v139, 1);
        v76 = 0;
        if ( v69 )
          v76 = v4;
        v77 = 0;
        if ( v69 )
          v77 = v6;
        v31 = (~v31 & ~(sub_14000D390(v139, v135, v77, v76) & 1)) != -1;
        sub_140001C10(v130);
        sub_14002E0B0(v118);
        sub_14002E0B0(v119);
        sub_14002E0B0(v120);
        sub_14002E0B0(v121);
        v78 = (_QWORD *)sub_140009490((__int64)v136);
        v79 = sub_1400094A0((__int64)v136);
        while ( v78 != (_QWORD *)v79 )
        {
          if ( *v78 != 0 )
            sub_140001C10(*v78);
          ++v78;
        }
        if ( v140 != 0 )
        {
          sub_14000C220(v116);
          for ( i7 = 0;
                i7 < 7;
                v116[v80] = ~(v81 & ((i7 & 0xC9) * (i7 & 0x36 ^ 0x36) + (i7 & 0x36) * (i7 | 0x36)))
                          & (v81
                           + (v81 ^ ((i7 & 0xC9) * (i7 & 0x36 ^ 0x36) + (i7 & 0x36) * (i7 | 0x36)) & 0xFE)
                           - (~((i7 & 0xC9) * (i7 & 0x36 ^ 0x36) + (i7 & 0x36) * (i7 | 0x36)) & v81)) )
          {
            v80 = (int)i7++;
            v81 = v116[v80];
          }
          sub_140006360(v116);
        }
        else
        {
          sub_14000C230(v124);
          for ( i8 = 0; i8 < 8; v124[v82] ^= 111 * (_BYTE)i8 )
            v82 = (int)i8++;
          sub_140006360(v124);
        }
        sub_140003A40((__int64)v139);
        sub_14000C240(v135);
      }
      else
      {
        sub_14002E0B0(v35);
        sub_140001C10(v37);
      }
    }
    else
    {
      sub_14002E0B0(v35);
    }
    v3 = (_QWORD *)v3[1];
  }
  if ( v109 != 0 )
  {
    v132 = &v109;
    sub_14000C280(&v109);
    v109 = 0;
  }
  if ( v6 != 0 )
    sub_140001C10(v6);
  return v31;
}


// ---- sub_14000B0C0 @ 0x14000b0c0 ----
__int64 __fastcall sub_14000B0C0(__int64 a1)
{
  *(_QWORD *)a1 = 0x2F91C30645ACE82DLL;
  *(_DWORD *)(a1 + 7) = 413394479;
  return 0x2F91C30645ACE82DLL;
}


// ---- sub_14000B0E0 @ 0x14000b0e0 ----
bool __fastcall sub_14000B0E0(_QWORD *a1, _QWORD *a2)
{
  void *v4; // rsp
  void *v5; // rsp
  void *v6; // rsp
  void *v7; // rsp
  void *v8; // rsp
  void *v9; // rsp
  _QWORD *v10; // r15
  void *v11; // rsp
  void *v12; // rsp
  _QWORD *v13; // r13
  void *v14; // rsp
  void *v15; // rsp
  unsigned __int64 *v16; // r12
  void *v17; // rsp
  void *v18; // rsp
  void *v19; // rsp
  void *v20; // rsp
  void *v21; // rsp
  void *v22; // rsp
  void *v23; // rsp
  void *v24; // rsp
  void *v25; // rsp
  void *v26; // rsp
  unsigned __int64 v27; // rax
  _QWORD *i; // rdx
  __int64 v29; // rcx
  unsigned __int64 v30; // r15
  __int64 v31; // rax
  __int64 v32; // r13
  __int64 v33; // r12
  __int64 v34; // r15
  __int64 j; // rbx
  _QWORD *v36; // r13
  __int64 v37; // rax
  _QWORD *v38; // rax
  __int64 v39; // r15
  __int64 v40; // rax
  _QWORD *v41; // rax
  __int64 v42; // rax
  bool v43; // di
  __int64 v44; // rax
  _QWORD *v45; // rax
  __int64 v46; // rax
  _QWORD *v47; // rsi
  __int64 v48; // r14
  int v49; // esi
  int v50; // edx
  __int64 v51; // rsi
  __int64 v52; // r14
  __int64 v53; // rax
  _QWORD *v54; // rax
  __int64 v55; // rax
  __int64 v56; // r14
  __int64 v57; // rax
  _QWORD *v58; // rax
  bool v59; // r13
  bool v60; // r13
  __int64 v61; // r14
  __int64 v62; // rax
  _QWORD *v63; // rax
  bool v64; // r14
  unsigned __int8 *v65; // r12
  __int64 v66; // r15
  unsigned __int64 v67; // r9
  __int64 v68; // r8
  _QWORD *v70; // [rsp+20h] [rbp-80h] BYREF
  __int64 v71; // [rsp+28h] [rbp-78h]
  __int64 v72; // [rsp+30h] [rbp-70h]
  __int64 v73; // [rsp+38h] [rbp-68h]
  unsigned __int64 v74; // [rsp+40h] [rbp-60h]
  _QWORD *v75; // [rsp+48h] [rbp-58h]
  _QWORD *v76; // [rsp+50h] [rbp-50h]
  _QWORD *v77; // [rsp+58h] [rbp-48h]
  unsigned __int8 *v78; // [rsp+60h] [rbp-40h]
  _QWORD *v79; // [rsp+68h] [rbp-38h]
  __int64 v80; // [rsp+70h] [rbp-30h]
  unsigned __int64 *v81; // [rsp+78h] [rbp-28h]
  _DWORD *v82; // [rsp+80h] [rbp-20h]
  _QWORD *v83; // [rsp+88h] [rbp-18h]
  __int64 v84; // [rsp+90h] [rbp-10h]
  unsigned int kk; // [rsp+9Ch] [rbp-4h]
  unsigned int jj; // [rsp+A0h] [rbp+0h]
  unsigned int ii; // [rsp+A4h] [rbp+4h]
  int v88; // [rsp+A8h] [rbp+8h]
  unsigned int n; // [rsp+ACh] [rbp+Ch]
  unsigned int m; // [rsp+B0h] [rbp+10h]
  unsigned int k; // [rsp+B4h] [rbp+14h]

  nullsub_1();
  v4 = alloca(sub_140001B30());
  v75 = &v70;
  v5 = alloca(sub_140001B30());
  v6 = alloca(sub_140001B30());
  v7 = alloca(sub_140001B30());
  v8 = alloca(sub_140001B30());
  v9 = alloca(sub_140001B30());
  v10 = &v70;
  v11 = alloca(sub_140001B30());
  v77 = &v70;
  v12 = alloca(sub_140001B30());
  v13 = &v70;
  v14 = alloca(sub_140001B30());
  v15 = alloca(sub_140001B30());
  v16 = (unsigned __int64 *)&v70;
  v17 = alloca(sub_140001B30());
  v82 = &v70;
  v18 = alloca(sub_140001B30());
  v19 = alloca(sub_140001B30());
  v20 = alloca(sub_140001B30());
  v21 = alloca(sub_140001B30());
  v22 = alloca(sub_140001B30());
  v23 = alloca(sub_140001B30());
  v24 = alloca(sub_140001B30());
  v25 = alloca(sub_140001B30());
  v78 = (unsigned __int8 *)&v70;
  v26 = alloca(sub_140001B30());
  v79 = &v70;
  v27 = 0;
  for ( i = a2; i != nullptr; i = (_QWORD *)i[1] )
    ++v27;
  v29 = 0;
  v76 = &v70;
  v74 = v27;
  if ( v27 != 0 )
  {
    v81 = (unsigned __int64 *)&v70;
    v83 = &v70;
    v30 = v27;
    v31 = sub_14002E070(saturated_mul(0x10u, v27));
    v70 = a1;
    v32 = 16 * v30 + v31;
    v33 = v31;
    v34 = v31;
    do
    {
      sub_14000C290(v34);
      v34 += 16;
    }
    while ( v34 != v32 );
    for ( j = 0; ; j = 2 * (j & 1) + (j ^ 1) )
    {
      v10 = v76;
      v13 = v83;
      if ( a2 == nullptr )
        break;
      v36 = v75;
      *v75 = *a2;
      sub_14000C2A0(&v70);
      for ( k = 0; ; *((_BYTE *)&v70 + v37) ^= 46 * (_BYTE)k )
      {
        nullsub_1();
        nullsub_1();
        if ( k >= 3 )
          break;
        nullsub_1();
        nullsub_1();
        v37 = (int)k++;
      }
      v38 = (_QWORD *)sub_140006B50(v36, (__int64)&v70);
      v39 = sub_140008790(v38);
      sub_14000C2B0(&v70);
      for ( m = 0; ; *((_BYTE *)&v70 + v40) ^= 103 * (_BYTE)m )
      {
        nullsub_1();
        nullsub_1();
        if ( m >= 5 )
          break;
        nullsub_1();
        nullsub_1();
        v40 = (int)m++;
      }
      v41 = (_QWORD *)sub_140006B50(v36, (__int64)&v70);
      v42 = sub_140008790(v41);
      sub_14000C2C0(16 * j + v33, v39, v42);
      a2 = (_QWORD *)a2[1];
    }
    v29 = v33;
    a1 = v70;
    v16 = v81;
  }
  v43 = false;
  while ( a1 != nullptr )
  {
    v84 = v29;
    *v10 = *a1;
    sub_14000C2D0(v13);
    for ( n = 0; n < 5; *((_BYTE *)v13 + v44) ^= 34 * (_BYTE)n )
      v44 = (int)n++;
    v45 = (_QWORD *)sub_140006B50(v10, (__int64)v13);
    v46 = sub_140008790(v45);
    v47 = v77;
    v48 = sub_14000BF30(v46, v77);
    v49 = sub_140031280(0, v48, *v47, 0, 0, (__int64)v16);
    sub_14000C2E0(v82);
    v88 = 0;
    while ( v88 == 0 )
    {
      v88 = 1;
      *v82 ^= 0x56FA793Du;
    }
    if ( v49 == *v82 )
    {
      v51 = sub_14002E070(saturated_mul(2u, *v16));
      if ( (int)sub_140031280(0, v48, *v77, v51, *v16, (__int64)v16) >= 0 )
      {
        sub_14002E0B0(v48);
        v52 = v71;
        sub_14000C2F0(v71);
        for ( ii = 0; ii < 5; *(_BYTE *)(v52 + v53) ^= 26 * (_BYTE)ii )
          v53 = (int)ii++;
        v54 = (_QWORD *)sub_140006B50(v10, v52);
        v55 = sub_140008790(v54);
        v80 = sub_140009590(v55, nullptr);
        v56 = v72;
        sub_14000C300(v72);
        for ( jj = 0; jj < 8; *(_BYTE *)(v56 + v57) ^= 83 * (_BYTE)jj )
          v57 = (int)jj++;
        v81 = v16;
        v83 = v13;
        v58 = (_QWORD *)sub_140006B50(v10, v56);
        v59 = true;
        if ( v58 != nullptr )
          v59 = sub_140008750(v58);
        v60 = v59;
        v61 = v73;
        sub_14000C310(v73);
        for ( kk = 0; kk < 0xB; *(_BYTE *)(v61 + v62) ^= 18 * (_BYTE)kk )
          v62 = (int)kk++;
        v63 = (_QWORD *)sub_140006B50(v10, v61);
        v64 = true;
        if ( v63 != nullptr )
          v64 = sub_140008750(v63);
        v65 = v78;
        *(_QWORD *)v78 = 0;
        *((_QWORD *)v65 + 1) = v80;
        *((_QWORD *)v65 + 2) = 0;
        *((_QWORD *)v65 + 3) = v51;
        *((_QWORD *)v65 + 4) = 0;
        *((_QWORD *)v65 + 5) = 0;
        sub_140002050(v65 + 48, 0, 0x18u);
        sub_1400087B0((__int64)(v65 + 48));
        v65[72] = ((v60 & 0xFD | v65[72] & 0xFC | 2) + 1 + (~(v60 & 0xFD | v65[72] & 0xFC | 2) | 0xFB)) & 0xF3 | 0xC;
        v66 = (__int64)v79;
        sub_140002F90((__int64)v79, 2);
        v67 = 0;
        if ( v64 )
          v67 = v74;
        v68 = 0;
        if ( v64 )
          v68 = v84;
        v43 = (sub_140014880(v66, v65, v68, v67) & 1 | v43) != 0;
        sub_14002E0B0(v80);
        sub_140001C10(v51);
        v13 = v83;
        sub_140003A40((__int64)v79);
        sub_14000C240(v78);
        v50 = 0;
        v10 = v76;
        v16 = v81;
        v29 = v84;
      }
      else
      {
        sub_14002E0B0(v48);
        sub_140001C10(v51);
        v29 = v84;
        v50 = 8;
      }
    }
    else
    {
      sub_14002E0B0(v48);
      v50 = 8;
      v29 = v84;
    }
    if ( v50 != 0 )
      break;
    a1 = (_QWORD *)a1[1];
  }
  if ( v29 != 0 )
    sub_140001C10(v29);
  return v43;
}


// ---- sub_14000B910 @ 0x14000b910 ----
bool __fastcall sub_14000B910(__int64 *a1, __int64 a2)
{
  bool v4; // bl
  __int64 v6; // rax
  __int64 v7; // rax
  int v8; // ebp
  __int64 v9; // rax
  __int64 v10; // rax
  int v11; // r14d
  __int64 v12; // rax
  _QWORD *v13; // rax
  int v14; // r15d
  __int64 v15; // rax
  _QWORD *v16; // rax
  __int64 v17; // r12
  __int64 v18; // rax
  _QWORD *v19; // rax
  __int64 v20; // r13
  __int64 v21; // rax
  _QWORD *v22; // rax
  int v23; // r13d
  int v24; // r15d
  int v25; // r12d
  __int64 v26; // rax
  unsigned __int8 *v27; // rbp
  __int64 v28; // r14
  _WORD *v29; // rsi
  __int64 v30; // rax
  int v31; // eax
  __int64 v32; // rax
  _QWORD *v33; // rax
  __int64 v34; // rax
  unsigned int i; // [rsp+4Ch] [rbp-FCh]
  unsigned int j; // [rsp+50h] [rbp-F8h]
  unsigned int k; // [rsp+54h] [rbp-F4h]
  unsigned int m; // [rsp+58h] [rbp-F0h]
  unsigned int n; // [rsp+5Ch] [rbp-ECh]
  unsigned int ii; // [rsp+60h] [rbp-E8h]
  unsigned int jj; // [rsp+64h] [rbp-E4h]
  unsigned int kk; // [rsp+68h] [rbp-E0h]
  _BYTE v43[3]; // [rsp+6Dh] [rbp-DBh] BYREF
  __int64 v44; // [rsp+70h] [rbp-D8h] BYREF
  _BYTE v45[4]; // [rsp+7Ch] [rbp-CCh] BYREF
  _BYTE v46[4]; // [rsp+80h] [rbp-C8h] BYREF
  _BYTE v47[5]; // [rsp+84h] [rbp-C4h] BYREF
  _BYTE v48[5]; // [rsp+89h] [rbp-BFh] BYREF
  _BYTE v49[5]; // [rsp+8Eh] [rbp-BAh] BYREF
  _BYTE v50[5]; // [rsp+93h] [rbp-B5h] BYREF
  _WORD v51[4]; // [rsp+98h] [rbp-B0h] BYREF
  __int64 v52; // [rsp+A0h] [rbp-A8h]
  __int64 v53; // [rsp+A8h] [rbp-A0h]
  __int64 v54; // [rsp+B0h] [rbp-98h] BYREF
  __int64 v55; // [rsp+B8h] [rbp-90h] BYREF
  __int64 v56; // [rsp+C0h] [rbp-88h]
  __int64 v57; // [rsp+C8h] [rbp-80h]
  char v58; // [rsp+D0h] [rbp-78h]
  char v59; // [rsp+D1h] [rbp-77h]
  __int64 v60; // [rsp+D8h] [rbp-70h]
  __int64 v61; // [rsp+E0h] [rbp-68h]
  __int64 *v62; // [rsp+E8h] [rbp-60h]
  __int64 *v63; // [rsp+F0h] [rbp-58h]
  __int64 v64; // [rsp+F8h] [rbp-50h]

  v4 = false;
  while ( a1 != nullptr )
  {
    v44 = *a1;
    sub_14000C330(v50);
    for ( i = 0; ; v50[v6] ^= (i & 0x4B ^ 0x4B) * (i & 0xB4) + (i & 0x4B) * (i | 0x4B) )
    {
      nullsub_1();
      nullsub_1();
      if ( i >= 5 )
        break;
      v6 = (int)i++;
    }
    v7 = sub_140006B50(&v44, (__int64)v50);
    v8 = (int)sub_140009560(v7);
    sub_14000C340(v49);
    for ( j = 0; j < 5; v49[v9] ^= (j & 0xA ^ 0xA) * (j & 0xF5) + (j & 0xA) * (j | 0xA) )
      v9 = (int)j++;
    v10 = sub_140006B50(&v44, (__int64)v49);
    v11 = (int)sub_140009560(v10);
    sub_14000C350(v48);
    for ( k = 0; k < 5; v48[v12] ^= 67 * (_BYTE)k )
      v12 = (int)k++;
    v13 = (_QWORD *)sub_140006B50(&v44, (__int64)v48);
    v14 = 0;
    if ( v13 != nullptr )
      v14 = sub_140008790(v13);
    sub_14000C360(v43);
    for ( m = 0; m < 3; v43[v15] ^= 124 * (_BYTE)m )
      v15 = (int)m++;
    v16 = (_QWORD *)sub_140006B50(&v44, (__int64)v43);
    v17 = 0;
    if ( v16 != nullptr )
      v17 = sub_140008790(v16);
    sub_14000C370(v46);
    for ( n = 0; n < 4; v46[v18] ^= 59 * (_BYTE)n )
      v18 = (int)n++;
    v19 = (_QWORD *)sub_140006B50(&v44, (__int64)v46);
    v20 = 0;
    if ( v19 != nullptr )
      v20 = sub_140008790(v19);
    sub_14000C380(v45);
    for ( ii = 0; ii < 4; v45[v21] ^= 116 * (_BYTE)ii )
      v21 = (int)ii++;
    v22 = (_QWORD *)sub_140006B50(&v44, (__int64)v45);
    if ( v22 != nullptr )
    {
      v52 = v20;
      v53 = v17;
      v23 = v14;
      v24 = v11;
      v25 = v8;
      v56 = a2;
      v26 = sub_140008790(v22);
      v27 = (unsigned __int8 *)sub_140009590(v26, nullptr);
      v28 = sub_14000C390(v27, 0) + 1;
      v29 = (_WORD *)sub_14002E070(saturated_mul(2u, v28));
      sub_1400068A0(v29, v28, v27, 0);
      sub_14002E0B0(v27);
      v57 = 0;
      v58 = 0;
      v59 = 1;
      v60 = 0;
      v61 = 0;
      v62 = &v55;
      v63 = &v54;
      v64 = 0;
      sub_14000C490(v51);
      for ( jj = 0; jj < 4; v51[v30] ^= 17519 * (_WORD)jj )
        v30 = (int)jj++;
      v8 = v25;
      v11 = v24;
      v14 = v23;
      if ( (sub_1400047E0((__int64)v29) & 1) != 0 )
      {
        LODWORD(v17) = v53;
        v20 = v52;
        v31 = 0;
      }
      else
      {
        LODWORD(v17) = v53;
        v20 = v52;
        sub_140001C10(v29);
        v31 = 4;
      }
      if ( v31 == 0 )
      {
        sub_140001C10(v29);
        v31 = 0;
      }
      a2 = v56;
      if ( v31 == 0 )
LABEL_46:
        v31 = 0;
    }
    else
    {
      sub_14000C4A0(v47);
      for ( kk = 0; ; v47[v32] = (-2 - (v47[v32] + (~v47[v32] | (108 * kk)))) & (v47[v32] | (108 * kk)) )
      {
        nullsub_1();
        nullsub_1();
        if ( kk >= 5 )
          break;
        v32 = (int)kk++;
      }
      v33 = (_QWORD *)sub_140006B50(&v44, (__int64)v47);
      if ( v33 != nullptr )
      {
        v34 = sub_140008790(v33);
        v55 = sub_140009590(v34, &v54);
        v31 = 0;
      }
      else
      {
        v31 = 4;
      }
      if ( v31 == 0 )
        goto LABEL_46;
    }
    if ( v31 == 0 )
      v4 = (sub_140018EA0(v11, v8, v14, v17, v20, v55, v54, a2) & 1 | v4) != 0;
    a1 = (__int64 *)a1[1];
  }
  return v4;
}


// ---- sub_14000BF10 @ 0x14000bf10 ----
__int64 __fastcall sub_14000BF10(__int64 a1)
{
  __int64 result; // rax

  result = -1;
  while ( *(_BYTE *)(a1 + result++ + 1) != 0 )
    ;
  return result;
}


// ---- sub_14000BF30 @ 0x14000bf30 ----
__int64 __fastcall sub_14000BF30(__int64 a1, unsigned __int64 *a2)
{
  __int64 v4; // rbx
  unsigned __int64 v5; // rcx
  unsigned __int64 v7; // rcx
  __int64 v8; // r14
  unsigned __int64 v9; // rax

  v4 = -1;
  v5 = -3;
  do
    v5 += 3LL;
  while ( *(_BYTE *)(a1 + v4++ + 1) != 0 );
  v7 = v5 >> 2;
  if ( *(_BYTE *)(a1 + v4 - 1) == 61 )
  {
    if ( *(_BYTE *)(a1 + v4 - 2) == 61 )
    {
      if ( *(_BYTE *)(a1 + v4 - 3) == 61 )
        v7 -= 3LL;
      else
        v7 -= 2LL;
    }
    else
    {
      --v7;
    }
  }
  v8 = sub_14002E070(v7 + 1);
  v9 = sub_14002D560(a1, v4, v8);
  *(_WORD *)(v8 + (v9 & 0xFFFFFFFFFFFFFFFEuLL)) = 0;
  if ( a2 != nullptr )
    *a2 = v9 >> 1;
  return v8;
}


// ---- sub_14000BFD0 @ 0x14000bfd0 ----
void __fastcall sub_14000BFD0(_DWORD *a1)
{
  *a1 = -297616147;
}


// ---- sub_14000BFE0 @ 0x14000bfe0 ----
void __fastcall sub_14000BFE0(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = -7;
  *(_DWORD *)a1 = -61101291;
}


// ---- sub_14000BFF0 @ 0x14000bff0 ----
void __fastcall sub_14000BFF0(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = -76;
  *(_DWORD *)a1 = -184473270;
}


// ---- sub_14000C000 @ 0x14000c000 ----
void __fastcall sub_14000C000(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = -47;
  *(_DWORD *)a1 = 526703408;
}


// ---- sub_14000C010 @ 0x14000c010 ----
void __fastcall sub_14000C010(__int64 a1)
{
  *(_WORD *)(a1 + 4) = -28656;
  *(_DWORD *)a1 = 339236220;
}


// ---- sub_14000C020 @ 0x14000c020 ----
void __fastcall sub_14000C020(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = -87;
  *(_DWORD *)a1 = 1066517305;
}


// ---- sub_14000C030 @ 0x14000c030 ----
void __fastcall sub_14000C030(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = 80;
  *(_DWORD *)a1 = 625625443;
}


// ---- sub_14000C040 @ 0x14000c040 ----
void __fastcall sub_14000C040(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = 109;
  *(_DWORD *)a1 = 1286599481;
}


// ---- sub_14000C050 @ 0x14000c050 ----
void __fastcall sub_14000C050(__int64 a1)
{
  *(_WORD *)(a1 + 4) = 12365;
  *(_DWORD *)a1 = 1433694590;
}


// ---- sub_14000C060 @ 0x14000c060 ----
void __fastcall sub_14000C060(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = 69;
  *(_DWORD *)a1 = 1638851375;
}


// ---- sub_14000C070 @ 0x14000c070 ----
_DWORD *__fastcall sub_14000C070(__int64 a1, _DWORD *a2)
{
  *a2 = -1909705067;
  return a2;
}


// ---- sub_14000C080 @ 0x14000c080 ----
__int64 __fastcall sub_14000C080(__int64 a1)
{
  *(_OWORD *)a1 = 0;
  *(_WORD *)(a1 + 16) = 0;
  return a1;
}


// ---- sub_14000C090 @ 0x14000c090 ----
void __fastcall sub_14000C090(__int64 a1)
{
  *(_BYTE *)(a1 + 2) = 122;
  *(_WORD *)a1 = -26601;
}


// ---- sub_14000C0A0 @ 0x14000c0a0 ----
void __fastcall sub_14000C0A0(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = 29;
  *(_DWORD *)a1 = -2117725353;
}


// ---- sub_14000C0B0 @ 0x14000c0b0 ----
void __fastcall sub_14000C0B0(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = 58;
  *(_DWORD *)a1 = -1439528421;
}


// ---- sub_14000C0C0 @ 0x14000c0c0 ----
void __fastcall sub_14000C0C0(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = -11;
  *(_DWORD *)a1 = -1476584638;
}


// ---- sub_14000C0D0 @ 0x14000c0d0 ----
__int64 __fastcall sub_14000C0D0(__int64 a1, __int64 a2, __int64 a3, char a4, char a5)
{
  *(_QWORD *)a1 = a2;
  *(_QWORD *)(a1 + 8) = a3;
  *(_BYTE *)(a1 + 16) = a4;
  *(_BYTE *)(a1 + 17) = a5;
  return a1;
}


// ---- sub_14000C0F0 @ 0x14000c0f0 ----
HDESK __fastcall sub_14000C0F0(const WCHAR *a1)
{
  return OpenDesktopW(a1, 0, true, 0x10000000u);
}


// ---- sub_14000C110 @ 0x14000c110 ----
HDESK __fastcall sub_14000C110(const WCHAR *a1)
{
  return CreateDesktopW(a1, nullptr, nullptr, 0, 0x10000000u, nullptr);
}


// ---- sub_14000C140 @ 0x14000c140 ----
void __fastcall sub_14000C140(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = 18;
  *(_DWORD *)a1 = -1068845798;
}


// ---- sub_14000C150 @ 0x14000c150 ----
void __fastcall sub_14000C150(_DWORD *a1)
{
  *a1 = -1283269106;
}


// ---- sub_14000C160 @ 0x14000c160 ----
void __fastcall sub_14000C160(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = -22;
  *(_DWORD *)a1 = -313809652;
}


// ---- sub_14000C170 @ 0x14000c170 ----
void __fastcall sub_14000C170(_DWORD *a1)
{
  *a1 = 1949650797;
}


// ---- sub_14000C180 @ 0x14000c180 ----
void __fastcall sub_14000C180(_DWORD *a1)
{
  *a1 = 1751895103;
}


// ---- sub_14000C190 @ 0x14000c190 ----
void __fastcall sub_14000C190(_DWORD *a1)
{
  *a1 = 1415398265;
}


// ---- sub_14000C1A0 @ 0x14000c1a0 ----
__int64 __fastcall sub_14000C1A0(_QWORD *a1)
{
  *a1 = 0x705BA6E94C99F526LL;
  return 0x705BA6E94C99F526LL;
}


// ---- sub_14000C1B0 @ 0x14000c1b0 ----
__int64 __fastcall sub_14000C1B0(__int64 a1)
{
  *(_QWORD *)a1 = 0x12F20245042686ELL;
  *(_DWORD *)(a1 + 8) = -1661145580;
  return 0x12F20245042686ELL;
}


// ---- sub_14000C1D0 @ 0x14000c1d0 ----
__int64 __fastcall sub_14000C1D0(_QWORD *a1)
{
  *a1 = 0x3099C13773BDE325LL;
  return 0x3099C13773BDE325LL;
}


// ---- sub_14000C1E0 @ 0x14000c1e0 ----
void __fastcall sub_14000C1E0(_DWORD *a1)
{
  *a1 = 342716009;
}


// ---- sub_14000C1F0 @ 0x14000c1f0 ----
unsigned __int64 __fastcall sub_14000C1F0(__int64 a1)
{
  *(_QWORD *)a1 = 0x9FDB07589DCE045BuLL;
  *(_DWORD *)(a1 + 7) = -1440792417;
  return 0x9FDB07589DCE045BuLL;
}


// ---- sub_14000C210 @ 0x14000c210 ----
void __fastcall sub_14000C210(_DWORD *a1)
{
  *(_DWORD *)((char *)a1 + 3) = 1105663630;
  *a1 = -1909079227;
}


// ---- sub_14000C220 @ 0x14000c220 ----
void __fastcall sub_14000C220(_DWORD *a1)
{
  *(_DWORD *)((char *)a1 + 3) = 2046836893;
  *a1 = -1645133564;
}


// ---- sub_14000C230 @ 0x14000c230 ----
__int64 __fastcall sub_14000C230(_QWORD *a1)
{
  *a1 = 0x7850CE7BF108F35DLL;
  return 0x7850CE7BF108F35DLL;
}


// ---- sub_14000C240 @ 0x14000c240 ----
__int64 __fastcall sub_14000C240(__int64 a1)
{
  __int64 result; // rax
  __int64 v2; // rsi

  result = *(_QWORD *)(a1 + 48);
  if ( result != 0 && result != *(_QWORD *)(a1 + 56) )
  {
    v2 = a1 + 48;
    result = sub_140001C10(*(_QWORD *)(a1 + 48));
    *(_OWORD *)v2 = 0;
    *(_QWORD *)(v2 + 16) = 0;
  }
  return result;
}


// ---- sub_14000C280 @ 0x14000c280 ----
BOOL __fastcall sub_14000C280(HDESK *a1)
{
  return CloseDesktop(*a1);
}


// ---- sub_14000C290 @ 0x14000c290 ----
_OWORD *__fastcall sub_14000C290(_OWORD *a1)
{
  *a1 = 0;
  return a1;
}


// ---- sub_14000C2A0 @ 0x14000c2a0 ----
void __fastcall sub_14000C2A0(__int64 a1)
{
  *(_BYTE *)(a1 + 2) = -118;
  *(_WORD *)a1 = 14407;
}


// ---- sub_14000C2B0 @ 0x14000c2b0 ----
void __fastcall sub_14000C2B0(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = 3;
  *(_DWORD *)a1 = -111628535;
}


// ---- sub_14000C2C0 @ 0x14000c2c0 ----
_QWORD *__fastcall sub_14000C2C0(_QWORD *a1, __int64 a2, __int64 a3)
{
  *a1 = a2;
  a1[1] = a3;
  return a1;
}


// ---- sub_14000C2D0 @ 0x14000c2d0 ----
void __fastcall sub_14000C2D0(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = -86;
  *(_DWORD *)a1 = -535681710;
}


// ---- sub_14000C2E0 @ 0x14000c2e0 ----
void __fastcall sub_14000C2E0(_DWORD *a1)
{
  *a1 = -1761969890;
}


// ---- sub_14000C2F0 @ 0x14000c2f0 ----
void __fastcall sub_14000C2F0(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = -126;
  *(_DWORD *)a1 = 220419444;
}


// ---- sub_14000C300 @ 0x14000c300 ----
unsigned __int64 __fastcall sub_14000C300(_QWORD *a1)
{
  *a1 = 0x983C80F0388ACF3BuLL;
  return 0x983C80F0388ACF3BuLL;
}


// ---- sub_14000C310 @ 0x14000c310 ----
unsigned __int64 __fastcall sub_14000C310(__int64 a1)
{
  *(_QWORD *)a1 = 0xFF171F342D425C77uLL;
  *(_DWORD *)(a1 + 7) = -959984385;
  return 0xFF171F342D425C77uLL;
}


// ---- sub_14000C330 @ 0x14000c330 ----
void __fastcall sub_14000C330(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = 119;
  *(_DWORD *)a1 = 1234300735;
}


// ---- sub_14000C340 @ 0x14000c340 ----
void __fastcall sub_14000C340(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = 50;
  *(_DWORD *)a1 = 1299872615;
}


// ---- sub_14000C350 @ 0x14000c350 ----
void __fastcall sub_14000C350(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = 79;
  *(_DWORD *)a1 = 1690167091;
}


// ---- sub_14000C360 @ 0x14000c360 ----
void __fastcall sub_14000C360(__int64 a1)
{
  *(_BYTE *)(a1 + 2) = 116;
  *(_WORD *)a1 = -27110;
}


// ---- sub_14000C370 @ 0x14000c370 ----
void __fastcall sub_14000C370(_DWORD *a1)
{
  *a1 = -321518502;
}


// ---- sub_14000C380 @ 0x14000c380 ----
void __fastcall sub_14000C380(_DWORD *a1)
{
  *a1 = -802121215;
}


// ---- sub_14000C390 @ 0x14000c390 ----
__int64 __fastcall sub_14000C390(_BYTE *a1, unsigned __int64 a2)
{
  unsigned int v2; // r8d
  __int64 result; // rax
  unsigned __int8 *v4; // rcx

  v2 = (unsigned __int8)*a1;
  if ( *a1 == 0 )
    return 0;
  if ( a2 != 0 )
  {
    result = 0;
    while ( (unsigned __int64)a1 < a2 )
    {
      if ( (v2 & 0xF0) == 0xE0 || v2 < 0x80 || (v2 & 0xE0) == 0xC0 )
      {
        result = (result ^ 1) + 2 * (result & 1);
        v2 = (unsigned __int8)*++a1;
        if ( v2 == 0 )
          return result;
      }
      else
      {
        if ( (v2 & 0xF8) == 0xF0 )
          result += 2;
        v2 = (unsigned __int8)*++a1;
        if ( v2 == 0 )
          return result;
      }
    }
  }
  else
  {
    v4 = a1 + 1;
    result = 0;
    do
    {
      if ( (v2 & 0xF0) == 0xE0 || v2 < 0x80 || (v2 & 0xE0) == 0xC0 )
      {
        result = (result ^ 1) + 2 * (result & 1);
      }
      else if ( (v2 & 0xF8) == 0xF0 )
      {
        result += 2;
      }
      v2 = *v4++;
    }
    while ( v2 != 0 );
  }
  return result;
}


// ---- sub_14000C490 @ 0x14000c490 ----
__int64 __fastcall sub_14000C490(_QWORD *a1)
{
  *a1 = 0x11BCCD19889B4428LL;
  return 0x11BCCD19889B4428LL;
}


// ---- sub_14000C4A0 @ 0x14000c4a0 ----
void __fastcall sub_14000C4A0(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = 28;
  *(_DWORD *)a1 = -785336056;
}


// ---- sub_14000C4B0 @ 0x14000c4b0 ----
__int64 __fastcall sub_14000C4B0(__int64 a1)
{
  *(_QWORD *)a1 = 0x69B0BD2570B9F466LL;
  *(_DWORD *)(a1 + 7) = -1058591127;
  return 0x69B0BD2570B9F466LL;
}


// ---- sub_14000C4D0 @ 0x14000c4d0 ----
__int64 __fastcall sub_14000C4D0(_QWORD *a1)
{
  *(_QWORD *)((char *)a1 + 6) = 0x2A1A4A4475746C4ALL;
  *a1 = 0x6C4A617C696A6562LL;
  return 0x6C4A617C696A6562LL;
}


// ---- sub_14000C4F0 @ 0x14000c4f0 ----
void __fastcall sub_14000C4F0(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = 93;
  *(_DWORD *)a1 = -2096784631;
}


// ---- sub_14000C500 @ 0x14000c500 ----
void __fastcall sub_14000C500(__int64 a1)
{
  *(_BYTE *)(a1 + 4) = 4;
  *(_DWORD *)a1 = -1258485928;
}


// ---- nullsub_1 @ 0x14000c510 ----
void nullsub_1()
{
  ;
}


// ---- sub_14000C520 @ 0x14000c520 ----
__int64 __fastcall sub_14000C520(__int64 a1, _QWORD *a2, __int64 a3, unsigned __int16 *a4)
{
  unsigned __int16 *v4; // r15
  __int64 v7; // rsi
  bool v8; // zf
  __int64 v9; // r12
  __int64 v10; // rax
  unsigned __int64 v11; // rsi
  __int64 v12; // rcx
  __int64 v13; // rbx
  __int64 v14; // rax
  __int16 v15; // cx
  __int64 v16; // rcx
  unsigned __int16 v17; // r8
  __int16 **i; // rax
  __int16 *v19; // rdx
  __int16 v20; // r11
  __int16 *v21; // r9
  _WORD *v22; // r10
  _WORD *v23; // r8
  int v24; // ebp
  char *v25; // r12
  __int64 v26; // rcx
  __int64 v27; // rax
  unsigned int v28; // r15d
  _BYTE *v29; // r13
  __int64 v30; // rcx
  _BYTE *v31; // rax
  __int64 v32; // rax
  __int64 v33; // rcx
  __int64 v34; // r14
  char v35; // dl
  _BYTE *v36; // rax
  char v37; // cl
  _BYTE *v38; // rax
  unsigned int j; // edx
  unsigned __int16 *v40; // rcx
  _BYTE *v41; // r8
  int v42; // r9d
  int v43; // ecx
  unsigned int v44; // r8d
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // r8d
  _DWORD *v49; // r12
  __int64 v50; // rdx
  int v51; // eax
  __int64 v52; // rsi
  __int64 v53; // rax
  int v54; // r9d
  int v55; // r13d
  int v56; // eax
  __int64 v57; // r8
  int v58; // eax
  unsigned __int64 v59; // rdx
  int v60; // eax
  __int64 v61; // rdx
  __int64 v62; // rax
  __int64 v63; // rdx
  __int64 v64; // rax
  __int64 v65; // rdx
  int v66; // r9d
  __int64 v67; // rdx
  __int64 v68; // rcx
  int v69; // esi
  int v70; // eax
  __int64 v71; // r9
  int v72; // r9d
  unsigned int v73; // ebx
  __int64 v74; // rdi
  __int64 v75; // rdx
  __int64 v77; // [rsp+20h] [rbp-D8h]
  __int64 v78; // [rsp+28h] [rbp-D0h]
  char v79; // [rsp+30h] [rbp-C8h]
  int v80; // [rsp+64h] [rbp-94h]
  int k; // [rsp+64h] [rbp-94h]
  int m; // [rsp+64h] [rbp-94h]
  __int64 v83; // [rsp+68h] [rbp-90h] BYREF
  unsigned int v84[4]; // [rsp+70h] [rbp-88h] BYREF
  __int64 v85; // [rsp+80h] [rbp-78h] BYREF
  __int64 v86; // [rsp+88h] [rbp-70h] BYREF
  __int64 v87; // [rsp+90h] [rbp-68h]
  unsigned __int64 v88; // [rsp+98h] [rbp-60h]

  v4 = a4;
  v87 = a1;
  v7 = 0x7FFFFFFFFFFFFFFFLL;
  do
    v8 = a4[++v7] == 0;
  while ( !v8 );
  v9 = *(_QWORD *)(a3 + 8);
  v10 = -2;
  do
  {
    v8 = *(_WORD *)(v9 + v10 + 2) == 0;
    v10 += 2;
  }
  while ( !v8 );
  v11 = (v7 * 2) >> 1;
  v12 = -1;
  if ( (__int64)(v11 + (v10 >> 1) + 2) >= 0 )
    v12 = 2 * (v11 + (v10 >> 1)) + 4;
  v13 = sub_14002E070(v12);
  v14 = 0;
  do
  {
    v15 = *(_WORD *)(v9 + v14);
    *(_WORD *)(v13 + v14) = v15;
    v14 += 2;
  }
  while ( v15 != 0 );
  *(_WORD *)(v13 + v14 - 2) = 92;
  v16 = 0;
  do
  {
    v17 = v4[v16];
    *(_WORD *)(v14 + v13 + v16 * 2) = v17;
    ++v16;
  }
  while ( v17 != 0 );
  for ( i = (__int16 **)a2[6]; i != (__int16 **)a2[7]; ++i )
  {
    v19 = *i;
    v20 = **i;
    if ( v20 == 0 )
    {
LABEL_26:
      sub_140001C10(v13);
      v28 = 0;
      goto LABEL_163;
    }
    v21 = *i;
    v22 = (_WORD *)v13;
    v23 = (_WORD *)v13;
    while ( *v22 != 0 )
    {
      if ( *v22 == v20 )
      {
        ++v21;
        ++v22;
        v20 = *v21;
        if ( *v21 == 0 )
        {
LABEL_12:
          if ( v23 != nullptr )
            goto LABEL_26;
          break;
        }
      }
      else
      {
        v22 = ++v23;
        v21 = *i;
        v20 = *v19;
        if ( *v19 == 0 )
          goto LABEL_12;
      }
    }
  }
  v24 = sub_140031DB0(v13, (unsigned int)&v86, -2146435071, 3, 1, 96, 128);
  v25 = *(char **)a3;
  if ( *(_QWORD *)a3 != 0 )
  {
    v26 = -1;
    do
    {
      v27 = v26 + 1;
      v8 = v25[++v26] == 0;
    }
    while ( !v8 );
  }
  else
  {
    v27 = 0;
  }
  v29 = (_BYTE *)a2[1];
  v30 = v27 + v11 + 2;
  v31 = v29;
  do
  {
    ++v30;
    v8 = *v31++ == 0;
  }
  while ( !v8 );
  v32 = sub_14002E070(v30);
  v33 = -1;
  v34 = v32;
  do
  {
    v35 = v29[v33 + 1];
    *(_BYTE *)(v32 + v33++ + 1) = v35;
  }
  while ( v35 != 0 );
  v36 = (_BYTE *)(v33 + v32);
  if ( v25 != nullptr )
  {
    *v36 = 47;
    do
    {
      v37 = *v25++;
      *++v36 = v37;
    }
    while ( v37 != 0 );
  }
  *v36 = 47;
  v38 = v36 + 1;
  for ( j = *v4; (_WORD)j != 0; v4 = v40 )
  {
    if ( v11 == 0 )
      break;
    v40 = v4 + 1;
    if ( (unsigned __int16)j > 0x7Fu )
    {
      if ( (unsigned __int16)j > 0x7FFu || v11 == 1 )
      {
        v42 = j & 0xFC00;
        if ( v42 == 55296 && v11 >= 4 )
        {
          v43 = v4[1];
          v44 = ((((unsigned __int16)j << 10) - 56623104) ^ (v43 - 56320))
              + 2 * ((((unsigned __int16)j << 10) - 56623104) & (v43 - 56320));
          *v38 = ((v44 + 0x10000) >> 18) - 16;
          v38[1] = ((v44 + 0x10000) >> 12) & 0x3F | 0x80;
          v38[2] = (v44 >> 6) & 0x3F | 0x80;
          v38[3] = v43 & 0x3F | 0x80;
          v41 = v38 + 4;
          v40 = v4 + 2;
        }
        else
        {
          if ( (unsigned __int16)v42 == 56320 )
            goto LABEL_46;
          if ( v11 < 3 )
          {
            v41 = v38;
          }
          else
          {
            *v38 = ((unsigned __int16)j >> 12) | 0xE0;
            v38[1] = ((unsigned __int16)j >> 6) & 0x3F | 0x80;
            v41 = v38 + 3;
            v38[2] = j & 0x3F | 0x80;
          }
        }
      }
      else
      {
        *v38 = (j >> 6) | 0xC0;
        v41 = v38 + 2;
        v38[1] = j & 0x3F | 0x80;
      }
    }
    else
    {
      v41 = v38 + 1;
      *v38 = j;
    }
    v11 = &v38[v11] - v41;
    v38 = v41;
LABEL_46:
    j = *v40;
  }
  *v38 = 0;
  v84[0] = 0;
  v45 = -684893158;
  do
  {
    ++v84[0];
    v45 ^= (v84[0] & 0x172D5C59 ^ 0x172D5C59) * (v84[0] & 0xE8D2A3A6) + (v84[0] & 0x172D5C59) * (v84[0] | 0x172D5C59);
  }
  while ( v84[0] == 0 );
  if ( v24 != v45 )
  {
    v84[0] = 0;
    v46 = -177940900;
    do
    {
      ++v84[0];
      v46 ^= 895800840 * v84[0];
    }
    while ( v84[0] == 0 );
    if ( v24 != v46 )
    {
      v28 = 0;
      goto LABEL_148;
    }
  }
  v84[0] = 0;
  v47 = 1909704962;
  do
  {
    v84[0] = (v84[0] ^ 1) + 2 * (v84[0] & 1);
    v47 = (v47 + ((1909705066 * v84[0]) ^ v47) - (v47 & ~(1909705066 * v84[0]))) & ~((1909705066 * v84[0]) & v47);
  }
  while ( v84[0] == 0 );
  v84[0] = 0;
  v48 = 1401704251;
  do
  {
    ++v84[0];
    v48 ^= 1402752955 * v84[0];
  }
  while ( v84[0] == 0 );
  if ( (int)sub_140032010(v13, (unsigned int)&v86, v48, 7, v47) < 0 )
  {
    v28 = 0;
    goto LABEL_133;
  }
  v49 = (_DWORD *)sub_14002E070(1024);
  if ( qword_14003BB50 != 0 )
  {
    v50 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v50) != 674329531 )
    {
      if ( qword_14003BB50 == ++v50 )
        goto LABEL_67;
    }
    v24 = sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v50 + 4), 5, v86, (unsigned int)v84, (__int64)v49, 1024, 47);
    if ( v24 < 0 )
      goto LABEL_123;
  }
  else
  {
LABEL_67:
    v84[0] = 0;
    v51 = 118103385;
    do
    {
      ++v84[0];
      v24 = ((-118103386 * v84[0]) | v51) & (((-118103386 * v84[0]) & v51) + ~(2 * ((-118103386 * v84[0]) & v51)));
      v51 = v24;
    }
    while ( v84[0] == 0 );
    if ( v24 < 0 )
      goto LABEL_123;
  }
  if ( *v49 != 0 )
  {
    v52 = 0;
    v28 = 0;
    while ( 1 )
    {
      v53 = sub_14002CC70(*(_QWORD *)&v49[2 * v52 + 2], v13);
      if ( v53 != 0 )
        break;
LABEL_78:
      if ( ++v52 >= (unsigned __int64)(unsigned int)*v49 )
        goto LABEL_124;
    }
    v55 = v53;
    LODWORD(v83) = 0;
    v56 = 403391259;
    do
    {
      LODWORD(v83) = v83 + 1;
      v56 ^= (v83 & 0xEFF4BCE4) * (v83 & 0x100B431B ^ 0x100B431B) + (v83 & 0x100B431B) * (v83 | 0x100B431B);
    }
    while ( (_DWORD)v83 == 0 );
    if ( qword_14003BB50 != 0 )
    {
      v57 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v57) != -1443343965 )
      {
        if ( qword_14003BB50 == ++v57 )
          goto LABEL_86;
      }
      v24 = sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v57 + 4), 7, (unsigned int)&v83, 4, 0, 0, 2);
      if ( v24 >= 0 )
      {
LABEL_91:
        v85 = 0;
        v88 = 0;
        if ( qword_14003BB50 != 0 )
        {
          v59 = 0;
          while ( *(_DWORD *)(qword_14003BB58 + 8 * v59) != -622556744 )
          {
            v59 = (v59 ^ 1) + 2 * (v59 & 1);
            if ( v59 >= qword_14003BB50 )
              goto LABEL_95;
          }
          v24 = sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v59 + 4), 10, v83, -1, (__int64)&v85, 0, 0);
          if ( v24 < 0 )
            goto LABEL_106;
        }
        else
        {
LABEL_95:
          v80 = 0;
          v60 = 118103385;
          do
          {
            ++v80;
            v24 = ((-118103386 * v80) | v60) & (((-118103386 * v80) & v60) + ~(2 * ((-118103386 * v80) & v60)));
            v60 = v24;
          }
          while ( v80 == 0 );
          if ( v24 < 0 )
            goto LABEL_106;
        }
        v28 = sub_140003370(v87, v34, v85, v88);
        if ( qword_14003BB50 != 0 )
        {
          v61 = 0;
          while ( *(_DWORD *)(qword_14003BB58 + 8 * v61) != -1591631313 )
          {
            if ( qword_14003BB50 == ++v61 )
              goto LABEL_104;
          }
          sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v61 + 4), 2, -1, v85, v77, v78, v79);
          v62 = qword_14003BB50;
          if ( qword_14003BB50 == 0 )
            goto LABEL_110;
          goto LABEL_107;
        }
LABEL_104:
        for ( k = 0; k == 0; ++k )
          ;
LABEL_106:
        v62 = qword_14003BB50;
        if ( qword_14003BB50 == 0 )
        {
LABEL_110:
          for ( m = 0; m == 0; ++m )
            ;
          goto LABEL_112;
        }
LABEL_107:
        v63 = 0;
        while ( *(_DWORD *)(qword_14003BB58 + 8 * v63) != -1825720177 )
        {
          if ( v62 == ++v63 )
            goto LABEL_110;
        }
        sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v63 + 4), 1, v83, v54, v77, v78, v79);
        v64 = qword_14003BB50;
        if ( qword_14003BB50 != 0 )
          goto LABEL_113;
        goto LABEL_116;
      }
    }
    else
    {
LABEL_86:
      LODWORD(v83) = 0;
      v58 = 118103385;
      do
      {
        LODWORD(v83) = v83 + 1;
        v24 = ((-118103386 * v83) | v58) & (((-118103386 * v83) & v58) + ~(2 * ((-118103386 * v83) & v58)));
        v58 = v24;
      }
      while ( (_DWORD)v83 == 0 );
      if ( v24 >= 0 )
        goto LABEL_91;
    }
LABEL_112:
    v64 = qword_14003BB50;
    if ( qword_14003BB50 != 0 )
    {
LABEL_113:
      v65 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v65) != -1825720177 )
      {
        if ( v64 == ++v65 )
          goto LABEL_116;
      }
      sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v65 + 4), 1, v55, v54, v77, v78, v79);
LABEL_77:
      if ( (v28 & 1) != 0 )
        goto LABEL_124;
      goto LABEL_78;
    }
LABEL_116:
    LODWORD(v83) = 0;
    do
      LODWORD(v83) = v83 + 1;
    while ( (_DWORD)v83 == 0 );
    goto LABEL_77;
  }
LABEL_123:
  v28 = 0;
LABEL_124:
  sub_14002E0B0(v49);
  if ( qword_14003BB50 != 0 )
  {
    v67 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v67) != -1825720177 )
    {
      if ( qword_14003BB50 == ++v67 )
        goto LABEL_128;
    }
    sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v67 + 4), 1, v86, v66, v77, v78, v79);
    if ( (v28 & 1) != 0 )
      goto LABEL_148;
    goto LABEL_133;
  }
LABEL_128:
  LODWORD(v83) = 0;
  do
    LODWORD(v83) = v83 + 1;
  while ( (_DWORD)v83 == 0 );
  if ( (v28 & 1) == 0 )
  {
LABEL_133:
    v68 = a2[4];
    if ( v68 != 0 && (unsigned __int8)sub_140030290(v68, v84) != 0 )
    {
      do
      {
        if ( (int)sub_140030330(&v83, *(_QWORD *)v84, 1048577) >= 0 )
        {
          v70 = sub_140030410(v83, 0, 0xFFFFFFFFLL);
          if ( qword_14003BB50 != 0 )
          {
            v71 = 0;
            while ( *(_DWORD *)(qword_14003BB58 + 8 * v71) != -1825720177 )
            {
              if ( qword_14003BB50 == ++v71 )
                goto LABEL_144;
            }
            v69 = v70;
            sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v71 + 4), 1, v83, v71, v77, v78, v79);
            v70 = v69;
          }
          else
          {
LABEL_144:
            LODWORD(v85) = 0;
            do
              LODWORD(v85) = v85 + 1;
            while ( (_DWORD)v85 == 0 );
          }
          if ( v70 < 0 )
            break;
        }
      }
      while ( (unsigned __int8)sub_140030290(a2[4], v84) != 0 );
    }
    v24 = sub_140031DB0(v13, (unsigned int)&v86, 1179785, 7, 1, 96, 128);
  }
LABEL_148:
  sub_140001C10(v13);
  if ( (v28 & 1) == 0 && v24 >= 0 )
  {
    if ( (int)sub_140032460(v86, v84, 0) >= 0 )
    {
      v73 = v84[0];
      v74 = sub_14002E070(v84[0]);
      if ( (int)sub_140032540(v86, v74, v73, 0) >= 0 )
        v28 = sub_140003370(v87, v34, v74, v84[0]);
      sub_140001C10(v74);
    }
    if ( qword_14003BB50 != 0 )
    {
      v75 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v75) != -1825720177 )
      {
        if ( qword_14003BB50 == ++v75 )
          goto LABEL_158;
      }
      sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v75 + 4), 1, v86, v72, v77, v78, v79);
    }
    else
    {
LABEL_158:
      v84[0] = 0;
      do
        ++v84[0];
      while ( v84[0] == 0 );
    }
  }
  sub_140001C10(v34);
LABEL_163:
  LOBYTE(v28) = v28 & 1;
  return v28;
}


// ---- sub_14000D200 @ 0x14000d200 ----
_BYTE *__fastcall sub_14000D200(_BYTE *a1, __int64 a2, unsigned __int16 *a3, unsigned __int64 a4)
{
  unsigned int v4; // r10d
  _BYTE *v5; // rax
  unsigned __int64 v6; // rdx
  unsigned __int16 *v7; // r11
  _BYTE *v8; // rsi
  int v9; // esi
  int v10; // edi
  int v11; // r10d
  unsigned int v12; // esi

  v4 = *a3;
  v5 = a1;
  if ( (_WORD)v4 != 0 )
  {
    v6 = a2 - 1;
    v5 = a1;
    do
    {
      if ( a4 != 0 && (unsigned __int64)a3 >= a4 || v6 == 0 )
        break;
      v7 = a3 + 1;
      if ( (unsigned __int16)v4 > 0x7Fu )
      {
        v9 = (unsigned __int16)v4;
        if ( (unsigned __int16)v4 > 0x7FFu || v6 < 2 )
        {
          v10 = v4 & 0xFC00;
          if ( v10 == 55296 && v6 >= 4 )
          {
            v11 = a3[1];
            v12 = (((v9 << 10) - 56623104) ^ (v11 - 56320)) + 2 * (((v9 << 10) - 56623104) & (v11 - 56320));
            *v5 = ((v12 + 0x10000) >> 18) - 16;
            v5[1] = ((v12 + 0x10000) >> 12) & 0x3F | 0x80;
            v5[2] = (v12 >> 6) & 0x3F | 0x80;
            v5[3] = v11 & 0x3F | 0x80;
            v8 = v5 + 4;
            v7 = a3 + 2;
          }
          else
          {
            if ( (unsigned __int16)v10 == 56320 )
              goto LABEL_15;
            if ( v6 < 3 )
            {
              v8 = v5;
            }
            else
            {
              *v5 = ((unsigned __int16)v4 >> 12) | 0xE0;
              v5[1] = ((unsigned __int16)v4 >> 6) & 0x3F | 0x80;
              v8 = v5 + 3;
              v5[2] = v4 & 0x3F | 0x80;
            }
          }
        }
        else
        {
          *v5 = (v4 >> 6) | 0xC0;
          v8 = v5 + 2;
          v5[1] = v4 & 0x3F | 0x80;
        }
      }
      else
      {
        v8 = v5 + 1;
        *v5 = v4;
      }
      v6 = &v5[v6] - v8;
      v5 = v8;
LABEL_15:
      v4 = *v7;
      a3 = v7;
    }
    while ( (_WORD)v4 != 0 );
  }
  *v5 = 0;
  return (_BYTE *)(v5 - a1);
}


// ---- sub_14000D390 @ 0x14000d390 ----
__int64 __fastcall sub_14000D390(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // r14
  bool v6; // zf
  __int64 v7; // rcx
  __int64 v8; // rbx
  __int64 v9; // rax
  __int64 v10; // rcx
  __int64 v11; // rax
  __int16 v12; // dx
  __int64 v13; // rcx
  __int16 v14; // r8
  unsigned int i; // [rsp+40h] [rbp-D8h]
  _QWORD v17[4]; // [rsp+50h] [rbp-C8h]
  __int64 v18; // [rsp+80h] [rbp-98h]
  __int64 v19; // [rsp+A0h] [rbp-78h]
  __int64 v20; // [rsp+A8h] [rbp-70h]
  __int64 v21; // [rsp+B8h] [rbp-60h] BYREF

  v19 = a4;
  v20 = a3;
  v18 = a1;
  v5 = -2;
  do
  {
    v6 = *(_WORD *)(*(_QWORD *)(a2 + 24) + v5 + 2) == 0;
    v5 += 2;
  }
  while ( !v6 );
  v7 = -1;
  if ( v5 >> 1 >= -13 )
    v7 = v5 + 26;
  v8 = sub_14002E070(v7);
  qmemcpy(v17, byte_140033AF4, 26);
  for ( i = 0;
        i < 0xD;
        *((_WORD *)v17 + v9) = (*((_WORD *)v17 + v9)
                              + (*((_WORD *)v17 + v9) ^ (13586 * i))
                              - (*((_WORD *)v17 + v9) & ~(13586 * i)))
                             & ~(*((_WORD *)v17 + v9) & (13586 * i)) )
  {
    v9 = (int)i++;
  }
  v10 = *(_QWORD *)(a2 + 24);
  v11 = 0;
  do
  {
    v12 = *(_WORD *)(v10 + v11);
    *(_WORD *)(v8 + v11) = v12;
    v11 += 2;
  }
  while ( v12 != 0 );
  v13 = 0;
  do
  {
    v14 = *(_WORD *)((char *)v17 + v13);
    *(_WORD *)(v11 + v8 + v13 - 2) = v14;
    v13 += 2;
  }
  while ( v14 != 0 );
  sub_140031DB0(v8, (unsigned int)&v21, 1048577, 3, 1, 96, 128);
  return off_1400373E0();
}


// ---- sub_14000D616 @ 0x14000d616 ----
__int64 __fastcall sub_14000D616()
{
  int v0; // r12d

  switch ( v0 >= 0 )
  {
    case false:
      return 0;
    case true:
      JUMPOUT(0x14000D511LL);
  }
}


// ---- sub_14000E0E0 @ 0x14000e0e0 ----
__int64 __fastcall sub_14000E0E0()
{
  __int64 v0; // r12
  __int64 v1; // r15

  return (*(__int64 (**)(void))(v1 + 8LL * (*(_QWORD *)(v0 + 8) != 0)))();
}


// ---- sub_14000E4A0 @ 0x14000e4a0 ----
__int64 __fastcall sub_14000E4A0(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // r10d
  int v5; // esi
  __int64 result; // rax
  __int64 v7; // r11
  int v8; // edi
  int v9; // ecx
  int v10; // ecx
  unsigned int v11; // ecx

  v3 = 0;
  if ( a2 != 0 )
  {
    v5 = -8;
    result = 0;
    v7 = 0;
    while ( 1 )
    {
      v8 = *(unsigned __int8 *)(a1 + v7);
      if ( v8 != 46 && v8 != 61 )
      {
        v9 = -65;
        if ( (unsigned __int8)(v8 - 65) >= 0x1Au && (v9 = -71, (unsigned __int8)(v8 - 97) >= 0x1Au) )
        {
          if ( (unsigned __int8)(v8 - 48) <= 9u )
          {
            v10 = v8 + 4;
LABEL_18:
            v3 = v10 | (v3 << 6);
            v11 = v5 + 6;
            if ( v5 >= -6 )
            {
              *(_BYTE *)(a3 + result) = v3 >> v11;
              v11 = (v11 & 0xFFFFFFF7) - ((9 - (_BYTE)v5) & 8);
              ++result;
            }
            v5 = v11;
            goto LABEL_21;
          }
          if ( *(unsigned __int8 *)(a1 + v7) > 0x2Eu )
          {
            if ( v8 == 95 || v8 == 47 )
            {
              v10 = 63;
              goto LABEL_18;
            }
          }
          else
          {
            v10 = 62;
            if ( v8 == 43 || v8 == 45 )
              goto LABEL_18;
          }
        }
        else
        {
          v10 = v8 + v9;
          if ( v10 >= 0 )
            goto LABEL_18;
        }
      }
LABEL_21:
      if ( v8 != 46 && v8 != 61 && a2 != ++v7 )
        continue;
      return result;
    }
  }
  return 0;
}


// ---- sub_14000E580 @ 0x14000e580 ----
__int64 __fastcall sub_14000E580(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int128 v3; // xmm6
  int v6; // r9d
  __int64 v7; // rcx
  int v8; // eax
  __int64 v9; // r8
  int v10; // eax
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // r15
  unsigned __int64 v14; // r12
  unsigned __int64 v15; // rbx
  unsigned __int64 v16; // rsi
  __int64 v17; // r14
  __int64 v18; // rax
  int v19; // r9d
  __int64 v20; // rdx
  int v21; // r8d
  int v22; // r10d
  int v23; // ecx
  int v24; // ecx
  unsigned int v25; // ecx
  __int64 v26; // rdi
  __int64 (__fastcall *v27)(__m256 *, _QWORD, __int64); // rax
  __int64 v28; // rcx
  unsigned int (__fastcall *v29)(__m256 *, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, __m256 *); // rax
  __int64 result; // rax
  int v31; // eax
  __int64 v32; // r8
  int v33; // eax
  unsigned int (__fastcall *v34)(__m256 *, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, unsigned __int64 *); // rax
  __int64 v35; // rax
  unsigned __int64 v36; // r15
  char *v37; // rdi
  __int64 v38; // rax
  __int64 (__fastcall *v39)(__m256 *, _QWORD, __int64); // rax
  __int64 v40; // rcx
  int v41; // ecx
  __int64 v42; // r10
  int v43; // ecx
  __int64 v44; // rsi
  int v45; // ecx
  __int64 v46; // rsi
  __int64 v47; // r13
  unsigned int (__fastcall *v48)(__int64 *, __m256 *, _QWORD); // rax
  __int64 v49; // rcx
  void (__fastcall *v50)(__int64); // r12
  unsigned int (__fastcall *v51)(__int64, __int64 *, __m256 *, _QWORD, _DWORD); // rax
  __int64 v52; // rcx
  unsigned int (__fastcall *v53)(__int64, char *, __int64, _QWORD, __m256 *, int, unsigned int *, int); // rax
  int v54; // eax
  __int64 v55; // r8
  int v56; // eax
  __int64 v57; // rdi
  __int64 v58; // rcx
  __int64 v59; // rax
  bool v60; // zf
  __int64 v61; // r12
  int v62; // eax
  __int64 v63; // rcx
  __int64 v64; // rax
  char v65; // dl
  __int64 v66; // rcx
  char v67; // r8
  __int64 v68; // rdx
  __int64 v69; // rcx
  __int64 v70; // rax
  bool v71; // cc
  __int64 v72; // rcx
  __int64 v73; // rdi
  int v74; // eax
  __int64 v75; // rcx
  __int64 v76; // rax
  __int16 v77; // dx
  __int64 v78; // rcx
  __int16 v79; // r8
  __int64 v80; // r14
  int v81; // r9d
  float v82; // r15d
  __int64 v83; // rdx
  __int64 v84; // rsi
  int v85; // eax
  __int64 v86; // rax
  __int16 v87; // cx
  __int64 v88; // rcx
  __int16 v89; // r8
  __int64 v90; // rax
  __m256 *v91; // rdi
  __int64 v92; // rax
  __int64 v93; // r15
  __int64 v94; // rcx
  __int64 v95; // rax
  __int64 v96; // rcx
  __int64 v97; // rax
  __int16 v98; // cx
  __int16 v99; // cx
  __int64 v100; // rcx
  __int64 v101; // rdx
  __int16 v102; // r9
  __int16 *v103; // rax
  __int64 v104; // r15
  __int64 v105; // rcx
  __int64 v106; // rdx
  __int64 v107; // rcx
  __int64 v108; // r15
  int v109; // edx
  __int64 v110; // r15
  __int64 v111; // rcx
  __int16 v112; // dx
  _BYTE *v113; // r12
  __int64 v114; // rsi
  _BYTE *v115; // rbx
  __int16 *v116; // r14
  __int16 *v117; // rcx
  __int16 v118; // dx
  __int16 v119; // ax
  __int64 v120; // r15
  __int64 v121; // rax
  __int16 *v122; // rcx
  int v123; // edx
  unsigned __int64 v124; // rdx
  __int16 v125; // r9
  __int16 v126; // r9
  __int64 v127; // r12
  int v128; // eax
  int v129; // ecx
  __int64 v130; // rbx
  __int64 v131; // rcx
  __int16 *v132; // rax
  __int64 v133; // rcx
  __int64 v134; // rdx
  __int16 v135; // cx
  __int16 *v136; // rcx
  __int16 *v137; // rbx
  __int64 v138; // r14
  __int16 v139; // r8
  __int16 v140; // ax
  __int64 v141; // rax
  __int16 *v142; // rcx
  __int64 v143; // rdx
  __int64 v144; // r15
  __int16 *v145; // rdx
  char *v146; // rax
  __int64 v147; // r8
  __int16 v148; // r9
  __int16 v149; // ax
  __int64 v150; // r15
  int v151; // eax
  int v152; // ecx
  __int64 v153; // rdi
  __int64 v154; // rcx
  int v155; // eax
  __int64 v156; // [rsp+20h] [rbp-418h]
  __int64 v157; // [rsp+20h] [rbp-418h]
  __int64 v158; // [rsp+28h] [rbp-410h]
  __int64 v159; // [rsp+28h] [rbp-410h]
  __int64 v160; // [rsp+58h] [rbp-3E0h] BYREF
  __m256 v161; // [rsp+60h] [rbp-3D8h] BYREF
  __int64 v162; // [rsp+80h] [rbp-3B8h] BYREF
  __int64 v163; // [rsp+88h] [rbp-3B0h] BYREF
  unsigned int i; // [rsp+94h] [rbp-3A4h] BYREF
  __int64 v165; // [rsp+98h] [rbp-3A0h] BYREF
  unsigned __int64 v166; // [rsp+A0h] [rbp-398h] BYREF
  char *v167; // [rsp+A8h] [rbp-390h]
  __int64 v168; // [rsp+B0h] [rbp-388h]
  __int64 v169; // [rsp+C0h] [rbp-378h]
  __m256 v170; // [rsp+D0h] [rbp-368h] BYREF
  __int128 v171; // [rsp+F0h] [rbp-348h]
  __int128 v172; // [rsp+100h] [rbp-338h]
  __int128 v173; // [rsp+110h] [rbp-328h]
  _BYTE v174[6]; // [rsp+25Ah] [rbp-1DEh] BYREF
  __m256 v175; // [rsp+260h] [rbp-1D8h] BYREF
  __int128 v176; // [rsp+3E0h] [rbp-58h]

  v176 = v3;
  v169 = a1;
  v160 = sub_140011CA0();
  switch ( v160 != 0 )
  {
    case false:
      goto LABEL_2;
    case true:
      v170.m256_f32[0] = 0.0;
      v8 = 1487506937;
      do
      {
        ++LODWORD(v170.m256_f32[0]);
        v8 ^= (LODWORD(v170.m256_f32[0]) & 0xA7567203) * (LODWORD(v170.m256_f32[0]) & 0x58A98DFC ^ 0x58A98DFC)
            + (LODWORD(v170.m256_f32[0]) & 0x58A98DFC) * (LODWORD(v170.m256_f32[0]) | 0x18A98DFC);
      }
      while ( LODWORD(v170.m256_f32[0]) == 0 );
      if ( qword_14003BB50 == 0 )
        goto LABEL_10;
      v9 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v9) != -1741979504 )
      {
        if ( qword_14003BB50 == ++v9 )
        {
LABEL_10:
          v170.m256_f32[0] = 0.0;
          v10 = 1371358003;
          do
          {
            ++LODWORD(v170.m256_f32[0]);
            v10 ^= -1371358004 * LODWORD(v170.m256_f32[0]);
          }
          while ( LODWORD(v170.m256_f32[0]) == 0 );
          switch ( v10 >= 0 )
          {
            case false:
              goto LABEL_13;
            case true:
              goto LABEL_16;
          }
        }
      }
      break;
  }
  switch ( (int)sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v9 + 4), 4, -2, v8, (__int64)&v160, 8) >= 0 )
  {
    case false:
LABEL_13:
      if ( qword_14003BB50 != 0 )
      {
        v68 = 0;
        do
        {
          if ( *(_DWORD *)(qword_14003BB58 + 8 * v68) == -1825720177 )
          {
            sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v68 + 4), 1, v160, v6, v156, v158);
            goto LABEL_2;
          }
          ++v68;
        }
        while ( qword_14003BB50 != v68 );
      }
      v170.m256_f32[0] = 0.0;
      do
        ++LODWORD(v170.m256_f32[0]);
      while ( LODWORD(v170.m256_f32[0]) == 0 );
LABEL_2:
      v7 = *(_QWORD *)(a2 + 32);
      switch ( v7 != 0 )
      {
        case false:
          break;
        case true:
          switch ( (unsigned __int8)sub_140030290(v7, &v170) )
          {
            case 0u:
              goto LABEL_125;
            case 1u:
              switch ( (unsigned __int8)sub_140011F00(v169, *(_QWORD *)v170.m256_f32, a2) )
              {
                case 0u:
                  goto LABEL_125;
                case 1u:
                  goto LABEL_218;
              }
          }
      }
LABEL_125:
      v69 = -2;
      do
      {
        v60 = *(_WORD *)(*(_QWORD *)(a2 + 24) + v69 + 2) == 0;
        v69 += 2;
      }
      while ( !v60 );
      v70 = v69 + 28;
      v71 = v69 < -29;
      v72 = -1;
      if ( !v71 )
        v72 = v70;
      v73 = sub_14002E070(v72);
      *(_OWORD *)&v170.m256_f32[3] = *(__int128 *)((char *)&xmmword_140033DAA + 12);
      *(_OWORD *)v170.m256_f32 = xmmword_140033DAA;
      v175.m256_f32[0] = 0.0;
      do
      {
        v74 = LODWORD(v175.m256_f32[0])++;
        *((_WORD *)v170.m256_f32 + v74) = (*((_WORD *)v170.m256_f32 + v74)
                                         | ((LOWORD(v175.m256_f32[0]) & 0xB5D2 ^ 0xB5D2)
                                          * (LOWORD(v175.m256_f32[0]) & 0x4A2D)
                                          + (LOWORD(v175.m256_f32[0]) & 0xB5D2) * (LOWORD(v175.m256_f32[0]) | 0xB5D2)))
                                        ^ *((_WORD *)v170.m256_f32 + v74)
                                        & ((LOWORD(v175.m256_f32[0]) & 0xB5D2 ^ 0xB5D2)
                                         * (LOWORD(v175.m256_f32[0]) & 0x4A2D)
                                         + (LOWORD(v175.m256_f32[0]) & 0xB5D2) * (LOWORD(v175.m256_f32[0]) | 0xB5D2));
      }
      while ( LODWORD(v175.m256_f32[0]) < 0xE );
      v75 = *(_QWORD *)(a2 + 24);
      v76 = 0;
      do
      {
        v77 = *(_WORD *)(v75 + v76);
        *(_WORD *)(v73 + v76) = v77;
        v76 += 2;
      }
      while ( v77 != 0 );
      v78 = 0;
      do
      {
        v79 = *(_WORD *)((char *)v170.m256_f32 + v78);
        *(_WORD *)(v76 + v73 + v78 - 2) = v79;
        v78 += 2;
      }
      while ( v79 != 0 );
      if ( (int)sub_140031DB0(v73, (unsigned int)&v170, 1179785, 3, 1, 96, 128) < 0 )
      {
        sub_140001C10(v73);
      }
      else
      {
        v80 = 0;
        if ( (int)sub_140032460(*(_QWORD *)v170.m256_f32, &v175, 0) >= 0 )
        {
          v82 = v175.m256_f32[0];
          v80 = sub_14002E070((LODWORD(v175.m256_f32[0]) & 0xFFFFFFFE) + 2LL);
          if ( (int)sub_140032540(*(_QWORD *)v170.m256_f32, v80, LODWORD(v82), 0) < 0 )
            JUMPOUT(0x1400108BELL);
          *(_WORD *)(v80 + 2LL * (LODWORD(v82) >> 1)) = 0;
        }
        if ( qword_14003BB50 == 0 )
LABEL_220:
          JUMPOUT(0x1400108D9LL);
        v83 = 0;
        while ( *(_DWORD *)(qword_14003BB58 + 8 * v83) != -1825720177 )
        {
          if ( qword_14003BB50 == ++v83 )
            goto LABEL_220;
        }
        sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v83 + 4), 1, LODWORD(v170.m256_f32[0]), v81, v157, v159);
        sub_140001C10(v73);
        if ( v80 != 0 )
          goto LABEL_213;
      }
      v84 = *(_QWORD *)(a2 + 16);
      sub_140001C20((__int64)&v175);
      v170.m256_f32[0] = 0.0;
      do
      {
        v85 = LODWORD(v170.m256_f32[0])++;
        *((_WORD *)v175.m256_f32 + v85) ^= (LOWORD(v170.m256_f32[0]) & 0x940E)
                                         * (LOWORD(v170.m256_f32[0]) & 0x6BF1 ^ 0x6BF1)
                                         + (LOWORD(v170.m256_f32[0]) & 0x6BF1) * (LOWORD(v170.m256_f32[0]) | 0x6BF1);
      }
      while ( LODWORD(v170.m256_f32[0]) < 0x47 );
      v86 = 0;
      do
      {
        v87 = *(_WORD *)((char *)v175.m256_f32 + v86);
        *(_WORD *)((char *)v170.m256_f32 + v86) = v87;
        v86 += 2;
      }
      while ( v87 != 0 );
      v88 = 0;
      do
      {
        v89 = *(_WORD *)(v84 + v88);
        *(_WORD *)((char *)v170.m256_f32 + v88 + v86 - 2) = v89;
        v88 += 2;
      }
      while ( v89 != 0 );
      v175 = ymmword_140033E54;
      v161.m256_f32[0] = 0.0;
      do
      {
        v90 = SLODWORD(v161.m256_f32[0]);
        ++LODWORD(v161.m256_f32[0]);
        *((_WORD *)v175.m256_f32 + v90) ^= 8720 * LOWORD(v161.m256_f32[0]);
      }
      while ( LODWORD(v161.m256_f32[0]) < 0x10 );
      v91 = &v175;
      v92 = sub_14002D260(&v170, &v175, &v166, 0);
      if ( v92 != 0 )
      {
        v93 = v92;
        v94 = -2;
        do
        {
          v60 = *(_WORD *)(*(_QWORD *)(a2 + 32) + v94 + 2) == 0;
          v94 += 2;
        }
        while ( !v60 );
        v95 = (((v166 >> 1) + 1) ^ (v94 >> 1)) + 2 * (((v166 >> 1) + 1) & (v94 >> 1));
        v96 = -1;
        if ( v95 >= 0 )
          v96 = 2 * v95;
        v80 = sub_14002E070(v96);
        v97 = 0;
        do
        {
          v98 = *(_WORD *)(v93 + v97);
          *(_WORD *)(v80 + v97) = v98;
          v97 += 2;
        }
        while ( v98 != 0 );
        v175.m256_f32[0] = 0.0;
        v99 = -10131;
        do
        {
          ++LODWORD(v175.m256_f32[0]);
          v99 ^= -10191 * LOWORD(v175.m256_f32[0]);
        }
        while ( LODWORD(v175.m256_f32[0]) == 0 );
        *(_WORD *)(v80 + v97 - 2) = v99;
        v100 = *(_QWORD *)(a2 + 32);
        v101 = 0;
        do
        {
          v102 = *(_WORD *)(v100 + v101);
          *(_WORD *)(v97 + v80 + v101) = v102;
          v101 += 2;
        }
        while ( v102 != 0 );
        sub_140001C10(v93);
      }
      else
      {
        v103 = *(__int16 **)(a2 + 16);
        if ( v103 != nullptr )
        {
          v104 = *(_QWORD *)(a2 + 8);
          v105 = 0;
          do
            v60 = *(_BYTE *)(v104 + v105++) == 0;
          while ( !v60 );
          v106 = v104 + v105 - 1;
          v107 = v104 & -(v104 + v105);
          v108 = v106 & ~v104;
          v161 = ymmword_140033E74;
          v175.m256_f32[0] = 0.0;
          do
          {
            v109 = LODWORD(v175.m256_f32[0])++;
            *((_WORD *)v161.m256_f32 + v109) = (*((_WORD *)v161.m256_f32 + v109)
                                              | ((LOWORD(v175.m256_f32[0]) & 0x8E50 ^ 0x8E50)
                                               * (LOWORD(v175.m256_f32[0]) & 0x71AF)
                                               + (LOWORD(v175.m256_f32[0]) & 0x8E50)
                                               * (LOWORD(v175.m256_f32[0]) | 0x8E50)))
                                             ^ *((_WORD *)v161.m256_f32 + v109)
                                             & ((LOWORD(v175.m256_f32[0]) & 0x8E50 ^ 0x8E50)
                                              * (LOWORD(v175.m256_f32[0]) & 0x71AF)
                                              + (LOWORD(v175.m256_f32[0]) & 0x8E50)
                                              * (LOWORD(v175.m256_f32[0]) | 0x8E50));
          }
          while ( LODWORD(v175.m256_f32[0]) < 0x10 );
          v110 = v108 - v107;
          v111 = 0;
          do
          {
            v112 = *(_WORD *)((char *)v161.m256_f32 + v111);
            *(_WORD *)((char *)v175.m256_f32 + v111) = v112;
            v111 += 2;
          }
          while ( v112 != 0 );
          v113 = &v174[v111 + 2];
          v114 = 5 - ((_QWORD)&v175 + v111);
          v115 = &v174[v111];
          v116 = (__int16 *)&v174[v111 + 4];
          do
          {
            v117 = v116;
            v118 = *v103++;
            ++v116;
            *v117 = v118;
            v115 += 2;
            v114 -= 2;
            v113 += 2;
          }
          while ( v118 != 0 );
          v161.m256_f32[0] = 0.0;
          v119 = 17459;
          do
          {
            ++LODWORD(v161.m256_f32[0]);
            v119 ^= (LOWORD(v161.m256_f32[0]) & 0x446F ^ 0x446F) * (LOWORD(v161.m256_f32[0]) & 0xBB90)
                  + (LOWORD(v161.m256_f32[0]) & 0x446F) * (LOWORD(v161.m256_f32[0]) | 0x446F);
          }
          while ( LODWORD(v161.m256_f32[0]) == 0 );
          *v117 = v119;
          v120 = v110 + 1;
          v121 = sub_1400068A0(v116, v120, *(unsigned __int8 **)(a2 + 8), 0);
          v122 = *(__int16 **)(a2 + 32);
          *(_OWORD *)&v161.m256_f32[3] = *(__int128 *)((char *)&xmmword_140033E94 + 12);
          *(_OWORD *)v161.m256_f32 = xmmword_140033E94;
          LODWORD(v160) = 0;
          do
          {
            v123 = v160;
            LODWORD(v160) = v160 + 1;
            *((_WORD *)v161.m256_f32 + v123) = (*((_WORD *)v161.m256_f32 + v123)
                                              | ((v160 & 0x56F) * (v160 & 0xFA90 ^ 0xFA90)
                                               + (v160 & 0xFA90) * (v160 | 0xFA90)))
                                             ^ *((_WORD *)v161.m256_f32 + v123)
                                             & ((v160 & 0x56F) * (v160 & 0xFA90 ^ 0xFA90)
                                              + (v160 & 0xFA90) * (v160 | 0xFA90));
          }
          while ( (unsigned int)v160 < 0xE );
          v124 = 0;
          do
          {
            v125 = *(_WORD *)((char *)v161.m256_f32 + v124);
            v116[v121 + v124 / 2] = v125;
            v124 += 2LL;
          }
          while ( v125 != 0 );
          do
          {
            v126 = *v122++;
            *(_WORD *)&v113[2 * v121 + v124] = v126;
            v124 += 2LL;
          }
          while ( v126 != 0 );
          v127 = (__int64)(((unsigned __int64)&v115[2 * v121 + v124] & ~(unsigned __int64)&v175)
                         - ((unsigned __int64)&v175 & (v114 - 2 * v121 - v124))) >> 1;
          v128 = sub_140031280(0, (unsigned int)&v175, v127, 0, 0, (__int64)&v160);
          v161.m256_f32[0] = 0.0;
          v129 = -2120995420;
          do
          {
            ++LODWORD(v161.m256_f32[0]);
            v129 ^= 1100230023 * LODWORD(v161.m256_f32[0]);
          }
          while ( LODWORD(v161.m256_f32[0]) == 0 );
          if ( v128 == v129 )
          {
            v130 = v160;
            v131 = -1;
            if ( v160 >= 0 )
              v131 = 2 * v160;
            v80 = sub_14002E070(v131);
            sub_140031280(0, (unsigned int)&v175, v127, v80, v130, (__int64)&v160);
            if ( (int)sub_140032240(v80, &v161) >= 0 && LODWORD(v161.m256_f32[0]) != -1 )
              goto LABEL_213;
            sub_140001C10(v80);
          }
          v132 = *(__int16 **)(a2 + 16);
          v161 = ymmword_140033EB0;
          LODWORD(v163) = 0;
          do
          {
            v133 = (int)v163;
            LODWORD(v163) = v163 + 1;
            *((_WORD *)v161.m256_f32 + v133) ^= 26322 * (_WORD)v163;
          }
          while ( (unsigned int)v163 < 0x10 );
          v134 = -4;
          do
          {
            v135 = *(_WORD *)((char *)&v161.m256_f32[1] + v134);
            LOWORD(v91->m256_f32[0]) = v135;
            v91 = (__m256 *)((char *)v91 + 2);
            v134 += 2;
          }
          while ( v135 != 0 );
          v136 = (__int16 *)&v91[-1].m256_f32[7] + 1;
          do
          {
            v137 = v136;
            v138 = v134;
            v139 = *v132++;
            ++v136;
            *v137 = v139;
            v134 += 2;
            v91 = (__m256 *)((char *)v91 + 2);
          }
          while ( v139 != 0 );
          v161.m256_f32[0] = 0.0;
          v140 = 7341;
          do
          {
            ++LODWORD(v161.m256_f32[0]);
            v140 ^= 7409 * LOWORD(v161.m256_f32[0]);
          }
          while ( LODWORD(v161.m256_f32[0]) == 0 );
          *v137 = v140;
          v141 = sub_1400068A0(v136, v120, *(unsigned __int8 **)(a2 + 8), 0);
          v142 = *(__int16 **)(a2 + 32);
          *(_OWORD *)&v161.m256_f32[3] = *(__int128 *)((char *)&xmmword_140033ED0 + 12);
          *(_OWORD *)v161.m256_f32 = xmmword_140033ED0;
          LODWORD(v163) = 0;
          do
          {
            v143 = (int)v163;
            LODWORD(v163) = v163 + 1;
            *((_WORD *)v161.m256_f32 + v143) = (*((_WORD *)v161.m256_f32 + v143)
                                              + (*((_WORD *)v161.m256_f32 + v143) ^ (-11506 * v163))
                                              - (*((_WORD *)v161.m256_f32 + v143) & ~(-11506 * v163)))
                                             & ~(*((_WORD *)v161.m256_f32 + v143) & (-11506 * v163));
          }
          while ( (unsigned int)v163 < 0xE );
          v144 = v138 + 2 * v141;
          v145 = &v137[v141];
          v146 = (char *)v91 + 2 * v141;
          v147 = -2;
          do
          {
            v148 = *(_WORD *)((char *)v161.m256_f32 + v147 + 2);
            *(_WORD *)&v146[v147] = v148;
            v144 += 2;
            v147 += 2;
            ++v145;
          }
          while ( v148 != 0 );
          do
          {
            v149 = *v142++;
            *v145++ = v149;
            v144 += 2;
          }
          while ( v149 != 0 );
          v150 = v144 >> 1;
          v151 = sub_140031280(0, (unsigned int)&v175, v150, 0, 0, (__int64)&v160);
          v161.m256_f32[0] = 0.0;
          v152 = -93186962;
          do
          {
            ++LODWORD(v161.m256_f32[0]);
            v152 ^= (LODWORD(v161.m256_f32[0]) & 0x3A72144D ^ 0x3A72144D) * (LODWORD(v161.m256_f32[0]) & 0xC58DEBB2)
                  + (LODWORD(v161.m256_f32[0]) & 0x3A72144D) * (LODWORD(v161.m256_f32[0]) | 0x3A72144D);
          }
          while ( LODWORD(v161.m256_f32[0]) == 0 );
          if ( v151 == v152 )
          {
            v153 = v160;
            v154 = -1;
            if ( v160 >= 0 )
              v154 = 2 * v160;
            v80 = sub_14002E070(v154);
            sub_140031280(0, (unsigned int)&v175, v150, v80, v153, (__int64)&v160);
            if ( (int)sub_140032240(v80, &v161) >= 0 && LODWORD(v161.m256_f32[0]) != -1 )
              goto LABEL_213;
            sub_140001C10(v80);
          }
        }
        v80 = 0;
      }
LABEL_213:
      switch ( v80 != 0 )
      {
        case false:
          *(_QWORD *)v170.m256_f32 = 0xFC12AE841BB18714uLL;
          LOWORD(v170.m256_f32[2]) = 21173;
          v175.m256_f32[0] = 0.0;
          do
          {
            v155 = LODWORD(v175.m256_f32[0])++;
            *((_BYTE *)v170.m256_f32 + v155) ^= 85 * LOBYTE(v175.m256_f32[0]);
          }
          while ( LODWORD(v175.m256_f32[0]) < 0xA );
          sub_140006360((unsigned __int8 *)&v170);
          break;
        case true:
          v168 = v80;
          JUMPOUT(0x14000FF8CLL);
      }
LABEL_218:
      JUMPOUT(0x140010925LL);
    case true:
LABEL_16:
      v11 = a3;
      do
        v12 = v11++;
      while ( *(_BYTE *)v12 != 0 );
      v13 = a3 & ~v12;
      v14 = v12 & ~a3;
      v15 = v14 - v13;
      v16 = (3 * (v14 - v13)) >> 2;
      if ( *(_BYTE *)(a3 + v14 - v13 - 1) == 61 )
      {
        if ( *(_BYTE *)(a3 + v15 - 2) == 61 )
        {
          if ( *(_BYTE *)(a3 + v15 - 3) == 61 )
            v16 -= 3LL;
          else
            v16 -= 2LL;
        }
        else
        {
          --v16;
        }
      }
      v17 = sub_14002E070(v16 + 1);
      if ( v14 == v13 )
        goto LABEL_48;
      v18 = 0;
      v19 = -8;
      v20 = 0;
      v21 = 0;
      break;
  }
  do
  {
    v22 = *(unsigned __int8 *)(a3 + v20);
    if ( v22 != 46 && v22 != 61 )
    {
      v23 = -65;
      if ( (unsigned __int8)(v22 - 65) >= 0x1Au && (v23 = -71, (unsigned __int8)(v22 - 97) >= 0x1Au) )
      {
        if ( (unsigned __int8)(v22 - 48) > 9u )
        {
          if ( *(unsigned __int8 *)(a3 + v20) > 0x2Eu )
          {
            if ( v22 != 95 && v22 != 47 )
              goto LABEL_45;
            v24 = 63;
          }
          else
          {
            v24 = 62;
            if ( v22 != 43 && v22 != 45 )
              goto LABEL_45;
          }
        }
        else
        {
          v24 = v22 + 4;
        }
      }
      else
      {
        v24 = v22 + v23;
        if ( v24 < 0 )
          goto LABEL_45;
      }
      v21 = v24 | (v21 << 6);
      v25 = v19 + 6;
      if ( v19 >= -6 )
      {
        *(_BYTE *)(v17 + v18) = v21 >> v25;
        v25 = (v25 & 0xFFFFFFF7) - ((9 - (_BYTE)v19) & 8);
        ++v18;
      }
      v19 = v25;
    }
LABEL_45:
    if ( v22 == 46 )
      break;
    if ( v22 == 61 )
      break;
    ++v20;
  }
  while ( v15 != v20 );
LABEL_48:
  LODWORD(v175.m256_f32[0]) = (v16 & 0xFFFFFFFB) - (~(_BYTE)v16 & 4);
  *(_QWORD *)&v175.m256_f32[2] = v17 + 4;
  v161.m256_f32[0] = 0.0;
  *(_QWORD *)&v161.m256_f32[2] = 0;
  v26 = sub_14002F7D0(2765091293LL);
  switch ( v26 == 0 )
  {
    case false:
      switch ( v26 != 0 )
      {
        case false:
          goto LABEL_54;
        case true:
          goto LABEL_53;
      }
    case true:
      v27 = (__int64 (__fastcall *)(__m256 *, _QWORD, __int64))sub_14002FDC0(qword_14003BA40, 2716158103LL);
      *(_OWORD *)v170.m256_f32 = xmmword_140033B8A;
      *(_QWORD *)&v170.m256_f32[4] = 0x814C8BB79606A09DuLL;
      LODWORD(v166) = 0;
      do
      {
        v28 = (int)v166;
        LODWORD(v166) = (v166 ^ 1) + 2 * (v166 & 1);
        *((_WORD *)v170.m256_f32 + v28) ^= -2703 * (_WORD)v166;
      }
      while ( (unsigned int)v166 < 0xC );
      v26 = v27(&v170, 0, 2048);
      switch ( v26 != 0 )
      {
        case false:
LABEL_54:
          result = off_1400376C0();
          break;
        case true:
LABEL_53:
          v29 = (unsigned int (__fastcall *)(__m256 *, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, __m256 *))sub_14002FDC0(v26, 189392399);
          switch ( v29(&v175, 0, 0, 0, 0, 0, &v161) != 0 )
          {
            case false:
              goto LABEL_54;
            case true:
              v163 = 0;
              v170.m256_f32[0] = 0.0;
              v31 = -1793556133;
              do
              {
                ++LODWORD(v170.m256_f32[0]);
                v31 ^= -1793556130 * LODWORD(v170.m256_f32[0]);
              }
              while ( LODWORD(v170.m256_f32[0]) == 0 );
              if ( qword_14003BB50 == 0 )
                goto LABEL_61;
              v32 = 0;
              while ( *(_DWORD *)(qword_14003BB58 + 8 * v32) != -1741979504 )
              {
                if ( qword_14003BB50 == ++v32 )
                {
LABEL_61:
                  v170.m256_f32[0] = 0.0;
                  v33 = 1371358003;
                  do
                  {
                    ++LODWORD(v170.m256_f32[0]);
                    v33 ^= -1371358004 * LODWORD(v170.m256_f32[0]);
                  }
                  while ( LODWORD(v170.m256_f32[0]) == 0 );
                  switch ( v33 >= 0 )
                  {
                    case false:
                      goto LABEL_66;
                    case true:
                      goto LABEL_65;
                  }
                }
              }
              switch ( (int)sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v32 + 4), 4, -2, v31, (__int64)&v163, 8) >= 0 )
              {
                case false:
LABEL_66:
                  LocalFree(*(HLOCAL *)&v161.m256_f32[2]);
                  result = off_1400376C0();
                  break;
                case true:
LABEL_65:
                  LODWORD(v166) = 0;
                  v167 = nullptr;
                  v34 = (unsigned int (__fastcall *)(__m256 *, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, unsigned __int64 *))sub_14002FDC0(v26, 189392399);
                  switch ( v34(&v161, 0, 0, 0, 0, 0, &v166) != 0 )
                  {
                    case false:
                      goto LABEL_66;
                    case true:
                      switch ( (unsigned int)v166 >= 4 )
                      {
                        case false:
LABEL_118:
                          LocalFree(v167);
                          LocalFree(*(HLOCAL *)&v161.m256_f32[2]);
                          result = off_1400376C0();
                          break;
                        case true:
                          v35 = *(unsigned int *)v167;
                          switch ( v35 != 0 )
                          {
                            case false:
                              goto LABEL_118;
                            case true:
                              v36 = *(unsigned int *)&v167[v35 + 4];
                              switch ( v36 != 0 )
                              {
                                case false:
                                  goto LABEL_118;
                                case true:
                                  v37 = &v167[v35];
                                  switch ( v167[v35 + 8] == 3 )
                                  {
                                    case false:
                                      goto LABEL_107;
                                    case true:
                                      v38 = sub_14002F7D0(1236396125);
                                      switch ( v38 == 0 )
                                      {
                                        case false:
                                          switch ( v38 != 0 )
                                          {
                                            case false:
                                              goto LABEL_107;
                                            case true:
                                              goto LABEL_76;
                                          }
                                        case true:
                                          v39 = (__int64 (__fastcall *)(__m256 *, _QWORD, __int64))sub_14002FDC0(
                                                                                                     qword_14003BA40,
                                                                                                     2716158103LL);
                                          *(_OWORD *)v170.m256_f32 = xmmword_140033BA2;
                                          *(_QWORD *)((char *)&v170.m256_f32[3] + 2) = 0x3285D0BA6F4B0D1CLL;
                                          LODWORD(v162) = 0;
                                          do
                                          {
                                            v40 = (int)v162;
                                            LODWORD(v162) = v162 + 1;
                                            *((_WORD *)v170.m256_f32 + v40) ^= 25007 * (_WORD)v162;
                                          }
                                          while ( (unsigned int)v162 < 0xB );
                                          v38 = v39(&v170, 0, 2048);
                                          switch ( v38 != 0 )
                                          {
                                            case false:
                                              goto LABEL_107;
                                            case true:
LABEL_76:
                                              v170.m256_f32[0] = 0.0;
                                              v41 = -779651899;
                                              do
                                              {
                                                ++LODWORD(v170.m256_f32[0]);
                                                v41 ^= -779651904 * LODWORD(v170.m256_f32[0]);
                                              }
                                              while ( LODWORD(v170.m256_f32[0]) == 0 );
                                              if ( qword_14003BB50 == 0 )
                                                goto LABEL_82;
                                              v42 = 0;
                                              break;
                                          }
                                          while ( *(_DWORD *)(qword_14003BB58 + 8 * v42) != -1741979504 )
                                          {
                                            if ( qword_14003BB50 == ++v42 )
                                            {
LABEL_82:
                                              v170.m256_f32[0] = 0.0;
                                              v43 = 1371358003;
                                              do
                                              {
                                                ++LODWORD(v170.m256_f32[0]);
                                                v43 ^= -1371358004 * LODWORD(v170.m256_f32[0]);
                                              }
                                              while ( LODWORD(v170.m256_f32[0]) == 0 );
                                              switch ( v43 >= 0 )
                                              {
                                                case false:
                                                  goto LABEL_107;
                                                case true:
                                                  goto LABEL_86;
                                              }
                                            }
                                          }
                                          v44 = v38;
                                          v45 = sub_14002F100(
                                                  *(_DWORD *)(qword_14003BB58 + 8 * v42 + 4),
                                                  4,
                                                  -2,
                                                  v41,
                                                  (__int64)&v160,
                                                  8);
                                          v38 = v44;
                                          switch ( v45 >= 0 )
                                          {
                                            case false:
                                              goto LABEL_107;
                                            case true:
LABEL_86:
                                              v46 = a2;
                                              v162 = 0;
                                              v47 = v38;
                                              v48 = (unsigned int (__fastcall *)(__int64 *, __m256 *, _QWORD))sub_14002FDC0(v38, 1218906422);
                                              v173 = xmmword_140033BF8;
                                              v172 = xmmword_140033BE8;
                                              v171 = xmmword_140033BD8;
                                              v170 = ymmword_140033BB8;
                                              LODWORD(v165) = 0;
                                              do
                                              {
                                                v49 = (int)v165;
                                                LODWORD(v165) = v165 + 1;
                                                *((_WORD *)v170.m256_f32 + v49) ^= -12817 * (_WORD)v165;
                                              }
                                              while ( (unsigned int)v165 < 0x28 );
                                              switch ( v48(&v162, &v170, 0) == 0 )
                                              {
                                                case false:
                                                  a2 = v46;
                                                  break;
                                                case true:
                                                  v50 = (void (__fastcall *)(__int64))sub_14002FDC0(v47, 3589784121LL);
                                                  v165 = 0;
                                                  v51 = (unsigned int (__fastcall *)(__int64, __int64 *, __m256 *, _QWORD, _DWORD))sub_14002FDC0(v47, 1168676662);
                                                  v170 = ymmword_140033C08;
                                                  LODWORD(v171) = 1224525023;
                                                  for ( i = 0;
                                                        i < 0x12;
                                                        *((_WORD *)v170.m256_f32 + v52) ^= -31730 * (_WORD)i )
                                                  {
                                                    v52 = (int)i++;
                                                  }
                                                  switch ( v51(v162, &v165, &v170, 0, 0) == 0 )
                                                  {
                                                    case false:
                                                      break;
                                                    case true:
                                                      v53 = (unsigned int (__fastcall *)(__int64, char *, __int64, _QWORD, __m256 *, int, unsigned int *, int))sub_14002FDC0(v47, 4023445044LL);
                                                      switch ( v53(v165, v37 + 9, 32, 0, &v170, 32, &i, 64) == 0 )
                                                      {
                                                        case false:
                                                          break;
                                                        case true:
                                                          sub_140001C40((__int64)(v37 + 9), (__int64)&v170, 0x20u);
                                                          break;
                                                      }
                                                      v50(v165);
                                                      break;
                                                  }
                                                  a2 = v46;
                                                  v50(v162);
                                                  break;
                                              }
                                              v163 = 0;
                                              v170.m256_f32[0] = 0.0;
                                              v54 = -1406279210;
                                              do
                                              {
                                                ++LODWORD(v170.m256_f32[0]);
                                                v54 = (v54
                                                     + ((-1406279213 * LODWORD(v170.m256_f32[0])) ^ v54)
                                                     - (v54 & ~(-1406279213 * LODWORD(v170.m256_f32[0]))))
                                                    & ~((-1406279213 * LODWORD(v170.m256_f32[0])) & v54);
                                              }
                                              while ( LODWORD(v170.m256_f32[0]) == 0 );
                                              if ( qword_14003BB50 != 0 )
                                              {
                                                v55 = 0;
                                                do
                                                {
                                                  if ( *(_DWORD *)(qword_14003BB58 + 8 * v55) == -1741979504 )
                                                  {
                                                    sub_14002F100(
                                                      *(_DWORD *)(qword_14003BB58 + 8 * v55 + 4),
                                                      4,
                                                      -2,
                                                      v54,
                                                      (__int64)&v163,
                                                      8);
                                                    goto LABEL_107;
                                                  }
                                                  ++v55;
                                                }
                                                while ( qword_14003BB50 != v55 );
                                              }
                                              v170.m256_f32[0] = 0.0;
                                              do
                                                ++LODWORD(v170.m256_f32[0]);
                                              while ( LODWORD(v170.m256_f32[0]) == 0 );
                                              break;
                                          }
                                          break;
                                      }
LABEL_107:
                                      *(_QWORD *)v170.m256_f32 = 0x60715C95E2D37568LL;
                                      LODWORD(v162) = 0;
                                      do
                                      {
                                        v56 = v162;
                                        LODWORD(v162) = v162 + 1;
                                        *((_BYTE *)v170.m256_f32 + v56) ^= 44 * (_BYTE)v162;
                                      }
                                      while ( (unsigned int)v162 < 8 );
                                      v57 = (__int64)(v37 + 8);
                                      sub_140006360((unsigned __int8 *)&v170);
                                      v58 = *(_QWORD *)(a2 + 8);
                                      v59 = 0;
                                      do
                                        v60 = *(_BYTE *)(v58 + v59++) == 0;
                                      while ( !v60 );
                                      v61 = sub_14002E070(((v58 + v59 - 1) & ~v58) - (v58 & -(v58 + v59)) + 8);
                                      *(_QWORD *)v170.m256_f32 = 0x48A61346D44B9346LL;
                                      LODWORD(v162) = 0;
                                      do
                                      {
                                        v62 = v162;
                                        LODWORD(v162) = v162 + 1;
                                        *((_BYTE *)v170.m256_f32 + v62) ^= (v162 & 0x96) * (v162 & 0x69 ^ 0x69)
                                                                         + (v162 & 0x69) * (v162 | 0x69);
                                      }
                                      while ( (unsigned int)v162 < 8 );
                                      v63 = *(_QWORD *)(a2 + 8);
                                      v64 = 0;
                                      do
                                      {
                                        v65 = *(_BYTE *)(v63 + v64);
                                        *(_BYTE *)(v61 + v64++) = v65;
                                      }
                                      while ( v65 != 0 );
                                      v66 = 0;
                                      do
                                      {
                                        v67 = *((_BYTE *)v170.m256_f32 + v66);
                                        *(_BYTE *)(v64 + v61 + v66++ - 1) = v67;
                                      }
                                      while ( v67 != 0 );
                                      sub_140003370(v169, v61, v57, v36);
                                      result = off_140037690();
                                      break;
                                  }
                                  break;
                              }
                              break;
                          }
                          break;
                      }
                      break;
                  }
                  break;
              }
              break;
          }
          break;
      }
      return result;
  }
}


// ---- sub_1400108AA @ 0x1400108aa ----
__int64 sub_1400108AA()
{
  return off_140037840();
}


// ---- sub_1400108B8 @ 0x1400108b8 ----
// positive sp value has been detected, the output may be wrong!
__int64 sub_1400108B8()
{
  return ((__int64 (*)(void))off_140037850)();
}


// ---- sub_140010970 @ 0x140010970 ----
__int64 __fastcall sub_140010970(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned __int64 a5)
{
  int v9; // eax
  unsigned int v10; // ebp
  __int64 v11; // rax
  char v12; // r15
  __int64 v13; // rax
  char v14; // r15
  __int64 v15; // rax
  __int64 result; // rax
  __int64 v17; // rax
  unsigned __int16 v18; // dx
  __int64 v19; // rax
  unsigned __int64 v20; // r15
  unsigned int j; // [rsp+40h] [rbp-98h]
  unsigned int k; // [rsp+40h] [rbp-98h]
  unsigned int m; // [rsp+40h] [rbp-98h]
  unsigned int i; // [rsp+40h] [rbp-98h]
  int n; // [rsp+40h] [rbp-98h]
  unsigned __int16 v26[24]; // [rsp+50h] [rbp-88h] BYREF

  v9 = *(_DWORD *)(a2 + 72);
  switch ( v9 & 1 )
  {
    case 0:
      v10 = 0;
      switch ( (v9 & 2) != 0 )
      {
        case false:
          goto LABEL_15;
        case true:
          goto LABEL_3;
      }
    case 1:
      *(_OWORD *)v26 = xmmword_140033F36;
      for ( i = 0;
            i < 8;
            v26[v17] = (v18 & (-16754 * i) | v18 ^ (-16754 * i))
                     + ((-2 - (v18 + ((-16754 * i) | ~v18))) | ~(v18 & (-16754 * i) | v18 ^ (-16754 * i)))
                     + 1 )
      {
        v17 = (int)i++;
        v18 = v26[v17];
      }
      v10 = sub_14000C520(a1, (_QWORD *)a2, a3, v26);
      LOBYTE(v9) = *(_BYTE *)(a2 + 72);
      switch ( (v9 & 2) != 0 )
      {
        case false:
LABEL_15:
          switch ( (v9 & 4) != 0 )
          {
            case false:
              goto LABEL_10;
            case true:
              goto LABEL_16;
          }
        case true:
LABEL_3:
          *(_OWORD *)v26 = xmmword_140033F46;
          *(_QWORD *)&v26[7] = 0x36F8EA31A61A509LL;
          for ( j = 0; j < 0xB; v26[v11] ^= 29869 * (_WORD)j )
            v11 = (int)j++;
          v12 = sub_14000C520(a1, (_QWORD *)a2, a3, v26);
          qmemcpy(v26, byte_140033F5C, 46);
          for ( k = 0; k < 0x17; v26[v13] ^= 10960 * (_WORD)k )
            v13 = (int)k++;
          v14 = sub_14000C520(a1, (_QWORD *)a2, a3, v26) | v12;
          *(_OWORD *)v26 = xmmword_140033F8A;
          v26[8] = -6059;
          for ( m = 0; m < 9; v26[v15] ^= -7955 * (_WORD)m )
            v15 = (int)m++;
          LOBYTE(v10) = sub_14000C520(a1, (_QWORD *)a2, a3, v26) | v14 | v10;
          LOBYTE(v9) = *(_BYTE *)(a2 + 72);
          switch ( (v9 & 4) != 0 )
          {
            case false:
LABEL_10:
              switch ( (v9 & 8) != 0 )
              {
                case false:
                  goto LABEL_19;
                case true:
                  goto LABEL_11;
              }
            case true:
LABEL_16:
              *(__m256 *)v26 = ymmword_140033F9C;
              for ( n = 0; (unsigned int)n < 0x10; v26[v19] ^= -26864 * (_WORD)n )
              {
                v19 = n;
                n = (n ^ 1) + 2 * (n & 1);
              }
              LOBYTE(v10) = sub_14000C520(a1, (_QWORD *)a2, a3, v26) | v10;
              switch ( (*(_BYTE *)(a2 + 72) & 8) != 0 )
              {
                case false:
LABEL_19:
                  switch ( a4 != 0 )
                  {
                    case false:
                      break;
                    case true:
                      v20 = 0;
                      switch ( a5 != 0 )
                      {
                        case false:
                          goto LABEL_22;
                        case true:
                          while ( 2 )
                          {
                            LOBYTE(v10) = sub_140011140(a1, a2, a3, a4 + 24 * v20++) | v10;
                            switch ( v20 < a5 )
                            {
                              case false:
                                goto LABEL_22;
                              case true:
                                continue;
                            }
                          }
                      }
                  }
LABEL_22:
                  LOBYTE(v10) = v10 & 1;
                  result = v10;
                  break;
                case true:
LABEL_11:
                  result = off_1400378F0();
                  break;
              }
              return result;
          }
      }
  }
}


// ---- sub_140010F69 @ 0x140010f69 ----
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_140010F69(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  __int64 v13; // rdi
  __int64 v14; // rax
  __int64 v15; // rdx
  bool v16; // zf
  __int64 v17; // rcx
  _WORD *v18; // rax
  __int64 v19; // rcx
  __int16 *v20; // rcx
  __int16 v21; // dx
  __int64 v22; // rcx
  __int16 v23; // dx
  unsigned int i; // [rsp+40h] [rbp+40h]

  v14 = -16777216;
  v15 = -2;
  do
  {
    v14 += 0x1000000;
    v16 = *(_WORD *)(*(_QWORD *)(v13 + 8) + v15 + 2) == 0;
    v15 += 2;
  }
  while ( !v16 );
  v17 = -1;
  if ( (v15 & 0x20000000000LL) == 0 )
    v17 = v14;
  v18 = (_WORD *)sub_14002E070(v17);
  *(_OWORD *)((char *)&a13 + 6) = *(__int128 *)((char *)&xmmword_140033FCC + 14);
  *(_OWORD *)&a12 = xmmword_140033FCC;
  *(_OWORD *)&a10 = xmmword_140033FBC;
  for ( i = 0; i < 0x17; *((_WORD *)&a10 + v19) ^= 19759 * (_WORD)i )
    v19 = (int)i++;
  v20 = *(__int16 **)(v13 + 8);
  do
  {
    v21 = *v20++;
    *v18++ = v21;
  }
  while ( v21 != 0 );
  v22 = 0;
  do
  {
    v23 = *(_WORD *)((char *)&a10 + v22 * 2);
    v18[v22++ - 1] = v23;
  }
  while ( v23 != 0 );
  JUMPOUT(0x140011043LL);
}


// ---- sub_140011140 @ 0x140011140 ----
__int64 sub_140011140()
{
  return off_140037978();
}


// ---- sub_140011AE5 @ 0x140011ae5 ----
// attributes: thunk
__int64 sub_140011AE5()
{
  return off_140037A30();
}


// ---- sub_140011AEB @ 0x140011aeb ----
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_140011AEB()
{
  __int64 v0; // rbp
  unsigned int v1; // esi
  __int64 *v2; // r14
  __int64 v3; // rcx

  sub_140001C10(*(_QWORD *)(v0 - 16));
  v3 = *v2;
  if ( *v2 != 0 && v3 != v2[1] )
  {
    sub_140001C10(v3);
    *(_OWORD *)v2 = 0;
    v2[2] = 0;
  }
  return v1;
}


// ---- sub_140011C87 @ 0x140011c87 ----
__int64 __fastcall sub_140011C87()
{
  __int64 v0; // rbp

  sub_140001C10(*(_QWORD *)(v0 - 8));
  return off_140037A30();
}


// ---- sub_140011CA0 @ 0x140011ca0 ----
__int64 sub_140011CA0()
{
  __int64 v0; // r8
  int v1; // eax
  __int64 v2; // rdx
  int v3; // eax
  __int64 v4; // rax
  __int64 v5; // rsi
  unsigned int i; // [rsp+38h] [rbp-B0h]
  WCHAR Name[8]; // [rsp+40h] [rbp-A8h] BYREF
  _WORD v9[16]; // [rsp+50h] [rbp-98h]
  _QWORD v10[10]; // [rsp+70h] [rbp-78h] BYREF
  struct _LUID Luid[2]; // [rsp+C0h] [rbp-28h] BYREF
  __int64 v12; // [rsp+D0h] [rbp-18h]

  *(_OWORD *)&Luid[0].LowPart = 0;
  memset(v10, 0, sizeof(v10));
  v12 = 0;
  if ( qword_14003BB50 != 0 )
  {
    v0 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v0) != 513242398 )
    {
      if ( qword_14003BB50 == ++v0 )
        goto LABEL_5;
    }
    if ( (int)sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v0 + 4), 5, -6, 1, (__int64)&v10[1], 84) < 0 )
      goto LABEL_23;
  }
  else
  {
LABEL_5:
    *(_DWORD *)Name = 0;
    v1 = 1371358003;
    do
    {
      ++*(_DWORD *)Name;
      v1 ^= -1371358004 * *(_DWORD *)Name;
    }
    while ( *(_DWORD *)Name == 0 );
    if ( v1 < 0 )
      goto LABEL_23;
  }
  if ( v10[1] != 0 && *(_BYTE *)v10[1] == 1 && *(_BYTE *)(v10[1] + 1LL) <= 0xFu && *(_WORD *)(v10[1] + 7LL) == 4613 )
  {
    if ( qword_14003BB50 != 0 )
    {
      v2 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v2) != -1848956125 )
      {
        if ( qword_14003BB50 == ++v2 )
          goto LABEL_18;
      }
      v3 = sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v2 + 4), 4, -6, 40, 0, (__int64)v10);
    }
    else
    {
LABEL_18:
      *(_DWORD *)Name = 0;
      v3 = 1371358003;
      do
      {
        ++*(_DWORD *)Name;
        v3 ^= -1371358004 * *(_DWORD *)Name;
      }
      while ( *(_DWORD *)Name == 0 );
    }
    if ( v3 >= 0 )
      return v10[0];
  }
LABEL_23:
  qmemcpy(v9, byte_140033B6C, 30);
  *(_OWORD *)Name = xmmword_140033B5C;
  for ( i = 0; i < 0x17; Name[v4] ^= 18834 * (_WORD)i )
    v4 = (int)i++;
  v5 = 0;
  if ( LookupPrivilegeValueW(nullptr, Name, (PLUID)&Luid[1].HighPart) )
  {
    sub_140030060(sub_1400133D0, v10);
    return v10[0];
  }
  return v5;
}


// ---- sub_140011F00 @ 0x140011f00 ----
__int64 __fastcall sub_140011F00(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // eax
  unsigned int v7; // r15d
  __int64 v8; // rdx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  __int64 v13; // rbp
  int v15; // eax
  int v16; // r9d
  __int64 v17; // rdx
  __int64 v18; // rax
  int v19; // edi
  int v20; // eax
  __int64 v21; // rbx
  int v22; // r15d
  int v23; // eax
  unsigned __int64 v24; // r14
  __int64 v25; // rax
  __int64 v26; // rbx
  __int64 v27; // rdx
  int v28; // eax
  int v29; // eax
  __int64 v30; // rax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  __int64 v34; // rax
  char v35; // dl
  char v36; // r8
  _QWORD *v37; // rax
  int v38; // ecx
  __int64 v39; // rax
  char v40; // cl
  __int64 v41; // rcx
  _QWORD *v42; // rax
  int v43; // ecx
  __int64 v44; // rax
  __int64 v45; // r9
  int v46; // ecx
  __int64 v47; // rax
  unsigned __int64 v48; // r10
  int v49; // eax
  __int64 v50; // rdx
  int v51; // eax
  signed int v52; // eax
  __int64 v53; // rdx
  int v54; // eax
  signed int v55; // eax
  int v56; // r9d
  signed int v57; // eax
  __int64 v58; // rdx
  __int64 v59; // rdx
  __int64 v60; // rdx
  __int64 v61; // rax
  __int64 v62; // rax
  __int64 v63; // rcx
  __int64 v65; // rax
  __int64 v66; // r15
  __int64 v67; // rax
  __int64 v68; // rdx
  __int64 v69; // rax
  char v70; // r8
  __int64 v71; // rdx
  char v72; // r9
  int v73; // eax
  __int64 v74; // [rsp+20h] [rbp-1C8h]
  __int64 v75; // [rsp+28h] [rbp-1C0h]
  _QWORD v76[2]; // [rsp+70h] [rbp-178h] BYREF
  char v77; // [rsp+80h] [rbp-168h]
  unsigned int i; // [rsp+8Ch] [rbp-15Ch]
  __int64 v79; // [rsp+90h] [rbp-158h] BYREF
  __int64 v80; // [rsp+98h] [rbp-150h] BYREF
  _BYTE v81[72]; // [rsp+A0h] [rbp-148h] BYREF
  __int64 v82; // [rsp+E8h] [rbp-100h] BYREF
  _QWORD v83[2]; // [rsp+F0h] [rbp-F8h] BYREF
  __int64 v84; // [rsp+100h] [rbp-E8h]
  unsigned __int64 v85; // [rsp+130h] [rbp-B8h]
  unsigned __int64 v86; // [rsp+138h] [rbp-B0h]
  char v87; // [rsp+148h] [rbp-A0h]
  __int64 v88; // [rsp+150h] [rbp-98h] BYREF
  __int64 v89; // [rsp+158h] [rbp-90h] BYREF
  __int64 v90; // [rsp+160h] [rbp-88h] BYREF
  __int64 v91; // [rsp+168h] [rbp-80h] BYREF
  __int128 v92; // [rsp+170h] [rbp-78h] BYREF
  __int64 v93; // [rsp+180h] [rbp-68h]
  char v94; // [rsp+190h] [rbp-58h] BYREF
  __int64 v95; // [rsp+198h] [rbp-50h]

  if ( a2 == 0 )
  {
    v83[0] = 0x407C79056F563D49LL;
    *(_DWORD *)v81 = 0;
    do
    {
      v11 = (*(_DWORD *)v81)++;
      *((_BYTE *)v83 + v11) ^= (v81[0] & 0xF7) * (v81[0] & 8 ^ 8) + (v81[0] & 8) * (v81[0] | 8);
    }
    while ( *(_DWORD *)v81 < 8u );
    goto LABEL_28;
  }
  if ( (int)sub_140030330(&v80, a2, 1082) < 0 )
  {
    v83[0] = 0x47EACA0C4585AF00LL;
    LODWORD(v83[1]) = 210095897;
    *(_DWORD *)v81 = 0;
    do
    {
      v12 = (*(_DWORD *)v81)++;
      *((_BYTE *)v83 + v12) ^= 65 * v81[0];
    }
    while ( *(_DWORD *)v81 < 0xCu );
    goto LABEL_28;
  }
  if ( (unsigned int)sub_1400302D0(v80) != 2 )
  {
    v83[0] = 0xDB17B3B203B78B12uLL;
    LOWORD(v83[1]) = 16035;
    *(_DWORD *)v81 = 0;
    do
    {
      v15 = (*(_DWORD *)v81)++;
      *((_BYTE *)v83 + v15) ^= 83 * v81[0];
    }
    while ( *(_DWORD *)v81 < 0xAu );
    sub_140006360((unsigned __int8 *)v83);
    LODWORD(v13) = 0;
    goto LABEL_34;
  }
  v92 = 0;
  v93 = 0;
  v91 = a3;
  *(_DWORD *)((char *)v83 + 3) = 1924735926;
  LODWORD(v83[0]) = -1237331649;
  *(_DWORD *)v81 = 0;
  do
  {
    v6 = (*(_DWORD *)v81)++;
    *((_BYTE *)v83 + v6) ^= 126 * v81[0];
  }
  while ( *(_DWORD *)v81 < 7u );
  sub_140006360((unsigned __int8 *)v83);
  if ( (int)sub_1400306E0(v80, sub_140014140, &v91) < 0 )
  {
    v7 = 0;
    do
    {
      v83[0] = -5000000;
      if ( qword_14003BB50 != 0 )
      {
        v8 = 0;
        while ( *(_DWORD *)(qword_14003BB58 + 8 * v8) != 1475872016 )
        {
          if ( qword_14003BB50 == ++v8 )
            goto LABEL_12;
        }
        sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v8 + 4), 2, 0, (unsigned int)v83, v74, v75);
      }
      else
      {
LABEL_12:
        *(_DWORD *)v81 = 0;
        do
          ++*(_DWORD *)v81;
        while ( *(_DWORD *)v81 == 0 );
      }
      if ( (int)sub_1400306E0(v80, sub_140014140, &v91) >= 0 )
        break;
    }
    while ( v7++ < 0xF );
  }
  if ( (_QWORD)v92 == 0 || *((_QWORD *)&v92 + 1) == 0 )
  {
    if ( (_QWORD)v92 != 0 )
    {
      v83[0] = 0xC5BB7E0EB357F68LL;
      LOWORD(v83[1]) = -26077;
      *(_DWORD *)v81 = 0;
      do
      {
        v10 = (*(_DWORD *)v81)++;
        *((_BYTE *)v83 + v10) ^= 41 * v81[0];
      }
      while ( *(_DWORD *)v81 < 0xAu );
    }
    else if ( *((_QWORD *)&v92 + 1) != 0 )
    {
      v83[0] = 0x52EF18C7C768E923LL;
      *(_DWORD *)((char *)v83 + 7) = 915488338;
      *(_DWORD *)v81 = 0;
      do
      {
        v29 = (*(_DWORD *)v81)++;
        *((_BYTE *)v83 + v29) = (*((_BYTE *)v83 + v29) | (98 * v81[0]))
                              & ((*((_BYTE *)v83 + v29) & (98 * v81[0])) + ~(2 * (*((_BYTE *)v83 + v29) & (98 * v81[0]))));
      }
      while ( *(_DWORD *)v81 < 0xBu );
    }
    else
    {
      v83[0] = 0xAA82E2BC3B19175CuLL;
      LOBYTE(v83[1]) = 5;
      *(_DWORD *)v81 = 0;
      do
      {
        v33 = (*(_DWORD *)v81)++;
        *((_BYTE *)v83 + v33) ^= 29 * v81[0];
      }
      while ( *(_DWORD *)v81 < 9u );
    }
LABEL_28:
    sub_140006360((unsigned __int8 *)v83);
LABEL_29:
    LODWORD(v13) = 0;
    return (unsigned int)v13;
  }
  v18 = sub_14002E1B0(v80, (unsigned int)&v92, 8, 0, 0, 0);
  if ( v18 == 0 )
  {
    *(_QWORD *)((char *)v83 + 6) = 0xECD77B90C57E8338uLL;
    v83[0] = 0x833855EF2740991BuLL;
    *(_DWORD *)v81 = 0;
    do
    {
      v30 = *(int *)v81;
      *(_DWORD *)v81 = (*(_DWORD *)v81 ^ 1) + 2 * (v81[0] & 1);
      *((_BYTE *)v83 + v30) ^= (v81[0] & 0xA5) * (v81[0] & 0x5A ^ 0x5A) + (v81[0] & 0x5A) * (v81[0] | 0x5A);
    }
    while ( *(_DWORD *)v81 < 0xEu );
    goto LABEL_28;
  }
  v19 = sub_140030630(v80, (unsigned __int8)v93 + (unsigned int)v18, (unsigned int)&v94, 24, 0);
  if ( v19 < 0 )
  {
    v83[0] = 0xE6DA2C441B710754uLL;
    LOWORD(v83[1]) = -11526;
    *(_DWORD *)v81 = 0;
    do
    {
      v32 = (*(_DWORD *)v81)++;
      *((_BYTE *)v83 + v32) ^= (v81[0] & 0x15 ^ 0x15) * (v81[0] & 0xEA) + (v81[0] & 0x15) * (v81[0] | 0x15);
    }
    while ( *(_DWORD *)v81 < 0xAu );
    sub_140006360((unsigned __int8 *)v83);
    LODWORD(v13) = 0;
    goto LABEL_73;
  }
  *(_DWORD *)((char *)v83 + 3) = 579257196;
  LODWORD(v83[0]) = 1822667023;
  *(_DWORD *)v81 = 0;
  do
  {
    v20 = (*(_DWORD *)v81)++;
    *((_BYTE *)v83 + v20) = (*((_BYTE *)v83 + v20) | (78 * v81[0]))
                          & ((*((_BYTE *)v83 + v20) & (78 * v81[0])) + ~(2 * (*((_BYTE *)v83 + v20) & (78 * v81[0]))));
  }
  while ( *(_DWORD *)v81 < 7u );
  sub_140006360((unsigned __int8 *)v83);
  if ( v95 == 0
    || (v21 = v80, (int)sub_140030630(v80, v95, (unsigned int)v83, 96, 0) < 0)
    || (unsigned __int8)sub_140014510(v21, v83) == 0 )
  {
    *(_QWORD *)v81 = 0x999BD0CB2908195BuLL;
    *(_DWORD *)&v81[8] = 944521662;
    LODWORD(v76[0]) = 0;
    do
    {
      v31 = LODWORD(v76[0])++;
      v81[v31] ^= (v76[0] & 0xE5) * (v76[0] & 0x1A ^ 0x1A) + (v76[0] & 0x1A) * (LOBYTE(v76[0]) | 0x1A);
    }
    while ( LODWORD(v76[0]) < 0xC );
    sub_140006360(v81);
    LODWORD(v13) = 0;
    if ( (*(_BYTE *)(a3 + 72) & 6) == 0 )
      goto LABEL_73;
LABEL_69:
    sub_1400139B0(a1, v80, a3);
    v83[0] = a1;
    v83[1] = a2;
    v84 = a3;
    sub_140030060(sub_1400147A0, v83);
    goto LABEL_73;
  }
  v22 = v85;
  v23 = 0;
  if ( v86 >= v85 )
    v23 = v85;
  LODWORD(v13) = v86 - v23;
  v24 = (unsigned int)(v86 - v23);
  v25 = sub_14002E070(v24);
  v26 = v25;
  if ( v87 == 1 )
  {
    v82 = 0;
    v90 = (unsigned int)v13;
    if ( qword_14003BB50 != 0 )
    {
      v27 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v27) != -1834021682 )
      {
        if ( qword_14003BB50 == ++v27 )
          goto LABEL_55;
      }
      v28 = sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v27 + 4), 6, v80, (unsigned int)&v82, 0, (__int64)&v90);
    }
    else
    {
LABEL_55:
      *(_DWORD *)v81 = 0;
      v28 = 1371358003;
      do
      {
        ++*(_DWORD *)v81;
        v28 ^= -1371358004 * *(_DWORD *)v81;
      }
      while ( *(_DWORD *)v81 == 0 );
    }
    if ( v28 < 0 )
    {
      LODWORD(v13) = 0;
    }
    else
    {
      BYTE2(v76[0]) = 39;
      LOWORD(v76[0]) = -23483;
      *(_DWORD *)v81 = 0;
      do
      {
        v34 = *(int *)v81;
        ++*(_DWORD *)v81;
        v35 = *((_BYTE *)v76 + v34);
        v36 = (v81[0] & 0xF2) * (v81[0] & 0xD ^ 0xD) + (v81[0] & 0xD) * (v81[0] | 0xD);
        *((_BYTE *)v76 + v34) = (v35 | v36) & (v35 + (v36 | ~v35) + ~(2 * (v35 + (v36 | ~v35)) + 2) + 1);
      }
      while ( *(_DWORD *)v81 < 3u );
      v37 = (_QWORD *)sub_140001C40((__int64)v81, (__int64)v76, 2u);
      *v37 = v85;
      BYTE2(v79) = -46;
      LOWORD(v79) = 13070;
      LODWORD(v76[0]) = 0;
      do
      {
        v38 = LODWORD(v76[0])++;
        *((_BYTE *)&v79 + v38) ^= (v76[0] & 0x46 ^ 0x46) * (v76[0] & 0xB9) + (v76[0] & 0x46) * (LOBYTE(v76[0]) | 0x46);
      }
      while ( LODWORD(v76[0]) < 3 );
      v39 = sub_140001C40((__int64)(v37 + 1), (__int64)&v79, 2u);
      *(_QWORD *)v39 = v82;
      LODWORD(v76[0]) = 0;
      v40 = -65;
      do
      {
        ++LODWORD(v76[0]);
        v40 = (v40 + (v40 ^ (5 * LOBYTE(v76[0]))) - (v40 & ~(5 * LOBYTE(v76[0])))) & ~(v40 & (5 * LOBYTE(v76[0])));
      }
      while ( LODWORD(v76[0]) == 0 );
      *(_BYTE *)(v39 + 8) = v40;
      *(_DWORD *)(v39 + 9) = v13;
      *(_OWORD *)v76 = xmmword_140033CD7;
      v77 = 30;
      LODWORD(v79) = 0;
      do
      {
        v41 = (int)v79;
        LODWORD(v79) = v79 + 1;
        *((_BYTE *)v76 + v41) = (*((_BYTE *)v76 + v41)
                               + (*((_BYTE *)v76 + v41) ^ (62 * v79))
                               - (*((_BYTE *)v76 + v41) & ~(62 * v79)))
                              & ~(*((_BYTE *)v76 + v41) & (62 * v79));
      }
      while ( (unsigned int)v79 < 0x11 );
      v42 = (_QWORD *)sub_140001C40(v39 + 13, (__int64)v76, 0x10u);
      *v42 = *((_QWORD *)&v92 + 1);
      BYTE2(v79) = 101;
      LOWORD(v79) = 3720;
      LODWORD(v76[0]) = 0;
      do
      {
        v43 = LODWORD(v76[0])++;
        *((_BYTE *)&v79 + v43) ^= 119 * LOBYTE(v76[0]);
      }
      while ( LODWORD(v76[0]) < 3 );
      v44 = sub_140001C40((__int64)(v42 + 1), (__int64)&v79, 2u);
      v79 = 0;
      v89 = 4096;
      if ( qword_14003BB50 != 0 )
      {
        v45 = 0;
        while ( *(_DWORD *)(qword_14003BB58 + 8 * v45) != -1834021682 )
        {
          if ( qword_14003BB50 == ++v45 )
            goto LABEL_95;
        }
        v13 = v44;
        v46 = sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v45 + 4), 6, v80, (unsigned int)&v79, 0, (__int64)&v89);
        v44 = v13;
      }
      else
      {
LABEL_95:
        LODWORD(v76[0]) = 0;
        v46 = 1371358003;
        do
        {
          ++LODWORD(v76[0]);
          v46 ^= -1371358004 * LODWORD(v76[0]);
        }
        while ( LODWORD(v76[0]) == 0 );
      }
      if ( v46 < 0 )
        goto LABEL_117;
      if ( qword_14003BB50 != 0 )
      {
        v47 = v44 - (_QWORD)v81;
        v48 = 0;
        while ( *(_DWORD *)(qword_14003BB58 + 8 * v48) != -705821472 )
        {
          v48 = (v48 ^ 1) + 2 * (v48 & 1);
          if ( v48 >= qword_14003BB50 )
            goto LABEL_105;
        }
        v49 = sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v48 + 4), 5, v80, v79, (__int64)v81, v47);
      }
      else
      {
LABEL_105:
        LODWORD(v76[0]) = 0;
        v49 = 1371358003;
        do
        {
          ++LODWORD(v76[0]);
          v49 ^= -1371358004 * LODWORD(v76[0]);
        }
        while ( LODWORD(v76[0]) == 0 );
      }
      if ( v49 < 0 )
      {
LABEL_117:
        LODWORD(v13) = 0;
      }
      else
      {
        v88 = 0;
        if ( qword_14003BB50 != 0 )
        {
          v50 = 0;
          while ( *(_DWORD *)(qword_14003BB58 + 8 * v50) != -2111626958 )
          {
            if ( qword_14003BB50 == ++v50 )
              goto LABEL_114;
          }
          v51 = sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v50 + 4), 11, (unsigned int)&v88, 0x1FFFFF, 0, v80);
        }
        else
        {
LABEL_114:
          LODWORD(v76[0]) = 0;
          v51 = 1371358003;
          do
          {
            ++LODWORD(v76[0]);
            v51 ^= -1371358004 * LODWORD(v76[0]);
          }
          while ( LODWORD(v76[0]) == 0 );
        }
        if ( v51 < 0 )
        {
          *(_QWORD *)((char *)v76 + 5) = 0x567CA88DCA236F58LL;
          v76[0] = 0x236F58AFF9CC716FLL;
          for ( i = 0; i < 0xD; *((_BYTE *)v76 + v55) ^= 46 * (_BYTE)i )
            v55 = i++;
          sub_140006360((unsigned __int8 *)v76);
          LODWORD(v13) = 0;
        }
        else
        {
          *(_DWORD *)((char *)v76 + 3) = 2047887257;
          LODWORD(v76[0]) = -1711980169;
          for ( i = 0; i < 7; *((_BYTE *)v76 + v52) ^= 54 * (_BYTE)i )
            v52 = i++;
          sub_140006360((unsigned __int8 *)v76);
          if ( qword_14003BB50 != 0 )
          {
            v53 = 0;
            while ( *(_DWORD *)(qword_14003BB58 + 8 * v53) != 577455468 )
            {
              if ( qword_14003BB50 == ++v53 )
                goto LABEL_126;
            }
            v54 = sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v53 + 4), 3, v88, 0, 0, v75);
          }
          else
          {
LABEL_126:
            LODWORD(v76[0]) = 0;
            v54 = 1371358003;
            do
            {
              ++LODWORD(v76[0]);
              v54 ^= -1371358004 * LODWORD(v76[0]);
            }
            while ( LODWORD(v76[0]) == 0 );
          }
          if ( v54 < 0 )
          {
            v76[0] = 0x2F24D662FD0BF32ELL;
            LODWORD(v76[1]) = 881926054;
            for ( i = 0; i < 0xC; *((_BYTE *)v76 + v57) ^= (i & 0x6F ^ 0x6F) * (i & 0x90) + (i & 0x6F) * (i | 0x6F) )
              v57 = i++;
            sub_140006360((unsigned __int8 *)v76);
            LODWORD(v13) = 0;
          }
          else
          {
            LOBYTE(v13) = (int)sub_140030630(v80, v82, v26, v24, 0) >= 0;
          }
          if ( qword_14003BB50 != 0 )
          {
            v58 = 0;
            while ( *(_DWORD *)(qword_14003BB58 + 8 * v58) != -1825720177 )
            {
              if ( qword_14003BB50 == ++v58 )
                goto LABEL_142;
            }
            sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v58 + 4), 1, v88, v56, v74, v75);
          }
          else
          {
LABEL_142:
            LODWORD(v76[0]) = 0;
            do
              ++LODWORD(v76[0]);
            while ( LODWORD(v76[0]) == 0 );
          }
        }
        v89 = 0;
        if ( qword_14003BB50 != 0 )
        {
          v59 = 0;
          while ( *(_DWORD *)(qword_14003BB58 + 8 * v59) != -289015568 )
          {
            if ( qword_14003BB50 == ++v59 )
              goto LABEL_150;
          }
          sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v59 + 4), 4, v80, (unsigned int)&v79, (__int64)&v89, 0x8000);
        }
        else
        {
LABEL_150:
          LODWORD(v76[0]) = 0;
          do
            ++LODWORD(v76[0]);
          while ( LODWORD(v76[0]) == 0 );
        }
      }
      v90 = 0;
      if ( qword_14003BB50 != 0 )
      {
        v60 = 0;
        while ( *(_DWORD *)(qword_14003BB58 + 8 * v60) != -289015568 )
        {
          if ( qword_14003BB50 == ++v60 )
            goto LABEL_158;
        }
        sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v60 + 4), 4, v80, (unsigned int)&v82, (__int64)&v90, 0x8000);
      }
      else
      {
LABEL_158:
        LODWORD(v76[0]) = 0;
        do
          ++LODWORD(v76[0]);
        while ( LODWORD(v76[0]) == 0 );
      }
    }
  }
  else
  {
    LOBYTE(v13) = (int)sub_140030630(v80, v22, v25, v13, 0) >= 0;
  }
  if ( (_BYTE)v13 != 0 )
  {
    *(_QWORD *)v81 = 0x38943E4ACE62E326LL;
    LODWORD(v76[0]) = 0;
    do
    {
      v61 = SLODWORD(v76[0]);
      ++LODWORD(v76[0]);
      v81[v61] = (v81[v61] | (103 * LOBYTE(v76[0]))) & (-2 - (v81[v61] + ((103 * LOBYTE(v76[0])) | ~v81[v61])));
    }
    while ( LODWORD(v76[0]) < 8 );
    sub_140006360(v81);
    v62 = *(_QWORD *)(a3 + 8);
    v63 = 0;
    while ( *(_BYTE *)(v62 + v63++) != 0 )
      ;
    v65 = ((v62 + v63 - 1) & ~v62) - (v62 & -(v62 + v63));
    v66 = sub_14002E070((v65 ^ 8) + 2 * (v65 & 8));
    *(_QWORD *)v81 = 0x1097A9E1F816050DLL;
    LODWORD(v76[0]) = 0;
    do
    {
      v67 = SLODWORD(v76[0]);
      ++LODWORD(v76[0]);
      v81[v67] = (v81[v67] | (34 * LOBYTE(v76[0]))) & (-2 - (v81[v67] + ((34 * LOBYTE(v76[0])) | ~v81[v67])));
    }
    while ( LODWORD(v76[0]) < 8 );
    v68 = *(_QWORD *)(a3 + 8);
    v69 = 0;
    do
    {
      v70 = *(_BYTE *)(v68 + v69);
      *(_BYTE *)(v66 + v69++) = v70;
    }
    while ( v70 != 0 );
    v71 = 0;
    do
    {
      v72 = v81[v71];
      *(_BYTE *)(v69 + v66 + v71++ - 1) = v72;
    }
    while ( v72 != 0 );
    LODWORD(v13) = sub_140003370(a1, v66, v26, v24);
    sub_140001C10(v66);
  }
  else
  {
    *(_QWORD *)v81 = 0xAAB476923D5B931EuLL;
    *(_DWORD *)&v81[7] = 367334058;
    LODWORD(v76[0]) = 0;
    do
    {
      v73 = LODWORD(v76[0])++;
      v81[v73] ^= 95 * LOBYTE(v76[0]);
    }
    while ( LODWORD(v76[0]) < 0xB );
    sub_140006360(v81);
  }
  sub_140001C10(v26);
  if ( (*(_BYTE *)(a3 + 72) & 6) != 0 )
    goto LABEL_69;
LABEL_73:
  if ( v19 < 0 )
    goto LABEL_29;
LABEL_34:
  if ( qword_14003BB50 != 0 )
  {
    v17 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v17) != -1825720177 )
    {
      if ( qword_14003BB50 == ++v17 )
        goto LABEL_38;
    }
    sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v17 + 4), 1, v80, v16, v74, v75);
  }
  else
  {
LABEL_38:
    LODWORD(v83[0]) = 0;
    do
      ++LODWORD(v83[0]);
    while ( LODWORD(v83[0]) == 0 );
  }
  return (unsigned int)v13;
}


// ---- sub_1400133D0 @ 0x1400133d0 ----
bool __fastcall sub_1400133D0(__int64 a1, __int64 a2)
{
  unsigned int v3; // r9d
  __int64 v4; // rdx
  int v5; // eax
  _BYTE **v6; // rdi
  __int64 v7; // rdx
  int v8; // eax
  _BYTE *v9; // rax
  __int64 v10; // rdx
  int v11; // eax
  int v12; // ecx
  _DWORD *v13; // rax
  __int64 v14; // r9
  int v15; // ecx
  _DWORD *v16; // rdi
  __int64 v17; // r8
  _DWORD *v18; // rdi
  __int64 v19; // rdx
  int v20; // eax
  __int64 v21; // rdx
  __int64 v22; // rax
  __int64 v23; // rdx
  __int64 v25; // [rsp+20h] [rbp-98h]
  __int64 v26; // [rsp+28h] [rbp-90h]
  int v27; // [rsp+44h] [rbp-74h]
  int i; // [rsp+48h] [rbp-70h] BYREF
  __int128 v29; // [rsp+50h] [rbp-68h]
  int v30; // [rsp+60h] [rbp-58h]
  __int64 v31; // [rsp+68h] [rbp-50h]
  __int64 *v32; // [rsp+70h] [rbp-48h]
  unsigned int v33; // [rsp+7Ch] [rbp-3Ch]
  __int64 v34; // [rsp+80h] [rbp-38h] BYREF
  int v35; // [rsp+8Ch] [rbp-2Ch]
  __int64 v36; // [rsp+90h] [rbp-28h] BYREF
  __int64 v37; // [rsp+9Ch] [rbp-1Ch] BYREF
  __int16 v38; // [rsp+A4h] [rbp-14h]

  if ( (int)sub_140030330(&v36, *(_QWORD *)(a1 + 80), 4096) < 0 )
    return *(_QWORD *)a2 != 0;
  if ( qword_14003BB50 == 0 )
  {
LABEL_6:
    i = 0;
    v5 = 1371358003;
    do
    {
      ++i;
      v5 ^= -1371358004 * i;
    }
    while ( i == 0 );
    if ( v5 >= 0 )
      goto LABEL_11;
LABEL_74:
    v22 = qword_14003BB50;
    if ( qword_14003BB50 == 0 )
    {
LABEL_78:
      for ( i = 0; i == 0; ++i )
        ;
      return *(_QWORD *)a2 != 0;
    }
    goto LABEL_75;
  }
  v4 = 0;
  while ( *(_DWORD *)(qword_14003BB58 + 8 * v4) != -1198997924 )
  {
    if ( qword_14003BB50 == ++v4 )
      goto LABEL_6;
  }
  if ( (int)sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v4 + 4), 3, v36, 10, (__int64)&v34, v26) < 0 )
    goto LABEL_74;
LABEL_11:
  v35 = 84;
  v6 = (_BYTE **)(a2 + 8);
  if ( qword_14003BB50 == 0 )
  {
LABEL_15:
    i = 0;
    v8 = 1371358003;
    do
    {
      ++i;
      v8 ^= -1371358004 * i;
    }
    while ( i == 0 );
    if ( v8 < 0 )
      goto LABEL_68;
    goto LABEL_20;
  }
  v7 = 0;
  while ( *(_DWORD *)(qword_14003BB58 + 8 * v7) != 513242398 )
  {
    if ( qword_14003BB50 == ++v7 )
      goto LABEL_15;
  }
  if ( (int)sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v7 + 4), 5, v34, 1, a2 + 8, 84) >= 0 )
  {
LABEL_20:
    v9 = *v6;
    if ( *v6 != nullptr && *v9 == 1 && v9[1] <= 0xFu && v9[7] == 5 && v9[8] == 18 )
    {
      if ( qword_14003BB50 != 0 )
      {
        v10 = 0;
        while ( *(_DWORD *)(qword_14003BB58 + 8 * v10) != 513242398 )
        {
          if ( qword_14003BB50 == ++v10 )
            goto LABEL_29;
        }
        v11 = sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v10 + 4), 5, v34, 3, 0, 0);
      }
      else
      {
LABEL_29:
        i = 0;
        v11 = 1371358003;
        do
        {
          ++i;
          v11 ^= -1371358004 * i;
        }
        while ( i == 0 );
      }
      i = 0;
      v12 = -1881645092;
      do
      {
        ++i;
        v3 = (i & 0x4FD85FFF ^ 0x5FFF) * (i & 0xB027A000);
        v12 ^= v3 + (i & 0x4FD85FFF) * (i | 0x4FD85FFF);
      }
      while ( i == 0 );
      if ( v11 == v12 )
      {
        v13 = (_DWORD *)sub_14002E070(v33);
        if ( qword_14003BB50 != 0 )
        {
          v14 = 0;
          while ( *(_DWORD *)(qword_14003BB58 + 8 * v14) != 513242398 )
          {
            if ( qword_14003BB50 == ++v14 )
              goto LABEL_40;
          }
          v16 = v13;
          v15 = sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v14 + 4), 5, v34, 3, (__int64)v13, v33);
          v13 = v16;
        }
        else
        {
LABEL_40:
          i = 0;
          v15 = 1371358003;
          do
          {
            ++i;
            v15 ^= -1371358004 * i;
          }
          while ( i == 0 );
        }
        if ( v15 >= 0 && *v13 != 0 )
        {
          v17 = 0;
          while ( LOBYTE(v13[v17 + 1]) != *(_BYTE *)(a2 + 92)
               || BYTE1(v13[v17 + 1]) != *(_BYTE *)(a2 + 93)
               || BYTE2(v13[v17 + 1]) != *(_BYTE *)(a2 + 94)
               || HIBYTE(v13[v17 + 1]) != *(_BYTE *)(a2 + 95)
               || LOBYTE(v13[v17 + 2]) != *(_BYTE *)(a2 + 96)
               || BYTE1(v13[v17 + 2]) != *(_BYTE *)(a2 + 97)
               || BYTE2(v13[v17 + 2]) != *(_BYTE *)(a2 + 98)
               || HIBYTE(v13[v17 + 2]) != *(_BYTE *)(a2 + 99) )
          {
            v17 += 3;
            if ( 3LL * (unsigned int)*v13 == v17 )
              goto LABEL_67;
          }
          v18 = v13;
          v37 = 0x20000000CLL;
          v38 = 1;
          i = 48;
          v31 = 0;
          v29 = 0;
          v30 = 0;
          v32 = &v37;
          if ( qword_14003BB50 != 0 )
          {
            v19 = 0;
            while ( *(_DWORD *)(qword_14003BB58 + 8 * v19) != 32145624 )
            {
              if ( qword_14003BB50 == ++v19 )
                goto LABEL_60;
            }
            v20 = sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v19 + 4), 6, v34, 0x2000000, (__int64)&i, 0);
          }
          else
          {
LABEL_60:
            v27 = 0;
            v20 = 1371358003;
            do
            {
              ++v27;
              v20 ^= -1371358004 * v27;
            }
            while ( v27 == 0 );
          }
          if ( v20 < 0 )
            *(_QWORD *)a2 = 0;
          v13 = v18;
        }
LABEL_67:
        sub_14002E0B0(v13);
      }
    }
  }
LABEL_68:
  if ( qword_14003BB50 == 0 )
  {
LABEL_72:
    for ( i = 0; i == 0; ++i )
      ;
    goto LABEL_74;
  }
  v21 = 0;
  while ( *(_DWORD *)(qword_14003BB58 + 8 * v21) != -1825720177 )
  {
    if ( qword_14003BB50 == ++v21 )
      goto LABEL_72;
  }
  sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v21 + 4), 1, v34, v3, v25, v26);
  v22 = qword_14003BB50;
  if ( qword_14003BB50 == 0 )
    goto LABEL_78;
LABEL_75:
  v23 = 0;
  while ( *(_DWORD *)(qword_14003BB58 + 8 * v23) != -1825720177 )
  {
    if ( v22 == ++v23 )
      goto LABEL_78;
  }
  sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v23 + 4), 1, v36, v3, v25, v26);
  return *(_QWORD *)a2 != 0;
}


// ---- sub_1400139B0 @ 0x1400139b0 ----
__int64 __fastcall sub_1400139B0(__int64 a1, int a2, _QWORD *a3)
{
  __int64 v5; // rdx
  int v6; // eax
  unsigned __int64 v7; // rbp
  unsigned __int64 v8; // rsi
  int v9; // eax
  unsigned __int8 *v10; // r14
  unsigned __int64 v11; // r15
  int v12; // edx
  int v13; // eax
  unsigned int v14; // r12d
  char v15; // al
  signed int v16; // eax
  __int64 v17; // rax
  char *v18; // r13
  __int64 v19; // rax
  __int64 v20; // rax
  __int64 v21; // rax
  __int64 v22; // rbx
  char *v23; // rax
  char *v24; // r15
  char *v25; // r12
  __int16 v26; // cx
  int v27; // esi
  __int64 v28; // rax
  __int64 v29; // rax
  __int64 v30; // r13
  unsigned __int64 v31; // rsi
  __int64 v32; // rcx
  __int64 v34; // rax
  _BYTE *v35; // rcx
  char v36; // dl
  __int16 v37; // dx
  __int64 v38; // r8
  __int64 v39; // rdx
  __int64 v40; // rcx
  __int64 v41; // r12
  __int64 v42; // rax
  __int16 v43; // cx
  unsigned __int64 v44; // rsi
  unsigned __int64 v45; // rax
  signed __int64 v46; // r13
  unsigned __int64 v47; // r15
  unsigned __int64 v48; // rax
  unsigned __int64 v49; // rdx
  __int64 v50; // rax
  unsigned int i; // [rsp+3Ch] [rbp-14Ch]
  unsigned int j; // [rsp+3Ch] [rbp-14Ch]
  unsigned int k; // [rsp+3Ch] [rbp-14Ch]
  unsigned int m; // [rsp+3Ch] [rbp-14Ch]
  _QWORD *v56; // [rsp+40h] [rbp-148h]
  unsigned __int64 v57; // [rsp+48h] [rbp-140h]
  _QWORD v58[6]; // [rsp+50h] [rbp-138h] BYREF
  __int64 v59; // [rsp+80h] [rbp-108h]
  __int64 v60; // [rsp+88h] [rbp-100h]
  __int128 v61; // [rsp+90h] [rbp-F8h] BYREF
  __int128 v62; // [rsp+A0h] [rbp-E8h]
  __int128 v63; // [rsp+B0h] [rbp-D8h]
  __int64 v64; // [rsp+D8h] [rbp-B0h]
  _QWORD v65[2]; // [rsp+E0h] [rbp-A8h] BYREF
  int v66; // [rsp+F0h] [rbp-98h]
  __m256 v67; // [rsp+100h] [rbp-88h] BYREF
  __int16 v68; // [rsp+120h] [rbp-68h]
  _QWORD v69[2]; // [rsp+130h] [rbp-58h] BYREF
  unsigned __int64 v70; // [rsp+140h] [rbp-48h]

  v64 = a1;
  if ( qword_14003BB50 != 0 )
  {
    v5 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v5) != -594858244 )
    {
      if ( qword_14003BB50 == ++v5 )
        goto LABEL_5;
    }
    if ( (int)sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v5 + 4), 4, 0, (unsigned int)&v61, 64, 0) < 0 )
      goto LABEL_10;
LABEL_8:
    v7 = *((_QWORD *)&v63 + 1);
    v8 = v63;
    goto LABEL_15;
  }
LABEL_5:
  LODWORD(v61) = 0;
  v6 = 1371358003;
  do
  {
    LODWORD(v61) = v61 + 1;
    v6 ^= -1371358004 * v61;
  }
  while ( (_DWORD)v61 == 0 );
  if ( v6 >= 0 )
    goto LABEL_8;
LABEL_10:
  LODWORD(v58[0]) = 0;
  v9 = 1789964336;
  do
  {
    ++LODWORD(v58[0]);
    v9 ^= (v58[0] & 0x6AB1B030 ^ 0x6AB1B030) * (v58[0] & 0x954E4FCF)
        + (v58[0] & 0x6AB1B030) * (LODWORD(v58[0]) | 0xAB1B030);
  }
  while ( LODWORD(v58[0]) == 0 );
  v7 = 0x7FFF7716D620LL;
  LODWORD(v58[0]) = 0;
  do
  {
    ++LODWORD(v58[0]);
    v7 ^= (SLODWORD(v58[0]) & 0xFFFFFFFF7716D620uLL) * (v58[0] & 0x88E929DF ^ 0x88E929DFLL)
        + (v58[0] & 0x88E929DF) * (SLODWORD(v58[0]) | 0x88E929DFLL);
  }
  while ( LODWORD(v58[0]) == 0 );
  v8 = v9;
LABEL_15:
  v10 = (unsigned __int8 *)sub_14002E070(536);
  LODWORD(v11) = 0;
  sub_140001B90(v10, 0, 0x218u);
  v63 = 0;
  v62 = 0;
  v61 = 0;
  if ( v8 < v7 )
  {
    v12 = v8;
    v11 = 0;
    v56 = a3;
    while ( 1 )
    {
      v13 = sub_140030560(a2, v12, 0, (unsigned int)&v61, 48, 0);
      if ( (unsigned int)v13 > 0xBFFFFFFF )
        goto LABEL_71;
      if ( v13 >= 0
        && (_DWORD)v63 == 4096
        && DWORD2(v63) == 0x40000
        && (BYTE4(v63) & 2) != 0
        && (int)sub_140030560(a2, v61, 2, (_DWORD)v10, 536, 0) >= 0 )
      {
        break;
      }
LABEL_20:
      v12 = v61 + DWORD2(v62);
      if ( (_QWORD)v61 + *((_QWORD *)&v62 + 1) >= v7 )
        goto LABEL_71;
    }
    v14 = *(unsigned __int16 *)v10;
    *(_WORD *)(*((_QWORD *)v10 + 1) + ((unsigned __int16)v14 & 0xFFFE)) = 0;
    v15 = *((_BYTE *)a3 + 72);
    if ( (v15 & 4) != 0 )
    {
      v67 = ymmword_140033D22;
      v68 = 3792;
      for ( i = 0;
            i < 0x11;
            *((_WORD *)v67.m256_f32 + v16) = (*((_WORD *)v67.m256_f32 + v16)
                                            | ((i & 0xF1D0 ^ 0xF1D0) * (i & 0xE2F) + (i & 0xF1D0) * (i | 0xF1D0)))
                                           ^ *((_WORD *)v67.m256_f32 + v16)
                                           & ((i & 0xF1D0 ^ 0xF1D0) * (i & 0xE2F) + (i & 0xF1D0) * (i | 0xF1D0)) )
      {
        v16 = i++;
      }
      v17 = sub_140014650(*((_QWORD *)v10 + 1), &v67);
      if ( v17 != 0 )
      {
        v18 = (char *)v17;
        v57 = v11;
        goto LABEL_41;
      }
      v15 = *((_BYTE *)a3 + 72);
    }
    if ( (v15 & 2) == 0 )
      goto LABEL_20;
    *(_OWORD *)v69 = xmmword_140033D44;
    v70 = 0xDF6437108F0AE7EAuLL;
    for ( j = 0; j < 0xC; *((_WORD *)v69 + v19) ^= -22541 * (_WORD)j )
      v19 = (int)j++;
    v20 = sub_140014650(*((_QWORD *)v10 + 1), v69);
    v57 = v11;
    if ( v20 != 0 )
      goto LABEL_40;
    qmemcpy(v58, byte_140033D5C, sizeof(v58));
    for ( k = 0; k < 0x18; *((_WORD *)v58 + v21) ^= 24082 * (_WORD)k )
      v21 = (int)k++;
    v20 = sub_140014650(*((_QWORD *)v10 + 1), v58);
    if ( v20 != 0 )
    {
LABEL_40:
      v18 = (char *)v20;
    }
    else
    {
      *(_OWORD *)v65 = xmmword_140033D8C;
      v66 = -907364904;
      for ( m = 0; m < 0xA; *((_WORD *)v65 + v50) ^= 5169 * (_WORD)m )
        v50 = (int)m++;
      v18 = (char *)sub_140014650(*((_QWORD *)v10 + 1), v65);
      if ( v18 == nullptr )
      {
        a3 = v56;
LABEL_19:
        v11 = v57;
        goto LABEL_20;
      }
    }
LABEL_41:
    v59 = v14 >> 1;
    v22 = *((_QWORD *)v10 + 1);
    *(_WORD *)v18 = 0;
    v23 = *((char **)v10 + 1);
    v24 = nullptr;
    do
    {
      v25 = v24;
      v26 = *(_WORD *)v23;
      if ( *(_WORD *)v23 == 92 )
        v24 = v23;
      v23 += 2;
    }
    while ( v26 != 0 );
    *(_WORD *)v18 = 92;
    v27 = DWORD2(v62);
    v28 = sub_14002E070(*((_QWORD *)&v62 + 1));
    v58[0] = 0;
    v60 = v28;
    if ( (int)sub_140030630(a2, v61, v28, v27, (__int64)v58) < 0 )
    {
      a3 = v56;
    }
    else
    {
      v29 = v18 - v25;
      v30 = (__int64)&v18[-v22];
      a3 = v56;
      v31 = v56[1];
      v32 = 0;
      while ( *(_BYTE *)(v31 + v32++) != 0 )
        ;
      v34 = sub_14002E070(v59 + (v29 >> 1) - ((v30 >> 1) + (v31 & -(__int64)(v31 + v32))) + ((v31 + v32 - 1) & ~v31) + 1);
      v35 = (_BYTE *)(v34 - 1);
      do
      {
        v36 = *(_BYTE *)v31++;
        *++v35 = v36;
      }
      while ( v36 != 0 );
      v37 = *(_WORD *)v24;
      if ( *(_WORD *)v24 != 0 )
      {
        v38 = 0;
        do
        {
          v35[v38] = v37;
          v37 = *(_WORD *)&v24[2 * v38++ + 2];
        }
        while ( v37 != 0 );
        v35 += v38;
      }
      *v35 = 0;
      if ( (unsigned __int8)sub_140003370(v64, v34, v60, *((unsigned __int64 *)&v62 + 1)) != 0 )
      {
        v39 = v59 - 0x4AA2BEBCDF54145LL - ((__int64)&v25[-*((_QWORD *)v10 + 1)] >> 1);
        v40 = 2 * v39 + 0x95457D79BEA828CLL;
        if ( v39 + 1 < (__int64)0xFB55D414320ABEBBuLL )
          v40 = -1;
        v41 = sub_14002E070(v40);
        v42 = 0;
        do
        {
          v43 = *(_WORD *)&v24[v42 + 2];
          *(_WORD *)(v41 + v42) = v43;
          v42 += 2;
        }
        while ( v43 != 0 );
        v44 = v56[6];
        v45 = v56[7];
        v46 = v45 - v44;
        if ( v45 == v56[8] )
        {
          v47 = (v46 >> 3) + ((unsigned __int64)(v46 >> 3) >> 1);
          if ( v47 <= (v46 >> 3) + 1 )
            v47 = (v46 >> 3) + 1;
          v48 = sub_140001B80(8 * v47);
          v49 = v44;
          v44 = v48;
          a3 = v56;
          if ( v49 != 0 )
          {
            sub_140001D60(v48, v49, v46);
            sub_140001C10(v56[6]);
          }
          v56[6] = v44;
          v56[7] = v44 + v46;
          v45 = v44 + 8 * v47;
          v56[8] = v45;
        }
        else
        {
          a3 = v56;
        }
        *(_QWORD *)(v44 + v46) = v41;
        a3[7] += 8LL;
        LOBYTE(v45) = 1;
        v57 = v45;
      }
    }
    sub_140001C10(v60);
    goto LABEL_19;
  }
LABEL_71:
  sub_14002E0B0(v10);
  LOBYTE(v11) = v11 & 1;
  return (unsigned int)v11;
}


// ---- sub_140014140 @ 0x140014140 ----
bool __fastcall sub_140014140(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rax
  __int64 v6; // r10
  __int16 v7; // r11
  __int16 v8; // si
  __int64 v9; // rbx
  signed int v10; // eax
  int v12; // esi
  __int64 v13; // rax
  int v14; // edx
  signed int v15; // edx
  int v16; // edi
  __int64 v17; // rax
  int v18; // eax
  __int16 v19; // r10
  __int16 v20; // r8
  __int64 v21; // rax
  __int16 v22; // r8
  __int16 v23; // r10
  unsigned int i; // [rsp+34h] [rbp-64h]
  unsigned int j; // [rsp+34h] [rbp-64h]
  __int64 v27; // [rsp+38h] [rbp-60h] BYREF
  _QWORD v28[10]; // [rsp+40h] [rbp-58h] BYREF

  if ( *(_QWORD *)(a5 + 8) == 0 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)a5 + 40LL);
    v6 = 0;
    do
    {
      v7 = *(_WORD *)(a4 + v6) | 0x20;
      if ( (unsigned __int16)(*(_WORD *)(a4 + v6) - 65) >= 0x1Au )
        v7 = *(_WORD *)(a4 + v6);
      v8 = *(_WORD *)(v5 + v6) | 0x20;
      if ( (unsigned __int16)(*(_WORD *)(v5 + v6) - 65) >= 0x1Au )
        v8 = *(_WORD *)(v5 + v6);
      if ( v7 == 0 )
        break;
      v6 += 2;
    }
    while ( v7 == v8 );
    if ( v7 == v8 )
    {
      v27 = 0x3EEEEEEFF87LL;
      v9 = (a2 ^ a3) + 2LL * (a3 & (unsigned int)a2);
      qmemcpy(v28, byte_140033C3F, 43);
      for ( i = 0; i < 0x2B; *((_BYTE *)v28 + v10) ^= (i & 0xC6) * (i & 0x39 ^ 0x39) + (i & 0x39) * (i | 0x39) )
        v10 = i++;
      v12 = a1;
      v13 = sub_14002E1B0(a1, (unsigned int)v28, 42, (unsigned int)&v27, a2, v9);
      *(_QWORD *)(a5 + 8) = v13;
      if ( v13 != 0 )
        goto LABEL_41;
      LODWORD(v28[0]) = 0;
      v14 = 416452255;
      do
      {
        ++LODWORD(v28[0]);
        v14 ^= 417100056 * LODWORD(v28[0]);
      }
      while ( LODWORD(v28[0]) == 0 );
      v27 = v14;
      *(_OWORD *)v28 = xmmword_140033C6A;
      *(_QWORD *)((char *)&v28[1] + 5) = 0x5952E3A1A5156E6LL;
      for ( j = 0; j < 0x15; *((_BYTE *)v28 + v15) ^= 49 * (_BYTE)j )
        v15 = j++;
      v13 = sub_14002E1B0(v12, (unsigned int)v28, 20, (unsigned int)&v27, a2, v9);
      *(_QWORD *)(a5 + 8) = v13;
      if ( v13 != 0 )
      {
LABEL_41:
        v16 = v13;
        v17 = (int)sub_140030630(v12, (int)v13 + 3, (unsigned int)v28, 4, 0) < 0
            ? 0LL
            : *(_QWORD *)(a5 + 8) + LODWORD(v28[0]) + 7;
        *(_QWORD *)(a5 + 8) = v17;
        if ( (int)sub_140030630(v12, v16 + 16, (int)a5 + 24, 1, 0) < 0 )
        {
          *(_BYTE *)(a5 + 24) = 16;
          if ( *(_QWORD *)(a5 + 8) != 0 )
            return *(_QWORD *)(a5 + 16) != 0;
          return false;
        }
      }
      goto LABEL_35;
    }
  }
  if ( *(_QWORD *)(a5 + 16) != 0 )
    goto LABEL_35;
  *(_OWORD *)v28 = xmmword_140033C80;
  LODWORD(v28[2]) = -1766553650;
  LODWORD(v27) = 0;
  do
  {
    v18 = v27;
    LODWORD(v27) = v27 + 1;
    v19 = *((_WORD *)v28 + v18);
    v20 = v19 & ((v27 & 0xF0ED) * (v27 & 0xF12 ^ 0xF12) + (v27 & 0xF12) * (v27 | 0xF12));
    *((_WORD *)v28 + v18) = (v19 | ((v27 & 0xF0ED) * (v27 & 0xF12 ^ 0xF12) + (v27 & 0xF12) * (v27 | 0xF12)))
                          & (v20 + ~(2 * v20));
  }
  while ( (unsigned int)v27 < 0xA );
  v21 = 0;
  do
  {
    v22 = *(_WORD *)(a4 + v21) | 0x20;
    if ( (unsigned __int16)(*(_WORD *)(a4 + v21) - 65) >= 0x1Au )
      v22 = *(_WORD *)(a4 + v21);
    v23 = *(_WORD *)((char *)v28 + v21) | 0x20;
    if ( (unsigned __int16)(*(_WORD *)((char *)v28 + v21) - 65) >= 0x1Au )
      v23 = *(_WORD *)((char *)v28 + v21);
    if ( v22 == 0 )
      break;
    v21 += 2;
  }
  while ( v22 == v23 );
  if ( v22 != v23 )
  {
LABEL_35:
    if ( *(_QWORD *)(a5 + 8) != 0 )
      return *(_QWORD *)(a5 + 16) != 0;
    return false;
  }
  *(_QWORD *)(a5 + 16) = sub_140030B40(a1, a2, 1324896975);
  if ( *(_QWORD *)(a5 + 8) != 0 )
    return *(_QWORD *)(a5 + 16) != 0;
  return false;
}


// ---- sub_140014510 @ 0x140014510 ----
char __fastcall sub_140014510(__int64 a1, __int64 a2)
{
  __int64 v4; // rcx
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rdx
  __int64 v7; // rax
  char v8; // cl
  int v9; // ecx
  char result; // al
  __int64 v11; // rdx
  __int64 v12; // rbx
  char v13; // cl
  char v14; // cl
  int v15; // [rsp+28h] [rbp-20h]
  _DWORD v16[7]; // [rsp+2Ch] [rbp-1Ch] BYREF

  v4 = *(char *)(a2 + 55);
  v5 = *(_QWORD *)(a2 + 40);
  v6 = v4;
  if ( v4 < 0 )
    v6 = v5;
  if ( v6 > 3 )
    goto LABEL_13;
  if ( (v4 & 0x80u) != 0LL )
  {
    v11 = *(_QWORD *)(a2 + 32);
    if ( v11 == 0 || (int)sub_140030630(a1, v11, (unsigned int)v16, (v5 ^ 1) + 2 * (v5 & 1), 0) < 0 )
      goto LABEL_13;
  }
  else
  {
    v7 = 0;
    do
    {
      v8 = *(_BYTE *)(a2 + v7 + 32);
      *((_BYTE *)v16 + v7++) = v8;
    }
    while ( v8 != 0 );
  }
  v15 = 0;
  v9 = 1279919115;
  do
  {
    ++v15;
    v9 ^= 1283077757 * v15;
  }
  while ( v15 == 0 );
  if ( v16[0] == v9 )
    return 1;
LABEL_13:
  v12 = *(_QWORD *)(a2 + 8);
  if ( *(_QWORD *)a2 == 0
    || (int)sub_140030630(a1, *(_QWORD *)a2, a2, 96, 0) < 0
    || (v13 = sub_140014510(a1, a2), result = 1, v13 == 0) )
  {
    if ( v12 == 0 )
      return 0;
    if ( (int)sub_140030630(a1, v12, a2, 96, 0) < 0 )
      return 0;
    v14 = sub_140014510(a1, a2);
    result = 1;
    if ( v14 == 0 )
      return 0;
  }
  return result;
}


// ---- sub_140014650 @ 0x140014650 ----
unsigned __int64 __fastcall sub_140014650(unsigned __int64 a1, unsigned __int16 *a2)
{
  unsigned __int64 result; // rax
  __int64 v3; // r9
  bool v4; // zf
  __int64 v5; // r8
  unsigned __int64 v6; // r9
  unsigned __int64 v7; // r8
  __int64 v8; // r9
  __int64 v9; // rax
  _WORD *v10; // r11
  unsigned __int16 v11; // r9
  _WORD *v12; // r10
  __int64 v13; // r10
  _WORD *v14; // rsi
  __int64 v15; // r11

  result = a1 - 2;
  v3 = -2;
  do
  {
    v3 += 2;
    v4 = *(_WORD *)(result + 2) == 0;
    result += 2LL;
  }
  while ( !v4 );
  v5 = 0x7FFFFFFFFFFFFFFFLL;
  do
    v4 = a2[++v5] == 0;
  while ( !v4 );
  if ( v5 != 0 )
  {
    v6 = v3 >> 1;
    v7 = (v5 * 2) >> 1;
    if ( v6 >= v7 )
    {
      v8 = v6 - v7;
      if ( v8 < 0 )
      {
        return 0;
      }
      else
      {
        v9 = ~(_BYTE)v7 & 2;
        v10 = (_WORD *)(a1 + 2 * v8);
        v11 = *a2;
        if ( (v7 & 0xFFFFFFFFFFFFFFFDuLL) == v9 )
        {
          result = 0;
          while ( *v10 == v11 )
          {
            v12 = v10;
LABEL_16:
            if ( v12[v7 - 1] == a2[v7 - 1] )
              return (unsigned __int64)v12;
            v10 = v12 - 1;
            if ( (unsigned __int64)(v12 - 1) < a1 )
              return result;
          }
          while ( v10 != (_WORD *)a1 )
          {
            v12 = v10 - 1;
            v4 = *--v10 == v11;
            if ( v4 )
              goto LABEL_16;
          }
        }
        else
        {
          v13 = (v7 & 0xFFFFFFFFFFFFFFFDuLL) - v9;
          result = 0;
          while ( *v10 == v11 )
          {
            v14 = v10;
LABEL_26:
            if ( v14[v7 - 1] == a2[v7 - 1] )
            {
              v15 = 0;
              while ( v13 != v15 )
              {
                v4 = *((_BYTE *)v14 + v15 + 2) == *((_BYTE *)a2 + v15 + 2);
                ++v15;
                if ( !v4 )
                  goto LABEL_21;
              }
              return (unsigned __int64)v14;
            }
LABEL_21:
            v10 = v14 - 1;
            if ( (unsigned __int64)(v14 - 1) < a1 )
              return result;
          }
          while ( v10 != (_WORD *)a1 )
          {
            v14 = v10 - 1;
            v4 = *--v10 == v11;
            if ( v4 )
              goto LABEL_26;
          }
        }
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}


// ---- sub_1400147A0 @ 0x1400147a0 ----
__int64 __fastcall sub_1400147A0(__int64 a1, __int64 a2)
{
  unsigned int v3; // esi
  int v4; // r9d
  __int64 v5; // rdx
  __int64 v7; // [rsp+20h] [rbp-18h]
  int i; // [rsp+24h] [rbp-14h]
  __int64 v9; // [rsp+28h] [rbp-10h] BYREF

  if ( *(_QWORD *)(a1 + 88) != *(_QWORD *)(a2 + 8) || (int)sub_140030330(&v9, *(_QWORD *)(a1 + 80), 1048) < 0 )
    return 0;
  v3 = sub_1400139B0(*(_QWORD *)a2, v9, *(_QWORD **)(a2 + 16));
  if ( qword_14003BB50 != 0 )
  {
    v5 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v5) != -1825720177 )
    {
      if ( qword_14003BB50 == ++v5 )
        goto LABEL_7;
    }
    sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v5 + 4), 1, v9, v4, v7, v9);
    return v3;
  }
  else
  {
LABEL_7:
    for ( i = 0; i == 0; ++i )
      ;
    return v3;
  }
}


// ---- sub_140014880 @ 0x140014880 ----
__int64 __fastcall sub_140014880(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD v5[4]; // [rsp+28h] [rbp-20h] BYREF

  v5[0] = a1;
  v5[1] = a2;
  v5[2] = a3;
  v5[3] = a4;
  return sub_140016E30(*(_QWORD *)(a2 + 24), 0, sub_1400166E0, v5);
}


// ---- sub_1400148C0 @ 0x1400148c0 ----
void __fastcall sub_1400148C0(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rdx
  __int64 v13; // r8
  __int64 v14; // r9
  void *v15; // rsp
  __int64 v16; // rcx
  __int64 v17; // r8
  void *v18; // rsp
  __int64 v19; // rdx
  __int64 v20; // rcx
  __int64 v21; // r8
  __int64 v22; // r9
  void *v23; // rsp
  __int64 v24; // rdx
  __int64 v25; // rcx
  __int64 v26; // r8
  __int64 v27; // r9
  void *v28; // rsp
  __int64 v29; // rdx
  __int64 v30; // rcx
  __int64 v31; // r8
  __int64 v32; // r9
  void *v33; // rsp
  __int64 v34; // rdx
  __int64 v35; // rcx
  __int64 v36; // r8
  __int64 v37; // r9
  void *v38; // rsp
  __int64 v39; // rdx
  __int64 v40; // rcx
  __int64 v41; // r8
  __int64 v42; // r9
  void *v43; // rsp
  __int64 v44; // rdx
  __int64 v45; // rcx
  __int64 v46; // r9
  void *v47; // rsp
  __int64 v48; // rdx
  __int64 v49; // rcx
  __int64 v50; // r8
  __int64 v51; // r9
  void *v52; // rsp
  __int64 v53; // rdx
  __int64 v54; // rcx
  __int64 v55; // r9
  void *v56; // rsp
  __int64 v57; // rdx
  __int64 v58; // rcx
  __int64 v59; // r8
  __int64 v60; // r9
  void *v61; // rsp
  __int64 v62; // rdx
  __int64 v63; // rcx
  __int64 v64; // r9
  void *v65; // rsp
  __int64 v66; // rdx
  __int64 v67; // rcx
  __int64 v68; // r8
  __int64 v69; // r9
  void *v70; // rsp
  __int64 v71; // rdx
  __int64 v72; // rcx
  __int64 v73; // r9
  void *v74; // rsp
  __int64 v75; // rdx
  __int64 v76; // rcx
  __int64 v77; // r8
  __int64 v78; // r9
  void *v79; // rsp
  __int64 v80; // rdx
  __int64 v81; // rcx
  __int64 v82; // r9
  void *v83; // rsp
  __int64 v84; // rdx
  __int64 v85; // rcx
  __int64 v86; // r8
  __int64 v87; // r9
  void *v88; // rsp
  __int64 v89; // rdx
  __int64 v90; // rcx
  __int64 v91; // r8
  __int64 v92; // r9
  void *v93; // rsp
  __int64 v94; // rdx
  __int64 v95; // rcx
  __int64 v96; // r8
  __int64 v97; // r9
  void *v98; // rsp
  __int64 v99; // rdx
  __int64 v100; // rcx
  __int64 v101; // r9
  void *v102; // rsp
  __int64 v103; // rdx
  __int64 v104; // rcx
  __int64 v105; // r8
  __int64 v106; // r9
  void *v107; // rsp
  __int64 v108; // rdx
  __int64 v109; // rcx
  __int64 v110; // r9
  void *v111; // rsp
  __int64 v112; // rdx
  __int64 v113; // rcx
  __int64 v114; // r8
  __int64 v115; // r9
  void *v116; // rsp
  __int64 v117; // rdx
  __int64 v118; // rcx
  __int64 v119; // r9
  void *v120; // rsp
  __int64 v121; // rdx
  __int64 v122; // rcx
  __int64 v123; // r8
  __int64 v124; // r9
  void *v125; // rsp
  __int64 v126; // rdx
  __int64 v127; // rcx
  __int64 v128; // r9
  void *v129; // rsp
  __int64 v130; // rdx
  __int64 v131; // rcx
  __int64 v132; // r8
  __int64 v133; // r9
  void *v134; // rsp
  __int64 v135; // rdx
  __int64 v136; // rcx
  __int64 v137; // r8
  __int64 v138; // r9
  void *v139; // rsp
  __int64 v140; // rdx
  __int64 v141; // rcx
  __int64 v142; // r8
  __int64 v143; // r9
  void *v144; // rsp
  __int64 v145; // rdx
  __int64 v146; // rcx
  __int64 v147; // r8
  __int64 v148; // r9
  void *v149; // rsp
  __int64 v150; // rdx
  __int64 v151; // rcx
  __int64 v152; // r8
  __int64 v153; // r9
  void *v154; // rsp
  __int64 v155; // rdx
  __int64 v156; // rcx
  __int64 v157; // r8
  __int64 v158; // r9
  void *v159; // rsp
  __int64 v160; // rdx
  __int64 v161; // rcx
  __int64 v162; // r8
  __int64 v163; // r9
  void *v164; // rsp
  __int64 v165; // rdx
  __int64 v166; // rcx
  __int64 v167; // r9
  void *v168; // rsp
  __int64 v169; // rdx
  __int64 v170; // rcx
  __int64 v171; // r8
  __int64 v172; // r9
  void *v173; // rsp
  __int64 v174; // rdx
  __int64 v175; // rcx
  __int64 v176; // r9
  void *v177; // rsp
  __int64 v178; // rdx
  __int64 v179; // rcx
  __int64 v180; // r8
  __int64 v181; // r9
  void *v182; // rsp
  __int64 v183; // rdx
  __int64 v184; // rcx
  __int64 v185; // r8
  __int64 v186; // r9
  void *v187; // rsp
  __int64 v188; // rdx
  __int64 v189; // rcx
  __int64 v190; // r8
  __int64 v191; // r9
  void *v192; // rsp
  __int64 v193; // rdx
  __int64 v194; // rcx
  __int64 v195; // r9
  void *v196; // rsp
  __int64 v197; // rdx
  __int64 v198; // rcx
  __int64 v199; // r8
  __int64 v200; // r9
  void *v201; // rsp
  __int64 v202; // rdx
  __int64 v203; // rcx
  __int64 v204; // r9
  void *v205; // rsp
  __int64 v206; // rdx
  __int64 v207; // rcx
  __int64 v208; // r8
  __int64 v209; // r9
  void *v210; // rsp
  __int64 v211; // rdx
  __int64 v212; // rcx
  __int64 v213; // r8
  __int64 v214; // r9
  void *v215; // rsp
  __int64 v216; // rdx
  __int64 v217; // rcx
  __int64 v218; // r8
  __int64 v219; // r9
  void *v220; // rsp
  __int64 v221; // rdx
  __int64 v222; // rcx
  __int64 v223; // r8
  __int64 v224; // r9
  void *v225; // rsp
  __int64 v226; // rdx
  __int64 v227; // rcx
  __int64 v228; // r8
  __int64 v229; // r9
  void *v230; // rsp
  __int64 v231; // rdx
  __int64 v232; // rcx
  __int64 v233; // r9
  void *v234; // rsp
  __int64 v235; // rdx
  __int64 v236; // rcx
  __int64 v237; // r8
  __int64 v238; // r9
  void *v239; // rsp
  __int64 v240; // rdx
  __int64 v241; // rcx
  __int64 v242; // r9
  void *v243; // rsp
  __int64 v244; // rdx
  __int64 v245; // rcx
  __int64 v246; // r8
  __int64 v247; // r9
  void *v248; // rsp
  __int64 v249; // rdx
  __int64 v250; // rcx
  __int64 v251; // r8
  __int64 v252; // r9
  void *v253; // rsp
  __int64 v254; // rdx
  __int64 v255; // rcx
  __int64 v256; // r8
  __int64 v257; // r9
  void *v258; // rsp
  __int64 v259; // rdx
  __int64 v260; // rcx
  __int64 v261; // r9
  void *v262; // rsp
  __int64 v263; // rdx
  __int64 v264; // rcx
  __int64 v265; // r8
  __int64 v266; // r9
  void *v267; // rsp
  __int64 v268; // rdx
  __int64 v269; // rcx
  __int64 v270; // r8
  __int64 v271; // r9
  void *v272; // rsp
  __int64 v273; // rdx
  __int64 v274; // rcx
  __int64 v275; // r8
  __int64 v276; // r9
  void *v277; // rsp
  __int64 v278; // rdx
  __int64 v279; // rcx
  __int64 v280; // r8
  __int64 v281; // r9
  void *v282; // rsp
  __int64 v283; // rdx
  __int64 v284; // rcx
  __int64 v285; // r8
  __int64 v286; // r9
  void *v287; // rsp
  __int64 v288; // rdx
  __int64 v289; // rcx
  __int64 v290; // r9
  void *v291; // rsp
  __int64 v292; // rdx
  __int64 v293; // rcx
  __int64 v294; // r8
  __int64 v295; // r9
  void *v296; // rsp
  __int64 v297; // rdx
  __int64 v298; // rcx
  __int64 v299; // r9
  void *v300; // rsp
  __int64 v301; // rdx
  __int64 v302; // rcx
  __int64 v303; // r8
  __int64 v304; // r9
  void *v305; // rsp
  __int64 v306; // rdx
  __int64 v307; // rcx
  __int64 v308; // r8
  __int64 v309; // r9
  void *v310; // rsp
  __int64 v311; // rdx
  __int64 v312; // rcx
  __int64 v313; // r8
  __int64 v314; // r9
  void *v315; // rsp
  __int64 v316; // rdx
  __int64 v317; // rcx
  __int64 v318; // r8
  __int64 v319; // r9
  void *v320; // rsp
  __int64 v321; // rdx
  __int64 v322; // rcx
  __int64 v323; // r8
  __int64 v324; // r9
  void *v325; // rsp
  __int64 v326; // rdx
  __int64 v327; // rcx
  __int64 v328; // r8
  __int64 v329; // r9
  void *v330; // rsp
  __int64 v331; // rdx
  __int64 v332; // rcx
  __int64 v333; // r8
  __int64 v334; // r9
  void *v335; // rsp
  __int64 v336; // rdx
  __int64 v337; // rcx
  __int64 v338; // r8
  __int64 v339; // r9
  void *v340; // rsp
  __int64 v341; // rdx
  __int64 v342; // rcx
  __int64 v343; // r8
  __int64 v344; // r9
  void *v345; // rsp
  __int64 v346; // rdx
  __int64 v347; // rcx
  __int64 v348; // r8
  __int64 v349; // r9
  void *v350; // rsp
  __int64 v351; // rdx
  __int64 v352; // rcx
  __int64 v353; // r8
  __int64 v354; // r9
  void *v355; // rsp
  __int64 v356; // rdx
  __int64 v357; // rcx
  __int64 v358; // r8
  __int64 v359; // r9
  void *v360; // rsp
  __int64 v361; // rdx
  __int64 v362; // rcx
  __int64 v363; // r8
  __int64 v364; // r9
  void *v365; // rsp
  __int64 v366; // rdx
  __int64 v367; // rcx
  __int64 v368; // r8
  __int64 v369; // r9
  void *v370; // rsp
  _DWORD v372[21]; // [rsp+20h] [rbp-80h] BYREF
  unsigned __int16 v373[35]; // [rsp+76h] [rbp-2Ah] BYREF
  unsigned __int16 v374[29]; // [rsp+BCh] [rbp+1Ch] BYREF
  unsigned __int16 v375[12]; // [rsp+F6h] [rbp+56h] BYREF
  unsigned __int16 v376[9]; // [rsp+10Eh] [rbp+6Eh] BYREF
  unsigned __int16 v377[8]; // [rsp+120h] [rbp+80h] BYREF
  __int64 (__fastcall **v378)(); // [rsp+130h] [rbp+90h]
  _DWORD *v379; // [rsp+140h] [rbp+A0h]
  _DWORD *v380; // [rsp+148h] [rbp+A8h]
  _DWORD *v381; // [rsp+150h] [rbp+B0h]
  _DWORD *v382; // [rsp+158h] [rbp+B8h]
  _DWORD *v383; // [rsp+160h] [rbp+C0h]
  _DWORD *v384; // [rsp+168h] [rbp+C8h]
  _DWORD *v385; // [rsp+170h] [rbp+D0h]
  _DWORD *v386; // [rsp+178h] [rbp+D8h]
  _DWORD *v387; // [rsp+180h] [rbp+E0h]
  _DWORD *v388; // [rsp+188h] [rbp+E8h]
  _DWORD *v389; // [rsp+190h] [rbp+F0h]
  _DWORD *v390; // [rsp+198h] [rbp+F8h]
  _DWORD *v391; // [rsp+1A0h] [rbp+100h]
  _DWORD *v392; // [rsp+1A8h] [rbp+108h]
  _DWORD *v393; // [rsp+1B0h] [rbp+110h]
  _DWORD *v394; // [rsp+1B8h] [rbp+118h]
  _DWORD *v395; // [rsp+1C0h] [rbp+120h]
  _DWORD *v396; // [rsp+1C8h] [rbp+128h]
  _DWORD *v397; // [rsp+1D0h] [rbp+130h]
  _DWORD *v398; // [rsp+1D8h] [rbp+138h]
  _DWORD *v399; // [rsp+1E0h] [rbp+140h]
  _DWORD *v400; // [rsp+1E8h] [rbp+148h]
  _DWORD *v401; // [rsp+1F0h] [rbp+150h]
  _DWORD *v402; // [rsp+1F8h] [rbp+158h]
  _DWORD *v403; // [rsp+200h] [rbp+160h]
  _DWORD *v404; // [rsp+208h] [rbp+168h]
  _DWORD *v405; // [rsp+210h] [rbp+170h]
  _DWORD *v406; // [rsp+218h] [rbp+178h]
  _DWORD *v407; // [rsp+220h] [rbp+180h]
  _DWORD *v408; // [rsp+228h] [rbp+188h]
  _DWORD *v409; // [rsp+230h] [rbp+190h]
  _DWORD *v410; // [rsp+238h] [rbp+198h]
  _DWORD *v411; // [rsp+240h] [rbp+1A0h]
  _DWORD *v412; // [rsp+248h] [rbp+1A8h]
  _DWORD *v413; // [rsp+250h] [rbp+1B0h]
  _DWORD *v414; // [rsp+258h] [rbp+1B8h]
  _DWORD *v415; // [rsp+260h] [rbp+1C0h]
  _DWORD *v416; // [rsp+268h] [rbp+1C8h]
  _DWORD *v417; // [rsp+270h] [rbp+1D0h]
  _DWORD *v418; // [rsp+278h] [rbp+1D8h]
  _DWORD *v419; // [rsp+280h] [rbp+1E0h]
  _DWORD *v420; // [rsp+288h] [rbp+1E8h]
  _DWORD *v421; // [rsp+290h] [rbp+1F0h]
  _DWORD *v422; // [rsp+298h] [rbp+1F8h]
  _DWORD *v423; // [rsp+2A0h] [rbp+200h]
  _DWORD *v424; // [rsp+2A8h] [rbp+208h]
  _DWORD *v425; // [rsp+2B0h] [rbp+210h]
  _DWORD *v426; // [rsp+2B8h] [rbp+218h]
  _DWORD *v427; // [rsp+2C0h] [rbp+220h]
  _DWORD *v428; // [rsp+2C8h] [rbp+228h]
  _DWORD *v429; // [rsp+2D0h] [rbp+230h]
  _DWORD *v430; // [rsp+2D8h] [rbp+238h]
  _DWORD *v431; // [rsp+2E0h] [rbp+240h]
  _DWORD *v432; // [rsp+2E8h] [rbp+248h]
  _DWORD *v433; // [rsp+2F0h] [rbp+250h]
  _DWORD *v434; // [rsp+2F8h] [rbp+258h]
  _DWORD *v435; // [rsp+300h] [rbp+260h]
  _DWORD *v436; // [rsp+308h] [rbp+268h]
  _DWORD *v437; // [rsp+310h] [rbp+270h]
  _DWORD *v438; // [rsp+318h] [rbp+278h]
  _DWORD *v439; // [rsp+320h] [rbp+280h]
  _DWORD *v440; // [rsp+328h] [rbp+288h]
  _DWORD *v441; // [rsp+330h] [rbp+290h]
  _DWORD *v442; // [rsp+350h] [rbp+2B0h]
  _DWORD *v443; // [rsp+358h] [rbp+2B8h]
  _DWORD *v444; // [rsp+360h] [rbp+2C0h]
  _DWORD *v445; // [rsp+368h] [rbp+2C8h]
  _DWORD *v446; // [rsp+370h] [rbp+2D0h]
  _DWORD *v447; // [rsp+378h] [rbp+2D8h]
  __int64 v448; // [rsp+3A0h] [rbp+300h]
  __int64 v449; // [rsp+3A8h] [rbp+308h]
  int v450; // [rsp+3C4h] [rbp+324h]
  unsigned int n; // [rsp+404h] [rbp+364h]
  unsigned int m; // [rsp+408h] [rbp+368h]
  unsigned int k; // [rsp+40Ch] [rbp+36Ch]
  unsigned int j; // [rsp+410h] [rbp+370h]
  unsigned int i; // [rsp+414h] [rbp+374h]

  v448 = a4;
  v378 = off_140037BC0;
  sub_1400160B0(v377);
  for ( i = 0;
        i < 8;
        v377[v7] = (v377[v7] | ((i & 0xBF2D) * (i & 0x40D2 ^ 0x40D2) + (i & 0x40D2) * (i | 0x40D2)) & 0xFFFE)
                 ^ v377[v7]
                 & ((i & 0xBF2D) * (i & 0x40D2 ^ 0x40D2) + (i & 0x40D2) * (i | 0x40D2)) )
  {
    nullsub_1();
    nullsub_1();
    v7 = (int)i++;
  }
  sub_14000C520(a1, (_QWORD *)a2, a3, v377);
  sub_1400160C0(v376);
  for ( j = 0; j < 9; v376[v8] = (~(2 * (v376[v8] & (-2317 * j))) + (v376[v8] & (-2317 * j))) & (v376[v8] | (-2317 * j)) )
  {
    nullsub_1();
    nullsub_1();
    v8 = (int)j++;
  }
  sub_14000C520(a1, (_QWORD *)a2, a3, v376);
  sub_1400160E0(v374);
  for ( k = 0; k < 0xF; v374[v9] ^= -21230 * (_WORD)k )
    v9 = (int)k++;
  sub_14000C520(a1, (_QWORD *)a2, a3, v374);
  sub_140016100(v375);
  for ( m = 0;
        m < 0xC;
        v375[v10] = ~(v375[v10] & (25393 * m)) & (v375[v10] + (v375[v10] ^ (25393 * m)) - (~(25393 * m) & v375[v10])) )
  {
    v10 = (int)m++;
  }
  sub_14000C520(a1, (_QWORD *)a2, a3, v375);
  sub_140016120(v373);
  for ( n = 0; n < 0x13; v373[v11] ^= 6484 * (_WORD)n )
    v11 = (int)n++;
  sub_14000C520(a1, (_QWORD *)a2, a3, v373);
  v449 = a2;
  v450 = *(_BYTE *)(a2 + 72) & 1;
  v15 = alloca(sub_140001B30(v378[v450], v12, v13, v14));
  v18 = alloca(sub_140001B30(v16, off_140037A40, v17, v372));
  v23 = alloca(sub_140001B30(v20, v19, v21, v22));
  v28 = alloca(sub_140001B30(v25, v24, v26, v27));
  v33 = alloca(sub_140001B30(v30, v29, v31, v32));
  v38 = alloca(sub_140001B30(v35, v34, v36, v37));
  v43 = alloca(sub_140001B30(v40, v39, v41, v42));
  v442 = v372;
  v47 = alloca(sub_140001B30(v45, v44, v372, v46));
  v443 = v372;
  v52 = alloca(sub_140001B30(v49, v48, v50, v51));
  v418 = v372;
  v56 = alloca(sub_140001B30(v54, v53, v372, v55));
  v423 = v372;
  v61 = alloca(sub_140001B30(v58, v57, v59, v60));
  v425 = v372;
  v65 = alloca(sub_140001B30(v63, v62, v372, v64));
  v430 = v372;
  v70 = alloca(sub_140001B30(v67, v66, v68, v69));
  v429 = v372;
  v74 = alloca(sub_140001B30(v72, v71, v372, v73));
  v433 = v372;
  v79 = alloca(sub_140001B30(v76, v75, v77, v78));
  v424 = v372;
  v83 = alloca(sub_140001B30(v81, v80, v372, v82));
  v428 = v372;
  v88 = alloca(sub_140001B30(v85, v84, v86, v87));
  v431 = v372;
  v93 = alloca(sub_140001B30(v90, v89, v91, v92));
  v435 = v372;
  v98 = alloca(sub_140001B30(v95, v94, v96, v97));
  v434 = v372;
  v102 = alloca(sub_140001B30(v100, v99, v372, v101));
  v437 = v372;
  v107 = alloca(sub_140001B30(v104, v103, v105, v106));
  v432 = v372;
  v111 = alloca(sub_140001B30(v109, v108, v372, v110));
  v436 = v372;
  v116 = alloca(sub_140001B30(v113, v112, v114, v115));
  v422 = v372;
  v120 = alloca(sub_140001B30(v118, v117, v372, v119));
  v427 = v372;
  v125 = alloca(sub_140001B30(v122, v121, v123, v124));
  v406 = v372;
  v129 = alloca(sub_140001B30(v127, v126, v372, v128));
  v408 = v372;
  v134 = alloca(sub_140001B30(v131, v130, v132, v133));
  v409 = v372;
  v139 = alloca(sub_140001B30(v136, v135, v137, v138));
  v414 = v372;
  v144 = alloca(sub_140001B30(v141, v140, v142, v143));
  v149 = alloca(sub_140001B30(v146, v145, v147, v148));
  v385 = v372;
  v154 = alloca(sub_140001B30(v151, v150, v152, v153));
  v386 = v372;
  v159 = alloca(sub_140001B30(v156, v155, v157, v158));
  v387 = v372;
  v164 = alloca(sub_140001B30(v161, v160, v162, v163));
  v388 = v372;
  v168 = alloca(sub_140001B30(v166, v165, v372, v167));
  v389 = v372;
  v173 = alloca(sub_140001B30(v170, v169, v171, v172));
  v390 = v372;
  v177 = alloca(sub_140001B30(v175, v174, v372, v176));
  v391 = v372;
  v182 = alloca(sub_140001B30(v179, v178, v180, v181));
  v392 = v372;
  v187 = alloca(sub_140001B30(v184, v183, v185, v186));
  v393 = v372;
  v192 = alloca(sub_140001B30(v189, v188, v190, v191));
  v394 = v372;
  v196 = alloca(sub_140001B30(v194, v193, v372, v195));
  v395 = v372;
  v201 = alloca(sub_140001B30(v198, v197, v199, v200));
  v396 = v372;
  v205 = alloca(sub_140001B30(v203, v202, v372, v204));
  v397 = v372;
  v210 = alloca(sub_140001B30(v207, v206, v208, v209));
  v398 = v372;
  v215 = alloca(sub_140001B30(v212, v211, v213, v214));
  v399 = v372;
  v220 = alloca(sub_140001B30(v217, v216, v218, v219));
  v400 = v372;
  v225 = alloca(sub_140001B30(v222, v221, v223, v224));
  v403 = v372;
  v230 = alloca(sub_140001B30(v227, v226, v228, v229));
  v402 = v372;
  v234 = alloca(sub_140001B30(v232, v231, v372, v233));
  v405 = v372;
  v239 = alloca(sub_140001B30(v236, v235, v237, v238));
  v401 = v372;
  v243 = alloca(sub_140001B30(v241, v240, v372, v242));
  v404 = v372;
  v248 = alloca(sub_140001B30(v245, v244, v246, v247));
  v407 = v372;
  v253 = alloca(sub_140001B30(v250, v249, v251, v252));
  v410 = v372;
  v258 = alloca(sub_140001B30(v255, v254, v256, v257));
  v411 = v372;
  v262 = alloca(sub_140001B30(v260, v259, v372, v261));
  v413 = v372;
  v267 = alloca(sub_140001B30(v264, v263, v265, v266));
  v412 = v372;
  v272 = alloca(sub_140001B30(v269, v268, v270, v271));
  v415 = v372;
  v277 = alloca(sub_140001B30(v274, v273, v275, v276));
  v416 = v372;
  v282 = alloca(sub_140001B30(v279, v278, v280, v281));
  v419 = v372;
  v287 = alloca(sub_140001B30(v284, v283, v285, v286));
  v417 = v372;
  v291 = alloca(sub_140001B30(v289, v288, v372, v290));
  v420 = v372;
  v296 = alloca(sub_140001B30(v293, v292, v294, v295));
  v379 = v372;
  v300 = alloca(sub_140001B30(v298, v297, v372, v299));
  v380 = v372;
  v305 = alloca(sub_140001B30(v302, v301, v303, v304));
  v381 = v372;
  v310 = alloca(sub_140001B30(v307, v306, v308, v309));
  v383 = v372;
  v315 = alloca(sub_140001B30(v312, v311, v313, v314));
  v382 = v372;
  v320 = alloca(sub_140001B30(v317, v316, v318, v319));
  v384 = v372;
  v325 = alloca(sub_140001B30(v322, v321, v323, v324));
  v446 = v372;
  v330 = alloca(sub_140001B30(v327, v326, v328, v329));
  v447 = v372;
  v335 = alloca(sub_140001B30(v332, v331, v333, v334));
  v444 = v372;
  v340 = alloca(sub_140001B30(v337, v336, v338, v339));
  v445 = v372;
  v345 = alloca(sub_140001B30(v342, v341, v343, v344));
  v439 = v372;
  v350 = alloca(sub_140001B30(v347, v346, v348, v349));
  v441 = v372;
  v355 = alloca(sub_140001B30(v352, v351, v353, v354));
  v438 = v372;
  v360 = alloca(sub_140001B30(v357, v356, v358, v359));
  v440 = v372;
  v365 = alloca(sub_140001B30(v362, v361, v363, v364));
  v421 = v372;
  v370 = alloca(sub_140001B30(v367, v366, v368, v369));
  v426 = v372;
  v372[0] = 30;
  __asm { jmp     rcx }
}


// ---- sub_140015414 @ 0x140015414 ----
__int64 __fastcall sub_140015414()
{
  __int64 v0; // rbp
  __int64 v1; // r12
  unsigned __int64 v2; // rax
  __int64 v3; // r15
  __int64 v4; // rax
  __int64 v5; // rax
  int *v6; // rdx

  sub_140002F90(v0 - 112, 0);
  v2 = saturated_mul(2u, sub_140016170(*(_QWORD *)(v1 + 8)) + 10);
  v3 = sub_14002E070(v2);
  sub_140016190(v0 + 784);
  for ( *(_DWORD *)(v0 + 856) = 0;
        *(_DWORD *)(v0 + 856) < 0xAu;
        *(_WORD *)(v0 + 2 * v4 + 784) ^= -31340 * (unsigned __int16)*(_DWORD *)(v0 + 856) )
  {
    nullsub_1();
    nullsub_1();
    v4 = (int)(*(_DWORD *)(v0 + 856))++;
  }
  nullsub_1();
  nullsub_1();
  v5 = sub_140004710(v3, *(__int16 **)(v1 + 8));
  sub_140004710(v5, (__int16 *)(v0 + 784));
  sub_140031DB0(v3, v0 + 816, 1179785, 3, 1, 96, 128);
  v6 = *(int **)(v0 + 512);
  *v6 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 472) + 8LL * *v6))();
}


// ---- sub_14001556C @ 0x14001556c ----
__int64 __fastcall sub_14001556C()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 400) + 8LL * **(int **)(v0 + 440)))();
}


// ---- sub_140015588 @ 0x140015588 ----
__int64 __fastcall sub_140015588()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 288);
  *v1 = 1;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 280) + 8LL * *v1))();
}


// ---- sub_1400155B5 @ 0x1400155b5 ----
__int64 __fastcall sub_1400155B5()
{
  __int64 v0; // rbp

  sub_140003A40(v0 - 112);
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 184) + 8LL * **(int **)(v0 + 200)))();
}


// ---- sub_1400155E0 @ 0x1400155e0 ----
__int64 __fastcall sub_1400155E0()
{
  _QWORD *v0; // rbx
  __int64 v1; // rbp
  unsigned __int64 v2; // rdi
  int *v3; // rcx

  v3 = *(int **)(v1 + 208);
  *v3 = v2 < *(_QWORD *)(v1 + 992);
  return (*(__int64 (**)(void))(*v0 + 8LL * *v3))();
}


// ---- sub_140015604 @ 0x140015604 ----
__int64 __fastcall sub_140015604()
{
  __int64 v0; // rbx
  __int64 v1; // rbp

  sub_140001C10(v0);
  return (*(__int64 (**)(void))(**(_QWORD **)(v1 + 264) + 8LL * **(int **)(v1 + 272)))();
}


// ---- sub_14001562E @ 0x14001562e ----
__int64 __fastcall sub_14001562E()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 312) + 8LL * **(int **)(v0 + 320)))();
}


// ---- sub_14001564F @ 0x14001564f ----
__int64 __fastcall sub_14001564F()
{
  int *v0; // r13
  _QWORD *v1; // r14

  return (*(__int64 (**)(void))(*v1 + 8LL * *v0))();
}


// ---- sub_14001565C @ 0x14001565c ----
None

// ---- sub_140015796 @ 0x140015796 ----
__int64 __fastcall sub_140015796()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 632) + 8LL * *(int *)*(unsigned int *)(v0 + 648)))();
}


// ---- sub_1400157B4 @ 0x1400157b4 ----
__int64 __fastcall sub_1400157B4()
{
  int v0; // eax
  __int64 v1; // rbp
  int *v2; // rcx

  v2 = *(int **)(v1 + 624);
  *v2 = v0 >= 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v1 + 600) + 8LL * *v2))();
}


// ---- sub_1400157D5 @ 0x1400157d5 ----
__int64 __fastcall sub_1400157D5()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 384) + 8LL * **(int **)(v0 + 408)))();
}


// ---- sub_1400157EF @ 0x1400157ef ----
__int64 __fastcall sub_1400157EF()
{
  __int64 v0; // rbp
  __int64 v1; // r15

  sub_140001C10(v1);
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 424) + 8LL * **(int **)(v0 + 448)))();
}


// ---- sub_140015819 @ 0x140015819 ----
__int64 __fastcall sub_140015819()
{
  __int64 v0; // rbp
  int *v1; // rdi
  _QWORD *v2; // r10

  *v1 = *(_QWORD *)(v0 + 768) == 0;
  return (*(__int64 (**)(void))(*v2 + 8LL * *v1))();
}


// ---- sub_140015834 @ 0x140015834 ----
__int64 __fastcall sub_140015834()
{
  __int64 v0; // rbp
  __int64 v1; // r15
  int v2; // eax
  int *v3; // rcx

  v1 = sub_14002E070((unsigned int)(*(_DWORD *)(v0 + 840) + 1));
  v2 = sub_140032540(*(_QWORD *)(v0 + 816), v1, *(unsigned int *)(v0 + 840), 0);
  v3 = *(int **)(v0 + 544);
  *v3 = v2 >= 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 504) + 8LL * *v3))();
}


// ---- sub_14001588E @ 0x14001588e ----
// positive sp value has been detected, the output may be wrong!
char __fastcall sub_14001588E()
{
  char v0; // si

  return v0 & 1;
}


// ---- sub_1400158A9 @ 0x1400158a9 ----
__int64 __fastcall sub_1400158A9()
{
  int *v0; // rbx
  _QWORD *v1; // rdi

  nullsub_1();
  *v0 = 0;
  return (*(__int64 (**)(void))(*v1 + 8LL * *v0))();
}


// ---- sub_1400158C8 @ 0x1400158c8 ----
__int64 __fastcall sub_1400158C8()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 216) + 8LL * **(int **)(v0 + 224)))();
}


// ---- sub_1400158E2 @ 0x1400158e2 ----
__int64 __fastcall sub_1400158E2()
{
  __int64 v0; // rbp
  int v1; // eax
  int *v2; // rcx

  v1 = sub_140032460(*(_QWORD *)(v0 + 816), v0 + 840, 0);
  v2 = *(int **)(v0 + 616);
  *v2 = v1 >= 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 584) + 8LL * *v2))();
}


// ---- sub_140015921 @ 0x140015921 ----
__int64 __fastcall sub_140015921(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v4; // rbp
  __int64 v5; // rdi
  int *v6; // r11
  __int64 v7; // r12
  __int64 v8; // r13
  __int64 v9; // r14
  __int64 v10; // r15
  int *v11; // r14
  __int64 v13; // rax

  *(_QWORD *)(v4 + 680) = v8;
  *(_QWORD *)(v4 + 672) = v9;
  *(_QWORD *)(v4 + 664) = v5;
  v11 = v6;
  sub_140016150(v4 + 58);
  for ( *(_DWORD *)(v4 + 864) = 0;
        *(_DWORD *)(v4 + 864) < 0xEu;
        *(_WORD *)(v4 + 2 * v13 + 58) ^= -12431 * (unsigned __int16)*(_DWORD *)(v4 + 864) )
  {
    v13 = (int)(*(_DWORD *)(v4 + 864))++;
  }
  sub_14000C520(v10, *(_QWORD **)(v4 + 776), v7, (unsigned __int16 *)(v4 + 58));
  return (*(__int64 (**)(void))(*a4 + 8LL * *v11))();
}


// ---- sub_1400159FE @ 0x1400159fe ----
__int64 __fastcall sub_1400159FE()
{
  __int64 v0; // rbp
  int *v1; // rcx

  v1 = *(int **)(v0 + 432);
  *v1 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 416) + 8LL * *v1))();
}


// ---- sub_140015A1E @ 0x140015a1e ----
__int64 __fastcall sub_140015A1E()
{
  __int64 v0; // rbp
  _QWORD *v1; // r14
  __int64 v2; // r15
  int *v3; // rcx

  nullsub_1();
  sub_140001C10(v2);
  v3 = *(int **)(v0 + 552);
  *v3 = 1;
  return (*(__int64 (**)(void))(*v1 + 8LL * *v3))();
}


// ---- sub_140015A4C @ 0x140015a4c ----
__int64 __fastcall sub_140015A4C()
{
  __int64 v0; // rbp
  __int64 v1; // r15
  __int64 v2; // rax
  __int64 v3; // r13
  int *v4; // rcx

  *(_BYTE *)(v1 + *(unsigned int *)(v0 + 840)) = 0;
  sub_140016210(v0 - 3);
  *(_DWORD *)(v0 + 852) = 0;
  while ( 1 )
  {
    nullsub_1();
    nullsub_1();
    if ( *(_DWORD *)(v0 + 852) >= 0x1Fu )
      break;
    v2 = (int)(*(_DWORD *)(v0 + 852))++;
    *(_BYTE *)(v0 + v2 - 3) ^= 93 * *(_BYTE *)(v0 + 852);
  }
  v3 = sub_1400161B0(v1, v0 - 3);
  v4 = *(int **)(v0 + 392);
  *v4 = v3 != 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 376) + 8LL * *v4))();
}


// ---- sub_140015AFB @ 0x140015afb ----
__int64 __fastcall sub_140015AFB()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 640) + 8LL * **(int **)(v0 + 656)))();
}


// ---- sub_140015B15 @ 0x140015b15 ----
__int64 __fastcall sub_140015B15()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 576) + 8LL * **(int **)(v0 + 608)))();
}


// ---- sub_140015B31 @ 0x140015b31 ----
__int64 __fastcall sub_140015B31()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 488);
  *v1 = 1;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 464) + 8LL * *v1))();
}


// ---- sub_140015B6C @ 0x140015b6c ----
__int64 __fastcall sub_140015B6C()
{
  __int64 v0; // rbp
  __int64 v1; // r15

  sub_140001C10(v1);
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 704) + 8LL * **(int **)(v0 + 712)))();
}


// ---- sub_140015B96 @ 0x140015b96 ----
__int64 __fastcall sub_140015B96()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 304);
  *v1 = 1;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 296) + 8LL * *v1))();
}


// ---- sub_140015BC3 @ 0x140015bc3 ----
__int64 __fastcall sub_140015BC3()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 696);
  *v1 = 1;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 688) + 8LL * *v1))();
}


// ---- sub_140015BF0 @ 0x140015bf0 ----
__int64 __fastcall sub_140015BF0()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 368);
  *v1 = 1;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 344) + 8LL * *v1))();
}


// ---- sub_140015C2B @ 0x140015c2b ----
__int64 __fastcall sub_140015C2B()
{
  __int64 v0; // rbp

  sub_14002E0B0(*(_QWORD *)(v0 + 744));
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 328) + 8LL * **(int **)(v0 + 352)))();
}


// ---- sub_140015C63 @ 0x140015c63 ----
__int64 __fastcall sub_140015C63(__int64 a1, __int64 a2)
{
  __int64 v2; // rax
  __int64 v3; // rbp
  int v4; // r12d
  __int64 v5; // r13
  __int64 v6; // r14
  __int64 v7; // rbx
  __int64 v8; // rax
  __int64 v9; // r13
  __int64 v10; // rcx
  _WORD *v11; // rbx
  int *v12; // rcx

  *(_QWORD *)(v3 + 736) = v5;
  v7 = *(_QWORD *)(v3 + 152) + v2 + 5;
  *(_QWORD *)(v3 + 760) = v7;
  LOBYTE(a2) = 92;
  v8 = sub_140016230(v7, a2);
  *(_QWORD *)(v3 + 752) = v8;
  v9 = v8 - v7 + 1;
  v10 = 2 * v9;
  if ( __CFADD__(v9, v9) )
    v10 = -1;
  v11 = (_WORD *)sub_14002E070(v10);
  sub_1400068A0(v11, v9, *(unsigned __int8 **)(v3 + 760), *(_QWORD *)(v3 + 752));
  sub_140016260(v3 - 112, *(_QWORD *)(v3 + 776), v4, (_DWORD)v11, v6);
  v12 = *(int **)(v3 + 256);
  *v12 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v3 + 248) + 8LL * *v12))();
}


// ---- sub_140015D36 @ 0x140015d36 ----
__int64 __fastcall sub_140015D36()
{
  __int64 v0; // rbx
  __int64 v1; // rbp
  __int64 v2; // rdi
  __int64 v3; // r13
  __int64 v4; // rax
  __int64 v5; // rax
  int *v6; // rdx

  *(_QWORD *)(v1 + 808) = v0;
  v4 = sub_140009590(*(_QWORD *)(*(_QWORD *)(v1 + 768) + 16 * v2), (__int64 *)(v1 + 152));
  *(_QWORD *)(v1 + 744) = v4;
  v5 = sub_1400161B0(v3, v4);
  v6 = *(int **)(v1 + 240);
  *v6 = v5 != 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v1 + 232) + 8LL * *v6))();
}


// ---- sub_140015D9F @ 0x140015d9f ----
__int64 __fastcall sub_140015D9F()
{
  __int64 v0; // rbp
  int *v1; // rdx

  v1 = *(int **)(v0 + 568);
  *v1 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 528) + 8LL * *v1))();
}


// ---- sub_140015DBF @ 0x140015dbf ----
__int64 __fastcall sub_140015DBF()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 592);
  *v1 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 560) + 8LL * *v1))();
}


// ---- sub_1400160B0 @ 0x1400160b0 ----
void __fastcall sub_1400160B0(_OWORD *a1)
{
  *a1 = xmmword_1400340EC;
}


// ---- sub_1400160C0 @ 0x1400160c0 ----
void __fastcall sub_1400160C0(__int64 a1)
{
  *(_OWORD *)a1 = xmmword_1400340FC;
  *(_WORD *)(a1 + 16) = -20853;
}


// ---- sub_1400160E0 @ 0x1400160e0 ----
void __fastcall sub_1400160E0(_OWORD *a1)
{
  *(_OWORD *)((char *)a1 + 14) = *(__int128 *)((char *)&xmmword_14003410E + 14);
  *a1 = xmmword_14003410E;
}


// ---- sub_140016100 @ 0x140016100 ----
unsigned __int64 __fastcall sub_140016100(__int64 a1)
{
  *(_OWORD *)a1 = xmmword_14003412C;
  *(_QWORD *)(a1 + 16) = 0xA64C4375DF857CCAuLL;
  return 0xA64C4375DF857CCAuLL;
}


// ---- sub_140016120 @ 0x140016120 ----
unsigned __int64 __fastcall sub_140016120(__int64 a1)
{
  *(_OWORD *)(a1 + 16) = xmmword_140034154;
  *(_OWORD *)a1 = xmmword_140034144;
  *(_QWORD *)(a1 + 30) = 0xE13CC78DAEE09529uLL;
  return 0xE13CC78DAEE09529uLL;
}


// ---- sub_140016150 @ 0x140016150 ----
void __fastcall sub_140016150(_OWORD *a1)
{
  *(_OWORD *)((char *)a1 + 12) = *(__int128 *)((char *)&xmmword_14003416A + 12);
  *a1 = xmmword_14003416A;
}


// ---- sub_140016170 @ 0x140016170 ----
__int64 __fastcall sub_140016170(__int64 a1)
{
  __int64 v1; // rax
  bool v2; // zf

  v1 = -2;
  do
  {
    v2 = *(_WORD *)(a1 + v1 + 2) == 0;
    v1 += 2;
  }
  while ( !v2 );
  return v1 >> 1;
}


// ---- sub_140016190 @ 0x140016190 ----
void __fastcall sub_140016190(__int64 a1)
{
  *(_OWORD *)a1 = xmmword_140034186;
  *(_DWORD *)(a1 + 16) = 935899719;
}


// ---- sub_1400161B0 @ 0x1400161b0 ----
_BYTE *__fastcall sub_1400161B0(_BYTE *a1, _BYTE *a2)
{
  char v2; // r9
  _BYTE *v3; // r8
  _BYTE *result; // rax

  v2 = *a2;
  if ( *a2 == 0 )
    return a1;
  v3 = a2;
  result = a1;
  while ( *a1 != 0 )
  {
    if ( *a1 == v2 )
    {
      ++a1;
      v2 = *++v3;
      if ( *v3 == 0 )
        return result;
    }
    else
    {
      a1 = ++result;
      v3 = a2;
      v2 = *a2;
      if ( *a2 == 0 )
        return result;
    }
  }
  return nullptr;
}


// ---- sub_140016210 @ 0x140016210 ----
void __fastcall sub_140016210(_OWORD *a1)
{
  *(_OWORD *)((char *)a1 + 15) = *(__int128 *)((char *)&xmmword_14003419A + 15);
  *a1 = xmmword_14003419A;
}


// ---- sub_140016230 @ 0x140016230 ----
_BYTE *__fastcall sub_140016230(_BYTE *a1, char a2)
{
  _BYTE *result; // rax
  char v3; // cl

  result = a1;
  v3 = *a1;
  if ( v3 == 0 )
    return nullptr;
  while ( v3 != a2 )
  {
    v3 = *++result;
    if ( v3 == 0 )
      return nullptr;
  }
  return result;
}


// ---- sub_140016260 @ 0x140016260 ----
__int64 __fastcall sub_140016260(__int64 a1, __int64 a2, _QWORD *a3, __int64 a4, __int64 a5)
{
  __int64 v8; // r14
  __int64 v9; // r13
  bool v10; // zf
  unsigned __int64 v11; // rcx
  __int64 v12; // rdi
  __int64 v13; // r13
  __int64 v14; // rbp
  __int64 v15; // rax
  __int64 v16; // rbp
  __int64 v17; // rcx
  __int64 v18; // r14
  __int64 v19; // rax
  __int64 v20; // rax
  __int64 v21; // rcx
  __int16 v22; // dx
  __int64 v23; // rax
  __int16 *v24; // rcx
  __int16 v25; // dx
  __int64 v26; // rcx
  signed int v27; // ecx
  __int16 *v28; // rsi
  __int16 *v29; // rcx
  _WORD *v30; // rdx
  __int16 v31; // r8
  __int64 v32; // rcx
  __int16 v33; // dx
  __int64 v34; // rdx
  __int16 v35; // r9
  char *v36; // r15
  __int64 v37; // rcx
  char *v38; // rax
  _BYTE *v39; // r12
  _BYTE *v40; // rax
  __int64 v41; // rbx
  _BYTE *v42; // rcx
  _BYTE *v43; // rax
  char v44; // dl
  __int64 v45; // rdx
  char v46; // al
  _BYTE *v47; // rax
  char *v48; // rcx
  char v49; // dl
  __int16 v50; // dx
  unsigned int i; // [rsp+3Ch] [rbp-BCh]
  _QWORD v53[4]; // [rsp+40h] [rbp-B8h] BYREF
  int v54; // [rsp+60h] [rbp-98h]
  __int64 v55; // [rsp+68h] [rbp-90h]
  _QWORD v56[2]; // [rsp+70h] [rbp-88h] BYREF
  __int128 v57; // [rsp+80h] [rbp-78h]
  _OWORD v58[6]; // [rsp+90h] [rbp-68h]

  v55 = a1;
  v8 = *(_QWORD *)(a5 + 8);
  v9 = -1;
  do
    v10 = *(_BYTE *)(v8 + v9++ + 1) == 0;
  while ( !v10 );
  v11 = ((v9 & 0xFFFFFFFFFFFFFFFCuLL) * (v9 & 3 ^ 3) + (v9 & 3) * (v9 | 3)) >> 2;
  if ( *(_BYTE *)(v8 + v9 - 1) == 61 )
  {
    if ( *(_BYTE *)(v8 + v9 - 2) == 61 )
    {
      if ( *(_BYTE *)(v8 + v9 - 3) == 61 )
        v11 -= 3LL;
      else
        v11 -= 2LL;
    }
    else
    {
      --v11;
    }
  }
  v12 = sub_14002E070(v11 + 1);
  v13 = sub_14002D560(v8, v9, v12);
  *(_BYTE *)(v12 + v13) = 0;
  v14 = -2;
  do
  {
    v10 = *(_WORD *)(a4 + v14 + 2) == 0;
    v14 += 2;
  }
  while ( !v10 );
  v15 = -2;
  do
  {
    v10 = *(_WORD *)(a3[1] + v15 + 2) == 0;
    v15 += 2;
  }
  while ( !v10 );
  v16 = v14 >> 1;
  v17 = -1;
  if ( (v15 >> 1) + v16 + 64 >= 0 )
    v17 = 2 * ((v15 >> 1) + v16) + 128;
  v18 = sub_14002E070(v17);
  v57 = xmmword_1400341CA;
  *(_OWORD *)v56 = xmmword_1400341BA;
  LOWORD(v58[0]) = 3792;
  LODWORD(v53[0]) = 0;
  do
  {
    v19 = SLODWORD(v53[0]);
    ++LODWORD(v53[0]);
    *((_WORD *)v56 + v19) ^= -3632 * LOWORD(v53[0]);
  }
  while ( LODWORD(v53[0]) < 0x11 );
  v20 = a3[1];
  v21 = 0;
  do
  {
    v22 = *(_WORD *)(v20 + v21);
    *(_WORD *)(v18 + v21) = v22;
    v21 += 2;
  }
  while ( v22 != 0 );
  v23 = v21 + v18;
  v24 = (__int16 *)v56;
  do
  {
    v25 = *v24++;
    *(_WORD *)(v23 - 2) = v25;
    v23 += 2;
  }
  while ( v25 != 0 );
  *(_OWORD *)((char *)v58 + 12) = *(__int128 *)((char *)&xmmword_1400341FC + 12);
  v58[0] = xmmword_1400341FC;
  v57 = xmmword_1400341EC;
  *(_OWORD *)v56 = xmmword_1400341DC;
  LODWORD(v53[0]) = 0;
  do
  {
    v26 = SLODWORD(v53[0]);
    ++LODWORD(v53[0]);
    *((_WORD *)v56 + v26) ^= 24082 * LOWORD(v53[0]);
  }
  while ( LODWORD(v53[0]) < 0x1E );
  qmemcpy(v53, &ymmword_140034218, sizeof(v53));
  v54 = -820631800;
  for ( i = 0; i < 0x12; *((_WORD *)v53 + v27) ^= (i & 0xA7F3 ^ 0xA7F3) * (i & 0x580C) + (i & 0xA7F3) * (i | 0xA7F3) )
    v27 = i++;
  v28 = (__int16 *)(v23 - 4);
  v29 = (__int16 *)v53;
  v30 = (_WORD *)(v23 - 4);
  do
  {
    v31 = *v29++;
    *v30++ = v31;
    v23 += 2;
  }
  while ( v31 != 0 );
  v32 = 0;
  do
  {
    v33 = *(_WORD *)(a4 + v32);
    *(_WORD *)(v23 + v32 - 6) = v33;
    v32 += 2;
  }
  while ( v33 != 0 );
  v34 = 0;
  do
  {
    v35 = *(_WORD *)((char *)v56 + v34);
    *(_WORD *)(v32 + v23 + v34 - 8) = v35;
    v34 += 2;
  }
  while ( v35 != 0 );
  v36 = *(char **)(a2 + 8);
  v37 = v13 + v16 + 48;
  v38 = v36;
  do
  {
    ++v37;
    v10 = *v38++ == 0;
  }
  while ( !v10 );
  v39 = (_BYTE *)*a3;
  v40 = (_BYTE *)*a3;
  do
  {
    ++v37;
    v10 = *v40++ == 0;
  }
  while ( !v10 );
  v41 = sub_14002E070(v37);
  v42 = (_BYTE *)v41;
  do
  {
    v43 = v42;
    v44 = *v36++;
    ++v42;
    *v43 = v44;
  }
  while ( v44 != 0 );
  *v43 = 47;
  v45 = -1;
  do
  {
    v46 = v39[v45 + 1];
    v42[++v45] = v46;
  }
  while ( v46 != 0 );
  v47 = &v42[v45];
  v42[v45] = 47;
  v48 = (char *)v12;
  do
  {
    v49 = *v48++;
    *++v47 = v49;
  }
  while ( v49 != 0 );
  while ( 1 )
  {
    v50 = *v28;
    switch ( *v28 != 0 )
    {
      case false:
        *v47 = 0;
        sub_14002E0B0(v12);
        sub_140016DD0(v55, v41, v18, 0, 0, 1, 0);
        return off_140037D20();
      case true:
        ++v28;
        *v47++ = v50;
        break;
    }
  }
}


// ---- sub_1400166E0 @ 0x1400166e0 ----
__int64 __fastcall sub_1400166E0(__int64 a1, __int64 *a2)
{
  unsigned int v2; // esi
  unsigned int v5; // r15d
  __int64 v6; // r12
  __int64 v7; // rax
  bool v8; // zf
  __int64 v9; // r14
  __int64 v10; // rax
  __int64 v11; // rcx
  __int64 v12; // rax
  __int64 v13; // rcx
  __int64 v14; // rdi
  __int16 v15; // dx
  unsigned __int16 *v16; // rbx
  unsigned __int16 *v17; // rax
  unsigned __int16 *v18; // r9
  unsigned __int64 v19; // r8
  __int64 v20; // r9
  unsigned __int16 *v21; // rdx
  unsigned __int16 v22; // r10
  __int64 v23; // rcx
  unsigned __int16 *v24; // r10
  unsigned __int16 *v25; // r9
  unsigned __int16 *v26; // r10
  unsigned int v27; // ebp
  unsigned __int16 *v28; // r15
  unsigned __int64 v29; // r12
  unsigned __int16 v30; // cx
  unsigned __int16 *v31; // rax
  _BYTE *v32; // rax
  _BYTE *v33; // r14
  unsigned __int16 *v34; // rcx
  _BYTE *v35; // rdx
  int v36; // r8d
  int v37; // ecx
  unsigned int v38; // edx
  unsigned int v39; // eax
  _QWORD v41[9]; // [rsp+30h] [rbp-48h] BYREF

  if ( (*(_BYTE *)(a1 + 56) & 0x10) != 0 )
  {
    v5 = *(_DWORD *)(a1 + 60);
    v6 = *(_QWORD *)(a2[1] + 24);
    v7 = -2;
    do
    {
      v8 = *(_WORD *)(v6 + v7 + 2) == 0;
      v7 += 2;
    }
    while ( !v8 );
    v9 = v5 >> 1;
    v10 = v9 + (v7 >> 1);
    v11 = -1;
    if ( v10 >= -2 )
      v11 = 2 * v10 + 4;
    v12 = sub_14002E070(v11);
    v13 = 0;
    v14 = v12;
    do
    {
      v15 = *(_WORD *)(v6 + v13);
      *(_WORD *)(v12 + v13) = v15;
      v13 += 2;
    }
    while ( v15 != 0 );
    v16 = (unsigned __int16 *)(a1 + 64);
    v17 = (unsigned __int16 *)(v13 + v12);
    *(_WORD *)(v14 + v13 - 2) = 92;
    if ( v5 < 2 )
    {
      v18 = v17;
      goto LABEL_16;
    }
    v19 = v9 - 1;
    if ( (v9 & 3) != 0 )
    {
      v20 = 0;
      v21 = v16;
      do
      {
        v22 = *v21;
        v21 += *v21 != 0;
        *v17++ = v22;
        ++v20;
      }
      while ( (v9 & 3) != v20 );
      v23 = v9 - v20;
      v18 = v17;
      if ( v19 < 3 )
      {
LABEL_16:
        *v18 = 0;
        if ( (unsigned __int8)sub_140016AA0(v14) != 0 )
        {
          v27 = *v16;
          if ( (_WORD)v27 != 0 )
          {
            v28 = &v16[v9];
            v29 = 0;
            v30 = *v16;
            v31 = v16;
            do
            {
              if ( v31 >= v28 )
                break;
              if ( v30 <= 0x7Fu )
              {
                ++v29;
              }
              else if ( v30 > 0x7FFu )
              {
                if ( v30 != 0xFFFF )
                  v29 += 3LL;
              }
              else
              {
                v29 += 2LL;
              }
              v30 = *++v31;
            }
            while ( *v31 != 0 );
            v32 = (_BYTE *)sub_14002E070(v29 + 1);
            v33 = v32;
            while ( 1 )
            {
              if ( v16 >= v28 || v29 == 0 )
                goto LABEL_50;
              v34 = v16 + 1;
              if ( (unsigned __int16)v27 > 0x7Fu )
              {
                if ( (unsigned __int16)v27 > 0x7FFu || v29 < 2 )
                {
                  v36 = v27 & 0xFC00;
                  if ( v36 == 55296 && v29 >= 4 )
                  {
                    v37 = v16[1];
                    v38 = v37 + ((unsigned __int16)v27 << 10) - 56613888;
                    *v32 = (v38 >> 18) | 0xF0;
                    v32[1] = (v38 >> 12) & 0x3F | 0x80;
                    v32[2] = (v38 >> 6) & 0x3F | 0x80;
                    v35 = v32 + 4;
                    v32[3] = v37 & 0x3F | 0x80;
                    v34 = v16 + 2;
                  }
                  else
                  {
                    if ( (unsigned __int16)v36 == 56320 )
                      goto LABEL_41;
                    if ( v29 < 3 )
                    {
                      v35 = v32;
                    }
                    else
                    {
                      *v32 = ((unsigned __int16)v27 >> 12) | 0xE0;
                      v32[1] = ((unsigned __int16)v27 >> 6) & 0x3F | 0x80;
                      v35 = v32 + 3;
                      v32[2] = v27 & 0x3F | 0x80;
                    }
                  }
                }
                else
                {
                  *v32 = (v27 >> 6) | 0xC0;
                  v35 = v32 + 2;
                  v32[1] = v27 & 0x3F | 0x80;
                }
              }
              else
              {
                v35 = v32 + 1;
                *v32 = v27;
              }
              v29 = &v32[v29] - v35;
              v32 = v35;
LABEL_41:
              v27 = *v34;
              v16 = v34;
              if ( (_WORD)v27 == 0 )
                goto LABEL_50;
            }
          }
          v32 = (_BYTE *)sub_14002E070(1);
          v33 = v32;
LABEL_50:
          *v32 = 0;
          v41[0] = v33;
          v41[1] = v14;
          sub_1400148C0(*a2, a2[1], (__int64)v41, a2[2]);
          v2 = v39;
          sub_140001C10(v33);
        }
        else
        {
          v2 = 0;
        }
        sub_140001C10(v14);
        return v2;
      }
    }
    else
    {
      v21 = v16;
      v23 = v5 >> 1;
      v18 = v17;
      if ( v19 < 3 )
        goto LABEL_16;
    }
    do
    {
      v24 = &v21[*v21 != 0];
      *v17 = *v21;
      v25 = &v24[*v24 != 0];
      v17[1] = *v24;
      v26 = &v25[*v25 != 0];
      v17[2] = *v25;
      v18 = v17 + 4;
      v21 = &v26[*v26 != 0];
      v17[3] = *v26;
      v17 += 4;
      v23 -= 4;
    }
    while ( v23 != 0 );
    goto LABEL_16;
  }
  return 0;
}


// ---- sub_140016AA0 @ 0x140016aa0 ----
__int64 __fastcall sub_140016AA0(__int64 a1)
{
  __int64 v2; // rax
  bool v3; // zf
  __int64 v4; // rcx
  __int64 v5; // rsi
  signed int v6; // eax
  __int64 v7; // rax
  __int16 v8; // cx
  __int64 v9; // rcx
  __int16 v10; // r8
  unsigned int i; // [rsp+2Ch] [rbp-3Ch]
  _QWORD v13[2]; // [rsp+30h] [rbp-38h] BYREF
  __int16 v14; // [rsp+40h] [rbp-28h]

  v2 = -2;
  do
  {
    v3 = *(_WORD *)(a1 + v2 + 2) == 0;
    v2 += 2;
  }
  while ( !v3 );
  v4 = -1;
  if ( v2 >= -19 )
    v4 = v2 + 18;
  v5 = sub_14002E070(v4);
  *(_OWORD *)v13 = xmmword_1400340DA;
  v14 = -8117;
  for ( i = 0; i < 9; *((_WORD *)v13 + v6) ^= (i & 0x8AB3 ^ 0x8AB3) * (i & 0x754C) + (i & 0x8AB3) * (i | 0x8AB3) )
    v6 = i++;
  v7 = 0;
  do
  {
    v8 = *(_WORD *)(a1 + v7);
    *(_WORD *)(v5 + v7) = v8;
    v7 += 2;
  }
  while ( v8 != 0 );
  v9 = 0;
  do
  {
    v10 = *(_WORD *)((char *)v13 + v9);
    *(_WORD *)(v7 + v5 + v9 - 2) = v10;
    v9 += 2;
  }
  while ( v10 != 0 );
  sub_140032240(v5, v13);
  return off_140037D40();
}


// ---- sub_140016BE0 @ 0x140016be0 ----
__int64 __fastcall sub_140016BE0(unsigned __int16 *a1, unsigned __int64 a2)
{
  unsigned __int16 v2; // r8
  __int64 result; // rax
  unsigned __int16 *v4; // rcx

  v2 = *a1;
  if ( *a1 == 0 )
    return 0;
  if ( a2 != 0 )
  {
    result = 0;
    do
    {
      if ( (unsigned __int64)a1 >= a2 )
        break;
      if ( v2 <= 0x7Fu )
      {
        ++result;
      }
      else if ( v2 > 0x7FFu )
      {
        if ( v2 != 0xFFFF )
          result += 3;
      }
      else
      {
        result += 2;
      }
      v2 = *++a1;
    }
    while ( *a1 != 0 );
  }
  else
  {
    v4 = a1 + 1;
    result = 0;
    do
    {
      if ( v2 < 0x80u )
      {
        ++result;
      }
      else if ( v2 >= 0x800u )
      {
        if ( v2 != 0xFFFF )
          result += 3;
      }
      else
      {
        result += 2;
      }
      v2 = *v4++;
    }
    while ( v2 != 0 );
  }
  return result;
}


// ---- sub_140016C90 @ 0x140016c90 ----
_DWORD *__fastcall sub_140016C90(__int64 a1, _DWORD *a2)
{
  *a2 = 118103385;
  return a2;
}


// ---- sub_140016CA0 @ 0x140016ca0 ----
__int64 __fastcall sub_140016CA0(__int64 a1, __int64 a2, int a3)
{
  unsigned int v5; // esi
  int v6; // r9d
  unsigned int v7; // r15d
  __int64 v8; // r14
  __int64 v9; // rdx
  __int64 v11; // [rsp+20h] [rbp-58h]
  __int64 v12; // [rsp+28h] [rbp-50h]
  unsigned int i; // [rsp+44h] [rbp-34h] BYREF
  __int64 v14; // [rsp+48h] [rbp-30h] BYREF

  if ( (int)sub_140031DB0(a3, (unsigned int)&v14, 1179785, 3, 1, 96, 128) < 0 )
  {
    return 0;
  }
  else
  {
    v5 = 0;
    if ( (int)sub_140032460(v14, &i, 0) >= 0 )
    {
      v7 = i;
      v8 = sub_14002E070(i);
      v5 = 0;
      if ( (int)sub_140032540(v14, v8, v7, 0) >= 0 )
        v5 = sub_140003370(a1, a2, v8, i);
      sub_140001C10(v8);
    }
    if ( qword_14003BB50 != 0 )
    {
      v9 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v9) != -1825720177 )
      {
        if ( qword_14003BB50 == ++v9 )
          goto LABEL_10;
      }
      sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v9 + 4), 1, v14, v6, v11, v12);
    }
    else
    {
LABEL_10:
      for ( i = 0; i == 0; ++i )
        ;
    }
  }
  return v5;
}


// ---- sub_140016DD0 @ 0x140016dd0 ----
__int64 __fastcall sub_140016DD0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5, int a6, char a7)
{
  _QWORD v8[4]; // [rsp+28h] [rbp-30h] BYREF
  int v9; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]
  char v11; // [rsp+50h] [rbp-8h]

  v8[0] = a1;
  v8[1] = a2;
  v8[2] = a3;
  v8[3] = a4;
  v9 = a5;
  v10 = a6;
  v11 = a7;
  return sub_140016E30(a3, 0, sub_1400175D0, v8);
}


// ---- sub_140016E30 @ 0x140016e30 ----
bool __fastcall sub_140016E30(int a1, __int64 a2, __int64 (__fastcall *a3)(_DWORD *, __int64), __int64 a4)
{
  int v4; // ebp
  bool v8; // bl
  _BYTE *v9; // rax
  unsigned __int64 i; // rbx
  bool v11; // r14
  _DWORD *v12; // rcx
  __int64 v13; // r14
  unsigned __int64 v14; // rax
  unsigned __int64 m; // r15
  bool v16; // r12
  bool v17; // r13
  _DWORD *v18; // rdx
  _DWORD *jj; // rax
  _DWORD *v20; // rcx
  unsigned int v21; // edx
  int v22; // eax
  int v23; // r9d
  unsigned __int64 kk; // rsi
  bool v25; // di
  bool v26; // bp
  __int64 v28; // [rsp+20h] [rbp-188h]
  __int64 v29; // [rsp+28h] [rbp-180h]
  int n; // [rsp+74h] [rbp-134h]
  int j; // [rsp+78h] [rbp-130h]
  int mm; // [rsp+7Ch] [rbp-12Ch]
  int k; // [rsp+80h] [rbp-128h]
  int ii; // [rsp+84h] [rbp-124h]
  _DWORD *v35; // [rsp+88h] [rbp-120h]
  int v36; // [rsp+94h] [rbp-114h] BYREF
  int v37; // [rsp+98h] [rbp-110h] BYREF
  int v38; // [rsp+9Ch] [rbp-10Ch] BYREF
  int v39; // [rsp+A0h] [rbp-108h] BYREF
  char v40; // [rsp+A5h] [rbp-103h] BYREF
  char v41; // [rsp+A6h] [rbp-102h] BYREF
  char v42; // [rsp+A7h] [rbp-101h] BYREF
  __int64 v43; // [rsp+A8h] [rbp-100h] BYREF
  __int64 v44; // [rsp+B0h] [rbp-F8h]
  _WORD *v45; // [rsp+B8h] [rbp-F0h]
  __int64 v46; // [rsp+C0h] [rbp-E8h] BYREF
  int v47; // [rsp+C8h] [rbp-E0h]
  int v48; // [rsp+CCh] [rbp-DCh]
  int v49; // [rsp+D0h] [rbp-D8h]
  int v50; // [rsp+D4h] [rbp-D4h]
  int v51; // [rsp+D8h] [rbp-D0h]
  int v52; // [rsp+DCh] [rbp-CCh]
  __int64 v53; // [rsp+E0h] [rbp-C8h]
  __int64 v54; // [rsp+E8h] [rbp-C0h]
  _BYTE *v55; // [rsp+F0h] [rbp-B8h]
  __int64 v56; // [rsp+F8h] [rbp-B0h]
  _BYTE *v57; // [rsp+100h] [rbp-A8h]
  __int64 v58; // [rsp+108h] [rbp-A0h]
  _WORD v59[4]; // [rsp+110h] [rbp-98h] BYREF
  __int64 v60; // [rsp+118h] [rbp-90h]
  __int64 v61; // [rsp+120h] [rbp-88h]
  __int64 v62; // [rsp+128h] [rbp-80h]
  __int64 v63; // [rsp+130h] [rbp-78h]
  __int64 v64; // [rsp+138h] [rbp-70h]
  __int64 v65; // [rsp+140h] [rbp-68h]
  __int64 v66; // [rsp+148h] [rbp-60h]
  _BYTE v67[88]; // [rsp+150h] [rbp-58h] BYREF

  v8 = false;
  if ( (int)sub_140031DB0(a1, (unsigned int)&v46, 1048577, 3, 1, 16417, 128) >= 0 )
  {
    v45 = nullptr;
    if ( a2 != 0 )
    {
      v59[0] = 2 * sub_140016170(a2);
      v59[1] = v59[0] + 2;
      v60 = a2;
      v45 = v59;
    }
    v58 = 2120;
    v44 = sub_14002E070(2120);
    v52 = 0;
    v51 = 1;
    v50 = 1;
    v9 = v67;
    v57 = v67;
    v66 = 0;
    v65 = 0;
    v64 = 0;
    for ( i = 0; ; ++i )
    {
      LOBYTE(v4) = i < qword_14003BB50;
      if ( i >= qword_14003BB50 )
        break;
      v11 = *(_DWORD *)(qword_14003BB58 + 8 * i) == 386101725;
      if ( *(_DWORD *)(qword_14003BB58 + 8 * i) == 386101725 )
        LODWORD(v9) = sub_14002F100(*(_DWORD *)(8 * i + qword_14003BB58 + 4), 11, v46, 0, 0, 0);
      if ( v11 )
        break;
    }
    if ( (v4 & 1) == 0 )
    {
      sub_140016C90((__int64)&v41, &v38);
      for ( j = 0; ; j = 1 )
      {
        nullsub_1();
        nullsub_1();
        if ( j != 0 )
          break;
        v38 ^= 0xF8F5E2A6;
      }
      LODWORD(v9) = v38;
    }
    v8 = false;
    if ( (int)v9 >= 0 )
    {
      v12 = (_DWORD *)v44;
      v35 = nullptr;
      v13 = 0;
      v8 = false;
      while ( 1 )
      {
        v14 = (unsigned __int64)(unsigned int)v12[15] >> 1;
        if ( (v12[14] & 0x400) == 0
          && ((unsigned int)v14 > 2 || *((_WORD *)v12 + 32) != 46 || (_DWORD)v14 != 1 && *((_WORD *)v12 + 33) != 46) )
        {
          v8 = (a3(v12, a4) & 1 | v8) != 0;
        }
        if ( v13 == 0 )
        {
          v13 = sub_14002E070(67840);
          if ( v13 == 0 )
            break;
          v35 = (_DWORD *)v13;
        }
        if ( v35 == (_DWORD *)v13 )
        {
          v49 = 0;
          v48 = 0;
          v47 = 1;
          sub_1400175B0(&v43);
          for ( k = 0; k == 0; k = 1 )
            v43 ^= 0x1C710A3uLL;
          v56 = v43;
          v55 = v67;
          v63 = 0;
          v62 = 0;
          v61 = 0;
          for ( m = 0; ; ++m )
          {
            v16 = m < qword_14003BB50;
            if ( m >= qword_14003BB50 )
              break;
            v17 = *(_DWORD *)(qword_14003BB58 + 8 * m) == 386101725;
            if ( *(_DWORD *)(qword_14003BB58 + 8 * m) == 386101725 )
            {
              v53 = v49;
              v54 = v46;
              v4 = sub_14002F100(*(_DWORD *)(8 * m + qword_14003BB58 + 4), 11, v46, 0, 0, 0);
            }
            if ( v17 )
              break;
          }
          if ( !v16 )
          {
            sub_140016C90((__int64)&v42, &v39);
            for ( n = 0; ; n = 1 )
            {
              nullsub_1();
              nullsub_1();
              if ( n != 0 )
                break;
              v39 ^= 0xF8F5E2A6;
            }
            v4 = v39;
          }
          sub_1400175C0(&v36);
          for ( ii = 0; ii == 0; ii = 1 )
            v36 = (-2 - ((~v36 | 0x1FFE8A56) + v36)) & (v36 | 0x1FFE8A56);
          if ( v4 == v36 )
          {
            v18 = v35;
            for ( jj = nullptr; ; jj = v20 )
            {
              v20 = v18;
              v21 = *v18;
              if ( v21 == 0 )
                break;
              v18 = &v20[(unsigned __int64)v21 >> 2];
            }
            if ( jj != nullptr )
              *jj = 0;
            v4 = 0;
          }
          if ( v4 >= 0 )
          {
            v22 = 0;
          }
          else
          {
            sub_14002E0B0(v13);
            v22 = 2;
          }
          if ( v22 != 0 )
            break;
        }
        v12 = v35;
        if ( *v35 != 0 )
          v35 = (_DWORD *)((char *)v35 + (unsigned int)*v35);
        else
          v35 = (_DWORD *)v13;
      }
    }
    sub_14002E0B0(v44);
    for ( kk = 0; ; ++kk )
    {
      v25 = kk < qword_14003BB50;
      if ( kk >= qword_14003BB50 )
        break;
      v26 = *(_DWORD *)(qword_14003BB58 + 8 * kk) == -1825720177;
      if ( *(_DWORD *)(qword_14003BB58 + 8 * kk) == -1825720177 )
        sub_14002F100(*(_DWORD *)(8 * kk + qword_14003BB58 + 4), 1, v46, v23, v28, v29);
      if ( v26 )
        break;
    }
    if ( !v25 )
    {
      sub_140016C90((__int64)&v40, &v37);
      for ( mm = 0; ; mm = 1 )
      {
        nullsub_1();
        nullsub_1();
        if ( mm != 0 )
          break;
        v37 ^= 0xF8F5E2A6;
      }
    }
  }
  return v8;
}


// ---- sub_1400175B0 @ 0x1400175b0 ----
void __fastcall sub_1400175B0(_QWORD *a1)
{
  *a1 = 29759907;
}


// ---- sub_1400175C0 @ 0x1400175c0 ----
void __fastcall sub_1400175C0(_DWORD *a1)
{
  *a1 = -1610708397;
}


// ---- sub_1400175D0 @ 0x1400175d0 ----
__int64 __fastcall sub_1400175D0(__int64 a1, __int64 a2)
{
  unsigned __int16 *v2; // rdi
  unsigned int v3; // ebp
  __int64 v4; // r15
  __int64 v5; // r13
  __int64 v6; // rax
  __int64 v7; // r12
  unsigned __int16 v8; // ax
  __int16 v9; // r9
  unsigned __int64 v10; // rbx
  __int16 v11; // ax
  __int16 v12; // r9
  __int16 v13; // ax
  __int16 v14; // r9
  __int16 v15; // r8
  __int16 v16; // r9
  int v17; // ecx
  __int64 v18; // rax
  int v19; // ecx
  int v20; // ecx
  unsigned int v21; // r15d
  __int64 v22; // r15
  __int64 v23; // rax
  bool v24; // zf
  __int64 v25; // rcx
  __int64 v26; // rax
  __int64 v27; // rcx
  __int64 v28; // r14
  __int16 v29; // dx
  unsigned __int16 *v30; // rax
  unsigned __int64 v31; // rdx
  __int64 v32; // r9
  unsigned __int16 *v33; // rcx
  unsigned __int16 v34; // r10
  unsigned __int16 *v36; // r14
  unsigned int v37; // r13d
  unsigned __int64 v38; // r12
  unsigned __int16 v39; // cx
  unsigned __int16 *v40; // rax
  __int64 v41; // rsi
  __int64 v42; // rcx
  __int64 v43; // rax
  __int64 v44; // rcx
  __int64 v45; // rbx
  char v46; // dl
  _BYTE *v47; // rax
  unsigned __int16 *v48; // rdx
  unsigned __int16 *v49; // rcx
  _BYTE *v50; // r8
  int v51; // r9d
  int v52; // ecx
  unsigned int v53; // r8d
  __int64 v54; // r12
  __int64 v55; // rax
  __int64 v56; // rcx
  __int64 v57; // rax
  __int64 v58; // rcx
  __int64 v59; // r14
  __int16 v60; // dx
  unsigned __int16 *v61; // rax
  unsigned __int16 *v62; // rdx
  __int64 v63; // rax
  unsigned __int64 v64; // rbx
  unsigned __int16 *v65; // rax
  __int16 v66; // dx
  __int64 *v67; // rax
  __int16 v68; // dx
  __int64 v69; // rax
  unsigned __int16 *v70; // rax
  int v71; // edx
  unsigned __int64 v72; // rcx
  __int64 v73; // r8
  unsigned __int16 v74; // r9
  unsigned __int16 *v75; // r8
  unsigned __int16 *v76; // r9
  unsigned __int16 *v77; // r8
  char v78; // al
  int v79; // ecx
  int v80; // edx
  __int64 v81; // r9
  unsigned int v82; // eax
  unsigned __int16 *v83; // rdx
  unsigned __int16 *v84; // r9
  unsigned __int16 *v85; // r8
  unsigned __int16 *v86; // rsi
  unsigned __int16 *v87; // r11
  int v88; // r10d
  int v89; // r11d
  unsigned __int16 *v90; // rdx
  unsigned __int16 *v91; // r9
  __int64 *v92; // r8
  unsigned __int16 *v93; // rsi
  __int64 *v94; // r11
  int v95; // r10d
  int v96; // r11d
  __int64 *v97; // rax
  int v98; // edx
  __int64 v99; // rax
  unsigned __int16 *v100; // rax
  int v101; // edx
  unsigned __int16 *v102; // rdx
  unsigned __int16 *v103; // r9
  unsigned __int16 *v104; // r8
  unsigned __int16 *v105; // rsi
  unsigned __int16 *v106; // r11
  int v107; // r10d
  int v108; // r11d
  unsigned __int16 *v109; // rdx
  unsigned __int16 *v110; // r9
  __int64 *v111; // r8
  unsigned __int16 *v112; // rsi
  __int64 *v113; // r11
  int v114; // r10d
  int v115; // r11d
  __int64 *v116; // rax
  int v117; // edx
  __int64 Data1; // rax
  __int64 p_rclsid; // rax
  __int16 v120; // dx
  unsigned __int16 *v121; // rdx
  unsigned __int16 *v122; // r9
  unsigned __int16 *v123; // r8
  unsigned __int16 *v124; // rsi
  unsigned __int16 *v125; // r11
  int v126; // r10d
  int v127; // r11d
  unsigned __int16 *v128; // rdx
  unsigned __int16 *v129; // r9
  __int64 *v130; // r8
  unsigned __int16 *v131; // rsi
  __int64 *v132; // r11
  int v133; // r10d
  int v134; // r11d
  __int16 v135; // dx
  __int64 *v136; // rdx
  __int64 v137; // r9
  __int64 v138; // rdx
  __int64 v139; // rdx
  __int64 v140; // r10
  int v141; // r15d
  __int16 *v142; // rsi
  unsigned __int16 *v143; // rsi
  unsigned __int16 v144; // r8
  __int16 v145; // r8
  unsigned __int16 *v146; // rdx
  unsigned __int16 *v147; // r9
  __int64 v148; // r8
  unsigned __int16 *v149; // rsi
  __int64 v150; // r11
  int v151; // r10d
  int v152; // r11d
  unsigned __int16 *v153; // rdx
  unsigned __int16 *v154; // r9
  __int64 v155; // r8
  unsigned __int16 *v156; // rsi
  __int64 v157; // r11
  int v158; // r10d
  int v159; // r11d
  unsigned __int16 *v160; // r8
  unsigned __int16 *v161; // r9
  unsigned __int16 *v162; // r8
  unsigned __int16 *v163; // r9
  __int64 v164; // rax
  __int64 v165; // rcx
  __int64 v166; // r13
  __int64 v167; // rsi
  _BYTE *v168; // rbp
  __int64 v169; // rcx
  _BYTE *v170; // rax
  __int64 v171; // r12
  __int64 v172; // rax
  char v173; // cl
  unsigned int v174; // eax
  int v175; // ecx
  __int64 v176; // r8
  unsigned int v177; // eax
  unsigned __int16 *v178; // r14
  __int64 v179; // rbp
  unsigned __int16 *v180; // r14
  unsigned __int16 *v181; // r13
  unsigned __int16 *v182; // r15
  unsigned __int16 *v183; // r11
  unsigned __int16 *v184; // r9
  unsigned __int16 *v185; // r8
  int v186; // esi
  int v187; // r8d
  unsigned __int16 v188; // r8
  unsigned __int16 *v189; // r15
  unsigned __int16 *v190; // r8
  unsigned __int16 *v191; // r11
  unsigned __int16 *v192; // r13
  unsigned __int16 *v193; // r9
  int v194; // esi
  int v195; // r9d
  __int16 v196; // r8
  unsigned int v197; // eax
  unsigned __int64 v198; // r14
  __int64 *v199; // rsi
  __int64 v200; // r13
  __int64 v201; // rax
  __int64 v202; // rcx
  __int64 v203; // rax
  __int64 v204; // rcx
  __int64 v205; // r15
  __int16 v206; // dx
  unsigned __int16 *v207; // rax
  unsigned __int16 *v208; // r8
  __int64 *v209; // r13
  unsigned __int64 v210; // rdx
  __int64 v211; // r9
  unsigned __int16 *v212; // rcx
  unsigned __int16 v213; // r10
  unsigned __int16 *v214; // r9
  unsigned __int16 *v215; // r8
  unsigned __int16 *v216; // r9
  int v217; // ebp
  int v218; // eax
  int v219; // eax
  __int64 v220; // rdx
  __int64 v221; // r12
  __int64 v222; // r15
  _BYTE *v223; // rbp
  __int64 v224; // rcx
  _BYTE *v225; // rax
  __int64 v226; // r13
  __int64 v227; // rax
  char v228; // cl
  int v229; // r9d
  __int64 v230; // rdx
  LPVOID *ppv; // [rsp+20h] [rbp-538h]
  __int64 v233; // [rsp+28h] [rbp-530h]
  unsigned int v234; // [rsp+38h] [rbp-520h]
  unsigned int v235; // [rsp+38h] [rbp-520h]
  int v236; // [rsp+3Ch] [rbp-51Ch]
  IID riid; // [rsp+40h] [rbp-518h] BYREF
  __int64 v238; // [rsp+50h] [rbp-508h]
  __int64 v239; // [rsp+58h] [rbp-500h]
  LPVOID v240; // [rsp+60h] [rbp-4F8h] BYREF
  IID rclsid; // [rsp+68h] [rbp-4F0h] BYREF
  __int64 v242; // [rsp+78h] [rbp-4E0h] BYREF
  __int64 v243; // [rsp+80h] [rbp-4D8h] BYREF
  __int64 v244; // [rsp+88h] [rbp-4D0h]
  __int64 *v245; // [rsp+90h] [rbp-4C8h]
  __int64 v246; // [rsp+98h] [rbp-4C0h]
  int v247; // [rsp+A0h] [rbp-4B8h]
  unsigned int v248; // [rsp+A4h] [rbp-4B4h]
  char v249; // [rsp+A8h] [rbp-4B0h]
  _QWORD v250[2]; // [rsp+B0h] [rbp-4A8h] BYREF
  __int64 v251; // [rsp+C0h] [rbp-498h] BYREF
  __int64 v252; // [rsp+C8h] [rbp-490h]
  __int64 v253; // [rsp+D0h] [rbp-488h]
  __int64 v254; // [rsp+D8h] [rbp-480h]
  int v255; // [rsp+E0h] [rbp-478h]
  int v256; // [rsp+E4h] [rbp-474h]
  char v257; // [rsp+E8h] [rbp-470h]
  __int64 v258; // [rsp+310h] [rbp-248h] BYREF
  int v259; // [rsp+318h] [rbp-240h]

  v2 = (unsigned __int16 *)(a1 + 64);
  v3 = *(_DWORD *)(a1 + 60);
  v4 = v3 >> 1;
  if ( (*(_BYTE *)(a1 + 56) & 0x10) != 0 )
  {
    if ( *(int *)(a2 + 36) <= 0 )
      return 0;
    v234 = *(_DWORD *)(a1 + 60);
    v36 = &v2[v4];
    v37 = *v2;
    v38 = 0;
    if ( (_WORD)v37 != 0 )
    {
      v39 = *v2;
      v40 = v2;
      do
      {
        if ( v40 >= v36 )
          break;
        if ( v39 <= 0x7Fu )
        {
          ++v38;
        }
        else if ( v39 > 0x7FFu )
        {
          if ( v39 != 0xFFFF )
            v38 += 3LL;
        }
        else
        {
          v38 += 2LL;
        }
        v39 = *++v40;
      }
      while ( *v40 != 0 );
    }
    v41 = *(_QWORD *)(a2 + 8);
    v42 = 1;
    do
      v24 = *(_BYTE *)(v41 + v42++ - 1) == 0;
    while ( !v24 );
    v43 = sub_14002E070(v38 + v42);
    v44 = 0;
    v45 = v43;
    do
    {
      v46 = *(_BYTE *)(v41 + v44);
      *(_BYTE *)(v43 + v44++) = v46;
    }
    while ( v46 != 0 );
    v47 = (_BYTE *)(v44 + v43);
    *(_BYTE *)(v45 + v44 - 1) = 47;
    if ( (_WORD)v37 == 0 )
    {
LABEL_83:
      *v47 = 0;
      v54 = *(_QWORD *)(a2 + 16);
      v55 = -2;
      do
      {
        v24 = *(_WORD *)(v54 + v55 + 2) == 0;
        v55 += 2;
      }
      while ( !v24 );
      v56 = -1;
      if ( v4 + (v55 >> 1) + 2 >= 0 )
        v56 = 2 * (v4 + (v55 >> 1)) + 4;
      v57 = sub_14002E070(v56);
      v58 = 0;
      v59 = v57;
      do
      {
        v60 = *(_WORD *)(v54 + v58);
        *(_WORD *)(v57 + v58) = v60;
        v58 += 2;
      }
      while ( v60 != 0 );
      v61 = (unsigned __int16 *)(v58 + v57);
      *(_WORD *)(v59 + v58 - 2) = 92;
      if ( v234 >= 2 )
      {
        v72 = v4 - 1;
        if ( (v4 & 3) != 0 )
        {
          v73 = 0;
          do
          {
            v74 = *v2;
            v2 += *v2 != 0;
            *v61++ = v74;
            ++v73;
          }
          while ( (v4 & 3) != v73 );
          v4 -= v73;
        }
        v62 = v61;
        if ( v72 >= 3 )
        {
          do
          {
            v75 = &v2[*v2 != 0];
            *v61 = *v2;
            v76 = &v75[*v75 != 0];
            v61[1] = *v75;
            v77 = &v76[*v76 != 0];
            v61[2] = *v76;
            v62 = v61 + 4;
            v2 = &v77[*v77 != 0];
            v61[3] = *v77;
            v61 += 4;
            v4 -= 4;
          }
          while ( v4 != 0 );
        }
      }
      else
      {
        v62 = v61;
      }
      *v62 = 0;
      v78 = *(_BYTE *)(a2 + 40);
      v79 = *(_DWORD *)(a2 + 36) - 1;
      v80 = *(_DWORD *)(a2 + 32);
      v81 = *(_QWORD *)(a2 + 24);
      v251 = *(_QWORD *)a2;
      v252 = v45;
      v253 = v59;
      v254 = v81;
      v255 = v80;
      v256 = v79;
      v257 = v78;
      LOBYTE(v82) = sub_140016E30(v59, 0, (__int64 (__fastcall *)(_DWORD *, __int64))sub_1400175D0, (__int64)&v251);
      v21 = v82;
      sub_140001C10(v59);
      sub_140001C10(v45);
      return v21;
    }
    v48 = v2;
    while ( 1 )
    {
      if ( v48 >= v36 || v38 == 0 )
        goto LABEL_83;
      v49 = v48 + 1;
      if ( (unsigned __int16)v37 > 0x7Fu )
      {
        if ( (unsigned __int16)v37 > 0x7FFu || v38 < 2 )
        {
          v51 = v37 & 0xFC00;
          if ( v51 == 55296 && v38 >= 4 )
          {
            v52 = v48[1];
            v53 = v52 + ((unsigned __int16)v37 << 10) - 56613888;
            *v47 = (v53 >> 18) | 0xF0;
            v47[1] = (v53 >> 12) & 0x3F | 0x80;
            v47[2] = (v53 >> 6) & 0x3F | 0x80;
            v50 = v47 + 4;
            v47[3] = v52 & 0x3F | 0x80;
            v49 = v48 + 2;
          }
          else
          {
            if ( (unsigned __int16)v51 == 56320 )
              goto LABEL_77;
            if ( v38 < 3 )
            {
              v50 = v47;
            }
            else
            {
              *v47 = ((unsigned __int16)v37 >> 12) | 0xE0;
              v47[1] = ((unsigned __int16)v37 >> 6) & 0x3F | 0x80;
              v50 = v47 + 3;
              v47[2] = v37 & 0x3F | 0x80;
            }
          }
        }
        else
        {
          *v47 = (v37 >> 6) | 0xC0;
          v50 = v47 + 2;
          v47[1] = v37 & 0x3F | 0x80;
        }
      }
      else
      {
        v50 = v47 + 1;
        *v47 = v37;
      }
      v38 = &v47[v38] - v50;
      v47 = v50;
LABEL_77:
      v37 = *v49;
      v48 = v49;
      if ( (_WORD)v37 == 0 )
        goto LABEL_83;
    }
  }
  v5 = a2;
  if ( (*(_BYTE *)(a2 + 40) & (v3 >= 8)) == 1 )
  {
    v251 = 0x2AA7A077150A8A9DLL;
    LOWORD(v252) = -19073;
    LODWORD(v258) = 0;
    do
    {
      v6 = (int)v258;
      LODWORD(v258) = v258 + 1;
      *((_WORD *)&v251 + v6) ^= -30029 * (_WORD)v258;
    }
    while ( (unsigned int)v258 < 5 );
    v7 = (unsigned int)v4;
    v8 = v2[(unsigned int)v4 - 4] | 0x20;
    if ( (unsigned __int16)(v2[(unsigned int)v4 - 4] - 65) >= 0x1Au )
      v8 = v2[(unsigned int)v4 - 4];
    v9 = v251 | 0x20;
    if ( (unsigned __int16)(v251 - 65) >= 0x1Au )
      v9 = v251;
    if ( v8 == v9 )
    {
      v10 = (unsigned __int64)&v2[(unsigned int)v4];
      if ( v8 == 0 )
        goto LABEL_28;
      v11 = *(_WORD *)(v10 - 6) | 0x20;
      if ( (unsigned __int16)(*(_WORD *)(v10 - 6) - 65) >= 0x1Au )
        v11 = *(_WORD *)(v10 - 6);
      v12 = WORD1(v251) | 0x20;
      if ( (unsigned __int16)(WORD1(v251) - 65) >= 0x1Au )
        v12 = WORD1(v251);
      if ( v11 == v12 )
      {
        if ( v11 == 0 )
          goto LABEL_28;
        v13 = *(_WORD *)(v10 - 4) | 0x20;
        if ( (unsigned __int16)(*(_WORD *)(v10 - 4) - 65) >= 0x1Au )
          v13 = *(_WORD *)(v10 - 4);
        v14 = WORD2(v251) | 0x20;
        if ( (unsigned __int16)(WORD2(v251) - 65) >= 0x1Au )
          v14 = WORD2(v251);
        if ( v13 == v14 )
        {
          if ( v13 == 0 )
            goto LABEL_28;
          v15 = *(_WORD *)(v10 - 2) | 0x20;
          if ( (unsigned __int16)(*(_WORD *)(v10 - 2) - 65) >= 0x1Au )
            v15 = *(_WORD *)(v10 - 2);
          v16 = HIWORD(v251) | 0x20;
          if ( (unsigned __int16)(HIWORD(v251) - 65) >= 0x1Au )
            v16 = HIWORD(v251);
          if ( v15 == v16 )
          {
LABEL_28:
            LODWORD(v251) = 0;
            v17 = 895926793;
            do
            {
              LODWORD(v251) = v251 + 1;
              v17 ^= 895800840 * v251;
            }
            while ( (_DWORD)v251 == 0 );
            v18 = 0x46000000D39C4F79LL;
            LODWORD(v251) = 0;
            do
            {
              LODWORD(v251) = (v251 ^ 1) + 2 * (v251 & 1);
              v18 ^= ((int)v251 & 0xFFFFFFFF2C63B046uLL) * ((unsigned int)v251 & 0xD39C4FB9 ^ 0xD39C4FB9LL)
                   + ((unsigned int)v251 & 0xD39C4FB9) * ((int)v251 | 0xD39C4FB9LL);
            }
            while ( (_DWORD)v251 == 0 );
            *(_QWORD *)&rclsid.Data1 = v17;
            *(_QWORD *)rclsid.Data4 = v18;
            LODWORD(v251) = 0;
            v19 = 1909579155;
            do
            {
              LODWORD(v251) = v251 + 1;
              v19 ^= (v251 & 0x71D3C96A ^ 0x71D3C96A) * (v251 & 0x8E2C3695) + (v251 & 0x71D3C96A) * (v251 | 0x71D3C96A);
            }
            while ( (_DWORD)v251 == 0 );
            *(_QWORD *)&riid.Data1 = v19;
            *(_QWORD *)riid.Data4 = v18;
            LODWORD(v251) = 0;
            v20 = 269173264;
            do
            {
              LODWORD(v251) = v251 + 1;
              v20 ^= (v251 & 0x100B431B ^ 0x100B431B) * (v251 & 0xEFF4BCE4) + (v251 & 0x100B431B) * (v251 | 0x100B431B);
            }
            while ( (_DWORD)v251 == 0 );
            v250[0] = v20;
            v250[1] = v18;
            v21 = 0;
            if ( CoCreateInstance(&rclsid, nullptr, 1u, &riid, &v240) >= 0 )
            {
              if ( (**(int (__fastcall ***)(LPVOID, _QWORD *, __int64 *))v240)(v240, v250, &v242) < 0 )
              {
                v21 = 0;
              }
              else
              {
                v22 = *(_QWORD *)(v5 + 16);
                v23 = -2;
                do
                {
                  v24 = *(_WORD *)(v22 + v23 + 2) == 0;
                  v23 += 2;
                }
                while ( !v24 );
                v25 = -1;
                if ( v7 + (v23 >> 1) + 2 >= 0 )
                  v25 = 2 * (v7 + (v23 >> 1)) + 4;
                v26 = sub_14002E070(v25);
                v27 = 0;
                v28 = v26;
                do
                {
                  v29 = *(_WORD *)(v22 + v27);
                  *(_WORD *)(v26 + v27) = v29;
                  v27 += 2;
                }
                while ( v29 != 0 );
                v30 = (unsigned __int16 *)(v27 + v26);
                *(_WORD *)(v28 + v27 - 2) = 92;
                v31 = v7 - 1;
                if ( (v7 & 3) != 0 )
                {
                  v32 = 0;
                  v33 = v2;
                  do
                  {
                    v34 = *v33;
                    v33 += *v33 != 0;
                    *v30++ = v34;
                    ++v32;
                  }
                  while ( (v7 & 3) != v32 );
                  v7 -= v32;
                }
                else
                {
                  v33 = v2;
                }
                v160 = v30;
                if ( v31 >= 3 )
                {
                  do
                  {
                    v161 = &v33[*v33 != 0];
                    *v30 = *v33;
                    v162 = &v161[*v161 != 0];
                    v30[1] = *v161;
                    v163 = &v162[*v162 != 0];
                    v30[2] = *v162;
                    v160 = v30 + 4;
                    v33 = &v163[*v163 != 0];
                    v30[3] = *v163;
                    v30 += 4;
                    v7 -= 4;
                  }
                  while ( v7 != 0 );
                }
                *v160 = 0;
                v21 = 0;
                if ( (*(int (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)v242 + 40LL))(v242, v28, 0) >= 0 )
                {
                  v21 = 0;
                  if ( (*(int (__fastcall **)(LPVOID, _QWORD, __int64))(*(_QWORD *)v240 + 152LL))(v240, 0, 1) >= 0 )
                  {
                    if ( (*(int (__fastcall **)(LPVOID, __int64 *, __int64, __int64 *, int))(*(_QWORD *)v240 + 24LL))(
                           v240,
                           &v258,
                           260,
                           &v251,
                           1) < 0 )
                    {
                      v21 = 0;
                    }
                    else
                    {
                      v164 = sub_140016BE0(v2, v10);
                      v165 = v5;
                      v166 = v164;
                      v167 = v165;
                      v168 = *(_BYTE **)(v165 + 8);
                      v169 = v164 + 1;
                      v170 = v168;
                      do
                      {
                        ++v169;
                        v24 = *v170++ == 0;
                      }
                      while ( !v24 );
                      v171 = sub_14002E070(v169);
                      v172 = 0;
                      do
                      {
                        v173 = v168[v172];
                        *(_BYTE *)(v171 + v172++) = v173;
                      }
                      while ( v173 != 0 );
                      *(_BYTE *)(v171 + v172 - 1) = 47;
                      sub_14000D200((_BYTE *)(v172 + v171), v166 + 1, v2, v10);
                      v174 = 2 * (*(_DWORD *)(v167 + 36) & 0xFFFFFFFE) - (*(_DWORD *)(v167 + 36) ^ 1);
                      v175 = *(_DWORD *)(v167 + 32);
                      v176 = *(_QWORD *)(v167 + 24);
                      v243 = *(_QWORD *)v167;
                      v244 = v171;
                      v245 = &v258;
                      v246 = v176;
                      v247 = v175;
                      v248 = v174;
                      v249 = 1;
                      LOBYTE(v177) = sub_140016E30(
                                       (int)&v258,
                                       0,
                                       (__int64 (__fastcall *)(_DWORD *, __int64))sub_1400175D0,
                                       (__int64)&v243);
                      v21 = v177;
                      sub_140001C10(v171);
                    }
                  }
                }
                (*(void (__fastcall **)(__int64))(*(_QWORD *)v242 + 16LL))(v242);
                sub_140001C10(v28);
              }
              (*(void (__fastcall **)(LPVOID))(*(_QWORD *)v240 + 16LL))(v240);
            }
            return v21;
          }
        }
      }
    }
  }
  else
  {
    v7 = (unsigned int)v4;
  }
  v251 = 0x65284B993286197ELL;
  LODWORD(v252) = -1745322303;
  LODWORD(v258) = 0;
  do
  {
    v63 = (int)v258;
    LODWORD(v258) = v258 + 1;
    *((_WORD *)&v251 + v63) ^= 6484 * (_WORD)v258;
  }
  while ( (unsigned int)v258 < 6 );
  v64 = (unsigned __int64)&v2[v7];
  if ( (_WORD)v251 == 33 )
  {
    v65 = (unsigned __int16 *)&v251 + 1;
    if ( v3 >= 2 )
    {
      v83 = nullptr;
      v84 = (unsigned __int16 *)(a1 + 64);
      v85 = nullptr;
      do
      {
        v88 = *v65 | 0x20;
        if ( (unsigned int)*v65 - 65 >= 0x1A )
          v88 = *v65;
        v89 = *v84 | 0x20;
        if ( (unsigned int)*v84 - 65 >= 0x1A )
          v89 = *v84;
        if ( v88 == 63 || v88 == v89 )
        {
          v86 = v84 + 1;
          v87 = v85;
          v84 = v83;
        }
        else
        {
          v87 = v65;
          v86 = v84;
          if ( v88 != 42 )
          {
            if ( v85 == nullptr )
              return 0;
            v65 = v85;
            v87 = v85;
            v84 = v83 + 1;
            v86 = v83 + 1;
          }
        }
        v83 = v84;
        ++v65;
        v84 = v86;
        v85 = v87;
      }
      while ( (unsigned __int64)v86 < v64 );
    }
    do
      v66 = *v65++;
    while ( v66 == 42 );
    if ( v66 != 0 )
      return 0;
  }
  else
  {
    v67 = &v251;
    if ( v3 >= 2 )
    {
      v90 = nullptr;
      v91 = (unsigned __int16 *)(a1 + 64);
      v92 = nullptr;
      while ( 1 )
      {
        v95 = *(unsigned __int16 *)v67 | 0x20;
        if ( (unsigned int)*(unsigned __int16 *)v67 - 65 >= 0x1A )
          v95 = *(unsigned __int16 *)v67;
        v96 = *v91 | 0x20;
        if ( (unsigned int)*v91 - 65 >= 0x1A )
          v96 = *v91;
        if ( v95 == 63 || v95 == v96 )
        {
          v93 = v91 + 1;
          v94 = v92;
          v91 = v90;
        }
        else
        {
          v94 = v67;
          v93 = v91;
          if ( v95 != 42 )
          {
            if ( v92 == nullptr )
              goto LABEL_102;
            v67 = v92;
            v94 = v92;
            v91 = v90 + 1;
            v93 = v90 + 1;
          }
        }
        v90 = v91;
        v67 = (__int64 *)((char *)v67 + 2);
        v91 = v93;
        v92 = v94;
        if ( (unsigned __int64)v93 >= v64 )
          goto LABEL_100;
      }
    }
    do
    {
LABEL_100:
      v68 = *(_WORD *)v67;
      v67 = (__int64 *)((char *)v67 + 2);
    }
    while ( v68 == 42 );
    if ( v68 == 0 )
      return 0;
  }
LABEL_102:
  v258 = 0x3DA86E379ECCCF5BLL;
  v259 = -593097383;
  riid.Data1 = 0;
  do
  {
    v69 = (int)riid.Data1++;
    *((_WORD *)&v258 + v69) ^= -12431 * LOWORD(riid.Data1);
  }
  while ( riid.Data1 < 6 );
  if ( (_WORD)v258 == 33 )
  {
    v70 = (unsigned __int16 *)&v258 + 1;
    if ( v3 >= 2 )
    {
      v102 = nullptr;
      v103 = (unsigned __int16 *)(a1 + 64);
      v104 = nullptr;
      do
      {
        v107 = *v70 | 0x20;
        if ( (unsigned int)*v70 - 65 >= 0x1A )
          v107 = *v70;
        v108 = *v103 | 0x20;
        if ( (unsigned int)*v103 - 65 >= 0x1A )
          v108 = *v103;
        if ( v107 == 63 || v107 == v108 )
        {
          v105 = v103 + 1;
          v106 = v104;
          v103 = v102;
        }
        else
        {
          v106 = v70;
          v105 = v103;
          if ( v107 != 42 )
          {
            if ( v104 == nullptr )
              return 0;
            v70 = v104;
            v106 = v104;
            v103 = v102 + 1;
            v105 = v102 + 1;
          }
        }
        v102 = v103;
        ++v70;
        v103 = v105;
        v104 = v106;
      }
      while ( (unsigned __int64)v105 < v64 );
    }
    do
      v71 = *v70++;
    while ( v71 == 42 );
    if ( v71 != 0 )
      return 0;
  }
  else
  {
    v97 = &v258;
    if ( v3 >= 2 )
    {
      v109 = nullptr;
      v110 = (unsigned __int16 *)(a1 + 64);
      v111 = nullptr;
      while ( 1 )
      {
        v114 = *(unsigned __int16 *)v97 | 0x20;
        if ( (unsigned int)*(unsigned __int16 *)v97 - 65 >= 0x1A )
          v114 = *(unsigned __int16 *)v97;
        v115 = *v110 | 0x20;
        if ( (unsigned int)*v110 - 65 >= 0x1A )
          v115 = *v110;
        if ( v114 == 63 || v114 == v115 )
        {
          v112 = v110 + 1;
          v113 = v111;
          v110 = v109;
        }
        else
        {
          v113 = v97;
          v112 = v110;
          if ( v114 != 42 )
          {
            if ( v111 == nullptr )
              goto LABEL_143;
            v97 = v111;
            v113 = v111;
            v110 = v109 + 1;
            v112 = v109 + 1;
          }
        }
        v109 = v110;
        v97 = (__int64 *)((char *)v97 + 2);
        v110 = v112;
        v111 = v113;
        if ( (unsigned __int64)v112 >= v64 )
          goto LABEL_141;
      }
    }
    do
    {
LABEL_141:
      v98 = *(unsigned __int16 *)v97;
      v97 = (__int64 *)((char *)v97 + 2);
    }
    while ( v98 == 42 );
    if ( v98 == 0 )
      return 0;
  }
LABEL_143:
  v243 = 0x162390D10B0685BELL;
  LODWORD(v244) = 561552269;
  riid.Data1 = 0;
  do
  {
    v99 = (int)riid.Data1++;
    *((_WORD *)&v243 + v99) ^= -31340 * LOWORD(riid.Data1);
  }
  while ( riid.Data1 < 6 );
  if ( (_WORD)v243 == 33 )
  {
    v100 = (unsigned __int16 *)&v243 + 1;
    if ( v3 >= 2 )
    {
      v121 = nullptr;
      v122 = (unsigned __int16 *)(a1 + 64);
      v123 = nullptr;
      do
      {
        v126 = *v100 | 0x20;
        if ( (unsigned int)*v100 - 65 >= 0x1A )
          v126 = *v100;
        v127 = *v122 | 0x20;
        if ( (unsigned int)*v122 - 65 >= 0x1A )
          v127 = *v122;
        if ( v126 == 63 || v126 == v127 )
        {
          v124 = v122 + 1;
          v125 = v123;
          v122 = v121;
        }
        else
        {
          v125 = v100;
          v124 = v122;
          if ( v126 != 42 )
          {
            if ( v123 == nullptr )
              return 0;
            v100 = v123;
            v125 = v123;
            v122 = v121 + 1;
            v124 = v121 + 1;
          }
        }
        v121 = v122;
        ++v100;
        v122 = v124;
        v123 = v125;
      }
      while ( (unsigned __int64)v124 < v64 );
    }
    do
      v101 = *v100++;
    while ( v101 == 42 );
    if ( v101 != 0 )
      return 0;
  }
  else
  {
    v116 = &v243;
    if ( v3 >= 2 )
    {
      v128 = nullptr;
      v129 = (unsigned __int16 *)(a1 + 64);
      v130 = nullptr;
      while ( 1 )
      {
        v133 = *(unsigned __int16 *)v116 | 0x20;
        if ( (unsigned int)*(unsigned __int16 *)v116 - 65 >= 0x1A )
          v133 = *(unsigned __int16 *)v116;
        v134 = *v129 | 0x20;
        if ( (unsigned int)*v129 - 65 >= 0x1A )
          v134 = *v129;
        if ( v133 == 63 || v133 == v134 )
        {
          v131 = v129 + 1;
          v132 = v130;
          v129 = v128;
        }
        else
        {
          v132 = v116;
          v131 = v129;
          if ( v133 != 42 )
          {
            if ( v130 == nullptr )
              goto LABEL_177;
            v116 = v130;
            v132 = v130;
            v129 = v128 + 1;
            v131 = v128 + 1;
          }
        }
        v128 = v129;
        v116 = (__int64 *)((char *)v116 + 2);
        v129 = v131;
        v130 = v132;
        if ( (unsigned __int64)v131 >= v64 )
          goto LABEL_175;
      }
    }
    do
    {
LABEL_175:
      v117 = *(unsigned __int16 *)v116;
      v116 = (__int64 *)((char *)v116 + 2);
    }
    while ( v117 == 42 );
    if ( v117 == 0 )
      return 0;
  }
LABEL_177:
  *(_QWORD *)&rclsid.Data1 = 0xEEB5B36A77483B99uLL;
  *(_DWORD *)rclsid.Data4 = 1714563596;
  riid.Data1 = 0;
  do
  {
    Data1 = (int)riid.Data1;
    riid.Data1 = (riid.Data1 ^ 1) + 2 * (riid.Data1 & 1);
    *((_WORD *)&rclsid.Data1 + Data1) ^= 15283 * LOWORD(riid.Data1);
  }
  while ( riid.Data1 < 6 );
  if ( LOWORD(rclsid.Data1) == 33 )
  {
    p_rclsid = (__int64)&rclsid.Data1 + 2;
    if ( v3 >= 2 )
    {
      v146 = nullptr;
      v147 = (unsigned __int16 *)(a1 + 64);
      v148 = 0;
      do
      {
        v151 = *(unsigned __int16 *)p_rclsid | 0x20;
        if ( (unsigned int)*(unsigned __int16 *)p_rclsid - 65 >= 0x1A )
          v151 = *(unsigned __int16 *)p_rclsid;
        v152 = *v147 | 0x20;
        if ( (unsigned int)*v147 - 65 >= 0x1A )
          v152 = *v147;
        if ( v151 == 63 || v151 == v152 )
        {
          v149 = v147 + 1;
          v150 = v148;
          v147 = v146;
        }
        else
        {
          v150 = p_rclsid;
          v149 = v147;
          if ( v151 != 42 )
          {
            if ( v148 == 0 )
              return 0;
            p_rclsid = v148;
            v150 = v148;
            v147 = v146 + 1;
            v149 = v146 + 1;
          }
        }
        v146 = v147;
        p_rclsid += 2;
        v147 = v149;
        v148 = v150;
      }
      while ( (unsigned __int64)v149 < v64 );
    }
    do
    {
      v120 = *(_WORD *)p_rclsid;
      p_rclsid += 2;
    }
    while ( v120 == 42 );
    if ( v120 != 0 )
      return 0;
  }
  else
  {
    p_rclsid = (__int64)&rclsid;
    if ( v3 >= 2 )
    {
      v153 = nullptr;
      v154 = (unsigned __int16 *)(a1 + 64);
      v155 = 0;
      while ( 1 )
      {
        v158 = *(unsigned __int16 *)p_rclsid | 0x20;
        if ( (unsigned int)*(unsigned __int16 *)p_rclsid - 65 >= 0x1A )
          v158 = *(unsigned __int16 *)p_rclsid;
        v159 = *v154 | 0x20;
        if ( (unsigned int)*v154 - 65 >= 0x1A )
          v159 = *v154;
        if ( v158 == 63 || v158 == v159 )
        {
          v156 = v154 + 1;
          v157 = v155;
          v154 = v153;
        }
        else
        {
          v157 = p_rclsid;
          v156 = v154;
          if ( v158 != 42 )
          {
            if ( v155 == 0 )
              goto LABEL_211;
            p_rclsid = v155;
            v157 = v155;
            v154 = v153 + 1;
            v156 = v153 + 1;
          }
        }
        v153 = v154;
        p_rclsid += 2;
        v154 = v156;
        v155 = v157;
        if ( (unsigned __int64)v156 >= v64 )
          goto LABEL_209;
      }
    }
    do
    {
LABEL_209:
      v135 = *(_WORD *)p_rclsid;
      p_rclsid += 2;
    }
    while ( v135 == 42 );
    if ( v135 == 0 )
      return 0;
  }
LABEL_211:
  v136 = *(__int64 **)(v5 + 24);
  v137 = *v136;
  v138 = v136[1] - *v136;
  if ( v138 != 0 )
  {
    v139 = v138 >> 3;
    v140 = 0;
    if ( v3 < 2 )
    {
      LOBYTE(v141) = 0;
      v239 = 0;
      while ( 1 )
      {
        v142 = *(__int16 **)(v137 + 8 * v140);
        if ( *v142 == 33 )
        {
          v143 = (unsigned __int16 *)(v142 + 1);
          do
            v144 = *v143++;
          while ( v144 == 42 );
          p_rclsid = v144;
          if ( v144 == 0 )
            return 0;
        }
        else
        {
          LOBYTE(p_rclsid) = 1;
          v239 = p_rclsid;
          if ( (v141 & 1) == 0 )
          {
            do
              v145 = *v142++;
            while ( v145 == 42 );
            if ( v145 == 0 )
              LOBYTE(v141) = 1;
          }
        }
        if ( ++v140 == v139 )
          goto LABEL_301;
      }
    }
    v141 = 0;
    v239 = 0;
    v238 = v137;
    v235 = v3;
    while ( 1 )
    {
      v178 = *(unsigned __int16 **)(v137 + 8 * v140);
      if ( *v178 == 33 )
      {
        v236 = v141;
        v179 = v5;
        v180 = v178 + 1;
        v181 = (unsigned __int16 *)(a1 + 64);
        v182 = nullptr;
        v183 = nullptr;
        do
        {
          v186 = *v180 | 0x20;
          if ( (unsigned int)*v180 - 65 >= 0x1A )
            v186 = *v180;
          p_rclsid = *v181;
          v187 = *v181 | 0x20;
          if ( (unsigned int)(p_rclsid - 65) >= 0x1A )
            v187 = *v181;
          if ( v186 == 63 || v186 == v187 )
          {
            v184 = v181 + 1;
            v185 = v183;
            v181 = v182;
          }
          else
          {
            v185 = v180;
            v184 = v181;
            if ( v186 != 42 )
            {
              if ( v183 == nullptr )
                goto LABEL_297;
              v180 = v183;
              v185 = v183;
              v181 = v182 + 1;
              v184 = v182 + 1;
            }
          }
          v182 = v181;
          ++v180;
          v181 = v184;
          v183 = v185;
        }
        while ( (unsigned __int64)v184 < v64 );
        do
          v188 = *v180++;
        while ( v188 == 42 );
        p_rclsid = v188;
        v141 = v236;
        if ( v188 == 0 )
          return 0;
      }
      else
      {
        LOBYTE(p_rclsid) = 1;
        v239 = p_rclsid;
        if ( (v141 & 1) != 0 )
          goto LABEL_263;
        v236 = v141;
        v179 = v5;
        v189 = (unsigned __int16 *)(a1 + 64);
        v190 = nullptr;
        v191 = nullptr;
        do
        {
          v194 = *v178 | 0x20;
          if ( (unsigned int)*v178 - 65 >= 0x1A )
            v194 = *v178;
          p_rclsid = (unsigned int)*v189 - 65;
          v195 = *v189 | 0x20;
          if ( (unsigned int)p_rclsid >= 0x1A )
            v195 = *v189;
          if ( v194 == 63 || v194 == v195 )
          {
            v192 = v189 + 1;
            v193 = v191;
            v189 = v190;
          }
          else
          {
            v193 = v178;
            v192 = v189;
            if ( v194 != 42 )
            {
              if ( v191 == nullptr )
              {
LABEL_297:
                v5 = v179;
                v3 = v235;
                v137 = v238;
                v141 = v236;
                goto LABEL_263;
              }
              v178 = v191;
              v193 = v191;
              v189 = v190 + 1;
              v192 = v190 + 1;
            }
          }
          v190 = v189;
          ++v178;
          v189 = v192;
          v191 = v193;
        }
        while ( (unsigned __int64)v192 < v64 );
        do
          v196 = *v178++;
        while ( v196 == 42 );
        v141 = (unsigned __int8)v236;
        p_rclsid = 1;
        if ( v196 == 0 )
          v141 = 1;
      }
      v5 = v179;
      v3 = v235;
      v137 = v238;
LABEL_263:
      if ( ++v140 == v139 )
      {
LABEL_301:
        if ( (v141 & 1 | ((v239 & 1) == 0)) != 0 )
          break;
        return 0;
      }
    }
  }
  v197 = *(_DWORD *)(a1 + 40);
  if ( v197 > *(_DWORD *)(v5 + 32) && *(_DWORD *)(v5 + 32) != 0 )
    return 0;
  v198 = v197;
  v199 = (__int64 *)v5;
  v200 = *(_QWORD *)(v5 + 16);
  v201 = -2;
  do
  {
    v24 = *(_WORD *)(v200 + v201 + 2) == 0;
    v201 += 2;
  }
  while ( !v24 );
  v202 = -1;
  if ( v7 + (v201 >> 1) + 2 >= 0 )
    v202 = 2 * (v7 + (v201 >> 1)) + 4;
  v203 = sub_14002E070(v202);
  v204 = 0;
  v205 = v203;
  do
  {
    v206 = *(_WORD *)(v200 + v204);
    *(_WORD *)(v203 + v204) = v206;
    v204 += 2;
  }
  while ( v206 != 0 );
  v207 = (unsigned __int16 *)(v204 + v203);
  *(_WORD *)(v205 + v204 - 2) = 92;
  if ( v3 >= 2 )
  {
    v210 = v7 - 1;
    v209 = v199;
    if ( (v7 & 3) != 0 )
    {
      v211 = 0;
      v212 = v2;
      do
      {
        v213 = *v212;
        v212 += *v212 != 0;
        *v207++ = v213;
        ++v211;
      }
      while ( (v7 & 3) != v211 );
      v7 -= v211;
    }
    else
    {
      v212 = v2;
    }
    v208 = v207;
    if ( v210 >= 3 )
    {
      do
      {
        v214 = &v212[*v212 != 0];
        *v207 = *v212;
        v215 = &v214[*v214 != 0];
        v207[1] = *v214;
        v216 = &v215[*v215 != 0];
        v207[2] = *v215;
        v208 = v207 + 4;
        v212 = &v216[*v216 != 0];
        v207[3] = *v216;
        v207 += 4;
        v7 -= 4;
      }
      while ( v7 != 0 );
    }
  }
  else
  {
    v208 = v207;
    v209 = v199;
  }
  *v208 = 0;
  v217 = sub_140031DB0(v205, (unsigned int)&v251, 1048577, 3, 1, 96, 128);
  LODWORD(v258) = 0;
  v218 = -417291309;
  do
  {
    LODWORD(v258) = v258 + 1;
    v218 = (v218 + (v218 ^ (656450448 * v258)) - (v218 & ~(656450448 * v258)))
         & ((v218 & (656450448 * v258)) + ~(2 * (v218 & (656450448 * v258))));
  }
  while ( (_DWORD)v258 == 0 );
  if ( v217 == v218 )
    goto LABEL_326;
  LODWORD(v258) = 0;
  v219 = -2057822953;
  do
  {
    LODWORD(v258) = v258 + 1;
    v219 ^= 1163402563 * v258;
  }
  while ( (_DWORD)v258 == 0 );
  if ( v217 == v219 )
  {
LABEL_326:
    LODWORD(v258) = 0;
    LODWORD(v220) = 1670350202;
    do
    {
      LODWORD(v258) = v258 + 1;
      v220 = (1670354674 * (_DWORD)v258) ^ (unsigned int)v220;
    }
    while ( (_DWORD)v258 == 0 );
    if ( (unsigned __int8)sub_14002C8C0(v205, v220) != 0 )
      v217 = sub_140031DB0(v205, (unsigned int)&v251, 1048577, 3, 1, 96, 128);
  }
  sub_140001C10(v205);
  if ( v217 < 0 )
    return 0;
  v221 = sub_14002E070(v198);
  v21 = 0;
  if ( (int)sub_140032540(v251, v221, (unsigned int)v198, 0) >= 0 )
  {
    v222 = sub_140016BE0(v2, v64);
    v223 = (_BYTE *)v209[1];
    v224 = v222 + 1;
    v225 = v223;
    do
    {
      ++v224;
      v24 = *v225++ == 0;
    }
    while ( !v24 );
    v226 = sub_14002E070(v224);
    v227 = 0;
    do
    {
      v228 = v223[v227];
      *(_BYTE *)(v226 + v227++) = v228;
    }
    while ( v228 != 0 );
    *(_BYTE *)(v226 + v227 - 1) = 47;
    sub_14000D200((_BYTE *)(v227 + v226), v222 + 1, v2, v64);
    v21 = sub_140003370(*v199, v226, v221, v198);
    sub_140001C10(v226);
  }
  sub_140001C10(v221);
  if ( qword_14003BB50 != 0 )
  {
    v230 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v230) != -1825720177 )
    {
      if ( qword_14003BB50 == ++v230 )
        goto LABEL_339;
    }
    sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v230 + 4), 1, v251, v229, (__int64)ppv, v233);
  }
  else
  {
LABEL_339:
    LODWORD(v258) = 0;
    do
      LODWORD(v258) = v258 + 1;
    while ( (_DWORD)v258 == 0 );
  }
  return v21;
}


// ---- sub_140018EA0 @ 0x140018ea0 ----
__int64 __fastcall sub_140018EA0(
        int a1,
        int a2,
        char *a3,
        unsigned __int8 *a4,
        unsigned __int8 *a5,
        unsigned __int8 *a6,
        __int64 a7,
        unsigned __int64 *a8)
{
  __int64 v8; // rsi
  char v10; // cl
  unsigned __int8 *v11; // rsi
  char *v12; // rax
  __int64 v13; // r14
  char v14; // cl
  char *v15; // rax
  __int64 v16; // r14
  __int64 (__fastcall *v17)(_QWORD, _QWORD, __int64 (__fastcall *)(), unsigned __int8 *, _DWORD, _QWORD); // rax
  __int64 v18; // rax
  unsigned __int64 v19; // rbx
  signed __int64 v20; // rdi
  unsigned __int64 v21; // r14
  int v22; // eax
  int v23; // eax
  int v24; // ecx
  __int64 v25; // r15
  __int64 v26; // rcx
  _WORD *v27; // r15
  unsigned int *v28; // r14
  unsigned int v29; // eax
  __m128 v30; // xmm5
  __int64 v31; // rax
  __m128i si128; // xmm3
  __m128 v33; // xmm4
  __m128 v34; // xmm6
  __m128i v35; // xmm6
  __m128i v36; // xmm5
  __m128i v37; // xmm7
  char v38; // cl
  char *v39; // rax
  __int64 v40; // r14
  __int64 v41; // r12
  unsigned __int64 v42; // r13
  unsigned __int64 v43; // rax
  __int64 v44; // rcx
  _WORD *v45; // r15
  int v46; // eax
  int v47; // ecx
  __int64 v48; // r13
  __int64 v49; // rcx
  int v50; // r13d
  int v51; // ebp
  _WORD *v52; // rcx
  __int64 v53; // rcx
  __int64 v54; // rbx
  __int64 v55; // rax
  __int64 v56; // r14
  __int64 v57; // rax
  __int16 v58; // cx
  _WORD *v59; // rcx
  __int64 v60; // rax
  __int64 v61; // rcx
  unsigned int (__fastcall *v62)(__int64, __int64, _QWORD, _QWORD); // rdi
  int v63; // r9d
  signed int v64; // eax
  __int64 v65; // rdx
  __int64 v66; // rax
  __int64 v67; // rdx
  unsigned int v68; // eax
  _WORD *v69; // r15
  __int64 v70; // r12
  __int64 v71; // r13
  __m128i v72; // xmm9
  char v73; // al
  unsigned int *v74; // r14
  unsigned int v75; // eax
  __m128 v76; // xmm1
  __int64 i; // rax
  __m128 v78; // xmm0
  __m128 v79; // xmm2
  __m128i v80; // xmm2
  __m128i v81; // xmm1
  __m128i v82; // xmm3
  unsigned int v83; // eax
  unsigned int v84; // eax
  unsigned int v85; // ecx
  unsigned int v86; // eax
  __int64 v87; // rax
  __int64 v88; // rax
  __int16 v89; // cx
  signed int v90; // eax
  __int64 v91; // rax
  __int16 v92; // cx
  __int64 v93; // rax
  __int64 v94; // rax
  __int16 v95; // cx
  __int64 v96; // rax
  __int64 v97; // rax
  __int16 v98; // cx
  __m256 *v99; // r14
  int v100; // ebp
  int v101; // r9d
  __int64 v102; // rdx
  __int64 v104; // rax
  bool v105; // zf
  __int64 v106; // rcx
  __int64 v107; // rax
  __int64 v108; // rax
  _WORD *v109; // rax
  __int16 v110; // cx
  __int64 v111; // rcx
  __int16 v112; // dx
  __int64 v113; // rdx
  __int16 v114; // r9
  __int64 v115; // rax
  __int64 v116; // rcx
  int v117; // eax
  __int64 v118; // rax
  __m256 *v119; // rcx
  _WORD *v120; // rax
  __int16 v121; // dx
  __int64 v122; // rcx
  __int16 v123; // dx
  __int64 v124; // rdx
  __int16 v125; // r9
  __int64 v126; // rax
  __int64 v127; // rdx
  __int64 v128; // r15
  __int64 v129; // rax
  __int64 v130; // rcx
  __int64 v131; // r14
  __int64 v132; // rax
  __int64 v133; // rcx
  __int64 v134; // rax
  bool v135; // sf
  __int64 v136; // rcx
  __int64 v137; // rax
  __int64 v138; // rax
  __int16 v139; // cx
  _WORD *v140; // r12
  __int16 *v141; // rax
  __int16 v142; // cx
  unsigned __int8 *v143; // r8
  _WORD *v144; // r12
  __int64 v145; // [rsp+20h] [rbp-178h]
  __int64 v146; // [rsp+20h] [rbp-178h]
  __int64 v147; // [rsp+28h] [rbp-170h]
  unsigned int ii; // [rsp+5Ch] [rbp-13Ch]
  unsigned int j; // [rsp+5Ch] [rbp-13Ch]
  unsigned int m; // [rsp+5Ch] [rbp-13Ch]
  unsigned int k; // [rsp+5Ch] [rbp-13Ch]
  unsigned int n; // [rsp+5Ch] [rbp-13Ch]
  _QWORD v153[5]; // [rsp+60h] [rbp-138h]
  __int64 v154; // [rsp+88h] [rbp-110h] BYREF
  __int64 v155; // [rsp+90h] [rbp-108h]
  __m256 v156[3]; // [rsp+A0h] [rbp-F8h] BYREF
  __int64 v157; // [rsp+100h] [rbp-98h]
  unsigned __int8 *v158; // [rsp+108h] [rbp-90h]

  if ( a1 == 1 )
  {
    if ( a2 == 3 )
    {
      v38 = *a6;
      if ( *a6 != 0 )
      {
        v39 = (char *)(a6 + 1);
        v40 = 0;
        do
        {
          while ( (v38 & 0xF0) == 0xE0 || v38 >= 0 || (v38 & 0xE0) == 0xC0 )
          {
            ++v40;
            v38 = *v39++;
            if ( v38 == 0 )
              goto LABEL_77;
          }
          if ( (v38 & 0xF8) == 0xF0 )
            v40 += 2;
          v38 = *v39++;
        }
        while ( v38 != 0 );
      }
      else
      {
        v40 = 0;
      }
LABEL_77:
      v60 = 2 * v40 + 2;
      v56 = v40 + 1;
      v61 = -1;
      if ( v56 >= 0 )
        v61 = v60;
      v54 = sub_14002E070(v61);
      v8 = 0;
      v59 = (_WORD *)v54;
    }
    else
    {
      if ( a2 != 2 )
        goto LABEL_26;
      v14 = *a6;
      if ( *a6 != 0 )
      {
        v15 = (char *)(a6 + 1);
        v16 = 0;
        do
        {
          while ( (v14 & 0xF0) == 0xE0 || v14 >= 0 || (v14 & 0xE0) == 0xC0 )
          {
            ++v16;
            v14 = *v15++;
            if ( v14 == 0 )
              goto LABEL_69;
          }
          if ( (v14 & 0xF8) == 0xF0 )
            v16 += 2;
          v14 = *v15++;
        }
        while ( v14 != 0 );
      }
      else
      {
        v16 = 0;
      }
LABEL_69:
      v53 = -1;
      if ( v16 + 25 >= 0 )
        v53 = 2 * v16 + 50;
      v54 = sub_14002E070(v53);
      qmemcpy(v156, byte_14003431A, 48);
      LOWORD(v156[1].m256_f32[4]) = -11255;
      LODWORD(v153[0]) = 0;
      do
      {
        v55 = SLODWORD(v153[0]);
        ++LODWORD(v153[0]);
        *((_WORD *)v156[0].m256_f32 + v55) ^= 12657 * LOWORD(v153[0]);
      }
      while ( LODWORD(v153[0]) < 0x19 );
      v56 = v16 + 1;
      v57 = 0;
      do
      {
        v58 = *(_WORD *)((char *)v156[0].m256_f32 + v57);
        *(_WORD *)(v54 + v57) = v58;
        v57 += 2;
      }
      while ( v58 != 0 );
      v59 = (_WORD *)(v54 + v57 - 2);
      v8 = 0;
    }
    sub_1400068A0(v59, v56, a6, 0);
    sub_14002E0B0(a6);
    v50 = 0x8000000;
    goto LABEL_81;
  }
  if ( a1 == 0 )
  {
    v158 = a4;
    if ( a3 != nullptr )
    {
      v10 = *a3;
      if ( *a3 != 0 )
      {
        v11 = (unsigned __int8 *)a3;
        v12 = a3 + 1;
        v13 = 0;
        do
        {
          while ( (v10 & 0xF0) == 0xE0 || v10 >= 0 || (v10 & 0xE0) == 0xC0 )
          {
            ++v13;
            v10 = *v12++;
            if ( v10 == 0 )
              goto LABEL_58;
          }
          if ( (v10 & 0xF8) == 0xF0 )
            v13 += 2;
          v10 = *v12++;
        }
        while ( v10 != 0 );
      }
      else
      {
        v11 = (unsigned __int8 *)a3;
        v13 = 0;
      }
LABEL_58:
      v44 = -1;
      if ( v13 + 1 >= 0 )
        v44 = 2 * v13 + 2;
      v45 = (_WORD *)sub_14002E070(v44);
      sub_1400068A0(v45, v13 + 1, v11, 0);
      v46 = sub_140031280(0, (_DWORD)v45, v13, 0, 0, (__int64)v156);
      LODWORD(v153[0]) = 0;
      v47 = -2057822880;
      do
      {
        ++LODWORD(v153[0]);
        v47 ^= (v153[0] & 0x45581D43 ^ 0x5581D43) * (v153[0] & 0xBAA7E2BC)
             + (v153[0] & 0x45581D43) * (LODWORD(v153[0]) | 0x45581D43);
      }
      while ( LODWORD(v153[0]) == 0 );
      if ( v46 != v47 )
        goto LABEL_67;
      v48 = *(_QWORD *)v156[0].m256_f32;
      v49 = -1;
      if ( *(__int64 *)v156[0].m256_f32 >= 0 )
        v49 = 2LL * *(_QWORD *)v156[0].m256_f32;
      v8 = sub_14002E070(v49);
      v146 = v48;
      v50 = 0;
      v51 = sub_140031280(0, (_DWORD)v45, v13, v8, v146, (__int64)v156);
      sub_140001C10(v45);
      if ( v51 < 0 )
      {
        v45 = (_WORD *)v8;
LABEL_67:
        v52 = v45;
LABEL_150:
        sub_140001C10(v52);
LABEL_151:
        LODWORD(v8) = 0;
        return (unsigned int)v8;
      }
    }
    else
    {
      *(_QWORD *)v156[0].m256_f32 = 0x78381A5BBC415E46LL;
      LOWORD(v156[0].m256_f32[2]) = -10662;
      LODWORD(v153[0]) = 0;
      do
      {
        v22 = LODWORD(v153[0])++;
        *((_WORD *)v156[0].m256_f32 + v22) = (*((_WORD *)v156[0].m256_f32 + v22)
                                            | ((v153[0] & 0xA1ED) * (v153[0] & 0x5E12 ^ 0x5E12)
                                             + (v153[0] & 0x5E12) * (LOWORD(v153[0]) | 0x5E12)))
                                           ^ *((_WORD *)v156[0].m256_f32 + v22)
                                           & ((v153[0] & 0xA1ED) * (v153[0] & 0x5E12 ^ 0x5E12)
                                            + (v153[0] & 0x5E12) * (LOWORD(v153[0]) | 0x5E12));
      }
      while ( LODWORD(v153[0]) < 5 );
      v23 = sub_1400310E0(0, (unsigned int)v156, 4, 0, 0, (__int64)&v154);
      LODWORD(v153[0]) = 0;
      v24 = -1043918720;
      do
      {
        ++LODWORD(v153[0]);
        v24 ^= (v153[0] & 0xFE38EF5C) * (v153[0] & 0x1C710A3 ^ 0x1C710A3)
             + (v153[0] & 0x1C710A3) * (LODWORD(v153[0]) | 0x1C710A3);
      }
      while ( LODWORD(v153[0]) == 0 );
      if ( v23 != v24 )
        goto LABEL_151;
      v25 = v154;
      v26 = -1;
      if ( v154 + 48 >= 0 )
        v26 = 2 * v154 + 96;
      v8 = sub_14002E070(v26);
      if ( (int)sub_1400310E0(0, (unsigned int)v156, 4, v8, v25, (__int64)&v154) < 0 )
        goto LABEL_149;
      v27 = (_WORD *)(v8 + 2 * v154);
      *v27 = 92;
      v28 = (unsigned int *)qword_14003BA50;
      v29 = *(_DWORD *)qword_14003BA50;
      if ( *(_DWORD *)qword_14003BA50 == 624 )
      {
        v30 = (__m128)_mm_shuffle_epi32(_mm_cvtsi32_si128(*(_DWORD *)(qword_14003BA50 + 4)), 0);
        v31 = -624;
        si128 = _mm_load_si128((const __m128i *)&xmmword_1400334E0);
        do
        {
          v33 = *(__m128 *)&v28[v31 + 626];
          v34 = (__m128)_mm_sub_epi32(
                          _mm_add_epi32(
                            (__m128i)_mm_or_ps(_mm_xor_ps(v33, (__m128)-1LL), (__m128)xmmword_140033AD0),
                            (__m128i)v33),
                          (__m128i)-1LL);
          v35 = _mm_xor_si128(
                  _mm_and_si128(_mm_srai_epi32(_mm_slli_epi32((__m128i)v34, 0x1Fu), 0x1Fu), si128),
                  _mm_srli_epi32(
                    (__m128i)_mm_or_ps(
                               _mm_and_ps(
                                 _mm_shuffle_ps(_mm_shuffle_ps(v30, v33, 3), v33, 152),
                                 (__m128)xmmword_1400334C0),
                               v34),
                    1u));
          v36 = _mm_loadu_si128((const __m128i *)&v28[v31 + 1022]);
          v37 = _mm_and_si128(v35, v36);
          *(__m128i *)&v28[v31 + 1249] = _mm_sub_epi32(_mm_add_epi32(v35, v36), _mm_add_epi32(v37, v37));
          v30 = v33;
          v31 += 4;
        }
        while ( v31 != 0 );
        v29 = 624;
      }
      else if ( v29 >= 0x4E0 )
      {
        sub_14001C670(qword_14003BA50);
        v29 = *v28;
      }
      *v28 = v29 + 1;
      v68 = v28[v29 + 1];
      v69 = v27 + 1;
      v70 = ((unsigned __int8)(v68 ^ (v68 >> 11))
           ^ (unsigned __int8)((v68
                              ^ (v68 >> 11)
                              ^ ((v68 ^ (v68 >> 11)) << 7)
                              & 0x2C0000
                              ^ ((((unsigned __int8)v68 ^ (unsigned __int8)(v68 >> 11)) & 8) << 15)) >> 18))
          & 0xF
          | 0x10u;
      v71 = 0;
      v72 = _mm_load_si128((const __m128i *)&xmmword_1400334E0);
      do
      {
        v74 = (unsigned int *)qword_14003BA50;
        v75 = *(_DWORD *)qword_14003BA50;
        if ( *(_DWORD *)qword_14003BA50 == 624 )
        {
          v76 = (__m128)_mm_shuffle_epi32(_mm_cvtsi32_si128(*(_DWORD *)(qword_14003BA50 + 4)), 0);
          for ( i = -624; i != 0; i += 4 )
          {
            v78 = *(__m128 *)&v74[i + 626];
            v79 = (__m128)_mm_sub_epi32(
                            _mm_add_epi32(
                              (__m128i)_mm_or_ps(_mm_xor_ps(v78, (__m128)-1LL), (__m128)xmmword_140033AD0),
                              (__m128i)v78),
                            (__m128i)-1LL);
            v80 = _mm_xor_si128(
                    _mm_and_si128(_mm_srai_epi32(_mm_slli_epi32((__m128i)v79, 0x1Fu), 0x1Fu), v72),
                    _mm_srli_epi32(
                      (__m128i)_mm_or_ps(
                                 _mm_and_ps(
                                   _mm_shuffle_ps(_mm_shuffle_ps(v76, v78, 3), v78, 152),
                                   (__m128)xmmword_1400334C0),
                                 v79),
                      1u));
            v81 = _mm_loadu_si128((const __m128i *)&v74[i + 1022]);
            v82 = _mm_and_si128(v80, v81);
            *(__m128i *)&v74[i + 1249] = _mm_sub_epi32(_mm_add_epi32(v80, v81), _mm_add_epi32(v82, v82));
            v76 = v78;
          }
          v75 = 624;
        }
        else if ( v75 >= 0x4E0 )
        {
          sub_14001C670(qword_14003BA50);
          v75 = *v74;
        }
        *v74 = v75 + 1;
        v83 = v74[v75 + 1];
        v84 = v83 ^ (v83 >> 11) ^ ((v83 ^ (v83 >> 11)) << 7) & 0x9D2C5680;
        v85 = v84 ^ (v84 << 15) & 0xEFC60000 ^ ((v84 ^ (v84 << 15) & 0xEFC60000) >> 18);
        v86 = v85 % 0x24;
        if ( v85 % 0x24 < 0xA )
          v73 = v86 | 0x30;
        else
          v73 = 32 * ((v85 & 1) == 0) + v86 + 55;
        *v69 = v73;
        ++v71;
        ++v69;
      }
      while ( v71 != v70 );
      v50 = 0;
      switch ( a2 )
      {
        case 0:
          v153[0] = 0x292D5E8E94C1CA7CLL;
          LOWORD(v153[1]) = -3174;
          for ( j = 0;
                j < 5;
                *((_WORD *)v153 + v87) = (*((_WORD *)v153 + v87) | (-13742 * j))
                                       & ((*((_WORD *)v153 + v87) & (-13742 * j))
                                        + ~(2 * (*((_WORD *)v153 + v87) & (-13742 * j)))) )
          {
            v87 = (int)j++;
          }
          v88 = 0;
          do
          {
            v89 = *(_WORD *)((char *)v153 + v88 * 2);
            v69[v88++] = v89;
          }
          while ( v89 != 0 );
          goto LABEL_138;
        case 1:
          v153[0] = 0xDA3CA3D06D4C36BAuLL;
          LOWORD(v153[1]) = 4324;
          for ( k = 0; k < 5; *((_WORD *)v153 + v93) ^= 13972 * (_WORD)k )
            v93 = (int)k++;
          v94 = 0;
          do
          {
            v95 = *(_WORD *)((char *)v153 + v94 * 2);
            v69[v94++] = v95;
          }
          while ( v95 != 0 );
          goto LABEL_138;
        case 2:
          v153[0] = 0xB2F5C660D912EC9FuLL;
          LOWORD(v153[1]) = -24715;
          for ( m = 0; m < 5; *((_WORD *)v153 + v90) ^= (m & 0x134E) * (m & 0xECB1 ^ 0xECB1)
                                                      + (m & 0xECB1) * (m | 0xECB1) )
            v90 = m++;
          v91 = 0;
          do
          {
            v92 = *(_WORD *)((char *)v153 + v91 * 2);
            v69[v91++] = v92;
          }
          while ( v92 != 0 );
          v50 = 0x8000000;
          break;
        case 4:
          v153[0] = 0x1AD8120008F805FLL;
          LOWORD(v153[1]) = -32203;
          for ( n = 0; n < 5; *((_WORD *)v153 + v96) ^= -32655 * (_WORD)n )
            v96 = (int)n++;
          v97 = 0;
          do
          {
            v98 = *(_WORD *)((char *)v153 + v97 * 2);
            v69[v97++] = v98;
          }
          while ( v98 != 0 );
LABEL_138:
          v50 = 0;
          break;
        default:
          break;
      }
    }
    v99 = v156;
    if ( (int)sub_140031DB0(v8, (unsigned int)v156, 1179926, 0, 5, 96, 128) < 0 )
    {
      sub_14002E0B0(a6);
    }
    else
    {
      v100 = sub_140032750(*(_QWORD *)v156[0].m256_f32, a6, a7, 0);
      if ( qword_14003BB50 != 0 )
      {
        v102 = 0;
        while ( *(_DWORD *)(qword_14003BB58 + 8 * v102) != -1825720177 )
        {
          if ( qword_14003BB50 == ++v102 )
            goto LABEL_144;
        }
        sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v102 + 4), 1, LODWORD(v156[0].m256_f32[0]), v101, v145, v147);
        sub_14002E0B0(a6);
        if ( v100 >= 0 )
          goto LABEL_154;
      }
      else
      {
LABEL_144:
        LODWORD(v153[0]) = 0;
        do
          ++LODWORD(v153[0]);
        while ( LODWORD(v153[0]) == 0 );
        sub_14002E0B0(a6);
        if ( v100 >= 0 )
        {
LABEL_154:
          switch ( a2 )
          {
            case 1:
              v126 = -2;
              do
              {
                v105 = *(_WORD *)(v8 + v126 + 2) == 0;
                v126 += 2;
              }
              while ( !v105 );
              if ( v158 != nullptr )
              {
                v127 = 0;
                do
                {
                  v128 = v127 + 1;
                  v105 = v158[v127++] == 0;
                }
                while ( !v105 );
              }
              else
              {
                v128 = 0;
              }
              v129 = v126 >> 1;
              if ( a5 != nullptr )
              {
                v130 = 0;
                do
                {
                  v131 = v130 + 1;
                  v105 = a5[v130++] == 0;
                }
                while ( !v105 );
              }
              else
              {
                v131 = 0;
              }
              v132 = v128 + v129;
              v133 = v131 + v132 + 16;
              v134 = 2 * (v131 + v132) + 32;
              v135 = v133 < 0;
              v136 = -1;
              if ( !v135 )
                v136 = v134;
              v54 = sub_14002E070(v136);
              *(_OWORD *)v156[0].m256_f32 = xmmword_1400342A8;
              *(_QWORD *)((char *)&v156[0].m256_f32[3] + 2) = 0xFEF05C02B97016B2uLL;
              LODWORD(v153[0]) = 0;
              do
              {
                v137 = SLODWORD(v153[0]);
                ++LODWORD(v153[0]);
                *((_WORD *)v156[0].m256_f32 + v137) ^= -23856 * LOWORD(v153[0]);
              }
              while ( LODWORD(v153[0]) < 0xB );
              v138 = 0;
              do
              {
                v139 = *(_WORD *)((char *)v156[0].m256_f32 + v138);
                *(_WORD *)(v54 + v138) = v139;
                v138 += 2;
              }
              while ( v139 != 0 );
              v140 = (_WORD *)(v138 + v54);
              v141 = (__int16 *)v8;
              do
              {
                v142 = *v141++;
                *(v140++ - 1) = v142;
              }
              while ( v142 != 0 );
              *(v140 - 2) = 34;
              sub_140001C10(v8);
              v143 = v158;
              if ( v158 != nullptr )
              {
                *(v140 - 1) = 44;
                v144 = &v140[sub_1400068A0(v140, v128, v143, 0)];
              }
              else
              {
                v144 = v140 - 1;
              }
              if ( a5 != nullptr )
              {
                *v144 = 44;
                v8 = 0;
                sub_1400068A0(v144 + 1, v131, a5, 0);
              }
              else
              {
                v8 = 0;
              }
              break;
            case 2:
              v115 = -2;
              do
              {
                v105 = *(_WORD *)(v8 + v115 + 2) == 0;
                v115 += 2;
              }
              while ( !v105 );
              v116 = -1;
              if ( v115 >= -65 )
                v116 = v115 + 64;
              v54 = sub_14002E070(v116);
              LODWORD(v154) = 505679664;
              v156[0].m256_f32[0] = 0.0;
              do
              {
                v117 = LODWORD(v156[0].m256_f32[0])++;
                *((_WORD *)&v154 + v117) = (*((_WORD *)&v154 + v117) | (3858 * LOWORD(v156[0].m256_f32[0])))
                                         & (-2
                                          - (*((_WORD *)&v154 + v117)
                                           + ((3858 * LOWORD(v156[0].m256_f32[0])) | ~*((_WORD *)&v154 + v117))));
              }
              while ( LODWORD(v156[0].m256_f32[0]) < 2 );
              qmemcpy(v156, byte_1400342BE, 58);
              LODWORD(v153[0]) = 0;
              do
              {
                v118 = SLODWORD(v153[0]);
                LODWORD(v153[0]) = (LODWORD(v153[0]) ^ 1) + 2 * (v153[0] & 1);
                *((_WORD *)v156[0].m256_f32 + v118) ^= (v153[0] & 0xA70C) * (v153[0] & 0x58F3 ^ 0x58F3)
                                                     + (v153[0] & 0x58F3) * (LOWORD(v153[0]) | 0x58F3);
              }
              while ( LODWORD(v153[0]) < 0x1D );
              v119 = v156;
              v120 = (_WORD *)v54;
              do
              {
                v121 = LOWORD(v119->m256_f32[0]);
                v119 = (__m256 *)((char *)v119 + 2);
                *v120++ = v121;
              }
              while ( v121 != 0 );
              v122 = 0;
              do
              {
                v123 = *(_WORD *)(v8 + v122 * 2);
                v120[v122++ - 1] = v123;
              }
              while ( v123 != 0 );
              v124 = 0;
              do
              {
                v125 = *(_WORD *)((char *)&v154 + v124 * 2);
                v120[v124 - 2 + v122] = v125;
                ++v124;
              }
              while ( v125 != 0 );
              sub_140001C10(v8);
              v50 = 0x8000000;
              v8 = 0;
              break;
            case 4:
              v104 = -2;
              do
              {
                v105 = *(_WORD *)(v8 + v104 + 2) == 0;
                v104 += 2;
              }
              while ( !v105 );
              v106 = -1;
              if ( v104 >= -65 )
                v106 = v104 + 64;
              v54 = sub_14002E070(v106);
              LODWORD(v154) = -156992656;
              v156[0].m256_f32[0] = 0.0;
              do
              {
                v107 = SLODWORD(v156[0].m256_f32[0]);
                ++LODWORD(v156[0].m256_f32[0]);
                *((_WORD *)&v154 + v107) = (*((_WORD *)&v154 + v107)
                                          ^ ((LOWORD(v156[0].m256_f32[0]) & 0x84AD)
                                           * (LOWORD(v156[0].m256_f32[0]) & 0x7B52 ^ 0x7B52)
                                           + (LOWORD(v156[0].m256_f32[0]) & 0x7B52)
                                           * (LOWORD(v156[0].m256_f32[0]) | 0x7B52)))
                                         & ~(*((_WORD *)&v154 + v107)
                                           & ((LOWORD(v156[0].m256_f32[0]) & 0x84AD)
                                            * (LOWORD(v156[0].m256_f32[0]) & 0x7B52 ^ 0x7B52)
                                            + (LOWORD(v156[0].m256_f32[0]) & 0x7B52)
                                            * (LOWORD(v156[0].m256_f32[0]) | 0x7B52)));
              }
              while ( LODWORD(v156[0].m256_f32[0]) < 2 );
              v156[0] = ymmword_1400342F8;
              LOWORD(v156[1].m256_f32[0]) = 6243;
              LODWORD(v153[0]) = 0;
              do
              {
                v108 = SLODWORD(v153[0]);
                LODWORD(v153[0]) = (LODWORD(v153[0]) ^ 1) + 2 * (v153[0] & 1);
                *((_WORD *)v156[0].m256_f32 + v108) ^= -15053 * LOWORD(v153[0]);
              }
              while ( LODWORD(v153[0]) < 0x11 );
              v109 = (_WORD *)v54;
              do
              {
                v110 = LOWORD(v99->m256_f32[0]);
                v99 = (__m256 *)((char *)v99 + 2);
                *v109++ = v110;
              }
              while ( v110 != 0 );
              v111 = 0;
              do
              {
                v112 = *(_WORD *)(v8 + v111 * 2);
                v109[v111++ - 1] = v112;
              }
              while ( v112 != 0 );
              v113 = 0;
              do
              {
                v114 = *(_WORD *)((char *)&v154 + v113 * 2);
                v109[v113 - 2 + v111] = v114;
                ++v113;
              }
              while ( v114 != 0 );
              sub_140001C10(v8);
              v8 = 0;
              break;
            default:
              v54 = 0;
              break;
          }
LABEL_81:
          memset(v156, 0, sizeof(v156));
          v157 = 0;
          LODWORD(v156[0].m256_f32[0]) = 104;
          v62 = (unsigned int (__fastcall *)(__int64, __int64, _QWORD, _QWORD))sub_14002FDC0(
                                                                                 qword_14003BA40,
                                                                                 2460270508LL);
          LODWORD(v147) = v50;
          LODWORD(v145) = 0;
          if ( v62(v8, v54, 0, 0) != 0 )
            goto LABEL_85;
          qmemcpy(v153, byte_14003434C, 29);
          for ( ii = 0; ii < 0x1D; *((_BYTE *)v153 + v64) ^= 90 * (_BYTE)ii )
            v64 = ii++;
          LODWORD(v147) = v50;
          LODWORD(v145) = 0;
          if ( v62(v8, v54, 0, 0) != 0 )
          {
LABEL_85:
            if ( qword_14003BB50 != 0 )
            {
              v65 = 0;
              while ( *(_DWORD *)(qword_14003BB58 + 8 * v65) != -1825720177 )
              {
                if ( qword_14003BB50 == ++v65 )
                  goto LABEL_89;
              }
              sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v65 + 4), 1, v155, v63, v145, v147);
              v66 = qword_14003BB50;
              if ( qword_14003BB50 != 0 )
              {
LABEL_94:
                v67 = 0;
                while ( *(_DWORD *)(qword_14003BB58 + 8 * v67) != -1825720177 )
                {
                  if ( v66 == ++v67 )
                    goto LABEL_97;
                }
                sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v67 + 4), 1, v154, v63, v145, v147);
                if ( v8 != 0 )
LABEL_100:
                  sub_140001C10(v8);
LABEL_101:
                LOBYTE(v8) = 1;
                if ( v54 != 0 )
                  sub_140001C10(v54);
                return (unsigned int)v8;
              }
            }
            else
            {
LABEL_89:
              LODWORD(v153[0]) = 0;
              do
                ++LODWORD(v153[0]);
              while ( LODWORD(v153[0]) == 0 );
              v66 = qword_14003BB50;
              if ( qword_14003BB50 != 0 )
                goto LABEL_94;
            }
LABEL_97:
            LODWORD(v153[0]) = 0;
            do
              ++LODWORD(v153[0]);
            while ( LODWORD(v153[0]) == 0 );
          }
          if ( v8 == 0 )
            goto LABEL_101;
          goto LABEL_100;
        }
      }
    }
LABEL_149:
    v52 = (_WORD *)v8;
    goto LABEL_150;
  }
LABEL_26:
  v17 = (__int64 (__fastcall *)(_QWORD, _QWORD, __int64 (__fastcall *)(), unsigned __int8 *, _DWORD, _QWORD))sub_14002FDC0(qword_14003BA40, 2014648154);
  v18 = v17(0, 0, sub_14001A240, a6, 0, 0);
  LOBYTE(v8) = 1;
  if ( v18 != 0 )
  {
    v19 = *a8;
    v20 = a8[1] - *a8;
    if ( a8[1] == a8[2] )
    {
      v41 = v18;
      v42 = (v20 >> 3) + ((unsigned __int64)(v20 >> 3) >> 1);
      if ( v42 <= (v20 >> 3) + 1 )
        v42 = (v20 >> 3) + 1;
      v43 = sub_140001B80(8 * v42);
      v21 = v43;
      if ( v19 != 0 )
      {
        sub_140001D60(v43, v19, v20);
        sub_140001C10(*a8);
      }
      *a8 = v21;
      a8[1] = v21 + v20;
      a8[2] = v21 + 8 * v42;
      v18 = v41;
    }
    else
    {
      v21 = *a8;
    }
    *(_QWORD *)(v21 + v20) = v18;
    a8[1] += 8LL;
  }
  return (unsigned int)v8;
}


// ---- sub_14001A240 @ 0x14001a240 ----
void sub_14001A240()
{
  nullsub_1();
  __asm { jmp     rax }
}


// ---- sub_14001A93A @ 0x14001a93a ----
__int64 __fastcall sub_14001A93A()
{
  __int64 v0; // rbp
  int v1; // edi
  __int64 v2; // rcx

  nullsub_1();
  LOBYTE(v2) = v1 == 0;
  *(_DWORD *)(v0 + 1292) = 0;
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v0 + 376) + 8LL * *(int *)(v0 + 1292)))(v2);
}


// ---- sub_14001A96C @ 0x14001a96c ----
__int64 __fastcall sub_14001A96C()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 520) + 8LL * *(int *)(v0 + 1364)))();
}


// ---- sub_14001A988 @ 0x14001a988 ----
__int64 __fastcall sub_14001A988()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 184) + 8LL * *(int *)(v0 + 1196)))();
}


// ---- sub_14001AA6C @ 0x14001aa6c ----
__int64 __fastcall sub_14001AA6C()
{
  __int64 v0; // rbp
  int v1; // esi

  *(_DWORD *)(v0 + 1340) = (v1 & 0x20000000) != 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 472) + 8LL * *(int *)(v0 + 1340)))();
}


// ---- sub_14001AA9D @ 0x14001aa9d ----
__int64 __fastcall sub_14001AA9D()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 608) + 8LL * *(int *)(v0 + 1408)))();
}


// ---- sub_14001AAB1 @ 0x14001aab1 ----
__int64 __fastcall sub_14001AAB1()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 712) + 8LL * *(int *)(v0 + 1460)))();
}


// ---- sub_14001AAC5 @ 0x14001aac5 ----
__int64 __fastcall sub_14001AAC5()
{
  __int64 v0; // rbp
  void (__fastcall *v1)(_QWORD, _QWORD, _QWORD); // rsi
  _QWORD *v2; // r15
  __int64 v3; // rax
  __int64 v4; // r9

  sub_14001C650(*(_QWORD *)(v0 + 1504));
  for ( *(_DWORD *)(v0 + 1600) = 0;
        *(_DWORD *)(v0 + 1600) == 0;
        *(_DWORD *)(v4 + 4 * v3) = (~(2 * ((656450448 * *(_DWORD *)(v0 + 1600)) & *(_DWORD *)(v4 + 4 * v3)))
                                  + ((656450448 * *(_DWORD *)(v0 + 1600)) & *(_DWORD *)(v4 + 4 * v3)))
                                 & ((656450448 * *(_DWORD *)(v0 + 1600)) | *(_DWORD *)(v4 + 4 * v3)) )
  {
    v3 = (int)(*(_DWORD *)(v0 + 1600))++;
    v4 = *(_QWORD *)(v0 + 1504);
  }
  v1(*v2, **(unsigned int **)(v0 + 1504), 0);
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v0 + 648) + 8LL * *(int *)(v0 + 1428)))(1);
}


// ---- sub_14001AB67 @ 0x14001ab67 ----
__int64 __fastcall sub_14001AB67()
{
  __int64 v0; // rbp

  nullsub_1();
  *(_DWORD *)(v0 + 1392) = 1;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 576) + 8LL * *(int *)(v0 + 1392)))();
}


// ---- sub_14001AB92 @ 0x14001ab92 ----
__int64 __fastcall sub_14001AB92()
{
  __int64 v0; // rbp
  unsigned __int64 v1; // r12
  unsigned __int64 v2; // r13

  *(_DWORD *)(v0 + 1160) = v2 < v1;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 112) + 8LL * *(int *)(v0 + 1160)))();
}


// ---- sub_14001ABD8 @ 0x14001abd8 ----
__int64 __fastcall sub_14001ABD8()
{
  __int64 v0; // rbp

  nullsub_1();
  *(_DWORD *)(v0 + 1188) = 1;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 168) + 8LL * *(int *)(v0 + 1188)))();
}


// ---- sub_14001AC03 @ 0x14001ac03 ----
__int64 __fastcall sub_14001AC03()
{
  __int64 v0; // rbp
  int v1; // edi

  *(_DWORD *)(v0 + 1264) = v1 == 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 320) + 8LL * *(int *)(v0 + 1264)))();
}


// ---- sub_14001AC24 @ 0x14001ac24 ----
__int64 __fastcall sub_14001AC24()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 552) + 8LL * *(int *)(v0 + 1380)))();
}


// ---- sub_14001AC38 @ 0x14001ac38 ----
__int64 __fastcall sub_14001AC38(unsigned int a1)
{
  unsigned int *v1; // rax
  __int64 v2; // rbp
  __int64 v3; // rdi
  _QWORD *v4; // r15

  sub_140001C40(*(unsigned int *)(v3 + 12) + *v4, *v1 + *(_QWORD *)(v2 + 1584), a1);
  return (*(__int64 (**)(void))(*(_QWORD *)(v2 + 56) + 8LL * *(int *)(v2 + 1132)))();
}


// ---- sub_14001AC6E @ 0x14001ac6e ----
__int64 __fastcall sub_14001AC6E(unsigned int a1)
{
  __int64 v1; // rbp

  **(_QWORD **)(v1 + 1512) = a1;
  *(_DWORD *)(v1 + 1324) = a1 == 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 + 440) + 8LL * *(int *)(v1 + 1324)))();
}


// ---- sub_14001AC9B @ 0x14001ac9b ----
__int64 __fastcall sub_14001AC9B()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 488) + 8LL * *(int *)(v0 + 1348)))();
}


// ---- sub_14001ACBB @ 0x14001acbb ----
__int64 __fastcall sub_14001ACBB()
{
  int v0; // eax
  __int64 v1; // rbp

  **(_DWORD **)(v1 + 1520) = v0 | 0x200;
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 + 536) + 8LL * *(int *)(v1 + 1372)))();
}


// ---- sub_14001ACDD @ 0x14001acdd ----
__int64 __fastcall sub_14001ACDD()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 32) + 8LL * *(int *)(v0 + 1120)))();
}


// ---- sub_14001ACEE @ 0x14001acee ----
__int64 __fastcall sub_14001ACEE()
{
  __int64 v0; // rbx
  __int64 v1; // rbp

  *(_DWORD *)(v1 + 1216) = *(_DWORD *)(v0 + 12) != 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 + 224) + 8LL * *(int *)(v1 + 1216)))();
}


// ---- sub_14001AD19 @ 0x14001ad19 ----
__int64 __fastcall sub_14001AD19(char a1)
{
  __int64 v1; // rbp

  *(_DWORD *)(v1 + 1048) = a1 & 1;
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 - 112) + 8LL * *(int *)(v1 + 1048)))();
}


// ---- sub_14001AD35 @ 0x14001ad35 ----
__int64 __fastcall sub_14001AD35()
{
  __int64 v0; // rbp

  nullsub_1();
  *(_DWORD *)(v0 + 1200) = 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 192) + 8LL * *(int *)(v0 + 1200)))();
}


// ---- sub_14001AD60 @ 0x14001ad60 ----
__int64 __fastcall sub_14001AD60()
{
  __int64 v0; // rbp

  nullsub_1();
  *(_DWORD *)(v0 + 1100) = 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 - 8) + 8LL * *(int *)(v0 + 1100)))();
}


// ---- sub_14001ADAC @ 0x14001adac ----
__int64 __fastcall sub_14001ADAC()
{
  __int64 v0; // rax
  __int64 v1; // rbp

  return (*(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v1 + 432) + 8LL * *(int *)(v1 + 1320)))(*(unsigned int *)(v0 + 16));
}


// ---- sub_14001ADC3 @ 0x14001adc3 ----
__int64 __fastcall sub_14001ADC3()
{
  __int64 v0; // rbp

  *(_QWORD *)(v0 + 816) = sub_14002FDC0(qword_14003BA40, 594155830);
  *(_QWORD *)(v0 + 1032) = sub_14002FDC0(qword_14003BA40, 123587604);
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 232) + 8LL * *(int *)(v0 + 1220)))();
}


// ---- sub_14001AE1F @ 0x14001ae1f ----
__int64 __fastcall sub_14001AE1F()
{
  __int16 v0; // ax
  __int64 v1; // rbp
  __int64 v2; // rdi
  _DWORD *v3; // rsi
  _QWORD *v4; // r15

  *(_QWORD *)(*v4 + (v0 & 0xFFFu) + *v3) += v2;
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 + 152) + 8LL * *(int *)(v1 + 1180)))();
}


// ---- sub_14001AE4A @ 0x14001ae4a ----
__int64 __fastcall sub_14001AE4A()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 360) + 8LL * *(int *)(v0 + 1284)))();
}


// ---- sub_14001AE60 @ 0x14001ae60 ----
__int64 __fastcall sub_14001AE60()
{
  __int64 v0; // rbp
  void (*v1)(void); // rsi

  v1();
  return (*(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v0 + 656) + 8LL * *(int *)(v0 + 1432)))(0);
}


// ---- sub_14001AE82 @ 0x14001ae82 ----
__int64 __fastcall sub_14001AE82()
{
  __int64 v0; // rbp
  unsigned __int16 v1; // di
  unsigned __int16 *v2; // r14

  *(_DWORD *)(v0 + 1304) = v1 < (unsigned int)*v2;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 400) + 8LL * *(int *)(v0 + 1304)))();
}


// ---- sub_14001AEAA @ 0x14001aeaa ----
__int64 __fastcall sub_14001AEAA()
{
  _QWORD *v0; // rbx
  __int64 v1; // rbp
  _DWORD *v2; // rsi
  __int64 v3; // r12
  _QWORD *v4; // r13
  _DWORD *v5; // r14
  _QWORD *v6; // rdi
  __int64 v7; // rax
  unsigned int v8; // eax
  unsigned __int64 i; // r14
  bool v10; // r15
  bool v11; // di
  __int64 v12; // rax

  *(_QWORD *)(v1 + 880) = v3 + 24;
  **(_QWORD **)(v1 + 1528) = *(unsigned int *)(v3 + 80);
  v6 = *(_QWORD **)(v1 + 1592);
  *v6 = 0;
  **(_DWORD **)(v1 + 1008) = 4;
  sub_14001C640(v5);
  for ( *(_DWORD *)(v1 + 1604) = 0; *(_DWORD *)(v1 + 1604) == 0; v5[v7] ^= 149498337 * *(_DWORD *)(v1 + 1604) )
    v7 = (int)(*(_DWORD *)(v1 + 1604))++;
  **(_DWORD **)(v1 + 1016) = *v5;
  **(_QWORD **)(v1 + 1024) = *(_QWORD *)(v1 + 1528);
  *v2 = 0;
  *v4 = v6;
  v8 = -1;
  *v0 = -1;
  for ( i = 0; ; ++i )
  {
    v10 = i < qword_14003BB50;
    if ( i >= qword_14003BB50 )
      break;
    v11 = *(_DWORD *)(qword_14003BB58 + 8 * i) == -1834021682;
    if ( *(_DWORD *)(qword_14003BB58 + 8 * i) == -1834021682 )
      v8 = sub_14002F100(
             *(_DWORD *)(8 * i + qword_14003BB58 + 4),
             6,
             *v0,
             *v4,
             (unsigned int)*v2,
             **(_QWORD **)(v1 + 1024));
    if ( v11 )
      break;
  }
  if ( !v10 )
  {
    sub_14001C660(v1 + 1563, v1 + 1580);
    for ( *(_DWORD *)(v1 + 1608) = 0;
          *(_DWORD *)(v1 + 1608) == 0;
          *(_DWORD *)(v1 + 4 * v12 + 1580) = (-2
                                            - ((~*(_DWORD *)(v1 + 4 * v12 + 1580)
                                              | (-1371358004 * *(_DWORD *)(v1 + 1608)))
                                             + *(_DWORD *)(v1 + 4 * v12 + 1580)))
                                           & ((-1371358004 * *(_DWORD *)(v1 + 1608)) | *(_DWORD *)(v1 + 4 * v12 + 1580)) )
    {
      v12 = (int)(*(_DWORD *)(v1 + 1608))++;
    }
    v8 = *(_DWORD *)(v1 + 1580);
  }
  *(_DWORD *)(v1 + 1064) = v8 >> 31;
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 - 80) + 8LL * *(int *)(v1 + 1064)))();
}


// ---- sub_14001B0BE @ 0x14001b0be ----
__int64 __fastcall sub_14001B0BE()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 136) + 8LL * *(int *)(v0 + 1172)))();
}


// ---- sub_14001B0D2 @ 0x14001b0d2 ----
__int64 __fastcall sub_14001B0D2()
{
  unsigned int *v0; // rax
  __int64 v1; // rbp
  _QWORD *v2; // r15

  *(_DWORD *)(v1 + 1388) = *(_QWORD *)(*v2 + *v0 + 24LL) != 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 + 568) + 8LL * *(int *)(v1 + 1388)))();
}


// ---- sub_14001B0FE @ 0x14001b0fe ----
__int64 __fastcall sub_14001B0FE()
{
  _QWORD *v0; // rbx
  __int64 v1; // rbp

  *(_DWORD *)(v1 + 1240) = *v0 != 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 + 272) + 8LL * *(int *)(v1 + 1240)))();
}


// ---- sub_14001B123 @ 0x14001b123 ----
__int64 __fastcall sub_14001B123()
{
  __int64 v0; // rbp
  __int64 v1; // rsi
  __int64 v2; // r12
  _QWORD *v3; // r15
  _WORD *v4; // rdi

  *(_QWORD *)(v0 + 1544) = v2;
  v4 = *(_WORD **)(v0 + 808);
  sub_1400068A0(v4, 260, (unsigned __int8 *)(*(unsigned int *)(v1 + 12) + *v3), 0);
  *(_DWORD *)(v0 + 1228) = (*(__int64 (__fastcall **)(_WORD *))(v0 + 816))(v4) == 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 248) + 8LL * *(int *)(v0 + 1228)))();
}


// ---- sub_14001B180 @ 0x14001b180 ----
__int64 __fastcall sub_14001B180()
{
  __int64 v0; // rbp
  __int64 v1; // r13
  __int64 v2; // rdx

  nullsub_1();
  LOBYTE(v2) = *(_DWORD *)(v1 + 16) != 0;
  *(_DWORD *)(v0 + 1416) = 0;
  return (*(__int64 (__fastcall **)(_QWORD, __int64))(*(_QWORD *)(v0 + 624) + 8LL * *(int *)(v0 + 1416)))(0, v2);
}


// ---- sub_14001B1B7 @ 0x14001b1b7 ----
__int64 __fastcall sub_14001B1B7()
{
  __int64 v0; // rbp

  nullsub_1();
  *(_DWORD *)(v0 + 1352) = 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 496) + 8LL * *(int *)(v0 + 1352)))();
}


// ---- sub_14001B1E2 @ 0x14001b1e2 ----
__int64 __fastcall sub_14001B1E2()
{
  __int64 v0; // rbp

  nullsub_1();
  *(_DWORD *)(v0 + 1088) = 1;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 - 32) + 8LL * *(int *)(v0 + 1088)))();
}


// ---- sub_14001B20A @ 0x14001b20a ----
__int64 __fastcall sub_14001B20A(__int64 a1, char a2)
{
  __int64 v2; // rbp

  *(_DWORD *)(v2 + 1400) = a2 & 1;
  return (*(__int64 (**)(void))(*(_QWORD *)(v2 + 592) + 8LL * *(int *)(v2 + 1400)))();
}


// ---- sub_14001B229 @ 0x14001b229 ----
__int64 __fastcall sub_14001B229()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 - 72) + 8LL * *(int *)(v0 + 1068)))();
}


// ---- sub_14001B23C @ 0x14001b23c ----
__int64 __fastcall sub_14001B23C(__int64 a1, char a2)
{
  __int64 v2; // rbp

  *(_DWORD *)(v2 + 1420) = a2 & 1;
  return (*(__int64 (**)(void))(*(_QWORD *)(v2 + 632) + 8LL * *(int *)(v2 + 1420)))();
}


// ---- sub_14001B277 @ 0x14001b277 ----
__int64 __fastcall sub_14001B277()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 208) + 8LL * *(int *)(v0 + 1208)))();
}


// ---- sub_14001B292 @ 0x14001b292 ----
__int64 __fastcall sub_14001B292()
{
  __int64 v0; // rbp
  _QWORD *v1; // r15
  _QWORD *v2; // rdx
  unsigned __int64 i; // rsi
  bool v4; // bl
  bool v5; // di
  __int64 v6; // rax

  v2 = *(_QWORD **)(v0 + 800);
  *v2 = *v1;
  **(_QWORD **)(v0 + 920) = *(_QWORD *)(v0 + 832);
  **(_DWORD **)(v0 + 936) = 2;
  **(_QWORD **)(v0 + 944) = *(_QWORD *)(v0 + 928);
  **(_QWORD **)(v0 + 952) = v2;
  **(_QWORD **)(v0 + 960) = -1;
  for ( i = 0; ; ++i )
  {
    v4 = i < qword_14003BB50;
    if ( i >= qword_14003BB50 )
      break;
    v5 = *(_DWORD *)(qword_14003BB58 + 8 * i) == -2107000239;
    if ( *(_DWORD *)(qword_14003BB58 + 8 * i) == -2107000239 )
      sub_14002F100(
        *(_DWORD *)(8 * i + qword_14003BB58 + 4),
        5,
        **(_QWORD **)(v0 + 960),
        **(_QWORD **)(v0 + 952),
        **(_QWORD **)(v0 + 944),
        **(int **)(v0 + 936));
    if ( v5 )
      break;
  }
  if ( !v4 )
  {
    sub_14001C660(v0 + 1561, v0 + 1572);
    for ( *(_DWORD *)(v0 + 1616) = 0;
          *(_DWORD *)(v0 + 1616) == 0;
          *(_DWORD *)(v0 + 4 * v6 + 1572) = (-2
                                           - ((~*(_DWORD *)(v0 + 4 * v6 + 1572) | (-1371358004 * *(_DWORD *)(v0 + 1616)))
                                            + *(_DWORD *)(v0 + 4 * v6 + 1572)))
                                          & ((-1371358004 * *(_DWORD *)(v0 + 1616)) | *(_DWORD *)(v0 + 4 * v6 + 1572)) )
    {
      v6 = (int)(*(_DWORD *)(v0 + 1616))++;
    }
  }
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 392) + 8LL * *(int *)(v0 + 1300)))();
}


// ---- sub_14001B438 @ 0x14001b438 ----
__int64 __fastcall sub_14001B438()
{
  __int64 v0; // rbp
  __int64 v1; // rdi

  *(_DWORD *)(v0 + 1112) = *(_DWORD *)(v1 + 8) != 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 16) + 8LL * *(int *)(v0 + 1112)))();
}


// ---- sub_14001B459 @ 0x14001b459 ----
__int64 __fastcall sub_14001B459()
{
  __int64 v0; // rbp

  nullsub_1();
  *(_DWORD *)(v0 + 1272) = 1;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 336) + 8LL * *(int *)(v0 + 1272)))();
}


// ---- sub_14001B484 @ 0x14001b484 ----
__int64 __fastcall sub_14001B484()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 680) + 8LL * *(int *)(v0 + 1444)))();
}


// ---- sub_14001B49D @ 0x14001b49d ----
__int64 __fastcall sub_14001B49D()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 64) + 8LL * *(int *)(v0 + 1136)))();
}


// ---- sub_14001B4B0 @ 0x14001b4b0 ----
__int64 __fastcall sub_14001B4B0()
{
  __int64 v0; // rbp

  nullsub_1();
  *(_DWORD *)(v0 + 1356) = 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 504) + 8LL * *(int *)(v0 + 1356)))();
}


// ---- sub_14001B4DB @ 0x14001b4db ----
__int64 __fastcall sub_14001B4DB()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 696) + 8LL * *(int *)(v0 + 1452)))();
}


// ---- sub_14001B4EF @ 0x14001b4ef ----
__int64 __fastcall sub_14001B4EF()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 - 104) + 8LL * *(int *)(v0 + 1052)))();
}


// ---- sub_14001B502 @ 0x14001b502 ----
__int64 __fastcall sub_14001B502()
{
  __int64 v0; // rbp

  nullsub_1();
  *(_DWORD *)(v0 + 1288) = 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 368) + 8LL * *(int *)(v0 + 1288)))();
}


// ---- sub_14001B52D @ 0x14001b52d ----
__int64 __fastcall sub_14001B52D()
{
  __int64 v0; // rbp
  __int64 v1; // r13
  __int64 (*v2)(void); // rcx

  *(_DWORD *)(v0 + 1080) = *(_DWORD *)(v1 + 156) != 0;
  v2 = *(__int64 (**)(void))(*(_QWORD *)(v0 - 48) + 8LL * *(int *)(v0 + 1080));
  *(_QWORD *)(v0 + 968) = v1 + 112;
  return v2();
}


// ---- sub_14001B569 @ 0x14001b569 ----
__int64 __fastcall sub_14001B569(int a1)
{
  __int64 v1; // rbp

  *(_DWORD *)(v1 + 1436) = a1 == 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 + 664) + 8LL * *(int *)(v1 + 1436)))();
}


// ---- sub_14001B58A @ 0x14001b58a ----
__int64 __fastcall sub_14001B58A()
{
  __int64 v0; // rbp
  unsigned __int64 i; // rsi
  bool v2; // bl
  bool v3; // r15
  __int64 v4; // rax

  **(_QWORD **)(v0 + 872) = *(_QWORD *)(v0 + 832);
  **(_QWORD **)(v0 + 888) = *(_QWORD *)(v0 + 1512);
  **(_QWORD **)(v0 + 896) = *(_QWORD *)(v0 + 1536);
  **(_QWORD **)(v0 + 904) = -1;
  for ( i = 0; ; ++i )
  {
    v2 = i < qword_14003BB50;
    if ( i >= qword_14003BB50 )
      break;
    v3 = *(_DWORD *)(qword_14003BB58 + 8 * i) == -2107000239;
    if ( *(_DWORD *)(qword_14003BB58 + 8 * i) == -2107000239 )
      sub_14002F100(
        *(_DWORD *)(8 * i + qword_14003BB58 + 4),
        5,
        **(_QWORD **)(v0 + 904),
        **(_QWORD **)(v0 + 896),
        **(_QWORD **)(v0 + 888),
        **(unsigned int **)(v0 + 1520));
    if ( v3 )
      break;
  }
  if ( !v2 )
  {
    sub_14001C660(v0 + 1559, v0 + 1564);
    for ( *(_DWORD *)(v0 + 1624) = 0;
          *(_DWORD *)(v0 + 1624) == 0;
          *(_DWORD *)(v0 + 4 * v4 + 1564) = (-2
                                           - ((~*(_DWORD *)(v0 + 4 * v4 + 1564) | (-1371358004 * *(_DWORD *)(v0 + 1624)))
                                            + *(_DWORD *)(v0 + 4 * v4 + 1564)))
                                          & ((-1371358004 * *(_DWORD *)(v0 + 1624)) | *(_DWORD *)(v0 + 4 * v4 + 1564)) )
    {
      v4 = (int)(*(_DWORD *)(v0 + 1624))++;
    }
  }
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 544) + 8LL * *(int *)(v0 + 1376)))();
}


// ---- sub_14001B729 @ 0x14001b729 ----
__int64 __fastcall sub_14001B729(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // rbp
  __int64 v4; // rsi
  __int64 v5; // r12

  *(_QWORD *)(v3 + 1544) = v5;
  return (*(__int64 (__fastcall **)(_QWORD, __int64, __int64, __int64))(*(_QWORD *)(v3 + 104) + 8LL
                                                                                              * *(int *)(v3 + 1156)))(
           *(_QWORD *)(v3 + 104),
           a2,
           a3,
           v4 + 8);
}


// ---- sub_14001B76D @ 0x14001b76d ----
__int64 __fastcall sub_14001B76D()
{
  __int64 v0; // rbp

  nullsub_1();
  *(_DWORD *)(v0 + 1412) = 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 616) + 8LL * *(int *)(v0 + 1412)))();
}


// ---- sub_14001B798 @ 0x14001b798 ----
__int64 __fastcall sub_14001B798()
{
  __int64 v0; // rbp
  __int64 v1; // r13
  _QWORD *v2; // r15

  *(_DWORD *)(v0 + 1140) = *v2 != *(_QWORD *)(v1 + 24);
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 72) + 8LL * *(int *)(v0 + 1140)))();
}


// ---- sub_14001B7D9 @ 0x14001b7d9 ----
__int64 __fastcall sub_14001B7D9()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 752) + 8LL * *(int *)(v0 + 1480)))();
}


// ---- sub_14001B7ED @ 0x14001b7ed ----
__int64 __fastcall sub_14001B7ED()
{
  unsigned __int64 v0; // rax
  __int64 v1; // rbp

  *(_DWORD *)(v1 + 1244) = v0 >> 63;
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 + 280) + 8LL * *(int *)(v1 + 1244)))();
}


// ---- sub_14001B80E @ 0x14001b80e ----
__int64 __fastcall sub_14001B80E()
{
  unsigned int v0; // ebx
  __int64 v1; // rbp

  return (*(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v1 + 48) + 8LL * *(int *)(v1 + 1128)))(v0);
}


// ---- sub_14001B821 @ 0x14001b821 ----
__int64 __fastcall sub_14001B821()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 - 88) + 8LL * *(int *)(v0 + 1060)))();
}


// ---- sub_14001B834 @ 0x14001b834 ----
__int64 __fastcall sub_14001B834(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rbp
  __int64 v5; // r13

  *(_DWORD *)(v4 + 1168) = *(unsigned __int16 *)(a4 + 2 * v5) >> 12 == 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v4 + 128) + 8LL * *(int *)(v4 + 1168)))();
}


// ---- sub_14001B85F @ 0x14001b85f ----
__int64 __fastcall sub_14001B85F()
{
  __int64 v0; // rbp
  char v1; // r15

  *(_DWORD *)(v0 + 1360) = v1 & 1;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 512) + 8LL * *(int *)(v0 + 1360)))();
}


// ---- sub_14001B885 @ 0x14001b885 ----
__int64 __fastcall sub_14001B885()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 560) + 8LL * *(int *)(v0 + 1384)))();
}


// ---- sub_14001B89B @ 0x14001b89b ----
// positive sp value has been detected, the output may be wrong!
void sub_14001B89B()
{
  ;
}


// ---- sub_14001B8AF @ 0x14001b8af ----
__int64 __fastcall sub_14001B8AF()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 424) + 8LL * *(int *)(v0 + 1316)))();
}


// ---- sub_14001B931 @ 0x14001b931 ----
__int64 __fastcall sub_14001B931()
{
  __int64 v0; // rbp

  *(_DWORD *)(v0 + 1308) = *(_DWORD *)(*(_QWORD *)(v0 + 968) + 76LL) != 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 408) + 8LL * *(int *)(v0 + 1308)))();
}


// ---- sub_14001B963 @ 0x14001b963 ----
__int64 __fastcall sub_14001B963()
{
  __int64 v0; // rbp
  __int64 v1; // r12
  __int64 v2; // r13
  __int64 *v3; // r15
  unsigned __int64 v4; // r8

  v4 = *(unsigned int *)(v2 + 60);
  **(_QWORD **)(v0 + 928) = v4;
  sub_140001C40(*v3, *(_QWORD *)(v0 + 1584), v4);
  *(_QWORD *)(v0 + 912) = v1 + *(unsigned __int16 *)(v1 + 20) + 24;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 - 64) + 8LL * *(int *)(v0 + 1072)))();
}


// ---- sub_14001B9B7 @ 0x14001b9b7 ----
__int64 __fastcall sub_14001B9B7()
{
  __int64 v0; // rbp
  __int64 v1; // r12

  sub_14002E0B0(*(_QWORD *)(v0 + 1584));
  *(_DWORD *)(v0 + 1424) = (*(_WORD *)(v1 + 18) & 0x2000) != 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 640) + 8LL * *(int *)(v0 + 1424)))();
}


// ---- sub_14001B9F9 @ 0x14001b9f9 ----
__int64 __fastcall sub_14001B9F9()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 304) + 8LL * *(int *)(v0 + 1256)))();
}


// ---- sub_14001BA15 @ 0x14001ba15 ----
__int64 __fastcall sub_14001BA15()
{
  __int64 v0; // rbp
  _DWORD *v1; // rsi

  *(_DWORD *)(v0 + 1148) = *v1 != 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 88) + 8LL * *(int *)(v0 + 1148)))();
}


// ---- sub_14001BA35 @ 0x14001ba35 ----
__int64 __fastcall sub_14001BA35()
{
  __int64 v0; // rbp
  _DWORD *v1; // r15
  int v2; // edi
  __int64 v3; // rax

  v2 = *(_DWORD *)(*(_QWORD *)(v0 + 1584) + *(int *)(*(_QWORD *)(v0 + 1584) + 60LL));
  sub_14001C630(v1);
  for ( *(_DWORD *)(v0 + 1628) = 0; *(_DWORD *)(v0 + 1628) == 0; v1[v3] ^= 1790029872 * *(_DWORD *)(v0 + 1628) )
    v3 = (int)(*(_DWORD *)(v0 + 1628))++;
  *(_DWORD *)(v0 + 1056) = v2 != *v1;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 - 96) + 8LL * *(int *)(v0 + 1056)))();
}


// ---- sub_14001BABB @ 0x14001babb ----
__int64 __fastcall sub_14001BABB()
{
  __int64 v0; // rbp
  __int64 v1; // rdx
  __int64 v2; // rcx
  __int64 v3; // r8
  __int64 v4; // r9
  void *v5; // rsp
  __int64 v6; // rdx
  __int64 v7; // rcx
  __int64 v8; // r8
  __int64 v9; // r9
  void *v10; // rsp
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // r8
  __int64 v14; // r9
  void *v15; // rsp
  __int64 v16; // rdx
  __int64 v17; // rcx
  __int64 v18; // r8
  __int64 v19; // r9
  void *v20; // rsp
  __int64 v21; // rdx
  __int64 v22; // rcx
  __int64 v23; // r8
  __int64 v24; // r9
  void *v25; // rsp
  __int64 v26; // rdx
  __int64 v27; // rcx
  __int64 v28; // r8
  __int64 v29; // r9
  void *v30; // rsp
  __int64 v31; // rdx
  __int64 v32; // rcx
  __int64 v33; // r8
  __int64 v34; // r9
  void *v35; // rsp
  __int64 v36; // rdx
  __int64 v37; // rcx
  __int64 v38; // r8
  __int64 v39; // r9
  void *v40; // rsp
  __int64 v41; // rdx
  __int64 v42; // rcx
  __int64 v43; // r8
  __int64 v44; // r9
  void *v45; // rsp
  __int64 v46; // rdx
  __int64 v47; // rcx
  __int64 v48; // r8
  __int64 v49; // r9
  void *v50; // rsp
  __int64 v51; // rdx
  __int64 v52; // rcx
  __int64 v53; // r8
  __int64 v54; // r9
  void *v55; // rsp
  __int64 v56; // rdx
  __int64 v57; // rcx
  __int64 v58; // r8
  __int64 v59; // r9
  void *v60; // rsp
  __int64 v61; // rdx
  __int64 v62; // rcx
  __int64 v63; // r8
  __int64 v64; // r9
  void *v65; // rsp
  __int64 v66; // rdx
  __int64 v67; // rcx
  __int64 v68; // r8
  __int64 v69; // r9
  void *v70; // rsp
  __int64 v71; // rdx
  __int64 v72; // rcx
  __int64 v73; // r8
  __int64 v74; // r9
  void *v75; // rsp
  __int64 v76; // rdx
  __int64 v77; // rcx
  __int64 v78; // r8
  __int64 v79; // r9
  void *v80; // rsp
  __int64 v81; // rdx
  __int64 v82; // rcx
  __int64 v83; // r8
  __int64 v84; // r9
  void *v85; // rsp
  __int64 v86; // rdx
  __int64 v87; // rcx
  __int64 v88; // r8
  __int64 v89; // r9
  void *v90; // rsp
  __int64 v91; // rdx
  __int64 v92; // rcx
  __int64 v93; // r8
  __int64 v94; // r9
  void *v95; // rsp
  __int64 v96; // rdx
  __int64 v97; // rcx
  __int64 v98; // r8
  __int64 v99; // r9
  void *v100; // rsp
  __int64 v101; // rdx
  __int64 v102; // rcx
  __int64 v103; // r8
  __int64 v104; // r9
  void *v105; // rsp
  __int64 v106; // rdx
  __int64 v107; // rcx
  __int64 v108; // r8
  __int64 v109; // r9
  void *v110; // rsp
  __int64 v111; // rdx
  __int64 v112; // rcx
  __int64 v113; // r8
  __int64 v114; // r9
  void *v115; // rsp
  __int64 v116; // rdx
  __int64 v117; // rcx
  __int64 v118; // r8
  __int64 v119; // r9
  void *v120; // rsp
  __int64 v121; // rdx
  __int64 v122; // rcx
  __int64 v123; // r8
  __int64 v124; // r9
  void *v125; // rsp
  __int64 v126; // rdx
  __int64 v127; // rcx
  __int64 v128; // r8
  __int64 v129; // r9
  void *v130; // rsp
  __int64 v131; // rdx
  __int64 v132; // rcx
  __int64 v133; // r8
  __int64 v134; // r9
  void *v135; // rsp
  __int64 v136; // rdx
  __int64 v137; // rcx
  __int64 v138; // r8
  __int64 v139; // r9
  void *v140; // rsp
  __int64 v141; // rdx
  __int64 v142; // rcx
  __int64 v143; // r8
  __int64 v144; // r9
  void *v145; // rsp
  __int64 v146; // rdx
  __int64 v147; // rcx
  __int64 v148; // r8
  __int64 v149; // r9
  void *v150; // rsp
  __int64 v151; // rdx
  __int64 v152; // rcx
  __int64 v153; // r8
  __int64 v154; // r9
  void *v155; // rsp
  __int64 v156; // rdx
  __int64 v157; // rcx
  __int64 v158; // r8
  __int64 v159; // r9
  void *v160; // rsp
  __int64 v161; // rdx
  __int64 v162; // rcx
  __int64 v163; // r8
  __int64 v164; // r9
  void *v165; // rsp
  __int64 v166; // rdx
  __int64 v167; // rcx
  __int64 v168; // r8
  __int64 v169; // r9
  void *v170; // rsp
  __int64 v171; // rdx
  __int64 v172; // rcx
  __int64 v173; // r8
  __int64 v174; // r9
  void *v175; // rsp
  __int64 v176; // rdx
  __int64 v177; // rcx
  __int64 v178; // r8
  __int64 v179; // r9
  void *v180; // rsp
  __int64 v181; // rdx
  __int64 v182; // rcx
  __int64 v183; // r8
  __int64 v184; // r9
  void *v185; // rsp
  __int64 v186; // rdx
  __int64 v187; // rcx
  __int64 v188; // r8
  __int64 v189; // r9
  void *v190; // rsp
  __int64 v191; // rdx
  __int64 v192; // rcx
  __int64 v193; // r8
  __int64 v194; // r9
  void *v195; // rsp
  __int64 v196; // rdx
  __int64 v197; // rcx
  __int64 v198; // r8
  __int64 v199; // r9
  void *v200; // rsp
  int v201; // edi
  __int64 v202; // rax
  __int64 v203; // rcx
  _UNKNOWN *retaddr; // [rsp+20h] [rbp+0h] BYREF

  nullsub_1();
  v5 = alloca(sub_140001B30(v2, v1, v3, v4));
  v10 = alloca(sub_140001B30(v7, v6, v8, v9));
  v15 = alloca(sub_140001B30(v12, v11, v13, v14));
  v20 = alloca(sub_140001B30(v17, v16, v18, v19));
  v25 = alloca(sub_140001B30(v22, v21, v23, v24));
  *(_QWORD *)(v0 + 1528) = &retaddr;
  v30 = alloca(sub_140001B30(v27, v26, v28, v29));
  *(_QWORD *)(v0 + 1592) = &retaddr;
  v35 = alloca(sub_140001B30(v32, v31, v33, v34));
  *(_QWORD *)(v0 + 1008) = &retaddr;
  v40 = alloca(sub_140001B30(v37, v36, v38, v39));
  *(_QWORD *)(v0 + 1016) = &retaddr;
  v45 = alloca(sub_140001B30(v42, v41, v43, v44));
  v50 = alloca(sub_140001B30(v47, v46, v48, v49));
  v55 = alloca(sub_140001B30(v52, v51, v53, v54));
  *(_QWORD *)(v0 + 1024) = &retaddr;
  v60 = alloca(sub_140001B30(v57, v56, v58, v59));
  v65 = alloca(sub_140001B30(v62, v61, v63, v64));
  v70 = alloca(sub_140001B30(v67, v66, v68, v69));
  v75 = alloca(sub_140001B30(v72, v71, v73, v74));
  *(_QWORD *)(v0 + 928) = &retaddr;
  v80 = alloca(sub_140001B30(v77, v76, v78, v79));
  *(_QWORD *)(v0 + 808) = &retaddr;
  v85 = alloca(sub_140001B30(v82, v81, v83, v84));
  *(_QWORD *)(v0 + 976) = &retaddr;
  v90 = alloca(sub_140001B30(v87, v86, v88, v89));
  *(_QWORD *)(v0 + 984) = &retaddr;
  v95 = alloca(sub_140001B30(v92, v91, v93, v94));
  *(_QWORD *)(v0 + 992) = &retaddr;
  v100 = alloca(sub_140001B30(v97, v96, v98, v99));
  *(_QWORD *)(v0 + 1000) = &retaddr;
  v105 = alloca(sub_140001B30(v102, v101, v103, v104));
  *(_QWORD *)(v0 + 800) = &retaddr;
  v110 = alloca(sub_140001B30(v107, v106, v108, v109));
  *(_QWORD *)(v0 + 832) = &retaddr;
  v115 = alloca(sub_140001B30(v112, v111, v113, v114));
  *(_QWORD *)(v0 + 920) = &retaddr;
  v120 = alloca(sub_140001B30(v117, v116, v118, v119));
  *(_QWORD *)(v0 + 936) = &retaddr;
  v125 = alloca(sub_140001B30(v122, v121, v123, v124));
  *(_QWORD *)(v0 + 944) = &retaddr;
  v130 = alloca(sub_140001B30(v127, v126, v128, v129));
  *(_QWORD *)(v0 + 952) = &retaddr;
  v135 = alloca(sub_140001B30(v132, v131, v133, v134));
  *(_QWORD *)(v0 + 960) = &retaddr;
  v140 = alloca(sub_140001B30(v137, v136, v138, v139));
  *(_QWORD *)(v0 + 1512) = &retaddr;
  v145 = alloca(sub_140001B30(v142, v141, v143, v144));
  *(_QWORD *)(v0 + 1536) = &retaddr;
  v150 = alloca(sub_140001B30(v147, v146, v148, v149));
  *(_QWORD *)(v0 + 840) = &retaddr;
  v155 = alloca(sub_140001B30(v152, v151, v153, v154));
  *(_QWORD *)(v0 + 848) = &retaddr;
  v160 = alloca(sub_140001B30(v157, v156, v158, v159));
  *(_QWORD *)(v0 + 856) = &retaddr;
  v165 = alloca(sub_140001B30(v162, v161, v163, v164));
  *(_QWORD *)(v0 + 864) = &retaddr;
  v170 = alloca(sub_140001B30(v167, v166, v168, v169));
  *(_QWORD *)(v0 + 1520) = &retaddr;
  v175 = alloca(sub_140001B30(v172, v171, v173, v174));
  *(_QWORD *)(v0 + 872) = &retaddr;
  v180 = alloca(sub_140001B30(v177, v176, v178, v179));
  *(_QWORD *)(v0 + 888) = &retaddr;
  v185 = alloca(sub_140001B30(v182, v181, v183, v184));
  *(_QWORD *)(v0 + 896) = &retaddr;
  v190 = alloca(sub_140001B30(v187, v186, v188, v189));
  *(_QWORD *)(v0 + 904) = &retaddr;
  v195 = alloca(sub_140001B30(v192, v191, v193, v194));
  *(_QWORD *)(v0 + 1504) = &retaddr;
  v200 = alloca(sub_140001B30(v197, v196, v198, v199));
  v201 = **(unsigned __int16 **)(v0 + 1584);
  sub_14001C620(&retaddr);
  for ( *(_DWORD *)(v0 + 1632) = 0;
        *(_DWORD *)(v0 + 1632) == 0;
        *((_DWORD *)&retaddr + v202) ^= 1283077757 * *(_DWORD *)(v0 + 1632) )
  {
    v202 = (int)(*(_DWORD *)(v0 + 1632))++;
  }
  v203 = (unsigned int)retaddr;
  LOBYTE(v203) = v201 != (_DWORD)retaddr;
  *(_DWORD *)(v0 + 1044) = 0;
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v0 - 120) + 8LL * *(int *)(v0 + 1044)))(v203);
}


// ---- sub_14001BE35 @ 0x14001be35 ----
__int64 __fastcall sub_14001BE35()
{
  __int64 v0; // rbp

  nullsub_1();
  *(_DWORD *)(v0 + 1104) = 0;
  return (*(__int64 (**)(void))(*(_QWORD *)v0 + 8LL * *(int *)(v0 + 1104)))();
}


// ---- sub_14001BE5D @ 0x14001be5d ----
__int64 __fastcall sub_14001BE5D()
{
  __int64 v0; // rbp
  __int64 v1; // r15
  _QWORD *v2; // rax
  unsigned __int64 i; // rdi
  bool v4; // bl
  bool v5; // r15
  __int64 v6; // rax

  v2 = *(_QWORD **)(v0 + 1528);
  *v2 = 0;
  **(_DWORD **)(v0 + 976) = 0x8000;
  **(_QWORD **)(v0 + 984) = v2;
  **(_QWORD **)(v0 + 992) = v1;
  **(_QWORD **)(v0 + 1000) = -1;
  for ( i = 0; ; ++i )
  {
    v4 = i < qword_14003BB50;
    if ( i >= qword_14003BB50 )
      break;
    v5 = *(_DWORD *)(qword_14003BB58 + 8 * i) == -289015568;
    if ( *(_DWORD *)(qword_14003BB58 + 8 * i) == -289015568 )
      sub_14002F100(
        *(_DWORD *)(8 * i + qword_14003BB58 + 4),
        4,
        **(_QWORD **)(v0 + 1000),
        **(_QWORD **)(v0 + 992),
        **(_QWORD **)(v0 + 984),
        **(int **)(v0 + 976));
    if ( v5 )
      break;
  }
  if ( !v4 )
  {
    sub_14001C660(v0 + 1562, v0 + 1576);
    for ( *(_DWORD *)(v0 + 1612) = 0;
          *(_DWORD *)(v0 + 1612) == 0;
          *(_DWORD *)(v0 + 4 * v6 + 1576) = (-2
                                           - ((~*(_DWORD *)(v0 + 4 * v6 + 1576) | (-1371358004 * *(_DWORD *)(v0 + 1612)))
                                            + *(_DWORD *)(v0 + 4 * v6 + 1576)))
                                          & ((-1371358004 * *(_DWORD *)(v0 + 1612)) | *(_DWORD *)(v0 + 4 * v6 + 1576)) )
    {
      v6 = (int)(*(_DWORD *)(v0 + 1612))++;
    }
  }
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 256) + 8LL * *(int *)(v0 + 1232)))();
}


// ---- sub_14001BFF0 @ 0x14001bff0 ----
__int64 __fastcall sub_14001BFF0()
{
  __int64 v0; // rbp
  __int64 v1; // rsi

  *(_DWORD *)(v0 + 1152) = *(_DWORD *)(v1 + 4) != 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 96) + 8LL * *(int *)(v0 + 1152)))();
}


// ---- sub_14001C018 @ 0x14001c018 ----
__int64 __fastcall sub_14001C018(__int64 a1, char a2)
{
  __int64 v2; // rbp

  *(_DWORD *)(v2 + 1096) = a2 & 1;
  return (*(__int64 (**)(void))(*(_QWORD *)(v2 - 16) + 8LL * *(int *)(v2 + 1096)))();
}


// ---- sub_14001C034 @ 0x14001c034 ----
__int64 __fastcall sub_14001C034()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 216) + 8LL * *(int *)(v0 + 1212)))();
}


// ---- sub_14001C048 @ 0x14001c048 ----
__int64 __fastcall sub_14001C048()
{
  __int64 v0; // rbx
  __int64 v1; // rbp
  unsigned __int64 i; // rsi
  bool v3; // bl
  bool v4; // r15
  __int64 v5; // rax

  **(_DWORD **)(v1 + 840) = 0x4000;
  **(_QWORD **)(v1 + 848) = *(_QWORD *)(v1 + 1512);
  **(_QWORD **)(v1 + 856) = v0;
  **(_QWORD **)(v1 + 864) = -1;
  for ( i = 0; ; ++i )
  {
    v3 = i < qword_14003BB50;
    if ( i >= qword_14003BB50 )
      break;
    v4 = *(_DWORD *)(qword_14003BB58 + 8 * i) == -289015568;
    if ( *(_DWORD *)(qword_14003BB58 + 8 * i) == -289015568 )
      sub_14002F100(
        *(_DWORD *)(8 * i + qword_14003BB58 + 4),
        4,
        **(_QWORD **)(v1 + 864),
        **(_QWORD **)(v1 + 856),
        **(_QWORD **)(v1 + 848),
        **(int **)(v1 + 840));
    if ( v4 )
      break;
  }
  if ( !v3 )
  {
    sub_14001C660(v1 + 1560, v1 + 1568);
    for ( *(_DWORD *)(v1 + 1620) = 0;
          *(_DWORD *)(v1 + 1620) == 0;
          *(_DWORD *)(v1 + 4 * v5 + 1568) = (-2
                                           - ((~*(_DWORD *)(v1 + 4 * v5 + 1568) | (-1371358004 * *(_DWORD *)(v1 + 1620)))
                                            + *(_DWORD *)(v1 + 4 * v5 + 1568)))
                                          & ((-1371358004 * *(_DWORD *)(v1 + 1620)) | *(_DWORD *)(v1 + 4 * v5 + 1568)) )
    {
      v5 = (int)(*(_DWORD *)(v1 + 1620))++;
    }
  }
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 + 464) + 8LL * *(int *)(v1 + 1336)))();
}


// ---- sub_14001C1CD @ 0x14001c1cd ----
__int64 __fastcall sub_14001C1CD()
{
  __int64 v0; // rbp

  nullsub_1();
  *(_DWORD *)(v0 + 1184) = 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 160) + 8LL * *(int *)(v0 + 1184)))();
}


// ---- sub_14001C1F8 @ 0x14001c1f8 ----
__int64 __fastcall sub_14001C1F8()
{
  unsigned int v0; // ebx
  __int64 v1; // rbp

  return (*(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v1 + 40) + 8LL * *(int *)(v1 + 1124)))(v0);
}


// ---- sub_14001C20B @ 0x14001c20b ----
__int64 __fastcall sub_14001C20B()
{
  int v0; // eax
  __int64 v1; // rbp
  int v2; // esi

  **(_DWORD **)(v1 + 1520) = v0;
  *(_DWORD *)(v1 + 1368) = (v2 & 0x4000000) != 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 + 528) + 8LL * *(int *)(v1 + 1368)))();
}


// ---- sub_14001C23B @ 0x14001c23b ----
__int64 __fastcall sub_14001C23B()
{
  __int64 v0; // rbp
  unsigned __int16 v1; // di

  *(_DWORD *)(v0 + 1312) = *(_DWORD *)(*(_QWORD *)(v0 + 912) + 40LL * v1 + 8) != 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 416) + 8LL * *(int *)(v0 + 1312)))();
}


// ---- sub_14001C272 @ 0x14001c272 ----
__int64 __fastcall sub_14001C272()
{
  unsigned __int16 v0; // ax
  __int64 v1; // rbp
  _QWORD *v2; // rdi
  __int64 v3; // r12

  *v2 = (*(__int64 (__fastcall **)(__int64, _QWORD))(v1 + 1032))(v3, v0);
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 + 288) + 8LL * *(int *)(v1 + 1248)))();
}


// ---- sub_14001C29D @ 0x14001c29d ----
__int64 __fastcall sub_14001C29D()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 448) + 8LL * *(int *)(v0 + 1328)))();
}


// ---- sub_14001C2B1 @ 0x14001c2b1 ----
__int64 __fastcall sub_14001C2B1()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 8) + 8LL * *(int *)(v0 + 1108)))();
}


// ---- sub_14001C2C2 @ 0x14001c2c2 ----
__int64 __fastcall sub_14001C2C2(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // rbp

  return (*(__int64 (__fastcall **)(_QWORD, __int64, __int64, _QWORD))(*(_QWORD *)(v3 + 176) + 8LL * *(int *)(v3 + 1192)))(
           *(_QWORD *)(v3 + 176),
           a2,
           a3,
           *(_QWORD *)(v3 + 824));
}


// ---- sub_14001C2DD @ 0x14001c2dd ----
__int64 __fastcall sub_14001C2DD()
{
  __int64 v0; // rbp
  __int64 v1; // rdi
  __int64 v2; // rdx

  nullsub_1();
  v2 = *(unsigned int *)(v1 + 20);
  LOBYTE(v2) = (_DWORD)v2 == 0;
  *(_DWORD *)(v0 + 1092) = 1;
  return (*(__int64 (__fastcall **)(_QWORD, __int64))(*(_QWORD *)(v0 - 24) + 8LL * *(int *)(v0 + 1092)))(0, v2);
}


// ---- sub_14001C317 @ 0x14001c317 ----
__int64 __fastcall sub_14001C317()
{
  __int64 v0; // rbp
  char v1; // r15

  *(_DWORD *)(v0 + 1344) = v1 & 1;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 480) + 8LL * *(int *)(v0 + 1344)))();
}


// ---- sub_14001C33D @ 0x14001c33d ----
__int64 __fastcall sub_14001C33D()
{
  __int64 v0; // rax
  _QWORD *v1; // rbx
  __int64 v2; // rbp
  _QWORD *v3; // r15

  *v1 = *(unsigned int *)(v0 + 12) + *v3;
  *(_DWORD *)(v2 + 1332) = (*(_DWORD *)(v0 + 36) & 0x2000000) != 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v2 + 456) + 8LL * *(int *)(v2 + 1332)))();
}


// ---- sub_14001C36E @ 0x14001c36e ----
__int64 __fastcall sub_14001C36E()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 80) + 8LL * *(int *)(v0 + 1144)))();
}


// ---- sub_14001C384 @ 0x14001c384 ----
__int64 __fastcall sub_14001C384()
{
  __int64 v0; // rbp

  sub_14002E0B0(*(_QWORD *)(v0 + 1584));
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 672) + 8LL * *(int *)(v0 + 1440)))();
}


// ---- sub_14001C3F6 @ 0x14001c3f6 ----
__int64 __fastcall sub_14001C3F6()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 688) + 8LL * *(int *)(v0 + 1448)))();
}


// ---- sub_14001C40A @ 0x14001c40a ----
__int64 __fastcall sub_14001C40A()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 312) + 8LL * *(int *)(v0 + 1260)))();
}


// ---- sub_14001C42B @ 0x14001c42b ----
__int64 __fastcall sub_14001C42B(char a1)
{
  __int64 v1; // rbp

  *(_DWORD *)(v1 + 1296) = a1 & 1;
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 + 384) + 8LL * *(int *)(v1 + 1296)))();
}


// ---- sub_14001C44C @ 0x14001c44c ----
__int64 __fastcall sub_14001C44C()
{
  __int64 v0; // rbp

  nullsub_1();
  *(_DWORD *)(v0 + 1204) = 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 200) + 8LL * *(int *)(v0 + 1204)))();
}


// ---- sub_14001C477 @ 0x14001c477 ----
__int64 __fastcall sub_14001C477()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 328) + 8LL * *(int *)(v0 + 1268)))();
}


// ---- sub_14001C48D @ 0x14001c48d ----
__int64 __fastcall sub_14001C48D()
{
  __int64 v0; // rbp
  _DWORD *v1; // rsi

  *(_DWORD *)(v0 + 1224) = *v1 != 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 240) + 8LL * *(int *)(v0 + 1224)))();
}


// ---- sub_14001C4B0 @ 0x14001c4b0 ----
__int64 __fastcall sub_14001C4B0()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 264) + 8LL * *(int *)(v0 + 1236)))();
}


// ---- sub_14001C4D5 @ 0x14001c4d5 ----
__int64 __fastcall sub_14001C4D5()
{
  void (__fastcall *v0)(_QWORD, __int64, _QWORD); // rax
  __int64 v1; // rbp
  _QWORD *v2; // r15

  v0(*v2, 1, 0);
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 + 600) + 8LL * *(int *)(v1 + 1404)))();
}


// ---- sub_14001C502 @ 0x14001c502 ----
__int64 __fastcall sub_14001C502()
{
  __int64 v0; // rax
  __int64 v1; // rbp
  _QWORD *v2; // rdi
  __int64 v3; // r12
  _QWORD *v4; // r15

  *v2 = (*(__int64 (__fastcall **)(__int64, __int64))(v1 + 1032))(v3, *v4 + v0 + 2);
  return (*(__int64 (**)(void))(*(_QWORD *)(v1 + 296) + 8LL * *(int *)(v1 + 1252)))();
}


// ---- sub_14001C532 @ 0x14001c532 ----
__int64 __fastcall sub_14001C532()
{
  __int64 v0; // rbp
  unsigned __int16 v1; // si

  *(_DWORD *)(v0 + 1084) = *(_DWORD *)(*(_QWORD *)(v0 + 912) + 40LL * v1 + 16) == 0;
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 - 40) + 8LL * *(int *)(v0 + 1084)))();
}


// ---- sub_14001C566 @ 0x14001c566 ----
__int64 __fastcall sub_14001C566()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 120) + 8LL * *(int *)(v0 + 1164)))();
}


// ---- sub_14001C58A @ 0x14001c58a ----
__int64 __fastcall sub_14001C58A(int a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rbp

  *(_QWORD *)(v4 + 824) = a4;
  *(_DWORD *)(v4 + 1176) = a1 == 10;
  return (*(__int64 (**)(void))(*(_QWORD *)(v4 + 144) + 8LL * *(int *)(v4 + 1176)))();
}


// ---- sub_14001C5B3 @ 0x14001c5b3 ----
__int64 __fastcall sub_14001C5B3()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(*(_QWORD *)(v0 + 704) + 8LL * *(int *)(v0 + 1456)))();
}


// ---- sub_14001C5E6 @ 0x14001c5e6 ----
__int64 __fastcall sub_14001C5E6()
{
  __int64 v0; // rbp
  unsigned __int16 v1; // si
  __int64 v2; // r12

  *(_DWORD *)(v0 + 1076) = v1 < (unsigned int)*(unsigned __int16 *)(v2 + 2);
  return (*(__int64 (**)(void))(*(_QWORD *)(v0 - 56) + 8LL * *(int *)(v0 + 1076)))();
}


// ---- sub_14001C620 @ 0x14001c620 ----
void __fastcall sub_14001C620(_DWORD *a1)
{
  *a1 = 1283091504;
}


// ---- sub_14001C630 @ 0x14001c630 ----
void __fastcall sub_14001C630(_DWORD *a1)
{
  *a1 = 1790047584;
}


// ---- sub_14001C640 @ 0x14001c640 ----
void __fastcall sub_14001C640(_DWORD *a1)
{
  *a1 = 149494241;
}


// ---- sub_14001C650 @ 0x14001c650 ----
void __fastcall sub_14001C650(_DWORD *a1)
{
  *a1 = 656450449;
}


// ---- sub_14001C660 @ 0x14001c660 ----
_DWORD *__fastcall sub_14001C660(__int64 a1, _DWORD *a2)
{
  *a2 = 1371358003;
  return a2;
}


// ---- sub_14001C670 @ 0x14001c670 ----
__int64 __fastcall sub_14001C670(_DWORD *a1)
{
  __int64 v1; // rax
  __int64 v2; // rdx
  __m128 v3; // xmm8
  __int64 v4; // rax
  __m128i si128; // xmm5
  __m128i v6; // xmm6
  __m128 v7; // xmm7
  __m128 v8; // xmm9
  __m128i v9; // xmm8
  __m128i v10; // xmm9
  __int64 result; // rax

  v1 = 624;
  v2 = 0;
  do
  {
    a1[v1 - 623] = ((a1[v1 + 1] & 0x80000000 | a1[(v2 & 2) + 1 + (v1 ^ 1)] & 0x7FFFFFFE) >> 1)
                 ^ a1[v1 + 398]
                 ^ -(a1[(v2 & 2) + 1 + (v1 ^ 1)] & 1)
                 & 0x9908B0DF;
    ++v1;
    v2 += 2;
  }
  while ( v1 != 851 );
  v3 = (__m128)_mm_shuffle_epi32(_mm_cvtsi32_si128(a1[852]), 0);
  v4 = 0;
  si128 = _mm_load_si128((const __m128i *)&xmmword_140034390);
  v6 = _mm_load_si128((const __m128i *)&xmmword_1400343A0);
  do
  {
    v7 = *(__m128 *)&a1[v4 + 853];
    v8 = _mm_or_ps(
           _mm_and_ps(v7, (__m128)xmmword_140033AD0),
           _mm_and_ps(_mm_shuffle_ps(_mm_shuffle_ps(v3, v7, 3), v7, 152), (__m128)xmmword_1400334C0));
    v9 = _mm_srli_epi32((__m128i)v8, 1u);
    v10 = _mm_cmpeq_epi32(
            (__m128i)_mm_and_ps(_mm_or_ps(v8, (__m128)xmmword_140034380), _mm_xor_ps(v8, (__m128)xmmword_140034370)),
            (__m128i)0LL);
    *(__m128i *)&a1[v4 + 228] = _mm_xor_si128(
                                  _mm_xor_si128(_mm_xor_si128(_mm_loadu_si128((const __m128i *)&a1[v4 + 1]), v9), si128),
                                  _mm_or_si128(_mm_andnot_si128(v10, v6), _mm_and_si128(v10, si128)));
    v4 += 4;
    v3 = v7;
  }
  while ( v4 != 396 );
  result = -((a1[1248] ^ 0x7FFFFFFF) & (a1[1248] | 0x80000000) & 1 | a1[1] & 1)
         & 0x9908B0DF
         ^ a1[397]
         ^ (((a1[1248] ^ 0x7FFFFFFF) & (a1[1248] | 0x80000000) | a1[1] & 0x7FFFFFFF) >> 1);
  a1[624] = result;
  *a1 = 0;
  return result;
}


// ---- sub_14001C840 @ 0x14001c840 ----
__int64 __fastcall sub_14001C840(__int64 a1)
{
  __int64 v1; // rdi
  int v2; // eax
  int v3; // ebx
  int v4; // ebx
  __int64 v5; // rax
  __int64 v6; // rcx
  __int64 result; // rax
  unsigned int i; // [rsp+50h] [rbp-918h]
  _QWORD v9[19]; // [rsp+78h] [rbp-8F0h] BYREF
  __int64 v10; // [rsp+114h] [rbp-854h]
  int v11; // [rsp+11Ch] [rbp-84Ch]
  _QWORD v12[265]; // [rsp+120h] [rbp-848h] BYREF

  v9[18] = a1;
  v10 = 0x10000000200LL;
  v11 = 0;
  v1 = 0;
  while ( 2 )
  {
    v2 = *(_DWORD *)((char *)&v10 + v1);
    LODWORD(v12[0]) = 0;
    v3 = 895931921;
    do
    {
      ++LODWORD(v12[0]);
      v3 = (v3 + ((895800840 * LODWORD(v12[0])) ^ v3) - (v3 & ~(895800840 * LODWORD(v12[0]))))
         & ~((895800840 * LODWORD(v12[0])) & v3);
    }
    while ( LODWORD(v12[0]) == 0 );
    v4 = v2 | v3;
    sub_140001C20((__int64)v12);
    for ( i = 0; i < 0x46; *((_WORD *)v12 + v5) ^= -30029 * (_WORD)i )
      v5 = (int)i++;
    switch ( (unsigned int)sub_140031450((unsigned int)v12, (unsigned int)v9, v4, 0, 0) >> 31 )
    {
      case 0u:
        result = off_140038650();
        break;
      case 1u:
        v1 += 4;
        switch ( v1 != 12 )
        {
          case false:
            switch ( byte_14003A810 )
            {
              case 0:
                break;
              case 1:
                v6 = 0;
                break;
            }
            result = off_140038790(v6);
            break;
          case true:
            continue;
        }
        break;
    }
    break;
  }
  return result;
}


// ---- sub_14001C9A9 @ 0x14001c9a9 ----
None

// ---- sub_14001D5E0 @ 0x14001d5e0 ----
__int64 __fastcall sub_14001D5E0(__int64 a1)
{
  int v2; // eax
  __int64 v3; // r9
  int v4; // eax
  int v5; // ecx
  unsigned int v6; // edx
  __int64 v7; // rdi
  unsigned int v8; // esi
  int v9; // eax
  __int64 v10; // rdx
  int v11; // eax
  unsigned int v12; // eax
  __int64 v13; // rcx
  __int64 v14; // rdx
  __int64 v15; // r8
  _BYTE *v16; // rax
  __int64 v17; // rbx
  unsigned int *v18; // rcx
  unsigned __int16 *v19; // r11
  unsigned int v20; // r10d
  unsigned __int16 *v21; // rdx
  unsigned __int64 v22; // r8
  unsigned __int16 *v23; // r9
  _BYTE *v24; // r14
  int v25; // ebp
  int v26; // r9d
  unsigned __int64 v27; // r9
  unsigned int v28; // eax
  _BYTE v30[14]; // [rsp+38h] [rbp-40h] BYREF
  unsigned int i; // [rsp+48h] [rbp-30h]
  unsigned int v32[11]; // [rsp+4Ch] [rbp-2Ch] BYREF

  v32[0] = 0;
  *(_DWORD *)v30 = 0;
  v2 = -984081084;
  do
  {
    ++*(_DWORD *)v30;
    v2 ^= -984081087 * *(_DWORD *)v30;
  }
  while ( *(_DWORD *)v30 == 0 );
  if ( qword_14003BB50 != 0 )
  {
    v3 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v3) != -594858244 )
    {
      if ( qword_14003BB50 == ++v3 )
        goto LABEL_7;
    }
    v4 = sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v3 + 4), 4, v2, 0, 0, (__int64)v32);
  }
  else
  {
LABEL_7:
    *(_DWORD *)v30 = 0;
    v4 = 118103385;
    do
    {
      ++*(_DWORD *)v30;
      v4 ^= -118103386 * *(_DWORD *)v30;
    }
    while ( *(_DWORD *)v30 == 0 );
  }
  *(_DWORD *)v30 = 0;
  v5 = -1550870794;
  do
  {
    ++*(_DWORD *)v30;
    v6 = (*(_DWORD *)v30 & 0x638F96F2 ^ 0x638F96F2) * (*(_DWORD *)v30 & 0x9C70690D)
       + (*(_DWORD *)v30 & 0x638F96F2) * (*(_DWORD *)v30 | 0x638F96F2);
    v5 = (v5 | v6) & (-2 - (v5 + (v6 | ~v5)));
  }
  while ( *(_DWORD *)v30 == 0 );
  if ( v4 == v5 )
  {
    v32[0] += 0x10000;
    v7 = sub_14002E070(v32[0]);
    *(_DWORD *)v30 = 0;
    v9 = 29823142;
    do
    {
      ++*(_DWORD *)v30;
      v9 ^= 29823139 * *(_DWORD *)v30;
    }
    while ( *(_DWORD *)v30 == 0 );
    if ( qword_14003BB50 != 0 )
    {
      v10 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v10) != -594858244 )
      {
        if ( qword_14003BB50 == ++v10 )
          goto LABEL_21;
      }
      if ( (int)sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v10 + 4), 4, v9, v7, v32[0], 0) < 0 )
        goto LABEL_56;
    }
    else
    {
LABEL_21:
      *(_DWORD *)v30 = 0;
      v11 = 118103385;
      do
      {
        ++*(_DWORD *)v30;
        v11 ^= -118103386 * *(_DWORD *)v30;
      }
      while ( *(_DWORD *)v30 == 0 );
      if ( v11 < 0 )
      {
LABEL_56:
        v8 = 0;
LABEL_59:
        sub_14002E0B0(v7);
        return v8;
      }
    }
    v12 = *(_DWORD *)v7;
    v13 = 2048;
    if ( *(_DWORD *)v7 != 0 )
    {
      v14 = v7;
      do
      {
        v15 = v12;
        v12 = *(_DWORD *)(v14 + v12);
        v14 += v15;
        v13 += 2048;
      }
      while ( v12 != 0 );
    }
    v16 = (_BYTE *)sub_14002E070(v13);
    v17 = (__int64)v16;
    v18 = (unsigned int *)v7;
    v19 = *(unsigned __int16 **)(v7 + 64);
    if ( v19 == nullptr )
    {
LABEL_48:
      while ( *v18 != 0 )
      {
        v18 = (unsigned int *)((char *)v18 + *v18);
        v19 = *((unsigned __int16 **)v18 + 8);
        if ( v19 != nullptr )
          goto LABEL_28;
      }
      v27 = (unsigned __int64)&v16[-v17];
      if ( v16 == (_BYTE *)v17 )
      {
        v8 = 0;
      }
      else
      {
        *v16 = 0;
        *(_QWORD *)&v30[6] = 0x701C182C7E3B254BLL;
        *(_QWORD *)v30 = 0x254B434D43776258LL;
        for ( i = 0; i < 0xE; v30[v28] ^= (i & 8 ^ 8) * (i & 0xF7) + (i & 8) * (i | 8) )
          v28 = i++;
        v8 = sub_140003370(a1, (__int64)v30, v17, v27);
      }
      sub_140001C10(v17);
      goto LABEL_59;
    }
LABEL_28:
    v20 = *v19;
    if ( (_WORD)v20 == 0 )
    {
LABEL_47:
      *v16++ = 10;
      goto LABEL_48;
    }
    v21 = (unsigned __int16 *)((char *)v19 + ((_WORD)v18[14] & 0xFFFE));
    v22 = 2047;
    while ( 1 )
    {
      if ( v19 >= v21 || v22 == 0 )
        goto LABEL_47;
      v23 = v19 + 1;
      if ( (unsigned __int16)v20 > 0x7Fu )
      {
        if ( (unsigned __int16)v20 > 0x7FFu || v22 < 2 )
        {
          v25 = v20 & 0xFC00;
          if ( v25 == 55296 && v22 >= 4 )
          {
            v26 = v19[1];
            *v16 = ((unsigned int)(((unsigned __int16)v20 << 10) + v26 - 56613888) >> 18) | 0xF0;
            v16[1] = ((unsigned int)(((unsigned __int16)v20 << 10) + v26 - 56613888) >> 12) & 0x3F | 0x80;
            v16[2] = ((((unsigned int)(((unsigned __int16)v20 << 10) + v26 - 56613888) >> 6)
                     ^ 0xC0)
                    & (((unsigned int)(((unsigned __int16)v20 << 10) + v26 - 56613888) >> 6) | 0x3F))
                   + 0x80;
            v24 = v16 + 4;
            v16[3] = v26 & 0x3F | 0x80;
            v23 = v19 + 2;
          }
          else
          {
            if ( (unsigned __int16)v25 == 56320 )
              goto LABEL_41;
            if ( v22 < 3 )
            {
              v24 = v16;
            }
            else
            {
              *v16 = ((unsigned __int16)v20 >> 12) | 0xE0;
              v16[1] = ((unsigned __int16)v20 >> 6) & 0x3F | 0x80;
              v24 = v16 + 3;
              v16[2] = v20 & 0x3F | 0x80;
            }
          }
        }
        else
        {
          *v16 = (v20 >> 6) | 0xC0;
          v24 = v16 + 2;
          v16[1] = v20 & 0x3F | 0x80;
        }
      }
      else
      {
        v24 = v16 + 1;
        *v16 = v20;
      }
      v22 = &v16[v22] - v24;
      v16 = v24;
LABEL_41:
      v20 = *v23;
      v19 = v23;
      if ( (_WORD)v20 == 0 )
        goto LABEL_47;
    }
  }
  return 0;
}


// ---- sub_14001DB00 @ 0x14001db00 ----
char __fastcall sub_14001DB00(
        int a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        __int64 a8,
        int a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        int a29,
        void *a30,
        int a31,
        __int64 a32,
        int a33,
        __int64 a34)
{
  __int64 v35; // rdx
  int v36; // r8d
  __int128 *v37; // r9

  if ( (unsigned __int8)sub_14001E1C0() != 0 )
    return 1;
  else
    return sub_14001EAB0(
             a1,
             v35,
             v36,
             v37,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             a14,
             a15,
             a16,
             a17,
             a18,
             a19,
             a20,
             a21,
             a22,
             a23,
             a24,
             a25,
             a26,
             a27,
             a28,
             a29,
             a30,
             a31,
             a32,
             a33,
             a34);
}


// ---- sub_14001DB30 @ 0x14001db30 ----
__int64 __fastcall sub_14001DB30(__int64 a1)
{
  __int64 v2; // rax
  int v3; // eax
  int v4; // ecx
  __int64 v5; // r14
  __int64 v6; // rcx
  __int64 v7; // rsi
  unsigned int v8; // r14d
  int v9; // r9d
  unsigned int v10; // r15d
  char *v11; // rbx
  char v12; // al
  __int64 v13; // rdx
  signed int v15; // eax
  char v16; // r8
  _QWORD *v17; // r12
  __int64 v18; // r14
  __int64 v19; // r12
  __int64 v21; // r12
  __int64 v22; // r13
  __int64 v23; // r15
  __int64 v24; // rax
  __int64 (__fastcall *v25)(_QWORD *, _QWORD, __int64); // rax
  __int64 v26; // rcx
  unsigned int (__fastcall *v27)(unsigned int *, _QWORD, _QWORD, _QWORD); // rax
  unsigned __int64 v28; // r9
  HLOCAL v29; // r8
  signed int v30; // eax
  __int64 v31; // [rsp+20h] [rbp-138h]
  __int64 v32; // [rsp+20h] [rbp-138h]
  __int64 v33; // [rsp+28h] [rbp-130h]
  unsigned int i; // [rsp+3Ch] [rbp-11Ch]
  unsigned int j; // [rsp+3Ch] [rbp-11Ch]
  _QWORD v36[2]; // [rsp+40h] [rbp-118h] BYREF
  __int128 v37; // [rsp+50h] [rbp-108h]
  unsigned int v38; // [rsp+64h] [rbp-F4h] BYREF
  unsigned int v39; // [rsp+68h] [rbp-F0h] BYREF
  __int64 v40; // [rsp+70h] [rbp-E8h]
  __int64 v41; // [rsp+78h] [rbp-E0h] BYREF
  unsigned int v42; // [rsp+80h] [rbp-D8h]
  HLOCAL hMem; // [rsp+88h] [rbp-D0h]
  _QWORD *v44; // [rsp+90h] [rbp-C8h] BYREF
  __int64 v45; // [rsp+98h] [rbp-C0h] BYREF
  __int64 v46; // [rsp+A0h] [rbp-B8h] BYREF
  unsigned __int64 v47[22]; // [rsp+A8h] [rbp-B0h] BYREF

  qmemcpy(&v47[11], byte_14003454C, 26);
  qmemcpy(&v47[1], byte_1400344FC, 80);
  LODWORD(v36[0]) = 0;
  do
  {
    v2 = SLODWORD(v36[0]);
    ++LODWORD(v36[0]);
    *((_WORD *)&v47[1] + v2) = (*((_WORD *)&v47[1] + v2) | (-32655 * LOWORD(v36[0])))
                             & ((*((_WORD *)&v47[1] + v2) & (-32655 * LOWORD(v36[0])))
                              + ~(2 * (*((_WORD *)&v47[1] + v2) & (-32655 * LOWORD(v36[0])))));
  }
  while ( LODWORD(v36[0]) < 0x35 );
  v3 = sub_140031280(0, (unsigned int)&v47[1], 52, 0, 0, (__int64)&v46);
  LODWORD(v36[0]) = 0;
  v4 = -1670546021;
  do
  {
    ++LODWORD(v36[0]);
    v4 ^= (v36[0] & 0x5C6D7DB8 ^ 0x5C6D7DB8) * (v36[0] & 0xA3928247)
        + (v36[0] & 0x5C6D7DB8) * (LODWORD(v36[0]) | 0x1C6D7DB8);
  }
  while ( LODWORD(v36[0]) == 0 );
  if ( v3 == v4 )
  {
    v5 = v46;
    v6 = -1;
    if ( v46 >= 0 )
      v6 = 2 * v46;
    v7 = sub_14002E070(v6);
    v31 = v5;
    v8 = 0;
    if ( (int)sub_140031280(0, (unsigned int)&v47[1], 52, v7, v31, (__int64)&v46) >= 0 )
    {
      if ( (int)sub_140031DB0(v7, (unsigned int)&v41, 1179785, 3, 1, 96, 128) < 0 )
      {
        v8 = 0;
      }
      else
      {
        v8 = 0;
        if ( (int)sub_140032460(v41, &v38, 0) >= 0 )
        {
          v10 = v38;
          v11 = (char *)sub_14002E070(v38 + 1);
          v8 = 0;
          if ( (int)sub_140032540(v41, v11, v10, 0) >= 0 )
          {
            LODWORD(v36[0]) = 0;
            v12 = 57;
            do
            {
              LODWORD(v36[0]) = (LODWORD(v36[0]) ^ 1) + 2 * (v36[0] & 1);
              v12 ^= 57 * LOBYTE(v36[0]);
            }
            while ( LODWORD(v36[0]) == 0 );
            v11[v38] = v12;
            v45 = 0x7FFF800000000000LL;
            v44 = nullptr;
            if ( (unsigned int)sub_140001040(v11, v47, &v45, &v44) != 0 )
              goto LABEL_15;
            v36[0] = 0xD46DC953A3398B31uLL;
            LODWORD(v36[1]) = 1485242467;
            v39 = 0;
            do
            {
              v15 = v39++;
              v16 = (v39 & 0x72 ^ 0x72) * (v39 & 0x8D) + (v39 & 0x72) * (v39 | 0x72);
              *((_BYTE *)v36 + v15) = (*((_BYTE *)v36 + v15) | v16)
                                    & ((*((_BYTE *)v36 + v15) & v16) + ~(2 * (*((_BYTE *)v36 + v15) & v16)));
            }
            while ( v39 < 0xC );
            v17 = (_QWORD *)(v45 & 0x7FFFFFFFFFFFLL);
            if ( (v45 & 0x7FFFFFFFFFFFLL) == 0 )
            {
LABEL_15:
              v8 = 0;
            }
            else
            {
              while ( (unsigned int)sub_1400020A0(v17[2], (__int64)v36) != 0 )
              {
                v17 = (_QWORD *)v17[1];
                if ( v17 == nullptr )
                  goto LABEL_15;
              }
              v18 = *v17 & 0x7FFFFFFFFFFFLL;
              v19 = 0;
              while ( *(_BYTE *)(v18 + v19++) != 0 )
                ;
              v21 = v19 - 1;
              v22 = sub_14001E160(v18, v21);
              v23 = sub_14002E070(v22 + 1);
              sub_14000E4A0(v18, v21, v23);
              v39 = v22;
              v40 = v23;
              v42 = 0;
              hMem = nullptr;
              v24 = sub_14002F7D0(2765091293LL);
              if ( v24 != 0 )
                goto LABEL_42;
              v25 = (__int64 (__fastcall *)(_QWORD *, _QWORD, __int64))sub_14002FDC0(qword_14003BA40, 2716158103LL);
              *(_OWORD *)v36 = xmmword_140034572;
              *(_QWORD *)&v37 = 0x2B64D21D791220EFLL;
              for ( i = 0;
                    i < 0xC;
                    *((_WORD *)v36 + v26) = (*((_WORD *)v36 + v26) | (22771 * i))
                                          & ((*((_WORD *)v36 + v26) & (22771 * i))
                                           + ~(2 * (*((_WORD *)v36 + v26) & (22771 * i)))) )
              {
                v26 = (int)i++;
              }
              v8 = 0;
              v24 = v25(v36, 0, 2048);
              if ( v24 != 0 )
              {
LABEL_42:
                v27 = (unsigned int (__fastcall *)(unsigned int *, _QWORD, _QWORD, _QWORD))sub_14002FDC0(v24, 189392399);
                LODWORD(v33) = 1;
                v32 = 0;
                v8 = 0;
                if ( v27(&v39, 0, 0, 0) != 0 )
                {
                  v28 = v42;
                  v29 = hMem;
                  v37 = xmmword_14003459A;
                  *(_OWORD *)v36 = xmmword_14003458A;
                  for ( j = 0; j < 0x20; *((_BYTE *)v36 + v30) ^= 106 * (_BYTE)j )
                    v30 = j++;
                  v8 = sub_140003370(a1, (__int64)v36, (__int64)v29, v28);
                  LocalFree(hMem);
                }
              }
              sub_140001C10(v23);
            }
            sub_140001000(&v44);
          }
          sub_140001C10(v11);
        }
        if ( qword_14003BB50 != 0 )
        {
          v13 = 0;
          while ( *(_DWORD *)(qword_14003BB58 + 8 * v13) != -1825720177 )
          {
            if ( qword_14003BB50 == ++v13 )
              goto LABEL_22;
          }
          sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v13 + 4), 1, v41, v9, v32, v33);
        }
        else
        {
LABEL_22:
          LODWORD(v36[0]) = 0;
          do
            ++LODWORD(v36[0]);
          while ( LODWORD(v36[0]) == 0 );
        }
      }
    }
    sub_140001C10(v7);
  }
  else
  {
    return 0;
  }
  return v8;
}


// ---- sub_14001E160 @ 0x14001e160 ----
unsigned __int64 __fastcall sub_14001E160(__int64 a1, __int64 a2)
{
  unsigned __int64 result; // rax

  result = (unsigned __int64)(3 * a2) >> 2;
  if ( *(_BYTE *)(a1 + a2 - 1) == 61 )
  {
    if ( *(_BYTE *)(a1 + a2 - 2) == 61 )
    {
      if ( *(_BYTE *)(a1 + a2 - 3) == 61 )
        result -= 3LL;
      else
        return 2 * (result & 0xFFFFFFFFFFFFFFFDuLL) - (result ^ 2);
    }
    else
    {
      return ((2 * result) & 0x7FFFFFFFFFFFFFFCLL) - (result ^ 1);
    }
  }
  return result;
}


// ---- sub_14001E1C0 @ 0x14001e1c0 ----
__int64 sub_14001E1C0()
{
  signed int v0; // eax
  unsigned int i; // [rsp+40h] [rbp-4B8h]
  __int64 v3; // [rsp+90h] [rbp-468h] BYREF
  _QWORD v4[2]; // [rsp+B0h] [rbp-448h] BYREF
  __int128 v5; // [rsp+C0h] [rbp-438h]

  *(_OWORD *)v4 = xmmword_1400345AA;
  LODWORD(v5) = 1795088430;
  for ( i = 0; i < 0xA; *((_WORD *)v4 + v0) ^= (i & 0x8AB3 ^ 0x8AB3) * (i & 0x754C) + (i & 0x8AB3) * (i | 0x8AB3) )
    v0 = i++;
  sub_140030290(v4, &v3);
  return off_140038E00();
}


// ---- sub_14001E49B @ 0x14001e49b ----
// attributes: thunk
__int64 __fastcall sub_14001E49B(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        __int64 a19,
        __int64 a20)
{
  return sub_14001EA87(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20);
}


// ---- sub_14001E8C2 @ 0x14001e8c2 ----
__int64 sub_14001E8C2()
{
  return off_140038EE8();
}


// ---- sub_14001E910 @ 0x14001e910 ----
__int64 __fastcall sub_14001E910()
{
  __int64 (*v0)(void); // rax

  return v0();
}


// ---- sub_14001EA87 @ 0x14001ea87 ----
void __fastcall sub_14001EA87(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        __int64 a19,
        __int64 a20)
{
  if ( a19 != 0 && a19 != a20 )
    sub_140001C10(a19);
  JUMPOUT(0x14001E904LL);
}


// ---- sub_14001EAB0 @ 0x14001eab0 ----
__int64 __fastcall sub_14001EAB0(__int64 a1, __int64 a2, __int64 a3, __int128 *a4)
{
  int v4; // eax
  __int64 v5; // rax
  __int64 v6; // rdi
  __int64 v7; // rcx
  __int64 v8; // rbx
  __int64 v9; // rax
  __int16 v10; // dx
  __int64 v11; // rax
  __int16 v12; // cx
  __int64 v13; // rcx
  __int16 v14; // r8
  _QWORD v16[2]; // [rsp+40h] [rbp-148h] BYREF
  unsigned __int64 v17; // [rsp+50h] [rbp-138h]
  unsigned int i; // [rsp+60h] [rbp-128h]
  _QWORD v19[2]; // [rsp+A0h] [rbp-E8h] BYREF
  __m256i v20; // [rsp+B0h] [rbp-D8h]
  _WORD v21[20]; // [rsp+D0h] [rbp-B8h]
  _QWORD v22[9]; // [rsp+140h] [rbp-48h] BYREF

  *(_OWORD *)v16 = xmmword_140034608;
  v17 = 0xB94CE9B31A1E4A98uLL;
  LODWORD(v19[0]) = 0;
  do
  {
    v4 = LODWORD(v19[0])++;
    *((_WORD *)v16 + v4) ^= (v19[0] & 0x308E) * (v19[0] & 0xCF71 ^ 0xCF71)
                          + (v19[0] & 0xCF71) * (LOWORD(v19[0]) | 0xCF71);
  }
  while ( LODWORD(v19[0]) < 0xC );
  qmemcpy(v21, byte_140034650, 30);
  v20 = (__m256i)ymmword_140034630;
  *(_OWORD *)v19 = xmmword_140034620;
  for ( i = 0; i < 0x27; *((_WORD *)v19 + v5) ^= 6484 * (_WORD)i )
    v5 = (int)i++;
  v6 = sub_14002D260(v19, v16, v22, 0);
  switch ( v6 == 0 )
  {
    case false:
      v7 = -1;
      if ( (v22[0] >> 1) + 18LL >= 0 )
        v7 = 2LL * (v22[0] >> 1) + 36;
      v8 = sub_14002E070(v7);
      *(_OWORD *)v20.m256i_i8 = xmmword_14003467E;
      *(_OWORD *)v19 = xmmword_14003466E;
      *(__int64 *)((char *)&v20.m256i_i64[1] + 6) = 0xE9FC640EDEB05936uLL;
      LODWORD(v16[0]) = 0;
      do
      {
        v9 = SLODWORD(v16[0]);
        ++LODWORD(v16[0]);
        v10 = *((_WORD *)v19 + v9);
        *((_WORD *)v19 + v9) = (v10
                              + (v10
                               ^ ((v16[0] & 0x8594 ^ 0x8594) * (v16[0] & 0x7A6B)
                                + (v16[0] & 0x8594) * (LOWORD(v16[0]) | 0x8594)))
                              - (v10
                               & ~((v16[0] & 0x8594 ^ 0x8594) * (v16[0] & 0x7A6B)
                                 + (v16[0] & 0x8594) * (LOWORD(v16[0]) | 0x8594))))
                             & ~(v10
                               & ((v16[0] & 0x8594 ^ 0x8594) * (v16[0] & 0x7A6B)
                                + (v16[0] & 0x8594) * (LOWORD(v16[0]) | 0x8594)));
      }
      while ( LODWORD(v16[0]) < 0x13 );
      v11 = 0;
      do
      {
        v12 = *(_WORD *)(v6 + v11);
        *(_WORD *)(v8 + v11) = v12;
        v11 += 2;
      }
      while ( v12 != 0 );
      v13 = 0;
      do
      {
        v14 = *(_WORD *)((char *)v19 + v13);
        *(_WORD *)(v11 + v8 + v13 - 2) = v14;
        v13 += 2;
      }
      while ( v14 != 0 );
      return off_140038FA0(v13);
    case true:
      JUMPOUT(0x1400200E0LL);
  }
}


// ---- sub_14001EEF3 @ 0x14001eef3 ----
None

// ---- sub_14001EF86 @ 0x14001ef86 ----
None

// ---- sub_14001F030 @ 0x14001f030 ----
__int64 __fastcall sub_14001F030()
{
  __int64 (*v0)(void); // rax

  return v0();
}


// ---- sub_14001F032 @ 0x14001f032 ----
None

// ---- sub_140020026 @ 0x140020026 ----
// positive sp value has been detected, the output may be wrong!
__int64 sub_140020026()
{
  return ((__int64 (*)(void))off_140039418)();
}


// ---- sub_140020132 @ 0x140020132 ----
void __fastcall sub_140020132()
{
  __int64 v0; // r14

  sub_140001C10(v0);
  JUMPOUT(0x14002013ALL);
}


// ---- sub_140020150 @ 0x140020150 ----
char __fastcall sub_140020150(unsigned int a1)
{
  return (a1 < 0x21) & (0x100003E00uLL >> a1);
}


// ---- sub_140020170 @ 0x140020170 ----
__int64 __fastcall sub_140020170(char *a1, _QWORD *a2, int a3, int *a4)
{
  int *v4; // rsi
  char *i; // rbx
  int v7; // eax
  bool v8; // r15
  _BYTE *v9; // rdi
  __int64 v10; // rax
  unsigned __int64 v11; // r14
  unsigned __int64 v12; // rdx
  char v13; // r13
  unsigned __int64 v14; // r15
  char v15; // bl
  char v16; // r12
  int v17; // eax
  int v18; // eax
  unsigned __int64 v19; // r15
  _BYTE *v20; // rcx
  __int64 v21; // rsi
  __int64 result; // rax
  bool v23; // [rsp+23h] [rbp-65h]
  int v24; // [rsp+24h] [rbp-64h] BYREF
  unsigned __int64 v25; // [rsp+28h] [rbp-60h]
  __int64 v26; // [rsp+30h] [rbp-58h]
  _BYTE *v27; // [rsp+38h] [rbp-50h]
  _QWORD *v28; // [rsp+40h] [rbp-48h]

  v4 = a4;
  v28 = a2;
  v24 = 0;
  if ( a4 == nullptr )
    v4 = &v24;
  v27 = a1;
  for ( i = a1; (sub_140020150(*i) & 1) != 0; ++i )
    ;
  v7 = *i;
  if ( v7 == 43 || (v8 = true, v7 == 45) )
    v8 = *i++ == 43;
  if ( a3 <= 0 )
  {
    if ( *i == 48 )
    {
      v9 = i + 1;
      if ( (i[1] | 0x20) == 0x78 )
      {
        v9 = i + 2;
        a3 = 16;
      }
      else
      {
        a3 = 8;
      }
    }
    else
    {
      a3 = 10;
      v9 = i;
    }
  }
  else if ( a3 == 16 )
  {
    a3 = 16;
    if ( *i == 48 )
    {
      a3 = 16;
      if ( (i[1] | 0x20) == 0x78 )
      {
        i += 2;
        a3 = 16;
      }
      v9 = i;
    }
    else
    {
      v9 = i;
    }
  }
  else
  {
    v9 = i;
  }
  v10 = sub_1400203E0();
  v11 = -1;
  v23 = v8;
  if ( v8 )
    v11 = v10;
  v26 = (unsigned int)a3;
  v12 = v11 % (unsigned int)a3;
  v25 = v11 / (unsigned int)a3;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  do
  {
    v16 = sub_1400203D0((unsigned int)(char)*v9, v12);
    if ( (v16 & 1) == 0 )
    {
      v15 = sub_1400203F0((unsigned int)(char)*v9) & 1;
      if ( v15 == 0 )
        break;
    }
    if ( (v16 & 1) != 0 )
    {
      v17 = (char)*v9 - 48;
    }
    else
    {
      v17 = 0;
      if ( (v15 & 1) != 0 )
        v17 = ~(*v9 & 0x20) + (char)*v9 + 33 - 97 + 10;
    }
    if ( v17 < a3 )
    {
      ++v9;
      if ( v14 == v11 )
      {
        *v4 = 34;
        v13 = 1;
        v18 = 5;
      }
      else
      {
        if ( v14 > v25 )
        {
          *v4 = 34;
          v19 = v11;
        }
        else
        {
          v19 = v26 * v14;
        }
        v12 = v11 - v17;
        if ( v19 > v12 )
        {
          *v4 = 34;
          v14 = v11;
        }
        else
        {
          v14 = v17 + v19;
        }
        v13 = 1;
        v18 = 0;
      }
    }
    else
    {
      v18 = 4;
    }
  }
  while ( v18 == 0 || v18 == 5 );
  if ( v28 != nullptr )
  {
    v20 = v27;
    if ( (v13 & 1) != 0 )
      v20 = v9;
    *v28 = v20;
  }
  if ( *v4 == 34 )
  {
    v21 = sub_1400203E0();
    sub_1400094F0();
    return v21;
  }
  else
  {
    result = -(__int64)v14;
    if ( v23 )
      return v14;
  }
  return result;
}


// ---- sub_1400203D0 @ 0x1400203d0 ----
bool __fastcall sub_1400203D0(int a1)
{
  return (unsigned int)(a1 - 48) < 0xA;
}


// ---- sub_1400203E0 @ 0x1400203e0 ----
__int64 sub_1400203E0()
{
  return -1;
}


// ---- sub_1400203F0 @ 0x1400203f0 ----
bool __fastcall sub_1400203F0(int a1)
{
  return (a1 & 0xFFFFFFDF) - 65 < 0x1A;
}


// ---- GetClientRect @ 0x140020400 ----
// attributes: thunk
BOOL __stdcall GetClientRect(HWND hWnd, LPRECT lpRect)
{
  return __imp_GetClientRect(hWnd, lpRect);
}


// ---- GetWindowRect @ 0x140020410 ----
// attributes: thunk
BOOL __stdcall GetWindowRect(HWND hWnd, LPRECT lpRect)
{
  return __imp_GetWindowRect(hWnd, lpRect);
}


// ---- GetWindowDC @ 0x140020420 ----
// attributes: thunk
HDC __stdcall GetWindowDC(HWND hWnd)
{
  return __imp_GetWindowDC(hWnd);
}


// ---- GetKeyboardLayoutNameW @ 0x140020430 ----
// attributes: thunk
BOOL __stdcall GetKeyboardLayoutNameW(LPWSTR pwszKLID)
{
  return __imp_GetKeyboardLayoutNameW(pwszKLID);
}


// ---- GetKeyboardLayout @ 0x140020440 ----
// attributes: thunk
HKL __stdcall GetKeyboardLayout(DWORD idThread)
{
  return __imp_GetKeyboardLayout(idThread);
}


// ---- sub_140020450 @ 0x140020450 ----
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall sub_140020450(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 nSize,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43,
        __int64 a44,
        __int64 a45,
        __int64 a46,
        __int64 a47,
        __int64 a48,
        __int64 a49,
        __int64 a50,
        __int64 a51,
        __int64 a52,
        __int64 a53,
        __int64 a54,
        __int64 a55,
        __int64 a56,
        __int64 a57,
        __int64 a58,
        __int64 a59,
        __int64 a60,
        __int64 a61,
        __int64 a62,
        __int64 a63,
        unsigned int Buffer)
{
  void *v64; // rsp
  __int64 v65; // rdx
  __int64 v66; // rsi
  __int64 v67; // rcx
  __int64 v68; // r14
  int v69; // eax
  signed int v70; // eax
  __int64 v71; // rax
  char v72; // cl
  __int64 v73; // rdi
  unsigned __int64 *v74; // rax
  __int64 v75; // rbx
  char v76; // cl
  __int64 v77; // rax
  _BYTE *v78; // rdi
  int v79; // eax
  __int64 v80; // rcx
  unsigned __int64 *v81; // rcx
  char v82; // dl
  unsigned __int16 *v83; // r9
  unsigned int v84; // r8d
  _BYTE *v85; // rdx
  unsigned __int16 *v86; // rax
  unsigned __int16 v87; // r10
  unsigned __int16 *v88; // rdx
  unsigned __int16 *v89; // r10
  _BYTE *v90; // r11
  int v91; // r11d
  int v92; // esi
  int v93; // r8d
  int v94; // eax
  signed int v95; // ecx
  unsigned __int64 *v96; // rcx
  char v97; // dl
  __int64 v98; // rsi
  char v99; // cl
  __int64 v100; // rax
  __int64 v101; // r12
  char v102; // cl
  unsigned __int64 *v103; // r14
  __int64 v104; // rdx
  __int64 v105; // rcx
  __int64 v106; // r8
  __int64 v107; // r9
  int v109; // eax
  int v110; // eax
  __int64 v111; // rbx
  _BYTE *v112; // rdi
  char v113; // al
  unsigned int (__fastcall *v114)(unsigned __int64 *, __int64); // rax
  unsigned __int64 *v115; // r14
  unsigned int v116; // r8d
  _BYTE *v117; // rax
  unsigned __int64 v118; // rcx
  unsigned __int64 *v119; // rdx
  _BYTE *v120; // r9
  int v121; // r10d
  int v122; // edx
  int v123; // eax
  _BYTE *v124; // rdi
  unsigned __int64 *v125; // rax
  char v126; // cl
  char *v127; // r15
  unsigned __int64 *v128; // r14
  char *v129; // rax
  char v130; // cl
  _BYTE *v131; // rbx
  char v132; // al
  int v133; // eax
  _BYTE *v134; // rbx
  char v135; // al
  char *v136; // r14
  BOOL UserNameA; // eax
  __int64 v138; // rdx
  __int64 v139; // r8
  __int64 v140; // r9
  __int64 v141; // rcx
  unsigned __int8 *v142; // rax
  _BYTE *v143; // rsi
  char v144; // al

  v64 = alloca(sub_140001B30(a1, a2, a3, a4));
  v66 = v65;
  a63 = v67;
  *(_OWORD *)&a14 = xmmword_140034730;
  v68 = sub_14002E070(0x2000);
  *(_OWORD *)&STACK[0x1668] = xmmword_14003474B;
  STACK[0x1676] = 0xFAD9A4C1FFF75079uLL;
  LODWORD(a30) = 0;
  do
  {
    v69 = a30;
    LODWORD(a30) = a30 + 1;
    *((_BYTE *)&STACK[0x1668] + v69) ^= (a30 & 0xE8) * (a30 & 0x17 ^ 0x17) + (a30 & 0x17) * (a30 | 0x17);
  }
  while ( (unsigned int)a30 < 0x16 );
  *(_OWORD *)&a30 = xmmword_140034761;
  for ( Buffer = 0; Buffer < 0x10; *((_BYTE *)&a30 + v70) ^= 88 * (_BYTE)Buffer )
    v70 = Buffer++;
  a28 = v66;
  v71 = 0;
  do
  {
    v72 = *((_BYTE *)&a30 + v71);
    *(_BYTE *)(v68 + v71++) = v72;
  }
  while ( v72 != 0 );
  strcpy((char *)(v68 + v71 - 1), "04.10.2026");
  v73 = v68 + v71 + 7;
  v74 = &STACK[0x1668];
  v75 = v73;
  do
  {
    v76 = *(_BYTE *)v74;
    v74 = (unsigned __int64 *)((char *)v74 + 1);
    *(_BYTE *)(v73 + 2) = v76;
    ++v75;
    ++v73;
  }
  while ( v76 != 0 );
  v77 = sub_14002FCD0(0);
  switch ( v77 != 0 )
  {
    case false:
      v78 = (_BYTE *)(v73 + 1);
      switch ( (unsigned __int8)sub_14002C3B0(v77 != 0) )
      {
        case 0u:
          goto LABEL_48;
        case 1u:
          goto LABEL_11;
      }
    case true:
      STACK[0x1668] = 0xA010C0B04ADD9E70uLL;
      LOBYTE(STACK[0x1670]) = -48;
      LODWORD(a30) = 0;
      do
      {
        v80 = (int)a30;
        LODWORD(a30) = (a30 ^ 1) + 2 * (a30 & 1);
        *((_BYTE *)&STACK[0x1668] + v80) ^= 80 * (_BYTE)a30;
      }
      while ( (unsigned int)a30 < 9 );
      v81 = &STACK[0x1668];
      do
      {
        v82 = *(_BYTE *)v81;
        v81 = (unsigned __int64 *)((char *)v81 + 1);
        *(_BYTE *)++v73 = v82;
        ++v75;
      }
      while ( v82 != 0 );
      v83 = *(unsigned __int16 **)(v77 + 8);
      v84 = *v83;
      v85 = (_BYTE *)v73;
      if ( (_WORD)v84 == 0 )
        goto LABEL_47;
      v86 = (unsigned __int16 *)((char *)v83 + (*(_WORD *)v77 & 0xFFFE));
      v81 = nullptr;
      v87 = *v83;
      v88 = v83;
      do
      {
        if ( v88 >= v86 )
          break;
        if ( v87 <= 0x7Fu )
        {
          v81 = (unsigned __int64 *)((char *)v81 + 1);
        }
        else if ( v87 > 0x7FFu )
        {
          if ( v87 != 0xFFFF )
            v81 = (unsigned __int64 *)((char *)v81 + 3);
        }
        else
        {
          v81 = (unsigned __int64 *)((char *)v81 + 2);
        }
        v87 = *++v88;
      }
      while ( *v88 != 0 );
      v85 = (_BYTE *)v73;
      break;
  }
  while ( v83 < v86 && v81 != nullptr )
  {
    v89 = v83 + 1;
    if ( (unsigned __int16)v84 > 0x7Fu )
    {
      v91 = (unsigned __int16)v84;
      if ( (unsigned __int16)v84 > 0x7FFu || (unsigned __int64)v81 < 2 )
      {
        v92 = v84 & 0xFC00;
        if ( v92 == 55296 && (unsigned __int64)v81 >= 4 )
        {
          v93 = v83[1];
          *v85 = ((unsigned int)((v91 << 10) + v93 - 56613888) >> 18) | 0xF0;
          v85[1] = ((unsigned int)((v91 << 10) + v93 - 56613888) >> 12) & 0x3F | 0x80;
          v85[2] = ((unsigned int)((v91 << 10) + v93 - 56613888) >> 6) & 0x3F | 0x80;
          v90 = v85 + 4;
          v85[3] = v93 & 0x3F | 0x80;
          v89 = v83 + 2;
        }
        else
        {
          if ( (unsigned __int16)v92 == 56320 )
            goto LABEL_41;
          if ( (unsigned __int64)v81 < 3 )
          {
            v90 = v85;
          }
          else
          {
            *v85 = ((unsigned __int16)v84 >> 12) | 0xE0;
            v85[1] = ((unsigned __int16)v84 >> 6) & 0x3F | 0x80;
            v85[2] = v84 & 0x3F | 0x80;
            v90 = v85 + 3;
          }
        }
      }
      else
      {
        *v85 = (v84 >> 6) | 0xC0;
        v90 = v85 + 2;
        v85[1] = v84 & 0x3F | 0x80;
      }
    }
    else
    {
      v90 = v85 + 1;
      *v85 = v84;
    }
    v81 = (unsigned __int64 *)((char *)v81 + (_QWORD)v85 - v90);
    v85 = v90;
LABEL_41:
    v84 = *v89;
    v83 = v89;
    if ( (_WORD)v84 == 0 )
      break;
  }
LABEL_47:
  *v85 = 0;
  v78 = &v85[v73 - v75];
  switch ( (unsigned __int8)sub_14002C3B0(v81) )
  {
    case 0u:
LABEL_48:
      WORD2(a30) = 4714;
      LODWORD(a30) = 2137352037;
      LODWORD(STACK[0x1668]) = 0;
      if ( LODWORD(STACK[0x1668]) <= 5 )
      {
        do
        {
          v94 = LODWORD(STACK[0x1668])++;
          *((_BYTE *)&a30 + v94) ^= (STACK[0x1668] & 3 ^ 3) * (STACK[0x1668] & 0xFC)
                                  + (STACK[0x1668] & 3) * (LOBYTE(STACK[0x1668]) | 3);
        }
        while ( LODWORD(STACK[0x1668]) < 6 );
      }
      break;
    case 1u:
LABEL_11:
      BYTE4(a30) = 104;
      LODWORD(a30) = 1169023548;
      LODWORD(STACK[0x1668]) = 0;
      if ( LODWORD(STACK[0x1668]) <= 4 )
      {
        do
        {
          v79 = LODWORD(STACK[0x1668])++;
          *((_BYTE *)&a30 + v79) ^= (STACK[0x1668] & 0xB7) * (STACK[0x1668] & 0x48 ^ 0x48)
                                  + (STACK[0x1668] & 0x48) * (LOBYTE(STACK[0x1668]) | 0x48);
        }
        while ( LODWORD(STACK[0x1668]) < 5 );
      }
      break;
  }
  STACK[0x166E] = 0xD2E38EC1F3F3191FuLL;
  STACK[0x1668] = 0x191F3F27590D3E05LL;
  for ( Buffer = 0;
        Buffer < 0xE;
        *((_BYTE *)&STACK[0x1668] + v95) ^= (Buffer & 0xF ^ 0xF) * (Buffer & 0xF0) + (Buffer & 0xF) * (Buffer | 0xF) )
  {
    v95 = Buffer++;
  }
  v96 = &STACK[0x1668];
  do
  {
    v97 = *(_BYTE *)v96;
    v96 = (unsigned __int64 *)((char *)v96 + 1);
    *v78++ = v97;
  }
  while ( v97 != 0 );
  v98 = 0;
  do
  {
    v99 = *((_BYTE *)&a30 + v98);
    v78[v98++ - 1] = v99;
  }
  while ( v99 != 0 );
  a29 = v68;
  *(_OWORD *)&STACK[0x1694] = *(__int128 *)((char *)&xmmword_1400347B3 + 12);
  *(_OWORD *)&STACK[0x1688] = xmmword_1400347B3;
  *(_OWORD *)&STACK[0x1678] = xmmword_1400347A3;
  *(_OWORD *)&STACK[0x1668] = xmmword_140034793;
  LODWORD(a30) = 0;
  do
  {
    v100 = (int)a30;
    LODWORD(a30) = a30 + 1;
    *((_BYTE *)&STACK[0x1668] + v100) = (*((_BYTE *)&STACK[0x1668] + v100)
                                       + (*((_BYTE *)&STACK[0x1668] + v100) ^ ((_BYTE)a30 << 6))
                                       - (*((_BYTE *)&STACK[0x1668] + v100) & ~((_BYTE)a30 << 6)))
                                      & ~(*((_BYTE *)&STACK[0x1668] + v100) & ((_BYTE)a30 << 6));
  }
  while ( (unsigned int)a30 < 0x3C );
  v101 = 0;
  do
  {
    v102 = *((_BYTE *)&STACK[0x1668] + v101);
    v78[v101++ - 2 + v98] = v102;
  }
  while ( v102 != 0 );
  a22 = 0;
  v103 = &STACK[0x1668];
  switch ( (unsigned __int8)sub_140024A10(&STACK[0x1668], &a22) )
  {
    case 0u:
      if ( STACK[0x1678] != 0 )
        sub_140001C10(STACK[0x1678]);
      BYTE4(a12) = -47;
      LODWORD(a12) = 410767155;
      LODWORD(STACK[0x1668]) = 0;
      if ( LODWORD(STACK[0x1668]) <= 4 )
      {
        do
        {
          v109 = LODWORD(STACK[0x1668])++;
          *((_BYTE *)&a12 + v109) ^= 93 * LOBYTE(STACK[0x1668]);
        }
        while ( LODWORD(STACK[0x1668]) < 5 );
      }
      STACK[0x166E] = 0x884C6A517F9D95A3uLL;
      STACK[0x1668] = 0x95A3C6ED1C741816uLL;
      LODWORD(a30) = 0;
      do
      {
        v110 = a30;
        LODWORD(a30) = a30 + 1;
        *((_BYTE *)&STACK[0x1668] + v110) ^= (a30 & 0xE3) * (a30 & 0x1C ^ 0x1C) + (a30 & 0x1C) * (a30 | 0x1C);
      }
      while ( (unsigned int)a30 < 0xE );
      v111 = (__int64)&v78[v98 - 4 + v101];
      v112 = (_BYTE *)v111;
      do
      {
        v113 = *(_BYTE *)v103;
        v103 = (unsigned __int64 *)((char *)v103 + 1);
        *++v112 = v113;
        ++v111;
      }
      while ( v113 != 0 );
      break;
    case 1u:
      return off_140039DE8(
               v105,
               v104,
               v106,
               v107,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               a13,
               a14,
               a15,
               a16,
               a17,
               a18,
               a19,
               a20,
               a21,
               a22,
               a23,
               a24,
               nSize,
               a26,
               a27,
               a28,
               a29,
               a30,
               a31,
               a32,
               a33,
               a34,
               a35,
               a36,
               a37,
               a38,
               a39,
               a40,
               a41,
               a42,
               a43,
               a44,
               a45,
               a46,
               a47,
               a48,
               a49,
               a50,
               a51,
               a52,
               a53,
               a54,
               a55,
               a56,
               a57,
               a58,
               a59);
  }
  v114 = (unsigned int (__fastcall *)(unsigned __int64 *, __int64))sub_14002FDC0(qword_14003BA40, 1114851402);
  switch ( v114 != nullptr )
  {
    case false:
      goto LABEL_91;
    case true:
      v115 = &STACK[0x1668];
      switch ( v114(&STACK[0x1668], 85) != 0 )
      {
        case false:
          goto LABEL_91;
        case true:
          v116 = LOWORD(STACK[0x1668]);
          v117 = v112;
          if ( (_WORD)v116 != 0 )
          {
            v118 = 84;
            v117 = v112;
            do
            {
              if ( v118 == 0 )
                break;
              v119 = (unsigned __int64 *)((char *)v115 + 2);
              if ( (unsigned __int16)v116 > 0x7Fu )
              {
                if ( (unsigned __int16)v116 > 0x7FFu || v118 == 1 )
                {
                  v121 = v116 & 0xFC00;
                  if ( v121 == 55296 && v118 >= 4 )
                  {
                    v122 = *((unsigned __int16 *)v115 + 1);
                    *v117 = ((unsigned int)(((unsigned __int16)v116 << 10) + v122 - 56613888) >> 18) | 0xF0;
                    v117[1] = ((unsigned int)(((unsigned __int16)v116 << 10) + v122 - 56613888) >> 12) & 0x3F | 0x80;
                    v117[2] = ((unsigned int)(((unsigned __int16)v116 << 10) + v122 - 56613888) >> 6) & 0x3F | 0x80;
                    v120 = v117 + 4;
                    v117[3] = v122 & 0x3F | 0x80;
                    v119 = (unsigned __int64 *)((char *)v115 + 4);
                  }
                  else
                  {
                    if ( (unsigned __int16)v121 == 56320 )
                      goto LABEL_84;
                    if ( v118 < 3 )
                    {
                      v120 = v117;
                    }
                    else
                    {
                      *v117 = ((unsigned __int16)v116 >> 12) | 0xE0;
                      v117[1] = ((unsigned __int16)v116 >> 6) & 0x3F | 0x80;
                      v117[2] = v116 & 0x3F | 0x80;
                      v120 = v117 + 3;
                    }
                  }
                }
                else
                {
                  *v117 = (v116 >> 6) | 0xC0;
                  v120 = v117 + 2;
                  v117[1] = v116 & 0x3F | 0x80;
                }
              }
              else
              {
                v120 = v117 + 1;
                *v117 = v116;
              }
              v118 = &v117[v118] - v120;
              v117 = v120;
LABEL_84:
              v116 = *(unsigned __int16 *)v119;
              v115 = v119;
            }
            while ( (_WORD)v116 != 0 );
          }
          *v117 = 0;
          v112 = &v117[(_QWORD)v112 - v111];
LABEL_91:
          *(__m128i *)&STACK[0x1668] = _mm_loadu_si128(xmmword_140034938);
          LODWORD(STACK[0x1677]) = 1339727669;
          LODWORD(a30) = 0;
          do
          {
            v123 = a30;
            LODWORD(a30) = a30 + 1;
            *((_BYTE *)&STACK[0x1668] + v123) ^= 85 * (_BYTE)a30;
          }
          while ( (unsigned int)a30 < 0x13 );
          v124 = v112 - 1;
          v125 = &STACK[0x1668];
          do
          {
            v126 = *(_BYTE *)v125;
            v125 = (unsigned __int64 *)((char *)v125 + 1);
            *++v124 = v126;
          }
          while ( v126 != 0 );
          LODWORD(STACK[0x1668]) = 16;
          v127 = (char *)&a26;
          v128 = &STACK[0x1668];
          switch ( GetComputerNameA((LPSTR)&a26, (LPDWORD)&STACK[0x1668]) )
          {
            case false:
              v129 = (char *)&a12;
              do
              {
                v130 = *v129++;
                *v124 = v130;
                v131 = v124++;
              }
              while ( v130 != 0 );
              break;
            case true:
              do
              {
                v132 = *v127++;
                *v124 = v132;
                v131 = v124++;
              }
              while ( v132 != 0 );
              break;
          }
          STACK[0x166F] = 0x2C383E95B1A9DA8DLL;
          STACK[0x1668] = 0x8DFE1D17251C081EuLL;
          LODWORD(a30) = 0;
          do
          {
            v133 = a30;
            LODWORD(a30) = a30 + 1;
            *((_BYTE *)&STACK[0x1668] + v133) ^= 20 * (_BYTE)a30;
          }
          while ( (unsigned int)a30 < 0xF );
          v134 = v131 - 1;
          do
          {
            v135 = *(_BYTE *)v128;
            v128 = (unsigned __int64 *)((char *)v128 + 1);
            *++v134 = v135;
          }
          while ( v135 != 0 );
          HIDWORD(nSize) = 257;
          v136 = (char *)&a30;
          UserNameA = GetUserNameA((LPSTR)&a30, (LPDWORD)&nSize + 1);
          v141 = UserNameA;
          switch ( UserNameA )
          {
            case false:
              v142 = (unsigned __int8 *)&a12;
              do
              {
                v141 = *v142++;
                *v134++ = v141;
              }
              while ( (_BYTE)v141 != 0 );
              break;
            case true:
              do
              {
                v143 = v134;
                v144 = *v136++;
                ++v134;
                *v143 = v144;
              }
              while ( v144 != 0 );
              break;
          }
          return off_140039E90(
                   v141,
                   v138,
                   v139,
                   v140,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   a13,
                   a14,
                   a15,
                   a16,
                   a17,
                   a18,
                   a19,
                   a20,
                   a21,
                   a22,
                   a23,
                   a24,
                   nSize,
                   a26,
                   a27,
                   a28,
                   a29,
                   a30,
                   a31,
                   a32,
                   a33,
                   a34,
                   a35,
                   a36,
                   a37,
                   a38,
                   a39,
                   a40,
                   a41,
                   a42,
                   a43,
                   a44,
                   a45,
                   a46,
                   a47,
                   a48,
                   a49,
                   a50,
                   a51,
                   a52,
                   a53,
                   a54,
                   a55,
                   a56,
                   a57,
                   a58,
                   a59);
      }
  }
}


// ---- sub_140020BAC @ 0x140020bac ----
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_140020BAC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        unsigned __int64 a38)
{
  __int64 v38; // rbx
  unsigned __int64 v39; // rax
  signed int v40; // ecx
  unsigned __int64 *v41; // rdx
  __int64 v42; // rcx
  char v43; // r8
  _BYTE *v44; // rsi
  __int64 v45; // rdx
  char v46; // r8
  char *v47; // rax
  char v48; // cl
  char *v49; // rax
  char v50; // cl
  char *v51; // rax
  char v52; // cl
  unsigned int i; // [rsp+40h] [rbp+40h]

  v39 = STACK[0x350];
  *(unsigned __int64 *)((char *)&a38 + 5) = 0x258C09D42EA13CA4LL;
  a38 = 0xA13CA438924BD273uLL;
  for ( i = 0; i < 0xD; *((_BYTE *)&a38 + v40) ^= (i & 0x86) * (i & 0x79 ^ 0x79) + (i & 0x79) * (i | 0x79) )
    v40 = i++;
  v41 = &a38;
  v42 = v38;
  do
  {
    v43 = *(_BYTE *)v41;
    v41 = (unsigned __int64 *)((char *)v41 + 1);
    *(_BYTE *)(v42 - 3) = v43;
    ++v42;
  }
  while ( v43 != 0 );
  v44 = (_BYTE *)(v42 - 3);
  v45 = -5;
  do
  {
    v46 = *(_BYTE *)(v39 + v45 + 5);
    *(_BYTE *)(v42 + v45++ + 1) = v46;
    ++v44;
  }
  while ( v46 != 0 );
  *(_WORD *)(v42 + v45) = 10272;
  v47 = (char *)sub_140006830(STACK[0x340], (__int64)&STACK[0x240], 11, 0xAu);
  do
  {
    v48 = *v47++;
    *v44++ = v48;
  }
  while ( v48 != 0 );
  *(v44 - 1) = 46;
  v49 = (char *)sub_140006830(STACK[0x344], (__int64)&STACK[0x240], 11, 0xAu);
  do
  {
    v50 = *v49++;
    *v44++ = v50;
  }
  while ( v50 != 0 );
  *(v44 - 1) = 46;
  v51 = (char *)sub_140006830(STACK[0x348], (__int64)&STACK[0x240], 11, 0xAu);
  do
  {
    v52 = *v51++;
    *v44++ = v52;
  }
  while ( v52 != 0 );
  *(_WORD *)(v44 - 1) = 8233;
  sub_1400302C0();
  JUMPOUT(0x140020D40LL);
}


// ---- sub_1400211A4 @ 0x1400211a4 ----
// attributes: thunk
__int64 sub_1400211A4()
{
  return off_140039FB8();
}


// ---- sub_1400211B0 @ 0x1400211b0 ----
// attributes: thunk
__int64 sub_1400211B0()
{
  return off_140039FB8();
}


// ---- sub_1400211B6 @ 0x1400211b6 ----
None

// ---- sub_140022A66 @ 0x140022a66 ----
// local variable allocation has failed, the output may be wrong!
void sub_140022A66(__int64 a1, __int64 a2, __int64 a3, __int128 *a4, int a5, int a6, int a7, ...)
{
  __int64 v7; // rbx
  __int64 v8; // rsi
  __int64 v9; // r13
  __int64 v10; // rax
  signed int v11; // ecx
  __int64 v12; // rcx
  va_list v13; // rdx
  char v14; // r8
  __int64 v15; // rcx
  char v16; // dl
  unsigned int i; // [rsp+34h] [rbp+34h]
  __int64 v18; // [rsp+40h] [rbp+40h] OVERLAPPED BYREF
  va_list va; // [rsp+40h] [rbp+40h]
  __int64 v20; // [rsp+48h] [rbp+48h] OVERLAPPED
  __int64 v21; // [rsp+50h] [rbp+50h]
  __int64 v22; // [rsp+58h] [rbp+58h]
  __int64 v23; // [rsp+60h] [rbp+60h]
  __int64 v24; // [rsp+68h] [rbp+68h]
  __int64 v25; // [rsp+70h] [rbp+70h]
  __int64 v26; // [rsp+78h] [rbp+78h]
  va_list va1; // [rsp+80h] [rbp+80h] BYREF

  va_start(va1, a7);
  va_start(va, a7);
  v18 = va_arg(va1, _QWORD);
  v20 = va_arg(va1, _QWORD);
  v21 = va_arg(va1, _QWORD);
  v22 = va_arg(va1, _QWORD);
  v23 = va_arg(va1, _QWORD);
  v24 = va_arg(va1, _QWORD);
  v25 = va_arg(va1, _QWORD);
  v26 = va_arg(va1, _QWORD);
  v10 = sub_140028CE0(*(unsigned __int16 *)(v9 + 48), va1, 6, 10);
  *(__m128i *)&v18 = _mm_loadu_si128(xmmword_140034B04);
  *(__int64 *)((char *)&v20 + 6) = 0xA44E0266A9FA024BuLL;
  for ( i = 0; i < 0x16; va[v11] ^= 54 * (_BYTE)i )
    v11 = i++;
  v12 = v8;
  va_copy(v13, va);
  do
  {
    v14 = *v13++;
    *(_BYTE *)++v12 = v14;
    ++v7;
  }
  while ( v14 != 0 );
  v15 = 0;
  do
  {
    v16 = *(_BYTE *)(v10 + v15);
    *(_BYTE *)(v7 + v15++ - 10) = v16;
  }
  while ( v16 != 0 );
  JUMPOUT(0x140022B20LL);
}


// ---- sub_14002341B @ 0x14002341b ----
void __fastcall sub_14002341B(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        unsigned __int8 *a36)
{
  __int64 v36; // rsi
  unsigned __int8 *v37; // rdi
  int v38; // eax
  int v39; // eax
  unsigned __int8 v40; // al
  int v41; // [rsp+40h] [rbp+40h]
  int v42; // [rsp+40h] [rbp+40h]
  int v43; // [rsp+40h] [rbp+40h]

  v36 = 0;
  v37 = a36;
  while ( 1 )
  {
    v41 = 0;
    v38 = -438881248;
    do
    {
      ++v41;
      v38 ^= 1304659206 * v41;
    }
    while ( v41 == 0 );
    *(int *)((char *)&a22 + v36) = (*(int *)((char *)&a22 + v36) & ~v38) * (v38 & ~*(int *)((char *)&a22 + v36))
                                 + (v38 & *(int *)((char *)&a22 + v36)) * (v38 | *(int *)((char *)&a22 + v36));
    v42 = 0;
    v39 = 787225282;
    do
    {
      ++v42;
      v39 ^= -335872329 * v42;
    }
    while ( v42 == 0 );
    *(int *)((char *)&a22 + v36) += v39;
    v43 = 0;
    v40 = 58;
    do
      v40 ^= 10 * (_BYTE)++v43;
    while ( v43 == 0 );
    sub_140001B90(v37, v40, 8u);
    sub_140006830(*(int *)((char *)&a22 + v36), (__int64)v37, 9, 0x10u);
    v37 += 8;
    v36 += 4;
    switch ( v36 != 16 )
    {
      case false:
        JUMPOUT(0x140023568LL);
      case true:
        continue;
    }
  }
}


// ---- sub_140023DD6 @ 0x140023dd6 ----
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_140023DD6(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int16 a40)
{
  _BYTE *v40; // rdi
  char *v41; // rax
  _BYTE *v42; // rcx
  char v43; // dl
  unsigned __int64 *v44; // rax
  signed int v45; // edx
  char *v46; // rdx
  char v47; // r8
  _BYTE *v48; // rdx
  char v49; // r8
  signed int v50; // eax
  char v51; // r8
  char v52; // r9
  __int64 v53; // rax
  char v54; // dl
  __int64 v55; // rdx
  char v56; // r9
  unsigned int i; // [rsp+40h] [rbp+40h]
  unsigned int v58; // [rsp+40h] [rbp+40h]

  v41 = (char *)sub_140027790(LOWORD(STACK[0x36C]), &STACK[0x240], 11, 10);
  v42 = v40;
  do
  {
    v43 = *v41++;
    *v42++ = v43;
  }
  while ( v43 != 0 );
  v44 = &STACK[0x358];
  *(_OWORD *)&a38 = xmmword_140034903;
  for ( i = 0; i < 0x10; *((_BYTE *)&a38 + v45) ^= 105 * (_BYTE)i )
    v45 = i++;
  v46 = (char *)&a38;
  do
  {
    v47 = *v46++;
    *(v42++ - 1) = v47;
  }
  while ( v47 != 0 );
  v48 = v42 - 2;
  do
  {
    v49 = *(_BYTE *)v44;
    v44 = (unsigned __int64 *)((char *)v44 + 1);
    *v48++ = v49;
    ++v42;
  }
  while ( v49 != 0 );
  *(_OWORD *)&a38 = xmmword_140034913;
  a40 = -30652;
  v58 = 0;
  do
  {
    v50 = v58++;
    v51 = *((_BYTE *)&a38 + v50);
    v52 = (v58 & 0x24 ^ 0x24) * (v58 & 0xDB) + (v58 & 0x24) * (v58 | 0x24);
    *((_BYTE *)&a38 + v50) = (v51 + (v51 ^ v52) - (v51 & ~v52)) & ((v51 & v52) + ~(2 * (v51 & v52)));
  }
  while ( v58 < 0x12 );
  v53 = 0;
  do
  {
    v54 = *((_BYTE *)&a38 + v53);
    v42[v53++ - 3] = v54;
  }
  while ( v54 != 0 );
  v55 = 0;
  do
  {
    v56 = *((_BYTE *)&STACK[0x36E] + v55);
    v42[v55++ - 4 + v53] = v56;
  }
  while ( v56 != 0 );
  JUMPOUT(0x140023C38LL);
}


// ---- sub_140024589 @ 0x140024589 ----
None

// ---- sub_140024A10 @ 0x140024a10 ----
void __fastcall sub_140024A10(__int64 a1, __int64 a2)
{
  _DWORD *v4; // rax
  int v5; // esi
  __int64 v6; // rsi
  __int64 v7; // rsi
  HRESULT v8; // eax
  __int64 v9; // rdx
  __int64 v10; // r8
  __int64 v11; // r9
  void *v12; // rsp
  __int64 v13; // rdx
  __int64 v14; // rcx
  __int64 v15; // r8
  __int64 v16; // r9
  void *v17; // rsp
  __int64 v18; // rdx
  __int64 v19; // rcx
  __int64 v20; // r8
  __int64 v21; // r9
  void *v22; // rsp
  __int64 v23; // rdx
  __int64 v24; // rcx
  __int64 v25; // r8
  __int64 v26; // r9
  void *v27; // rsp
  __int64 v28; // rdx
  __int64 v29; // rcx
  __int64 v30; // r8
  __int64 v31; // r9
  void *v32; // rsp
  __int64 v33; // rdx
  __int64 v34; // rcx
  __int64 v35; // r8
  __int64 v36; // r9
  void *v37; // rsp
  __int64 v38; // rdx
  __int64 v39; // rcx
  __int64 v40; // r8
  __int64 v41; // r9
  void *v42; // rsp
  __int64 v43; // rdx
  __int64 v44; // rcx
  __int64 v45; // r8
  __int64 v46; // r9
  void *v47; // rsp
  __int64 v48; // rdx
  __int64 v49; // rcx
  __int64 v50; // r8
  __int64 v51; // r9
  void *v52; // rsp
  __int64 v53; // rcx
  __int64 v54; // r8
  __int64 v55; // r9
  void *v56; // rsp
  __int64 v57; // rdx
  __int64 v58; // rcx
  __int64 v59; // r8
  __int64 v60; // r9
  void *v61; // rsp
  __int64 v62; // rcx
  __int64 v63; // r8
  __int64 v64; // r9
  void *v65; // rsp
  __int64 v66; // rdx
  __int64 v67; // rcx
  __int64 v68; // r8
  __int64 v69; // r9
  void *v70; // rsp
  __int64 v71; // rdx
  __int64 v72; // rcx
  __int64 v73; // r9
  void *v74; // rsp
  __int64 v75; // rdx
  __int64 v76; // rcx
  __int64 v77; // r8
  __int64 v78; // r9
  void *v79; // rsp
  __int64 v80; // rdx
  __int64 v81; // rcx
  __int64 v82; // r9
  void *v83; // rsp
  __int64 v84; // rdx
  __int64 v85; // rcx
  __int64 v86; // r8
  __int64 v87; // r9
  void *v88; // rsp
  __int64 v89; // rdx
  __int64 v90; // rcx
  __int64 v91; // r8
  __int64 v92; // r9
  void *v93; // rsp
  __int64 v94; // rdx
  __int64 v95; // rcx
  __int64 v96; // r8
  __int64 v97; // r9
  void *v98; // rsp
  __int64 v99; // rdx
  __int64 v100; // rcx
  __int64 v101; // r8
  __int64 v102; // r9
  void *v103; // rsp
  __int64 v104; // rdx
  __int64 v105; // rcx
  __int64 v106; // r8
  __int64 v107; // r9
  void *v108; // rsp
  __int64 v109; // rdx
  __int64 v110; // rcx
  __int64 v111; // r9
  void *v112; // rsp
  __int64 v113; // rdx
  __int64 v114; // rcx
  __int64 v115; // r8
  __int64 v116; // r9
  void *v117; // rsp
  __int64 v118; // rdx
  __int64 v119; // rcx
  __int64 v120; // r8
  __int64 v121; // r9
  void *v122; // rsp
  __int64 v123; // rdx
  __int64 v124; // rcx
  __int64 v125; // r8
  __int64 v126; // r9
  void *v127; // rsp
  __int64 v128; // rdx
  __int64 v129; // rcx
  __int64 v130; // r9
  void *v131; // rsp
  __int64 v132; // rdx
  __int64 v133; // rcx
  __int64 v134; // r8
  __int64 v135; // r9
  void *v136; // rsp
  __int64 v137; // rdx
  __int64 v138; // rcx
  __int64 v139; // r9
  void *v140; // rsp
  __int64 v141; // rdx
  __int64 v142; // rcx
  __int64 v143; // r8
  __int64 v144; // r9
  void *v145; // rsp
  __int64 v146; // rdx
  __int64 v147; // rcx
  __int64 v148; // r9
  void *v149; // rsp
  __int64 v150; // rdx
  __int64 v151; // rcx
  __int64 v152; // r8
  __int64 v153; // r9
  void *v154; // rsp
  __int64 v155; // rdx
  __int64 v156; // rcx
  __int64 v157; // r9
  void *v158; // rsp
  __int64 v159; // rdx
  __int64 v160; // rcx
  __int64 v161; // r8
  __int64 v162; // r9
  void *v163; // rsp
  __int64 v164; // rdx
  __int64 v165; // rcx
  __int64 v166; // r8
  __int64 v167; // r9
  void *v168; // rsp
  __int64 v169; // rdx
  __int64 v170; // rcx
  __int64 v171; // r8
  __int64 v172; // r9
  void *v173; // rsp
  __int64 v174; // rdx
  __int64 v175; // rcx
  __int64 v176; // r9
  void *v177; // rsp
  __int64 v178; // rdx
  __int64 v179; // rcx
  __int64 v180; // r8
  __int64 v181; // r9
  void *v182; // rsp
  __int64 v183; // rdx
  __int64 v184; // rcx
  __int64 v185; // r9
  void *v186; // rsp
  __int64 v187; // rdx
  __int64 v188; // rcx
  __int64 v189; // r8
  __int64 v190; // r9
  void *v191; // rsp
  __int64 v192; // rdx
  __int64 v193; // rcx
  __int64 v194; // r8
  __int64 v195; // r9
  void *v196; // rsp
  __int64 v197; // rdx
  __int64 v198; // rcx
  __int64 v199; // r8
  __int64 v200; // r9
  void *v201; // rsp
  __int64 v202; // rdx
  __int64 v203; // rcx
  __int64 v204; // r8
  __int64 v205; // r9
  void *v206; // rsp
  __int64 v207; // rdx
  __int64 v208; // rcx
  __int64 v209; // r8
  __int64 v210; // r9
  void *v211; // rsp
  __int64 v212; // rdx
  __int64 v213; // rcx
  __int64 v214; // r8
  __int64 v215; // r9
  void *v216; // rsp
  __int64 v217; // rdx
  __int64 v218; // rcx
  __int64 v219; // r8
  __int64 v220; // r9
  void *v221; // rsp
  __int64 v222; // rdx
  __int64 v223; // rcx
  __int64 v224; // r9
  void *v225; // rsp
  __int64 v226; // rdx
  __int64 v227; // rcx
  __int64 v228; // r8
  __int64 v229; // r9
  void *v230; // rsp
  __int64 v231; // rdx
  __int64 v232; // rcx
  __int64 v233; // r9
  void *v234; // rsp
  __int64 v235; // rdx
  __int64 v236; // rcx
  __int64 v237; // r8
  __int64 v238; // r9
  void *v239; // rsp
  __int64 v240; // rdx
  __int64 v241; // rcx
  __int64 v242; // r9
  void *v243; // rsp
  __int64 v244; // rdx
  __int64 v245; // rcx
  __int64 v246; // r8
  __int64 v247; // r9
  void *v248; // rsp
  __int64 v249; // rdx
  __int64 v250; // rcx
  __int64 v251; // r9
  void *v252; // rsp
  __int64 v253; // rdx
  __int64 v254; // rcx
  __int64 v255; // r8
  __int64 v256; // r9
  void *v257; // rsp
  __int64 v258; // rdx
  __int64 v259; // rcx
  __int64 v260; // r9
  void *v261; // rsp
  __int64 v262; // rdx
  __int64 v263; // rcx
  __int64 v264; // r8
  __int64 v265; // r9
  void *v266; // rsp
  __int64 v267; // rdx
  __int64 v268; // rcx
  __int64 v269; // r8
  __int64 v270; // r9
  void *v271; // rsp
  __int64 v272; // rdx
  __int64 v273; // rcx
  __int64 v274; // r8
  __int64 v275; // r9
  void *v276; // rsp
  __int64 v277; // rdx
  __int64 v278; // rcx
  __int64 v279; // r9
  void *v280; // rsp
  __int64 v281; // rdx
  __int64 v282; // rcx
  __int64 v283; // r8
  void *v284; // rsp
  __int64 v285; // rdx
  __int64 v286; // rcx
  __int64 v287; // r8
  __int64 v288; // r9
  void *v289; // rsp
  __int64 v290; // rdx
  __int64 v291; // rcx
  __int64 v292; // r8
  __int64 v293; // r9
  void *v294; // rsp
  __int64 v295; // rdx
  __int64 v296; // rcx
  __int64 v297; // r8
  __int64 v298; // r9
  void *v299; // rsp
  __int64 v300; // rdx
  __int64 v301; // rcx
  __int64 v302; // r8
  __int64 v303; // r9
  void *v304; // rsp
  __int64 v305; // rdx
  __int64 v306; // rcx
  __int64 v307; // r8
  __int64 v308; // r9
  void *v309; // rsp
  __int64 v310; // rdx
  __int64 v311; // rcx
  __int64 v312; // r8
  __int64 v313; // r9
  void *v314; // rsp
  __int64 v315; // rdx
  __int64 v316; // rcx
  __int64 v317; // r8
  __int64 v318; // r9
  void *v319; // rsp
  __int64 v320; // rdx
  __int64 v321; // rcx
  __int64 v322; // r8
  __int64 v323; // r9
  void *v324; // rsp
  __int64 v325; // rdx
  __int64 v326; // rcx
  __int64 v327; // r8
  __int64 v328; // r9
  void *v329; // rsp
  __int64 v330; // rdx
  __int64 v331; // rcx
  __int64 v332; // r8
  __int64 v333; // r9
  void *v334; // rsp
  __int64 v335; // rdx
  __int64 v336; // rcx
  __int64 v337; // r8
  __int64 v338; // r9
  void *v339; // rsp
  __int64 v340; // rdx
  __int64 v341; // rcx
  __int64 v342; // r8
  __int64 v343; // r9
  void *v344; // rsp
  __int64 v345; // rdx
  __int64 v346; // rcx
  __int64 v347; // r8
  __int64 v348; // r9
  void *v349; // rsp
  __int64 v350; // rdx
  __int64 v351; // rcx
  __int64 v352; // r8
  __int64 v353; // r9
  void *v354; // rsp
  __int64 v355; // rdx
  __int64 v356; // rcx
  __int64 v357; // r8
  __int64 v358; // r9
  void *v359; // rsp
  __int64 v360; // rdx
  __int64 v361; // rcx
  __int64 v362; // r8
  __int64 v363; // r9
  void *v364; // rsp
  __int64 v365; // rdx
  __int64 v366; // rcx
  __int64 v367; // r8
  __int64 v368; // r9
  void *v369; // rsp
  __int64 v370; // rdx
  __int64 v371; // rcx
  __int64 v372; // r8
  __int64 v373; // r9
  void *v374; // rsp
  __int64 v375; // rdx
  __int64 v376; // rcx
  __int64 v377; // r8
  __int64 v378; // r9
  void *v379; // rsp
  __int64 v380; // rdx
  __int64 v381; // rcx
  __int64 v382; // r8
  __int64 v383; // r9
  void *v384; // rsp
  __int64 v385; // rdx
  __int64 v386; // rcx
  __int64 v387; // r8
  __int64 v388; // r9
  void *v389; // rsp
  __int64 v390; // rdx
  __int64 v391; // rcx
  __int64 v392; // r8
  __int64 v393; // r9
  void *v394; // rsp
  __int64 v395; // rdx
  __int64 v396; // rcx
  __int64 v397; // r8
  __int64 v398; // r9
  void *v399; // rsp
  __int64 v400; // rdx
  __int64 v401; // rcx
  __int64 v402; // r8
  __int64 v403; // r9
  void *v404; // rsp
  __int64 v405; // rdx
  __int64 v406; // rcx
  __int64 v407; // r8
  __int64 v408; // r9
  void *v409; // rsp
  __int64 v410; // rdx
  __int64 v411; // rcx
  __int64 v412; // r8
  __int64 v413; // r9
  void *v414; // rsp
  __int64 v415; // rdx
  __int64 v416; // rcx
  __int64 v417; // r8
  __int64 v418; // r9
  void *v419; // rsp
  __int64 v420; // rdx
  __int64 v421; // rcx
  __int64 v422; // r8
  __int64 v423; // r9
  void *v424; // rsp
  __int64 v425; // rdx
  __int64 v426; // rcx
  __int64 v427; // r8
  __int64 v428; // r9
  void *v429; // rsp
  __int64 v430; // rdx
  __int64 v431; // rcx
  __int64 v432; // r8
  __int64 v433; // r9
  void *v434; // rsp
  __int64 v435; // rdx
  __int64 v436; // rcx
  __int64 v437; // r8
  __int64 v438; // r9
  void *v439; // rsp
  __int64 v440; // rdx
  __int64 v441; // rcx
  __int64 v442; // r8
  __int64 v443; // r9
  void *v444; // rsp
  __int64 v445; // rdx
  __int64 v446; // rcx
  __int64 v447; // r8
  __int64 v448; // r9
  void *v449; // rsp
  __int64 v450; // rdx
  __int64 v451; // rcx
  __int64 v452; // r8
  __int64 v453; // r9
  void *v454; // rsp
  __int64 v455; // rdx
  __int64 v456; // rcx
  __int64 v457; // r8
  __int64 v458; // r9
  void *v459; // rsp
  __int64 v460; // rdx
  __int64 v461; // rcx
  __int64 v462; // r8
  __int64 v463; // r9
  void *v464; // rsp
  __int64 v465; // rdx
  __int64 v466; // rcx
  __int64 v467; // r8
  __int64 v468; // r9
  void *v469; // rsp
  __int64 v470; // rdx
  __int64 v471; // rcx
  __int64 v472; // r8
  __int64 v473; // r9
  void *v474; // rsp
  __int64 v475; // rdx
  __int64 v476; // rcx
  __int64 v477; // r8
  __int64 v478; // r9
  void *v479; // rsp
  __int64 v480; // rdx
  __int64 v481; // rcx
  __int64 v482; // r8
  __int64 v483; // r9
  void *v484; // rsp
  __int64 v485; // rdx
  __int64 v486; // rcx
  __int64 v487; // r8
  __int64 v488; // r9
  void *v489; // rsp
  __int64 v490; // rdx
  __int64 v491; // rcx
  __int64 v492; // r8
  __int64 v493; // r9
  void *v494; // rsp
  __int64 v495; // rdx
  __int64 v496; // rcx
  __int64 v497; // r8
  __int64 v498; // r9
  void *v499; // rsp
  __int64 v500; // rdx
  __int64 v501; // rcx
  __int64 v502; // r8
  __int64 v503; // r9
  void *v504; // rsp
  __int64 v505; // rdx
  __int64 v506; // rcx
  __int64 v507; // r8
  __int64 v508; // r9
  void *v509; // rsp
  __int64 v510; // rdx
  __int64 v511; // rcx
  __int64 v512; // r8
  __int64 v513; // r9
  void *v514; // rsp
  __int64 v515; // rdx
  __int64 v516; // rcx
  __int64 v517; // r8
  __int64 v518; // r9
  void *v519; // rsp
  __int64 v520; // rdx
  __int64 v521; // rcx
  __int64 v522; // r8
  __int64 v523; // r9
  void *v524; // rsp
  __int64 v525; // rdx
  __int64 v526; // rcx
  __int64 v527; // r8
  __int64 v528; // r9
  void *v529; // rsp
  __int64 v530; // rdx
  __int64 v531; // rcx
  __int64 v532; // r8
  __int64 v533; // r9
  void *v534; // rsp
  __int64 v535; // rdx
  __int64 v536; // rcx
  __int64 v537; // r8
  __int64 v538; // r9
  void *v539; // rsp
  __int64 v540; // rdx
  __int64 v541; // rcx
  __int64 v542; // r8
  __int64 v543; // r9
  void *v544; // rsp
  __int64 v545; // rdx
  __int64 v546; // rcx
  __int64 v547; // r8
  __int64 v548; // r9
  void *v549; // rsp
  __int64 v550; // rdx
  __int64 v551; // rcx
  __int64 v552; // r8
  __int64 v553; // r9
  void *v554; // rsp
  __int64 v555; // rdx
  __int64 v556; // rcx
  __int64 v557; // r8
  __int64 v558; // r9
  void *v559; // rsp
  __int64 v560; // rdx
  __int64 v561; // rcx
  __int64 v562; // r8
  __int64 v563; // r9
  void *v564; // rsp
  __int64 v565; // rdx
  __int64 v566; // rcx
  __int64 v567; // r8
  __int64 v568; // r9
  void *v569; // rsp
  __int64 v570; // rdx
  __int64 v571; // rcx
  __int64 v572; // r8
  __int64 v573; // r9
  void *v574; // rsp
  __int64 v575; // rdx
  __int64 v576; // rcx
  __int64 v577; // r8
  __int64 v578; // r9
  void *v579; // rsp
  _DWORD v581[36]; // [rsp+20h] [rbp-80h] BYREF
  IID rclsid; // [rsp+B0h] [rbp+10h] BYREF
  IID riid; // [rsp+C0h] [rbp+20h] BYREF
  __int64 (__fastcall **v584)(); // [rsp+E0h] [rbp+40h]
  __int64 v585; // [rsp+190h] [rbp+F0h]
  _DWORD *v586; // [rsp+1B8h] [rbp+118h]
  _DWORD *v587; // [rsp+1C0h] [rbp+120h]
  _DWORD *v588; // [rsp+1C8h] [rbp+128h]
  _DWORD *v589; // [rsp+1D0h] [rbp+130h]
  _DWORD *v590; // [rsp+1D8h] [rbp+138h]
  _DWORD *v591; // [rsp+1E0h] [rbp+140h]
  _DWORD *v592; // [rsp+1E8h] [rbp+148h]
  _DWORD *v593; // [rsp+1F0h] [rbp+150h]
  _DWORD *v594; // [rsp+1F8h] [rbp+158h]
  _DWORD *v595; // [rsp+200h] [rbp+160h]
  _DWORD *v596; // [rsp+208h] [rbp+168h]
  _DWORD *v597; // [rsp+210h] [rbp+170h]
  _DWORD *v598; // [rsp+218h] [rbp+178h]
  _DWORD *v599; // [rsp+220h] [rbp+180h]
  _DWORD *v600; // [rsp+228h] [rbp+188h]
  _DWORD *v601; // [rsp+230h] [rbp+190h]
  _DWORD *v602; // [rsp+238h] [rbp+198h]
  _DWORD *v603; // [rsp+240h] [rbp+1A0h]
  _DWORD *v604; // [rsp+248h] [rbp+1A8h]
  _DWORD *v605; // [rsp+250h] [rbp+1B0h]
  _DWORD *v606; // [rsp+258h] [rbp+1B8h]
  _DWORD *v607; // [rsp+260h] [rbp+1C0h]
  _DWORD *v608; // [rsp+268h] [rbp+1C8h]
  _DWORD *v609; // [rsp+270h] [rbp+1D0h]
  _DWORD *v610; // [rsp+278h] [rbp+1D8h]
  _DWORD *v611; // [rsp+280h] [rbp+1E0h]
  _DWORD *v612; // [rsp+288h] [rbp+1E8h]
  _DWORD *v613; // [rsp+290h] [rbp+1F0h]
  _DWORD *v614; // [rsp+298h] [rbp+1F8h]
  _DWORD *v615; // [rsp+2A0h] [rbp+200h]
  _DWORD *v616; // [rsp+2A8h] [rbp+208h]
  _DWORD *v617; // [rsp+2B0h] [rbp+210h]
  _DWORD *v618; // [rsp+2B8h] [rbp+218h]
  _DWORD *v619; // [rsp+2C0h] [rbp+220h]
  _DWORD *v620; // [rsp+2C8h] [rbp+228h]
  _DWORD *v621; // [rsp+2D0h] [rbp+230h]
  _DWORD *v622; // [rsp+2D8h] [rbp+238h]
  _DWORD *v623; // [rsp+2E0h] [rbp+240h]
  __int64 v624; // [rsp+2E8h] [rbp+248h]
  _DWORD *v625; // [rsp+2F0h] [rbp+250h]
  _DWORD *v626; // [rsp+2F8h] [rbp+258h]
  _DWORD *v627; // [rsp+300h] [rbp+260h]
  _DWORD *v628; // [rsp+308h] [rbp+268h]
  _DWORD *v629; // [rsp+310h] [rbp+270h]
  _DWORD *v630; // [rsp+318h] [rbp+278h]
  _DWORD *v631; // [rsp+320h] [rbp+280h]
  _DWORD *v632; // [rsp+328h] [rbp+288h]
  _DWORD *v633; // [rsp+330h] [rbp+290h]
  _DWORD *v634; // [rsp+338h] [rbp+298h]
  _DWORD *v635; // [rsp+340h] [rbp+2A0h]
  _DWORD *v636; // [rsp+348h] [rbp+2A8h]
  _DWORD *v637; // [rsp+350h] [rbp+2B0h]
  _DWORD *v638; // [rsp+358h] [rbp+2B8h]
  _DWORD *v639; // [rsp+360h] [rbp+2C0h]
  _DWORD *v640; // [rsp+368h] [rbp+2C8h]
  _DWORD *v641; // [rsp+370h] [rbp+2D0h]
  _DWORD *v642; // [rsp+378h] [rbp+2D8h]
  _DWORD *v643; // [rsp+380h] [rbp+2E0h]
  _DWORD *v644; // [rsp+388h] [rbp+2E8h]
  _DWORD *v645; // [rsp+390h] [rbp+2F0h]
  _DWORD *v646; // [rsp+398h] [rbp+2F8h]
  _DWORD *v647; // [rsp+3A0h] [rbp+300h]
  _DWORD *v648; // [rsp+3A8h] [rbp+308h]
  _DWORD *v649; // [rsp+3B0h] [rbp+310h]
  _DWORD *v650; // [rsp+3B8h] [rbp+318h]
  _DWORD *v651; // [rsp+3C0h] [rbp+320h]
  _DWORD *v652; // [rsp+3C8h] [rbp+328h]
  _DWORD *v653; // [rsp+3D0h] [rbp+330h]
  _DWORD *v654; // [rsp+3D8h] [rbp+338h]
  _DWORD *v655; // [rsp+3E0h] [rbp+340h]
  _DWORD *v656; // [rsp+3E8h] [rbp+348h]
  _DWORD *v657; // [rsp+3F0h] [rbp+350h]
  _DWORD *v658; // [rsp+3F8h] [rbp+358h]
  _DWORD *v659; // [rsp+400h] [rbp+360h]
  __int64 v660; // [rsp+408h] [rbp+368h]
  _DWORD *v661; // [rsp+410h] [rbp+370h]
  _DWORD *v662; // [rsp+418h] [rbp+378h]
  _DWORD *v663; // [rsp+420h] [rbp+380h]
  _DWORD *v664; // [rsp+428h] [rbp+388h]
  _DWORD *v665; // [rsp+430h] [rbp+390h]
  _DWORD *v666; // [rsp+438h] [rbp+398h]
  _DWORD *v667; // [rsp+440h] [rbp+3A0h]
  _DWORD *v668; // [rsp+448h] [rbp+3A8h]
  _DWORD *v669; // [rsp+450h] [rbp+3B0h]
  _DWORD *v670; // [rsp+458h] [rbp+3B8h]
  _DWORD *v671; // [rsp+460h] [rbp+3C0h]
  _DWORD *v672; // [rsp+468h] [rbp+3C8h]
  _DWORD *v673; // [rsp+470h] [rbp+3D0h]
  _DWORD *v674; // [rsp+478h] [rbp+3D8h]
  _DWORD *v675; // [rsp+480h] [rbp+3E0h]
  _DWORD *v676; // [rsp+488h] [rbp+3E8h]
  _DWORD *v677; // [rsp+490h] [rbp+3F0h]
  _DWORD *v678; // [rsp+498h] [rbp+3F8h]
  _DWORD *v679; // [rsp+4A0h] [rbp+400h]
  _DWORD *v680; // [rsp+4A8h] [rbp+408h]
  __int64 v681; // [rsp+4B0h] [rbp+410h]
  _DWORD *v682; // [rsp+4B8h] [rbp+418h]
  _DWORD *v683; // [rsp+4C0h] [rbp+420h]
  _DWORD *v684; // [rsp+4C8h] [rbp+428h]
  _DWORD *v685; // [rsp+4D0h] [rbp+430h]
  _DWORD *v686; // [rsp+4D8h] [rbp+438h]
  _DWORD *v687; // [rsp+4E0h] [rbp+440h]
  _DWORD *v688; // [rsp+4E8h] [rbp+448h]
  _DWORD *v689; // [rsp+4F0h] [rbp+450h]
  _DWORD *v690; // [rsp+4F8h] [rbp+458h]
  _DWORD *v691; // [rsp+500h] [rbp+460h]
  _DWORD *v692; // [rsp+508h] [rbp+468h]
  _DWORD *v693; // [rsp+510h] [rbp+470h]
  _DWORD *v694; // [rsp+518h] [rbp+478h]
  BOOL v695; // [rsp+55Ch] [rbp+4BCh]
  __int64 v696; // [rsp+560h] [rbp+4C0h] BYREF
  __int64 v697; // [rsp+568h] [rbp+4C8h] BYREF
  __int64 v698; // [rsp+570h] [rbp+4D0h] BYREF
  _QWORD v699[8]; // [rsp+578h] [rbp+4D8h] BYREF
  LPVOID ppv; // [rsp+5B8h] [rbp+518h] BYREF
  int v701; // [rsp+5E0h] [rbp+540h] BYREF
  _DWORD v702[32]; // [rsp+5E4h] [rbp+544h] BYREF
  int v703; // [rsp+664h] [rbp+5C4h]
  int v704; // [rsp+668h] [rbp+5C8h]
  int v705; // [rsp+66Ch] [rbp+5CCh]
  int v706; // [rsp+670h] [rbp+5D0h]
  int v707; // [rsp+674h] [rbp+5D4h]
  int v708; // [rsp+678h] [rbp+5D8h]

  v584 = off_14003A408;
  sub_14002A030(&v701);
  v708 = 0;
  while ( v708 == 0 )
  {
    v708 = 1;
    v701 = (~(2 * (v701 & 0x4C7A367D)) + (v701 & 0x4C7A367D)) & (v701 | 0x4C7A367D);
  }
  v585 = a2;
  v4 = (_DWORD *)v701;
  *(_DWORD *)a1 = *(_DWORD *)(v701 + 0x26CLL);
  *(_DWORD *)(a1 + 4) = v4[156];
  *(_DWORD *)(a1 + 8) = v4[152];
  v5 = v4[153];
  sub_14002A040(v702);
  v707 = 0;
  while ( v707 == 0 )
  {
    v707 = 1;
    v702[0] ^= 0x6AB1B030u;
  }
  *(_BYTE *)(a1 + 12) = v5 == v702[0];
  v699[6] = a1 + 16;
  *(_QWORD *)(a1 + 16) = 0;
  v681 = a1 + 24;
  *(_BYTE *)(a1 + 24) = 0;
  v660 = a1 + 44;
  *(_WORD *)(a1 + 44) = 0;
  v624 = a1 + 46;
  *(_BYTE *)(a1 + 46) = 0;
  sub_14002A050(&v696);
  v706 = 0;
  while ( v706 == 0 )
  {
    v706 = 1;
    v696 ^= 0x88E929DFuLL;
  }
  v6 = v696;
  sub_14002A060(&v697);
  v705 = 0;
  while ( v705 == 0 )
  {
    v705 = 1;
    v697 ^= 0x2720A390uLL;
  }
  *(_QWORD *)&rclsid.Data1 = v6;
  *(_QWORD *)rclsid.Data4 = v697;
  sub_14002A070(&v698);
  v704 = 0;
  while ( v704 == 0 )
  {
    v704 = 1;
    v698 ^= 0xC5581D41uLL;
  }
  v7 = v698;
  sub_14002A080(v699);
  v703 = 0;
  while ( v703 == 0 )
  {
    v703 = 1;
    v699[0] ^= 0x638F96F2uLL;
  }
  *(_QWORD *)&riid.Data1 = v7;
  *(_QWORD *)riid.Data4 = v699[0];
  ppv = nullptr;
  v8 = CoCreateInstance(&rclsid, nullptr, 1u, &riid, &ppv);
  v695 = v8 >= 0;
  v12 = alloca(sub_140001B30(v584[v8 >= 0], v9, v10, v11));
  v17 = alloca(sub_140001B30(v14, v13, v15, v16));
  v22 = alloca(sub_140001B30(v19, v18, v20, v21));
  v27 = alloca(sub_140001B30(v24, v23, v25, v26));
  v694 = v581;
  v32 = alloca(sub_140001B30(v29, v28, v30, v31));
  v37 = alloca(sub_140001B30(v34, v33, v35, v36));
  v693 = v581;
  v42 = alloca(sub_140001B30(v39, v38, v40, v41));
  v47 = alloca(sub_140001B30(v44, v43, v45, v46));
  v692 = v581;
  v52 = alloca(sub_140001B30(v49, v48, v50, v51));
  v690 = v581;
  v56 = alloca(sub_140001B30(v53, v581, v54, v55));
  v691 = v581;
  v61 = alloca(sub_140001B30(v58, v57, v59, v60));
  v688 = v581;
  v65 = alloca(sub_140001B30(v62, jpt_1400299C8, v63, v64));
  v689 = v581;
  v70 = alloca(sub_140001B30(v67, v66, v68, v69));
  v686 = v581;
  v74 = alloca(sub_140001B30(v72, v71, v581, v73));
  v687 = v581;
  v79 = alloca(sub_140001B30(v76, v75, v77, v78));
  v675 = v581;
  v83 = alloca(sub_140001B30(v81, v80, v581, v82));
  v677 = v581;
  v88 = alloca(sub_140001B30(v85, v84, v86, v87));
  v676 = v581;
  v93 = alloca(sub_140001B30(v90, v89, v91, v92));
  v678 = v581;
  v98 = alloca(sub_140001B30(v95, v94, v96, v97));
  v679 = v581;
  v103 = alloca(sub_140001B30(v100, v99, v101, v102));
  v680 = v581;
  v108 = alloca(sub_140001B30(v105, v104, v106, v107));
  v671 = v581;
  v112 = alloca(sub_140001B30(v110, v109, v581, v111));
  v674 = v581;
  v117 = alloca(sub_140001B30(v114, v113, v115, v116));
  v669 = v581;
  v122 = alloca(sub_140001B30(v119, v118, v120, v121));
  v672 = v581;
  v127 = alloca(sub_140001B30(v124, v123, v125, v126));
  v665 = v581;
  v131 = alloca(sub_140001B30(v129, v128, v581, v130));
  v666 = v581;
  v136 = alloca(sub_140001B30(v133, v132, v134, v135));
  v636 = v581;
  v140 = alloca(sub_140001B30(v138, v137, v581, v139));
  v640 = v581;
  v145 = alloca(sub_140001B30(v142, v141, v143, v144));
  v639 = v581;
  v149 = alloca(sub_140001B30(v147, v146, v581, v148));
  v642 = v581;
  v154 = alloca(sub_140001B30(v151, v150, v152, v153));
  v635 = v581;
  v158 = alloca(sub_140001B30(v156, v155, v581, v157));
  v638 = v581;
  v163 = alloca(sub_140001B30(v160, v159, v161, v162));
  v641 = v581;
  v168 = alloca(sub_140001B30(v165, v164, v166, v167));
  v645 = v581;
  v173 = alloca(sub_140001B30(v170, v169, v171, v172));
  v644 = v581;
  v177 = alloca(sub_140001B30(v175, v174, v581, v176));
  v648 = v581;
  v182 = alloca(sub_140001B30(v179, v178, v180, v181));
  v643 = v581;
  v186 = alloca(sub_140001B30(v184, v183, v581, v185));
  v646 = v581;
  v191 = alloca(sub_140001B30(v188, v187, v189, v190));
  v650 = v581;
  v196 = alloca(sub_140001B30(v193, v192, v194, v195));
  v654 = v581;
  v201 = alloca(sub_140001B30(v198, v197, v199, v200));
  v647 = v581;
  v206 = alloca(sub_140001B30(v203, v202, v204, v205));
  v651 = v581;
  v211 = alloca(sub_140001B30(v208, v207, v209, v210));
  v649 = v581;
  v216 = alloca(sub_140001B30(v213, v212, v214, v215));
  v653 = v581;
  v221 = alloca(sub_140001B30(v218, v217, v219, v220));
  v652 = v581;
  v225 = alloca(sub_140001B30(v223, v222, v581, v224));
  v655 = v581;
  v230 = alloca(sub_140001B30(v227, v226, v228, v229));
  v626 = v581;
  v234 = alloca(sub_140001B30(v232, v231, v581, v233));
  v627 = v581;
  v239 = alloca(sub_140001B30(v236, v235, v237, v238));
  v628 = v581;
  v243 = alloca(sub_140001B30(v241, v240, v581, v242));
  v631 = v581;
  v248 = alloca(sub_140001B30(v245, v244, v246, v247));
  v630 = v581;
  v252 = alloca(sub_140001B30(v250, v249, v581, v251));
  v633 = v581;
  v257 = alloca(sub_140001B30(v254, v253, v255, v256));
  v629 = v581;
  v261 = alloca(sub_140001B30(v259, v258, v581, v260));
  v632 = v581;
  v266 = alloca(sub_140001B30(v263, v262, v264, v265));
  v634 = v581;
  v271 = alloca(sub_140001B30(v268, v267, v269, v270));
  v637 = v581;
  v276 = alloca(sub_140001B30(v273, v272, v274, v275));
  v280 = alloca(sub_140001B30(v278, v277, v581, v279));
  v284 = alloca(sub_140001B30(v282, v281, v283, v581));
  v289 = alloca(sub_140001B30(v286, v285, v287, v288));
  v294 = alloca(sub_140001B30(v291, v290, v292, v293));
  v586 = v581;
  v299 = alloca(sub_140001B30(v296, v295, v297, v298));
  v587 = v581;
  v304 = alloca(sub_140001B30(v301, v300, v302, v303));
  v588 = v581;
  v309 = alloca(sub_140001B30(v306, v305, v307, v308));
  v589 = v581;
  v314 = alloca(sub_140001B30(v311, v310, v312, v313));
  v319 = alloca(sub_140001B30(v316, v315, v317, v318));
  v699[7] = v581;
  v324 = alloca(sub_140001B30(v321, v320, v322, v323));
  v590 = v581;
  v329 = alloca(sub_140001B30(v326, v325, v327, v328));
  v591 = v581;
  v334 = alloca(sub_140001B30(v331, v330, v332, v333));
  v592 = v581;
  v339 = alloca(sub_140001B30(v336, v335, v337, v338));
  v593 = v581;
  v344 = alloca(sub_140001B30(v341, v340, v342, v343));
  v594 = v581;
  v349 = alloca(sub_140001B30(v346, v345, v347, v348));
  v595 = v581;
  v354 = alloca(sub_140001B30(v351, v350, v352, v353));
  v596 = v581;
  v359 = alloca(sub_140001B30(v356, v355, v357, v358));
  v597 = v581;
  v364 = alloca(sub_140001B30(v361, v360, v362, v363));
  v598 = v581;
  v369 = alloca(sub_140001B30(v366, v365, v367, v368));
  v599 = v581;
  v374 = alloca(sub_140001B30(v371, v370, v372, v373));
  v600 = v581;
  v379 = alloca(sub_140001B30(v376, v375, v377, v378));
  v603 = v581;
  v384 = alloca(sub_140001B30(v381, v380, v382, v383));
  v605 = v581;
  v389 = alloca(sub_140001B30(v386, v385, v387, v388));
  v610 = v581;
  v394 = alloca(sub_140001B30(v391, v390, v392, v393));
  v602 = v581;
  v399 = alloca(sub_140001B30(v396, v395, v397, v398));
  v606 = v581;
  v404 = alloca(sub_140001B30(v401, v400, v402, v403));
  v607 = v581;
  v409 = alloca(sub_140001B30(v406, v405, v407, v408));
  v611 = v581;
  v414 = alloca(sub_140001B30(v411, v410, v412, v413));
  v612 = v581;
  v419 = alloca(sub_140001B30(v416, v415, v417, v418));
  v619 = v581;
  v424 = alloca(sub_140001B30(v421, v420, v422, v423));
  v616 = v581;
  v429 = alloca(sub_140001B30(v426, v425, v427, v428));
  v622 = v581;
  v434 = alloca(sub_140001B30(v431, v430, v432, v433));
  v613 = v581;
  v439 = alloca(sub_140001B30(v436, v435, v437, v438));
  v620 = v581;
  v444 = alloca(sub_140001B30(v441, v440, v442, v443));
  v617 = v581;
  v449 = alloca(sub_140001B30(v446, v445, v447, v448));
  v623 = v581;
  v454 = alloca(sub_140001B30(v451, v450, v452, v453));
  v621 = v581;
  v459 = alloca(sub_140001B30(v456, v455, v457, v458));
  v625 = v581;
  v464 = alloca(sub_140001B30(v461, v460, v462, v463));
  v601 = v581;
  v469 = alloca(sub_140001B30(v466, v465, v467, v468));
  v604 = v581;
  v474 = alloca(sub_140001B30(v471, v470, v472, v473));
  v608 = v581;
  v479 = alloca(sub_140001B30(v476, v475, v477, v478));
  v615 = v581;
  v484 = alloca(sub_140001B30(v481, v480, v482, v483));
  v614 = v581;
  v489 = alloca(sub_140001B30(v486, v485, v487, v488));
  v618 = v581;
  v494 = alloca(sub_140001B30(v491, v490, v492, v493));
  v609 = v581;
  v499 = alloca(sub_140001B30(v496, v495, v497, v498));
  v504 = alloca(sub_140001B30(v501, v500, v502, v503));
  v684 = v581;
  v509 = alloca(sub_140001B30(v506, v505, v507, v508));
  v685 = v581;
  v514 = alloca(sub_140001B30(v511, v510, v512, v513));
  v682 = v581;
  v519 = alloca(sub_140001B30(v516, v515, v517, v518));
  v683 = v581;
  v524 = alloca(sub_140001B30(v521, v520, v522, v523));
  v670 = v581;
  v529 = alloca(sub_140001B30(v526, v525, v527, v528));
  v673 = v581;
  v534 = alloca(sub_140001B30(v531, v530, v532, v533));
  v667 = v581;
  v539 = alloca(sub_140001B30(v536, v535, v537, v538));
  v668 = v581;
  v544 = alloca(sub_140001B30(v541, v540, v542, v543));
  v661 = v581;
  v549 = alloca(sub_140001B30(v546, v545, v547, v548));
  v663 = v581;
  v554 = alloca(sub_140001B30(v551, v550, v552, v553));
  v662 = v581;
  v559 = alloca(sub_140001B30(v556, v555, v557, v558));
  v664 = v581;
  v564 = alloca(sub_140001B30(v561, v560, v562, v563));
  v657 = v581;
  v569 = alloca(sub_140001B30(v566, v565, v567, v568));
  v659 = v581;
  v574 = alloca(sub_140001B30(v571, v570, v572, v573));
  v656 = v581;
  v579 = alloca(sub_140001B30(v576, v575, v577, v578));
  v658 = v581;
  v581[0] = 237;
  __asm { jmp     rcx }
}


// ---- sub_140025A69 @ 0x140025a69 ----
__int64 __fastcall sub_140025A69()
{
  __int64 v0; // rbp
  __int64 v1; // r14
  _BYTE *v2; // rbx
  __int64 v3; // rax
  _BYTE *v4; // rdi
  __int64 v5; // rax
  __int64 v6; // rax
  _BYTE *v7; // rdi
  __int64 v8; // rax
  _BYTE *v9; // rdi
  __int64 v10; // rax
  _BYTE *v11; // rdi
  __int64 v12; // rax
  _BYTE *v13; // r14
  __int64 v14; // rax
  __int64 v15; // rax
  int *v16; // rcx

  v1 = sub_140016BE0(*(unsigned __int16 **)(v0 + 152), 0) + 1;
  v2 = (_BYTE *)sub_14002E070(v1);
  sub_14000D200(v2, v1, *(unsigned __int16 **)(v0 + 152), 0);
  sub_14002A3E0(v0 + 1364);
  for ( *(_DWORD *)(v0 + 1420) = 0;
        *(_DWORD *)(v0 + 1420) == 0;
        *(_DWORD *)(v0 + 4 * v3 + 1364) ^= -448877645 * *(_DWORD *)(v0 + 1420) )
  {
    nullsub_1();
    nullsub_1();
    v3 = *(int *)(v0 + 1420);
    *(_DWORD *)(v0 + 1420) = (*(_DWORD *)(v0 + 1420) ^ 1) + 2 * (*(_DWORD *)(v0 + 1420) & 1);
  }
  v4 = (_BYTE *)sub_14002A290(*(_QWORD *)(v0 + 584), &v2[*(unsigned int *)(v0 + 1364)], 2);
  sub_14002A3F0(v0 + 1507);
  for ( *(_DWORD *)(v0 + 1416) = 0;
        *(_DWORD *)(v0 + 1416) == 0;
        *(_BYTE *)(v0 + v5 + 1507) = ~(*(_BYTE *)(v0 + v5 + 1507) & (62 * *(_DWORD *)(v0 + 1416)))
                                   & (*(_BYTE *)(v0 + v5 + 1507)
                                    + (*(_BYTE *)(v0 + v5 + 1507) ^ (62 * *(_DWORD *)(v0 + 1416)))
                                    - (~(62 * *(_DWORD *)(v0 + 1416)) & *(_BYTE *)(v0 + v5 + 1507))) )
  {
    v5 = *(int *)(v0 + 1416);
    *(_DWORD *)(v0 + 1416) = (*(_DWORD *)(v0 + 1416) ^ 1) + 2 * (*(_DWORD *)(v0 + 1416) & 1);
  }
  *v4 = *(_BYTE *)(v0 + 1507);
  sub_14002A400(v0 + 1368);
  for ( *(_DWORD *)(v0 + 1412) = 0;
        *(_DWORD *)(v0 + 1412) == 0;
        *(_DWORD *)(v0 + 4 * v6 + 1368) = (-2
                                         - ((~*(_DWORD *)(v0 + 4 * v6 + 1368) | (565026581 * *(_DWORD *)(v0 + 1412)))
                                          + *(_DWORD *)(v0 + 4 * v6 + 1368)))
                                        & ((565026581 * *(_DWORD *)(v0 + 1412)) | *(_DWORD *)(v0 + 4 * v6 + 1368)) )
  {
    v6 = (int)(*(_DWORD *)(v0 + 1412))++;
  }
  v7 = (_BYTE *)sub_14002A290(v4 + 1, &v2[*(unsigned int *)(v0 + 1368)], 2);
  sub_14002A410(v0 + 1508);
  *(_DWORD *)(v0 + 1408) = 0;
  while ( *(_DWORD *)(v0 + 1408) == 0 )
  {
    v8 = (int)(*(_DWORD *)(v0 + 1408))++;
    *(_BYTE *)(v0 + v8 + 1508) ^= 54 * *(_BYTE *)(v0 + 1408);
  }
  *v7 = *(_BYTE *)(v0 + 1508);
  v9 = (_BYTE *)sub_14002A290(v7 + 1, v2, 4);
  sub_14002A420(v0 + 1509);
  for ( *(_DWORD *)(v0 + 1404) = 0;
        *(_DWORD *)(v0 + 1404) == 0;
        *(_BYTE *)(v0 + v10 + 1509) = (-2
                                     - (*(_BYTE *)(v0 + v10 + 1509)
                                      + (~*(_BYTE *)(v0 + v10 + 1509) | (111 * *(_DWORD *)(v0 + 1404)))))
                                    & (*(_BYTE *)(v0 + v10 + 1509) | (111 * *(_DWORD *)(v0 + 1404))) )
  {
    v10 = (int)(*(_DWORD *)(v0 + 1404))++;
  }
  *v9 = *(_BYTE *)(v0 + 1509);
  v11 = (_BYTE *)sub_14002A290(v9 + 1, v2 + 8, 2);
  sub_14002A430(v0 + 1510);
  *(_DWORD *)(v0 + 1400) = 0;
  while ( *(_DWORD *)(v0 + 1400) == 0 )
  {
    v12 = (int)(*(_DWORD *)(v0 + 1400))++;
    *(_BYTE *)(v0 + v12 + 1510) ^= 46 * *(_BYTE *)(v0 + 1400);
  }
  *v11 = *(_BYTE *)(v0 + 1510);
  v13 = (_BYTE *)sub_14002A290(v11 + 1, v2 + 10, 2);
  sub_14002A440(v0 + 1511);
  *(_DWORD *)(v0 + 1396) = 0;
  while ( *(_DWORD *)(v0 + 1396) == 0 )
  {
    v14 = (int)(*(_DWORD *)(v0 + 1396))++;
    *(_BYTE *)(v0 + v14 + 1511) ^= 103 * *(_BYTE *)(v0 + 1396);
  }
  *v13 = *(_BYTE *)(v0 + 1511);
  sub_14002A450(v0 + 1372);
  for ( *(_DWORD *)(v0 + 1392) = 0;
        *(_DWORD *)(v0 + 1392) == 0;
        *(_DWORD *)(v0 + 4 * v15 + 1372) ^= 952303498 * *(_DWORD *)(v0 + 1392) )
  {
    v15 = (int)(*(_DWORD *)(v0 + 1392))++;
  }
  *(_BYTE *)sub_14002A290(v13 + 1, &v2[*(unsigned int *)(v0 + 1372)], 2) = 0;
  v16 = *(int **)(v0 + 712);
  *v16 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 680) + 8LL * *v16))();
}


// ---- sub_140025F6A @ 0x140025f6a ----
__int64 __fastcall sub_140025F6A()
{
  __int64 v0; // rbp
  _QWORD *v1; // rsi

  *v1 = *(_QWORD *)(v0 + 1272);
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 488) + 8LL * **(int **)(v0 + 544)))();
}


// ---- sub_14002611F @ 0x14002611f ----
__int64 __fastcall sub_14002611F()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 592);
  *v1 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 560) + 8LL * *v1))();
}


// ---- sub_140026168 @ 0x140026168 ----
__int64 __fastcall sub_140026168()
{
  __int64 v0; // rbp
  _QWORD *v1; // r14
  __int64 v2; // rbx
  _BYTE *v3; // rax

  v2 = sub_140016BE0(*(unsigned __int16 **)(v0 + 192), 0) + 1;
  v3 = (_BYTE *)sub_14002E070(v2);
  *v1 = v3;
  sub_14000D200(v3, v2, *(unsigned __int16 **)(v0 + 192), 0);
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 344) + 8LL * **(int **)(v0 + 352)))();
}


// ---- sub_1400261CE @ 0x1400261ce ----
__int64 __fastcall sub_1400261CE()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 792) + 8LL * **(int **)(v0 + 824)))();
}


// ---- sub_1400261E8 @ 0x1400261e8 ----
__int64 __fastcall sub_1400261E8()
{
  __int64 v0; // rbp
  _QWORD *v1; // rdi
  int v2; // eax
  int *v3; // rcx

  *(_QWORD *)(v0 + 1312) = sub_14002A100();
  *(_QWORD *)(v0 + 1376) = sub_14002A180();
  v2 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD, __int64, _QWORD, __int64))(**(_QWORD **)(v0 + 1328) + 160LL))(
         *(_QWORD *)(v0 + 1328),
         *(_QWORD *)(v0 + 1312),
         *(_QWORD *)(v0 + 1376),
         48,
         0,
         v0 + 1176);
  v3 = *(int **)(v0 + 1136);
  *v3 = v2 >= 0;
  return (*(__int64 (**)(void))(*v1 + 8LL * *v3))();
}


// ---- sub_140026278 @ 0x140026278 ----
__int64 __fastcall sub_140026278()
{
  __int64 v0; // rbp
  int *v1; // rdi
  _QWORD *v2; // rsi

  nullsub_1();
  *(_QWORD *)(v0 + 1280) = v0 + 1248;
  sub_14002A460(*(_QWORD *)(v0 + 1280));
  (*(void (__fastcall **)(_QWORD))(**(_QWORD **)(v0 + 1304) + 16LL))(*(_QWORD *)(v0 + 1304));
  *v1 = 0;
  return (*(__int64 (**)(void))(*v2 + 8LL * *v1))();
}


// ---- sub_1400262D1 @ 0x1400262d1 ----
__int64 __fastcall sub_1400262D1()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 304);
  *v1 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 296) + 8LL * *v1))();
}


// ---- sub_1400262FE @ 0x1400262fe ----
__int64 __fastcall sub_1400262FE()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 720) + 8LL * **(int **)(v0 + 752)))();
}


// ---- sub_14002633A @ 0x14002633a ----
__int64 __fastcall sub_14002633A()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 536);
  *v1 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 504) + 8LL * *v1))();
}


// ---- sub_140026375 @ 0x140026375 ----
__int64 __fastcall sub_140026375()
{
  __int64 v0; // rbp
  _QWORD *v1; // r13
  HRESULT v2; // eax
  int *v3; // rcx

  v2 = CoSetProxyBlanket(*(IUnknown **)(v0 + 1328), 0xAu, 0, nullptr, 3u, 3u, nullptr, 0);
  v3 = *(int **)(v0 + 1144);
  *v3 = v2 >= 0;
  return (*(__int64 (**)(void))(*v1 + 8LL * *v3))();
}


// ---- sub_1400263D4 @ 0x1400263d4 ----
__int64 __fastcall sub_1400263D4()
{
  __int64 v0; // rbp
  int v1; // eax
  int *v2; // rcx

  *(_DWORD *)(v0 + 1324) = 0;
  v1 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int64, __int64, __int64))(**(_QWORD **)(v0 + 1264) + 32LL))(
         *(_QWORD *)(v0 + 1264),
         0xFFFFFFFFLL,
         1,
         v0 + 1184,
         v0 + 1324);
  v2 = *(int **)(v0 + 256);
  *v2 = v1 < 0 || *(_DWORD *)(v0 + 1324) == 0 || v1 == 1;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 248) + 8LL * *v2))();
}


// ---- sub_14002644D @ 0x14002644d ----
__int64 __fastcall sub_14002644D()
{
  __int64 v0; // rbp
  int *v1; // rdi
  _QWORD *v2; // rsi

  nullsub_1();
  *(_QWORD *)(v0 + 1272) = 0;
  *v1 = 1;
  return (*(__int64 (**)(void))(*v2 + 8LL * *v1))();
}


// ---- sub_140026477 @ 0x140026477 ----
__int64 __fastcall sub_140026477()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 456) + 8LL * **(int **)(v0 + 512)))();
}


// ---- sub_140026491 @ 0x140026491 ----
__int64 __fastcall sub_140026491()
{
  _QWORD *v0; // rbx
  int *v1; // r14

  return (*(__int64 (**)(void))(*v0 + 8LL * *v1))();
}


// ---- sub_14002649D @ 0x14002649d ----
__int64 __fastcall sub_14002649D()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 472);
  *v1 = 1;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 432) + 8LL * *v1))();
}


// ---- sub_1400264DF @ 0x1400264df ----
__int64 __fastcall sub_1400264DF()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 280) + 8LL * **(int **)(v0 + 288)))();
}


// ---- sub_1400264FB @ 0x1400264fb ----
__int64 __fastcall sub_1400264FB()
{
  __int64 v0; // rbp
  __int64 v1; // r14
  __int64 v2; // rax
  int v3; // eax
  int *v4; // rcx

  *(_QWORD *)(v0 + 104) = v0 + 72;
  VariantClear(*(VARIANTARG **)(v0 + 104));
  *(_QWORD *)(v0 + 112) = v0 + 1152;
  VariantInit(*(VARIANTARG **)(v0 + 112));
  v1 = *(_QWORD *)(v0 + 1336);
  sub_14002A270(v0 - 60);
  for ( *(_DWORD *)(v0 + 1464) = 0; ; *(_WORD *)(v0 + 2 * v2 - 60) ^= -23856 * (unsigned __int16)*(_DWORD *)(v0 + 1464) )
  {
    nullsub_1();
    nullsub_1();
    if ( *(_DWORD *)(v0 + 1464) >= 0xEu )
      break;
    v2 = (int)(*(_DWORD *)(v0 + 1464))++;
  }
  v3 = (*(__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, _QWORD))(*(_QWORD *)v1 + 32LL))(
         v1,
         v0 - 60,
         0,
         v0 + 1152,
         0,
         0);
  v4 = *(int **)(v0 + 1088);
  *v4 = *(_WORD *)(v0 + 1152) == 8 && v3 >= 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 1080) + 8LL * *v4))();
}


// ---- sub_140026607 @ 0x140026607 ----
__int64 __fastcall sub_140026607()
{
  int *v0; // rbx
  _QWORD *v1; // rdi
  __int64 v2; // rsi
  __int64 v3; // rcx

  nullsub_1();
  LOBYTE(v3) = v2 != 0;
  *v0 = 0;
  return (*(__int64 (__fastcall **)(__int64))(*v1 + 8LL * *v0))(v3);
}


// ---- sub_14002666E @ 0x14002666e ----
__int64 __fastcall sub_14002666E()
{
  int *v0; // rdi
  _QWORD *v1; // rsi

  nullsub_1();
  *v0 = 1;
  return (*(__int64 (**)(void))(*v1 + 8LL * *v0))();
}


// ---- sub_140026803 @ 0x140026803 ----
__int64 __fastcall sub_140026803()
{
  __int64 v0; // rbp
  __int64 v1; // r14
  __int64 v2; // rax
  int v3; // eax
  int *v4; // rcx

  *(_QWORD *)(v0 + 96) = v0 + 72;
  VariantInit(*(VARIANTARG **)(v0 + 96));
  v1 = *(_QWORD *)(v0 + 1336);
  sub_14002A240(v0 + 48);
  *(_DWORD *)(v0 + 1472) = 0;
  while ( *(_DWORD *)(v0 + 1472) < 8u )
  {
    v2 = (int)(*(_DWORD *)(v0 + 1472))++;
    *(_WORD *)(v0 + 2 * v2 + 48) = (*(_WORD *)(v0 + 2 * v2 + 48)
                                  | ((*(_WORD *)(v0 + 1472) & 0x3694 ^ 0x3694) * (*(_WORD *)(v0 + 1472) & 0xC96B)
                                   + (*(_WORD *)(v0 + 1472) & 0x3694) * (*(_WORD *)(v0 + 1472) | 0x3694))
                                  & 0xFFFC)
                                 - (*(_WORD *)(v0 + 2 * v2 + 48)
                                  & ((*(_WORD *)(v0 + 1472) & 0x3694 ^ 0x3694) * (*(_WORD *)(v0 + 1472) & 0xC96B)
                                   + (*(_WORD *)(v0 + 1472) & 0x3694) * (*(_WORD *)(v0 + 1472) | 0x3694)));
  }
  v3 = (*(__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, _QWORD))(*(_QWORD *)v1 + 32LL))(
         v1,
         v0 + 48,
         0,
         v0 + 72,
         0,
         0);
  v4 = *(int **)(v0 + 1120);
  *v4 = *(_WORD *)(v0 + 72) == 8 && v3 >= 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 1112) + 8LL * *v4))();
}


// ---- sub_140026916 @ 0x140026916 ----
__int64 __fastcall sub_140026916(char a1)
{
  __int64 v1; // rbp
  int v2; // eax
  int *v3; // rcx

  v2 = a1 & 1;
  v3 = *(int **)(v1 + 320);
  *v3 = v2;
  return (*(__int64 (**)(void))(**(_QWORD **)(v1 + 312) + 8LL * *v3))();
}


// ---- sub_140026937 @ 0x140026937 ----
__int64 __fastcall sub_140026937()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 656);
  *v1 = 1;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 632) + 8LL * *v1))();
}


// ---- sub_140026972 @ 0x140026972 ----
// positive sp value has been detected, the output may be wrong!
char __fastcall sub_140026972()
{
  char v0; // al

  return v0 & 1;
}


// ---- sub_140026988 @ 0x140026988 ----
__int64 __fastcall sub_140026988()
{
  __int64 v0; // rbp

  *(_QWORD *)(v0 + 224) = v0 + 1376;
  sub_14002A460(*(_QWORD *)(v0 + 224));
  *(_QWORD *)(v0 + 232) = v0 + 1312;
  sub_14002A460(*(_QWORD *)(v0 + 232));
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 496) + 8LL * **(int **)(v0 + 552)))();
}


// ---- sub_1400269E6 @ 0x1400269e6 ----
__int64 __fastcall sub_1400269E6()
{
  __int64 v0; // rbp
  _BYTE *v1; // rdi
  _BYTE *v2; // rsi

  *v1 = *v2;
  *(_QWORD *)(v0 + 1272) = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 928) + 8LL * **(int **)(v0 + 936)))();
}


// ---- sub_140026A13 @ 0x140026a13 ----
__int64 __fastcall sub_140026A13()
{
  int v0; // ebx
  _QWORD *v1; // r13
  int *v2; // r15
  __int64 v3; // rcx

  nullsub_1();
  LOBYTE(v3) = v0 == 0;
  *v2 = 0;
  return (*(__int64 (__fastcall **)(__int64))(*v1 + 8LL * *v2))(v3);
}


// ---- sub_140026A3B @ 0x140026a3b ----
__int64 __fastcall sub_140026A3B()
{
  _QWORD *v0; // rdi
  int *v1; // r12

  nullsub_1();
  *v1 = 0;
  return (*(__int64 (**)(void))(*v0 + 8LL * *v1))();
}


// ---- sub_140026A66 @ 0x140026a66 ----
__int64 __fastcall sub_140026A66()
{
  __int64 v0; // rbp

  *(_QWORD *)(v0 + 176) = v0 + 144;
  VariantClear(*(VARIANTARG **)(v0 + 176));
  (*(void (__fastcall **)(_QWORD))(**(_QWORD **)(v0 + 1336) + 16LL))(*(_QWORD *)(v0 + 1336));
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 768) + 8LL * **(int **)(v0 + 800)))();
}


// ---- sub_140026ABA @ 0x140026aba ----
__int64 __fastcall sub_140026ABA()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 664) + 8LL * **(int **)(v0 + 688)))();
}


// ---- sub_140026ADB @ 0x140026adb ----
__int64 __fastcall sub_140026ADB()
{
  __int64 v0; // rbp

  **(_WORD **)(v0 + 872) = *(__int16 *)v0 / 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 944) + 8LL * **(int **)(v0 + 968)))();
}


// ---- sub_140026B1B @ 0x140026b1b ----
__int64 __fastcall sub_140026B1B(char a1)
{
  __int64 v1; // rbp
  int v2; // eax
  int *v3; // rcx

  v2 = a1 & 1;
  v3 = *(int **)(v1 + 480);
  *v3 = v2;
  return (*(__int64 (**)(void))(**(_QWORD **)(v1 + 448) + 8LL * *v3))();
}


// ---- sub_140026B3C @ 0x140026b3c ----
__int64 __fastcall sub_140026B3C()
{
  char v0; // al
  __int64 v1; // rbp
  int *v2; // rdx

  v2 = *(int **)(v1 + 640);
  *v2 = v0 & 1;
  return (*(__int64 (**)(void))(**(_QWORD **)(v1 + 616) + 8LL * *v2))();
}


// ---- sub_140026B5D @ 0x140026b5d ----
__int64 __fastcall sub_140026B5D()
{
  __int64 v0; // rbp
  __int64 v1; // r14
  _BYTE *v2; // rax
  __int64 v3; // rax
  unsigned __int64 *v4; // rsi
  _BYTE *v5; // rax
  __int64 v6; // r14

  v1 = sub_140016BE0(*(unsigned __int16 **)(v0 + 80), 0);
  v2 = (_BYTE *)sub_14002E070(2 * (v1 & 1) + (v1 ^ 1));
  **(_QWORD **)(v0 + 1288) = v2;
  sub_14000D200(v2, 2 * (v1 & 1) + (v1 ^ 1), *(unsigned __int16 **)(v0 + 80), 0);
  sub_14002A250(v0 + 1204);
  *(_DWORD *)(v0 + 1468) = 0;
  while ( *(_DWORD *)(v0 + 1468) < 8u )
  {
    v3 = (int)(*(_DWORD *)(v0 + 1468))++;
    *(_BYTE *)(v0 + v3 + 1204) ^= 57 * *(_BYTE *)(v0 + 1468);
  }
  v4 = *(unsigned __int64 **)(v0 + 1288);
  v5 = sub_1400161B0((_BYTE *)*v4, (_BYTE *)(v0 + 1204));
  v6 = 2 * (~(unsigned __int64)&v5[-*v4] & v1) - ((unsigned __int64)&v5[-*v4] ^ v1);
  sub_140001D60(*v4, (unsigned __int64)v5, (v6 | 1) + (v6 & 1));
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 1096) + 8LL * **(int **)(v0 + 1104)))();
}


// ---- sub_140026C93 @ 0x140026c93 ----
__int64 __fastcall sub_140026C93()
{
  __int64 v0; // rbp
  __int64 v1; // r15
  _BYTE *v2; // r14
  __int64 v3; // rax
  _BYTE *v4; // rbx
  __int64 v5; // rax
  _BYTE *v6; // r15
  __int64 v7; // rax
  __int64 v8; // rax
  _BYTE *v9; // rbx
  __int64 v10; // rax
  _BYTE *v11; // r15
  __int64 v12; // rax
  __int64 v13; // rax
  int v14; // ecx
  int v15; // r8d
  int v16; // ecx
  _BYTE *v17; // rbx
  __int64 v18; // rax
  int *v19; // rcx

  v1 = sub_140016BE0(*(unsigned __int16 **)(v0 + 1160), 0) + 1;
  v2 = (_BYTE *)sub_14002E070(v1);
  sub_14000D200(v2, v1, *(unsigned __int16 **)(v0 + 1160), 0);
  sub_14002A320(v0 + 1352);
  for ( *(_DWORD *)(v0 + 1460) = 0;
        *(_DWORD *)(v0 + 1460) == 0;
        *(_DWORD *)(v0 + 4 * v3 + 1352) ^= -1223431479 * *(_DWORD *)(v0 + 1460) )
  {
    v3 = (int)(*(_DWORD *)(v0 + 1460))++;
  }
  v4 = (_BYTE *)sub_14002A290(*(_QWORD *)(v0 + 1040), &v2[*(unsigned int *)(v0 + 1352)], 2);
  sub_14002A330(v0 + 1502);
  *(_DWORD *)(v0 + 1456) = 0;
  while ( *(_DWORD *)(v0 + 1456) == 0 )
  {
    v5 = (int)(*(_DWORD *)(v0 + 1456))++;
    *(_BYTE *)(v0 + v5 + 1502) ^= 106 * *(_BYTE *)(v0 + 1456);
  }
  *v4 = *(_BYTE *)(v0 + 1502);
  v6 = (_BYTE *)sub_14002A290(v4 + 1, v2 + 4, 2);
  sub_14002A340(v0 + 1503);
  *(_DWORD *)(v0 + 1452) = 0;
  while ( 1 )
  {
    nullsub_1();
    nullsub_1();
    if ( *(_DWORD *)(v0 + 1452) != 0 )
      break;
    v7 = (int)(*(_DWORD *)(v0 + 1452))++;
    *(_BYTE *)(v0 + v7 + 1503) ^= 41 * *(_BYTE *)(v0 + 1452);
  }
  *v6 = *(_BYTE *)(v0 + 1503);
  sub_14002A350(v0 + 1356);
  for ( *(_DWORD *)(v0 + 1448) = 0;
        ;
        *(_DWORD *)(v0 + 4 * v8 + 1356) ^= (*(_DWORD *)(v0 + 1448) & 0x91BA57DC ^ 0x91BA57DC)
                                         * (*(_DWORD *)(v0 + 1448) & 0x6E45A823)
                                         + (*(_DWORD *)(v0 + 1448) & 0x91BA57DC) * (*(_DWORD *)(v0 + 1448) | 0x91BA57DC) )
  {
    nullsub_1();
    nullsub_1();
    if ( *(_DWORD *)(v0 + 1448) != 0 )
      break;
    v8 = (int)(*(_DWORD *)(v0 + 1448))++;
  }
  v9 = (_BYTE *)sub_14002A290(v6 + 1, v2, *(unsigned int *)(v0 + 1356));
  sub_14002A360(v0 + 1504);
  *(_DWORD *)(v0 + 1444) = 0;
  while ( *(_DWORD *)(v0 + 1444) == 0 )
  {
    v10 = (int)(*(_DWORD *)(v0 + 1444))++;
    *(_BYTE *)(v0 + v10 + 1504) ^= 29 * *(_BYTE *)(v0 + 1444);
  }
  *v9 = *(_BYTE *)(v0 + 1504);
  v11 = (_BYTE *)sub_14002A290(v9 + 1, v2 + 8, 2);
  sub_14002A370(v0 + 1505);
  *(_DWORD *)(v0 + 1440) = 0;
  while ( *(_DWORD *)(v0 + 1440) == 0 )
  {
    v12 = (int)(*(_DWORD *)(v0 + 1440))++;
    *(_BYTE *)(v0 + v12 + 1505) ^= 90 * *(_BYTE *)(v0 + 1440);
  }
  *v11 = *(_BYTE *)(v0 + 1505);
  sub_14002A380(v0 + 1360);
  *(_DWORD *)(v0 + 1436) = 0;
  while ( *(_DWORD *)(v0 + 1436) == 0 )
  {
    v13 = (int)(*(_DWORD *)(v0 + 1436))++;
    v14 = 1818281199 * *(_DWORD *)(v0 + 1436);
    v15 = v14 | *(_DWORD *)(v0 + 4 * v13 + 1360);
    v16 = *(_DWORD *)(v0 + 4 * v13 + 1360) + 1 + (~*(_DWORD *)(v0 + 4 * v13 + 1360) | v14);
    *(_DWORD *)(v0 + 4 * v13 + 1360) = (~(2 * v16) + v16) & v15;
  }
  v17 = (_BYTE *)sub_14002A290(v11 + 1, &v2[*(unsigned int *)(v0 + 1360)], 2);
  sub_14002A390(v0 + 1506);
  for ( *(_DWORD *)(v0 + 1432) = 0; ; *(_BYTE *)(v0 + v18 + 1506) ^= 78 * (unsigned __int8)*(_DWORD *)(v0 + 1432) )
  {
    nullsub_1();
    nullsub_1();
    if ( *(_DWORD *)(v0 + 1432) != 0 )
      break;
    v18 = (int)(*(_DWORD *)(v0 + 1432))++;
  }
  *v17 = *(_BYTE *)(v0 + 1506);
  *(_BYTE *)sub_14002A290(v17 + 1, v2 + 12, 2) = 0;
  v19 = *(int **)(v0 + 1008);
  *v19 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 992) + 8LL * *v19))();
}


// ---- sub_140027192 @ 0x140027192 ----
__int64 __fastcall sub_140027192()
{
  __int64 v0; // rbp
  int *v1; // rdi
  _QWORD *v2; // rsi

  nullsub_1();
  *(_QWORD *)(v0 + 1256) = v0 + 1376;
  sub_14002A460(*(_QWORD *)(v0 + 1256));
  *(_QWORD *)(v0 + 1376) = sub_14002A470();
  (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD, __int64, _QWORD, __int64))(**(_QWORD **)(v0 + 1328) + 160LL))(
    *(_QWORD *)(v0 + 1328),
    *(_QWORD *)(v0 + 1312),
    *(_QWORD *)(v0 + 1376),
    48,
    0,
    v0 + 1264);
  *v1 = 1;
  return (*(__int64 (__fastcall **)(_QWORD))(*v2 + 8LL * *v1))(0);
}


// ---- sub_14002722A @ 0x14002722a ----
__int64 __fastcall sub_14002722A()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 376) + 8LL * **(int **)(v0 + 384)))();
}


// ---- sub_140027244 @ 0x140027244 ----
__int64 __fastcall sub_140027244()
{
  int v0; // ebx
  __int64 v1; // rbp
  int *v2; // rcx

  v2 = *(int **)(v1 + 416);
  *v2 = v0 == 3;
  return (*(__int64 (**)(void))(**(_QWORD **)(v1 + 392) + 8LL * *v2))();
}


// ---- sub_140027268 @ 0x140027268 ----
__int64 __fastcall sub_140027268(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rbp
  _QWORD *v5; // rsi
  __int64 v6; // r10
  __int64 v7; // r11
  int *v8; // r15

  *(_QWORD *)(v4 + 272) = v7;
  *(_QWORD *)(v4 + 264) = v6;
  *(_QWORD *)(v4 + 256) = a4;
  *(_QWORD *)(v4 + 248) = a3;
  *(_QWORD *)(v4 + 1248) = sub_14002A090();
  *v8 = (*(int (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, __int64))(**(_QWORD **)(v4 + 1304) + 24LL))(
          *(_QWORD *)(v4 + 1304),
          *(_QWORD *)(v4 + 1248),
          0,
          0,
          0,
          0,
          0,
          0,
          v4 + 1328) >= 0;
  return (*(__int64 (**)(void))(*v5 + 8LL * *v8))();
}


// ---- sub_140027300 @ 0x140027300 ----
__int64 __fastcall sub_140027300()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 264) + 8LL * **(int **)(v0 + 272)))();
}


// ---- sub_14002731F @ 0x14002731f ----
__int64 __fastcall sub_14002731F()
{
  __int64 v0; // rbx
  int *v1; // rdi
  _QWORD *v2; // rsi

  nullsub_1();
  sub_140001C10(v0);
  *v1 = 0;
  return (*(__int64 (**)(void))(*v2 + 8LL * *v1))();
}


// ---- sub_140027346 @ 0x140027346 ----
__int64 __fastcall sub_140027346()
{
  __int64 v0; // rbp

  (*(void (__fastcall **)(_QWORD))(**(_QWORD **)(v0 + 1176) + 16LL))(*(_QWORD *)(v0 + 1176));
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 784) + 8LL * **(int **)(v0 + 816)))();
}


// ---- sub_140027378 @ 0x140027378 ----
__int64 __fastcall sub_140027378()
{
  __int64 v0; // rbp
  _QWORD *v1; // rsi
  _QWORD *v2; // rdi
  __int64 v3; // rbx
  __int64 v4; // rax
  int v5; // eax
  int *v6; // rcx

  v2 = (_QWORD *)sub_14002E070(16);
  *v2 = 0;
  v2[1] = 0;
  *v1 = v2;
  *(_QWORD *)(v0 + 208) = v0 + 184;
  VariantInit(*(VARIANTARG **)(v0 + 208));
  v3 = *(_QWORD *)(v0 + 1184);
  sub_14002A510(v0 + 1194);
  *(_DWORD *)(v0 + 1388) = 0;
  while ( *(_DWORD *)(v0 + 1388) < 5u )
  {
    v4 = (int)(*(_DWORD *)(v0 + 1388))++;
    *(_WORD *)(v0 + 2 * v4 + 1194) = (*(_WORD *)(v0 + 2 * v4 + 1194)
                                    | ((*(_WORD *)(v0 + 1388) & 0x22AF) * (*(_WORD *)(v0 + 1388) & 0xDD50 ^ 0xDD50)
                                     + (*(_WORD *)(v0 + 1388) & 0xDD50) * (*(_WORD *)(v0 + 1388) | 0xDD50))
                                    & 0xFFF0)
                                   ^ *(_WORD *)(v0 + 2 * v4 + 1194)
                                   & ((*(_WORD *)(v0 + 1388) & 0x22AF) * (*(_WORD *)(v0 + 1388) & 0xDD50 ^ 0xDD50)
                                    + (*(_WORD *)(v0 + 1388) & 0xDD50) * (*(_WORD *)(v0 + 1388) | 0xDD50));
  }
  nullsub_1();
  nullsub_1();
  v5 = (*(__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, _QWORD))(*(_QWORD *)v3 + 32LL))(
         v3,
         v0 + 1194,
         0,
         v0 + 184,
         0,
         0);
  v6 = *(int **)(v0 + 336);
  *v6 = *(_WORD *)(v0 + 184) == 8 && v5 >= 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 328) + 8LL * *v6))();
}


// ---- sub_140027568 @ 0x140027568 ----
__int64 __fastcall sub_140027568()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 728);
  *v1 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 704) + 8LL * *v1))();
}


// ---- sub_1400275A3 @ 0x1400275a3 ----
__int64 __fastcall sub_1400275A3()
{
  __int64 v0; // rbp

  (*(void (__fastcall **)(_QWORD))(**(_QWORD **)(v0 + 1264) + 16LL))(*(_QWORD *)(v0 + 1264));
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 520) + 8LL * **(int **)(v0 + 568)))();
}


// ---- sub_1400275D5 @ 0x1400275d5 ----
__int64 __fastcall sub_1400275D5()
{
  __int64 v0; // rbp

  *(_QWORD *)(v0 + 216) = v0 + 184;
  VariantClear(*(VARIANTARG **)(v0 + 216));
  (*(void (__fastcall **)(_QWORD))(**(_QWORD **)(v0 + 1184) + 16LL))(*(_QWORD *)(v0 + 1184));
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 360) + 8LL * **(int **)(v0 + 368)))();
}


// ---- sub_14002762E @ 0x14002762e ----
__int64 __fastcall sub_14002762E()
{
  __int64 v0; // rbp

  (*(void (__fastcall **)(_QWORD))(**(_QWORD **)(v0 + 1328) + 16LL))(*(_QWORD *)(v0 + 1328));
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 528) + 8LL * **(int **)(v0 + 576)))();
}


// ---- sub_140027660 @ 0x140027660 ----
__int64 __fastcall sub_140027660()
{
  __int64 v0; // rbp
  _QWORD *v1; // r14
  int v2; // eax
  int *v3; // rcx

  *(_DWORD *)(v0 + 1320) = 0;
  v2 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int64, __int64, __int64))(**(_QWORD **)(v0 + 1176) + 32LL))(
         *(_QWORD *)(v0 + 1176),
         0xFFFFFFFFLL,
         1,
         v0 + 1336,
         v0 + 1320);
  v3 = *(int **)(v0 + 1128);
  *v3 = v2 >= 0 && *(_DWORD *)(v0 + 1320) != 0 && v2 != 1;
  return (*(__int64 (**)(void))(*v1 + 8LL * *v3))();
}


// ---- sub_1400276D2 @ 0x1400276d2 ----
__int64 __fastcall sub_1400276D2()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 776);
  *v1 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 744) + 8LL * *v1))();
}


// ---- sub_140027714 @ 0x140027714 ----
__int64 __fastcall sub_140027714()
{
  __int64 v0; // rbp
  __int64 v1; // r14

  sub_140001C10(v1);
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 1000) + 8LL * **(int **)(v0 + 1016)))();
}


// ---- sub_14002773E @ 0x14002773e ----
__int64 __fastcall sub_14002773E()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 832);
  *v1 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 808) + 8LL * *v1))();
}


// ---- sub_140027790 @ 0x140027790 ----
__int64 __fastcall sub_140027790(__int16 a1, __int64 a2, __int64 a3, int a4)
{
  int v5; // ebx
  _BYTE *v6; // rsi
  int v7; // ebp
  int v8; // edx
  char v9; // dl

  LOWORD(v5) = a1;
  v6 = (_BYTE *)(a3 + a2 - 1);
  *v6 = 0;
  v7 = a1;
  if ( a1 != 0 )
  {
    nullsub_1();
    if ( a4 == 10 && v7 < 0 )
      LOWORD(v5) = -(__int16)v7;
    while ( (_WORD)v5 != 0 )
    {
      v8 = (unsigned __int16)v5 % a4;
      if ( v8 < 10 )
        v9 = v8 + 48;
      else
        v9 = v8 - 10 + 97;
      *(v6 - 1) = v9;
      v5 = (unsigned __int16)v5 / a4;
      --v6;
    }
    if ( a4 == 10 && v7 < 0 )
      *--v6 = 45;
  }
  else
  {
    *(_BYTE *)(a3 + a2 - 2) = 48;
    return a3 + a2 - 2;
  }
  return (__int64)v6;
}


// ---- sub_140027840 @ 0x140027840 ----
void sub_140027840()
{
  __int64 v0; // rsi
  __int64 v1; // rsi
  int v2; // eax
  __int64 v3; // rdx
  __int64 v4; // r8
  __int64 v5; // r9
  void *v6; // rsp
  __int64 v7; // rdx
  __int64 v8; // rcx
  __int64 v9; // r8
  __int64 v10; // r9
  void *v11; // rsp
  __int64 v12; // rdx
  __int64 v13; // rcx
  __int64 v14; // r8
  __int64 v15; // r9
  void *v16; // rsp
  __int64 v17; // rdx
  __int64 v18; // rcx
  __int64 v19; // r8
  __int64 v20; // r9
  void *v21; // rsp
  __int64 v22; // rdx
  __int64 v23; // rcx
  __int64 v24; // r8
  __int64 v25; // r9
  void *v26; // rsp
  __int64 v27; // rcx
  __int64 v28; // r8
  __int64 v29; // r9
  void *v30; // rsp
  __int64 v31; // rdx
  __int64 v32; // rcx
  __int64 v33; // r8
  __int64 v34; // r9
  void *v35; // rsp
  __int64 v36; // rcx
  __int64 v37; // r8
  __int64 v38; // r9
  void *v39; // rsp
  __int64 v40; // rdx
  __int64 v41; // rcx
  __int64 v42; // r8
  __int64 v43; // r9
  void *v44; // rsp
  __int64 v45; // rdx
  __int64 v46; // rcx
  __int64 v47; // r9
  void *v48; // rsp
  __int64 v49; // rdx
  __int64 v50; // rcx
  __int64 v51; // r8
  void *v52; // rsp
  __int64 v53; // rdx
  __int64 v54; // rcx
  __int64 v55; // r8
  __int64 v56; // r9
  void *v57; // rsp
  __int64 v58; // rdx
  __int64 v59; // rcx
  __int64 v60; // r8
  __int64 v61; // r9
  void *v62; // rsp
  __int64 v63; // rdx
  __int64 v64; // rcx
  __int64 v65; // r8
  __int64 v66; // r9
  void *v67; // rsp
  __int64 v68; // rdx
  __int64 v69; // rcx
  __int64 v70; // r8
  __int64 v71; // r9
  void *v72; // rsp
  __int64 v73; // rdx
  __int64 v74; // rcx
  __int64 v75; // r8
  __int64 v76; // r9
  void *v77; // rsp
  __int64 v78; // rdx
  __int64 v79; // rcx
  __int64 v80; // r8
  __int64 v81; // r9
  void *v82; // rsp
  __int64 v83; // rdx
  __int64 v84; // rcx
  __int64 v85; // r8
  __int64 v86; // r9
  void *v87; // rsp
  __int64 v88; // rdx
  __int64 v89; // rcx
  __int64 v90; // r8
  __int64 v91; // r9
  void *v92; // rsp
  __int64 v93; // rdx
  __int64 v94; // rcx
  __int64 v95; // r8
  __int64 v96; // r9
  void *v97; // rsp
  __int64 v98; // rdx
  __int64 v99; // rcx
  __int64 v100; // r8
  __int64 v101; // r9
  void *v102; // rsp
  __int64 v103; // rdx
  __int64 v104; // rcx
  __int64 v105; // r8
  __int64 v106; // r9
  void *v107; // rsp
  __int64 v108; // rdx
  __int64 v109; // rcx
  __int64 v110; // r8
  __int64 v111; // r9
  void *v112; // rsp
  __int64 v113; // rdx
  __int64 v114; // rcx
  __int64 v115; // r8
  __int64 v116; // r9
  void *v117; // rsp
  __int64 v118; // rdx
  __int64 v119; // rcx
  __int64 v120; // r8
  __int64 v121; // r9
  void *v122; // rsp
  __int64 v123; // rdx
  __int64 v124; // rcx
  __int64 v125; // r8
  __int64 v126; // r9
  void *v127; // rsp
  __int64 v128; // rdx
  __int64 v129; // rcx
  __int64 v130; // r8
  __int64 v131; // r9
  void *v132; // rsp
  __int64 v133; // rdx
  __int64 v134; // rcx
  __int64 v135; // r8
  __int64 v136; // r9
  void *v137; // rsp
  __int64 v138; // rdx
  __int64 v139; // rcx
  __int64 v140; // r8
  __int64 v141; // r9
  void *v142; // rsp
  __int64 v143; // rdx
  __int64 v144; // rcx
  __int64 v145; // r8
  __int64 v146; // r9
  void *v147; // rsp
  __int64 v148; // rdx
  __int64 v149; // rcx
  __int64 v150; // r8
  __int64 v151; // r9
  void *v152; // rsp
  __int64 v153; // rdx
  __int64 v154; // rcx
  __int64 v155; // r8
  __int64 v156; // r9
  void *v157; // rsp
  __int64 v158; // rdx
  __int64 v159; // rcx
  __int64 v160; // r8
  __int64 v161; // r9
  void *v162; // rsp
  __int64 v163; // rdx
  __int64 v164; // rcx
  __int64 v165; // r8
  __int64 v166; // r9
  void *v167; // rsp
  __int64 v168; // rdx
  __int64 v169; // rcx
  __int64 v170; // r8
  __int64 v171; // r9
  void *v172; // rsp
  __int64 v173; // rdx
  __int64 v174; // rcx
  __int64 v175; // r8
  __int64 v176; // r9
  void *v177; // rsp
  __int64 v178; // rdx
  __int64 v179; // rcx
  __int64 v180; // r8
  __int64 v181; // r9
  void *v182; // rsp
  __int64 v183; // rdx
  __int64 v184; // rcx
  __int64 v185; // r8
  __int64 v186; // r9
  void *v187; // rsp
  __int64 v188; // rdx
  __int64 v189; // rcx
  __int64 v190; // r8
  __int64 v191; // r9
  void *v192; // rsp
  __int64 v193; // rdx
  __int64 v194; // rcx
  __int64 v195; // r8
  __int64 v196; // r9
  void *v197; // rsp
  __int64 v198; // rdx
  __int64 v199; // rcx
  __int64 v200; // r8
  __int64 v201; // r9
  void *v202; // rsp
  __int64 v203; // rdx
  __int64 v204; // rcx
  __int64 v205; // r8
  __int64 v206; // r9
  void *v207; // rsp
  __int64 v208; // rdx
  __int64 v209; // rcx
  __int64 v210; // r8
  __int64 v211; // r9
  void *v212; // rsp
  __int64 v213; // rdx
  __int64 v214; // rcx
  __int64 v215; // r8
  __int64 v216; // r9
  void *v217; // rsp
  __int64 v218; // rdx
  __int64 v219; // rcx
  __int64 v220; // r8
  __int64 v221; // r9
  void *v222; // rsp
  __int64 v223; // rdx
  __int64 v224; // rcx
  __int64 v225; // r8
  __int64 v226; // r9
  void *v227; // rsp
  __int64 v228; // rdx
  __int64 v229; // rcx
  __int64 v230; // r8
  __int64 v231; // r9
  void *v232; // rsp
  __int64 v233; // rdx
  __int64 v234; // rcx
  __int64 v235; // r8
  __int64 v236; // r9
  void *v237; // rsp
  __int64 v238; // rdx
  __int64 v239; // rcx
  __int64 v240; // r8
  __int64 v241; // r9
  void *v242; // rsp
  __int64 v243; // rdx
  __int64 v244; // rcx
  __int64 v245; // r8
  __int64 v246; // r9
  void *v247; // rsp
  __int64 v248; // rdx
  __int64 v249; // rcx
  __int64 v250; // r8
  __int64 v251; // r9
  void *v252; // rsp
  __int64 v253; // rdx
  __int64 v254; // rcx
  __int64 v255; // r8
  __int64 v256; // r9
  void *v257; // rsp
  __int64 v258; // rdx
  __int64 v259; // rcx
  __int64 v260; // r8
  __int64 v261; // r9
  void *v262; // rsp
  __int64 v263; // rdx
  __int64 v264; // rcx
  __int64 v265; // r8
  __int64 v266; // r9
  void *v267; // rsp
  __int64 v268; // rdx
  __int64 v269; // rcx
  __int64 v270; // r8
  __int64 v271; // r9
  void *v272; // rsp
  __int64 v273; // rdx
  __int64 v274; // rcx
  __int64 v275; // r8
  __int64 v276; // r9
  void *v277; // rsp
  __int64 v278; // rdx
  __int64 v279; // rcx
  __int64 v280; // r8
  __int64 v281; // r9
  void *v282; // rsp
  __int64 v283; // rdx
  __int64 v284; // rcx
  __int64 v285; // r8
  __int64 v286; // r9
  void *v287; // rsp
  __int64 v288; // rdx
  __int64 v289; // rcx
  __int64 v290; // r8
  __int64 v291; // r9
  void *v292; // rsp
  __int64 v293; // rdx
  __int64 v294; // rcx
  __int64 v295; // r8
  __int64 v296; // r9
  void *v297; // rsp
  __int64 v298; // rdx
  __int64 v299; // rcx
  __int64 v300; // r8
  __int64 v301; // r9
  void *v302; // rsp
  __int64 v303; // rdx
  __int64 v304; // rcx
  __int64 v305; // r8
  __int64 v306; // r9
  void *v307; // rsp
  __int64 v308; // rdx
  __int64 v309; // rcx
  __int64 v310; // r8
  __int64 v311; // r9
  void *v312; // rsp
  __int64 v313; // rdx
  __int64 v314; // rcx
  __int64 v315; // r8
  __int64 v316; // r9
  void *v317; // rsp
  __int64 v318; // rdx
  __int64 v319; // rcx
  __int64 v320; // r8
  __int64 v321; // r9
  void *v322; // rsp
  __int64 v323; // rdx
  __int64 v324; // rcx
  __int64 v325; // r8
  __int64 v326; // r9
  void *v327; // rsp
  __int64 v328; // rdx
  __int64 v329; // rcx
  __int64 v330; // r8
  __int64 v331; // r9
  void *v332; // rsp
  __int64 v333; // rdx
  __int64 v334; // rcx
  __int64 v335; // r8
  __int64 v336; // r9
  void *v337; // rsp
  _DWORD v339[10]; // [rsp+20h] [rbp-80h] BYREF
  _QWORD v340[3]; // [rsp+48h] [rbp-58h] BYREF
  _QWORD v341[2]; // [rsp+60h] [rbp-40h] BYREF
  _QWORD v342[2]; // [rsp+70h] [rbp-30h] BYREF
  __int64 (__fastcall **v343)(); // [rsp+80h] [rbp-20h]
  _DWORD *v344; // [rsp+E8h] [rbp+48h]
  _DWORD *v345; // [rsp+F0h] [rbp+50h]
  _DWORD *v346; // [rsp+F8h] [rbp+58h]
  _DWORD *v347; // [rsp+100h] [rbp+60h]
  _DWORD *v348; // [rsp+108h] [rbp+68h]
  _DWORD *v349; // [rsp+110h] [rbp+70h]
  _DWORD *v350; // [rsp+118h] [rbp+78h]
  _DWORD *v351; // [rsp+120h] [rbp+80h]
  _DWORD *v352; // [rsp+128h] [rbp+88h]
  _DWORD *v353; // [rsp+130h] [rbp+90h]
  _DWORD *v354; // [rsp+138h] [rbp+98h]
  _DWORD *v355; // [rsp+140h] [rbp+A0h]
  _DWORD *v356; // [rsp+148h] [rbp+A8h]
  _DWORD *v357; // [rsp+150h] [rbp+B0h]
  _DWORD *v358; // [rsp+158h] [rbp+B8h]
  _DWORD *v359; // [rsp+160h] [rbp+C0h]
  _DWORD *v360; // [rsp+168h] [rbp+C8h]
  _DWORD *v361; // [rsp+170h] [rbp+D0h]
  _DWORD *v362; // [rsp+178h] [rbp+D8h]
  _DWORD *v363; // [rsp+180h] [rbp+E0h]
  _DWORD *v364; // [rsp+188h] [rbp+E8h]
  _DWORD *v365; // [rsp+190h] [rbp+F0h]
  _DWORD *v366; // [rsp+198h] [rbp+F8h]
  _DWORD *v367; // [rsp+1A0h] [rbp+100h]
  _DWORD *v368; // [rsp+1A8h] [rbp+108h]
  _DWORD *v369; // [rsp+1B0h] [rbp+110h]
  _DWORD *v370; // [rsp+1B8h] [rbp+118h]
  _DWORD *v371; // [rsp+1C0h] [rbp+120h]
  _DWORD *v372; // [rsp+1C8h] [rbp+128h]
  _DWORD *v373; // [rsp+1D0h] [rbp+130h]
  _DWORD *v374; // [rsp+1D8h] [rbp+138h]
  _DWORD *v375; // [rsp+1E0h] [rbp+140h]
  _DWORD *v376; // [rsp+1E8h] [rbp+148h]
  _DWORD *v377; // [rsp+1F0h] [rbp+150h]
  _DWORD *v378; // [rsp+1F8h] [rbp+158h]
  _DWORD *v379; // [rsp+200h] [rbp+160h]
  _DWORD *v380; // [rsp+208h] [rbp+168h]
  _DWORD *v381; // [rsp+210h] [rbp+170h]
  _DWORD *v382; // [rsp+218h] [rbp+178h]
  _DWORD *v383; // [rsp+220h] [rbp+180h]
  _DWORD *v384; // [rsp+228h] [rbp+188h]
  _DWORD *v385; // [rsp+230h] [rbp+190h]
  _DWORD *v386; // [rsp+238h] [rbp+198h]
  _DWORD *v387; // [rsp+240h] [rbp+1A0h]
  _DWORD *v388; // [rsp+248h] [rbp+1A8h]
  _DWORD *v389; // [rsp+250h] [rbp+1B0h]
  _DWORD *v390; // [rsp+258h] [rbp+1B8h]
  _DWORD *v391; // [rsp+260h] [rbp+1C0h]
  _DWORD *v392; // [rsp+268h] [rbp+1C8h]
  _DWORD *v393; // [rsp+270h] [rbp+1D0h]
  _DWORD *v394; // [rsp+278h] [rbp+1D8h]
  _DWORD *v395; // [rsp+280h] [rbp+1E0h]
  _DWORD *v396; // [rsp+288h] [rbp+1E8h]
  _DWORD *v397; // [rsp+290h] [rbp+1F0h]
  _DWORD *v398; // [rsp+298h] [rbp+1F8h]
  _DWORD *v399; // [rsp+2A0h] [rbp+200h]
  __int64 v400; // [rsp+2D8h] [rbp+238h]
  _DWORD *v401; // [rsp+2F0h] [rbp+250h]
  BOOL v402; // [rsp+2FCh] [rbp+25Ch]
  __int64 v403; // [rsp+300h] [rbp+260h] BYREF
  __int64 v404; // [rsp+308h] [rbp+268h] BYREF
  __int64 v405; // [rsp+310h] [rbp+270h] BYREF
  __int64 v406[7]; // [rsp+318h] [rbp+278h] BYREF
  __int64 v407; // [rsp+350h] [rbp+2B0h] BYREF
  int v408; // [rsp+378h] [rbp+2D8h]
  int v409; // [rsp+37Ch] [rbp+2DCh]
  int v410; // [rsp+380h] [rbp+2E0h]
  int v411; // [rsp+384h] [rbp+2E4h]

  v343 = off_14003A618;
  v400 = 0;
  sub_14002A530(&v403);
  v411 = 0;
  while ( 1 )
  {
    nullsub_1();
    nullsub_1();
    if ( v411 != 0 )
      break;
    v411 = 1;
    v403 ^= 0x13696C9DuLL;
  }
  v0 = v403;
  sub_14002A540(&v404);
  v410 = 0;
  while ( v410 == 0 )
  {
    v410 = 1;
    v404 ^= 0xB1A0E64EuLL;
  }
  v341[0] = v0;
  v341[1] = v404;
  sub_14002A550(&v405);
  v409 = 0;
  while ( 1 )
  {
    nullsub_1();
    nullsub_1();
    if ( v409 != 0 )
      break;
    v409 = 1;
    v405 ^= 0x4FD85FFFuLL;
  }
  v1 = v405;
  sub_14002A560(v406);
  v408 = 0;
  while ( v408 == 0 )
  {
    v408 = 1;
    v406[0] = (~(2LL * (v406[0] & 0xEE0FD9B0)) + (v406[0] & 0xEE0FD9B0)) & (v406[0] | 0xEE0FD9B0LL);
  }
  v342[0] = v1;
  v342[1] = v406[0];
  v407 = 0;
  v340[0] = v341;
  v340[1] = v342;
  v340[2] = &v407;
  v2 = sub_14002A570(v340);
  v402 = v2 >= 0;
  v6 = alloca(sub_140001B30(v343[v2 >= 0], v3, v4, v5));
  v11 = alloca(sub_140001B30(v8, v7, v9, v10));
  v399 = v339;
  v16 = alloca(sub_140001B30(v13, v12, v14, v15));
  v21 = alloca(sub_140001B30(v18, v17, v19, v20));
  v398 = v339;
  v26 = alloca(sub_140001B30(v23, v22, v24, v25));
  v394 = v339;
  v30 = alloca(sub_140001B30(v27, v339, v28, v29));
  v395 = v339;
  v35 = alloca(sub_140001B30(v32, v31, v33, v34));
  v396 = v339;
  v39 = alloca(sub_140001B30(v36, jpt_1400299C8, v37, v38));
  v397 = v339;
  v44 = alloca(sub_140001B30(v41, v40, v42, v43));
  v48 = alloca(sub_140001B30(v46, v45, v339, v47));
  v52 = alloca(sub_140001B30(v50, v49, v51, v339));
  v57 = alloca(sub_140001B30(v54, v53, v55, v56));
  v62 = alloca(sub_140001B30(v59, v58, v60, v61));
  v344 = v339;
  v67 = alloca(sub_140001B30(v64, v63, v65, v66));
  v345 = v339;
  v72 = alloca(sub_140001B30(v69, v68, v70, v71));
  v346 = v339;
  v77 = alloca(sub_140001B30(v74, v73, v75, v76));
  v347 = v339;
  v82 = alloca(sub_140001B30(v79, v78, v80, v81));
  v348 = v339;
  v87 = alloca(sub_140001B30(v84, v83, v85, v86));
  v349 = v339;
  v92 = alloca(sub_140001B30(v89, v88, v90, v91));
  v350 = v339;
  v97 = alloca(sub_140001B30(v94, v93, v95, v96));
  v351 = v339;
  v102 = alloca(sub_140001B30(v99, v98, v100, v101));
  v352 = v339;
  v107 = alloca(sub_140001B30(v104, v103, v105, v106));
  v353 = v339;
  v112 = alloca(sub_140001B30(v109, v108, v110, v111));
  v354 = v339;
  v117 = alloca(sub_140001B30(v114, v113, v115, v116));
  v355 = v339;
  v122 = alloca(sub_140001B30(v119, v118, v120, v121));
  v356 = v339;
  v127 = alloca(sub_140001B30(v124, v123, v125, v126));
  v357 = v339;
  v132 = alloca(sub_140001B30(v129, v128, v130, v131));
  v358 = v339;
  v137 = alloca(sub_140001B30(v134, v133, v135, v136));
  v359 = v339;
  v142 = alloca(sub_140001B30(v139, v138, v140, v141));
  v360 = v339;
  v147 = alloca(sub_140001B30(v144, v143, v145, v146));
  v361 = v339;
  v152 = alloca(sub_140001B30(v149, v148, v150, v151));
  v362 = v339;
  v157 = alloca(sub_140001B30(v154, v153, v155, v156));
  v363 = v339;
  v162 = alloca(sub_140001B30(v159, v158, v160, v161));
  v364 = v339;
  v167 = alloca(sub_140001B30(v164, v163, v165, v166));
  v365 = v339;
  v172 = alloca(sub_140001B30(v169, v168, v170, v171));
  v366 = v339;
  v177 = alloca(sub_140001B30(v174, v173, v175, v176));
  v367 = v339;
  v182 = alloca(sub_140001B30(v179, v178, v180, v181));
  v370 = v339;
  v187 = alloca(sub_140001B30(v184, v183, v185, v186));
  v377 = v339;
  v192 = alloca(sub_140001B30(v189, v188, v190, v191));
  v378 = v339;
  v197 = alloca(sub_140001B30(v194, v193, v195, v196));
  v383 = v339;
  v202 = alloca(sub_140001B30(v199, v198, v200, v201));
  v368 = v339;
  v207 = alloca(sub_140001B30(v204, v203, v205, v206));
  v371 = v339;
  v212 = alloca(sub_140001B30(v209, v208, v210, v211));
  v375 = v339;
  v217 = alloca(sub_140001B30(v214, v213, v215, v216));
  v381 = v339;
  v222 = alloca(sub_140001B30(v219, v218, v220, v221));
  v372 = v339;
  v227 = alloca(sub_140001B30(v224, v223, v225, v226));
  v379 = v339;
  v232 = alloca(sub_140001B30(v229, v228, v230, v231));
  v376 = v339;
  v237 = alloca(sub_140001B30(v234, v233, v235, v236));
  v382 = v339;
  v242 = alloca(sub_140001B30(v239, v238, v240, v241));
  v380 = v339;
  v247 = alloca(sub_140001B30(v244, v243, v245, v246));
  v384 = v339;
  v252 = alloca(sub_140001B30(v249, v248, v250, v251));
  v257 = alloca(sub_140001B30(v254, v253, v255, v256));
  v262 = alloca(sub_140001B30(v259, v258, v260, v261));
  v369 = v339;
  v267 = alloca(sub_140001B30(v264, v263, v265, v266));
  v374 = v339;
  v272 = alloca(sub_140001B30(v269, v268, v270, v271));
  v373 = v339;
  v277 = alloca(sub_140001B30(v274, v273, v275, v276));
  v282 = alloca(sub_140001B30(v279, v278, v280, v281));
  v287 = alloca(sub_140001B30(v284, v283, v285, v286));
  v292 = alloca(sub_140001B30(v289, v288, v290, v291));
  v389 = v339;
  v297 = alloca(sub_140001B30(v294, v293, v295, v296));
  v391 = v339;
  v302 = alloca(sub_140001B30(v299, v298, v300, v301));
  v392 = v339;
  v307 = alloca(sub_140001B30(v304, v303, v305, v306));
  v393 = v339;
  v312 = alloca(sub_140001B30(v309, v308, v310, v311));
  v388 = v339;
  v317 = alloca(sub_140001B30(v314, v313, v315, v316));
  v390 = v339;
  v322 = alloca(sub_140001B30(v319, v318, v320, v321));
  v386 = v339;
  v327 = alloca(sub_140001B30(v324, v323, v325, v326));
  v401 = v339;
  v332 = alloca(sub_140001B30(v329, v328, v330, v331));
  v385 = v339;
  v337 = alloca(sub_140001B30(v334, v333, v335, v336));
  v387 = v339;
  v339[0] = 275;
  __asm { jmp     rcx }
}


// ---- sub_1400281A9 @ 0x1400281a9 ----
__int64 __fastcall sub_1400281A9()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 72) + 8LL * **(int **)(v0 + 80)))();
}


// ---- sub_1400281BF @ 0x1400281bf ----
__int64 __fastcall sub_1400281BF()
{
  __int64 v0; // rbp
  __int64 v1; // r13
  int *v2; // rcx

  nullsub_1();
  sub_140001C40(v0 + 712, v0 - 8, 4u);
  *(_BYTE *)(v1 + 16) = *(_BYTE *)(v0 + 713);
  v2 = *(int **)(v0 + 208);
  *v2 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 200) + 8LL * *v2))();
}


// ---- sub_14002825B @ 0x14002825b ----
__int64 __fastcall sub_14002825B()
{
  __int64 v0; // rbp
  __int64 v1; // rdi
  __int64 v2; // rax
  int v3; // eax
  int *v4; // rcx

  *(_QWORD *)(v0 - 24) = v0 + 544;
  VariantClear(*(VARIANTARG **)(v0 - 24));
  *(_QWORD *)(v0 + 8) = v0 - 16;
  VariantInit(*(VARIANTARG **)(v0 + 8));
  v1 = *(_QWORD *)(v0 + 696);
  sub_14002A740(v0 - 114);
  *(_DWORD *)(v0 + 716) = 0;
  while ( 1 )
  {
    nullsub_1();
    nullsub_1();
    if ( *(_DWORD *)(v0 + 716) >= 0xDu )
      break;
    v2 = (int)(*(_DWORD *)(v0 + 716))++;
    *(_WORD *)(v0 + 2 * v2 - 114) ^= (*(_WORD *)(v0 + 716) & 0xBB90) * (*(_WORD *)(v0 + 716) & 0x446F ^ 0x446F)
                                   + (*(_WORD *)(v0 + 716) & 0x446F) * (*(_WORD *)(v0 + 716) | 0x446F);
  }
  v3 = (*(__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, _QWORD))(*(_QWORD *)v1 + 32LL))(
         v1,
         v0 - 114,
         0,
         v0 - 16,
         0,
         0);
  v4 = *(int **)(v0 + 176);
  *v4 = *(_WORD *)(v0 - 16) == 3 && v3 >= 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 168) + 8LL * *v4))();
}


// ---- sub_14002838D @ 0x14002838d ----
__int64 __fastcall sub_14002838D()
{
  __int64 v0; // rbp

  (*(void (__fastcall **)(_QWORD))(**(_QWORD **)(v0 + 656) + 16LL))(*(_QWORD *)(v0 + 656));
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 424) + 8LL * **(int **)(v0 + 440)))();
}


// ---- sub_1400283BF @ 0x1400283bf ----
__int64 __fastcall sub_1400283BF()
{
  __int64 v0; // rbp
  int v1; // eax
  int *v2; // rcx

  *(_DWORD *)(v0 + 708) = 0;
  v1 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int64, __int64, __int64))(**(_QWORD **)(v0 + 656) + 32LL))(
         *(_QWORD *)(v0 + 656),
         0xFFFFFFFFLL,
         1,
         v0 + 696,
         v0 + 708);
  v2 = *(int **)(v0 + 48);
  *v2 = v1 < 0 || *(_DWORD *)(v0 + 708) == 0 || v1 == 1;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 40) + 8LL * *v2))();
}


// ---- sub_140028432 @ 0x140028432 ----
__int64 __fastcall sub_140028432(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rbp
  __int64 v5; // r10
  __int64 v6; // r11
  _QWORD *v7; // r13
  int v8; // eax
  int *v9; // rcx

  *(_QWORD *)(v4 + 64) = v6;
  *(_QWORD *)(v4 + 56) = v5;
  *(_QWORD *)(v4 + 48) = a4;
  *(_QWORD *)(v4 + 40) = a3;
  *(_QWORD *)(v4 + 640) = sub_14002A5A0();
  v8 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, __int64))(**(_QWORD **)(v4 + 688) + 24LL))(
         *(_QWORD *)(v4 + 688),
         *(_QWORD *)(v4 + 640),
         0,
         0,
         0,
         0,
         0,
         0,
         v4 + 648);
  v9 = *(int **)(v4 + 512);
  *v9 = v8 >= 0;
  return (*(__int64 (**)(void))(*v7 + 8LL * *v9))();
}


// ---- sub_1400284CC @ 0x1400284cc ----
__int64 __fastcall sub_1400284CC()
{
  __int64 v0; // rbp
  __int64 (*v1)(void); // rax

  v1 = *(__int64 (**)(void))(**(_QWORD **)(v0 + 488) + 8LL * **(int **)(v0 + 496));
  *(_QWORD *)(v0 + 680) = v0 + 568;
  return v1();
}


// ---- sub_1400284F4 @ 0x1400284f4 ----
__int64 __fastcall sub_1400284F4()
{
  int v0; // eax
  __int64 v1; // rbp
  int *v2; // rdx

  v2 = *(int **)(v1 + 96);
  *v2 = v0 == 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v1 + 88) + 8LL * *v2))();
}


// ---- sub_140028511 @ 0x140028511 ----
__int64 __fastcall sub_140028511()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 192);
  *v1 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 184) + 8LL * *v1))();
}


// ---- sub_14002853E @ 0x14002853e ----
__int64 __fastcall sub_14002853E()
{
  char v0; // al
  __int64 v1; // rbp
  int *v2; // rcx

  v2 = *(int **)(v1 + 144);
  *v2 = v0 & 1;
  return (*(__int64 (**)(void))(**(_QWORD **)(v1 + 136) + 8LL * *v2))();
}


// ---- sub_140028560 @ 0x140028560 ----
__int64 __fastcall sub_140028560()
{
  __int64 v0; // rbp
  unsigned __int8 *v1; // rdi
  __int64 v2; // rdi
  __int64 v3; // rax
  int *v4; // rdx

  v1 = (unsigned __int8 *)sub_14002E070(24);
  sub_140002050(v1, 0, 0x18u);
  **(_QWORD **)(v0 + 680) = v1;
  *(_QWORD *)(v0 + 664) = v0 + 544;
  VariantInit(*(VARIANTARG **)(v0 + 664));
  v2 = *(_QWORD *)(v0 + 696);
  sub_14002A720(v0 + 520);
  for ( *(_DWORD *)(v0 + 720) = 0;
        *(_DWORD *)(v0 + 720) < 0xCu;
        *(_WORD *)(v0 + 2 * v3 + 520) ^= -29104 * (unsigned __int16)*(_DWORD *)(v0 + 720) )
  {
    v3 = (int)(*(_DWORD *)(v0 + 720))++;
  }
  nullsub_1();
  nullsub_1();
  (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, _QWORD))(*(_QWORD *)v2 + 32LL))(
    v2,
    v0 + 520,
    0,
    v0 + 544,
    0,
    0);
  v4 = *(int **)(v0 + 128);
  *v4 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 120) + 8LL * *v4))();
}


// ---- sub_14002869D @ 0x14002869d ----
__int64 __fastcall sub_14002869D()
{
  __int64 v0; // rbp
  _QWORD *v1; // rdi
  int *v2; // r13

  *(_QWORD *)(v0 + 672) = v0 + 640;
  sub_14002A460(*(_QWORD *)(v0 + 672));
  (*(void (__fastcall **)(_QWORD))(**(_QWORD **)(v0 + 688) + 16LL))(*(_QWORD *)(v0 + 688));
  return (*(__int64 (**)(void))(*v1 + 8LL * *v2))();
}


// ---- sub_1400286E4 @ 0x1400286e4 ----
__int64 __fastcall sub_1400286E4()
{
  __int64 v0; // rbp

  (*(void (__fastcall **)(_QWORD))(**(_QWORD **)(v0 + 648) + 16LL))(*(_QWORD *)(v0 + 648));
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 328) + 8LL * **(int **)(v0 + 376)))();
}


// ---- sub_140028716 @ 0x140028716 ----
__int64 __fastcall sub_140028716()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 112);
  *v1 = 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 104) + 8LL * *v1))();
}


// ---- sub_14002873D @ 0x14002873d ----
__int64 __fastcall sub_14002873D()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 392);
  *v1 = 1;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 360) + 8LL * *v1))();
}


// ---- sub_140028771 @ 0x140028771 ----
__int64 __fastcall sub_140028771()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 216) + 8LL * **(int **)(v0 + 224)))();
}


// ---- sub_14002878B @ 0x14002878b ----
__int64 __fastcall sub_14002878B()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 272) + 8LL * **(int **)(v0 + 312)))();
}


// ---- sub_1400287A5 @ 0x1400287a5 ----
__int64 __fastcall sub_1400287A5()
{
  __int64 v0; // rbp
  __int64 v1; // r13
  __int64 v2; // rdi
  _BYTE *v3; // rax

  v2 = sub_140016BE0(*(unsigned __int16 **)(v0 + 552), 0) + 1;
  v3 = (_BYTE *)sub_14002E070(v2);
  *(_QWORD *)(v1 + 8) = v3;
  sub_14000D200(v3, v2, *(unsigned __int16 **)(v0 + 552), 0);
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 152) + 8LL * **(int **)(v0 + 160)))();
}


// ---- sub_14002880C @ 0x14002880c ----
__int64 __fastcall sub_14002880C(__int64 a1, __int64 a2)
{
  __int64 v2; // rbp
  __int64 v3; // r13

  MEMORY[0xCD4B76CF] <<= 21;
  sub_140001C40(v2 + 712, a2, 4u);
  *(_BYTE *)(v3 + 16) = *(_BYTE *)(v2 + 713);
  return (*(__int64 (**)(void))(**(_QWORD **)(v2 + 456) + 8LL * **(int **)(v2 + 464)))();
}


// ---- sub_140028852 @ 0x140028852 ----
__int64 __fastcall sub_140028852()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 248) + 8LL * **(int **)(v0 + 256)))();
}


// ---- sub_14002886C @ 0x14002886c ----
__int64 __fastcall sub_14002886C()
{
  __int64 v0; // rbp

  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 320) + 8LL * **(int **)(v0 + 368)))();
}


// ---- sub_14002888D @ 0x14002888d ----
// positive sp value has been detected, the output may be wrong!
void sub_14002888D()
{
  ;
}


// ---- sub_1400288A1 @ 0x1400288a1 ----
__int64 __fastcall sub_1400288A1()
{
  __int64 v0; // rbp
  int *v1; // rsi

  nullsub_1();
  *v1 = 1;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 304) + 8LL * *v1))();
}


// ---- sub_1400288C7 @ 0x1400288c7 ----
__int64 __fastcall sub_1400288C7()
{
  __int64 v0; // rbp

  *(_QWORD *)(v0 + 24) = v0 + 584;
  sub_14002A460(*(_QWORD *)(v0 + 24));
  *(_QWORD *)(v0 + 32) = v0 + 576;
  sub_14002A460(*(_QWORD *)(v0 + 32));
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 296) + 8LL * **(int **)(v0 + 352)))();
}


// ---- sub_140028919 @ 0x140028919 ----
__int64 __fastcall sub_140028919()
{
  int *v0; // r14
  _QWORD *v1; // r15

  nullsub_1();
  *v0 = 1;
  return (*(__int64 (**)(void))(*v1 + 8LL * *v0))();
}


// ---- sub_140028940 @ 0x140028940 ----
__int64 __fastcall sub_140028940()
{
  __int64 v0; // rbp
  int *v1; // rcx

  nullsub_1();
  v1 = *(int **)(v0 + 384);
  *v1 = 1;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 344) + 8LL * *v1))();
}


// ---- sub_14002897B @ 0x14002897b ----
__int64 __fastcall sub_14002897B()
{
  __int64 v0; // rbp
  __int64 v1; // r13
  __int64 (*v2)(void); // rcx

  *(_QWORD *)(v0 + 16) = v0 - 16;
  VariantClear(*(VARIANTARG **)(v0 + 16));
  (*(void (__fastcall **)(_QWORD))(**(_QWORD **)(v0 + 696) + 16LL))(*(_QWORD *)(v0 + 696));
  v2 = *(__int64 (**)(void))(**(_QWORD **)(v0 + 232) + 8LL * **(int **)(v0 + 240));
  *(_QWORD *)(v0 + 680) = v1;
  return v2();
}


// ---- sub_1400289CF @ 0x1400289cf ----
__int64 __fastcall sub_1400289CF()
{
  __int64 v0; // rbp
  int v1; // eax
  int *v2; // rcx

  *(_QWORD *)(v0 + 576) = sub_14002A620();
  *(_QWORD *)(v0 + 584) = sub_14002A690();
  v1 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD, __int64, _QWORD, __int64))(**(_QWORD **)(v0 + 648) + 160LL))(
         *(_QWORD *)(v0 + 648),
         *(_QWORD *)(v0 + 576),
         *(_QWORD *)(v0 + 584),
         48,
         0,
         v0 + 656);
  v2 = *(int **)(v0 + 480);
  *v2 = v1 >= 0;
  return (*(__int64 (**)(void))(**(_QWORD **)(v0 + 472) + 8LL * *v2))();
}


// ---- sub_140028A5C @ 0x140028a5c ----
__int64 __fastcall sub_140028A5C()
{
  __int64 v0; // rbp
  _QWORD *v1; // rdi
  HRESULT v2; // eax
  int *v3; // rcx

  v2 = CoSetProxyBlanket(*(IUnknown **)(v0 + 648), 0xAu, 0, nullptr, 3u, 3u, nullptr, 0);
  v3 = *(int **)(v0 + 504);
  *v3 = v2 >= 0;
  return (*(__int64 (**)(void))(*v1 + 8LL * *v3))();
}


// ---- sub_140028CA0 @ 0x140028ca0 ----
__int64 __fastcall sub_140028CA0(_QWORD *a1)
{
  __int64 v2; // rdi
  __int64 result; // rax
  __int64 v4; // rcx

  v2 = *a1;
  if ( *a1 != 0 )
  {
    sub_140028CA0(*a1);
    result = sub_140001C10(v2);
  }
  v4 = a1[1];
  if ( v4 != 0 )
    return sub_140001C10(v4);
  return result;
}


// ---- sub_140028CE0 @ 0x140028ce0 ----
_BYTE *__fastcall sub_140028CE0(int a1, __int64 a2, __int64 a3, int a4)
{
  _BYTE *v4; // r10
  _BYTE *result; // rax
  int v6; // edx
  char v7; // dl

  v4 = (_BYTE *)(a3 + a2 - 1);
  *v4 = 0;
  if ( (_WORD)a1 != 0 )
  {
    while ( (_WORD)a1 != 0 )
    {
      v6 = (unsigned __int16)a1 % a4;
      if ( v6 < 10 )
        v7 = v6 + 48;
      else
        v7 = v6 - 10 + 97;
      *(v4 - 1) = v7;
      a1 = (unsigned __int16)a1 / a4;
      --v4;
    }
    return v4;
  }
  else
  {
    result = (_BYTE *)(a3 + a2 - 2);
    *result = 48;
  }
  return result;
}


// ---- sub_140028D50 @ 0x140028d50 ----
__int64 __fastcall sub_140028D50(_QWORD *a1)
{
  __int64 v2; // rdi
  __int64 result; // rax
  __int64 v4; // rcx

  v2 = *a1;
  if ( *a1 != 0 )
  {
    sub_140028D50(*a1);
    result = sub_140001C10(v2);
  }
  v4 = a1[1];
  if ( v4 != 0 )
    return sub_140001C10(v4);
  return result;
}


// ---- sub_140028D90 @ 0x140028d90 ----
_BYTE *__fastcall sub_140028D90(unsigned int a1, __int64 a2, __int64 a3, unsigned int a4)
{
  _BYTE *v4; // r10
  _BYTE *result; // rax
  int v6; // edx
  char v7; // dl

  v4 = (_BYTE *)(a3 + a2 - 1);
  *v4 = 0;
  if ( a1 != 0 )
  {
    while ( a1 != 0 )
    {
      v6 = a1 % a4;
      if ( a1 % a4 < 0xA )
        v7 = v6 + 48;
      else
        v7 = v6 - 10 + 97;
      *(v4 - 1) = v7;
      a1 /= a4;
      --v4;
    }
    return v4;
  }
  else
  {
    result = (_BYTE *)(a3 + a2 - 2);
    *result = 48;
  }
  return result;
}


// ---- sub_140028DF0 @ 0x140028df0 ----
char __fastcall sub_140028DF0(__int64 a1)
{
  __int64 v2; // rsi
  unsigned int (__fastcall *v3)(_QWORD); // rax
  char v4; // bl
  __int64 (__fastcall *v5)(__int64); // rax
  unsigned __int16 *v6; // rax
  unsigned __int16 *v7; // r12
  unsigned __int64 v8; // r14
  _BYTE *v9; // r15
  __int64 v10; // rax
  void (*v11)(void); // rax
  unsigned int i; // [rsp+24h] [rbp-64h]
  __int64 v14; // [rsp+28h] [rbp-60h] BYREF
  _BYTE v15[14]; // [rsp+32h] [rbp-56h] BYREF
  __int64 *v16; // [rsp+40h] [rbp-48h]
  __int64 *v17; // [rsp+48h] [rbp-40h]

  v2 = sub_14002F7D0(272198096);
  v3 = (unsigned int (__fastcall *)(_QWORD))sub_14002FDC0(v2, 4101680061LL);
  v4 = 0;
  if ( v3(0) != 0 )
  {
    v5 = (__int64 (__fastcall *)(__int64))sub_14002FDC0(v2, 3214652975LL);
    v14 = v5(13);
    v4 = 0;
    if ( v14 != 0 )
    {
      v17 = &v14;
      v6 = (unsigned __int16 *)sub_140028F70(&v14);
      v7 = v6;
      v4 = 0;
      if ( v6 != nullptr )
      {
        v8 = sub_140016BE0(v6, 0);
        v4 = 0;
        if ( v8 != 0 )
        {
          v9 = (_BYTE *)sub_14002E070(v8 + 1);
          sub_14000D200(v9, v8 + 1, v7, 0);
          sub_140028F80(v15);
          for ( i = 0; i < 0xE; v15[v10] ^= 67 * (_BYTE)i )
          {
            nullsub_1();
            nullsub_1();
            v10 = (int)i++;
          }
          v4 = sub_140003370(a1, (__int64)v15, (__int64)v9, v8) & 1;
          sub_140001C10(v9);
        }
        v16 = &v14;
        sub_140028FA0(&v14);
      }
    }
    v11 = (void (*)(void))sub_14002FDC0(v2, 1474314631);
    v11();
  }
  return v4;
}


// ---- sub_140028F70 @ 0x140028f70 ----
LPVOID __fastcall sub_140028F70(HGLOBAL *a1)
{
  return GlobalLock(*a1);
}


// ---- sub_140028F80 @ 0x140028f80 ----
__int64 __fastcall sub_140028F80(_QWORD *a1)
{
  *(_QWORD *)((char *)a1 + 6) = 0xAA135C95B03F6AB4uLL;
  *a1 = 0x6AB4FD2D7CA0EA00LL;
  return 0x6AB4FD2D7CA0EA00LL;
}


// ---- sub_140028FA0 @ 0x140028fa0 ----
BOOL __fastcall sub_140028FA0(HGLOBAL *a1)
{
  return GlobalUnlock(*a1);
}


// ---- sub_140028FB0 @ 0x140028fb0 ----
// local variable allocation has failed, the output may be wrong!
char __fastcall sub_140028FB0(
        _BYTE *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        unsigned __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        unsigned __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43,
        __int64 a44,
        __int64 a45,
        __int64 a46,
        __int64 a47,
        __int64 a48,
        __int64 a49,
        __int64 a50,
        __int64 a51,
        __int64 a52,
        __int64 a53,
        __int64 a54,
        __int64 a55,
        __int64 a56,
        __int64 a57,
        __int64 a58,
        __int64 a59,
        __int64 a60,
        __int64 a61,
        __int64 a62,
        __int64 a63,
        unsigned int j)
{
  char *v64; // rax
  int v65; // ecx
  unsigned __int64 *v66; // r8
  __int64 v67; // r10
  unsigned __int64 v68; // r11
  __int64 v69; // r9
  unsigned __int64 v70; // rcx
  __int64 v71; // rdx
  char v72; // si
  unsigned __int64 v73; // rdi
  _WORD *v74; // r13
  char v75; // r8
  char *v76; // rax
  unsigned __int64 v77; // rsi
  _WORD *v78; // rbp
  char v79; // cl
  char *v80; // rax
  _WORD *v81; // rdi
  char v82; // cl
  char *v83; // rax
  char v84; // cl
  __int64 v85; // rdx
  __int64 v86; // rcx
  __int64 v87; // r8
  __int64 v88; // r9
  int v89; // eax
  __int64 v90; // rdx
  int v91; // r8d
  char v92; // cl
  unsigned __int64 v93; // r8
  __int64 v94; // rax
  int v95; // eax
  char v96; // cl
  int v97; // eax
  unsigned __int64 *v98; // rax
  __int64 v99; // rcx
  char *v100; // rax
  char v101; // cl
  signed int v102; // eax
  unsigned __int64 *v103; // rax
  char v104; // cl
  char *v105; // rax
  char v106; // cl
  char v107; // al
  int v108; // eax
  unsigned __int64 *v109; // rax
  char v110; // cl
  char *v111; // rax
  char v112; // cl
  char v113; // al
  int v114; // eax
  unsigned __int64 *v115; // rax
  char v116; // cl
  bool v117; // zf
  char *v118; // r9
  int v119; // r8d
  unsigned __int64 v120; // r15
  unsigned __int64 *v121; // r8
  unsigned __int64 v122; // r10
  char v123; // r11
  char v124; // r11
  __int64 v125; // r9
  int v126; // r9d
  int v127; // r9d
  int v128; // r9d
  unsigned __int64 *v129; // r9
  int v130; // r10d
  unsigned __int64 *v131; // r10
  char v132; // r11
  char v133; // r8
  char *v134; // rax
  _BYTE *v135; // rbx
  char v136; // cl
  unsigned __int64 *v137; // rax
  int v138; // ecx
  unsigned __int64 *v139; // rcx
  char v140; // dl
  char v141; // cl
  unsigned __int64 *v142; // rax
  int v143; // ecx
  unsigned int v144; // edx
  int v145; // r8d
  unsigned int v146; // r9d
  int v147; // edx
  __int64 v148; // r9
  __int64 v149; // r8
  unsigned __int64 *v150; // rcx
  __int64 v151; // rdx
  __int64 v152; // rcx
  int v153; // eax
  int v154; // eax
  unsigned __int64 v155; // rbx
  char v156; // al
  unsigned int v157; // r8d
  char v158; // al
  signed int v159; // eax
  _BYTE *v160; // r15
  unsigned __int64 *v161; // rax
  char v162; // cl
  __int64 v163; // rdx
  __int64 v164; // rcx
  __int64 v165; // r8
  __int64 v166; // r9
  __int64 v167; // rdx
  __int64 v168; // rcx
  __int64 v169; // r8
  __int64 v170; // r9
  void *v171; // rsp
  __int64 v172; // rdx
  __int64 v173; // rcx
  __int64 v174; // r8
  __int64 v175; // r9
  void *v176; // rsp
  __int64 v177; // rdx
  __int64 v178; // rcx
  __int64 v179; // r8
  __int64 v180; // r9
  void *v181; // rsp
  __int64 v182; // rdx
  __int64 v183; // rcx
  __int64 v184; // r8
  __int64 v185; // r9
  void *v186; // rsp
  __int64 v187; // rdx
  __int64 v188; // rcx
  __int64 v189; // r8
  __int64 v190; // r9
  void *v191; // rsp
  __int64 v192; // rdx
  __int64 v193; // rcx
  __int64 v194; // r8
  __int64 v195; // r9
  void *v196; // rsp
  __int64 v197; // rdx
  __int64 v198; // rcx
  __int64 v199; // r8
  __int64 v200; // r9
  void *v201; // rsp
  __int64 v202; // rdx
  __int64 v203; // rcx
  __int64 v204; // r8
  __int64 v205; // r9
  void *v206; // rsp
  __int64 v207; // rdx
  __int64 v208; // rcx
  __int64 v209; // r8
  __int64 v210; // r9
  void *v211; // rsp
  __int64 v212; // rdx
  __int64 v213; // rcx
  __int64 v214; // r8
  __int64 v215; // r9
  void *v216; // rsp
  __int64 v217; // rdx
  __int64 v218; // rcx
  __int64 v219; // r8
  __int64 v220; // r9
  void *v221; // rsp
  __int64 v222; // rdx
  __int64 v223; // rcx
  __int64 v224; // r8
  __int64 v225; // r9
  void *v226; // rsp
  __int64 v227; // rdx
  __int64 v228; // rcx
  __int64 v229; // r8
  __int64 v230; // r9
  void *v231; // rsp
  __int64 v232; // rdx
  __int64 v233; // rcx
  __int64 v234; // r8
  __int64 v235; // r9
  void *v236; // rsp
  __int64 v237; // rdx
  __int64 v238; // rcx
  __int64 v239; // r8
  __int64 v240; // r9
  void *v241; // rsp
  __int64 v242; // rdx
  __int64 v243; // rcx
  __int64 v244; // r8
  __int64 v245; // r9
  void *v246; // rsp
  __int64 v247; // rdx
  __int64 v248; // rcx
  __int64 v249; // r8
  __int64 v250; // r9
  void *v251; // rsp
  __int64 v252; // rdx
  __int64 v253; // rcx
  __int64 v254; // r8
  __int64 v255; // r9
  void *v256; // rsp
  __int64 v257; // rdx
  __int64 v258; // rcx
  __int64 v259; // r8
  __int64 v260; // r9
  void *v261; // rsp
  __int64 v262; // rdx
  __int64 v263; // rcx
  __int64 v264; // r8
  __int64 v265; // r9
  void *v266; // rsp
  __int64 v267; // rdx
  __int64 v268; // rcx
  __int64 v269; // r8
  __int64 v270; // r9
  void *v271; // rsp
  __int64 v272; // rdx
  __int64 v273; // rcx
  __int64 v274; // r8
  __int64 v275; // r9
  void *v276; // rsp
  __int64 v277; // rdx
  __int64 v278; // rcx
  __int64 v279; // r8
  __int64 v280; // r9
  void *v281; // rsp
  __int64 v282; // rdx
  __int64 v283; // rcx
  __int64 v284; // r8
  __int64 v285; // r9
  void *v286; // rsp
  __int64 v287; // rdx
  __int64 v288; // rcx
  __int64 v289; // r8
  __int64 v290; // r9
  void *v291; // rsp
  __int64 v292; // rdx
  __int64 v293; // rcx
  __int64 v294; // r8
  __int64 v295; // r9
  void *v296; // rsp
  __int64 v297; // rdx
  __int64 v298; // rcx
  __int64 v299; // r8
  __int64 v300; // r9
  void *v301; // rsp
  __int64 v302; // rdx
  __int64 v303; // rcx
  __int64 v304; // r8
  __int64 v305; // r9
  void *v306; // rsp
  _QWORD *v307; // rbx
  _QWORD *v308; // rax
  _UNKNOWN ***v309; // r12
  _UNKNOWN **v310; // r13
  _QWORD *v311; // rax
  _QWORD *v312; // rcx
  __int64 v313; // rax
  __int64 *v314; // rdi
  _QWORD *v315; // rax
  __int64 v316; // rax
  unsigned __int64 *p_j; // r14
  __int64 v318; // rdx
  unsigned __int64 v319; // rdi
  _QWORD *v320; // r13
  char v321; // al
  _QWORD *v322; // rsi
  __int64 **v323; // r12
  _QWORD *v324; // rdi
  _QWORD *v325; // r14
  _BYTE *v326; // rsi
  unsigned __int64 v327; // r15
  __int64 v328; // r12
  __int64 v329; // rax
  __int64 v330; // rcx
  bool v331; // dl
  __int64 v332; // rbx
  char result; // al
  _UNKNOWN **v334; // [rsp+20h] [rbp-80h] BYREF
  _UNKNOWN ***v335; // [rsp+28h] [rbp-78h]
  _UNKNOWN **v336; // [rsp+30h] [rbp-70h]
  _UNKNOWN ***v337; // [rsp+38h] [rbp-68h]
  _UNKNOWN **v338; // [rsp+40h] [rbp-60h]
  _UNKNOWN **v339; // [rsp+48h] [rbp-58h]
  _UNKNOWN **v340; // [rsp+50h] [rbp-50h]
  _UNKNOWN **v341; // [rsp+58h] [rbp-48h]
  _UNKNOWN **v342; // [rsp+60h] [rbp-40h]
  _UNKNOWN **v343; // [rsp+68h] [rbp-38h]
  _UNKNOWN **v344; // [rsp+70h] [rbp-30h]
  _UNKNOWN **v345; // [rsp+78h] [rbp-28h]
  _BYTE *v346; // [rsp+80h] [rbp-20h]
  _UNKNOWN ***v347; // [rsp+88h] [rbp-18h]
  __int64 **v348; // [rsp+90h] [rbp-10h]
  _UNKNOWN ***v349; // [rsp+98h] [rbp-8h]
  _UNKNOWN ***v350; // [rsp+A0h] [rbp+0h]
  _DWORD *v351; // [rsp+A8h] [rbp+8h]
  _QWORD *v352; // [rsp+B0h] [rbp+10h]
  _DWORD *v353; // [rsp+B8h] [rbp+18h]
  _UNKNOWN ***v354; // [rsp+E0h] [rbp+40h]
  _UNKNOWN ***v355; // [rsp+F0h] [rbp+50h]
  _QWORD *v356; // [rsp+100h] [rbp+60h]
  _QWORD *v357; // [rsp+118h] [rbp+78h]
  _UNKNOWN ***v358; // [rsp+120h] [rbp+80h]
  _QWORD *v359; // [rsp+130h] [rbp+90h]
  unsigned __int64 *v360; // [rsp+140h] [rbp+A0h]
  _UNKNOWN ***v361; // [rsp+148h] [rbp+A8h]
  _DWORD *v362; // [rsp+150h] [rbp+B0h]
  _DWORD *v363; // [rsp+158h] [rbp+B8h]
  int v364; // [rsp+170h] [rbp+D0h]
  int v365; // [rsp+174h] [rbp+D4h]
  int v366; // [rsp+178h] [rbp+D8h]
  int v367; // [rsp+17Ch] [rbp+DCh]
  int v368; // [rsp+180h] [rbp+E0h]
  int v369; // [rsp+184h] [rbp+E4h]
  int v370; // [rsp+188h] [rbp+E8h]
  int v371; // [rsp+18Ch] [rbp+ECh]
  int v372; // [rsp+190h] [rbp+F0h]
  int v373; // [rsp+194h] [rbp+F4h]
  int v374; // [rsp+198h] [rbp+F8h]
  int v375; // [rsp+19Ch] [rbp+FCh]
  __int64 *v376; // [rsp+1A0h] [rbp+100h]
  __int64 *v377; // [rsp+1A8h] [rbp+108h]
  unsigned int i; // [rsp+1B0h] [rbp+110h]
  _UNKNOWN *retaddr; // [rsp+1F8h] [rbp+158h]

  v346 = a1;
  v334 = jpt_14002908C;
  nullsub_1();
  v364 = 0;
  v335 = (_UNKNOWN ***)jpt_140029405;
  v336 = jpt_140029900;
  v337 = (_UNKNOWN ***)jpt_14002951B;
  v338 = jpt_1400295AE;
  v339 = jpt_1400294EF;
  v340 = jpt_1400299C8;
  v370 = 288;
  v341 = jpt_1400294D3;
  v342 = jpt_14002949B;
  v343 = jpt_1400299C8;
  v373 = 282;
  v344 = jpt_1400299C8;
  v374 = 285;
  v345 = jpt_1400299C8;
  v375 = 289;
  switch ( (unsigned __int64)jpt_1400299C8 )
  {
    case 0uLL:
      nullsub_1();
      v171 = alloca(sub_140001B30(v168, v167, v169, v170));
      v362 = &v334;
      v176 = alloca(sub_140001B30(v173, v172, v174, v175));
      v181 = alloca(sub_140001B30(v178, v177, v179, v180));
      v363 = &v334;
      v186 = alloca(sub_140001B30(v183, v182, v184, v185));
      v191 = alloca(sub_140001B30(v188, v187, v189, v190));
      v196 = alloca(sub_140001B30(v193, v192, v194, v195));
      v201 = alloca(sub_140001B30(v198, v197, v199, v200));
      v206 = alloca(sub_140001B30(v203, v202, v204, v205));
      v211 = alloca(sub_140001B30(v208, v207, v209, v210));
      v216 = alloca(sub_140001B30(v213, v212, v214, v215));
      v221 = alloca(sub_140001B30(v218, v217, v219, v220));
      v352 = &v334;
      v226 = alloca(sub_140001B30(v223, v222, v224, v225));
      v351 = &v334;
      v231 = alloca(sub_140001B30(v228, v227, v229, v230));
      v353 = &v334;
      v236 = alloca(sub_140001B30(v233, v232, v234, v235));
      v358 = &v334;
      v241 = alloca(sub_140001B30(v238, v237, v239, v240));
      v356 = &v334;
      v246 = alloca(sub_140001B30(v243, v242, v244, v245));
      v376 = (__int64 *)&v334;
      v251 = alloca(sub_140001B30(v248, v247, v249, v250));
      v357 = &v334;
      v256 = alloca(sub_140001B30(v253, v252, v254, v255));
      v377 = (__int64 *)&v334;
      v261 = alloca(sub_140001B30(v258, v257, v259, v260));
      v359 = &v334;
      v266 = alloca(sub_140001B30(v263, v262, v264, v265));
      v271 = alloca(sub_140001B30(v268, v267, v269, v270));
      v355 = &v334;
      v276 = alloca(sub_140001B30(v273, v272, v274, v275));
      v360 = (unsigned __int64 *)&v334;
      v281 = alloca(sub_140001B30(v278, v277, v279, v280));
      v354 = &v334;
      v286 = alloca(sub_140001B30(v283, v282, v284, v285));
      v291 = alloca(sub_140001B30(v288, v287, v289, v290));
      v347 = &v334;
      v296 = alloca(sub_140001B30(v293, v292, v294, v295));
      v348 = (__int64 **)&v334;
      v301 = alloca(sub_140001B30(v298, v297, v299, v300));
      v349 = &v334;
      v306 = alloca(sub_140001B30(v303, v302, v304, v305));
      v350 = &v334;
      *v362 = sub_140029A60();
      *v363 = sub_140029A70();
      sub_140029A80();
      v334 = (_UNKNOWN **)&v334;
      sub_140029A90(&v334);
      v334 = (_UNKNOWN **)&v334;
      v335 = &v334;
      v307 = v358;
      sub_140029AA0(&v334, &v334);
      v308 = v352;
      *v352 = &v334;
      sub_140029AC0(*v308);
      v309 = (_UNKNOWN ***)v351;
      *v351 = HIDWORD(v334);
      v310 = (_UNKNOWN **)v353;
      *v353 = (_DWORD)v335;
      v311 = v356;
      *v356 = &v334;
      *v307 = sub_140029AD0(*v311);
      v312 = v357;
      *v357 = &v334;
      v312[1] = v309;
      v312[2] = v310;
      v313 = sub_140029AE0();
      v314 = v376;
      *v376 = v313;
      v315 = v359;
      *v359 = v307;
      v315[1] = v314;
      v316 = sub_140029B00(*v315, v315[1]);
      *v377 = v316;
      p_j = v360;
      v334 = (_UNKNOWN **)v307;
      v335 = v309;
      v336 = v310;
      v361 = &v334;
      v337 = &v334;
      v338 = (_UNKNOWN **)v362;
      v339 = (_UNKNOWN **)v363;
      sub_140029B10(&v334);
      v318 = *v314;
      v319 = (unsigned __int64)v355;
      v320 = v307;
      v321 = sub_140029B70(*v307, v318, v355, p_j);
      v365 = 1;
      v332 = (__int64)v354;
      v366 = v321 & 1;
      LOBYTE(v327) = 0;
      switch ( v321 & 1 )
      {
        case 0:
LABEL_3:
          nullsub_1();
          v371 = 1;
          v322 = v347;
          v323 = v348;
          v324 = v349;
          v325 = v350;
          nullsub_1();
          *v322 = v320;
          v322[1] = v377;
          sub_140029B00(*v322, v322[1]);
          *v323 = v376;
          sub_140029AC0(*v323);
          *v324 = v320;
          sub_14002A010(*v324);
          *v325 = v361;
          sub_14002A020(*v325);
          v372 = 0;
          result = v327 & 1;
          break;
        case 1:
          nullsub_1();
          v367 = 0;
          v326 = v346;
          v327 = *p_j;
          v328 = *(_QWORD *)v319;
          sub_140029FF0(v332);
          for ( i = 0; i < 0xF; *(_BYTE *)(v332 + v329) ^= 2 * (_BYTE)i )
            v329 = (int)i++;
          LOBYTE(v327) = sub_140003370((__int64)v326, v332, v328, v327);
          v330 = *(_QWORD *)v319;
          v331 = *(_QWORD *)v319 == 0;
          v368 = 0;
          v369 = v331;
          switch ( v331 )
          {
            case false:
              sub_140001C10(v330);
              v117 = &v334 == nullptr;
              v94 = v370;
              switch ( v370 )
              {
                case 0:
                  JUMPOUT(0x140020690LL);
                case 1:
                  JUMPOUT(0x1400205FCLL);
                case 2:
                  JUMPOUT(0x140020611LL);
                case 3:
                  JUMPOUT(0x14002092FLL);
                case 4:
                  JUMPOUT(0x1400209B1LL);
                case 5:
                  JUMPOUT(0x140020B94LL);
                case 6:
                  v64 = (char *)STACK[0x508];
                  *(unsigned __int64 *)((char *)&a30 + 5) = 0x258C09D42EA13CA4LL;
                  a30 = 0xA13CA438924BD273uLL;
                  LODWORD(retaddr) = 0;
                  do
                  {
                    v65 = (int)retaddr;
                    LODWORD(retaddr) = (_DWORD)retaddr + 1;
                    *((_BYTE *)&a30 + v65) ^= ((unsigned __int8)retaddr & 0x86)
                                            * ((unsigned __int8)retaddr & 0x79 ^ 0x79)
                                            + ((unsigned __int8)retaddr & 0x79) * ((unsigned __int8)retaddr | 0x79);
                  }
                  while ( (unsigned int)retaddr < 0xD );
                  v66 = &a30;
                  v67 = v332;
                  v68 = v327;
                  v69 = v328;
                  do
                  {
                    v70 = v68;
                    v71 = v67;
                    v72 = *(_BYTE *)v66;
                    v66 = (unsigned __int64 *)((char *)v66 + 1);
                    *(_BYTE *)++v69 = v72;
                    ++v68;
                    ++v67;
                  }
                  while ( v72 != 0 );
                  do
                  {
                    v73 = v70;
                    v74 = (_WORD *)v71;
                    v75 = *v64++;
                    *(_BYTE *)(v70 - 4) = v75;
                    ++v70;
                    ++v71;
                  }
                  while ( v75 != 0 );
                  *(_WORD *)(v70 - 5) = 10272;
                  v76 = (char *)sub_140006830(STACK[0x4F8], (__int64)&j, 11, 0xAu);
                  do
                  {
                    v77 = v73;
                    v78 = v74;
                    v79 = *v76++;
                    *(_BYTE *)(v73 - 2) = v79;
                    ++v73;
                    v74 = (_WORD *)((char *)v74 + 1);
                  }
                  while ( v79 != 0 );
                  *(_BYTE *)(v73 - 3) = 46;
                  v80 = (char *)sub_140006830(STACK[0x4FC], (__int64)&j, 11, 0xAu);
                  do
                  {
                    v81 = v78;
                    v82 = *v80++;
                    *(_BYTE *)(v77++ - 1) = v82;
                    v78 = (_WORD *)((char *)v78 + 1);
                  }
                  while ( v82 != 0 );
                  *(_BYTE *)(v77 - 2) = 46;
                  v83 = (char *)sub_140006830(STACK[0x500], (__int64)&j, 11, 0xAu);
                  do
                  {
                    v84 = *v83++;
                    *((_BYTE *)v81 + 1) = v84;
                    v81 = (_WORD *)((char *)v81 + 1);
                  }
                  while ( v84 != 0 );
                  *v81 = 8233;
                  sub_1400302C0();
                  return off_140039E00(
                           v86,
                           v85,
                           v87,
                           v88,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9,
                           a10,
                           a11,
                           a12,
                           a13,
                           a14,
                           a15,
                           a16,
                           a17,
                           a18,
                           a19,
                           a20,
                           a21,
                           a22,
                           a23,
                           a24,
                           a25,
                           a26);
                case 7:
                  switch ( v370 == 1 )
                  {
                    case false:
                      goto LABEL_23;
                    case true:
                      goto LABEL_26;
                  }
                case 8:
LABEL_26:
                  LODWORD(a8) = -793879732;
                  LODWORD(a30) = 0;
                  do
                  {
                    v95 = a30;
                    LODWORD(a30) = a30 + 1;
                    *((_BYTE *)&a8 + v95) ^= 52 * (_BYTE)a30;
                  }
                  while ( (unsigned int)a30 < 4 );
                  v94 = (__int64)&a8;
                  goto LABEL_29;
                case 9:
LABEL_23:
                  LODWORD(a26) = -999828471;
                  LODWORD(a30) = 0;
                  do
                  {
                    v89 = a30;
                    LODWORD(a30) = a30 + 1;
                    v90 = (unsigned __int8)a30 & 0x8E;
                    v91 = a30 & 0x71;
                    v92 = v91 * (a30 | 0x71);
                    v93 = (unsigned int)v90 * (v91 ^ 0x71);
                    *((_BYTE *)&a26 + v89) ^= (_BYTE)v93 + v92;
                  }
                  while ( (unsigned int)a30 < 4 );
                  v94 = (__int64)&a26;
                  goto LABEL_29;
                case 10:
                  do
                  {
LABEL_29:
                    v96 = *(_BYTE *)v94++;
                    *(_BYTE *)(v319 + 2) = v96;
                    ++v319;
                  }
                  while ( v96 != 0 );
                  *(_OWORD *)&a30 = xmmword_1400348F1;
                  LOWORD(a32) = 6319;
                  LODWORD(retaddr) = 0;
                  do
                  {
                    v97 = (int)retaddr;
                    LODWORD(retaddr) = (_DWORD)retaddr + 1;
                    *((_BYTE *)&a30 + v97) ^= 44 * (_BYTE)retaddr;
                  }
                  while ( (unsigned int)retaddr < 0x12 );
                  v98 = &a30;
                  do
                  {
                    v99 = *(unsigned __int8 *)v98;
                    v98 = (unsigned __int64 *)((char *)v98 + 1);
                    *(_BYTE *)++v319 = v99;
                  }
                  while ( (_BYTE)v99 != 0 );
                  switch ( SLOWORD(STACK[0x524]) >= 0 )
                  {
                    case false:
                      return off_140039E28(
                               v99,
                               v90,
                               v93,
                               v125,
                               a5,
                               a6,
                               a7,
                               a8,
                               a9,
                               a10,
                               a11,
                               a12,
                               a13,
                               a14,
                               a15,
                               a16,
                               a17,
                               a18,
                               a19,
                               a20,
                               a21,
                               a22,
                               a23,
                               a24,
                               a25,
                               a26,
                               a27);
                    case true:
                      goto LABEL_36;
                  }
                case 11:
LABEL_36:
                  *(_BYTE *)v319 = 43;
                  return off_140039E28(
                           v99,
                           v90,
                           v93,
                           v125,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9,
                           a10,
                           a11,
                           a12,
                           a13,
                           a14,
                           a15,
                           a16,
                           a17,
                           a18,
                           a19,
                           a20,
                           a21,
                           a22,
                           a23,
                           a24,
                           a25,
                           a26,
                           a27);
                case 12:
                  return off_140039E28(
                           v99,
                           v90,
                           v93,
                           v125,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9,
                           a10,
                           a11,
                           a12,
                           a13,
                           a14,
                           a15,
                           a16,
                           a17,
                           a18,
                           a19,
                           a20,
                           a21,
                           a22,
                           a23,
                           a24,
                           a25,
                           a26,
                           a27);
                case 13:
                  v134 = (char *)sub_140027790(STACK[0x524], (__int64)&j, 11, 10);
                  v135 = (_BYTE *)(v319 - 5);
                  do
                  {
                    v136 = *v134++;
                    v135[5] = v136;
                    ++v135;
                  }
                  while ( v136 != 0 );
                  v137 = &STACK[0x510];
                  *(_OWORD *)&a30 = xmmword_140034903;
                  LODWORD(retaddr) = 0;
                  do
                  {
                    v138 = (int)retaddr;
                    LODWORD(retaddr) = (_DWORD)retaddr + 1;
                    *((_BYTE *)&a30 + v138) ^= 105 * (_BYTE)retaddr;
                  }
                  while ( (unsigned int)retaddr < 0x10 );
                  v139 = &a30;
                  do
                  {
                    v140 = *(_BYTE *)v139;
                    v139 = (unsigned __int64 *)((char *)v139 + 1);
                    v135[4] = v140;
                    ++v135;
                  }
                  while ( v140 != 0 );
                  do
                  {
                    v141 = *(_BYTE *)v137;
                    v137 = (unsigned __int64 *)((char *)v137 + 1);
                    v135[3] = v141;
                    ++v135;
                  }
                  while ( v141 != 0 );
                  v142 = &STACK[0x526];
                  *(_OWORD *)&a30 = xmmword_140034913;
                  LOWORD(a32) = -30652;
                  LODWORD(retaddr) = 0;
                  do
                  {
                    v143 = (int)retaddr;
                    LODWORD(retaddr) = (_DWORD)retaddr + 1;
                    v144 = ((unsigned __int8)retaddr & 0x24 ^ 0x24) * ((unsigned __int8)retaddr & 0xDB)
                         + ((unsigned __int8)retaddr & 0x24) * ((unsigned int)retaddr | 0x24);
                    v145 = *((char *)&a30 + v143);
                    v146 = (char)v144;
                    v147 = v145 + (v145 ^ v144) - (v145 & ~v144);
                    v148 = v145 & v146;
                    v149 = v147 & (unsigned int)(v148 + ~(2 * v148));
                    *((_BYTE *)&a30 + v143) = v147 & (v148 + ~(2 * v148));
                  }
                  while ( (unsigned int)retaddr < 0x12 );
                  v150 = &a30;
                  do
                  {
                    v151 = *(unsigned __int8 *)v150;
                    v150 = (unsigned __int64 *)((char *)v150 + 1);
                    v135[2] = v151;
                    ++v135;
                  }
                  while ( (_BYTE)v151 != 0 );
                  do
                  {
                    v152 = *(unsigned __int8 *)v142;
                    v142 = (unsigned __int64 *)((char *)v142 + 1);
                    *++v135 = v152;
                  }
                  while ( (_BYTE)v152 != 0 );
                  return off_140039E40(
                           v152,
                           v151,
                           v149,
                           v148,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9,
                           a10,
                           a11,
                           a12,
                           a13,
                           a14,
                           a15,
                           a16,
                           a17,
                           a18,
                           a19,
                           a20,
                           a21,
                           a22,
                           a23,
                           a24,
                           a25,
                           a26,
                           a27);
                case 14:
                case 15:
                  if ( STACK[0x508] != 0 )
                    sub_140001C10(STACK[0x508]);
                  BYTE4(a12) = -47;
                  LODWORD(a12) = 410767155;
                  LODWORD(STACK[0x4F8]) = 0;
                  if ( LODWORD(STACK[0x4F8]) <= 4 )
                  {
                    do
                    {
                      v153 = LODWORD(STACK[0x4F8])++;
                      *((_BYTE *)&a12 + v153) ^= 93 * LOBYTE(STACK[0x4F8]);
                    }
                    while ( LODWORD(STACK[0x4F8]) < 5 );
                  }
                  STACK[0x4FE] = 0x884C6A517F9D95A3uLL;
                  STACK[0x4F8] = 0x95A3C6ED1C741816uLL;
                  LODWORD(a30) = 0;
                  do
                  {
                    v154 = a30;
                    LODWORD(a30) = a30 + 1;
                    *((_BYTE *)&STACK[0x4F8] + v154) ^= (a30 & 0xE3) * (a30 & 0x1C ^ 0x1C) + (a30 & 0x1C) * (a30 | 0x1C);
                  }
                  while ( (unsigned int)a30 < 0xE );
                  v155 = v332 - 1;
                  v319 = v155;
                  do
                  {
                    v156 = *(_BYTE *)p_j;
                    p_j = (unsigned __int64 *)((char *)p_j + 1);
                    *(_BYTE *)++v319 = v156;
                    ++v155;
                  }
                  while ( v156 != 0 );
                  v94 = sub_14002FDC0(qword_14003BA40, 1114851402);
                  switch ( v94 != 0 )
                  {
                    case false:
                      goto LABEL_124;
                    case true:
                      goto LABEL_108;
                  }
                case 16:
LABEL_108:
                  switch ( ((unsigned int (__fastcall *)(unsigned __int64 *, __int64))v94)(&STACK[0x4F8], 85) != 0 )
                  {
                    case false:
                      goto LABEL_124;
                    case true:
                      goto LABEL_109;
                  }
                case 17:
LABEL_109:
                  v157 = LOWORD(STACK[0x4F8]);
                  if ( (_WORD)v157 != 0 )
                  {
                    if ( (unsigned __int16)v157 > 0x7Fu )
                    {
                      if ( (unsigned __int16)v157 > 0x7FFu )
                        JUMPOUT(0x1400241A0LL);
                      *(_BYTE *)v319 = (v157 >> 6) | 0xC0;
                      *(_BYTE *)(v319 + 1) = v157 & 0x3F | 0x80;
                    }
                    else
                    {
                      *(_BYTE *)v319 = v157;
                    }
                    JUMPOUT(0x140024220LL);
                  }
                  JUMPOUT(0x140024284LL);
                case 18:
LABEL_124:
                  JUMPOUT(0x14002428DLL);
                case 19:
                  JUMPOUT(0x140024364LL);
                case 20:
                  JUMPOUT(0x140024348LL);
                case 21:
                  JUMPOUT(0x140024383LL);
                case 22:
                  JUMPOUT(0x140024464LL);
                case 23:
                  JUMPOUT(0x140024446LL);
                case 24:
                  JUMPOUT(0x140024483LL);
                case 25:
                  STACK[0x4FD] = v319;
                  STACK[0x4F8] = v332;
                  for ( j = 0;
                        j < 0xD;
                        *((_BYTE *)&STACK[0x4F8] + v159) = (*((_BYTE *)&STACK[0x4F8] + v159) | (77 * j))
                                                         & ((*((_BYTE *)&STACK[0x4F8] + v159) & (77 * j))
                                                          + ~(2 * (*((_BYTE *)&STACK[0x4F8] + v159) & (77 * j)))) )
                  {
                    v159 = j++;
                  }
                  v160 = v326 - 1;
                  v161 = &STACK[0x4F8];
                  do
                  {
                    v162 = *(_BYTE *)v161;
                    v161 = (unsigned __int64 *)((char *)v161 + 1);
                    *++v160 = v162;
                  }
                  while ( v162 != 0 );
                  HIDWORD(a18) = 16;
                  GetComputerNameExA(ComputerNamePhysicalNetBIOS, (LPSTR)&a26, (LPDWORD)&a18 + 1);
                  return off_140039E98(
                           v164,
                           v163,
                           v165,
                           v166,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9,
                           a10,
                           a11,
                           a12,
                           a13,
                           a14,
                           a15,
                           a16,
                           a17,
                           a18,
                           a19,
                           a20,
                           a21,
                           a22,
                           a23,
                           a24,
                           a25,
                           a26,
                           a27,
                           a28,
                           a29,
                           a30,
                           a31,
                           a32,
                           a33,
                           a34,
                           a35,
                           a36,
                           a37,
                           a38,
                           a39,
                           a40,
                           a41,
                           a42,
                           a43,
                           a44,
                           a45,
                           a46,
                           a47,
                           a48,
                           a49,
                           a50,
                           a51,
                           a52,
                           a53,
                           a54,
                           a55,
                           a56,
                           a57,
                           a58,
                           a59);
                case 26:
                  switch ( v370 != 0 )
                  {
                    case false:
                      goto LABEL_37;
                    case true:
                      goto LABEL_115;
                  }
                case 27:
                  do
                  {
LABEL_115:
                    v158 = *(_BYTE *)p_j;
                    p_j = (unsigned __int64 *)((char *)p_j + 1);
                    *(_BYTE *)v327 = v158;
                    v326 = (_BYTE *)v327++;
                  }
                  while ( v158 != 0 );
                  goto LABEL_39;
                case 28:
LABEL_37:
                  v100 = (char *)&a12;
                  do
                  {
                    v326 = (_BYTE *)v327;
                    v101 = *v100++;
                    ++v327;
                    *v326 = v101;
                  }
                  while ( v101 != 0 );
                  goto LABEL_39;
                case 29:
LABEL_39:
                  STACK[0x4F8] = 0x29595D4744383002LL;
                  LODWORD(STACK[0x500]) = 1618504230;
                  for ( j = 0; j < 0xC; *((_BYTE *)&STACK[0x4F8] + v102) ^= (j & 0xF7) * (j & 8 ^ 8) + (j & 8) * (j | 8) )
                    v102 = j++;
                  --v326;
                  v103 = &STACK[0x4F8];
                  do
                  {
                    v104 = *(_BYTE *)v103;
                    v103 = (unsigned __int64 *)((char *)v103 + 1);
                    *++v326 = v104;
                  }
                  while ( v104 != 0 );
                  LODWORD(a25) = 256;
                  p_j = (unsigned __int64 *)&j;
                  switch ( GetComputerNameExA(ComputerNamePhysicalDnsDomain, (LPSTR)&j, (LPDWORD)&a25) )
                  {
                    case false:
                      goto LABEL_44;
                    case true:
                      goto LABEL_47;
                  }
                case 30:
                  do
                  {
LABEL_47:
                    v319 = (unsigned __int64)v326;
                    v107 = *(_BYTE *)p_j;
                    p_j = (unsigned __int64 *)((char *)p_j + 1);
                    ++v326;
                    *(_BYTE *)v319 = v107;
                  }
                  while ( v107 != 0 );
                  goto LABEL_48;
                case 31:
LABEL_44:
                  v105 = (char *)&a12;
                  do
                  {
                    v319 = (unsigned __int64)v326;
                    v106 = *v105++;
                    ++v326;
                    *(_BYTE *)v319 = v106;
                  }
                  while ( v106 != 0 );
                  goto LABEL_48;
                case 32:
LABEL_48:
                  STACK[0x4FE] = 0xC6A10692DF0C4697uLL;
                  STACK[0x4F8] = 0x4697ED367CEFAA4FLL;
                  LODWORD(retaddr) = 0;
                  do
                  {
                    v108 = (int)retaddr;
                    LODWORD(retaddr) = (_DWORD)retaddr + 1;
                    *((_BYTE *)&STACK[0x4F8] + v108) ^= 69 * (_BYTE)retaddr;
                  }
                  while ( (unsigned int)retaddr < 0xE );
                  --v319;
                  v109 = &STACK[0x4F8];
                  do
                  {
                    v110 = *(_BYTE *)v109;
                    v109 = (unsigned __int64 *)((char *)v109 + 1);
                    *(_BYTE *)++v319 = v110;
                  }
                  while ( v110 != 0 );
                  HIDWORD(a24) = 256;
                  p_j = (unsigned __int64 *)&j;
                  switch ( GetComputerNameExA(ComputerNamePhysicalDnsHostname, (LPSTR)&j, (LPDWORD)&a24 + 1) )
                  {
                    case false:
                      goto LABEL_53;
                    case true:
                      goto LABEL_56;
                  }
                case 33:
                  do
                  {
LABEL_56:
                    v326 = (_BYTE *)v319;
                    v113 = *(_BYTE *)p_j;
                    p_j = (unsigned __int64 *)((char *)p_j + 1);
                    ++v319;
                    *v326 = v113;
                  }
                  while ( v113 != 0 );
                  goto LABEL_57;
                case 34:
LABEL_53:
                  v111 = (char *)&a12;
                  do
                  {
                    v326 = (_BYTE *)v319;
                    v112 = *v111++;
                    ++v319;
                    *v326 = v112;
                  }
                  while ( v112 != 0 );
                  goto LABEL_57;
                case 35:
LABEL_57:
                  STACK[0x4FF] = 0x62DE159D188518DDLL;
                  STACK[0x4F8] = 0xDD1B8018995ADC74uLL;
                  LODWORD(retaddr) = 0;
                  do
                  {
                    v114 = (int)retaddr;
                    LODWORD(retaddr) = (_DWORD)retaddr + 1;
                    *((_BYTE *)&STACK[0x4F8] + v114) ^= 126 * (_BYTE)retaddr;
                  }
                  while ( (unsigned int)retaddr < 0xF );
                  --v326;
                  v115 = &STACK[0x4F8];
                  do
                  {
                    v116 = *(_BYTE *)v115;
                    v115 = (unsigned __int64 *)((char *)v115 + 1);
                    *++v326 = v116;
                  }
                  while ( v116 != 0 );
                  sub_140027840();
                  v117 = v94 == 0;
                  v99 = v94 != 0;
                  switch ( v94 != 0 )
                  {
                    case false:
                      return off_140039F50(0x7EC122CAA506E468LL);
                    case true:
                      goto LABEL_63;
                  }
                case 36:
                case 37:
LABEL_63:
                  LOBYTE(v99) = !v117;
                  v327 = (unsigned __int64)v326;
                  v90 = v94;
                  switch ( !v117 )
                  {
                    case false:
                      goto LABEL_85;
                    case true:
                      goto LABEL_64;
                  }
                case 38:
                  goto LABEL_85;
                case 39:
LABEL_64:
                  v118 = *(char **)(v90 + 8);
                  STACK[0x538] = 0xA5EE383DC98B5233uLL;
                  LODWORD(STACK[0x540]) = -1403846556;
                  LODWORD(a8) = 0;
                  do
                  {
                    v119 = a8;
                    LODWORD(a8) = a8 + 1;
                    *((_BYTE *)&STACK[0x538] + v119) ^= 57 * (_BYTE)a8;
                  }
                  while ( (unsigned int)a8 < 0xC );
                  v120 = v327 - 1;
                  v121 = &STACK[0x538];
                  do
                  {
                    v122 = v120++;
                    v123 = *(_BYTE *)v121;
                    v121 = (unsigned __int64 *)((char *)v121 + 1);
                    *(_BYTE *)(v122 + 1) = v123;
                  }
                  while ( v123 != 0 );
                  do
                  {
                    v93 = v122++;
                    v124 = *v118++;
                    *(_BYTE *)(v93 + 1) = v124;
                  }
                  while ( v124 != 0 );
                  LOBYTE(v125) = *(_BYTE *)(v90 + 16);
                  switch ( (_BYTE)v125 == 0 )
                  {
                    case false:
                      goto LABEL_70;
                    case true:
                      goto LABEL_74;
                  }
                case 40:
LABEL_74:
                  a8 = 0xED214F81A7F20C58uLL;
                  LOBYTE(a9) = -71;
                  LODWORD(STACK[0x538]) = 0;
                  if ( LODWORD(STACK[0x538]) <= 8 )
                  {
                    do
                    {
                      v127 = LODWORD(STACK[0x538])++;
                      *((_BYTE *)&a8 + v127) ^= 49 * LOBYTE(STACK[0x538]);
                    }
                    while ( LODWORD(STACK[0x538]) < 9 );
                  }
                  goto LABEL_79;
                case 41:
LABEL_70:
                  switch ( (_BYTE)v125 == 2 )
                  {
                    case false:
                      *(_DWORD *)((char *)&a8 + 3) = 529775565;
                      LODWORD(a8) = -854642360;
                      LODWORD(STACK[0x538]) = 0;
                      if ( LODWORD(STACK[0x538]) <= 6 )
                      {
                        do
                        {
                          v126 = LODWORD(STACK[0x538])++;
                          *((_BYTE *)&a8 + v126) ^= 41 * LOBYTE(STACK[0x538]);
                        }
                        while ( LODWORD(STACK[0x538]) < 7 );
                      }
                      break;
                    case true:
                      *(_DWORD *)((char *)&a8 + 3) = 49372375;
                      LODWORD(a8) = -685395427;
                      LODWORD(STACK[0x538]) = 0;
                      if ( LODWORD(STACK[0x538]) <= 6 )
                      {
                        do
                        {
                          v128 = LODWORD(STACK[0x538])++;
                          *((_BYTE *)&a8 + v128) ^= (STACK[0x538] & 0x6E ^ 0x6E) * (STACK[0x538] & 0x91)
                                                  + (STACK[0x538] & 0x6E) * (LOBYTE(STACK[0x538]) | 0x6E);
                        }
                        while ( LODWORD(STACK[0x538]) < 7 );
                      }
                      break;
                  }
LABEL_79:
                  v129 = &a8;
                  STACK[0x53D] = 0xFEA828F952D14EB7uLL;
                  STACK[0x538] = 0xD14EB76EF842CC7CuLL;
                  LODWORD(a16) = 0;
                  do
                  {
                    v130 = a16;
                    LODWORD(a16) = a16 + 1;
                    *((_BYTE *)&STACK[0x538] + v130) ^= (a16 & 0x76 ^ 0x76) * (a16 & 0x89) + (a16 & 0x76) * (a16 | 0x76);
                  }
                  while ( (unsigned int)a16 < 0xD );
                  v131 = &STACK[0x538];
                  do
                  {
                    v327 = v93++;
                    v132 = *(_BYTE *)v131;
                    v131 = (unsigned __int64 *)((char *)v131 + 1);
                    *(_BYTE *)(v327 + 1) = v132;
                  }
                  while ( v132 != 0 );
                  do
                  {
                    v133 = *(_BYTE *)v129;
                    v129 = (unsigned __int64 *)((char *)v129 + 1);
                    *(_BYTE *)++v327 = v133;
                  }
                  while ( v133 != 0 );
                  v90 = *(_QWORD *)v90;
                  switch ( v90 != 0 )
                  {
                    case false:
                      break;
                    case true:
                      goto LABEL_64;
                  }
LABEL_85:
                  result = off_140039EF8(v99, v90);
                  break;
              }
              break;
            case true:
              goto LABEL_3;
          }
          break;
      }
      return result;
    case 1uLL:
      JUMPOUT(0x1400295B3LL);
  }
}


// ---- sub_140029A60 @ 0x140029a60 ----
int sub_140029A60()
{
  return GetSystemMetrics(76);
}


// ---- sub_140029A70 @ 0x140029a70 ----
int sub_140029A70()
{
  return GetSystemMetrics(77);
}


// ---- sub_140029A80 @ 0x140029a80 ----
HDC sub_140029A80()
{
  return GetDC(nullptr);
}


// ---- sub_140029A90 @ 0x140029a90 ----
HGDIOBJ __fastcall sub_140029A90(HDC *a1)
{
  return GetCurrentObject(*a1, 7u);
}


// ---- sub_140029AA0 @ 0x140029aa0 ----
int __fastcall sub_140029AA0(HANDLE *a1, void *a2)
{
  return GetObjectW(*a1, 32, a2);
}


// ---- sub_140029AC0 @ 0x140029ac0 ----
BOOL __fastcall sub_140029AC0(HGDIOBJ *a1)
{
  return DeleteObject(*a1);
}


// ---- sub_140029AD0 @ 0x140029ad0 ----
HDC __fastcall sub_140029AD0(HDC *a1)
{
  return CreateCompatibleDC(*a1);
}


// ---- sub_140029AE0 @ 0x140029ae0 ----
HBITMAP __fastcall sub_140029AE0(__int64 a1)
{
  return CreateCompatibleBitmap(**(HDC **)a1, **(_DWORD **)(a1 + 8), **(_DWORD **)(a1 + 16));
}


// ---- sub_140029B00 @ 0x140029b00 ----
HGDIOBJ __fastcall sub_140029B00(HDC *a1, HGDIOBJ *a2)
{
  return SelectObject(*a1, *a2);
}


// ---- sub_140029B10 @ 0x140029b10 ----
BOOL __fastcall sub_140029B10(__int64 a1)
{
  return BitBlt(
           **(HDC **)a1,
           0,
           0,
           **(_DWORD **)(a1 + 8),
           **(_DWORD **)(a1 + 16),
           **(HDC **)(a1 + 24),
           **(_DWORD **)(a1 + 32),
           **(_DWORD **)(a1 + 40),
           0xCC0020u);
}


// ---- sub_140029B70 @ 0x140029b70 ----
char __fastcall sub_140029B70(
        __int64 a1,
        __int64 a2,
        __int64 *a3,
        _QWORD *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        unsigned __int64 a8,
        char a9)
{
  char *v9; // r9
  int v10; // r8d
  char *v11; // r15
  unsigned __int64 *v12; // r8
  char *v13; // r10
  char v14; // r11
  char *v15; // r8
  char v16; // r11
  int v17; // r9d
  int v18; // r9d
  __int64 v19; // rdx
  char v20; // r9
  __int64 v21; // rcx
  __int64 v22; // rax
  __int64 *v23; // rdi
  __int64 v24; // rbx
  __int64 v25; // rdx
  __int64 v26; // rcx
  __int64 v27; // r8
  __int64 v28; // r9
  void *v29; // rsp
  __int64 v30; // rdx
  __int64 v31; // rcx
  __int64 v32; // r8
  __int64 v33; // r9
  void *v34; // rsp
  __int64 v35; // rdx
  __int64 v36; // rcx
  __int64 v37; // r8
  __int64 v38; // r9
  void *v39; // rsp
  __int64 v40; // rdx
  __int64 v41; // rcx
  __int64 v42; // r8
  __int64 v43; // r9
  void *v44; // rsp
  __int64 v45; // rcx
  __int64 v46; // r8
  __int64 v47; // r9
  void *v48; // rsp
  __int64 v49; // rdx
  __int64 v50; // rcx
  __int64 v51; // r8
  __int64 v52; // r9
  void *v53; // rsp
  __int64 v54; // rdx
  __int64 v55; // rcx
  __int64 v56; // r8
  __int64 v57; // r9
  void *v58; // rsp
  __int64 v59; // rdx
  __int64 v60; // rcx
  __int64 v61; // r8
  __int64 v62; // r9
  void *v63; // rsp
  __int64 v64; // rdx
  unsigned __int64 v65; // r13
  bool v66; // al
  char result; // al
  char v68; // [rsp+1Fh] [rbp-81h] BYREF
  __int64 v69; // [rsp+20h] [rbp-80h] BYREF
  __int64 *v70; // [rsp+28h] [rbp-78h]
  __int64 *v71; // [rsp+30h] [rbp-70h]
  __int64 *v72; // [rsp+38h] [rbp-68h]
  __int64 *v73; // [rsp+40h] [rbp-60h]
  _UNKNOWN **v74; // [rsp+48h] [rbp-58h]
  _UNKNOWN **v75; // [rsp+50h] [rbp-50h]
  _UNKNOWN **v76; // [rsp+58h] [rbp-48h]
  __int64 *v77; // [rsp+60h] [rbp-40h]
  _QWORD *v78; // [rsp+68h] [rbp-38h]
  __int64 *v79; // [rsp+70h] [rbp-30h]
  __int64 v80; // [rsp+78h] [rbp-28h]
  __int64 v81; // [rsp+80h] [rbp-20h]
  int v82; // [rsp+8Ch] [rbp-14h]
  int v83; // [rsp+90h] [rbp-10h]
  int v84; // [rsp+94h] [rbp-Ch]
  int v85; // [rsp+98h] [rbp-8h]
  BOOL v86; // [rsp+9Ch] [rbp-4h]
  int v87; // [rsp+A0h] [rbp+0h]
  int v88; // [rsp+A4h] [rbp+4h]

  v78 = a4;
  v77 = a3;
  v80 = a2;
  v81 = a1;
  v70 = (__int64 *)jpt_140029C0F;
  nullsub_1();
  v82 = 0;
  v71 = (__int64 *)jpt_140029FD6;
  v72 = (__int64 *)jpt_140029E62;
  v73 = (__int64 *)jpt_1400299C8;
  v85 = 297;
  v74 = jpt_140029C46;
  v75 = jpt_1400299C8;
  v87 = 299;
  v76 = jpt_1400299C8;
  v88 = 294;
  switch ( (unsigned __int64)jpt_1400299C8 )
  {
    case 0uLL:
      nullsub_1();
      v29 = alloca(sub_140001B30(v26, v25, v27, v28));
      v34 = alloca(sub_140001B30(v31, v30, v32, v33));
      v39 = alloca(sub_140001B30(v36, v35, v37, v38));
      v44 = alloca(sub_140001B30(v41, v40, v42, v43));
      v48 = alloca(sub_140001B30(v45, &v69, v46, v47));
      v53 = alloca(sub_140001B30(v50, v49, v51, v52));
      v58 = alloca(sub_140001B30(v55, v54, v56, v57));
      v63 = alloca(sub_140001B30(v60, v59, v61, v62));
      v79 = &v69;
      v69 = v81;
      *(_QWORD *)v64 = &v69;
      *(_QWORD *)(v64 + 8) = &v69;
      sub_140029AA0(*(HANDLE **)v64, *(void **)(v64 + 8));
      LODWORD(v69) = 40;
      LODWORD(v70) = -(int)v70;
      HIDWORD(v70) = 2097153;
      v71 = nullptr;
      v72 = nullptr;
      v73 = nullptr;
      v65 = (unsigned int)(4 * (_DWORD)v70 * HIDWORD(v69));
      sub_14002E070(v65);
      v69 = (__int64)&v69;
      v70 = &v69;
      v71 = &v69;
      v72 = &v69;
      v73 = &v69;
      v66 = (unsigned int)sub_14002A760(&v69) != 0;
      v83 = 1;
      v24 = (__int64)v79;
      v84 = v66;
      switch ( v66 )
      {
        case false:
          v86 = v69 == 0;
          switch ( v69 == 0 )
          {
            case false:
              sub_140001C10(v69);
              switch ( v87 )
              {
                case 0:
                  goto LABEL_25;
                case 1:
                  goto LABEL_23;
                case 2:
                  goto LABEL_24;
                case 3:
                  goto LABEL_26;
                case 4:
                  goto LABEL_27;
                case 5:
                  goto LABEL_28;
                case 6:
                  goto LABEL_29;
                case 7:
                  goto LABEL_30;
                case 8:
                  goto LABEL_32;
                case 9:
                  goto LABEL_31;
                case 10:
                  goto LABEL_33;
                case 11:
                  goto LABEL_35;
                case 12:
                  goto LABEL_34;
                case 13:
                  goto LABEL_46;
                case 14:
                case 15:
                  goto LABEL_47;
                case 16:
                  goto LABEL_48;
                case 17:
                  goto LABEL_49;
                case 18:
                  goto LABEL_50;
                case 19:
                  goto LABEL_52;
                case 20:
                  goto LABEL_51;
                case 21:
                  goto LABEL_53;
                case 22:
                  goto LABEL_55;
                case 23:
                  goto LABEL_54;
                case 24:
                  goto LABEL_56;
                case 25:
                  goto LABEL_59;
                case 26:
                  goto LABEL_57;
                case 27:
                  goto LABEL_58;
                case 28:
                  goto LABEL_36;
                case 29:
                  goto LABEL_37;
                case 30:
                  goto LABEL_39;
                case 31:
                  goto LABEL_38;
                case 32:
                  goto LABEL_40;
                case 33:
                  goto LABEL_42;
                case 34:
                  goto LABEL_41;
                case 35:
                  goto LABEL_43;
                case 36:
                case 37:
                  goto LABEL_44;
                case 38:
                  goto LABEL_45;
                case 39:
                  goto LABEL_5;
                case 40:
                  goto LABEL_15;
                case 41:
                  goto LABEL_11;
              }
            case true:
              return 0;
          }
        case true:
          *(_WORD *)v79 = 19778;
          *(_DWORD *)(v24 + 10) = 54;
          v21 = (unsigned int)(v65 + 54);
          *(_DWORD *)(v24 + 2) = v21;
          v22 = sub_14002E070(v21);
          v23 = v77;
          *v77 = v22;
          *v78 = *(unsigned int *)(v24 + 2);
          sub_140001C40(*v23, v24, 0xEu);
          sub_140001C40(*v23 + 14, (__int64)&v69, 0x28u);
          sub_140001C40(*v23 + 54, v69, v65);
          switch ( v85 )
          {
            case 0:
LABEL_25:
              JUMPOUT(0x140020690LL);
            case 1:
LABEL_23:
              JUMPOUT(0x1400205FCLL);
            case 2:
LABEL_24:
              JUMPOUT(0x140020611LL);
            case 3:
LABEL_26:
              JUMPOUT(0x14002092FLL);
            case 4:
LABEL_27:
              JUMPOUT(0x1400209B1LL);
            case 5:
LABEL_28:
              JUMPOUT(0x140020B94LL);
            case 6:
LABEL_29:
              JUMPOUT(0x140020D40LL);
            case 7:
LABEL_30:
              JUMPOUT(0x140020EF0LL);
            case 8:
LABEL_32:
              JUMPOUT(0x140020F85LL);
            case 9:
LABEL_31:
              JUMPOUT(0x140020F02LL);
            case 10:
LABEL_33:
              JUMPOUT(0x140020FF0LL);
            case 11:
LABEL_35:
              JUMPOUT(0x14002108ELL);
            case 12:
LABEL_34:
              JUMPOUT(0x140021088LL);
            case 13:
LABEL_46:
              JUMPOUT(0x140023C38LL);
            case 14:
            case 15:
LABEL_47:
              JUMPOUT(0x140023F9FLL);
            case 16:
LABEL_48:
              JUMPOUT(0x1400240F7LL);
            case 17:
LABEL_49:
              JUMPOUT(0x14002411ALL);
            case 18:
LABEL_50:
              JUMPOUT(0x14002428DLL);
            case 19:
LABEL_52:
              JUMPOUT(0x140024364LL);
            case 20:
LABEL_51:
              JUMPOUT(0x140024348LL);
            case 21:
LABEL_53:
              JUMPOUT(0x140024383LL);
            case 22:
LABEL_55:
              JUMPOUT(0x140024464LL);
            case 23:
LABEL_54:
              JUMPOUT(0x140024446LL);
            case 24:
LABEL_56:
              JUMPOUT(0x140024483LL);
            case 25:
LABEL_59:
              JUMPOUT(0x140024948LL);
            case 26:
LABEL_57:
              JUMPOUT(0x140024869LL);
            case 27:
LABEL_58:
              JUMPOUT(0x14002487ALL);
            case 28:
LABEL_36:
              JUMPOUT(0x14002357CLL);
            case 29:
LABEL_37:
              JUMPOUT(0x1400235A2LL);
            case 30:
LABEL_39:
              JUMPOUT(0x1400236B4LL);
            case 31:
LABEL_38:
              JUMPOUT(0x14002368ALL);
            case 32:
LABEL_40:
              JUMPOUT(0x1400236D3LL);
            case 33:
LABEL_42:
              JUMPOUT(0x1400237C4LL);
            case 34:
LABEL_41:
              JUMPOUT(0x14002379ALL);
            case 35:
LABEL_43:
              JUMPOUT(0x1400237E3LL);
            case 36:
            case 37:
LABEL_44:
              JUMPOUT(0x1400238A5LL);
            case 38:
LABEL_45:
              JUMPOUT(0x140023C14LL);
            case 39:
LABEL_5:
              v9 = *(char **)(v19 + 8);
              STACK[0x428] = 0xA5EE383DC98B5233uLL;
              LODWORD(STACK[0x430]) = -1403846556;
              LODWORD(a8) = 0;
              do
              {
                v10 = a8;
                LODWORD(a8) = a8 + 1;
                *((_BYTE *)&STACK[0x428] + v10) ^= 57 * (_BYTE)a8;
              }
              while ( (unsigned int)a8 < 0xC );
              v11 = &v68;
              v12 = &STACK[0x428];
              do
              {
                v13 = v11++;
                v14 = *(_BYTE *)v12;
                v12 = (unsigned __int64 *)((char *)v12 + 1);
                v13[1] = v14;
              }
              while ( v14 != 0 );
              do
              {
                v15 = v13++;
                v16 = *v9++;
                v15[1] = v16;
              }
              while ( v16 != 0 );
              v20 = *(_BYTE *)(v19 + 16);
              switch ( v20 == 0 )
              {
                case false:
                  goto LABEL_11;
                case true:
                  goto LABEL_15;
              }
            case 40:
LABEL_15:
              a8 = 0xED214F81A7F20C58uLL;
              a9 = -71;
              LODWORD(STACK[0x428]) = 0;
              if ( LODWORD(STACK[0x428]) <= 8 )
              {
                do
                {
                  v18 = LODWORD(STACK[0x428])++;
                  *((_BYTE *)&a8 + v18) ^= 49 * LOBYTE(STACK[0x428]);
                }
                while ( LODWORD(STACK[0x428]) < 9 );
              }
              break;
            case 41:
LABEL_11:
              switch ( v20 == 2 )
              {
                case false:
                  *(_DWORD *)((char *)&a8 + 3) = 529775565;
                  LODWORD(a8) = -854642360;
                  LODWORD(STACK[0x428]) = 0;
                  if ( LODWORD(STACK[0x428]) <= 6 )
                  {
                    do
                    {
                      v17 = LODWORD(STACK[0x428])++;
                      *((_BYTE *)&a8 + v17) ^= 41 * LOBYTE(STACK[0x428]);
                    }
                    while ( LODWORD(STACK[0x428]) < 7 );
                  }
                  break;
                case true:
                  JUMPOUT(0x140023AA0LL);
              }
              return result;
          }
          JUMPOUT(0x140023B20LL);
      }
    case 1uLL:
      JUMPOUT(0x140029C51LL);
  }
}


// ---- sub_140029FF0 @ 0x140029ff0 ----
__int64 __fastcall sub_140029FF0(_QWORD *a1)
{
  *(_QWORD *)((char *)a1 + 7) = 0x1E6C777A38607D78LL;
  *a1 = 0x787D626F6D746751LL;
  return 0x787D626F6D746751LL;
}


// ---- sub_14002A010 @ 0x14002a010 ----
BOOL __fastcall sub_14002A010(HDC *a1)
{
  return DeleteDC(*a1);
}


// ---- sub_14002A020 @ 0x14002a020 ----
int __fastcall sub_14002A020(HDC *a1)
{
  return ReleaseDC(nullptr, *a1);
}


// ---- sub_14002A030 @ 0x14002a030 ----
void __fastcall sub_14002A030(_DWORD *a1)
{
  *a1 = 864302717;
}


// ---- sub_14002A040 @ 0x14002a040 ----
void __fastcall sub_14002A040(_DWORD *a1)
{
  *a1 = 1790029874;
}


// ---- sub_14002A050 @ 0x14002a050 ----
__int64 __fastcall sub_14002A050(_QWORD *a1)
{
  *a1 = 0x11D01D3ACD79D1CELL;
  return 0x11D01D3ACD79D1CELL;
}


// ---- sub_14002A060 @ 0x14002a060 ----
__int64 __fastcall sub_14002A060(_QWORD *a1)
{
  *a1 = 0x242E4B008D20BC19LL;
  return 0x242E4B008D20BC19LL;
}


// ---- sub_14002A070 @ 0x14002a070 ----
__int64 __fastcall sub_14002A070(_QWORD *a1)
{
  *a1 = 0x11CF737F194ABBC6LL;
  return 0x11CF737F194ABBC6LL;
}


// ---- sub_14002A080 @ 0x14002a080 ----
__int64 __fastcall sub_14002A080(_QWORD *a1)
{
  *a1 = 0x242E4B00C98FDB7ALL;
  return 0x242E4B00C98FDB7ALL;
}


// ---- sub_14002A090 @ 0x14002a090 ----
BSTR sub_14002A090()
{
  __int64 v0; // rax
  unsigned int i; // [rsp+2Ch] [rbp-1Ch]
  OLECHAR psz[12]; // [rsp+30h] [rbp-18h] BYREF

  *(_OWORD *)psz = xmmword_1400347D0;
  *(_QWORD *)&psz[7] = 0xDE1BC9D8B5EFA1C5uLL;
  for ( i = 0; i < 0xB; psz[v0] ^= 5169 * (_WORD)i )
    v0 = (int)i++;
  return SysAllocString(psz);
}


// ---- sub_14002A100 @ 0x14002a100 ----
BSTR sub_14002A100()
{
  unsigned int v0; // eax
  unsigned int i; // [rsp+2Ch] [rbp-Ch]
  OLECHAR psz[4]; // [rsp+30h] [rbp-8h] BYREF

  *(_QWORD *)psz = 0x29485EBA94F5CA05LL;
  for ( i = 0; i < 4; psz[v0] = (psz[v0] | (-13742 * i)) & (-2 - (psz[v0] + ((-13742 * i) | ~psz[v0]))) )
    v0 = i++;
  return SysAllocString(psz);
}


// ---- sub_14002A180 @ 0x14002a180 ----
BSTR sub_14002A180()
{
  unsigned int v0; // eax
  unsigned int i; // [rsp+2Ch] [rbp-4Ch]
  OLECHAR psz[8]; // [rsp+30h] [rbp-48h] BYREF
  __int128 v4; // [rsp+40h] [rbp-38h]
  __int128 v5; // [rsp+50h] [rbp-28h]
  __int128 v6; // [rsp+60h] [rbp-18h]
  __int64 v7; // [rsp+70h] [rbp-8h]

  v6 = xmmword_140034816;
  v5 = xmmword_140034806;
  v4 = xmmword_1400347F6;
  *(_OWORD *)psz = xmmword_1400347E6;
  v7 = 0xFE48F1E0F678EE5LL;
  for ( i = 0; i < 0x24; psz[v0] = (psz[v0] | (-32655 * i)) & (-2 - (psz[v0] + ((-32655 * i) | ~psz[v0]))) )
    v0 = i++;
  return SysAllocString(psz);
}


// ---- VariantInit @ 0x14002a230 ----
// attributes: thunk
void __stdcall VariantInit(VARIANTARG *pvarg)
{
  __imp_VariantInit(pvarg);
}


// ---- sub_14002A240 @ 0x14002a240 ----
void __fastcall sub_14002A240(_OWORD *a1)
{
  *a1 = xmmword_14003482E;
}


// ---- sub_14002A250 @ 0x14002a250 ----
unsigned __int64 __fastcall sub_14002A250(_QWORD *a1)
{
  *a1 = 0xC8FC217280C51B6EuLL;
  return 0xC8FC217280C51B6EuLL;
}


// ---- VariantClear @ 0x14002a260 ----
// attributes: thunk
HRESULT __stdcall VariantClear(VARIANTARG *pvarg)
{
  return __imp_VariantClear(pvarg);
}


// ---- sub_14002A270 @ 0x14002a270 ----
void __fastcall sub_14002A270(_OWORD *a1)
{
  *(_OWORD *)((char *)a1 + 12) = *(__int128 *)((char *)&xmmword_14003483E + 12);
  *a1 = xmmword_14003483E;
}


// ---- sub_14002A290 @ 0x14002a290 ----
void __fastcall sub_14002A290(_BYTE *a1, char *a2, unsigned __int64 a3)
{
  __int64 v3; // rax
  char v4; // r10
  unsigned __int64 v5; // r9
  char v6; // al
  char *v7; // rdx
  char v8; // al
  char *v9; // rdx
  char v10; // al
  char *v11; // rdx
  char v12; // r8

  if ( a3 != 0 )
  {
    if ( (a3 & 3) == 0 )
    {
      v5 = a3;
      if ( a3 < 4 )
        return;
      goto LABEL_6;
    }
    v3 = 0;
    do
    {
      v4 = *a2;
      a2 += -(*a2 == 0) + 1;
      a1[v3++] = v4;
    }
    while ( (a3 & 3) != v3 );
    a1 += v3;
    v5 = a3 - v3;
    if ( a3 >= 4 )
    {
      do
      {
LABEL_6:
        v6 = *a2;
        v7 = &a2[-(*a2 == 0) + 1];
        *a1 = v6;
        v8 = *v7;
        v9 = &v7[-(*v7 == 0) + 1];
        a1[1] = v8;
        v10 = *v9;
        v11 = &v9[-(*v9 == 0) + 1];
        a1[2] = v10;
        v12 = *v11;
        a2 = &v11[-(*v11 == 0) + 1];
        a1[3] = v12;
        a1 += 4;
        v5 -= 4LL;
      }
      while ( v5 != 0 );
    }
  }
}


// ---- sub_14002A320 @ 0x14002a320 ----
void __fastcall sub_14002A320(_DWORD *a1)
{
  *a1 = -1223431473;
}


// ---- sub_14002A330 @ 0x14002a330 ----
void __fastcall sub_14002A330(_BYTE *a1)
{
  *a1 = 68;
}


// ---- sub_14002A340 @ 0x14002a340 ----
void __fastcall sub_14002A340(_BYTE *a1)
{
  *a1 = 7;
}


// ---- sub_14002A350 @ 0x14002a350 ----
void __fastcall sub_14002A350(_DWORD *a1)
{
  *a1 = -1850058792;
}


// ---- sub_14002A360 @ 0x14002a360 ----
void __fastcall sub_14002A360(_BYTE *a1)
{
  *a1 = 61;
}


// ---- sub_14002A370 @ 0x14002a370 ----
void __fastcall sub_14002A370(_BYTE *a1)
{
  *a1 = 96;
}


// ---- sub_14002A380 @ 0x14002a380 ----
void __fastcall sub_14002A380(_DWORD *a1)
{
  *a1 = 1818281189;
}


// ---- sub_14002A390 @ 0x14002a390 ----
void __fastcall sub_14002A390(_BYTE *a1)
{
  *a1 = 116;
}


// ---- sub_14002A3A0 @ 0x14002a3a0 ----
void __fastcall sub_14002A3A0(_OWORD *a1)
{
  a1[1] = xmmword_14003486A;
  *a1 = xmmword_14003485A;
}


// ---- sub_14002A3C0 @ 0x14002a3c0 ----
__int64 __fastcall sub_14002A3C0(__int64 a1)
{
  *(_OWORD *)a1 = xmmword_14003487A;
  *(_QWORD *)(a1 + 16) = 0xC040D580D4C0F1LL;
  return 0xC040D580D4C0F1LL;
}


// ---- sub_14002A3E0 @ 0x14002a3e0 ----
void __fastcall sub_14002A3E0(_DWORD *a1)
{
  *a1 = -448877643;
}


// ---- sub_14002A3F0 @ 0x14002a3f0 ----
void __fastcall sub_14002A3F0(_BYTE *a1)
{
  *a1 = 16;
}


// ---- sub_14002A400 @ 0x14002a400 ----
void __fastcall sub_14002A400(_DWORD *a1)
{
  *a1 = 565026577;
}


// ---- sub_14002A410 @ 0x14002a410 ----
void __fastcall sub_14002A410(_BYTE *a1)
{
  *a1 = 24;
}


// ---- sub_14002A420 @ 0x14002a420 ----
void __fastcall sub_14002A420(_BYTE *a1)
{
  *a1 = 79;
}


// ---- sub_14002A430 @ 0x14002a430 ----
void __fastcall sub_14002A430(_BYTE *a1)
{
  *a1 = 20;
}


// ---- sub_14002A440 @ 0x14002a440 ----
void __fastcall sub_14002A440(_BYTE *a1)
{
  *a1 = 93;
}


// ---- sub_14002A450 @ 0x14002a450 ----
void __fastcall sub_14002A450(_DWORD *a1)
{
  *a1 = 952303494;
}


// ---- sub_14002A460 @ 0x14002a460 ----
void __fastcall sub_14002A460(BSTR *a1)
{
  SysFreeString(*a1);
}


// ---- sub_14002A470 @ 0x14002a470 ----
BSTR sub_14002A470()
{
  __int64 v0; // rax
  unsigned int i; // [rsp+2Ch] [rbp-4Ch]
  OLECHAR psz[8]; // [rsp+30h] [rbp-48h] BYREF
  __int128 v4; // [rsp+40h] [rbp-38h]
  __int128 v5; // [rsp+50h] [rbp-28h]
  __int128 v6; // [rsp+60h] [rbp-18h]
  unsigned __int64 v7; // [rsp+70h] [rbp-8h]

  v6 = xmmword_1400348C2;
  v5 = xmmword_1400348B2;
  v4 = xmmword_1400348A2;
  *(_OWORD *)psz = xmmword_140034892;
  v7 = 0x832C5B8B34A30DFFuLL;
  for ( i = 0; i < 0x24; psz[v0] ^= 10035 * (_WORD)i )
    v0 = (int)i++;
  return SysAllocString(psz);
}


// ---- sub_14002A510 @ 0x14002a510 ----
__int64 __fastcall sub_14002A510(__int64 a1)
{
  *(_QWORD *)a1 = 0x7525979DBAC1DD1ELL;
  *(_WORD *)(a1 + 8) = 21136;
  return 0x7525979DBAC1DD1ELL;
}


// ---- sub_14002A530 @ 0x14002a530 ----
__int64 __fastcall sub_14002A530(_QWORD *a1)
{
  *a1 = 0x11D01D3A56F9948CLL;
  return 0x11D01D3A56F9948CLL;
}


// ---- sub_14002A540 @ 0x14002a540 ----
__int64 __fastcall sub_14002A540(_QWORD *a1)
{
  *a1 = 0x242E4B001BA0F9C7LL;
  return 0x242E4B001BA0F9C7LL;
}


// ---- sub_14002A550 @ 0x14002a550 ----
__int64 __fastcall sub_14002A550(_QWORD *a1)
{
  *a1 = 0x11CF737F93CAF978LL;
  return 0x11CF737F93CAF978LL;
}


// ---- sub_14002A560 @ 0x14002a560 ----
__int64 __fastcall sub_14002A560(_QWORD *a1)
{
  *a1 = 0x242E4B00440F9438LL;
  return 0x242E4B00440F9438LL;
}


// ---- sub_14002A570 @ 0x14002a570 ----
HRESULT __fastcall sub_14002A570(__int64 a1)
{
  return CoCreateInstance(*(const IID *const *)a1, nullptr, 1u, *(const IID *const *)(a1 + 8), *(LPVOID **)(a1 + 16));
}


// ---- sub_14002A5A0 @ 0x14002a5a0 ----
BSTR sub_14002A5A0()
{
  __int64 v0; // rax
  unsigned int i; // [rsp+2Ch] [rbp-3Ch]
  _QWORD psz[6]; // [rsp+30h] [rbp-38h] BYREF

  *(_OWORD *)((char *)&psz[3] + 2) = *(__int128 *)((char *)&xmmword_1400349A0 + 10);
  *(_OWORD *)&psz[2] = xmmword_1400349A0;
  *(_OWORD *)psz = xmmword_140034990;
  for ( i = 0; i < 0x15; *((_WORD *)psz + v0) ^= 27633 * (_WORD)i )
    v0 = (int)i++;
  return SysAllocString((const OLECHAR *)psz);
}


// ---- sub_14002A620 @ 0x14002a620 ----
BSTR sub_14002A620()
{
  __int64 v0; // rax
  unsigned int i; // [rsp+2Ch] [rbp-Ch]
  OLECHAR psz[4]; // [rsp+30h] [rbp-8h] BYREF

  *(_QWORD *)psz = 0x8840667C44712247uLL;
  for ( i = 0; i < 4; psz[v0] ^= 8720 * (_WORD)i )
    v0 = (int)i++;
  return SysAllocString(psz);
}


// ---- sub_14002A690 @ 0x14002a690 ----
BSTR sub_14002A690()
{
  __int64 v0; // rax
  unsigned int i; // [rsp+2Ch] [rbp-4Ch]
  OLECHAR psz[8]; // [rsp+30h] [rbp-48h] BYREF
  __int128 v4; // [rsp+40h] [rbp-38h]
  _WORD v5[20]; // [rsp+50h] [rbp-28h]

  qmemcpy(v5, byte_1400349DA, 30);
  v4 = xmmword_1400349CA;
  *(_OWORD *)psz = xmmword_1400349BA;
  for ( i = 0; i < 0x1F; psz[v0] ^= -10191 * (_WORD)i )
    v0 = (int)i++;
  return SysAllocString(psz);
}


// ---- sub_14002A720 @ 0x14002a720 ----
unsigned __int64 __fastcall sub_14002A720(__int64 a1)
{
  *(_OWORD *)a1 = xmmword_1400349F8;
  *(_QWORD *)(a1 + 16) = 0xABC01D158F4D00B1uLL;
  return 0xABC01D158F4D00B1uLL;
}


// ---- sub_14002A740 @ 0x14002a740 ----
void __fastcall sub_14002A740(_OWORD *a1)
{
  *(_OWORD *)((char *)a1 + 10) = *(__int128 *)((char *)&xmmword_140034A10 + 10);
  *a1 = xmmword_140034A10;
}


// ---- sub_14002A760 @ 0x14002a760 ----
int __fastcall sub_14002A760(__int64 a1)
{
  return GetDIBits(
           **(HDC **)a1,
           **(HBITMAP **)(a1 + 8),
           0,
           *(_DWORD *)(*(_QWORD *)(a1 + 16) + 8LL),
           **(LPVOID **)(a1 + 24),
           *(LPBITMAPINFO *)(a1 + 32),
           0);
}


// ---- sub_14002A7B0 @ 0x14002a7b0 ----
char __fastcall sub_14002A7B0()
{
  int v0; // ebp
  unsigned __int64 jj; // rdi
  int v2; // r9d
  __int64 v3; // rcx
  __int64 v5; // rax
  __int64 v6; // rax
  __int64 v7; // rax
  unsigned __int64 nn; // rsi
  bool v9; // bl
  bool v10; // cf
  bool v11; // zf
  __int64 v12; // rsi
  unsigned __int64 j; // rdi
  bool v14; // bl
  bool v15; // bp
  char result; // al
  int v17; // eax
  __int64 v18; // rax
  __int64 v19; // rax
  bool v20; // bl
  int v22; // esp
  unsigned __int64 v23; // rax
  unsigned __int16 (*v24)(void); // rax
  int v25; // esi
  int v26; // eax
  int v27; // eax
  __int64 v28; // [rsp+20h] [rbp-438h]
  __int64 v29; // [rsp+28h] [rbp-430h]
  int i; // [rsp+48h] [rbp-410h]
  unsigned int kk; // [rsp+4Ch] [rbp-40Ch]
  unsigned int mm; // [rsp+50h] [rbp-408h]
  int v33; // [rsp+54h] [rbp-404h]
  int k; // [rsp+58h] [rbp-400h]
  int v35; // [rsp+60h] [rbp-3F8h]
  int v36; // [rsp+64h] [rbp-3F4h]
  unsigned int m; // [rsp+68h] [rbp-3F0h]
  unsigned int n; // [rsp+6Ch] [rbp-3ECh]
  int ii; // [rsp+70h] [rbp-3E8h]
  int v40; // [rsp+74h] [rbp-3E4h] BYREF
  unsigned int v41; // [rsp+78h] [rbp-3E0h] BYREF
  int v42; // [rsp+7Ch] [rbp-3DCh] BYREF
  int v43; // [rsp+80h] [rbp-3D8h] BYREF
  unsigned int v44; // [rsp+84h] [rbp-3D4h] BYREF
  int v45; // [rsp+88h] [rbp-3D0h] BYREF
  unsigned int v46; // [rsp+90h] [rbp-3C8h] BYREF
  char v47; // [rsp+94h] [rbp-3C4h] BYREF
  _BYTE v48[2]; // [rsp+95h] [rbp-3C3h] BYREF
  char v49; // [rsp+97h] [rbp-3C1h] BYREF
  __int64 v50; // [rsp+98h] [rbp-3C0h] BYREF
  int v51; // [rsp+A0h] [rbp-3B8h]
  int v52; // [rsp+A4h] [rbp-3B4h]
  int v53; // [rsp+A8h] [rbp-3B0h]
  int v54; // [rsp+ACh] [rbp-3ACh]
  int v55; // [rsp+B0h] [rbp-3A8h]
  int v56; // [rsp+B4h] [rbp-3A4h]
  int v57; // [rsp+B8h] [rbp-3A0h]
  int v58; // [rsp+BCh] [rbp-39Ch]
  int v59; // [rsp+C0h] [rbp-398h]
  int v60; // [rsp+C4h] [rbp-394h]
  int v61; // [rsp+C8h] [rbp-390h]
  int v62; // [rsp+CCh] [rbp-38Ch]
  int v63; // [rsp+D0h] [rbp-388h]
  int v64; // [rsp+D4h] [rbp-384h]
  BOOL v65; // [rsp+D8h] [rbp-380h]
  int v66; // [rsp+DCh] [rbp-37Ch]
  int v67; // [rsp+E0h] [rbp-378h]
  int v68; // [rsp+E4h] [rbp-374h]
  int v69; // [rsp+E8h] [rbp-370h]
  int v70; // [rsp+ECh] [rbp-36Ch]
  int v71; // [rsp+F0h] [rbp-368h]
  int v72; // [rsp+F4h] [rbp-364h]
  int v73; // [rsp+F8h] [rbp-360h]
  int v74; // [rsp+FCh] [rbp-35Ch]
  int v75; // [rsp+100h] [rbp-358h]
  int v76; // [rsp+104h] [rbp-354h]
  BOOL v77; // [rsp+108h] [rbp-350h]
  BOOL v78; // [rsp+10Ch] [rbp-34Ch]
  BOOL v79; // [rsp+110h] [rbp-348h]
  int v80; // [rsp+114h] [rbp-344h]
  int v81; // [rsp+118h] [rbp-340h]
  int v82; // [rsp+11Ch] [rbp-33Ch]
  int v83; // [rsp+120h] [rbp-338h]
  int v84; // [rsp+124h] [rbp-334h]
  int v85; // [rsp+128h] [rbp-330h]
  BOOL v86; // [rsp+12Ch] [rbp-32Ch]
  int v87; // [rsp+130h] [rbp-328h]
  int v88; // [rsp+134h] [rbp-324h]
  int v89; // [rsp+138h] [rbp-320h]
  BOOL v90; // [rsp+13Ch] [rbp-31Ch]
  int v91; // [rsp+140h] [rbp-318h]
  BOOL v92; // [rsp+144h] [rbp-314h]
  int v93; // [rsp+148h] [rbp-310h]
  int v94; // [rsp+14Ch] [rbp-30Ch]
  int v95; // [rsp+150h] [rbp-308h]
  int v96; // [rsp+154h] [rbp-304h]
  unsigned int v97; // [rsp+158h] [rbp-300h] BYREF
  int v98; // [rsp+15Ch] [rbp-2FCh]
  int v99; // [rsp+160h] [rbp-2F8h]
  int v100; // [rsp+164h] [rbp-2F4h]
  BOOL v101; // [rsp+168h] [rbp-2F0h]
  _WORD v102[6]; // [rsp+16Ch] [rbp-2ECh] BYREF
  _UNKNOWN **v103; // [rsp+178h] [rbp-2E0h]
  _UNKNOWN **v104; // [rsp+180h] [rbp-2D8h]
  _UNKNOWN **v105; // [rsp+188h] [rbp-2D0h]
  _UNKNOWN **v106; // [rsp+190h] [rbp-2C8h]
  _UNKNOWN **v107; // [rsp+198h] [rbp-2C0h]
  _UNKNOWN **v108; // [rsp+1A0h] [rbp-2B8h]
  _UNKNOWN **v109; // [rsp+1A8h] [rbp-2B0h]
  _UNKNOWN **v110; // [rsp+1B0h] [rbp-2A8h]
  _UNKNOWN **v111; // [rsp+1B8h] [rbp-2A0h]
  _UNKNOWN **v112; // [rsp+1C0h] [rbp-298h]
  _UNKNOWN **v113; // [rsp+1C8h] [rbp-290h]
  _UNKNOWN **v114; // [rsp+1D0h] [rbp-288h]
  _UNKNOWN **v115; // [rsp+1D8h] [rbp-280h]
  _UNKNOWN **v116; // [rsp+1E0h] [rbp-278h]
  _UNKNOWN **v117; // [rsp+1E8h] [rbp-270h]
  _UNKNOWN **v118; // [rsp+1F0h] [rbp-268h]
  _UNKNOWN **v119; // [rsp+1F8h] [rbp-260h]
  _UNKNOWN **v120; // [rsp+200h] [rbp-258h]
  _UNKNOWN **v121; // [rsp+208h] [rbp-250h]
  _UNKNOWN **v122; // [rsp+210h] [rbp-248h]
  _UNKNOWN **v123; // [rsp+218h] [rbp-240h]
  _UNKNOWN **v124; // [rsp+220h] [rbp-238h]
  _UNKNOWN **v125; // [rsp+228h] [rbp-230h]
  _UNKNOWN **v126; // [rsp+230h] [rbp-228h]
  _UNKNOWN **v127; // [rsp+238h] [rbp-220h]
  _UNKNOWN **v128; // [rsp+240h] [rbp-218h]
  _UNKNOWN **v129; // [rsp+248h] [rbp-210h]
  _UNKNOWN **v130; // [rsp+250h] [rbp-208h]
  _UNKNOWN **v131; // [rsp+258h] [rbp-200h]
  _UNKNOWN **v132; // [rsp+260h] [rbp-1F8h]
  _UNKNOWN **v133; // [rsp+268h] [rbp-1F0h]
  _UNKNOWN **v134; // [rsp+270h] [rbp-1E8h]
  _UNKNOWN **v135; // [rsp+278h] [rbp-1E0h]
  _UNKNOWN **v136; // [rsp+280h] [rbp-1D8h]
  _UNKNOWN **v137; // [rsp+288h] [rbp-1D0h]
  _UNKNOWN **v138; // [rsp+290h] [rbp-1C8h]
  _UNKNOWN **v139; // [rsp+298h] [rbp-1C0h]
  _UNKNOWN **v140; // [rsp+2A0h] [rbp-1B8h]
  _UNKNOWN **v141; // [rsp+2A8h] [rbp-1B0h]
  _UNKNOWN **v142; // [rsp+2B0h] [rbp-1A8h]
  _UNKNOWN **v143; // [rsp+2B8h] [rbp-1A0h]
  _UNKNOWN **v144; // [rsp+2C0h] [rbp-198h]
  _UNKNOWN **v145; // [rsp+2C8h] [rbp-190h]
  __int64 v146; // [rsp+2D0h] [rbp-188h]
  unsigned int *v147; // [rsp+2D8h] [rbp-180h]
  _WORD v148[4]; // [rsp+2E0h] [rbp-178h] BYREF
  _WORD *v149; // [rsp+2E8h] [rbp-170h]
  _WORD v150[4]; // [rsp+2F0h] [rbp-168h] BYREF
  _WORD *v151; // [rsp+2F8h] [rbp-160h]
  __int64 v152; // [rsp+300h] [rbp-158h]
  char *v153; // [rsp+308h] [rbp-150h]
  _WORD v154[4]; // [rsp+310h] [rbp-148h] BYREF
  _WORD *v155; // [rsp+318h] [rbp-140h]
  _WORD v156[4]; // [rsp+320h] [rbp-138h] BYREF
  _WORD *v157; // [rsp+328h] [rbp-130h]
  _UNKNOWN **v158; // [rsp+330h] [rbp-128h]
  char v159; // [rsp+33Ch] [rbp-11Ch] BYREF
  _WORD v160[8]; // [rsp+340h] [rbp-118h] BYREF
  _QWORD v161[4]; // [rsp+350h] [rbp-108h] BYREF
  _QWORD v162[3]; // [rsp+370h] [rbp-E8h] BYREF
  _WORD v163[28]; // [rsp+38Eh] [rbp-CAh] BYREF
  _WORD v164[73]; // [rsp+3C6h] [rbp-92h] BYREF

  v158 = jpt_14002AAE0;
  v101 = sub_14002BA40(&byte_14003A810, 12, 0) != dword_14003A81C;
  v3 = (__int64)jpt_14002B030;
  v145 = jpt_14002B030;
  v93 = 36;
  v144 = jpt_14002B90A;
  v143 = jpt_14002B030;
  v91 = 36;
  v142 = jpt_14002B6C2;
  v141 = jpt_14002BA31;
  v140 = jpt_14002B7FC;
  v139 = jpt_14002B030;
  v87 = 35;
  v138 = jpt_14002BA0B;
  v137 = jpt_14002B7B2;
  v136 = jpt_14002B822;
  v135 = jpt_14002B030;
  v83 = 34;
  v134 = jpt_14002B4DF;
  v133 = jpt_14002B750;
  v132 = jpt_14002B055;
  v131 = jpt_14002B881;
  v130 = jpt_14002B0B0;
  v129 = jpt_14002B9B4;
  v128 = jpt_14002B030;
  v76 = 18;
  v127 = jpt_14002AB17;
  v126 = &off_14003AC58;
  v125 = jpt_14002B696;
  v124 = jpt_14002B030;
  v72 = 22;
  v123 = jpt_14002B505;
  v122 = jpt_14002B4B9;
  v121 = jpt_14002B030;
  v69 = 25;
  v120 = &off_14003AC98;
  v119 = &off_14003ACA8;
  v118 = jpt_14002B7D6;
  v117 = jpt_14002B424;
  v116 = jpt_14002B030;
  v64 = 30;
  v115 = jpt_14002B030;
  v63 = 31;
  v114 = jpt_14002B6E8;
  _RDX = jpt_14002B70E;
  v113 = jpt_14002B70E;
  v112 = jpt_14002B030;
  v60 = 34;
  v111 = jpt_14002B030;
  v59 = 35;
  v110 = jpt_14002B030;
  v58 = 36;
  v109 = jpt_14002B030;
  v57 = 5;
  v108 = jpt_14002B030;
  v56 = 9;
  v107 = jpt_14002B030;
  v55 = 12;
  v106 = jpt_14002B030;
  v54 = 20;
  v105 = jpt_14002B030;
  v53 = 23;
  v104 = jpt_14002B030;
  v52 = 26;
  v103 = jpt_14002B030;
  v51 = 32;
  switch ( (unsigned __int64)jpt_14002B030 )
  {
    case 0uLL:
LABEL_86:
      while ( 2 )
      {
        v24 = (unsigned __int16 (*)(void))sub_14002FDC0(qword_14003BA40, 2729970938LL);
        v25 = v24();
        sub_14002BB60(&v43);
        for ( i = 0; i == 0; i = 1 )
          v43 ^= 0x172D5C59u;
        v12 = (unsigned int)(v25 - v43);
        v92 = v12 == 0;
        switch ( (_DWORD)v12 == 0 )
        {
          case false:
LABEL_73:
            v5 = sub_14002FCD0(0);
            v90 = v5 == 0;
            switch ( v5 == 0 )
            {
              case false:
LABEL_95:
                v27 = sub_140031DB0(*(_QWORD *)(v5 + 8), (unsigned int)&v50, 1179785, 3, 1, 96, 128);
                v86 = v27 >= 0;
                switch ( v27 >= 0 )
                {
                  case false:
LABEL_79:
                    nullsub_1();
                    v85 = 0;
LABEL_82:
                    nullsub_1();
                    v84 = 1;
                    v3 = 1;
LABEL_64:
                    v5 = v83;
                    LOBYTE(v12) = 1;
                    switch ( v83 )
                    {
                      case 0:
                        goto LABEL_39;
                      case 1:
                        continue;
                      case 2:
                        goto LABEL_5;
                      case 3:
                        goto LABEL_73;
                      case 4:
                        goto LABEL_96;
                      case 5:
                        goto LABEL_81;
                      case 6:
                        goto LABEL_90;
                      case 7:
                        goto LABEL_95;
                      case 8:
                        goto LABEL_79;
                      case 9:
                        goto LABEL_82;
                      case 10:
                        goto LABEL_64;
                      case 11:
                        goto LABEL_69;
                      case 12:
                        goto LABEL_76;
                      case 13:
                        goto LABEL_40;
                      case 14:
LABEL_85:
                        v3 = v41;
                        v23 = (unsigned int)dword_14003A814 + 16LL;
                        v79 = v41 >= v23;
                        switch ( v41 >= v23 )
                        {
                          case false:
                            goto LABEL_71;
                          case true:
                            goto LABEL_42;
                        }
                      case 15:
LABEL_42:
                        jj = sub_14002E070(v3);
                        v17 = sub_140032540(v50, jj, v41, 0);
                        v78 = v17 >= 0;
                        switch ( v17 >= 0 )
                        {
                          case false:
                            goto LABEL_3;
                          case true:
                            goto LABEL_94;
                        }
                      case 16:
LABEL_94:
                        v26 = sub_14002BBC0(jj + (unsigned int)dword_14003A814 + 8, &unk_14003A818, 4);
                        v77 = v26 == 0;
                        v3 = v26 == 0;
                        switch ( v26 == 0 )
                        {
                          case false:
                            goto LABEL_3;
                          case true:
                            goto LABEL_36;
                        }
                      case 17:
LABEL_36:
                        v5 = v76;
                        v10 = false;
                        v11 = true;
                        v12 = 0;
                        switch ( v76 )
                        {
                          case 0:
                            goto LABEL_39;
                          case 1:
                            continue;
                          case 2:
                            goto LABEL_5;
                          case 3:
                            goto LABEL_73;
                          case 4:
                            goto LABEL_96;
                          case 5:
                            goto LABEL_81;
                          case 6:
                            goto LABEL_90;
                          case 7:
                            goto LABEL_95;
                          case 8:
                            goto LABEL_79;
                          case 9:
                            goto LABEL_82;
                          case 10:
                            goto LABEL_64;
                          case 11:
                            goto LABEL_69;
                          case 12:
                            goto LABEL_76;
                          case 13:
                            goto LABEL_40;
                          case 14:
                            goto LABEL_85;
                          case 15:
                            goto LABEL_42;
                          case 16:
                            goto LABEL_94;
                          case 17:
                            goto LABEL_36;
                          case 18:
                            goto LABEL_3;
                          case 19:
                            goto LABEL_78;
                          case 20:
                            goto LABEL_72;
                          case 21:
                            goto LABEL_2;
                          case 22:
                            goto LABEL_70;
                          case 23:
                            goto LABEL_68;
                          case 24:
                            goto LABEL_63;
                          case 25:
                            goto LABEL_71;
                          case 26:
                            goto LABEL_25;
                          case 27:
                            goto LABEL_80;
                          case 28:
                            goto LABEL_43;
                          case 29:
                            goto LABEL_37;
                          case 30:
                            goto LABEL_41;
                          case 31:
                            goto LABEL_74;
                          case 32:
                            goto LABEL_75;
                          case 33:
                            goto LABEL_4;
                          case 34:
                            goto LABEL_91;
                          case 35:
                            goto LABEL_77;
                          case 36:
                            return v12;
                          case 37:
                            goto LABEL_83;
                          case 38:
                            goto LABEL_65;
                          case 39:
                            goto LABEL_92;
                        }
                      case 18:
LABEL_3:
                        v75 = 0;
                        goto LABEL_78;
                      case 19:
LABEL_78:
                        nullsub_1();
                        v74 = 1;
                        __asm { jmp     rax }
                        return result;
                      case 20:
LABEL_72:
                        nullsub_1();
                        sub_140001C10(jj);
                        v73 = 1;
                        v3 = 1;
                        goto LABEL_2;
                      case 21:
LABEL_2:
                        v5 = v72;
                        switch ( v72 )
                        {
                          case 0:
                            goto LABEL_39;
                          case 1:
                            continue;
                          case 2:
                            goto LABEL_5;
                          case 3:
                            goto LABEL_73;
                          case 4:
                            goto LABEL_96;
                          case 5:
                            goto LABEL_81;
                          case 6:
                            goto LABEL_90;
                          case 7:
                            goto LABEL_95;
                          case 8:
                            goto LABEL_79;
                          case 9:
                            goto LABEL_82;
                          case 10:
                            goto LABEL_64;
                          case 11:
                            goto LABEL_69;
                          case 12:
                            goto LABEL_76;
                          case 13:
                            goto LABEL_40;
                          case 14:
                            goto LABEL_85;
                          case 15:
                            goto LABEL_42;
                          case 16:
                            goto LABEL_94;
                          case 17:
                            goto LABEL_36;
                          case 18:
                            goto LABEL_3;
                          case 19:
                            goto LABEL_78;
                          case 20:
                            goto LABEL_72;
                          case 21:
                            goto LABEL_2;
                          case 22:
                            goto LABEL_70;
                          case 23:
                            goto LABEL_68;
                          case 24:
                            goto LABEL_63;
                          case 25:
                            goto LABEL_71;
                          case 26:
                            goto LABEL_25;
                          case 27:
                            goto LABEL_80;
                          case 28:
                            goto LABEL_43;
                          case 29:
                            goto LABEL_37;
                          case 30:
                            goto LABEL_41;
                          case 31:
                            goto LABEL_74;
                          case 32:
                            goto LABEL_75;
                          case 33:
                            goto LABEL_4;
                          case 34:
                            goto LABEL_91;
                          case 35:
                            goto LABEL_77;
                          case 36:
                            return v12;
                          case 37:
                            goto LABEL_83;
                          case 38:
                            goto LABEL_65;
                          case 39:
                            goto LABEL_92;
                        }
                      case 22:
LABEL_70:
                        nullsub_1();
                        v71 = 1;
                        goto LABEL_68;
                      case 23:
LABEL_68:
                        nullsub_1();
                        v70 = 0;
                        v3 = 0;
                        goto LABEL_63;
                      case 24:
LABEL_63:
                        v5 = v69;
                        switch ( v69 )
                        {
                          case 0:
                            goto LABEL_39;
                          case 1:
                            continue;
                          case 2:
                            goto LABEL_5;
                          case 3:
                            goto LABEL_73;
                          case 4:
                            goto LABEL_96;
                          case 5:
                            goto LABEL_81;
                          case 6:
                            goto LABEL_90;
                          case 7:
                            goto LABEL_95;
                          case 8:
                            goto LABEL_79;
                          case 9:
                            goto LABEL_82;
                          case 10:
                            goto LABEL_64;
                          case 11:
                            goto LABEL_69;
                          case 12:
                            goto LABEL_76;
                          case 13:
                            goto LABEL_40;
                          case 14:
                            goto LABEL_85;
                          case 15:
                            goto LABEL_42;
                          case 16:
                            goto LABEL_94;
                          case 17:
                            goto LABEL_36;
                          case 18:
                            goto LABEL_3;
                          case 19:
                            goto LABEL_78;
                          case 20:
                            goto LABEL_72;
                          case 21:
                            goto LABEL_2;
                          case 22:
                            goto LABEL_70;
                          case 23:
                            goto LABEL_68;
                          case 24:
                            goto LABEL_63;
                          case 25:
                            goto LABEL_71;
                          case 26:
                            goto LABEL_25;
                          case 27:
                            goto LABEL_80;
                          case 28:
                            goto LABEL_43;
                          case 29:
                            goto LABEL_37;
                          case 30:
                            goto LABEL_41;
                          case 31:
                            goto LABEL_74;
                          case 32:
                            goto LABEL_75;
                          case 33:
                            goto LABEL_4;
                          case 34:
                            goto LABEL_91;
                          case 35:
                            goto LABEL_77;
                          case 36:
                            return v12;
                          case 37:
                            goto LABEL_83;
                          case 38:
                            goto LABEL_65;
                          case 39:
                            goto LABEL_92;
                        }
                      case 25:
LABEL_71:
                        nullsub_1();
                        v68 = 1;
                        __asm { jmp     rax }
                        return result;
                      case 26:
LABEL_25:
                        for ( j = 0; ; ++j )
                        {
                          v14 = j < qword_14003BB50;
                          if ( j >= qword_14003BB50 )
                            break;
                          v15 = *(_DWORD *)(qword_14003BB58 + 8 * j) == -1825720177;
                          if ( *(_DWORD *)(qword_14003BB58 + 8 * j) == -1825720177 )
                            sub_14002F100(*(_DWORD *)(8 * j + qword_14003BB58 + 4), 1, v50, v2, v28, v29);
                          if ( v15 )
                            break;
                        }
                        if ( !v14 )
                        {
                          sub_140016C90((__int64)&v49, &v46);
                          for ( k = 0; k == 0; k = 1 )
                            v46 = (-2 - ((~v46 | 0xF8F5E2A6) + v46)) & (v46 | 0xF8F5E2A6);
                        }
                        v67 = 1;
                        __asm { jmp     rax }
                        return result;
                      case 27:
LABEL_80:
                        v66 = v12 & 1;
                        switch ( v12 & 1 )
                        {
                          case 0LL:
                            goto LABEL_43;
                          case 1LL:
                            goto LABEL_74;
                        }
                      case 28:
LABEL_43:
                        sub_14002BBF0(v164);
                        v150[0] = 96;
                        v150[1] = 98;
                        for ( m = 0; ; v164[v18] ^= 25393 * (_WORD)m )
                        {
                          nullsub_1();
                          nullsub_1();
                          if ( m >= 0x31 )
                            break;
                          v18 = (int)m++;
                        }
                        v151 = v164;
                        sub_14002BC40(v102);
                        v148[0] = 10;
                        v148[1] = 12;
                        for ( n = 0;
                              n < 6;
                              v102[v19] = (v102[v19]
                                         | ((n & 0x1954 ^ 0x1954) * (n & 0xE6AB) + (n & 0x1954) * (n | 0x1954)) & 0xFFFC)
                                        ^ v102[v19]
                                        & ((n & 0x1954 ^ 0x1954) * (n & 0xE6AB) + (n & 0x1954) * (n | 0x1954)) )
                        {
                          nullsub_1();
                          nullsub_1();
                          v19 = (int)n++;
                        }
                        v149 = v102;
                        v161[0] = v150;
                        v161[1] = v148;
                        v161[2] = 17;
                        v147 = &v97;
                        v96 = 0;
                        v146 = 3;
                        v95 = 3;
                        sub_14002BC60(&v40);
                        for ( ii = 0; ii == 0; ii = 1 )
                        {
                          LOBYTE(_RDX) = 1;
                          v40 ^= 0x4C7A367Du;
                        }
                        v94 = v40;
                        for ( jj = 0; ; ++jj )
                        {
                          v20 = jj < qword_14003BB50;
                          if ( jj >= qword_14003BB50 )
                            break;
                          LOBYTE(_RDX) = 8 * jj;
                          LOBYTE(v0) = *(_DWORD *)(qword_14003BB58 + 8 * jj) == -144319733;
                          if ( *(_DWORD *)(qword_14003BB58 + 8 * jj) == -144319733 )
                            sub_14002F100(*(_DWORD *)(8 * jj + qword_14003BB58 + 4), 6, v94, v95, v146, (__int64)v161);
                          if ( (v0 & 1) != 0 )
                            break;
                        }
                        if ( !v20 )
                        {
                          sub_140016C90((__int64)&v47, &v44);
                          v36 = 0;
                          while ( v36 == 0 )
                          {
                            v36 = 1;
                            v2 = ~v44;
                            LODWORD(_RDX) = (~v44 | 0xF8F5E2A6) + v44;
                            v44 = (-2 - (_DWORD)_RDX) & (v44 | 0xF8F5E2A6);
                          }
                        }
                        v10 = v97 < 6;
                        v11 = v97 == 6;
                        v65 = v97 == 6;
                        v3 = v97 == 6;
                        switch ( v97 == 6 )
                        {
                          case false:
                            goto LABEL_41;
                          case true:
                            goto LABEL_37;
                        }
                      case 29:
LABEL_37:
                        v5 = v64;
                        LOBYTE(v12) = 1;
                        switch ( v64 )
                        {
                          case 0:
                            goto LABEL_39;
                          case 1:
                            continue;
                          case 2:
                            goto LABEL_5;
                          case 3:
                            goto LABEL_73;
                          case 4:
                            goto LABEL_96;
                          case 5:
                            goto LABEL_81;
                          case 6:
                            goto LABEL_90;
                          case 7:
                            goto LABEL_95;
                          case 8:
                            goto LABEL_79;
                          case 9:
                            goto LABEL_82;
                          case 10:
                            goto LABEL_64;
                          case 11:
                            goto LABEL_69;
                          case 12:
                            goto LABEL_76;
                          case 13:
                            goto LABEL_40;
                          case 14:
                            goto LABEL_85;
                          case 15:
                            goto LABEL_42;
                          case 16:
                            goto LABEL_94;
                          case 17:
                            goto LABEL_36;
                          case 18:
                            goto LABEL_3;
                          case 19:
                            goto LABEL_78;
                          case 20:
                            goto LABEL_72;
                          case 21:
                            goto LABEL_2;
                          case 22:
                            goto LABEL_70;
                          case 23:
                            goto LABEL_68;
                          case 24:
                            goto LABEL_63;
                          case 25:
                            goto LABEL_71;
                          case 26:
                            goto LABEL_25;
                          case 27:
                            goto LABEL_80;
                          case 28:
                            goto LABEL_43;
                          case 29:
                            goto LABEL_37;
                          case 30:
                            goto LABEL_41;
                          case 31:
                            goto LABEL_74;
                          case 32:
                            goto LABEL_75;
                          case 33:
                            goto LABEL_4;
                          case 34:
                            goto LABEL_91;
                          case 35:
                            goto LABEL_77;
                          case 36:
                            return v12;
                          case 37:
                            goto LABEL_83;
                          case 38:
                            goto LABEL_65;
                          case 39:
                            goto LABEL_92;
                        }
                      case 30:
LABEL_41:
                        v5 = v63;
                        switch ( v63 )
                        {
                          case 0:
                            goto LABEL_39;
                          case 1:
                            continue;
                          case 2:
                            goto LABEL_5;
                          case 3:
                            goto LABEL_73;
                          case 4:
                            goto LABEL_96;
                          case 5:
                            goto LABEL_81;
                          case 6:
                            goto LABEL_90;
                          case 7:
                            goto LABEL_95;
                          case 8:
                            goto LABEL_79;
                          case 9:
                            goto LABEL_82;
                          case 10:
                            goto LABEL_64;
                          case 11:
                            goto LABEL_69;
                          case 12:
                            goto LABEL_76;
                          case 13:
                            goto LABEL_40;
                          case 14:
                            goto LABEL_85;
                          case 15:
                            goto LABEL_42;
                          case 16:
                            goto LABEL_94;
                          case 17:
                            goto LABEL_36;
                          case 18:
                            goto LABEL_3;
                          case 19:
                            goto LABEL_78;
                          case 20:
                            goto LABEL_72;
                          case 21:
                            goto LABEL_2;
                          case 22:
                            goto LABEL_70;
                          case 23:
                            goto LABEL_68;
                          case 24:
                            goto LABEL_63;
                          case 25:
                            goto LABEL_71;
                          case 26:
                            goto LABEL_25;
                          case 27:
                            goto LABEL_80;
                          case 28:
                            goto LABEL_43;
                          case 29:
                            goto LABEL_37;
                          case 30:
                            goto LABEL_41;
                          case 31:
                            goto LABEL_74;
                          case 32:
                            goto LABEL_75;
                          case 33:
                            goto LABEL_4;
                          case 34:
                            goto LABEL_91;
                          case 35:
                            goto LABEL_77;
                          case 36:
                            return v12;
                          case 37:
                            goto LABEL_83;
                          case 38:
                            goto LABEL_65;
                          case 39:
                            goto LABEL_92;
                        }
                      case 31:
LABEL_74:
                        nullsub_1();
                        v62 = 1;
                        goto LABEL_75;
                      case 32:
LABEL_75:
                        nullsub_1();
                        v61 = 0;
                        v3 = 0;
                        break;
                      case 33:
                        break;
                      case 34:
LABEL_91:
                        v5 = v59;
                        switch ( v59 )
                        {
                          case 0:
                            goto LABEL_39;
                          case 1:
                            continue;
                          case 2:
                            goto LABEL_5;
                          case 3:
                            goto LABEL_73;
                          case 4:
                            goto LABEL_96;
                          case 5:
                            goto LABEL_81;
                          case 6:
                            goto LABEL_90;
                          case 7:
                            goto LABEL_95;
                          case 8:
                            goto LABEL_79;
                          case 9:
                            goto LABEL_82;
                          case 10:
                            goto LABEL_64;
                          case 11:
                            goto LABEL_69;
                          case 12:
                            goto LABEL_76;
                          case 13:
                            goto LABEL_40;
                          case 14:
                            goto LABEL_85;
                          case 15:
                            goto LABEL_42;
                          case 16:
                            goto LABEL_94;
                          case 17:
                            goto LABEL_36;
                          case 18:
                            goto LABEL_3;
                          case 19:
                            goto LABEL_78;
                          case 20:
                            goto LABEL_72;
                          case 21:
                            goto LABEL_2;
                          case 22:
                            goto LABEL_70;
                          case 23:
                            goto LABEL_68;
                          case 24:
                            goto LABEL_63;
                          case 25:
                            goto LABEL_71;
                          case 26:
                            goto LABEL_25;
                          case 27:
                            goto LABEL_80;
                          case 28:
                            goto LABEL_43;
                          case 29:
                            goto LABEL_37;
                          case 30:
                            goto LABEL_41;
                          case 31:
                            goto LABEL_74;
                          case 32:
                            goto LABEL_75;
                          case 33:
                            goto LABEL_4;
                          case 34:
                            goto LABEL_91;
                          case 35:
                            goto LABEL_77;
                          case 36:
                            return v12;
                          case 37:
                            goto LABEL_83;
                          case 38:
                            goto LABEL_65;
                          case 39:
                            goto LABEL_92;
                        }
                      case 35:
LABEL_77:
                        v5 = v58;
                        switch ( v58 )
                        {
                          case 0:
                            goto LABEL_39;
                          case 1:
                            continue;
                          case 2:
                            goto LABEL_5;
                          case 3:
                            goto LABEL_73;
                          case 4:
                            goto LABEL_96;
                          case 5:
                            goto LABEL_81;
                          case 6:
                            goto LABEL_90;
                          case 7:
                            goto LABEL_95;
                          case 8:
                            goto LABEL_79;
                          case 9:
                            goto LABEL_82;
                          case 10:
                            goto LABEL_64;
                          case 11:
                            goto LABEL_69;
                          case 12:
                            goto LABEL_76;
                          case 13:
                            goto LABEL_40;
                          case 14:
                            goto LABEL_85;
                          case 15:
                            goto LABEL_42;
                          case 16:
                            goto LABEL_94;
                          case 17:
                            goto LABEL_36;
                          case 18:
                            goto LABEL_3;
                          case 19:
                            goto LABEL_78;
                          case 20:
                            goto LABEL_72;
                          case 21:
                            goto LABEL_2;
                          case 22:
                            goto LABEL_70;
                          case 23:
                            goto LABEL_68;
                          case 24:
                            goto LABEL_63;
                          case 25:
                            goto LABEL_71;
                          case 26:
                            goto LABEL_25;
                          case 27:
                            goto LABEL_80;
                          case 28:
                            goto LABEL_43;
                          case 29:
                            goto LABEL_37;
                          case 30:
                            goto LABEL_41;
                          case 31:
                            goto LABEL_74;
                          case 32:
                            goto LABEL_75;
                          case 33:
                            goto LABEL_4;
                          case 34:
                            goto LABEL_91;
                          case 35:
                            goto LABEL_77;
                          case 36:
                            return v12;
                          case 37:
                            goto LABEL_83;
                          case 38:
                            goto LABEL_65;
                          case 39:
                            goto LABEL_92;
                        }
                      case 36:
                        return v12;
                      case 37:
LABEL_83:
                        *(_BYTE *)jj = v5;
                        JUMPOUT(0x14002B826LL);
                      case 38:
LABEL_65:
                        if ( !v11 )
                        {
                          BYTE1(_RDX) = -v10;
                          __asm { insd }
                          *(_DWORD *)(v3 - 17) -= v22;
                          JUMPOUT(0x14002B485LL);
                        }
                        JUMPOUT(0x14002B498LL);
                      case 39:
LABEL_92:
                        *(_BYTE *)jj = v5;
                        *(_DWORD *)(v12 + 115) = v0;
                        JUMPOUT(0x14002B93FLL);
                    }
LABEL_4:
                    v5 = v60;
                    switch ( v60 )
                    {
                      case 0:
                        goto LABEL_39;
                      case 1:
                        continue;
                      case 2:
                        goto LABEL_5;
                      case 3:
                        goto LABEL_73;
                      case 4:
                        goto LABEL_96;
                      case 5:
                        goto LABEL_81;
                      case 6:
                        goto LABEL_90;
                      case 7:
                        goto LABEL_95;
                      case 8:
                        goto LABEL_79;
                      case 9:
                        goto LABEL_82;
                      case 10:
                        goto LABEL_64;
                      case 11:
                        goto LABEL_69;
                      case 12:
                        goto LABEL_76;
                      case 13:
                        goto LABEL_40;
                      case 14:
                        goto LABEL_85;
                      case 15:
                        goto LABEL_42;
                      case 16:
                        goto LABEL_94;
                      case 17:
                        goto LABEL_36;
                      case 18:
                        goto LABEL_3;
                      case 19:
                        goto LABEL_78;
                      case 20:
                        goto LABEL_72;
                      case 21:
                        goto LABEL_2;
                      case 22:
                        goto LABEL_70;
                      case 23:
                        goto LABEL_68;
                      case 24:
                        goto LABEL_63;
                      case 25:
                        goto LABEL_71;
                      case 26:
                        goto LABEL_25;
                      case 27:
                        goto LABEL_80;
                      case 28:
                        goto LABEL_43;
                      case 29:
                        goto LABEL_37;
                      case 30:
                        goto LABEL_41;
                      case 31:
                        goto LABEL_74;
                      case 32:
                        goto LABEL_75;
                      case 33:
                        goto LABEL_4;
                      case 34:
                        goto LABEL_91;
                      case 35:
                        goto LABEL_77;
                      case 36:
                        return v12;
                      case 37:
                        goto LABEL_83;
                      case 38:
                        goto LABEL_65;
                      case 39:
                        goto LABEL_92;
                    }
                  case true:
LABEL_69:
                    nullsub_1();
                    v82 = 1;
LABEL_76:
                    nullsub_1();
                    LOBYTE(v5) = (int)sub_140032460(v50, &v41, 0) >= 0;
                    v81 = 1;
LABEL_40:
                    v80 = v5 & 1;
                    switch ( v5 & 1 )
                    {
                      case 0LL:
                        goto LABEL_71;
                      case 1LL:
                        goto LABEL_85;
                    }
                }
              case true:
LABEL_96:
                nullsub_1();
                v89 = 0;
LABEL_81:
                nullsub_1();
                v88 = 0;
                v3 = 0;
LABEL_90:
                v5 = v87;
                LOBYTE(v12) = 1;
                switch ( v87 )
                {
                  case 0:
                    goto LABEL_39;
                  case 1:
                    continue;
                  case 2:
                    goto LABEL_5;
                  case 3:
                    goto LABEL_73;
                  case 4:
                    goto LABEL_96;
                  case 5:
                    goto LABEL_81;
                  case 6:
                    goto LABEL_90;
                  case 7:
                    goto LABEL_95;
                  case 8:
                    goto LABEL_79;
                  case 9:
                    goto LABEL_82;
                  case 10:
                    goto LABEL_64;
                  case 11:
                    goto LABEL_69;
                  case 12:
                    goto LABEL_76;
                  case 13:
                    goto LABEL_40;
                  case 14:
                    goto LABEL_85;
                  case 15:
                    goto LABEL_42;
                  case 16:
                    goto LABEL_94;
                  case 17:
                    goto LABEL_36;
                  case 18:
                    goto LABEL_3;
                  case 19:
                    goto LABEL_78;
                  case 20:
                    goto LABEL_72;
                  case 21:
                    goto LABEL_2;
                  case 22:
                    goto LABEL_70;
                  case 23:
                    goto LABEL_68;
                  case 24:
                    goto LABEL_63;
                  case 25:
                    goto LABEL_71;
                  case 26:
                    goto LABEL_25;
                  case 27:
                    goto LABEL_80;
                  case 28:
                    goto LABEL_43;
                  case 29:
                    goto LABEL_37;
                  case 30:
                    goto LABEL_41;
                  case 31:
                    goto LABEL_74;
                  case 32:
                    goto LABEL_75;
                  case 33:
                    goto LABEL_4;
                  case 34:
                    goto LABEL_91;
                  case 35:
                    goto LABEL_77;
                  case 36:
                    return v12;
                  case 37:
                    goto LABEL_83;
                  case 38:
                    goto LABEL_65;
                  case 39:
                    goto LABEL_92;
                }
            }
          case true:
LABEL_5:
            sub_14002BB70(v163);
            v156[0] = 54;
            v156[1] = 56;
            for ( kk = 0;
                  kk < 0x1C;
                  v163[v6] = v163[v6]
                           & ((kk & 0x40D2 ^ 0x40D2) * (kk & 0xBF2D) + (kk & 0x40D2) * (kk | 0x40D2))
                           ^ (v163[v6]
                            | ((kk & 0x40D2 ^ 0x40D2) * (kk & 0xBF2D) + (kk & 0x40D2) * (kk | 0x40D2)) & 0xFFFE) )
            {
              v6 = (int)kk++;
            }
            v157 = v163;
            sub_14002BBA0(v160);
            v154[0] = 14;
            v154[1] = 16;
            for ( mm = 0; mm < 8; v160[v7] ^= -2317 * (_WORD)mm )
              v7 = (int)mm++;
            v155 = v160;
            v162[0] = v156;
            v162[1] = v154;
            v162[2] = 48;
            v153 = &v159;
            v100 = 0;
            v152 = 3;
            v99 = 3;
            sub_14002BBB0(&v42);
            v33 = 0;
            while ( v33 == 0 )
            {
              v33 = 1;
              LOBYTE(_RDX) = 0;
              v3 = v42 ^ 0x71D3C96Au;
              v42 ^= 0x71D3C96Au;
            }
            v98 = v42;
            for ( nn = 0; ; ++nn )
            {
              v9 = nn < qword_14003BB50;
              if ( nn >= qword_14003BB50 )
                break;
              v3 = qword_14003BB58;
              LOBYTE(_RDX) = 8 * nn;
              LOBYTE(jj) = *(_DWORD *)(qword_14003BB58 + 8 * nn) == -144319733;
              if ( *(_DWORD *)(qword_14003BB58 + 8 * nn) == -144319733 )
                sub_14002F100(*(_DWORD *)(8 * nn + qword_14003BB58 + 4), 6, v98, v99, v152, (__int64)v162);
              if ( (jj & 1) != 0 )
                break;
            }
            if ( !v9 )
            {
              sub_140016C90((__int64)v48, &v45);
              v35 = 0;
              while ( v35 == 0 )
              {
                v35 = 1;
                v2 = ~v45;
                LODWORD(_RDX) = (~v45 | 0xF8F5E2A6) + v45;
                v3 = (unsigned int)(-2 - (_DWORD)_RDX);
                v45 = v3 & (v45 | 0xF8F5E2A6);
              }
            }
            v5 = v91;
            v10 = false;
            v11 = true;
            v12 = 0;
            switch ( v91 )
            {
              case 0:
                goto LABEL_39;
              case 1:
                continue;
              case 2:
                goto LABEL_5;
              case 3:
                goto LABEL_73;
              case 4:
                goto LABEL_96;
              case 5:
                goto LABEL_81;
              case 6:
                goto LABEL_90;
              case 7:
                goto LABEL_95;
              case 8:
                goto LABEL_79;
              case 9:
                goto LABEL_82;
              case 10:
                goto LABEL_64;
              case 11:
                goto LABEL_69;
              case 12:
                goto LABEL_76;
              case 13:
                goto LABEL_40;
              case 14:
                goto LABEL_85;
              case 15:
                goto LABEL_42;
              case 16:
                goto LABEL_94;
              case 17:
                goto LABEL_36;
              case 18:
                goto LABEL_3;
              case 19:
                goto LABEL_78;
              case 20:
                goto LABEL_72;
              case 21:
                goto LABEL_2;
              case 22:
                goto LABEL_70;
              case 23:
                goto LABEL_68;
              case 24:
                goto LABEL_63;
              case 25:
                goto LABEL_71;
              case 26:
                goto LABEL_25;
              case 27:
                goto LABEL_80;
              case 28:
                goto LABEL_43;
              case 29:
                goto LABEL_37;
              case 30:
                goto LABEL_41;
              case 31:
                goto LABEL_74;
              case 32:
                goto LABEL_75;
              case 33:
                goto LABEL_4;
              case 34:
                goto LABEL_91;
              case 35:
                goto LABEL_77;
              case 36:
                return v12;
              case 37:
                goto LABEL_83;
              case 38:
                goto LABEL_65;
              case 39:
                goto LABEL_92;
            }
        }
      }
    case 1uLL:
LABEL_39:
      while ( 2 )
      {
        v5 = v93;
        v10 = false;
        v11 = true;
        v12 = 0;
        switch ( v93 )
        {
          case 0:
            continue;
          case 1:
            goto LABEL_86;
          case 2:
            goto LABEL_5;
          case 3:
            goto LABEL_73;
          case 4:
            goto LABEL_96;
          case 5:
            goto LABEL_81;
          case 6:
            goto LABEL_90;
          case 7:
            goto LABEL_95;
          case 8:
            goto LABEL_79;
          case 9:
            goto LABEL_82;
          case 10:
            goto LABEL_64;
          case 11:
            goto LABEL_69;
          case 12:
            goto LABEL_76;
          case 13:
            goto LABEL_40;
          case 14:
            goto LABEL_85;
          case 15:
            goto LABEL_42;
          case 16:
            goto LABEL_94;
          case 17:
            goto LABEL_36;
          case 18:
            goto LABEL_3;
          case 19:
            goto LABEL_78;
          case 20:
            goto LABEL_72;
          case 21:
            goto LABEL_2;
          case 22:
            goto LABEL_70;
          case 23:
            goto LABEL_68;
          case 24:
            goto LABEL_63;
          case 25:
            goto LABEL_71;
          case 26:
            goto LABEL_25;
          case 27:
            goto LABEL_80;
          case 28:
            goto LABEL_43;
          case 29:
            goto LABEL_37;
          case 30:
            goto LABEL_41;
          case 31:
            goto LABEL_74;
          case 32:
            goto LABEL_75;
          case 33:
            goto LABEL_4;
          case 34:
            goto LABEL_91;
          case 35:
            goto LABEL_77;
          case 36:
            return v12;
          case 37:
            goto LABEL_83;
          case 38:
            goto LABEL_65;
          case 39:
            goto LABEL_92;
        }
      }
  }
}


// ---- sub_14002BA40 @ 0x14002ba40 ----
__int64 __fastcall sub_14002BA40(unsigned __int8 *a1, __int64 a2, unsigned int a3)
{
  __int64 result; // rax
  int v4; // r8d
  unsigned int v5; // eax
  __int64 v6; // r9
  int i; // r10d
  unsigned int v8; // edx
  int j; // eax
  int v10; // r10d
  int v11; // [rsp+0h] [rbp-4h]

  result = a3;
  v11 = 0;
  v4 = -201853261;
  do
  {
    ++v11;
    v4 ^= (v11 & 0xE1B08A6C) * (v11 & 0x1E4F7593 ^ 0x1E4F7593) + (v11 & 0x1E4F7593) * (v11 | 0x1E4F7593);
  }
  while ( v11 == 0 );
  if ( a2 != 0 )
  {
    v5 = ~(_DWORD)result;
    if ( (a2 & 1) != 0 )
    {
      v6 = a2 - 1;
      v5 ^= *a1;
      for ( i = 8; i != 0; --i )
        v5 = (v5 >> 1) ^ v4 & -(v5 & 1);
      ++a1;
      if ( a2 == 1 )
        return ~v5;
    }
    else
    {
      v6 = a2;
      if ( a2 == 1 )
        return ~v5;
    }
    do
    {
      v8 = v5 ^ *a1;
      for ( j = 8; j != 0; --j )
        v8 = (v8 >> 1) ^ v4 & -(v8 & 1);
      v6 -= 2;
      v10 = 8;
      v5 = a1[1] ^ v8;
      do
      {
        v5 = (v5 >> 1) ^ v4 & -(v5 & 1);
        --v10;
      }
      while ( v10 != 0 );
      a1 += 2;
    }
    while ( v6 != 0 );
    return ~v5;
  }
  return result;
}


// ---- sub_14002BB60 @ 0x14002bb60 ----
void __fastcall sub_14002BB60(_DWORD *a1)
{
  *a1 = 388847680;
}


// ---- sub_14002BB70 @ 0x14002bb70 ----
__int64 __fastcall sub_14002BB70(__int64 a1)
{
  *(_OWORD *)(a1 + 32) = xmmword_140034BF8;
  *(_OWORD *)(a1 + 16) = xmmword_140034BE8;
  *(_OWORD *)a1 = xmmword_140034BD8;
  *(_QWORD *)(a1 + 48) = 0x16F8D662951154D5LL;
  return 0x16F8D662951154D5LL;
}


// ---- sub_14002BBA0 @ 0x14002bba0 ----
void __fastcall sub_14002BBA0(_OWORD *a1)
{
  *a1 = xmmword_140034C10;
}


// ---- sub_14002BBB0 @ 0x14002bbb0 ----
void __fastcall sub_14002BBB0(_DWORD *a1)
{
  *a1 = 567527794;
}


// ---- sub_14002BBC0 @ 0x14002bbc0 ----
__int64 __fastcall sub_14002BBC0(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // rax
  __int64 v4; // r9
  int v5; // r10d
  int v6; // r11d

  result = 0;
  v4 = 0;
  while ( a3 != v4 )
  {
    v5 = *(unsigned __int8 *)(a1 + v4);
    v6 = *(unsigned __int8 *)(a2 + v4++);
    if ( (_BYTE)v5 != (_BYTE)v6 )
      return (unsigned int)(v5 - v6);
  }
  return result;
}


// ---- sub_14002BBF0 @ 0x14002bbf0 ----
void __fastcall sub_14002BBF0(__int64 a1)
{
  *(_OWORD *)(a1 + 80) = xmmword_140034C70;
  *(_OWORD *)(a1 + 64) = xmmword_140034C60;
  *(_OWORD *)(a1 + 48) = xmmword_140034C50;
  *(_OWORD *)(a1 + 32) = xmmword_140034C40;
  *(_OWORD *)(a1 + 16) = xmmword_140034C30;
  *(_OWORD *)a1 = xmmword_140034C20;
  *(_WORD *)(a1 + 96) = -927;
}


// ---- sub_14002BC40 @ 0x14002bc40 ----
__int64 __fastcall sub_14002BC40(__int64 a1)
{
  *(_QWORD *)a1 = 0x65054BB132ED1906LL;
  *(_DWORD *)(a1 + 8) = -1745322249;
  return 0x65054BB132ED1906LL;
}


// ---- sub_14002BC60 @ 0x14002bc60 ----
void __fastcall sub_14002BC60(_DWORD *a1)
{
  *a1 = 477771365;
}


// ---- sub_14002BC70 @ 0x14002bc70 ----
bool sub_14002BC70()
{
  int v5; // esi
  __int64 v6; // rdx
  __int64 v7; // r8
  int v13; // eax
  int j; // [rsp+20h] [rbp-48h]
  int i; // [rsp+24h] [rbp-44h]
  int m; // [rsp+28h] [rbp-40h]
  int k; // [rsp+2Ch] [rbp-3Ch]
  unsigned int v20; // [rsp+30h] [rbp-38h] BYREF
  unsigned int v21; // [rsp+34h] [rbp-34h] BYREF
  int v22; // [rsp+38h] [rbp-30h] BYREF
  _DWORD v23[2]; // [rsp+3Ch] [rbp-2Ch] BYREF
  _DWORD v24[9]; // [rsp+44h] [rbp-24h] BYREF

  sub_14002BE40(v23);
  for ( i = 0; i == 0; i = 1 )
    v23[0] ^= 0x6AB1B030u;
  sub_14002BE40(&v21);
  for ( j = 0; j == 0; j = 1 )
    v21 ^= 0x6AB1B030u;
  _RAX = v21;
  __asm { cpuid }
  v5 = _RCX;
  sub_14002BE50(&v22, _RDX, _RBX);
  for ( k = 0; k == 0; k = 1 )
    v22 ^= 0x8E929E1u;
  sub_14002BE50(&v20, v6, v7);
  for ( m = 0; m == 0; m = 1 )
    v20 ^= 0x8E929E1u;
  _RAX = v20;
  __asm { cpuid }
  v23[1] = _RAX;
  v24[0] = _RBX;
  v24[1] = _RCX;
  v24[2] = _RDX;
  v13 = sub_14002BA40((unsigned __int8 *)v24, 12, 0x69A88187u);
  return v13 == -1644060089
      || v13 == -197019311
      || v13 == -790740309
      || v13 == 1087180071
      || v13 == -374298321
      || v13 != -1808286998 && v5 < 0;
}


// ---- sub_14002BE40 @ 0x14002be40 ----
void __fastcall sub_14002BE40(_DWORD *a1)
{
  *a1 = 1790029873;
}


// ---- sub_14002BE50 @ 0x14002be50 ----
void __fastcall sub_14002BE50(_DWORD *a1)
{
  *a1 = 1223240161;
}


// ---- sub_14002BE60 @ 0x14002be60 ----
bool sub_14002BE60()
{
  __int64 v0; // rdx
  __int64 v1; // rcx
  __int64 v2; // r8
  __int64 v3; // r9
  void *v4; // rsp
  __int64 *v5; // r14
  __int64 v6; // rdx
  __int64 v7; // rcx
  __int64 v8; // r8
  __int64 v9; // r9
  void *v10; // rsp
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // r8
  __int64 v14; // r9
  void *v15; // rsp
  __int64 v16; // rdx
  __int64 v17; // rcx
  __int64 v18; // r8
  __int64 v19; // r9
  void *v20; // rsp
  __int64 v21; // rdx
  __int64 v22; // rcx
  __int64 v23; // r8
  __int64 v24; // r9
  void *v25; // rsp
  __int64 v26; // rdx
  __int64 v27; // rcx
  __int64 v28; // r8
  __int64 v29; // r9
  void *v30; // rsp
  unsigned __int64 *v31; // rbx
  __int64 v32; // rdx
  __int64 v33; // rcx
  __int64 v34; // r8
  __int64 v35; // r9
  void *v36; // rsp
  int *v37; // r12
  __int64 v38; // rdx
  __int64 v39; // rcx
  __int64 v40; // r8
  __int64 v41; // r9
  void *v42; // rsp
  __int64 v43; // rdx
  __int64 v44; // rcx
  __int64 v45; // r8
  __int64 v46; // r9
  void *v47; // rsp
  __int64 v48; // rdx
  __int64 v49; // rcx
  __int64 v50; // r8
  __int64 v51; // r9
  void *v52; // rsp
  __int64 v53; // rdx
  __int64 v54; // rcx
  __int64 v55; // r8
  __int64 v56; // r9
  void *v57; // rsp
  __int64 v58; // rax
  int v59; // ecx
  int v60; // edx
  _QWORD *v61; // r12
  _QWORD *i; // r15
  int v63; // eax
  bool v64; // zf
  int v65; // ecx
  bool v66; // dl
  bool v67; // r15
  __int64 v68; // rax
  int v69; // r14d
  __int64 v70; // rax
  __int64 *v71; // r10
  __int64 v72; // rbx
  __int64 v73; // rax
  __int64 v75; // [rsp+20h] [rbp-30h] BYREF
  int *v76; // [rsp+28h] [rbp-28h]
  unsigned __int64 *v77; // [rsp+30h] [rbp-20h]
  int v78; // [rsp+3Ch] [rbp-14h]
  __int64 *v79; // [rsp+40h] [rbp-10h]
  unsigned int k; // [rsp+48h] [rbp-8h]
  int v81; // [rsp+4Ch] [rbp-4h]
  unsigned int j; // [rsp+50h] [rbp+0h]
  int v83; // [rsp+54h] [rbp+4h]
  __int64 v84; // [rsp+68h] [rbp+18h] BYREF

  nullsub_1();
  v4 = alloca(sub_140001B30(v1, v0, v2, v3));
  v5 = &v75;
  v10 = alloca(sub_140001B30(v7, v6, v8, v9));
  v79 = &v75;
  v15 = alloca(sub_140001B30(v12, v11, v13, v14));
  v20 = alloca(sub_140001B30(v17, v16, v18, v19));
  v25 = alloca(sub_140001B30(v22, v21, v23, v24));
  v30 = alloca(sub_140001B30(v27, v26, v28, v29));
  v31 = (unsigned __int64 *)&v75;
  v36 = alloca(sub_140001B30(v33, v32, v34, v35));
  v37 = (int *)&v75;
  v42 = alloca(sub_140001B30(v39, v38, v40, v41));
  v47 = alloca(sub_140001B30(v44, v43, v45, v46));
  v52 = alloca(sub_140001B30(v49, v48, v50, v51));
  v57 = alloca(sub_140001B30(v54, v53, v55, v56));
  sub_140001C20((__int64)&v75);
  v58 = sub_14002F770();
  while ( v5 != &v84 )
  {
    v76 = v37;
    v60 = *(_DWORD *)v5;
    v61 = (_QWORD *)(v58 + 24);
    for ( i = *(_QWORD **)(*(_QWORD *)(v58 + 24) + 16LL); ; i = (_QWORD *)*i )
    {
      if ( i == (_QWORD *)(*v61 + 16LL) )
      {
        v59 = 4;
        goto LABEL_17;
      }
      v77 = v31;
      if ( i[12] == 0 )
        goto LABEL_13;
      v78 = v60;
      v75 = v58;
      sub_14002C330(v79);
      v83 = 0;
      while ( v83 == 0 )
      {
        v83 = 1;
        *(_DWORD *)v79 ^= 0x2720A390u;
      }
      v63 = sub_14002C260(i[12], *(unsigned int *)v79);
      v60 = v78;
      v64 = v63 != v78;
      v58 = v75;
      if ( v64 )
      {
LABEL_13:
        v65 = 0;
        v31 = v77;
      }
      else
      {
        v65 = 1;
        v31 = v77;
      }
      if ( v65 != 0 )
        break;
    }
    v59 = 1;
LABEL_17:
    v66 = v59 == 4;
    if ( v59 == 4 )
      v59 = 0;
    v37 = v76;
    if ( !v66 )
      goto LABEL_21;
    v5 = (__int64 *)((char *)v5 + 4);
  }
  v59 = 2;
LABEL_21:
  v67 = true;
  if ( v59 == 2 )
  {
    sub_14002C340(&v75);
    for ( j = 0; ; *((_WORD *)&v75 + v68) ^= -22541 * (_WORD)j )
    {
      nullsub_1();
      nullsub_1();
      if ( j >= 0x26 )
        break;
      v68 = (int)j++;
    }
    v69 = sub_140031280(0, (unsigned int)&v75, 37, 0, 0, (__int64)v31);
    sub_14002C380(v37);
    v81 = 0;
    while ( v81 == 0 )
    {
      v81 = 1;
      *v37 = (-2 - ((~*v37 | 0x638F96F2) + *v37)) & (*v37 | 0x638F96F2);
    }
    v67 = false;
    if ( v69 == *v37 )
    {
      v70 = sub_14002E070(saturated_mul(2u, *v31));
      v71 = (__int64 *)v31;
      v72 = v70;
      sub_140031280(0, (unsigned int)&v75, 37, v70, *v71, (__int64)v71);
      sub_14002C390(&v75);
      for ( k = 0; k < 6; *((_WORD *)&v75 + v73) ^= 5169 * (_WORD)k )
        v73 = (int)k++;
      v67 = sub_140016E30(v72, (__int64)&v75, (__int64 (__fastcall *)(_DWORD *, __int64))sub_14002DFD0, 0);
      sub_140001C10(v72);
    }
  }
  return v67;
}


// ---- sub_14002C260 @ 0x14002c260 ----
__int64 __fastcall sub_14002C260(unsigned __int16 *a1, unsigned int a2)
{
  __int64 result; // rax
  int v3; // edx
  unsigned __int16 v4; // r8
  unsigned int v5; // eax
  int i; // r8d
  int v7; // [rsp+0h] [rbp-4h]

  result = a2;
  v7 = 0;
  v3 = 1363045476;
  do
  {
    ++v7;
    v3 ^= (v7 & 0x437910BB) * (v7 & 0xBC86EF44 ^ 0xBC86EF44) + (v7 & 0xBC86EF44) * (v7 | 0x3C86EF44);
  }
  while ( v7 == 0 );
  v4 = *a1;
  if ( *a1 != 0 )
  {
    v5 = ~(_DWORD)result;
    do
    {
      v5 ^= v4;
      for ( i = 8; i != 0; --i )
        v5 = (v5 >> 1) ^ v3 & -((v5 ^ 0xFFFFFFFE) & (v5 | 1));
      v4 = a1[1];
      ++a1;
    }
    while ( v4 != 0 );
    return ~v5;
  }
  return result;
}


// ---- sub_14002C330 @ 0x14002c330 ----
void __fastcall sub_14002C330(_DWORD *a1)
{
  *a1 = -1029366026;
}


// ---- sub_14002C340 @ 0x14002c340 ----
void __fastcall sub_14002C340(_OWORD *a1)
{
  *(_OWORD *)((char *)a1 + 60) = *(__int128 *)((char *)&xmmword_140034CBE + 12);
  a1[3] = xmmword_140034CBE;
  a1[2] = xmmword_140034CAE;
  a1[1] = xmmword_140034C9E;
  *a1 = xmmword_140034C8E;
}


// ---- sub_14002C380 @ 0x14002c380 ----
void __fastcall sub_14002C380(_DWORD *a1)
{
  *a1 = -1550870831;
}


// ---- sub_14002C390 @ 0x14002c390 ----
__int64 __fastcall sub_14002C390(__int64 a1)
{
  *(_QWORD *)a1 = 0x50B73CE3284C141BLL;
  *(_DWORD *)(a1 + 8) = 2032559233;
  return 0x50B73CE3284C141BLL;
}


// ---- sub_14002C3B0 @ 0x14002c3b0 ----
bool sub_14002C3B0()
{
  __int64 v0; // rdx
  __int64 v1; // rcx
  __int64 v2; // r8
  __int64 v3; // r9
  void *v4; // rsp
  __int64 v5; // rdx
  __int64 v6; // r8
  __int64 v7; // r9
  void *v8; // rsp
  __int64 v9; // rcx
  __int64 v10; // r8
  __int64 v11; // r9
  void *v12; // rsp
  __int64 v13; // rdx
  __int64 v14; // rcx
  __int64 v15; // r8
  __int64 v16; // r9
  void *v17; // rsp
  __int64 v18; // rdx
  __int64 v19; // rcx
  __int64 v20; // r8
  __int64 v21; // r9
  void *v22; // rsp
  __int64 v23; // rdx
  __int64 v24; // rcx
  __int64 v25; // r8
  __int64 v26; // r9
  void *v27; // rsp
  __int64 v28; // rdx
  __int64 v29; // rcx
  __int64 v30; // r8
  __int64 v31; // r9
  void *v32; // rsp
  __int64 *v33; // r13
  __int64 v34; // rdx
  __int64 v35; // rcx
  __int64 v36; // r8
  __int64 v37; // r9
  void *v38; // rsp
  __int64 v39; // rdx
  __int64 v40; // rcx
  __int64 v41; // r8
  __int64 v42; // r9
  void *v43; // rsp
  __int64 v44; // rdx
  __int64 v45; // rcx
  __int64 v46; // r8
  __int64 v47; // r9
  void *v48; // rsp
  __int64 v49; // rdx
  __int64 v50; // rcx
  __int64 v51; // r8
  __int64 v52; // r9
  void *v53; // rsp
  __int64 v54; // rdx
  __int64 v55; // rcx
  __int64 v56; // r8
  __int64 v57; // r9
  void *v58; // rsp
  _QWORD *v59; // rcx
  __int64 *v60; // rdx
  int v61; // r9d
  int v62; // eax
  unsigned __int64 i; // rsi
  bool v64; // r12
  __int64 *v65; // rbx
  bool v66; // r13
  bool v67; // si
  int v68; // eax
  unsigned __int64 j; // rsi
  bool v70; // bl
  bool v71; // di
  unsigned __int64 k; // rdi
  bool v73; // bl
  bool v74; // r14
  __int64 v76; // [rsp+18h] [rbp-58h]
  __int64 v77; // [rsp+20h] [rbp-50h] BYREF
  __int64 *v78; // [rsp+28h] [rbp-48h]
  _QWORD *v79; // [rsp+30h] [rbp-40h]
  _QWORD *v80; // [rsp+38h] [rbp-38h]
  __int64 *v81; // [rsp+40h] [rbp-30h]
  __int64 *v82; // [rsp+48h] [rbp-28h]
  __int64 *v83; // [rsp+50h] [rbp-20h]
  char v84; // [rsp+59h] [rbp-17h] BYREF
  char v85; // [rsp+5Ah] [rbp-16h] BYREF
  char v86; // [rsp+5Bh] [rbp-15h] BYREF
  unsigned int v87; // [rsp+5Ch] [rbp-14h] BYREF
  unsigned int v88; // [rsp+60h] [rbp-10h] BYREF
  unsigned int v89; // [rsp+64h] [rbp-Ch] BYREF
  int v90; // [rsp+68h] [rbp-8h]
  int v91; // [rsp+6Ch] [rbp-4h]
  int v92; // [rsp+70h] [rbp+0h]
  int v93; // [rsp+74h] [rbp+4h]

  nullsub_1();
  v4 = alloca(sub_140001B30(v1, v0, v2, v3));
  v8 = alloca(sub_140001B30(&v77, v5, v6, v7));
  v12 = alloca(sub_140001B30(v9, &v77, v10, v11));
  v17 = alloca(sub_140001B30(v14, v13, v15, v16));
  v22 = alloca(sub_140001B30(v19, v18, v20, v21));
  v27 = alloca(sub_140001B30(v24, v23, v25, v26));
  v32 = alloca(sub_140001B30(v29, v28, v30, v31));
  v33 = &v77;
  v38 = alloca(sub_140001B30(v35, v34, v36, v37));
  v43 = alloca(sub_140001B30(v40, v39, v41, v42));
  v48 = alloca(sub_140001B30(v45, v44, v46, v47));
  v81 = &v77;
  v53 = alloca(sub_140001B30(v50, v49, v51, v52));
  v82 = &v77;
  v58 = alloca(sub_140001B30(v55, v54, v56, v57));
  v83 = &v77;
  v79 = v59;
  v78 = v60;
  *v60 = (__int64)v59;
  sub_14002C8B0(&v77);
  v90 = 0;
  while ( v90 == 0 )
  {
    v90 = 1;
    LODWORD(v77) = v77 ^ 0x3E360405;
  }
  v62 = -1;
  v77 = -1;
  for ( i = 0; ; ++i )
  {
    v64 = i < qword_14003BB50;
    if ( i >= qword_14003BB50 )
      break;
    v65 = v33;
    v66 = *(_DWORD *)(qword_14003BB58 + 8 * i) == -1198997924;
    if ( *(_DWORD *)(qword_14003BB58 + 8 * i) == -1198997924 )
      v62 = sub_14002F100(*(_DWORD *)(8 * i + qword_14003BB58 + 4), 3, v77, v77, *v78, v76);
    if ( v66 )
    {
      v33 = v65;
      break;
    }
    v33 = v65;
  }
  if ( !v64 )
  {
    sub_140016C90((__int64)&v85, &v88);
    v92 = 0;
    while ( v92 == 0 )
    {
      v92 = 1;
      v61 = ~v88;
      v88 = (-2 - ((~v88 | 0xF8F5E2A6) + v88)) & (v88 | 0xF8F5E2A6);
    }
    v62 = v88;
  }
  v67 = false;
  if ( v62 >= 0 )
  {
    *v80 = &v77;
    *v81 = 4;
    *v82 = (__int64)v33;
    v68 = (int)v83;
    *(_DWORD *)v83 = 20;
    for ( j = 0; ; ++j )
    {
      v70 = j < qword_14003BB50;
      if ( j >= qword_14003BB50 )
        break;
      v71 = *(_DWORD *)(qword_14003BB58 + 8 * j) == 513242398;
      if ( *(_DWORD *)(qword_14003BB58 + 8 * j) == 513242398 )
        v68 = sub_14002F100(*(_DWORD *)(8 * j + qword_14003BB58 + 4), 5, *v79, *(_DWORD *)v83, *v82, *v81);
      if ( v71 )
        break;
    }
    if ( !v70 )
    {
      sub_140016C90((__int64)&v84, &v87);
      v93 = 0;
      while ( v93 == 0 )
      {
        v93 = 1;
        v61 = ~v87;
        v87 = (-2 - ((~v87 | 0xF8F5E2A6) + v87)) & (v87 | 0xF8F5E2A6);
      }
      v68 = v87;
    }
    v67 = false;
    if ( v68 >= 0 )
      v67 = *(_DWORD *)v33 != 0;
    for ( k = 0; ; ++k )
    {
      v73 = k < qword_14003BB50;
      if ( k >= qword_14003BB50 )
        break;
      v74 = *(_DWORD *)(qword_14003BB58 + 8 * k) == -1825720177;
      if ( *(_DWORD *)(qword_14003BB58 + 8 * k) == -1825720177 )
        sub_14002F100(*(_DWORD *)(8 * k + qword_14003BB58 + 4), 1, *v79, v61, v77, (__int64)v78);
      if ( v74 )
        break;
    }
    if ( !v73 )
    {
      sub_140016C90((__int64)&v86, &v89);
      v91 = 0;
      while ( v91 == 0 )
      {
        v91 = 1;
        v89 = (-2 - ((~v89 | 0xF8F5E2A6) + v89)) & (v89 | 0xF8F5E2A6);
      }
    }
  }
  return v67;
}


// ---- sub_14002C8B0 @ 0x14002c8b0 ----
void __fastcall sub_14002C8B0(_DWORD *a1)
{
  *a1 = 1043727373;
}


// ---- sub_14002C8C0 @ 0x14002c8c0 ----
bool __fastcall sub_14002C8C0(int a1, unsigned int a2)
{
  int v4; // eax
  unsigned int v5; // r8d
  unsigned int v6; // edx
  int v7; // edi
  _DWORD *v8; // rbx
  unsigned __int64 v9; // rdx
  int v10; // eax
  int v11; // ecx
  int v12; // ebp
  int v13; // r9d
  __int64 v14; // rdx
  int v15; // r9d
  __int64 v16; // rdx
  bool result; // al
  __int64 v18; // [rsp+20h] [rbp-68h]
  __int64 v19; // [rsp+28h] [rbp-60h]
  __int64 v20; // [rsp+38h] [rbp-50h] BYREF
  int i; // [rsp+44h] [rbp-44h]
  int v22; // [rsp+48h] [rbp-40h] BYREF
  __int64 v23; // [rsp+58h] [rbp-30h] BYREF

  v22 = 0;
  v4 = 2057631503;
  do
  {
    ++v22;
    v4 = ((2057631591 * v22) | v4) & (-2 - (v4 + ((2057631591 * v22) | ~v4)));
  }
  while ( v22 == 0 );
  v22 = 0;
  v5 = 1551727928;
  do
  {
    ++v22;
    v6 = v5 & ((v22 & 0xA3928247) * (v22 & 0x5C6D7DB8 ^ 0x5C6D7DB8) + (v22 & 0x5C6D7DB8) * (v22 | 0x1C6D7DB8));
    v5 = (v5
        + (v5 ^ ((v22 & 0xA3928247) * (v22 & 0x5C6D7DB8 ^ 0x5C6D7DB8) + (v22 & 0x5C6D7DB8) * (v22 | 0x1C6D7DB8)))
        - (v5 & ~((v22 & 0xA3928247) * (v22 & 0x5C6D7DB8 ^ 0x5C6D7DB8) + (v22 & 0x5C6D7DB8) * (v22 | 0x1C6D7DB8))))
       & (v6 + ~(2 * v6));
  }
  while ( v22 == 0 );
  v7 = sub_140032010(a1, (unsigned int)&v23, v5, 7, v4);
  switch ( v7 >= 0 )
  {
    case false:
      return v7 >= 0;
    case true:
      v8 = (_DWORD *)sub_14002E070(1024);
      if ( qword_14003BB50 != 0 )
      {
        v9 = 0;
        while ( *(_DWORD *)(qword_14003BB58 + 8 * v9) != 674329531 )
        {
          v9 = (v9 ^ 1) + 2 * (v9 & 1);
          if ( v9 >= qword_14003BB50 )
            goto LABEL_10;
        }
        switch ( (int)sub_14002F100(
                        *(_DWORD *)(qword_14003BB58 + 8 * v9 + 4),
                        5,
                        v23,
                        (unsigned int)&v22,
                        (__int64)v8,
                        1024) >= 0 )
        {
          case false:
            break;
          case true:
LABEL_14:
            v12 = 0;
            switch ( *v8 != 0 )
            {
              case false:
                goto LABEL_25;
              case true:
LABEL_16:
                while ( 2 )
                {
                  switch ( (int)sub_140030330(&v20, *(_QWORD *)&v8[2 * v12 + 2], ((unsigned __int8)(a2 != 0) << 20) + 1) >= 0 )
                  {
                    case false:
                      __asm { jmp     qword ptr [r14+rax*8] }
                      return result;
                    case true:
                      v7 = sub_140030410(v20, 0, a2);
                      if ( qword_14003BB50 != 0 )
                      {
                        v14 = 0;
                        do
                        {
                          if ( *(_DWORD *)(qword_14003BB58 + 8 * v14) == -1825720177 )
                          {
                            sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v14 + 4), 1, v20, v13, v18, v19);
                            switch ( (unsigned int)++v12 < *v8 )
                            {
                              case false:
                                goto LABEL_25;
                              case true:
                                goto LABEL_16;
                            }
                          }
                          ++v14;
                        }
                        while ( qword_14003BB50 != v14 );
                      }
                      for ( i = 0; i == 0; ++i )
                        ;
                      switch ( (unsigned int)++v12 < *v8 )
                      {
                        case false:
                          goto LABEL_25;
                        case true:
                          continue;
                      }
                  }
                }
            }
        }
      }
      else
      {
LABEL_10:
        LODWORD(v20) = 0;
        v10 = 118103385;
        do
        {
          LODWORD(v20) = v20 + 1;
          v11 = (v20 & 0x70A1D59) * (v20 & 0xF8F5E2A6 ^ 0xF8F5E2A6) + (v20 & 0xF8F5E2A6) * (v20 | 0x78F5E2A6);
          v10 = (v10 | v11) & (-2 - (v10 + (v11 | ~v10)));
        }
        while ( (_DWORD)v20 == 0 );
        switch ( v10 >= 0 )
        {
          case false:
            break;
          case true:
            goto LABEL_14;
        }
      }
LABEL_25:
      sub_14002E0B0(v8);
      if ( qword_14003BB50 != 0 )
      {
        v16 = 0;
        while ( *(_DWORD *)(qword_14003BB58 + 8 * v16) != -1825720177 )
        {
          if ( qword_14003BB50 == ++v16 )
            goto LABEL_29;
        }
        sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v16 + 4), 1, v23, v15, v18, v19);
      }
      else
      {
LABEL_29:
        LODWORD(v20) = 0;
        do
          LODWORD(v20) = v20 + 1;
        while ( (_DWORD)v20 == 0 );
      }
      break;
  }
  return v7 >= 0;
}


// ---- sub_14002CC70 @ 0x14002cc70 ----
__int64 __fastcall sub_14002CC70(__int64 a1, __int64 a2)
{
  __int64 v4; // r14
  unsigned int *v5; // rsi
  __int64 v6; // rdx
  int v7; // eax
  unsigned int v8; // ecx
  int v9; // ecx
  int v10; // r9d
  unsigned int v11; // eax
  _DWORD *v12; // r13
  __int64 v13; // r14
  __int64 v14; // rbp
  __int64 v15; // rdx
  int v16; // eax
  unsigned int v17; // ecx
  __int64 v18; // r12
  unsigned int *v19; // rcx
  unsigned __int64 v20; // r9
  int v21; // eax
  unsigned int v22; // edx
  unsigned int *v23; // r12
  int v24; // edx
  unsigned __int64 v25; // rax
  __int64 v26; // r8
  bool v27; // zf
  __int64 v28; // r9
  __int64 v29; // rdx
  __int64 v30; // r8
  __int64 v31; // r9
  __int64 v32; // r10
  __int64 v33; // rdx
  __int64 v34; // rax
  __int64 v35; // rdx
  __int64 v37; // [rsp+20h] [rbp-A8h]
  __int64 v38; // [rsp+28h] [rbp-A0h]
  __int64 v39; // [rsp+28h] [rbp-A0h]
  int v40; // [rsp+4Ch] [rbp-7Ch]
  int v41; // [rsp+4Ch] [rbp-7Ch]
  int i; // [rsp+4Ch] [rbp-7Ch]
  _DWORD v43[4]; // [rsp+50h] [rbp-78h] BYREF
  __int64 v44; // [rsp+60h] [rbp-68h] BYREF
  __int64 v45; // [rsp+68h] [rbp-60h] BYREF

  v4 = 0x4000;
  v5 = nullptr;
  do
  {
    v4 *= 2;
    v5 = (unsigned int *)sub_14002E100(v5, v4);
    if ( qword_14003BB50 != 0 )
    {
      v6 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v6) != -594858244 )
      {
        if ( qword_14003BB50 == ++v6 )
          goto LABEL_6;
      }
      v7 = sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v6 + 4), 4, 16, (_DWORD)v5, v4, (__int64)v43);
    }
    else
    {
LABEL_6:
      v43[0] = 0;
      v7 = 118103385;
      do
      {
        ++v43[0];
        v8 = (v43[0] & 0x70A1D59) * (v43[0] & 0xF8F5E2A6 ^ 0xF8F5E2A6) + (v43[0] & 0xF8F5E2A6) * (v43[0] | 0x78F5E2A6);
        v7 = (v7 | v8) & (-2 - (v7 + (v8 | ~v7)));
      }
      while ( v43[0] == 0 );
    }
    v43[0] = 0;
    v9 = -656641764;
    do
    {
      ++v43[0];
      v9 ^= 417100056 * v43[0];
    }
    while ( v43[0] == 0 );
  }
  while ( v7 == v9 );
  if ( v7 < 0 || (int)sub_140030330(&v45, a1, 64) < 0 )
  {
    v13 = 0;
    goto LABEL_71;
  }
  v11 = *v5;
  if ( *v5 != 0 )
  {
    v12 = v5 + 2;
    v13 = 0;
    v14 = 0;
    while ( 1 )
    {
      if ( LOWORD(v12[6 * v14]) != a1 )
        goto LABEL_19;
      if ( qword_14003BB50 != 0 )
      {
        v10 = HIWORD(v12[6 * v14 + 1]);
        v15 = 0;
        while ( *(_DWORD *)(qword_14003BB58 + 8 * v15) != -1846491889 )
        {
          if ( qword_14003BB50 == ++v15 )
            goto LABEL_25;
        }
        if ( (int)sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v15 + 4), 7, v45, v10, -1, (__int64)&v44) >= 0 )
        {
LABEL_30:
          v18 = 524;
          v19 = nullptr;
          do
          {
            v19 = (unsigned int *)sub_14002E100(v19, v18);
            if ( qword_14003BB50 != 0 )
            {
              v20 = 0;
              while ( *(_DWORD *)(qword_14003BB58 + 8 * v20) != 674329531 )
              {
                v20 = (v20 ^ 1) + 2 * (v20 & 1);
                if ( v20 >= qword_14003BB50 )
                  goto LABEL_35;
              }
              v39 = v18;
              v23 = v19;
              v21 = sub_14002F100(
                      *(_DWORD *)(qword_14003BB58 + 8 * v20 + 4),
                      5,
                      v44,
                      (unsigned int)v43,
                      (__int64)v19,
                      v39);
              v19 = v23;
            }
            else
            {
LABEL_35:
              v40 = 0;
              v21 = 118103385;
              do
              {
                ++v40;
                v22 = (v40 & 0x70A1D59) * (v40 & 0xF8F5E2A6 ^ 0xF8F5E2A6) + (v40 & 0xF8F5E2A6) * (v40 | 0x78F5E2A6);
                v21 = (v21 | v22) & (-2 - (v21 + (v22 | ~v21)));
              }
              while ( v40 == 0 );
            }
            v41 = 0;
            v24 = -1223431474;
            do
            {
              ++v41;
              v24 ^= (v41 & 0xC8EC1534) * (v41 & 0x3713EACB ^ 0x3713EACB) + (v41 & 0x3713EACB) * (v41 | 0x3713EACB);
            }
            while ( v41 == 0 );
            v18 = *v19 + 4LL;
          }
          while ( v21 == v24 );
          if ( v21 >= 0 )
          {
            v25 = *v19;
            v26 = 0;
            do
            {
              v27 = *(_WORD *)(a2 + v26) == 0;
              v26 += 2;
            }
            while ( !v27 );
            if ( v26 - 2 >= v25 )
            {
              v28 = v26 + ~v25;
              if ( v28 != 0 )
              {
                v29 = v26 + (v28 == 0) + ~v25;
                v30 = a2;
                v31 = 0;
LABEL_48:
                v32 = 0;
                while ( v25 != v32 )
                {
                  v27 = *(_BYTE *)(v30 + v32) == *((_BYTE *)v19 + v32 + 4);
                  ++v32;
                  if ( !v27 )
                  {
                    ++v31;
                    ++v30;
                    if ( v31 != v29 )
                      goto LABEL_48;
                    goto LABEL_54;
                  }
                }
                if ( a2 == 0 )
                  goto LABEL_54;
                v13 = v44;
                sub_14002E0B0(v19);
                v34 = qword_14003BB50;
                if ( qword_14003BB50 == 0 )
                  goto LABEL_67;
LABEL_64:
                v35 = 0;
                while ( *(_DWORD *)(qword_14003BB58 + 8 * v35) != -1825720177 )
                {
                  if ( v34 == ++v35 )
                    goto LABEL_67;
                }
                sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v35 + 4), 1, v45, v10, v37, v38);
                goto LABEL_71;
              }
            }
          }
LABEL_54:
          sub_14002E0B0(v19);
          if ( qword_14003BB50 != 0 )
          {
            v33 = 0;
            while ( *(_DWORD *)(qword_14003BB58 + 8 * v33) != -1825720177 )
            {
              if ( qword_14003BB50 == ++v33 )
                goto LABEL_58;
            }
            sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v33 + 4), 1, v44, v10, v37, v38);
          }
          else
          {
LABEL_58:
            for ( i = 0; i == 0; ++i )
              ;
          }
        }
      }
      else
      {
LABEL_25:
        v43[0] = 0;
        v16 = 118103385;
        do
        {
          ++v43[0];
          v17 = (v43[0] & 0x70A1D59) * (v43[0] & 0xF8F5E2A6 ^ 0xF8F5E2A6)
              + (v43[0] & 0xF8F5E2A6) * (v43[0] | 0x78F5E2A6);
          v16 = (v16 | v17) & (-2 - (v16 + (v17 | ~v16)));
        }
        while ( v43[0] == 0 );
        if ( v16 >= 0 )
          goto LABEL_30;
      }
      v11 = *v5;
LABEL_19:
      if ( ++v14 >= (unsigned __int64)v11 )
        goto LABEL_63;
    }
  }
  v13 = 0;
LABEL_63:
  v34 = qword_14003BB50;
  if ( qword_14003BB50 != 0 )
    goto LABEL_64;
LABEL_67:
  v43[0] = 0;
  do
    ++v43[0];
  while ( v43[0] == 0 );
LABEL_71:
  sub_14002E0B0(v5);
  return v13;
}


// ---- sub_14002D260 @ 0x14002d260 ----
__int64 __fastcall sub_14002D260(int a1, int a2, _QWORD *a3, __int64 a4)
{
  int v8; // r8d
  __int64 v9; // rbx
  int v10; // r9d
  __int64 v11; // rax
  __int64 v12; // rdx
  int v13; // r8d
  int v14; // r9d
  __int64 v15; // rax
  __int64 v16; // rdx
  __int64 v18; // [rsp+20h] [rbp-78h]
  __int64 v19; // [rsp+20h] [rbp-78h]
  __int64 v20; // [rsp+28h] [rbp-70h]
  __int64 v21; // [rsp+28h] [rbp-70h]
  int v22; // [rsp+50h] [rbp-48h]
  int v23; // [rsp+50h] [rbp-48h]
  int i; // [rsp+50h] [rbp-48h]
  int j; // [rsp+50h] [rbp-48h]
  unsigned int v26; // [rsp+54h] [rbp-44h] BYREF
  __int64 v27; // [rsp+58h] [rbp-40h] BYREF
  _BYTE v28[52]; // [rsp+64h] [rbp-34h] BYREF

  v22 = 0;
  v8 = 1430873187;
  do
  {
    ++v22;
    v8 ^= 1431004282 * v22;
  }
  while ( v22 == 0 );
  if ( (int)sub_140031450(a1, (unsigned int)&v27, v8, 0, a4) < 0 )
    goto LABEL_15;
  v9 = 0;
  if ( (int)sub_140031820(v27, 0, 0, 0, 0, 0, 0, (__int64)v28, (__int64)&v26) < 0 )
  {
LABEL_8:
    v11 = qword_14003BB50;
    if ( qword_14003BB50 != 0 )
      goto LABEL_9;
LABEL_28:
    for ( i = 0; i == 0; ++i )
      ;
    goto LABEL_14;
  }
  v9 = sub_14002E070(v26 + 1);
  if ( (int)sub_140031B50(v27, a2, 0, v9, (__int64)&v26) >= 0 )
  {
    if ( a3 != nullptr )
      *a3 = v26;
    goto LABEL_8;
  }
  sub_140001C10(v9);
  v9 = 0;
  v11 = qword_14003BB50;
  if ( qword_14003BB50 == 0 )
    goto LABEL_28;
LABEL_9:
  v12 = 0;
  while ( *(_DWORD *)(qword_14003BB58 + 8 * v12) != -1825720177 )
  {
    if ( v11 == ++v12 )
      goto LABEL_28;
  }
  sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v12 + 4), 1, v27, v10, v18, v20);
LABEL_14:
  if ( v9 != 0 )
    return v9;
LABEL_15:
  v23 = 0;
  v13 = 1430873187;
  do
  {
    ++v23;
    v13 ^= 1431004282 * v23;
  }
  while ( v23 == 0 );
  if ( (int)sub_140031450(a1, (unsigned int)&v27, v13 | 0x200u, 0, a4) < 0 )
    return 0;
  v9 = 0;
  if ( (int)sub_140031820(v27, 0, 0, 0, 0, 0, 0, (__int64)v28, (__int64)&v26) < 0 )
  {
LABEL_22:
    v15 = qword_14003BB50;
    if ( qword_14003BB50 != 0 )
      goto LABEL_23;
LABEL_36:
    for ( j = 0; j == 0; ++j )
      ;
    goto LABEL_32;
  }
  v9 = sub_14002E070(v26 + 1);
  if ( (int)sub_140031B50(v27, a2, 0, v9, (__int64)&v26) >= 0 )
  {
    if ( a3 != nullptr )
      *a3 = v26;
    goto LABEL_22;
  }
  sub_140001C10(v9);
  v9 = 0;
  v15 = qword_14003BB50;
  if ( qword_14003BB50 == 0 )
    goto LABEL_36;
LABEL_23:
  v16 = 0;
  while ( *(_DWORD *)(qword_14003BB58 + 8 * v16) != -1825720177 )
  {
    if ( v15 == ++v16 )
      goto LABEL_36;
  }
  sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v16 + 4), 1, v27, v14, v19, v21);
LABEL_32:
  if ( v9 == 0 )
    return 0;
  return v9;
}


// ---- sub_14002D560 @ 0x14002d560 ----
unsigned __int64 __fastcall sub_14002D560(__int64 a1, __int64 a2, _DWORD *a3)
{
  unsigned __int64 result; // rax
  unsigned __int64 i; // rdx
  _DWORD v6[3]; // [rsp+2Ch] [rbp-Ch]

  result = sub_14000E4A0(a1, a2, (__int64)a3) - 4;
  v6[0] = *a3;
  for ( i = 0; i < result; ++i )
    *((_BYTE *)a3 + i) = ~((~*((_BYTE *)v6 + (i & 3)) | *((_BYTE *)a3 + i + 4))
                         & ~(~*((_BYTE *)v6 + (i & 3)) & *((_BYTE *)a3 + i + 4)));
  return result;
}


// ---- sub_14002D5E0 @ 0x14002d5e0 ----
void __fastcall sub_14002D5E0(_WORD *a1, _WORD *a2)
{
  switch ( a1 == nullptr || a2 == nullptr )
  {
    case false:
      *a2 = 0;
      switch ( *a1 != 0 )
      {
        case false:
          JUMPOUT(0x14002DE80LL);
        case true:
          JUMPOUT(0x14002D64FLL);
      }
    case true:
      JUMPOUT(0x14002DF86LL);
  }
}


// ---- sub_14002DFA0 @ 0x14002dfa0 ----
_WORD *__fastcall sub_14002DFA0(_WORD *a1, __int16 a2)
{
  _WORD *result; // rax
  __int16 v3; // cx

  result = a1;
  v3 = *a1;
  if ( v3 == 0 )
    return nullptr;
  while ( v3 != a2 )
  {
    v3 = result[1];
    ++result;
    if ( v3 == 0 )
      return nullptr;
  }
  return result;
}


// ---- sub_14002DFD0 @ 0x14002dfd0 ----
char __fastcall sub_14002DFD0(__int64 a1)
{
  __int64 v1; // rax
  __int64 v2; // rdx
  __int64 j; // rdx
  __int16 v4; // r8
  unsigned int i; // [rsp+Ch] [rbp-2Ch]
  _QWORD v7[4]; // [rsp+10h] [rbp-28h]
  int v8; // [rsp+30h] [rbp-8h]

  v1 = *(_DWORD *)(a1 + 60) >> 1;
  qmemcpy(v7, &ymmword_140034CDA, sizeof(v7));
  v8 = 969174790;
  for ( i = 0; i < 0x12; *((_WORD *)v7 + v2) ^= -13742 * (_WORD)i )
    v2 = (int)i++;
  for ( j = 0; ; ++j )
  {
    if ( v1 == j )
      return 1;
    v4 = *(_WORD *)(a1 + 2 * j + 64);
    if ( v4 != *((_WORD *)v7 + j) )
      break;
    if ( v4 == 0 )
      return 1;
  }
  return 0;
}


// ---- sub_14002E070 @ 0x14002e070 ----
__int64 __fastcall sub_14002E070(__int64 a1)
{
  __int64 v2; // rdi
  __int64 (__fastcall *v3)(__int64, _QWORD, __int64); // rax

  v2 = *(_QWORD *)(sub_14002F770() + 48);
  v3 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))sub_14002FDC0(qword_14003BA38, 2529313623LL);
  return v3(v2, 0, a1);
}


// ---- sub_14002E0B0 @ 0x14002e0b0 ----
__int64 __fastcall sub_14002E0B0(__int64 a1)
{
  __int64 result; // rax
  __int64 v3; // rdi
  __int64 (__fastcall *v4)(__int64, _QWORD, __int64); // rax

  result = a1 != 0;
  switch ( a1 != 0 )
  {
    case false:
      return result;
    case true:
      v3 = *(_QWORD *)(sub_14002F770() + 48);
      v4 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))sub_14002FDC0(qword_14003BA38, 1758750051);
      result = v4(v3, 0, a1);
      break;
  }
  return result;
}


// ---- sub_14002E100 @ 0x14002e100 ----
__int64 __fastcall sub_14002E100(__int64 a1, __int64 a2)
{
  __int64 result; // rax
  __int64 v4; // rdi
  __int64 (__fastcall *v5)(__int64, _QWORD, __int64); // rax

  switch ( a1 == 0 )
  {
    case false:
      result = off_14003AFA0();
      break;
    case true:
      v4 = *(_QWORD *)(sub_14002F770() + 48);
      v5 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))sub_14002FDC0(qword_14003BA38, 2529313623LL);
      result = v5(v4, 0, a2);
      break;
  }
  return result;
}


// ---- sub_14002E1B0 @ 0x14002e1b0 ----
unsigned __int64 __fastcall sub_14002E1B0(
        int a1,
        __int64 a2,
        unsigned __int64 a3,
        __int64 a4,
        unsigned __int64 a5,
        unsigned __int64 a6)
{
  unsigned int v10; // eax
  __int64 v11; // rdx
  int v12; // eax
  unsigned __int64 v13; // rbp
  unsigned __int64 v14; // r15
  __int64 v15; // rdx
  int v16; // eax
  unsigned __int64 result; // rax
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // r9d
  __int64 v22; // rdx
  __int64 v23; // rdx
  int v24; // eax
  int v25; // eax
  unsigned __int64 v26; // rdx
  unsigned __int64 v27; // rax
  unsigned __int64 v28; // r8
  __int64 v29; // r9
  __int64 v30; // r8
  __int64 v31; // rcx
  __int64 v32; // r8
  unsigned __int64 v33; // rsi
  unsigned __int64 v34; // [rsp+40h] [rbp-A8h] BYREF
  __int64 v35; // [rsp+48h] [rbp-A0h] BYREF
  unsigned __int64 v36; // [rsp+50h] [rbp-98h] BYREF
  unsigned __int64 v37; // [rsp+58h] [rbp-90h] BYREF
  __int128 v38; // [rsp+60h] [rbp-88h] BYREF
  __int128 v39; // [rsp+70h] [rbp-78h]
  __int128 v40; // [rsp+80h] [rbp-68h]

  LODWORD(v38) = 0;
  v10 = -740536391;
  do
  {
    LODWORD(v38) = v38 + 1;
    v10 ^= -744730695 * v38;
  }
  while ( (_DWORD)v38 == 0 );
  v37 = v10;
  v36 = 0;
  if ( qword_14003BB50 != 0 )
  {
    v11 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v11) != -1834021682 )
    {
      if ( qword_14003BB50 == ++v11 )
        goto LABEL_7;
    }
    if ( (int)sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v11 + 4), 6, -1, (unsigned int)&v36, 0, (__int64)&v37) < 0 )
      return 0;
  }
  else
  {
LABEL_7:
    LODWORD(v38) = 0;
    v12 = -895800841;
    do
    {
      LODWORD(v38) = v38 + 1;
      v12 ^= 895800840 * v38;
    }
    while ( (_DWORD)v38 == 0 );
    if ( v12 < 0 )
      return 0;
  }
  v13 = a6;
  v14 = a5;
  if ( a6 == 0 || a5 == 0 )
  {
    if ( qword_14003BB50 != 0 )
    {
      v15 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v15) != -594858244 )
      {
        if ( qword_14003BB50 == ++v15 )
          goto LABEL_15;
      }
      if ( (int)sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v15 + 4), 4, 0, (unsigned int)&v38, 64, 0) < 0 )
        goto LABEL_25;
    }
    else
    {
LABEL_15:
      LODWORD(v38) = 0;
      v16 = -895800841;
      do
      {
        LODWORD(v38) = v38 + 1;
        v16 ^= 895800840 * v38;
      }
      while ( (_DWORD)v38 == 0 );
      if ( v16 < 0 )
      {
LABEL_25:
        if ( a5 == 0 )
        {
          LODWORD(v35) = 0;
          v18 = 1909639530;
          do
          {
            LODWORD(v35) = v35 + 1;
            v19 = (v35 & 0x71D3C96A ^ 0x71D3C96A) * (v35 & 0x8E2C3695) + (v35 & 0x71D3C96A) * (v35 | 0x71D3C96A);
            v18 = (v18 | v19) & (-2 - (v18 + (v19 | ~v18)));
          }
          while ( (_DWORD)v35 == 0 );
          v14 = v18;
        }
        if ( a6 == 0 )
        {
          v13 = 0x7FFFEFF4BCE4LL;
          LODWORD(v35) = 0;
          do
          {
            LODWORD(v35) = v35 + 1;
            v13 ^= 269173531LL * (int)v35;
          }
          while ( (_DWORD)v35 == 0 );
        }
        goto LABEL_30;
      }
    }
    if ( a5 == 0 )
      v14 = v40;
    if ( a6 == 0 )
      v13 = *((_QWORD *)&v40 + 1);
  }
LABEL_30:
  v35 = 0;
  v40 = 0;
  v39 = 0;
  v38 = 0;
  if ( v14 < v13 )
  {
    do
    {
      v20 = sub_140030560(a1, v14, 0, (unsigned int)&v38, 48, 0);
      if ( (unsigned int)v20 > 0xBFFFFFFF )
        break;
      if ( v20 >= 0 && (_DWORD)v40 == 4096 && (BYTE4(v40) & 0xFE) != 0 )
      {
        v21 = DWORD2(v39);
        if ( *((_QWORD *)&v39 + 1) > v37 )
        {
          if ( qword_14003BB50 != 0 )
          {
            v22 = 0;
            while ( *(_DWORD *)(qword_14003BB58 + 8 * v22) != -289015568 )
            {
              if ( qword_14003BB50 == ++v22 )
                goto LABEL_43;
            }
            sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v22 + 4), 4, -1, (unsigned int)&v36, (__int64)&v35, 0x8000);
          }
          else
          {
LABEL_43:
            LODWORD(v34) = 0;
            do
              LODWORD(v34) = v34 + 1;
            while ( (_DWORD)v34 == 0 );
          }
          v36 = 0;
          v37 = *((_QWORD *)&v39 + 1);
          if ( qword_14003BB50 != 0 )
          {
            v23 = 0;
            while ( *(_DWORD *)(qword_14003BB58 + 8 * v23) != -1834021682 )
            {
              if ( qword_14003BB50 == ++v23 )
                goto LABEL_51;
            }
            if ( (int)sub_14002F100(
                        *(_DWORD *)(qword_14003BB58 + 8 * v23 + 4),
                        6,
                        -1,
                        (unsigned int)&v36,
                        0,
                        (__int64)&v37) < 0 )
              break;
          }
          else
          {
LABEL_51:
            LODWORD(v34) = 0;
            v24 = -895800841;
            do
            {
              LODWORD(v34) = v34 + 1;
              v24 ^= 895800840 * v34;
            }
            while ( (_DWORD)v34 == 0 );
            if ( v24 < 0 )
              break;
          }
          v21 = DWORD2(v39);
        }
        v34 = 0;
        v25 = sub_140030630(a1, v14, v36, v21, (__int64)&v34);
        if ( (v25 == -2147483635 || v25 >= 0) && v34 <= *((_QWORD *)&v39 + 1) && v34 >= a3 )
        {
          v26 = v36 + v34 - a3;
          if ( v26 >= v36 )
          {
            v27 = v36;
            if ( a3 != 0 )
            {
              v27 = v36;
              if ( a4 != 0 )
              {
                do
                {
                  v28 = 0;
                  while ( 1 )
                  {
                    v29 = *(_QWORD *)(a4 + 8 * (v28 >> 6));
                    if ( _bittest64(&v29, v28) )
                    {
                      if ( *(_BYTE *)(v27 + v28) != *(_BYTE *)(a2 + v28) )
                        break;
                    }
                    if ( a3 == ++v28 )
                      goto LABEL_32;
                  }
                  ++v27;
                }
                while ( v27 <= v26 );
              }
              else
              {
                v27 = v36;
                do
                {
                  v30 = 0;
                  while ( *(_BYTE *)(v27 + v30) == *(_BYTE *)(a2 + v30) )
                  {
                    if ( a3 == ++v30 )
                      goto LABEL_87;
                  }
                  ++v27;
                }
                while ( v27 <= v26 );
              }
            }
            else
            {
LABEL_32:
              if ( v27 != 0 )
              {
LABEL_87:
                result = v14 + v27 - v36;
                v31 = qword_14003BB50;
                if ( qword_14003BB50 != 0 )
                  goto LABEL_77;
                goto LABEL_80;
              }
            }
          }
        }
      }
      v14 = v38 + *((_QWORD *)&v39 + 1);
    }
    while ( (_QWORD)v38 + *((_QWORD *)&v39 + 1) < v13 );
  }
  result = 0;
  v31 = qword_14003BB50;
  if ( qword_14003BB50 != 0 )
  {
LABEL_77:
    v32 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v32) != -289015568 )
    {
      if ( v31 == ++v32 )
        goto LABEL_80;
    }
    v33 = result;
    sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v32 + 4), 4, -1, (unsigned int)&v36, (__int64)&v35, 0x8000);
    return v33;
  }
  else
  {
LABEL_80:
    LODWORD(v34) = 0;
    do
      LODWORD(v34) = v34 + 1;
    while ( (_DWORD)v34 == 0 );
  }
  return result;
}


// ---- sub_14002E850 @ 0x14002e850 ----
unsigned __int64 *__fastcall sub_14002E850(
        unsigned __int64 *a1,
        __int64 a2,
        __int64 a3,
        unsigned __int64 a4,
        __int64 a5)
{
  unsigned __int64 *v7; // rbx
  int v8; // ecx
  unsigned int v9; // eax
  int v10; // eax
  __int64 v11; // r8
  int v12; // eax
  int v13; // esi
  unsigned __int64 v14; // r12
  __int64 v15; // rdx
  int v16; // eax
  unsigned __int64 v17; // r15
  __int64 v18; // r13
  int v19; // eax
  int v20; // r9d
  int v21; // eax
  __int64 v22; // r8
  __int64 v23; // rdx
  int v24; // eax
  int v25; // eax
  __int64 v26; // r8
  int v27; // ecx
  unsigned __int64 v28; // rsi
  unsigned __int64 v29; // r9
  unsigned __int64 v30; // r14
  unsigned __int64 v31; // rbp
  unsigned __int64 v32; // rsi
  unsigned __int64 v33; // rax
  unsigned __int64 v34; // rcx
  __int64 v35; // rdx
  __int64 v36; // rcx
  unsigned __int64 v37; // r12
  signed __int64 v38; // r13
  unsigned __int64 v39; // rbx
  unsigned __int64 v40; // rbp
  unsigned __int64 v41; // rax
  unsigned __int64 v42; // rdx
  unsigned __int64 *v43; // rcx
  unsigned __int64 v44; // rax
  int v45; // eax
  __int64 v46; // r8
  unsigned __int64 v48; // [rsp+40h] [rbp-D8h] BYREF
  int v49; // [rsp+4Ch] [rbp-CCh]
  unsigned __int64 v50; // [rsp+50h] [rbp-C8h] BYREF
  int v51[6]; // [rsp+58h] [rbp-C0h] BYREF
  unsigned __int64 v52; // [rsp+70h] [rbp-A8h]
  unsigned __int64 v53; // [rsp+78h] [rbp-A0h]
  unsigned __int64 v54; // [rsp+80h] [rbp-98h]
  unsigned __int64 v55; // [rsp+98h] [rbp-80h] BYREF
  __int64 v56; // [rsp+A0h] [rbp-78h]
  __int64 v57; // [rsp+A8h] [rbp-70h] BYREF
  __int64 v58; // [rsp+B0h] [rbp-68h]
  unsigned __int64 *v59; // [rsp+B8h] [rbp-60h]
  unsigned __int64 v60; // [rsp+C0h] [rbp-58h]
  unsigned __int64 v61; // [rsp+C8h] [rbp-50h]
  __int64 v62; // [rsp+D0h] [rbp-48h]

  v7 = a1;
  *(_OWORD *)a1 = 0;
  a1[2] = 0;
  v57 = 0;
  v51[0] = 0;
  v8 = -1375552308;
  v9 = -1375552308;
  do
  {
    ++v51[0];
    v9 = ~((-1371358004 * v51[0]) & v8 | ((v8 & ~(-1371358004 * v51[0])) + ~(v8 + ((-1371358004 * v51[0]) ^ v9))));
    v8 = v9;
  }
  while ( v51[0] == 0 );
  v55 = v9;
  v50 = 0;
  v51[0] = 0;
  v10 = 1283065469;
  do
  {
    ++v51[0];
    v10 ^= (v51[0] & 0x4C7A367D ^ 0x4C7A367D) * (v51[0] & 0xB385C982) + (v51[0] & 0x4C7A367D) * (v51[0] | 0x4C7A367D);
  }
  while ( v51[0] == 0 );
  v56 = a3;
  if ( qword_14003BB50 == 0 )
  {
LABEL_9:
    v51[0] = 0;
    v12 = -895800841;
    do
    {
      ++v51[0];
      v12 ^= 895800840 * v51[0];
    }
    while ( v51[0] == 0 );
    if ( v12 < 0 )
      return v7;
LABEL_14:
    v51[0] = 0;
    v13 = 1789964336;
    do
    {
      ++v51[0];
      v13 ^= (v51[0] & 0x954E4FCF) * (v51[0] & 0x6AB1B030 ^ 0x6AB1B030) + (v51[0] & 0x6AB1B030) * (v51[0] | 0xAB1B030);
    }
    while ( v51[0] == 0 );
    v14 = 0x7FFF7716D620LL;
    v51[0] = 0;
    do
    {
      ++v51[0];
      v14 ^= (v51[0] & 0x88E929DF ^ 0x88E929DFLL) * (v51[0] & 0xFFFFFFFF7716D620uLL)
           + (v51[0] & 0x88E929DF) * (v51[0] | 0x88E929DFLL);
    }
    while ( v51[0] == 0 );
    if ( qword_14003BB50 != 0 )
    {
      v15 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v15) != -594858244 )
      {
        if ( qword_14003BB50 == ++v15 )
          goto LABEL_22;
      }
      if ( (int)sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v15 + 4), 4, 0, (unsigned int)v51, 64, 0) < 0 )
      {
LABEL_28:
        v17 = v13;
        if ( v13 < v14 )
        {
LABEL_29:
          v18 = a5;
          v62 = -(__int64)a4;
          v59 = v7;
          v58 = a2;
          v61 = v14;
          do
          {
            v19 = sub_140030560(a2, v17, 0, (unsigned int)v51, 48, 0);
            if ( (unsigned int)v19 > 0xBFFFFFFF )
              break;
            if ( v19 >= 0 && (_DWORD)v53 == 4096 && (v53 & 0x6600000000LL) != 0 )
            {
              v20 = v52;
              if ( v52 > v55 )
              {
                LODWORD(v48) = 0;
                v21 = 656417680;
                do
                {
                  LODWORD(v48) = v48 + 1;
                  v21 ^= 656450448 * v48;
                }
                while ( (_DWORD)v48 == 0 );
                if ( qword_14003BB50 != 0 )
                {
                  v22 = 0;
                  while ( *(_DWORD *)(qword_14003BB58 + 8 * v22) != -289015568 )
                  {
                    if ( qword_14003BB50 == ++v22 )
                      goto LABEL_43;
                  }
                  sub_14002F100(
                    *(_DWORD *)(qword_14003BB58 + 8 * v22 + 4),
                    4,
                    -1,
                    (unsigned int)&v50,
                    (__int64)&v57,
                    v21);
                }
                else
                {
LABEL_43:
                  LODWORD(v48) = 0;
                  do
                    LODWORD(v48) = v48 + 1;
                  while ( (_DWORD)v48 == 0 );
                }
                v50 = 0;
                v55 = v52;
                if ( qword_14003BB50 != 0 )
                {
                  v23 = 0;
                  while ( *(_DWORD *)(qword_14003BB58 + 8 * v23) != -1834021682 )
                  {
                    if ( qword_14003BB50 == ++v23 )
                      goto LABEL_51;
                  }
                  if ( (int)sub_14002F100(
                              *(_DWORD *)(qword_14003BB58 + 8 * v23 + 4),
                              6,
                              -1,
                              (unsigned int)&v50,
                              0,
                              (__int64)&v55) < 0 )
                    break;
                }
                else
                {
LABEL_51:
                  LODWORD(v48) = 0;
                  v24 = -895800841;
                  do
                  {
                    LODWORD(v48) = v48 + 1;
                    v24 ^= 895800840 * v48;
                  }
                  while ( (_DWORD)v48 == 0 );
                  if ( v24 < 0 )
                    break;
                }
                v20 = v52;
              }
              v25 = sub_140030630(a2, v17, v50, v20, (__int64)&v48);
              v26 = v56;
              if ( v25 >= 0 )
                goto LABEL_99;
              v49 = 0;
              v27 = -984081074;
              do
              {
                ++v49;
                v27 ^= 1163402563 * v49;
              }
              while ( v49 == 0 );
              if ( v25 == v27 )
              {
LABEL_99:
                v28 = v48;
                if ( v48 <= v52 && v48 >= a4 )
                {
                  v29 = *v7;
                  v30 = v50;
                  do
                  {
                    v32 = v30 + v28;
                    v33 = v32 + v62;
                    if ( v32 + v62 < v30 )
                      break;
                    if ( a4 != 0 )
                    {
                      if ( v18 != 0 )
                      {
                        do
                        {
                          v34 = 0;
                          while ( 1 )
                          {
                            v35 = *(_QWORD *)(v18 + 8 * (v34 >> 6));
                            if ( _bittest64(&v35, v34) )
                            {
                              if ( *(_BYTE *)(v30 + v34) != *(_BYTE *)(v26 + v34) )
                                break;
                            }
                            if ( a4 == ++v34 )
                              goto LABEL_74;
                          }
                          ++v30;
                        }
                        while ( v30 <= v33 );
                      }
                      else
                      {
                        do
                        {
                          v36 = 0;
                          while ( *(_BYTE *)(v30 + v36) == *(_BYTE *)(v26 + v36) )
                          {
                            if ( a4 == ++v36 )
                              goto LABEL_80;
                          }
                          ++v30;
                        }
                        while ( v30 <= v33 );
                      }
                      break;
                    }
LABEL_74:
                    if ( v30 == 0 )
                      break;
LABEL_80:
                    v37 = v17 + v30 - v50;
                    v38 = v7[1] - v29;
                    if ( v7[1] == v7[2] )
                    {
                      v39 = (v38 >> 3) + ((unsigned __int64)(v38 >> 3) >> 1);
                      if ( v39 <= (v38 >> 3) + 1 )
                        v39 = (v38 >> 3) + 1;
                      v40 = v29;
                      v41 = sub_140001B80(8 * v39);
                      v42 = v40;
                      v31 = v41;
                      if ( v42 != 0 )
                      {
                        v60 = v42;
                        sub_140001D60(v41, v42, v38);
                        sub_140001C10(v60);
                      }
                      v43 = v59;
                      *v59 = v31;
                      v43[1] = v38 + v31;
                      v44 = v31 + 8 * v39;
                      v7 = v43;
                      v43[2] = v44;
                      v29 = v31;
                      v26 = v56;
                    }
                    else
                    {
                      v31 = v29;
                    }
                    *(_QWORD *)(v31 + v38) = v37;
                    v7[1] += 8LL;
                    v30 += a4;
                    v28 = v32 - v30;
                    v14 = v61;
                    v18 = a5;
                  }
                  while ( v28 >= a4 );
                }
              }
              LODWORD(a2) = v58;
            }
            v17 = *(_QWORD *)v51 + v52;
          }
          while ( *(_QWORD *)v51 + v52 < v14 );
        }
LABEL_86:
        LODWORD(v48) = 0;
        v45 = 1670321906;
        do
        {
          LODWORD(v48) = v48 + 1;
          v45 ^= (v48 & 0x9C70690D) * (v48 & 0x638F96F2 ^ 0x638F96F2) + (v48 & 0x638F96F2) * (v48 | 0x638F96F2);
        }
        while ( (_DWORD)v48 == 0 );
        if ( qword_14003BB50 != 0 )
        {
          v46 = 0;
          while ( *(_DWORD *)(qword_14003BB58 + 8 * v46) != -289015568 )
          {
            if ( qword_14003BB50 == ++v46 )
              goto LABEL_92;
          }
          sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v46 + 4), 4, -1, (unsigned int)&v50, (__int64)&v57, v45);
        }
        else
        {
LABEL_92:
          LODWORD(v48) = 0;
          do
            LODWORD(v48) = v48 + 1;
          while ( (_DWORD)v48 == 0 );
        }
        return v7;
      }
    }
    else
    {
LABEL_22:
      v51[0] = 0;
      v16 = -895800841;
      do
      {
        ++v51[0];
        v16 ^= 895800840 * v51[0];
      }
      while ( v51[0] == 0 );
      if ( v16 < 0 )
        goto LABEL_28;
    }
    v17 = v53;
    v14 = v54;
    if ( v53 < v54 )
      goto LABEL_29;
    goto LABEL_86;
  }
  v11 = 0;
  while ( *(_DWORD *)(qword_14003BB58 + 8 * v11) != -1834021682 )
  {
    if ( qword_14003BB50 == ++v11 )
      goto LABEL_9;
  }
  if ( (int)sub_14002F100(*(_DWORD *)(qword_14003BB58 + 8 * v11 + 4), 6, -1, (unsigned int)&v50, 0, (__int64)&v55) >= 0 )
    goto LABEL_14;
  return v7;
}


// ---- sub_14002F100 @ 0x14002f100 ----
__int64 sub_14002F100(__int64 a1, __int64 a2, _DWORD a3, _DWORD a4, __int64 a5, __int64 a6, ...)
{
  __int64 result; // rax
  va_list va; // [rsp+48h] [rbp+38h] BYREF

  va_start(va, a6);
  result = a1;
  if ( a2 > 4 )
    qmemcpy(&a5, va, 8 * (a2 - 4));
  __asm { syscall; Low latency system call }
  return result;
}


// ---- sub_14002F140 @ 0x14002f140 ----
__int64 sub_14002F140()
{
  return off_14003B1D0();
}


// ---- sub_14002F230 @ 0x14002f230 ----
char __fastcall sub_14002F230(unsigned __int16 *a1)
{
  int v1; // eax
  int v2; // ecx
  char result; // al
  int v4; // [rsp+34h] [rbp-44h]

  v1 = *a1;
  v4 = 0;
  v2 = 1642125438;
  do
  {
    ++v4;
    v2 ^= 1642103347 * v4;
  }
  while ( v4 == 0 );
  switch ( v2 != v1 )
  {
    case false:
      result = off_14003B238();
      break;
    case true:
      result = 0;
      break;
  }
  return result;
}


// ---- sub_14002F770 @ 0x14002f770 ----
unsigned __int64 sub_14002F770()
{
  unsigned int v0; // eax
  int v2; // [rsp+0h] [rbp-4h]

  v2 = 0;
  v0 = 1402752987;
  do
  {
    ++v2;
    v0 ^= 1402752955 * v2;
  }
  while ( v2 == 0 );
  return __readgsqword(v0);
}


// ---- sub_14002F7D0 @ 0x14002f7d0 ----
void __fastcall sub_14002F7D0(int a1)
{
  unsigned int v1; // eax
  unsigned __int64 v2; // rdx
  int v3; // [rsp+0h] [rbp-30h]

  v3 = 0;
  v1 = 1402752987;
  do
  {
    ++v3;
    v1 ^= 1402752955 * v3;
  }
  while ( v3 == 0 );
  v2 = __readgsqword(v1);
  switch ( a1 == 0 )
  {
    case false:
      switch ( *(_QWORD *)(*(_QWORD *)(v2 + 24) + 16LL) != *(_QWORD *)(v2 + 24) + 16LL )
      {
        case false:
          __asm { jmp     rcx; jumptable 000000014002F4A8 cases 6,22 }
          return;
        case true:
          JUMPOUT(0x14002F894LL);
      }
    case true:
      JUMPOUT(0x14002F9D3LL);
  }
}


// ---- sub_14002FCD0 @ 0x14002fcd0 ----
void __fastcall sub_14002FCD0(__int64 a1)
{
  unsigned int v1; // eax
  unsigned __int64 v2; // rax
  int v3; // [rsp+0h] [rbp-Ch]

  v3 = 0;
  v1 = 1402752987;
  do
  {
    ++v3;
    v1 ^= 1402752955 * v3;
  }
  while ( v3 == 0 );
  v2 = __readgsqword(v1);
  switch ( a1 == 0 )
  {
    case false:
      switch ( *(_QWORD *)(*(_QWORD *)(v2 + 24) + 16LL) != *(_QWORD *)(v2 + 24) + 16LL )
      {
        case false:
          JUMPOUT(0x14002FD50LL);
        case true:
          JUMPOUT(0x14002FD7CLL);
      }
    case true:
      JUMPOUT(0x14002FDA3LL);
  }
}


// ---- sub_14002FDC0 @ 0x14002fdc0 ----
__int64 __fastcall sub_14002FDC0(unsigned __int16 *a1)
{
  void *v1; // rdi
  int v2; // r8d
  __int64 result; // rax
  __int64 v4; // r8
  int v5; // r9d
  int v6; // [rsp-18h] [rbp-60h]
  int v7; // [rsp+4h] [rbp-44h]

  v7 = 0;
  v2 = 776136323;
  do
  {
    ++v7;
    v2 ^= 776125646 * v7;
  }
  while ( v7 == 0 );
  result = 0;
  switch ( v2 != *a1 )
  {
    case false:
      v4 = *((int *)a1 + 15);
      v6 = 0;
      v5 = 1283093293;
      do
      {
        ++v6;
        v5 ^= 1283077757 * v6;
      }
      while ( v6 == 0 );
      result = 0;
      switch ( *(_DWORD *)((char *)a1 + v4) != v5 )
      {
        case false:
          result = 0;
          switch ( *(_DWORD *)((char *)a1 + v4 + 140) == 0 || *(_DWORD *)((char *)a1 + v4 + 136) == 0 )
          {
            case false:
              v1 = off_14003B978;
              goto LABEL_9;
            case true:
              return result;
            case 2:
            case 3:
            case 4:
LABEL_9:
              __asm { jmp     rdi; jumptable 000000014002F4A8 case 78 }
              return result;
          }
        case true:
          return result;
      }
    case true:
      return result;
  }
}


// ---- sub_140030060 @ 0x140030060 ----
__int64 __fastcall sub_140030060(unsigned __int8 (__fastcall *a1)(_DWORD *, __int64), __int64 a2)
{
  unsigned __int64 v4; // rdx
  int v5; // ebp
  int v6; // eax
  __int64 v7; // rbx
  __int64 v8; // rdx
  int v9; // r15d
  _DWORD *v10; // r14
  int v12; // [rsp+30h] [rbp-38h]
  int v13; // [rsp+30h] [rbp-38h]
  int v14; // [rsp+30h] [rbp-38h]
  int v15; // [rsp+30h] [rbp-38h]
  _DWORD v16[13]; // [rsp+34h] [rbp-34h] BYREF

  v16[0] = 0;
  if ( qword_14003BB50 != 0 )
  {
    v4 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v4) != -594858244 )
    {
      v4 = (v4 ^ 1) + 2 * (v4 & 1);
      if ( v4 >= qword_14003BB50 )
        goto LABEL_5;
    }
    v5 = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v4 + 4), 4, 5, 0, 0, (__int64)v16);
  }
  else
  {
LABEL_5:
    v12 = 0;
    v5 = -895800841;
    do
    {
      ++v12;
      v5 ^= 895800840 * v12;
    }
    while ( v12 == 0 );
  }
  v13 = 0;
  v6 = -417291372;
  do
  {
    ++v13;
    v6 ^= 656450448 * v13;
  }
  while ( v13 == 0 );
  if ( v5 == v6 )
  {
    v16[0] += 0x10000;
    v7 = sub_14002E070(v16[0]);
    if ( qword_14003BB50 != 0 )
    {
      v8 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v8) != -594858244 )
      {
        if ( qword_14003BB50 == ++v8 )
          goto LABEL_16;
      }
      v5 = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v8 + 4), 4, 5, v7, v16[0], 0);
      if ( v5 < 0 )
        goto LABEL_29;
    }
    else
    {
LABEL_16:
      v14 = 0;
      v5 = -895800841;
      do
      {
        ++v14;
        v5 ^= 895800840 * v14;
      }
      while ( v14 == 0 );
      if ( v5 < 0 )
      {
LABEL_29:
        sub_14002E0B0(v7);
        return (unsigned int)v5;
      }
    }
    v15 = 0;
    v9 = -2057822362;
    do
    {
      ++v15;
      v9 ^= 1163402563 * v15;
    }
    while ( v15 == 0 );
    v5 = 0;
    if ( a1((_DWORD *)v7, a2) == 0 )
    {
      v10 = (_DWORD *)v7;
      while ( *v10 != 0 )
      {
        v10 = (_DWORD *)((char *)v10 + (unsigned int)*v10);
        if ( a1(v10, a2) != 0 )
          goto LABEL_29;
      }
      v5 = v9;
    }
    goto LABEL_29;
  }
  return (unsigned int)v5;
}


// ---- sub_140030290 @ 0x140030290 ----
bool __fastcall sub_140030290(__int64 a1, __int64 a2)
{
  _QWORD v3[2]; // [rsp+28h] [rbp-10h] BYREF

  v3[0] = a1;
  v3[1] = a2;
  return (int)sub_140030060((unsigned __int8 (__fastcall *)(_DWORD *, __int64))sub_140032900, (__int64)v3) >= 0;
}


// ---- sub_1400302C0 @ 0x1400302c0 ----
__int64 sub_1400302C0()
{
  return 2;
}


// ---- sub_1400302D0 @ 0x1400302d0 ----
__int64 __fastcall sub_1400302D0(__int64 a1)
{
  __int64 (__fastcall *v2)(__int64, _DWORD *); // rax
  int v3; // eax
  _DWORD v5[3]; // [rsp+2Ch] [rbp-Ch] BYREF

  v2 = (__int64 (__fastcall *)(__int64, _DWORD *))sub_14002FDC0((unsigned __int16 *)qword_14003BA40);
  if ( v2 == nullptr )
    return 1;
  v5[0] = 0;
  v3 = v2(a1, v5);
  return (v3 != 0 && v5[0] != 0) | 2u;
}


// ---- sub_140030330 @ 0x140030330 ----
__int64 __fastcall sub_140030330(int a1, __int64 a2, int a3)
{
  __int64 v3; // r10
  __int64 result; // rax
  int v5; // [rsp+34h] [rbp-44h]
  _QWORD v6[2]; // [rsp+38h] [rbp-40h] BYREF
  int v7; // [rsp+48h] [rbp-30h] BYREF
  __int128 v8; // [rsp+50h] [rbp-28h]
  int v9; // [rsp+60h] [rbp-18h]
  __int128 v10; // [rsp+68h] [rbp-10h]

  v7 = 48;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v6[0] = a2;
  v6[1] = 0;
  if ( qword_14003BB50 != 0 )
  {
    v3 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v3) != -1681590846 )
    {
      if ( qword_14003BB50 == ++v3 )
        goto LABEL_5;
    }
    return sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v3 + 4), 4, a1, a3, (__int64)&v7, (__int64)v6);
  }
  else
  {
LABEL_5:
    v5 = 0;
    LODWORD(result) = -895800841;
    do
    {
      ++v5;
      result = (895800840 * v5) ^ (unsigned int)result;
    }
    while ( v5 == 0 );
  }
  return result;
}


// ---- sub_140030410 @ 0x140030410 ----
__int64 __fastcall sub_140030410(int a1, int a2, unsigned int a3)
{
  __int64 v4; // r10
  __int64 result; // rax
  unsigned int v6; // edi
  __int64 v7; // rcx
  bool v8; // zf
  __int64 *v9; // r8
  __int64 v10; // [rsp+20h] [rbp-28h]
  __int64 v11; // [rsp+28h] [rbp-20h]
  int v12; // [rsp+2Ch] [rbp-1Ch]
  __int64 v13; // [rsp+30h] [rbp-18h] BYREF

  if ( qword_14003BB50 == 0 )
  {
LABEL_5:
    LODWORD(v13) = 0;
    LODWORD(result) = -895800841;
    do
    {
      LODWORD(v13) = v13 + 1;
      result = (895800840 * (_DWORD)v13) ^ (unsigned int)result;
    }
    while ( (_DWORD)v13 == 0 );
    if ( a3 == 0 )
      return result;
    goto LABEL_10;
  }
  v4 = 0;
  while ( *(_DWORD *)(qword_14003BB58 + 8 * v4) != -368179260 )
  {
    if ( qword_14003BB50 == ++v4 )
      goto LABEL_5;
  }
  v6 = a3;
  result = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v4 + 4), 2, a1, a2, v10, v11);
  a3 = v6;
  if ( v6 != 0 )
  {
LABEL_10:
    if ( (_DWORD)result == -1073741558 )
    {
      v13 = -10000LL * a3;
      if ( qword_14003BB50 != 0 )
      {
        v7 = 0;
        while ( *(_DWORD *)(qword_14003BB58 + 8 * v7) != 577455468 )
        {
          if ( qword_14003BB50 == ++v7 )
            goto LABEL_15;
        }
        v8 = a3 == -1;
        v9 = &v13;
        if ( v8 )
          v9 = nullptr;
        return sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v7 + 4), 3, a1, 0, (__int64)v9, v11);
      }
      else
      {
LABEL_15:
        v12 = 0;
        LODWORD(result) = -895800841;
        do
        {
          ++v12;
          result = (895800840 * v12) ^ (unsigned int)result;
        }
        while ( v12 == 0 );
      }
    }
  }
  return result;
}


// ---- sub_140030560 @ 0x140030560 ----
__int64 __fastcall sub_140030560(int a1, int a2, unsigned int a3, __int64 a4, __int64 a5, __int64 *a6)
{
  __int64 *v6; // r10
  __int64 v7; // rdi
  __int64 result; // rax
  int v9; // [rsp+4Ch] [rbp-1Ch]
  __int64 v10; // [rsp+50h] [rbp-18h] BYREF

  v10 = 0;
  v6 = &v10;
  if ( a6 != nullptr )
    v6 = a6;
  if ( qword_14003BB50 != 0 )
  {
    v7 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v7) != 849309269 )
    {
      if ( qword_14003BB50 == ++v7 )
        goto LABEL_7;
    }
    return sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v7 + 4), 6, a1, a2, a3, a4, a5, v6);
  }
  else
  {
LABEL_7:
    v9 = 0;
    LODWORD(result) = -895800841;
    do
    {
      ++v9;
      result = (895800840 * v9) ^ (unsigned int)result;
    }
    while ( v9 == 0 );
  }
  return result;
}


// ---- sub_140030630 @ 0x140030630 ----
__int64 __fastcall sub_140030630(int a1, int a2, __int64 a3, __int64 a4, char *a5)
{
  char *v5; // r10
  __int64 v6; // rsi
  __int64 result; // rax
  int v8; // [rsp+44h] [rbp-14h]
  char v9; // [rsp+48h] [rbp-10h] BYREF

  v5 = &v9;
  if ( a5 != nullptr )
    v5 = a5;
  if ( qword_14003BB50 != 0 )
  {
    v6 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v6) != -2043607876 )
    {
      if ( qword_14003BB50 == ++v6 )
        goto LABEL_7;
    }
    return sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v6 + 4), 5, a1, a2, a3, a4, v5);
  }
  else
  {
LABEL_7:
    v8 = 0;
    LODWORD(result) = -895800841;
    do
    {
      ++v8;
      result = (895800840 * v8) ^ (unsigned int)result;
    }
    while ( v8 == 0 );
  }
  return result;
}


// ---- sub_1400306E0 @ 0x1400306e0 ----
__int64 __fastcall sub_1400306E0(
        __int64 a1,
        __int64 (__fastcall *a2)(__int64, _QWORD, _QWORD, __int64, __int64),
        __int64 a3)
{
  __int64 v6; // rdx
  __int64 result; // rax
  __int64 v8; // rdx
  __int64 v9; // r14
  __int64 v10; // rdx
  int v11; // r9d
  __int64 v12; // rdx
  __int64 v13; // r15
  __int64 v14; // r8
  int v15; // eax
  int v16; // r13d
  char v17; // bp
  int v18; // [rsp+38h] [rbp-1C0h] BYREF
  __int64 v19; // [rsp+40h] [rbp-1B8h] BYREF
  __int64 v20; // [rsp+48h] [rbp-1B0h] BYREF
  _QWORD v21[8]; // [rsp+50h] [rbp-1A8h] BYREF
  unsigned int v22; // [rsp+90h] [rbp-168h]
  unsigned __int16 v23; // [rsp+AAh] [rbp-14Eh]
  __int64 v24; // [rsp+B0h] [rbp-148h]
  _BYTE v25[8]; // [rsp+188h] [rbp-70h] BYREF
  __int64 v26; // [rsp+190h] [rbp-68h]

  if ( qword_14003BB50 != 0 )
  {
    v6 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v6) != -279929060 )
    {
      if ( qword_14003BB50 == ++v6 )
        goto LABEL_5;
    }
    result = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v6 + 4), 5, a1, 0, (__int64)v25, 48, 0);
    if ( (int)result < 0 )
      return result;
  }
  else
  {
LABEL_5:
    LODWORD(v21[0]) = 0;
    LODWORD(result) = -895800841;
    do
    {
      ++LODWORD(v21[0]);
      result = (895800840 * LODWORD(v21[0])) ^ (unsigned int)result;
    }
    while ( LODWORD(v21[0]) == 0 );
    if ( (int)result < 0 )
      return result;
  }
  if ( qword_14003BB50 != 0 )
  {
    v8 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v8) != -2043607876 )
    {
      if ( qword_14003BB50 == ++v8 )
        goto LABEL_14;
    }
    result = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v8 + 4), 5, a1, (int)v26 + 24, (__int64)&v20, 8, v21);
    if ( (int)result < 0 )
      return result;
  }
  else
  {
LABEL_14:
    LODWORD(v21[0]) = 0;
    LODWORD(result) = -895800841;
    do
    {
      ++LODWORD(v21[0]);
      result = (895800840 * LODWORD(v21[0])) ^ (unsigned int)result;
    }
    while ( LODWORD(v21[0]) == 0 );
    if ( (int)result < 0 )
      return result;
  }
  v9 = (v20 ^ 0x10) + 2 * (v20 & 0x10);
  if ( qword_14003BB50 != 0 )
  {
    v10 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v10) != -2043607876 )
    {
      if ( qword_14003BB50 == ++v10 )
        goto LABEL_23;
    }
    result = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v10 + 4), 5, a1, v9, (__int64)&v19, 8, v21);
    if ( (int)result >= 0 )
    {
LABEL_28:
      v11 = v19;
      if ( v19 == v9 )
        return result;
      do
      {
        if ( qword_14003BB50 != 0 )
        {
          v12 = 0;
          while ( *(_DWORD *)(qword_14003BB58 + 8 * v12) != -2043607876 )
          {
            if ( qword_14003BB50 == ++v12 )
              goto LABEL_37;
          }
          result = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v12 + 4), 5, a1, v11, (__int64)v21, 312, &v18);
          if ( (int)result < 0 )
            return result;
        }
        else
        {
LABEL_37:
          v18 = 0;
          LODWORD(result) = -895800841;
          do
          {
            ++v18;
            result = (895800840 * v18) ^ (unsigned int)result;
          }
          while ( v18 == 0 );
          if ( (int)result < 0 )
            return result;
        }
        if ( v24 != 0 && v23 != 0 )
        {
          v13 = sub_14002E070(v23);
          if ( qword_14003BB50 != 0 )
          {
            v14 = 0;
            while ( *(_DWORD *)(qword_14003BB58 + 8 * v14) != -2043607876 )
            {
              if ( qword_14003BB50 == ++v14 )
                goto LABEL_47;
            }
            v16 = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v14 + 4), 5, a1, v24, v13, v23, &v18);
            if ( v16 < 0 )
            {
LABEL_31:
              sub_14002E0B0(v13);
              result = (unsigned int)v16;
              goto LABEL_32;
            }
          }
          else
          {
LABEL_47:
            v18 = 0;
            v15 = -895800841;
            do
            {
              ++v18;
              v15 ^= 895800840 * v18;
            }
            while ( v18 == 0 );
            v16 = v15;
            if ( v15 < 0 )
              goto LABEL_31;
          }
          v17 = a2(a1, v21[6], v22, v13, a3);
          sub_14002E0B0(v13);
          result = (unsigned int)v16;
          if ( v17 != 0 )
            return result;
        }
LABEL_32:
        v11 = v21[0];
        v19 = v21[0];
      }
      while ( v9 != v21[0] );
    }
  }
  else
  {
LABEL_23:
    LODWORD(v21[0]) = 0;
    LODWORD(result) = -895800841;
    do
    {
      ++LODWORD(v21[0]);
      result = (895800840 * LODWORD(v21[0])) ^ (unsigned int)result;
    }
    while ( LODWORD(v21[0]) == 0 );
    if ( (int)result >= 0 )
      goto LABEL_28;
  }
  return result;
}


// ---- sub_140030B40 @ 0x140030b40 ----
__int64 __fastcall sub_140030B40(int a1, __int64 a2, int a3)
{
  __int64 v6; // rdx
  int v7; // ecx
  __int64 result; // rax
  int v9; // ecx
  __int64 v10; // rdx
  int v11; // ecx
  int v12; // ecx
  __int64 v13; // rdx
  int v14; // eax
  __int64 v15; // r15
  __int64 v16; // r14
  __int64 v17; // r15
  __int64 v18; // rdx
  int v19; // eax
  __int64 v20; // rcx
  __int64 v21; // r15
  __int64 v22; // r8
  unsigned int v23; // eax
  unsigned int v24; // eax
  int v25; // eax
  char v26; // r9
  unsigned int v27; // edx
  _DWORD *v28; // r8
  int i; // r9d
  __int64 v30; // rsi
  _DWORD v31[3]; // [rsp+38h] [rbp-2C0h] BYREF
  unsigned __int16 v32; // [rsp+46h] [rbp-2B2h] BYREF
  char v33[24]; // [rsp+48h] [rbp-2B0h] BYREF
  unsigned int v34; // [rsp+60h] [rbp-298h]
  int v35; // [rsp+64h] [rbp-294h]
  int v36; // [rsp+68h] [rbp-290h]
  int v37; // [rsp+6Ch] [rbp-28Ch]
  _DWORD v38[63]; // [rsp+70h] [rbp-288h] BYREF
  char v39; // [rsp+16Fh] [rbp-189h]
  _DWORD v40[34]; // [rsp+178h] [rbp-180h] BYREF
  int v41; // [rsp+200h] [rbp-F8h]
  int v42; // [rsp+204h] [rbp-F4h]
  __int16 v43[30]; // [rsp+280h] [rbp-78h] BYREF
  int v44; // [rsp+2BCh] [rbp-3Ch]

  if ( qword_14003BB50 != 0 )
  {
    v6 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v6) != -2043607876 )
    {
      if ( qword_14003BB50 == ++v6 )
        goto LABEL_5;
    }
    v9 = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v6 + 4), 5, a1, a2, (__int64)v43, 64, v40);
    result = 0;
    if ( v9 < 0 )
      return result;
  }
  else
  {
LABEL_5:
    v40[0] = 0;
    v7 = -895800841;
    do
    {
      ++v40[0];
      v7 ^= 895800840 * v40[0];
    }
    while ( v40[0] == 0 );
    result = 0;
    if ( v7 < 0 )
      return result;
  }
  if ( v43[0] != 23117 )
    return result;
  if ( qword_14003BB50 != 0 )
  {
    v10 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v10) != -2043607876 )
    {
      if ( qword_14003BB50 == ++v10 )
        goto LABEL_15;
    }
    v12 = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v10 + 4), 5, a1, (int)a2 + v44, (__int64)v40, 264, v38);
    result = 0;
    if ( v12 < 0 )
      return result;
  }
  else
  {
LABEL_15:
    v40[0] = 0;
    v11 = -895800841;
    do
    {
      ++v40[0];
      v11 ^= 895800840 * v40[0];
    }
    while ( v40[0] == 0 );
    result = 0;
    if ( v11 < 0 )
      return result;
  }
  if ( v40[0] != 17744 )
    return result;
  if ( v42 == 0 || v41 == 0 )
    return 0;
  if ( qword_14003BB50 != 0 )
  {
    v13 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v13) != -2043607876 )
    {
      if ( qword_14003BB50 == ++v13 )
        goto LABEL_26;
    }
    if ( (int)sub_14002F100(
                *(unsigned int *)(qword_14003BB58 + 8 * v13 + 4),
                5,
                a1,
                (int)a2 + v41,
                (__int64)v33,
                40,
                v38) < 0 )
      return 0;
  }
  else
  {
LABEL_26:
    v38[0] = 0;
    v14 = -895800841;
    do
    {
      ++v38[0];
      v14 ^= 895800840 * v38[0];
    }
    while ( v38[0] == 0 );
    if ( v14 < 0 )
      return 0;
  }
  v15 = v34;
  v16 = sub_14002E070(4LL * v34);
  if ( qword_14003BB50 != 0 )
  {
    v17 = ((unsigned int)v15 & 0xFFFFFFFB) * (v15 & 4 ^ 4) + (v15 & 4) * (v15 | 4);
    v18 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v18) != -2043607876 )
    {
      if ( qword_14003BB50 == ++v18 )
        goto LABEL_33;
    }
    if ( (int)sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v18 + 4), 5, a1, (int)a2 + v36, v16, v17, v38) < 0 )
    {
LABEL_63:
      v30 = 0;
      goto LABEL_66;
    }
  }
  else
  {
LABEL_33:
    v38[0] = 0;
    v19 = -895800841;
    do
    {
      ++v38[0];
      v19 ^= 895800840 * v38[0];
    }
    while ( v38[0] == 0 );
    if ( v19 < 0 )
      goto LABEL_63;
  }
  if ( v34 == 0 )
    goto LABEL_64;
  v20 = 0;
  v21 = 0;
  while ( 1 )
  {
    if ( qword_14003BB50 != 0 )
    {
      v22 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v22) != -2043607876 )
      {
        if ( qword_14003BB50 == ++v22 )
          goto LABEL_44;
      }
      v24 = sub_14002F100(
              *(unsigned int *)(qword_14003BB58 + 8 * v22 + 4),
              5,
              a1,
              (int)a2 + *(_DWORD *)(v16 + 4 * v21),
              (__int64)v38,
              256,
              v31);
      v20 = 0;
      if ( v24 > 0xBFFFFFFF )
        goto LABEL_39;
    }
    else
    {
LABEL_44:
      v31[0] = 0;
      v23 = -895800841;
      do
      {
        ++v31[0];
        v23 ^= 895800840 * v31[0];
      }
      while ( v31[0] == 0 );
      if ( v23 > 0xBFFFFFFF )
        goto LABEL_39;
    }
    v39 = 0;
    v31[0] = 0;
    v25 = 357392774;
    do
    {
      ++v31[0];
      v25 ^= -118103386 * v31[0];
    }
    while ( v31[0] == 0 );
    v26 = v38[0];
    if ( LOBYTE(v38[0]) != 0 )
      break;
    if ( a3 == 1772650887 )
      goto LABEL_57;
LABEL_39:
    if ( ++v21 >= (unsigned __int64)v34 )
      goto LABEL_65;
  }
  v27 = -1772650888;
  v28 = v38;
  do
  {
    v27 ^= v26;
    for ( i = 8; i != 0; --i )
      v27 = (v27 >> 1) ^ v25 & -(v27 & 1);
    v26 = *((_BYTE *)v28 + 1);
    v28 = (_DWORD *)((char *)v28 + 1);
  }
  while ( v26 != 0 );
  if ( ~v27 != a3 )
    goto LABEL_39;
LABEL_57:
  if ( (int)sub_140030630(a1, v37 + (int)a2 + 2 * (int)v21, (__int64)&v32, 2, nullptr) >= 0
    && (int)sub_140030630(a1, ((4 * v32) ^ (a2 + v35)) + 2 * ((4 * v32) & (a2 + v35)), (__int64)v31, 4, nullptr) >= 0 )
  {
    v20 = (a2 ^ v31[0]) + 2LL * (v31[0] & (unsigned int)a2);
    goto LABEL_65;
  }
LABEL_64:
  v20 = 0;
LABEL_65:
  v30 = v20;
LABEL_66:
  sub_140001C10(v16);
  return v30;
}


// ---- sub_1400310E0 @ 0x1400310e0 ----
__int64 __fastcall sub_1400310E0(
        _WORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned __int64 a5,
        unsigned __int64 *a6)
{
  __int64 result; // rax
  unsigned int v7; // eax
  _WORD *v8; // rax
  unsigned __int16 *v9; // r10
  unsigned __int16 *v10; // rcx
  int v11; // edi
  __int64 v12; // rdi
  bool v13; // zf
  unsigned __int64 v14; // rdi
  __int64 v15; // rbx
  __int16 v16; // bp
  __int16 v17; // r12
  int v19; // [rsp+2Ch] [rbp-3Ch]

  if ( a1 != nullptr )
  {
    if ( *a1 == 0 )
      return 3221225728LL;
  }
  else
  {
    v19 = 0;
    v7 = 1402752987;
    do
    {
      ++v19;
      v7 ^= 1402752955 * v19;
    }
    while ( v19 == 0 );
    a1 = *(_WORD **)(*(_QWORD *)(__readgsqword(v7) + 32) + 128LL);
    result = 3221225728LL;
    if ( a1 == nullptr || *a1 == 0 )
      return result;
  }
  while ( 2 )
  {
    v8 = a1;
    v9 = a1 + 1;
    do
    {
      v10 = v9;
      v11 = *v9++;
      if ( v11 == 0 )
      {
        v10 = v9 - 1;
        v9 = nullptr;
        v14 = 0;
        goto LABEL_15;
      }
    }
    while ( v11 != 61 );
    v12 = -2;
    do
    {
      v12 += 2;
      v13 = v10[1] == 0;
      ++v10;
    }
    while ( !v13 );
    v14 = v12 >> 1;
LABEL_15:
    a1 = v10 + 1;
    v15 = 0;
    while ( 1 )
    {
      if ( a3 == v15 )
      {
LABEL_26:
        *a6 = v14;
        result = 3221225507LL;
        if ( v14 <= a5 )
        {
          sub_140001C40(a4, (__int64)v9, 2 * v14);
          result = 0;
          if ( v14 < a5 )
            *(_WORD *)(a4 + 2 * v14) = 0;
        }
        return result;
      }
      v16 = *(_WORD *)(a2 + 2 * v15) | 0x20;
      if ( (unsigned __int16)(*(_WORD *)(a2 + 2 * v15) - 65) >= 0x1Au )
        v16 = *(_WORD *)(a2 + 2 * v15);
      v17 = v8[v15] | 0x20;
      if ( (unsigned __int16)(v8[v15] - 65) >= 0x1Au )
        v17 = v8[v15];
      if ( v16 != v17 )
        break;
      ++v15;
      if ( v16 == 0 )
        goto LABEL_26;
    }
    result = 3221225728LL;
    if ( *a1 != 0 )
      continue;
    return result;
  }
}


// ---- sub_140031280 @ 0x140031280 ----
__int64 __fastcall sub_140031280(_WORD *a1, _WORD *a2, __int64 a3, _WORD *a4, unsigned __int64 a5, __int64 *a6)
{
  unsigned __int64 v8; // rdx
  __int64 v9; // r14
  __int64 v10; // rbp
  int v11; // edi
  _WORD *v12; // r12
  unsigned __int64 v13; // rsi
  __int64 v14; // r13
  int v15; // eax
  _WORD *v16; // r12
  __int64 v17; // r13
  __int64 v18; // r13
  bool v19; // sf
  unsigned __int64 v20; // rax
  __int64 v21; // rbp
  __int64 *v22; // rax
  unsigned __int64 v24; // [rsp+30h] [rbp-58h]
  unsigned __int64 v25; // [rsp+38h] [rbp-50h] BYREF
  _WORD *v26; // [rsp+40h] [rbp-48h]

  v26 = a1;
  v8 = a5;
  if ( a3 == 0 )
  {
    v21 = 1;
    v22 = a6;
    if ( a5 == 0 )
      goto LABEL_30;
LABEL_25:
    *a4 = 0;
    v11 = 0;
LABEL_26:
    if ( v22 == nullptr )
      return (unsigned int)v11;
LABEL_27:
    *v22 = v21;
    return (unsigned int)v11;
  }
  v9 = a3;
  v10 = 0;
  v11 = 0;
  do
  {
    while ( 1 )
    {
      if ( *a2 != 37 || v9 == 1 )
        goto LABEL_12;
      v12 = a2 + 1;
      v13 = 0;
      v14 = 0;
      while ( v12[v14] != 37 )
      {
        ++v14;
        v13 -= 2LL;
        if ( v14 + 1 - v9 == 0 )
          goto LABEL_12;
      }
      if ( v14 != 0 )
      {
        v25 = 0;
        v24 = v8;
        v15 = sub_1400310E0(v26, (__int64)(a2 + 1), v14, (__int64)a4, v8, &v25);
        if ( v15 >= 0 || v15 == -1073741789 )
          break;
        v8 = v24;
      }
LABEL_12:
      if ( v11 >= 0 )
      {
        if ( v8 != 0 )
        {
          --v8;
          *a4++ = *a2;
          v11 = 0;
        }
        else
        {
          v11 = -1073741789;
          v8 = 0;
        }
      }
      ++v10;
      --v9;
      ++a2;
      if ( v9 == 0 )
        goto LABEL_23;
    }
    v16 = &v12[v13 / 0xFFFFFFFFFFFFFFFEuLL];
    v10 += v25;
    v17 = (-(int)v13 & 4) + (v14 ^ 2);
    v18 = 2 * (v9 & ~v17) - (v9 ^ v17);
    v19 = v15 < 0;
    if ( v15 < 0 )
      v11 = v15;
    v20 = 0;
    if ( !v19 )
      v20 = v25;
    v8 = v24 - v20;
    a4 += v20;
    v9 = v18;
    a2 = v16 + 1;
  }
  while ( v18 != 0 );
LABEL_23:
  v21 = v10 + 1;
  v22 = a6;
  if ( v11 < 0 )
    goto LABEL_26;
  if ( v8 != 0 )
    goto LABEL_25;
LABEL_30:
  v11 = -1073741789;
  if ( v22 != nullptr )
    goto LABEL_27;
  return (unsigned int)v11;
}


// ---- sub_140031450 @ 0x140031450 ----
__int64 __fastcall sub_140031450(__int64 a1, int a2, int a3, unsigned int a4, __int64 a5)
{
  __int64 v5; // r10
  bool v6; // zf
  __int64 v7; // r10
  __int64 result; // rax
  int v9; // [rsp+34h] [rbp-44h]
  _WORD v10[4]; // [rsp+38h] [rbp-40h] BYREF
  __int64 v11; // [rsp+40h] [rbp-38h]
  int v12; // [rsp+48h] [rbp-30h] BYREF
  __int64 v13; // [rsp+50h] [rbp-28h]
  _WORD *v14; // [rsp+58h] [rbp-20h]
  int v15; // [rsp+60h] [rbp-18h]
  __int128 v16; // [rsp+68h] [rbp-10h]

  v5 = 0;
  do
  {
    v6 = *(_WORD *)(a1 + v5) == 0;
    v5 += 2;
  }
  while ( !v6 );
  v10[0] = (v5 - 2) & 0xFFFE;
  v10[1] = v10[0] + 2;
  v11 = a1;
  v12 = 48;
  v13 = a5;
  v15 = 64;
  v14 = v10;
  v16 = 0;
  if ( qword_14003BB50 != 0 )
  {
    v7 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v7) != 989745270 )
    {
      if ( qword_14003BB50 == ++v7 )
        goto LABEL_7;
    }
    return sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v7 + 4), 4, a2, a3, (__int64)&v12, a4);
  }
  else
  {
LABEL_7:
    v9 = 0;
    LODWORD(result) = -895800841;
    do
    {
      ++v9;
      result = (895800840 * v9) ^ (unsigned int)result;
    }
    while ( v9 == 0 );
  }
  return result;
}


// ---- sub_140031550 @ 0x140031550 ----
__int64 __fastcall sub_140031550(int a1, int a2, __int16 *a3, unsigned int *a4)
{
  __int64 v8; // rdx
  __int64 result; // rax
  int v10; // ecx
  __int64 v11; // rax
  __int64 v12; // r8
  int v13; // edx
  __int64 v14; // rcx
  int v15; // r8d
  __int64 v16; // rbx
  unsigned int v17; // r9d
  __int16 *v18; // r8
  __int64 v19; // rcx
  __int64 v20; // r11
  __int16 v21; // bx
  __int16 *v22; // r10
  __int16 *v23; // r11
  __int16 *v24; // r10
  __int16 *v25; // r11
  unsigned int v26; // esi
  int v27; // [rsp+48h] [rbp-30h]
  int v28; // [rsp+48h] [rbp-30h]
  int v29; // [rsp+48h] [rbp-30h]
  _DWORD v30[11]; // [rsp+4Ch] [rbp-2Ch] BYREF

  if ( qword_14003BB50 != 0 )
  {
    v8 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v8) != -1783001607 )
    {
      if ( qword_14003BB50 == ++v8 )
        goto LABEL_5;
    }
    result = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v8 + 4), 6, a1, a2, 0, 0, 0, v30);
  }
  else
  {
LABEL_5:
    v27 = 0;
    LODWORD(result) = -895800841;
    do
    {
      ++v27;
      result = (895800840 * v27) ^ (unsigned int)result;
    }
    while ( v27 == 0 );
  }
  v28 = 0;
  v10 = -1550870831;
  do
  {
    ++v28;
    v10 ^= 1670354674 * v28;
  }
  while ( v28 == 0 );
  if ( (_DWORD)result == v10 )
  {
    v11 = sub_14002E070(v30[0]);
    if ( qword_14003BB50 != 0 )
    {
      v12 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v12) != -1783001607 )
      {
        if ( qword_14003BB50 == ++v12 )
          goto LABEL_16;
      }
      v14 = *(unsigned int *)(qword_14003BB58 + 8 * v12 + 4);
      v15 = a1;
      v16 = v11;
      v13 = sub_14002F100(v14, 6, v15, a2, 0, v11, v30[0], v30);
      v11 = v16;
      if ( a4 == nullptr )
        goto LABEL_36;
    }
    else
    {
LABEL_16:
      v29 = 0;
      v13 = -895800841;
      do
      {
        ++v29;
        v13 ^= 895800840 * v29;
      }
      while ( v29 == 0 );
      if ( a4 == nullptr )
      {
LABEL_36:
        v26 = v13;
        sub_14002E0B0(v11);
        return v26;
      }
    }
    if ( v13 >= 0 )
    {
      if ( a3 != nullptr )
      {
        v17 = *(_DWORD *)(v11 + 12) >> 1;
        if ( *a4 < v17 )
          v17 = *a4;
        if ( v17 != 0 )
        {
          v18 = (__int16 *)(v11 + 16);
          v19 = v17;
          if ( (v17 & 3) != 0 )
          {
            v20 = 0;
            do
            {
              v21 = *v18;
              v18 += *v18 != 0;
              *a3++ = v21;
              ++v20;
            }
            while ( (v17 & 3) != v20 );
            v19 = v17 - v20;
          }
          v22 = a3;
          if ( v17 >= 4 )
          {
            do
            {
              v23 = &v18[*v18 != 0];
              *a3 = *v18;
              v24 = &v23[*v23 != 0];
              a3[1] = *v23;
              v25 = &v24[*v24 != 0];
              a3[2] = *v24;
              v22 = a3 + 4;
              v18 = &v25[*v25 != 0];
              a3[3] = *v25;
              a3 += 4;
              v19 -= 4;
            }
            while ( v19 != 0 );
          }
        }
        else
        {
          v22 = a3;
        }
        *v22 = 0;
      }
      *a4 = *(_DWORD *)(v11 + 12) >> 1;
    }
    goto LABEL_36;
  }
  return result;
}


// ---- sub_140031820 @ 0x140031820 ----
__int64 __fastcall sub_140031820(
        int a1,
        __int16 *a2,
        unsigned int *a3,
        _DWORD *a4,
        _DWORD *a5,
        _DWORD *a6,
        _DWORD *a7,
        _DWORD *a8,
        _DWORD *a9)
{
  __int64 v13; // rdx
  __int64 result; // rax
  int v15; // ecx
  _DWORD *v16; // rax
  __int64 v17; // r8
  int v18; // edx
  __int64 v19; // rcx
  int v20; // r8d
  _DWORD *v21; // r14
  unsigned int v22; // r9d
  __int16 *v23; // r8
  __int64 v24; // rcx
  __int64 v25; // r11
  __int16 v26; // bp
  __int16 *v27; // r10
  __int16 *v28; // r11
  __int16 *v29; // r10
  __int16 *v30; // r11
  unsigned int v31; // esi
  int v32; // [rsp+38h] [rbp-30h]
  int v33; // [rsp+38h] [rbp-30h]
  int v34; // [rsp+38h] [rbp-30h]
  _DWORD v35[11]; // [rsp+3Ch] [rbp-2Ch] BYREF

  if ( qword_14003BB50 != 0 )
  {
    v13 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v13) != 2073805848 )
    {
      if ( qword_14003BB50 == ++v13 )
        goto LABEL_5;
    }
    result = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v13 + 4), 5, a1, 2, 0, 0, v35);
  }
  else
  {
LABEL_5:
    v32 = 0;
    LODWORD(result) = -895800841;
    do
    {
      ++v32;
      result = (895800840 * v32) ^ (unsigned int)result;
    }
    while ( v32 == 0 );
  }
  v33 = 0;
  v15 = -1043918720;
  do
  {
    ++v33;
    v15 ^= 29823139 * v33;
  }
  while ( v33 == 0 );
  if ( (_DWORD)result == v15 )
  {
    v16 = (_DWORD *)sub_14002E070(v35[0]);
    if ( qword_14003BB50 != 0 )
    {
      v17 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v17) != 2073805848 )
      {
        if ( qword_14003BB50 == ++v17 )
          goto LABEL_16;
      }
      v19 = *(unsigned int *)(qword_14003BB58 + 8 * v17 + 4);
      v20 = a1;
      v21 = v16;
      v18 = sub_14002F100(v19, 5, v20, 2, (__int64)v16, v35[0], v35);
      v16 = v21;
      if ( v18 < 0 )
        goto LABEL_48;
    }
    else
    {
LABEL_16:
      v34 = 0;
      v18 = -895800841;
      do
      {
        ++v34;
        v18 ^= 895800840 * v34;
      }
      while ( v34 == 0 );
      if ( v18 < 0 )
      {
LABEL_48:
        v31 = v18;
        sub_14002E0B0((__int64)v16);
        return v31;
      }
    }
    if ( a3 != nullptr )
    {
      if ( a2 != nullptr )
      {
        v22 = v16[4] >> 1;
        if ( *a3 < v22 )
          v22 = *a3;
        if ( v22 != 0 )
        {
          v23 = (__int16 *)(v16 + 11);
          v24 = v22;
          if ( (v22 & 3) != 0 )
          {
            v25 = 0;
            do
            {
              v26 = *v23;
              v23 += *v23 != 0;
              *a2++ = v26;
              ++v25;
            }
            while ( (v22 & 3) != v25 );
            v24 = v22 - v25;
          }
          v27 = a2;
          if ( v22 >= 4 )
          {
            do
            {
              v28 = &v23[*v23 != 0];
              *a2 = *v23;
              v29 = &v28[*v28 != 0];
              a2[1] = *v28;
              v30 = &v29[*v29 != 0];
              a2[2] = *v29;
              v27 = a2 + 4;
              v23 = &v30[*v30 != 0];
              a2[3] = *v30;
              a2 += 4;
              v24 -= 4;
            }
            while ( v24 != 0 );
          }
        }
        else
        {
          v27 = a2;
        }
        *v27 = 0;
      }
      *a3 = v16[4] >> 1;
    }
    if ( a4 != nullptr )
      *a4 = v16[5];
    if ( a5 != nullptr )
      *a5 = v16[6] >> 1;
    if ( a6 != nullptr )
      *a6 = v16[7] >> 1;
    if ( a7 != nullptr )
      *a7 = v16[8];
    if ( a8 != nullptr )
      *a8 = v16[9] >> 1;
    if ( a9 != nullptr )
      *a9 = v16[10];
    goto LABEL_48;
  }
  return result;
}


// ---- sub_140031B50 @ 0x140031b50 ----
__int64 __fastcall sub_140031B50(int a1, __int64 a2, _DWORD *a3, __int64 a4, _DWORD *a5)
{
  __int64 v8; // rcx
  bool v9; // zf
  __int16 v10; // r8
  __int64 v11; // rdx
  int v12; // ebp
  int v13; // eax
  __int64 v14; // r14
  __int64 v15; // rdx
  unsigned __int64 v16; // r8
  int v18; // [rsp+48h] [rbp-40h]
  int v19; // [rsp+48h] [rbp-40h]
  int v20; // [rsp+48h] [rbp-40h]
  unsigned int v21; // [rsp+4Ch] [rbp-3Ch] BYREF
  _WORD v22[4]; // [rsp+50h] [rbp-38h] BYREF
  __int64 v23; // [rsp+58h] [rbp-30h]

  v8 = 0;
  if ( a2 != 0 )
  {
    do
    {
      v9 = *(_WORD *)(a2 + v8) == 0;
      v8 += 2;
    }
    while ( !v9 );
    LOWORD(v8) = (v8 - 2) & 0xFFFE;
  }
  v10 = v8 + 2;
  v22[0] = v8;
  if ( a2 == 0 )
    v10 = 0;
  v22[1] = v10;
  v23 = a2;
  if ( qword_14003BB50 != 0 )
  {
    v11 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v11) != 1655466551 )
    {
      if ( qword_14003BB50 == ++v11 )
        goto LABEL_10;
    }
    v12 = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v11 + 4), 6, a1, (unsigned int)v22, 2, 0, 0, &v21);
  }
  else
  {
LABEL_10:
    v18 = 0;
    v12 = -895800841;
    do
    {
      ++v18;
      v12 ^= 895800840 * v18;
    }
    while ( v18 == 0 );
  }
  v19 = 0;
  v13 = -30014426;
  do
  {
    ++v19;
    v13 = ((1043727365 * v19) | v13) & (-2 - (v13 + ((1043727365 * v19) | ~v13)));
  }
  while ( v19 == 0 );
  if ( v12 == v13 )
  {
    v14 = sub_14002E070(v21);
    if ( qword_14003BB50 != 0 )
    {
      v15 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v15) != 1655466551 )
      {
        if ( qword_14003BB50 == ++v15 )
          goto LABEL_21;
      }
      v12 = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v15 + 4), 6, a1, (unsigned int)v22, 2, v14, v21, &v21);
      if ( v12 < 0 )
        goto LABEL_34;
    }
    else
    {
LABEL_21:
      v20 = 0;
      v12 = -895800841;
      do
      {
        ++v20;
        v12 ^= 895800840 * v20;
      }
      while ( v20 == 0 );
      if ( v12 < 0 )
      {
LABEL_34:
        sub_14002E0B0(v14);
        return (unsigned int)v12;
      }
    }
    if ( a3 != nullptr )
      *a3 = *(_DWORD *)(v14 + 4);
    if ( a5 != nullptr )
    {
      if ( a4 != 0 )
      {
        v16 = *(unsigned int *)(v14 + 8);
        if ( *a5 < (unsigned int)v16 )
          v16 = (unsigned int)*a5;
        sub_140001C40(a4, v14 + 12, v16);
      }
      *a5 = *(_DWORD *)(v14 + 8);
    }
    goto LABEL_34;
  }
  return (unsigned int)v12;
}


// ---- sub_140031DB0 @ 0x140031db0 ----
__int64 __fastcall sub_140031DB0(
        __int64 a1,
        int a2,
        int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7)
{
  __int64 v11; // rax
  bool v12; // zf
  __int64 v13; // r13
  __int64 v14; // rax
  __int64 v15; // rcx
  __int64 v16; // rax
  __int64 v17; // rcx
  __int64 v18; // rdx
  __int16 v19; // r8
  __int64 v20; // r8
  __int16 v21; // r10
  __int64 v22; // rdx
  unsigned int v23; // esi
  int v24; // r9d
  __int64 v25; // rdi
  __int64 v27; // [rsp+68h] [rbp-90h] BYREF
  __int64 v28; // [rsp+70h] [rbp-88h]
  _DWORD v29[4]; // [rsp+78h] [rbp-80h] BYREF
  unsigned __int64 v30; // [rsp+88h] [rbp-70h] BYREF
  __int64 v31; // [rsp+90h] [rbp-68h]
  __int64 *v32; // [rsp+98h] [rbp-60h]
  int v33; // [rsp+A0h] [rbp-58h]
  __int128 v34; // [rsp+A8h] [rbp-50h]

  v11 = -2;
  do
  {
    v12 = *(_WORD *)(a1 + v11 + 2) == 0;
    v11 += 2;
  }
  while ( !v12 );
  v13 = v11 >> 1;
  v14 = v11 + 10;
  v15 = -1;
  if ( v13 >= -5 )
    v15 = v14;
  v16 = sub_14002E070(v15);
  v30 = 0xDA0CA3836D1736C8uLL;
  LOWORD(v31) = 4324;
  LODWORD(v27) = 0;
  do
  {
    v17 = (int)v27;
    LODWORD(v27) = v27 + 1;
    *((_WORD *)&v30 + v17) ^= 13972 * (_WORD)v27;
  }
  while ( (unsigned int)v27 < 5 );
  v18 = 0;
  do
  {
    v19 = *(_WORD *)((char *)&v30 + v18);
    *(_WORD *)(v16 + v18) = v19;
    v18 += 2;
  }
  while ( v19 != 0 );
  v20 = 0;
  do
  {
    v21 = *(_WORD *)(a1 + v20);
    *(_WORD *)(v18 + v16 + v20 - 2) = v21;
    v20 += 2;
  }
  while ( v21 != 0 );
  LOWORD(v27) = (v13 & 2) * ((v13 + 4) | 2) + ((v13 + 4) & 0xFFFD) * (v13 & 2 ^ 2);
  WORD1(v27) = v27 + 2;
  v28 = v16;
  LODWORD(v30) = 48;
  v31 = 0;
  v33 = 64;
  v32 = &v27;
  v34 = 0;
  if ( qword_14003BB50 != 0 )
  {
    v22 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v22) != -694559300 )
    {
      if ( qword_14003BB50 == ++v22 )
        goto LABEL_15;
    }
    v24 = a3;
    v25 = v16;
    v23 = sub_14002F100(
            *(unsigned int *)(qword_14003BB58 + 8 * v22 + 4),
            11,
            a2,
            v24,
            (__int64)&v30,
            (__int64)v29,
            0,
            a7,
            a4,
            a5,
            a6,
            0,
            0,
            v27,
            v28);
    v16 = v25;
  }
  else
  {
LABEL_15:
    v29[0] = 0;
    v23 = -895800841;
    do
    {
      ++v29[0];
      v23 ^= 895800840 * v29[0];
    }
    while ( v29[0] == 0 );
  }
  sub_140001C10(v16);
  return v23;
}


// ---- sub_140032010 @ 0x140032010 ----
__int64 __fastcall sub_140032010(__int64 a1, int a2, int a3, unsigned int a4, unsigned int a5)
{
  __int64 v9; // rax
  bool v10; // zf
  __int64 v11; // r15
  __int64 v12; // rax
  __int64 v13; // rcx
  __int64 v14; // rax
  signed int v15; // ecx
  __int64 v16; // rcx
  __int16 v17; // dx
  __int64 v18; // rdx
  __int16 v19; // r9
  __int64 v20; // rdx
  unsigned int v21; // esi
  int v22; // r9d
  __int64 v23; // rdi
  unsigned int i; // [rsp+48h] [rbp-80h] BYREF
  __int64 v26; // [rsp+50h] [rbp-78h]
  _DWORD v27[4]; // [rsp+58h] [rbp-70h] BYREF
  unsigned __int64 v28; // [rsp+68h] [rbp-60h] BYREF
  __int64 v29; // [rsp+70h] [rbp-58h]
  unsigned int *p_i; // [rsp+78h] [rbp-50h]
  int v31; // [rsp+80h] [rbp-48h]
  __int128 v32; // [rsp+88h] [rbp-40h]

  v9 = -2;
  do
  {
    v10 = *(_WORD *)(a1 + v9 + 2) == 0;
    v9 += 2;
  }
  while ( !v10 );
  v11 = v9 >> 1;
  v12 = v9 + 10;
  v13 = -1;
  if ( v11 >= -5 )
    v13 = v12;
  v14 = sub_14002E070(v13);
  v28 = 0xB298C62CD95DECEDuLL;
  LOWORD(v29) = -24715;
  for ( i = 0; i < 5; *((_WORD *)&v28 + v15) ^= (i & 0x134E) * (i & 0xECB1 ^ 0xECB1) + (i & 0xECB1) * (i | 0xECB1) )
    v15 = i++;
  v16 = 0;
  do
  {
    v17 = *(_WORD *)((char *)&v28 + v16);
    *(_WORD *)(v14 + v16) = v17;
    v16 += 2;
  }
  while ( v17 != 0 );
  v18 = 0;
  do
  {
    v19 = *(_WORD *)(a1 + v18);
    *(_WORD *)(v16 + v14 + v18 - 2) = v19;
    v18 += 2;
  }
  while ( v19 != 0 );
  LOWORD(i) = 2 * v11 + 8;
  HIWORD(i) = 2 * v11 + 10;
  v26 = v14;
  LODWORD(v28) = 48;
  v29 = 0;
  v31 = 64;
  p_i = &i;
  v32 = 0;
  if ( qword_14003BB50 != 0 )
  {
    v20 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v20) != -1279250598 )
    {
      if ( qword_14003BB50 == ++v20 )
        goto LABEL_15;
    }
    v22 = a3;
    v23 = v14;
    v21 = sub_14002F100(
            *(unsigned int *)(qword_14003BB58 + 8 * v20 + 4),
            6,
            a2,
            v22,
            (__int64)&v28,
            (__int64)v27,
            a4,
            a5);
    v14 = v23;
  }
  else
  {
LABEL_15:
    v27[0] = 0;
    v21 = -895800841;
    do
    {
      ++v27[0];
      v21 ^= 895800840 * v27[0];
    }
    while ( v27[0] == 0 );
  }
  sub_140001C10(v14);
  return v21;
}


// ---- sub_140032240 @ 0x140032240 ----
__int64 __fastcall sub_140032240(__int64 a1, _DWORD *a2)
{
  __int64 v4; // rax
  bool v5; // zf
  __int64 v6; // rbx
  __int64 v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rcx
  __int64 v10; // rcx
  __int16 v11; // dx
  __int64 v12; // rdx
  __int16 v13; // r9
  __int64 v14; // r8
  unsigned int v15; // edi
  __int64 v17; // rbx
  __int64 v18; // [rsp+20h] [rbp-88h]
  __int64 v19; // [rsp+28h] [rbp-80h] BYREF
  int v20; // [rsp+48h] [rbp-60h]
  _WORD v21[4]; // [rsp+50h] [rbp-58h] BYREF
  __int64 v22; // [rsp+58h] [rbp-50h]
  unsigned __int64 v23; // [rsp+60h] [rbp-48h] BYREF
  __int64 v24; // [rsp+68h] [rbp-40h]
  _WORD *v25; // [rsp+70h] [rbp-38h]
  int v26; // [rsp+78h] [rbp-30h]
  __int128 v27; // [rsp+80h] [rbp-28h]

  v4 = -2;
  do
  {
    v5 = *(_WORD *)(a1 + v4 + 2) == 0;
    v4 += 2;
  }
  while ( !v5 );
  v6 = ((v4 >> 1) ^ 4) + (v4 & 8);
  v7 = -1;
  if ( v6 + 1 >= 0 )
    v7 = 2 * v6 + 2;
  v8 = sub_14002E070(v7);
  v23 = 0x8B1CE84F459FA28CuLL;
  LOWORD(v24) = 11792;
  LODWORD(v19) = 0;
  do
  {
    v9 = (int)v19;
    LODWORD(v19) = v19 + 1;
    *((_WORD *)&v23 + v9) = (*((_WORD *)&v23 + v9) | (-23856 * v19))
                          & ((*((_WORD *)&v23 + v9) & (-23856 * v19)) + ~(2 * (*((_WORD *)&v23 + v9) & (-23856 * v19))));
  }
  while ( (unsigned int)v19 < 5 );
  v10 = 0;
  do
  {
    v11 = *(_WORD *)((char *)&v23 + v10);
    *(_WORD *)(v8 + v10) = v11;
    v10 += 2;
  }
  while ( v11 != 0 );
  v12 = 0;
  do
  {
    v13 = *(_WORD *)(a1 + v12);
    *(_WORD *)(v10 + v8 + v12 - 2) = v13;
    v12 += 2;
  }
  while ( v13 != 0 );
  v21[0] = 2 * v6;
  v21[1] = 2 * v6 + 2;
  v22 = v8;
  LODWORD(v23) = 48;
  v24 = 0;
  v26 = 64;
  v25 = v21;
  v27 = 0;
  if ( qword_14003BB50 == 0 )
  {
LABEL_15:
    LODWORD(v19) = 0;
    v15 = -895800841;
    do
    {
      LODWORD(v19) = v19 + 1;
      v15 ^= 895800840 * v19;
    }
    while ( (_DWORD)v19 == 0 );
    sub_140001C10(v8);
    if ( a2 == nullptr )
      return v15;
LABEL_18:
    *a2 = v20;
    return v15;
  }
  v14 = 0;
  while ( *(_DWORD *)(qword_14003BB58 + 8 * v14) != 2081000212 )
  {
    if ( qword_14003BB50 == ++v14 )
      goto LABEL_15;
  }
  v17 = v8;
  v15 = sub_14002F100(
          *(unsigned int *)(qword_14003BB58 + 8 * v14 + 4),
          2,
          (unsigned int)&v23,
          (unsigned int)&v19,
          v18,
          v19);
  sub_140001C10(v17);
  if ( a2 != nullptr )
    goto LABEL_18;
  return v15;
}


// ---- sub_140032460 @ 0x140032460 ----
__int64 __fastcall sub_140032460(int a1, _DWORD *a2, _BYTE *a3)
{
  __int64 v3; // r10
  __int64 result; // rax
  _DWORD *v5; // rsi
  _BYTE *v6; // rdi
  _DWORD v7[5]; // [rsp+40h] [rbp-38h] BYREF
  char v8; // [rsp+55h] [rbp-23h]
  char v9; // [rsp+58h] [rbp-20h] BYREF

  if ( qword_14003BB50 == 0 )
  {
LABEL_5:
    v7[0] = 0;
    LODWORD(result) = -895800841;
    do
    {
      ++v7[0];
      result = (895800840 * v7[0]) ^ (unsigned int)result;
    }
    while ( v7[0] == 0 );
    if ( a2 == nullptr )
      goto LABEL_9;
    goto LABEL_8;
  }
  v3 = 0;
  while ( *(_DWORD *)(qword_14003BB58 + 8 * v3) != 674329531 )
  {
    if ( qword_14003BB50 == ++v3 )
      goto LABEL_5;
  }
  v5 = a2;
  v6 = a3;
  result = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v3 + 4), 5, a1, (unsigned int)&v9, (__int64)v7, 24, 5);
  a2 = v5;
  a3 = v6;
  if ( v5 != nullptr )
LABEL_8:
    *a2 = v7[2];
LABEL_9:
  if ( a3 != nullptr )
    *a3 = v8;
  return result;
}


// ---- sub_140032540 @ 0x140032540 ----
__int64 __fastcall sub_140032540(int a1, __int64 a2, unsigned int a3, _DWORD *a4)
{
  __int64 v6; // r9
  __int64 result; // rax
  int v8; // ecx
  unsigned __int64 v9; // rdx
  int v10; // ecx
  int v11; // edx
  __int64 v12; // [rsp+28h] [rbp-60h]
  int v13; // [rsp+64h] [rbp-24h]
  int v14; // [rsp+64h] [rbp-24h]
  int v15; // [rsp+64h] [rbp-24h]
  _DWORD v16[8]; // [rsp+68h] [rbp-20h] BYREF

  if ( qword_14003BB50 != 0 )
  {
    v6 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v6) != -1329995138 )
    {
      if ( qword_14003BB50 == ++v6 )
        goto LABEL_5;
    }
    result = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v6 + 4), 9, a1, 0, 0, 0, v16, a2, a3, 0, 0);
  }
  else
  {
LABEL_5:
    v16[0] = 0;
    LODWORD(result) = -895800841;
    do
    {
      ++v16[0];
      result = (895800840 * v16[0]) ^ (unsigned int)result;
    }
    while ( v16[0] == 0 );
  }
  v13 = 0;
  v8 = 924052424;
  do
  {
    ++v13;
    v8 ^= 924052171 * v13;
  }
  while ( v13 == 0 );
  if ( (_DWORD)result == v8 )
  {
    if ( qword_14003BB50 != 0 )
    {
      v9 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v9) != 577455468 )
      {
        v9 = (v9 ^ 1) + 2 * (v9 & 1);
        if ( v9 >= qword_14003BB50 )
          goto LABEL_16;
      }
      result = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v9 + 4), 3, a1, 0, 0, v12);
      if ( (int)result < 0 )
        goto LABEL_20;
    }
    else
    {
LABEL_16:
      v14 = 0;
      LODWORD(result) = -895800841;
      do
      {
        ++v14;
        result = (895800840 * v14) ^ (unsigned int)result;
      }
      while ( v14 == 0 );
      if ( (int)result < 0 )
        goto LABEL_20;
    }
    result = v16[0];
  }
LABEL_20:
  if ( a4 != nullptr )
  {
    v15 = 0;
    v10 = -1790221205;
    do
    {
      ++v15;
      v10 ^= (v15 & 0xAAB49B85) * (v15 & 0x554B647A ^ 0x554B647A) + (v15 & 0x554B647A) * (v15 | 0x554B647A);
    }
    while ( v15 == 0 );
    v11 = 0;
    if ( (_DWORD)result != v10 )
      v11 = v16[2];
    *a4 = v11;
  }
  return result;
}


// ---- sub_140032750 @ 0x140032750 ----
__int64 __fastcall sub_140032750(int a1, __int64 a2, unsigned int a3, _DWORD *a4)
{
  __int64 v6; // r9
  __int64 result; // rax
  int v8; // ecx
  unsigned __int64 v9; // rdx
  __int64 v10; // [rsp+28h] [rbp-60h]
  int v11; // [rsp+64h] [rbp-24h]
  int v12; // [rsp+64h] [rbp-24h]
  _DWORD v13[8]; // [rsp+68h] [rbp-20h] BYREF

  if ( qword_14003BB50 != 0 )
  {
    v6 = 0;
    while ( *(_DWORD *)(qword_14003BB58 + 8 * v6) != -46252772 )
    {
      if ( qword_14003BB50 == ++v6 )
        goto LABEL_5;
    }
    result = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v6 + 4), 9, a1, 0, 0, 0, v13, a2, a3, 0, 0);
  }
  else
  {
LABEL_5:
    v13[0] = 0;
    LODWORD(result) = -895800841;
    do
    {
      ++v13[0];
      result = (895800840 * v13[0]) ^ (unsigned int)result;
    }
    while ( v13[0] == 0 );
  }
  v11 = 0;
  v8 = 1937956654;
  do
  {
    ++v11;
    v8 ^= 1937956397 * v11;
  }
  while ( v11 == 0 );
  if ( (_DWORD)result == v8 )
  {
    if ( qword_14003BB50 != 0 )
    {
      v9 = 0;
      while ( *(_DWORD *)(qword_14003BB58 + 8 * v9) != 577455468 )
      {
        v9 = (v9 ^ 1) + 2 * (v9 & 1);
        if ( v9 >= qword_14003BB50 )
          goto LABEL_16;
      }
      result = sub_14002F100(*(unsigned int *)(qword_14003BB58 + 8 * v9 + 4), 3, a1, 0, 0, v10);
      if ( (int)result < 0 )
        goto LABEL_20;
    }
    else
    {
LABEL_16:
      v12 = 0;
      LODWORD(result) = -895800841;
      do
      {
        ++v12;
        result = (895800840 * v12) ^ (unsigned int)result;
      }
      while ( v12 == 0 );
      if ( (int)result < 0 )
        goto LABEL_20;
    }
    result = v13[0];
  }
LABEL_20:
  if ( a4 != nullptr )
    *a4 = v13[2];
  return result;
}


// ---- sub_140032900 @ 0x140032900 ----
char __fastcall sub_140032900(__int64 a1, __int64 *a2)
{
  __int64 v2; // rax
  __int64 v3; // r8
  __int64 v4; // r9
  __int16 v5; // r10
  __int16 v6; // r11

  v2 = *(_QWORD *)(a1 + 64);
  if ( v2 == 0 )
    return 0;
  v3 = *a2;
  v4 = 0;
  do
  {
    v5 = *(_WORD *)(v2 + v4) | 0x20;
    if ( (unsigned __int16)(*(_WORD *)(v2 + v4) - 65) >= 0x1Au )
      v5 = *(_WORD *)(v2 + v4);
    v6 = *(_WORD *)(v3 + v4) | 0x20;
    if ( (unsigned __int16)(*(_WORD *)(v3 + v4) - 65) >= 0x1Au )
      v6 = *(_WORD *)(v3 + v4);
    if ( v5 == 0 )
      break;
    v4 += 2;
  }
  while ( v5 == v6 );
  if ( v5 != v6 )
    return 0;
  *(_QWORD *)a2[1] = *(_QWORD *)(a1 + 80);
  return 1;
}



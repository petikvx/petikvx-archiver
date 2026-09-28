/* Hex-Rays dump LockBit 3 sample EP 0x41946F */

/* sub_40105C @ 0040105C */
int __usercall sub_40105C@<eax>(__int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  __int64 v2; // rax

  if ( a2 >= 0x40u )
  {
    LODWORD(v2) = 0;
  }
  else if ( a2 >= 0x20u )
  {
    LODWORD(v2) = 0;
  }
  else
  {
    return a1 << (a2 & 0x1F);
  }
  return v2;
}


/* sub_40107C @ 0040107C */
void __stdcall sub_40107C(void *a1, const void *a2, unsigned int a3)
{
  qmemcpy(a1, a2, a3);
}


/* sub_401094 @ 00401094 */
int __stdcall sub_401094(void *a1, unsigned __int8 a2, unsigned int a3)
{
  memset(a1, a2, a3);
  return a2;
}


/* sub_4010AC @ 004010AC */
struct _PEB *sub_4010AC()
{
  return NtCurrentPeb();
}


/* sub_4010D4 @ 004010D4 */
int sub_4010D4()
{
  int result; // eax
  unsigned __int64 v14; // rax
  int v15; // ecx

  _EAX = 1;
  __asm { cpuid }
  if ( (_ECX & 0x40000000) != 0 )
  {
    __asm
    {
      rdrand  eax
      rdrand  edx
    }
  }
  else
  {
    _EAX = 7;
    __asm { cpuid }
    if ( (_EBX & 0x40000) != 0 )
    {
      __asm
      {
        rdseed  eax
        rdseed  edx
      }
    }
    else
    {
      v14 = __rdtsc();
      v15 = __ROR4__(v14, 13);
      __rdtsc();
      return v15;
    }
  }
  return result;
}


/* sub_401124 @ 00401124 */
unsigned int __stdcall sub_401124(unsigned int a1, unsigned int a2)
{
  unsigned int result; // eax

  do
  {
    do
      result = ((1664525 * sub_4010D4() + 1013904223) & 0x7FFFFFFu) % (a2 + 1);
    while ( result < a1 );
  }
  while ( result > a2 );
  return result;
}


/* sub_401190 @ 00401190 */
int __stdcall sub_401190(_BYTE *a1, int a2)
{
  int v2; // eax

  v2 = 0;
  do
  {
    LOBYTE(v2) = *a1++;
    a2 = v2 + __ROR4__(a2, 13);
  }
  while ( v2 != 0 );
  return a2;
}


/* sub_4011D4 @ 004011D4 */
int __stdcall sub_4011D4(_WORD *a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = 0;
  do
  {
    LOWORD(v2) = *a1++;
    if ( (unsigned __int16)v2 >= 0x41u && (unsigned __int16)v2 <= 0x5Au )
      LOWORD(v2) = v2 | 0x20;
    a2 = v2 + __ROR4__(a2, 13);
  }
  while ( v2 != 0 );
  return a2;
}


/* sub_401228 @ 00401228 */
int __stdcall sub_401228(__int16 *a1, _BYTE *a2)
{
  int i; // ebx
  __int16 v5; // ax

  for ( i = 0; ; ++i )
  {
    v5 = *a1++;
    if ( v5 == 0 )
      break;
    *a2++ = v5;
  }
  *a2 = 0;
  return i;
}


/* sub_401250 @ 00401250 */
void __stdcall sub_401250(int *a1, int a2)
{
  do
  {
    *a1 ^= 0x4803BFC7u;
    *a1 = ~*a1;
    ++a1;
    --a2;
  }
  while ( a2 != 0 );
}


/* sub_401274 @ 00401274 */
int __stdcall sub_401274(unsigned __int8 *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // ebx
  bool i; // zf
  int v8; // edi

  v3 = a2;
  v4 = (unsigned __int16)a3;
  v5 = HIWORD(a3);
  for ( i = a2 == 0; !i; i = v3 == 0 )
  {
    v8 = 4001;
    if ( v3 < 0xFA1 )
      v8 = v3;
    v3 -= v8;
    do
    {
      v4 += *a1++;
      v5 += v4;
      --v8;
    }
    while ( v8 != 0 );
    v5 %= 0x1000Fu;
    v4 %= 0x1000Fu;
  }
  return unk_424F70 ^ ((v5 << 16) + v4);
}


/* sub_4012F4 @ 004012F4 */
int __stdcall sub_4012F4(char *a1, _BYTE *a2)
{
  int *v2; // edi
  int v3; // ecx
  char v4; // al
  _BYTE *v5; // edi
  _BYTE *v6; // edi
  int v7; // ecx
  char v8; // al
  _BYTE *v9; // edi
  int i; // ecx
  char *v11; // edi
  char *v12; // esi
  char v13; // al
  int result; // eax
  unsigned int v15; // ebx
  bool v16; // dl
  bool v17; // zf
  unsigned int v19; // ebx
  char v20; // al
  unsigned __int8 v21; // ah
  int v22; // ecx
  __int16 v23; // kr00_2
  char v24; // bh
  int v25; // [esp-14h] [ebp-11Ch]
  _BYTE v26[48]; // [esp+4h] [ebp-104h] BYREF
  int v27; // [esp+34h] [ebp-D4h] BYREF
  unsigned int v28; // [esp+104h] [ebp-4h]

  v26[0] = 0;
  memset(&v26[1], 255, 0x2Au);
  v26[43] = 62;
  memset(&v26[44], 255, 3u);
  v26[47] = 63;
  v2 = &v27;
  v3 = 10;
  v4 = 52;
  do
  {
    *(_BYTE *)v2 = v4;
    v2 = (int *)((char *)v2 + 1);
    ++v4;
    --v3;
  }
  while ( v3 != 0 );
  memset(v2, 255, 3u);
  v5 = (char *)v2 + 3;
  *v5++ = 0;
  memset(v5, 255, 3u);
  v6 = v5 + 3;
  v7 = 26;
  v8 = 0;
  do
  {
    *v6++ = v8++;
    --v7;
  }
  while ( v7 != 0 );
  memset(v6, 255, 6u);
  v9 = v6 + 6;
  for ( i = 26; i != 0; --i )
    *v9++ = v8++;
  memset(v9, 255, 0x85u);
  v11 = a1;
  v12 = a1;
  do
  {
    v13 = *v11;
    v11 += 4;
  }
  while ( v13 != 0 );
  result = 61;
  v15 = v11 - 4 - a1;
  if ( v11 - 4 != a1 )
  {
    v16 = *(v11 - 5) == 61;
    if ( *(v11 - 5) == 61 )
      *(v11 - 5) = 0;
    v17 = *(v11 - 6) == 61;
    if ( *(v11 - 6) == 61 )
      *(v11 - 6) = 0;
    LOBYTE(result) = v16 + v17;
    v19 = v15 >> 2;
    v25 = 3 * v19 - result;
    v28 = v19;
    do
    {
      v20 = v26[(unsigned __int8)*(_DWORD *)v12];
      v21 = v26[BYTE1(*(_DWORD *)v12)];
      v22 = HIWORD(*(_DWORD *)v12);
      v12 += 4;
      v23 = (unsigned __int8)v26[(unsigned __int8)v22] << 6;
      v24 = v23 | v26[BYTE1(v22)];
      *a2 = (v21 >> 4) | (4 * v20);
      a2[2] = v24;
      a2[1] = HIBYTE(v23) | (16 * v21);
      v17 = v28-- == 1;
      a2 += 3;
    }
    while ( !v17 );
    return v25;
  }
  return result;
}


/* sub_401414 @ 00401414 */
char *__userpurge sub_401414@<eax>(int a1@<ebx>, _BYTE *a2, int a3, int *a4)
{
  int *v5; // edi
  unsigned __int16 v6; // ax
  _BYTE v8[64]; // [esp+4h] [ebp-44h] BYREF
  int v9; // [esp+44h] [ebp-4h]

  qmemcpy(v8, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", sizeof(v8));
  v9 = a3;
  v5 = a4;
  do
  {
    if ( v9 == 0 )
      break;
    LOBYTE(v6) = v8[*a2 >> 2];
    HIBYTE(v6) = v8[(unsigned __int8)((a2[1] >> 4) | (16 * (*a2 & 3)))];
    LOBYTE(a1) = v8[(unsigned __int8)((4 * (a2[1] & 0xF)) | (a2[2] >> 6))];
    BYTE1(a1) = v8[a2[2] & 0x3F];
    a1 <<= 16;
    a2 += 3;
    *v5++ = a1 | v6;
    v9 -= 3;
  }
  while ( v9 > 0 );
  if ( v9 != 0 )
  {
    v5 = (int *)((char *)v5 + v9);
    do
    {
      *(_BYTE *)v5 = 61;
      v5 = (int *)((char *)v5 + 1);
      ++v9;
    }
    while ( v9 != 0 );
  }
  *(_WORD *)v5 = 0;
  return (char *)((char *)v5 - (char *)a4);
}


/* sub_401518 @ 00401518 */
unsigned int __stdcall sub_401518(int a1)
{
  int v1; // edi
  int i; // ebx

  v1 = 0;
  for ( i = 0; *(_BYTE *)(a1 + i) != 0; ++i )
    ;
  if ( i != 0 )
  {
    if ( *(_BYTE *)(a1 + i - 1) == 61 && *(_BYTE *)(a1 + i - 2) == 61 )
    {
      v1 = 2;
    }
    else if ( *(_BYTE *)(a1 + i - 1) == 61 )
    {
      v1 = 1;
    }
  }
  return ((unsigned int)(3 * i) >> 2) - v1;
}


/* sub_401564 @ 00401564 */
int sub_401564()
{
  sub_4010AC();
  return 1;
}


/* sub_401574 @ 00401574 */
int sub_401574()
{
  int v0; // eax
  unsigned int v1; // esi
  int v2; // edi

  v0 = sub_4010AC();
  v1 = *(_DWORD *)(v0 + 164);
  v2 = *(_DWORD *)(v0 + 168);
  if ( v1 == 5 && v2 == 0 || v1 < 5 )
    return 0;
  if ( v1 == 5 && v2 == 1 )
    return 51;
  if ( v1 == 5 && v2 == 2 )
    return 52;
  if ( v1 == 6 && v2 == 0 )
    return 60;
  if ( v1 == 6 && v2 == 1 )
    return 61;
  if ( v1 == 6 && v2 == 2 )
    return 62;
  if ( v1 == 6 && v2 == 3 )
    return 63;
  if ( v1 == 10 && v2 == 0 )
    return 100;
  if ( v1 == 10 && v2 != 0 || v1 > 0xA )
    return 0x7FFFFFFF;
  return -1;
}


/* sub_401650 @ 00401650 */
wchar_t *sub_401650()
{
  return sub_4010AC()->ProcessParameters->CommandLine.Buffer;
}


/* sub_40165C @ 0040165C */
int sub_40165C()
{
  return *(_DWORD *)(*(_DWORD *)(sub_4010AC() + 16) + 60);
}


/* sub_401668 @ 00401668 */
__int16 __stdcall sub_401668(_WORD *a1)
{
  int v1; // esi
  __int16 v3; // ax
  _WORD *v4; // edi

  v1 = 2147352624;
  while ( 1 )
  {
    v3 = *(_WORD *)v1;
    v1 += 2;
    if ( v3 == 0 )
      break;
    *a1++ = v3;
  }
  *a1 = 92;
  v4 = a1 + 1;
  *(_DWORD *)v4 = 7929939;
  v4 += 2;
  *(_DWORD *)v4 = 7602291;
  v4 += 2;
  *(_DWORD *)v4 = 7143525;
  v4 += 2;
  *(_DWORD *)v4 = 3276851;
  v4[2] = 0;
  return 0;
}


/* sub_4016C8 @ 004016C8 */
int sub_4016C8()
{
  return MEMORY[0x7FFE02D8];
}


/* sub_4016D0 @ 004016D0 */
void __stdcall sub_4016D0(int a1)
{
  int i; // eax

  if ( a1 != 0 )
  {
    for ( i = 0; *(_WORD *)(a1 + 2 * i) != 0; ++i )
      ;
    if ( *(_WORD *)(a1 + 2 * i - 2) != 92 )
      *(_DWORD *)(a1 + 2 * i) = 92;
  }
}


/* sub_401700 @ 00401700 */
void __stdcall sub_401700(int a1)
{
  int i; // eax

  if ( a1 != 0 )
  {
    for ( i = 0; *(_WORD *)(a1 + 2 * i) != 0; ++i )
      ;
    if ( *(_WORD *)(a1 + 2 * i - 2) == 92 )
      *(_DWORD *)(a1 + 2 * i - 2) = 0;
  }
}


/* sub_401730 @ 00401730 */
unsigned int __stdcall sub_401730(_BYTE *a1, int a2)
{
  unsigned int result; // eax
  unsigned int v5; // edx
  _BYTE *v6; // esi
  int v7; // ebx
  _BYTE *v8; // esi
  int v9; // ebx
  _BYTE *v10; // esi
  int v11; // ebx
  _DWORD v12[2]; // [esp+4h] [ebp-Ch] BYREF
  int v13; // [esp+Ch] [ebp-4h]

  v12[0] = dword_426000[0];
  v12[1] = dword_426000[1];
LABEL_2:
  result = sub_4017BC(dword_426000, v12);
  v13 = 2;
  while ( 1 )
  {
    *a1 ^= result;
    v6 = a1 + 1;
    v7 = a2 - 1;
    if ( v7 == 0 )
      return result;
    *v6 ^= BYTE1(v5);
    v8 = v6 + 1;
    v9 = v7 - 1;
    if ( v9 == 0 )
      return result;
    *v8 ^= BYTE1(result);
    v10 = v8 + 1;
    v11 = v9 - 1;
    if ( v11 == 0 )
      return result;
    *v10 ^= v5;
    a1 = v10 + 1;
    a2 = v11 - 1;
    if ( a2 == 0 )
      return result;
    result >>= 16;
    v5 >>= 16;
    if ( --v13 == 0 )
      goto LABEL_2;
  }
}


/* sub_4017BC @ 004017BC */
// attributes: thunk
int __stdcall sub_4017BC(int a1, int a2)
{
  return dword_42519C(a1, a2);
}


/* sub_4017C4 @ 004017C4 */
_OWORD *__stdcall sub_4017C4(_OWORD *a1, int a2)
{
  _OWORD *result; // eax
  _OWORD *v3; // edx
  int i; // ecx
  _BYTE v5[132]; // [esp+20h] [ebp-114h] BYREF
  _DWORD v6[33]; // [esp+B0h] [ebp-84h] BYREF

  memset(&v6[1], 0, 124);
  v6[0] = 1;
  sub_401948(v6, v5, a2, a1);
  sub_401948(v6, v5, a2, 0);
  sub_401948(v6, v5, a2, a1);
  result = v6;
  v3 = a1;
  for ( i = 8; i != 0; --i )
    *v3++ = *result++;
  return result;
}


/* sub_401948 @ 00401948 */
const __m128i *__stdcall sub_401948(__m128i *a1, int a2, _DWORD *a3, int a4)
{
  const __m128i *v4; // esi
  __m128i *v5; // edi
  int i; // ecx
  __m128i *v7; // edi
  const __m128i *v8; // esi
  int j; // ecx
  __m128i *v10; // edi
  const __m128i *v11; // esi
  int k; // ecx
  __m128i *v13; // edi
  const __m128i *v14; // esi
  int m; // ecx
  __m128i *v16; // edi
  const __m128i *v17; // esi
  int n; // ecx
  __m128i *v19; // edi
  const __m128i *v20; // esi
  int ii; // ecx
  __m128i *v22; // edi
  const __m128i *v23; // esi
  int jj; // ecx
  __m128i *v25; // edi
  const __m128i *v26; // esi
  int kk; // ecx
  __m128i *v28; // edi
  const __m128i *v29; // esi
  const __m128i *result; // eax
  int mm; // ecx

  v4 = a1;
  v5 = (__m128i *)a2;
  for ( i = 8; i != 0; --i )
    *v5++ = _mm_load_si128(v4++);
  v7 = (__m128i *)a2;
  v8 = a1;
  sub_401AAC(a1, a2, a3);
  for ( j = 8; j != 0; --j )
    *v7++ = _mm_load_si128(v8++);
  v10 = (__m128i *)a2;
  v11 = a1;
  sub_401AAC(a1, a2, a3);
  for ( k = 8; k != 0; --k )
    *v10++ = _mm_load_si128(v11++);
  v13 = (__m128i *)a2;
  v14 = a1;
  sub_401AAC(a1, a2, a3);
  for ( m = 8; m != 0; --m )
    *v13++ = _mm_load_si128(v14++);
  v16 = (__m128i *)a2;
  v17 = a1;
  sub_401AAC(a1, a2, a3);
  for ( n = 8; n != 0; --n )
    *v16++ = _mm_load_si128(v17++);
  v19 = (__m128i *)a2;
  v20 = a1;
  sub_401AAC(a1, a2, a3);
  for ( ii = 8; ii != 0; --ii )
    *v19++ = _mm_load_si128(v20++);
  v22 = (__m128i *)a2;
  v23 = a1;
  sub_401AAC(a1, a2, a3);
  for ( jj = 8; jj != 0; --jj )
    *v22++ = _mm_load_si128(v23++);
  v25 = (__m128i *)a2;
  v26 = a1;
  sub_401AAC(a1, a2, a3);
  for ( kk = 8; kk != 0; --kk )
    *v25++ = _mm_load_si128(v26++);
  v28 = (__m128i *)a2;
  v29 = a1;
  result = sub_401AAC(a1, a2, a3);
  if ( a4 != 0 )
  {
    for ( mm = 8; mm != 0; --mm )
      *v28++ = _mm_load_si128(v29++);
    return sub_401AAC(a1, a4, a3);
  }
  return result;
}


/* sub_401AAC @ 00401AAC */
const __m128i *__stdcall sub_401AAC(__m128i *a1, int a2, _DWORD *a3)
{
  int v4; // esi
  int v5; // edi
  bool v6; // cf
  unsigned int v7; // ett
  unsigned int v8; // ett
  int v9; // ebx
  int v10; // esi
  int v11; // edi
  unsigned int v12; // ett
  unsigned int v13; // ett
  unsigned int v14; // ett
  unsigned int v15; // ett
  int v16; // ebx
  int v17; // esi
  int v18; // edi
  unsigned int v19; // ett
  unsigned int v20; // ett
  unsigned int v21; // ett
  unsigned int v22; // ett
  int v23; // ebx
  int v24; // esi
  int v25; // edi
  unsigned int v26; // ett
  unsigned int v27; // ett
  unsigned int v28; // ett
  unsigned int v29; // ett
  int v30; // ebx
  int v31; // esi
  int v32; // edi
  unsigned int v33; // ett
  unsigned int v34; // ett
  unsigned int v35; // ett
  unsigned int v36; // ett
  int v37; // ebx
  int v38; // esi
  int v39; // edi
  unsigned int v40; // ett
  unsigned int v41; // ett
  unsigned int v42; // ett
  unsigned int v43; // ett
  int v44; // ebx
  int v45; // esi
  int v46; // edi
  unsigned int v47; // ett
  unsigned int v48; // ett
  unsigned int v49; // ett
  unsigned int v50; // ett
  int v51; // ebx
  int v52; // esi
  int v53; // edi
  unsigned int v54; // ett
  unsigned int v55; // ett
  unsigned int v56; // ett
  unsigned int v57; // ett
  int v58; // ebx
  int v59; // esi
  int v60; // edi
  int v61; // ett
  BOOL v62; // ett
  int v63; // edx
  int v64; // ebx
  int v65; // esi
  int v66; // edi
  BOOL v67; // ett
  BOOL v68; // ett
  BOOL v69; // ett
  BOOL v70; // ett
  int v71; // edx
  int v72; // ebx
  int v73; // esi
  int v74; // edi
  BOOL v75; // ett
  BOOL v76; // ett
  BOOL v77; // ett
  BOOL v78; // ett
  int v79; // edx
  int v80; // ebx
  int v81; // esi
  int v82; // edi
  BOOL v83; // ett
  BOOL v84; // ett
  BOOL v85; // ett
  BOOL v86; // ett
  int v87; // edx
  int v88; // ebx
  int v89; // esi
  int v90; // edi
  BOOL v91; // ett
  BOOL v92; // ett
  BOOL v93; // ett
  BOOL v94; // ett
  int v95; // edx
  int v96; // ebx
  int v97; // esi
  int v98; // edi
  BOOL v99; // ett
  BOOL v100; // ett
  BOOL v101; // ett
  BOOL v102; // ett
  int v103; // edx
  int v104; // ebx
  int v105; // esi
  int v106; // edi
  BOOL v107; // ett
  BOOL v108; // ett
  BOOL v109; // ett
  BOOL v110; // ett
  int v111; // edx
  int v112; // ebx
  int v113; // esi
  int v114; // edi
  BOOL v115; // ett
  BOOL v116; // ett
  BOOL v117; // ett
  int v119; // esi
  int v120; // edi
  unsigned int v121; // ett
  unsigned int v122; // ett
  int v123; // ebx
  int v124; // esi
  int v125; // edi
  unsigned int v126; // ett
  unsigned int v127; // ett
  unsigned int v128; // ett
  unsigned int v129; // ett
  int v130; // ebx
  int v131; // esi
  int v132; // edi
  unsigned int v133; // ett
  unsigned int v134; // ett
  unsigned int v135; // ett
  unsigned int v136; // ett
  int v137; // ebx
  int v138; // esi
  int v139; // edi
  unsigned int v140; // ett
  unsigned int v141; // ett
  unsigned int v142; // ett
  unsigned int v143; // ett
  int v144; // ebx
  int v145; // esi
  int v146; // edi
  unsigned int v147; // ett
  unsigned int v148; // ett
  unsigned int v149; // ett
  unsigned int v150; // ett
  int v151; // ebx
  int v152; // esi
  int v153; // edi
  unsigned int v154; // ett
  unsigned int v155; // ett
  unsigned int v156; // ett
  unsigned int v157; // ett
  int v158; // ebx
  int v159; // esi
  int v160; // edi
  unsigned int v161; // ett
  unsigned int v162; // ett
  unsigned int v163; // ett
  unsigned int v164; // ett
  int v165; // ebx
  int v166; // esi
  int v167; // edi
  unsigned int v168; // ett
  unsigned int v169; // ett
  unsigned int v170; // ett
  unsigned int v171; // ett
  int v172; // ebx
  int v173; // esi
  int v174; // edi
  int v175; // ett
  BOOL v176; // ett
  int v177; // edx
  int v178; // ebx
  int v179; // esi
  int v180; // edi
  BOOL v181; // ett
  BOOL v182; // ett
  BOOL v183; // ett
  BOOL v184; // ett
  int v185; // edx
  int v186; // ebx
  int v187; // esi
  int v188; // edi
  BOOL v189; // ett
  BOOL v190; // ett
  BOOL v191; // ett
  BOOL v192; // ett
  int v193; // edx
  int v194; // ebx
  int v195; // esi
  int v196; // edi
  BOOL v197; // ett
  BOOL v198; // ett
  BOOL v199; // ett
  BOOL v200; // ett
  int v201; // edx
  int v202; // ebx
  int v203; // esi
  int v204; // edi
  BOOL v205; // ett
  BOOL v206; // ett
  BOOL v207; // ett
  BOOL v208; // ett
  int v209; // edx
  int v210; // ebx
  int v211; // esi
  int v212; // edi
  BOOL v213; // ett
  BOOL v214; // ett
  BOOL v215; // ett
  BOOL v216; // ett
  int v217; // edx
  int v218; // ebx
  int v219; // esi
  int v220; // edi
  BOOL v221; // ett
  BOOL v222; // ett
  BOOL v223; // ett
  BOOL v224; // ett
  int v225; // edx
  int v226; // ebx
  int v227; // esi
  int v228; // edi
  BOOL v229; // ett
  BOOL v230; // ett
  BOOL v231; // ett
  const __m128i *result; // eax
  __m128i *v233; // edx
  int j; // ecx
  int i; // [esp+Ch] [ebp-98h]
  unsigned __int64 v236; // [esp+20h] [ebp-84h] BYREF
  unsigned int v237; // [esp+28h] [ebp-7Ch]
  unsigned int v238; // [esp+2Ch] [ebp-78h]
  unsigned int v239; // [esp+30h] [ebp-74h]
  unsigned int v240; // [esp+34h] [ebp-70h]
  unsigned int v241; // [esp+38h] [ebp-6Ch]
  unsigned int v242; // [esp+3Ch] [ebp-68h]
  unsigned int v243; // [esp+40h] [ebp-64h]
  unsigned int v244; // [esp+44h] [ebp-60h]
  unsigned int v245; // [esp+48h] [ebp-5Ch]
  unsigned int v246; // [esp+4Ch] [ebp-58h]
  unsigned int v247; // [esp+50h] [ebp-54h]
  unsigned int v248; // [esp+54h] [ebp-50h]
  unsigned int v249; // [esp+58h] [ebp-4Ch]
  unsigned int v250; // [esp+5Ch] [ebp-48h]
  unsigned int v251; // [esp+60h] [ebp-44h]
  unsigned int v252; // [esp+64h] [ebp-40h]
  unsigned int v253; // [esp+68h] [ebp-3Ch]
  unsigned int v254; // [esp+6Ch] [ebp-38h]
  unsigned int v255; // [esp+70h] [ebp-34h]
  unsigned int v256; // [esp+74h] [ebp-30h]
  unsigned int v257; // [esp+78h] [ebp-2Ch]
  unsigned int v258; // [esp+7Ch] [ebp-28h]
  unsigned int v259; // [esp+80h] [ebp-24h]
  unsigned int v260; // [esp+84h] [ebp-20h]
  unsigned int v261; // [esp+88h] [ebp-1Ch]
  unsigned int v262; // [esp+8Ch] [ebp-18h]
  unsigned int v263; // [esp+90h] [ebp-14h]
  unsigned int v264; // [esp+94h] [ebp-10h]
  unsigned int v265; // [esp+98h] [ebp-Ch]
  unsigned int v266; // [esp+9Ch] [ebp-8h]

  v236 = 0;
  v237 = 0;
  v238 = 0;
  v239 = 0;
  v240 = 0;
  v241 = 0;
  v242 = 0;
  v243 = 0;
  v244 = 0;
  v245 = 0;
  v246 = 0;
  v247 = 0;
  v248 = 0;
  v249 = 0;
  v250 = 0;
  v251 = 0;
  v252 = 0;
  v253 = 0;
  v254 = 0;
  v255 = 0;
  v256 = 0;
  v257 = 0;
  v258 = 0;
  v259 = 0;
  v260 = 0;
  v261 = 0;
  v262 = 0;
  v263 = 0;
  v264 = 0;
  v265 = 0;
  v266 = 0;
  for ( i = 1024; i != 0; --i )
  {
    _EAX = &v236;
    __asm
    {
      rcl     dword ptr [eax], 1
      rcl     dword ptr [eax+4], 1
      rcl     dword ptr [eax+8], 1
      rcl     dword ptr [eax+0Ch], 1
      rcl     dword ptr [eax+10h], 1
      rcl     dword ptr [eax+14h], 1
      rcl     dword ptr [eax+18h], 1
      rcl     dword ptr [eax+1Ch], 1
      rcl     dword ptr [eax+20h], 1
      rcl     dword ptr [eax+24h], 1
      rcl     dword ptr [eax+28h], 1
      rcl     dword ptr [eax+2Ch], 1
      rcl     dword ptr [eax+30h], 1
      rcl     dword ptr [eax+34h], 1
      rcl     dword ptr [eax+38h], 1
      rcl     dword ptr [eax+3Ch], 1
      rcl     dword ptr [eax+40h], 1
      rcl     dword ptr [eax+44h], 1
      rcl     dword ptr [eax+48h], 1
      rcl     dword ptr [eax+4Ch], 1
      rcl     dword ptr [eax+50h], 1
      rcl     dword ptr [eax+54h], 1
      rcl     dword ptr [eax+58h], 1
      rcl     dword ptr [eax+5Ch], 1
      rcl     dword ptr [eax+60h], 1
      rcl     dword ptr [eax+64h], 1
      rcl     dword ptr [eax+68h], 1
      rcl     dword ptr [eax+6Ch], 1
      rcl     dword ptr [eax+70h], 1
      rcl     dword ptr [eax+74h], 1
      rcl     dword ptr [eax+78h], 1
      rcl     dword ptr [eax+7Ch], 1
    }
    v4 = a3[2];
    v5 = a3[3];
    v6 = v236 < *(_QWORD *)a3;
    v236 -= *(_QWORD *)a3;
    v7 = v6 + v4;
    v6 = v237 < v7;
    v237 -= v7;
    v8 = v6 + v5;
    v6 = v238 < v8;
    v238 -= v8;
    v9 = a3[5];
    v10 = a3[6];
    v11 = a3[7];
    v12 = v6 + a3[4];
    v6 = v239 < v12;
    v239 -= v12;
    v13 = v6 + v9;
    v6 = v240 < v13;
    v240 -= v13;
    v14 = v6 + v10;
    v6 = v241 < v14;
    v241 -= v14;
    v15 = v6 + v11;
    v6 = v242 < v15;
    v242 -= v15;
    v16 = a3[9];
    v17 = a3[10];
    v18 = a3[11];
    v19 = v6 + a3[8];
    v6 = v243 < v19;
    v243 -= v19;
    v20 = v6 + v16;
    v6 = v244 < v20;
    v244 -= v20;
    v21 = v6 + v17;
    v6 = v245 < v21;
    v245 -= v21;
    v22 = v6 + v18;
    v6 = v246 < v22;
    v246 -= v22;
    v23 = a3[13];
    v24 = a3[14];
    v25 = a3[15];
    v26 = v6 + a3[12];
    v6 = v247 < v26;
    v247 -= v26;
    v27 = v6 + v23;
    v6 = v248 < v27;
    v248 -= v27;
    v28 = v6 + v24;
    v6 = v249 < v28;
    v249 -= v28;
    v29 = v6 + v25;
    v6 = v250 < v29;
    v250 -= v29;
    v30 = a3[17];
    v31 = a3[18];
    v32 = a3[19];
    v33 = v6 + a3[16];
    v6 = v251 < v33;
    v251 -= v33;
    v34 = v6 + v30;
    v6 = v252 < v34;
    v252 -= v34;
    v35 = v6 + v31;
    v6 = v253 < v35;
    v253 -= v35;
    v36 = v6 + v32;
    v6 = v254 < v36;
    v254 -= v36;
    v37 = a3[21];
    v38 = a3[22];
    v39 = a3[23];
    v40 = v6 + a3[20];
    v6 = v255 < v40;
    v255 -= v40;
    v41 = v6 + v37;
    v6 = v256 < v41;
    v256 -= v41;
    v42 = v6 + v38;
    v6 = v257 < v42;
    v257 -= v42;
    v43 = v6 + v39;
    v6 = v258 < v43;
    v258 -= v43;
    v44 = a3[25];
    v45 = a3[26];
    v46 = a3[27];
    v47 = v6 + a3[24];
    v6 = v259 < v47;
    v259 -= v47;
    v48 = v6 + v44;
    v6 = v260 < v48;
    v260 -= v48;
    v49 = v6 + v45;
    v6 = v261 < v49;
    v261 -= v49;
    v50 = v6 + v46;
    v6 = v262 < v50;
    v262 -= v50;
    v51 = a3[29];
    v52 = a3[30];
    v53 = a3[31];
    v54 = v6 + a3[28];
    v6 = v263 < v54;
    v263 -= v54;
    v55 = v6 + v51;
    v6 = v264 < v55;
    v264 -= v55;
    v56 = v6 + v52;
    v6 = v265 < v56;
    v265 -= v56;
    v57 = v6 + v53;
    v6 = v266 < v57;
    v266 -= v57;
    if ( v6 )
    {
      v58 = a3[1];
      v59 = a3[2];
      v60 = a3[3];
      v6 = __CFADD__(*a3, (_DWORD)v236);
      v236 += *(_QWORD *)a3;
      v61 = __CFADD__(v6, HIDWORD(v236)) | __CFADD__(v58, v6 + HIDWORD(v236));
      v6 = __CFADD__(v61, v237) | __CFADD__(v59, v61 + v237);
      v237 += v59 + v61;
      v62 = v6;
      v6 = __CFADD__(v6, v238) | __CFADD__(v60, v6 + v238);
      v238 += v60 + v62;
      v63 = a3[4];
      v64 = a3[5];
      v65 = a3[6];
      v66 = a3[7];
      v67 = v6;
      v6 = __CFADD__(v6, v239) | __CFADD__(v63, v6 + v239);
      v239 += v63 + v67;
      v68 = v6;
      v6 = __CFADD__(v6, v240) | __CFADD__(v64, v6 + v240);
      v240 += v64 + v68;
      v69 = v6;
      v6 = __CFADD__(v6, v241) | __CFADD__(v65, v6 + v241);
      v241 += v65 + v69;
      v70 = v6;
      v6 = __CFADD__(v6, v242) | __CFADD__(v66, v6 + v242);
      v242 += v66 + v70;
      v71 = a3[8];
      v72 = a3[9];
      v73 = a3[10];
      v74 = a3[11];
      v75 = v6;
      v6 = __CFADD__(v6, v243) | __CFADD__(v71, v6 + v243);
      v243 += v71 + v75;
      v76 = v6;
      v6 = __CFADD__(v6, v244) | __CFADD__(v72, v6 + v244);
      v244 += v72 + v76;
      v77 = v6;
      v6 = __CFADD__(v6, v245) | __CFADD__(v73, v6 + v245);
      v245 += v73 + v77;
      v78 = v6;
      v6 = __CFADD__(v6, v246) | __CFADD__(v74, v6 + v246);
      v246 += v74 + v78;
      v79 = a3[12];
      v80 = a3[13];
      v81 = a3[14];
      v82 = a3[15];
      v83 = v6;
      v6 = __CFADD__(v6, v247) | __CFADD__(v79, v6 + v247);
      v247 += v79 + v83;
      v84 = v6;
      v6 = __CFADD__(v6, v248) | __CFADD__(v80, v6 + v248);
      v248 += v80 + v84;
      v85 = v6;
      v6 = __CFADD__(v6, v249) | __CFADD__(v81, v6 + v249);
      v249 += v81 + v85;
      v86 = v6;
      v6 = __CFADD__(v6, v250) | __CFADD__(v82, v6 + v250);
      v250 += v82 + v86;
      v87 = a3[16];
      v88 = a3[17];
      v89 = a3[18];
      v90 = a3[19];
      v91 = v6;
      v6 = __CFADD__(v6, v251) | __CFADD__(v87, v6 + v251);
      v251 += v87 + v91;
      v92 = v6;
      v6 = __CFADD__(v6, v252) | __CFADD__(v88, v6 + v252);
      v252 += v88 + v92;
      v93 = v6;
      v6 = __CFADD__(v6, v253) | __CFADD__(v89, v6 + v253);
      v253 += v89 + v93;
      v94 = v6;
      v6 = __CFADD__(v6, v254) | __CFADD__(v90, v6 + v254);
      v254 += v90 + v94;
      v95 = a3[20];
      v96 = a3[21];
      v97 = a3[22];
      v98 = a3[23];
      v99 = v6;
      v6 = __CFADD__(v6, v255) | __CFADD__(v95, v6 + v255);
      v255 += v95 + v99;
      v100 = v6;
      v6 = __CFADD__(v6, v256) | __CFADD__(v96, v6 + v256);
      v256 += v96 + v100;
      v101 = v6;
      v6 = __CFADD__(v6, v257) | __CFADD__(v97, v6 + v257);
      v257 += v97 + v101;
      v102 = v6;
      v6 = __CFADD__(v6, v258) | __CFADD__(v98, v6 + v258);
      v258 += v98 + v102;
      v103 = a3[24];
      v104 = a3[25];
      v105 = a3[26];
      v106 = a3[27];
      v107 = v6;
      v6 = __CFADD__(v6, v259) | __CFADD__(v103, v6 + v259);
      v259 += v103 + v107;
      v108 = v6;
      v6 = __CFADD__(v6, v260) | __CFADD__(v104, v6 + v260);
      v260 += v104 + v108;
      v109 = v6;
      v6 = __CFADD__(v6, v261) | __CFADD__(v105, v6 + v261);
      v261 += v105 + v109;
      v110 = v6;
      v6 = __CFADD__(v6, v262) | __CFADD__(v106, v6 + v262);
      v262 += v106 + v110;
      v111 = a3[28];
      v112 = a3[29];
      v113 = a3[30];
      v114 = a3[31];
      v115 = v6;
      v6 = __CFADD__(v6, v263) | __CFADD__(v111, v6 + v263);
      v263 += v111 + v115;
      v116 = v6;
      v6 = __CFADD__(v6, v264) | __CFADD__(v112, v6 + v264);
      v264 += v112 + v116;
      v117 = v6;
      v6 = __CFADD__(v6, v265) | __CFADD__(v113, v6 + v265);
      v265 += v113 + v117;
      v266 += v114 + v6;
    }
    _EAX = a1;
    __asm
    {
      rcl     dword ptr [eax], 1
      rcl     dword ptr [eax+4], 1
      rcl     dword ptr [eax+8], 1
      rcl     dword ptr [eax+0Ch], 1
      rcl     dword ptr [eax+10h], 1
      rcl     dword ptr [eax+14h], 1
      rcl     dword ptr [eax+18h], 1
      rcl     dword ptr [eax+1Ch], 1
      rcl     dword ptr [eax+20h], 1
      rcl     dword ptr [eax+24h], 1
      rcl     dword ptr [eax+28h], 1
      rcl     dword ptr [eax+2Ch], 1
      rcl     dword ptr [eax+30h], 1
      rcl     dword ptr [eax+34h], 1
      rcl     dword ptr [eax+38h], 1
      rcl     dword ptr [eax+3Ch], 1
      rcl     dword ptr [eax+40h], 1
      rcl     dword ptr [eax+44h], 1
      rcl     dword ptr [eax+48h], 1
      rcl     dword ptr [eax+4Ch], 1
      rcl     dword ptr [eax+50h], 1
      rcl     dword ptr [eax+54h], 1
      rcl     dword ptr [eax+58h], 1
      rcl     dword ptr [eax+5Ch], 1
      rcl     dword ptr [eax+60h], 1
      rcl     dword ptr [eax+64h], 1
      rcl     dword ptr [eax+68h], 1
      rcl     dword ptr [eax+6Ch], 1
      rcl     dword ptr [eax+70h], 1
      rcl     dword ptr [eax+74h], 1
      rcl     dword ptr [eax+78h], 1
      rcl     dword ptr [eax+7Ch], 1
    }
    v119 = a3[2];
    v120 = a3[3];
    v6 = v236 < *(_QWORD *)a3;
    v236 -= *(_QWORD *)a3;
    v121 = v6 + v119;
    v6 = v237 < v121;
    v237 -= v121;
    v122 = v6 + v120;
    v6 = v238 < v122;
    v238 -= v122;
    v123 = a3[5];
    v124 = a3[6];
    v125 = a3[7];
    v126 = v6 + a3[4];
    v6 = v239 < v126;
    v239 -= v126;
    v127 = v6 + v123;
    v6 = v240 < v127;
    v240 -= v127;
    v128 = v6 + v124;
    v6 = v241 < v128;
    v241 -= v128;
    v129 = v6 + v125;
    v6 = v242 < v129;
    v242 -= v129;
    v130 = a3[9];
    v131 = a3[10];
    v132 = a3[11];
    v133 = v6 + a3[8];
    v6 = v243 < v133;
    v243 -= v133;
    v134 = v6 + v130;
    v6 = v244 < v134;
    v244 -= v134;
    v135 = v6 + v131;
    v6 = v245 < v135;
    v245 -= v135;
    v136 = v6 + v132;
    v6 = v246 < v136;
    v246 -= v136;
    v137 = a3[13];
    v138 = a3[14];
    v139 = a3[15];
    v140 = v6 + a3[12];
    v6 = v247 < v140;
    v247 -= v140;
    v141 = v6 + v137;
    v6 = v248 < v141;
    v248 -= v141;
    v142 = v6 + v138;
    v6 = v249 < v142;
    v249 -= v142;
    v143 = v6 + v139;
    v6 = v250 < v143;
    v250 -= v143;
    v144 = a3[17];
    v145 = a3[18];
    v146 = a3[19];
    v147 = v6 + a3[16];
    v6 = v251 < v147;
    v251 -= v147;
    v148 = v6 + v144;
    v6 = v252 < v148;
    v252 -= v148;
    v149 = v6 + v145;
    v6 = v253 < v149;
    v253 -= v149;
    v150 = v6 + v146;
    v6 = v254 < v150;
    v254 -= v150;
    v151 = a3[21];
    v152 = a3[22];
    v153 = a3[23];
    v154 = v6 + a3[20];
    v6 = v255 < v154;
    v255 -= v154;
    v155 = v6 + v151;
    v6 = v256 < v155;
    v256 -= v155;
    v156 = v6 + v152;
    v6 = v257 < v156;
    v257 -= v156;
    v157 = v6 + v153;
    v6 = v258 < v157;
    v258 -= v157;
    v158 = a3[25];
    v159 = a3[26];
    v160 = a3[27];
    v161 = v6 + a3[24];
    v6 = v259 < v161;
    v259 -= v161;
    v162 = v6 + v158;
    v6 = v260 < v162;
    v260 -= v162;
    v163 = v6 + v159;
    v6 = v261 < v163;
    v261 -= v163;
    v164 = v6 + v160;
    v6 = v262 < v164;
    v262 -= v164;
    v165 = a3[29];
    v166 = a3[30];
    v167 = a3[31];
    v168 = v6 + a3[28];
    v6 = v263 < v168;
    v263 -= v168;
    v169 = v6 + v165;
    v6 = v264 < v169;
    v264 -= v169;
    v170 = v6 + v166;
    v6 = v265 < v170;
    v265 -= v170;
    v171 = v6 + v167;
    v6 = v266 < v171;
    v266 -= v171;
    if ( v6 )
    {
      v172 = a3[1];
      v173 = a3[2];
      v174 = a3[3];
      v6 = __CFADD__(*a3, (_DWORD)v236);
      v236 += *(_QWORD *)a3;
      v175 = __CFADD__(v6, HIDWORD(v236)) | __CFADD__(v172, v6 + HIDWORD(v236));
      v6 = __CFADD__(v175, v237) | __CFADD__(v173, v175 + v237);
      v237 += v173 + v175;
      v176 = v6;
      v6 = __CFADD__(v6, v238) | __CFADD__(v174, v6 + v238);
      v238 += v174 + v176;
      v177 = a3[4];
      v178 = a3[5];
      v179 = a3[6];
      v180 = a3[7];
      v181 = v6;
      v6 = __CFADD__(v6, v239) | __CFADD__(v177, v6 + v239);
      v239 += v177 + v181;
      v182 = v6;
      v6 = __CFADD__(v6, v240) | __CFADD__(v178, v6 + v240);
      v240 += v178 + v182;
      v183 = v6;
      v6 = __CFADD__(v6, v241) | __CFADD__(v179, v6 + v241);
      v241 += v179 + v183;
      v184 = v6;
      v6 = __CFADD__(v6, v242) | __CFADD__(v180, v6 + v242);
      v242 += v180 + v184;
      v185 = a3[8];
      v186 = a3[9];
      v187 = a3[10];
      v188 = a3[11];
      v189 = v6;
      v6 = __CFADD__(v6, v243) | __CFADD__(v185, v6 + v243);
      v243 += v185 + v189;
      v190 = v6;
      v6 = __CFADD__(v6, v244) | __CFADD__(v186, v6 + v244);
      v244 += v186 + v190;
      v191 = v6;
      v6 = __CFADD__(v6, v245) | __CFADD__(v187, v6 + v245);
      v245 += v187 + v191;
      v192 = v6;
      v6 = __CFADD__(v6, v246) | __CFADD__(v188, v6 + v246);
      v246 += v188 + v192;
      v193 = a3[12];
      v194 = a3[13];
      v195 = a3[14];
      v196 = a3[15];
      v197 = v6;
      v6 = __CFADD__(v6, v247) | __CFADD__(v193, v6 + v247);
      v247 += v193 + v197;
      v198 = v6;
      v6 = __CFADD__(v6, v248) | __CFADD__(v194, v6 + v248);
      v248 += v194 + v198;
      v199 = v6;
      v6 = __CFADD__(v6, v249) | __CFADD__(v195, v6 + v249);
      v249 += v195 + v199;
      v200 = v6;
      v6 = __CFADD__(v6, v250) | __CFADD__(v196, v6 + v250);
      v250 += v196 + v200;
      v201 = a3[16];
      v202 = a3[17];
      v203 = a3[18];
      v204 = a3[19];
      v205 = v6;
      v6 = __CFADD__(v6, v251) | __CFADD__(v201, v6 + v251);
      v251 += v201 + v205;
      v206 = v6;
      v6 = __CFADD__(v6, v252) | __CFADD__(v202, v6 + v252);
      v252 += v202 + v206;
      v207 = v6;
      v6 = __CFADD__(v6, v253) | __CFADD__(v203, v6 + v253);
      v253 += v203 + v207;
      v208 = v6;
      v6 = __CFADD__(v6, v254) | __CFADD__(v204, v6 + v254);
      v254 += v204 + v208;
      v209 = a3[20];
      v210 = a3[21];
      v211 = a3[22];
      v212 = a3[23];
      v213 = v6;
      v6 = __CFADD__(v6, v255) | __CFADD__(v209, v6 + v255);
      v255 += v209 + v213;
      v214 = v6;
      v6 = __CFADD__(v6, v256) | __CFADD__(v210, v6 + v256);
      v256 += v210 + v214;
      v215 = v6;
      v6 = __CFADD__(v6, v257) | __CFADD__(v211, v6 + v257);
      v257 += v211 + v215;
      v216 = v6;
      v6 = __CFADD__(v6, v258) | __CFADD__(v212, v6 + v258);
      v258 += v212 + v216;
      v217 = a3[24];
      v218 = a3[25];
      v219 = a3[26];
      v220 = a3[27];
      v221 = v6;
      v6 = __CFADD__(v6, v259) | __CFADD__(v217, v6 + v259);
      v259 += v217 + v221;
      v222 = v6;
      v6 = __CFADD__(v6, v260) | __CFADD__(v218, v6 + v260);
      v260 += v218 + v222;
      v223 = v6;
      v6 = __CFADD__(v6, v261) | __CFADD__(v219, v6 + v261);
      v261 += v219 + v223;
      v224 = v6;
      v6 = __CFADD__(v6, v262) | __CFADD__(v220, v6 + v262);
      v262 += v220 + v224;
      v225 = a3[28];
      v226 = a3[29];
      v227 = a3[30];
      v228 = a3[31];
      v229 = v6;
      v6 = __CFADD__(v6, v263) | __CFADD__(v225, v6 + v263);
      v263 += v225 + v229;
      v230 = v6;
      v6 = __CFADD__(v6, v264) | __CFADD__(v226, v6 + v264);
      v264 += v226 + v230;
      v231 = v6;
      v6 = __CFADD__(v6, v265) | __CFADD__(v227, v6 + v265);
      v265 += v227 + v231;
      v266 += v228 + v6;
    }
  }
  result = (const __m128i *)&v236;
  v233 = a1;
  for ( j = 8; j != 0; --j )
    *v233++ = _mm_load_si128(result++);
  return result;
}


/* sub_4020BC @ 004020BC */
void __cdecl sub_4020BC(unsigned int a1, __m128i *a2, unsigned int a3)
{
  _OWORD *v3; // esi
  __int128 v4; // xmm0
  int v5; // edx
  int v6; // esi
  int v7; // ecx
  int v8; // ebx
  int v9; // ebp
  int v10; // edi
  int v11; // eax
  int v12; // ebp
  int v13; // ebx
  int v14; // edx
  int v15; // ecx
  bool v16; // zf
  int v17; // eax
  __m128i *v18; // edi
  bool v19; // cf
  unsigned int v20; // ebx
  unsigned int v21; // edx
  __m128i *v22; // ecx
  __m128i v23; // xmm0
  __m128i *v24; // ecx
  char *v25; // ebp
  unsigned int v26; // edi
  char v27; // al
  int v28; // [esp+8h] [ebp-84h]
  int v29; // [esp+8h] [ebp-84h]
  __int64 v30; // [esp+Ch] [ebp-80h]
  int v31; // [esp+14h] [ebp-78h]
  int v32; // [esp+14h] [ebp-78h]
  int v33; // [esp+18h] [ebp-74h]
  int v34; // [esp+18h] [ebp-74h]
  int v35; // [esp+1Ch] [ebp-70h]
  int v36; // [esp+1Ch] [ebp-70h]
  int v37; // [esp+20h] [ebp-6Ch]
  int v38; // [esp+20h] [ebp-6Ch]
  int v39; // [esp+24h] [ebp-68h]
  int v40; // [esp+24h] [ebp-68h]
  int v41; // [esp+28h] [ebp-64h]
  int v42; // [esp+28h] [ebp-64h]
  int v43; // [esp+2Ch] [ebp-60h]
  int v44; // [esp+2Ch] [ebp-60h]
  int v45; // [esp+30h] [ebp-5Ch]
  int v46; // [esp+30h] [ebp-5Ch]
  int v48; // [esp+38h] [ebp-54h]
  int v49; // [esp+3Ch] [ebp-50h]
  unsigned int v50; // [esp+44h] [ebp-48h] BYREF
  _QWORD v51[2]; // [esp+48h] [ebp-44h] BYREF
  _QWORD v52[2]; // [esp+58h] [ebp-34h] BYREF
  __int128 v53; // [esp+68h] [ebp-24h]
  __int128 v54; // [esp+78h] [ebp-14h] BYREF

  v3 = (_OWORD *)a3;
  if ( a1 != 0 )
  {
    v50 = a3 + 60;
    do
    {
      v48 = 10;
      *(_OWORD *)v51 = *v3;
      *(_OWORD *)v52 = v3[1];
      v53 = v3[2];
      v4 = v3[3];
      v5 = HIDWORD(v53);
      v6 = v52[0];
      v41 = DWORD2(v53);
      v31 = DWORD1(v53);
      v33 = v53;
      v30 = v52[1];
      v39 = HIDWORD(v52[0]);
      v28 = HIDWORD(v51[1]);
      v35 = v51[1];
      v54 = v4;
      v7 = HIDWORD(v4);
      v8 = DWORD2(v4);
      v9 = DWORD1(v4);
      v10 = v4;
      v43 = HIDWORD(v51[0]);
      v11 = v51[0];
      v37 = v51[0];
      while ( 1 )
      {
        v45 = __ROL4__(v10 + v11, 7) ^ v6;
        v34 = __ROL4__(v45 + v37, 9) ^ v33;
        v49 = __ROL4__(v45 + v34, 13) ^ v10;
        v38 = __ROR4__(v49 + v34, 14) ^ v37;
        v32 = __ROL4__(v43 + v39, 7) ^ v31;
        v12 = __ROL4__(v39 + v32, 9) ^ v9;
        v44 = __ROL4__(v12 + v32, 13) ^ v43;
        v40 = __ROR4__(v44 + v12, 14) ^ v39;
        v13 = __ROL4__(v41 + v30, 7) ^ v8;
        v36 = __ROL4__(v13 + v41, 9) ^ v35;
        LODWORD(v30) = __ROL4__(v13 + v36, 13) ^ v30;
        v29 = __ROL4__(v5 + v7, 7) ^ v28;
        v42 = __ROR4__(v36 + v30, 14) ^ v41;
        HIDWORD(v30) ^= __ROL4__(v7 + v29, 9);
        v14 = __ROL4__(v29 + HIDWORD(v30), 13) ^ v5;
        v15 = __ROR4__(v14 + HIDWORD(v30), 14) ^ v7;
        v43 = __ROL4__(v38 + v29, 7) ^ v44;
        v35 = __ROL4__(v43 + v38, 9) ^ v36;
        LODWORD(v51[1]) = v35;
        v28 = __ROL4__(v35 + v43, 13) ^ v29;
        HIDWORD(v51[1]) = v28;
        LODWORD(v30) = __ROL4__(v40 + v45, 7) ^ v30;
        HIDWORD(v30) ^= __ROL4__(v40 + v30, 9);
        v52[1] = v30;
        v37 = __ROR4__(v35 + v28, 14) ^ v38;
        v46 = __ROL4__(v30 + HIDWORD(v30), 13) ^ v45;
        LODWORD(v52[0]) = v46;
        v51[0] = __PAIR64__(v43, v37);
        v39 = __ROR4__(v46 + HIDWORD(v30), 14) ^ v40;
        v5 = __ROL4__(v42 + v32, 7) ^ v14;
        HIDWORD(v52[0]) = v39;
        v33 = __ROL4__(v5 + v42, 9) ^ v34;
        LODWORD(v53) = v33;
        v31 = __ROL4__(v5 + v33, 13) ^ v32;
        DWORD1(v53) = v31;
        v10 = __ROL4__(v13 + v15, 7) ^ v49;
        v41 = __ROR4__(v33 + v31, 14) ^ v42;
        DWORD2(v53) = v41;
        LODWORD(v54) = v10;
        v9 = __ROL4__(v10 + v15, 9) ^ v12;
        v8 = __ROL4__(v10 + v9, 13) ^ v13;
        v7 = __ROR4__(v8 + v9, 14) ^ v15;
        v16 = v48-- == 1;
        v11 = v37;
        if ( v16 )
          break;
        v6 = v46;
      }
      v3 = (_OWORD *)a3;
      v17 = 0;
      v18 = a2;
      HIDWORD(v53) = v5;
      *((_QWORD *)&v54 + 1) = __PAIR64__(v7, v8);
      DWORD1(v54) = v9;
      if ( (unsigned int)v51 > v50 || (unsigned int)&v54 + 12 < a3 )
      {
        do
        {
          *(__m128i *)((char *)v51 + 4 * v17) = _mm_add_epi32(
                                                  *(__m128i *)((char *)v51 + 4 * v17),
                                                  *(__m128i *)(a3 + 4 * v17));
          *(__m128i *)((char *)v52 + 4 * v17) = _mm_add_epi32(
                                                  *(__m128i *)(a3 + 4 * v17 + 16),
                                                  *(__m128i *)((char *)v52 + 4 * v17));
          v17 += 8;
        }
        while ( v17 < 16 );
      }
      else
      {
        do
        {
          *((_DWORD *)v51 + v17) += *(_DWORD *)(a3 + 4 * v17);
          ++v17;
        }
        while ( v17 < 16 );
      }
      v19 = __CFADD__((*(_DWORD *)(a3 + 32))++, 1);
      v20 = a1;
      *(_DWORD *)(a3 + 36) += v19;
      if ( a1 > 0x40 )
        v20 = 64;
      v21 = 0;
      if ( v20 >= 0x20
        && (a2 > (__m128i *)((char *)&v50 + v20 + 3) || (char *)&a2[-1].m128i_u64[1] + v20 + 7 < (char *)v51) )
      {
        v22 = a2;
        v18 = a2;
        do
        {
          v23 = *v22;
          v21 += 32;
          v22 += 2;
          v22[-2] = _mm_xor_si128(*(__m128i *)((char *)v22 + (char *)v51 - (char *)a2 - 32), v23);
          v22[-1] = _mm_xor_si128(*(__m128i *)((char *)v22 + (char *)v52 - (char *)a2 - 32), v22[-1]);
        }
        while ( v21 < (v20 & 0xFFFFFFE0) );
        v3 = (_OWORD *)a3;
      }
      if ( v21 < v20 )
      {
        v24 = &v18[v21 / 0x10];
        v25 = (char *)((char *)v51 - (char *)v18);
        v26 = v20 - v21;
        do
        {
          v27 = v25[(_DWORD)v24];
          v24 = (__m128i *)((char *)v24 + 1);
          v24[-1].m128i_i8[15] ^= v27;
          --v26;
        }
        while ( v26 != 0 );
        v18 = a2;
      }
      a2 = (__m128i *)((char *)v18 + v20);
      a1 -= v20;
    }
    while ( a1 != 0 );
  }
}


/* sub_404D18 @ 00404D18 */
unsigned int __stdcall sub_404D18(unsigned int *a1, unsigned int a2)
{
  _DWORD *v2; // edi
  unsigned __int32 v3; // ebx
  unsigned __int32 v4; // ecx
  unsigned __int32 v5; // edx
  unsigned __int32 v6; // ebx
  unsigned __int32 v7; // edx
  unsigned int result; // eax
  int v9; // esi
  unsigned int v10; // eax
  int v11; // eax
  int v12; // eax
  unsigned int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  int v18; // eax
  int v19; // eax
  unsigned int v20; // eax
  int v21; // eax
  int v22; // eax
  unsigned int v23; // ecx
  unsigned int v24; // ebx
  int *v25; // edi
  int v26; // edx
  int v27; // edx
  int v28; // edx
  int v29; // edx
  int i; // esi

  v2 = dword_4251F4;
  v3 = _byteswap_ulong(a1[1]);
  v4 = _byteswap_ulong(a1[2]);
  v5 = _byteswap_ulong(a1[3]);
  dword_4251F4[0] = _byteswap_ulong(*a1);
  dword_4251F4[1] = v3;
  dword_4251F4[2] = v4;
  dword_4251F4[3] = v5;
  if ( a2 >= 0x18 )
  {
    v6 = _byteswap_ulong(a1[5]);
    dword_4251F4[4] = _byteswap_ulong(a1[4]);
    dword_4251F4[5] = v6;
    if ( a2 >= 0x20 )
    {
      v7 = _byteswap_ulong(a1[7]);
      dword_4251F4[6] = _byteswap_ulong(a1[6]);
      dword_4251F4[7] = v7;
    }
  }
  result = a2;
  v9 = 0;
  switch ( a2 )
  {
    case 0x10u:
      while ( 1 )
      {
        v10 = *v2
            ^ dword_404CF0[v9]
            ^ (unsigned __int8)dword_4034F0[HIBYTE(v2[3])]
            ^ dword_4034F0[(unsigned __int8)v2[3]]
            & 0xFF00
            ^ dword_4034F0[(unsigned __int8)BYTE1(v2[3])]
            & 0xFF0000
            ^ dword_4034F0[(unsigned __int8)BYTE2(v2[3])]
            & 0xFF000000;
        v2[4] = v10;
        v11 = v2[1] ^ v10;
        v2[5] = v11;
        v12 = v2[2] ^ v11;
        v2[6] = v12;
        result = v2[3] ^ v12;
        v2[7] = result;
        if ( ++v9 == 10 )
          break;
        v2 += 4;
      }
      break;
    case 0x18u:
      while ( 1 )
      {
        v13 = *v2
            ^ dword_404CF0[v9]
            ^ (unsigned __int8)dword_4034F0[HIBYTE(v2[5])]
            ^ dword_4034F0[(unsigned __int8)v2[5]]
            & 0xFF00
            ^ dword_4034F0[(unsigned __int8)BYTE1(v2[5])]
            & 0xFF0000
            ^ dword_4034F0[(unsigned __int8)BYTE2(v2[5])]
            & 0xFF000000;
        v2[6] = v13;
        v14 = v2[1] ^ v13;
        v2[7] = v14;
        v15 = v2[2] ^ v14;
        v2[8] = v15;
        result = v2[3] ^ v15;
        v2[9] = result;
        if ( ++v9 == 8 )
          break;
        v16 = v2[4] ^ result;
        v2[10] = v16;
        v2[11] = v2[5] ^ v16;
        v2 += 6;
      }
      v9 = 12;
      break;
    case 0x20u:
      while ( 1 )
      {
        v17 = *v2
            ^ dword_404CF0[v9]
            ^ (unsigned __int8)dword_4034F0[HIBYTE(v2[7])]
            ^ dword_4034F0[(unsigned __int8)v2[7]]
            & 0xFF00
            ^ dword_4034F0[(unsigned __int8)BYTE1(v2[7])]
            & 0xFF0000
            ^ dword_4034F0[(unsigned __int8)BYTE2(v2[7])]
            & 0xFF000000;
        v2[8] = v17;
        v18 = v2[1] ^ v17;
        v2[9] = v18;
        v19 = v2[2] ^ v18;
        v2[10] = v19;
        result = v2[3] ^ v19;
        v2[11] = result;
        if ( ++v9 == 7 )
          break;
        v20 = v2[4]
            ^ (unsigned __int8)dword_4034F0[(unsigned __int8)result]
            ^ dword_4034F0[BYTE1(result)]
            & 0xFF00
            ^ dword_4034F0[BYTE2(result)]
            & 0xFF0000
            ^ dword_4034F0[HIBYTE(result)]
            & 0xFF000000;
        v2[12] = v20;
        v21 = v2[5] ^ v20;
        v2[13] = v21;
        v22 = v2[6] ^ v21;
        v2[14] = v22;
        v2[15] = v2[7] ^ v22;
        v2 += 8;
      }
      v9 = 14;
      break;
    default:
      break;
  }
  dword_4253F4 = v9;
  v23 = 0;
  v24 = 4 * v9;
  v25 = dword_4252F4;
  while ( v23 <= v24 )
  {
    v26 = dword_4251F4[v23 + 1];
    dword_4252F4[v24] = dword_4251F4[v23];
    dword_4252F4[v24 + 1] = v26;
    v27 = dword_4251F4[v23 + 3];
    dword_4252F4[v24 + 2] = dword_4251F4[v23 + 2];
    dword_4252F4[v24 + 3] = v27;
    v28 = dword_4251F4[v24 + 1];
    dword_4252F4[v23] = dword_4251F4[v24];
    dword_4252F4[v23 + 1] = v28;
    result = dword_4251F4[v24 + 2];
    v29 = dword_4251F4[v24 + 3];
    dword_4252F4[v23 + 2] = result;
    dword_4252F4[v23 + 3] = v29;
    v23 += 4;
    v24 -= 4;
  }
  for ( i = dword_4253F4 - 1; i != 0; --i )
  {
    v25 += 4;
    *v25 = dword_4044F0[(unsigned __int8)dword_4034F0[(unsigned __int8)*v25]]
         ^ dword_4040F0[(unsigned __int8)dword_4034F0[(unsigned __int8)BYTE1(*v25)]]
         ^ dword_403CF0[(unsigned __int8)dword_4034F0[(unsigned __int8)BYTE2(*v25)]]
         ^ dword_4038F0[(unsigned __int8)dword_4034F0[HIBYTE(*v25)]];
    v25[1] = dword_4044F0[(unsigned __int8)dword_4034F0[(unsigned __int8)v25[1]]]
           ^ dword_4040F0[(unsigned __int8)dword_4034F0[(unsigned __int8)BYTE1(v25[1])]]
           ^ dword_403CF0[(unsigned __int8)dword_4034F0[(unsigned __int8)BYTE2(v25[1])]]
           ^ dword_4038F0[(unsigned __int8)dword_4034F0[HIBYTE(v25[1])]];
    v25[2] = dword_4044F0[(unsigned __int8)dword_4034F0[(unsigned __int8)v25[2]]]
           ^ dword_4040F0[(unsigned __int8)dword_4034F0[(unsigned __int8)BYTE1(v25[2])]]
           ^ dword_403CF0[(unsigned __int8)dword_4034F0[(unsigned __int8)BYTE2(v25[2])]]
           ^ dword_4038F0[(unsigned __int8)dword_4034F0[HIBYTE(v25[2])]];
    result = dword_4044F0[(unsigned __int8)dword_4034F0[(unsigned __int8)v25[3]]]
           ^ dword_4040F0[(unsigned __int8)dword_4034F0[(unsigned __int8)BYTE1(v25[3])]]
           ^ dword_403CF0[(unsigned __int8)dword_4034F0[(unsigned __int8)BYTE2(v25[3])]]
           ^ dword_4038F0[(unsigned __int8)dword_4034F0[HIBYTE(v25[3])]];
    v25[3] = result;
  }
  return result;
}


/* sub_405228 @ 00405228 */
unsigned __int32 __stdcall sub_405228(unsigned int *a1, _DWORD *a2)
{
  _DWORD *v2; // edi
  unsigned int v3; // esi
  unsigned __int32 result; // eax
  unsigned int v5; // [esp+Ch] [ebp-20h]
  unsigned int v6; // [esp+10h] [ebp-1Ch]
  unsigned int v7; // [esp+14h] [ebp-18h]
  unsigned int v8; // [esp+18h] [ebp-14h]
  unsigned __int32 v9; // [esp+1Ch] [ebp-10h]
  unsigned __int32 v10; // [esp+20h] [ebp-Ch]
  unsigned __int32 v11; // [esp+24h] [ebp-8h]
  unsigned __int32 v12; // [esp+28h] [ebp-4h]

  v2 = dword_4251F4;
  v12 = dword_4251F4[0] ^ _byteswap_ulong(*a1);
  v11 = dword_4251F4[1] ^ _byteswap_ulong(a1[1]);
  v10 = dword_4251F4[2] ^ _byteswap_ulong(a1[2]);
  v9 = dword_4251F4[3] ^ _byteswap_ulong(a1[3]);
  v3 = (unsigned int)dword_4253F4 >> 1;
  while ( 1 )
  {
    v8 = v2[4]
       ^ dword_4030F0[(unsigned __int8)v9]
       ^ dword_402CF0[BYTE1(v10)]
       ^ dword_4028F0[BYTE2(v11)]
       ^ dword_4024F0[HIBYTE(v12)];
    v7 = v2[5]
       ^ dword_4030F0[(unsigned __int8)v12]
       ^ dword_402CF0[BYTE1(v9)]
       ^ dword_4028F0[BYTE2(v10)]
       ^ dword_4024F0[HIBYTE(v11)];
    v6 = v2[6]
       ^ dword_4030F0[(unsigned __int8)v11]
       ^ dword_402CF0[BYTE1(v12)]
       ^ dword_4028F0[BYTE2(v9)]
       ^ dword_4024F0[HIBYTE(v10)];
    v5 = v2[7]
       ^ dword_4030F0[(unsigned __int8)v10]
       ^ dword_402CF0[BYTE1(v11)]
       ^ dword_4028F0[BYTE2(v12)]
       ^ dword_4024F0[HIBYTE(v9)];
    v2 += 8;
    if ( --v3 == 0 )
      break;
    v12 = *v2
        ^ dword_4030F0[(unsigned __int8)v5]
        ^ dword_402CF0[BYTE1(v6)]
        ^ dword_4028F0[BYTE2(v7)]
        ^ dword_4024F0[HIBYTE(v8)];
    v11 = v2[1]
        ^ dword_4030F0[(unsigned __int8)v8]
        ^ dword_402CF0[BYTE1(v5)]
        ^ dword_4028F0[BYTE2(v6)]
        ^ dword_4024F0[HIBYTE(v7)];
    v10 = v2[2]
        ^ dword_4030F0[(unsigned __int8)v7]
        ^ dword_402CF0[BYTE1(v8)]
        ^ dword_4028F0[BYTE2(v5)]
        ^ dword_4024F0[HIBYTE(v6)];
    v9 = v2[3]
       ^ dword_4030F0[(unsigned __int8)v6]
       ^ dword_402CF0[BYTE1(v7)]
       ^ dword_4028F0[BYTE2(v8)]
       ^ dword_4024F0[HIBYTE(v5)];
  }
  *a2 = _byteswap_ulong(
          *v2
        ^ (unsigned __int8)dword_4034F0[(unsigned __int8)v5]
        ^ dword_4034F0[BYTE1(v6)]
        & 0xFF00
        ^ dword_4034F0[BYTE2(v7)]
        & 0xFF0000
        ^ dword_4034F0[HIBYTE(v8)]
        & 0xFF000000);
  a2[1] = _byteswap_ulong(
            v2[1]
          ^ (unsigned __int8)dword_4034F0[(unsigned __int8)v8]
          ^ dword_4034F0[BYTE1(v5)]
          & 0xFF00
          ^ dword_4034F0[BYTE2(v6)]
          & 0xFF0000
          ^ dword_4034F0[HIBYTE(v7)]
          & 0xFF000000);
  a2[2] = _byteswap_ulong(
            v2[2]
          ^ (unsigned __int8)dword_4034F0[(unsigned __int8)v7]
          ^ dword_4034F0[BYTE1(v8)]
          & 0xFF00
          ^ dword_4034F0[BYTE2(v5)]
          & 0xFF0000
          ^ dword_4034F0[HIBYTE(v6)]
          & 0xFF000000);
  result = _byteswap_ulong(
             v2[3]
           ^ (unsigned __int8)dword_4034F0[(unsigned __int8)v6]
           ^ dword_4034F0[BYTE1(v7)]
           & 0xFF00
           ^ dword_4034F0[BYTE2(v8)]
           & 0xFF0000
           ^ dword_4034F0[HIBYTE(v5)]
           & 0xFF000000);
  a2[3] = result;
  return result;
}


/* sub_4056A0 @ 004056A0 */
unsigned int __stdcall sub_4056A0(unsigned int *a1, unsigned int a2, unsigned int *a3, int a4)
{
  unsigned int v4; // ebx
  unsigned int *v5; // edi

  sub_404D18(a1, a2);
  memset((char *)a3 + a4, ((a4 + 15) & 0xF0) + 16 - a4, ((a4 + 15) & 0xFFFFFFF0) + 16 - a4);
  v4 = (((a4 + 15) & 0xFFFFFFF0) + 16) >> 4;
  v5 = a3;
  do
  {
    sub_405228(v5, v5);
    v5 += 4;
    --v4;
  }
  while ( v4 != 0 );
  return ((a4 + 15) & 0xFFFFFFF0) + 16;
}


/* sub_4056F0 @ 004056F0 */
// attributes: thunk
int sub_4056F0()
{
  return dword_425198();
}


/* sub_4056F8 @ 004056F8 */
// attributes: thunk
int __stdcall sub_4056F8(int a1, int a2)
{
  return dword_425194(a1, a2);
}


/* sub_405700 @ 00405700 */
int __stdcall sub_405700(int a1, _WORD *a2)
{
  _WORD *v2; // edi
  int v3; // ecx
  int result; // eax
  bool v5; // zf
  unsigned int v6; // ecx
  __int16 v7; // cx

  v2 = a2;
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = a2;
  if ( a2 != nullptr )
  {
    v3 = -1;
    result = 0;
    do
    {
      if ( v3 == 0 )
        break;
      v5 = *v2++ == 0;
      --v3;
    }
    while ( !v5 );
    v6 = ~v3;
    if ( v6 > 0xFFFF )
      LOWORD(v6) = -1;
    v7 = 2 * v6;
    *(_WORD *)(a1 + 2) = v7;
    *(_WORD *)a1 = v7 - 2;
  }
  return result;
}


/* sub_405744 @ 00405744 */
int __stdcall sub_405744(int a1, const char *a2)
{
  int result; // eax
  unsigned int v3; // ecx

  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = a2;
  if ( a2 != nullptr )
  {
    result = 0;
    v3 = strlen(a2) + 1;
    if ( v3 > 0xFFFF )
      LOWORD(v3) = -1;
    *(_WORD *)(a1 + 2) = v3;
    *(_WORD *)a1 = v3 - 1;
  }
  return result;
}


/* sub_405784 @ 00405784 */
int __stdcall sub_405784(unsigned __int8 a1)
{
  return asc_4057A0[a1] & 0x157;
}


/* sub_4059A0 @ 004059A0 */
int __stdcall sub_4059A0(const char *a1)
{
  int v1; // ebx
  unsigned __int8 *v2; // edi
  unsigned int v3; // esi

  v1 = 0;
  v2 = (unsigned __int8 *)a1;
  v3 = strlen(a1);
  if ( v3 > 5 )
  {
    do
    {
      if ( sub_405784(*v2) == 0 )
        break;
      ++v2;
      --v3;
    }
    while ( v3 != 0 );
    if ( v3 == 0 )
      return 1;
  }
  return v1;
}


/* sub_4059E4 @ 004059E4 */
int __stdcall sub_4059E4(int a1, const char *a2)
{
  _BYTE v3[8]; // [esp+0h] [ebp-Ch] BYREF
  int v4; // [esp+8h] [ebp-4h] BYREF

  if ( (unsigned int)a2 <= 0xFFFF )
  {
    dword_4253FC(a1, 0, a2, &v4);
  }
  else
  {
    sub_405744((int)v3, a2);
    dword_4253FC(a1, v3, 0, &v4);
  }
  return v4;
}


/* sub_405A30 @ 00405A30 */
int __stdcall sub_405A30(_WORD *a1, int a2)
{
  __int16 v2; // ax
  _BYTE *v3; // esi
  _WORD *v4; // edi
  _WORD v6[260]; // [esp+Ch] [ebp-214h] BYREF
  _BYTE v7[8]; // [esp+214h] [ebp-Ch] BYREF
  int v8; // [esp+21Ch] [ebp-4h] BYREF

  HIBYTE(v2) = 0;
  v8 = 0;
  if ( a2 != 0 )
  {
    sub_405700((int)v7, a1);
  }
  else
  {
    v3 = a1;
    v4 = v6;
    do
    {
      LOBYTE(v2) = *v3++;
      *v4++ = v2;
    }
    while ( (_BYTE)v2 != 0 );
    sub_405700((int)v7, v6);
  }
  dword_4253F8(0, 0, v7, &v8);
  return v8;
}


/* sub_405A94 @ 00405A94 */
int __thiscall sub_405A94(void *this, _BYTE *a2)
{
  _BYTE *v2; // edi
  int v3; // ecx
  bool v4; // zf
  unsigned int v5; // ecx
  char *v6; // esi
  int result; // eax
  char *v8; // esi
  char *v9; // edi
  char v10; // cl
  char v11; // [esp-1h] [ebp-81h]
  char v12[128]; // [esp+0h] [ebp-80h] BYREF

  v11 = HIBYTE(this);
  v2 = a2;
  v3 = -1;
  do
  {
    if ( v3 == 0 )
      break;
    v4 = *v2++ == 46;
    --v3;
  }
  while ( !v4 );
  v5 = -v3 - 2;
  qmemcpy(v12, a2, v5);
  v6 = &a2[v5];
  v12[v5] = 0;
  result = 0;
  if ( dword_4253F8 != nullptr && dword_4253FC != nullptr )
  {
    result = sub_405A30(v12, 0);
    if ( result != 0 )
    {
      v8 = v6 + 1;
      v9 = v12;
      do
      {
        v10 = *v8;
        *v9++ = *v8++;
      }
      while ( v10 != 0 );
      return sub_4059E4(result, v12);
    }
  }
  return result;
}


/* sub_405AFC @ 00405AFC */
int __stdcall sub_405AFC(int a1)
{
  __m64 v1; // mm0
  struct _LIST_ENTRY *Flink; // ecx
  struct _LIST_ENTRY *v3; // ebx
  __int64 v4; // rax
  __m64 v5; // mm1
  _DWORD *v6; // edx
  int *v7; // esi
  unsigned __int16 *v8; // edi
  int v9; // eax
  int v10; // edx
  unsigned int v11; // eax
  struct _LIST_ENTRY *p_InLoadOrderModuleList; // [esp+Ch] [ebp-8h]
  int v14; // [esp+10h] [ebp-4h]

  if ( dword_4253F8 == 0 )
  {
    dword_4253F8 = 1855194865;
    dword_4253F8 = sub_405AFC(1855194865);
  }
  if ( dword_4253FC == 0 )
  {
    dword_4253FC = 388451637;
    dword_4253FC = sub_405AFC(388451637);
  }
  v1.m64_u64 = 0;
  p_InLoadOrderModuleList = &NtCurrentPeb()->Ldr->InLoadOrderModuleList;
  Flink = p_InLoadOrderModuleList->Flink;
  do
  {
    v3 = Flink[3].Flink;
    if ( *(struct _LIST_ENTRY **)((char *)&v3[15].Flink + (unsigned int)v3[7].Blink) != nullptr )
    {
      v4 = sub_4011D4(Flink[6].Flink, 0);
      v5 = _mm_cvtsi32_si64(v4);
      v6 = (struct _LIST_ENTRY **)((char *)&v3->Flink + HIDWORD(v4));
      if ( v6[6] != 0 )
      {
        v14 = v6[6];
        v7 = (int *)((char *)v3 + v6[8]);
        v8 = (unsigned __int16 *)((char *)v3 + v6[9]);
        while ( 1 )
        {
          v9 = *v7++;
          if ( sub_401190((char *)v3 + v9, _mm_cvtsi64_si32(v5)) == a1 )
            break;
          ++v8;
          if ( --v14 == 0 )
            goto LABEL_14;
        }
        v11 = *(unsigned int *)((char *)&v3->Flink + 4 * *v8 + *(_DWORD *)(v10 + 28)) + (unsigned int)v3;
        v1 = _mm_cvtsi32_si64(v11);
        if ( sub_4059A0(v11) != 0 )
          v1 = _mm_cvtsi32_si64(sub_405A94(_mm_cvtsi64_si32(v1)));
      }
LABEL_14:
      if ( _mm_cvtsi64_si32(v1) != 0 )
        break;
    }
    Flink = Flink->Flink;
  }
  while ( p_InLoadOrderModuleList != Flink );
  return _mm_cvtsi64_si32(v1);
}


/* sub_405C34 @ 00405C34 */
int __stdcall sub_405C34(int a1)
{
  int *v1; // ebx
  int *j; // ebx
  _BYTE v4[128]; // [esp+4h] [ebp-2D8h] BYREF
  _BYTE v5[44]; // [esp+84h] [ebp-258h] BYREF
  _BYTE v6[548]; // [esp+B0h] [ebp-22Ch] BYREF
  int v7; // [esp+2D4h] [ebp-8h]
  int i; // [esp+2D8h] [ebp-4h]

  if ( dword_425400 == nullptr )
  {
    dword_425400 = (int (__stdcall *)(_DWORD, _DWORD))-635785566;
    dword_425400 = (int (__stdcall *)(_DWORD, _DWORD))sub_405AFC(-635785566);
  }
  if ( dword_425404 == nullptr )
  {
    dword_425404 = (int (__stdcall *)(_DWORD, _DWORD))1466616277;
    dword_425404 = (int (__stdcall *)(_DWORD, _DWORD))sub_405AFC(1466616277);
  }
  if ( dword_425408 == nullptr )
  {
    dword_425408 = (int (__stdcall *)(_DWORD))2017475196;
    dword_425408 = (int (__stdcall *)(_DWORD))sub_405AFC(2017475196);
  }
  v1 = (int *)v4;
  sub_401668(v4);
  while ( *(_WORD *)v1 != 0 )
    v1 = (int *)((char *)v1 + 2);
  *v1 = -1210695580;
  v1[1] = -1214758890;
  v1[2] = -1215283116;
  v1[3] = -1208205256;
  sub_401250(v1, 4);
  for ( i = 0; ; ++i )
  {
    v7 = dword_425400(v4, v5);
    if ( v7 != -1 )
    {
      do
      {
        if ( (unsigned int)sub_4011D4(v6, 0) == a1 )
        {
          dword_425408(v7);
          return sub_405A30(v6, 1);
        }
      }
      while ( dword_425404(v7, v5) != 0 );
      dword_425408(v7);
    }
    if ( i != 0 )
      break;
    for ( j = (int *)v4; *((_WORD *)j - 1) != 46; j = (int *)((char *)j + 2) )
      ;
    *j = -1215414180;
    j[1] = -1208205234;
    sub_401250(j, 2);
  }
  return 0;
}


/* sub_405DB0 @ 00405DB0 */
int __stdcall sub_405DB0(int a1, _DWORD *a2, int a3, int (__stdcall *a4)(int, _DWORD, int))
{
  int *v4; // esi
  int result; // eax
  _DWORD *v6; // edi
  int v7; // ebx
  _BYTE *v8; // eax
  unsigned int v9; // eax
  int v10; // edx
  char v11; // al
  int v12; // edx
  char v13; // al
  int v14; // edx
  char v15; // al
  int v16; // edx
  char v17; // al
  int v18; // edx

  v4 = a2 + 1;
  result = sub_405C34(*a2 ^ 0x4803BFC7);
  if ( result != 0 )
  {
    v6 = (_DWORD *)(a1 + 4);
    while ( 1 )
    {
      result = *v4++;
      if ( result == -858993460 )
        break;
      v7 = sub_405AFC(result ^ 0x4803BFC7);
      v8 = (_BYTE *)a4(a3, 0, 16);
      *v6++ = v8;
      *v8 = -72;
      v9 = sub_401124(0, 4u);
      if ( v9 != 0 )
      {
        switch ( v9 )
        {
          case 1u:
            v13 = sub_401124(1u, 9u);
            *(_DWORD *)(v14 + 1) = __ROR4__(v7, v13);
            *(_WORD *)(v14 + 5) = -16191;
            *(_BYTE *)(v14 + 7) = v13;
            *(_WORD *)(v14 + 8) = -7937;
            break;
          case 2u:
            *(_DWORD *)(v10 + 1) = v7 ^ 0x4803BFC7;
            *(_BYTE *)(v10 + 5) = 53;
            *(_DWORD *)(v10 + 6) = 1208205255;
            *(_WORD *)(v10 + 10) = -7937;
            break;
          case 3u:
            v15 = sub_401124(1u, 9u);
            *(_DWORD *)(v16 + 1) = __ROL4__(v7 ^ 0x4803BFC7, v15);
            *(_WORD *)(v16 + 5) = -14143;
            *(_BYTE *)(v16 + 7) = v15;
            *(_BYTE *)(v16 + 8) = 53;
            *(_DWORD *)(v16 + 9) = 1208205255;
            *(_WORD *)(v16 + 13) = -7937;
            break;
          case 4u:
            v17 = sub_401124(1u, 9u);
            *(_DWORD *)(v18 + 1) = __ROR4__(v7 ^ 0x4803BFC7, v17);
            *(_WORD *)(v18 + 5) = -16191;
            *(_BYTE *)(v18 + 7) = v17;
            *(_BYTE *)(v18 + 8) = 53;
            *(_DWORD *)(v18 + 9) = 1208205255;
            *(_WORD *)(v18 + 13) = -7937;
            break;
          default:
            break;
        }
      }
      else
      {
        v11 = sub_401124(1u, 9u);
        *(_DWORD *)(v12 + 1) = __ROL4__(v7, v11);
        *(_WORD *)(v12 + 5) = -14143;
        *(_BYTE *)(v12 + 7) = v11;
        *(_WORD *)(v12 + 8) = -7937;
      }
    }
  }
  return result;
}


/* sub_40639C @ 0040639C */
int (__stdcall *sub_40639C())(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD)
{
  int (__stdcall *result)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // eax
  int (__stdcall *v1)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // esi
  int (__stdcall *v2)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // edi

  result = (int (__stdcall *)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))sub_405AFC(-133228312);
  if ( result != nullptr )
  {
    result = (int (__stdcall *)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))result(266242, 0, 0, 0, 0, 0);
    v1 = result;
    if ( result != nullptr )
    {
      result = (int (__stdcall *)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))sub_405AFC(1851803611);
      v2 = result;
      if ( result != nullptr )
      {
        sub_405DB0(&unk_42540C, dword_405EE8, v1, result);
        sub_405DB0(&unk_4254FC, dword_405FDC, v1, v2);
        sub_405DB0(&unk_4255EC, dword_4060D0, v1, v2);
        sub_405DB0(&unk_42568C, byte_406174, v1, v2);
        sub_405DB0(&unk_42569C, dword_406188, v1, v2);
        sub_405DB0(&unk_4256D4, dword_4061C4, v1, v2);
        sub_405DB0(&unk_425728, dword_40621C, v1, v2);
        sub_405DB0(&unk_42573C, dword_406234, v1, v2);
        sub_405DB0(&unk_425764, dword_406260, v1, v2);
        sub_405DB0(&unk_42579C, dword_40629C, v1, v2);
        sub_405DB0(&unk_4257B0, dword_4062B4, v1, v2);
        sub_405DB0(&unk_4257B8, dword_4062C0, v1, v2);
        sub_405DB0(&unk_4257CC, dword_4062D8, v1, v2);
        sub_405DB0(&unk_4257F8, dword_406308, v1, v2);
        sub_405DB0(&unk_425810, dword_406324, v1, v2);
        sub_405DB0(&unk_42583C, dword_406354, v1, v2);
        sub_405DB0(&unk_42584C, dword_406368, v1, v2);
        sub_405DB0(&unk_425858, dword_406378, v1, v2);
        sub_405DB0(&unk_42586C, dword_406390, v1, v2);
        sub_40B414(0);
        sub_417694(v1, v2);
        return (int (__stdcall *)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))sub_40B41C();
      }
    }
  }
  return result;
}


/* sub_406544 @ 00406544 */
int __stdcall sub_406544(int a1, _DWORD *a2)
{
  int v2; // ebx
  __int16 v3; // si
  __int16 *v4; // eax
  int result; // eax
  int v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]

  v6 = 0;
  v7 = sub_4068FC(a1, 0);
  if ( v7 != 0 )
  {
    v6 = sub_4068FC(a1, 0);
    if ( v6 != 0 )
    {
      v2 = 26;
      v3 = 65;
      do
      {
        v4 = (__int16 *)(dword_425450(v6, 92) + 2);
        do
          *v4++ = v3;
        while ( *v4 != 0 );
        if ( dword_425518(v7, v6, 8) == 0 )
          break;
        dword_425444(v7, v6);
        ++v3;
        --v2;
      }
      while ( v2 != 0 );
    }
  }
  result = (int)a2;
  *a2 = v7;
  if ( v6 != 0 )
    return sub_40684C(v6);
  return result;
}


/* sub_406614 @ 00406614 */
int __stdcall sub_406614(int *a1, unsigned int a2)
{
  unsigned int v2; // ebx
  unsigned int v3; // esi
  int v5; // edx
  int *v6; // edi
  int result; // eax

  v2 = a2 / 8;
  v3 = a2 % 8;
  do
  {
    *a1 = sub_4010D4();
    v6 = a1 + 1;
    result = v5;
    *v6 = v5;
    a1 = v6 + 1;
    --v2;
  }
  while ( v2 != 0 );
  for ( ; v3 != 0; --v3 )
  {
    result = sub_4010D4();
    *(_BYTE *)a1 = result;
    a1 = (int *)((char *)a1 + 1);
  }
  return result;
}


/* sub_406654 @ 00406654 */
int __stdcall sub_406654(int a1)
{
  int v1; // ebx
  _DWORD *v2; // edi
  int v3; // ebx
  _DWORD *v4; // edi
  int v5; // ebx
  int *v6; // esi
  int v7; // eax
  int v8; // ebx
  int *v9; // esi
  int v10; // eax
  _BYTE v12[12]; // [esp+Ch] [ebp-34h] BYREF
  int v13; // [esp+18h] [ebp-28h] BYREF
  __int64 v14; // [esp+1Ch] [ebp-24h] BYREF
  __int64 i; // [esp+24h] [ebp-1Ch]
  unsigned int v16; // [esp+2Ch] [ebp-14h] BYREF
  int v17; // [esp+30h] [ebp-10h] BYREF
  int v18; // [esp+34h] [ebp-Ch]
  int v19; // [esp+38h] [ebp-8h]
  int v20; // [esp+3Ch] [ebp-4h]

  v20 = 0;
  v13 = 0;
  v1 = 0;
  v2 = v12;
  do
  {
    *v2++ = 0;
    ++v1;
  }
  while ( v1 != 3 );
  v19 = -1;
  sub_40A064(a1, &v14);
  if ( v14 != 0 )
  {
    v19 = dword_425528(a1, 0x40000000, 3, 0, 3, 0x80000000, 0);
    if ( v19 != -1 )
    {
      v3 = 0;
      v4 = v12;
      do
      {
        v16 = 0x10000;
        v17 = 0;
        if ( dword_4254E4(-1, &v17, 0, &v16, 4096, 4) != 0 )
          break;
        *v4++ = v17;
        if ( v3 == 1 )
        {
          memset((void *)*(v4 - 1), 0xFFu, 0x10000u);
        }
        else if ( v3 == 2 )
        {
          sub_406614((int *)*(v4 - 1), 0x10000u);
        }
        ++v3;
      }
      while ( v3 != 3 );
      for ( i = 0; ; dword_425544(v19, i, HIDWORD(i), 0, 0) )
      {
        v14 -= 0x10000;
        if ( v14 >= 0 )
        {
          v5 = 0x10000;
        }
        else
        {
          LODWORD(v14) = v14 + 0x10000;
          v5 = v14;
        }
        v18 = 3;
        v6 = (int *)v12;
        do
        {
          v7 = *v6++;
          if ( dword_42552C(v19, v7, v5, &v16, 0) == 0 )
            break;
          dword_425544(v19, -v5, -1, 0, 1);
          --v18;
        }
        while ( v18 != 0 );
        if ( v16 < 0x10000 )
          break;
        i += 0x10000;
      }
    }
  }
  v8 = 0;
  v9 = (int *)v12;
  do
  {
    v10 = *v9++;
    if ( v10 != 0 )
    {
      v17 = v10;
      v16 = 0x10000;
      dword_4254E8(-1, &v17, &v16, 0x8000);
    }
    ++v8;
  }
  while ( v8 != 3 );
  if ( v19 != -1 )
    dword_4254D0(v19);
  sub_406544(a1, &v13);
  if ( dword_425570(v13) != 0 )
    v20 = 1;
  if ( v13 != 0 )
    sub_40684C(v13);
  return v20;
}


/* sub_406830 @ 00406830 */
int __stdcall sub_406830(int a1)
{
  int v1; // eax

  v1 = sub_4010AC();
  return dword_425418(*(_DWORD *)(v1 + 24), 8, a1);
}


/* sub_40684C @ 0040684C */
int __stdcall sub_40684C(int a1)
{
  int v1; // eax

  v1 = sub_4010AC();
  return dword_425420(*(_DWORD *)(v1 + 24), 0, a1);
}


/* sub_406868 @ 00406868 */
int __stdcall sub_406868(int a1, int a2)
{
  struct _PEB *v2; // eax

  v2 = sub_4010AC();
  return dword_42541C(v2->ProcessHeap, 8, a1, a2);
}


/* sub_406888 @ 00406888 */
unsigned int __stdcall sub_406888(int a1)
{
  unsigned int result; // eax
  unsigned int v2; // ecx

  result = sub_406830(a1 + 19);
  v2 = result;
  if ( result != 0 )
  {
    result = (result + 19) & 0xFFFFFFF0;
    *(_DWORD *)(result - 4) = v2;
  }
  return result;
}


/* sub_4068B4 @ 004068B4 */
int __stdcall sub_4068B4(int a1)
{
  return sub_40684C(*(_DWORD *)(a1 - 4));
}


/* sub_4068C8 @ 004068C8 */
unsigned int sub_4068C8()
{
  unsigned int result; // eax
  int v1; // eax
  int v2; // [esp+0h] [ebp-4h] BYREF

  result = sub_401574();
  if ( result > 0x3C )
  {
    v1 = sub_4010AC(2);
    return dword_4254C0(*(_DWORD *)(v1 + 24), 0, &v2, 4);
  }
  return result;
}


/* sub_4068FC @ 004068FC */
int __stdcall sub_4068FC(int a1, int a2)
{
  int v2; // eax
  int v4; // [esp+0h] [ebp-4h]

  v4 = 0;
  v2 = dword_42543C(a1);
  if ( v2 != 0 )
  {
    v4 = sub_406830(2 * (a2 + v2) + 2);
    if ( v4 != 0 )
      dword_425444(v4, a1);
  }
  return v4;
}


/* sub_40694C @ 0040694C */
_DWORD *__stdcall sub_40694C(int a1)
{
  int v1; // ebx
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v5; // [esp+8h] [ebp-4h]

  v5 = 0;
  v1 = dword_42543C(a1);
  if ( v1 != 0 )
  {
    v2 = (_DWORD *)sub_406830(2 * v1 + 10);
    v3 = v2;
    if ( v2 != nullptr )
    {
      *v2 = 6029404;
      v2[1] = 6029375;
      dword_425440(v2, a1);
      return v3;
    }
  }
  return (_DWORD *)v5;
}


/* sub_4069A8 @ 004069A8 */
_DWORD *__stdcall sub_4069A8(_DWORD *a1, int a2)
{
  _DWORD *v2; // esi
  int v3; // ebx
  int v4; // eax
  _DWORD *v6; // [esp+8h] [ebp-4h]

  v2 = a1;
  v3 = dword_42543C(a1);
  v4 = dword_42543C(a2);
  v6 = (_DWORD *)sub_406830(2 * (v4 + v3) + 22);
  if ( v6 != nullptr )
  {
    *v6 = 6029404;
    v6[1] = 6029375;
    v6[2] = 5111893;
    v6[3] = 6029379;
    if ( *a1 == 6029404 )
      v2 = a1 + 1;
    dword_425440(v6, v2);
    sub_4016D0((int)v6);
    dword_425440(v6, a2);
  }
  return v6;
}


/* sub_406A3C @ 00406A3C */
_DWORD *__stdcall sub_406A3C(_DWORD *a1)
{
  _DWORD *v1; // esi
  int v2; // ebx
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  int v6; // [esp+8h] [ebp-4h]

  v6 = 0;
  v1 = a1;
  v2 = dword_42543C(a1);
  if ( v2 != 0 )
  {
    v3 = (_DWORD *)sub_406830(2 * v2 + 22);
    v4 = v3;
    if ( v3 != nullptr )
    {
      *v3 = 6029404;
      v3[1] = 6029375;
      v3[2] = 5111893;
      v3[3] = 6029379;
      if ( *a1 == 6029404 )
        v1 = a1 + 1;
      dword_425440(v3, v1);
      return v4;
    }
  }
  return (_DWORD *)v6;
}


/* sub_406AB0 @ 00406AB0 */
int sub_406AB0()
{
  __int64 v1; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v2[8]; // [esp+14h] [ebp-8h] BYREF

  dword_4255C0(v2);
  dword_4255C4(v2, &v1);
  return dword_425470(v1 + 717324288, (unsigned __int64)(v1 - 116444736000000000LL) >> 32, 10000000, 0);
}


/* sub_406B10 @ 00406B10 */
int __stdcall sub_406B10(int a1)
{
  int v2[26]; // [esp+Ch] [ebp-D0h] BYREF
  _DWORD v3[26]; // [esp+74h] [ebp-68h] BYREF

  dword_4255FC(v3);
  dword_425600(v3, &unk_424F70, 128);
  dword_425604(v3);
  v2[0] = -1210499005;
  v2[1] = -1211875320;
  v2[2] = -1211023264;
  v2[3] = -1211351011;
  v2[4] = -1213972468;
  v2[5] = -1210499051;
  v2[6] = -1211613176;
  v2[7] = -1211023264;
  v2[8] = -1211351011;
  v2[9] = -1213972470;
  v2[10] = -1211351011;
  v2[11] = -1213972470;
  v2[12] = -1210499051;
  v2[13] = -1211219960;
  v2[14] = -1210498976;
  v2[15] = -1211219960;
  v2[16] = -1210498976;
  v2[17] = -1211219960;
  v2[18] = -1210498976;
  v2[19] = -1211219960;
  v2[20] = -1210498976;
  v2[21] = -1211219960;
  v2[22] = -1210498976;
  v2[23] = -1211219960;
  v2[24] = -1216266144;
  v2[25] = -1208205256;
  sub_401250(v2, 26);
  return dword_425464(a1, v2, v3[22], LOWORD(v3[23]));
}


/* sub_406C60 @ 00406C60 */
int __stdcall sub_406C60(int a1, int a2)
{
  int v2; // ebx
  _DWORD v4[10]; // [esp+4h] [ebp-38h] BYREF
  int v5; // [esp+2Ch] [ebp-10h] BYREF
  _BYTE v6[4]; // [esp+30h] [ebp-Ch] BYREF
  int v7; // [esp+34h] [ebp-8h] BYREF
  int v8; // [esp+38h] [ebp-4h]

  v8 = 0;
  v7 = 0;
  v5 = 0;
  v2 = a1;
  if ( a1 == 0 )
  {
    if ( dword_4254A0(-1, 8, &v7) != 0 )
      goto LABEL_7;
    v2 = v7;
  }
  if ( dword_425490(v2, 1, v4, 40, v6) == 0 && dword_425660(v4[0], &v5) != 0 )
  {
    dword_425444(a2, v5);
    v8 = 1;
  }
LABEL_7:
  if ( v5 != 0 )
    sub_40684C(v5);
  if ( v7 != 0 )
    dword_4254D0(v7);
  return v8;
}


/* sub_406D08 @ 00406D08 */
int sub_406D08()
{
  _WORD *v0; // eax
  int v1; // ebx
  _WORD *v2; // edi
  int v3; // eax
  int *v4; // esi
  __int16 v5; // ax
  int v7[8]; // [esp+Ch] [ebp-108h] BYREF
  _BYTE v8[128]; // [esp+2Ch] [ebp-E8h] BYREF
  _BYTE v9[88]; // [esp+ACh] [ebp-68h] BYREF
  _BYTE v10[16]; // [esp+104h] [ebp-10h] BYREF

  v0 = (_WORD *)sub_406830(24);
  v1 = (int)v0;
  if ( v0 != nullptr )
  {
    *v0 = 46;
    v2 = v0 + 1;
    dword_4255FC(v9);
    v3 = sub_406B10((int)v8);
    if ( v3 != 0 )
    {
      dword_425600(v9, v8, 2 * v3);
      dword_425604(v9);
      v4 = v7;
      sub_401414(v1, v10, 16, v7);
      BYTE1(v7[2]) = 0;
      HIBYTE(v5) = 0;
      while ( 1 )
      {
        LOBYTE(v5) = *(_BYTE *)v4;
        v4 = (int *)((char *)v4 + 1);
        if ( (_BYTE)v5 == 0 )
          break;
        switch ( (_BYTE)v5 )
        {
          case '+':
            LOBYTE(v5) = 120;
            break;
          case '/':
            LOBYTE(v5) = 105;
            break;
          case '=':
            LOBYTE(v5) = 122;
            break;
          default:
            break;
        }
        *v2++ = v5;
      }
      *v2 = v5;
    }
  }
  return v1;
}


/* sub_406DB0 @ 00406DB0 */
void *__stdcall sub_406DB0(_DWORD *a1)
{
  void *v1; // eax
  void *v2; // ebx
  unsigned int v3; // edx

  v1 = (void *)sub_406830(*(a1 - 1));
  v2 = v1;
  if ( v1 != nullptr )
  {
    v3 = *(a1 - 1);
    qmemcpy(v1, a1, v3);
    sub_401730(v1, v3);
  }
  return v2;
}


/* sub_406DE0 @ 00406DE0 */
unsigned int *__stdcall sub_406DE0(const void *a1, unsigned int a2)
{
  unsigned int *v2; // eax
  unsigned int *v3; // ebx

  v2 = (unsigned int *)sub_406830(a2 + 4);
  v3 = v2;
  if ( v2 != nullptr )
  {
    *v2 = a2;
    qmemcpy(v2 + 1, a1, a2);
    sub_401730((_BYTE *)v2 + 4, a2);
  }
  return v3;
}


/* sub_406E1C @ 00406E1C */
int __stdcall sub_406E1C(int a1, _DWORD *a2)
{
  int v2; // ebx
  int v4; // [esp+4h] [ebp-4h] BYREF

  v2 = 0;
  if ( dword_42548C(a1, 26, &v4, 4, 0) == 0 )
  {
    *a2 = v4 != 0;
    return 1;
  }
  return v2;
}


/* sub_406E54 @ 00406E54 */
int sub_406E54()
{
  int v0; // eax
  int v1; // ebx
  int v2; // esi
  int v3; // edi
  unsigned __int8 v4; // al
  int v6; // [esp+0h] [ebp-14h]
  int v7; // [esp+4h] [ebp-10h]
  int v8; // [esp+8h] [ebp-Ch]
  __int64 v9; // [esp+Ch] [ebp-8h] BYREF

  strcpy((char *)&v9 + 3, "%02X");
  v0 = sub_406830(17);
  v1 = v0;
  if ( v0 != 0 )
  {
    v2 = 0;
    v3 = v0;
    do
    {
      v4 = sub_4010D4();
      ((void (__cdecl *)(int, char *, _DWORD, int, int, int, _DWORD))dword_425468)(
        v3,
        (char *)&v9 + 3,
        v4,
        v6,
        v7,
        v8,
        v9);
      v3 += 2;
      ++v2;
    }
    while ( v2 != 8 );
  }
  return v1;
}


/* sub_406EAC @ 00406EAC */
int __stdcall sub_406EAC(_BYTE *a1)
{
  int v1; // ebx
  unsigned __int8 *v2; // esi
  int v4; // eax
  const void *v5; // ebx
  int v7; // [esp+0h] [ebp-14h]
  int v8; // [esp+4h] [ebp-10h]
  int v9; // [esp+8h] [ebp-Ch]
  __int64 v10; // [esp+Ch] [ebp-8h] BYREF

  v1 = 0;
  strcpy((char *)&v10 + 3, "%02X");
  v2 = (unsigned __int8 *)&unk_424F70;
  do
  {
    v4 = *v2++;
    ((void (__cdecl *)(_BYTE *, char *, int, int, int, int, _DWORD))dword_425468)(
      a1,
      (char *)&v10 + 3,
      v4,
      v7,
      v8,
      v9,
      v10);
    a1 += 2;
    ++v1;
  }
  while ( v1 != 8 );
  v5 = (const void *)sub_406E54();
  qmemcpy(a1, v5, 0x12u);
  a1[18] = 0;
  return sub_40684C((int)v5);
}


/* sub_406F10 @ 00406F10 */
int sub_406F10()
{
  int result; // eax
  _DWORD *v1; // edi
  int v2; // eax
  char *v3; // ebx
  int v4; // eax
  int v5; // eax
  char *v6; // ebx
  int v7; // eax
  int v8; // eax
  char *v9; // ebx
  int v10; // eax
  int v11; // eax
  char *v12; // ebx
  int v13; // eax
  int v14; // eax
  char *v15; // ebx
  int v16; // eax
  int v17; // eax
  char *v18; // ebx
  int v19; // eax
  int v20; // eax
  char *v21; // ebx
  int v22; // eax
  int v23; // eax
  char *v24; // ebx
  int v25; // eax
  int v26; // eax
  char *v27; // ebx
  int v28; // eax
  int v29; // esi
  _BYTE v30[48]; // [esp+Ch] [ebp-38h] BYREF
  _DWORD *v31; // [esp+3Ch] [ebp-8h]
  int v32; // [esp+40h] [ebp-4h]

  result = sub_406DB0(&unk_42600C);
  v32 = result;
  if ( result != 0 )
  {
    v31 = (_DWORD *)sub_406830(4 * unk_426008);
    if ( v31 != nullptr )
    {
      if ( sub_418BA4(v32, v31) != -1 )
      {
        dword_425424(&unk_424F70, v31, 128);
        dword_425424(&unk_425100, v31 + 32, 32);
        dword_425424(&byte_425120, v31 + 40, 24);
        v1 = v31 + 46;
        v2 = v31[46];
        if ( v2 != 0 )
        {
          v3 = (char *)v1 + v2;
          v4 = sub_401518((char *)v1 + v2);
          dword_425138 = sub_406830(v4 + 2);
          if ( dword_425138 != 0 )
            sub_4012F4(v3, dword_425138);
        }
        v5 = v31[47];
        if ( v5 != 0 )
        {
          v6 = (char *)v1 + v5;
          v7 = sub_401518((char *)v1 + v5);
          dword_42513C = sub_406830(v7 + 2);
          if ( dword_42513C != 0 )
            sub_4012F4(v6, dword_42513C);
        }
        v8 = v31[48];
        if ( v8 != 0 )
        {
          v9 = (char *)v1 + v8;
          v10 = sub_401518((char *)v1 + v8);
          dword_425140 = sub_406830(v10 + 2);
          if ( dword_425140 != 0 )
            sub_4012F4(v9, dword_425140);
        }
        v11 = v31[49];
        if ( v11 != 0 )
        {
          v12 = (char *)v1 + v11;
          v13 = sub_401518((char *)v1 + v11);
          dword_425144 = sub_406830(v13 + 2);
          if ( dword_425144 != 0 )
            sub_4012F4(v12, dword_425144);
        }
        v14 = v31[51];
        if ( v14 != 0 )
        {
          v15 = (char *)v1 + v14;
          v16 = sub_401518((char *)v1 + v14);
          dword_425148 = sub_406830(v16 + 2);
          if ( dword_425148 != 0 )
            sub_4012F4(v15, dword_425148);
        }
        v17 = v31[52];
        if ( v17 != 0 )
        {
          v18 = (char *)v1 + v17;
          v19 = sub_401518((char *)v1 + v17);
          dword_42514C = sub_406830(v19 + 2);
          if ( dword_42514C != 0 )
            sub_4012F4(v18, dword_42514C);
        }
        v20 = v31[53];
        if ( v20 != 0 )
        {
          v21 = (char *)v1 + v20;
          v22 = sub_401518((char *)v1 + v20);
          dword_425150 = sub_406830(v22 + 2);
          if ( dword_425150 != 0 )
            sub_4012F4(v21, dword_425150);
        }
        v23 = v31[54];
        if ( v23 != 0 )
        {
          v24 = (char *)v1 + v23;
          v25 = dword_425430((char *)v1 + v23);
          dword_425154 = sub_406830(v25 + 2);
          if ( dword_425154 != 0 )
            dword_425434(dword_425154, v24);
        }
        v26 = v31[55];
        if ( v26 != 0 )
        {
          v27 = (char *)v1 + v26;
          v28 = sub_401518((char *)v1 + v26);
          dword_425158 = sub_406830(v28 + 2);
          if ( dword_425158 != 0 )
          {
            dword_425174 = sub_4012F4(v27, dword_425158);
            sub_406EAC(v30);
            sub_401730(dword_425158, dword_425174);
            v29 = sub_406830(dword_425174 + 48);
            if ( v29 != 0 )
            {
              dword_425174 = ((int (__cdecl *)(int, int, _BYTE *))dword_425468)(v29, dword_425158, v30);
              sub_401730(v29, dword_425174);
              sub_40684C(dword_425158);
              dword_425158 = v29;
            }
          }
        }
      }
      sub_40684C((int)v31);
    }
    return sub_40684C(v32);
  }
  return result;
}


/* sub_407260 @ 00407260 */
int __stdcall sub_407260(int a1)
{
  return dword_425608(a1, 1, 5, dword_407210, 0, dword_407230, 0);
}


/* sub_407284 @ 00407284 */
int sub_407284()
{
  _DWORD v1[10]; // [esp+4h] [ebp-90h] BYREF
  _DWORD v2[15]; // [esp+2Ch] [ebp-68h] BYREF
  _DWORD v3[4]; // [esp+68h] [ebp-2Ch] BYREF
  _DWORD v4[4]; // [esp+78h] [ebp-1Ch] BYREF
  int v5; // [esp+88h] [ebp-Ch]
  int v6; // [esp+8Ch] [ebp-8h]
  int v7; // [esp+90h] [ebp-4h]

  v4[0] = 6881367;
  v4[1] = 5439598;
  v4[2] = 6357108;
  v4[3] = 48;
  v3[0] = 6619204;
  v3[1] = 6357094;
  v3[2] = 7078005;
  v3[3] = 116;
  dword_425428(v1, 0, 100);
  v1[0] = 1;
  v2[0] = 3932162;
  v2[1] = 1;
  v2[2] = 1310720;
  v2[3] = 0x10000000;
  v2[4] = 257;
  v2[5] = 0x1000000;
  if ( (unsigned int)sub_401574() >= 0x3E )
  {
    v2[1] = 2;
    v2[7] = 1572864;
    v2[8] = 0x10000000;
    v2[9] = 513;
    v2[10] = 251658240;
    v2[11] = 2;
    v2[12] = 1;
  }
  HIWORD(v1[0]) = 4;
  v1[4] = v2;
  v7 = 0;
  v6 = 0;
  v5 = 0;
  v6 = dword_4256B4(v4, 0, 0x40000);
  if ( v6 != 0 && dword_42549C(v6, 4, v1) == 0 )
  {
    v5 = dword_4256BC(v3, 0, 0, 262273);
    if ( v5 != 0 && dword_42549C(v5, 4, v1) == 0 )
      v7 = 1;
  }
  if ( v5 != 0 )
    dword_4256C0(v5);
  if ( v6 != 0 )
    dword_4256B8(v6);
  return v7;
}


/* sub_4073F8 @ 004073F8 */
int sub_4073F8()
{
  struct _PEB *v0; // eax
  int result; // eax
  int v2; // [esp+0h] [ebp-4h]

  v0 = sub_4010AC();
  result = sub_4068FC((int)v0->ProcessParameters->ImagePathName.Buffer, 0);
  v2 = result;
  if ( result != 0 )
  {
    dword_425784(result);
    dword_42558C(v2);
    return sub_40684C(v2);
  }
  return result;
}


/* sub_407438 @ 00407438 */
unsigned int sub_407438()
{
  unsigned int result; // eax
  unsigned int v1; // ebx
  _BYTE *v2; // esi
  _BYTE v3[520]; // [esp+8h] [ebp-208h] BYREF

  result = dword_425564(260, v3);
  if ( result != 0 )
  {
    v1 = result >> 2;
    v2 = v3;
    do
    {
      result = dword_425568(v2);
      if ( result == 3 || result == 2 )
        result = sub_40748C(v2);
      v2 += 8;
      --v1;
    }
    while ( v1 != 0 );
  }
  return result;
}


/* sub_40748C @ 0040748C */
int __stdcall sub_40748C(int a1)
{
  int result; // eax
  int v2; // eax
  _BYTE v3[44]; // [esp+0h] [ebp-464h] BYREF
  _BYTE v4[548]; // [esp+2Ch] [ebp-438h] BYREF
  _BYTE v5[520]; // [esp+250h] [ebp-214h] BYREF
  _DWORD v6[2]; // [esp+458h] [ebp-Ch] BYREF
  int v7; // [esp+460h] [ebp-4h]

  result = sub_407560(a1, v5);
  if ( result != 0 )
  {
    sub_4016D0((int)v5);
    v6[0] = 2949203;
    v6[1] = 42;
    dword_425440(v5, v6);
    result = dword_425508(v5, 0, v3, 0, 0, 0);
    v7 = result;
    if ( result != -1 )
    {
      do
      {
        if ( (v3[0] & 0x10) != 0 )
        {
          v2 = dword_425450(v5, 92);
          dword_425444(v2 + 2, v4);
          sub_40763C(v5);
        }
      }
      while ( dword_42550C(v7, v3) != 0 );
      return dword_425510(v7);
    }
  }
  return result;
}


/* sub_407560 @ 00407560 */
int __stdcall sub_407560(int a1, int a2)
{
  _BYTE v3[44]; // [esp+0h] [ebp-474h] BYREF
  _BYTE v4[548]; // [esp+2Ch] [ebp-448h] BYREF
  _BYTE v5[520]; // [esp+250h] [ebp-224h] BYREF
  _DWORD v6[5]; // [esp+458h] [ebp-1Ch] BYREF
  int v7; // [esp+46Ch] [ebp-8h]
  int v8; // [esp+470h] [ebp-4h]

  v8 = 0;
  dword_425444(v5, a1);
  v6[0] = 7471146;
  v6[1] = 6488165;
  v6[2] = 6488185;
  v6[3] = 6619244;
  v6[4] = 42;
  dword_425440(v5, v6);
  v7 = dword_425508(v5, 0, v3, 0, 0, 0);
  if ( v7 != -1 )
  {
    while ( (v3[0] & 0x10) == 0 )
    {
      if ( dword_42550C(v7, v3) == 0 )
        goto LABEL_5;
    }
    dword_425444(a2, a1);
    dword_425440(a2, v4);
    v8 = 1;
LABEL_5:
    dword_425510(v7);
  }
  return v8;
}


/* sub_40763C @ 0040763C */
int __stdcall sub_40763C(int a1)
{
  int result; // eax
  int v2; // esi
  int v3; // eax
  int v4; // eax
  _BYTE v5[44]; // [esp+8h] [ebp-260h] BYREF
  _DWORD v6[137]; // [esp+34h] [ebp-234h] BYREF
  int v7; // [esp+258h] [ebp-10h]
  int v8; // [esp+25Ch] [ebp-Ch]
  int v9; // [esp+260h] [ebp-8h] BYREF
  int v10; // [esp+264h] [ebp-4h]

  v8 = 0;
  v7 = 0;
  result = dword_42543C(a1);
  if ( result != 0 )
  {
    result = sub_406830(2 * result + 6);
    v8 = result;
    if ( result != 0 )
    {
      dword_425444(v8, a1);
      sub_4016D0(v8);
      v9 = 42;
      dword_425440(v8, &v9);
      result = dword_425508(v8, 0, v5, 0, 0, 0);
      v10 = result;
      if ( result != -1 )
      {
        do
        {
          if ( v6[0] != 46 && v6[0] != 3014702 )
          {
            v2 = dword_42543C(v6);
            v3 = dword_42543C(v8);
            v7 = sub_406830(2 * (v3 + v2) + 2);
            if ( v7 != 0 )
            {
              dword_425444(v7, v8);
              v4 = dword_425450(v7, 42);
              dword_425444(v4, v6);
              if ( (dword_425504(v7) & 0x10) != 0 )
              {
                while ( dword_425578(v7) == 0 && __readfsdword(0x34u) == 145 )
                  sub_40763C(v7);
                sub_40684C(v7);
                v7 = 0;
              }
              else
              {
                sub_406654(v7);
                sub_40684C(v7);
                v7 = 0;
              }
            }
          }
        }
        while ( dword_42550C(v10, v5) != 0 );
        result = dword_425510(v10);
      }
    }
    if ( v8 != 0 )
      result = sub_40684C(v8);
    if ( v7 != 0 )
      return sub_40684C(v7);
  }
  return result;
}


/* sub_4077FC @ 004077FC */
int sub_4077FC()
{
  int result; // eax
  _BYTE v1[128]; // [esp+0h] [ebp-1C8h] BYREF
  int v2[12]; // [esp+80h] [ebp-148h] BYREF
  int v3[16]; // [esp+B0h] [ebp-118h] BYREF
  int v4[13]; // [esp+F0h] [ebp-D8h] BYREF
  int v5[2]; // [esp+124h] [ebp-A4h] BYREF
  int v6[2]; // [esp+12Ch] [ebp-9Ch] BYREF
  int v7[6]; // [esp+134h] [ebp-94h] BYREF
  int v8[4]; // [esp+14Ch] [ebp-7Ch] BYREF
  int v9[4]; // [esp+15Ch] [ebp-6Ch] BYREF
  int v10[4]; // [esp+16Ch] [ebp-5Ch] BYREF
  int v11[4]; // [esp+17Ch] [ebp-4Ch] BYREF
  _DWORD v12[4]; // [esp+18Ch] [ebp-3Ch] BYREF
  _BYTE v13[8]; // [esp+19Ch] [ebp-2Ch] BYREF
  int v14; // [esp+1A4h] [ebp-24h]
  int v15; // [esp+1ACh] [ebp-1Ch] BYREF
  int v16; // [esp+1B0h] [ebp-18h] BYREF
  int v17; // [esp+1B4h] [ebp-14h] BYREF
  int v18; // [esp+1B8h] [ebp-10h] BYREF
  int v19; // [esp+1BCh] [ebp-Ch] BYREF
  int v20; // [esp+1C0h] [ebp-8h] BYREF
  int v21; // [esp+1C4h] [ebp-4h] BYREF

  v20 = 0;
  v18 = 0;
  v19 = 0;
  v17 = 0;
  result = dword_425744(0);
  if ( result != 0 )
    return result;
  v11[0] = 2088310260;
  v11[1] = -1506946800;
  v11[2] = 2013059989;
  v11[3] = 1208064119;
  sub_401250(v11, 4);
  v10[0] = 1810818751;
  v10[1] = -1506593977;
  v10[2] = 503057840;
  v10[3] = -1814951112;
  sub_401250(v10, 4);
  v9[0] = -793303392;
  v9[1] = -1507021142;
  v9[2] = 2013016469;
  v9[3] = 1208064119;
  sub_401250(v9, 4);
  v8[0] = -212801972;
  v8[1] = -1507022652;
  v8[2] = 2013019288;
  v8[3] = -1753942409;
  sub_401250(v8, 4);
  v2[0] = -1214037913;
  v2[1] = -1215414168;
  v2[2] = -1215676329;
  v2[3] = -1214758831;
  v2[4] = -1215414179;
  v2[5] = -1215414151;
  v2[6] = -1215020965;
  v2[7] = -1215807407;
  v2[8] = -1214300067;
  v2[9] = -1215741876;
  v2[10] = -1214693302;
  v2[11] = -1208205256;
  sub_401250(v2, 12);
  v7[0] = -1212989334;
  v7[1] = -1213710217;
  v7[2] = -1212202908;
  v7[3] = -1213120399;
  v7[4] = -1211219858;
  v7[5] = -1208205256;
  sub_401250(v7, 6);
  v5[0] = -1212661647;
  v5[1] = -1208205256;
  sub_401250(v5, 2);
  v3[0] = -1212596117;
  v3[1] = -1212596108;
  v3[2] = -1213710213;
  v3[3] = -1210695656;
  v3[4] = -1212530664;
  v3[5] = -1212989334;
  v3[6] = -1210302347;
  v3[7] = -1214955409;
  v3[8] = -1211154346;
  v3[9] = -1214038006;
  v3[10] = -1215020949;
  v3[11] = -1214758823;
  v3[12] = -1215610793;
  v3[13] = -1215086469;
  v3[14] = -1216004024;
  v3[15] = -1208205256;
  sub_401250(v3, 16);
  v6[0] = -1213382545;
  v6[1] = -1208205196;
  sub_401250(v6, 2);
  v4[0] = -1214955409;
  v4[1] = -1211154346;
  v4[2] = -1214038006;
  v4[3] = -1215020949;
  v4[4] = -1214758823;
  v4[5] = -1215610793;
  v4[6] = -1215086469;
  v4[7] = -1216004024;
  v4[8] = -1212858346;
  v4[9] = -1212071812;
  v4[10] = -1210499041;
  v4[11] = -1210367925;
  v4[12] = -1208205256;
  sub_401250(v4, 13);
  if ( dword_425758(v11, 0, 1, v10, &v20) == 0 && dword_425758(v9, 0, 1, v8, &v19) == 0 )
  {
    sub_406E1C(-1, &v21);
    if ( v21 == 0 )
    {
LABEL_7:
      if ( (*(int (__stdcall **)(int, int *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int *))(*(_DWORD *)v20 + 12))(
             v20,
             v7,
             0,
             0,
             0,
             0,
             0,
             v19,
             &v18) == 0
        && dword_425760(v18, 10, 0, 0, 3, 3, 0, 0) == 0
        && (*(int (__stdcall **)(int, int *, int *, int, _DWORD, int *))(*(_DWORD *)v18 + 80))(v18, v6, v3, 48, 0, &v17) == 0 )
      {
        while ( 1 )
        {
          v16 = 0;
          v15 = 0;
          if ( (*(int (__stdcall **)(int, int, int, int *, int *))(*(_DWORD *)v17 + 16))(v17, -1, 1, &v16, &v15) != 0 )
            break;
          dword_4257A0(v13);
          if ( (*(int (__stdcall **)(int, int *, _DWORD, _BYTE *, _DWORD, _DWORD))(*(_DWORD *)v16 + 16))(
                 v16,
                 v5,
                 0,
                 v13,
                 0,
                 0) == 0 )
          {
            ((void (__cdecl *)(_BYTE *, int *, int))dword_425464)(v1, v4, v14);
            (*(void (__stdcall **)(int, _BYTE *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v18 + 64))(v18, v1, 0, 0, 0);
            dword_4257A4(v13);
          }
          (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(v16);
        }
      }
      goto LABEL_14;
    }
    dword_4257A0(v12);
    v12[0] = 3;
    v12[2] = 64;
    if ( (*(int (__stdcall **)(int, int *, _DWORD, _DWORD *))(*(_DWORD *)v19 + 32))(v19, v2, 0, v12) == 0 )
    {
      dword_4257A4(v12);
      goto LABEL_7;
    }
  }
LABEL_14:
  if ( v17 != 0 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v17 + 8))(v17);
  if ( v18 != 0 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v18 + 8))(v18);
  if ( v19 != 0 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v19 + 8))(v19);
  if ( v20 != 0 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v20 + 8))(v20);
  return dword_42574C();
}


/* sub_407C74 @ 00407C74 */
int sub_407C74()
{
  int result; // eax
  _DWORD *v1; // edi
  _BYTE v2[28]; // [esp+4h] [ebp-58h] BYREF
  int v3; // [esp+20h] [ebp-3Ch]
  _BYTE v4[28]; // [esp+28h] [ebp-34h] BYREF
  _BYTE v5[4]; // [esp+44h] [ebp-18h] BYREF
  int v6; // [esp+48h] [ebp-14h] BYREF
  int v7; // [esp+4Ch] [ebp-10h] BYREF
  _DWORD *v8; // [esp+50h] [ebp-Ch]
  int v9; // [esp+54h] [ebp-8h]
  int v10; // [esp+58h] [ebp-4h]

  v8 = nullptr;
  result = dword_425624(0, 0, 4);
  v10 = result;
  if ( result != 0 )
  {
    v7 = 0;
    dword_425628(v10, 0, 48, 3, 0, 0, &v7, &v6, 0, 0);
    result = sub_406830(v7);
    v8 = (_DWORD *)result;
    if ( result != 0 )
    {
      result = dword_425628(v10, 0, 48, 3, v8, v7, &v7, &v6, 0, 0);
      if ( result != 0 )
      {
        v1 = v8;
        do
        {
          result = sub_407DCC(*v1);
          if ( result != 0 )
          {
            result = dword_42562C(v10, *v1, 65568);
            v9 = result;
            if ( result != 0 )
            {
              dword_425428(v4, 0, 28);
              if ( dword_425640(v9, 1, v4) == 0 )
              {
                dword_425428(v2, 0, 36);
                if ( dword_42563C(v9, 0, v2, 36, v5) != 0 )
                  sub_40DBBC(v3);
              }
              dword_425644(v9);
              result = dword_425648(v9);
            }
          }
          v1 += 11;
          --v6;
        }
        while ( v6 != 0 );
      }
    }
  }
  if ( v10 != 0 )
    result = dword_425648(v10);
  if ( v8 != nullptr )
    return sub_40684C((int)v8);
  return result;
}


/* sub_407DCC @ 00407DCC */
int __stdcall sub_407DCC(int a1)
{
  _WORD *v1; // esi
  int v3; // [esp+4h] [ebp-4h]

  v3 = 0;
  v1 = (_WORD *)dword_42514C;
  dword_425458(a1);
  while ( dword_425448(a1, v1) == 0 )
  {
    v1 += dword_42543C(v1) + 1;
    if ( *v1 == 0 )
      return v3;
  }
  return 1;
}


/* sub_407E28 @ 00407E28 */
int sub_407E28()
{
  int v0; // eax
  int *v2; // ebx
  int v3; // esi
  _DWORD v4[6]; // [esp+8h] [ebp-2Ch] BYREF
  _DWORD v5[2]; // [esp+20h] [ebp-14h] BYREF
  int *i; // [esp+28h] [ebp-Ch]
  int v7; // [esp+2Ch] [ebp-8h] BYREF
  int v8; // [esp+30h] [ebp-4h] BYREF

LABEL_1:
  v7 = 1024;
  for ( i = (int *)sub_406830(1024); ; i = (int *)sub_406868((int)i, v7) )
  {
    v0 = dword_425488(5, i, v7, &v7);
    if ( v0 == 0 )
    {
      v2 = i;
      do
      {
        v3 = *v2;
        if ( v2[15] != 0 && sub_407F20(v2[15]) != 0 )
        {
          v5[0] = v2[17];
          v5[1] = 0;
          v4[0] = 24;
          memset(&v4[1], 0, 20);
          if ( dword_425474(&v8, 1, v4, v5) == 0 )
          {
            dword_4254C8(v8, 0);
            dword_4254D0(v8);
          }
        }
        v2 = (int *)((char *)v2 + v3);
      }
      while ( v3 != 0 );
      sub_40684C((int)i);
      dword_42553C(2000);
      goto LABEL_1;
    }
    if ( v0 != -1073741820 )
      break;
  }
  return sub_40684C((int)i);
}


/* sub_407F20 @ 00407F20 */
int __stdcall sub_407F20(int a1)
{
  _WORD *v1; // esi
  int v3; // [esp+8h] [ebp-4h]

  v3 = 0;
  v1 = (_WORD *)dword_425148;
  dword_425458(a1);
  while ( 1 )
  {
    dword_425458(v1);
    if ( dword_425448(a1, v1) != 0 )
      break;
    v1 += dword_42543C(v1) + 1;
    if ( *v1 == 0 )
      return v3;
  }
  return 1;
}


/* sub_407F8C @ 00407F8C */
unsigned int sub_407F8C()
{
  unsigned int v0; // ebx
  _WORD v2[64]; // [esp+8h] [ebp-11Ch] BYREF
  int v3[12]; // [esp+88h] [ebp-9Ch] BYREF
  _DWORD v4[26]; // [esp+B8h] [ebp-6Ch] BYREF
  int v5; // [esp+120h] [ebp-4h] BYREF

  v0 = 0;
  if ( sub_406B10((int)v2) != 0 )
  {
    v5 = sub_4011D4(v2, 0);
    dword_425428(v4, 0, 104);
    dword_4255F0(v4);
    dword_4255F4(v4, &v5, 4);
    dword_4255F8(v4);
    v3[0] = -1215283073;
    v3[1] = -1214365609;
    v3[2] = -1215283111;
    v3[3] = -1210498972;
    v3[4] = -1211875306;
    v3[5] = -1210499008;
    v3[6] = -1211875306;
    v3[7] = -1210499008;
    v3[8] = -1211875306;
    v3[9] = -1210499008;
    v3[10] = -1211875306;
    v3[11] = -1208205248;
    sub_401250(v3, 12);
    v0 = sub_406888(80);
    if ( v0 != 0 )
      dword_425464(v0, v3, v4[22], v4[23]);
  }
  return v0;
}


/* sub_408088 @ 00408088 */
BOOL sub_408088()
{
  __int16 v0; // si
  __int16 v1; // bx
  __int16 v2; // bx
  __int16 v3; // bx
  __int16 v4; // bx
  _WORD v6[4]; // [esp+Ch] [ebp-8h] BYREF

  dword_4254F0(v6);
  v0 = v6[0];
  dword_4254F4(v6);
  HIBYTE(v1) = 4;
  if ( v0 == 1049 )
    return true;
  LOBYTE(v1) = 34;
  if ( v1 == v0 )
    return true;
  if ( v1 == v6[0] )
    return true;
  LOBYTE(v1) = 35;
  if ( v1 == v0 )
    return true;
  if ( v1 == v6[0] )
    return true;
  LOBYTE(v1) = 40;
  if ( v1 == v0 )
    return true;
  if ( v1 == v6[0] )
    return true;
  LOBYTE(v1) = 43;
  if ( v1 == v0 )
    return true;
  if ( v1 == v6[0] )
    return true;
  LOBYTE(v1) = 44;
  if ( v1 == v0 )
    return true;
  if ( v1 == v6[0] )
    return true;
  LOBYTE(v1) = 55;
  if ( v1 == v0 )
    return true;
  if ( v1 == v6[0] )
    return true;
  LOBYTE(v1) = 63;
  if ( v1 == v0 )
    return true;
  if ( v1 == v6[0] )
    return true;
  LOBYTE(v1) = 64;
  if ( v1 == v0 )
    return true;
  if ( v1 == v6[0] )
    return true;
  LOBYTE(v1) = 66;
  if ( v1 == v0 )
    return true;
  if ( v1 == v6[0] )
    return true;
  LOBYTE(v1) = 67;
  if ( v1 == v0 )
    return true;
  if ( v1 == v6[0] )
    return true;
  LOBYTE(v1) = 68;
  if ( v1 == v0 )
    return true;
  if ( v1 == v6[0] )
    return true;
  v2 = (2 * v1) ^ 0x90;
  if ( v2 == v0 )
    return true;
  if ( v2 == v6[0] )
    return true;
  v3 = v2 + 1;
  if ( v3 == v0 )
    return true;
  if ( v3 == v6[0] )
    return true;
  LOBYTE(v3) = v3 ^ 0x35;
  if ( v3 == v0 )
    return true;
  if ( v3 == v6[0] )
    return true;
  LOBYTE(v3) = v3 ^ 0x6F;
  if ( v3 == v0 )
    return true;
  if ( v3 == v6[0] )
    return true;
  v4 = (4 * v3) ^ 0x90D;
  return v4 == v0 || v4 == v6[0];
}


/* sub_408200 @ 00408200 */
void __stdcall sub_408200(int a1)
{
  int v1; // eax
  int v2; // ebx
  int v3; // eax
  int v4; // ebx
  _DWORD *v5; // eax
  int v6; // eax
  int v7; // eax
  _BYTE v8[520]; // [esp+Ch] [ebp-2E0h] BYREF
  _DWORD v9[11]; // [esp+214h] [ebp-D8h] BYREF
  _DWORD v10[8]; // [esp+240h] [ebp-ACh] BYREF
  __int16 v11; // [esp+260h] [ebp-8Ch] BYREF
  int v12; // [esp+262h] [ebp-8Ah]
  __int16 v13; // [esp+266h] [ebp-86h]
  __int16 v14; // [esp+268h] [ebp-84h]
  int v15; // [esp+26Ah] [ebp-82h]
  int v16; // [esp+270h] [ebp-7Ch] BYREF
  unsigned int v17; // [esp+274h] [ebp-78h]
  unsigned int v18; // [esp+278h] [ebp-74h]
  __int16 v19; // [esp+27Ch] [ebp-70h]
  __int16 v20; // [esp+27Eh] [ebp-6Eh]
  int v21; // [esp+280h] [ebp-6Ch]
  int v22; // [esp+284h] [ebp-68h]
  _DWORD v23[4]; // [esp+29Ch] [ebp-50h] BYREF
  int v24; // [esp+2ACh] [ebp-40h] BYREF
  int v25; // [esp+2B0h] [ebp-3Ch]
  int v26; // [esp+2B4h] [ebp-38h]
  _BYTE v27[4]; // [esp+2B8h] [ebp-34h] BYREF
  int v28; // [esp+2BCh] [ebp-30h]
  int v29; // [esp+2C0h] [ebp-2Ch]
  int v30; // [esp+2C4h] [ebp-28h]
  int v31; // [esp+2C8h] [ebp-24h]
  unsigned int v32; // [esp+2CCh] [ebp-20h] BYREF
  unsigned int v33; // [esp+2D0h] [ebp-1Ch] BYREF
  int v34; // [esp+2D4h] [ebp-18h]
  int v35; // [esp+2D8h] [ebp-14h]
  int v36; // [esp+2DCh] [ebp-10h]
  _BYTE v37[4]; // [esp+2E0h] [ebp-Ch] BYREF
  int v38; // [esp+2E4h] [ebp-8h] BYREF
  int v39; // [esp+2E8h] [ebp-4h]

  v36 = 0;
  v35 = 0;
  v34 = 0;
  v31 = 0;
  v30 = 0;
  v26 = 0;
  v25 = 0;
  v39 = 0;
  v38 = 0;
  v29 = 0;
  if ( byte_42512B != 0 )
  {
    v36 = dword_4256A0(0);
    if ( v36 != 0 )
    {
      v35 = dword_4256F4(v36);
      if ( v35 != 0 )
      {
        v34 = dword_4256F4(v36);
        if ( v34 != 0 )
        {
          if ( sub_410DF4(0, dword_425178 + 2, &v32, &v33) == 0 )
          {
            v32 = (dword_4256E0(v36, 8) + 1) & 0xFFFFFFFE;
            v33 = (dword_4256E0(v36, 10) + 1) & 0xFFFFFFFE;
          }
          v10[0] = -1214955412;
          v10[1] = -1214693291;
          v10[2] = -1210302389;
          v10[3] = -1214693258;
          v10[4] = -1210302385;
          v10[5] = -1215086486;
          v10[6] = -1214431147;
          v10[7] = -1208205226;
          sub_401250(v10, 8);
          v1 = dword_4256E0(v36, 88);
          v31 = dword_4256D8(6 * (v33 / (__int64)v1), 0, 0, 0, 700, 0, 0, 0, 1, 7, 0, 2, 0, v10);
          if ( v31 != 0 && dword_4256F8(v35, v31) != 0 )
          {
            v30 = sub_406830(1024);
            if ( v30 != 0 )
            {
              if ( sub_401574() == 52 )
              {
                v29 = sub_406DB0(&unk_41B0F8);
                if ( v29 == 0 )
                  goto LABEL_35;
              }
              else
              {
                v29 = sub_406DB0(&unk_41B004);
                if ( v29 == 0 )
                  goto LABEL_35;
              }
              v2 = ((int (__cdecl *)(int, int, int))dword_425464)(v30, v29, dword_42517C);
              if ( v2 != 0 )
              {
                if ( dword_425714(v35, v30, v2, v27) != 0 )
                {
                  v26 = dword_4256F0(v35, v32, v33);
                  if ( v26 != 0 && dword_4256F8(v35, v26) != 0 )
                  {
                    dword_425708(v35, 0xFFFFFF);
                    dword_42570C(v35, 2);
                    dword_4256E8(v35, 0);
                    v23[0] = 0;
                    v23[1] = (v33 >> 1) - 2 * v28;
                    v3 = sub_401574() == 52 ? (v32 >> 2) + (v32 >> 1) : v32;
                    v23[2] = v3;
                    v23[3] = v33;
                    if ( dword_4256A8(v35, v30, v2, v23, 529) != 0 )
                    {
                      dword_425428(v30, 0, 1024);
                      dword_425428(&v16, 0, 44);
                      v16 = 40;
                      v20 = 16;
                      v21 = 0;
                      v17 = v32;
                      v18 = v33;
                      v19 = 1;
                      v22 = 2 * v33 * v32;
                      v11 = 19778;
                      v15 = 54;
                      v12 = v22 + 54;
                      v13 = 0;
                      v14 = 0;
                      v25 = dword_4256FC(v35, &v16, 0, &v24, 0, 0);
                      if ( v25 != 0 )
                      {
                        dword_4256F8(v34, v25);
                        if ( dword_4256E4(v34, 0, 0, v17, v18, v35, 0, 0, 13369376) != 0 )
                        {
                          dword_425730(0, v30, 35, 0);
                          sub_4016D0(v30);
                          v4 = v30;
                          dword_425440(v30, dword_425178 + 2);
                          v5 = (_DWORD *)(v4 + 2 * dword_42543C(v4));
                          *v5 = -1214365674;
                          v5[1] = -1215545259;
                          v5[2] = -1208205256;
                          sub_401250(v5, 3);
                          v39 = dword_425528(v30, 0x40000000, 0, 0, 4, 128, 0);
                          if ( v39 != -1
                            && dword_42552C(v39, &v11, 14, v37, 0) != 0
                            && dword_42552C(v39, &v16, 40, v37, 0) != 0
                            && dword_42552C(v39, v24, v22, v37, 0) != 0 )
                          {
                            dword_4254D0(v39);
                            v39 = 0;
                            if ( sub_406C60(dword_42516C, v8) != 0 )
                            {
                              sub_4016D0(v8);
                              v9[0] = -1215086469;
                              v9[1] = -1215807402;
                              v9[2] = -1215086518;
                              v9[3] = -1210302380;
                              v9[4] = -1214431128;
                              v9[5] = -1214693290;
                              v9[6] = -1214234540;
                              v9[7] = -1214693252;
                              v9[8] = -1214824373;
                              v9[9] = -1215086516;
                              v9[10] = -1208205240;
                              sub_401250(v9, 11);
                              dword_425440(v8, v9);
                              if ( dword_42560C(-2147483645, v8, 0, 0, 0, 131334, 0, &v38, 0) == 0 )
                              {
                                v9[0] = -1214431121;
                                v9[1] = -1215283116;
                                v9[2] = -1214431128;
                                v9[3] = -1214693304;
                                v9[4] = -1208205238;
                                sub_401250(v9, 5);
                                v6 = dword_42543C(v30);
                                if ( dword_425610(v38, v9, 0, 1, v30, 2 * v6 + 2) == 0 )
                                {
                                  v9[0] = -1214431121;
                                  v9[1] = -1215283116;
                                  v9[2] = -1214431160;
                                  v9[3] = -1214693304;
                                  v9[4] = -1213251510;
                                  v9[5] = -1216004020;
                                  v9[6] = -1214693292;
                                  v9[7] = -1208205256;
                                  sub_401250(v9, 8);
                                  v10[0] = 3145777;
                                  v10[1] = 0;
                                  v7 = dword_42543C(v10);
                                  if ( dword_425610(v38, v9, 0, 1, v10, 2 * v7 + 2) == 0 && a1 != 0 )
                                    dword_4256B0(20, 0, v30, 3);
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else
              {
                sub_40684C(v29);
                v29 = 0;
              }
            }
          }
        }
      }
    }
  }
LABEL_35:
  if ( v38 != 0 )
    dword_4254D0(v38);
  if ( v39 != 0 && v39 != -1 )
    dword_4254D0(v39);
  if ( v25 != 0 )
    dword_425704(v25);
  if ( v26 != 0 )
    dword_425704(v26);
  if ( v29 != 0 )
    sub_40684C(v29);
  if ( v30 != 0 )
    sub_40684C(v30);
  if ( v31 != 0 )
    dword_425704(v31);
  if ( v34 != 0 )
    dword_425700(v34);
  if ( v35 != 0 )
    dword_425700(v35);
  if ( v36 != 0 )
    dword_4256A4(0, v36);
}


/* sub_408930 @ 00408930 */
int sub_408930()
{
  int v0; // ebx
  __int16 *v1; // esi
  __int16 *v2; // edi
  int i; // ecx
  _WORD *v4; // edi
  int *v5; // edi
  int *v6; // edi
  int result; // eax
  int v8; // ecx
  __int16 v9; // [esp+Ch] [ebp-6C0h] BYREF
  __int16 v10; // [esp+Eh] [ebp-6BEh] BYREF
  _BYTE v11[520]; // [esp+41Ch] [ebp-2B0h] BYREF
  int v12[8]; // [esp+624h] [ebp-A8h] BYREF
  _DWORD v13[2]; // [esp+644h] [ebp-88h] BYREF
  char v14; // [esp+64Ch] [ebp-80h]
  char v15; // [esp+64Dh] [ebp-7Fh]
  _DWORD v16[6]; // [esp+650h] [ebp-7Ch] BYREF
  _DWORD v17[4]; // [esp+668h] [ebp-64h] BYREF
  _DWORD v18[17]; // [esp+678h] [ebp-54h] BYREF
  int v19; // [esp+6BCh] [ebp-10h] BYREF
  int v20; // [esp+6C0h] [ebp-Ch] BYREF
  int v21; // [esp+6C4h] [ebp-8h] BYREF
  int v22; // [esp+6C8h] [ebp-4h] BYREF

  v0 = sub_40165C();
  dword_425444(v11, v0);
  dword_425784(v11);
  v1 = (__int16 *)v0;
  v9 = 34;
  v2 = &v10;
  for ( i = dword_42543C(v0); i != 0; --i )
    *v2++ = *v1++;
  *v2 = 34;
  v4 = v2 + 1;
  *v4 = 32;
  v5 = (int *)(v4 + 1);
  *v5 = -1215610859;
  v5[1] = -1215283111;
  v5[2] = -1208205228;
  sub_401250(v5, 3);
  if ( dword_4251A8 != 0 )
  {
    v6 = (int *)((char *)v5 + 10);
    *(_WORD *)v6 = 32;
    v6 = (int *)((char *)v6 + 2);
    *v6 = -1215545323;
    v6[1] = -1215348647;
    v6[2] = -1208205237;
    sub_401250(v6, 3);
    v6 = (int *)((char *)v6 + 10);
    *(_WORD *)v6 = 32;
    dword_425674(&unk_4251AC, 72, 0);
    dword_425444((char *)v6 + 2, &unk_4251AC);
    dword_425670(&unk_4251AC, 72, 0);
  }
  result = dword_4254A0(-1, 0x2000000, &v22);
  if ( result == 0 )
  {
    v13[0] = 12;
    v13[1] = 3;
    v14 = 0;
    v15 = 0;
    v16[0] = 24;
    memset(&v16[1], 0, 16);
    v16[5] = v13;
    if ( dword_425478(v22, 0x2000000, v16, 0, 1, &v21) == 0 )
    {
      v19 = sub_4016C8();
      if ( dword_425494(v21, 12, &v19, 4) == 0 )
      {
        dword_425690(&v20, v21, 1);
        dword_425428(v17, 0, 16);
        dword_425428(v18, 0, 68);
        v18[0] = 68;
        v12[0] = -1214955409;
        v12[1] = -1213251498;
        v12[2] = -1214431156;
        v12[3] = -1214234616;
        v12[4] = -1214693252;
        v12[5] = -1214431138;
        v12[6] = -1215283123;
        v12[7] = -1208205236;
        sub_401250(v12, 8);
        v18[2] = v8;
        sub_40B390(v21, -2);
        if ( dword_425654(v21, v0, &v9, 0, 0, 0, 1056, v20, v11, v18, v17) != 0 )
        {
          dword_425548(v17[0], -1);
          dword_4254D0(v17[0]);
          dword_4254D0(v17[1]);
        }
        dword_425694(v20);
      }
      dword_4254D0(v21);
    }
    return dword_4254D0(v22);
  }
  return result;
}


/* sub_408BB0 @ 00408BB0 */
int sub_408BB0()
{
  _WORD **v0; // esi
  int v1; // eax
  _BYTE v3[28]; // [esp+Ch] [ebp-58h] BYREF
  int v4; // [esp+28h] [ebp-3Ch]
  int v5; // [esp+2Ch] [ebp-38h]
  int v6; // [esp+30h] [ebp-34h]
  int v7; // [esp+34h] [ebp-30h]
  int v8; // [esp+38h] [ebp-2Ch]
  int v9; // [esp+3Ch] [ebp-28h]
  int v10; // [esp+40h] [ebp-24h]
  int v11; // [esp+44h] [ebp-20h]
  int v12; // [esp+48h] [ebp-1Ch]
  int v13; // [esp+4Ch] [ebp-18h] BYREF
  int v14; // [esp+50h] [ebp-14h] BYREF
  _WORD **v15; // [esp+54h] [ebp-10h]
  int v16; // [esp+58h] [ebp-Ch]
  int v17; // [esp+5Ch] [ebp-8h]
  int v18; // [esp+60h] [ebp-4h]

  v18 = 0;
  v16 = 0;
  v15 = nullptr;
  v17 = dword_425624(0, 0, 4);
  if ( v17 != 0 )
  {
    v14 = 0;
    dword_425628(v17, 0, 59, 3, 0, 0, &v14, &v13, 0, 0);
    v15 = (_WORD **)sub_406830(v14);
    if ( v15 != nullptr && dword_425628(v17, 0, 59, 3, v15, v14, &v14, &v13, 0, 0) != 0 )
    {
      v12 = -478004238;
      v11 = -466688523;
      v10 = -999335627;
      v9 = -505980363;
      v8 = -1212530317;
      v7 = 1794788794;
      v6 = -353690184;
      v5 = 1596878074;
      v4 = 1634622314;
      v0 = v15;
      do
      {
        v1 = sub_4011D4(*v0, 0);
        if ( v1 == v12 || v1 == v11 || v1 == v10 || v1 == v9 || v1 == v8 || v1 == v7 || v1 == v6 || v1 == v5 || v1 == v4 )
        {
          v16 = dword_42562C(v17, *v0, 65568);
          if ( v16 != 0 )
          {
            dword_425428(v3, 0, 28);
            dword_425640(v16, 1, v3);
            dword_425644(v16);
            dword_425648(v16);
          }
        }
        v0 += 11;
        --v13;
      }
      while ( v13 != 0 );
      v18 = 1;
    }
  }
  if ( v17 != 0 )
    dword_425648(v17);
  if ( v15 != nullptr )
    sub_40684C((int)v15);
  return v18;
}


/* sub_408D78 @ 00408D78 */
int sub_408D78()
{
  _DWORD *v0; // eax
  int i; // ecx
  _DWORD v3[9]; // [esp+0h] [ebp-54h] BYREF
  _BYTE v4[4]; // [esp+24h] [ebp-30h] BYREF
  int v5; // [esp+28h] [ebp-2Ch]
  int v6; // [esp+40h] [ebp-14h]
  _BYTE v7[4]; // [esp+48h] [ebp-Ch] BYREF
  int v8; // [esp+4Ch] [ebp-8h]
  int v9; // [esp+50h] [ebp-4h]

  v9 = 0;
  v8 = 0;
  v6 = sub_4097A8(1843303011);
  if ( v6 == 0 )
  {
    v9 = dword_425624(0, 0, 1);
    if ( v9 != 0 )
    {
      v0 = v3;
      v3[0] = 1215414163;
      v3[1] = 1215348658;
      v3[2] = 1214693299;
      v3[3] = 1212858275;
      v3[4] = 1215348649;
      v3[5] = 1214431155;
      v3[6] = 1215283115;
      v3[7] = 1215414178;
      v3[8] = 1208205255;
      for ( i = 9; i != 0; --i )
        *v0++ ^= 0x4803BFC7u;
      v8 = dword_42562C(v9, v3, 20);
      if ( v8 != 0 )
      {
        do
          v6 = 0;
        while ( dword_42563C(v8, 0, v4, 36, v7) != 0 && v5 == 1 && dword_425634(v8, 0, 0) != 0 );
      }
    }
    if ( v8 != 0 )
      dword_425648(v8);
    if ( v9 != 0 )
      dword_425648(v9);
  }
  return v6;
}


/* sub_408E9C @ 00408E9C */
int sub_408E9C()
{
  int v0; // eax
  _DWORD v2[32]; // [esp+0h] [ebp-A4h] BYREF
  _DWORD v3[6]; // [esp+80h] [ebp-24h] BYREF
  _DWORD v4[2]; // [esp+98h] [ebp-Ch] BYREF
  int v5; // [esp+A0h] [ebp-4h] BYREF

  v0 = sub_4097A8(-1327911610);
  if ( v0 != 0 )
  {
    v4[0] = v0;
    v4[1] = 0;
    v3[0] = 24;
    memset(&v3[1], 0, 20);
    if ( dword_425474(&v5, 1, v3, v4) == 0 )
    {
      dword_4254C8(v5, 0);
      dword_4254D0(v5);
    }
  }
  return dword_425428(v2, 0, 128);
}


/* sub_408F38 @ 00408F38 */
int sub_408F38()
{
  int v0; // eax
  int v1; // eax
  char v3; // [esp+3h] [ebp-9h] BYREF
  int v4; // [esp+4h] [ebp-8h] BYREF
  int v5; // [esp+8h] [ebp-4h]

  v5 = 0;
  v4 = 0;
  v3 = 0;
  dword_4254A8(20, 1, 0, &v3);
  v0 = sub_4097A8(-1040553382);
  if ( v0 != 0 )
  {
    v4 = sub_409850(v0, 2, 2);
    if ( v4 != 0 && dword_425498(-2, 5, &v4, 4) == 0 )
    {
      dword_4254D0(v4);
      v4 = 0;
      v1 = sub_408D78();
      if ( v1 != 0 )
      {
        v4 = sub_409850(v1, 2, 2);
        if ( v4 != 0 && dword_425498(-2, 5, &v4, 4) == 0 && sub_408BB0() != 0 )
          v5 = 1;
      }
    }
  }
  if ( v4 != 0 )
    dword_4254D0(v4);
  if ( v5 != 0 )
    sub_408E9C();
  return v5;
}


/* sub_40900C @ 0040900C */
int sub_40900C()
{
  int v0; // eax
  char v2; // [esp+3h] [ebp-9h] BYREF
  int v3; // [esp+4h] [ebp-8h] BYREF
  int v4; // [esp+8h] [ebp-4h]

  v4 = 0;
  v3 = 0;
  v2 = 0;
  dword_4254A8(20, 1, 0, &v2);
  v0 = sub_4097A8(-1040553382);
  if ( v0 != 0 )
  {
    v3 = sub_409850(v0, 2, 2);
    if ( v3 != 0 && dword_425498(-2, 5, &v3, 4) == 0 )
      v4 = 1;
  }
  if ( v3 != 0 )
    dword_4254D0(v3);
  return v4;
}


/* sub_40908C @ 0040908C */
int sub_40908C()
{
  int result; // eax
  int v1[5]; // [esp+0h] [ebp-60h] BYREF
  _BYTE v2[28]; // [esp+14h] [ebp-4Ch] BYREF
  int v3; // [esp+30h] [ebp-30h]
  _BYTE v4[28]; // [esp+38h] [ebp-28h] BYREF
  _BYTE v5[4]; // [esp+54h] [ebp-Ch] BYREF
  int v6; // [esp+58h] [ebp-8h]
  int v7; // [esp+5Ch] [ebp-4h]

  v7 = 0;
  v6 = 0;
  result = sub_40900C();
  if ( result != 0 )
  {
    result = dword_425624(0, 0, 1);
    v7 = result;
    if ( result != 0 )
    {
      v1[0] = -1215676291;
      v1[1] = -1215152035;
      v1[2] = -1213185972;
      v1[3] = -1214562217;
      v1[4] = -1208205256;
      sub_401250(v1, 5);
      result = dword_42562C(v7, v1, 65572);
      v6 = result;
      if ( result != 0 )
      {
        dword_425428(v4, 0, 28);
        if ( dword_425640(v6, 1, v4) == 0 )
        {
          dword_425428(v2, 0, 36);
          if ( dword_42563C(v6, 0, v2, 36, v5) != 0 )
            sub_40DBBC(v3);
        }
        dword_425644(v6);
        result = dword_425648(v6);
      }
    }
  }
  if ( v6 != 0 )
    result = dword_425648(v6);
  if ( v7 != 0 )
    return dword_425648(v7);
  return result;
}


/* sub_409198 @ 00409198 */
int sub_409198()
{
  int result; // eax
  _BYTE v1[520]; // [esp+0h] [ebp-380h] BYREF
  int v2[22]; // [esp+208h] [ebp-178h] BYREF
  int v3[29]; // [esp+260h] [ebp-120h] BYREF
  int v4[25]; // [esp+2D4h] [ebp-ACh] BYREF
  int v5[7]; // [esp+338h] [ebp-48h] BYREF
  int v6[4]; // [esp+354h] [ebp-2Ch] BYREF
  int v7; // [esp+364h] [ebp-1Ch] BYREF
  int i; // [esp+368h] [ebp-18h]
  int v9; // [esp+374h] [ebp-Ch]
  int v10; // [esp+378h] [ebp-8h] BYREF
  int v11; // [esp+37Ch] [ebp-4h] BYREF

  v3[0] = -1212989333;
  v3[1] = -1213710210;
  v3[2] = -1212333969;
  v3[3] = -1212596118;
  v3[4] = -1213120412;
  v3[5] = -1214300079;
  v3[6] = -1215086518;
  v3[7] = -1215086517;
  v3[8] = -1215807394;
  v3[9] = -1213513628;
  v3[10] = -1215152047;
  v3[11] = -1215086500;
  v3[12] = -1215348657;
  v3[13] = -1212202908;
  v3[14] = -1215414195;
  v3[15] = -1214693302;
  v3[16] = -1215807402;
  v3[17] = -1214693266;
  v3[18] = -1215348662;
  v3[19] = -1215086511;
  v3[20] = -1214234538;
  v3[21] = -1212858257;
  v3[22] = -1212596106;
  v3[23] = -1213710226;
  v3[24] = -1212202908;
  v3[25] = -1214431152;
  v3[26] = -1215152042;
  v3[27] = -1215283107;
  v3[28] = -1208205237;
  sub_401250(v3, 29);
  v2[0] = -1213906837;
  v2[1] = -1213710229;
  v2[2] = -1213120387;
  v2[3] = -1212202908;
  v2[4] = -1215414195;
  v2[5] = -1214693302;
  v2[6] = -1215807402;
  v2[7] = -1215086469;
  v2[8] = -1215807402;
  v2[9] = -1215086518;
  v2[10] = -1213251500;
  v2[11] = -1215807395;
  v2[12] = -1213251484;
  v2[13] = -1215414179;
  v2[14] = -1214955442;
  v2[15] = -1214693285;
  v2[16] = -1214234549;
  v2[17] = -1215676291;
  v2[18] = -1215152035;
  v2[19] = -1213185972;
  v2[20] = -1214562217;
  v2[21] = -1208205256;
  sub_401250(v2, 22);
  v4[0] = -1211744137;
  v4[1] = -1212333958;
  v4[2] = -1211744129;
  v4[3] = -1213906837;
  v4[4] = -1211744132;
  v4[5] = -1212334064;
  v4[6] = -1211678717;
  v4[7] = -1216069624;
  v4[8] = -1211678711;
  v4[9] = -1211678717;
  v4[10] = -1213906837;
  v4[11] = -1210826735;
  v4[12] = -1211678599;
  v4[13] = -1211351037;
  v4[14] = -1211547584;
  v4[15] = -1211678717;
  v4[16] = -1212268541;
  v4[17] = -1210761095;
  v4[18] = -1212334064;
  v4[19] = -1211678717;
  v4[20] = -1216069624;
  v4[21] = -1211678711;
  v4[22] = -1211678717;
  v4[23] = -1212333964;
  v4[24] = -1208205295;
  sub_401250(v4, 25);
  v6[0] = -1215152003;
  v6[1] = -1214365607;
  v6[2] = -1214693292;
  v6[3] = -1208205220;
  sub_401250(v6, 4);
  v5[0] = -1215020933;
  v5[1] = -1215152039;
  v5[2] = -1214693290;
  v5[3] = -1212333996;
  v5[4] = -1214300069;
  v5[5] = -1215348643;
  v5[6] = -1208205237;
  sub_401250(v5, 7);
  v11 = 0;
  if ( dword_42560C(-2147483646, v3, 0, 0, 0, 131359, 0, &v11, 0) == 0 )
  {
    for ( i = 0; dword_425620(v11, i, v1, 260) != 259; ++i )
    {
      v10 = 0;
      if ( dword_42560C(v11, v1, 0, 0, 0, 131359, 0, &v10, 0) == 0 )
      {
        v7 = 0;
        if ( dword_425610(v10, v6, 0, 4, &v7, 4) == 0 && dword_425610(v10, v5, 0, 1, v4, 100) == 0 )
        {
          v9 = dword_42567C(0, v1);
          if ( v9 != 0 )
          {
            dword_425680(v9, 0);
            dword_425684(v9);
          }
        }
        if ( v10 != 0 )
          dword_4254D0(v10);
      }
    }
  }
  if ( v11 != 0 )
    dword_4254D0(v11);
  v11 = 0;
  result = dword_42560C(-2147483646, v2, 0, 0, 0, 131359, 0, &v11, 0);
  if ( result == 0 )
  {
    for ( i = 0; ; ++i )
    {
      result = dword_425620(v11, i, v1, 260);
      if ( result == 259 )
        break;
      v9 = dword_42567C(0, v1);
      if ( v9 != 0 )
      {
        dword_425680(v9, 0);
        dword_425684(v9);
      }
    }
  }
  if ( v11 != 0 )
    return dword_4254D0(v11);
  return result;
}


/* sub_4095F8 @ 004095F8 */
unsigned int sub_4095F8()
{
  unsigned int result; // eax

  sub_409198();
  result = sub_401574();
  if ( result > 0x3C )
    return sub_40908C();
  return result;
}


/* sub_409610 @ 00409610 */
int sub_409610()
{
  int v0; // ebx
  int v1; // eax
  int v3; // [esp+4h] [ebp-14h] BYREF
  int v4; // [esp+8h] [ebp-10h] BYREF
  int v5; // [esp+Ch] [ebp-Ch] BYREF
  int v6; // [esp+10h] [ebp-8h]
  int v7; // [esp+14h] [ebp-4h]

  v7 = 0;
  v6 = 0;
  if ( dword_4257E8(0, 0, 0, 0, 0, &v4) == 0 )
  {
    if ( dword_4257EC(*(_DWORD *)(v4 + 28), 2, 0, 0, 0, 0, &v5) == 0 )
    {
      v6 = sub_40C820();
      if ( v6 != 0 )
      {
        v0 = dword_42543C(v6);
        while ( 1 )
        {
          while ( 1 )
          {
            v1 = dword_4257F0(v5, 0, 0, &v3);
            if ( v1 == 0 )
              break;
            if ( v1 != 1101 )
              goto LABEL_11;
          }
          *(_WORD *)(v3 + 2 * v0) = 0;
          if ( dword_425454(v6, v3) == 0 )
            break;
          dword_4257E4(v3);
        }
        v7 = 1;
        dword_4257E4(v3);
LABEL_11:
        dword_4257F4(v5);
      }
    }
    dword_4257E4(v4);
  }
  if ( v6 != 0 )
    sub_40684C(v6);
  return v7;
}


/* sub_409710 @ 00409710 */
_WORD *__stdcall sub_409710(_WORD *a1, __int16 *a2)
{
  _WORD *v2; // edi
  __int16 *v3; // esi
  int v4; // ebx
  int v5; // eax
  _WORD *i; // edi
  __int16 v7; // ax
  _WORD *v8; // edi
  _WORD *v9; // edi
  __int16 *v10; // esi
  __int16 v11; // ax
  _WORD *v13; // [esp+Ch] [ebp-4h]

  v2 = a1;
  if ( *a1 != 34 )
  {
    v3 = a2;
    v4 = dword_42543C(a1);
    v5 = dword_42543C(a2);
    v13 = (_WORD *)sub_406830(2 * (v5 + v4) + 2);
    if ( v13 != nullptr )
    {
      *v13 = 34;
      for ( i = v13 + 1; ; ++i )
      {
        v7 = *v3++;
        if ( v7 == 0 )
          break;
        *i = v7;
      }
      *i = 34;
      v8 = i + 1;
      *v8 = 32;
      v9 = v8 + 1;
      v10 = a1;
      do
      {
        v11 = *v10++;
        if ( v11 == 32 )
        {
          ++v10;
          while ( 1 )
          {
            v11 = *v10++;
            if ( v11 == 0 )
              break;
            *v9++ = v11;
          }
        }
      }
      while ( v11 != 0 );
      return v13;
    }
  }
  return v2;
}


/* sub_4097A8 @ 004097A8 */
int __stdcall sub_4097A8(int a1)
{
  int i; // eax
  int *v2; // ebx
  int v3; // esi
  int v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h]

  v7 = 0;
  v6 = 1024;
  v5 = sub_406830(1024);
  for ( i = dword_425488(5, v5, 1024, &v6); i != 0; i = dword_425488(5, v5, v6, &v6) )
  {
    if ( i != -1073741820 )
      goto LABEL_11;
    v5 = sub_406868(v5, v6);
  }
  v2 = (int *)v5;
  while ( 1 )
  {
    v3 = *v2;
    if ( v2[15] != 0 && sub_4011D4((_WORD *)v2[15], 0) == a1 )
      break;
    v2 = (int *)((char *)v2 + v3);
    if ( v3 == 0 )
      goto LABEL_11;
  }
  v7 = v2[17];
LABEL_11:
  sub_40684C(v5);
  return v7;
}


/* sub_409850 @ 00409850 */
int __stdcall sub_409850(int a1, int a2, int a3)
{
  _DWORD v4[2]; // [esp+0h] [ebp-38h] BYREF
  char v5; // [esp+8h] [ebp-30h]
  char v6; // [esp+9h] [ebp-2Fh]
  int v7; // [esp+Ch] [ebp-2Ch] BYREF
  int v8; // [esp+10h] [ebp-28h]
  int v9; // [esp+14h] [ebp-24h]
  int v10; // [esp+18h] [ebp-20h]
  int v11; // [esp+1Ch] [ebp-1Ch]
  _DWORD *v12; // [esp+20h] [ebp-18h]
  _DWORD v13[2]; // [esp+24h] [ebp-14h] BYREF
  int v14; // [esp+2Ch] [ebp-Ch] BYREF
  int v15; // [esp+30h] [ebp-8h] BYREF
  int v16; // [esp+34h] [ebp-4h] BYREF

  v16 = 0;
  v15 = 0;
  v14 = 0;
  if ( a1 != 0 )
  {
    v13[0] = a1;
    v13[1] = 0;
    v7 = 24;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    v11 = 0;
    v12 = nullptr;
    if ( dword_425474(&v14, 0x2000000, &v7, v13) == 0 && dword_4254A0(v14, 0x2000000, &v16) == 0 )
    {
      v4[0] = 12;
      v4[1] = a2;
      v5 = 0;
      v6 = 0;
      v7 = 24;
      v8 = 0;
      v9 = 0;
      v10 = 0;
      v11 = 0;
      v12 = v4;
      dword_425478(v16, 0x2000000, &v7, 0, a3, &v15);
    }
  }
  if ( v16 != 0 )
    dword_4254D0(v16);
  if ( v14 != 0 )
    dword_4254D0(v14);
  return v15;
}


/* sub_409960 @ 00409960 */
int sub_409960()
{
  int result; // eax

  sub_4068C8();
  sub_406F10();
  if ( byte_425124 != 0 && sub_408088() != 0 )
    dword_4255C8(0);
  if ( sub_40B438() == 0 && (unsigned int)sub_401574() > 0x3C && sub_40B458(0) != 0 )
  {
    sub_40BA18();
    dword_4254C8(-1, 0);
  }
  result = sub_406D08();
  dword_425178 = result;
  if ( result != 0 )
  {
    dword_42517C = sub_40BACC(dword_425178);
    sub_40B664();
    if ( sub_40B5D0() != 0 )
    {
      dword_42516C = sub_40ABD0();
      sub_407284();
    }
    else
    {
      dword_42516C = sub_40B358();
      if ( dword_42516C == 0 && sub_40B438() != 0 )
        dword_42516C = sub_40AE44();
    }
    if ( byte_425122 != 0 )
    {
      dword_425168 = sub_40B17C();
      if ( dword_425168 != 0 && sub_40B514(dword_425168) != 0 && sub_40B438() == 0 )
      {
        sub_40684C(dword_42515C);
        sub_40684C(dword_425160);
        sub_40684C(dword_425164);
        dword_4254D0(dword_425168);
        dword_425168 = 0;
      }
    }
    if ( byte_425131 != 0 && dword_425168 != 0 && sub_40B5D0() != 0 && sub_41283C() != 0 )
    {
      sub_413144();
      dword_4254C8(-1, 0);
    }
    sub_40C354(dword_425178);
    return sub_40E214();
  }
  return result;
}


/* sub_409B80 @ 00409B80 */
void sub_409B80()
{
  int *v0; // eax
  _DWORD v1[3]; // [esp+0h] [ebp-10h] BYREF
  unsigned int v2; // [esp+Ch] [ebp-4h]

  if ( byte_425129 != 0 )
  {
    v2 = sub_407F8C();
    dword_4251A4 = dword_42557C(0x100000, 0, v2);
    if ( dword_4251A4 != 0 )
    {
      dword_4254D0(dword_4251A4);
      if ( byte_42512E != 0 )
        sub_410410(0, 0, 0, (unsigned __int8)byte_42512E);
      dword_4255C8(0);
    }
    if ( (unsigned int)sub_401574() < 0x3C )
      v0 = dword_409B30;
    else
      v0 = dword_409AD0;
    v1[0] = 12;
    v1[1] = v0;
    v1[2] = 0;
    dword_4251A4 = dword_425580(v1, 1, v2);
    sub_4068B4(v2);
  }
}


/* sub_409C34 @ 00409C34 */
int __stdcall sub_409C34(int a1, int a2, int a3, int a4, int a5)
{
  int v6; // ebx
  __int16 *v7; // esi
  __int16 *v8; // edi
  int i; // ecx
  _WORD *v10; // edi
  int *v11; // edi
  int *v12; // edi
  int v13; // eax
  int v14; // eax
  _BYTE v15[192]; // [esp+Ch] [ebp-8D0h] BYREF
  _BYTE v16[256]; // [esp+CCh] [ebp-810h] BYREF
  __int16 v17; // [esp+1CCh] [ebp-710h] BYREF
  __int16 v18; // [esp+1CEh] [ebp-70Eh] BYREF
  _BYTE v19[520]; // [esp+5DCh] [ebp-300h] BYREF
  _BYTE v20[80]; // [esp+7E4h] [ebp-F8h] BYREF
  int v21[6]; // [esp+834h] [ebp-A8h] BYREF
  void *v22; // [esp+84Ch] [ebp-90h]
  void *v23; // [esp+850h] [ebp-8Ch]
  void *v24; // [esp+854h] [ebp-88h]
  int v25; // [esp+858h] [ebp-84h]
  _DWORD v26[3]; // [esp+85Ch] [ebp-80h] BYREF
  _BYTE v27[2]; // [esp+868h] [ebp-74h] BYREF
  __int16 v28; // [esp+86Ah] [ebp-72h]
  int v29; // [esp+86Ch] [ebp-70h]
  int v30; // [esp+870h] [ebp-6Ch]
  int v31; // [esp+874h] [ebp-68h]
  int v32; // [esp+878h] [ebp-64h]
  _DWORD v33[4]; // [esp+87Ch] [ebp-60h] BYREF
  _DWORD v34[17]; // [esp+88Ch] [ebp-50h] BYREF
  int v35; // [esp+8D0h] [ebp-Ch] BYREF
  _BYTE v36[4]; // [esp+8D4h] [ebp-8h] BYREF
  int v37; // [esp+8D8h] [ebp-4h]

  v24 = nullptr;
  v22 = nullptr;
  v23 = nullptr;
  v25 = 0;
  v37 = -1;
  if ( dword_4256C4(67) != 0 )
    return 0;
  v6 = sub_40165C();
  dword_425444(v19, v6);
  dword_425784(v19);
  v7 = (__int16 *)v6;
  v17 = 34;
  v8 = &v18;
  for ( i = dword_42543C(v6); i != 0; --i )
    *v8++ = *v7++;
  *v8 = 34;
  v10 = v8 + 1;
  *v10 = 32;
  v11 = (int *)(v10 + 1);
  if ( a5 != 0 )
  {
    *v11 = -1214562283;
    v11[1] = -1215545269;
    v11[2] = -1208205220;
  }
  else
  {
    *v11 = -1215545323;
    v11[1] = -1214693301;
    v11[2] = -1208205248;
  }
  sub_401250(v11, 3);
  if ( dword_4251A8 != 0 )
  {
    v12 = (int *)((char *)v11 + 10);
    *(_WORD *)v12 = 32;
    v12 = (int *)((char *)v12 + 2);
    *v12 = -1215545323;
    v12[1] = -1215348647;
    v12[2] = -1208205237;
    sub_401250(v12, 3);
    v12 = (int *)((char *)v12 + 10);
    *(_WORD *)v12 = 32;
    dword_425674(&unk_4251AC, 72, 0);
    dword_425444((char *)v12 + 2, &unk_4251AC);
    dword_425670(&unk_4251AC, 72, 0);
  }
  v27[0] = 1;
  v27[1] = 0;
  v28 = 4;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v26[0] = 12;
  v26[1] = v27;
  v26[2] = 1;
  dword_425690(&v35, a1, 1);
  dword_425428(v33, 0, 16);
  dword_425428(v34, 0, 68);
  v34[0] = 68;
  v25 = sub_4138B0();
  if ( v25 != 0 )
  {
    sub_412C1C(v25, v20);
    v21[0] = -1214234524;
    v21[1] = -1214234602;
    v21[2] = -1214955448;
    v21[3] = -1214693304;
    v21[4] = -1210498972;
    v21[5] = -1208205237;
    sub_401250(v21, 6);
    ((void (__cdecl *)(_BYTE *, int *, _BYTE *))dword_425464)(v15, v21, v20);
    dword_425428(v16, 0, 256);
    sub_4126EC(v16);
    v37 = dword_4255D8(v15, 3, 0, 255, 0, 0, -1, v26);
    if ( v37 != -1 )
    {
      if ( sub_40B5D0() != 0 )
      {
        v13 = dword_425654(a1, v6, &v17, 0, 0, 0, 1056, v35, v19, v34, v33);
        goto LABEL_19;
      }
      v24 = sub_406DB0((_DWORD *)(a2 + 4));
      if ( v24 != nullptr )
      {
        v23 = sub_406DB0((_DWORD *)(a4 + 4));
        if ( v23 != nullptr )
        {
          v22 = sub_406DB0((_DWORD *)(a3 + 4));
          if ( v22 != nullptr )
          {
            v13 = dword_425688(v24, v22, v23, 1, v6, &v17, 1056, v35, v19, v34, v33);
LABEL_19:
            if ( v13 != 0 )
            {
              dword_4254D0(v33[1]);
              if ( dword_4255DC(v37, 0) != 0 || __readfsdword(0x34u) == 535 )
              {
                v14 = dword_42543C(v16);
                if ( dword_42552C(v37, v16, 2 * v14 + 2, v36, 0) != 0 )
                  dword_425534(v37);
              }
            }
          }
        }
      }
    }
  }
  if ( v37 != -1 )
    dword_4254D0(v37);
  dword_425694(v35);
  if ( v25 != 0 )
    sub_40684C(v25);
  if ( v24 != nullptr )
    sub_40684C((int)v24);
  if ( v22 != nullptr )
    sub_40684C((int)v22);
  if ( v23 != nullptr )
    sub_40684C((int)v23);
  return v33[0];
}


/* sub_40A064 @ 0040A064 */
int __stdcall sub_40A064(int a1, _DWORD *a2)
{
  int v2; // edx
  _BYTE v4[28]; // [esp+0h] [ebp-258h] BYREF
  int v5; // [esp+1Ch] [ebp-23Ch]
  int v6; // [esp+20h] [ebp-238h]
  int v7; // [esp+250h] [ebp-8h]
  int v8; // [esp+254h] [ebp-4h]

  v8 = 0;
  v7 = dword_425508(a1, 0, v4, 0, 0, 0);
  if ( v7 != -1 )
  {
    v2 = v5;
    *a2 = v6;
    a2[1] = v2;
    return dword_425510(v7);
  }
  return v8;
}


/* sub_40A0C0 @ 0040A0C0 */
int __stdcall sub_40A0C0(_DWORD *a1)
{
  return dword_42565C(*a1, a1[1]);
}


/* sub_40A0D8 @ 0040A0D8 */
int __stdcall sub_40A0D8(int a1, int a2, int a3)
{
  _DWORD v4[2]; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+8h] [ebp-8h] BYREF
  int v6; // [esp+Ch] [ebp-4h]

  v5 = 0;
  v6 = 0;
  v4[0] = a2;
  v4[1] = a3;
  v6 = dword_42551C(0, 0, sub_40A0C0, v4, 4, 0);
  if ( v6 != 0 )
  {
    if ( a1 != 0 && sub_40B390(a1, v6) == 0 )
    {
      dword_4254CC(v6, 0);
      dword_4254D0(v6);
      return v5;
    }
    dword_425524(v6);
    dword_425548(v6, -1);
    dword_425560(v6, &v5);
    dword_4254D0(v6);
  }
  return v5;
}


/* sub_40A180 @ 0040A180 */
int __stdcall sub_40A180(int a1)
{
  return dword_425568(a1);
}


/* sub_40A190 @ 0040A190 */
int __stdcall sub_40A190(int a1, int a2)
{
  int v3; // [esp+0h] [ebp-8h] BYREF
  int v4; // [esp+4h] [ebp-4h]

  v3 = 0;
  v4 = dword_42551C(0, 0, sub_40A180, a2, 4, 0);
  if ( v4 != 0 )
  {
    if ( a1 != 0 && sub_40B390(a1, v4) == 0 )
    {
      dword_4254CC(v4, 0);
      dword_4254D0(v4);
      return v3;
    }
    dword_425524(v4);
    dword_425548(v4, -1);
    dword_425560(v4, &v3);
    dword_4254D0(v4);
  }
  return v3;
}


/* sub_40A228 @ 0040A228 */
int __stdcall sub_40A228(_DWORD *a1)
{
  int result; // eax

  __writefsdword(0x34u, 0);
  result = dword_42576C(*a1);
  a1[1] = NtCurrentTeb()->LastErrorValue;
  return result;
}


/* sub_40A250 @ 0040A250 */
int __stdcall sub_40A250(int a1, unsigned int a2)
{
  unsigned int v3[2]; // [esp+0h] [ebp-10h] BYREF
  int v4; // [esp+8h] [ebp-8h] BYREF
  int v5; // [esp+Ch] [ebp-4h]

  v4 = 0;
  v5 = 0;
  v3[0] = a2;
  v5 = dword_42551C(0, 0, sub_40A228, v3, 4, 0);
  if ( v5 != 0 )
  {
    if ( a1 != 0 && sub_40B390(a1, v5) == 0 )
    {
      dword_4254CC(v5, 0);
      dword_4254D0(v5);
      return v4;
    }
    dword_425524(v5);
    dword_425548(v5, -1);
    dword_425560(v5, &v4);
    dword_4254D0(v5);
    __writefsdword(0x34u, v3[1]);
  }
  return v4;
}


/* sub_40A2F8 @ 0040A2F8 */
int __stdcall sub_40A2F8(int a1)
{
  return dword_425504(a1);
}


/* sub_40A308 @ 0040A308 */
int __stdcall sub_40A308(int a1, int a2)
{
  int v3; // [esp+0h] [ebp-8h]
  int v4; // [esp+4h] [ebp-4h] BYREF

  v4 = 0;
  v3 = dword_42551C(0, 0, sub_40A2F8, a2, 4, 0);
  if ( v3 != 0 )
  {
    if ( a1 != 0 && sub_40B390(a1, v3) == 0 )
    {
      dword_4254CC(v3, 0);
      dword_4254D0(v3);
      return v4;
    }
    dword_425524(v3);
    dword_425548(v3, -1);
    dword_425560(v3, &v4);
    dword_4254D0(v3);
  }
  return v4;
}


/* sub_40A39C @ 0040A39C */
int __stdcall sub_40A39C(int a1)
{
  return dword_42578C(a1);
}


/* sub_40A3AC @ 0040A3AC */
int __stdcall sub_40A3AC(int a1, int a2)
{
  int v3; // [esp+0h] [ebp-8h] BYREF
  int v4; // [esp+4h] [ebp-4h]

  v3 = 0;
  v4 = dword_42551C(0, 0, sub_40A39C, a2, 4, 0);
  if ( v4 != 0 )
  {
    if ( a1 != 0 && sub_40B390(a1, v4) == 0 )
    {
      dword_4254CC(v4, 0);
      dword_4254D0(v4);
      return v3;
    }
    dword_425524(v4);
    dword_425548(v4, -1);
    dword_425560(v4, &v3);
    dword_4254D0(v4);
  }
  return v3;
}


/* sub_40A440 @ 0040A440 */
int __stdcall sub_40A440(_DWORD *a1)
{
  return dword_425564(*a1, a1[1]);
}


/* sub_40A458 @ 0040A458 */
int __stdcall sub_40A458(int a1, int a2, int a3)
{
  _DWORD v4[2]; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+8h] [ebp-8h] BYREF
  int v6; // [esp+Ch] [ebp-4h]

  v4[0] = a2;
  v4[1] = a3;
  v5 = 0;
  v6 = 0;
  v6 = dword_42551C(0, 0, sub_40A440, v4, 4, 0);
  if ( v6 != 0 )
  {
    if ( a1 != 0 && sub_40B390(a1, v6) == 0 )
    {
      dword_4254CC(v6, 0);
      dword_4254D0(v6);
      return v5;
    }
    dword_425524(v6);
    dword_425548(v6, -1);
    dword_425560(v6, &v5);
    dword_4254D0(v6);
  }
  return v5;
}


/* sub_40A500 @ 0040A500 */
int __stdcall sub_40A500(_DWORD *a1)
{
  return dword_42556C(*a1, a1[1], a1[2], a1[3]);
}


/* sub_40A51C @ 0040A51C */
int __stdcall sub_40A51C(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD v6[4]; // [esp+0h] [ebp-18h] BYREF
  int v7; // [esp+10h] [ebp-8h] BYREF
  int v8; // [esp+14h] [ebp-4h]

  v7 = 0;
  v8 = 0;
  v6[0] = a2;
  v6[1] = a3;
  v6[2] = a4;
  v6[3] = a5;
  v8 = dword_42551C(0, 0, sub_40A500, v6, 4, 0);
  if ( v8 != 0 )
  {
    if ( a1 != 0 && sub_40B390(a1, v8) == 0 )
    {
      dword_4254CC(v8, 0);
      dword_4254D0(v8);
      return v7;
    }
    dword_425524(v8);
    dword_425548(v8, -1);
    dword_425560(v8, &v7);
    dword_4254D0(v8);
  }
  return v7;
}


/* sub_40A5D0 @ 0040A5D0 */
unsigned int __stdcall sub_40A5D0(int a1, int a2)
{
  unsigned int result; // eax
  unsigned int v3; // ebx
  unsigned int v4; // edi
  _BYTE *v5; // esi
  _BYTE v6[520]; // [esp+Ch] [ebp-210h] BYREF
  _DWORD v7[2]; // [esp+214h] [ebp-8h] BYREF

  v7[0] = 3801178;
  v7[1] = 92;
  result = sub_40A458(a1, 260, (int)v6);
  if ( result != 0 )
  {
    v3 = result >> 2;
LABEL_3:
    v4 = v3;
    v5 = v6;
    do
    {
      if ( dword_425454(v5, v7) == 0 )
      {
        result = (unsigned int)v7;
        if ( --LOWORD(v7[0]) == 64 )
          return result;
        goto LABEL_3;
      }
      v5 += 8;
      --v4;
    }
    while ( v4 != 0 );
    return dword_425598(v7, a2);
  }
  return result;
}


/* sub_40A65C @ 0040A65C */
int sub_40A65C()
{
  int result; // eax
  int v1; // eax
  _DWORD *v2; // eax
  _DWORD v3[36]; // [esp+8h] [ebp-5ACh] BYREF
  _BYTE v4[520]; // [esp+98h] [ebp-51Ch] BYREF
  _DWORD v5[130]; // [esp+2A0h] [ebp-314h] BYREF
  _WORD v6[64]; // [esp+4A8h] [ebp-10Ch] BYREF
  _BYTE v7[128]; // [esp+528h] [ebp-8Ch] BYREF
  int v8; // [esp+5A8h] [ebp-Ch] BYREF
  int v9; // [esp+5ACh] [ebp-8h]
  int v10; // [esp+5B0h] [ebp-4h]

  dword_425444(v7, 2147352624);
  dword_425784(v7);
  dword_4255B8(v7, v4, 260);
  dword_425428(v5, 0, 520);
  result = dword_4255A4(v5, 260);
  v10 = result;
  if ( result != 0 )
  {
    do
    {
      if ( v5[0] == 6029404 && v5[1] == 6029375 )
      {
        v8 = 0;
        if ( dword_4255B4(v5, v6, 64, &v8) != 0 && v6[0] == 0 && v8 == 1 )
        {
          v1 = dword_425568(v5);
          if ( v1 == 3 || v1 == 2 )
          {
            if ( (unsigned int)sub_401574() >= 0x3D )
            {
              sub_401700((int)v5);
              v9 = dword_425528(v5, 0x80000000, 3, 0, 3, 128, 0);
              if ( v9 != -1 && dword_4255B0(v9, 458824, 0, 0, v3, 144, &v8, 0) != 0 )
              {
                if ( v3[0] == 1 )
                {
                  if ( (v3[8] != -1054182616 || v3[9] != 299038751 || v3[10] != -1610593350 || v3[11] != 1003044553)
                    && (v3[8] != -560677980 || v3[9] != 1296041681 || v3[10] != -708875615 || v3[11] != -1395230463) )
                  {
                    sub_4016D0((int)v5);
                    sub_40A5D0(dword_42516C, (int)v5);
                  }
                }
                else if ( v3[0] == 0 && LOBYTE(v3[8]) != 39 && BYTE1(v3[8]) != 1 )
                {
                  sub_4016D0((int)v5);
                  if ( dword_425454(v4, v5) == 1 )
                  {
                    if ( LOBYTE(v3[8]) == 0 )
                      sub_40A5D0(dword_42516C, (int)v5);
                  }
                  else
                  {
                    sub_40A5D0(dword_42516C, (int)v5);
                  }
                }
              }
              dword_4254D0(v9);
            }
            else
            {
              v2 = (_DWORD *)((char *)v5 + 2 * dword_42543C(v5));
              *v2 = 7274594;
              v2[1] = 7602287;
              v2[2] = 6750317;
              v2[3] = 114;
              v9 = dword_425528(v5, 0x80000000, 3, 0, 3, 128, 0);
              if ( v9 == -1 )
              {
                *(_WORD *)(dword_425450(v5, 92) + 2) = 0;
                sub_40A5D0(dword_42516C, (int)v5);
              }
              if ( v9 != -1 )
                dword_4254D0(v9);
            }
          }
        }
      }
      dword_425428(v5, 0, 520);
    }
    while ( dword_4255A8(v10, v5, 260) != 0 );
    return dword_4255AC(v10);
  }
  return result;
}


/* sub_40A928 @ 0040A928 */
_DWORD *__stdcall sub_40A928(int a1)
{
  unsigned int v1; // eax
  unsigned int v2; // ebx
  unsigned int v3; // edi
  _BYTE *i; // esi
  _DWORD *v6; // eax
  _BYTE v7[520]; // [esp+Ch] [ebp-214h] BYREF
  int v8; // [esp+214h] [ebp-Ch] BYREF
  int v9; // [esp+218h] [ebp-8h]
  int v10; // [esp+21Ch] [ebp-4h]

  v10 = 0;
  v8 = -1211744158;
  v9 = -1208205212;
  sub_401250(&v8, 2);
  v1 = sub_40A458(dword_42516C, 260, (int)v7);
  if ( v1 == 0 )
    return (_DWORD *)v10;
  v2 = v1 >> 2;
  while ( 2 )
  {
    v3 = v2;
    for ( i = v7; dword_425454(i, &v8) != 0; i += 8 )
    {
      if ( --v3 == 0 )
      {
        if ( dword_425598(&v8, a1) != 0 )
        {
          v6 = (_DWORD *)sub_406830(8);
          if ( v6 != nullptr )
          {
            *v6 = v8;
            v6[1] = v9;
            return v6;
          }
        }
        return (_DWORD *)v10;
      }
    }
    LOWORD(v8) = v8 - 1;
    if ( (_WORD)v8 != 64 )
      continue;
    break;
  }
  return (_DWORD *)v10;
}


/* sub_40A9F0 @ 0040A9F0 */
int __stdcall sub_40A9F0(int a1)
{
  int v2[4]; // [esp+0h] [ebp-3Ch] BYREF
  int v3[4]; // [esp+10h] [ebp-2Ch] BYREF
  int v4[4]; // [esp+20h] [ebp-1Ch] BYREF
  int v5; // [esp+30h] [ebp-Ch] BYREF
  int v6; // [esp+34h] [ebp-8h] BYREF
  int v7; // [esp+38h] [ebp-4h]

  v7 = 0;
  v6 = 0;
  v5 = 0;
  dword_425744(0);
  v4[0] = -1208069063;
  v4[1] = -1208205256;
  v4[2] = -1208205064;
  v4[3] = -235126728;
  sub_401250(v4, 4);
  v3[0] = -1208068927;
  v3[1] = -1208205256;
  v3[2] = -1208205064;
  v3[3] = -235126728;
  sub_401250(v3, 4);
  v2[0] = -1208205005;
  v2[1] = -1208205256;
  v2[2] = -1208205064;
  v2[3] = -235126728;
  sub_401250(v2, 4);
  if ( dword_425758(v4, 0, 1, v3, &v6) == 0
    && (**(int (__stdcall ***)(int, int *, int *))v6)(v6, v2, &v5) == 0
    && (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v5 + 20))(v5, a1, 0) == 0 )
  {
    v7 = sub_406830(0x4000);
    if ( v7 != 0
      && (*(int (__stdcall **)(int, int, int, _DWORD, _DWORD))(*(_DWORD *)v6 + 12))(v6, v7, 0x4000, 0, 0) != 0 )
    {
      sub_40684C(v7);
      v7 = 0;
    }
  }
  if ( v5 != 0 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 8))(v5);
  if ( v6 != 0 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6);
  dword_42574C();
  return v7;
}


/* sub_40AB38 @ 0040AB38 */
int __stdcall sub_40AB38(int a1, int a2)
{
  int v3; // [esp+0h] [ebp-8h] BYREF
  int v4; // [esp+4h] [ebp-4h]

  v3 = 0;
  v4 = dword_42551C(0, 0, sub_40A9F0, a2, 4, 0);
  if ( v4 != 0 )
  {
    if ( a1 != 0 && sub_40B390(a1, v4) == 0 )
    {
      dword_4254CC(v4, 0);
      dword_4254D0(v4);
      return v3;
    }
    dword_425524(v4);
    dword_425548(v4, -1);
    dword_425560(v4, &v3);
    dword_4254D0(v4);
  }
  return v3;
}


/* sub_40ABD0 @ 0040ABD0 */
int sub_40ABD0()
{
  int v1; // [esp+0h] [ebp-4h] BYREF

  v1 = 0;
  dword_4257B4(MEMORY[0x7FFE02D8], &v1);
  return v1;
}


/* sub_40ABF8 @ 0040ABF8 */
int sub_40ABF8()
{
  int v0; // eax
  int v2; // ebx
  int v3; // esi
  _DWORD v4[5]; // [esp+8h] [ebp-4Ch] BYREF
  _DWORD v5[6]; // [esp+1Ch] [ebp-38h] BYREF
  _DWORD v6[2]; // [esp+34h] [ebp-20h] BYREF
  int i; // [esp+3Ch] [ebp-18h]
  int v8; // [esp+40h] [ebp-14h] BYREF
  int v9; // [esp+44h] [ebp-10h] BYREF
  int v10; // [esp+48h] [ebp-Ch] BYREF
  int v11; // [esp+4Ch] [ebp-8h] BYREF
  int v12; // [esp+50h] [ebp-4h]

  v12 = 0;
  v11 = 0;
  v8 = 1024;
  for ( i = sub_406830(1024); ; i = sub_406868(i, v8) )
  {
    v0 = dword_425488(5, i, v8, &v8);
    if ( v0 == 0 )
      break;
    if ( v0 != -1073741820 )
    {
      sub_40684C(i);
      return v11;
    }
  }
  v2 = i;
  while ( 1 )
  {
    v3 = *(_DWORD *)v2;
    if ( *(_DWORD *)(v2 + 60) != 0 )
    {
      if ( sub_4011D4(*(_WORD **)(v2 + 60), 0) != -1210047432 )
        goto LABEL_16;
      v6[0] = *(_DWORD *)(v2 + 68);
      v6[1] = 0;
      v5[0] = 24;
      memset(&v5[1], 0, 20);
      v9 = 0;
      if ( dword_425474(&v9, 0x1FFFFF, v5, v6) != 0 )
        goto LABEL_16;
      if ( dword_4254A0(v9, 8, &v10) == 0 )
        break;
LABEL_15:
      dword_4254D0(v9);
    }
LABEL_16:
    v2 += v3;
    if ( v3 == 0 )
      goto LABEL_17;
  }
  v4[0] = 1;
  v4[1] = 1;
  v4[2] = 7;
  v4[3] = 0;
  v4[4] = 2;
  v11 = 0;
  if ( dword_4254D4(v10, v4, &v11) != 0 || v11 == 0 )
  {
    dword_4254D0(v10);
    goto LABEL_15;
  }
  dword_4254D0(v10);
  dword_4254D0(v9);
  v12 = *(_DWORD *)(v2 + 68);
LABEL_17:
  sub_40684C(i);
  return v12;
}


/* sub_40AD8C @ 0040AD8C */
int __stdcall sub_40AD8C(int a1, int a2, int a3)
{
  int v4; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+4h] [ebp-Ch] BYREF
  int v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v7 = 0;
  v5 = 0;
  v4 = 719;
  if ( dword_4254E4(a1, &v5, 0, &v4, 12288, 64) == 0 )
  {
    if ( dword_4254D8(a1, v5, a2, a3, 0) == 0 )
    {
      v6 = dword_425520(a1, 0, 0, v5, 0, 0, 0);
      if ( v6 != 0 )
      {
        dword_425548(v6, -1);
        dword_425560(v6, &v7);
        dword_4254D0(v6);
      }
    }
    v4 = 0;
    dword_4254E8(a1, &v5, &v4, 0x8000);
  }
  return v7;
}


/* sub_40AE44 @ 0040AE44 */
int sub_40AE44()
{
  int v0; // eax
  void *v1; // eax
  int v2; // esi
  int v3; // esi
  void *v4; // eax
  int v5; // esi
  int v6; // esi
  void *v7; // eax
  int v8; // esi
  int v9; // esi
  _DWORD v11[6]; // [esp+4h] [ebp-48h] BYREF
  HANDLE UniqueProcess; // [esp+1Ch] [ebp-30h] BYREF
  int v13; // [esp+20h] [ebp-2Ch]
  int v14; // [esp+24h] [ebp-28h] BYREF
  int v15; // [esp+28h] [ebp-24h] BYREF
  _DWORD v16[2]; // [esp+2Ch] [ebp-20h] BYREF
  int v17; // [esp+34h] [ebp-18h] BYREF
  int v18; // [esp+38h] [ebp-14h] BYREF
  int v19; // [esp+3Ch] [ebp-10h] BYREF
  int v20; // [esp+40h] [ebp-Ch]
  int v21; // [esp+44h] [ebp-8h] BYREF
  int v22; // [esp+48h] [ebp-4h] BYREF

  v20 = 0;
  v19 = 0;
  v17 = 0;
  v16[1] = 0;
  v16[0] = 0;
  v15 = 0;
  v22 = 0;
  v21 = 0;
  v14 = 0;
  if ( (unsigned int)sub_401574() >= 0x3C )
  {
    v0 = sub_40ABF8();
    if ( v0 != 0 )
    {
      UniqueProcess = (HANDLE)v0;
      v13 = 0;
      v11[0] = 24;
      memset(&v11[1], 0, 20);
      if ( dword_425474(&v22, 0x1FFFFF, v11, &UniqueProcess) == 0 )
      {
        UniqueProcess = NtCurrentTeb()->ClientId.UniqueProcess;
        v13 = 0;
        v11[0] = 24;
        memset(&v11[1], 0, 20);
        if ( dword_425474(&v21, 0x1FFFFF, v11, &UniqueProcess) == 0 )
        {
          if ( dword_42547C(v21, v21, v22, &v14, 0, 0, 2) == 0 )
          {
            sub_406E1C(-1, &v19);
            if ( v19 != 0 )
            {
              v18 = 513;
              if ( dword_4254E4(v21, v16, 0, &v18, 12288, 4) == 0 )
              {
                v1 = sub_406DB0(dword_41B3DA);
                v2 = (int)v1;
                if ( v1 != nullptr )
                {
                  dword_425424(v16[0], v1, 513);
                  sub_40684C(v2);
                  v3 = v16[0];
                  *(_DWORD *)(v3 + 9) = sub_4010AC()->SessionId;
                  *(_DWORD *)(v3 + 13) = v14;
                  v18 = 719;
                  if ( dword_4254E4(v21, &v15, 0, &v18, 12288, 64) == 0 )
                  {
                    v4 = sub_406DB0(dword_41B5DF);
                    v5 = (int)v4;
                    if ( v4 != nullptr )
                    {
                      dword_425424(v15, v4, 719);
                      sub_40684C(v5);
                      v6 = v15;
                      *(_DWORD *)(v15 + 37) = v22;
                      *(_DWORD *)(v6 + 44) = v16[0];
                      *(_DWORD *)(v6 + 51) = 513;
                      v20 = ((int (*)(void))v6)();
                      v18 = 0;
                      dword_4254E8(v21, &v15, &v18, 0x8000);
                    }
                  }
                  v18 = 0;
                  dword_4254E8(v21, v16, &v18, 0x8000);
                }
              }
            }
            else
            {
              v18 = 380;
              if ( dword_4254E4(v21, &v17, 0, &v18, 12288, 4) == 0 )
              {
                v7 = sub_406DB0(dword_41B25A);
                v8 = (int)v7;
                if ( v7 != nullptr )
                {
                  dword_425424(v17, v7, 380);
                  sub_40684C(v8);
                  v9 = v17;
                  *(_DWORD *)(v9 + 5) = sub_4010AC()->SessionId;
                  *(_DWORD *)(v9 + 9) = v14;
                  v20 = sub_40AD8C(v22, v9, 380);
                  v18 = 0;
                  dword_4254E8(v21, &v17, &v18, 0x8000);
                }
              }
            }
          }
          dword_4254D0(v21);
        }
        dword_4254D0(v22);
      }
    }
  }
  return v20;
}


/* sub_40B14C @ 0040B14C */
int __stdcall sub_40B14C(_DWORD *a1)
{
  int v2; // [esp+0h] [ebp-4h] BYREF

  v2 = 0;
  dword_425658(*a1, a1[1], a1[2], 2, 0, &v2);
  return v2;
}


/* sub_40B17C @ 0040B17C */
int sub_40B17C()
{
  unsigned int v0; // edi
  _BYTE *v1; // eax
  _BYTE *v2; // esi
  _WORD *v3; // eax
  const void *v4; // ebx
  int v5; // eax
  const void *v6; // ebx
  int v7; // eax
  const void *v8; // ebx
  int v9; // eax
  _BYTE *v11; // [esp+Ch] [ebp-214h] BYREF
  _BYTE *v12; // [esp+10h] [ebp-210h]
  _WORD *v13; // [esp+14h] [ebp-20Ch]
  _BYTE v14[256]; // [esp+18h] [ebp-208h] BYREF
  _BYTE v15[256]; // [esp+118h] [ebp-108h] BYREF
  int v16; // [esp+218h] [ebp-8h] BYREF
  int v17; // [esp+21Ch] [ebp-4h]

  v16 = 0;
  v0 = sub_401518(dword_425154);
  v1 = (_BYTE *)sub_406830(v0 + 2);
  v2 = v1;
  if ( v1 != nullptr )
  {
    sub_4012F4((char *)dword_425154, v1);
    sub_40684C(dword_425154);
    sub_401730(v2, v0);
    dword_425154 = (int)v2;
    if ( sub_4125D0(v14) != 0 )
    {
      while ( 1 )
      {
        dword_425444(v15, v2);
        v3 = (_WORD *)dword_42544C(v15, 58);
        if ( v3 != nullptr )
        {
          *v3 = 0;
          v11 = v15;
          v13 = v3 + 1;
          v12 = v14;
          v16 = 0;
          v17 = 0;
          v17 = dword_42551C(0, 0, sub_40B14C, &v11, 4, 0);
          if ( v17 != 0 )
          {
            dword_425524(v17);
            if ( dword_425548(v17, 3000) == 258 )
              dword_4254CC(v17, 0);
            else
              dword_425560(v17, &v16);
            dword_4254D0(v17);
            if ( v16 != 0 )
              break;
          }
        }
        v2 += 2 * dword_42543C(v2) + 2;
        if ( *(_WORD *)v2 == 0 )
          goto LABEL_11;
      }
      v4 = v13;
      v5 = dword_42543C(v13);
      dword_425164 = (int)sub_406DE0(v4, 2 * v5 + 2);
      v6 = v11;
      v7 = dword_42543C(v11);
      dword_42515C = (int)sub_406DE0(v6, 2 * v7 + 2);
      v8 = v12;
      v9 = dword_42543C(v12);
      dword_425160 = (int)sub_406DE0(v8, 2 * v9 + 2);
    }
LABEL_11:
    sub_40684C(dword_425154);
  }
  return v16;
}


/* sub_40B358 @ 0040B358 */
int sub_40B358()
{
  int v0; // eax
  int v2; // [esp+0h] [ebp-4h]

  v2 = 0;
  v0 = sub_4097A8(1051882214);
  if ( v0 != 0 )
    return sub_409850(v0, 3, 1);
  return v2;
}


/* sub_40B390 @ 0040B390 */
int __stdcall sub_40B390(int a1, int a2)
{
  BOOL v2; // ebx
  _DWORD v4[6]; // [esp+4h] [ebp-1Ch] BYREF
  int v5; // [esp+1Ch] [ebp-4h] BYREF

  v2 = false;
  if ( a1 == 0 )
    return 1;
  v4[0] = 24;
  memset(&v4[1], 0, 20);
  if ( dword_425478(a1, 12, v4, 0, 2, &v5) == 0 )
  {
    v2 = dword_425498(a2, 5, &v5, 4) == 0;
    dword_4254D0(v5);
  }
  return v2;
}


/* sub_40B414 @ 0040B414 */
void __stdcall sub_40B414(int a1)
{
  ;
}


/* sub_40B41C @ 0040B41C */
void sub_40B41C()
{
  ;
}


/* sub_40B438 @ 0040B438 */
int sub_40B438()
{
  int v1; // [esp+0h] [ebp-4h] BYREF

  dword_425678(0, dword_40B428, &v1);
  return v1;
}


/* sub_40B458 @ 0040B458 */
int __stdcall sub_40B458(int a1)
{
  int v1; // eax
  int *v2; // esi
  int v3; // ebx
  int v4; // eax
  _DWORD *v5; // esi
  int *v7; // [esp+8h] [ebp-10h] BYREF
  int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  int v10; // [esp+14h] [ebp-4h]

  v10 = 0;
  if ( a1 != 0 )
  {
    v9 = a1;
    v1 = 0;
  }
  else
  {
    v1 = dword_4254A0(-1, 8, &v9);
  }
  if ( v1 == 0 )
  {
    dword_425490(v9, 2, &v7, 4, &v8);
    v7 = (int *)sub_406830(v8);
    if ( v7 != nullptr )
    {
      if ( dword_425490(v9, 2, v7, v8, &v8) == 0 )
      {
        v2 = v7 + 1;
        v3 = *v7;
        while ( 1 )
        {
          v4 = *v2;
          v5 = v2 + 1;
          if ( *(_DWORD *)(v4 + 8) == 32 && *(_DWORD *)(v4 + 12) == 544 )
            break;
          v2 = v5 + 1;
          if ( --v3 == 0 )
            goto LABEL_12;
        }
        v10 = 1;
      }
LABEL_12:
      sub_40684C((int)v7);
    }
    if ( a1 == 0 )
      dword_4254D0(v9);
  }
  return v10;
}


/* sub_40B514 @ 0040B514 */
int __stdcall sub_40B514(int a1)
{
  int v1; // eax
  int *v2; // esi
  int v3; // ebx
  int v4; // eax
  _DWORD *v5; // esi
  int *v7; // [esp+8h] [ebp-10h] BYREF
  int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  int v10; // [esp+14h] [ebp-4h]

  v10 = 0;
  if ( a1 != 0 )
  {
    v9 = a1;
    v1 = 0;
  }
  else
  {
    v1 = dword_4254A0(-1, 8, &v9);
  }
  if ( v1 == 0 )
  {
    dword_425490(v9, 2, &v7, 4, &v8);
    v7 = (int *)sub_406830(v8);
    if ( v7 != nullptr )
    {
      if ( dword_425490(v9, 2, v7, v8, &v8) == 0 )
      {
        v2 = v7 + 1;
        v3 = *v7;
        while ( 1 )
        {
          v4 = *v2;
          v5 = v2 + 1;
          if ( *(_DWORD *)(v4 + 8) == 21 && *(_DWORD *)(v4 + 24) == 512 )
            break;
          v2 = v5 + 1;
          if ( --v3 == 0 )
            goto LABEL_12;
        }
        v10 = 1;
      }
LABEL_12:
      sub_40684C((int)v7);
    }
    if ( a1 == 0 )
      dword_4254D0(v9);
  }
  return v10;
}


/* sub_40B5D0 @ 0040B5D0 */
BOOL sub_40B5D0()
{
  BOOL v0; // ebx
  _DWORD v2[11]; // [esp+4h] [ebp-34h] BYREF
  _BYTE v3[4]; // [esp+30h] [ebp-8h] BYREF
  int v4; // [esp+34h] [ebp-4h] BYREF

  v0 = false;
  if ( dword_4254A0(-1, 8, &v4) == 0 )
  {
    if ( dword_425490(v4, 1, v2, 44, v3) == 0 )
      v0 = *(_DWORD *)(v2[0] + 8) == 18;
    dword_4254D0(v4);
  }
  return v0;
}


/* sub_40B664 @ 0040B664 */
int sub_40B664()
{
  int *v0; // esi
  int result; // eax
  char v2; // [esp+7h] [ebp-1h] BYREF

  v0 = dword_40B624;
  while ( 1 )
  {
    result = *v0++;
    if ( result == 0 )
      break;
    dword_4254A8(result, 1, 0, &v2);
  }
  return result;
}


/* sub_40B690 @ 0040B690 */
_DWORD *sub_40B690()
{
  _DWORD *result; // eax
  _DWORD *v1; // ebx

  result = (_DWORD *)sub_406888(4);
  v1 = result;
  if ( result != nullptr )
  {
    *result = 3;
    dword_425484(-1, 33, result, 4);
    *v1 <<= 9;
    dword_425484(-1, 18, v1, 2);
    *v1 = 7;
    dword_425484(-1, 12, v1, 4);
    return (_DWORD *)sub_4068B4((int)v1);
  }
  return result;
}


/* sub_40B6E4 @ 0040B6E4 */
_BYTE *__stdcall sub_40B6E4(int a1, int a2, _BYTE *a3)
{
  if ( *(_DWORD *)(a2 + 8) == *(_DWORD *)(a1 + 24) )
  {
    dword_4254BC(a1 + 36, dword_425874);
    dword_4254BC(a1 + 44, dword_42587C);
    *a3 = 1;
    return a3;
  }
  else
  {
    *a3 = 0;
    return a3;
  }
}


/* sub_40B72C @ 0040B72C */
int sub_40B72C()
{
  int result; // eax
  _WORD *v1; // esi
  int v2; // edi
  _WORD *v3; // edi
  int i; // ecx
  struct _PEB *v5; // ebx
  struct _RTL_USER_PROCESS_PARAMETERS *ProcessParameters; // esi
  int v7[6]; // [esp+4h] [ebp-1Ch] BYREF
  int v8; // [esp+1Ch] [ebp-4h] BYREF

  v8 = 4096;
  result = dword_4254E4(-1, &dword_42587C, 0, &v8, 12288, 4);
  if ( dword_42587C != 0 )
  {
    result = dword_4254E4(-1, &dword_425878, 0, &v8, 12288, 4);
    if ( dword_425878 != 0 )
    {
      result = dword_4254E4(-1, &dword_425874, 0, &v8, 12288, 4);
      if ( dword_425874 != 0 )
      {
        sub_401668((_WORD *)dword_425874);
        sub_4016D0(dword_425874);
        v7[0] = -1215283108;
        v7[1] = -1215020972;
        v7[2] = -1215348649;
        v7[3] = -1210957748;
        v7[4] = -1216069539;
        v7[5] = -1208205219;
        sub_401250(v7, 6);
        dword_425444(dword_42587C, v7);
        dword_425440(dword_425874, v7);
        v1 = (_WORD *)dword_425874;
        v2 = dword_425878;
        *(_WORD *)dword_425878 = 34;
        v3 = (_WORD *)(v2 + 2);
        for ( i = dword_42543C(v1); i != 0; --i )
          *v3++ = *v1++;
        *v3 = 34;
        v5 = sub_4010AC();
        dword_4254B0(v5->FastPebLock);
        ProcessParameters = v5->ProcessParameters;
        dword_4254BC(&ProcessParameters->ImagePathName, dword_425874);
        dword_4254BC(&ProcessParameters->CommandLine, dword_425878);
        dword_4254B4(v5->FastPebLock);
        return dword_4254C4(0, sub_40B6E4, v5);
      }
    }
  }
  return result;
}


/* sub_40B8A0 @ 0040B8A0 */
int __stdcall sub_40B8A0(int a1)
{
  int v2[34]; // [esp+4h] [ebp-BCh] BYREF
  int v3[4]; // [esp+8Ch] [ebp-34h] BYREF
  _DWORD v4[9]; // [esp+9Ch] [ebp-24h] BYREF

  v3[0] = -652137140;
  v3[1] = -108429249;
  v3[2] = -1021760881;
  v3[3] = -81865423;
  sub_401250(v3, 4);
  v2[0] = -1215283075;
  v2[1] = -1215676323;
  v2[2] = -1215807399;
  v2[3] = -1215086511;
  v2[4] = -1211744170;
  v2[5] = -1214758791;
  v2[6] = -1214955435;
  v2[7] = -1214955434;
  v2[8] = -1215807413;
  v2[9] = -1214431158;
  v2[10] = -1215086516;
  v2[11] = -1210236854;
  v2[12] = -1214693290;
  v2[13] = -1211744177;
  v2[14] = -1211154365;
  v2[15] = -1211547523;
  v2[16] = -1212202882;
  v2[17] = -1212530673;
  v2[18] = -1211023359;
  v2[19] = -1212334079;
  v2[20] = -1211285491;
  v2[21] = -1211613163;
  v2[22] = -1211482101;
  v2[23] = -1211023345;
  v2[24] = -1211351039;
  v2[25] = -1211154418;
  v2[26] = -1212334059;
  v2[27] = -1211219959;
  v2[28] = -1211219960;
  v2[29] = -1211613172;
  v2[30] = -1212268418;
  v2[31] = -1212202883;
  v2[32] = -1216266225;
  v2[33] = -1208205256;
  sub_401250(v2, 34);
  dword_425428(v4, 0, 36);
  v4[0] = 36;
  v4[5] = 4;
  return dword_425750(v2, v4, v3, a1);
}


/* sub_40BA18 @ 0040BA18 */
int sub_40BA18()
{
  int result; // eax
  int v1; // esi
  int v2; // eax
  _DWORD *v3; // ebx
  int v4; // esi
  int v5; // eax
  int v6; // [esp+0h] [ebp-10h]
  int v7; // [esp+4h] [ebp-Ch]
  int v8; // [esp+8h] [ebp-8h] BYREF
  int v9; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  result = dword_425744(0);
  if ( result != 1359 )
  {
    v6 = sub_40165C();
    v7 = sub_401650();
    sub_40B72C();
    sub_40B8A0(&v8);
    if ( v8 != 0 )
    {
      v1 = sub_409710(v7, v6);
      v2 = dword_42572C(v1, &v9);
      v3 = (_DWORD *)v2;
      if ( v9 == 1 )
      {
        v4 = 0;
      }
      else
      {
        v5 = dword_425448(v1, *(_DWORD *)(v2 + 4));
        v4 = v5;
        if ( *(_WORD *)(v5 - 2) != 32 )
          v4 = v5 - 2;
      }
      if ( (*(int (__stdcall **)(int, _DWORD, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v8 + 36))(v8, *v3, v4, 0, 0, 0) == 0 )
        (*(void (__stdcall **)(int))(*(_DWORD *)v8 + 8))(v8);
      sub_40684C((int)v3);
    }
    return dword_42574C();
  }
  return result;
}


/* sub_40BACC @ 0040BACC */
_WORD *__thiscall sub_40BACC(void *this, int a2)
{
  _WORD *v2; // ebx
  int v5[7]; // [esp+4h] [ebp-1Ch] BYREF

  v2 = (_WORD *)sub_406830(42);
  if ( v2 != nullptr )
  {
    v5[0] = -1215348707;
    v5[1] = -1213317098;
    v5[2] = -1212333955;
    v5[3] = -1213120388;
    v5[4] = -1210957699;
    v5[5] = -1216069556;
    v5[6] = -1208205236;
    sub_401250(v5, 7);
    dword_425464(v2, v5, dword_425178 + 2, this);
    dword_425170 = sub_4011D4(v2, -1);
  }
  return v2;
}


/* sub_40BB50 @ 0040BB50 */
int __stdcall sub_40BB50(_WORD *a1, int a2)
{
  _WORD *v2; // eax
  int v4; // [esp+0h] [ebp-4h]

  v4 = 0;
  if ( a2 != 0 )
    v2 = (_WORD *)dword_425770(a1);
  else
    v2 = a1;
  if ( sub_4011D4(v2, -1) == dword_425170 )
    return 1;
  return v4;
}


/* sub_40BB94 @ 0040BB94 */
int __stdcall sub_40BB94(int a1, _BYTE *a2, int a3)
{
  int result; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int i; // ebx
  unsigned int v8; // esi
  int v9[5]; // [esp+8h] [ebp-A8h] BYREF
  _DWORD v10[5]; // [esp+1Ch] [ebp-94h] BYREF
  _DWORD v11[7]; // [esp+30h] [ebp-80h] BYREF
  int v12[16]; // [esp+4Ch] [ebp-64h] BYREF
  _BYTE v13[4]; // [esp+8Ch] [ebp-24h] BYREF
  int v14; // [esp+90h] [ebp-20h]
  int v15; // [esp+94h] [ebp-1Ch]
  unsigned int v16; // [esp+98h] [ebp-18h]
  int v17; // [esp+9Ch] [ebp-14h]
  int v18; // [esp+A0h] [ebp-10h] BYREF
  int v19; // [esp+A4h] [ebp-Ch]
  int v20; // [esp+A8h] [ebp-8h]
  int v21; // [esp+ACh] [ebp-4h]

  v21 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  result = dword_42585C(a1, &v18, 0);
  if ( result != 0 )
  {
    v4 = dword_425868(0, v18, a1, 0, 0, 0);
    result = sub_406830(v4);
    v17 = result;
    if ( result != 0 )
    {
      dword_425868(0, v18, a1, v17, 0, 2);
      v9[0] = -1212858257;
      v9[1] = -1213251466;
      v9[2] = -1212989336;
      v9[3] = -1213185929;
      v9[4] = -1208205256;
      sub_401250(v9, 5);
      result = dword_4256EC(v5, a1, 0, v17);
      v21 = result;
      if ( result != 0 )
      {
        dword_42570C(v21, 1);
        dword_425710(v21, 1);
        dword_425428(v11, 0, 92);
        v12[0] = -1215086469;
        v12[1] = -1215348650;
        v12[2] = -1215283113;
        v12[3] = -1215348647;
        v12[4] = -1208205256;
        sub_401250(v12, 5);
        v6 = dword_4256E0(v21, 90);
        v11[0] = dword_4255E8(18, v6, 72);
        v11[4] = 900;
        v20 = dword_4256DC(v11);
        v19 = dword_4256F8(v21, v20);
        dword_425428(v10, 0, 20);
        v10[0] = 20;
        v10[1] = a1;
        dword_425718(v21, v10);
        sub_401730(a2, a3);
        for ( i = 1000; i != 0; --i )
        {
          dword_425720(v21);
          dword_425428(v13, 0, 16);
          v15 = dword_4256E0(v21, 8);
          v16 = dword_4256E0(v21, 10);
          v8 = v16;
          dword_4256AC(v21, a2, a3, v13, 1297);
          v14 = (v8 >> 1) - (v16 >> 1);
          dword_4256AC(v21, a2, a3, v13, 273);
          dword_425724(v21);
        }
        dword_42571C(v21);
        sub_401730(a2, a3);
        result = dword_4256F8(v21, v19);
      }
    }
  }
  if ( v20 != 0 )
    result = dword_425704(v20);
  if ( v21 != 0 )
    result = dword_425700(v21);
  if ( v17 != 0 )
    result = sub_40684C(v17);
  if ( v18 != 0 )
    return dword_425860(v18);
  return result;
}


/* sub_40BE2C @ 0040BE2C */
int __stdcall sub_40BE2C(int a1)
{
  int v1; // ecx
  int v2; // ebx
  int v3; // ecx
  int v5[4]; // [esp+4h] [ebp-18h] BYREF
  int v6; // [esp+14h] [ebp-8h]
  int v7; // [esp+18h] [ebp-4h]

  v7 = 1;
  v6 = sub_4068FC(a1, 0);
  if ( v6 != 0 )
  {
    dword_425458(v6);
    v5[0] = -1214627753;
    v5[1] = -1214955426;
    v5[2] = -1214693285;
    v5[3] = -1208205256;
    sub_401250(v5, 4);
    v2 = dword_425448(v6, v1);
    v5[0] = -1215152041;
    v5[1] = -1215152035;
    v5[2] = -1215807401;
    v5[3] = -1208205219;
    sub_401250(v5, 4);
    if ( dword_425448(v6, v3) == 0 && v2 == 0 )
      v7 = 0;
  }
  if ( v6 != 0 )
    sub_40684C(v6);
  return v7;
}


/* sub_40BEF0 @ 0040BEF0 */
int __stdcall sub_40BEF0(int a1, _BYTE *a2, int a3)
{
  int result; // eax
  int *v4; // ebx
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h] BYREF
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v5 = 0;
  result = dword_425864(a1, 0, 5, 0, 0, &v7, &v6);
  if ( v7 != 0 )
  {
    result = sub_406830(v7);
    v5 = result;
    if ( result != 0 )
    {
      result = dword_425864(a1, 0, 5, result, v7, &v7, &v6);
      if ( result != 0 )
      {
        v4 = (int *)v5;
        do
        {
          result = ~sub_4011D4((_WORD *)v4[1], 0) ^ 0x4803BFC7;
          if ( result != -396403967
            && result != 1921698977
            && result != 1848305995
            && result != 796838764
            && result != 1424252472 )
          {
            result = sub_40BE2C(v4[1]);
            if ( result == 0 )
              result = sub_40BB94(*v4, a2, a3);
          }
          v4 += 5;
          --v6;
        }
        while ( v6 != 0 );
      }
    }
  }
  if ( v5 != 0 )
    return sub_40684C(v5);
  return result;
}


/* sub_40BFC0 @ 0040BFC0 */
_BYTE *sub_40BFC0()
{
  _BYTE *result; // eax
  _BYTE *v1; // ebx
  int v2; // ebx
  _BYTE v3[48]; // [esp+4h] [ebp-3Ch] BYREF
  _BYTE *v4; // [esp+34h] [ebp-Ch]
  _BYTE *v5; // [esp+38h] [ebp-8h]
  _BYTE *v6; // [esp+3Ch] [ebp-4h]

  v6 = nullptr;
  v4 = nullptr;
  result = sub_406DB0(dword_41B8B2);
  v5 = result;
  if ( result != nullptr )
  {
    result = (_BYTE *)sub_406830(716);
    v4 = result;
    if ( result != nullptr )
    {
      result = (_BYTE *)sub_418BA4(v5, v4);
      v1 = result;
      if ( result != (_BYTE *)-1 )
      {
        sub_40684C((int)v5);
        v5 = nullptr;
        result = (_BYTE *)sub_406830((int)(v1 + 48));
        v6 = result;
        if ( result != nullptr )
        {
          sub_406EAC(v3);
          v2 = ((int (__cdecl *)(_BYTE *, _BYTE *, _BYTE *))dword_425468)(v6, v4, v3);
          sub_40684C((int)v4);
          v4 = nullptr;
          dword_425428(v3, 0, 48);
          sub_401730(v6, v2);
          sub_40BEF0(2, v6, v2);
          if ( dword_425168 != 0 )
            sub_40B390(dword_425168, -2);
          sub_40BEF0(64, v6, v2);
          sub_40BEF0(16, v6, v2);
          result = (_BYTE *)sub_40BEF0(4, v6, v2);
        }
      }
    }
  }
  if ( v6 != nullptr )
    result = (_BYTE *)sub_40684C((int)v6);
  if ( v4 != nullptr )
    result = (_BYTE *)sub_40684C((int)v4);
  if ( v5 != nullptr )
    return (_BYTE *)sub_40684C((int)v5);
  return result;
}


/* sub_40C0F8 @ 0040C0F8 */
void __stdcall sub_40C0F8(int a1, int *a2)
{
  int v2; // [esp+4h] [ebp-4h]

  if ( dword_425158 != 0 )
  {
    v2 = sub_4068FC(a1, 26);
    if ( v2 != 0 )
    {
      if ( (dword_425504(v2) & 0x10) == 0 )
        dword_425784(v2);
      sub_4016D0(v2);
      dword_425440(v2, dword_42517C);
      if ( a2 == nullptr )
      {
        sub_40C1E8(v2);
        sub_40684C(v2);
        return;
      }
      if ( *(_BYTE *)a2 == 0 )
        goto LABEL_8;
      if ( dword_425504(*a2) == -1 )
      {
        sub_40684C(*a2);
        *(_BYTE *)a2 = 0;
LABEL_8:
        sub_40C1E8(v2);
        *a2 = v2;
        return;
      }
      dword_425514(*a2, v2, 0);
      sub_40684C(v2);
    }
  }
}


/* sub_40C1E8 @ 0040C1E8 */
int __stdcall sub_40C1E8(int a1)
{
  int result; // eax
  int v2; // edx
  char *v3; // esi
  unsigned int v4; // ebx
  unsigned int v5; // edx
  unsigned int v6; // edi
  char v7; // al
  char *v8; // esi
  char v9; // al
  char *v10; // esi
  char v11; // al
  char *v12; // esi
  char v13; // al
  _DWORD v14[2]; // [esp+Ch] [ebp-1Ch] BYREF
  int v15; // [esp+14h] [ebp-14h]
  int v16; // [esp+18h] [ebp-10h]
  char v17; // [esp+1Fh] [ebp-9h] BYREF
  _BYTE v18[4]; // [esp+20h] [ebp-8h] BYREF
  int v19; // [esp+24h] [ebp-4h]

  result = dword_425528(a1, 0x40000000, 0, 0, 2, 128, 0);
  v19 = result;
  if ( result != -1 )
  {
    v2 = dword_426000[1];
    v14[0] = dword_426000[0];
    v14[1] = v2;
    v15 = dword_425174;
    v3 = (char *)dword_425158;
LABEL_3:
    v4 = sub_4017BC((int)dword_426000, (int)v14);
    v6 = v5;
    v16 = 2;
    while ( 1 )
    {
      v7 = *v3;
      v8 = v3 + 1;
      v17 = v4 ^ v7;
      dword_42552C(v19, &v17, 1, v18, 0);
      if ( --v15 == 0 )
        break;
      v9 = *v8;
      v10 = v8 + 1;
      v17 = BYTE1(v6) ^ v9;
      dword_42552C(v19, &v17, 1, v18, 0);
      if ( --v15 == 0 )
        break;
      v11 = *v10;
      v12 = v10 + 1;
      v17 = BYTE1(v4) ^ v11;
      dword_42552C(v19, &v17, 1, v18, 0);
      if ( --v15 == 0 )
        break;
      v13 = *v12;
      v3 = v12 + 1;
      v17 = v6 ^ v13;
      dword_42552C(v19, &v17, 1, v18, 0);
      if ( --v15 == 0 )
        break;
      v4 >>= 16;
      v6 >>= 16;
      if ( --v16 == 0 )
        goto LABEL_3;
    }
    return dword_4254D0(v19);
  }
  return result;
}


/* sub_40C354 @ 0040C354 */
int __stdcall sub_40C354(int a1)
{
  void *v1; // esi
  int v2; // eax
  int v3; // ebx
  _WORD *v4; // edi
  int v5; // ecx
  bool v6; // zf
  _DWORD *v7; // edi
  int v8; // eax
  _WORD *v9; // edi
  int v10; // ecx
  _DWORD *v11; // edi
  int v12; // eax
  _BYTE v14[520]; // [esp+Ch] [ebp-260h] BYREF
  _BYTE v15[64]; // [esp+214h] [ebp-58h] BYREF
  int v16; // [esp+254h] [ebp-18h] BYREF
  int v17; // [esp+258h] [ebp-14h]
  _BYTE v18[4]; // [esp+25Ch] [ebp-10h] BYREF
  int v19; // [esp+260h] [ebp-Ch]
  int v20; // [esp+264h] [ebp-8h] BYREF
  int v21; // [esp+268h] [ebp-4h]

  v21 = 0;
  if ( byte_42512C != 0 )
  {
    v16 = 0;
    v1 = sub_406DB0(dword_41BA1C);
    if ( v1 != nullptr )
    {
      v2 = sub_406830(8 * dword_41BA18);
      v3 = v2;
      if ( v2 != 0 )
      {
        v17 = sub_418BA4(v1, v2);
        if ( v17 != -1 )
        {
          dword_425730(0, v14, 35, 0);
          sub_4016D0(v14);
          dword_425440(v14, a1 + 2);
          v4 = v14;
          v5 = -1;
          do
          {
            if ( v5 == 0 )
              break;
            v6 = *v4++ == 0;
            --v5;
          }
          while ( !v6 );
          v7 = v4 - 1;
          *v7 = 6881326;
          v7[1] = 7274595;
          v7[2] = 0;
          v19 = dword_425528(v14, 0x40000000, 0, 0, 2, 128, 0);
          if ( v19 != -1 )
          {
            if ( dword_42552C(v19, v3, v17, v18, 0) != 0
              && dword_42560C(0x80000000, a1, 0, 0, 0, 131334, 0, &v20, 0) == 0 )
            {
              v8 = dword_42543C(a1 + 2);
              if ( dword_425610(v20, &v16, 0, 1, a1 + 2, 2 * v8 + 2) == 0 )
              {
                dword_4254D0(v20);
                dword_425444(v15, a1 + 2);
                v9 = v15;
                v10 = -1;
                do
                {
                  if ( v10 == 0 )
                    break;
                  v6 = *v9++ == 0;
                  --v10;
                }
                while ( !v6 );
                v11 = v9 - 1;
                *v11 = 4456540;
                v11[1] = 6684773;
                v11[2] = 7667809;
                v11[3] = 7602284;
                v11[4] = 6488137;
                v11[5] = 7209071;
                v11[6] = 0;
                if ( dword_42560C(0x80000000, v15, 0, 0, 0, 131334, 0, &v20, 0) == 0 )
                {
                  v12 = dword_42543C(v14);
                  if ( dword_425610(v20, &v16, 0, 1, v14, 2 * v12 + 2) == 0 )
                  {
                    dword_425738(0x8000000, 4096, 0, 0);
                    v21 = 1;
                  }
                }
              }
              dword_4254D0(v20);
            }
            dword_4254D0(v19);
          }
        }
        sub_40684C(v3);
      }
      sub_40684C((int)v1);
    }
  }
  return v21;
}


/* sub_40C5B4 @ 0040C5B4 */
int sub_40C5B4()
{
  int v0; // ebx
  unsigned int v1; // ebx
  int v2; // esi
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  int v7; // eax
  _WORD *v8; // edi
  int v9; // eax
  int v10; // eax
  int v12; // [esp+0h] [ebp-34h]
  void *v13; // [esp+Ch] [ebp-28h]
  void *v14; // [esp+10h] [ebp-24h]
  int v15; // [esp+14h] [ebp-20h]
  unsigned int v16; // [esp+18h] [ebp-1Ch]
  int v17; // [esp+1Ch] [ebp-18h]
  int v18; // [esp+20h] [ebp-14h]
  _DWORD v19[2]; // [esp+24h] [ebp-10h] BYREF
  _DWORD v20[2]; // [esp+2Ch] [ebp-8h] BYREF

  v18 = 0;
  v14 = nullptr;
  v13 = nullptr;
  v17 = 0;
  v0 = sub_40A458(dword_42516C, 0, 0);
  if ( v0 != 0 )
  {
    v15 = sub_406830(2 * v0);
    if ( v15 != 0 )
    {
      v1 = sub_40A458(dword_42516C, v0, v15);
      if ( v1 != 0 )
      {
        v14 = sub_406DB0(dword_41CF80);
        if ( v14 != nullptr )
        {
          v13 = sub_406DB0(dword_41CFFE);
          if ( v13 != nullptr )
          {
            v16 = v1 >> 2;
            v2 = (v1 >> 2) * dword_42543C(v14);
            v17 = sub_406830(4 * v2);
            if ( v17 != 0 )
            {
              v3 = dword_42543C(v13);
              v18 = sub_406830(4 * (v3 + v2));
              if ( v18 != 0 )
              {
                v4 = 0;
                v5 = v15;
                v6 = (_DWORD *)v17;
                do
                {
                  v7 = sub_40A190(dword_42516C, v5);
                  if ( v7 == 3 || v7 == 2 || v7 == 4 )
                  {
                    if ( sub_40A51C(dword_42516C, v5, 0, (int)v20, (int)v19) != 0 )
                    {
                      if ( v4 != 0 )
                      {
                        *v6 = 852012;
                        v8 = v6 + 1;
                        *v8 = 10;
                        v6 = v8 + 1;
                      }
                      else
                      {
                        v4 = 1;
                      }
                      v13 = (void *)dword_425470(v19[0], v19[1], 0x100000, 0);
                      v9 = dword_425470(v20[0], v20[1], 0x100000, 0);
                      *(_WORD *)(v5 + 2) = 0;
                      v6 = (_DWORD *)((char *)v6 + 2 * dword_425464(v6, v14, v5, v9));
                      v5 += 8;
                    }
                    else
                    {
                      v5 += 8;
                    }
                  }
                  else
                  {
                    v5 += 8;
                  }
                  --v16;
                }
                while ( v16 != 0 );
                v10 = dword_425464(v18, v13, v17, v12);
                v18 = sub_406868(v18, 2 * v10 + 2);
              }
            }
          }
        }
      }
    }
  }
  if ( v14 != nullptr )
    sub_40684C((int)v14);
  if ( v13 != nullptr )
    sub_40684C((int)v13);
  if ( v17 != 0 )
    sub_40684C(v17);
  return v18;
}


/* sub_40C7B4 @ 0040C7B4 */
int sub_40C7B4()
{
  int v1; // [esp+0h] [ebp-8h]
  int v2; // [esp+4h] [ebp-4h] BYREF

  v2 = 0;
  sub_40A0D8(dword_42516C, 0, (int)&v2);
  v1 = sub_406830(2 * v2 + 4);
  if ( v1 != 0 && sub_40A0D8(dword_42516C, v1, (int)&v2) == 0 )
  {
    sub_40684C(v1);
    return 0;
  }
  return v1;
}


/* sub_40C820 @ 0040C820 */
int sub_40C820()
{
  int v1; // [esp+0h] [ebp-8h]
  int v2; // [esp+4h] [ebp-4h] BYREF

  v2 = 0;
  dword_425594(0, &v2);
  v1 = sub_406830(2 * v2);
  if ( v1 != 0 && dword_425594(v1, &v2) == 0 )
  {
    sub_40684C(v1);
    return 0;
  }
  return v1;
}


/* sub_40C884 @ 0040C884 */
int sub_40C884()
{
  _BYTE v1[520]; // [esp+0h] [ebp-260h] BYREF
  int v2[14]; // [esp+208h] [ebp-58h] BYREF
  _BYTE v3[16]; // [esp+240h] [ebp-20h] BYREF
  int v4; // [esp+250h] [ebp-10h] BYREF
  int v5; // [esp+254h] [ebp-Ch] BYREF
  int v6; // [esp+258h] [ebp-8h] BYREF
  int v7; // [esp+25Ch] [ebp-4h]

  v7 = 0;
  v6 = 0;
  if ( sub_406C60(dword_42516C, (int)v1) != 0 )
  {
    sub_4016D0((int)v1);
    v2[0] = -1215086469;
    v2[1] = -1215807402;
    v2[2] = -1215086518;
    v2[3] = -1210302380;
    v2[4] = -1214431128;
    v2[5] = -1214693290;
    v2[6] = -1214234540;
    v2[7] = -1215152015;
    v2[8] = -1214693300;
    v2[9] = -1215152054;
    v2[10] = -1215807399;
    v2[11] = -1215086511;
    v2[12] = -1214431146;
    v2[13] = -1208205228;
    sub_401250(v2, 14);
    dword_425440(v1, v2);
    if ( dword_42560C(-2147483645, v1, 0, 0, 0, 131353, 0, &v6, 0) == 0 )
    {
      v2[0] = -1215086476;
      v2[1] = -1214431141;
      v2[2] = -1214693292;
      v2[3] = -1214431114;
      v2[4] = -1214693291;
      v2[5] = -1208205256;
      sub_401250(v2, 6);
      v5 = 1;
      v4 = 16;
      if ( dword_425614(v6, v2, 0, &v5, v3, &v4) == 0
        || (v2[0] = -1213185973,
            v2[1] = -1215152039,
            v2[2] = -1215741857,
            v2[3] = -1214562215,
            v2[4] = -1208205219,
            sub_401250(v2, 5),
            dword_425614(v6, v2, 0, &v5, v3, &v4) == 0) )
      {
        v7 = sub_406830(v4);
        if ( v7 != 0 )
          dword_425444(v7, v3);
      }
    }
  }
  if ( v6 != 0 )
    dword_4254D0(v6);
  return v7;
}


/* sub_40CA58 @ 0040CA58 */
int sub_40CA58()
{
  _BYTE v1[4]; // [esp+0h] [ebp-8h] BYREF
  int v2; // [esp+4h] [ebp-4h] BYREF

  v2 = 0;
  dword_4257D0(0, &v2, v1);
  return v2;
}


/* sub_40CA7C @ 0040CA7C */
int sub_40CA7C()
{
  _BYTE v1[128]; // [esp+0h] [ebp-ECh] BYREF
  int v2[23]; // [esp+80h] [ebp-6Ch] BYREF
  int v3; // [esp+DCh] [ebp-10h] BYREF
  int v4; // [esp+E0h] [ebp-Ch] BYREF
  int v5; // [esp+E4h] [ebp-8h] BYREF
  int v6; // [esp+E8h] [ebp-4h]

  v6 = 0;
  v2[0] = -1212989333;
  v2[1] = -1213710210;
  v2[2] = -1212333969;
  v2[3] = -1212596118;
  v2[4] = -1213120412;
  v2[5] = -1214300079;
  v2[6] = -1215086518;
  v2[7] = -1215086517;
  v2[8] = -1215807394;
  v2[9] = -1213513628;
  v2[10] = -1215152047;
  v2[11] = -1215086500;
  v2[12] = -1215348657;
  v2[13] = -1213054952;
  v2[14] = -1214234516;
  v2[15] = -1215741829;
  v2[16] = -1215414198;
  v2[17] = -1215152035;
  v2[18] = -1213579188;
  v2[19] = -1215414179;
  v2[20] = -1214955445;
  v2[21] = -1215152041;
  v2[22] = -1208205256;
  sub_401250(v2, 23);
  if ( dword_42560C(-2147483646, v2, 0, 0, 0, 131353, 0, &v5, 0) == 0 )
  {
    v2[0] = -1215414168;
    v2[1] = -1214758825;
    v2[2] = -1214300083;
    v2[3] = -1213054900;
    v2[4] = -1215217575;
    v2[5] = -1208205219;
    sub_401250(v2, 6);
    dword_425428(v1, 0, 128);
    v4 = 1;
    v3 = 128;
    if ( dword_425614(v5, v2, 0, &v4, v1, &v3) == 0 )
    {
      v6 = sub_406830(v3);
      if ( v6 != 0 )
        dword_425444(v6, v1);
    }
    dword_4254D0(v5);
  }
  return v6;
}


/* sub_40CC10 @ 0040CC10 */
_DWORD *sub_40CC10()
{
  _DWORD *v0; // ebx
  int v2; // [esp+4h] [ebp-4h] BYREF

  v0 = (_DWORD *)sub_406830(8);
  if ( v0 != nullptr )
  {
    sub_406E1C(-1, &v2);
    if ( v2 != 0 )
    {
      *v0 = 3539064;
      v0[1] = 52;
    }
    else
    {
      *v0 = 3670136;
      v0[1] = 54;
    }
  }
  return v0;
}


/* sub_40CC60 @ 0040CC60 */
__int16 *sub_40CC60()
{
  int v0; // ebx
  int v1; // ebx
  int v2; // ebx
  int v3; // ebx
  int v4; // ebx
  int v5; // ebx
  int v6; // ebx
  int v7; // eax
  int v8; // ebx
  __int16 *v10; // [esp+Ch] [ebp-24h]
  void *v11; // [esp+10h] [ebp-20h]
  _DWORD *v12; // [esp+14h] [ebp-1Ch]
  int v13; // [esp+18h] [ebp-18h]
  int v14; // [esp+1Ch] [ebp-14h]
  int v15; // [esp+20h] [ebp-10h]
  int v16; // [esp+24h] [ebp-Ch]
  int v17; // [esp+28h] [ebp-8h]
  int v18; // [esp+2Ch] [ebp-4h]

  v10 = nullptr;
  v18 = 0;
  v17 = 0;
  v16 = 0;
  v15 = 0;
  v14 = 0;
  v13 = 0;
  v12 = nullptr;
  v11 = sub_406DB0(dword_41CE8A);
  if ( v11 != nullptr )
  {
    v18 = sub_40C5B4();
    v17 = sub_40C7B4();
    v16 = sub_40C820();
    v15 = sub_40C884();
    v14 = sub_40CA58();
    v13 = sub_40CA7C();
    v12 = sub_40CC10();
    v0 = dword_42543C(v18);
    v1 = dword_42543C(v17) + v0;
    v2 = dword_42543C(v16) + v1;
    v3 = dword_42543C(v15) + v2;
    v4 = dword_42543C(v14) + v3;
    v5 = dword_42543C(v13) + v4;
    v6 = dword_42543C(v12) + v5;
    v7 = dword_42543C(v11);
    v10 = (__int16 *)sub_406830(2 * (v7 + v6) + 2);
    if ( v10 != nullptr )
    {
      v8 = dword_425464(v10, v11, v16, v17);
      sub_401228(v10, v10);
      v10 = (__int16 *)sub_406868((int)v10, v8 + 1);
    }
  }
  if ( v11 != nullptr )
    sub_40684C((int)v11);
  if ( v18 != 0 )
    sub_40684C(v18);
  if ( v17 != 0 )
    sub_40684C(v17);
  if ( v16 != 0 )
    sub_40684C(v16);
  if ( v15 != 0 )
    sub_40684C(v15);
  if ( v14 != 0 )
    sub_40684C(v14);
  if ( v13 != 0 )
    sub_40684C(v13);
  if ( v12 != nullptr )
    sub_40684C((int)v12);
  return v10;
}


/* sub_40CE38 @ 0040CE38 */
int sub_40CE38()
{
  _DWORD v1[32]; // [esp+0h] [ebp-104h] BYREF
  int v2[5]; // [esp+80h] [ebp-84h] BYREF
  _BYTE v3[88]; // [esp+94h] [ebp-70h] BYREF
  unsigned int v4; // [esp+ECh] [ebp-18h]
  unsigned int v5; // [esp+F0h] [ebp-14h]
  unsigned int v6; // [esp+F4h] [ebp-10h]
  unsigned int v7; // [esp+F8h] [ebp-Ch]
  int v8; // [esp+FCh] [ebp-8h] BYREF
  int v9; // [esp+100h] [ebp-4h]

  v9 = 0;
  if ( sub_406B10((int)v1) != 0 )
  {
    v8 = sub_4011D4(v1, 0);
    dword_425428(v3, 0, 104);
    dword_4255F0(v3);
    dword_4255F4(v3, &v8, 4);
    dword_4255F8(v3);
    v2[0] = -809210339;
    v2[1] = -809210339;
    v2[2] = -809210339;
    v2[3] = -809210339;
    v2[4] = -1208205283;
    sub_401250(v2, 5);
    v9 = sub_406830(33);
    if ( v9 != 0 )
    {
      v4 = _byteswap_ulong(v4);
      v5 = _byteswap_ulong(v5);
      v6 = _byteswap_ulong(v6);
      v7 = _byteswap_ulong(v7);
      dword_425468(v9, v2, v4, v5, v6, v7, v1[0], v1[1]);
    }
  }
  return v9;
}


/* sub_40CF28 @ 0040CF28 */
void __stdcall sub_40CF28(unsigned int *a1, int a2)
{
  _WORD *v2; // esi
  unsigned int v3; // ebx
  int v4; // eax
  unsigned int v5; // eax
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  _WORD *v9; // eax
  int v10; // ebx
  int v11; // eax
  _WORD v12[128]; // [esp+4h] [ebp-150h] BYREF
  _WORD v13[8]; // [esp+104h] [ebp-50h] BYREF
  int v14[3]; // [esp+114h] [ebp-40h] BYREF
  _WORD v15[4]; // [esp+120h] [ebp-34h] BYREF
  int v16; // [esp+128h] [ebp-2Ch] BYREF
  int v17; // [esp+12Ch] [ebp-28h] BYREF
  int *v18; // [esp+130h] [ebp-24h]
  int v19; // [esp+134h] [ebp-20h]
  _BYTE *v20; // [esp+138h] [ebp-1Ch]
  int v21; // [esp+13Ch] [ebp-18h]
  int v22; // [esp+140h] [ebp-14h]
  void *v23; // [esp+144h] [ebp-10h]
  int v24; // [esp+148h] [ebp-Ch]
  int v25; // [esp+14Ch] [ebp-8h]
  int v26; // [esp+150h] [ebp-4h]

  v22 = 0;
  v18 = nullptr;
  v19 = 0;
  v21 = 0;
  v20 = nullptr;
  v23 = nullptr;
  v26 = 0;
  v25 = 0;
  v24 = 0;
  if ( a1 != nullptr )
  {
    v2 = (_WORD *)dword_425150;
    if ( dword_425150 != 0 )
    {
      v3 = sub_4056A0(dword_425110, 0x10u, a1, (a2 + 16) & 0xFFFFFFF0);
      if ( v3 != 0 )
      {
        v18 = (int *)sub_406830(4 * v3);
        if ( v18 != nullptr )
        {
          sub_401414(v3, a1, v3, v18);
          v21 = sub_40D5D8(&unk_425100, v18);
          if ( v21 != 0 )
          {
            v19 = sub_40D40C();
            if ( v19 != 0 )
            {
              v22 = sub_40D594();
              if ( v22 != 0 )
              {
                v23 = sub_406DB0(dword_41D170);
                if ( v23 != nullptr )
                {
                  v26 = dword_425814(v22, 0, 0, 0, 0);
                  if ( v26 != 0 )
                  {
                    v14[0] = -1212989336;
                    v14[1] = -1213710229;
                    v14[2] = -1208205256;
                    sub_401250(v14, 3);
                    v15[0] = 58;
                    v15[1] = 47;
                    v15[2] = 47;
                    v15[3] = 0;
                    while ( 1 )
                    {
                      while ( 1 )
                      {
                        while ( 1 )
                        {
                          while ( 1 )
                          {
                            if ( *v2 == 0 )
                              goto LABEL_40;
                            v4 = dword_425448(v2, v15);
                            if ( v4 != 0 )
                            {
                              v5 = v4 - (_DWORD)v2;
                              qmemcpy(v12, v2, v5);
                              v2 = (_WORD *)((char *)v2 + v5);
                              *(_WORD *)((char *)v12 + v5) = 0;
                              v6 = sub_4011D4(v12, 0);
                              if ( v6 == -341877708 )
                              {
                                v7 = 443;
                                v8 = 0x800000;
                              }
                              else
                              {
                                if ( v6 != -343499520 )
                                  goto LABEL_21;
                                v7 = 80;
                                v8 = 0x400000;
                              }
                              v2 += 3;
                              dword_425444(v12, v2);
                              v9 = (_WORD *)dword_425450(v12, 47);
                              if ( v9 != nullptr )
                                *v9 = 0;
                              v25 = dword_425818(v26, v12, v7, 0);
                              if ( v25 != 0 )
                                break;
                            }
LABEL_21:
                            v2 += dword_42543C(v2) + 1;
                          }
                          v24 = dword_42582C(v25, v14, v19, 0, 0, 0, v8, 0);
                          if ( v24 != 0 )
                            break;
                          dword_425824(v25);
                          v25 = 0;
                          v2 += dword_42543C(v2) + 1;
                        }
                        if ( v7 != 443 )
                          break;
                        v17 = 0;
                        v16 = 4;
                        if ( dword_425820(v24, 31, &v17, &v16) != 0 )
                        {
                          v17 |= 0x84603300;
                          if ( dword_42581C(v24, 31, &v17, 4) != 0 )
                            break;
                        }
LABEL_39:
                        dword_425824(v25);
                        dword_425824(v24);
                        v25 = 0;
                        v24 = 0;
                        v2 += dword_42543C(v2) + 1;
                      }
                      v10 = dword_425430(v21);
                      v11 = dword_42543C(v23);
                      if ( dword_425830(v24, v23, v11, v21, v10, 0, 3) != 0 )
                      {
                        v16 = 16;
                        v17 = 0;
                        if ( dword_425828(v24, 19, v13) != 0 && v13[0] == 50 && v13[1] == 48 && v13[2] == 48 )
                        {
                          v16 = 0;
                          if ( dword_425834(v24, &v16, 0, 0) != 0 )
                          {
                            v20 = (_BYTE *)sub_406830(v16 + 1);
                            if ( v20 == nullptr
                              || dword_425838(v24, v20, v16, &v16) != 0 && *v20 == 123 && v20[v16 - 1] == 125 )
                            {
                              break;
                            }
                            sub_40684C((int)v20);
                            v20 = nullptr;
                          }
                        }
                        goto LABEL_39;
                      }
                      dword_425824(v25);
                      dword_425824(v24);
                      v25 = 0;
                      v24 = 0;
                      v2 += dword_42543C(v2) + 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_40:
  if ( v24 != 0 )
    dword_425824(v24);
  if ( v25 != 0 )
    dword_425824(v25);
  if ( v26 != 0 )
    dword_425824(v26);
  if ( v19 != 0 )
    sub_40684C(v19);
  if ( v23 != nullptr )
    sub_40684C((int)v23);
  if ( v22 != 0 )
    sub_40684C(v22);
  if ( v20 != nullptr )
    sub_40684C((int)v20);
  if ( v21 != 0 )
    sub_40684C(v21);
  if ( v18 != nullptr )
    sub_40684C((int)v18);
}


/* sub_40D40C @ 0040D40C */
_WORD *sub_40D40C()
{
  _WORD *v0; // edi
  unsigned int v1; // ebx
  _WORD *v2; // edi
  unsigned int v3; // ebx
  _WORD *v4; // edi
  int v5; // eax
  _WORD *v6; // edi
  int v8[16]; // [esp+Ch] [ebp-B0h] BYREF
  int v9[3]; // [esp+4Ch] [ebp-70h] BYREF
  _BYTE v10[66]; // [esp+58h] [ebp-64h] BYREF
  _BYTE v11[22]; // [esp+9Ah] [ebp-22h] BYREF
  _WORD *v12; // [esp+B0h] [ebp-Ch]
  unsigned int v13; // [esp+B4h] [ebp-8h]
  _WORD *v14; // [esp+B8h] [ebp-4h]

  v14 = nullptr;
  v8[0] = -205585799;
  v8[1] = -4520323;
  v8[2] = -71890319;
  v8[3] = -407695755;
  v8[4] = -475065751;
  v8[5] = -274000275;
  v8[6] = -711124383;
  v8[7] = -778492837;
  v8[8] = -577427361;
  v8[9] = -644797357;
  v8[10] = -980602793;
  v8[11] = -1047972789;
  v8[12] = -846907313;
  v8[13] = -2066845432;
  v8[14] = -2134215412;
  v8[15] = -1208190720;
  sub_401250(v8, 16);
  v9[0] = -1215348707;
  v9[1] = -1210499067;
  v9[2] = -1208205237;
  sub_401250(v9, 3);
  v13 = sub_401124(1u, 0x14u);
  v14 = (_WORD *)sub_406830(72 * v13);
  if ( v14 != nullptr )
  {
    v0 = v14;
    *v14 = 47;
    *++v0 = 63;
    v12 = v0 + 1;
    do
    {
      v1 = sub_401124(3u, 0xAu);
      v2 = v11;
      do
      {
        *v2++ = *((unsigned __int8 *)v8 + sub_401124(0, 0x3Eu));
        --v1;
      }
      while ( v1 != 0 );
      *v2 = 0;
      v3 = sub_401124(3u, 0x14u);
      v4 = v10;
      do
      {
        *v4++ = *((unsigned __int8 *)v8 + sub_401124(0, 0x3Eu));
        --v3;
      }
      while ( v3 != 0 );
      *v4 = 0;
      v5 = dword_425464(v12, v9, v11, v10);
      v12 += v5;
      if ( v13 != 1 )
      {
        v6 = v12;
        *v12 = 38;
        v12 = v6 + 1;
      }
      --v13;
    }
    while ( v13 != 0 );
  }
  return v14;
}


/* sub_40D594 @ 0040D594 */
void *sub_40D594()
{
  _DWORD *v0; // ebx
  unsigned int v1; // eax
  int i; // ecx

  v0 = &unk_41D02E;
  v1 = sub_401124(0, 6u);
  for ( i = 0; i != v1; ++i )
    v0 = (_DWORD *)((char *)v0 + *(v0 - 1) + 4);
  return sub_406DB0(v0);
}


/* sub_40D5D8 @ 0040D5D8 */
_BYTE *__stdcall sub_40D5D8(unsigned int *a1, _BYTE *a2)
{
  unsigned int v2; // eax
  unsigned int v3; // ebx
  int v4; // eax
  int v5; // eax
  unsigned int v6; // ebx
  _BYTE *v7; // edi
  _BYTE *v8; // edi
  unsigned int v9; // ebx
  _BYTE *v10; // edi
  int v11; // eax
  _BYTE *v12; // edi
  int v14; // [esp+0h] [ebp-C0h]
  int v15; // [esp+4h] [ebp-BCh]
  int v16; // [esp+8h] [ebp-B8h]
  int v17[16]; // [esp+Ch] [ebp-B4h] BYREF
  int v18[5]; // [esp+4Ch] [ebp-74h] BYREF
  int v19[2]; // [esp+60h] [ebp-60h] BYREF
  _BYTE v20[33]; // [esp+6Bh] [ebp-55h] BYREF
  _BYTE v21[32]; // [esp+8Ch] [ebp-34h] BYREF
  _BYTE *v22; // [esp+ACh] [ebp-14h]
  unsigned int v23; // [esp+B0h] [ebp-10h]
  unsigned int v24; // [esp+B4h] [ebp-Ch]
  unsigned int v25; // [esp+B8h] [ebp-8h]
  _BYTE *v26; // [esp+BCh] [ebp-4h]

  v26 = nullptr;
  v19[0] = -1832832227;
  v19[1] = -1208205237;
  sub_401250(v19, 2);
  v18[0] = -809210339;
  v18[1] = -809210339;
  v18[2] = -809210339;
  v18[3] = -809210339;
  v18[4] = -1208205283;
  sub_401250(v18, 5);
  v17[0] = -205585799;
  v17[1] = -4520323;
  v17[2] = -71890319;
  v17[3] = -407695755;
  v17[4] = -475065751;
  v17[5] = -274000275;
  v17[6] = -711124383;
  v17[7] = -778492837;
  v17[8] = -577427361;
  v17[9] = -644797357;
  v17[10] = -980602793;
  v17[11] = -1047972789;
  v17[12] = -846907313;
  v17[13] = -2066845432;
  v17[14] = -2134215412;
  v17[15] = -1208190720;
  sub_401250(v17, 16);
  v25 = sub_401124(5u, 0x14u);
  do
  {
    v24 = sub_401124(1u, v25);
    v2 = sub_401124(1u, v25);
  }
  while ( v24 == v2 );
  v23 = v2;
  v3 = 35 * v25;
  v4 = dword_425430(a2);
  v5 = sub_406830(v4 + v3 + 34);
  v26 = (_BYTE *)v5;
  if ( v5 != 0 )
  {
    v22 = v26;
    do
    {
      v6 = sub_401124(3u, 0xAu);
      v7 = v21;
      do
      {
        *v7++ = *((_BYTE *)v17 + sub_401124(0, 0x3Eu));
        --v6;
      }
      while ( v6 != 0 );
      *v7 = 0;
      if ( v24 == v25 )
      {
        v8 = v20;
        dword_425468(
          v20,
          v18,
          _byteswap_ulong(*a1),
          _byteswap_ulong(a1[1]),
          _byteswap_ulong(a1[2]),
          _byteswap_ulong(a1[3]),
          v14,
          v15);
      }
      else if ( v23 == v25 )
      {
        v8 = a2;
      }
      else
      {
        v9 = sub_401124(3u, 0x14u);
        v10 = v20;
        do
        {
          *v10++ = *((_BYTE *)v17 + sub_401124(0, 0x3Eu));
          --v9;
        }
        while ( v9 != 0 );
        *v10 = 0;
        v8 = v20;
      }
      v11 = dword_425468(v22, v19, v21, v8, v14, v15, v16, v17[0]);
      v22 += v11;
      if ( v25 != 1 )
      {
        v12 = v22;
        *v22 = 38;
        v22 = v12 + 1;
      }
      --v25;
    }
    while ( v25 != 0 );
  }
  return v26;
}


/* sub_40D7E8 @ 0040D7E8 */
void __usercall sub_40D7E8(int a1@<edx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
  int v4; // ebx
  int v5; // ebx
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  _BYTE v11[16]; // [esp+4h] [ebp-28h] BYREF
  int v12[2]; // [esp+14h] [ebp-18h] BYREF
  unsigned int *v13; // [esp+1Ch] [ebp-10h]
  void *v14; // [esp+20h] [ebp-Ch]
  int v15; // [esp+24h] [ebp-8h]
  __int16 *v16; // [esp+28h] [ebp-4h]

  v15 = 0;
  v14 = nullptr;
  v13 = nullptr;
  v16 = sub_40CC60();
  if ( v16 != nullptr )
  {
    v15 = sub_40CE38();
    if ( v15 != 0 )
    {
      v12[0] = -1831717603;
      v12[1] = -1208205235;
      sub_401250(v12, 2);
      dword_425468(v11, v12, 1, 0, a3, a4, a1, a2);
      v14 = sub_406DB0(dword_41D23C);
      if ( v14 != nullptr )
      {
        v4 = dword_425430(v14);
        v5 = dword_425430(v11) + v4;
        v6 = dword_425430(v16) + v5;
        v7 = dword_425430(v15);
        v13 = (unsigned int *)sub_406830(v7 + v6 + 260);
        if ( v13 != nullptr )
        {
          v8 = dword_425468(
                 v13,
                 v14,
                 v11,
                 v15,
                 _byteswap_ulong(unk_425100),
                 _byteswap_ulong(unk_425104),
                 _byteswap_ulong(unk_425108),
                 _byteswap_ulong(unk_42510C));
          sub_40CF28(v13, v8);
        }
      }
    }
  }
  if ( v15 != 0 )
    sub_40684C(v15);
  if ( v16 != nullptr )
    sub_40684C((int)v16);
  if ( v14 != nullptr )
    sub_40684C((int)v14);
  if ( v13 != nullptr )
    sub_40684C((int)v13);
}


/* sub_40D95C @ 0040D95C */
void __userpurge sub_40D95C(int a1@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>, int a5, int a6, int a7)
{
  int v7; // ebx
  int v8; // eax
  __int64 v9; // rax
  int v10; // eax
  _BYTE v12[32]; // [esp+4h] [ebp-44h] BYREF
  _BYTE v13[16]; // [esp+24h] [ebp-24h] BYREF
  int v14[2]; // [esp+34h] [ebp-14h] BYREF
  unsigned int *v15; // [esp+3Ch] [ebp-Ch]
  void *v16; // [esp+40h] [ebp-8h]
  int v17; // [esp+44h] [ebp-4h]

  v16 = nullptr;
  v15 = nullptr;
  v17 = sub_40CE38();
  if ( v17 != 0 )
  {
    v14[0] = -1831717603;
    v14[1] = -1208205235;
    sub_401250(v14, 2);
    ((void (__cdecl *)(_BYTE *, int *, int, _DWORD, int, int, int))dword_425468)(v13, v14, 1, 0, a3, a4, a1);
    v16 = sub_406DB0(dword_41D292);
    if ( v16 != nullptr )
    {
      v7 = dword_425430(v16) + a2;
      v8 = dword_425430(v17);
      v15 = (unsigned int *)sub_406830(v8 + v7 + 260);
      if ( v15 != nullptr )
      {
        v9 = dword_425470(dword_425188, dword_42518C, 0x100000, 0);
        dword_42546C(v9, HIDWORD(v9), v12, 10);
        v10 = dword_425468(
                v15,
                v16,
                v13,
                v17,
                _byteswap_ulong(unk_425100),
                _byteswap_ulong(unk_425104),
                _byteswap_ulong(unk_425108),
                _byteswap_ulong(unk_42510C));
        sub_40CF28(v15, v10);
      }
    }
  }
  if ( v17 != 0 )
    sub_40684C(v17);
  if ( v16 != nullptr )
    sub_40684C((int)v16);
  if ( v15 != nullptr )
    sub_40684C((int)v15);
}


/* sub_40DAEC @ 0040DAEC */
int __stdcall sub_40DAEC(int a1)
{
  _BYTE v2[28]; // [esp+0h] [ebp-50h] BYREF
  int v3; // [esp+1Ch] [ebp-34h]
  _BYTE v4[28]; // [esp+24h] [ebp-2Ch] BYREF
  _BYTE v5[4]; // [esp+40h] [ebp-10h] BYREF
  int v6; // [esp+44h] [ebp-Ch]
  int v7; // [esp+48h] [ebp-8h]
  int v8; // [esp+4Ch] [ebp-4h]

  v8 = 0;
  v7 = dword_425624(0, 0, 4);
  if ( v7 != 0 )
  {
    v6 = dword_42562C(v7, a1, 65568);
    if ( v6 != 0 )
    {
      dword_425428(v4, 0, 28);
      if ( dword_425640(v6, 1, v4) == 0 )
      {
        dword_425428(v2, 0, 36);
        if ( dword_42563C(v6, 0, v2, 36, v5) != 0 )
          sub_40DBBC(v3);
      }
      dword_425644(v6);
      dword_425648(v6);
      v8 = 1;
    }
  }
  if ( v7 != 0 )
    dword_425648(v7);
  return v8;
}


/* sub_40DBBC @ 0040DBBC */
int __stdcall sub_40DBBC(int a1)
{
  _DWORD v2[6]; // [esp+0h] [ebp-28h] BYREF
  _DWORD v3[2]; // [esp+18h] [ebp-10h] BYREF
  int v4; // [esp+20h] [ebp-8h] BYREF
  int v5; // [esp+24h] [ebp-4h]

  v5 = 0;
  v3[0] = a1;
  v3[1] = 0;
  v2[0] = 24;
  memset(&v2[1], 0, 20);
  if ( dword_425474(&v4, 1, v2, v3) == 0 )
  {
    dword_4254C8(v4, 0);
    dword_4254D0(v4);
    return 1;
  }
  return v5;
}


/* sub_40DC40 @ 0040DC40 */
int __stdcall sub_40DC40(char a1)
{
  int v1; // eax
  int v2; // ebx
  int *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  _BYTE v8[80]; // [esp+8h] [ebp-6Ch] BYREF
  int v9; // [esp+58h] [ebp-1Ch] BYREF
  int v10; // [esp+5Ch] [ebp-18h] BYREF
  int v11; // [esp+60h] [ebp-14h] BYREF
  int *v12; // [esp+64h] [ebp-10h]
  int v13; // [esp+68h] [ebp-Ch] BYREF
  HANDLE UniqueProcess; // [esp+6Ch] [ebp-8h]
  int v15; // [esp+70h] [ebp-4h]

  v15 = 0;
  v12 = nullptr;
  v13 = 1208205255;
  UniqueProcess = NtCurrentTeb()->ClientId.UniqueProcess;
  dword_425428(v8, 0, 80);
  if ( dword_4257BC(&v13, 0, v8) == 0 )
  {
    if ( dword_4257C0(v13, 1, &a1, 0, 0, 0, 0) == 0 )
    {
      v10 = 0;
      v9 = 0;
      v11 = 1;
      v12 = (int *)sub_406830(668);
      if ( v12 != nullptr )
      {
        do
        {
          v1 = dword_4257C4(v13, &v10, &v11, v12, &v9);
          if ( v1 != 234 )
            break;
          v11 = v10;
          v1 = sub_406868((int)v12, 668 * v10);
          v12 = (int *)v1;
        }
        while ( v1 != 0 );
        if ( v1 == 0 )
        {
          v2 = v10;
          if ( v10 != 0 )
          {
            v3 = v12;
            do
            {
              v4 = v3[163];
              if ( v4 == 1000 || v4 == 4 )
                break;
              if ( v4 == 3 )
              {
                v5 = sub_40DAEC((int)(v3 + 131));
                v15 += v5;
              }
              else if ( UniqueProcess != (HANDLE)*v3 )
              {
                v6 = sub_40DBBC(*v3);
                v15 += v6;
              }
              v3 += 167;
              --v2;
            }
            while ( v2 != 0 );
          }
        }
      }
    }
    dword_4257C8(v13);
  }
  if ( v12 != nullptr )
    sub_40684C((int)v12);
  return v15;
}


/* sub_40DDA4 @ 0040DDA4 */
int __stdcall sub_40DDA4(char a1)
{
  int v1; // ebx

  v1 = 0;
  if ( (unsigned int)sub_401574() > 0x3C )
    v1 = sub_40DC40(a1);
  if ( v1 != 0 )
    dword_42553C(200);
  return v1;
}


/* sub_40DDD4 @ 0040DDD4 */
int sub_40DDD4()
{
  int result; // eax
  _DWORD *v1; // ebx
  int v2; // eax
  int v3; // edx
  __int64 v4; // rax
  int v5; // esi
  _BYTE v6[4]; // [esp+0h] [ebp-10h] BYREF
  unsigned int v7; // [esp+4h] [ebp-Ch] BYREF
  int v8; // [esp+8h] [ebp-8h]
  _DWORD *v9; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  dword_42559C(-2, 2);
  while ( 1 )
  {
    while ( 1 )
    {
      result = dword_425554(dword_425880, &v7, v6, &v9, -1);
      v1 = v9;
      if ( result != 0 || __readfsdword(0x34u) != 38 )
        break;
      v9[10] = 2;
      while ( dword_425558(dword_425880, 0, 0, v1) == 0 )
        ;
    }
    if ( v9 == nullptr )
      return result;
    while ( 1 )
    {
      v2 = v1[10];
      switch ( v2 )
      {
        case 0:
          v3 = v1[6];
          v1[2] = v1[5];
          v1[3] = v3;
          v1[10] = 1;
          if ( dword_425530(v1[9], v1 + 231, v1[230], &v7, v1) == 0 && __readfsdword(0x34u) != 997 )
          {
            if ( __readfsdword(0x34u) == 38 )
            {
              v1[10] = 2;
              dword_425558(dword_425880, 0, 0, v1);
            }
            else
            {
              do
                dword_42553C(100);
              while ( dword_425530(v1[9], v1 + 231, v1[230], &v7, v1) == 0 && __readfsdword(0x34u) != 997 );
            }
          }
          goto LABEL_38;
        case 1:
          dword_425674(v1 + 198, 128, 0);
          sub_4020BC(v7, (__m128i *)(v1 + 231), (unsigned int)(v1 + 198));
          dword_425670(v1 + 198, 128, 0);
          if ( v1[12] != 0 )
          {
            *(_QWORD *)(v1 + 5) += 0x20000LL;
            --v1[12];
            v1[10] = 0;
          }
          else
          {
            v4 = *(_QWORD *)(v1 + 7);
            if ( v4 != 0 )
            {
              *(_QWORD *)(v1 + 5) += v4;
              v1[12] = v1[11];
              v1[10] = 0;
            }
            else
            {
              v1[10] = 2;
            }
          }
          while ( dword_42552C(v1[9], v1 + 231, v7, &v7, v1) == 0 && __readfsdword(0x34u) != 997 )
            dword_42553C(100);
          goto LABEL_38;
        case 2:
          v1[2] = -1;
          v1[3] = -1;
          v1[10] = 3;
          v5 = (int)v1 - v1[13] + 792;
          v8 = dword_42552C(v1[9], v5, v1[13], &v7, v1);
          if ( v8 == 0 && __readfsdword(0x34u) != 997 )
          {
            do
              dword_42553C(100);
            while ( dword_42552C(v1[9], v5, v1[13], &v7, v1) == 0 && __readfsdword(0x34u) != 997 );
          }
          goto LABEL_38;
        default:
          break;
      }
      if ( v2 == 3 )
        break;
LABEL_38:
      while ( 1 )
      {
        result = dword_425554(dword_425880, &v7, v6, &v9, -1);
        v1 = v9;
        if ( result != 0 )
          break;
        if ( __readfsdword(0x34u) == 38 )
        {
          v9[10] = 2;
          while ( dword_425558(dword_425880, 0, 0, v1) == 0 )
            ;
        }
      }
      if ( v9 == nullptr )
        return result;
    }
    if ( v8 == 0 )
    {
      while ( *v1 == 259 )
        dword_42553C(1);
    }
    dword_4254D0(v1[9]);
    sub_401094(v1, 0, v1[230] + 924);
    sub_40684C((int)v1);
    dword_42555C(&dword_425888);
  }
}


/* sub_40E144 @ 0040E144 */
int sub_40E144()
{
  int v0; // ebx
  int v1; // ebx
  int v2; // eax
  int v3; // esi
  int v5; // [esp+8h] [ebp-4h]

  v0 = sub_401564();
  if ( (v0 & 0x20) != 0 )
    v0 = 32;
  v1 = 2 * v0 + 1;
  v5 = 0;
  dword_425880 = dword_425550(-1, 0, 0, v1);
  if ( dword_425880 != 0 )
  {
    do
    {
      v2 = dword_42551C(0, 0, sub_40DDD4, 0, 0, 0);
      v3 = v2;
      if ( v2 != 0 )
      {
        sub_40B414(v2);
        dword_4254D0(v3);
        ++v5;
      }
      --v1;
    }
    while ( v1 != 0 );
  }
  dword_4254AC(&unk_425890);
  return v5;
}


/* sub_40E1CC @ 0040E1CC */
int __stdcall sub_40E1CC(int a1)
{
  int v1; // ebx

  v1 = a1;
  if ( a1 != 0 )
  {
    do
    {
      dword_425558(dword_425880, 0, 0, 0);
      --v1;
    }
    while ( v1 != 0 );
    if ( dword_425880 != 0 )
      dword_4254D0(dword_425880);
  }
  return dword_4254B8(&unk_425890);
}


/* sub_40E214 @ 0040E214 */
int sub_40E214()
{
  int *v0; // eax
  int v2; // [esp+0h] [ebp-4h]

  v2 = 0;
  sub_4056F8(&unk_425080, &unk_424F70);
  dword_425670(&unk_425080, 128, 0);
  sub_40107C(xmmword_424FF4, &unk_425080, 128);
  dword_425674(xmmword_424FF4, 128, 0);
  sub_4017C4(xmmword_424FF4, (int)&unk_424F70);
  v0 = (int *)sub_40E2AC(xmmword_424FF4, 128);
  if ( v0 != nullptr )
  {
    dword_424FF0 = *v0;
    sub_40684C((int)v0);
    return 1;
  }
  return v2;
}


/* sub_40E2AC @ 0040E2AC */
_DWORD *__stdcall sub_40E2AC(unsigned __int8 *a1, unsigned int a2)
{
  _DWORD *v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // eax

  v2 = nullptr;
  if ( a2 != 0 && a1 != nullptr )
  {
    v2 = (_DWORD *)sub_406830(4);
    if ( v2 != nullptr )
    {
      v3 = sub_401274(a1, a2, 0xD6917Au);
      v4 = sub_401274(a1, a2, _byteswap_ulong(v3));
      *v2 = _byteswap_ulong(sub_401274(a1, a2, _byteswap_ulong(v4)));
    }
  }
  return v2;
}


/* sub_40E308 @ 0040E308 */
int __stdcall sub_40E308(int a1)
{
  int v2; // [esp+4h] [ebp-Ch]
  int v3; // [esp+8h] [ebp-8h]
  int v4; // [esp+Ch] [ebp-4h]

  v3 = 0;
  v4 = 0;
  while ( 1 )
  {
    dword_425500(a1, 128);
    v2 = dword_425528(a1, 0x40000000, 0, 0, 3, 0, 0);
    if ( v2 != -1 )
      break;
    if ( __readfsdword(0x34u) == 32 )
    {
      if ( sub_40DDA4(a1) == 0 )
        goto LABEL_12;
    }
    else
    {
      if ( __readfsdword(0x34u) != 5 || v4 != 0 )
        goto LABEL_12;
      sub_407260(a1);
      v4 = 1;
    }
  }
  v3 = 1;
LABEL_12:
  if ( v2 != -1 )
    dword_4254D0(v2);
  return v3;
}


/* sub_40E3B8 @ 0040E3B8 */
int __stdcall sub_40E3B8(int a1)
{
  _DWORD *v1; // ebx
  int v3; // [esp+4h] [ebp-90h] BYREF
  unsigned __int8 v4[128]; // [esp+8h] [ebp-8Ch] BYREF
  _BYTE v5[4]; // [esp+88h] [ebp-Ch] BYREF
  int v6; // [esp+8Ch] [ebp-8h]
  int v7; // [esp+90h] [ebp-4h]

  v7 = 0;
  dword_425500(a1, 128);
  v6 = dword_425528(a1, 0x80000000, 0, 0, 3, 0, 0);
  if ( v6 != -1 )
  {
    if ( dword_425544(v6, -132, -1, 0, 2) != 0 && dword_425530(v6, &v3, 132, v5, 0) != 0 )
    {
      v1 = sub_40E2AC(v4, 0x80u);
      if ( v1 != nullptr )
      {
        if ( *v1 == v3 )
          v7 = 1;
        sub_40684C((int)v1);
      }
    }
    dword_4254D0(v6);
  }
  return v7;
}


/* sub_40E478 @ 0040E478 */
int __stdcall sub_40E478(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return 0;
}


/* sub_40E7C4 @ 0040E7C4 */
int __stdcall sub_40E7C4(_WORD *a1)
{
  int v1; // ebx
  __int16 *v2; // esi
  int v3; // eax
  int v4; // eax
  int v6; // [esp+8h] [ebp-4h]

  v6 = 0;
  v1 = sub_4011D4(a1, 0);
  v2 = &word_40E48E;
  while ( 1 )
  {
    v3 = *(_DWORD *)v2;
    v2 += 2;
    v4 = v3 ^ 0x4803BFC7;
    if ( v4 == v1 )
      break;
    if ( v4 == 0 )
      return v6;
  }
  return 1;
}


/* sub_40E808 @ 0040E808 */
int __stdcall sub_40E808(int a1, unsigned __int64 a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  unsigned __int64 v5; // rax
  _WORD *v6; // ebx
  unsigned __int64 v7; // rax
  unsigned __int8 v8; // cl
  unsigned __int64 v9; // rax
  unsigned __int8 v10; // cl
  unsigned __int64 v11; // rax
  unsigned __int8 v12; // cl
  unsigned __int64 v13; // rax
  unsigned __int8 v14; // cl
  unsigned __int64 v15; // rax
  unsigned __int8 v16; // cl
  unsigned __int64 v17; // rax
  unsigned __int8 v18; // cl
  unsigned __int64 v19; // rax
  unsigned __int8 v20; // cl
  int v22; // [esp+Ch] [ebp-4h]

  v22 = 0;
  LODWORD(v5) = dword_425768(a1);
  if ( *(_WORD *)v5 != 0 )
  {
    v6 = (_WORD *)(v5 + 2);
    LODWORD(v5) = sub_40E478(v5 + 2, a2, SHIDWORD(a2), (int)a3, (int)a4, (int)a5);
    if ( (_DWORD)v5 != 0 )
      return v5;
    if ( byte_425120 == 0 )
    {
      LODWORD(v5) = sub_40E7C4(v6);
      v22 = v5;
    }
  }
  if ( byte_425120 != 0 || v22 != 0 )
  {
    if ( a2 >= 0x4000000 )
    {
      LODWORD(v7) = sub_40105C(0x4000000, 2u);
      if ( a2 >= v7 )
      {
        LODWORD(v9) = sub_40105C(v7, v8);
        if ( a2 >= v9 )
        {
          LODWORD(v11) = sub_40105C(v9, v10);
          if ( a2 >= v11 )
          {
            LODWORD(v13) = sub_40105C(v11, v12);
            if ( a2 >= v13 )
            {
              LODWORD(v15) = sub_40105C(v13, v14);
              if ( a2 >= v15 )
              {
                LODWORD(v17) = sub_40105C(v15, v16);
                if ( a2 >= v17 )
                {
                  LODWORD(v19) = sub_40105C(v17, v18);
                  if ( a2 >= v19 )
                  {
                    LODWORD(v5) = sub_40105C(v19, v20);
                    if ( a2 >= v5 )
                    {
                      *a3 = 0;
                      a3[1] = 0;
                      *a4 = 1999;
                      *a5 = 0;
                    }
                    else
                    {
                      *(_QWORD *)a3 = 0x61A820000LL;
                      *a4 = 199;
                      *a5 = 199;
                      LODWORD(v5) = 444727296;
                    }
                  }
                  else
                  {
                    *(_QWORD *)a3 = 0x2EE020000LL;
                    *a4 = 199;
                    *a5 = 199;
                    LODWORD(v5) = -301858816;
                  }
                }
                else
                {
                  *(_QWORD *)a3 = 3145859072LL;
                  *a4 = 199;
                  *a5 = 79;
                  LODWORD(v5) = -1149108224;
                }
              }
              else
              {
                *(_QWORD *)a3 = 1048707072;
                *a4 = 199;
                *a5 = 39;
                LODWORD(v5) = 1048707072;
              }
            }
            else
            {
              *(_QWORD *)a3 = 524419072;
              *a4 = 119;
              *a5 = 39;
              LODWORD(v5) = 524419072;
            }
          }
          else
          {
            *(_QWORD *)a3 = 104988672;
            *a4 = 119;
            *a5 = 19;
            LODWORD(v5) = 104988672;
          }
        }
        else
        {
          *(_QWORD *)a3 = 31588352;
          *a4 = 39;
          *a5 = 7;
          LODWORD(v5) = 31588352;
        }
      }
      else
      {
        *(_QWORD *)a3 = 15859712;
        *a4 = 39;
        *a5 = 3;
        LODWORD(v5) = 15859712;
      }
    }
    else
    {
      *(_QWORD *)a3 = 5373952;
      *a4 = 3;
      *a5 = 3;
      LODWORD(v5) = 5373952;
    }
  }
  else
  {
    *a3 = 0;
    a3[1] = 0;
    *a4 = 3;
    *a5 = 0;
  }
  return v5;
}


/* sub_40EB34 @ 0040EB34 */
BOOL __stdcall sub_40EB34(int a1)
{
  return byte_425121 == 0;
}


/* sub_40EB5C @ 0040EB5C */
int __stdcall sub_40EB5C(int a1, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // ebx

  v2 = dword_42543C(a2);
  v3 = sub_4068FC(a1, v2);
  v4 = v3;
  if ( v3 != 0 )
    dword_425440(v3, a2);
  return v4;
}


/* sub_40EB90 @ 0040EB90 */
__int16 __stdcall sub_40EB90(_WORD *a1, int a2)
{
  if ( unk_4258A8 == 0 )
  {
    unk_4258A8 = -205585799;
    unk_4258B0 = -4520323;
    unk_4258AC = -71890319;
    unk_4258B8 = -407695755;
    unk_4258B4 = -475065751;
    unk_4258C0 = -274000275;
    unk_4258BC = -711124383;
    unk_4258C8 = -778492837;
    unk_4258C4 = -577427361;
    unk_4258D0 = -644797357;
    unk_4258CC = -980602793;
    unk_4258D8 = -1047972789;
    unk_4258D4 = -846907313;
    unk_4258E0 = -2066845432;
    unk_4258DC = -2134215412;
    unk_4258E4 = -1208190720;
    sub_401250((int *)&unk_4258A8, 16);
  }
  do
  {
    *a1++ = *((unsigned __int8 *)&unk_4258A8 + sub_401124(0, 0x3Du));
    --a2;
  }
  while ( a2 != 0 );
  *a1 = 0;
  return 0;
}


/* sub_40EC40 @ 0040EC40 */
int __stdcall sub_40EC40(int a1, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // ebx
  _WORD *v5; // esi

  v2 = dword_42543C(a2);
  v3 = sub_4068FC(a1, v2 + 7);
  v4 = v3;
  if ( v3 != 0 )
  {
    v5 = (_WORD *)dword_425770(v3);
    sub_40EB90(v5, 7);
    dword_425440(v5, a2);
  }
  return v4;
}


/* sub_40EC8C @ 0040EC8C */
int __stdcall sub_40EC8C(int a1, unsigned __int64 a2)
{
  int v2; // esi
  int v3; // eax
  int v4; // esi
  unsigned int v5; // eax
  unsigned int v6; // esi
  int v7; // eax
  const void *v9; // [esp+Ch] [ebp-10h]
  int v10; // [esp+10h] [ebp-Ch]
  int v11; // [esp+14h] [ebp-8h]
  void *v12; // [esp+18h] [ebp-4h]

  v10 = 0;
  v9 = nullptr;
  v12 = nullptr;
  dword_4254B0(&unk_425890);
  if ( a2 >= 0x20000 )
    v2 = 0x20000;
  else
    v2 = a2;
  if ( _InterlockedCompareExchange(&dword_42588C, 0, 1000) == 1000 )
    sub_40E214();
  v11 = sub_406830(v2 + 924);
  if ( v11 != 0 )
  {
    *(_DWORD *)(v11 + 920) = v2;
    sub_4056F0();
    dword_425670(v11 + 792, 128, 0);
    sub_40107C((void *)(v11 + 660), &dword_424FF0, 0x84u);
    v10 = sub_406830(655360);
    if ( v10 != 0 )
    {
      v3 = dword_42543C(a1);
      v4 = 2 * v3 + 2;
      v9 = (const void *)sub_406830((2 * v3 + 33) & 0xFFFFFFF0);
      if ( v9 != nullptr )
      {
        v5 = sub_418B54(a1, v9, v4, v10, 0, 0);
        v6 = v5;
        if ( v5 != -1 )
        {
          *(_WORD *)(v11 + 576) = v5;
          sub_40107C((void *)(v11 + 576 - v5), v9, v5);
          v7 = 658 - (576 - v6);
          *(_WORD *)(v11 + 658) = v7;
          *(_DWORD *)(v11 + 52) = v7 + 134;
          sub_40E808(a1, a2, (_DWORD *)(v11 + 28), (_DWORD *)(v11 + 48), (_DWORD *)(v11 + 44));
          *(_DWORD *)(v11 + 578) = *(_DWORD *)(v11 + 28);
          *(_DWORD *)(v11 + 582) = *(_DWORD *)(v11 + 32);
          *(_DWORD *)(v11 + 586) = *(_DWORD *)(v11 + 48);
          *(_DWORD *)(v11 + 590) = *(_DWORD *)(v11 + 44);
          v12 = (void *)sub_406830(128);
          if ( v12 != nullptr )
          {
            sub_40107C(v12, &unk_425080, 0x80u);
            dword_425674(v12, 128, 0);
            sub_4020BC(*(unsigned __int16 *)(v11 + 658), (__m128i *)(v11 + 576 - v6), (unsigned int)v12);
          }
          else
          {
            sub_40684C(v11);
            v11 = 0;
          }
        }
      }
    }
  }
  if ( v10 != 0 )
    sub_40684C(v10);
  if ( v9 != nullptr )
    sub_40684C((int)v9);
  if ( v12 != nullptr )
    sub_40684C((int)v12);
  dword_4254B4(&unk_425890);
  return v11;
}


/* sub_40EEC8 @ 0040EEC8 */
int __stdcall sub_40EEC8(int a1, unsigned __int64 a2)
{
  int v2; // eax
  int v3; // ebx
  int v5; // [esp+Ch] [ebp-Ch]
  int v6; // [esp+10h] [ebp-8h]
  int v7; // [esp+14h] [ebp-4h]

  v7 = 0;
  if ( a1 != 0 )
  {
    if ( sub_40E308(a1) != 0 && sub_40E3B8(a1) == 0 )
    {
      v5 = sub_40EB34(a1) ? sub_40EB5C(a1, dword_425178) : sub_40EC40(a1, dword_425178);
      if ( v5 != 0 )
      {
        while ( dword_425518(a1, v5, 8) == 0 )
        {
          if ( __readfsdword(0x34u) != 183 )
          {
            sub_40684C(v5);
            v5 = 0;
            break;
          }
          sub_40684C(v5);
          v5 = sub_40EC40(a1, dword_425178);
          if ( v5 == 0 )
            break;
        }
        if ( v5 != 0 )
        {
          v6 = dword_425528(v5, -1073741824, 0, 0, 3, 0x40000000, 0);
          if ( v6 != -1 )
          {
            v2 = dword_425770(a1);
            v3 = sub_40EC8C(v2, a2);
            if ( v3 != 0 )
            {
              if ( dword_425550(v6, dword_425880, 0, 0) != 0
                && (*(_DWORD *)(v3 + 36) = v6, *(_DWORD *)(v3 + 40) = 0, dword_425558(dword_425880, 0, 0, v3) != 0) )
              {
                dword_42555C(&dword_42588C);
                dword_42555C(&dword_425884);
                v7 = 1;
              }
              else
              {
                dword_425428(v3, 0, 920);
                sub_40684C(v3);
                dword_4254D0(v6);
              }
            }
            else
            {
              dword_4254D0(v6);
            }
          }
        }
        if ( v5 != 0 )
          sub_40684C(v5);
      }
    }
    sub_40684C(a1);
  }
  return v7;
}


/* sub_40F0C0 @ 0040F0C0 */
int __stdcall sub_40F0C0(int a1)
{
  int v1; // ebx
  int v2; // eax
  int v3; // esi
  _DWORD *v4; // eax
  int v6; // [esp+8h] [ebp-4h]

  v6 = 0;
  v1 = dword_42543C(a1);
  if ( v1 != 0 )
  {
    v2 = sub_406830(2 * v1 + 8);
    v3 = v2;
    if ( v2 != 0 )
    {
      dword_425444(v2, a1);
      v4 = (_DWORD *)(v3 + 2 * v1);
      if ( *((_WORD *)v4 - 1) == 92 )
        v4 = (_DWORD *)((char *)v4 - 2);
      *v4 = 2752604;
      return v3;
    }
  }
  return v6;
}


/* sub_40F124 @ 0040F124 */
int __stdcall sub_40F124(int a1, int a2)
{
  int v2; // ebx
  int v3; // eax
  int v4; // esi

  v2 = dword_42543C(a1);
  v3 = dword_42543C(a2);
  v4 = sub_406830(2 * (v3 + v2) + 2);
  dword_425444(v4, a1);
  dword_425440(v4, a2);
  return v4;
}


/* sub_40F178 @ 0040F178 */
int __stdcall sub_40F178(_WORD *a1)
{
  int v1; // ebx
  int *v2; // esi
  int v3; // eax
  _WORD *v4; // eax
  int v5; // ebx
  int *v6; // esi
  int v7; // eax
  int v9; // [esp+8h] [ebp-4h]

  v9 = 0;
  if ( dword_42513C != 0 )
  {
    v1 = sub_4011D4(a1, 0);
    v2 = (int *)dword_42513C;
    while ( 1 )
    {
      v3 = *v2++;
      if ( v3 == 0 )
        break;
      if ( v1 == v3 )
      {
        v9 = 1;
        break;
      }
    }
  }
  if ( v9 == 0 && dword_425140 != 0 )
  {
    v4 = (_WORD *)dword_425768(a1);
    if ( *v4 != 0 )
    {
      v5 = sub_4011D4(v4 + 1, 0);
      v6 = (int *)dword_425140;
      while ( 1 )
      {
        v7 = *v6++;
        if ( v7 == 0 )
          break;
        if ( v5 == v7 )
          return 1;
      }
    }
  }
  return v9;
}


/* sub_40F210 @ 0040F210 */
int __stdcall sub_40F210(_WORD *a1)
{
  int v1; // ebx
  int *v2; // esi
  int v3; // eax
  int v5; // [esp+8h] [ebp-4h]

  v5 = 0;
  if ( dword_425138 != 0 )
  {
    v1 = sub_4011D4(a1, 0);
    v2 = (int *)dword_425138;
    while ( 1 )
    {
      v3 = *v2++;
      if ( v3 == 0 )
        break;
      if ( v1 == v3 || v1 == -482186025 )
        return 1;
    }
  }
  return v5;
}


/* sub_40F264 @ 0040F264 */
int __stdcall sub_40F264(_WORD *a1)
{
  int v2; // esi
  int v3; // esi
  int v4; // eax
  int *v11; // eax
  int v12; // ecx
  _BYTE v13[28]; // [esp+0h] [ebp-270h] BYREF
  unsigned int v14; // [esp+1Ch] [ebp-254h]
  unsigned int v15; // [esp+20h] [ebp-250h]
  _DWORD v16[137]; // [esp+2Ch] [ebp-244h] BYREF
  unsigned __int64 v17; // [esp+250h] [ebp-20h] BYREF
  int v18; // [esp+258h] [ebp-18h]
  _WORD *v19; // [esp+25Ch] [ebp-14h]
  int v20; // [esp+260h] [ebp-10h]
  int i; // [esp+264h] [ebp-Ch]
  int v22; // [esp+268h] [ebp-8h]
  int v23; // [esp+26Ch] [ebp-4h]

  if ( (dword_425504(a1) & 0x10) != 0 )
  {
    dword_42559C(-2, 2);
    if ( (unsigned int)sub_401574() <= 0x3C )
      v22 = 0;
    else
      v22 = 2;
    v18 = sub_406830(4000000);
    v19 = a1;
    for ( i = -1; ; --i )
    {
      sub_40C0F8((int)v19, &dword_425180);
      v20 = sub_40F0C0((int)v19);
      sub_40684C((int)v19);
      v23 = dword_425508(v20, 0, v13, 0, 0, v22);
      if ( v23 != -1 )
      {
        *(_WORD *)dword_425450(v20, 42) = 0;
        do
        {
          if ( v16[0] != 46 && v16[0] != 3014702 && (v13[0] & 4) == 0 && (byte_425123 == 0 || (v13[0] & 2) == 0) )
          {
            if ( (v13[0] & 0x10) != 0 )
            {
              if ( sub_40F210(v16) == 0 )
              {
                v2 = sub_40F124(v20, (int)v16);
                ++i;
                *(_DWORD *)(v18 + 4 * i) = v2;
              }
            }
            else if ( sub_40F178(v16) == 0 && (v14 != 0 || v15 != 0) && sub_40BB50(v16, 0) == 0 )
            {
              v3 = sub_40F124(v20, (int)v16);
              sub_407260(v3);
              v4 = sub_40EEC8(v3, __PAIR64__(v14, v15));
              if ( byte_42512D != 0 )
              {
                if ( v4 != 0 )
                {
                  dword_42555C(&dword_425184);
                  _EDX = v14;
                  _InterlockedAdd(&dword_425188, v15);
                  __asm { lock adc dword_42518C, edx }
                }
                else
                {
                  dword_42555C(&dword_425190);
                }
              }
            }
          }
        }
        while ( dword_42550C(v23, v13) != 0 );
        dword_425510(v23);
      }
      sub_40684C(v20);
      v20 = 0;
      if ( i == -1 )
        break;
      v11 = (int *)(v18 + 4 * i);
      v12 = *v11;
      *v11 = 0;
      v19 = (_WORD *)v12;
    }
    return sub_40684C(v18);
  }
  else if ( sub_40BB50(a1, 1) == 0 && sub_40A064((int)a1, &v17) != 0 && v17 != 0 )
  {
    sub_40C0F8((int)a1, nullptr);
    sub_407260((int)a1);
    return sub_40EEC8((int)a1, v17);
  }
  else
  {
    return sub_40684C((int)a1);
  }
}


/* sub_40F4D4 @ 0040F4D4 */
int __stdcall sub_40F4D4(_DWORD *a1)
{
  return dword_4257D4(*a1, a1[1], a1[2], a1[3], a1[4], a1[5], a1[6]);
}


/* sub_40F4F8 @ 0040F4F8 */
int __stdcall sub_40F4F8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  _DWORD v10[7]; // [esp+4h] [ebp-24h] BYREF
  int v11; // [esp+20h] [ebp-8h] BYREF
  int v12; // [esp+24h] [ebp-4h]

  v11 = -1;
  v12 = 0;
  v10[0] = a2;
  v10[1] = a3;
  v10[2] = a4;
  v10[3] = a5;
  v10[4] = a6;
  v10[5] = a7;
  v10[6] = a8;
  v12 = dword_42551C(0, 0, sub_40F4D4, v10, 4, 0);
  if ( v12 != 0 )
  {
    if ( a1 != 0 && sub_40B390(a1, v12) == 0 )
    {
      dword_4254CC(v12, 0);
      dword_4254D0(v12);
      return v11;
    }
    dword_425524(v12);
    dword_425548(v12, -1);
    dword_425560(v12, &v11);
    dword_4254D0(v12);
  }
  return v11;
}


/* sub_40F5CC @ 0040F5CC */
int __stdcall sub_40F5CC(_WORD *a1)
{
  int v1; // ebx
  int v2; // eax

  v1 = 0;
  v2 = sub_4011D4(a1, 0);
  if ( v2 == -726996046 || v2 == 18880704 )
    return 1;
  return v1;
}


/* sub_40F5FC @ 0040F5FC */
int __stdcall sub_40F5FC(int a1)
{
  int v1; // eax
  int v2; // eax
  int v4; // [esp+0h] [ebp-4h]

  v4 = 0;
  v1 = dword_425504(a1);
  if ( v1 != -1 )
  {
    v2 = dword_425500(a1, v1);
    if ( v2 != 0 )
      return v2;
  }
  return v4;
}


/* sub_40F634 @ 0040F634 */
int __stdcall sub_40F634(int a1, int a2)
{
  int v3; // [esp+4h] [ebp-8h] BYREF
  int v4; // [esp+8h] [ebp-4h]

  v3 = 0;
  v4 = dword_42551C(0, 0, sub_40F5FC, a2, 4, 0);
  if ( v4 != 0 )
  {
    if ( a1 != 0 && sub_40B390(a1, v4) == 0 )
    {
      dword_4254CC(v4, 0);
      dword_4254D0(v4);
      return v3;
    }
    dword_425524(v4);
    dword_425548(v4, -1);
    dword_425560(v4, &v3);
    dword_4254D0(v4);
  }
  return v3;
}


/* sub_40F788 @ 0040F788 */
int __userpurge sub_40F788@<eax>(int a1@<edx>, int a2@<edi>, int *a3, char a4)
{
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // esi
  int v12; // [esp-10h] [ebp-2C0h]
  int v13; // [esp-8h] [ebp-2B8h]
  _BYTE v14[520]; // [esp+4h] [ebp-2ACh] BYREF
  int v15[4]; // [esp+20Ch] [ebp-A4h] BYREF
  int v16[4]; // [esp+21Ch] [ebp-94h] BYREF
  int v17[3]; // [esp+22Ch] [ebp-84h] BYREF
  int v18[11]; // [esp+238h] [ebp-78h] BYREF
  _BYTE v19[8]; // [esp+264h] [ebp-4Ch] BYREF
  int v20; // [esp+26Ch] [ebp-44h]
  _BYTE v21[8]; // [esp+274h] [ebp-3Ch] BYREF
  int v22; // [esp+27Ch] [ebp-34h]
  int v23; // [esp+284h] [ebp-2Ch] BYREF
  int v24; // [esp+28Ch] [ebp-24h] BYREF
  int v25; // [esp+294h] [ebp-1Ch] BYREF
  int v26; // [esp+29Ch] [ebp-14h] BYREF
  int v27; // [esp+2A0h] [ebp-10h] BYREF
  int v28; // [esp+2A4h] [ebp-Ch] BYREF
  int v29; // [esp+2A8h] [ebp-8h] BYREF
  int v30; // [esp+2ACh] [ebp-4h]

  v13 = a1;
  v12 = a2;
  v30 = 0;
  v28 = 0;
  v27 = 0;
  v26 = 0;
  if ( dword_425744(0) == 0 )
  {
    if ( (a4 & 1) != 0 && dword_4257E8(0, 0, 0, 0, 0, &v23) == 0 )
    {
      v17[0] = -1214234524;
      v17[1] = -1215348707;
      v17[2] = -1208205212;
      sub_401250(v17, 3);
      if ( dword_4257EC(*(_DWORD *)(v23 + 28), 2, 0, 0, 0, 0, &v29) == 0 )
      {
        do
        {
          while ( 1 )
          {
            v5 = dword_4257F0(v29, 0, 0, &v24);
            if ( v5 != 0 )
              break;
            v6 = v24;
            v7 = dword_42543C(v24);
            v8 = sub_406830(2 * v7 + 8);
            if ( v8 != 0 )
            {
              dword_425464(v8, v17, v6, v13);
              *a3++ = v8;
              dword_4257E4(v6);
              ++v30;
            }
          }
        }
        while ( v5 == 1101 );
      }
      dword_4257F4(v29);
      dword_4257E4(v23);
    }
    if ( (a4 & 2) != 0 )
    {
      v16[0] = 1249777384;
      v16[1] = -1506624211;
      v16[2] = -671185773;
      v16[3] = -460726604;
      sub_401250(v16, 4);
      v15[0] = -1209387032;
      v15[1] = -1506624210;
      v15[2] = -671185773;
      v15[3] = -460726604;
      sub_401250(v15, 4);
      v18[0] = -1212661644;
      v18[1] = -1213448071;
      v18[2] = -1210892286;
      v18[3] = -1215414249;
      v18[4] = -1215086505;
      v18[5] = -1212661684;
      v18[6] = -1212596117;
      v18[7] = -1208205256;
      sub_401250(v18, 8);
      if ( dword_4257FC(v18, 0, 0, 1, v16, &v28) == 0 )
      {
        dword_4257A0(v21);
        dword_4257A0(v19);
        v18[0] = -1214693284;
        v18[1] = -1214431138;
        v18[2] = -1215283123;
        v18[3] = -1213054900;
        v18[4] = -1215217575;
        v18[5] = -1215152047;
        v18[6] = -1212202913;
        v18[7] = -1215152041;
        v18[8] = -1214693300;
        v18[9] = -1215807424;
        v18[10] = -1208205256;
        sub_401250(v18, 11);
        if ( (*(int (__stdcall **)(int, int *, _BYTE *))(*(_DWORD *)v28 + 60))(v28, v18, v21) == 0 )
        {
          v18[0] = -1212661644;
          v18[1] = -1213448071;
          v18[2] = -1210892286;
          v18[3] = -1212202985;
          v18[4] = -1212071818;
          v18[5] = -1215086469;
          v18[6] = -1215545259;
          v18[7] = -1215807411;
          v18[8] = -1215414179;
          v18[9] = -1211088821;
          v18[10] = -1208205256;
          sub_401250(v18, 11);
          dword_425444(v14, v18);
          dword_425440(v14, v22);
          if ( dword_4257FC(v14, 0, 0, 1, v15, &v26) == 0 && dword_425804(v26, &v27) == 0 )
          {
            v18[0] = -1213054884;
            v18[1] = -1212923797;
            v18[2] = -1215348649;
            v18[3] = -1213054900;
            v18[4] = -1215217575;
            v18[5] = -1208205219;
            sub_401250(v18, 6);
            v17[0] = -1214234524;
            v17[1] = -1215348707;
            v17[2] = -1208205212;
            sub_401250(v17, 3);
            while ( 1 )
            {
              v25 = 0;
              dword_4257A4(v21);
              dword_4257A4(v19);
              if ( dword_425808(v27, 1, v21, &v25) != 0
                || v25 == 0
                || (*(int (__stdcall **)(int, int *, _BYTE *))(*(_DWORD *)v22 + 60))(v22, v18, v19) != 0 )
              {
                break;
              }
              v9 = dword_42543C(v20);
              v10 = sub_406830(2 * v9 + 8);
              if ( v10 != 0 )
              {
                dword_425464(v10, v17, v20, v12);
                *a3++ = v10;
                ++v30;
              }
            }
          }
        }
      }
    }
    if ( v27 != 0 )
      dword_42580C(v27);
    if ( v26 != 0 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v26 + 8))(v26);
    if ( v28 != 0 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v28 + 8))(v28);
    dword_42574C();
  }
  return v30;
}


/* sub_40FBE4 @ 0040FBE4 */
int *__usercall sub_40FBE4@<eax>(int a1@<edi>)
{
  int *result; // eax
  int v2; // edx
  _DWORD **v3; // esi
  _DWORD *v4; // eax
  int v5; // eax
  int *v6; // ebx
  int v7; // eax
  int v8; // ecx
  int v9; // ebx
  int *v10; // esi
  _DWORD *v11; // edi
  int v12; // eax
  int v13; // ebx
  int *v14; // esi
  int v15; // eax
  int v16; // ett
  int *v17; // [esp+4h] [ebp-3Ch]
  int v18; // [esp+8h] [ebp-38h]
  int v19; // [esp+Ch] [ebp-34h]
  int v20; // [esp+10h] [ebp-30h]
  int v21; // [esp+14h] [ebp-2Ch]
  int v22; // [esp+18h] [ebp-28h] BYREF
  _BYTE v23[4]; // [esp+1Ch] [ebp-24h] BYREF
  int v24; // [esp+20h] [ebp-20h] BYREF
  _DWORD *v25; // [esp+24h] [ebp-1Ch]
  _DWORD *v26; // [esp+28h] [ebp-18h]
  int *v27; // [esp+2Ch] [ebp-14h] BYREF
  int v28; // [esp+30h] [ebp-10h]
  int v29; // [esp+34h] [ebp-Ch]
  int v30; // [esp+38h] [ebp-8h]
  int v31; // [esp+3Ch] [ebp-4h]

  v25 = nullptr;
  v20 = 0;
  v19 = 0;
  v21 = sub_401564();
  result = (int *)sub_406830(4000000);
  v18 = (int)result;
  if ( result == nullptr )
    goto LABEL_49;
  result = (int *)sub_40F788(v2, a1, result, 3);
  v17 = result;
  if ( result == nullptr )
    goto LABEL_49;
  result = (int *)sub_406830(4 * v21);
  v20 = (int)result;
  if ( result == nullptr )
    goto LABEL_49;
  result = (int *)sub_406830(4 * v21);
  v19 = (int)result;
  if ( result == nullptr )
    goto LABEL_49;
  dword_425884 = 0;
  dword_425888 = 0;
  dword_42588C = 0;
  v31 = 0;
  v30 = 0;
  v3 = (_DWORD **)v18;
  do
  {
    v4 = *v3++;
    v26 = v4;
    v22 = 0;
    v5 = sub_40F4F8(0, (int)v4, 1, (int)&v27, -1, (int)&v24, (int)v23, (int)&v22, 100);
    if ( v5 != 0 )
    {
      v5 = sub_40F4F8(dword_42516C, (int)v26, 1, (int)&v27, -1, (int)&v24, (int)v23, (int)&v22, 100);
      if ( v5 != 0 )
        v5 = sub_40F4F8(dword_425168, (int)v26, 1, (int)&v27, -1, (int)&v24, (int)v23, (int)&v22, 100);
    }
    if ( v5 == 0 )
    {
      v6 = v27;
      while ( 1 )
      {
        if ( v6[1] != 0 && v6[1] != 0x80000000 )
          goto LABEL_33;
        if ( v6[1] == 0x80000000 && sub_40F5CC((_WORD *)*v6) != 0 )
        {
          v6 += 3;
          --v24;
        }
        else
        {
          v25 = sub_4069A8(v26, *v6);
          if ( v25 == nullptr )
            goto LABEL_33;
          if ( sub_40F634(0, (int)v25) != 0 )
          {
            v29 = 0;
          }
          else if ( sub_40F634(dword_42516C, (int)v25) != 0 )
          {
            v29 = dword_42516C;
          }
          else
          {
            if ( sub_40F634(dword_425168, (int)v25) == 0 )
              goto LABEL_23;
            v29 = dword_425168;
          }
          v7 = dword_42551C(0, 0, sub_40F264, v25, 4, 0);
          v28 = v7;
          if ( v7 == 0 )
          {
LABEL_23:
            sub_40684C((int)v25);
            v6 += 3;
            --v24;
            goto LABEL_34;
          }
          if ( v29 != 0 )
            v7 = sub_40B390(v29, v28);
          if ( v7 != 0 )
          {
            dword_425524(v28);
            *(_DWORD *)(v20 + 4 * v31++) = v28;
            if ( ++v30 == v21 )
            {
              v31 = dword_42554C(v30, v20, 0, -1);
              v8 = *(_DWORD *)(v20 + 4 * v31);
              *(_DWORD *)(v20 + 4 * v31) = 0;
              dword_4254D0(v8);
              --v30;
            }
LABEL_33:
            v6 += 3;
            --v24;
            goto LABEL_34;
          }
          dword_4254CC(v28, 0);
          dword_4254D0(v28);
          sub_40684C((int)v25);
          v6 += 3;
          --v24;
        }
LABEL_34:
        if ( v24 == 0 )
        {
          if ( v27 != nullptr )
            sub_40684C((int)v27);
          if ( v26 != nullptr )
            sub_40684C((int)v26);
          break;
        }
      }
    }
    v17 = (int *)((char *)v17 - 1);
  }
  while ( v17 != nullptr );
  if ( v30 != 0 )
  {
    v9 = v30;
    v10 = (int *)v20;
    v11 = (_DWORD *)v19;
    do
    {
      v12 = *v10++;
      if ( v12 != 0 )
      {
        *v11++ = v12;
        --v9;
      }
    }
    while ( v9 != 0 );
    dword_42554C(v30, v19, 1, -1);
    v13 = v30;
    v14 = (int *)v19;
    do
    {
      v15 = *v14++;
      dword_4254D0(v15);
      --v13;
    }
    while ( v13 != 0 );
  }
  while ( 1 )
  {
    v16 = dword_425884;
    result = (int *)_InterlockedCompareExchange(&dword_425888, dword_425884, dword_425884);
    if ( (int *)v16 == result )
      break;
    dword_42553C(100);
  }
LABEL_49:
  if ( v18 != 0 )
    result = (int *)sub_40684C(v18);
  if ( v20 != 0 )
    result = (int *)sub_40684C(v20);
  if ( v19 != 0 )
    return (int *)sub_40684C(v19);
  return result;
}


/* sub_40FF5C @ 0040FF5C */
signed __int32 __stdcall sub_40FF5C(_DWORD *a1)
{
  signed __int32 result; // eax
  int *v2; // ebx
  int v3; // eax
  int v4; // ecx
  int v5; // ebx
  int *v6; // esi
  _DWORD *v7; // edi
  int v8; // eax
  int v9; // ebx
  int *v10; // esi
  int v11; // eax
  int v12; // ett
  int v13; // [esp+0h] [ebp-34h]
  int v14; // [esp+4h] [ebp-30h]
  int v15; // [esp+8h] [ebp-2Ch]
  int v16; // [esp+Ch] [ebp-28h]
  int v17; // [esp+10h] [ebp-24h] BYREF
  _BYTE v18[4]; // [esp+14h] [ebp-20h] BYREF
  int v19; // [esp+18h] [ebp-1Ch] BYREF
  _DWORD *v20; // [esp+1Ch] [ebp-18h]
  int *v21; // [esp+20h] [ebp-14h] BYREF
  int v22; // [esp+24h] [ebp-10h]
  int v23; // [esp+28h] [ebp-Ch]
  int v24; // [esp+2Ch] [ebp-8h]
  int v25; // [esp+30h] [ebp-4h]

  v20 = nullptr;
  v14 = 0;
  v13 = 0;
  v25 = 0;
  v24 = 0;
  v17 = 0;
  v23 = 0;
  result = sub_40F4F8(0, (int)a1, 1, (int)&v21, -1, (int)&v19, (int)v18, (int)&v17, 100);
  if ( result != 0 )
  {
    result = sub_40F4F8(dword_42516C, (int)a1, 1, (int)&v21, -1, (int)&v19, (int)v18, (int)&v17, 100);
    if ( result != 0 )
      result = sub_40F4F8(dword_425168, (int)a1, 1, (int)&v21, -1, (int)&v19, (int)v18, (int)&v17, 100);
  }
  if ( result == 0 )
  {
    v16 = sub_401564();
    result = sub_406830(4 * v16);
    v14 = result;
    if ( result != 0 )
    {
      result = sub_406830(4 * v16);
      v13 = result;
      if ( result != 0 )
      {
        v15 = sub_40E144();
        dword_425884 = 0;
        dword_425888 = 0;
        dword_42588C = 0;
        v2 = v21;
        while ( 1 )
        {
          if ( v2[1] != 0 && v2[1] != 0x80000000 )
            goto LABEL_30;
          if ( v2[1] == 0x80000000 && sub_40F5CC((_WORD *)*v2) != 0 )
          {
            v2 += 3;
            --v19;
          }
          else
          {
            v20 = sub_4069A8(a1, *v2);
            if ( v20 == nullptr )
              goto LABEL_30;
            if ( sub_40F634(0, (int)v20) != 0 )
            {
              v23 = 0;
            }
            else if ( sub_40F634(dword_42516C, (int)v20) != 0 )
            {
              v23 = dword_42516C;
            }
            else
            {
              if ( sub_40F634(dword_425168, (int)v20) == 0 )
                goto LABEL_20;
              v23 = dword_425168;
            }
            v3 = dword_42551C(0, 0, sub_40F264, v20, 4, 0);
            v22 = v3;
            if ( v3 == 0 )
            {
LABEL_20:
              sub_40684C((int)v20);
              v2 += 3;
              --v19;
              goto LABEL_31;
            }
            if ( v23 != 0 )
              v3 = sub_40B390(v23, v22);
            if ( v3 != 0 )
            {
              dword_425524(v22);
              *(_DWORD *)(v14 + 4 * v25++) = v22;
              if ( ++v24 == v16 )
              {
                v25 = dword_42554C(v24, v14, 0, -1);
                v4 = *(_DWORD *)(v14 + 4 * v25);
                *(_DWORD *)(v14 + 4 * v25) = 0;
                dword_4254D0(v4);
                --v24;
              }
LABEL_30:
              v2 += 3;
              --v19;
              goto LABEL_31;
            }
            dword_4254CC(v22, 0);
            dword_4254D0(v22);
            sub_40684C((int)v20);
            v2 += 3;
            --v19;
          }
LABEL_31:
          if ( v19 == 0 )
          {
            if ( v21 != nullptr )
              sub_40684C((int)v21);
            if ( v24 != 0 )
            {
              v5 = v24;
              v6 = (int *)v14;
              v7 = (_DWORD *)v13;
              do
              {
                v8 = *v6++;
                if ( v8 != 0 )
                {
                  *v7++ = v8;
                  --v5;
                }
              }
              while ( v5 != 0 );
              dword_42554C(v24, v13, 1, -1);
              v9 = v24;
              v10 = (int *)v13;
              do
              {
                v11 = *v10++;
                dword_4254D0(v11);
                --v9;
              }
              while ( v9 != 0 );
            }
            while ( 1 )
            {
              v12 = dword_425884;
              result = _InterlockedCompareExchange(&dword_425888, dword_425884, dword_425884);
              if ( v12 == result )
                break;
              dword_42553C(100);
            }
            if ( v15 != 0 )
              result = sub_40E1CC(v15);
            break;
          }
        }
      }
    }
  }
  if ( a1 != nullptr )
    result = sub_40684C((int)a1);
  if ( v14 != 0 )
    result = sub_40684C(v14);
  if ( v13 != 0 )
    return sub_40684C(v13);
  return result;
}


/* sub_410294 @ 00410294 */
int __stdcall sub_410294(int a1, int a2)
{
  int v3[30]; // [esp+0h] [ebp-E4h] BYREF
  _DWORD v4[26]; // [esp+78h] [ebp-6Ch] BYREF
  int v5; // [esp+E0h] [ebp-4h]

  v5 = 0;
  dword_4255FC(v4);
  dword_425600(v4, a1, a2);
  dword_425604(v4);
  v5 = sub_406830(96);
  if ( v5 != 0 )
  {
    v3[0] = -1214234524;
    v3[1] = -1214234602;
    v3[2] = -1214955448;
    v3[3] = -1214693304;
    v3[4] = -1215872924;
    v3[5] = -1211351011;
    v3[6] = -1213972480;
    v3[7] = -1210499051;
    v3[8] = -1211613176;
    v3[9] = -1211023264;
    v3[10] = -1211351011;
    v3[11] = -1213972468;
    v3[12] = -1210499051;
    v3[13] = -1211219960;
    v3[14] = -1210498976;
    v3[15] = -1211219960;
    v3[16] = -1211023264;
    v3[17] = -1211351011;
    v3[18] = -1213972470;
    v3[19] = -1211351011;
    v3[20] = -1213972470;
    v3[21] = -1211351011;
    v3[22] = -1213972470;
    v3[23] = -1211351011;
    v3[24] = -1213972470;
    v3[25] = -1211351011;
    v3[26] = -1213972470;
    v3[27] = -1211351011;
    v3[28] = -1213972470;
    v3[29] = -1208205243;
    sub_401250(v3, 30);
    dword_425464(v5, v3, v4[22], LOWORD(v4[23]));
  }
  return v5;
}


/* sub_410410 @ 00410410 */
unsigned int *__stdcall sub_410410(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  unsigned int *result; // eax
  unsigned int *v6; // ebx
  __int16 *v7; // esi
  __int16 *i; // edi
  __int16 v9; // ax
  int v10; // edi
  _BYTE *v11; // esi
  int v12; // ebx
  int v13; // edi
  _DWORD v14[4]; // [esp+Ch] [ebp-A7Ch] BYREF
  _BYTE v15[4]; // [esp+1Ch] [ebp-A6Ch] BYREF
  _BYTE v16[520]; // [esp+20h] [ebp-A68h] BYREF
  __int16 v17; // [esp+228h] [ebp-860h] BYREF
  __int16 v18; // [esp+22Ah] [ebp-85Eh] BYREF
  _BYTE v19[520]; // [esp+430h] [ebp-658h] BYREF
  _BYTE v20[520]; // [esp+638h] [ebp-450h] BYREF
  _BYTE v21[256]; // [esp+840h] [ebp-248h] BYREF
  unsigned __int32 v22[8]; // [esp+940h] [ebp-148h] BYREF
  _DWORD v23[16]; // [esp+960h] [ebp-128h] BYREF
  _DWORD v24[6]; // [esp+9A0h] [ebp-E8h] BYREF
  _BYTE v25[4]; // [esp+9B8h] [ebp-D0h] BYREF
  int v26; // [esp+9BCh] [ebp-CCh]
  int v27; // [esp+9D0h] [ebp-B8h] BYREF
  int v28; // [esp+9D4h] [ebp-B4h]
  _DWORD v29[17]; // [esp+9E0h] [ebp-A8h] BYREF
  int v30; // [esp+A24h] [ebp-64h] BYREF
  _DWORD v31[3]; // [esp+A28h] [ebp-60h] BYREF
  _BYTE v32[2]; // [esp+A34h] [ebp-54h] BYREF
  __int16 v33; // [esp+A36h] [ebp-52h]
  int v34; // [esp+A38h] [ebp-50h]
  int v35; // [esp+A3Ch] [ebp-4Ch]
  int v36; // [esp+A40h] [ebp-48h]
  int v37; // [esp+A44h] [ebp-44h]
  _DWORD v38[2]; // [esp+A48h] [ebp-40h] BYREF
  _BYTE v39[4]; // [esp+A50h] [ebp-38h] BYREF
  _BYTE v40[4]; // [esp+A54h] [ebp-34h] BYREF
  _BYTE v41[4]; // [esp+A58h] [ebp-30h] BYREF
  int v42; // [esp+A5Ch] [ebp-2Ch] BYREF
  int v43; // [esp+A60h] [ebp-28h] BYREF
  int v44; // [esp+A64h] [ebp-24h]
  unsigned int *v45; // [esp+A68h] [ebp-20h]
  unsigned int *v46; // [esp+A6Ch] [ebp-1Ch]
  unsigned int *v47; // [esp+A70h] [ebp-18h]
  unsigned int *v48; // [esp+A74h] [ebp-14h]
  _BYTE v49[4]; // [esp+A78h] [ebp-10h] BYREF
  int v50; // [esp+A7Ch] [ebp-Ch]
  int v51; // [esp+A80h] [ebp-8h] BYREF
  unsigned int *v52; // [esp+A84h] [ebp-4h]

  v45 = nullptr;
  v46 = nullptr;
  v48 = nullptr;
  v47 = nullptr;
  v51 = 0;
  v50 = -1;
  dword_425428(v14, 0, 540);
  v14[0] = a1;
  v14[1] = a2;
  v14[2] = a3;
  v14[3] = a4;
  v4 = sub_40165C();
  dword_425444(v16, v4);
  dword_425428(&v27, 0, 16);
  dword_425428(v29, 0, 68);
  v29[0] = 68;
  result = (unsigned int *)sub_406DB0(dword_41D369);
  v48 = result;
  if ( result != nullptr )
  {
    result = (unsigned int *)sub_406830(54264);
    v47 = result;
    if ( result != nullptr )
    {
      result = (unsigned int *)sub_418BA4(v48, v47);
      v6 = result;
      if ( result != (unsigned int *)-1 )
      {
        result = (unsigned int *)sub_410294((int)v47, (int)result);
        v45 = result;
        if ( result != nullptr )
        {
          dword_425730(0, v20, 35, 0);
          dword_4255E0(v20, 0, 0, v19);
          result = (unsigned int *)dword_425528(v19, 0x40000000, 0, 0, 2, 384, 0);
          v52 = result;
          if ( result != (unsigned int *)-1 )
          {
            result = (unsigned int *)dword_42552C(v52, v47, v6, v41, 0);
            if ( result != nullptr )
            {
              dword_4254D0(v52);
              v7 = (__int16 *)v19;
              v17 = 34;
              for ( i = &v18; ; ++i )
              {
                v9 = *v7++;
                if ( v9 == 0 )
                  break;
                *i = v9;
              }
              *(_DWORD *)i = 34;
              result = (unsigned int *)dword_4255D4(v19, &v17, 0, 0, 1, 4, 0, v20, v29, &v27);
              if ( result != nullptr )
              {
                result = (unsigned int *)dword_42548C(v27, 0, v25, 24, v40);
                if ( result == nullptr )
                {
                  result = (unsigned int *)dword_4254DC(v27, v26 + 8, &v30, 4, 0);
                  if ( result == nullptr )
                  {
                    result = (unsigned int *)sub_406DB0(dword_42086B);
                    v46 = result;
                    if ( result != nullptr )
                    {
                      sub_4192F4(v22, v46);
                      v44 = sub_419348((int)v22, (int)v23, (int)v21);
                      v10 = *(unsigned int *)((char *)v47 + v47[15] + 260);
                      v11 = (char *)v47 + *(unsigned int *)((char *)v47 + v47[15] + 268);
                      v12 = *(unsigned int *)((char *)v47 + v47[15] + 264);
                      sub_41941C(v11, v12, (int)v21, v44);
                      v13 = v30 + v10;
                      v43 = v12;
                      v42 = v13;
                      result = (unsigned int *)dword_4254E0(v27, &v42, &v43, 64, v39);
                      if ( result == nullptr )
                      {
                        result = (unsigned int *)dword_4254D8(v27, v13, v11, v12, 0);
                        if ( result == nullptr )
                        {
                          v38[0] = NtCurrentTeb()->ClientId.UniqueProcess;
                          v38[1] = 0;
                          v24[0] = 24;
                          memset(&v24[1], 0, 20);
                          result = (unsigned int *)dword_425474(&v51, 2035711, v24, v38);
                          if ( result == nullptr )
                          {
                            result = (unsigned int *)dword_42547C(v51, v51, v27, v15, 0, 0, 3);
                            if ( result == nullptr )
                            {
                              v51 = 0;
                              v32[0] = 1;
                              v32[1] = 0;
                              v33 = 4;
                              v34 = 0;
                              v35 = 0;
                              v36 = 0;
                              v37 = 0;
                              v31[0] = 12;
                              v31[1] = v32;
                              v31[2] = 1;
                              result = (unsigned int *)dword_4255D8(v45, 3, 0, 255, 0, 0, -1, v31);
                              v50 = (int)result;
                              if ( result != (unsigned int *)-1 )
                              {
                                dword_425524(v28);
                                result = (unsigned int *)dword_4255DC(v50, 0);
                                if ( result != nullptr || NtCurrentTeb()->LastErrorValue == 535 )
                                {
                                  result = (unsigned int *)dword_42552C(v50, v14, 540, v49, 0);
                                  if ( result != nullptr )
                                    result = (unsigned int *)dword_425534(v50);
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( v28 != 0 )
    result = (unsigned int *)dword_4254D0(v28);
  if ( v27 != 0 )
    result = (unsigned int *)dword_4254D0(v27);
  if ( v51 != 0 )
    result = (unsigned int *)dword_4254D0(v51);
  if ( v45 != nullptr )
    result = (unsigned int *)sub_40684C((int)v45);
  if ( v46 != nullptr )
    result = (unsigned int *)sub_40684C((int)v46);
  if ( v47 != nullptr )
    result = (unsigned int *)sub_40684C((int)v47);
  if ( v48 != nullptr )
    return (unsigned int *)sub_40684C((int)v48);
  return result;
}


/* sub_4108C8 @ 004108C8 */
int __stdcall sub_4108C8(int a1, int a2)
{
  int result; // eax
  int v3; // ett
  int v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]

  v4 = sub_40E144();
  dword_425884 = 0;
  dword_425888 = 0;
  dword_42588C = 0;
  result = dword_42551C(0, 0, sub_40F264, a2, 4, 0);
  v5 = result;
  if ( result != 0 )
  {
    if ( a1 != 0 && sub_40B390(a1, result) == 0 )
    {
      dword_4254CC(v5, 0);
      return dword_4254D0(v5);
    }
    dword_425524(v5);
    dword_425548(v5, -1);
    while ( 1 )
    {
      v3 = dword_425884;
      if ( v3 == _InterlockedCompareExchange(&dword_425888, dword_425884, dword_425884) )
        break;
      dword_42553C(100);
    }
    result = dword_4254D0(v5);
  }
  if ( v4 != 0 )
    return sub_40E1CC(v4);
  return result;
}


/* sub_410994 @ 00410994 */
int sub_410994()
{
  int result; // eax
  _DWORD *v1; // eax
  int v2; // ett
  _BYTE v3[520]; // [esp+4h] [ebp-260h] BYREF
  int v4[10]; // [esp+20Ch] [ebp-58h] BYREF
  int v5[7]; // [esp+234h] [ebp-30h] BYREF
  int v6[4]; // [esp+250h] [ebp-14h] BYREF
  int v7; // [esp+260h] [ebp-4h]

  v4[0] = -1216069507;
  v4[1] = -1215020965;
  v4[2] = -1215152039;
  v4[3] = -1214693281;
  v4[4] = -1215152015;
  v4[5] = -1215807413;
  v4[6] = -1215283111;
  v4[7] = -1213448108;
  v4[8] = -1215807399;
  v4[9] = -1208205232;
  sub_401250(v4, 10);
  result = dword_4255CC(v4, v3, 260);
  if ( result != 0 )
  {
    v5[0] = -1215414168;
    v5[1] = -1214562217;
    v5[2] = -1214431158;
    v5[3] = -1210302379;
    v5[4] = -1214955394;
    v5[5] = -1214693292;
    v5[6] = -1208205237;
    sub_401250(v5, 7);
    if ( dword_425448(v3, v5) == 0 || (result = sub_40B438()) != 0 )
    {
      sub_4016D0((int)v3);
      v6[0] = -1214431115;
      v6[1] = -1215283119;
      v6[2] = -1215086502;
      v6[3] = -1208205248;
      sub_401250(v6, 4);
      dword_425440(v3, v6);
      v1 = sub_40694C((int)v3);
      dword_425884 = 0;
      dword_425888 = 0;
      dword_42588C = 0;
      result = dword_42551C(0, 0, sub_40F264, v1, 4, 0);
      v7 = result;
      if ( result != 0 )
      {
        dword_425524(v7);
        dword_425548(v7, -1);
        while ( 1 )
        {
          v2 = dword_425884;
          if ( v2 == _InterlockedCompareExchange(&dword_425888, dword_425884, dword_425884) )
            break;
          dword_42553C(100);
        }
        return dword_4254D0(v7);
      }
    }
  }
  return result;
}


/* sub_410B40 @ 00410B40 */
unsigned __int32 sub_410B40()
{
  unsigned __int32 result; // eax
  int v1; // ebx
  unsigned __int32 v2; // ebx
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int v7; // ebx
  int *v8; // esi
  _DWORD *v9; // edi
  int v10; // eax
  int v11; // ebx
  int *v12; // esi
  int v13; // eax
  int v14; // ett
  int v15; // [esp+4h] [ebp-20h]
  int v16; // [esp+8h] [ebp-1Ch]
  int v17; // [esp+Ch] [ebp-18h]
  int v18; // [esp+10h] [ebp-14h]
  _DWORD *v19; // [esp+14h] [ebp-10h]
  _DWORD *v20; // [esp+14h] [ebp-10h]
  int v21; // [esp+18h] [ebp-Ch]
  int v22; // [esp+1Ch] [ebp-8h]
  int v23; // [esp+20h] [ebp-4h]

  v18 = 0;
  v15 = sub_401564();
  result = sub_40A458(dword_42516C, 0, 0);
  v1 = result;
  if ( result == 0 )
    goto LABEL_28;
  result = sub_406830(2 * result);
  v18 = result;
  if ( result == 0 )
    goto LABEL_28;
  result = sub_40A458(dword_42516C, v1, result);
  if ( result == 0 )
    goto LABEL_28;
  v2 = result >> 2;
  result = sub_406830(4 * (result >> 2));
  v17 = result;
  if ( result == 0 )
    goto LABEL_28;
  result = sub_406830(4 * v2);
  v16 = result;
  if ( result == 0 )
    goto LABEL_28;
  dword_425884 = 0;
  dword_425888 = 0;
  dword_42588C = 0;
  v22 = 0;
  v21 = 0;
  v3 = v18;
  do
  {
    v4 = sub_40A190(dword_42516C, v3);
    if ( v4 == 3 || v4 == 2 )
    {
      v19 = sub_40694C(v3);
      v5 = dword_42551C(0, 0, sub_40F264, v19, 0, 0);
      if ( v5 == 0 )
        goto LABEL_18;
    }
    else
    {
      if ( v4 != 4 )
        goto LABEL_18;
      v20 = sub_40694C(v3);
      v23 = dword_42551C(0, 0, sub_40F264, v20, 4, 0);
      if ( v23 == 0 )
        goto LABEL_18;
      if ( sub_40B390(dword_42516C, v23) == 0 )
      {
        dword_4254CC(v23, 0);
        dword_4254D0(v23);
        goto LABEL_18;
      }
      dword_425524(v23);
      v5 = v23;
    }
    *(_DWORD *)(v17 + 4 * v22++) = v5;
    if ( ++v21 == v15 )
    {
      v22 = dword_42554C(v21, v17, 0, -1);
      v6 = *(_DWORD *)(v17 + 4 * v22);
      *(_DWORD *)(v17 + 4 * v22) = 0;
      dword_4254D0(v6);
      --v21;
    }
LABEL_18:
    v3 += 8;
    --v2;
  }
  while ( v2 != 0 );
  if ( v21 != 0 )
  {
    v7 = v21;
    v8 = (int *)v17;
    v9 = (_DWORD *)v16;
    do
    {
      v10 = *v8++;
      if ( v10 != 0 )
      {
        *v9++ = v10;
        --v7;
      }
    }
    while ( v7 != 0 );
    dword_42554C(v21, v16, 1, -1);
    v11 = v21;
    v12 = (int *)v16;
    do
    {
      v13 = *v12++;
      dword_4254D0(v13);
      --v11;
    }
    while ( v11 != 0 );
  }
  while ( 1 )
  {
    v14 = dword_425884;
    result = _InterlockedCompareExchange(&dword_425888, dword_425884, dword_425884);
    if ( v14 == result )
      break;
    dword_42553C(100);
  }
LABEL_28:
  if ( v16 != 0 )
    result = sub_40684C(v16);
  if ( v17 != 0 )
    result = sub_40684C(v17);
  if ( v18 != 0 )
    return sub_40684C(v18);
  return result;
}


/* sub_410D8C @ 00410D8C */
int sub_410D8C()
{
  int *v0; // esi
  int v1; // ecx
  int v2; // eax
  _WORD *v4; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  v5 = 0;
  v0 = (int *)dword_425144;
  if ( dword_425144 != 0 )
  {
    v4 = (_WORD *)sub_40C820();
    if ( v4 != nullptr )
    {
      v1 = sub_4011D4(v4, 0);
      do
      {
        v2 = *v0++;
        if ( v2 == 0 )
        {
          v5 = 0;
          goto LABEL_9;
        }
      }
      while ( v2 != v1 );
      v5 = 1;
    }
LABEL_9:
    if ( v4 != nullptr )
      sub_40684C((int)v4);
  }
  return v5;
}


/* sub_410DF4 @ 00410DF4 */
int __stdcall sub_410DF4(int a1, int a2, int a3, int a4)
{
  int v5[6]; // [esp+0h] [ebp-148h] BYREF
  int v6[4]; // [esp+18h] [ebp-130h] BYREF
  _BYTE v7[256]; // [esp+28h] [ebp-120h] BYREF
  unsigned int v8; // [esp+128h] [ebp-20h] BYREF
  unsigned int v9; // [esp+12Ch] [ebp-1Ch] BYREF
  int v10; // [esp+130h] [ebp-18h] BYREF
  int v11; // [esp+134h] [ebp-14h] BYREF
  int v12; // [esp+138h] [ebp-10h] BYREF
  int v13; // [esp+13Ch] [ebp-Ch]
  int v14; // [esp+140h] [ebp-8h] BYREF
  int v15; // [esp+144h] [ebp-4h]

  v15 = 0;
  v5[0] = -1212989333;
  v5[1] = -1213710210;
  v5[2] = -1212333969;
  v5[3] = -1212596118;
  v5[4] = -1210498972;
  v5[5] = -1208205237;
  sub_401250(v5, 6);
  v6[0] = -1213251504;
  v6[1] = -1215414181;
  v6[2] = -1214693283;
  v6[3] = -1208205226;
  sub_401250(v6, 4);
  ((void (__cdecl *)(_BYTE *, int *, int))dword_425464)(v7, v5, a2);
  if ( a1 != 0 )
  {
    v13 = dword_4256A0(0);
    v9 = (dword_4256E0(v13, 8) + 1) & 0xFFFFFFFE;
    v8 = (dword_4256E0(v13, 10) + 1) & 0xFFFFFFFE;
    dword_4256A4(0, v13);
    if ( dword_42560C(-2147483646, v7, 0, 0, 0, 983359, 0, &v12, 0) == 0 )
    {
      if ( dword_425610(v12, v6, 0, 4, &v8, 4) == 0 )
      {
        LOWORD(v6[0]) += 15;
        if ( dword_425610(v12, v6, 0, 4, &v9, 4) == 0 )
          v15 = 1;
      }
      dword_4254D0(v12);
    }
  }
  else if ( dword_42560C(-2147483646, v7, 0, 0, 0, 131353, 0, &v12, 0) == 0 )
  {
    v11 = 4;
    v10 = 4;
    if ( dword_425614(v12, v6, 0, &v11, a4, &v10) == 0 )
    {
      LOWORD(v6[0]) += 15;
      if ( dword_425614(v12, v6, 0, &v11, a3, &v10) == 0 )
        v15 = 1;
    }
    dword_4254D0(v12);
    sub_406E1C(-1, &v14);
    if ( v14 != 0 )
      dword_425618(-2147483646, v7, 256, 0);
    else
      dword_42561C(-2147483646, v7);
  }
  return v15;
}


/* sub_411028 @ 00411028 */
int sub_411028()
{
  _WORD *v0; // edi
  int i; // ebx
  int j; // ebx
  int k; // ebx
  int m; // ebx
  int n; // ebx
  int v7; // [esp+8h] [ebp-4h]

  v7 = sub_406830(26);
  if ( v7 != 0 )
  {
    v0 = (_WORD *)v7;
    for ( i = 3; i != 0; --i )
      *v0++ = sub_401124(0x41u, 0x5Au);
    for ( j = 1; j != 0; --j )
      *v0++ = sub_401124(0x23u, 0x26u);
    for ( k = 3; k != 0; --k )
      *v0++ = sub_401124(0x30u, 0x39u);
    for ( m = 1; m != 0; --m )
      *v0++ = sub_401124(0x23u, 0x26u);
    for ( n = 4; n != 0; --n )
      *v0++ = sub_401124(0x61u, 0x7Au);
  }
  return v7;
}


/* sub_4110CC @ 004110CC */
int sub_4110CC()
{
  void *v1; // [esp+0h] [ebp-14h]
  void *v2; // [esp+4h] [ebp-10h]
  int v3; // [esp+8h] [ebp-Ch] BYREF
  _DWORD v4[2]; // [esp+Ch] [ebp-8h] BYREF

  v4[0] = 0;
  v2 = nullptr;
  v1 = nullptr;
  if ( (unsigned int)sub_401574() >= 0x64 )
  {
    v2 = sub_406DB0(dword_42087F);
    if ( v2 != nullptr && dword_42560C(-2147483646, v2, 0, 0, 0, 131334, 0, v4, 0) == 0 )
    {
      v1 = sub_406DB0(dword_4208D5);
      if ( v1 != nullptr )
      {
        v3 = 1;
        dword_425610(v4[0], v1, 0, 4, &v3, 4);
      }
    }
  }
  if ( v1 != nullptr )
    sub_40684C((int)v1);
  if ( v2 != nullptr )
    sub_40684C((int)v2);
  if ( v4[0] != 0 )
    dword_4254D0(v4[0]);
  return v4[1];
}


/* sub_41119C @ 0041119C */
void *__stdcall sub_41119C(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  void *result; // eax
  int *v4; // ebx
  _BYTE v5[256]; // [esp+4h] [ebp-124h] BYREF
  int v6; // [esp+104h] [ebp-24h] BYREF
  _BYTE v7[4]; // [esp+108h] [ebp-20h] BYREF
  int v8; // [esp+10Ch] [ebp-1Ch] BYREF
  int *v9; // [esp+110h] [ebp-18h] BYREF
  void *v10; // [esp+114h] [ebp-14h]
  void *v11; // [esp+118h] [ebp-10h]
  void *v12; // [esp+11Ch] [ebp-Ch]
  int v13; // [esp+120h] [ebp-8h] BYREF
  int v14; // [esp+124h] [ebp-4h]

  v14 = 0;
  v12 = nullptr;
  v11 = nullptr;
  v10 = nullptr;
  if ( byte_425122 != 0
    && dword_425168 != 0
    && dword_42515C != 0
    && (v12 = sub_406DB0((_DWORD *)(dword_42515C + 4)), dword_425160 != 0)
    && (v11 = sub_406DB0((_DWORD *)(dword_425160 + 4)), dword_425164 != 0) )
  {
    v10 = sub_406DB0((_DWORD *)(dword_425164 + 4));
    *a1 = v12;
    *a2 = v11;
    result = v10;
    *a3 = v10;
    v14 = 1;
  }
  else
  {
    v6 = 0;
    if ( dword_4257D8(0, 3, 2, &v9, -1, &v8, v7, &v6) == 0 )
    {
      v4 = v9;
      while ( v4[24] != 500 )
      {
        v4 += 29;
        if ( --v8 == 0 )
          goto LABEL_23;
      }
      if ( (v4[6] & 2) != 0 )
        v4[6] ^= 2u;
      v10 = (void *)sub_411028();
      v4[1] = (int)v10;
      v12 = (void *)sub_4068FC(*v4, 0);
      v13 = 128;
      if ( dword_425594(v5, &v13) != 0 )
      {
        v11 = (void *)sub_4068FC((int)v5, 0);
        if ( dword_4257DC(0, v12, 1, v4, 0) != 0 )
        {
          if ( v11 != nullptr )
            sub_40684C((int)v11);
          if ( v12 != nullptr )
            sub_40684C((int)v12);
          if ( v10 != nullptr )
            sub_40684C((int)v10);
        }
        else
        {
          *a1 = v12;
          *a2 = v11;
          *a3 = v10;
          v14 = 1;
        }
      }
LABEL_23:
      dword_4257E4(v9);
    }
    return (void *)v14;
  }
  return result;
}


/* sub_41135C @ 0041135C */
int sub_41135C()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v4; // [esp+0h] [ebp-1Ch] BYREF
  int v5; // [esp+4h] [ebp-18h] BYREF
  int v6; // [esp+8h] [ebp-14h] BYREF
  void *v7; // [esp+Ch] [ebp-10h]
  int v8; // [esp+10h] [ebp-Ch] BYREF
  int v9; // [esp+14h] [ebp-8h] BYREF
  int v10; // [esp+18h] [ebp-4h]

  v10 = 0;
  v9 = 0;
  v6 = 0;
  v5 = 0;
  v4 = 0;
  v7 = nullptr;
  if ( sub_41119C(&v6, &v5, &v4) != nullptr )
  {
    v7 = sub_406DB0(dword_42090B);
    if ( v7 != nullptr && dword_42560C(-2147483646, v7, 0, 0, 0, 131334, 0, &v9, 0) == 0 )
    {
      sub_41156D();
      v7 = sub_406DB0(dword_42097B);
      if ( v7 != nullptr )
      {
        v8 = 49;
        if ( dword_425610(v9, v7, 0, 1, &v8, 4) == 0 )
        {
          sub_41156D();
          v7 = sub_406DB0(dword_42099D);
          if ( v7 != nullptr )
          {
            v0 = dword_42543C(v6);
            if ( dword_425610(v9, v7, 0, 1, v6, 2 * v0 + 2) == 0 )
            {
              sub_41156D();
              v7 = sub_406DB0(dword_4209C1);
              if ( v7 != nullptr )
              {
                v1 = dword_42543C(v5);
                if ( dword_425610(v9, v7, 0, 1, v5, 2 * v1 + 2) == 0 )
                {
                  sub_41156D();
                  v7 = sub_406DB0(dword_4209E9);
                  if ( v7 != nullptr )
                  {
                    if ( sub_411584(v7, v4) != 0
                      || (v2 = dword_42543C(v4), dword_425610(v9, v7, 0, 1, v4, 2 * v2 + 2) == 0) )
                    {
                      v10 = 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( v9 != 0 )
    dword_4254D0(v9);
  if ( v7 != nullptr )
    sub_40684C((int)v7);
  if ( v5 != 0 )
    sub_40684C(v5);
  if ( v6 != 0 )
    sub_40684C(v6);
  if ( v4 != 0 )
    sub_40684C(v4);
  return v10;
}


/* sub_41156D @ 0041156D */
int __usercall sub_41156D@<eax>(int a1@<ebp>)
{
  int result; // eax

  if ( *(_DWORD *)(a1 - 16) != 0 )
  {
    result = sub_40684C(*(_DWORD *)(a1 - 16));
    *(_DWORD *)(a1 - 16) = 0;
  }
  return result;
}


/* sub_411584 @ 00411584 */
int __stdcall sub_411584(int a1, int a2)
{
  _DWORD v3[6]; // [esp+0h] [ebp-30h] BYREF
  _BYTE v4[8]; // [esp+18h] [ebp-18h] BYREF
  _BYTE v5[8]; // [esp+20h] [ebp-10h] BYREF
  int v6; // [esp+28h] [ebp-8h] BYREF
  int v7; // [esp+2Ch] [ebp-4h]

  v7 = 0;
  dword_425428(v3, 0, 24);
  v3[0] = 24;
  if ( dword_425664(0, v3, 32, &v6) == 0 )
  {
    dword_4254BC(v5, a1);
    dword_4254BC(v4, a2);
    if ( dword_425668(v6, v5, v4) == 0 )
      v7 = 1;
    dword_42566C(v6);
  }
  return v7;
}


/* sub_411608 @ 00411608 */
void *__stdcall sub_411608(int a1)
{
  _DWORD *v1; // eax
  void *result; // eax
  int v3; // [esp+0h] [ebp-Ch] BYREF
  int v4; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h] BYREF

  v4 = 0;
  sub_406E1C(-1, &v5);
  if ( (unsigned int)sub_401574() < 0x3C )
  {
    if ( a1 != 0 )
      v1 = &unk_420A65;
    else
      v1 = &unk_420A91;
  }
  else if ( a1 != 0 )
  {
    v1 = &unk_420A0D;
  }
  else
  {
    v1 = &unk_420A39;
  }
  result = sub_406DB0(v1);
  v4 = (int)result;
  if ( result != nullptr )
  {
    if ( v5 != 0 )
      dword_4254EC(1, &v3);
    dword_425538(v4, 0);
    dword_42553C(300);
    if ( v4 != 0 )
      sub_40684C(v4);
    if ( v5 != 0 )
      dword_4254EC(v3, &v3);
    return (void *)dword_4254A4(1);
  }
  return result;
}


/* sub_4116BC @ 004116BC */
int sub_4116BC()
{
  int v0; // eax
  int v1; // ebx
  void *v2; // esi
  int v3; // eax
  _BYTE v5[768]; // [esp+8h] [ebp-310h] BYREF
  int v6; // [esp+308h] [ebp-10h]
  void *v7; // [esp+30Ch] [ebp-Ch]
  int v8; // [esp+310h] [ebp-8h] BYREF
  int v9; // [esp+314h] [ebp-4h]

  v9 = 0;
  v8 = 0;
  v6 = 0;
  v7 = sub_406DB0(dword_420AB4);
  if ( v7 != nullptr && dword_42560C(-2147483646, v7, 0, 0, 0, 131078, 0, &v8, 0) == 0 )
  {
    v6 = sub_411814();
    if ( v6 != 0 )
    {
      v0 = sub_40165C();
      v1 = v0;
      if ( dword_4251A8 != 0 )
      {
        v2 = sub_406DB0(dword_420B1C);
        dword_425674(&unk_4251AC, 72, 0);
        dword_425464(v5, v2, v1, &unk_4251AC);
        dword_425670(&unk_4251AC, 72, 0);
        sub_40684C((int)v2);
      }
      else
      {
        dword_425444(v5, v0);
      }
      v3 = dword_42543C(v5);
      if ( dword_425610(v8, v6, 0, 1, v5, 2 * v3 + 2) == 0 )
        v9 = 1;
    }
  }
  if ( v6 != 0 )
    sub_40684C(v6);
  if ( v7 != nullptr )
    sub_40684C((int)v7);
  if ( v8 != 0 )
    dword_4254D0(v8);
  return v9;
}


/* sub_411814 @ 00411814 */
_WORD *sub_411814()
{
  _WORD *v0; // edi
  int i; // ebx
  int j; // ebx
  int k; // ebx
  _WORD *v5; // [esp+8h] [ebp-4h]

  v5 = (_WORD *)sub_406830(22);
  if ( v5 != nullptr )
  {
    *v5 = 42;
    v0 = v5 + 1;
    for ( i = 3; i != 0; --i )
      *v0++ = sub_401124(0x41u, 0x5Au);
    for ( j = 3; j != 0; --j )
      *v0++ = sub_401124(0x30u, 0x39u);
    for ( k = 3; k != 0; --k )
      *v0++ = sub_401124(0x61u, 0x7Au);
  }
  return v5;
}


/* sub_411890 @ 00411890 */
int sub_411890()
{
  int v0; // ebx
  int v1; // eax
  int v2; // eax
  _DWORD *v3; // esi
  void *v4; // esi
  int v5; // eax
  _BYTE v7[768]; // [esp+8h] [ebp-310h] BYREF
  _WORD *v8; // [esp+308h] [ebp-10h]
  void *v9; // [esp+30Ch] [ebp-Ch]
  int v10; // [esp+310h] [ebp-8h] BYREF
  int v11; // [esp+314h] [ebp-4h]

  v11 = 0;
  v10 = 0;
  v8 = nullptr;
  v0 = 0;
  v9 = sub_406DB0(dword_420AB4);
  if ( v9 != nullptr && dword_42560C(-2147483646, v9, 0, 0, 0, 131078, 0, &v10, 0) == 0 )
  {
    v8 = sub_411814();
    if ( v8 != nullptr )
    {
      v1 = sub_40165C();
      v2 = sub_4068FC(v1, 6);
      v0 = v2;
      if ( v2 != 0 )
      {
        v3 = (_DWORD *)(v2 + 2 * dword_42543C(v2));
        *v3 = 1211023335;
        v3[1] = 1214431152;
        v3[2] = 1215283115;
        *v3 ^= 0x4803BFC7u;
        v3[1] ^= 0x4803BFC7u;
        v3[2] ^= 0x4803BFC7u;
        if ( dword_4251A8 != 0 )
        {
          v4 = sub_406DB0(dword_420B1C);
          dword_425674(&unk_4251AC, 72, 0);
          dword_425464(v7, v4, v0, &unk_4251AC);
          dword_425670(&unk_4251AC, 72, 0);
          sub_40684C((int)v4);
        }
        else
        {
          dword_425444(v7, v0);
        }
        v5 = dword_42543C(v7);
        if ( dword_425610(v10, v8, 0, 1, v7, 2 * v5 + 2) == 0 )
          v11 = 1;
      }
    }
  }
  if ( v0 != 0 )
    sub_40684C(v0);
  if ( v8 != nullptr )
    sub_40684C((int)v8);
  if ( v9 != nullptr )
    sub_40684C((int)v9);
  if ( v10 != 0 )
    dword_4254D0(v10);
  return v11;
}


/* sub_411A38 @ 00411A38 */
int __stdcall sub_411A38(int a1)
{
  int result; // eax
  _DWORD v2[6]; // [esp+0h] [ebp-24h] BYREF
  _DWORD v3[2]; // [esp+18h] [ebp-Ch] BYREF
  int v4; // [esp+20h] [ebp-4h] BYREF

  v3[0] = a1;
  v3[1] = 0;
  v2[0] = 24;
  memset(&v2[1], 0, 20);
  result = dword_425474(&v4, 1, v2, v3);
  if ( result == 0 )
  {
    dword_4254C8(v4, 0);
    return dword_4254D0(v4);
  }
  return result;
}


/* sub_411AAC @ 00411AAC */
int sub_411AAC()
{
  int i; // eax
  int *v1; // ebx
  int v2; // esi
  int v4; // [esp+8h] [ebp-8h]
  int v5; // [esp+Ch] [ebp-4h] BYREF

  v5 = 1024;
  v4 = sub_406830(1024);
  for ( i = dword_425488(5, v4, 1024, &v5); i != 0; i = dword_425488(5, v4, v5, &v5) )
  {
    if ( i != -1073741820 )
      return sub_40684C(v4);
    v4 = sub_406868(v4, v5);
  }
  v1 = (int *)v4;
  do
  {
    v2 = *v1;
    if ( v1[15] != 0 && sub_4011D4((_WORD *)v1[15], 0) == -23167984 )
      sub_411A38(v1[17]);
    v1 = (int *)((char *)v1 + v2);
  }
  while ( v2 != 0 );
  return sub_40684C(v4);
}


/* sub_411B44 @ 00411B44 */
int sub_411B44()
{
  int (*v0)(void); // esi
  int v1; // ebx
  int result; // eax

  if ( (unsigned int)sub_401574() > 0x34 )
    v0 = (int (*)(void))dword_4256C8;
  else
    v0 = (int (*)(void))dword_4256CC;
  sub_411AAC();
  while ( 1 )
  {
    v1 = v0();
    if ( v1 != 0 )
      break;
    dword_42553C(100);
  }
  while ( 1 )
  {
    result = dword_4256D0(v1);
    if ( result != 0 )
      break;
    dword_42553C(100);
  }
  return result;
}


/* sub_411B90 @ 00411B90 */
int sub_411B90()
{
  unsigned __int8 *v0; // esi
  int v1; // edi
  int i; // ebx
  unsigned __int8 v3; // al
  int v4; // eax
  unsigned __int8 *v5; // esi
  int j; // ebx
  unsigned __int8 v7; // al
  int v9; // [esp+0h] [ebp-84h]
  _BYTE v10[88]; // [esp+Ch] [ebp-78h] BYREF
  _BYTE v11[16]; // [esp+64h] [ebp-20h] BYREF
  int v12[3]; // [esp+74h] [ebp-10h] BYREF
  int v13; // [esp+80h] [ebp-4h]

  v13 = sub_406830(130);
  if ( v13 != 0 )
  {
    v12[0] = -1211351011;
    v12[1] = -1213972470;
    v12[2] = -1208205256;
    sub_401250(v12, 3);
    dword_4255FC(v10);
    dword_425600(v10, &unk_424F70, 127);
    dword_425604(v10);
    v0 = v11;
    v1 = v13;
    for ( i = 16; i != 0; --i )
    {
      v3 = *v0++;
      dword_425464(v1, v12, v3, v9);
      v1 += 4;
    }
    dword_4255FC(v10);
    v4 = dword_42543C(v13);
    dword_425600(v10, v13, 2 * v4);
    dword_425604(v10);
    v5 = v11;
    for ( j = 16; j != 0; --j )
    {
      v7 = *v5++;
      dword_425464(v1, v12, v7, v9);
      v1 += 4;
    }
  }
  return v13;
}


/* sub_411C84 @ 00411C84 */
int __stdcall sub_411C84(int a1)
{
  int v2[31]; // [esp+0h] [ebp-94h] BYREF
  int v3; // [esp+7Ch] [ebp-18h]
  int v4; // [esp+80h] [ebp-14h] BYREF
  int v5; // [esp+84h] [ebp-10h] BYREF
  int v6; // [esp+88h] [ebp-Ch] BYREF
  int v7; // [esp+8Ch] [ebp-8h] BYREF
  int v8; // [esp+90h] [ebp-4h]

  v8 = 0;
  v7 = 0;
  v3 = 0;
  v2[0] = -1215086485;
  v2[1] = -1215807394;
  v2[2] = -1214431153;
  v2[3] = -1214693302;
  v2[4] = -1213120412;
  v2[5] = -1214300079;
  v2[6] = -1215086518;
  v2[7] = -1215086517;
  v2[8] = -1215807394;
  v2[9] = -1213513628;
  v2[10] = -1215152047;
  v2[11] = -1215086500;
  v2[12] = -1215348657;
  v2[13] = -1212202908;
  v2[14] = -1215414195;
  v2[15] = -1214693302;
  v2[16] = -1215807402;
  v2[17] = -1214693266;
  v2[18] = -1215348662;
  v2[19] = -1215086511;
  v2[20] = -1214234538;
  v2[21] = -1215414145;
  v2[22] = -1215741865;
  v2[23] = -1210302392;
  v2[24] = -1215086488;
  v2[25] = -1214955436;
  v2[26] = -1216004005;
  v2[27] = -1213251484;
  v2[28] = -1214431156;
  v2[29] = -1215741876;
  v2[30] = -1208205237;
  sub_401250(v2, 31);
  if ( dword_42560C(-2147483646, v2, 0, 0, 0, 131359, 0, &v7, 0) == 0 )
  {
    v3 = sub_411B90();
    if ( v3 != 0 )
    {
      if ( a1 != 0 )
      {
        v6 = 1;
        v5 = 4;
        if ( dword_425614(v7, v3, 0, &v6, &v4, &v5) == 0 && v4 == 49 )
          v8 = 1;
      }
      else
      {
        v4 = 49;
        if ( dword_425610(v7, v3, 0, 1, &v4, 4) == 0 )
          v8 = 1;
      }
    }
  }
  if ( v7 != 0 )
    dword_4254D0(v7);
  if ( v3 != 0 )
    sub_40684C(v3);
  return v8;
}


/* sub_411E50 @ 00411E50 */
unsigned int *sub_411E50()
{
  unsigned int *result; // eax
  int v1; // eax
  int v2; // ebx
  int v3; // eax
  int v4; // ebx
  int v5; // [esp+4h] [ebp-4h]

  result = (unsigned int *)sub_411C84(1);
  if ( result != nullptr )
  {
    if ( byte_42512E != 0 )
      return sub_410410(0, 0, 0, (unsigned __int8)byte_42512E);
  }
  else if ( sub_409610() != 0 )
  {
    return (unsigned int *)sub_416F90();
  }
  else
  {
    result = (unsigned int *)sub_40B438();
    if ( result != nullptr )
    {
      if ( byte_42512F != 0 )
      {
        v5 = dword_42551C(0, 0, sub_408F38, 0, 0, 0);
        if ( v5 != 0 )
        {
          dword_425548(v5, -1);
          dword_4254D0(v5);
        }
      }
      if ( byte_425132 != 0 && dword_425168 != 0 )
      {
        v1 = sub_409C34(dword_425168, dword_42515C, dword_425160, dword_425164, 1);
        v2 = v1;
        if ( v1 != 0 )
        {
          dword_425548(v1, -1);
          dword_4254D0(v2);
        }
      }
      if ( byte_425131 != 0 && dword_425168 != 0 )
      {
        v3 = sub_409C34(dword_425168, dword_42515C, dword_425160, dword_425164, 0);
        v4 = v3;
        if ( v3 != 0 )
        {
          dword_425548(v3, -1);
          dword_4254D0(v4);
        }
      }
      result = (unsigned int *)sub_410D8C();
      if ( result == nullptr )
      {
        result = (unsigned int *)sub_41135C();
        if ( result != nullptr )
        {
          result = (unsigned int *)sub_4116BC();
          if ( result != nullptr )
          {
            sub_410DF4(1, dword_425178 + 2, 0, 0);
            sub_4110CC();
            sub_408200(0);
            return (unsigned int *)sub_411608(1);
          }
        }
      }
    }
  }
  return result;
}


/* sub_411FB8 @ 00411FB8 */
_DWORD *__stdcall sub_411FB8(int a1)
{
  _DWORD *result; // eax
  int v2; // eax
  _DWORD *v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  _DWORD *v7; // eax
  int v8; // eax
  _WORD *v9; // eax
  _DWORD *v10; // eax
  int v11; // eax
  _WORD *v12; // eax
  _DWORD *v13; // [esp-4h] [ebp-24h]
  _DWORD *v14; // [esp-4h] [ebp-24h]
  _DWORD *v15; // [esp-4h] [ebp-24h]
  _DWORD *v16; // [esp-4h] [ebp-24h]
  _DWORD v17[4]; // [esp+4h] [ebp-1Ch] BYREF
  _DWORD *v18; // [esp+14h] [ebp-Ch]
  int v19; // [esp+18h] [ebp-8h]
  _DWORD *v20; // [esp+1Ch] [ebp-4h]

  result = (_DWORD *)sub_4068FC(a1, 0);
  v18 = result;
  if ( result != nullptr )
  {
    sub_401700((int)v18);
    if ( dword_425778(v18) != 0 )
    {
      return (_DWORD *)sub_40FF5C(v18);
    }
    else
    {
      v19 = 0;
      v17[0] = 7274582;
      v17[1] = 7667820;
      v17[2] = 6619245;
      v17[3] = 123;
      sub_4073F8();
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            while ( dword_425788(v18) != 0 )
            {
              if ( dword_425504(v18) == -1 )
                return (_DWORD *)sub_40684C((int)v18);
              v2 = sub_406830(520);
              v3 = (_DWORD *)v2;
              if ( v2 == 0 )
                return (_DWORD *)sub_40684C((int)v18);
              dword_425588(260, v2);
              sub_4016D0((int)v3);
              dword_425440(v3, v18);
              sub_40684C((int)v18);
              v18 = v3;
            }
            v4 = dword_425448(v18, v17);
            v5 = v4;
            if ( v4 == 0 )
              break;
            v6 = dword_42543C(v4);
            v20 = (_DWORD *)sub_406830(2 * v6 + 16);
            if ( v20 == nullptr )
              return (_DWORD *)sub_40684C((int)v18);
            v7 = v20;
            *v20 = 1214234523;
            v7[1] = 1214234616;
            *v7 ^= 0x4803BFC7u;
            v7[1] ^= 0x4803BFC7u;
            dword_425440(v20, v5);
            sub_40684C((int)v18);
            v18 = nullptr;
            sub_4016D0((int)v20);
            v18 = sub_40A928((int)v20);
            result = (_DWORD *)sub_40684C((int)v20);
            if ( v18 == nullptr )
              return result;
          }
          if ( sub_40A250(v19, (unsigned int)v18) != 0 )
            break;
          v11 = dword_425504(v18);
          if ( v11 == -1 )
            return (_DWORD *)sub_40684C((int)v18);
          if ( (v11 & 0x10) != 0 )
          {
            sub_4016D0((int)v18);
            if ( dword_42578C(v18) != 0 )
              return (_DWORD *)sub_40684C((int)v18);
LABEL_45:
            v16 = sub_40694C((int)v18);
            result = (_DWORD *)sub_40684C((int)v18);
            v18 = v16;
            if ( v16 != nullptr )
              return (_DWORD *)sub_4108C8(v19, (int)v18);
            return result;
          }
          v12 = (_WORD *)dword_425768(v18);
          if ( *v12 == 0 || sub_4011D4(v12 + 1, 0) != -614982784 )
            goto LABEL_45;
          v15 = (_DWORD *)sub_40AB38(v19, (int)v18);
          result = (_DWORD *)sub_40684C((int)v18);
          v18 = v15;
          if ( v15 == nullptr )
            return result;
        }
        if ( __readfsdword(0x34u) == 1201 )
        {
          v19 = dword_42516C;
          if ( sub_40A250(dword_42516C, (unsigned int)v18) == 0 || __readfsdword(0x34u) == 1201 )
          {
            v19 = dword_425168;
            if ( sub_40A250(dword_425168, (unsigned int)v18) == 0 || __readfsdword(0x34u) == 1201 )
              return (_DWORD *)sub_40684C((int)v18);
          }
        }
        v8 = sub_40A308(v19, (int)v18);
        if ( v8 == -1 )
          return (_DWORD *)sub_40684C((int)v18);
        if ( (v8 & 0x10) != 0 )
          break;
        v9 = (_WORD *)dword_425768(v18);
        if ( *v9 == 0 || sub_4011D4(v9 + 1, 0) != -614982784 )
          goto LABEL_30;
        v13 = (_DWORD *)sub_40AB38(v19, (int)v18);
        result = (_DWORD *)sub_40684C((int)v18);
        v18 = v13;
        if ( v13 == nullptr )
          return result;
      }
      sub_4016D0((int)v18);
      if ( sub_40A3AC(v19, (int)v18) != 0 )
        return (_DWORD *)sub_40684C((int)v18);
LABEL_30:
      if ( *((_WORD *)v18 + 1) == 58 )
        v10 = sub_40694C((int)v18);
      else
        v10 = sub_406A3C(v18);
      v14 = v10;
      result = (_DWORD *)sub_40684C((int)v18);
      v18 = v14;
      if ( v14 != nullptr )
        return (_DWORD *)sub_4108C8(v19, (int)v18);
    }
  }
  return result;
}


/* sub_412384 @ 00412384 */
int __stdcall sub_412384(int a1)
{
  int result; // eax
  int v2; // eax
  _WORD *v3; // eax
  _DWORD *v4; // eax
  int v5; // eax
  _WORD *v6; // eax
  int v7; // [esp-4h] [ebp-10h]
  _DWORD *v8; // [esp-4h] [ebp-10h]
  int v9; // [esp-4h] [ebp-10h]
  _DWORD *v10; // [esp-4h] [ebp-10h]
  unsigned int v11; // [esp+4h] [ebp-8h]
  int v12; // [esp+4h] [ebp-8h]
  int v13; // [esp+8h] [ebp-4h]

  result = sub_4068FC(a1, 2);
  v11 = result;
  if ( result != 0 )
  {
    v13 = 0;
    while ( 1 )
    {
      while ( sub_40A250(v13, v11) == 0 )
      {
        v5 = dword_425504(v11);
        if ( v5 == -1 )
          return sub_40684C(v11);
        if ( (v5 & 0x10) != 0 )
        {
          sub_4016D0(v11);
          if ( dword_42578C(v11) != 0 )
            return sub_40684C(v11);
LABEL_33:
          v10 = sub_40694C(v11);
          result = sub_40684C(v11);
          v12 = (int)v10;
          if ( v10 != nullptr )
            return sub_4108C8(v13, v12);
          return result;
        }
        v6 = (_WORD *)dword_425768(v11);
        if ( *v6 == 0 || sub_4011D4(v6 + 1, 0) != -614982784 )
          goto LABEL_33;
        v9 = sub_40AB38(v13, v11);
        result = sub_40684C(v11);
        v11 = v9;
        if ( v9 == 0 )
          return result;
      }
      if ( __readfsdword(0x34u) == 1201 )
      {
        v13 = dword_42516C;
        if ( sub_40A250(dword_42516C, v11) == 0 || __readfsdword(0x34u) == 1201 )
        {
          v13 = dword_425168;
          if ( sub_40A250(dword_425168, v11) == 0 || __readfsdword(0x34u) == 1201 )
            return sub_40684C(v11);
        }
      }
      v2 = sub_40A308(v13, v11);
      if ( v2 == -1 )
        return sub_40684C(v11);
      if ( (v2 & 0x10) != 0 )
        break;
      v3 = (_WORD *)dword_425768(v11);
      if ( *v3 == 0 || sub_4011D4(v3 + 1, 0) != -614982784 )
        goto LABEL_19;
      v7 = sub_40AB38(v13, v11);
      result = sub_40684C(v11);
      v11 = v7;
      if ( v7 == 0 )
        return result;
    }
    sub_4016D0(v11);
    if ( sub_40A3AC(v13, v11) != 0 )
      return sub_40684C(v11);
LABEL_19:
    if ( *(_WORD *)(v11 + 2) == 58 )
      v4 = sub_40694C(v11);
    else
      v4 = sub_406A3C((_DWORD *)v11);
    v8 = v4;
    result = sub_40684C(v11);
    v12 = (int)v8;
    if ( v8 != nullptr )
      return sub_4108C8(v13, v12);
  }
  return result;
}


/* sub_4125D0 @ 004125D0 */
int __stdcall sub_4125D0(int a1)
{
  int v1; // ebx
  int v3; // [esp+4h] [ebp-8h] BYREF
  int v4; // [esp+8h] [ebp-4h]

  v4 = 0;
  if ( dword_4257E8(0, 0, 0, 0, 0, &v3) == 0 )
  {
    v1 = v3;
    dword_425444(a1, *(_DWORD *)(v3 + 28));
    dword_4257E4(v1);
    return 1;
  }
  return v4;
}


/* sub_412620 @ 00412620 */
int __stdcall sub_412620(int a1, int a2, int a3)
{
  _BYTE v4[192]; // [esp+0h] [ebp-134h] BYREF
  _BYTE v5[80]; // [esp+C0h] [ebp-74h] BYREF
  int v6[6]; // [esp+110h] [ebp-24h] BYREF
  _BYTE v7[4]; // [esp+128h] [ebp-Ch] BYREF
  int v8; // [esp+12Ch] [ebp-8h]
  int v9; // [esp+130h] [ebp-4h]

  v9 = 0;
  v8 = -1;
  sub_412C1C(a1, v5);
  v6[0] = -1214234524;
  v6[1] = -1214234602;
  v6[2] = -1214955448;
  v6[3] = -1214693304;
  v6[4] = -1210498972;
  v6[5] = -1208205237;
  sub_401250(v6, 6);
  ((void (__cdecl *)(_BYTE *, int *, _BYTE *))dword_425464)(v4, v6, v5);
  v8 = dword_425528(v4, -1073741824, 3, 0, 3, 128, 0);
  if ( v8 != -1 )
  {
    if ( dword_425530(v8, a2, a3, v7, 0) != 0 )
      v9 = 1;
    dword_4254D0(v8);
  }
  return v9;
}


/* sub_4126EC @ 004126EC */
void __stdcall sub_4126EC(int *a1)
{
  int *v1; // edi
  wchar_t *v2; // eax
  int *v3; // esi
  int v4; // eax
  _WORD *v5; // edi
  unsigned int v6; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h]

  if ( dword_4256C4(67) != 0 )
  {
    *a1 = -1215348715;
    a1[1] = -1214627751;
    a1[2] = -1208205219;
    sub_401250(a1, 3);
  }
  else
  {
    v1 = a1;
    v2 = sub_401650();
    v7 = dword_42572C(v2, &v6);
    if ( v7 != 0 && v6 >= 2 )
    {
      v3 = (int *)(v7 + 4);
      --v6;
      do
      {
        v4 = *v3++;
        dword_425444(v1, v4);
        v5 = (_WORD *)v1 + dword_42543C(v1);
        if ( --v6 != 0 )
          *v5 = 32;
        else
          *v5 = 0;
        v1 = (int *)(v5 + 1);
      }
      while ( v6 != 0 );
    }
    if ( v7 != 0 )
      dword_4255E4(v7);
  }
}


/* sub_4127A8 @ 004127A8 */
int __stdcall sub_4127A8(int a1, int a2, int a3)
{
  int i; // ebx
  int v5; // [esp+4h] [ebp-Ch] BYREF
  int v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]

  v7 = 0;
  for ( i = 60; i != 0; --i )
  {
    v6 = dword_425528(a1, -1073741824, 3, 0, 3, 128, 0);
    if ( v6 != -1 )
    {
      if ( dword_42552C(v6, a2, a3, &v5, 0) != 0 && v5 == a3 )
      {
        dword_425534(v6);
        v7 = 1;
      }
      dword_4254D0(v6);
    }
    if ( v7 != 0 )
      break;
    dword_42553C(1000);
  }
  return v7;
}


/* sub_41283C @ 0041283C */
int sub_41283C()
{
  wchar_t *v0; // eax
  _WORD **v1; // esi
  _WORD *v2; // eax
  unsigned int v4; // [esp+4h] [ebp-Ch] BYREF
  int v5; // [esp+8h] [ebp-8h]
  int v6; // [esp+Ch] [ebp-4h]

  v6 = 0;
  v5 = 0;
  v0 = sub_401650();
  v5 = dword_42572C(v0, &v4);
  if ( v5 != 0 && v4 >= 2 )
  {
    v1 = (_WORD **)v5;
    while ( 1 )
    {
      v2 = *v1++;
      if ( sub_4011D4(v2, 0) == 903026761 )
        break;
      if ( --v4 == 0 )
        goto LABEL_7;
    }
    v6 = 1;
  }
LABEL_7:
  if ( v5 != 0 )
    dword_4255E4(v5);
  return v6;
}


/* sub_4128B0 @ 004128B0 */
int __userpurge sub_4128B0@<eax>(int a1@<eax>, int a2)
{
  int v2; // eax
  _DWORD v4[6]; // [esp+Ch] [ebp-38h] BYREF
  HANDLE UniqueProcess; // [esp+24h] [ebp-20h] BYREF
  int v6; // [esp+28h] [ebp-1Ch]
  int v7; // [esp+2Ch] [ebp-18h] BYREF
  int v8; // [esp+30h] [ebp-14h] BYREF
  int v9; // [esp+34h] [ebp-10h] BYREF
  int v10; // [esp+3Ch] [ebp-8h] BYREF
  int v11; // [esp+40h] [ebp-4h]

  v11 = a1;
  v10 = a1;
  v9 = a1;
  v7 = a1;
  v8 = a1;
  dword_4254A8(20, 1, 0, &v10);
  v2 = sub_4097A8(1051882214);
  if ( v2 != 0 || (v2 = sub_4097A8(-1040553382)) != 0 )
  {
    UniqueProcess = (HANDLE)v2;
    v6 = 0;
    v4[0] = 24;
    memset(&v4[1], 0, 20);
    if ( dword_425474(&v9, 64, v4, &UniqueProcess) == 0 )
    {
      UniqueProcess = NtCurrentTeb()->ClientId.UniqueProcess;
      v6 = 0;
      v4[0] = 24;
      memset(&v4[1], 0, 20);
      if ( dword_425474(&v8, 64, v4, &UniqueProcess) == 0 && dword_42547C(v8, a2, v9, &v7, 0, 0, 3) == 0 )
        v11 = 1;
    }
  }
  if ( v8 != 0 )
    dword_4254D0(v8);
  if ( v9 != 0 )
    dword_4254D0(v9);
  return v11;
}


/* sub_4129F4 @ 004129F4 */
BOOL __stdcall sub_4129F4(int a1)
{
  int v2; // [esp+0h] [ebp-8h]
  int v3; // [esp+4h] [ebp-4h]

  v2 = dword_425528(a1, 0x80000000, 3, 0, 3, 128, 0);
  if ( v2 == -1 )
    return __readfsdword(0x34u) != 2;
  v3 = 1;
  dword_4254D0(v2);
  return v3;
}


/* sub_412A54 @ 00412A54 */
int __stdcall sub_412A54(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  _BYTE v6[192]; // [esp+0h] [ebp-2ACh] BYREF
  _BYTE v7[256]; // [esp+C0h] [ebp-1ECh] BYREF
  _BYTE v8[80]; // [esp+1C0h] [ebp-ECh] BYREF
  _BYTE v9[64]; // [esp+210h] [ebp-9Ch] BYREF
  int v10[6]; // [esp+250h] [ebp-5Ch] BYREF
  int v11[5]; // [esp+268h] [ebp-44h] BYREF
  _DWORD v12[3]; // [esp+27Ch] [ebp-30h] BYREF
  _BYTE v13[2]; // [esp+288h] [ebp-24h] BYREF
  __int16 v14; // [esp+28Ah] [ebp-22h]
  int v15; // [esp+28Ch] [ebp-20h]
  int v16; // [esp+290h] [ebp-1Ch]
  int v17; // [esp+294h] [ebp-18h]
  int v18; // [esp+298h] [ebp-14h]
  int v19; // [esp+29Ch] [ebp-10h]
  unsigned int LastErrorValue; // [esp+2A0h] [ebp-Ch]
  int v21; // [esp+2A4h] [ebp-8h] BYREF
  int v22; // [esp+2A8h] [ebp-4h]

  v22 = 0;
  LastErrorValue = 0;
  v21 = 32;
  if ( dword_425594(v9, &v21) != 0 )
  {
    v11[0] = -1214234524;
    v11[1] = -1215348707;
    v11[2] = -1210499050;
    v11[3] = -1214234549;
    v11[4] = -1208205256;
    sub_401250(v11, 5);
    dword_425464(v7, v11, v9, a1);
    dword_425458(v7);
    sub_412C1C(v7, v8);
    v10[0] = -1214234524;
    v10[1] = -1214234602;
    v10[2] = -1214955448;
    v10[3] = -1214693304;
    v10[4] = -1210498972;
    v10[5] = -1208205237;
    sub_401250(v10, 6);
    ((void (__cdecl *)(_BYTE *, int *, _BYTE *))dword_425464)(v6, v10, v8);
    v13[0] = 1;
    v13[1] = 0;
    v14 = 4;
    v15 = 0;
    v16 = 0;
    v17 = 0;
    v18 = 0;
    v12[0] = 12;
    v12[1] = v13;
    v12[2] = 1;
    v4 = dword_4255D8(v6, 3, 0, 255, 0, 0, -1, v12);
    v19 = v4;
    if ( v4 != -1 )
    {
      LastErrorValue = NtCurrentTeb()->LastErrorValue;
      v22 = 1;
      if ( a4 != 0 )
      {
        v4 = dword_4255DC(v19, 0);
        if ( v4 == 0 && NtCurrentTeb()->LastErrorValue != 535 )
          return v22;
        if ( a2 != 0 || a3 != 0 )
          v4 = dword_425530(v19, a2, a3, &v21, 0);
      }
      if ( LastErrorValue != 183 )
        sub_4128B0(v4, v19);
    }
  }
  return v22;
}


/* sub_412C1C @ 00412C1C */
int __stdcall sub_412C1C(int a1, int a2)
{
  int v2; // eax
  _BYTE v4[256]; // [esp+4h] [ebp-1E0h] BYREF
  int v5[26]; // [esp+104h] [ebp-E0h] BYREF
  int v6[4]; // [esp+16Ch] [ebp-78h] BYREF
  _DWORD v7[26]; // [esp+17Ch] [ebp-68h] BYREF

  v6[0] = -1215348707;
  v6[1] = -1212858265;
  v6[2] = -1212202904;
  v6[3] = -1208205284;
  sub_401250(v6, 4);
  ((void (__cdecl *)(_BYTE *, int *, int))dword_425464)(v4, v6, a1);
  dword_4255FC(v7);
  v2 = dword_42543C(v4);
  dword_425600(v7, v4, 2 * v2);
  dword_425604(v7);
  v5[0] = -1210499005;
  v5[1] = -1211875320;
  v5[2] = -1211023264;
  v5[3] = -1211351011;
  v5[4] = -1213972468;
  v5[5] = -1210499051;
  v5[6] = -1211613176;
  v5[7] = -1211023264;
  v5[8] = -1211351011;
  v5[9] = -1213972470;
  v5[10] = -1211351011;
  v5[11] = -1213972470;
  v5[12] = -1210499051;
  v5[13] = -1211219960;
  v5[14] = -1210498976;
  v5[15] = -1211219960;
  v5[16] = -1210498976;
  v5[17] = -1211219960;
  v5[18] = -1210498976;
  v5[19] = -1211219960;
  v5[20] = -1210498976;
  v5[21] = -1211219960;
  v5[22] = -1210498976;
  v5[23] = -1211219960;
  v5[24] = -1216266144;
  v5[25] = -1208205256;
  sub_401250(v5, 26);
  return dword_425464(a2, v5, v7[22], LOWORD(v7[23]));
}


/* sub_412DB8 @ 00412DB8 */
int __stdcall sub_412DB8(int a1)
{
  return dword_425850(a1, 0, 0, 0);
}


/* sub_412DD0 @ 00412DD0 */
int __stdcall sub_412DD0(int a1, int a2, int a3)
{
  _BYTE v4[256]; // [esp+0h] [ebp-12Ch] BYREF
  _BYTE v5[20]; // [esp+100h] [ebp-2Ch] BYREF
  _BYTE *v6; // [esp+114h] [ebp-18h]
  int v7; // [esp+120h] [ebp-Ch]
  int v8; // [esp+124h] [ebp-8h] BYREF
  int v9; // [esp+128h] [ebp-4h]

  v9 = 0;
  v7 = 0;
  v8 = 0;
  dword_425444(v4, a1);
  dword_425440(v4, a2);
  if ( a3 != 0 )
  {
    dword_425428(v5, 0, 32);
    v6 = v4;
    v7 = dword_42551C(0, 0, sub_412DB8, v5, 0, 0);
    if ( v7 != 0 )
    {
      if ( dword_425548(v7, 3000) != 258 )
      {
        dword_425560(v7, &v8);
        if ( v8 == 0 )
          v9 = 1;
      }
      dword_4254D0(v7);
    }
  }
  else if ( dword_425854(v4, 0, 0) == 0 )
  {
    return 1;
  }
  return v9;
}


/* sub_412EB4 @ 00412EB4 */
int __stdcall sub_412EB4(_WORD *a1)
{
  int v1; // ebx
  __int16 *v2; // esi
  __int16 *v3; // edi
  int i; // ecx
  _WORD *v5; // edi
  _WORD *v6; // edi
  _WORD *v7; // esi
  int j; // ecx
  int result; // eax
  int v10; // ecx
  __int16 v11; // [esp+Ch] [ebp-6C0h] BYREF
  __int16 v12; // [esp+Eh] [ebp-6BEh] BYREF
  _BYTE v13[520]; // [esp+41Ch] [ebp-2B0h] BYREF
  int v14[8]; // [esp+624h] [ebp-A8h] BYREF
  _DWORD v15[2]; // [esp+644h] [ebp-88h] BYREF
  char v16; // [esp+64Ch] [ebp-80h]
  char v17; // [esp+64Dh] [ebp-7Fh]
  _DWORD v18[6]; // [esp+650h] [ebp-7Ch] BYREF
  _DWORD v19[4]; // [esp+668h] [ebp-64h] BYREF
  _DWORD v20[17]; // [esp+678h] [ebp-54h] BYREF
  int v21; // [esp+6BCh] [ebp-10h] BYREF
  int v22; // [esp+6C0h] [ebp-Ch] BYREF
  int v23; // [esp+6C4h] [ebp-8h] BYREF
  int v24; // [esp+6C8h] [ebp-4h] BYREF

  v1 = sub_40165C();
  dword_425444(v13, v1);
  dword_425784(v13);
  v2 = (__int16 *)v1;
  v11 = 34;
  v3 = &v12;
  for ( i = dword_42543C(v1); i != 0; --i )
    *v3++ = *v2++;
  *v3 = 34;
  v5 = v3 + 1;
  *v5 = 32;
  v6 = v5 + 1;
  v7 = a1;
  for ( j = dword_42543C(a1); j != 0; --j )
    *v6++ = *v7++;
  *v6 = 0;
  result = dword_4254A0(-1, 0x2000000, &v24);
  if ( result == 0 )
  {
    v15[0] = 12;
    v15[1] = 3;
    v16 = 0;
    v17 = 0;
    v18[0] = 24;
    memset(&v18[1], 0, 16);
    v18[5] = v15;
    if ( dword_425478(v24, 0x2000000, v18, 0, 1, &v23) == 0 )
    {
      v21 = sub_4016C8();
      if ( dword_425494(v23, 12, &v21, 4) == 0 )
      {
        dword_425690(&v22, v23, 1);
        dword_425428(v19, 0, 16);
        dword_425428(v20, 0, 68);
        v20[0] = 68;
        v14[0] = -1214955409;
        v14[1] = -1213251498;
        v14[2] = -1214431156;
        v14[3] = -1214234616;
        v14[4] = -1214693252;
        v14[5] = -1214431138;
        v14[6] = -1215283123;
        v14[7] = -1208205236;
        sub_401250(v14, 8);
        v20[2] = v10;
        sub_40B390(v23, -2);
        if ( dword_425654(v23, v1, &v11, 0, 0, 0, 1056, v22, v13, v20, v19) != 0 )
        {
          dword_4254D0(v19[0]);
          dword_4254D0(v19[1]);
        }
        dword_425694(v22);
      }
      dword_4254D0(v23);
    }
    return dword_4254D0(v24);
  }
  return result;
}


/* sub_4130BC @ 004130BC */
void __stdcall sub_4130BC(int a1)
{
  ;
}


/* sub_4130C4 @ 004130C4 */
int __stdcall sub_4130C4(int a1, int a2)
{
  int result; // eax
  int v3; // [esp+0h] [ebp-20h] BYREF
  int v4; // [esp+4h] [ebp-1Ch]
  int v5; // [esp+1Ch] [ebp-4h]

  result = dword_425650(dword_4258E8, sub_4130BC);
  v5 = result;
  if ( result != 0 )
  {
    dword_425428(&v3, 0, 28);
    v3 = 16;
    v4 = 4;
    result = dword_425638(v5, &v3);
    if ( result != 0 )
    {
      sub_412A54((int)&unk_4258F0, (int)&unk_4259C0, 512, 1);
      v4 = 1;
      return dword_425638(v5, &v3);
    }
  }
  return result;
}


/* sub_413144 @ 00413144 */
int sub_413144()
{
  int result; // eax
  int v1; // eax
  int v2; // eax
  _BYTE v3[28]; // [esp+0h] [ebp-24h] BYREF
  int v4; // [esp+1Ch] [ebp-8h]
  int v5; // [esp+20h] [ebp-4h]

  result = sub_4125D0((int)&unk_4258F0);
  if ( result != 0 )
  {
    v1 = sub_40165C();
    v2 = dword_425770(v1);
    dword_425444(&unk_425970, v2);
    *(_WORD *)dword_425768(&unk_425970) = 0;
    dword_4258E8 = (int)&unk_425970;
    dword_4258EC = (int)sub_4130C4;
    dword_42564C(&dword_4258E8);
    sub_412EB4(word_4259C0);
    result = dword_425624(0, 0, 983103);
    v5 = result;
    if ( result != 0 )
    {
      v4 = dword_42562C(v5, &unk_425970, 983103);
      if ( v4 != 0 )
      {
        dword_425428(v3, 0, 28);
        dword_425640(v4, 1, v3);
        dword_425644(v4);
        dword_425648(v4);
      }
      return dword_425648(v5);
    }
  }
  return result;
}


/* sub_413228 @ 00413228 */
int __stdcall sub_413228(int a1)
{
  int v1; // eax
  int v2; // eax
  int result; // eax
  _DWORD v4[64]; // [esp+0h] [ebp-8E0h] BYREF
  _BYTE v5[256]; // [esp+100h] [ebp-7E0h] BYREF
  _BYTE v6[256]; // [esp+200h] [ebp-6E0h] BYREF
  _BYTE v7[1024]; // [esp+300h] [ebp-5E0h] BYREF
  int v8[35]; // [esp+700h] [ebp-1E0h] BYREF
  int v9[11]; // [esp+78Ch] [ebp-154h] BYREF
  int v10[7]; // [esp+7B8h] [ebp-128h] BYREF
  int v11[5]; // [esp+7D4h] [ebp-10Ch] BYREF
  int v12[3]; // [esp+7E8h] [ebp-F8h] BYREF
  int v13[36]; // [esp+7F4h] [ebp-ECh] BYREF
  _BYTE v14[80]; // [esp+884h] [ebp-5Ch] BYREF
  int v15; // [esp+8D4h] [ebp-Ch]
  int v16; // [esp+8D8h] [ebp-8h]
  int v17; // [esp+8DCh] [ebp-4h]

  v17 = 0;
  v15 = 0;
  v16 = 0;
  v13[0] = -1212661639;
  v13[1] = -1212858251;
  v13[2] = -1210564490;
  v13[3] = -1208205256;
  sub_401250(v13, 4);
  v12[0] = -1213448079;
  v12[1] = -1210564485;
  v12[2] = -1208205256;
  sub_401250(v12, 3);
  v11[0] = -1215348707;
  v11[1] = -1214955448;
  v11[2] = -1214693304;
  v11[3] = -1210498972;
  v11[4] = -1208205237;
  sub_401250(v11, 5);
  v8[0] = -1210499043;
  v8[1] = -1216003989;
  v8[2] = -1215807413;
  v8[3] = -1215217571;
  v8[4] = -1215086486;
  v8[5] = -1215807401;
  v8[6] = -1210499043;
  v8[7] = -1213710236;
  v8[8] = -1215217571;
  v8[9] = -1214234552;
  v8[10] = -1215348707;
  v8[11] = -1214693354;
  v8[12] = -1214693312;
  v8[13] = -1211023336;
  v8[14] = -1210302381;
  v8[15] = -1215086476;
  v8[16] = -1214431141;
  v8[17] = -1213251500;
  v8[18] = -1215414179;
  v8[19] = -1214955442;
  v8[20] = -1214693285;
  v8[21] = -1214693258;
  v8[22] = -1215610804;
  v8[23] = -1215414185;
  v8[24] = -1213317037;
  v8[25] = -1215348643;
  v8[26] = -1215414196;
  v8[27] = -1214300079;
  v8[28] = -1214693300;
  if ( dword_4251A8 != 0 )
  {
    v8[29] = -1210302372;
    v8[30] = -1215545323;
    v8[31] = -1215348647;
    v8[32] = -1210302389;
    v8[33] = -1215348707;
    v8[34] = -1208205256;
    sub_401250(v8, 35);
  }
  else
  {
    v8[29] = -1208205220;
    sub_401250(v8, 30);
  }
  v9[0] = -1215348707;
  v9[1] = -1212661639;
  v9[2] = -1212858251;
  v9[3] = -1210564490;
  v9[4] = -1213710236;
  v9[5] = -1215217571;
  v9[6] = -1214234552;
  v9[7] = -1215348707;
  v9[8] = -1214693354;
  v9[9] = -1214693312;
  v9[10] = -1208205256;
  sub_401250(v9, 11);
  v10[0] = -1215348707;
  v10[1] = -1212661639;
  v10[2] = -1212858251;
  v10[3] = -1210564490;
  v10[4] = -1213710236;
  v10[5] = -1215217571;
  v10[6] = -1208205240;
  sub_401250(v10, 7);
  dword_425458(a1);
  if ( sub_412DD0(a1, (int)v13, 1) != 0 && sub_412DD0(a1, (int)v12, 1) != 0 )
  {
    sub_412C1C(a1, (int)v14);
    dword_425464(v4, v11, a1, v14);
    if ( !sub_4129F4((int)v4) )
    {
      if ( dword_4251A8 != 0 )
      {
        dword_425674(&unk_4251AC, 72, 0);
        dword_425464(v7, v8, v14, &unk_4251AC);
        dword_425670(&unk_4251AC, 72, 0);
      }
      else
      {
        dword_425464(v7, v8, v14, v4[0]);
      }
      dword_425464(v6, v9, a1, v14);
      dword_425464(v5, v10, a1, v4[0]);
      dword_425574(v5, 0);
      v1 = sub_40165C();
      if ( dword_425514(v1, v6, 0) != 0 )
      {
        v16 = dword_425624(a1, 0, 983103);
        if ( v16 != 0 )
        {
          v15 = dword_42562C(v16, v14, 983551);
          if ( v15 == 0 )
            v15 = dword_425630(v16, v14, v14, 983551, 272, 3, 1, v7, 0, 0, 0, 0, 0);
          if ( v15 != 0 )
          {
            if ( dword_425634(v15, 0, 0) != 0 )
            {
              v2 = dword_42543C(&unk_425BC0);
              sub_4127A8((int)v4, (int)&unk_425BC0, 2 * v2 + 2);
              dword_425644(v15);
            }
            else
            {
              dword_425644(v15);
              dword_425570(v6);
            }
          }
        }
      }
    }
  }
  if ( v15 != 0 )
    dword_425648(v15);
  if ( v16 != 0 )
    dword_425648(v16);
  sub_412DD0(a1, (int)v13, 0);
  result = sub_412DD0(a1, (int)v12, 0);
  if ( a1 != 0 )
    return sub_40684C(a1);
  return result;
}


/* sub_4136E0 @ 004136E0 */
int *__usercall sub_4136E0@<eax>(int a1@<edi>)
{
  int *result; // eax
  int v2; // edx
  int *v3; // ebx
  int v4; // edi
  int *v5; // esi
  int v6; // eax
  int v7; // ecx
  int v8; // ebx
  int *v9; // esi
  int *v10; // edi
  int v11; // eax
  int v12; // ebx
  int *v13; // esi
  int v14; // eax
  _BYTE v15[520]; // [esp+0h] [ebp-220h] BYREF
  int *v16; // [esp+208h] [ebp-18h]
  int *v17; // [esp+20Ch] [ebp-14h]
  int *v18; // [esp+210h] [ebp-10h]
  int *v19; // [esp+214h] [ebp-Ch]
  int v20; // [esp+218h] [ebp-8h]
  int v21; // [esp+21Ch] [ebp-4h]

  v17 = nullptr;
  v16 = nullptr;
  v19 = nullptr;
  v18 = nullptr;
  result = (int *)sub_4125D0((int)v15);
  if ( result != nullptr )
  {
    sub_412A54((int)v15, 0, 0, 0);
    result = (int *)sub_406830(4000000);
    v17 = result;
    if ( result != nullptr )
    {
      result = (int *)sub_40F788(v2, a1, v17, 3);
      v16 = result;
      if ( result != nullptr )
      {
        v3 = v16;
        result = (int *)sub_406830(4 * (_DWORD)v16);
        v19 = result;
        if ( result != nullptr )
        {
          result = (int *)sub_406830(4 * (_DWORD)v3);
          v18 = result;
          if ( result != nullptr )
          {
            v21 = 0;
            v20 = 0;
            v4 = (int)v19;
            v5 = v17;
            do
            {
              v6 = *v5++;
              result = (int *)dword_42551C(0, 0, sub_413228, v6, 0, 0);
              if ( result != nullptr )
              {
                *(_DWORD *)(v4 + 4 * v21++) = result;
                if ( ++v20 == 64 )
                {
                  v21 = dword_42554C(64, v19, 0, -1);
                  v7 = *(_DWORD *)(v4 + 4 * v21);
                  *(_DWORD *)(v4 + 4 * v21) = 0;
                  result = (int *)dword_4254D0(v7);
                  --v20;
                }
              }
              v16 = (int *)((char *)v16 - 1);
            }
            while ( v16 != nullptr );
            if ( v20 != 0 )
            {
              v8 = v20;
              v9 = v19;
              v10 = v18;
              do
              {
                v11 = *v9++;
                if ( v11 != 0 )
                {
                  *v10++ = v11;
                  --v8;
                }
              }
              while ( v8 != 0 );
              dword_42554C(v20, v18, 1, -1);
              v12 = v20;
              v13 = v18;
              do
              {
                v14 = *v13++;
                result = (int *)dword_4254D0(v14);
                --v12;
              }
              while ( v12 != 0 );
            }
          }
        }
      }
    }
  }
  if ( v18 != nullptr )
    result = (int *)sub_40684C((int)v18);
  if ( v19 != nullptr )
    result = (int *)sub_40684C((int)v19);
  if ( v17 != nullptr )
    return (int *)sub_40684C((int)v17);
  return result;
}


/* sub_413868 @ 00413868 */
int *__usercall sub_413868@<eax>(int a1@<edi>)
{
  int *result; // eax
  int v2; // [esp+0h] [ebp-4h]

  result = (int *)sub_4138B0(0);
  v2 = (int)result;
  if ( result != nullptr )
  {
    result = (int *)sub_412620((int)result, (int)&unk_425BC0, 520);
    if ( result != nullptr )
      result = sub_4136E0(a1);
  }
  if ( v2 != 0 )
    return (int *)sub_40684C(v2);
  return result;
}


/* sub_4138B0 @ 004138B0 */
int sub_4138B0()
{
  unsigned __int8 *v0; // esi
  int v1; // edi
  int i; // ebx
  int v3; // eax
  int v5; // [esp+0h] [ebp-1Ch]
  int v6[3]; // [esp+Ch] [ebp-10h] BYREF
  int v7; // [esp+18h] [ebp-4h]

  v7 = sub_406830(34);
  if ( v7 != 0 )
  {
    v6[0] = -1211351011;
    v6[1] = -1213972470;
    v6[2] = -1208205256;
    sub_401250(v6, 3);
    v0 = (unsigned __int8 *)&unk_424F70;
    v1 = v7;
    for ( i = 0; i != 8; ++i )
    {
      v3 = *v0++;
      dword_425464(v1, v6, v3, v5);
      v1 += 4;
    }
  }
  return v7;
}


/* sub_413920 @ 00413920 */
int __stdcall sub_413920(int a1, int a2)
{
  int v2; // ecx
  _BYTE v4[520]; // [esp+0h] [ebp-334h] BYREF
  int v5[4]; // [esp+208h] [ebp-12Ch] BYREF
  int v6[4]; // [esp+218h] [ebp-11Ch] BYREF
  int v7[11]; // [esp+228h] [ebp-10Ch] BYREF
  int v8[16]; // [esp+254h] [ebp-E0h] BYREF
  int v9[9]; // [esp+294h] [ebp-A0h] BYREF
  int v10[6]; // [esp+2B8h] [ebp-7Ch] BYREF
  int v11[8]; // [esp+2D0h] [ebp-64h] BYREF
  _BYTE v12[8]; // [esp+2F0h] [ebp-44h] BYREF
  int v13; // [esp+2F8h] [ebp-3Ch]
  _BYTE v14[8]; // [esp+300h] [ebp-34h] BYREF
  int v15; // [esp+308h] [ebp-2Ch]
  _BYTE v16[8]; // [esp+310h] [ebp-24h] BYREF
  int v17; // [esp+318h] [ebp-1Ch]
  int v18; // [esp+320h] [ebp-14h] BYREF
  int v19; // [esp+324h] [ebp-10h] BYREF
  int v20; // [esp+328h] [ebp-Ch] BYREF
  int v21; // [esp+32Ch] [ebp-8h] BYREF
  int v22; // [esp+330h] [ebp-4h]

  v22 = 0;
  v21 = 0;
  v20 = 0;
  v19 = 0;
  if ( dword_425744(0) == 0 )
  {
    v6[0] = 1249777384;
    v6[1] = -1506624211;
    v6[2] = -671185773;
    v6[3] = -460726604;
    sub_401250(v6, 4);
    v5[0] = -1209387032;
    v5[1] = -1506624210;
    v5[2] = -671185773;
    v5[3] = -460726604;
    sub_401250(v5, 4);
    v11[0] = -1212661644;
    v11[1] = -1213448071;
    v11[2] = -1210892286;
    v11[3] = -1215414249;
    v11[4] = -1215086505;
    v11[5] = -1212661684;
    v11[6] = -1212596117;
    v11[7] = -1208205256;
    sub_401250(v11, 8);
    if ( dword_4257FC(v11, 0, 0, 1, v6, &v21) == 0 )
    {
      v7[0] = -1214693284;
      v7[1] = -1214431138;
      v7[2] = -1215283123;
      v7[3] = -1213054900;
      v7[4] = -1215217575;
      v7[5] = -1215152047;
      v7[6] = -1212202913;
      v7[7] = -1215152041;
      v7[8] = -1214693300;
      v7[9] = -1215807424;
      v7[10] = -1208205256;
      sub_401250(v7, 11);
      dword_4257A0(v16);
      if ( (*(int (__stdcall **)(int, int *, _BYTE *))(*(_DWORD *)v21 + 60))(v21, v7, v16) == 0 )
      {
        v8[0] = -1212661644;
        v8[1] = -1213448071;
        v8[2] = -1210892286;
        v8[3] = -1212202985;
        v8[4] = -1212071818;
        v8[5] = -1215086488;
        v8[6] = -1214955436;
        v8[7] = -1214955429;
        v8[8] = -1215348643;
        v8[9] = -1212202988;
        v8[10] = -1212071818;
        v8[11] = -1216003989;
        v8[12] = -1215807413;
        v8[13] = -1215217571;
        v8[14] = -1210499052;
        v8[15] = -1208205237;
        sub_401250(v8, 16);
        ((void (__cdecl *)(_BYTE *, int *, int))dword_425464)(v4, v8, v17);
        if ( dword_4257FC(v4, 0, 0, 1, v5, &v19) == 0 && dword_425804(v19, &v20) == 0 )
        {
          v10[0] = -1214955428;
          v10[1] = -1215545269;
          v10[2] = -1214431148;
          v10[3] = -1213054911;
          v10[4] = -1215217575;
          v10[5] = -1208205219;
          sub_401250(v10, 6);
          dword_4257A4(v12);
          while ( 1 )
          {
            v18 = 0;
            dword_4257A4(v16);
            dword_4257A4(v14);
            if ( dword_425808(v20, 1, v16, &v18) != 0
              || v18 == 0
              || (*(int (__stdcall **)(int, int *, _BYTE *))(*(_DWORD *)v17 + 60))(v17, v10, v14) != 0 )
            {
              break;
            }
            if ( dword_425454(a1, v15) == 0 )
            {
              if ( a2 != 0 )
              {
                v9[0] = -1214955428;
                v9[1] = -1215807413;
                v9[2] = -1215152047;
                v9[3] = -1215741857;
                v9[4] = -1215348655;
                v9[5] = -1214693296;
                v9[6] = -1213054884;
                v9[7] = -1215217575;
                v9[8] = -1208205219;
                sub_401250(v9, 9);
                if ( (*(int (__stdcall **)(int, int, _BYTE *))(*(_DWORD *)v17 + 60))(v17, v2, v12) == 0 )
                {
                  dword_425444(a2, v13);
                  dword_4257A4(v12);
                }
              }
              dword_4257A4(v16);
              dword_4257A4(v14);
              v22 = 1;
              break;
            }
          }
        }
      }
    }
    if ( v20 != 0 )
      dword_42580C(v20);
    if ( v19 != 0 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v19 + 8))(v19);
    if ( v21 != 0 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v21 + 8))(v21);
    dword_42574C();
  }
  return v22;
}


/* sub_413CF4 @ 00413CF4 */
int __stdcall sub_413CF4(int a1)
{
  int v1; // eax
  unsigned __int8 *v2; // esi
  int v3; // edi
  int i; // ebx
  unsigned __int8 v5; // al
  int v6; // eax
  unsigned __int8 *v7; // esi
  int j; // ebx
  unsigned __int8 v9; // al
  int v11; // [esp+0h] [ebp-84h]
  _BYTE v12[88]; // [esp+Ch] [ebp-78h] BYREF
  _BYTE v13[16]; // [esp+64h] [ebp-20h] BYREF
  int v14[3]; // [esp+74h] [ebp-10h] BYREF
  int v15; // [esp+80h] [ebp-4h]

  v15 = sub_406830(130);
  if ( v15 != 0 )
  {
    v14[0] = -1211351011;
    v14[1] = -1213972470;
    v14[2] = -1208205256;
    sub_401250(v14, 3);
    dword_4255FC(v12);
    v1 = dword_42543C(a1);
    dword_425600(v12, a1, 2 * v1);
    dword_425604(v12);
    v2 = v13;
    v3 = v15;
    for ( i = 16; i != 0; --i )
    {
      v5 = *v2++;
      dword_425464(v3, v14, v5, v11);
      v3 += 4;
    }
    dword_4255FC(v12);
    v6 = dword_42543C(v15);
    dword_425600(v12, v15, 2 * v6);
    dword_425604(v12);
    v7 = v13;
    for ( j = 16; j != 0; --j )
    {
      v9 = *v7++;
      dword_425464(v3, v14, v9, v11);
      v3 += 4;
    }
  }
  return v15;
}


/* sub_413DFC @ 00413DFC */
int __stdcall sub_413DFC(int a1, int a2)
{
  int v3[31]; // [esp+0h] [ebp-94h] BYREF
  int v4; // [esp+7Ch] [ebp-18h]
  int v5; // [esp+80h] [ebp-14h] BYREF
  int v6; // [esp+84h] [ebp-10h] BYREF
  int v7; // [esp+88h] [ebp-Ch] BYREF
  int v8; // [esp+8Ch] [ebp-8h] BYREF
  int v9; // [esp+90h] [ebp-4h]

  v9 = 0;
  v8 = 0;
  v4 = 0;
  v3[0] = -1215086485;
  v3[1] = -1215807394;
  v3[2] = -1214431153;
  v3[3] = -1214693302;
  v3[4] = -1213120412;
  v3[5] = -1214300079;
  v3[6] = -1215086518;
  v3[7] = -1215086517;
  v3[8] = -1215807394;
  v3[9] = -1213513628;
  v3[10] = -1215152047;
  v3[11] = -1215086500;
  v3[12] = -1215348657;
  v3[13] = -1212202908;
  v3[14] = -1215414195;
  v3[15] = -1214693302;
  v3[16] = -1215807402;
  v3[17] = -1214693266;
  v3[18] = -1215348662;
  v3[19] = -1215086511;
  v3[20] = -1214234538;
  v3[21] = -1215414145;
  v3[22] = -1215741865;
  v3[23] = -1210302392;
  v3[24] = -1215086488;
  v3[25] = -1214955436;
  v3[26] = -1216004005;
  v3[27] = -1213251484;
  v3[28] = -1214431156;
  v3[29] = -1215741876;
  v3[30] = -1208205237;
  sub_401250(v3, 31);
  if ( dword_42560C(-2147483646, v3, 0, 0, 0, 131359, 0, &v8, 0) == 0 )
  {
    v4 = sub_413CF4(a1);
    if ( v4 != 0 )
    {
      if ( a2 != 0 )
      {
        v7 = 1;
        v6 = 4;
        if ( dword_425614(v8, v4, 0, &v7, &v5, &v6) == 0 && v5 == 49 )
          v9 = 1;
      }
      else
      {
        v5 = 49;
        if ( dword_425610(v8, v4, 0, 1, &v5, 4) == 0 )
          v9 = 1;
      }
    }
  }
  if ( v8 != 0 )
    dword_4254D0(v8);
  if ( v4 != 0 )
    sub_40684C(v4);
  return v9;
}


/* sub_413FCC @ 00413FCC */
int __stdcall sub_413FCC(int a1)
{
  _DWORD v2[64]; // [esp+0h] [ebp-550h] BYREF
  _BYTE v3[256]; // [esp+100h] [ebp-450h] BYREF
  _BYTE v4[256]; // [esp+200h] [ebp-350h] BYREF
  _BYTE v5[272]; // [esp+300h] [ebp-250h] BYREF
  _BYTE v6[80]; // [esp+410h] [ebp-140h] BYREF
  int v7[14]; // [esp+460h] [ebp-F0h] BYREF
  int v8[11]; // [esp+498h] [ebp-B8h] BYREF
  int v9[7]; // [esp+4C4h] [ebp-8Ch] BYREF
  int v10[5]; // [esp+4E0h] [ebp-70h] BYREF
  int v11[3]; // [esp+4F4h] [ebp-5Ch] BYREF
  int v12[4]; // [esp+500h] [ebp-50h] BYREF
  int v13; // [esp+510h] [ebp-40h]
  void *v14; // [esp+514h] [ebp-3Ch]
  _BYTE v15[4]; // [esp+518h] [ebp-38h] BYREF
  int v16; // [esp+51Ch] [ebp-34h]
  _DWORD v17[3]; // [esp+520h] [ebp-30h] BYREF
  _BYTE v18[2]; // [esp+52Ch] [ebp-24h] BYREF
  __int16 v19; // [esp+52Eh] [ebp-22h]
  int v20; // [esp+530h] [ebp-20h]
  int v21; // [esp+534h] [ebp-1Ch]
  int v22; // [esp+538h] [ebp-18h]
  int v23; // [esp+53Ch] [ebp-14h]
  int v24; // [esp+540h] [ebp-10h]
  int v25; // [esp+544h] [ebp-Ch]
  int v26; // [esp+548h] [ebp-8h]
  int v27; // [esp+54Ch] [ebp-4h]

  v27 = 0;
  v14 = nullptr;
  v13 = 0;
  v25 = 0;
  v26 = 0;
  v24 = -1;
  v12[0] = -1212661639;
  v12[1] = -1212858251;
  v12[2] = -1210564490;
  v12[3] = -1208205256;
  sub_401250(v12, 4);
  dword_425458(a1);
  if ( sub_412DD0(a1, (int)v12, 1) != 0 )
  {
    v11[0] = -1213448079;
    v11[1] = -1210564485;
    v11[2] = -1208205256;
    sub_401250(v11, 3);
    if ( sub_412DD0(a1, (int)v11, 1) != 0 )
    {
      v10[0] = -1215348707;
      v10[1] = -1214955448;
      v10[2] = -1214693304;
      v10[3] = -1210498972;
      v10[4] = -1208205237;
      sub_401250(v10, 5);
      sub_412C1C(a1, (int)v6);
      dword_425464(v2, v10, a1, v6);
      if ( !sub_4129F4((int)v2) )
      {
        v14 = sub_406DB0(dword_420B38);
        if ( v14 != nullptr )
        {
          v13 = sub_406830(4 * dword_420B38[-1]);
          if ( v13 != 0 )
          {
            v16 = sub_418BA4(v14, v13);
            if ( v16 != -1 )
            {
              v9[0] = -1215348707;
              v9[1] = -1212661639;
              v9[2] = -1212858251;
              v9[3] = -1210564490;
              v9[4] = -1213710236;
              v9[5] = -1215217571;
              v9[6] = -1208205240;
              sub_401250(v9, 7);
              dword_425464(v3, v9, a1, v2[0]);
              dword_425574(v3, 0);
              v8[0] = -1215348707;
              v8[1] = -1212661639;
              v8[2] = -1212858251;
              v8[3] = -1210564490;
              v8[4] = -1213710236;
              v8[5] = -1215217571;
              v8[6] = -1214234552;
              v8[7] = -1215348707;
              v8[8] = -1214693354;
              v8[9] = -1214693312;
              v8[10] = -1208205256;
              sub_401250(v8, 11);
              dword_425464(v4, v8, a1, v6);
              v18[0] = 1;
              v18[1] = 0;
              v19 = 4;
              v20 = 0;
              v21 = 0;
              v22 = 0;
              v23 = 0;
              v17[0] = 12;
              v17[1] = v18;
              v17[2] = 1;
              v24 = dword_425528(v4, 0x40000000, 0, v17, 1, 128, 0);
              if ( v24 != -1 && dword_42552C(v24, v13, v16, v15, 0) != 0 )
              {
                dword_4254D0(v24);
                v24 = -1;
                v7[0] = -1210499043;
                v7[1] = -1216003989;
                v7[2] = -1215807413;
                v7[3] = -1215217571;
                v7[4] = -1215086486;
                v7[5] = -1215807401;
                v7[6] = -1210499043;
                v7[7] = -1213710236;
                v7[8] = -1215217571;
                v7[9] = -1214234552;
                v7[10] = -1215348707;
                v7[11] = -1214693354;
                v7[12] = -1214693312;
                v7[13] = -1208205256;
                sub_401250(v7, 14);
                dword_425464(v5, v7, v6, v2[0]);
                v26 = dword_425624(a1, 0, 983103);
                if ( v26 != 0 )
                {
                  v25 = dword_42562C(v26, v6, 983551);
                  if ( v25 == 0 )
                    v25 = dword_425630(v26, v6, v6, 983551, 272, 3, 1, v5, 0, 0, 0, 0, 0);
                  if ( v25 != 0 )
                  {
                    if ( dword_425634(v25, 0, 0) != 0 )
                    {
                      v27 = 1;
                    }
                    else
                    {
                      dword_425644(v25);
                      dword_425570(v4);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( v25 != 0 )
    dword_425648(v25);
  if ( v26 != 0 )
    dword_425648(v26);
  sub_412DD0(a1, (int)v12, 0);
  sub_412DD0(a1, (int)v11, 0);
  if ( v24 != -1 )
    dword_4254D0(v24);
  if ( v14 != nullptr )
    sub_40684C((int)v14);
  if ( v13 != 0 )
    sub_40684C(v13);
  if ( a1 != 0 )
    sub_40684C(a1);
  return v27;
}


/* sub_414464 @ 00414464 */
int *__usercall sub_414464@<eax>(int a1@<edi>)
{
  int *result; // eax
  int v2; // edx
  char v3; // al
  int *v4; // ebx
  int v5; // edi
  int *v6; // esi
  int v7; // eax
  int v8; // ecx
  int v9; // ebx
  int *v10; // esi
  int *v11; // edi
  int v12; // eax
  int v13; // ebx
  int *v14; // esi
  int v15; // eax
  _BYTE v16[520]; // [esp+Ch] [ebp-220h] BYREF
  int *v17; // [esp+214h] [ebp-18h]
  int *v18; // [esp+218h] [ebp-14h]
  int *v19; // [esp+21Ch] [ebp-10h]
  int *v20; // [esp+220h] [ebp-Ch]
  int v21; // [esp+224h] [ebp-8h]
  int v22; // [esp+228h] [ebp-4h]

  v18 = nullptr;
  v17 = nullptr;
  v20 = nullptr;
  v19 = nullptr;
  result = (int *)sub_4125D0((int)v16);
  if ( result != nullptr )
  {
    sub_412A54((int)v16, 0, 0, 0);
    result = (int *)sub_406830(4000000);
    v18 = result;
    if ( result != nullptr )
    {
      v3 = sub_409610() != 0 ? 2 : 1;
      result = (int *)sub_40F788(v2, a1, v18, v3);
      v17 = result;
      if ( result != nullptr )
      {
        v4 = v17;
        result = (int *)sub_406830(4 * (_DWORD)v17);
        v20 = result;
        if ( result != nullptr )
        {
          result = (int *)sub_406830(4 * (_DWORD)v4);
          v19 = result;
          if ( result != nullptr )
          {
            v22 = 0;
            v21 = 0;
            v5 = (int)v20;
            v6 = v18;
            do
            {
              v7 = *v6++;
              result = (int *)dword_42551C(0, 0, sub_413FCC, v7, 0, 0);
              if ( result != nullptr )
              {
                *(_DWORD *)(v5 + 4 * v22++) = result;
                if ( ++v21 == 64 )
                {
                  v22 = dword_42554C(64, v20, 0, -1);
                  v8 = *(_DWORD *)(v5 + 4 * v22);
                  *(_DWORD *)(v5 + 4 * v22) = 0;
                  result = (int *)dword_4254D0(v8);
                  --v21;
                }
              }
              v17 = (int *)((char *)v17 - 1);
            }
            while ( v17 != nullptr );
            if ( v21 != 0 )
            {
              v9 = v21;
              v10 = v20;
              v11 = v19;
              do
              {
                v12 = *v10++;
                if ( v12 != 0 )
                {
                  *v11++ = v12;
                  --v9;
                }
              }
              while ( v9 != 0 );
              dword_42554C(v21, v19, 1, -1);
              v13 = v21;
              v14 = v19;
              do
              {
                v15 = *v14++;
                result = (int *)dword_4254D0(v15);
                --v13;
              }
              while ( v13 != 0 );
            }
          }
        }
      }
    }
  }
  if ( v19 != nullptr )
    result = (int *)sub_40684C((int)v19);
  if ( v20 != nullptr )
    result = (int *)sub_40684C((int)v20);
  if ( v18 != nullptr )
    return (int *)sub_40684C((int)v18);
  return result;
}


/* sub_414604 @ 00414604 */
void *sub_414604()
{
  void *result; // eax
  _BYTE v1[520]; // [esp+Ch] [ebp-2B0h] BYREF
  int v2[11]; // [esp+214h] [ebp-A8h] BYREF
  int v3[4]; // [esp+240h] [ebp-7Ch] BYREF
  _DWORD v4[4]; // [esp+250h] [ebp-6Ch] BYREF
  _DWORD v5[17]; // [esp+260h] [ebp-5Ch] BYREF
  int v6; // [esp+2A4h] [ebp-18h]
  _BYTE v7[8]; // [esp+2A8h] [ebp-14h] BYREF
  int v8; // [esp+2B0h] [ebp-Ch]
  void *v9; // [esp+2B8h] [ebp-4h] BYREF

  result = (void *)sub_401574();
  if ( (unsigned int)result >= 0x3D )
  {
    result = (void *)sub_409610();
    if ( result != nullptr )
    {
      v9 = result;
      result = sub_406DB0(dword_421F72);
      v6 = (int)result;
      if ( result != nullptr )
      {
        result = (void *)dword_425744(0);
        if ( result == nullptr )
        {
          v3[0] = 1249777384;
          v3[1] = -1506624211;
          v3[2] = -671185773;
          v3[3] = -460726604;
          sub_401250(v3, 4);
          v2[0] = -1212661644;
          v2[1] = -1213448071;
          v2[2] = -1210892286;
          v2[3] = -1215414249;
          v2[4] = -1215086505;
          v2[5] = -1212661684;
          v2[6] = -1212596117;
          v2[7] = -1208205256;
          sub_401250(v2, 8);
          if ( dword_4257FC(v2, 0, 0, 1, v3, &v9) == 0 )
          {
            v2[0] = -1214693284;
            v2[1] = -1214431138;
            v2[2] = -1215283123;
            v2[3] = -1213054900;
            v2[4] = -1215217575;
            v2[5] = -1215152047;
            v2[6] = -1212202913;
            v2[7] = -1215152041;
            v2[8] = -1214693300;
            v2[9] = -1215807424;
            v2[10] = -1208205256;
            sub_401250(v2, 11);
            dword_4257A0(v7);
            if ( (*(int (__stdcall **)(void *, int *, _BYTE *))(*(_DWORD *)v9 + 60))(v9, v2, v7) == 0 )
            {
              ((void (__cdecl *)(_BYTE *, int, int))dword_425464)(v1, v6, v8);
              dword_4257A4(v7);
              dword_425428(v4, 0, 16);
              dword_425428(v5, 0, 68);
              v5[0] = 68;
              if ( dword_4255D4(0, v1, 0, 0, 1, 0x8000000, 0, 0, v5, v4) != 0 )
              {
                dword_4254D0(v4[1]);
                dword_4254D0(v4[0]);
              }
            }
          }
          if ( v9 != nullptr )
            (*(void (__stdcall **)(void *))(*(_DWORD *)v9 + 8))(v9);
          result = (void *)dword_42574C();
        }
        if ( v6 != 0 )
          return (void *)sub_40684C(v6);
      }
    }
  }
  return result;
}


/* sub_414820 @ 00414820 */
int *__stdcall sub_414820(int a1)
{
  int *v1; // eax
  int *v2; // ecx

  v1 = (int *)sub_406830(20);
  v2 = v1;
  if ( v1 != nullptr )
  {
    *v1 = -1214955394;
    v1[1] = -1214693292;
    if ( a1 != 0 )
    {
      v1[2] = -1210957749;
      v1[3] = -1215217600;
      v1[4] = -1208205228;
      sub_401250(v1, 5);
    }
    else
    {
      v1[2] = -1208205237;
      sub_401250(v1, 3);
    }
  }
  return v2;
}


/* sub_41487C @ 0041487C */
int *__stdcall sub_41487C(int a1)
{
  int *v1; // eax
  int *v2; // ecx

  v1 = (int *)sub_406830(26);
  v2 = v1;
  if ( v1 != nullptr )
  {
    *v1 = -1214693269;
    v1[1] = -1215676342;
    v1[2] = -1214300079;
    v1[3] = -1215348643;
    if ( a1 != 0 )
    {
      v1[4] = -1216069610;
      v1[5] = -1215283115;
      sub_401250(v1, 6);
    }
    else
    {
      sub_401250(v1, 4);
    }
  }
  return v2;
}


/* sub_4148D8 @ 004148D8 */
int *sub_4148D8()
{
  int *v0; // eax
  int *v1; // ecx

  v0 = (int *)sub_406830(24);
  v1 = v0;
  if ( v0 != nullptr )
  {
    *v0 = -1215414168;
    v0[1] = -1214627747;
    v0[2] = -1215414179;
    v0[3] = -1215152035;
    v0[4] = -1214693285;
    v0[5] = -1208205237;
    sub_401250(v0, 6);
  }
  return v1;
}


/* sub_41491C @ 0041491C */
int *__stdcall sub_41491C(int a1)
{
  int *v1; // eax
  int *v2; // ecx

  v1 = (int *)sub_406830(38);
  v2 = v1;
  if ( v1 != nullptr )
  {
    *v1 = -1214300053;
    v1[1] = -1214693296;
    v1[2] = -1215741860;
    v1[3] = -1214693292;
    v1[4] = -1213710244;
    v1[5] = -1215348647;
    v1[6] = -1215348653;
    sub_401250(v1, 7);
    if ( a1 != 0 )
    {
      v2[7] = -1216069610;
      v2[8] = -1215283115;
      sub_401250(v2 + 7, 2);
    }
  }
  return v2;
}


/* sub_41498C @ 0041498C */
int *__stdcall sub_41498C(int a1)
{
  int *v1; // eax
  int *v2; // ecx

  v1 = (int *)sub_406830(36);
  v2 = v1;
  if ( v1 != nullptr )
  {
    *v1 = -1214693258;
    v1[1] = -1215610804;
    v1[2] = -1215414185;
    v1[3] = -1213251501;
    v1[4] = -1214431152;
    v1[5] = -1214693302;
    if ( a1 != 0 )
    {
      v1[6] = -1210957749;
      v1[7] = -1215217600;
      v1[8] = -1208205228;
      sub_401250(v1, 9);
    }
    else
    {
      v1[6] = -1208205237;
      sub_401250(v1, 7);
    }
  }
  return v2;
}


/* sub_414A04 @ 00414A04 */
int sub_414A04()
{
  int v0; // ebx
  _WORD v2[8]; // [esp+4h] [ebp-30h] BYREF
  int v3[8]; // [esp+14h] [ebp-20h] BYREF

  v0 = sub_406830(20);
  if ( v0 != 0 )
  {
    v3[0] = -741838819;
    v3[1] = -2050202347;
    v3[2] = -2015793828;
    v3[3] = -1831066614;
    v3[4] = -1919389176;
    v3[5] = -741445603;
    v3[6] = -2050202366;
    v3[7] = -1208205220;
    sub_401250(v3, 8);
  }
  dword_4255BC(v2);
  dword_425468(v0, v3, v2[0], v2[1], v2[3], v2[4], v2[5], v2[6]);
  return v0;
}


/* sub_414AA8 @ 00414AA8 */
int __stdcall sub_414AA8(int a1, int a2)
{
  int v3[13]; // [esp+0h] [ebp-34h] BYREF

  v3[0] = -1882430141;
  v3[1] = -1831790508;
  v3[2] = -1700498424;
  v3[3] = -272076771;
  v3[4] = -2050202347;
  v3[5] = -2050202272;
  v3[6] = -2015793824;
  v3[7] = -2015815670;
  v3[8] = -2015815670;
  v3[9] = -2015815670;
  v3[10] = -2015815670;
  v3[11] = -2015815670;
  v3[12] = -1216276470;
  sub_401250(v3, 13);
  return dword_425468(
           a2,
           v3,
           *(_DWORD *)a1,
           *(unsigned __int16 *)(a1 + 4),
           *(unsigned __int16 *)(a1 + 6),
           *(unsigned __int8 *)(a1 + 8),
           *(unsigned __int8 *)(a1 + 9),
           *(unsigned __int8 *)(a1 + 10));
}


/* sub_414B64 @ 00414B64 */
int __stdcall sub_414B64(int a1)
{
  int v1; // ebx
  int *v2; // edi
  int v3; // eax
  _BYTE v5[16]; // [esp+8h] [ebp-14h] BYREF
  int v6; // [esp+18h] [ebp-4h]

  v1 = a1;
  v6 = sub_406830(4 * a1 + 4);
  v2 = (int *)v6;
  do
  {
    dword_425740(v5);
    v3 = sub_406830(40);
    if ( v3 != 0 )
    {
      *v2++ = v3;
      sub_414AA8((int)v5, *(v2 - 1));
    }
    --v1;
  }
  while ( v1 != 0 );
  return v6;
}


/* sub_414BBC @ 00414BBC */
int __stdcall sub_414BBC(int a1)
{
  int v1; // eax
  int v3[10]; // [esp+0h] [ebp-58h] BYREF
  int v4[2]; // [esp+28h] [ebp-30h] BYREF
  int v5[4]; // [esp+30h] [ebp-28h] BYREF
  int v6; // [esp+40h] [ebp-18h]
  __int16 *v7; // [esp+44h] [ebp-14h]
  int v8; // [esp+48h] [ebp-10h]
  _BYTE v9[4]; // [esp+4Ch] [ebp-Ch] BYREF
  int v10; // [esp+50h] [ebp-8h]
  int v11; // [esp+54h] [ebp-4h]

  v11 = 0;
  v8 = 0;
  v7 = nullptr;
  v10 = -1;
  v6 = sub_406830(2048);
  if ( v6 != 0 && (*(int (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)a1 + 56))(a1, 0, v6, 1024) == 0 )
  {
    v7 = (__int16 *)sub_406830(34);
    if ( v7 != nullptr && (*(int (__stdcall **)(int, __int16 *, int))(*(_DWORD *)a1 + 40))(a1, v7, 17) == 0 )
    {
      sub_401228(v7, v7);
      v5[0] = -1213448065;
      v5[1] = -1210957716;
      v5[2] = -1213054863;
      v5[3] = -1208205199;
      sub_401250(v5, 4);
      dword_425790(v6, v5);
      v10 = dword_425528(v6, 0x40000000, 0, 0, 4, 128, 0);
      if ( v10 != -1 )
      {
        v8 = sub_406830(128);
        if ( v8 != 0 )
        {
          v4[0] = -2033289718;
          v4[1] = -1211205376;
          sub_401250(v4, 2);
          v3[0] = -644282525;
          v3[1] = -610454947;
          v3[2] = -503952027;
          v3[3] = -561040803;
          v3[4] = -1832833449;
          v3[5] = -738833077;
          v3[6] = -611568815;
          v3[7] = -692962983;
          v3[8] = -1832835755;
          v3[9] = -1208595125;
          sub_401250(v3, 10);
          v1 = ((int (__cdecl *)(int, int *, int *, __int16 *))dword_425468)(v8, v3, v4, v7);
          if ( dword_42552C(v10, v8, v1, v9, 0) != 0 )
            v11 = 1;
        }
      }
    }
  }
  if ( v8 != 0 )
    sub_40684C(v8);
  if ( v6 != 0 )
    sub_40684C(v6);
  if ( v7 != nullptr )
    sub_40684C((int)v7);
  if ( v10 != -1 )
    dword_4254D0(v10);
  return v11;
}


/* sub_414DAC @ 00414DAC */
int __stdcall sub_414DAC(int a1)
{
  int v1; // ebx
  int *v2; // esi
  int v3; // ebx
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v8; // [esp-58h] [ebp-84h]
  int v9; // [esp-54h] [ebp-80h]
  int v10; // [esp-50h] [ebp-7Ch]
  int v11; // [esp-4Ch] [ebp-78h]
  int v12; // [esp-48h] [ebp-74h]
  void *v13; // [esp+0h] [ebp-2Ch]
  int v14; // [esp+4h] [ebp-28h]
  int v15; // [esp+8h] [ebp-24h]
  int v16; // [esp+Ch] [ebp-20h]
  int *v17; // [esp+10h] [ebp-1Ch]
  int *v18; // [esp+14h] [ebp-18h]
  int v19; // [esp+18h] [ebp-14h]
  int v20; // [esp+1Ch] [ebp-10h]
  _BYTE v21[4]; // [esp+20h] [ebp-Ch] BYREF
  int v22; // [esp+24h] [ebp-8h]
  int v23; // [esp+28h] [ebp-4h]

  v23 = 0;
  v16 = 0;
  v19 = 0;
  v18 = nullptr;
  v17 = nullptr;
  v13 = nullptr;
  v15 = 0;
  v14 = 0;
  v20 = sub_406830(2048);
  if ( v20 != 0 && (*(int (__cdecl **)(int, int, int, int))(*(_DWORD *)a1 + 56))(a1, 2, v20, 1024) == 0 )
  {
    v18 = sub_4148D8();
    if ( v18 != nullptr )
    {
      dword_425790(v20, v18);
      dword_425574(v20, 0);
      v17 = sub_41487C(0);
      if ( v17 != nullptr )
      {
        dword_425790(v20, v17);
        sub_40684C((int)v17);
        dword_425574(v20, 0);
        v17 = sub_41487C(1);
        if ( v17 != nullptr )
        {
          dword_425790(v20, v17);
          v22 = dword_425528(v20, 0x40000000, 0, 0, 4, 128, 0);
          if ( v22 != -1 )
          {
            v19 = sub_414A04();
            if ( v19 != 0 )
            {
              v16 = sub_414B64(17);
              if ( v16 != 0 )
              {
                v1 = 16 * dword_42208A[-1];
                v15 = sub_406830(v1);
                if ( v15 != 0 )
                {
                  v13 = sub_406DB0(dword_42208A);
                  if ( v13 != nullptr && sub_418BA4(v13, v15) != -1 )
                  {
                    v14 = sub_406830(v1);
                    if ( v14 != 0 )
                    {
                      v2 = (int *)v16;
                      v3 = 17;
                      v4 = 0;
                      do
                      {
                        v8 = *(_DWORD *)(v16 + v4);
                        v4 += 4;
                        --v3;
                      }
                      while ( v3 != 0 );
                      v5 = dword_425468(v14, v15, v19, v8, v9, v10, v11, v12);
                      if ( dword_42552C(v22, v14, v5, v21, 0) != 0 )
                      {
                        while ( 1 )
                        {
                          v6 = *v2++;
                          if ( v6 == 0 )
                            break;
                          sub_40684C(v6);
                        }
                        v23 = 1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( v13 != nullptr )
    sub_40684C((int)v13);
  if ( v16 != 0 )
    sub_40684C(v16);
  if ( v19 != 0 )
    sub_40684C(v19);
  if ( v17 != nullptr )
    sub_40684C((int)v17);
  if ( v18 != nullptr )
    sub_40684C((int)v18);
  if ( v14 != 0 )
    sub_40684C(v14);
  if ( v15 != 0 )
    sub_40684C(v15);
  if ( v20 != 0 )
    sub_40684C(v20);
  if ( v22 != -1 )
    dword_4254D0(v22);
  return v23;
}


/* sub_41503C @ 0041503C */
int __stdcall sub_41503C(int a1, __int16 *a2, int a3)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  _DWORD *v7; // edi
  int v8; // ebx
  int v9; // ecx
  __int16 v10; // ax
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  _DWORD *v14; // esi
  int v15; // eax
  char *v16; // esi
  _DWORD *v17; // edi
  int v18; // ebx
  int v19; // ecx
  char v20; // al
  int v21; // ebx
  int v22; // eax
  _DWORD *v23; // esi
  int v24; // eax
  _DWORD v26[32]; // [esp+Fh] [ebp-109h] BYREF
  _BYTE v27[17]; // [esp+8Fh] [ebp-89h] BYREF
  _DWORD v28[12]; // [esp+A0h] [ebp-78h] BYREF
  _DWORD v29[5]; // [esp+D0h] [ebp-48h] BYREF
  int v30; // [esp+E4h] [ebp-34h]
  int v31; // [esp+E8h] [ebp-30h]
  int v32; // [esp+ECh] [ebp-2Ch]
  int v33; // [esp+F0h] [ebp-28h]
  int v34; // [esp+F4h] [ebp-24h]
  int v35; // [esp+F8h] [ebp-20h]
  int v36; // [esp+FCh] [ebp-1Ch]
  int v37; // [esp+100h] [ebp-18h]
  _DWORD *v38; // [esp+104h] [ebp-14h]
  int v39; // [esp+108h] [ebp-10h]
  _BYTE v40[4]; // [esp+10Ch] [ebp-Ch] BYREF
  int v41; // [esp+110h] [ebp-8h]
  int v42; // [esp+114h] [ebp-4h]

  v42 = 0;
  v41 = -1;
  v37 = 0;
  v35 = 0;
  v29[0] = 0;
  v32 = 0;
  v31 = 0;
  v30 = 0;
  v33 = 0;
  v36 = 0;
  v34 = sub_406830(2048);
  if ( v34 != 0 )
  {
    v28[0] = -1214234524;
    v28[1] = -1215348707;
    v28[2] = -1215348636;
    v28[3] = -1215348671;
    v28[4] = -1215086514;
    v28[5] = -1214234540;
    v28[6] = -1215348707;
    v28[7] = -1215348636;
    v28[8] = -1215414181;
    v28[9] = -1215545263;
    v28[10] = -1215348660;
    v28[11] = -1208205212;
    sub_401250(v28, 12);
    dword_425464(v34, v28, a3, a3);
    v3 = sub_40165C();
    v4 = dword_425770(v3);
    dword_425790(v34, v4);
    v5 = sub_40165C();
    if ( dword_425514(v5, v34, 0) != 0 )
    {
      v33 = sub_406830(2048);
      if ( v33 != 0 && (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 56))(a1, 1, v33, 1024) == 0 )
      {
        v35 = sub_4148D8();
        if ( v35 != 0 )
        {
          dword_425790(v33, v35);
          dword_425574(v33, 0);
          v37 = sub_414820(0);
          if ( v37 != 0 )
          {
            dword_425790(v33, v37);
            sub_40684C(v37);
            v37 = 0;
            dword_425574(v33, 0);
            v37 = sub_414820(1);
            if ( v37 != 0 )
            {
              dword_425790(v33, v37);
              v41 = dword_425528(v33, 0x40000000, 0, 0, 4, 128, 0);
              if ( v41 != -1 )
              {
                v39 = sub_414A04();
                if ( v39 != 0 )
                {
                  v38 = (_DWORD *)sub_414B64(1);
                  if ( v38 != nullptr )
                  {
                    v7 = v27;
LABEL_12:
                    v8 = 0;
                    v9 = 4;
                    while ( 1 )
                    {
                      v10 = *a2++;
                      if ( v10 == 0 )
                        break;
                      LOBYTE(v8) = v10;
                      v8 = __ROL4__(v8, 8);
                      if ( --v9 == 0 )
                      {
                        *v7++ = __ROL4__(v8, 16);
                        goto LABEL_12;
                      }
                    }
                    *(_BYTE *)v7 = 0;
                    v11 = 16 * dword_4222C3[-1];
                    v12 = sub_406830(v11);
                    v32 = v12;
                    if ( v12 != 0 )
                    {
                      v30 = sub_406DB0(dword_4222C3);
                      if ( v30 != 0 && sub_418BA4(v30, v32) != -1 )
                      {
                        v31 = sub_406830(v11);
                        if ( v31 != 0 )
                        {
                          v26[0] = -627502051;
                          v26[1] = -980089784;
                          v26[2] = -1208205283;
                          sub_401250(v26, 3);
                          sub_401228(v34, v34);
                          v13 = dword_425774(v34);
                          dword_425794(v26, v13);
                          v14 = v38;
                          v15 = dword_425468(v31, v32, v27, v27, v39, *v38, v34, v26);
                          if ( dword_42552C(v41, v31, v15, v40, 0) != 0 )
                          {
                            sub_40684C(*v14);
                            if ( v30 != 0 )
                            {
                              sub_40684C(v30);
                              v30 = 0;
                            }
                            if ( v38 != nullptr )
                            {
                              sub_40684C(v38);
                              v38 = nullptr;
                            }
                            if ( v37 != 0 )
                            {
                              sub_40684C(v37);
                              v37 = 0;
                            }
                            if ( v39 != 0 )
                            {
                              sub_40684C(v39);
                              v39 = 0;
                            }
                            if ( v35 != 0 )
                            {
                              sub_40684C(v35);
                              v35 = 0;
                            }
                            if ( v33 != 0 )
                            {
                              sub_40684C(v33);
                              v33 = 0;
                            }
                            if ( v32 != 0 )
                            {
                              sub_40684C(v32);
                              v32 = 0;
                            }
                            if ( v31 != 0 )
                            {
                              sub_40684C(v31);
                              v31 = 0;
                            }
                            if ( v41 != -1 )
                            {
                              dword_4254D0(v41);
                              v41 = -1;
                            }
                            v33 = sub_406830(2048);
                            if ( v33 != 0
                              && (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 56))(a1, 1, v33, 1024) == 0 )
                            {
                              v35 = sub_4148D8();
                              if ( v35 != 0 )
                              {
                                dword_425790(v33, v35);
                                dword_425574(v33, 0);
                                v36 = sub_41491C(0);
                                if ( v36 != 0 )
                                {
                                  dword_425790(v33, v36);
                                  dword_425574(v33, 0);
                                  sub_40684C(v36);
                                  v36 = 0;
                                  v36 = sub_41491C(1);
                                  if ( v36 != 0 )
                                  {
                                    dword_425790(v33, v36);
                                    v41 = dword_425528(v33, 0x40000000, 0, 0, 4, 128, 0);
                                    if ( v41 != -1 )
                                    {
                                      v39 = sub_414A04();
                                      if ( v39 != 0 )
                                      {
                                        v38 = (_DWORD *)sub_414B64(1);
                                        if ( v38 != nullptr )
                                        {
                                          v29[0] = -153349002;
                                          v29[1] = -122416019;
                                          v29[2] = -290977430;
                                          v29[3] = -458943644;
                                          v29[4] = -1213135508;
                                          sub_401250(v29, 5);
                                          v16 = v27;
                                          v17 = v27;
LABEL_49:
                                          v18 = 0;
                                          v19 = 4;
                                          while ( 1 )
                                          {
                                            v20 = *v16++;
                                            if ( v20 == 0 )
                                              break;
                                            LOBYTE(v18) = v20;
                                            v18 = __ROL4__(v18, 8);
                                            if ( --v19 == 0 )
                                            {
                                              *v17++ = __ROL4__(v18, 16);
                                              goto LABEL_49;
                                            }
                                          }
                                          *(_BYTE *)v17 = 0;
                                          v21 = 16 * dword_4223D8[-1];
                                          v22 = sub_406830(v21);
                                          v32 = v22;
                                          if ( v22 != 0 )
                                          {
                                            v30 = sub_406DB0(dword_4223D8);
                                            if ( v30 != 0 && sub_418BA4(v30, v32) != -1 )
                                            {
                                              v31 = sub_406830(v21);
                                              if ( v31 != 0 )
                                              {
                                                v23 = v38;
                                                v24 = dword_425468(v31, v32, v27, v39, *v38, v27, v29, v29);
                                                if ( dword_42552C(v41, v31, v24, v40, 0) != 0 )
                                                {
                                                  sub_40684C(*v23);
                                                  v42 = 1;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( v30 != 0 )
    sub_40684C(v30);
  if ( v38 != nullptr )
    sub_40684C(v38);
  if ( v37 != 0 )
    sub_40684C(v37);
  if ( v39 != 0 )
    sub_40684C(v39);
  if ( v36 != 0 )
    sub_40684C(v36);
  if ( v35 != 0 )
    sub_40684C(v35);
  if ( v34 != 0 )
    sub_40684C(v34);
  if ( v33 != 0 )
    sub_40684C(v33);
  if ( v32 != 0 )
    sub_40684C(v32);
  if ( v31 != 0 )
    sub_40684C(v31);
  if ( v41 != -1 )
    dword_4254D0(v41);
  return v42;
}


/* sub_415710 @ 00415710 */
int __stdcall sub_415710(int a1)
{
  int v1; // ecx
  int v2; // ecx
  void *v4; // [esp+0h] [ebp-5Ch]
  int v5; // [esp+4h] [ebp-58h]
  int v6; // [esp+8h] [ebp-54h]
  int v7[7]; // [esp+Ch] [ebp-50h] BYREF
  int v8[7]; // [esp+28h] [ebp-34h] BYREF
  int v9; // [esp+44h] [ebp-18h]
  int v10; // [esp+48h] [ebp-14h]
  int v11; // [esp+4Ch] [ebp-10h]
  int v12; // [esp+50h] [ebp-Ch]
  _BYTE v13[4]; // [esp+54h] [ebp-8h] BYREF
  int v14; // [esp+58h] [ebp-4h]

  v14 = 0;
  v4 = nullptr;
  v12 = -1;
  v11 = -1;
  v9 = 0;
  v6 = 0;
  v5 = 0;
  v10 = sub_406830(2048);
  if ( v10 != 0 )
  {
    v9 = sub_406830(2048);
    if ( v9 != 0 && (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 56))(a1, 2, v10, 1024) == 0 )
    {
      dword_425444(v9, v10);
      v8[0] = -1214693270;
      v8[1] = -1214955425;
      v8[2] = -1215807413;
      v8[3] = -1216004022;
      v8[4] = -1215545322;
      v8[5] = -1215283113;
      v8[6] = -1208205256;
      sub_401250(v8, 7);
      v7[0] = -1215086501;
      v7[1] = -1215217579;
      v7[2] = -1215152035;
      v7[3] = -1210957748;
      v7[4] = -1215217573;
      v7[5] = -1216069556;
      v7[6] = -1208205256;
      sub_401250(v7, 7);
      dword_425790(v10, v8);
      dword_425790(v9, v7);
      v12 = dword_425528(v10, 0x40000000, 0, 0, 2, 128, 0);
      if ( v12 != -1 )
      {
        v11 = dword_425528(v9, 0x40000000, 0, 0, 2, 128, 0);
        if ( v11 != -1 )
        {
          v6 = sub_406830(16 * dword_422689[-1]);
          if ( v6 != 0 )
          {
            v4 = sub_406DB0(dword_422689);
            if ( v4 != nullptr )
            {
              v1 = sub_418BA4(v4, v6);
              if ( v1 != -1 && dword_42552C(v12, v6, v1, v13, 0) != 0 )
              {
                sub_40684C((int)v4);
                v4 = nullptr;
                v5 = sub_406830(16 * dword_422810[-1]);
                if ( v5 != 0 )
                {
                  v4 = sub_406DB0(dword_422810);
                  if ( v4 != nullptr )
                  {
                    v2 = sub_418BA4(v4, v5);
                    if ( v2 != -1 && dword_42552C(v11, v5, v2, v13, 0) != 0 )
                      v14 = 1;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( v4 != nullptr )
    sub_40684C((int)v4);
  if ( v6 != 0 )
    sub_40684C(v6);
  if ( v5 != 0 )
    sub_40684C(v5);
  if ( v10 != 0 )
    sub_40684C(v10);
  if ( v9 != 0 )
    sub_40684C(v9);
  if ( v12 != -1 )
    dword_4254D0(v12);
  if ( v11 != -1 )
    dword_4254D0(v11);
  return v14;
}


/* sub_4159E0 @ 004159E0 */
int __stdcall sub_4159E0(int a1)
{
  int v1; // ebx
  int *v2; // esi
  int v3; // ebx
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v8; // [esp-58h] [ebp-90h]
  int v9; // [esp-54h] [ebp-8Ch]
  int v10; // [esp-50h] [ebp-88h]
  int v11; // [esp-4Ch] [ebp-84h]
  int v12; // [esp-48h] [ebp-80h]
  int v13; // [esp+Ch] [ebp-2Ch]
  void *v14; // [esp+10h] [ebp-28h]
  int v15; // [esp+14h] [ebp-24h]
  int v16; // [esp+18h] [ebp-20h]
  int v17; // [esp+1Ch] [ebp-1Ch]
  int *v18; // [esp+20h] [ebp-18h]
  int *v19; // [esp+24h] [ebp-14h]
  int v20; // [esp+28h] [ebp-10h]
  _BYTE v21[4]; // [esp+2Ch] [ebp-Ch] BYREF
  int v22; // [esp+30h] [ebp-8h]
  int v23; // [esp+34h] [ebp-4h]

  v23 = 0;
  v22 = -1;
  v17 = 0;
  v20 = 0;
  v19 = nullptr;
  v18 = nullptr;
  v16 = 0;
  v15 = 0;
  v14 = nullptr;
  v13 = sub_406830(2048);
  if ( v13 != 0 && (*(int (__cdecl **)(int, int, int, int))(*(_DWORD *)a1 + 56))(a1, 2, v13, 1024) == 0 )
  {
    v19 = sub_4148D8();
    if ( v19 != nullptr )
    {
      dword_425790(v13, v19);
      dword_425574(v13, 0);
      v18 = sub_41498C(0);
      if ( v18 != nullptr )
      {
        dword_425790(v13, v18);
        sub_40684C((int)v18);
        dword_425574(v13, 0);
        v18 = sub_41498C(1);
        if ( v18 != nullptr )
        {
          dword_425790(v13, v18);
          v22 = dword_425528(v13, 0x40000000, 0, 0, 4, 128, 0);
          if ( v22 != -1 )
          {
            v20 = sub_414A04();
            if ( v20 != 0 )
            {
              v17 = sub_414B64(23);
              if ( v17 != 0 )
              {
                v1 = 16 * dword_422974[-1];
                v16 = sub_406830(v1);
                if ( v16 != 0 )
                {
                  v14 = sub_406DB0(dword_422974);
                  if ( v14 != nullptr && sub_418BA4(v14, v16) != -1 )
                  {
                    v15 = sub_406830(v1);
                    if ( v15 != 0 )
                    {
                      v2 = (int *)v17;
                      v3 = 23;
                      v4 = 0;
                      do
                      {
                        v8 = *(_DWORD *)(v17 + v4);
                        v4 += 4;
                        --v3;
                      }
                      while ( v3 != 0 );
                      v5 = dword_425468(v15, v16, v20, v8, v9, v10, v11, v12);
                      if ( dword_42552C(v22, v15, v5, v21, 0) != 0 )
                      {
                        while ( 1 )
                        {
                          v6 = *v2++;
                          if ( v6 == 0 )
                            break;
                          sub_40684C(v6);
                        }
                        v23 = 1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( v17 != 0 )
    sub_40684C(v17);
  if ( v20 != 0 )
    sub_40684C(v20);
  if ( v18 != nullptr )
    sub_40684C((int)v18);
  if ( v19 != nullptr )
    sub_40684C((int)v19);
  if ( v15 != 0 )
    sub_40684C(v15);
  if ( v16 != 0 )
    sub_40684C(v16);
  if ( v13 != 0 )
    sub_40684C(v13);
  if ( v14 != nullptr )
    sub_40684C((int)v14);
  if ( v22 != -1 )
    dword_4254D0(v22);
  return v23;
}


/* sub_415C84 @ 00415C84 */
int __stdcall sub_415C84(int a1)
{
  int v1; // eax
  int v3[13]; // [esp+0h] [ebp-CCh] BYREF
  int v4[11]; // [esp+34h] [ebp-98h] BYREF
  int v5[7]; // [esp+60h] [ebp-6Ch] BYREF
  int v6[4]; // [esp+7Ch] [ebp-50h] BYREF
  int v7[4]; // [esp+8Ch] [ebp-40h] BYREF
  int v8; // [esp+9Ch] [ebp-30h]
  int v9; // [esp+A0h] [ebp-2Ch]
  int v10; // [esp+A4h] [ebp-28h]
  int v11; // [esp+A8h] [ebp-24h]
  void *v12; // [esp+ACh] [ebp-20h]
  void *v13; // [esp+B0h] [ebp-1Ch]
  int v14; // [esp+B4h] [ebp-18h] BYREF
  int v15; // [esp+B8h] [ebp-14h]
  int v16; // [esp+BCh] [ebp-10h]
  int v17; // [esp+C0h] [ebp-Ch]
  int v18; // [esp+C4h] [ebp-8h] BYREF
  int v19; // [esp+C8h] [ebp-4h]

  v19 = 0;
  v18 = 0;
  v11 = 0;
  v10 = 0;
  v9 = 0;
  v8 = 0;
  v13 = nullptr;
  v12 = nullptr;
  v7[0] = 1249777384;
  v7[1] = -1506624211;
  v7[2] = -671185773;
  v7[3] = -460726604;
  sub_401250(v7, 4);
  if ( dword_425800(a1, v7, &v18) == 0 )
  {
    v3[0] = -1213448097;
    v3[1] = -1213120389;
    v3[2] = -1214300071;
    v3[3] = -1214955440;
    v3[4] = -1214693290;
    v3[5] = -1216069507;
    v3[6] = -1214693300;
    v3[7] = -1215348650;
    v3[8] = -1215086511;
    v3[9] = -1213054890;
    v3[10] = -1215217575;
    v3[11] = -1215348643;
    v3[12] = -1208205256;
    sub_401250(v3, 13);
    v12 = sub_406DB0(dword_422D8D);
    if ( v12 != nullptr )
    {
      dword_4257A0(&v14);
      v14 = 8;
      v16 = dword_4257A8(v12);
      if ( v16 != 0 )
      {
        v11 = v16;
        v10 = dword_4257A8(v3);
        if ( (*(int (__stdcall **)(int, int, int, int, int, int))(*(_DWORD *)v18 + 64))(v18, v10, v14, v15, v16, v17) == 0 )
        {
          dword_4257A4(&v14);
          v4[0] = -1213448097;
          v4[1] = -1213644677;
          v4[2] = -1214693301;
          v4[3] = -1212596150;
          v4[4] = -1215807424;
          v4[5] = -1215152035;
          v4[6] = -1214955445;
          v4[7] = -1215152041;
          v4[8] = -1214431114;
          v4[9] = -1214693291;
          v4[10] = -1208205237;
          sub_401250(v4, 11);
          v13 = sub_406DB0(dword_422B67);
          if ( v13 != nullptr )
          {
            dword_4257A0(&v14);
            v14 = 8;
            v16 = dword_4257A8(v13);
            if ( v16 != 0 )
            {
              v9 = v16;
              v8 = dword_4257A8(v4);
              if ( (*(int (__stdcall **)(int, int, int, int, int, int))(*(_DWORD *)v18 + 64))(
                     v18,
                     v8,
                     v14,
                     v15,
                     v16,
                     v17) == 0 )
              {
                dword_4257A4(&v14);
                v5[0] = -1214693298;
                v5[1] = -1215348662;
                v5[2] = -1215086511;
                v5[3] = -1213054890;
                v5[4] = -1215217587;
                v5[5] = -1214693286;
                v5[6] = -1208205238;
                sub_401250(v5, 7);
                v6[0] = -1211482102;
                v6[1] = -1211285494;
                v6[2] = -1211809792;
                v6[3] = -1208205302;
                sub_401250(v6, 4);
                dword_4257A0(&v14);
                v14 = 8;
                v16 = dword_4257A8(v6);
                v1 = dword_4257A8(v5);
                if ( (*(int (__stdcall **)(int, int, int, int, int, int))(*(_DWORD *)v18 + 64))(
                       v18,
                       v1,
                       v14,
                       v15,
                       v16,
                       v17) == 0
                  && (*(int (__stdcall **)(int))(*(_DWORD *)v18 + 56))(v18) == 0 )
                {
                  v19 = 1;
                }
              }
            }
          }
        }
      }
    }
  }
  if ( v11 != 0 )
    dword_4257AC(v11);
  if ( v10 != 0 )
    dword_4257AC(v10);
  if ( v9 != 0 )
    dword_4257AC(v9);
  if ( v8 != 0 )
    dword_4257AC(v8);
  if ( v18 != 0 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v18 + 8))(v18);
  if ( v13 != nullptr )
    sub_40684C((int)v13);
  if ( v12 != nullptr )
    sub_40684C((int)v12);
  return v19;
}


/* sub_416004 @ 00416004 */
int __stdcall sub_416004(int a1, int *a2, int *a3)
{
  _WORD *v3; // eax
  int v4; // eax
  int v5; // eax
  _BYTE v7[520]; // [esp+0h] [ebp-20Ch] BYREF
  int v8; // [esp+208h] [ebp-4h]

  v8 = 0;
  dword_425444(v7, a1);
  v3 = (_WORD *)dword_425450(v7, 46);
  if ( v3 != nullptr )
  {
    *v3 = 0;
    v4 = sub_4068FC((int)(v3 + 1), 0);
    if ( v4 != 0 )
    {
      *a3 = v4;
      v5 = sub_4068FC((int)v7, 0);
      if ( v5 != 0 )
      {
        *a2 = v5;
        return 1;
      }
    }
  }
  return v8;
}


/* sub_416080 @ 00416080 */
int __stdcall sub_416080(int a1, int a2, int a3, int *a4)
{
  int result; // eax
  int v5; // ebx
  int v6; // ebx
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // ebx
  int v11; // ebx
  int v12; // eax
  int v13; // ebx
  int v14[24]; // [esp+4h] [ebp-CCh] BYREF
  int v15[11]; // [esp+64h] [ebp-6Ch] BYREF
  int v16[10]; // [esp+90h] [ebp-40h] BYREF
  int v17; // [esp+B8h] [ebp-18h]
  int v18; // [esp+BCh] [ebp-14h] BYREF
  int v19; // [esp+C0h] [ebp-10h] BYREF
  int v20; // [esp+C4h] [ebp-Ch]
  int v21; // [esp+C8h] [ebp-8h]
  int v22; // [esp+CCh] [ebp-4h]

  v22 = 0;
  v21 = 0;
  v20 = 0;
  v19 = 0;
  v18 = 0;
  v17 = 0;
  result = sub_416004(a2, &v19, &v18);
  if ( result != 0 )
  {
    v5 = dword_42543C(v19);
    v6 = dword_42543C(v18) + v5;
    v7 = dword_42543C(a2);
    result = sub_406830(2 * (v7 + v6) + 32);
    v17 = result;
    if ( result != 0 )
    {
      v15[0] = -1212661644;
      v15[1] = -1213448071;
      v15[2] = -1210892286;
      v15[3] = -1210499049;
      v15[4] = -1210892213;
      v15[5] = -1212202884;
      v15[6] = -1210499067;
      v15[7] = -1211088821;
      v15[8] = -1212202884;
      v15[9] = -1210499067;
      v15[10] = -1208205237;
      sub_401250(v15, 11);
      dword_425464(v17, v15, a2, v19);
      result = (*(int (__stdcall **)(int, int, int, _DWORD))(*(_DWORD *)a1 + 12))(a1, v17, a3, 0);
      if ( result == 0 )
      {
        result = sub_406830(78);
        v20 = result;
        if ( result != 0 )
        {
          result = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)a1 + 36))(a1, v20, 78);
          if ( result == 0 )
          {
            v8 = dword_42543C(v19);
            v9 = dword_42543C(v18);
            result = sub_406830(2 * (v9 + v8) + 30);
            v21 = result;
            if ( result != 0 )
            {
              v16[0] = -1212661644;
              v16[1] = -1213448071;
              v16[2] = -1210892286;
              v16[3] = -1212661737;
              v16[4] = -1212071813;
              v16[5] = -1215348707;
              v16[6] = -1212661740;
              v16[7] = -1212071813;
              v16[8] = -1215348707;
              v16[9] = -1208205256;
              sub_401250(v16, 10);
              dword_425464(v21, v16, v19, v18);
              v10 = dword_42543C(v20);
              v11 = dword_42543C(v19) + v10;
              v12 = dword_42543C(v18);
              result = sub_406830(2 * (v12 + v11) + 82);
              v13 = result;
              if ( result != 0 )
              {
                v14[0] = -1212661644;
                v14[1] = -1213448071;
                v14[2] = -1210892286;
                v14[3] = -1212202985;
                v14[4] = -1212071818;
                v14[5] = -1215348707;
                v14[6] = -1212202988;
                v14[7] = -1212071818;
                v14[8] = -1215086488;
                v14[9] = -1214955436;
                v14[10] = -1214955429;
                v14[11] = -1215348643;
                v14[12] = -1212202988;
                v14[13] = -1212071818;
                v14[14] = -1216003989;
                v14[15] = -1215807413;
                v14[16] = -1215217571;
                v14[17] = -1212661740;
                v14[18] = -1212071813;
                v14[19] = -1215348707;
                v14[20] = -1212661740;
                v14[21] = -1212071813;
                v14[22] = -1215348707;
                v14[23] = -1208205256;
                sub_401250(v14, 24);
                dword_425464(v13, v14, v20, v19);
                if ( dword_425870(v13, v21, 1) != 0 )
                {
                  result = sub_40684C(v13);
                }
                else
                {
                  result = (int)a4;
                  *a4 = v13;
                  v22 = 1;
                }
              }
            }
          }
        }
      }
    }
  }
  if ( v21 != 0 )
    result = sub_40684C(v21);
  if ( v20 != 0 )
    result = sub_40684C(v20);
  if ( v19 != 0 )
    result = sub_40684C(v19);
  if ( v18 != 0 )
    result = sub_40684C(v18);
  if ( v17 != 0 )
    return sub_40684C(v17);
  return result;
}


/* sub_4163EC @ 004163EC */
int __stdcall sub_4163EC(__int16 *a1)
{
  int v2[4]; // [esp+0h] [ebp-234h] BYREF
  int v3[4]; // [esp+10h] [ebp-224h] BYREF
  _BYTE v4[520]; // [esp+20h] [ebp-214h] BYREF
  int v5; // [esp+228h] [ebp-Ch] BYREF
  int v6; // [esp+22Ch] [ebp-8h] BYREF
  int v7; // [esp+230h] [ebp-4h]

  v7 = 0;
  v6 = 0;
  v5 = 0;
  if ( dword_425744(0) == 0 )
  {
    if ( sub_4125D0((int)v4) != 0 )
    {
      v3[0] = 1571579675;
      v3[1] = -1506942459;
      v3[2] = -1208183905;
      v3[3] = 1418540480;
      sub_401250(v3, 4);
      v2[0] = 1571579674;
      v2[1] = -1506942459;
      v2[2] = -1208183905;
      v2[3] = 1418540480;
      sub_401250(v2, 4);
      if ( dword_425758(v2, 0, 1, v3, &v6) == 0
        && sub_416080(v6, (int)v4, (int)a1, &v5) != 0
        && sub_415C84(v5) != 0
        && sub_414BBC(v6) != 0
        && sub_4159E0(v6) != 0
        && sub_415710(v6) != 0
        && sub_414DAC(v6) != 0
        && sub_41503C(v6, a1, (int)v4) != 0 )
      {
        v7 = 1;
      }
    }
    if ( v6 != 0 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6);
    dword_42574C();
  }
  if ( v5 != 0 )
    sub_40684C(v5);
  return v7;
}


/* sub_416558 @ 00416558 */
BOOL __stdcall sub_416558(int a1)
{
  int v2; // [esp+0h] [ebp-10h] BYREF
  int v3; // [esp+4h] [ebp-Ch] BYREF
  int v4; // [esp+8h] [ebp-8h]
  int v5; // [esp+Ch] [ebp-4h]

  v5 = 0;
  v4 = dword_425528(a1, -1073741824, 3, 0, 3, 128, 0);
  if ( v4 == -1 )
    return __readfsdword(0x34u) != 2;
  v2 = -1;
  if ( dword_42552C(v4, &v2, 4, &v3, 0) != 0 && v3 == 4 )
    dword_425534(v4);
  dword_4254D0(v4);
  return true;
}


/* sub_4165E4 @ 004165E4 */
int __stdcall sub_4165E4(__int16 *a1, int a2, int a3)
{
  int *v4; // edi
  __int16 v5; // ax
  _DWORD *i; // edi
  int v8; // [esp+0h] [ebp-75Ch]
  int v9; // [esp+4h] [ebp-758h] BYREF
  int v10; // [esp+8h] [ebp-754h] BYREF
  _BYTE v11[256]; // [esp+20Ch] [ebp-550h] BYREF
  _BYTE v12[256]; // [esp+30Ch] [ebp-450h] BYREF
  _BYTE v13[256]; // [esp+40Ch] [ebp-350h] BYREF
  _BYTE v14[272]; // [esp+50Ch] [ebp-250h] BYREF
  _BYTE v15[80]; // [esp+61Ch] [ebp-140h] BYREF
  int v16[14]; // [esp+66Ch] [ebp-F0h] BYREF
  int v17[11]; // [esp+6A4h] [ebp-B8h] BYREF
  int v18[7]; // [esp+6D0h] [ebp-8Ch] BYREF
  int v19[5]; // [esp+6ECh] [ebp-70h] BYREF
  int v20[3]; // [esp+700h] [ebp-5Ch] BYREF
  int v21[4]; // [esp+70Ch] [ebp-50h] BYREF
  _DWORD *v22; // [esp+71Ch] [ebp-40h]
  void *v23; // [esp+720h] [ebp-3Ch]
  _BYTE v24[4]; // [esp+724h] [ebp-38h] BYREF
  int v25; // [esp+728h] [ebp-34h]
  _DWORD v26[3]; // [esp+72Ch] [ebp-30h] BYREF
  _BYTE v27[2]; // [esp+738h] [ebp-24h] BYREF
  __int16 v28; // [esp+73Ah] [ebp-22h]
  int v29; // [esp+73Ch] [ebp-20h]
  int v30; // [esp+740h] [ebp-1Ch]
  int v31; // [esp+744h] [ebp-18h]
  int v32; // [esp+748h] [ebp-14h]
  int v33; // [esp+74Ch] [ebp-10h]
  int v34; // [esp+750h] [ebp-Ch]
  int v35; // [esp+754h] [ebp-8h]
  int v36; // [esp+758h] [ebp-4h]

  v36 = 0;
  v23 = nullptr;
  v22 = nullptr;
  v34 = 0;
  v35 = 0;
  v33 = -1;
  v9 = 6029404;
  v4 = &v10;
  do
  {
    v5 = *a1++;
    *(_WORD *)v4 = v5;
    v4 = (int *)((char *)v4 + 2);
  }
  while ( v5 != 0 );
  *(int *)((char *)v4 - 2) = 92;
  dword_42545C(&v9);
  v21[0] = -1212661639;
  v21[1] = -1212858251;
  v21[2] = -1210564490;
  v21[3] = -1208205256;
  sub_401250(v21, 4);
  if ( sub_412DD0((int)&v9, (int)v21, 1) != 0 )
  {
    v20[0] = -1213448079;
    v20[1] = -1210564485;
    v20[2] = -1208205256;
    sub_401250(v20, 3);
    if ( sub_412DD0((int)&v9, (int)v20, 1) != 0 )
    {
      v19[0] = -1215348707;
      v19[1] = -1214955448;
      v19[2] = -1214693304;
      v19[3] = -1210498972;
      v19[4] = -1208205237;
      sub_401250(v19, 5);
      sub_412C1C((int)&v9, (int)v15);
      dword_425464(v11, v19, &v9, v15);
      if ( sub_416558((int)v11) )
      {
        if ( a3 == 0 )
          sub_4127A8((int)v11, (int)&a3, 4);
      }
      else
      {
        v23 = sub_406DB0(dword_42304F);
        if ( v23 != nullptr )
        {
          v22 = (_DWORD *)sub_406830(4 * dword_42304F[-1]);
          if ( v22 != nullptr )
          {
            v25 = sub_418BA4(v23, v22);
            if ( v25 != -1 )
            {
              v18[0] = -1215348707;
              v18[1] = -1212661639;
              v18[2] = -1212858251;
              v18[3] = -1210564490;
              v18[4] = -1213710236;
              v18[5] = -1215217571;
              v18[6] = -1208205240;
              sub_401250(v18, 7);
              ((void (__cdecl *)(_BYTE *, int *, int *))dword_425464)(v12, v18, &v9);
              dword_425574(v12, 0);
              v17[0] = -1215348707;
              v17[1] = -1212661639;
              v17[2] = -1212858251;
              v17[3] = -1210564490;
              v17[4] = -1213710236;
              v17[5] = -1215217571;
              v17[6] = -1214234552;
              v17[7] = -1215348707;
              v17[8] = -1214693354;
              v17[9] = -1214693312;
              v17[10] = -1208205256;
              sub_401250(v17, 11);
              dword_425464(v13, v17, &v9, v15);
              v27[0] = 1;
              v27[1] = 0;
              v28 = 4;
              v29 = 0;
              v30 = 0;
              v31 = 0;
              v32 = 0;
              v26[0] = 12;
              v26[1] = v27;
              v26[2] = 1;
              v33 = dword_425528(v13, 0x40000000, 0, v26, 1, 128, 0);
              if ( v33 != -1 )
              {
                for ( i = v22;
                      *i != 2359332 || i[1] != 2359332 || i[2] != 2359332 || i[3] != 2359332;
                      i = (_DWORD *)((char *)i + 1) )
                {
                  ;
                }
                dword_425444(i, a2);
                if ( dword_42552C(v33, v22, v25, v24, 0) != 0 )
                {
                  dword_4254D0(v33);
                  v33 = -1;
                  v16[0] = -1210499043;
                  v16[1] = -1216003989;
                  v16[2] = -1215807413;
                  v16[3] = -1215217571;
                  v16[4] = -1215086486;
                  v16[5] = -1215807401;
                  v16[6] = -1210499043;
                  v16[7] = -1213710236;
                  v16[8] = -1215217571;
                  v16[9] = -1214234552;
                  v16[10] = -1215348707;
                  v16[11] = -1214693354;
                  v16[12] = -1214693312;
                  v16[13] = -1208205256;
                  sub_401250(v16, 14);
                  dword_425464(v14, v16, v15, v8);
                  v35 = dword_425624(&v9, 0, 983103);
                  if ( v35 != 0 )
                  {
                    v34 = dword_42562C(v35, v15, 983551);
                    if ( v34 == 0 )
                      v34 = dword_425630(v35, v15, v15, 983551, 272, 3, 1, v14, 0, 0, 0, 0, 0);
                    if ( v34 != 0 )
                    {
                      if ( dword_425634(v34, 0, 0) != 0 )
                      {
                        sub_4127A8((int)v11, (int)&a3, 4);
                        v36 = 1;
                      }
                      else
                      {
                        dword_425644(v34);
                        dword_425570(v13);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( v34 != 0 )
    dword_425648(v34);
  if ( v35 != 0 )
    dword_425648(v35);
  sub_412DD0((int)&v9, (int)v21, 0);
  sub_412DD0((int)&v9, (int)v20, 0);
  if ( v33 != -1 )
    dword_4254D0(v33);
  if ( v23 != nullptr )
    sub_40684C((int)v23);
  if ( v22 != nullptr )
    sub_40684C((int)v22);
  return v36;
}


/* sub_416B18 @ 00416B18 */
void __stdcall sub_416B18(unsigned __int16 a1)
{
  int v1; // eax
  int v2[5]; // [esp+4h] [ebp-450h] BYREF
  int v3[4]; // [esp+18h] [ebp-43Ch] BYREF
  int v4[4]; // [esp+28h] [ebp-42Ch] BYREF
  _BYTE v5[520]; // [esp+38h] [ebp-41Ch] BYREF
  __int16 v6[260]; // [esp+240h] [ebp-214h] BYREF
  int v7; // [esp+448h] [ebp-Ch]
  int v8; // [esp+44Ch] [ebp-8h]
  int v9; // [esp+450h] [ebp-4h] BYREF

  if ( a1 != 0 )
  {
    v9 = 0;
    v7 = 0;
    v8 = sub_4138B0();
    if ( v8 != 0 && sub_413920(v8, (int)v5) != 0 && dword_425744(0) == 0 )
    {
      v4[0] = 1571579675;
      v4[1] = -1506942459;
      v4[2] = -1208183905;
      v4[3] = 1418540480;
      sub_401250(v4, 4);
      v3[0] = 1571579674;
      v3[1] = -1506942459;
      v3[2] = -1208183905;
      v3[3] = 1418540480;
      sub_401250(v3, 4);
      if ( dword_425758(v3, 0, 1, v4, &v9) == 0 )
      {
        v1 = dword_42543C(v5);
        v7 = sub_406830(2 * v1 + 16);
        if ( v7 != 0 )
        {
          v2[0] = -1212661644;
          v2[1] = -1213448071;
          v2[2] = -1210892286;
          v2[3] = -1210499049;
          v2[4] = -1208205237;
          sub_401250(v2, 5);
          ((void (__cdecl *)(int, int *, _BYTE *))dword_425464)(v7, v2, v5);
          if ( (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v9 + 16))(v9, v7, 0) == 0
            && (*(int (__stdcall **)(int, __int16 *, int))(*(_DWORD *)v9 + 76))(v9, v6, 260) == 0 )
          {
            if ( a1 == 0xFFFF )
              sub_4165E4(v6, v8, 0);
            else
              sub_4165E4(v6, v8, 60000 * a1);
          }
        }
      }
      if ( v9 != 0 )
        (*(void (__stdcall **)(int))(*(_DWORD *)v9 + 8))(v9);
      dword_42574C();
    }
    if ( v7 != 0 )
      sub_40684C(v7);
    if ( v8 != 0 )
      sub_40684C(v8);
  }
}


/* sub_416D04 @ 00416D04 */
void *__stdcall sub_416D04(int a1, int a2, int a3, int a4)
{
  int v4; // ebx
  __int16 *v5; // esi
  __int16 *v6; // edi
  int i; // ecx
  _WORD *v8; // edi
  int *v9; // edi
  int *v10; // edi
  void *result; // eax
  __int16 v12; // [esp+Ch] [ebp-67Ch] BYREF
  __int16 v13; // [esp+Eh] [ebp-67Ah] BYREF
  _BYTE v14[520]; // [esp+41Ch] [ebp-26Ch] BYREF
  _DWORD v15[4]; // [esp+624h] [ebp-64h] BYREF
  _DWORD v16[17]; // [esp+634h] [ebp-54h] BYREF
  int v17; // [esp+678h] [ebp-10h] BYREF
  int v18; // [esp+67Ch] [ebp-Ch]
  int v19; // [esp+680h] [ebp-8h]
  int v20; // [esp+684h] [ebp-4h]

  v20 = 0;
  v18 = 0;
  v19 = 0;
  v4 = sub_40165C();
  dword_425444(v14, v4);
  dword_425784(v14);
  v5 = (__int16 *)v4;
  v12 = 34;
  v6 = &v13;
  for ( i = dword_42543C(v4); i != 0; --i )
    *v6++ = *v5++;
  *v6 = 34;
  v8 = v6 + 1;
  *v8 = 32;
  v9 = (int *)(v8 + 1);
  *v9 = -1214562283;
  v9[1] = -1214693284;
  v9[2] = -1208205228;
  sub_401250(v9, 3);
  if ( dword_4251A8 != 0 )
  {
    v10 = (int *)((char *)v9 + 10);
    *(_WORD *)v10 = 32;
    v10 = (int *)((char *)v10 + 2);
    *v10 = -1215545323;
    v10[1] = -1215348647;
    v10[2] = -1208205237;
    sub_401250(v10, 3);
    v10 = (int *)((char *)v10 + 10);
    *(_WORD *)v10 = 32;
    dword_425674(&unk_4251AC, 72, 0);
    dword_425444((char *)v10 + 2, &unk_4251AC);
    dword_425670(&unk_4251AC, 72, 0);
  }
  dword_425690(&v17, a1, 1);
  dword_425428(v15, 0, 16);
  dword_425428(v16, 0, 68);
  v16[0] = 68;
  result = sub_406DB0((_DWORD *)(a2 + 4));
  v20 = (int)result;
  if ( result != nullptr )
  {
    result = sub_406DB0((_DWORD *)(a4 + 4));
    v19 = (int)result;
    if ( result != nullptr )
    {
      result = sub_406DB0((_DWORD *)(a3 + 4));
      v18 = (int)result;
      if ( result != nullptr )
      {
        result = (void *)dword_425688(v20, v18, v19, 1, v4, &v12, 1056, v17, v14, v16, v15);
        if ( result != nullptr )
        {
          dword_425548(v15[0], -1);
          dword_4254D0(v15[1]);
          dword_4254D0(v15[0]);
          result = (void *)dword_425694(v17);
        }
      }
    }
  }
  if ( v20 != 0 )
    result = (void *)sub_40684C(v20);
  if ( v18 != 0 )
    result = (void *)sub_40684C(v18);
  if ( v19 != 0 )
    return (void *)sub_40684C(v19);
  return result;
}


/* sub_416EFC @ 00416EFC */
int __usercall sub_416EFC@<eax>(int a1@<edi>)
{
  int result; // eax
  __int16 *v2; // [esp+0h] [ebp-4h]

  result = sub_4138B0();
  v2 = (__int16 *)result;
  if ( result != 0 )
  {
    result = sub_412620(result, (int)word_425BC0, 520);
    if ( result != 0 )
    {
      sub_401228(word_425BC0, word_425BC0);
      if ( sub_413920((int)v2, 0) == 0 )
        sub_4163EC(v2);
      result = sub_413DFC((int)v2, 1);
      if ( result == 0 )
      {
        sub_414464(a1);
        if ( byte_425133 != 0 )
          sub_414604();
        result = sub_413DFC((int)v2, 0);
      }
    }
  }
  if ( v2 != nullptr )
    return sub_40684C((int)v2);
  return result;
}


/* sub_416F90 @ 00416F90 */
void __usercall sub_416F90(int a1@<edi>, int a2@<esi>)
{
  int v2; // ebx
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // ebx
  int v10; // ebx
  int v11; // ecx
  int v12; // eax
  int v13; // [esp+4h] [ebp-24h]
  int v14; // [esp+8h] [ebp-20h]
  int v15; // [esp+Ch] [ebp-1Ch]
  int v16; // [esp+10h] [ebp-18h]
  int v17; // [esp+14h] [ebp-14h]
  int v18; // [esp+18h] [ebp-10h]
  int v19; // [esp+1Ch] [ebp-Ch]
  int v20; // [esp+20h] [ebp-8h]
  int v21; // [esp+24h] [ebp-4h] BYREF

  v20 = 0;
  v19 = 0;
  if ( dword_4256C4(67) == 0 )
  {
    if ( byte_42512D != 0 )
    {
      v20 = dword_42551C(0, 0, sub_40D7E8, 0, 0, 0);
      v13 = dword_425590();
      v16 = sub_406AB0();
    }
    if ( byte_425131 != 0 && dword_425168 != 0 )
    {
      v2 = sub_409C34(dword_425168, dword_42515C, dword_425160, dword_425164, 0);
      dword_425548(v2, -1);
      dword_4254D0(v2);
    }
    if ( byte_425132 != 0 && dword_425168 != 0 )
    {
      v3 = sub_409C34(dword_425168, dword_42515C, dword_425160, dword_425164, 1);
      dword_425548(v3, -1);
      dword_4254D0(v3);
    }
  }
  if ( byte_42512F != 0 )
  {
    v4 = dword_42551C(0, 0, sub_408F38, 0, 0, 0);
    v5 = v4;
    if ( v4 != 0 )
    {
      dword_425548(v4, -1);
      dword_4254D0(v5);
    }
  }
  v18 = dword_42551C(0, 0, sub_407438, 0, 0, 0);
  v17 = dword_42551C(0, 0, sub_4077FC, 0, 0, 0);
  if ( byte_425128 != 0 )
    sub_407C74();
  if ( byte_425127 != 0 )
    v19 = dword_42551C(0, 0, sub_407E28, 0, 0, 0);
  if ( byte_425125 != 0 || byte_425126 != 0 )
  {
    dword_425480(-2147483647, &v21);
    sub_40B690();
    v14 = sub_40E144();
    if ( v14 != 0 )
    {
      if ( byte_425125 != 0 )
      {
        sub_40A65C();
        sub_40E214();
        sub_410994();
        sub_40E214();
        sub_410B40();
      }
      if ( byte_425126 != 0 )
      {
        sub_40E214();
        sub_40FBE4(a1);
      }
      sub_40E1CC(v14);
      sub_40E214();
    }
    dword_425480(v21, &v21);
  }
  if ( v18 != 0 )
  {
    dword_425548(v18, -1);
    dword_4254D0(v18);
  }
  if ( v17 != 0 )
  {
    dword_425548(v17, -1);
    dword_4254D0(v17);
  }
  if ( byte_425127 != 0 )
  {
    dword_4254CC(v19, 0);
    dword_4254D0(v19);
  }
  if ( byte_425135 != 0 )
  {
    v6 = dword_42551C(0, 0, sub_4095F8, 0, 0, 0);
    v7 = v6;
    if ( v6 != 0 )
    {
      dword_425548(v6, -1);
      dword_4254D0(v7);
    }
  }
  if ( dword_4256C4(67) != 0 )
  {
    sub_411890();
    sub_411C84(0);
    sub_411608(0);
  }
  else
  {
    if ( byte_42512A != 0 )
    {
      v8 = dword_42551C(0, 0, sub_40BFC0, 0, 0, 0);
      v9 = v8;
      if ( v8 != 0 )
      {
        dword_425548(v8, -1);
        dword_4254D0(v9);
      }
    }
    if ( byte_42512D != 0 )
    {
      if ( v20 != 0 )
      {
        dword_425548(v20, -1);
        dword_4254D0(v20);
      }
      v10 = dword_425590() - v13;
      v15 = sub_406AB0();
      sub_40D95C(v11, v10, a1, a2, v16, v15, v10);
    }
    if ( sub_40B5D0() )
      sub_408930();
    else
      sub_408200(1);
    if ( byte_425134 != 0 || byte_425130 != 0 || byte_42512E != 0 )
    {
      v12 = sub_409610();
      sub_410410(v12, (unsigned __int8)byte_425134, (unsigned __int8)byte_425130, (unsigned __int8)byte_42512E);
    }
  }
}


/* sub_417308 @ 00417308 */
unsigned int *sub_417308()
{
  unsigned int *result; // eax
  unsigned int *v1; // ebx
  int v2; // eax

  sub_411B44();
  sub_408200(1);
  dword_425738(0x8000000, 4096, 0, 0);
  result = (unsigned int *)sub_40B5D0();
  if ( result == nullptr )
  {
    if ( byte_42512A != 0 )
    {
      result = (unsigned int *)dword_42551C(0, 0, sub_40BFC0, 0, 0, 0);
      v1 = result;
      if ( result != nullptr )
      {
        dword_425548(result, -1);
        result = (unsigned int *)dword_4254D0(v1);
      }
    }
    if ( byte_425134 != 0 || byte_425130 != 0 || byte_42512E != 0 )
    {
      v2 = sub_409610();
      return sub_410410(v2, (unsigned __int8)byte_425134, (unsigned __int8)byte_425130, (unsigned __int8)byte_42512E);
    }
  }
  return result;
}


/* sub_4173B4 @ 004173B4 */
int sub_4173B4()
{
  int v0; // eax
  int result; // eax
  _DWORD *v2; // ebx
  int *v3; // ebx
  _DWORD *v4; // ebx
  int v5; // [esp+20h] [ebp-28h]
  int v6; // [esp+24h] [ebp-24h]
  int v7; // [esp+28h] [ebp-20h]
  int v8; // [esp+2Ch] [ebp-1Ch]
  int v9; // [esp+30h] [ebp-18h]
  int v10; // [esp+34h] [ebp-14h]
  int v11; // [esp+38h] [ebp-10h]
  int v12; // [esp+3Ch] [ebp-Ch]
  int v13; // [esp+40h] [ebp-8h]
  unsigned int v14; // [esp+44h] [ebp-4h] BYREF

  v12 = 0;
  v11 = 0;
  v10 = 0;
  dword_4251A8 = 0;
  v9 = 0;
  v8 = 0;
  v7 = 0;
  v6 = 0;
  v0 = sub_401650();
  result = dword_42572C(v0, &v14);
  v13 = result;
  if ( result == 0 )
    goto LABEL_45;
  if ( v14 <= 1 )
    goto LABEL_3;
  v2 = (_DWORD *)(result + 4);
  --v14;
  do
  {
    result = sub_4011D4(*v2, 0);
    switch ( result )
    {
      case 1162288407:
        v3 = v2 + 1;
        v5 = *v3;
        v12 = 1;
        v2 = v3 + 1;
        --v14;
        --v14;
        break;
      case 1168055511:
        v4 = v2 + 1;
        dword_425444(&unk_4251AC, *v4);
        dword_425670(&unk_4251AC, 72, 0);
        result = dword_425428(*v4, 0, 66);
        dword_4251A8 = 1;
        v2 = v4 + 1;
        --v14;
        --v14;
        break;
      case 1160726935:
        v11 = 1;
        ++v2;
        --v14;
        break;
      default:
        switch ( result )
        {
          case 1164413719:
            v10 = 1;
            ++v2;
            break;
          case 1764133911:
            v9 = 1;
            ++v2;
            break;
          case 1774655831:
            v8 = 1;
            ++v2;
            break;
          case -882710208:
            v7 = 1;
            ++v2;
            break;
          case 1265011031:
            v6 = 1;
            ++v2;
            break;
          default:
            break;
        }
        --v14;
        break;
    }
  }
  while ( v14 != 0 );
  if ( v12 != 0 )
  {
    result = sub_411FB8(v5);
  }
  else if ( v11 != 0 )
  {
    sub_409B80();
    result = sub_411E50();
  }
  else if ( v10 != 0 )
  {
    result = sub_417308();
  }
  else if ( v9 != 0 )
  {
    sub_416EFC();
    result = sub_416B18(word_425136);
  }
  else if ( v8 != 0 )
  {
    result = sub_413868();
  }
  else if ( v7 != 0 )
  {
    if ( byte_425132 != 0 && dword_425168 != 0 )
      result = sub_416D04(dword_425168, dword_42515C, dword_425160, dword_425164);
    if ( byte_42512E != 0 )
      result = sub_410410(0, 0, 0, (unsigned __int8)byte_42512E);
  }
  else if ( v6 != 0 )
  {
    result = sub_416B18(-1);
  }
  else
  {
    if ( sub_40A308(dword_42516C, *(_DWORD *)(v13 + 4)) == -1 && sub_40A308(dword_425168, *(_DWORD *)(v13 + 4)) == -1 )
    {
LABEL_3:
      sub_409B80();
      result = sub_416F90();
      goto LABEL_45;
    }
    result = sub_412384(*(_DWORD *)(v13 + 4));
  }
LABEL_45:
  if ( v13 != 0 )
    return dword_4255E4(v13);
  return result;
}


/* sub_417694 @ 00417694 */
int __stdcall sub_417694(int a1, int (__stdcall *a2)(int, int, int))
{
  char *v2; // esi
  int v3; // eax
  _BYTE *v4; // edi
  int v5; // ecx
  char v6; // al
  int v7; // edi
  int v8; // eax
  int v9; // esi
  int v10; // esi
  int v12; // [esp-8h] [ebp-1Ch]
  int v13; // [esp+10h] [ebp-4h]

  v13 = 0;
  v2 = (char *)dword_424DBF;
  v3 = sub_406830(dword_424DBF[-1]);
  v4 = (_BYTE *)v3;
  if ( v3 != 0 )
  {
    v12 = v3;
    v5 = dword_424DBF[-1];
    do
    {
      v6 = *v2++;
      *v4++ = v6 ^ 0x30;
      --v5;
    }
    while ( v5 != 0 );
    v7 = v12;
    v8 = a2(a1, 8, 2 * dword_424DBF[-1]);
    v9 = v8;
    if ( v8 != 0 )
    {
      sub_418BA4(v7, v8);
      v10 = v9 + 131;
      dword_42519C = (int (__stdcall *)(_DWORD, _DWORD))sub_417754(v10, a1, a2);
      v10 += 65;
      dword_425194 = sub_417754(v10, a1, a2);
      dword_425198 = sub_417754(v10 + 215, a1, a2);
      v13 = 1;
    }
    sub_40684C(v7);
  }
  return v13;
}


/* sub_417754 @ 00417754 */
int __stdcall sub_417754(int a1, int a2, int (__stdcall *a3)(int, _DWORD, int))
{
  unsigned int v3; // eax
  int v4; // edx
  char v5; // al
  char v6; // al
  char v7; // al
  char v8; // al

  *(_BYTE *)a3(a2, 0, 16) = -72;
  v3 = sub_401124(0, 4u);
  if ( v3 != 0 )
  {
    switch ( v3 )
    {
      case 1u:
        v6 = sub_401124(1u, 9u);
        *(_DWORD *)(v4 + 1) = __ROR4__(a1, v6);
        *(_WORD *)(v4 + 5) = -16191;
        *(_BYTE *)(v4 + 7) = v6;
        *(_WORD *)(v4 + 8) = -7937;
        break;
      case 2u:
        *(_DWORD *)(v4 + 1) = a1 ^ 0x4803BFC7;
        *(_BYTE *)(v4 + 5) = 53;
        *(_DWORD *)(v4 + 6) = 1208205255;
        *(_WORD *)(v4 + 10) = -7937;
        break;
      case 3u:
        v7 = sub_401124(1u, 9u);
        *(_DWORD *)(v4 + 1) = __ROL4__(a1 ^ 0x4803BFC7, v7);
        *(_WORD *)(v4 + 5) = -14143;
        *(_BYTE *)(v4 + 7) = v7;
        *(_BYTE *)(v4 + 8) = 53;
        *(_DWORD *)(v4 + 9) = 1208205255;
        *(_WORD *)(v4 + 13) = -7937;
        break;
      case 4u:
        v8 = sub_401124(1u, 9u);
        *(_DWORD *)(v4 + 1) = __ROR4__(a1 ^ 0x4803BFC7, v8);
        *(_WORD *)(v4 + 5) = -16191;
        *(_BYTE *)(v4 + 7) = v8;
        *(_BYTE *)(v4 + 8) = 53;
        *(_DWORD *)(v4 + 9) = 1208205255;
        *(_WORD *)(v4 + 13) = -7937;
        break;
      default:
        break;
    }
  }
  else
  {
    v5 = sub_401124(1u, 9u);
    *(_DWORD *)(v4 + 1) = __ROL4__(a1, v5);
    *(_WORD *)(v4 + 5) = -14143;
    *(_BYTE *)(v4 + 7) = v5;
    *(_WORD *)(v4 + 8) = -7937;
  }
  return v4;
}


/* BitBlt @ 0041785A */
// attributes: thunk
BOOL __stdcall BitBlt(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1, int y1, DWORD rop)
{
  return __imp_BitBlt(hdc, x, y, cx, cy, hdcSrc, x1, y1, rop);
}


/* CreateDIBitmap @ 00417860 */
// attributes: thunk
HBITMAP __stdcall CreateDIBitmap(
        HDC hdc,
        const BITMAPINFOHEADER *pbmih,
        DWORD flInit,
        const void *pjBits,
        const BITMAPINFO *pbmi,
        UINT iUsage)
{
  return __imp_CreateDIBitmap(hdc, pbmih, flInit, pjBits, pbmi, iUsage);
}


/* CreateFontW @ 00417866 */
// attributes: thunk
HFONT __stdcall CreateFontW(
        int cHeight,
        int cWidth,
        int cEscapement,
        int cOrientation,
        int cWeight,
        DWORD bItalic,
        DWORD bUnderline,
        DWORD bStrikeOut,
        DWORD iCharSet,
        DWORD iOutPrecision,
        DWORD iClipPrecision,
        DWORD iQuality,
        DWORD iPitchAndFamily,
        LPCWSTR pszFaceName)
{
  return __imp_CreateFontW(
           cHeight,
           cWidth,
           cEscapement,
           cOrientation,
           cWeight,
           bItalic,
           bUnderline,
           bStrikeOut,
           iCharSet,
           iOutPrecision,
           iClipPrecision,
           iQuality,
           iPitchAndFamily,
           pszFaceName);
}


/* CreateSolidBrush @ 0041786C */
// attributes: thunk
HBRUSH __stdcall CreateSolidBrush(COLORREF color)
{
  return __imp_CreateSolidBrush(color);
}


/* GetDeviceCaps @ 00417872 */
// attributes: thunk
int __stdcall GetDeviceCaps(HDC hdc, int index)
{
  return __imp_GetDeviceCaps(hdc, index);
}


/* GetPixel @ 00417878 */
// attributes: thunk
COLORREF __stdcall GetPixel(HDC hdc, int x, int y)
{
  return __imp_GetPixel(hdc, x, y);
}


/* GetTextColor @ 0041787E */
// attributes: thunk
COLORREF __stdcall GetTextColor(HDC hdc)
{
  return __imp_GetTextColor(hdc);
}


/* SelectObject @ 00417884 */
// attributes: thunk
HGDIOBJ __stdcall SelectObject(HDC hdc, HGDIOBJ h)
{
  return __imp_SelectObject(hdc, h);
}


/* SelectPalette @ 0041788A */
// attributes: thunk
HPALETTE __stdcall SelectPalette(HDC hdc, HPALETTE hPal, BOOL bForceBkgd)
{
  return __imp_SelectPalette(hdc, hPal, bForceBkgd);
}


/* SetPixel @ 00417890 */
// attributes: thunk
COLORREF __stdcall SetPixel(HDC hdc, int x, int y, COLORREF color)
{
  return __imp_SetPixel(hdc, x, y, color);
}


/* sub_4178EC @ 004178EC */
char __thiscall sub_4178EC(_DWORD *this)
{
  int v2; // eax
  _BYTE *v3; // ecx
  char result; // al

  if ( (*(this + 3))-- == 1 )
  {
    v2 = *(this + 1);
    *(this + 2) = v2;
    *(this + 3) = 8;
    *(this + 1) = v2 + 1;
  }
  v3 = (_BYTE *)*(this + 2);
  result = 2 * *v3 + 1;
  *v3 = result;
  return result;
}


/* sub_41792B @ 0041792B */
_BYTE *__thiscall sub_41792B(int this, unsigned int a2)
{
  unsigned int v2; // eax
  unsigned int v3; // edx
  int v4; // esi
  int v5; // edi
  int i; // esi
  bool v7; // zf
  int v8; // eax
  _BYTE *v9; // eax
  int v10; // eax
  int v11; // eax
  _BYTE *result; // eax
  int v13; // eax

  v2 = a2;
  v3 = a2;
  v4 = 0;
  do
  {
    v5 = v2 & 1;
    v2 >>= 1;
    ++v4;
    v3 = v5 + 2 * v3;
  }
  while ( v2 > 1 );
  for ( i = v4 - 1; i != 0; **(_BYTE **)(this + 8) = 2 * **(_BYTE **)(this + 8) + 1 )
  {
    v7 = (*(_DWORD *)(this + 12))-- == 1;
    if ( v7 )
    {
      v8 = *(_DWORD *)(this + 4);
      *(_DWORD *)(this + 8) = v8;
      *(_DWORD *)(this + 12) = 8;
      *(_DWORD *)(this + 4) = v8 + 1;
    }
    v9 = *(_BYTE **)(this + 8);
    if ( (v3 & 1) != 0 )
      *v9 = 2 * *v9 + 1;
    else
      *v9 *= 2;
    v7 = (*(_DWORD *)(this + 12))-- == 1;
    if ( v7 )
    {
      v10 = *(_DWORD *)(this + 4);
      *(_DWORD *)(this + 8) = v10;
      *(_DWORD *)(this + 12) = 8;
      *(_DWORD *)(this + 4) = v10 + 1;
    }
    v3 >>= 1;
    --i;
  }
  v7 = (*(_DWORD *)(this + 12))-- == 1;
  if ( v7 )
  {
    v11 = *(_DWORD *)(this + 4);
    *(_DWORD *)(this + 8) = v11;
    *(_DWORD *)(this + 12) = 8;
    *(_DWORD *)(this + 4) = v11 + 1;
  }
  result = *(_BYTE **)(this + 8);
  if ( (v3 & 1) != 0 )
    *result = 2 * *result + 1;
  else
    *result *= 2;
  v7 = (*(_DWORD *)(this + 12))-- == 1;
  if ( v7 )
  {
    v13 = *(_DWORD *)(this + 4);
    *(_DWORD *)(this + 8) = v13;
    result = (_BYTE *)(v13 + 1);
    *(_DWORD *)(this + 12) = 8;
    *(_DWORD *)(this + 4) = result;
  }
  **(_BYTE **)(this + 8) *= 2;
  return result;
}


/* sub_4179E7 @ 004179E7 */
int __cdecl sub_4179E7(_BYTE *a1, unsigned int a2, int a3)
{
  int v3; // ebp
  int result; // eax
  _BYTE *v5; // edi
  _BYTE *v6; // esi
  int v7; // ecx
  _BYTE *v8; // edx

  v3 = a2;
  result = 0;
  if ( a2 > 0xF )
    v3 = 15;
  v5 = a1;
  v6 = &a1[-v3];
  do
  {
    if ( *v5 != 0 )
    {
      v7 = v3;
      v8 = v6;
      do
      {
        if ( *v8 == *v5 )
          break;
        ++v8;
        --v7;
      }
      while ( v7 != 0 );
      result += 2 * (v7 == 0) + 7;
    }
    else
    {
      result += 7;
    }
    ++v5;
    ++v6;
    --a3;
  }
  while ( a3 != 0 );
  return result;
}


/* sub_417A3C @ 00417A3C */
char __thiscall sub_417A3C(_DWORD *this, _BYTE *a2, unsigned int a3)
{
  int v3; // esi
  _BYTE *v4; // eax
  bool v5; // zf
  int v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _BYTE *v12; // eax
  int v13; // eax
  _BYTE *v14; // eax
  int v15; // eax
  int v16; // eax
  _BYTE *v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax

  *(this + 266) = 0;
  if ( *a2 != 0 )
  {
    v3 = a3;
    if ( a3 > 0xF )
    {
      v3 = 15;
      a3 = 15;
    }
    v4 = &a2[-v3];
    while ( *v4 != *a2 )
    {
      ++v4;
      if ( --a3 == 0 )
        goto LABEL_7;
    }
    if ( a3 == 0 )
    {
LABEL_7:
      v5 = (*(this + 3))-- == 1;
      if ( v5 )
      {
        v6 = *(this + 1);
        *(this + 2) = v6;
        *(this + 3) = 8;
        *(this + 1) = v6 + 1;
      }
      *(_BYTE *)*(this + 2) *= 2;
      LOBYTE(v7) = *a2;
      *(_BYTE *)(*(this + 1))++ = *a2;
      return (char)v7;
    }
    v5 = (*(this + 3))-- == 1;
    if ( v5 )
    {
      v8 = *(this + 1);
      *(this + 2) = v8;
      *(this + 3) = 8;
      *(this + 1) = v8 + 1;
    }
    *(_BYTE *)*(this + 2) = 2 * *(_BYTE *)*(this + 2) + 1;
    v5 = (*(this + 3))-- == 1;
    if ( v5 )
    {
      v9 = *(this + 1);
      *(this + 2) = v9;
      *(this + 3) = 8;
      *(this + 1) = v9 + 1;
    }
    *(_BYTE *)*(this + 2) = 2 * *(_BYTE *)*(this + 2) + 1;
    v5 = (*(this + 3))-- == 1;
    if ( v5 )
    {
      v10 = *(this + 1);
      *(this + 2) = v10;
      *(this + 3) = 8;
      *(this + 1) = v10 + 1;
    }
    *(_BYTE *)*(this + 2) = 2 * *(_BYTE *)*(this + 2) + 1;
    v5 = (*(this + 3))-- == 1;
    if ( v5 )
    {
      v11 = *(this + 1);
      *(this + 2) = v11;
      *(this + 3) = 8;
      *(this + 1) = v11 + 1;
    }
    v12 = (_BYTE *)*(this + 2);
    if ( (a3 & 8) != 0 )
      *v12 = 2 * *v12 + 1;
    else
      *v12 *= 2;
    v5 = (*(this + 3))-- == 1;
    if ( v5 )
    {
      v13 = *(this + 1);
      *(this + 2) = v13;
      *(this + 3) = 8;
      *(this + 1) = v13 + 1;
    }
    v14 = (_BYTE *)*(this + 2);
    if ( (a3 & 4) != 0 )
      *v14 = 2 * *v14 + 1;
    else
      *v14 *= 2;
    v5 = (*(this + 3))-- == 1;
    if ( v5 )
    {
      v15 = *(this + 1);
      *(this + 2) = v15;
      *(this + 3) = 8;
      *(this + 1) = v15 + 1;
    }
    v7 = (_BYTE *)*(this + 2);
    if ( (a3 & 2) != 0 )
      *v7 = 2 * *v7 + 1;
    else
      *v7 *= 2;
    v5 = (*(this + 3))-- == 1;
    if ( v5 )
    {
      v16 = *(this + 1);
      *(this + 2) = v16;
      v7 = (_BYTE *)(v16 + 1);
      *(this + 3) = 8;
      *(this + 1) = v7;
    }
    v17 = (_BYTE *)*(this + 2);
    if ( (a3 & 1) != 0 )
    {
      LOBYTE(v7) = 2 * *v17 + 1;
      *v17 = (_BYTE)v7;
      return (char)v7;
    }
  }
  else
  {
    v5 = (*(this + 3))-- == 1;
    if ( v5 )
    {
      v18 = *(this + 1);
      *(this + 2) = v18;
      *(this + 3) = 8;
      *(this + 1) = v18 + 1;
    }
    *(_BYTE *)*(this + 2) = 2 * *(_BYTE *)*(this + 2) + 1;
    v5 = (*(this + 3))-- == 1;
    if ( v5 )
    {
      v19 = *(this + 1);
      *(this + 2) = v19;
      *(this + 3) = 8;
      *(this + 1) = v19 + 1;
    }
    *(_BYTE *)*(this + 2) = 2 * *(_BYTE *)*(this + 2) + 1;
    v5 = (*(this + 3))-- == 1;
    if ( v5 )
    {
      v20 = *(this + 1);
      *(this + 2) = v20;
      *(this + 3) = 8;
      *(this + 1) = v20 + 1;
    }
    *(_BYTE *)*(this + 2) = 2 * *(_BYTE *)*(this + 2) + 1;
    v5 = (*(this + 3))-- == 1;
    if ( v5 )
    {
      v21 = *(this + 1);
      *(this + 2) = v21;
      *(this + 3) = 8;
      *(this + 1) = v21 + 1;
    }
    *(_BYTE *)*(this + 2) *= 2;
    v5 = (*(this + 3))-- == 1;
    if ( v5 )
    {
      v22 = *(this + 1);
      *(this + 2) = v22;
      *(this + 3) = 8;
      *(this + 1) = v22 + 1;
    }
    *(_BYTE *)*(this + 2) *= 2;
    v5 = (*(this + 3))-- == 1;
    if ( v5 )
    {
      v23 = *(this + 1);
      *(this + 2) = v23;
      *(this + 3) = 8;
      *(this + 1) = v23 + 1;
    }
    v7 = (_BYTE *)*(this + 2);
    *v7 *= 2;
    v5 = (*(this + 3))-- == 1;
    if ( v5 )
    {
      v24 = *(this + 1);
      *(this + 2) = v24;
      v7 = (_BYTE *)(v24 + 1);
      *(this + 3) = 8;
      *(this + 1) = v7;
    }
    v17 = (_BYTE *)*(this + 2);
  }
  *v17 *= 2;
  return (char)v7;
}


/* sub_417C72 @ 00417C72 */
int __thiscall sub_417C72(_DWORD *this, unsigned int a2, int a3)
{
  int v3; // edx
  unsigned int v5; // eax
  int v6; // ecx
  unsigned int i; // eax
  int v8; // eax
  unsigned int j; // edx
  int v10; // eax
  unsigned int k; // edx

  v3 = a3;
  if ( a2 < 0x80 && (unsigned int)a3 < 4 )
  {
    if ( a2 != *(this + 265) )
      return a2 != 0 ? 11 : 5;
  }
  else if ( a2 != *(this + 265) )
  {
    if ( a2 >= 0x80 )
    {
      if ( a2 >= 0x500 )
      {
        v3 = a3 - 1;
        if ( a2 >= 0x7D00 )
          v3 = a3 - 2;
      }
    }
    else
    {
      v3 = a3 - 2;
    }
    v5 = (a2 >> 8) + 3;
    if ( v5 >= 2 )
    {
      v6 = 0;
      for ( i = v5 >> 1; i != 0; i >>= 1 )
        v6 += 2;
    }
    else
    {
      v6 = 100;
    }
    if ( v3 < 2 )
      return v6 + 110;
    v8 = 0;
    for ( j = (unsigned int)v3 >> 1; j != 0; j >>= 1 )
      v8 += 2;
    return v6 + v8 + 10;
  }
  if ( a3 < 2 )
    return 104;
  v10 = 0;
  for ( k = (unsigned int)a3 >> 1; k != 0; k >>= 1 )
    v10 += 2;
  return v10 + 4;
}


/* sub_417D26 @ 00417D26 */
unsigned __int8 __thiscall sub_417D26(_DWORD *this, unsigned int a2, unsigned int a3)
{
  bool v4; // zf
  int v5; // eax
  int v6; // eax
  int v7; // eax
  unsigned __int8 result; // al
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax

  if ( *(this + 266) != 0 )
  {
    if ( a2 < 0x80 && a3 < 4 )
    {
      v4 = (*(this + 3))-- == 1;
      if ( v4 )
      {
        v5 = *(this + 1);
        *(this + 2) = v5;
        *(this + 3) = 8;
        *(this + 1) = v5 + 1;
      }
      *(_BYTE *)*(this + 2) = 2 * *(_BYTE *)*(this + 2) + 1;
      v4 = (*(this + 3))-- == 1;
      if ( v4 )
      {
        v6 = *(this + 1);
        *(this + 2) = v6;
        *(this + 3) = 8;
        *(this + 1) = v6 + 1;
      }
      *(_BYTE *)*(this + 2) = 2 * *(_BYTE *)*(this + 2) + 1;
      v4 = (*(this + 3))-- == 1;
      if ( v4 )
      {
        v7 = *(this + 1);
        *(this + 2) = v7;
        *(this + 3) = 8;
        *(this + 1) = v7 + 1;
      }
      *(_BYTE *)*(this + 2) *= 2;
      *(_BYTE *)(*(this + 1))++ = (2 * a2) | a3 & 1;
      *(this + 265) = a2;
      return 2 * a2;
    }
    v4 = (*(this + 3))-- == 1;
    if ( v4 )
    {
      v9 = *(this + 1);
      *(this + 2) = v9;
      *(this + 3) = 8;
      *(this + 1) = v9 + 1;
    }
    *(_BYTE *)*(this + 2) = 2 * *(_BYTE *)*(this + 2) + 1;
    v4 = (*(this + 3))-- == 1;
    if ( v4 )
    {
      v10 = *(this + 1);
      *(this + 2) = v10;
      *(this + 3) = 8;
      *(this + 1) = v10 + 1;
    }
    *(_BYTE *)*(this + 2) *= 2;
    sub_41792B((int)this, (a2 >> 8) + 2);
    *(_BYTE *)(*(this + 1))++ = a2;
    *(this + 265) = a2;
    if ( a2 < 0x80 )
      return (unsigned __int8)sub_41792B((int)this, a3 - 2);
    if ( a2 >= 0x500 )
    {
      --a3;
      if ( a2 >= 0x7D00 )
        --a3;
    }
    return (unsigned __int8)sub_41792B((int)this, a3);
  }
  *(this + 266) = 1;
  if ( a2 >= 0x80 || a3 >= 4 || a2 == *(this + 265) )
  {
    v4 = (*(this + 3))-- == 1;
    if ( v4 )
    {
      v12 = *(this + 1);
      *(this + 2) = v12;
      *(this + 3) = 8;
      *(this + 1) = v12 + 1;
    }
    *(_BYTE *)*(this + 2) = 2 * *(_BYTE *)*(this + 2) + 1;
    v4 = (*(this + 3))-- == 1;
    if ( v4 )
    {
      v13 = *(this + 1);
      *(this + 2) = v13;
      *(this + 3) = 8;
      *(this + 1) = v13 + 1;
    }
    *(_BYTE *)*(this + 2) *= 2;
    if ( a2 == *(this + 265) )
    {
      v4 = (*(this + 3))-- == 1;
      if ( v4 )
      {
        v14 = *(this + 1);
        *(this + 2) = v14;
        *(this + 3) = 8;
        *(this + 1) = v14 + 1;
      }
      *(_BYTE *)*(this + 2) *= 2;
      v4 = (*(this + 3))-- == 1;
      if ( v4 )
      {
        v15 = *(this + 1);
        *(this + 2) = v15;
        *(this + 3) = 8;
        *(this + 1) = v15 + 1;
      }
      *(_BYTE *)*(this + 2) *= 2;
    }
    else
    {
      sub_41792B((int)this, (a2 >> 8) + 3);
      *(_BYTE *)(*(this + 1))++ = a2;
      *(this + 265) = a2;
      if ( a2 < 0x80 )
        return (unsigned __int8)sub_41792B((int)this, a3 - 2);
      if ( a2 >= 0x500 )
      {
        --a3;
        if ( a2 >= 0x7D00 )
          return (unsigned __int8)sub_41792B((int)this, a3 - 1);
      }
    }
    return (unsigned __int8)sub_41792B((int)this, a3);
  }
  sub_4178EC(this);
  sub_4178EC(this);
  v4 = (*(this + 3))-- == 1;
  if ( v4 )
  {
    v11 = *(this + 1);
    *(this + 2) = v11;
    *(this + 3) = 8;
    *(this + 1) = v11 + 1;
  }
  *(_BYTE *)*(this + 2) *= 2;
  result = (2 * a2) | a3 & 1;
  *(_BYTE *)(*(this + 1))++ = result;
  *(this + 265) = a2;
  return result;
}


/* sub_417FF3 @ 00417FF3 */
unsigned int *__thiscall sub_417FF3(int this, unsigned int *a2, unsigned __int8 *a3, unsigned int a4, unsigned int a5)
{
  unsigned __int8 *v5; // ebp
  unsigned int v7; // eax
  unsigned int v8; // ecx
  int v9; // eax
  unsigned int v10; // edi
  int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // eax
  int v14; // edi
  unsigned int v15; // ecx
  unsigned int v16; // ebx
  bool v17; // zf
  _BYTE *v18; // ecx
  int v19; // ebp
  int v20; // edx
  int v21; // ebp
  int v22; // ecx
  unsigned int v23; // eax
  int v24; // edi
  unsigned int v26; // [esp+10h] [ebp-10h]
  unsigned int v27; // [esp+14h] [ebp-Ch]
  unsigned int v28; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v5 = a3;
  v26 = 0;
  v27 = 0;
  while ( *(_DWORD *)(this + 1048) < (unsigned int)a3 )
  {
    v7 = *(_DWORD *)(this + 1044);
    if ( v7 + 92160 < v7 )
    {
      v9 = 0;
    }
    else
    {
      v8 = *(_DWORD *)(this + 1052);
      if ( v7 <= v8 )
        v9 = v7 - v8 + 92160;
      else
        v9 = v7 - v8;
    }
    *(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v9) = *(_DWORD *)(*(_DWORD *)(this
                                                                         + 4 * **(unsigned __int8 **)(this + 1048)
                                                                         + 20)
                                                             + 4 * *(unsigned __int8 *)(*(_DWORD *)(this + 1048) + 1));
    *(_DWORD *)(*(_DWORD *)(this + 4 * **(unsigned __int8 **)(this + 1048) + 20)
              + 4 * *(unsigned __int8 *)++*(_DWORD *)(this + 1048)) = (*(_DWORD *)(this + 1044))++;
    if ( (unsigned int)(*(_DWORD *)(this + 1044) - *(_DWORD *)(this + 1052)) > 0x16800 )
      *(_DWORD *)(this + 1052) = *(_DWORD *)(this + 1044) - 1;
  }
  if ( a5 <= 0x16700 )
  {
    if ( a5 <= 1 )
      goto LABEL_50;
  }
  else
  {
    a5 = 91904;
  }
  v10 = *(_DWORD *)(*(_DWORD *)(this + 4 * *a3 + 20) + 4 * a3[1]);
  if ( v10 != 0 )
  {
    v11 = *(_DWORD *)(this + 1056);
    v12 = v10 + v11;
    for ( i = 2048; v10 + v11 >= (unsigned int)a3; v12 = v10 + v11 )
    {
      if ( v10 == 0 )
        break;
      if ( v10 + 92160 <= *(_DWORD *)(this + 1044) )
      {
        v14 = 0;
      }
      else
      {
        v13 = *(_DWORD *)(this + 1052);
        v14 = v10 <= v13 ? v10 - v13 + 92160 : v10 - v13;
      }
      v10 = *(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v14);
    }
    if ( a4 > 0x16700 )
      a4 = 91904;
    if ( v10 != 0 )
    {
      do
      {
        v28 = (unsigned int)&v5[-v12];
        if ( (unsigned int)&v5[-v12] > a4 )
          break;
        v15 = (unsigned int)&v5[-v12];
        v16 = 2;
        if ( *(_BYTE *)(v26 + v12) == v5[v26] || v28 == *(_DWORD *)(this + 1060) )
        {
          v17 = a5 == 2;
          if ( a5 > 2 )
          {
            v18 = v5 + 2;
            do
            {
              if ( v18[v12 - (_DWORD)a3] != *v18 )
                break;
              ++v16;
              ++v18;
            }
            while ( v16 < a5 );
            v15 = (unsigned int)&v5[-v12];
            v5 = a3;
            v17 = v16 == a5;
          }
          if ( v17 )
          {
            v27 = v15;
            v26 = v16;
            break;
          }
          if ( v16 <= v26 )
          {
            if ( v15 == *(_DWORD *)(this + 1060) )
            {
              v21 = sub_417C72((_DWORD *)this, v15, v16);
              v22 = sub_417C72((_DWORD *)this, v27, v26) - v21;
              v5 = a3;
              if ( v16 + v22 / 6 >= v26 )
              {
                v27 = v28;
                goto LABEL_40;
              }
            }
          }
          else
          {
            v19 = sub_417C72((_DWORD *)this, v15, v16);
            v20 = (unsigned __int64)(2643056798LL * (v19 - sub_417C72((_DWORD *)this, v27, v26))) >> 32;
            v5 = a3;
            if ( v16 > v26 + (v20 >> 2) + ((unsigned int)v20 >> 31) )
            {
              v27 = v28;
LABEL_40:
              v26 = v16;
            }
          }
        }
        if ( v10 + 92160 <= *(_DWORD *)(this + 1044) )
        {
          v24 = 0;
        }
        else
        {
          v23 = *(_DWORD *)(this + 1052);
          if ( v10 <= v23 )
            v24 = v10 - v23 + 92160;
          else
            v24 = v10 - v23;
        }
        v10 = *(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v24);
        v12 = v10 + *(_DWORD *)(this + 1056);
        --i;
      }
      while ( i != 0 && v10 != 0 );
    }
  }
LABEL_50:
  *a2 = v26;
  a2[1] = v27;
  return a2;
}


/* sub_4182BA @ 004182BA */
int sub_4182BA()
{
  return 655360;
}


/* sub_4182C0 @ 004182C0 */
int __cdecl sub_4182C0(unsigned int a1)
{
  return a1 + (a1 >> 3) + 64;
}


/* sub_4182CE @ 004182CE */
int __thiscall sub_4182CE(_DWORD *this, int *a2, int *a3, int a4)
{
  int v4; // ebp
  signed int v5; // edi
  signed int v7; // ebx
  int v8; // eax
  int v9; // esi
  int v10; // eax
  int result; // eax
  int v12; // [esp+10h] [ebp-4h]
  int v13; // [esp+18h] [ebp+4h]
  int v14; // [esp+1Ch] [ebp+8h]

  v4 = *a2;
  v5 = a2[1];
  v12 = sub_417C72(this, v5, *a2);
  v7 = a3[1];
  v14 = *a3;
  v8 = sub_417C72(this, v7, v14);
  v9 = v8;
  v13 = 0;
  if ( v7 < v5 )
    v10 = (v12 - v8) / 4;
  else
    v10 = 2 * (v12 - v8) / 9;
  if ( v4 < v14 + v10 )
    v13 = 1;
  if ( a4 == 0 )
    return v13;
  if ( v14 < v4 )
    return v13;
  result = 1;
  if ( v9 >= v12 )
    return v13;
  return result;
}


/* sub_41836A @ 0041836A */
int __thiscall sub_41836A(_DWORD *this, int *a2, int *a3, int a4)
{
  int v4; // ebp
  signed int v5; // edi
  signed int v7; // ebx
  int v8; // eax
  int v9; // esi
  int v10; // eax
  int result; // eax
  int v12; // [esp+10h] [ebp-4h]
  int v13; // [esp+18h] [ebp+4h]
  int v14; // [esp+1Ch] [ebp+8h]

  v4 = *a2;
  v5 = a2[1];
  v12 = sub_417C72(this, v5, *a2);
  v7 = a3[1];
  v14 = *a3;
  v8 = sub_417C72(this, v7, v14);
  v9 = v8;
  v13 = 0;
  if ( v7 < v5 )
    v10 = 2 * (v12 - v8) / 11;
  else
    v10 = (v12 - v8) / 4;
  if ( v4 < v14 + v10 )
    v13 = 1;
  if ( a4 == 0 )
    return v13;
  if ( v14 < v4 )
    return v13;
  result = 1;
  if ( v9 >= v12 )
    return v13;
  return result;
}


/* sub_418406 @ 00418406 */
int __thiscall sub_418406(
        _DWORD *this,
        int a2,
        int a3,
        unsigned int a4,
        int a5,
        int (__cdecl *a6)(unsigned int, int, int, int),
        int a7)
{
  _DWORD *v9; // ecx
  int v10; // edx
  unsigned int v11; // edi
  unsigned int v12; // ebp
  unsigned int i; // eax
  _BYTE *v14; // ecx
  _DWORD *v15; // edx
  _BYTE *v16; // ecx
  _BYTE *v17; // edx
  int v18; // eax
  int v19; // ebx
  unsigned int v20; // ebx
  int v21; // ebx
  int v22; // ebx
  bool v23; // cc
  unsigned int v24; // eax
  unsigned int v25; // ebx
  int v26; // ebx
  int v27; // ebx
  int v28; // ebx
  int v29; // ebx
  int v30; // eax
  int v31; // ebx
  int v32; // edx
  unsigned int v33; // eax
  unsigned int v34; // ebx
  int v35; // ebx
  int v36; // ebx
  int v37; // ebx
  int v38; // ebx
  int v39; // ebx
  bool v40; // zf
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // ecx
  _BYTE *v45; // eax
  int v46; // [esp+4h] [ebp-30h]
  int v47; // [esp+4h] [ebp-30h]
  int j; // [esp+4h] [ebp-30h]
  int v49; // [esp+8h] [ebp-2Ch]
  int v50; // [esp+Ch] [ebp-28h]
  int v51; // [esp+10h] [ebp-24h]
  int v52; // [esp+10h] [ebp-24h]
  int v53; // [esp+10h] [ebp-24h]
  int v54; // [esp+14h] [ebp-20h] BYREF
  int v55; // [esp+18h] [ebp-1Ch]
  int v56; // [esp+1Ch] [ebp-18h]
  int v57; // [esp+20h] [ebp-14h]
  unsigned int v58; // [esp+24h] [ebp-10h] BYREF
  int v59; // [esp+28h] [ebp-Ch]
  int v60; // [esp+2Ch] [ebp-8h] BYREF
  int v61; // [esp+30h] [ebp-4h]
  int v62; // [esp+44h] [ebp+10h]

  if ( a4 == 0 )
    return 0;
  if ( a2 == 0 || a3 == 0 || a5 == 0 )
    return -1;
  *this = a2;
  *(this + 264) = a2 - 1;
  *(this + 1) = a3;
  *(this + 4) = a5;
  v9 = this + 5;
  v10 = a5 + 368664;
  v11 = 256;
  v12 = 1;
  do
  {
    *v9 = v10;
    for ( i = 0; i < 0x400; i += 4 )
      *(_DWORD *)(*v9 + i) = 0;
    ++v9;
    v10 += 1024;
    --v11;
  }
  while ( v11 != 0 );
  v14 = (_BYTE *)*this;
  v15 = (_DWORD *)*(this + 4);
  *(this + 265) = -1;
  *(this + 262) = v14;
  *(this + 261) = 1;
  *(this + 263) = 0;
  *v15 = 0;
  v16 = (_BYTE *)*this;
  v17 = (_BYTE *)*(this + 1);
  *(this + 266) = 0;
  v50 = -1;
  *v17 = *v16;
  ++*(this + 1);
  ++*this;
  v62 = 0;
  v49 = 0;
  *(this + 3) = 1;
  if ( a4 - 1 <= 1 )
    goto LABEL_113;
  do
  {
    if ( a6 != nullptr && (++v49 & 0xFFF) == 0 && a6(a4, *this - a2, *(this + 1) - a3, a7) == 0 )
      return -1;
    if ( v12 == v50 )
    {
      v54 = v60;
      v55 = v61;
    }
    else
    {
      sub_417FF3(&v54, *this, v12, a4 - v12);
    }
    if ( v54 < 2 )
    {
      if ( v11 != 0 )
        ++v11;
      else
        sub_417A3C(*this, v12);
LABEL_78:
      ++*this;
      goto LABEL_79;
    }
    v18 = *(this + 265);
    if ( v55 != v18
      || v11 > 1
      && (v19 = v57, v57 != v18)
      && (v51 = sub_4179E7(v62, v12 - v11, v11), sub_417C72(v19, v11) < v51)
      && (v19 < 1280 || v11 != 2)
      && (v19 < 32000 || v11 != 3) )
    {
      v20 = a4 - v12;
      sub_417FF3(&v60, *this + 1, v12 + 1, a4 - v12 - 1);
      v50 = v12 + 1;
      v46 = sub_4182CE(&v54, &v60, v11);
      if ( v11 != 0
        || v60 >= v54
        || (v21 = sub_417C72(v61, v60),
            v22 = sub_4179E7(*this, v12, 1) + v21 + 1,
            v23 = v22 <= sub_417C72(v55, v54),
            v20 = a4 - v12,
            v23) )
      {
        if ( v46 != 0 )
          goto LABEL_72;
      }
      if ( v54 > 2 )
      {
        sub_417FF3(&v58, *this + 2, v12 + 2, v20 - 2);
        if ( sub_41836A(&v54, &v58, v11) != 0
          || v54 > 3 && (sub_417FF3(&v58, *this + 3, v12 + 3, v20 - 3), sub_41836A(&v54, &v58, v11) != 0) )
        {
LABEL_72:
          if ( v11 == 0 )
          {
            v32 = *this;
            v56 = v54;
            v57 = v55;
            v62 = v32;
          }
          ++v11;
          goto LABEL_78;
        }
      }
    }
    if ( v11 == 0 )
      goto LABEL_57;
    if ( v11 <= 1 )
    {
      sub_417A3C(v62, v12 - 1);
      goto LABEL_56;
    }
    v24 = a4 + v11 - v12;
    if ( v24 > v11 )
      v24 = v11;
    v25 = v12 - v11;
    sub_417FF3(&v58, v62, v12 - v11, v24);
    if ( v58 >= v11 )
    {
      v26 = sub_417C72(v59, v11);
      v23 = sub_417C72(v57, v11) <= v26;
      v25 = v12 - v11;
      if ( !v23 )
      {
        v57 = v59;
        v56 = v58;
      }
    }
    v52 = sub_4179E7(v62, v25, v11);
    v27 = sub_417C72(v57, v11);
    if ( v27 < v52 )
    {
      if ( v55 != *(this + 265) || (v47 = v27 + sub_417C72(v55 + 1, v54), v52 + sub_417C72(v55, v54) > v47) )
      {
        if ( v57 == *(this + 265) && *(this + 266) == 0 || (v57 < 1280 || v11 != 2) && (v57 < 32000 || v11 != 3) )
        {
          sub_417D26(v57, v11);
LABEL_56:
          v11 = 0;
          goto LABEL_57;
        }
      }
    }
    v28 = v62;
    do
      sub_417A3C(v28++, v12 - v11--);
    while ( v11 != 0 );
    v62 = v28;
LABEL_57:
    v29 = v54;
    if ( v54 > 3 )
    {
      v30 = v55;
LABEL_71:
      sub_417D26(v30, v29);
      *this += v29;
      v12 = v12 + v29 - 1;
      goto LABEL_79;
    }
    v53 = sub_4179E7(*this, v12, v54);
    if ( sub_417C72(v55, v29) > v53 )
    {
      v29 = v54;
    }
    else
    {
      v30 = v55;
      if ( v55 == *(this + 265) && *(this + 266) == 0 )
      {
        v31 = v54;
        sub_417D26(v55, v54);
        *this += v31;
        v12 = v12 + v31 - 1;
        goto LABEL_79;
      }
      v29 = v54;
      if ( (v55 < 1280 || v54 != 2) && v55 < 32000 )
        goto LABEL_71;
    }
    for ( j = v29; j != 0; --j )
    {
      sub_417A3C(*this, v12);
      ++*this;
    }
    v12 = v12 + v29 - 1;
LABEL_79:
    if ( v11 != 0 && v11 == v56 )
    {
      v33 = a4 + v11 - v12;
      if ( v33 > v11 )
        v33 = v11;
      v34 = v12 - v11;
      sub_417FF3(&v58, v62, v12 - v11, v33);
      if ( v58 >= v11 )
      {
        v35 = sub_417C72(v59, v11);
        v23 = sub_417C72(v57, v11) <= v35;
        v34 = v12 - v11;
        if ( !v23 )
        {
          v57 = v59;
          v56 = v58;
        }
      }
      v36 = sub_4179E7(v62, v34, v11);
      if ( sub_417C72(v57, v11) >= v36
        || (v57 != *(this + 265) || *(this + 266) != 0) && (v57 >= 1280 && v11 == 2 || v57 >= 32000 && v11 == 3) )
      {
        v37 = v62;
        do
          sub_417A3C(v37++, v12 - v11--);
        while ( v11 != 0 );
        v62 = v37;
      }
      else
      {
        sub_417D26(v57, v11);
        v11 = 0;
      }
    }
    ++v12;
  }
  while ( v12 < a4 - 1 );
  if ( v11 != 0 )
  {
    if ( v11 <= 1 )
    {
      sub_417A3C(v62, v12 - 1);
    }
    else
    {
      v38 = sub_4179E7(v62, v12 - v11, v11);
      if ( sub_417C72(v57, v11) > v38
        || (v57 != *(this + 265) || *(this + 266) != 0) && (v57 >= 1280 && v11 == 2 || v57 >= 32000 && v11 == 3) )
      {
        v39 = v62;
        do
          sub_417A3C(v39++, v12 - v11--);
        while ( v11 != 0 );
      }
      else
      {
        sub_417D26(v57, v11);
      }
    }
  }
LABEL_113:
  while ( v12 < a4 )
  {
    sub_417A3C(*this, v12);
    ++*this;
    ++v12;
  }
  v40 = (*(this + 3))-- == 1;
  if ( v40 )
  {
    v41 = *(this + 1);
    *(this + 2) = v41;
    *(this + 3) = 8;
    *(this + 1) = v41 + 1;
  }
  *(_BYTE *)*(this + 2) = 2 * *(_BYTE *)*(this + 2) + 1;
  v40 = (*(this + 3))-- == 1;
  if ( v40 )
  {
    v42 = *(this + 1);
    *(this + 2) = v42;
    *(this + 3) = 8;
    *(this + 1) = v42 + 1;
  }
  *(_BYTE *)*(this + 2) = 2 * *(_BYTE *)*(this + 2) + 1;
  v40 = (*(this + 3))-- == 1;
  if ( v40 )
  {
    v43 = *(this + 1);
    *(this + 2) = v43;
    *(this + 3) = 8;
    *(this + 1) = v43 + 1;
  }
  *(_BYTE *)*(this + 2) *= 2;
  *(_BYTE *)*(this + 1) = 0;
  v44 = *(this + 3);
  v45 = (_BYTE *)*(this + 2);
  ++*(this + 1);
  *v45 <<= v44 - 1;
  if ( a6 == nullptr || a6(a4, *this - a2, *(this + 1) - a3, a7) != 0 )
    return *(this + 1) - a3;
  else
    return -1;
}


/* sub_418B54 @ 00418B54 */
int __cdecl sub_418B54(int a1, int a2, unsigned int a3, int a4, int (__cdecl *a5)(unsigned int, int, int, int), int a6)
{
  int result; // eax
  _DWORD v7[267]; // [esp+0h] [ebp-42Ch] BYREF

  result = a3;
  if ( a3 != 0 )
    return sub_418406(v7, a1, a2, a3, a4, a5, a6);
  return result;
}


/* sub_418BA4 @ 00418BA4 */
void __usercall __spoils<ecx> sub_418BA4(unsigned int a1@<ebp>, char *a2, _BYTE *a3)
{
  char v5; // dl
  char v6; // al
  int i; // ebx
  bool v8; // cf
  char v9; // dl
  char v10; // tt
  bool v11; // cf
  char v12; // dl
  char v13; // tt
  unsigned int v14; // eax
  bool v15; // cf
  char v16; // dl
  char v17; // tt
  bool v18; // cf
  char v19; // dl
  char v20; // dl
  char v21; // tt
  BOOL v22; // eax
  bool v23; // cf
  char v24; // dl
  char v25; // dl
  char v26; // tt
  int v27; // eax
  bool v28; // cf
  char v29; // dl
  char v30; // dl
  char v31; // tt
  int v32; // eax
  bool v33; // cf
  char v34; // dl
  char v35; // tt
  int v36; // eax
  int v37; // eax
  bool v38; // cf
  char v39; // dl
  char v40; // dl
  char v41; // tt
  bool v42; // cf
  char v43; // dl
  char v44; // tt
  int v45; // eax
  unsigned int v46; // ecx
  bool v47; // cf
  char v48; // dl
  char v49; // dl
  char v50; // tt
  bool v51; // cf
  char v52; // dl
  char v53; // tt
  unsigned int v54; // eax
  int v55; // ecx
  bool v56; // cf
  char v57; // dl
  char v58; // dl
  char v59; // tt
  bool v60; // cf
  char v61; // dl
  char v62; // tt
  unsigned int v63; // ecx
  unsigned __int8 v64; // al
  char v65; // cf
  unsigned int v66; // ecx

  v5 = 0x80;
LABEL_2:
  v6 = *a2++;
  *a3++ = v6;
  for ( i = 2; ; i = 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v8 = __CFADD__(v5, v5);
        v5 *= 2;
        if ( v5 == 0 )
        {
          v9 = *a2++;
          v10 = v8 + v9;
          v8 = __CFADD__(v8, v9) | __CFADD__(v9, v8 + v9);
          v5 = v9 + v10;
        }
        if ( !v8 )
          goto LABEL_2;
        v11 = __CFADD__(v5, v5);
        v5 *= 2;
        if ( v5 == 0 )
        {
          v12 = *a2++;
          v13 = v11 + v12;
          v11 = __CFADD__(v11, v12) | __CFADD__(v12, v11 + v12);
          v5 = v12 + v13;
        }
        if ( v11 )
          break;
        v37 = 1;
        do
        {
          v38 = __CFADD__(v5, v5);
          v39 = 2 * v5;
          if ( v39 == 0 )
          {
            v40 = *a2++;
            v41 = v38 + v40;
            v38 = __CFADD__(v38, v40) | __CFADD__(v40, v38 + v40);
            v39 = v40 + v41;
          }
          v37 += v38 + v37;
          v42 = __CFADD__(v39, v39);
          v5 = 2 * v39;
          if ( v5 == 0 )
          {
            v43 = *a2++;
            v44 = v42 + v43;
            v42 = __CFADD__(v42, v43) | __CFADD__(v43, v42 + v43);
            v5 = v43 + v44;
          }
        }
        while ( v42 );
        v45 = v37 - i;
        i = 1;
        if ( v45 != 0 )
        {
          v54 = (v45 - 1) << 8;
          LOBYTE(v54) = *a2++;
          a1 = v54;
          v55 = 1;
          do
          {
            v56 = __CFADD__(v5, v5);
            v57 = 2 * v5;
            if ( v57 == 0 )
            {
              v58 = *a2++;
              v59 = v56 + v58;
              v56 = __CFADD__(v56, v58) | __CFADD__(v58, v56 + v58);
              v57 = v58 + v59;
            }
            v55 += v56 + v55;
            v60 = __CFADD__(v57, v57);
            v5 = 2 * v57;
            if ( v5 == 0 )
            {
              v61 = *a2++;
              v62 = v60 + v61;
              v60 = __CFADD__(v60, v61) | __CFADD__(v61, v60 + v61);
              v5 = v61 + v62;
            }
          }
          while ( v60 );
          v63 = (v54 < 0x80) + (v54 < 0x80) + v55 - ((v54 < 0x7D00) - 1) - ((v54 < 0x500) - 1);
          qmemcpy(a3, &a3[-v54], v63);
          a3 += v63;
        }
        else
        {
          v46 = 1;
          do
          {
            v47 = __CFADD__(v5, v5);
            v48 = 2 * v5;
            if ( v48 == 0 )
            {
              v49 = *a2++;
              v50 = v47 + v49;
              v47 = __CFADD__(v47, v49) | __CFADD__(v49, v47 + v49);
              v48 = v49 + v50;
            }
            v46 += v47 + v46;
            v51 = __CFADD__(v48, v48);
            v5 = 2 * v48;
            if ( v5 == 0 )
            {
              v52 = *a2++;
              v53 = v51 + v52;
              v51 = __CFADD__(v51, v52) | __CFADD__(v52, v51 + v52);
              v5 = v52 + v53;
            }
          }
          while ( v51 );
          qmemcpy(a3, &a3[-a1], v46);
          a3 += v46;
        }
      }
      v14 = 0;
      v15 = __CFADD__(v5, v5);
      v5 *= 2;
      if ( v5 == 0 )
      {
        v16 = *a2++;
        v17 = v15 + v16;
        v15 = __CFADD__(v15, v16) | __CFADD__(v16, v15 + v16);
        v5 = v16 + v17;
      }
      if ( !v15 )
        break;
      v18 = __CFADD__(v5, v5);
      v19 = 2 * v5;
      if ( v19 == 0 )
      {
        v20 = *a2++;
        v21 = v18 + v20;
        v18 = __CFADD__(v18, v20) | __CFADD__(v20, v18 + v20);
        v19 = v20 + v21;
      }
      v22 = v18;
      v23 = __CFADD__(v19, v19);
      v24 = 2 * v19;
      if ( v24 == 0 )
      {
        v25 = *a2++;
        v26 = v23 + v25;
        v23 = __CFADD__(v23, v25) | __CFADD__(v25, v23 + v25);
        v24 = v25 + v26;
      }
      v27 = v22 + v23 + v22;
      v28 = __CFADD__(v24, v24);
      v29 = 2 * v24;
      if ( v29 == 0 )
      {
        v30 = *a2++;
        v31 = v28 + v30;
        v28 = __CFADD__(v28, v30) | __CFADD__(v30, v28 + v30);
        v29 = v30 + v31;
      }
      v32 = v27 + v28 + v27;
      v33 = __CFADD__(v29, v29);
      v5 = 2 * v29;
      if ( v5 == 0 )
      {
        v34 = *a2++;
        v35 = v33 + v34;
        v33 = __CFADD__(v33, v34) | __CFADD__(v34, v33 + v34);
        v5 = v34 + v35;
      }
      v36 = v32 + v33 + v32;
      if ( v36 != 0 )
        LOBYTE(v36) = a3[-v36];
      *a3++ = v36;
      i = 2;
    }
    v64 = *a2++;
    v65 = v64 & 1;
    LOBYTE(v14) = v64 >> 1;
    if ( (_BYTE)v14 == 0 )
      break;
    v66 = v65 + 2;
    a1 = v14;
    qmemcpy(a3, &a3[-v14], v66);
    a3 += v66;
  }
}


/* CreateDialogParamW @ 00418CEC */
// attributes: thunk
HWND __stdcall CreateDialogParamW(
        HINSTANCE hInstance,
        LPCWSTR lpTemplateName,
        HWND hWndParent,
        DLGPROC lpDialogFunc,
        LPARAM dwInitParam)
{
  return __imp_CreateDialogParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam);
}


/* CreateWindowExW @ 00418CF2 */
// attributes: thunk
HWND __stdcall CreateWindowExW(
        DWORD dwExStyle,
        LPCWSTR lpClassName,
        LPCWSTR lpWindowName,
        DWORD dwStyle,
        int X,
        int Y,
        int nWidth,
        int nHeight,
        HWND hWndParent,
        HMENU hMenu,
        HINSTANCE hInstance,
        LPVOID lpParam)
{
  return __imp_CreateWindowExW(
           dwExStyle,
           lpClassName,
           lpWindowName,
           dwStyle,
           X,
           Y,
           nWidth,
           nHeight,
           hWndParent,
           hMenu,
           hInstance,
           lpParam);
}


/* DefWindowProcW @ 00418CF8 */
// attributes: thunk
LRESULT __stdcall DefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return __imp_DefWindowProcW(hWnd, Msg, wParam, lParam);
}


/* GetDlgItem @ 00418CFE */
// attributes: thunk
HWND __stdcall GetDlgItem(HWND hDlg, int nIDDlgItem)
{
  return __imp_GetDlgItem(hDlg, nIDDlgItem);
}


/* IsDlgButtonChecked @ 00418D04 */
// attributes: thunk
UINT __stdcall IsDlgButtonChecked(HWND hDlg, int nIDButton)
{
  return __imp_IsDlgButtonChecked(hDlg, nIDButton);
}


/* LoadImageW @ 00418D0A */
// attributes: thunk
HANDLE __stdcall LoadImageW(HINSTANCE hInst, LPCWSTR name, UINT type, int cx, int cy, UINT fuLoad)
{
  return __imp_LoadImageW(hInst, name, type, cx, cy, fuLoad);
}


/* LoadMenuW @ 00418D10 */
// attributes: thunk
HMENU __stdcall LoadMenuW(HINSTANCE hInstance, LPCWSTR lpMenuName)
{
  return __imp_LoadMenuW(hInstance, lpMenuName);
}


/* FreeLibrary @ 00418D16 */
// attributes: thunk
BOOL __stdcall FreeLibrary(HMODULE hLibModule)
{
  return __imp_FreeLibrary(hLibModule);
}


/* GetCommandLineA @ 00418D1C */
// attributes: thunk
LPSTR __stdcall GetCommandLineA()
{
  return __imp_GetCommandLineA();
}


/* GetCommandLineW @ 00418D22 */
// attributes: thunk
LPWSTR __stdcall GetCommandLineW()
{
  return __imp_GetCommandLineW();
}


/* GetFileAttributesW @ 00418D28 */
// attributes: thunk
DWORD __stdcall GetFileAttributesW(LPCWSTR lpFileName)
{
  return __imp_GetFileAttributesW(lpFileName);
}


/* GetLastError @ 00418D2E */
// attributes: thunk
DWORD __stdcall GetLastError()
{
  return __imp_GetLastError();
}


/* GetLocaleInfoW @ 00418D34 */
// attributes: thunk
int __stdcall GetLocaleInfoW(LCID Locale, LCTYPE LCType, LPWSTR lpLCData, int cchData)
{
  return __imp_GetLocaleInfoW(Locale, LCType, lpLCData, cchData);
}


/* GetModuleHandleA @ 00418D3A */
// attributes: thunk
HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName)
{
  return __imp_GetModuleHandleA(lpModuleName);
}


/* GetProcAddress @ 00418D40 */
// attributes: thunk
FARPROC __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{
  return __imp_GetProcAddress(hModule, lpProcName);
}


/* nullsub_1 @ 00419000 */
void nullsub_1()
{
  ;
}


/* sub_4192F4 @ 004192F4 */
int __stdcall sub_4192F4(unsigned __int32 *a1, unsigned int *a2)
{
  int i; // ebx
  unsigned int v5; // eax
  int *v6; // esi
  int v7; // edx
  int v8; // eax
  unsigned __int32 *v9; // edi
  unsigned __int32 v10; // eax
  unsigned __int32 v11; // eax
  int result; // eax

  for ( i = 6; i != 0; --i )
  {
    v5 = *a2;
    v6 = (int *)(a2 + 1);
    v7 = ~__ROR4__(_byteswap_ulong(v5), 13);
    v8 = *v6++;
    *a1 = v7 ^ _byteswap_ulong(__ROL4__(v8, 11));
    v9 = a1 + 1;
    v10 = _byteswap_ulong(__ROL4__(*v6, 9));
    *v9++ = v10;
    v11 = ~v10 ^ _byteswap_ulong(__ROL4__(v6[1], 7));
    *v9++ = v11;
    result = ~v11 ^ __ROL4__(v11, 5);
    *v9 = result;
    a1 = v9 + 1;
    a2 = a1 - 4;
  }
  return result;
}


/* sub_419348 @ 00419348 */
int __stdcall sub_419348(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int i; // ecx
  int v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edx
  unsigned int j; // ecx
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int k; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx

  v3 = -66052;
  for ( i = 64; i != 0; --i )
  {
    *(_DWORD *)(a3 + 4 * i - 4) = v3;
    v3 -= 67372036;
  }
  v5 = 0;
  do
  {
    v6 = i / 0x40;
    v7 = i % 0x40;
    LOBYTE(v6) = i;
    LOBYTE(v7) = v5 + *(_BYTE *)(a3 + v6) + *(_BYTE *)(a2 + i % 0x40);
    LOBYTE(v5) = *(_BYTE *)(a3 + v7);
    LOBYTE(v7) = *(_BYTE *)(a3 + v6);
    *(_BYTE *)(a3 + v6) = *(_BYTE *)(a3 + v5);
    *(_BYTE *)(a3 + v5) = v7;
    ++i;
  }
  while ( i != 768 );
  for ( j = 0; j != 768; ++j )
  {
    v9 = j / 0x20;
    v10 = j % 0x20;
    LOBYTE(v9) = j;
    LOBYTE(v10) = v5 + *(_BYTE *)(a3 + v9) + *(_BYTE *)(a1 + j % 0x20);
    LOBYTE(v5) = *(_BYTE *)(a3 + v10);
    LOBYTE(v10) = *(_BYTE *)(a3 + v9);
    *(_BYTE *)(a3 + v9) = *(_BYTE *)(a3 + v5);
    *(_BYTE *)(a3 + v5) = v10;
  }
  for ( k = 0; k != 768; ++k )
  {
    v12 = k / 0x40;
    v13 = k % 0x40;
    LOBYTE(v12) = k;
    LOBYTE(v13) = v5 + *(_BYTE *)(a3 + v12) + *(_BYTE *)(a2 + k % 0x40);
    LOBYTE(v5) = *(_BYTE *)(a3 + v13);
    LOBYTE(v13) = *(_BYTE *)(a3 + v12);
    *(_BYTE *)(a3 + v12) = *(_BYTE *)(a3 + v5);
    *(_BYTE *)(a3 + v5) = v13;
  }
  return v5;
}


/* sub_41941C @ 0041941C */
char __stdcall sub_41941C(_BYTE *a1, int a2, int a3, int a4)
{
  char result; // al
  int v6; // ecx
  int v7; // edx
  int i; // esi
  char v10; // dl

  result = 0;
  v6 = 0;
  v7 = 0;
  for ( i = a2; i != 0; --i )
  {
    LOBYTE(v7) = a4 + *(_BYTE *)(a3 + v6);
    LOBYTE(a4) = *(_BYTE *)(a3 + v7);
    LOBYTE(v7) = *(_BYTE *)(a3 + a4);
    LOBYTE(v7) = *(_BYTE *)(a3 + v7) + 1;
    result = *(_BYTE *)(a3 + v7);
    *a1 ^= result;
    v10 = *(_BYTE *)(a3 + v6);
    *(_BYTE *)(a3 + v6) = *(_BYTE *)(a3 + a4);
    *(_BYTE *)(a3 + a4) = v10;
    LOBYTE(v6) = v6 + 1;
    ++a1;
  }
  return result;
}



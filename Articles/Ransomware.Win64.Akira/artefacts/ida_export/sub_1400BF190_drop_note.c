__int64 __fastcall sub_1400BF190(__int64 a1)
{
  __int64 v1; // rbx
  __int64 v2; // rax
  _QWORD *v3; // rdi
  __int64 v4; // rcx
  _QWORD *v5; // rsi
  _OWORD *v6; // rdi
  __int64 v7; // r8
  unsigned int v8; // eax
  void *v9; // rcx
  void (**v10)(void); // rdx
  void (**v11)(void); // rdx
  _QWORD *v12; // rsi
  _QWORD *v13; // r15
  char **v14; // r13
  char *v15; // rcx
  _WORD *v16; // rax
  __int64 v17; // r10
  _WORD *v18; // r11
  _WORD *v19; // rdx
  __int16 v20; // cx
  void **v21; // rdi
  __int64 v22; // rax
  __int64 v23; // rcx
  char v24; // si
  _BYTE *v25; // rcx
  __int64 v26; // rsi
  char v27; // r14
  int v28; // r15d
  __int64 v29; // r12
  int v30; // r8d
  _QWORD *v31; // rdx
  __int64 v32; // rax
  char *v33; // rcx
  void **v34; // r14
  _BYTE *v35; // rcx
  char *v36; // rcx
  void **v37; // rsi
  __int64 v38; // rdi
  void *v39; // rcx
  unsigned __int64 v40; // rdi
  int v41; // r14d
  _BYTE *v42; // rcx
  char *v43; // rcx
  char *v44; // rdi
  char *v45; // rax
  char *v46; // rdx
  char *v47; // r8
  __int16 v48; // cx
  __int64 v49; // rax
  _WORD *v50; // rdx
  void **v51; // rdi
  _BYTE *v52; // rcx
  _QWORD *v53; // rax
  _QWORD *v54; // rcx
  _WORD *v55; // rax
  __int64 v56; // r10
  _WORD *v57; // r11
  _WORD *v58; // rdx
  __int16 v59; // cx
  void **v60; // rdi
  _BYTE *v61; // rcx
  __int64 v62; // rax
  __int64 v63; // rcx
  _OWORD *v64; // r15
  char *v65; // rdx
  __int64 v66; // r8
  __int64 v67; // rcx
  _WORD *v68; // rax
  __int64 v69; // r10
  _WORD *v70; // r11
  _WORD *v71; // rdx
  __int16 v72; // cx
  void **v73; // r14
  void **v74; // rsi
  char *v75; // rcx
  _BYTE *v76; // rcx
  _BYTE *v77; // rcx
  void *v78; // rcx
  char *v79; // rdx
  __int64 v80; // r8
  __int64 v81; // r10
  _WORD *v82; // rax
  _WORD *v83; // rdx
  __int64 v84; // r10
  _WORD *v85; // r8
  __int16 v86; // cx
  _WORD *v87; // r8
  __int16 v88; // cx
  void **v89; // r13
  void *v90; // rax
  __int64 v91; // rax
  void **v92; // r12
  __int64 v93; // rax
  void **v94; // r14
  __int64 v95; // r8
  __int64 v96; // rax
  void **v97; // rdi
  __int64 v98; // r15
  void *v99; // rsi
  void **v100; // rsi
  _BYTE *v101; // rcx
  _BYTE *v102; // rcx
  _BYTE *v103; // rcx
  void *v104; // rcx
  _BYTE *v105; // rcx
  void *v106; // rcx
  char **v107; // rdi
  __int64 v108; // rcx
  _QWORD *v109; // rcx
  unsigned __int64 v110; // r11
  unsigned __int64 v111; // rdx
  char *v112; // r10
  signed __int64 v113; // r10
  unsigned __int16 v114; // r8
  int v115; // eax
  char v116; // al
  __int64 v117; // rcx
  _QWORD *v118; // rcx
  unsigned __int64 v119; // r11
  unsigned __int64 v120; // rdx
  char *v121; // r10
  __int64 v122; // r10
  unsigned __int16 v123; // r8
  int v124; // eax
  char v125; // al
  unsigned __int8 v126; // si
  __int64 v127; // r14
  char v128; // r15
  int v129; // r12d
  __int64 v130; // r13
  int v131; // eax
  char *v132; // rcx
  _BYTE *v133; // rcx
  char *v134; // rcx
  char *v135; // rcx
  void **v136; // r14
  void **v137; // rsi
  _BYTE *v138; // rcx
  _BYTE *v139; // rcx
  _BYTE *v140; // rcx
  _QWORD *v141; // rsi
  unsigned int v142; // eax
  __int64 v143; // rcx
  volatile signed __int32 *v144; // rdi
  void (**v145)(void); // rdx
  void (**v146)(void); // rdx
  void (**v147)(void); // rdx
  void (**v148)(void); // rdx
  void (**v149)(void); // rdx
  void (**v150)(void); // rdx
  __int64 result; // rax
  __int64 v152; // rax
  __int64 v153; // rax
  __int64 v154; // rcx
  int v155; // [rsp+40h] [rbp-7F8h]
  unsigned __int8 v156; // [rsp+44h] [rbp-7F4h]
  int v157; // [rsp+50h] [rbp-7E8h]
  _QWORD *v159; // [rsp+70h] [rbp-7C8h]
  _QWORD *v160; // [rsp+A8h] [rbp-790h]
  std::exception *v161; // [rsp+288h] [rbp-5B0h] BYREF
  __int128 v162; // [rsp+300h] [rbp-538h]
  __int64 v163; // [rsp+310h] [rbp-528h]
  __int64 v164; // [rsp+318h] [rbp-520h]
  _QWORD *v165; // [rsp+320h] [rbp-518h]
  volatile signed __int32 *v166; // [rsp+328h] [rbp-510h]
  char *v167; // [rsp+330h] [rbp-508h]
  unsigned __int64 v168; // [rsp+340h] [rbp-4F8h]
  unsigned __int64 v169; // [rsp+348h] [rbp-4F0h]
  _QWORD *v170; // [rsp+350h] [rbp-4E8h]
  __int64 v171; // [rsp+358h] [rbp-4E0h]
  char *v172; // [rsp+360h] [rbp-4D8h]
  __int64 v173; // [rsp+370h] [rbp-4C8h]
  unsigned __int64 v174; // [rsp+378h] [rbp-4C0h]
  char *v175; // [rsp+380h] [rbp-4B8h]
  __int64 v176; // [rsp+390h] [rbp-4A8h]
  unsigned __int64 v177; // [rsp+398h] [rbp-4A0h]
  char *v178; // [rsp+3A0h] [rbp-498h]
  unsigned __int64 v179; // [rsp+3B8h] [rbp-480h]
  char *v180; // [rsp+3C0h] [rbp-478h]
  __int64 v181; // [rsp+3D0h] [rbp-468h]
  unsigned __int64 v182; // [rsp+3D8h] [rbp-460h]
  char *v183; // [rsp+3E0h] [rbp-458h]
  unsigned __int64 v184; // [rsp+3F8h] [rbp-440h]
  char *v185; // [rsp+400h] [rbp-438h]
  unsigned __int64 v186; // [rsp+418h] [rbp-420h]
  char *v187; // [rsp+420h] [rbp-418h]
  unsigned __int64 v188; // [rsp+438h] [rbp-400h]
  char *v189; // [rsp+440h] [rbp-3F8h]
  unsigned __int64 v190; // [rsp+458h] [rbp-3E0h]
  char *v191; // [rsp+460h] [rbp-3D8h]
  unsigned __int64 v192; // [rsp+478h] [rbp-3C0h]
  __int64 (__fastcall **v193)(__int64); // [rsp+498h] [rbp-3A0h]
  __int64 v194; // [rsp+4A0h] [rbp-398h]
  __int16 v195; // [rsp+4ECh] [rbp-34Ch]
  __int16 v196; // [rsp+4EEh] [rbp-34Ah]
  __int16 v197; // [rsp+4F0h] [rbp-348h]
  const std::filesystem::filesystem_error *v198[30]; // [rsp+710h] [rbp-128h] BYREF

  v1 = a1;
  switch ( *(_WORD *)(a1 + 148) )
  {
    case 0xFFFF:
    case 1:
    case 3:
      sub_140080718(a1: a1 + 40);
      result = sub_1400709A0(a1: v1 + 65);
      if ( *(_WORD *)(v1 + 10) != 0 )
        result = sub_14003A420(a1: v1, a2: 2032);
      goto LABEL_350;
    case 2:
      __eh34_enter_try_state(-1, 0);
      __eh34_enter_wind_state(0, 1);
      v157 = 0;
      *(_OWORD *)(a1 + 152) = 0;
      *(_OWORD *)(a1 + 168) = 0;
      *(_OWORD *)(a1 + 184) = 0;
      *(_QWORD *)(a1 + 200) = 0;
      v2 = *(_QWORD *)(a1 + 24);
      v3 = *(_QWORD **)v2;
      if ( *(_QWORD *)(*(_QWORD *)v2 + 80LL) != 0 )
      {
        v4 = v3[9];
        *(_QWORD *)(v1 + 176) = v4;
        *(_QWORD *)(v1 + 192) = v3[11];
        v193 = (__int64 (__fastcall **)(__int64))v4;
        (*(void (__fastcall **)(__int64, _QWORD *))(v4 + 8))(a1: v1 + 152, a2: v3 + 6);
      }
      else
      {
        *(_QWORD *)(a1 + 176) = 0;
        *(_QWORD *)(a1 + 184) = 0;
        *(_QWORD *)(a1 + 192) = 0;
      }
      if ( __eh34_unwind(1) )
unwind_state_1:
        terminate();
      __eh34_exit_wind_state(1, 0);
      __wind
      {
        *(_QWORD *)(v1 + 200) = v3[12];
        v5 = (_QWORD *)(v1 + 97);
        sub_140042C90(a1: v1 + 97);
        v6 = (_OWORD *)(v1 + 224);
        v7 = *(_QWORD *)(v1 + 113);
        if ( *(_QWORD *)(v1 + 121) >= 8u )
          v5 = (_QWORD *)*v5;
        try
        {
          *v6 = 0;
          *(_QWORD *)(v1 + 240) = 0;
          *(_QWORD *)(v1 + 248) = 0;
          sub_14003EE60(a1: v1 + 224, a2: v5, a3: v7);
          __wind
          {
            __wind
            {
              v155 = 384;
              *(_QWORD *)(v1 + 208) = 0;
              *(_QWORD *)(v1 + 216) = 0;
              v8 = sub_140070DB0(a1: v1 + 208, a2: v1 + 224);
              if ( v8 != 0 )
                sub_14006F280(a1: "directory_iterator::directory_iterator", a2: v8, a3: v1 + 224);
            }
            __unwind
            {
              v198[3] = (const std::filesystem::filesystem_error *)(a1 + 208);
              sub_14004F3A0(a1: (void *)(a1 + 208));
            }
          }
          __unwind
          {
            v198[2] = (const std::filesystem::filesystem_error *)(a1 + 224);
            unknown_libname_4(a1: (void *)(a1 + 224));
          }
          __wind
          {
            if ( *(_QWORD *)(v1 + 248) >= 8u )
            {
              v9 = *(void **)v6;
              if ( (unsigned __int64)(2LL * *(_QWORD *)(v1 + 248) + 2) >= 0x1000 )
              {
                v9 = *(void **)(*(_QWORD *)v6 - 8LL);
                if ( (unsigned __int64)(*(_QWORD *)v6 - (_QWORD)v9 - 8LL) > 0x1F )
                  invalid_parameter_noinfo_noreturn();
              }
              j_j_free(Block: v9);
            }
            *(_OWORD *)(v1 + 256) = 0;
            v164 = *(_QWORD *)(v1 + 216);
            if ( v164 != 0 )
            {
              v164 = *(_QWORD *)(v1 + 216);
              _InterlockedIncrement((volatile signed __int32 *)(v164 + 8));
            }
            v163 = *(_QWORD *)(v1 + 208);
            *(_QWORD *)(v1 + 256) = v163;
            v164 = *(_QWORD *)(v1 + 216);
            *(_QWORD *)(v1 + 264) = v164;
            v164 = *(_QWORD *)(v1 + 216);
            if ( v164 != 0 )
            {
              v164 = *(_QWORD *)(v1 + 216);
              _InterlockedIncrement((volatile signed __int32 *)(v164 + 8));
            }
            *(_OWORD *)(v1 + 288) = 0;
            *(_QWORD *)(v1 + 288) = 0;
            *(_QWORD *)(v1 + 296) = 0;
            v164 = *(_QWORD *)(v1 + 216);
            if ( v164 != 0 )
            {
              v164 = *(_QWORD *)(v1 + 216);
              if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v164 + 8), 0xFFFFFFFF) == 1 )
              {
                v164 = *(_QWORD *)(v1 + 216);
                v10 = *(void (***)(void))v164;
                v164 = *(_QWORD *)(v1 + 216);
                (*v10)();
                v164 = *(_QWORD *)(v1 + 216);
                if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v164 + 12), 0xFFFFFFFF) == 1 )
                {
                  v164 = *(_QWORD *)(v1 + 216);
                  v11 = *(void (***)(void))v164;
                  v164 = *(_QWORD *)(v1 + 216);
                  v11[1]();
                }
              }
            }
            __wind
            {
              __wind
              {
                while ( 1 )
                {
LABEL_22:
                  v12 = (_QWORD *)(v1 + 256);
                  v159 = (_QWORD *)(v1 + 256);
                  v165 = *(_QWORD **)(v1 + 256);
                  v170 = *(_QWORD **)(v1 + 288);
                  if ( v165 == v170 )
                    goto LABEL_351;
                  v165 = (_QWORD *)*v12;
                  v13 = v165 + 4;
                  v160 = v165 + 4;
                  v14 = (char **)(v1 + 320);
                  sub_14003B400(a1: v1 + 320, a2: v165 + 4);
                  v15 = (char *)(v1 + 320);
                  v174 = *(_QWORD *)(v1 + 344);
                  if ( v174 >= 8 )
                  {
                    v15 = *v14;
                    v172 = *v14;
                  }
                  v173 = *(_QWORD *)(v1 + 336);
                  v16 = (_WORD *)sub_1400382A0(a1: v15, a2: &v15[2 * v173]);
                  if ( v16 != v18 )
                  {
                    do
                    {
                      if ( *v16 != 92 && *v16 != 47 )
                        break;
                      ++v16;
                    }
                    while ( v16 != v18 );
                    if ( v16 != v18 )
                    {
                      do
                      {
                        v19 = (_WORD *)(v17 - 2);
                        v20 = *(_WORD *)(v17 - 2);
                        if ( v20 == 92 )
                          break;
                        if ( v20 == 47 )
                          break;
                        v17 -= 2;
                      }
                      while ( v16 != v19 );
                    }
                  }
                  __eh34_enter_wind_state(9, 10);
                  v34 = (void **)(v1 + 352);
                  *(_OWORD *)(v1 + 352) = 0;
                  *(_QWORD *)(v1 + 368) = 0;
                  *(_QWORD *)(v1 + 376) = 0;
                  sub_14003EE60(a1: v1 + 352, a2: v17, a3: ((__int64)v18 - v17) >> 1);
                  v155 |= 7u;
                  v165 = (_QWORD *)*v12;
                  sub_14006F350(a1: v165, a2: v1 + 1776);
                  __eh34_enter_wind_state(10, 11);
                  try
                  {
                    if ( *(_DWORD *)(v1 + 1784) != 0 && *(_DWORD *)(v1 + 1776) != 1 && *(_DWORD *)(v1 + 1776) != 9 )
                      sub_14006F280(a1: "directory_entry::status", a2: *(unsigned int *)(v1 + 1784), a3: v13);
                    v165 = (_QWORD *)*v12;
                    sub_14006F350(a1: v165, a2: v1 + 1792);
                  }
                  catch ( const std::filesystem::filesystem_error *v198 )
                  {
                    unknown_libname_4(a1: (void *)(v1 + 352));
                    if ( __eh34_unwind(11) )
                      goto unwind_state_11;
                    __eh34_exit_wind_state(11, 10);
                    if ( __eh34_unwind(10) )
                      goto unwind_state_10;
                    __eh34_exit_wind_state(10, 9);
                    unknown_libname_4(a1: (void *)(v1 + 320));
                    v159 = (_QWORD *)(v1 + 256);
                    v1 = a1;
                    goto LABEL_305;
                  }
                  if ( *(_DWORD *)(v1 + 1800) != 0 && *(_DWORD *)(v1 + 1792) != 1 && *(_DWORD *)(v1 + 1792) != 9 )
                    sub_14006F280(a1: "directory_entry::status", a2: *(unsigned int *)(v1 + 1800), a3: v13);
                  if ( *(_DWORD *)(v1 + 1792) == 3 )
                  {
                    v21 = (void **)(v1 + 384);
                    sub_14003B400(a1: v1 + 384, a2: v1 + 352);
                    v155 |= 8u;
                    v22 = sub_14005DEA0(a1: &Block, a2: v1 + 1808, a3: v1 + 384);
                    v24 = sub_14005DF80(a1: v23, a2: *(_QWORD *)(v22 + 16), a3: v1 + 384);
                    if ( *(_QWORD *)(v1 + 408) >= 8u )
                    {
                      v25 = *v21;
                      if ( (unsigned __int64)(2LL * *(_QWORD *)(v1 + 408) + 2) >= 0x1000 )
                      {
                        v25 = *((_BYTE **)*v21 - 1);
                        if ( (unsigned __int64)((_BYTE *)*v21 - v25 - 8) > 0x1F )
LABEL_56:
                          invalid_parameter_noinfo_noreturn();
                      }
                      j_j_free(Block: v25);
                    }
                    if ( v24 == 0 )
                    {
                      sub_14003B400(a1: v1 + 416, a2: v13);
                      v155 |= 0x10u;
                      __wind
                      {
                        v26 = *(_QWORD *)(v1 + 65);
                        v27 = *(_BYTE *)(v1 + 141);
                        v28 = *(_DWORD *)(v1 + 137);
                        v29 = *(_QWORD *)(v1 + 129);
                        v30 = sub_14003B400(a1: v1 + 448, a2: v1 + 416);
                        v31 = (_QWORD *)(v1 + 480);
                        *(_QWORD *)(v1 + 480) = 0;
                        *(_QWORD *)(v1 + 488) = 0;
                        v32 = *(_QWORD *)(v1 + 89);
                        if ( v32 != 0 )
                          _InterlockedIncrement((volatile signed __int32 *)(v32 + 8));
                        *v31 = *(_QWORD *)(v1 + 81);
                        *(_QWORD *)(v1 + 488) = *(_QWORD *)(v1 + 89);
                        sub_14007BFD0(a1: v26, a2: (_DWORD)v31, a3: v30, a4: v29, a5: v28, a6: v27);
                      }
                      __unwind
                      {
                        v198[9] = (const std::filesystem::filesystem_error *)(a1 + 416);
                        unknown_libname_4(a1: (void *)(a1 + 416));
                      }
                      v184 = *(_QWORD *)(v1 + 440);
                      if ( v184 >= 8 )
                      {
                        v184 = *(_QWORD *)(v1 + 440);
                        v33 = *(char **)(v1 + 416);
                        v183 = v33;
                        if ( 2 * v184 + 2 >= 0x1000 )
                        {
                          v183 = *(char **)(v1 + 416);
                          v33 = *((char **)v183 - 1);
                          v183 = *(char **)(v1 + 416);
                          if ( (unsigned __int64)(v183 - v33 - 8) > 0x1F )
                            goto LABEL_56;
                        }
                        j_j_free(Block: v33);
                      }
                      v34 = (void **)(v1 + 352);
                    }
                    v179 = *(_QWORD *)(v1 + 376);
                    if ( v179 >= 8 )
                    {
                      v179 = *(_QWORD *)(v1 + 376);
                      v35 = *v34;
                      v178 = (char *)*v34;
                      if ( 2 * v179 + 2 >= 0x1000 )
                      {
                        v178 = (char *)*v34;
                        v35 = *((_BYTE **)v178 - 1);
                        v178 = (char *)*v34;
                        if ( (unsigned __int64)(v178 - v35 - 8) > 0x1F )
                          goto LABEL_299;
                      }
                      j_j_free(Block: v35);
                    }
                    *(_QWORD *)(v1 + 368) = 0;
                    *(_QWORD *)(v1 + 376) = 7;
                    *(_WORD *)v34 = 0;
                    v174 = *(_QWORD *)(v1 + 344);
                    if ( v174 >= 8 )
                    {
                      v174 = *(_QWORD *)(v1 + 344);
                      v36 = *v14;
                      v172 = *v14;
                      if ( 2 * v174 + 2 >= 0x1000 )
                      {
                        v172 = *v14;
                        v36 = *((char **)v172 - 1);
                        v172 = *v14;
                        if ( (unsigned __int64)(v172 - v36 - 8) > 0x1F )
                          goto LABEL_304;
                      }
LABEL_66:
                      j_j_free(Block: v36);
                      goto LABEL_447;
                    }
                    goto LABEL_447;
                  }
                  v165 = (_QWORD *)*v12;
                  sub_14006F350(a1: v165, a2: v1 + 1832);
                  if ( *(_DWORD *)(v1 + 1840) != 0 && *(_DWORD *)(v1 + 1832) != 1 && *(_DWORD *)(v1 + 1832) != 9 )
                    sub_14006F280(a1: "directory_entry::status", a2: *(unsigned int *)(v1 + 1840), a3: v13);
                  if ( *(_DWORD *)(v1 + 1832) == 2 )
                    break;
LABEL_296:
                  v179 = *(_QWORD *)(v1 + 376);
                  if ( v179 >= 8 )
                  {
                    v179 = *(_QWORD *)(v1 + 376);
                    v140 = *v34;
                    v178 = (char *)*v34;
                    if ( 2 * v179 + 2 >= 0x1000 )
                    {
                      v178 = (char *)*v34;
                      v140 = *((_BYTE **)v178 - 1);
                      v178 = (char *)*v34;
                      if ( (unsigned __int64)(v178 - v140 - 8) > 0x1F )
LABEL_299:
                        invalid_parameter_noinfo_noreturn();
                    }
                    j_j_free(Block: v140);
                  }
                  *(_QWORD *)(v1 + 368) = 0;
                  *(_QWORD *)(v1 + 376) = 7;
                  *(_WORD *)v34 = 0;
                  v174 = *(_QWORD *)(v1 + 344);
                  if ( v174 >= 8 )
                  {
                    v174 = *(_QWORD *)(v1 + 344);
                    v36 = *v14;
                    v172 = *v14;
                    if ( 2 * v174 + 2 >= 0x1000 )
                    {
                      v172 = *v14;
                      v36 = *((char **)v172 - 1);
                      v172 = *v14;
                      if ( (unsigned __int64)(v172 - v36 - 8) > 0x1F )
LABEL_304:
                        invalid_parameter_noinfo_noreturn();
                    }
                    goto LABEL_66;
                  }
                  if ( __eh34_unwind(11) )
                  {
unwind_state_11:
                    v198[8] = (const std::filesystem::filesystem_error *)(a1 + 352);
                    unknown_libname_4(a1: (void *)(a1 + 352));
                    __eh34_continue_unwinding(11, 10);
                  }
LABEL_447:
                  __eh34_exit_wind_state(11, 10);
                  if ( __eh34_unwind(10) )
                  {
unwind_state_10:
                    v198[7] = (const std::filesystem::filesystem_error *)(a1 + 320);
                    unknown_libname_4(a1: (void *)(a1 + 320));
                    __eh34_continue_unwinding(10, 9);
                  }
                  __eh34_exit_wind_state(10, 9);
LABEL_305:
                  v141 = (_QWORD *)*v159;
                  v165 = (_QWORD *)*v159;
                  while ( 1 )
                  {
                    v142 = sub_140080B0C(a1: v141[8], a2: v1 + 1184);
                    if ( v142 == 18 )
                      break;
                    if ( v142 != 0 )
                      sub_14006F190(a1: v143, a2: v142);
                    v195 = *(_WORD *)(v1 + 1228);
                    if ( v195 == 46 )
                    {
                      v196 = *(_WORD *)(v1 + 1230);
                      if ( v196 == 0 )
                        continue;
                      v196 = *(_WORD *)(v1 + 1230);
                      if ( v196 == 46 )
                      {
                        v197 = *(_WORD *)(v1 + 1232);
                        if ( v197 == 0 )
                          continue;
                      }
                    }
                    v165 = (_QWORD *)*v159;
                    sub_14006F630(a1: v165, a2: v1 + 1184);
                    goto LABEL_22;
                  }
                  *v159 = 0;
                  v166 = *(volatile signed __int32 **)(v1 + 264);
                  v144 = v166;
                  *(_QWORD *)(v1 + 264) = 0;
                  if ( v144 != nullptr && _InterlockedExchangeAdd(v144 + 2, 0xFFFFFFFF) == 1 )
                  {
                    (**(void (__fastcall ***)(volatile signed __int32 *))v144)(a1: v144);
                    if ( _InterlockedExchangeAdd(v144 + 3, 0xFFFFFFFF) == 1 )
                      (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v144 + 8LL))(a1: v144);
                  }
                }
                v37 = (void **)(v1 + 496);
                v38 = -1;
                do
                  ++v38;
                while ( aAkiraReadmeTxt[v38] != 0 );
                _std_fs_code_page();
                *(_QWORD *)(v1 + 1888) = aAkiraReadmeTxt;
                *(_QWORD *)(v1 + 1896) = v38;
                sub_14006E2E0(Src: (void *)(v1 + 496));
                v155 |= 0x60u;
                v39 = (void *)(v1 + 496);
                v40 = *(_QWORD *)(v1 + 520);
                if ( v40 >= 8 )
                  v39 = *v37;
                *(_QWORD *)(v1 + 1848) = v39;
                *(_QWORD *)(v1 + 1856) = *(_QWORD *)(v1 + 512);
                v162 = *(_OWORD *)(v1 + 1848);
                *(_OWORD *)(v1 + 1872) = v162;
                v41 = sub_14006E6C0(a1: v1 + 352);
                if ( v40 >= 8 )
                {
                  v42 = *v37;
                  if ( (unsigned __int64)(2LL * *(_QWORD *)(v1 + 520) + 2) >= 0x1000 )
                  {
                    v42 = *((_BYTE **)*v37 - 1);
                    if ( (unsigned __int64)((_BYTE *)*v37 - v42 - 8) > 0x1F )
                      invalid_parameter_noinfo_noreturn();
                  }
                  j_j_free(Block: v42);
                }
                if ( v41 == 0 )
                {
LABEL_295:
                  v34 = (void **)(v1 + 352);
                  goto LABEL_296;
                }
                v43 = (char *)(v1 + 320);
                v174 = *(_QWORD *)(v1 + 344);
                if ( v174 >= 8 )
                {
                  v43 = *v14;
                  v172 = *v14;
                }
                v173 = *(_QWORD *)(v1 + 336);
                v44 = &v43[2 * v173];
                v45 = (char *)sub_1400382A0(a1: v43, a2: v44);
                if ( v45 != v46 )
                {
                  do
                  {
                    if ( *(_WORD *)v45 != 92 && *(_WORD *)v45 != 47 )
                      break;
                    v45 += 2;
                  }
                  while ( v45 != v46 );
                  if ( v45 != v46 )
                  {
                    do
                    {
                      v47 = v44 - 2;
                      v48 = *((_WORD *)v44 - 1);
                      if ( v48 == 92 )
                        break;
                      if ( v48 == 47 )
                        break;
                      v44 -= 2;
                    }
                    while ( v45 != v47 );
                  }
                }
                LOWORD(v47) = 58;
                v49 = unknown_libname_27(a1: v44, a2: v46, a3: v47);
                if ( v44 == (char *)v49 )
                  goto LABEL_101;
                v50 = (_WORD *)(v49 - 2);
                if ( v44 == (char *)(v49 - 2) )
                  goto LABEL_101;
                if ( *v50 == 46 )
                {
                  if ( v44 == (char *)(v49 - 4) && *(_WORD *)(v49 - 4) == 46 )
                    goto LABEL_101;
                }
                else
                {
                  v50 = (_WORD *)(v49 - 4);
                  if ( v44 == (char *)(v49 - 4) )
                  {
LABEL_101:
                    v50 = (_WORD *)v49;
                    goto LABEL_102;
                  }
                  while ( *v50 != 46 )
                  {
                    if ( v44 == (char *)--v50 )
                      goto LABEL_101;
                  }
                }
LABEL_102:
                v51 = (void **)(v1 + 528);
                *(_OWORD *)(v1 + 528) = 0;
                *(_QWORD *)(v1 + 544) = 0;
                *(_QWORD *)(v1 + 552) = 0;
                sub_14003EE60(a1: v1 + 528, a2: v50, a3: (v49 - (__int64)v50) >> 1);
                __wind
                {
                  v137 = (void **)(v1 + 560);
                  sub_14003B400(a1: v1 + 560, a2: v1 + 528);
                }
                __unwind
                {
                  v198[10] = (const std::filesystem::filesystem_error *)(a1 + 528);
                  unknown_libname_4(a1: (void *)(a1 + 528));
                }
                __eh34_enter_wind_state(11, 17);
                if ( *(_QWORD *)(v1 + 552) >= 8u )
                {
                  v52 = *v51;
                  if ( (unsigned __int64)(2LL * *(_QWORD *)(v1 + 552) + 2) >= 0x1000 )
                  {
                    v52 = *((_BYTE **)*v51 - 1);
                    if ( (unsigned __int64)((_BYTE *)*v51 - v52 - 8) > 0x1F )
                    {
                      if ( __eh34_unwind(17) )
                      {
unwind_state_17:
                        v198[11] = (const std::filesystem::filesystem_error *)(a1 + 560);
                        unknown_libname_4(a1: (void *)(a1 + 560));
                        __eh34_continue_unwinding(17, 11);
                      }
                      __eh34_exit_wind_state(17, 11);
LABEL_288:
                      invalid_parameter_noinfo_noreturn();
                    }
                  }
                  j_j_free(Block: v52);
                }
                v53 = (_QWORD *)*v159;
                v165 = v53;
                v54 = v53 + 4;
                if ( v53[7] >= 8u )
                  v54 = (_QWORD *)v53[4];
                v55 = (_WORD *)sub_1400382A0(a1: v54, a2: (char *)v54 + 2 * v53[6]);
                if ( v55 != v57 )
                {
                  do
                  {
                    if ( *v55 != 92 && *v55 != 47 )
                      break;
                    ++v55;
                  }
                  while ( v55 != v57 );
                  if ( v55 != v57 )
                  {
                    do
                    {
                      v58 = (_WORD *)(v56 - 2);
                      v59 = *(_WORD *)(v56 - 2);
                      if ( v59 == 92 )
                        break;
                      if ( v59 == 47 )
                        break;
                      v56 -= 2;
                    }
                    while ( v55 != v58 );
                  }
                }
                v60 = (void **)(v1 + 592);
                *(_OWORD *)(v1 + 592) = 0;
                *(_QWORD *)(v1 + 608) = 0;
                *(_QWORD *)(v1 + 616) = 0;
                sub_14003EE60(a1: v1 + 592, a2: v56, a3: ((__int64)v57 - v56) >> 1);
                __wind
                {
                  v136 = (void **)(v1 + 624);
                  sub_14003B400(a1: v1 + 624, a2: v1 + 592);
                  v155 |= 0x1FE00u;
                }
                __unwind
                {
                  v198[12] = (const std::filesystem::filesystem_error *)(a1 + 592);
                  unknown_libname_4(a1: (void *)(a1 + 592));
                }
                __wind
                {
                  if ( *(_QWORD *)(v1 + 616) >= 8u )
                  {
                    v61 = *v60;
                    if ( (unsigned __int64)(2LL * *(_QWORD *)(v1 + 616) + 2) >= 0x1000 )
                    {
                      v61 = *((_BYTE **)*v60 - 1);
                      if ( (unsigned __int64)((_BYTE *)*v60 - v61 - 8) > 0x1F )
                        invalid_parameter_noinfo_noreturn();
                    }
                    j_j_free(Block: v61);
                  }
                  v62 = sub_14005DEA0(a1: &qword_140102138, a2: v1 + 1904, a3: v137);
                  if ( (unsigned __int8)sub_14005DF80(a1: v63, a2: *(_QWORD *)(v62 + 16), a3: v137) != 0
                    || (unsigned __int8)sub_1400704D0(a1: v136) != 0 )
                  {
                    goto LABEL_382;
                  }
                  sub_14003B400(a1: v1 + 656, a2: v13);
                  __wind
                  {
                    v64 = (_OWORD *)(v1 + 688);
                    v65 = (char *)(v1 + 656);
                    v177 = *(_QWORD *)(v1 + 680);
                    if ( v177 >= 8 )
                    {
                      v65 = *(char **)(v1 + 656);
                      v175 = v65;
                    }
                    v176 = *(_QWORD *)(v1 + 672);
                    v66 = v176;
                    *v64 = 0;
                    *(_QWORD *)(v1 + 704) = 0;
                    *(_QWORD *)(v1 + 712) = 0;
                    sub_14003EE60(a1: v1 + 688, a2: v65, a3: v66);
                    __wind
                    {
                      v67 = v1 + 688;
                      if ( *(_QWORD *)(v1 + 712) >= 8u )
                        v67 = *(_QWORD *)v64;
                      v68 = (_WORD *)sub_1400382A0(a1: v67, a2: v67 + 2LL * *(_QWORD *)(v1 + 704));
                      if ( v68 != v70 )
                      {
                        do
                        {
                          if ( *v68 != 92 && *v68 != 47 )
                            break;
                          ++v68;
                        }
                        while ( v68 != v70 );
                        if ( v68 != v70 )
                        {
                          do
                          {
                            v71 = (_WORD *)(v69 - 2);
                            v72 = *(_WORD *)(v69 - 2);
                            if ( v72 == 92 )
                              break;
                            if ( v72 == 47 )
                              break;
                            v69 -= 2;
                          }
                          while ( v68 != v71 );
                        }
                      }
                      v73 = (void **)(v1 + 720);
                      *(_OWORD *)(v1 + 720) = 0;
                      *(_QWORD *)(v1 + 736) = 0;
                      *(_QWORD *)(v1 + 744) = 0;
                      sub_14003EE60(a1: v1 + 720, a2: v69, a3: ((__int64)v70 - v69) >> 1);
                      __wind
                      {
                        v74 = (void **)(v1 + 752);
                        sub_14003B400(a1: v1 + 752, a2: v1 + 720);
                        __wind
                        {
                          sub_14007EAF0(a1: v1 + 1952, a2: v1 + 752, a3: 65001);
                          __wind
                          {
                            sub_140036AB0(a1: v1 + 784, a2: v1 + 1952);
                          }
                          __unwind
                          {
                            v198[18] = (const std::filesystem::filesystem_error *)(a1 + 1952);
                            sub_1400371B0(a1: a1 + 1952);
                          }
                          v186 = *(_QWORD *)(v1 + 1976);
                          if ( v186 >= 0x10 )
                          {
                            v186 = *(_QWORD *)(v1 + 1976);
                            v75 = *(char **)(v1 + 1952);
                            v185 = v75;
                            if ( v186 + 1 >= 0x1000 )
                            {
                              v185 = *(char **)(v1 + 1952);
                              v75 = *((char **)v185 - 1);
                              v185 = *(char **)(v1 + 1952);
                              if ( (unsigned __int64)(v185 - v75 - 8) > 0x1F )
                                invalid_parameter_noinfo_noreturn();
                            }
                            j_j_free(Block: v75);
                          }
                          if ( *(_QWORD *)(v1 + 776) >= 8u )
                          {
                            v76 = *v74;
                            if ( (unsigned __int64)(2LL * *(_QWORD *)(v1 + 776) + 2) >= 0x1000 )
                            {
                              v76 = *((_BYTE **)*v74 - 1);
                              if ( (unsigned __int64)((_BYTE *)*v74 - v76 - 8) > 0x1F )
                                invalid_parameter_noinfo_noreturn();
                            }
                            j_j_free(Block: v76);
                          }
                          *(_QWORD *)(v1 + 768) = 0;
                          *(_QWORD *)(v1 + 776) = 7;
                          *(_WORD *)v74 = 0;
                          if ( *(_QWORD *)(v1 + 744) >= 8u )
                          {
                            v77 = *v73;
                            if ( (unsigned __int64)(2LL * *(_QWORD *)(v1 + 744) + 2) >= 0x1000 )
                            {
                              v77 = *((_BYTE **)*v73 - 1);
                              if ( (unsigned __int64)((_BYTE *)*v73 - v77 - 8) > 0x1F )
                                invalid_parameter_noinfo_noreturn();
                            }
                            j_j_free(Block: v77);
                          }
                          if ( *(_QWORD *)(v1 + 712) >= 8u )
                          {
                            v78 = *(void **)v64;
                            if ( (unsigned __int64)(2LL * *(_QWORD *)(v1 + 712) + 2) >= 0x1000 )
                            {
                              v78 = *(void **)(*(_QWORD *)v64 - 8LL);
                              if ( (unsigned __int64)(*(_QWORD *)v64 - (_QWORD)v78 - 8LL) > 0x1F )
                                invalid_parameter_noinfo_noreturn();
                            }
                            j_j_free(Block: v78);
                          }
                          *(_QWORD *)(v1 + 704) = 0;
                          *(_QWORD *)(v1 + 712) = 7;
                          *(_WORD *)v64 = 0;
                          v79 = (char *)(v1 + 656);
                          v177 = *(_QWORD *)(v1 + 680);
                          if ( v177 >= 8 )
                          {
                            v79 = *(char **)(v1 + 656);
                            v175 = v79;
                          }
                        }
                        __unwind
                        {
                          v198[17] = (const std::filesystem::filesystem_error *)(a1 + 752);
                          unknown_libname_4(a1: (void *)(a1 + 752));
                        }
                      }
                      __unwind
                      {
                        v198[16] = (const std::filesystem::filesystem_error *)(a1 + 720);
                        unknown_libname_4(a1: (void *)(a1 + 720));
                      }
                    }
                    __unwind
                    {
                      v198[15] = (const std::filesystem::filesystem_error *)(a1 + 688);
                      unknown_libname_4(a1: (void *)(a1 + 688));
                    }
                    __wind
                    {
                      v176 = *(_QWORD *)(v1 + 672);
                      v80 = v176;
                      *(_OWORD *)(v1 + 848) = 0;
                      *(_QWORD *)(v1 + 864) = 0;
                      *(_QWORD *)(v1 + 872) = 0;
                      sub_14003EE60(a1: v1 + 848, a2: v79, a3: v80);
                      v81 = v1 + 848;
                      if ( *(_QWORD *)(v1 + 872) >= 8u )
                        v81 = *(_QWORD *)(v1 + 848);
                      v82 = (_WORD *)sub_1400382A0(a1: v81, a2: v81 + 2LL * *(_QWORD *)(v1 + 864));
                      if ( v82 != v83 )
                      {
                        do
                        {
                          if ( *v82 != 92 && *v82 != 47 )
                            break;
                          ++v82;
                        }
                        while ( v82 != v83 );
                        if ( v82 != v83 )
                        {
                          while ( 1 )
                          {
                            v85 = v83 - 1;
                            v86 = *(v83 - 1);
                            if ( v86 == 92 || v86 == 47 )
                              break;
                            --v83;
                            if ( v82 == v85 )
                              goto LABEL_394;
                          }
                          if ( v82 != v83 )
                          {
                            do
                            {
                              v87 = v83 - 1;
                              v88 = *(v83 - 1);
                              if ( v88 != 92 && v88 != 47 )
                                break;
                              --v83;
                            }
                            while ( v82 != v87 );
                          }
                        }
                      }
LABEL_394:
                      __wind
                      {
                        v89 = (void **)(v1 + 880);
                        *(_OWORD *)(v1 + 880) = 0;
                        *(_QWORD *)(v1 + 896) = 0;
                        *(_QWORD *)(v1 + 904) = 0;
                        sub_14003EE60(a1: v1 + 880, a2: v84, a3: ((__int64)v83 - v84) >> 1);
                        __wind
                        {
                          v90 = (void *)sub_140038390(lpWideCharStr: (LPCWCH)(v1 + 880));
                          __wind
                          {
                            v91 = sub_140037430(Src: v90);
                            v92 = (void **)(v1 + 944);
                            *(_OWORD *)(v1 + 944) = 0;
                            *(_QWORD *)(v1 + 960) = 0;
                            *(_QWORD *)(v1 + 968) = 0;
                            *(_OWORD *)(v1 + 944) = *(_OWORD *)v91;
                            *(_OWORD *)(v1 + 960) = *(_OWORD *)(v91 + 16);
                            *(_QWORD *)(v91 + 16) = 0;
                            *(_QWORD *)(v91 + 24) = 15;
                            *(_BYTE *)v91 = 0;
                            v182 = *(_QWORD *)(v1 + 808);
                            if ( v182 >= 0x10 )
                              v180 = *(char **)(v1 + 784);
                            __wind
                            {
                              v181 = *(_QWORD *)(v1 + 800);
                              v93 = sub_140037430(Src: (void *)(v1 + 944));
                              v94 = (void **)(v1 + 976);
                              *(_OWORD *)(v1 + 976) = 0;
                              *(_QWORD *)(v1 + 992) = 0;
                              *(_QWORD *)(v1 + 1000) = 0;
                              *(_OWORD *)(v1 + 976) = *(_OWORD *)v93;
                              *(_OWORD *)(v1 + 992) = *(_OWORD *)(v93 + 16);
                              *(_QWORD *)(v93 + 16) = 0;
                              *(_QWORD *)(v93 + 24) = 15;
                              *(_BYTE *)v93 = 0;
                              v95 = -1;
                              do
                                ++v95;
                              while ( aArika[v95] != 0 );
                              __wind
                              {
                                v96 = sub_140037430(Src: (void *)(v1 + 976));
                                v97 = (void **)(v1 + 1008);
                                *(_OWORD *)(v1 + 1008) = 0;
                                *(_QWORD *)(v1 + 1024) = 0;
                                *(_QWORD *)(v1 + 1032) = 0;
                                *(_OWORD *)(v1 + 1008) = *(_OWORD *)v96;
                                *(_OWORD *)(v1 + 1024) = *(_OWORD *)(v96 + 16);
                                *(_QWORD *)(v96 + 16) = 0;
                                *(_QWORD *)(v96 + 24) = 15;
                                *(_BYTE *)v96 = 0;
                                v157 |= 7u;
                                v98 = *(_QWORD *)(v1 + 1024);
                                v99 = (void *)(v1 + 1008);
                                if ( *(_QWORD *)(v1 + 1032) >= 0x10u )
                                  v99 = *v97;
                                _std_fs_code_page();
                                __wind
                                {
                                  *(_QWORD *)(v1 + 1936) = v99;
                                  *(_QWORD *)(v1 + 1944) = v98;
                                  v100 = (void **)(v1 + 816);
                                  sub_14006E2E0(Src: (void *)(v1 + 816));
                                  v155 |= 0xFFFE0000;
                                  if ( *(_QWORD *)(v1 + 1032) >= 0x10u )
                                  {
                                    v101 = *v97;
                                    if ( (unsigned __int64)(*(_QWORD *)(v1 + 1032) + 1LL) >= 0x1000 )
                                    {
                                      v101 = *((_BYTE **)*v97 - 1);
                                      if ( (unsigned __int64)((_BYTE *)*v97 - v101 - 8) > 0x1F )
                                        invalid_parameter_noinfo_noreturn();
                                    }
                                    j_j_free(Block: v101);
                                  }
                                  *(_QWORD *)(v1 + 1024) = 0;
                                  *(_QWORD *)(v1 + 1032) = 15;
                                  *(_BYTE *)v97 = 0;
                                  if ( *(_QWORD *)(v1 + 1000) >= 0x10u )
                                  {
                                    v102 = *v94;
                                    if ( (unsigned __int64)(*(_QWORD *)(v1 + 1000) + 1LL) >= 0x1000 )
                                    {
                                      v102 = *((_BYTE **)*v94 - 1);
                                      if ( (unsigned __int64)((_BYTE *)*v94 - v102 - 8) > 0x1F )
                                        invalid_parameter_noinfo_noreturn();
                                    }
                                    j_j_free(Block: v102);
                                  }
                                  *(_QWORD *)(v1 + 992) = 0;
                                  *(_QWORD *)(v1 + 1000) = 15;
                                  *(_BYTE *)v94 = 0;
                                  if ( *(_QWORD *)(v1 + 968) >= 0x10u )
                                  {
                                    v103 = *v92;
                                    if ( (unsigned __int64)(*(_QWORD *)(v1 + 968) + 1LL) >= 0x1000 )
                                    {
                                      v103 = *((_BYTE **)*v92 - 1);
                                      if ( (unsigned __int64)((_BYTE *)*v92 - v103 - 8) > 0x1F )
                                        invalid_parameter_noinfo_noreturn();
                                    }
                                    j_j_free(Block: v103);
                                  }
                                  *(_QWORD *)(v1 + 960) = 0;
                                  *(_QWORD *)(v1 + 968) = 15;
                                  *(_BYTE *)v92 = 0;
                                  if ( *(_QWORD *)(v1 + 936) >= 0x10u )
                                  {
                                    v104 = *(void **)(v1 + 912);
                                    if ( (unsigned __int64)(*(_QWORD *)(v1 + 936) + 1LL) >= 0x1000 )
                                    {
                                      v104 = *(void **)(*(_QWORD *)(v1 + 912) - 8LL);
                                      if ( (unsigned __int64)(*(_QWORD *)(v1 + 912) - (_QWORD)v104 - 8LL) > 0x1F )
                                        invalid_parameter_noinfo_noreturn();
                                    }
                                    j_j_free(Block: v104);
                                  }
                                  *(_QWORD *)(v1 + 928) = 0;
                                  *(_QWORD *)(v1 + 936) = 15;
                                  *(_BYTE *)(v1 + 912) = 0;
                                  if ( *(_QWORD *)(v1 + 904) >= 8u )
                                  {
                                    v105 = *v89;
                                    if ( (unsigned __int64)(2LL * *(_QWORD *)(v1 + 904) + 2) >= 0x1000 )
                                    {
                                      v105 = *((_BYTE **)*v89 - 1);
                                      if ( (unsigned __int64)((_BYTE *)*v89 - v105 - 8) > 0x1F )
                                        invalid_parameter_noinfo_noreturn();
                                    }
                                    j_j_free(Block: v105);
                                  }
                                  *(_QWORD *)(v1 + 896) = 0;
                                  *(_QWORD *)(v1 + 904) = 7;
                                  *(_WORD *)v89 = 0;
                                  if ( *(_QWORD *)(v1 + 872) >= 8u )
                                  {
                                    v106 = *(void **)(v1 + 848);
                                    if ( (unsigned __int64)(2LL * *(_QWORD *)(v1 + 872) + 2) >= 0x1000 )
                                    {
                                      v106 = *(void **)(*(_QWORD *)(v1 + 848) - 8LL);
                                      if ( (unsigned __int64)(*(_QWORD *)(v1 + 848) - (_QWORD)v106 - 8LL) > 0x1F )
                                        invalid_parameter_noinfo_noreturn();
                                    }
                                    j_j_free(Block: v106);
                                  }
                                }
                                __unwind
                                {
                                  v198[25] = (const std::filesystem::filesystem_error *)(a1 + 1008);
                                  sub_1400371B0(a1: a1 + 1008);
                                }
                              }
                              __unwind
                              {
                                v198[24] = (const std::filesystem::filesystem_error *)(a1 + 976);
                                sub_1400371B0(a1: a1 + 976);
                              }
                            }
                            __unwind
                            {
                              v198[23] = (const std::filesystem::filesystem_error *)(a1 + 944);
                              sub_1400371B0(a1: a1 + 944);
                            }
                          }
                          __unwind
                          {
                            v198[22] = (const std::filesystem::filesystem_error *)(a1 + 912);
                            sub_1400371B0(a1: a1 + 912);
                          }
                        }
                        __unwind
                        {
                          v198[21] = (const std::filesystem::filesystem_error *)(a1 + 880);
                          unknown_libname_4(a1: (void *)(a1 + 880));
                        }
                      }
                      __unwind
                      {
                        v198[20] = (const std::filesystem::filesystem_error *)(a1 + 848);
                        unknown_libname_4(a1: (void *)(a1 + 848));
                      }
                      __wind
                      {
                        *(_QWORD *)(v1 + 864) = 0;
                        *(_QWORD *)(v1 + 872) = 7;
                        *(_WORD *)(v1 + 848) = 0;
                        if ( (unsigned __int8)sub_14006FCD0(a1: v100) != 0 )
                        {
LABEL_269:
                          v190 = *(_QWORD *)(v1 + 840);
                          if ( v190 >= 8 )
                          {
                            v190 = *(_QWORD *)(v1 + 840);
                            v133 = *v100;
                            v189 = (char *)*v100;
                            if ( 2 * v190 + 2 >= 0x1000 )
                            {
                              v189 = (char *)*v100;
                              v133 = *((_BYTE **)v189 - 1);
                              v189 = (char *)*v100;
                              if ( (unsigned __int64)(v189 - v133 - 8) > 0x1F )
                                invalid_parameter_noinfo_noreturn();
                            }
                            j_j_free(Block: v133);
                          }
                          *(_QWORD *)(v1 + 832) = 0;
                          *(_QWORD *)(v1 + 840) = 7;
                          *(_WORD *)v100 = 0;
                          v182 = *(_QWORD *)(v1 + 808);
                          if ( v182 >= 0x10 )
                          {
                            v182 = *(_QWORD *)(v1 + 808);
                            v134 = *(char **)(v1 + 784);
                            v180 = v134;
                            if ( v182 + 1 >= 0x1000 )
                            {
                              v180 = *(char **)(v1 + 784);
                              v134 = *((char **)v180 - 1);
                              v180 = *(char **)(v1 + 784);
                              if ( (unsigned __int64)(v180 - v134 - 8) > 0x1F )
                                invalid_parameter_noinfo_noreturn();
                            }
                            j_j_free(Block: v134);
                          }
                          *(_QWORD *)(v1 + 800) = 0;
                          *(_QWORD *)(v1 + 808) = 15;
                          *(_BYTE *)(v1 + 784) = 0;
                          v177 = *(_QWORD *)(v1 + 680);
                          if ( v177 >= 8 )
                          {
                            v177 = *(_QWORD *)(v1 + 680);
                            v135 = *(char **)(v1 + 656);
                            v175 = v135;
                            if ( 2 * v177 + 2 >= 0x1000 )
                            {
                              v175 = *(char **)(v1 + 656);
                              v135 = *((char **)v175 - 1);
                              v175 = *(char **)(v1 + 656);
                              if ( (unsigned __int64)(v175 - v135 - 8) > 0x1F )
                                invalid_parameter_noinfo_noreturn();
                            }
                            j_j_free(Block: v135);
                          }
                          v14 = (char **)(v1 + 320);
                          v136 = (void **)(v1 + 624);
                          v137 = (void **)(v1 + 560);
                          goto LABEL_382;
                        }
                        v107 = (char **)(v1 + 560);
                        v108 = *(_QWORD *)(sub_14005DEA0(a1: &qword_140102168, a2: v1 + 2008, a3: v1 + 560) + 16);
                        if ( *(_BYTE *)(v108 + 25) != 0 )
                          goto LABEL_238;
                        v109 = (_QWORD *)(v108 + 32);
                        v110 = v109[2];
                        if ( v109[3] >= 8u )
                          v109 = (_QWORD *)*v109;
                        v111 = *(_QWORD *)(v1 + 576);
                        v168 = v111;
                        v112 = (char *)(v1 + 560);
                        v169 = *(_QWORD *)(v1 + 584);
                        if ( v169 >= 8 )
                        {
                          v112 = *v107;
                          v167 = *v107;
                        }
                        v168 = *(_QWORD *)(v1 + 576);
                        if ( v110 < v168 )
                          v111 = v110;
                        if ( v111 != 0 )
                        {
                          v113 = v112 - (char *)v109;
                          while ( 1 )
                          {
                            v114 = *(_WORD *)((char *)v109 + v113);
                            if ( v114 != *(_WORD *)v109 )
                              break;
                            v109 = (_QWORD *)((char *)v109 + 2);
                            if ( --v111 == 0 )
                              goto LABEL_232;
                          }
                          v115 = 1;
                          if ( v114 < *(_WORD *)v109 )
                            v115 = -1;
                          if ( v115 < 0 )
                            goto LABEL_233;
                        }
                        else
                        {
LABEL_232:
                          v168 = *(_QWORD *)(v1 + 576);
                          if ( v168 < v110 )
                          {
LABEL_233:
                            v116 = -1;
                            goto LABEL_236;
                          }
                          v168 = *(_QWORD *)(v1 + 576);
                          if ( v168 <= v110 )
                          {
LABEL_237:
                            v156 = 1;
                            goto LABEL_239;
                          }
                        }
                        v116 = 1;
LABEL_236:
                        if ( v116 >= 0 )
                          goto LABEL_237;
LABEL_238:
                        v156 = 0;
LABEL_239:
                        v117 = *(_QWORD *)(sub_14005DEA0(a1: &qword_140102190, a2: v1 + 1984, a3: v1 + 560) + 16);
                        if ( *(_BYTE *)(v117 + 25) != 0 )
                          goto LABEL_261;
                        v118 = (_QWORD *)(v117 + 32);
                        v119 = v118[2];
                        if ( v118[3] >= 8u )
                          v118 = (_QWORD *)*v118;
                        v120 = *(_QWORD *)(v1 + 576);
                        v168 = v120;
                        v121 = (char *)(v1 + 560);
                        v169 = *(_QWORD *)(v1 + 584);
                        if ( v169 >= 8 )
                        {
                          v121 = *v107;
                          v167 = *v107;
                        }
                        v168 = *(_QWORD *)(v1 + 576);
                        if ( v119 < v168 )
                          v120 = v119;
                        if ( v120 != 0 )
                        {
                          v122 = v121 - (char *)v118;
                          while ( 1 )
                          {
                            v123 = *(_WORD *)((char *)v118 + v122);
                            if ( v123 != *(_WORD *)v118 )
                              break;
                            v118 = (_QWORD *)((char *)v118 + 2);
                            if ( --v120 == 0 )
                              goto LABEL_255;
                          }
                          v124 = 1;
                          if ( v123 < *(_WORD *)v118 )
                            v124 = -1;
                          if ( v124 < 0 )
                            goto LABEL_256;
                        }
                        else
                        {
LABEL_255:
                          v168 = *(_QWORD *)(v1 + 576);
                          if ( v168 < v119 )
                          {
LABEL_256:
                            v125 = -1;
                            goto LABEL_259;
                          }
                          v168 = *(_QWORD *)(v1 + 576);
                          if ( v168 <= v119 )
                          {
LABEL_260:
                            v126 = 1;
                            goto LABEL_262;
                          }
                        }
                        v125 = 1;
LABEL_259:
                        if ( v125 >= 0 )
                          goto LABEL_260;
LABEL_261:
                        v126 = 0;
LABEL_262:
                        sub_14003B400(a1: v1 + 1040, a2: v160);
                        v157 |= 8u;
                        __wind
                        {
                          v127 = *(_QWORD *)(v1 + 81);
                          v128 = *(_BYTE *)(v1 + 141);
                          v129 = *(_DWORD *)(v1 + 137);
                          v130 = *(_QWORD *)(v1 + 129);
                          v131 = sub_14003B400(a1: v1 + 1072, a2: v1 + 1040);
                          sub_14007C470(a1: v127, a2: v131, a3: v126, a4: v156, a5: v130, a6: v129, a7: v128);
                        }
                        __unwind
                        {
                          v198[27] = (const std::filesystem::filesystem_error *)(a1 + 1040);
                          unknown_libname_4(a1: (void *)(a1 + 1040));
                        }
                        v188 = *(_QWORD *)(v1 + 1064);
                        if ( v188 >= 8 )
                        {
                          v188 = *(_QWORD *)(v1 + 1064);
                          v132 = *(char **)(v1 + 1040);
                          v187 = v132;
                          if ( 2 * v188 + 2 >= 0x1000 )
                          {
                            v187 = *(char **)(v1 + 1040);
                            v132 = *((char **)v187 - 1);
                            v187 = *(char **)(v1 + 1040);
                            if ( (unsigned __int64)(v187 - v132 - 8) > 0x1F )
                              invalid_parameter_noinfo_noreturn();
                          }
                          j_j_free(Block: v132);
                        }
                        v100 = (void **)(v1 + 816);
                        goto LABEL_269;
                      }
                      __unwind
                      {
                        v198[26] = (const std::filesystem::filesystem_error *)(a1 + 816);
                        unknown_libname_4(a1: (void *)(a1 + 816));
                      }
                    }
                    __unwind
                    {
                      v198[19] = (const std::filesystem::filesystem_error *)(a1 + 784);
                      sub_1400371B0(a1: a1 + 784);
                    }
                  }
                  __unwind
                  {
                    v198[14] = (const std::filesystem::filesystem_error *)(a1 + 656);
                    unknown_libname_4(a1: (void *)(a1 + 656));
                  }
                }
                __unwind
                {
                  v198[13] = (const std::filesystem::filesystem_error *)(a1 + 624);
                  unknown_libname_4(a1: (void *)(a1 + 624));
                }
                if ( __eh34_unwind(17) )
                  goto unwind_state_17;
LABEL_382:
                __eh34_exit_wind_state(17, 11);
                v192 = *(_QWORD *)(v1 + 648);
                if ( v192 >= 8 )
                {
                  v192 = *(_QWORD *)(v1 + 648);
                  v138 = *v136;
                  v191 = (char *)*v136;
                  if ( 2 * v192 + 2 >= 0x1000 )
                  {
                    v191 = (char *)*v136;
                    v138 = *((_BYTE **)v191 - 1);
                    v191 = (char *)*v136;
                    if ( (unsigned __int64)(v191 - v138 - 8) > 0x1F )
                      goto LABEL_288;
                  }
                  j_j_free(Block: v138);
                }
                *(_QWORD *)(v1 + 640) = 0;
                *(_QWORD *)(v1 + 648) = 7;
                *(_WORD *)v136 = 0;
                v169 = *(_QWORD *)(v1 + 584);
                if ( v169 >= 8 )
                {
                  v169 = *(_QWORD *)(v1 + 584);
                  v139 = *v137;
                  v167 = (char *)*v137;
                  if ( 2 * v169 + 2 >= 0x1000 )
                  {
                    v167 = (char *)*v137;
                    v139 = *((_BYTE **)v167 - 1);
                    v167 = (char *)*v137;
                    if ( (unsigned __int64)(v167 - v139 - 8) > 0x1F )
                      invalid_parameter_noinfo_noreturn();
                  }
                  j_j_free(Block: v139);
                }
                goto LABEL_295;
              }
              __unwind
              {
                v198[6] = (const std::filesystem::filesystem_error *)(a1 + 288);
                sub_14004F3A0(a1: (void *)(a1 + 288));
              }
LABEL_351:
              v171 = *(_QWORD *)(v1 + 296);
              if ( v171 != 0 )
              {
                v171 = *(_QWORD *)(v1 + 296);
                if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v171 + 8), 0xFFFFFFFF) == 1 )
                {
                  v171 = *(_QWORD *)(v1 + 296);
                  v145 = *(void (***)(void))v171;
                  v171 = *(_QWORD *)(v1 + 296);
                  (*v145)();
                  v171 = *(_QWORD *)(v1 + 296);
                  if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v171 + 12), 0xFFFFFFFF) == 1 )
                  {
                    v171 = *(_QWORD *)(v1 + 296);
                    v146 = *(void (***)(void))v171;
                    v171 = *(_QWORD *)(v1 + 296);
                    v146[1]();
                  }
                }
              }
              v166 = *(volatile signed __int32 **)(v1 + 264);
              if ( v166 != nullptr )
              {
                v166 = *(volatile signed __int32 **)(v1 + 264);
                if ( _InterlockedExchangeAdd(v166 + 2, 0xFFFFFFFF) == 1 )
                {
                  v166 = *(volatile signed __int32 **)(v1 + 264);
                  v147 = *(void (***)(void))v166;
                  v166 = *(volatile signed __int32 **)(v1 + 264);
                  (*v147)();
                  v166 = *(volatile signed __int32 **)(v1 + 264);
                  if ( _InterlockedExchangeAdd(v166 + 3, 0xFFFFFFFF) == 1 )
                  {
                    v166 = *(volatile signed __int32 **)(v1 + 264);
                    v148 = *(void (***)(void))v166;
                    v166 = *(volatile signed __int32 **)(v1 + 264);
                    v148[1]();
                  }
                }
              }
              v164 = *(_QWORD *)(v1 + 216);
              if ( v164 != 0 )
              {
                v164 = *(_QWORD *)(v1 + 216);
                if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v164 + 8), 0xFFFFFFFF) == 1 )
                {
                  v164 = *(_QWORD *)(v1 + 216);
                  v149 = *(void (***)(void))v164;
                  v164 = *(_QWORD *)(v1 + 216);
                  (*v149)();
                  v164 = *(_QWORD *)(v1 + 216);
                  if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v164 + 12), 0xFFFFFFFF) == 1 )
                  {
                    v164 = *(_QWORD *)(v1 + 216);
                    v150 = *(void (***)(void))v164;
                    v164 = *(_QWORD *)(v1 + 216);
                    v150[1]();
                  }
                }
              }
            }
            __unwind
            {
              v198[5] = (const std::filesystem::filesystem_error *)(a1 + 256);
              sub_14004F3A0(a1: (void *)(a1 + 256));
            }
          }
          __unwind
          {
            v198[4] = (const std::filesystem::filesystem_error *)(a1 + 208);
            sub_14004F3A0(a1: (void *)(a1 + 208));
          }
        }
        catch ( std::exception *v161 )
        {
          *(_QWORD *)(a1 + 1104) = (*(__int64 (__fastcall **)(std::exception *))(*(_QWORD *)v161 + 8LL))(a1: v161);
          v152 = sub_14003E680(a1: (void *)(a1 + 1112));
          __wind
          {
            v153 = sub_14003E3F0(a1: a1 + 1144, a2: "search files error:", a3: v152);
            __wind
            {
              sub_140039EC0(a1: v154, a2: v153);
            }
            __unwind
            {
              v198[29] = (const std::filesystem::filesystem_error *)(a1 + 1144);
              sub_1400371B0(a1: a1 + 1144);
            }
            sub_1400371B0(a1: a1 + 1144);
            sub_1400371B0(a1: a1 + 1112);
          }
          __unwind
          {
            v198[28] = (const std::filesystem::filesystem_error *)(a1 + 1112);
            sub_1400371B0(a1: a1 + 1112);
          }
          v1 = a1;
        }
      }
      __unwind
      {
        v198[1] = (const std::filesystem::filesystem_error *)(a1 + 152);
        sub_140038710(a1: a1 + 152);
      }
      __eh34_enter_wind_state(0, 1);
      result = *(_QWORD *)(v1 + 184);
      v194 = result;
      if ( result != 0 )
      {
        v193 = *(__int64 (__fastcall ***)(__int64))(v1 + 176);
        result = (*v193)(a1: v1 + 152);
      }
      if ( __eh34_unwind(1) )
        goto unwind_state_1;
      __eh34_exit_wind_state(1, 0);
      if ( __eh34_catch(0) )
      {
catch_state_0:
        if ( __eh34_catch_ellipsis(0) )
        {
          *(_QWORD *)a1 = 0;
          *(_WORD *)(a1 + 148) = -1;
          sub_14003A3D0(a1: a1 + 16);
          v1 = a1;
          goto LABEL_332;
        }
        goto LABEL_349;
      }
      __eh34_exit_try_state(0, -1);
LABEL_332:
      *(_QWORD *)(v1 + 1176) = v1 + 16;
      *(_WORD *)(v1 + 148) = 0;
      *(_QWORD *)v1 = 0;
      result = sub_140039F80();
LABEL_350:
      __eh34_enter_try_state(-1, 0);
      if ( __eh34_catch(0) )
        goto catch_state_0;
LABEL_349:
      __eh34_exit_try_state(0, -1);
      return result;
    default:
      __debugbreak();
  }
}
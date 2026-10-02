void __fastcall sub_1400B71A0(__int64 a1)
{
  __int64 v1; // rbx
  _WORD *v2; // rsi
  __int64 v3; // rax
  _QWORD *v4; // rdi
  __int64 v5; // rcx
  char *v6; // r13
  size_t v7; // r10
  void **v8; // rsi
  size_t v9; // r9
  __int64 v10; // r12
  _QWORD *v11; // rdi
  __int64 *v12; // r8
  size_t v13; // rcx
  void *v14; // rax
  __int64 v15; // rax
  void **v16; // rdi
  _BYTE *v17; // rcx
  _BYTE *v18; // rcx
  volatile signed __int32 *v19; // rdi
  volatile signed __int32 *v20; // rdi
  char *v21; // rcx
  _WORD *v22; // rdx
  char v23; // r15
  const WCHAR *v24; // rdi
  const WCHAR *v25; // rcx
  DWORD FileAttributesW; // eax
  const WCHAR *v27; // rcx
  DWORD v28; // r8d
  const WCHAR *v29; // rcx
  HANDLE FileW; // rsi
  DWORD LastError; // eax
  size_t v32; // r10
  void **v33; // rsi
  size_t v34; // r9
  __int64 v35; // r12
  _QWORD *v36; // rdi
  __int64 *v37; // r8
  size_t v38; // rcx
  void *v39; // rax
  __int64 v40; // rax
  void **v41; // rdi
  _BYTE *v42; // rcx
  _BYTE *v43; // rcx
  volatile signed __int32 *v44; // rdi
  volatile signed __int32 *v45; // rdi
  char *v46; // rcx
  size_t v47; // r10
  void **v48; // rsi
  size_t v49; // r9
  __int64 v50; // r12
  _QWORD *v51; // rdi
  __int64 *v52; // r8
  size_t v53; // rcx
  void *v54; // rax
  __int64 v55; // rax
  void **v56; // rdi
  _BYTE *v57; // rcx
  _BYTE *v58; // rcx
  volatile signed __int32 *v59; // rdi
  volatile signed __int32 *v60; // rdi
  char *v61; // rcx
  size_t v62; // r10
  void **v63; // rsi
  size_t v64; // r9
  __int64 v65; // r12
  _QWORD *v66; // rdi
  __int64 *v67; // r8
  size_t v68; // rcx
  void *v69; // rax
  __int64 v70; // rax
  void **v71; // rdi
  _BYTE *v72; // rcx
  _BYTE *v73; // rcx
  volatile signed __int32 *v74; // rdi
  volatile signed __int32 *v75; // rdi
  char *v76; // rcx
  _OWORD *v77; // rax
  volatile signed __int32 *v78; // rdi
  char v79; // al
  __int64 perf_frequency; // rdi
  __int64 v81; // rax
  __int64 v82; // rcx
  __int64 v83; // rdi
  size_t v84; // r10
  void **v85; // rsi
  size_t v86; // r9
  __int64 v87; // r12
  _QWORD *v88; // rdi
  __int64 *v89; // r8
  size_t v90; // rcx
  void *v91; // rax
  __int64 v92; // rax
  void **v93; // rdi
  _BYTE *v94; // rcx
  _BYTE *v95; // rcx
  char *v96; // rcx
  volatile signed __int32 *v97; // rdi
  volatile signed __int32 *v98; // rdi
  char *v99; // rcx
  _QWORD *v100; // rdx
  _OWORD *v101; // r12
  __int64 v102; // r8
  __int64 v103; // rcx
  _WORD *v104; // rax
  __int64 v105; // r10
  _WORD *v106; // r11
  _WORD *v107; // rdx
  __int16 v108; // cx
  void **v109; // rsi
  void **v110; // rdi
  _BYTE *v111; // rcx
  _BYTE *v112; // rcx
  void *v113; // rcx
  __int64 v114; // rdi
  DWORD v115; // esi
  __int128 v116; // xmm0
  size_t v117; // r10
  void **v118; // rsi
  size_t v119; // r9
  __int64 v120; // r12
  _QWORD *v121; // rdi
  __int64 *v122; // r8
  size_t v123; // rcx
  void *v124; // rax
  __int64 v125; // rax
  void **v126; // rdi
  _BYTE *v127; // rcx
  _BYTE *v128; // rcx
  void **v129; // rdi
  void *v130; // rcx
  char **v131; // rdi
  char *v132; // rax
  char *v133; // rcx
  char *v134; // rcx
  volatile signed __int32 *v135; // rdi
  volatile signed __int32 *v136; // rdi
  char *v137; // rcx
  _QWORD *v138; // rdx
  __int64 v139; // r8
  __int64 v140; // rcx
  _WORD *v141; // rax
  __int64 v142; // r10
  _WORD *v143; // r11
  _WORD *v144; // rdx
  __int16 v145; // cx
  __int64 v146; // rax
  __int64 v147; // rax
  void **v148; // rsi
  char **v149; // rdi
  char **v150; // r8
  char *v151; // rax
  char *v152; // rcx
  _BYTE *v153; // rcx
  void *v154; // rcx
  void *v155; // rcx
  void *v156; // rcx
  void *v157; // rcx
  __int64 v158; // rdi
  DWORD v159; // esi
  __int128 v160; // xmm0
  size_t v161; // r10
  void **v162; // rsi
  size_t v163; // r9
  __int64 v164; // r12
  _QWORD *v165; // rdi
  __int64 *v166; // r8
  size_t v167; // rcx
  void *v168; // rax
  __int64 v169; // rax
  void **v170; // rdi
  _BYTE *v171; // rcx
  _BYTE *v172; // rcx
  void **v173; // rdi
  _BYTE *v174; // rcx
  char **v175; // rdi
  char *v176; // rax
  char *v177; // rcx
  char *v178; // rcx
  volatile signed __int32 *v179; // rdi
  volatile signed __int32 *v180; // rdi
  char *v181; // rcx
  __int64 v182; // rdi
  __int64 v183; // rax
  __int64 v184; // rax
  __int64 v185; // rax
  __int64 v186; // rax
  __int64 v187; // rax
  __int64 v188; // rax
  __int64 v189; // rax
  __int64 v190; // rax
  char v191; // di
  __int64 v192; // rax
  __int64 v193; // rax
  __int64 v194; // rcx
  char *v195; // rcx
  _WORD *v196; // rsi
  int v197; // ecx
  int v198; // ecx
  __int64 v199; // rax
  __int64 v200; // rax
  __int64 v201; // rax
  __int64 v202; // rax
  __int64 v203; // rax
  __int64 v204; // rax
  char v205; // di
  __int64 v206; // rax
  __int64 v207; // rax
  __int64 v208; // rcx
  __int64 v209; // rax
  __int64 v210; // rax
  __int64 v211; // rcx
  char v212; // di
  __int64 v213; // rax
  __int64 v214; // rax
  __int64 v215; // rcx
  __int64 v216; // rax
  __int64 v217; // rax
  char v218; // di
  __int64 v219; // rax
  __int64 v220; // rax
  __int64 v221; // rcx
  __int64 v222; // rax
  __int64 v223; // rax
  __int64 v224; // rax
  _BYTE *v225; // rsi
  size_t v226; // rdi
  const wchar_t *v227; // rax
  DWORD v228; // eax
  __int64 v229; // rax
  __int64 v230; // rax
  __int64 v231; // rax
  __int64 v232; // rax
  __int64 v233; // rax
  __int64 v234; // rcx
  const WCHAR *v235; // rax
  __int64 v236; // rax
  __int64 v237; // rax
  __int64 v238; // rcx
  void *v239; // rdi
  volatile signed __int32 *v240; // rdi
  volatile signed __int32 *v241; // rdi
  __int64 v242; // rax
  __int64 v243; // rax
  __int64 v244; // rax
  __int64 v245; // rax
  __int64 v246; // rax
  __int64 v247; // rcx
  __int64 v248; // rax
  __int64 v249; // rax
  __int64 v250; // rcx
  char v251; // [rsp+40h] [rbp-B38h]
  size_t Size; // [rsp+48h] [rbp-B30h]
  size_t Sizea; // [rsp+48h] [rbp-B30h]
  size_t Sizeb; // [rsp+48h] [rbp-B30h]
  size_t Sizec; // [rsp+48h] [rbp-B30h]
  size_t Sized; // [rsp+48h] [rbp-B30h]
  size_t Sizee; // [rsp+48h] [rbp-B30h]
  size_t Sizef; // [rsp+48h] [rbp-B30h]
  size_t Sizeg; // [rsp+48h] [rbp-B30h]
  size_t v260; // [rsp+50h] [rbp-B28h]
  size_t v261; // [rsp+50h] [rbp-B28h]
  size_t v262; // [rsp+50h] [rbp-B28h]
  size_t v263; // [rsp+50h] [rbp-B28h]
  _WORD *v264; // [rsp+58h] [rbp-B20h]
  size_t v265; // [rsp+60h] [rbp-B18h]
  size_t v266; // [rsp+60h] [rbp-B18h]
  size_t v267; // [rsp+60h] [rbp-B18h]
  DWORD dwBufferSize[2]; // [rsp+68h] [rbp-B10h]
  DWORD dwBufferSizea; // [rsp+68h] [rbp-B10h]
  _WORD *v271; // [rsp+80h] [rbp-AF8h]
  std::exception *v272; // [rsp+358h] [rbp-820h] BYREF
  std::exception *v273; // [rsp+360h] [rbp-818h] BYREF
  __int64 v274; // [rsp+368h] [rbp-810h]
  HANDLE v275; // [rsp+3A0h] [rbp-7D8h]
  __int64 v276; // [rsp+3A8h] [rbp-7D0h]
  volatile signed __int32 *v277; // [rsp+3B0h] [rbp-7C8h]
  __int64 v278; // [rsp+3B8h] [rbp-7C0h]
  void *v279; // [rsp+3C0h] [rbp-7B8h]
  __int64 v280; // [rsp+5E8h] [rbp-590h]
  volatile signed __int32 *v281; // [rsp+5F0h] [rbp-588h]
  char *v282; // [rsp+810h] [rbp-368h]
  size_t v283; // [rsp+820h] [rbp-358h]
  unsigned __int64 v284; // [rsp+828h] [rbp-350h]
  char *v285; // [rsp+830h] [rbp-348h]
  char *v286; // [rsp+838h] [rbp-340h]
  __int64 v287; // [rsp+840h] [rbp-338h]
  __int64 v288; // [rsp+848h] [rbp-330h]
  char *v289; // [rsp+850h] [rbp-328h]
  __int64 v290; // [rsp+860h] [rbp-318h]
  unsigned __int64 v291; // [rsp+868h] [rbp-310h]
  char *v292; // [rsp+870h] [rbp-308h]
  __int64 v293; // [rsp+880h] [rbp-2F8h]
  unsigned __int64 v294; // [rsp+888h] [rbp-2F0h]
  __int64 v295; // [rsp+890h] [rbp-2E8h]
  __int64 v296; // [rsp+898h] [rbp-2E0h]
  volatile signed __int32 *v297; // [rsp+8A0h] [rbp-2D8h]
  void (__fastcall **v298)(__int64); // [rsp+8C0h] [rbp-2B8h]
  __int64 v299; // [rsp+8C8h] [rbp-2B0h]
  __int64 v300; // [rsp+8E0h] [rbp-298h]
  __int64 v301; // [rsp+8E8h] [rbp-290h]
  __int64 v302; // [rsp+900h] [rbp-278h]
  _BYTE *v303; // [rsp+910h] [rbp-268h]
  __int64 v304; // [rsp+928h] [rbp-250h]
  __int64 v305; // [rsp+930h] [rbp-248h]
  __int64 v306; // [rsp+938h] [rbp-240h]
  __int64 v307; // [rsp+940h] [rbp-238h]
  __int64 v308; // [rsp+948h] [rbp-230h]
  __int64 v309; // [rsp+950h] [rbp-228h]
  __int64 v310; // [rsp+958h] [rbp-220h]
  __int64 v311; // [rsp+960h] [rbp-218h]
  __int64 v312; // [rsp+968h] [rbp-210h]
  __int64 v313; // [rsp+970h] [rbp-208h]
  __int64 v314; // [rsp+978h] [rbp-200h]
  __int64 v315; // [rsp+980h] [rbp-1F8h]
  __int64 v316; // [rsp+988h] [rbp-1F0h]
  __int64 v317; // [rsp+990h] [rbp-1E8h]
  __int64 v318; // [rsp+998h] [rbp-1E0h]
  __int64 v319; // [rsp+9A0h] [rbp-1D8h]
  __int64 v320; // [rsp+9A8h] [rbp-1D0h]
  __int64 v321; // [rsp+9B0h] [rbp-1C8h]
  __int64 v322; // [rsp+9B8h] [rbp-1C0h]
  __int64 v323; // [rsp+9C0h] [rbp-1B8h]
  __int64 v324; // [rsp+9C8h] [rbp-1B0h]
  __int64 v325; // [rsp+9D0h] [rbp-1A8h]
  __int64 v326; // [rsp+9D8h] [rbp-1A0h]
  __int64 v327; // [rsp+9E0h] [rbp-198h]
  __int64 v328; // [rsp+9E8h] [rbp-190h]
  __int64 v329; // [rsp+9F0h] [rbp-188h]
  __int64 v330; // [rsp+9F8h] [rbp-180h]
  __int64 v331; // [rsp+A00h] [rbp-178h]
  __int64 v332; // [rsp+A08h] [rbp-170h]
  __int64 v333; // [rsp+A10h] [rbp-168h]
  __int64 v334; // [rsp+A18h] [rbp-160h]
  __int64 v335; // [rsp+A20h] [rbp-158h]
  __int64 v336; // [rsp+A28h] [rbp-150h]
  __int64 v337; // [rsp+A30h] [rbp-148h]
  __int64 v338; // [rsp+A38h] [rbp-140h]
  __int64 v339; // [rsp+A40h] [rbp-138h]
  __int64 v340; // [rsp+A48h] [rbp-130h]
  __int64 v341; // [rsp+A50h] [rbp-128h]
  __int64 v342; // [rsp+A58h] [rbp-120h]
  __int64 v343; // [rsp+A60h] [rbp-118h]
  __int64 v344; // [rsp+A68h] [rbp-110h]
  __int64 v345; // [rsp+A70h] [rbp-108h]
  __int64 v346; // [rsp+A78h] [rbp-100h]
  __int64 v347; // [rsp+A80h] [rbp-F8h]
  __int64 v348; // [rsp+A88h] [rbp-F0h]
  __int64 v349; // [rsp+A90h] [rbp-E8h]
  __int64 v350; // [rsp+A98h] [rbp-E0h]
  __int64 v351; // [rsp+AA0h] [rbp-D8h]
  __int64 v352; // [rsp+AA8h] [rbp-D0h]
  __int64 v353; // [rsp+AB0h] [rbp-C8h]
  __int64 v354; // [rsp+AB8h] [rbp-C0h]
  __int64 v355; // [rsp+AC0h] [rbp-B8h]
  __int64 v356; // [rsp+AC8h] [rbp-B0h]
  __int64 v357; // [rsp+AD0h] [rbp-A8h]
  __int64 v358; // [rsp+AD8h] [rbp-A0h]
  __int64 v359; // [rsp+AE0h] [rbp-98h]
  __int64 v360; // [rsp+AE8h] [rbp-90h]
  __int64 v361; // [rsp+AF0h] [rbp-88h]
  __int64 v362; // [rsp+AF8h] [rbp-80h]
  __int64 v363; // [rsp+B00h] [rbp-78h]
  __int64 v364; // [rsp+B08h] [rbp-70h]
  __int64 v365; // [rsp+B10h] [rbp-68h]
  __int64 v366; // [rsp+B18h] [rbp-60h]
  __int64 v367; // [rsp+B20h] [rbp-58h]
  __int64 v368; // [rsp+B28h] [rbp-50h]
  __int64 v369; // [rsp+B30h] [rbp-48h]
  __int64 v370; // [rsp+B38h] [rbp-40h]

  v1 = a1;
  v2 = (_WORD *)(a1 + 100);
  v264 = (_WORD *)(a1 + 100);
  v271 = (_WORD *)(a1 + 100);
  __eh34_enter_try_state(-1, 0);
  __eh34_enter_wind_state(0, 2);
  __eh34_enter_wind_state(2, 3);
  __eh34_enter_wind_state(3, 4);
  __eh34_enter_wind_state(4, 5);
  __eh34_enter_wind_state(5, 17);
  __eh34_enter_wind_state(17, 20);
  switch ( *(_WORD *)(a1 + 100) )
  {
    case 0xFFFF:
    case 1:
    case 3:
      goto LABEL_584;
    case 2:
      *(_QWORD *)dwBufferSize = a1 + 104;
      *(_OWORD *)(a1 + 104) = 0;
      *(_OWORD *)(a1 + 120) = 0;
      *(_OWORD *)(a1 + 136) = 0;
      *(_QWORD *)(a1 + 152) = 0;
      v3 = *(_QWORD *)(a1 + 24);
      v4 = *(_QWORD **)v3;
      if ( *(_QWORD *)(*(_QWORD *)v3 + 80LL) != 0 )
      {
        if ( __eh34_unwind(20) )
          goto unwind_state_20;
        __eh34_exit_wind_state(20, 17);
        if ( __eh34_unwind(17) )
          goto unwind_state_17;
        __eh34_exit_wind_state(17, 5);
        if ( __eh34_unwind(5) )
          goto unwind_state_5;
        __eh34_exit_wind_state(5, 4);
        if ( __eh34_unwind(4) )
          goto unwind_state_4;
        __eh34_exit_wind_state(4, 3);
        if ( __eh34_unwind(3) )
          goto unwind_state_3;
        __eh34_exit_wind_state(3, 2);
        if ( __eh34_unwind(2) )
          goto unwind_state_2;
        __eh34_exit_wind_state(2, 0);
        __eh34_enter_wind_state(0, 1);
        v5 = v4[9];
        *(_QWORD *)(v1 + 128) = v5;
        *(_QWORD *)(v1 + 144) = v4[11];
        v298 = (void (__fastcall **)(__int64))v5;
        (*(void (__fastcall **)(__int64, _QWORD *))(v5 + 8))(a1: v1 + 104, a2: v4 + 6);
      }
      else
      {
        if ( __eh34_unwind(20) )
        {
unwind_state_20:
          v325 = a1 + 1912;
          sub_140037060(a1: a1 + 1912);
          __eh34_continue_unwinding(20, 17);
        }
        __eh34_exit_wind_state(20, 17);
        if ( __eh34_unwind(17) )
        {
unwind_state_17:
          v322 = a1 + 1784;
          unknown_libname_4(a1: (void *)(a1 + 1784));
          __eh34_continue_unwinding(17, 5);
        }
        __eh34_exit_wind_state(17, 5);
        if ( __eh34_unwind(5) )
        {
unwind_state_5:
          v307 = a1 + 768;
          sub_14003A350(a1: a1 + 768);
          __eh34_continue_unwinding(5, 4);
        }
        __eh34_exit_wind_state(5, 4);
        if ( __eh34_unwind(4) )
        {
unwind_state_4:
          v306 = a1 + 192;
          sub_14003A350(a1: a1 + 192);
          __eh34_continue_unwinding(4, 3);
        }
        __eh34_exit_wind_state(4, 3);
        if ( __eh34_unwind(3) )
        {
unwind_state_3:
          v305 = a1 + 160;
          sub_1400371B0(a1: a1 + 160);
          __eh34_continue_unwinding(3, 2);
        }
        __eh34_exit_wind_state(3, 2);
        if ( __eh34_unwind(2) )
        {
unwind_state_2:
          v304 = a1 + 104;
          sub_140038710(a1: a1 + 104);
          __eh34_continue_unwinding(2, 0);
        }
        __eh34_exit_wind_state(2, 0);
        __eh34_enter_wind_state(0, 1);
        *(_QWORD *)(a1 + 128) = 0;
        *(_QWORD *)(a1 + 136) = 0;
        *(_QWORD *)(a1 + 144) = 0;
      }
      if ( __eh34_unwind(1) )
unwind_state_1:
        terminate();
      __eh34_exit_wind_state(1, 0);
      __eh34_enter_wind_state(0, 2);
      *(_QWORD *)(v1 + 152) = v4[12];
      v6 = (char *)(v1 + 160);
      Size = v1 + 160;
      sub_14007EAF0(a1: v1 + 160, a2: *(_QWORD *)(v1 + 65), a3: 0);
      *(_QWORD *)(v1 + 208) = 0;
      *(_QWORD *)(v1 + 216) = 0;
      *(_QWORD *)(v1 + 224) = 0;
      *(_QWORD *)(v1 + 232) = 0;
      *(_QWORD *)(v1 + 240) = 0;
      memset(a1: (void *)(v1 + 248), Val: 0, Size: 0x200u);
      *(_BYTE *)(v1 + 768) = 0;
      *(_WORD *)(v1 + 769) = 0;
      *(_QWORD *)(v1 + 771) = 0;
      *(_QWORD *)(v1 + 784) = 0;
      *(_OWORD *)(v1 + 792) = 0;
      *(_QWORD *)(v1 + 792) = 0;
      *(_QWORD *)(v1 + 800) = 0;
      *(_QWORD *)(v1 + 808) = 0;
      *(_QWORD *)(v1 + 816) = 0;
      memset(a1: (void *)(v1 + 824), Val: 0, Size: 0x200u);
      __eh34_enter_wind_state(2, 3);
      __eh34_enter_wind_state(3, 4);
      __eh34_enter_wind_state(4, 5);
      if ( *(_QWORD *)(v1 + 81) == 0 )
      {
        v7 = *(_QWORD *)(v1 + 176);
        Sizea = v7;
        v283 = v7;
        v283 = *(_QWORD *)(v1 + 176);
        if ( 0x7FFFFFFFFFFFFFFFLL - v283 < 0x1A )
          unknown_libname_3();
        v284 = *(_QWORD *)(v1 + 184);
        if ( v284 >= 0x10 )
        {
          v6 = *(char **)(v1 + 160);
          v282 = v6;
        }
        v8 = (void **)(v1 + 1344);
        *(_OWORD *)(v1 + 1344) = 0;
        *(_QWORD *)(v1 + 1360) = 0;
        *(_QWORD *)(v1 + 1368) = 0;
        v283 = *(_QWORD *)(v1 + 176);
        v9 = v283 + 26;
        v260 = v283 + 26;
        v10 = 15;
        v11 = (_QWORD *)(v1 + 1344);
        if ( v283 + 26 > 0xF )
        {
          v12 = (__int64 *)(v1 + 3496);
          *(_QWORD *)(v1 + 3496) = v9 | 0xF;
          if ( (v9 | 0xF) <= 0x7FFFFFFFFFFFFFFFLL )
          {
            *(_QWORD *)(v1 + 3504) = 22;
            v296 = v9 | 0xF;
            if ( (v9 | 0xF) < 0x16 )
              v12 = (__int64 *)(v1 + 3504);
            v10 = *v12;
          }
          else
          {
            v10 = 0x7FFFFFFFFFFFFFFFLL;
          }
          v13 = v10 + 1;
          if ( v10 == -1 )
            v13 = -1;
          if ( v13 < 0x1000 )
          {
            if ( v13 != 0 )
            {
              v11 = operator new(Size: v13);
              v9 = v260;
              v7 = Sizea;
            }
            else
            {
              v11 = nullptr;
            }
          }
          else
          {
            if ( v13 + 39 < v13 )
              sub_140035990();
            v14 = operator new(Size: v13 + 39);
            if ( v14 == nullptr )
LABEL_38:
              invalid_parameter_noinfo_noreturn();
            v11 = (_QWORD *)(((unsigned __int64)v14 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *(v11 - 1) = v14;
            v9 = v260;
            v7 = Sizea;
          }
          *v8 = v11;
        }
        *(_QWORD *)(v1 + 1360) = v9;
        *(_QWORD *)(v1 + 1368) = v10;
        qmemcpy(v11, "Crypt context not found! (", 26);
        memmove(a1: (char *)v11 + 26, Src: v6, Size: v7);
        *((_BYTE *)v11 + v260) = 0;
        __wind
        {
          v15 = sub_140037430(Src: (void *)(v1 + 1344));
          v16 = (void **)(v1 + 1376);
          *(_OWORD *)(v1 + 1376) = 0;
          *(_QWORD *)(v1 + 1392) = 0;
          *(_QWORD *)(v1 + 1400) = 0;
          *(_OWORD *)(v1 + 1376) = *(_OWORD *)v15;
          *(_OWORD *)(v1 + 1392) = *(_OWORD *)(v15 + 16);
          *(_QWORD *)(v15 + 16) = 0;
          *(_QWORD *)(v15 + 24) = 15;
          *(_BYTE *)v15 = 0;
          __wind
          {
            if ( qword_140102188 != 0 )
            {
              sub_140040440(a1: qword_140102188, a2: 4, a3: v1 + 1376);
              if ( qword_140102188 != 0 )
                (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
            }
          }
          __unwind
          {
            v309 = a1 + 1376;
            sub_1400371B0(a1: a1 + 1376);
          }
          if ( *(_QWORD *)(v1 + 1400) >= 0x10u )
          {
            v17 = *v16;
            if ( (unsigned __int64)(*(_QWORD *)(v1 + 1400) + 1LL) >= 0x1000 )
            {
              v17 = *((_BYTE **)*v16 - 1);
              if ( (unsigned __int64)((_BYTE *)*v16 - v17 - 8) > 0x1F )
                invalid_parameter_noinfo_noreturn();
            }
            j_j_free(Block: v17);
          }
        }
        __unwind
        {
          v308 = a1 + 1344;
          sub_1400371B0(a1: a1 + 1344);
        }
        *(_QWORD *)(v1 + 1392) = 0;
        *(_QWORD *)(v1 + 1400) = 15;
        *(_BYTE *)v16 = 0;
        if ( *(_QWORD *)(v1 + 1368) >= 0x10u )
        {
          v18 = *v8;
          if ( (unsigned __int64)(*(_QWORD *)(v1 + 1368) + 1LL) >= 0x1000 )
          {
            v18 = *((_BYTE **)*v8 - 1);
            if ( (unsigned __int64)((_BYTE *)*v8 - v18 - 8) > 0x1F )
              goto LABEL_38;
          }
          j_j_free(Block: v18);
        }
        v281 = *(volatile signed __int32 **)(v1 + 800);
        if ( v281 != nullptr )
        {
          v19 = *(volatile signed __int32 **)(v1 + 800);
          v281 = v19;
          v281 = *(volatile signed __int32 **)(v1 + 800);
          if ( _InterlockedExchangeAdd(v281 + 2, 0xFFFFFFFF) == 1 )
          {
            (**(void (__fastcall ***)(volatile signed __int32 *))v19)(a1: v19);
            if ( _InterlockedExchangeAdd(v19 + 3, 0xFFFFFFFF) == 1 )
              (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v19 + 8LL))(a1: v19);
          }
        }
        v277 = *(volatile signed __int32 **)(v1 + 224);
        if ( v277 != nullptr )
        {
          v20 = *(volatile signed __int32 **)(v1 + 224);
          v277 = v20;
          v277 = *(volatile signed __int32 **)(v1 + 224);
          if ( _InterlockedExchangeAdd(v277 + 2, 0xFFFFFFFF) == 1 )
          {
            (**(void (__fastcall ***)(volatile signed __int32 *))v20)(a1: v20);
            if ( _InterlockedExchangeAdd(v20 + 3, 0xFFFFFFFF) == 1 )
              (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v20 + 8LL))(a1: v20);
          }
        }
        v284 = *(_QWORD *)(v1 + 184);
        if ( v284 < 0x10 )
          goto LABEL_894;
        v284 = *(_QWORD *)(v1 + 184);
        v21 = *(char **)(v1 + 160);
        v282 = v21;
        if ( v284 + 1 < 0x1000
          || (v282 = *(char **)(v1 + 160),
              v21 = *((char **)v282 - 1),
              (unsigned __int64)((v282 = *(char **)(v1 + 160)) - v21 - 8) <= 0x1F) )
        {
          j_j_free(Block: v21);
          if ( __eh34_unwind(5) )
            goto unwind_state_5;
LABEL_894:
          __eh34_exit_wind_state(5, 4);
          if ( __eh34_unwind(4) )
            goto unwind_state_4;
          __eh34_exit_wind_state(4, 3);
          if ( __eh34_unwind(3) )
            goto unwind_state_3;
          __eh34_exit_wind_state(3, 2);
          if ( __eh34_unwind(2) )
            goto unwind_state_2;
          __eh34_exit_wind_state(2, 0);
          __eh34_enter_wind_state(0, 1);
          *(_QWORD *)(v1 + 176) = 0;
          *(_QWORD *)(v1 + 184) = 15;
          *(_BYTE *)(v1 + 160) = 0;
          v299 = *(_QWORD *)(v1 + 136);
          if ( v299 != 0 )
          {
            v298 = *(void (__fastcall ***)(__int64))(v1 + 128);
            (*v298)(a1: v1 + 104);
          }
          v22 = v264;
          goto LABEL_899;
        }
LABEL_299:
        invalid_parameter_noinfo_noreturn();
      }
      v23 = *(_BYTE *)(v1 + 93);
      v24 = *(const WCHAR **)(v1 + 65);
      v25 = v24;
      if ( *((_QWORD *)v24 + 3) >= 8u )
        v25 = *(const WCHAR **)v24;
      FileAttributesW = GetFileAttributesW(lpFileName: v25);
      if ( FileAttributesW != -1 && (FileAttributesW & 1) != 0 )
      {
        v27 = v24;
        if ( *((_QWORD *)v24 + 3) >= 8u )
          v27 = *(const WCHAR **)v24;
        SetFileAttributesW(lpFileName: v27, dwFileAttributes: FileAttributesW ^ 1);
      }
      v28 = 0;
      if ( v23 == 0 )
        v28 = 3;
      v29 = v24;
      if ( *((_QWORD *)v24 + 3) >= 8u )
        v29 = *(const WCHAR **)v24;
      FileW = CreateFileW(
                lpFileName: v29,
                dwDesiredAccess: 0xC0010000,
                dwShareMode: v28,
                lpSecurityAttributes: nullptr,
                dwCreationDisposition: 3u,
                dwFlagsAndAttributes: 0x40000080u,
                hTemplateFile: nullptr);
      LastError = GetLastError();
      if ( FileW == (HANDLE)-1LL )
      {
        if ( v23 != 0 || LastError - 32 > 1 )
          goto LABEL_73;
        if ( (unsigned __int8)sub_140078CC0(a1: v24) != 0 )
        {
          if ( *((_QWORD *)v24 + 3) >= 8u )
            v24 = *(const WCHAR **)v24;
          FileW = CreateFileW(
                    lpFileName: v24,
                    dwDesiredAccess: 0xC0000000,
                    dwShareMode: 3u,
                    lpSecurityAttributes: nullptr,
                    dwCreationDisposition: 3u,
                    dwFlagsAndAttributes: 0x40000080u,
                    hTemplateFile: nullptr);
          if ( FileW == (HANDLE)-1LL )
LABEL_73:
            FileW = nullptr;
        }
      }
      *(_QWORD *)(v1 + 208) = FileW;
      if ( FileW == nullptr )
      {
        v32 = *(_QWORD *)(v1 + 176);
        Sizeb = v32;
        v283 = v32;
        v283 = *(_QWORD *)(v1 + 176);
        if ( 0x7FFFFFFFFFFFFFFFLL - v283 < 0x18 )
          unknown_libname_3();
        v284 = *(_QWORD *)(v1 + 184);
        if ( v284 >= 0x10 )
        {
          v6 = *(char **)(v1 + 160);
          v282 = v6;
        }
        v33 = (void **)(v1 + 1408);
        *(_OWORD *)(v1 + 1408) = 0;
        *(_QWORD *)(v1 + 1424) = 0;
        *(_QWORD *)(v1 + 1432) = 0;
        v283 = *(_QWORD *)(v1 + 176);
        v34 = v283 + 24;
        v261 = v283 + 24;
        v35 = 15;
        v36 = (_QWORD *)(v1 + 1408);
        if ( v283 + 24 > 0xF )
        {
          v37 = (__int64 *)(v1 + 3512);
          *(_QWORD *)(v1 + 3512) = v34 | 0xF;
          if ( (v34 | 0xF) <= 0x7FFFFFFFFFFFFFFFLL )
          {
            *(_QWORD *)(v1 + 3520) = 22;
            v296 = v34 | 0xF;
            if ( (v34 | 0xF) < 0x16 )
              v37 = (__int64 *)(v1 + 3520);
            v35 = *v37;
          }
          else
          {
            v35 = 0x7FFFFFFFFFFFFFFFLL;
          }
          v38 = v35 + 1;
          if ( v35 == -1 )
            v38 = -1;
          if ( v38 < 0x1000 )
          {
            if ( v38 != 0 )
            {
              v36 = operator new(Size: v38);
              v34 = v261;
              v32 = Sizeb;
            }
            else
            {
              v36 = nullptr;
            }
          }
          else
          {
            if ( v38 + 39 < v38 )
              sub_140035990();
            v39 = operator new(Size: v38 + 39);
            if ( v39 == nullptr )
LABEL_108:
              invalid_parameter_noinfo_noreturn();
            v36 = (_QWORD *)(((unsigned __int64)v39 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *(v36 - 1) = v39;
            v34 = v261;
            v32 = Sizeb;
          }
          *v33 = v36;
        }
        *(_QWORD *)(v1 + 1424) = v34;
        *(_QWORD *)(v1 + 1432) = v35;
        qmemcpy(v36, "File handle not found! (", 24);
        memmove(a1: v36 + 3, Src: v6, Size: v32);
        *((_BYTE *)v36 + v261) = 0;
        __wind
        {
          v40 = sub_140037430(Src: (void *)(v1 + 1408));
          v41 = (void **)(v1 + 1440);
          *(_OWORD *)(v1 + 1440) = 0;
          *(_QWORD *)(v1 + 1456) = 0;
          *(_QWORD *)(v1 + 1464) = 0;
          *(_OWORD *)(v1 + 1440) = *(_OWORD *)v40;
          *(_OWORD *)(v1 + 1456) = *(_OWORD *)(v40 + 16);
          *(_QWORD *)(v40 + 16) = 0;
          *(_QWORD *)(v40 + 24) = 15;
          *(_BYTE *)v40 = 0;
          __wind
          {
            if ( qword_140102188 != 0 )
            {
              sub_140040440(a1: qword_140102188, a2: 4, a3: v1 + 1440);
              if ( qword_140102188 != 0 )
                (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
            }
          }
          __unwind
          {
            v311 = a1 + 1440;
            sub_1400371B0(a1: a1 + 1440);
          }
          if ( *(_QWORD *)(v1 + 1464) >= 0x10u )
          {
            v42 = *v41;
            if ( (unsigned __int64)(*(_QWORD *)(v1 + 1464) + 1LL) >= 0x1000 )
            {
              v42 = *((_BYTE **)*v41 - 1);
              if ( (unsigned __int64)((_BYTE *)*v41 - v42 - 8) > 0x1F )
                invalid_parameter_noinfo_noreturn();
            }
            j_j_free(Block: v42);
          }
        }
        __unwind
        {
          v310 = a1 + 1408;
          sub_1400371B0(a1: a1 + 1408);
        }
        *(_QWORD *)(v1 + 1456) = 0;
        *(_QWORD *)(v1 + 1464) = 15;
        *(_BYTE *)v41 = 0;
        if ( *(_QWORD *)(v1 + 1432) >= 0x10u )
        {
          v43 = *v33;
          if ( (unsigned __int64)(*(_QWORD *)(v1 + 1432) + 1LL) >= 0x1000 )
          {
            v43 = *((_BYTE **)*v33 - 1);
            if ( (unsigned __int64)((_BYTE *)*v33 - v43 - 8) > 0x1F )
              goto LABEL_108;
          }
          j_j_free(Block: v43);
        }
        v281 = *(volatile signed __int32 **)(v1 + 800);
        if ( v281 != nullptr )
        {
          v44 = *(volatile signed __int32 **)(v1 + 800);
          v281 = v44;
          v281 = *(volatile signed __int32 **)(v1 + 800);
          if ( _InterlockedExchangeAdd(v281 + 2, 0xFFFFFFFF) == 1 )
          {
            (**(void (__fastcall ***)(volatile signed __int32 *))v44)(a1: v44);
            if ( _InterlockedExchangeAdd(v44 + 3, 0xFFFFFFFF) == 1 )
              (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v44 + 8LL))(a1: v44);
          }
        }
        v277 = *(volatile signed __int32 **)(v1 + 224);
        if ( v277 != nullptr )
        {
          v45 = *(volatile signed __int32 **)(v1 + 224);
          v277 = v45;
          v277 = *(volatile signed __int32 **)(v1 + 224);
          if ( _InterlockedExchangeAdd(v277 + 2, 0xFFFFFFFF) == 1 )
          {
            (**(void (__fastcall ***)(volatile signed __int32 *))v45)(a1: v45);
            if ( _InterlockedExchangeAdd(v45 + 3, 0xFFFFFFFF) == 1 )
              (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v45 + 8LL))(a1: v45);
          }
        }
        v284 = *(_QWORD *)(v1 + 184);
        if ( v284 >= 0x10 )
        {
          v284 = *(_QWORD *)(v1 + 184);
          v46 = *(char **)(v1 + 160);
          v282 = v46;
          if ( v284 + 1 >= 0x1000 )
          {
            v282 = *(char **)(v1 + 160);
            v46 = *((char **)v282 - 1);
            v282 = *(char **)(v1 + 160);
            if ( (unsigned __int64)(v282 - v46 - 8) > 0x1F )
              goto LABEL_299;
          }
          j_j_free(Block: v46);
        }
        if ( __eh34_unwind(5) )
          goto unwind_state_5;
        __eh34_exit_wind_state(5, 4);
        if ( __eh34_unwind(4) )
          goto unwind_state_4;
        __eh34_exit_wind_state(4, 3);
        if ( __eh34_unwind(3) )
          goto unwind_state_3;
        __eh34_exit_wind_state(3, 2);
        if ( __eh34_unwind(2) )
          goto unwind_state_2;
        __eh34_exit_wind_state(2, 0);
        __eh34_enter_wind_state(0, 1);
        *(_QWORD *)(v1 + 176) = 0;
        *(_QWORD *)(v1 + 184) = 15;
        *(_BYTE *)(v1 + 160) = 0;
        v299 = *(_QWORD *)(v1 + 136);
        if ( v299 != 0 )
        {
          v298 = *(void (__fastcall ***)(__int64))(v1 + 128);
          (*v298)(a1: v1 + 104);
        }
        v22 = v264;
        if ( __eh34_unwind(1) )
          goto unwind_state_1;
LABEL_899:
        __eh34_exit_wind_state(1, 0);
        goto LABEL_901;
      }
      *(_QWORD *)(v1 + 1472) = 0;
      if ( !GetFileSizeEx(hFile: FileW, lpFileSize: (PLARGE_INTEGER)(v1 + 1472)) )
      {
        v47 = *(_QWORD *)(v1 + 176);
        Sizec = v47;
        v283 = v47;
        v283 = *(_QWORD *)(v1 + 176);
        if ( 0x7FFFFFFFFFFFFFFFLL - v283 < 0x17 )
          unknown_libname_3();
        v284 = *(_QWORD *)(v1 + 184);
        if ( v284 >= 0x10 )
        {
          v6 = *(char **)(v1 + 160);
          v282 = v6;
        }
        v48 = (void **)(v1 + 1480);
        *(_OWORD *)(v1 + 1480) = 0;
        *(_QWORD *)(v1 + 1496) = 0;
        *(_QWORD *)(v1 + 1504) = 0;
        v283 = *(_QWORD *)(v1 + 176);
        v49 = v283 + 23;
        v262 = v283 + 23;
        v50 = 15;
        v51 = (_QWORD *)(v1 + 1480);
        if ( v283 + 23 > 0xF )
        {
          v52 = (__int64 *)(v1 + 3528);
          *(_QWORD *)(v1 + 3528) = v49 | 0xF;
          if ( (v49 | 0xF) <= 0x7FFFFFFFFFFFFFFFLL )
          {
            *(_QWORD *)(v1 + 3536) = 22;
            v296 = v49 | 0xF;
            if ( (v49 | 0xF) < 0x16 )
              v52 = (__int64 *)(v1 + 3536);
            v50 = *v52;
          }
          else
          {
            v50 = 0x7FFFFFFFFFFFFFFFLL;
          }
          v53 = v50 + 1;
          if ( v50 == -1 )
            v53 = -1;
          if ( v53 < 0x1000 )
          {
            if ( v53 != 0 )
            {
              v51 = operator new(Size: v53);
              v49 = v262;
              v47 = Sizec;
            }
            else
            {
              v51 = nullptr;
            }
          }
          else
          {
            if ( v53 + 39 < v53 )
              sub_140035990();
            v54 = operator new(Size: v53 + 39);
            if ( v54 == nullptr )
LABEL_159:
              invalid_parameter_noinfo_noreturn();
            v51 = (_QWORD *)(((unsigned __int64)v54 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *(v51 - 1) = v54;
            v49 = v262;
            v47 = Sizec;
          }
          *v48 = v51;
        }
        *(_QWORD *)(v1 + 1496) = v49;
        *(_QWORD *)(v1 + 1504) = v50;
        qmemcpy(v51, "Get file size failed! (", 23);
        memmove(a1: (char *)v51 + 23, Src: v6, Size: v47);
        *((_BYTE *)v51 + v262) = 0;
        __wind
        {
          v55 = sub_140037430(Src: (void *)(v1 + 1480));
          v56 = (void **)(v1 + 1512);
          *(_OWORD *)(v1 + 1512) = 0;
          *(_QWORD *)(v1 + 1528) = 0;
          *(_QWORD *)(v1 + 1536) = 0;
          *(_OWORD *)(v1 + 1512) = *(_OWORD *)v55;
          *(_OWORD *)(v1 + 1528) = *(_OWORD *)(v55 + 16);
          *(_QWORD *)(v55 + 16) = 0;
          *(_QWORD *)(v55 + 24) = 15;
          *(_BYTE *)v55 = 0;
          __wind
          {
            if ( qword_140102188 != 0 )
            {
              sub_140040440(a1: qword_140102188, a2: 4, a3: v1 + 1512);
              if ( qword_140102188 != 0 )
                (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
            }
          }
          __unwind
          {
            v313 = a1 + 1512;
            sub_1400371B0(a1: a1 + 1512);
          }
          if ( *(_QWORD *)(v1 + 1536) >= 0x10u )
          {
            v57 = *v56;
            if ( (unsigned __int64)(*(_QWORD *)(v1 + 1536) + 1LL) >= 0x1000 )
            {
              v57 = *((_BYTE **)*v56 - 1);
              if ( (unsigned __int64)((_BYTE *)*v56 - v57 - 8) > 0x1F )
                invalid_parameter_noinfo_noreturn();
            }
            j_j_free(Block: v57);
          }
        }
        __unwind
        {
          v312 = a1 + 1480;
          sub_1400371B0(a1: a1 + 1480);
        }
        *(_QWORD *)(v1 + 1528) = 0;
        *(_QWORD *)(v1 + 1536) = 15;
        *(_BYTE *)v56 = 0;
        if ( *(_QWORD *)(v1 + 1504) >= 0x10u )
        {
          v58 = *v48;
          if ( (unsigned __int64)(*(_QWORD *)(v1 + 1504) + 1LL) >= 0x1000 )
          {
            v58 = *((_BYTE **)*v48 - 1);
            if ( (unsigned __int64)((_BYTE *)*v48 - v58 - 8) > 0x1F )
              goto LABEL_159;
          }
          j_j_free(Block: v58);
        }
        v275 = *(HANDLE *)(v1 + 208);
        CloseHandle(hObject: v275);
        v281 = *(volatile signed __int32 **)(v1 + 800);
        if ( v281 != nullptr )
        {
          v59 = *(volatile signed __int32 **)(v1 + 800);
          v281 = v59;
          v281 = *(volatile signed __int32 **)(v1 + 800);
          if ( _InterlockedExchangeAdd(v281 + 2, 0xFFFFFFFF) == 1 )
          {
            (**(void (__fastcall ***)(volatile signed __int32 *))v59)(a1: v59);
            if ( _InterlockedExchangeAdd(v59 + 3, 0xFFFFFFFF) == 1 )
              (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v59 + 8LL))(a1: v59);
          }
        }
        v277 = *(volatile signed __int32 **)(v1 + 224);
        if ( v277 != nullptr )
        {
          v60 = *(volatile signed __int32 **)(v1 + 224);
          v277 = v60;
          v277 = *(volatile signed __int32 **)(v1 + 224);
          if ( _InterlockedExchangeAdd(v277 + 2, 0xFFFFFFFF) == 1 )
          {
            (**(void (__fastcall ***)(volatile signed __int32 *))v60)(a1: v60);
            if ( _InterlockedExchangeAdd(v60 + 3, 0xFFFFFFFF) == 1 )
              (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v60 + 8LL))(a1: v60);
          }
        }
        v284 = *(_QWORD *)(v1 + 184);
        if ( v284 >= 0x10 )
        {
          v284 = *(_QWORD *)(v1 + 184);
          v61 = *(char **)(v1 + 160);
          v282 = v61;
          if ( v284 + 1 >= 0x1000 )
          {
            v282 = *(char **)(v1 + 160);
            v61 = *((char **)v282 - 1);
            v282 = *(char **)(v1 + 160);
            if ( (unsigned __int64)(v282 - v61 - 8) > 0x1F )
              goto LABEL_299;
          }
          j_j_free(Block: v61);
        }
        if ( __eh34_unwind(5) )
          goto unwind_state_5;
        __eh34_exit_wind_state(5, 4);
        if ( __eh34_unwind(4) )
          goto unwind_state_4;
        __eh34_exit_wind_state(4, 3);
        if ( __eh34_unwind(3) )
          goto unwind_state_3;
        __eh34_exit_wind_state(3, 2);
        if ( __eh34_unwind(2) )
          goto unwind_state_2;
        __eh34_exit_wind_state(2, 0);
        __eh34_enter_wind_state(0, 1);
        *(_QWORD *)(v1 + 176) = 0;
        *(_QWORD *)(v1 + 184) = 15;
        *(_BYTE *)(v1 + 160) = 0;
        v299 = *(_QWORD *)(v1 + 136);
        if ( v299 != 0 )
        {
          v298 = *(void (__fastcall ***)(__int64))(v1 + 128);
          (*v298)(a1: v1 + 104);
        }
        v22 = v264;
        goto LABEL_899;
      }
      v295 = *(_QWORD *)(v1 + 1472);
      if ( v295 == 0 )
      {
        v62 = *(_QWORD *)(v1 + 176);
        Sized = v62;
        v283 = v62;
        v283 = *(_QWORD *)(v1 + 176);
        if ( 0x7FFFFFFFFFFFFFFFLL - v283 < 0x14 )
          unknown_libname_3();
        v284 = *(_QWORD *)(v1 + 184);
        if ( v284 >= 0x10 )
        {
          v6 = *(char **)(v1 + 160);
          v282 = v6;
        }
        v63 = (void **)(v1 + 1544);
        *(_OWORD *)(v1 + 1544) = 0;
        *(_QWORD *)(v1 + 1560) = 0;
        *(_QWORD *)(v1 + 1568) = 0;
        v283 = *(_QWORD *)(v1 + 176);
        v64 = v283 + 20;
        v263 = v283 + 20;
        v65 = 15;
        v66 = (_QWORD *)(v1 + 1544);
        if ( v283 + 20 > 0xF )
        {
          v67 = (__int64 *)(v1 + 3552);
          *(_QWORD *)(v1 + 3552) = v64 | 0xF;
          if ( (v64 | 0xF) <= 0x7FFFFFFFFFFFFFFFLL )
          {
            *(_QWORD *)(v1 + 3560) = 22;
            v296 = v64 | 0xF;
            if ( (v64 | 0xF) < 0x16 )
              v67 = (__int64 *)(v1 + 3560);
            v65 = *v67;
          }
          else
          {
            v65 = 0x7FFFFFFFFFFFFFFFLL;
          }
          v68 = v65 + 1;
          if ( v65 == -1 )
            v68 = -1;
          if ( v68 < 0x1000 )
          {
            if ( v68 != 0 )
            {
              v66 = operator new(Size: v68);
              v64 = v263;
              v62 = Sized;
            }
            else
            {
              v66 = nullptr;
            }
          }
          else
          {
            if ( v68 + 39 < v68 )
              sub_140035990();
            v69 = operator new(Size: v68 + 39);
            if ( v69 == nullptr )
LABEL_210:
              invalid_parameter_noinfo_noreturn();
            v66 = (_QWORD *)(((unsigned __int64)v69 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *(v66 - 1) = v69;
            v64 = v263;
            v62 = Sized;
          }
          *v63 = v66;
        }
        *(_QWORD *)(v1 + 1560) = v64;
        *(_QWORD *)(v1 + 1568) = v65;
        qmemcpy(v66, "File size invalid! (", 20);
        memmove(a1: (char *)v66 + 20, Src: v6, Size: v62);
        *((_BYTE *)v66 + v263) = 0;
        __wind
        {
          v70 = sub_140037430(Src: (void *)(v1 + 1544));
          v71 = (void **)(v1 + 1576);
          *(_OWORD *)(v1 + 1576) = 0;
          *(_QWORD *)(v1 + 1592) = 0;
          *(_QWORD *)(v1 + 1600) = 0;
          *(_OWORD *)(v1 + 1576) = *(_OWORD *)v70;
          *(_OWORD *)(v1 + 1592) = *(_OWORD *)(v70 + 16);
          *(_QWORD *)(v70 + 16) = 0;
          *(_QWORD *)(v70 + 24) = 15;
          *(_BYTE *)v70 = 0;
          __wind
          {
            if ( qword_140102188 != 0 )
            {
              sub_140040440(a1: qword_140102188, a2: 4, a3: v1 + 1576);
              if ( qword_140102188 != 0 )
                (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
            }
          }
          __unwind
          {
            v315 = a1 + 1576;
            sub_1400371B0(a1: a1 + 1576);
          }
          if ( *(_QWORD *)(v1 + 1600) >= 0x10u )
          {
            v72 = *v71;
            if ( (unsigned __int64)(*(_QWORD *)(v1 + 1600) + 1LL) >= 0x1000 )
            {
              v72 = *((_BYTE **)*v71 - 1);
              if ( (unsigned __int64)((_BYTE *)*v71 - v72 - 8) > 0x1F )
                invalid_parameter_noinfo_noreturn();
            }
            j_j_free(Block: v72);
          }
        }
        __unwind
        {
          v314 = a1 + 1544;
          sub_1400371B0(a1: a1 + 1544);
        }
        *(_QWORD *)(v1 + 1592) = 0;
        *(_QWORD *)(v1 + 1600) = 15;
        *(_BYTE *)v71 = 0;
        if ( *(_QWORD *)(v1 + 1568) >= 0x10u )
        {
          v73 = *v63;
          if ( (unsigned __int64)(*(_QWORD *)(v1 + 1568) + 1LL) >= 0x1000 )
          {
            v73 = *((_BYTE **)*v63 - 1);
            if ( (unsigned __int64)((_BYTE *)*v63 - v73 - 8) > 0x1F )
              goto LABEL_210;
          }
          j_j_free(Block: v73);
        }
        v275 = *(HANDLE *)(v1 + 208);
        CloseHandle(hObject: v275);
        v281 = *(volatile signed __int32 **)(v1 + 800);
        if ( v281 != nullptr )
        {
          v74 = *(volatile signed __int32 **)(v1 + 800);
          v281 = v74;
          v281 = *(volatile signed __int32 **)(v1 + 800);
          if ( _InterlockedExchangeAdd(v281 + 2, 0xFFFFFFFF) == 1 )
          {
            (**(void (__fastcall ***)(volatile signed __int32 *))v74)(a1: v74);
            if ( _InterlockedExchangeAdd(v74 + 3, 0xFFFFFFFF) == 1 )
              (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v74 + 8LL))(a1: v74);
          }
        }
        v277 = *(volatile signed __int32 **)(v1 + 224);
        if ( v277 != nullptr )
        {
          v75 = *(volatile signed __int32 **)(v1 + 224);
          v277 = v75;
          v277 = *(volatile signed __int32 **)(v1 + 224);
          if ( _InterlockedExchangeAdd(v277 + 2, 0xFFFFFFFF) == 1 )
          {
            (**(void (__fastcall ***)(volatile signed __int32 *))v75)(a1: v75);
            if ( _InterlockedExchangeAdd(v75 + 3, 0xFFFFFFFF) == 1 )
              (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v75 + 8LL))(a1: v75);
          }
        }
        v284 = *(_QWORD *)(v1 + 184);
        if ( v284 >= 0x10 )
        {
          v284 = *(_QWORD *)(v1 + 184);
          v76 = *(char **)(v1 + 160);
          v282 = v76;
          if ( v284 + 1 >= 0x1000 )
          {
            v282 = *(char **)(v1 + 160);
            v76 = *((char **)v282 - 1);
            v282 = *(char **)(v1 + 160);
            if ( (unsigned __int64)(v282 - v76 - 8) > 0x1F )
              goto LABEL_299;
          }
          j_j_free(Block: v76);
        }
        if ( __eh34_unwind(5) )
          goto unwind_state_5;
        __eh34_exit_wind_state(5, 4);
        if ( __eh34_unwind(4) )
          goto unwind_state_4;
        __eh34_exit_wind_state(4, 3);
        if ( __eh34_unwind(3) )
          goto unwind_state_3;
        __eh34_exit_wind_state(3, 2);
        if ( __eh34_unwind(2) )
          goto unwind_state_2;
        __eh34_exit_wind_state(2, 0);
        __eh34_enter_wind_state(0, 1);
        *(_QWORD *)(v1 + 176) = 0;
        *(_QWORD *)(v1 + 184) = 15;
        *(_BYTE *)(v1 + 160) = 0;
        v299 = *(_QWORD *)(v1 + 136);
        if ( v299 != 0 )
        {
          v298 = *(void (__fastcall ***)(__int64))(v1 + 128);
          (*v298)(a1: v1 + 104);
        }
        v22 = v264;
        goto LABEL_899;
      }
      try
      {
        v77 = operator new(Size: 0x70u);
        __wind
        {
          *(_QWORD *)(v1 + 3544) = v77;
          *v77 = 0;
          *(_DWORD *)(*(_QWORD *)(v1 + 3544) + 8LL) = 1;
          *(_DWORD *)(*(_QWORD *)(v1 + 3544) + 12LL) = 1;
          **(_QWORD **)(v1 + 3544) = &std::_Ref_count_obj2<asio::windows::basic_random_access_handle<asio::any_io_executor>>::`vftable';
          sub_140040B50(a1: *(_QWORD *)(v1 + 3544) + 16LL, a2: v1 + 104, a3: v1 + 208);
          *(_QWORD *)(v1 + 216) = *(_QWORD *)(v1 + 3544) + 16LL;
          v78 = *(volatile signed __int32 **)(v1 + 224);
          v277 = v78;
          v297 = v78;
          *(_QWORD *)(v1 + 224) = *(_QWORD *)(v1 + 3544);
          if ( v78 != nullptr && _InterlockedExchangeAdd(v78 + 2, 0xFFFFFFFF) == 1 )
          {
            (**(void (__fastcall ***)(volatile signed __int32 *))v78)(a1: v78);
            if ( _InterlockedExchangeAdd(v78 + 3, 0xFFFFFFFF) == 1 )
              (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v78 + 8LL))(a1: v78);
          }
          *(_BYTE *)(v1 + 1780) = 0;
          v295 = *(_QWORD *)(v1 + 1472);
          *(_QWORD *)(v1 + 232) = v295;
          v251 = 0;
          *(_OWORD *)(v1 + 1784) = 0;
          *(_QWORD *)(v1 + 1800) = 0;
          *(_QWORD *)(v1 + 1808) = 7;
          *(_WORD *)(v1 + 1784) = 0;
          if ( *(_BYTE *)(v1 + 73) != 0 )
          {
            *(_DWORD *)(v1 + 1776) = 0;
          }
          else
          {
            if ( *(_BYTE *)(v1 + 74) == 0 )
            {
              v295 = *(_QWORD *)(v1 + 1472);
              if ( v295 <= 2000000 )
              {
                *(_DWORD *)(v1 + 1776) = 1;
                *(_BYTE *)(v1 + 1780) = *(_BYTE *)(v1 + 89);
                goto LABEL_238;
              }
            }
            v79 = *(_BYTE *)(v1 + 89);
            *(_DWORD *)(v1 + 1776) = 2;
            *(_BYTE *)(v1 + 1780) = v79;
          }
          v251 = 1;
LABEL_238:
          *(_OWORD *)(v1 + 1816) = 0;
          *(_DWORD *)(v1 + 1816) = 0;
          *(_QWORD *)(v1 + 1824) = &off_1400F9FB0;
          perf_frequency = Query_perf_frequency();
          v81 = sub_140080F48();
          if ( perf_frequency == 10000000 )
            v82 = 100 * v81;
          else
            v82 = 1000000000 * (v81 % perf_frequency) / perf_frequency + 1000000000 * (v81 / perf_frequency);
        }
        __unwind
        {
          v316 = a1 + 3544;
          j_j_free(Block: *(void **)(a1 + 3544));
        }
      }
      catch ( std::exception *v272 )
      {
        v275 = *(HANDLE *)(a1 + 208);
        CloseHandle(hObject: v275);
        *(_QWORD *)(a1 + 1608) = (*(__int64 (__fastcall **)(std::exception *))(*(_QWORD *)v272 + 8LL))(a1: v272);
        v242 = sub_14003E680(a1: (void *)(a1 + 1616));
        __wind
        {
          v243 = sub_14003E3F0(a1: a1 + 1648, a2: "asio::random_access_handle error:", a3: v242);
          __wind
          {
            v244 = sub_14003E000(a1: a1 + 1680, a2: v243, a3: &unk_1400DC5FC);
            __wind
            {
              v245 = sub_14003E070(a1: a1 + 1712, a2: v244, a3: a1 + 160);
              __wind
              {
                v246 = sub_14003E000(a1: a1 + 1744, a2: v245, a3: &unk_1400DC5F8);
                __wind
                {
                  sub_140039EC0(a1: v247, a2: v246);
                }
                __unwind
                {
                  v321 = a1 + 1744;
                  sub_1400371B0(a1: a1 + 1744);
                }
                sub_1400371B0(a1: a1 + 1744);
                sub_1400371B0(a1: a1 + 1712);
                sub_1400371B0(a1: a1 + 1680);
                sub_1400371B0(a1: a1 + 1648);
                sub_1400371B0(a1: a1 + 1616);
              }
              __unwind
              {
                v320 = a1 + 1712;
                sub_1400371B0(a1: a1 + 1712);
              }
            }
            __unwind
            {
              v319 = a1 + 1680;
              sub_1400371B0(a1: a1 + 1680);
            }
          }
          __unwind
          {
            v318 = a1 + 1648;
            sub_1400371B0(a1: a1 + 1648);
          }
        }
        __unwind
        {
          v317 = a1 + 1616;
          sub_1400371B0(a1: a1 + 1616);
        }
        sub_14003A350(a1: v1 + 768);
        __eh34_enter_wind_state(5, 17);
        __eh34_enter_wind_state(17, 20);
        v1 = a1;
        sub_14003A350(a1: a1 + 192);
        sub_1400371B0(a1: Size);
        sub_140038710(a1: *(_QWORD *)dwBufferSize);
        v22 = v271;
LABEL_583:
        *(_QWORD *)(v1 + 3488) = v1 + 16;
        *v22 = 0;
        *(_QWORD *)v1 = 0;
        sub_140039F80();
        break;
      }
      __eh34_enter_wind_state(5, 17);
      *(_QWORD *)(v1 + 1832) = v82;
      *(_BYTE *)(v1 + 192) = 1;
      *(_BYTE *)(v1 + 193) = *(_DWORD *)(v1 + 1776);
      *(_BYTE *)(v1 + 194) = *(_BYTE *)(v1 + 1780);
      v278 = *(_QWORD *)(v1 + 232);
      *(_QWORD *)(v1 + 195) = v278;
      if ( (unsigned __int8)sub_140036740(a1: *(_QWORD *)(v1 + 81), a2: v1 + 192) == 0 )
      {
        v83 = *(_QWORD *)(v1 + 216);
        v276 = v83;
        if ( *(_QWORD *)(v83 + 8) != -1 )
        {
          if ( !CloseHandle(hObject: *(HANDLE *)(v83 + 8)) )
          {
            GetLastError();
            if ( dword_140101DC4 > *(_DWORD *)(*(_QWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + 8LL) )
            {
              Init_thread_header(a1: &dword_140101DC4);
              if ( dword_140101DC4 == -1 )
              {
                atexit(a1: nullsub_3);
                Init_thread_footer(a1: &dword_140101DC4);
              }
            }
          }
          *(_QWORD *)(v83 + 8) = -1;
          *(_DWORD *)(v83 + 16) = 0;
        }
        v84 = *(_QWORD *)(v1 + 176);
        v265 = v84;
        v283 = v84;
        v283 = *(_QWORD *)(v1 + 176);
        if ( 0x7FFFFFFFFFFFFFFFLL - v283 < 0x15 )
          unknown_libname_3();
        v284 = *(_QWORD *)(v1 + 184);
        if ( v284 >= 0x10 )
        {
          v6 = *(char **)(v1 + 160);
          v282 = v6;
        }
        __wind
        {
          v85 = (void **)(v1 + 1840);
          *(_OWORD *)(v1 + 1840) = 0;
          *(_QWORD *)(v1 + 1856) = 0;
          *(_QWORD *)(v1 + 1864) = 0;
          v283 = *(_QWORD *)(v1 + 176);
          v86 = v283 + 21;
          Sizee = v283 + 21;
          v87 = 15;
          v88 = (_QWORD *)(v1 + 1840);
          if ( v283 + 21 > 0xF )
          {
            v89 = (__int64 *)(v1 + 3568);
            *(_QWORD *)(v1 + 3568) = v86 | 0xF;
            if ( (v86 | 0xF) <= 0x7FFFFFFFFFFFFFFFLL )
            {
              *(_QWORD *)(v1 + 3576) = 22;
              v300 = v86 | 0xF;
              if ( (v86 | 0xF) < 0x16 )
                v89 = (__int64 *)(v1 + 3576);
              v87 = *v89;
            }
            else
            {
              v87 = 0x7FFFFFFFFFFFFFFFLL;
            }
            v90 = v87 + 1;
            if ( v87 == -1 )
              v90 = -1;
            if ( v90 < 0x1000 )
            {
              if ( v90 != 0 )
              {
                v88 = operator new(Size: v90);
                v86 = Sizee;
                v84 = v265;
              }
              else
              {
                v88 = nullptr;
              }
            }
            else
            {
              if ( v90 + 39 < v90 )
                sub_140035990();
              v91 = operator new(Size: v90 + 39);
              if ( v91 == nullptr )
LABEL_281:
                invalid_parameter_noinfo_noreturn();
              v88 = (_QWORD *)(((unsigned __int64)v91 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
              *(v88 - 1) = v91;
              v86 = Sizee;
              v84 = v265;
            }
            *v85 = v88;
          }
          *(_QWORD *)(v1 + 1856) = v86;
          *(_QWORD *)(v1 + 1864) = v87;
          qmemcpy(v88, "Init cipher failed! (", 21);
          memmove(a1: (char *)v88 + 21, Src: v6, Size: v84);
          *((_BYTE *)v88 + Sizee) = 0;
          v92 = sub_140037430(Src: (void *)(v1 + 1840));
          v93 = (void **)(v1 + 1872);
          *(_OWORD *)(v1 + 1872) = 0;
          *(_QWORD *)(v1 + 1888) = 0;
          *(_QWORD *)(v1 + 1896) = 0;
          *(_OWORD *)(v1 + 1872) = *(_OWORD *)v92;
          *(_OWORD *)(v1 + 1888) = *(_OWORD *)(v92 + 16);
          *(_QWORD *)(v92 + 16) = 0;
          *(_QWORD *)(v92 + 24) = 15;
          *(_BYTE *)v92 = 0;
          __wind
          {
            if ( qword_140102188 != 0 )
            {
              sub_140040440(a1: qword_140102188, a2: 4, a3: v1 + 1872);
              if ( qword_140102188 != 0 )
                (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
            }
          }
          __unwind
          {
            v324 = a1 + 1872;
            sub_1400371B0(a1: a1 + 1872);
          }
          if ( *(_QWORD *)(v1 + 1896) >= 0x10u )
          {
            v94 = *v93;
            if ( (unsigned __int64)(*(_QWORD *)(v1 + 1896) + 1LL) >= 0x1000 )
            {
              v94 = *((_BYTE **)*v93 - 1);
              if ( (unsigned __int64)((_BYTE *)*v93 - v94 - 8) > 0x1F )
                invalid_parameter_noinfo_noreturn();
            }
            j_j_free(Block: v94);
          }
          *(_QWORD *)(v1 + 1888) = 0;
          *(_QWORD *)(v1 + 1896) = 15;
          *(_BYTE *)v93 = 0;
          if ( *(_QWORD *)(v1 + 1864) >= 0x10u )
          {
            v95 = *v85;
            if ( (unsigned __int64)(*(_QWORD *)(v1 + 1864) + 1LL) >= 0x1000 )
            {
              v95 = *((_BYTE **)*v85 - 1);
              if ( (unsigned __int64)((_BYTE *)*v85 - v95 - 8) > 0x1F )
                goto LABEL_281;
            }
            j_j_free(Block: v95);
          }
          v291 = *(_QWORD *)(v1 + 1808);
          if ( v291 >= 8 )
          {
            v291 = *(_QWORD *)(v1 + 1808);
            v96 = *(char **)(v1 + 1784);
            v289 = v96;
            if ( 2 * v291 + 2 >= 0x1000 )
            {
              v289 = *(char **)(v1 + 1784);
              v96 = *((char **)v289 - 1);
              v289 = *(char **)(v1 + 1784);
              if ( (unsigned __int64)(v289 - v96 - 8) > 0x1F )
                invalid_parameter_noinfo_noreturn();
            }
            j_j_free(Block: v96);
          }
          *(_QWORD *)(v1 + 1800) = 0;
          *(_QWORD *)(v1 + 1808) = 7;
          *(_WORD *)(v1 + 1784) = 0;
          v281 = *(volatile signed __int32 **)(v1 + 800);
          if ( v281 != nullptr )
          {
            v97 = *(volatile signed __int32 **)(v1 + 800);
            v281 = v97;
            v281 = *(volatile signed __int32 **)(v1 + 800);
            if ( _InterlockedExchangeAdd(v281 + 2, 0xFFFFFFFF) == 1 )
            {
              (**(void (__fastcall ***)(volatile signed __int32 *))v97)(a1: v97);
              if ( _InterlockedExchangeAdd(v97 + 3, 0xFFFFFFFF) == 1 )
                (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v97 + 8LL))(a1: v97);
            }
          }
          v277 = *(volatile signed __int32 **)(v1 + 224);
          if ( v277 != nullptr )
          {
            v98 = *(volatile signed __int32 **)(v1 + 224);
            v277 = v98;
            v277 = *(volatile signed __int32 **)(v1 + 224);
            if ( _InterlockedExchangeAdd(v277 + 2, 0xFFFFFFFF) == 1 )
            {
              (**(void (__fastcall ***)(volatile signed __int32 *))v98)(a1: v98);
              if ( _InterlockedExchangeAdd(v98 + 3, 0xFFFFFFFF) == 1 )
                (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v98 + 8LL))(a1: v98);
            }
          }
        }
        __unwind
        {
          v323 = a1 + 1840;
          sub_1400371B0(a1: a1 + 1840);
        }
        if ( __eh34_unwind(17) )
          goto unwind_state_17;
        __eh34_exit_wind_state(17, 5);
        v284 = *(_QWORD *)(v1 + 184);
        if ( v284 >= 0x10 )
        {
          v284 = *(_QWORD *)(v1 + 184);
          v99 = *(char **)(v1 + 160);
          v282 = v99;
          if ( v284 + 1 >= 0x1000 )
          {
            v282 = *(char **)(v1 + 160);
            v99 = *((char **)v282 - 1);
            v282 = *(char **)(v1 + 160);
            if ( (unsigned __int64)(v282 - v99 - 8) > 0x1F )
              goto LABEL_299;
          }
          j_j_free(Block: v99);
        }
        if ( __eh34_unwind(5) )
          goto unwind_state_5;
        __eh34_exit_wind_state(5, 4);
        if ( __eh34_unwind(4) )
          goto unwind_state_4;
        __eh34_exit_wind_state(4, 3);
        if ( __eh34_unwind(3) )
          goto unwind_state_3;
        __eh34_exit_wind_state(3, 2);
        if ( __eh34_unwind(2) )
          goto unwind_state_2;
        __eh34_exit_wind_state(2, 0);
        __eh34_enter_wind_state(0, 1);
        *(_QWORD *)(v1 + 176) = 0;
        *(_QWORD *)(v1 + 184) = 15;
        *(_BYTE *)(v1 + 160) = 0;
        v299 = *(_QWORD *)(v1 + 136);
        if ( v299 != 0 )
        {
          v298 = *(void (__fastcall ***)(__int64))(v1 + 128);
          (*v298)(a1: v1 + 104);
        }
        v22 = v264;
        goto LABEL_899;
      }
      __eh34_enter_wind_state(17, 20);
      __eh34_enter_try_state(20, 21);
      *(_BYTE *)(v1 + 1904) = 0;
      *(_OWORD *)(v1 + 1912) = 0;
      *(_QWORD *)(v1 + 1912) = 0;
      *(_QWORD *)(v1 + 1920) = 0;
      *(_QWORD *)(v1 + 1928) = 0;
      v100 = *(_QWORD **)(v1 + 65);
      v101 = (_OWORD *)(v1 + 1936);
      v102 = v100[2];
      if ( v100[3] >= 8u )
        v100 = (_QWORD *)*v100;
      *v101 = 0;
      *(_QWORD *)(v1 + 1952) = 0;
      *(_QWORD *)(v1 + 1960) = 0;
      sub_14003EE60(a1: v1 + 1936, a2: v100, a3: v102);
      v103 = v1 + 1936;
      if ( *(_QWORD *)(v1 + 1960) >= 8u )
        v103 = *(_QWORD *)v101;
      v104 = (_WORD *)sub_1400382A0(a1: v103, a2: v103 + 2LL * *(_QWORD *)(v1 + 1952));
      if ( v104 != v106 )
      {
        do
        {
          if ( *v104 != 92 && *v104 != 47 )
            break;
          ++v104;
        }
        while ( v104 != v106 );
        if ( v104 != v106 )
        {
          do
          {
            v107 = (_WORD *)(v105 - 2);
            v108 = *(_WORD *)(v105 - 2);
            if ( v108 == 92 )
              break;
            if ( v108 == 47 )
              break;
            v105 -= 2;
          }
          while ( v104 != v107 );
        }
      }
      __eh34_enter_wind_state(21, 22);
      v109 = (void **)(v1 + 1968);
      *(_OWORD *)(v1 + 1968) = 0;
      *(_QWORD *)(v1 + 1984) = 0;
      *(_QWORD *)(v1 + 1992) = 0;
      sub_14003EE60(a1: v1 + 1968, a2: v105, a3: ((__int64)v106 - v105) >> 1);
      __eh34_enter_wind_state(22, 23);
      v110 = (void **)(v1 + 2000);
      sub_14003B400(a1: v1 + 2000, a2: v1 + 1968);
      __eh34_enter_wind_state(23, 24);
      sub_140036BF0(a1: v1 + 2032, a2: v1 + 2000);
      if ( *(_QWORD *)(v1 + 2024) >= 8u )
      {
        v111 = *v110;
        if ( (unsigned __int64)(2LL * *(_QWORD *)(v1 + 2024) + 2) >= 0x1000 )
        {
          v111 = *((_BYTE **)*v110 - 1);
          if ( (unsigned __int64)((_BYTE *)*v110 - v111 - 8) > 0x1F )
            invalid_parameter_noinfo_noreturn();
        }
        j_j_free(Block: v111);
      }
      *(_QWORD *)(v1 + 2016) = 0;
      *(_QWORD *)(v1 + 2024) = 7;
      *(_WORD *)v110 = 0;
      if ( *(_QWORD *)(v1 + 1992) >= 8u )
      {
        v112 = *v109;
        if ( (unsigned __int64)(2LL * *(_QWORD *)(v1 + 1992) + 2) >= 0x1000 )
        {
          v112 = *((_BYTE **)*v109 - 1);
          if ( (unsigned __int64)((_BYTE *)*v109 - v112 - 8) > 0x1F )
            invalid_parameter_noinfo_noreturn();
        }
        j_j_free(Block: v112);
      }
      if ( *(_QWORD *)(v1 + 1960) >= 8u )
      {
        v113 = *(void **)v101;
        if ( (unsigned __int64)(2LL * *(_QWORD *)(v1 + 1960) + 2) >= 0x1000 )
        {
          v113 = *(void **)(*(_QWORD *)v101 - 8LL);
          if ( (unsigned __int64)(*(_QWORD *)v101 - (_QWORD)v113 - 8LL) > 0x1F )
            invalid_parameter_noinfo_noreturn();
        }
        j_j_free(Block: v113);
      }
      *(_QWORD *)(v1 + 1952) = 0;
      *(_QWORD *)(v1 + 1960) = 7;
      *(_WORD *)v101 = 0;
      v293 = *(_QWORD *)(v1 + 2048);
      if ( v293 == 0 )
      {
        v114 = *(_QWORD *)(v1 + 216);
        v276 = v114;
        if ( *(_QWORD *)(v114 + 8) == -1 )
        {
          *(_DWORD *)(v1 + 3632) = 0;
          *(_QWORD *)(v1 + 3640) = &off_1400F9FB0;
          v116 = *(_OWORD *)(v1 + 3632);
        }
        else
        {
          if ( CloseHandle(hObject: *(HANDLE *)(v114 + 8)) )
          {
            *(_DWORD *)(v1 + 3616) = 0;
            *(_QWORD *)(v1 + 3624) = &off_1400F9FB0;
            v116 = *(_OWORD *)(v1 + 3616);
          }
          else
          {
            v115 = GetLastError();
            if ( dword_140101DC4 > *(_DWORD *)(*(_QWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + 8LL) )
            {
              Init_thread_header(a1: &dword_140101DC4);
              if ( dword_140101DC4 == -1 )
              {
                atexit(a1: nullsub_3);
                Init_thread_footer(a1: &dword_140101DC4);
              }
            }
            *(_DWORD *)(v1 + 3600) = v115;
            *(_QWORD *)(v1 + 3608) = &off_1400F9FA0;
            v116 = *(_OWORD *)(v1 + 3600);
          }
          *(_QWORD *)(v114 + 8) = -1;
          *(_DWORD *)(v114 + 16) = 0;
        }
        if ( __eh34_unwind(24) )
          goto unwind_state_24;
        __eh34_exit_wind_state(24, 23);
        if ( __eh34_unwind(23) )
          goto unwind_state_23;
        __eh34_exit_wind_state(23, 22);
        if ( __eh34_unwind(22) )
          goto unwind_state_22;
        __eh34_exit_wind_state(22, 21);
        __eh34_enter_wind_state(21, 28);
        *(_OWORD *)(v1 + 1816) = v116;
        v117 = *(_QWORD *)(v1 + 176);
        v266 = v117;
        v283 = v117;
        v283 = *(_QWORD *)(v1 + 176);
        if ( 0x7FFFFFFFFFFFFFFFLL - v283 < 0x21 )
          unknown_libname_3();
        v284 = *(_QWORD *)(v1 + 184);
        if ( v284 >= 0x10 )
        {
          v6 = *(char **)(v1 + 160);
          v282 = v6;
        }
        v118 = (void **)(v1 + 2064);
        *(_OWORD *)(v1 + 2064) = 0;
        *(_QWORD *)(v1 + 2080) = 0;
        *(_QWORD *)(v1 + 2088) = 0;
        v283 = *(_QWORD *)(v1 + 176);
        v119 = v283 + 33;
        Sizef = v283 + 33;
        v120 = 15;
        v121 = (_QWORD *)(v1 + 2064);
        if ( v283 + 33 > 0xF )
        {
          v122 = (__int64 *)(v1 + 3584);
          *(_QWORD *)(v1 + 3584) = v119 | 0xF;
          if ( (v119 | 0xF) <= 0x7FFFFFFFFFFFFFFFLL )
          {
            *(_QWORD *)(v1 + 3592) = 22;
            v301 = v119 | 0xF;
            if ( (v119 | 0xF) < 0x16 )
              v122 = (__int64 *)(v1 + 3592);
            v120 = *v122;
          }
          else
          {
            v120 = 0x7FFFFFFFFFFFFFFFLL;
          }
          v123 = v120 + 1;
          if ( v120 == -1 )
            v123 = -1;
          if ( v123 < 0x1000 )
          {
            if ( v123 != 0 )
            {
              v121 = operator new(Size: v123);
              v119 = Sizef;
              v117 = v266;
            }
            else
            {
              v121 = nullptr;
            }
          }
          else
          {
            if ( v123 + 39 < v123 )
              sub_140035990();
            v124 = operator new(Size: v123 + 39);
            if ( v124 == nullptr )
LABEL_375:
              invalid_parameter_noinfo_noreturn();
            v121 = (_QWORD *)(((unsigned __int64)v124 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *(v121 - 1) = v124;
            v119 = Sizef;
            v117 = v266;
          }
          *v118 = v121;
        }
        *(_QWORD *)(v1 + 2080) = v119;
        *(_QWORD *)(v1 + 2088) = v120;
        qmemcpy(v121, "get auto save file name failed! (", 33);
        memmove(a1: (char *)v121 + 33, Src: v6, Size: v117);
        *((_BYTE *)v121 + Sizef) = 0;
        __wind
        {
          v125 = sub_140037430(Src: (void *)(v1 + 2064));
          v126 = (void **)(v1 + 2096);
          *(_OWORD *)(v1 + 2096) = 0;
          *(_QWORD *)(v1 + 2112) = 0;
          *(_QWORD *)(v1 + 2120) = 0;
          *(_OWORD *)(v1 + 2096) = *(_OWORD *)v125;
          *(_OWORD *)(v1 + 2112) = *(_OWORD *)(v125 + 16);
          *(_QWORD *)(v125 + 16) = 0;
          *(_QWORD *)(v125 + 24) = 15;
          *(_BYTE *)v125 = 0;
          __wind
          {
            if ( qword_140102188 != 0 )
            {
              sub_140040440(a1: qword_140102188, a2: 4, a3: v1 + 2096);
              if ( qword_140102188 != 0 )
                (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
            }
          }
          __unwind
          {
            v331 = a1 + 2096;
            sub_1400371B0(a1: a1 + 2096);
          }
          if ( *(_QWORD *)(v1 + 2120) >= 0x10u )
          {
            v127 = *v126;
            if ( (unsigned __int64)(*(_QWORD *)(v1 + 2120) + 1LL) >= 0x1000 )
            {
              v127 = *((_BYTE **)*v126 - 1);
              if ( (unsigned __int64)((_BYTE *)*v126 - v127 - 8) > 0x1F )
                invalid_parameter_noinfo_noreturn();
            }
            j_j_free(Block: v127);
          }
        }
        __unwind
        {
          v330 = a1 + 2064;
          sub_1400371B0(a1: a1 + 2064);
        }
        *(_QWORD *)(v1 + 2112) = 0;
        *(_QWORD *)(v1 + 2120) = 15;
        *(_BYTE *)v126 = 0;
        if ( *(_QWORD *)(v1 + 2088) >= 0x10u )
        {
          v128 = *v118;
          if ( (unsigned __int64)(*(_QWORD *)(v1 + 2088) + 1LL) >= 0x1000 )
          {
            v128 = *((_BYTE **)*v118 - 1);
            if ( (unsigned __int64)((_BYTE *)*v118 - v128 - 8) > 0x1F )
              goto LABEL_375;
          }
          j_j_free(Block: v128);
        }
        __eh34_enter_wind_state(28, 36);
        v294 = *(_QWORD *)(v1 + 2056);
        v129 = (void **)(v1 + 2032);
        if ( v294 < 8 )
          goto LABEL_381;
        v294 = *(_QWORD *)(v1 + 2056);
        v130 = *v129;
        v292 = (char *)*v129;
        if ( 2 * v294 + 2 < 0x1000
          || (v292 = (char *)*v129,
              v130 = *((void **)v292 - 1),
              (unsigned __int64)((v292 = (char *)*v129) - (_BYTE *)v130 - 8) <= 0x1F) )
        {
          j_j_free(Block: v130);
LABEL_381:
          *(_QWORD *)(v1 + 2048) = 0;
          *(_QWORD *)(v1 + 2056) = 7;
          *(_WORD *)v129 = 0;
          v131 = (char **)(v1 + 1912);
          v285 = *(char **)(v1 + 1912);
          if ( v285 == nullptr )
          {
LABEL_385:
            v291 = *(_QWORD *)(v1 + 1808);
            if ( v291 < 8 )
              goto LABEL_389;
            v291 = *(_QWORD *)(v1 + 1808);
            v134 = *(char **)(v1 + 1784);
            v289 = v134;
            if ( 2 * v291 + 2 < 0x1000
              || (v289 = *(char **)(v1 + 1784),
                  v134 = *((char **)v289 - 1),
                  (unsigned __int64)((v289 = *(char **)(v1 + 1784)) - v134 - 8) <= 0x1F) )
            {
              j_j_free(Block: v134);
LABEL_389:
              *(_QWORD *)(v1 + 1800) = 0;
              *(_QWORD *)(v1 + 1808) = 7;
              *(_WORD *)(v1 + 1784) = 0;
              v281 = *(volatile signed __int32 **)(v1 + 800);
              if ( v281 != nullptr )
              {
                v135 = *(volatile signed __int32 **)(v1 + 800);
                v281 = v135;
                v281 = *(volatile signed __int32 **)(v1 + 800);
                if ( _InterlockedExchangeAdd(v281 + 2, 0xFFFFFFFF) == 1 )
                {
                  (**(void (__fastcall ***)(volatile signed __int32 *))v135)(a1: v135);
                  if ( _InterlockedExchangeAdd(v135 + 3, 0xFFFFFFFF) == 1 )
                    (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v135 + 8LL))(a1: v135);
                }
              }
              v277 = *(volatile signed __int32 **)(v1 + 224);
              if ( v277 != nullptr )
              {
                v136 = *(volatile signed __int32 **)(v1 + 224);
                v277 = v136;
                v277 = *(volatile signed __int32 **)(v1 + 224);
                if ( _InterlockedExchangeAdd(v277 + 2, 0xFFFFFFFF) == 1 )
                {
                  (**(void (__fastcall ***)(volatile signed __int32 *))v136)(a1: v136);
                  if ( _InterlockedExchangeAdd(v136 + 3, 0xFFFFFFFF) == 1 )
                    (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v136 + 8LL))(a1: v136);
                }
              }
              v284 = *(_QWORD *)(v1 + 184);
              if ( v284 < 0x10 )
                goto LABEL_401;
              v284 = *(_QWORD *)(v1 + 184);
              v137 = *(char **)(v1 + 160);
              v282 = v137;
              if ( v284 + 1 < 0x1000
                || (v282 = *(char **)(v1 + 160),
                    v137 = *((char **)v282 - 1),
                    (unsigned __int64)((v282 = *(char **)(v1 + 160)) - v137 - 8) <= 0x1F) )
              {
                j_j_free(Block: v137);
LABEL_401:
                *(_QWORD *)(v1 + 176) = 0;
                *(_QWORD *)(v1 + 184) = 15;
                *(_BYTE *)(v1 + 160) = 0;
                v299 = *(_QWORD *)(v1 + 136);
                if ( v299 != 0 )
                {
                  if ( __eh34_unwind(36) )
                    goto unwind_state_36;
                  __eh34_exit_wind_state(36, 28);
                  if ( __eh34_unwind(28) )
                    goto unwind_state_28;
                  __eh34_exit_wind_state(28, 21);
                  if ( __eh34_catch(21) )
                    goto catch_state_21;
                  __eh34_exit_try_state(21, 20);
                  if ( __eh34_unwind(20) )
                    goto unwind_state_20;
                  __eh34_exit_wind_state(20, 17);
                  if ( __eh34_unwind(17) )
                    goto unwind_state_17;
                  __eh34_exit_wind_state(17, 5);
                  if ( __eh34_unwind(5) )
                    goto unwind_state_5;
                  __eh34_exit_wind_state(5, 4);
                  if ( __eh34_unwind(4) )
                    goto unwind_state_4;
                  __eh34_exit_wind_state(4, 3);
                  if ( __eh34_unwind(3) )
                    goto unwind_state_3;
                  __eh34_exit_wind_state(3, 2);
                  if ( __eh34_unwind(2) )
                    goto unwind_state_2;
                  __eh34_exit_wind_state(2, 0);
                  __eh34_enter_wind_state(0, 31);
                  v298 = *(void (__fastcall ***)(__int64))(v1 + 128);
                  (*v298)(a1: v1 + 104);
                }
                else
                {
                  if ( __eh34_unwind(36) )
                    goto unwind_state_36;
                  __eh34_exit_wind_state(36, 28);
                  if ( __eh34_unwind(28) )
                    goto unwind_state_28;
                  __eh34_exit_wind_state(28, 21);
                  if ( __eh34_catch(21) )
                    goto catch_state_21;
                  __eh34_exit_try_state(21, 20);
                  if ( __eh34_unwind(20) )
                    goto unwind_state_20;
                  __eh34_exit_wind_state(20, 17);
                  if ( __eh34_unwind(17) )
                    goto unwind_state_17;
                  __eh34_exit_wind_state(17, 5);
                  if ( __eh34_unwind(5) )
                    goto unwind_state_5;
                  __eh34_exit_wind_state(5, 4);
                  if ( __eh34_unwind(4) )
                    goto unwind_state_4;
                  __eh34_exit_wind_state(4, 3);
                  if ( __eh34_unwind(3) )
                    goto unwind_state_3;
                  __eh34_exit_wind_state(3, 2);
                  if ( __eh34_unwind(2) )
                    goto unwind_state_2;
                  __eh34_exit_wind_state(2, 0);
                  __eh34_enter_wind_state(0, 31);
                }
                v22 = v264;
                goto LABEL_902;
              }
LABEL_519:
              invalid_parameter_noinfo_noreturn();
            }
LABEL_506:
            invalid_parameter_noinfo_noreturn();
          }
          v287 = *(_QWORD *)(v1 + 1928);
          v285 = *v131;
          v132 = v285;
          v133 = *v131;
          v285 = *v131;
          if ( (unsigned __int64)(v287 - (_QWORD)v132) < 0x1000
            || (v285 = *v131, v133 = *((char **)v285 - 1), (unsigned __int64)((v285 = *v131) - v133 - 8) <= 0x1F) )
          {
            j_j_free(Block: v133);
            *v131 = nullptr;
            *(_QWORD *)(v1 + 1920) = 0;
            *(_QWORD *)(v1 + 1928) = 0;
            goto LABEL_385;
          }
LABEL_501:
          invalid_parameter_noinfo_noreturn();
        }
LABEL_496:
        invalid_parameter_noinfo_noreturn();
      }
      v138 = *(_QWORD **)(v1 + 65);
      v139 = v138[2];
      if ( v138[3] >= 8u )
        v138 = (_QWORD *)*v138;
      if ( __eh34_unwind(24) )
      {
unwind_state_24:
        v328 = a1 + 2000;
        unknown_libname_4(a1: (void *)(a1 + 2000));
        __eh34_continue_unwinding(24, 23);
      }
      __eh34_exit_wind_state(24, 23);
      if ( __eh34_unwind(23) )
      {
unwind_state_23:
        v327 = a1 + 1968;
        unknown_libname_4(a1: (void *)(a1 + 1968));
        __eh34_continue_unwinding(23, 22);
      }
      __eh34_exit_wind_state(23, 22);
      if ( __eh34_unwind(22) )
      {
unwind_state_22:
        v326 = a1 + 1936;
        unknown_libname_4(a1: (void *)(a1 + 1936));
        __eh34_continue_unwinding(22, 21);
      }
      __eh34_exit_wind_state(22, 21);
      __eh34_enter_wind_state(21, 28);
      *(_OWORD *)(v1 + 2128) = 0;
      *(_QWORD *)(v1 + 2144) = 0;
      *(_QWORD *)(v1 + 2152) = 0;
      sub_14003EE60(a1: v1 + 2128, a2: v138, a3: v139);
      v140 = v1 + 2128;
      if ( *(_QWORD *)(v1 + 2152) >= 8u )
        v140 = *(_QWORD *)(v1 + 2128);
      v141 = (_WORD *)sub_1400382A0(a1: v140, a2: v140 + 2LL * *(_QWORD *)(v1 + 2144));
      if ( v141 != v143 )
      {
        do
        {
          if ( *v141 != 92 && *v141 != 47 )
            break;
          ++v141;
        }
        while ( v141 != v143 );
        if ( v141 != v143 )
        {
          do
          {
            v144 = (_WORD *)(v142 - 2);
            v145 = *(_WORD *)(v142 - 2);
            if ( v145 == 92 )
              break;
            if ( v145 == 47 )
              break;
            v142 -= 2;
          }
          while ( v141 != v144 );
        }
      }
      __wind
      {
        *(_OWORD *)(v1 + 2160) = 0;
        *(_QWORD *)(v1 + 2176) = 0;
        *(_QWORD *)(v1 + 2184) = 0;
        sub_14003EE60(a1: v1 + 2160, a2: v142, a3: ((__int64)v143 - v142) >> 1);
        __wind
        {
          v146 = sub_140038390(lpWideCharStr: (LPCWCH)(v1 + 2160));
          __wind
          {
            v147 = sub_140036AB0(a1: v1 + 2224, a2: v146);
            __wind
            {
              v148 = (void **)(v1 + 2256);
              v149 = (char **)sub_140036DA0(a1: v1 + 2256, a2: v147);
              v150 = (char **)(v1 + 1912);
              if ( (char **)(v1 + 1912) != v149 )
              {
                v285 = *v150;
                if ( v285 != nullptr )
                {
                  v287 = *(_QWORD *)(v1 + 1928);
                  v285 = *v150;
                  v151 = v285;
                  v152 = *v150;
                  v285 = *v150;
                  if ( (unsigned __int64)(v287 - (_QWORD)v151) >= 0x1000 )
                  {
                    v285 = *v150;
                    v152 = *((char **)v285 - 1);
                    v285 = *v150;
                    if ( (unsigned __int64)(v285 - v152 - 8) > 0x1F )
LABEL_426:
                      invalid_parameter_noinfo_noreturn();
                  }
                  j_j_free(Block: v152);
                  v150 = (char **)(v1 + 1912);
                  *(_QWORD *)(v1 + 1912) = 0;
                  *(_QWORD *)(v1 + 1920) = 0;
                  *(_QWORD *)(v1 + 1928) = 0;
                }
                *v150 = *v149;
                *(_QWORD *)(v1 + 1920) = v149[1];
                *(_QWORD *)(v1 + 1928) = v149[2];
                *v149 = nullptr;
                v149[1] = nullptr;
                v149[2] = nullptr;
              }
              if ( *v148 != nullptr )
              {
                v153 = *v148;
                if ( *(_QWORD *)(v1 + 2272) - (_QWORD)*v148 >= 0x1000u )
                {
                  v153 = *((_BYTE **)*v148 - 1);
                  if ( (unsigned __int64)((_BYTE *)*v148 - v153 - 8) > 0x1F )
                    goto LABEL_426;
                }
                j_j_free(Block: v153);
                *v148 = nullptr;
                *(_QWORD *)(v1 + 2264) = 0;
                *(_QWORD *)(v1 + 2272) = 0;
              }
              if ( *(_QWORD *)(v1 + 2248) >= 0x10u )
              {
                v154 = *(void **)(v1 + 2224);
                if ( (unsigned __int64)(*(_QWORD *)(v1 + 2248) + 1LL) >= 0x1000 )
                {
                  v154 = *(void **)(*(_QWORD *)(v1 + 2224) - 8LL);
                  if ( (unsigned __int64)(*(_QWORD *)(v1 + 2224) - (_QWORD)v154 - 8LL) > 0x1F )
                    invalid_parameter_noinfo_noreturn();
                }
                j_j_free(Block: v154);
              }
              *(_QWORD *)(v1 + 2240) = 0;
              *(_QWORD *)(v1 + 2248) = 15;
              *(_BYTE *)(v1 + 2224) = 0;
              if ( *(_QWORD *)(v1 + 2216) >= 0x10u )
              {
                v155 = *(void **)(v1 + 2192);
                if ( (unsigned __int64)(*(_QWORD *)(v1 + 2216) + 1LL) >= 0x1000 )
                {
                  v155 = *(void **)(*(_QWORD *)(v1 + 2192) - 8LL);
                  if ( (unsigned __int64)(*(_QWORD *)(v1 + 2192) - (_QWORD)v155 - 8LL) > 0x1F )
                    invalid_parameter_noinfo_noreturn();
                }
                j_j_free(Block: v155);
              }
              *(_QWORD *)(v1 + 2208) = 0;
              *(_QWORD *)(v1 + 2216) = 15;
              *(_BYTE *)(v1 + 2192) = 0;
              if ( *(_QWORD *)(v1 + 2184) >= 8u )
              {
                v156 = *(void **)(v1 + 2160);
                if ( (unsigned __int64)(2LL * *(_QWORD *)(v1 + 2184) + 2) >= 0x1000 )
                {
                  v156 = *(void **)(*(_QWORD *)(v1 + 2160) - 8LL);
                  if ( (unsigned __int64)(*(_QWORD *)(v1 + 2160) - (_QWORD)v156 - 8LL) > 0x1F )
                    invalid_parameter_noinfo_noreturn();
                }
                j_j_free(Block: v156);
              }
              *(_QWORD *)(v1 + 2176) = 0;
              *(_QWORD *)(v1 + 2184) = 7;
              *(_WORD *)(v1 + 2160) = 0;
              if ( *(_QWORD *)(v1 + 2152) >= 8u )
              {
                v157 = *(void **)(v1 + 2128);
                if ( (unsigned __int64)(2LL * *(_QWORD *)(v1 + 2152) + 2) >= 0x1000 )
                {
                  v157 = *(void **)(*(_QWORD *)(v1 + 2128) - 8LL);
                  if ( (unsigned __int64)(*(_QWORD *)(v1 + 2128) - (_QWORD)v157 - 8LL) > 0x1F )
                    invalid_parameter_noinfo_noreturn();
                }
                j_j_free(Block: v157);
              }
            }
            __unwind
            {
              v335 = a1 + 2224;
              sub_1400371B0(a1: a1 + 2224);
            }
          }
          __unwind
          {
            v334 = a1 + 2192;
            sub_1400371B0(a1: a1 + 2192);
          }
        }
        __unwind
        {
          v333 = a1 + 2160;
          unknown_libname_4(a1: (void *)(a1 + 2160));
        }
      }
      __unwind
      {
        v332 = a1 + 2128;
        unknown_libname_4(a1: (void *)(a1 + 2128));
      }
      v286 = *(char **)(v1 + 1920);
      v285 = *(char **)(v1 + 1912);
      if ( v286 == v285 )
      {
        v158 = *(_QWORD *)(v1 + 216);
        v276 = v158;
        if ( *(_QWORD *)(v158 + 8) == -1 )
        {
          *(_DWORD *)(v1 + 3680) = 0;
          *(_QWORD *)(v1 + 3688) = &off_1400F9FB0;
          v160 = *(_OWORD *)(v1 + 3680);
        }
        else
        {
          if ( CloseHandle(hObject: *(HANDLE *)(v158 + 8)) )
          {
            *(_DWORD *)(v1 + 3664) = 0;
            *(_QWORD *)(v1 + 3672) = &off_1400F9FB0;
            v160 = *(_OWORD *)(v1 + 3664);
          }
          else
          {
            v159 = GetLastError();
            if ( dword_140101DC4 > *(_DWORD *)(*(_QWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + 8LL) )
            {
              Init_thread_header(a1: &dword_140101DC4);
              if ( dword_140101DC4 == -1 )
              {
                atexit(a1: nullsub_3);
                Init_thread_footer(a1: &dword_140101DC4);
              }
            }
            *(_DWORD *)(v1 + 3648) = v159;
            *(_QWORD *)(v1 + 3656) = &off_1400F9FA0;
            v160 = *(_OWORD *)(v1 + 3648);
          }
          *(_QWORD *)(v158 + 8) = -1;
          *(_DWORD *)(v158 + 16) = 0;
        }
        *(_OWORD *)(v1 + 1816) = v160;
        v161 = *(_QWORD *)(v1 + 176);
        v267 = v161;
        v283 = v161;
        v283 = *(_QWORD *)(v1 + 176);
        if ( 0x7FFFFFFFFFFFFFFFLL - v283 < 0x19 )
          unknown_libname_3();
        v284 = *(_QWORD *)(v1 + 184);
        if ( v284 >= 0x10 )
        {
          v6 = *(char **)(v1 + 160);
          v282 = v6;
        }
        __eh34_enter_wind_state(28, 36);
        v162 = (void **)(v1 + 2280);
        *(_OWORD *)(v1 + 2280) = 0;
        *(_QWORD *)(v1 + 2296) = 0;
        *(_QWORD *)(v1 + 2304) = 0;
        v283 = *(_QWORD *)(v1 + 176);
        v163 = v283 + 25;
        Sizeg = v283 + 25;
        v164 = 15;
        v165 = (_QWORD *)(v1 + 2280);
        if ( v283 + 25 > 0xF )
        {
          v166 = (__int64 *)(v1 + 3696);
          *(_QWORD *)(v1 + 3696) = v163 | 0xF;
          if ( (v163 | 0xF) <= 0x7FFFFFFFFFFFFFFFLL )
          {
            *(_QWORD *)(v1 + 3704) = 22;
            v288 = v163 | 0xF;
            if ( (v163 | 0xF) < 0x16 )
              v166 = (__int64 *)(v1 + 3704);
            v164 = *v166;
          }
          else
          {
            v164 = 0x7FFFFFFFFFFFFFFFLL;
          }
          v167 = v164 + 1;
          if ( v164 == -1 )
            v167 = -1;
          if ( v167 < 0x1000 )
          {
            if ( v167 != 0 )
            {
              v165 = operator new(Size: v167);
              v163 = Sizeg;
              v161 = v267;
            }
            else
            {
              v165 = nullptr;
            }
          }
          else
          {
            if ( v167 + 39 < v167 )
              sub_140035990();
            v168 = operator new(Size: v167 + 39);
            if ( v168 == nullptr )
LABEL_491:
              invalid_parameter_noinfo_noreturn();
            v165 = (_QWORD *)(((unsigned __int64)v168 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *(v165 - 1) = v168;
            v163 = Sizeg;
            v161 = v267;
          }
          *v162 = v165;
        }
        *(_QWORD *)(v1 + 2296) = v163;
        *(_QWORD *)(v1 + 2304) = v164;
        qmemcpy(v165, "Encrypt pack id failed! (", 25);
        memmove(a1: (char *)v165 + 25, Src: v6, Size: v161);
        *((_BYTE *)v165 + Sizeg) = 0;
        v169 = sub_140037430(Src: (void *)(v1 + 2280));
        v170 = (void **)(v1 + 2312);
        *(_OWORD *)(v1 + 2312) = 0;
        *(_QWORD *)(v1 + 2328) = 0;
        *(_QWORD *)(v1 + 2336) = 0;
        *(_OWORD *)(v1 + 2312) = *(_OWORD *)v169;
        *(_OWORD *)(v1 + 2328) = *(_OWORD *)(v169 + 16);
        *(_QWORD *)(v169 + 16) = 0;
        *(_QWORD *)(v169 + 24) = 15;
        *(_BYTE *)v169 = 0;
        __wind
        {
          if ( qword_140102188 != 0 )
          {
            sub_140040440(a1: qword_140102188, a2: 4, a3: v1 + 2312);
            if ( qword_140102188 != 0 )
              (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
          }
        }
        __unwind
        {
          v337 = a1 + 2312;
          sub_1400371B0(a1: a1 + 2312);
        }
        if ( *(_QWORD *)(v1 + 2336) >= 0x10u )
        {
          v171 = *v170;
          if ( (unsigned __int64)(*(_QWORD *)(v1 + 2336) + 1LL) >= 0x1000 )
          {
            v171 = *((_BYTE **)*v170 - 1);
            if ( (unsigned __int64)((_BYTE *)*v170 - v171 - 8) > 0x1F )
              invalid_parameter_noinfo_noreturn();
          }
          j_j_free(Block: v171);
        }
        *(_QWORD *)(v1 + 2328) = 0;
        *(_QWORD *)(v1 + 2336) = 15;
        *(_BYTE *)v170 = 0;
        if ( *(_QWORD *)(v1 + 2304) >= 0x10u )
        {
          v172 = *v162;
          if ( (unsigned __int64)(*(_QWORD *)(v1 + 2304) + 1LL) >= 0x1000 )
          {
            v172 = *((_BYTE **)*v162 - 1);
            if ( (unsigned __int64)((_BYTE *)*v162 - v172 - 8) > 0x1F )
              goto LABEL_491;
          }
          j_j_free(Block: v172);
        }
        v294 = *(_QWORD *)(v1 + 2056);
        v173 = (void **)(v1 + 2032);
        if ( v294 >= 8 )
        {
          v294 = *(_QWORD *)(v1 + 2056);
          v174 = *v173;
          v292 = (char *)*v173;
          if ( 2 * v294 + 2 >= 0x1000 )
          {
            v292 = (char *)*v173;
            v174 = *((_BYTE **)v292 - 1);
            v292 = (char *)*v173;
            if ( (unsigned __int64)(v292 - v174 - 8) > 0x1F )
              goto LABEL_496;
          }
          j_j_free(Block: v174);
        }
        *(_QWORD *)(v1 + 2048) = 0;
        *(_QWORD *)(v1 + 2056) = 7;
        *(_WORD *)v173 = 0;
        v175 = (char **)(v1 + 1912);
        v285 = *(char **)(v1 + 1912);
        if ( v285 != nullptr )
        {
          v287 = *(_QWORD *)(v1 + 1928);
          v285 = *v175;
          v176 = v285;
          v177 = *v175;
          v285 = *v175;
          if ( (unsigned __int64)(v287 - (_QWORD)v176) >= 0x1000 )
          {
            v285 = *v175;
            v177 = *((char **)v285 - 1);
            v285 = *v175;
            if ( (unsigned __int64)(v285 - v177 - 8) > 0x1F )
              goto LABEL_501;
          }
          j_j_free(Block: v177);
          *v175 = nullptr;
          *(_QWORD *)(v1 + 1920) = 0;
          *(_QWORD *)(v1 + 1928) = 0;
        }
        v291 = *(_QWORD *)(v1 + 1808);
        if ( v291 >= 8 )
        {
          v291 = *(_QWORD *)(v1 + 1808);
          v178 = *(char **)(v1 + 1784);
          v289 = v178;
          if ( 2 * v291 + 2 >= 0x1000 )
          {
            v289 = *(char **)(v1 + 1784);
            v178 = *((char **)v289 - 1);
            v289 = *(char **)(v1 + 1784);
            if ( (unsigned __int64)(v289 - v178 - 8) > 0x1F )
              goto LABEL_506;
          }
          j_j_free(Block: v178);
        }
        *(_QWORD *)(v1 + 1800) = 0;
        *(_QWORD *)(v1 + 1808) = 7;
        *(_WORD *)(v1 + 1784) = 0;
        v281 = *(volatile signed __int32 **)(v1 + 800);
        if ( v281 != nullptr )
        {
          v179 = *(volatile signed __int32 **)(v1 + 800);
          v281 = v179;
          v281 = *(volatile signed __int32 **)(v1 + 800);
          if ( _InterlockedExchangeAdd(v281 + 2, 0xFFFFFFFF) == 1 )
          {
            (**(void (__fastcall ***)(volatile signed __int32 *))v179)(a1: v179);
            if ( _InterlockedExchangeAdd(v179 + 3, 0xFFFFFFFF) == 1 )
              (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v179 + 8LL))(a1: v179);
          }
        }
        v277 = *(volatile signed __int32 **)(v1 + 224);
        if ( v277 != nullptr )
        {
          v180 = *(volatile signed __int32 **)(v1 + 224);
          v277 = v180;
          v277 = *(volatile signed __int32 **)(v1 + 224);
          if ( _InterlockedExchangeAdd(v277 + 2, 0xFFFFFFFF) == 1 )
          {
            (**(void (__fastcall ***)(volatile signed __int32 *))v180)(a1: v180);
            if ( _InterlockedExchangeAdd(v180 + 3, 0xFFFFFFFF) == 1 )
              (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v180 + 8LL))(a1: v180);
          }
        }
        v284 = *(_QWORD *)(v1 + 184);
        if ( v284 >= 0x10 )
        {
          v284 = *(_QWORD *)(v1 + 184);
          v181 = *(char **)(v1 + 160);
          v282 = v181;
          if ( v284 + 1 >= 0x1000 )
          {
            v282 = *(char **)(v1 + 160);
            v181 = *((char **)v282 - 1);
            v282 = *(char **)(v1 + 160);
            if ( (unsigned __int64)(v282 - v181 - 8) > 0x1F )
              goto LABEL_519;
          }
          j_j_free(Block: v181);
        }
        if ( __eh34_unwind(36) )
        {
unwind_state_36:
          v336 = a1 + 2280;
          sub_1400371B0(a1: a1 + 2280);
          __eh34_continue_unwinding(36, 28);
        }
        __eh34_exit_wind_state(36, 28);
        if ( __eh34_unwind(28) )
          goto unwind_state_28;
        __eh34_exit_wind_state(28, 21);
        if ( __eh34_catch(21) )
          goto catch_state_21;
        __eh34_exit_try_state(21, 20);
        if ( __eh34_unwind(20) )
          goto unwind_state_20;
        __eh34_exit_wind_state(20, 17);
        if ( __eh34_unwind(17) )
          goto unwind_state_17;
        __eh34_exit_wind_state(17, 5);
        if ( __eh34_unwind(5) )
          goto unwind_state_5;
        __eh34_exit_wind_state(5, 4);
        if ( __eh34_unwind(4) )
          goto unwind_state_4;
        __eh34_exit_wind_state(4, 3);
        if ( __eh34_unwind(3) )
          goto unwind_state_3;
        __eh34_exit_wind_state(3, 2);
        if ( __eh34_unwind(2) )
          goto unwind_state_2;
        __eh34_exit_wind_state(2, 0);
        __eh34_enter_wind_state(0, 31);
        *(_QWORD *)(v1 + 176) = 0;
        *(_QWORD *)(v1 + 184) = 15;
        *(_BYTE *)(v1 + 160) = 0;
        v299 = *(_QWORD *)(v1 + 136);
        if ( v299 != 0 )
        {
          v298 = *(void (__fastcall ***)(__int64))(v1 + 128);
          (*v298)(a1: v1 + 104);
        }
        v22 = v264;
        if ( __eh34_unwind(31) )
          terminate();
LABEL_902:
        __eh34_exit_wind_state(31, 0);
        goto LABEL_901;
      }
      if ( v251 != 0 )
      {
        v182 = sub_14003B2C0(a1: v1 + 2032);
        v183 = sub_14003E0E0(a1: v1 + 2344, a2: *(_QWORD *)(v1 + 65));
        __wind
        {
          v184 = sub_1400384A0(a1: v183, a2: v1 + 2376);
          __wind
          {
            v185 = sub_140038480(a1: v184, a2: v1 + 2408);
            __wind
            {
              v186 = sub_14003E950(a1: v1 + 2440, a2: v185, a3: &unk_1400DC68C);
              __wind
              {
                v187 = sub_14003E950(a1: v1 + 2472, a2: v186, a3: v182);
                __wind
                {
                  v188 = sub_14003E950(a1: v1 + 2504, a2: v187, a3: aArika_0);
                  sub_14003B360(a1: v1 + 1784, a2: v188);
                  unknown_libname_4(a1: (void *)(v1 + 2504));
                  unknown_libname_4(a1: (void *)(v1 + 2472));
                  unknown_libname_4(a1: (void *)(v1 + 2440));
                  unknown_libname_4(a1: (void *)(v1 + 2408));
                  unknown_libname_4(a1: (void *)(v1 + 2376));
                  unknown_libname_4(a1: (void *)(v1 + 2344));
                }
                __unwind
                {
                  v342 = a1 + 2472;
                  unknown_libname_4(a1: (void *)(a1 + 2472));
                }
              }
              __unwind
              {
                v341 = a1 + 2440;
                unknown_libname_4(a1: (void *)(a1 + 2440));
              }
            }
            __unwind
            {
              v340 = a1 + 2408;
              unknown_libname_4(a1: (void *)(a1 + 2408));
            }
          }
          __unwind
          {
            v339 = a1 + 2376;
            unknown_libname_4(a1: (void *)(a1 + 2376));
          }
        }
        __unwind
        {
          v338 = a1 + 2344;
          unknown_libname_4(a1: (void *)(a1 + 2344));
        }
        v189 = sub_140039FB0(
                 a1: (int)v1 + 2544,
                 a2: (int)v1 + 1784,
                 a3: (int)v1 + 192,
                 a4: (int)v1 + 768,
                 a5: v1 + 1912);
        v190 = sub_14003A030(a1: v1 + 16, a2: v1 + 2552, a3: v189);
        *(_QWORD *)(v1 + 2536) = v190;
        __wind
        {
          *v264 = 6;
          sub_14003E7D0(a1: v190, a2: v1);
        }
        __unwind
        {
          v343 = a1 + 2552;
          sub_14003A3B0(a1: a1 + 2552);
        }
        if ( __eh34_unwind(28) )
          goto unwind_state_28;
        __eh34_exit_wind_state(28, 21);
        if ( __eh34_catch(21) )
          goto catch_state_21;
        goto LABEL_739;
      }
LABEL_531:
      v294 = *(_QWORD *)(v1 + 2056);
      if ( v294 >= 8 )
      {
        v294 = *(_QWORD *)(v1 + 2056);
        v195 = *(char **)(v1 + 2032);
        v292 = v195;
        if ( 2 * v294 + 2 >= 0x1000 )
        {
          v292 = *(char **)(v1 + 2032);
          v195 = *((char **)v292 - 1);
          v292 = *(char **)(v1 + 2032);
          if ( (unsigned __int64)(v292 - v195 - 8) > 0x1F )
            invalid_parameter_noinfo_noreturn();
        }
        j_j_free(Block: v195);
      }
      v196 = v264;
      if ( __eh34_unwind(28) )
        goto unwind_state_28;
      __eh34_exit_wind_state(28, 21);
      if ( __eh34_catch(21) )
        goto catch_state_21;
      __eh34_exit_try_state(21, 20);
LABEL_537:
      v197 = *(_DWORD *)(v1 + 1776);
      if ( v197 != 0 )
      {
        v198 = v197 - 1;
        if ( v198 != 0 )
        {
          if ( v198 == 1 )
          {
            v199 = sub_14003A240(a1: v1 + 2848, a2: v1 + 192, a3: *(unsigned __int8 *)(v1 + 1780), a4: v1 + 768);
            v200 = sub_14003A030(a1: v1 + 16, a2: v1 + 2856, a3: v199);
            *(_QWORD *)(v1 + 2840) = v200;
            __eh34_enter_wind_state(20, 51);
            *v196 = 12;
            sub_14003E7D0(a1: v200, a2: v1);
            if ( __eh34_unwind(51) )
              goto unwind_state_51;
            __eh34_exit_wind_state(51, 20);
            break;
          }
LABEL_562:
          sub_140038230(a1: v1 + 3064);
          v274 = *(_QWORD *)(v1 + 3064);
          *(_QWORD *)(v1 + 3072) = v274 - *(_QWORD *)(v1 + 1832);
          sub_14003E9C0(a1: v1 + 3080);
          v280 = *(_QWORD *)(v1 + 792);
          if ( v280 != 0 )
          {
            v280 = *(_QWORD *)(v1 + 792);
            sub_14003A5C0(a1: v280, a2: v1 + 3088, a3: v1 + 1816);
          }
          if ( *(_BYTE *)(v1 + 1904) != 0 )
          {
            sub_1400372D0(a1: v1 + 3104, a2: aAkira);
            __wind
            {
              v224 = sub_14007E9F0(a1: v1 + 3136, a2: v1 + 3104, a3: 0);
              __wind
              {
                sub_14007E940(a1: v1 + 3168, a2: *(_QWORD *)(v1 + 65), a3: v224);
              }
              __unwind
              {
                v361 = a1 + 3136;
                unknown_libname_4(a1: (void *)(a1 + 3136));
              }
              __wind
              {
                unknown_libname_4(a1: (void *)(v1 + 3136));
                sub_1400371B0(a1: v1 + 3104);
                v302 = *(_QWORD *)(v1 + 3184);
                dwBufferSizea = 2 * v302 + 26;
                sub_140036FB0(a1: v1 + 3200);
              }
              __unwind
              {
                v362 = a1 + 3168;
                unknown_libname_4(a1: (void *)(a1 + 3168));
              }
            }
            __unwind
            {
              v360 = a1 + 3104;
              sub_1400371B0(a1: a1 + 3104);
            }
            __wind
            {
              *(_BYTE *)(v1 + 3224) = 0;
              sub_14003A760(a1: v1 + 3200);
              v303 = *(_BYTE **)(v1 + 3200);
              v225 = v303;
              v303 = *(_BYTE **)(v1 + 3200);
              *v303 = 1;
              LODWORD(v302) = *(_DWORD *)(v1 + 3184);
              *((_DWORD *)v225 + 4) = 2 * v302;
              v302 = *(_QWORD *)(v1 + 3184);
              v226 = v302 + 1;
              v227 = (const wchar_t *)sub_14003B2C0(a1: v1 + 3168);
              wmemmove(S1: (wchar_t *)v225 + 10, S2: v227, N: v226);
              v275 = *(HANDLE *)(v1 + 208);
              if ( !SetFileInformationByHandle(
                      hFile: v275,
                      FileInformationClass: FileRenameInfo,
                      lpFileInformation: v225,
                      dwBufferSize: dwBufferSizea) )
              {
                v228 = GetLastError();
                __wind
                {
                  *(_DWORD *)(v1 + 3228) = v228;
                  v229 = sub_14003E9F0(a1: (void *)(v1 + 3232));
                  __wind
                  {
                    v230 = sub_14003E3F0(a1: v1 + 3264, a2: "file rename failed. System error:", a3: v229);
                    __wind
                    {
                      v231 = sub_14003E000(a1: v1 + 3296, a2: v230, a3: " (");
                      __wind
                      {
                        v232 = sub_14003E070(a1: v1 + 3328, a2: v231, a3: v1 + 160);
                        __wind
                        {
                          v233 = sub_14003E000(a1: v1 + 3360, a2: v232, a3: ")");
                          __wind
                          {
                            sub_140039EC0(a1: v234, a2: v233);
                            sub_1400371B0(a1: v1 + 3360);
                            sub_1400371B0(a1: v1 + 3328);
                            sub_1400371B0(a1: v1 + 3296);
                            sub_1400371B0(a1: v1 + 3264);
                            sub_1400371B0(a1: v1 + 3232);
                          }
                          __unwind
                          {
                            v368 = a1 + 3360;
                            sub_1400371B0(a1: a1 + 3360);
                          }
                        }
                        __unwind
                        {
                          v367 = a1 + 3328;
                          sub_1400371B0(a1: a1 + 3328);
                        }
                      }
                      __unwind
                      {
                        v366 = a1 + 3296;
                        sub_1400371B0(a1: a1 + 3296);
                      }
                    }
                    __unwind
                    {
                      v365 = a1 + 3264;
                      sub_1400371B0(a1: a1 + 3264);
                    }
                  }
                  __unwind
                  {
                    v364 = a1 + 3232;
                    sub_1400371B0(a1: a1 + 3232);
                  }
                }
                __unwind
                {
                  v363 = a1 + 3200;
                  sub_140037060(a1: a1 + 3200);
                }
              }
              v276 = *(_QWORD *)(v1 + 216);
              sub_14003A5C0(a1: v276, a2: v1 + 3392, a3: v1 + 1816);
              v290 = *(_QWORD *)(v1 + 1800);
              if ( v290 != 0 )
              {
                v235 = (const WCHAR *)sub_14003B2C0(a1: v1 + 1784);
                DeleteFileW(lpFileName: v235);
              }
              sub_140037060(a1: v1 + 3200);
              unknown_libname_4(a1: (void *)(v1 + 3168));
            }
            __unwind
            {
              v362 = a1 + 3168;
              unknown_libname_4(a1: (void *)(a1 + 3168));
            }
          }
          else
          {
            v236 = sub_14003E290(a1: (void *)(v1 + 3408), Src: "Failed to write header! (", a3: (void *)(v1 + 160));
            __wind
            {
              v237 = sub_14003E000(a1: v1 + 3440, a2: v236, a3: ")");
              __wind
              {
                sub_140039EC0(a1: v238, a2: v237);
                sub_1400371B0(a1: v1 + 3440);
                sub_1400371B0(a1: v1 + 3408);
                v276 = *(_QWORD *)(v1 + 216);
                sub_14003A5C0(a1: v276, a2: v1 + 3472, a3: v1 + 1816);
              }
              __unwind
              {
                v370 = a1 + 3440;
                sub_1400371B0(a1: a1 + 3440);
              }
            }
            __unwind
            {
              v369 = a1 + 3408;
              sub_1400371B0(a1: a1 + 3408);
            }
          }
          v279 = *(void **)(v1 + 240);
          if ( v279 != nullptr )
          {
            v279 = *(void **)(v1 + 240);
            v239 = v279;
            v279 = *(void **)(v1 + 240);
            sub_140083740();
            sub_140083C20(a1: v239);
            v279 = *(void **)(v1 + 240);
            j_j_free(Block: v279);
            *(_QWORD *)(v1 + 240) = 0;
          }
          if ( __eh34_unwind(20) )
            goto unwind_state_20;
          __eh34_exit_wind_state(20, 17);
          sub_140037060(a1: v1 + 1912);
          unknown_libname_4(a1: (void *)(v1 + 1784));
          v281 = *(volatile signed __int32 **)(v1 + 800);
          if ( v281 != nullptr )
          {
            v240 = *(volatile signed __int32 **)(v1 + 800);
            v281 = v240;
            v281 = *(volatile signed __int32 **)(v1 + 800);
            if ( _InterlockedExchangeAdd(v281 + 2, 0xFFFFFFFF) == 1 )
            {
              (**(void (__fastcall ***)(volatile signed __int32 *))v240)(a1: v240);
              if ( _InterlockedExchangeAdd(v240 + 3, 0xFFFFFFFF) == 1 )
                (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v240 + 8LL))(a1: v240);
            }
          }
          v277 = *(volatile signed __int32 **)(v1 + 224);
          if ( v277 != nullptr )
          {
            v241 = *(volatile signed __int32 **)(v1 + 224);
            v277 = v241;
            v277 = *(volatile signed __int32 **)(v1 + 224);
            if ( _InterlockedExchangeAdd(v277 + 2, 0xFFFFFFFF) == 1 )
            {
              (**(void (__fastcall ***)(volatile signed __int32 *))v241)(a1: v241);
              if ( _InterlockedExchangeAdd(v241 + 3, 0xFFFFFFFF) == 1 )
                (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v241 + 8LL))(a1: v241);
            }
          }
          sub_1400371B0(a1: v1 + 160);
          sub_140038710(a1: v1 + 104);
          v22 = v264;
          goto LABEL_637;
        }
        v201 = sub_14003A160(a1: v1 + 2960, a2: v1 + 192, a3: *(unsigned __int8 *)(v1 + 1780), a4: v1 + 768);
        v202 = sub_14003A030(a1: v1 + 16, a2: v1 + 2968, a3: v201);
        *(_QWORD *)(v1 + 2952) = v202;
        __eh34_enter_wind_state(20, 55);
        *v196 = 16;
        sub_14003E7D0(a1: v202, a2: v1);
        if ( __eh34_unwind(55) )
          goto unwind_state_55;
        __eh34_exit_wind_state(55, 20);
      }
      else
      {
        v203 = sub_14003A1D0(a1: v1 + 2736, a2: v1 + 192, a3: v1 + 768);
        v204 = sub_14003A030(a1: v1 + 16, a2: v1 + 2744, a3: v203);
        *(_QWORD *)(v1 + 2728) = v204;
        __eh34_enter_wind_state(20, 47);
        *v196 = 8;
        sub_14003E7D0(a1: v204, a2: v1);
        if ( __eh34_unwind(47) )
          goto unwind_state_47;
        __eh34_exit_wind_state(47, 20);
      }
      break;
    case 6:
      v191 = sub_14003A6C0(a1: *(_QWORD *)(a1 + 2536));
      __eh34_enter_try_state(20, 21);
      __eh34_enter_wind_state(21, 28);
      sub_14003A3B0(a1: v1 + 2552);
      if ( v191 != 0 )
        goto LABEL_531;
      v276 = *(_QWORD *)(v1 + 216);
      sub_14003A5C0(a1: v276, a2: v1 + 2560, a3: v1 + 1816);
      v192 = sub_14003E290(a1: (void *)(v1 + 2576), Src: "create auto save file failed! (", a3: (void *)(v1 + 160));
      __wind
      {
        v193 = sub_14003E000(a1: v1 + 2608, a2: v192, a3: &unk_1400DC690);
        __wind
        {
          sub_140039EC0(a1: v194, a2: v193);
        }
        __unwind
        {
          v345 = a1 + 2608;
          sub_1400371B0(a1: a1 + 2608);
        }
        sub_1400371B0(a1: v1 + 2608);
        sub_1400371B0(a1: v1 + 2576);
        unknown_libname_4(a1: (void *)(v1 + 2032));
        sub_140037060(a1: v1 + 1912);
        unknown_libname_4(a1: (void *)(v1 + 1784));
        sub_14003A350(a1: v1 + 768);
        sub_14003A350(a1: v1 + 192);
        sub_1400371B0(a1: v1 + 160);
        sub_140038710(a1: v1 + 104);
        v22 = v264;
      }
      __unwind
      {
        v344 = a1 + 2576;
        sub_1400371B0(a1: a1 + 2576);
      }
      if ( __eh34_unwind(28) )
      {
unwind_state_28:
        v329 = a1 + 2032;
        unknown_libname_4(a1: (void *)(a1 + 2032));
        __eh34_continue_unwinding(28, 21);
      }
      __eh34_exit_wind_state(28, 21);
      if ( __eh34_catch(21) )
      {
catch_state_21:
        if ( __eh34_catch_type(21, &std::exception `RTTI Type Descriptor', &v273) )
        {
          v276 = *(_QWORD *)(a1 + 216);
          sub_14003A5C0(a1: v276, a2: a1 + 2640, a3: a1 + 1816);
          *(_QWORD *)(a1 + 2656) = (*(__int64 (__fastcall **)(std::exception *))(*(_QWORD *)v273 + 8LL))(a1: v273);
          v248 = sub_14003E680(a1: (void *)(a1 + 2664));
          __wind
          {
            v249 = sub_14003E3F0(a1: a1 + 2696, a2: "get auto hash file name failed:", a3: v248);
            __wind
            {
              sub_140039EC0(a1: v250, a2: v249);
            }
            __unwind
            {
              v347 = a1 + 2696;
              sub_1400371B0(a1: a1 + 2696);
            }
            sub_1400371B0(a1: a1 + 2696);
            sub_1400371B0(a1: a1 + 2664);
          }
          __unwind
          {
            v346 = a1 + 2664;
            sub_1400371B0(a1: a1 + 2664);
          }
          v196 = v271;
          v264 = v271;
          v1 = a1;
          goto LABEL_537;
        }
LABEL_739:
        __eh34_exit_try_state(21, 20);
        break;
      }
      __eh34_exit_try_state(21, 20);
      goto LABEL_583;
    case 7:
      sub_14003A3B0(a1: a1 + 2552);
      unknown_libname_4(a1: (void *)(v1 + 2032));
      sub_140037060(a1: v1 + 1912);
      unknown_libname_4(a1: (void *)(v1 + 1784));
      sub_14003A350(a1: v1 + 768);
      sub_14003A350(a1: v1 + 192);
      sub_1400371B0(a1: v1 + 160);
      sub_140038710(a1: v1 + 104);
      goto LABEL_584;
    case 8:
      __eh34_enter_wind_state(20, 47);
      v218 = sub_14003A6C0(a1: *(_QWORD *)(a1 + 2728));
      sub_14003A3B0(a1: v1 + 2744);
      if ( __eh34_unwind(47) )
      {
unwind_state_47:
        v348 = a1 + 2744;
        sub_14003A3B0(a1: a1 + 2744);
        __eh34_continue_unwinding(47, 20);
      }
      __eh34_exit_wind_state(47, 20);
      if ( v218 == 0 )
      {
        v219 = sub_14003E290(a1: (void *)(v1 + 2752), Src: "Failed to make full encrypt! (", a3: (void *)(v1 + 160));
        __wind
        {
          v220 = sub_14003E000(a1: v1 + 2784, a2: v219, a3: ")");
          __wind
          {
            sub_140039EC0(a1: v221, a2: v220);
            sub_1400371B0(a1: v1 + 2784);
            sub_1400371B0(a1: v1 + 2752);
          }
          __unwind
          {
            v350 = a1 + 2784;
            sub_1400371B0(a1: a1 + 2784);
          }
        }
        __unwind
        {
          v349 = a1 + 2752;
          sub_1400371B0(a1: a1 + 2752);
        }
        goto LABEL_562;
      }
      v222 = sub_14003A0F0(a1: v1 + 2824, a2: v1 + 192, a3: v1 + 1912);
      v223 = sub_14003A030(a1: v1 + 16, a2: v1 + 2832, a3: v222);
      *(_QWORD *)(v1 + 2816) = v223;
      __wind
      {
        *v2 = 10;
        sub_14003E7D0(a1: v223, a2: v1);
      }
      __unwind
      {
        v351 = a1 + 2832;
        sub_14003A3B0(a1: a1 + 2832);
      }
      break;
    case 9:
      sub_14003A3B0(a1: a1 + 2744);
      sub_140037060(a1: v1 + 1912);
      unknown_libname_4(a1: (void *)(v1 + 1784));
      sub_14003A350(a1: v1 + 768);
      sub_14003A350(a1: v1 + 192);
      sub_1400371B0(a1: v1 + 160);
      sub_140038710(a1: v1 + 104);
      goto LABEL_584;
    case 0xA:
      *(_BYTE *)(a1 + 1904) = sub_14003A6C0(a1: *(_QWORD *)(a1 + 2816));
      v211 = v1 + 2832;
      goto LABEL_561;
    case 0xB:
      sub_14003A3B0(a1: a1 + 2832);
      sub_140037060(a1: v1 + 1912);
      unknown_libname_4(a1: (void *)(v1 + 1784));
      sub_14003A350(a1: v1 + 768);
      sub_14003A350(a1: v1 + 192);
      sub_1400371B0(a1: v1 + 160);
      sub_140038710(a1: v1 + 104);
      goto LABEL_584;
    case 0xC:
      __eh34_enter_wind_state(20, 51);
      v205 = sub_14003A6C0(a1: *(_QWORD *)(a1 + 2840));
      sub_14003A3B0(a1: v1 + 2856);
      if ( __eh34_unwind(51) )
      {
unwind_state_51:
        v352 = a1 + 2856;
        sub_14003A3B0(a1: a1 + 2856);
        __eh34_continue_unwinding(51, 20);
      }
      __eh34_exit_wind_state(51, 20);
      if ( v205 == 0 )
      {
        v206 = sub_14003E290(a1: (void *)(v1 + 2864), Src: "Failed to make spot encrypt! (", a3: (void *)(v1 + 160));
        __wind
        {
          v207 = sub_14003E000(a1: v1 + 2896, a2: v206, a3: ")");
          __wind
          {
            sub_140039EC0(a1: v208, a2: v207);
            sub_1400371B0(a1: v1 + 2896);
            sub_1400371B0(a1: v1 + 2864);
          }
          __unwind
          {
            v354 = a1 + 2896;
            sub_1400371B0(a1: a1 + 2896);
          }
        }
        __unwind
        {
          v353 = a1 + 2864;
          sub_1400371B0(a1: a1 + 2864);
        }
        goto LABEL_562;
      }
      v209 = sub_14003A0F0(a1: v1 + 2936, a2: v1 + 192, a3: v1 + 1912);
      v210 = sub_14003A030(a1: v1 + 16, a2: v1 + 2944, a3: v209);
      *(_QWORD *)(v1 + 2928) = v210;
      __wind
      {
        *v2 = 14;
        sub_14003E7D0(a1: v210, a2: v1);
      }
      __unwind
      {
        v355 = a1 + 2944;
        sub_14003A3B0(a1: a1 + 2944);
      }
      break;
    case 0xD:
      sub_14003A3B0(a1: a1 + 2856);
      sub_140037060(a1: v1 + 1912);
      unknown_libname_4(a1: (void *)(v1 + 1784));
      sub_14003A350(a1: v1 + 768);
      sub_14003A350(a1: v1 + 192);
      sub_1400371B0(a1: v1 + 160);
      sub_140038710(a1: v1 + 104);
      goto LABEL_584;
    case 0xE:
      *(_BYTE *)(a1 + 1904) = sub_14003A6C0(a1: *(_QWORD *)(a1 + 2928));
      v211 = v1 + 2944;
      goto LABEL_561;
    case 0xF:
      sub_14003A3B0(a1: a1 + 2944);
      sub_140037060(a1: v1 + 1912);
      unknown_libname_4(a1: (void *)(v1 + 1784));
      sub_14003A350(a1: v1 + 768);
      sub_14003A350(a1: v1 + 192);
      sub_1400371B0(a1: v1 + 160);
      sub_140038710(a1: v1 + 104);
      goto LABEL_584;
    case 0x10:
      __eh34_enter_wind_state(20, 55);
      v212 = sub_14003A6C0(a1: *(_QWORD *)(a1 + 2952));
      sub_14003A3B0(a1: v1 + 2968);
      if ( __eh34_unwind(55) )
      {
unwind_state_55:
        v356 = a1 + 2968;
        sub_14003A3B0(a1: a1 + 2968);
        __eh34_continue_unwinding(55, 20);
      }
      __eh34_exit_wind_state(55, 20);
      if ( v212 == 0 )
      {
        v213 = sub_14003E290(a1: (void *)(v1 + 2976), Src: "Failed to make part encrypt! (", a3: (void *)(v1 + 160));
        __wind
        {
          v214 = sub_14003E000(a1: v1 + 3008, a2: v213, a3: ")");
          __wind
          {
            sub_140039EC0(a1: v215, a2: v214);
            sub_1400371B0(a1: v1 + 3008);
            sub_1400371B0(a1: v1 + 2976);
          }
          __unwind
          {
            v358 = a1 + 3008;
            sub_1400371B0(a1: a1 + 3008);
          }
        }
        __unwind
        {
          v357 = a1 + 2976;
          sub_1400371B0(a1: a1 + 2976);
        }
        goto LABEL_562;
      }
      v216 = sub_14003A0F0(a1: v1 + 3048, a2: v1 + 192, a3: v1 + 1912);
      v217 = sub_14003A030(a1: v1 + 16, a2: v1 + 3056, a3: v216);
      *(_QWORD *)(v1 + 3040) = v217;
      __eh34_enter_wind_state(20, 58);
      *v2 = 18;
      sub_14003E7D0(a1: v217, a2: v1);
      if ( __eh34_unwind(58) )
      {
unwind_state_58:
        v359 = a1 + 3056;
        sub_14003A3B0(a1: a1 + 3056);
        __eh34_continue_unwinding(58, 20);
      }
      __eh34_exit_wind_state(58, 20);
      break;
    case 0x11:
      sub_14003A3B0(a1: a1 + 2968);
      sub_140037060(a1: v1 + 1912);
      unknown_libname_4(a1: (void *)(v1 + 1784));
      sub_14003A350(a1: v1 + 768);
      sub_14003A350(a1: v1 + 192);
      sub_1400371B0(a1: v1 + 160);
      sub_140038710(a1: v1 + 104);
      goto LABEL_584;
    case 0x12:
      *(_BYTE *)(a1 + 1904) = sub_14003A6C0(a1: *(_QWORD *)(a1 + 3040));
      v211 = v1 + 3056;
LABEL_561:
      sub_14003A3B0(a1: v211);
      goto LABEL_562;
    case 0x13:
      sub_14003A3B0(a1: a1 + 3056);
      sub_140037060(a1: v1 + 1912);
      unknown_libname_4(a1: (void *)(v1 + 1784));
      sub_14003A350(a1: v1 + 768);
      sub_14003A350(a1: v1 + 192);
      sub_1400371B0(a1: v1 + 160);
      sub_140038710(a1: v1 + 104);
LABEL_584:
      sub_140080718(a1: v1 + 40);
      if ( *(_WORD *)(v1 + 10) != 0 )
        sub_14003A420(a1: v1, a2: 3712);
      break;
    default:
      __debugbreak();
  }
  __eh34_enter_wind_state(20, 58);
  if ( __eh34_unwind(58) )
    goto unwind_state_58;
  __eh34_exit_wind_state(58, 20);
  if ( __eh34_unwind(20) )
    goto unwind_state_20;
  __eh34_exit_wind_state(20, 17);
  if ( __eh34_unwind(17) )
    goto unwind_state_17;
  __eh34_exit_wind_state(17, 5);
  if ( __eh34_unwind(5) )
    goto unwind_state_5;
  __eh34_exit_wind_state(5, 4);
  if ( __eh34_unwind(4) )
    goto unwind_state_4;
  __eh34_exit_wind_state(4, 3);
  if ( __eh34_unwind(3) )
    goto unwind_state_3;
  __eh34_exit_wind_state(3, 2);
  if ( __eh34_unwind(2) )
    goto unwind_state_2;
  __eh34_exit_wind_state(2, 0);
  if ( __eh34_catch(0) )
  {
    if ( __eh34_catch_ellipsis(0) )
    {
      *(_QWORD *)a1 = 0;
      *(_WORD *)(a1 + 100) = -1;
      sub_14003A3D0(a1: a1 + 16);
      v22 = v271;
      v1 = a1;
      __eh34_enter_try_state(-1, 0);
LABEL_901:
      __eh34_enter_wind_state(0, 2);
      __eh34_enter_wind_state(2, 3);
      __eh34_enter_wind_state(3, 4);
      __eh34_enter_wind_state(4, 5);
      __eh34_enter_wind_state(5, 17);
LABEL_637:
      __eh34_enter_wind_state(17, 20);
      goto LABEL_583;
    }
  }
  __eh34_exit_try_state(0, -1);
}